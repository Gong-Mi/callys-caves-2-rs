/* libyoyo.so 覆盖卡组 0207
 * 函数 0x232d04..0x233af0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x232d04 · ov_time_tell · size=292 · insn=73 */
/* @0x232d04 ldr r3, [r0, #0x58] */
/* @0x232d08 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x232d0c cmp r3, #1 */
/* @0x232d10 mov r8, r0 */
/* @0x232d14 ble 0x232e0c <ov_time_tell+0x108> */
/* @0x232d18 ldr r9, [r0, #0x4] */
/* @0x232d1c cmp r9, #0 */
/* @0x232d20 bne 0x232d70 <ov_time_tell+0x6c> */
/* @0x232d24 ldr r0, [r0, #0x50] */
/* @0x232d28 mov r6, #0 */
/* @0x232d2c ldr lr, [r8, #0x54] */
/* @0x232d30 mov r7, #0 */
/* @0x232d34 mov r4, r6 */
/* @0x232d38 mov r5, r7 */
/* @0x232d3c mov r12, #1000 */
/* @0x232d40 ldr r3, [r8, #0x48] */
/* @0x232d44 umull r0, r1, r0, r12 */
/* @0x232d48 add r9, r3, r9 */
/* @0x232d4c ldr r2, [r9, #0x8] */
/* @0x232d50 mla r1, r12, lr, r1 */
/* @0x232d54 asr r3, r2, #31 */
/* @0x232d58 subs r0, r0, r4 */
/* @0x232d5c sbc r1, r1, r5 */
/* @0x232d60 bl 0x319414 <__aeabi_ldivmod> */
/* @0x232d64 adds r0, r0, r6 */
/* @0x232d68 adc r1, r1, r7 */
/* @0x232d6c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x232d70 mvn r1, #0 */
/* @0x232d74 bl 0x23138c <ov_pcm_total> */
/* @0x232d78 mov r4, r0 */
/* @0x232d7c mov r5, r1 */
/* @0x232d80 mov r0, r8 */
/* @0x232d84 mvn r1, #0 */
/* @0x232d88 bl 0x231424 <ov_time_total> */
/* @0x232d8c ldr r9, [r8, #0x34] */
/* @0x232d90 subs r9, r9, #1 */
/* @0x232d94 lslpl r10, r9, #4 */
/* @0x232d98 addpl r10, r10, #8 */
/* @0x232d9c mov r6, r0 */
/* @0x232da0 mov r7, r1 */
/* @0x232da4 bpl 0x232db4 <ov_time_tell+0xb0> */
/* @0x232da8 b 0x232e18 <ov_time_tell+0x114> */
/* @0x232dac subs r9, r9, #1 */
/* @0x232db0 blo 0x232dfc <ov_time_tell+0xf8> */
/* @0x232db4 ldr r3, [r8, #0x44] */
/* @0x232db8 mov r0, r8 */
/* @0x232dbc mov r1, r9 */
/* @0x232dc0 ldrd r2, r3, [r3, r10] */
/* @0x232dc4 sub r10, r10, #16 */
/* @0x232dc8 subs r4, r4, r2 */
/* @0x232dcc sbc r5, r5, r3 */
/* @0x232dd0 bl 0x231424 <ov_time_total> */
/* @0x232dd4 ldrd r2, r3, [r8, #80] */
/* @0x232dd8 subs r6, r6, r0 */
/* @0x232ddc sbc r7, r7, r1 */
/* @0x232de0 cmp r2, r4 */
/* @0x232de4 sbcs r1, r3, r5 */
/* @0x232de8 blt 0x232dac <ov_time_tell+0xa8> */
/* @0x232dec lsl r9, r9, #5 */
/* @0x232df0 mov r0, r2 */
/* @0x232df4 mov lr, r3 */
/* @0x232df8 b 0x232d3c <ov_time_tell+0x38> */
/* @0x232dfc mov r0, r2 */
/* @0x232e00 mov lr, r3 */
/* @0x232e04 mvn r9, #31 */
/* @0x232e08 b 0x232d3c <ov_time_tell+0x38> */
/* @0x232e0c mvn r0, #130 */
/* @0x232e10 mvn r1, #0 */
/* @0x232e14 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x232e18 lsl r9, r9, #5 */
/* @0x232e1c ldr r0, [r8, #0x50] */
/* @0x232e20 ldr lr, [r8, #0x54] */
/* @0x232e24 b 0x232d3c <ov_time_tell+0x38> */

/* ── FUNC 0x232e28 · ov_info · size=80 · insn=20 */
/* @0x232e28 ldr r3, [r0, #0x4] */
/* @0x232e2c cmp r3, #0 */
/* @0x232e30 beq 0x232e54 <ov_info+0x2c> */
/* @0x232e34 cmp r1, #0 */
/* @0x232e38 blt 0x232e5c <ov_info+0x34> */
/* @0x232e3c ldr r3, [r0, #0x34] */
/* @0x232e40 cmp r1, r3 */
/* @0x232e44 ldrlt r0, [r0, #0x48] */
/* @0x232e48 addlt r0, r0, r1, lsl #5 */
/* @0x232e4c movge r0, #0 */
/* @0x232e50 bx lr */
/* @0x232e54 ldr r0, [r0, #0x48] */
/* @0x232e58 bx lr */
/* @0x232e5c ldr r3, [r0, #0x58] */
/* @0x232e60 cmp r3, #2 */
/* @0x232e64 ble 0x232e54 <ov_info+0x2c> */
/* @0x232e68 ldr r1, [r0, #0x60] */
/* @0x232e6c ldr r3, [r0, #0x48] */
/* @0x232e70 add r0, r3, r1, lsl #5 */
/* @0x232e74 bx lr */

/* ── FUNC 0x232e78 · ov_comment · size=80 · insn=20 */
/* @0x232e78 ldr r3, [r0, #0x4] */
/* @0x232e7c cmp r3, #0 */
/* @0x232e80 beq 0x232ea4 <ov_comment+0x2c> */
/* @0x232e84 cmp r1, #0 */
/* @0x232e88 blt 0x232eac <ov_comment+0x34> */
/* @0x232e8c ldr r3, [r0, #0x34] */
/* @0x232e90 cmp r1, r3 */
/* @0x232e94 ldrlt r0, [r0, #0x4c] */
/* @0x232e98 addlt r0, r0, r1, lsl #4 */
/* @0x232e9c movge r0, #0 */
/* @0x232ea0 bx lr */
/* @0x232ea4 ldr r0, [r0, #0x4c] */
/* @0x232ea8 bx lr */
/* @0x232eac ldr r3, [r0, #0x58] */
/* @0x232eb0 cmp r3, #2 */
/* @0x232eb4 ble 0x232ea4 <ov_comment+0x2c> */
/* @0x232eb8 ldr r1, [r0, #0x60] */
/* @0x232ebc ldr r3, [r0, #0x4c] */
/* @0x232ec0 add r0, r3, r1, lsl #4 */
/* @0x232ec4 bx lr */

