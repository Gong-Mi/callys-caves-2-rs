/* libyoyo.so 覆盖卡组 0250
 * 函数 0x2a2c28..0x2a44d6，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a2c28 · SetLaunchedFromPlayer(char const*, bool) · size=20 · insn=5 */
/* @0x2a2c28 ldr r3, [pc, #0x8] */
/* @0x2a2c2c ldr r3, [pc, r3] */
/* @0x2a2c30 strb r1, [r3] */
/* @0x2a2c34 b 0x15f61c <_Z28SetAndroidLaunchedFromPlayerPKcb> */
/* @0x2a2c38 andseq r11, r4, r4 */

/* ── FUNC 0x2a2c3c · RunGame() · size=560 · insn=140 */
/* @0x2a2c3c push {r4, r5, r6, r7, r8, lr} */
/* @0x2a2c40 sub sp, sp, #8 */
/* @0x2a2c44 ldr r4, [pc, #0x1e0] */
/* @0x2a2c48 ldr r3, [pc, #0x1e0] */
/* @0x2a2c4c add r4, pc, r4 */
/* @0x2a2c50 ldr r5, [r4, r3] */
/* @0x2a2c54 ldr r6, [r5] */
/* @0x2a2c58 cmp r6, #0 */
/* @0x2a2c5c beq 0x2a2d3c <_Z7RunGamev+0x100> */
/* @0x2a2c60 ldr r3, [pc, #0x1cc] */
/* @0x2a2c64 ldr r6, [r4, r3] */
/* @0x2a2c68 ldr r0, [r6] */
/* @0x2a2c6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2c70 ldr r1, [pc, #0x1c0] */
/* @0x2a2c74 mov r3, #1 */
/* @0x2a2c78 mov r0, #4096 */
/* @0x2a2c7c add r1, pc, r1 */
/* @0x2a2c80 movw r2, #0x38a */
/* @0x2a2c84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2c88 ldr r3, [pc, #0x1ac] */
/* @0x2a2c8c str r0, [r6] */
/* @0x2a2c90 ldr r6, [r4, r3] */
/* @0x2a2c94 ldr r12, [r6] */
/* @0x2a2c98 cmp r12, #0 */
/* @0x2a2c9c beq 0x2a2e14 <_Z7RunGamev+0x1d8> */
/* @0x2a2ca0 ldr r7, [pc, #0x198] */
/* @0x2a2ca4 mov r1, #4096 */
/* @0x2a2ca8 ldr r3, [r5] */
/* @0x2a2cac add r7, pc, r7 */
/* @0x2a2cb0 str r12, [sp] */
/* @0x2a2cb4 mov r2, r7 */
/* @0x2a2cb8 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2cbc ldr r1, [r5] */
/* @0x2a2cc0 mov r0, r7 */
/* @0x2a2cc4 ldr r2, [r6] */
/* @0x2a2cc8 bl 0xb6964 <printf@plt> */
/* @0x2a2ccc ldr r0, [r5] */
/* @0x2a2cd0 mov r1, #1 */
/* @0x2a2cd4 bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb> */
/* @0x2a2cd8 ldr r3, [pc, #0x164] */
/* @0x2a2cdc mov r2, #1 */
/* @0x2a2ce0 ldr r0, [r5] */
/* @0x2a2ce4 ldr r3, [r4, r3] */
/* @0x2a2ce8 strb r2, [r3] */
/* @0x2a2cec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2cf0 ldr r0, [r6] */
/* @0x2a2cf4 cmp r0, #0 */
/* @0x2a2cf8 beq 0x2a2d00 <_Z7RunGamev+0xc4> */
/* @0x2a2cfc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d00 ldr r3, [pc, #0x140] */
/* @0x2a2d04 mov r7, #0 */
/* @0x2a2d08 str r7, [r5] */
/* @0x2a2d0c str r7, [r6] */
/* @0x2a2d10 ldr r5, [r4, r3] */
/* @0x2a2d14 ldr r0, [r5] */
/* @0x2a2d18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d1c ldr r3, [pc, #0x128] */
/* @0x2a2d20 str r7, [r5] */
/* @0x2a2d24 ldr r3, [r4, r3] */
/* @0x2a2d28 ldr r0, [r3] */
/* @0x2a2d2c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2d30 str r0, [r5] */
/* @0x2a2d34 add sp, sp, #8 */
/* @0x2a2d38 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a2d3c ldr r3, [pc, #0x10c] */
/* @0x2a2d40 ldr r5, [r4, r3] */
/* @0x2a2d44 ldr r3, [r5] */
/* @0x2a2d48 cmp r3, #0 */
/* @0x2a2d4c beq 0x2a2d34 <_Z7RunGamev+0xf8> */
/* @0x2a2d50 ldr r2, [pc, #0xfc] */
/* @0x2a2d54 ldr r3, [pc, #0xd8] */
/* @0x2a2d58 ldr r7, [pc, #0xf8] */
/* @0x2a2d5c ldr r2, [r4, r2] */
/* @0x2a2d60 add r7, pc, r7 */
/* @0x2a2d64 strb r6, [r2] */
/* @0x2a2d68 ldr r8, [r4, r3] */
/* @0x2a2d6c ldr r0, [r8] */
/* @0x2a2d70 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2d74 ldr r1, [pc, #0xe0] */
/* @0x2a2d78 mov r2, #948 */
/* @0x2a2d7c mov r3, #1 */
/* @0x2a2d80 add r1, pc, r1 */
/* @0x2a2d84 mov r0, #4096 */
/* @0x2a2d88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2a2d8c ldr r2, [pc, #0xcc] */
/* @0x2a2d90 ldr r3, [r5] */
/* @0x2a2d94 mov r1, #4096 */
/* @0x2a2d98 add r2, pc, r2 */
/* @0x2a2d9c str r0, [r8] */
/* @0x2a2da0 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2da4 mov r1, r6 */
/* @0x2a2da8 mov r0, r7 */
/* @0x2a2dac bl 0x2a2c28 <_Z21SetLaunchedFromPlayerPKcb> */
/* @0x2a2db0 ldr r3, [pc, #0x8c] */
/* @0x2a2db4 ldr r0, [r5] */
/* @0x2a2db8 mov r2, #1 */
/* @0x2a2dbc ldr r3, [r4, r3] */
/* @0x2a2dc0 strb r2, [r3] */
/* @0x2a2dc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2dc8 ldr r3, [pc, #0x78] */
/* @0x2a2dcc str r6, [r5] */
/* @0x2a2dd0 ldr r5, [r4, r3] */
/* @0x2a2dd4 ldr r0, [r5] */
/* @0x2a2dd8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2ddc mov r0, r7 */
/* @0x2a2de0 str r6, [r5] */
/* @0x2a2de4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2de8 ldr r3, [pc, #0x74] */
/* @0x2a2dec str r0, [r5] */
/* @0x2a2df0 ldr r4, [r4, r3] */
/* @0x2a2df4 ldr r0, [r4] */
/* @0x2a2df8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2a2dfc mov r0, r7 */
/* @0x2a2e00 str r6, [r4] */
/* @0x2a2e04 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x2a2e08 str r0, [r4] */
/* @0x2a2e0c add sp, sp, #8 */
/* @0x2a2e10 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2a2e14 ldr r2, [pc, #0x4c] */
/* @0x2a2e18 mov r1, #4096 */
/* @0x2a2e1c ldr r3, [r5] */
/* @0x2a2e20 add r2, pc, r2 */
/* @0x2a2e24 bl 0xb65c8 <snprintf@plt> */
/* @0x2a2e28 b 0x2a2cd8 <_Z7RunGamev+0x9c> */
/* @0x2a2e2c andseq pc, r4, r4 */
/* @0x2a2e30 .word 0xffffdf58 */
/* @0x2a2e34 .word 0xfffffd10 */
/* @0x2a2e38 andeq r7, r11, r4, ror #11 */
/* @0x2a2e3c .word 0xffffdf60 */
/* @0x2a2e40 ldrdeq r7, r8, [r11], -r8 */
/* @0x2a2e44 .word 0xfffffcf0 */
/* @0x2a2e48 .word 0xfffffcc4 */
/* @0x2a2e4c .word 0xffffdf54 */
/* @0x2a2e50 .word 0xfffffde0 */
/* @0x2a2e54 .word 0xffffc140 */
/* @0x2a2e58 ldrdeq r11, r12, [r8], -r6 */
/* @0x2a2e5c andeq r7, r11, r0, ror #9 */
/* @0x2a2e60 andeq r7, r11, r0, ror #13 */
/* @0x2a2e64 .word 0xffffef18 */
/* @0x2a2e68 andeq r7, r11, r8, asr r6 */

/* ── FUNC 0x2a2e6c · anon_2a2e6c · size=32 · insn=9 */
/* @0x2a2e6c ldr r1, [pc, #0x18] */
/* @0x2a2e70 mov r0, #0 */
/* @0x2a2e74 mov r2, #0 */
/* @0x2a2e78 mov r3, #0 */
/* @0x2a2e7c add r1, pc, r1 */
/* @0x2a2e80 str r0, [r1] */
/* @0x2a2e84 strd r2, r3, [r1, #8] */
/* @0x2a2e88 bx lr */
/* @0x2a2e8c subeq r6, r11, r4, asr r2 */

/* ── FUNC 0x2a2e90 · android_getCpuFamily · size=44 · insn=11 */
/* @0x2a2e90 push {r4, lr} */
/* @0x2a2e94 ldr r4, [pc, #0x18] */
/* @0x2a2e98 ldr r1, [pc, #0x18] */
/* @0x2a2e9c add r4, pc, r4 */
/* @0x2a2ea0 add r1, pc, r1 */
/* @0x2a2ea4 add r0, r4, #16 */
/* @0x2a2ea8 bl 0xb6e98 <pthread_once@plt> */
/* @0x2a2eac ldr r0, [r4] */
/* @0x2a2eb0 pop {r4, pc} */
/* @0x2a2eb4 subeq r6, r11, r4, lsr r2 */
/* @0x2a2eb8 .word 0xffffffc4 */

/* ── FUNC 0x2a2ebc · android_getCpuFeatures · size=44 · insn=11 */
/* @0x2a2ebc push {r4, lr} */
/* @0x2a2ec0 ldr r4, [pc, #0x18] */
/* @0x2a2ec4 ldr r1, [pc, #0x18] */
/* @0x2a2ec8 add r4, pc, r4 */
/* @0x2a2ecc add r1, pc, r1 */
/* @0x2a2ed0 add r0, r4, #16 */
/* @0x2a2ed4 bl 0xb6e98 <pthread_once@plt> */
/* @0x2a2ed8 ldrd r0, r1, [r4, #8] */
/* @0x2a2edc pop {r4, pc} */
/* @0x2a2ee0 subeq r6, r11, r8, lsl #4 */
/* @0x2a2ee4 .word 0xffffff98 */

/* ── FUNC 0x2a2ee8 · anon_2a2ee8 · size=768 · insn=193 */
/* @0x2a2ee8 movwhs r11, #0x4537 */
/* @0x2a2eec strmi r4, [r4], -sp, lsl #12 */
/* @0x2a2ef0 ldrmi r4, [r0], -r9, ror #12 */
/* @0x2a2ef4 strmi r2, [r8, r8, lsl #4]! */
/* @0x2a2ef8 .word 0xdc032807 */
/* @0x2a2efc eorvs r2, r3, r4, lsl r3 */
/* @0x2a2f00 and r2, r2, r0, lsl #6 */
/* @0x2a2f04 eorvs r9, r3, r0, lsl #22 */
/* @0x2a2f08 rsbvs r9, r3, r1, lsl #22 */
/* @0x2a2f0c ldclt p0, c11, [r0, #-12]! */
/* @0x2a2f10 stmdavs r9, {r6, r11, sp, lr} ^ */
/* @0x2a2f14 stcllt p0, c15, [r2, #480] */
/* @0x2a2f18 svcmi #0xf0e92d */
/* @0x2a2f1c stcmi p5, c15, [r0, #692] */
/* @0x2a2f20 mrrcmi p0, #0x9, r11, lr, c11 */
/* @0x2a2f24 strmi pc, [r1, sp, lsl #10] */
/* @0x2a2f28 .word 0x3710461d */
/* @0x2a2f2c stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a2f30 .word 0xf50d9107 */
/* @0x2a2f34 ldmdavs pc!, {r7, r8, lr} */
/* @0x2a2f38 stmdavs r3!, {r2, r5, r6, r8, r12, sp} */
/* @0x2a2f3c stmdaeq r8, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a2f40 .word 0xf8a54606 */
/* @0x2a2f44 smladls r8, r8, r0, r8 */
/* @0x2a2f48 andvs r2, r11, r0, lsl #14 */
/* @0x2a2f4c shadd8mi r4, r9, r3 */
/* @0x2a2f50 .word 0x612f463a */
/* @0x2a2f54 .word 0x616f4638 */
/* @0x2a2f58 stmdbeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x2a2f5c svc #0xa2f613 */
/* @0x2a2f60 ldrtmi r2, [r10], -r1, lsl #2 */
/* @0x2a2f64 .word 0x97149713 */
/* @0x2a2f68 smladls r12, r5, r7, r9 */
/* @0x2a2f6c adcvs r9, r8, pc, lsl #14 */
/* @0x2a2f70 .word 0xf0014630 */
/* @0x2a2f74 strls pc, [r9], #-3267 */
/* @0x2a2f78 .word 0xf1a94b49 */
/* @0x2a2f7c .word 0x4642043c */
/* @0x2a2f80 ldrbtmi r2, [r11], #-265 */
/* @0x2a2f84 teqhs r8, #134217728 */
/* @0x2a2f88 .word 0xf06f9303 */
/* @0x2a2f8c adcsmi r0, r8, #939524096 */
/* @0x2a2f90 andhs r11, r9, r12, lsl #30 */
/* @0x2a2f94 .word 0xf50d4640 */
/* @0x2a2f98 stm sp, {r0, r11, r12, lr} */
/* @0x2a2f9c strtmi r0, [r0], -r1, lsl #1 */
/* @0x2a2fa0 svc #0x86f613 */
/* @0x2a2fa4 stmdaeq r4!, {r3, r8, r12, sp, lr, pc} */
/* @0x2a2fa8 movwpl pc, #0x44f */
/* @0x2a2fac ldchi p8, c15, [r0], #-292 */
/* @0x2a2fb0 stclo p8, c15, [r12], #-292 */
/* @0x2a2fb4 ldcvc p8, c15, [r12], #-292 */
/* @0x2a2fb8 ldcvc p8, c15, [r8], #-292 */
/* @0x2a2fbc stmdbeq r4, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x2a2fc0 stmdavs r3!, {r0, r2, r8, r9, r10, r12, pc} ^ */
/* @0x2a2fc4 svcls #0x5bb1b */
/* @0x2a2fc8 .word 0xf44fbb0f */
/* @0x2a2fcc ldrbmi r5, [r8], -r0, lsl #4 */
/* @0x2a2fd0 movwhs r4, #0x1649 */
/* @0x2a2fd4 ldrmi r9, [r8, r7, lsl #30]! */
/* @0x2a2fd8 ble 0x4ea7e8 <SrcVerts+0x4782c> */
/* @0x2a2fdc andeq pc, r12, r6, lsl #2 */
/* @0x2a2fe0 ldrbmi r9, [r10], -r7, lsl #18 */
/* @0x2a2fe4 .word 0xff80f7ff */
/* @0x2a2fe8 .word 0xf6134620 */
/* @0x2a2fec ands lr, r11, r6, ror #25 */
/* @0x2a2ff0 stmdbvs r11!, {r0, r1, r3, r12, lr, pc} */
/* @0x2a2ff4 stmvs r8!, {r0, r3, r6, r9, r10, lr} */
/* @0x2a2ff8 .word 0x612b4413 */
/* @0x2a2ffc .word 0xf8c46062 */
/* @0x2a3000 .word 0xf6139000 */
/* @0x2a3004 adcvs lr, r8, r0, asr pc */
/* @0x2a3008 strhs lr, [r4, -r1] */
/* @0x2a300c strtmi r9, [r0], -r5, lsl #14 */
/* @0x2a3010 .word 0xf6139905 */
/* @0x2a3014 stmdahs r1, {r2, r3, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a3018 stmdble r8, {r1, r7, r9, r10, lr} */
/* @0x2a301c andeq pc, r12, r6, lsl #2 */
/* @0x2a3020 ldrbmi r2, [r2], -sp, lsl #2 */
/* @0x2a3024 .word 0xf998f001 */
/* @0x2a3028 rscslo pc, pc, pc, asr #32 */
/* @0x2a302c stmdbvs r3!, {r0, r1, r2, r5, sp, lr, pc} */
/* @0x2a3030 svcpl #0xf5b3 */
/* @0x2a3034 .word 0xf5c3d01c */
/* @0x2a3038 strbmi r5, [r0], -r0, lsl #24 */
/* @0x2a303c blls 0x4ab448 <SrcVerts+0x848c> */
/* @0x2a3040 .word 0xf8cd4662 */
/* @0x2a3044 .word 0xf613c018 */
/* @0x2a3048 .word 0xf8ddec3a */
/* @0x2a304c strbmi r12, [r0, #-0x18]! */
/* @0x2a3050 .word 0xf613d006 */
/* @0x2a3054 ldrdhs lr, pc, [r6, -r2] */
/* @0x2a3058 .word 0xf1066802 */
/* @0x2a305c strb r0, [r1, r12]! */
/* @0x2a3060 vst2.16 {d22, d24}, [pc:128], r11 */
/* @0x2a3064 .word 0xf8c45100 */
/* @0x2a3068 ldrmi r8, [r8], #-12 */
/* @0x2a306c .word 0x61686121 */
/* @0x2a3070 svceq #0x1f1ba */
/* @0x2a3074 strtmi sp, [r0], -r5, lsr #3 */
/* @0x2a3078 ldc p6, c15, [lr], {19} */
/* @0x2a307c .word 0xf50d2000 */
/* @0x2a3080 svcls #0x94380 */
/* @0x2a3084 ldmdavs r10, {r2, r5, r6, r8, r9, r12, sp} */
/* @0x2a3088 addsmi r6, r10, #3866624 */
/* @0x2a308c .word 0xf613d001 */
/* @0x2a3090 .word 0xf50deaa2 */
/* @0x2a3094 andslt r4, r11, r0, lsl #27 */
/* @0x2a3098 svchi #0xf0e8bd */
/* @0x2a309c andseq r10, r4, r8, lsr #20 */
/* @0x2a30a0 andeq r9, lr, r6, asr #32 */
/* @0x2a30a4 svcmi #0xf0e92d */
/* @0x2a30a8 stcpl p5, c15, [r0, #-692] */
/* @0x2a30ac addlt r4, r3, r6, lsr #26 */
/* @0x2a30b0 sadd8mi r4, lr, r2 */
/* @0x2a30b4 stmdavs sp!, {r0, r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a30b8 andpl pc, r0, #54525952 */
/* @0x2a30bc strmi r3, [r1], r4, lsl #4 */
/* @0x2a30c0 strmi r6, [r12], -r11, lsr #16 */
/* @0x2a30c4 teqlt r9, r3, lsl r0 */
/* @0x2a30c8 bleq 0x31f9d8 */
/* @0x2a30cc stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2a30d0 bne 0xbdb0d8 <b2_toiTime+0x481c34> */
/* @0x2a30d4 .word 0xdc012c00 */
/* @0x2a30d8 eor r2, r7, r0 */
/* @0x2a30dc svclt #0x34455c */
/* @0x2a30e0 .word 0xf44f4622 */
/* @0x2a30e4 strbmi r5, [r0], -r0, lsl #4 */
/* @0x2a30e8 strbmi r2, [r11], -r1, lsl #2 */
/* @0x2a30ec bl 0xffde0940 <b2_toiTime+0xffffffffff68749c> */
/* @0x2a30f0 ble 0x3ea914 <af_cjk_writing_system_class+0x31c> */
/* @0x2a30f4 stc p6, c15, [r0, #76] */
/* @0x2a30f8 stmdavs r2, {r0, r2, r8, sp} */
/* @0x2a30fc ands r4, r1, r0, lsr r6 */
/* @0x2a3100 ldrtmi sp, [r0], -r3, lsl #2 */
/* @0x2a3104 shadd16mi r2, r10, r1 */
/* @0x2a3108 strbmi lr, [r0], -r12 */
/* @0x2a310c ldrtmi r2, [r10], -r1, lsl #2 */
/* @0x2a3110 .word 0xf6134653 */
/* @0x2a3114 adcsmi lr, r8, #212, #22 */
/* @0x2a3118 .word 0xf613d0db */
/* @0x2a311c .word 0x2106ed6e */
/* @0x2a3120 ldrtmi r6, [r0], -r2, lsl #16 */
/* @0x2a3124 .word 0xf918f001 */
/* @0x2a3128 rscslo pc, pc, pc, asr #32 */
/* @0x2a312c movwpl pc, #0x50d */
/* @0x2a3130 ldmdavs r10, {r2, r8, r9, r12, sp} */
/* @0x2a3134 addsmi r6, r10, #2818048 */
/* @0x2a3138 .word 0xf613d001 */
/* @0x2a313c .word 0xf50dea4c */
/* @0x2a3140 andlt r5, r3, r0, lsl #26 */
/* @0x2a3144 svchi #0xf0e8bd */
/* @0x2a3148 andseq r10, r4, r0, lsr #17 */
/* @0x2a314c svcmi #0xf0e92d */
/* @0x2a3150 stcpl p5, c15, [r0, #-692] */
/* @0x2a3154 stcmi p0, c11, [r4], #-524 */
/* @0x2a3158 .word 0xf50d4616 */
/* @0x2a315c eorslo r5, r0, #0, #4 */
/* @0x2a3160 stmdavs r4!, {r2, r3, r4, r5, r6, r10, lr} */
/* @0x2a3164 .word 0x9000f8d2 */
/* @0x2a3168 .word 0xf50d469a */
/* @0x2a316c stmdavs r3!, {r9, r12, lr} */
/* @0x2a3170 .word 0xf10d3204 */
/* @0x2a3174 strmi r0, [r0], r4, lsl #22 */
/* @0x2a3178 andsvs r4, r3, pc, lsl #12 */
/* @0x2a317c eorsvs r2, r3, r0, lsl #6 */
/* @0x2a3180 uasxmi r4, r9, r8 */
/* @0x2a3184 andpl pc, r0, #1325400064 */
/* @0x2a3188 strbmi r2, [r0, r1, lsl #6] */
/* @0x2a318c ldcle p14, c1, [r3, #-20] */
/* @0x2a3190 qaddhs r4, r8, r1 */
/* @0x2a3194 ldrbmi r4, [r3], -r10, lsr #12 */
/* @0x2a3198 bl 0xfe6e09ec <b2_toiTime+0xfffffffffdf87548> */
/* @0x2a319c andle r4, r7, r8, lsr #5 */
/* @0x2a31a0 stc p6, c15, [r10, #-76]! */
/* @0x2a31a4 stmdavs r2, {r1, r2, r8, sp} */
/* @0x2a31a8 .word 0xf0014648 */
/* @0x2a31ac .word 0xe00bf8d5 */
/* @0x2a31b0 ldrmi r6, [r8], #-2099 */
/* @0x2a31b4 .word 0xe7e36030 */
/* @0x2a31b8 strtmi r11, [r8], -r8, lsl #30 */
/* @0x2a31bc strbmi sp, [r8], -r6 */
/* @0x2a31c0 ldrtmi r4, [r10], -r1, asr #12 */
/* @0x2a31c4 mrc2 p7, #0x4, apsr_nzcv, c0, c15, #0x7 */
/* @0x2a31c8 rscslo pc, pc, pc, asr #32 */
/* @0x2a31cc movwpl pc, #0x50d */
/* @0x2a31d0 ldmdavs r10, {r2, r8, r9, r12, sp} */
/* @0x2a31d4 addsmi r6, r10, #2293760 */
/* @0x2a31d8 .word 0xf613d001 */
/* @0x2a31dc .word 0xf50de9fc */
/* @0x2a31e0 andlt r5, r3, r0, lsl #26 */
/* @0x2a31e4 svchi #0xf0e8bd */
/* @0x2a31e8 ldrsheq r10, [r4], -r4 */

