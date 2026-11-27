/* libyoyo.so 覆盖卡组 0217
 * 函数 0x23db24..0x240828，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x23db24 · strcp_D2A · size=44 · insn=11 */
/* @0x23db24 ldrb r3, [r1] */
/* @0x23db28 cmp r3, #0 */
/* @0x23db2c strb r3, [r0] */
/* @0x23db30 bxeq lr */
/* @0x23db34 add r3, r0, #1 */
/* @0x23db38 ldrb r2, [r1, #0x1]! */
/* @0x23db3c mov r0, r3 */
/* @0x23db40 cmp r2, #0 */
/* @0x23db44 strb r2, [r3], #1 */
/* @0x23db48 bne 0x23db38 <strcp_D2A+0x14> */
/* @0x23db4c bx lr */

/* ── FUNC 0x23db50 · rshift_D2A · size=244 · insn=61 */
/* @0x23db50 ldr r2, [r0, #0x10] */
/* @0x23db54 asr r3, r1, #5 */
/* @0x23db58 push {r4, r5, r6, r7, r8} */
/* @0x23db5c cmp r3, r2 */
/* @0x23db60 add r8, r0, #20 */
/* @0x23db64 bge 0x23dbec <rshift_D2A+0x9c> */
/* @0x23db68 ands r6, r1, #31 */
/* @0x23db6c add r2, r8, r2, lsl #2 */
/* @0x23db70 add r7, r8, r3, lsl #2 */
/* @0x23db74 beq 0x23dc04 <rshift_D2A+0xb4> */
/* @0x23db78 ldr r12, [r8, r3, lsl #2] */
/* @0x23db7c add r3, r7, #4 */
/* @0x23db80 cmp r2, r3 */
/* @0x23db84 rsb r1, r6, #32 */
/* @0x23db88 lsr r12, r12, r6 */
/* @0x23db8c bls 0x23dc3c <rshift_D2A+0xec> */
/* @0x23db90 mov r4, r8 */
/* @0x23db94 ldr r5, [r3] */
/* @0x23db98 orr r12, r12, r5, lsl r1 */
/* @0x23db9c str r12, [r4], #4 */
/* @0x23dba0 ldr r12, [r3], #4 */
/* @0x23dba4 cmp r3, r2 */
/* @0x23dba8 lsr r12, r12, r6 */
/* @0x23dbac blo 0x23db94 <rshift_D2A+0x44> */
/* @0x23dbb0 rsb r3, r7, r2 */
/* @0x23dbb4 sub r3, r3, #5 */
/* @0x23dbb8 bic r3, r3, #3 */
/* @0x23dbbc add r3, r3, #4 */
/* @0x23dbc0 add r3, r8, r3 */
/* @0x23dbc4 cmp r12, #0 */
/* @0x23dbc8 str r12, [r3] */
/* @0x23dbcc addne r3, r3, #4 */
/* @0x23dbd0 rsb r8, r8, r3 */
/* @0x23dbd4 asr r8, r8, #2 */
/* @0x23dbd8 cmp r8, #0 */
/* @0x23dbdc str r8, [r0, #0x10] */
/* @0x23dbe0 beq 0x23dbf4 <rshift_D2A+0xa4> */
/* @0x23dbe4 pop {r4, r5, r6, r7, r8} */
/* @0x23dbe8 bx lr */
/* @0x23dbec mov r3, #0 */
/* @0x23dbf0 str r3, [r0, #0x10] */
/* @0x23dbf4 mov r3, #0 */
/* @0x23dbf8 str r3, [r0, #0x14] */
/* @0x23dbfc pop {r4, r5, r6, r7, r8} */
/* @0x23dc00 bx lr */
/* @0x23dc04 cmp r2, r7 */
/* @0x23dc08 movhi r1, r8 */
/* @0x23dc0c movhi r3, r7 */
/* @0x23dc10 bls 0x23dbec <rshift_D2A+0x9c> */
/* @0x23dc14 ldr r12, [r3], #4 */
/* @0x23dc18 cmp r2, r3 */
/* @0x23dc1c str r12, [r1], #4 */
/* @0x23dc20 bhi 0x23dc14 <rshift_D2A+0xc4> */
/* @0x23dc24 mvn r8, r7 */
/* @0x23dc28 add r8, r8, r2 */
/* @0x23dc2c bic r8, r8, #3 */
/* @0x23dc30 add r8, r8, #4 */
/* @0x23dc34 asr r8, r8, #2 */
/* @0x23dc38 b 0x23dbd8 <rshift_D2A+0x88> */
/* @0x23dc3c mov r3, r8 */
/* @0x23dc40 b 0x23dbc4 <rshift_D2A+0x74> */

/* ── FUNC 0x23dc44 · trailz_D2A · size=128 · insn=32 */
/* @0x23dc44 ldr r1, [r0, #0x10] */
/* @0x23dc48 add r3, r0, #20 */
/* @0x23dc4c push {r4, lr} */
/* @0x23dc50 sub sp, sp, #8 */
/* @0x23dc54 add r1, r3, r1, lsl #2 */
/* @0x23dc58 cmp r3, r1 */
/* @0x23dc5c bhs 0x23dcbc <trailz_D2A+0x78> */
/* @0x23dc60 ldr r4, [r0, #0x14] */
/* @0x23dc64 cmp r4, #0 */
/* @0x23dc68 bne 0x23dc98 <trailz_D2A+0x54> */
/* @0x23dc6c add r3, r0, #24 */
/* @0x23dc70 b 0x23dc80 <trailz_D2A+0x3c> */
/* @0x23dc74 ldr r2, [r3], #4 */
/* @0x23dc78 cmp r2, #0 */
/* @0x23dc7c bne 0x23dca0 <trailz_D2A+0x5c> */
/* @0x23dc80 cmp r1, r3 */
/* @0x23dc84 add r4, r4, #32 */
/* @0x23dc88 bhi 0x23dc74 <trailz_D2A+0x30> */
/* @0x23dc8c mov r0, r4 */
/* @0x23dc90 add sp, sp, #8 */
/* @0x23dc94 pop {r4, pc} */
/* @0x23dc98 mov r2, r4 */
/* @0x23dc9c mov r4, #0 */
/* @0x23dca0 add r0, sp, #8 */
/* @0x23dca4 str r2, [r0, #-0x4]! */
/* @0x23dca8 bl 0x23d2d4 <lo0bits_D2A> */
/* @0x23dcac add r4, r4, r0 */
/* @0x23dcb0 mov r0, r4 */
/* @0x23dcb4 add sp, sp, #8 */
/* @0x23dcb8 pop {r4, pc} */
/* @0x23dcbc mov r4, #0 */
/* @0x23dcc0 b 0x23dc8c <trailz_D2A+0x48> */

/* ── FUNC 0x23dcc4 · rv_alloc_D2A · size=80 · insn=20 */
/* @0x23dcc4 cmp r0, #19 */
/* @0x23dcc8 push {r4, lr} */
/* @0x23dccc mov r4, #0 */
/* @0x23dcd0 ble 0x23dcec <rv_alloc_D2A+0x28> */
/* @0x23dcd4 mov r3, #4 */
/* @0x23dcd8 lsl r3, r3, #1 */
/* @0x23dcdc add r4, r4, #1 */
/* @0x23dce0 add r2, r3, #16 */
/* @0x23dce4 cmp r2, r0 */
/* @0x23dce8 ble 0x23dcd8 <rv_alloc_D2A+0x14> */
/* @0x23dcec mov r0, r4 */
/* @0x23dcf0 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23dcf4 ldr r2, [pc, #0x14] */
/* @0x23dcf8 ldr r2, [pc, r2] */
/* @0x23dcfc mov r3, r0 */
/* @0x23dd00 str r4, [r3], #4 */
/* @0x23dd04 mov r0, r3 */
/* @0x23dd08 str r3, [r2] */
/* @0x23dd0c pop {r4, pc} */
/* @0x23dd10 andseq r3, r11, r0, lsl r8 */

/* ── FUNC 0x23dd14 · nrv_alloc_D2A · size=84 · insn=21 */
/* @0x23dd14 push {r3, r4, r5, lr} */
/* @0x23dd18 mov r4, r0 */
/* @0x23dd1c mov r0, r2 */
/* @0x23dd20 mov r5, r1 */
/* @0x23dd24 bl 0x23dcc4 <rv_alloc_D2A> */
/* @0x23dd28 ldrb r3, [r4] */
/* @0x23dd2c cmp r3, #0 */
/* @0x23dd30 strb r3, [r0] */
/* @0x23dd34 beq 0x23dd60 <nrv_alloc_D2A+0x4c> */
/* @0x23dd38 add r3, r0, #1 */
/* @0x23dd3c mov r12, r4 */
/* @0x23dd40 ldrb r2, [r12, #0x1]! */
/* @0x23dd44 mov r4, r3 */
/* @0x23dd48 cmp r2, #0 */
/* @0x23dd4c strb r2, [r3], #1 */
/* @0x23dd50 bne 0x23dd40 <nrv_alloc_D2A+0x2c> */
/* @0x23dd54 cmp r5, #0 */
/* @0x23dd58 strne r4, [r5] */
/* @0x23dd5c pop {r3, r4, r5, pc} */
/* @0x23dd60 mov r4, r0 */
/* @0x23dd64 b 0x23dd54 <nrv_alloc_D2A+0x40> */

/* ── FUNC 0x23dd68 · freedtoa(char*) · size=68 · insn=17 */
/* @0x23dd68 ldr r3, [r0, #-0x4] */
/* @0x23dd6c mov r2, #1 */
/* @0x23dd70 push {r4, lr} */
/* @0x23dd74 mov r4, r0 */
/* @0x23dd78 lsl r2, r2, r3 */
/* @0x23dd7c str r3, [r4] */
/* @0x23dd80 str r2, [r4, #0x4] */
/* @0x23dd84 sub r0, r0, #4 */
/* @0x23dd88 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23dd8c ldr r3, [pc, #0x14] */
/* @0x23dd90 ldr r3, [pc, r3] */
/* @0x23dd94 ldr r2, [r3] */
/* @0x23dd98 cmp r4, r2 */
/* @0x23dd9c moveq r2, #0 */
/* @0x23dda0 streq r2, [r3] */
/* @0x23dda4 pop {r4, pc} */
/* @0x23dda8 andseq r3, r11, r8, ror r7 */

/* ── FUNC 0x23ddac · quorem_D2A · size=544 · insn=136 */
/* @0x23ddac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23ddb0 sub sp, sp, #60 */
/* @0x23ddb4 ldr r3, [r0, #0x10] */
/* @0x23ddb8 mov r12, r0 */
/* @0x23ddbc ldr r10, [r1, #0x10] */
/* @0x23ddc0 str r1, [sp, #0x8] */
/* @0x23ddc4 cmp r10, r3 */
/* @0x23ddc8 movgt r0, #0 */
/* @0x23ddcc bgt 0x23dfc4 <quorem_D2A+0x218> */
/* @0x23ddd0 sub r10, r10, #1 */
/* @0x23ddd4 add r8, r1, #20 */
/* @0x23ddd8 add r11, r12, #20 */
/* @0x23dddc ldr r1, [r8, r10, lsl #2] */
/* @0x23dde0 lsl r7, r10, #2 */
/* @0x23dde4 ldr r0, [r11, r10, lsl #2] */
/* @0x23dde8 add r2, r11, r7 */
/* @0x23ddec add r1, r1, #1 */
/* @0x23ddf0 str r12, [sp, #0x4] */
/* @0x23ddf4 str r2, [sp, #0xc] */
/* @0x23ddf8 bl 0x318c48 <__udivsi3> */
/* @0x23ddfc add r9, r8, r7 */
/* @0x23de00 ldr r12, [sp, #0x4] */
/* @0x23de04 cmp r0, #0 */
/* @0x23de08 str r0, [sp, #0x10] */
/* @0x23de0c beq 0x23def4 <quorem_D2A+0x148> */
/* @0x23de10 mov r4, #0 */
/* @0x23de14 mov r5, #0 */
/* @0x23de18 mov lr, r11 */
/* @0x23de1c str r10, [sp, #0x14] */
/* @0x23de20 str r7, [sp, #0x1c] */
/* @0x23de24 mov r6, r8 */
/* @0x23de28 str r11, [sp, #0x20] */
/* @0x23de2c mov r7, r9 */
/* @0x23de30 str r12, [sp, #0x24] */
/* @0x23de34 mov r10, r4 */
/* @0x23de38 mov r11, r5 */
/* @0x23de3c mov r12, r0 */
/* @0x23de40 str r8, [sp, #0x18] */
/* @0x23de44 ldr r3, [r6], #4 */
/* @0x23de48 mov r8, r4 */
/* @0x23de4c mov r9, r5 */
/* @0x23de50 ldr r2, [lr] */
/* @0x23de54 mov r5, #0 */
/* @0x23de58 umlal r8, r9, r3, r12 */
/* @0x23de5c subs r2, r2, r8 */
/* @0x23de60 sbc r3, r2, r2 */
/* @0x23de64 subs r2, r2, r10 */
/* @0x23de68 sbc r3, r3, r11 */
/* @0x23de6c cmp r7, r6 */
/* @0x23de70 mov r10, #1 */
/* @0x23de74 mov r11, #0 */
/* @0x23de78 str r2, [lr], #4 */
/* @0x23de7c mov r4, r9 */
/* @0x23de80 and r10, r10, r3 */
/* @0x23de84 and r11, r11, r5 */
/* @0x23de88 bhs 0x23de44 <quorem_D2A+0x98> */
/* @0x23de8c mov r9, r7 */
/* @0x23de90 add r7, sp, #28 */
/* @0x23de94 ldr r10, [sp, #0x14] */
/* @0x23de98 ldm r7, {r7, r11, r12} */
/* @0x23de9c ldr r8, [sp, #0x18] */
/* @0x23dea0 ldr r3, [r11, r7] */
/* @0x23dea4 cmp r3, r5 */
/* @0x23dea8 bne 0x23def4 <quorem_D2A+0x148> */
/* @0x23deac ldr r2, [sp, #0xc] */
/* @0x23deb0 sub r3, r2, #4 */
/* @0x23deb4 cmp r11, r3 */
/* @0x23deb8 bhs 0x23def0 <quorem_D2A+0x144> */
/* @0x23debc ldr r3, [r2, #-0x4] */
/* @0x23dec0 cmp r3, r5 */
/* @0x23dec4 bne 0x23def0 <quorem_D2A+0x144> */
/* @0x23dec8 ldr r2, [sp, #0xc] */
/* @0x23decc sub r5, r2, #8 */
/* @0x23ded0 cmp r11, r5 */
/* @0x23ded4 mov r3, r5 */
/* @0x23ded8 sub r10, r10, #1 */
/* @0x23dedc sub r5, r5, #4 */
/* @0x23dee0 bhs 0x23def0 <quorem_D2A+0x144> */
/* @0x23dee4 ldr r3, [r3] */
/* @0x23dee8 cmp r3, #0 */
/* @0x23deec beq 0x23ded0 <quorem_D2A+0x124> */
/* @0x23def0 str r10, [r12, #0x10] */
/* @0x23def4 mov r0, r12 */
/* @0x23def8 ldr r1, [sp, #0x8] */
/* @0x23defc str r12, [sp, #0x4] */
/* @0x23df00 bl 0x23d7c8 <cmp_D2A> */
/* @0x23df04 ldr r12, [sp, #0x4] */
/* @0x23df08 cmp r0, #0 */
/* @0x23df0c blt 0x23dfc0 <quorem_D2A+0x214> */
/* @0x23df10 ldr r3, [sp, #0x10] */
/* @0x23df14 mov r4, #0 */
/* @0x23df18 str r12, [sp, #0x8] */
/* @0x23df1c mov r5, #0 */
/* @0x23df20 mov r12, r9 */
/* @0x23df24 mov r6, #1 */
/* @0x23df28 mov r9, r8 */
/* @0x23df2c mov r7, #0 */
/* @0x23df30 mov r8, r11 */
/* @0x23df34 add r3, r3, #1 */
/* @0x23df38 str r3, [sp, #0x10] */
/* @0x23df3c ldr r3, [r9], #4 */
/* @0x23df40 mov r1, #0 */
/* @0x23df44 ldr r2, [r8] */
/* @0x23df48 subs r2, r2, r3 */
/* @0x23df4c sbc r3, r2, r2 */
/* @0x23df50 subs r2, r2, r4 */
/* @0x23df54 sbc r3, r3, r5 */
/* @0x23df58 cmp r12, r9 */
/* @0x23df5c str r2, [r8], #4 */
/* @0x23df60 and r4, r3, r6 */
/* @0x23df64 and r5, r1, r7 */
/* @0x23df68 bhs 0x23df3c <quorem_D2A+0x190> */
/* @0x23df6c ldr r3, [r11, r10, lsl #2] */
/* @0x23df70 add r2, r11, r10, lsl #2 */
/* @0x23df74 ldr r12, [sp, #0x8] */
/* @0x23df78 cmp r3, r1 */
/* @0x23df7c bne 0x23dfc0 <quorem_D2A+0x214> */
/* @0x23df80 sub r3, r2, #4 */
/* @0x23df84 cmp r11, r3 */
/* @0x23df88 bhs 0x23dfbc <quorem_D2A+0x210> */
/* @0x23df8c ldr r3, [r2, #-0x4] */
/* @0x23df90 cmp r3, r1 */
/* @0x23df94 bne 0x23dfbc <quorem_D2A+0x210> */
/* @0x23df98 sub r2, r2, #8 */
/* @0x23df9c cmp r11, r2 */
/* @0x23dfa0 mov r3, r2 */
/* @0x23dfa4 sub r10, r10, #1 */
/* @0x23dfa8 sub r2, r2, #4 */
/* @0x23dfac bhs 0x23dfbc <quorem_D2A+0x210> */
/* @0x23dfb0 ldr r3, [r3] */
/* @0x23dfb4 cmp r3, #0 */
/* @0x23dfb8 beq 0x23df9c <quorem_D2A+0x1f0> */
/* @0x23dfbc str r10, [r12, #0x10] */
/* @0x23dfc0 ldr r0, [sp, #0x10] */
/* @0x23dfc4 add sp, sp, #60 */
/* @0x23dfc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x23dfcc · anon_23dfcc · size=0 · insn=1 */
/* @0x23dfcc andeq r0, r0, r0 */