/* ── FUNC 0x232ec8 · ov_read · size=352 · insn=88 */
/* @0x232ec8 ldr r12, [r0, #0x58] */
/* @0x232ecc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x232ed0 cmp r12, #1 */
/* @0x232ed4 sub sp, sp, #20 */
/* @0x232ed8 mov r4, r0 */
/* @0x232edc mov r5, r1 */
/* @0x232ee0 mov r9, r2 */
/* @0x232ee4 mov r6, r3 */
/* @0x232ee8 ble 0x233020 <ov_read+0x158> */
/* @0x232eec add r7, r0, #480 */
/* @0x232ef0 add r10, sp, #12 */
/* @0x232ef4 b 0x232f14 <ov_read+0x4c> */
/* @0x232ef8 mov r0, r4 */
/* @0x232efc bl 0x230b68 <vorbis_packet_blocksize+0xeec> */
/* @0x232f00 cmn r0, #2 */
/* @0x232f04 beq 0x233014 <ov_read+0x14c> */
/* @0x232f08 cmp r0, #0 */
/* @0x232f0c ble 0x23300c <ov_read+0x144> */
/* @0x232f10 ldr r12, [r4, #0x58] */
/* @0x232f14 cmp r12, #4 */
/* @0x232f18 bne 0x232ef8 <ov_read+0x30> */
/* @0x232f1c mov r0, r7 */
/* @0x232f20 mov r1, r10 */
/* @0x232f24 bl 0x227c80 <vorbis_synthesis_pcmout> */
/* @0x232f28 cmp r0, #0 */
/* @0x232f2c beq 0x232ef8 <ov_read+0x30> */
/* @0x232f30 mov r8, r0 */
/* @0x232f34 movle r0, r0 */
/* @0x232f38 ble 0x23300c <ov_read+0x144> */
/* @0x232f3c mvn r1, #0 */
/* @0x232f40 mov r0, r4 */
/* @0x232f44 bl 0x232e28 <ov_info> */
/* @0x232f48 ldr r0, [r0, #0x4] */
/* @0x232f4c str r0, [sp, #0x4] */
/* @0x232f50 mov r0, r9 */
/* @0x232f54 ldr r3, [sp, #0x4] */
/* @0x232f58 lsl r9, r3, #1 */
/* @0x232f5c mov r1, r9 */
/* @0x232f60 bl 0x318d10 <__divsi3> */
/* @0x232f64 ldr r3, [sp, #0x4] */
/* @0x232f68 cmp r8, r0 */
/* @0x232f6c movge r8, r0 */
/* @0x232f70 cmp r3, #0 */
/* @0x232f74 ble 0x232fd8 <ov_read+0x110> */
/* @0x232f78 ldr r1, [sp, #0xc] */
/* @0x232f7c lsl r11, r8, #2 */
/* @0x232f80 add r10, r5, r9 */
/* @0x232f84 mov r0, r5 */
/* @0x232f88 sub r1, r1, #4 */
/* @0x232f8c cmp r8, #0 */
/* @0x232f90 ldr r3, [r1, #0x4]! */
/* @0x232f94 mov lr, r0 */
/* @0x232f98 addgt r5, r3, r11 */
/* @0x232f9c ble 0x232fcc <ov_read+0x104> */
/* @0x232fa0 ldr r12, [r3], #4 */
/* @0x232fa4 mov r2, #32768 */
/* @0x232fa8 asr r12, r12, #9 */
/* @0x232fac cmp r12, r2 */
/* @0x232fb0 movwge r2, #0x7fff */
/* @0x232fb4 bge 0x232fc0 <ov_read+0xf8> */
/* @0x232fb8 cmn r12, #32768 */
/* @0x232fbc uxthge r2, r12 */
/* @0x232fc0 cmp r3, r5 */
/* @0x232fc4 strh r2, [lr], r9 */
/* @0x232fc8 bne 0x232fa0 <ov_read+0xd8> */
/* @0x232fcc add r0, r0, #2 */
/* @0x232fd0 cmp r0, r10 */
/* @0x232fd4 bne 0x232f8c <ov_read+0xc4> */
/* @0x232fd8 mov r0, r7 */
/* @0x232fdc mov r1, r8 */
/* @0x232fe0 bl 0x227cfc <vorbis_synthesis_read> */
/* @0x232fe4 ldrd r2, r3, [r4, #80] */
/* @0x232fe8 adds r2, r2, r8 */
/* @0x232fec adc r3, r3, r8, asr #31 */
/* @0x232ff0 cmp r6, #0 */
/* @0x232ff4 strd r2, r3, [r4, #80] */
/* @0x232ff8 ldrne r3, [r4, #0x60] */
/* @0x232ffc strne r3, [r6] */
/* @0x233000 ldr r3, [sp, #0x4] */
/* @0x233004 lsl r0, r8, #1 */
/* @0x233008 mul r0, r3, r0 */
/* @0x23300c add sp, sp, #20 */
/* @0x233010 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x233014 mov r0, #0 */
/* @0x233018 add sp, sp, #20 */
/* @0x23301c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x233020 mvn r0, #130 */
/* @0x233024 b 0x23300c <ov_read+0x144> */