/* ── FUNC 0x2a31ec · zip_close · size=1968 · insn=877 */
/* @0x2a31ec ldr.w r3, [pc, #0x78c] */
/* @0x2a31f0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a31f4 add r3, pc */
/* @0x2a31f6 ldr r3, [r3] */
/* @0x2a31f8 sub sp, #0xa4 */
/* @0x2a31fa mov r4, r0 */
/* @0x2a31fc ldr r2, [r3] */
/* @0x2a31fe str r3, [sp, #0x30] */
/* @0x2a3200 str r2, [sp, #0x9c] */
/* @0x2a3202 cmp r0, #0x0 */
/* @0x2a3204 beq.w 0x2a38e2 <zip_close+0x6f6> */
/* @0x2a3208 ldr r3, [r0, #0x28] */
/* @0x2a320a adds r3, #0x1 */
/* @0x2a320c bne 0x2a321a <zip_close+0x2e> */
/* @0x2a320e ldr r2, [r0, #0x1c] */
/* @0x2a3210 ldr r3, [r0, #0x18] */
/* @0x2a3212 subs r3, r2, r3 */
/* @0x2a3214 it ne */
/* @0x2a3216 movne r3, #0x1 */
/* @0x2a3218 b 0x2a321c <zip_close+0x30> */
/* @0x2a321a movs r3, #0x1 */
/* @0x2a321c ldr r5, [r4, #0x2c] */
/* @0x2a321e movs r1, #0x0 */
/* @0x2a3220 mov r2, r1 */
/* @0x2a3222 movs r6, #0x14 */
/* @0x2a3224 str r1, [sp, #0x1c] */
/* @0x2a3226 cmp r2, r5 */
/* @0x2a3228 bge 0x2a3256 <zip_close+0x6a> */
/* @0x2a322a mul r1, r6, r2 */
/* @0x2a322c blvs 0x1adf63c <b2_toiTime+0x1386198> */
/* @0x2a322e ldr r0, [r4, #0x34] */
/* @0x2a3230 adds r7, r0, r1 */
/* @0x2a3232 ldr r1, [r0, r1] */
/* @0x2a3234 cbnz r1, 0x2a3242 <zip_close+0x56> */
/* @0x2a3236 ldr r1, [r7, #0x10] */
/* @0x2a3238 cmp.w r1, #0xffffffff */
/* @0x2a323c it ne */
/* @0x2a323e movne r3, #0x1 */
/* @0x2a3240 b 0x2a3248 <zip_close+0x5c> */
/* @0x2a3242 cmp r1, #0x1 */
/* @0x2a3244 beq 0x2a3250 <zip_close+0x64> */
/* @0x2a3246 movs r3, #0x1 */
/* @0x2a3248 ldr r1, [sp, #0x1c] */
/* @0x2a324a adds r1, #0x1 */
/* @0x2a324c str r1, [sp, #0x1c] */
/* @0x2a324e b 0x2a3252 <zip_close+0x66> */
/* @0x2a3250 mov r3, r1 */
/* @0x2a3252 adds r2, #0x1 */
/* @0x2a3254 b 0x2a3226 <zip_close+0x3a> */
/* @0x2a3256 cbnz r3, 0x2a3262 <zip_close+0x76> */
/* @0x2a3258 mov r0, r4 */
/* @0x2a325a movs r5, #0x0 */
/* @0x2a325c bl 0x2a4884 <_Z9_zip_freeP3zip> */
/* @0x2a3260 b 0x2a393e <zip_close+0x752> */
/* @0x2a3262 ldr r2, [sp, #0x1c] */
/* @0x2a3264 cbnz r2, 0x2a3290 <zip_close+0xa4> */
/* @0x2a3266 ldr r0, [r4] */
/* @0x2a3268 cmp r0, #0x0 */
/* @0x2a326a beq 0x2a3258 <zip_close+0x6c> */
/* @0x2a326c ldr r3, [r4, #0x4] */
/* @0x2a326e cbnz r3, 0x2a3276 <zip_close+0x8a> */
/* @0x2a3270 ldr r3, [r4, #0x8] */
/* @0x2a3272 cmp r3, #0x0 */
/* @0x2a3274 beq 0x2a3258 <zip_close+0x6c> */
/* @0x2a3276 blx 0xb6970 <remove@plt> */
/* @0x2a3278 stmdahs r0, {r2, r3, r4, r5, r6, r8, r9, r11, sp, lr, pc} */
/* @0x2a327a cmp r0, #0x0 */
/* @0x2a327c beq 0x2a3258 <zip_close+0x6c> */
/* @0x2a327e blx 0xb6bf8 <__errno@plt> */
/* @0x2a3280 ldrhhs lr, [r6, -r12] */
/* @0x2a3282 movs r1, #0x16 */
/* @0x2a3284 ldr r2, [r0] */
/* @0x2a3286 add.w r0, r4, #0xc */
/* @0x2a3288 .word 0xf001000c */
/* @0x2a328a bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a328c msr APSR_nzcvq, #6619136 */
/* @0x2a328e b 0x2a38e2 <zip_close+0x6f6> */
/* @0x2a3290 ldr r3, [sp, #0x1c] */
/* @0x2a3292 lsls r0, r3, #0x3 */
/* @0x2a3294 blx 0xb6544 <malloc@plt> */
/* @0x2a3298 str r0, [sp, #0x10] */
/* @0x2a329a cmp r0, #0x0 */
/* @0x2a329c beq.w 0x2a38e2 <zip_close+0x6f6> */
/* @0x2a32a0 add.w r6, r4, #0xc */
/* @0x2a32a4 ldr r0, [sp, #0x1c] */
/* @0x2a32a6 mov r1, r6 */
/* @0x2a32a8 bl 0x2a3b88 <_Z13_zip_cdir_newiP9zip_error> */
/* @0x2a32ac mov r5, r0 */
/* @0x2a32ae cmp r0, #0x0 */
/* @0x2a32b0 beq.w 0x2a3970 <zip_close+0x784> */
/* @0x2a32b4 movs r7, #0x0 */
/* @0x2a32b6 mov.w r8, #0x3c */
/* @0x2a32b8 stmdavs r8!, {r2, r3, r4, r5, r11} */
/* @0x2a32ba ldr r0, [r5] */
/* @0x2a32bc mla r0, r8, r7, r0 */
/* @0x2a32c0 bl 0x2a3c2c <_Z16_zip_dirent_initP10zip_dirent> */
/* @0x2a32c4 ldr r1, [sp, #0x1c] */
/* @0x2a32c6 adds r7, #0x1 */
/* @0x2a32c8 cmp r7, r1 */
/* @0x2a32ca blt 0x2a32ba <zip_close+0xce> */
/* @0x2a32cc mov r0, r4 */
/* @0x2a32ce movs r1, #0x1 */
/* @0x2a32d0 movs r2, #0x0 */
/* @0x2a32d2 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a32d4 cmplt r0, r3, lsl r11 */
/* @0x2a32d6 cbz r0, 0x2a32ee <zip_close+0x102> */
/* @0x2a32d8 ldr.w r0, [pc, #0x6a4] */
/* @0x2a32dc movs r1, #0x16 */
/* @0x2a32de mov r2, r6 */
/* @0x2a32e0 add r0, pc */
/* @0x2a32e2 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error> */
/* @0x2a32e4 tsths r6, #74752 */
/* @0x2a32e6 movs r3, #0x16 */
/* @0x2a32e8 str r0, [r5, #0x10] */
/* @0x2a32ea cbnz r0, 0x2a3330 <zip_close+0x144> */
/* @0x2a32ec b 0x2a396a <zip_close+0x77e> */
/* @0x2a32ee mov r0, r4 */
/* @0x2a32f0 movs r1, #0x1 */
/* @0x2a32f2 movs r2, #0x8 */
/* @0x2a32f4 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a32f8 cbnz r0, 0x2a3332 <zip_close+0x146> */
/* @0x2a32fa ldr r1, [r4, #0x28] */
/* @0x2a32fc adds r0, r1, #0x1 */
/* @0x2a32fe beq 0x2a3314 <zip_close+0x128> */
/* @0x2a3300 ldr r0, [r4, #0x24] */
/* @0x2a3302 mov r2, r6 */
/* @0x2a3304 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error> */
/* @0x2a3308 str r0, [r5, #0x10] */
/* @0x2a330a cmp r0, #0x0 */
/* @0x2a330c beq.w 0x2a396a <zip_close+0x77e> */
/* @0x2a3310 ldr r3, [r4, #0x28] */
/* @0x2a3312 b 0x2a3330 <zip_close+0x144> */
/* @0x2a3314 ldr r3, [r4, #0x20] */
/* @0x2a3316 cbz r3, 0x2a3332 <zip_close+0x146> */
/* @0x2a3318 ldr r0, [r3, #0x10] */
/* @0x2a331a cbz r0, 0x2a3332 <zip_close+0x146> */
/* @0x2a331c ldrh r1, [r3, #0x14] */
/* @0x2a331e mov r2, r6 */
/* @0x2a3320 bl 0x2a4978 <_Z11_zip_memdupPKvjP9zip_error> */
/* @0x2a3324 str r0, [r5, #0x10] */
/* @0x2a3326 cmp r0, #0x0 */
/* @0x2a3328 beq.w 0x2a396a <zip_close+0x77e> */
/* @0x2a332c ldr r3, [r4, #0x20] */
/* @0x2a332e ldrh r3, [r3, #0x14] */
/* @0x2a3330 strh r3, [r5, #0x14] */
/* @0x2a3332 ldr r7, [r4] */
/* @0x2a3334 mov r0, r7 */
/* @0x2a3336 blx 0xb6538 <strlen@plt> */
/* @0x2a3338 andlo lr, r8, r0, lsl #18 */
/* @0x2a333a adds r0, #0x8 */
/* @0x2a333c blx 0xb6544 <malloc@plt> */
/* @0x2a3340 mov r11, r0 */
/* @0x2a3342 cbnz r0, 0x2a3350 <zip_close+0x164> */
/* @0x2a3344 mov r0, r6 */
/* @0x2a3346 movs r1, #0xe */
/* @0x2a3348 mov r2, r11 */
/* @0x2a334a bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a334c movw pc, #0xc805 */
/* @0x2a334e b 0x2a396a <zip_close+0x77e> */
/* @0x2a3350 ldr.w r1, [pc, #0x630] */
/* @0x2a3354 mov r2, r7 */
/* @0x2a3356 add r1, pc */
/* @0x2a3358 blx 0xb6550 <sprintf@plt> */
/* @0x2a335c mov r0, r11 */
/* @0x2a335e blx 0xb6ebc <mkstemp@plt> */
/* @0x2a3360 mcrrne p13, #0xa, lr, r1, c14 */
/* @0x2a3362 adds r1, r0, #0x1 */
/* @0x2a3364 bne 0x2a3376 <zip_close+0x18a> */
/* @0x2a3366 blx 0xb6bf8 <__errno@plt> */
/* @0x2a3368 .word 0x210cec48 */
/* @0x2a336a movs r1, #0xc */
/* @0x2a336c ldr r2, [r0] */
/* @0x2a336e mov r0, r6 */
/* @0x2a3370 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3374 b 0x2a33a4 <zip_close+0x1b8> */
/* @0x2a3376 ldr.w r1, [pc, #0x610] */
/* @0x2a3378 ldrbtmi r1, [r9], #-1552 */
/* @0x2a337a add r1, pc */
/* @0x2a337c blx 0xb6ec8 <fdopen@plt> */
/* @0x2a3380 mov r7, r0 */
/* @0x2a3382 cbz r0, 0x2a3390 <zip_close+0x1a4> */
/* @0x2a3384 mov.w r9, #0x0 */
/* @0x2a3388 mov.w r10, #0x14 */
/* @0x2a338c mov r8, r9 */
/* @0x2a338e b 0x2a33da <zip_close+0x1ee> */
/* @0x2a3390 blx 0xb6bf8 <__errno@plt> */
/* @0x2a3394 movs r1, #0xc */
/* @0x2a3396 ldr r2, [r0] */
/* @0x2a3398 mov r0, r6 */
/* @0x2a339a bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a339c .word 0x4658ffdd */
/* @0x2a339e mov r0, r11 */
/* @0x2a33a0 blx 0xb6970 <remove@plt> */
/* @0x2a33a4 mov r0, r11 */
/* @0x2a33a6 blx 0xb655c <free@plt> */
/* @0x2a33a8 sbcs lr, lr, #14286848 */
/* @0x2a33aa b 0x2a396a <zip_close+0x77e> */
/* @0x2a33ac mul r2, r10, r8 */
/* @0x2a33b0 ldr r3, [r4, #0x34] */
/* @0x2a33b2 ldr r3, [r3, r2] */
/* @0x2a33b4 cmp r3, #0x1 */
/* @0x2a33b6 beq 0x2a33d6 <zip_close+0x1ea> */
/* @0x2a33b8 ldr r2, [sp, #0x10] */
/* @0x2a33ba mov r0, r4 */
/* @0x2a33bc mov r1, r8 */
/* @0x2a33be add.w r3, r2, r9, lsl #3 */
/* @0x2a33c0 .word 0xf84203c9 */
/* @0x2a33c2 str.w r8, [r2, r9, lsl #3] */
/* @0x2a33c4 andhs r8, r0, #57 */
/* @0x2a33c6 movs r2, #0x0 */
/* @0x2a33c8 str r3, [sp, #0x8] */
/* @0x2a33ca bl 0x2a4970 <zip_get_name> */
/* @0x2a33cc blls 0x361f18 <_ZTS12CDS_Priority+0x3f70> */
/* @0x2a33ce ldr r3, [sp, #0x8] */
/* @0x2a33d0 add.w r9, r9, #0x1 */
/* @0x2a33d4 str r0, [r3, #0x4] */
/* @0x2a33d6 add.w r8, r8, #0x1 */
/* @0x2a33d8 bvs 0xffb653e4 <b2_toiTime+0xffffffffff40bf40> */
/* @0x2a33da ldr r3, [r4, #0x2c] */
/* @0x2a33dc cmp r8, r3 */
/* @0x2a33de blt 0x2a33ac <zip_close+0x1c0> */
/* @0x2a33e0 mov r0, r4 */
/* @0x2a33e2 movs r1, #0x1 */
/* @0x2a33e4 movs r2, #0x0 */
/* @0x2a33e6 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a33e8 teqlt r8, r9, lsl #21 */
/* @0x2a33ea cbz r0, 0x2a33fc <zip_close+0x210> */
/* @0x2a33ec ldr.w r3, [pc, #0x59c] */
/* @0x2a33f0 movs r2, #0x8 */
/* @0x2a33f2 ldr r0, [sp, #0x10] */
/* @0x2a33f4 ldr r1, [sp, #0x1c] */
/* @0x2a33f6 add r3, pc */
/* @0x2a33f8 blx 0xb66dc <qsort@plt> */
/* @0x2a33fc movs r1, #0x1 */
/* @0x2a33fe mov r0, r4 */
/* @0x2a3400 movs r2, #0x0 */
/* @0x2a3402 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a3404 stmdahs r1, {r0, r1, r3, r4, r5, r6, r9, r11, r12, sp, lr, pc} */
/* @0x2a3406 cmp r0, #0x1 */
/* @0x2a3408 mov r1, r0 */
/* @0x2a340a bne 0x2a3420 <zip_close+0x234> */
/* @0x2a340c mov r0, r4 */
/* @0x2a340e movs r2, #0x8 */
/* @0x2a3410 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a3414 rsbs.w r0, r0, #0x1 */
/* @0x2a3418 it lo */
/* @0x2a341a movlo r0, #0x0 */
/* @0x2a341c str r0, [sp, #0x14] */
/* @0x2a341e b 0x2a3424 <zip_close+0x238> */
/* @0x2a3420 movs r3, #0x0 */
/* @0x2a3422 str r3, [sp, #0x14] */
/* @0x2a3424 ldr.w r2, [pc, #0x568] */
/* @0x2a3428 add r3, sp, #0x38 */
/* @0x2a342a movs r1, #0x0 */
/* @0x2a342c str r3, [sp, #0x24] */
/* @0x2a342e str r1, [sp, #0x18] */
/* @0x2a3430 add r2, pc */
/* @0x2a3432 add.w r1, r3, #0x14 */
/* @0x2a3434 andls r0, r10, #20, #2 */
/* @0x2a3436 str r2, [sp, #0x28] */
/* @0x2a3438 str r1, [sp, #0x34] */
/* @0x2a343a ldr r3, [sp, #0x18] */
/* @0x2a343c mov.w r8, #0x14 */
/* @0x2a3440 ldr r2, [sp, #0x10] */
/* @0x2a3442 ldr.w r10, [r2, r3, lsl #3] */
/* @0x2a3444 blvs 0x1b8b518 <b2_toiTime+0x1432074> */
/* @0x2a3446 ldr r3, [r4, #0x34] */
/* @0x2a3448 mul r8, r8, r10 */
/* @0x2a344c ldr.w r3, [r3, r8] */
/* @0x2a3450 subs r3, #0x2 */
/* @0x2a3452 cmp r3, #0x1 */
/* @0x2a3454 bls 0x2a345c <zip_close+0x270> */
/* @0x2a3456 ldr r1, [sp, #0x14] */
/* @0x2a3458 cmp r1, #0x0 */
/* @0x2a345a beq 0x2a3520 <zip_close+0x334> */
/* @0x2a345c add.w r12, sp, #0x54 */
/* @0x2a3460 str.w r12, [sp, #0xc] */
/* @0x2a3464 mov r0, r12 */
/* @0x2a3466 bl 0x2a3c2c <_Z16_zip_dirent_initP10zip_dirent> */
/* @0x2a3468 strtmi pc, [r0], -r1, ror #23 */
/* @0x2a346a mov r0, r4 */
/* @0x2a346c movs r1, #0x1 */
/* @0x2a346e movs r2, #0x0 */
/* @0x2a3470 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a3474 ldr.w r12, [sp, #0xc] */
/* @0x2a3478 cbz r0, 0x2a3484 <zip_close+0x298> */
/* @0x2a347a mov r0, r12 */
/* @0x2a347c bl 0x2a3c58 <_Z29_zip_dirent_torrent_normalizeP10zip_dirent> */
/* @0x2a3480 ldr.w r12, [sp, #0xc] */
/* @0x2a3484 ldr r2, [sp, #0x18] */
/* @0x2a3486 mov.w r9, #0x3c */
/* @0x2a3488 stmdavs r11!, {r2, r3, r4, r5, r8, r11} */
/* @0x2a348a ldr r3, [r5] */
/* @0x2a348c mul r9, r9, r2 */
/* @0x2a3490 mov r2, r12 */
/* @0x2a3492 add.w r12, r12, #0x38 */
/* @0x2a3494 strbmi r0, [r11], #-3128 */
/* @0x2a3496 add r3, r9 */
/* @0x2a3498 mov lr, r2 */
/* @0x2a349a adds r3, #0x8 */
/* @0x2a349c ldm.w lr!, {r0, r1} */
/* @0x2a34a0 cmp lr, r12 */
/* @0x2a34a2 str r0, [r3, #-8] */
/* @0x2a34a4 ldrbtmi r0, [r2], -r8, lsl #24 */
/* @0x2a34a6 mov r2, lr */
/* @0x2a34a8 str r1, [r3, #-4] */
/* @0x2a34ac bne 0x2a3498 <zip_close+0x2ac> */
/* @0x2a34ae ldr r0, [r2] */
/* @0x2a34b0 str r0, [r3] */
/* @0x2a34b2 ldr r3, [r4, #0x34] */
/* @0x2a34b4 add.w r2, r3, r8 */
/* @0x2a34b8 ldr r2, [r2, #0x8] */
/* @0x2a34ba cmp r2, #0x0 */
/* @0x2a34bc bne 0x2a35b2 <zip_close+0x3c6> */
/* @0x2a34be ldr.w r3, [r3, r8] */
/* @0x2a34c0 blhs 0x36f4e8 <_ZTS13C_UTF16String+0x6594> */
/* @0x2a34c2 cmp r3, #0x3 */
/* @0x2a34c4 bne 0x2a34e4 <zip_close+0x2f8> */
/* @0x2a34c6 ldr r0, [sp, #0x28] */
/* @0x2a34c8 blx 0xb6640 <strdup@plt> */
/* @0x2a34cc movs r3, #0x1 */
/* @0x2a34ce strh.w r3, [sp, #0x70] */
/* @0x2a34d0 stmdbls r10, {r4, r5, r6, r12, sp} */
/* @0x2a34d2 ldr r1, [sp, #0x28] */
/* @0x2a34d4 str r0, [sp, #0x6c] */
/* @0x2a34d6 ldr r2, [r5] */
/* @0x2a34d8 add r2, r9 */
/* @0x2a34da str r1, [r2, #0x18] */
/* @0x2a34dc ldr r2, [r5] */
/* @0x2a34de add r2, r9 */
/* @0x2a34e0 strh r3, [r2, #0x1c] */
/* @0x2a34e2 b 0x2a35b2 <zip_close+0x3c6> */
/* @0x2a34e4 ldr r3, [r4, #0x20] */
/* @0x2a34e6 movs r2, #0x3c */
/* @0x2a34e8 mul r1, r2, r10 */
/* @0x2a34ec ldr r2, [r3] */
/* @0x2a34ee add r2, r1 */
/* @0x2a34f0 ldr r0, [r2, #0x18] */
/* @0x2a34f2 str r1, [sp, #0xc] */
/* @0x2a34f4 str r3, [sp, #0x8] */
/* @0x2a34f6 blx 0xb6640 <strdup@plt> */
/* @0x2a34f8 andsls lr, r11, r4, lsr #17 */
/* @0x2a34fa str r0, [sp, #0x6c] */
/* @0x2a34fc blx 0xb6538 <strlen@plt> */
/* @0x2a3500 ldr r3, [sp, #0x8] */
/* @0x2a3502 ldr r1, [sp, #0xc] */
/* @0x2a3504 strh.w r0, [sp, #0x70] */
/* @0x2a3508 ldr r3, [r3] */
/* @0x2a350a add r3, r1 */
/* @0x2a350c ldr r2, [r3, #0x18] */
/* @0x2a350e ldr r3, [r5] */
/* @0x2a3510 add r3, r9 */
/* @0x2a3512 str r2, [r3, #0x18] */
/* @0x2a3514 ldr r3, [r5] */
/* @0x2a3516 ldrh.w r2, [sp, #0x70] */
/* @0x2a3518 strbmi r2, [r11], #-112 */
/* @0x2a351a add r3, r9 */
/* @0x2a351c strh r2, [r3, #0x1c] */
/* @0x2a351e b 0x2a35b2 <zip_close+0x3c6> */
/* @0x2a3520 ldr r0, [r4, #0x4] */
/* @0x2a3522 cmp r0, #0x0 */
/* @0x2a3524 beq 0x2a361c <zip_close+0x430> */
/* @0x2a3526 ldr r3, [r4, #0x20] */
/* @0x2a3528 movs r2, #0x3c */
/* @0x2a352a ldr r3, [r3] */
/* @0x2a352c mla r3, r2, r10, r3 */
/* @0x2a3530 ldr r2, [sp, #0x14] */
/* @0x2a3532 ldr r1, [r3, #0x38] */
/* @0x2a3534 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a3538 cmp r0, #0x0 */
/* @0x2a353a bne.w 0x2a377a <zip_close+0x58e> */
/* @0x2a353c bls 0x4039bc <g_RomDisk+0xc19c> */
/* @0x2a353e ldr r2, [sp, #0x14] */
/* @0x2a3540 movs r3, #0x1 */
/* @0x2a3542 add r0, sp, #0x54 */
/* @0x2a3544 stm.w sp, {r3, r6} */
/* @0x2a3548 ldr r1, [r4, #0x4] */
/* @0x2a354a mov r3, r2 */
/* @0x2a354c bl 0x2a3ef0 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error> */
/* @0x2a3550 cmp r0, #0x0 */
/* @0x2a3552 bne 0x2a3616 <zip_close+0x42a> */
/* @0x2a3554 ldr r2, [sp, #0x18] */
/* @0x2a3556 movs r3, #0x3c */
/* @0x2a3558 ldr r0, [r5] */
/* @0x2a355a mul r1, r3, r2 */
/* @0x2a355c bvs 0xb5f96c <b2_toiTime+0x4064c8> */
/* @0x2a355e ldr r2, [r4, #0x20] */
/* @0x2a3560 mul r3, r3, r10 */
/* @0x2a3564 ldr r2, [r2] */
/* @0x2a3566 add r0, r1 */
/* @0x2a3568 add r2, r3 */
/* @0x2a356a add.w lr, r2, #0x3c */
/* @0x2a356c .word 0xf8520e3c */
/* @0x2a356e ldr r12, [r2], #4 */
/* @0x2a3570 ldrbmi r12, [r2, #-0xb04]! */
/* @0x2a3572 cmp r2, lr */
/* @0x2a3574 str r12, [r0], #4 */
/* @0x2a3578 bne 0x2a356e <zip_close+0x382> */
/* @0x2a357a ldrh.w lr, [sp, #0x58] */
/* @0x2a357c .word 0xf01ee058 */
/* @0x2a357e tst.w lr, #0x8 */
/* @0x2a3580 andsle r0, r6, r8, lsl #30 */
/* @0x2a3582 beq 0x2a35b2 <zip_close+0x3c6> */
/* @0x2a3584 ldr r2, [r4, #0x20] */
/* @0x2a3586 bic lr, lr, #0x8 */
/* @0x2a3588 ldmdavs r0, {r3, r9, r10, r11} */
/* @0x2a358a ldr r0, [r2] */
/* @0x2a358c add r0, r3 */
/* @0x2a358e ldr r0, [r0, #0xc] */
/* @0x2a3590 str r0, [sp, #0x60] */
/* @0x2a3592 ldr r0, [r2] */
/* @0x2a3594 add r0, r3 */
/* @0x2a3596 ldr r0, [r0, #0x10] */
/* @0x2a3598 str r0, [sp, #0x64] */
/* @0x2a359a ldr r2, [r2] */
/* @0x2a359c strh.w lr, [sp, #0x58] */
/* @0x2a35a0 add r3, r2 */
/* @0x2a35a2 ldr r3, [r3, #0x14] */
/* @0x2a35a4 str r3, [sp, #0x68] */
/* @0x2a35a6 ldr r3, [r5] */
/* @0x2a35a8 add r1, r3 */
/* @0x2a35aa ldrh r3, [r1, #0x4] */
/* @0x2a35ac bic r3, r3, #0x8 */
/* @0x2a35b0 strh r3, [r1, #0x4] */
/* @0x2a35b2 ldr r3, [r4, #0x34] */
/* @0x2a35b4 add r3, r8 */
/* @0x2a35b6 ldr r3, [r3, #0x8] */
/* @0x2a35b8 cmp r3, #0x0 */
/* @0x2a35ba bne 0x2a364a <zip_close+0x45e> */
/* @0x2a35bc mov r0, r4 */
/* @0x2a35be movs r1, #0x1 */
/* @0x2a35c0 movs r2, #0x0 */
/* @0x2a35c2 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a35c4 stmdahs r0, {r0, r1, r3, r4, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2a35c6 cmp r0, #0x0 */
/* @0x2a35c8 beq 0x2a3688 <zip_close+0x49c> */
/* @0x2a35ca ldr r2, [sp, #0x18] */
/* @0x2a35cc movs r3, #0x3c */
/* @0x2a35ce mov r0, r7 */
/* @0x2a35d0 muls r3, r2, r3 */
/* @0x2a35d2 str r3, [sp, #0x20] */
/* @0x2a35d4 ldr.w r9, [sp, #0x20] */
/* @0x2a35d8 ldr r3, [r5] */
/* @0x2a35da add r9, r3 */
/* @0x2a35dc blx 0xb6ee0 <ftello@plt> */
/* @0x2a35e0 str.w r0, [r9, #0x38] */
/* @0x2a35e4 ldr r3, [r4, #0x34] */
/* @0x2a35e6 add.w r2, r3, r8 */
/* @0x2a35e8 .word 0xf8530208 */
/* @0x2a35ea ldr.w r3, [r3, r8] */
/* @0x2a35ec bllo 0x32f614 */
/* @0x2a35ee subs r3, #0x2 */
/* @0x2a35f0 cmp r3, #0x1 */
/* @0x2a35f2 bls 0x2a3696 <zip_close+0x4aa> */
/* @0x2a35f4 ldr r3, [sp, #0x14] */
/* @0x2a35f6 cmp r3, #0x0 */
/* @0x2a35f8 beq.w 0x2a37c0 <zip_close+0x5d4> */
/* @0x2a35fc movs r2, #0x0 */
/* @0x2a35fe mov.w r3, #0xffffffff */
/* @0x2a3600 qsub8mi r3, r0, pc */
/* @0x2a3602 mov r0, r4 */
/* @0x2a3604 stm.w sp, {r2, r3} */
/* @0x2a3608 mov r1, r4 */
/* @0x2a360a mov r2, r10 */
/* @0x2a360c movs r3, #0x10 */
/* @0x2a360e bl 0x2a555c <zip_source_zip> */
/* @0x2a3610 stmdahs r0, {r0, r2, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3612 cmp r0, #0x0 */
/* @0x2a3614 bne 0x2a3698 <zip_close+0x4ac> */
/* @0x2a3616 mov.w r8, #0x1 */
/* @0x2a3618 rscs r0, r2, r1, lsl #16 */
/* @0x2a361a b 0x2a3802 <zip_close+0x616> */
/* @0x2a361c ldr r0, [r4, #0x8] */
/* @0x2a361e cmp r0, #0x0 */
/* @0x2a3620 beq 0x2a3554 <zip_close+0x368> */
/* @0x2a3622 ldr r2, [r4, #0x20] */
/* @0x2a3624 movs r1, #0x3c */
/* @0x2a3626 ldr r3, [r0] */
/* @0x2a3628 ldr r2, [r2] */
/* @0x2a362a ldr r3, [r3, #0x10] */
/* @0x2a362c mla r2, r1, r10, r2 */
/* @0x2a3630 ldr r1, [sp, #0x14] */
/* @0x2a3632 ldr r2, [r2, #0x38] */
/* @0x2a3634 blx r3 */
/* @0x2a3636 ldr r2, [sp, #0x14] */
/* @0x2a3638 movs r3, #0x1 */
/* @0x2a363a add r0, sp, #0x54 */
/* @0x2a363c stm.w sp, {r3, r6} */
/* @0x2a3640 mov r3, r2 */
/* @0x2a3642 ldr r1, [r4, #0x8] */
/* @0x2a3644 bl 0x2a4108 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error> */
/* @0x2a3648 b 0x2a3550 <zip_close+0x364> */
/* @0x2a364a ldr r0, [sp, #0x6c] */
/* @0x2a364c blx 0xb655c <free@plt> */
/* @0x2a3650 ldr r3, [r4, #0x34] */
/* @0x2a3652 add.w r9, r3, r8 */
/* @0x2a3654 .word 0xf8d90908 */
/* @0x2a3656 ldr.w r0, [r9, #0x8] */
/* @0x2a3658 .word 0xf6120008 */
/* @0x2a365a blx 0xb6640 <strdup@plt> */
/* @0x2a365c ldrshls lr, [r11], -r2 */
/* @0x2a365e str r0, [sp, #0x6c] */
/* @0x2a3660 cmp r0, #0x0 */
/* @0x2a3662 beq 0x2a3616 <zip_close+0x42a> */
/* @0x2a3664 blx 0xb6538 <strlen@plt> */
/* @0x2a3668 ldr r1, [sp, #0x18] */
/* @0x2a366a movs r3, #0x3c */
/* @0x2a366c muls r3, r1, r3 */
/* @0x2a366e strh.w r0, [sp, #0x70] */
/* @0x2a3670 stmdavs r10!, {r4, r5, r6} */
/* @0x2a3672 ldr r2, [r5] */
/* @0x2a3674 ldr.w r1, [r9, #0x8] */
/* @0x2a3678 add r2, r3 */
/* @0x2a367a str r1, [r2, #0x18] */
/* @0x2a367c ldr r2, [r5] */
/* @0x2a367e ldrh.w r1, [sp, #0x70] */
/* @0x2a3680 ldrmi r1, [r3], #-112 */
/* @0x2a3682 add r3, r2 */
/* @0x2a3684 strh r1, [r3, #0x1c] */
/* @0x2a3686 b 0x2a35bc <zip_close+0x3d0> */
/* @0x2a3688 ldr r2, [r4, #0x34] */
/* @0x2a368a add r2, r8 */
/* @0x2a368c ldr r3, [r2, #0x10] */
/* @0x2a368e adds r3, #0x1 */
/* @0x2a3690 bne.w 0x2a394e <zip_close+0x762> */
/* @0x2a3694 b 0x2a35ca <zip_close+0x3de> */
/* @0x2a3696 ldr r0, [r2, #0x4] */
/* @0x2a3698 ldr.w r8, [r0, #0x4] */
/* @0x2a369c add r1, sp, #0x38 */
/* @0x2a369e ldr.w r9, [r0] */
/* @0x2a36a0 andshs r9, r12, #0 */
/* @0x2a36a2 movs r2, #0x1c */
/* @0x2a36a4 movs r3, #0x3 */
/* @0x2a36a6 mov r0, r8 */
/* @0x2a36a8 blx r9 */
/* @0x2a36aa cmp r0, #0x1b */
/* @0x2a36ac ble 0x2a370e <zip_close+0x522> */
/* @0x2a36ae movs r1, #0x0 */
/* @0x2a36b0 mov r0, r8 */
/* @0x2a36b2 mov r2, r1 */
/* @0x2a36b4 mov r3, r1 */
/* @0x2a36b6 blx r9 */
/* @0x2a36b8 cmp r0, #0x0 */
/* @0x2a36ba blt 0x2a370e <zip_close+0x522> */
/* @0x2a36bc mov r0, r7 */
/* @0x2a36be add.w r10, sp, #0x54 */
/* @0x2a36c0 .word 0xf6130a54 */
/* @0x2a36c2 blx 0xb6ee0 <ftello@plt> */
/* @0x2a36c4 ldrtmi lr, [r9], -lr, lsl #24 */
/* @0x2a36c6 mov r1, r7 */
/* @0x2a36c8 movs r2, #0x1 */
/* @0x2a36ca mov r3, r6 */
/* @0x2a36cc str r0, [sp, #0x2c] */
/* @0x2a36ce mov r0, r10 */
/* @0x2a36d0 bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error> */
/* @0x2a36d4 cmp r0, #0x0 */
/* @0x2a36d6 blt 0x2a3616 <zip_close+0x42a> */
/* @0x2a36d8 ldrh.w r3, [sp, #0x50] */
/* @0x2a36dc cbz r3, 0x2a36ee <zip_close+0x502> */
/* @0x2a36de str r6, [sp] */
/* @0x2a36e0 mov r0, r9 */
/* @0x2a36e2 mov r1, r8 */
/* @0x2a36e4 ldr r2, [sp, #0x34] */
/* @0x2a36e6 mov r3, r7 */
/* @0x2a36e8 bl 0x2a314c <android_getCpuFeatures+0x290> */
/* @0x2a36ec b 0x2a36fc <zip_close+0x510> */
/* @0x2a36ee str r7, [sp] */
/* @0x2a36f0 mov r0, r4 */
/* @0x2a36f2 mov r1, r9 */
/* @0x2a36f4 mov r2, r8 */
/* @0x2a36f6 add r3, sp, #0x38 */
/* @0x2a36f8 bl 0x2a2f18 <android_getCpuFeatures+0x5c> */
/* @0x2a36fc cmp r0, #0x0 */
/* @0x2a36fe blt 0x2a3616 <zip_close+0x42a> */
/* @0x2a3700 movs r1, #0x0 */
/* @0x2a3702 mov r0, r8 */
/* @0x2a3704 mov r2, r1 */
/* @0x2a3706 movs r3, #0x2 */
/* @0x2a3708 blx r9 */
/* @0x2a370a cmp r0, #0x0 */
/* @0x2a370c bge 0x2a371a <zip_close+0x52e> */
/* @0x2a370e mov r0, r6 */
/* @0x2a3710 mov r1, r9 */
/* @0x2a3712 mov r2, r8 */
/* @0x2a3714 bl 0x2a2ee8 <android_getCpuFeatures+0x2c> */
/* @0x2a3718 b 0x2a3616 <zip_close+0x42a> */
/* @0x2a371a mov r0, r7 */
/* @0x2a371c blx 0xb6ee0 <ftello@plt> */
/* @0x2a3720 ldr r1, [sp, #0x2c] */
/* @0x2a3722 movs r2, #0x0 */
/* @0x2a3724 mov r8, r0 */
/* @0x2a3726 mov r0, r7 */
/* @0x2a3728 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a372c cmp r0, #0x0 */
/* @0x2a372e blt 0x2a377a <zip_close+0x58e> */
/* @0x2a3730 ldr r3, [sp, #0x44] */
/* @0x2a3732 mov r0, r4 */
/* @0x2a3734 movs r1, #0x1 */
/* @0x2a3736 movs r2, #0x0 */
/* @0x2a3738 str r3, [sp, #0x5c] */
/* @0x2a373a ldrh.w r3, [sp, #0x50] */
/* @0x2a373c .word 0xf8ad3050 */
/* @0x2a373e strh.w r3, [sp, #0x5a] */
/* @0x2a3740 blls 0x6af8b0 <g_SWFlinevertbuff+0x5c7e8> */
/* @0x2a3742 ldr r3, [sp, #0x40] */
/* @0x2a3744 str r3, [sp, #0x60] */
/* @0x2a3746 ldr r3, [sp, #0x48] */
/* @0x2a3748 str r3, [sp, #0x68] */
/* @0x2a374a ldr r3, [sp, #0x4c] */
/* @0x2a374c str r3, [sp, #0x64] */
/* @0x2a374e bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a3750 ldrsblt pc, [r0, -r5] */
/* @0x2a3752 cbz r0, 0x2a375a <zip_close+0x56e> */
/* @0x2a3754 mov r0, r10 */
/* @0x2a3756 bl 0x2a3c58 <_Z29_zip_dirent_torrent_normalizeP10zip_dirent> */
/* @0x2a3758 usub16mi pc, r0, pc */
/* @0x2a375a mov r0, r10 */
/* @0x2a375c mov r1, r7 */
/* @0x2a375e movs r2, #0x1 */
/* @0x2a3760 mov r3, r6 */
/* @0x2a3762 bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error> */
/* @0x2a3764 stmdahs r0, {r0, r2, r3, r4, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2a3766 cmp r0, #0x0 */
/* @0x2a3768 blt.w 0x2a3616 <zip_close+0x42a> */
/* @0x2a376c mov r0, r7 */
/* @0x2a376e mov r1, r8 */
/* @0x2a3770 movs r2, #0x0 */
/* @0x2a3772 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a3774 stmdahs r0, {r4, r5, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2a3776 cmp r0, #0x0 */
/* @0x2a3778 bge 0x2a378a <zip_close+0x59e> */
/* @0x2a377a blx 0xb6bf8 <__errno@plt> */
/* @0x2a377c .word 0x2104ea3e */
/* @0x2a377e movs r1, #0x4 */
/* @0x2a3780 ldr r2, [r0] */
/* @0x2a3782 mov r0, r6 */
/* @0x2a3784 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3788 b 0x2a3616 <zip_close+0x42a> */
/* @0x2a378a ldr r3, [r5] */
/* @0x2a378c ldr r2, [sp, #0x20] */
/* @0x2a378e ldr r1, [sp, #0x20] */
/* @0x2a3790 add r2, r3 */
/* @0x2a3792 ldr r3, [sp, #0x5c] */
/* @0x2a3794 str r3, [r2, #0x8] */
/* @0x2a3796 ldr r3, [r5] */
/* @0x2a3798 ldrh.w r2, [sp, #0x5a] */
/* @0x2a379c add r3, r1 */
/* @0x2a379e strh r2, [r3, #0x6] */
/* @0x2a37a0 mov r2, r1 */
/* @0x2a37a2 ldr r3, [r5] */
/* @0x2a37a4 add r2, r3 */
/* @0x2a37a6 ldr r3, [sp, #0x64] */
/* @0x2a37a8 str r3, [r2, #0x10] */
/* @0x2a37aa mov r2, r1 */
/* @0x2a37ac ldr r3, [r5] */
/* @0x2a37ae add r2, r3 */
/* @0x2a37b0 ldr r3, [sp, #0x68] */
/* @0x2a37b2 str r3, [r2, #0x14] */
/* @0x2a37b4 mov r2, r1 */
/* @0x2a37b6 ldr r3, [r5] */
/* @0x2a37b8 add r2, r3 */
/* @0x2a37ba ldr r3, [sp, #0x60] */
/* @0x2a37bc str r3, [r2, #0xc] */
/* @0x2a37be b 0x2a37ea <zip_close+0x5fe> */
/* @0x2a37c0 add r0, sp, #0x54 */
/* @0x2a37c2 mov r1, r7 */
/* @0x2a37c4 movs r2, #0x1 */
/* @0x2a37c6 mov r3, r6 */
/* @0x2a37c8 bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error> */
/* @0x2a37cc cmp r0, #0x0 */
/* @0x2a37ce blt.w 0x2a3616 <zip_close+0x42a> */
/* @0x2a37d0 bls 0x4cf460 <SrcVerts+0x2c4a4> */
/* @0x2a37d2 ldr r2, [sp, #0x20] */
/* @0x2a37d4 ldr r3, [r5] */
/* @0x2a37d6 ldr r0, [r4, #0x4] */
/* @0x2a37d8 add r3, r2 */
/* @0x2a37da mov r2, r7 */
/* @0x2a37dc ldr r1, [r3, #0x10] */
/* @0x2a37de mov r3, r6 */
/* @0x2a37e0 bl 0x2a30a4 <android_getCpuFeatures+0x1e8> */
/* @0x2a37e4 cmp r0, #0x0 */
/* @0x2a37e6 blt.w 0x2a3616 <zip_close+0x42a> */
/* @0x2a37e8 ldmdage r5, {r1, r2, r4, r8, r9, r10, r11, sp, pc} */
/* @0x2a37ea add r0, sp, #0x54 */
/* @0x2a37ec bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent> */
/* @0x2a37f0 ldr r3, [sp, #0x18] */
/* @0x2a37f2 ldr r1, [sp, #0x1c] */
/* @0x2a37f4 adds r3, #0x1 */
/* @0x2a37f6 str r3, [sp, #0x18] */
/* @0x2a37f8 cmp r3, r1 */
/* @0x2a37fa blt.w 0x2a343a <zip_close+0x24e> */
/* @0x2a37fc .word 0xf04fae1e */
/* @0x2a37fe mov.w r8, #0x0 */
/* @0x2a3800 stmdals r4, {r11} */
/* @0x2a3802 ldr r0, [sp, #0x10] */
/* @0x2a3804 blx 0xb655c <free@plt> */
/* @0x2a3808 cmp.w r8, #0x0 */
/* @0x2a380c bne 0x2a389e <zip_close+0x6b2> */
/* @0x2a380e mov r0, r5 */
/* @0x2a3810 mov r1, r7 */
/* @0x2a3812 mov r2, r6 */
/* @0x2a3814 bl 0x2a3e10 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error> */
/* @0x2a3818 cmp r0, #0x0 */
/* @0x2a381a blt 0x2a3894 <zip_close+0x6a8> */
/* @0x2a381c mov r0, r4 */
/* @0x2a381e movs r1, #0x1 */
/* @0x2a3820 mov r2, r8 */
/* @0x2a3822 bl 0x2a48fc <zip_get_archive_flag> */
/* @0x2a3824 ldmdblt r0, {r0, r1, r3, r5, r6, r11, r12, sp, lr, pc} */
/* @0x2a3826 cbnz r0, 0x2a382e <zip_close+0x642> */
/* @0x2a3828 mov.w r8, #0x0 */
/* @0x2a382c b 0x2a3898 <zip_close+0x6ac> */
/* @0x2a382e mov r0, r7 */
/* @0x2a3830 blx 0xb6ee0 <ftello@plt> */
/* @0x2a3834 str r6, [sp] */
/* @0x2a3836 add r3, sp, #0x38 */
/* @0x2a3838 ldr r1, [r5, #0xc] */
/* @0x2a383a ldr r2, [r5, #0x8] */
/* @0x2a383c mov r9, r0 */
/* @0x2a383e mov r0, r7 */
/* @0x2a3840 bl 0x2a43f8 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error> */
/* @0x2a3844 cmp r0, #0x0 */
/* @0x2a3846 blt 0x2a3894 <zip_close+0x6a8> */
/* @0x2a3848 add.w r10, sp, #0x90 */
/* @0x2a384c ldr r2, [pc, #0x144] */
/* @0x2a384e movs r1, #0x9 */
/* @0x2a3850 ldr r3, [sp, #0x38] */
/* @0x2a3852 add r2, pc */
/* @0x2a3854 mov r0, r10 */
/* @0x2a3856 blx 0xb65c8 <snprintf@plt> */
/* @0x2a3858 .word 0x4638eeb8 */
/* @0x2a385a mov r0, r7 */
/* @0x2a385c sub.w r1, r9, #0x8 */
/* @0x2a3860 mov r2, r8 */
/* @0x2a3862 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a3864 stmdahs r0, {r3, r4, r5, r8, r9, r11, sp, lr, pc} */
/* @0x2a3866 cmp r0, #0x0 */
/* @0x2a3868 bge 0x2a3876 <zip_close+0x68a> */
/* @0x2a386a blx 0xb6bf8 <__errno@plt> */
/* @0x2a386c smlabths r4, r6, r9, lr */
/* @0x2a386e movs r1, #0x4 */
/* @0x2a3870 ldr r2, [r0] */
/* @0x2a3872 mov r0, r6 */
/* @0x2a3874 b 0x2a3890 <zip_close+0x6a4> */
/* @0x2a3876 mov r0, r10 */
/* @0x2a3878 movs r1, #0x8 */
/* @0x2a387a movs r2, #0x1 */
/* @0x2a387c mov r3, r7 */
/* @0x2a387e blx 0xb68bc <fwrite@plt> */
/* @0x2a3880 stmdahs r1, {r1, r2, r3, r4, r11, sp, lr, pc} */
/* @0x2a3882 cmp r0, #0x1 */
/* @0x2a3884 beq 0x2a3828 <zip_close+0x63c> */
/* @0x2a3886 blx 0xb6bf8 <__errno@plt> */
/* @0x2a3888 strhhs lr, [r6, -r8] */
/* @0x2a388a movs r1, #0x6 */
/* @0x2a388c ldr r2, [r0] */
/* @0x2a388e mov r0, r6 */
/* @0x2a3890 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3894 mov.w r8, #0xffffffff */
/* @0x2a3898 rsb.w r8, r8, #0x0 */
/* @0x2a389c b 0x2a38a2 <zip_close+0x6b6> */
/* @0x2a389e mov.w r8, #0x1 */
/* @0x2a38a0 movwhs r0, #0x801 */
/* @0x2a38a2 movs r3, #0x0 */
/* @0x2a38a4 mov r0, r5 */
/* @0x2a38a6 str r3, [r5, #0x4] */
/* @0x2a38a8 bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a38ac cmp.w r8, #0x0 */
/* @0x2a38b0 beq 0x2a38c0 <zip_close+0x6d4> */
/* @0x2a38b2 add r0, sp, #0x54 */
/* @0x2a38b4 bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent> */
/* @0x2a38b8 mov r0, r7 */
/* @0x2a38ba blx 0xb6850 <fclose@plt> */
/* @0x2a38bc and lr, r10, r10, asr #31 */
/* @0x2a38be b 0x2a38d6 <zip_close+0x6ea> */
/* @0x2a38c0 mov r0, r7 */
/* @0x2a38c2 blx 0xb6850 <fclose@plt> */
/* @0x2a38c4 cmnlt r8, r6, asr #31 */
/* @0x2a38c6 cbz r0, 0x2a38e8 <zip_close+0x6fc> */
/* @0x2a38c8 blx 0xb6bf8 <__errno@plt> */
/* @0x2a38cc movs r1, #0x3 */
/* @0x2a38ce ldr r2, [r0] */
/* @0x2a38d0 mov r0, r6 */
/* @0x2a38d2 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a38d4 ldrbmi pc, [r8], -r1, asr #26 */
/* @0x2a38d6 mov r0, r11 */
/* @0x2a38d8 blx 0xb6970 <remove@plt> */
/* @0x2a38dc mov r0, r11 */
/* @0x2a38de blx 0xb655c <free@plt> */
/* @0x2a38e0 .word 0xf04fee3e */
/* @0x2a38e2 mov.w r5, #0xffffffff */
/* @0x2a38e4 .word 0xe02a35ff */
/* @0x2a38e6 b 0x2a393e <zip_close+0x752> */
/* @0x2a38e8 ldr r0, [r4, #0x4] */
/* @0x2a38ea cbz r0, 0x2a38f8 <zip_close+0x70c> */
/* @0x2a38ec blx 0xb6850 <fclose@plt> */
/* @0x2a38f0 movs r7, #0x1 */
/* @0x2a38f2 str.w r8, [r4, #0x4] */
/* @0x2a38f4 and r8, r0, r4 */
/* @0x2a38f6 b 0x2a38fa <zip_close+0x70e> */
/* @0x2a38f8 mov r7, r8 */
/* @0x2a38fa mov r0, r11 */
/* @0x2a38fc ldr r1, [r4] */
/* @0x2a38fe blx 0xb685c <rename@plt> */
/* @0x2a3900 strmi lr, [r5], -lr, lsr #31 */
/* @0x2a3902 mov r5, r0 */
/* @0x2a3904 cbz r0, 0x2a3932 <zip_close+0x746> */
/* @0x2a3906 blx 0xb6bf8 <__errno@plt> */
/* @0x2a3908 .word 0x2102e978 */
/* @0x2a390a movs r1, #0x2 */
/* @0x2a390c ldr r2, [r0] */
/* @0x2a390e mov r0, r6 */
/* @0x2a3910 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3914 mov r0, r11 */
/* @0x2a3916 blx 0xb6970 <remove@plt> */
/* @0x2a3918 ldrbmi lr, [r8], -r12, lsr #16 */
/* @0x2a391a mov r0, r11 */
/* @0x2a391c blx 0xb655c <free@plt> */
/* @0x2a3920 cmp r7, #0x0 */
/* @0x2a3922 beq 0x2a38e2 <zip_close+0x6f6> */
/* @0x2a3924 ldr r1, [pc, #0x70] */
/* @0x2a3926 ldr r0, [r4] */
/* @0x2a3928 add r1, pc */
/* @0x2a392a blx 0xb6844 <fopen@plt> */
/* @0x2a392c rsbvs lr, r0, r12, lsl #31 */
/* @0x2a392e str r0, [r4, #0x4] */
/* @0x2a3930 b 0x2a38e2 <zip_close+0x6f6> */
/* @0x2a3932 mov r0, r4 */
/* @0x2a3934 bl 0x2a4884 <_Z9_zip_freeP3zip> */
/* @0x2a3938 mov r0, r11 */
/* @0x2a393a blx 0xb655c <free@plt> */
/* @0x2a393c stmdbls r12, {r4, r9, r10, r11, sp, lr, pc} */
/* @0x2a393e ldr r1, [sp, #0x30] */
/* @0x2a3940 mov r0, r5 */
/* @0x2a3942 ldr r2, [sp, #0x9c] */
/* @0x2a3944 ldr r3, [r1] */
/* @0x2a3946 cmp r2, r3 */
/* @0x2a3948 beq 0x2a3974 <zip_close+0x788> */
/* @0x2a394a blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a394c stmdbls r6, {r2, r6, r9, r10, r11, sp, lr, pc} */
/* @0x2a394e ldr r1, [sp, #0x18] */
/* @0x2a3950 movs r3, #0x3c */
/* @0x2a3952 muls r3, r1, r3 */
/* @0x2a3954 ldr r1, [r2, #0xc] */
/* @0x2a3956 ldr r2, [r5] */
/* @0x2a3958 add r2, r3 */
/* @0x2a395a str r1, [r2, #0x28] */
/* @0x2a395c ldr r2, [r5] */
/* @0x2a395e add r3, r2 */
/* @0x2a3960 ldr r2, [r4, #0x34] */
/* @0x2a3962 add r2, r8 */
/* @0x2a3964 ldr r2, [r2, #0x10] */
/* @0x2a3966 strh r2, [r3, #0x2c] */
/* @0x2a3968 b 0x2a35ca <zip_close+0x3de> */
/* @0x2a396a mov r0, r5 */
/* @0x2a396c bl 0x2a3bf6 <_Z14_zip_cdir_freeP8zip_cdir> */
/* @0x2a3970 ldr r0, [sp, #0x10] */
/* @0x2a3972 b 0x2a38de <zip_close+0x6f2> */
/* @0x2a3974 add sp, #0xa4 */
/* @0x2a3976 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a3978 svclt #0x8ff0 */
/* @0x2a397a nop */
/* @0x2a397c adr r7, #384 <zip_close+0x7f4> */
/* @0x2a397e movs r4, r2 */
/* @0x2a3980 ldrh r6, [r5, #0x26] */
/* @0x2a3982 movs r6, r1 */
/* @0x2a3984 ldrh r7, [r1, #0x24] */
/* @0x2a3986 movs r6, r1 */
/* @0x2a3988 ldrh r5, [r6, #0x22] */
/* @0x2a398a movs r6, r1 */
/* @0x2a398c .word 0xfb17 ffff */
/* @0x2a3990 ldrh r3, [r0, #0x1e] */
/* @0x2a3992 movs r6, r1 */
/* @0x2a3994 strh r3, [r4, #0x3c] */
/* @0x2a3996 movs r6, r1 */
/* @0x2a3998 strh r3, [r2, #0x36] */
/* @0x2a399a movs r6, r1 */

