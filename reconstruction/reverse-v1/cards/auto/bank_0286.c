/* libyoyo.so 覆盖卡组 0286
 * 函数 0x2e4e4c..0x2e58ac，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e4e4c · FT_MulFix · size=28 · insn=11 */
/* @0x2e4e4c smull r3, r2, r1, r0 */
/* @0x2e4e50 asr.w r0, r2, #0x1f */
/* @0x2e4e54 add.w r0, r0, #0x8000 */
/* @0x2e4e58 adds r3, r3, r0 */
/* @0x2e4e5a adc r2, r2, #0x0 */
/* @0x2e4e5c b 0x16a5664 <b2_toiTime+0xf4c1c0> */
/* @0x2e4e5e lsr.w r0, r3, #0x10 */
/* @0x2e4e60 b 0x12f4eb4 <b2_toiTime+0xb9ba10> */
/* @0x2e4e62 orr.w r0, r0, r2, lsl #16 */
/* @0x2e4e64 ldrbmi r4, [r0, -r2]! */
/* @0x2e4e66 bx lr */

/* ── FUNC 0x2e4e68 · anon_2e4e68 · size=76 · insn=20 */
/* @0x2e4e68 .word 0x460cb538 */
/* @0x2e4e6c stmvs r9, {r0, r2, r9, r10, lr} */
/* @0x2e4e70 strheq pc, [r6], #-144 */
/* @0x2e4e74 .word 0xffeaf7ff */
/* @0x2e4e78 eorslo r6, pc, r1, lsr #17 */
/* @0x2e4e7c eorseq pc, pc, r0, lsr #32 */
/* @0x2e4e80 rfeib r5! */
/* @0x2e4e84 .word 0xf7ff0048 */
/* @0x2e4e88 stmvs r1!, {r0, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e4e8c eorseq pc, pc, r0, lsr #32 */
/* @0x2e4e90 rfeib r5! */
/* @0x2e4e94 .word 0xf7ff004a */
/* @0x2e4e98 stmdavs r1!, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e4e9c .word 0xf0203020 */
/* @0x2e4ea0 .word 0x6160003f */
/* @0x2e4ea4 strheq pc, [r12], #-149 */
/* @0x2e4ea8 .word 0xffd0f7ff */
/* @0x2e4eac .word 0xf0203020 */
/* @0x2e4eb0 lsrvs r0, pc, r0 */
/* @0x2e4eb4 mcrne p13, #0x0, r11, c3, c8, #0x1 */

/* ── FUNC 0x2e4eb6 · FT_DivFix · size=88 · insn=42 */
/* @0x2e4eb6 subs r3, r0, #0x0 */
/* @0x2e4eb8 mov r2, r1 */
/* @0x2e4eba push {r4, lr} */
/* @0x2e4ebc itte lt */
/* @0x2e4ebe rsblt r3, r3, #0 */
/* @0x2e4ec0 movlt.w r4, #0xffffffff */
/* @0x2e4ec2 strhs r3, [r1], #-1279 */
/* @0x2e4ec4 movge r4, #0x1 */
/* @0x2e4ec6 cmp r1, #0x0 */
/* @0x2e4ec8 itt lt */
/* @0x2e4eca rsblt r2, r1, #0 */
/* @0x2e4ecc rsblt r4, r4, #0 */
/* @0x2e4ece cbz r2, 0x2e4f02 <FT_DivFix+0x4c> */
/* @0x2e4ed0 lsrs r1, r2, #0x11 */
/* @0x2e4ed2 lsls r0, r3, #0x10 */
/* @0x2e4ed4 rsb.w r1, r1, #0xff00 */
/* @0x2e4ed6 mvnslo r4, pc, ror r1 */
/* @0x2e4ed8 adds r1, #0xff */
/* @0x2e4eda cmp r1, r3 */
/* @0x2e4edc lsr.w r1, r2, #0x1 */
/* @0x2e4ede movwle r0, #0x4152 */
/* @0x2e4ee0 blo 0x2e4eec <FT_DivFix+0x36> */
/* @0x2e4ee2 add r0, r1 */
/* @0x2e4ee4 mov r1, r2 */
/* @0x2e4ee6 blx 0x318c48 <__udivsi3> */
/* @0x2e4eea b 0x2e4f06 <FT_DivFix+0x50> */
/* @0x2e4eec adds r1, r1, r0 */
/* @0x2e4eee ite lo */
/* @0x2e4ef0 movlo r0, #0x0 */
/* @0x2e4ef2 movhs r0, #0x1 */
/* @0x2e4ef4 add.w r0, r0, r3, lsr #16 */
/* @0x2e4ef6 addsmi r4, r0, #19 */
/* @0x2e4ef8 cmp r0, r2 */
/* @0x2e4efa bhs 0x2e4f02 <FT_DivFix+0x4c> */
/* @0x2e4efc bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a> */
/* @0x2e4efe mul r1, pc, lr */
/* @0x2e4f00 b 0x2e4f06 <FT_DivFix+0x50> */
/* @0x2e4f02 mvn r0, #0x80000000 */
/* @0x2e4f06 adds r4, #0x1 */
/* @0x2e4f08 it eq */
/* @0x2e4f0a rsbeq r0, r0, #0 */
/* @0x2e4f0c pop {r4, pc} */

/* ── FUNC 0x2e4f0e · FT_Matrix_Multiply · size=110 · insn=50 */
/* @0x2e4f0e push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e4f12 mov r4, r1 */
/* @0x2e4f14 mov r5, r0 */
/* @0x2e4f16 cmp r0, #0x0 */
/* @0x2e4f18 beq 0x2e4f78 <FT_Matrix_Multiply+0x6a> */
/* @0x2e4f1a cmp r1, #0x0 */
/* @0x2e4f1c beq 0x2e4f78 <FT_Matrix_Multiply+0x6a> */
/* @0x2e4f1e ldr r1, [r1] */
/* @0x2e4f20 ldr r0, [r0] */
/* @0x2e4f22 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f26 ldr r1, [r4, #0x8] */
/* @0x2e4f28 mov r8, r0 */
/* @0x2e4f2a ldr r0, [r5, #0x4] */
/* @0x2e4f2c bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f2e stmdavs r1!, {r1, r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e4f30 ldr r1, [r4, #0x4] */
/* @0x2e4f32 add r8, r0 */
/* @0x2e4f34 ldr r0, [r5] */
/* @0x2e4f36 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f3a ldr r1, [r4, #0xc] */
/* @0x2e4f3c mov r7, r0 */
/* @0x2e4f3e ldr r0, [r5, #0x4] */
/* @0x2e4f40 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f42 stmdavs r1!, {r2, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e4f44 ldr r1, [r4] */
/* @0x2e4f46 add r7, r0 */
/* @0x2e4f48 ldr r0, [r5, #0x8] */
/* @0x2e4f4a bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f4e ldr r1, [r4, #0x8] */
/* @0x2e4f50 mov r6, r0 */
/* @0x2e4f52 ldr r0, [r5, #0xc] */
/* @0x2e4f54 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f56 stmdavs r1!, {r1, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e4f58 ldr r1, [r4, #0x4] */
/* @0x2e4f5a add r6, r0 */
/* @0x2e4f5c ldr r0, [r5, #0x8] */
/* @0x2e4f5e bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f62 ldr r1, [r4, #0xc] */
/* @0x2e4f64 mov r9, r0 */
/* @0x2e4f66 ldr r0, [r5, #0xc] */
/* @0x2e4f68 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f6a .word 0xf8c4ff70 */
/* @0x2e4f6c str.w r8, [r4] */
/* @0x2e4f6e rsbvs r8, r7, r0 */
/* @0x2e4f70 str r7, [r4, #0x4] */
/* @0x2e4f72 str r6, [r4, #0x8] */
/* @0x2e4f74 add r0, r9 */
/* @0x2e4f76 str r0, [r4, #0xc] */
/* @0x2e4f78 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e4f7a ldrblt r8, [r0, #-0x3f8]! */