/* ── FUNC 0x233028 · _vorbis_window · size=244 · insn=61 */
/* @0x233028 cmp r0, #0 */
/* @0x23302c bne 0x23308c <_vorbis_window+0x64> */
/* @0x233030 cmp r1, #256 */
/* @0x233034 beq 0x2330ec <_vorbis_window+0xc4> */
/* @0x233038 ble 0x233068 <_vorbis_window+0x40> */
/* @0x23303c cmp r1, #1024 */
/* @0x233040 beq 0x2330dc <_vorbis_window+0xb4> */
/* @0x233044 ble 0x2330b4 <_vorbis_window+0x8c> */
/* @0x233048 cmp r1, #2048 */
/* @0x23304c beq 0x2330a4 <_vorbis_window+0x7c> */
/* @0x233050 cmp r1, #4096 */
/* @0x233054 bne 0x23308c <_vorbis_window+0x64> */
/* @0x233058 ldr r0, [pc, #0x9c] */
/* @0x23305c add r0, pc, r0 */
/* @0x233060 sub r0, r0, #112 */
/* @0x233064 bx lr */
/* @0x233068 cmp r1, #64 */
/* @0x23306c beq 0x2330cc <_vorbis_window+0xa4> */
/* @0x233070 cmp r1, #128 */
/* @0x233074 beq 0x233094 <_vorbis_window+0x6c> */
/* @0x233078 cmp r1, #32 */
/* @0x23307c bne 0x23308c <_vorbis_window+0x64> */
/* @0x233080 ldr r0, [pc, #0x78] */
/* @0x233084 add r0, pc, r0 */
/* @0x233088 bx lr */
/* @0x23308c mov r0, #0 */
/* @0x233090 bx lr */
/* @0x233094 ldr r0, [pc, #0x68] */
/* @0x233098 add r0, pc, r0 */
/* @0x23309c add r0, r0, #384 */
/* @0x2330a0 bx lr */
/* @0x2330a4 ldr r0, [pc, #0x5c] */
/* @0x2330a8 add r0, pc, r0 */
/* @0x2330ac sub r0, r0, #120 */
/* @0x2330b0 bx lr */
/* @0x2330b4 cmp r1, #512 */
/* @0x2330b8 bne 0x23308c <_vorbis_window+0x64> */
/* @0x2330bc ldr r0, [pc, #0x48] */
/* @0x2330c0 add r0, pc, r0 */
/* @0x2330c4 add r0, r0, #1920 */
/* @0x2330c8 bx lr */
/* @0x2330cc ldr r0, [pc, #0x3c] */
/* @0x2330d0 add r0, pc, r0 */
/* @0x2330d4 add r0, r0, #128 */
/* @0x2330d8 bx lr */
/* @0x2330dc ldr r0, [pc, #0x30] */
/* @0x2330e0 add r0, pc, r0 */
/* @0x2330e4 add r0, r0, #3968 */
/* @0x2330e8 bx lr */
/* @0x2330ec ldr r0, [pc, #0x24] */
/* @0x2330f0 add r0, pc, r0 */
/* @0x2330f4 add r0, r0, #896 */
/* @0x2330f8 bx lr */
/* @0x2330fc andseq r1, r3, r12, asr #20 */
/* @0x233100 andseq sp, r2, r4, lsr r10 */
/* @0x233104 andseq sp, r2, r0, lsr #20 */
/* @0x233108 andseq pc, r2, r8, lsl #20 */
/* @0x23310c ldrsheq sp, [r2], -r8 */
/* @0x233110 andseq sp, r2, r8, ror #19 */
/* @0x233114 ldrsbeq sp, [r2], -r8 */
/* @0x233118 andseq sp, r2, r8, asr #19 */

/* ── FUNC 0x23311c · _vorbis_apply_window · size=328 · insn=82 */
/* @0x23311c push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x233120 sub sp, sp, #12 */
/* @0x233124 ldr r9, [r2, r3, lsl #2] */
/* @0x233128 ldr r12, [sp, #0x28] */
/* @0x23312c cmp r9, #0 */
/* @0x233130 ldr r7, [sp, #0x2c] */
/* @0x233134 ldr r5, [r2, r12, lsl #2] */
/* @0x233138 add r12, r9, #3 */
/* @0x23313c movge r12, r9 */
/* @0x233140 ldr r2, [r2, r7, lsl #2] */
/* @0x233144 cmp r5, #0 */
/* @0x233148 add r4, r5, #3 */
/* @0x23314c add r10, r2, #3 */
/* @0x233150 add r6, r5, r5, lsr #31 */
/* @0x233154 movge r4, r5 */
/* @0x233158 cmp r2, #0 */
/* @0x23315c asr r4, r4, #2 */
/* @0x233160 add r8, r2, r2, lsr #31 */
/* @0x233164 add r6, r4, r6, asr #1 */
/* @0x233168 movlt r2, r10 */
/* @0x23316c sub r12, r4, r12, asr #2 */
/* @0x233170 ldr r10, [r1] */
/* @0x233174 ldr r4, [r1, #0x4] */
/* @0x233178 add r9, r9, r9, lsr #31 */
/* @0x23317c cmp r12, #0 */
/* @0x233180 sub r1, r6, r2, asr #2 */
/* @0x233184 asr r8, r8, #1 */
/* @0x233188 add r9, r12, r9, asr #1 */
/* @0x23318c add r6, r8, r1 */
/* @0x233190 str r10, [sp] */
/* @0x233194 str r4, [sp, #0x4] */
/* @0x233198 ble 0x23325c <_vorbis_apply_window+0x140> */
/* @0x23319c add r10, r0, r12, lsl #2 */
/* @0x2331a0 mov r2, r0 */
/* @0x2331a4 mov r4, #0 */
/* @0x2331a8 str r4, [r2], #4 */
/* @0x2331ac cmp r2, r10 */
/* @0x2331b0 bne 0x2331a8 <_vorbis_apply_window+0x8c> */
/* @0x2331b4 cmp r9, r12 */
/* @0x2331b8 ble 0x2331f0 <_vorbis_apply_window+0xd4> */
/* @0x2331bc add r2, sp, #8 */
/* @0x2331c0 add r12, r0, r12, lsl #2 */
/* @0x2331c4 add r3, r2, r3, lsl #2 */
/* @0x2331c8 add r9, r0, r9, lsl #2 */
/* @0x2331cc ldr r4, [r3, #-0x8] */
/* @0x2331d0 sub r4, r4, #4 */
/* @0x2331d4 ldr r2, [r12] */
/* @0x2331d8 ldr r3, [r4, #0x4]! */
/* @0x2331dc smull r2, r3, r2, r3 */
/* @0x2331e0 lsl r3, r3, #1 */
/* @0x2331e4 str r3, [r12], #4 */
/* @0x2331e8 cmp r12, r9 */
/* @0x2331ec bne 0x2331d4 <_vorbis_apply_window+0xb8> */
/* @0x2331f0 cmp r1, r6 */
/* @0x2331f4 bge 0x233230 <_vorbis_apply_window+0x114> */
/* @0x2331f8 add r3, sp, #8 */
/* @0x2331fc add r1, r0, r1, lsl #2 */
/* @0x233200 add r7, r3, r7, lsl #2 */
/* @0x233204 add r4, r0, r6, lsl #2 */
/* @0x233208 ldr r12, [r7, #-0x8] */
/* @0x23320c add r12, r12, r8, lsl #2 */
/* @0x233210 ldr r2, [r1] */
/* @0x233214 ldr r3, [r12, #-0x4]! */
/* @0x233218 smull r2, r3, r2, r3 */
/* @0x23321c lsl r3, r3, #1 */
/* @0x233220 str r3, [r1], #4 */
/* @0x233224 cmp r1, r4 */
/* @0x233228 bne 0x233210 <_vorbis_apply_window+0xf4> */
/* @0x23322c mov r1, r6 */
/* @0x233230 cmp r5, r1 */
/* @0x233234 ble 0x233250 <_vorbis_apply_window+0x134> */
/* @0x233238 add r1, r0, r1, lsl #2 */
/* @0x23323c add r5, r0, r5, lsl #2 */
/* @0x233240 mov r3, #0 */
/* @0x233244 str r3, [r1], #4 */
/* @0x233248 cmp r1, r5 */
/* @0x23324c bne 0x233244 <_vorbis_apply_window+0x128> */
/* @0x233250 add sp, sp, #12 */
/* @0x233254 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x233258 bx lr */
/* @0x23325c mov r12, #0 */
/* @0x233260 b 0x2331b4 <_vorbis_apply_window+0x98> */

