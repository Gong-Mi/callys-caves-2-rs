/* libyoyo.so 覆盖卡组 0297
 * 函数 0x318dec..0x319458，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x318dec · __aeabi_idivmod · size=32 · insn=8 */
/* @0x318dec cmp r1, #0 */
/* @0x318df0 beq 0x318ddc <__divsi3+0xcc> */
/* @0x318df4 push {r0, r1, lr} */
/* @0x318df8 bl 0x318d18 <__divsi3+0x8> */
/* @0x318dfc pop {r1, r2, lr} */
/* @0x318e00 mul r3, r2, r0 */
/* @0x318e04 sub r1, r1, r3 */
/* @0x318e08 bx lr */

/* ── FUNC 0x318e0c · anon_318e0c · size=8 · insn=2 */
/* @0x318e0c eor r1, r1, #-2147483648 */
/* @0x318e10 b 0x318e18 <__aeabi_dadd> */

/* ── FUNC 0x318e14 · __aeabi_dsub · size=688 · insn=1 */
/* @0x318e14 eor r3, r3, #-2147483648 */

/* ── FUNC 0x318e14 · __subdf3 · alias of the symbol above · insn=0 */

/* ── FUNC 0x318e18 · __adddf3 · size=684 · insn=171 */
/* @0x318e18 push {r4, r5, lr} */
/* @0x318e1c lsl r4, r1, #1 */
/* @0x318e20 lsl r5, r3, #1 */
/* @0x318e24 teq r4, r5 */
/* @0x318e28 teqeq r0, r2 */
/* @0x318e2c orrsne r12, r4, r0 */
/* @0x318e30 orrsne r12, r5, r2 */
/* @0x318e34 mvnsne r12, r4, asr #21 */
/* @0x318e38 mvnsne r12, r5, asr #21 */
/* @0x318e3c beq 0x319028 <__aeabi_dadd+0x210> */
/* @0x318e40 lsr r4, r4, #21 */
/* @0x318e44 rsbs r5, r4, r5, lsr #21 */
/* @0x318e48 rsblt r5, r5, #0 */
/* @0x318e4c ble 0x318e6c <__aeabi_dadd+0x54> */
/* @0x318e50 add r4, r4, r5 */
/* @0x318e54 eor r2, r0, r2 */
/* @0x318e58 eor r3, r1, r3 */
/* @0x318e5c eor r0, r2, r0 */
/* @0x318e60 eor r1, r3, r1 */
/* @0x318e64 eor r2, r0, r2 */
/* @0x318e68 eor r3, r1, r3 */
/* @0x318e6c cmp r5, #54 */
/* @0x318e70 pophi {r4, r5, pc} */
/* @0x318e74 tst r1, #-2147483648 */
/* @0x318e78 lsl r1, r1, #12 */
/* @0x318e7c mov r12, #1048576 */
/* @0x318e80 orr r1, r12, r1, lsr #12 */
/* @0x318e84 beq 0x318e90 <__aeabi_dadd+0x78> */
/* @0x318e88 rsbs r0, r0, #0 */
/* @0x318e8c rsc r1, r1, #0 */
/* @0x318e90 tst r3, #-2147483648 */
/* @0x318e94 lsl r3, r3, #12 */
/* @0x318e98 orr r3, r12, r3, lsr #12 */
/* @0x318e9c beq 0x318ea8 <__aeabi_dadd+0x90> */
/* @0x318ea0 rsbs r2, r2, #0 */
/* @0x318ea4 rsc r3, r3, #0 */
/* @0x318ea8 teq r4, r5 */
/* @0x318eac beq 0x319010 <__aeabi_dadd+0x1f8> */
/* @0x318eb0 sub r4, r4, #1 */
/* @0x318eb4 rsbs lr, r5, #32 */
/* @0x318eb8 blt 0x318ed4 <__aeabi_dadd+0xbc> */
/* @0x318ebc lsl r12, r2, lr */
/* @0x318ec0 adds r0, r0, r2, lsr r5 */
/* @0x318ec4 adc r1, r1, #0 */
/* @0x318ec8 adds r0, r0, r3, lsl lr */
/* @0x318ecc adcs r1, r1, r3, asr r5 */
/* @0x318ed0 b 0x318ef0 <__aeabi_dadd+0xd8> */
/* @0x318ed4 sub r5, r5, #32 */
/* @0x318ed8 add lr, lr, #32 */
/* @0x318edc cmp r2, #1 */
/* @0x318ee0 lsl r12, r3, lr */
/* @0x318ee4 orrhs r12, r12, #2 */
/* @0x318ee8 adds r0, r0, r3, asr r5 */
/* @0x318eec adcs r1, r1, r3, asr #31 */
/* @0x318ef0 and r5, r1, #-2147483648 */
/* @0x318ef4 bpl 0x318f04 <__aeabi_dadd+0xec> */
/* @0x318ef8 rsbs r12, r12, #0 */
/* @0x318efc rscs r0, r0, #0 */
/* @0x318f00 rsc r1, r1, #0 */
/* @0x318f04 cmp r1, #1048576 */
/* @0x318f08 blo 0x318f48 <__aeabi_dadd+0x130> */
/* @0x318f0c cmp r1, #2097152 */
/* @0x318f10 blo 0x318f30 <__aeabi_dadd+0x118> */
/* @0x318f14 lsrs r1, r1, #1 */
/* @0x318f18 rrxs r0, r0 */
/* @0x318f1c rrx r12, r12 */
/* @0x318f20 add r4, r4, #1 */
/* @0x318f24 lsl r2, r4, #21 */
/* @0x318f28 cmn r2, #4194304 */
/* @0x318f2c bhs 0x319088 <__aeabi_dadd+0x270> */
/* @0x318f30 cmp r12, #-2147483648 */
/* @0x318f34 lsrseq r12, r0, #1 */
/* @0x318f38 adcs r0, r0, #0 */
/* @0x318f3c adc r1, r1, r4, lsl #20 */
/* @0x318f40 orr r1, r1, r5 */
/* @0x318f44 pop {r4, r5, pc} */
/* @0x318f48 lsls r12, r12, #1 */
/* @0x318f4c adcs r0, r0, r0 */
/* @0x318f50 adc r1, r1, r1 */
/* @0x318f54 tst r1, #1048576 */
/* @0x318f58 sub r4, r4, #1 */
/* @0x318f5c bne 0x318f30 <__aeabi_dadd+0x118> */
/* @0x318f60 teq r1, #0 */
/* @0x318f64 moveq r1, r0 */
/* @0x318f68 moveq r0, #0 */
/* @0x318f6c clz r3, r1 */
/* @0x318f70 addeq r3, r3, #32 */
/* @0x318f74 sub r3, r3, #11 */
/* @0x318f78 subs r2, r3, #32 */
/* @0x318f7c bge 0x318fa0 <__aeabi_dadd+0x188> */
/* @0x318f80 adds r2, r2, #12 */
/* @0x318f84 ble 0x318f9c <__aeabi_dadd+0x184> */
/* @0x318f88 add r12, r2, #20 */
/* @0x318f8c rsb r2, r2, #12 */
/* @0x318f90 lsl r0, r1, r12 */
/* @0x318f94 lsr r1, r1, r2 */
/* @0x318f98 b 0x318fb0 <__aeabi_dadd+0x198> */
/* @0x318f9c add r2, r2, #20 */
/* @0x318fa0 rsble r12, r2, #32 */
/* @0x318fa4 lsl r1, r1, r2 */
/* @0x318fa8 orrle r1, r1, r0, lsr r12 */
/* @0x318fac lslle r0, r0, r2 */
/* @0x318fb0 subs r4, r4, r3 */
/* @0x318fb4 addge r1, r1, r4, lsl #20 */
/* @0x318fb8 orrge r1, r1, r5 */
/* @0x318fbc popge {r4, r5, pc} */
/* @0x318fc0 mvn r4, r4 */
/* @0x318fc4 subs r4, r4, #31 */
/* @0x318fc8 bge 0x319004 <__aeabi_dadd+0x1ec> */
/* @0x318fcc adds r4, r4, #12 */
/* @0x318fd0 bgt 0x318fec <__aeabi_dadd+0x1d4> */
/* @0x318fd4 add r4, r4, #20 */
/* @0x318fd8 rsb r2, r4, #32 */
/* @0x318fdc lsr r0, r0, r4 */
/* @0x318fe0 orr r0, r0, r1, lsl r2 */
/* @0x318fe4 orr r1, r5, r1, lsr r4 */
/* @0x318fe8 pop {r4, r5, pc} */
/* @0x318fec rsb r4, r4, #12 */
/* @0x318ff0 rsb r2, r4, #32 */
/* @0x318ff4 lsr r0, r0, r2 */
/* @0x318ff8 orr r0, r0, r1, lsl r4 */
/* @0x318ffc mov r1, r5 */
/* @0x319000 pop {r4, r5, pc} */
/* @0x319004 lsr r0, r1, r4 */
/* @0x319008 mov r1, r5 */
/* @0x31900c pop {r4, r5, pc} */
/* @0x319010 teq r4, #0 */
/* @0x319014 eor r3, r3, #1048576 */
/* @0x319018 eoreq r1, r1, #1048576 */
/* @0x31901c addeq r4, r4, #1 */
/* @0x319020 subne r5, r5, #1 */
/* @0x319024 b 0x318eb0 <__aeabi_dadd+0x98> */
/* @0x319028 mvns r12, r4, asr #21 */
/* @0x31902c mvnsne r12, r5, asr #21 */
/* @0x319030 beq 0x319098 <__aeabi_dadd+0x280> */
/* @0x319034 teq r4, r5 */
/* @0x319038 teqeq r0, r2 */
/* @0x31903c beq 0x319050 <__aeabi_dadd+0x238> */
/* @0x319040 orrs r12, r4, r0 */
/* @0x319044 moveq r1, r3 */
/* @0x319048 moveq r0, r2 */
/* @0x31904c pop {r4, r5, pc} */
/* @0x319050 teq r1, r3 */
/* @0x319054 movne r1, #0 */
/* @0x319058 movne r0, #0 */
/* @0x31905c popne {r4, r5, pc} */
/* @0x319060 lsrs r12, r4, #21 */
/* @0x319064 bne 0x319078 <__aeabi_dadd+0x260> */
/* @0x319068 lsls r0, r0, #1 */
/* @0x31906c adcs r1, r1, r1 */
/* @0x319070 orrhs r1, r1, #-2147483648 */
/* @0x319074 pop {r4, r5, pc} */
/* @0x319078 adds r4, r4, #4194304 */
/* @0x31907c addlo r1, r1, #1048576 */
/* @0x319080 poplo {r4, r5, pc} */
/* @0x319084 and r5, r1, #-2147483648 */
/* @0x319088 orr r1, r5, #2130706432 */
/* @0x31908c orr r1, r1, #15728640 */
/* @0x319090 mov r0, #0 */
/* @0x319094 pop {r4, r5, pc} */
/* @0x319098 mvns r12, r4, asr #21 */
/* @0x31909c movne r1, r3 */
/* @0x3190a0 movne r0, r2 */
/* @0x3190a4 mvnseq r12, r5, asr #21 */
/* @0x3190a8 movne r3, r1 */
/* @0x3190ac movne r2, r0 */
/* @0x3190b0 orrs r4, r0, r1, lsl #12 */
/* @0x3190b4 orrseq r5, r2, r3, lsl #12 */
/* @0x3190b8 teqeq r1, r3 */
/* @0x3190bc orrne r1, r1, #524288 */
/* @0x3190c0 pop {r4, r5, pc} */