/* ── FUNC 0x2e4f7c · FT_Matrix_Invert · size=82 · insn=37 */
/* @0x2e4f7c push {r4, r5, r6, lr} */
/* @0x2e4f7e mov r4, r0 */
/* @0x2e4f80 cbnz r0, 0x2e4f86 <FT_Matrix_Invert+0xa> */
/* @0x2e4f82 movs r0, #0x6 */
/* @0x2e4f84 pop {r4, r5, r6, pc} */
/* @0x2e4f86 ldr r1, [r4, #0xc] */
/* @0x2e4f88 ldr r0, [r0] */
/* @0x2e4f8a bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f8c stmvs r1!, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e4f8e ldr r1, [r4, #0x8] */
/* @0x2e4f90 mov r5, r0 */
/* @0x2e4f92 ldr r0, [r4, #0x4] */
/* @0x2e4f94 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e4f98 subs r5, r5, r0 */
/* @0x2e4f9a beq 0x2e4f82 <FT_Matrix_Invert+0x6> */
/* @0x2e4f9c mov r1, r5 */
/* @0x2e4f9e ldr r0, [r4, #0x4] */
/* @0x2e4fa0 bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e4fa4 mov r1, r5 */
/* @0x2e4fa6 rsbs r0, r0, #0 */
/* @0x2e4fa8 str r0, [r4, #0x4] */
/* @0x2e4faa ldr r0, [r4, #0x8] */
/* @0x2e4fac bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e4fb0 mov r1, r5 */
/* @0x2e4fb2 ldr r6, [r4] */
/* @0x2e4fb4 rsbs r0, r0, #0 */
/* @0x2e4fb6 str r0, [r4, #0x8] */
/* @0x2e4fb8 ldr r0, [r4, #0xc] */
/* @0x2e4fba bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e4fbc qsub16mi pc, r9, r12 */
/* @0x2e4fbe mov r1, r5 */
/* @0x2e4fc0 str r0, [r4] */
/* @0x2e4fc2 mov r0, r6 */
/* @0x2e4fc4 bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e4fc8 str r0, [r4, #0xc] */
/* @0x2e4fca movs r0, #0x0 */
/* @0x2e4fcc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e4fce · FT_Matrix_Multiply_Scaled · size=130 · insn=54 */
/* @0x2e4fce push.w {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2e4fd2 mov r4, r1 */
/* @0x2e4fd4 mov r5, r0 */
/* @0x2e4fd6 cmp r0, #0x0 */
/* @0x2e4fd8 beq 0x2e504c <FT_Matrix_Multiply_Scaled+0x7e> */
/* @0x2e4fda cmp r1, #0x0 */
/* @0x2e4fdc beq 0x2e504c <FT_Matrix_Multiply_Scaled+0x7e> */
/* @0x2e4fde lsls r6, r2, #0x10 */
/* @0x2e4fe0 ldr r1, [r1] */
/* @0x2e4fe2 ldr r0, [r0] */
/* @0x2e4fe4 mov r2, r6 */
/* @0x2e4fe6 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e4fea ldr r1, [r4, #0x8] */
/* @0x2e4fec mov r2, r6 */
/* @0x2e4fee mov r9, r0 */
/* @0x2e4ff0 ldr r0, [r5, #0x4] */
/* @0x2e4ff2 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e4ff6 ldr r1, [r4, #0x4] */
/* @0x2e4ff8 mov r2, r6 */
/* @0x2e4ffa add r9, r0 */
/* @0x2e4ffc ldr r0, [r5] */
/* @0x2e4ffe bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5002 ldr r1, [r4, #0xc] */
/* @0x2e5004 mov r2, r6 */
/* @0x2e5006 mov r8, r0 */
/* @0x2e5008 ldr r0, [r5, #0x4] */
/* @0x2e500a bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e500e ldr r1, [r4] */
/* @0x2e5010 mov r2, r6 */
/* @0x2e5012 add r8, r0 */
/* @0x2e5014 ldr r0, [r5, #0x8] */
/* @0x2e5016 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e501a ldr r1, [r4, #0x8] */
/* @0x2e501c mov r2, r6 */
/* @0x2e501e mov r7, r0 */
/* @0x2e5020 ldr r0, [r5, #0xc] */
/* @0x2e5022 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5026 ldr r1, [r4, #0x4] */
/* @0x2e5028 mov r2, r6 */
/* @0x2e502a add r7, r0 */
/* @0x2e502c ldr r0, [r5, #0x8] */
/* @0x2e502e bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5032 ldr r1, [r4, #0xc] */
/* @0x2e5034 mov r2, r6 */
/* @0x2e5036 mov r10, r0 */
/* @0x2e5038 ldr r0, [r5, #0xc] */
/* @0x2e503a bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e503e str.w r9, [r4] */
/* @0x2e5042 str.w r8, [r4, #0x4] */
/* @0x2e5046 str r7, [r4, #0x8] */
/* @0x2e5048 add r0, r10 */
/* @0x2e504a str r0, [r4, #0xc] */
/* @0x2e504c pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2e504e push {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2e5050 · FT_Vector_Transform_Scaled · size=70 · insn=30 */
/* @0x2e5050 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e5054 mov r5, r1 */
/* @0x2e5056 mov r4, r0 */
/* @0x2e5058 cbz r0, 0x2e5092 <FT_Vector_Transform_Scaled+0x42> */
/* @0x2e505a cbz r1, 0x2e5092 <FT_Vector_Transform_Scaled+0x42> */
/* @0x2e505c lsls r6, r2, #0x10 */
/* @0x2e505e ldr r1, [r1] */
/* @0x2e5060 ldr r0, [r0] */
/* @0x2e5062 mov r2, r6 */
/* @0x2e5064 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5068 ldr r1, [r5, #0x4] */
/* @0x2e506a mov r2, r6 */
/* @0x2e506c mov r7, r0 */
/* @0x2e506e ldr r0, [r4, #0x4] */
/* @0x2e5070 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5074 ldr r1, [r5, #0x8] */
/* @0x2e5076 mov r2, r6 */
/* @0x2e5078 add r7, r0 */
/* @0x2e507a ldr r0, [r4] */
/* @0x2e507c bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5080 ldr r1, [r5, #0xc] */
/* @0x2e5082 mov r2, r6 */
/* @0x2e5084 mov r8, r0 */
/* @0x2e5086 ldr r0, [r4, #0x4] */
/* @0x2e5088 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e508c str r7, [r4] */
/* @0x2e508e add r0, r8 */
/* @0x2e5090 str r0, [r4, #0x4] */
/* @0x2e5092 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e5094 push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e5096 · FT_Vector_NormLen · size=300 · insn=116 */
/* @0x2e5096 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e509a ldm.w r0, {r2, r3} */
/* @0x2e509e cmp r2, #0x0 */
/* @0x2e50a0 itte lt */
/* @0x2e50a2 rsblt r2, r2, #0 */
/* @0x2e50a4 movlt.w r8, #0xffffffff */
/* @0x2e50a6 .word 0xf04f38ff */
/* @0x2e50a8 movge.w r8, #0x1 */
/* @0x2e50aa blhs 0x2e70b6 <FT_Vector_Polarize+0x2a> */
/* @0x2e50ac cmp r3, #0x0 */
/* @0x2e50ae itte lt */
/* @0x2e50b0 rsblt r3, r3, #0 */
/* @0x2e50b2 movlt.w r12, #0xffffffff */
/* @0x2e50b6 movge.w r12, #0x1 */
/* @0x2e50ba cbnz r2, 0x2e50c8 <FT_Vector_NormLen+0x32> */
/* @0x2e50bc cmp r3, #0x0 */
/* @0x2e50be beq 0x2e51bc <FT_Vector_NormLen+0x126> */
/* @0x2e50c0 lsl.w r2, r12, #0x10 */
/* @0x2e50c2 subvs r4, r2, r12, lsl #4 */
/* @0x2e50c4 str r2, [r0, #0x4] */
/* @0x2e50c6 b 0x2e51bc <FT_Vector_NormLen+0x126> */
/* @0x2e50c8 cbnz r3, 0x2e50d6 <FT_Vector_NormLen+0x40> */
/* @0x2e50ca lsl.w r3, r8, #0x10 */
/* @0x2e50ce str r3, [r0] */
/* @0x2e50d0 mov r0, r2 */
/* @0x2e50d2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e50d6 cmp r2, r3 */
/* @0x2e50d8 mov.w r1, #0xaaaaaaaa */
/* @0x2e50da svclt #0x8c31aa */
/* @0x2e50dc ite hi */
/* @0x2e50de addhi.w r4, r2, r3, lsr #1 */
/* @0x2e50e2 addls.w r4, r3, r2, lsr #1 */
/* @0x2e50e6 clz r5, r4 */
/* @0x2e50ea lsrs r1, r5 */
/* @0x2e50ec cmp r4, r1 */
/* @0x2e50ee ite lo */
/* @0x2e50f0 movlo r1, #0xf */
/* @0x2e50f2 movhs r1, #0x10 */
/* @0x2e50f4 subs r1, r5, r1 */
/* @0x2e50f6 cmp r1, #0x0 */
/* @0x2e50f8 ble 0x2e510c <FT_Vector_NormLen+0x76> */
/* @0x2e50fa lsls r2, r1 */
/* @0x2e50fc lsls r3, r1 */
/* @0x2e50fe cmp r2, r3 */
/* @0x2e5100 ite hi */
/* @0x2e5102 addhi.w r6, r2, r3, lsr #1 */
/* @0x2e5106 addls.w r6, r3, r2, lsr #1 */
/* @0x2e510a b 0x2e5116 <FT_Vector_NormLen+0x80> */
/* @0x2e510c rsbs r6, r1, #0 */
/* @0x2e510e lsrs r2, r6 */
/* @0x2e5110 lsrs r3, r6 */
/* @0x2e5112 lsr.w r6, r4, r6 */
/* @0x2e5116 rsb.w r6, r6, #0x10000 */
/* @0x2e511a mul r5, r6, r2 */
/* @0x2e511e add.w r9, r6, #0x10000 */
/* @0x2e5122 mul r4, r6, r3 */
/* @0x2e5126 asr.w r9, r9, #0x8 */
/* @0x2e512a add.w r5, r2, r5, asr #16 */
/* @0x2e512e add.w r11, r3, r4, asr #16 */
/* @0x2e5132 mul r7, r5, r5 */
/* @0x2e5136 mla r7, r11, r11, r7 */
/* @0x2e513a cmp r7, #0x0 */
/* @0x2e513c it lt */
/* @0x2e513e addwlt r7, r7, #0x1ff */
/* @0x2e5142 asr.w r10, r7, #0x9 */
/* @0x2e5146 mov r7, r9 */
/* @0x2e5148 rsb.w r10, r10, #0x0 */
/* @0x2e514a ldrbmi r0, [r4], -r0, lsl #20 */
/* @0x2e514c mov r4, r10 */
/* @0x2e514e muls r4, r7, r4 */
/* @0x2e5150 it mi */
/* @0x2e5152 addmi.w r7, r4, #0xff00 */
/* @0x2e5156 mov r9, r4 */
/* @0x2e5158 it mi */
/* @0x2e515a addmi.w r9, r7, #0xff */
/* @0x2e515e asr.w r7, r9, #0x10 */
/* @0x2e5162 cmp r7, #0x0 */
/* @0x2e5164 add r6, r7 */
/* @0x2e5166 bgt 0x2e511a <FT_Vector_NormLen+0x84> */
/* @0x2e5168 muls r2, r5, r2 */
/* @0x2e516a cmp.w r8, #0xffffffff */
/* @0x2e516e mla r3, r3, r11, r2 */
/* @0x2e5172 ite eq */
/* @0x2e5174 rsbeq r6, r5, #0 */
/* @0x2e5176 movne r6, r5 */
/* @0x2e5178 cmp.w r12, #0xffffffff */
/* @0x2e517a strdvs r3, r4, [r6], -pc */
/* @0x2e517c str r6, [r0] */
/* @0x2e517e ite eq */
/* @0x2e5180 rsbeq.w r6, r11, #0x0 */
/* @0x2e5182 ldrbmi r0, [lr], -r0, lsl #12 */
/* @0x2e5184 movne r6, r11 */
/* @0x2e5186 cmp r3, #0x0 */
/* @0x2e5188 it lt */
/* @0x2e518a addlt.w r3, r3, #0xff00 */
/* @0x2e518e str r6, [r0, #0x4] */
/* @0x2e5190 it lt */
/* @0x2e5192 addlt r3, #0xff */
/* @0x2e5194 cmp r1, #0x0 */
/* @0x2e5196 asr.w r3, r3, #0x10 */
/* @0x2e519a add.w r3, r3, #0x10000 */
/* @0x2e519e ble 0x2e51b2 <FT_Vector_NormLen+0x11c> */
/* @0x2e51a0 subs r2, r1, #0x1 */
/* @0x2e51a2 movs r0, #0x1 */
/* @0x2e51a4 lsl.w r2, r0, r2 */
/* @0x2e51a6 ldrmi pc, [r3], #-514 */
/* @0x2e51a8 add r3, r2 */
/* @0x2e51aa lsr.w r0, r3, r1 */
/* @0x2e51ae pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e51b2 rsbs r1, r1, #0 */
/* @0x2e51b4 lsl.w r0, r3, r1 */
/* @0x2e51b6 pop {r0, r12, sp, lr, pc} */
/* @0x2e51b8 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e51ba ssub8mi r8, r8, r0 */
/* @0x2e51bc mov r0, r3 */
/* @0x2e51be pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2e51c2 · anon_2e51c2 · size=0 · insn=1 */
/* @0x2e51c2 ldrblt r0, [pc, #-0x0]! */

