/* libyoyo.so 覆盖卡组 0236
 * 函数 0x283bb0..0x2853c8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x283bb0 · spAnimationStateData_setMix · size=176 · insn=44 */
/* @0x283bb0 push {r3, r4, r5, r6, r7, lr} */
/* @0x283bb4 mov r5, r0 */
/* @0x283bb8 ldr r4, [r0, #0x8] */
/* @0x283bbc mov r6, r2 */
/* @0x283bc0 mov r7, r3 */
/* @0x283bc4 cmp r4, #0 */
/* @0x283bc8 beq 0x283bf4 <spAnimationStateData_setMix+0x44> */
/* @0x283bcc ldr r3, [r4] */
/* @0x283bd0 cmp r3, r1 */
/* @0x283bd4 bne 0x283be8 <spAnimationStateData_setMix+0x38> */
/* @0x283bd8 b 0x283c28 <spAnimationStateData_setMix+0x78> */
/* @0x283bdc ldr r12, [r4] */
/* @0x283be0 cmp r12, r1 */
/* @0x283be4 beq 0x283c28 <spAnimationStateData_setMix+0x78> */
/* @0x283be8 ldr r4, [r4, #0x8] */
/* @0x283bec cmp r4, #0 */
/* @0x283bf0 bne 0x283bdc <spAnimationStateData_setMix+0x2c> */
/* @0x283bf4 mov r0, r1 */
/* @0x283bf8 bl 0x283afc <_FromEntry_create> */
/* @0x283bfc ldr r3, [r5, #0x8] */
/* @0x283c00 mov r4, r0 */
/* @0x283c04 str r3, [r0, #0x8] */
/* @0x283c08 str r0, [r5, #0x8] */
/* @0x283c0c mov r0, r6 */
/* @0x283c10 mov r1, r7 */
/* @0x283c14 bl 0x283ac4 <_ToEntry_create> */
/* @0x283c18 ldr r3, [r4, #0x4] */
/* @0x283c1c str r3, [r0, #0x8] */
/* @0x283c20 str r0, [r4, #0x4] */
/* @0x283c24 pop {r3, r4, r5, r6, r7, pc} */
/* @0x283c28 ldr r12, [r4, #0x4] */
/* @0x283c2c cmp r12, #0 */
/* @0x283c30 beq 0x283c0c <spAnimationStateData_setMix+0x5c> */
/* @0x283c34 ldr r3, [r12] */
/* @0x283c38 cmp r3, r6 */
/* @0x283c3c beq 0x283c58 <spAnimationStateData_setMix+0xa8> */
/* @0x283c40 ldr r12, [r12, #0x8] */
/* @0x283c44 cmp r12, #0 */
/* @0x283c48 beq 0x283c0c <spAnimationStateData_setMix+0x5c> */
/* @0x283c4c ldr r5, [r12] */
/* @0x283c50 cmp r5, r6 */
/* @0x283c54 bne 0x283c40 <spAnimationStateData_setMix+0x90> */
/* @0x283c58 str r7, [r12, #0x4] */
/* @0x283c5c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x283c60 · spAnimationStateData_setMixByName · size=72 · insn=18 */
/* @0x283c60 push {r4, r5, r6, r7, r8, lr} */
/* @0x283c64 mov r4, r0 */
/* @0x283c68 ldr r0, [r0] */
/* @0x283c6c mov r5, r2 */
/* @0x283c70 mov r6, r3 */
/* @0x283c74 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0x283c78 subs r7, r0, #0 */
/* @0x283c7c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x283c80 mov r1, r5 */
/* @0x283c84 ldr r0, [r4] */
/* @0x283c88 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0x283c8c subs r2, r0, #0 */
/* @0x283c90 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x283c94 mov r0, r4 */
/* @0x283c98 mov r1, r7 */
/* @0x283c9c mov r3, r6 */
/* @0x283ca0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x283ca4 b 0x283bb0 <spAnimationStateData_setMix> */

/* ── FUNC 0x283ca8 · spAnimationStateData_getMix · size=108 · insn=27 */
/* @0x283ca8 ldr r12, [r0, #0x8] */
/* @0x283cac str r4, [sp, #-0x4]! */
/* @0x283cb0 cmp r12, #0 */
/* @0x283cb4 bne 0x283cc8 <spAnimationStateData_getMix+0x20> */
/* @0x283cb8 b 0x283d08 <spAnimationStateData_getMix+0x60> */
/* @0x283cbc ldr r12, [r12, #0x8] */
/* @0x283cc0 cmp r12, #0 */
/* @0x283cc4 beq 0x283d08 <spAnimationStateData_getMix+0x60> */
/* @0x283cc8 ldr r3, [r12] */
/* @0x283ccc cmp r3, r1 */
/* @0x283cd0 bne 0x283cbc <spAnimationStateData_getMix+0x14> */
/* @0x283cd4 ldr r3, [r12, #0x4] */
/* @0x283cd8 cmp r3, #0 */
/* @0x283cdc bne 0x283cf0 <spAnimationStateData_getMix+0x48> */
/* @0x283ce0 b 0x283cbc <spAnimationStateData_getMix+0x14> */
/* @0x283ce4 ldr r3, [r3, #0x8] */
/* @0x283ce8 cmp r3, #0 */
/* @0x283cec beq 0x283cbc <spAnimationStateData_getMix+0x14> */
/* @0x283cf0 ldr r4, [r3] */
/* @0x283cf4 cmp r4, r2 */
/* @0x283cf8 bne 0x283ce4 <spAnimationStateData_getMix+0x3c> */
/* @0x283cfc ldr r0, [r3, #0x4] */
/* @0x283d00 ldr r4, [sp], #4 */
/* @0x283d04 bx lr */
/* @0x283d08 ldr r0, [r0, #0x4] */
/* @0x283d0c ldr r4, [sp], #4 */
/* @0x283d10 bx lr */

