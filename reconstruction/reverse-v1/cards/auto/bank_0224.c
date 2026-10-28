/* libyoyo.so 覆盖卡组 0224
 * 函数 0x25255c..0x255170，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x25255c · JS_Math_log(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x25255c cmp r3, #0 */
/* @0x252560 push {r3, r4, r5, lr} */
/* @0x252564 mov r5, #0 */
/* @0x252568 mov r4, r0 */
/* @0x25256c ldr r1, [sp, #0x10] */
/* @0x252570 str r5, [r0, #0xc] */
/* @0x252574 ble 0x25259c <_Z11JS_Math_logR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252578 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25257c cmp r0, #1 */
/* @0x252580 beq 0x2525ac <_Z11JS_Math_logR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252584 mov r1, r5 */
/* @0x252588 mov r0, r4 */
/* @0x25258c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252590 bl 0xb6730 <log@plt> */
/* @0x252594 stm r4, {r0, r1} */
/* @0x252598 pop {r3, r4, r5, pc} */
/* @0x25259c mvn r2, #0 */
/* @0x2525a0 mvn r3, #-2147483648 */
/* @0x2525a4 stm r0, {r2, r3} */
/* @0x2525a8 pop {r3, r4, r5, pc} */
/* @0x2525ac ldr r0, [pc, #0x8] */
/* @0x2525b0 pop {r3, r4, r5, lr} */
/* @0x2525b4 add r0, pc, r0 */
/* @0x2525b8 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2525bc mulseq r0, r4, r9 */

/* ── FUNC 0x2525c0 · JS_Math_max(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x2525c0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2525c4 vpush {d8} */
/* @0x2525c8 subs r7, r3, #0 */
/* @0x2525cc mov r6, r0 */
/* @0x2525d0 ldr r4, [sp, #0x20] */
/* @0x2525d4 ble 0x252674 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x2525d8 mov r5, #0 */
/* @0x2525dc vldr d8, [pc, #156] */
/* @0x2525e0 b 0x252600 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2525e4 vcmp.f64 d7, d8 */
/* @0x2525e8 add r5, r5, #1 */
/* @0x2525ec add r4, r4, #16 */
/* @0x2525f0 vmrs APSR_nzcv, fpscr */
/* @0x2525f4 vmovgt.f64 d8, d7 */
/* @0x2525f8 cmp r5, r7 */
/* @0x2525fc beq 0x252644 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x252600 mov r1, r4 */
/* @0x252604 mov r0, r6 */
/* @0x252608 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25260c mov r1, #0 */
/* @0x252610 cmp r0, #1 */
/* @0x252614 mov r0, r6 */
/* @0x252618 beq 0x252660 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x25261c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252620 vmov d7, r0, r1 */
/* @0x252624 vcmp.f64 d7, d7 */
/* @0x252628 vmrs APSR_nzcv, fpscr */
/* @0x25262c bvc 0x2525e4 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x252630 add r5, r5, #1 */
/* @0x252634 vmov d8, r0, r1 */
/* @0x252638 cmp r5, r7 */
/* @0x25263c add r4, r4, #16 */
/* @0x252640 bne 0x252600 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252644 mov r3, #0 */
/* @0x252648 vmov r2, s16 */
/* @0x25264c str r3, [r6, #0xc] */
/* @0x252650 vmov r3, s17 */
/* @0x252654 stm r6, {r2, r3} */
/* @0x252658 vpop {d8} */
/* @0x25265c pop {r3, r4, r5, r6, r7, pc} */
/* @0x252660 vpop {d8} */
/* @0x252664 ldr r0, [pc, #0x1c] */
/* @0x252668 add r0, pc, r0 */
/* @0x25266c pop {r3, r4, r5, r6, r7, lr} */
/* @0x252670 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252674 vldr d8, [pc, #4] */
/* @0x252678 b 0x252644 <_Z11JS_Math_maxR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x25267c nop */
/* @0x252680 andeq r0, r0, r0 */
/* @0x252684 .word 0xfff00000 */
/* @0x252688 andseq r3, r0, r0, ror #17 */

/* ── FUNC 0x25268c · anon_25268c · size=0 · insn=1 */
/* @0x25268c nop */

/* ── FUNC 0x252690 · JS_Math_min(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x252690 push {r3, r4, r5, r6, r7, lr} */
/* @0x252694 vpush {d8} */
/* @0x252698 subs r7, r3, #0 */
/* @0x25269c mov r6, r0 */
/* @0x2526a0 ldr r4, [sp, #0x20] */
/* @0x2526a4 ble 0x252744 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x2526a8 mov r5, #0 */
/* @0x2526ac vldr d8, [pc, #156] */
/* @0x2526b0 b 0x2526d0 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2526b4 vcmp.f64 d7, d8 */
/* @0x2526b8 add r5, r5, #1 */
/* @0x2526bc add r4, r4, #16 */
/* @0x2526c0 vmrs APSR_nzcv, fpscr */
/* @0x2526c4 vmovmi.f64 d8, d7 */
/* @0x2526c8 cmp r5, r7 */
/* @0x2526cc beq 0x252714 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2526d0 mov r1, r4 */
/* @0x2526d4 mov r0, r6 */
/* @0x2526d8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2526dc mov r1, #0 */
/* @0x2526e0 cmp r0, #1 */
/* @0x2526e4 mov r0, r6 */
/* @0x2526e8 beq 0x252730 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x2526ec bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2526f0 vmov d7, r0, r1 */
/* @0x2526f4 vcmp.f64 d7, d7 */
/* @0x2526f8 vmrs APSR_nzcv, fpscr */
/* @0x2526fc bvc 0x2526b4 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x252700 add r5, r5, #1 */
/* @0x252704 vmov d8, r0, r1 */
/* @0x252708 cmp r5, r7 */
/* @0x25270c add r4, r4, #16 */
/* @0x252710 bne 0x2526d0 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252714 mov r3, #0 */
/* @0x252718 vmov r2, s16 */
/* @0x25271c str r3, [r6, #0xc] */
/* @0x252720 vmov r3, s17 */
/* @0x252724 stm r6, {r2, r3} */
/* @0x252728 vpop {d8} */
/* @0x25272c pop {r3, r4, r5, r6, r7, pc} */
/* @0x252730 vpop {d8} */
/* @0x252734 ldr r0, [pc, #0x1c] */
/* @0x252738 add r0, pc, r0 */
/* @0x25273c pop {r3, r4, r5, r6, r7, lr} */
/* @0x252740 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252744 vldr d8, [pc, #4] */
/* @0x252748 b 0x252714 <_Z11JS_Math_minR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x25274c nop */
/* @0x252750 andeq r0, r0, r0 */
/* @0x252754 svcvc #0xf00000 */
/* @0x252758 andseq r3, r0, r0, lsl r8 */

/* ── FUNC 0x25275c · anon_25275c · size=0 · insn=1 */
/* @0x25275c nop */

/* ── FUNC 0x252760 · JS_Math_pow(RValue&, CInstance*, CInstance*, int, RValue*) · size=704 · insn=176 */
/* @0x252760 cmp r3, #1 */
/* @0x252764 push {r4, r5, r6, r7, lr} */
/* @0x252768 vpush {d8, d9} */
/* @0x25276c mov r5, #0 */
/* @0x252770 sub sp, sp, #36 */
/* @0x252774 mov r4, r0 */
/* @0x252778 str r5, [r0, #0xc] */
/* @0x25277c ble 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x252780 ldr r3, [sp, #0x48] */
/* @0x252784 mov r0, sp */
/* @0x252788 add r1, r3, #16 */
/* @0x25278c mov r3, #5 */
/* @0x252790 str r3, [sp, #0xc] */
/* @0x252794 str r3, [sp, #0x1c] */
/* @0x252798 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25279c cmp r0, #1 */
/* @0x2527a0 beq 0x252874 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2527a4 add r7, sp, #16 */
/* @0x2527a8 ldr r1, [sp, #0x48] */
/* @0x2527ac mov r0, r7 */
/* @0x2527b0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2527b4 cmp r0, #1 */
/* @0x2527b8 beq 0x252874 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x2527bc mov r0, sp */
/* @0x2527c0 mov r1, r5 */
/* @0x2527c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2527c8 vmov d8, r0, r1 */
/* @0x2527cc mov r0, r7 */
/* @0x2527d0 mov r1, r5 */
/* @0x2527d4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2527d8 vmov d9, r0, r1 */
/* @0x2527dc vmov r0, r1, d8 */
/* @0x2527e0 bl 0x24364c <_Z7myisinfd> */
/* @0x2527e4 mov r6, r0 */
/* @0x2527e8 vmov r0, r1, d9 */
/* @0x2527ec bl 0x24364c <_Z7myisinfd> */
/* @0x2527f0 vcmp.f64 d8, d8 */
/* @0x2527f4 vmrs APSR_nzcv, fpscr */
/* @0x2527f8 bvs 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x2527fc vcmp.f64 d8, #0 */
/* @0x252800 vmrs APSR_nzcv, fpscr */
/* @0x252804 beq 0x25288c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x252808 vcmp.f64 d9, d9 */
/* @0x25280c vmrs APSR_nzcv, fpscr */
/* @0x252810 bvs 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x252814 cmp r6, #0 */
/* @0x252818 bne 0x25290c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x25281c cmp r0, #0 */
/* @0x252820 bne 0x2528dc <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x252824 vcmp.f64 d9, #0 */
/* @0x252828 vmov r0, r1, d9 */
/* @0x25282c vmrs APSR_nzcv, fpscr */
/* @0x252830 bne 0x2528a8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x252834 bl 0x243674 <_Z7myisposd> */
/* @0x252838 cmp r0, #0 */
/* @0x25283c beq 0x252980 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x252840 vcmpe.f64 d8, #0 */
/* @0x252844 vmrs APSR_nzcv, fpscr */
/* @0x252848 ble 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25284c mov r3, #0 */
/* @0x252850 str r3, [r4] */
/* @0x252854 str r3, [r4, #0x4] */
/* @0x252858 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25285c mvn r2, #0 */
/* @0x252860 mvn r3, #-2147483648 */
/* @0x252864 stm r4, {r2, r3} */
/* @0x252868 add sp, sp, #36 */
/* @0x25286c vpop {d8, d9} */
/* @0x252870 pop {r4, r5, r6, r7, pc} */
/* @0x252874 ldr r0, [pc, #0x1a0] */
/* @0x252878 add r0, pc, r0 */
/* @0x25287c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252880 add sp, sp, #36 */
/* @0x252884 vpop {d8, d9} */
/* @0x252888 pop {r4, r5, r6, r7, pc} */
/* @0x25288c str r5, [r4] */
/* @0x252890 mov r3, #0 */
/* @0x252894 movt r3, #0x3ff0 */
/* @0x252898 str r3, [r4, #0x4] */
/* @0x25289c add sp, sp, #36 */
/* @0x2528a0 vpop {d8, d9} */
/* @0x2528a4 pop {r4, r5, r6, r7, pc} */
/* @0x2528a8 bl 0x243674 <_Z7myisposd> */
/* @0x2528ac cmp r0, #0 */
/* @0x2528b0 bne 0x2528c8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x2528b4 vcvt.s32.f64 s14, d8 */
/* @0x2528b8 vcvt.f64.s32 d7, s14 */
/* @0x2528bc vcmp.f64 d8, d7 */
/* @0x2528c0 vmrs APSR_nzcv, fpscr */
/* @0x2528c4 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x2528c8 vmov r0, r1, d9 */
/* @0x2528cc vmov r2, r3, d8 */
/* @0x2528d0 bl 0xb6784 <pow@plt> */
/* @0x2528d4 stm r4, {r0, r1} */
/* @0x2528d8 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x2528dc vmov r0, r1, d9 */
/* @0x2528e0 bl 0x243674 <_Z7myisposd> */
/* @0x2528e4 cmp r0, #0 */
/* @0x2528e8 beq 0x2529cc <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x2528ec vcmpe.f64 d8, #0 */
/* @0x2528f0 vmrs APSR_nzcv, fpscr */
/* @0x2528f4 ble 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x2528f8 mov r3, #0 */
/* @0x2528fc mov r2, r3 */
/* @0x252900 movt r3, #0x7ff0 */
/* @0x252904 stm r4, {r2, r3} */
/* @0x252908 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25290c vmov r0, r1, d8 */
/* @0x252910 bl 0x243674 <_Z7myisposd> */
/* @0x252914 vmov.f64 d7, #1.000000e+00 */
/* @0x252918 vabs.f64 d9, d9 */
/* @0x25291c vcmpe.f64 d9, d7 */
/* @0x252920 vmrs APSR_nzcv, fpscr */
/* @0x252924 ble 0x252934 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x252928 cmp r0, #0 */
/* @0x25292c beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x252930 b 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x252934 ble 0x252940 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x252938 cmp r0, #0 */
/* @0x25293c beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x252940 vmov.f64 d7, #1.000000e+00 */
/* @0x252944 vcmp.f64 d9, d7 */
/* @0x252948 vmrs APSR_nzcv, fpscr */
/* @0x25294c movne r3, #0 */
/* @0x252950 moveq r3, #1 */
/* @0x252954 tst r0, r3 */
/* @0x252958 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x25295c eor r2, r0, #1 */
/* @0x252960 tst r3, r2 */
/* @0x252964 bne 0x25285c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x252968 vcmpe.f64 d9, d7 */
/* @0x25296c vmrs APSR_nzcv, fpscr */
/* @0x252970 bpl 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x252974 cmp r0, #0 */
/* @0x252978 bne 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x25297c b 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x252980 vcvt.s32.f64 s18, d8 */
/* @0x252984 vmov r0, r1, d8 */
/* @0x252988 vcvt.f64.s32 d7, s18 */
/* @0x25298c vcmp.f64 d8, d7 */
/* @0x252990 vmrs APSR_nzcv, fpscr */
/* @0x252994 movne r5, #0 */
/* @0x252998 moveq r5, #1 */
/* @0x25299c bl 0x243674 <_Z7myisposd> */
/* @0x2529a0 cmp r0, #0 */
/* @0x2529a4 beq 0x2529f4 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x2529a8 cmp r5, #0 */
/* @0x2529ac beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x2529b0 vmov r3, s18 */
/* @0x2529b4 tst r3, #1 */
/* @0x2529b8 beq 0x25284c <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x2529bc mov r2, #0 */
/* @0x2529c0 mov r3, #-2147483648 */
/* @0x2529c4 stm r4, {r2, r3} */
/* @0x2529c8 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x2529cc vcvt.s32.f64 s18, d8 */
/* @0x2529d0 vmov r0, r1, d8 */
/* @0x2529d4 vcvt.f64.s32 d7, s18 */
/* @0x2529d8 vcmp.f64 d8, d7 */
/* @0x2529dc vmrs APSR_nzcv, fpscr */
/* @0x2529e0 movne r5, #0 */
/* @0x2529e4 moveq r5, #1 */
/* @0x2529e8 bl 0x243674 <_Z7myisposd> */
/* @0x2529ec cmp r0, #0 */
/* @0x2529f0 beq 0x2529a8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x2529f4 cmp r5, #0 */
/* @0x2529f8 beq 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x2529fc vmov r3, s18 */
/* @0x252a00 tst r3, #1 */
/* @0x252a04 beq 0x2528f8 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x252a08 mov r3, #0 */
/* @0x252a0c mov r2, r3 */
/* @0x252a10 movt r3, #0xfff0 */
/* @0x252a14 stm r4, {r2, r3} */
/* @0x252a18 b 0x252868 <_Z11JS_Math_powR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x252a1c ldrsbeq r3, [r0], -r0 */

/* ── FUNC 0x252a20 · JS_Math_round(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x252a20 cmp r3, #0 */
/* @0x252a24 push {r3, r4, r5, lr} */
/* @0x252a28 mov r5, #0 */
/* @0x252a2c mov r4, r0 */
/* @0x252a30 ldr r1, [sp, #0x10] */
/* @0x252a34 str r5, [r0, #0xc] */
/* @0x252a38 ble 0x252a74 <_Z13JS_Math_roundR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x252a3c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252a40 cmp r0, #1 */
/* @0x252a44 beq 0x252a84 <_Z13JS_Math_roundR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x252a48 mov r1, r5 */
/* @0x252a4c mov r0, r4 */
/* @0x252a50 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252a54 bl 0xb66e8 <lrint@plt> */
/* @0x252a58 vmov s15, r0 */
/* @0x252a5c vcvt.f64.s32 d7, s15 */
/* @0x252a60 vmov r0, r1, d7 */
/* @0x252a64 vmov r2, s14 */
/* @0x252a68 mov r3, r1 */
/* @0x252a6c stm r4, {r2, r3} */
/* @0x252a70 pop {r3, r4, r5, pc} */
/* @0x252a74 mvn r2, #0 */
/* @0x252a78 mvn r3, #-2147483648 */
/* @0x252a7c stm r0, {r2, r3} */
/* @0x252a80 pop {r3, r4, r5, pc} */
/* @0x252a84 ldr r0, [pc, #0x8] */
/* @0x252a88 pop {r3, r4, r5, lr} */
/* @0x252a8c add r0, pc, r0 */
/* @0x252a90 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252a94 ldrheq r3, [r0], -r12 */

/* ── FUNC 0x252a98 · JS_Math_sin(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x252a98 cmp r3, #0 */
/* @0x252a9c push {r3, r4, r5, lr} */
/* @0x252aa0 mov r5, #0 */
/* @0x252aa4 mov r4, r0 */
/* @0x252aa8 ldr r1, [sp, #0x10] */
/* @0x252aac str r5, [r0, #0xc] */
/* @0x252ab0 ble 0x252ad8 <_Z11JS_Math_sinR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252ab4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252ab8 cmp r0, #1 */
/* @0x252abc beq 0x252ae8 <_Z11JS_Math_sinR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252ac0 mov r1, r5 */
/* @0x252ac4 mov r0, r4 */
/* @0x252ac8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252acc bl 0xb67d8 <sin@plt> */
/* @0x252ad0 stm r4, {r0, r1} */
/* @0x252ad4 pop {r3, r4, r5, pc} */
/* @0x252ad8 mvn r2, #0 */
/* @0x252adc mvn r3, #-2147483648 */
/* @0x252ae0 stm r0, {r2, r3} */
/* @0x252ae4 pop {r3, r4, r5, pc} */
/* @0x252ae8 ldr r0, [pc, #0x8] */
/* @0x252aec pop {r3, r4, r5, lr} */
/* @0x252af0 add r0, pc, r0 */
/* @0x252af4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252af8 andseq r3, r0, r8, asr r4 */