/* ── FUNC 0x2a399c · anon_2a399c · size=432 · insn=109 */
/* @0x2a399c .word 0x4604b538 */
/* @0x2a39a0 sbclt r4, r0, #13631488 */
/* @0x2a39a4 b 0xfeb611f8 <b2_toiTime+0xfffffffffe407d54> */
/* @0x2a39a8 .word 0xf3c44629 */
/* @0x2a39ac .word 0xf6132007 */
/* @0x2a39b0 qadd8mi lr, r9, lr */
/* @0x2a39b4 andmi pc, r7, r4, asr #7 */
/* @0x2a39b8 b 0xfe8e120c <b2_toiTime+0xfffffffffe187d68> */
/* @0x2a39bc strtmi r0, [r9], -r0, lsr #28 */
/* @0x2a39c0 ldrhtmi lr, [r8], -sp */
/* @0x2a39c4 ldmdalt r2!, {r3, r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a39c8 .word 0x4604b538 */
/* @0x2a39cc sbclt r4, r0, #13631488 */
/* @0x2a39d0 b 0xfe5e1224 <b2_toiTime+0xfffffffffde87d80> */
/* @0x2a39d4 strtmi r0, [r9], -r0, lsr #20 */
/* @0x2a39d8 ldrhtmi lr, [r8], -sp */
/* @0x2a39dc stmdalt r6!, {r3, r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a39e0 mvnsmi lr, sp, lsr #18 */
/* @0x2a39e4 strmi r4, [sp], -r0, lsl #13 */
/* @0x2a39e8 sadd16mi r4, r6, pc */
/* @0x2a39ec mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a39f0 strmi lr, [r8], -r0 */
/* @0x2a39f4 stc p6, c15, [r6, #72]! */
/* @0x2a39f8 stmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a39fc .word 0x210e4638 */
/* @0x2a3a00 .word 0xf0004622 */
/* @0x2a3a04 eor pc, r3, r9, lsr #25 */
/* @0x2a3a08 strtmi r2, [r10], -r1, lsl #2 */
/* @0x2a3a0c .word 0xf6124643 */
/* @0x2a3a10 adcmi lr, r8, #92, #30 */
/* @0x2a3a14 strtmi sp, [r0], -r12, lsl #4 */
/* @0x2a3a18 stc p6, c15, [r0, #72]! */
/* @0x2a3a1c stm r12!, {r0, r1, r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a3a20 stmdavs r2, {r0, r2, r8, sp} */
/* @0x2a3a24 .word 0xf0004638 */
/* @0x2a3a28 mulhs r0, r7, r12 */
/* @0x2a3a2c ldrhhi lr, [r0, #141]! */
/* @0x2a3a30 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^ */
/* @0x2a3a34 eorhs r2, r0, r0, lsl #6 */
/* @0x2a3a38 strtmi r5, [r3], -r3, ror #10 */
/* @0x2a3a3c sadd8mi r4, r9, r3 */
/* @0x2a3a40 stmdavc r9, {r1, r2, r9, r12, lr, pc} */
/* @0x2a3a44 stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x2a3a48 .word 0xf803d1f8 */
/* @0x2a3a4c ldrb r0, [r5, r1, lsl #24]! */
/* @0x2a3a50 pop {r5, r9, r10, lr} */
/* @0x2a3a54 strlt r8, [r0, #-0x1f0] */
/* @0x2a3a58 .word 0xf04fb08d */
/* @0x2a3a5c movwls r3, #0x93ff */
/* @0x2a3a60 movths pc, #0x63c1 */
/* @0x2a3a64 movwls r3, #0x6350 */
/* @0x2a3a68 movtne pc, #0x33c1 */
/* @0x2a3a6c tsteq pc, r1 */
/* @0x2a3a70 movwls r3, #0x5b01 */
/* @0x2a3a74 bichs pc, r4, #192, #6 */
/* @0x2a3a78 .word 0xf3c09303 */
/* @0x2a3a7c subeq r1, r0, r5, asr #6 */
/* @0x2a3a80 .word 0xf0009302 */
/* @0x2a3a84 stmdage r12, {r1, r2, r3, r4, r5, r8, r9} */
/* @0x2a3a88 .word 0xf8409104 */
/* @0x2a3a8c .word 0xf6133d2c */
/* @0x2a3a90 andlt lr, sp, r4, lsr r10 */
/* @0x2a3a94 blx 0x3e1c12 <error_g0017+0x3a8b6> */
/* @0x2a3a98 mvnsmi lr, sp, lsr #18 */
/* @0x2a3a9c strmi r4, [r12], -r6, lsl #12 */
/* @0x2a3aa0 sadd8mi r4, r7, r8 */
/* @0x2a3aa4 mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a3aa8 strmi lr, [r8], -r0 */
/* @0x2a3aac stcl p6, c15, [r10, #-72] */
/* @0x2a3ab0 stmdblt r8!, {r0, r2, r9, r10, lr} */
/* @0x2a3ab4 .word 0x210e4640 */
/* @0x2a3ab8 .word 0xf000462a */
/* @0x2a3abc ands pc, r6, sp, asr #24 */
/* @0x2a3ac0 qasxmi r6, r2, r1 */
/* @0x2a3ac4 ldcl p6, c15, [r10, #-72]! */
/* @0x2a3ac8 strtmi r6, [r3], #-2099 */
/* @0x2a3acc cmnlt r7, r3, lsr r0 */
/* @0x2a3ad0 movwhs r1, #0x92a */
/* @0x2a3ad4 strpl r2, [r11, #-0x20]! */
/* @0x2a3ad8 addsmi r4, r3, #45088768 */
/* @0x2a3adc andle r4, r6, #26214400 */
/* @0x2a3ae0 movwlo r7, #0x1809 */
/* @0x2a3ae4 mvnsle r2, r0, lsl #18 */
/* @0x2a3ae8 .word 0x0c01f803 */
/* @0x2a3aec qsub8mi lr, r8, r5 */
/* @0x2a3af0 ldrhhi lr, [r0, #141]! */
/* @0x2a3af4 mvnsmi lr, sp, lsr #18 */
/* @0x2a3af8 strmi r4, [sp], -r7, lsl #12 */
/* @0x2a3afc sadd8mi r4, r6, r8 */
/* @0x2a3b00 mcrrne p1, #0x0, r11, r8, c10 */
/* @0x2a3b04 strmi lr, [r8], -r0 */
/* @0x2a3b08 ldc p6, c15, [r12, #-72] */
/* @0x2a3b0c stmdblt r8!, {r2, r9, r10, lr} */
/* @0x2a3b10 .word 0x210e4640 */
/* @0x2a3b14 .word 0xf0004622 */
/* @0x2a3b18 ands pc, r5, pc, lsl r12 */
/* @0x2a3b1c qasxmi r4, r1, r8 */
/* @0x2a3b20 strtmi r2, [r11], -r1, lsl #4 */
/* @0x2a3b24 ldm r10!, {r1, r3, r5, r9, r10, r12, sp, lr, pc} */
/* @0x2a3b28 stmdbne r2!, {r1, r2, r4, r5, r6, r8, r12, sp, pc} ^ */
/* @0x2a3b2c eorhs r2, r0, r0, lsl #6 */
/* @0x2a3b30 strtmi r5, [r3], -r3, ror #10 */
/* @0x2a3b34 sadd8mi r4, r9, r3 */
/* @0x2a3b38 stmdavc r9, {r1, r2, r9, r12, lr, pc} */
/* @0x2a3b3c stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x2a3b40 .word 0xf803d1f8 */
/* @0x2a3b44 ldrb r0, [r5, r1, lsl #24]! */
/* @0x2a3b48 pop {r5, r9, r10, lr} */
/* @0x2a3b4c ldrblt r8, [r0, #-0x1f0]! */