/* ── FUNC 0x283d14 · anon_283d14 · size=832 · insn=209 */
/* @0x283d14 ldr r3, [pc, #0xc8] */
/* @0x283d18 ldr r2, [r0] */
/* @0x283d1c ldr r3, [pc, r3] */
/* @0x283d20 push {r4, r5} */
/* @0x283d24 ldr r1, [r3] */
/* @0x283d28 ldrb r12, [r2] */
/* @0x283d2c ldr r5, [r0, #0x4] */
/* @0x283d30 add r3, r1, r12 */
/* @0x283d34 ldrb r3, [r3, #0x1] */
/* @0x283d38 tst r3, #8 */
/* @0x283d3c beq 0x283d78 <spAnimationStateData_getMix+0xd0> */
/* @0x283d40 cmp r2, r5 */
/* @0x283d44 bhs 0x283d78 <spAnimationStateData_getMix+0xd0> */
/* @0x283d48 add r3, r2, #1 */
/* @0x283d4c add r4, r5, #1 */
/* @0x283d50 str r3, [r0] */
/* @0x283d54 mov r2, r3 */
/* @0x283d58 ldrb r12, [r3] */
/* @0x283d5c add r3, r3, #1 */
/* @0x283d60 add r12, r1, r12 */
/* @0x283d64 ldrb r12, [r12, #0x1] */
/* @0x283d68 tst r12, #8 */
/* @0x283d6c beq 0x283d78 <spAnimationStateData_getMix+0xd0> */
/* @0x283d70 cmp r3, r4 */
/* @0x283d74 bne 0x283d50 <spAnimationStateData_getMix+0xa8> */
/* @0x283d78 cmp r2, r5 */
/* @0x283d7c beq 0x283ddc <spAnimationStateData_getMix+0x134> */
/* @0x283d80 sub r12, r5, #1 */
/* @0x283d84 str r12, [r0, #0x4] */
/* @0x283d88 ldrb r3, [r5, #-0x1] */
/* @0x283d8c add r3, r1, r3 */
/* @0x283d90 ldrb r3, [r3, #0x1] */
/* @0x283d94 tst r3, #8 */
/* @0x283d98 beq 0x283dd4 <spAnimationStateData_getMix+0x12c> */
/* @0x283d9c cmp r12, r2 */
/* @0x283da0 blo 0x283dd4 <spAnimationStateData_getMix+0x12c> */
/* @0x283da4 sub r3, r5, #2 */
/* @0x283da8 sub r2, r2, #2 */
/* @0x283dac str r3, [r0, #0x4] */
/* @0x283db0 mov r12, r3 */
/* @0x283db4 ldrb r4, [r3] */
/* @0x283db8 sub r3, r3, #1 */
/* @0x283dbc add r4, r1, r4 */
/* @0x283dc0 ldrb r4, [r4, #0x1] */
/* @0x283dc4 tst r4, #8 */
/* @0x283dc8 beq 0x283dd4 <spAnimationStateData_getMix+0x12c> */
/* @0x283dcc cmp r3, r2 */
/* @0x283dd0 bne 0x283dac <spAnimationStateData_getMix+0x104> */
/* @0x283dd4 add r12, r12, #1 */
/* @0x283dd8 str r12, [r0, #0x4] */
/* @0x283ddc pop {r4, r5} */
/* @0x283de0 bx lr */
/* @0x283de4 andseq r9, r6, r4, ror #24 */
/* @0x283de8 push {r3, r4, r5, lr} */
/* @0x283dec mov r4, r0 */
/* @0x283df0 ldr r3, [r0] */
/* @0x283df4 mov r5, r1 */
/* @0x283df8 cmp r3, r1 */
/* @0x283dfc beq 0x283e6c <spAnimationStateData_getMix+0x1c4> */
/* @0x283e00 str r3, [r2] */
/* @0x283e04 ldr r12, [r0] */
/* @0x283e08 cmp r12, r1 */
/* @0x283e0c beq 0x283e44 <spAnimationStateData_getMix+0x19c> */
/* @0x283e10 ldrb r3, [r12] */
/* @0x283e14 cmp r3, #10 */
/* @0x283e18 beq 0x283e44 <spAnimationStateData_getMix+0x19c> */
/* @0x283e1c add r3, r12, #1 */
/* @0x283e20 b 0x283e30 <spAnimationStateData_getMix+0x188> */
/* @0x283e24 ldrb lr, [r12] */
/* @0x283e28 cmp lr, #10 */
/* @0x283e2c beq 0x283e44 <spAnimationStateData_getMix+0x19c> */
/* @0x283e30 cmp r3, r5 */
/* @0x283e34 str r3, [r4] */
/* @0x283e38 mov r12, r3 */
/* @0x283e3c add r3, r3, #1 */
/* @0x283e40 bne 0x283e24 <spAnimationStateData_getMix+0x17c> */
/* @0x283e44 str r12, [r2, #0x4] */
/* @0x283e48 mov r0, r2 */
/* @0x283e4c bl 0x283d14 <spAnimationStateData_getMix+0x6c> */
/* @0x283e50 ldr r3, [r4] */
/* @0x283e54 cmp r3, r5 */
/* @0x283e58 beq 0x283e74 <spAnimationStateData_getMix+0x1cc> */
/* @0x283e5c add r3, r3, #1 */
/* @0x283e60 mov r0, #1 */
/* @0x283e64 str r3, [r4] */
/* @0x283e68 pop {r3, r4, r5, pc} */
/* @0x283e6c mov r0, #0 */
/* @0x283e70 pop {r3, r4, r5, pc} */
/* @0x283e74 mov r0, #1 */
/* @0x283e78 pop {r3, r4, r5, pc} */
/* @0x283e7c push {r3, r4, r5, lr} */
/* @0x283e80 mov r5, r2 */
/* @0x283e84 bl 0x283de8 <spAnimationStateData_getMix+0x140> */
/* @0x283e88 ldm r5, {r3, r12} */
/* @0x283e8c add r3, r3, #1 */
/* @0x283e90 add r12, r12, #1 */
/* @0x283e94 b 0x283ea0 <spAnimationStateData_getMix+0x1f8> */
/* @0x283e98 cmp r1, #58 */
/* @0x283e9c beq 0x283ebc <spAnimationStateData_getMix+0x214> */
/* @0x283ea0 cmp r3, r12 */
/* @0x283ea4 mov r4, r3 */
/* @0x283ea8 ldrb r1, [r3, #-0x1] */
/* @0x283eac add r3, r3, #1 */
/* @0x283eb0 bne 0x283e98 <spAnimationStateData_getMix+0x1f0> */
/* @0x283eb4 mov r0, #0 */
/* @0x283eb8 pop {r3, r4, r5, pc} */
/* @0x283ebc mov r0, r5 */
/* @0x283ec0 str r4, [r5] */
/* @0x283ec4 bl 0x283d14 <spAnimationStateData_getMix+0x6c> */
/* @0x283ec8 mov r0, #1 */
/* @0x283ecc pop {r3, r4, r5, pc} */
/* @0x283ed0 push {r4, r5, r6, r7, r8, lr} */
/* @0x283ed4 sub sp, sp, #8 */
/* @0x283ed8 mov r5, r2 */
/* @0x283edc mov r3, #0 */
/* @0x283ee0 mov r2, sp */
/* @0x283ee4 str r3, [sp] */
/* @0x283ee8 str r3, [sp, #0x4] */
/* @0x283eec bl 0x283de8 <spAnimationStateData_getMix+0x140> */
/* @0x283ef0 ldm sp, {r3, r7} */
/* @0x283ef4 add r12, r7, #1 */
/* @0x283ef8 add r3, r3, #1 */
/* @0x283efc b 0x283f08 <spAnimationStateData_getMix+0x260> */
/* @0x283f00 cmp r1, #58 */
/* @0x283f04 beq 0x283f2c <spAnimationStateData_getMix+0x284> */
/* @0x283f08 cmp r3, r12 */
/* @0x283f0c mov r4, r3 */
/* @0x283f10 ldrb r1, [r3, #-0x1] */
/* @0x283f14 add r3, r3, #1 */
/* @0x283f18 bne 0x283f00 <spAnimationStateData_getMix+0x258> */
/* @0x283f1c mov r8, #0 */
/* @0x283f20 mov r0, r8 */
/* @0x283f24 add sp, sp, #8 */
/* @0x283f28 pop {r4, r5, r6, r7, r8, pc} */
/* @0x283f2c mov r2, r4 */
/* @0x283f30 mov r6, r5 */
/* @0x283f34 mov r8, #0 */
/* @0x283f38 str r4, [sp] */
/* @0x283f3c add r3, r2, #1 */
/* @0x283f40 mov r4, r6 */
/* @0x283f44 str r2, [r6] */
/* @0x283f48 b 0x283f54 <spAnimationStateData_getMix+0x2ac> */
/* @0x283f4c cmp r1, #44 */
/* @0x283f50 beq 0x283f88 <spAnimationStateData_getMix+0x2e0> */
/* @0x283f54 cmp r3, r12 */
/* @0x283f58 mov lr, r3 */
/* @0x283f5c ldrb r1, [r3, #-0x1] */
/* @0x283f60 add r3, r3, #1 */
/* @0x283f64 bne 0x283f4c <spAnimationStateData_getMix+0x2a4> */
/* @0x283f68 add r8, r8, #1 */
/* @0x283f6c mov r0, r4 */
/* @0x283f70 str r2, [r4] */
/* @0x283f74 str r7, [r4, #0x4] */
/* @0x283f78 bl 0x283d14 <spAnimationStateData_getMix+0x6c> */
/* @0x283f7c mov r0, r8 */
/* @0x283f80 add sp, sp, #8 */
/* @0x283f84 pop {r4, r5, r6, r7, r8, pc} */
/* @0x283f88 sub r3, lr, #2 */
/* @0x283f8c mov r0, r6 */
/* @0x283f90 str r3, [r6, #0x4] */
/* @0x283f94 add r8, r8, #1 */
/* @0x283f98 str lr, [sp] */
/* @0x283f9c bl 0x283d14 <spAnimationStateData_getMix+0x6c> */
/* @0x283fa0 cmp r8, #3 */
/* @0x283fa4 add r6, r6, #8 */
/* @0x283fa8 ldmne sp, {r2, r7} */
/* @0x283fac addne r12, r7, #1 */
/* @0x283fb0 bne 0x283f3c <spAnimationStateData_getMix+0x294> */
/* @0x283fb4 ldr r2, [sp] */
/* @0x283fb8 add r4, r5, #24 */
/* @0x283fbc ldr r7, [sp, #0x4] */
/* @0x283fc0 mov r8, #4 */
/* @0x283fc4 b 0x283f6c <spAnimationStateData_getMix+0x2c4> */
/* @0x283fc8 push {r3, r4, r5, lr} */
/* @0x283fcc mov r2, #137 */
/* @0x283fd0 ldr r3, [r0] */
/* @0x283fd4 mov r5, r0 */
/* @0x283fd8 ldr r4, [r0, #0x4] */
/* @0x283fdc ldr r1, [pc, #0x28] */
/* @0x283fe0 rsb r4, r3, r4 */
/* @0x283fe4 add r1, pc, r1 */
/* @0x283fe8 add r0, r4, #1 */
/* @0x283fec bl 0x285c10 <_malloc> */
/* @0x283ff0 mov r2, r4 */
/* @0x283ff4 ldr r1, [r5] */
/* @0x283ff8 bl 0xb65bc <memcpy@plt> */
/* @0x283ffc mov r2, #0 */
/* @0x284000 mov r3, r0 */
/* @0x284004 strb r2, [r3, r4] */
/* @0x284008 pop {r3, r4, r5, pc} */
/* @0x28400c andeq r3, sp, r0, lsr #10 */
/* @0x284010 push {r3, r4, r5, r6, r7, lr} */
/* @0x284014 add r5, r0, #32 */
/* @0x284018 ldr r6, [r1] */
/* @0x28401c mov r4, #7 */
/* @0x284020 ldr r7, [r1, #0x4] */
/* @0x284024 rsb r7, r6, r7 */
/* @0x284028 ldr r0, [r5, #-0x4]! */
/* @0x28402c mov r1, r6 */
/* @0x284030 mov r2, r7 */
/* @0x284034 bl 0xb65e0 <strncmp@plt> */
/* @0x284038 cmp r0, #0 */
/* @0x28403c beq 0x284050 <spAnimationStateData_getMix+0x3a8> */
/* @0x284040 subs r4, r4, #1 */
/* @0x284044 bhs 0x284028 <spAnimationStateData_getMix+0x380> */
/* @0x284048 mov r0, #0 */
/* @0x28404c pop {r3, r4, r5, r6, r7, pc} */
/* @0x284050 mov r0, r4 */
/* @0x284054 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x284058 · spAtlasPage_create · size=96 · insn=24 */
/* @0x284058 push {r3, r4, r5, r6, r7, lr} */
/* @0x28405c mov r3, #37 */
/* @0x284060 ldr r6, [pc, #0x4c] */
/* @0x284064 mov r5, r1 */
/* @0x284068 mov r7, r0 */
/* @0x28406c mov r1, #44 */
/* @0x284070 add r6, pc, r6 */
/* @0x284074 mov r0, #1 */
/* @0x284078 mov r2, r6 */
/* @0x28407c bl 0x285c4c <_calloc> */
/* @0x284080 mov r4, r0 */
/* @0x284084 str r7, [r0] */
/* @0x284088 mov r0, r5 */
/* @0x28408c bl 0xb6538 <strlen@plt> */
/* @0x284090 mov r1, r6 */
/* @0x284094 mov r2, #39 */
/* @0x284098 add r0, r0, #1 */
/* @0x28409c bl 0x285c10 <_malloc> */
/* @0x2840a0 mov r1, r5 */
/* @0x2840a4 str r0, [r4, #0x4] */
/* @0x2840a8 bl 0xb65a4 <strcpy@plt> */
/* @0x2840ac mov r0, r4 */
/* @0x2840b0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2840b4 muleq sp, r4, r4 */

/* ── FUNC 0x2840b8 · spAtlasPage_dispose · size=32 · insn=8 */
/* @0x2840b8 push {r4, lr} */
/* @0x2840bc mov r4, r0 */
/* @0x2840c0 bl 0xbd814 <_spAtlasPage_disposeTexture> */
/* @0x2840c4 ldr r0, [r4, #0x4] */
/* @0x2840c8 bl 0x285c80 <_free> */
/* @0x2840cc mov r0, r4 */
/* @0x2840d0 pop {r4, lr} */
/* @0x2840d4 b 0x285c80 <_free> */

/* ── FUNC 0x2840d8 · spAtlasRegion_create · size=28 · insn=7 */
/* @0x2840d8 ldr r2, [pc, #0x10] */
/* @0x2840dc mov r0, #1 */
/* @0x2840e0 mov r1, #80 */
/* @0x2840e4 mov r3, #52 */
/* @0x2840e8 add r2, pc, r2 */
/* @0x2840ec b 0x285c4c <_calloc> */
/* @0x2840f0 andeq r3, sp, r12, lsl r4 */

/* ── FUNC 0x2840f4 · spAtlasRegion_dispose · size=44 · insn=11 */
/* @0x2840f4 push {r4, lr} */
/* @0x2840f8 mov r4, r0 */
/* @0x2840fc ldr r0, [r0] */
/* @0x284100 bl 0x285c80 <_free> */
/* @0x284104 ldr r0, [r4, #0x40] */
/* @0x284108 bl 0x285c80 <_free> */
/* @0x28410c ldr r0, [r4, #0x44] */
/* @0x284110 bl 0x285c80 <_free> */
/* @0x284114 mov r0, r4 */
/* @0x284118 pop {r4, lr} */
/* @0x28411c b 0x285c80 <_free> */

/* ── FUNC 0x284120 · spAtlas_dispose · size=84 · insn=21 */
/* @0x284120 push {r3, r4, r5, lr} */
/* @0x284124 mov r5, r0 */
/* @0x284128 ldr r0, [r0] */
/* @0x28412c cmp r0, #0 */
/* @0x284130 beq 0x284148 <spAtlas_dispose+0x28> */
/* @0x284134 ldr r4, [r0, #0x28] */
/* @0x284138 bl 0x2840b8 <spAtlasPage_dispose> */
/* @0x28413c cmp r4, #0 */
/* @0x284140 mov r0, r4 */
/* @0x284144 bne 0x284134 <spAtlas_dispose+0x14> */
/* @0x284148 ldr r0, [r5, #0x4] */
/* @0x28414c cmp r0, #0 */
/* @0x284150 beq 0x284168 <spAtlas_dispose+0x48> */
/* @0x284154 ldr r4, [r0, #0x4c] */
/* @0x284158 bl 0x2840f4 <spAtlasRegion_dispose> */
/* @0x28415c cmp r4, #0 */
/* @0x284160 mov r0, r4 */
/* @0x284164 bne 0x284154 <spAtlas_dispose+0x34> */
/* @0x284168 mov r0, r5 */
/* @0x28416c pop {r3, r4, r5, lr} */
/* @0x284170 b 0x285c80 <_free> */