/* ── FUNC 0x233264 · oggpack_writeinit · size=56 · insn=14 */
/* @0x233264 push {r4, lr} */
/* @0x233268 mov r2, #20 */
/* @0x23326c mov r1, #0 */
/* @0x233270 mov r4, r0 */
/* @0x233274 bl 0xb65b0 <memset@plt> */
/* @0x233278 mov r0, #256 */
/* @0x23327c bl 0xb6544 <malloc@plt> */
/* @0x233280 mov r2, #256 */
/* @0x233284 mov r3, #0 */
/* @0x233288 str r2, [r4, #0x10] */
/* @0x23328c str r0, [r4, #0x8] */
/* @0x233290 str r0, [r4, #0xc] */
/* @0x233294 strb r3, [r0] */
/* @0x233298 pop {r4, pc} */

/* ── FUNC 0x23329c · oggpackB_writeinit · size=4 · insn=1 */
/* @0x23329c b 0x233264 <oggpack_writeinit> */

/* ── FUNC 0x2332a0 · oggpack_writecheck · size=40 · insn=10 */
/* @0x2332a0 ldr r3, [r0, #0xc] */
/* @0x2332a4 cmp r3, #0 */
/* @0x2332a8 beq 0x2332c0 <oggpack_writecheck+0x20> */
/* @0x2332ac ldr r0, [r0, #0x10] */
/* @0x2332b0 cmp r0, #0 */
/* @0x2332b4 movne r0, #0 */
/* @0x2332b8 mvneq r0, #0 */
/* @0x2332bc bx lr */
/* @0x2332c0 mvn r0, #0 */
/* @0x2332c4 bx lr */

/* ── FUNC 0x2332c8 · oggpackB_writecheck · size=4 · insn=1 */
/* @0x2332c8 b 0x2332a0 <oggpack_writecheck> */

/* ── FUNC 0x2332cc · oggpack_writetrunc · size=80 · insn=20 */
/* @0x2332cc ldr r2, [r0, #0xc] */
/* @0x2332d0 asr r3, r1, #3 */
/* @0x2332d4 str r4, [sp, #-0x4]! */
/* @0x2332d8 cmp r2, #0 */
/* @0x2332dc beq 0x233310 <oggpack_writetrunc+0x44> */
/* @0x2332e0 ldr r4, [pc, #0x30] */
/* @0x2332e4 sub r12, r1, r3, lsl #3 */
/* @0x2332e8 ldr r2, [r0, #0x8] */
/* @0x2332ec add r4, pc, r4 */
/* @0x2332f0 str r3, [r0] */
/* @0x2332f4 str r12, [r0, #0x4] */
/* @0x2332f8 add r3, r2, r3 */
/* @0x2332fc str r3, [r0, #0xc] */
/* @0x233300 ldr r0, [r4, r12, lsl #2] */
/* @0x233304 ldrb r3, [r2, r1, asr #3] */
/* @0x233308 and r3, r0, r3 */
/* @0x23330c strb r3, [r2, r1, asr #3] */
/* @0x233310 ldr r4, [sp], #4 */
/* @0x233314 bx lr */
/* @0x233318 andseq r5, r3, r12, asr #14 */

/* ── FUNC 0x23331c · oggpackB_writetrunc · size=84 · insn=21 */
/* @0x23331c ldr r2, [r0, #0xc] */
/* @0x233320 asr r3, r1, #3 */
/* @0x233324 str r4, [sp, #-0x4]! */
/* @0x233328 cmp r2, #0 */
/* @0x23332c beq 0x233364 <oggpackB_writetrunc+0x48> */
/* @0x233330 ldr r4, [pc, #0x34] */
/* @0x233334 sub r12, r1, r3, lsl #3 */
/* @0x233338 ldr r2, [r0, #0x8] */
/* @0x23333c add r4, pc, r4 */
/* @0x233340 str r3, [r0] */
/* @0x233344 add r4, r4, r12, lsl #2 */
/* @0x233348 str r12, [r0, #0x4] */
/* @0x23334c add r3, r2, r3 */
/* @0x233350 str r3, [r0, #0xc] */
/* @0x233354 ldr r0, [r4, #0x84] */
/* @0x233358 ldrb r3, [r2, r1, asr #3] */
/* @0x23335c and r3, r0, r3 */
/* @0x233360 strb r3, [r2, r1, asr #3] */
/* @0x233364 ldr r4, [sp], #4 */
/* @0x233368 bx lr */
/* @0x23336c ldrsheq r5, [r3], -r12 */

/* ── FUNC 0x233370 · oggpack_reset · size=40 · insn=10 */
/* @0x233370 ldr r3, [r0, #0xc] */
/* @0x233374 cmp r3, #0 */
/* @0x233378 bxeq lr */
/* @0x23337c ldr r2, [r0, #0x8] */
/* @0x233380 mov r3, #0 */
/* @0x233384 str r2, [r0, #0xc] */
/* @0x233388 strb r3, [r2] */
/* @0x23338c str r3, [r0] */
/* @0x233390 str r3, [r0, #0x4] */
/* @0x233394 bx lr */

/* ── FUNC 0x233398 · oggpackB_reset · size=4 · insn=1 */
/* @0x233398 b 0x233370 <oggpack_reset> */

/* ── FUNC 0x23339c · oggpack_writeclear · size=44 · insn=11 */
/* @0x23339c push {r4, lr} */
/* @0x2333a0 mov r4, r0 */
/* @0x2333a4 ldr r0, [r0, #0x8] */
/* @0x2333a8 cmp r0, #0 */
/* @0x2333ac beq 0x2333b4 <oggpack_writeclear+0x18> */
/* @0x2333b0 bl 0xb655c <free@plt> */
/* @0x2333b4 mov r0, r4 */
/* @0x2333b8 mov r1, #0 */
/* @0x2333bc mov r2, #20 */
/* @0x2333c0 pop {r4, lr} */
/* @0x2333c4 b 0xb65b0 <memset@plt> */

