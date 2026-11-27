/* libyoyo.so 覆盖卡组 0043
 * 函数 0x1169a4..0x117d98，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1169a4 · F_VariableInstanceGet(RValue&, CInstance*, CInstance*, int, RValue*) · size=268 · insn=67 */
/* @0x1169a4 push {r4, r5, r6, lr} */
/* @0x1169a8 mov r1, #0 */
/* @0x1169ac ldr r6, [sp, #0x10] */
/* @0x1169b0 mov r5, r0 */
/* @0x1169b4 mov r0, r6 */
/* @0x1169b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1169bc mov r1, #1 */
/* @0x1169c0 mov r4, r0 */
/* @0x1169c4 mov r0, r6 */
/* @0x1169c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1169cc cmp r4, #0 */
/* @0x1169d0 mov r6, r0 */
/* @0x1169d4 blt 0x116a20 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1169d8 ldr r3, [pc, #0xcc] */
/* @0x1169dc ldr r3, [pc, r3] */
/* @0x1169e0 ldr r2, [r3, #0x4] */
/* @0x1169e4 ldr r3, [r3] */
/* @0x1169e8 and r2, r4, r2 */
/* @0x1169ec ldr r2, [r3, r2, lsl #3] */
/* @0x1169f0 cmp r2, #0 */
/* @0x1169f4 beq 0x116a20 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1169f8 ldr r3, [r2, #0x8] */
/* @0x1169fc cmp r4, r3 */
/* @0x116a00 bne 0x116a14 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x116a04 b 0x116a38 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x116a08 ldr r12, [r2, #0x8] */
/* @0x116a0c cmp r4, r12 */
/* @0x116a10 beq 0x116a38 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x116a14 ldr r2, [r2, #0x4] */
/* @0x116a18 cmp r2, #0 */
/* @0x116a1c bne 0x116a08 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x116a20 mov r3, #0 */
/* @0x116a24 str r3, [r5] */
/* @0x116a28 str r3, [r5, #0x8] */
/* @0x116a2c mov r3, #5 */
/* @0x116a30 str r3, [r5, #0xc] */
/* @0x116a34 pop {r4, r5, r6, pc} */
/* @0x116a38 ldr r4, [r2, #0xc] */
/* @0x116a3c mov r3, #0 */
/* @0x116a40 mvn r2, #-16777216 */
/* @0x116a44 str r3, [r5] */
/* @0x116a48 cmp r4, r3 */
/* @0x116a4c str r2, [r5, #0xc] */
/* @0x116a50 str r3, [r5, #0x8] */
/* @0x116a54 beq 0x116a2c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x116a58 mov r0, r6 */
/* @0x116a5c bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x116a60 subs r1, r0, #0 */
/* @0x116a64 blt 0x116a8c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x116a68 mov r0, r4 */
/* @0x116a6c mov r2, #-2147483648 */
/* @0x116a70 mov r3, r5 */
/* @0x116a74 bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x116a78 ldr r3, [r5, #0xc] */
/* @0x116a7c mvn r2, #-16777216 */
/* @0x116a80 cmp r3, r2 */
/* @0x116a84 popne {r4, r5, r6, pc} */
/* @0x116a88 b 0x116a2c <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x116a8c mov r1, r6 */
/* @0x116a90 mov r0, r4 */
/* @0x116a94 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x116a98 cmp r0, #0 */
/* @0x116a9c addge r1, r0, #99328 */
/* @0x116aa0 addge r1, r1, #672 */
/* @0x116aa4 bge 0x116a68 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x116aa8 b 0x116a78 <_Z21F_VariableInstanceGetR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x116aac eoreq r7, sp, r8, ror #4 */

/* ── FUNC 0x116ab0 · F_VariableInstanceSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0x116ab0 push {r4, r5, r6, lr} */
/* @0x116ab4 mov r1, #0 */
/* @0x116ab8 ldr r5, [sp, #0x10] */
/* @0x116abc mov r0, r5 */
/* @0x116ac0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x116ac4 mov r1, #1 */
/* @0x116ac8 mov r4, r0 */
/* @0x116acc mov r0, r5 */
/* @0x116ad0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x116ad4 cmp r4, #0 */
/* @0x116ad8 mov r6, r0 */
/* @0x116adc poplt {r4, r5, r6, pc} */
/* @0x116ae0 ldr r2, [pc, #0x8c] */
/* @0x116ae4 ldr r2, [pc, r2] */
/* @0x116ae8 ldm r2, {r3, r12} */
/* @0x116aec and r2, r4, r12 */
/* @0x116af0 ldr r2, [r3, r2, lsl #3] */
/* @0x116af4 cmp r2, #0 */
/* @0x116af8 popeq {r4, r5, r6, pc} */
/* @0x116afc ldr r3, [r2, #0x8] */
/* @0x116b00 cmp r4, r3 */
/* @0x116b04 bne 0x116b18 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x116b08 b 0x116b28 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x116b0c ldr r12, [r2, #0x8] */
/* @0x116b10 cmp r4, r12 */
/* @0x116b14 beq 0x116b28 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x116b18 ldr r2, [r2, #0x4] */
/* @0x116b1c cmp r2, #0 */
/* @0x116b20 bne 0x116b0c <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x116b24 pop {r4, r5, r6, pc} */
/* @0x116b28 ldr r4, [r2, #0xc] */
/* @0x116b2c cmp r4, #0 */
/* @0x116b30 popeq {r4, r5, r6, pc} */
/* @0x116b34 mov r0, r6 */
/* @0x116b38 bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x116b3c subs r1, r0, #0 */
/* @0x116b40 blt 0x116b58 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x116b44 mov r0, r4 */
/* @0x116b48 add r3, r5, #32 */
/* @0x116b4c mov r2, #-2147483648 */
/* @0x116b50 pop {r4, r5, r6, lr} */
/* @0x116b54 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x116b58 mov r1, r6 */
/* @0x116b5c mov r0, r4 */
/* @0x116b60 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x116b64 subs r1, r0, #0 */
/* @0x116b68 addge r1, r1, #99328 */
/* @0x116b6c addge r1, r1, #672 */
/* @0x116b70 b 0x116b44 <_Z21F_VariableInstanceSetR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x116b74 eoreq r7, sp, r0, ror #2 */

/* ── FUNC 0x116b78 · F_DateGetWeekday(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x116b78 push {r4, lr} */
/* @0x116b7c sub sp, sp, #8 */
/* @0x116b80 mov r1, #0 */
/* @0x116b84 mov r4, r0 */
/* @0x116b88 mov r3, r1 */
/* @0x116b8c str r1, [r0, #0xc] */
/* @0x116b90 movt r3, #0xbff0 */
/* @0x116b94 stm r0, {r1, r3} */
/* @0x116b98 ldr r0, [sp, #0x10] */
/* @0x116b9c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116ba0 vldr d7, [pc, #120] */
/* @0x116ba4 vldr d5, [pc, #124] */
/* @0x116ba8 vmov d6, r0, r1 */
/* @0x116bac vsub.f64 d7, d6, d7 */
/* @0x116bb0 vabs.f64 d4, d7 */
/* @0x116bb4 vcmpe.f64 d4, d5 */
/* @0x116bb8 vmrs APSR_nzcv, fpscr */
/* @0x116bbc vldrls d7, [pc, #108] */
/* @0x116bc0 vldrhi d6, [pc, #104] */
/* @0x116bc4 vmul.f64 d5, d7, d6 */
/* @0x116bc8 vmov r0, r1, d5 */
/* @0x116bcc bl 0x3194a0 <__fixdfdi> */
/* @0x116bd0 mov r3, r1 */
/* @0x116bd4 ldr r1, [pc, #0x5c] */
/* @0x116bd8 mov r2, r0 */
/* @0x116bdc strd r2, r3, [sp] */
/* @0x116be0 add r1, pc, r1 */
/* @0x116be4 mov r0, sp */
/* @0x116be8 ldrb r3, [r1] */
/* @0x116bec cmp r3, #0 */
/* @0x116bf0 bne 0x116c18 <_Z16F_DateGetWeekdayR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116bf4 bl 0xb6820 <gmtime64@plt> */
/* @0x116bf8 cmp r0, #0 */
/* @0x116bfc ldrne r2, [r0, #0x18] */
/* @0x116c00 vmovne s15, r2 */
/* @0x116c04 vcvtne.f64.s32 d7, s15 */
/* @0x116c08 vmovne r2, r3, d7 */
/* @0x116c0c stmne r4, {r2, r3} */
/* @0x116c10 add sp, sp, #8 */
/* @0x116c14 pop {r4, pc} */
/* @0x116c18 bl 0xb682c <localtime64@plt> */
/* @0x116c1c b 0x116bf8 <_Z16F_DateGetWeekdayR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x116c20 andeq r0, r0, r0 */
/* @0x116c24 sbcsmi pc, r8, r0, asr #16 */
/* @0x116c28 bl 0x8278e4 <b2_toiTime+0xce440> */
/* @0x116c2c svclo #0x1a36e2 */
/* @0x116c30 andeq r0, r0, r0 */
/* @0x116c34 rscsmi r1, r5, r0, lsl #16 */
/* @0x116c38 eoreq r11, sp, r8, asr r5 */

/* ── FUNC 0x116c3c · anon_116c3c · size=0 · insn=1 */
/* @0x116c3c nop */