/* ── FUNC 0x252afc · JS_Math_sqrt(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x252afc cmp r3, #0 */
/* @0x252b00 push {r3, r4, r5, lr} */
/* @0x252b04 mov r5, #0 */
/* @0x252b08 mov r4, r0 */
/* @0x252b0c ldr r1, [sp, #0x10] */
/* @0x252b10 str r5, [r0, #0xc] */
/* @0x252b14 ble 0x252b54 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x252b18 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252b1c cmp r0, #1 */
/* @0x252b20 beq 0x252b64 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x252b24 mov r1, r5 */
/* @0x252b28 mov r0, r4 */
/* @0x252b2c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252b30 vmov d6, r0, r1 */
/* @0x252b34 vsqrt.f64 d7, d6 */
/* @0x252b38 vcmp.f64 d7, d7 */
/* @0x252b3c vmrs APSR_nzcv, fpscr */
/* @0x252b40 bne 0x252b74 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x252b44 vmov r2, s14 */
/* @0x252b48 vmov r3, s15 */
/* @0x252b4c stm r4, {r2, r3} */
/* @0x252b50 pop {r3, r4, r5, pc} */
/* @0x252b54 mvn r2, #0 */
/* @0x252b58 mvn r3, #-2147483648 */
/* @0x252b5c stm r0, {r2, r3} */
/* @0x252b60 pop {r3, r4, r5, pc} */
/* @0x252b64 ldr r0, [pc, #0x14] */
/* @0x252b68 pop {r3, r4, r5, lr} */
/* @0x252b6c add r0, pc, r0 */
/* @0x252b70 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252b74 bl 0xb66f4 <sqrt@plt> */
/* @0x252b78 vmov d7, r0, r1 */
/* @0x252b7c b 0x252b44 <_Z12JS_Math_sqrtR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x252b80 ldrsbeq r3, [r0], -r12 */

/* ── FUNC 0x252b84 · JS_Math_tan(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x252b84 cmp r3, #0 */
/* @0x252b88 push {r3, r4, r5, lr} */
/* @0x252b8c mov r5, #0 */
/* @0x252b90 mov r4, r0 */
/* @0x252b94 ldr r1, [sp, #0x10] */
/* @0x252b98 str r5, [r0, #0xc] */
/* @0x252b9c ble 0x252bc4 <_Z11JS_Math_tanR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252ba0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252ba4 cmp r0, #1 */
/* @0x252ba8 beq 0x252bd4 <_Z11JS_Math_tanR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252bac mov r1, r5 */
/* @0x252bb0 mov r0, r4 */
/* @0x252bb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252bb8 bl 0xb6c7c <tan@plt> */
/* @0x252bbc stm r4, {r0, r1} */
/* @0x252bc0 pop {r3, r4, r5, pc} */
/* @0x252bc4 mvn r2, #0 */
/* @0x252bc8 mvn r3, #-2147483648 */
/* @0x252bcc stm r0, {r2, r3} */
/* @0x252bd0 pop {r3, r4, r5, pc} */
/* @0x252bd4 ldr r0, [pc, #0x8] */
/* @0x252bd8 pop {r3, r4, r5, lr} */
/* @0x252bdc add r0, pc, r0 */
/* @0x252be0 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252be4 andseq r3, r0, r12, ror #6 */

/* ── FUNC 0x252be8 · JS_Boolean_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x252be8 push {r3, r4, r5, lr} */
/* @0x252bec mov r4, r1 */
/* @0x252bf0 ldr r1, [pc, #0x84] */
/* @0x252bf4 mov r5, r0 */
/* @0x252bf8 ldr r0, [r4, #0x40] */
/* @0x252bfc add r1, pc, r1 */
/* @0x252c00 bl 0xb6574 <strcmp@plt> */
/* @0x252c04 cmp r0, #0 */
/* @0x252c08 bne 0x252c60 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x252c0c ldr r1, [pc, #0x6c] */
/* @0x252c10 mov r0, r4 */
/* @0x252c14 add r1, pc, r1 */
/* @0x252c18 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x252c1c cmp r0, #0 */
/* @0x252c20 beq 0x252c70 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x252c24 ldm r0, {r2, r3} */
/* @0x252c28 vmov d7, r2, r3 */
/* @0x252c2c vcmp.f64 d7, #0 */
/* @0x252c30 vmrs APSR_nzcv, fpscr */
/* @0x252c34 bne 0x252c4c <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x252c38 ldr r1, [pc, #0x44] */
/* @0x252c3c add r1, pc, r1 */
/* @0x252c40 mov r0, r5 */
/* @0x252c44 pop {r3, r4, r5, lr} */
/* @0x252c48 b 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x252c4c ldr r1, [pc, #0x34] */
/* @0x252c50 mov r0, r5 */
/* @0x252c54 pop {r3, r4, r5, lr} */
/* @0x252c58 add r1, pc, r1 */
/* @0x252c5c b 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x252c60 ldr r0, [pc, #0x24] */
/* @0x252c64 pop {r3, r4, r5, lr} */
/* @0x252c68 add r0, pc, r0 */
/* @0x252c6c b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252c70 ldr r1, [pc, #0x18] */
/* @0x252c74 add r1, pc, r1 */
/* @0x252c78 b 0x252c40 <_Z29JS_Boolean_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x252c7c andseq r2, r0, r12, lsl #18 */
/* @0x252c80 ldrsheq r2, [r0], -r12 */
/* @0x252c84 andeq r1, lr, r12, ror #27 */
/* @0x252c88 andeq r1, lr, r8, asr #27 */
/* @0x252c8c andseq r3, r0, r0, lsl r9 */
/* @0x252c90 ldrsheq r3, [r0], -r4 */

/* ── FUNC 0x252c94 · JS_Boolean_prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x252c94 push {r4, r5, r6, lr} */
/* @0x252c98 mov r5, r1 */
/* @0x252c9c ldr r1, [pc, #0x64] */
/* @0x252ca0 mov r4, r0 */
/* @0x252ca4 ldr r0, [r5, #0x40] */
/* @0x252ca8 add r1, pc, r1 */
/* @0x252cac bl 0xb6574 <strcmp@plt> */
/* @0x252cb0 subs r6, r0, #0 */
/* @0x252cb4 bne 0x252cf8 <_Z28JS_Boolean_prototype_valueOfR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x252cb8 ldr r1, [pc, #0x4c] */
/* @0x252cbc mov r0, r5 */
/* @0x252cc0 add r1, pc, r1 */
/* @0x252cc4 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x252cc8 cmp r0, #0 */
/* @0x252ccc popeq {r4, r5, r6, pc} */
/* @0x252cd0 mov r3, #13 */
/* @0x252cd4 str r3, [r4, #0xc] */
/* @0x252cd8 ldm r0, {r2, r3} */
/* @0x252cdc str r6, [r4] */
/* @0x252ce0 orrs r1, r2, r3 */
/* @0x252ce4 movne r3, #0 */
/* @0x252ce8 moveq r3, r6 */
/* @0x252cec movtne r3, #0x3ff0 */
/* @0x252cf0 str r3, [r4, #0x4] */
/* @0x252cf4 pop {r4, r5, r6, pc} */
/* @0x252cf8 ldr r0, [pc, #0x10] */
/* @0x252cfc pop {r4, r5, r6, lr} */
/* @0x252d00 add r0, pc, r0 */
/* @0x252d04 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252d08 andseq r2, r0, r0, ror #16 */
/* @0x252d0c andseq r2, r0, r0, asr r8 */
/* @0x252d10 andseq r3, r0, r4, lsr #17 */

/* ── FUNC 0x252d14 · JS_Number_Call(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x252d14 push {r3, lr} */
/* @0x252d18 cmp r3, #0 */
/* @0x252d1c ldr r1, [sp, #0x8] */
/* @0x252d20 bne 0x252d34 <_Z14JS_Number_CallR6RValueP9CInstanceS2_iPS_+0x20> */
/* @0x252d24 str r3, [r0] */
/* @0x252d28 str r3, [r0, #0x4] */
/* @0x252d2c str r3, [r0, #0xc] */
/* @0x252d30 pop {r3, pc} */
/* @0x252d34 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252d38 cmp r0, #1 */
/* @0x252d3c popne {r3, pc} */
/* @0x252d40 ldr r0, [pc, #0x8] */
/* @0x252d44 pop {r3, lr} */
/* @0x252d48 add r0, pc, r0 */
/* @0x252d4c b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252d50 andseq r3, r0, r8, lsl #17 */

/* ── FUNC 0x252d54 · JS_Number_Prototype_valueOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x252d54 push {r3, r4, r5, lr} */
/* @0x252d58 mov r5, r1 */
/* @0x252d5c ldr r1, [pc, #0x44] */
/* @0x252d60 mov r4, r0 */
/* @0x252d64 ldr r0, [r5, #0x40] */
/* @0x252d68 add r1, pc, r1 */
/* @0x252d6c bl 0xb6574 <strcmp@plt> */
/* @0x252d70 cmp r0, #0 */
/* @0x252d74 bne 0x252d98 <_Z27JS_Number_Prototype_valueOfR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x252d78 ldr r1, [pc, #0x2c] */
/* @0x252d7c str r0, [r4, #0xc] */
/* @0x252d80 mov r0, r5 */
/* @0x252d84 add r1, pc, r1 */
/* @0x252d88 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x252d8c ldm r0, {r2, r3} */
/* @0x252d90 stm r4, {r2, r3} */
/* @0x252d94 pop {r3, r4, r5, pc} */
/* @0x252d98 ldr r0, [pc, #0x10] */
/* @0x252d9c pop {r3, r4, r5, lr} */
/* @0x252da0 add r0, pc, r0 */
/* @0x252da4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252da8 andseq r2, r0, r8, lsr #24 */
/* @0x252dac andseq r2, r0, r12, lsl #15 */
/* @0x252db0 andseq r3, r0, r8, lsr #3 */