/* ── FUNC 0x284174 · spAtlas_create · size=1824 · insn=456 */
/* @0x284174 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x284178 sub sp, sp, #108 */
/* @0x28417c add r5, r0, r1 */
/* @0x284180 mov r4, r3 */
/* @0x284184 str r0, [sp, #0x3c] */
/* @0x284188 mov r0, r2 */
/* @0x28418c str r2, [sp, #0xc] */
/* @0x284190 bl 0xb6538 <strlen@plt> */
/* @0x284194 cmp r0, #0 */
/* @0x284198 str r0, [sp, #0x14] */
/* @0x28419c ble 0x2844bc <spAtlas_create+0x348> */
/* @0x2841a0 ldr r12, [sp, #0xc] */
/* @0x2841a4 add r3, r12, r0 */
/* @0x2841a8 ldrb r3, [r3, #-0x1] */
/* @0x2841ac cmp r3, #47 */
/* @0x2841b0 beq 0x2844bc <spAtlas_create+0x348> */
/* @0x2841b4 subs r3, r3, #92 */
/* @0x2841b8 movne r3, #1 */
/* @0x2841bc str r3, [sp, #0x20] */
/* @0x2841c0 ldr r2, [pc, #0x6b0] */
/* @0x2841c4 mov r3, #182 */
/* @0x2841c8 ldr r12, [pc, #0x6ac] */
/* @0x2841cc mov r0, #1 */
/* @0x2841d0 mov r1, #12 */
/* @0x2841d4 add r2, pc, r2 */
/* @0x2841d8 add r12, pc, r12 */
/* @0x2841dc str r12, [sp, #0x10] */
/* @0x2841e0 bl 0x285c4c <_calloc> */
/* @0x2841e4 ldr r3, [sp, #0x10] */
/* @0x2841e8 ldr r12, [pc, #0x690] */
/* @0x2841ec mov r8, #0 */
/* @0x2841f0 add r3, r3, #32 */
/* @0x2841f4 str r3, [sp, #0x28] */
/* @0x2841f8 ldr r3, [pc, #0x684] */
/* @0x2841fc add r12, pc, r12 */
/* @0x284200 str r12, [sp, #0x18] */
/* @0x284204 mov r11, r8 */
/* @0x284208 add r3, pc, r3 */
/* @0x28420c ldr r12, [pc, #0x674] */
/* @0x284210 str r3, [sp, #0x24] */
/* @0x284214 add r10, sp, #64 */
/* @0x284218 ldr r3, [pc, #0x66c] */
/* @0x28421c add r12, pc, r12 */
/* @0x284220 str r8, [sp, #0x1c] */
/* @0x284224 add r3, pc, r3 */
/* @0x284228 str r12, [sp, #0x2c] */
/* @0x28422c str r3, [sp, #0x30] */
/* @0x284230 str r4, [r0, #0x8] */
/* @0x284234 add r4, sp, #60 */
/* @0x284238 str r0, [sp, #0x8] */
/* @0x28423c b 0x284254 <spAtlas_create+0xe0> */
/* @0x284240 ldr r2, [sp, #0x44] */
/* @0x284244 ldr r3, [sp, #0x40] */
/* @0x284248 cmp r2, r3 */
/* @0x28424c bne 0x284278 <spAtlas_create+0x104> */
/* @0x284250 mov r11, #0 */
/* @0x284254 mov r0, r4 */
/* @0x284258 mov r1, r5 */
/* @0x28425c mov r2, r10 */
/* @0x284260 bl 0x283de8 <spAnimationStateData_getMix+0x140> */
/* @0x284264 cmp r0, #0 */
/* @0x284268 bne 0x284240 <spAtlas_create+0xcc> */
/* @0x28426c ldr r0, [sp, #0x8] */
/* @0x284270 add sp, sp, #108 */
/* @0x284274 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x284278 cmp r11, #0 */
/* @0x28427c beq 0x284654 <spAtlas_create+0x4e0> */
/* @0x284280 bl 0x2840d8 <spAtlasRegion_create> */
/* @0x284284 cmp r8, #0 */
/* @0x284288 ldreq r3, [sp, #0x8] */
/* @0x28428c strne r0, [r8, #0x4c] */
/* @0x284290 mov r6, r0 */
/* @0x284294 streq r0, [r3, #0x4] */
/* @0x284298 str r11, [r0, #0x48] */
/* @0x28429c mov r0, r10 */
/* @0x2842a0 bl 0x283fc8 <spAnimationStateData_getMix+0x320> */
/* @0x2842a4 mov r1, r5 */
/* @0x2842a8 mov r2, r10 */
/* @0x2842ac str r0, [r6] */
/* @0x2842b0 mov r0, r4 */
/* @0x2842b4 bl 0x283e7c <spAnimationStateData_getMix+0x1d4> */
/* @0x2842b8 cmp r0, #0 */
/* @0x2842bc beq 0x284830 <spAtlas_create+0x6bc> */
/* @0x2842c0 ldr r1, [sp, #0x40] */
/* @0x2842c4 add r7, sp, #72 */
/* @0x2842c8 ldr r2, [sp, #0x44] */
/* @0x2842cc ldr r0, [sp, #0x18] */
/* @0x2842d0 rsb r2, r1, r2 */
/* @0x2842d4 bl 0xb65e0 <strncmp@plt> */
/* @0x2842d8 mov r2, r7 */
/* @0x2842dc mov r1, r5 */
/* @0x2842e0 rsbs r0, r0, #1 */
/* @0x2842e4 movlo r0, #0 */
/* @0x2842e8 str r0, [r6, #0x38] */
/* @0x2842ec mov r0, r4 */
/* @0x2842f0 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x2842f4 cmp r0, #2 */
/* @0x2842f8 bne 0x284844 <spAtlas_create+0x6d0> */
/* @0x2842fc add r9, sp, #76 */
/* @0x284300 mov r2, #10 */
/* @0x284304 ldr r0, [sp, #0x48] */
/* @0x284308 add r8, sp, #84 */
/* @0x28430c mov r1, r9 */
/* @0x284310 bl 0xb6670 <strtol@plt> */
/* @0x284314 mov r1, r8 */
/* @0x284318 mov r2, #10 */
/* @0x28431c str r0, [r6, #0x4] */
/* @0x284320 ldr r0, [sp, #0x50] */
/* @0x284324 bl 0xb6670 <strtol@plt> */
/* @0x284328 mov r1, r5 */
/* @0x28432c mov r2, r7 */
/* @0x284330 str r0, [r6, #0x8] */
/* @0x284334 mov r0, r4 */
/* @0x284338 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x28433c cmp r0, #2 */
/* @0x284340 bne 0x284844 <spAtlas_create+0x6d0> */
/* @0x284344 mov r1, r9 */
/* @0x284348 mov r2, #10 */
/* @0x28434c ldr r0, [sp, #0x48] */
/* @0x284350 bl 0xb6670 <strtol@plt> */
/* @0x284354 mov r1, r8 */
/* @0x284358 mov r2, #10 */
/* @0x28435c str r0, [r6, #0xc] */
/* @0x284360 ldr r0, [sp, #0x50] */
/* @0x284364 bl 0xb6670 <strtol@plt> */
/* @0x284368 ldr r3, [r6, #0x4] */
/* @0x28436c ldr r2, [r6, #0x8] */
/* @0x284370 vldr s15, [r11, #32] */
/* @0x284374 vldr s14, [r11, #36] */
/* @0x284378 vcvt.f32.s32 s15, s15 */
/* @0x28437c vmov s11, r3 */
/* @0x284380 ldr r1, [r6, #0x38] */
/* @0x284384 cmp r1, #0 */
/* @0x284388 ldr r1, [r6, #0xc] */
/* @0x28438c vcvt.f32.s32 s12, s11 */
/* @0x284390 vmov s11, r2 */
/* @0x284394 vcvt.f32.s32 s14, s14 */
/* @0x284398 vcvt.f32.s32 s13, s11 */
/* @0x28439c vdiv.f32 s12, s12, s15 */
/* @0x2843a0 str r0, [r6, #0x10] */
/* @0x2843a4 vdiv.f32 s13, s13, s14 */
/* @0x2843a8 vstr s12, [r6, #20] */
/* @0x2843ac vstr s13, [r6, #24] */
/* @0x2843b0 bne 0x284490 <spAtlas_create+0x31c> */
/* @0x2843b4 add r0, r2, r0 */
/* @0x2843b8 add r3, r3, r1 */
/* @0x2843bc vmov s13, r0 */
/* @0x2843c0 vmov s11, r3 */
/* @0x2843c4 vcvt.f32.s32 s12, s13 */
/* @0x2843c8 vcvt.f32.s32 s13, s11 */
/* @0x2843cc vdiv.f32 s14, s12, s14 */
/* @0x2843d0 vdiv.f32 s15, s13, s15 */
/* @0x2843d4 vstr s14, [r6, #32] */
/* @0x2843d8 vstr s15, [r6, #28] */
/* @0x2843dc mov r0, r4 */
/* @0x2843e0 mov r1, r5 */
/* @0x2843e4 mov r2, r7 */
/* @0x2843e8 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x2843ec cmp r0, #0 */
/* @0x2843f0 beq 0x284638 <spAtlas_create+0x4c4> */
/* @0x2843f4 cmp r0, #4 */
/* @0x2843f8 beq 0x2844c8 <spAtlas_create+0x354> */
/* @0x2843fc mov r1, r9 */
/* @0x284400 mov r2, #10 */
/* @0x284404 ldr r0, [sp, #0x48] */
/* @0x284408 bl 0xb6670 <strtol@plt> */
/* @0x28440c mov r1, r8 */
/* @0x284410 mov r2, #10 */
/* @0x284414 str r0, [r6, #0x2c] */
/* @0x284418 ldr r0, [sp, #0x50] */
/* @0x28441c bl 0xb6670 <strtol@plt> */
/* @0x284420 mov r2, r7 */
/* @0x284424 mov r1, r5 */
/* @0x284428 str r0, [r6, #0x30] */
/* @0x28442c mov r0, r4 */
/* @0x284430 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x284434 mov r1, r9 */
/* @0x284438 mov r2, #10 */
/* @0x28443c ldr r0, [sp, #0x48] */
/* @0x284440 bl 0xb6670 <strtol@plt> */
/* @0x284444 mov r1, r8 */
/* @0x284448 mov r2, #10 */
/* @0x28444c str r0, [r6, #0x24] */
/* @0x284450 ldr r0, [sp, #0x50] */
/* @0x284454 bl 0xb6670 <strtol@plt> */
/* @0x284458 mov r1, r5 */
/* @0x28445c mov r2, r10 */
/* @0x284460 str r0, [r6, #0x28] */
/* @0x284464 mov r0, r4 */
/* @0x284468 bl 0x283e7c <spAnimationStateData_getMix+0x1d4> */
/* @0x28446c cmp r0, #0 */
/* @0x284470 beq 0x284830 <spAtlas_create+0x6bc> */
/* @0x284474 ldr r0, [sp, #0x40] */
/* @0x284478 add r1, sp, #68 */
/* @0x28447c mov r2, #10 */
/* @0x284480 mov r8, r6 */
/* @0x284484 bl 0xb6670 <strtol@plt> */
/* @0x284488 str r0, [r6, #0x34] */
/* @0x28448c b 0x284254 <spAtlas_create+0xe0> */
/* @0x284490 add r0, r3, r0 */
/* @0x284494 add r2, r2, r1 */
/* @0x284498 vmov s13, r0 */
/* @0x28449c vmov s11, r2 */
/* @0x2844a0 vcvt.f32.s32 s12, s13 */
/* @0x2844a4 vcvt.f32.s32 s13, s11 */
/* @0x2844a8 vdiv.f32 s15, s12, s15 */
/* @0x2844ac vdiv.f32 s14, s13, s14 */
/* @0x2844b0 vstr s15, [r6, #28] */
/* @0x2844b4 vstr s14, [r6, #32] */
/* @0x2844b8 b 0x2843dc <spAtlas_create+0x268> */
/* @0x2844bc mov r12, #0 */
/* @0x2844c0 str r12, [sp, #0x20] */
/* @0x2844c4 b 0x2841c0 <spAtlas_create+0x4c> */
/* @0x2844c8 ldr r1, [sp, #0x24] */
/* @0x2844cc movw r2, #0x10d */
/* @0x2844d0 mov r0, #16 */
/* @0x2844d4 add r3, sp, #92 */
/* @0x2844d8 str r3, [sp, #0x34] */
/* @0x2844dc bl 0x285c10 <_malloc> */
/* @0x2844e0 mov r1, r9 */
/* @0x2844e4 mov r2, #10 */
/* @0x2844e8 mov r3, r0 */
/* @0x2844ec str r0, [r6, #0x40] */
/* @0x2844f0 ldr r0, [sp, #0x48] */
/* @0x2844f4 str r3, [sp, #0x4] */
/* @0x2844f8 bl 0xb6670 <strtol@plt> */
/* @0x2844fc ldr r3, [sp, #0x4] */
/* @0x284500 mov r1, r8 */
/* @0x284504 ldr r12, [r6, #0x40] */
/* @0x284508 mov r2, #10 */
/* @0x28450c add lr, sp, #100 */
/* @0x284510 str lr, [sp, #0x38] */
/* @0x284514 str r0, [r3] */
/* @0x284518 ldr r0, [sp, #0x50] */
/* @0x28451c str r12, [sp, #0x4] */
/* @0x284520 bl 0xb6670 <strtol@plt> */
/* @0x284524 ldr r12, [sp, #0x4] */
/* @0x284528 add r1, sp, #92 */
/* @0x28452c ldr r3, [r6, #0x40] */
/* @0x284530 mov r2, #10 */
/* @0x284534 str r0, [r12, #0x4] */
/* @0x284538 ldr r0, [sp, #0x58] */
/* @0x28453c str r3, [sp, #0x4] */
/* @0x284540 bl 0xb6670 <strtol@plt> */
/* @0x284544 ldr r3, [sp, #0x4] */
/* @0x284548 add r1, sp, #100 */
/* @0x28454c ldr r12, [r6, #0x40] */
/* @0x284550 mov r2, #10 */
/* @0x284554 str r0, [r3, #0x8] */
/* @0x284558 ldr r0, [sp, #0x60] */
/* @0x28455c str r12, [sp, #0x4] */
/* @0x284560 bl 0xb6670 <strtol@plt> */
/* @0x284564 ldr r12, [sp, #0x4] */
/* @0x284568 mov r1, r5 */
/* @0x28456c mov r2, r7 */
/* @0x284570 str r0, [r12, #0xc] */
/* @0x284574 mov r0, r4 */
/* @0x284578 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x28457c cmp r0, #0 */
/* @0x284580 beq 0x284638 <spAtlas_create+0x4c4> */
/* @0x284584 cmp r0, #4 */
/* @0x284588 bne 0x2843fc <spAtlas_create+0x288> */
/* @0x28458c ldr r1, [sp, #0x24] */
/* @0x284590 movw r2, #0x115 */
/* @0x284594 mov r0, #16 */
/* @0x284598 bl 0x285c10 <_malloc> */
/* @0x28459c mov r1, r9 */
/* @0x2845a0 mov r2, #10 */
/* @0x2845a4 mov r3, r0 */
/* @0x2845a8 str r0, [r6, #0x44] */
/* @0x2845ac ldr r0, [sp, #0x48] */
/* @0x2845b0 str r3, [sp, #0x4] */
/* @0x2845b4 bl 0xb6670 <strtol@plt> */
/* @0x2845b8 ldr r3, [sp, #0x4] */
/* @0x2845bc mov r1, r8 */
/* @0x2845c0 ldr r12, [r6, #0x44] */
/* @0x2845c4 mov r2, #10 */
/* @0x2845c8 str r0, [r3] */
/* @0x2845cc ldr r0, [sp, #0x50] */
/* @0x2845d0 str r12, [sp, #0x4] */
/* @0x2845d4 bl 0xb6670 <strtol@plt> */
/* @0x2845d8 ldr r12, [sp, #0x4] */
/* @0x2845dc add r1, sp, #92 */
/* @0x2845e0 ldr r3, [r6, #0x44] */
/* @0x2845e4 mov r2, #10 */
/* @0x2845e8 str r0, [r12, #0x4] */
/* @0x2845ec ldr r0, [sp, #0x58] */
/* @0x2845f0 str r3, [sp, #0x4] */
/* @0x2845f4 bl 0xb6670 <strtol@plt> */
/* @0x2845f8 ldr r3, [sp, #0x4] */
/* @0x2845fc add r1, sp, #100 */
/* @0x284600 ldr r12, [r6, #0x44] */
/* @0x284604 mov r2, #10 */
/* @0x284608 str r0, [r3, #0x8] */
/* @0x28460c ldr r0, [sp, #0x60] */
/* @0x284610 str r12, [sp, #0x4] */
/* @0x284614 bl 0xb6670 <strtol@plt> */
/* @0x284618 ldr r12, [sp, #0x4] */
/* @0x28461c mov r1, r5 */
/* @0x284620 mov r2, r7 */
/* @0x284624 str r0, [r12, #0xc] */
/* @0x284628 mov r0, r4 */
/* @0x28462c bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x284630 cmp r0, #0 */
/* @0x284634 bne 0x2843fc <spAtlas_create+0x288> */
/* @0x284638 mov r3, r0 */
/* @0x28463c ldr r0, [sp, #0x8] */
/* @0x284640 str r3, [sp, #0x4] */
/* @0x284644 bl 0x284120 <spAtlas_dispose> */
/* @0x284648 ldr r3, [sp, #0x4] */
/* @0x28464c mov r0, r3 */
/* @0x284650 b 0x284270 <spAtlas_create+0xfc> */
/* @0x284654 ldr lr, [sp, #0x14] */
/* @0x284658 mov r0, r10 */
/* @0x28465c ldr r12, [sp, #0x20] */
/* @0x284660 add r7, r12, lr */
/* @0x284664 bl 0x283fc8 <spAnimationStateData_getMix+0x320> */
/* @0x284668 mov r6, r0 */
/* @0x28466c bl 0xb6538 <strlen@plt> */
/* @0x284670 add r3, r7, #1 */
/* @0x284674 ldr r1, [sp, #0x2c] */
/* @0x284678 mov r2, #190 */
/* @0x28467c add r0, r3, r0 */
/* @0x284680 bl 0x285c10 <_malloc> */
/* @0x284684 ldr r2, [sp, #0x14] */
/* @0x284688 ldr r1, [sp, #0xc] */
/* @0x28468c mov r9, r0 */
/* @0x284690 bl 0xb65bc <memcpy@plt> */
/* @0x284694 ldr r12, [sp, #0x20] */
/* @0x284698 add r0, r9, r7 */
/* @0x28469c mov r1, r6 */
/* @0x2846a0 add r7, sp, #72 */
/* @0x2846a4 cmp r12, #0 */
/* @0x2846a8 ldrne r12, [sp, #0x14] */
/* @0x2846ac movne r3, #47 */
/* @0x2846b0 strbne r3, [r9, r12] */
/* @0x2846b4 bl 0xb65a4 <strcpy@plt> */
/* @0x2846b8 mov r1, r6 */
/* @0x2846bc ldr r0, [sp, #0x8] */
/* @0x2846c0 bl 0x284058 <spAtlasPage_create> */
/* @0x2846c4 mov r11, r0 */
/* @0x2846c8 mov r0, r6 */
/* @0x2846cc bl 0x285c80 <_free> */
/* @0x2846d0 ldr r3, [sp, #0x1c] */
/* @0x2846d4 mov r0, r4 */
/* @0x2846d8 mov r1, r5 */
/* @0x2846dc cmp r3, #0 */
/* @0x2846e0 mov r2, r7 */
/* @0x2846e4 strne r11, [r3, #0x28] */
/* @0x2846e8 ldreq r12, [sp, #0x8] */
/* @0x2846ec streq r11, [r12] */
/* @0x2846f0 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x2846f4 cmp r0, #0 */
/* @0x2846f8 beq 0x28481c <spAtlas_create+0x6a8> */
/* @0x2846fc cmp r0, #2 */
/* @0x284700 beq 0x2847dc <spAtlas_create+0x668> */
/* @0x284704 ldr r0, [sp, #0x10] */
/* @0x284708 mov r1, r7 */
/* @0x28470c bl 0x284010 <spAnimationStateData_getMix+0x368> */
/* @0x284710 mov r1, r5 */
/* @0x284714 mov r2, r7 */
/* @0x284718 str r0, [r11, #0x8] */
/* @0x28471c mov r0, r4 */
/* @0x284720 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x284724 cmp r0, #0 */
/* @0x284728 beq 0x28481c <spAtlas_create+0x6a8> */
/* @0x28472c mov r1, r7 */
/* @0x284730 ldr r0, [sp, #0x28] */
/* @0x284734 bl 0x284010 <spAnimationStateData_getMix+0x368> */
/* @0x284738 add r1, sp, #80 */
/* @0x28473c str r0, [r11, #0xc] */
/* @0x284740 ldr r0, [sp, #0x28] */
/* @0x284744 bl 0x284010 <spAnimationStateData_getMix+0x368> */
/* @0x284748 mov r1, r5 */
/* @0x28474c mov r2, r10 */
/* @0x284750 str r0, [r11, #0x10] */
/* @0x284754 mov r0, r4 */
/* @0x284758 bl 0x283e7c <spAnimationStateData_getMix+0x1d4> */
/* @0x28475c cmp r0, #0 */
/* @0x284760 beq 0x284830 <spAtlas_create+0x6bc> */
/* @0x284764 ldr r6, [sp, #0x40] */
/* @0x284768 mov r3, #1 */
/* @0x28476c ldr r7, [sp, #0x44] */
/* @0x284770 ldr r0, [sp, #0x30] */
/* @0x284774 rsb r7, r6, r7 */
/* @0x284778 str r3, [r11, #0x14] */
/* @0x28477c mov r1, r6 */
/* @0x284780 str r3, [r11, #0x18] */
/* @0x284784 mov r2, r7 */
/* @0x284788 bl 0xb65e0 <strncmp@plt> */
/* @0x28478c cmp r0, #0 */
/* @0x284790 beq 0x2847c0 <spAtlas_create+0x64c> */
/* @0x284794 cmp r7, #1 */
/* @0x284798 beq 0x284854 <spAtlas_create+0x6e0> */
/* @0x28479c ldr r0, [pc, #0xec] */
/* @0x2847a0 mov r1, r6 */
/* @0x2847a4 mov r2, r7 */
/* @0x2847a8 add r0, pc, r0 */
/* @0x2847ac bl 0xb65e0 <strncmp@plt> */
/* @0x2847b0 cmp r0, #0 */
/* @0x2847b4 moveq r3, #2 */
/* @0x2847b8 streq r3, [r11, #0x14] */
/* @0x2847bc streq r3, [r11, #0x18] */
/* @0x2847c0 mov r0, r11 */
/* @0x2847c4 mov r1, r9 */
/* @0x2847c8 bl 0xbd6e4 <_spAtlasPage_createTexture> */
/* @0x2847cc mov r0, r9 */
/* @0x2847d0 bl 0x285c80 <_free> */
/* @0x2847d4 str r11, [sp, #0x1c] */
/* @0x2847d8 b 0x284254 <spAtlas_create+0xe0> */
/* @0x2847dc add r1, sp, #76 */
/* @0x2847e0 mov r2, #10 */
/* @0x2847e4 ldr r0, [sp, #0x48] */
/* @0x2847e8 bl 0xb6670 <strtol@plt> */
/* @0x2847ec add r1, sp, #84 */
/* @0x2847f0 mov r2, #10 */
/* @0x2847f4 str r0, [r11, #0x20] */
/* @0x2847f8 ldr r0, [sp, #0x50] */
/* @0x2847fc bl 0xb6670 <strtol@plt> */
/* @0x284800 mov r1, r5 */
/* @0x284804 mov r2, r7 */
/* @0x284808 str r0, [r11, #0x24] */
/* @0x28480c mov r0, r4 */
/* @0x284810 bl 0x283ed0 <spAnimationStateData_getMix+0x228> */
/* @0x284814 cmp r0, #0 */
/* @0x284818 bne 0x284704 <spAtlas_create+0x590> */
/* @0x28481c mov r9, r0 */
/* @0x284820 ldr r0, [sp, #0x8] */
/* @0x284824 bl 0x284120 <spAtlas_dispose> */
/* @0x284828 mov r0, r9 */
/* @0x28482c b 0x284270 <spAtlas_create+0xfc> */
/* @0x284830 mov r7, r0 */
/* @0x284834 ldr r0, [sp, #0x8] */
/* @0x284838 bl 0x284120 <spAtlas_dispose> */
/* @0x28483c mov r0, r7 */
/* @0x284840 b 0x284270 <spAtlas_create+0xfc> */
/* @0x284844 ldr r0, [sp, #0x8] */
/* @0x284848 bl 0x284120 <spAtlas_dispose> */
/* @0x28484c mov r0, #0 */
/* @0x284850 b 0x284270 <spAtlas_create+0xfc> */
/* @0x284854 ldrb r3, [r6] */
/* @0x284858 cmp r3, #120 */
/* @0x28485c moveq r3, #2 */
/* @0x284860 streq r3, [r11, #0x14] */
/* @0x284864 beq 0x2847c0 <spAtlas_create+0x64c> */
/* @0x284868 cmp r3, #121 */
/* @0x28486c moveq r3, #2 */
/* @0x284870 streq r3, [r11, #0x18] */
/* @0x284874 b 0x2847c0 <spAtlas_create+0x64c> */
/* @0x284878 andeq r3, sp, r0, lsr r3 */
/* @0x28487c andseq r3, r7, r0, ror r5 */
/* @0x284880 andeq r0, r11, r4, lsr #16 */
/* @0x284884 strdeq r3, r4, [sp], -r12 */
/* @0x284888 andeq r3, sp, r8, ror #5 */
/* @0x28488c andeq r3, sp, r4, lsl r3 */
/* @0x284890 muleq sp, r8, sp */

