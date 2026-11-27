/* libyoyo.so 覆盖卡组 0288
 * 函数 0x2e5fb6..0x2e69f2，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e5fb6 · FT_Reference_Library · size=20 · insn=9 */
/* @0x2e5fb6 cbz r0, 0x2e5fc6 <FT_Reference_Library+0x10> */
/* @0x2e5fb8 ldr.w r3, [r0, #0xbc] */
/* @0x2e5fba movwlo r3, #0x10bc */
/* @0x2e5fbc adds r3, #0x1 */
/* @0x2e5fbe str.w r3, [r0, #0xbc] */
/* @0x2e5fc2 movs r0, #0x0 */
/* @0x2e5fc4 bx lr */
/* @0x2e5fc6 movs r0, #0x21 */
/* @0x2e5fc8 bx lr */

/* ── FUNC 0x2e5fca · FT_Library_Version · size=30 · insn=15 */
/* @0x2e5fca push {r4, r5, lr} */
/* @0x2e5fcc cbz r0, 0x2e5fd6 <FT_Library_Version+0xc> */
/* @0x2e5fce ldr r5, [r0, #0x4] */
/* @0x2e5fd0 ldr r4, [r0, #0x8] */
/* @0x2e5fd2 ldr r0, [r0, #0xc] */
/* @0x2e5fd4 b 0x2e5fda <FT_Library_Version+0x10> */
/* @0x2e5fd6 mov r4, r0 */
/* @0x2e5fd8 mov r5, r0 */
/* @0x2e5fda cbz r1, 0x2e5fde <FT_Library_Version+0x14> */
/* @0x2e5fdc str r5, [r1] */
/* @0x2e5fde cbz r2, 0x2e5fe2 <FT_Library_Version+0x18> */
/* @0x2e5fe0 str r4, [r2] */
/* @0x2e5fe2 cbz r3, 0x2e5fe6 <FT_Library_Version+0x1c> */
/* @0x2e5fe4 str r0, [r3] */
/* @0x2e5fe6 pop {r4, r5, pc} */

/* ── FUNC 0x2e5fe8 · FT_Set_Debug_Hook · size=18 · insn=7 */
/* @0x2e5fe8 cbz r0, 0x2e5ff8 <FT_Set_Debug_Hook+0x10> */
/* @0x2e5fea cbz r2, 0x2e5ff8 <FT_Set_Debug_Hook+0x10> */
/* @0x2e5fec cmp r1, #0x3 */
/* @0x2e5fee itt ls */
/* @0x2e5ff0 addls.w r1, r0, r1, lsl #2 */
/* @0x2e5ff4 strls.w r2, [r1, #0xac] */
/* @0x2e5ff8 bx lr */

/* ── FUNC 0x2e5ffc · FT_Get_TrueType_Engine_Type · size=48 · insn=23 */
/* @0x2e5ffc push {r3, lr} */
/* @0x2e5ffe cbnz r0, 0x2e6004 <FT_Get_TrueType_Engine_Type+0x8> */
/* @0x2e6000 movs r0, #0x0 */
/* @0x2e6002 pop {r3, pc} */
/* @0x2e6004 ldr r1, [pc, #0x1c] */
/* @0x2e6006 add r1, pc */
/* @0x2e6008 bl 0x2e5ef0 <FT_Get_Module> */
/* @0x2e600c cmp r0, #0x0 */
/* @0x2e600e beq 0x2e6000 <FT_Get_TrueType_Engine_Type+0x4> */
/* @0x2e6010 ldr r1, [pc, #0x14] */
/* @0x2e6012 movs r2, #0x0 */
/* @0x2e6014 add r1, pc */
/* @0x2e6016 bl 0x2e5f36 <ft_module_get_service> */
/* @0x2e6018 stmdahs r0, {r1, r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e601a cmp r0, #0x0 */
/* @0x2e601c beq 0x2e6000 <FT_Get_TrueType_Engine_Type+0x4> */
/* @0x2e601e ldr r0, [r0] */
/* @0x2e6020 pop {r3, pc} */
/* @0x2e6022 nop */
/* @0x2e6024 strh r2, [r3, #0x38] */
/* @0x2e6026 movs r2, r1 */
/* @0x2e6028 strh r5, [r2, #0x38] */
/* @0x2e602a movs r2, r1 */

/* ── FUNC 0x2e602c · FT_Get_SubGlyph_Info · size=76 · insn=36 */
/* @0x2e602c push {r4, r5, r6, r7, lr} */
/* @0x2e602e ldr r4, [sp, #0x1c] */
/* @0x2e6030 cbz r0, 0x2e606e <FT_Get_SubGlyph_Info+0x42> */
/* @0x2e6032 ldr.w r5, [r0, #0x84] */
/* @0x2e6034 bicslt r5, r5, r4, lsl #1 */
/* @0x2e6036 cbz r5, 0x2e606e <FT_Get_SubGlyph_Info+0x42> */
/* @0x2e6038 ldr r6, [r0, #0x48] */
/* @0x2e603a ldr r7, [pc, #0x38] */
/* @0x2e603c cmp r6, r7 */
/* @0x2e603e bne 0x2e606e <FT_Get_SubGlyph_Info+0x42> */
/* @0x2e6040 ldr.w r0, [r0, #0x80] */
/* @0x2e6044 cmp r1, r0 */
/* @0x2e6046 bhs 0x2e606e <FT_Get_SubGlyph_Info+0x42> */
/* @0x2e6048 lsls r1, r1, #0x5 */
/* @0x2e604a adds r0, r5, r1 */
/* @0x2e604c ldr r1, [r5, r1] */
/* @0x2e604e str r1, [r2] */
/* @0x2e6050 ldrh r2, [r0, #0x4] */
/* @0x2e6052 str r2, [r3] */
/* @0x2e6054 ldr r3, [sp, #0x14] */
/* @0x2e6056 ldr r2, [r0, #0x8] */
/* @0x2e6058 str r2, [r3] */
/* @0x2e605a ldr r3, [sp, #0x18] */
/* @0x2e605c ldr r2, [r0, #0xc] */
/* @0x2e605e str r2, [r3] */
/* @0x2e6060 add.w r3, r0, #0x10 */
/* @0x2e6064 ldm r3, {r0, r1, r2, r3} */
/* @0x2e6066 stm.w r4, {r0, r1, r2, r3} */
/* @0x2e6068 andhs r0, r0, pc */
/* @0x2e606a movs r0, #0x0 */
/* @0x2e606c pop {r4, r5, r6, r7, pc} */
/* @0x2e606e movs r0, #0x6 */
/* @0x2e6070 pop {r4, r5, r6, r7, pc} */
/* @0x2e6072 nop */
/* @0x2e6074 ldr r0, [r6, #0x54] */
/* @0x2e6076 str r7, [r5, #0x34] */