/* ── FUNC 0x252db4 · F_JS_Object_defineProperties(RValue&, CInstance*, CInstance*, int, RValue*) · size=1480 · insn=370 */
/* @0x252db4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x252db8 cmp r3, #0 */
/* @0x252dbc sub sp, sp, #100 */
/* @0x252dc0 str r0, [sp, #0xc] */
/* @0x252dc4 ldr r5, [sp, #0x88] */
/* @0x252dc8 beq 0x252ddc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x252dcc ldr r3, [r5, #0xc] */
/* @0x252dd0 bic r3, r3, #-16777216 */
/* @0x252dd4 cmp r3, #6 */
/* @0x252dd8 beq 0x252df0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x252ddc ldr r0, [pc, #0x58c] */
/* @0x252de0 add r0, pc, r0 */
/* @0x252de4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252de8 add sp, sp, #100 */
/* @0x252dec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x252df0 add r0, sp, #20 */
/* @0x252df4 add r1, r5, #16 */
/* @0x252df8 bl 0x2403cc <_Z13F_JS_ToObjectP6RValueS0_> */
/* @0x252dfc cmp r0, #1 */
/* @0x252e00 beq 0x252ddc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x252e04 add r9, sp, #68 */
/* @0x252e08 mov r2, #1 */
/* @0x252e0c ldr r1, [sp, #0x14] */
/* @0x252e10 add r10, sp, #36 */
/* @0x252e14 mov r0, r9 */
/* @0x252e18 add r7, sp, #52 */
/* @0x252e1c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x252e20 mov r3, #0 */
/* @0x252e24 mov r6, r3 */
/* @0x252e28 mov r4, r3 */
/* @0x252e2c mov r8, r3 */
/* @0x252e30 mvn r2, #-16777216 */
/* @0x252e34 str r3, [sp, #0x24] */
/* @0x252e38 str r3, [sp, #0x28] */
/* @0x252e3c str r3, [sp, #0x2c] */
/* @0x252e40 str r2, [sp, #0x30] */
/* @0x252e44 mov r0, r9 */
/* @0x252e48 mov r1, r10 */
/* @0x252e4c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x252e50 cmp r0, #0 */
/* @0x252e54 beq 0x2530d4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x320> */
/* @0x252e58 ldr r3, [sp, #0x24] */
/* @0x252e5c mov r1, r7 */
/* @0x252e60 ldr r0, [sp, #0x14] */
/* @0x252e64 ldr r2, [r3] */
/* @0x252e68 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x252e6c ldr r3, [sp, #0x40] */
/* @0x252e70 mvn r0, #-16777216 */
/* @0x252e74 cmp r3, r0 */
/* @0x252e78 beq 0x252e44 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x252e7c mov r0, #40 */
/* @0x252e80 bl 0x27c524 <_Znwj> */
/* @0x252e84 ldr r2, [r0, #0xc] */
/* @0x252e88 mov r11, r0 */
/* @0x252e8c bic r3, r2, #-16777216 */
/* @0x252e90 cmp r3, #1 */
/* @0x252e94 beq 0x252fe0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x252e98 cmp r3, #2 */
/* @0x252e9c bne 0x252ec0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x252ea0 sub r2, r2, #1 */
/* @0x252ea4 bic r2, r2, #-16777216 */
/* @0x252ea8 bic r2, r2, #3 */
/* @0x252eac cmp r2, #0 */
/* @0x252eb0 beq 0x2530cc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x318> */
/* @0x252eb4 mov r1, #5 */
/* @0x252eb8 str r8, [r11, #0x8] */
/* @0x252ebc str r1, [r11, #0xc] */
/* @0x252ec0 ldr r3, [sp, #0x30] */
/* @0x252ec4 ldr r2, [sp, #0x2c] */
/* @0x252ec8 str r8, [r11] */
/* @0x252ecc str r3, [r11, #0xc] */
/* @0x252ed0 ldr r3, [sp, #0x30] */
/* @0x252ed4 str r2, [r11, #0x8] */
/* @0x252ed8 bic r3, r3, #-16777216 */
/* @0x252edc cmp r3, #14 */
/* @0x252ee0 addls pc, pc, r3, lsl #2 */
/* @0x252ee4 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252ee8 b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x252eec b 0x252fc8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x252ef0 b 0x252f9c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x252ef4 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x252ef8 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252efc b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f00 b 0x252f78 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x252f04 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x252f08 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f0c b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f10 b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x252f14 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f18 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f1c b 0x252f68 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x252f20 b 0x252f24 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x252f24 ldr r3, [sp, #0x24] */
/* @0x252f28 str r3, [r11] */
/* @0x252f2c add r0, r11, #16 */
/* @0x252f30 mov r1, r7 */
/* @0x252f34 bl 0x24195c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_> */
/* @0x252f38 cmp r0, #1 */
/* @0x252f3c beq 0x25322c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x478> */
/* @0x252f40 cmp r6, #0 */
/* @0x252f44 streq r6, [r11, #0x24] */
/* @0x252f48 streq r6, [r11, #0x20] */
/* @0x252f4c moveq r6, r11 */
/* @0x252f50 strne r11, [r6, #0x20] */
/* @0x252f54 moveq r4, r6 */
/* @0x252f58 strne r6, [r11, #0x24] */
/* @0x252f5c strne r8, [r11, #0x20] */
/* @0x252f60 movne r6, r11 */
/* @0x252f64 b 0x252e44 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x252f68 ldr r2, [sp, #0x24] */
/* @0x252f6c ldr r3, [sp, #0x28] */
/* @0x252f70 stm r11, {r2, r3} */
/* @0x252f74 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f78 ldr r3, [sp, #0x24] */
/* @0x252f7c str r3, [r11] */
/* @0x252f80 ldr r3, [sp, #0x24] */
/* @0x252f84 cmp r3, #0 */
/* @0x252f88 beq 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f8c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x252f90 ldr r1, [sp, #0x24] */
/* @0x252f94 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x252f98 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252f9c ldr r3, [sp, #0x24] */
/* @0x252fa0 cmp r3, #0 */
/* @0x252fa4 str r3, [r11] */
/* @0x252fa8 beq 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252fac ldr r1, [r3, #0x8] */
/* @0x252fb0 ldr r2, [r3] */
/* @0x252fb4 cmp r1, #0 */
/* @0x252fb8 streq r11, [r3, #0x8] */
/* @0x252fbc add r2, r2, #1 */
/* @0x252fc0 str r2, [r3] */
/* @0x252fc4 b 0x252f2c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x252fc8 ldr r3, [sp, #0x24] */
/* @0x252fcc cmp r3, #0 */
/* @0x252fd0 ldrne r2, [r3, #0x4] */
/* @0x252fd4 addne r2, r2, #1 */
/* @0x252fd8 strne r2, [r3, #0x4] */
/* @0x252fdc b 0x252f28 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x252fe0 ldr r3, [r0] */
/* @0x252fe4 cmp r3, #0 */
/* @0x252fe8 beq 0x253010 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x252fec str r3, [sp, #0x4] */
/* @0x252ff0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x252ff4 ldr r3, [sp, #0x4] */
/* @0x252ff8 ldr r2, [r3, #0x4] */
/* @0x252ffc sub r2, r2, #1 */
/* @0x253000 str r2, [r3, #0x4] */
/* @0x253004 cmp r2, #0 */
/* @0x253008 beq 0x253018 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x25300c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x253010 str r8, [r11] */
/* @0x253014 b 0x252ec0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x253018 ldr r0, [r3] */
/* @0x25301c str r2, [sp, #0x8] */
/* @0x253020 str r3, [sp, #0x4] */
/* @0x253024 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253028 ldr r3, [sp, #0x4] */
/* @0x25302c ldr r2, [sp, #0x8] */
/* @0x253030 str r2, [r3] */
/* @0x253034 str r2, [r3, #0x8] */
/* @0x253038 str r3, [sp, #0x4] */
/* @0x25303c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x253040 ldr r3, [sp, #0x4] */
/* @0x253044 ldr r2, [r3, #0x4] */
/* @0x253048 sub r2, r2, #1 */
/* @0x25304c str r2, [r3, #0x4] */
/* @0x253050 cmp r2, #0 */
/* @0x253054 beq 0x253070 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x253058 str r3, [sp, #0x4] */
/* @0x25305c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x253060 ldr r3, [sp, #0x4] */
/* @0x253064 mov r0, r3 */
/* @0x253068 bl 0x27d1d0 <_ZdlPv> */
/* @0x25306c b 0x25300c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x253070 ldr r0, [r3] */
/* @0x253074 str r2, [sp, #0x8] */
/* @0x253078 str r3, [sp, #0x4] */
/* @0x25307c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253080 ldr r3, [sp, #0x4] */
/* @0x253084 ldr r2, [sp, #0x8] */
/* @0x253088 str r2, [r3] */
/* @0x25308c str r2, [r3, #0x8] */
/* @0x253090 str r3, [sp, #0x4] */
/* @0x253094 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x253098 ldr r3, [sp, #0x4] */
/* @0x25309c ldr r2, [r3, #0x4] */
/* @0x2530a0 sub r2, r2, #1 */
/* @0x2530a4 str r2, [r3, #0x4] */
/* @0x2530a8 cmp r2, #0 */
/* @0x2530ac beq 0x2532d8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x2530b0 str r3, [sp, #0x4] */
/* @0x2530b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2530b8 ldr r3, [sp, #0x4] */
/* @0x2530bc mov r0, r3 */
/* @0x2530c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2530c4 ldr r3, [sp, #0x4] */
/* @0x2530c8 b 0x253058 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x2530cc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2530d0 b 0x252eb4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x2530d4 cmp r4, #0 */
/* @0x2530d8 beq 0x253184 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3d0> */
/* @0x2530dc mov r6, r4 */
/* @0x2530e0 b 0x2530f0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x33c> */
/* @0x2530e4 ldr r6, [r6, #0x20] */
/* @0x2530e8 cmp r6, #0 */
/* @0x2530ec beq 0x253114 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x360> */
/* @0x2530f0 ldr r0, [r5] */
/* @0x2530f4 mov r1, r6 */
/* @0x2530f8 add r2, r6, #16 */
/* @0x2530fc mov r3, #1 */
/* @0x253100 bl 0x248610 <_Z22JS_DefineOwnPropertyRVP12YYObjectBaseP6RValueS2_b> */
/* @0x253104 cmp r0, #2 */
/* @0x253108 beq 0x2531ac <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3f8> */
/* @0x25310c cmp r6, #0 */
/* @0x253110 bne 0x2530e4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x330> */
/* @0x253114 mov r7, #0 */
/* @0x253118 mov r8, #5 */
/* @0x25311c ldr r3, [r4, #0xc] */
/* @0x253120 ldr r6, [r4, #0x20] */
/* @0x253124 sub r3, r3, #1 */
/* @0x253128 bic r3, r3, #-16777216 */
/* @0x25312c bic r3, r3, #3 */
/* @0x253130 cmp r3, #0 */
/* @0x253134 beq 0x2532b4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x500> */
/* @0x253138 ldr r3, [r4, #0x1c] */
/* @0x25313c str r7, [r4, #0x8] */
/* @0x253140 sub r3, r3, #1 */
/* @0x253144 str r8, [r4, #0xc] */
/* @0x253148 bic r3, r3, #-16777216 */
/* @0x25314c str r7, [r4] */
/* @0x253150 bic r3, r3, #3 */
/* @0x253154 cmp r3, #0 */
/* @0x253158 bne 0x253164 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x3b0> */
/* @0x25315c add r0, r4, #16 */
/* @0x253160 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253164 str r7, [r4, #0x18] */
/* @0x253168 mov r0, r4 */
/* @0x25316c str r8, [r4, #0x1c] */
/* @0x253170 str r7, [r4, #0x10] */
/* @0x253174 mov r4, r6 */
/* @0x253178 bl 0x27d1d0 <_ZdlPv> */
/* @0x25317c cmp r6, #0 */
/* @0x253180 bne 0x25311c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x253184 ldr r0, [r5] */
/* @0x253188 ldr r1, [r5, #0x4] */
/* @0x25318c ldr r2, [r5, #0x8] */
/* @0x253190 ldr r3, [r5, #0xc] */
/* @0x253194 ldr r12, [sp, #0xc] */
/* @0x253198 str r0, [r12] */
/* @0x25319c str r1, [r12, #0x4] */
/* @0x2531a0 str r2, [r12, #0x8] */
/* @0x2531a4 str r3, [r12, #0xc] */
/* @0x2531a8 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2531ac mov r5, #0 */
/* @0x2531b0 mov r7, #5 */
/* @0x2531b4 ldr r3, [r4, #0xc] */
/* @0x2531b8 ldr r6, [r4, #0x20] */
/* @0x2531bc sub r3, r3, #1 */
/* @0x2531c0 bic r3, r3, #-16777216 */
/* @0x2531c4 bic r3, r3, #3 */
/* @0x2531c8 cmp r3, #0 */
/* @0x2531cc beq 0x2532c0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x50c> */
/* @0x2531d0 ldr r3, [r4, #0x1c] */
/* @0x2531d4 str r5, [r4, #0x8] */
/* @0x2531d8 sub r3, r3, #1 */
/* @0x2531dc str r7, [r4, #0xc] */
/* @0x2531e0 bic r3, r3, #-16777216 */
/* @0x2531e4 str r5, [r4] */
/* @0x2531e8 bic r3, r3, #3 */
/* @0x2531ec cmp r3, #0 */
/* @0x2531f0 bne 0x2531fc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x448> */
/* @0x2531f4 add r0, r4, #16 */
/* @0x2531f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2531fc str r5, [r4, #0x18] */
/* @0x253200 mov r0, r4 */
/* @0x253204 str r7, [r4, #0x1c] */
/* @0x253208 str r5, [r4, #0x10] */
/* @0x25320c mov r4, r6 */
/* @0x253210 bl 0x27d1d0 <_ZdlPv> */
/* @0x253214 cmp r6, #0 */
/* @0x253218 bne 0x2531b4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x400> */
/* @0x25321c ldr r0, [pc, #0x150] */
/* @0x253220 add r0, pc, r0 */
/* @0x253224 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x253228 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x25322c cmp r4, #0 */
/* @0x253230 movne r6, #0 */
/* @0x253234 movne r7, #5 */
/* @0x253238 beq 0x2532a4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4f0> */
/* @0x25323c ldr r3, [r4, #0xc] */
/* @0x253240 ldr r5, [r4, #0x20] */
/* @0x253244 sub r3, r3, #1 */
/* @0x253248 bic r3, r3, #-16777216 */
/* @0x25324c bic r3, r3, #3 */
/* @0x253250 cmp r3, #0 */
/* @0x253254 beq 0x2532cc <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x518> */
/* @0x253258 ldr r3, [r4, #0x1c] */
/* @0x25325c str r6, [r4, #0x8] */
/* @0x253260 sub r3, r3, #1 */
/* @0x253264 str r7, [r4, #0xc] */
/* @0x253268 bic r3, r3, #-16777216 */
/* @0x25326c str r6, [r4] */
/* @0x253270 bic r3, r3, #3 */
/* @0x253274 cmp r3, #0 */
/* @0x253278 bne 0x253284 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4d0> */
/* @0x25327c add r0, r4, #16 */
/* @0x253280 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253284 str r6, [r4, #0x18] */
/* @0x253288 mov r0, r4 */
/* @0x25328c str r7, [r4, #0x1c] */
/* @0x253290 str r6, [r4, #0x10] */
/* @0x253294 mov r4, r5 */
/* @0x253298 bl 0x27d1d0 <_ZdlPv> */
/* @0x25329c cmp r5, #0 */
/* @0x2532a0 bne 0x25323c <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x488> */
/* @0x2532a4 ldr r0, [pc, #0xcc] */
/* @0x2532a8 add r0, pc, r0 */
/* @0x2532ac bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2532b0 b 0x252de8 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2532b4 mov r0, r4 */
/* @0x2532b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2532bc b 0x253138 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x2532c0 mov r0, r4 */
/* @0x2532c4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2532c8 b 0x2531d0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x41c> */
/* @0x2532cc mov r0, r4 */
/* @0x2532d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2532d4 b 0x253258 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x4a4> */
/* @0x2532d8 ldr r0, [r3] */
/* @0x2532dc str r2, [sp, #0x8] */
/* @0x2532e0 str r3, [sp, #0x4] */
/* @0x2532e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2532e8 ldr r3, [sp, #0x4] */
/* @0x2532ec ldr r2, [sp, #0x8] */
/* @0x2532f0 str r2, [r3] */
/* @0x2532f4 str r2, [r3, #0x8] */
/* @0x2532f8 str r3, [sp, #0x4] */
/* @0x2532fc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x253300 ldr r3, [sp, #0x4] */
/* @0x253304 ldr r2, [r3, #0x4] */
/* @0x253308 sub r2, r2, #1 */
/* @0x25330c str r2, [r3, #0x4] */
/* @0x253310 cmp r2, #0 */
/* @0x253314 bne 0x253354 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x5a0> */
/* @0x253318 ldr r0, [r3] */
/* @0x25331c str r2, [sp, #0x8] */
/* @0x253320 str r3, [sp, #0x4] */
/* @0x253324 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253328 ldr r3, [sp, #0x4] */
/* @0x25332c ldr r2, [sp, #0x8] */
/* @0x253330 mov r0, r3 */
/* @0x253334 str r2, [r3] */
/* @0x253338 str r2, [r3, #0x8] */
/* @0x25333c str r3, [sp, #0x4] */
/* @0x253340 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x253344 ldr r3, [sp, #0x4] */
/* @0x253348 mov r0, r3 */
/* @0x25334c bl 0x27d1d0 <_ZdlPv> */
/* @0x253350 ldr r3, [sp, #0x4] */
/* @0x253354 str r3, [sp, #0x4] */
/* @0x253358 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25335c ldr r3, [sp, #0x4] */
/* @0x253360 mov r0, r3 */
/* @0x253364 bl 0x27d1d0 <_ZdlPv> */
/* @0x253368 ldr r3, [sp, #0x4] */
/* @0x25336c b 0x2530b0 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x253370 andseq r3, r0, r8, ror #2 */
/* @0x253374 andseq r2, r0, r8, lsr #26 */
/* @0x253378 andseq r2, r0, r0, lsr #25 */

/* ── FUNC 0x25337c · F_JS_Object_create(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0x25337c push {r4, r5, r6, r7, r8, lr} */
/* @0x253380 subs r8, r3, #0 */
/* @0x253384 sub sp, sp, #8 */
/* @0x253388 mov r6, r1 */
/* @0x25338c mov r7, r2 */
/* @0x253390 mov r5, r0 */
/* @0x253394 ldr r4, [sp, #0x20] */
/* @0x253398 beq 0x2533b8 <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x25339c ldr r12, [r4, #0xc] */
/* @0x2533a0 bic r12, r12, #-16777216 */
/* @0x2533a4 cmp r12, #12 */
/* @0x2533a8 cmpne r12, #6 */
/* @0x2533ac moveq r12, #0 */
/* @0x2533b0 movne r12, #1 */
/* @0x2533b4 beq 0x2533cc <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2533b8 ldr r0, [pc, #0x64] */
/* @0x2533bc add r0, pc, r0 */
/* @0x2533c0 add sp, sp, #8 */
/* @0x2533c4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2533c8 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2533cc mov r1, r12 */
/* @0x2533d0 mov r3, r12 */
/* @0x2533d4 str r12, [sp] */
/* @0x2533d8 mov r2, r12 */
/* @0x2533dc bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x2533e0 ldr r3, [r5] */
/* @0x2533e4 ldr r1, [r4] */
/* @0x2533e8 mov r0, r3 */
/* @0x2533ec str r1, [r3, #0x18] */
/* @0x2533f0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2533f4 cmp r8, #1 */
/* @0x2533f8 ble 0x25341c <_Z18F_JS_Object_createR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x2533fc str r4, [sp, #0x20] */
/* @0x253400 mov r0, r5 */
/* @0x253404 mov r1, r6 */
/* @0x253408 mov r2, r7 */
/* @0x25340c mov r3, #2 */
/* @0x253410 add sp, sp, #8 */
/* @0x253414 pop {r4, r5, r6, r7, r8, lr} */
/* @0x253418 b 0x252db4 <_Z28F_JS_Object_definePropertiesR6RValueP9CInstanceS2_iPS_> */
/* @0x25341c add sp, sp, #8 */
/* @0x253420 pop {r4, r5, r6, r7, r8, pc} */
/* @0x253424 andseq r2, r0, r12, lsl #23 */