/* ── FUNC 0x23dfd0 · gdtoa(FPI*, int, unsigned int*, int*, int, int, int*, char**) · size=5016 · insn=1254 */
/* @0x23dfd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23dfd4 mov r8, r0 */
/* @0x23dfd8 ldr r7, [pc, #0x598] */
/* @0x23dfdc sub sp, sp, #84 */
/* @0x23dfe0 ldr r0, [pc, #0x594] */
/* @0x23dfe4 mov r10, r1 */
/* @0x23dfe8 add r7, pc, r7 */
/* @0x23dfec str r2, [sp, #0xc] */
/* @0x23dff0 mov r4, r3 */
/* @0x23dff4 ldr r5, [r7, r0] */
/* @0x23dff8 ldr r0, [r5] */
/* @0x23dffc cmp r0, #0 */
/* @0x23e000 beq 0x23e010 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x40> */
/* @0x23e004 bl 0x23dd68 <_Z8freedtoaPc> */
/* @0x23e008 mov r3, #0 */
/* @0x23e00c str r3, [r5] */
/* @0x23e010 ldr r9, [r4] */
/* @0x23e014 and r3, r9, #7 */
/* @0x23e018 bic r2, r9, #48 */
/* @0x23e01c str r2, [r4] */
/* @0x23e020 cmp r3, #4 */
/* @0x23e024 addls pc, pc, r3, lsl #2 */
/* @0x23e028 b 0x23f360 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1390> */
/* @0x23e02c b 0x23e104 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x134> */
/* @0x23e030 b 0x23e040 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x70> */
/* @0x23e034 b 0x23e040 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x70> */
/* @0x23e038 b 0x23e154 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x184> */
/* @0x23e03c b 0x23e128 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x158> */
/* @0x23e040 ldr r11, [r8] */
/* @0x23e044 mov r0, #0 */
/* @0x23e048 cmp r11, #32 */
/* @0x23e04c ble 0x23e064 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x94> */
/* @0x23e050 mov r3, #32 */
/* @0x23e054 lsl r3, r3, #1 */
/* @0x23e058 add r0, r0, #1 */
/* @0x23e05c cmp r11, r3 */
/* @0x23e060 bgt 0x23e054 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x84> */
/* @0x23e064 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23e068 ldr r3, [sp, #0xc] */
/* @0x23e06c mov r5, r0 */
/* @0x23e070 sub r0, r11, #1 */
/* @0x23e074 add r2, r5, #20 */
/* @0x23e078 asr r0, r0, #5 */
/* @0x23e07c mov r6, r2 */
/* @0x23e080 add r0, r3, r0, lsl #2 */
/* @0x23e084 ldr r1, [r3], #4 */
/* @0x23e088 cmp r0, r3 */
/* @0x23e08c str r1, [r6], #4 */
/* @0x23e090 bhs 0x23e084 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb4> */
/* @0x23e094 rsb r6, r2, r6 */
/* @0x23e098 asr r6, r6, #2 */
/* @0x23e09c add r2, r2, r6, lsl #2 */
/* @0x23e0a0 b 0x23e0b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe0> */
/* @0x23e0a4 cmp r3, #0 */
/* @0x23e0a8 mov r6, r3 */
/* @0x23e0ac beq 0x23e2d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x304> */
/* @0x23e0b0 ldr r1, [r2, #-0x4]! */
/* @0x23e0b4 sub r3, r6, #1 */
/* @0x23e0b8 cmp r1, #0 */
/* @0x23e0bc beq 0x23e0a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd4> */
/* @0x23e0c0 add r3, r5, r6, lsl #2 */
/* @0x23e0c4 str r6, [r5, #0x10] */
/* @0x23e0c8 ldr r0, [r3, #0x10] */
/* @0x23e0cc bl 0x23d41c <hi0bits_D2A> */
/* @0x23e0d0 rsb r6, r0, r6, lsl #5 */
/* @0x23e0d4 str r6, [sp, #0x24] */
/* @0x23e0d8 mov r0, r5 */
/* @0x23e0dc bl 0x23dc44 <trailz_D2A> */
/* @0x23e0e0 cmp r0, #0 */
/* @0x23e0e4 str r0, [sp, #0x4c] */
/* @0x23e0e8 moveq r6, r10 */
/* @0x23e0ec bne 0x23e2e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x310> */
/* @0x23e0f0 ldr r3, [r5, #0x10] */
/* @0x23e0f4 mov r0, r5 */
/* @0x23e0f8 cmp r3, #0 */
/* @0x23e0fc bne 0x23e180 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1b0> */
/* @0x23e100 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e104 ldr r3, [sp, #0x80] */
/* @0x23e108 mov r2, #1 */
/* @0x23e10c ldr r0, [pc, #0x46c] */
/* @0x23e110 ldr r1, [sp, #0x84] */
/* @0x23e114 add r0, pc, r0 */
/* @0x23e118 str r2, [r3] */
/* @0x23e11c bl 0x23dd14 <nrv_alloc_D2A> */
/* @0x23e120 add sp, sp, #84 */
/* @0x23e124 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23e128 ldr lr, [sp, #0x80] */
/* @0x23e12c mov r2, #3 */
/* @0x23e130 ldr r0, [pc, #0x44c] */
/* @0x23e134 mov r3, #32768 */
/* @0x23e138 ldr r1, [sp, #0x84] */
/* @0x23e13c movt r3, #0xffff */
/* @0x23e140 add r0, pc, r0 */
/* @0x23e144 str r3, [lr] */
/* @0x23e148 bl 0x23dd14 <nrv_alloc_D2A> */
/* @0x23e14c add sp, sp, #84 */
/* @0x23e150 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23e154 ldr r2, [sp, #0x80] */
/* @0x23e158 mov r3, #32768 */
/* @0x23e15c ldr r0, [pc, #0x424] */
/* @0x23e160 movt r3, #0xffff */
/* @0x23e164 ldr r1, [sp, #0x84] */
/* @0x23e168 str r3, [r2] */
/* @0x23e16c add r0, pc, r0 */
/* @0x23e170 mov r2, #8 */
/* @0x23e174 bl 0x23dd14 <nrv_alloc_D2A> */
/* @0x23e178 add sp, sp, #84 */
/* @0x23e17c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23e180 add r1, sp, #76 */
/* @0x23e184 bl 0x23d968 <b2d_D2A> */
/* @0x23e188 vmov.f64 d4, #1.500000e+00 */
/* @0x23e18c vldr d5, [pc, #964] */
/* @0x23e190 vldr d7, [pc, #968] */
/* @0x23e194 vldr d6, [pc, #972] */
/* @0x23e198 strd r0, r1, [sp, #24] */
/* @0x23e19c ldr lr, [sp, #0x1c] */
/* @0x23e1a0 ldr r0, [sp, #0x24] */
/* @0x23e1a4 ubfx r2, lr, #0x0, #0x14 */
/* @0x23e1a8 orr r2, r2, #1069547520 */
/* @0x23e1ac add r3, r6, r0 */
/* @0x23e1b0 orr r2, r2, #3145728 */
/* @0x23e1b4 str r2, [sp, #0x1c] */
/* @0x23e1b8 vldr d2, [sp, #24] */
/* @0x23e1bc vsub.f64 d4, d2, d4 */
/* @0x23e1c0 sub r3, r3, #1 */
/* @0x23e1c4 eor r1, r3, r3, asr #31 */
/* @0x23e1c8 sub r1, r1, r3, asr #31 */
/* @0x23e1cc vmov s5, r3 */
/* @0x23e1d0 sub r1, r1, #1072 */
/* @0x23e1d4 sub r1, r1, #5 */
/* @0x23e1d8 cmp r1, #0 */
/* @0x23e1dc vmovgt s6, r1 */
/* @0x23e1e0 vmla.f64 d7, d4, d5 */
/* @0x23e1e4 vcvt.f64.s32 d5, s5 */
/* @0x23e1e8 vmla.f64 d7, d5, d6 */
/* @0x23e1ec vldrgt d6, [pc, #892] */
/* @0x23e1f0 vcvtgt.f64.s32 d5, s6 */
/* @0x23e1f4 vmlagt.f64 d7, d5, d6 */
/* @0x23e1f8 vcvt.s32.f64 s7, d7 */
/* @0x23e1fc vcmpe.f64 d7, #0 */
/* @0x23e200 vstr s7, [sp, #16] */
/* @0x23e204 vmrs APSR_nzcv, fpscr */
/* @0x23e208 bmi 0x23e938 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x968> */
/* @0x23e20c ldr r1, [sp, #0x10] */
/* @0x23e210 add r2, r2, r3, lsl #20 */
/* @0x23e214 str r2, [sp, #0x1c] */
/* @0x23e218 cmp r1, #22 */
/* @0x23e21c movhi r2, #1 */
/* @0x23e220 strhi r2, [sp, #0x40] */
/* @0x23e224 bhi 0x23e254 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x284> */
/* @0x23e228 ldr r2, [pc, #0x35c] */
/* @0x23e22c vldr d2, [sp, #24] */
/* @0x23e230 ldr r2, [r7, r2] */
/* @0x23e234 add r2, r2, r1, lsl #3 */
/* @0x23e238 vldr d7, [r2] */
/* @0x23e23c vcmpe.f64 d7, d2 */
/* @0x23e240 mov r2, #0 */
/* @0x23e244 str r2, [sp, #0x40] */
/* @0x23e248 vmrs APSR_nzcv, fpscr */
/* @0x23e24c subgt r1, r1, #1 */
/* @0x23e250 strgt r1, [sp, #0x10] */
/* @0x23e254 ldr r2, [sp, #0x24] */
/* @0x23e258 ldr lr, [sp, #0x10] */
/* @0x23e25c rsb r12, r3, r2 */
/* @0x23e260 subs r12, r12, #1 */
/* @0x23e264 rsbmi r12, r12, #0 */
/* @0x23e268 strmi r12, [sp, #0x28] */
/* @0x23e26c movpl r2, #0 */
/* @0x23e270 movmi r12, #0 */
/* @0x23e274 strpl r2, [sp, #0x28] */
/* @0x23e278 cmp lr, #0 */
/* @0x23e27c blt 0x23e914 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x944> */
/* @0x23e280 add r12, r12, lr */
/* @0x23e284 mov r2, #0 */
/* @0x23e288 str lr, [sp, #0x38] */
/* @0x23e28c str r2, [sp, #0x30] */
/* @0x23e290 ldr lr, [sp, #0x78] */
/* @0x23e294 cmp lr, #9 */
/* @0x23e298 bhi 0x23e304 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x334> */
/* @0x23e29c cmp lr, #5 */
/* @0x23e2a0 ble 0x23e30c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x33c> */
/* @0x23e2a4 mov r3, #0 */
/* @0x23e2a8 sub lr, lr, #4 */
/* @0x23e2ac str lr, [sp, #0x78] */
/* @0x23e2b0 ldr r1, [sp, #0x78] */
/* @0x23e2b4 sub r2, r1, #2 */
/* @0x23e2b8 cmp r2, #3 */
/* @0x23e2bc addls pc, pc, r2, lsl #2 */
/* @0x23e2c0 b 0x23e5dc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x60c> */
/* @0x23e2c4 b 0x23e590 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5c0> */
/* @0x23e2c8 b 0x23e328 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x358> */
/* @0x23e2cc b 0x23e5d0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x600> */
/* @0x23e2d0 b 0x23ebd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc08> */
/* @0x23e2d4 str r3, [r5, #0x10] */
/* @0x23e2d8 str r3, [sp, #0x24] */
/* @0x23e2dc b 0x23e0d8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108> */
/* @0x23e2e0 mov r1, r0 */
/* @0x23e2e4 mov r0, r5 */
/* @0x23e2e8 bl 0x23db50 <rshift_D2A> */
/* @0x23e2ec ldr r3, [sp, #0x4c] */
/* @0x23e2f0 ldr r2, [sp, #0x24] */
/* @0x23e2f4 add r6, r10, r3 */
/* @0x23e2f8 rsb r2, r3, r2 */
/* @0x23e2fc str r2, [sp, #0x24] */
/* @0x23e300 b 0x23e0f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x120> */
/* @0x23e304 mov r0, #0 */
/* @0x23e308 str r0, [sp, #0x78] */
/* @0x23e30c add r3, r3, #1020 */
/* @0x23e310 movw r2, #0x7f7 */
/* @0x23e314 add r3, r3, #2 */
/* @0x23e318 cmp r3, r2 */
/* @0x23e31c movhi r3, #0 */
/* @0x23e320 movls r3, #1 */
/* @0x23e324 b 0x23e2b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x2e0> */
/* @0x23e328 mov r0, #0 */
/* @0x23e32c str r0, [sp, #0x34] */
/* @0x23e330 ldr r2, [sp, #0x7c] */
/* @0x23e334 ldr r1, [sp, #0x10] */
/* @0x23e338 add r1, r2, r1 */
/* @0x23e33c str r1, [sp, #0x44] */
/* @0x23e340 add lr, r1, #1 */
/* @0x23e344 str lr, [sp, #0x20] */
/* @0x23e348 cmp lr, #0 */
/* @0x23e34c ble 0x23ee4c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe7c> */
/* @0x23e350 mov r0, lr */
/* @0x23e354 cmp lr, #14 */
/* @0x23e358 movhi r3, #0 */
/* @0x23e35c andls r3, r3, #1 */
/* @0x23e360 str lr, [sp, #0x4c] */
/* @0x23e364 str r3, [sp, #0x3c] */
/* @0x23e368 str r12, [sp, #0x4] */
/* @0x23e36c bl 0x23dcc4 <rv_alloc_D2A> */
/* @0x23e370 ldr r3, [r8, #0xc] */
/* @0x23e374 ldr r12, [sp, #0x4] */
/* @0x23e378 sub r3, r3, #1 */
/* @0x23e37c str r3, [sp, #0x14] */
/* @0x23e380 cmp r3, #0 */
/* @0x23e384 str r0, [sp, #0x2c] */
/* @0x23e388 beq 0x23e3a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x3d4> */
/* @0x23e38c movlt r3, #2 */
/* @0x23e390 strlt r3, [sp, #0x14] */
/* @0x23e394 tst r9, #8 */
/* @0x23e398 ldrne r3, [sp, #0x14] */
/* @0x23e39c rsbne r3, r3, #3 */
/* @0x23e3a0 strne r3, [sp, #0x14] */
/* @0x23e3a4 ldr r1, [sp, #0x3c] */
/* @0x23e3a8 cmp r1, #0 */
/* @0x23e3ac beq 0x23e624 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x654> */
/* @0x23e3b0 ldr r2, [sp, #0x14] */
/* @0x23e3b4 ldr lr, [sp, #0x10] */
/* @0x23e3b8 orrs r3, r2, lr */
/* @0x23e3bc bne 0x23e624 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x654> */
/* @0x23e3c0 ldr r2, [sp, #0x40] */
/* @0x23e3c4 vldr d3, [sp, #24] */
/* @0x23e3c8 str r3, [sp, #0x4c] */
/* @0x23e3cc cmp r2, #0 */
/* @0x23e3d0 beq 0x23e3e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x414> */
/* @0x23e3d4 vmov.f64 d7, #1.000000e+00 */
/* @0x23e3d8 vcmpe.f64 d3, d7 */
/* @0x23e3dc vmrs APSR_nzcv, fpscr */
/* @0x23e3e0 bmi 0x23f138 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1168> */
/* @0x23e3e4 vadd.f64 d6, d3, d3 */
/* @0x23e3e8 ldr r3, [sp, #0x20] */
/* @0x23e3ec cmp r3, #0 */
/* @0x23e3f0 vmov.f64 d7, #7.000000e+00 */
/* @0x23e3f4 vadd.f64 d2, d6, d7 */
/* @0x23e3f8 vstr d2, [sp, #24] */
/* @0x23e3fc ldr r0, [sp, #0x1c] */
/* @0x23e400 sub r0, r0, #54525952 */
/* @0x23e404 str r0, [sp, #0x1c] */
/* @0x23e408 beq 0x23eb04 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb34> */
/* @0x23e40c vmov.f64 d7, d3 */
/* @0x23e410 ldr r1, [sp, #0x20] */
/* @0x23e414 mov r0, #0 */
/* @0x23e418 ldr r3, [sp, #0x34] */
/* @0x23e41c cmp r3, #0 */
/* @0x23e420 beq 0x23ef40 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf70> */
/* @0x23e424 vmov.f64 d5, #5.000000e-01 */
/* @0x23e428 ldr r3, [pc, #0x15c] */
/* @0x23e42c ldr lr, [sp, #0x2c] */
/* @0x23e430 vldr d2, [sp, #24] */
/* @0x23e434 ldr r3, [r7, r3] */
/* @0x23e438 add r2, lr, #1 */
/* @0x23e43c add r3, r3, r1, lsl #3 */
/* @0x23e440 vldr d6, [r3, #-8] */
/* @0x23e444 mov r3, #0 */
/* @0x23e448 str r3, [sp, #0x4c] */
/* @0x23e44c mov r9, r2 */
/* @0x23e450 vdiv.f64 d6, d5, d6 */
/* @0x23e454 vcvt.s32.f64 s9, d7 */
/* @0x23e458 vmov lr, s9 */
/* @0x23e45c vcvt.f64.s32 d5, s9 */
/* @0x23e460 vsub.f64 d6, d6, d2 */
/* @0x23e464 vsub.f64 d7, d7, d5 */
/* @0x23e468 add r3, lr, #48 */
/* @0x23e46c ldr lr, [sp, #0x2c] */
/* @0x23e470 uxtb r3, r3 */
/* @0x23e474 strb r3, [lr] */
/* @0x23e478 vcmpe.f64 d6, d7 */
/* @0x23e47c vmrs APSR_nzcv, fpscr */
/* @0x23e480 bgt 0x23e508 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x538> */
/* @0x23e484 vmov.f64 d2, #1.000000e+00 */
/* @0x23e488 vsub.f64 d5, d2, d7 */
/* @0x23e48c vcmpe.f64 d5, d6 */
/* @0x23e490 vmrs APSR_nzcv, fpscr */
/* @0x23e494 bmi 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0> */
/* @0x23e498 ldr r3, [sp, #0x4c] */
/* @0x23e49c add r3, r3, #1 */
/* @0x23e4a0 str r3, [sp, #0x4c] */
/* @0x23e4a4 cmp r1, r3 */
/* @0x23e4a8 ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650> */
/* @0x23e4ac vmov.f64 d5, #1.000000e+01 */
/* @0x23e4b0 b 0x23e4d8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x508> */
/* @0x23e4b4 vsub.f64 d4, d2, d7 */
/* @0x23e4b8 vcmpe.f64 d4, d6 */
/* @0x23e4bc vmrs APSR_nzcv, fpscr */
/* @0x23e4c0 bmi 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0> */
/* @0x23e4c4 ldr r3, [sp, #0x4c] */
/* @0x23e4c8 add r3, r3, #1 */
/* @0x23e4cc str r3, [sp, #0x4c] */
/* @0x23e4d0 cmp r1, r3 */
/* @0x23e4d4 ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650> */
/* @0x23e4d8 vmul.f64 d7, d7, d5 */
/* @0x23e4dc vcvt.s32.f64 s8, d7 */
/* @0x23e4e0 vmov lr, s8 */
/* @0x23e4e4 vmul.f64 d6, d6, d5 */
/* @0x23e4e8 vcvt.f64.s32 d4, s8 */
/* @0x23e4ec add r3, lr, #48 */
/* @0x23e4f0 uxtb r3, r3 */
/* @0x23e4f4 strb r3, [r9], #1 */
/* @0x23e4f8 vsub.f64 d7, d7, d4 */
/* @0x23e4fc vcmpe.f64 d7, d6 */
/* @0x23e500 vmrs APSR_nzcv, fpscr */
/* @0x23e504 bpl 0x23e4b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x4e4> */
/* @0x23e508 vcmp.f64 d7, #0 */
/* @0x23e50c add r11, r0, #1 */
/* @0x23e510 vmrs APSR_nzcv, fpscr */
/* @0x23e514 beq 0x23ed24 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd54> */
/* @0x23e518 mov r10, #16 */
/* @0x23e51c mov r0, r5 */
/* @0x23e520 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e524 ldr r1, [sp, #0x80] */
/* @0x23e528 ldr r0, [sp, #0x84] */
/* @0x23e52c mov r3, #0 */
/* @0x23e530 strb r3, [r9] */
/* @0x23e534 str r11, [r1] */
/* @0x23e538 cmp r0, #0 */
/* @0x23e53c ldr r3, [r4] */
/* @0x23e540 strne r9, [r0] */
/* @0x23e544 orr r10, r3, r10 */
/* @0x23e548 ldr r0, [sp, #0x2c] */
/* @0x23e54c str r10, [r4] */
/* @0x23e550 add sp, sp, #84 */
/* @0x23e554 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23e558 .word 0x636f4361 */
/* @0x23e55c svclo #0xd287a7 */
/* @0x23e560 blhi 0x1a70834 <b2_toiTime+0x1317390> */
/* @0x23e564 svclo #0xc68a28 */
/* @0x23e568 ldrshpl r7, [pc], r11 */
/* @0x23e56c svclo #0xd34413 */
/* @0x23e570 vldmdbls sp!, {s31} */
/* @0x23e574 ldclo p13, c2, [r4], {22} */
/* @0x23e578 andseq r3, r11, r8, ror #24 */
/* @0x23e57c .word 0xfffff8b8 */
/* @0x23e580 ldrdeq r4, r5, [pc], -r8 */
/* @0x23e584 strheq r4, [pc], -r4 */
/* @0x23e588 andseq r7, r1, r0, lsl #5 */
/* @0x23e58c .word 0xfffff8bc */
/* @0x23e590 mov r0, #0 */
/* @0x23e594 str r0, [sp, #0x34] */
/* @0x23e598 ldr r1, [sp, #0x7c] */
/* @0x23e59c cmp r1, #0 */
/* @0x23e5a0 ble 0x23ee40 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe70> */
/* @0x23e5a4 cmp r1, #14 */
/* @0x23e5a8 movhi r2, #0 */
/* @0x23e5ac movls r2, #1 */
/* @0x23e5b0 ldr lr, [sp, #0x7c] */
/* @0x23e5b4 and r2, r2, r3 */
/* @0x23e5b8 str r2, [sp, #0x3c] */
/* @0x23e5bc str lr, [sp, #0x4c] */
/* @0x23e5c0 mov r0, lr */
/* @0x23e5c4 str lr, [sp, #0x44] */
/* @0x23e5c8 str lr, [sp, #0x20] */
/* @0x23e5cc b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398> */
/* @0x23e5d0 mov r2, #1 */
/* @0x23e5d4 str r2, [sp, #0x34] */
/* @0x23e5d8 b 0x23e598 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5c8> */
/* @0x23e5dc vmov s4, r11 */
/* @0x23e5e0 vldr d7, [pc, #960] */
/* @0x23e5e4 mvn r3, #0 */
/* @0x23e5e8 mov r1, #0 */
/* @0x23e5ec vcvt.f64.s32 d6, s4 */
/* @0x23e5f0 str r3, [sp, #0x44] */
/* @0x23e5f4 str r3, [sp, #0x20] */
/* @0x23e5f8 mov r3, #1 */
/* @0x23e5fc str r1, [sp, #0x3c] */
/* @0x23e600 str r1, [sp, #0x7c] */
/* @0x23e604 str r3, [sp, #0x34] */
/* @0x23e608 vmul.f64 d7, d6, d7 */
/* @0x23e60c vcvt.s32.f64 s4, d7 */
/* @0x23e610 vmov r0, s4 */
/* @0x23e614 add r0, r0, #3 */
/* @0x23e618 str r0, [sp, #0x4c] */
/* @0x23e61c b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398> */
/* @0x23e620 vstr d3, [sp, #24] */
/* @0x23e624 cmp r6, #0 */
/* @0x23e628 blt 0x23e6e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x710> */
/* @0x23e62c ldr r3, [r8, #0x14] */
/* @0x23e630 ldr r2, [sp, #0x10] */
/* @0x23e634 cmp r2, r3 */
/* @0x23e638 bgt 0x23e6e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x710> */
/* @0x23e63c ldr lr, [sp, #0x7c] */
/* @0x23e640 ldr r3, [pc, #0x368] */
/* @0x23e644 ldr r0, [sp, #0x20] */
/* @0x23e648 lsr r10, lr, #31 */
/* @0x23e64c cmp r0, #0 */
/* @0x23e650 movgt r10, #0 */
/* @0x23e654 andle r10, r10, #1 */
/* @0x23e658 ldr r3, [r7, r3] */
/* @0x23e65c cmp r10, #0 */
/* @0x23e660 add r3, r3, r2, lsl #3 */
/* @0x23e664 vldr d6, [r3] */
/* @0x23e668 beq 0x23ec74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xca4> */
/* @0x23e66c cmp r0, #0 */
/* @0x23e670 bne 0x23eb2c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb5c> */
/* @0x23e674 vmov.f64 d7, #5.000000e+00 */
/* @0x23e678 vldr d2, [sp, #24] */
/* @0x23e67c vmul.f64 d6, d6, d7 */
/* @0x23e680 vcmpe.f64 d6, d2 */
/* @0x23e684 vmrs APSR_nzcv, fpscr */
/* @0x23e688 bge 0x23f078 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10a8> */
/* @0x23e68c add r11, r2, #2 */
/* @0x23e690 mov r7, r0 */
/* @0x23e694 mov r6, r0 */
/* @0x23e698 ldr r0, [sp, #0x2c] */
/* @0x23e69c mov r2, #0 */
/* @0x23e6a0 mov r10, #32 */
/* @0x23e6a4 mov r3, #49 */
/* @0x23e6a8 add r9, r0, #1 */
/* @0x23e6ac strb r3, [r0] */
/* @0x23e6b0 mov r0, r7 */
/* @0x23e6b4 str r2, [sp, #0x4] */
/* @0x23e6b8 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e6bc cmp r6, #0 */
/* @0x23e6c0 ldr r2, [sp, #0x4] */
/* @0x23e6c4 beq 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23e6c8 cmp r2, r6 */
/* @0x23e6cc cmpne r2, #0 */
/* @0x23e6d0 bne 0x23ebcc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xbfc> */
/* @0x23e6d4 mov r0, r6 */
/* @0x23e6d8 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e6dc b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23e6e0 ldr r3, [sp, #0x34] */
/* @0x23e6e4 cmp r3, #0 */
/* @0x23e6e8 beq 0x23e954 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x984> */
/* @0x23e6ec ldr r2, [sp, #0x24] */
/* @0x23e6f0 ldr r3, [r8, #0x4] */
/* @0x23e6f4 rsb r11, r2, r11 */
/* @0x23e6f8 rsb r2, r11, r6 */
/* @0x23e6fc add r11, r11, #1 */
/* @0x23e700 cmp r2, r3 */
/* @0x23e704 str r11, [sp, #0x4c] */
/* @0x23e708 bge 0x23eb64 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb94> */
/* @0x23e70c ldr lr, [sp, #0x78] */
/* @0x23e710 cmp lr, #3 */
/* @0x23e714 cmpne lr, #5 */
/* @0x23e718 beq 0x23eb64 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb94> */
/* @0x23e71c ldr r2, [sp, #0x78] */
/* @0x23e720 rsb r3, r3, r6 */
/* @0x23e724 ldr lr, [sp, #0x20] */
/* @0x23e728 add r11, r3, #1 */
/* @0x23e72c str r11, [sp, #0x4c] */
/* @0x23e730 cmp r2, #1 */
/* @0x23e734 cmpgt lr, #0 */
/* @0x23e738 ble 0x23e748 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x778> */
/* @0x23e73c ldr r3, [sp, #0x20] */
/* @0x23e740 cmp r3, r11 */
/* @0x23e744 blt 0x23eb70 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xba0> */
/* @0x23e748 ldr r7, [sp, #0x30] */
/* @0x23e74c ldr r9, [sp, #0x28] */
/* @0x23e750 ldr r2, [sp, #0x28] */
/* @0x23e754 mov r0, #1 */
/* @0x23e758 add r12, r12, r11 */
/* @0x23e75c str r12, [sp, #0x4] */
/* @0x23e760 add r2, r2, r11 */
/* @0x23e764 str r2, [sp, #0x28] */
/* @0x23e768 bl 0x23d478 <i2b_D2A> */
/* @0x23e76c ldr r12, [sp, #0x4] */
/* @0x23e770 mov r6, r0 */
/* @0x23e774 cmp r12, #0 */
/* @0x23e778 cmpgt r9, #0 */
/* @0x23e77c ble 0x23e7a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x7d4> */
/* @0x23e780 cmp r12, r9 */
/* @0x23e784 movlt r3, r12 */
/* @0x23e788 movge r3, r9 */
/* @0x23e78c ldr r2, [sp, #0x28] */
/* @0x23e790 rsb r9, r3, r9 */
/* @0x23e794 rsb r12, r3, r12 */
/* @0x23e798 rsb r2, r3, r2 */
/* @0x23e79c str r3, [sp, #0x4c] */
/* @0x23e7a0 str r2, [sp, #0x28] */
/* @0x23e7a4 ldr r3, [sp, #0x30] */
/* @0x23e7a8 cmp r3, #0 */
/* @0x23e7ac ble 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830> */
/* @0x23e7b0 ldr r3, [sp, #0x34] */
/* @0x23e7b4 cmp r3, #0 */
/* @0x23e7b8 beq 0x23ee24 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe54> */
/* @0x23e7bc cmp r7, #0 */
/* @0x23e7c0 ble 0x23e7f4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x824> */
/* @0x23e7c4 mov r0, r6 */
/* @0x23e7c8 mov r1, r7 */
/* @0x23e7cc str r12, [sp, #0x4] */
/* @0x23e7d0 bl 0x23d5ec <pow5mult_D2A> */
/* @0x23e7d4 mov r1, r5 */
/* @0x23e7d8 mov r6, r0 */
/* @0x23e7dc bl 0x23d498 <mult_D2A> */
/* @0x23e7e0 mov r3, r0 */
/* @0x23e7e4 mov r0, r5 */
/* @0x23e7e8 mov r5, r3 */
/* @0x23e7ec bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e7f0 ldr r12, [sp, #0x4] */
/* @0x23e7f4 ldr r2, [sp, #0x30] */
/* @0x23e7f8 subs r1, r2, r7 */
/* @0x23e7fc bne 0x23eee0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf10> */
/* @0x23e800 mov r0, #1 */
/* @0x23e804 str r12, [sp, #0x4] */
/* @0x23e808 bl 0x23d478 <i2b_D2A> */
/* @0x23e80c ldr r3, [sp, #0x38] */
/* @0x23e810 ldr r12, [sp, #0x4] */
/* @0x23e814 cmp r3, #0 */
/* @0x23e818 mov r7, r0 */
/* @0x23e81c ble 0x23e830 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x860> */
/* @0x23e820 mov r1, r3 */
/* @0x23e824 bl 0x23d5ec <pow5mult_D2A> */
/* @0x23e828 ldr r12, [sp, #0x4] */
/* @0x23e82c mov r7, r0 */
/* @0x23e830 ldr lr, [sp, #0x78] */
/* @0x23e834 cmp lr, #1 */
/* @0x23e838 ble 0x23ed2c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd5c> */
/* @0x23e83c mov r8, #0 */
/* @0x23e840 ldr r2, [sp, #0x38] */
/* @0x23e844 cmp r2, #0 */
/* @0x23e848 moveq r0, #31 */
/* @0x23e84c bne 0x23ebe4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc14> */
/* @0x23e850 rsb r10, r12, r0 */
/* @0x23e854 ldr r3, [sp, #0x28] */
/* @0x23e858 sub r10, r10, #4 */
/* @0x23e85c and r10, r10, #31 */
/* @0x23e860 str r10, [sp, #0x4c] */
/* @0x23e864 add r1, r3, r10 */
/* @0x23e868 cmp r1, #0 */
/* @0x23e86c movle r1, r10 */
/* @0x23e870 ble 0x23e88c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8bc> */
/* @0x23e874 mov r0, r5 */
/* @0x23e878 str r12, [sp, #0x4] */
/* @0x23e87c bl 0x23d6cc <lshift_D2A> */
/* @0x23e880 ldr r1, [sp, #0x4c] */
/* @0x23e884 ldr r12, [sp, #0x4] */
/* @0x23e888 mov r5, r0 */
/* @0x23e88c add r1, r12, r1 */
/* @0x23e890 cmp r1, #0 */
/* @0x23e894 ble 0x23e8a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8d4> */
/* @0x23e898 mov r0, r7 */
/* @0x23e89c bl 0x23d6cc <lshift_D2A> */
/* @0x23e8a0 mov r7, r0 */
/* @0x23e8a4 ldr r2, [sp, #0x40] */
/* @0x23e8a8 cmp r2, #0 */
/* @0x23e8ac bne 0x23ec00 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc30> */
/* @0x23e8b0 ldr r1, [sp, #0x20] */
/* @0x23e8b4 ldr r2, [sp, #0x78] */
/* @0x23e8b8 cmp r1, #0 */
/* @0x23e8bc movgt r3, #0 */
/* @0x23e8c0 movle r3, #1 */
/* @0x23e8c4 cmp r2, #2 */
/* @0x23e8c8 movle r3, #0 */
/* @0x23e8cc cmp r3, #0 */
/* @0x23e8d0 beq 0x23e964 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x994> */
/* @0x23e8d4 ldr r3, [sp, #0x20] */
/* @0x23e8d8 cmp r3, #0 */
/* @0x23e8dc bne 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64> */
/* @0x23e8e0 mov r0, r7 */
/* @0x23e8e4 mov r2, r3 */
/* @0x23e8e8 mov r1, #5 */
/* @0x23e8ec bl 0x23d368 <multadd_D2A> */
/* @0x23e8f0 mov r7, r0 */
/* @0x23e8f4 mov r0, r5 */
/* @0x23e8f8 mov r1, r7 */
/* @0x23e8fc bl 0x23d7c8 <cmp_D2A> */
/* @0x23e900 cmp r0, #0 */
/* @0x23e904 ble 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64> */
/* @0x23e908 ldr r3, [sp, #0x10] */
/* @0x23e90c add r11, r3, #2 */
/* @0x23e910 b 0x23e698 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6c8> */
/* @0x23e914 ldr r2, [sp, #0x28] */
/* @0x23e918 ldr lr, [sp, #0x10] */
/* @0x23e91c rsb r2, lr, r2 */
/* @0x23e920 str r2, [sp, #0x28] */
/* @0x23e924 rsb r2, lr, #0 */
/* @0x23e928 str r2, [sp, #0x30] */
/* @0x23e92c mov r2, #0 */
/* @0x23e930 str r2, [sp, #0x38] */
/* @0x23e934 b 0x23e290 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x2c0> */
/* @0x23e938 vcvt.f64.s32 d6, s7 */
/* @0x23e93c vcmp.f64 d6, d7 */
/* @0x23e940 vmrs APSR_nzcv, fpscr */
/* @0x23e944 vmovne r0, s7 */
/* @0x23e948 subne r0, r0, #1 */
/* @0x23e94c strne r0, [sp, #0x10] */
/* @0x23e950 b 0x23e20c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x23c> */
/* @0x23e954 ldr r7, [sp, #0x30] */
/* @0x23e958 ldr r9, [sp, #0x28] */
/* @0x23e95c ldr r6, [sp, #0x34] */
/* @0x23e960 b 0x23e774 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x7a4> */
/* @0x23e964 ldr r3, [sp, #0x34] */
/* @0x23e968 cmp r3, #0 */
/* @0x23e96c beq 0x23ed60 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd90> */
/* @0x23e970 add r1, r9, r10 */
/* @0x23e974 cmp r1, #0 */
/* @0x23e978 ble 0x23e988 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9b8> */
/* @0x23e97c mov r0, r6 */
/* @0x23e980 bl 0x23d6cc <lshift_D2A> */
/* @0x23e984 mov r6, r0 */
/* @0x23e988 cmp r8, #0 */
/* @0x23e98c moveq r8, r6 */
/* @0x23e990 bne 0x23f100 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1130> */
/* @0x23e994 mov r3, #1 */
/* @0x23e998 ldr r9, [sp, #0x2c] */
/* @0x23e99c str r3, [sp, #0x4c] */
/* @0x23e9a0 str r4, [sp, #0x18] */
/* @0x23e9a4 b 0x23ea84 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xab4> */
/* @0x23e9a8 strbpl r5, [r7, #-0xa32] */
/* @0x23e9ac svclo #0xd34413 */
/* @0x23e9b0 .word 0xfffff8bc */
/* @0x23e9b4 mov r0, r3 */
/* @0x23e9b8 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23e9bc ldr r0, [sp, #0x78] */
/* @0x23e9c0 orrs r0, r4, r0 */
/* @0x23e9c4 bne 0x23e9e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa14> */
/* @0x23e9c8 ldr r1, [sp, #0xc] */
/* @0x23e9cc ldr r3, [r1] */
/* @0x23e9d0 tst r3, #1 */
/* @0x23e9d4 bne 0x23e9e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa14> */
/* @0x23e9d8 ldr r3, [sp, #0x14] */
/* @0x23e9dc cmp r3, #0 */
/* @0x23e9e0 beq 0x23f2b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12e0> */
/* @0x23e9e4 cmp r10, #0 */
/* @0x23e9e8 blt 0x23efc4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xff4> */
/* @0x23e9ec ldr lr, [sp, #0x78] */
/* @0x23e9f0 orrs lr, r10, lr */
/* @0x23e9f4 bne 0x23ea08 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa38> */
/* @0x23e9f8 ldr r0, [sp, #0xc] */
/* @0x23e9fc ldr r3, [r0] */
/* @0x23ea00 tst r3, #1 */
/* @0x23ea04 beq 0x23efc4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xff4> */
/* @0x23ea08 ldr r3, [sp, #0x14] */
/* @0x23ea0c cmp r3, #2 */
/* @0x23ea10 cmpne r4, #0 */
/* @0x23ea14 movle r4, #0 */
/* @0x23ea18 movgt r4, #1 */
/* @0x23ea1c bgt 0x23f194 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11c4> */
/* @0x23ea20 strb r11, [r9], #1 */
/* @0x23ea24 ldr r3, [sp, #0x4c] */
/* @0x23ea28 ldr lr, [sp, #0x20] */
/* @0x23ea2c cmp r3, lr */
/* @0x23ea30 beq 0x23f184 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11b4> */
/* @0x23ea34 mov r0, r5 */
/* @0x23ea38 mov r1, #10 */
/* @0x23ea3c mov r2, r4 */
/* @0x23ea40 bl 0x23d368 <multadd_D2A> */
/* @0x23ea44 cmp r6, r8 */
/* @0x23ea48 mov r5, r0 */
/* @0x23ea4c mov r0, r6 */
/* @0x23ea50 beq 0x23eb4c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb7c> */
/* @0x23ea54 mov r1, #10 */
/* @0x23ea58 mov r2, r4 */
/* @0x23ea5c bl 0x23d368 <multadd_D2A> */
/* @0x23ea60 mov r2, r4 */
/* @0x23ea64 mov r1, #10 */
/* @0x23ea68 mov r6, r0 */
/* @0x23ea6c mov r0, r8 */
/* @0x23ea70 bl 0x23d368 <multadd_D2A> */
/* @0x23ea74 mov r8, r0 */
/* @0x23ea78 ldr r3, [sp, #0x4c] */
/* @0x23ea7c add r3, r3, #1 */
/* @0x23ea80 str r3, [sp, #0x4c] */
/* @0x23ea84 mov r1, r7 */
/* @0x23ea88 mov r0, r5 */
/* @0x23ea8c bl 0x23ddac <quorem_D2A> */
/* @0x23ea90 mov r1, r6 */
/* @0x23ea94 str r0, [sp, #0x8] */
/* @0x23ea98 mov r0, r5 */
/* @0x23ea9c bl 0x23d7c8 <cmp_D2A> */
/* @0x23eaa0 mov r1, r8 */
/* @0x23eaa4 mov r10, r0 */
/* @0x23eaa8 mov r0, r7 */
/* @0x23eaac bl 0x23d828 <diff_D2A> */
/* @0x23eab0 ldr lr, [sp, #0x8] */
/* @0x23eab4 add r11, lr, #48 */
/* @0x23eab8 ldr r2, [r0, #0xc] */
/* @0x23eabc mov r3, r0 */
/* @0x23eac0 cmp r2, #0 */
/* @0x23eac4 movne r4, #1 */
/* @0x23eac8 bne 0x23e9b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9e4> */
/* @0x23eacc mov r1, r3 */
/* @0x23ead0 mov r0, r5 */
/* @0x23ead4 str r3, [sp, #0x4] */
/* @0x23ead8 bl 0x23d7c8 <cmp_D2A> */
/* @0x23eadc ldr r3, [sp, #0x4] */
/* @0x23eae0 mov r4, r0 */
/* @0x23eae4 b 0x23e9b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9e4> */
/* @0x23eae8 vadd.f64 d6, d3, d3 */
/* @0x23eaec vmov.f64 d7, #7.000000e+00 */
/* @0x23eaf0 vadd.f64 d2, d6, d7 */
/* @0x23eaf4 vstr d2, [sp, #24] */
/* @0x23eaf8 ldr r0, [sp, #0x1c] */
/* @0x23eafc sub r0, r0, #54525952 */
/* @0x23eb00 str r0, [sp, #0x1c] */
/* @0x23eb04 vmov.f64 d7, #5.000000e+00 */
/* @0x23eb08 vldr d6, [sp, #24] */
/* @0x23eb0c vsub.f64 d7, d3, d7 */
/* @0x23eb10 vcmpe.f64 d7, d6 */
/* @0x23eb14 vmrs APSR_nzcv, fpscr */
/* @0x23eb18 bgt 0x23ef30 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf60> */
/* @0x23eb1c vneg.f64 d6, d6 */
/* @0x23eb20 vcmpe.f64 d7, d6 */
/* @0x23eb24 vmrs APSR_nzcv, fpscr */
/* @0x23eb28 bpl 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650> */
/* @0x23eb2c mov r7, #0 */
/* @0x23eb30 mov r6, r7 */
/* @0x23eb34 ldr lr, [sp, #0x7c] */
/* @0x23eb38 mov r2, #0 */
/* @0x23eb3c ldr r9, [sp, #0x2c] */
/* @0x23eb40 mov r10, #16 */
/* @0x23eb44 rsb r11, lr, #0 */
/* @0x23eb48 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23eb4c mov r2, r4 */
/* @0x23eb50 mov r1, #10 */
/* @0x23eb54 bl 0x23d368 <multadd_D2A> */
/* @0x23eb58 mov r6, r0 */
/* @0x23eb5c mov r8, r0 */
/* @0x23eb60 b 0x23ea78 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xaa8> */
/* @0x23eb64 ldr r1, [sp, #0x78] */
/* @0x23eb68 cmp r1, #1 */
/* @0x23eb6c ble 0x23e748 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x778> */
/* @0x23eb70 ldr r3, [sp, #0x20] */
/* @0x23eb74 ldr r2, [sp, #0x30] */
/* @0x23eb78 sub r7, r3, #1 */
/* @0x23eb7c cmp r2, r7 */
/* @0x23eb80 rsbge r7, r7, r2 */
/* @0x23eb84 ldrlt r2, [sp, #0x30] */
/* @0x23eb88 strlt r7, [sp, #0x30] */
/* @0x23eb8c rsblt r3, r2, r7 */
/* @0x23eb90 ldrlt r2, [sp, #0x38] */
/* @0x23eb94 movlt r7, #0 */
/* @0x23eb98 addlt r2, r2, r3 */
/* @0x23eb9c ldr r3, [sp, #0x20] */
/* @0x23eba0 strlt r2, [sp, #0x38] */
/* @0x23eba4 cmp r3, #0 */
/* @0x23eba8 strge r3, [sp, #0x4c] */
/* @0x23ebac ldrlt r2, [sp, #0x28] */
/* @0x23ebb0 movlt r11, #0 */
/* @0x23ebb4 ldrlt r3, [sp, #0x20] */
/* @0x23ebb8 movge r11, r3 */
/* @0x23ebbc ldrge r9, [sp, #0x28] */
/* @0x23ebc0 rsblt r9, r3, r2 */
/* @0x23ebc4 strlt r11, [sp, #0x4c] */
/* @0x23ebc8 b 0x23e750 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x780> */
/* @0x23ebcc mov r0, r2 */
/* @0x23ebd0 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23ebd4 b 0x23e6d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x704> */
/* @0x23ebd8 mov lr, #1 */
/* @0x23ebdc str lr, [sp, #0x34] */
/* @0x23ebe0 b 0x23e330 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x360> */
/* @0x23ebe4 ldr r3, [r7, #0x10] */
/* @0x23ebe8 add r3, r7, r3, lsl #2 */
/* @0x23ebec ldr r0, [r3, #0x10] */
/* @0x23ebf0 str r12, [sp, #0x4] */
/* @0x23ebf4 bl 0x23d41c <hi0bits_D2A> */
/* @0x23ebf8 ldr r12, [sp, #0x4] */
/* @0x23ebfc b 0x23e850 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x880> */
/* @0x23ec00 mov r0, r5 */
/* @0x23ec04 mov r1, r7 */
/* @0x23ec08 bl 0x23d7c8 <cmp_D2A> */
/* @0x23ec0c cmp r0, #0 */
/* @0x23ec10 bge 0x23e8b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8e0> */
/* @0x23ec14 ldr r3, [sp, #0x10] */
/* @0x23ec18 mov r0, r5 */
/* @0x23ec1c mov r1, #10 */
/* @0x23ec20 mov r2, #0 */
/* @0x23ec24 sub r3, r3, #1 */
/* @0x23ec28 str r3, [sp, #0x10] */
/* @0x23ec2c bl 0x23d368 <multadd_D2A> */
/* @0x23ec30 ldr r3, [sp, #0x34] */
/* @0x23ec34 cmp r3, #0 */
/* @0x23ec38 mov r5, r0 */
/* @0x23ec3c bne 0x23f300 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1330> */
/* @0x23ec40 ldr r0, [sp, #0x44] */
/* @0x23ec44 ldr r1, [sp, #0x78] */
/* @0x23ec48 cmp r0, #0 */
/* @0x23ec4c movgt r3, #0 */
/* @0x23ec50 movle r3, #1 */
/* @0x23ec54 cmp r1, #2 */
/* @0x23ec58 movle r3, #0 */
/* @0x23ec5c cmp r3, #0 */
/* @0x23ec60 streq r0, [sp, #0x20] */
/* @0x23ec64 beq 0x23ed60 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd90> */
/* @0x23ec68 ldr r3, [sp, #0x44] */
/* @0x23ec6c str r3, [sp, #0x20] */
/* @0x23ec70 b 0x23e8d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x904> */
/* @0x23ec74 vldr d7, [sp, #24] */
/* @0x23ec78 vdiv.f64 d5, d7, d6 */
/* @0x23ec7c ldr r0, [sp, #0x2c] */
/* @0x23ec80 ldr r3, [sp, #0x2c] */
/* @0x23ec84 add r9, r3, #1 */
/* @0x23ec88 mov r3, #1 */
/* @0x23ec8c str r3, [sp, #0x4c] */
/* @0x23ec90 mov r2, r9 */
/* @0x23ec94 vcvt.s32.f64 s7, d5 */
/* @0x23ec98 vcvt.f64.s32 d4, s7 */
/* @0x23ec9c vmov lr, s7 */
/* @0x23eca0 vmls.f64 d7, d4, d6 */
/* @0x23eca4 add r3, lr, #48 */
/* @0x23eca8 strb r3, [r0] */
/* @0x23ecac vcmp.f64 d7, #0 */
/* @0x23ecb0 vmrs APSR_nzcv, fpscr */
/* @0x23ecb4 ldreq r3, [sp, #0x10] */
/* @0x23ecb8 addeq r11, r3, #1 */
/* @0x23ecbc beq 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23ecc0 ldr r3, [sp, #0x4c] */
/* @0x23ecc4 ldr lr, [sp, #0x20] */
/* @0x23ecc8 cmp lr, r3 */
/* @0x23eccc vmovne.f64 d4, #1.000000e+01 */
/* @0x23ecd0 ldrne r1, [sp, #0x20] */
/* @0x23ecd4 bne 0x23ece8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd18> */
/* @0x23ecd8 b 0x23eef8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf28> */
/* @0x23ecdc ldr r3, [sp, #0x4c] */
/* @0x23ece0 cmp r1, r3 */
/* @0x23ece4 beq 0x23eef8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf28> */
/* @0x23ece8 vmul.f64 d7, d7, d4 */
/* @0x23ecec add r3, r3, #1 */
/* @0x23ecf0 str r3, [sp, #0x4c] */
/* @0x23ecf4 vdiv.f64 d5, d7, d6 */
/* @0x23ecf8 vcvt.s32.f64 s7, d5 */
/* @0x23ecfc vcvt.f64.s32 d5, s7 */
/* @0x23ed00 vmov r0, s7 */
/* @0x23ed04 vmls.f64 d7, d5, d6 */
/* @0x23ed08 add r3, r0, #48 */
/* @0x23ed0c strb r3, [r9], #1 */
/* @0x23ed10 vcmp.f64 d7, #0 */
/* @0x23ed14 vmrs APSR_nzcv, fpscr */
/* @0x23ed18 bne 0x23ecdc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd0c> */
/* @0x23ed1c ldr r3, [sp, #0x10] */
/* @0x23ed20 add r11, r3, #1 */
/* @0x23ed24 mov r10, #0 */
/* @0x23ed28 b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23ed2c ldr r2, [sp, #0x24] */
/* @0x23ed30 cmp r2, #1 */
/* @0x23ed34 bne 0x23e83c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x86c> */
/* @0x23ed38 ldr r3, [r8, #0x4] */
/* @0x23ed3c add r3, r3, #1 */
/* @0x23ed40 cmp r10, r3 */
/* @0x23ed44 ble 0x23e83c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x86c> */
/* @0x23ed48 ldr r3, [sp, #0x28] */
/* @0x23ed4c add r12, r12, #1 */
/* @0x23ed50 mov r8, r2 */
/* @0x23ed54 add r3, r3, #1 */
/* @0x23ed58 str r3, [sp, #0x28] */
/* @0x23ed5c b 0x23e840 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x870> */
/* @0x23ed60 mov r3, #1 */
/* @0x23ed64 ldr r9, [sp, #0x2c] */
/* @0x23ed68 str r3, [sp, #0x4c] */
/* @0x23ed6c ldr r8, [sp, #0x20] */
/* @0x23ed70 b 0x23ed88 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xdb8> */
/* @0x23ed74 bl 0x23d368 <multadd_D2A> */
/* @0x23ed78 ldr r3, [sp, #0x4c] */
/* @0x23ed7c add r3, r3, #1 */
/* @0x23ed80 str r3, [sp, #0x4c] */
/* @0x23ed84 mov r5, r0 */
/* @0x23ed88 mov r1, r7 */
/* @0x23ed8c mov r0, r5 */
/* @0x23ed90 bl 0x23ddac <quorem_D2A> */
/* @0x23ed94 mov r1, #10 */
/* @0x23ed98 mov r2, #0 */
/* @0x23ed9c add r11, r0, #48 */
/* @0x23eda0 strb r11, [r9], #1 */
/* @0x23eda4 ldr r3, [sp, #0x4c] */
/* @0x23eda8 mov r0, r5 */
/* @0x23edac cmp r8, r3 */
/* @0x23edb0 bgt 0x23ed74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xda4> */
/* @0x23edb4 mov r2, #0 */
/* @0x23edb8 ldr r3, [sp, #0x14] */
/* @0x23edbc cmp r3, #0 */
/* @0x23edc0 beq 0x23f084 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10b4> */
/* @0x23edc4 cmp r3, #2 */
/* @0x23edc8 beq 0x23f0b8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10e8> */
/* @0x23edcc ldr r3, [r5, #0x10] */
/* @0x23edd0 cmp r3, #1 */
/* @0x23edd4 ble 0x23f258 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1288> */
/* @0x23edd8 ldrb r1, [r9, #-0x1] */
/* @0x23eddc ldr lr, [sp, #0x2c] */
/* @0x23ede0 mov r3, r9 */
/* @0x23ede4 add r12, lr, #1 */
/* @0x23ede8 b 0x23edfc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe2c> */
/* @0x23edec cmp r9, r12 */
/* @0x23edf0 beq 0x23ef18 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf48> */
/* @0x23edf4 ldrb r1, [r3, #-0x2] */
/* @0x23edf8 mov r3, r0 */
/* @0x23edfc cmp r1, #57 */
/* @0x23ee00 mov r9, r3 */
/* @0x23ee04 sub r0, r3, #1 */
/* @0x23ee08 beq 0x23edec <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe1c> */
/* @0x23ee0c ldr r3, [sp, #0x10] */
/* @0x23ee10 add r1, r1, #1 */
/* @0x23ee14 mov r10, #32 */
/* @0x23ee18 strb r1, [r0] */
/* @0x23ee1c add r11, r3, #1 */
/* @0x23ee20 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23ee24 mov r0, r5 */
/* @0x23ee28 ldr r1, [sp, #0x30] */
/* @0x23ee2c str r12, [sp, #0x4] */
/* @0x23ee30 bl 0x23d5ec <pow5mult_D2A> */
/* @0x23ee34 ldr r12, [sp, #0x4] */
/* @0x23ee38 mov r5, r0 */
/* @0x23ee3c b 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830> */
/* @0x23ee40 mov r2, #1 */
/* @0x23ee44 str r2, [sp, #0x7c] */
/* @0x23ee48 b 0x23e5b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5e0> */
/* @0x23ee4c ldr r0, [sp, #0x20] */
/* @0x23ee50 cmp r0, #14 */
/* @0x23ee54 movhi r3, #0 */
/* @0x23ee58 andls r3, r3, #1 */
/* @0x23ee5c str r3, [sp, #0x3c] */
/* @0x23ee60 mov r3, #1 */
/* @0x23ee64 str r3, [sp, #0x4c] */
/* @0x23ee68 mov r0, r3 */
/* @0x23ee6c b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398> */
/* @0x23ee70 vadd.f64 d7, d7, d7 */
/* @0x23ee74 vcmpe.f64 d6, d7 */
/* @0x23ee78 vmrs APSR_nzcv, fpscr */
/* @0x23ee7c bmi 0x23f234 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1264> */
/* @0x23ee80 vcmp.f64 d6, d7 */
/* @0x23ee84 vmrs APSR_nzcv, fpscr */
/* @0x23ee88 bne 0x23f2a0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12d0> */
/* @0x23ee8c vmov lr, s7 */
/* @0x23ee90 tst lr, #1 */
/* @0x23ee94 beq 0x23f2a0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12d0> */
/* @0x23ee98 ldrb r3, [r9, #-0x1] */
/* @0x23ee9c ldr r0, [sp, #0x10] */
/* @0x23eea0 mov r1, r9 */
/* @0x23eea4 b 0x23eeb8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xee8> */
/* @0x23eea8 cmp r9, r2 */
/* @0x23eeac beq 0x23f0ec <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x111c> */
/* @0x23eeb0 ldrb r3, [r1, #-0x2] */
/* @0x23eeb4 mov r1, r12 */
/* @0x23eeb8 cmp r3, #57 */
/* @0x23eebc mov r9, r1 */
/* @0x23eec0 sub r12, r1, #1 */
/* @0x23eec4 beq 0x23eea8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed8> */
/* @0x23eec8 add r3, r3, #1 */
/* @0x23eecc uxtb r3, r3 */
/* @0x23eed0 strb r3, [r12] */
/* @0x23eed4 add r11, r0, #1 */
/* @0x23eed8 mov r10, #32 */
/* @0x23eedc b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23eee0 mov r0, r5 */
/* @0x23eee4 str r12, [sp, #0x4] */
/* @0x23eee8 bl 0x23d5ec <pow5mult_D2A> */
/* @0x23eeec ldr r12, [sp, #0x4] */
/* @0x23eef0 mov r5, r0 */
/* @0x23eef4 b 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830> */
/* @0x23eef8 ldr r3, [sp, #0x14] */
/* @0x23eefc cmp r3, #0 */
/* @0x23ef00 beq 0x23ee70 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xea0> */
/* @0x23ef04 cmp r3, #1 */
/* @0x23ef08 beq 0x23f234 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1264> */
/* @0x23ef0c ldr r3, [sp, #0x10] */
/* @0x23ef10 add r11, r3, #1 */
/* @0x23ef14 b 0x23e518 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x548> */
/* @0x23ef18 ldr r3, [sp, #0x10] */
/* @0x23ef1c mov r10, #32 */
/* @0x23ef20 add r11, r3, #2 */
/* @0x23ef24 mov r3, #49 */
/* @0x23ef28 strb r3, [r0] */
/* @0x23ef2c b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23ef30 mov r7, #0 */
/* @0x23ef34 mov r11, #2 */
/* @0x23ef38 mov r6, r7 */
/* @0x23ef3c b 0x23e698 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6c8> */
/* @0x23ef40 ldr r3, [pc, #-0x598] */
/* @0x23ef44 mov r2, #1 */
/* @0x23ef48 vldr d2, [sp, #24] */
/* @0x23ef4c vmov.f64 d6, #1.000000e+01 */
/* @0x23ef50 ldr r9, [sp, #0x2c] */
/* @0x23ef54 ldr r3, [r7, r3] */
/* @0x23ef58 str r2, [sp, #0x4c] */
/* @0x23ef5c add r3, r3, r1, lsl #3 */
/* @0x23ef60 vldr d4, [r3, #-8] */
/* @0x23ef64 vmul.f64 d4, d4, d2 */
/* @0x23ef68 b 0x23ef74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xfa4> */
/* @0x23ef6c vmul.f64 d7, d7, d6 */
/* @0x23ef70 str r2, [sp, #0x4c] */
/* @0x23ef74 vcvt.s32.f64 s5, d7 */
/* @0x23ef78 vmov r2, s5 */
/* @0x23ef7c cmp r2, #0 */
/* @0x23ef80 add r3, r2, #48 */
/* @0x23ef84 vcvtne.f64.s32 d5, s5 */
/* @0x23ef88 uxtb r3, r3 */
/* @0x23ef8c strb r3, [r9], #1 */
/* @0x23ef90 ldr r2, [sp, #0x4c] */
/* @0x23ef94 vsubne.f64 d7, d7, d5 */
/* @0x23ef98 cmp r2, r1 */
/* @0x23ef9c add r2, r2, #1 */
/* @0x23efa0 bne 0x23ef6c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf9c> */
/* @0x23efa4 vmov.f64 d6, #5.000000e-01 */
/* @0x23efa8 vadd.f64 d5, d4, d6 */
/* @0x23efac vcmpe.f64 d5, d7 */
/* @0x23efb0 vmrs APSR_nzcv, fpscr */
/* @0x23efb4 bpl 0x23f1f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1220> */
/* @0x23efb8 ldr r1, [sp, #0x2c] */
/* @0x23efbc add r2, r1, #1 */
/* @0x23efc0 b 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0> */
/* @0x23efc4 ldr r3, [sp, #0x14] */
/* @0x23efc8 mov r2, r4 */
/* @0x23efcc ldr r4, [sp, #0x18] */
/* @0x23efd0 cmp r3, #0 */
/* @0x23efd4 beq 0x23f1d0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1200> */
/* @0x23efd8 ldr r1, [r5, #0x10] */
/* @0x23efdc cmp r1, #1 */
/* @0x23efe0 ble 0x23f1c4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11f4> */
/* @0x23efe4 ldr r3, [sp, #0x14] */
/* @0x23efe8 cmp r3, #2 */
/* @0x23efec bne 0x23f02c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x105c> */
/* @0x23eff0 b 0x23f1e8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1218> */
/* @0x23eff4 strb r11, [r9], #1 */
/* @0x23eff8 bl 0x23d368 <multadd_D2A> */
/* @0x23effc cmp r6, r8 */
/* @0x23f000 mov r1, #10 */
/* @0x23f004 mov r2, #0 */
/* @0x23f008 mov r10, r0 */
/* @0x23f00c mov r0, r5 */
/* @0x23f010 moveq r6, r10 */
/* @0x23f014 bl 0x23d368 <multadd_D2A> */
/* @0x23f018 mov r1, r7 */
/* @0x23f01c mov r8, r10 */
/* @0x23f020 mov r5, r0 */
/* @0x23f024 bl 0x23ddac <quorem_D2A> */
/* @0x23f028 add r11, r0, #48 */
/* @0x23f02c mov r1, r8 */
/* @0x23f030 mov r0, r7 */
/* @0x23f034 bl 0x23d7c8 <cmp_D2A> */
/* @0x23f038 mov r2, #0 */
/* @0x23f03c mov r1, #10 */
/* @0x23f040 cmp r0, r2 */
/* @0x23f044 mov r0, r8 */
/* @0x23f048 bgt 0x23eff4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1024> */
/* @0x23f04c cmp r11, #57 */
/* @0x23f050 beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270> */
/* @0x23f054 add r11, r11, #1 */
/* @0x23f058 mov r10, #32 */
/* @0x23f05c strb r11, [r9] */
/* @0x23f060 mov r2, r6 */
/* @0x23f064 ldr r3, [sp, #0x10] */
/* @0x23f068 add r9, r9, #1 */
/* @0x23f06c mov r6, r8 */
/* @0x23f070 add r11, r3, #1 */
/* @0x23f074 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23f078 ldr r7, [sp, #0x20] */
/* @0x23f07c mov r6, r7 */
/* @0x23f080 b 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64> */
/* @0x23f084 mov r0, r5 */
/* @0x23f088 mov r1, #1 */
/* @0x23f08c str r2, [sp, #0x4] */
/* @0x23f090 bl 0x23d6cc <lshift_D2A> */
/* @0x23f094 mov r1, r7 */
/* @0x23f098 mov r5, r0 */
/* @0x23f09c bl 0x23d7c8 <cmp_D2A> */
/* @0x23f0a0 ldr r2, [sp, #0x4] */
/* @0x23f0a4 cmp r0, #0 */
/* @0x23f0a8 bgt 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08> */
/* @0x23f0ac bne 0x23f0b8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10e8> */
/* @0x23f0b0 tst r11, #1 */
/* @0x23f0b4 bne 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08> */
/* @0x23f0b8 ldr r3, [r5, #0x10] */
/* @0x23f0bc cmp r3, #1 */
/* @0x23f0c0 ble 0x23f350 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1380> */
/* @0x23f0c4 mov r10, #16 */
/* @0x23f0c8 mov r3, r9 */
/* @0x23f0cc mov r9, r3 */
/* @0x23f0d0 sub r3, r3, #1 */
/* @0x23f0d4 ldrb r1, [r9, #-0x1] */
/* @0x23f0d8 cmp r1, #48 */
/* @0x23f0dc beq 0x23f0cc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10fc> */
/* @0x23f0e0 ldr r3, [sp, #0x10] */
/* @0x23f0e4 add r11, r3, #1 */
/* @0x23f0e8 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23f0ec mov r2, #48 */
/* @0x23f0f0 add r0, r0, #1 */
/* @0x23f0f4 mov r3, #49 */
/* @0x23f0f8 strb r2, [r12] */
/* @0x23f0fc b 0x23eed0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf00> */
/* @0x23f100 ldr r0, [r6, #0x4] */
/* @0x23f104 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23f108 ldr r2, [r6, #0x10] */
/* @0x23f10c add r1, r6, #12 */
/* @0x23f110 lsl r2, r2, #2 */
/* @0x23f114 add r2, r2, #8 */
/* @0x23f118 mov r8, r0 */
/* @0x23f11c add r0, r0, #12 */
/* @0x23f120 bl 0xb65bc <memcpy@plt> */
/* @0x23f124 mov r0, r8 */
/* @0x23f128 mov r1, #1 */
/* @0x23f12c bl 0x23d6cc <lshift_D2A> */
/* @0x23f130 mov r8, r0 */
/* @0x23f134 b 0x23e994 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9c4> */
/* @0x23f138 ldr r3, [sp, #0x20] */
/* @0x23f13c cmp r3, #0 */
/* @0x23f140 beq 0x23eae8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb18> */
/* @0x23f144 ldr r3, [sp, #0x44] */
/* @0x23f148 cmp r3, #0 */
/* @0x23f14c ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650> */
/* @0x23f150 vmov.f64 d7, #1.000000e+01 */
/* @0x23f154 mov r1, r3 */
/* @0x23f158 mvn r0, #0 */
/* @0x23f15c vmul.f64 d7, d3, d7 */
/* @0x23f160 vmov.f64 d6, #7.000000e+00 */
/* @0x23f164 vmov.f64 d5, #3.000000e+00 */
/* @0x23f168 vmov.f64 d2, d6 */
/* @0x23f16c vmla.f64 d2, d7, d5 */
/* @0x23f170 vstr d2, [sp, #24] */
/* @0x23f174 ldr r2, [sp, #0x1c] */
/* @0x23f178 sub r2, r2, #54525952 */
/* @0x23f17c str r2, [sp, #0x1c] */
/* @0x23f180 b 0x23e418 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x448> */
/* @0x23f184 mov r2, r6 */
/* @0x23f188 ldr r4, [sp, #0x18] */
/* @0x23f18c mov r6, r8 */
/* @0x23f190 b 0x23edb8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xde8> */
/* @0x23f194 cmp r11, #57 */
/* @0x23f198 ldr r4, [sp, #0x18] */
/* @0x23f19c beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270> */
/* @0x23f1a0 add r3, r11, #1 */
/* @0x23f1a4 strb r3, [r9] */
/* @0x23f1a8 ldr r3, [sp, #0x10] */
/* @0x23f1ac mov r2, r6 */
/* @0x23f1b0 add r9, r9, #1 */
/* @0x23f1b4 mov r6, r8 */
/* @0x23f1b8 add r11, r3, #1 */
/* @0x23f1bc mov r10, #32 */
/* @0x23f1c0 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0> */
/* @0x23f1c4 ldr r1, [r5, #0x14] */
/* @0x23f1c8 cmp r1, #0 */
/* @0x23f1cc bne 0x23efe4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1014> */
/* @0x23f1d0 cmp r2, #0 */
/* @0x23f1d4 bgt 0x23f268 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1298> */
/* @0x23f1d8 mov r10, #0 */
/* @0x23f1dc ldr r2, [r5, #0x10] */
/* @0x23f1e0 cmp r2, #1 */
/* @0x23f1e4 ble 0x23f2f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1320> */
/* @0x23f1e8 mov r10, #16 */
/* @0x23f1ec b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c> */
/* @0x23f1f0 vsub.f64 d6, d6, d4 */
/* @0x23f1f4 vcmpe.f64 d6, d7 */
/* @0x23f1f8 vmrs APSR_nzcv, fpscr */
/* @0x23f1fc ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650> */
/* @0x23f200 vcmp.f64 d7, #0 */
/* @0x23f204 vmrs APSR_nzcv, fpscr */
/* @0x23f208 movne r10, #16 */
/* @0x23f20c moveq r10, #0 */
/* @0x23f210 mov r2, r9 */
/* @0x23f214 b 0x23f220 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1250> */
/* @0x23f218 ldrb r3, [r2, #-0x2] */
/* @0x23f21c sub r2, r2, #1 */
/* @0x23f220 cmp r3, #48 */
/* @0x23f224 mov r9, r2 */
/* @0x23f228 beq 0x23f218 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1248> */
/* @0x23f22c add r11, r0, #1 */
/* @0x23f230 b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c> */
/* @0x23f234 ldr r0, [sp, #0x10] */
/* @0x23f238 ldrb r3, [r9, #-0x1] */
/* @0x23f23c b 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0> */
/* @0x23f240 mov r1, #57 */
/* @0x23f244 mov r2, r6 */
/* @0x23f248 strb r1, [r9] */
/* @0x23f24c mov r6, r8 */
/* @0x23f250 add r9, r9, #1 */
/* @0x23f254 b 0x23eddc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe0c> */
/* @0x23f258 ldr r10, [r5, #0x14] */
/* @0x23f25c cmp r10, #0 */
/* @0x23f260 beq 0x23f0c8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f8> */
/* @0x23f264 b 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08> */
/* @0x23f268 mov r0, r5 */
/* @0x23f26c mov r1, #1 */
/* @0x23f270 bl 0x23d6cc <lshift_D2A> */
/* @0x23f274 mov r1, r7 */
/* @0x23f278 mov r5, r0 */
/* @0x23f27c bl 0x23d7c8 <cmp_D2A> */
/* @0x23f280 cmp r0, #0 */
/* @0x23f284 ble 0x23f340 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1370> */
/* @0x23f288 cmp r11, #57 */
/* @0x23f28c beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270> */
/* @0x23f290 ldr r2, [sp, #0x8] */
/* @0x23f294 add r11, r2, #49 */
/* @0x23f298 mov r10, #32 */
/* @0x23f29c b 0x23f1dc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x120c> */
/* @0x23f2a0 ldr r0, [sp, #0x10] */
/* @0x23f2a4 mov r10, #16 */
/* @0x23f2a8 ldrb r3, [r9, #-0x1] */
/* @0x23f2ac b 0x23f210 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1240> */
/* @0x23f2b0 cmp r11, #57 */
/* @0x23f2b4 ldr r4, [sp, #0x18] */
/* @0x23f2b8 beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270> */
/* @0x23f2bc cmp r10, #0 */
/* @0x23f2c0 ldrgt r2, [sp, #0x8] */
/* @0x23f2c4 movgt r10, #32 */
/* @0x23f2c8 addgt r11, r2, #49 */
/* @0x23f2cc bgt 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c> */
/* @0x23f2d0 ldr r2, [r5, #0x10] */
/* @0x23f2d4 cmp r2, #1 */
/* @0x23f2d8 bgt 0x23f1e8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1218> */
/* @0x23f2dc ldr r10, [r5, #0x14] */
/* @0x23f2e0 cmp r10, #0 */
/* @0x23f2e4 movne r10, #16 */
/* @0x23f2e8 moveq r10, #0 */
/* @0x23f2ec b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c> */
/* @0x23f2f0 ldr r2, [r5, #0x14] */
/* @0x23f2f4 cmp r2, #0 */
/* @0x23f2f8 movne r10, #16 */
/* @0x23f2fc b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c> */
/* @0x23f300 mov r0, r6 */
/* @0x23f304 mov r1, #10 */
/* @0x23f308 mov r2, #0 */
/* @0x23f30c bl 0x23d368 <multadd_D2A> */
/* @0x23f310 ldr lr, [sp, #0x44] */
/* @0x23f314 cmp lr, #0 */
/* @0x23f318 movgt r3, #0 */
/* @0x23f31c movle r3, #1 */
/* @0x23f320 mov r6, r0 */
/* @0x23f324 ldr r0, [sp, #0x78] */
/* @0x23f328 cmp r0, #2 */
/* @0x23f32c movle r3, #0 */
/* @0x23f330 cmp r3, #0 */
/* @0x23f334 streq lr, [sp, #0x20] */
/* @0x23f338 beq 0x23e970 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9a0> */
/* @0x23f33c b 0x23ec68 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc98> */
/* @0x23f340 bne 0x23f298 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12c8> */
/* @0x23f344 tst r11, #1 */
/* @0x23f348 beq 0x23f298 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12c8> */
/* @0x23f34c b 0x23f288 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12b8> */
/* @0x23f350 ldr r10, [r5, #0x14] */
/* @0x23f354 cmp r10, #0 */
/* @0x23f358 bne 0x23f0c4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f4> */
/* @0x23f35c b 0x23f0c8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f8> */
/* @0x23f360 mov r0, #0 */
/* @0x23f364 b 0x23e120 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x150> */