/* ── FUNC 0x116c40 · F_DateGetYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x116c40 push {r4, lr} */
/* @0x116c44 sub sp, sp, #8 */
/* @0x116c48 mov r1, #0 */
/* @0x116c4c mov r4, r0 */
/* @0x116c50 mov r3, r1 */
/* @0x116c54 str r1, [r0, #0xc] */
/* @0x116c58 movt r3, #0xbff0 */
/* @0x116c5c stm r0, {r1, r3} */
/* @0x116c60 ldr r0, [sp, #0x10] */
/* @0x116c64 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116c68 vldr d7, [pc, #128] */
/* @0x116c6c vldr d5, [pc, #132] */
/* @0x116c70 vmov d6, r0, r1 */
/* @0x116c74 vsub.f64 d7, d6, d7 */
/* @0x116c78 vabs.f64 d4, d7 */
/* @0x116c7c vcmpe.f64 d4, d5 */
/* @0x116c80 vmrs APSR_nzcv, fpscr */
/* @0x116c84 vldrls d7, [pc, #116] */
/* @0x116c88 vldrhi d6, [pc, #112] */
/* @0x116c8c vmul.f64 d5, d7, d6 */
/* @0x116c90 vmov r0, r1, d5 */
/* @0x116c94 bl 0x3194a0 <__fixdfdi> */
/* @0x116c98 mov r3, r1 */
/* @0x116c9c ldr r1, [pc, #0x6c] */
/* @0x116ca0 mov r2, r0 */
/* @0x116ca4 strd r2, r3, [sp] */
/* @0x116ca8 add r1, pc, r1 */
/* @0x116cac mov r0, sp */
/* @0x116cb0 ldrb r3, [r1] */
/* @0x116cb4 cmp r3, #0 */
/* @0x116cb8 bne 0x116ce8 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x116cbc bl 0xb6820 <gmtime64@plt> */
/* @0x116cc0 cmp r0, #0 */
/* @0x116cc4 beq 0x116ce0 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116cc8 vldr s12, [r0, #20] */
/* @0x116ccc vcvt.f64.s32 d6, s12 */
/* @0x116cd0 vldr d7, [pc, #48] */
/* @0x116cd4 vadd.f64 d5, d6, d7 */
/* @0x116cd8 vmov r2, r3, d5 */
/* @0x116cdc stm r4, {r2, r3} */
/* @0x116ce0 add sp, sp, #8 */
/* @0x116ce4 pop {r4, pc} */
/* @0x116ce8 bl 0xb682c <localtime64@plt> */
/* @0x116cec b 0x116cc0 <_Z13F_DateGetYearR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x116cf0 andeq r0, r0, r0 */
/* @0x116cf4 sbcsmi pc, r8, r0, asr #16 */
/* @0x116cf8 bl 0x8279b4 <b2_toiTime+0xce510> */
/* @0x116cfc svclo #0x1a36e2 */
/* @0x116d00 andeq r0, r0, r0 */
/* @0x116d04 rscsmi r1, r5, r0, lsl #16 */
/* @0x116d08 andeq r0, r0, r0 */
/* @0x116d0c addsmi r11, sp, r0 */
/* @0x116d10 mlaeq sp, r0, r4, r11 */

/* ── FUNC 0x116d14 · anon_116d14 · size=0 · insn=1 */
/* @0x116d14 nop */

/* ── FUNC 0x116d18 · F_DateGetMonth(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x116d18 push {r4, lr} */
/* @0x116d1c sub sp, sp, #8 */
/* @0x116d20 mov r1, #0 */
/* @0x116d24 mov r4, r0 */
/* @0x116d28 mov r3, r1 */
/* @0x116d2c str r1, [r0, #0xc] */
/* @0x116d30 movt r3, #0xbff0 */
/* @0x116d34 stm r0, {r1, r3} */
/* @0x116d38 ldr r0, [sp, #0x10] */
/* @0x116d3c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116d40 vldr d7, [pc, #128] */
/* @0x116d44 vldr d5, [pc, #132] */
/* @0x116d48 vmov d6, r0, r1 */
/* @0x116d4c vsub.f64 d7, d6, d7 */
/* @0x116d50 vabs.f64 d4, d7 */
/* @0x116d54 vcmpe.f64 d4, d5 */
/* @0x116d58 vmrs APSR_nzcv, fpscr */
/* @0x116d5c vldrls d7, [pc, #116] */
/* @0x116d60 vldrhi d6, [pc, #112] */
/* @0x116d64 vmul.f64 d5, d7, d6 */
/* @0x116d68 vmov r0, r1, d5 */
/* @0x116d6c bl 0x3194a0 <__fixdfdi> */
/* @0x116d70 mov r3, r1 */
/* @0x116d74 ldr r1, [pc, #0x64] */
/* @0x116d78 mov r2, r0 */
/* @0x116d7c strd r2, r3, [sp] */
/* @0x116d80 add r1, pc, r1 */
/* @0x116d84 mov r0, sp */
/* @0x116d88 ldrb r3, [r1] */
/* @0x116d8c cmp r3, #0 */
/* @0x116d90 bne 0x116dc0 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x116d94 bl 0xb6820 <gmtime64@plt> */
/* @0x116d98 cmp r0, #0 */
/* @0x116d9c beq 0x116db8 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116da0 vmov.f64 d7, #1.000000e+00 */
/* @0x116da4 vldr s12, [r0, #16] */
/* @0x116da8 vcvt.f64.s32 d6, s12 */
/* @0x116dac vadd.f64 d5, d6, d7 */
/* @0x116db0 vmov r2, r3, d5 */
/* @0x116db4 stm r4, {r2, r3} */
/* @0x116db8 add sp, sp, #8 */
/* @0x116dbc pop {r4, pc} */
/* @0x116dc0 bl 0xb682c <localtime64@plt> */
/* @0x116dc4 b 0x116d98 <_Z14F_DateGetMonthR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x116dc8 andeq r0, r0, r0 */
/* @0x116dcc sbcsmi pc, r8, r0, asr #16 */
/* @0x116dd0 bl 0x827a8c <b2_toiTime+0xce5e8> */
/* @0x116dd4 svclo #0x1a36e2 */
/* @0x116dd8 andeq r0, r0, r0 */
/* @0x116ddc rscsmi r1, r5, r0, lsl #16 */
/* @0x116de0 .word 0x002db3b8 */

/* ── FUNC 0x116de4 · anon_116de4 · size=0 · insn=1 */
/* @0x116de4 nop */

/* ── FUNC 0x116de8 · F_DateGetDay(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x116de8 push {r4, lr} */
/* @0x116dec sub sp, sp, #8 */
/* @0x116df0 mov r1, #0 */
/* @0x116df4 mov r4, r0 */
/* @0x116df8 mov r3, r1 */
/* @0x116dfc str r1, [r0, #0xc] */
/* @0x116e00 movt r3, #0xbff0 */
/* @0x116e04 stm r0, {r1, r3} */
/* @0x116e08 ldr r0, [sp, #0x10] */
/* @0x116e0c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116e10 vldr d7, [pc, #120] */
/* @0x116e14 vldr d5, [pc, #124] */
/* @0x116e18 vmov d6, r0, r1 */
/* @0x116e1c vsub.f64 d7, d6, d7 */
/* @0x116e20 vabs.f64 d4, d7 */
/* @0x116e24 vcmpe.f64 d4, d5 */
/* @0x116e28 vmrs APSR_nzcv, fpscr */
/* @0x116e2c vldrls d7, [pc, #108] */
/* @0x116e30 vldrhi d6, [pc, #104] */
/* @0x116e34 vmul.f64 d5, d7, d6 */
/* @0x116e38 vmov r0, r1, d5 */
/* @0x116e3c bl 0x3194a0 <__fixdfdi> */
/* @0x116e40 mov r3, r1 */
/* @0x116e44 ldr r1, [pc, #0x5c] */
/* @0x116e48 mov r2, r0 */
/* @0x116e4c strd r2, r3, [sp] */
/* @0x116e50 add r1, pc, r1 */
/* @0x116e54 mov r0, sp */
/* @0x116e58 ldrb r3, [r1] */
/* @0x116e5c cmp r3, #0 */
/* @0x116e60 bne 0x116e88 <_Z12F_DateGetDayR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116e64 bl 0xb6820 <gmtime64@plt> */
/* @0x116e68 cmp r0, #0 */
/* @0x116e6c ldrne r2, [r0, #0xc] */
/* @0x116e70 vmovne s15, r2 */
/* @0x116e74 vcvtne.f64.s32 d7, s15 */
/* @0x116e78 vmovne r2, r3, d7 */
/* @0x116e7c stmne r4, {r2, r3} */
/* @0x116e80 add sp, sp, #8 */
/* @0x116e84 pop {r4, pc} */
/* @0x116e88 bl 0xb682c <localtime64@plt> */
/* @0x116e8c b 0x116e68 <_Z12F_DateGetDayR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x116e90 andeq r0, r0, r0 */
/* @0x116e94 sbcsmi pc, r8, r0, asr #16 */
/* @0x116e98 bl 0x827b54 <b2_toiTime+0xce6b0> */
/* @0x116e9c svclo #0x1a36e2 */
/* @0x116ea0 andeq r0, r0, r0 */
/* @0x116ea4 rscsmi r1, r5, r0, lsl #16 */
/* @0x116ea8 eoreq r11, sp, r8, ror #5 */

/* ── FUNC 0x116eac · anon_116eac · size=0 · insn=1 */
/* @0x116eac nop */

