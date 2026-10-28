/* libyoyo.so 覆盖卡组 0294
 * 函数 0x317e5c..0x3191d0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x317e5c · anon_317e5c · size=288 · insn=73 */
/* @0x317e5c .word 0x460db5f0 */
/* @0x317e60 smlabbhs r0, r5, r0, r11 */
/* @0x317e64 ldrmi r10, [r6], -r4, lsl #24 */
/* @0x317e68 strmi r4, [r10], -r7, lsl #12 */
/* @0x317e6c strtmi r4, [r8], -r11, lsl #12 */
/* @0x317e70 stcvc p8, c15, [r4, #-272] */
/* @0x317e74 .word 0xf0019400 */
/* @0x317e78 ldmdavs r7!, {r3, r4, r5, r6, r7, r9, r10, r11, sp, lr, pc} */
/* @0x317e7c andhs r2, r1, #0, #2 */
/* @0x317e80 strmi r4, [r11], -r8, lsr #12 */
/* @0x317e84 strls r9, [r3, -r0, lsl #8] */
/* @0x317e88 cdp p0, #0xe, c15, c14, c1, #0x0 */
/* @0x317e8c andhs r2, pc, #0, #2 */
/* @0x317e90 ldmdbvs r6!, {r3, r5, r9, r10, lr} */
/* @0x317e94 strls r4, [r0], #-1547 */
/* @0x317e98 cdp p0, #0xa, c15, c4, c1, #0x0 */
/* @0x317e9c .word 0x21009b03 */
/* @0x317ea0 .word 0xf0034628 */
/* @0x317ea4 andhs r0, pc, #67108864 */
/* @0x317ea8 .word 0x460b431e */
/* @0x317eac strls r9, [r3], -r0, lsl #8 */
/* @0x317eb0 cdp p0, #0xd, c15, c10, c1, #0x0 */
/* @0x317eb4 ldcllt p0, c11, [r0, #20]! */
/* @0x317eb8 .word 0xf002b508 */
/* @0x317ebc stmdahs r0, {r1, r2, r3, r4, r5, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x317ec0 andhs r11, r8, r12, lsl #30 */
/* @0x317ec4 stclt p0, c2, [r8, #-36] */
/* @0x317ec8 .word 0x4604b570 */
/* @0x317ecc .word 0x21004608 */
/* @0x317ed0 ldrmi r11, [r5], -r4, lsl #1 */
/* @0x317ed4 andhs r4, sp, #11534336 */
/* @0x317ed8 strls r10, [r0], -r3, lsl #28 */
/* @0x317edc cdp p0, #0x8, c15, c2, c1, #0x0 */
/* @0x317ee0 stmdavs r10!, {r0, r3, r5, r6, r8, r11, sp, lr} */
/* @0x317ee4 rsbvs r6, r1, #704512 */
/* @0x317ee8 adcvs r9, r2, #49152 */
/* @0x317eec eorvs r6, r1, #-1946157056 */
/* @0x317ef0 ldcllt p0, c11, [r0, #-16]! */
/* @0x317ef4 blvs 0x3f2904 <MAX_TEXTURE_SIZE+0x5c> */
/* @0x317ef8 bvs 0x1444f40 <b2_toiTime+0xceba9c> */
/* @0x317efc andhs r6, r0, #10 */
/* @0x317f00 mrsvs r6, spsr */
/* @0x317f04 .word 0xbc10604a */
/* @0x317f08 svclt #0x4770 */
/* @0x317f0c bllt 0xfe653f14 <b2_toiTime+0xfffffffffdefaa70> */
/* @0x317f10 .word 0x460db5f0 */
/* @0x317f14 ldrmi r11, [r7], -r3, lsl #1 */
/* @0x317f18 .word 0xf7ff4604 */
/* @0x317f1c qsub8mi pc, r8, r7 */
/* @0x317f20 .word 0xf002ae02 */
/* @0x317f24 .word 0x4603edf2 */
/* @0x317f28 .word 0xf8139001 */
/* @0x317f2c .word 0xf8461b01 */
/* @0x317f30 ldrtmi r3, [r0], -r4, lsl #26 */
/* @0x317f34 ldc2l p0, c15, [lr], #-0 */
/* @0x317f38 .word 0xf0024628 */
/* @0x317f3c blls 0x3936bc <ft_adobe_glyph_list+0x2d98> */
/* @0x317f40 .word 0xf8132000 */
/* @0x317f44 bhs 0x2e2b50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x25c> */
/* @0x317f48 andle r9, r4, r1, lsl #6 */
/* @0x317f4c .word 0xf0004630 */
/* @0x317f50 blls 0x397054 <ft_adobe_glyph_list+0x6730> */
/* @0x317f54 ldmdavs r10!, {r3, r4, r11, r12} */
/* @0x317f58 .word 0xf85043d2 */
/* @0x317f5c bl 0x323fec */
/* @0x317f60 teqlt r3, r2, lsl #1 */
/* @0x317f64 strmi r2, [r2], -r0, lsl #6 */
/* @0x317f68 svcne #0x4f852 */
/* @0x317f6c stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x317f70 adcvs sp, r3, #-2147483586 */
/* @0x317f74 .word 0x63602304 */
/* @0x317f78 andlt r6, r3, r3, lsr #6 */
/* @0x317f7c svclt #0xbdf0 */