/* ── FUNC 0x23f368 · g__fmt_D2A · size=628 · insn=157 */
/* @0x23f368 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x23f36c rsb r2, r1, r2 */
/* @0x23f370 ldr r8, [sp, #0x24] */
/* @0x23f374 mov r10, r1 */
/* @0x23f378 add r1, r2, #6 */
/* @0x23f37c cmp r1, r8 */
/* @0x23f380 bhi 0x23f4f8 <g__fmt_D2A+0x190> */
/* @0x23f384 ldr r1, [sp, #0x20] */
/* @0x23f388 sub r8, r8, #1 */
/* @0x23f38c add r8, r0, r8 */
/* @0x23f390 cmp r1, #0 */
/* @0x23f394 movne r1, #45 */
/* @0x23f398 strbne r1, [r0] */
/* @0x23f39c addne r0, r0, #1 */
/* @0x23f3a0 cmn r3, #5 */
/* @0x23f3a4 blt 0x23f428 <g__fmt_D2A+0xc0> */
/* @0x23f3a8 add r1, r2, #20 */
/* @0x23f3ac cmp r3, r1 */
/* @0x23f3b0 bgt 0x23f428 <g__fmt_D2A+0xc0> */
/* @0x23f3b4 cmp r3, #0 */
/* @0x23f3b8 ble 0x23f55c <g__fmt_D2A+0x1f4> */
/* @0x23f3bc sub r1, r10, #1 */
/* @0x23f3c0 mov lr, #46 */
/* @0x23f3c4 b 0x23f3e4 <g__fmt_D2A+0x7c> */
/* @0x23f3c8 subs r3, r3, #1 */
/* @0x23f3cc bne 0x23f3e0 <g__fmt_D2A+0x78> */
/* @0x23f3d0 ldrb r2, [r1, #0x1] */
/* @0x23f3d4 cmp r2, #0 */
/* @0x23f3d8 strbne lr, [r0, #0x1] */
/* @0x23f3dc addne r12, r0, #2 */
/* @0x23f3e0 mov r0, r12 */
/* @0x23f3e4 ldrb r2, [r1, #0x1]! */
/* @0x23f3e8 add r12, r0, #1 */
/* @0x23f3ec cmp r2, #0 */
/* @0x23f3f0 strb r2, [r0] */
/* @0x23f3f4 bne 0x23f3c8 <g__fmt_D2A+0x60> */
/* @0x23f3f8 add r4, r0, r3 */
/* @0x23f3fc cmp r8, r4 */
/* @0x23f400 blo 0x23f4f8 <g__fmt_D2A+0x190> */
/* @0x23f404 cmp r3, #0 */
/* @0x23f408 ble 0x23f5d4 <g__fmt_D2A+0x26c> */
/* @0x23f40c mov r3, #48 */
/* @0x23f410 strb r3, [r0], #1 */
/* @0x23f414 cmp r4, r0 */
/* @0x23f418 bne 0x23f410 <g__fmt_D2A+0xa8> */
/* @0x23f41c mov r3, #0 */
/* @0x23f420 strb r3, [r4] */
/* @0x23f424 b 0x23f4fc <g__fmt_D2A+0x194> */
/* @0x23f428 ldrb r2, [r10] */
/* @0x23f42c strb r2, [r0] */
/* @0x23f430 ldrb r2, [r10, #0x1] */
/* @0x23f434 cmp r2, #0 */
/* @0x23f438 addeq r12, r0, #1 */
/* @0x23f43c bne 0x23f50c <g__fmt_D2A+0x1a4> */
/* @0x23f440 subs r6, r3, #1 */
/* @0x23f444 mov r3, #101 */
/* @0x23f448 rsbmi r6, r6, #0 */
/* @0x23f44c strb r3, [r12] */
/* @0x23f450 addmi r9, r12, #2 */
/* @0x23f454 movmi r3, #45 */
/* @0x23f458 movpl r3, #43 */
/* @0x23f45c addpl r9, r12, #2 */
/* @0x23f460 cmp r6, #9 */
/* @0x23f464 strb r3, [r12, #0x1] */
/* @0x23f468 ble 0x23f5c8 <g__fmt_D2A+0x260> */
/* @0x23f46c mov r5, #10 */
/* @0x23f470 mov r4, #1 */
/* @0x23f474 b 0x23f47c <g__fmt_D2A+0x114> */
/* @0x23f478 mov r5, r3 */
/* @0x23f47c add r3, r5, r5, lsl #2 */
/* @0x23f480 add r4, r4, #1 */
/* @0x23f484 lsl r3, r3, #1 */
/* @0x23f488 cmp r6, r3 */
/* @0x23f48c bge 0x23f478 <g__fmt_D2A+0x110> */
/* @0x23f490 mov r0, r6 */
/* @0x23f494 mov r1, r5 */
/* @0x23f498 bl 0x318d10 <__divsi3> */
/* @0x23f49c cmp r9, r8 */
/* @0x23f4a0 bhs 0x23f4f8 <g__fmt_D2A+0x190> */
/* @0x23f4a4 cmp r4, #1 */
/* @0x23f4a8 add r3, r0, #48 */
/* @0x23f4ac add r7, r9, #1 */
/* @0x23f4b0 strb r3, [r9] */
/* @0x23f4b4 beq 0x23f548 <g__fmt_D2A+0x1e0> */
/* @0x23f4b8 add r9, r9, r4 */
/* @0x23f4bc b 0x23f4d0 <g__fmt_D2A+0x168> */
/* @0x23f4c0 strb r3, [r4], #1 */
/* @0x23f4c4 cmp r4, r9 */
/* @0x23f4c8 beq 0x23f550 <g__fmt_D2A+0x1e8> */
/* @0x23f4cc mov r7, r4 */
/* @0x23f4d0 mls r6, r5, r0, r6 */
/* @0x23f4d4 mov r1, r5 */
/* @0x23f4d8 mov r4, r7 */
/* @0x23f4dc add r6, r6, r6, lsl #2 */
/* @0x23f4e0 lsl r6, r6, #1 */
/* @0x23f4e4 mov r0, r6 */
/* @0x23f4e8 bl 0x318d10 <__divsi3> */
/* @0x23f4ec cmp r7, r8 */
/* @0x23f4f0 add r3, r0, #48 */
/* @0x23f4f4 bne 0x23f4c0 <g__fmt_D2A+0x158> */
/* @0x23f4f8 mov r4, #0 */
/* @0x23f4fc mov r0, r10 */
/* @0x23f500 bl 0x23dd68 <_Z8freedtoaPc> */
/* @0x23f504 mov r0, r4 */
/* @0x23f508 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x23f50c mov r2, #46 */
/* @0x23f510 strb r2, [r0, #0x1] */
/* @0x23f514 ldrb r2, [r10, #0x1] */
/* @0x23f518 add r12, r0, #2 */
/* @0x23f51c add r1, r10, #2 */
/* @0x23f520 cmp r2, #0 */
/* @0x23f524 strb r2, [r0, #0x2] */
/* @0x23f528 beq 0x23f440 <g__fmt_D2A+0xd8> */
/* @0x23f52c add r0, r0, #3 */
/* @0x23f530 ldrb r2, [r1], #1 */
/* @0x23f534 mov r12, r0 */
/* @0x23f538 cmp r2, #0 */
/* @0x23f53c strb r2, [r0], #1 */
/* @0x23f540 bne 0x23f530 <g__fmt_D2A+0x1c8> */
/* @0x23f544 b 0x23f440 <g__fmt_D2A+0xd8> */
/* @0x23f548 mov r4, r7 */
/* @0x23f54c mov r7, r9 */
/* @0x23f550 mov r3, #0 */
/* @0x23f554 strb r3, [r7, #0x1] */
/* @0x23f558 b 0x23f4fc <g__fmt_D2A+0x194> */
/* @0x23f55c rsb r12, r3, r2 */
/* @0x23f560 mov r4, r0 */
/* @0x23f564 mov r2, #48 */
/* @0x23f568 strb r2, [r4], #2 */
/* @0x23f56c add r12, r4, r12 */
/* @0x23f570 mov r1, #46 */
/* @0x23f574 cmp r8, r12 */
/* @0x23f578 strb r1, [r0, #0x1] */
/* @0x23f57c blo 0x23f4f8 <g__fmt_D2A+0x190> */
/* @0x23f580 cmp r3, #0 */
/* @0x23f584 beq 0x23f598 <g__fmt_D2A+0x230> */
/* @0x23f588 rsb r3, r3, r4 */
/* @0x23f58c strb r2, [r4], #1 */
/* @0x23f590 cmp r4, r3 */
/* @0x23f594 bne 0x23f58c <g__fmt_D2A+0x224> */
/* @0x23f598 ldrb r3, [r10] */
/* @0x23f59c cmp r3, #0 */
/* @0x23f5a0 strb r3, [r4] */
/* @0x23f5a4 beq 0x23f4fc <g__fmt_D2A+0x194> */
/* @0x23f5a8 add r3, r4, #1 */
/* @0x23f5ac mov r1, r10 */
/* @0x23f5b0 ldrb r2, [r1, #0x1]! */
/* @0x23f5b4 mov r4, r3 */
/* @0x23f5b8 cmp r2, #0 */
/* @0x23f5bc strb r2, [r3], #1 */
/* @0x23f5c0 bne 0x23f5b0 <g__fmt_D2A+0x248> */
/* @0x23f5c4 b 0x23f4fc <g__fmt_D2A+0x194> */
/* @0x23f5c8 mov r5, #1 */
/* @0x23f5cc mov r4, r5 */
/* @0x23f5d0 b 0x23f490 <g__fmt_D2A+0x128> */
/* @0x23f5d4 mov r4, r0 */
/* @0x23f5d8 b 0x23f41c <g__fmt_D2A+0xb4> */