/* ── FUNC 0x253428 · JS_Array_prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*) · size=1312 · insn=328 */
/* @0x253428 ldr r12, [pc, #0x500] */
/* @0x25342c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x253430 sub sp, sp, #180 */
/* @0x253434 ldr r2, [pc, #0x4f8] */
/* @0x253438 mov r7, r1 */
/* @0x25343c str r12, [sp, #0x14] */
/* @0x253440 add r12, sp, #60 */
/* @0x253444 str r12, [sp, #0x20] */
/* @0x253448 add r2, pc, r2 */
/* @0x25344c ldr r12, [sp, #0x14] */
/* @0x253450 mov r6, #5 */
/* @0x253454 str r0, [sp, #0x2c] */
/* @0x253458 mov r0, r1 */
/* @0x25345c ldr r12, [pc, r12] */
/* @0x253460 add r1, sp, #60 */
/* @0x253464 str r12, [sp, #0x14] */
/* @0x253468 ldr r3, [r12] */
/* @0x25346c str r6, [sp, #0x48] */
/* @0x253470 str r3, [sp, #0xac] */
/* @0x253474 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x253478 add r0, sp, #60 */
/* @0x25347c mov r1, #0 */
/* @0x253480 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x253484 mov r12, #0 */
/* @0x253488 str r12, [sp, #0x30] */
/* @0x25348c str r12, [sp, #0x34] */
/* @0x253490 str r12, [sp, #0x38] */
/* @0x253494 cmp r0, #0 */
/* @0x253498 str r0, [sp, #0xc] */
/* @0x25349c beq 0x253818 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f0> */
/* @0x2534a0 mov r10, r12 */
/* @0x2534a4 ldr r11, [pc, #0x48c] */
/* @0x2534a8 ldr r12, [pc, #0x48c] */
/* @0x2534ac add r4, sp, #140 */
/* @0x2534b0 add r5, sp, #76 */
/* @0x2534b4 add r11, pc, r11 */
/* @0x2534b8 add r12, pc, r12 */
/* @0x2534bc str r12, [sp, #0x18] */
/* @0x2534c0 ldr r12, [pc, #0x478] */
/* @0x2534c4 add r12, pc, r12 */
/* @0x2534c8 str r12, [sp, #0x10] */
/* @0x2534cc mov r3, r10 */
/* @0x2534d0 mov r1, #32 */
/* @0x2534d4 mov r2, r11 */
/* @0x2534d8 mov r0, r4 */
/* @0x2534dc bl 0xb65c8 <snprintf@plt> */
/* @0x2534e0 mov r2, r4 */
/* @0x2534e4 mov r0, r7 */
/* @0x2534e8 mov r1, r5 */
/* @0x2534ec str r6, [sp, #0x58] */
/* @0x2534f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2534f4 ldr r2, [sp, #0x58] */
/* @0x2534f8 bic r3, r2, #-16777216 */
/* @0x2534fc cmp r3, #12 */
/* @0x253500 beq 0x25365c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x253504 mvn r8, #-16777216 */
/* @0x253508 cmp r3, r8 */
/* @0x25350c beq 0x253654 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x253510 cmp r3, #5 */
/* @0x253514 beq 0x25365c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x253518 add r0, sp, #92 */
/* @0x25351c mov r1, r5 */
/* @0x253520 bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x253524 cmp r0, #1 */
/* @0x253528 beq 0x253820 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f8> */
/* @0x25352c ldr r3, [sp, #0x68] */
/* @0x253530 bic r3, r3, #-16777216 */
/* @0x253534 cmp r3, r8 */
/* @0x253538 beq 0x25357c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x25353c add r8, sp, #108 */
/* @0x253540 ldr r0, [sp, #0x5c] */
/* @0x253544 ldr r2, [sp, #0x18] */
/* @0x253548 mov r1, r8 */
/* @0x25354c str r6, [sp, #0x78] */
/* @0x253550 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x253554 mov r0, r8 */
/* @0x253558 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x25355c cmp r0, #0 */
/* @0x253560 bne 0x2536f4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2cc> */
/* @0x253564 ldr r3, [sp, #0x78] */
/* @0x253568 sub r3, r3, #1 */
/* @0x25356c bic r3, r3, #-16777216 */
/* @0x253570 bic r3, r3, #3 */
/* @0x253574 cmp r3, #0 */
/* @0x253578 beq 0x25380c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3e4> */
/* @0x25357c ldr r2, [sp, #0x58] */
/* @0x253580 mov r8, #0 */
/* @0x253584 sub r2, r2, #1 */
/* @0x253588 bic r2, r2, #-16777216 */
/* @0x25358c bic r2, r2, #3 */
/* @0x253590 cmp r2, #0 */
/* @0x253594 beq 0x253664 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x253598 ldr r12, [sp, #0xc] */
/* @0x25359c add r10, r10, #1 */
/* @0x2535a0 cmp r10, r12 */
/* @0x2535a4 beq 0x25367c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x2535a8 eor r8, r8, #1 */
/* @0x2535ac cmp r10, #0 */
/* @0x2535b0 moveq r8, #0 */
/* @0x2535b4 andne r8, r8, #1 */
/* @0x2535b8 cmp r8, #0 */
/* @0x2535bc beq 0x2534cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x2535c0 ldr r3, [sp, #0x38] */
/* @0x2535c4 ldr r2, [sp, #0x34] */
/* @0x2535c8 mvn r1, r3 */
/* @0x2535cc add r1, r2, r1 */
/* @0x2535d0 cmp r1, #1 */
/* @0x2535d4 bgt 0x253634 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x2535d8 cmp r2, #0 */
/* @0x2535dc add r3, r3, #2 */
/* @0x2535e0 addne r2, r2, r2, lsl #1 */
/* @0x2535e4 ldr r9, [sp, #0x30] */
/* @0x2535e8 moveq r8, #3 */
/* @0x2535ec addne r2, r2, r2, lsr #31 */
/* @0x2535f0 asrne r8, r2, #1 */
/* @0x2535f4 cmp r3, r8 */
/* @0x2535f8 addgt r3, r3, r3, lsl #1 */
/* @0x2535fc addgt r3, r3, r3, lsr #31 */
/* @0x253600 asrgt r8, r3, #1 */
/* @0x253604 mov r0, r8 */
/* @0x253608 bl 0xcef4c <_Z7YYAlloci> */
/* @0x25360c ldr r2, [sp, #0x34] */
/* @0x253610 mov r1, r9 */
/* @0x253614 str r0, [sp, #0x30] */
/* @0x253618 bl 0xb65bc <memcpy@plt> */
/* @0x25361c cmp r9, #0 */
/* @0x253620 str r8, [sp, #0x34] */
/* @0x253624 beq 0x253630 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x253628 mov r0, r9 */
/* @0x25362c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253630 ldr r3, [sp, #0x38] */
/* @0x253634 ldr r12, [sp, #0x10] */
/* @0x253638 ldr r2, [sp, #0x30] */
/* @0x25363c ldrh r1, [r12] */
/* @0x253640 strh r1, [r2, r3] */
/* @0x253644 ldr r3, [sp, #0x38] */
/* @0x253648 add r3, r3, #1 */
/* @0x25364c str r3, [sp, #0x38] */
/* @0x253650 b 0x2534cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x253654 mov r8, #1 */
/* @0x253658 b 0x253584 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x25365c mov r8, #0 */
/* @0x253660 b 0x253584 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x253664 mov r0, r5 */
/* @0x253668 add r10, r10, #1 */
/* @0x25366c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253670 ldr r12, [sp, #0xc] */
/* @0x253674 cmp r10, r12 */
/* @0x253678 bne 0x2535a8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x25367c ldr r3, [sp, #0x38] */
/* @0x253680 cmp r3, #0 */
/* @0x253684 beq 0x253818 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3f0> */
/* @0x253688 ldr r1, [sp, #0x30] */
/* @0x25368c ldr r0, [sp, #0x2c] */
/* @0x253690 mov r3, #0 */
/* @0x253694 str r3, [sp, #0x38] */
/* @0x253698 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x25369c ldr r3, [sp, #0x48] */
/* @0x2536a0 sub r3, r3, #1 */
/* @0x2536a4 bic r3, r3, #-16777216 */
/* @0x2536a8 bic r3, r3, #3 */
/* @0x2536ac cmp r3, #0 */
/* @0x2536b0 beq 0x25383c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x414> */
/* @0x2536b4 ldr r0, [sp, #0x30] */
/* @0x2536b8 mov r3, #0 */
/* @0x2536bc mov r2, #5 */
/* @0x2536c0 str r3, [sp, #0x44] */
/* @0x2536c4 cmp r0, r3 */
/* @0x2536c8 str r3, [sp, #0x3c] */
/* @0x2536cc str r2, [sp, #0x48] */
/* @0x2536d0 beq 0x2536d8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x2536d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2536d8 ldr r12, [sp, #0x14] */
/* @0x2536dc ldr r2, [sp, #0xac] */
/* @0x2536e0 ldr r3, [r12] */
/* @0x2536e4 cmp r2, r3 */
/* @0x2536e8 bne 0x25392c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x504> */
/* @0x2536ec add sp, sp, #180 */
/* @0x2536f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2536f4 add r12, sp, #124 */
/* @0x2536f8 mov r1, #0 */
/* @0x2536fc ldr r0, [sp, #0x5c] */
/* @0x253700 mov r2, r8 */
/* @0x253704 str r1, [sp] */
/* @0x253708 mov r3, #0 */
/* @0x25370c mov r1, r12 */
/* @0x253710 str r12, [sp, #0x1c] */
/* @0x253714 str r6, [sp, #0x88] */
/* @0x253718 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x25371c cmp r0, #2 */
/* @0x253720 beq 0x253848 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x420> */
/* @0x253724 add r0, sp, #124 */
/* @0x253728 mov r1, #0 */
/* @0x25372c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x253730 subs r3, r0, #0 */
/* @0x253734 str r3, [sp, #0x24] */
/* @0x253738 beq 0x2537e8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3c0> */
/* @0x25373c bl 0xb6538 <strlen@plt> */
/* @0x253740 ldr r2, [sp, #0x38] */
/* @0x253744 ldr r3, [sp, #0x34] */
/* @0x253748 add r1, r0, #1 */
/* @0x25374c mov r9, r0 */
/* @0x253750 mvn r0, r2 */
/* @0x253754 add r0, r3, r0 */
/* @0x253758 cmp r1, r0 */
/* @0x25375c ble 0x2537cc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3a4> */
/* @0x253760 cmp r3, #0 */
/* @0x253764 add r2, r1, r2 */
/* @0x253768 ldr r12, [sp, #0x30] */
/* @0x25376c moveq r3, r1 */
/* @0x253770 add r3, r3, r3, lsl #1 */
/* @0x253774 str r12, [sp, #0x28] */
/* @0x253778 add r3, r3, r3, lsr #31 */
/* @0x25377c asr r3, r3, #1 */
/* @0x253780 cmp r3, r2 */
/* @0x253784 addlt r2, r2, r2, lsl #1 */
/* @0x253788 addlt r2, r2, r2, lsr #31 */
/* @0x25378c asrlt r3, r2, #1 */
/* @0x253790 str r3, [sp, #0x8] */
/* @0x253794 mov r0, r3 */
/* @0x253798 bl 0xcef4c <_Z7YYAlloci> */
/* @0x25379c ldr r2, [sp, #0x34] */
/* @0x2537a0 ldr r1, [sp, #0x28] */
/* @0x2537a4 str r0, [sp, #0x30] */
/* @0x2537a8 bl 0xb65bc <memcpy@plt> */
/* @0x2537ac ldr r12, [sp, #0x28] */
/* @0x2537b0 ldr r3, [sp, #0x8] */
/* @0x2537b4 cmp r12, #0 */
/* @0x2537b8 str r3, [sp, #0x34] */
/* @0x2537bc beq 0x2537c8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x3a0> */
/* @0x2537c0 ldr r0, [sp, #0x28] */
/* @0x2537c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2537c8 ldr r2, [sp, #0x38] */
/* @0x2537cc ldr r0, [sp, #0x30] */
/* @0x2537d0 ldr r1, [sp, #0x24] */
/* @0x2537d4 add r0, r0, r2 */
/* @0x2537d8 bl 0xb65a4 <strcpy@plt> */
/* @0x2537dc ldr r3, [sp, #0x38] */
/* @0x2537e0 add r9, r3, r9 */
/* @0x2537e4 str r9, [sp, #0x38] */
/* @0x2537e8 ldr r3, [sp, #0x88] */
/* @0x2537ec sub r3, r3, #1 */
/* @0x2537f0 bic r3, r3, #-16777216 */
/* @0x2537f4 bic r3, r3, #3 */
/* @0x2537f8 cmp r3, #0 */
/* @0x2537fc bne 0x253564 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x253800 add r0, sp, #124 */
/* @0x253804 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253808 b 0x253564 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x25380c mov r0, r8 */
/* @0x253810 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253814 b 0x25357c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x253818 add r1, sp, #56 */
/* @0x25381c b 0x25368c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x253820 ldr r0, [pc, #0x11c] */
/* @0x253824 add r0, pc, r0 */
/* @0x253828 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25382c ldr r0, [sp, #0x30] */
/* @0x253830 cmp r0, #0 */
/* @0x253834 bne 0x2536d4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x253838 b 0x2536d8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x25383c add r0, sp, #60 */
/* @0x253840 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253844 b 0x2536b4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x28c> */
/* @0x253848 ldr r3, [sp, #0x88] */
/* @0x25384c sub r3, r3, #1 */
/* @0x253850 bic r3, r3, #-16777216 */
/* @0x253854 bic r3, r3, #3 */
/* @0x253858 cmp r3, #0 */
/* @0x25385c beq 0x2538fc <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x253860 ldr r1, [sp, #0x78] */
/* @0x253864 mov r3, #0 */
/* @0x253868 str r3, [sp, #0x84] */
/* @0x25386c mov r2, #5 */
/* @0x253870 sub r1, r1, #1 */
/* @0x253874 str r3, [sp, #0x7c] */
/* @0x253878 bic r3, r1, #-16777216 */
/* @0x25387c str r2, [sp, #0x88] */
/* @0x253880 bic r3, r3, #3 */
/* @0x253884 cmp r3, #0 */
/* @0x253888 beq 0x253920 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4f8> */
/* @0x25388c ldr r1, [sp, #0x58] */
/* @0x253890 mov r3, #0 */
/* @0x253894 str r3, [sp, #0x74] */
/* @0x253898 mov r2, #5 */
/* @0x25389c sub r1, r1, #1 */
/* @0x2538a0 str r3, [sp, #0x6c] */
/* @0x2538a4 bic r3, r1, #-16777216 */
/* @0x2538a8 str r2, [sp, #0x78] */
/* @0x2538ac bic r3, r3, #3 */
/* @0x2538b0 cmp r3, #0 */
/* @0x2538b4 beq 0x253914 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4ec> */
/* @0x2538b8 ldr r1, [sp, #0x48] */
/* @0x2538bc mov r3, #0 */
/* @0x2538c0 str r3, [sp, #0x54] */
/* @0x2538c4 mov r2, #5 */
/* @0x2538c8 sub r1, r1, #1 */
/* @0x2538cc str r3, [sp, #0x4c] */
/* @0x2538d0 bic r3, r1, #-16777216 */
/* @0x2538d4 str r2, [sp, #0x58] */
/* @0x2538d8 bic r3, r3, #3 */
/* @0x2538dc cmp r3, #0 */
/* @0x2538e0 beq 0x253908 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4e0> */
/* @0x2538e4 mov r3, #0 */
/* @0x2538e8 mov r2, #5 */
/* @0x2538ec str r3, [sp, #0x44] */
/* @0x2538f0 str r3, [sp, #0x3c] */
/* @0x2538f4 str r2, [sp, #0x48] */
/* @0x2538f8 b 0x25382c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x404> */
/* @0x2538fc add r0, sp, #124 */
/* @0x253900 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253904 b 0x253860 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x438> */
/* @0x253908 add r0, sp, #60 */
/* @0x25390c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253910 b 0x2538e4 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x4bc> */
/* @0x253914 mov r0, r5 */
/* @0x253918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25391c b 0x2538b8 <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x490> */
/* @0x253920 mov r0, r8 */
/* @0x253924 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253928 b 0x25388c <_Z33JS_Array_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x464> */
/* @0x25392c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x253930 ldrsheq r10, [r9], -r4 */
/* @0x253934 andeq sp, sp, r4, lsr #8 */
/* @0x253938 andseq r2, r0, r12, lsr #19 */
/* @0x25393c mulseq r0, r0, r1 */
/* @0x253940 andeq pc, sp, r0, rrx */
/* @0x253944 andseq r2, r0, r12, asr #27 */

/* ── FUNC 0x253948 · JS_RegExp_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=1088 · insn=272 */
/* @0x253948 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25394c add r11, sp, #32 */
/* @0x253950 ldr r5, [pc, #0x40c] */
/* @0x253954 sub sp, sp, #92 */
/* @0x253958 mov r6, r1 */
/* @0x25395c ldr r5, [pc, r5] */
/* @0x253960 ldr r1, [pc, #0x400] */
/* @0x253964 mov r8, r0 */
/* @0x253968 ldr r0, [r6, #0x40] */
/* @0x25396c ldr r3, [r5] */
/* @0x253970 add r1, pc, r1 */
/* @0x253974 str r3, [r11, #-0x28] */
/* @0x253978 bl 0xb6574 <strcmp@plt> */
/* @0x25397c subs r4, r0, #0 */
/* @0x253980 bne 0x253d50 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x408> */
/* @0x253984 sub r7, r11, #104 */
/* @0x253988 ldr r2, [pc, #0x3dc] */
/* @0x25398c mov r0, r6 */
/* @0x253990 str r4, [r11, #-0x68] */
/* @0x253994 add r2, pc, r2 */
/* @0x253998 mov r1, r7 */
/* @0x25399c str r4, [r11, #-0x64] */
/* @0x2539a0 sub r10, r11, #72 */
/* @0x2539a4 str r4, [r11, #-0x60] */
/* @0x2539a8 sub r9, r11, #56 */
/* @0x2539ac str r4, [r11, #-0x5c] */
/* @0x2539b0 str r4, [r11, #-0x58] */
/* @0x2539b4 str r4, [r11, #-0x54] */
/* @0x2539b8 str r4, [r11, #-0x50] */
/* @0x2539bc str r4, [r11, #-0x4c] */
/* @0x2539c0 str r4, [r11, #-0x48] */
/* @0x2539c4 str r4, [r11, #-0x44] */
/* @0x2539c8 str r4, [r11, #-0x40] */
/* @0x2539cc str r4, [r11, #-0x3c] */
/* @0x2539d0 str r4, [r11, #-0x38] */
/* @0x2539d4 str r4, [r11, #-0x34] */
/* @0x2539d8 str r4, [r11, #-0x30] */
/* @0x2539dc str r4, [r11, #-0x2c] */
/* @0x2539e0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2539e4 sub r3, r11, #88 */
/* @0x2539e8 ldr r2, [pc, #0x380] */
/* @0x2539ec mov r0, r6 */
/* @0x2539f0 str r3, [r11, #-0x78] */
/* @0x2539f4 mov r1, r3 */
/* @0x2539f8 add r2, pc, r2 */
/* @0x2539fc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x253a00 ldr r2, [pc, #0x36c] */
/* @0x253a04 mov r1, r10 */
/* @0x253a08 mov r0, r6 */
/* @0x253a0c add r2, pc, r2 */
/* @0x253a10 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x253a14 ldr r2, [pc, #0x35c] */
/* @0x253a18 mov r0, r6 */
/* @0x253a1c mov r1, r9 */
/* @0x253a20 add r2, pc, r2 */
/* @0x253a24 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x253a28 mov r1, r4 */
/* @0x253a2c mov r0, r7 */
/* @0x253a30 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x253a34 ldr r3, [r11, #-0x78] */
/* @0x253a38 mov r1, r4 */
/* @0x253a3c mov r6, r0 */
/* @0x253a40 mov r0, r3 */
/* @0x253a44 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x253a48 mov r1, r4 */
/* @0x253a4c mov r3, r0 */
/* @0x253a50 mov r0, r10 */
/* @0x253a54 str r3, [r11, #-0x78] */
/* @0x253a58 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x253a5c mov r1, r4 */
/* @0x253a60 mov r4, #0 */
/* @0x253a64 mov r10, r0 */
/* @0x253a68 mov r0, r9 */
/* @0x253a6c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x253a70 ldr r3, [r11, #-0x78] */
/* @0x253a74 sub sp, sp, #16 */
/* @0x253a78 str r4, [r11, #-0x74] */
/* @0x253a7c cmp r3, #0 */
/* @0x253a80 str r4, [r11, #-0x70] */
/* @0x253a84 addne r3, sp, #1 */
/* @0x253a88 str r4, [r11, #-0x6c] */
/* @0x253a8c movne r2, #103 */
/* @0x253a90 moveq r3, sp */
/* @0x253a94 mov r9, sp */
/* @0x253a98 strbne r2, [sp] */
/* @0x253a9c cmp r10, #0 */
/* @0x253aa0 movne r2, #105 */
/* @0x253aa4 strbne r2, [r3] */
/* @0x253aa8 addne r3, r3, #1 */
/* @0x253aac cmp r0, #0 */
/* @0x253ab0 mov r0, #3 */
/* @0x253ab4 movne r2, #109 */
/* @0x253ab8 strbne r2, [r3] */
/* @0x253abc addne r3, r3, #1 */
/* @0x253ac0 strb r4, [r3] */
/* @0x253ac4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x253ac8 mov r1, r4 */
/* @0x253acc ldr r2, [r11, #-0x70] */
/* @0x253ad0 str r0, [r11, #-0x74] */
/* @0x253ad4 bl 0xb65bc <memcpy@plt> */
/* @0x253ad8 ldr r1, [pc, #0x29c] */
/* @0x253adc mov r0, #3 */
/* @0x253ae0 ldr r3, [r11, #-0x6c] */
/* @0x253ae4 cmp r6, r4 */
/* @0x253ae8 add r1, pc, r1 */
/* @0x253aec ldr r2, [r11, #-0x74] */
/* @0x253af0 str r0, [r11, #-0x70] */
/* @0x253af4 ldrh r1, [r1] */
/* @0x253af8 strh r1, [r2, r3] */
/* @0x253afc ldr r4, [r11, #-0x6c] */
/* @0x253b00 add r4, r4, #1 */
/* @0x253b04 str r4, [r11, #-0x6c] */
/* @0x253b08 beq 0x253bb0 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x253b0c mov r0, r6 */
/* @0x253b10 bl 0xb6538 <strlen@plt> */
/* @0x253b14 ldr r3, [r11, #-0x70] */
/* @0x253b18 mvn r1, r4 */
/* @0x253b1c add r1, r3, r1 */
/* @0x253b20 add r2, r0, #1 */
/* @0x253b24 mov r10, r0 */
/* @0x253b28 cmp r2, r1 */
/* @0x253b2c ble 0x253b94 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x253b30 cmp r3, #0 */
/* @0x253b34 add r4, r4, r2 */
/* @0x253b38 moveq r3, r2 */
/* @0x253b3c add r3, r3, r3, lsl #1 */
/* @0x253b40 add r3, r3, r3, lsr #31 */
/* @0x253b44 asr r3, r3, #1 */
/* @0x253b48 cmp r3, r4 */
/* @0x253b4c addlt r4, r4, r4, lsl #1 */
/* @0x253b50 addlt r4, r4, r4, lsr #31 */
/* @0x253b54 asrlt r3, r4, #1 */
/* @0x253b58 ldr r4, [r11, #-0x74] */
/* @0x253b5c str r3, [r11, #-0x78] */
/* @0x253b60 mov r0, r3 */
/* @0x253b64 bl 0xcef4c <_Z7YYAlloci> */
/* @0x253b68 ldr r2, [r11, #-0x70] */
/* @0x253b6c mov r1, r4 */
/* @0x253b70 str r0, [r11, #-0x74] */
/* @0x253b74 bl 0xb65bc <memcpy@plt> */
/* @0x253b78 ldr r3, [r11, #-0x78] */
/* @0x253b7c cmp r4, #0 */
/* @0x253b80 str r3, [r11, #-0x70] */
/* @0x253b84 beq 0x253b90 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x253b88 mov r0, r4 */
/* @0x253b8c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253b90 ldr r4, [r11, #-0x6c] */
/* @0x253b94 ldr r0, [r11, #-0x74] */
/* @0x253b98 mov r1, r6 */
/* @0x253b9c add r0, r0, r4 */
/* @0x253ba0 bl 0xb65a4 <strcpy@plt> */
/* @0x253ba4 ldr r4, [r11, #-0x6c] */
/* @0x253ba8 add r4, r10, r4 */
/* @0x253bac str r4, [r11, #-0x6c] */
/* @0x253bb0 ldr r3, [r11, #-0x70] */
/* @0x253bb4 mvn r2, r4 */
/* @0x253bb8 add r2, r3, r2 */
/* @0x253bbc cmp r2, #1 */
/* @0x253bc0 bgt 0x253c20 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2d8> */
/* @0x253bc4 cmp r3, #0 */
/* @0x253bc8 add r4, r4, #2 */
/* @0x253bcc addne r3, r3, r3, lsl #1 */
/* @0x253bd0 moveq r6, #3 */
/* @0x253bd4 addne r3, r3, r3, lsr #31 */
/* @0x253bd8 asrne r6, r3, #1 */
/* @0x253bdc cmp r4, r6 */
/* @0x253be0 addgt r4, r4, r4, lsl #1 */
/* @0x253be4 addgt r4, r4, r4, lsr #31 */
/* @0x253be8 asrgt r6, r4, #1 */
/* @0x253bec ldr r4, [r11, #-0x74] */
/* @0x253bf0 mov r0, r6 */
/* @0x253bf4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x253bf8 ldr r2, [r11, #-0x70] */
/* @0x253bfc mov r1, r4 */
/* @0x253c00 str r0, [r11, #-0x74] */
/* @0x253c04 bl 0xb65bc <memcpy@plt> */
/* @0x253c08 cmp r4, #0 */
/* @0x253c0c str r6, [r11, #-0x70] */
/* @0x253c10 beq 0x253c1c <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x253c14 mov r0, r4 */
/* @0x253c18 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253c1c ldr r4, [r11, #-0x6c] */
/* @0x253c20 ldr r2, [pc, #0x158] */
/* @0x253c24 mov r0, r9 */
/* @0x253c28 ldr r3, [r11, #-0x74] */
/* @0x253c2c add r2, pc, r2 */
/* @0x253c30 ldrh r2, [r2] */
/* @0x253c34 strh r2, [r3, r4] */
/* @0x253c38 ldr r4, [r11, #-0x6c] */
/* @0x253c3c add r4, r4, #1 */
/* @0x253c40 str r4, [r11, #-0x6c] */
/* @0x253c44 bl 0xb6538 <strlen@plt> */
/* @0x253c48 ldr r3, [r11, #-0x70] */
/* @0x253c4c mvn r1, r4 */
/* @0x253c50 add r1, r3, r1 */
/* @0x253c54 add r2, r0, #1 */
/* @0x253c58 mov r6, r0 */
/* @0x253c5c cmp r2, r1 */
/* @0x253c60 ble 0x253cc0 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x378> */
/* @0x253c64 cmp r3, #0 */
/* @0x253c68 add r4, r4, r2 */
/* @0x253c6c moveq r3, r2 */
/* @0x253c70 add r3, r3, r3, lsl #1 */
/* @0x253c74 add r3, r3, r3, lsr #31 */
/* @0x253c78 asr r10, r3, #1 */
/* @0x253c7c cmp r10, r4 */
/* @0x253c80 addlt r4, r4, r4, lsl #1 */
/* @0x253c84 addlt r4, r4, r4, lsr #31 */
/* @0x253c88 asrlt r10, r4, #1 */
/* @0x253c8c ldr r4, [r11, #-0x74] */
/* @0x253c90 mov r0, r10 */
/* @0x253c94 bl 0xcef4c <_Z7YYAlloci> */
/* @0x253c98 ldr r2, [r11, #-0x70] */
/* @0x253c9c mov r1, r4 */
/* @0x253ca0 str r0, [r11, #-0x74] */
/* @0x253ca4 bl 0xb65bc <memcpy@plt> */
/* @0x253ca8 cmp r4, #0 */
/* @0x253cac str r10, [r11, #-0x70] */
/* @0x253cb0 beq 0x253cbc <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x253cb4 mov r0, r4 */
/* @0x253cb8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253cbc ldr r4, [r11, #-0x6c] */
/* @0x253cc0 ldr r0, [r11, #-0x74] */
/* @0x253cc4 mov r1, r9 */
/* @0x253cc8 add r0, r0, r4 */
/* @0x253ccc bl 0xb65a4 <strcpy@plt> */
/* @0x253cd0 ldr r3, [r11, #-0x6c] */
/* @0x253cd4 mov r0, r8 */
/* @0x253cd8 add r6, r6, r3 */
/* @0x253cdc mov r3, #0 */
/* @0x253ce0 cmp r6, #0 */
/* @0x253ce4 str r3, [r11, #-0x6c] */
/* @0x253ce8 subeq r1, r11, #108 */
/* @0x253cec ldrne r1, [r11, #-0x74] */
/* @0x253cf0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x253cf4 ldr r3, [r11, #-0x5c] */
/* @0x253cf8 sub r3, r3, #1 */
/* @0x253cfc bic r3, r3, #-16777216 */
/* @0x253d00 bic r3, r3, #3 */
/* @0x253d04 cmp r3, #0 */
/* @0x253d08 bne 0x253d14 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3cc> */
/* @0x253d0c mov r0, r7 */
/* @0x253d10 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253d14 ldr r0, [r11, #-0x74] */
/* @0x253d18 mov r3, #0 */
/* @0x253d1c mov r2, #5 */
/* @0x253d20 str r3, [r11, #-0x60] */
/* @0x253d24 cmp r0, r3 */
/* @0x253d28 str r3, [r11, #-0x68] */
/* @0x253d2c str r2, [r11, #-0x5c] */
/* @0x253d30 beq 0x253d38 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3f0> */
/* @0x253d34 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x253d38 ldr r2, [r11, #-0x28] */
/* @0x253d3c ldr r3, [r5] */
/* @0x253d40 cmp r2, r3 */
/* @0x253d44 bne 0x253d60 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x418> */
/* @0x253d48 sub sp, r11, #32 */
/* @0x253d4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x253d50 ldr r0, [pc, #0x2c] */
/* @0x253d54 add r0, pc, r0 */
/* @0x253d58 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x253d5c b 0x253d38 <_Z28JS_RegExp_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x3f0> */
/* @0x253d60 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x253d64 ldrsheq r9, [r9], -r4 */
/* @0x253d68 ldrheq r2, [r0], -r12 */
/* @0x253d6c mulseq r0, r8, r12 */
/* @0x253d70 andeq r1, lr, r0, ror #9 */
/* @0x253d74 andseq r2, r0, r8, lsr #24 */
/* @0x253d78 andseq r2, r0, r0, lsr #24 */
/* @0x253d7c andeq sp, sp, r4, lsr #1 */
/* @0x253d80 andeq r12, sp, r0, ror #30 */
/* @0x253d84 ldrsheq r2, [r0], -r4 */