/* ── FUNC 0x2a3b4e · _zip_cdir_grow(zip_cdir*, int, zip_error*) · size=58 · insn=26 */
/* @0x2a3b4e push {r4, r5, r6, lr} */
/* @0x2a3b50 mov r4, r0 */
/* @0x2a3b52 ldr r3, [r0, #0x4] */
/* @0x2a3b54 mov r5, r1 */
/* @0x2a3b56 mov r6, r2 */
/* @0x2a3b58 cmp r1, r3 */
/* @0x2a3b5a bge 0x2a3b64 <_Z14_zip_cdir_growP8zip_cdiriP9zip_error+0x16> */
/* @0x2a3b5c mov r0, r2 */
/* @0x2a3b5e movs r1, #0x14 */
/* @0x2a3b60 movs r2, #0x0 */
/* @0x2a3b62 b 0x2a3b76 <_Z14_zip_cdir_growP8zip_cdiriP9zip_error+0x28> */
/* @0x2a3b64 movs r1, #0x3c */
/* @0x2a3b66 ldr r0, [r0] */
/* @0x2a3b68 muls r1, r5, r1 */
/* @0x2a3b6a blx 0xb6c28 <realloc@plt> */
/* @0x2a3b6e mov r2, r0 */
/* @0x2a3b70 cbnz r0, 0x2a3b80 <_Z14_zip_cdir_growP8zip_cdiriP9zip_error+0x32> */
/* @0x2a3b72 mov r0, r6 */
/* @0x2a3b74 movs r1, #0xe */
/* @0x2a3b76 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3b7a mov.w r0, #0xffffffff */
/* @0x2a3b7e pop {r4, r5, r6, pc} */
/* @0x2a3b80 stm.w r4, {r2, r5} */
/* @0x2a3b82 andhs r0, r0, r4, lsr #32 */
/* @0x2a3b84 movs r0, #0x0 */
/* @0x2a3b86 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a3b88 · _zip_cdir_new(int, zip_error*) · size=78 · insn=36 */
/* @0x2a3b88 push {r3, r4, r5, r6, r7, lr} */
/* @0x2a3b8a mov r6, r0 */
/* @0x2a3b8c movs r0, #0x18 */
/* @0x2a3b8e mov r7, r1 */
/* @0x2a3b90 blx 0xb6544 <malloc@plt> */
/* @0x2a3b94 mov r4, r0 */
/* @0x2a3b96 cbnz r0, 0x2a3ba4 <_Z13_zip_cdir_newiP9zip_error+0x1c> */
/* @0x2a3b98 mov r0, r7 */
/* @0x2a3b9a movs r1, #0xe */
/* @0x2a3b9c mov r2, r4 */
/* @0x2a3b9e bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3ba0 ldrsb pc, [r6], -r11 */
/* @0x2a3ba2 b 0x2a3bd2 <_Z13_zip_cdir_newiP9zip_error+0x4a> */
/* @0x2a3ba4 movs r0, #0x3c */
/* @0x2a3ba6 muls r0, r6, r0 */
/* @0x2a3ba8 blx 0xb6544 <malloc@plt> */
/* @0x2a3bac mov r5, r0 */
/* @0x2a3bae str r0, [r4] */
/* @0x2a3bb0 cbnz r0, 0x2a3bc6 <_Z13_zip_cdir_newiP9zip_error+0x3e> */
/* @0x2a3bb2 mov r0, r7 */
/* @0x2a3bb4 movs r1, #0xe */
/* @0x2a3bb6 mov r2, r5 */
/* @0x2a3bb8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3bbc mov r0, r4 */
/* @0x2a3bbe blx 0xb655c <free@plt> */
/* @0x2a3bc0 strtmi lr, [r8], -lr, asr #25 */
/* @0x2a3bc2 mov r0, r5 */
/* @0x2a3bc4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a3bc6 movs r3, #0x0 */
/* @0x2a3bc8 str r6, [r4, #0x4] */
/* @0x2a3bca str r3, [r4, #0xc] */
/* @0x2a3bcc str r3, [r4, #0x8] */
/* @0x2a3bce str r3, [r4, #0x10] */
/* @0x2a3bd0 strh r3, [r4, #0x14] */
/* @0x2a3bd2 mov r0, r4 */
/* @0x2a3bd4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2a3bd6 · _zip_dirent_finalize(zip_dirent*) · size=32 · insn=13 */
/* @0x2a3bd6 push {r3, r4, r5, lr} */
/* @0x2a3bd8 mov r4, r0 */
/* @0x2a3bda ldr r0, [r0, #0x18] */
/* @0x2a3bdc movs r5, #0x0 */
/* @0x2a3bde blx 0xb655c <free@plt> */
/* @0x2a3be2 ldr r0, [r4, #0x20] */
/* @0x2a3be4 str r5, [r4, #0x18] */
/* @0x2a3be6 blx 0xb655c <free@plt> */
/* @0x2a3bea str r5, [r4, #0x20] */
/* @0x2a3bec ldr r0, [r4, #0x28] */
/* @0x2a3bee blx 0xb655c <free@plt> */
/* @0x2a3bf2 str r5, [r4, #0x28] */
/* @0x2a3bf4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a3bf6 · _zip_cdir_free(zip_cdir*) · size=54 · insn=24 */
/* @0x2a3bf6 push {r4, r5, r6, lr} */
/* @0x2a3bf8 mov r4, r0 */
/* @0x2a3bfa cbz r0, 0x2a3c2a <_Z14_zip_cdir_freeP8zip_cdir+0x34> */
/* @0x2a3bfc movs r5, #0x0 */
/* @0x2a3bfe movs r6, #0x3c */
/* @0x2a3c00 ldr r3, [r4, #0x4] */
/* @0x2a3c02 cmp r5, r3 */
/* @0x2a3c04 bge 0x2a3c14 <_Z14_zip_cdir_freeP8zip_cdir+0x1e> */
/* @0x2a3c06 ldr r0, [r4] */
/* @0x2a3c08 mla r0, r6, r5, r0 */
/* @0x2a3c0a .word 0xf7ff0005 */
/* @0x2a3c0c bl 0x2a3bd6 <_Z20_zip_dirent_finalizeP10zip_dirent> */
/* @0x2a3c0e strlo pc, [r1, #-0xfe3] */
/* @0x2a3c10 adds r5, #0x1 */
/* @0x2a3c12 b 0x2a3c00 <_Z14_zip_cdir_freeP8zip_cdir+0xa> */
/* @0x2a3c14 ldr r0, [r4, #0x10] */
/* @0x2a3c16 blx 0xb655c <free@plt> */
/* @0x2a3c1a ldr r0, [r4] */
/* @0x2a3c1c blx 0xb655c <free@plt> */
/* @0x2a3c1e qadd8mi lr, r0, lr */
/* @0x2a3c20 mov r0, r4 */
/* @0x2a3c22 pop.w {r4, r5, r6, lr} */
/* @0x2a3c26 b.w 0x31babc <__udivdi3+0x424> */
/* @0x2a3c2a pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a3c2c · _zip_dirent_init(zip_dirent*) · size=42 · insn=21 */
/* @0x2a3c2c movs r3, #0x0 */
/* @0x2a3c2e movs r2, #0x14 */
/* @0x2a3c30 strh r3, [r0] */
/* @0x2a3c32 strh r2, [r0, #0x2] */
/* @0x2a3c34 strh r3, [r0, #0x4] */
/* @0x2a3c36 strh r3, [r0, #0x6] */
/* @0x2a3c38 str r3, [r0, #0x8] */
/* @0x2a3c3a str r3, [r0, #0xc] */
/* @0x2a3c3c str r3, [r0, #0x10] */
/* @0x2a3c3e str r3, [r0, #0x14] */
/* @0x2a3c40 str r3, [r0, #0x18] */
/* @0x2a3c42 strh r3, [r0, #0x1c] */
/* @0x2a3c44 str r3, [r0, #0x20] */
/* @0x2a3c46 strh r3, [r0, #0x24] */
/* @0x2a3c48 str r3, [r0, #0x28] */
/* @0x2a3c4a strh r3, [r0, #0x2c] */
/* @0x2a3c4c strh r3, [r0, #0x2e] */
/* @0x2a3c4e strh r3, [r0, #0x30] */
/* @0x2a3c50 str r3, [r0, #0x34] */
/* @0x2a3c52 str r3, [r0, #0x38] */
/* @0x2a3c54 bx lr */