/* ── FUNC 0x2e51c4 · ft_corner_orientation · size=132 · insn=62 */
/* @0x2e51c4 push {r0, r1, r2, r3, r4, r5, r6, lr} */
/* @0x2e51c6 mov r5, r1 */
/* @0x2e51c8 mov r4, r2 */
/* @0x2e51ca eor.w r1, r0, r0, asr #31 */
/* @0x2e51cc bl 0xfeb41954 <b2_toiTime+0xfffffffffe3e84b0> */
/* @0x2e51ce sub.w r1, r1, r0, asr #31 */
/* @0x2e51d0 b 0xfe3c1958 <b2_toiTime+0xfffffffffdc684b4> */
/* @0x2e51d2 eor.w r2, r3, r3, asr #31 */
/* @0x2e51d4 bl 0xfeb81d68 <b2_toiTime+0xfffffffffe4288c4> */
/* @0x2e51d6 sub.w r2, r2, r3, asr #31 */
/* @0x2e51d8 ldrmi r7, [r1], #-739 */
/* @0x2e51da add r1, r2 */
/* @0x2e51dc ldr r2, [pc, #0x64] */
/* @0x2e51de cmp r1, r2 */
/* @0x2e51e0 bhi 0x2e520a <ft_corner_orientation+0x46> */
/* @0x2e51e2 eor.w r6, r5, r5, asr #31 */
/* @0x2e51e4 bl 0xfec82d80 <b2_toiTime+0xfffffffffe5298dc> */
/* @0x2e51e6 sub.w r6, r6, r5, asr #31 */
/* @0x2e51e8 b 0xfe402d84 <b2_toiTime+0xfffffffffdca98e0> */
/* @0x2e51ea eor.w r1, r4, r4, asr #31 */
/* @0x2e51ec bl 0xfeb41984 <b2_toiTime+0xfffffffffe3e84e0> */
/* @0x2e51ee sub.w r1, r1, r4, asr #31 */
/* @0x2e51f0 ldrtmi r7, [r1], #-484 */
/* @0x2e51f2 add r1, r6 */
/* @0x2e51f4 cmp r1, r2 */
/* @0x2e51f6 bhi 0x2e520a <ft_corner_orientation+0x46> */
/* @0x2e51f8 muls r0, r3, r0 */
/* @0x2e51fa muls r4, r5, r4 */
/* @0x2e51fc cmp r0, r4 */
/* @0x2e51fe bgt 0x2e523e <ft_corner_orientation+0x7a> */
/* @0x2e5200 ite ge */
/* @0x2e5202 movge r0, #0x0 */
/* @0x2e5204 mvnlt r0, #0x0 */
/* @0x2e5208 b 0x2e5240 <ft_corner_orientation+0x7c> */
/* @0x2e520a mov r1, r3 */
/* @0x2e520c mov r2, sp */
/* @0x2e520e bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8> */
/* @0x2e5210 bge 0x3a400c <af_blue_strings+0x1ce8> */
/* @0x2e5212 add r2, sp, #0x8 */
/* @0x2e5214 mov r0, r5 */
/* @0x2e5216 mov r1, r4 */
/* @0x2e5218 bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8> */
/* @0x2e521c ldr r3, [sp, #0xc] */
/* @0x2e521e ldr r2, [sp, #0x4] */
/* @0x2e5220 cmp r2, r3 */
/* @0x2e5222 bhi 0x2e523e <ft_corner_orientation+0x7a> */
/* @0x2e5224 blo 0x2e5238 <ft_corner_orientation+0x74> */
/* @0x2e5226 ldr r3, [sp, #0x8] */
/* @0x2e5228 ldr r2, [sp] */
/* @0x2e522a cmp r2, r3 */
/* @0x2e522c bhi 0x2e523e <ft_corner_orientation+0x7a> */
/* @0x2e522e ite hs */
/* @0x2e5230 movhs r0, #0x0 */
/* @0x2e5232 mvnlo r0, #0x0 */
/* @0x2e5234 and r0, r3, r0 */
/* @0x2e5236 b 0x2e5240 <ft_corner_orientation+0x7c> */
/* @0x2e5238 mov.w r0, #0xffffffff */
/* @0x2e523c b 0x2e5240 <ft_corner_orientation+0x7c> */
/* @0x2e523e movs r0, #0x1 */
/* @0x2e5240 add sp, #0x10 */
/* @0x2e5242 pop {r4, r5, r6, pc} */
/* @0x2e5244 .word 0xffff 0001 */

/* ── FUNC 0x2e5248 · ft_corner_is_flat · size=116 · insn=54 */
/* @0x2e5248 push {r4, r5, r6, lr} */
/* @0x2e524a adds r6, r0, r2 */
/* @0x2e524c adds r5, r1, r3 */
/* @0x2e524e cmp r0, #0x0 */
/* @0x2e5250 it lt */
/* @0x2e5252 rsblt r0, r0, #0 */
/* @0x2e5254 cmp r1, #0x0 */
/* @0x2e5256 it lt */
/* @0x2e5258 rsblt r1, r1, #0 */
/* @0x2e525a movs r4, #0x3 */
/* @0x2e525c cmp r0, r1 */
/* @0x2e525e ite gt */
/* @0x2e5260 mulgt r1, r4, r1 */
/* @0x2e5262 mulle r0, r4, r0 */
/* @0x2e5264 mov.w r4, #0x3 */
/* @0x2e5268 ite gt */
/* @0x2e526a addgt.w r1, r0, r1, asr #3 */
/* @0x2e526c bl 0x3259f8 */
/* @0x2e526e addle.w r1, r1, r0, asr #3 */
/* @0x2e5270 bhs 0x2e59f8 <FT_Face_Properties> */
/* @0x2e5272 cmp r2, #0x0 */
/* @0x2e5274 it lt */
/* @0x2e5276 rsblt r2, r2, #0 */
/* @0x2e5278 cmp r3, #0x0 */
/* @0x2e527a it lt */
/* @0x2e527c rsblt r3, r3, #0 */
/* @0x2e527e movs r0, #0x3 */
/* @0x2e5280 cmp r2, r3 */
/* @0x2e5282 itete gt */
/* @0x2e5284 mulgt r3, r0, r3 */
/* @0x2e5286 mulle r2, r0, r2 */
/* @0x2e5288 addgt.w r3, r2, r3, asr #3 */
/* @0x2e528c addle.w r3, r3, r2, asr #3 */
/* @0x2e5290 cmp r6, #0x0 */
/* @0x2e5292 it lt */
/* @0x2e5294 rsblt r6, r6, #0 */
/* @0x2e5296 cmp r5, #0x0 */
/* @0x2e5298 it lt */
/* @0x2e529a rsblt r5, r5, #0 */
/* @0x2e529c add r3, r1 */
/* @0x2e529e cmp r6, r5 */
/* @0x2e52a0 itete gt */
/* @0x2e52a2 mulgt r4, r5, r4 */
/* @0x2e52a4 mulle r4, r6, r4 */
/* @0x2e52a6 addgt.w r4, r6, r4, asr #3 */
/* @0x2e52a8 bl 0x426640 <g_RomDisk+0x2ee20> */
/* @0x2e52aa addle.w r4, r5, r4, asr #3 */
/* @0x2e52ac blne 0x9a6644 <b2_toiTime+0x24d1a0> */
/* @0x2e52ae subs r3, r3, r4 */
/* @0x2e52b0 cmp.w r3, r4, asr #4 */
/* @0x2e52b4 ite ge */
/* @0x2e52b6 movge r0, #0x0 */
/* @0x2e52b8 movlt r0, #0x1 */
/* @0x2e52ba pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e52bc · FT_GlyphLoader_Rewind · size=32 · insn=15 */
/* @0x2e52bc push {r4, r5, lr} */
/* @0x2e52be add.w r5, r0, #0x14 */
/* @0x2e52c0 movwhs r0, #0x514 */
/* @0x2e52c2 movs r3, #0x0 */
/* @0x2e52c4 add.w r4, r0, #0x38 */
/* @0x2e52c8 strh r3, [r0, #0x16] */
/* @0x2e52ca strh r3, [r0, #0x14] */
/* @0x2e52cc str r3, [r0, #0x30] */
/* @0x2e52ce ldm r5!, {r0, r1, r2, r3} */
/* @0x2e52d0 stm r4!, {r0, r1, r2, r3} */
/* @0x2e52d2 ldm r5!, {r0, r1, r2, r3} */
/* @0x2e52d4 stm r4!, {r0, r1, r2, r3} */
/* @0x2e52d6 ldr r3, [r5] */
/* @0x2e52d8 str r3, [r4] */
/* @0x2e52da pop {r4, r5, pc} */