/* ── FUNC 0x23f5dc · add_nanbits_D2A · size=232 · insn=58 */
/* @0x23f5dc push {r4, r5, r6, r7, r8, r9} */
/* @0x23f5e0 add r4, r2, r3, lsl #2 */
/* @0x23f5e4 b 0x23f5f0 <add_nanbits_D2A+0x14> */
/* @0x23f5e8 cmp r3, #0 */
/* @0x23f5ec beq 0x23f6b4 <add_nanbits_D2A+0xd8> */
/* @0x23f5f0 ldr r12, [r4, #-0x4] */
/* @0x23f5f4 sub r6, r4, #4 */
/* @0x23f5f8 sub r3, r3, #1 */
/* @0x23f5fc cmp r12, #0 */
/* @0x23f600 mov r4, r6 */
/* @0x23f604 beq 0x23f5e8 <add_nanbits_D2A+0xc> */
/* @0x23f608 lsl r4, r3, #3 */
/* @0x23f60c add r4, r4, #3 */
/* @0x23f610 lsrs r12, r12, #4 */
/* @0x23f614 add r4, r4, #1 */
/* @0x23f618 bne 0x23f610 <add_nanbits_D2A+0x34> */
/* @0x23f61c cmp r1, r4 */
/* @0x23f620 blo 0x23f6b4 <add_nanbits_D2A+0xd8> */
/* @0x23f624 add r7, r0, r4 */
/* @0x23f628 cmp r3, #0 */
/* @0x23f62c mov r1, #41 */
/* @0x23f630 sub r8, r7, #2 */
/* @0x23f634 strb r12, [r7, #-0x1] */
/* @0x23f638 strb r1, [r7, #-0x2] */
/* @0x23f63c ble 0x23f680 <add_nanbits_D2A+0xa4> */
/* @0x23f640 ldr r5, [pc, #0x74] */
/* @0x23f644 add r9, r2, r3, lsl #2 */
/* @0x23f648 mov r1, r8 */
/* @0x23f64c add r5, pc, r5 */
/* @0x23f650 ldr r0, [r2], #4 */
/* @0x23f654 sub r4, r1, #8 */
/* @0x23f658 and r12, r0, #15 */
/* @0x23f65c lsr r0, r0, #4 */
/* @0x23f660 ldrb r12, [r5, r12] */
/* @0x23f664 strb r12, [r1, #-0x1]! */
/* @0x23f668 cmp r4, r1 */
/* @0x23f66c bne 0x23f658 <add_nanbits_D2A+0x7c> */
/* @0x23f670 cmp r2, r9 */
/* @0x23f674 mov r1, r4 */
/* @0x23f678 bne 0x23f650 <add_nanbits_D2A+0x74> */
/* @0x23f67c sub r8, r8, r3, lsl #3 */
/* @0x23f680 ldr r0, [pc, #0x38] */
/* @0x23f684 sub r2, r8, #1 */
/* @0x23f688 ldr r3, [r6] */
/* @0x23f68c add r0, pc, r0 */
/* @0x23f690 and r1, r3, #15 */
/* @0x23f694 lsrs r3, r3, #4 */
/* @0x23f698 mov r12, r2 */
/* @0x23f69c ldrb r1, [r0, r1] */
/* @0x23f6a0 strb r1, [r2], #-1 */
/* @0x23f6a4 bne 0x23f690 <add_nanbits_D2A+0xb4> */
/* @0x23f6a8 sub r0, r7, #1 */
/* @0x23f6ac mov r3, #40 */
/* @0x23f6b0 strb r3, [r12, #-0x1] */
/* @0x23f6b4 pop {r4, r5, r6, r7, r8, r9} */
/* @0x23f6b8 bx lr */
/* @0x23f6bc andseq r5, r1, r12, lsr #27 */
/* @0x23f6c0 andseq r5, r1, r12, ror #26 */