/* ── FUNC 0x116eb0 · F_DateGetHour(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x116eb0 push {r4, lr} */
/* @0x116eb4 sub sp, sp, #8 */
/* @0x116eb8 mov r1, #0 */
/* @0x116ebc mov r4, r0 */
/* @0x116ec0 mov r3, r1 */
/* @0x116ec4 str r1, [r0, #0xc] */
/* @0x116ec8 movt r3, #0xbff0 */
/* @0x116ecc stm r0, {r1, r3} */
/* @0x116ed0 ldr r0, [sp, #0x10] */
/* @0x116ed4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116ed8 vldr d7, [pc, #120] */
/* @0x116edc vldr d5, [pc, #124] */
/* @0x116ee0 vmov d6, r0, r1 */
/* @0x116ee4 vsub.f64 d7, d6, d7 */
/* @0x116ee8 vabs.f64 d4, d7 */
/* @0x116eec vcmpe.f64 d4, d5 */
/* @0x116ef0 vmrs APSR_nzcv, fpscr */
/* @0x116ef4 vldrls d7, [pc, #108] */
/* @0x116ef8 vldrhi d6, [pc, #104] */
/* @0x116efc vmul.f64 d5, d7, d6 */
/* @0x116f00 vmov r0, r1, d5 */
/* @0x116f04 bl 0x3194a0 <__fixdfdi> */
/* @0x116f08 mov r3, r1 */
/* @0x116f0c ldr r1, [pc, #0x5c] */
/* @0x116f10 mov r2, r0 */
/* @0x116f14 strd r2, r3, [sp] */
/* @0x116f18 add r1, pc, r1 */
/* @0x116f1c mov r0, sp */
/* @0x116f20 ldrb r3, [r1] */
/* @0x116f24 cmp r3, #0 */
/* @0x116f28 bne 0x116f50 <_Z13F_DateGetHourR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116f2c bl 0xb6820 <gmtime64@plt> */
/* @0x116f30 cmp r0, #0 */
/* @0x116f34 ldrne r2, [r0, #0x8] */
/* @0x116f38 vmovne s15, r2 */
/* @0x116f3c vcvtne.f64.s32 d7, s15 */
/* @0x116f40 vmovne r2, r3, d7 */
/* @0x116f44 stmne r4, {r2, r3} */
/* @0x116f48 add sp, sp, #8 */
/* @0x116f4c pop {r4, pc} */
/* @0x116f50 bl 0xb682c <localtime64@plt> */
/* @0x116f54 b 0x116f30 <_Z13F_DateGetHourR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x116f58 andeq r0, r0, r0 */
/* @0x116f5c sbcsmi pc, r8, r0, asr #16 */
/* @0x116f60 bl 0x827c1c <b2_toiTime+0xce778> */
/* @0x116f64 svclo #0x1a36e2 */
/* @0x116f68 andeq r0, r0, r0 */
/* @0x116f6c rscsmi r1, r5, r0, lsl #16 */
/* @0x116f70 eoreq r11, sp, r0, lsr #4 */

/* ── FUNC 0x116f74 · anon_116f74 · size=0 · insn=1 */
/* @0x116f74 nop */

/* ── FUNC 0x116f78 · F_DateGetMinute(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x116f78 push {r4, lr} */
/* @0x116f7c sub sp, sp, #8 */
/* @0x116f80 mov r1, #0 */
/* @0x116f84 mov r4, r0 */
/* @0x116f88 mov r3, r1 */
/* @0x116f8c str r1, [r0, #0xc] */
/* @0x116f90 movt r3, #0xbff0 */
/* @0x116f94 stm r0, {r1, r3} */
/* @0x116f98 ldr r0, [sp, #0x10] */
/* @0x116f9c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x116fa0 vldr d7, [pc, #120] */
/* @0x116fa4 vldr d5, [pc, #124] */
/* @0x116fa8 vmov d6, r0, r1 */
/* @0x116fac vsub.f64 d7, d6, d7 */
/* @0x116fb0 vabs.f64 d4, d7 */
/* @0x116fb4 vcmpe.f64 d4, d5 */
/* @0x116fb8 vmrs APSR_nzcv, fpscr */
/* @0x116fbc vldrls d7, [pc, #108] */
/* @0x116fc0 vldrhi d6, [pc, #104] */
/* @0x116fc4 vmul.f64 d5, d7, d6 */
/* @0x116fc8 vmov r0, r1, d5 */
/* @0x116fcc bl 0x3194a0 <__fixdfdi> */
/* @0x116fd0 mov r3, r1 */
/* @0x116fd4 ldr r1, [pc, #0x5c] */
/* @0x116fd8 mov r2, r0 */
/* @0x116fdc strd r2, r3, [sp] */
/* @0x116fe0 add r1, pc, r1 */
/* @0x116fe4 mov r0, sp */
/* @0x116fe8 ldrb r3, [r1] */
/* @0x116fec cmp r3, #0 */
/* @0x116ff0 bne 0x117018 <_Z15F_DateGetMinuteR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x116ff4 bl 0xb6820 <gmtime64@plt> */
/* @0x116ff8 cmp r0, #0 */
/* @0x116ffc ldrne r2, [r0, #0x4] */
/* @0x117000 vmovne s15, r2 */
/* @0x117004 vcvtne.f64.s32 d7, s15 */
/* @0x117008 vmovne r2, r3, d7 */
/* @0x11700c stmne r4, {r2, r3} */
/* @0x117010 add sp, sp, #8 */
/* @0x117014 pop {r4, pc} */
/* @0x117018 bl 0xb682c <localtime64@plt> */
/* @0x11701c b 0x116ff8 <_Z15F_DateGetMinuteR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x117020 andeq r0, r0, r0 */
/* @0x117024 sbcsmi pc, r8, r0, asr #16 */
/* @0x117028 bl 0x827ce4 <b2_toiTime+0xce840> */
/* @0x11702c svclo #0x1a36e2 */
/* @0x117030 andeq r0, r0, r0 */
/* @0x117034 rscsmi r1, r5, r0, lsl #16 */
/* @0x117038 eoreq r11, sp, r8, asr r1 */

/* ── FUNC 0x11703c · anon_11703c · size=0 · insn=1 */
/* @0x11703c nop */

/* ── FUNC 0x117040 · F_DateGetSecond(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x117040 push {r4, lr} */
/* @0x117044 sub sp, sp, #8 */
/* @0x117048 mov r1, #0 */
/* @0x11704c mov r4, r0 */
/* @0x117050 mov r3, r1 */
/* @0x117054 str r1, [r0, #0xc] */
/* @0x117058 movt r3, #0xbff0 */
/* @0x11705c stm r0, {r1, r3} */
/* @0x117060 ldr r0, [sp, #0x10] */
/* @0x117064 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x117068 vldr d7, [pc, #120] */
/* @0x11706c vldr d5, [pc, #124] */
/* @0x117070 vmov d6, r0, r1 */
/* @0x117074 vsub.f64 d7, d6, d7 */
/* @0x117078 vabs.f64 d4, d7 */
/* @0x11707c vcmpe.f64 d4, d5 */
/* @0x117080 vmrs APSR_nzcv, fpscr */
/* @0x117084 vldrls d7, [pc, #108] */
/* @0x117088 vldrhi d6, [pc, #104] */
/* @0x11708c vmul.f64 d5, d7, d6 */
/* @0x117090 vmov r0, r1, d5 */
/* @0x117094 bl 0x3194a0 <__fixdfdi> */
/* @0x117098 mov r3, r1 */
/* @0x11709c ldr r1, [pc, #0x5c] */
/* @0x1170a0 mov r2, r0 */
/* @0x1170a4 strd r2, r3, [sp] */
/* @0x1170a8 add r1, pc, r1 */
/* @0x1170ac mov r0, sp */
/* @0x1170b0 ldrb r3, [r1] */
/* @0x1170b4 cmp r3, #0 */
/* @0x1170b8 bne 0x1170e0 <_Z15F_DateGetSecondR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1170bc bl 0xb6820 <gmtime64@plt> */
/* @0x1170c0 cmp r0, #0 */
/* @0x1170c4 ldrne r2, [r0] */
/* @0x1170c8 vmovne s15, r2 */
/* @0x1170cc vcvtne.f64.s32 d7, s15 */
/* @0x1170d0 vmovne r2, r3, d7 */
/* @0x1170d4 stmne r4, {r2, r3} */
/* @0x1170d8 add sp, sp, #8 */
/* @0x1170dc pop {r4, pc} */
/* @0x1170e0 bl 0xb682c <localtime64@plt> */
/* @0x1170e4 b 0x1170c0 <_Z15F_DateGetSecondR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1170e8 andeq r0, r0, r0 */
/* @0x1170ec sbcsmi pc, r8, r0, asr #16 */
/* @0x1170f0 bl 0x827dac <b2_toiTime+0xce908> */
/* @0x1170f4 svclo #0x1a36e2 */
/* @0x1170f8 andeq r0, r0, r0 */
/* @0x1170fc rscsmi r1, r5, r0, lsl #16 */
/* @0x117100 mlaeq sp, r0, r0, r11 */

/* ── FUNC 0x117104 · anon_117104 · size=0 · insn=1 */
/* @0x117104 nop */