/* ── FUNC 0x2e52dc · FT_GlyphLoader_Prepare · size=28 · insn=12 */
/* @0x2e52dc movs r3, #0x0 */
/* @0x2e52de strh r3, [r0, #0x3a] */
/* @0x2e52e0 push {r4, lr} */
/* @0x2e52e2 mov r4, r0 */
/* @0x2e52e4 strh r3, [r0, #0x38] */
/* @0x2e52e6 str r3, [r0, #0x54] */
/* @0x2e52e8 bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40> */
/* @0x2e52ec ldr r2, [r4, #0x30] */
/* @0x2e52ee ldr r3, [r4, #0x34] */
/* @0x2e52f0 add.w r3, r3, r2, lsl #5 */
/* @0x2e52f4 str r3, [r4, #0x58] */
/* @0x2e52f6 pop {r4, pc} */

/* ── FUNC 0x2e52f8 · FT_GlyphLoader_Add · size=62 · insn=28 */
/* @0x2e52f8 push {r4, r5, lr} */
/* @0x2e52fa cbz r0, 0x2e5334 <FT_GlyphLoader_Add+0x3c> */
/* @0x2e52fc ldrh r2, [r0, #0x16] */
/* @0x2e52fe ldrh r1, [r0, #0x3a] */
/* @0x2e5300 ldrh r3, [r0, #0x38] */
/* @0x2e5302 add r1, r2 */
/* @0x2e5304 strh r1, [r0, #0x16] */
/* @0x2e5306 ldrh r1, [r0, #0x14] */
/* @0x2e5308 sxth r4, r3 */
/* @0x2e530a add r3, r1 */
/* @0x2e530c ldr r1, [r0, #0x30] */
/* @0x2e530e strh r3, [r0, #0x14] */
/* @0x2e5310 ldr r3, [r0, #0x54] */
/* @0x2e5312 add r3, r1 */
/* @0x2e5314 str r3, [r0, #0x30] */
/* @0x2e5316 movs r3, #0x0 */
/* @0x2e5318 cmp r3, r4 */
/* @0x2e531a bge 0x2e532c <FT_GlyphLoader_Add+0x34> */
/* @0x2e531c ldr r1, [r0, #0x44] */
/* @0x2e531e ldrh.w r5, [r1, r3, lsl #1] */
/* @0x2e5320 ldrmi r5, [r5], #-19 */
/* @0x2e5322 add r5, r2 */
/* @0x2e5324 strh.w r5, [r1, r3, lsl #1] */
/* @0x2e5328 adds r3, #0x1 */
/* @0x2e532a b 0x2e5318 <FT_GlyphLoader_Add+0x20> */
/* @0x2e532c pop.w {r4, r5, lr} */
/* @0x2e5330 b.w 0x2e52dc <FT_GlyphLoader_Prepare> */
/* @0x2e5334 pop {r4, r5, pc} */

/* ── FUNC 0x2e5336 · ft_hash_str_lookup · size=14 · insn=7 */
/* @0x2e5336 push {r3, lr} */
/* @0x2e5338 bl 0x2e49b8 <_ZNK11b2GearJoint8GetRatioEv+0xb4> */
/* @0x2e533a stmdavs r0, {r1, r2, r3, r4, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2e533c ldr r0, [r0] */
/* @0x2e533e cbz r0, 0x2e5342 <ft_hash_str_lookup+0xc> */
/* @0x2e5340 adds r0, #0x4 */
/* @0x2e5342 pop {r3, pc} */

/* ── FUNC 0x2e5344 · ft_hash_num_lookup · size=14 · insn=7 */
/* @0x2e5344 push {r3, lr} */
/* @0x2e5346 bl 0x2e49b8 <_ZNK11b2GearJoint8GetRatioEv+0xb4> */
/* @0x2e5348 stmdavs r0, {r0, r1, r2, r4, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2e534a ldr r0, [r0] */
/* @0x2e534c cbz r0, 0x2e5350 <ft_hash_num_lookup+0xc> */
/* @0x2e534e adds r0, #0x4 */
/* @0x2e5350 pop {r3, pc} */

/* ── FUNC 0x2e5352 · ft_service_list_lookup · size=38 · insn=18 */
/* @0x2e5352 push {r3, r4, r5, lr} */
/* @0x2e5354 mov r5, r1 */
/* @0x2e5356 mov r4, r0 */
/* @0x2e5358 cbz r0, 0x2e5372 <ft_service_list_lookup+0x20> */
/* @0x2e535a cbz r1, 0x2e5374 <ft_service_list_lookup+0x22> */
/* @0x2e535c ldr r0, [r4] */
/* @0x2e535e cbz r0, 0x2e5370 <ft_service_list_lookup+0x1e> */
/* @0x2e5360 mov r1, r5 */
/* @0x2e5362 blx 0xb6574 <strcmp@plt> */
/* @0x2e5366 cbnz r0, 0x2e536c <ft_service_list_lookup+0x1a> */
/* @0x2e5368 ldr r0, [r4, #0x4] */
/* @0x2e536a pop {r3, r4, r5, pc} */
/* @0x2e536c adds r4, #0x8 */
/* @0x2e536e b 0x2e535c <ft_service_list_lookup+0xa> */
/* @0x2e5370 pop {r3, r4, r5, pc} */
/* @0x2e5372 pop {r3, r4, r5, pc} */
/* @0x2e5374 mov r0, r1 */
/* @0x2e5376 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e5378 · ft_validator_init · size=20 · insn=7 */
/* @0x2e5378 str.w r1, [r0, #0x100] */
/* @0x2e537c str.w r2, [r0, #0x104] */
/* @0x2e5380 str.w r3, [r0, #0x108] */
/* @0x2e5384 movs r3, #0x0 */
/* @0x2e5386 str.w r3, [r0, #0x10c] */
/* @0x2e5388 ldrbmi r3, [r0, -r12, lsl #2]! */
/* @0x2e538a bx lr */

/* ── FUNC 0x2e538c · ft_validator_run · size=6 · insn=2 */
/* @0x2e538c mov.w r0, #0xffffffff */
/* @0x2e5390 bx lr */

/* ── FUNC 0x2e5392 · ft_validator_error · size=12 · insn=4 */
/* @0x2e5392 str.w r1, [r0, #0x10c] */
/* @0x2e5396 movs r1, #0x1 */
/* @0x2e5398 push {r3, lr} */
/* @0x2e539a blx 0xb6f7c <longjmp@plt> */

/* ── FUNC 0x2e539e · FT_Set_Transform · size=114 · insn=51 */
/* @0x2e539e push {r4, r5, r6, lr} */
/* @0x2e53a0 mov r5, r1 */
/* @0x2e53a2 mov r6, r2 */
/* @0x2e53a4 cmp r0, #0x0 */
/* @0x2e53a6 beq 0x2e540e <FT_Set_Transform+0x70> */
/* @0x2e53a8 ldr.w r4, [r0, #0x80] */
/* @0x2e53aa movwhs r4, #0x80 */
/* @0x2e53ac movs r3, #0x0 */
/* @0x2e53ae str r3, [r4, #0x18] */
/* @0x2e53b0 cbnz r1, 0x2e53c2 <FT_Set_Transform+0x24> */
/* @0x2e53b2 mov.w r3, #0x10000 */
/* @0x2e53b6 str r1, [r4, #0x8] */
/* @0x2e53b8 stm.w r4, {r3, r5} */
/* @0x2e53ba strtmi r0, [r5], -r8, lsr #32 */
/* @0x2e53bc mov r5, r4 */
/* @0x2e53be str r3, [r4, #0xc] */
/* @0x2e53c0 b 0x2e53c8 <FT_Set_Transform+0x2a> */
/* @0x2e53c2 ldm r1, {r0, r1, r2, r3} */
/* @0x2e53c4 stm.w r4, {r0, r1, r2, r3} */
/* @0x2e53c6 stmvs r10!, {r0, r1, r2, r3} */
/* @0x2e53c8 ldr r2, [r5, #0x8] */
/* @0x2e53ca ldr r3, [r5, #0x4] */
/* @0x2e53cc orrs r3, r2 */
/* @0x2e53ce bne 0x2e53e0 <FT_Set_Transform+0x42> */
/* @0x2e53d0 ldr r3, [r5] */
/* @0x2e53d2 cmp.w r3, #0x10000 */
/* @0x2e53d6 bne 0x2e53e0 <FT_Set_Transform+0x42> */
/* @0x2e53d8 ldr r3, [r5, #0xc] */
/* @0x2e53da cmp.w r3, #0x10000 */
/* @0x2e53de beq 0x2e53e8 <FT_Set_Transform+0x4a> */
/* @0x2e53e0 ldr r3, [r4, #0x18] */
/* @0x2e53e2 orr r3, r3, #0x1 */
/* @0x2e53e6 str r3, [r4, #0x18] */
/* @0x2e53e8 add.w r3, r4, #0x10 */
/* @0x2e53ea ldmdblt lr, {r4, r8, r9} */
/* @0x2e53ec cbnz r6, 0x2e53f6 <FT_Set_Transform+0x58> */
/* @0x2e53ee str r6, [r4, #0x10] */
/* @0x2e53f0 str r6, [r4, #0x14] */
/* @0x2e53f2 mov r6, r3 */
/* @0x2e53f4 b 0x2e53fe <FT_Set_Transform+0x60> */
/* @0x2e53f6 ldm.w r6, {r0, r1} */
/* @0x2e53fa stm.w r3, {r0, r1} */
/* @0x2e53fe ldr r2, [r6, #0x4] */
/* @0x2e5400 ldr r3, [r6] */
/* @0x2e5402 orrs r3, r2 */
/* @0x2e5404 beq 0x2e540e <FT_Set_Transform+0x70> */
/* @0x2e5406 ldr r3, [r4, #0x18] */
/* @0x2e5408 orr r3, r3, #0x2 */
/* @0x2e540a .word 0x61a30302 */
/* @0x2e540c str r3, [r4, #0x18] */
/* @0x2e540e pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e5410 · FT_Reference_Face · size=20 · insn=10 */
/* @0x2e5410 cbz r0, 0x2e5420 <FT_Reference_Face+0x10> */
/* @0x2e5412 ldr.w r3, [r0, #0x80] */
/* @0x2e5414 andhs r3, r0, r0, lsl #1 */
/* @0x2e5416 movs r0, #0x0 */
/* @0x2e5418 ldr r2, [r3, #0x40] */
/* @0x2e541a adds r2, #0x1 */
/* @0x2e541c str r2, [r3, #0x40] */
/* @0x2e541e bx lr */
/* @0x2e5420 movs r0, #0x23 */
/* @0x2e5422 bx lr */