/* ── FUNC 0x284894 · spAtlas_createFromFile · size=196 · insn=49 */
/* @0x284894 push {r4, r5, r6, r7, lr} */
/* @0x284898 mov r7, r1 */
/* @0x28489c sub sp, sp, #12 */
/* @0x2848a0 mov r1, #47 */
/* @0x2848a4 mov r4, r0 */
/* @0x2848a8 bl 0xb6868 <strrchr@plt> */
/* @0x2848ac mov r1, #92 */
/* @0x2848b0 mov r5, r0 */
/* @0x2848b4 mov r0, r4 */
/* @0x2848b8 bl 0xb6868 <strrchr@plt> */
/* @0x2848bc ldr r1, [pc, #0x90] */
/* @0x2848c0 mov r2, #316 */
/* @0x2848c4 add r1, pc, r1 */
/* @0x2848c8 cmp r5, r0 */
/* @0x2848cc movhs r0, r5 */
/* @0x2848d0 cmp r0, r4 */
/* @0x2848d4 addeq r0, r0, #1 */
/* @0x2848d8 cmp r0, #0 */
/* @0x2848dc rsbne r6, r4, r0 */
/* @0x2848e0 moveq r6, r0 */
/* @0x2848e4 addne r0, r6, #1 */
/* @0x2848e8 moveq r0, #1 */
/* @0x2848ec bl 0x285c10 <_malloc> */
/* @0x2848f0 mov r1, r4 */
/* @0x2848f4 mov r2, r6 */
/* @0x2848f8 mov r5, r0 */
/* @0x2848fc bl 0xb65bc <memcpy@plt> */
/* @0x284900 mov r0, r4 */
/* @0x284904 mov r3, #0 */
/* @0x284908 add r1, sp, #4 */
/* @0x28490c strb r3, [r5, r6] */
/* @0x284910 bl 0xbd83c <_spUtil_readFile> */
/* @0x284914 subs r4, r0, #0 */
/* @0x284918 beq 0x28494c <spAtlas_createFromFile+0xb8> */
/* @0x28491c mov r3, r7 */
/* @0x284920 ldr r1, [sp, #0x4] */
/* @0x284924 mov r2, r5 */
/* @0x284928 bl 0x284174 <spAtlas_create> */
/* @0x28492c mov r6, r0 */
/* @0x284930 mov r0, r4 */
/* @0x284934 bl 0x285c80 <_free> */
/* @0x284938 mov r0, r5 */
/* @0x28493c bl 0x285c80 <_free> */
/* @0x284940 mov r0, r6 */
/* @0x284944 add sp, sp, #12 */
/* @0x284948 pop {r4, r5, r6, r7, pc} */
/* @0x28494c mov r6, r4 */
/* @0x284950 b 0x284930 <spAtlas_createFromFile+0x9c> */
/* @0x284954 andeq r2, sp, r0, asr #24 */

