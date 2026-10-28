/* libyoyo.so 覆盖卡组 0263
 * 函数 0x2b1891..0x2b35c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2b1891 · png_write_iCCP · size=252 · insn=0 */

/* ── FUNC 0x2b198d · png_write_sPLT · size=288 · insn=0 */

/* ── FUNC 0x2b1aad · png_write_sBIT · size=160 · insn=0 */

/* ── FUNC 0x2b1b51 · png_write_cHRM · size=368 · insn=0 */

/* ── FUNC 0x2b1cc1 · png_write_cHRM_fixed · size=192 · insn=0 */

/* ── FUNC 0x2b1d81 · png_write_tRNS · size=212 · insn=0 */

/* ── FUNC 0x2b1e55 · png_write_bKGD · size=212 · insn=0 */

/* ── FUNC 0x2b1f29 · png_write_hIST · size=108 · insn=0 */

/* ── FUNC 0x2b1f95 · png_write_tEXt · size=112 · insn=0 */

/* ── FUNC 0x2b2005 · png_write_zTXt · size=180 · insn=0 */

/* ── FUNC 0x2b20b9 · png_write_iTXt · size=288 · insn=0 */

/* ── FUNC 0x2b21d9 · png_write_oFFs · size=120 · insn=0 */

/* ── FUNC 0x2b2251 · png_write_pCAL · size=308 · insn=0 */

/* ── FUNC 0x2b2385 · png_write_sCAL · size=148 · insn=0 */

/* ── FUNC 0x2b2419 · png_write_pHYs · size=120 · insn=0 */

/* ── FUNC 0x2b2491 · png_write_tIME · size=128 · insn=0 */

/* ── FUNC 0x2b2511 · png_write_start_row · size=252 · insn=0 */

/* ── FUNC 0x2b260d · png_write_finish_row · size=400 · insn=0 */

/* ── FUNC 0x2b279d · png_do_write_interlace · size=416 · insn=0 */

/* ── FUNC 0x2b293d · png_write_filtered_row · size=156 · insn=0 */

/* ── FUNC 0x2b29d9 · png_write_find_filter · size=1060 · insn=0 */

/* ── FUNC 0x2b2dfc · jpeg_CreateDecompress · size=260 · insn=65 */
/* @0x2b2dfc cmp r1, #62 */
/* @0x2b2e00 mov r3, #0 */
/* @0x2b2e04 push {r4, r5, r6, lr} */
/* @0x2b2e08 mov r4, r0 */
/* @0x2b2e0c mov r5, r2 */
/* @0x2b2e10 str r3, [r0, #0x4] */
/* @0x2b2e14 beq 0x2b2e40 <jpeg_CreateDecompress+0x44> */
/* @0x2b2e18 ldr r3, [r0] */
/* @0x2b2e1c mov r2, #62 */
/* @0x2b2e20 mov r12, #12 */
/* @0x2b2e24 str r2, [r3, #0x18] */
/* @0x2b2e28 ldr r2, [r0] */
/* @0x2b2e2c str r12, [r3, #0x14] */
/* @0x2b2e30 str r1, [r2, #0x1c] */
/* @0x2b2e34 ldr r3, [r0] */
/* @0x2b2e38 ldr r3, [r3] */
/* @0x2b2e3c blx r3 */
/* @0x2b2e40 cmp r5, #432 */
/* @0x2b2e44 beq 0x2b2e74 <jpeg_CreateDecompress+0x78> */
/* @0x2b2e48 ldr r3, [r4] */
/* @0x2b2e4c mov r2, #432 */
/* @0x2b2e50 mov r1, #21 */
/* @0x2b2e54 mov r0, r4 */
/* @0x2b2e58 str r2, [r3, #0x18] */
/* @0x2b2e5c ldr r2, [r4] */
/* @0x2b2e60 str r1, [r3, #0x14] */
/* @0x2b2e64 str r5, [r2, #0x1c] */
/* @0x2b2e68 ldr r3, [r4] */
/* @0x2b2e6c ldr r3, [r3] */
/* @0x2b2e70 blx r3 */
/* @0x2b2e74 ldr r6, [r4] */
/* @0x2b2e78 mov r1, #0 */
/* @0x2b2e7c ldr r5, [r4, #0xc] */
/* @0x2b2e80 mov r2, #432 */
/* @0x2b2e84 mov r0, r4 */
/* @0x2b2e88 bl 0xb65b0 <memset@plt> */
/* @0x2b2e8c mov r3, #1 */
/* @0x2b2e90 mov r0, r4 */
/* @0x2b2e94 strb r3, [r4, #0x10] */
/* @0x2b2e98 str r6, [r4] */
/* @0x2b2e9c str r5, [r4, #0xc] */
/* @0x2b2ea0 bl 0x2ba0b4 <jinit_memory_mgr> */
/* @0x2b2ea4 mov r3, #0 */
/* @0x2b2ea8 mov r0, r4 */
/* @0x2b2eac str r3, [r4, #0x8] */
/* @0x2b2eb0 str r3, [r4, #0x18] */
/* @0x2b2eb4 str r3, [r4, #0x90] */
/* @0x2b2eb8 str r3, [r4, #0x94] */
/* @0x2b2ebc str r3, [r4, #0x98] */
/* @0x2b2ec0 str r3, [r4, #0x9c] */
/* @0x2b2ec4 str r3, [r4, #0xa0] */
/* @0x2b2ec8 str r3, [r4, #0xb0] */
/* @0x2b2ecc str r3, [r4, #0xa4] */
/* @0x2b2ed0 str r3, [r4, #0xb4] */
/* @0x2b2ed4 str r3, [r4, #0xa8] */
/* @0x2b2ed8 str r3, [r4, #0xb8] */
/* @0x2b2edc str r3, [r4, #0xac] */
/* @0x2b2ee0 str r3, [r4, #0xbc] */
/* @0x2b2ee4 str r3, [r4, #0x10c] */
/* @0x2b2ee8 bl 0x2b5efc <jinit_marker_reader> */
/* @0x2b2eec mov r0, r4 */
/* @0x2b2ef0 bl 0x2b3ee0 <jinit_input_controller> */
/* @0x2b2ef4 mov r3, #200 */
/* @0x2b2ef8 str r3, [r4, #0x14] */
/* @0x2b2efc pop {r4, r5, r6, pc} */