/* ── FUNC 0x317f80 · __gxx_personality_v0 · size=360 · insn=164 */
/* @0x317f80 and r0, r0, #0x3 */
/* @0x317f84 cmp r0, #0x1 */
/* @0x317f86 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x317f88 .word 0x460c43f0 */
/* @0x317f8a mov r4, r1 */
/* @0x317f8c sub sp, #0x34 */
/* @0x317f8e mov r6, r2 */
/* @0x317f90 ldrd r8, r9, [r1] */
/* @0x317f94 beq 0x318044 <__gxx_personality_v0+0xc4> */
/* @0x317f96 bhs 0x318016 <__gxx_personality_v0+0x96> */
/* @0x317f98 add r7, sp, #0xc */
/* @0x317f9a movs r5, #0x1 */
/* @0x317f9c movs r1, #0x0 */
/* @0x317f9e mov r0, r6 */
/* @0x317fa0 movs r2, #0xc */
/* @0x317fa2 str r4, [sp, #0xc] */
/* @0x317fa4 mov r3, r1 */
/* @0x317fa6 str r7, [sp] */
/* @0x317fa8 blx 0x319c68 <_Unwind_VRS_Set> */
/* @0x317fac cmp r6, #0x0 */
/* @0x317fae beq 0x318040 <__gxx_personality_v0+0xc0> */
/* @0x317fb0 adr r3, #300 <__gxx_personality_v0+0x7f> */
/* @0x317fb2 ldrd r2, r3, [r3] */
/* @0x317fb4 b 0xfe3a0bbc <b2_toiTime+0xfffffffffdc47718> */
/* @0x317fb6 eor.w r2, r2, r8 */
/* @0x317fb8 b 0xfe3d87e0 <b2_toiTime+0xfffffffffdc7f33c> */
/* @0x317fba eor.w r3, r3, r9 */
/* @0x317fbc b 0x1798be8 <b2_toiTime+0x103f744> */
/* @0x317fbe orrs.w r1, r2, r3 */
/* @0x317fc0 svclt #0x140103 */
/* @0x317fc2 ite ne */
/* @0x317fc4 movne r7, #0x0 */
/* @0x317fc6 moveq r7, #0x1 */
/* @0x317fc8 lsls r1, r5, #0x1f */
/* @0x317fca bmi 0x318022 <__gxx_personality_v0+0xa2> */
/* @0x317fcc lsls r2, r5, #0x1e */
/* @0x317fce bpl 0x318040 <__gxx_personality_v0+0xc0> */
/* @0x317fd0 lsls r3, r5, #0x1d */
/* @0x317fd2 bpl 0x318094 <__gxx_personality_v0+0x114> */
/* @0x317fd4 cmp r7, #0x0 */
/* @0x317fd6 beq 0x3180bc <__gxx_personality_v0+0x13c> */
/* @0x317fd8 ldmdb r4, {r0, r1, r2} */
/* @0x317fdc add.w r8, sp, #0x10 */
/* @0x317fe0 ldr r3, [r4, #-20] */
/* @0x317fe4 ldr r5, [r4, #-16] */
/* @0x317fe8 str r0, [sp, #0x1c] */
/* @0x317fea mov r0, r4 */
/* @0x317fec str r1, [sp, #0x20] */
/* @0x317fee mov r1, r8 */
/* @0x317ff0 asrs r7, r3, #0x1f */
/* @0x317ff2 str r3, [sp, #0x10] */
/* @0x317ff4 str r7, [sp, #0x14] */
/* @0x317ff6 str r5, [sp, #0x18] */
/* @0x317ff8 str r2, [sp, #0x24] */
/* @0x317ffa bl 0x317ef4 <ft_lzwstate_io+0xf40> */
/* @0x317ffc qsub16mi pc, r0, r11 */
/* @0x317ffe mov r0, r4 */
/* @0x318000 mov r1, r6 */
/* @0x318002 mov r2, r8 */
/* @0x318004 bl 0x317e5c <ft_lzwstate_io+0xea8> */
/* @0x318008 mov r0, r4 */
/* @0x31800a mov r1, r6 */
/* @0x31800c mov r2, r8 */
/* @0x31800e bl 0x317f10 <ft_lzwstate_io+0xf5c> */
/* @0x318010 andhs pc, r7, pc, ror pc */
/* @0x318012 movs r0, #0x7 */
/* @0x318014 b 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x318016 cmp r0, #0x2 */
/* @0x318018 beq 0x318036 <__gxx_personality_v0+0xb6> */
/* @0x31801a movs r0, #0x9 */
/* @0x31801c add sp, #0x34 */
/* @0x31801e pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x318020 qsub8mi r8, r9, r0 */
/* @0x318022 mov r1, r5 */
/* @0x318024 mov r2, r7 */
/* @0x318026 mov r3, r4 */
/* @0x318028 add r0, sp, #0x10 */
/* @0x31802a str r6, [sp] */
/* @0x31802c bl 0x317ba8 <ft_lzwstate_io+0xbf4> */
/* @0x318030 ldr r5, [sp, #0x28] */
/* @0x318032 cmp r5, #0x6 */
/* @0x318034 beq 0x318062 <__gxx_personality_v0+0xe2> */
/* @0x318036 mov r0, r4 */
/* @0x318038 mov r1, r6 */
/* @0x31803a bl 0x317eb8 <ft_lzwstate_io+0xf04> */
/* @0x31803c .word 0xe7edff3d */
/* @0x31803e b 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x318040 movs r0, #0x3 */
/* @0x318042 b 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x318044 movs r1, #0x0 */
/* @0x318046 mov r0, r2 */
/* @0x318048 movs r2, #0xd */
/* @0x31804a ldr r5, [r4, #0x20] */
/* @0x31804c mov r3, r1 */
/* @0x31804e add r7, sp, #0xc */
/* @0x318050 str r7, [sp] */
/* @0x318052 blx 0x319be4 <_Unwind_VRS_Get> */
/* @0x318054 blls 0x41377c <g_RomDisk+0x1bf5c> */
/* @0x318056 ldr r3, [sp, #0xc] */
/* @0x318058 cmp r5, r3 */
/* @0x31805a ite eq */
/* @0x31805c moveq r5, #0x6 */
/* @0x31805e movne r5, #0x2 */
/* @0x318060 b 0x317f9c <__gxx_personality_v0+0x1c> */
/* @0x318062 mov r0, r5 */
/* @0x318064 cmp r7, #0x0 */
/* @0x318066 beq 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x318068 ldr r3, [sp, #0x10] */
/* @0x31806a mov r0, r4 */
/* @0x31806c mov r1, r6 */
/* @0x31806e add r2, sp, #0x10 */
/* @0x318070 str r3, [r4, #-20] */
/* @0x318074 ldr r3, [sp, #0x18] */
/* @0x318076 str r3, [r4, #-16] */
/* @0x318078 blls 0x4e70c0 <SrcVerts+0x44104> */
/* @0x31807a ldr r3, [sp, #0x1c] */
/* @0x31807c str r3, [r4, #-12] */
/* @0x318080 ldr r3, [sp, #0x20] */
/* @0x318082 str r3, [r4, #-8] */
/* @0x318084 blls 0x5670ac <g_SWFlineaavertbuff+0x13fe4> */
/* @0x318086 ldr r3, [sp, #0x24] */
/* @0x318088 str r3, [r4, #-4] */
/* @0x31808c bl 0x317ec8 <ft_lzwstate_io+0xf14> */
/* @0x318090 mov r0, r5 */
/* @0x318092 b 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x318094 mov r3, r4 */
/* @0x318096 mov r1, r5 */
/* @0x318098 mov r2, r7 */
/* @0x31809a add r0, sp, #0x10 */
/* @0x31809c str r6, [sp] */
/* @0x31809e bl 0x317ba8 <ft_lzwstate_io+0xbf4> */
/* @0x3180a0 blls 0x5d76b4 <g_SWFaavertbuff+0x45ec> */
/* @0x3180a2 ldr r3, [sp, #0x28] */
/* @0x3180a4 cmp r3, #0x6 */
/* @0x3180a6 bne 0x318036 <__gxx_personality_v0+0xb6> */
/* @0x3180a8 mov r1, r6 */
/* @0x3180aa add r2, sp, #0x10 */
/* @0x3180ac mov r0, r4 */
/* @0x3180ae bl 0x317e5c <ft_lzwstate_io+0xea8> */
/* @0x3180b0 .word 0x4620fed5 */
/* @0x3180b2 mov r0, r4 */
/* @0x3180b4 bl 0x317f0c <ft_lzwstate_io+0xf58> */
/* @0x3180b8 movs r0, #0x7 */
/* @0x3180ba b 0x31801c <__gxx_personality_v0+0x9c> */
/* @0x3180bc add.w r8, sp, #0x10 */
/* @0x3180c0 mov r3, r4 */
/* @0x3180c2 mov r1, r5 */
/* @0x3180c4 mov r2, r7 */
/* @0x3180c6 mov r0, r8 */
/* @0x3180c8 str r6, [sp] */
/* @0x3180ca bl 0x317ba8 <ft_lzwstate_io+0xbf4> */
/* @0x3180cc blls 0x5d7688 <g_SWFaavertbuff+0x45c0> */
/* @0x3180ce ldr r3, [sp, #0x28] */
/* @0x3180d0 cmp r3, #0x6 */
/* @0x3180d2 beq 0x317ffe <__gxx_personality_v0+0x7e> */
/* @0x3180d4 mov r0, r4 */
/* @0x3180d6 bl 0x317b38 <ft_lzwstate_io+0xb84> */
/* @0x3180d8 svclt #0xfd2f */
/* @0x3180da nop */
/* @0x3180dc nop.w */
/* @0x3180e0 cmp r3, #0x0 */
/* @0x3180e2 orrs r3, r5 */
/* @0x3180e4 strb r3, [r0, r5] */
/* @0x3180e6 bx r9 */