/* ── FUNC 0x117108 · F_DateIsToday(RValue&, CInstance*, CInstance*, int, RValue*) · size=336 · insn=84 */
/* @0x117108 push {r4, r5, r6, r7, lr} */
/* @0x11710c sub sp, sp, #20 */
/* @0x117110 mov r3, #0 */
/* @0x117114 mov r4, r0 */
/* @0x117118 str r3, [r0, #0xc] */
/* @0x11711c mov r1, r3 */
/* @0x117120 str r3, [r0] */
/* @0x117124 str r3, [r0, #0x4] */
/* @0x117128 ldr r0, [sp, #0x28] */
/* @0x11712c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x117130 vldr d7, [pc, #256] */
/* @0x117134 vldr d5, [pc, #260] */
/* @0x117138 vmov d6, r0, r1 */
/* @0x11713c vsub.f64 d7, d6, d7 */
/* @0x117140 vabs.f64 d4, d7 */
/* @0x117144 vcmpe.f64 d4, d5 */
/* @0x117148 vmrs APSR_nzcv, fpscr */
/* @0x11714c vldrls d7, [pc, #244] */
/* @0x117150 vldrhi d6, [pc, #240] */
/* @0x117154 vmul.f64 d5, d7, d6 */
/* @0x117158 vmov r0, r1, d5 */
/* @0x11715c bl 0x3194a0 <__fixdfdi> */
/* @0x117160 mov r3, r1 */
/* @0x117164 ldr r1, [pc, #0xe4] */
/* @0x117168 mov r2, r0 */
/* @0x11716c strd r2, r3, [sp] */
/* @0x117170 add r1, pc, r1 */
/* @0x117174 mov r0, sp */
/* @0x117178 ldrb r3, [r1] */
/* @0x11717c cmp r3, #0 */
/* @0x117180 bne 0x117228 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x117184 bl 0xb6820 <gmtime64@plt> */
/* @0x117188 mov r3, r0 */
/* @0x11718c cmp r3, #0 */
/* @0x117190 beq 0x1171e8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x117194 mov r0, #0 */
/* @0x117198 ldr r6, [r3, #0x10] */
/* @0x11719c ldr r5, [r3, #0x14] */
/* @0x1171a0 ldr r7, [r3, #0x1c] */
/* @0x1171a4 bl 0xb67fc <time@plt> */
/* @0x1171a8 ldr r3, [pc, #0xa4] */
/* @0x1171ac add r3, pc, r3 */
/* @0x1171b0 ldrb r3, [r3] */
/* @0x1171b4 cmp r3, #0 */
/* @0x1171b8 asr r1, r0, #31 */
/* @0x1171bc strd r0, r1, [sp, #8] */
/* @0x1171c0 add r0, sp, #8 */
/* @0x1171c4 bne 0x1171f0 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x1171c8 bl 0xb6820 <gmtime64@plt> */
/* @0x1171cc ldr r3, [r0, #0x14] */
/* @0x1171d0 cmp r3, r5 */
/* @0x1171d4 beq 0x117200 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1171d8 mov r3, #0 */
/* @0x1171dc mov r2, r3 */
/* @0x1171e0 str r3, [r4] */
/* @0x1171e4 str r2, [r4, #0x4] */
/* @0x1171e8 add sp, sp, #20 */
/* @0x1171ec pop {r4, r5, r6, r7, pc} */
/* @0x1171f0 bl 0xb682c <localtime64@plt> */
/* @0x1171f4 ldr r3, [r0, #0x14] */
/* @0x1171f8 cmp r3, r5 */
/* @0x1171fc bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x117200 ldr r3, [r0, #0x10] */
/* @0x117204 cmp r3, r6 */
/* @0x117208 bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x11720c ldr r3, [r0, #0x1c] */
/* @0x117210 cmp r3, r7 */
/* @0x117214 bne 0x1171d8 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x117218 mov r2, #0 */
/* @0x11721c mov r3, #0 */
/* @0x117220 movt r2, #0x3ff0 */
/* @0x117224 b 0x1171e0 <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x117228 bl 0xb682c <localtime64@plt> */
/* @0x11722c mov r3, r0 */
/* @0x117230 b 0x11718c <_Z13F_DateIsTodayR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x117234 nop */
/* @0x117238 andeq r0, r0, r0 */
/* @0x11723c sbcsmi pc, r8, r0, asr #16 */
/* @0x117240 bl 0x827efc <b2_toiTime+0xcea58> */
/* @0x117244 svclo #0x1a36e2 */
/* @0x117248 andeq r0, r0, r0 */
/* @0x11724c rscsmi r1, r5, r0, lsl #16 */
/* @0x117250 eoreq r10, sp, r8, asr #31 */
/* @0x117254 eoreq r10, sp, r12, lsl #31 */

/* ── FUNC 0x117258 · F_DateDateTimeString(RValue&, CInstance*, CInstance*, int, RValue*) · size=368 · insn=92 */
/* @0x117258 push {r4, r5, r6, r7, lr} */
/* @0x11725c mov r5, r0 */
/* @0x117260 ldr r4, [pc, #0x148] */
/* @0x117264 sub sp, sp, #1040 */
/* @0x117268 sub sp, sp, #4 */
/* @0x11726c mov r3, #1 */
/* @0x117270 ldr r4, [pc, r4] */
/* @0x117274 str r3, [r5, #0xc] */
/* @0x117278 ldr r0, [sp, #0x428] */
/* @0x11727c mov r1, #0 */
/* @0x117280 ldr r3, [r4] */
/* @0x117284 str r3, [sp, #0x40c] */
/* @0x117288 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11728c vldr d7, [pc, #260] */
/* @0x117290 vldr d5, [pc, #264] */
/* @0x117294 vmov d6, r0, r1 */
/* @0x117298 vsub.f64 d7, d6, d7 */
/* @0x11729c vabs.f64 d4, d7 */
/* @0x1172a0 vcmpe.f64 d4, d5 */
/* @0x1172a4 vmrs APSR_nzcv, fpscr */
/* @0x1172a8 vldrls d7, [pc, #248] */
/* @0x1172ac vldrhi d6, [pc, #244] */
/* @0x1172b0 vmul.f64 d5, d7, d6 */
/* @0x1172b4 vmov r0, r1, d5 */
/* @0x1172b8 bl 0x3194a0 <__fixdfdi> */
/* @0x1172bc add r12, sp, #1040 */
/* @0x1172c0 mov r2, r0 */
/* @0x1172c4 ldr r0, [pc, #0xe8] */
/* @0x1172c8 mov r3, r1 */
/* @0x1172cc movw r1, #0xfbf0 */
/* @0x1172d0 add r0, pc, r0 */
/* @0x1172d4 movt r1, #0xffff */
/* @0x1172d8 ldrb r0, [r0] */
/* @0x1172dc strd r2, r3, [r12, r1] */
/* @0x1172e0 cmp r0, #0 */
/* @0x1172e4 mov r0, sp */
/* @0x1172e8 bne 0x117360 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1172ec bl 0xb6820 <gmtime64@plt> */
/* @0x1172f0 mov r7, r0 */
/* @0x1172f4 cmp r7, #0 */
/* @0x1172f8 beq 0x117370 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1172fc ldr r1, [pc, #0xb4] */
/* @0x117300 mov r0, #6 */
/* @0x117304 add r6, sp, #12 */
/* @0x117308 add r1, pc, r1 */
/* @0x11730c bl 0xb679c <setlocale@plt> */
/* @0x117310 ldr r2, [pc, #0xa4] */
/* @0x117314 mov r1, #1024 */
/* @0x117318 mov r3, r7 */
/* @0x11731c add r2, pc, r2 */
/* @0x117320 mov r0, r6 */
/* @0x117324 bl 0xb6838 <strftime@plt> */
/* @0x117328 ldr r1, [pc, #0x90] */
/* @0x11732c mov r0, #6 */
/* @0x117330 add r1, pc, r1 */
/* @0x117334 bl 0xb679c <setlocale@plt> */
/* @0x117338 mov r0, r5 */
/* @0x11733c mov r1, r6 */
/* @0x117340 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x117344 ldr r2, [sp, #0x40c] */
/* @0x117348 ldr r3, [r4] */
/* @0x11734c cmp r2, r3 */
/* @0x117350 bne 0x117390 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x117354 add sp, sp, #1040 */
/* @0x117358 add sp, sp, #4 */
/* @0x11735c pop {r4, r5, r6, r7, pc} */
/* @0x117360 bl 0xb682c <localtime64@plt> */
/* @0x117364 mov r7, r0 */
/* @0x117368 cmp r7, #0 */
/* @0x11736c bne 0x1172fc <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x117370 ldr r3, [pc, #0x4c] */
/* @0x117374 add r6, sp, #12 */
/* @0x117378 add r3, pc, r3 */
/* @0x11737c mov r12, r6 */
/* @0x117380 ldm r3, {r0, r1, r2, r3} */
/* @0x117384 stm r12!, {r0, r1, r2} */
/* @0x117388 strb r3, [r12] */
/* @0x11738c b 0x117338 <_Z20F_DateDateTimeStringR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x117390 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x117394 nop */
/* @0x117398 andeq r0, r0, r0 */
/* @0x11739c sbcsmi pc, r8, r0, asr #16 */
/* @0x1173a0 bl 0x82805c <b2_toiTime+0xcebb8> */
/* @0x1173a4 svclo #0x1a36e2 */
/* @0x1173a8 andeq r0, r0, r0 */
/* @0x1173ac rscsmi r1, r5, r0, lsl #16 */
/* @0x1173b0 eoreq r6, sp, r0, ror #13 */
/* @0x1173b4 eoreq r10, sp, r8, ror #28 */
/* @0x1173b8 eoreq r7, r1, lr, lsr #16 */
/* @0x1173bc eoreq r2, r2, r0, asr #9 */
/* @0x1173c0 eoreq r1, r2, r0, ror sp */
/* @0x1173c4 eoreq r2, r2, r8, ror #8 */