/* ── FUNC 0x2b2f00 · jpeg_destroy_decompress · size=4 · insn=1 */
/* @0x2b2f00 b 0x2bc8b8 <jpeg_destroy> */

/* ── FUNC 0x2b2f04 · jpeg_abort_decompress · size=4 · insn=1 */
/* @0x2b2f04 b 0x2bc874 <jpeg_abort> */

/* ── FUNC 0x2b2f08 · jpeg_consume_input · size=688 · insn=172 */
/* @0x2b2f08 ldr r2, [r0, #0x14] */
/* @0x2b2f0c push {r3, r4, r5, r6, r7, lr} */
/* @0x2b2f10 sub r3, r2, #200 */
/* @0x2b2f14 mov r4, r0 */
/* @0x2b2f18 cmp r3, #10 */
/* @0x2b2f1c addls pc, pc, r3, lsl #2 */
/* @0x2b2f20 b 0x2b2fbc <jpeg_consume_input+0xb4> */
/* @0x2b2f24 b 0x2b2f50 <jpeg_consume_input+0x48> */
/* @0x2b2f28 b 0x2b2f74 <jpeg_consume_input+0x6c> */
/* @0x2b2f2c b 0x2b2f98 <jpeg_consume_input+0x90> */
/* @0x2b2f30 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f34 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f38 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f3c b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f40 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f44 b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f48 b 0x2b2fbc <jpeg_consume_input+0xb4> */
/* @0x2b2f4c b 0x2b2fa4 <jpeg_consume_input+0x9c> */
/* @0x2b2f50 ldr r3, [r0, #0x190] */
/* @0x2b2f54 ldr r3, [r3, #0x4] */
/* @0x2b2f58 blx r3 */
/* @0x2b2f5c ldr r3, [r4, #0x18] */
/* @0x2b2f60 mov r0, r4 */
/* @0x2b2f64 ldr r3, [r3, #0x8] */
/* @0x2b2f68 blx r3 */
/* @0x2b2f6c mov r3, #201 */
/* @0x2b2f70 str r3, [r4, #0x14] */
/* @0x2b2f74 ldr r3, [r4, #0x190] */
/* @0x2b2f78 mov r0, r4 */
/* @0x2b2f7c ldr r3, [r3] */
/* @0x2b2f80 blx r3 */
/* @0x2b2f84 cmp r0, #1 */
/* @0x2b2f88 mov r5, r0 */
/* @0x2b2f8c beq 0x2b2fe4 <jpeg_consume_input+0xdc> */
/* @0x2b2f90 mov r0, r5 */
/* @0x2b2f94 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2f98 mov r5, #1 */
/* @0x2b2f9c mov r0, r5 */
/* @0x2b2fa0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fa4 ldr r3, [r0, #0x190] */
/* @0x2b2fa8 ldr r3, [r3] */
/* @0x2b2fac blx r3 */
/* @0x2b2fb0 mov r5, r0 */
/* @0x2b2fb4 mov r0, r5 */
/* @0x2b2fb8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fbc ldr r3, [r0] */
/* @0x2b2fc0 mov r1, #20 */
/* @0x2b2fc4 mov r5, #0 */
/* @0x2b2fc8 str r2, [r3, #0x18] */
/* @0x2b2fcc ldr r2, [r4] */
/* @0x2b2fd0 str r1, [r3, #0x14] */
/* @0x2b2fd4 ldr r3, [r2] */
/* @0x2b2fd8 blx r3 */
/* @0x2b2fdc mov r0, r5 */
/* @0x2b2fe0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b2fe4 ldr r6, [r4, #0x24] */
/* @0x2b2fe8 cmp r6, #3 */
/* @0x2b2fec beq 0x2b3078 <jpeg_consume_input+0x170> */
/* @0x2b2ff0 cmp r6, #4 */
/* @0x2b2ff4 beq 0x2b30dc <jpeg_consume_input+0x1d4> */
/* @0x2b2ff8 cmp r6, #1 */
/* @0x2b2ffc streq r0, [r4, #0x28] */
/* @0x2b3000 streq r0, [r4, #0x2c] */
/* @0x2b3004 movne r3, #0 */
/* @0x2b3008 strne r3, [r4, #0x28] */
/* @0x2b300c strne r3, [r4, #0x2c] */
/* @0x2b3010 mov r1, #0 */
/* @0x2b3014 mov r0, #1 */
/* @0x2b3018 mov r2, #0 */
/* @0x2b301c mov r3, #0 */
/* @0x2b3020 mov r7, #2 */
/* @0x2b3024 movt r3, #0x3ff0 */
/* @0x2b3028 mov r6, #256 */
/* @0x2b302c mov r12, #202 */
/* @0x2b3030 str r0, [r4, #0x30] */
/* @0x2b3034 str r0, [r4, #0x34] */
/* @0x2b3038 strb r0, [r4, #0x48] */
/* @0x2b303c strb r0, [r4, #0x49] */
/* @0x2b3040 strb r0, [r4, #0x50] */
/* @0x2b3044 strb r1, [r4, #0x40] */
/* @0x2b3048 strb r1, [r4, #0x41] */
/* @0x2b304c str r1, [r4, #0x44] */
/* @0x2b3050 strb r1, [r4, #0x4a] */
/* @0x2b3054 strd r2, r3, [r4, #56] */
/* @0x2b3058 str r1, [r4, #0x74] */
/* @0x2b305c strb r1, [r4, #0x58] */
/* @0x2b3060 strb r1, [r4, #0x59] */
/* @0x2b3064 strb r1, [r4, #0x5a] */
/* @0x2b3068 str r7, [r4, #0x4c] */
/* @0x2b306c str r6, [r4, #0x54] */
/* @0x2b3070 str r12, [r4, #0x14] */
/* @0x2b3074 b 0x2b2f90 <jpeg_consume_input+0x88> */
/* @0x2b3078 ldrb r3, [r4, #0x100] */
/* @0x2b307c cmp r3, #0 */
/* @0x2b3080 bne 0x2b3198 <jpeg_consume_input+0x290> */
/* @0x2b3084 ldrb r3, [r4, #0x108] */
/* @0x2b3088 cmp r3, #0 */
/* @0x2b308c beq 0x2b3138 <jpeg_consume_input+0x230> */
/* @0x2b3090 ldrb r3, [r4, #0x109] */
/* @0x2b3094 cmp r3, #0 */
/* @0x2b3098 beq 0x2b31ac <jpeg_consume_input+0x2a4> */
/* @0x2b309c cmp r3, #1 */
/* @0x2b30a0 beq 0x2b30cc <jpeg_consume_input+0x1c4> */
/* @0x2b30a4 ldr r3, [r4] */
/* @0x2b30a8 mov r2, #114 */
/* @0x2b30ac mov r0, r4 */
/* @0x2b30b0 mvn r1, #0 */
/* @0x2b30b4 str r2, [r3, #0x14] */
/* @0x2b30b8 ldrb r2, [r4, #0x109] */
/* @0x2b30bc str r2, [r3, #0x18] */
/* @0x2b30c0 ldr r3, [r4] */
/* @0x2b30c4 ldr r3, [r3, #0x4] */
/* @0x2b30c8 blx r3 */
/* @0x2b30cc str r6, [r4, #0x28] */
/* @0x2b30d0 mov r3, #2 */
/* @0x2b30d4 str r3, [r4, #0x2c] */
/* @0x2b30d8 b 0x2b3010 <jpeg_consume_input+0x108> */
/* @0x2b30dc ldrb r3, [r4, #0x108] */
/* @0x2b30e0 cmp r3, #0 */
/* @0x2b30e4 beq 0x2b31a4 <jpeg_consume_input+0x29c> */
/* @0x2b30e8 ldrb r3, [r4, #0x109] */
/* @0x2b30ec cmp r3, #0 */
/* @0x2b30f0 beq 0x2b31a4 <jpeg_consume_input+0x29c> */
/* @0x2b30f4 cmp r3, #2 */
/* @0x2b30f8 beq 0x2b3124 <jpeg_consume_input+0x21c> */
/* @0x2b30fc ldr r3, [r4] */
/* @0x2b3100 mov r2, #114 */
/* @0x2b3104 mov r0, r4 */
/* @0x2b3108 mvn r1, #0 */
/* @0x2b310c str r2, [r3, #0x14] */
/* @0x2b3110 ldrb r2, [r4, #0x109] */
/* @0x2b3114 str r2, [r3, #0x18] */
/* @0x2b3118 ldr r3, [r4] */
/* @0x2b311c ldr r3, [r3, #0x4] */
/* @0x2b3120 blx r3 */
/* @0x2b3124 mov r3, #5 */
/* @0x2b3128 str r3, [r4, #0x28] */
/* @0x2b312c mov r3, #4 */
/* @0x2b3130 str r3, [r4, #0x2c] */
/* @0x2b3134 b 0x2b3010 <jpeg_consume_input+0x108> */
/* @0x2b3138 ldr r3, [r4, #0xc4] */
/* @0x2b313c ldr r12, [r3] */
/* @0x2b3140 ldr r2, [r3, #0x54] */
/* @0x2b3144 ldr r6, [r3, #0xa8] */
/* @0x2b3148 cmp r12, #1 */
/* @0x2b314c cmpeq r2, #2 */
/* @0x2b3150 bne 0x2b315c <jpeg_consume_input+0x254> */
/* @0x2b3154 cmp r6, #3 */
/* @0x2b3158 beq 0x2b3198 <jpeg_consume_input+0x290> */
/* @0x2b315c cmp r12, #82 */
/* @0x2b3160 cmpeq r2, #71 */
/* @0x2b3164 bne 0x2b3170 <jpeg_consume_input+0x268> */
/* @0x2b3168 cmp r6, #66 */
/* @0x2b316c beq 0x2b31ac <jpeg_consume_input+0x2a4> */
/* @0x2b3170 ldr r3, [r4] */
/* @0x2b3174 mov lr, #111 */
/* @0x2b3178 mov r0, r4 */
/* @0x2b317c mov r1, #1 */
/* @0x2b3180 str r12, [r3, #0x18] */
/* @0x2b3184 str r2, [r3, #0x1c] */
/* @0x2b3188 str r6, [r3, #0x20] */
/* @0x2b318c str lr, [r3, #0x14] */
/* @0x2b3190 ldr r3, [r3, #0x4] */
/* @0x2b3194 blx r3 */
/* @0x2b3198 mov r3, #3 */
/* @0x2b319c str r3, [r4, #0x28] */
/* @0x2b31a0 b 0x2b30d0 <jpeg_consume_input+0x1c8> */
/* @0x2b31a4 str r6, [r4, #0x28] */
/* @0x2b31a8 b 0x2b312c <jpeg_consume_input+0x224> */
/* @0x2b31ac mov r3, #2 */
/* @0x2b31b0 str r3, [r4, #0x28] */
/* @0x2b31b4 b 0x2b30d0 <jpeg_consume_input+0x1c8> */