/* ── FUNC 0x2333c8 · oggpack_write · size=368 · insn=92 */
/* @0x2333c8 cmp r2, #32 */
/* @0x2333cc push {r4, r5, lr} */
/* @0x2333d0 mov r4, r0 */
/* @0x2333d4 sub sp, sp, #12 */
/* @0x2333d8 mov r5, r1 */
/* @0x2333dc bhi 0x2334e8 <oggpack_write+0x120> */
/* @0x2333e0 ldr r3, [r0, #0x10] */
/* @0x2333e4 ldr r0, [r0] */
/* @0x2333e8 sub r1, r3, #4 */
/* @0x2333ec cmp r0, r1 */
/* @0x2333f0 bge 0x2334cc <oggpack_write+0x104> */
/* @0x2333f4 ldr r3, [r4, #0xc] */
/* @0x2333f8 ldr r12, [pc, #0x134] */
/* @0x2333fc ldr r1, [r4, #0x4] */
/* @0x233400 add r12, pc, r12 */
/* @0x233404 ldrb r0, [r3] */
/* @0x233408 ldr r12, [r12, r2, lsl #2] */
/* @0x23340c add r2, r2, r1 */
/* @0x233410 cmp r2, #7 */
/* @0x233414 and r5, r5, r12 */
/* @0x233418 orr r1, r0, r5, lsl r1 */
/* @0x23341c strb r1, [r3] */
/* @0x233420 ble 0x233494 <oggpack_write+0xcc> */
/* @0x233424 ldr r1, [r4, #0x4] */
/* @0x233428 cmp r2, #15 */
/* @0x23342c ldr r3, [r4, #0xc] */
/* @0x233430 rsb r1, r1, #8 */
/* @0x233434 lsr r1, r5, r1 */
/* @0x233438 strb r1, [r3, #0x1] */
/* @0x23343c ble 0x233494 <oggpack_write+0xcc> */
/* @0x233440 ldr r1, [r4, #0x4] */
/* @0x233444 cmp r2, #23 */
/* @0x233448 ldr r3, [r4, #0xc] */
/* @0x23344c rsb r1, r1, #16 */
/* @0x233450 lsr r1, r5, r1 */
/* @0x233454 strb r1, [r3, #0x2] */
/* @0x233458 ble 0x233494 <oggpack_write+0xcc> */
/* @0x23345c ldr r1, [r4, #0x4] */
/* @0x233460 cmp r2, #31 */
/* @0x233464 ldr r3, [r4, #0xc] */
/* @0x233468 rsb r1, r1, #24 */
/* @0x23346c lsr r1, r5, r1 */
/* @0x233470 strb r1, [r3, #0x3] */
/* @0x233474 ble 0x233494 <oggpack_write+0xcc> */
/* @0x233478 ldr r3, [r4, #0x4] */
/* @0x23347c ldr r1, [r4, #0xc] */
/* @0x233480 cmp r3, #0 */
/* @0x233484 rsbne r3, r3, #32 */
/* @0x233488 lsrne r5, r5, r3 */
/* @0x23348c strbeq r3, [r1, #0x4] */
/* @0x233490 strbne r5, [r1, #0x4] */
/* @0x233494 cmp r2, #0 */
/* @0x233498 add r3, r2, #7 */
/* @0x23349c ldr r0, [r4] */
/* @0x2334a0 movge r3, r2 */
/* @0x2334a4 ldr r1, [r4, #0xc] */
/* @0x2334a8 asr r3, r3, #3 */
/* @0x2334ac and r2, r2, #7 */
/* @0x2334b0 str r2, [r4, #0x4] */
/* @0x2334b4 add r2, r0, r3 */
/* @0x2334b8 add r3, r1, r3 */
/* @0x2334bc str r2, [r4] */
/* @0x2334c0 str r3, [r4, #0xc] */
/* @0x2334c4 add sp, sp, #12 */
/* @0x2334c8 pop {r4, r5, pc} */
/* @0x2334cc ldr r1, [r4, #0xc] */
/* @0x2334d0 cmp r1, #0 */
/* @0x2334d4 beq 0x2334c4 <oggpack_write+0xfc> */
/* @0x2334d8 movw r1, #0xfeff */
/* @0x2334dc movt r1, #0x7fff */
/* @0x2334e0 cmp r3, r1 */
/* @0x2334e4 ble 0x2334f8 <oggpack_write+0x130> */
/* @0x2334e8 mov r0, r4 */
/* @0x2334ec add sp, sp, #12 */
/* @0x2334f0 pop {r4, r5, lr} */
/* @0x2334f4 b 0x23339c <oggpack_writeclear> */
/* @0x2334f8 ldr r0, [r4, #0x8] */
/* @0x2334fc add r1, r3, #256 */
/* @0x233500 str r2, [sp, #0x4] */
/* @0x233504 bl 0xb6c28 <realloc@plt> */
/* @0x233508 ldr r2, [sp, #0x4] */
/* @0x23350c cmp r0, #0 */
/* @0x233510 beq 0x2334e8 <oggpack_write+0x120> */
/* @0x233514 ldr r1, [r4, #0x10] */
/* @0x233518 ldr r3, [r4] */
/* @0x23351c add r1, r1, #256 */
/* @0x233520 str r0, [r4, #0x8] */
/* @0x233524 add r3, r0, r3 */
/* @0x233528 str r1, [r4, #0x10] */
/* @0x23352c str r3, [r4, #0xc] */
/* @0x233530 b 0x2333f8 <oggpack_write+0x30> */
/* @0x233534 andseq r5, r3, r8, lsr r6 */

/* ── FUNC 0x233538 · oggpack_writealign · size=24 · insn=6 */
/* @0x233538 ldr r2, [r0, #0x4] */
/* @0x23353c rsb r2, r2, #8 */
/* @0x233540 cmp r2, #7 */
/* @0x233544 bxgt lr */
/* @0x233548 mov r1, #0 */
/* @0x23354c b 0x2333c8 <oggpack_write> */