/* ── FUNC 0x253d88 · JSThrowSyntaxError(char const*) · size=284 · insn=71 */
/* @0x253d88 push {r4, r5, r6, r7, lr} */
/* @0x253d8c sub sp, sp, #60 */
/* @0x253d90 add r6, sp, #8 */
/* @0x253d94 add r5, sp, #24 */
/* @0x253d98 mov r4, #0 */
/* @0x253d9c mov r1, r0 */
/* @0x253da0 add r7, sp, #40 */
/* @0x253da4 mov r0, r6 */
/* @0x253da8 str r4, [sp, #0x8] */
/* @0x253dac str r4, [sp, #0xc] */
/* @0x253db0 str r4, [sp, #0x10] */
/* @0x253db4 str r4, [sp, #0x14] */
/* @0x253db8 str r4, [sp, #0x18] */
/* @0x253dbc str r4, [sp, #0x1c] */
/* @0x253dc0 str r4, [sp, #0x20] */
/* @0x253dc4 str r4, [sp, #0x24] */
/* @0x253dc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x253dcc mov r1, r4 */
/* @0x253dd0 mov r2, r4 */
/* @0x253dd4 mov r0, r5 */
/* @0x253dd8 mov r3, #1 */
/* @0x253ddc str r6, [sp] */
/* @0x253de0 bl 0x2440e4 <_Z19F_JSSyntaxErrorCallR6RValueP9CInstanceS2_iPS_> */
/* @0x253de4 mov r3, #1 */
/* @0x253de8 mov r1, r4 */
/* @0x253dec str r5, [sp] */
/* @0x253df0 mov r2, r4 */
/* @0x253df4 mov r0, r7 */
/* @0x253df8 str r4, [sp, #0x28] */
/* @0x253dfc str r4, [sp, #0x2c] */
/* @0x253e00 str r4, [sp, #0x30] */
/* @0x253e04 str r4, [sp, #0x34] */
/* @0x253e08 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_> */
/* @0x253e0c ldr r3, [sp, #0x14] */
/* @0x253e10 sub r3, r3, #1 */
/* @0x253e14 bic r3, r3, #-16777216 */
/* @0x253e18 bic r3, r3, #3 */
/* @0x253e1c cmp r3, r4 */
/* @0x253e20 beq 0x253e98 <_Z18JSThrowSyntaxErrorPKc+0x110> */
/* @0x253e24 ldr r1, [sp, #0x24] */
/* @0x253e28 mov r3, #0 */
/* @0x253e2c str r3, [sp, #0x10] */
/* @0x253e30 mov r2, #5 */
/* @0x253e34 sub r1, r1, #1 */
/* @0x253e38 str r3, [sp, #0x8] */
/* @0x253e3c bic r3, r1, #-16777216 */
/* @0x253e40 str r2, [sp, #0x14] */
/* @0x253e44 bic r3, r3, #3 */
/* @0x253e48 cmp r3, #0 */
/* @0x253e4c beq 0x253e8c <_Z18JSThrowSyntaxErrorPKc+0x104> */
/* @0x253e50 ldr r1, [sp, #0x34] */
/* @0x253e54 mov r3, #0 */
/* @0x253e58 str r3, [sp, #0x20] */
/* @0x253e5c mov r2, #5 */
/* @0x253e60 sub r1, r1, #1 */
/* @0x253e64 str r3, [sp, #0x18] */
/* @0x253e68 bic r3, r1, #-16777216 */
/* @0x253e6c str r2, [sp, #0x24] */
/* @0x253e70 bic r3, r3, #3 */
/* @0x253e74 cmp r3, #0 */
/* @0x253e78 bne 0x253e84 <_Z18JSThrowSyntaxErrorPKc+0xfc> */
/* @0x253e7c mov r0, r7 */
/* @0x253e80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253e84 add sp, sp, #60 */
/* @0x253e88 pop {r4, r5, r6, r7, pc} */
/* @0x253e8c mov r0, r5 */
/* @0x253e90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253e94 b 0x253e50 <_Z18JSThrowSyntaxErrorPKc+0xc8> */
/* @0x253e98 mov r0, r6 */
/* @0x253e9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253ea0 b 0x253e24 <_Z18JSThrowSyntaxErrorPKc+0x9c> */

/* ── FUNC 0x253ea4 · JSThrowRangeError(char const*) · size=284 · insn=71 */
/* @0x253ea4 push {r4, r5, r6, r7, lr} */
/* @0x253ea8 sub sp, sp, #60 */
/* @0x253eac add r6, sp, #8 */
/* @0x253eb0 add r5, sp, #24 */
/* @0x253eb4 mov r4, #0 */
/* @0x253eb8 mov r1, r0 */
/* @0x253ebc add r7, sp, #40 */
/* @0x253ec0 mov r0, r6 */
/* @0x253ec4 str r4, [sp, #0x8] */
/* @0x253ec8 str r4, [sp, #0xc] */
/* @0x253ecc str r4, [sp, #0x10] */
/* @0x253ed0 str r4, [sp, #0x14] */
/* @0x253ed4 str r4, [sp, #0x18] */
/* @0x253ed8 str r4, [sp, #0x1c] */
/* @0x253edc str r4, [sp, #0x20] */
/* @0x253ee0 str r4, [sp, #0x24] */
/* @0x253ee4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x253ee8 mov r1, r4 */
/* @0x253eec mov r2, r4 */
/* @0x253ef0 mov r0, r5 */
/* @0x253ef4 mov r3, #1 */
/* @0x253ef8 str r6, [sp] */
/* @0x253efc bl 0x244044 <_Z18F_JSRangeErrorCallR6RValueP9CInstanceS2_iPS_> */
/* @0x253f00 mov r3, #1 */
/* @0x253f04 mov r1, r4 */
/* @0x253f08 str r5, [sp] */
/* @0x253f0c mov r2, r4 */
/* @0x253f10 mov r0, r7 */
/* @0x253f14 str r4, [sp, #0x28] */
/* @0x253f18 str r4, [sp, #0x2c] */
/* @0x253f1c str r4, [sp, #0x30] */
/* @0x253f20 str r4, [sp, #0x34] */
/* @0x253f24 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_> */
/* @0x253f28 ldr r3, [sp, #0x14] */
/* @0x253f2c sub r3, r3, #1 */
/* @0x253f30 bic r3, r3, #-16777216 */
/* @0x253f34 bic r3, r3, #3 */
/* @0x253f38 cmp r3, r4 */
/* @0x253f3c beq 0x253fb4 <_Z17JSThrowRangeErrorPKc+0x110> */
/* @0x253f40 ldr r1, [sp, #0x24] */
/* @0x253f44 mov r3, #0 */
/* @0x253f48 str r3, [sp, #0x10] */
/* @0x253f4c mov r2, #5 */
/* @0x253f50 sub r1, r1, #1 */
/* @0x253f54 str r3, [sp, #0x8] */
/* @0x253f58 bic r3, r1, #-16777216 */
/* @0x253f5c str r2, [sp, #0x14] */
/* @0x253f60 bic r3, r3, #3 */
/* @0x253f64 cmp r3, #0 */
/* @0x253f68 beq 0x253fa8 <_Z17JSThrowRangeErrorPKc+0x104> */
/* @0x253f6c ldr r1, [sp, #0x34] */
/* @0x253f70 mov r3, #0 */
/* @0x253f74 str r3, [sp, #0x20] */
/* @0x253f78 mov r2, #5 */
/* @0x253f7c sub r1, r1, #1 */
/* @0x253f80 str r3, [sp, #0x18] */
/* @0x253f84 bic r3, r1, #-16777216 */
/* @0x253f88 str r2, [sp, #0x24] */
/* @0x253f8c bic r3, r3, #3 */
/* @0x253f90 cmp r3, #0 */
/* @0x253f94 bne 0x253fa0 <_Z17JSThrowRangeErrorPKc+0xfc> */
/* @0x253f98 mov r0, r7 */
/* @0x253f9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253fa0 add sp, sp, #60 */
/* @0x253fa4 pop {r4, r5, r6, r7, pc} */
/* @0x253fa8 mov r0, r5 */
/* @0x253fac bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253fb0 b 0x253f6c <_Z17JSThrowRangeErrorPKc+0xc8> */
/* @0x253fb4 mov r0, r6 */
/* @0x253fb8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x253fbc b 0x253f40 <_Z17JSThrowRangeErrorPKc+0x9c> */