/* ── FUNC 0x3180e8 · anon_3180e8 · size=1224 · insn=307 */
/* @0x3180e8 ldrlt r4, [r0, #-0xb04] */
/* @0x3180ec .word 0x4604447b */
/* @0x3180f0 andvs r3, r3, r8, lsl #6 */
/* @0x3180f4 stc2l p0, c15, [r8], #0 */
/* @0x3180f8 ldclt p6, c4, [r0, #-128] */
/* @0x3180fc ldrdeq r4, r5, [sp], -r0 */
/* @0x318100 .word 0x4604b510 */
/* @0x318104 .word 0xfff0f7ff */
/* @0x318108 .word 0xf7654620 */
/* @0x31810c strtmi lr, [r0], -r2, ror #16 */
/* @0x318110 svclt #0xbd10 */
/* @0x318114 .word 0xf013b538 */
/* @0x318118 strmi r0, [sp], -r1, lsl #6 */
/* @0x31811c svclt #0x89c04 */
/* @0x318120 .word 0xd1004618 */
/* @0x318124 stmdbmi sp, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x318128 ldrbtmi r6, [r9], #-2240 */
/* @0x31812c .word 0xf0006809 */
/* @0x318130 stmdahs r0, {r0, r1, r3, r4, r8, r11, r12, sp, lr, pc} */
/* @0x318134 stmvs r8!, {r1, r2, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x318138 stmdbmi r9, {r3, r5, r6, r8, r12, sp, pc} */
/* @0x31813c bmi 0x560d44 <g_SWFlineaavertbuff+0xdc7c> */
/* @0x318140 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318144 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318148 ldc2l p7, c15, [r12], #-1020 */
/* @0x31814c movwhs r11, #0x118 */
/* @0x318150 eorvc r2, r3, r1 */
/* @0x318154 andhs r11, r1, r8, lsr sp */
/* @0x318158 ldclt p0, c7, [r8, #-128]! */
/* @0x31815c andeq r9, sp, r6, ror #21 */
/* @0x318160 andeq r9, sp, r4, asr #21 */
/* @0x318164 ldrdeq r9, r10, [sp], -r0 */
/* @0x318168 ldrbmi r2, [r0, -r1]! */
/* @0x31816c ldrlt r4, [r0, #-0xb04] */
/* @0x318170 .word 0x4604447b */
/* @0x318174 andvs r3, r3, r8, lsl #6 */
/* @0x318178 .word 0xf8d2f7ff */
/* @0x31817c ldclt p6, c4, [r0, #-128] */
/* @0x318180 andeq r4, sp, r12, ror #30 */
/* @0x318184 .word 0x4604b510 */
/* @0x318188 .word 0xfff0f7ff */
/* @0x31818c .word 0xf7654620 */
/* @0x318190 strtmi lr, [r0], -r0, lsr #16 */
/* @0x318194 svclt #0xbd10 */
/* @0x318198 .word 0x4607b5f8 */
/* @0x31819c ldrmi r4, [r5], -lr, lsl #12 */
/* @0x3181a0 .word 0xf7ff461c */
/* @0x3181a4 .word 0xb108f8d3 */
/* @0x3181a8 ldcllt p0, c2, [r8, #4]! */
/* @0x3181ac .word 0x462368b8 */
/* @0x3181b0 qasxmi r4, r10, r1 */
/* @0x3181b4 stmdbvs r4!, {r2, r11, sp, lr} */
/* @0x3181b8 ldcllt p7, c4, [r8, #640]! */
/* @0x3181bc .word 0xf64cb508 */
/* @0x3181c0 .word 0xf6cd23b1 */
/* @0x3181c4 andhs r6, r0, #-1275068414 */
/* @0x3181c8 .word 0xf59e701a */
/* @0x3181cc svclt #0xed5e */
/* @0x3181d0 tstlt r0, r8, lsl #10 */
/* @0x3181d4 .word 0xf7ff4780 */
/* @0x3181d8 stmdami r5, {r0, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3181dc .word 0x47804478 */
/* @0x3181e0 .word 0xf7ffe7f9 */
/* @0x3181e4 .word 0xf7fffa9d */
/* @0x3181e8 .word 0xf7fffad7 */
/* @0x3181ec svclt #0xffe7 */
/* @0x3181f0 .word 0xffffffdd */
/* @0x3181f4 andhs r4, r0, #9216 */
/* @0x3181f8 .word 0xf3bf447b */
/* @0x3181fc ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^ */
/* @0x318200 bl 0x31be08 */
/* @0x318204 stmda r3, {r1, r8} ^ */
/* @0x318208 .word 0xf0901000 */
/* @0x31820c mvnsle r0, r0, lsl #30 */
/* @0x318210 andeq lr, r2, r1, lsr #23 */
/* @0x318214 svchi #0x5ff3bf */
/* @0x318218 svclt #0x4770 */
/* @0x31821c andseq r1, r6, r8, lsl #17 */
/* @0x318220 .word 0xb1684602 */
/* @0x318224 ldrbtmi r4, [r11], #-2824 */
/* @0x318228 svceq #0xe853 */
/* @0x31822c .word 0x2100e843 */
/* @0x318230 svceq #0xf091 */
/* @0x318234 .word 0xf3bfd1f8 */
/* @0x318238 .word 0xf3bf8f5f */
/* @0x31823c .word 0x47708f5f */
/* @0x318240 ldrbtmi r4, [r10], #-2562 */
/* @0x318244 svclt #0xe7ee */
/* @0x318248 andseq r1, r6, r10, asr r8 */
/* @0x31824c .word 0xffffff77 */
/* @0x318250 .word 0xf7ffb508 */
/* @0x318254 .word 0xf7ffffcf */
/* @0x318258 svclt #0xffbb */
/* @0x31825c .word 0xf7ffb508 */
/* @0x318260 svclt #0xfff7 */
/* @0x318264 andhs r4, r0, #9216 */
/* @0x318268 .word 0xf3bf447b */
/* @0x31826c ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^ */
/* @0x318270 bl 0x31be78 */
/* @0x318274 stmda r3, {r1, r8} ^ */
/* @0x318278 .word 0xf0901000 */
/* @0x31827c mvnsle r0, r0, lsl #30 */
/* @0x318280 andeq lr, r2, r1, lsr #23 */
/* @0x318284 svchi #0x5ff3bf */
/* @0x318288 svclt #0x4770 */
/* @0x31828c andseq r1, r6, r4, lsl r8 */
/* @0x318290 .word 0xb1684602 */
/* @0x318294 ldrbtmi r4, [r11], #-2824 */
/* @0x318298 svceq #0xe853 */
/* @0x31829c .word 0x2100e843 */
/* @0x3182a0 svceq #0xf091 */
/* @0x3182a4 .word 0xf3bfd1f8 */
/* @0x3182a8 .word 0xf3bf8f5f */
/* @0x3182ac .word 0x47708f5f */
/* @0x3182b0 ldrbtmi r4, [r10], #-2562 */
/* @0x3182b4 svclt #0xe7ee */
/* @0x3182b8 andseq r1, r6, r6, ror #15 */
/* @0x3182bc .word 0xffffff07 */
/* @0x3182c0 .word 0xf7ffb508 */
/* @0x3182c4 smlabtlt r0, pc, pc, pc */
/* @0x3182c8 .word 0xf7ff4780 */
/* @0x3182cc svclt #0xffc1 */
/* @0x3182d0 ldrbtmi r4, [r11], #-2818 */
/* @0x3182d4 andvs r3, r3, r8, lsl #6 */
/* @0x3182d8 svclt #0x4770 */
/* @0x3182dc andeq r4, sp, r2, asr lr */
/* @0x3182e0 ldrbtmi r4, [r8], #-2049 */
/* @0x3182e4 svclt #0x4770 */
/* @0x3182e8 andeq r4, r4, r2, lsr #6 */
/* @0x3182ec ldrbtmi r4, [r8], #-2049 */
/* @0x3182f0 svclt #0x4770 */
/* @0x3182f4 andeq r4, r4, r6, lsr #6 */
/* @0x3182f8 ldrlt r4, [r0, #-0xb04] */
/* @0x3182fc .word 0x4604447b */
/* @0x318300 andvs r3, r3, r8, lsl #6 */
/* @0x318304 svc #0x64f764 */
/* @0x318308 ldclt p6, c4, [r0, #-128] */
/* @0x31830c andeq r4, sp, r8, lsr #28 */
/* @0x318310 ldrlt r4, [r0, #-0xb04] */
/* @0x318314 .word 0x4604447b */
/* @0x318318 andvs r3, r3, r8, lsl #6 */
/* @0x31831c blx 0x1954326 <b2_toiTime+0x11fae82> */
/* @0x318320 ldclt p6, c4, [r0, #-128] */
/* @0x318324 strdeq r4, r5, [sp], -r8 */
/* @0x318328 .word 0x4604b510 */
/* @0x31832c .word 0xfff0f7ff */
/* @0x318330 .word 0xf7644620 */
/* @0x318334 strtmi lr, [r0], -lr, asr #30 */
/* @0x318338 svclt #0xbd10 */
/* @0x31833c ldrlt r4, [r0, #-0xb04] */
/* @0x318340 .word 0x4604447b */
/* @0x318344 andvs r3, r3, r8, lsl #6 */
/* @0x318348 blx 0x13d4352 <b2_toiTime+0xc7aeae> */
/* @0x31834c ldclt p6, c4, [r0, #-128] */
/* @0x318350 andeq r4, sp, r4, lsl #28 */
/* @0x318354 .word 0x4604b510 */
/* @0x318358 .word 0xfff0f7ff */
/* @0x31835c .word 0xf7644620 */
/* @0x318360 qasxmi lr, r0, r8 */
/* @0x318364 svclt #0xbd10 */
/* @0x318368 stmdavs r0, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x31836c .word 0xf59e6849 */
/* @0x318370 .word 0xf1d0e902 */
/* @0x318374 svclt #0x380001 */
/* @0x318378 stclt p0, c2, [r8, #-0] */
/* @0x31837c .word 0xf7ffb508 */
/* @0x318380 .word 0xf080fff3 */
/* @0x318384 sbclt r0, r0, #1 */
/* @0x318388 svclt #0xbd08 */
/* @0x31838c stmdavs r0, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x318390 .word 0xf59e6849 */
/* @0x318394 svceq #0xc0e8f0 */
/* @0x318398 svclt #0xbd08 */
/* @0x31839c .word 0x4604b510 */
/* @0x3183a0 blx 0x15d43aa <b2_toiTime+0xe7af06> */
/* @0x3183a4 strtmi r4, [r0], -r2, lsl #22 */
/* @0x3183a8 movwlo r4, #0x847b */
/* @0x3183ac ldclt p0, c6, [r0, #-140] */
/* @0x3183b0 muleq sp, r12, sp */
/* @0x3183b4 .word 0x4604b510 */
/* @0x3183b8 blx 0x12d43c2 <b2_toiTime+0xb7af1e> */
/* @0x3183bc strtmi r4, [r0], -r2, lsl #22 */
/* @0x3183c0 movwlo r4, #0x847b */
/* @0x3183c4 ldclt p0, c6, [r0, #-140] */
/* @0x3183c8 andeq r4, sp, r12, asr #26 */
/* @0x3183cc ldrbmi r2, [r0, -r2]! */
/* @0x3183d0 ldrlt r4, [r0, #-0xb04] */
/* @0x3183d4 .word 0x4604447b */
/* @0x3183d8 andvs r3, r3, r8, lsl #6 */
/* @0x3183dc .word 0xffa0f7fe */
/* @0x3183e0 ldclt p6, c4, [r0, #-128] */
/* @0x3183e4 andeq r4, sp, r0, lsr #27 */
/* @0x3183e8 .word 0x4604b510 */
/* @0x3183ec .word 0xfff0f7ff */
/* @0x3183f0 .word 0xf7644620 */
/* @0x3183f4 strtmi lr, [r0], -lr, ror #29 */
/* @0x3183f8 svclt #0xbd10 */
/* @0x3183fc svcmi #0xf0e92d */
/* @0x318400 strmi r11, [r5], -sp, lsl #1 */
/* @0x318404 swpls r4, r3, [r1] */
/* @0x318408 .word 0xf7fe461e */
/* @0x31840c stmdahs r0, {r0, r1, r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318410 addshi pc, r0, r0, asr #32 */
/* @0x318414 movwls r6, #0x28eb */
/* @0x318418 rsbsle r2, r1, r0, lsl #22 */
/* @0x31841c ssatmi r4, #0x9, r8, asr #22 */
/* @0x318420 strtmi r4, [pc], -r4, lsl #12 */
/* @0x318424 blmi 0x18fd038 <b2_toiTime+0x11a3b94> */
/* @0x318428 blmi 0x18fd040 <b2_toiTime+0x11a3b9c> */
/* @0x31842c blls 0x3fd048 <g_RomDisk+0x5828> */
/* @0x318430 movwls r4, #0x347b */
/* @0x318434 ldrbtmi r9, [r11], #-2820 */
/* @0x318438 blls 0x47d050 <targetStr+0x1e10> */
/* @0x31843c movwls r4, #0x547b */
/* @0x318440 ldrtmi r10, [r9], -r7, lsl #16 */
/* @0x318444 .word 0xff94f7fe */
/* @0x318448 sbceq lr, r4, #7168 */
/* @0x31844c .word 0x3000f8db */
/* @0x318450 .word 0xf8d86952 */
/* @0x318454 movwls r0, #0x6010 */
/* @0x318458 beq 0x394468 <ft_adobe_glyph_list+0x3b44> */
/* @0x31845c stmdbeq r0, {r1, r6, r7, r8, r9, r12, sp, lr, pc} ^ */
/* @0x318460 andsne r11, r2, #-1073741810 */
/* @0x318464 svceq #0xf1ba */
/* @0x318468 ldmdavs r9, {r0, r12, lr, pc} */
/* @0x31846c ldmne r11, {r1, r3, r7, r11, r12, lr} */
/* @0x318470 .word 0xf1b99306 */
/* @0x318474 .word 0xd1020f00 */
/* @0x318478 .word 0x07da68f3 */
/* @0x31847c stmdavs r5, {r1, r3, r4, r5, r8, r10, r12, lr, pc} */
/* @0x318480 stmdbls r1, {r1, r2, r9, r11, sp, pc} */
/* @0x318484 pushvs {r0, r1, r2, r8, r9, r11, sp, pc} */
/* @0x318488 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr} */
/* @0x31848c .word 0xf1b9d032 */
/* @0x318490 .word 0xd1010f00 */
/* @0x318494 movwls r2, #0x7302 */
/* @0x318498 svceq #0xf1ba */
/* @0x31849c ldmdavs r1!, {r0, r2, r4, r5, r8, r12, lr, pc} ^ */
/* @0x3184a0 andsle r2, r12, r0, lsl #18 */
/* @0x3184a4 stmdahs r0, {r3, r11, r12, pc} */
/* @0x3184a8 .word 0xf7ffd050 */
/* @0x3184ac stmiblt r0, {r0, r1, r2, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3184b0 blhs 0x332784 */
/* @0x3184b4 ldmdavs r0!, {r0, r2, r3, r5, r12, lr, pc} ^ */
/* @0x3184b8 .word 0xf7ff9908 */
/* @0x3184bc stmdahs r0, {r0, r2, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3184c0 ldmvs r3!, {r1, r3, r4, r5, r12, lr, pc} */
/* @0x3184c4 suble r2, sp, r0, lsl #22 */
/* @0x3184c8 bhs 0x33ecf4 */
/* @0x3184cc addsmi sp, r3, #74 */
/* @0x3184d0 andhs sp, r1, r0, lsl r0 */
/* @0x3184d4 eorsvs r2, r3, r2, lsl #6 */
/* @0x3184d8 pop {r0, r2, r3, r12, sp, pc} */
/* @0x3184dc blls 0x53c4a4 <obj_has_event+0x1934> */
/* @0x3184e0 eorsle r2, r3, r0, lsl #22 */
/* @0x3184e4 shadd16mi r2, r0, r1 */
/* @0x3184e8 .word 0xf59ea907 */
/* @0x3184ec ldmdavs r0!, {r3, r5, r6, r11, sp, lr, pc} */
/* @0x3184f0 suble r2, r0, r1, lsl #16 */
/* @0x3184f4 strlo r9, [r1], #-2818 */
/* @0x3184f8 stmdaeq r8, {r3, r8, r12, sp, lr, pc} */
/* @0x3184fc orrsle r4, pc, r3, lsr #5 */
/* @0x318500 andlo r6, r0, r0, lsr r8 */
/* @0x318504 andhs r11, r1, r8, lsl pc */
/* @0x318508 movwhs lr, #0x7e6 */
/* @0x31850c eorlo pc, r12, sp, lsl #17 */
/* @0x318510 blls 0x59242c <g_SWFlineaavertbuff+0x3f364> */
/* @0x318514 bicle r2, lr, r0, lsl #22 */
/* @0x318518 blhs 0x3375ec */
/* @0x31851c .word 0xf89dd1d9 */
/* @0x318520 blhs 0x3245d8 */
/* @0x318524 ldmdavs r0!, {r0, r2, r4, r6, r7, r8, r12, lr, pc} ^ */
/* @0x318528 .word 0xf7ff9908 */
/* @0x31852c stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318530 strb sp, [lr, r1, asr #1] */
/* @0x318534 strb r2, [pc, r1] */
/* @0x318538 orrhs r4, r10, r4, lsl r8 */
/* @0x31853c blmi 0x86ad94 <b2_toiTime+0x1118f0> */
/* @0x318540 ldrbtmi r4, [r10], #-1144 */
/* @0x318544 .word 0xf59e447b */
/* @0x318548 .word 0xe7baed32 */
/* @0x31854c .word 0x216f4812 */
/* @0x318550 blmi 0x7eada0 <b2_toiTime+0x918fc> */
/* @0x318554 ldrbtmi r4, [r10], #-1144 */
/* @0x318558 .word 0xf59e447b */
/* @0x31855c stmdals r8, {r3, r5, r8, r10, r11, sp, lr, pc} */
/* @0x318560 .word 0xe7a26871 */
/* @0x318564 orrhs r9, pc, r4, lsl #20 */
/* @0x318568 stmdals r3, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x31856c ldc p5, c15, [lr, #-632] */
/* @0x318570 bls 0x572844 <g_SWFlineaavertbuff+0x1f77c> */
/* @0x318574 ldmvs r11!, {r0, r1, r3, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x318578 ldrtle r0, [r11], #2011 */
/* @0x31857c svclt #0xe7ac */
/* @0x318580 strdeq r4, r5, [r4], -r4 */
/* @0x318584 andeq sp, r8, lr, ror #2 */
/* @0x318588 andeq r4, r4, r8, lsr #5 */
/* @0x31858c andeq r4, r4, r4, ror #1 */
/* @0x318590 andeq sp, r8, r2, rrx */
/* @0x318594 andeq r4, r4, r4, ror r1 */
/* @0x318598 ldrdeq r4, r5, [r4], -r0 */
/* @0x31859c andeq sp, r8, lr, asr #32 */
/* @0x3185a0 andeq r4, r4, r4, lsr #2 */
/* @0x3185a4 .word 0xf000b41e */
/* @0x3185a8 .word 0xbc1ef867 */
/* @0x3185ac ldmda r8!, {r1, r12, sp, lr, pc} */
/* @0x3185b0 bl 0x1dd5c30 <b2_toiTime+0x167c78c> */