/* ── FUNC 0x284958 · spAtlas_findRegion · size=176 · insn=44 */
/* @0x284958 push {r4, r5, r6, lr} */
/* @0x28495c mov r4, r1 */
/* @0x284960 ldr r5, [r0, #0x4] */
/* @0x284964 cmp r5, #0 */
/* @0x284968 beq 0x2849d0 <spAtlas_findRegion+0x78> */
/* @0x28496c ldr r6, [r5] */
/* @0x284970 mov r1, r4 */
/* @0x284974 mov r0, r6 */
/* @0x284978 bl 0xb6574 <strcmp@plt> */
/* @0x28497c cmp r0, #0 */
/* @0x284980 beq 0x2849d0 <spAtlas_findRegion+0x78> */
/* @0x284984 cmp r4, #0 */
/* @0x284988 beq 0x2849c4 <spAtlas_findRegion+0x6c> */
/* @0x28498c mov r0, r4 */
/* @0x284990 bl 0xb6538 <strlen@plt> */
/* @0x284994 subs r0, r0, #1 */
/* @0x284998 bmi 0x2849c4 <spAtlas_findRegion+0x6c> */
/* @0x28499c ldrb r3, [r4, r0] */
/* @0x2849a0 cmp r3, #47 */
/* @0x2849a4 movne r3, r0 */
/* @0x2849a8 bne 0x2849bc <spAtlas_findRegion+0x64> */
/* @0x2849ac b 0x2849c4 <spAtlas_findRegion+0x6c> */
/* @0x2849b0 ldrb r2, [r4, r3] */
/* @0x2849b4 cmp r2, #47 */
/* @0x2849b8 beq 0x2849d8 <spAtlas_findRegion+0x80> */
/* @0x2849bc subs r3, r3, #1 */
/* @0x2849c0 bhs 0x2849b0 <spAtlas_findRegion+0x58> */
/* @0x2849c4 ldr r5, [r5, #0x4c] */
/* @0x2849c8 cmp r5, #0 */
/* @0x2849cc bne 0x28496c <spAtlas_findRegion+0x14> */
/* @0x2849d0 mov r0, r5 */
/* @0x2849d4 pop {r4, r5, r6, pc} */
/* @0x2849d8 cmp r0, r3 */
/* @0x2849dc beq 0x2849c4 <spAtlas_findRegion+0x6c> */
/* @0x2849e0 add r1, r3, #1 */
/* @0x2849e4 mov r0, r6 */
/* @0x2849e8 add r1, r4, r1 */
/* @0x2849ec bl 0xb6574 <strcmp@plt> */
/* @0x2849f0 cmp r0, #0 */
/* @0x2849f4 beq 0x2849d0 <spAtlas_findRegion+0x78> */
/* @0x2849f8 ldr r5, [r5, #0x4c] */
/* @0x2849fc cmp r5, #0 */
/* @0x284a00 bne 0x28496c <spAtlas_findRegion+0x14> */
/* @0x284a04 b 0x2849d0 <spAtlas_findRegion+0x78> */

/* ── FUNC 0x284a08 · _spAtlasAttachmentLoader_createAttachment · size=428 · insn=107 */
/* @0x284a08 push {r4, r5, r6, r7, r8, lr} */
/* @0x284a0c mov r6, r0 */
/* @0x284a10 sub sp, sp, #8 */
/* @0x284a14 mov r5, r3 */
/* @0x284a18 cmp r2, #4 */
/* @0x284a1c addls pc, pc, r2, lsl #2 */
/* @0x284a20 b 0x284b60 <_spAtlasAttachmentLoader_createAttachment+0x158> */
/* @0x284a24 b 0x284ae0 <_spAtlasAttachmentLoader_createAttachment+0xd8> */
/* @0x284a28 b 0x284ad0 <_spAtlasAttachmentLoader_createAttachment+0xc8> */
/* @0x284a2c b 0x284a48 <_spAtlasAttachmentLoader_createAttachment+0x40> */
/* @0x284a30 b 0x284a48 <_spAtlasAttachmentLoader_createAttachment+0x40> */
/* @0x284a34 b 0x284a38 <_spAtlasAttachmentLoader_createAttachment+0x30> */
/* @0x284a38 mov r0, r3 */
/* @0x284a3c bl 0x2876f4 <spPathAttachment_create> */
/* @0x284a40 add sp, sp, #8 */
/* @0x284a44 pop {r4, r5, r6, r7, r8, pc} */
/* @0x284a48 ldr r0, [r0, #0xc] */
/* @0x284a4c ldr r1, [sp, #0x20] */
/* @0x284a50 bl 0x284958 <spAtlas_findRegion> */
/* @0x284a54 subs r4, r0, #0 */
/* @0x284a58 beq 0x284b90 <_spAtlasAttachmentLoader_createAttachment+0x188> */
/* @0x284a5c mov r0, r5 */
/* @0x284a60 bl 0x2874dc <spMeshAttachment_create> */
/* @0x284a64 ldr r2, [r4, #0x14] */
/* @0x284a68 ldr r7, [r4, #0x24] */
/* @0x284a6c ldr r6, [r4, #0x28] */
/* @0x284a70 ldr r5, [r4, #0xc] */
/* @0x284a74 ldr r12, [r4, #0x10] */
/* @0x284a78 ldr r1, [r4, #0x2c] */
/* @0x284a7c ldr r8, [r4, #0x20] */
/* @0x284a80 mov r3, r0 */
/* @0x284a84 ldr r0, [r4, #0x38] */
/* @0x284a88 str r2, [r3, #0x40] */
/* @0x284a8c ldr r2, [r4, #0x18] */
/* @0x284a90 str r2, [r3, #0x44] */
/* @0x284a94 ldr r2, [r4, #0x1c] */
/* @0x284a98 str r2, [r3, #0x48] */
/* @0x284a9c ldr r2, [r4, #0x30] */
/* @0x284aa0 str r0, [r3, #0x50] */
/* @0x284aa4 mov r0, r3 */
/* @0x284aa8 str r4, [r3, #0x24] */
/* @0x284aac str r8, [r3, #0x4c] */
/* @0x284ab0 str r7, [r3, #0x28] */
/* @0x284ab4 str r6, [r3, #0x2c] */
/* @0x284ab8 str r5, [r3, #0x30] */
/* @0x284abc str r12, [r3, #0x34] */
/* @0x284ac0 str r1, [r3, #0x38] */
/* @0x284ac4 str r2, [r3, #0x3c] */
/* @0x284ac8 add sp, sp, #8 */
/* @0x284acc pop {r4, r5, r6, r7, r8, pc} */
/* @0x284ad0 mov r0, r3 */
/* @0x284ad4 bl 0x285af8 <spBoundingBoxAttachment_create> */
/* @0x284ad8 add sp, sp, #8 */
/* @0x284adc pop {r4, r5, r6, r7, r8, pc} */
/* @0x284ae0 ldr r0, [r0, #0xc] */
/* @0x284ae4 ldr r1, [sp, #0x20] */
/* @0x284ae8 bl 0x284958 <spAtlas_findRegion> */
/* @0x284aec subs r4, r0, #0 */
/* @0x284af0 beq 0x284b74 <_spAtlasAttachmentLoader_createAttachment+0x16c> */
/* @0x284af4 mov r0, r5 */
/* @0x284af8 bl 0x288f78 <spRegionAttachment_create> */
/* @0x284afc ldr r12, [r4, #0x20] */
/* @0x284b00 ldr r1, [r4, #0x14] */
/* @0x284b04 ldr r2, [r4, #0x18] */
/* @0x284b08 ldr r3, [r4, #0x1c] */
/* @0x284b0c str r4, [r0, #0x40] */
/* @0x284b10 mov r5, r0 */
/* @0x284b14 str r12, [sp] */
/* @0x284b18 ldr r12, [r4, #0x38] */
/* @0x284b1c str r12, [sp, #0x4] */
/* @0x284b20 bl 0x288fdc <spRegionAttachment_setUVs> */
/* @0x284b24 ldr r7, [r4, #0x24] */
/* @0x284b28 ldr r6, [r4, #0x28] */
/* @0x284b2c mov r0, r5 */
/* @0x284b30 ldr r12, [r4, #0xc] */
/* @0x284b34 ldr r1, [r4, #0x10] */
/* @0x284b38 ldr r2, [r4, #0x2c] */
/* @0x284b3c ldr r3, [r4, #0x30] */
/* @0x284b40 str r7, [r5, #0x44] */
/* @0x284b44 str r6, [r5, #0x48] */
/* @0x284b48 str r12, [r5, #0x4c] */
/* @0x284b4c str r1, [r5, #0x50] */
/* @0x284b50 str r2, [r5, #0x54] */
/* @0x284b54 str r3, [r5, #0x58] */
/* @0x284b58 add sp, sp, #8 */
/* @0x284b5c pop {r4, r5, r6, r7, r8, pc} */
/* @0x284b60 mov r1, r2 */
/* @0x284b64 bl 0x284e68 <_spAttachmentLoader_setUnknownTypeError> */
/* @0x284b68 mov r0, #0 */
/* @0x284b6c add sp, sp, #8 */
/* @0x284b70 pop {r4, r5, r6, r7, r8, pc} */
/* @0x284b74 ldr r1, [pc, #0x30] */
/* @0x284b78 mov r0, r6 */
/* @0x284b7c ldr r2, [sp, #0x20] */
/* @0x284b80 add r1, pc, r1 */
/* @0x284b84 bl 0x284df0 <_spAttachmentLoader_setError> */
/* @0x284b88 mov r0, r4 */
/* @0x284b8c b 0x284a40 <_spAtlasAttachmentLoader_createAttachment+0x38> */
/* @0x284b90 ldr r1, [pc, #0x18] */
/* @0x284b94 mov r0, r6 */
/* @0x284b98 ldr r2, [sp, #0x20] */
/* @0x284b9c add r1, pc, r1 */
/* @0x284ba0 bl 0x284df0 <_spAttachmentLoader_setError> */
/* @0x284ba4 mov r0, r4 */
/* @0x284ba8 b 0x284a40 <_spAtlasAttachmentLoader_createAttachment+0x38> */
/* @0x284bac andeq r2, sp, r12, ror r10 */
/* @0x284bb0 andeq r2, sp, r0, ror #20 */