/* ── FUNC 0x2b31b8 · jpeg_read_header · size=136 · insn=34 */
/* @0x2b31b8 ldr r3, [r0, #0x14] */
/* @0x2b31bc push {r4, r5, r6, lr} */
/* @0x2b31c0 sub r2, r3, #200 */
/* @0x2b31c4 cmp r2, #1 */
/* @0x2b31c8 mov r4, r0 */
/* @0x2b31cc mov r6, r1 */
/* @0x2b31d0 bls 0x2b31f0 <jpeg_read_header+0x38> */
/* @0x2b31d4 ldr r2, [r0] */
/* @0x2b31d8 mov r1, #20 */
/* @0x2b31dc str r3, [r2, #0x18] */
/* @0x2b31e0 ldr r3, [r0] */
/* @0x2b31e4 str r1, [r2, #0x14] */
/* @0x2b31e8 ldr r3, [r3] */
/* @0x2b31ec blx r3 */
/* @0x2b31f0 mov r0, r4 */
/* @0x2b31f4 bl 0x2b2f08 <jpeg_consume_input> */
/* @0x2b31f8 cmp r0, #2 */
/* @0x2b31fc mov r5, r0 */
/* @0x2b3200 beq 0x2b320c <jpeg_read_header+0x54> */
/* @0x2b3204 mov r0, r5 */
/* @0x2b3208 pop {r4, r5, r6, pc} */
/* @0x2b320c cmp r6, #0 */
/* @0x2b3210 bne 0x2b3224 <jpeg_read_header+0x6c> */
/* @0x2b3214 mov r0, r4 */
/* @0x2b3218 bl 0x2bc874 <jpeg_abort> */
/* @0x2b321c mov r0, r5 */
/* @0x2b3220 pop {r4, r5, r6, pc} */
/* @0x2b3224 ldr r3, [r4] */
/* @0x2b3228 mov r2, #51 */
/* @0x2b322c mov r0, r4 */
/* @0x2b3230 str r2, [r3, #0x14] */
/* @0x2b3234 ldr r3, [r3] */
/* @0x2b3238 blx r3 */
/* @0x2b323c b 0x2b3214 <jpeg_read_header+0x5c> */