/* ── FUNC 0x3185b4 · __cxa_type_match · size=116 · insn=53 */
/* @0x3185b4 push {r4, r5, r6, r7, lr} */
/* @0x3185b6 sub sp, #0xc */
/* @0x3185b8 ldr r4, [r0, #-52] */
/* @0x3185bc add.w r2, r0, #0x58 */
/* @0x3185c0 mov r5, r0 */
/* @0x3185c2 mov r6, r1 */
/* @0x3185c4 mov r7, r3 */
/* @0x3185c6 str r2, [sp, #0x4] */
/* @0x3185c8 cmp r4, #0x0 */
/* @0x3185ca beq 0x318616 <__cxa_type_match+0x62> */
/* @0x3185cc ldr r1, [pc, #0x50] */
/* @0x3185ce mov r0, r4 */
/* @0x3185d0 ldr r2, [pc, #0x50] */
/* @0x3185d2 movs r3, #0x0 */
/* @0x3185d4 add r1, pc */
/* @0x3185d6 ldr r1, [r1] */
/* @0x3185d8 add r2, pc */
/* @0x3185da ldr r2, [r2] */
/* @0x3185dc bl 0x317a44 <ft_lzwstate_io+0xa90> */
/* @0x3185e0 cbz r0, 0x318616 <__cxa_type_match+0x62> */
/* @0x3185e2 ldr r3, [r5, #0x58] */
/* @0x3185e4 movs r5, #0x2 */
/* @0x3185e6 str r3, [sp, #0x4] */
/* @0x3185e8 rsbs.w r3, r4, #0x1 */
/* @0x3185ec it lo */
/* @0x3185ee movlo r3, #0x0 */
/* @0x3185f0 cmp r6, #0x0 */
/* @0x3185f2 it eq */
/* @0x3185f4 orreq r3, r3, #0x1 */
/* @0x3185f8 cbz r3, 0x318602 <__cxa_type_match+0x4e> */
/* @0x3185fa movs r5, #0x0 */
/* @0x3185fc mov r0, r5 */
/* @0x3185fe add sp, #0xc */
/* @0x318600 pop {r4, r5, r6, r7, pc} */
/* @0x318602 ldr r3, [r6] */
/* @0x318604 mov r0, r6 */
/* @0x318606 mov r1, r4 */
/* @0x318608 add r2, sp, #0x4 */
/* @0x31860a ldr r3, [r3, #0x8] */
/* @0x31860c blx r3 */
/* @0x31860e cbz r0, 0x31861a <__cxa_type_match+0x66> */
/* @0x318610 ldr r3, [sp, #0x4] */
/* @0x318612 str r3, [r7] */
/* @0x318614 b 0x3185fc <__cxa_type_match+0x48> */
/* @0x318616 movs r5, #0x1 */
/* @0x318618 b 0x3185e8 <__cxa_type_match+0x34> */
/* @0x31861a mov r5, r0 */
/* @0x31861c b 0x3185fc <__cxa_type_match+0x48> */
/* @0x31861e nop */
/* @0x318620 str r6, [sp, #0x110] */
/* @0x318622 movs r5, r1 */
/* @0x318624 str r6, [sp, #0xd0] */
/* @0x318626 movs r5, r1 */