/* ── FUNC 0x2a3c58 · _zip_dirent_torrent_normalize(zip_dirent*) · size=136 · insn=65 */
/* @0x2a3c58 push {r0, r1, r4, r5, r6, lr} */
/* @0x2a3c5a mov r4, r0 */
/* @0x2a3c5c ldr r5, [pc, #0x78] */
/* @0x2a3c5e add r5, pc */
/* @0x2a3c60 ldr r3, [r5] */
/* @0x2a3c62 cbnz r3, 0x2a3c9e <_Z29_zip_dirent_torrent_normalizeP10zip_dirent+0x46> */
/* @0x2a3c64 add r6, sp, #0x4 */
/* @0x2a3c66 str r3, [r5, #0x4] */
/* @0x2a3c68 str r3, [r5, #0x1c] */
/* @0x2a3c6a movs r2, #0x20 */
/* @0x2a3c6c mov r0, r6 */
/* @0x2a3c6e str r3, [r5, #0x20] */
/* @0x2a3c70 str r3, [r5, #0x24] */
/* @0x2a3c72 str r2, [r5, #0x8] */
/* @0x2a3c74 movs r2, #0x17 */
/* @0x2a3c76 str r2, [r5, #0xc] */
/* @0x2a3c78 movs r2, #0x18 */
/* @0x2a3c7a str r2, [r5, #0x10] */
/* @0x2a3c7c movs r2, #0xb */
/* @0x2a3c7e str r2, [r5, #0x14] */
/* @0x2a3c80 movs r2, #0x60 */
/* @0x2a3c82 str r2, [r5, #0x18] */
/* @0x2a3c84 blx 0xb67fc <time@plt> */
/* @0x2a3c88 mov r0, r6 */
/* @0x2a3c8a blx 0xb6f04 <localtime@plt> */
/* @0x2a3c8c bvs 0x139e184 <b2_toiTime+0xc44ce0> */
/* @0x2a3c8e ldr r3, [r0, #0x24] */
/* @0x2a3c90 str r3, [r5, #0x28] */
/* @0x2a3c92 ldr r3, [r0, #0x28] */
/* @0x2a3c94 adds r0, r5, #0x4 */
/* @0x2a3c96 str r3, [r5, #0x2c] */
/* @0x2a3c98 blx 0xb6ef8 <mktime@plt> */
/* @0x2a3c9c str r0, [r5] */
/* @0x2a3c9e movs r3, #0x14 */
/* @0x2a3ca0 strh r3, [r4, #0x2] */
/* @0x2a3ca2 movs r3, #0x2 */
/* @0x2a3ca4 strh r3, [r4, #0x4] */
/* @0x2a3ca6 movs r3, #0x8 */
/* @0x2a3ca8 strh r3, [r4, #0x6] */
/* @0x2a3caa ldr r3, [pc, #0x30] */
/* @0x2a3cac movs r5, #0x0 */
/* @0x2a3cae ldr r0, [r4, #0x20] */
/* @0x2a3cb0 add r3, pc */
/* @0x2a3cb2 strh r5, [r4] */
/* @0x2a3cb4 strh r5, [r4, #0x2e] */
/* @0x2a3cb6 ldr r3, [r3] */
/* @0x2a3cb8 strh r5, [r4, #0x30] */
/* @0x2a3cba str r5, [r4, #0x34] */
/* @0x2a3cbc str r3, [r4, #0x8] */
/* @0x2a3cbe str r5, [r4, #0x38] */
/* @0x2a3cc0 blx 0xb655c <free@plt> */
/* @0x2a3cc4 str r5, [r4, #0x20] */
/* @0x2a3cc6 strh r5, [r4, #0x24] */
/* @0x2a3cc8 ldr r0, [r4, #0x28] */
/* @0x2a3cca blx 0xb655c <free@plt> */
/* @0x2a3ccc adcvs lr, r5, #72, #24 */
/* @0x2a3cce str r5, [r4, #0x28] */
/* @0x2a3cd0 strh r5, [r4, #0x2c] */
/* @0x2a3cd2 add sp, #0x8 */
/* @0x2a3cd4 pop {r4, r5, r6, pc} */
/* @0x2a3cd6 nop */
/* @0x2a3cd8 strb r6, [r1, r2] */
/* @0x2a3cda lsls r3, r1, #0x1 */
/* @0x2a3cdc strb r4, [r7, r0] */
/* @0x2a3cde lsls r3, r1, #0x1 */