/* ── FUNC 0x1173c8 · F_DateDateString(RValue&, CInstance*, CInstance*, int, RValue*) · size=368 · insn=92 */
/* @0x1173c8 push {r4, r5, r6, r7, lr} */
/* @0x1173cc mov r5, r0 */
/* @0x1173d0 ldr r4, [pc, #0x148] */
/* @0x1173d4 sub sp, sp, #1040 */
/* @0x1173d8 sub sp, sp, #4 */
/* @0x1173dc mov r3, #1 */
/* @0x1173e0 ldr r4, [pc, r4] */
/* @0x1173e4 str r3, [r5, #0xc] */
/* @0x1173e8 ldr r0, [sp, #0x428] */
/* @0x1173ec mov r1, #0 */
/* @0x1173f0 ldr r3, [r4] */
/* @0x1173f4 str r3, [sp, #0x40c] */
/* @0x1173f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1173fc vldr d7, [pc, #260] */
/* @0x117400 vldr d5, [pc, #264] */
/* @0x117404 vmov d6, r0, r1 */
/* @0x117408 vsub.f64 d7, d6, d7 */
/* @0x11740c vabs.f64 d4, d7 */
/* @0x117410 vcmpe.f64 d4, d5 */
/* @0x117414 vmrs APSR_nzcv, fpscr */
/* @0x117418 vldrls d7, [pc, #248] */
/* @0x11741c vldrhi d6, [pc, #244] */
/* @0x117420 vmul.f64 d5, d7, d6 */
/* @0x117424 vmov r0, r1, d5 */
/* @0x117428 bl 0x3194a0 <__fixdfdi> */
/* @0x11742c add r12, sp, #1040 */
/* @0x117430 mov r2, r0 */
/* @0x117434 ldr r0, [pc, #0xe8] */
/* @0x117438 mov r3, r1 */
/* @0x11743c movw r1, #0xfbf0 */
/* @0x117440 add r0, pc, r0 */
/* @0x117444 movt r1, #0xffff */
/* @0x117448 ldrb r0, [r0] */
/* @0x11744c strd r2, r3, [r12, r1] */
/* @0x117450 cmp r0, #0 */
/* @0x117454 mov r0, sp */
/* @0x117458 bne 0x1174d0 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x11745c bl 0xb6820 <gmtime64@plt> */
/* @0x117460 mov r7, r0 */
/* @0x117464 cmp r7, #0 */
/* @0x117468 beq 0x1174e0 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x11746c ldr r1, [pc, #0xb4] */
/* @0x117470 mov r0, #6 */
/* @0x117474 add r6, sp, #12 */
/* @0x117478 add r1, pc, r1 */
/* @0x11747c bl 0xb679c <setlocale@plt> */
/* @0x117480 ldr r2, [pc, #0xa4] */
/* @0x117484 mov r1, #1024 */
/* @0x117488 mov r3, r7 */
/* @0x11748c add r2, pc, r2 */
/* @0x117490 mov r0, r6 */
/* @0x117494 bl 0xb6838 <strftime@plt> */
/* @0x117498 ldr r1, [pc, #0x90] */
/* @0x11749c mov r0, #6 */
/* @0x1174a0 add r1, pc, r1 */
/* @0x1174a4 bl 0xb679c <setlocale@plt> */
/* @0x1174a8 mov r0, r5 */
/* @0x1174ac mov r1, r6 */
/* @0x1174b0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1174b4 ldr r2, [sp, #0x40c] */
/* @0x1174b8 ldr r3, [r4] */
/* @0x1174bc cmp r2, r3 */
/* @0x1174c0 bne 0x117500 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1174c4 add sp, sp, #1040 */
/* @0x1174c8 add sp, sp, #4 */
/* @0x1174cc pop {r4, r5, r6, r7, pc} */
/* @0x1174d0 bl 0xb682c <localtime64@plt> */
/* @0x1174d4 mov r7, r0 */
/* @0x1174d8 cmp r7, #0 */
/* @0x1174dc bne 0x11746c <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x1174e0 ldr r3, [pc, #0x4c] */
/* @0x1174e4 add r6, sp, #12 */
/* @0x1174e8 add r3, pc, r3 */
/* @0x1174ec mov r12, r6 */
/* @0x1174f0 ldm r3, {r0, r1, r2, r3} */
/* @0x1174f4 stm r12!, {r0, r1, r2} */
/* @0x1174f8 strb r3, [r12] */
/* @0x1174fc b 0x1174a8 <_Z16F_DateDateStringR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x117500 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x117504 nop */
/* @0x117508 andeq r0, r0, r0 */
/* @0x11750c sbcsmi pc, r8, r0, asr #16 */
/* @0x117510 bl 0x8281cc <b2_toiTime+0xced28> */
/* @0x117514 svclo #0x1a36e2 */
/* @0x117518 andeq r0, r0, r0 */
/* @0x11751c rscsmi r1, r5, r0, lsl #16 */
/* @0x117520 eoreq r6, sp, r0, ror r5 */
/* @0x117524 .word 0x002dacf8 */
/* @0x117528 .word 0x002176be */
/* @0x11752c eoreq r2, r2, r4, ror #6 */
/* @0x117530 eoreq r1, r2, r0, lsl #24 */
/* @0x117534 .word 0x002222f8 */

/* ── FUNC 0x117538 · F_DateTimeString(RValue&, CInstance*, CInstance*, int, RValue*) · size=368 · insn=92 */
/* @0x117538 push {r4, r5, r6, r7, lr} */
/* @0x11753c mov r5, r0 */
/* @0x117540 ldr r4, [pc, #0x148] */
/* @0x117544 sub sp, sp, #1040 */
/* @0x117548 sub sp, sp, #4 */
/* @0x11754c mov r3, #1 */
/* @0x117550 ldr r4, [pc, r4] */
/* @0x117554 str r3, [r5, #0xc] */
/* @0x117558 ldr r0, [sp, #0x428] */
/* @0x11755c mov r1, #0 */
/* @0x117560 ldr r3, [r4] */
/* @0x117564 str r3, [sp, #0x40c] */
/* @0x117568 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x11756c vldr d7, [pc, #260] */
/* @0x117570 vldr d5, [pc, #264] */
/* @0x117574 vmov d6, r0, r1 */
/* @0x117578 vsub.f64 d7, d6, d7 */
/* @0x11757c vabs.f64 d4, d7 */
/* @0x117580 vcmpe.f64 d4, d5 */
/* @0x117584 vmrs APSR_nzcv, fpscr */
/* @0x117588 vldrls d7, [pc, #248] */
/* @0x11758c vldrhi d6, [pc, #244] */
/* @0x117590 vmul.f64 d5, d7, d6 */
/* @0x117594 vmov r0, r1, d5 */
/* @0x117598 bl 0x3194a0 <__fixdfdi> */
/* @0x11759c add r12, sp, #1040 */
/* @0x1175a0 mov r2, r0 */
/* @0x1175a4 ldr r0, [pc, #0xe8] */
/* @0x1175a8 mov r3, r1 */
/* @0x1175ac movw r1, #0xfbf0 */
/* @0x1175b0 add r0, pc, r0 */
/* @0x1175b4 movt r1, #0xffff */
/* @0x1175b8 ldrb r0, [r0] */
/* @0x1175bc strd r2, r3, [r12, r1] */
/* @0x1175c0 cmp r0, #0 */
/* @0x1175c4 mov r0, sp */
/* @0x1175c8 bne 0x117640 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1175cc bl 0xb6820 <gmtime64@plt> */
/* @0x1175d0 mov r7, r0 */
/* @0x1175d4 cmp r7, #0 */
/* @0x1175d8 beq 0x117650 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1175dc ldr r1, [pc, #0xb4] */
/* @0x1175e0 mov r0, #6 */
/* @0x1175e4 add r6, sp, #12 */
/* @0x1175e8 add r1, pc, r1 */
/* @0x1175ec bl 0xb679c <setlocale@plt> */
/* @0x1175f0 ldr r2, [pc, #0xa4] */
/* @0x1175f4 mov r1, #1024 */
/* @0x1175f8 mov r3, r7 */
/* @0x1175fc add r2, pc, r2 */
/* @0x117600 mov r0, r6 */
/* @0x117604 bl 0xb6838 <strftime@plt> */
/* @0x117608 ldr r1, [pc, #0x90] */
/* @0x11760c mov r0, #6 */
/* @0x117610 add r1, pc, r1 */
/* @0x117614 bl 0xb679c <setlocale@plt> */
/* @0x117618 mov r0, r5 */
/* @0x11761c mov r1, r6 */
/* @0x117620 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x117624 ldr r2, [sp, #0x40c] */
/* @0x117628 ldr r3, [r4] */
/* @0x11762c cmp r2, r3 */
/* @0x117630 bne 0x117670 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x117634 add sp, sp, #1040 */
/* @0x117638 add sp, sp, #4 */
/* @0x11763c pop {r4, r5, r6, r7, pc} */
/* @0x117640 bl 0xb682c <localtime64@plt> */
/* @0x117644 mov r7, r0 */
/* @0x117648 cmp r7, #0 */
/* @0x11764c bne 0x1175dc <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x117650 ldr r3, [pc, #0x4c] */
/* @0x117654 add r6, sp, #12 */
/* @0x117658 add r3, pc, r3 */
/* @0x11765c mov r12, r6 */
/* @0x117660 ldm r3, {r0, r1, r2, r3} */
/* @0x117664 stm r12!, {r0, r1, r2} */
/* @0x117668 strb r3, [r12] */
/* @0x11766c b 0x117618 <_Z16F_DateTimeStringR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x117670 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x117674 nop */
/* @0x117678 andeq r0, r0, r0 */
/* @0x11767c sbcsmi pc, r8, r0, asr #16 */
/* @0x117680 bl 0x82833c <b2_toiTime+0xcee98> */
/* @0x117684 svclo #0x1a36e2 */
/* @0x117688 andeq r0, r0, r0 */
/* @0x11768c rscsmi r1, r5, r0, lsl #16 */
/* @0x117690 eoreq r6, sp, r0, lsl #8 */
/* @0x117694 eoreq r10, sp, r8, lsl #23 */
/* @0x117698 eoreq r7, r1, lr, asr #10 */
/* @0x11769c .word 0x002221f8 */
/* @0x1176a0 mlaeq r2, r0, r10, r1 */
/* @0x1176a4 eoreq r2, r2, r8, lsl #3 */