/* ── FUNC 0x233550 · oggpackB_write · size=376 · insn=94 */
/* @0x233550 cmp r2, #32 */
/* @0x233554 push {r4, r5, r6, lr} */
/* @0x233558 mov r4, r0 */
/* @0x23355c sub sp, sp, #8 */
/* @0x233560 mov r5, r1 */
/* @0x233564 bhi 0x233678 <oggpackB_write+0x128> */
/* @0x233568 ldr r3, [r0, #0x10] */
/* @0x23356c ldr r0, [r0] */
/* @0x233570 sub r1, r3, #4 */
/* @0x233574 cmp r0, r1 */
/* @0x233578 bge 0x23365c <oggpackB_write+0x10c> */
/* @0x23357c ldr r3, [r4, #0xc] */
/* @0x233580 ldr r6, [pc, #0x13c] */
/* @0x233584 rsb r12, r2, #32 */
/* @0x233588 ldr r1, [r4, #0x4] */
/* @0x23358c add r6, pc, r6 */
/* @0x233590 ldrb r0, [r3] */
/* @0x233594 ldr r6, [r6, r2, lsl #2] */
/* @0x233598 add r2, r2, r1 */
/* @0x23359c cmp r2, #7 */
/* @0x2335a0 add r1, r1, #24 */
/* @0x2335a4 and r5, r5, r6 */
/* @0x2335a8 lsl r5, r5, r12 */
/* @0x2335ac orr r1, r0, r5, lsr r1 */
/* @0x2335b0 strb r1, [r3] */
/* @0x2335b4 ble 0x233624 <oggpackB_write+0xd4> */
/* @0x2335b8 ldr r1, [r4, #0x4] */
/* @0x2335bc cmp r2, #15 */
/* @0x2335c0 ldr r3, [r4, #0xc] */
/* @0x2335c4 add r1, r1, #16 */
/* @0x2335c8 lsr r1, r5, r1 */
/* @0x2335cc strb r1, [r3, #0x1] */
/* @0x2335d0 ble 0x233624 <oggpackB_write+0xd4> */
/* @0x2335d4 ldr r1, [r4, #0x4] */
/* @0x2335d8 cmp r2, #23 */
/* @0x2335dc ldr r3, [r4, #0xc] */
/* @0x2335e0 add r1, r1, #8 */
/* @0x2335e4 lsr r1, r5, r1 */
/* @0x2335e8 strb r1, [r3, #0x2] */
/* @0x2335ec ble 0x233624 <oggpackB_write+0xd4> */
/* @0x2335f0 ldr r3, [r4, #0xc] */
/* @0x2335f4 cmp r2, #31 */
/* @0x2335f8 ldr r1, [r4, #0x4] */
/* @0x2335fc lsr r1, r5, r1 */
/* @0x233600 strb r1, [r3, #0x3] */
/* @0x233604 ble 0x233624 <oggpackB_write+0xd4> */
/* @0x233608 ldr r3, [r4, #0x4] */
/* @0x23360c ldr r1, [r4, #0xc] */
/* @0x233610 cmp r3, #0 */
/* @0x233614 rsbne r3, r3, #8 */
/* @0x233618 lslne r5, r5, r3 */
/* @0x23361c strbeq r3, [r1, #0x4] */
/* @0x233620 strbne r5, [r1, #0x4] */
/* @0x233624 cmp r2, #0 */
/* @0x233628 add r3, r2, #7 */
/* @0x23362c ldr r0, [r4] */
/* @0x233630 movge r3, r2 */
/* @0x233634 ldr r1, [r4, #0xc] */
/* @0x233638 asr r3, r3, #3 */
/* @0x23363c and r2, r2, #7 */
/* @0x233640 str r2, [r4, #0x4] */
/* @0x233644 add r2, r0, r3 */
/* @0x233648 add r3, r1, r3 */
/* @0x23364c str r2, [r4] */
/* @0x233650 str r3, [r4, #0xc] */
/* @0x233654 add sp, sp, #8 */
/* @0x233658 pop {r4, r5, r6, pc} */
/* @0x23365c ldr r1, [r4, #0xc] */
/* @0x233660 cmp r1, #0 */
/* @0x233664 beq 0x233654 <oggpackB_write+0x104> */
/* @0x233668 movw r1, #0xfeff */
/* @0x23366c movt r1, #0x7fff */
/* @0x233670 cmp r3, r1 */
/* @0x233674 ble 0x233688 <oggpackB_write+0x138> */
/* @0x233678 mov r0, r4 */
/* @0x23367c add sp, sp, #8 */
/* @0x233680 pop {r4, r5, r6, lr} */
/* @0x233684 b 0x23339c <oggpack_writeclear> */
/* @0x233688 ldr r0, [r4, #0x8] */
/* @0x23368c add r1, r3, #256 */
/* @0x233690 str r2, [sp, #0x4] */
/* @0x233694 bl 0xb6c28 <realloc@plt> */
/* @0x233698 ldr r2, [sp, #0x4] */
/* @0x23369c cmp r0, #0 */
/* @0x2336a0 beq 0x233678 <oggpackB_write+0x128> */
/* @0x2336a4 ldr r1, [r4, #0x10] */
/* @0x2336a8 ldr r3, [r4] */
/* @0x2336ac add r1, r1, #256 */
/* @0x2336b0 str r0, [r4, #0x8] */
/* @0x2336b4 add r3, r0, r3 */
/* @0x2336b8 str r1, [r4, #0x10] */
/* @0x2336bc str r3, [r4, #0xc] */
/* @0x2336c0 b 0x233580 <oggpackB_write+0x30> */
/* @0x2336c4 andseq r5, r3, r12, lsr #9 */

/* ── FUNC 0x2336c8 · oggpackB_writealign · size=24 · insn=6 */
/* @0x2336c8 ldr r2, [r0, #0x4] */
/* @0x2336cc rsb r2, r2, #8 */
/* @0x2336d0 cmp r2, #7 */
/* @0x2336d4 bxgt lr */
/* @0x2336d8 mov r1, #0 */
/* @0x2336dc b 0x233550 <oggpackB_write> */

/* ── FUNC 0x2336e0 · anon_2336e0 · size=296 · insn=74 */
/* @0x2336e0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2336e4 mov r8, r2 */
/* @0x2336e8 ldr r2, [r0, #0x4] */
/* @0x2336ec cmp r8, #0 */
/* @0x2336f0 add r9, r8, #7 */
/* @0x2336f4 mov r5, r0 */
/* @0x2336f8 movge r9, r8 */
/* @0x2336fc cmp r2, #0 */
/* @0x233700 mov r10, r1 */
/* @0x233704 mov r6, r3 */
/* @0x233708 asr r9, r9, #3 */
/* @0x23370c ldr r11, [sp, #0x28] */
/* @0x233710 beq 0x233768 <oggpackB_writealign+0xa0> */
/* @0x233714 cmp r9, #0 */
/* @0x233718 ble 0x23373c <oggpackB_writealign+0x74> */
/* @0x23371c add r7, r1, r9 */
/* @0x233720 mov r4, r1 */
/* @0x233724 ldrb r1, [r4], #1 */
/* @0x233728 mov r0, r5 */
/* @0x23372c mov r2, #8 */
/* @0x233730 blx r6 */
/* @0x233734 cmp r4, r7 */
/* @0x233738 bne 0x233724 <oggpackB_writealign+0x5c> */
/* @0x23373c subs r2, r8, r9, lsl #3 */
/* @0x233740 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x233744 cmp r11, #0 */
/* @0x233748 rsbne r3, r2, #8 */
/* @0x23374c ldrbne r1, [r10, r9] */
/* @0x233750 movne r0, r5 */
/* @0x233754 moveq r0, r5 */
/* @0x233758 ldrbeq r1, [r10, r9] */
/* @0x23375c asrne r1, r1, r3 */
/* @0x233760 blx r6 */
/* @0x233764 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x233768 ldr r3, [r0] */
/* @0x23376c ldr r2, [r0, #0x10] */
/* @0x233770 add r3, r9, r3 */
/* @0x233774 add r1, r3, #1 */
/* @0x233778 cmp r1, r2 */
/* @0x23377c ldrlt r0, [r0, #0xc] */
/* @0x233780 blt 0x2337d0 <oggpackB_writealign+0x108> */
/* @0x233784 ldr r1, [r5, #0xc] */
/* @0x233788 cmp r1, #0 */
/* @0x23378c beq 0x23379c <oggpackB_writealign+0xd4> */
/* @0x233790 add r1, r3, #255 */
/* @0x233794 cmp r2, r1 */
/* @0x233798 bgt 0x2337a8 <oggpackB_writealign+0xe0> */
/* @0x23379c mov r0, r5 */
/* @0x2337a0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2337a4 b 0x23339c <oggpack_writeclear> */
/* @0x2337a8 add r1, r3, #256 */
/* @0x2337ac ldr r0, [r5, #0x8] */
/* @0x2337b0 str r1, [r5, #0x10] */
/* @0x2337b4 bl 0xb6c28 <realloc@plt> */
/* @0x2337b8 cmp r0, #0 */
/* @0x2337bc beq 0x23379c <oggpackB_writealign+0xd4> */
/* @0x2337c0 ldr r3, [r5] */
/* @0x2337c4 str r0, [r5, #0x8] */
/* @0x2337c8 add r0, r0, r3 */
/* @0x2337cc str r0, [r5, #0xc] */
/* @0x2337d0 mov r1, r10 */
/* @0x2337d4 mov r2, r9 */
/* @0x2337d8 bl 0xb6694 <memmove@plt> */
/* @0x2337dc ldr r3, [r5, #0xc] */
/* @0x2337e0 ldr r1, [r5] */
/* @0x2337e4 mov r2, #0 */
/* @0x2337e8 add r0, r3, r9 */
/* @0x2337ec str r0, [r5, #0xc] */
/* @0x2337f0 add r1, r1, r9 */
/* @0x2337f4 str r1, [r5] */
/* @0x2337f8 strb r2, [r3, r9] */
/* @0x2337fc subs r2, r8, r9, lsl #3 */
/* @0x233800 bne 0x233744 <oggpackB_writealign+0x7c> */
/* @0x233804 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x233808 · oggpack_writecopy · size=40 · insn=10 */
/* @0x233808 str lr, [sp, #-0x4]! */
/* @0x23380c sub sp, sp, #12 */
/* @0x233810 ldr r3, [pc, #0x14] */
/* @0x233814 mov r12, #0 */
/* @0x233818 str r12, [sp] */
/* @0x23381c ldr r3, [pc, r3] */
/* @0x233820 bl 0x2336e0 <oggpackB_writealign+0x18> */
/* @0x233824 add sp, sp, #12 */
/* @0x233828 ldr pc, [sp], #4 */
/* @0x23382c andseq sp, r11, r8, ror r12 */