/* ── FUNC 0x2e6078 · FT_Outline_Decompose · size=678 · insn=302 */
/* @0x2e6078 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e607c sub sp, #0x4c */
/* @0x2e607e mov r7, r1 */
/* @0x2e6080 mov r9, r2 */
/* @0x2e6082 str r0, [sp, #0xc] */
/* @0x2e6084 cmp r0, #0x0 */
/* @0x2e6086 beq.w 0x2e619a <FT_Outline_Decompose+0x122> */
/* @0x2e6088 stmdbhs r0, {r3, r7, pc} */
/* @0x2e608a cmp r1, #0x0 */
/* @0x2e608c beq.w 0x2e6316 <FT_Outline_Decompose+0x29e> */
/* @0x2e6090 movs r3, #0x0 */
/* @0x2e6092 add.w r8, sp, #0x40 */
/* @0x2e6094 stmdbvs sp, {r6, r11} */
/* @0x2e6096 ldr r5, [r1, #0x10] */
/* @0x2e6098 ldr r6, [r1, #0x14] */
/* @0x2e609a str r3, [sp, #0x14] */
/* @0x2e609c str.w r8, [sp, #0x1c] */
/* @0x2e60a0 b 0x2e6178 <FT_Outline_Decompose+0x100> */
/* @0x2e60a2 ldr.w r8, [r0, #0x4] */
/* @0x2e60a4 stmdage r10, {r2, pc} */
/* @0x2e60a6 add r0, sp, #0x28 */
/* @0x2e60a8 str r0, [sp, #0x4] */
/* @0x2e60aa add.w r4, r8, r3, lsl #3 */
/* @0x2e60ac bl 0x4e73c0 <SrcVerts+0x44404> */
/* @0x2e60ae add.w r11, r8, r2, lsl #3 */
/* @0x2e60b0 bls 0x328fc0 */
/* @0x2e60b2 ldr r2, [sp, #0x4] */
/* @0x2e60b4 ldm.w r4, {r0, r1} */
/* @0x2e60b8 stm.w r2, {r0, r1} */
/* @0x2e60bc lsl.w r12, r0, r5 */
/* @0x2e60c0 ldr r2, [sp, #0x2c] */
/* @0x2e60c2 rsb r12, r6, r12 */
/* @0x2e60c4 stmdbls r4, {r2, r3, r10, r11} */
/* @0x2e60c6 ldr r1, [sp, #0x10] */
/* @0x2e60c8 str.w r12, [sp, #0x28] */
/* @0x2e60cc lsls r2, r5 */
/* @0x2e60ce subs r2, r2, r6 */
/* @0x2e60d0 str r2, [sp, #0x2c] */
/* @0x2e60d2 ldr.w r0, [r8, r1, lsl #3] */
/* @0x2e60d4 .word 0xf10d0031 */
/* @0x2e60d6 add.w r8, sp, #0x20 */
/* @0x2e60d8 .word 0xf8db0820 */
/* @0x2e60da ldr.w r1, [r11, #0x4] */
/* @0x2e60dc .word 0xf8cd1004 */
/* @0x2e60de str.w r8, [sp, #0x8] */
/* @0x2e60e0 .word 0xf8dd8008 */
/* @0x2e60e2 ldr.w r8, [sp, #0x4] */
/* @0x2e60e4 adcmi r8, r8, r4 */
/* @0x2e60e6 lsls r0, r5 */
/* @0x2e60e8 lsl.w r10, r1, r5 */
/* @0x2e60ec str r0, [sp, #0x18] */
/* @0x2e60ee ldm.w r8, {r0, r1} */
/* @0x2e60f0 .word 0xf8dd0003 */
/* @0x2e60f2 ldr.w r8, [sp, #0x8] */
/* @0x2e60f4 stm r8, {r3, pc} */
/* @0x2e60f6 stm.w r8, {r0, r1} */
/* @0x2e60f8 stmdals r3, {r0, r1} */
/* @0x2e60fa ldr r0, [sp, #0xc] */
/* @0x2e60fc ldr r1, [r0, #0x8] */
/* @0x2e60fe add.w r8, r1, r3 */
/* @0x2e6100 stclpl p8, c0, [r11], {3} */
/* @0x2e6102 ldrb r3, [r1, r3] */
/* @0x2e6104 and r3, r3, #0x3 */
/* @0x2e6108 cmp r3, #0x2 */
/* @0x2e610a beq 0x2e619a <FT_Outline_Decompose+0x122> */
/* @0x2e610c cmp r3, #0x0 */
/* @0x2e610e beq 0x2e619e <FT_Outline_Decompose+0x126> */
/* @0x2e6110 ldr r3, [r7] */
/* @0x2e6112 add r0, sp, #0x28 */
/* @0x2e6114 mov r1, r9 */
/* @0x2e6116 blx r3 */
/* @0x2e6118 cmp r0, #0x0 */
/* @0x2e611a bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e611c stmdage r12, {r0, r2, r3, r4, r5, r6, r7, pc} */
/* @0x2e611e add r0, sp, #0x30 */
/* @0x2e6120 str r0, [sp, #0x18] */
/* @0x2e6122 cmp r4, r11 */
/* @0x2e6124 bhs.w 0x2e6308 <FT_Outline_Decompose+0x290> */
/* @0x2e6128 ldrb.w r3, [r8, #0x1] */
/* @0x2e612c add.w r10, r4, #0x8 */
/* @0x2e6130 add.w r2, r8, #0x1 */
/* @0x2e6134 ands r3, r3, #0x3 */
/* @0x2e6138 bne 0x2e61de <FT_Outline_Decompose+0x166> */
/* @0x2e613a ldr r3, [r4, #0x8] */
/* @0x2e613c lsls r3, r5 */
/* @0x2e613e subs r3, r3, r6 */
/* @0x2e6140 str r3, [sp, #0x20] */
/* @0x2e6142 ldr r3, [r4, #0xc] */
/* @0x2e6144 add.w r4, r8, #0x2 */
/* @0x2e6148 lsls r3, r5 */
/* @0x2e614a subs r3, r3, r6 */
/* @0x2e614c str r3, [sp, #0x24] */
/* @0x2e614e mov r3, r10 */
/* @0x2e6150 cmp r3, r11 */
/* @0x2e6152 blo 0x2e6208 <FT_Outline_Decompose+0x190> */
/* @0x2e6154 ldr r3, [r7, #0x8] */
/* @0x2e6156 add r0, sp, #0x20 */
/* @0x2e6158 add r1, sp, #0x28 */
/* @0x2e615a mov r2, r9 */
/* @0x2e615c blx r3 */
/* @0x2e615e cmp r0, #0x0 */
/* @0x2e6160 bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e6164 ldr.w r8, [sp, #0x10] */
/* @0x2e6168 add.w r3, r8, #0x1 */
/* @0x2e616c ldr.w r8, [sp, #0x14] */
/* @0x2e6170 add.w r8, r8, #0x1 */
/* @0x2e6174 str.w r8, [sp, #0x14] */
/* @0x2e6178 ldr r0, [sp, #0xc] */
/* @0x2e617a ldr.w r8, [sp, #0x14] */
/* @0x2e617c rfeib r0! */
/* @0x2e617e ldrsh.w r2, [r0] */
/* @0x2e6180 ldrmi r2, [r0] */
/* @0x2e6182 cmp r8, r2 */
/* @0x2e6184 bge.w 0x2e6312 <FT_Outline_Decompose+0x29a> */
/* @0x2e6188 ldr r0, [sp, #0xc] */
/* @0x2e618a ldr.w r8, [sp, #0x14] */
/* @0x2e618c stmvs r2, {r2, r4, pc} ^ */
/* @0x2e618e ldr r2, [r0, #0xc] */
/* @0x2e6190 ldrsh.w r2, [r2, r8, lsl #1] */
/* @0x2e6194 cmp r2, #0x0 */
/* @0x2e6196 str r2, [sp, #0x10] */
/* @0x2e6198 bge 0x2e60a2 <FT_Outline_Decompose+0x2a> */
/* @0x2e619a movs r0, #0x14 */
/* @0x2e619c b 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e619e ldr.w lr, [sp, #0x10] */
/* @0x2e61a0 blls 0x49e1e8 <TimingData+0x41d0> */
/* @0x2e61a2 ldr r3, [sp, #0x18] */
/* @0x2e61a4 ldrb.w r1, [r1, lr] */
/* @0x2e61a8 subs r0, r3, r6 */
/* @0x2e61aa rsb r3, r6, r10 */
/* @0x2e61ac .word 0xf001030a */
/* @0x2e61ae and r1, r1, #0x3 */
/* @0x2e61b0 stmdbhs r1, {r0, r1, r8} */
/* @0x2e61b2 cmp r1, #0x1 */
/* @0x2e61b4 bne 0x2e61c0 <FT_Outline_Decompose+0x148> */
/* @0x2e61b6 str r0, [sp, #0x28] */
/* @0x2e61b8 sub.w r11, r11, #0x8 */
/* @0x2e61bc str r3, [sp, #0x2c] */
/* @0x2e61be b 0x2e61d6 <FT_Outline_Decompose+0x15e> */
/* @0x2e61c0 add r12, r0 */
/* @0x2e61c2 add r2, r3 */
/* @0x2e61c4 add.w r12, r12, r12, lsr #31 */
/* @0x2e61c8 add.w r2, r2, r2, lsr #31 */
/* @0x2e61cc asr.w r1, r12, #0x1 */
/* @0x2e61d0 asrs r2, r2, #0x1 */
/* @0x2e61d2 str r1, [sp, #0x28] */
/* @0x2e61d4 str r2, [sp, #0x2c] */
/* @0x2e61d6 subs r4, #0x8 */
/* @0x2e61d8 add.w r8, r8, #0xffffffff */
/* @0x2e61dc b 0x2e6110 <FT_Outline_Decompose+0x98> */
/* @0x2e61de cmp r3, #0x1 */
/* @0x2e61e0 bne 0x2e6286 <FT_Outline_Decompose+0x20e> */
/* @0x2e61e2 ldr r3, [r4, #0x8] */
/* @0x2e61e4 add r0, sp, #0x40 */
/* @0x2e61e6 mov r1, r9 */
/* @0x2e61e8 lsls r3, r5 */
/* @0x2e61ea subs r3, r3, r6 */
/* @0x2e61ec str r3, [sp, #0x40] */
/* @0x2e61ee ldr r3, [r4, #0xc] */
/* @0x2e61f0 lsls r3, r5 */
/* @0x2e61f2 subs r3, r3, r6 */
/* @0x2e61f4 str r3, [sp, #0x44] */
/* @0x2e61f6 ldr r3, [r7, #0x4] */
/* @0x2e61f8 str r2, [sp] */
/* @0x2e61fa blx r3 */
/* @0x2e61fc ldr r2, [sp] */
/* @0x2e61fe cmp r0, #0x0 */
/* @0x2e6200 bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e6204 mov r8, r2 */
/* @0x2e6206 b 0x2e6304 <FT_Outline_Decompose+0x28c> */
/* @0x2e6208 ldr r2, [r3, #0x8] */
/* @0x2e620a mov r8, r4 */
/* @0x2e620c ldrb.w r1, [r8] */
/* @0x2e6210 add.w r12, r3, #0x8 */
/* @0x2e6214 adds r4, #0x1 */
/* @0x2e6216 lsls r2, r5 */
/* @0x2e6218 and r1, r1, #0x3 */
/* @0x2e621c subs r2, r2, r6 */
/* @0x2e621e str r2, [sp, #0x38] */
/* @0x2e6220 ldr r3, [r3, #0xc] */
/* @0x2e6222 cmp r1, #0x1 */
/* @0x2e6224 mov r10, r12 */
/* @0x2e6226 lsl.w r3, r3, r5 */
/* @0x2e6228 bl 0xff4a2e44 <b2_toiTime+0xfffffffffed499a0> */
/* @0x2e622a rsb r3, r6, r3 */
/* @0x2e622c movwls r0, #0xf303 */
/* @0x2e622e str r3, [sp, #0x3c] */
/* @0x2e6230 bne 0x2e6242 <FT_Outline_Decompose+0x1ca> */
/* @0x2e6232 ldr r3, [r7, #0x8] */
/* @0x2e6234 add r0, sp, #0x20 */
/* @0x2e6236 add r1, sp, #0x38 */
/* @0x2e6238 mov r2, r9 */
/* @0x2e623a blx r3 */
/* @0x2e623c cmp r0, #0x0 */
/* @0x2e623e bne 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e6240 b 0x2e6304 <FT_Outline_Decompose+0x28c> */
/* @0x2e6242 cmp r1, #0x0 */
/* @0x2e6244 bne 0x2e619a <FT_Outline_Decompose+0x122> */
/* @0x2e6246 ldr r1, [sp, #0x20] */
/* @0x2e6248 add r0, sp, #0x20 */
/* @0x2e624a add r2, r1 */
/* @0x2e624c add r1, sp, #0x40 */
/* @0x2e624e add.w r2, r2, r2, lsr #31 */
/* @0x2e6250 ldrsbne r7, [r2], #-34 */
/* @0x2e6252 asrs r2, r2, #0x1 */
/* @0x2e6254 str r2, [sp, #0x40] */
/* @0x2e6256 ldr r2, [sp, #0x24] */
/* @0x2e6258 add r3, r2 */
/* @0x2e625a mov r2, r9 */
/* @0x2e625c add.w r3, r3, r3, lsr #31 */
/* @0x2e6260 asrs r3, r3, #0x1 */
/* @0x2e6262 str r3, [sp, #0x44] */
/* @0x2e6264 ldr r3, [r7, #0x8] */
/* @0x2e6266 str.w r12, [sp] */
/* @0x2e6268 ldrmi r12, [r8, r0] */
/* @0x2e626a blx r3 */
/* @0x2e626c ldr.w r12, [sp] */
/* @0x2e6270 cmp r0, #0x0 */
/* @0x2e6272 bne 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e6274 add r3, sp, #0x38 */
/* @0x2e6276 ldr.w r8, [sp, #0x8] */
/* @0x2e6278 ldm r3, {r3, pc} */
/* @0x2e627a ldm.w r3, {r0, r1} */
/* @0x2e627c strbtmi r0, [r3], -r3 */
/* @0x2e627e mov r3, r12 */
/* @0x2e6280 stm.w r8, {r0, r1} */
/* @0x2e6284 b 0x2e6150 <FT_Outline_Decompose+0xd8> */
/* @0x2e6286 add.w r3, r4, #0x10 */
/* @0x2e6288 ldrmi r0, [r11, #0x310] */
/* @0x2e628a cmp r11, r3 */
/* @0x2e628c blo 0x2e619a <FT_Outline_Decompose+0x122> */
/* @0x2e628e ldrb.w r3, [r8, #0x2] */
/* @0x2e6290 .word 0xf0033002 */
/* @0x2e6292 and r3, r3, #0x3 */
/* @0x2e6294 blhs 0x366ea8 <_ZTS12CDS_Priority+0x8f00> */
/* @0x2e6296 cmp r3, #0x2 */
/* @0x2e6298 bne.w 0x2e619a <FT_Outline_Decompose+0x122> */
/* @0x2e629c ldr r3, [r4, #0x8] */
/* @0x2e629e add.w r10, r4, #0x18 */
/* @0x2e62a0 ldrbmi r0, [r10, #0xa18] */
/* @0x2e62a2 cmp r10, r11 */
/* @0x2e62a4 add r1, sp, #0x38 */
/* @0x2e62a6 lsl.w r3, r3, r5 */
/* @0x2e62a8 bl 0xff4a2ec4 <b2_toiTime+0xfffffffffed49a20> */
/* @0x2e62aa rsb r3, r6, r3 */
/* @0x2e62ac movwls r0, #0xc303 */
/* @0x2e62ae str r3, [sp, #0x30] */
/* @0x2e62b0 ldr r3, [r4, #0xc] */
/* @0x2e62b2 lsl.w r3, r3, r5 */
/* @0x2e62b4 bl 0xff4a2ed0 <b2_toiTime+0xfffffffffed49a2c> */
/* @0x2e62b6 rsb r3, r6, r3 */
/* @0x2e62b8 movwls r0, #0xd303 */
/* @0x2e62ba str r3, [sp, #0x34] */
/* @0x2e62bc ldr r3, [r4, #0x10] */
/* @0x2e62be lsl.w r3, r3, r5 */
/* @0x2e62c0 bl 0xff4a2edc <b2_toiTime+0xfffffffffed49a38> */
/* @0x2e62c2 rsb r3, r6, r3 */
/* @0x2e62c4 movwls r0, #0xe303 */
/* @0x2e62c6 str r3, [sp, #0x38] */
/* @0x2e62c8 ldr r3, [r4, #0x14] */
/* @0x2e62ca lsl.w r3, r3, r5 */
/* @0x2e62cc bl 0xff4a2ee8 <b2_toiTime+0xfffffffffed49a44> */
/* @0x2e62ce rsb r3, r6, r3 */
/* @0x2e62d0 movwls r0, #0xf303 */
/* @0x2e62d2 str r3, [sp, #0x3c] */
/* @0x2e62d4 bhi 0x2e62f8 <FT_Outline_Decompose+0x280> */
/* @0x2e62d6 ldr r3, [r4, #0x18] */
/* @0x2e62d8 add r0, sp, #0x30 */
/* @0x2e62da add r2, sp, #0x40 */
/* @0x2e62dc lsls r3, r5 */
/* @0x2e62de subs r3, r3, r6 */
/* @0x2e62e0 str r3, [sp, #0x40] */
/* @0x2e62e2 ldr r3, [r4, #0x1c] */
/* @0x2e62e4 ldr r4, [r7, #0xc] */
/* @0x2e62e6 lsls r3, r5 */
/* @0x2e62e8 subs r3, r3, r6 */
/* @0x2e62ea str r3, [sp, #0x44] */
/* @0x2e62ec mov r3, r9 */
/* @0x2e62ee blx r4 */
/* @0x2e62f0 cbnz r0, 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e62f2 add.w r8, r8, #0x3 */
/* @0x2e62f4 and r0, r5, r3, lsl #16 */
/* @0x2e62f6 b 0x2e6304 <FT_Outline_Decompose+0x28c> */
/* @0x2e62f8 ldr r4, [r7, #0xc] */
/* @0x2e62fa add r0, sp, #0x30 */
/* @0x2e62fc add r2, sp, #0x28 */
/* @0x2e62fe mov r3, r9 */
/* @0x2e6300 blx r4 */
/* @0x2e6302 b 0x2e615e <FT_Outline_Decompose+0xe6> */
/* @0x2e6304 mov r4, r10 */
/* @0x2e6306 b 0x2e6122 <FT_Outline_Decompose+0xaa> */
/* @0x2e6308 ldr r3, [r7, #0x4] */
/* @0x2e630a add r0, sp, #0x28 */
/* @0x2e630c mov r1, r9 */
/* @0x2e630e blx r3 */
/* @0x2e6310 b 0x2e615e <FT_Outline_Decompose+0xe6> */
/* @0x2e6312 movs r0, #0x0 */
/* @0x2e6314 b 0x2e6318 <FT_Outline_Decompose+0x2a0> */
/* @0x2e6316 movs r0, #0x6 */
/* @0x2e6318 add sp, #0x4c */
/* @0x2e631a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e631c ldrlt r8, [r0, #-0xff0]! */