/* ── FUNC 0x2b3240 · jpeg_input_complete · size=64 · insn=16 */
/* @0x2b3240 ldr r3, [r0, #0x14] */
/* @0x2b3244 push {r4, lr} */
/* @0x2b3248 sub r2, r3, #200 */
/* @0x2b324c cmp r2, #10 */
/* @0x2b3250 mov r4, r0 */
/* @0x2b3254 bls 0x2b3274 <jpeg_input_complete+0x34> */
/* @0x2b3258 ldr r2, [r0] */
/* @0x2b325c mov r1, #20 */
/* @0x2b3260 str r3, [r2, #0x18] */
/* @0x2b3264 ldr r3, [r0] */
/* @0x2b3268 str r1, [r2, #0x14] */
/* @0x2b326c ldr r3, [r3] */
/* @0x2b3270 blx r3 */
/* @0x2b3274 ldr r3, [r4, #0x190] */
/* @0x2b3278 ldrb r0, [r3, #0x11] */
/* @0x2b327c pop {r4, pc} */

/* ── FUNC 0x2b3280 · jpeg_has_multiple_scans · size=64 · insn=16 */
/* @0x2b3280 ldr r3, [r0, #0x14] */
/* @0x2b3284 push {r4, lr} */
/* @0x2b3288 sub r2, r3, #202 */
/* @0x2b328c cmp r2, #8 */
/* @0x2b3290 mov r4, r0 */
/* @0x2b3294 bls 0x2b32b4 <jpeg_has_multiple_scans+0x34> */
/* @0x2b3298 ldr r2, [r0] */
/* @0x2b329c mov r1, #20 */
/* @0x2b32a0 str r3, [r2, #0x18] */
/* @0x2b32a4 ldr r3, [r0] */
/* @0x2b32a8 str r1, [r2, #0x14] */
/* @0x2b32ac ldr r3, [r3] */
/* @0x2b32b0 blx r3 */
/* @0x2b32b4 ldr r3, [r4, #0x190] */
/* @0x2b32b8 ldrb r0, [r3, #0x10] */
/* @0x2b32bc pop {r4, pc} */