/* ── FUNC 0x253fc0 · F_JSArrayCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=1608 · insn=402 */
/* @0x253fc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x253fc4 cmp r3, #1 */
/* @0x253fc8 sub sp, sp, #20 */
/* @0x253fcc mov r4, r3 */
/* @0x253fd0 mov r9, r0 */
/* @0x253fd4 mov r11, r1 */
/* @0x253fd8 mov r10, r2 */
/* @0x253fdc ldr r8, [sp, #0x38] */
/* @0x253fe0 beq 0x2541e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x253fe4 str r8, [sp] */
/* @0x253fe8 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x253fec ldr r0, [r9] */
/* @0x253ff0 ldr r3, [r0, #0x4] */
/* @0x253ff4 cmp r3, #0 */
/* @0x253ff8 beq 0x254494 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x253ffc add r0, r3, #16 */
/* @0x254000 ldr r5, [r0] */
/* @0x254004 mov r0, r5 */
/* @0x254008 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x25400c subs r6, r4, #1 */
/* @0x254010 str r4, [r5, #0x24] */
/* @0x254014 ldr r4, [r5, #0x4] */
/* @0x254018 movpl r9, #0 */
/* @0x25401c addpl r5, r8, #16 */
/* @0x254020 movpl r10, #6 */
/* @0x254024 addpl r4, r4, #16 */
/* @0x254028 bmi 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x25402c ldr r2, [r4, #-0x4] */
/* @0x254030 sub r8, r5, #16 */
/* @0x254034 sub r7, r4, #16 */
/* @0x254038 bic r3, r2, #-16777216 */
/* @0x25403c cmp r3, #1 */
/* @0x254040 beq 0x254170 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x254044 cmp r3, #2 */
/* @0x254048 bne 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x25404c sub r2, r2, #1 */
/* @0x254050 bic r2, r2, #-16777216 */
/* @0x254054 bic r2, r2, #3 */
/* @0x254058 cmp r2, #0 */
/* @0x25405c beq 0x2541dc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x254060 mov r3, #5 */
/* @0x254064 str r9, [r4, #-0x8] */
/* @0x254068 str r3, [r4, #-0x4] */
/* @0x25406c str r9, [r4, #-0x10] */
/* @0x254070 ldr r3, [r5, #-0x4] */
/* @0x254074 str r3, [r4, #-0x4] */
/* @0x254078 ldr r3, [r5, #-0x8] */
/* @0x25407c str r3, [r4, #-0x8] */
/* @0x254080 ldr r3, [r5, #-0x4] */
/* @0x254084 bic r3, r3, #-16777216 */
/* @0x254088 cmp r3, #14 */
/* @0x25408c addls pc, pc, r3, lsl #2 */
/* @0x254090 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x254094 b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x254098 b 0x254158 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25409c b 0x25412c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x2540a0 b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x2540a4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540a8 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540ac b 0x254108 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x2540b0 b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x2540b4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540b8 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540bc b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x2540c0 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540c4 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x2540c8 b 0x2540fc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x2540cc b 0x2540d0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x2540d0 ldr r3, [r5, #-0x10] */
/* @0x2540d4 str r3, [r4, #-0x10] */
/* @0x2540d8 sub r6, r6, #1 */
/* @0x2540dc str r10, [r4, #-0x8] */
/* @0x2540e0 cmn r6, #1 */
/* @0x2540e4 add r5, r5, #16 */
/* @0x2540e8 add r4, r4, #16 */
/* @0x2540ec bne 0x25402c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x2540f0 add sp, sp, #20 */
/* @0x2540f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2540f8 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x2540fc ldm r8, {r2, r3} */
/* @0x254100 stm r7, {r2, r3} */
/* @0x254104 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x254108 ldr r3, [r5, #-0x10] */
/* @0x25410c str r3, [r4, #-0x10] */
/* @0x254110 ldr r3, [r5, #-0x10] */
/* @0x254114 cmp r3, #0 */
/* @0x254118 beq 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x25411c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x254120 ldr r1, [r5, #-0x10] */
/* @0x254124 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x254128 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x25412c ldr r3, [r5, #-0x10] */
/* @0x254130 cmp r3, #0 */
/* @0x254134 str r3, [r4, #-0x10] */
/* @0x254138 beq 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x25413c ldr r1, [r3, #0x8] */
/* @0x254140 ldr r2, [r3] */
/* @0x254144 cmp r1, #0 */
/* @0x254148 streq r7, [r3, #0x8] */
/* @0x25414c add r2, r2, #1 */
/* @0x254150 str r2, [r3] */
/* @0x254154 b 0x2540d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x254158 ldr r3, [r5, #-0x10] */
/* @0x25415c cmp r3, #0 */
/* @0x254160 ldrne r2, [r3, #0x4] */
/* @0x254164 addne r2, r2, #1 */
/* @0x254168 strne r2, [r3, #0x4] */
/* @0x25416c b 0x2540d4 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x254170 ldr r11, [r4, #-0x10] */
/* @0x254174 cmp r11, #0 */
/* @0x254178 beq 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x25417c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x254180 ldr r2, [r11, #0x4] */
/* @0x254184 sub r2, r2, #1 */
/* @0x254188 str r2, [r11, #0x4] */
/* @0x25418c cmp r2, #0 */
/* @0x254190 beq 0x25419c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x254194 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x254198 b 0x25406c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x25419c ldr r0, [r11] */
/* @0x2541a0 str r2, [sp, #0xc] */
/* @0x2541a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2541a8 ldr r2, [sp, #0xc] */
/* @0x2541ac str r2, [r11] */
/* @0x2541b0 str r2, [r11, #0x8] */
/* @0x2541b4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2541b8 ldr r2, [r11, #0x4] */
/* @0x2541bc sub r2, r2, #1 */
/* @0x2541c0 str r2, [r11, #0x4] */
/* @0x2541c4 cmp r2, #0 */
/* @0x2541c8 beq 0x2543b8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3f8> */
/* @0x2541cc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2541d0 mov r0, r11 */
/* @0x2541d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2541d8 b 0x254194 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x2541dc mov r0, r7 */
/* @0x2541e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2541e4 b 0x254060 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x2541e8 ldr r12, [r8, #0xc] */
/* @0x2541ec bic r12, r12, #-16777216 */
/* @0x2541f0 cmp r12, #7 */
/* @0x2541f4 beq 0x254388 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3c8> */
/* @0x2541f8 cmp r12, #10 */
/* @0x2541fc beq 0x254388 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3c8> */
/* @0x254200 cmp r12, #0 */
/* @0x254204 beq 0x2542d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x318> */
/* @0x254208 str r8, [sp] */
/* @0x25420c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x254210 ldr r0, [r9] */
/* @0x254214 ldr r3, [r0, #0x4] */
/* @0x254218 cmp r3, #0 */
/* @0x25421c addne r0, r3, #16 */
/* @0x254220 beq 0x25455c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x59c> */
/* @0x254224 ldr r4, [r0] */
/* @0x254228 mov r0, r4 */
/* @0x25422c bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x254230 ldr r4, [r4, #0x4] */
/* @0x254234 ldr r2, [r4, #0xc] */
/* @0x254238 bic r3, r2, #-16777216 */
/* @0x25423c cmp r3, #1 */
/* @0x254240 beq 0x2543f8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x438> */
/* @0x254244 cmp r3, #2 */
/* @0x254248 bne 0x254270 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x25424c sub r3, r2, #1 */
/* @0x254250 bic r3, r3, #-16777216 */
/* @0x254254 bic r3, r3, #3 */
/* @0x254258 cmp r3, #0 */
/* @0x25425c beq 0x254550 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x590> */
/* @0x254260 mov r2, #0 */
/* @0x254264 mov r3, #5 */
/* @0x254268 str r2, [r4, #0x8] */
/* @0x25426c str r3, [r4, #0xc] */
/* @0x254270 ldr r3, [r8, #0xc] */
/* @0x254274 mov r1, #0 */
/* @0x254278 ldr r2, [r8, #0x8] */
/* @0x25427c str r1, [r4] */
/* @0x254280 str r3, [r4, #0xc] */
/* @0x254284 ldr r3, [r8, #0xc] */
/* @0x254288 str r2, [r4, #0x8] */
/* @0x25428c bic r3, r3, #-16777216 */
/* @0x254290 cmp r3, #14 */
/* @0x254294 addls pc, pc, r3, lsl #2 */
/* @0x254298 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x25429c b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388> */
/* @0x2542a0 b 0x25447c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4bc> */
/* @0x2542a4 b 0x254450 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x490> */
/* @0x2542a8 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2542ac b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542b0 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542b4 b 0x25442c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x46c> */
/* @0x2542b8 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2542bc b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542c0 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542c4 b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388> */
/* @0x2542c8 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542cc b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2542d0 b 0x254348 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x388> */
/* @0x2542d4 b 0x254334 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2542d8 mov r1, r12 */
/* @0x2542dc mov r0, r8 */
/* @0x2542e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2542e4 vmov d7, r0, r1 */
/* @0x2542e8 vcmpe.f64 d7, #0 */
/* @0x2542ec vmrs APSR_nzcv, fpscr */
/* @0x2542f0 bmi 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394> */
/* @0x2542f4 vldr d6, [pc, #764] */
/* @0x2542f8 vcmpe.f64 d7, d6 */
/* @0x2542fc vmrs APSR_nzcv, fpscr */
/* @0x254300 bgt 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394> */
/* @0x254304 vcmp.f64 d7, d7 */
/* @0x254308 vmrs APSR_nzcv, fpscr */
/* @0x25430c bvs 0x254354 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x394> */
/* @0x254310 vcvt.u32.f64 s11, d7 */
/* @0x254314 vcvt.f64.u32 d6, s11 */
/* @0x254318 vsub.f64 d6, d7, d6 */
/* @0x25431c vcmp.f64 d6, #0 */
/* @0x254320 vmrs APSR_nzcv, fpscr */
/* @0x254324 vmoveq r3, s11 */
/* @0x254328 beq 0x25436c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3ac> */
/* @0x25432c vmov r4, s11 */
/* @0x254330 b 0x25435c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x254334 ldr r3, [r8] */
/* @0x254338 str r3, [r4] */
/* @0x25433c add sp, sp, #20 */
/* @0x254340 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x254344 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x254348 ldm r8, {r2, r3} */
/* @0x25434c stm r4, {r2, r3} */
/* @0x254350 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x254354 vcvt.u32.f64 s13, d7 */
/* @0x254358 vmov r4, s13 */
/* @0x25435c ldr r0, [pc, #0x29c] */
/* @0x254360 add r0, pc, r0 */
/* @0x254364 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x254368 mov r3, r4 */
/* @0x25436c str r8, [sp, #0x38] */
/* @0x254370 mov r0, r9 */
/* @0x254374 mov r1, r11 */
/* @0x254378 mov r2, r10 */
/* @0x25437c add sp, sp, #20 */
/* @0x254380 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x254384 b 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x254388 mov r0, r8 */
/* @0x25438c mov r1, #0 */
/* @0x254390 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0x254394 mvn r6, #0 */
/* @0x254398 mov r7, #0 */
/* @0x25439c mov r4, r0 */
/* @0x2543a0 mov r5, r1 */
/* @0x2543a4 cmp r5, r7 */
/* @0x2543a8 cmpeq r4, r6 */
/* @0x2543ac bhi 0x254540 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x580> */
/* @0x2543b0 mov r3, r4 */
/* @0x2543b4 b 0x25436c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3ac> */
/* @0x2543b8 ldr r0, [r11] */
/* @0x2543bc str r2, [sp, #0xc] */
/* @0x2543c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2543c4 ldr r2, [sp, #0xc] */
/* @0x2543c8 str r2, [r11] */
/* @0x2543cc str r2, [r11, #0x8] */
/* @0x2543d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2543d4 ldr r2, [r11, #0x4] */
/* @0x2543d8 sub r2, r2, #1 */
/* @0x2543dc str r2, [r11, #0x4] */
/* @0x2543e0 cmp r2, #0 */
/* @0x2543e4 beq 0x2544d8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x518> */
/* @0x2543e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2543ec mov r0, r11 */
/* @0x2543f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2543f4 b 0x2541cc <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x2543f8 ldr r5, [r4] */
/* @0x2543fc cmp r5, #0 */
/* @0x254400 beq 0x254420 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x460> */
/* @0x254404 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x254408 ldr r6, [r5, #0x4] */
/* @0x25440c sub r6, r6, #1 */
/* @0x254410 str r6, [r5, #0x4] */
/* @0x254414 cmp r6, #0 */
/* @0x254418 beq 0x2544a0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x4e0> */
/* @0x25441c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x254420 mov r3, #0 */
/* @0x254424 str r3, [r4] */
/* @0x254428 b 0x254270 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x25442c ldr r3, [r8] */
/* @0x254430 str r3, [r4] */
/* @0x254434 ldr r3, [r8] */
/* @0x254438 cmp r3, #0 */
/* @0x25443c beq 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x254440 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x254444 ldr r1, [r8] */
/* @0x254448 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x25444c b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x254450 ldr r3, [r8] */
/* @0x254454 cmp r3, #0 */
/* @0x254458 str r3, [r4] */
/* @0x25445c beq 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x254460 ldr r1, [r3, #0x8] */
/* @0x254464 ldr r2, [r3] */
/* @0x254468 cmp r1, #0 */
/* @0x25446c streq r4, [r3, #0x8] */
/* @0x254470 add r2, r2, #1 */
/* @0x254474 str r2, [r3] */
/* @0x254478 b 0x2540f0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x25447c ldr r3, [r8] */
/* @0x254480 cmp r3, #0 */
/* @0x254484 ldrne r2, [r3, #0x4] */
/* @0x254488 addne r2, r2, #1 */
/* @0x25448c strne r2, [r3, #0x4] */
/* @0x254490 b 0x254338 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x378> */
/* @0x254494 mov r1, #1 */
/* @0x254498 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25449c b 0x254000 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2544a0 ldr r0, [r5] */
/* @0x2544a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2544a8 str r6, [r5] */
/* @0x2544ac str r6, [r5, #0x8] */
/* @0x2544b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2544b4 ldr r6, [r5, #0x4] */
/* @0x2544b8 sub r6, r6, #1 */
/* @0x2544bc str r6, [r5, #0x4] */
/* @0x2544c0 cmp r6, #0 */
/* @0x2544c4 beq 0x254568 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5a8> */
/* @0x2544c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2544cc mov r0, r5 */
/* @0x2544d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2544d4 b 0x25441c <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x45c> */
/* @0x2544d8 ldr r0, [r11] */
/* @0x2544dc str r2, [sp, #0xc] */
/* @0x2544e0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2544e4 ldr r2, [sp, #0xc] */
/* @0x2544e8 str r2, [r11] */
/* @0x2544ec str r2, [r11, #0x8] */
/* @0x2544f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2544f4 ldr r2, [r11, #0x4] */
/* @0x2544f8 sub r2, r2, #1 */
/* @0x2544fc str r2, [r11, #0x4] */
/* @0x254500 cmp r2, #0 */
/* @0x254504 bne 0x254530 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x570> */
/* @0x254508 ldr r0, [r11] */
/* @0x25450c str r2, [sp, #0xc] */
/* @0x254510 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x254514 ldr r2, [sp, #0xc] */
/* @0x254518 mov r0, r11 */
/* @0x25451c str r2, [r11] */
/* @0x254520 str r2, [r11, #0x8] */
/* @0x254524 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x254528 mov r0, r11 */
/* @0x25452c bl 0x27d1d0 <_ZdlPv> */
/* @0x254530 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x254534 mov r0, r11 */
/* @0x254538 bl 0x27d1d0 <_ZdlPv> */
/* @0x25453c b 0x2543e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x428> */
/* @0x254540 ldr r0, [pc, #0xbc] */
/* @0x254544 add r0, pc, r0 */
/* @0x254548 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x25454c b 0x2543b0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x3f0> */
/* @0x254550 mov r0, r4 */
/* @0x254554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x254558 b 0x254260 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x25455c mov r1, r4 */
/* @0x254560 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x254564 b 0x254224 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x254568 ldr r0, [r5] */
/* @0x25456c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x254570 str r6, [r5] */
/* @0x254574 str r6, [r5, #0x8] */
/* @0x254578 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25457c ldr r6, [r5, #0x4] */
/* @0x254580 sub r6, r6, #1 */
/* @0x254584 str r6, [r5, #0x4] */
/* @0x254588 cmp r6, #0 */
/* @0x25458c beq 0x2545a0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5e0> */
/* @0x254590 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x254594 mov r0, r5 */
/* @0x254598 bl 0x27d1d0 <_ZdlPv> */
/* @0x25459c b 0x2544c8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x508> */
/* @0x2545a0 ldr r0, [r5] */
/* @0x2545a4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2545a8 str r6, [r5] */
/* @0x2545ac str r6, [r5, #0x8] */
/* @0x2545b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2545b4 ldr r6, [r5, #0x4] */
/* @0x2545b8 sub r6, r6, #1 */
/* @0x2545bc str r6, [r5, #0x4] */
/* @0x2545c0 cmp r6, #0 */
/* @0x2545c4 bne 0x2545e8 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x628> */
/* @0x2545c8 ldr r0, [r5] */
/* @0x2545cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2545d0 mov r0, r5 */
/* @0x2545d4 str r6, [r5] */
/* @0x2545d8 str r6, [r5, #0x8] */
/* @0x2545dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2545e0 mov r0, r5 */
/* @0x2545e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x2545e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2545ec mov r0, r5 */
/* @0x2545f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2545f4 b 0x254590 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_+0x5d0> */
/* @0x2545f8 .word 0xffe00000 */
/* @0x2545fc .word 0x41efffff */
/* @0x254600 andseq r1, r0, r8, ror #23 */
/* @0x254604 andseq r1, r0, r4, lsl #20 */

/* ── FUNC 0x254608 · JS_Function_prototype_bind(RValue&, CInstance*, CInstance*, int, RValue*) · size=616 · insn=154 */
/* @0x254608 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25460c sub sp, sp, #52 */
/* @0x254610 mov r9, r0 */
/* @0x254614 mov r0, r1 */
/* @0x254618 mov r7, r1 */
/* @0x25461c mov r11, r2 */
/* @0x254620 mov r10, r3 */
/* @0x254624 ldr r8, [sp, #0x58] */
/* @0x254628 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0x25462c cmp r0, #0 */
/* @0x254630 beq 0x2547c4 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x254634 add r0, sp, #16 */
/* @0x254638 ldr r4, [pc, #0x210] */
/* @0x25463c bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue> */
/* @0x254640 ldr r6, [sp, #0x10] */
/* @0x254644 mov r1, r7 */
/* @0x254648 mov r0, r6 */
/* @0x25464c bl 0x1982d4 <_ZN12YYObjectBase10AssignVarsEPS_> */
/* @0x254650 ldr r4, [pc, r4] */
/* @0x254654 mov r1, r4 */
/* @0x254658 mov r0, r4 */
/* @0x25465c bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_> */
/* @0x254660 ldr r1, [pc, #0x1ec] */
/* @0x254664 mov r3, #0 */
/* @0x254668 add r1, pc, r1 */
/* @0x25466c mov r2, r0 */
/* @0x254670 mov r0, r6 */
/* @0x254674 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x254678 ldr r1, [pc, #0x1d8] */
/* @0x25467c mov r0, r6 */
/* @0x254680 add r1, pc, r1 */
/* @0x254684 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x254688 ldr r3, [r6, #0x4] */
/* @0x25468c cmp r3, #0 */
/* @0x254690 beq 0x25483c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x254694 add r2, r3, r0, lsl #4 */
/* @0x254698 mov r1, r4 */
/* @0x25469c mov r0, r4 */
/* @0x2546a0 str r2, [sp, #0xc] */
/* @0x2546a4 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_> */
/* @0x2546a8 ldr r2, [sp, #0xc] */
/* @0x2546ac mov r3, #0 */
/* @0x2546b0 mov r1, #6 */
/* @0x2546b4 ldr r5, [pc, #0x1a0] */
/* @0x2546b8 str r3, [r2, #0x8] */
/* @0x2546bc add r5, pc, r5 */
/* @0x2546c0 str r1, [r2, #0xc] */
/* @0x2546c4 mov r1, r4 */
/* @0x2546c8 str r0, [r2] */
/* @0x2546cc mov r0, r4 */
/* @0x2546d0 str r3, [sp, #0xc] */
/* @0x2546d4 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_> */
/* @0x2546d8 ldr r1, [pc, #0x180] */
/* @0x2546dc ldr r3, [sp, #0xc] */
/* @0x2546e0 add r1, pc, r1 */
/* @0x2546e4 mov r2, r0 */
/* @0x2546e8 mov r0, r6 */
/* @0x2546ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2546f0 mov r1, r5 */
/* @0x2546f4 mov r0, r6 */
/* @0x2546f8 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x2546fc cmp r0, #0 */
/* @0x254700 blt 0x254810 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x254704 ldr r3, [r6, #0x4] */
/* @0x254708 cmp r3, #0 */
/* @0x25470c beq 0x254828 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x254710 add r5, r3, r0, lsl #4 */
/* @0x254714 cmp r5, #0 */
/* @0x254718 beq 0x254748 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x25471c mov r0, r5 */
/* @0x254720 rsb r4, r10, #1 */
/* @0x254724 bl 0xd11b0 <_Z12INT32_RValuePK6RValue> */
/* @0x254728 mov r3, #0 */
/* @0x25472c str r3, [r5, #0xc] */
/* @0x254730 add r0, r0, r4 */
/* @0x254734 bic r4, r0, r0, asr #31 */
/* @0x254738 vmov s15, r4 */
/* @0x25473c vcvt.f64.s32 d7, s15 */
/* @0x254740 vmov r2, r3, d7 */
/* @0x254744 stm r5, {r2, r3} */
/* @0x254748 ldr r3, [r8, #0xc] */
/* @0x25474c ldr r4, [pc, #0x110] */
/* @0x254750 bic r3, r3, #-16777216 */
/* @0x254754 cmp r3, #6 */
/* @0x254758 ldr r4, [pc, r4] */
/* @0x25475c ldr r3, [r4] */
/* @0x254760 bne 0x2547d8 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x254764 ldr r3, [r8] */
/* @0x254768 add r5, sp, #32 */
/* @0x25476c str r3, [r6, #0x7c] */
/* @0x254770 mov r1, r7 */
/* @0x254774 mov r2, r11 */
/* @0x254778 sub r3, r10, #1 */
/* @0x25477c mov r4, #6 */
/* @0x254780 mov r0, r5 */
/* @0x254784 str r4, [r6, #0x88] */
/* @0x254788 add r8, r8, #16 */
/* @0x25478c str r8, [sp] */
/* @0x254790 mov r12, #5 */
/* @0x254794 str r12, [sp, #0x2c] */
/* @0x254798 bl 0x253fc0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_> */
/* @0x25479c ldr r1, [pc, #0xc4] */
/* @0x2547a0 mov r0, r6 */
/* @0x2547a4 mov r2, r5 */
/* @0x2547a8 mov r3, #0 */
/* @0x2547ac add r1, pc, r1 */
/* @0x2547b0 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x2547b4 str r4, [r9, #0xc] */
/* @0x2547b8 str r6, [r9] */
/* @0x2547bc add sp, sp, #52 */
/* @0x2547c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2547c4 ldr r0, [pc, #0xa0] */
/* @0x2547c8 add r0, pc, r0 */
/* @0x2547cc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2547d0 add sp, sp, #52 */
/* @0x2547d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2547d8 mov r0, r8 */
/* @0x2547dc str r3, [sp, #0xc] */
/* @0x2547e0 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue> */
/* @0x2547e4 add r5, sp, #32 */
/* @0x2547e8 ldr r3, [sp, #0xc] */
/* @0x2547ec cmp r0, #0 */
/* @0x2547f0 beq 0x25476c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x2547f4 mov r1, r8 */
/* @0x2547f8 mov r0, r5 */
/* @0x2547fc bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_> */
/* @0x254800 cmp r0, #0 */
/* @0x254804 ldrne r3, [r4] */
/* @0x254808 ldreq r3, [sp, #0x20] */
/* @0x25480c b 0x25476c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x254810 mov r1, r5 */
/* @0x254814 mov r0, r6 */
/* @0x254818 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x25481c subs r5, r0, #0 */
/* @0x254820 bne 0x25471c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x254824 b 0x254748 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x254828 mov r1, r0 */
/* @0x25482c mov r0, r6 */
/* @0x254830 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x254834 mov r5, r0 */
/* @0x254838 b 0x254714 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x25483c mov r1, r0 */
/* @0x254840 mov r0, r6 */
/* @0x254844 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x254848 mov r2, r0 */
/* @0x25484c b 0x254698 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x254850 andseq sp, r9, r4, lsl #3 */
/* @0x254854 andseq r2, r0, r12, lsl r0 */
/* @0x254858 muleq pc, r0, r0 */
/* @0x25485c strheq r12, [sp], -r0 */
/* @0x254860 andeq sp, pc, r0, lsr r0 */
/* @0x254864 andseq r9, r9, r0, asr r5 */
/* @0x254868 andeq r0, lr, r0, lsr #1 */
/* @0x25486c andseq r1, r0, r4, lsl #29 */