/* ── FUNC 0x318e18 · __aeabi_dadd · alias of the symbol above · insn=0 */

/* ── FUNC 0x3190c4 · __aeabi_ui2d · size=36 · insn=9 */
/* @0x3190c4 teq r0, #0 */
/* @0x3190c8 moveq r1, #0 */
/* @0x3190cc bxeq lr */
/* @0x3190d0 push {r4, r5, lr} */
/* @0x3190d4 mov r4, #1024 */
/* @0x3190d8 add r4, r4, #50 */
/* @0x3190dc mov r5, #0 */
/* @0x3190e0 mov r1, #0 */
/* @0x3190e4 b 0x318f60 <__aeabi_dadd+0x148> */

/* ── FUNC 0x3190c4 · __floatunsidf · alias of the symbol above · insn=0 */

/* ── FUNC 0x3190e8 · __aeabi_i2d · size=40 · insn=10 */
/* @0x3190e8 teq r0, #0 */
/* @0x3190ec moveq r1, #0 */
/* @0x3190f0 bxeq lr */
/* @0x3190f4 push {r4, r5, lr} */
/* @0x3190f8 mov r4, #1024 */
/* @0x3190fc add r4, r4, #50 */
/* @0x319100 ands r5, r0, #-2147483648 */
/* @0x319104 rsbmi r0, r0, #0 */
/* @0x319108 mov r1, #0 */
/* @0x31910c b 0x318f60 <__aeabi_dadd+0x148> */

/* ── FUNC 0x3190e8 · __floatsidf · alias of the symbol above · insn=0 */

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

/* ── FUNC 0x319414 · anon_319414 · size=68 · insn=17 */
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