/* ── FUNC 0x2b32c0 · jpeg_finish_decompress · size=228 · insn=57 */
/* @0x2b32c0 ldr r3, [r0, #0x14] */
/* @0x2b32c4 push {r4, lr} */
/* @0x2b32c8 sub r2, r3, #205 */
/* @0x2b32cc cmp r2, #1 */
/* @0x2b32d0 mov r4, r0 */
/* @0x2b32d4 bls 0x2b3354 <jpeg_finish_decompress+0x94> */
/* @0x2b32d8 cmp r3, #207 */
/* @0x2b32dc moveq r3, #210 */
/* @0x2b32e0 streq r3, [r0, #0x14] */
/* @0x2b32e4 beq 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b32e8 cmp r3, #210 */
/* @0x2b32ec beq 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b32f0 ldr r2, [r4] */
/* @0x2b32f4 mov r1, #20 */
/* @0x2b32f8 mov r0, r4 */
/* @0x2b32fc str r3, [r2, #0x18] */
/* @0x2b3300 ldr r3, [r4] */
/* @0x2b3304 str r1, [r2, #0x14] */
/* @0x2b3308 ldr r3, [r3] */
/* @0x2b330c blx r3 */
/* @0x2b3310 b 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b3314 ldr r3, [r3] */
/* @0x2b3318 blx r3 */
/* @0x2b331c cmp r0, #0 */
/* @0x2b3320 popeq {r4, pc} */
/* @0x2b3324 ldr r3, [r4, #0x190] */
/* @0x2b3328 mov r0, r4 */
/* @0x2b332c ldrb r2, [r3, #0x11] */
/* @0x2b3330 cmp r2, #0 */
/* @0x2b3334 beq 0x2b3314 <jpeg_finish_decompress+0x54> */
/* @0x2b3338 ldr r3, [r4, #0x18] */
/* @0x2b333c ldr r3, [r3, #0x18] */
/* @0x2b3340 blx r3 */
/* @0x2b3344 mov r0, r4 */
/* @0x2b3348 bl 0x2bc874 <jpeg_abort> */
/* @0x2b334c mov r0, #1 */
/* @0x2b3350 pop {r4, pc} */
/* @0x2b3354 ldrb r2, [r0, #0x40] */
/* @0x2b3358 cmp r2, #0 */
/* @0x2b335c bne 0x2b32f0 <jpeg_finish_decompress+0x30> */
/* @0x2b3360 ldr r2, [r0, #0x78] */
/* @0x2b3364 ldr r3, [r0, #0x60] */
/* @0x2b3368 cmp r2, r3 */
/* @0x2b336c blo 0x2b338c <jpeg_finish_decompress+0xcc> */
/* @0x2b3370 ldr r3, [r4, #0x180] */
/* @0x2b3374 mov r0, r4 */
/* @0x2b3378 ldr r3, [r3, #0x4] */
/* @0x2b337c blx r3 */
/* @0x2b3380 mov r3, #210 */
/* @0x2b3384 str r3, [r4, #0x14] */
/* @0x2b3388 b 0x2b3324 <jpeg_finish_decompress+0x64> */
/* @0x2b338c ldr r3, [r0] */
/* @0x2b3390 mov r1, #67 */
/* @0x2b3394 ldr r2, [r3] */
/* @0x2b3398 str r1, [r3, #0x14] */
/* @0x2b339c blx r2 */
/* @0x2b33a0 b 0x2b3370 <jpeg_finish_decompress+0xb0> */