/* ── FUNC 0x23f6c4 · g_dfmt(char*, double*, int, unsigned int) · size=400 · insn=100 */
/* @0x23f6c4 bic r2, r2, r2, asr #31 */
/* @0x23f6c8 push {r4, r5, r6, r7, lr} */
/* @0x23f6cc mov r5, r3 */
/* @0x23f6d0 add r3, r2, #9 */
/* @0x23f6d4 sub sp, sp, #44 */
/* @0x23f6d8 cmp r3, r5 */
/* @0x23f6dc mov r7, r0 */
/* @0x23f6e0 bge 0x23f83c <_Z6g_dfmtPcPdij+0x178> */
/* @0x23f6e4 ldr r4, [r1, #0x4] */
/* @0x23f6e8 mov r12, #0 */
/* @0x23f6ec movt r12, #0x7ff0 */
/* @0x23f6f0 mov r3, #0 */
/* @0x23f6f4 and r12, r4, r12 */
/* @0x23f6f8 movt r3, #0x7ff0 */
/* @0x23f6fc cmp r12, r3 */
/* @0x23f700 and r6, r4, #-2147483648 */
/* @0x23f704 beq 0x23f7dc <_Z6g_dfmtPcPdij+0x118> */
/* @0x23f708 ldr r3, [r1] */
/* @0x23f70c cmp r3, #0 */
/* @0x23f710 beq 0x23f7ac <_Z6g_dfmtPcPdij+0xe8> */
/* @0x23f714 ubfx r1, r4, #0x14, #0xb */
/* @0x23f718 ubfx r4, r4, #0x0, #0x14 */
/* @0x23f71c cmp r1, #0 */
/* @0x23f720 streq r4, [sp, #0x24] */
/* @0x23f724 subne r1, r1, #1072 */
/* @0x23f728 orrne r4, r4, #1048576 */
/* @0x23f72c movweq r1, #0xfbce */
/* @0x23f730 subne r1, r1, #3 */
/* @0x23f734 movteq r1, #0xffff */
/* @0x23f738 strne r4, [sp, #0x24] */
/* @0x23f73c cmp r2, #0 */
/* @0x23f740 str r3, [sp, #0x20] */
/* @0x23f744 str r2, [sp, #0x4] */
/* @0x23f748 add r2, sp, #32 */
/* @0x23f74c movne r3, #2 */
/* @0x23f750 moveq r3, #0 */
/* @0x23f754 cmp r6, #0 */
/* @0x23f758 str r3, [sp] */
/* @0x23f75c add r3, sp, #24 */
/* @0x23f760 str r3, [sp, #0x8] */
/* @0x23f764 moveq r0, #1 */
/* @0x23f768 movne r0, #9 */
/* @0x23f76c str r0, [sp, #0x1c] */
/* @0x23f770 add r3, sp, #20 */
/* @0x23f774 ldr r0, [pc, #0xcc] */
/* @0x23f778 str r3, [sp, #0xc] */
/* @0x23f77c add r3, sp, #28 */
/* @0x23f780 add r0, pc, r0 */
/* @0x23f784 bl 0x23dfd0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc> */
/* @0x23f788 ldr r2, [sp, #0x14] */
/* @0x23f78c ldr r3, [sp, #0x18] */
/* @0x23f790 str r6, [sp] */
/* @0x23f794 str r5, [sp, #0x4] */
/* @0x23f798 mov r1, r0 */
/* @0x23f79c mov r0, r7 */
/* @0x23f7a0 bl 0x23f368 <g__fmt_D2A> */
/* @0x23f7a4 add sp, sp, #44 */
/* @0x23f7a8 pop {r4, r5, r6, r7, pc} */
/* @0x23f7ac cmp r4, r6 */
/* @0x23f7b0 bne 0x23f714 <_Z6g_dfmtPcPdij+0x50> */
/* @0x23f7b4 cmp r4, #0 */
/* @0x23f7b8 mov r2, #48 */
/* @0x23f7bc addlt r7, r0, #1 */
/* @0x23f7c0 movlt r3, #45 */
/* @0x23f7c4 strblt r3, [r0] */
/* @0x23f7c8 mov r3, #0 */
/* @0x23f7cc strb r2, [r7] */
/* @0x23f7d0 add r0, r7, #1 */
/* @0x23f7d4 strb r3, [r7, #0x1] */
/* @0x23f7d8 b 0x23f7a4 <_Z6g_dfmtPcPdij+0xe0> */
/* @0x23f7dc cmp r5, #9 */
/* @0x23f7e0 bls 0x23f83c <_Z6g_dfmtPcPdij+0x178> */
/* @0x23f7e4 ubfx r4, r4, #0x0, #0x14 */
/* @0x23f7e8 cmp r4, #0 */
/* @0x23f7ec bne 0x23f824 <_Z6g_dfmtPcPdij+0x160> */
/* @0x23f7f0 ldr r3, [r1] */
/* @0x23f7f4 cmp r3, #0 */
/* @0x23f7f8 bne 0x23f824 <_Z6g_dfmtPcPdij+0x160> */
/* @0x23f7fc cmp r6, #0 */
/* @0x23f800 ldr r1, [pc, #0x44] */
/* @0x23f804 addne r7, r0, #1 */
/* @0x23f808 movne r3, #45 */
/* @0x23f80c add r1, pc, r1 */
/* @0x23f810 strbne r3, [r0] */
/* @0x23f814 mov r0, r7 */
/* @0x23f818 bl 0x23db24 <strcp_D2A> */
/* @0x23f81c add sp, sp, #44 */
/* @0x23f820 pop {r4, r5, r6, r7, pc} */
/* @0x23f824 ldr r1, [pc, #0x24] */
/* @0x23f828 mov r0, r7 */
/* @0x23f82c add r1, pc, r1 */
/* @0x23f830 bl 0x23db24 <strcp_D2A> */
/* @0x23f834 add sp, sp, #44 */
/* @0x23f838 pop {r4, r5, r6, r7, pc} */
/* @0x23f83c mov r0, #0 */
/* @0x23f840 add sp, sp, #44 */
/* @0x23f844 pop {r4, r5, r6, r7, pc} */
/* @0x23f848 andseq r7, r11, r0, lsr #24 */
/* @0x23f84c andseq r5, r1, r0, ror #23 */
/* @0x23f850 andeq r2, pc, r8, asr #25 */