/* ── FUNC 0x233830 · oggpackB_writecopy · size=40 · insn=10 */
/* @0x233830 str lr, [sp, #-0x4]! */
/* @0x233834 sub sp, sp, #12 */
/* @0x233838 ldr r3, [pc, #0x14] */
/* @0x23383c mov r12, #1 */
/* @0x233840 str r12, [sp] */
/* @0x233844 ldr r3, [pc, r3] */
/* @0x233848 bl 0x2336e0 <oggpackB_writealign+0x18> */
/* @0x23384c add sp, sp, #12 */
/* @0x233850 ldr pc, [sp], #4 */
/* @0x233854 andseq sp, r11, r4, asr r12 */

/* ── FUNC 0x233858 · oggpackB_writeclear · size=4 · insn=1 */
/* @0x233858 b 0x23339c <oggpack_writeclear> */

/* ── FUNC 0x23385c · oggpack_readinit · size=44 · insn=11 */
/* @0x23385c push {r4, r5, r6, lr} */
/* @0x233860 mov r4, r0 */
/* @0x233864 mov r5, r1 */
/* @0x233868 mov r6, r2 */
/* @0x23386c mov r1, #0 */
/* @0x233870 mov r2, #20 */
/* @0x233874 bl 0xb65b0 <memset@plt> */
/* @0x233878 str r6, [r4, #0x10] */
/* @0x23387c str r5, [r4, #0xc] */
/* @0x233880 str r5, [r4, #0x8] */
/* @0x233884 pop {r4, r5, r6, pc} */

/* ── FUNC 0x233888 · oggpackB_readinit · size=4 · insn=1 */
/* @0x233888 b 0x23385c <oggpack_readinit> */

/* ── FUNC 0x23388c · oggpack_look · size=204 · insn=51 */
/* @0x23388c cmp r1, #32 */
/* @0x233890 push {r4, r5} */
/* @0x233894 bhi 0x23394c <oggpack_look+0xc0> */
/* @0x233898 ldr r4, [r0, #0x10] */
/* @0x23389c ldr r12, [r0] */
/* @0x2338a0 ldr r2, [pc, #0xac] */
/* @0x2338a4 sub r3, r4, #4 */
/* @0x2338a8 cmp r12, r3 */
/* @0x2338ac ldr r3, [r0, #0x4] */
/* @0x2338b0 add r2, pc, r2 */
/* @0x2338b4 ldr r5, [r2, r1, lsl #2] */
/* @0x2338b8 add r1, r3, r1 */
/* @0x2338bc blt 0x2338dc <oggpack_look+0x50> */
/* @0x2338c0 add r2, r1, #7 */
/* @0x2338c4 sub r4, r4, r2, asr #3 */
/* @0x2338c8 cmp r12, r4 */
/* @0x2338cc bgt 0x23394c <oggpack_look+0xc0> */
/* @0x2338d0 cmp r1, #0 */
/* @0x2338d4 moveq r0, r1 */
/* @0x2338d8 beq 0x2338f4 <oggpack_look+0x68> */
/* @0x2338dc ldr r12, [r0, #0xc] */
/* @0x2338e0 cmp r1, #8 */
/* @0x2338e4 ldrb r2, [r12] */
/* @0x2338e8 asr r2, r2, r3 */
/* @0x2338ec bgt 0x2338fc <oggpack_look+0x70> */
/* @0x2338f0 and r0, r2, r5 */
/* @0x2338f4 pop {r4, r5} */
/* @0x2338f8 bx lr */
/* @0x2338fc ldrb r4, [r12, #0x1] */
/* @0x233900 cmp r1, #16 */
/* @0x233904 rsb r0, r3, #8 */
/* @0x233908 orr r2, r2, r4, lsl r0 */
/* @0x23390c ble 0x2338f0 <oggpack_look+0x64> */
/* @0x233910 ldrb r4, [r12, #0x2] */
/* @0x233914 cmp r1, #24 */
/* @0x233918 rsb r0, r3, #16 */
/* @0x23391c orr r2, r2, r4, lsl r0 */
/* @0x233920 ble 0x2338f0 <oggpack_look+0x64> */
/* @0x233924 ldrb r0, [r12, #0x3] */
/* @0x233928 cmp r1, #32 */
/* @0x23392c rsb r1, r3, #24 */
/* @0x233930 orr r2, r2, r0, lsl r1 */
/* @0x233934 ble 0x2338f0 <oggpack_look+0x64> */
/* @0x233938 cmp r3, #0 */
/* @0x23393c rsbne r3, r3, #32 */
/* @0x233940 ldrbne r1, [r12, #0x4] */
/* @0x233944 orrne r2, r2, r1, lsl r3 */
/* @0x233948 b 0x2338f0 <oggpack_look+0x64> */
/* @0x23394c mvn r0, #0 */
/* @0x233950 b 0x2338f4 <oggpack_look+0x68> */
/* @0x233954 andseq r5, r3, r8, lsl #3 */