/* ── FUNC 0x1176a8 · YYGML_show_debug_message(YYRValue const&) · size=520 · insn=130 */
/* @0x1176a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1176ac sub sp, sp, #1040 */
/* @0x1176b0 ldr r9, [pc, #0x1d4] */
/* @0x1176b4 sub sp, sp, #12 */
/* @0x1176b8 ldr r3, [pc, #0x1d0] */
/* @0x1176bc mov r4, r0 */
/* @0x1176c0 add r9, pc, r9 */
/* @0x1176c4 ldr r2, [r0, #0xc] */
/* @0x1176c8 ldr r3, [r9, r3] */
/* @0x1176cc str r3, [sp] */
/* @0x1176d0 bic r3, r2, #-16777216 */
/* @0x1176d4 ldr r1, [sp] */
/* @0x1176d8 cmp r3, #1 */
/* @0x1176dc ldr r3, [r1] */
/* @0x1176e0 str r3, [sp, #0x414] */
/* @0x1176e4 movne r3, #0 */
/* @0x1176e8 strne r3, [sp, #0x4] */
/* @0x1176ec beq 0x117874 <_Z24YYGML_show_debug_messageRK8YYRValue+0x1cc> */
/* @0x1176f0 cmp r2, #1 */
/* @0x1176f4 beq 0x117844 <_Z24YYGML_show_debug_messageRK8YYRValue+0x19c> */
/* @0x1176f8 ldr r1, [pc, #0x194] */
/* @0x1176fc mov r12, #256 */
/* @0x117700 mov r0, r12 */
/* @0x117704 movw r2, #0x20e */
/* @0x117708 add r1, pc, r1 */
/* @0x11770c mov r3, #1 */
/* @0x117710 str r12, [sp, #0x8] */
/* @0x117714 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x117718 mov r12, #0 */
/* @0x11771c mov r3, r4 */
/* @0x117720 add r1, sp, #12 */
/* @0x117724 mov r2, r0 */
/* @0x117728 str r0, [sp, #0xc] */
/* @0x11772c str r0, [sp, #0x10] */
/* @0x117730 add r0, sp, #16 */
/* @0x117734 strb r12, [r2] */
/* @0x117738 add r2, sp, #8 */
/* @0x11773c bl 0xcff78 <_Z13STRING_RValuePPcS0_PiPK6RValue> */
/* @0x117740 ldr r10, [sp, #0xc] */
/* @0x117744 mov r0, r10 */
/* @0x117748 bl 0xb6538 <strlen@plt> */
/* @0x11774c cmp r0, #1024 */
/* @0x117750 mov r11, r0 */
/* @0x117754 ble 0x11784c <_Z24YYGML_show_debug_messageRK8YYRValue+0x1a4> */
/* @0x117758 ldr r2, [pc, #0x138] */
/* @0x11775c add r6, sp, #20 */
/* @0x117760 ldr r8, [pc, #0x134] */
/* @0x117764 mov r4, r10 */
/* @0x117768 mov r7, #0 */
/* @0x11776c ldr r2, [r9, r2] */
/* @0x117770 add r8, pc, r8 */
/* @0x117774 ldr r5, [r2] */
/* @0x117778 mov r1, r4 */
/* @0x11777c movw r2, #0x3ff */
/* @0x117780 mov r0, r6 */
/* @0x117784 sub r11, r11, #1020 */
/* @0x117788 bl 0xb6568 <strncpy@plt> */
/* @0x11778c strb r7, [sp, #0x413] */
/* @0x117790 ldr r3, [r5] */
/* @0x117794 mov r0, r5 */
/* @0x117798 mov r1, r8 */
/* @0x11779c mov r2, r6 */
/* @0x1177a0 sub r11, r11, #3 */
/* @0x1177a4 add r4, r4, #1020 */
/* @0x1177a8 ldr r3, [r3, #0xc] */
/* @0x1177ac add r4, r4, #3 */
/* @0x1177b0 blx r3 */
/* @0x1177b4 cmp r11, #1024 */
/* @0x1177b8 bge 0x117778 <_Z24YYGML_show_debug_messageRK8YYRValue+0xd0> */
/* @0x1177bc ldr r3, [r5] */
/* @0x1177c0 mov r2, r4 */
/* @0x1177c4 ldr r1, [pc, #0xd4] */
/* @0x1177c8 mov r0, r5 */
/* @0x1177cc add r1, pc, r1 */
/* @0x1177d0 ldr r3, [r3, #0xc] */
/* @0x1177d4 blx r3 */
/* @0x1177d8 ldr r1, [sp, #0x4] */
/* @0x1177dc cmp r10, r1 */
/* @0x1177e0 beq 0x1177ec <_Z24YYGML_show_debug_messageRK8YYRValue+0x144> */
/* @0x1177e4 mov r0, r10 */
/* @0x1177e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1177ec ldr r3, [pc, #0xb0] */
/* @0x1177f0 ldr r3, [r9, r3] */
/* @0x1177f4 ldrb r3, [r3] */
/* @0x1177f8 cmp r3, #0 */
/* @0x1177fc beq 0x117814 <_Z24YYGML_show_debug_messageRK8YYRValue+0x16c> */
/* @0x117800 ldr r3, [pc, #0xa0] */
/* @0x117804 ldr r3, [r9, r3] */
/* @0x117808 ldr r3, [r3] */
/* @0x11780c cmp r3, #0 */
/* @0x117810 beq 0x117834 <_Z24YYGML_show_debug_messageRK8YYRValue+0x18c> */
/* @0x117814 ldr r1, [sp] */
/* @0x117818 ldr r2, [sp, #0x414] */
/* @0x11781c ldr r3, [r1] */
/* @0x117820 cmp r2, r3 */
/* @0x117824 bne 0x117888 <_Z24YYGML_show_debug_messageRK8YYRValue+0x1e0> */
/* @0x117828 add sp, sp, #1040 */
/* @0x11782c add sp, sp, #12 */
/* @0x117830 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x117834 mov r1, r10 */
/* @0x117838 mov r0, #1 */
/* @0x11783c bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x117840 b 0x117814 <_Z24YYGML_show_debug_messageRK8YYRValue+0x16c> */
/* @0x117844 ldr r10, [sp, #0x4] */
/* @0x117848 b 0x117744 <_Z24YYGML_show_debug_messageRK8YYRValue+0x9c> */
/* @0x11784c ldr r3, [pc, #0x44] */
/* @0x117850 mov r2, r10 */
/* @0x117854 ldr r1, [pc, #0x50] */
/* @0x117858 ldr r3, [r9, r3] */
/* @0x11785c add r1, pc, r1 */
/* @0x117860 ldr r0, [r3] */
/* @0x117864 ldr r3, [r0] */
/* @0x117868 ldr r3, [r3, #0xc] */
/* @0x11786c blx r3 */
/* @0x117870 b 0x1177d8 <_Z24YYGML_show_debug_messageRK8YYRValue+0x130> */
/* @0x117874 ldr r11, [r0] */
/* @0x117878 cmp r11, #0 */
/* @0x11787c ldrne r11, [r11] */
/* @0x117880 str r11, [sp, #0x4] */
/* @0x117884 b 0x1176f0 <_Z24YYGML_show_debug_messageRK8YYRValue+0x48> */
/* @0x117888 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x11788c mlaeq sp, r0, r5, r10 */
/* @0x117890 .word 0xffffbd00 */
/* @0x117894 .word 0x002220f0 */
/* @0x117898 .word 0xffffbcf0 */
/* @0x11789c mlaeq r1, r8, r3, sp */
/* @0x1178a0 .word 0x0021d4d8 */
/* @0x1178a4 .word 0xffffbcd4 */
/* @0x1178a8 .word 0xffffc7d0 */
/* @0x1178ac eoreq sp, r1, r8, asr #8 */

/* ── FUNC 0x1178b0 · F_ShowDebugMessage(RValue&, CInstance*, CInstance*, int, RValue*) · size=8 · insn=2 */
/* @0x1178b0 ldr r0, [sp] */
/* @0x1178b4 b 0x1176a8 <_Z24YYGML_show_debug_messageRK8YYRValue> */

/* ── FUNC 0x1178b8 · DoVariableInstanceExists(CInstance*, char const*) · size=132 · insn=33 */
/* @0x1178b8 push {r4, r5, lr} */
/* @0x1178bc mov r5, r0 */
/* @0x1178c0 sub sp, sp, #20 */
/* @0x1178c4 mov r0, r1 */
/* @0x1178c8 mov r4, r1 */
/* @0x1178cc bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x1178d0 subs r1, r0, #0 */
/* @0x1178d4 blt 0x117918 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x60> */
/* @0x1178d8 mov r3, sp */
/* @0x1178dc mov r0, r5 */
/* @0x1178e0 mov r2, #-2147483648 */
/* @0x1178e4 mov r12, #0 */
/* @0x1178e8 str r12, [sp] */
/* @0x1178ec str r12, [sp, #0x4] */
/* @0x1178f0 str r12, [sp, #0x8] */
/* @0x1178f4 str r12, [sp, #0xc] */
/* @0x1178f8 bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1178fc ldr r0, [sp, #0xc] */
/* @0x117900 mvn r3, #-16777216 */
/* @0x117904 and r0, r0, r3 */
/* @0x117908 subs r0, r0, r3 */
/* @0x11790c movne r0, #1 */
/* @0x117910 add sp, sp, #20 */
/* @0x117914 pop {r4, r5, pc} */
/* @0x117918 mov r1, r4 */
/* @0x11791c mov r0, r5 */
/* @0x117920 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x117924 cmp r0, #0 */
/* @0x117928 movlt r0, #0 */
/* @0x11792c blt 0x117910 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x58> */
/* @0x117930 add r1, r0, #99328 */
/* @0x117934 add r1, r1, #672 */
/* @0x117938 b 0x1178d8 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x20> */