/* ── FUNC 0x23f854 · utf8proc_get_property(int) · size=100 · insn=25 */
/* @0x23f854 cmp r0, #1114112 */
/* @0x23f858 bhs 0x23f89c <_Z21utf8proc_get_propertyi+0x48> */
/* @0x23f85c ldr r12, [pc, #0x44] */
/* @0x23f860 asr r2, r0, #8 */
/* @0x23f864 movw r1, #0x654 */
/* @0x23f868 ldr r3, [pc, #0x3c] */
/* @0x23f86c add r12, pc, r12 */
/* @0x23f870 add r12, r12, r2, lsl #1 */
/* @0x23f874 add r3, pc, r3 */
/* @0x23f878 ldr r2, [pc, #0x30] */
/* @0x23f87c ldrh r1, [r12, r1] */
/* @0x23f880 add r2, pc, r2 */
/* @0x23f884 uxtab r0, r1, r0 */
/* @0x23f888 add r0, r3, r0, lsl #1 */
/* @0x23f88c ldrh r3, [r0, #12] */
/* @0x23f890 add r3, r3, r3, lsl #2 */
/* @0x23f894 add r0, r2, r3, lsl #3 */
/* @0x23f898 bx lr */
/* @0x23f89c ldr r0, [pc, #0x10] */
/* @0x23f8a0 add r0, pc, r0 */
/* @0x23f8a4 bx lr */
/* @0x23f8a8 andseq r11, r3, r12, lsr #13 */
/* @0x23f8ac andseq r9, r2, r12, ror #13 */
/* @0x23f8b0 andseq r7, r6, r8, ror #21 */
/* @0x23f8b4 andseq r7, r6, r8, asr #21 */

/* ── FUNC 0x23f8b8 · utf8_tolower(int) · size=28 · insn=7 */
/* @0x23f8b8 push {r4, lr} */
/* @0x23f8bc mov r4, r0 */
/* @0x23f8c0 bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x23f8c4 ldr r0, [r0, #0x14] */
/* @0x23f8c8 cmp r0, #0 */
/* @0x23f8cc movlt r0, r4 */
/* @0x23f8d0 pop {r4, pc} */

/* ── FUNC 0x23f8d4 · utf8_toupper(int) · size=28 · insn=7 */
/* @0x23f8d4 push {r4, lr} */
/* @0x23f8d8 mov r4, r0 */
/* @0x23f8dc bl 0x23f854 <_Z21utf8proc_get_propertyi> */
/* @0x23f8e0 ldr r0, [r0, #0x10] */
/* @0x23f8e4 cmp r0, #0 */
/* @0x23f8e8 movlt r0, r4 */
/* @0x23f8ec pop {r4, pc} */

/* ── FUNC 0x23f8f0 · isGlobalBuiltinVar(char const*) · size=76 · insn=19 */
/* @0x23f8f0 push {r4, r5, r6, lr} */
/* @0x23f8f4 mov r5, r0 */
/* @0x23f8f8 ldr r6, [pc, #0x38] */
/* @0x23f8fc ldr r6, [pc, r6] */
/* @0x23f900 sub r4, r6, #4 */
/* @0x23f904 add r6, r6, #512 */
/* @0x23f908 b 0x23f914 <_Z18isGlobalBuiltinVarPKc+0x24> */
/* @0x23f90c cmp r4, r6 */
/* @0x23f910 beq 0x23f930 <_Z18isGlobalBuiltinVarPKc+0x40> */
/* @0x23f914 ldr r0, [r4, #0x4]! */
/* @0x23f918 mov r1, r5 */
/* @0x23f91c bl 0xb6574 <strcmp@plt> */
/* @0x23f920 cmp r0, #0 */
/* @0x23f924 bne 0x23f90c <_Z18isGlobalBuiltinVarPKc+0x1c> */
/* @0x23f928 mov r0, #1 */
/* @0x23f92c pop {r4, r5, r6, pc} */
/* @0x23f930 mov r0, #0 */
/* @0x23f934 pop {r4, r5, r6, pc} */
/* @0x23f938 andseq r1, r11, r4, lsl r12 */

/* ── FUNC 0x23f93c · JS_ResourceSetup() · size=1240 · insn=310 */
/* @0x23f93c push {r4, r5, r6, r7, r8, lr} */
/* @0x23f940 sub sp, sp, #40 */
/* @0x23f944 mov r7, #0 */
/* @0x23f948 ldr r6, [pc, #0x4b4] */
/* @0x23f94c mov r3, r7 */
/* @0x23f950 str r7, [sp] */
/* @0x23f954 mov r1, r7 */
/* @0x23f958 mov r2, r7 */
/* @0x23f95c add r0, sp, #8 */
/* @0x23f960 mov r4, #0 */
/* @0x23f964 str r7, [sp, #0x10] */
/* @0x23f968 mov r5, #0 */
/* @0x23f96c mvn r12, #-16777216 */
/* @0x23f970 strd r4, r5, [sp, #8] */
/* @0x23f974 str r12, [sp, #0x14] */
/* @0x23f978 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x23f97c ldr r6, [pc, r6] */
/* @0x23f980 ldr r5, [sp, #0x8] */
/* @0x23f984 ldr r3, [r6] */
/* @0x23f988 cmp r3, r7 */
/* @0x23f98c addgt r8, sp, #24 */
/* @0x23f990 movgt r4, r7 */
/* @0x23f994 movgt r7, r4 */
/* @0x23f998 bgt 0x23f9b0 <_Z16JS_ResourceSetupv+0x74> */
/* @0x23f99c b 0x23f9fc <_Z16JS_ResourceSetupv+0xc0> */
/* @0x23f9a0 ldr r3, [r6] */
/* @0x23f9a4 add r4, r4, #1 */
/* @0x23f9a8 cmp r4, r3 */
/* @0x23f9ac bge 0x23f9fc <_Z16JS_ResourceSetupv+0xc0> */
/* @0x23f9b0 mov r0, r4 */
/* @0x23f9b4 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x23f9b8 cmp r0, #0 */
/* @0x23f9bc beq 0x23f9a0 <_Z16JS_ResourceSetupv+0x64> */
/* @0x23f9c0 vmov s13, r4 */
/* @0x23f9c4 mov r0, r4 */
/* @0x23f9c8 str r7, [sp, #0x24] */
/* @0x23f9cc add r4, r4, #1 */
/* @0x23f9d0 vcvt.f64.s32 d7, s13 */
/* @0x23f9d4 vstr d7, [sp, #24] */
/* @0x23f9d8 bl 0x19ed54 <_Z11Object_Namei> */
/* @0x23f9dc mov r3, #1 */
/* @0x23f9e0 mov r2, r8 */
/* @0x23f9e4 mov r1, r0 */
/* @0x23f9e8 mov r0, r5 */
/* @0x23f9ec bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23f9f0 ldr r3, [r6] */
/* @0x23f9f4 cmp r4, r3 */
/* @0x23f9f8 blt 0x23f9b0 <_Z16JS_ResourceSetupv+0x74> */
/* @0x23f9fc mov r4, #0 */
/* @0x23fa00 add r7, sp, #24 */
/* @0x23fa04 mov r6, r4 */
/* @0x23fa08 b 0x23fa10 <_Z16JS_ResourceSetupv+0xd4> */
/* @0x23fa0c add r4, r4, #1 */
/* @0x23fa10 bl 0x1eee84 <_Z13Sprite_Numberv> */
/* @0x23fa14 cmp r4, r0 */
/* @0x23fa18 mov r0, r4 */
/* @0x23fa1c bge 0x23fa5c <_Z16JS_ResourceSetupv+0x120> */
/* @0x23fa20 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x23fa24 cmp r0, #0 */
/* @0x23fa28 beq 0x23fa0c <_Z16JS_ResourceSetupv+0xd0> */
/* @0x23fa2c vmov s13, r4 */
/* @0x23fa30 mov r0, r4 */
/* @0x23fa34 str r6, [sp, #0x24] */
/* @0x23fa38 vcvt.f64.s32 d7, s13 */
/* @0x23fa3c vstr d7, [sp, #24] */
/* @0x23fa40 bl 0x1eeee0 <_Z11Sprite_Namei> */
/* @0x23fa44 mov r2, r7 */
/* @0x23fa48 mov r3, #1 */
/* @0x23fa4c mov r1, r0 */
/* @0x23fa50 mov r0, r5 */
/* @0x23fa54 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fa58 b 0x23fa0c <_Z16JS_ResourceSetupv+0xd0> */
/* @0x23fa5c mov r4, #0 */
/* @0x23fa60 add r7, sp, #24 */
/* @0x23fa64 mov r6, r4 */
/* @0x23fa68 b 0x23fa70 <_Z16JS_ResourceSetupv+0x134> */
/* @0x23fa6c add r4, r4, #1 */
/* @0x23fa70 bl 0x21fb6c <_Z12Sound_Numberv> */
/* @0x23fa74 cmp r4, r0 */
/* @0x23fa78 mov r0, r4 */
/* @0x23fa7c bge 0x23fabc <_Z16JS_ResourceSetupv+0x180> */
/* @0x23fa80 bl 0x21fbd0 <_Z12Sound_Existsi> */
/* @0x23fa84 cmp r0, #0 */
/* @0x23fa88 beq 0x23fa6c <_Z16JS_ResourceSetupv+0x130> */
/* @0x23fa8c vmov s13, r4 */
/* @0x23fa90 mov r0, r4 */
/* @0x23fa94 str r6, [sp, #0x24] */
/* @0x23fa98 vcvt.f64.s32 d7, s13 */
/* @0x23fa9c vstr d7, [sp, #24] */
/* @0x23faa0 bl 0x21fc18 <_Z10Sound_Namei> */
/* @0x23faa4 mov r2, r7 */
/* @0x23faa8 mov r3, #1 */
/* @0x23faac mov r1, r0 */
/* @0x23fab0 mov r0, r5 */
/* @0x23fab4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fab8 b 0x23fa6c <_Z16JS_ResourceSetupv+0x130> */
/* @0x23fabc mov r4, #0 */
/* @0x23fac0 add r7, sp, #24 */
/* @0x23fac4 mov r6, r4 */
/* @0x23fac8 b 0x23fad0 <_Z16JS_ResourceSetupv+0x194> */
/* @0x23facc add r4, r4, #1 */
/* @0x23fad0 bl 0x2172f8 <_Z12Audio_Numberv> */
/* @0x23fad4 cmp r4, r0 */
/* @0x23fad8 mov r0, r4 */
/* @0x23fadc bge 0x23fb1c <_Z16JS_ResourceSetupv+0x1e0> */
/* @0x23fae0 bl 0x217260 <_Z12Audio_Existsi> */
/* @0x23fae4 cmp r0, #0 */
/* @0x23fae8 beq 0x23facc <_Z16JS_ResourceSetupv+0x190> */
/* @0x23faec vmov s13, r4 */
/* @0x23faf0 mov r0, r4 */
/* @0x23faf4 str r6, [sp, #0x24] */
/* @0x23faf8 vcvt.f64.s32 d7, s13 */
/* @0x23fafc vstr d7, [sp, #24] */
/* @0x23fb00 bl 0x21730c <_Z10Audio_Namei> */
/* @0x23fb04 mov r2, r7 */
/* @0x23fb08 mov r3, #1 */
/* @0x23fb0c mov r1, r0 */
/* @0x23fb10 mov r0, r5 */
/* @0x23fb14 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fb18 b 0x23facc <_Z16JS_ResourceSetupv+0x190> */
/* @0x23fb1c mov r4, #0 */
/* @0x23fb20 add r7, sp, #24 */
/* @0x23fb24 mov r6, r4 */
/* @0x23fb28 b 0x23fb30 <_Z16JS_ResourceSetupv+0x1f4> */
/* @0x23fb2c add r4, r4, #1 */
/* @0x23fb30 bl 0xc362c <_Z17Background_Numberv> */
/* @0x23fb34 cmp r4, r0 */
/* @0x23fb38 mov r0, r4 */
/* @0x23fb3c bge 0x23fb7c <_Z16JS_ResourceSetupv+0x240> */
/* @0x23fb40 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x23fb44 cmp r0, #0 */
/* @0x23fb48 beq 0x23fb2c <_Z16JS_ResourceSetupv+0x1f0> */
/* @0x23fb4c vmov s13, r4 */
/* @0x23fb50 mov r0, r4 */
/* @0x23fb54 str r6, [sp, #0x24] */
/* @0x23fb58 vcvt.f64.s32 d7, s13 */
/* @0x23fb5c vstr d7, [sp, #24] */
/* @0x23fb60 bl 0xc3688 <_Z15Background_Namei> */
/* @0x23fb64 mov r2, r7 */
/* @0x23fb68 mov r3, #1 */
/* @0x23fb6c mov r1, r0 */
/* @0x23fb70 mov r0, r5 */
/* @0x23fb74 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fb78 b 0x23fb2c <_Z16JS_ResourceSetupv+0x1f0> */
/* @0x23fb7c mov r4, #0 */
/* @0x23fb80 add r7, sp, #24 */
/* @0x23fb84 mov r6, r4 */
/* @0x23fb88 b 0x23fb90 <_Z16JS_ResourceSetupv+0x254> */
/* @0x23fb8c add r4, r4, #1 */
/* @0x23fb90 bl 0x1a7ff4 <_Z11Path_Numberv> */
/* @0x23fb94 cmp r4, r0 */
/* @0x23fb98 mov r0, r4 */
/* @0x23fb9c bge 0x23fbdc <_Z16JS_ResourceSetupv+0x2a0> */
/* @0x23fba0 bl 0x1a8008 <_Z11Path_Existsi> */
/* @0x23fba4 cmp r0, #0 */
/* @0x23fba8 beq 0x23fb8c <_Z16JS_ResourceSetupv+0x250> */
/* @0x23fbac vmov s13, r4 */
/* @0x23fbb0 mov r0, r4 */
/* @0x23fbb4 str r6, [sp, #0x24] */
/* @0x23fbb8 vcvt.f64.s32 d7, s13 */
/* @0x23fbbc vstr d7, [sp, #24] */
/* @0x23fbc0 bl 0x1a8050 <_Z9Path_Namei> */
/* @0x23fbc4 mov r2, r7 */
/* @0x23fbc8 mov r3, #1 */
/* @0x23fbcc mov r1, r0 */
/* @0x23fbd0 mov r0, r5 */
/* @0x23fbd4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fbd8 b 0x23fb8c <_Z16JS_ResourceSetupv+0x250> */
/* @0x23fbdc mov r4, #0 */
/* @0x23fbe0 add r7, sp, #24 */
/* @0x23fbe4 mov r6, r4 */
/* @0x23fbe8 b 0x23fbf0 <_Z16JS_ResourceSetupv+0x2b4> */
/* @0x23fbec add r4, r4, #1 */
/* @0x23fbf0 bl 0xfa294 <_Z11Font_Numberv> */
/* @0x23fbf4 cmp r4, r0 */
/* @0x23fbf8 mov r0, r4 */
/* @0x23fbfc bge 0x23fc3c <_Z16JS_ResourceSetupv+0x300> */
/* @0x23fc00 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x23fc04 cmp r0, #0 */
/* @0x23fc08 beq 0x23fbec <_Z16JS_ResourceSetupv+0x2b0> */
/* @0x23fc0c vmov s13, r4 */
/* @0x23fc10 mov r0, r4 */
/* @0x23fc14 str r6, [sp, #0x24] */
/* @0x23fc18 vcvt.f64.s32 d7, s13 */
/* @0x23fc1c vstr d7, [sp, #24] */
/* @0x23fc20 bl 0xfa2f0 <_Z9Font_Namei> */
/* @0x23fc24 mov r2, r7 */
/* @0x23fc28 mov r3, #1 */
/* @0x23fc2c mov r1, r0 */
/* @0x23fc30 mov r0, r5 */
/* @0x23fc34 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fc38 b 0x23fbec <_Z16JS_ResourceSetupv+0x2b0> */
/* @0x23fc3c mov r4, #0 */
/* @0x23fc40 add r7, sp, #24 */
/* @0x23fc44 mov r6, r4 */
/* @0x23fc48 b 0x23fc50 <_Z16JS_ResourceSetupv+0x314> */
/* @0x23fc4c add r4, r4, #1 */
/* @0x23fc50 bl 0x1f2b00 <_Z15TimeLine_Numberv> */
/* @0x23fc54 cmp r4, r0 */
/* @0x23fc58 mov r0, r4 */
/* @0x23fc5c bge 0x23fc9c <_Z16JS_ResourceSetupv+0x360> */
/* @0x23fc60 bl 0x1f2b18 <_Z15TimeLine_Existsi> */
/* @0x23fc64 cmp r0, #0 */
/* @0x23fc68 beq 0x23fc4c <_Z16JS_ResourceSetupv+0x310> */
/* @0x23fc6c vmov s13, r4 */
/* @0x23fc70 mov r0, r4 */
/* @0x23fc74 str r6, [sp, #0x24] */
/* @0x23fc78 vcvt.f64.s32 d7, s13 */
/* @0x23fc7c vstr d7, [sp, #24] */
/* @0x23fc80 bl 0x1f2b58 <_Z13TimeLine_Namei> */
/* @0x23fc84 mov r2, r7 */
/* @0x23fc88 mov r3, #1 */
/* @0x23fc8c mov r1, r0 */
/* @0x23fc90 mov r0, r5 */
/* @0x23fc94 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fc98 b 0x23fc4c <_Z16JS_ResourceSetupv+0x310> */
/* @0x23fc9c mov r4, #0 */
/* @0x23fca0 add r7, sp, #24 */
/* @0x23fca4 mov r6, r4 */
/* @0x23fca8 b 0x23fcb0 <_Z16JS_ResourceSetupv+0x374> */
/* @0x23fcac add r4, r4, #1 */
/* @0x23fcb0 bl 0x1e0530 <_Z13Script_Numberv> */
/* @0x23fcb4 cmp r4, r0 */
/* @0x23fcb8 mov r0, r4 */
/* @0x23fcbc bge 0x23fcfc <_Z16JS_ResourceSetupv+0x3c0> */
/* @0x23fcc0 bl 0x1e0544 <_Z13Script_Existsi> */
/* @0x23fcc4 cmp r0, #0 */
/* @0x23fcc8 beq 0x23fcac <_Z16JS_ResourceSetupv+0x370> */
/* @0x23fccc vmov s13, r4 */
/* @0x23fcd0 mov r0, r4 */
/* @0x23fcd4 str r6, [sp, #0x24] */
/* @0x23fcd8 vcvt.f64.s32 d7, s13 */
/* @0x23fcdc vstr d7, [sp, #24] */
/* @0x23fce0 bl 0x1e058c <_Z11Script_Namei> */
/* @0x23fce4 mov r2, r7 */
/* @0x23fce8 mov r3, #1 */
/* @0x23fcec mov r1, r0 */
/* @0x23fcf0 mov r0, r5 */
/* @0x23fcf4 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fcf8 b 0x23fcac <_Z16JS_ResourceSetupv+0x370> */
/* @0x23fcfc mov r4, #0 */
/* @0x23fd00 add r7, sp, #24 */
/* @0x23fd04 mov r6, r4 */
/* @0x23fd08 b 0x23fd10 <_Z16JS_ResourceSetupv+0x3d4> */
/* @0x23fd0c add r4, r4, #1 */
/* @0x23fd10 bl 0x1b523c <_Z11Room_Numberv> */
/* @0x23fd14 cmp r4, r0 */
/* @0x23fd18 mov r0, r4 */
/* @0x23fd1c bge 0x23fd5c <_Z16JS_ResourceSetupv+0x420> */
/* @0x23fd20 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x23fd24 cmp r0, #0 */
/* @0x23fd28 beq 0x23fd0c <_Z16JS_ResourceSetupv+0x3d0> */
/* @0x23fd2c vmov s13, r4 */
/* @0x23fd30 mov r0, r4 */
/* @0x23fd34 str r6, [sp, #0x24] */
/* @0x23fd38 vcvt.f64.s32 d7, s13 */
/* @0x23fd3c vstr d7, [sp, #24] */
/* @0x23fd40 bl 0x1b530c <_Z9Room_Namei> */
/* @0x23fd44 mov r2, r7 */
/* @0x23fd48 mov r3, #1 */
/* @0x23fd4c mov r1, r0 */
/* @0x23fd50 mov r0, r5 */
/* @0x23fd54 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fd58 b 0x23fd0c <_Z16JS_ResourceSetupv+0x3d0> */
/* @0x23fd5c ldr r6, [pc, #0xa4] */
/* @0x23fd60 ldr r6, [pc, r6] */
/* @0x23fd64 ldr r3, [r6] */
/* @0x23fd68 cmp r3, #0 */
/* @0x23fd6c addgt r8, sp, #24 */
/* @0x23fd70 movgt r4, #0 */
/* @0x23fd74 movgt r7, r4 */
/* @0x23fd78 bgt 0x23fd90 <_Z16JS_ResourceSetupv+0x454> */
/* @0x23fd7c b 0x23fddc <_Z16JS_ResourceSetupv+0x4a0> */
/* @0x23fd80 ldr r3, [r6] */
/* @0x23fd84 add r4, r4, #1 */
/* @0x23fd88 cmp r3, r4 */
/* @0x23fd8c ble 0x23fddc <_Z16JS_ResourceSetupv+0x4a0> */
/* @0x23fd90 mov r0, r4 */
/* @0x23fd94 bl 0x1e1294 <_Z12ShaderExistsi> */
/* @0x23fd98 cmp r0, #0 */
/* @0x23fd9c beq 0x23fd80 <_Z16JS_ResourceSetupv+0x444> */
/* @0x23fda0 mov r0, r4 */
/* @0x23fda4 bl 0x1e1254 <_Z9GetShaderi> */
/* @0x23fda8 vmov s13, r4 */
/* @0x23fdac mov r3, #1 */
/* @0x23fdb0 mov r2, r8 */
/* @0x23fdb4 vcvt.f64.s32 d7, s13 */
/* @0x23fdb8 str r7, [sp, #0x24] */
/* @0x23fdbc add r4, r4, #1 */
/* @0x23fdc0 vstr d7, [sp, #24] */
/* @0x23fdc4 ldr r1, [r0, #0x4] */
/* @0x23fdc8 mov r0, r5 */
/* @0x23fdcc bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei> */
/* @0x23fdd0 ldr r3, [r6] */
/* @0x23fdd4 cmp r3, r4 */
/* @0x23fdd8 bgt 0x23fd90 <_Z16JS_ResourceSetupv+0x454> */
/* @0x23fddc ldr r0, [pc, #0x28] */
/* @0x23fde0 mov r2, r5 */
/* @0x23fde4 ldr r1, [pc, #0x24] */
/* @0x23fde8 mov r3, #1 */
/* @0x23fdec ldr r0, [pc, r0] */
/* @0x23fdf0 add r1, pc, r1 */
/* @0x23fdf4 ldr r0, [r0] */
/* @0x23fdf8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x23fdfc add sp, sp, #40 */
/* @0x23fe00 pop {r4, r5, r6, r7, r8, pc} */
/* @0x23fe04 andseq r0, r11, r8, ror #26 */
/* @0x23fe08 andseq r0, r11, r4, ror #31 */
/* @0x23fe0c andseq sp, r10, r8, asr #27 */
/* @0x23fe10 andseq r5, r1, r12, lsl r6 */