/* ── FUNC 0x2e631e · FT_Outline_Check · size=78 · insn=35 */
/* @0x2e631e push {r4, r5, lr} */
/* @0x2e6320 cbz r0, 0x2e6368 <FT_Outline_Check+0x4a> */
/* @0x2e6322 ldrsh.w r1, [r0, #0x2] */
/* @0x2e6326 ldrsh.w r4, [r0] */
/* @0x2e632a cmp r1, #0x0 */
/* @0x2e632c bne 0x2e6338 <FT_Outline_Check+0x1a> */
/* @0x2e632e cmp r4, #0x0 */
/* @0x2e6330 ite ne */
/* @0x2e6332 movne r0, #0x6 */
/* @0x2e6334 moveq r0, #0x0 */
/* @0x2e6336 pop {r4, r5, pc} */
/* @0x2e6338 ble 0x2e6368 <FT_Outline_Check+0x4a> */
/* @0x2e633a cmp r4, #0x0 */
/* @0x2e633c ble 0x2e6368 <FT_Outline_Check+0x4a> */
/* @0x2e633e ldr r5, [r0, #0xc] */
/* @0x2e6340 movs r2, #0x0 */
/* @0x2e6342 mov.w r0, #0xffffffff */
/* @0x2e6346 ldrsh.w r3, [r5, r2, lsl #1] */
/* @0x2e634a cmp r3, r0 */
/* @0x2e634c ble 0x2e6368 <FT_Outline_Check+0x4a> */
/* @0x2e634e cmp r3, r1 */
/* @0x2e6350 bge 0x2e6368 <FT_Outline_Check+0x4a> */
/* @0x2e6352 adds r2, #0x1 */
/* @0x2e6354 cmp r2, r4 */
/* @0x2e6356 bge 0x2e635c <FT_Outline_Check+0x3e> */
/* @0x2e6358 mov r0, r3 */
/* @0x2e635a b 0x2e6346 <FT_Outline_Check+0x28> */
/* @0x2e635c subs r0, r1, #0x1 */
/* @0x2e635e cmp r3, r0 */
/* @0x2e6360 ite ne */
/* @0x2e6362 movne r0, #0x6 */
/* @0x2e6364 moveq r0, #0x0 */
/* @0x2e6366 pop {r4, r5, pc} */
/* @0x2e6368 movs r0, #0x6 */
/* @0x2e636a pop {r4, r5, pc} */

/* ── FUNC 0x2e636c · FT_Outline_Copy · size=96 · insn=48 */
/* @0x2e636c push {r3, r4, r5, lr} */
/* @0x2e636e mov r5, r1 */
/* @0x2e6370 mov r4, r0 */
/* @0x2e6372 cbz r0, 0x2e63c0 <FT_Outline_Copy+0x54> */
/* @0x2e6374 cbz r1, 0x2e63c0 <FT_Outline_Copy+0x54> */
/* @0x2e6376 ldr r2, [r0] */
/* @0x2e6378 ldr r3, [r1] */
/* @0x2e637a cmp r2, r3 */
/* @0x2e637c bne 0x2e63c4 <FT_Outline_Copy+0x58> */
/* @0x2e637e cmp r0, r1 */
/* @0x2e6380 beq 0x2e63c8 <FT_Outline_Copy+0x5c> */
/* @0x2e6382 ldrh r2, [r0, #0x2] */
/* @0x2e6384 cbz r2, 0x2e639e <FT_Outline_Copy+0x32> */
/* @0x2e6386 sxth r2, r2 */
/* @0x2e6388 ldr r0, [r1, #0x4] */
/* @0x2e638a ldr r1, [r4, #0x4] */
/* @0x2e638c lsls r2, r2, #0x3 */
/* @0x2e638e blx 0xb65bc <memcpy@plt> */
/* @0x2e6390 stmvs r8!, {r1, r2, r4, r8, r11, sp, lr, pc} */
/* @0x2e6392 ldr r0, [r5, #0x8] */
/* @0x2e6394 ldr r1, [r4, #0x8] */
/* @0x2e6396 ldrsh.w r2, [r4, #0x2] */
/* @0x2e6398 .word 0xf5d02002 */
/* @0x2e639a blx 0xb65bc <memcpy@plt> */
/* @0x2e639c stmdahi r2!, {r4, r8, r11, sp, lr, pc} */
/* @0x2e639e ldrh r2, [r4] */
/* @0x2e63a0 cbz r2, 0x2e63ae <FT_Outline_Copy+0x42> */
/* @0x2e63a2 sxth r2, r2 */
/* @0x2e63a4 ldr r0, [r5, #0xc] */
/* @0x2e63a6 ldr r1, [r4, #0xc] */
/* @0x2e63a8 lsls r2, r2, #0x1 */
/* @0x2e63aa blx 0xb65bc <memcpy@plt> */
/* @0x2e63ac stmdbvs r2!, {r3, r8, r11, sp, lr, pc} */
/* @0x2e63ae ldr r2, [r4, #0x10] */
/* @0x2e63b0 ldr r3, [r5, #0x10] */
/* @0x2e63b2 bic r2, r2, #0x1 */
/* @0x2e63b4 .word 0xf0030201 */
/* @0x2e63b6 and r3, r3, #0x1 */
/* @0x2e63b8 tstmi r3, #67108864 */
/* @0x2e63ba orrs r3, r2 */
/* @0x2e63bc str r3, [r5, #0x10] */
/* @0x2e63be b 0x2e63c8 <FT_Outline_Copy+0x5c> */
/* @0x2e63c0 movs r0, #0x14 */
/* @0x2e63c2 pop {r3, r4, r5, pc} */
/* @0x2e63c4 movs r0, #0x6 */
/* @0x2e63c6 pop {r3, r4, r5, pc} */
/* @0x2e63c8 movs r0, #0x0 */
/* @0x2e63ca pop {r3, r4, r5, pc} */