/* ── FUNC 0x2e5424 · FT_Match_Size · size=188 · insn=87 */
/* @0x2e5424 push.w {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2e5428 mov r7, r3 */
/* @0x2e542a ldr r3, [r0, #0x8] */
/* @0x2e542c mov r6, r0 */
/* @0x2e542e mov r4, r1 */
/* @0x2e5430 mov r8, r2 */
/* @0x2e5432 lsls r3, r3, #0x1e */
/* @0x2e5434 bpl 0x2e54ce <FT_Match_Size+0xaa> */
/* @0x2e5436 ldr r3, [r1] */
/* @0x2e5438 cmp r3, #0x0 */
/* @0x2e543a bne 0x2e54d4 <FT_Match_Size+0xb0> */
/* @0x2e543c ldr r0, [r1, #0xc] */
/* @0x2e543e ldr.w r9, [r1, #0x4] */
/* @0x2e5440 teqlt r8, r4 */
/* @0x2e5442 cbz r0, 0x2e5454 <FT_Match_Size+0x30> */
/* @0x2e5444 mul r0, r9, r0 */
/* @0x2e5448 movs r1, #0x48 */
/* @0x2e544a adds r0, #0x24 */
/* @0x2e544c blx 0x318d10 <__divsi3> */
/* @0x2e5450 mov r5, r0 */
/* @0x2e5452 b 0x2e5456 <FT_Match_Size+0x32> */
/* @0x2e5454 mov r5, r9 */
/* @0x2e5456 ldr r0, [r4, #0x10] */
/* @0x2e5458 ldr r4, [r4, #0x8] */
/* @0x2e545a cbz r0, 0x2e5468 <FT_Match_Size+0x44> */
/* @0x2e545c muls r0, r4, r0 */
/* @0x2e545e movs r1, #0x48 */
/* @0x2e5460 adds r0, #0x24 */
/* @0x2e5462 blx 0x318d10 <__divsi3> */
/* @0x2e5464 and lr, r0, r6, asr r12 */
/* @0x2e5466 b 0x2e546a <FT_Match_Size+0x46> */
/* @0x2e5468 mov r0, r4 */
/* @0x2e546a cmp.w r9, #0x0 */
/* @0x2e546c andle r0, r3, r0, lsl #30 */
/* @0x2e546e beq 0x2e5478 <FT_Match_Size+0x54> */
/* @0x2e5470 cmp r4, #0x0 */
/* @0x2e5472 it eq */
/* @0x2e5474 moveq r0, r5 */
/* @0x2e5476 b 0x2e547e <FT_Match_Size+0x5a> */
/* @0x2e5478 cmp r4, #0x0 */
/* @0x2e547a it ne */
/* @0x2e547c movne r5, r0 */
/* @0x2e547e adds r5, #0x20 */
/* @0x2e5480 bics r5, r5, #0x3f */
/* @0x2e5484 beq 0x2e54da <FT_Match_Size+0xb6> */
/* @0x2e5486 add.w r1, r0, #0x20 */
/* @0x2e5488 .word 0xf0310120 */
/* @0x2e548a bics r4, r1, #0x3f */
/* @0x2e548c eorle r0, r4, pc, lsr r4 */
/* @0x2e548e beq 0x2e54da <FT_Match_Size+0xb6> */
/* @0x2e5490 ldr r0, [r6, #0x1c] */
/* @0x2e5492 movs r1, #0x0 */
/* @0x2e5494 cmp r1, r0 */
/* @0x2e5496 bge 0x2e54da <FT_Match_Size+0xb6> */
/* @0x2e5498 ldr r3, [r6, #0x20] */
/* @0x2e549a add.w r3, r3, r1, lsl #4 */
/* @0x2e549c ldmvs r10, {r0, r8, r9, r12} ^ */
/* @0x2e549e ldr r2, [r3, #0xc] */
/* @0x2e54a0 adds r2, #0x20 */
/* @0x2e54a2 bic r2, r2, #0x3f */
/* @0x2e54a4 addsmi r0, r4, #-268435453 */
/* @0x2e54a6 cmp r4, r2 */
/* @0x2e54a8 bne 0x2e54ca <FT_Match_Size+0xa6> */
/* @0x2e54aa ldr r3, [r3, #0x8] */
/* @0x2e54ac adds r3, #0x20 */
/* @0x2e54ae bic r3, r3, #0x3f */
/* @0x2e54b0 addsmi r0, sp, #-67108864 */
/* @0x2e54b2 cmp r5, r3 */
/* @0x2e54b4 bne 0x2e54bc <FT_Match_Size+0x98> */
/* @0x2e54b6 cbz r7, 0x2e54c4 <FT_Match_Size+0xa0> */
/* @0x2e54b8 str r1, [r7] */
/* @0x2e54ba b 0x2e54c4 <FT_Match_Size+0xa0> */
/* @0x2e54bc cmp.w r8, #0x0 */
/* @0x2e54c0 beq 0x2e54ca <FT_Match_Size+0xa6> */
/* @0x2e54c2 b 0x2e54b6 <FT_Match_Size+0x92> */
/* @0x2e54c4 movs r0, #0x0 */
/* @0x2e54c6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e54c8 strdlo r8, r9, [r1, -r8] */
/* @0x2e54ca adds r1, #0x1 */
/* @0x2e54cc b 0x2e5494 <FT_Match_Size+0x70> */
/* @0x2e54ce movs r0, #0x23 */
/* @0x2e54d0 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e54d4 movs r0, #0x7 */
/* @0x2e54d6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2e54d8 ldrshhs r8, [r7], -r8 */
/* @0x2e54da movs r0, #0x17 */
/* @0x2e54dc pop.w {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2e54e0 · ft_synthesize_vertical_metrics · size=68 · insn=32 */
/* @0x2e54e0 push {r3, r4, r5, lr} */
/* @0x2e54e2 mov r4, r0 */
/* @0x2e54e4 ldr r3, [r0, #0xc] */
/* @0x2e54e6 ldr r5, [r0, #0x4] */
/* @0x2e54e8 cmp r3, #0x0 */
/* @0x2e54ea bge 0x2e54f4 <ft_synthesize_vertical_metrics+0x14> */
/* @0x2e54ec cmp r5, r3 */
/* @0x2e54ee it lt */
/* @0x2e54f0 movlt r5, r3 */
/* @0x2e54f2 b 0x2e54fa <ft_synthesize_vertical_metrics+0x1a> */
/* @0x2e54f4 it ne */
/* @0x2e54f6 rsbne r5, r3, r5 */
/* @0x2e54f8 stmdblt r9!, {r0, r2, r8, r10} */
/* @0x2e54fa cbnz r1, 0x2e5508 <ft_synthesize_vertical_metrics+0x28> */
/* @0x2e54fc movs r0, #0xc */
/* @0x2e54fe movs r1, #0xa */
/* @0x2e5500 muls r0, r5, r0 */
/* @0x2e5502 blx 0x318d10 <__divsi3> */
/* @0x2e5504 strmi lr, [r1], -r6, lsl #24 */
/* @0x2e5506 mov r1, r0 */
/* @0x2e5508 ldr r3, [r4, #0x10] */
/* @0x2e550a subs r5, r1, r5 */
/* @0x2e550c ldr r2, [r4, #0x8] */
/* @0x2e550e add.w r5, r5, r5, lsr #31 */
/* @0x2e5510 ldrdvs r7, r8, [r1, #85]! */
/* @0x2e5512 str r1, [r4, #0x1c] */
/* @0x2e5514 add.w r3, r3, r3, lsr #31 */
/* @0x2e5518 asrs r5, r5, #0x1 */
/* @0x2e551a str r5, [r4, #0x18] */
/* @0x2e551c sub.w r2, r2, r3, asr #1 */
/* @0x2e5520 str r2, [r4, #0x14] */
/* @0x2e5522 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e5524 · FT_Select_Metrics · size=100 · insn=48 */
/* @0x2e5524 push {r4, r5, r6, lr} */
/* @0x2e5526 lsls r1, r1, #0x4 */
/* @0x2e5528 ldr r2, [r0, #0x20] */
/* @0x2e552a mov r6, r0 */
/* @0x2e552c ldr r4, [r0, #0x58] */
/* @0x2e552e adds r5, r2, r1 */
/* @0x2e5530 ldr r3, [r5, #0x8] */
/* @0x2e5532 adds r3, #0x20 */
/* @0x2e5534 asrs r3, r3, #0x6 */
/* @0x2e5536 strh r3, [r4, #0xc] */
/* @0x2e5538 ldr r3, [r5, #0xc] */
/* @0x2e553a adds r3, #0x20 */
/* @0x2e553c asrs r3, r3, #0x6 */
/* @0x2e553e strh r3, [r4, #0xe] */
/* @0x2e5540 ldr r3, [r0, #0x8] */
/* @0x2e5542 ands r3, r3, #0x1 */
/* @0x2e5544 andsle r0, r2, r1, lsl #6 */
/* @0x2e5546 beq 0x2e556e <FT_Select_Metrics+0x4a> */
/* @0x2e5548 ldrh.w r1, [r6, #0x44] */
/* @0x2e554c ldr r0, [r5, #0x8] */
/* @0x2e554e bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e5550 strhvs pc, [r0, -r2]! */
/* @0x2e5552 str r0, [r4, #0x10] */
/* @0x2e5554 ldrh.w r1, [r6, #0x44] */
/* @0x2e5558 ldr r0, [r5, #0xc] */
/* @0x2e555a bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e555c .word 0xf104fcac */
/* @0x2e555e add.w r1, r4, #0xc */
/* @0x2e5560 .word 0x6160010c */
/* @0x2e5562 str r0, [r4, #0x14] */
/* @0x2e5564 mov r0, r6 */
/* @0x2e5566 pop.w {r4, r5, r6, lr} */
/* @0x2e5568 .word 0xf7ff4070 */
/* @0x2e556a b.w 0x2e4e68 <FT_MulFix+0x1c> */
/* @0x2e556c .word 0xf44fbc7d */
/* @0x2e556e mov.w r0, #0x10000 */
/* @0x2e5570 smlawbvs r0, r0, r0, r3 */
/* @0x2e5572 str r0, [r4, #0x10] */
/* @0x2e5574 str r0, [r4, #0x14] */
/* @0x2e5576 ldr r0, [r5, #0xc] */
/* @0x2e5578 str r3, [r4, #0x1c] */
/* @0x2e557a str r0, [r4, #0x18] */
/* @0x2e557c ldrsh r3, [r2, r1] */
/* @0x2e557e lsls r3, r3, #0x6 */
/* @0x2e5580 str r3, [r4, #0x20] */
/* @0x2e5582 ldr r3, [r5, #0x8] */
/* @0x2e5584 str r3, [r4, #0x24] */
/* @0x2e5586 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e5588 · FT_Request_Metrics · size=370 · insn=164 */
/* @0x2e5588 push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e558c mov r7, r1 */
/* @0x2e558e ldr r1, [r0, #0x8] */
/* @0x2e5590 mov r5, r0 */
/* @0x2e5592 ldr r4, [r0, #0x58] */
/* @0x2e5594 ands r1, r1, #0x1 */
/* @0x2e5598 add.w r11, r4, #0xc */
/* @0x2e559c beq.w 0x2e56dc <FT_Request_Metrics+0x154> */
/* @0x2e55a0 ldm.w r7, {r2, r3} */
/* @0x2e55a4 cmp r2, #0x4 */
/* @0x2e55a6 bhi.w 0x2e56f2 <FT_Request_Metrics+0x16a> */
/* @0x2e55a8 ldm pc, {r2, r5, r7, pc} ^ */
/* @0x2e55aa tbb [pc, r2] */
/* @0x2e55ac streq pc, [r3], -r2 */
/* @0x2e55ae lsls r3, r0, #0x18 */
/* @0x2e55b0 asrs r6, r1, #0x1c */
/* @0x2e55b2 movs r0, r4 */
/* @0x2e55b4 ldrh.w r9, [r5, #0x44] */
/* @0x2e55b8 b 0x2e56f6 <FT_Request_Metrics+0x16e> */
/* @0x2e55ba ldrsh.w r9, [r5, #0x46] */
/* @0x2e55bc rfeib r5! */
/* @0x2e55be ldrsh.w r2, [r5, #0x48] */
/* @0x2e55c0 bl 0xff36d6e8 <b2_toiTime+0xfffffffffec14244> */
/* @0x2e55c2 rsb r9, r2, r9 */
/* @0x2e55c4 strbmi r0, [r10], r9, lsl #18 */
/* @0x2e55c6 mov r10, r9 */
/* @0x2e55c8 b 0x2e5604 <FT_Request_Metrics+0x7c> */
/* @0x2e55ca ldr r1, [r5, #0x3c] */
/* @0x2e55cc ldr r2, [r5, #0x34] */
/* @0x2e55ce rsb r9, r2, r1 */
/* @0x2e55d0 stcvs p9, c0, [r9], #-4 */
/* @0x2e55d2 ldr r1, [r5, #0x40] */
/* @0x2e55d4 ldr r2, [r5, #0x38] */
/* @0x2e55d6 rsb r10, r2, r1 */
/* @0x2e55d8 ands r0, r3, r1, lsl #20 */
/* @0x2e55da b 0x2e5604 <FT_Request_Metrics+0x7c> */
/* @0x2e55dc ldrsh.w r10, [r5, #0x46] */
/* @0x2e55e0 ldrsh.w r2, [r5, #0x48] */
/* @0x2e55e4 ldrsh.w r9, [r5, #0x4c] */
/* @0x2e55e8 rsb r10, r2, r10 */
/* @0x2e55ec b 0x2e5604 <FT_Request_Metrics+0x7c> */
/* @0x2e55ee str r3, [r4, #0x10] */
/* @0x2e55f0 ldr r6, [r7, #0x8] */
/* @0x2e55f2 str r6, [r4, #0x14] */
/* @0x2e55f4 cbnz r3, 0x2e55fc <FT_Request_Metrics+0x74> */
/* @0x2e55f6 str r6, [r4, #0x10] */
/* @0x2e55f8 mov r6, r3 */
/* @0x2e55fa b 0x2e569e <FT_Request_Metrics+0x116> */
/* @0x2e55fc cmp r6, #0x0 */
/* @0x2e55fe bne 0x2e569c <FT_Request_Metrics+0x114> */
/* @0x2e5600 str r3, [r4, #0x14] */
/* @0x2e5602 b 0x2e569e <FT_Request_Metrics+0x116> */
/* @0x2e5604 cmp.w r9, #0x0 */
/* @0x2e5608 it lt */
/* @0x2e560a rsblt.w r9, r9, #0x0 */
/* @0x2e560c ldmvs r8!, {r8, r11} ^ */
/* @0x2e560e ldr r0, [r7, #0xc] */
/* @0x2e5610 cmp.w r10, #0x0 */
/* @0x2e5614 it lt */
/* @0x2e5616 rsblt.w r10, r10, #0x0 */
/* @0x2e5618 .word 0xb1400a00 */
/* @0x2e561a cbz r0, 0x2e562e <FT_Request_Metrics+0xa6> */
/* @0x2e561c muls r0, r3, r0 */
/* @0x2e561e movs r1, #0x48 */
/* @0x2e5620 str r3, [sp, #0x4] */
/* @0x2e5622 adds r0, #0x24 */
/* @0x2e5624 blx 0x318d10 <__divsi3> */
/* @0x2e5628 ldr r3, [sp, #0x4] */
/* @0x2e562a mov r8, r0 */
/* @0x2e562c b 0x2e5630 <FT_Request_Metrics+0xa8> */
/* @0x2e562e mov r8, r3 */
/* @0x2e5630 ldr r0, [r7, #0x10] */
/* @0x2e5632 ldr r6, [r7, #0x8] */
/* @0x2e5634 cbz r0, 0x2e5646 <FT_Request_Metrics+0xbe> */
/* @0x2e5636 muls r0, r6, r0 */
/* @0x2e5638 movs r1, #0x48 */
/* @0x2e563a str r3, [sp, #0x4] */
/* @0x2e563c adds r0, #0x24 */
/* @0x2e563e blx 0x318d10 <__divsi3> */
/* @0x2e5640 blls 0x3603e8 <_ZTS12CDS_Priority+0x2440> */
/* @0x2e5642 ldr r3, [sp, #0x4] */
/* @0x2e5644 mov r6, r0 */
/* @0x2e5646 cbz r3, 0x2e5682 <FT_Request_Metrics+0xfa> */
/* @0x2e5648 mov r0, r8 */
/* @0x2e564a mov r1, r9 */
/* @0x2e564c bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e5650 str r0, [r4, #0x10] */
/* @0x2e5652 ldr r3, [r7, #0x8] */
/* @0x2e5654 cbz r3, 0x2e5672 <FT_Request_Metrics+0xea> */
/* @0x2e5656 mov r0, r6 */
/* @0x2e5658 mov r1, r10 */
/* @0x2e565a bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e565c .word 0x6160fc2c */
/* @0x2e565e str r0, [r4, #0x14] */
/* @0x2e5660 ldr r3, [r7] */
/* @0x2e5662 cmp r3, #0x3 */
/* @0x2e5664 bne 0x2e56a0 <FT_Request_Metrics+0x118> */
/* @0x2e5666 ldr r3, [r4, #0x10] */
/* @0x2e5668 cmp r0, r3 */
/* @0x2e566a ite le */
/* @0x2e566c strle r0, [r4, #0x10] */
/* @0x2e566e strgt r3, [r4, #0x14] */
/* @0x2e5670 b 0x2e56a0 <FT_Request_Metrics+0x118> */
/* @0x2e5672 str r0, [r4, #0x14] */
/* @0x2e5674 mov r1, r10 */
/* @0x2e5676 mov r0, r8 */
/* @0x2e5678 mov r2, r9 */
/* @0x2e567a bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e567c .word 0x4606fb5f */
/* @0x2e567e mov r6, r0 */
/* @0x2e5680 b 0x2e56a0 <FT_Request_Metrics+0x118> */
/* @0x2e5682 mov r1, r10 */
/* @0x2e5684 mov r0, r6 */
/* @0x2e5686 bl 0x2e4eb6 <FT_DivFix> */
/* @0x2e5688 .word 0x4649fc16 */
/* @0x2e568a mov r1, r9 */
/* @0x2e568c mov r2, r10 */
/* @0x2e568e str r0, [r4, #0x14] */
/* @0x2e5690 str r0, [r4, #0x10] */
/* @0x2e5692 mov r0, r6 */
/* @0x2e5694 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5698 mov r8, r0 */
/* @0x2e569a b 0x2e56a0 <FT_Request_Metrics+0x118> */
/* @0x2e569c movs r6, #0x0 */
/* @0x2e569e mov r8, r6 */
/* @0x2e56a0 ldr r3, [r7] */
/* @0x2e56a2 cbz r3, 0x2e56bc <FT_Request_Metrics+0x134> */
/* @0x2e56a4 ldr r1, [r4, #0x10] */
/* @0x2e56a6 ldrh.w r0, [r5, #0x44] */
/* @0x2e56a8 .word 0xf7ff0044 */
/* @0x2e56aa bl 0x2e4e4c <FT_MulFix> */
/* @0x2e56ac stmdbvs r1!, {r0, r1, r2, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x2e56ae ldr r1, [r4, #0x14] */
/* @0x2e56b0 mov r8, r0 */
/* @0x2e56b2 ldrh.w r0, [r5, #0x44] */
/* @0x2e56b4 .word 0xf7ff0044 */
/* @0x2e56b6 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e56b8 strmi pc, [r6], -r9, asr #23 */
/* @0x2e56ba mov r6, r0 */
/* @0x2e56bc add.w r8, r8, #0x20 */
/* @0x2e56c0 adds r6, #0x20 */
/* @0x2e56c2 mov r0, r5 */
/* @0x2e56c4 mov r1, r11 */
/* @0x2e56c6 asr.w r8, r8, #0x6 */
/* @0x2e56c8 .word 0x11b618a8 */
/* @0x2e56ca asrs r6, r6, #0x6 */
/* @0x2e56cc strh.w r8, [r4, #0xc] */
/* @0x2e56d0 strh r6, [r4, #0xe] */
/* @0x2e56d2 add sp, #0xc */
/* @0x2e56d4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e56d8 b.w 0x2e4e68 <FT_MulFix+0x1c> */
/* @0x2e56dc mov r0, r11 */
/* @0x2e56de movs r2, #0x1c */
/* @0x2e56e0 blx 0xb65b0 <memset@plt> */
/* @0x2e56e4 mov.w r3, #0x10000 */
/* @0x2e56e8 str r3, [r4, #0x10] */
/* @0x2e56ea str r3, [r4, #0x14] */
/* @0x2e56ec add sp, #0xc */
/* @0x2e56ee pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e56f0 .word 0xf04f8ff0 */
/* @0x2e56f2 mov.w r9, #0x0 */
/* @0x2e56f4 strbmi r0, [r10], r0, lsl #18 */
/* @0x2e56f6 mov r10, r9 */
/* @0x2e56f8 b 0x2e560e <FT_Request_Metrics+0x86> */