/* ── FUNC 0x23fe14 · getRadixChar(char, int) · size=136 · insn=34 */
/* @0x23fe14 cmp r1, #0 */
/* @0x23fe18 str r4, [sp, #-0x4]! */
/* @0x23fe1c ble 0x23fe74 <_Z12getRadixCharci+0x60> */
/* @0x23fe20 ldr r2, [pc, #0x6c] */
/* @0x23fe24 ldr r2, [pc, r2] */
/* @0x23fe28 ldrb r3, [r2] */
/* @0x23fe2c cmp r3, r0 */
/* @0x23fe30 beq 0x23fe8c <_Z12getRadixCharci+0x78> */
/* @0x23fe34 ldr r12, [pc, #0x5c] */
/* @0x23fe38 ldr r12, [pc, r12] */
/* @0x23fe3c ldrb r3, [r12] */
/* @0x23fe40 cmp r3, r0 */
/* @0x23fe44 beq 0x23fe8c <_Z12getRadixCharci+0x78> */
/* @0x23fe48 mov r3, #0 */
/* @0x23fe4c b 0x23fe68 <_Z12getRadixCharci+0x54> */
/* @0x23fe50 ldrb r4, [r2, #0x1]! */
/* @0x23fe54 cmp r4, r0 */
/* @0x23fe58 beq 0x23fe80 <_Z12getRadixCharci+0x6c> */
/* @0x23fe5c ldrb r4, [r12, #0x1]! */
/* @0x23fe60 cmp r4, r0 */
/* @0x23fe64 beq 0x23fe80 <_Z12getRadixCharci+0x6c> */
/* @0x23fe68 add r3, r3, #1 */
/* @0x23fe6c cmp r3, r1 */
/* @0x23fe70 bne 0x23fe50 <_Z12getRadixCharci+0x3c> */
/* @0x23fe74 mvn r0, #0 */
/* @0x23fe78 ldr r4, [sp], #4 */
/* @0x23fe7c bx lr */
/* @0x23fe80 mov r0, r3 */
/* @0x23fe84 ldr r4, [sp], #4 */
/* @0x23fe88 bx lr */
/* @0x23fe8c mov r0, #0 */
/* @0x23fe90 b 0x23fe84 <_Z12getRadixCharci+0x70> */
/* @0x23fe94 ldrsheq r1, [r11], -r0 */
/* @0x23fe98 andseq r1, r11, r0, ror #13 */

/* ── FUNC 0x23fe9c · isValidRadixChar(char, int) · size=116 · insn=29 */
/* @0x23fe9c cmp r1, #0 */
/* @0x23fea0 ble 0x23fef8 <_Z16isValidRadixCharci+0x5c> */
/* @0x23fea4 ldr r2, [pc, #0x5c] */
/* @0x23fea8 ldr r2, [pc, r2] */
/* @0x23feac ldrb r3, [r2] */
/* @0x23feb0 cmp r3, r0 */
/* @0x23feb4 beq 0x23ff00 <_Z16isValidRadixCharci+0x64> */
/* @0x23feb8 ldr r3, [pc, #0x4c] */
/* @0x23febc ldr r3, [pc, r3] */
/* @0x23fec0 ldrb r12, [r3] */
/* @0x23fec4 cmp r12, r0 */
/* @0x23fec8 beq 0x23ff00 <_Z16isValidRadixCharci+0x64> */
/* @0x23fecc sub r12, r3, #1 */
/* @0x23fed0 add r12, r12, r1 */
/* @0x23fed4 b 0x23fef0 <_Z16isValidRadixCharci+0x54> */
/* @0x23fed8 ldrb r1, [r2, #0x1]! */
/* @0x23fedc cmp r1, r0 */
/* @0x23fee0 beq 0x23ff00 <_Z16isValidRadixCharci+0x64> */
/* @0x23fee4 ldrb r1, [r3, #0x1]! */
/* @0x23fee8 cmp r1, r0 */
/* @0x23feec beq 0x23ff00 <_Z16isValidRadixCharci+0x64> */
/* @0x23fef0 cmp r3, r12 */
/* @0x23fef4 bne 0x23fed8 <_Z16isValidRadixCharci+0x3c> */
/* @0x23fef8 mov r0, #0 */
/* @0x23fefc bx lr */
/* @0x23ff00 mov r0, #1 */
/* @0x23ff04 bx lr */
/* @0x23ff08 andseq r1, r11, r12, ror #12 */
/* @0x23ff0c andseq r1, r11, r12, asr r6 */

/* ── FUNC 0x23ff10 · JS_SetupBuiltinAccessorFunction(bool (*)(CInstance*, int, RValue*), int) · size=156 · insn=39 */
/* @0x23ff10 push {r4, r5, r6, r7, r8, lr} */
/* @0x23ff14 sub sp, sp, #16 */
/* @0x23ff18 mov r8, r0 */
/* @0x23ff1c mov r7, r1 */
/* @0x23ff20 mov r0, sp */
/* @0x23ff24 mov r6, #0 */
/* @0x23ff28 mvn r3, #-16777216 */
/* @0x23ff2c mov r4, #0 */
/* @0x23ff30 str r3, [sp, #0xc] */
/* @0x23ff34 mov r5, #0 */
/* @0x23ff38 str r6, [sp, #0x8] */
/* @0x23ff3c strd r4, r5, [sp] */
/* @0x23ff40 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue> */
/* @0x23ff44 ldr r4, [sp] */
/* @0x23ff48 mov r2, r8 */
/* @0x23ff4c ldr r1, [pc, #0x48] */
/* @0x23ff50 mov r3, r6 */
/* @0x23ff54 mov r0, r4 */
/* @0x23ff58 add r1, pc, r1 */
/* @0x23ff5c bl 0x199b20 <_ZN12YYObjectBase3AddEPKcPvi> */
/* @0x23ff60 ldr r12, [pc, #0x38] */
/* @0x23ff64 ldr r0, [pc, #0x38] */
/* @0x23ff68 mov r2, r7 */
/* @0x23ff6c ldr r1, [pc, #0x34] */
/* @0x23ff70 ldr r12, [pc, r12] */
/* @0x23ff74 ldr r0, [pc, r0] */
/* @0x23ff78 mov r3, r6 */
/* @0x23ff7c str r0, [r4, #0x94] */
/* @0x23ff80 add r1, pc, r1 */
/* @0x23ff84 mov r0, r4 */
/* @0x23ff88 str r12, [r4, #0x90] */
/* @0x23ff8c bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x23ff90 mov r0, r4 */
/* @0x23ff94 add sp, sp, #16 */
/* @0x23ff98 pop {r4, r5, r6, r7, r8, pc} */
/* @0x23ff9c andseq r5, r1, r0, asr #9 */
/* @0x23ffa0 andseq r1, r11, r12, lsr #11 */
/* @0x23ffa4 andseq r1, r11, r12, lsr #11 */
/* @0x23ffa8 andeq r0, pc, r12, ror #17 */

/* ── FUNC 0x23ffac · JS_SetupBuiltinProperty(bool (*)(CInstance*, int, RValue*), bool (*)(CInstance*, int, RValue*)) · size=320 · insn=80 */
/* @0x23ffac push {r3, r4, r5, r6, r7, lr} */
/* @0x23ffb0 mov r2, #0 */
/* @0x23ffb4 mov r6, r0 */
/* @0x23ffb8 mov r5, r1 */
/* @0x23ffbc mov r0, #2 */
/* @0x23ffc0 mvn r1, #-16777216 */
/* @0x23ffc4 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x23ffc8 cmp r6, #0 */
/* @0x23ffcc mov r3, #2 */
/* @0x23ffd0 mov r4, r0 */
/* @0x23ffd4 str r3, [r0, #0x48] */
/* @0x23ffd8 beq 0x240024 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x78> */
/* @0x23ffdc ldr r7, [r0, #0x4] */
/* @0x23ffe0 cmp r7, #0 */
/* @0x23ffe4 beq 0x2400bc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x110> */
/* @0x23ffe8 mov r1, #0 */
/* @0x23ffec mov r0, r6 */
/* @0x23fff0 bl 0x23ff10 <_Z31JS_SetupBuiltinAccessorFunctionPFbP9CInstanceiP6RValueEi> */
/* @0x23fff4 str r0, [r7] */
/* @0x23fff8 ldr r1, [r4, #0x4] */
/* @0x23fffc cmp r1, #0 */
/* @0x240000 beq 0x2400cc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x120> */
/* @0x240004 ldr r1, [r1] */
/* @0x240008 mov r0, r4 */
/* @0x24000c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240010 ldr r1, [r4, #0x4] */
/* @0x240014 cmp r1, #0 */
/* @0x240018 beq 0x2400dc <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x130> */
/* @0x24001c mov r3, #11 */
/* @0x240020 str r3, [r1, #0xc] */
/* @0x240024 cmp r5, #0 */
/* @0x240028 beq 0x240080 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xd4> */
/* @0x24002c ldr r0, [r4, #0x4] */
/* @0x240030 cmp r0, #0 */
/* @0x240034 beq 0x240088 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xdc> */
/* @0x240038 add r6, r0, #16 */
/* @0x24003c mov r0, r5 */
/* @0x240040 mov r1, #1 */
/* @0x240044 bl 0x23ff10 <_Z31JS_SetupBuiltinAccessorFunctionPFbP9CInstanceiP6RValueEi> */
/* @0x240048 str r0, [r6] */
/* @0x24004c ldr r0, [r4, #0x4] */
/* @0x240050 cmp r0, #0 */
/* @0x240054 beq 0x24009c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xf0> */
/* @0x240058 add r0, r0, #16 */
/* @0x24005c ldr r1, [r0] */
/* @0x240060 mov r0, r4 */
/* @0x240064 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240068 ldr r0, [r4, #0x4] */
/* @0x24006c cmp r0, #0 */
/* @0x240070 beq 0x2400ac <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x100> */
/* @0x240074 add r0, r0, #16 */
/* @0x240078 mov r3, #11 */
/* @0x24007c str r3, [r0, #0xc] */
/* @0x240080 mov r0, r4 */
/* @0x240084 pop {r3, r4, r5, r6, r7, pc} */
/* @0x240088 mov r0, r4 */
/* @0x24008c mov r1, #1 */
/* @0x240090 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240094 mov r6, r0 */
/* @0x240098 b 0x24003c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x90> */
/* @0x24009c mov r0, r4 */
/* @0x2400a0 mov r1, #1 */
/* @0x2400a4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2400a8 b 0x24005c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xb0> */
/* @0x2400ac mov r0, r4 */
/* @0x2400b0 mov r1, #1 */
/* @0x2400b4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2400b8 b 0x240078 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0xcc> */
/* @0x2400bc mov r1, r7 */
/* @0x2400c0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2400c4 mov r7, r0 */
/* @0x2400c8 b 0x23ffe8 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x3c> */
/* @0x2400cc mov r0, r4 */
/* @0x2400d0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2400d4 mov r1, r0 */
/* @0x2400d8 b 0x240004 <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x58> */
/* @0x2400dc mov r0, r4 */
/* @0x2400e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2400e4 mov r1, r0 */
/* @0x2400e8 b 0x24001c <_Z23JS_SetupBuiltinPropertyPFbP9CInstanceiP6RValueES4_+0x70> */

/* ── FUNC 0x2400ec · YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) · size=72 · insn=18 */
/* @0x2400ec ldr r12, [r1, #0x24] */
/* @0x2400f0 mov r3, #0 */
/* @0x2400f4 str r1, [r0] */
/* @0x2400f8 cmp r12, r3 */
/* @0x2400fc str r2, [r0, #0xc] */
/* @0x240100 str r3, [r0, #0x4] */
/* @0x240104 str r3, [r0, #0x8] */
/* @0x240108 strb r3, [r0, #0x11] */
/* @0x24010c str r3, [r0, #0x18] */
/* @0x240110 strb r3, [r0, #0x10] */
/* @0x240114 str r3, [r0, #0x14] */
/* @0x240118 beq 0x240128 <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei+0x3c> */
/* @0x24011c ldr r3, [r1, #0x60] */
/* @0x240120 cmp r3, #0 */
/* @0x240124 bxne lr */
/* @0x240128 mov r3, #2 */
/* @0x24012c str r3, [r0, #0x4] */
/* @0x240130 bx lr */

/* ── FUNC 0x2400ec · YYObject_PropertyNameIterator::YYObject_PropertyNameIterator(YYObjectBase*, int) · alias of the symbol above · insn=0 */