/* ── FUNC 0x2e63cc · FT_Outline_Get_CBox · size=88 · insn=42 */
/* @0x2e63cc push {r4, r5, r6, r7, lr} */
/* @0x2e63ce cbz r0, 0x2e6422 <FT_Outline_Get_CBox+0x56> */
/* @0x2e63d0 cbz r1, 0x2e6422 <FT_Outline_Get_CBox+0x56> */
/* @0x2e63d2 ldrh r3, [r0, #0x2] */
/* @0x2e63d4 cbz r3, 0x2e6416 <FT_Outline_Get_CBox+0x4a> */
/* @0x2e63d6 ldr r4, [r0, #0x4] */
/* @0x2e63d8 sxth r3, r3 */
/* @0x2e63da add.w r5, r4, #0x8 */
/* @0x2e63dc bl 0x3e7804 <error_g0017+0x404a8> */
/* @0x2e63de add.w r7, r4, r3, lsl #3 */
/* @0x2e63e0 ldm r4, {r0, r1, r6, r7, r8, r9, r10} */
/* @0x2e63e2 ldm.w r4, {r0, r2} */
/* @0x2e63e4 ldrmi r0, [r3], -r5 */
/* @0x2e63e6 mov r3, r2 */
/* @0x2e63e8 mov r4, r0 */
/* @0x2e63ea cmp r7, r5 */
/* @0x2e63ec add.w r6, r5, #0x8 */
/* @0x2e63f0 bls 0x2e641c <FT_Outline_Get_CBox+0x50> */
/* @0x2e63f2 ldr r5, [r6, #-8] */
/* @0x2e63f4 adcmi r5, r8, #8, #24 */
/* @0x2e63f6 cmp r0, r5 */
/* @0x2e63f8 it ge */
/* @0x2e63fa movge r0, r5 */
/* @0x2e63fc cmp r4, r5 */
/* @0x2e63fe it lt */
/* @0x2e6400 movlt r4, r5 */
/* @0x2e6402 ldr r5, [r6, #-4] */
/* @0x2e6404 adcmi r5, r10, #4, #24 */
/* @0x2e6406 cmp r2, r5 */
/* @0x2e6408 it ge */
/* @0x2e640a movge r2, r5 */
/* @0x2e640c cmp r3, r5 */
/* @0x2e640e it lt */
/* @0x2e6410 movlt r3, r5 */
/* @0x2e6412 mov r5, r6 */
/* @0x2e6414 b 0x2e63ea <FT_Outline_Get_CBox+0x1e> */
/* @0x2e6416 mov r4, r3 */
/* @0x2e6418 mov r2, r3 */
/* @0x2e641a mov r0, r3 */
/* @0x2e641c stm.w r1, {r0, r2, r4} */
/* @0x2e6420 str r3, [r1, #0xc] */
/* @0x2e6422 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6424 · FT_Outline_Translate · size=46 · insn=22 */
/* @0x2e6424 push {r4, r5, lr} */
/* @0x2e6426 cbz r0, 0x2e6450 <FT_Outline_Translate+0x2c> */
/* @0x2e6428 ldr r3, [r0, #0x4] */
/* @0x2e642a movs r4, #0x0 */
/* @0x2e642c ldrsh.w r5, [r0, #0x2] */
/* @0x2e6430 adds r3, #0x8 */
/* @0x2e6432 cmp r4, r5 */
/* @0x2e6434 bge 0x2e6450 <FT_Outline_Translate+0x2c> */
/* @0x2e6436 ldr r5, [r3, #-8] */
/* @0x2e6438 strlo r5, [r1], #-3080 */
/* @0x2e643a adds r4, #0x1 */
/* @0x2e643c add r5, r1 */
/* @0x2e643e str r5, [r3, #-8] */
/* @0x2e6440 .word 0xf8535c08 */
/* @0x2e6442 ldr r5, [r3, #-4] */
/* @0x2e6444 adclt r5, r4, #4, #24 */
/* @0x2e6446 uxth r4, r4 */
/* @0x2e6448 add r5, r2 */
/* @0x2e644a str r5, [r3, #-4] */
/* @0x2e644c strb r5, [sp, r4, lsl #24]! */
/* @0x2e644e b 0x2e642c <FT_Outline_Translate+0x8> */
/* @0x2e6450 pop {r4, r5, pc} */

/* ── FUNC 0x2e6452 · FT_Outline_Reverse · size=116 · insn=50 */
/* @0x2e6452 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e6456 mov r3, r0 */
/* @0x2e6458 cbz r0, 0x2e64c2 <FT_Outline_Reverse+0x70> */
/* @0x2e645a movs r6, #0x0 */
/* @0x2e645c mov r5, r6 */
/* @0x2e645e ldrsh.w r2, [r3] */
/* @0x2e6462 cmp r5, r2 */
/* @0x2e6464 bge 0x2e64ba <FT_Outline_Reverse+0x68> */
/* @0x2e6466 ldr r2, [r3, #0xc] */
/* @0x2e6468 ldr r4, [r3, #0x4] */
/* @0x2e646a ldrsh.w r7, [r2, r5, lsl #1] */
/* @0x2e646e add.w r2, r4, r6, lsl #3 */
/* @0x2e6472 add.w r4, r4, r7, lsl #3 */
/* @0x2e6476 cmp r2, r4 */
/* @0x2e6478 sub.w r4, r4, #0x8 */
/* @0x2e647a .word 0xf1020408 */
/* @0x2e647c add.w r2, r2, #0x8 */
/* @0x2e647e andle r0, r11, #8, #4 */
/* @0x2e6480 bhs 0x2e649a <FT_Outline_Reverse+0x48> */
/* @0x2e6482 add.w r1, r4, #0x8 */
/* @0x2e6486 ldmdb r2, {r8, r12} */
/* @0x2e648a ldm r1, {r0, r1} */
/* @0x2e648c stmdb r2, {r0, r1} */
/* @0x2e648e .word 0xf8c40003 */
/* @0x2e6490 str.w r8, [r4, #0x8] */
/* @0x2e6492 .word 0xf8c48008 */
/* @0x2e6494 str.w r12, [r4, #0xc] */
/* @0x2e6496 strb r12, [sp, r12]! */
/* @0x2e6498 b 0x2e6476 <FT_Outline_Reverse+0x24> */
/* @0x2e649a ldr r2, [r3, #0x8] */
/* @0x2e649c add r6, r2 */
/* @0x2e649e add r2, r7 */
/* @0x2e64a0 cmp r6, r2 */
/* @0x2e64a2 bhs 0x2e64b2 <FT_Outline_Reverse+0x60> */
/* @0x2e64a4 ldrb r1, [r6] */
/* @0x2e64a6 ldrb r0, [r2] */
/* @0x2e64a8 strb r0, [r6], #1 */
/* @0x2e64aa .word 0xf8020b01 */
/* @0x2e64ac strb r1, [r2], #-1 */
/* @0x2e64ae ldrb r1, [r6, r1, lsl #18]! */
/* @0x2e64b0 b 0x2e64a0 <FT_Outline_Reverse+0x4e> */
/* @0x2e64b2 adds r5, #0x1 */
/* @0x2e64b4 adds r6, r7, #0x1 */
/* @0x2e64b6 uxth r5, r5 */
/* @0x2e64b8 b 0x2e645e <FT_Outline_Reverse+0xc> */
/* @0x2e64ba ldr r2, [r3, #0x10] */
/* @0x2e64bc eor r2, r2, #0x4 */
/* @0x2e64be tstvs r10, r4, lsl #4 */
/* @0x2e64c0 str r2, [r3, #0x10] */
/* @0x2e64c2 pop.w {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e64c6 · anon_2e64c6 · size=0 · insn=1 */
/* @0x2e64c6 ldrblt r0, [r7, #0x0]! */