/* ── FUNC 0x2b33a4 · anon_2b33a4 · size=260 · insn=65 */
/* @0x2b33a4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2b33a8 mov r4, r0 */
/* @0x2b33ac ldr r3, [r0, #0x14] */
/* @0x2b33b0 cmp r3, #204 */
/* @0x2b33b4 beq 0x2b33d4 <jpeg_finish_decompress+0x114> */
/* @0x2b33b8 ldr r3, [r0, #0x180] */
/* @0x2b33bc ldr r3, [r3] */
/* @0x2b33c0 blx r3 */
/* @0x2b33c4 mov r2, #0 */
/* @0x2b33c8 mov r3, #204 */
/* @0x2b33cc str r2, [r4, #0x78] */
/* @0x2b33d0 str r3, [r4, #0x14] */
/* @0x2b33d4 ldr r3, [r4, #0x180] */
/* @0x2b33d8 ldrb r3, [r3, #0x8] */
/* @0x2b33dc cmp r3, #0 */
/* @0x2b33e0 beq 0x2b3484 <jpeg_finish_decompress+0x1c4> */
/* @0x2b33e4 mov r6, r4 */
/* @0x2b33e8 mov r7, #0 */
/* @0x2b33ec ldr r5, [r6, #0x78]! */
/* @0x2b33f0 b 0x2b3440 <jpeg_finish_decompress+0x180> */
/* @0x2b33f4 ldr r3, [r4, #0x8] */
/* @0x2b33f8 cmp r3, #0 */
/* @0x2b33fc beq 0x2b3414 <jpeg_finish_decompress+0x154> */
/* @0x2b3400 str r5, [r3, #0x4] */
/* @0x2b3404 str r1, [r3, #0x8] */
/* @0x2b3408 ldr r3, [r3] */
/* @0x2b340c blx r3 */
/* @0x2b3410 ldr r5, [r4, #0x78] */
/* @0x2b3414 ldr r12, [r4, #0x184] */
/* @0x2b3418 mov r1, #0 */
/* @0x2b341c mov r3, r1 */
/* @0x2b3420 mov r0, r4 */
/* @0x2b3424 mov r2, r6 */
/* @0x2b3428 ldr r12, [r12, #0x4] */
/* @0x2b342c blx r12 */
/* @0x2b3430 ldr r3, [r4, #0x78] */
/* @0x2b3434 cmp r3, r5 */
/* @0x2b3438 mov r5, r3 */
/* @0x2b343c beq 0x2b34a0 <jpeg_finish_decompress+0x1e0> */
/* @0x2b3440 ldr r1, [r4, #0x60] */
/* @0x2b3444 mov r0, r4 */
/* @0x2b3448 cmp r1, r5 */
/* @0x2b344c bhi 0x2b33f4 <jpeg_finish_decompress+0x134> */
/* @0x2b3450 ldr r3, [r4, #0x180] */
/* @0x2b3454 mov r5, #0 */
/* @0x2b3458 ldr r3, [r3, #0x4] */
/* @0x2b345c blx r3 */
/* @0x2b3460 ldr r3, [r4, #0x180] */
/* @0x2b3464 mov r0, r4 */
/* @0x2b3468 ldr r3, [r3] */
/* @0x2b346c blx r3 */
/* @0x2b3470 ldr r3, [r4, #0x180] */
/* @0x2b3474 str r7, [r4, #0x78] */
/* @0x2b3478 ldrb r3, [r3, #0x8] */
/* @0x2b347c cmp r3, r5 */
/* @0x2b3480 bne 0x2b3440 <jpeg_finish_decompress+0x180> */
/* @0x2b3484 ldrb r3, [r4, #0x41] */
/* @0x2b3488 mov r0, #1 */
/* @0x2b348c cmp r3, #0 */
/* @0x2b3490 movne r3, #206 */
/* @0x2b3494 moveq r3, #205 */
/* @0x2b3498 str r3, [r4, #0x14] */
/* @0x2b349c pop {r3, r4, r5, r6, r7, pc} */
/* @0x2b34a0 mov r0, #0 */
/* @0x2b34a4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2b34a8 · jpeg_start_decompress · size=280 · insn=70 */
/* @0x2b34a8 ldr r3, [r0, #0x14] */
/* @0x2b34ac push {r4, lr} */
/* @0x2b34b0 cmp r3, #202 */
/* @0x2b34b4 mov r4, r0 */
/* @0x2b34b8 beq 0x2b3598 <jpeg_start_decompress+0xf0> */
/* @0x2b34bc cmp r3, #203 */
/* @0x2b34c0 beq 0x2b34f4 <jpeg_start_decompress+0x4c> */
/* @0x2b34c4 cmp r3, #204 */
/* @0x2b34c8 beq 0x2b34e8 <jpeg_start_decompress+0x40> */
/* @0x2b34cc ldr r2, [r0] */
/* @0x2b34d0 mov r1, #20 */
/* @0x2b34d4 str r3, [r2, #0x18] */
/* @0x2b34d8 ldr r3, [r0] */
/* @0x2b34dc str r1, [r2, #0x14] */
/* @0x2b34e0 ldr r3, [r3] */
/* @0x2b34e4 blx r3 */
/* @0x2b34e8 mov r0, r4 */
/* @0x2b34ec pop {r4, lr} */
/* @0x2b34f0 b 0x2b33a4 <jpeg_finish_decompress+0xe4> */
/* @0x2b34f4 ldr r3, [r4, #0x190] */
/* @0x2b34f8 ldrb r3, [r3, #0x10] */
/* @0x2b34fc cmp r3, #0 */
/* @0x2b3500 beq 0x2b3584 <jpeg_start_decompress+0xdc> */
/* @0x2b3504 ldr r3, [r4, #0x8] */
/* @0x2b3508 cmp r3, #0 */
/* @0x2b350c beq 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3510 ldr r3, [r3] */
/* @0x2b3514 mov r0, r4 */
/* @0x2b3518 blx r3 */
/* @0x2b351c ldr r3, [r4, #0x190] */
/* @0x2b3520 mov r0, r4 */
/* @0x2b3524 ldr r3, [r3] */
/* @0x2b3528 blx r3 */
/* @0x2b352c cmp r0, #0 */
/* @0x2b3530 popeq {r4, pc} */
/* @0x2b3534 cmp r0, #2 */
/* @0x2b3538 beq 0x2b3584 <jpeg_start_decompress+0xdc> */
/* @0x2b353c ldr r3, [r4, #0x8] */
/* @0x2b3540 cmp r3, #0 */
/* @0x2b3544 beq 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3548 bic r0, r0, #2 */
/* @0x2b354c cmp r0, #1 */
/* @0x2b3550 bne 0x2b3508 <jpeg_start_decompress+0x60> */
/* @0x2b3554 ldr r2, [r3, #0x4] */
/* @0x2b3558 ldr r1, [r3, #0x8] */
/* @0x2b355c add r2, r2, #1 */
/* @0x2b3560 str r2, [r3, #0x4] */
/* @0x2b3564 cmp r2, r1 */
/* @0x2b3568 blt 0x2b3508 <jpeg_start_decompress+0x60> */
/* @0x2b356c ldr r2, [r4, #0x11c] */
/* @0x2b3570 cmp r3, #0 */
/* @0x2b3574 add r1, r1, r2 */
/* @0x2b3578 str r1, [r3, #0x8] */
/* @0x2b357c bne 0x2b3510 <jpeg_start_decompress+0x68> */
/* @0x2b3580 b 0x2b351c <jpeg_start_decompress+0x74> */
/* @0x2b3584 ldr r3, [r4, #0x7c] */
/* @0x2b3588 mov r0, r4 */
/* @0x2b358c str r3, [r4, #0x84] */
/* @0x2b3590 pop {r4, lr} */
/* @0x2b3594 b 0x2b33a4 <jpeg_finish_decompress+0xe4> */
/* @0x2b3598 bl 0x2b66d8 <jinit_master_decompress> */
/* @0x2b359c ldrb r3, [r4, #0x40] */
/* @0x2b35a0 cmp r3, #0 */
/* @0x2b35a4 moveq r3, #203 */
/* @0x2b35a8 streq r3, [r4, #0x14] */
/* @0x2b35ac beq 0x2b34f4 <jpeg_start_decompress+0x4c> */
/* @0x2b35b0 mov r3, #207 */
/* @0x2b35b4 mov r0, #1 */
/* @0x2b35b8 str r3, [r4, #0x14] */
/* @0x2b35bc pop {r4, pc} */