/* ── FUNC 0x2a3ce0 · _zip_dirent_write(zip_dirent*, __sFILE*, int, zip_error*) · size=304 · insn=133 */
/* @0x2a3ce0 push.w {r0, r1, r4, r5, r6, r7, r8, lr} */
/* @0x2a3ce4 mov r5, r0 */
/* @0x2a3ce6 mov r4, r1 */
/* @0x2a3ce8 mov r7, r3 */
/* @0x2a3cea mov r6, r2 */
/* @0x2a3cec cbz r2, 0x2a3cf4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x14> */
/* @0x2a3cee ldr r0, [pc, #0x118] */
/* @0x2a3cf0 add r0, pc */
/* @0x2a3cf2 b 0x2a3cf8 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x18> */
/* @0x2a3cf4 ldr r0, [pc, #0x114] */
/* @0x2a3cf6 add r0, pc */
/* @0x2a3cf8 movs r1, #0x1 */
/* @0x2a3cfa movs r2, #0x4 */
/* @0x2a3cfc mov r3, r4 */
/* @0x2a3cfe blx 0xb68bc <fwrite@plt> */
/* @0x2a3d00 ldmdblt lr, {r1, r2, r3, r4, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x2a3d02 cbnz r6, 0x2a3d0c <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x2c> */
/* @0x2a3d04 ldrh r0, [r5] */
/* @0x2a3d06 mov r1, r4 */
/* @0x2a3d08 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d0c ldrh r0, [r5, #0x2] */
/* @0x2a3d0e mov r1, r4 */
/* @0x2a3d10 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d14 ldrh r0, [r5, #0x4] */
/* @0x2a3d16 mov r1, r4 */
/* @0x2a3d18 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d1c mov r1, r4 */
/* @0x2a3d1e ldrh r0, [r5, #0x6] */
/* @0x2a3d20 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d24 ldr r3, [r5, #0x8] */
/* @0x2a3d26 add r0, sp, #0x8 */
/* @0x2a3d28 str r3, [r0, #-4]! */
/* @0x2a3d2c blx 0xb6f04 <localtime@plt> */
/* @0x2a3d30 mov r1, r4 */
/* @0x2a3d32 ldr r2, [r0, #0x10] */
/* @0x2a3d34 ldr r3, [r0, #0x14] */
/* @0x2a3d36 adds r2, #0x1 */
/* @0x2a3d38 subs r3, #0x50 */
/* @0x2a3d3a lsls r2, r2, #0x5 */
/* @0x2a3d3c add.w r8, r2, r3, lsl #9 */
/* @0x2a3d40 ldr r3, [r0, #0xc] */
/* @0x2a3d42 ldr r2, [r0, #0x8] */
/* @0x2a3d44 add r3, r8 */
/* @0x2a3d46 uxth.w r8, r3 */
/* @0x2a3d48 stmdavs r3, {r0, r1, r7, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d4a ldr r3, [r0, #0x4] */
/* @0x2a3d4c ldr r0, [r0] */
/* @0x2a3d4e lsls r2, r2, #0xb */
/* @0x2a3d50 add.w r3, r2, r3, lsl #5 */
/* @0x2a3d54 add.w r0, r3, r0, asr #1 */
/* @0x2a3d58 uxth r0, r0 */
/* @0x2a3d5a bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d5c .word 0x4640fe35 */
/* @0x2a3d5e mov r0, r8 */
/* @0x2a3d60 mov r1, r4 */
/* @0x2a3d62 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d64 stmvs r8!, {r0, r4, r5, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d66 ldr r0, [r5, #0xc] */
/* @0x2a3d68 mov r1, r4 */
/* @0x2a3d6a bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3d6c stmdbvs r8!, {r0, r1, r2, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3d6e ldr r0, [r5, #0x10] */
/* @0x2a3d70 mov r1, r4 */
/* @0x2a3d72 bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3d74 stmdbvs r8!, {r0, r1, r4, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2a3d76 ldr r0, [r5, #0x14] */
/* @0x2a3d78 mov r1, r4 */
/* @0x2a3d7a bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3d7c blhi 0xfece35c0 <b2_toiTime+0xfffffffffe58a11c> */
/* @0x2a3d7e ldrh r0, [r5, #0x1c] */
/* @0x2a3d80 mov r1, r4 */
/* @0x2a3d82 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d84 stchi p14, c15, [r8], #132 */
/* @0x2a3d86 ldrh r0, [r5, #0x24] */
/* @0x2a3d88 mov r1, r4 */
/* @0x2a3d8a bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d8c ldmiblt lr, {r0, r2, r3, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3d8e cbnz r6, 0x2a3db8 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0xd8> */
/* @0x2a3d90 ldrh r0, [r5, #0x2c] */
/* @0x2a3d92 mov r1, r4 */
/* @0x2a3d94 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3d98 ldrh r0, [r5, #0x2e] */
/* @0x2a3d9a mov r1, r4 */
/* @0x2a3d9c bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3da0 ldrh r0, [r5, #0x30] */
/* @0x2a3da2 mov r1, r4 */
/* @0x2a3da4 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3da8 ldr r0, [r5, #0x34] */
/* @0x2a3daa mov r1, r4 */
/* @0x2a3dac bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3db0 ldr r0, [r5, #0x38] */
/* @0x2a3db2 mov r1, r4 */
/* @0x2a3db4 bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3db8 ldrh r2, [r5, #0x1c] */
/* @0x2a3dba cbz r2, 0x2a3dc6 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0xe6> */
/* @0x2a3dbc ldr r0, [r5, #0x18] */
/* @0x2a3dbe movs r1, #0x1 */
/* @0x2a3dc0 mov r3, r4 */
/* @0x2a3dc2 blx 0xb68bc <fwrite@plt> */
/* @0x2a3dc4 stchi p13, c14, [r10], #496 */
/* @0x2a3dc6 ldrh r2, [r5, #0x24] */
/* @0x2a3dc8 cbz r2, 0x2a3dd4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0xf4> */
/* @0x2a3dca ldr r0, [r5, #0x20] */
/* @0x2a3dcc movs r1, #0x1 */
/* @0x2a3dce mov r3, r4 */
/* @0x2a3dd0 blx 0xb68bc <fwrite@plt> */
/* @0x2a3dd4 cbnz r6, 0x2a3de4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x104> */
/* @0x2a3dd6 ldrh r2, [r5, #0x2c] */
/* @0x2a3dd8 cbz r2, 0x2a3de4 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x104> */
/* @0x2a3dda ldr r0, [r5, #0x28] */
/* @0x2a3ddc movs r1, #0x1 */
/* @0x2a3dde mov r3, r4 */
/* @0x2a3de0 blx 0xb68bc <fwrite@plt> */
/* @0x2a3de4 ldrh r0, [r4, #0xc] */
/* @0x2a3de6 and r0, r0, #0x40 */
/* @0x2a3de8 addlt r0, r0, #64 */
/* @0x2a3dea uxth r0, r0 */
/* @0x2a3dec cbz r0, 0x2a3e00 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error+0x120> */
/* @0x2a3dee blx 0xb6bf8 <__errno@plt> */
/* @0x2a3df0 .word 0x2106ef04 */
/* @0x2a3df2 movs r1, #0x6 */
/* @0x2a3df4 ldr r2, [r0] */
/* @0x2a3df6 mov r0, r7 */
/* @0x2a3df8 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3dfc mov.w r0, #0xffffffff */
/* @0x2a3e00 add sp, #0x8 */
/* @0x2a3e02 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a3e04 svclt #0x81f0 */
/* @0x2a3e06 nop */
/* @0x2a3e08 strh r6, [r1, #0x18] */
/* @0x2a3e0a movs r6, r1 */
/* @0x2a3e0c strh r5, [r1, #0x18] */
/* @0x2a3e0e movs r6, r1 */

/* ── FUNC 0x2a3e10 · _zip_cdir_write(zip_cdir*, __sFILE*, zip_error*) · size=176 · insn=74 */
/* @0x2a3e10 push.w {r4, r5, r6, r7, r8, lr} */
/* @0x2a3e14 mov r5, r0 */
/* @0x2a3e16 mov r0, r1 */
/* @0x2a3e18 mov r4, r1 */
/* @0x2a3e1a mov r7, r2 */
/* @0x2a3e1c blx 0xb6ee0 <ftello@plt> */
/* @0x2a3e20 movs r6, #0x0 */
/* @0x2a3e22 mov.w r8, #0x3c */
/* @0x2a3e24 rscvs r0, r8, r12, lsr r8 */
/* @0x2a3e26 str r0, [r5, #0xc] */
/* @0x2a3e28 ldr r3, [r5, #0x4] */
/* @0x2a3e2a cmp r6, r3 */
/* @0x2a3e2c bge 0x2a3e46 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0x36> */
/* @0x2a3e2e ldr r0, [r5] */
/* @0x2a3e30 mov r1, r4 */
/* @0x2a3e32 movs r2, #0x0 */
/* @0x2a3e34 mov r3, r7 */
/* @0x2a3e36 mla r0, r8, r6, r0 */
/* @0x2a3e38 .word 0xf7ff0006 */
/* @0x2a3e3a bl 0x2a3ce0 <_Z17_zip_dirent_writeP10zip_direntP7__sFILEiP9zip_error> */
/* @0x2a3e3c stmdahs r0, {r0, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3e3e cmp r0, #0x0 */
/* @0x2a3e40 bne 0x2a3eb4 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0xa4> */
/* @0x2a3e42 adds r6, #0x1 */
/* @0x2a3e44 b 0x2a3e28 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0x18> */
/* @0x2a3e46 mov r0, r4 */
/* @0x2a3e48 blx 0xb6ee0 <ftello@plt> */
/* @0x2a3e4c ldr r3, [r5, #0xc] */
/* @0x2a3e4e movs r2, #0x4 */
/* @0x2a3e50 movs r1, #0x1 */
/* @0x2a3e52 subs r0, r0, r3 */
/* @0x2a3e54 str r0, [r5, #0x8] */
/* @0x2a3e56 ldr r0, [pc, #0x64] */
/* @0x2a3e58 mov r3, r4 */
/* @0x2a3e5a add r0, pc */
/* @0x2a3e5c blx 0xb68bc <fwrite@plt> */
/* @0x2a3e60 movs r0, #0x0 */
/* @0x2a3e62 mov r1, r4 */
/* @0x2a3e64 bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3e68 ldrh r0, [r5, #0x4] */
/* @0x2a3e6a mov r1, r4 */
/* @0x2a3e6c bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3e70 ldrh r0, [r5, #0x4] */
/* @0x2a3e72 mov r1, r4 */
/* @0x2a3e74 bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3e78 ldr r0, [r5, #0x8] */
/* @0x2a3e7a mov r1, r4 */
/* @0x2a3e7c bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3e80 ldr r0, [r5, #0xc] */
/* @0x2a3e82 mov r1, r4 */
/* @0x2a3e84 bl 0x2a399c <zip_close+0x7b0> */
/* @0x2a3e88 ldrh r0, [r5, #0x14] */
/* @0x2a3e8a mov r1, r4 */
/* @0x2a3e8c bl 0x2a39c8 <zip_close+0x7dc> */
/* @0x2a3e90 ldr r0, [r5, #0x10] */
/* @0x2a3e92 movs r1, #0x1 */
/* @0x2a3e94 ldrh r2, [r5, #0x14] */
/* @0x2a3e96 mov r3, r4 */
/* @0x2a3e98 blx 0xb68bc <fwrite@plt> */
/* @0x2a3e9c ldrh r0, [r4, #0xc] */
/* @0x2a3e9e and r0, r0, #0x40 */
/* @0x2a3ea0 addlt r0, r0, #64 */
/* @0x2a3ea2 uxth r0, r0 */
/* @0x2a3ea4 cbz r0, 0x2a3eb8 <_Z15_zip_cdir_writeP8zip_cdirP7__sFILEP9zip_error+0xa8> */
/* @0x2a3ea6 blx 0xb6bf8 <__errno@plt> */
/* @0x2a3ea8 smlatbhs r6, r8, lr, lr */
/* @0x2a3eaa movs r1, #0x6 */
/* @0x2a3eac ldr r2, [r0] */
/* @0x2a3eae mov r0, r7 */
/* @0x2a3eb0 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3eb4 mov.w r0, #0xffffffff */
/* @0x2a3eb8 pop.w {r4, r5, r6, r7, r8, pc} */
/* @0x2a3ebc strh r6, [r5, #0xc] */
/* @0x2a3ebe movs r6, r1 */

/* ── FUNC 0x2a3ec0 · _zip_read2(unsigned char**) · size=18 · insn=7 */
/* @0x2a3ec0 ldr r3, [r0] */
/* @0x2a3ec2 ldrb r1, [r3, #0x1] */
/* @0x2a3ec4 ldrb r2, [r3], #2 */
/* @0x2a3ec8 add.w r2, r2, r1, lsl #8 */
/* @0x2a3ecc str r3, [r0] */
/* @0x2a3ece uxth r0, r2 */
/* @0x2a3ed0 bx lr */

/* ── FUNC 0x2a3ed2 · _zip_read4(unsigned char**) · size=28 · insn=12 */
/* @0x2a3ed2 ldr r3, [r0] */
/* @0x2a3ed4 ldrb r1, [r3, #0x3] */
/* @0x2a3ed6 ldrb r2, [r3, #0x2] */
/* @0x2a3ed8 add.w r1, r2, r1, lsl #8 */
/* @0x2a3eda ldmdavc r10, {r0, r8, sp} ^ */
/* @0x2a3edc ldrb r2, [r3, #0x1] */
/* @0x2a3ede add.w r1, r2, r1, lsl #8 */
/* @0x2a3ee2 ldrb r2, [r3], #4 */
/* @0x2a3ee6 str r3, [r0] */
/* @0x2a3ee8 add.w r0, r2, r1, lsl #8 */
/* @0x2a3eea ldrbmi r2, [r0, -r1]! */
/* @0x2a3eec bx lr */

/* ── FUNC 0x2a3eee · anon_2a3eee · size=0 · insn=1 */
/* @0x2a3eee .word 0xe92d0000 */