/* ── FUNC 0x254870 · JS_Number_Prototype_toExponential(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x254870 push {r4, r5, r6, r7, r8, r11, lr} */
/* @0x254874 vpush {d8} */
/* @0x254878 add r11, sp, #32 */
/* @0x25487c ldr r6, [pc, #0x110] */
/* @0x254880 sub sp, sp, #20 */
/* @0x254884 cmp r3, #0 */
/* @0x254888 ldr r6, [pc, r6] */
/* @0x25488c mov r8, r0 */
/* @0x254890 mov r4, r1 */
/* @0x254894 ldr r0, [r11, #0x4] */
/* @0x254898 ldr r2, [r6] */
/* @0x25489c str r2, [r11, #-0x28] */
/* @0x2548a0 ble 0x2548f4 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2548a4 ldr r2, [r0, #0xc] */
/* @0x2548a8 bic r2, r2, #-16777216 */
/* @0x2548ac cmp r2, #5 */
/* @0x2548b0 beq 0x2548f4 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x2548b4 bl 0x24d730 <_Z14F_JS_ToIntegerR6RValue> */
/* @0x2548b8 vmov d8, r0, r1 */
/* @0x2548bc vcmpe.f64 d8, #0 */
/* @0x2548c0 vmrs APSR_nzcv, fpscr */
/* @0x2548c4 bmi 0x2548d8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x2548c8 vmov.f64 d7, #2.000000e+01 */
/* @0x2548cc vcmpe.f64 d8, d7 */
/* @0x2548d0 vmrs APSR_nzcv, fpscr */
/* @0x2548d4 ble 0x2548f8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x2548d8 vcmp.f64 d8, d8 */
/* @0x2548dc vmrs APSR_nzcv, fpscr */
/* @0x2548e0 bvs 0x2548f8 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x2548e4 ldr r0, [pc, #0xac] */
/* @0x2548e8 add r0, pc, r0 */
/* @0x2548ec bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x2548f0 b 0x254960 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x2548f4 vmov.f64 d8, #5.000000e+00 */
/* @0x2548f8 ldr r1, [pc, #0x9c] */
/* @0x2548fc mov r0, r4 */
/* @0x254900 add r1, pc, r1 */
/* @0x254904 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x254908 ldm r0, {r4, r5} */
/* @0x25490c vmov d6, r4, r5 */
/* @0x254910 vmov d7, r4, r5 */
/* @0x254914 vcmp.f64 d6, d7 */
/* @0x254918 vmrs APSR_nzcv, fpscr */
/* @0x25491c bvs 0x25497c <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x254920 sub sp, sp, #264 */
/* @0x254924 mov r1, #0 */
/* @0x254928 add r7, sp, #8 */
/* @0x25492c mov r2, #256 */
/* @0x254930 mov r0, r7 */
/* @0x254934 bl 0xb65b0 <memset@plt> */
/* @0x254938 vcvt.s32.f64 s15, d8 */
/* @0x25493c ldr r1, [pc, #0x5c] */
/* @0x254940 mov r0, r7 */
/* @0x254944 strd r4, r5, [sp] */
/* @0x254948 add r1, pc, r1 */
/* @0x25494c vmov r2, s15 */
/* @0x254950 bl 0xb6550 <sprintf@plt> */
/* @0x254954 mov r0, r8 */
/* @0x254958 mov r1, r7 */
/* @0x25495c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x254960 ldr r2, [r11, #-0x28] */
/* @0x254964 ldr r3, [r6] */
/* @0x254968 cmp r2, r3 */
/* @0x25496c bne 0x254990 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x254970 sub sp, r11, #32 */
/* @0x254974 vpop {d8} */
/* @0x254978 pop {r4, r5, r6, r7, r8, r11, pc} */
/* @0x25497c ldr r1, [pc, #0x20] */
/* @0x254980 mov r0, r8 */
/* @0x254984 add r1, pc, r1 */
/* @0x254988 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x25498c b 0x254960 <_Z33JS_Number_Prototype_toExponentialR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x254990 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x254994 andseq r9, r9, r8, asr #1 */
/* @0x254998 andseq r1, r0, r4, lsr #27 */
/* @0x25499c andseq r0, r0, r0, lsl r12 */
/* @0x2549a0 andseq r1, r0, r12, lsl #27 */
/* @0x2549a4 andeq sp, sp, r0, ror r11 */

/* ── FUNC 0x2549a8 · JS_Date_toISOString(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=87 */
/* @0x2549a8 push {r4, r5, r6, r7, lr} */
/* @0x2549ac vpush {d8, d9, d10, d11, d12, d13} */
/* @0x2549b0 mov r7, r0 */
/* @0x2549b4 ldr r6, [pc, #0x138] */
/* @0x2549b8 mov r0, r1 */
/* @0x2549bc sub sp, sp, #1056 */
/* @0x2549c0 ldr r1, [pc, #0x130] */
/* @0x2549c4 ldr r6, [pc, r6] */
/* @0x2549c8 sub sp, sp, #4 */
/* @0x2549cc add r1, pc, r1 */
/* @0x2549d0 ldr r3, [r6] */
/* @0x2549d4 str r3, [sp, #0x41c] */
/* @0x2549d8 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x2549dc cmp r0, #0 */
/* @0x2549e0 beq 0x254ae0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x2549e4 ldr r4, [r0, #0x4] */
/* @0x2549e8 ldr r5, [r0] */
/* @0x2549ec mov r1, r4 */
/* @0x2549f0 mov r0, r5 */
/* @0x2549f4 bl 0x244b90 <_Z12YearFromTimed> */
/* @0x2549f8 vmov d13, r0, r1 */
/* @0x2549fc mov r1, r4 */
/* @0x254a00 mov r0, r5 */
/* @0x254a04 bl 0x244c68 <_Z13MonthFromTimed> */
/* @0x254a08 vmov d12, r0, r1 */
/* @0x254a0c mov r1, r4 */
/* @0x254a10 mov r0, r5 */
/* @0x254a14 bl 0x244f60 <_Z12DateFromTimed> */
/* @0x254a18 vmov d11, r0, r1 */
/* @0x254a1c mov r1, r4 */
/* @0x254a20 mov r0, r5 */
/* @0x254a24 bl 0x245120 <_Z12HourFromTimed> */
/* @0x254a28 vmov d10, r0, r1 */
/* @0x254a2c mov r1, r4 */
/* @0x254a30 mov r0, r5 */
/* @0x254a34 bl 0x245158 <_Z11MinFromTimed> */
/* @0x254a38 vmov d9, r0, r1 */
/* @0x254a3c mov r1, r4 */
/* @0x254a40 mov r0, r5 */
/* @0x254a44 bl 0x245190 <_Z11SecFromTimed> */
/* @0x254a48 vmov d8, r0, r1 */
/* @0x254a4c mov r1, r4 */
/* @0x254a50 mov r0, r5 */
/* @0x254a54 add r4, sp, #28 */
/* @0x254a58 bl 0x2451c8 <_Z10msFromTimed> */
/* @0x254a5c vcvt.s32.f64 s14, d12 */
/* @0x254a60 ldr r2, [pc, #0x94] */
/* @0x254a64 add r2, pc, r2 */
/* @0x254a68 vmov r3, s14 */
/* @0x254a6c vcvt.s32.f64 s22, d11 */
/* @0x254a70 vcvt.s32.f64 s20, d10 */
/* @0x254a74 vstr s22, [sp, #4] */
/* @0x254a78 vcvt.s32.f64 s18, d9 */
/* @0x254a7c vstr s20, [sp, #8] */
/* @0x254a80 add r3, r3, #1 */
/* @0x254a84 str r3, [sp] */
/* @0x254a88 vcvt.s32.f64 s16, d8 */
/* @0x254a8c vstr s18, [sp, #12] */
/* @0x254a90 vmov d7, r0, r1 */
/* @0x254a94 mov r1, #1024 */
/* @0x254a98 mov r0, r4 */
/* @0x254a9c vcvt.s32.f64 s15, d7 */
/* @0x254aa0 vstr s16, [sp, #16] */
/* @0x254aa4 vcvt.s32.f64 s14, d13 */
/* @0x254aa8 vstr s15, [sp, #20] */
/* @0x254aac vmov r3, s14 */
/* @0x254ab0 bl 0xb65c8 <snprintf@plt> */
/* @0x254ab4 mov r0, r7 */
/* @0x254ab8 mov r1, r4 */
/* @0x254abc bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x254ac0 ldr r2, [sp, #0x41c] */
/* @0x254ac4 ldr r3, [r6] */
/* @0x254ac8 cmp r2, r3 */
/* @0x254acc bne 0x254af0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x254ad0 add sp, sp, #1056 */
/* @0x254ad4 add sp, sp, #4 */
/* @0x254ad8 vpop {d8, d9, d10, d11, d12, d13} */
/* @0x254adc pop {r4, r5, r6, r7, pc} */
/* @0x254ae0 ldr r0, [pc, #0x18] */
/* @0x254ae4 add r0, pc, r0 */
/* @0x254ae8 bl 0x253ea4 <_Z17JSThrowRangeErrorPKc> */
/* @0x254aec b 0x254ac0 <_Z19JS_Date_toISOStringR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x254af0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x254af4 andseq r8, r9, r12, lsl #31 */
/* @0x254af8 andseq r0, r0, r4, asr #22 */
/* @0x254afc andseq r1, r0, r8, ror r12 */
/* @0x254b00 andseq r1, r0, r4, ror #8 */

/* ── FUNC 0x254b04 · JSThrowReferenceError(char const*) · size=284 · insn=71 */
/* @0x254b04 push {r4, r5, r6, r7, lr} */
/* @0x254b08 sub sp, sp, #60 */
/* @0x254b0c add r6, sp, #8 */
/* @0x254b10 add r5, sp, #24 */
/* @0x254b14 mov r4, #0 */
/* @0x254b18 mov r1, r0 */
/* @0x254b1c add r7, sp, #40 */
/* @0x254b20 mov r0, r6 */
/* @0x254b24 str r4, [sp, #0x8] */
/* @0x254b28 str r4, [sp, #0xc] */
/* @0x254b2c str r4, [sp, #0x10] */
/* @0x254b30 str r4, [sp, #0x14] */
/* @0x254b34 str r4, [sp, #0x18] */
/* @0x254b38 str r4, [sp, #0x1c] */
/* @0x254b3c str r4, [sp, #0x20] */
/* @0x254b40 str r4, [sp, #0x24] */
/* @0x254b44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x254b48 mov r1, r4 */
/* @0x254b4c mov r2, r4 */
/* @0x254b50 mov r0, r5 */
/* @0x254b54 mov r3, #1 */
/* @0x254b58 str r6, [sp] */
/* @0x254b5c bl 0x244094 <_Z22F_JSReferenceErrorCallR6RValueP9CInstanceS2_iPS_> */
/* @0x254b60 mov r3, #1 */
/* @0x254b64 mov r1, r4 */
/* @0x254b68 str r5, [sp] */
/* @0x254b6c mov r2, r4 */
/* @0x254b70 mov r0, r7 */
/* @0x254b74 str r4, [sp, #0x28] */
/* @0x254b78 str r4, [sp, #0x2c] */
/* @0x254b7c str r4, [sp, #0x30] */
/* @0x254b80 str r4, [sp, #0x34] */
/* @0x254b84 bl 0x24e33c <_Z9F_JSThrowR6RValueP9CInstanceS2_iPS_> */
/* @0x254b88 ldr r3, [sp, #0x14] */
/* @0x254b8c sub r3, r3, #1 */
/* @0x254b90 bic r3, r3, #-16777216 */
/* @0x254b94 bic r3, r3, #3 */
/* @0x254b98 cmp r3, r4 */
/* @0x254b9c beq 0x254c14 <_Z21JSThrowReferenceErrorPKc+0x110> */
/* @0x254ba0 ldr r1, [sp, #0x24] */
/* @0x254ba4 mov r3, #0 */
/* @0x254ba8 str r3, [sp, #0x10] */
/* @0x254bac mov r2, #5 */
/* @0x254bb0 sub r1, r1, #1 */
/* @0x254bb4 str r3, [sp, #0x8] */
/* @0x254bb8 bic r3, r1, #-16777216 */
/* @0x254bbc str r2, [sp, #0x14] */
/* @0x254bc0 bic r3, r3, #3 */
/* @0x254bc4 cmp r3, #0 */
/* @0x254bc8 beq 0x254c08 <_Z21JSThrowReferenceErrorPKc+0x104> */
/* @0x254bcc ldr r1, [sp, #0x34] */
/* @0x254bd0 mov r3, #0 */
/* @0x254bd4 str r3, [sp, #0x20] */
/* @0x254bd8 mov r2, #5 */
/* @0x254bdc sub r1, r1, #1 */
/* @0x254be0 str r3, [sp, #0x18] */
/* @0x254be4 bic r3, r1, #-16777216 */
/* @0x254be8 str r2, [sp, #0x24] */
/* @0x254bec bic r3, r3, #3 */
/* @0x254bf0 cmp r3, #0 */
/* @0x254bf4 bne 0x254c00 <_Z21JSThrowReferenceErrorPKc+0xfc> */
/* @0x254bf8 mov r0, r7 */
/* @0x254bfc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x254c00 add sp, sp, #60 */
/* @0x254c04 pop {r4, r5, r6, r7, pc} */
/* @0x254c08 mov r0, r5 */
/* @0x254c0c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x254c10 b 0x254bcc <_Z21JSThrowReferenceErrorPKc+0xc8> */
/* @0x254c14 mov r0, r6 */
/* @0x254c18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x254c1c b 0x254ba0 <_Z21JSThrowReferenceErrorPKc+0x9c> */

/* ── FUNC 0x254c20 · JS_Global_unimplemented(RValue&, CInstance*, CInstance*, int, RValue*) · size=16 · insn=4 */
/* @0x254c20 ldr r0, [pc, #0x4] */
/* @0x254c24 add r0, pc, r0 */
/* @0x254c28 b 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x254c2c ldrsbeq r1, [r0], -r12 */

/* ── FUNC 0x254c30 · F_JSInstanceOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=284 · insn=71 */
/* @0x254c30 push {r3, r4, r5, lr} */
/* @0x254c34 mvn r3, #-16777216 */
/* @0x254c38 ldr r1, [sp, #0x10] */
/* @0x254c3c mov r4, r0 */
/* @0x254c40 ldr r2, [r1, #0x1c] */
/* @0x254c44 and r2, r2, r3 */
/* @0x254c48 cmp r2, r3 */
/* @0x254c4c beq 0x254cf4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x254c50 ldr r2, [r1, #0xc] */
/* @0x254c54 bic r2, r2, #-16777216 */
/* @0x254c58 cmp r2, r3 */
/* @0x254c5c beq 0x254d04 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x254c60 mov r3, #13 */
/* @0x254c64 str r3, [r0, #0xc] */
/* @0x254c68 ldr r3, [r1, #0xc] */
/* @0x254c6c mov r5, #0 */
/* @0x254c70 str r5, [r0] */
/* @0x254c74 bic r3, r3, #-16777216 */
/* @0x254c78 str r5, [r0, #0x4] */
/* @0x254c7c cmp r3, #6 */
/* @0x254c80 bne 0x254cd4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x254c84 ldr r0, [r1] */
/* @0x254c88 cmp r0, #0 */
/* @0x254c8c popeq {r3, r4, r5, pc} */
/* @0x254c90 ldr r3, [r0, #0x48] */
/* @0x254c94 cmp r3, #3 */
/* @0x254c98 bne 0x254ce4 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x254c9c ldr r3, [r0, #0x90] */
/* @0x254ca0 cmp r3, #0 */
/* @0x254ca4 beq 0x254d14 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x254ca8 add r1, r1, #16 */
/* @0x254cac blx r3 */
/* @0x254cb0 cmp r0, #2 */
/* @0x254cb4 beq 0x254d24 <_Z14F_JSInstanceOfR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x254cb8 cmp r0, #1 */
/* @0x254cbc str r5, [r4] */
/* @0x254cc0 moveq r3, #0 */
/* @0x254cc4 movne r3, r5 */
/* @0x254cc8 movteq r3, #0x3ff0 */
/* @0x254ccc str r3, [r4, #0x4] */
/* @0x254cd0 pop {r3, r4, r5, pc} */
/* @0x254cd4 ldr r0, [pc, #0x58] */
/* @0x254cd8 pop {r3, r4, r5, lr} */
/* @0x254cdc add r0, pc, r0 */
/* @0x254ce0 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x254ce4 ldr r0, [pc, #0x4c] */
/* @0x254ce8 pop {r3, r4, r5, lr} */
/* @0x254cec add r0, pc, r0 */
/* @0x254cf0 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x254cf4 ldr r0, [pc, #0x40] */
/* @0x254cf8 pop {r3, r4, r5, lr} */
/* @0x254cfc add r0, pc, r0 */
/* @0x254d00 b 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x254d04 ldr r0, [pc, #0x34] */
/* @0x254d08 pop {r3, r4, r5, lr} */
/* @0x254d0c add r0, pc, r0 */
/* @0x254d10 b 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x254d14 ldr r0, [pc, #0x28] */
/* @0x254d18 pop {r3, r4, r5, lr} */
/* @0x254d1c add r0, pc, r0 */
/* @0x254d20 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x254d24 ldr r0, [pc, #0x1c] */
/* @0x254d28 pop {r3, r4, r5, lr} */
/* @0x254d2c add r0, pc, r0 */
/* @0x254d30 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x254d34 andseq r1, r0, r4, lsl #21 */
/* @0x254d38 andseq r1, r0, r8, lsr #22 */
/* @0x254d3c andseq r1, r0, r12, lsl r10 */
/* @0x254d40 andseq r1, r0, r0, lsr r10 */
/* @0x254d44 ldrheq r1, [r0], -r4 */
/* @0x254d48 andseq r1, r0, r4, ror r10 */