/* ── FUNC 0x2e56fa · FT_Select_Size · size=50 · insn=25 */
/* @0x2e56fa push {r4, lr} */
/* @0x2e56fc cbz r0, 0x2e5724 <FT_Select_Size+0x2a> */
/* @0x2e56fe ldr r4, [r0, #0x8] */
/* @0x2e5700 lsls r4, r4, #0x1e */
/* @0x2e5702 bpl 0x2e5724 <FT_Select_Size+0x2a> */
/* @0x2e5704 cmp r1, #0x0 */
/* @0x2e5706 blt 0x2e5728 <FT_Select_Size+0x2e> */
/* @0x2e5708 ldr r4, [r0, #0x1c] */
/* @0x2e570a cmp r1, r4 */
/* @0x2e570c bge 0x2e5728 <FT_Select_Size+0x2e> */
/* @0x2e570e ldr r2, [r0, #0x60] */
/* @0x2e5710 ldr r2, [r2, #0xc] */
/* @0x2e5712 ldr r4, [r2, #0x5c] */
/* @0x2e5714 cbz r4, 0x2e571c <FT_Select_Size+0x22> */
/* @0x2e5716 ldr r0, [r0, #0x58] */
/* @0x2e5718 blx r4 */
/* @0x2e571a pop {r4, pc} */
/* @0x2e571c bl 0x2e5524 <FT_Select_Metrics> */
/* @0x2e571e strtmi pc, [r0], -r2, lsl #30 */
/* @0x2e5720 mov r0, r4 */
/* @0x2e5722 pop {r4, pc} */
/* @0x2e5724 movs r0, #0x23 */
/* @0x2e5726 pop {r4, pc} */
/* @0x2e5728 movs r0, #0x6 */
/* @0x2e572a pop {r4, pc} */