/* ── FUNC 0x318628 · __cxa_begin_cleanup · size=80 · insn=34 */
/* @0x318628 push {r4, r5, r6, lr} */
/* @0x31862a mov r6, r0 */
/* @0x31862c bl 0x3174e0 <ft_lzwstate_io+0x52c> */
/* @0x318630 ldrd r4, r5, [r6] */
/* @0x318634 sub.w r1, r6, #0x38 */
/* @0x318638 adr r3, #52 <__cxa_begin_cleanup+0x21> */
/* @0x31863a ldrd r2, r3, [r3] */
/* @0x31863c rsbmi r2, r2, r0, lsl #6 */
/* @0x31863e eors r2, r4 */
/* @0x318640 eors r3, r5 */
/* @0x318642 orrs.w r4, r2, r3 */
/* @0x318644 svclt #0x180403 */
/* @0x318646 it ne */
/* @0x318648 strne r1, [r0, #0x8] */
/* @0x31864a beq 0x318650 <__cxa_begin_cleanup+0x28> */
/* @0x31864c movs r0, #0x1 */
/* @0x31864e pop {r4, r5, r6, pc} */
/* @0x318650 ldr r3, [r6, #-24] */
/* @0x318654 adds r3, #0x1 */
/* @0x318656 str r3, [r6, #-24] */
/* @0x318658 blhs 0x3676c0 <_ZTS12CDS_Priority+0x9718> */
/* @0x31865a cmp r3, #0x1 */
/* @0x31865c ittt eq */
/* @0x31865e ldreq r3, [r0, #0x8] */
/* @0x318660 streq r3, [r6, #-28] */
/* @0x318664 streq r1, [r0, #0x8] */
/* @0x318666 movs r0, #0x1 */
/* @0x318668 pop {r4, r5, r6, pc} */
/* @0x31866a nop */
/* @0x31866c nop.w */
/* @0x318670 cmp r3, #0x0 */
/* @0x318672 orrs r3, r5 */
/* @0x318674 strb r3, [r0, r5] */
/* @0x318676 bx r9 */

/* ── FUNC 0x318678 · anon_318678 · size=76 · insn=20 */
/* @0x318678 .word 0xf7feb538 */
/* @0x31867c stmvs r1, {r0, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318680 ldmib r1, {r0, r3, r6, r7, r8, r12, sp, pc} ^ */
/* @0x318684 movwge r4, #0xe50e */
/* @0x318688 movwhs lr, #0x9d3 */
/* @0x31868c rsbmi r4, r11, r2, rrx */
/* @0x318690 streq lr, [r3], #-2642 */
/* @0x318694 movwhs sp, #0x4 */
/* @0x318698 .word 0xf1016083 */
/* @0x31869c ldclt p0, c0, [r8, #-224]! */
/* @0x3186a0 bllo 0x372ed4 <_ZTS13C_UTF16String+0x9f80> */
/* @0x3186a4 blhs 0x330ed8 */
/* @0x3186a8 stmibvs r10, {r0, r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} ^ */
/* @0x3186ac .word 0xf1016082 */
/* @0x3186b0 bicvs r0, r11, r8, lsr r0 */
/* @0x3186b4 .word 0xf7ffbd38 */
/* @0x3186b8 svclt #0xfdcb */
/* @0x3186bc andhi pc, r0, pc, lsr #7 */
/* @0x3186c0 .word 0x432b2b00 */
/* @0x3186c4 strbmi r5, [lr, -r3, asr #10] */

/* ── FUNC 0x3186c8 · __cxa_call_unexpected · size=260 · insn=106 */
/* @0x3186c8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x3186cc mov r4, r0 */
/* @0x3186ce adr r3, #232 <__cxa_call_unexpected+0x44> */
/* @0x3186d0 ldrd r2, r3, [r3] */
/* @0x3186d4 sub sp, #0xc */
/* @0x3186d6 ldrd r0, r1, [r0] */
/* @0x3186d8 cdpmi p1, #0x3, c0, c9, c0, #0x0 */
/* @0x3186da ldr r6, [pc, #0xe4] */
/* @0x3186dc eors r2, r0 */
/* @0x3186de eors r3, r1 */
/* @0x3186e0 orrs.w r1, r2, r3 */
/* @0x3186e4 add r6, pc */
/* @0x3186e6 mov r0, r4 */
/* @0x3186e8 beq 0x3186f2 <__cxa_call_unexpected+0x2a> */
/* @0x3186ea bl 0x317720 <ft_lzwstate_io+0x76c> */
/* @0x3186ec .word 0xf7fff819 */
/* @0x3186ee bl 0x3182c0 <__gxx_personality_v0+0x340> */
/* @0x3186f0 .word 0xf8d4fde7 */
/* @0x3186f2 ldr.w r8, [r4, #0x28] */
/* @0x3186f4 blvs 0xc7879c <b2_toiTime+0x51f2f8> */
/* @0x3186f6 ldr r5, [r4, #0x30] */
/* @0x3186f8 ldr r7, [r4, #0x34] */
/* @0x3186fa bl 0x317720 <ft_lzwstate_io+0x76c> */
/* @0x3186fc .word 0xf854f811 */
/* @0x3186fe ldr r3, [r4, #-44] */
/* @0x318700 ldrmi r3, [r8, r12, lsr #24] */
/* @0x318702 blx r3 */
/* @0x318704 bl 0x318250 <__gxx_personality_v0+0x2d0> */
/* @0x318708 bl 0x317720 <ft_lzwstate_io+0x76c> */
/* @0x31870c bl 0x318250 <__gxx_personality_v0+0x2d0> */
/* @0x318710 bl 0x317720 <ft_lzwstate_io+0x76c> */
/* @0x318714 mov.w r9, #0x0 */
/* @0x318718 bic r11, r5, #0x3 */
/* @0x31871c mov r10, r9 */
/* @0x31871e cmp r9, r8 */
/* @0x318720 beq 0x318778 <__cxa_call_unexpected+0xb0> */
/* @0x318722 mov r0, r7 */
/* @0x318724 bl 0x317b44 <ft_lzwstate_io+0xb90> */
/* @0x318728 mov r5, r0 */
/* @0x31872a bl 0x3174e0 <ft_lzwstate_io+0x52c> */
/* @0x31872c .word 0x4629fed9 */
/* @0x31872e mov r1, r5 */
/* @0x318730 movs r2, #0x0 */
/* @0x318732 ldr r3, [r0] */
/* @0x318734 add.w r0, r3, #0x38 */
/* @0x318738 adds r3, #0x90 */
/* @0x31873a str r3, [sp] */
/* @0x31873c mov r3, sp */
/* @0x31873e bl 0x3185b4 <__cxa_type_match> */
/* @0x318740 ldmiblt r8, {r0, r3, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318742 cbnz r0, 0x31876c <__cxa_call_unexpected+0xa4> */
/* @0x318744 ldr r2, [pc, #0x7c] */
/* @0x318746 ldr r3, [r5] */
/* @0x318748 str r0, [sp, #0x4] */
/* @0x31874a mov r0, r5 */
/* @0x31874c ldr r1, [r6, r2] */
/* @0x31874e add r2, sp, #0x4 */
/* @0x318750 ldr r3, [r3, #0x8] */
/* @0x318752 blx r3 */
/* @0x318754 add.w r9, r9, #0x1 */
/* @0x318758 cmp r0, #0x0 */
/* @0x31875a it ne */
/* @0x31875c movne.w r10, #0x1 */
/* @0x318760 add r7, r11 */
/* @0x318762 b 0x31871e <__cxa_call_unexpected+0x56> */
/* @0x318764 bl 0x317798 <ft_lzwstate_io+0x7e4> */
/* @0x318768 bl 0x3185a4 <__cxa_end_cleanup> */
/* @0x31876c bl 0x3176d8 <ft_lzwstate_io+0x724> */
/* @0x318770 bl 0x317798 <ft_lzwstate_io+0x7e4> */
/* @0x318774 bl 0x3185a4 <__cxa_end_cleanup> */
/* @0x318778 cmp.w r10, #0x0 */
/* @0x31877c beq 0x3187a0 <__cxa_call_unexpected+0xd8> */
/* @0x31877e bl 0x317798 <ft_lzwstate_io+0x7e4> */
/* @0x318780 .word 0xf7fff80b */
/* @0x318782 bl 0x317798 <ft_lzwstate_io+0x7e4> */
/* @0x318784 andhs pc, r4, r9, lsl #16 */
/* @0x318786 movs r0, #0x4 */
/* @0x318788 bl 0x317624 <ft_lzwstate_io+0x670> */
/* @0x31878c mov r4, r0 */
/* @0x31878e bl 0x318a48 <__cxa_call_unexpected+0x380> */
/* @0x318790 blmi 0x656d04 <g_SWFlinevertbuff+0x3c3c> */
/* @0x318792 ldr r3, [pc, #0x30] */
/* @0x318794 mov r0, r4 */
/* @0x318796 ldr r1, [r6, r3] */
/* @0x318798 ldr r3, [pc, #0x2c] */
/* @0x31879a ldr r2, [r6, r3] */
/* @0x31879c bl 0x3176a0 <ft_lzwstate_io+0x6ec> */
/* @0x3187a0 ldr r3, [r4, #-40] */
/* @0x3187a4 blx r3 */
/* @0x3187a6 blx 0xb6c88 <abort@plt> */
/* @0x3187a8 .word 0xf7feea70 */
/* @0x3187aa bl 0x317720 <ft_lzwstate_io+0x76c> */
/* @0x3187ac .word 0xf59effb9 */
/* @0x3187ae blx 0xb6c88 <abort@plt> */
/* @0x3187b0 .word 0xf7feea6c */
/* @0x3187b2 bl 0x317798 <ft_lzwstate_io+0x7e4> */
/* @0x3187b4 .word 0xe7dbfff1 */
/* @0x3187b6 b 0x318770 <__cxa_call_unexpected+0xa8> */
/* @0x3187b8 cmp r3, #0x0 */
/* @0x3187ba orrs r3, r5 */
/* @0x3187bc strb r3, [r0, r5] */
/* @0x3187be bx r9 */
/* @0x3187c0 str r5, [sp, #0x1c0] */
/* @0x3187c2 movs r5, r1 */
/* @0x3187c4 .word 0xffc8 ffff */
/* @0x3187c8 .word 0xffcc ffff */