/* ── FUNC 0x284bb4 · spAtlasAttachmentLoader_create · size=100 · insn=25 */
/* @0x284bb4 ldr r2, [pc, #0x50] */
/* @0x284bb8 mov r1, #16 */
/* @0x284bbc push {r4, r5, lr} */
/* @0x284bc0 add r2, pc, r2 */
/* @0x284bc4 sub sp, sp, #12 */
/* @0x284bc8 mov r5, r0 */
/* @0x284bcc mov r3, #93 */
/* @0x284bd0 mov r0, #1 */
/* @0x284bd4 bl 0x285c4c <_calloc> */
/* @0x284bd8 ldr r1, [pc, #0x30] */
/* @0x284bdc ldr r2, [pc, #0x30] */
/* @0x284be0 mov r12, #0 */
/* @0x284be4 mov r3, r12 */
/* @0x284be8 ldr r1, [pc, r1] */
/* @0x284bec str r12, [sp] */
/* @0x284bf0 ldr r2, [pc, r2] */
/* @0x284bf4 mov r4, r0 */
/* @0x284bf8 bl 0x284cc8 <_spAttachmentLoader_init> */
/* @0x284bfc mov r0, r4 */
/* @0x284c00 str r5, [r4, #0xc] */
/* @0x284c04 add sp, sp, #12 */
/* @0x284c08 pop {r4, r5, pc} */
/* @0x284c0c andeq r2, sp, r0, asr r10 */
/* @0x284c10 andseq r12, r6, r12, lsl #26 */
/* @0x284c14 andseq r12, r6, r8, lsl #26 */

/* ── FUNC 0x284c18 · _spAttachment_init · size=108 · insn=27 */
/* @0x284c18 push {r4, r5, r6, r7, r8, lr} */
/* @0x284c1c mov r4, r0 */
/* @0x284c20 ldr r6, [pc, #0x58] */
/* @0x284c24 mov r5, r1 */
/* @0x284c28 mov r7, r2 */
/* @0x284c2c mov r8, r3 */
/* @0x284c30 add r6, pc, r6 */
/* @0x284c34 mov r3, #43 */
/* @0x284c38 mov r1, #4 */
/* @0x284c3c mov r0, #1 */
/* @0x284c40 mov r2, r6 */
/* @0x284c44 bl 0x285c4c <_calloc> */
/* @0x284c48 mov r1, r0 */
/* @0x284c4c mov r0, r5 */
/* @0x284c50 str r1, [r4, #0x8] */
/* @0x284c54 str r8, [r1] */
/* @0x284c58 bl 0xb6538 <strlen@plt> */
/* @0x284c5c mov r1, r6 */
/* @0x284c60 mov r2, #46 */
/* @0x284c64 add r0, r0, #1 */
/* @0x284c68 bl 0x285c10 <_malloc> */
/* @0x284c6c mov r1, r5 */
/* @0x284c70 str r0, [r4] */
/* @0x284c74 bl 0xb65a4 <strcpy@plt> */
/* @0x284c78 str r7, [r4, #0x4] */
/* @0x284c7c pop {r4, r5, r6, r7, r8, pc} */
/* @0x284c80 andeq r2, sp, r4, lsr #20 */

/* ── FUNC 0x284c84 · _spAttachment_deinit · size=48 · insn=12 */
/* @0x284c84 push {r4, lr} */
/* @0x284c88 mov r4, r0 */
/* @0x284c8c ldr r0, [r0, #0xc] */
/* @0x284c90 cmp r0, #0 */
/* @0x284c94 beq 0x284ca0 <_spAttachment_deinit+0x1c> */
/* @0x284c98 mov r1, r4 */
/* @0x284c9c bl 0x284dd4 <spAttachmentLoader_disposeAttachment> */
/* @0x284ca0 ldr r0, [r4, #0x8] */
/* @0x284ca4 bl 0x285c80 <_free> */
/* @0x284ca8 ldr r0, [r4] */
/* @0x284cac pop {r4, lr} */
/* @0x284cb0 b 0x285c80 <_free> */

/* ── FUNC 0x284cb4 · spAttachment_dispose · size=20 · insn=5 */
/* @0x284cb4 push {r3, lr} */
/* @0x284cb8 ldr r3, [r0, #0x8] */
/* @0x284cbc ldr r3, [r3] */
/* @0x284cc0 blx r3 */
/* @0x284cc4 pop {r3, pc} */

/* ── FUNC 0x284cc8 · _spAttachmentLoader_init · size=76 · insn=19 */
/* @0x284cc8 push {r4, r5, r6, r7, r8, lr} */
/* @0x284ccc mov r6, r2 */
/* @0x284cd0 ldr r2, [pc, #0x38] */
/* @0x284cd4 mov r8, r0 */
/* @0x284cd8 mov r7, r1 */
/* @0x284cdc mov r5, r3 */
/* @0x284ce0 mov r0, #1 */
/* @0x284ce4 mov r1, #16 */
/* @0x284ce8 add r2, pc, r2 */
/* @0x284cec mov r3, #51 */
/* @0x284cf0 ldr r4, [sp, #0x18] */
/* @0x284cf4 bl 0x285c4c <_calloc> */
/* @0x284cf8 str r0, [r8, #0x8] */
/* @0x284cfc str r7, [r0, #0xc] */
/* @0x284d00 str r6, [r0] */
/* @0x284d04 str r5, [r0, #0x4] */
/* @0x284d08 str r4, [r0, #0x8] */
/* @0x284d0c pop {r4, r5, r6, r7, r8, pc} */
/* @0x284d10 andeq r2, sp, r4, lsr #19 */

/* ── FUNC 0x284d14 · _spAttachmentLoader_deinit · size=36 · insn=9 */
/* @0x284d14 push {r4, lr} */
/* @0x284d18 mov r4, r0 */
/* @0x284d1c ldr r0, [r0, #0x8] */
/* @0x284d20 bl 0x285c80 <_free> */
/* @0x284d24 ldr r0, [r4] */
/* @0x284d28 bl 0x285c80 <_free> */
/* @0x284d2c ldr r0, [r4, #0x4] */
/* @0x284d30 pop {r4, lr} */
/* @0x284d34 b 0x285c80 <_free> */

/* ── FUNC 0x284d38 · spAttachmentLoader_dispose · size=32 · insn=8 */
/* @0x284d38 ldr r3, [r0, #0x8] */
/* @0x284d3c push {r4, lr} */
/* @0x284d40 mov r4, r0 */
/* @0x284d44 ldr r3, [r3, #0xc] */
/* @0x284d48 blx r3 */
/* @0x284d4c mov r0, r4 */
/* @0x284d50 pop {r4, lr} */
/* @0x284d54 b 0x285c80 <_free> */

/* ── FUNC 0x284d58 · spAttachmentLoader_createAttachment · size=96 · insn=24 */
/* @0x284d58 push {r4, r5, r6, r7, r8, lr} */
/* @0x284d5c sub sp, sp, #8 */
/* @0x284d60 mov r4, r0 */
/* @0x284d64 ldr r0, [r0] */
/* @0x284d68 mov r8, r1 */
/* @0x284d6c mov r7, r2 */
/* @0x284d70 mov r6, r3 */
/* @0x284d74 ldr r5, [sp, #0x20] */
/* @0x284d78 bl 0x285c80 <_free> */
/* @0x284d7c ldr r0, [r4, #0x4] */
/* @0x284d80 bl 0x285c80 <_free> */
/* @0x284d84 ldr r0, [r4, #0x8] */
/* @0x284d88 mov r12, #0 */
/* @0x284d8c str r5, [sp] */
/* @0x284d90 mov r1, r8 */
/* @0x284d94 mov r2, r7 */
/* @0x284d98 ldr r5, [r0] */
/* @0x284d9c mov r3, r6 */
/* @0x284da0 mov r0, r4 */
/* @0x284da4 str r12, [r4] */
/* @0x284da8 str r12, [r4, #0x4] */
/* @0x284dac blx r5 */
/* @0x284db0 add sp, sp, #8 */
/* @0x284db4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x284db8 · spAttachmentLoader_configureAttachment · size=28 · insn=7 */
/* @0x284db8 push {r3, lr} */
/* @0x284dbc ldr r3, [r0, #0x8] */
/* @0x284dc0 ldr r3, [r3, #0x4] */
/* @0x284dc4 cmp r3, #0 */
/* @0x284dc8 popeq {r3, pc} */
/* @0x284dcc blx r3 */
/* @0x284dd0 pop {r3, pc} */

/* ── FUNC 0x284dd4 · spAttachmentLoader_disposeAttachment · size=28 · insn=7 */
/* @0x284dd4 push {r3, lr} */
/* @0x284dd8 ldr r3, [r0, #0x8] */
/* @0x284ddc ldr r3, [r3, #0x8] */
/* @0x284de0 cmp r3, #0 */
/* @0x284de4 popeq {r3, pc} */
/* @0x284de8 blx r3 */
/* @0x284dec pop {r3, pc} */