/* ── FUNC 0x2e64c8 · FT_Outline_Render · size=84 · insn=39 */
/* @0x2e64c8 push {r0, r1, r2, r4, r5, r6, r7, lr} */
/* @0x2e64ca mov r6, r2 */
/* @0x2e64cc mov r5, r0 */
/* @0x2e64ce cbz r0, 0x2e6506 <FT_Outline_Render+0x3e> */
/* @0x2e64d0 cbz r1, 0x2e650a <FT_Outline_Render+0x42> */
/* @0x2e64d2 cbz r2, 0x2e650e <FT_Outline_Render+0x46> */
/* @0x2e64d4 ldr.w r3, [r5, #0x94] */
/* @0x2e64d8 add r7, sp, #0x8 */
/* @0x2e64da movs r4, #0x13 */
/* @0x2e64dc ldr.w r0, [r0, #0x9c] */
/* @0x2e64e0 str r1, [r2, #0x4] */
/* @0x2e64e2 str r3, [r7, #-4]! */
/* @0x2e64e4 lsllt r3, r4, #26 */
/* @0x2e64e6 cbz r0, 0x2e6512 <FT_Outline_Render+0x4a> */
/* @0x2e64e8 ldr r3, [r0, #0x38] */
/* @0x2e64ea mov r1, r6 */
/* @0x2e64ec ldr r0, [r0, #0x34] */
/* @0x2e64ee blx r3 */
/* @0x2e64f0 mov r4, r0 */
/* @0x2e64f2 cbz r0, 0x2e6512 <FT_Outline_Render+0x4a> */
/* @0x2e64f4 uxtb r3, r0 */
/* @0x2e64f6 cmp r3, #0x13 */
/* @0x2e64f8 bne 0x2e6512 <FT_Outline_Render+0x4a> */
/* @0x2e64fa mov r0, r5 */
/* @0x2e64fc ldr r1, [pc, #0x18] */
/* @0x2e64fe mov r2, r7 */
/* @0x2e6500 bl 0x2e5e36 <FT_Lookup_Renderer> */
/* @0x2e6504 b 0x2e64e6 <FT_Outline_Render+0x1e> */
/* @0x2e6506 movs r0, #0x21 */
/* @0x2e6508 b 0x2e6514 <FT_Outline_Render+0x4c> */
/* @0x2e650a movs r0, #0x14 */
/* @0x2e650c b 0x2e6514 <FT_Outline_Render+0x4c> */
/* @0x2e650e movs r0, #0x6 */
/* @0x2e6510 b 0x2e6514 <FT_Outline_Render+0x4c> */
/* @0x2e6512 mov r0, r4 */
/* @0x2e6514 add sp, #0xc */
/* @0x2e6516 pop {r4, r5, r6, r7, pc} */
/* @0x2e6518 strb r4, [r5, #0x11] */
/* @0x2e651a ldr r5, [r6, #0x74] */

/* ── FUNC 0x2e651c · FT_Outline_Get_Bitmap · size=44 · insn=21 */
/* @0x2e651c push {lr} */
/* @0x2e651e sub sp, #0x34 */
/* @0x2e6520 cbz r2, 0x2e6540 <FT_Outline_Get_Bitmap+0x24> */
/* @0x2e6522 movs r3, #0x0 */
/* @0x2e6524 str r3, [sp, #0x8] */
/* @0x2e6526 ldrb r3, [r2, #0x12] */
/* @0x2e6528 str r2, [sp] */
/* @0x2e652a cmp r3, #0x2 */
/* @0x2e652c beq 0x2e6534 <FT_Outline_Get_Bitmap+0x18> */
/* @0x2e652e subs r3, #0x5 */
/* @0x2e6530 cmp r3, #0x1 */
/* @0x2e6532 bhi 0x2e6538 <FT_Outline_Get_Bitmap+0x1c> */
/* @0x2e6534 movs r3, #0x1 */
/* @0x2e6536 str r3, [sp, #0x8] */
/* @0x2e6538 mov r2, sp */
/* @0x2e653a bl 0x2e64c8 <FT_Outline_Render> */
/* @0x2e653c and pc, r0, r5, asr #31 */
/* @0x2e653e b 0x2e6542 <FT_Outline_Get_Bitmap+0x26> */
/* @0x2e6540 movs r0, #0x6 */
/* @0x2e6542 add sp, #0x34 */
/* @0x2e6544 ldr pc, [sp], #4 */