/* ── FUNC 0x3187cc · anon_3187cc · size=1144 · insn=287 */
/* @0x3187cc andhi pc, r0, pc, lsr #7 */
/* @0x3187d0 movwhs r11, #0x430 */
/* @0x3187d4 ldrmi r6, [r9], -r4, lsl #16 */
/* @0x3187d8 blhs 0x396830 <ft_adobe_glyph_list+0x5f0c> */
/* @0x3187dc ldrbeq pc, [pc, #-0x2]! */
/* @0x3187e0 movwlo r4, #0x709d */
/* @0x3187e4 b 0x135a034 <b2_toiTime+0xc00b90> */
/* @0x3187e8 ldrbtle r0, [r5], #261 */
/* @0x3187ec strmi r6, [r8], -r4 */
/* @0x3187f0 .word 0x4770bc30 */
/* @0x3187f4 movwhs r11, #0x430 */
/* @0x3187f8 ldrmi r6, [r9], -r4, lsl #16 */
/* @0x3187fc blhs 0x396854 <ft_adobe_glyph_list+0x5f30> */
/* @0x318800 ldrbeq pc, [pc, #-0x2]! */
/* @0x318804 movwlo r4, #0x709d */
/* @0x318808 svceq #0x80f012 */
/* @0x31880c .word 0x0105ea41 */
/* @0x318810 blhs 0xb0cfe8 <b2_toiTime+0x3b3b44> */
/* @0x318814 svclt #0x8c6004 */
/* @0x318818 strhs r2, [r1, #-0x500] */
/* @0x31881c ldrne lr, [r2, #0xa15] */
/* @0x318820 .word 0xf04fd004 */
/* @0x318824 blx 0x7a5428 <b2_toiTime+0x4bf84> */
/* @0x318828 tstmi r9, #201326592 */
/* @0x31882c ldclt p6, c4, [r0], #-32 */
/* @0x318830 svclt #0x4770 */
/* @0x318834 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, sp} */
/* @0x318838 .word 0x46064ff0 */
/* @0x31883c strmi r11, [sp], -r9, lsl #1 */
/* @0x318840 sbchi pc, r3, r0 */
/* @0x318844 .word 0xf0016804 */
/* @0x318848 strls r0, [r7], #-783 */
/* @0x31884c ldmdale r10, {r2, r3, r8, r9, r11, sp} */
/* @0x318850 .word 0xf003e8df */
/* @0x318854 ldrbeq r6, [sp, -r7, lsl #30]! */
/* @0x318858 ldmdbne r9, {r0, r2, r3, r5, r8, r11, r12} */
/* @0x31885c .word 0x07676319 */
/* @0x318860 stmvc r0!, {r0, r2, r7} */
/* @0x318864 stmdavc r1!, {r1, r5, r8, r10, r11, r12} ^ */
/* @0x318868 .word 0xf8947823 */
/* @0x31886c streq r10, [r0], #-3 */
/* @0x318870 andhs lr, r1, r0, asr #20 */
/* @0x318874 tstmi r8, #1879048192 */
/* @0x318878 andvs lr, r10, r0, asr #20 */
/* @0x31887c cmneq r0, #21 */
/* @0x318880 blhs 0x74c8b4 <g_SWFvertbuff+0x797ec> */
/* @0x318884 .word 0xf59ed001 */
/* @0x318888 stmdblt r0!, {r9, r11, sp, lr, pc} */
/* @0x31888c eorsvs r9, r3, r7, lsl #22 */
/* @0x318890 pop {r0, r3, r12, sp, pc} */
/* @0x318894 ldmdavs r3!, {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x318898 stmibeq sp!, {r3, r4, r11, r12} ^ */
/* @0x31889c svclt #0xc2800 */
/* @0x3188a0 .word 0xf0052500 */
/* @0x3188a4 stchs p5, c0, [r0, #-4] */
/* @0x3188a8 stmdavs r0, {r4, r5, r6, r7, r12, lr, pc} */
/* @0x3188ac stmdbvc r0!, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x3188b0 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^ */
/* @0x3188b4 andls r7, r5, r3, lsr #17 */
/* @0x3188b8 b 0x16f6f40 <b2_toiTime+0xf9da9c> */
/* @0x3188bc .word 0x91022802 */
/* @0x3188c0 mrsls r2, apsr */
/* @0x3188c4 bmi 0x413208 <g_RomDisk+0x1b9e8> */
/* @0x3188c8 b 0x153c8d4 <b2_toiTime+0xde3430> */
/* @0x3188cc ldmib sp, {r1, r3, r9} ^ */
/* @0x3188d0 movwhs r0, #0x102 */
/* @0x3188d4 mulgt r3, r4, r8 */
/* @0x3188d8 b 0x13bd4f0 <b2_toiTime+0xc6404c> */
/* @0x3188dc stmdbvc r7!, {r9, r11} ^ */
/* @0x3188e0 movwhs lr, #0x49dd */
/* @0x3188e4 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3188e8 b 0x15be8f4 <b2_toiTime+0xe65450> */
/* @0x3188ec eorseq r0, pc, #8, #20 */
/* @0x3188f0 andls r9, r2, #786432 */
/* @0x3188f4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3188f8 andeq lr, r2, r10, asr #20 */
/* @0x3188fc movwhs lr, #0x29dd */
/* @0x318900 .word 0xf8942300 */
/* @0x318904 strlo r12, [r8], #-7 */
/* @0x318908 .word 0x46984310 */
/* @0x31890c .word 0x469a4318 */
/* @0x318910 blvs 0x653254 <g_SWFlinevertbuff+0x18c> */
/* @0x318914 strls r4, [r7], #-792 */
/* @0x318918 stmdage r7, {r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31891c .word 0xff6af7ff */
/* @0x318920 stmdavc r0!, {r2, r3, r5, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x318924 bllo 0x3d697c <error_g0017+0x2f620> */
/* @0x318928 andhs lr, r0, r3, asr #20 */
/* @0x31892c andlt r9, r0, #117440512 */
/* @0x318930 movwhs lr, #0x7a4 */
/* @0x318934 .word 0xf8144618 */
/* @0x318938 .word 0xf0022b01 */
/* @0x31893c addsmi r0, r9, pc, ror r1 */
/* @0x318940 ldreq r3, [r2], -r7, lsl #6 */
/* @0x318944 andeq lr, r1, r0, asr #20 */
/* @0x318948 strls sp, [r7], #-1269 */
/* @0x31894c qadd8mi lr, r3, r6 */
/* @0x318950 .word 0xf8137860 */
/* @0x318954 b 0x13a3564 <b2_toiTime+0xc4a0c0> */
/* @0x318958 movwls r2, #0x7000 */
/* @0x31895c stmdbvc r0!, {r1, r2, r3, r7, r8, r9, r10, sp, lr, pc} */
/* @0x318960 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^ */
/* @0x318964 andls r7, r5, r3, lsr #17 */
/* @0x318968 b 0x16f6ff0 <b2_toiTime+0xf9db4c> */
/* @0x31896c .word 0x91022802 */
/* @0x318970 mrsls r2, apsr */
/* @0x318974 bmi 0x4132b8 <g_RomDisk+0x1ba98> */
/* @0x318978 b 0x153c984 <b2_toiTime+0xde34e0> */
/* @0x31897c ldmib sp, {r1, r3, r9} ^ */
/* @0x318980 movwhs r0, #0x102 */
/* @0x318984 mulgt r3, r4, r8 */
/* @0x318988 b 0x13bd5a0 <b2_toiTime+0xc640fc> */
/* @0x31898c stmdbvc r7!, {r9, r11} ^ */
/* @0x318990 movwhs lr, #0x49dd */
/* @0x318994 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x318998 b 0x15be9a4 <b2_toiTime+0xe65500> */
/* @0x31899c eorseq r0, pc, #8, #20 */
/* @0x3189a0 andls r9, r2, #786432 */
/* @0x3189a4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3189a8 andeq lr, r2, r10, asr #20 */
/* @0x3189ac movwhs lr, #0x29dd */
/* @0x3189b0 .word 0xf8942300 */
/* @0x3189b4 strlo r12, [r8], #-7 */
/* @0x3189b8 .word 0x46984310 */
/* @0x3189bc .word 0x469a4318 */
/* @0x3189c0 blvs 0x653304 <g_SWFlinevertbuff+0x23c> */
/* @0x3189c4 strls r4, [r7], #-792 */
/* @0x3189c8 andhs lr, r0, r8, asr r7 */
/* @0x3189cc svclt #0xe760 */
/* @0x3189d0 ldrbtmi r4, [r11], #-2818 */
/* @0x3189d4 andvs r3, r3, r8, lsl #6 */
/* @0x3189d8 svclt #0x4770 */
/* @0x3189dc andeq r4, sp, r2, lsl #16 */
/* @0x3189e0 ldrbtmi r4, [r8], #-2049 */
/* @0x3189e4 svclt #0x4770 */
/* @0x3189e8 andeq r3, r4, r2, lsr sp */
/* @0x3189ec ldrbtmi r4, [r11], #-2818 */
/* @0x3189f0 andvs r3, r3, r8, lsl #6 */
/* @0x3189f4 svclt #0x4770 */
/* @0x3189f8 andeq r4, sp, r6, ror #15 */
/* @0x3189fc ldrbtmi r4, [r8], #-2049 */
/* @0x318a00 svclt #0x4770 */
/* @0x318a04 andeq r3, r4, r6, lsr #26 */
/* @0x318a08 ldrlt r4, [r0, #-0xb04] */
/* @0x318a0c .word 0x4604447b */
/* @0x318a10 andvs r3, r3, r8, lsl #6 */
/* @0x318a14 bl 0xffa567ac <b2_toiTime+0xffffffffff2fd308> */
/* @0x318a18 ldclt p6, c4, [r0, #-128] */
/* @0x318a1c andeq r4, sp, r8, asr #15 */
/* @0x318a20 ldrlt r4, [r0, #-0xb04] */
/* @0x318a24 .word 0x4604447b */
/* @0x318a28 andvs r3, r3, r8, lsl #6 */
/* @0x318a2c bl 0xff7567c4 <b2_toiTime+0xfffffffffeffd320> */
/* @0x318a30 ldclt p6, c4, [r0, #-128] */
/* @0x318a34 strheq r4, [sp], -r0 */
/* @0x318a38 ldrbtmi r4, [r11], #-2818 */
/* @0x318a3c andvs r3, r3, r8, lsl #6 */
/* @0x318a40 svclt #0x4770 */
/* @0x318a44 muleq sp, r10, r7 */
/* @0x318a48 ldrbtmi r4, [r11], #-2818 */
/* @0x318a4c andvs r3, r3, r8, lsl #6 */
/* @0x318a50 svclt #0x4770 */
/* @0x318a54 andeq r4, sp, r2, ror #14 */
/* @0x318a58 .word 0xf7feb508 */
/* @0x318a5c stmdavs r0, {r0, r6, r8, r10, r11, r12, sp, lr, pc} ^ */
/* @0x318a60 svclt #0x183000 */
/* @0x318a64 stclt p0, c2, [r8, #-4] */
/* @0x318a68 ldrbmi r2, [r0, -r0]! */
/* @0x318a6c ldrlt r4, [r0, #-0xb04] */
/* @0x318a70 .word 0x4604447b */
/* @0x318a74 andvs r3, r3, r8, lsl #6 */
/* @0x318a78 stc2 p7, c15, [r12, #-1016] */
/* @0x318a7c ldclt p6, c4, [r0, #-128] */
/* @0x318a80 andeq r4, sp, r12, ror r7 */
/* @0x318a84 .word 0x4604b510 */
/* @0x318a88 .word 0xfff0f7ff */
/* @0x318a8c .word 0xf7644620 */
/* @0x318a90 strtmi lr, [r0], -r0, lsr #23 */
/* @0x318a94 svclt #0xbd10 */
/* @0x318a98 stcllt p7, c15, [r6], #-1020 */
/* @0x318a9c ldrlt r4, [r0, #-0xb04] */
/* @0x318aa0 .word 0x4604447b */
/* @0x318aa4 andvs r3, r3, r8, lsl #6 */
/* @0x318aa8 ldc2l p7, c15, [r4], #1016 */
/* @0x318aac ldclt p6, c4, [r0, #-128] */
/* @0x318ab0 andeq r4, sp, r12, lsl #22 */
/* @0x318ab4 .word 0x4604b510 */
/* @0x318ab8 .word 0xfff0f7ff */
/* @0x318abc .word 0xf7644620 */
/* @0x318ac0 strtmi lr, [r0], -r8, lsl #23 */
/* @0x318ac4 svclt #0xbd10 */
/* @0x318ac8 ldrlt r4, [r0, #-0xb04] */
/* @0x318acc .word 0x4604447b */
/* @0x318ad0 andvs r3, r3, r8, lsl #6 */
/* @0x318ad4 ldc2l p7, c15, [lr], {254} */
/* @0x318ad8 ldclt p6, c4, [r0, #-128] */
/* @0x318adc andeq r4, sp, r8, lsl #22 */
/* @0x318ae0 .word 0x4604b510 */
/* @0x318ae4 .word 0xfff0f7ff */
/* @0x318ae8 .word 0xf7644620 */
/* @0x318aec qsub16mi lr, r0, r2 */
/* @0x318af0 svclt #0xbd10 */
/* @0x318af4 movwhs r11, #0x1538 */
/* @0x318af8 strmi r6, [r12], -r5, lsl #16 */
/* @0x318afc strmi r6, [r8, sp, ror #17]! */
/* @0x318b00 andhs r11, r1, r8, lsl #2 */
/* @0x318b04 stmdbmi r4, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x318b08 ldrbtmi r4, [r9], #-1568 */
/* @0x318b0c pop {r0, r3, r11, sp, lr} */
/* @0x318b10 .word 0xf7ff4038 */
/* @0x318b14 svclt #0xbc29 */
/* @0x318b18 andeq r9, sp, r10, lsl r1 */
/* @0x318b1c mvnsmi lr, sp, lsr #18 */
/* @0x318b20 stmdavs r7, {r2, r7, r12, sp, pc} */
/* @0x318b24 .word 0xf10d4698 */
/* @0x318b28 movwls r0, #0x30f */
/* @0x318b2c strmi r4, [r4], -r3, asr #12 */
/* @0x318b30 .word 0x460e693f */
/* @0x318b34 .word 0x47b84615 */
/* @0x318b38 .word 0xf89d4603 */
/* @0x318b3c stmiblt r3, {r0, r1, r2, r3} */
/* @0x318b40 orrlt r6, r12, r4, ror #17 */
/* @0x318b44 strtmi r4, [r0], -r12, lsl #18 */
/* @0x318b48 ldrbtmi r4, [r9], #-2572 */
/* @0x318b4c ldrbtmi r6, [r10], #-2057 */
/* @0x318b50 .word 0xff78f7fe */
/* @0x318b54 stmdavs r4, {r6, r8, r12, sp, pc} */
/* @0x318b58 ldmvs r1!, {r1, r3, r5, r9, r10, lr} ^ */
/* @0x318b5c stmvs r4!, {r0, r1, r6, r9, r10, lr} ^ */
/* @0x318b60 andlt r4, r4, r0, lsr #15 */
/* @0x318b64 ldrhhi lr, [r0, #141]! */
/* @0x318b68 strtmi r6, [r0], -r3, lsr #16 */
/* @0x318b6c qsub8mi r6, r10, r1 */
/* @0x318b70 .word 0x4798689b */
/* @0x318b74 svclt #0xe7f5 */
/* @0x318b78 strheq r9, [sp], -r10 */
/* @0x318b7c andeq r4, sp, r6, lsr #21 */
/* @0x318b80 mvnsmi lr, sp, lsr #18 */
/* @0x318b84 strmi r4, [r12], -r5, lsl #12 */
/* @0x318b88 .word 0x46984616 */
/* @0x318b8c blx 0xffe56b92 <b2_toiTime+0xffffffffff6fd6ee> */
/* @0x318b90 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x318b94 stmdavs r11!, {r1, r2, r5, r8, r12, lr, pc} */
/* @0x318b98 .word 0x0c04f853 */
/* @0x318b9c eorle r2, r9, r0, lsl #24 */
/* @0x318ba0 .word 0xf8536823 */
/* @0x318ba4 .word 0xf7ff1c04 */
/* @0x318ba8 stmiblt r0, {r0, r3, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x318bac stmvs r7!, {r0, r1, r3, r5, r7, r11, sp, lr} */
/* @0x318bb0 andeq lr, r3, #225280 */
/* @0x318bb4 .word 0xf1b8d114 */
/* @0x318bb8 andsle r0, r6, r1, lsl #30 */
/* @0x318bbc svceq #0x4f018 */
/* @0x318bc0 streq pc, [r1, -r8, lsr #32] */
/* @0x318bc4 bfieq sp, r3, #2, #26 */
/* @0x318bc8 svclt #0x584628 */
/* @0x318bcc streq pc, [r4, -r7, asr #32] */
/* @0x318bd0 ldrtmi r4, [r2], -r1, lsr #12 */
/* @0x318bd4 pop {r0, r1, r3, r4, r5, r9, r10, lr} */
/* @0x318bd8 .word 0xf7ff41f0 */
/* @0x318bdc shadd8mi r11, r8, pc */
/* @0x318be0 ldrhhi lr, [r0, #141]! */
/* @0x318be4 pop {r0, sp} */
/* @0x318be8 .word 0x270381f0 */
/* @0x318bec ldrmi lr, [r0], -r11, ror #15 */
/* @0x318bf0 ldrhhi lr, [r0, #141]! */
/* @0x318bf4 .word 0xf814f000 */
/* @0x318bf8 andhs r11, r4, r0, lsl r5 */
/* @0x318bfc ldc2 p7, c15, [r2, #-1016] */
/* @0x318c00 .word 0xf7ff4604 */
/* @0x318c04 stmdbmi r4, {r0, r1, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x318c08 bmi 0x42a490 <g_RomDisk+0x32c70> */
/* @0x318c0c stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318c10 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318c14 stc2l p7, c15, [r4, #-1016] */
/* @0x318c18 andeq r9, sp, r12, lsl r0 */
/* @0x318c1c andeq r9, sp, r12, lsl r0 */
/* @0x318c20 andhs r11, r4, r0, lsl r5 */
/* @0x318c24 ldc2l p7, c15, [lr], #1016 */
/* @0x318c28 .word 0xf7ff4604 */
/* @0x318c2c stmdbmi r4, {r0, r1, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x318c30 bmi 0x42a4b8 <g_RomDisk+0x32c98> */
/* @0x318c34 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318c38 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318c3c ldc2 p7, c15, [r0, #-1016]! */
/* @0x318c40 strdeq r8, r9, [sp], -r12 */
/* @0x318c44 strdeq r8, r9, [sp], -r12 */