/* ── FUNC 0x254d4c · F_JSNew(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x254d4c push {r4, r5, r6, r7, lr} */
/* @0x254d50 sub sp, sp, #20 */
/* @0x254d54 subs r5, r3, #0 */
/* @0x254d58 mov r6, r0 */
/* @0x254d5c ldr r4, [sp, #0x28] */
/* @0x254d60 ldr r1, [r4, #0xc] */
/* @0x254d64 bic r1, r1, #-16777216 */
/* @0x254d68 ble 0x254d74 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x254d6c cmp r1, #6 */
/* @0x254d70 beq 0x254da8 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x254d74 mvn r3, #-16777216 */
/* @0x254d78 ldr r0, [pc, #0x88] */
/* @0x254d7c cmp r1, r3 */
/* @0x254d80 add r0, pc, r0 */
/* @0x254d84 beq 0x254d94 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x254d88 add sp, sp, #20 */
/* @0x254d8c pop {r4, r5, r6, r7, lr} */
/* @0x254d90 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x254d94 ldr r0, [pc, #0x70] */
/* @0x254d98 add r0, pc, r0 */
/* @0x254d9c add sp, sp, #20 */
/* @0x254da0 pop {r4, r5, r6, r7, lr} */
/* @0x254da4 b 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0x254da8 ldr r0, [r4] */
/* @0x254dac ldr r3, [r0, #0x48] */
/* @0x254db0 cmp r3, #3 */
/* @0x254db4 bne 0x254df0 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x254db8 ldr r7, [r0, #0x94] */
/* @0x254dbc cmp r7, #0 */
/* @0x254dc0 beq 0x254dfc <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x254dc4 str r2, [sp, #0xc] */
/* @0x254dc8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x254dcc ldr r1, [r4], #16 */
/* @0x254dd0 mov r0, r6 */
/* @0x254dd4 ldr r2, [sp, #0xc] */
/* @0x254dd8 sub r3, r5, #1 */
/* @0x254ddc str r4, [sp] */
/* @0x254de0 blx r7 */
/* @0x254de4 add sp, sp, #20 */
/* @0x254de8 pop {r4, r5, r6, r7, lr} */
/* @0x254dec b 0xd3a34 <_Z15PopContextStackv> */
/* @0x254df0 ldr r0, [pc, #0x18] */
/* @0x254df4 add r0, pc, r0 */
/* @0x254df8 b 0x254d88 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x254dfc ldr r0, [pc, #0x10] */
/* @0x254e00 add r0, pc, r0 */
/* @0x254e04 b 0x254d88 <_Z7F_JSNewR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x254e08 andseq r1, r0, r12, lsl #22 */
/* @0x254e0c andseq r1, r0, r0, asr #21 */
/* @0x254e10 andseq r1, r0, r12, asr #21 */
/* @0x254e14 ldrsheq r1, [r0], -r4 */

/* ── FUNC 0x254e18 · JS_Global_parseInt(RValue&, CInstance*, CInstance*, int, RValue*) · size=536 · insn=134 */
/* @0x254e18 cmp r3, #0 */
/* @0x254e1c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x254e20 mov r7, r0 */
/* @0x254e24 sub sp, sp, #36 */
/* @0x254e28 bne 0x254e44 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x254e2c str r3, [r0, #0xc] */
/* @0x254e30 mvn r2, #0 */
/* @0x254e34 mvn r3, #-2147483648 */
/* @0x254e38 stm r0, {r2, r3} */
/* @0x254e3c add sp, sp, #36 */
/* @0x254e40 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x254e44 ldr r1, [sp, #0x40] */
/* @0x254e48 mov r0, sp */
/* @0x254e4c mov r2, #0 */
/* @0x254e50 mov r3, #0 */
/* @0x254e54 mov r12, #0 */
/* @0x254e58 strd r2, r3, [sp] */
/* @0x254e5c str r12, [sp, #0x8] */
/* @0x254e60 mvn r3, #-16777216 */
/* @0x254e64 add r5, r1, #16 */
/* @0x254e68 str r3, [sp, #0xc] */
/* @0x254e6c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x254e70 cmp r0, #1 */
/* @0x254e74 beq 0x255000 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x254e78 ldr r3, [sp] */
/* @0x254e7c ldr r6, [r3] */
/* @0x254e80 cmp r6, #0 */
/* @0x254e84 beq 0x254eb0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x254e88 mov r4, r6 */
/* @0x254e8c mov r6, r4 */
/* @0x254e90 add r4, r4, #1 */
/* @0x254e94 ldrb r0, [r6] */
/* @0x254e98 bl 0x2425ac <_Z15JS_isWhitespacei> */
/* @0x254e9c cmp r0, #0 */
/* @0x254ea0 beq 0x254eb0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x254ea4 cmp r4, #0 */
/* @0x254ea8 mov r6, r4 */
/* @0x254eac bne 0x254e8c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x254eb0 ldrb r3, [r6] */
/* @0x254eb4 cmp r3, #0 */
/* @0x254eb8 beq 0x254edc <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x254ebc cmp r3, #45 */
/* @0x254ec0 addeq r6, r6, #1 */
/* @0x254ec4 mvneq r8, #0 */
/* @0x254ec8 beq 0x254ee0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x254ecc cmp r3, #43 */
/* @0x254ed0 addeq r6, r6, #1 */
/* @0x254ed4 moveq r8, #1 */
/* @0x254ed8 beq 0x254ee0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x254edc mov r8, #1 */
/* @0x254ee0 mov r1, r5 */
/* @0x254ee4 add r0, sp, #16 */
/* @0x254ee8 mov r4, #0 */
/* @0x254eec mov r9, #0 */
/* @0x254ef0 mvn r3, #-16777216 */
/* @0x254ef4 mov r5, #0 */
/* @0x254ef8 str r9, [sp, #0x18] */
/* @0x254efc strd r4, r5, [sp, #16] */
/* @0x254f00 str r3, [sp, #0x1c] */
/* @0x254f04 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0x254f08 vldr d7, [sp, #16] */
/* @0x254f0c vcvt.s32.f64 s13, d7 */
/* @0x254f10 vmov r4, s13 */
/* @0x254f14 cmp r4, r9 */
/* @0x254f18 bne 0x254f50 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x254f1c mov r4, #10 */
/* @0x254f20 ldrb r0, [r6] */
/* @0x254f24 cmp r0, #48 */
/* @0x254f28 beq 0x255010 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x254f2c mov r1, r4 */
/* @0x254f30 bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x254f34 cmp r0, #0 */
/* @0x254f38 bne 0x254f70 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x254f3c mvn r2, #0 */
/* @0x254f40 mvn r3, #-2147483648 */
/* @0x254f44 str r0, [r7, #0xc] */
/* @0x254f48 stm r7, {r2, r3} */
/* @0x254f4c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x254f50 sub r3, r4, #2 */
/* @0x254f54 cmp r3, #34 */
/* @0x254f58 bls 0x254ff0 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x254f5c mvn r2, #0 */
/* @0x254f60 mvn r3, #-2147483648 */
/* @0x254f64 str r9, [r7, #0xc] */
/* @0x254f68 stm r7, {r2, r3} */
/* @0x254f6c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x254f70 ldrb r3, [r6] */
/* @0x254f74 cmp r3, #0 */
/* @0x254f78 bne 0x254fa4 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x254f7c mov r2, #0 */
/* @0x254f80 mov r3, #0 */
/* @0x254f84 mov r1, r2 */
/* @0x254f88 mov r2, r3 */
/* @0x254f8c str r1, [r7] */
/* @0x254f90 mov r3, #0 */
/* @0x254f94 str r2, [r7, #0x4] */
/* @0x254f98 str r3, [r7, #0xc] */
/* @0x254f9c add sp, sp, #36 */
/* @0x254fa0 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x254fa4 sub r6, r6, #1 */
/* @0x254fa8 mov r5, #0 */
/* @0x254fac mov r1, r4 */
/* @0x254fb0 mov r0, r3 */
/* @0x254fb4 bl 0x23fe9c <_Z16isValidRadixCharci> */
/* @0x254fb8 mov r1, r4 */
/* @0x254fbc cmp r0, #0 */
/* @0x254fc0 beq 0x254fdc <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x254fc4 ldrb r0, [r6, #0x1]! */
/* @0x254fc8 bl 0x23fe14 <_Z12getRadixCharci> */
/* @0x254fcc ldrb r3, [r6, #0x1] */
/* @0x254fd0 cmp r3, #0 */
/* @0x254fd4 mla r5, r4, r5, r0 */
/* @0x254fd8 bne 0x254fac <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x254fdc mul r2, r5, r8 */
/* @0x254fe0 vmov s15, r2 */
/* @0x254fe4 vcvt.f64.s32 d7, s15 */
/* @0x254fe8 vmov r2, r3, d7 */
/* @0x254fec b 0x254f84 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x254ff0 cmp r4, #16 */
/* @0x254ff4 beq 0x254f20 <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x254ff8 ldrb r0, [r6] */
/* @0x254ffc b 0x254f2c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x255000 ldr r0, [pc, #0x24] */
/* @0x255004 add r0, pc, r0 */
/* @0x255008 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25500c b 0x254e3c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x255010 ldrb r3, [r6, #0x1] */
/* @0x255014 and r3, r3, #223 */
/* @0x255018 cmp r3, #88 */
/* @0x25501c ldrbeq r0, [r6, #0x2] */
/* @0x255020 moveq r4, #16 */
/* @0x255024 addeq r6, r6, #2 */
/* @0x255028 b 0x254f2c <_Z18JS_Global_parseIntR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x25502c andseq r1, r0, r0, lsr r9 */

/* ── FUNC 0x255030 · JS_Global_parseFloat(RValue&, CInstance*, CInstance*, int, RValue*) · size=316 · insn=79 */
/* @0x255030 cmp r3, #0 */
/* @0x255034 push {r4, r5, r6, r7, lr} */
/* @0x255038 mov r7, r0 */
/* @0x25503c sub sp, sp, #28 */
/* @0x255040 bne 0x25505c <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x255044 str r3, [r0, #0xc] */
/* @0x255048 mvn r2, #0 */
/* @0x25504c mvn r3, #-2147483648 */
/* @0x255050 stm r0, {r2, r3} */
/* @0x255054 add sp, sp, #28 */
/* @0x255058 pop {r4, r5, r6, r7, pc} */
/* @0x25505c add r0, sp, #8 */
/* @0x255060 ldr r1, [sp, #0x30] */
/* @0x255064 mov r2, #0 */
/* @0x255068 mov r3, #0 */
/* @0x25506c mov r12, #0 */
/* @0x255070 strd r2, r3, [sp, #8] */
/* @0x255074 str r12, [sp, #0x10] */
/* @0x255078 mvn r3, #-16777216 */
/* @0x25507c str r3, [sp, #0x14] */
/* @0x255080 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x255084 cmp r0, #1 */
/* @0x255088 beq 0x255148 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x25508c ldr r3, [sp, #0x8] */
/* @0x255090 ldr r6, [r3] */
/* @0x255094 cmp r6, #0 */
/* @0x255098 beq 0x2550c4 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x25509c mov r4, r6 */
/* @0x2550a0 mov r6, r4 */
/* @0x2550a4 add r4, r4, #1 */
/* @0x2550a8 ldrb r0, [r6] */
/* @0x2550ac bl 0x2425ac <_Z15JS_isWhitespacei> */
/* @0x2550b0 cmp r0, #0 */
/* @0x2550b4 beq 0x2550c4 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x2550b8 cmp r4, #0 */
/* @0x2550bc mov r6, r4 */
/* @0x2550c0 bne 0x2550a0 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x2550c4 mov r0, r6 */
/* @0x2550c8 add r1, sp, #4 */
/* @0x2550cc bl 0xb6658 <strtod@plt> */
/* @0x2550d0 mov r4, r0 */
/* @0x2550d4 mov r5, r1 */
/* @0x2550d8 bl 0xb6bf8 <__errno@plt> */
/* @0x2550dc ldr r3, [r0] */
/* @0x2550e0 cmp r3, #34 */
/* @0x2550e4 beq 0x25510c <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0xdc> */
/* @0x2550e8 ldr r3, [sp, #0x4] */
/* @0x2550ec cmp r6, r3 */
/* @0x2550f0 beq 0x255130 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x2550f4 mov r3, #0 */
/* @0x2550f8 str r4, [r7] */
/* @0x2550fc str r5, [r7, #0x4] */
/* @0x255100 str r3, [r7, #0xc] */
/* @0x255104 add sp, sp, #28 */
/* @0x255108 pop {r4, r5, r6, r7, pc} */
/* @0x25510c vmov d6, r4, r5 */
/* @0x255110 vldr d7, [pc, #64] */
/* @0x255114 vcmpe.f64 d6, d7 */
/* @0x255118 vmrs APSR_nzcv, fpscr */
/* @0x25511c bgt 0x255130 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x255120 vldr d7, [pc, #56] */
/* @0x255124 vcmpe.f64 d6, d7 */
/* @0x255128 vmrs APSR_nzcv, fpscr */
/* @0x25512c bpl 0x2550e8 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x255130 mov r3, #0 */
/* @0x255134 mvn r2, #0 */
/* @0x255138 str r3, [r7, #0xc] */
/* @0x25513c mvn r3, #-2147483648 */
/* @0x255140 stm r7, {r2, r3} */
/* @0x255144 b 0x255054 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x255148 ldr r0, [pc, #0x18] */
/* @0x25514c add r0, pc, r0 */
/* @0x255150 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x255154 b 0x255054 <_Z20JS_Global_parseFloatR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x255158 .word 0xffffffff */
/* @0x25515c svcvc #0xefffff */
/* @0x255160 .word 0xffffffff */
/* @0x255164 .word 0xffefffff */
/* @0x255168 andseq r1, r0, r8, lsl r8 */

/* ── FUNC 0x25516c · anon_25516c · size=0 · insn=1 */
/* @0x25516c nop */

/* ── FUNC 0x255170 · F_JS_Object_defineProperty(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x255170 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x255174 cmp r3, #0 */
/* @0x255178 sub sp, sp, #36 */
/* @0x25517c mov r7, r0 */
/* @0x255180 ldr r6, [sp, #0x48] */
/* @0x255184 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x255188 ldr r3, [r6, #0xc] */
/* @0x25518c bic r3, r3, #-16777216 */
/* @0x255190 cmp r3, #6 */
/* @0x255194 beq 0x2551ac <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x255198 ldr r0, [pc, #0xa0] */
/* @0x25519c add r0, pc, r0 */
/* @0x2551a0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2551a4 add sp, sp, #36 */
/* @0x2551a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2551ac add r1, r6, #16 */
/* @0x2551b0 mov r0, sp */
/* @0x2551b4 mov r4, #0 */
/* @0x2551b8 mov r5, #0 */
/* @0x2551bc mov r9, #0 */
/* @0x2551c0 strd r4, r5, [sp] */
/* @0x2551c4 str r9, [sp, #0x8] */
/* @0x2551c8 mvn r8, #-16777216 */
/* @0x2551cc str r8, [sp, #0xc] */
/* @0x2551d0 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2551d4 cmp r0, #1 */
/* @0x2551d8 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2551dc add r11, sp, #16 */
/* @0x2551e0 add r1, r6, #32 */
/* @0x2551e4 strd r4, r5, [sp, #16] */
/* @0x2551e8 mov r0, r11 */
/* @0x2551ec str r9, [sp, #0x18] */
/* @0x2551f0 str r8, [sp, #0x1c] */
/* @0x2551f4 bl 0x24195c <_Z25F_JS_ToPropertyDescriptorP6RValueS0_> */
/* @0x2551f8 cmp r0, #1 */
/* @0x2551fc beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x255200 mov r1, sp */
/* @0x255204 mov r2, r11 */
/* @0x255208 ldr r0, [r6] */
/* @0x25520c mov r3, #1 */
/* @0x255210 bl 0x248610 <_Z22JS_DefineOwnPropertyRVP12YYObjectBaseP6RValueS2_b> */
/* @0x255214 cmp r0, #2 */
/* @0x255218 beq 0x255198 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x25521c ldr r0, [r6] */
/* @0x255220 ldr r1, [r6, #0x4] */
/* @0x255224 ldr r2, [r6, #0x8] */
/* @0x255228 ldr r3, [r6, #0xc] */
/* @0x25522c str r0, [r7] */
/* @0x255230 str r1, [r7, #0x4] */
/* @0x255234 str r2, [r7, #0x8] */
/* @0x255238 str r3, [r7, #0xc] */
/* @0x25523c b 0x2551a4 <_Z26F_JS_Object_definePropertyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x255240 andseq r0, r0, r12, lsr #27 */