/* ── FUNC 0x2e6548 · FT_Vector_Transform · size=56 · insn=26 */
/* @0x2e6548 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e654a mov r5, r1 */
/* @0x2e654c mov r4, r0 */
/* @0x2e654e cbz r0, 0x2e657e <FT_Vector_Transform+0x36> */
/* @0x2e6550 cbz r1, 0x2e657e <FT_Vector_Transform+0x36> */
/* @0x2e6552 ldr r1, [r1] */
/* @0x2e6554 ldr r0, [r0] */
/* @0x2e6556 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6558 stmdavs r9!, {r0, r3, r4, r5, r6, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e655a ldr r1, [r5, #0x4] */
/* @0x2e655c mov r6, r0 */
/* @0x2e655e ldr r0, [r4, #0x4] */
/* @0x2e6560 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6564 ldr r1, [r5, #0x8] */
/* @0x2e6566 add r6, r0 */
/* @0x2e6568 ldr r0, [r4] */
/* @0x2e656a bl 0x2e4e4c <FT_MulFix> */
/* @0x2e656c stmvs r9!, {r0, r1, r2, r3, r5, r6, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e656e ldr r1, [r5, #0xc] */
/* @0x2e6570 mov r7, r0 */
/* @0x2e6572 ldr r0, [r4, #0x4] */
/* @0x2e6574 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6578 str r6, [r4] */
/* @0x2e657a add r0, r7 */
/* @0x2e657c str r0, [r4, #0x4] */
/* @0x2e657e pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e6580 · FT_Outline_Transform · size=36 · insn=17 */
/* @0x2e6580 push {r4, r5, r6, lr} */
/* @0x2e6582 mov r5, r1 */
/* @0x2e6584 cbz r0, 0x2e65a2 <FT_Outline_Transform+0x22> */
/* @0x2e6586 cbz r1, 0x2e65a2 <FT_Outline_Transform+0x22> */
/* @0x2e6588 ldrsh.w r6, [r0, #0x2] */
/* @0x2e658c ldr r4, [r0, #0x4] */
/* @0x2e658e add.w r6, r4, r6, lsl #3 */
/* @0x2e6590 adcsmi r0, r4, #207618048 */
/* @0x2e6592 cmp r4, r6 */
/* @0x2e6594 bhs 0x2e65a2 <FT_Outline_Transform+0x22> */
/* @0x2e6596 mov r0, r4 */
/* @0x2e6598 mov r1, r5 */
/* @0x2e659a bl 0x2e6548 <FT_Vector_Transform> */
/* @0x2e659c strlo pc, [r8], #-4053 */
/* @0x2e659e adds r4, #0x8 */
/* @0x2e65a0 b 0x2e6592 <FT_Outline_Transform+0x12> */
/* @0x2e65a2 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e65a4 · FT_Outline_Get_Orientation · size=204 · insn=90 */
/* @0x2e65a4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e65a8 mov r4, r0 */
/* @0x2e65aa sub sp, #0x1c */
/* @0x2e65ac cbnz r0, 0x2e65b2 <FT_Outline_Get_Orientation+0xe> */
/* @0x2e65ae movs r0, #0x0 */
/* @0x2e65b0 b 0x2e666a <FT_Outline_Get_Orientation+0xc6> */
/* @0x2e65b2 ldrsh.w r3, [r0, #0x2] */
/* @0x2e65b4 blhs 0x2f25c4 <ps_hints_apply+0x11c4> */
/* @0x2e65b6 cmp r3, #0x0 */
/* @0x2e65b8 ble 0x2e65ae <FT_Outline_Get_Orientation+0xa> */
/* @0x2e65ba add r1, sp, #0x8 */
/* @0x2e65bc bl 0x2e63cc <FT_Outline_Get_CBox> */
/* @0x2e65c0 ldr r0, [sp, #0x8] */
/* @0x2e65c2 ldr r1, [sp, #0x10] */
/* @0x2e65c4 cmp r0, r1 */
/* @0x2e65c6 beq 0x2e6664 <FT_Outline_Get_Orientation+0xc0> */
/* @0x2e65c8 ldr r3, [sp, #0xc] */
/* @0x2e65ca ldr r2, [sp, #0x14] */
/* @0x2e65cc cmp r3, r2 */
/* @0x2e65ce beq 0x2e6664 <FT_Outline_Get_Orientation+0xc0> */
/* @0x2e65d0 eor.w r12, r0, r0, asr #31 */
/* @0x2e65d4 sub.w r12, r12, r0, asr #31 */
/* @0x2e65d8 cmp r1, #0x0 */
/* @0x2e65da it lt */
/* @0x2e65dc rsblt r1, r1, #0 */
/* @0x2e65de rsb r8, r3, r2 */
/* @0x2e65e0 b 0x15e85f0 <b2_toiTime+0xe8f14c> */
/* @0x2e65e2 orr.w r12, r12, r1 */
/* @0x2e65e4 blx 0xff1e95f0 <b2_toiTime+0xfffffffffea9014c> */
/* @0x2e65e6 clz r12, r12 */
/* @0x2e65e8 blx 0xff125820 <b2_toiTime+0xfffffffffe9cc37c> */
/* @0x2e65ea clz r8, r8 */
/* @0x2e65ec .word 0xf1ccf888 */
/* @0x2e65ee rsb.w r12, r12, #0x11 */
/* @0x2e65f0 .word 0xf1c80c11 */
/* @0x2e65f2 rsb.w r8, r8, #0x11 */
/* @0x2e65f4 rfeib r4! */
/* @0x2e65f6 ldrsh.w r0, [r4] */
/* @0x2e65f8 movwhs r0, #0x0 */
/* @0x2e65fa movs r3, #0x0 */
/* @0x2e65fc ldr r6, [r4, #0x4] */
/* @0x2e65fe bic.w r12, r12, r12, asr #31 */
/* @0x2e6600 b 0xd059b8 <b2_toiTime+0x5ac514> */
/* @0x2e6602 bic.w r8, r8, r8, asr #31 */
/* @0x2e6604 ldrmi r7, [r10], -r8, ror #17 */
/* @0x2e6606 mov r2, r3 */
/* @0x2e6608 mov r1, r3 */
/* @0x2e660a str r0, [sp, #0x4] */
/* @0x2e660c ldr r0, [sp, #0x4] */
/* @0x2e660e cmp r1, r0 */
/* @0x2e6610 bge 0x2e665e <FT_Outline_Get_Orientation+0xba> */
/* @0x2e6612 ldr r0, [r4, #0xc] */
/* @0x2e6614 ldrsh.w r0, [r0, r1, lsl #1] */
/* @0x2e6618 ldr.w r5, [r6, r0, lsl #3] */
/* @0x2e661c add.w r7, r6, r0, lsl #3 */
/* @0x2e6620 asr.w r10, r5, r12 */
/* @0x2e6624 ldr r5, [r7, #0x4] */
/* @0x2e6626 asr.w r9, r5, r8 */
/* @0x2e6628 bl 0x4a4a50 <SrcVerts+0x1a94> */
/* @0x2e662a add.w r5, r6, r2, lsl #3 */
/* @0x2e662c addmi r0, r2, #813694976 */
/* @0x2e662e cmp r2, r0 */
/* @0x2e6630 add.w r5, r5, #0x8 */
/* @0x2e6634 bgt 0x2e6658 <FT_Outline_Get_Orientation+0xb4> */
/* @0x2e6636 ldr r7, [r5, #-8] */
/* @0x2e6638 andlo r7, r1, #8, #24 */
/* @0x2e663a adds r2, #0x1 */
/* @0x2e663c asr.w r11, r7, r12 */
/* @0x2e6640 ldr r7, [r5, #-4] */
/* @0x2e6644 add r10, r11 */
/* @0x2e6646 asr.w r7, r7, r8 */
/* @0x2e6648 bl 0xff564270 <b2_toiTime+0xfffffffffee0adcc> */
/* @0x2e664a rsb r9, r9, r7 */
/* @0x2e664c blx 0x568a72 <g_SWFlineaavertbuff+0x159aa> */
/* @0x2e664e mla r3, r10, r9, r3 */
/* @0x2e6650 ldrtmi r3, [r9], r9, lsl #6 */
/* @0x2e6652 mov r9, r7 */
/* @0x2e6654 mov r10, r11 */
/* @0x2e6656 b 0x2e662e <FT_Outline_Get_Orientation+0x8a> */
/* @0x2e6658 adds r2, r0, #0x1 */
/* @0x2e665a adds r1, #0x1 */
/* @0x2e665c b 0x2e660c <FT_Outline_Get_Orientation+0x68> */
/* @0x2e665e cmp r3, #0x0 */
/* @0x2e6660 bgt 0x2e6668 <FT_Outline_Get_Orientation+0xc4> */
/* @0x2e6662 bne 0x2e65ae <FT_Outline_Get_Orientation+0xa> */
/* @0x2e6664 movs r0, #0x2 */
/* @0x2e6666 b 0x2e666a <FT_Outline_Get_Orientation+0xc6> */
/* @0x2e6668 movs r0, #0x1 */
/* @0x2e666a add sp, #0x1c */
/* @0x2e666c pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2e6670 · FT_Outline_EmboldenXY · size=512 · insn=241 */
/* @0x2e6670 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e6674 sub sp, #0x44 */
/* @0x2e6676 str r0, [sp, #0x4] */
/* @0x2e6678 cmp r0, #0x0 */
/* @0x2e667a beq.w 0x2e6862 <FT_Outline_EmboldenXY+0x1f2> */
/* @0x2e667c bl 0x346a4c */
/* @0x2e667e add.w r1, r1, r1, lsr #31 */
/* @0x2e6680 bl 0x382dcc <_ZTS13C_UTF16String+0x19e78> */
/* @0x2e6682 add.w r2, r2, r2, lsr #31 */
/* @0x2e6684 ldrdne r7, r8, [r9], #-34 */
/* @0x2e6686 asrs r1, r1, #0x1 */
/* @0x2e6688 asr.w r2, r2, #0x1 */
/* @0x2e668c str r1, [sp, #0x24] */
/* @0x2e668e str r2, [sp, #0x18] */
/* @0x2e6690 bne 0x2e6698 <FT_Outline_EmboldenXY+0x28> */
/* @0x2e6692 cbnz r2, 0x2e6698 <FT_Outline_EmboldenXY+0x28> */
/* @0x2e6694 movs r0, #0x0 */
/* @0x2e6696 b 0x2e6864 <FT_Outline_EmboldenXY+0x1f4> */
/* @0x2e6698 ldr r0, [sp, #0x4] */
/* @0x2e669a bl 0x2e65a4 <FT_Outline_Get_Orientation> */
/* @0x2e669c blls 0x3664b0 <_ZTS12CDS_Priority+0x8508> */
/* @0x2e669e ldr r3, [sp, #0x4] */
/* @0x2e66a0 cmp r0, #0x2 */
/* @0x2e66a2 str r0, [sp, #0x28] */
/* @0x2e66a4 bne 0x2e66b4 <FT_Outline_EmboldenXY+0x44> */
/* @0x2e66a6 ldrsh.w r0, [r3] */
/* @0x2e66a8 .word 0x28000000 */
/* @0x2e66aa cmp r0, #0x0 */
/* @0x2e66ac ite ne */
/* @0x2e66ae movne r0, #0x6 */
/* @0x2e66b0 moveq r0, #0x0 */
/* @0x2e66b2 b 0x2e6864 <FT_Outline_EmboldenXY+0x1f4> */
/* @0x2e66b4 ldr r6, [r3, #0x4] */
/* @0x2e66b6 movs r3, #0x0 */
/* @0x2e66b8 str r3, [sp, #0x8] */
/* @0x2e66ba str r3, [sp, #0xc] */
/* @0x2e66bc add r3, sp, #0x38 */
/* @0x2e66be str r3, [sp, #0x34] */
/* @0x2e66c0 ldr r2, [sp, #0x4] */
/* @0x2e66c2 ldrsh.w r3, [r2] */
/* @0x2e66c4 bls 0x3b26cc <error_g0017+0xb370> */
/* @0x2e66c6 ldr r2, [sp, #0xc] */
/* @0x2e66c8 cmp r2, r3 */
/* @0x2e66ca bge 0x2e6694 <FT_Outline_EmboldenXY+0x24> */
/* @0x2e66cc ldr r2, [sp, #0x4] */
/* @0x2e66ce mov.w r9, #0x0 */
/* @0x2e66d0 stcls p9, c0, [r2, #-0] */
/* @0x2e66d2 ldr r5, [sp, #0x8] */
/* @0x2e66d4 mov r7, r9 */
/* @0x2e66d6 mov r11, r9 */
/* @0x2e66d8 mov r8, r9 */
/* @0x2e66da ldr r3, [r2, #0xc] */
/* @0x2e66dc ldr r2, [sp, #0xc] */
/* @0x2e66de str.w r9, [sp, #0x30] */
/* @0x2e66e0 .word 0xf8cd9030 */
/* @0x2e66e2 str.w r9, [sp, #0x2c] */
/* @0x2e66e4 rfedb r3! */
/* @0x2e66e6 ldrsh.w r3, [r3, r2, lsl #1] */
/* @0x2e66e8 movwls r3, #0x7012 */
/* @0x2e66ea str r3, [sp, #0x1c] */
/* @0x2e66ec mov r4, r3 */
/* @0x2e66ee mov.w r3, #0xffffffff */
/* @0x2e66f0 movwls r3, #0x53ff */
/* @0x2e66f2 str r3, [sp, #0x14] */
/* @0x2e66f4 cmp r5, r4 */
/* @0x2e66f6 beq.w 0x2e6854 <FT_Outline_EmboldenXY+0x1e4> */
/* @0x2e66f8 blls 0x4469b4 <g_RomDisk+0x4f194> */
/* @0x2e66fa ldr r3, [sp, #0x14] */
/* @0x2e66fc cmp r4, r3 */
/* @0x2e66fe beq.w 0x2e6854 <FT_Outline_EmboldenXY+0x1e4> */
/* @0x2e6700 blls 0x4469ac <g_RomDisk+0x4f18c> */
/* @0x2e6702 ldr r3, [sp, #0x14] */
/* @0x2e6704 cmp r5, r3 */
/* @0x2e6706 beq 0x2e6734 <FT_Outline_EmboldenXY+0xc4> */
/* @0x2e6708 ldr.w r2, [r6, r5, lsl #3] */
/* @0x2e670c add.w r0, r6, r5, lsl #3 */
/* @0x2e6710 ldr.w r3, [r6, r4, lsl #3] */
/* @0x2e6714 add.w r1, r6, r4, lsl #3 */
/* @0x2e6718 subs r3, r2, r3 */
/* @0x2e671a ldr r2, [r0, #0x4] */
/* @0x2e671c str r3, [sp, #0x38] */
/* @0x2e671e add r0, sp, #0x38 */
/* @0x2e6720 ldr r3, [r1, #0x4] */
/* @0x2e6722 subs r3, r2, r3 */
/* @0x2e6724 str r3, [sp, #0x3c] */
/* @0x2e6726 bl 0x2e5096 <FT_Vector_NormLen> */
/* @0x2e6728 strhls pc, [r4], -r6 */
/* @0x2e672a str r0, [sp, #0x10] */
/* @0x2e672c cmp r0, #0x0 */
/* @0x2e672e beq.w 0x2e6848 <FT_Outline_EmboldenXY+0x1d8> */
/* @0x2e6730 and r8, r5, r11, lsl #1 */
/* @0x2e6732 b 0x2e6740 <FT_Outline_EmboldenXY+0xd0> */
/* @0x2e6734 ldr r3, [sp, #0x30] */
/* @0x2e6736 str.w r9, [sp, #0x3c] */
/* @0x2e6738 movwls r9, #0xe03c */
/* @0x2e673a str r3, [sp, #0x38] */
/* @0x2e673c ldr r3, [sp, #0x2c] */
/* @0x2e673e str r3, [sp, #0x10] */
/* @0x2e6740 cmp.w r8, #0x0 */
/* @0x2e6744 beq 0x2e683c <FT_Outline_EmboldenXY+0x1cc> */
/* @0x2e6746 ldr r3, [sp, #0x14] */
/* @0x2e6748 cmp r3, #0x0 */
/* @0x2e674a bge 0x2e6758 <FT_Outline_EmboldenXY+0xe8> */
/* @0x2e674c mov r9, r7 */
/* @0x2e674e str.w r11, [sp, #0x30] */
/* @0x2e6750 strls r11, [r5], #-48 */
/* @0x2e6752 str r4, [sp, #0x14] */
/* @0x2e6754 str.w r8, [sp, #0x2c] */
/* @0x2e6758 ldr r1, [sp, #0x38] */
/* @0x2e675a mov r0, r11 */
/* @0x2e675c bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6760 ldr r1, [sp, #0x3c] */
/* @0x2e6762 mov r10, r0 */
/* @0x2e6764 mov r0, r7 */
/* @0x2e6766 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6768 bmi 0x1325534 <b2_toiTime+0xbcc090> */
/* @0x2e676a ldr r2, [pc, #0x100] */
/* @0x2e676c add r0, r10 */
/* @0x2e676e cmp r0, r2 */
/* @0x2e6770 blt 0x2e6800 <FT_Outline_EmboldenXY+0x190> */
/* @0x2e6772 add.w r10, r0, #0x10000 */
/* @0x2e6774 stmdals lr, {r7, r9, r11, r12, sp} */
/* @0x2e6776 ldr r0, [sp, #0x38] */
/* @0x2e6778 ldr r3, [sp, #0x3c] */
/* @0x2e677a add.w r2, r11, r0 */
/* @0x2e677c andls r0, r8, #0, #4 */
/* @0x2e677e str r2, [sp, #0x20] */
/* @0x2e6780 ldr r2, [sp, #0x28] */
/* @0x2e6782 add r3, r7 */
/* @0x2e6784 cbnz r2, 0x2e678a <FT_Outline_EmboldenXY+0x11a> */
/* @0x2e6786 rsbs r3, r3, #0 */
/* @0x2e6788 b 0x2e6790 <FT_Outline_EmboldenXY+0x120> */
/* @0x2e678a ldr r2, [sp, #0x20] */
/* @0x2e678c rsbs r2, r2, #0 */
/* @0x2e678e str r2, [sp, #0x20] */
/* @0x2e6790 mov r1, r7 */
/* @0x2e6792 str r3, [sp] */
/* @0x2e6794 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e6798 mov r1, r11 */
/* @0x2e679a mov r7, r0 */
/* @0x2e679c ldr r0, [sp, #0x3c] */
/* @0x2e679e bl 0x2e4e4c <FT_MulFix> */
/* @0x2e67a0 bls 0x5a54fc <g_SWFlineaavertbuff+0x52434> */
/* @0x2e67a2 ldr r2, [sp, #0x28] */
/* @0x2e67a4 ldr r3, [sp] */
/* @0x2e67a6 subs r7, r7, r0 */
/* @0x2e67a8 cbnz r2, 0x2e67ac <FT_Outline_EmboldenXY+0x13c> */
/* @0x2e67aa rsbs r7, r7, #0 */
/* @0x2e67ac ldr r2, [sp, #0x10] */
/* @0x2e67ae mov r1, r7 */
/* @0x2e67b0 ldr r0, [sp, #0x24] */
/* @0x2e67b2 cmp r2, r8 */
/* @0x2e67b4 it lt */
/* @0x2e67b6 movlt r8, r2 */
/* @0x2e67b8 str r3, [sp] */
/* @0x2e67ba bl 0x2e4e4c <FT_MulFix> */
/* @0x2e67bc ldrbmi pc, [r1], -r7, asr #22 */
/* @0x2e67be mov r1, r10 */
/* @0x2e67c0 mov r11, r0 */
/* @0x2e67c2 mov r0, r8 */
/* @0x2e67c4 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e67c8 ldr r3, [sp] */
/* @0x2e67ca cmp r11, r0 */
/* @0x2e67cc mov r0, r3 */
/* @0x2e67ce itete le */
/* @0x2e67d0 ldrle r1, [sp, #0x24] */
/* @0x2e67d2 movgt r1, r8 */
/* @0x2e67d4 movle r2, r10 */
/* @0x2e67d6 movgt r2, r7 */
/* @0x2e67d8 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e67dc mov r1, r7 */
/* @0x2e67de mov r11, r0 */
/* @0x2e67e0 ldr r0, [sp, #0x18] */
/* @0x2e67e2 bl 0x2e4e4c <FT_MulFix> */
/* @0x2e67e4 uasxmi pc, r1, r3 */
/* @0x2e67e6 mov r1, r10 */
/* @0x2e67e8 mov r3, r0 */
/* @0x2e67ea mov r0, r8 */
/* @0x2e67ec str r3, [sp] */
/* @0x2e67ee bl 0x2e4e4c <FT_MulFix> */
/* @0x2e67f0 blls 0x3254ac */
/* @0x2e67f2 ldr r3, [sp] */
/* @0x2e67f4 cmp r3, r0 */
/* @0x2e67f6 ldr r0, [sp, #0x20] */
/* @0x2e67f8 bgt 0x2e680e <FT_Outline_EmboldenXY+0x19e> */
/* @0x2e67fa ldr r1, [sp, #0x18] */
/* @0x2e67fc mov r2, r10 */
/* @0x2e67fe b 0x2e6812 <FT_Outline_EmboldenXY+0x1a2> */
/* @0x2e6800 movs r0, #0x0 */
/* @0x2e6802 mov r11, r0 */
/* @0x2e6804 ldr r3, [sp, #0x24] */
/* @0x2e6806 add r11, r3 */
/* @0x2e6808 ldr r3, [sp, #0x18] */
/* @0x2e680a add r0, r3 */
/* @0x2e680c b 0x2e6818 <FT_Outline_EmboldenXY+0x1a8> */
/* @0x2e680e mov r1, r8 */
/* @0x2e6810 mov r2, r7 */
/* @0x2e6812 bl 0x2e4d3c <FT_MulDiv> */
/* @0x2e6814 .word 0xe7f5fa93 */
/* @0x2e6816 b 0x2e6804 <FT_Outline_EmboldenXY+0x194> */
/* @0x2e6818 add.w r3, r6, r4, lsl #3 */
/* @0x2e681c ldr.w r2, [r6, r4, lsl #3] */
/* @0x2e6820 add r2, r11 */
/* @0x2e6822 str.w r2, [r6, r4, lsl #3] */
/* @0x2e6824 ldmdavs r10, {r2, r4, r5, sp} ^ */
/* @0x2e6826 ldr r2, [r3, #0x4] */
/* @0x2e6828 add r2, r0 */
/* @0x2e682a str r2, [r3, #0x4] */
/* @0x2e682c ldr r3, [sp, #0x1c] */
/* @0x2e682e cmp r4, r3 */
/* @0x2e6830 ite lt */
/* @0x2e6832 addlt r4, #0x1 */
/* @0x2e6834 ldrge r4, [sp, #0x8] */
/* @0x2e6836 cmp r4, r5 */
/* @0x2e6838 bne 0x2e6818 <FT_Outline_EmboldenXY+0x1a8> */
/* @0x2e683a b 0x2e683e <FT_Outline_EmboldenXY+0x1ce> */
/* @0x2e683c mov r4, r5 */
/* @0x2e683e ldr.w r11, [sp, #0x38] */
/* @0x2e6840 svcls #0xfb038 */
/* @0x2e6842 ldr r7, [sp, #0x3c] */
/* @0x2e6844 ldr.w r8, [sp, #0x10] */
/* @0x2e6848 ldr r3, [sp, #0x1c] */
/* @0x2e684a cmp r5, r3 */
/* @0x2e684c ite lt */
/* @0x2e684e addlt r5, #0x1 */
/* @0x2e6850 ldrge r5, [sp, #0x8] */
/* @0x2e6852 b 0x2e66f4 <FT_Outline_EmboldenXY+0x84> */
/* @0x2e6854 ldr r3, [sp, #0x1c] */
/* @0x2e6856 adds r3, #0x1 */
/* @0x2e6858 str r3, [sp, #0x8] */
/* @0x2e685a ldr r3, [sp, #0xc] */
/* @0x2e685c adds r3, #0x1 */
/* @0x2e685e str r3, [sp, #0xc] */
/* @0x2e6860 b 0x2e66c0 <FT_Outline_EmboldenXY+0x50> */
/* @0x2e6862 movs r0, #0x14 */
/* @0x2e6864 add sp, #0x44 */
/* @0x2e6866 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e6868 svclt #0x8ff0 */
/* @0x2e686a nop */
/* @0x2e686c asrs r1, r0, #0x20 */
/* @0x2e686e .word 0xffff 460a */