/* ── FUNC 0x11793c · F_VariableInstanceExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0x11793c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x117940 sub sp, sp, #48 */
/* @0x117944 mov r6, r0 */
/* @0x117948 mov r9, r1 */
/* @0x11794c ldr r5, [sp, #0x50] */
/* @0x117950 mov r1, #0 */
/* @0x117954 mov r8, r2 */
/* @0x117958 add r4, sp, #12 */
/* @0x11795c mov r0, r5 */
/* @0x117960 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x117964 mov r1, #1 */
/* @0x117968 mov r10, r0 */
/* @0x11796c mov r0, r5 */
/* @0x117970 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x117974 mov r12, #0 */
/* @0x117978 mov r1, r10 */
/* @0x11797c str r12, [r6] */
/* @0x117980 str r12, [r6, #0x4] */
/* @0x117984 mov r2, r9 */
/* @0x117988 mov r3, r8 */
/* @0x11798c mov r7, r0 */
/* @0x117990 mov r0, #13 */
/* @0x117994 str r0, [r6, #0xc] */
/* @0x117998 mov r0, r4 */
/* @0x11799c str r12, [sp] */
/* @0x1179a0 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */
/* @0x1179a4 b 0x1179dc <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1179a8 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x1179ac ldrb r2, [r0, #0x68] */
/* @0x1179b0 cmp r2, #0 */
/* @0x1179b4 bne 0x1179d4 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1179b8 ldrb r5, [r0, #0x69] */
/* @0x1179bc cmp r5, #0 */
/* @0x1179c0 bne 0x1179d4 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1179c4 mov r1, r7 */
/* @0x1179c8 bl 0x1178b8 <_Z24DoVariableInstanceExistsP9CInstancePKc> */
/* @0x1179cc cmp r0, #0 */
/* @0x1179d0 bne 0x1179f8 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1179d4 mov r0, r4 */
/* @0x1179d8 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */
/* @0x1179dc mov r0, r4 */
/* @0x1179e0 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x1179e4 cmp r0, #0 */
/* @0x1179e8 mov r0, r4 */
/* @0x1179ec bne 0x1179a8 <_Z24F_VariableInstanceExistsR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1179f0 add sp, sp, #48 */
/* @0x1179f4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1179f8 str r5, [r6] */
/* @0x1179fc mov r3, #0 */
/* @0x117a00 movt r3, #0x3ff0 */
/* @0x117a04 str r3, [r6, #0x4] */
/* @0x117a08 add sp, sp, #48 */
/* @0x117a0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x117a10 · CurrentTimeToTM() · size=76 · insn=19 */
/* @0x117a10 str lr, [sp, #-0x4]! */
/* @0x117a14 mov r0, #0 */
/* @0x117a18 sub sp, sp, #12 */
/* @0x117a1c bl 0xb67fc <time@plt> */
/* @0x117a20 ldr r3, [pc, #0x30] */
/* @0x117a24 add r3, pc, r3 */
/* @0x117a28 ldrb r3, [r3] */
/* @0x117a2c cmp r3, #0 */
/* @0x117a30 asr r1, r0, #31 */
/* @0x117a34 strd r0, r1, [sp] */
/* @0x117a38 mov r0, sp */
/* @0x117a3c bne 0x117a4c <_Z15CurrentTimeToTMv+0x3c> */
/* @0x117a40 bl 0xb6820 <gmtime64@plt> */
/* @0x117a44 add sp, sp, #12 */
/* @0x117a48 ldr pc, [sp], #4 */
/* @0x117a4c bl 0xb682c <localtime64@plt> */
/* @0x117a50 add sp, sp, #12 */
/* @0x117a54 ldr pc, [sp], #4 */
/* @0x117a58 eoreq r10, sp, r4, lsl r7 */

/* ── FUNC 0x117a5c · is_leap_year(int) · size=84 · insn=21 */
/* @0x117a5c tst r0, #3 */
/* @0x117a60 bne 0x117aa8 <_Z12is_leap_yeari+0x4c> */
/* @0x117a64 movw r3, #0x851f */
/* @0x117a68 movt r3, #0x51eb */
/* @0x117a6c asr r2, r0, #31 */
/* @0x117a70 mov r12, #400 */
/* @0x117a74 smull r1, r3, r3, r0 */
/* @0x117a78 rsb r1, r2, r3, asr #7 */
/* @0x117a7c mls r1, r12, r1, r0 */
/* @0x117a80 cmp r1, #0 */
/* @0x117a84 beq 0x117aa0 <_Z12is_leap_yeari+0x44> */
/* @0x117a88 rsb r3, r2, r3, asr #5 */
/* @0x117a8c mov r2, #100 */
/* @0x117a90 mls r0, r2, r3, r0 */
/* @0x117a94 adds r0, r0, #0 */
/* @0x117a98 movne r0, #1 */
/* @0x117a9c bx lr */
/* @0x117aa0 mov r0, #1 */
/* @0x117aa4 bx lr */
/* @0x117aa8 mov r0, #0 */
/* @0x117aac bx lr */

/* ── FUNC 0x117ab0 · F_DateDaysInMonth(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0x117ab0 push {r4, r5, lr} */
/* @0x117ab4 mov r5, #0 */
/* @0x117ab8 ldr lr, [pc, #0x110] */
/* @0x117abc mov r4, r0 */
/* @0x117ac0 str r5, [r0, #0xc] */
/* @0x117ac4 sub sp, sp, #68 */
/* @0x117ac8 add lr, pc, lr */
/* @0x117acc add r12, sp, #12 */
/* @0x117ad0 str r5, [r4] */
/* @0x117ad4 ldm lr!, {r0, r1, r2, r3} */
/* @0x117ad8 str r5, [r4, #0x4] */
/* @0x117adc stm r12!, {r0, r1, r2, r3} */
/* @0x117ae0 ldm lr!, {r0, r1, r2, r3} */
/* @0x117ae4 stm r12!, {r0, r1, r2, r3} */
/* @0x117ae8 ldm lr!, {r0, r1, r2, r3} */
/* @0x117aec ldr lr, [lr] */
/* @0x117af0 stm r12!, {r0, r1, r2, r3} */
/* @0x117af4 mov r1, r5 */
/* @0x117af8 ldr r0, [sp, #0x50] */
/* @0x117afc str lr, [r12] */
/* @0x117b00 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x117b04 vldr d7, [pc, #172] */
/* @0x117b08 vldr d5, [pc, #176] */
/* @0x117b0c vmov d6, r0, r1 */
/* @0x117b10 vsub.f64 d7, d6, d7 */
/* @0x117b14 vabs.f64 d4, d7 */
/* @0x117b18 vcmpe.f64 d4, d5 */
/* @0x117b1c vmrs APSR_nzcv, fpscr */
/* @0x117b20 vldrls d7, [pc, #160] */
/* @0x117b24 vldrhi d6, [pc, #156] */
/* @0x117b28 vmul.f64 d5, d7, d6 */
/* @0x117b2c vmov r0, r1, d5 */
/* @0x117b30 bl 0x3194a0 <__fixdfdi> */
/* @0x117b34 mov r3, r1 */
/* @0x117b38 ldr r1, [pc, #0x94] */
/* @0x117b3c mov r2, r0 */
/* @0x117b40 strd r2, r3, [sp] */
/* @0x117b44 add r1, pc, r1 */
/* @0x117b48 mov r0, sp */
/* @0x117b4c ldrb r3, [r1] */
/* @0x117b50 cmp r3, #0 */
/* @0x117b54 bne 0x117bac <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x117b58 bl 0xb6820 <gmtime64@plt> */
/* @0x117b5c mov r5, r0 */
/* @0x117b60 cmp r5, #0 */
/* @0x117b64 beq 0x117ba4 <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x117b68 ldr r0, [r5, #0x14] */
/* @0x117b6c add r0, r0, #1888 */
/* @0x117b70 add r0, r0, #12 */
/* @0x117b74 bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117b78 add r2, sp, #64 */
/* @0x117b7c cmp r0, #0 */
/* @0x117b80 movne r3, #29 */
/* @0x117b84 strne r3, [sp, #0x14] */
/* @0x117b88 ldr r3, [r5, #0x10] */
/* @0x117b8c add r3, r2, r3, lsl #2 */
/* @0x117b90 ldr r2, [r3, #-0x30] */
/* @0x117b94 vmov s11, r2 */
/* @0x117b98 vcvt.f64.s32 d5, s11 */
/* @0x117b9c vmov r2, r3, d5 */
/* @0x117ba0 stm r4, {r2, r3} */
/* @0x117ba4 add sp, sp, #68 */
/* @0x117ba8 pop {r4, r5, pc} */
/* @0x117bac bl 0xb682c <localtime64@plt> */
/* @0x117bb0 mov r5, r0 */
/* @0x117bb4 b 0x117b60 <_Z17F_DateDaysInMonthR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x117bb8 andeq r0, r0, r0 */
/* @0x117bbc sbcsmi pc, r8, r0, asr #16 */
/* @0x117bc0 bl 0x82887c <b2_toiTime+0xcf3d8> */
/* @0x117bc4 svclo #0x1a36e2 */
/* @0x117bc8 andeq r0, r0, r0 */
/* @0x117bcc rscsmi r1, r5, r0, lsl #16 */
/* @0x117bd0 eoreq r4, r4, r8, ror lr */
/* @0x117bd4 .word 0x002da5f4 */

/* ── FUNC 0x117bd8 · F_DateDaysInYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x117bd8 push {r4, lr} */
/* @0x117bdc sub sp, sp, #8 */
/* @0x117be0 mov r1, #0 */
/* @0x117be4 mov r4, r0 */
/* @0x117be8 str r1, [r0, #0xc] */
/* @0x117bec mov r3, #53248 */
/* @0x117bf0 movt r3, #0x4076 */
/* @0x117bf4 stm r0, {r1, r3} */
/* @0x117bf8 ldr r0, [sp, #0x10] */
/* @0x117bfc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x117c00 vldr d7, [pc, #144] */
/* @0x117c04 vldr d5, [pc, #148] */
/* @0x117c08 vmov d6, r0, r1 */
/* @0x117c0c vsub.f64 d7, d6, d7 */
/* @0x117c10 vabs.f64 d4, d7 */
/* @0x117c14 vcmpe.f64 d4, d5 */
/* @0x117c18 vmrs APSR_nzcv, fpscr */
/* @0x117c1c vldrls d7, [pc, #132] */
/* @0x117c20 vldrhi d6, [pc, #128] */
/* @0x117c24 vmul.f64 d5, d7, d6 */
/* @0x117c28 vmov r0, r1, d5 */
/* @0x117c2c bl 0x3194a0 <__fixdfdi> */
/* @0x117c30 mov r3, r1 */
/* @0x117c34 ldr r1, [pc, #0x74] */
/* @0x117c38 mov r2, r0 */
/* @0x117c3c strd r2, r3, [sp] */
/* @0x117c40 add r1, pc, r1 */
/* @0x117c44 mov r0, sp */
/* @0x117c48 ldrb r3, [r1] */
/* @0x117c4c cmp r3, #0 */
/* @0x117c50 bne 0x117c8c <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x117c54 bl 0xb6820 <gmtime64@plt> */
/* @0x117c58 cmp r0, #0 */
/* @0x117c5c beq 0x117c84 <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x117c60 ldr r0, [r0, #0x14] */
/* @0x117c64 add r0, r0, #1888 */
/* @0x117c68 add r0, r0, #12 */
/* @0x117c6c bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117c70 cmp r0, #0 */
/* @0x117c74 movne r3, #57344 */
/* @0x117c78 movne r2, #0 */
/* @0x117c7c movtne r3, #0x4076 */
/* @0x117c80 stmne r4, {r2, r3} */
/* @0x117c84 add sp, sp, #8 */
/* @0x117c88 pop {r4, pc} */
/* @0x117c8c bl 0xb682c <localtime64@plt> */
/* @0x117c90 b 0x117c58 <_Z16F_DateDaysInYearR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x117c94 nop */
/* @0x117c98 andeq r0, r0, r0 */
/* @0x117c9c sbcsmi pc, r8, r0, asr #16 */
/* @0x117ca0 bl 0x82895c <b2_toiTime+0xcf4b8> */
/* @0x117ca4 svclo #0x1a36e2 */
/* @0x117ca8 andeq r0, r0, r0 */
/* @0x117cac rscsmi r1, r5, r0, lsl #16 */
/* @0x117cb0 .word 0x002da4f8 */