/* ── FUNC 0x284df0 · _spAttachmentLoader_setError · size=120 · insn=30 */
/* @0x284df0 push {r3, r4, r5, r6, r7, lr} */
/* @0x284df4 mov r4, r0 */
/* @0x284df8 ldr r0, [r0] */
/* @0x284dfc mov r6, r1 */
/* @0x284e00 mov r5, r2 */
/* @0x284e04 bl 0x285c80 <_free> */
/* @0x284e08 ldr r0, [r4, #0x4] */
/* @0x284e0c bl 0x285c80 <_free> */
/* @0x284e10 mov r0, r6 */
/* @0x284e14 bl 0xb6538 <strlen@plt> */
/* @0x284e18 ldr r7, [pc, #0x44] */
/* @0x284e1c mov r2, #91 */
/* @0x284e20 add r7, pc, r7 */
/* @0x284e24 mov r1, r7 */
/* @0x284e28 add r0, r0, #1 */
/* @0x284e2c bl 0x285c10 <_malloc> */
/* @0x284e30 mov r1, r6 */
/* @0x284e34 str r0, [r4] */
/* @0x284e38 bl 0xb65a4 <strcpy@plt> */
/* @0x284e3c mov r0, r5 */
/* @0x284e40 bl 0xb6538 <strlen@plt> */
/* @0x284e44 mov r1, r7 */
/* @0x284e48 mov r2, #92 */
/* @0x284e4c add r0, r0, #1 */
/* @0x284e50 bl 0x285c10 <_malloc> */
/* @0x284e54 mov r1, r5 */
/* @0x284e58 str r0, [r4, #0x4] */
/* @0x284e5c pop {r3, r4, r5, r6, r7, lr} */
/* @0x284e60 b 0xb65a4 <strcpy@plt> */
/* @0x284e64 andeq r2, sp, r12, ror #16 */

/* ── FUNC 0x284e68 · _spAttachmentLoader_setUnknownTypeError · size=112 · insn=28 */
/* @0x284e68 push {r4, r5, r6, lr} */
/* @0x284e6c sub sp, sp, #24 */
/* @0x284e70 ldr r4, [pc, #0x54] */
/* @0x284e74 mov r2, r1 */
/* @0x284e78 add r5, sp, #4 */
/* @0x284e7c ldr r1, [pc, #0x4c] */
/* @0x284e80 ldr r4, [pc, r4] */
/* @0x284e84 mov r6, r0 */
/* @0x284e88 add r1, pc, r1 */
/* @0x284e8c mov r0, r5 */
/* @0x284e90 ldr r3, [r4] */
/* @0x284e94 str r3, [sp, #0x14] */
/* @0x284e98 bl 0xb6550 <sprintf@plt> */
/* @0x284e9c ldr r1, [pc, #0x30] */
/* @0x284ea0 mov r2, r5 */
/* @0x284ea4 mov r0, r6 */
/* @0x284ea8 add r1, pc, r1 */
/* @0x284eac bl 0x284df0 <_spAttachmentLoader_setError> */
/* @0x284eb0 ldr r2, [sp, #0x14] */
/* @0x284eb4 ldr r3, [r4] */
/* @0x284eb8 cmp r2, r3 */
/* @0x284ebc bne 0x284ec8 <_spAttachmentLoader_setUnknownTypeError+0x60> */
/* @0x284ec0 add sp, sp, #24 */
/* @0x284ec4 pop {r4, r5, r6, pc} */
/* @0x284ec8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x284ecc ldrsbeq r8, [r6], -r0 */
/* @0x284ed0 andeq sp, r10, r4, lsl #13 */
/* @0x284ed4 andeq r2, sp, r4, lsr #16 */

/* ── FUNC 0x284ed8 · spBone_setYDown · size=20 · insn=5 */
/* @0x284ed8 ldr r3, [pc, #0x8] */
/* @0x284edc add r3, pc, r3 */
/* @0x284ee0 str r0, [r3] */
/* @0x284ee4 bx lr */
/* @0x284ee8 ldrdeq r1, r2, [sp], #-204 */

/* ── FUNC 0x284eec · spBone_isYDown · size=16 · insn=4 */
/* @0x284eec ldr r3, [pc, #0x4] */
/* @0x284ef0 ldr r0, [pc, r3] */
/* @0x284ef4 bx lr */
/* @0x284ef8 subeq r1, sp, r8, asr #25 */

/* ── FUNC 0x284efc · spBone_dispose · size=28 · insn=7 */
/* @0x284efc push {r4, lr} */
/* @0x284f00 mov r4, r0 */
/* @0x284f04 ldr r0, [r0, #0x10] */
/* @0x284f08 bl 0x285c80 <_free> */
/* @0x284f0c mov r0, r4 */
/* @0x284f10 pop {r4, lr} */
/* @0x284f14 b 0x285c80 <_free> */