/* ── FUNC 0x318c48 · __udivsi3 · size=168 · insn=42 */
/* @0x318c48 subs r2, r1, #1 */
/* @0x318c4c bxeq lr */
/* @0x318c50 blo 0x318ce4 <__udivsi3+0x9c> */
/* @0x318c54 cmp r0, r1 */
/* @0x318c58 bls 0x318cc8 <__udivsi3+0x80> */
/* @0x318c5c tst r1, r2 */
/* @0x318c60 beq 0x318cd4 <__udivsi3+0x8c> */
/* @0x318c64 clz r3, r1 */
/* @0x318c68 clz r2, r0 */
/* @0x318c6c sub r2, r3, r2 */
/* @0x318c70 mov r3, #1 */
/* @0x318c74 lsl r1, r1, r2 */
/* @0x318c78 lsl r3, r3, r2 */
/* @0x318c7c mov r2, #0 */
/* @0x318c80 cmp r0, r1 */
/* @0x318c84 subhs r0, r0, r1 */
/* @0x318c88 orrhs r2, r2, r3 */
/* @0x318c8c cmp r0, r1, lsr #1 */
/* @0x318c90 subhs r0, r0, r1, lsr #1 */
/* @0x318c94 orrhs r2, r2, r3, lsr #1 */
/* @0x318c98 cmp r0, r1, lsr #2 */
/* @0x318c9c subhs r0, r0, r1, lsr #2 */
/* @0x318ca0 orrhs r2, r2, r3, lsr #2 */
/* @0x318ca4 cmp r0, r1, lsr #3 */
/* @0x318ca8 subhs r0, r0, r1, lsr #3 */
/* @0x318cac orrhs r2, r2, r3, lsr #3 */
/* @0x318cb0 cmp r0, #0 */
/* @0x318cb4 lsrsne r3, r3, #4 */
/* @0x318cb8 lsrne r1, r1, #4 */
/* @0x318cbc bne 0x318c80 <__udivsi3+0x38> */
/* @0x318cc0 mov r0, r2 */
/* @0x318cc4 bx lr */
/* @0x318cc8 moveq r0, #1 */
/* @0x318ccc movne r0, #0 */
/* @0x318cd0 bx lr */
/* @0x318cd4 clz r2, r1 */
/* @0x318cd8 rsb r2, r2, #31 */
/* @0x318cdc lsr r0, r0, r2 */
/* @0x318ce0 bx lr */
/* @0x318ce4 cmp r0, #0 */
/* @0x318ce8 mvnne r0, #0 */
/* @0x318cec b 0x319458 <__aeabi_ldiv0> */