/* ── FUNC 0x2b35c0 · jpeg_read_scanlines · size=216 · insn=54 */
/* @0x2b35c0 ldr r12, [r0, #0x14] */
/* @0x2b35c4 push {r4, r5, r6, lr} */
/* @0x2b35c8 cmp r12, #205 */
/* @0x2b35cc sub sp, sp, #8 */
/* @0x2b35d0 mov r4, r0 */
/* @0x2b35d4 mov r6, r1 */
/* @0x2b35d8 mov r5, r2 */
/* @0x2b35dc beq 0x2b35fc <jpeg_read_scanlines+0x3c> */
/* @0x2b35e0 ldr r3, [r0] */
/* @0x2b35e4 mov r1, #20 */
/* @0x2b35e8 str r12, [r3, #0x18] */
/* @0x2b35ec ldr r2, [r0] */
/* @0x2b35f0 str r1, [r3, #0x14] */
/* @0x2b35f4 ldr r3, [r2] */
/* @0x2b35f8 blx r3 */
/* @0x2b35fc ldr r0, [r4, #0x78] */
/* @0x2b3600 ldr lr, [r4, #0x60] */
/* @0x2b3604 cmp r0, lr */
/* @0x2b3608 bhs 0x2b3670 <jpeg_read_scanlines+0xb0> */
/* @0x2b360c ldr r12, [r4, #0x8] */
/* @0x2b3610 cmp r12, #0 */
/* @0x2b3614 beq 0x2b362c <jpeg_read_scanlines+0x6c> */
/* @0x2b3618 str r0, [r12, #0x4] */
/* @0x2b361c mov r0, r4 */
/* @0x2b3620 str lr, [r12, #0x8] */
/* @0x2b3624 ldr r3, [r12] */
/* @0x2b3628 blx r3 */
/* @0x2b362c ldr lr, [r4, #0x184] */
/* @0x2b3630 add r12, sp, #8 */
/* @0x2b3634 mov r3, r5 */
/* @0x2b3638 mov r0, r4 */
/* @0x2b363c mov r1, r6 */
/* @0x2b3640 mov r2, #0 */
/* @0x2b3644 str r2, [r12, #-0x4]! */
/* @0x2b3648 mov r2, r12 */
/* @0x2b364c ldr r12, [lr, #0x4] */
/* @0x2b3650 blx r12 */
/* @0x2b3654 ldr r3, [sp, #0x4] */
/* @0x2b3658 ldr r2, [r4, #0x78] */
/* @0x2b365c mov r0, r3 */
/* @0x2b3660 add r3, r2, r3 */
/* @0x2b3664 str r3, [r4, #0x78] */
/* @0x2b3668 add sp, sp, #8 */
/* @0x2b366c pop {r4, r5, r6, pc} */
/* @0x2b3670 ldr r3, [r4] */
/* @0x2b3674 mov r0, r4 */
/* @0x2b3678 mov r2, #123 */
/* @0x2b367c mvn r1, #0 */
/* @0x2b3680 str r2, [r3, #0x14] */
/* @0x2b3684 ldr r3, [r3, #0x4] */
/* @0x2b3688 blx r3 */
/* @0x2b368c mov r0, #0 */
/* @0x2b3690 add sp, sp, #8 */
/* @0x2b3694 pop {r4, r5, r6, pc} */