/* ── FUNC 0x284f18 · spBone_updateWorldTransformWith · size=1072 · insn=268 */
/* @0x284f18 push {r3, r4, r5, lr} */
/* @0x284f1c vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x284f20 vmov s21, r3 */
/* @0x284f24 vldr s18, [sp, #80] */
/* @0x284f28 vldr s27, [pc, #896] */
/* @0x284f2c vldr s16, [pc, #896] */
/* @0x284f30 vadd.f32 s18, s21, s18 */
/* @0x284f34 mov r5, r0 */
/* @0x284f38 vmov s29, r1 */
/* @0x284f3c vldr s17, [sp, #84] */
/* @0x284f40 vmov s28, r2 */
/* @0x284f44 vldr s26, [sp, #72] */
/* @0x284f48 vldr s25, [sp, #76] */
/* @0x284f4c vmul.f32 s18, s18, s27 */
/* @0x284f50 vcvt.f64.f32 d9, s18 */
/* @0x284f54 vadd.f32 s16, s21, s16 */
/* @0x284f58 vmov r0, r1, d9 */
/* @0x284f5c bl 0xb67e4 <cos@plt> */
/* @0x284f60 vadd.f32 s16, s16, s17 */
/* @0x284f64 vmul.f32 s16, s16, s27 */
/* @0x284f68 vcvt.f64.f32 d8, s16 */
/* @0x284f6c vmov d6, r0, r1 */
/* @0x284f70 vmov r0, r1, d8 */
/* @0x284f74 vcvt.f32.f64 s20, d6 */
/* @0x284f78 bl 0xb67e4 <cos@plt> */
/* @0x284f7c vmul.f32 s20, s20, s26 */
/* @0x284f80 vmov d7, r0, r1 */
/* @0x284f84 vmov r0, r1, d9 */
/* @0x284f88 vcvt.f32.f64 s22, d7 */
/* @0x284f8c bl 0xb67d8 <sin@plt> */
/* @0x284f90 vmul.f32 s22, s22, s25 */
/* @0x284f94 vmov d6, r0, r1 */
/* @0x284f98 vmov r0, r1, d8 */
/* @0x284f9c vcvt.f32.f64 s24, d6 */
/* @0x284fa0 bl 0xb67d8 <sin@plt> */
/* @0x284fa4 ldr r4, [r5, #0x8] */
/* @0x284fa8 vstr s21, [r5, #48] */
/* @0x284fac cmp r4, #0 */
/* @0x284fb0 vmul.f32 s24, s24, s26 */
/* @0x284fb4 vmov d7, r0, r1 */
/* @0x284fb8 vcvt.f32.f64 s23, d7 */
/* @0x284fbc vmul.f32 s23, s23, s25 */
/* @0x284fc0 beq 0x2852c4 <spBone_updateWorldTransformWith+0x3ac> */
/* @0x284fc4 vldr s10, [r4, #56] */
/* @0x284fc8 vldr s11, [r4, #68] */
/* @0x284fcc vldr s12, [r4, #52] */
/* @0x284fd0 vldr s13, [r4, #64] */
/* @0x284fd4 vldr s9, [r4, #60] */
/* @0x284fd8 ldr r3, [r5] */
/* @0x284fdc ldr r2, [r3, #0x2c] */
/* @0x284fe0 ldr r3, [r3, #0x30] */
/* @0x284fe4 vmul.f32 s14, s10, s28 */
/* @0x284fe8 vmul.f32 s15, s11, s28 */
/* @0x284fec vmla.f32 s14, s12, s29 */
/* @0x284ff0 vmla.f32 s15, s13, s29 */
/* @0x284ff4 vadd.f32 s14, s14, s9 */
/* @0x284ff8 vmov.f32 s19, #1.000000e+00 */
/* @0x284ffc vstr s14, [r5, #60] */
/* @0x285000 vldr s9, [r4, #72] */
/* @0x285004 vmov.f32 s14, #-1.000000e+00 */
/* @0x285008 vadd.f32 s15, s15, s9 */
/* @0x28500c vcmpe.f32 s26, #0 */
/* @0x285010 vstr s15, [r5, #72] */
/* @0x285014 vldr s9, [r4, #76] */
/* @0x285018 vmrs APSR_nzcv, fpscr */
/* @0x28501c vmovle.f32 s15, s14 */
/* @0x285020 vmovgt.f32 s15, s19 */
/* @0x285024 vmul.f32 s15, s9, s15 */
/* @0x285028 vcmpe.f32 s25, #0 */
/* @0x28502c vstr s15, [r5, #76] */
/* @0x285030 vldr s15, [r4, #80] */
/* @0x285034 vmrs APSR_nzcv, fpscr */
/* @0x285038 vmovgt.f32 s14, s19 */
/* @0x28503c cmp r2, #0 */
/* @0x285040 vmul.f32 s14, s15, s14 */
/* @0x285044 vstr s14, [r5, #80] */
/* @0x285048 beq 0x28516c <spBone_updateWorldTransformWith+0x254> */
/* @0x28504c cmp r3, #0 */
/* @0x285050 bne 0x285278 <spBone_updateWorldTransformWith+0x360> */
/* @0x285054 vldr s25, [pc, #604] */
/* @0x285058 vmov.f32 s26, s19 */
/* @0x28505c vmov.f32 s21, s25 */
/* @0x285060 b 0x285070 <spBone_updateWorldTransformWith+0x158> */
/* @0x285064 ldr r4, [r4, #0x8] */
/* @0x285068 cmp r4, #0 */
/* @0x28506c beq 0x2850dc <spBone_updateWorldTransformWith+0x1c4> */
/* @0x285070 vldr s16, [r4, #48] */
/* @0x285074 vmul.f32 s16, s16, s27 */
/* @0x285078 vcvt.f64.f32 d8, s16 */
/* @0x28507c vmov r0, r1, d8 */
/* @0x285080 bl 0xb67e4 <cos@plt> */
/* @0x285084 vmov d6, r0, r1 */
/* @0x285088 vmov r0, r1, d8 */
/* @0x28508c vcvt.f32.f64 s18, d6 */
/* @0x285090 bl 0xb67d8 <sin@plt> */
/* @0x285094 ldr r3, [r4] */
/* @0x285098 ldr r3, [r3, #0x2c] */
/* @0x28509c cmp r3, #0 */
/* @0x2850a0 vmov d6, r0, r1 */
/* @0x2850a4 vcvt.f32.f64 s15, d6 */
/* @0x2850a8 vmul.f32 s13, s21, s15 */
/* @0x2850ac vmul.f32 s12, s26, s15 */
/* @0x2850b0 vmul.f32 s14, s19, s15 */
/* @0x2850b4 vmul.f32 s15, s25, s15 */
/* @0x2850b8 vmla.f32 s13, s26, s18 */
/* @0x2850bc vnmls.f32 s12, s21, s18 */
/* @0x2850c0 vmla.f32 s14, s25, s18 */
/* @0x2850c4 vnmls.f32 s15, s19, s18 */
/* @0x2850c8 vmov.f32 s26, s13 */
/* @0x2850cc vmov.f32 s21, s12 */
/* @0x2850d0 vmov.f32 s25, s14 */
/* @0x2850d4 vmov.f32 s19, s15 */
/* @0x2850d8 bne 0x285064 <spBone_updateWorldTransformWith+0x14c> */
/* @0x2850dc vmul.f32 s15, s24, s21 */
/* @0x2850e0 vmul.f32 s24, s24, s19 */
/* @0x2850e4 vmul.f32 s21, s23, s21 */
/* @0x2850e8 vmul.f32 s19, s23, s19 */
/* @0x2850ec vmla.f32 s15, s20, s13 */
/* @0x2850f0 vmla.f32 s21, s22, s13 */
/* @0x2850f4 vstr s15, [r5, #52] */
/* @0x2850f8 vmla.f32 s24, s20, s14 */
/* @0x2850fc vstr s21, [r5, #56] */
/* @0x285100 vmla.f32 s19, s22, s14 */
/* @0x285104 vstr s24, [r5, #64] */
/* @0x285108 vstr s19, [r5, #68] */
/* @0x28510c ldr r3, [r5, #0x4] */
/* @0x285110 ldr r2, [r3, #0x50] */
/* @0x285114 cmp r2, #0 */
/* @0x285118 beq 0x285134 <spBone_updateWorldTransformWith+0x21c> */
/* @0x28511c vldr s14, [r5, #52] */
/* @0x285120 vldr s15, [r5, #56] */
/* @0x285124 vneg.f32 s14, s14 */
/* @0x285128 vneg.f32 s15, s15 */
/* @0x28512c vstr s14, [r5, #52] */
/* @0x285130 vstr s15, [r5, #56] */
/* @0x285134 ldr r1, [pc, #0x180] */
/* @0x285138 ldr r2, [r3, #0x54] */
/* @0x28513c add r1, pc, r1 */
/* @0x285140 ldr r3, [r1] */
/* @0x285144 cmp r2, r3 */
/* @0x285148 beq 0x285164 <spBone_updateWorldTransformWith+0x24c> */
/* @0x28514c vldr s14, [r5, #64] */
/* @0x285150 vldr s15, [r5, #68] */
/* @0x285154 vneg.f32 s14, s14 */
/* @0x285158 vneg.f32 s15, s15 */
/* @0x28515c vstr s14, [r5, #64] */
/* @0x285160 vstr s15, [r5, #68] */
/* @0x285164 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x285168 pop {r3, r4, r5, pc} */
/* @0x28516c cmp r3, #0 */
/* @0x285170 beq 0x285264 <spBone_updateWorldTransformWith+0x34c> */
/* @0x285174 vldr s21, [pc, #316] */
/* @0x285178 vmov.f32 s25, s19 */
/* @0x28517c vmov.f32 s26, s21 */
/* @0x285180 b 0x285190 <spBone_updateWorldTransformWith+0x278> */
/* @0x285184 ldr r4, [r4, #0x8] */
/* @0x285188 cmp r4, #0 */
/* @0x28518c beq 0x285230 <spBone_updateWorldTransformWith+0x318> */
/* @0x285190 vldr s16, [r4, #48] */
/* @0x285194 vmul.f32 s16, s16, s27 */
/* @0x285198 vldr s28, [r4, #32] */
/* @0x28519c vldr s29, [r4, #36] */
/* @0x2851a0 vcvt.f64.f32 d8, s16 */
/* @0x2851a4 vmov r0, r1, d8 */
/* @0x2851a8 bl 0xb67e4 <cos@plt> */
/* @0x2851ac vmov d7, r0, r1 */
/* @0x2851b0 vmov r0, r1, d8 */
/* @0x2851b4 vcvt.f32.f64 s18, d7 */
/* @0x2851b8 bl 0xb67d8 <sin@plt> */
/* @0x2851bc ldr r3, [r4] */
/* @0x2851c0 ldr r3, [r3, #0x30] */
/* @0x2851c4 vmul.f32 s9, s18, s29 */
/* @0x2851c8 vmul.f32 s10, s18, s28 */
/* @0x2851cc vcmpe.f32 s28, #0 */
/* @0x2851d0 vmov d6, r0, r1 */
/* @0x2851d4 vcvt.f32.f64 s15, d6 */
/* @0x2851d8 vmrs APSR_nzcv, fpscr */
/* @0x2851dc vmul.f32 s14, s15, s29 */
/* @0x2851e0 vmul.f32 s13, s15, s28 */
/* @0x2851e4 vmul.f32 s12, s25, s14 */
/* @0x2851e8 vmul.f32 s11, s26, s13 */
/* @0x2851ec vmul.f32 s14, s21, s14 */
/* @0x2851f0 vmul.f32 s13, s19, s13 */
/* @0x2851f4 vnmls.f32 s12, s26, s9 */
/* @0x2851f8 vnmls.f32 s14, s19, s9 */
/* @0x2851fc vmla.f32 s11, s25, s10 */
/* @0x285200 vmla.f32 s13, s21, s10 */
/* @0x285204 vnegge.f32 s15, s15 */
/* @0x285208 cmp r3, #0 */
/* @0x28520c vmul.f32 s25, s12, s15 */
/* @0x285210 vmul.f32 s26, s15, s11 */
/* @0x285214 vmul.f32 s21, s14, s15 */
/* @0x285218 vmul.f32 s19, s15, s13 */
/* @0x28521c vmla.f32 s25, s18, s11 */
/* @0x285220 vnmls.f32 s26, s12, s18 */
/* @0x285224 vmla.f32 s21, s18, s13 */
/* @0x285228 vnmls.f32 s19, s14, s18 */
/* @0x28522c bne 0x285184 <spBone_updateWorldTransformWith+0x26c> */
/* @0x285230 vmul.f32 s15, s24, s26 */
/* @0x285234 vmul.f32 s24, s24, s19 */
/* @0x285238 vmul.f32 s26, s23, s26 */
/* @0x28523c vmul.f32 s19, s23, s19 */
/* @0x285240 vmla.f32 s15, s20, s25 */
/* @0x285244 vmla.f32 s26, s22, s25 */
/* @0x285248 vstr s15, [r5, #52] */
/* @0x28524c vmla.f32 s24, s20, s21 */
/* @0x285250 vstr s26, [r5, #56] */
/* @0x285254 vmla.f32 s19, s22, s21 */
/* @0x285258 vstr s24, [r5, #64] */
/* @0x28525c vstr s19, [r5, #68] */
/* @0x285260 b 0x28510c <spBone_updateWorldTransformWith+0x1f4> */
/* @0x285264 vstr s20, [r5, #52] */
/* @0x285268 vstr s22, [r5, #56] */
/* @0x28526c vstr s24, [r5, #64] */
/* @0x285270 vstr s23, [r5, #68] */
/* @0x285274 b 0x28510c <spBone_updateWorldTransformWith+0x1f4> */
/* @0x285278 vmul.f32 s15, s10, s24 */
/* @0x28527c vmul.f32 s24, s11, s24 */
/* @0x285280 vmul.f32 s10, s10, s23 */
/* @0x285284 vmul.f32 s11, s11, s23 */
/* @0x285288 vmla.f32 s24, s13, s20 */
/* @0x28528c vmla.f32 s15, s12, s20 */
/* @0x285290 vstr s24, [r5, #64] */
/* @0x285294 vmla.f32 s10, s12, s22 */
/* @0x285298 vstr s15, [r5, #52] */
/* @0x28529c vmla.f32 s11, s13, s22 */
/* @0x2852a0 vstr s10, [r5, #56] */
/* @0x2852a4 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2852a8 vstr s11, [r5, #68] */
/* @0x2852ac pop {r3, r4, r5, pc} */
/* @0x2852b0 vstmialo lr, {s30, s31} */
/* @0x2852b4 adcsmi r0, r4, #0 */
/* @0x2852b8 andeq r0, r0, r0 */
/* @0x2852bc subeq r1, sp, r12, ror r10 */
/* @0x2852c0 subeq r1, sp, r4, ror #17 */
/* @0x2852c4 ldr r3, [r5, #0x4] */
/* @0x2852c8 vmov.f32 s14, #1.000000e+00 */
/* @0x2852cc ldr r1, [pc, #-0x14] */
/* @0x2852d0 ldr r2, [r3, #0x50] */
/* @0x2852d4 add r1, pc, r1 */
/* @0x2852d8 cmp r2, #0 */
/* @0x2852dc ldr r2, [r3, #0x54] */
/* @0x2852e0 ldr r3, [r1] */
/* @0x2852e4 vnegne.f32 s29, s29 */
/* @0x2852e8 vnegne.f32 s20, s20 */
/* @0x2852ec vstr s29, [r5, #60] */
/* @0x2852f0 vnegne.f32 s22, s22 */
/* @0x2852f4 cmp r2, r3 */
/* @0x2852f8 vstr s20, [r5, #52] */
/* @0x2852fc vmov.f32 s15, #-1.000000e+00 */
/* @0x285300 vstr s22, [r5, #56] */
/* @0x285304 vnegne.f32 s28, s28 */
/* @0x285308 vnegne.f32 s24, s24 */
/* @0x28530c vstr s28, [r5, #72] */
/* @0x285310 vnegne.f32 s23, s23 */
/* @0x285314 vstr s24, [r5, #64] */
/* @0x285318 vcmpe.f32 s26, #0 */
/* @0x28531c vstr s23, [r5, #68] */
/* @0x285320 vmrs APSR_nzcv, fpscr */
/* @0x285324 vcmpe.f32 s25, #0 */
/* @0x285328 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x28532c vmovle.f32 s13, s15 */
/* @0x285330 vmovgt.f32 s13, s14 */
/* @0x285334 vmrs APSR_nzcv, fpscr */
/* @0x285338 vstr s13, [r5, #76] */
/* @0x28533c vmovgt.f32 s15, s14 */
/* @0x285340 vstr s15, [r5, #80] */
/* @0x285344 pop {r3, r4, r5, pc} */

/* ── FUNC 0x285348 · spBone_updateWorldTransform · size=64 · insn=16 */
/* @0x285348 push {r4, lr} */
/* @0x28534c sub sp, sp, #16 */
/* @0x285350 ldr lr, [r0, #0x20] */
/* @0x285354 ldr r4, [r0, #0x24] */
/* @0x285358 ldr r12, [r0, #0x2c] */
/* @0x28535c str lr, [sp] */
/* @0x285360 ldr lr, [r0, #0x28] */
/* @0x285364 ldr r1, [r0, #0x14] */
/* @0x285368 ldr r2, [r0, #0x18] */
/* @0x28536c ldr r3, [r0, #0x1c] */
/* @0x285370 str r4, [sp, #0x4] */
/* @0x285374 str lr, [sp, #0x8] */
/* @0x285378 str r12, [sp, #0xc] */
/* @0x28537c bl 0x284f18 <spBone_updateWorldTransformWith> */
/* @0x285380 add sp, sp, #16 */
/* @0x285384 pop {r4, pc} */

/* ── FUNC 0x285388 · spBone_setToSetupPose · size=64 · insn=16 */
/* @0x285388 ldr r3, [r0] */
/* @0x28538c ldr r1, [r3, #0x10] */
/* @0x285390 ldr r2, [r3, #0x14] */
/* @0x285394 str r1, [r0, #0x14] */
/* @0x285398 str r2, [r0, #0x18] */
/* @0x28539c ldr r1, [r3, #0x18] */
/* @0x2853a0 ldr r2, [r3, #0x1c] */
/* @0x2853a4 str r1, [r0, #0x1c] */
/* @0x2853a8 str r2, [r0, #0x20] */
/* @0x2853ac ldr r1, [r3, #0x20] */
/* @0x2853b0 ldr r2, [r3, #0x24] */
/* @0x2853b4 ldr r3, [r3, #0x28] */
/* @0x2853b8 str r1, [r0, #0x24] */
/* @0x2853bc str r2, [r0, #0x28] */
/* @0x2853c0 str r3, [r0, #0x2c] */
/* @0x2853c4 bx lr */

/* ── FUNC 0x2853c8 · spBone_create · size=72 · insn=18 */
/* @0x2853c8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2853cc mov r5, r2 */
/* @0x2853d0 ldr r2, [pc, #0x34] */
/* @0x2853d4 mov r7, r0 */
/* @0x2853d8 mov r6, r1 */
/* @0x2853dc mov r3, #46 */
/* @0x2853e0 mov r1, #88 */
/* @0x2853e4 add r2, pc, r2 */
/* @0x2853e8 mov r0, #1 */
/* @0x2853ec bl 0x285c4c <_calloc> */
/* @0x2853f0 mov r4, r0 */
/* @0x2853f4 str r7, [r0] */
/* @0x2853f8 str r6, [r0, #0x4] */
/* @0x2853fc str r5, [r0, #0x8] */
/* @0x285400 bl 0x285388 <spBone_setToSetupPose> */
/* @0x285404 mov r0, r4 */
/* @0x285408 pop {r3, r4, r5, r6, r7, pc} */
/* @0x28540c andeq r2, sp, r4, lsl #6 */