/* ── FUNC 0x2a3ef0 · _zip_dirent_read(zip_dirent*, __sFILE*, unsigned char**, unsigned int*, int, zip_error*) · size=536 · insn=251 */
/* @0x2a3ef0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a3ef4 mov r9, r2 */
/* @0x2a3ef6 ldr r2, [pc, #0x204] */
/* @0x2a3ef8 mov r10, r1 */
/* @0x2a3efa sub sp, #0x44 */
/* @0x2a3efc mov r4, r0 */
/* @0x2a3efe add r2, pc */
/* @0x2a3f00 ldr r2, [r2] */
/* @0x2a3f02 mov r7, r3 */
/* @0x2a3f04 ldr r6, [sp, #0x6c] */
/* @0x2a3f06 ldr r1, [r2] */
/* @0x2a3f08 str r2, [sp, #0x4] */
/* @0x2a3f0a str r1, [sp, #0x3c] */
/* @0x2a3f0c ldr r1, [sp, #0x68] */
/* @0x2a3f0e cmp r1, #0x0 */
/* @0x2a3f10 ite eq */
/* @0x2a3f12 moveq.w r11, #0x2e */
/* @0x2a3f14 .word 0xf04f0b2e */
/* @0x2a3f16 movne.w r11, #0x1e */
/* @0x2a3f18 teqlt r3, lr, lsl r11 */
/* @0x2a3f1a cbz r3, 0x2a3f2a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x3a> */
/* @0x2a3f1c ldr r3, [r3] */
/* @0x2a3f1e cmp r3, r11 */
/* @0x2a3f20 bhs 0x2a3f2a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x3a> */
/* @0x2a3f22 mov r0, r6 */
/* @0x2a3f24 movs r1, #0x13 */
/* @0x2a3f26 movs r2, #0x0 */
/* @0x2a3f28 b 0x2a3f58 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x68> */
/* @0x2a3f2a cmp.w r9, #0x0 */
/* @0x2a3f2c andle r0, r3, r0, lsl #30 */
/* @0x2a3f2e beq 0x2a3f38 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x48> */
/* @0x2a3f30 ldr.w r3, [r9] */
/* @0x2a3f34 str r3, [sp, #0x8] */
/* @0x2a3f36 b 0x2a3f5e <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x6e> */
/* @0x2a3f38 add r5, sp, #0xc */
/* @0x2a3f3a movs r1, #0x1 */
/* @0x2a3f3c mov r2, r11 */
/* @0x2a3f3e mov r3, r10 */
/* @0x2a3f40 mov r0, r5 */
/* @0x2a3f42 blx 0xb68c8 <fread@plt> */
/* @0x2a3f44 ldrbmi lr, [r8, #-0xcc2] */
/* @0x2a3f46 cmp r0, r11 */
/* @0x2a3f48 it hs */
/* @0x2a3f4a strhs r5, [sp, #0x8] */
/* @0x2a3f4c bhs 0x2a3f5e <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x6e> */
/* @0x2a3f4e blx 0xb6bf8 <__errno@plt> */
/* @0x2a3f50 qaddhs lr, r4, r5 */
/* @0x2a3f52 movs r1, #0x5 */
/* @0x2a3f54 ldr r2, [r0] */
/* @0x2a3f56 mov r0, r6 */
/* @0x2a3f58 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a3f5c b 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a3f5e ldr r2, [sp, #0x68] */
/* @0x2a3f60 ldr r5, [sp, #0x8] */
/* @0x2a3f62 cbz r2, 0x2a3f6a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x7a> */
/* @0x2a3f64 ldr r1, [pc, #0x198] */
/* @0x2a3f66 add r1, pc */
/* @0x2a3f68 b 0x2a3f6e <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x7e> */
/* @0x2a3f6a ldr r1, [pc, #0x198] */
/* @0x2a3f6c add r1, pc */
/* @0x2a3f6e mov r0, r5 */
/* @0x2a3f70 movs r2, #0x4 */
/* @0x2a3f72 blx 0xb6c40 <memcmp@plt> */
/* @0x2a3f74 strmi lr, [r0], r6, ror #28 */
/* @0x2a3f76 mov r8, r0 */
/* @0x2a3f78 cmp r0, #0x0 */
/* @0x2a3f7a bne 0x2a3f22 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x32> */
/* @0x2a3f7c adds r3, r5, #0x4 */
/* @0x2a3f7e add r5, sp, #0x40 */
/* @0x2a3f80 str r3, [r5, #-56]! */
/* @0x2a3f84 ldr r3, [sp, #0x68] */
/* @0x2a3f86 cbnz r3, 0x2a3f92 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0xa2> */
/* @0x2a3f88 mov r0, r5 */
/* @0x2a3f8a bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3f8c mlahi r0, r9, pc, pc */
/* @0x2a3f8e strh r0, [r4] */
/* @0x2a3f90 b 0x2a3f94 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0xa4> */
/* @0x2a3f92 strh r0, [r4] */
/* @0x2a3f94 mov r0, r5 */
/* @0x2a3f96 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3f98 mlshi r0, r3, pc, pc */
/* @0x2a3f9a strh r0, [r4, #0x2] */
/* @0x2a3f9c mov r0, r5 */
/* @0x2a3f9e bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fa0 adchi pc, r0, pc, lsl #31 */
/* @0x2a3fa2 strh r0, [r4, #0x4] */
/* @0x2a3fa4 mov r0, r5 */
/* @0x2a3fa6 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fa8 rschi pc, r0, r11, lsl #31 */
/* @0x2a3faa strh r0, [r4, #0x6] */
/* @0x2a3fac mov r0, r5 */
/* @0x2a3fae bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fb0 strmi pc, [r3], -r7, lsl #31 */
/* @0x2a3fb2 mov r3, r0 */
/* @0x2a3fb4 mov r0, r5 */
/* @0x2a3fb6 str r3, [sp] */
/* @0x2a3fb8 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fbc ldr r3, [sp] */
/* @0x2a3fbe mov r1, r0 */
/* @0x2a3fc0 mov r0, r3 */
/* @0x2a3fc2 bl 0x2a3a56 <zip_close+0x86a> */
/* @0x2a3fc4 adcvs pc, r0, r8, asr #26 */
/* @0x2a3fc6 str r0, [r4, #0x8] */
/* @0x2a3fc8 mov r0, r5 */
/* @0x2a3fca bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a3fcc rscvs pc, r0, r2, lsl #31 */
/* @0x2a3fce str r0, [r4, #0xc] */
/* @0x2a3fd0 mov r0, r5 */
/* @0x2a3fd2 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a3fd4 .word 0x6120ff7e */
/* @0x2a3fd6 str r0, [r4, #0x10] */
/* @0x2a3fd8 mov r0, r5 */
/* @0x2a3fda bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a3fdc .word 0x6160ff7a */
/* @0x2a3fde str r0, [r4, #0x14] */
/* @0x2a3fe0 mov r0, r5 */
/* @0x2a3fe2 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fe4 movhi pc, #436 */
/* @0x2a3fe6 strh r0, [r4, #0x1c] */
/* @0x2a3fe8 mov r0, r5 */
/* @0x2a3fea bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a3fec ldmdbls r10, {r0, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2a3fee ldr r1, [sp, #0x68] */
/* @0x2a3ff0 strh r0, [r4, #0x24] */
/* @0x2a3ff2 cbz r1, 0x2a4002 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x112> */
/* @0x2a3ff4 movs r3, #0x0 */
/* @0x2a3ff6 strh r3, [r4, #0x2c] */
/* @0x2a3ff8 strh r3, [r4, #0x2e] */
/* @0x2a3ffa strh r3, [r4, #0x30] */
/* @0x2a3ffc str r3, [r4, #0x34] */
/* @0x2a3ffe str r3, [r4, #0x38] */
/* @0x2a4000 b 0x2a402a <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x13a> */
/* @0x2a4002 mov r0, r5 */
/* @0x2a4004 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4008 strh r0, [r4, #0x2c] */
/* @0x2a400a mov r0, r5 */
/* @0x2a400c bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4010 strh r0, [r4, #0x2e] */
/* @0x2a4012 mov r0, r5 */
/* @0x2a4014 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4018 strh r0, [r4, #0x30] */
/* @0x2a401a mov r0, r5 */
/* @0x2a401c bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a4020 str r0, [r4, #0x34] */
/* @0x2a4022 mov r0, r5 */
/* @0x2a4024 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a4028 str r0, [r4, #0x38] */
/* @0x2a402a movs r3, #0x0 */
/* @0x2a402c ldrh r1, [r4, #0x1c] */
/* @0x2a402e str r3, [r4, #0x18] */
/* @0x2a4030 str r3, [r4, #0x20] */
/* @0x2a4032 str r3, [r4, #0x28] */
/* @0x2a4034 ldrh r3, [r4, #0x24] */
/* @0x2a4036 ldrh r2, [r4, #0x2c] */
/* @0x2a4038 add r3, r1 */
/* @0x2a403a add r3, r2 */
/* @0x2a403c add r11, r3 */
/* @0x2a403e cbz r7, 0x2a4048 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x158> */
/* @0x2a4040 ldr r3, [r7] */
/* @0x2a4042 cmp r3, r11 */
/* @0x2a4044 blo.w 0x2a3f22 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x32> */
/* @0x2a4048 cmp.w r9, #0x0 */
/* @0x2a404c beq 0x2a4094 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1a4> */
/* @0x2a404e cbnz r1, 0x2a4056 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x166> */
/* @0x2a4050 ldrh r1, [r4, #0x24] */
/* @0x2a4052 cbz r1, 0x2a407c <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x18c> */
/* @0x2a4054 b 0x2a406c <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x17c> */
/* @0x2a4056 mov r0, r5 */
/* @0x2a4058 movs r2, #0x1 */
/* @0x2a405a mov r3, r6 */
/* @0x2a405c bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a4060 str r0, [r4, #0x18] */
/* @0x2a4062 cmp r0, #0x0 */
/* @0x2a4064 bne 0x2a4050 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x160> */
/* @0x2a4066 mov.w r8, #0xffffffff */
/* @0x2a4068 ldrsht r3, [r7], -pc */
/* @0x2a406a b 0x2a40dc <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ec> */
/* @0x2a406c mov r0, r5 */
/* @0x2a406e movs r2, #0x0 */
/* @0x2a4070 mov r3, r6 */
/* @0x2a4072 bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a4074 eorvs pc, r0, #1088 */
/* @0x2a4076 str r0, [r4, #0x20] */
/* @0x2a4078 cmp r0, #0x0 */
/* @0x2a407a beq 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a407c ldrh r1, [r4, #0x2c] */
/* @0x2a407e cmp r1, #0x0 */
/* @0x2a4080 beq 0x2a40ec <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1fc> */
/* @0x2a4082 mov r0, r5 */
/* @0x2a4084 movs r2, #0x0 */
/* @0x2a4086 mov r3, r6 */
/* @0x2a4088 bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a408c str r0, [r4, #0x28] */
/* @0x2a408e cmp r0, #0x0 */
/* @0x2a4090 bne 0x2a40ec <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1fc> */
/* @0x2a4092 b 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a4094 cbnz r1, 0x2a409c <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ac> */
/* @0x2a4096 ldrh r1, [r4, #0x24] */
/* @0x2a4098 cbz r1, 0x2a40be <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ce> */
/* @0x2a409a b 0x2a40ae <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1be> */
/* @0x2a409c mov r0, r10 */
/* @0x2a409e movs r2, #0x1 */
/* @0x2a40a0 mov r3, r6 */
/* @0x2a40a2 bl 0x2a39e0 <zip_close+0x7f4> */
/* @0x2a40a4 .word 0x61a0fc9d */
/* @0x2a40a6 str r0, [r4, #0x18] */
/* @0x2a40a8 cmp r0, #0x0 */
/* @0x2a40aa bne 0x2a4096 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1a6> */
/* @0x2a40ac b 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a40ae mov r0, r10 */
/* @0x2a40b0 movs r2, #0x0 */
/* @0x2a40b2 mov r3, r6 */
/* @0x2a40b4 bl 0x2a39e0 <zip_close+0x7f4> */
/* @0x2a40b8 str r0, [r4, #0x20] */
/* @0x2a40ba cmp r0, #0x0 */
/* @0x2a40bc beq 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a40be ldrh r1, [r4, #0x2c] */
/* @0x2a40c0 cbz r1, 0x2a40d2 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1e2> */
/* @0x2a40c2 mov r0, r10 */
/* @0x2a40c4 movs r2, #0x0 */
/* @0x2a40c6 mov r3, r6 */
/* @0x2a40c8 bl 0x2a39e0 <zip_close+0x7f4> */
/* @0x2a40cc str r0, [r4, #0x28] */
/* @0x2a40ce cmp r0, #0x0 */
/* @0x2a40d0 beq 0x2a4066 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x176> */
/* @0x2a40d2 cbz r7, 0x2a40dc <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1ec> */
/* @0x2a40d4 ldr r3, [r7] */
/* @0x2a40d6 rsb r3, r11, r3 */
/* @0x2a40d8 eorsvs r0, r11, r3, lsl #6 */
/* @0x2a40da str r3, [r7] */
/* @0x2a40dc ldr r1, [sp, #0x4] */
/* @0x2a40de mov r0, r8 */
/* @0x2a40e0 ldr r2, [sp, #0x3c] */
/* @0x2a40e2 ldr r3, [r1] */
/* @0x2a40e4 cmp r2, r3 */
/* @0x2a40e6 beq 0x2a40f4 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x204> */
/* @0x2a40e8 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a40ec ldr r3, [sp, #0x8] */
/* @0x2a40ee str.w r3, [r9] */
/* @0x2a40f0 strb r3, [lr, r0]! */
/* @0x2a40f2 b 0x2a40d2 <_Z16_zip_dirent_readP10zip_direntP7__sFILEPPhPjiP9zip_error+0x1e2> */
/* @0x2a40f4 add sp, #0x44 */
/* @0x2a40f6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a40f8 svclt #0x8ff0 */
/* @0x2a40fa nop */
/* @0x2a40fc ldr r2, [sp, #0x158] */
/* @0x2a40fe movs r4, r2 */
/* @0x2a4100 strh r0, [r3, #0x4] */
/* @0x2a4102 movs r6, r1 */
/* @0x2a4104 strh r7, [r2, #0x4] */
/* @0x2a4106 movs r6, r1 */

/* ── FUNC 0x2a4108 · _zip_dirent_read_buff(zip_dirent*, IBuffer*, unsigned char**, unsigned int*, int, zip_error*) · size=516 · insn=237 */
/* @0x2a4108 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a410c mov r9, r2 */
/* @0x2a410e ldr r2, [pc, #0x1f0] */
/* @0x2a4110 mov r10, r1 */
/* @0x2a4112 sub sp, #0x44 */
/* @0x2a4114 mov r4, r0 */
/* @0x2a4116 add r2, pc */
/* @0x2a4118 ldr r2, [r2] */
/* @0x2a411a mov r6, r3 */
/* @0x2a411c ldr r7, [sp, #0x6c] */
/* @0x2a411e ldr r1, [r2] */
/* @0x2a4120 str r2, [sp, #0x4] */
/* @0x2a4122 str r1, [sp, #0x3c] */
/* @0x2a4124 ldr r1, [sp, #0x68] */
/* @0x2a4126 cmp r1, #0x0 */
/* @0x2a4128 ite eq */
/* @0x2a412a moveq.w r11, #0x2e */
/* @0x2a412c .word 0xf04f0b2e */
/* @0x2a412e movne.w r11, #0x1e */
/* @0x2a4130 .word 0xb1430b1e */
/* @0x2a4132 cbz r3, 0x2a4146 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x3e> */
/* @0x2a4134 ldr r3, [r3] */
/* @0x2a4136 cmp r3, r11 */
/* @0x2a4138 bhs 0x2a4146 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x3e> */
/* @0x2a413a mov r0, r7 */
/* @0x2a413c movs r1, #0x13 */
/* @0x2a413e movs r2, #0x0 */
/* @0x2a4140 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4144 b 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a4146 cmp.w r9, #0x0 */
/* @0x2a4148 andle r0, r3, r0, lsl #30 */
/* @0x2a414a beq 0x2a4154 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x4c> */
/* @0x2a414c ldr.w r3, [r9] */
/* @0x2a4150 str r3, [sp, #0x8] */
/* @0x2a4152 b 0x2a4164 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x5c> */
/* @0x2a4154 add r5, sp, #0xc */
/* @0x2a4156 mov r0, r10 */
/* @0x2a4158 movs r2, #0x1 */
/* @0x2a415a mov r3, r11 */
/* @0x2a415c mov r1, r5 */
/* @0x2a415e blx 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */
/* @0x2a4160 strls lr, [r2, #-0xd9e] */
/* @0x2a4162 str r5, [sp, #0x8] */
/* @0x2a4164 ldr r2, [sp, #0x68] */
/* @0x2a4166 ldr r5, [sp, #0x8] */
/* @0x2a4168 cbz r2, 0x2a4170 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x68> */
/* @0x2a416a ldr r1, [pc, #0x198] */
/* @0x2a416c add r1, pc */
/* @0x2a416e b 0x2a4174 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x6c> */
/* @0x2a4170 ldr r1, [pc, #0x194] */
/* @0x2a4172 add r1, pc */
/* @0x2a4174 mov r0, r5 */
/* @0x2a4176 movs r2, #0x4 */
/* @0x2a4178 blx 0xb6c40 <memcmp@plt> */
/* @0x2a417c mov r8, r0 */
/* @0x2a417e cmp r0, #0x0 */
/* @0x2a4180 bne 0x2a413a <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x32> */
/* @0x2a4182 adds r3, r5, #0x4 */
/* @0x2a4184 add r5, sp, #0x40 */
/* @0x2a4186 str r3, [r5, #-56]! */
/* @0x2a4188 blls 0x933670 <b2_toiTime+0x1da1cc> */
/* @0x2a418a ldr r3, [sp, #0x68] */
/* @0x2a418c cbnz r3, 0x2a4198 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x90> */
/* @0x2a418e mov r0, r5 */
/* @0x2a4190 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4194 strh r0, [r4] */
/* @0x2a4196 b 0x2a419a <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x92> */
/* @0x2a4198 strh r0, [r4] */
/* @0x2a419a mov r0, r5 */
/* @0x2a419c bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41a0 strh r0, [r4, #0x2] */
/* @0x2a41a2 mov r0, r5 */
/* @0x2a41a4 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41a8 strh r0, [r4, #0x4] */
/* @0x2a41aa mov r0, r5 */
/* @0x2a41ac bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41b0 strh r0, [r4, #0x6] */
/* @0x2a41b2 mov r0, r5 */
/* @0x2a41b4 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41b8 mov r3, r0 */
/* @0x2a41ba mov r0, r5 */
/* @0x2a41bc str r3, [sp] */
/* @0x2a41be bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41c0 blls 0x2e3bc4 <_ZN11b2GearJoint4DumpEv+0xb8> */
/* @0x2a41c2 ldr r3, [sp] */
/* @0x2a41c4 mov r1, r0 */
/* @0x2a41c6 mov r0, r3 */
/* @0x2a41c8 bl 0x2a3a56 <zip_close+0x86a> */
/* @0x2a41cc str r0, [r4, #0x8] */
/* @0x2a41ce mov r0, r5 */
/* @0x2a41d0 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a41d4 str r0, [r4, #0xc] */
/* @0x2a41d6 mov r0, r5 */
/* @0x2a41d8 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a41dc str r0, [r4, #0x10] */
/* @0x2a41de mov r0, r5 */
/* @0x2a41e0 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a41e4 str r0, [r4, #0x14] */
/* @0x2a41e6 mov r0, r5 */
/* @0x2a41e8 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41ec strh r0, [r4, #0x1c] */
/* @0x2a41ee mov r0, r5 */
/* @0x2a41f0 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a41f4 ldr r1, [sp, #0x68] */
/* @0x2a41f6 strh r0, [r4, #0x24] */
/* @0x2a41f8 cbz r1, 0x2a4208 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x100> */
/* @0x2a41fa movs r3, #0x0 */
/* @0x2a41fc strh r3, [r4, #0x2c] */
/* @0x2a41fe strh r3, [r4, #0x2e] */
/* @0x2a4200 strh r3, [r4, #0x30] */
/* @0x2a4202 str r3, [r4, #0x34] */
/* @0x2a4204 str r3, [r4, #0x38] */
/* @0x2a4206 b 0x2a4230 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x128> */
/* @0x2a4208 mov r0, r5 */
/* @0x2a420a bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a420c strhi pc, [r0, #0xe59]! */
/* @0x2a420e strh r0, [r4, #0x2c] */
/* @0x2a4210 mov r0, r5 */
/* @0x2a4212 bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a4214 strbhi pc, [r0, #0xe55]! */
/* @0x2a4216 strh r0, [r4, #0x2e] */
/* @0x2a4218 mov r0, r5 */
/* @0x2a421a bl 0x2a3ec0 <_Z10_zip_read2PPh> */
/* @0x2a421c qsaxhi pc, r0, r1 */
/* @0x2a421e strh r0, [r4, #0x30] */
/* @0x2a4220 mov r0, r5 */
/* @0x2a4222 bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a4224 msrvs SPSR, #1376 */
/* @0x2a4226 str r0, [r4, #0x34] */
/* @0x2a4228 mov r0, r5 */
/* @0x2a422a bl 0x2a3ed2 <_Z10_zip_read4PPh> */
/* @0x2a422c movvs pc, #1312 */
/* @0x2a422e str r0, [r4, #0x38] */
/* @0x2a4230 movs r3, #0x0 */
/* @0x2a4232 ldrh r1, [r4, #0x1c] */
/* @0x2a4234 str r3, [r4, #0x18] */
/* @0x2a4236 str r3, [r4, #0x20] */
/* @0x2a4238 str r3, [r4, #0x28] */
/* @0x2a423a ldrh r3, [r4, #0x24] */
/* @0x2a423c ldrh r2, [r4, #0x2c] */
/* @0x2a423e add r3, r1 */
/* @0x2a4240 add r3, r2 */
/* @0x2a4242 add r11, r3 */
/* @0x2a4244 cbz r6, 0x2a424e <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x146> */
/* @0x2a4246 ldr r3, [r6] */
/* @0x2a4248 cmp r3, r11 */
/* @0x2a424a blo.w 0x2a413a <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x32> */
/* @0x2a424c .word 0xf1b9af76 */
/* @0x2a424e cmp.w r9, #0x0 */
/* @0x2a4250 eorle r0, r2, r0, lsl #30 */
/* @0x2a4252 beq 0x2a429a <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x192> */
/* @0x2a4254 cbnz r1, 0x2a425c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x154> */
/* @0x2a4256 ldrh r1, [r4, #0x24] */
/* @0x2a4258 cbz r1, 0x2a4282 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x17a> */
/* @0x2a425a b 0x2a4272 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x16a> */
/* @0x2a425c mov r0, r5 */
/* @0x2a425e movs r2, #0x1 */
/* @0x2a4260 mov r3, r7 */
/* @0x2a4262 bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a4264 lslvs pc, r9, r12 */
/* @0x2a4266 str r0, [r4, #0x18] */
/* @0x2a4268 cmp r0, #0x0 */
/* @0x2a426a bne 0x2a4256 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x14e> */
/* @0x2a426c mov.w r8, #0xffffffff */
/* @0x2a4270 b 0x2a42e2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1da> */
/* @0x2a4272 mov r0, r5 */
/* @0x2a4274 movs r2, #0x0 */
/* @0x2a4276 mov r3, r7 */
/* @0x2a4278 bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a427c str r0, [r4, #0x20] */
/* @0x2a427e cmp r0, #0x0 */
/* @0x2a4280 beq 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a4282 ldrh r1, [r4, #0x2c] */
/* @0x2a4284 cmp r1, #0x0 */
/* @0x2a4286 beq 0x2a42f2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1ea> */
/* @0x2a4288 mov r0, r5 */
/* @0x2a428a movs r2, #0x0 */
/* @0x2a428c mov r3, r7 */
/* @0x2a428e bl 0x2a3a98 <zip_close+0x8ac> */
/* @0x2a4290 adcvs pc, r0, #768 */
/* @0x2a4292 str r0, [r4, #0x28] */
/* @0x2a4294 cmp r0, #0x0 */
/* @0x2a4296 bne 0x2a42f2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1ea> */
/* @0x2a4298 b 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a429a cbnz r1, 0x2a42a2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x19a> */
/* @0x2a429c ldrh r1, [r4, #0x24] */
/* @0x2a429e cbz r1, 0x2a42c4 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1bc> */
/* @0x2a42a0 b 0x2a42b4 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1ac> */
/* @0x2a42a2 mov r0, r10 */
/* @0x2a42a4 movs r2, #0x1 */
/* @0x2a42a6 mov r3, r7 */
/* @0x2a42a8 bl 0x2a3af4 <zip_close+0x908> */
/* @0x2a42ac str r0, [r4, #0x18] */
/* @0x2a42ae cmp r0, #0x0 */
/* @0x2a42b0 bne 0x2a429c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x194> */
/* @0x2a42b2 b 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a42b4 mov r0, r10 */
/* @0x2a42b6 movs r2, #0x0 */
/* @0x2a42b8 mov r3, r7 */
/* @0x2a42ba bl 0x2a3af4 <zip_close+0x908> */
/* @0x2a42bc eorvs pc, r0, #6912 */
/* @0x2a42be str r0, [r4, #0x20] */
/* @0x2a42c0 cmp r0, #0x0 */
/* @0x2a42c2 beq 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a42c4 ldrh r1, [r4, #0x2c] */
/* @0x2a42c6 cbz r1, 0x2a42d8 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1d0> */
/* @0x2a42c8 mov r0, r10 */
/* @0x2a42ca movs r2, #0x0 */
/* @0x2a42cc mov r3, r7 */
/* @0x2a42ce bl 0x2a3af4 <zip_close+0x908> */
/* @0x2a42d0 adcvs pc, r0, #4352 */
/* @0x2a42d2 str r0, [r4, #0x28] */
/* @0x2a42d4 cmp r0, #0x0 */
/* @0x2a42d6 beq 0x2a426c <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x164> */
/* @0x2a42d8 cbz r6, 0x2a42e2 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1da> */
/* @0x2a42da ldr r3, [r6] */
/* @0x2a42dc rsb r3, r11, r3 */
/* @0x2a42e0 str r3, [r6] */
/* @0x2a42e2 ldr r1, [sp, #0x4] */
/* @0x2a42e4 mov r0, r8 */
/* @0x2a42e6 ldr r2, [sp, #0x3c] */
/* @0x2a42e8 ldr r3, [r1] */
/* @0x2a42ea cmp r2, r3 */
/* @0x2a42ec beq 0x2a42fa <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1f2> */
/* @0x2a42ee blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a42f0 blls 0x35e8c0 <_ZTS12CDS_Priority+0x918> */
/* @0x2a42f2 ldr r3, [sp, #0x8] */
/* @0x2a42f4 str.w r3, [r9] */
/* @0x2a42f8 b 0x2a42d8 <_Z21_zip_dirent_read_buffP10zip_direntP7IBufferPPhPjiP9zip_error+0x1d0> */
/* @0x2a42fa add sp, #0x44 */
/* @0x2a42fc pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a4300 ldr r0, [sp, #0xf8] */
/* @0x2a4302 movs r4, r2 */
/* @0x2a4304 ldrb r2, [r2, #0x1a] */
/* @0x2a4306 movs r6, r1 */
/* @0x2a4308 ldrb r1, [r2, #0x1a] */
/* @0x2a430a movs r6, r1 */