/* ── FUNC 0x117cb4 · anon_117cb4 · size=0 · insn=1 */
/* @0x117cb4 nop */

/* ── FUNC 0x117cb8 · F_DateLeapYear(RValue&, CInstance*, CInstance*, int, RValue*) · size=220 · insn=55 */
/* @0x117cb8 push {r4, lr} */
/* @0x117cbc sub sp, sp, #8 */
/* @0x117cc0 mov r3, #0 */
/* @0x117cc4 mov r4, r0 */
/* @0x117cc8 str r3, [r0, #0xc] */
/* @0x117ccc mov r1, r3 */
/* @0x117cd0 str r3, [r0] */
/* @0x117cd4 str r3, [r0, #0x4] */
/* @0x117cd8 ldr r0, [sp, #0x10] */
/* @0x117cdc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x117ce0 vldr d7, [pc, #144] */
/* @0x117ce4 vldr d5, [pc, #148] */
/* @0x117ce8 vmov d6, r0, r1 */
/* @0x117cec vsub.f64 d7, d6, d7 */
/* @0x117cf0 vabs.f64 d4, d7 */
/* @0x117cf4 vcmpe.f64 d4, d5 */
/* @0x117cf8 vmrs APSR_nzcv, fpscr */
/* @0x117cfc vldrls d7, [pc, #132] */
/* @0x117d00 vldrhi d6, [pc, #128] */
/* @0x117d04 vmul.f64 d5, d7, d6 */
/* @0x117d08 vmov r0, r1, d5 */
/* @0x117d0c bl 0x3194a0 <__fixdfdi> */
/* @0x117d10 mov r3, r1 */
/* @0x117d14 ldr r1, [pc, #0x74] */
/* @0x117d18 mov r2, r0 */
/* @0x117d1c strd r2, r3, [sp] */
/* @0x117d20 add r1, pc, r1 */
/* @0x117d24 mov r0, sp */
/* @0x117d28 ldrb r3, [r1] */
/* @0x117d2c cmp r3, #0 */
/* @0x117d30 bne 0x117d6c <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x117d34 bl 0xb6820 <gmtime64@plt> */
/* @0x117d38 cmp r0, #0 */
/* @0x117d3c beq 0x117d64 <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x117d40 ldr r0, [r0, #0x14] */
/* @0x117d44 add r0, r0, #1888 */
/* @0x117d48 add r0, r0, #12 */
/* @0x117d4c bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117d50 cmp r0, #0 */
/* @0x117d54 movne r3, #0 */
/* @0x117d58 movne r2, r3 */
/* @0x117d5c movtne r3, #0x3ff0 */
/* @0x117d60 stmne r4, {r2, r3} */
/* @0x117d64 add sp, sp, #8 */
/* @0x117d68 pop {r4, pc} */
/* @0x117d6c bl 0xb682c <localtime64@plt> */
/* @0x117d70 b 0x117d38 <_Z14F_DateLeapYearR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x117d74 nop */
/* @0x117d78 andeq r0, r0, r0 */
/* @0x117d7c sbcsmi pc, r8, r0, asr #16 */
/* @0x117d80 bl 0x828a3c <b2_toiTime+0xcf598> */
/* @0x117d84 svclo #0x1a36e2 */
/* @0x117d88 andeq r0, r0, r0 */
/* @0x117d8c rscsmi r1, r5, r0, lsl #16 */
/* @0x117d90 eoreq r10, sp, r8, lsl r4 */

/* ── FUNC 0x117d94 · anon_117d94 · size=0 · insn=1 */
/* @0x117d94 nop */

/* ── FUNC 0x117d98 · _yytimegm(tm*) · size=340 · insn=85 */
/* @0x117d98 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x117d9c mov r7, r0 */
/* @0x117da0 ldr r4, [pc, #0x140] */
/* @0x117da4 sub sp, sp, #48 */
/* @0x117da8 ldr r3, [r0, #0x14] */
/* @0x117dac mov r5, #0 */
/* @0x117db0 add r4, pc, r4 */
/* @0x117db4 mov r12, sp */
/* @0x117db8 add r4, r4, #52 */
/* @0x117dbc cmp r3, #70 */
/* @0x117dc0 ldm r4!, {r0, r1, r2, r3} */
/* @0x117dc4 stm r12!, {r0, r1, r2, r3} */
/* @0x117dc8 ldm r4!, {r0, r1, r2, r3} */
/* @0x117dcc stm r12!, {r0, r1, r2, r3} */
/* @0x117dd0 ldm r4, {r0, r1, r2, r3} */
/* @0x117dd4 mov r4, #0 */
/* @0x117dd8 stm r12, {r0, r1, r2, r3} */
/* @0x117ddc ble 0x117e1c <_Z9_yytimegmP2tm+0x84> */
/* @0x117de0 mov r6, #70 */
/* @0x117de4 add r0, r6, #1888 */
/* @0x117de8 add r6, r6, #1 */
/* @0x117dec add r0, r0, #12 */
/* @0x117df0 bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117df4 mov r3, #0 */
/* @0x117df8 movw r2, #0x16e */
/* @0x117dfc cmp r0, #0 */
/* @0x117e00 moveq r3, #0 */
/* @0x117e04 movweq r2, #0x16d */
/* @0x117e08 adds r4, r4, r2 */
/* @0x117e0c adc r5, r5, r3 */
/* @0x117e10 ldr r3, [r7, #0x14] */
/* @0x117e14 cmp r3, r6 */
/* @0x117e18 bgt 0x117de4 <_Z9_yytimegmP2tm+0x4c> */
/* @0x117e1c ldr r2, [r7, #0x10] */
/* @0x117e20 cmp r2, #0 */
/* @0x117e24 ble 0x117e7c <_Z9_yytimegmP2tm+0xe4> */
/* @0x117e28 sub r8, sp, #4 */
/* @0x117e2c mov r6, #0 */
/* @0x117e30 b 0x117e40 <_Z9_yytimegmP2tm+0xa8> */
/* @0x117e34 add r6, r6, #1 */
/* @0x117e38 cmp r2, r6 */
/* @0x117e3c ble 0x117e7c <_Z9_yytimegmP2tm+0xe4> */
/* @0x117e40 ldr r3, [r8, #0x4]! */
/* @0x117e44 adds r4, r4, r3 */
/* @0x117e48 adc r5, r5, r3, asr #31 */
/* @0x117e4c cmp r6, #1 */
/* @0x117e50 bne 0x117e34 <_Z9_yytimegmP2tm+0x9c> */
/* @0x117e54 ldr r0, [r7, #0x14] */
/* @0x117e58 add r0, r0, #1888 */
/* @0x117e5c add r0, r0, #12 */
/* @0x117e60 bl 0x117a5c <_Z12is_leap_yeari> */
/* @0x117e64 cmp r0, #0 */
/* @0x117e68 bne 0x117ed8 <_Z9_yytimegmP2tm+0x140> */
/* @0x117e6c ldr r2, [r7, #0x10] */
/* @0x117e70 add r6, r6, #1 */
/* @0x117e74 cmp r2, r6 */
/* @0x117e78 bgt 0x117e40 <_Z9_yytimegmP2tm+0xa8> */
/* @0x117e7c ldr r3, [r7, #0xc] */
/* @0x117e80 mov r1, #24 */
/* @0x117e84 ldr r10, [r7, #0x8] */
/* @0x117e88 mov r12, #60 */
/* @0x117e8c sub r3, r3, #1 */
/* @0x117e90 ldr r6, [r7, #0x4] */
/* @0x117e94 adds r8, r4, r3 */
/* @0x117e98 adc r9, r5, r3, asr #31 */
/* @0x117e9c ldr r5, [r7] */
/* @0x117ea0 umull r2, r3, r8, r1 */
/* @0x117ea4 adds r0, r2, r10 */
/* @0x117ea8 mla r3, r1, r9, r3 */
/* @0x117eac adc r1, r3, r10, asr #31 */
/* @0x117eb0 umull r2, r3, r0, r12 */
/* @0x117eb4 adds r2, r2, r6 */
/* @0x117eb8 mla r3, r12, r1, r3 */
/* @0x117ebc umull r0, r1, r2, r12 */
/* @0x117ec0 adc r3, r3, r6, asr #31 */
/* @0x117ec4 adds r0, r0, r5 */
/* @0x117ec8 mla r1, r12, r3, r1 */
/* @0x117ecc adc r1, r1, r5, asr #31 */
/* @0x117ed0 add sp, sp, #48 */
/* @0x117ed4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x117ed8 adds r4, r4, #1 */
/* @0x117edc ldr r2, [r7, #0x10] */
/* @0x117ee0 adc r5, r5, #0 */
/* @0x117ee4 b 0x117e34 <_Z9_yytimegmP2tm+0x9c> */
/* @0x117ee8 mlaeq r4, r0, r11, r4 */