/* ── FUNC 0x318cf0 · __aeabi_uidivmod · size=32 · insn=8 */
/* @0x318cf0 cmp r1, #0 */
/* @0x318cf4 beq 0x318ce4 <__udivsi3+0x9c> */
/* @0x318cf8 push {r0, r1, lr} */
/* @0x318cfc bl 0x318c48 <__udivsi3> */
/* @0x318d00 pop {r1, r2, lr} */
/* @0x318d04 mul r3, r2, r0 */
/* @0x318d08 sub r1, r1, r3 */
/* @0x318d0c bx lr */

/* ── FUNC 0x318d10 · __divsi3 · size=220 · insn=55 */
/* @0x318d10 cmp r1, #0 */
/* @0x318d14 beq 0x318ddc <__divsi3+0xcc> */
/* @0x318d18 eor r12, r0, r1 */
/* @0x318d1c rsbmi r1, r1, #0 */
/* @0x318d20 subs r2, r1, #1 */
/* @0x318d24 beq 0x318da8 <__divsi3+0x98> */
/* @0x318d28 movs r3, r0 */
/* @0x318d2c rsbmi r3, r0, #0 */
/* @0x318d30 cmp r3, r1 */
/* @0x318d34 bls 0x318db4 <__divsi3+0xa4> */
/* @0x318d38 tst r1, r2 */
/* @0x318d3c beq 0x318dc4 <__divsi3+0xb4> */
/* @0x318d40 clz r2, r1 */
/* @0x318d44 clz r0, r3 */
/* @0x318d48 sub r0, r2, r0 */
/* @0x318d4c mov r2, #1 */
/* @0x318d50 lsl r1, r1, r0 */
/* @0x318d54 lsl r2, r2, r0 */
/* @0x318d58 mov r0, #0 */
/* @0x318d5c cmp r3, r1 */
/* @0x318d60 subhs r3, r3, r1 */
/* @0x318d64 orrhs r0, r0, r2 */
/* @0x318d68 cmp r3, r1, lsr #1 */
/* @0x318d6c subhs r3, r3, r1, lsr #1 */
/* @0x318d70 orrhs r0, r0, r2, lsr #1 */
/* @0x318d74 cmp r3, r1, lsr #2 */
/* @0x318d78 subhs r3, r3, r1, lsr #2 */
/* @0x318d7c orrhs r0, r0, r2, lsr #2 */
/* @0x318d80 cmp r3, r1, lsr #3 */
/* @0x318d84 subhs r3, r3, r1, lsr #3 */
/* @0x318d88 orrhs r0, r0, r2, lsr #3 */
/* @0x318d8c cmp r3, #0 */
/* @0x318d90 lsrsne r2, r2, #4 */
/* @0x318d94 lsrne r1, r1, #4 */
/* @0x318d98 bne 0x318d5c <__divsi3+0x4c> */
/* @0x318d9c cmp r12, #0 */
/* @0x318da0 rsbmi r0, r0, #0 */
/* @0x318da4 bx lr */
/* @0x318da8 teq r12, r0 */
/* @0x318dac rsbmi r0, r0, #0 */
/* @0x318db0 bx lr */
/* @0x318db4 movlo r0, #0 */
/* @0x318db8 asreq r0, r12, #31 */
/* @0x318dbc orreq r0, r0, #1 */
/* @0x318dc0 bx lr */
/* @0x318dc4 clz r2, r1 */
/* @0x318dc8 rsb r2, r2, #31 */
/* @0x318dcc cmp r12, #0 */
/* @0x318dd0 lsr r0, r3, r2 */
/* @0x318dd4 rsbmi r0, r0, #0 */
/* @0x318dd8 bx lr */
/* @0x318ddc cmp r0, #0 */
/* @0x318de0 mvngt r0, #-2147483648 */
/* @0x318de4 movlt r0, #-2147483648 */
/* @0x318de8 b 0x319458 <__aeabi_ldiv0> */

/* ── FUNC 0x318dec · __aeabi_idivmod · size=32 · insn=8 */
/* @0x318dec cmp r1, #0 */
/* @0x318df0 beq 0x318ddc <__divsi3+0xcc> */
/* @0x318df4 push {r0, r1, lr} */
/* @0x318df8 bl 0x318d18 <__divsi3+0x8> */
/* @0x318dfc pop {r1, r2, lr} */
/* @0x318e00 mul r3, r2, r0 */
/* @0x318e04 sub r1, r1, r3 */
/* @0x318e08 bx lr */

/* ── FUNC 0x318e0c · anon_318e0c · size=4 · insn=2 */
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