/* ── FUNC 0x233958 · oggpackB_look · size=208 · insn=52 */
/* @0x233958 rsb r12, r1, #32 */
/* @0x23395c cmp r12, #32 */
/* @0x233960 push {r4, r5, r6} */
/* @0x233964 bhi 0x233a20 <oggpackB_look+0xc8> */
/* @0x233968 ldr r5, [r0, #0x10] */
/* @0x23396c ldr r4, [r0] */
/* @0x233970 sub r3, r5, #4 */
/* @0x233974 ldr r2, [r0, #0x4] */
/* @0x233978 cmp r4, r3 */
/* @0x23397c add r3, r2, r1 */
/* @0x233980 blt 0x2339a0 <oggpackB_look+0x48> */
/* @0x233984 add r6, r3, #7 */
/* @0x233988 sub r5, r5, r6, asr #3 */
/* @0x23398c cmp r4, r5 */
/* @0x233990 bgt 0x233a20 <oggpackB_look+0xc8> */
/* @0x233994 cmp r3, #0 */
/* @0x233998 moveq r0, r3 */
/* @0x23399c beq 0x2339cc <oggpackB_look+0x74> */
/* @0x2339a0 ldr r4, [r0, #0xc] */
/* @0x2339a4 cmp r3, #8 */
/* @0x2339a8 add r0, r2, #24 */
/* @0x2339ac ldrb r5, [r4] */
/* @0x2339b0 lsl r0, r5, r0 */
/* @0x2339b4 bgt 0x2339d4 <oggpackB_look+0x7c> */
/* @0x2339b8 asr r12, r12, #1 */
/* @0x2339bc rsb r1, r1, #33 */
/* @0x2339c0 lsr r0, r0, r12 */
/* @0x2339c4 asr r1, r1, #1 */
/* @0x2339c8 lsr r0, r0, r1 */
/* @0x2339cc pop {r4, r5, r6} */
/* @0x2339d0 bx lr */
/* @0x2339d4 ldrb r6, [r4, #0x1] */
/* @0x2339d8 cmp r3, #16 */
/* @0x2339dc add r5, r2, #16 */
/* @0x2339e0 orr r0, r0, r6, lsl r5 */
/* @0x2339e4 ble 0x2339b8 <oggpackB_look+0x60> */
/* @0x2339e8 ldrb r6, [r4, #0x2] */
/* @0x2339ec cmp r3, #24 */
/* @0x2339f0 add r5, r2, #8 */
/* @0x2339f4 orr r0, r0, r6, lsl r5 */
/* @0x2339f8 ble 0x2339b8 <oggpackB_look+0x60> */
/* @0x2339fc ldrb r5, [r4, #0x3] */
/* @0x233a00 cmp r3, #32 */
/* @0x233a04 orr r0, r0, r5, lsl r2 */
/* @0x233a08 ble 0x2339b8 <oggpackB_look+0x60> */
/* @0x233a0c cmp r2, #0 */
/* @0x233a10 rsbne r2, r2, #8 */
/* @0x233a14 ldrbne r3, [r4, #0x4] */
/* @0x233a18 orrne r0, r0, r3, asr r2 */
/* @0x233a1c b 0x2339b8 <oggpackB_look+0x60> */
/* @0x233a20 mvn r0, #0 */
/* @0x233a24 b 0x2339cc <oggpackB_look+0x74> */

/* ── FUNC 0x233a28 · oggpack_look1 · size=40 · insn=10 */
/* @0x233a28 ldr r2, [r0] */
/* @0x233a2c ldr r3, [r0, #0x10] */
/* @0x233a30 cmp r2, r3 */
/* @0x233a34 ldrlt r2, [r0, #0xc] */
/* @0x233a38 ldrlt r3, [r0, #0x4] */
/* @0x233a3c ldrblt r0, [r2] */
/* @0x233a40 asrlt r0, r0, r3 */
/* @0x233a44 andlt r0, r0, #1 */
/* @0x233a48 mvnge r0, #0 */
/* @0x233a4c bx lr */

/* ── FUNC 0x233a50 · oggpackB_look1 · size=44 · insn=11 */
/* @0x233a50 ldr r3, [r0, #0x10] */
/* @0x233a54 ldr r2, [r0] */
/* @0x233a58 cmp r2, r3 */
/* @0x233a5c ldrlt r3, [r0, #0xc] */
/* @0x233a60 ldrlt r0, [r0, #0x4] */
/* @0x233a64 ldrblt r3, [r3] */
/* @0x233a68 rsblt r0, r0, #7 */
/* @0x233a6c asrlt r0, r3, r0 */
/* @0x233a70 andlt r0, r0, #1 */
/* @0x233a74 mvnge r0, #0 */
/* @0x233a78 bx lr */

/* ── FUNC 0x233a7c · oggpack_adv · size=112 · insn=28 */
/* @0x233a7c ldr r2, [r0, #0x4] */
/* @0x233a80 ldr r3, [r0, #0x10] */
/* @0x233a84 add r1, r1, r2 */
/* @0x233a88 ldr r2, [r0] */
/* @0x233a8c add r12, r1, #7 */
/* @0x233a90 str r4, [sp, #-0x4]! */
/* @0x233a94 sub r4, r3, r12, asr #3 */
/* @0x233a98 cmp r2, r4 */
/* @0x233a9c ble 0x233abc <oggpack_adv+0x40> */
/* @0x233aa0 str r3, [r0] */
/* @0x233aa4 mov r2, #0 */
/* @0x233aa8 mov r3, #1 */
/* @0x233aac str r2, [r0, #0xc] */
/* @0x233ab0 str r3, [r0, #0x4] */
/* @0x233ab4 ldr r4, [sp], #4 */
/* @0x233ab8 bx lr */
/* @0x233abc cmp r1, #0 */
/* @0x233ac0 ldr r3, [r0, #0xc] */
/* @0x233ac4 ldr r4, [sp], #4 */
/* @0x233ac8 movge r12, r1 */
/* @0x233acc and r1, r1, #7 */
/* @0x233ad0 asr r12, r12, #3 */
/* @0x233ad4 str r1, [r0, #0x4] */
/* @0x233ad8 add r2, r2, r12 */
/* @0x233adc add r12, r3, r12 */
/* @0x233ae0 str r2, [r0] */
/* @0x233ae4 str r12, [r0, #0xc] */
/* @0x233ae8 bx lr */

/* ── FUNC 0x233aec · oggpackB_adv · size=4 · insn=1 */
/* @0x233aec b 0x233a7c <oggpack_adv> */

/* ── FUNC 0x233af0 · oggpack_adv1 · size=52 · insn=13 */
/* @0x233af0 ldr r3, [r0, #0x4] */
/* @0x233af4 add r3, r3, #1 */
/* @0x233af8 cmp r3, #7 */
/* @0x233afc strle r3, [r0, #0x4] */
/* @0x233b00 ldrgt r2, [r0, #0xc] */
/* @0x233b04 movgt r1, #0 */
/* @0x233b08 ldrgt r3, [r0] */
/* @0x233b0c addgt r2, r2, #1 */
/* @0x233b10 strgt r1, [r0, #0x4] */
/* @0x233b14 addgt r3, r3, #1 */
/* @0x233b18 strgt r2, [r0, #0xc] */
/* @0x233b1c strgt r3, [r0] */
/* @0x233b20 bx lr */