/* ── FUNC 0x2e6870 · FT_Outline_Embolden · size=6 · insn=3 */
/* @0x2e6870 mov r2, r1 */
/* @0x2e6872 b.w 0x2e6670 <FT_Outline_EmboldenXY> */
/* @0x2e6874 ldrshlt r11, [r8, -sp]! */

/* ── FUNC 0x2e6876 · FT_Get_Sfnt_Name_Count · size=20 · insn=9 */
/* @0x2e6876 cbz r0, 0x2e6888 <FT_Get_Sfnt_Name_Count+0x12> */
/* @0x2e6878 ldr r3, [r0, #0x8] */
/* @0x2e687a ands r3, r3, #0x8 */
/* @0x2e687e beq 0x2e6886 <FT_Get_Sfnt_Name_Count+0x10> */
/* @0x2e6880 ldrh.w r0, [r0, #0x154] */
/* @0x2e6882 .word 0x47700154 */
/* @0x2e6884 bx lr */
/* @0x2e6886 mov r0, r3 */
/* @0x2e6888 bx lr */

/* ── FUNC 0x2e688a · FT_Stream_OpenMemory · size=16 · insn=8 */
/* @0x2e688a movs r3, #0x0 */
/* @0x2e688c stm.w r0, {r1, r2} */
/* @0x2e688e addvs r0, r3, r6 */
/* @0x2e6890 str r3, [r0, #0x8] */
/* @0x2e6892 str r3, [r0, #0x20] */
/* @0x2e6894 str r3, [r0, #0x14] */
/* @0x2e6896 str r3, [r0, #0x18] */
/* @0x2e6898 bx lr */

/* ── FUNC 0x2e689a · FT_Stream_Close · size=12 · insn=6 */
/* @0x2e689a push {r3, lr} */
/* @0x2e689c cbz r0, 0x2e68a4 <FT_Stream_Close+0xa> */
/* @0x2e689e ldr r3, [r0, #0x18] */
/* @0x2e68a0 cbz r3, 0x2e68a4 <FT_Stream_Close+0xa> */
/* @0x2e68a2 blx r3 */
/* @0x2e68a4 pop {r3, pc} */

/* ── FUNC 0x2e68a6 · FT_Stream_Seek · size=36 · insn=18 */
/* @0x2e68a6 push {r4, r5, r6, lr} */
/* @0x2e68a8 mov r4, r0 */
/* @0x2e68aa ldr r6, [r0, #0x14] */
/* @0x2e68ac mov r5, r1 */
/* @0x2e68ae cbz r6, 0x2e68ba <FT_Stream_Seek+0x14> */
/* @0x2e68b0 movs r2, #0x0 */
/* @0x2e68b2 mov r3, r2 */
/* @0x2e68b4 blx r6 */
/* @0x2e68b6 cbnz r0, 0x2e68c6 <FT_Stream_Seek+0x20> */
/* @0x2e68b8 b 0x2e68c0 <FT_Stream_Seek+0x1a> */
/* @0x2e68ba ldr r3, [r0, #0x4] */
/* @0x2e68bc cmp r1, r3 */
/* @0x2e68be bhi 0x2e68c6 <FT_Stream_Seek+0x20> */
/* @0x2e68c0 str r5, [r4, #0x8] */
/* @0x2e68c2 movs r0, #0x0 */
/* @0x2e68c4 pop {r4, r5, r6, pc} */
/* @0x2e68c6 movs r0, #0x55 */
/* @0x2e68c8 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2e68ca · anon_2e68ca · size=0 · insn=1 */
/* @0x2e68ca .word 0xe92d0000 */