/* ── FUNC 0x240134 · YYObject_PropertyNameIterator::NextInternal(RValue*, RValue*) · size=664 · insn=166 */
/* @0x240134 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x240138 sub sp, sp, #76 */
/* @0x24013c ldr r4, [pc, #0x278] */
/* @0x240140 mov r5, r0 */
/* @0x240144 ldr r12, [r0, #0x4] */
/* @0x240148 mov r7, r1 */
/* @0x24014c ldr r4, [pc, r4] */
/* @0x240150 mov r6, r2 */
/* @0x240154 cmp r12, #0 */
/* @0x240158 ldr r3, [r4] */
/* @0x24015c str r3, [sp, #0x44] */
/* @0x240160 beq 0x2401d8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xa4> */
/* @0x240164 cmp r12, #1 */
/* @0x240168 bne 0x2401bc <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x88> */
/* @0x24016c ldr r0, [r0] */
/* @0x240170 ldr r3, [r0, #0x24] */
/* @0x240174 cmp r3, #1 */
/* @0x240178 bls 0x24019c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x68> */
/* @0x24017c ldr r3, [r0, #0x4] */
/* @0x240180 cmp r3, #0 */
/* @0x240184 beq 0x240388 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x254> */
/* @0x240188 add r0, r3, #16 */
/* @0x24018c ldr r3, [r0, #0xc] */
/* @0x240190 bic r3, r3, #-16777216 */
/* @0x240194 cmp r3, #6 */
/* @0x240198 beq 0x2402c8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x194> */
/* @0x24019c ldr r1, [pc, #0x21c] */
/* @0x2401a0 mov r0, r7 */
/* @0x2401a4 add r1, pc, r1 */
/* @0x2401a8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2401ac mov r3, #2 */
/* @0x2401b0 mov r0, #1 */
/* @0x2401b4 str r3, [r5, #0x4] */
/* @0x2401b8 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c> */
/* @0x2401bc mov r0, #0 */
/* @0x2401c0 ldr r2, [sp, #0x44] */
/* @0x2401c4 ldr r3, [r4] */
/* @0x2401c8 cmp r2, r3 */
/* @0x2401cc bne 0x2403b8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x284> */
/* @0x2401d0 add sp, sp, #76 */
/* @0x2401d4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2401d8 ldr r3, [r0] */
/* @0x2401dc ldr r2, [r0, #0x8] */
/* @0x2401e0 ldr r3, [r3, #0x60] */
/* @0x2401e4 cmp r2, #0 */
/* @0x2401e8 ldr r8, [r3, #0x4] */
/* @0x2401ec blt 0x2402b8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x184> */
/* @0x2401f0 cmp r8, r2 */
/* @0x2401f4 blt 0x2402a8 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x174> */
/* @0x2401f8 ldr r3, [r3, #0x10] */
/* @0x2401fc b 0x240208 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xd4> */
/* @0x240200 add r12, r12, #1 */
/* @0x240204 add r3, r3, #12 */
/* @0x240208 ldr lr, [r3, #0x8] */
/* @0x24020c cmp lr, #0 */
/* @0x240210 ble 0x240204 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xd0> */
/* @0x240214 cmp r2, r12 */
/* @0x240218 bne 0x240200 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xcc> */
/* @0x24021c ldr r2, [r3] */
/* @0x240220 add r9, r3, #4 */
/* @0x240224 add r2, r2, #99328 */
/* @0x240228 add r2, r2, #672 */
/* @0x24022c ldr r0, [pc, #0x190] */
/* @0x240230 mvn r1, #8 */
/* @0x240234 add r0, pc, r0 */
/* @0x240238 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x24023c ldr r3, [r9] */
/* @0x240240 ldr r12, [r3] */
/* @0x240244 ldr r2, [r3, #0x8] */
/* @0x240248 mov r1, r0 */
/* @0x24024c ldr r0, [r3, #0x4] */
/* @0x240250 ldr r3, [r3, #0xc] */
/* @0x240254 str r12, [r6] */
/* @0x240258 str r0, [r6, #0x4] */
/* @0x24025c str r2, [r6, #0x8] */
/* @0x240260 str r3, [r6, #0xc] */
/* @0x240264 ldr r3, [r5, #0x8] */
/* @0x240268 add r3, r3, #1 */
/* @0x24026c str r3, [r5, #0x8] */
/* @0x240270 cmp r3, r8 */
/* @0x240274 blo 0x240298 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x164> */
/* @0x240278 ldr r3, [r5] */
/* @0x24027c ldr r3, [r3, #0x24] */
/* @0x240280 cmp r3, #1 */
/* @0x240284 movhi r2, #1 */
/* @0x240288 movhi r3, #0 */
/* @0x24028c movls r3, #2 */
/* @0x240290 stmibhi r5, {r2, r3} */
/* @0x240294 strls r3, [r5, #0x4] */
/* @0x240298 mov r0, r7 */
/* @0x24029c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2402a0 mov r0, #1 */
/* @0x2402a4 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c> */
/* @0x2402a8 movw r2, #0x869f */
/* @0x2402ac mov r9, r12 */
/* @0x2402b0 movt r2, #0x1 */
/* @0x2402b4 b 0x24022c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xf8> */
/* @0x2402b8 movw r2, #0x869f */
/* @0x2402bc mov r9, r12 */
/* @0x2402c0 movt r2, #0x1 */
/* @0x2402c4 b 0x24022c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0xf8> */
/* @0x2402c8 ldr r0, [r5] */
/* @0x2402cc ldr r3, [r0, #0x4] */
/* @0x2402d0 cmp r3, #0 */
/* @0x2402d4 beq 0x240394 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x260> */
/* @0x2402d8 add r0, r3, #16 */
/* @0x2402dc ldr r3, [r0] */
/* @0x2402e0 ldr r8, [r3, #0x24] */
/* @0x2402e4 cmp r8, #0 */
/* @0x2402e8 ble 0x24019c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x68> */
/* @0x2402ec add r9, sp, #4 */
/* @0x2402f0 ldr r2, [pc, #0xd0] */
/* @0x2402f4 ldr r3, [r5, #0x8] */
/* @0x2402f8 mov r1, #64 */
/* @0x2402fc add r2, pc, r2 */
/* @0x240300 mov r0, r9 */
/* @0x240304 bl 0xb65c8 <snprintf@plt> */
/* @0x240308 ldr r0, [r5] */
/* @0x24030c mov r3, #0 */
/* @0x240310 strb r3, [sp, #0x43] */
/* @0x240314 ldr r3, [r0, #0x4] */
/* @0x240318 cmp r3, #0 */
/* @0x24031c beq 0x2403ac <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x278> */
/* @0x240320 add r0, r3, #16 */
/* @0x240324 ldr r0, [r0] */
/* @0x240328 ldr r1, [r5, #0x8] */
/* @0x24032c ldr r3, [r0, #0x4] */
/* @0x240330 cmp r3, #0 */
/* @0x240334 beq 0x2403a0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x26c> */
/* @0x240338 add r3, r3, r1, lsl #4 */
/* @0x24033c ldr r0, [r3] */
/* @0x240340 ldr r1, [r3, #0x4] */
/* @0x240344 ldr r2, [r3, #0x8] */
/* @0x240348 ldr r3, [r3, #0xc] */
/* @0x24034c str r0, [r6] */
/* @0x240350 mov r0, r7 */
/* @0x240354 str r1, [r6, #0x4] */
/* @0x240358 mov r1, r9 */
/* @0x24035c str r2, [r6, #0x8] */
/* @0x240360 str r3, [r6, #0xc] */
/* @0x240364 ldr r3, [r5, #0x8] */
/* @0x240368 add r3, r3, #1 */
/* @0x24036c str r3, [r5, #0x8] */
/* @0x240370 cmp r8, r3 */
/* @0x240374 movle r3, #2 */
/* @0x240378 strle r3, [r5, #0x4] */
/* @0x24037c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x240380 mov r0, #1 */
/* @0x240384 b 0x2401c0 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x8c> */
/* @0x240388 mov r1, r12 */
/* @0x24038c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240390 b 0x24018c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x58> */
/* @0x240394 mov r1, #1 */
/* @0x240398 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24039c b 0x2402dc <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x1a8> */
/* @0x2403a0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2403a4 mov r3, r0 */
/* @0x2403a8 b 0x24033c <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x208> */
/* @0x2403ac mov r1, #1 */
/* @0x2403b0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2403b4 b 0x240324 <_ZN29YYObject_PropertyNameIterator12NextInternalEP6RValueS1_+0x1f0> */
/* @0x2403b8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2403bc andseq sp, r10, r4, lsl #16 */
/* @0x2403c0 muleq lr, r2, r9 */
/* @0x2403c4 andeq lr, lr, r2, lsl #18 */
/* @0x2403c8 andeq r2, pc, r0, lsl r2 */

/* ── FUNC 0x2403cc · F_JS_ToObject(RValue*, RValue*) · size=240 · insn=60 */
/* @0x2403cc push {r3, r4, r5, lr} */
/* @0x2403d0 ldr r3, [r1, #0xc] */
/* @0x2403d4 bic r3, r3, #-16777216 */
/* @0x2403d8 cmp r3, #12 */
/* @0x2403dc addls pc, pc, r3, lsl #2 */
/* @0x2403e0 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x2403e4 b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84> */
/* @0x2403e8 b 0x240424 <_Z13F_JS_ToObjectP6RValueS0_+0x58> */
/* @0x2403ec b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x2403f0 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x2403f4 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x2403f8 b 0x240418 <_Z13F_JS_ToObjectP6RValueS0_+0x4c> */
/* @0x2403fc b 0x240464 <_Z13F_JS_ToObjectP6RValueS0_+0x98> */
/* @0x240400 b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84> */
/* @0x240404 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x240408 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x24040c b 0x240450 <_Z13F_JS_ToObjectP6RValueS0_+0x84> */
/* @0x240410 b 0x240490 <_Z13F_JS_ToObjectP6RValueS0_+0xc4> */
/* @0x240414 b 0x240418 <_Z13F_JS_ToObjectP6RValueS0_+0x4c> */
/* @0x240418 mov r3, #1 */
/* @0x24041c mov r0, r3 */
/* @0x240420 pop {r3, r4, r5, pc} */
/* @0x240424 ldr r3, [pc, #0x7c] */
/* @0x240428 ldr r1, [pc, #0x7c] */
/* @0x24042c ldr r3, [pc, r3] */
/* @0x240430 add r1, pc, r1 */
/* @0x240434 ldr r0, [r3] */
/* @0x240438 ldr r3, [r0] */
/* @0x24043c ldr r3, [r3, #0xc] */
/* @0x240440 blx r3 */
/* @0x240444 mov r3, #1 */
/* @0x240448 mov r0, r3 */
/* @0x24044c pop {r3, r4, r5, pc} */
/* @0x240450 ldr r3, [pc, #0x58] */
/* @0x240454 ldr r1, [pc, #0x58] */
/* @0x240458 ldr r3, [pc, r3] */
/* @0x24045c add r1, pc, r1 */
/* @0x240460 b 0x240434 <_Z13F_JS_ToObjectP6RValueS0_+0x68> */
/* @0x240464 ldr r5, [r1] */
/* @0x240468 mov r3, #0 */
/* @0x24046c ldr r4, [r1, #0x4] */
/* @0x240470 ldr r12, [r1, #0x8] */
/* @0x240474 ldr r2, [r1, #0xc] */
/* @0x240478 str r5, [r0] */
/* @0x24047c str r4, [r0, #0x4] */
/* @0x240480 str r12, [r0, #0x8] */
/* @0x240484 str r2, [r0, #0xc] */
/* @0x240488 mov r0, r3 */
/* @0x24048c pop {r3, r4, r5, pc} */
/* @0x240490 ldr r0, [pc, #0x20] */
/* @0x240494 add r0, pc, r0 */
/* @0x240498 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x24049c mov r3, #1 */
/* @0x2404a0 mov r0, r3 */
/* @0x2404a4 pop {r3, r4, r5, pc} */
/* @0x2404a8 andseq sp, r10, r8, ror #5 */
/* @0x2404ac andseq r5, r1, r12, asr #32 */
/* @0x2404b0 ldrheq sp, [r10], -r12 */
/* @0x2404b4 ldrsbeq r4, [r1], -r4 */
/* @0x2404b8 andseq r5, r1, r8, lsr #32 */

/* ── FUNC 0x2404bc · JS_ToBoolean(RValue&) · size=204 · insn=51 */
/* @0x2404bc ldr r1, [r0, #0xc] */
/* @0x2404c0 push {r3, lr} */
/* @0x2404c4 bic r1, r1, #-16777216 */
/* @0x2404c8 cmp r1, #13 */
/* @0x2404cc addls pc, pc, r1, lsl #2 */
/* @0x2404d0 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404d4 b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c> */
/* @0x2404d8 b 0x24056c <_Z12JS_ToBooleanR6RValue+0xb0> */
/* @0x2404dc b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404e0 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404e4 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404e8 b 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c> */
/* @0x2404ec b 0x240520 <_Z12JS_ToBooleanR6RValue+0x64> */
/* @0x2404f0 b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c> */
/* @0x2404f4 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404f8 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x2404fc b 0x240528 <_Z12JS_ToBooleanR6RValue+0x6c> */
/* @0x240500 b 0x24050c <_Z12JS_ToBooleanR6RValue+0x50> */
/* @0x240504 b 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c> */
/* @0x240508 b 0x240550 <_Z12JS_ToBooleanR6RValue+0x94> */
/* @0x24050c ldr r0, [pc, #0x70] */
/* @0x240510 add r0, pc, r0 */
/* @0x240514 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x240518 mov r0, #0 */
/* @0x24051c pop {r3, pc} */
/* @0x240520 mov r0, #1 */
/* @0x240524 pop {r3, pc} */
/* @0x240528 ldm r0, {r2, r3} */
/* @0x24052c vmov d7, r2, r3 */
/* @0x240530 vcmp.f64 d7, #0 */
/* @0x240534 vmrs APSR_nzcv, fpscr */
/* @0x240538 beq 0x240518 <_Z12JS_ToBooleanR6RValue+0x5c> */
/* @0x24053c vcmp.f64 d7, d7 */
/* @0x240540 vmrs APSR_nzcv, fpscr */
/* @0x240544 movvs r0, #0 */
/* @0x240548 movvc r0, #1 */
/* @0x24054c pop {r3, pc} */
/* @0x240550 ldm r0, {r2, r3} */
/* @0x240554 vmov d6, r2, r3 */
/* @0x240558 vcmp.f64 d6, #0 */
/* @0x24055c vmrs APSR_nzcv, fpscr */
/* @0x240560 moveq r0, #0 */
/* @0x240564 movne r0, #1 */
/* @0x240568 pop {r3, pc} */
/* @0x24056c ldr r3, [r0] */
/* @0x240570 ldr r3, [r3] */
/* @0x240574 ldrb r0, [r3] */
/* @0x240578 adds r0, r0, #0 */
/* @0x24057c movne r0, #1 */
/* @0x240580 pop {r3, pc} */
/* @0x240584 ldrsbeq r4, [r1], -r0 */

/* ── FUNC 0x240588 · F_JSBooleanCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x240588 cmp r3, #0 */
/* @0x24058c push {r4, lr} */
/* @0x240590 mov r4, r0 */
/* @0x240594 ble 0x2405c4 <_Z15F_JSBooleanCallR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x240598 ldr r0, [sp, #0x8] */
/* @0x24059c bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x2405a0 mov r3, #13 */
/* @0x2405a4 str r3, [r4, #0xc] */
/* @0x2405a8 cmp r0, #0 */
/* @0x2405ac movne r3, #0 */
/* @0x2405b0 moveq r3, r0 */
/* @0x2405b4 movne r0, r3 */
/* @0x2405b8 movtne r3, #0x3ff0 */
/* @0x2405bc stm r4, {r0, r3} */
/* @0x2405c0 pop {r4, pc} */
/* @0x2405c4 mov r3, #0 */
/* @0x2405c8 mov r2, #13 */
/* @0x2405cc str r3, [r0] */
/* @0x2405d0 str r2, [r0, #0xc] */
/* @0x2405d4 str r3, [r0, #0x4] */
/* @0x2405d8 pop {r4, pc} */

/* ── FUNC 0x2405dc · F_JSBooleanConstruct(RValue&, CInstance*, CInstance*, int, RValue*) · size=380 · insn=95 */
/* @0x2405dc push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2405e0 subs r5, r3, #0 */
/* @0x2405e4 sub sp, sp, #12 */
/* @0x2405e8 mov r6, r0 */
/* @0x2405ec mov r9, r1 */
/* @0x2405f0 mov r8, r2 */
/* @0x2405f4 ldr r4, [sp, #0x28] */
/* @0x2405f8 movle r7, #0 */
/* @0x2405fc ble 0x24060c <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x240600 mov r0, r4 */
/* @0x240604 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x240608 mov r7, r0 */
/* @0x24060c mov r2, r8 */
/* @0x240610 mov r3, r5 */
/* @0x240614 str r4, [sp] */
/* @0x240618 mov r1, r9 */
/* @0x24061c mov r0, r6 */
/* @0x240620 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x240624 ldr r3, [pc, #0x114] */
/* @0x240628 ldr r4, [r6] */
/* @0x24062c ldr r3, [pc, r3] */
/* @0x240630 ldr r1, [r3] */
/* @0x240634 mov r0, r4 */
/* @0x240638 str r1, [r4, #0x18] */
/* @0x24063c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x240640 ldr r12, [r4, #0x28] */
/* @0x240644 ldr r3, [pc, #0xf8] */
/* @0x240648 mov r2, r7 */
/* @0x24064c ldr r1, [pc, #0xf4] */
/* @0x240650 orr r12, r12, #1 */
/* @0x240654 add r3, pc, r3 */
/* @0x240658 str r12, [r4, #0x28] */
/* @0x24065c mov r0, r4 */
/* @0x240660 add r1, pc, r1 */
/* @0x240664 str r3, [r4, #0x40] */
/* @0x240668 mov r3, #0 */
/* @0x24066c bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi> */
/* @0x240670 ldr r3, [pc, #0xd4] */
/* @0x240674 mvn r1, #-16777216 */
/* @0x240678 mov r2, #0 */
/* @0x24067c ldr r3, [pc, r3] */
/* @0x240680 ldr r0, [r3] */
/* @0x240684 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x240688 ldr r1, [pc, #0xc0] */
/* @0x24068c ldr r2, [r6] */
/* @0x240690 mov r3, #6 */
/* @0x240694 add r1, pc, r1 */
/* @0x240698 mov r5, r0 */
/* @0x24069c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i> */
/* @0x2406a0 ldr r3, [pc, #0xac] */
/* @0x2406a4 mov r0, r5 */
/* @0x2406a8 ldr r3, [pc, r3] */
/* @0x2406ac ldr r1, [r3] */
/* @0x2406b0 str r1, [r5, #0x18] */
/* @0x2406b4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2406b8 ldr r1, [r4, #0x4] */
/* @0x2406bc cmp r1, #0 */
/* @0x2406c0 beq 0x2406f8 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x2406c4 str r5, [r1] */
/* @0x2406c8 mov r0, r4 */
/* @0x2406cc mov r1, r5 */
/* @0x2406d0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x2406d4 ldr r1, [r4, #0x4] */
/* @0x2406d8 cmp r1, #0 */
/* @0x2406dc movne r3, #6 */
/* @0x2406e0 strne r3, [r1, #0xc] */
/* @0x2406e4 beq 0x240708 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x2406e8 mov r3, #6 */
/* @0x2406ec str r3, [r1, #0x8] */
/* @0x2406f0 add sp, sp, #12 */
/* @0x2406f4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2406f8 mov r0, r4 */
/* @0x2406fc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240700 mov r1, r0 */
/* @0x240704 b 0x2406c4 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x240708 mov r0, r4 */
/* @0x24070c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x240710 ldr r1, [r4, #0x4] */
/* @0x240714 mov r3, #6 */
/* @0x240718 cmp r1, #0 */
/* @0x24071c str r3, [r0, #0xc] */
/* @0x240720 bne 0x2406e8 <_Z20F_JSBooleanConstructR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x240724 mov r0, r4 */
/* @0x240728 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24072c mov r3, #6 */
/* @0x240730 mov r1, r0 */
/* @0x240734 str r3, [r1, #0x8] */
/* @0x240738 add sp, sp, #12 */
/* @0x24073c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x240740 ldrsheq r0, [r11], -r8 */
/* @0x240744 ldrheq r4, [r1], -r4 */
/* @0x240748 ldrheq r4, [r1], -r0 */
/* @0x24074c mulseq r10, r8, r6 */
/* @0x240750 mulseq r1, r0, lr */
/* @0x240754 ldrsheq sp, [r10], -r8 */

/* ── FUNC 0x240758 · JS_IsCallable_Object(YYObjectBase*) · size=20 · insn=5 */
/* @0x240758 ldr r0, [r0, #0x48] */
/* @0x24075c subs r3, r0, #3 */
/* @0x240760 rsbs r0, r3, #0 */
/* @0x240764 adcs r0, r0, r3 */
/* @0x240768 bx lr */

/* ── FUNC 0x24076c · JS_IsCallable(RValue&) · size=124 · insn=31 */
/* @0x24076c ldr r1, [r0, #0xc] */
/* @0x240770 push {r3, lr} */
/* @0x240774 bic r1, r1, #-16777216 */
/* @0x240778 cmp r1, #7 */
/* @0x24077c beq 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x240780 bgt 0x2407b8 <_Z13JS_IsCallableR6RValue+0x4c> */
/* @0x240784 cmp r1, #5 */
/* @0x240788 beq 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x24078c ble 0x24079c <_Z13JS_IsCallableR6RValue+0x30> */
/* @0x240790 ldr r0, [r0] */
/* @0x240794 pop {r3, lr} */
/* @0x240798 b 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase> */
/* @0x24079c cmp r1, #1 */
/* @0x2407a0 bls 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x2407a4 ldr r0, [pc, #0x38] */
/* @0x2407a8 add r0, pc, r0 */
/* @0x2407ac bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x2407b0 mov r0, #0 */
/* @0x2407b4 pop {r3, pc} */
/* @0x2407b8 cmp r1, #13 */
/* @0x2407bc bgt 0x2407d4 <_Z13JS_IsCallableR6RValue+0x68> */
/* @0x2407c0 cmp r1, #12 */
/* @0x2407c4 bge 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x2407c8 cmp r1, #10 */
/* @0x2407cc bne 0x2407a4 <_Z13JS_IsCallableR6RValue+0x38> */
/* @0x2407d0 b 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x2407d4 mvn r3, #-16777216 */
/* @0x2407d8 cmp r1, r3 */
/* @0x2407dc bne 0x2407a4 <_Z13JS_IsCallableR6RValue+0x38> */
/* @0x2407e0 b 0x2407b0 <_Z13JS_IsCallableR6RValue+0x44> */
/* @0x2407e4 andseq r4, r1, r8, lsl #27 */

/* ── FUNC 0x2407e8 · JS_IsDataDescriptor(RValue*) · size=64 · insn=16 */
/* @0x2407e8 ldr r3, [r0, #0xc] */
/* @0x2407ec mvn r2, #-16777216 */
/* @0x2407f0 and r3, r3, r2 */
/* @0x2407f4 cmp r3, r2 */
/* @0x2407f8 beq 0x240820 <_Z19JS_IsDataDescriptorP6RValue+0x38> */
/* @0x2407fc cmp r3, #6 */
/* @0x240800 beq 0x24080c <_Z19JS_IsDataDescriptorP6RValue+0x24> */
/* @0x240804 mov r0, #1 */
/* @0x240808 bx lr */
/* @0x24080c ldr r3, [r0] */
/* @0x240810 ldr r0, [r3, #0x48] */
/* @0x240814 subs r0, r0, #2 */
/* @0x240818 movne r0, #1 */
/* @0x24081c bx lr */
/* @0x240820 mov r0, #0 */
/* @0x240824 bx lr */

/* ── FUNC 0x240828 · JS_IsAccessorDescriptor(RValue*) · size=48 · insn=12 */
/* @0x240828 ldr r3, [r0, #0xc] */
/* @0x24082c bic r3, r3, #-16777216 */
/* @0x240830 cmp r3, #6 */
/* @0x240834 beq 0x240840 <_Z23JS_IsAccessorDescriptorP6RValue+0x18> */
/* @0x240838 mov r0, #0 */
/* @0x24083c bx lr */
/* @0x240840 ldr r3, [r0] */
/* @0x240844 ldr r0, [r3, #0x48] */
/* @0x240848 subs r3, r0, #2 */
/* @0x24084c rsbs r0, r3, #0 */
/* @0x240850 adcs r0, r0, r3 */
/* @0x240854 bx lr */