/* ── FUNC 0x2a430c · _zip_error_clear(zip_error*) · size=8 · insn=4 */
/* @0x2a430c movs r3, #0x0 */
/* @0x2a430e str r3, [r0] */
/* @0x2a4310 str r3, [r0, #0x4] */
/* @0x2a4312 bx lr */

/* ── FUNC 0x2a4314 · _zip_error_copy(zip_error*, zip_error*) · size=10 · insn=5 */
/* @0x2a4314 ldr r3, [r1] */
/* @0x2a4316 str r3, [r0] */
/* @0x2a4318 ldr r3, [r1, #0x4] */
/* @0x2a431a str r3, [r0, #0x4] */
/* @0x2a431c bx lr */

/* ── FUNC 0x2a431e · _zip_error_fini(zip_error*) · size=16 · insn=8 */
/* @0x2a431e push {r4, lr} */
/* @0x2a4320 mov r4, r0 */
/* @0x2a4322 ldr r0, [r0, #0x8] */
/* @0x2a4324 blx 0xb655c <free@plt> */
/* @0x2a4326 movwhs lr, #0x91a */
/* @0x2a4328 movs r3, #0x0 */
/* @0x2a432a str r3, [r4, #0x8] */
/* @0x2a432c pop {r4, pc} */

/* ── FUNC 0x2a432e · _zip_error_get(zip_error*, int*, int*) · size=32 · insn=15 */
/* @0x2a432e push {r3, r4, r5, lr} */
/* @0x2a4330 mov r4, r0 */
/* @0x2a4332 mov r5, r2 */
/* @0x2a4334 cbz r1, 0x2a433a <_Z14_zip_error_getP9zip_errorPiS1_+0xc> */
/* @0x2a4336 ldr r3, [r0] */
/* @0x2a4338 str r3, [r1] */
/* @0x2a433a cbz r5, 0x2a434c <_Z14_zip_error_getP9zip_errorPiS1_+0x1e> */
/* @0x2a433c ldr r0, [r4] */
/* @0x2a433e bl 0x2a4360 <zip_error_get_sys_type> */
/* @0x2a4342 cbz r0, 0x2a434a <_Z14_zip_error_getP9zip_errorPiS1_+0x1c> */
/* @0x2a4344 ldr r3, [r4, #0x4] */
/* @0x2a4346 str r3, [r5] */
/* @0x2a4348 pop {r3, r4, r5, pc} */
/* @0x2a434a str r0, [r5] */
/* @0x2a434c pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a434e · _zip_error_init(zip_error*) · size=10 · insn=5 */
/* @0x2a434e movs r3, #0x0 */
/* @0x2a4350 str r3, [r0] */
/* @0x2a4352 str r3, [r0, #0x4] */
/* @0x2a4354 str r3, [r0, #0x8] */
/* @0x2a4356 bx lr */

/* ── FUNC 0x2a4358 · _zip_error_set(zip_error*, int, int) · size=8 · insn=4 */
/* @0x2a4358 cbz r0, 0x2a435e <_Z14_zip_error_setP9zip_errorii+0x6> */
/* @0x2a435a stm.w r0, {r1, r2} */
/* @0x2a435c ldrbmi r0, [r0, -r6]! */
/* @0x2a435e bx lr */

/* ── FUNC 0x2a4360 · zip_error_get_sys_type · size=40 · insn=20 */
/* @0x2a4360 cmp r0, #0x0 */
/* @0x2a4362 blt 0x2a437c <zip_error_get_sys_type+0x1c> */
/* @0x2a4364 ldr r3, [pc, #0x18] */
/* @0x2a4366 add r3, pc */
/* @0x2a4368 ldr r3, [r3] */
/* @0x2a436a ldr r3, [r3] */
/* @0x2a436c cmp r0, r3 */
/* @0x2a436e bge 0x2a437c <zip_error_get_sys_type+0x1c> */
/* @0x2a4370 ldr r3, [pc, #0x10] */
/* @0x2a4372 add r3, pc */
/* @0x2a4374 ldr r3, [r3] */
/* @0x2a4376 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2a4378 ldrbmi r0, [r0, -r0, lsr #32]! */
/* @0x2a437a bx lr */
/* @0x2a437c movs r0, #0x0 */
/* @0x2a437e bx lr */
/* @0x2a4380 bvc 0x2a43c0 <zip_fclose+0x38> */
/* @0x2a4382 movs r4, r2 */
/* @0x2a4384 bvc 0x2a43b4 <zip_fclose+0x2c> */
/* @0x2a4386 movs r4, r2 */

/* ── FUNC 0x2a4388 · zip_fclose · size=110 · insn=49 */
/* @0x2a4388 push {r4, r5, r6, lr} */
/* @0x2a438a mov r4, r0 */
/* @0x2a438c ldr r0, [r0, #0x30] */
/* @0x2a438e cbz r0, 0x2a4394 <zip_fclose+0xc> */
/* @0x2a4390 blx 0xb69e8 <inflateEnd@plt> */
/* @0x2a4394 ldr r0, [r4, #0x2c] */
/* @0x2a4396 blx 0xb655c <free@plt> */
/* @0x2a4398 blvs 0xade728 <b2_toiTime+0x385284> */
/* @0x2a439a ldr r0, [r4, #0x30] */
/* @0x2a439c blx 0xb655c <free@plt> */
/* @0x2a43a0 ldr r0, [r4] */
/* @0x2a43a2 movs r3, #0x0 */
/* @0x2a43a4 ldr r1, [r0, #0x38] */
/* @0x2a43a6 cmp r3, r1 */
/* @0x2a43a8 bge 0x2a43d2 <zip_fclose+0x4a> */
/* @0x2a43aa ldr r2, [r0, #0x40] */
/* @0x2a43ac add.w r6, r2, r3, lsl #2 */
/* @0x2a43b0 ldr.w r5, [r2, r3, lsl #2] */
/* @0x2a43b4 cmp r5, r4 */
/* @0x2a43b6 bne 0x2a43ce <zip_fclose+0x46> */
/* @0x2a43b8 add.w r3, r1, #0x40000000 */
/* @0x2a43bc subs r3, #0x1 */
/* @0x2a43be ldr.w r3, [r2, r3, lsl #2] */
/* @0x2a43c0 eorsvs r3, r3, r3, lsr #32 */
/* @0x2a43c2 str r3, [r6] */
/* @0x2a43c4 ldr r3, [r4] */
/* @0x2a43c6 ldr r2, [r3, #0x38] */
/* @0x2a43c8 subs r2, #0x1 */
/* @0x2a43ca str r2, [r3, #0x38] */
/* @0x2a43cc b 0x2a43d2 <zip_fclose+0x4a> */
/* @0x2a43ce adds r3, #0x1 */
/* @0x2a43d0 b 0x2a43a6 <zip_fclose+0x1e> */
/* @0x2a43d2 ldr r5, [r4, #0x4] */
/* @0x2a43d4 cbnz r5, 0x2a43ec <zip_fclose+0x64> */
/* @0x2a43d6 ldr r3, [r4, #0x10] */
/* @0x2a43d8 and r3, r3, #0x5 */
/* @0x2a43dc cmp r3, #0x5 */
/* @0x2a43de bne 0x2a43ec <zip_fclose+0x64> */
/* @0x2a43e0 ldr r5, [r4, #0x28] */
/* @0x2a43e2 ldr r3, [r4, #0x24] */
/* @0x2a43e4 cmp r5, r3 */
/* @0x2a43e6 ite ne */
/* @0x2a43e8 movne r5, #0x7 */
/* @0x2a43ea moveq r5, #0x0 */
/* @0x2a43ec mov r0, r4 */
/* @0x2a43ee blx 0xb655c <free@plt> */
/* @0x2a43f0 .word 0x4628e8b6 */
/* @0x2a43f2 mov r0, r5 */
/* @0x2a43f4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a43f8 · _zip_filerange_crc(__sFILE*, long, long, unsigned long*, zip_error*) · size=192 · insn=84 */
/* @0x2a43f8 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a43fc sub.w sp, sp, #0x2000 */
/* @0x2a4400 sub sp, #0xc */
/* @0x2a4402 ldr r6, [pc, #0xb0] */
/* @0x2a4404 mov r4, r2 */
/* @0x2a4406 add.w r2, sp, #0x2000 */
/* @0x2a4408 ldrbtmi r5, [lr], #-512 */
/* @0x2a440a add r6, pc */
/* @0x2a440c ldr r6, [r6] */
/* @0x2a440e adds r2, #0x30 */
/* @0x2a4410 mov r7, r3 */
/* @0x2a4412 ldr.w r9, [r2] */
/* @0x2a4414 ldmdavs r3!, {r12, pc} */
/* @0x2a4416 ldr r3, [r6] */
/* @0x2a4418 add.w r2, sp, #0x2000 */
/* @0x2a441c adds r2, #0x4 */
/* @0x2a441e mov r8, r0 */
/* @0x2a4420 movs r0, #0x0 */
/* @0x2a4422 mov r5, r1 */
/* @0x2a4424 str r3, [r2] */
/* @0x2a4426 mov r1, r0 */
/* @0x2a4428 mov r2, r0 */
/* @0x2a442a mov r11, r6 */
/* @0x2a442c blx 0xb6ea4 <crc32@plt> */
/* @0x2a4430 mov r1, r5 */
/* @0x2a4432 movs r2, #0x0 */
/* @0x2a4434 str r0, [r7] */
/* @0x2a4436 mov r0, r8 */
/* @0x2a4438 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a443c mov r5, r0 */
/* @0x2a443e cbnz r0, 0x2a4446 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x4e> */
/* @0x2a4440 add.w r10, sp, #0x4 */
/* @0x2a4444 b 0x2a4460 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x68> */
/* @0x2a4446 blx 0xb6bf8 <__errno@plt> */
/* @0x2a4448 ldrdhs lr, pc, [r4, -r8] */
/* @0x2a444a movs r1, #0x4 */
/* @0x2a444c ldr r2, [r0] */
/* @0x2a444e mov r0, r9 */
/* @0x2a4450 b 0x2a448a <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x92> */
/* @0x2a4452 ldr r0, [r7] */
/* @0x2a4454 mov r1, r10 */
/* @0x2a4456 mov r2, r6 */
/* @0x2a4458 subs r4, r4, r6 */
/* @0x2a445a blx 0xb6ea4 <crc32@plt> */
/* @0x2a445c eorsvs lr, r8, r4, lsr #26 */
/* @0x2a445e str r0, [r7] */
/* @0x2a4460 cmp r4, #0x0 */
/* @0x2a4462 ble 0x2a4492 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x9a> */
/* @0x2a4464 mov r0, r10 */
/* @0x2a4466 movs r1, #0x1 */
/* @0x2a4468 cmp.w r4, #0x2000 */
/* @0x2a446c ite lt */
/* @0x2a446e movlt r2, r4 */
/* @0x2a4470 movge.w r2, #0x2000 */
/* @0x2a4474 mov r3, r8 */
/* @0x2a4476 blx 0xb68c8 <fread@plt> */
/* @0x2a4478 strmi lr, [r6], -r8, lsr #20 */
/* @0x2a447a mov r6, r0 */
/* @0x2a447c cmp r0, #0x0 */
/* @0x2a447e bne 0x2a4452 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0x5a> */
/* @0x2a4480 blx 0xb6bf8 <__errno@plt> */
/* @0x2a4484 movs r1, #0x5 */
/* @0x2a4486 ldr r2, [r0] */
/* @0x2a4488 mov r0, r9 */
/* @0x2a448a bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a448c .word 0xf04fff65 */
/* @0x2a448e mov.w r5, #0xffffffff */
/* @0x2a4490 .word 0xf50d35ff */
/* @0x2a4492 add.w r3, sp, #0x2000 */
/* @0x2a4494 strtmi r5, [r8], -r0, lsl #6 */
/* @0x2a4496 mov r0, r5 */
/* @0x2a4498 adds r3, #0x4 */
/* @0x2a449a ldr r2, [r3] */
/* @0x2a449c ldr.w r3, [r11] */
/* @0x2a44a0 cmp r2, r3 */
/* @0x2a44a2 beq 0x2a44a8 <_Z18_zip_filerange_crcP7__sFILEllPmP9zip_error+0xb0> */
/* @0x2a44a4 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2a44a8 add.w sp, sp, #0x2000 */
/* @0x2a44ac add sp, #0xc */
/* @0x2a44ae pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a44b0 svclt #0x8ff0 */
/* @0x2a44b2 nop */
/* @0x2a44b4 str r5, [sp, #0x128] */
/* @0x2a44b6 movs r4, r2 */

/* ── FUNC 0x2a44b8 · zip_fopen · size=30 · insn=15 */
/* @0x2a44b8 push {r3, r4, r5, lr} */
/* @0x2a44ba mov r5, r0 */
/* @0x2a44bc mov r4, r2 */
/* @0x2a44be bl 0x2a4a58 <zip_name_locate> */
/* @0x2a44c0 vmlsne.f32 s30, s3, s22 */
/* @0x2a44c2 subs r1, r0, #0x0 */
/* @0x2a44c4 blt 0x2a44d2 <zip_fopen+0x1a> */
/* @0x2a44c6 mov r0, r5 */
/* @0x2a44c8 mov r2, r4 */
/* @0x2a44ca pop.w {r3, r4, r5, lr} */
/* @0x2a44cc .word 0xf0004038 */
/* @0x2a44ce b.w 0x2a4584 <zip_fopen_index> */
/* @0x2a44d0 andhs r11, r0, r9, asr r8 */
/* @0x2a44d2 movs r0, #0x0 */
/* @0x2a44d4 pop {r3, r4, r5, pc} */

/* ── FUNC 0x2a44d6 · _zip_file_fillbuf(void*, unsigned int, zip_file*) · size=174 · insn=83 */
/* @0x2a44d6 push.w {r3, r4, r5, r7, r8, lr} */
/* @0x2a44da mov r7, r0 */
/* @0x2a44dc ldr r5, [r2, #0x4] */
/* @0x2a44de mov r8, r1 */
/* @0x2a44e0 mov r4, r2 */
/* @0x2a44e2 cmp r5, #0x0 */
/* @0x2a44e4 bne 0x2a457a <_Z17_zip_file_fillbufPvjP8zip_file+0xa4> */
/* @0x2a44e6 ldr r3, [r2, #0x10] */
/* @0x2a44e8 lsls r3, r3, #0x1f */
/* @0x2a44ea bmi 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a44ec ldr r3, [r2, #0x20] */
/* @0x2a44ee cmp r3, #0x0 */
/* @0x2a44f0 beq 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a44f2 cmp r1, #0x0 */
/* @0x2a44f4 beq 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a44f6 ldr r3, [r2] */
/* @0x2a44f8 ldr r0, [r3, #0x4] */
/* @0x2a44fa cbz r0, 0x2a4514 <_Z17_zip_file_fillbufPvjP8zip_file+0x3e> */
/* @0x2a44fc ldr r1, [r2, #0x18] */
/* @0x2a44fe mov r2, r5 */
/* @0x2a4500 blx 0xb6ed4 <fseeko@plt> */
/* @0x2a4502 stmdahs r0, {r3, r5, r6, r7, r10, r11, sp, lr, pc} */
/* @0x2a4504 cmp r0, #0x0 */
/* @0x2a4506 bge 0x2a4522 <_Z17_zip_file_fillbufPvjP8zip_file+0x4c> */
/* @0x2a4508 blx 0xb6bf8 <__errno@plt> */
/* @0x2a450a .word 0x2104eb76 */
/* @0x2a450c movs r1, #0x4 */
/* @0x2a450e ldr r2, [r0] */
/* @0x2a4510 adds r0, r4, #0x4 */
/* @0x2a4512 b 0x2a4544 <_Z17_zip_file_fillbufPvjP8zip_file+0x6e> */
/* @0x2a4514 ldr r0, [r3, #0x8] */
/* @0x2a4516 cbz r0, 0x2a4522 <_Z17_zip_file_fillbufPvjP8zip_file+0x4c> */
/* @0x2a4518 ldr r3, [r0] */
/* @0x2a451a mov r1, r5 */
/* @0x2a451c ldr r2, [r2, #0x18] */
/* @0x2a451e ldr r3, [r3, #0x10] */
/* @0x2a4520 blx r3 */
/* @0x2a4522 ldr r2, [r4] */
/* @0x2a4524 ldr r3, [r4, #0x20] */
/* @0x2a4526 cmp r8, r3 */
/* @0x2a4528 it hs */
/* @0x2a452a movhs r8, r3 */
/* @0x2a452c ldr r3, [r2, #0x4] */
/* @0x2a452e cbz r3, 0x2a454a <_Z17_zip_file_fillbufPvjP8zip_file+0x74> */
/* @0x2a4530 mov r0, r7 */
/* @0x2a4532 movs r1, #0x1 */
/* @0x2a4534 mov r2, r8 */
/* @0x2a4536 blx 0xb68c8 <fread@plt> */
/* @0x2a453a subs r5, r0, #0x0 */
/* @0x2a453c bne 0x2a455a <_Z17_zip_file_fillbufPvjP8zip_file+0x84> */
/* @0x2a453e adds r0, r4, #0x4 */
/* @0x2a4540 movs r1, #0x11 */
/* @0x2a4542 movs r2, #0x0 */
/* @0x2a4544 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a4546 ands pc, r7, r8, lsl #30 */
/* @0x2a4548 b 0x2a457a <_Z17_zip_file_fillbufPvjP8zip_file+0xa4> */
/* @0x2a454a ldr r0, [r2, #0x8] */
/* @0x2a454c cbz r0, 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a454e mov r1, r7 */
/* @0x2a4550 movs r2, #0x1 */
/* @0x2a4552 mov r3, r8 */
/* @0x2a4554 blx 0xcdc9c <_ZN7IBuffer4ReadEPKvjj> */
/* @0x2a4556 strb lr, [pc, r2, lsr #23]! */
/* @0x2a4558 b 0x2a453a <_Z17_zip_file_fillbufPvjP8zip_file+0x64> */
/* @0x2a455a bge 0x2a456c <_Z17_zip_file_fillbufPvjP8zip_file+0x96> */
/* @0x2a455c blx 0xb6bf8 <__errno@plt> */
/* @0x2a455e .word 0x2105eb4c */
/* @0x2a4560 movs r1, #0x5 */
/* @0x2a4562 ldr r2, [r0] */
/* @0x2a4564 adds r0, r4, #0x4 */
/* @0x2a4566 bl 0x2a4358 <_Z14_zip_error_setP9zip_errorii> */
/* @0x2a456a b 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a456c ldr r3, [r4, #0x18] */
/* @0x2a456e add r3, r5 */
/* @0x2a4570 str r3, [r4, #0x18] */
/* @0x2a4572 ldr r3, [r4, #0x20] */
/* @0x2a4574 subs r3, r3, r5 */
/* @0x2a4576 str r3, [r4, #0x20] */
/* @0x2a4578 b 0x2a457e <_Z17_zip_file_fillbufPvjP8zip_file+0xa8> */
/* @0x2a457a mov.w r5, #0xffffffff */
/* @0x2a457e mov r0, r5 */
/* @0x2a4580 pop.w {r3, r4, r5, r7, r8, pc} */
/* @0x2a4582 push {r3, r4, r5, r7, r8, pc} */