/* ── FUNC 0x2e68cc · FT_Raccess_Guess · size=100 · insn=48 */
/* @0x2e68cc push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2e68d0 movs r4, #0x0 */
/* @0x2e68d2 ldr.w r11, [pc, #0x58] */
/* @0x2e68d4 addlt r11, r5, r8, asr r0 */
/* @0x2e68d6 sub sp, #0x14 */
/* @0x2e68d8 mov r8, r0 */
/* @0x2e68da mov r7, r1 */
/* @0x2e68dc add r11, pc */
/* @0x2e68de mov r9, r2 */
/* @0x2e68e0 mov r6, r3 */
/* @0x2e68e2 mov r10, r4 */
/* @0x2e68e4 mov r3, r6 */
/* @0x2e68e6 str r10, [r6], #4 */
/* @0x2e68e8 .word 0xb147ab04 */
/* @0x2e68ea cbz r7, 0x2e68fe <FT_Raccess_Guess+0x32> */
/* @0x2e68ec mov r0, r7 */
/* @0x2e68ee movs r1, #0x0 */
/* @0x2e68f0 str r3, [sp, #0xc] */
/* @0x2e68f2 bl 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e68f4 stcls p15, c15, [pc, #-864] */
/* @0x2e68f6 ldr r5, [sp, #0x3c] */
/* @0x2e68f8 str r0, [r5, r4] */
/* @0x2e68fa ldr r3, [sp, #0xc] */
/* @0x2e68fc b 0x2e6902 <FT_Raccess_Guess+0x36> */
/* @0x2e68fe ldr r5, [sp, #0x3c] */
/* @0x2e6900 str r7, [r5, r4] */
/* @0x2e6902 ldr r5, [sp, #0x3c] */
/* @0x2e6904 ldr r2, [r5, r4] */
/* @0x2e6906 cbnz r2, 0x2e691e <FT_Raccess_Guess+0x52> */
/* @0x2e6908 ldr r2, [sp, #0x38] */
/* @0x2e690a mov r0, r8 */
/* @0x2e690c ldr.w r5, [r11, r4, lsl #1] */
/* @0x2e6910 mov r1, r7 */
/* @0x2e6912 add r2, r4 */
/* @0x2e6914 str r2, [sp] */
/* @0x2e6916 mov r2, r9 */
/* @0x2e6918 blx r5 */
/* @0x2e691a ldr r5, [sp, #0x3c] */
/* @0x2e691c str r0, [r5, r4] */
/* @0x2e691e adds r4, #0x4 */
/* @0x2e6920 cmp r4, #0x24 */
/* @0x2e6922 bne 0x2e68e4 <FT_Raccess_Guess+0x18> */
/* @0x2e6924 add sp, #0x14 */
/* @0x2e6926 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2e6928 svclt #0x8ff0 */
/* @0x2e692a nop */
/* @0x2e692c movs r0, #0x88 */
/* @0x2e692e movs r0, r2 */

/* ── FUNC 0x2e6930 · FT_Stream_Skip · size=16 · insn=7 */
/* @0x2e6930 cmp r1, #0x0 */
/* @0x2e6932 blt 0x2e693c <FT_Stream_Skip+0xc> */
/* @0x2e6934 ldr r3, [r0, #0x8] */
/* @0x2e6936 add r1, r3 */
/* @0x2e6938 b.w 0x2e68a6 <FT_Stream_Seek> */
/* @0x2e693c movs r0, #0x55 */
/* @0x2e693e bx lr */

/* ── FUNC 0x2e6940 · FT_Stream_Pos · size=4 · insn=2 */
/* @0x2e6940 ldr r0, [r0, #0x8] */
/* @0x2e6942 bx lr */

/* ── FUNC 0x2e6944 · FT_Stream_ReadAt · size=74 · insn=32 */
/* @0x2e6944 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2e6948 mov r4, r0 */
/* @0x2e694a ldr r6, [r0, #0x4] */
/* @0x2e694c mov r5, r1 */
/* @0x2e694e mov r7, r3 */
/* @0x2e6950 cmp r1, r6 */
/* @0x2e6952 bhs 0x2e6988 <FT_Stream_ReadAt+0x44> */
/* @0x2e6954 ldr.w r12, [r0, #0x14] */
/* @0x2e6958 cmp.w r12, #0x0 */
/* @0x2e695c beq 0x2e6964 <FT_Stream_ReadAt+0x20> */
/* @0x2e695e blx r12 */
/* @0x2e6960 mov r6, r0 */
/* @0x2e6962 b 0x2e6978 <FT_Stream_ReadAt+0x34> */
/* @0x2e6964 subs r6, r6, r1 */
/* @0x2e6966 ldr r1, [r0] */
/* @0x2e6968 cmp r6, r3 */
/* @0x2e696a it hs */
/* @0x2e696c movhs r6, r3 */
/* @0x2e696e mov r0, r2 */
/* @0x2e6970 add r1, r5 */
/* @0x2e6972 mov r2, r6 */
/* @0x2e6974 blx 0xb65bc <memcpy@plt> */
/* @0x2e6978 add r5, r6 */
/* @0x2e697a cmp r6, r7 */
/* @0x2e697c ite lo */
/* @0x2e697e movlo r0, #0x55 */
/* @0x2e6980 movhs r0, #0x0 */
/* @0x2e6982 str r5, [r4, #0x8] */
/* @0x2e6984 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e6988 movs r0, #0x55 */
/* @0x2e698a pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2e698c ldrlt r8, [r0, #-0x1f0] */

/* ── FUNC 0x2e698e · FT_Stream_Read · size=18 · insn=9 */
/* @0x2e698e push {r4, lr} */
/* @0x2e6990 mov r4, r1 */
/* @0x2e6992 mov r3, r2 */
/* @0x2e6994 ldr r1, [r0, #0x8] */
/* @0x2e6996 mov r2, r4 */
/* @0x2e6998 pop.w {r4, lr} */
/* @0x2e699a .word 0xf7ff4010 */
/* @0x2e699c b.w 0x2e6944 <FT_Stream_ReadAt> */
/* @0x2e699e ldrblt r11, [r8, #0xfd2]! */

/* ── FUNC 0x2e69a0 · FT_Stream_TryRead · size=62 · insn=30 */
/* @0x2e69a0 push {r3, r4, r5, r6, r7, lr} */
/* @0x2e69a2 mov r7, r1 */
/* @0x2e69a4 ldr r5, [r0, #0x4] */
/* @0x2e69a6 mov r4, r0 */
/* @0x2e69a8 ldr r1, [r0, #0x8] */
/* @0x2e69aa mov r3, r2 */
/* @0x2e69ac cmp r1, r5 */
/* @0x2e69ae bhs 0x2e69d8 <FT_Stream_TryRead+0x38> */
/* @0x2e69b0 ldr r6, [r0, #0x14] */
/* @0x2e69b2 cbz r6, 0x2e69bc <FT_Stream_TryRead+0x1c> */
/* @0x2e69b4 mov r2, r7 */
/* @0x2e69b6 blx r6 */
/* @0x2e69b8 mov r5, r0 */
/* @0x2e69ba b 0x2e69d0 <FT_Stream_TryRead+0x30> */
/* @0x2e69bc subs r5, r5, r1 */
/* @0x2e69be ldr r3, [r0] */
/* @0x2e69c0 cmp r2, r5 */
/* @0x2e69c2 it lo */
/* @0x2e69c4 movlo r5, r2 */
/* @0x2e69c6 mov r0, r7 */
/* @0x2e69c8 add r1, r3 */
/* @0x2e69ca mov r2, r5 */
/* @0x2e69cc blx 0xb65bc <memcpy@plt> */
/* @0x2e69d0 ldr r3, [r4, #0x8] */
/* @0x2e69d2 add r3, r5 */
/* @0x2e69d4 str r3, [r4, #0x8] */
/* @0x2e69d6 b 0x2e69da <FT_Stream_TryRead+0x3a> */
/* @0x2e69d8 movs r5, #0x0 */
/* @0x2e69da mov r0, r5 */
/* @0x2e69dc pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2e69de · FT_Stream_GetChar · size=20 · insn=10 */
/* @0x2e69de ldr r3, [r0, #0x20] */
/* @0x2e69e0 ldr r2, [r0, #0x24] */
/* @0x2e69e2 cmp r3, r2 */
/* @0x2e69e4 ittte lo */
/* @0x2e69e6 addlo r2, r3, #0x1 */
/* @0x2e69e8 strlo r2, [r0, #0x20] */
/* @0x2e69ea ldrblo r0, [r3] */
/* @0x2e69ec movhs r0, #0x0 */
/* @0x2e69ee sxtb r0, r0 */
/* @0x2e69f0 bx lr */

/* ── FUNC 0x2e69f2 · FT_Stream_GetUShort · size=32 · insn=14 */
/* @0x2e69f2 mov r2, r0 */
/* @0x2e69f4 ldr r3, [r0, #0x20] */
/* @0x2e69f6 ldr r1, [r2, #0x24] */
/* @0x2e69f8 adds r0, r3, #0x1 */
/* @0x2e69fa cmp r1, r0 */
/* @0x2e69fc bls 0x2e6a0c <FT_Stream_GetUShort+0x1a> */
/* @0x2e69fe ldrb r0, [r3] */
/* @0x2e6a00 adds r3, #0x2 */
/* @0x2e6a02 ldrb r1, [r3, #-1] */
/* @0x2e6a06 orr.w r0, r1, r0, lsl #8 */
/* @0x2e6a0a b 0x2e6a0e <FT_Stream_GetUShort+0x1c> */
/* @0x2e6a0c movs r0, #0x0 */
/* @0x2e6a0e str r3, [r2, #0x20] */
/* @0x2e6a10 bx lr */