/* ── FUNC 0x2e572c · FT_Request_Size · size=96 · insn=47 */
/* @0x2e572c push {r0, r1, r2, r4, r5, lr} */
/* @0x2e572e mov r4, r0 */
/* @0x2e5730 cbz r0, 0x2e5782 <FT_Request_Size+0x56> */
/* @0x2e5732 cbz r1, 0x2e5786 <FT_Request_Size+0x5a> */
/* @0x2e5734 ldr r2, [r1, #0x4] */
/* @0x2e5736 cmp r2, #0x0 */
/* @0x2e5738 blt 0x2e5786 <FT_Request_Size+0x5a> */
/* @0x2e573a ldr r2, [r1, #0x8] */
/* @0x2e573c cmp r2, #0x0 */
/* @0x2e573e blt 0x2e5786 <FT_Request_Size+0x5a> */
/* @0x2e5740 ldr r3, [r1] */
/* @0x2e5742 cmp r3, #0x4 */
/* @0x2e5744 bhi 0x2e5786 <FT_Request_Size+0x5a> */
/* @0x2e5746 ldr r3, [r0, #0x58] */
/* @0x2e5748 movs r2, #0x0 */
/* @0x2e574a ldr r3, [r3, #0x28] */
/* @0x2e574c str r2, [r3, #0xc] */
/* @0x2e574e ldr r3, [r0, #0x60] */
/* @0x2e5750 ldr r3, [r3, #0xc] */
/* @0x2e5752 ldr r5, [r3, #0x58] */
/* @0x2e5754 cbz r5, 0x2e575c <FT_Request_Size+0x30> */
/* @0x2e5756 ldr r0, [r0, #0x58] */
/* @0x2e5758 blx r5 */
/* @0x2e575a b 0x2e5788 <FT_Request_Size+0x5c> */
/* @0x2e575c ldr r3, [r0, #0x8] */
/* @0x2e575e and r3, r3, #0x3 */
/* @0x2e5760 blhs 0x366374 <_ZTS12CDS_Priority+0x83cc> */
/* @0x2e5762 cmp r3, #0x2 */
/* @0x2e5764 bne 0x2e577a <FT_Request_Size+0x4e> */
/* @0x2e5766 mov r2, r5 */
/* @0x2e5768 add r3, sp, #0x4 */
/* @0x2e576a bl 0x2e5424 <FT_Match_Size> */
/* @0x2e576c ldmdblt r8, {r0, r1, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e576e cbnz r0, 0x2e5788 <FT_Request_Size+0x5c> */
/* @0x2e5770 mov r0, r4 */
/* @0x2e5772 ldr r1, [sp, #0x4] */
/* @0x2e5774 bl 0x2e56fa <FT_Select_Size> */
/* @0x2e5778 b 0x2e5788 <FT_Request_Size+0x5c> */
/* @0x2e577a bl 0x2e5588 <FT_Request_Metrics> */
/* @0x2e577c strtmi pc, [r8], -r5, lsl #30 */
/* @0x2e577e mov r0, r5 */
/* @0x2e5780 b 0x2e5788 <FT_Request_Size+0x5c> */
/* @0x2e5782 movs r0, #0x23 */
/* @0x2e5784 b 0x2e5788 <FT_Request_Size+0x5c> */
/* @0x2e5786 movs r0, #0x6 */
/* @0x2e5788 add sp, #0xc */
/* @0x2e578a pop {r4, r5, pc} */

/* ── FUNC 0x2e578c · FT_Set_Char_Size · size=70 · insn=35 */
/* @0x2e578c push {r4, r5, lr} */
/* @0x2e578e sub sp, #0x1c */
/* @0x2e5790 ldr r4, [sp, #0x28] */
/* @0x2e5792 cbz r1, 0x2e579c <FT_Set_Char_Size+0x10> */
/* @0x2e5794 cmp r2, #0x0 */
/* @0x2e5796 it eq */
/* @0x2e5798 moveq r2, r1 */
/* @0x2e579a b 0x2e579e <FT_Set_Char_Size+0x12> */
/* @0x2e579c mov r1, r2 */
/* @0x2e579e cbz r3, 0x2e57a8 <FT_Set_Char_Size+0x1c> */
/* @0x2e57a0 cmp r4, #0x0 */
/* @0x2e57a2 it eq */
/* @0x2e57a4 moveq r4, r3 */
/* @0x2e57a6 b 0x2e57aa <FT_Set_Char_Size+0x1e> */
/* @0x2e57a8 mov r3, r4 */
/* @0x2e57aa cmp r1, #0x40 */
/* @0x2e57ac it lt */
/* @0x2e57ae movlt r1, #0x40 */
/* @0x2e57b0 cmp r2, #0x40 */
/* @0x2e57b2 it lt */
/* @0x2e57b4 movlt r2, #0x40 */
/* @0x2e57b6 cbnz r3, 0x2e57bc <FT_Set_Char_Size+0x30> */
/* @0x2e57b8 movs r4, #0x48 */
/* @0x2e57ba mov r3, r4 */
/* @0x2e57bc str r1, [sp, #0x8] */
/* @0x2e57be add r1, sp, #0x4 */
/* @0x2e57c0 movs r5, #0x0 */
/* @0x2e57c2 str r2, [sp, #0xc] */
/* @0x2e57c4 str r5, [sp, #0x4] */
/* @0x2e57c6 str r3, [sp, #0x10] */
/* @0x2e57c8 str r4, [sp, #0x14] */
/* @0x2e57ca bl 0x2e572c <FT_Request_Size> */
/* @0x2e57cc andlt pc, r7, pc, lsr #31 */
/* @0x2e57ce add sp, #0x1c */
/* @0x2e57d0 pop {r4, r5, pc} */

/* ── FUNC 0x2e57d2 · FT_Set_Pixel_Sizes · size=74 · insn=37 */
/* @0x2e57d2 push {r4, lr} */
/* @0x2e57d4 movw r3, #0xfffe */
/* @0x2e57d6 strdlt r7, r8, [r6], lr */
/* @0x2e57d8 sub sp, #0x18 */
/* @0x2e57da cbz r1, 0x2e57e4 <FT_Set_Pixel_Sizes+0x12> */
/* @0x2e57dc cmp r2, #0x0 */
/* @0x2e57de it eq */
/* @0x2e57e0 moveq r2, r1 */
/* @0x2e57e2 b 0x2e57e8 <FT_Set_Pixel_Sizes+0x16> */
/* @0x2e57e4 cbz r2, 0x2e57f4 <FT_Set_Pixel_Sizes+0x22> */
/* @0x2e57e6 mov r1, r2 */
/* @0x2e57e8 movw r4, #0xffff */
/* @0x2e57ea addsmi r7, r9, #-16777216 */
/* @0x2e57ec cmp r1, r3 */
/* @0x2e57ee it hi */
/* @0x2e57f0 movhi r1, r4 */
/* @0x2e57f2 b 0x2e57f8 <FT_Set_Pixel_Sizes+0x26> */
/* @0x2e57f4 movs r1, #0x1 */
/* @0x2e57f6 mov r2, r1 */
/* @0x2e57f8 movw r4, #0xffff */
/* @0x2e57fa addsmi r7, r10, #-16777216 */
/* @0x2e57fc cmp r2, r3 */
/* @0x2e57fe it hi */
/* @0x2e5800 movhi r2, r4 */
/* @0x2e5802 lsls r1, r1, #0x6 */
/* @0x2e5804 str r1, [sp, #0x8] */
/* @0x2e5806 add r1, sp, #0x4 */
/* @0x2e5808 movs r3, #0x0 */
/* @0x2e580a lsls r2, r2, #0x6 */
/* @0x2e580c str r3, [sp, #0x4] */
/* @0x2e580e str r2, [sp, #0xc] */
/* @0x2e5810 str r3, [sp, #0x10] */
/* @0x2e5812 str r3, [sp, #0x14] */
/* @0x2e5814 bl 0x2e572c <FT_Request_Size> */
/* @0x2e5816 andlt pc, r6, r10, lsl #31 */
/* @0x2e5818 add sp, #0x18 */
/* @0x2e581a pop {r4, pc} */

/* ── FUNC 0x2e581c · FT_Get_Kerning · size=142 · insn=69 */
/* @0x2e581c push {r3, r4, r5, r6, r7, lr} */
/* @0x2e581e mov r6, r3 */
/* @0x2e5820 ldr r4, [sp, #0x18] */
/* @0x2e5822 mov r5, r0 */
/* @0x2e5824 cmp r0, #0x0 */
/* @0x2e5826 beq 0x2e58a2 <FT_Get_Kerning+0x86> */
/* @0x2e5828 cmp r4, #0x0 */
/* @0x2e582a beq 0x2e58a6 <FT_Get_Kerning+0x8a> */
/* @0x2e582c ldr r7, [r0, #0x60] */
/* @0x2e582e movs r3, #0x0 */
/* @0x2e5830 str r3, [r4] */
/* @0x2e5832 str r3, [r4, #0x4] */
/* @0x2e5834 ldr r3, [r7, #0xc] */
/* @0x2e5836 ldr r7, [r3, #0x4c] */
/* @0x2e5838 cmp r7, #0x0 */
/* @0x2e583a beq 0x2e589e <FT_Get_Kerning+0x82> */
/* @0x2e583c mov r3, r4 */
/* @0x2e583e blx r7 */
/* @0x2e5840 cmp r0, #0x0 */
/* @0x2e5842 bne 0x2e58a8 <FT_Get_Kerning+0x8c> */
/* @0x2e5844 cmp r6, #0x2 */
/* @0x2e5846 beq 0x2e589e <FT_Get_Kerning+0x82> */
/* @0x2e5848 ldr r3, [r5, #0x58] */
/* @0x2e584a ldr r0, [r4] */
/* @0x2e584c ldr r1, [r3, #0x10] */
/* @0x2e584e bl 0x2e4e4c <FT_MulFix> */
/* @0x2e5850 .word 0x6020fafd */
/* @0x2e5852 str r0, [r4] */
/* @0x2e5854 ldr r3, [r5, #0x58] */
/* @0x2e5856 ldr r0, [r4, #0x4] */
/* @0x2e5858 ldr r1, [r3, #0x14] */
/* @0x2e585a bl 0x2e4e4c <FT_MulFix> */
/* @0x2e585c .word 0x2e01faf7 */
/* @0x2e585e cmp r6, #0x1 */
/* @0x2e5860 mov r7, r0 */
/* @0x2e5862 str r0, [r4, #0x4] */
/* @0x2e5864 beq 0x2e589e <FT_Get_Kerning+0x82> */
/* @0x2e5866 ldr r3, [r5, #0x58] */
/* @0x2e5868 ldr r0, [r4] */
/* @0x2e586a ldrh r1, [r3, #0xc] */
/* @0x2e586c cmp r1, #0x18 */
/* @0x2e586e bhi 0x2e5878 <FT_Get_Kerning+0x5c> */
/* @0x2e5870 movs r2, #0x19 */
/* @0x2e5872 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5874 eorvs pc, r0, r3, ror #20 */
/* @0x2e5876 str r0, [r4] */
/* @0x2e5878 ldr r3, [r5, #0x58] */
/* @0x2e587a ldrh r1, [r3, #0xe] */
/* @0x2e587c cmp r1, #0x18 */
/* @0x2e587e bhi 0x2e588a <FT_Get_Kerning+0x6e> */
/* @0x2e5880 mov r0, r7 */
/* @0x2e5882 movs r2, #0x19 */
/* @0x2e5884 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e5888 str r0, [r4, #0x4] */
/* @0x2e588a ldr r3, [r4] */
/* @0x2e588c adds r3, #0x20 */
/* @0x2e588e bic r3, r3, #0x3f */
/* @0x2e5890 eorvs r0, r3, pc, lsr r3 */
/* @0x2e5892 str r3, [r4] */
/* @0x2e5894 ldr r3, [r4, #0x4] */
/* @0x2e5896 adds r3, #0x20 */
/* @0x2e5898 bic r3, r3, #0x3f */
/* @0x2e589c str r3, [r4, #0x4] */
/* @0x2e589e movs r0, #0x0 */
/* @0x2e58a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e58a2 movs r0, #0x23 */
/* @0x2e58a4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2e58a6 movs r0, #0x6 */
/* @0x2e58a8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e58ac · FT_Get_Track_Kerning · size=72 · insn=33 */
/* @0x2e58ac push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e58b0 mov r7, r1 */
/* @0x2e58b2 mov r8, r2 */
/* @0x2e58b4 mov r5, r3 */
/* @0x2e58b6 mov r4, r0 */
/* @0x2e58b8 cbz r0, 0x2e58e4 <FT_Get_Track_Kerning+0x38> */
/* @0x2e58ba cbz r3, 0x2e58ea <FT_Get_Track_Kerning+0x3e> */
/* @0x2e58bc ldr r0, [r0, #0x60] */
/* @0x2e58be ldr r3, [r0] */
/* @0x2e58c0 ldr r3, [r3, #0x20] */
/* @0x2e58c2 cbnz r3, 0x2e58ca <FT_Get_Track_Kerning+0x1e> */
/* @0x2e58c4 movs r0, #0x7 */
/* @0x2e58c6 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e58c8 stmdbmi r9, {r4, r5, r6, r7, r8, pc} */
/* @0x2e58ca ldr r1, [pc, #0x24] */
/* @0x2e58cc add r1, pc */
/* @0x2e58ce blx r3 */
/* @0x2e58d0 cmp r0, #0x0 */
/* @0x2e58d2 beq 0x2e58c4 <FT_Get_Track_Kerning+0x18> */
/* @0x2e58d4 ldr r6, [r0] */
/* @0x2e58d6 mov r1, r7 */
/* @0x2e58d8 mov r0, r4 */
/* @0x2e58da mov r2, r8 */
/* @0x2e58dc mov r3, r5 */
/* @0x2e58de blx r6 */
/* @0x2e58e0 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e58e4 movs r0, #0x23 */
/* @0x2e58e6 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e58e8 strdhs r8, r9, [r6], -r0 */
/* @0x2e58ea movs r0, #0x6 */
/* @0x2e58ec pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e58f0 ldrh r0, [r3, #0x30] */
/* @0x2e58f2 movs r2, r1 */
