/* libyoyo.so 覆盖卡组 0256
 * 函数 0x2a90ac..0x2ac9ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a90ac · png_do_gray_to_rgb · size=256 · insn=123 */
/* @0x2a90ac ldrb r2, [r0, #0x9] */
/* @0x2a90ae push {r4, r5, r6, lr} */
/* @0x2a90b0 cmp r2, #0x7 */
/* @0x2a90b2 ldr r3, [r0] */
/* @0x2a90b4 bls 0x2a91aa <png_do_gray_to_rgb+0xfe> */
/* @0x2a90b6 ldrb r4, [r0, #0x8] */
/* @0x2a90b8 and r6, r4, #0x2 */
/* @0x2a90bc and r5, r6, #0xff */
/* @0x2a90c0 cmp r6, #0x0 */
/* @0x2a90c2 bne 0x2a91aa <png_do_gray_to_rgb+0xfe> */
/* @0x2a90c4 cbnz r4, 0x2a90ee <png_do_gray_to_rgb+0x42> */
/* @0x2a90c6 cmp r2, #0x8 */
/* @0x2a90c8 lsl.w r2, r3, #0x1 */
/* @0x2a90cc bne 0x2a9114 <png_do_gray_to_rgb+0x68> */
/* @0x2a90ce subs r4, r3, #0x1 */
/* @0x2a90d0 add r1, r4 */
/* @0x2a90d2 mvns r4, r3 */
/* @0x2a90d4 add r2, r1 */
/* @0x2a90d6 add r4, r1 */
/* @0x2a90d8 subs r1, #0x1 */
/* @0x2a90da cmp r1, r4 */
/* @0x2a90dc beq 0x2a90f2 <png_do_gray_to_rgb+0x46> */
/* @0x2a90de ldrb r5, [r1, #0x1] */
/* @0x2a90e0 subs r2, #0x3 */
/* @0x2a90e2 strb r5, [r2, #0x3] */
/* @0x2a90e4 ldrb r5, [r1, #0x1] */
/* @0x2a90e6 strb r5, [r2, #0x2] */
/* @0x2a90e8 ldrb r5, [r1, #0x1] */
/* @0x2a90ea strb r5, [r2, #0x1] */
/* @0x2a90ec b 0x2a90d8 <png_do_gray_to_rgb+0x2c> */
/* @0x2a90ee cmp r4, #0x4 */
/* @0x2a90f0 beq 0x2a9142 <png_do_gray_to_rgb+0x96> */
/* @0x2a90f2 ldrb r2, [r0, #0xa] */
/* @0x2a90f4 ldrb r1, [r0, #0x8] */
/* @0x2a90f6 adds r2, #0x2 */
/* @0x2a90f8 orr r1, r1, #0x2 */
/* @0x2a90fc strb r1, [r0, #0x8] */
/* @0x2a90fe ldrb r1, [r0, #0x9] */
/* @0x2a9100 uxtb r2, r2 */
/* @0x2a9102 strb r2, [r0, #0xa] */
/* @0x2a9104 muls r2, r1, r2 */
/* @0x2a9106 uxtb r2, r2 */
/* @0x2a9108 strb r2, [r0, #0xb] */
/* @0x2a910a cmp r2, #0x7 */
/* @0x2a910c bls 0x2a91a2 <png_do_gray_to_rgb+0xf6> */
/* @0x2a910e lsrs r2, r2, #0x3 */
/* @0x2a9110 muls r3, r2, r3 */
/* @0x2a9112 b 0x2a91a8 <png_do_gray_to_rgb+0xfc> */
/* @0x2a9114 subs r2, #0x1 */
/* @0x2a9116 add r1, r2 */
/* @0x2a9118 add.w r2, r1, r3, lsl #2 */
/* @0x2a911c cmp r4, r3 */
/* @0x2a911e sub.w r1, r1, #0x2 */
/* @0x2a9120 rscle r0, r6, r2, lsl #2 */
/* @0x2a9122 beq 0x2a90f2 <png_do_gray_to_rgb+0x46> */
/* @0x2a9124 ldrb r5, [r1, #0x2] */
/* @0x2a9126 adds r4, #0x1 */
/* @0x2a9128 subs r2, #0x6 */
/* @0x2a912a strb r5, [r2, #0x6] */
/* @0x2a912c ldrb r5, [r1, #0x1] */
/* @0x2a912e strb r5, [r2, #0x5] */
/* @0x2a9130 ldrb r5, [r1, #0x2] */
/* @0x2a9132 strb r5, [r2, #0x4] */
/* @0x2a9134 ldrb r5, [r1, #0x1] */
/* @0x2a9136 strb r5, [r2, #0x3] */
/* @0x2a9138 ldrb r5, [r1, #0x2] */
/* @0x2a913a strb r5, [r2, #0x2] */
/* @0x2a913c ldrb r5, [r1, #0x1] */
/* @0x2a913e strb r5, [r2, #0x1] */
/* @0x2a9140 b 0x2a911c <png_do_gray_to_rgb+0x70> */
/* @0x2a9142 cmp r2, #0x8 */
/* @0x2a9144 bne 0x2a916c <png_do_gray_to_rgb+0xc0> */
/* @0x2a9146 lsls r2, r3, #0x1 */
/* @0x2a9148 subs r4, r2, #0x1 */
/* @0x2a914a add r1, r4 */
/* @0x2a914c mov r4, r5 */
/* @0x2a914e add r2, r1 */
/* @0x2a9150 cmp r4, r3 */
/* @0x2a9152 beq 0x2a90f2 <png_do_gray_to_rgb+0x46> */
/* @0x2a9154 ldrb r5, [r1] */
/* @0x2a9156 adds r4, #0x1 */
/* @0x2a9158 subs r1, #0x2 */
/* @0x2a915a subs r2, #0x4 */
/* @0x2a915c strb r5, [r2, #0x4] */
/* @0x2a915e ldrb r5, [r1, #0x1] */
/* @0x2a9160 strb r5, [r2, #0x3] */
/* @0x2a9162 ldrb r5, [r1, #0x1] */
/* @0x2a9164 strb r5, [r2, #0x2] */
/* @0x2a9166 ldrb r5, [r1, #0x1] */
/* @0x2a9168 strb r5, [r2, #0x1] */
/* @0x2a916a b 0x2a9150 <png_do_gray_to_rgb+0xa4> */
/* @0x2a916c lsls r2, r3, #0x2 */
/* @0x2a916e subs r4, r2, #0x1 */
/* @0x2a9170 add r1, r4 */
/* @0x2a9172 mov r4, r5 */
/* @0x2a9174 add r2, r1 */
/* @0x2a9176 cmp r4, r3 */
/* @0x2a9178 beq 0x2a90f2 <png_do_gray_to_rgb+0x46> */
/* @0x2a917a ldrb r5, [r1] */
/* @0x2a917c adds r4, #0x1 */
/* @0x2a917e subs r1, #0x4 */
/* @0x2a9180 subs r2, #0x8 */
/* @0x2a9182 strb r5, [r2, #0x8] */
/* @0x2a9184 ldrb r5, [r1, #0x3] */
/* @0x2a9186 strb r5, [r2, #0x7] */
/* @0x2a9188 ldrb r5, [r1, #0x2] */
/* @0x2a918a strb r5, [r2, #0x6] */
/* @0x2a918c ldrb r5, [r1, #0x1] */
/* @0x2a918e strb r5, [r2, #0x5] */
/* @0x2a9190 ldrb r5, [r1, #0x2] */
/* @0x2a9192 strb r5, [r2, #0x4] */
/* @0x2a9194 ldrb r5, [r1, #0x1] */
/* @0x2a9196 strb r5, [r2, #0x3] */
/* @0x2a9198 ldrb r5, [r1, #0x2] */
/* @0x2a919a strb r5, [r2, #0x2] */
/* @0x2a919c ldrb r5, [r1, #0x1] */
/* @0x2a919e strb r5, [r2, #0x1] */
/* @0x2a91a0 b 0x2a9176 <png_do_gray_to_rgb+0xca> */
/* @0x2a91a2 muls r3, r2, r3 */
/* @0x2a91a4 adds r3, #0x7 */
/* @0x2a91a6 lsrs r3, r3, #0x3 */
/* @0x2a91a8 str r3, [r0, #0x4] */
/* @0x2a91aa pop {r4, r5, r6, pc} */

/* ── FUNC 0x2a91ac · png_do_rgb_to_gray · size=1166 · insn=496 */
/* @0x2a91ac ldrb r3, [r1, #0x8] */
/* @0x2a91ae push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a91b0 .word 0xf0034ff7 */
/* @0x2a91b2 and r5, r3, #0x3 */
/* @0x2a91b4 stchs p5, c0, [r2, #-12] */
/* @0x2a91b6 cmp r5, #0x2 */
/* @0x2a91b8 ldr r4, [r1] */
/* @0x2a91ba bne.w 0x2a9630 <png_do_rgb_to_gray+0x484> */
/* @0x2a91bc rfeia r0! */
/* @0x2a91be ldrh.w r5, [r0, #0x2d6] */
/* @0x2a91c0 blhs 0x33dd20 */
/* @0x2a91c2 cmp r3, #0x2 */
/* @0x2a91c4 ldrh.w r9, [r0, #0x2d8] */
/* @0x2a91c8 str r5, [sp] */
/* @0x2a91ca str.w r9, [sp, #0x4] */
/* @0x2a91cc rfeia r0! */
/* @0x2a91ce ldrh.w r5, [r0, #0x2da] */
/* @0x2a91d0 .word 0xf04052da */
/* @0x2a91d2 bne.w 0x2a93e4 <png_do_rgb_to_gray+0x238> */
/* @0x2a91d4 bvc 0x15895f8 <b2_toiTime+0xe30154> */
/* @0x2a91d6 ldrb r3, [r1, #0x9] */
/* @0x2a91d8 cmp r3, #0x8 */
/* @0x2a91da bne 0x2a9296 <png_do_rgb_to_gray+0xea> */
/* @0x2a91dc ldr.w r3, [r0, #0x22c] */
/* @0x2a91e0 mov.w r10, #0x3 */
/* @0x2a91e4 adds r7, r2, #0x1 */
/* @0x2a91e6 mov r6, r2 */
/* @0x2a91e8 mla r10, r10, r4, r2 */
/* @0x2a91ec cbnz r3, 0x2a91f2 <png_do_rgb_to_gray+0x46> */
/* @0x2a91ee movs r3, #0x0 */
/* @0x2a91f0 b 0x2a9286 <png_do_rgb_to_gray+0xda> */
/* @0x2a91f2 ldr.w r3, [r0, #0x230] */
/* @0x2a91f4 blhs 0x2b5abc <jinit_input_controller+0x1bdc> */
/* @0x2a91f6 cmp r3, #0x0 */
/* @0x2a91f8 beq 0x2a91ee <png_do_rgb_to_gray+0x42> */
/* @0x2a91fa movs r3, #0x0 */
/* @0x2a91fc cmp r6, r10 */
/* @0x2a91fe beq.w 0x2a93e6 <png_do_rgb_to_gray+0x23a> */
/* @0x2a9200 .word 0xf8d080f2 */
/* @0x2a9202 ldr.w r8, [r0, #0x230] */
/* @0x2a9204 .word 0xf8968230 */
/* @0x2a9206 ldrb.w r9, [r6, #0x1] */
/* @0x2a9208 .word 0xf8969001 */
/* @0x2a920a ldrb.w r12, [r6] */
/* @0x2a920c .word 0xf818c000 */
/* @0x2a920e ldrb.w r11, [r8, r9] */
/* @0x2a9210 .word 0xf818b009 */
/* @0x2a9212 ldrb.w r12, [r8, r12] */
/* @0x2a9214 .word 0xf896c00c */
/* @0x2a9216 ldrb.w r9, [r6, #0x2] */
/* @0x2a9218 ldrbmi r9, [r12, #0x2] */
/* @0x2a921a cmp r12, r11 */
/* @0x2a921c ldrb.w r8, [r8, r9] */
/* @0x2a9220 bne 0x2a9226 <png_do_rgb_to_gray+0x7a> */
/* @0x2a9222 cmp r12, r8 */
/* @0x2a9224 beq 0x2a924c <png_do_rgb_to_gray+0xa0> */
/* @0x2a9226 ldr r3, [sp] */
/* @0x2a9228 ldr.w r9, [sp, #0x4] */
/* @0x2a922c mul r12, r3, r12 */
/* @0x2a9230 ldr.w r3, [r0, #0x22c] */
/* @0x2a9234 mla r11, r9, r11, r12 */
/* @0x2a9238 mla r8, r5, r8, r11 */
/* @0x2a923c lsr.w r8, r8, #0xf */
/* @0x2a9240 ldrb.w r3, [r3, r8] */
/* @0x2a9244 strb r3, [r7, #-1] */
/* @0x2a9248 movs r3, #0x1 */
/* @0x2a924a b 0x2a9250 <png_do_rgb_to_gray+0xa4> */
/* @0x2a924c strb r9, [r7, #-1] */
/* @0x2a9250 adds r6, #0x3 */
/* @0x2a9252 adds r7, #0x1 */
/* @0x2a9254 b 0x2a91fc <png_do_rgb_to_gray+0x50> */
/* @0x2a9256 ldrb.w r12, [r6] */
/* @0x2a9258 .word 0xf896c000 */
/* @0x2a925a ldrb.w r9, [r6, #0x1] */
/* @0x2a925c .word 0xf8969001 */
/* @0x2a925e ldrb.w r8, [r6, #0x2] */
/* @0x2a9260 strbmi r8, [r12, #0x2] */
/* @0x2a9262 cmp r12, r9 */
/* @0x2a9264 beq 0x2a928c <png_do_rgb_to_gray+0xe0> */
/* @0x2a9266 ldr.w r11, [sp] */
/* @0x2a9268 blls 0x315270 <FT_Bitmap_Embolden+0x42a> */
/* @0x2a926a ldr r3, [sp, #0x4] */
/* @0x2a926c mul r12, r11, r12 */
/* @0x2a9270 mla r9, r3, r9, r12 */
/* @0x2a9274 movs r3, #0x1 */
/* @0x2a9276 mla r8, r5, r8, r9 */
/* @0x2a9278 b 0x168f2a0 <b2_toiTime+0xf35dfc> */
/* @0x2a927a lsr.w r8, r8, #0xf */
/* @0x2a927c .word 0xf80738d8 */
/* @0x2a927e strb r8, [r7, #-1] */
/* @0x2a9280 strlo r8, [r3], -r1, lsl #24 */
/* @0x2a9282 adds r6, #0x3 */
/* @0x2a9284 adds r7, #0x1 */
/* @0x2a9286 cmp r6, r10 */
/* @0x2a9288 bne 0x2a9256 <png_do_rgb_to_gray+0xaa> */
/* @0x2a928a b 0x2a93e6 <png_do_rgb_to_gray+0x23a> */
/* @0x2a928c cmp r12, r8 */
/* @0x2a928e bne 0x2a9266 <png_do_rgb_to_gray+0xba> */
/* @0x2a9290 strb r12, [r7, #-1] */
/* @0x2a9294 b 0x2a9282 <png_do_rgb_to_gray+0xd6> */
/* @0x2a9296 ldr.w r3, [r0, #0x23c] */
/* @0x2a9298 ldcne p2, c3, [r7], {60} */
/* @0x2a929a adds r7, r2, #0x2 */
/* @0x2a929c mov r6, r2 */
/* @0x2a929e cbnz r3, 0x2a92a6 <png_do_rgb_to_gray+0xfa> */
/* @0x2a92a0 movs r3, #0x0 */
/* @0x2a92a2 mov r12, r3 */
/* @0x2a92a4 b 0x2a93da <png_do_rgb_to_gray+0x22e> */
/* @0x2a92a6 ldr.w r3, [r0, #0x238] */
/* @0x2a92a8 blhs 0x2b5b90 <jinit_input_controller+0x1cb0> */
/* @0x2a92aa cmp r3, #0x0 */
/* @0x2a92ac beq 0x2a92a0 <png_do_rgb_to_gray+0xf4> */
/* @0x2a92ae movs r3, #0x0 */
/* @0x2a92b0 mov r12, r7 */
/* @0x2a92b2 mov r8, r3 */
/* @0x2a92b4 cmp r8, r4 */
/* @0x2a92b6 beq.w 0x2a93e6 <png_do_rgb_to_gray+0x23a> */
/* @0x2a92b8 .word 0xf8968096 */
/* @0x2a92ba ldrb.w r9, [r6] */
/* @0x2a92bc ldmdavc r7!, {r12, pc} ^ */
/* @0x2a92be ldrb r7, [r6, #0x1] */
/* @0x2a92c0 ldrb.w r10, [r6, #0x2] */
/* @0x2a92c4 orr.w r7, r7, r9, lsl #8 */
/* @0x2a92c8 ldrb.w r9, [r6, #0x3] */
/* @0x2a92cc ldrb.w r11, [r6, #0x4] */
/* @0x2a92d0 orr.w r10, r9, r10, lsl #8 */
/* @0x2a92d4 ldrb.w r9, [r6, #0x5] */
/* @0x2a92d8 cmp r7, r10 */
/* @0x2a92da orr.w r9, r9, r11, lsl #8 */
/* @0x2a92dc mrsle r2, apsr */
/* @0x2a92de bne 0x2a92e4 <png_do_rgb_to_gray+0x138> */
/* @0x2a92e0 cmp r7, r9 */
/* @0x2a92e2 beq 0x2a9368 <png_do_rgb_to_gray+0x1bc> */
/* @0x2a92e4 uxtb.w r11, r10 */
/* @0x2a92e8 ldr.w r3, [r0, #0x21c] */
/* @0x2a92ec lsr.w r10, r10, #0x8 */
/* @0x2a92f0 asr.w r11, r11, r3 */
/* @0x2a92f4 ldr.w r3, [r0, #0x23c] */
/* @0x2a92f8 ldr.w r11, [r3, r11, lsl #2] */
/* @0x2a92fc ldr.w r3, [r0, #0x21c] */
/* @0x2a9300 ldrh.w r10, [r11, r10, lsl #1] */
/* @0x2a9304 uxtb.w r11, r7 */
/* @0x2a9308 lsrs r7, r7, #0x8 */
/* @0x2a930a asr.w r11, r11, r3 */
/* @0x2a930c .word 0xf8d0fb03 */
/* @0x2a930e ldr.w r3, [r0, #0x23c] */
/* @0x2a9310 .word 0xf853323c */
/* @0x2a9312 ldr.w r11, [r3, r11, lsl #2] */
/* @0x2a9314 blls 0x3153c8 <FT_Bitmap_Embolden+0x582> */
/* @0x2a9316 ldr r3, [sp, #0x4] */
/* @0x2a9318 ldrh.w r7, [r11, r7, lsl #1] */
/* @0x2a931c ldr.w r11, [sp] */
/* @0x2a9320 mul r7, r11, r7 */
/* @0x2a9324 mla r10, r3, r10, r7 */
/* @0x2a9328 uxtb.w r7, r9 */
/* @0x2a932c ldr.w r3, [r0, #0x21c] */
/* @0x2a9330 lsr.w r9, r9, #0x8 */
/* @0x2a9334 asrs r7, r3 */
/* @0x2a9336 ldr.w r3, [r0, #0x23c] */
/* @0x2a9338 .word 0xf853323c */
/* @0x2a933a ldr.w r7, [r3, r7, lsl #2] */
/* @0x2a933c .word 0xf8d07027 */
/* @0x2a933e ldr.w r3, [r0, #0x21c] */
/* @0x2a9340 rfeda r7! */
/* @0x2a9342 ldrh.w r7, [r7, r9, lsl #1] */
/* @0x2a9344 blx 0x4053b2 <g_RomDisk+0xdb92> */
/* @0x2a9346 mla r10, r5, r7, r10 */
/* @0x2a9348 vmlsl.u8 q13, d10, d7 */
/* @0x2a934a ubfx r10, r10, #0xf, #0x10 */
/* @0x2a934c blx 0x1a77e90 <b2_toiTime+0x131e9ec> */
/* @0x2a934e uxtb.w r7, r10 */
/* @0x2a9350 b 0x16a7180 <b2_toiTime+0xf4dcdc> */
/* @0x2a9352 lsr.w r10, r10, #0x8 */
/* @0x2a9354 blx 0x1473bc4 <b2_toiTime+0xd1a720> */
/* @0x2a9356 asr.w r9, r7, r3 */
/* @0x2a9358 .word 0xf8d0f903 */
/* @0x2a935a ldr.w r7, [r0, #0x238] */
/* @0x2a935c .word 0xf8577238 */
/* @0x2a935e ldr.w r3, [r7, r9, lsl #2] */
/* @0x2a9360 rfeda r3! */
/* @0x2a9362 ldrh.w r7, [r3, r10, lsl #1] */
/* @0x2a9364 movwhs r7, #0x101a */
/* @0x2a9366 movs r3, #0x1 */
/* @0x2a9368 lsr.w r9, r7, #0x8 */
/* @0x2a936c strb r7, [r12, #-1] */
/* @0x2a9370 strb r9, [r12, #-2] */
/* @0x2a9374 add.w r8, r8, #0x1 */
/* @0x2a9378 adds r6, #0x6 */
/* @0x2a937a add.w r12, r12, #0x2 */
/* @0x2a937c ldr r0, [r9, r2, lsl #24] */
/* @0x2a937e b 0x2a92b4 <png_do_rgb_to_gray+0x108> */
/* @0x2a9380 ldrb.w r9, [r6] */
/* @0x2a9384 ldrb.w r8, [r6, #0x1] */
/* @0x2a9388 ldrb.w r10, [r6, #0x2] */
/* @0x2a938c orr.w r8, r8, r9, lsl #8 */
/* @0x2a9390 ldrb.w r9, [r6, #0x3] */
/* @0x2a9394 ldrb.w r11, [r6, #0x4] */
/* @0x2a9398 orr.w r9, r9, r10, lsl #8 */
/* @0x2a939c ldrb.w r10, [r6, #0x5] */
/* @0x2a93a0 cmp r8, r9 */
/* @0x2a93a2 orr.w r10, r10, r11, lsl #8 */
/* @0x2a93a4 tstle r11, r11, lsl #20 */
/* @0x2a93a6 bne 0x2a93e0 <png_do_rgb_to_gray+0x234> */
/* @0x2a93a8 cmp r8, r10 */
/* @0x2a93aa it ne */
/* @0x2a93ac movne r3, #0x1 */
/* @0x2a93ae ldr.w r11, [sp] */
/* @0x2a93b0 .word 0xf10cb000 */
/* @0x2a93b2 add.w r12, r12, #0x1 */
/* @0x2a93b4 strlo r0, [r6], -r1, lsl #24 */
/* @0x2a93b6 adds r6, #0x6 */
/* @0x2a93b8 adds r7, #0x2 */
/* @0x2a93ba mul r8, r11, r8 */
/* @0x2a93bc .word 0xf8ddf808 */
/* @0x2a93be ldr.w r11, [sp, #0x4] */
/* @0x2a93c0 blx 0x5953da <g_SWFlineaavertbuff+0x42312> */
/* @0x2a93c2 mla r8, r11, r9, r8 */
/* @0x2a93c4 blx 0x40b3f2 <g_RomDisk+0x13bd2> */
/* @0x2a93c6 mla r10, r5, r10, r8 */
/* @0x2a93c8 b 0x168bbf8 <b2_toiTime+0xf32754> */
/* @0x2a93ca lsr.w r10, r10, #0xf */
/* @0x2a93cc .word 0xf8073ada */
/* @0x2a93ce strb r10, [r7, #-3] */
/* @0x2a93d0 vmull.u8 q13, d10, d3 */
/* @0x2a93d2 ubfx r8, r10, #0x8, #0x8 */
/* @0x2a93d4 .word 0xf8072807 */
/* @0x2a93d6 strb r8, [r7, #-4] */
/* @0x2a93d8 strmi r8, [r4, #0xc04]! */
/* @0x2a93da cmp r12, r4 */
/* @0x2a93dc bne 0x2a9380 <png_do_rgb_to_gray+0x1d4> */
/* @0x2a93de b 0x2a93e6 <png_do_rgb_to_gray+0x23a> */
/* @0x2a93e0 movs r3, #0x1 */
/* @0x2a93e2 b 0x2a93ae <png_do_rgb_to_gray+0x202> */
/* @0x2a93e4 movs r3, #0x0 */
/* @0x2a93e6 ldrb r6, [r1, #0x8] */
/* @0x2a93e8 cmp r6, #0x6 */
/* @0x2a93ea bne.w 0x2a9604 <png_do_rgb_to_gray+0x458> */
/* @0x2a93ec bvc 0x1649820 <b2_toiTime+0xef037c> */
/* @0x2a93ee ldrb r6, [r1, #0x9] */
/* @0x2a93f0 cmp r6, #0x8 */
/* @0x2a93f2 bne 0x2a94b8 <png_do_rgb_to_gray+0x30c> */
/* @0x2a93f4 ldr.w r6, [r0, #0x22c] */
/* @0x2a93f8 adds r7, r2, #0x2 */
/* @0x2a93fa cbnz r6, 0x2a9400 <png_do_rgb_to_gray+0x254> */
/* @0x2a93fc movs r0, #0x0 */
/* @0x2a93fe b 0x2a94ae <png_do_rgb_to_gray+0x302> */
/* @0x2a9400 ldr.w r6, [r0, #0x230] */
/* @0x2a9404 cmp r6, #0x0 */
/* @0x2a9406 beq 0x2a93fc <png_do_rgb_to_gray+0x250> */
/* @0x2a9408 mov.w r12, #0x0 */
/* @0x2a940c cmp r12, r4 */
/* @0x2a940e beq.w 0x2a9604 <png_do_rgb_to_gray+0x458> */
/* @0x2a9410 .word 0xf8d080f9 */
/* @0x2a9412 ldr.w r8, [r0, #0x230] */
/* @0x2a9414 ldmdavc r6, {r4, r5, r9, pc} */
/* @0x2a9416 ldrb r6, [r2] */
/* @0x2a9418 ldrb.w r9, [r2, #0x1] */
/* @0x2a941c ldrb.w r10, [r2, #0x2] */
/* @0x2a9420 ldrb.w r6, [r8, r6] */
/* @0x2a9424 ldrb.w r9, [r8, r9] */
/* @0x2a9428 ldrb.w r8, [r8, r10] */
/* @0x2a942c cmp r6, r9 */
/* @0x2a942e bne 0x2a9438 <png_do_rgb_to_gray+0x28c> */
/* @0x2a9430 cmp r6, r8 */
/* @0x2a9432 it ne */
/* @0x2a9434 movne r3, #0x1 */
/* @0x2a9436 b 0x2a943a <png_do_rgb_to_gray+0x28e> */
/* @0x2a9438 movs r3, #0x1 */
/* @0x2a943a ldr.w r10, [sp] */
/* @0x2a943c .word 0xf10ca000 */
/* @0x2a943e add.w r12, r12, #0x1 */
/* @0x2a9440 .word 0xf8dd0c01 */
/* @0x2a9442 ldr.w r11, [sp, #0x4] */
/* @0x2a9444 andlo r11, r4, #4 */
/* @0x2a9446 adds r2, #0x4 */
/* @0x2a9448 adds r7, #0x2 */
/* @0x2a944a mul r6, r10, r6 */
/* @0x2a944c blx 0x5a6c6e <g_SWFlineaavertbuff+0x53ba6> */
/* @0x2a944e mla r9, r11, r9, r6 */
/* @0x2a9450 .word 0xf8d06909 */
/* @0x2a9452 ldr.w r6, [r0, #0x22c] */
/* @0x2a9454 blx 0x401d0e <g_RomDisk+0xa4ee> */
/* @0x2a9456 mla r8, r5, r8, r9 */
/* @0x2a9458 b 0x168f480 <b2_toiTime+0xf35fdc> */
/* @0x2a945a lsr.w r8, r8, #0xf */
/* @0x2a945c .word 0xf81638d8 */
/* @0x2a945e ldrb.w r6, [r6, r8] */
/* @0x2a9460 .word 0xf8076008 */
/* @0x2a9462 strb r6, [r7, #-4] */
/* @0x2a9464 .word 0xf8126c04 */
/* @0x2a9466 ldrb r6, [r2, #-1] */
/* @0x2a9468 .word 0xf8076c01 */
/* @0x2a946a strb r6, [r7, #-3] */
/* @0x2a946c strb r6, [sp, r3, lsl #24] */
/* @0x2a946e b 0x2a940c <png_do_rgb_to_gray+0x260> */
/* @0x2a9470 ldrb r6, [r2] */
/* @0x2a9472 ldrb.w r8, [r2, #0x1] */
/* @0x2a9474 .word 0xf8928001 */
/* @0x2a9476 ldrb.w r12, [r2, #0x2] */
/* @0x2a9478 strbmi r12, [r6, #-0x2] */
/* @0x2a947a cmp r6, r8 */
/* @0x2a947c bne 0x2a94b4 <png_do_rgb_to_gray+0x308> */
/* @0x2a947e cmp r6, r12 */
/* @0x2a9480 it ne */
/* @0x2a9482 movne r3, #0x1 */
/* @0x2a9484 ldr.w r9, [sp] */
/* @0x2a9488 adds r0, #0x1 */
/* @0x2a948a ldr.w r10, [sp, #0x4] */
/* @0x2a948c andlo r10, r4, #4 */
/* @0x2a948e adds r2, #0x4 */
/* @0x2a9490 adds r7, #0x2 */
/* @0x2a9492 mul r6, r9, r6 */
/* @0x2a9494 blx 0x566cb6 <g_SWFlineaavertbuff+0x13bee> */
/* @0x2a9496 mla r8, r10, r8, r6 */
/* @0x2a9498 blx 0x4034c2 <g_RomDisk+0xbca2> */
/* @0x2a949a mla r12, r5, r12, r8 */
/* @0x2a949c b 0x168c4d4 <b2_toiTime+0xf33030> */
/* @0x2a949e lsr.w r12, r12, #0xf */
/* @0x2a94a0 .word 0xf8073cdc */
/* @0x2a94a2 strb r12, [r7, #-4] */
/* @0x2a94a4 .word 0xf812cc04 */
/* @0x2a94a6 ldrb r6, [r2, #-1] */
/* @0x2a94a8 .word 0xf8076c01 */
/* @0x2a94aa strb r6, [r7, #-3] */
/* @0x2a94ac adcmi r6, r0, #768 */
/* @0x2a94ae cmp r0, r4 */
/* @0x2a94b0 bne 0x2a9470 <png_do_rgb_to_gray+0x2c4> */
/* @0x2a94b2 b 0x2a9604 <png_do_rgb_to_gray+0x458> */
/* @0x2a94b4 movs r3, #0x1 */
/* @0x2a94b6 b 0x2a9484 <png_do_rgb_to_gray+0x2d8> */
/* @0x2a94b8 ldr.w r6, [r0, #0x23c] */
/* @0x2a94bc cbnz r6, 0x2a94c4 <png_do_rgb_to_gray+0x318> */
/* @0x2a94be mov r0, r2 */
/* @0x2a94c0 movs r6, #0x0 */
/* @0x2a94c2 b 0x2a95fa <png_do_rgb_to_gray+0x44e> */
/* @0x2a94c4 ldr.w r6, [r0, #0x238] */
/* @0x2a94c8 cmp r6, #0x0 */
/* @0x2a94ca beq 0x2a94be <png_do_rgb_to_gray+0x312> */
/* @0x2a94cc mov r7, r2 */
/* @0x2a94ce mov.w r12, #0x0 */
/* @0x2a94d0 strmi r0, [r4, #0xc00]! */
/* @0x2a94d2 cmp r12, r4 */
/* @0x2a94d4 beq.w 0x2a9604 <png_do_rgb_to_gray+0x458> */
/* @0x2a94d8 ldrb.w r8, [r2] */
/* @0x2a94dc ldrb r6, [r2, #0x1] */
/* @0x2a94de ldrb.w r9, [r2, #0x2] */
/* @0x2a94e0 b 0x144d4f0 <b2_toiTime+0xcf404c> */
/* @0x2a94e2 orr.w r6, r6, r8, lsl #8 */
/* @0x2a94e4 .word 0xf8922608 */
/* @0x2a94e6 ldrb.w r8, [r2, #0x3] */
/* @0x2a94e8 .word 0xf8928003 */
/* @0x2a94ea ldrb.w r10, [r2, #0x4] */
/* @0x2a94ec b 0x14d1504 <b2_toiTime+0xd78060> */
/* @0x2a94ee orr.w r9, r8, r9, lsl #8 */
/* @0x2a94f0 .word 0xf8922909 */
/* @0x2a94f2 ldrb.w r8, [r2, #0x5] */
/* @0x2a94f4 strbmi r8, [lr, #-0x5] */
/* @0x2a94f6 cmp r6, r9 */
/* @0x2a94f8 orr.w r8, r8, r10, lsl #8 */
/* @0x2a94fc bne 0x2a9502 <png_do_rgb_to_gray+0x356> */
/* @0x2a94fe cmp r6, r8 */
/* @0x2a9500 beq 0x2a9574 <png_do_rgb_to_gray+0x3c8> */
/* @0x2a9502 ldr.w r3, [r0, #0x21c] */
/* @0x2a9504 blx 0x1a75d7c <b2_toiTime+0x131c8d8> */
/* @0x2a9506 uxtb.w r10, r9 */
/* @0x2a9508 .word 0xf8d0fa89 */
/* @0x2a950a ldr.w r11, [r0, #0x23c] */
/* @0x2a950c b 0x1695e04 <b2_toiTime+0xf3c960> */
/* @0x2a950e lsr.w r9, r9, #0x8 */
/* @0x2a9510 blx 0x153397c <b2_toiTime+0xdda4d8> */
/* @0x2a9512 asr.w r10, r10, r3 */
/* @0x2a9514 .word 0xf85bfa03 */
/* @0x2a9516 ldr.w r10, [r11, r10, lsl #2] */
/* @0x2a9518 rfeda r10! */
/* @0x2a951a ldrh.w r9, [r10, r9, lsl #1] */
/* @0x2a951c blx 0x1a8d588 <b2_toiTime+0x13340e4> */
/* @0x2a951e uxtb.w r10, r6 */
/* @0x2a9520 beq 0x1067f40 <b2_toiTime+0x90ea9c> */
/* @0x2a9522 lsrs r6, r6, #0x8 */
/* @0x2a9524 asr.w r10, r10, r3 */
/* @0x2a9528 ldr.w r10, [r11, r10, lsl #2] */
/* @0x2a952c ldrh.w r6, [r10, r6, lsl #1] */
/* @0x2a9530 ldr.w r10, [sp] */
/* @0x2a9534 mul r6, r10, r6 */
/* @0x2a9538 ldr.w r10, [sp, #0x4] */
/* @0x2a953c mla r9, r10, r9, r6 */
/* @0x2a9540 uxtb.w r6, r8 */
/* @0x2a9544 lsr.w r8, r8, #0x8 */
/* @0x2a9548 asrs r6, r3 */
/* @0x2a954a ldr.w r6, [r11, r6, lsl #2] */
/* @0x2a954c rfeda r6! */
/* @0x2a954e ldrh.w r6, [r6, r8, lsl #1] */
/* @0x2a9550 blx 0x4015ba <g_RomDisk+0x9d9a> */
/* @0x2a9552 mla r9, r5, r6, r9 */
/* @0x2a9554 .word 0xf3c99906 */
/* @0x2a9556 ubfx r9, r9, #0xf, #0x10 */
/* @0x2a9558 blx 0x1a77c9c <b2_toiTime+0x131e7f8> */
/* @0x2a955a uxtb.w r6, r9 */
/* @0x2a955c b 0x16a6f88 <b2_toiTime+0xf4dae4> */
/* @0x2a955e lsr.w r9, r9, #0x8 */
/* @0x2a9560 blx 0x14339cc <b2_toiTime+0xcda528> */
/* @0x2a9562 asr.w r3, r6, r3 */
/* @0x2a9564 .word 0xf8d0f303 */
/* @0x2a9566 ldr.w r6, [r0, #0x238] */
/* @0x2a9568 .word 0xf8566238 */
/* @0x2a956a ldr.w r3, [r6, r3, lsl #2] */
/* @0x2a956c rfeda r3! */
/* @0x2a956e ldrh.w r6, [r3, r9, lsl #1] */
/* @0x2a9570 movwhs r6, #0x1019 */
/* @0x2a9572 movs r3, #0x1 */
/* @0x2a9574 strb r6, [r7, #0x1] */
/* @0x2a9576 lsr.w r8, r6, #0x8 */
/* @0x2a9578 .word 0xf8872816 */
/* @0x2a957a strb.w r8, [r7] */
/* @0x2a957c .word 0xf10c8000 */
/* @0x2a957e add.w r12, r12, #0x1 */
/* @0x2a9580 ldmibvc r6, {r0, r10, r11} */
/* @0x2a9582 ldrb r6, [r2, #0x6] */
/* @0x2a9584 adds r7, #0x4 */
/* @0x2a9586 adds r2, #0x8 */
/* @0x2a9588 strb r6, [r7, #-2] */
/* @0x2a958c ldrb r6, [r2, #-1] */
/* @0x2a9590 strb r6, [r7, #-1] */
/* @0x2a9594 b 0x2a94d2 <png_do_rgb_to_gray+0x326> */
/* @0x2a9596 ldrb.w r12, [r2] */
/* @0x2a9598 ldmdavc r7, {lr, pc} ^ */
/* @0x2a959a ldrb r7, [r2, #0x1] */
/* @0x2a959c ldrb.w r8, [r2, #0x2] */
/* @0x2a95a0 orr.w r7, r7, r12, lsl #8 */
/* @0x2a95a4 ldrb.w r12, [r2, #0x3] */
/* @0x2a95a8 ldrb.w r9, [r2, #0x4] */
/* @0x2a95ac orr.w r8, r12, r8, lsl #8 */
/* @0x2a95b0 ldrb.w r12, [r2, #0x5] */
/* @0x2a95b4 cmp r7, r8 */
/* @0x2a95b6 orr.w r12, r12, r9, lsl #8 */
/* @0x2a95b8 .word 0xd1212c09 */
/* @0x2a95ba bne 0x2a9600 <png_do_rgb_to_gray+0x454> */
/* @0x2a95bc cmp r7, r12 */
/* @0x2a95be it ne */
/* @0x2a95c0 movne r3, #0x1 */
/* @0x2a95c2 ldr.w r11, [sp] */
/* @0x2a95c4 strlo r11, [r1], -r0 */
/* @0x2a95c6 adds r6, #0x1 */
/* @0x2a95c8 ldr.w r9, [sp, #0x4] */
/* @0x2a95cc adds r2, #0x8 */
/* @0x2a95ce adds r0, #0x4 */
/* @0x2a95d0 mul r7, r11, r7 */
/* @0x2a95d4 mla r7, r9, r8, r7 */
/* @0x2a95d8 mla r7, r5, r12, r7 */
/* @0x2a95dc lsrs r7, r7, #0xf */
/* @0x2a95de strb r7, [r0, #-3] */
/* @0x2a95e0 .word 0xf3c77c03 */
/* @0x2a95e2 ubfx r12, r7, #0x8, #0x8 */
/* @0x2a95e4 .word 0xf8002c07 */
/* @0x2a95e6 strb r12, [r0, #-4] */
/* @0x2a95e8 .word 0xf812cc04 */
/* @0x2a95ea ldrb r7, [r2, #-2] */
/* @0x2a95ec .word 0xf8007c02 */
/* @0x2a95ee strb r7, [r0, #-2] */
/* @0x2a95f0 .word 0xf8127c02 */
/* @0x2a95f2 ldrb r7, [r2, #-1] */
/* @0x2a95f4 .word 0xf8007c01 */
/* @0x2a95f6 strb r7, [r0, #-1] */
/* @0x2a95f8 adcmi r7, r6, #256 */
/* @0x2a95fa cmp r6, r4 */
/* @0x2a95fc bne 0x2a9596 <png_do_rgb_to_gray+0x3ea> */
/* @0x2a95fe b 0x2a9604 <png_do_rgb_to_gray+0x458> */
/* @0x2a9600 movs r3, #0x1 */
/* @0x2a9602 b 0x2a95c2 <png_do_rgb_to_gray+0x416> */
/* @0x2a9604 ldrb r2, [r1, #0xa] */
/* @0x2a9606 ldrb r0, [r1, #0x8] */
/* @0x2a9608 subs r2, #0x2 */
/* @0x2a960a bic r0, r0, #0x2 */
/* @0x2a960c andvc r0, r8, #2 */
/* @0x2a960e strb r0, [r1, #0x8] */
/* @0x2a9610 ldrb r0, [r1, #0x9] */
/* @0x2a9612 uxtb r2, r2 */
/* @0x2a9614 strb r2, [r1, #0xa] */
/* @0x2a9616 muls r2, r0, r2 */
/* @0x2a9618 uxtb r2, r2 */
/* @0x2a961a strb r2, [r1, #0xb] */
/* @0x2a961c cmp r2, #0x7 */
/* @0x2a961e bls 0x2a9626 <png_do_rgb_to_gray+0x47a> */
/* @0x2a9620 lsrs r2, r2, #0x3 */
/* @0x2a9622 muls r4, r2, r4 */
/* @0x2a9624 b 0x2a962c <png_do_rgb_to_gray+0x480> */
/* @0x2a9626 muls r4, r2, r4 */
/* @0x2a9628 adds r4, #0x7 */
/* @0x2a962a lsrs r4, r4, #0x3 */
/* @0x2a962c str r4, [r1, #0x4] */
/* @0x2a962e b 0x2a9632 <png_do_rgb_to_gray+0x486> */
/* @0x2a9630 movs r3, #0x0 */
/* @0x2a9632 mov r0, r3 */
/* @0x2a9634 add sp, #0xc */
/* @0x2a9636 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2a9638 strdeq r8, r9, [r0], -r0 */

/* ── FUNC 0x2a963c · png_build_grayscale_palette · size=68 · insn=33 */
/* @0x2a963c push {r4, r5, lr} */
/* @0x2a963e cbz r1, 0x2a9678 <png_build_grayscale_palette+0x3c> */
/* @0x2a9640 subs r0, #0x1 */
/* @0x2a9642 cmp r0, #0x7 */
/* @0x2a9644 bhi 0x2a9654 <png_build_grayscale_palette+0x18> */
/* @0x2a9646 ldr r3, [pc, #0x34] */
/* @0x2a9648 add r3, pc */
/* @0x2a964a ldrsh.w r5, [r3, r0, lsl #1] */
/* @0x2a964c ldrmi r5, [r8], #-16 */
/* @0x2a964e add r0, r3 */
/* @0x2a9650 ldrb r0, [r0, #0x10] */
/* @0x2a9652 b 0x2a9658 <png_build_grayscale_palette+0x1c> */
/* @0x2a9654 movs r0, #0x0 */
/* @0x2a9656 mov r5, r0 */
/* @0x2a9658 movs r3, #0x0 */
/* @0x2a965a mov r2, r3 */
/* @0x2a965c cmp r2, r5 */
/* @0x2a965e add.w r1, r1, #0x3 */
/* @0x2a9660 ble 0x4e9a74 <SrcVerts+0x46ab8> */
/* @0x2a9662 bge 0x2a9678 <png_build_grayscale_palette+0x3c> */
/* @0x2a9664 uxtb r4, r3 */
/* @0x2a9666 adds r2, #0x1 */
/* @0x2a9668 strb r4, [r1, #-3] */
/* @0x2a966c add r3, r0 */
/* @0x2a966e strb r4, [r1, #-2] */
/* @0x2a9670 .word 0xf8014c02 */
/* @0x2a9672 strb r4, [r1, #-1] */
/* @0x2a9674 ldrb r4, [r1, r1, lsl #24]! */
/* @0x2a9676 b 0x2a965c <png_build_grayscale_palette+0x20> */
/* @0x2a9678 pop {r4, r5, pc} */
/* @0x2a967a nop */
/* @0x2a967c str r4, [r4, #0x34] */
/* @0x2a967e movs r6, r1 */

/* ── FUNC 0x2a9680 · png_do_background · size=2646 · insn=1129 */
/* @0x2a9680 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2a9684 sub sp, #0x1c */
/* @0x2a9686 str r0, [sp, #0xc] */
/* @0x2a9688 ldr r4, [sp, #0x44] */
/* @0x2a968a ldr r6, [sp, #0x4c] */
/* @0x2a968c ldr.w r10, [sp, #0x54] */
/* @0x2a9690 ldr.w r9, [sp, #0x58] */
/* @0x2a9694 ldr.w r11, [sp, #0x5c] */
/* @0x2a9698 ldr r0, [r0] */
/* @0x2a969a cmp r3, #0x0 */
/* @0x2a969c beq.w 0x2aa0d0 <png_do_background+0xa50> */
/* @0x2a96a0 ldr r7, [sp, #0xc] */
/* @0x2a96a2 ldrb r5, [r7, #0x8] */
/* @0x2a96a4 lsls r7, r5, #0x1d */
/* @0x2a96a6 bpl 0x2a96ae <png_do_background+0x2e> */
/* @0x2a96a8 cmp r2, #0x0 */
/* @0x2a96aa beq.w 0x2aa0d0 <png_do_background+0xa50> */
/* @0x2a96ac stchs p5, c8, [r6, #-68] */
/* @0x2a96ae cmp r5, #0x6 */
/* @0x2a96b0 bhi.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a96b4 tbh [pc, r5, lsl #1] */
/* @0x2a96b8 movs r7, r0 */
/* @0x2a96ba lsls r3, r6, #0x13 */
/* @0x2a96bc lsls r6, r0, #0x5 */
/* @0x2a96be lsls r3, r6, #0x13 */
/* @0x2a96c0 lsls r1, r6, #0x8 */
/* @0x2a96c2 lsls r3, r6, #0x13 */
/* @0x2a96c4 lsls r3, r2, #0xc */
/* @0x2a96c6 ldr r6, [sp, #0xc] */
/* @0x2a96c8 ldrb r5, [r6, #0x9] */
/* @0x2a96ca subs r5, #0x1 */
/* @0x2a96cc cmp r5, #0xf */
/* @0x2a96ce bhi.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a96d0 ldm pc, {r1, r2, r5, r6, r7, r10, pc} ^ */
/* @0x2a96d2 tbh [pc, r5, lsl #1] */
/* @0x2a96d4 andseq pc, r0, r5, lsl r0 */
/* @0x2a96d6 movs r0, r2 */
/* @0x2a96d8 movs r0, r6 */
/* @0x2a96da lsls r4, r4, #0x13 */
/* @0x2a96dc lsls r3, r1, #0x2 */
/* @0x2a96de lsls r4, r4, #0x13 */
/* @0x2a96e0 lsls r4, r4, #0x13 */
/* @0x2a96e2 lsls r4, r4, #0x13 */
/* @0x2a96e4 lsls r7, r3, #0x3 */
/* @0x2a96e6 lsls r4, r4, #0x13 */
/* @0x2a96e8 lsls r4, r4, #0x13 */
/* @0x2a96ea lsls r4, r4, #0x13 */
/* @0x2a96ec lsls r4, r4, #0x13 */
/* @0x2a96ee lsls r4, r4, #0x13 */
/* @0x2a96f0 lsls r4, r4, #0x13 */
/* @0x2a96f2 lsls r4, r4, #0x13 */
/* @0x2a96f4 lsls r2, r7, #0x3 */
/* @0x2a96f6 movs r4, #0x7 */
/* @0x2a96f8 movs r5, #0x0 */
/* @0x2a96fa movw r12, #0x7f7f */
/* @0x2a96fc addmi r7, r5, #32512 */
/* @0x2a96fe cmp r5, r0 */
/* @0x2a9700 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9704 ldrb r7, [r1] */
/* @0x2a9706 ldrh r6, [r2, #0x8] */
/* @0x2a9708 asr.w r8, r7, r4 */
/* @0x2a970c and r8, r8, #0x1 */
/* @0x2a9710 cmp r8, r6 */
/* @0x2a9712 bne 0x2a9728 <png_do_background+0xa8> */
/* @0x2a9714 rsb.w r6, r4, #0x7 */
/* @0x2a9718 asr.w r6, r12, r6 */
/* @0x2a971c ands r6, r7 */
/* @0x2a971e strb r6, [r1] */
/* @0x2a9720 ldrh r7, [r3, #0x8] */
/* @0x2a9722 lsls r7, r4 */
/* @0x2a9724 orrs r6, r7 */
/* @0x2a9726 strb r6, [r1] */
/* @0x2a9728 cbnz r4, 0x2a9730 <png_do_background+0xb0> */
/* @0x2a972a adds r1, #0x1 */
/* @0x2a972c movs r4, #0x7 */
/* @0x2a972e b 0x2a9732 <png_do_background+0xb2> */
/* @0x2a9730 subs r4, #0x1 */
/* @0x2a9732 adds r5, #0x1 */
/* @0x2a9734 b 0x2a96fe <png_do_background+0x7e> */
/* @0x2a9736 movs r5, #0x6 */
/* @0x2a9738 cbnz r4, 0x2a9740 <png_do_background+0xc0> */
/* @0x2a973a movw r12, #0x3f3f */
/* @0x2a973c sub r7, pc, pc, lsr r12 */
/* @0x2a973e b 0x2a97e0 <png_do_background+0x160> */
/* @0x2a9740 movs r7, #0x0 */
/* @0x2a9742 movw r8, #0x3f3f */
/* @0x2a9744 addmi r7, r7, #4128768 */
/* @0x2a9746 cmp r7, r0 */
/* @0x2a9748 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a974c ldrb.w r12, [r1] */
/* @0x2a9750 ldrh.w r9, [r2, #0x8] */
/* @0x2a9754 asr.w r6, r12, r5 */
/* @0x2a9758 and r6, r6, #0x3 */
/* @0x2a975c cmp r6, r9 */
/* @0x2a975e rsb.w r9, r5, #0x6 */
/* @0x2a9760 .word 0xd10c0906 */
/* @0x2a9762 bne 0x2a977e <png_do_background+0xfe> */
/* @0x2a9764 asr.w r9, r8, r9 */
/* @0x2a9768 and.w r12, r12, r9 */
/* @0x2a976c strb.w r12, [r1] */
/* @0x2a9770 ldrh.w r9, [r3, #0x8] */
/* @0x2a9774 lsl.w r9, r9, r5 */
/* @0x2a9778 orr.w r12, r12, r9 */
/* @0x2a977c b 0x2a97a2 <png_do_background+0x122> */
/* @0x2a977e uxtb r6, r6 */
/* @0x2a9780 asr.w r9, r8, r9 */
/* @0x2a9784 and.w r12, r12, r9 */
/* @0x2a9788 lsl.w r10, r6, #0x4 */
/* @0x2a978c orr.w r10, r10, r6, lsl #2 */
/* @0x2a9790 orr.w r10, r10, r6 */
/* @0x2a9794 orr.w r6, r10, r6, lsl #6 */
/* @0x2a9798 ldrb r6, [r4, r6] */
/* @0x2a979a lsrs r6, r6, #0x6 */
/* @0x2a979c lsls r6, r5 */
/* @0x2a979e orr.w r12, r6, r12 */
/* @0x2a97a0 .word 0xf8810c0c */
/* @0x2a97a2 strb.w r12, [r1] */
/* @0x2a97a4 ldmdblt r5, {lr, pc} */
/* @0x2a97a6 cbnz r5, 0x2a97ae <png_do_background+0x12e> */
/* @0x2a97a8 adds r1, #0x1 */
/* @0x2a97aa movs r5, #0x6 */
/* @0x2a97ac b 0x2a97b0 <png_do_background+0x130> */
/* @0x2a97ae subs r5, #0x2 */
/* @0x2a97b0 adds r7, #0x1 */
/* @0x2a97b2 b 0x2a9746 <png_do_background+0xc6> */
/* @0x2a97b4 ldrb r7, [r1] */
/* @0x2a97b6 ldrh r6, [r2, #0x8] */
/* @0x2a97b8 asr.w r8, r7, r5 */
/* @0x2a97bc and r8, r8, #0x3 */
/* @0x2a97c0 cmp r8, r6 */
/* @0x2a97c2 bne 0x2a97d8 <png_do_background+0x158> */
/* @0x2a97c4 rsb.w r6, r5, #0x6 */
/* @0x2a97c8 asr.w r6, r12, r6 */
/* @0x2a97cc ands r6, r7 */
/* @0x2a97ce strb r6, [r1] */
/* @0x2a97d0 ldrh r7, [r3, #0x8] */
/* @0x2a97d2 lsls r7, r5 */
/* @0x2a97d4 orrs r6, r7 */
/* @0x2a97d6 strb r6, [r1] */
/* @0x2a97d8 cbnz r5, 0x2a97e8 <png_do_background+0x168> */
/* @0x2a97da adds r1, #0x1 */
/* @0x2a97dc movs r5, #0x6 */
/* @0x2a97de adds r4, #0x1 */
/* @0x2a97e0 cmp r4, r0 */
/* @0x2a97e2 bne 0x2a97b4 <png_do_background+0x134> */
/* @0x2a97e4 b.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a97e8 subs r5, #0x2 */
/* @0x2a97ea b 0x2a97de <png_do_background+0x15e> */
/* @0x2a97ec movs r5, #0x4 */
/* @0x2a97ee cbnz r4, 0x2a97f6 <png_do_background+0x176> */
/* @0x2a97f0 movw r12, #0xf0f */
/* @0x2a97f4 b 0x2a9888 <png_do_background+0x208> */
/* @0x2a97f6 movs r6, #0x0 */
/* @0x2a97f8 movw r8, #0xf0f */
/* @0x2a97fc cmp r6, r0 */
/* @0x2a97fe beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9800 stmdavc pc, {r1, r2, r3, r6, r10, pc} */
/* @0x2a9802 ldrb r7, [r1] */
/* @0x2a9804 ldrh.w r9, [r2, #0x8] */
/* @0x2a9808 asr.w r12, r7, r5 */
/* @0x2a980c and r12, r12, #0xf */
/* @0x2a9810 cmp r12, r9 */
/* @0x2a9812 rsb.w r9, r5, #0x4 */
/* @0x2a9814 mrsle r0, apsr */
/* @0x2a9816 bne 0x2a9830 <png_do_background+0x1b0> */
/* @0x2a9818 asr.w r9, r8, r9 */
/* @0x2a981c and.w r7, r7, r9 */
/* @0x2a9820 strb r7, [r1] */
/* @0x2a9822 ldrh.w r9, [r3, #0x8] */
/* @0x2a9824 blx 0x50d84c <SrcVerts+0x6a890> */
/* @0x2a9826 lsl.w r9, r9, r5 */
/* @0x2a9828 b 0x14a7c44 <b2_toiTime+0xd4e7a0> */
/* @0x2a982a orr.w r7, r7, r9 */
/* @0x2a982c and r0, sp, r9, lsl #14 */
/* @0x2a982e b 0x2a984c <png_do_background+0x1cc> */
/* @0x2a9830 orr.w r12, r12, r12, lsl #4 */
/* @0x2a9834 asr.w r9, r8, r9 */
/* @0x2a9838 and.w r7, r7, r9 */
/* @0x2a983c ldrb.w r12, [r4, r12] */
/* @0x2a9840 lsr.w r12, r12, #0x4 */
/* @0x2a9844 lsl.w r12, r12, r5 */
/* @0x2a9848 orr.w r7, r12, r7 */
/* @0x2a984c strb r7, [r1] */
/* @0x2a984e cbnz r5, 0x2a9856 <png_do_background+0x1d6> */
/* @0x2a9850 adds r1, #0x1 */
/* @0x2a9852 movs r5, #0x4 */
/* @0x2a9854 b 0x2a9858 <png_do_background+0x1d8> */
/* @0x2a9856 subs r5, #0x4 */
/* @0x2a9858 adds r6, #0x1 */
/* @0x2a985a b 0x2a97fc <png_do_background+0x17c> */
/* @0x2a985c ldrb r7, [r1] */
/* @0x2a985e ldrh r6, [r2, #0x8] */
/* @0x2a9860 asr.w r8, r7, r5 */
/* @0x2a9864 and r8, r8, #0xf */
/* @0x2a9868 cmp r8, r6 */
/* @0x2a986a bne 0x2a9880 <png_do_background+0x200> */
/* @0x2a986c rsb.w r6, r5, #0x4 */
/* @0x2a9870 asr.w r6, r12, r6 */
/* @0x2a9874 ands r6, r7 */
/* @0x2a9876 strb r6, [r1] */
/* @0x2a9878 ldrh r7, [r3, #0x8] */
/* @0x2a987a lsls r7, r5 */
/* @0x2a987c orrs r6, r7 */
/* @0x2a987e strb r6, [r1] */
/* @0x2a9880 cbnz r5, 0x2a9890 <png_do_background+0x210> */
/* @0x2a9882 adds r1, #0x1 */
/* @0x2a9884 movs r5, #0x4 */
/* @0x2a9886 adds r4, #0x1 */
/* @0x2a9888 cmp r4, r0 */
/* @0x2a988a bne 0x2a985c <png_do_background+0x1dc> */
/* @0x2a988c b.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9890 subs r5, #0x4 */
/* @0x2a9892 b 0x2a9886 <png_do_background+0x206> */
/* @0x2a9894 adds r5, r1, r0 */
/* @0x2a9896 cbz r4, 0x2a98b2 <png_do_background+0x232> */
/* @0x2a9898 cmp r1, r5 */
/* @0x2a989a beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a989c .word 0xf8118400 */
/* @0x2a989e ldrb r6, [r1], #1 */
/* @0x2a98a0 ldmdbhi r7, {r0, r8, r9, r11, sp, lr} */
/* @0x2a98a2 ldrh r7, [r2, #0x8] */
/* @0x2a98a4 cmp r7, r6 */
/* @0x2a98a6 ite eq */
/* @0x2a98a8 ldrheq r6, [r3, #0x8] */
/* @0x2a98aa ldrbne r6, [r4, r6] */
/* @0x2a98ac strb r6, [r1, #-1] */
/* @0x2a98b0 b 0x2a9898 <png_do_background+0x218> */
/* @0x2a98b2 cmp r1, r5 */
/* @0x2a98b4 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a98b8 ldrb r4, [r1], #1 */
/* @0x2a98bc ldrh r6, [r2, #0x8] */
/* @0x2a98be cmp r6, r4 */
/* @0x2a98c0 itt eq */
/* @0x2a98c2 ldrheq r4, [r3, #0x8] */
/* @0x2a98c4 strbeq r4, [r1, #-1] */
/* @0x2a98c8 b 0x2a98b2 <png_do_background+0x232> */
/* @0x2a98ca ldr r4, [sp, #0x50] */
/* @0x2a98cc adds r1, #0x2 */
/* @0x2a98ce cbz r4, 0x2a993e <png_do_background+0x2be> */
/* @0x2a98d0 movs r4, #0x0 */
/* @0x2a98d2 cmp r4, r0 */
/* @0x2a98d4 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a98d8 ldrb r5, [r1, #-2] */
/* @0x2a98dc ldrb r6, [r1, #-1] */
/* @0x2a98e0 ldrh.w r12, [r2, #0x8] */
/* @0x2a98e4 add.w r7, r6, r5, lsl #8 */
/* @0x2a98e8 uxth r7, r7 */
/* @0x2a98ea cmp r12, r7 */
/* @0x2a98ec bne 0x2a98fa <png_do_background+0x27a> */
/* @0x2a98ee ldrh r5, [r3, #0x8] */
/* @0x2a98f0 lsrs r5, r5, #0x8 */
/* @0x2a98f2 strb r5, [r1, #-2] */
/* @0x2a98f4 ldmdbhi sp, {r1, r10, r11, r12, lr} */
/* @0x2a98f6 ldrh r5, [r3, #0x8] */
/* @0x2a98f8 b 0x2a990e <png_do_background+0x28e> */
/* @0x2a98fa ldr r7, [sp, #0x50] */
/* @0x2a98fc asr.w r6, r6, r11 */
/* @0x2a9900 ldr.w r6, [r7, r6, lsl #2] */
/* @0x2a9904 ldrh.w r5, [r6, r5, lsl #1] */
/* @0x2a9908 lsrs r6, r5, #0x8 */
/* @0x2a990a strb r6, [r1, #-2] */
/* @0x2a990c .word 0xf8016c02 */
/* @0x2a990e strb r5, [r1, #-1] */
/* @0x2a9910 strlo r5, [r1], #-3073 */
/* @0x2a9912 adds r4, #0x1 */
/* @0x2a9914 adds r1, #0x2 */
/* @0x2a9916 b 0x2a98d2 <png_do_background+0x252> */
/* @0x2a9918 ldrb r6, [r1, #-2] */
/* @0x2a991c ldrb r5, [r1, #-1] */
/* @0x2a9920 add.w r5, r5, r6, lsl #8 */
/* @0x2a9924 ldrh r6, [r2, #0x8] */
/* @0x2a9926 uxth r5, r5 */
/* @0x2a9928 cmp r6, r5 */
/* @0x2a992a bne 0x2a993a <png_do_background+0x2ba> */
/* @0x2a992c ldrh r5, [r3, #0x8] */
/* @0x2a992e lsrs r5, r5, #0x8 */
/* @0x2a9930 strb r5, [r1, #-2] */
/* @0x2a9934 ldrh r5, [r3, #0x8] */
/* @0x2a9936 strb r5, [r1, #-1] */
/* @0x2a9938 strlo r5, [r1], #-3073 */
/* @0x2a993a adds r4, #0x1 */
/* @0x2a993c adds r1, #0x2 */
/* @0x2a993e cmp r4, r0 */
/* @0x2a9940 bne 0x2a9918 <png_do_background+0x298> */
/* @0x2a9942 b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9944 ldr r6, [sp, #0xc] */
/* @0x2a9946 ldrb r5, [r6, #0x9] */
/* @0x2a9948 cmp r5, #0x8 */
/* @0x2a994a bne 0x2a99da <png_do_background+0x35a> */
/* @0x2a994c movs r6, #0x3 */
/* @0x2a994e cbnz r4, 0x2a9956 <png_do_background+0x2d6> */
/* @0x2a9950 mla r6, r6, r0, r1 */
/* @0x2a9954 b 0x2a99b6 <png_do_background+0x336> */
/* @0x2a9956 mla r7, r6, r0, r1 */
/* @0x2a9958 stclne p7, c1, [sp], {0} */
/* @0x2a995a adds r5, r1, #0x3 */
/* @0x2a995c cmp r1, r7 */
/* @0x2a995e beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9960 .word 0xf815839e */
/* @0x2a9962 ldrb r6, [r5, #-3] */
/* @0x2a9964 rfeia r2! */
/* @0x2a9966 ldrh.w r12, [r2, #0x2] */
/* @0x2a9968 ldrmi r12, [r4, #0x2]! */
/* @0x2a996a cmp r12, r6 */
/* @0x2a996c bne 0x2a9994 <png_do_background+0x314> */
/* @0x2a996e ldrb.w r8, [r1, #0x1] */
/* @0x2a9970 rfeia r2! */
/* @0x2a9972 ldrh.w r12, [r2, #0x4] */
/* @0x2a9974 strbmi r12, [r0, #0x4]! */
/* @0x2a9976 cmp r8, r12 */
/* @0x2a9978 bne 0x2a9994 <png_do_background+0x314> */
/* @0x2a997a ldrb.w r8, [r1, #0x2] */
/* @0x2a997c rfeia r2! */
/* @0x2a997e ldrh.w r12, [r2, #0x6] */
/* @0x2a9980 strbmi r12, [r0, #0x6]! */
/* @0x2a9982 cmp r8, r12 */
/* @0x2a9984 bne 0x2a9994 <png_do_background+0x314> */
/* @0x2a9986 ldrh r6, [r3, #0x2] */
/* @0x2a9988 strb r6, [r5, #-3] */
/* @0x2a998c ldrh r6, [r3, #0x4] */
/* @0x2a998e strb r6, [r1, #0x1] */
/* @0x2a9990 ldrh r6, [r3, #0x6] */
/* @0x2a9992 b 0x2a99a4 <png_do_background+0x324> */
/* @0x2a9994 ldrb r6, [r4, r6] */
/* @0x2a9996 strb r6, [r5, #-3] */
/* @0x2a9998 stmdavc lr, {r0, r1, r10, r11, sp, lr} ^ */
/* @0x2a999a ldrb r6, [r1, #0x1] */
/* @0x2a999c ldrb r6, [r4, r6] */
/* @0x2a999e strb r6, [r1, #0x1] */
/* @0x2a99a0 ldrb r6, [r1, #0x2] */
/* @0x2a99a2 ldrb r6, [r4, r6] */
/* @0x2a99a4 strb r6, [r1, #0x2] */
/* @0x2a99a6 adds r5, #0x3 */
/* @0x2a99a8 adds r1, #0x3 */
/* @0x2a99aa b 0x2a995c <png_do_background+0x2dc> */
/* @0x2a99ac ldrb r5, [r1] */
/* @0x2a99ae ldrh r4, [r2, #0x2] */
/* @0x2a99b0 cmp r5, r4 */
/* @0x2a99b2 beq 0x2a99bc <png_do_background+0x33c> */
/* @0x2a99b4 adds r1, #0x3 */
/* @0x2a99b6 cmp r1, r6 */
/* @0x2a99b8 bne 0x2a99ac <png_do_background+0x32c> */
/* @0x2a99ba b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a99bc ldrb r5, [r1, #0x1] */
/* @0x2a99be ldrh r4, [r2, #0x4] */
/* @0x2a99c0 cmp r5, r4 */
/* @0x2a99c2 bne 0x2a99b4 <png_do_background+0x334> */
/* @0x2a99c4 ldrb r5, [r1, #0x2] */
/* @0x2a99c6 ldrh r4, [r2, #0x6] */
/* @0x2a99c8 cmp r5, r4 */
/* @0x2a99ca bne 0x2a99b4 <png_do_background+0x334> */
/* @0x2a99cc ldrh r4, [r3, #0x2] */
/* @0x2a99ce strb r4, [r1] */
/* @0x2a99d0 ldrh r4, [r3, #0x4] */
/* @0x2a99d2 strb r4, [r1, #0x1] */
/* @0x2a99d4 ldrh r4, [r3, #0x6] */
/* @0x2a99d6 strb r4, [r1, #0x2] */
/* @0x2a99d8 b 0x2a99b4 <png_do_background+0x334> */
/* @0x2a99da ldr r7, [sp, #0x50] */
/* @0x2a99dc cbnz r7, 0x2a99e2 <png_do_background+0x362> */
/* @0x2a99de mov r4, r7 */
/* @0x2a99e0 b 0x2a9ada <png_do_background+0x45a> */
/* @0x2a99e2 adds r4, r1, #0x6 */
/* @0x2a99e4 movs r5, #0x0 */
/* @0x2a99e6 cmp r5, r0 */
/* @0x2a99e8 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a99ec ldrb r8, [r4, #-6] */
/* @0x2a99f0 ldrb.w r10, [r1, #0x2] */
/* @0x2a99f4 ldrb.w r9, [r1, #0x1] */
/* @0x2a99f8 ldrb r6, [r1, #0x4] */
/* @0x2a99fa add.w r7, r9, r8, lsl #8 */
/* @0x2a99fc .word 0xf8cd2708 */
/* @0x2a99fe str.w r10, [sp, #0x8] */
/* @0x2a9a00 rfeia r2! */
/* @0x2a9a02 ldrh.w r10, [r2, #0x2] */
/* @0x2a9a04 adcslt r10, pc, #2 */
/* @0x2a9a06 uxth r7, r7 */
/* @0x2a9a08 str r6, [sp, #0x10] */
/* @0x2a9a0a cmp r10, r7 */
/* @0x2a9a0c ldrb.w r12, [r1, #0x3] */
/* @0x2a9a10 ldrb r6, [r1, #0x5] */
/* @0x2a9a12 bne 0x2a9a60 <png_do_background+0x3e0> */
/* @0x2a9a14 ldr r7, [sp, #0x8] */
/* @0x2a9a16 add.w r7, r12, r7, lsl #8 */
/* @0x2a9a18 strls r2, [r1, -r7, lsl #14] */
/* @0x2a9a1a str r7, [sp, #0x4] */
/* @0x2a9a1c ldr.w r10, [sp, #0x4] */
/* @0x2a9a20 ldrh r7, [r2, #0x4] */
/* @0x2a9a22 uxth.w r10, r10 */
/* @0x2a9a24 ldrbmi pc, [r7, #-0xa8a] */
/* @0x2a9a26 cmp r7, r10 */
/* @0x2a9a28 bne 0x2a9a60 <png_do_background+0x3e0> */
/* @0x2a9a2a ldr.w r10, [sp, #0x10] */
/* @0x2a9a2c ldmhi r7, {r4, sp, pc} ^ */
/* @0x2a9a2e ldrh r7, [r2, #0x6] */
/* @0x2a9a30 add.w r10, r6, r10, lsl #8 */
/* @0x2a9a34 str.w r10, [sp, #0x4] */
/* @0x2a9a38 uxth.w r10, r10 */
/* @0x2a9a3c cmp r7, r10 */
/* @0x2a9a3e bne 0x2a9a60 <png_do_background+0x3e0> */
/* @0x2a9a40 ldrh r6, [r3, #0x2] */
/* @0x2a9a42 lsrs r6, r6, #0x8 */
/* @0x2a9a44 strb r6, [r4, #-6] */
/* @0x2a9a48 ldrh r6, [r3, #0x2] */
/* @0x2a9a4a strb r6, [r1, #0x1] */
/* @0x2a9a4c ldrh r6, [r3, #0x4] */
/* @0x2a9a4e lsrs r6, r6, #0x8 */
/* @0x2a9a50 strb r6, [r1, #0x2] */
/* @0x2a9a52 ldrh r6, [r3, #0x4] */
/* @0x2a9a54 strb r6, [r1, #0x3] */
/* @0x2a9a56 ldrh r6, [r3, #0x6] */
/* @0x2a9a58 lsrs r6, r6, #0x8 */
/* @0x2a9a5a strb r6, [r1, #0x4] */
/* @0x2a9a5c ldrh r6, [r3, #0x6] */
/* @0x2a9a5e b 0x2a9aaa <png_do_background+0x42a> */
/* @0x2a9a60 ldr r7, [sp, #0x50] */
/* @0x2a9a62 asr.w r9, r9, r11 */
/* @0x2a9a64 blx 0x15e7e98 <b2_toiTime+0xe8e9f4> */
/* @0x2a9a66 asr.w r12, r12, r11 */
/* @0x2a9a68 blx 0x1468a9c <b2_toiTime+0xd0f5f8> */
/* @0x2a9a6a asr.w r6, r6, r11 */
/* @0x2a9a6c .word 0xf857f60b */
/* @0x2a9a6e ldr.w r9, [r7, r9, lsl #2] */
/* @0x2a9a70 rfeda r9! */
/* @0x2a9a72 ldrh.w r8, [r9, r8, lsl #1] */
/* @0x2a9a74 b 0x1689adc <b2_toiTime+0xf30638> */
/* @0x2a9a76 lsr.w r9, r8, #0x8 */
/* @0x2a9a78 .word 0xf8042918 */
/* @0x2a9a7a strb r9, [r4, #-6] */
/* @0x2a9a7c .word 0xf8819c06 */
/* @0x2a9a7e strb.w r8, [r1, #0x1] */
/* @0x2a9a80 .word 0xf8578001 */
/* @0x2a9a82 ldr.w r12, [r7, r12, lsl #2] */
/* @0x2a9a84 .word 0xf8ddc02c */
/* @0x2a9a86 ldr.w r8, [sp, #0x8] */
/* @0x2a9a88 rfeda r12! */
/* @0x2a9a8a ldrh.w r7, [r12, r8, lsl #1] */
/* @0x2a9a8c .word 0xf8dd7018 */
/* @0x2a9a8e ldr.w r8, [sp, #0x10] */
/* @0x2a9a90 sbcvc r8, pc, r0, lsl r0 */
/* @0x2a9a92 strb r7, [r1, #0x3] */
/* @0x2a9a94 lsr.w r12, r7, #0x8 */
/* @0x2a9a98 ldr r7, [sp, #0x50] */
/* @0x2a9a9a strb.w r12, [r1, #0x2] */
/* @0x2a9a9c .word 0xf857c002 */
/* @0x2a9a9e ldr.w r6, [r7, r6, lsl #2] */
/* @0x2a9aa0 rfeda r6! */
/* @0x2a9aa2 ldrh.w r6, [r6, r8, lsl #1] */
/* @0x2a9aa4 beq 0x1081b0c <b2_toiTime+0x928668> */
/* @0x2a9aa6 lsrs r7, r6, #0x8 */
/* @0x2a9aa8 strb r7, [r1, #0x4] */
/* @0x2a9aaa strb r6, [r1, #0x5] */
/* @0x2a9aac adds r5, #0x1 */
/* @0x2a9aae adds r1, #0x6 */
/* @0x2a9ab0 adds r4, #0x6 */
/* @0x2a9ab2 b 0x2a99e6 <png_do_background+0x366> */
/* @0x2a9ab4 ldrb.w r9, [r1] */
/* @0x2a9ab8 ldrb.w r8, [r1, #0x1] */
/* @0x2a9abc ldrb.w r12, [r1, #0x2] */
/* @0x2a9ac0 add.w r8, r8, r9, lsl #8 */
/* @0x2a9ac4 ldrh.w r9, [r2, #0x2] */
/* @0x2a9ac8 ldrb r7, [r1, #0x3] */
/* @0x2a9aca uxth.w r8, r8 */
/* @0x2a9acc stmdbvc lr, {r3, r7, r11, r12, sp, lr, pc} */
/* @0x2a9ace ldrb r6, [r1, #0x4] */
/* @0x2a9ad0 cmp r9, r8 */
/* @0x2a9ad2 ldrb r5, [r1, #0x5] */
/* @0x2a9ad4 beq 0x2a9ae0 <png_do_background+0x460> */
/* @0x2a9ad6 adds r4, #0x1 */
/* @0x2a9ad8 adds r1, #0x6 */
/* @0x2a9ada cmp r4, r0 */
/* @0x2a9adc bne 0x2a9ab4 <png_do_background+0x434> */
/* @0x2a9ade b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9ae0 add.w r7, r7, r12, lsl #8 */
/* @0x2a9ae4 ldrh.w r12, [r2, #0x4] */
/* @0x2a9ae8 uxth r7, r7 */
/* @0x2a9aea cmp r12, r7 */
/* @0x2a9aec bne 0x2a9ad6 <png_do_background+0x456> */
/* @0x2a9aee add.w r5, r5, r6, lsl #8 */
/* @0x2a9af0 ldmhi r6, {r1, r2, r8, r10, sp} ^ */
/* @0x2a9af2 ldrh r6, [r2, #0x6] */
/* @0x2a9af4 uxth r5, r5 */
/* @0x2a9af6 cmp r6, r5 */
/* @0x2a9af8 bne 0x2a9ad6 <png_do_background+0x456> */
/* @0x2a9afa ldrh r5, [r3, #0x2] */
/* @0x2a9afc lsrs r5, r5, #0x8 */
/* @0x2a9afe strb r5, [r1] */
/* @0x2a9b00 ldrh r5, [r3, #0x2] */
/* @0x2a9b02 strb r5, [r1, #0x1] */
/* @0x2a9b04 ldrh r5, [r3, #0x4] */
/* @0x2a9b06 lsrs r5, r5, #0x8 */
/* @0x2a9b08 strb r5, [r1, #0x2] */
/* @0x2a9b0a ldrh r5, [r3, #0x4] */
/* @0x2a9b0c strb r5, [r1, #0x3] */
/* @0x2a9b0e ldrh r5, [r3, #0x6] */
/* @0x2a9b10 lsrs r5, r5, #0x8 */
/* @0x2a9b12 strb r5, [r1, #0x4] */
/* @0x2a9b14 ldrh r5, [r3, #0x6] */
/* @0x2a9b16 strb r5, [r1, #0x5] */
/* @0x2a9b18 b 0x2a9ad6 <png_do_background+0x456> */
/* @0x2a9b1a ldr r5, [sp, #0xc] */
/* @0x2a9b1c ldrb r2, [r5, #0x9] */
/* @0x2a9b1e cmp r2, #0x8 */
/* @0x2a9b20 bne 0x2a9bd4 <png_do_background+0x554> */
/* @0x2a9b22 adds r7, r1, #0x2 */
/* @0x2a9b24 cbz r6, 0x2a9b2a <png_do_background+0x4aa> */
/* @0x2a9b26 ldr r2, [sp, #0x48] */
/* @0x2a9b28 cbnz r2, 0x2a9b30 <png_do_background+0x4b0> */
/* @0x2a9b2a mov r4, r7 */
/* @0x2a9b2c movs r2, #0x0 */
/* @0x2a9b2e b 0x2a9baa <png_do_background+0x52a> */
/* @0x2a9b30 cmp r4, #0x0 */
/* @0x2a9b32 beq 0x2a9b2a <png_do_background+0x4aa> */
/* @0x2a9b34 movs r2, #0x0 */
/* @0x2a9b36 cmp r2, r0 */
/* @0x2a9b38 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9b3c ldrb r12, [r7, #-1] */
/* @0x2a9b40 cmp.w r12, #0xff */
/* @0x2a9b44 bne 0x2a9b50 <png_do_background+0x4d0> */
/* @0x2a9b46 ldrb r12, [r7, #-2] */
/* @0x2a9b48 .word 0xf814cc02 */
/* @0x2a9b4a ldrb.w r12, [r4, r12] */
/* @0x2a9b4c ands r12, lr, r12 */
/* @0x2a9b4e b 0x2a9b8e <png_do_background+0x50e> */
/* @0x2a9b50 cmp.w r12, #0x0 */
/* @0x2a9b54 bne 0x2a9b5c <png_do_background+0x4dc> */
/* @0x2a9b56 ldrh.w r12, [r3, #0x8] */
/* @0x2a9b58 ands r12, r8, r8 */
/* @0x2a9b5a b 0x2a9b8e <png_do_background+0x50e> */
/* @0x2a9b5c ldr r5, [sp, #0x40] */
/* @0x2a9b5e rsb.w r9, r12, #0xff */
/* @0x2a9b60 rfeia r5! */
/* @0x2a9b62 ldrh.w r8, [r5, #0x8] */
/* @0x2a9b64 blx 0x509b8e <SrcVerts+0x66bd2> */
/* @0x2a9b66 mul r8, r9, r8 */
/* @0x2a9b68 .word 0xf817f808 */
/* @0x2a9b6a ldrb r9, [r7, #-2] */
/* @0x2a9b6c .word 0xf8169c02 */
/* @0x2a9b6e ldrb.w r9, [r6, r9] */
/* @0x2a9b70 .word 0xf1089009 */
/* @0x2a9b72 add.w r8, r8, #0x80 */
/* @0x2a9b74 blx 0x4ebd7e <SrcVerts+0x48dc2> */
/* @0x2a9b76 mla r12, r9, r12, r8 */
/* @0x2a9b78 .word 0xf8dd8c0c */
/* @0x2a9b7a ldr.w r8, [sp, #0x48] */
/* @0x2a9b7c blx 0xa89ca4 <b2_toiTime+0x330800> */
/* @0x2a9b7e uxth.w r12, r12 */
/* @0x2a9b80 bl 0x5e8db8 <g_SWFaavertbuff+0x15cf0> */
/* @0x2a9b82 add.w r12, r12, r12, lsr #8 */
/* @0x2a9b84 .word 0xf3cc2c1c */
/* @0x2a9b86 ubfx r12, r12, #0x8, #0x8 */
/* @0x2a9b88 .word 0xf8182c07 */
/* @0x2a9b8a ldrb.w r12, [r8, r12] */
/* @0x2a9b8c .word 0xf801c00c */
/* @0x2a9b8e strb.w r12, [r1, r2] */
/* @0x2a9b90 strlo r12, [r2, -r2] */
/* @0x2a9b92 adds r7, #0x2 */
/* @0x2a9b94 adds r2, #0x1 */
/* @0x2a9b96 b 0x2a9b36 <png_do_background+0x4b6> */
/* @0x2a9b98 ldrb r5, [r4, #-1] */
/* @0x2a9b9c cmp r5, #0xff */
/* @0x2a9b9e bne 0x2a9bb0 <png_do_background+0x530> */
/* @0x2a9ba0 ldrb r5, [r4, #-2] */
/* @0x2a9ba4 strb r5, [r1, r2] */
/* @0x2a9ba6 adds r4, #0x2 */
/* @0x2a9ba8 adds r2, #0x1 */
/* @0x2a9baa cmp r2, r0 */
/* @0x2a9bac bne 0x2a9b98 <png_do_background+0x518> */
/* @0x2a9bae b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9bb0 cbnz r5, 0x2a9bb6 <png_do_background+0x536> */
/* @0x2a9bb2 ldrh r5, [r3, #0x8] */
/* @0x2a9bb4 b 0x2a9ba4 <png_do_background+0x524> */
/* @0x2a9bb6 ldrb r6, [r4, #-2] */
/* @0x2a9bb8 .word 0xf1c56c02 */
/* @0x2a9bba rsb.w r12, r5, #0xff */
/* @0x2a9bbc .word 0x436e0cff */
/* @0x2a9bbe muls r6, r5, r6 */
/* @0x2a9bc0 ldr r5, [sp, #0x40] */
/* @0x2a9bc2 ldrh r7, [r5, #0x8] */
/* @0x2a9bc4 adds r6, #0x80 */
/* @0x2a9bc6 mla r5, r12, r7, r6 */
/* @0x2a9bc8 adclt r6, sp, #29360128 */
/* @0x2a9bca uxth r5, r5 */
/* @0x2a9bcc add.w r5, r5, r5, lsr #8 */
/* @0x2a9bd0 asrs r5, r5, #0x8 */
/* @0x2a9bd2 b 0x2a9ba4 <png_do_background+0x524> */
/* @0x2a9bd4 ldr r6, [sp, #0x50] */
/* @0x2a9bd6 cbz r6, 0x2a9bde <png_do_background+0x55e> */
/* @0x2a9bd8 cmp.w r10, #0x0 */
/* @0x2a9bdc bne 0x2a9be8 <png_do_background+0x568> */
/* @0x2a9bde mov r2, r1 */
/* @0x2a9be0 movs r5, #0x0 */
/* @0x2a9be2 movw r6, #0xffff */
/* @0x2a9be4 ldrsh r7, [r8], #-111 */
/* @0x2a9be6 b 0x2a9c9a <png_do_background+0x61a> */
/* @0x2a9be8 cmp.w r9, #0x0 */
/* @0x2a9bec beq 0x2a9bde <png_do_background+0x55e> */
/* @0x2a9bee adds r2, r1, #0x2 */
/* @0x2a9bf0 movs r5, #0x0 */
/* @0x2a9bf2 cmp r5, r0 */
/* @0x2a9bf4 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9bf8 ldrb r7, [r1, #0x2] */
/* @0x2a9bfa ldrb r4, [r1, #0x3] */
/* @0x2a9bfc add.w r4, r4, r7, lsl #8 */
/* @0x2a9c00 movw r7, #0xffff */
/* @0x2a9c04 uxth r4, r4 */
/* @0x2a9c06 cmp r4, r7 */
/* @0x2a9c08 bne 0x2a9c1e <png_do_background+0x59e> */
/* @0x2a9c0a ldrb r4, [r1, #0x1] */
/* @0x2a9c0c ldr r6, [sp, #0x50] */
/* @0x2a9c0e ldrb r7, [r1] */
/* @0x2a9c10 asr.w r4, r4, r11 */
/* @0x2a9c14 ldr.w r4, [r6, r4, lsl #2] */
/* @0x2a9c18 ldrh.w r4, [r4, r7, lsl #1] */
/* @0x2a9c1c b 0x2a9c70 <png_do_background+0x5f0> */
/* @0x2a9c1e cbnz r4, 0x2a9c2c <png_do_background+0x5ac> */
/* @0x2a9c20 ldrh r4, [r3, #0x8] */
/* @0x2a9c22 lsrs r4, r4, #0x8 */
/* @0x2a9c24 strb r4, [r2, #-2] */
/* @0x2a9c28 ldrh r4, [r3, #0x8] */
/* @0x2a9c2a b 0x2a9c76 <png_do_background+0x5f6> */
/* @0x2a9c2c ldr r6, [sp, #0x40] */
/* @0x2a9c2e rsb.w r7, r4, #0xff00 */
/* @0x2a9c30 .word 0x37ff477f */
/* @0x2a9c32 adds r7, #0xff */
/* @0x2a9c34 ldrb.w r8, [r1] */
/* @0x2a9c38 ldrh.w r12, [r6, #0x8] */
/* @0x2a9c3c mul r7, r12, r7 */
/* @0x2a9c40 ldrb.w r12, [r1, #0x1] */
/* @0x2a9c44 asr.w r12, r12, r11 */
/* @0x2a9c48 add.w r7, r7, #0x8000 */
/* @0x2a9c4c ldr.w r12, [r9, r12, lsl #2] */
/* @0x2a9c50 ldrh.w r12, [r12, r8, lsl #1] */
/* @0x2a9c54 mla r4, r4, r12, r7 */
/* @0x2a9c58 add.w r4, r4, r4, lsr #16 */
/* @0x2a9c5c lsrs r4, r4, #0x10 */
/* @0x2a9c5e uxtb.w r8, r4 */
/* @0x2a9c60 beq 0xbe7e78 <b2_toiTime+0x48e9d4> */
/* @0x2a9c62 lsrs r4, r4, #0x8 */
/* @0x2a9c64 asr.w r8, r8, r11 */
/* @0x2a9c68 ldr.w r7, [r10, r8, lsl #2] */
/* @0x2a9c6c ldrh.w r4, [r7, r4, lsl #1] */
/* @0x2a9c70 lsrs r7, r4, #0x8 */
/* @0x2a9c72 strb r7, [r2, #-2] */
/* @0x2a9c74 .word 0xf8027c02 */
/* @0x2a9c76 strb r4, [r2, #-1] */
/* @0x2a9c78 strlo r4, [r1, #-0xc01] */
/* @0x2a9c7a adds r5, #0x1 */
/* @0x2a9c7c adds r1, #0x4 */
/* @0x2a9c7e adds r2, #0x2 */
/* @0x2a9c80 b 0x2a9bf2 <png_do_background+0x572> */
/* @0x2a9c82 ldrb r7, [r1, #0x2] */
/* @0x2a9c84 ldrb r4, [r1, #0x3] */
/* @0x2a9c86 add.w r4, r4, r7, lsl #8 */
/* @0x2a9c88 adclt r2, r4, #117440512 */
/* @0x2a9c8a uxth r4, r4 */
/* @0x2a9c8c cmp r4, r6 */
/* @0x2a9c8e bne 0x2a9ca0 <png_do_background+0x620> */
/* @0x2a9c90 ldrh r4, [r1] */
/* @0x2a9c92 strh r4, [r2] */
/* @0x2a9c94 adds r5, #0x1 */
/* @0x2a9c96 adds r1, #0x4 */
/* @0x2a9c98 adds r2, #0x2 */
/* @0x2a9c9a cmp r5, r0 */
/* @0x2a9c9c bne 0x2a9c82 <png_do_background+0x602> */
/* @0x2a9c9e b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9ca0 cbnz r4, 0x2a9cac <png_do_background+0x62c> */
/* @0x2a9ca2 ldrh r4, [r3, #0x8] */
/* @0x2a9ca4 lsrs r4, r4, #0x8 */
/* @0x2a9ca6 strb r4, [r2] */
/* @0x2a9ca8 ldrh r4, [r3, #0x8] */
/* @0x2a9caa b 0x2a9cda <png_do_background+0x65a> */
/* @0x2a9cac ldrb.w r12, [r1] */
/* @0x2a9cb0 ldrb r7, [r1, #0x1] */
/* @0x2a9cb2 add.w r7, r7, r12, lsl #8 */
/* @0x2a9cb4 adcslt r2, pc, #12, #14 */
/* @0x2a9cb6 uxth r7, r7 */
/* @0x2a9cb8 muls r7, r4, r7 */
/* @0x2a9cba rsb.w r4, r4, #0xff00 */
/* @0x2a9cbc .word 0xf104447f */
/* @0x2a9cbe add.w r8, r4, #0xff */
/* @0x2a9cc0 .word 0x9c1008ff */
/* @0x2a9cc2 ldr r4, [sp, #0x40] */
/* @0x2a9cc4 add.w r7, r7, #0x8000 */
/* @0x2a9cc8 ldrh.w r12, [r4, #0x8] */
/* @0x2a9ccc mla r4, r12, r8, r7 */
/* @0x2a9cd0 add.w r4, r4, r4, lsr #16 */
/* @0x2a9cd4 lsrs r4, r4, #0x10 */
/* @0x2a9cd6 lsrs r7, r4, #0x8 */
/* @0x2a9cd8 strb r7, [r2] */
/* @0x2a9cda strb r4, [r2, #0x1] */
/* @0x2a9cdc b 0x2a9c94 <png_do_background+0x614> */
/* @0x2a9cde ldr r5, [sp, #0xc] */
/* @0x2a9ce0 ldrb r2, [r5, #0x9] */
/* @0x2a9ce2 cmp r2, #0x8 */
/* @0x2a9ce4 bne.w 0x2a9e5e <png_do_background+0x7de> */
/* @0x2a9ce8 add.w r12, r1, #0x3 */
/* @0x2a9cec cbz r6, 0x2a9cf2 <png_do_background+0x672> */
/* @0x2a9cee ldr r7, [sp, #0x48] */
/* @0x2a9cf0 cbnz r7, 0x2a9d00 <png_do_background+0x680> */
/* @0x2a9cf2 mov.w r8, #0x3 */
/* @0x2a9cf4 strbtmi r0, [r5], -r3, lsl #16 */
/* @0x2a9cf6 mov r5, r12 */
/* @0x2a9cf8 mla r8, r8, r0, r1 */
/* @0x2a9cfc mov r2, r1 */
/* @0x2a9cfe b 0x2a9dfa <png_do_background+0x77a> */
/* @0x2a9d00 cmp r4, #0x0 */
/* @0x2a9d02 beq 0x2a9cf2 <png_do_background+0x672> */
/* @0x2a9d04 mov.w r9, #0x3 */
/* @0x2a9d08 mov r2, r1 */
/* @0x2a9d0a mla r9, r9, r0, r1 */
/* @0x2a9d0c strbmi r1, [r10, #-0x900] */
/* @0x2a9d0e cmp r2, r9 */
/* @0x2a9d10 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9d14 ldrb r7, [r1, #0x3] */
/* @0x2a9d16 cmp r7, #0xff */
/* @0x2a9d18 bne 0x2a9d2e <png_do_background+0x6ae> */
/* @0x2a9d1a ldrb r7, [r1] */
/* @0x2a9d1c ldrb r7, [r4, r7] */
/* @0x2a9d1e strb r7, [r12, #-3] */
/* @0x2a9d20 stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^ */
/* @0x2a9d22 ldrb r7, [r1, #0x1] */
/* @0x2a9d24 ldrb r7, [r4, r7] */
/* @0x2a9d26 strb r7, [r2, #0x1] */
/* @0x2a9d28 ldrb r7, [r1, #0x2] */
/* @0x2a9d2a ldrb r7, [r4, r7] */
/* @0x2a9d2c b 0x2a9dd4 <png_do_background+0x754> */
/* @0x2a9d2e cbnz r7, 0x2a9d3e <png_do_background+0x6be> */
/* @0x2a9d30 ldrh r7, [r3, #0x2] */
/* @0x2a9d32 strb r7, [r12, #-3] */
/* @0x2a9d34 ldmhi pc, {r0, r1, r10, r11, r12, sp, lr} */
/* @0x2a9d36 ldrh r7, [r3, #0x4] */
/* @0x2a9d38 strb r7, [r2, #0x1] */
/* @0x2a9d3a ldrh r7, [r3, #0x6] */
/* @0x2a9d3c b 0x2a9dd4 <png_do_background+0x754> */
/* @0x2a9d3e ldr r5, [sp, #0x40] */
/* @0x2a9d40 rsb.w r8, r7, #0xff */
/* @0x2a9d44 ldrb.w r11, [r1] */
/* @0x2a9d48 uxth.w r8, r8 */
/* @0x2a9d4c ldrh.w r10, [r5, #0x2] */
/* @0x2a9d50 ldrb.w r11, [r6, r11] */
/* @0x2a9d54 ldr r5, [sp, #0x48] */
/* @0x2a9d56 mul r10, r10, r8 */
/* @0x2a9d58 .word 0xf10afa08 */
/* @0x2a9d5a add.w r10, r10, #0x80 */
/* @0x2a9d5c blx 0x56c766 <g_SWFlineaavertbuff+0x1969e> */
/* @0x2a9d5e mla r10, r11, r7, r10 */
/* @0x2a9d60 blx 0xa94584 <b2_toiTime+0x33b0e0> */
/* @0x2a9d62 uxth.w r10, r10 */
/* @0x2a9d64 bl 0x568794 <g_SWFlineaavertbuff+0x156cc> */
/* @0x2a9d66 add.w r10, r10, r10, lsr #8 */
/* @0x2a9d68 vshll.u8 q9, d10, #0x2 */
/* @0x2a9d6a ubfx r10, r10, #0x8, #0x8 */
/* @0x2a9d6c .word 0xf8152a07 */
/* @0x2a9d6e ldrb.w r10, [r5, r10] */
/* @0x2a9d70 ldcls p0, c10, [r0, #-40] */
/* @0x2a9d72 ldr r5, [sp, #0x40] */
/* @0x2a9d74 strb r10, [r12, #-3] */
/* @0x2a9d78 ldrh.w r10, [r5, #0x4] */
/* @0x2a9d7c ldrb.w r11, [r1, #0x1] */
/* @0x2a9d80 ldr r5, [sp, #0x48] */
/* @0x2a9d82 mul r10, r10, r8 */
/* @0x2a9d84 .word 0xf816fa08 */
/* @0x2a9d86 ldrb.w r11, [r6, r11] */
/* @0x2a9d88 .word 0xf10ab00b */
/* @0x2a9d8a add.w r10, r10, #0x80 */
/* @0x2a9d8c blx 0x56c796 <g_SWFlineaavertbuff+0x196ce> */
/* @0x2a9d8e mla r10, r11, r7, r10 */
/* @0x2a9d90 blx 0xa945b4 <b2_toiTime+0x33b110> */
/* @0x2a9d92 uxth.w r10, r10 */
/* @0x2a9d94 bl 0x5687c4 <g_SWFlineaavertbuff+0x156fc> */
/* @0x2a9d96 add.w r10, r10, r10, lsr #8 */
/* @0x2a9d98 vshll.u8 q9, d10, #0x2 */
/* @0x2a9d9a ubfx r10, r10, #0x8, #0x8 */
/* @0x2a9d9c .word 0xf8152a07 */
/* @0x2a9d9e ldrb.w r10, [r5, r10] */
/* @0x2a9da0 ldcls p0, c10, [r0, #-40] */
/* @0x2a9da2 ldr r5, [sp, #0x40] */
/* @0x2a9da4 strb.w r10, [r2, #0x1] */
/* @0x2a9da8 ldrh.w r10, [r5, #0x6] */
/* @0x2a9dac mul r8, r10, r8 */
/* @0x2a9db0 ldrb.w r10, [r1, #0x2] */
/* @0x2a9db4 ldrb.w r10, [r6, r10] */
/* @0x2a9db8 add.w r8, r8, #0x80 */
/* @0x2a9dbc mla r8, r10, r7, r8 */
/* @0x2a9dc0 ldr.w r10, [sp, #0x48] */
/* @0x2a9dc4 uxth.w r8, r8 */
/* @0x2a9dc8 add.w r8, r8, r8, lsr #8 */
/* @0x2a9dcc ubfx r8, r8, #0x8, #0x8 */
/* @0x2a9dd0 ldrb.w r7, [r10, r8] */
/* @0x2a9dd4 strb r7, [r2, #0x2] */
/* @0x2a9dd6 adds r1, #0x4 */
/* @0x2a9dd8 adds r2, #0x3 */
/* @0x2a9dda add.w r12, r12, #0x3 */
/* @0x2a9ddc ldr r0, [r6, r3, lsl #24] */
/* @0x2a9dde b 0x2a9d0e <png_do_background+0x68e> */
/* @0x2a9de0 ldrb r4, [r1, #0x3] */
/* @0x2a9de2 cmp r4, #0xff */
/* @0x2a9de4 bne 0x2a9e00 <png_do_background+0x780> */
/* @0x2a9de6 ldrb r4, [r1] */
/* @0x2a9de8 strb r4, [r5, #-3] */
/* @0x2a9dec ldrb r4, [r1, #0x1] */
/* @0x2a9dee strb r4, [r2, #0x1] */
/* @0x2a9df0 ldrb r4, [r1, #0x2] */
/* @0x2a9df2 strb r4, [r2, #0x2] */
/* @0x2a9df4 adds r1, #0x4 */
/* @0x2a9df6 adds r2, #0x3 */
/* @0x2a9df8 adds r5, #0x3 */
/* @0x2a9dfa cmp r2, r8 */
/* @0x2a9dfc bne 0x2a9de0 <png_do_background+0x760> */
/* @0x2a9dfe b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9e00 ldrh.w r12, [r3, #0x2] */
/* @0x2a9e04 cbnz r4, 0x2a9e12 <png_do_background+0x792> */
/* @0x2a9e06 strb r12, [r5, #-3] */
/* @0x2a9e08 ldmhi r12, {r0, r1, r10, r11, lr, pc} */
/* @0x2a9e0a ldrh r4, [r3, #0x4] */
/* @0x2a9e0c strb r4, [r2, #0x1] */
/* @0x2a9e0e ldrh r4, [r3, #0x6] */
/* @0x2a9e10 b 0x2a9df2 <png_do_background+0x772> */
/* @0x2a9e12 ldrb r7, [r1] */
/* @0x2a9e14 rsb.w r6, r4, #0xff */
/* @0x2a9e18 uxth r6, r6 */
/* @0x2a9e1a muls r7, r4, r7 */
/* @0x2a9e1c adds r7, #0x80 */
/* @0x2a9e1e mla r7, r6, r12, r7 */
/* @0x2a9e20 adcslt r7, pc, #12, #14 */
/* @0x2a9e22 uxth r7, r7 */
/* @0x2a9e24 add.w r7, r7, r7, lsr #8 */
/* @0x2a9e28 asrs r7, r7, #0x8 */
/* @0x2a9e2a strb r7, [r5, #-3] */
/* @0x2a9e2c stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^ */
/* @0x2a9e2e ldrb r7, [r1, #0x1] */
/* @0x2a9e30 ldrh.w r12, [r3, #0x4] */
/* @0x2a9e34 muls r7, r4, r7 */
/* @0x2a9e36 adds r7, #0x80 */
/* @0x2a9e38 mla r7, r6, r12, r7 */
/* @0x2a9e3c uxth r7, r7 */
/* @0x2a9e3e add.w r7, r7, r7, lsr #8 */
/* @0x2a9e40 eorsne r2, pc, #6029312 */
/* @0x2a9e42 asrs r7, r7, #0x8 */
/* @0x2a9e44 strb r7, [r2, #0x1] */
/* @0x2a9e46 ldrb r7, [r1, #0x2] */
/* @0x2a9e48 muls r4, r7, r4 */
/* @0x2a9e4a ldrh r7, [r3, #0x6] */
/* @0x2a9e4c adds r4, #0x80 */
/* @0x2a9e4e mla r6, r6, r7, r4 */
/* @0x2a9e50 adcslt r4, r6, #7340032 */
/* @0x2a9e52 uxth r6, r6 */
/* @0x2a9e54 add.w r6, r6, r6, lsr #8 */
/* @0x2a9e58 asrs r6, r6, #0x8 */
/* @0x2a9e5a strb r6, [r2, #0x2] */
/* @0x2a9e5c b 0x2a9df4 <png_do_background+0x774> */
/* @0x2a9e5e ldr r2, [sp, #0x50] */
/* @0x2a9e60 cbz r2, 0x2a9e68 <png_do_background+0x7e8> */
/* @0x2a9e62 cmp.w r10, #0x0 */
/* @0x2a9e64 .word 0xd1040f00 */
/* @0x2a9e66 bne 0x2a9e72 <png_do_background+0x7f2> */
/* @0x2a9e68 mov r2, r1 */
/* @0x2a9e6a movs r5, #0x0 */
/* @0x2a9e6c movw r12, #0xffff */
/* @0x2a9e70 b 0x2a9fec <png_do_background+0x96c> */
/* @0x2a9e72 cmp.w r9, #0x0 */
/* @0x2a9e74 rscsle r0, r7, r0, lsl #30 */
/* @0x2a9e76 beq 0x2a9e68 <png_do_background+0x7e8> */
/* @0x2a9e78 add.w r8, r1, #0x6 */
/* @0x2a9e7c mov r2, r1 */
/* @0x2a9e7e movs r4, #0x0 */
/* @0x2a9e80 str r4, [sp, #0x14] */
/* @0x2a9e82 ldr r4, [sp, #0x14] */
/* @0x2a9e84 cmp r4, r0 */
/* @0x2a9e86 beq.w 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9e88 stmibvc sp, {r1, r3, r8, pc} */
/* @0x2a9e8a ldrb r5, [r1, #0x6] */
/* @0x2a9e8c ldrb r4, [r1, #0x7] */
/* @0x2a9e8e add.w r4, r4, r5, lsl #8 */
/* @0x2a9e90 .word 0xf64f2405 */
/* @0x2a9e92 movw r5, #0xffff */
/* @0x2a9e94 adclt r7, r4, #1069547520 */
/* @0x2a9e96 uxth r4, r4 */
/* @0x2a9e98 cmp r4, r5 */
/* @0x2a9e9a bne 0x2a9ede <png_do_background+0x85e> */
/* @0x2a9e9c ldrb r4, [r1, #0x1] */
/* @0x2a9e9e ldr r6, [sp, #0x50] */
/* @0x2a9ea0 ldrb r5, [r1] */
/* @0x2a9ea2 asr.w r4, r4, r11 */
/* @0x2a9ea4 .word 0xf856f40b */
/* @0x2a9ea6 ldr.w r4, [r6, r4, lsl #2] */
/* @0x2a9ea8 rfeda r4! */
/* @0x2a9eaa ldrh.w r4, [r4, r5, lsl #1] */
/* @0x2a9eac beq 0xbf9f08 <b2_toiTime+0x4a0a64> */
/* @0x2a9eae lsrs r5, r4, #0x8 */
/* @0x2a9eb0 strb r5, [r8, #-6] */
/* @0x2a9eb4 strb r4, [r2, #0x1] */
/* @0x2a9eb6 ldrb r4, [r1, #0x3] */
/* @0x2a9eb8 ldrb r5, [r1, #0x2] */
/* @0x2a9eba asr.w r4, r4, r11 */
/* @0x2a9ebc .word 0xf856f40b */
/* @0x2a9ebe ldr.w r4, [r6, r4, lsl #2] */
/* @0x2a9ec0 rfeda r4! */
/* @0x2a9ec2 ldrh.w r4, [r4, r5, lsl #1] */
/* @0x2a9ec4 sbcsvc r4, r4, r5, lsl r0 */
/* @0x2a9ec6 strb r4, [r2, #0x3] */
/* @0x2a9ec8 lsrs r5, r4, #0x8 */
/* @0x2a9eca strb r5, [r2, #0x2] */
/* @0x2a9ecc ldrb r4, [r1, #0x5] */
/* @0x2a9ece ldrb r5, [r1, #0x4] */
/* @0x2a9ed0 asr.w r4, r4, r11 */
/* @0x2a9ed4 ldr.w r4, [r6, r4, lsl #2] */
/* @0x2a9ed8 ldrh.w r4, [r4, r5, lsl #1] */
/* @0x2a9edc b 0x2a9fb4 <png_do_background+0x934> */
/* @0x2a9ede cbnz r4, 0x2a9f00 <png_do_background+0x880> */
/* @0x2a9ee0 ldrh r4, [r3, #0x2] */
/* @0x2a9ee2 lsrs r4, r4, #0x8 */
/* @0x2a9ee4 strb r4, [r8, #-6] */
/* @0x2a9ee8 ldrh r4, [r3, #0x2] */
/* @0x2a9eea strb r4, [r2, #0x1] */
/* @0x2a9eec ldrh r4, [r3, #0x4] */
/* @0x2a9eee lsrs r4, r4, #0x8 */
/* @0x2a9ef0 strb r4, [r2, #0x2] */
/* @0x2a9ef2 ldrh r4, [r3, #0x4] */
/* @0x2a9ef4 strb r4, [r2, #0x3] */
/* @0x2a9ef6 ldrh r4, [r3, #0x6] */
/* @0x2a9ef8 lsrs r4, r4, #0x8 */
/* @0x2a9efa strb r4, [r2, #0x4] */
/* @0x2a9efc ldrh r4, [r3, #0x6] */
/* @0x2a9efe b 0x2a9fb8 <png_do_background+0x938> */
/* @0x2a9f00 ldr r7, [sp, #0x40] */
/* @0x2a9f02 rsb.w r5, r4, #0xff00 */
/* @0x2a9f04 ldrblo r4, [pc, #0x57f]! */
/* @0x2a9f06 adds r5, #0xff */
/* @0x2a9f08 ldrb.w r12, [r1] */
/* @0x2a9f0c ldrh r6, [r7, #0x2] */
/* @0x2a9f0e ldrb r7, [r1, #0x1] */
/* @0x2a9f10 muls r6, r5, r6 */
/* @0x2a9f12 asr.w r7, r7, r11 */
/* @0x2a9f14 .word 0xf859f70b */
/* @0x2a9f16 ldr.w r7, [r9, r7, lsl #2] */
/* @0x2a9f18 .word 0xf5067027 */
/* @0x2a9f1a add.w r6, r6, #0x8000 */
/* @0x2a9f1c rfeda r7! */
/* @0x2a9f1e ldrh.w r7, [r7, r12, lsl #1] */
/* @0x2a9f20 blx 0x3c5f9a <error_g0017+0x1ec3e> */
/* @0x2a9f22 mla r6, r4, r7, r6 */
/* @0x2a9f24 bl 0x443748 <g_RomDisk+0x4bf28> */
/* @0x2a9f26 add.w r6, r6, r6, lsr #16 */
/* @0x2a9f28 ldceq p6, c4, [r6], #-88 */
/* @0x2a9f2a lsrs r6, r6, #0x10 */
/* @0x2a9f2c uxtb r7, r6 */
/* @0x2a9f2e lsrs r6, r6, #0x8 */
/* @0x2a9f30 asr.w r7, r7, r11 */
/* @0x2a9f34 ldr.w r7, [r10, r7, lsl #2] */
/* @0x2a9f38 ldrh.w r6, [r7, r6, lsl #1] */
/* @0x2a9f3c lsrs r7, r6, #0x8 */
/* @0x2a9f3e strb r7, [r8, #-6] */
/* @0x2a9f40 svcls #0x107c06 */
/* @0x2a9f42 ldr r7, [sp, #0x40] */
/* @0x2a9f44 strb r6, [r2, #0x1] */
/* @0x2a9f46 ldrb.w r12, [r1, #0x2] */
/* @0x2a9f48 ldmhi lr!, {r1, lr, pc} */
/* @0x2a9f4a ldrh r6, [r7, #0x4] */
/* @0x2a9f4c ldrb r7, [r1, #0x3] */
/* @0x2a9f4e muls r6, r5, r6 */
/* @0x2a9f50 asr.w r7, r7, r11 */
/* @0x2a9f54 ldr.w r7, [r9, r7, lsl #2] */
/* @0x2a9f58 add.w r6, r6, #0x8000 */
/* @0x2a9f5c ldrh.w r7, [r7, r12, lsl #1] */
/* @0x2a9f60 mla r6, r4, r7, r6 */
/* @0x2a9f64 add.w r6, r6, r6, lsr #16 */
/* @0x2a9f68 lsrs r6, r6, #0x10 */
/* @0x2a9f6a uxtb r7, r6 */
/* @0x2a9f6c lsrs r6, r6, #0x8 */
/* @0x2a9f6e asr.w r7, r7, r11 */
/* @0x2a9f70 .word 0xf85af70b */
/* @0x2a9f72 ldr.w r7, [r10, r7, lsl #2] */
/* @0x2a9f74 rfeda r7! */
/* @0x2a9f76 ldrh.w r6, [r7, r6, lsl #1] */
/* @0x2a9f78 beq 0x1081fd8 <b2_toiTime+0x928b34> */
/* @0x2a9f7a lsrs r7, r6, #0x8 */
/* @0x2a9f7c strb r7, [r2, #0x2] */
/* @0x2a9f7e ldr r7, [sp, #0x40] */
/* @0x2a9f80 strb r6, [r2, #0x3] */
/* @0x2a9f82 ldrh r6, [r7, #0x6] */
/* @0x2a9f84 ldrb r7, [r1, #0x4] */
/* @0x2a9f86 muls r5, r6, r5 */
/* @0x2a9f88 ldrb r6, [r1, #0x5] */
/* @0x2a9f8a asr.w r6, r6, r11 */
/* @0x2a9f8c .word 0xf505f60b */
/* @0x2a9f8e add.w r5, r5, #0x8000 */
/* @0x2a9f90 .word 0xf8594500 */
/* @0x2a9f92 ldr.w r6, [r9, r6, lsl #2] */
/* @0x2a9f94 rfeda r6! */
/* @0x2a9f96 ldrh.w r6, [r6, r7, lsl #1] */
/* @0x2a9f98 blx 0x3c1ffe <error_g0017+0x1aca2> */
/* @0x2a9f9a mla r4, r4, r6, r5 */
/* @0x2a9f9c bl 0x3befbc <error_g0017+0x17c60> */
/* @0x2a9f9e add.w r4, r4, r4, lsr #16 */
/* @0x2a9fa0 stceq p4, c4, [r4], #-80 */
/* @0x2a9fa2 lsrs r4, r4, #0x10 */
/* @0x2a9fa4 uxtb r7, r4 */
/* @0x2a9fa6 lsrs r4, r4, #0x8 */
/* @0x2a9fa8 asr.w r7, r7, r11 */
/* @0x2a9fac ldr.w r5, [r10, r7, lsl #2] */
/* @0x2a9fb0 ldrh.w r4, [r5, r4, lsl #1] */
/* @0x2a9fb4 lsrs r5, r4, #0x8 */
/* @0x2a9fb6 strb r5, [r2, #0x4] */
/* @0x2a9fb8 ldr.w r12, [sp, #0x14] */
/* @0x2a9fbc adds r1, #0x8 */
/* @0x2a9fbe strb r4, [r2, #0x5] */
/* @0x2a9fc0 add.w r8, r8, #0x6 */
/* @0x2a9fc4 add.w r12, r12, #0x1 */
/* @0x2a9fc8 adds r2, #0x6 */
/* @0x2a9fca str.w r12, [sp, #0x14] */
/* @0x2a9fcc smmla r8, r4, r0, r12 */
/* @0x2a9fce b 0x2a9e82 <png_do_background+0x802> */
/* @0x2a9fd0 ldrb r6, [r1, #0x6] */
/* @0x2a9fd2 ldrb r4, [r1, #0x7] */
/* @0x2a9fd4 add.w r4, r4, r6, lsl #8 */
/* @0x2a9fd8 uxth r4, r4 */
/* @0x2a9fda cmp r4, r12 */
/* @0x2a9fdc bne 0x2a9ff2 <png_do_background+0x972> */
/* @0x2a9fde ldr r4, [r1] */
/* @0x2a9fe0 str r4, [r2] */
/* @0x2a9fe2 ldrh r4, [r1, #0x4] */
/* @0x2a9fe4 strh r4, [r2, #0x4] */
/* @0x2a9fe6 adds r5, #0x1 */
/* @0x2a9fe8 adds r1, #0x8 */
/* @0x2a9fea adds r2, #0x6 */
/* @0x2a9fec cmp r5, r0 */
/* @0x2a9fee bne 0x2a9fd0 <png_do_background+0x950> */
/* @0x2a9ff0 b 0x2aa09e <png_do_background+0xa1e> */
/* @0x2a9ff2 ldrh r7, [r3, #0x2] */
/* @0x2a9ff4 cbnz r4, 0x2aa014 <png_do_background+0x994> */
/* @0x2a9ff6 lsrs r7, r7, #0x8 */
/* @0x2a9ff8 strb r7, [r2] */
/* @0x2a9ffa ldrh r4, [r3, #0x2] */
/* @0x2a9ffc strb r4, [r2, #0x1] */
/* @0x2a9ffe ldrh r4, [r3, #0x4] */
/* @0x2aa000 lsrs r4, r4, #0x8 */
/* @0x2aa002 strb r4, [r2, #0x2] */
/* @0x2aa004 ldrh r4, [r3, #0x4] */
/* @0x2aa006 strb r4, [r2, #0x3] */
/* @0x2aa008 ldrh r4, [r3, #0x6] */
/* @0x2aa00a lsrs r4, r4, #0x8 */
/* @0x2aa00c strb r4, [r2, #0x4] */
/* @0x2aa00e ldrh r4, [r3, #0x6] */
/* @0x2aa010 strb r4, [r2, #0x5] */
/* @0x2aa012 b 0x2a9fe6 <png_do_background+0x966> */
/* @0x2aa014 ldrb.w r11, [r1] */
/* @0x2aa018 ldrb.w r10, [r1, #0x1] */
/* @0x2aa01c ldrb.w r9, [r1, #0x2] */
/* @0x2aa020 add.w r10, r10, r11, lsl #8 */
/* @0x2aa024 ldrb r6, [r1, #0x3] */
/* @0x2aa026 ldrb.w r8, [r1, #0x4] */
/* @0x2aa028 blx 0xa8a040 <b2_toiTime+0x330b9c> */
/* @0x2aa02a uxth.w r10, r10 */
/* @0x2aa02c bl 0x468a5c <g_RomDisk+0x7123c> */
/* @0x2aa02e add.w r9, r6, r9, lsl #8 */
/* @0x2aa030 stmdbvc lr, {r0, r3, r8, r11, sp} ^ */
/* @0x2aa032 ldrb r6, [r1, #0x5] */
/* @0x2aa034 mul r10, r10, r4 */
/* @0x2aa038 add.w r8, r6, r8, lsl #8 */
/* @0x2aa03c rsb.w r6, r4, #0xff00 */
/* @0x2aa040 uxth.w r9, r9 */
/* @0x2aa044 adds r6, #0xff */
/* @0x2aa046 uxth.w r8, r8 */
/* @0x2aa048 .word 0xf50af888 */
/* @0x2aa04a add.w r10, r10, #0x8000 */
/* @0x2aa04c blx 0x3bc856 <error_g0017+0x154fa> */
/* @0x2aa04e mul r9, r4, r9 */
/* @0x2aa050 blx 0x4a847e <SrcVerts+0x54c2> */
/* @0x2aa052 mla r7, r7, r6, r10 */
/* @0x2aa054 .word 0xf509a706 */
/* @0x2aa056 add.w r9, r9, #0x8000 */
/* @0x2aa058 blx 0x3bc462 <error_g0017+0x15106> */
/* @0x2aa05a mul r4, r4, r8 */
/* @0x2aa05c bl 0x4a7084 <SrcVerts+0x40c8> */
/* @0x2aa05e add.w r7, r7, r7, lsr #16 */
/* @0x2aa060 .word 0xf5044717 */
/* @0x2aa062 add.w r4, r4, #0x8000 */
/* @0x2aa064 ldceq p4, c4, [pc], #-0 */
/* @0x2aa066 lsrs r7, r7, #0x10 */
/* @0x2aa068 strb r7, [r2, #0x1] */
/* @0x2aa06a lsr.w r10, r7, #0x8 */
/* @0x2aa06c .word 0xf8822a17 */
/* @0x2aa06e strb.w r10, [r2] */
/* @0x2aa070 ldmhi pc, {sp, pc} */
/* @0x2aa072 ldrh r7, [r3, #0x4] */
/* @0x2aa074 mla r7, r7, r6, r9 */
/* @0x2aa078 add.w r7, r7, r7, lsr #16 */
/* @0x2aa07c lsrs r7, r7, #0x10 */
/* @0x2aa07e strb r7, [r2, #0x3] */
/* @0x2aa080 lsr.w r9, r7, #0x8 */
/* @0x2aa084 strb.w r9, [r2, #0x2] */
/* @0x2aa088 ldrh.w r8, [r3, #0x6] */
/* @0x2aa08c mla r6, r8, r6, r4 */
/* @0x2aa090 add.w r6, r6, r6, lsr #16 */
/* @0x2aa094 lsrs r6, r6, #0x10 */
/* @0x2aa096 strb r6, [r2, #0x5] */
/* @0x2aa098 lsrs r4, r6, #0x8 */
/* @0x2aa09a strb r4, [r2, #0x4] */
/* @0x2aa09c b 0x2a9fe6 <png_do_background+0x966> */
/* @0x2aa09e ldr r5, [sp, #0xc] */
/* @0x2aa0a0 ldrb r3, [r5, #0x8] */
/* @0x2aa0a2 lsls r2, r3, #0x1d */
/* @0x2aa0a4 bpl 0x2aa0d0 <png_do_background+0xa50> */
/* @0x2aa0a6 bic r3, r3, #0x4 */
/* @0x2aa0a8 eorvc r0, r11, #4, #6 */
/* @0x2aa0aa strb r3, [r5, #0x8] */
/* @0x2aa0ac ldrb r3, [r5, #0xa] */
/* @0x2aa0ae ldrb r2, [r5, #0x9] */
/* @0x2aa0b0 subs r3, #0x1 */
/* @0x2aa0b2 uxtb r3, r3 */
/* @0x2aa0b4 strb r3, [r5, #0xa] */
/* @0x2aa0b6 muls r3, r2, r3 */
/* @0x2aa0b8 uxtb r3, r3 */
/* @0x2aa0ba strb r3, [r5, #0xb] */
/* @0x2aa0bc cmp r3, #0x7 */
/* @0x2aa0be bls 0x2aa0c6 <png_do_background+0xa46> */
/* @0x2aa0c0 lsrs r3, r3, #0x3 */
/* @0x2aa0c2 muls r0, r3, r0 */
/* @0x2aa0c4 b 0x2aa0cc <png_do_background+0xa4c> */
/* @0x2aa0c6 muls r0, r3, r0 */
/* @0x2aa0c8 adds r0, #0x7 */
/* @0x2aa0ca lsrs r0, r0, #0x3 */
/* @0x2aa0cc ldr r6, [sp, #0xc] */
/* @0x2aa0ce str r0, [r6, #0x4] */
/* @0x2aa0d0 add sp, #0x1c */
/* @0x2aa0d2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa0d4 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2aa0d6 · png_do_gamma · size=706 · insn=283 */
/* @0x2aa0d6 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aa0da ldrb r6, [r0, #0x9] */
/* @0x2aa0dc ldr r5, [sp, #0x24] */
/* @0x2aa0de cmp r6, #0x8 */
/* @0x2aa0e0 ldr r4, [r0] */
/* @0x2aa0e2 bhi 0x2aa0ea <png_do_gamma+0x14> */
/* @0x2aa0e4 cbnz r2, 0x2aa0f6 <png_do_gamma+0x20> */
/* @0x2aa0e6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa0ea cmp r6, #0x10 */
/* @0x2aa0ec bne.w 0x2aa394 <png_do_gamma+0x2be> */
/* @0x2aa0ee blhs 0x2ca63e <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb8a> */
/* @0x2aa0f0 cmp r3, #0x0 */
/* @0x2aa0f2 beq.w 0x2aa394 <png_do_gamma+0x2be> */
/* @0x2aa0f6 ldrb r7, [r0, #0x8] */
/* @0x2aa0f8 cmp r7, #0x6 */
/* @0x2aa0fa bhi.w 0x2aa394 <png_do_gamma+0x2be> */
/* @0x2aa0fe tbh [pc, r7, lsl #1] */
/* @0x2aa102 lsls r2, r0, #0x3 */
/* @0x2aa104 lsls r1, r1, #0x5 */
/* @0x2aa106 movs r7, r0 */
/* @0x2aa108 lsls r1, r1, #0x5 */
/* @0x2aa10a lsls r2, r3, #0x2 */
/* @0x2aa10c lsls r1, r1, #0x5 */
/* @0x2aa10e lsls r1, r2, #0x1 */
/* @0x2aa110 cmp r6, #0x8 */
/* @0x2aa112 beq 0x2aa118 <png_do_gamma+0x42> */
/* @0x2aa114 movs r2, #0x0 */
/* @0x2aa116 b 0x2aa146 <png_do_gamma+0x70> */
/* @0x2aa118 movs r3, #0x3 */
/* @0x2aa11a mla r4, r3, r4, r1 */
/* @0x2aa11e cmp r1, r4 */
/* @0x2aa120 beq 0x2aa142 <png_do_gamma+0x6c> */
/* @0x2aa122 ldrb r3, [r1] */
/* @0x2aa124 adds r1, #0x3 */
/* @0x2aa126 ldrb r3, [r2, r3] */
/* @0x2aa128 strb r3, [r1, #-3] */
/* @0x2aa12a .word 0xf8113c03 */
/* @0x2aa12c ldrb r3, [r1, #-2] */
/* @0x2aa12e ldclpl p12, c3, [r3], {2} */
/* @0x2aa130 ldrb r3, [r2, r3] */
/* @0x2aa132 strb r3, [r1, #-2] */
/* @0x2aa136 ldrb r3, [r1, #-1] */
/* @0x2aa13a ldrb r3, [r2, r3] */
/* @0x2aa13c strb r3, [r1, #-1] */
/* @0x2aa13e strb r3, [sp, r1, lsl #24]! */
/* @0x2aa140 b 0x2aa11e <png_do_gamma+0x48> */
/* @0x2aa142 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa146 cmp r2, r4 */
/* @0x2aa148 beq 0x2aa1a0 <png_do_gamma+0xca> */
/* @0x2aa14a ldrb r0, [r1, #0x1] */
/* @0x2aa14c adds r2, #0x1 */
/* @0x2aa14e ldrb r6, [r1] */
/* @0x2aa150 adds r1, #0x6 */
/* @0x2aa152 asrs r0, r5 */
/* @0x2aa154 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa156 rfeda r0! */
/* @0x2aa158 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa15a .word 0xf8010016 */
/* @0x2aa15c strb r0, [r1, #-5] */
/* @0x2aa15e beq 0x42d17a <g_RomDisk+0x3595a> */
/* @0x2aa160 lsrs r6, r0, #0x8 */
/* @0x2aa162 ldrb r0, [r1, #-3] */
/* @0x2aa166 strb r6, [r1, #-6] */
/* @0x2aa16a ldrb r6, [r1, #-4] */
/* @0x2aa16e asrs r0, r5 */
/* @0x2aa170 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa172 rfeda r0! */
/* @0x2aa174 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa176 .word 0xf8010016 */
/* @0x2aa178 strb r0, [r1, #-3] */
/* @0x2aa17a beq 0x42d18e <g_RomDisk+0x3596e> */
/* @0x2aa17c lsrs r6, r0, #0x8 */
/* @0x2aa17e ldrb r0, [r1, #-1] */
/* @0x2aa182 strb r6, [r1, #-4] */
/* @0x2aa186 ldrb r6, [r1, #-2] */
/* @0x2aa18a asrs r0, r5 */
/* @0x2aa18c ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa18e rfeda r0! */
/* @0x2aa190 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa192 beq 0x42a1f2 <g_RomDisk+0x329d2> */
/* @0x2aa194 lsrs r6, r0, #0x8 */
/* @0x2aa196 strb r0, [r1, #-1] */
/* @0x2aa19a strb r6, [r1, #-2] */
/* @0x2aa19e b 0x2aa146 <png_do_gamma+0x70> */
/* @0x2aa1a0 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa1a2 mcrhs p15, #0x0, r8, c8, c0, #0x7 */
/* @0x2aa1a4 cmp r6, #0x8 */
/* @0x2aa1a6 beq 0x2aa1ac <png_do_gamma+0xd6> */
/* @0x2aa1a8 movs r2, #0x0 */
/* @0x2aa1aa b 0x2aa1d8 <png_do_gamma+0x102> */
/* @0x2aa1ac movs r3, #0x0 */
/* @0x2aa1ae cmp r3, r4 */
/* @0x2aa1b0 beq 0x2aa1d4 <png_do_gamma+0xfe> */
/* @0x2aa1b2 ldrb r0, [r1] */
/* @0x2aa1b4 adds r3, #0x1 */
/* @0x2aa1b6 adds r1, #0x4 */
/* @0x2aa1b8 ldrb r0, [r2, r0] */
/* @0x2aa1ba strb r0, [r1, #-4] */
/* @0x2aa1be ldrb r0, [r1, #-3] */
/* @0x2aa1c2 ldrb r0, [r2, r0] */
/* @0x2aa1c4 strb r0, [r1, #-3] */
/* @0x2aa1c6 .word 0xf8110c03 */
/* @0x2aa1c8 ldrb r0, [r1, #-2] */
/* @0x2aa1ca .word 0x5c100c02 */
/* @0x2aa1cc ldrb r0, [r2, r0] */
/* @0x2aa1ce strb r0, [r1, #-2] */
/* @0x2aa1d2 b 0x2aa1ae <png_do_gamma+0xd8> */
/* @0x2aa1d4 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa1d6 adcmi r8, r2, #240, #30 */
/* @0x2aa1d8 cmp r2, r4 */
/* @0x2aa1da beq 0x2aa232 <png_do_gamma+0x15c> */
/* @0x2aa1dc ldrb r0, [r1, #0x1] */
/* @0x2aa1de adds r2, #0x1 */
/* @0x2aa1e0 ldrb r6, [r1] */
/* @0x2aa1e2 adds r1, #0x8 */
/* @0x2aa1e4 asrs r0, r5 */
/* @0x2aa1e6 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa1ea ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa1ee strb r0, [r1, #-7] */
/* @0x2aa1f2 lsrs r6, r0, #0x8 */
/* @0x2aa1f4 ldrb r0, [r1, #-5] */
/* @0x2aa1f6 .word 0xf8010c05 */
/* @0x2aa1f8 strb r6, [r1, #-8] */
/* @0x2aa1fa .word 0xf8116c08 */
/* @0x2aa1fc ldrb r6, [r1, #-6] */
/* @0x2aa1fe .word 0x41286c06 */
/* @0x2aa200 asrs r0, r5 */
/* @0x2aa202 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa206 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa20a strb r0, [r1, #-5] */
/* @0x2aa20e lsrs r6, r0, #0x8 */
/* @0x2aa210 ldrb r0, [r1, #-3] */
/* @0x2aa212 .word 0xf8010c03 */
/* @0x2aa214 strb r6, [r1, #-6] */
/* @0x2aa216 .word 0xf8116c06 */
/* @0x2aa218 ldrb r6, [r1, #-4] */
/* @0x2aa21a .word 0x41286c04 */
/* @0x2aa21c asrs r0, r5 */
/* @0x2aa21e ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa222 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa226 lsrs r6, r0, #0x8 */
/* @0x2aa228 strb r0, [r1, #-3] */
/* @0x2aa22a .word 0xf8010c03 */
/* @0x2aa22c strb r6, [r1, #-4] */
/* @0x2aa22e ldrb r6, [r2, r4, lsl #24] */
/* @0x2aa230 b 0x2aa1d8 <png_do_gamma+0x102> */
/* @0x2aa232 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa236 cmp r6, #0x8 */
/* @0x2aa238 beq 0x2aa23e <png_do_gamma+0x168> */
/* @0x2aa23a movs r2, #0x0 */
/* @0x2aa23c b 0x2aa25a <png_do_gamma+0x184> */
/* @0x2aa23e movs r3, #0x0 */
/* @0x2aa240 cmp r3, r4 */
/* @0x2aa242 add.w r1, r1, #0x2 */
/* @0x2aa246 beq 0x2aa256 <png_do_gamma+0x180> */
/* @0x2aa248 ldrb r0, [r1, #-2] */
/* @0x2aa24a movwlo r0, #0x1c02 */
/* @0x2aa24c adds r3, #0x1 */
/* @0x2aa24e ldrb r0, [r2, r0] */
/* @0x2aa250 strb r0, [r1, #-2] */
/* @0x2aa252 ldrb r0, [r4, r2, lsl #24]! */
/* @0x2aa254 b 0x2aa240 <png_do_gamma+0x16a> */
/* @0x2aa256 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa25a cmp r2, r4 */
/* @0x2aa25c add.w r1, r1, #0x4 */
/* @0x2aa25e andle r0, pc, r4, lsl #2 */
/* @0x2aa260 beq 0x2aa282 <png_do_gamma+0x1ac> */
/* @0x2aa262 ldrb r0, [r1, #-3] */
/* @0x2aa266 adds r2, #0x1 */
/* @0x2aa268 ldrb r6, [r1, #-4] */
/* @0x2aa26a .word 0x41286c04 */
/* @0x2aa26c asrs r0, r5 */
/* @0x2aa26e ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa272 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa276 lsrs r6, r0, #0x8 */
/* @0x2aa278 strb r0, [r1, #-3] */
/* @0x2aa27a .word 0xf8010c03 */
/* @0x2aa27c strb r6, [r1, #-4] */
/* @0x2aa27e strb r6, [r11, r4, lsl #24]! */
/* @0x2aa280 b 0x2aa25a <png_do_gamma+0x184> */
/* @0x2aa282 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa286 cmp r6, #0x2 */
/* @0x2aa288 beq 0x2aa294 <png_do_gamma+0x1be> */
/* @0x2aa28a ldrb r0, [r0, #0x9] */
/* @0x2aa28c cmp r0, #0x4 */
/* @0x2aa28e bne 0x2aa34e <png_do_gamma+0x278> */
/* @0x2aa290 movs r3, #0x0 */
/* @0x2aa292 b 0x2aa320 <png_do_gamma+0x24a> */
/* @0x2aa294 mov r10, r1 */
/* @0x2aa296 mov.w r9, #0x0 */
/* @0x2aa29a cmp r9, r4 */
/* @0x2aa29c bhs 0x2aa28a <png_do_gamma+0x1b4> */
/* @0x2aa29e ldrb.w r8, [r10] */
/* @0x2aa2a2 add.w r9, r9, #0x4 */
/* @0x2aa2a6 and r12, r8, #0xc0 */
/* @0x2aa2aa and r7, r8, #0x30 */
/* @0x2aa2ae and r6, r8, #0xc */
/* @0x2aa2b2 and r8, r8, #0x3 */
/* @0x2aa2b6 lsl.w r11, r8, #0x4 */
/* @0x2aa2ba orr.w r11, r11, r8, lsl #6 */
/* @0x2aa2be orr.w r11, r11, r8 */
/* @0x2aa2c2 orr.w r8, r11, r8, lsl #2 */
/* @0x2aa2c6 asr.w r11, r12, #0x4 */
/* @0x2aa2ca orr.w r11, r11, r12, lsr #2 */
/* @0x2aa2ce orr.w r11, r11, r12 */
/* @0x2aa2d2 ldrb.w r8, [r2, r8] */
/* @0x2aa2d6 orr.w r12, r11, r12, lsr #6 */
/* @0x2aa2da ldrb.w r12, [r2, r12] */
/* @0x2aa2de bic r12, r12, #0x3f */
/* @0x2aa2e2 orr.w r12, r12, r8, lsr #6 */
/* @0x2aa2e6 asr.w r8, r7, #0x2 */
/* @0x2aa2ea orr.w r8, r8, r7, lsl #2 */
/* @0x2aa2ee orr.w r8, r8, r7 */
/* @0x2aa2f2 orr.w r7, r8, r7, lsr #4 */
/* @0x2aa2f6 ldrb r7, [r2, r7] */
/* @0x2aa2f8 lsrs r7, r7, #0x2 */
/* @0x2aa2fa and r7, r7, #0x30 */
/* @0x2aa2fe orr.w r12, r12, r7 */
/* @0x2aa302 lsls r7, r6, #0x2 */
/* @0x2aa304 orr.w r7, r7, r6, lsl #4 */
/* @0x2aa306 teqmi r7, #1572864 */
/* @0x2aa308 orrs r7, r6 */
/* @0x2aa30a orr.w r6, r7, r6, lsr #2 */
/* @0x2aa30e ldrb r7, [r2, r6] */
/* @0x2aa310 lsrs r7, r7, #0x4 */
/* @0x2aa312 and r7, r7, #0xc */
/* @0x2aa316 orr.w r6, r12, r7 */
/* @0x2aa31a strb r6, [r10], #1 */
/* @0x2aa31e b 0x2aa29a <png_do_gamma+0x1c4> */
/* @0x2aa320 cmp r3, r4 */
/* @0x2aa322 bhs 0x2aa34a <png_do_gamma+0x274> */
/* @0x2aa324 ldrb r5, [r1] */
/* @0x2aa326 adds r3, #0x2 */
/* @0x2aa328 and r0, r5, #0xf0 */
/* @0x2aa32a .word 0xf00500f0 */
/* @0x2aa32c and r5, r5, #0xf */
/* @0x2aa32e b 0x12ab772 <b2_toiTime+0xb522ce> */
/* @0x2aa330 orr.w r0, r0, r0, lsr #4 */
/* @0x2aa332 b 0x13ee37a <b2_toiTime+0xc94ed6> */
/* @0x2aa334 orr.w r5, r5, r5, lsl #4 */
/* @0x2aa336 .word 0x5c101505 */
/* @0x2aa338 ldrb r0, [r2, r0] */
/* @0x2aa33a ldrb r5, [r2, r5] */
/* @0x2aa33c bic r0, r0, #0xf */
/* @0x2aa33e b 0x12aa382 <b2_toiTime+0xb50ede> */
/* @0x2aa340 orr.w r0, r0, r5, lsr #4 */
/* @0x2aa342 .word 0xf8011015 */
/* @0x2aa344 strb r0, [r1], #1 */
/* @0x2aa346 strb r0, [r10, r1, lsl #22]! */
/* @0x2aa348 b 0x2aa320 <png_do_gamma+0x24a> */
/* @0x2aa34a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa34e cmp r0, #0x8 */
/* @0x2aa350 bne 0x2aa366 <png_do_gamma+0x290> */
/* @0x2aa352 add r4, r1 */
/* @0x2aa354 cmp r1, r4 */
/* @0x2aa356 beq 0x2aa362 <png_do_gamma+0x28c> */
/* @0x2aa358 ldrb r3, [r1] */
/* @0x2aa35a ldrb r3, [r2, r3] */
/* @0x2aa35c strb r3, [r1], #1 */
/* @0x2aa35e ldrb r3, [r8, r1, lsl #22]! */
/* @0x2aa360 b 0x2aa354 <png_do_gamma+0x27e> */
/* @0x2aa362 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa366 cmp r0, #0x10 */
/* @0x2aa368 bne 0x2aa394 <png_do_gamma+0x2be> */
/* @0x2aa36a movs r2, #0x0 */
/* @0x2aa36c cmp r2, r4 */
/* @0x2aa36e add.w r1, r1, #0x2 */
/* @0x2aa372 beq 0x2aa394 <png_do_gamma+0x2be> */
/* @0x2aa374 ldrb r0, [r1, #-1] */
/* @0x2aa376 andlo r0, r1, #256 */
/* @0x2aa378 adds r2, #0x1 */
/* @0x2aa37a ldrb r6, [r1, #-2] */
/* @0x2aa37e asrs r0, r5 */
/* @0x2aa380 ldr.w r0, [r3, r0, lsl #2] */
/* @0x2aa382 rfeda r0! */
/* @0x2aa384 ldrh.w r0, [r0, r6, lsl #1] */
/* @0x2aa386 beq 0x42a3e6 <g_RomDisk+0x32bc6> */
/* @0x2aa388 lsrs r6, r0, #0x8 */
/* @0x2aa38a strb r0, [r1, #-1] */
/* @0x2aa38e strb r6, [r1, #-2] */
/* @0x2aa392 b 0x2aa36c <png_do_gamma+0x296> */
/* @0x2aa394 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2aa396 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2aa398 · png_do_expand_palette · size=420 · insn=193 */
/* @0x2aa398 push.w {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2aa39c ldrb r5, [r0, #0x8] */
/* @0x2aa39e ldr r4, [r0] */
/* @0x2aa3a0 cmp r5, #0x3 */
/* @0x2aa3a2 bne.w 0x2aa538 <png_do_expand_palette+0x1a0> */
/* @0x2aa3a4 .word 0xf89080c9 */
/* @0x2aa3a6 ldrb.w r12, [r0, #0x9] */
/* @0x2aa3a8 .word 0xf1bcc009 */
/* @0x2aa3aa cmp.w r12, #0x7 */
/* @0x2aa3ac stmdale r9!, {r0, r1, r2, r8, r9, r10, r11} ^ */
/* @0x2aa3ae bhi 0x2aa484 <png_do_expand_palette+0xec> */
/* @0x2aa3b0 cmp.w r12, #0x2 */
/* @0x2aa3b4 beq 0x2aa408 <png_do_expand_palette+0x70> */
/* @0x2aa3b6 cmp.w r12, #0x4 */
/* @0x2aa3b8 suble r0, r3, r4, lsl #30 */
/* @0x2aa3ba beq 0x2aa444 <png_do_expand_palette+0xac> */
/* @0x2aa3bc cmp.w r12, #0x1 */
/* @0x2aa3c0 bne 0x2aa47c <png_do_expand_palette+0xe4> */
/* @0x2aa3c2 add.w r9, r4, #0xffffffff */
/* @0x2aa3c4 stclne p9, c3, [r7, #1020]! */
/* @0x2aa3c6 adds r7, r4, #0x7 */
/* @0x2aa3c8 mvn.w r10, r4 */
/* @0x2aa3cc add.w r6, r1, r9, lsr #3 */
/* @0x2aa3d0 add r9, r1 */
/* @0x2aa3d2 mvns r7, r7 */
/* @0x2aa3d4 add.w r5, r9, #0xffffffff */
/* @0x2aa3d8 and r7, r7, #0x7 */
/* @0x2aa3dc add r10, r9 */
/* @0x2aa3de cmp r5, r10 */
/* @0x2aa3e0 beq 0x2aa47c <png_do_expand_palette+0xe4> */
/* @0x2aa3e2 ldrb.w r9, [r6] */
/* @0x2aa3e4 stclo p0, c9, [r1, #-0] */
/* @0x2aa3e6 subs r5, #0x1 */
/* @0x2aa3e8 asr.w r9, r9, r7 */
/* @0x2aa3ec ands r9, r9, #0x1 */
/* @0x2aa3f0 ite ne */
/* @0x2aa3f2 strbne.w r12, [r5, #0x2] */
/* @0x2aa3f4 .word 0xf885c002 */
/* @0x2aa3f6 strbeq.w r9, [r5, #0x2] */
/* @0x2aa3f8 svchs #0x79002 */
/* @0x2aa3fa cmp r7, #0x7 */
/* @0x2aa3fc itet eq */
/* @0x2aa3fe addeq.w r6, r6, #0xffffffff */
/* @0x2aa400 .word 0x370136ff */
/* @0x2aa402 addne r7, #0x1 */
/* @0x2aa404 moveq r7, #0x0 */
/* @0x2aa406 b 0x2aa3de <png_do_expand_palette+0x46> */
/* @0x2aa408 adds r5, r4, #0x3 */
/* @0x2aa40a subs r7, r4, #0x1 */
/* @0x2aa40c mvns r5, r5 */
/* @0x2aa40e and r5, r5, #0x3 */
/* @0x2aa410 bl 0x2eb824 <FT_Done_Memory+0x1bb0> */
/* @0x2aa412 add.w r6, r1, r7, lsr #2 */
/* @0x2aa414 strmi r0, [pc], #-1687 */
/* @0x2aa416 add r7, r1 */
/* @0x2aa418 lsls r5, r5, #0x1 */
/* @0x2aa41a rsb r8, r4, r7 */
/* @0x2aa41c strbmi r0, [r7, #-0x807] */
/* @0x2aa41e cmp r7, r8 */
/* @0x2aa420 beq 0x2aa47c <png_do_expand_palette+0xe4> */
/* @0x2aa422 ldrb.w r9, [r6] */
/* @0x2aa424 stchs p0, c9, [r6, #-0] */
/* @0x2aa426 cmp r5, #0x6 */
/* @0x2aa428 it eq */
/* @0x2aa42a addeq.w r6, r6, #0xffffffff */
/* @0x2aa42c blx 0x14f8030 <b2_toiTime+0xd9eb8c> */
/* @0x2aa42e asr.w r9, r9, r5 */
/* @0x2aa430 svclt #0x8f905 */
/* @0x2aa432 it eq */
/* @0x2aa434 moveq r5, #0x0 */
/* @0x2aa436 and r9, r9, #0x3 */
/* @0x2aa438 svclt #0x180903 */
/* @0x2aa43a it ne */
/* @0x2aa43c addne r5, #0x2 */
/* @0x2aa43e strb r9, [r7], #-1 */
/* @0x2aa440 strb r9, [r12, r1, lsl #18]! */
/* @0x2aa442 b 0x2aa41e <png_do_expand_palette+0x86> */
/* @0x2aa444 subs r7, r4, #0x1 */
/* @0x2aa446 and r5, r4, #0x1 */
/* @0x2aa448 bl 0x2eb854 <FT_Done_Memory+0x1be0> */
/* @0x2aa44a add.w r6, r1, r7, lsr #1 */
/* @0x2aa44c strmi r0, [pc], #-1623 */
/* @0x2aa44e add r7, r1 */
/* @0x2aa450 lsls r5, r5, #0x2 */
/* @0x2aa452 rsb r8, r4, r7 */
/* @0x2aa454 strbmi r0, [r7, #-0x807] */
/* @0x2aa456 cmp r7, r8 */
/* @0x2aa458 beq 0x2aa47c <png_do_expand_palette+0xe4> */
/* @0x2aa45a ldrb.w r9, [r6] */
/* @0x2aa45c stchs p0, c9, [r4, #-0] */
/* @0x2aa45e cmp r5, #0x4 */
/* @0x2aa460 it eq */
/* @0x2aa462 addeq.w r6, r6, #0xffffffff */
/* @0x2aa464 blx 0x14f8068 <b2_toiTime+0xd9ebc4> */
/* @0x2aa466 asr.w r9, r9, r5 */
/* @0x2aa468 svclt #0x8f905 */
/* @0x2aa46a it eq */
/* @0x2aa46c moveq r5, #0x0 */
/* @0x2aa46e and r9, r9, #0xf */
/* @0x2aa470 svclt #0x18090f */
/* @0x2aa472 it ne */
/* @0x2aa474 addne r5, #0x4 */
/* @0x2aa476 strb r9, [r7], #-1 */
/* @0x2aa478 strb r9, [r12, r1, lsl #18]! */
/* @0x2aa47a b 0x2aa456 <png_do_expand_palette+0xbe> */
/* @0x2aa47c movs r5, #0x8 */
/* @0x2aa47e str r4, [r0, #0x4] */
/* @0x2aa480 strb r5, [r0, #0x9] */
/* @0x2aa482 strb r5, [r0, #0xb] */
/* @0x2aa484 ldrb r5, [r0, #0x9] */
/* @0x2aa486 cmp r5, #0x8 */
/* @0x2aa488 bne 0x2aa538 <png_do_expand_palette+0x1a0> */
/* @0x2aa48a subs r7, r4, #0x1 */
/* @0x2aa48c cbz r3, 0x2aa4ec <png_do_expand_palette+0x154> */
/* @0x2aa48e lsls r6, r4, #0x2 */
/* @0x2aa490 mov.w r8, #0xff */
/* @0x2aa494 adds r5, r1, r6 */
/* @0x2aa496 add r1, r7 */
/* @0x2aa498 subs r5, #0x2 */
/* @0x2aa49a rsb r12, r4, r1 */
/* @0x2aa49c strbmi r0, [r1, #-0xc01]! */
/* @0x2aa49e cmp r1, r12 */
/* @0x2aa4a0 beq 0x2aa4da <png_do_expand_palette+0x142> */
/* @0x2aa4a2 ldrb r7, [r1], #-1 */
/* @0x2aa4a4 stclo p9, c7, [r4, #-4] */
/* @0x2aa4a6 subs r5, #0x4 */
/* @0x2aa4a8 ldr r4, [sp, #0x20] */
/* @0x2aa4aa cmp r7, r4 */
/* @0x2aa4ac itee ge */
/* @0x2aa4ae strbge.w r8, [r5, #0x5] */
/* @0x2aa4b0 ldclpl p0, c8, [pc, #20] */
/* @0x2aa4b2 ldrblt r7, [r3, r7] */
/* @0x2aa4b4 strblt r7, [r5, #0x5] */
/* @0x2aa4b6 ldrb r7, [r1, #0x1] */
/* @0x2aa4b8 add.w r7, r7, r7, lsl #1 */
/* @0x2aa4bc add r7, r2 */
/* @0x2aa4be ldrb r7, [r7, #0x2] */
/* @0x2aa4c0 strb r7, [r5, #0x4] */
/* @0x2aa4c2 ldrb r7, [r1, #0x1] */
/* @0x2aa4c4 add.w r7, r7, r7, lsl #1 */
/* @0x2aa4c8 add r7, r2 */
/* @0x2aa4ca ldrb r7, [r7, #0x1] */
/* @0x2aa4cc strb r7, [r5, #0x3] */
/* @0x2aa4ce ldrb r7, [r1, #0x1] */
/* @0x2aa4d0 add.w r7, r7, r7, lsl #1 */
/* @0x2aa4d4 ldrb r7, [r2, r7] */
/* @0x2aa4d6 strb r7, [r5, #0x2] */
/* @0x2aa4d8 b 0x2aa49e <png_do_expand_palette+0x106> */
/* @0x2aa4da movs r3, #0x8 */
/* @0x2aa4dc str r6, [r0, #0x4] */
/* @0x2aa4de strb r3, [r0, #0x9] */
/* @0x2aa4e0 movs r3, #0x20 */
/* @0x2aa4e2 strb r3, [r0, #0xb] */
/* @0x2aa4e4 movs r3, #0x6 */
/* @0x2aa4e6 strb r3, [r0, #0x8] */
/* @0x2aa4e8 movs r3, #0x4 */
/* @0x2aa4ea b 0x2aa536 <png_do_expand_palette+0x19e> */
/* @0x2aa4ec movs r5, #0x3 */
/* @0x2aa4ee adds r3, r1, r7 */
/* @0x2aa4f0 muls r5, r4, r5 */
/* @0x2aa4f2 mvns r4, r4 */
/* @0x2aa4f4 add r4, r3 */
/* @0x2aa4f6 subs r6, r5, #0x1 */
/* @0x2aa4f8 add r1, r6 */
/* @0x2aa4fa subs r3, #0x1 */
/* @0x2aa4fc cmp r3, r4 */
/* @0x2aa4fe beq 0x2aa526 <png_do_expand_palette+0x18e> */
/* @0x2aa500 ldrb r6, [r3, #0x1] */
/* @0x2aa502 subs r1, #0x3 */
/* @0x2aa504 add.w r6, r6, r6, lsl #1 */
/* @0x2aa508 add r6, r2 */
/* @0x2aa50a ldrb r6, [r6, #0x2] */
/* @0x2aa50c strb r6, [r1, #0x3] */
/* @0x2aa50e ldrb r6, [r3, #0x1] */
/* @0x2aa510 add.w r6, r6, r6, lsl #1 */
/* @0x2aa514 add r6, r2 */
/* @0x2aa516 ldrb r6, [r6, #0x1] */
/* @0x2aa518 strb r6, [r1, #0x2] */
/* @0x2aa51a ldrb r6, [r3, #0x1] */
/* @0x2aa51c add.w r6, r6, r6, lsl #1 */
/* @0x2aa520 ldrb r6, [r2, r6] */
/* @0x2aa522 strb r6, [r1, #0x1] */
/* @0x2aa524 b 0x2aa4fa <png_do_expand_palette+0x162> */
/* @0x2aa526 movs r3, #0x8 */
/* @0x2aa528 strb r3, [r0, #0x9] */
/* @0x2aa52a movs r3, #0x18 */
/* @0x2aa52c strb r3, [r0, #0xb] */
/* @0x2aa52e movs r3, #0x2 */
/* @0x2aa530 strb r3, [r0, #0x8] */
/* @0x2aa532 movs r3, #0x3 */
/* @0x2aa534 str r5, [r0, #0x4] */
/* @0x2aa536 strb r3, [r0, #0xa] */
/* @0x2aa538 pop.w {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2aa53c · png_do_expand · size=792 · insn=345 */
/* @0x2aa53c push.w {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aa540 ldrb r4, [r0, #0x8] */
/* @0x2aa542 ldr r3, [r0] */
/* @0x2aa544 cmp r4, #0x0 */
/* @0x2aa546 bne.w 0x2aa6f8 <png_do_expand+0x1bc> */
/* @0x2aa548 ldrdlt r8, r9, [r10, -r7] */
/* @0x2aa54a cbz r2, 0x2aa550 <png_do_expand+0x14> */
/* @0x2aa54c ldrh r4, [r2, #0x8] */
/* @0x2aa54e b 0x2aa552 <png_do_expand+0x16> */
/* @0x2aa550 mov r4, r2 */
/* @0x2aa552 ldrb r5, [r0, #0x9] */
/* @0x2aa554 cmp r5, #0x7 */
/* @0x2aa556 bhi.w 0x2aa65e <png_do_expand+0x122> */
/* @0x2aa558 stchs p0, c8, [r2, #-520] */
/* @0x2aa55a cmp r5, #0x2 */
/* @0x2aa55c beq 0x2aa5bc <png_do_expand+0x80> */
/* @0x2aa55e cmp r5, #0x4 */
/* @0x2aa560 beq 0x2aa610 <png_do_expand+0xd4> */
/* @0x2aa562 cmp r5, #0x1 */
/* @0x2aa564 bne 0x2aa656 <png_do_expand+0x11a> */
/* @0x2aa566 and r4, r4, #0x1 */
/* @0x2aa568 .word 0xf04f0401 */
/* @0x2aa56a mov.w r12, #0xff */
/* @0x2aa56c .word 0xf1030cff */
/* @0x2aa56e add.w r8, r3, #0xffffffff */
/* @0x2aa570 ldclne p8, c3, [lr, #1020] */
/* @0x2aa572 adds r6, r3, #0x7 */
/* @0x2aa574 mul r4, r12, r4 */
/* @0x2aa578 add.w r7, r1, r8, lsr #3 */
/* @0x2aa57c mvns r6, r6 */
/* @0x2aa57e add r8, r1 */
/* @0x2aa580 and r6, r6, #0x7 */
/* @0x2aa584 mvn.w r9, r3 */
/* @0x2aa588 add.w r5, r8, #0xffffffff */
/* @0x2aa58c add r8, r9 */
/* @0x2aa58e mov r9, r12 */
/* @0x2aa590 uxth r4, r4 */
/* @0x2aa592 cmp r5, r8 */
/* @0x2aa594 beq 0x2aa656 <png_do_expand+0x11a> */
/* @0x2aa596 ldrb.w r12, [r7] */
/* @0x2aa598 stclo p0, c12, [r1, #-0] */
/* @0x2aa59a subs r5, #0x1 */
/* @0x2aa59c asr.w r12, r12, r6 */
/* @0x2aa5a0 ands r12, r12, #0x1 */
/* @0x2aa5a4 ite ne */
/* @0x2aa5a6 strbne.w r9, [r5, #0x2] */
/* @0x2aa5a8 .word 0xf8859002 */
/* @0x2aa5aa strbeq.w r12, [r5, #0x2] */
/* @0x2aa5ac cdphs p0, #0x0, c12, c7, c2, #0x0 */
/* @0x2aa5ae cmp r6, #0x7 */
/* @0x2aa5b0 itet eq */
/* @0x2aa5b2 addeq.w r7, r7, #0xffffffff */
/* @0x2aa5b4 .word 0x360137ff */
/* @0x2aa5b6 addne r6, #0x1 */
/* @0x2aa5b8 moveq r6, #0x0 */
/* @0x2aa5ba b 0x2aa592 <png_do_expand+0x56> */
/* @0x2aa5bc and r4, r4, #0x3 */
/* @0x2aa5c0 movs r5, #0x55 */
/* @0x2aa5c2 subs r6, r3, #0x1 */
/* @0x2aa5c4 muls r4, r5, r4 */
/* @0x2aa5c6 adds r5, r3, #0x3 */
/* @0x2aa5c8 add.w r12, r1, r6, lsr #2 */
/* @0x2aa5cc add r6, r1 */
/* @0x2aa5ce mvns r5, r5 */
/* @0x2aa5d0 and r5, r5, #0x3 */
/* @0x2aa5d4 rsb r8, r3, r6 */
/* @0x2aa5d8 lsls r5, r5, #0x1 */
/* @0x2aa5da cmp r6, r8 */
/* @0x2aa5dc beq 0x2aa656 <png_do_expand+0x11a> */
/* @0x2aa5de ldrb.w r7, [r12] */
/* @0x2aa5e0 stchs p0, c7, [r6, #-0] */
/* @0x2aa5e2 cmp r5, #0x6 */
/* @0x2aa5e4 it eq */
/* @0x2aa5e6 addeq.w r12, r12, #0xffffffff */
/* @0x2aa5e8 blx 0x14799ec <b2_toiTime+0xd20548> */
/* @0x2aa5ea asr.w r7, r7, r5 */
/* @0x2aa5ec svclt #0x8f705 */
/* @0x2aa5ee it eq */
/* @0x2aa5f0 moveq r5, #0x0 */
/* @0x2aa5f2 and r7, r7, #0x3 */
/* @0x2aa5f4 svclt #0x180703 */
/* @0x2aa5f6 it ne */
/* @0x2aa5f8 addne r5, #0x2 */
/* @0x2aa5fa lsl.w r9, r7, #0x4 */
/* @0x2aa5fc b 0x14f0a20 <b2_toiTime+0xd9757c> */
/* @0x2aa5fe orr.w r9, r9, r7, lsl #2 */
/* @0x2aa600 b 0x14ecc24 <b2_toiTime+0xd93780> */
/* @0x2aa602 orr.w r9, r9, r7 */
/* @0x2aa604 b 0x14eca28 <b2_toiTime+0xd93584> */
/* @0x2aa606 orr.w r7, r9, r7, lsl #6 */
/* @0x2aa608 .word 0xf8061787 */
/* @0x2aa60a strb r7, [r6], #-1 */
/* @0x2aa60c strb r7, [r4, r1, lsl #18]! */
/* @0x2aa60e b 0x2aa5da <png_do_expand+0x9e> */
/* @0x2aa610 and r4, r4, #0xf */
/* @0x2aa614 movs r5, #0x11 */
/* @0x2aa616 tst.w r3, #0x1 */
/* @0x2aa618 blx 0x3ee226 */
/* @0x2aa61a mul r4, r5, r4 */
/* @0x2aa61c .word 0xf103f404 */
/* @0x2aa61e add.w r5, r3, #0xffffffff */
/* @0x2aa620 svclt #0xc35ff */
/* @0x2aa622 ite eq */
/* @0x2aa624 moveq r6, #0x0 */
/* @0x2aa626 movne r6, #0x4 */
/* @0x2aa628 add.w r7, r1, r5, lsr #1 */
/* @0x2aa62c add r5, r1 */
/* @0x2aa62e rsb r8, r3, r5 */
/* @0x2aa630 strbmi r0, [r5, #-0x805] */
/* @0x2aa632 cmp r5, r8 */
/* @0x2aa634 beq 0x2aa656 <png_do_expand+0x11a> */
/* @0x2aa636 ldrb.w r12, [r7] */
/* @0x2aa638 blx 0x15da640 <b2_toiTime+0xe8119c> */
/* @0x2aa63a asr.w r12, r12, r6 */
/* @0x2aa63c .word 0xf00cfc06 */
/* @0x2aa63e and r12, r12, #0xf */
/* @0x2aa640 b 0x15ad684 <b2_toiTime+0xe541e0> */
/* @0x2aa642 orr.w r12, r12, r12, lsl #4 */
/* @0x2aa644 .word 0xf8051c0c */
/* @0x2aa646 strb r12, [r5], #-1 */
/* @0x2aa648 tstlt r6, r1, lsl #18 */
/* @0x2aa64a cbz r6, 0x2aa652 <png_do_expand+0x116> */
/* @0x2aa64c subs r7, #0x1 */
/* @0x2aa64e movs r6, #0x0 */
/* @0x2aa650 b 0x2aa632 <png_do_expand+0xf6> */
/* @0x2aa652 movs r6, #0x4 */
/* @0x2aa654 b 0x2aa632 <png_do_expand+0xf6> */
/* @0x2aa656 movs r5, #0x8 */
/* @0x2aa658 str r3, [r0, #0x4] */
/* @0x2aa65a strb r5, [r0, #0x9] */
/* @0x2aa65c strb r5, [r0, #0xb] */
/* @0x2aa65e cmp r2, #0x0 */
/* @0x2aa660 beq.w 0x2aa84e <png_do_expand+0x312> */
/* @0x2aa664 ldrb r2, [r0, #0x9] */
/* @0x2aa666 cmp r2, #0x8 */
/* @0x2aa668 bne 0x2aa698 <png_do_expand+0x15c> */
/* @0x2aa66a subs r5, r3, #0x1 */
/* @0x2aa66c add.w r2, r1, r3, lsl #1 */
/* @0x2aa670 add r1, r5 */
/* @0x2aa672 uxtb r4, r4 */
/* @0x2aa674 subs r2, #0x2 */
/* @0x2aa676 subs r6, r1, r3 */
/* @0x2aa678 movs r7, #0xff */
/* @0x2aa67a mov.w r12, #0x0 */
/* @0x2aa67c adcsmi r0, r1, #0, #24 */
/* @0x2aa67e cmp r1, r6 */
/* @0x2aa680 beq 0x2aa6b8 <png_do_expand+0x17c> */
/* @0x2aa682 ldrb r5, [r1], #-1 */
/* @0x2aa684 adcmi r5, r5, #16384 */
/* @0x2aa686 cmp r5, r4 */
/* @0x2aa688 ite ne */
/* @0x2aa68a movne r5, r7 */
/* @0x2aa68c moveq r5, r12 */
/* @0x2aa68e strb r5, [r2, #0x1] */
/* @0x2aa690 ldrb r5, [r1, #0x1] */
/* @0x2aa692 strb r5, [r2], #-2 */
/* @0x2aa694 ldrb r5, [r2, r2, lsl #18]! */
/* @0x2aa696 b 0x2aa67e <png_do_expand+0x142> */
/* @0x2aa698 cmp r2, #0x10 */
/* @0x2aa69a bne 0x2aa6b8 <png_do_expand+0x17c> */
/* @0x2aa69c ldr r5, [r0, #0x4] */
/* @0x2aa69e ubfx r12, r4, #0x8, #0x8 */
/* @0x2aa6a0 rsclt r2, r4, #1792 */
/* @0x2aa6a2 uxtb r4, r4 */
/* @0x2aa6a4 movs r6, #0xff */
/* @0x2aa6a6 adds r2, r1, r5 */
/* @0x2aa6a8 add.w r1, r1, r5, lsl #1 */
/* @0x2aa6ac subs r2, #0x3 */
/* @0x2aa6ae movs r5, #0x0 */
/* @0x2aa6b0 subs r1, #0x3 */
/* @0x2aa6b2 mov r7, r5 */
/* @0x2aa6b4 cmp r5, r3 */
/* @0x2aa6b6 bne 0x2aa6c6 <png_do_expand+0x18a> */
/* @0x2aa6b8 movs r2, #0x4 */
/* @0x2aa6ba strb r2, [r0, #0x8] */
/* @0x2aa6bc movs r2, #0x2 */
/* @0x2aa6be strb r2, [r0, #0xa] */
/* @0x2aa6c0 ldrb r2, [r0, #0x9] */
/* @0x2aa6c2 lsls r2, r2, #0x1 */
/* @0x2aa6c4 b 0x2aa7be <png_do_expand+0x282> */
/* @0x2aa6c6 ldrb.w r8, [r2, #0x1] */
/* @0x2aa6c8 strbmi r8, [r0, #0x1]! */
/* @0x2aa6ca cmp r8, r12 */
/* @0x2aa6cc bne 0x2aa6dc <png_do_expand+0x1a0> */
/* @0x2aa6ce ldrb.w r8, [r2, #0x2] */
/* @0x2aa6d0 strmi r8, [r0, #0x2]! */
/* @0x2aa6d2 cmp r8, r4 */
/* @0x2aa6d4 bne 0x2aa6dc <png_do_expand+0x1a0> */
/* @0x2aa6d6 strb r7, [r1, #0x2] */
/* @0x2aa6d8 strb r7, [r1, #0x1] */
/* @0x2aa6da b 0x2aa6e0 <png_do_expand+0x1a4> */
/* @0x2aa6dc strb r6, [r1, #0x2] */
/* @0x2aa6de strb r6, [r1, #0x1] */
/* @0x2aa6e0 ldrb.w r8, [r2, #0x2] */
/* @0x2aa6e4 adds r5, #0x1 */
/* @0x2aa6e6 subs r2, #0x2 */
/* @0x2aa6e8 subs r1, #0x4 */
/* @0x2aa6ea strb.w r8, [r1, #0x4] */
/* @0x2aa6ec .word 0xf8928004 */
/* @0x2aa6ee ldrb.w r8, [r2, #0x3] */
/* @0x2aa6f0 .word 0xf8818003 */
/* @0x2aa6f2 strb.w r8, [r1, #0x3] */
/* @0x2aa6f4 ldrb r8, [sp, r3] */
/* @0x2aa6f6 b 0x2aa6b4 <png_do_expand+0x178> */
/* @0x2aa6f8 cmp r4, #0x2 */
/* @0x2aa6fa bne.w 0x2aa84e <png_do_expand+0x312> */
/* @0x2aa6fc bhs 0x2ca9a4 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x140> */
/* @0x2aa6fe cmp r2, #0x0 */
/* @0x2aa700 beq.w 0x2aa84e <png_do_expand+0x312> */
/* @0x2aa704 ldrb r4, [r0, #0x9] */
/* @0x2aa706 cmp r4, #0x8 */
/* @0x2aa708 bne 0x2aa76e <png_do_expand+0x232> */
/* @0x2aa70a ldrb r5, [r2, #0x2] */
/* @0x2aa70c movs r4, #0x3 */
/* @0x2aa70e ldrb r6, [r2, #0x4] */
/* @0x2aa710 mov.w r12, #0xff */
/* @0x2aa714 ldrb r7, [r2, #0x6] */
/* @0x2aa716 mov.w r8, #0x0 */
/* @0x2aa718 stmdavs r2, {r11} ^ */
/* @0x2aa71a ldr r2, [r0, #0x4] */
/* @0x2aa71c subs r2, #0x1 */
/* @0x2aa71e add r2, r1 */
/* @0x2aa720 add.w r1, r1, r3, lsl #2 */
/* @0x2aa724 subs r1, #0x2 */
/* @0x2aa726 mls r4, r4, r3, r2 */
/* @0x2aa728 adcmi r2, r2, #318767104 */
/* @0x2aa72a cmp r2, r4 */
/* @0x2aa72c beq 0x2aa7b2 <png_do_expand+0x276> */
/* @0x2aa72e ldrb r9, [r2, #-2] */
/* @0x2aa730 strmi r9, [r9, #0xc02]! */
/* @0x2aa732 cmp r9, r5 */
/* @0x2aa734 bne 0x2aa74c <png_do_expand+0x210> */
/* @0x2aa736 ldrb r9, [r2, #-1] */
/* @0x2aa738 ldrmi r9, [r1, #0xc01]! */
/* @0x2aa73a cmp r9, r6 */
/* @0x2aa73c bne 0x2aa74c <png_do_expand+0x210> */
/* @0x2aa73e ldrb.w r9, [r2] */
/* @0x2aa740 ldrmi r9, [r9, #0x0]! */
/* @0x2aa742 cmp r9, r7 */
/* @0x2aa744 bne 0x2aa74c <png_do_expand+0x210> */
/* @0x2aa746 strb.w r8, [r1, #0x1] */
/* @0x2aa748 and r8, r1, r1 */
/* @0x2aa74a b 0x2aa750 <png_do_expand+0x214> */
/* @0x2aa74c strb.w r12, [r1, #0x1] */
/* @0x2aa750 ldrb.w r9, [r2] */
/* @0x2aa754 subs r1, #0x4 */
/* @0x2aa756 subs r2, #0x3 */
/* @0x2aa758 strb.w r9, [r1, #0x4] */
/* @0x2aa75c ldrb.w r9, [r2, #0x2] */
/* @0x2aa760 strb.w r9, [r1, #0x3] */
/* @0x2aa764 ldrb.w r9, [r2, #0x1] */
/* @0x2aa768 strb.w r9, [r1, #0x2] */
/* @0x2aa76c b 0x2aa72a <png_do_expand+0x1ee> */
/* @0x2aa76e cmp r4, #0x10 */
/* @0x2aa770 bne 0x2aa7b2 <png_do_expand+0x276> */
/* @0x2aa772 ldrh.w r8, [r2, #0x2] */
/* @0x2aa774 ldrbhs r8, [pc, #0x2]! */
/* @0x2aa776 movs r5, #0xff */
/* @0x2aa778 ldrh.w r9, [r2, #0x4] */
/* @0x2aa77c ldrh.w r10, [r2, #0x6] */
/* @0x2aa780 ldr r2, [r0, #0x4] */
/* @0x2aa782 lsr.w r4, r8, #0x8 */
/* @0x2aa784 b 0x16737ec <b2_toiTime+0xf1a348> */
/* @0x2aa786 lsr.w r7, r9, #0x8 */
/* @0x2aa788 strls r2, [r1], #-1817 */
/* @0x2aa78a str r4, [sp, #0x4] */
/* @0x2aa78c subs r2, #0x1 */
/* @0x2aa78e lsr.w r12, r10, #0x8 */
/* @0x2aa790 strmi r2, [r10], #-3098 */
/* @0x2aa792 add r2, r1 */
/* @0x2aa794 add.w r1, r1, r3, lsl #3 */
/* @0x2aa798 movs r4, #0x0 */
/* @0x2aa79a uxtb.w r8, r8 */
/* @0x2aa79c blx 0x1aa89c4 <b2_toiTime+0x134f520> */
/* @0x2aa79e uxtb.w r9, r9 */
/* @0x2aa7a0 blx 0x1aa8dcc <b2_toiTime+0x134f928> */
/* @0x2aa7a2 uxtb.w r10, r10 */
/* @0x2aa7a4 stmdblo r3, {r1, r3, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2aa7a6 subs r1, #0x3 */
/* @0x2aa7a8 mov r6, r4 */
/* @0x2aa7aa str.w r12, [sp] */
/* @0x2aa7ac addsmi r12, r12, #0 */
/* @0x2aa7ae cmp r4, r3 */
/* @0x2aa7b0 bne 0x2aa7cc <png_do_expand+0x290> */
/* @0x2aa7b2 movs r2, #0x6 */
/* @0x2aa7b4 strb r2, [r0, #0x8] */
/* @0x2aa7b6 movs r2, #0x4 */
/* @0x2aa7b8 strb r2, [r0, #0xa] */
/* @0x2aa7ba ldrb r2, [r0, #0x9] */
/* @0x2aa7bc lsls r2, r2, #0x2 */
/* @0x2aa7be uxtb r2, r2 */
/* @0x2aa7c0 strb r2, [r0, #0xb] */
/* @0x2aa7c2 cmp r2, #0x7 */
/* @0x2aa7c4 bls 0x2aa846 <png_do_expand+0x30a> */
/* @0x2aa7c6 lsrs r2, r2, #0x3 */
/* @0x2aa7c8 muls r3, r2, r3 */
/* @0x2aa7ca b 0x2aa84c <png_do_expand+0x310> */
/* @0x2aa7cc ldrb r11, [r2, #-5] */
/* @0x2aa7d0 ldr.w r12, [sp, #0x4] */
/* @0x2aa7d4 cmp r11, r12 */
/* @0x2aa7d6 bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa7d8 ldrb r11, [r2, #-4] */
/* @0x2aa7dc cmp r11, r8 */
/* @0x2aa7de bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa7e0 ldrb r11, [r2, #-3] */
/* @0x2aa7e4 cmp r11, r7 */
/* @0x2aa7e6 bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa7e8 ldrb r11, [r2, #-2] */
/* @0x2aa7ec cmp r11, r9 */
/* @0x2aa7ee bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa7f0 ldrb r11, [r2, #-1] */
/* @0x2aa7f4 ldr.w r12, [sp] */
/* @0x2aa7f8 cmp r11, r12 */
/* @0x2aa7fa bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa7fc ldrb.w r11, [r2] */
/* @0x2aa800 cmp r11, r10 */
/* @0x2aa802 bne 0x2aa80a <png_do_expand+0x2ce> */
/* @0x2aa804 strb r6, [r1, #0x2] */
/* @0x2aa806 strb r6, [r1, #0x1] */
/* @0x2aa808 b 0x2aa80e <png_do_expand+0x2d2> */
/* @0x2aa80a strb r5, [r1, #0x2] */
/* @0x2aa80c strb r5, [r1, #0x1] */
/* @0x2aa80e ldrb.w r11, [r2] */
/* @0x2aa810 strlo r11, [r1], #-0 */
/* @0x2aa812 adds r4, #0x1 */
/* @0x2aa814 subs r2, #0x6 */
/* @0x2aa816 subs r1, #0x8 */
/* @0x2aa818 strb.w r11, [r1, #0x8] */
/* @0x2aa81c ldrb.w r11, [r2, #0x5] */
/* @0x2aa820 strb.w r11, [r1, #0x7] */
/* @0x2aa824 ldrb.w r11, [r2, #0x4] */
/* @0x2aa828 strb.w r11, [r1, #0x6] */
/* @0x2aa82c ldrb.w r11, [r2, #0x3] */
/* @0x2aa830 strb.w r11, [r1, #0x5] */
/* @0x2aa834 ldrb.w r11, [r2, #0x2] */
/* @0x2aa838 strb.w r11, [r1, #0x4] */
/* @0x2aa83c ldrb.w r11, [r2, #0x1] */
/* @0x2aa840 strb.w r11, [r1, #0x3] */
/* @0x2aa844 b 0x2aa7ae <png_do_expand+0x272> */
/* @0x2aa846 muls r3, r2, r3 */
/* @0x2aa848 adds r3, #0x7 */
/* @0x2aa84a lsrs r3, r3, #0x3 */
/* @0x2aa84c str r3, [r0, #0x4] */
/* @0x2aa84e add sp, #0xc */
/* @0x2aa850 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2aa854 · png_do_quantize · size=214 · insn=101 */
/* @0x2aa854 push {r4, r5, r6, r7, lr} */
/* @0x2aa856 ldrb r5, [r0, #0x8] */
/* @0x2aa858 ldr r4, [r0] */
/* @0x2aa85a cmp r5, #0x2 */
/* @0x2aa85c bne 0x2aa8b2 <png_do_quantize+0x5e> */
/* @0x2aa85e cmp r2, #0x0 */
/* @0x2aa860 beq 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa862 ldrb r3, [r0, #0x9] */
/* @0x2aa864 cmp r3, #0x8 */
/* @0x2aa866 bne 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa868 adds r5, r1, r4 */
/* @0x2aa86a mov r3, r1 */
/* @0x2aa86c cmp r1, r5 */
/* @0x2aa86e beq 0x2aa892 <png_do_quantize+0x3e> */
/* @0x2aa870 ldrb r6, [r3, #0x1] */
/* @0x2aa872 adds r3, #0x3 */
/* @0x2aa874 ldrb r7, [r3, #-3] */
/* @0x2aa878 asrs r6, r6, #0x3 */
/* @0x2aa87a asrs r7, r7, #0x3 */
/* @0x2aa87c lsls r6, r6, #0x5 */
/* @0x2aa87e orr.w r6, r6, r7, lsl #10 */
/* @0x2aa880 .word 0xf8132687 */
/* @0x2aa882 ldrb r7, [r3, #-1] */
/* @0x2aa884 b 0x1449890 <b2_toiTime+0xcf03ec> */
/* @0x2aa886 orr.w r6, r6, r7, lsr #3 */
/* @0x2aa888 ldcpl p6, c0, [r6, #860] */
/* @0x2aa88a ldrb r6, [r2, r6] */
/* @0x2aa88c strb r6, [r1], #1 */
/* @0x2aa890 b 0x2aa86c <png_do_quantize+0x18> */
/* @0x2aa892 movs r3, #0x3 */
/* @0x2aa894 strb r3, [r0, #0x8] */
/* @0x2aa896 movs r3, #0x1 */
/* @0x2aa898 strb r3, [r0, #0xa] */
/* @0x2aa89a ldrb r3, [r0, #0x9] */
/* @0x2aa89c cmp r3, #0x7 */
/* @0x2aa89e strb r3, [r0, #0xb] */
/* @0x2aa8a0 bls 0x2aa8a8 <png_do_quantize+0x54> */
/* @0x2aa8a2 lsrs r3, r3, #0x3 */
/* @0x2aa8a4 muls r4, r3, r4 */
/* @0x2aa8a6 b 0x2aa8ae <png_do_quantize+0x5a> */
/* @0x2aa8a8 muls r4, r3, r4 */
/* @0x2aa8aa adds r4, #0x7 */
/* @0x2aa8ac lsrs r4, r4, #0x3 */
/* @0x2aa8ae str r4, [r0, #0x4] */
/* @0x2aa8b0 pop {r4, r5, r6, r7, pc} */
/* @0x2aa8b2 cmp r5, #0x6 */
/* @0x2aa8b4 bne 0x2aa90c <png_do_quantize+0xb8> */
/* @0x2aa8b6 cmp r2, #0x0 */
/* @0x2aa8b8 beq 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa8ba ldrb r3, [r0, #0x9] */
/* @0x2aa8bc cmp r3, #0x8 */
/* @0x2aa8be bne 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa8c0 mov r5, r1 */
/* @0x2aa8c2 movs r3, #0x0 */
/* @0x2aa8c4 cmp r3, r4 */
/* @0x2aa8c6 beq 0x2aa8ec <png_do_quantize+0x98> */
/* @0x2aa8c8 ldrb r6, [r5, #0x1] */
/* @0x2aa8ca adds r5, #0x4 */
/* @0x2aa8cc ldrb r12, [r5, #-4] */
/* @0x2aa8d0 ldrb r7, [r5, #-2] */
/* @0x2aa8d4 asrs r6, r6, #0x3 */
/* @0x2aa8d6 asr.w r12, r12, #0x3 */
/* @0x2aa8d8 cmneq r6, r12, ror #25 */
/* @0x2aa8da lsls r6, r6, #0x5 */
/* @0x2aa8dc orr.w r6, r6, r12, lsl #10 */
/* @0x2aa8e0 orr.w r6, r6, r7, lsr #3 */
/* @0x2aa8e4 ldrb r6, [r2, r6] */
/* @0x2aa8e6 strb r6, [r1, r3] */
/* @0x2aa8e8 adds r3, #0x1 */
/* @0x2aa8ea b 0x2aa8c4 <png_do_quantize+0x70> */
/* @0x2aa8ec movs r2, #0x3 */
/* @0x2aa8ee strb r2, [r0, #0x8] */
/* @0x2aa8f0 movs r2, #0x1 */
/* @0x2aa8f2 strb r2, [r0, #0xa] */
/* @0x2aa8f4 ldrb r2, [r0, #0x9] */
/* @0x2aa8f6 cmp r2, #0x7 */
/* @0x2aa8f8 strb r2, [r0, #0xb] */
/* @0x2aa8fa bls 0x2aa902 <png_do_quantize+0xae> */
/* @0x2aa8fc lsrs r2, r2, #0x3 */
/* @0x2aa8fe muls r3, r2, r3 */
/* @0x2aa900 b 0x2aa908 <png_do_quantize+0xb4> */
/* @0x2aa902 muls r3, r2, r3 */
/* @0x2aa904 adds r3, #0x7 */
/* @0x2aa906 lsrs r3, r3, #0x3 */
/* @0x2aa908 str r3, [r0, #0x4] */
/* @0x2aa90a pop {r4, r5, r6, r7, pc} */
/* @0x2aa90c cmp r5, #0x3 */
/* @0x2aa90e bne 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa910 cbz r3, 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa912 ldrb r2, [r0, #0x9] */
/* @0x2aa914 cmp r2, #0x8 */
/* @0x2aa916 bne 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa918 add r4, r1 */
/* @0x2aa91a cmp r1, r4 */
/* @0x2aa91c beq 0x2aa928 <png_do_quantize+0xd4> */
/* @0x2aa91e ldrb r2, [r1] */
/* @0x2aa920 ldrb r2, [r3, r2] */
/* @0x2aa922 strb r2, [r1], #1 */
/* @0x2aa924 ldrb r2, [r8, r1, lsl #22]! */
/* @0x2aa926 b 0x2aa91a <png_do_quantize+0xc6> */
/* @0x2aa928 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2aa92c · png_do_read_transformations · size=880 · insn=360 */
/* @0x2aa92c ldr r3, [pc, #0x354] */
/* @0x2aa92e push {r4, r5, r6, lr} */
/* @0x2aa930 add r3, pc */
/* @0x2aa932 ldr r3, [r3] */
/* @0x2aa934 sub sp, #0x58 */
/* @0x2aa936 mov r4, r0 */
/* @0x2aa938 ldr r2, [r3] */
/* @0x2aa93a mov r6, r3 */
/* @0x2aa93c str r2, [sp, #0x54] */
/* @0x2aa93e ldr.w r2, [r0, #0x1b0] */
/* @0x2aa940 ldmdblt r10!, {r4, r5, r7, r8, sp} ^ */
/* @0x2aa942 cbnz r2, 0x2aa964 <png_do_read_transformations+0x38> */
/* @0x2aa944 ldrb.w r3, [r0, #0x1e8] */
/* @0x2aa948 add r5, sp, #0x20 */
/* @0x2aa94a ldr r2, [pc, #0x33c] */
/* @0x2aa94c movs r1, #0x32 */
/* @0x2aa94e mov r0, r5 */
/* @0x2aa950 str r3, [sp] */
/* @0x2aa952 add r2, pc */
/* @0x2aa954 ldr.w r3, [r4, #0x1a8] */
/* @0x2aa958 blx 0xb65c8 <snprintf@plt> */
/* @0x2aa95c mov r0, r4 */
/* @0x2aa95e mov r1, r5 */
/* @0x2aa960 bl 0x2a642c <png_error> */
/* @0x2aa964 ldr.w r3, [r4, #0x134] */
/* @0x2aa968 lsls r1, r3, #0x13 */
/* @0x2aa96a bpl 0x2aa9c2 <png_do_read_transformations+0x96> */
/* @0x2aa96c ldrb.w r2, [r4, #0x1cc] */
/* @0x2aa970 add.w r5, r4, #0x1c4 */
/* @0x2aa974 cmp r2, #0x3 */
/* @0x2aa976 bne 0x2aa9a4 <png_do_read_transformations+0x78> */
/* @0x2aa978 ldr.w r3, [r4, #0x1d8] */
/* @0x2aa97c cbnz r3, 0x2aa988 <png_do_read_transformations+0x5c> */
/* @0x2aa97e ldr r1, [pc, #0x30c] */
/* @0x2aa980 mov r0, r4 */
/* @0x2aa982 add r1, pc */
/* @0x2aa984 bl 0x2a642c <png_error> */
/* @0x2aa988 ldrh.w r3, [r4, #0x1de] */
/* @0x2aa98c mov r0, r5 */
/* @0x2aa98e ldr.w r1, [r4, #0x1b0] */
/* @0x2aa990 .word 0xf8d411b0 */
/* @0x2aa992 ldr.w r2, [r4, #0x1d8] */
/* @0x2aa994 movwls r2, #0x1d8 */
/* @0x2aa996 str r3, [sp] */
/* @0x2aa998 adds r1, #0x1 */
/* @0x2aa99a ldr.w r3, [r4, #0x24c] */
/* @0x2aa99c .word 0xf7ff324c */
/* @0x2aa99e bl 0x2aa398 <png_do_expand_palette> */
/* @0x2aa9a0 .word 0xe00efcfb */
/* @0x2aa9a2 b 0x2aa9c2 <png_do_read_transformations+0x96> */
/* @0x2aa9a4 ldr.w r1, [r4, #0x1b0] */
/* @0x2aa9a8 mov r0, r5 */
/* @0x2aa9aa ldrh.w r2, [r4, #0x1de] */
/* @0x2aa9ac ldrdlo r2, r3, [r1, -lr] */
/* @0x2aa9ae adds r1, #0x1 */
/* @0x2aa9b0 cbz r2, 0x2aa9bc <png_do_read_transformations+0x90> */
/* @0x2aa9b2 lsls r2, r3, #0x6 */
/* @0x2aa9b4 bpl 0x2aa9bc <png_do_read_transformations+0x90> */
/* @0x2aa9b6 add.w r2, r4, #0x250 */
/* @0x2aa9b8 and r7, r0, r4, lsl r2 */
/* @0x2aa9ba b 0x2aa9be <png_do_read_transformations+0x92> */
/* @0x2aa9bc movs r2, #0x0 */
/* @0x2aa9be bl 0x2aa53c <png_do_expand> */
/* @0x2aa9c0 .word 0xf8d4fdbd */
/* @0x2aa9c2 ldr.w r2, [r4, #0x130] */
/* @0x2aa9c4 .word 0xf4122130 */
/* @0x2aa9c6 ands r2, r2, #0x400000 */
/* @0x2aa9c8 andle r0, r8, r0, lsl #5 */
/* @0x2aa9ca beq 0x2aa9de <png_do_read_transformations+0xb2> */
/* @0x2aa9cc ldr.w r1, [r4, #0x1b0] */
/* @0x2aa9d0 add.w r0, r4, #0x1c4 */
/* @0x2aa9d4 orr r2, r2, #0x80 */
/* @0x2aa9d8 adds r1, #0x1 */
/* @0x2aa9da bl 0x2af930 <png_do_strip_filler> */
/* @0x2aa9dc .word 0xf8d4ffa9 */
/* @0x2aa9de ldr.w r3, [r4, #0x134] */
/* @0x2aa9e0 .word 0xf4133134 */
/* @0x2aa9e2 tst.w r3, #0x600000 */
/* @0x2aa9e4 eorle r0, r3, r0, asr #31 */
/* @0x2aa9e6 beq 0x2aaa30 <png_do_read_transformations+0x104> */
/* @0x2aa9e8 ldr.w r2, [r4, #0x1b0] */
/* @0x2aa9ec mov r0, r4 */
/* @0x2aa9ee add.w r1, r4, #0x1c4 */
/* @0x2aa9f0 andlo r7, r1, #-2147483592 */
/* @0x2aa9f2 adds r2, #0x1 */
/* @0x2aa9f4 bl 0x2a91ac <png_do_rgb_to_gray> */
/* @0x2aa9f8 cbz r0, 0x2aaa30 <png_do_read_transformations+0x104> */
/* @0x2aa9fa movs r3, #0x1 */
/* @0x2aa9fc strb.w r3, [r4, #0x2d4] */
/* @0x2aaa00 ldr.w r3, [r4, #0x134] */
/* @0x2aaa04 and r3, r3, #0x600000 */
/* @0x2aaa08 cmp.w r3, #0x400000 */
/* @0x2aaa0c bne 0x2aaa18 <png_do_read_transformations+0xec> */
/* @0x2aaa0e ldr r1, [pc, #0x280] */
/* @0x2aaa10 mov r0, r4 */
/* @0x2aaa12 add r1, pc */
/* @0x2aaa14 bl 0x2a6474 <png_warning> */
/* @0x2aaa18 ldr.w r3, [r4, #0x134] */
/* @0x2aaa1c and r3, r3, #0x600000 */
/* @0x2aaa20 cmp.w r3, #0x200000 */
/* @0x2aaa24 bne 0x2aaa30 <png_do_read_transformations+0x104> */
/* @0x2aaa26 ldr r1, [pc, #0x26c] */
/* @0x2aaa28 mov r0, r4 */
/* @0x2aaa2a add r1, pc */
/* @0x2aaa2c bl 0x2a642c <png_error> */
/* @0x2aaa30 ldr.w r3, [r4, #0x134] */
/* @0x2aaa34 lsls r3, r3, #0x11 */
/* @0x2aaa36 bpl 0x2aaa4e <png_do_read_transformations+0x122> */
/* @0x2aaa38 ldr.w r3, [r4, #0x12c] */
/* @0x2aaa3c lsls r5, r3, #0x14 */
/* @0x2aaa3e bmi 0x2aaa4e <png_do_read_transformations+0x122> */
/* @0x2aaa40 ldr.w r1, [r4, #0x1b0] */
/* @0x2aaa44 add.w r0, r4, #0x1c4 */
/* @0x2aaa48 adds r1, #0x1 */
/* @0x2aaa4a bl 0x2a90ac <png_do_gray_to_rgb> */
/* @0x2aaa4c .word 0xf8d4fb2f */
/* @0x2aaa4e ldr.w r3, [r4, #0x134] */
/* @0x2aaa50 sasxeq r3, r8, r4 */
/* @0x2aaa52 lsls r0, r3, #0x18 */
/* @0x2aaa54 bpl 0x2aaaaa <png_do_read_transformations+0x17e> */
/* @0x2aaa56 ldrh.w r3, [r4, #0x1de] */
/* @0x2aaa58 ldmdblt r11, {r1, r2, r3, r4, r6, r7, r8, r12, sp} */
/* @0x2aaa5a cbnz r3, 0x2aaa64 <png_do_read_transformations+0x138> */
/* @0x2aaa5c ldrb.w r3, [r4, #0x1ea] */
/* @0x2aaa60 lsls r1, r3, #0x1d */
/* @0x2aaa62 bpl 0x2aaaaa <png_do_read_transformations+0x17e> */
/* @0x2aaa64 addw r3, r4, #0x206 */
/* @0x2aaa68 str r3, [sp] */
/* @0x2aaa6a ldr.w r3, [r4, #0x228] */
/* @0x2aaa6c .word 0xf5043228 */
/* @0x2aaa6e add.w r0, r4, #0x1c4 */
/* @0x2aaa70 .word 0xf8d470e2 */
/* @0x2aaa72 ldr.w r1, [r4, #0x1b0] */
/* @0x2aaa74 .word 0xf50411b0 */
/* @0x2aaa76 add.w r2, r4, #0x250 */
/* @0x2aaa78 movwls r7, #0x1214 */
/* @0x2aaa7a str r3, [sp, #0x4] */
/* @0x2aaa7c adds r1, #0x1 */
/* @0x2aaa7e ldr.w r3, [r4, #0x22c] */
/* @0x2aaa80 movwls r3, #0x222c */
/* @0x2aaa82 str r3, [sp, #0x8] */
/* @0x2aaa84 ldr.w r3, [r4, #0x230] */
/* @0x2aaa88 str r3, [sp, #0xc] */
/* @0x2aaa8a ldr.w r3, [r4, #0x234] */
/* @0x2aaa8c movwls r3, #0x4234 */
/* @0x2aaa8e str r3, [sp, #0x10] */
/* @0x2aaa90 ldr.w r3, [r4, #0x238] */
/* @0x2aaa94 str r3, [sp, #0x14] */
/* @0x2aaa96 ldr.w r3, [r4, #0x23c] */
/* @0x2aaa98 movwls r3, #0x623c */
/* @0x2aaa9a str r3, [sp, #0x18] */
/* @0x2aaa9c ldr.w r3, [r4, #0x21c] */
/* @0x2aaaa0 str r3, [sp, #0x1c] */
/* @0x2aaaa2 add.w r3, r4, #0x1fc */
/* @0x2aaaa4 .word 0xf7fe73fe */
/* @0x2aaaa6 bl 0x2a9680 <png_do_background> */
/* @0x2aaaa8 .word 0xf8d4fdeb */
/* @0x2aaaaa ldr.w r3, [r4, #0x134] */
/* @0x2aaaac ldreq r3, [r10], #308 */
/* @0x2aaaae lsls r2, r3, #0x12 */
/* @0x2aaab0 bpl 0x2aaae8 <png_do_read_transformations+0x1bc> */
/* @0x2aaab2 lsls r3, r3, #0x18 */
/* @0x2aaab4 bpl 0x2aaac4 <png_do_read_transformations+0x198> */
/* @0x2aaab6 ldrh.w r3, [r4, #0x1de] */
/* @0x2aaab8 stmiblt r11!, {r1, r2, r3, r4, r6, r7, r8, r12, sp} */
/* @0x2aaaba cbnz r3, 0x2aaae8 <png_do_read_transformations+0x1bc> */
/* @0x2aaabc ldrb.w r3, [r4, #0x1ea] */
/* @0x2aaac0 lsls r5, r3, #0x1d */
/* @0x2aaac2 bmi 0x2aaae8 <png_do_read_transformations+0x1bc> */
/* @0x2aaac4 ldrb.w r3, [r4, #0x1ea] */
/* @0x2aaac8 cmp r3, #0x3 */
/* @0x2aaaca beq 0x2aaae8 <png_do_read_transformations+0x1bc> */
/* @0x2aaacc ldr.w r3, [r4, #0x21c] */
/* @0x2aaad0 add.w r0, r4, #0x1c4 */
/* @0x2aaad4 ldr.w r1, [r4, #0x1b0] */
/* @0x2aaad8 ldr.w r2, [r4, #0x228] */
/* @0x2aaadc str r3, [sp] */
/* @0x2aaade adds r1, #0x1 */
/* @0x2aaae0 ldr.w r3, [r4, #0x234] */
/* @0x2aaae4 bl 0x2aa0d6 <png_do_gamma> */
/* @0x2aaae8 ldr.w r3, [r4, #0x134] */
/* @0x2aaaec lsls r0, r3, #0x15 */
/* @0x2aaaee bpl 0x2aaafe <png_do_read_transformations+0x1d2> */
/* @0x2aaaf0 ldr.w r1, [r4, #0x1b0] */
/* @0x2aaaf4 add.w r0, r4, #0x1c4 */
/* @0x2aaaf8 adds r1, #0x1 */
/* @0x2aaafa bl 0x2a8d28 <png_do_chop> */
/* @0x2aaafc .word 0xf8d4f915 */
/* @0x2aaafe ldr.w r3, [r4, #0x134] */
/* @0x2aab00 uasxeq r3, r9, r4 */
/* @0x2aab02 lsls r1, r3, #0x19 */
/* @0x2aab04 bpl 0x2aab2c <png_do_read_transformations+0x200> */
/* @0x2aab06 ldr.w r1, [r4, #0x1b0] */
/* @0x2aab08 .word 0xf50411b0 */
/* @0x2aab0a add.w r0, r4, #0x1c4 */
/* @0x2aab0c .word 0xf8d470e2 */
/* @0x2aab0e ldr.w r3, [r4, #0x2b4] */
/* @0x2aab10 strhlo r3, [r1, -r4] */
/* @0x2aab12 adds r1, #0x1 */
/* @0x2aab14 ldr.w r2, [r4, #0x2b0] */
/* @0x2aab18 bl 0x2aa854 <png_do_quantize> */
/* @0x2aab1c ldr.w r3, [r4, #0x1c8] */
/* @0x2aab20 cbnz r3, 0x2aab2c <png_do_read_transformations+0x200> */
/* @0x2aab22 ldr r1, [pc, #0x174] */
/* @0x2aab24 mov r0, r4 */
/* @0x2aab26 add r1, pc */
/* @0x2aab28 bl 0x2a642c <png_error> */
/* @0x2aab2c ldr.w r3, [r4, #0x134] */
/* @0x2aab30 lsls r2, r3, #0x1a */
/* @0x2aab32 bpl 0x2aab42 <png_do_read_transformations+0x216> */
/* @0x2aab34 ldr.w r1, [r4, #0x1b0] */
/* @0x2aab38 add.w r0, r4, #0x1c4 */
/* @0x2aab3c adds r1, #0x1 */
/* @0x2aab3e bl 0x2af85a <png_do_invert> */
/* @0x2aab40 .word 0xf8d4fe8c */
/* @0x2aab42 ldr.w r3, [r4, #0x134] */
/* @0x2aab44 .word 0x071b3134 */
/* @0x2aab46 lsls r3, r3, #0x1c */
/* @0x2aab48 bpl 0x2aab5c <png_do_read_transformations+0x230> */
/* @0x2aab4a ldr.w r1, [r4, #0x1b0] */
/* @0x2aab4c .word 0xf50411b0 */
/* @0x2aab4e add.w r0, r4, #0x1c4 */
/* @0x2aab50 .word 0xf20470e2 */
/* @0x2aab52 addw r2, r4, #0x245 */
/* @0x2aab54 .word 0x31012245 */
/* @0x2aab56 adds r1, #0x1 */
/* @0x2aab58 bl 0x2a8bf2 <png_do_unshift> */
/* @0x2aab5c ldr.w r3, [r4, #0x134] */
/* @0x2aab60 lsls r5, r3, #0x1d */
/* @0x2aab62 bpl 0x2aab72 <png_do_read_transformations+0x246> */
/* @0x2aab64 ldr.w r1, [r4, #0x1b0] */
/* @0x2aab68 add.w r0, r4, #0x1c4 */
/* @0x2aab6c adds r1, #0x1 */
/* @0x2aab6e bl 0x2a8b2e <png_do_unpack> */
/* @0x2aab70 .word 0xf8d4ffde */
/* @0x2aab72 ldr.w r3, [r4, #0x134] */
/* @0x2aab74 .word 0x07d83134 */
/* @0x2aab76 lsls r0, r3, #0x1f */
/* @0x2aab78 bpl 0x2aab88 <png_do_read_transformations+0x25c> */
/* @0x2aab7a ldr.w r1, [r4, #0x1b0] */
/* @0x2aab7c .word 0xf50411b0 */
/* @0x2aab7e add.w r0, r4, #0x1c4 */
/* @0x2aab80 smlattlo r1, r2, r0, r7 */
/* @0x2aab82 adds r1, #0x1 */
/* @0x2aab84 bl 0x2afae8 <png_do_bgr> */
/* @0x2aab88 ldr.w r3, [r4, #0x134] */
/* @0x2aab8c lsls r1, r3, #0xf */
/* @0x2aab8e bpl 0x2aab9e <png_do_read_transformations+0x272> */
/* @0x2aab90 ldr.w r1, [r4, #0x1b0] */
/* @0x2aab94 add.w r0, r4, #0x1c4 */
/* @0x2aab98 adds r1, #0x1 */
/* @0x2aab9a bl 0x2af8e4 <png_do_packswap> */
/* @0x2aab9c .word 0xf8d4fea3 */
/* @0x2aab9e ldr.w r3, [r4, #0x134] */
/* @0x2aaba0 ldrbeq r3, [r10], #-308 */
/* @0x2aaba2 lsls r2, r3, #0x11 */
/* @0x2aaba4 bpl 0x2aabbc <png_do_read_transformations+0x290> */
/* @0x2aaba6 ldr.w r3, [r4, #0x12c] */
/* @0x2aaba8 ldreq r3, [r11, #-0x12c] */
/* @0x2aabaa lsls r3, r3, #0x14 */
/* @0x2aabac bpl 0x2aabbc <png_do_read_transformations+0x290> */
/* @0x2aabae ldr.w r1, [r4, #0x1b0] */
/* @0x2aabb0 .word 0xf50411b0 */
/* @0x2aabb2 add.w r0, r4, #0x1c4 */
/* @0x2aabb4 smlattlo r1, r2, r0, r7 */
/* @0x2aabb6 adds r1, #0x1 */
/* @0x2aabb8 bl 0x2a90ac <png_do_gray_to_rgb> */
/* @0x2aabbc ldr.w r3, [r4, #0x134] */
/* @0x2aabc0 lsls r5, r3, #0x10 */
/* @0x2aabc2 bpl 0x2aabda <png_do_read_transformations+0x2ae> */
/* @0x2aabc4 ldr.w r1, [r4, #0x1b0] */
/* @0x2aabc8 add.w r0, r4, #0x1c4 */
/* @0x2aabcc ldrh.w r2, [r4, #0x1f2] */
/* @0x2aabd0 adds r1, #0x1 */
/* @0x2aabd2 ldr.w r3, [r4, #0x130] */
/* @0x2aabd4 .word 0xf7fe3130 */
/* @0x2aabd6 bl 0x2a8ebe <png_do_read_filler> */
/* @0x2aabd8 .word 0xf8d4f972 */
/* @0x2aabda ldr.w r3, [r4, #0x134] */
/* @0x2aabdc tsteq r8, #52, #2 */
/* @0x2aabde lsls r0, r3, #0xc */
/* @0x2aabe0 bpl 0x2aabf0 <png_do_read_transformations+0x2c4> */
/* @0x2aabe2 ldr.w r1, [r4, #0x1b0] */
/* @0x2aabe4 .word 0xf50411b0 */
/* @0x2aabe6 add.w r0, r4, #0x1c4 */
/* @0x2aabe8 smlattlo r1, r2, r0, r7 */
/* @0x2aabea adds r1, #0x1 */
/* @0x2aabec bl 0x2a8e3a <png_do_read_invert_alpha> */
/* @0x2aabf0 ldr.w r3, [r4, #0x134] */
/* @0x2aabf4 lsls r1, r3, #0xe */
/* @0x2aabf6 bpl 0x2aac06 <png_do_read_transformations+0x2da> */
/* @0x2aabf8 ldr.w r1, [r4, #0x1b0] */
/* @0x2aabfc add.w r0, r4, #0x1c4 */
/* @0x2aac00 adds r1, #0x1 */
/* @0x2aac02 bl 0x2a8d58 <png_do_read_swap_alpha> */
/* @0x2aac04 .word 0xf8d4f8a9 */
/* @0x2aac06 ldr.w r3, [r4, #0x134] */
/* @0x2aac08 .word 0x06da3134 */
/* @0x2aac0a lsls r2, r3, #0x1b */
/* @0x2aac0c bpl 0x2aac1c <png_do_read_transformations+0x2f0> */
/* @0x2aac0e ldr.w r1, [r4, #0x1b0] */
/* @0x2aac10 .word 0xf50411b0 */
/* @0x2aac12 add.w r0, r4, #0x1c4 */
/* @0x2aac14 smlattlo r1, r2, r0, r7 */
/* @0x2aac16 adds r1, #0x1 */
/* @0x2aac18 bl 0x2af8b6 <png_do_swap> */
/* @0x2aac1c ldr.w r3, [r4, #0x134] */
/* @0x2aac20 lsls r3, r3, #0xb */
/* @0x2aac22 bpl 0x2aac74 <png_do_read_transformations+0x348> */
/* @0x2aac24 ldr.w r5, [r4, #0x11c] */
/* @0x2aac28 cbz r5, 0x2aac38 <png_do_read_transformations+0x30c> */
/* @0x2aac2a ldr.w r2, [r4, #0x1b0] */
/* @0x2aac2c .word 0x462021b0 */
/* @0x2aac2e mov r0, r4 */
/* @0x2aac30 add.w r1, r4, #0x1c4 */
/* @0x2aac34 adds r2, #0x1 */
/* @0x2aac36 blx r5 */
/* @0x2aac38 ldrb.w r3, [r4, #0x128] */
/* @0x2aac3c cbz r3, 0x2aac42 <png_do_read_transformations+0x316> */
/* @0x2aac3e strb.w r3, [r4, #0x1cd] */
/* @0x2aac40 .word 0xf89431cd */
/* @0x2aac42 ldrb.w r3, [r4, #0x129] */
/* @0x2aac44 .word 0xb10b3129 */
/* @0x2aac46 cbz r3, 0x2aac4c <png_do_read_transformations+0x320> */
/* @0x2aac48 strb.w r3, [r4, #0x1ce] */
/* @0x2aac4c ldrb.w r2, [r4, #0x1ce] */
/* @0x2aac50 ldrb.w r3, [r4, #0x1cd] */
/* @0x2aac54 muls r3, r2, r3 */
/* @0x2aac56 ldr.w r2, [r4, #0x1c4] */
/* @0x2aac58 sbcslt r2, r11, #196, #2 */
/* @0x2aac5a uxtb r3, r3 */
/* @0x2aac5c strb.w r3, [r4, #0x1cf] */
/* @0x2aac60 cmp r3, #0x7 */
/* @0x2aac62 bls 0x2aac6a <png_do_read_transformations+0x33e> */
/* @0x2aac64 lsrs r3, r3, #0x3 */
/* @0x2aac66 muls r2, r3, r2 */
/* @0x2aac68 b 0x2aac70 <png_do_read_transformations+0x344> */
/* @0x2aac6a muls r2, r3, r2 */
/* @0x2aac6c adds r2, #0x7 */
/* @0x2aac6e lsrs r2, r2, #0x3 */
/* @0x2aac70 str.w r2, [r4, #0x1c8] */
/* @0x2aac74 ldr r2, [sp, #0x54] */
/* @0x2aac76 ldr r3, [r6] */
/* @0x2aac78 cmp r2, r3 */
/* @0x2aac7a beq 0x2aac80 <png_do_read_transformations+0x354> */
/* @0x2aac7c blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2aac80 add sp, #0x58 */
/* @0x2aac82 pop {r4, r5, r6, pc} */
/* @0x2aac84 adds r0, #0x24 */
/* @0x2aac86 movs r4, r2 */
/* @0x2aac88 movs r0, #0xf1 */
/* @0x2aac8a movs r6, r1 */
/* @0x2aac8c movs r0, #0xe6 */
/* @0x2aac8e movs r6, r1 */
/* @0x2aac90 movs r0, #0x77 */
/* @0x2aac92 movs r6, r1 */
/* @0x2aac94 movs r0, #0x5f */
/* @0x2aac96 movs r6, r1 */
/* @0x2aac98 subs r2, r1, #0x6 */
/* @0x2aac9a movs r6, r1 */

/* ── FUNC 0x2aac9c · anon_2aac9c · size=0 · insn=1 */
/* @0x2aac9c andeq r0, r0, r0 */

/* ── FUNC 0x2aaca0 · png_build_gamma_table · size=1236 · insn=494 */
/* @0x2aaca0 cmp r1, #0x8 */
/* @0x2aaca2 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2aaca4 stc p15, c4, [sp, #-960]! */
/* @0x2aaca6 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2aaca8 strmi r8, [r4], -lr, lsl #22 */
/* @0x2aacaa mov r4, r0 */
/* @0x2aacac vldr s13, [r0, #548] */
/* @0x2aacb0 sub sp, #0xc */
/* @0x2aacb2 vldr d9, [pc, #676] */
/* @0x2aacb4 .word 0xeeb79ba9 */
/* @0x2aacb6 vmov.f64 d8, #1.000000e+00 */
/* @0x2aacb8 .word 0xf2008b00 */
/* @0x2aacba bhi.w 0x2aae08 <png_build_gamma_table+0x168> */
/* @0x2aacbc cdp p0, #0xb, c8, c7, c5, #0x5 */
/* @0x2aacbe vcvt.f64.f32 d7, s13 */
/* @0x2aacc0 vcmpe.f32 s14, s13 */
/* @0x2aacc2 vcmpe.f64 d7, d9 */
/* @0x2aacc4 vsqrt.f64 d23, d9 */
/* @0x2aacc6 vmrs APSR_nzcv, fpscr */
/* @0x2aacc8 vstrle s30, [r8, #-64] */
/* @0x2aacca ble 0x2aacde <png_build_gamma_table+0x3e> */
/* @0x2aaccc vldr s24, [r0, #544] */
/* @0x2aacd0 vmul.f32 s24, s13, s24 */
/* @0x2aacd4 vcvt.f64.f32 d12, s24 */
/* @0x2aacd8 vdiv.f64 d12, d8, d12 */
/* @0x2aacdc b 0x2aace2 <png_build_gamma_table+0x42> */
/* @0x2aacde vmov.f64 d12, d8 */
/* @0x2aace0 strtmi r12, [r0], -r8, asr #22 */
/* @0x2aace2 mov r0, r4 */
/* @0x2aace4 mov.w r1, #0x100 */
/* @0x2aace8 bl 0x2a6ca0 <png_malloc> */
/* @0x2aacec movs r5, #0x0 */
/* @0x2aacee vmov.f64 d14, #5.000000e-01 */
/* @0x2aacf0 vldr d14, [pc] */
/* @0x2aacf2 vldr d11, [pc, #620] */
/* @0x2aacf4 .word 0xf8c4bb9b */
/* @0x2aacf6 str.w r0, [r4, #0x228] */
/* @0x2aacf8 cdp p2, #0x0, c0, c6, c8, #0x1 */
/* @0x2aacfa vmov s12, r5 */
/* @0x2aacfc .word 0xf8d45a10 */
/* @0x2aacfe ldr.w r6, [r4, #0x228] */
/* @0x2aad00 mrrc p2, #0x2, r6, r3, c8 */
/* @0x2aad02 vmov r2, r3, d12 */
/* @0x2aad04 vldr d2, [pc, #112] */
/* @0x2aad06 vldr d10, [pc, #600] */
/* @0x2aad08 .word 0xeeb8ab96 */
/* @0x2aad0a vcvt.f64.s32 d7, s12 */
/* @0x2aad0c .word 0xee877bc6 */
/* @0x2aad0e vdiv.f64 d6, d7, d11 */
/* @0x2aad10 .word 0xec516b0b */
/* @0x2aad12 vmov r0, r1, d6 */
/* @0x2aad14 .word 0xf60b0b16 */
/* @0x2aad16 blx 0xb6784 <pow@plt> */
/* @0x2aad18 mrc p13, #0x5, lr, c0, c6, #0x1 */
/* @0x2aad1a vmov.f64 d7, d14 */
/* @0x2aad1c .word 0xeeb67b4e */
/* @0x2aad1e vmov.f64 d13, #5.000000e-01 */
/* @0x2aad20 .word 0xec41db00 */
/* @0x2aad22 vmov d6, r0, r1 */
/* @0x2aad24 .word 0xee060b16 */
/* @0x2aad26 vmla.f64 d7, d6, d11 */
/* @0x2aad28 vmov.f64 d23, #-2.109375e-01 */
/* @0x2aad2a vcvt.u32.f64 s13, d7 */
/* @0x2aad2c vnmla.f64 d6, d22, d7 */
/* @0x2aad2e vmov r3, s13 */
/* @0x2aad30 ldrbpl r3, [r3, #-0xa90]! */
/* @0x2aad32 strb r3, [r6, r5] */
/* @0x2aad34 adds r5, #0x1 */
/* @0x2aad36 cmp.w r5, #0x100 */
/* @0x2aad38 bicsle r7, lr, r0, lsl #31 */
/* @0x2aad3a bne 0x2aacfa <png_build_gamma_table+0x5a> */
/* @0x2aad3c ldr.w r2, [r4, #0x134] */
/* @0x2aad40 ldr r3, [pc, #0x22c] */
/* @0x2aad42 ands r3, r2 */
/* @0x2aad44 cmp r3, #0x0 */
/* @0x2aad46 beq.w 0x2ab152 <png_build_gamma_table+0x4b2> */
/* @0x2aad48 ldc p2, c8, [r4, #16] */
/* @0x2aad4a vldr s22, [r4, #544] */
/* @0x2aad4c .word 0xeeb7ba88 */
/* @0x2aad4e vcvt.f64.f32 d11, s22 */
/* @0x2aad50 strtmi r11, [r9], -r11, asr #21 */
/* @0x2aad52 mov r1, r5 */
/* @0x2aad54 mov r0, r4 */
/* @0x2aad56 bl 0x2a6ca0 <png_malloc> */
/* @0x2aad58 strhs pc, [r0, #-0xfa3] */
/* @0x2aad5a movs r5, #0x0 */
/* @0x2aad5c vdiv.f64 d11, d8, d11 */
/* @0x2aad60 str.w r0, [r4, #0x230] */
/* @0x2aad64 vmov s12, r5 */
/* @0x2aad68 ldr.w r6, [r4, #0x230] */
/* @0x2aad6c vmov r2, r3, d11 */
/* @0x2aad70 vcvt.f64.s32 d7, s12 */
/* @0x2aad74 vdiv.f64 d6, d7, d10 */
/* @0x2aad78 vmov r0, r1, d6 */
/* @0x2aad7c blx 0xb6784 <pow@plt> */
/* @0x2aad80 vmov.f64 d7, d13 */
/* @0x2aad84 vmov d6, r0, r1 */
/* @0x2aad88 vmla.f64 d7, d6, d10 */
/* @0x2aad8c vcvt.u32.f64 s13, d7 */
/* @0x2aad90 vmov r3, s13 */
/* @0x2aad94 strb r3, [r6, r5] */
/* @0x2aad96 adds r5, #0x1 */
/* @0x2aad98 cmp.w r5, #0x100 */
/* @0x2aad9c bne 0x2aad64 <png_build_gamma_table+0xc4> */
/* @0x2aad9e mov r1, r5 */
/* @0x2aada0 mov r0, r4 */
/* @0x2aada2 bl 0x2a6ca0 <png_malloc> */
/* @0x2aada4 ldc p15, c15, [r4, #500] */
/* @0x2aada6 vldr s14, [r4, #548] */
/* @0x2aada8 .word 0xeeb77a89 */
/* @0x2aadaa vcvt.f64.f32 d7, s14 */
/* @0x2aadac strhs r7, [r0, #-0xac7] */
/* @0x2aadae movs r5, #0x0 */
/* @0x2aadb0 vcmpe.f64 d7, d9 */
/* @0x2aadb4 vmrs APSR_nzcv, fpscr */
/* @0x2aadb8 ite gt */
/* @0x2aadba vdivgt.f64 d8, d8, d7 */
/* @0x2aadbc vldr d8, [r4, #28] */
/* @0x2aadbe vldrle s16, [r4, #544] */
/* @0x2aadc0 .word 0xf8c48a88 */
/* @0x2aadc2 str.w r0, [r4, #0x22c] */
/* @0x2aadc4 svclt #0xd8022c */
/* @0x2aadc6 it le */
/* @0x2aadc8 vcvtle.f64.f32 d8, s16 */
/* @0x2aadcc vmov s12, r5 */
/* @0x2aadd0 ldr.w r6, [r4, #0x22c] */
/* @0x2aadd4 vmov r2, r3, d8 */
/* @0x2aadd8 vcvt.f64.s32 d7, s12 */
/* @0x2aaddc vdiv.f64 d6, d7, d10 */
/* @0x2aade0 vmov r0, r1, d6 */
/* @0x2aade4 blx 0xb6784 <pow@plt> */
/* @0x2aade8 vmov.f64 d7, d13 */
/* @0x2aadec vmov d6, r0, r1 */
/* @0x2aadf0 vmla.f64 d7, d6, d10 */
/* @0x2aadf4 vcvt.u32.f64 s13, d7 */
/* @0x2aadf8 vmov r3, s13 */
/* @0x2aadfc strb r3, [r6, r5] */
/* @0x2aadfe adds r5, #0x1 */
/* @0x2aae00 cmp.w r5, #0x100 */
/* @0x2aae04 bne 0x2aadcc <png_build_gamma_table+0x12c> */
/* @0x2aae06 b 0x2ab152 <png_build_gamma_table+0x4b2> */
/* @0x2aae08 ldrb.w r3, [r0, #0x1ea] */
/* @0x2aae0c lsls r2, r3, #0x1e */
/* @0x2aae0e bpl 0x2aae28 <png_build_gamma_table+0x188> */
/* @0x2aae10 ldrb.w r3, [r0, #0x240] */
/* @0x2aae14 ldrb.w r5, [r0, #0x241] */
/* @0x2aae18 cmp r5, r3 */
/* @0x2aae1a it lt */
/* @0x2aae1c movlt r5, r3 */
/* @0x2aae1e ldrb.w r3, [r0, #0x242] */
/* @0x2aae20 adcmi r3, r11, #536870916 */
/* @0x2aae22 cmp r3, r5 */
/* @0x2aae24 bgt 0x2aae30 <png_build_gamma_table+0x190> */
/* @0x2aae26 b 0x2aae2c <png_build_gamma_table+0x18c> */
/* @0x2aae28 ldrb.w r5, [r0, #0x243] */
/* @0x2aae2c cbnz r5, 0x2aae32 <png_build_gamma_table+0x192> */
/* @0x2aae2e b 0x2aae36 <png_build_gamma_table+0x196> */
/* @0x2aae30 mov r5, r3 */
/* @0x2aae32 rsb.w r5, r5, #0x10 */
/* @0x2aae34 .word 0xf8d40510 */
/* @0x2aae36 ldr.w r3, [r4, #0x134] */
/* @0x2aae38 ldrbeq r3, [r11, #-0x134] */
/* @0x2aae3a lsls r3, r3, #0x15 */
/* @0x2aae3c bpl 0x2aae42 <png_build_gamma_table+0x1a2> */
/* @0x2aae3e cmp r5, #0x4 */
/* @0x2aae40 ble 0x2aae4c <png_build_gamma_table+0x1ac> */
/* @0x2aae42 cmp r5, #0x8 */
/* @0x2aae44 bgt 0x2aae50 <png_build_gamma_table+0x1b0> */
/* @0x2aae46 bic.w r5, r5, r5, asr #31 */
/* @0x2aae48 and r7, r2, r5, ror #11 */
/* @0x2aae4a b 0x2aae52 <png_build_gamma_table+0x1b2> */
/* @0x2aae4c movs r5, #0x5 */
/* @0x2aae4e b 0x2aae52 <png_build_gamma_table+0x1b2> */
/* @0x2aae50 movs r5, #0x8 */
/* @0x2aae52 vcvt.f64.f32 d7, s13 */
/* @0x2aae54 .word 0xf1c57ae6 */
/* @0x2aae56 rsb.w r9, r5, #0x8 */
/* @0x2aae58 strhs r0, [r1], -r8, lsl #18 */
/* @0x2aae5a movs r6, #0x1 */
/* @0x2aae5c str.w r5, [r4, #0x21c] */
/* @0x2aae60 lsl.w r6, r6, r9 */
/* @0x2aae64 vcmpe.f64 d7, d9 */
/* @0x2aae68 vmrs APSR_nzcv, fpscr */
/* @0x2aae6c ble 0x2aae80 <png_build_gamma_table+0x1e0> */
/* @0x2aae6e vldr s20, [r4, #544] */
/* @0x2aae70 vmul.f32 s20, s13, s16 */
/* @0x2aae72 vmul.f32 s20, s13, s20 */
/* @0x2aae74 .word 0xeeb7aa8a */
/* @0x2aae76 vcvt.f64.f32 d10, s20 */
/* @0x2aae78 .word 0xee88aaca */
/* @0x2aae7a vdiv.f64 d10, d8, d10 */
/* @0x2aae7c and r10, r1, r10, lsl #22 */
/* @0x2aae7e b 0x2aae84 <png_build_gamma_table+0x1e4> */
/* @0x2aae80 vmov.f64 d10, #1.000000e+00 */
/* @0x2aae84 lsls r2, r6, #0x2 */
/* @0x2aae86 mov r0, r4 */
/* @0x2aae88 str r2, [sp] */
/* @0x2aae8a mov r1, r2 */
/* @0x2aae8c bl 0x2a6cd8 <png_calloc> */
/* @0x2aae90 ldr.w r7, [r4, #0x134] */
/* @0x2aae94 ands r7, r7, #0x480 */
/* @0x2aae98 str.w r0, [r4, #0x234] */
/* @0x2aae9c beq 0x2aaf74 <png_build_gamma_table+0x2d4> */
/* @0x2aae9e movs r7, #0x0 */
/* @0x2aaea0 mov r0, r4 */
/* @0x2aaea2 mov.w r1, #0x200 */
/* @0x2aaea4 .word 0xf8d47100 */
/* @0x2aaea6 ldr.w r8, [r4, #0x234] */
/* @0x2aaea8 .word 0xf7fb8234 */
/* @0x2aaeaa bl 0x2a6ca0 <png_malloc> */
/* @0x2aaeac .word 0xf848fef9 */
/* @0x2aaeae str.w r0, [r8, r7, lsl #2] */
/* @0x2aaeb0 strlo r0, [r1, -r7, lsr #32] */
/* @0x2aaeb2 adds r7, #0x1 */
/* @0x2aaeb4 cmp r7, r6 */
/* @0x2aaeb6 blt 0x2aaea0 <png_build_gamma_table+0x200> */
/* @0x2aaeb8 vdiv.f64 d10, d8, d10 */
/* @0x2aaebc mov.w r11, #0xff */
/* @0x2aaec0 movs r7, #0x0 */
/* @0x2aaec2 lsl.w r10, r6, #0x8 */
/* @0x2aaec4 blx 0x15756e4 <b2_toiTime+0xe1c240> */
/* @0x2aaec6 asr.w r11, r11, r5 */
/* @0x2aaec8 ldrtmi pc, [r8], r5, lsl #22 */
/* @0x2aaeca mov r8, r7 */
/* @0x2aaecc vldr d12, [pc, #152] */
/* @0x2aaed0 vmov.f64 d11, #5.000000e-01 */
/* @0x2aaed4 vmov s12, r8 */
/* @0x2aaed8 vmov r2, r3, d10 */
/* @0x2aaedc vcvt.f64.s32 d7, s12 */
/* @0x2aaee0 vadd.f64 d7, d7, d11 */
/* @0x2aaee4 vmul.f64 d6, d7, d12 */
/* @0x2aaee8 vmov r0, r1, d6 */
/* @0x2aaeec blx 0xb6784 <pow@plt> */
/* @0x2aaef0 orr.w r2, r8, r8, lsl #8 */
/* @0x2aaef4 vmov s13, r10 */
/* @0x2aaef8 uxth r2, r2 */
/* @0x2aaefa vcvt.f64.s32 d7, s13 */
/* @0x2aaefc .word 0xec417be6 */
/* @0x2aaefe vmov d6, r0, r1 */
/* @0x2aaf00 .word 0xee260b16 */
/* @0x2aaf02 vmul.f64 d7, d6, d7 */
/* @0x2aaf04 vmov.f64 d7, #-1.796875e-01 */
/* @0x2aaf06 vcvt.u32.f64 s14, d7 */
/* @0x2aaf08 vnmla.f64 d7, d23, d7 */
/* @0x2aaf0a vmov r3, s14 */
/* @0x2aaf0c addsmi r3, pc, #16, #20 */
/* @0x2aaf0e cmp r7, r3 */
/* @0x2aaf10 bhi 0x2aaf2a <png_build_gamma_table+0x28a> */
/* @0x2aaf12 ldr.w r3, [r4, #0x234] */
/* @0x2aaf14 b 0x4777ec <g_RomDisk+0x7ffcc> */
/* @0x2aaf16 and.w r0, r7, r11 */
/* @0x2aaf18 blx 0xc6af4c <b2_toiTime+0x511aa8> */
/* @0x2aaf1a lsr.w r1, r7, r9 */
/* @0x2aaf1c strlo pc, [r1, -r9, lsl #2] */
/* @0x2aaf1e adds r7, #0x1 */
/* @0x2aaf20 ldr.w r3, [r3, r0, lsl #2] */
/* @0x2aaf24 strh.w r2, [r3, r1, lsl #1] */
/* @0x2aaf28 b 0x2aaf0a <png_build_gamma_table+0x26a> */
/* @0x2aaf2a add.w r8, r8, #0x1 */
/* @0x2aaf2c .word 0xf5b80801 */
/* @0x2aaf2e cmp.w r8, #0x100 */
/* @0x2aaf30 bicle r7, pc, r0, lsl #31 */
/* @0x2aaf32 bne 0x2aaed4 <png_build_gamma_table+0x234> */
/* @0x2aaf34 movw r2, #0xffff */
/* @0x2aaf38 cmp r7, r10 */
/* @0x2aaf3a bhs 0x2aaffa <png_build_gamma_table+0x35a> */
/* @0x2aaf3c ldr.w r3, [r4, #0x234] */
/* @0x2aaf40 and.w r0, r7, r11 */
/* @0x2aaf44 lsr.w r1, r7, r9 */
/* @0x2aaf48 adds r7, #0x1 */
/* @0x2aaf4a ldr.w r3, [r3, r0, lsl #2] */
/* @0x2aaf4c .word 0xf8233020 */
/* @0x2aaf4e strh.w r2, [r3, r1, lsl #1] */
/* @0x2aaf50 .word 0xe7f12011 */
/* @0x2aaf52 b 0x2aaf38 <png_build_gamma_table+0x298> */
/* @0x2aaf54 nop.w */
/* @0x2aaf58 stc p0, c10, [sp, #724] */
/* @0x2aaf5c stm r6!, {r0, r1, r2, r4, r5, r6, r7} */
/* @0x2aaf5e subs r6, #0xb0 */
/* @0x2aaf60 movs r0, r0 */
/* @0x2aaf62 movs r0, r0 */
/* @0x2aaf64 b 0x2aaf68 <png_build_gamma_table+0x2c8> */
/* @0x2aaf66 eors r7, r5 */
/* @0x2aaf68 movs r0, r0 */
/* @0x2aaf6a movs r0, r0 */
/* @0x2aaf6c movs r0, r0 */
/* @0x2aaf6e subs r7, #0x70 */
/* @0x2aaf70 lsls r0, r0, #0x2 */
/* @0x2aaf72 lsls r0, r4, #0x1 */
/* @0x2aaf74 vmov.f64 d12, #5.000000e-01 */
/* @0x2aaf78 ldr.w r9, [pc, #0x1f0] */
/* @0x2aaf7c vldr d11, [pc, #480] */
/* @0x2aaf80 add r9, pc */
/* @0x2aaf82 add.w r9, r9, r5, lsl #2 */
/* @0x2aaf84 strtmi r0, [r0], -r5, lsl #19 */
/* @0x2aaf86 mov r0, r4 */
/* @0x2aaf88 mov.w r1, #0x200 */
/* @0x2aaf8c ldr.w r8, [r4, #0x234] */
/* @0x2aaf90 bl 0x2a6ca0 <png_malloc> */
/* @0x2aaf94 ldr.w r3, [r9, #0x18] */
/* @0x2aaf98 lsl.w r11, r7, #0x2 */
/* @0x2aaf9c muls r3, r7, r3 */
/* @0x2aaf9e lsr.w r10, r3, #0x4 */
/* @0x2aafa0 .word 0xf8481a13 */
/* @0x2aafa2 str.w r0, [r8, r7, lsl #2] */
/* @0x2aafa4 .word 0xf04f0027 */
/* @0x2aafa6 mov.w r8, #0x0 */
/* @0x2aafa8 bl 0x52cfb0 <SrcVerts+0x89ff4> */
/* @0x2aafaa add.w r2, r10, r8, lsl #8 */
/* @0x2aafac .word 0xf8d42208 */
/* @0x2aafae ldr.w r3, [r4, #0x234] */
/* @0x2aafb0 mcr p2, #0x0, r3, c7, c4, #0x1 */
/* @0x2aafb2 vmov s14, r2 */
/* @0x2aafb4 .word 0xf8532a10 */
/* @0x2aafb6 ldr.w r3, [r3, r11] */
/* @0x2aafb8 cdp p0, #0xb, c3, c8, c11, #0x0 */
/* @0x2aafba vcvt.f64.s32 d7, s14 */
/* @0x2aafbc movwls r7, #0x1bc7 */
/* @0x2aafbe str r3, [sp, #0x4] */
/* @0x2aafc0 vmov r2, r3, d10 */
/* @0x2aafc4 vdiv.f64 d6, d7, d11 */
/* @0x2aafc8 vmov r0, r1, d6 */
/* @0x2aafcc blx 0xb6784 <pow@plt> */
/* @0x2aafd0 ldr r2, [sp, #0x4] */
/* @0x2aafd2 vmov.f64 d7, d12 */
/* @0x2aafd4 .word 0xec417b4c */
/* @0x2aafd6 vmov d6, r0, r1 */
/* @0x2aafd8 .word 0xee060b16 */
/* @0x2aafda vmla.f64 d7, d6, d11 */
/* @0x2aafdc vmov.f64 d23, #-2.109375e-01 */
/* @0x2aafde vcvt.u32.f64 s13, d7 */
/* @0x2aafe0 vnmla.f64 d6, d22, d7 */
/* @0x2aafe2 vmov r3, s13 */
/* @0x2aafe4 .word 0xf8223a90 */
/* @0x2aafe6 strh.w r3, [r2, r8, lsl #1] */
/* @0x2aafe8 .word 0xf1083018 */
/* @0x2aafea add.w r8, r8, #0x1 */
/* @0x2aafec .word 0xf5b80801 */
/* @0x2aafee cmp.w r8, #0x100 */
/* @0x2aaff0 bicsle r7, r10, r0, lsl #31 */
/* @0x2aaff2 bne 0x2aafaa <png_build_gamma_table+0x30a> */
/* @0x2aaff4 adds r7, #0x1 */
/* @0x2aaff6 cmp r7, r6 */
/* @0x2aaff8 blt 0x2aaf86 <png_build_gamma_table+0x2e6> */
/* @0x2aaffa ldr.w r2, [r4, #0x134] */
/* @0x2aaffc blmi 0x19334d4 <b2_toiTime+0x11da030> */
/* @0x2aaffe ldr r3, [pc, #0x168] */
/* @0x2ab000 ands r3, r2 */
/* @0x2ab002 cmp r3, #0x0 */
/* @0x2ab004 beq.w 0x2ab152 <png_build_gamma_table+0x4b2> */
/* @0x2ab008 vldr s26, [r4, #544] */
/* @0x2ab00c vcvt.f64.f32 d13, s26 */
/* @0x2ab010 mov r0, r4 */
/* @0x2ab012 ldr r1, [sp] */
/* @0x2ab014 bl 0x2a6cd8 <png_calloc> */
/* @0x2ab018 ldr.w r9, [pc, #0x154] */
/* @0x2ab01c movs r7, #0x0 */
/* @0x2ab01e vldr d11, [pc, #320] */
/* @0x2ab020 ldrbtmi r11, [r9], #2896 */
/* @0x2ab022 add r9, pc */
/* @0x2ab024 add.w r9, r9, r5, lsl #2 */
/* @0x2ab028 vdiv.f64 d13, d8, d13 */
/* @0x2ab02c str.w r0, [r4, #0x23c] */
/* @0x2ab030 vmov.f64 d12, #5.000000e-01 */
/* @0x2ab034 mov r0, r4 */
/* @0x2ab036 mov.w r1, #0x200 */
/* @0x2ab038 .word 0xf8d47100 */
/* @0x2ab03a ldr.w r5, [r4, #0x23c] */
/* @0x2ab03c .word 0xf7fb523c */
/* @0x2ab03e bl 0x2a6ca0 <png_malloc> */
/* @0x2ab040 b 0x16aa904 <b2_toiTime+0xf51460> */
/* @0x2ab042 lsl.w r11, r7, #0x2 */
/* @0x2ab044 .word 0xf04f0b87 */
/* @0x2ab046 mov.w r8, #0x0 */
/* @0x2ab048 .word 0xf8450800 */
/* @0x2ab04a str.w r0, [r5, r7, lsl #2] */
/* @0x2ab04c .word 0xf8d90027 */
/* @0x2ab04e ldr.w r5, [r9, #0x18] */
/* @0x2ab050 blx 0x3ff0ba <g_RomDisk+0x789a> */
/* @0x2ab052 mul r12, r5, r7 */
/* @0x2ab054 b 0x16aa078 <b2_toiTime+0xf50bd4> */
/* @0x2ab056 lsr.w r10, r12, #0x4 */
/* @0x2ab058 .word 0xf8d41a1c */
/* @0x2ab05a ldr.w r3, [r4, #0x23c] */
/* @0x2ab05c mrc p2, #0x5, r3, c6, c12, #0x1 */
/* @0x2ab05e vmov.f64 d14, #5.000000e-01 */
/* @0x2ab060 vldr d14, [pc] */
/* @0x2ab062 vldr d10, [pc, #252] */
/* @0x2ab064 .word 0xf853ab3f */
/* @0x2ab066 ldr.w r3, [r3, r11] */
/* @0x2ab068 movwls r3, #0x100b */
/* @0x2ab06a str r3, [sp, #0x4] */
/* @0x2ab06c add.w r3, r10, r8, lsl #8 */
/* @0x2ab070 vmov s14, r3 */
/* @0x2ab074 vmov r2, r3, d13 */
/* @0x2ab078 vcvt.f64.s32 d7, s14 */
/* @0x2ab07c vdiv.f64 d6, d7, d11 */
/* @0x2ab080 vmov r0, r1, d6 */
/* @0x2ab084 blx 0xb6784 <pow@plt> */
/* @0x2ab088 ldr r2, [sp, #0x4] */
/* @0x2ab08a vmov.f64 d7, d12 */
/* @0x2ab08c .word 0xec417b4c */
/* @0x2ab08e vmov d6, r0, r1 */
/* @0x2ab090 .word 0xee060b16 */
/* @0x2ab092 vmla.f64 d7, d6, d11 */
/* @0x2ab094 vmov.f64 d23, #-2.109375e-01 */
/* @0x2ab096 vcvt.u32.f64 s13, d7 */
/* @0x2ab098 vnmla.f64 d6, d22, d7 */
/* @0x2ab09a vmov r3, s13 */
/* @0x2ab09c .word 0xf8223a90 */
/* @0x2ab09e strh.w r3, [r2, r8, lsl #1] */
/* @0x2ab0a0 .word 0xf1083018 */
/* @0x2ab0a2 add.w r8, r8, #0x1 */
/* @0x2ab0a4 .word 0xf5b80801 */
/* @0x2ab0a6 cmp.w r8, #0x100 */
/* @0x2ab0a8 bicsle r7, r6, r0, lsl #31 */
/* @0x2ab0aa bne 0x2ab05a <png_build_gamma_table+0x3ba> */
/* @0x2ab0ac adds r7, #0x1 */
/* @0x2ab0ae cmp r7, r6 */
/* @0x2ab0b0 blt 0x2ab034 <png_build_gamma_table+0x394> */
/* @0x2ab0b2 vldr s14, [r4, #548] */
/* @0x2ab0b4 .word 0xeeb77a89 */
/* @0x2ab0b6 vcvt.f64.f32 d7, s14 */
/* @0x2ab0b8 strtmi r7, [r0], -r7, asr #21 */
/* @0x2ab0ba mov r0, r4 */
/* @0x2ab0bc ldr r1, [sp] */
/* @0x2ab0be mov.w r9, #0x0 */
/* @0x2ab0c0 strbmi r0, [pc], -r0, lsl #18 */
/* @0x2ab0c2 mov r7, r9 */
/* @0x2ab0c4 vcmpe.f64 d7, d9 */
/* @0x2ab0c8 vmrs APSR_nzcv, fpscr */
/* @0x2ab0cc itet le */
/* @0x2ab0ce vldrle s16, [r4, #544] */
/* @0x2ab0d0 vdiv.f32 s16, s17, s16 */
/* @0x2ab0d2 vdivgt.f64 d8, d8, d7 */
/* @0x2ab0d4 vmov.f64 d8, #1.437500e+00 */
/* @0x2ab0d6 vcvtle.f64.f32 d8, s16 */
/* @0x2ab0d8 .word 0xf7fb8ac8 */
/* @0x2ab0da bl 0x2a6cd8 <png_calloc> */
/* @0x2ab0dc .word 0xf8c4fdfd */
/* @0x2ab0de str.w r0, [r4, #0x238] */
/* @0x2ab0e0 qasxmi r0, r0, r8 */
/* @0x2ab0e2 mov r0, r4 */
/* @0x2ab0e4 mov.w r1, #0x200 */
/* @0x2ab0e8 ldr.w r8, [r4, #0x238] */
/* @0x2ab0ec bl 0x2a6ca0 <png_malloc> */
/* @0x2ab0f0 lsl.w r11, r7, #0x2 */
/* @0x2ab0f4 lsr.w r10, r9, #0x4 */
/* @0x2ab0f8 str.w r0, [r8, r7, lsl #2] */
/* @0x2ab0fc mov.w r8, #0x0 */
/* @0x2ab100 ldr.w r3, [r4, #0x238] */
/* @0x2ab104 ldr.w r3, [r3, r11] */
/* @0x2ab108 str r3, [sp] */
/* @0x2ab10a add.w r3, r10, r8, lsl #8 */
/* @0x2ab10c cdp p3, #0x0, c2, c7, c8, #0x0 */
/* @0x2ab10e vmov s14, r3 */
/* @0x2ab110 vmov r3, r3, s0, s1 */
/* @0x2ab112 vmov r2, r3, d8 */
/* @0x2ab114 .word 0xeeb82b18 */
/* @0x2ab116 vcvt.f64.s32 d7, s14 */
/* @0x2ab118 .word 0xee877bc7 */
/* @0x2ab11a vdiv.f64 d6, d7, d10 */
/* @0x2ab11c .word 0xec516b0a */
/* @0x2ab11e vmov r0, r1, d6 */
/* @0x2ab120 .word 0xf60b0b16 */
/* @0x2ab122 blx 0xb6784 <pow@plt> */
/* @0x2ab124 bls 0x2e5dec <FT_Face_GetVariantsOfChar+0xe> */
/* @0x2ab126 ldr r2, [sp] */
/* @0x2ab128 vmov.f64 d7, d14 */
/* @0x2ab12c vmov d6, r0, r1 */
/* @0x2ab130 vmla.f64 d7, d6, d10 */
/* @0x2ab134 vcvt.u32.f64 s13, d7 */
/* @0x2ab138 vmov r3, s13 */
/* @0x2ab13c strh.w r3, [r2, r8, lsl #1] */
/* @0x2ab140 add.w r8, r8, #0x1 */
/* @0x2ab144 cmp.w r8, #0x100 */
/* @0x2ab148 bne 0x2ab100 <png_build_gamma_table+0x460> */
/* @0x2ab14a adds r7, #0x1 */
/* @0x2ab14c add r9, r5 */
/* @0x2ab14e cmp r7, r6 */
/* @0x2ab150 blt 0x2ab0e2 <png_build_gamma_table+0x442> */
/* @0x2ab152 add sp, #0xc */
/* @0x2ab154 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x2ab158 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ab15c nop.w */
/* @0x2ab160 movs r0, r0 */
/* @0x2ab162 movs r0, r0 */
/* @0x2ab164 vmla.i32 q10, q8, d15[1] */
/* @0x2ab168 lsls r0, r0, #0x2 */
/* @0x2ab16a lsls r0, r4, #0x1 */
/* @0x2ab16c ldr r2, [pc, #0xb0] */
/* @0x2ab16e movs r6, r1 */
/* @0x2ab170 ldr r1, [pc, #0x228] */
/* @0x2ab172 movs r6, r1 */

/* ── FUNC 0x2ab174 · anon_2ab174 · size=0 · insn=1 */
/* @0x2ab174 andhi pc, r0, pc, lsr #7 */

/* ── FUNC 0x2ab178 · png_init_read_transformations · size=2172 · insn=922 */
/* @0x2ab178 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ab17c vpush {d8, d9, d10, d11} */
/* @0x2ab180 mov r4, r0 */
/* @0x2ab182 ldr.w r3, [r0, #0x134] */
/* @0x2ab184 addlt r3, r3, r4, lsr r1 */
/* @0x2ab186 sub sp, #0xc */
/* @0x2ab188 ldrb.w r10, [r0, #0x1ea] */
/* @0x2ab18c lsls r5, r3, #0x17 */
/* @0x2ab18e bpl 0x2ab1a4 <png_init_read_transformations+0x2c> */
/* @0x2ab190 tst.w r10, #0x2 */
/* @0x2ab194 bne 0x2ab1a4 <png_init_read_transformations+0x2c> */
/* @0x2ab196 ldr.w r2, [r0, #0x12c] */
/* @0x2ab198 vst4.8 {d18, d20, d22, d24}, [r2:128], r12 */
/* @0x2ab19a orr r2, r2, #0x800 */
/* @0x2ab19c .word 0xf8c06200 */
/* @0x2ab19e str.w r2, [r0, #0x12c] */
/* @0x2ab1a0 ands r2, r6, r12, lsr #2 */
/* @0x2ab1a2 b 0x2ab1d2 <png_init_read_transformations+0x5a> */
/* @0x2ab1a4 and r2, r3, #0x4180 */
/* @0x2ab1a8 cmp.w r2, #0x4080 */
/* @0x2ab1ac bne 0x2ab1d2 <png_init_read_transformations+0x5a> */
/* @0x2ab1ae ldrh.w r2, [r4, #0x1fe] */
/* @0x2ab1b0 rfeia r4! */
/* @0x2ab1b2 ldrh.w r1, [r4, #0x200] */
/* @0x2ab1b4 addsmi r1, r1, #0, #4 */
/* @0x2ab1b6 cmp r1, r2 */
/* @0x2ab1b8 bne 0x2ab1d2 <png_init_read_transformations+0x5a> */
/* @0x2ab1ba ldrh.w r2, [r4, #0x202] */
/* @0x2ab1bc addmi r2, r10, #536870912 */
/* @0x2ab1be cmp r2, r1 */
/* @0x2ab1c0 bne 0x2ab1d2 <png_init_read_transformations+0x5a> */
/* @0x2ab1c2 ldr.w r1, [r4, #0x12c] */
/* @0x2ab1c4 .word 0xf8a4112c */
/* @0x2ab1c6 strh.w r2, [r4, #0x204] */
/* @0x2ab1c8 vst1.8 {d18, d19, d20, d21}, [r1], r4 */
/* @0x2ab1ca orr r1, r1, #0x800 */
/* @0x2ab1cc .word 0xf8c46100 */
/* @0x2ab1ce str.w r1, [r4, #0x12c] */
/* @0x2ab1d0 vst4.8 {d1, d3, d5, d7}, [r3:128], r12 */
/* @0x2ab1d2 and r2, r3, #0x1100 */
/* @0x2ab1d4 .word 0xf5b25288 */
/* @0x2ab1d6 cmp.w r2, #0x1100 */
/* @0x2ab1d8 cmple r10, r8, lsl #31 */
/* @0x2ab1da bne 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab1dc tst.w r10, #0x2 */
/* @0x2ab1e0 bne 0x2ab24c <png_init_read_transformations+0xd4> */
/* @0x2ab1e2 ldrb.w r2, [r4, #0x1eb] */
/* @0x2ab1e4 bhs 0x333998 */
/* @0x2ab1e6 cmp r2, #0x2 */
/* @0x2ab1e8 beq 0x2ab1fa <png_init_read_transformations+0x82> */
/* @0x2ab1ea cmp r2, #0x4 */
/* @0x2ab1ec beq 0x2ab202 <png_init_read_transformations+0x8a> */
/* @0x2ab1ee cmp r2, #0x1 */
/* @0x2ab1f0 bne 0x2ab23a <png_init_read_transformations+0xc2> */
/* @0x2ab1f2 ldrh.w r2, [r4, #0x204] */
/* @0x2ab1f4 mvnshs r2, r4, lsl #4 */
/* @0x2ab1f6 movs r1, #0xff */
/* @0x2ab1f8 b 0x2ab208 <png_init_read_transformations+0x90> */
/* @0x2ab1fa ldrh.w r2, [r4, #0x204] */
/* @0x2ab1fc cmphs r5, r4, lsl #4 */
/* @0x2ab1fe movs r1, #0x55 */
/* @0x2ab200 b 0x2ab208 <png_init_read_transformations+0x90> */
/* @0x2ab202 ldrh.w r2, [r4, #0x204] */
/* @0x2ab204 tsths r1, r4, lsl #4 */
/* @0x2ab206 movs r1, #0x11 */
/* @0x2ab208 muls r2, r1, r2 */
/* @0x2ab20a lsls r0, r3, #0x6 */
/* @0x2ab20c uxth r2, r2 */
/* @0x2ab20e strh.w r2, [r4, #0x204] */
/* @0x2ab210 .word 0xf8a42204 */
/* @0x2ab212 strh.w r2, [r4, #0x202] */
/* @0x2ab214 .word 0xf8a42202 */
/* @0x2ab216 strh.w r2, [r4, #0x200] */
/* @0x2ab218 .word 0xf8a42200 */
/* @0x2ab21a strh.w r2, [r4, #0x1fe] */
/* @0x2ab21c ldrtle r2, [r8], #-510 */
/* @0x2ab21e bmi 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab220 ldrh.w r3, [r4, #0x258] */
/* @0x2ab224 muls r3, r1, r3 */
/* @0x2ab226 uxth r3, r3 */
/* @0x2ab228 strh.w r3, [r4, #0x258] */
/* @0x2ab22c strh.w r3, [r4, #0x256] */
/* @0x2ab230 strh.w r3, [r4, #0x254] */
/* @0x2ab234 strh.w r3, [r4, #0x252] */
/* @0x2ab238 b 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab23a ldrh.w r3, [r4, #0x204] */
/* @0x2ab23c .word 0xf8a43204 */
/* @0x2ab23e strh.w r3, [r4, #0x202] */
/* @0x2ab240 .word 0xf8a43202 */
/* @0x2ab242 strh.w r3, [r4, #0x200] */
/* @0x2ab244 .word 0xf8a43200 */
/* @0x2ab246 strh.w r3, [r4, #0x1fe] */
/* @0x2ab248 .word 0xe02231fe */
/* @0x2ab24a b 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab24c cmp.w r10, #0x3 */
/* @0x2ab250 bne 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab252 ldrb.w r1, [r4, #0x1fc] */
/* @0x2ab254 .word 0xf8d411fc */
/* @0x2ab256 ldr.w r0, [r4, #0x1d8] */
/* @0x2ab258 bl 0x2eb9c0 <FT_Done_Memory+0x1d4c> */
/* @0x2ab25a add.w r1, r1, r1, lsl #1 */
/* @0x2ab25c stmdane r2, {r0, r6, r8} ^ */
/* @0x2ab25e adds r2, r0, r1 */
/* @0x2ab260 ldrb r1, [r0, r1] */
/* @0x2ab262 strh.w r1, [r4, #0x1fe] */
/* @0x2ab264 ldmdavc r1, {r1, r2, r3, r4, r5, r6, r7, r8, r12} ^ */
/* @0x2ab266 ldrb r1, [r2, #0x1] */
/* @0x2ab268 strh.w r1, [r4, #0x200] */
/* @0x2ab26c ldrb r2, [r2, #0x2] */
/* @0x2ab26e strh.w r2, [r4, #0x202] */
/* @0x2ab270 tsteq r10, #536870912 */
/* @0x2ab272 lsls r2, r3, #0xc */
/* @0x2ab274 bpl 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab276 ands r3, r3, #0x2000000 */
/* @0x2ab278 .word 0xd10a7300 */
/* @0x2ab27a bne 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab27c ldrh.w r1, [r4, #0x1de] */
/* @0x2ab280 cmp r3, r1 */
/* @0x2ab282 bge 0x2ab292 <png_init_read_transformations+0x11a> */
/* @0x2ab284 ldr.w r2, [r4, #0x24c] */
/* @0x2ab288 ldrb r0, [r2, r3] */
/* @0x2ab28a mvns r0, r0 */
/* @0x2ab28c strb r0, [r2, r3] */
/* @0x2ab28e adds r3, #0x1 */
/* @0x2ab290 b 0x2ab280 <png_init_read_transformations+0x108> */
/* @0x2ab292 add.w r3, r4, #0x1fc */
/* @0x2ab294 .word 0xf1ba73fe */
/* @0x2ab296 cmp.w r10, #0x3 */
/* @0x2ab298 blgt 0x36eeac <_ZTS13C_UTF16String+0x5f58> */
/* @0x2ab29a ldm r3!, {r0, r1} */
/* @0x2ab29c str.w r0, [r4, #0x206] */
/* @0x2ab2a0 str.w r1, [r4, #0x20a] */
/* @0x2ab2a4 ldrh r3, [r3] */
/* @0x2ab2a6 strh.w r3, [r4, #0x20e] */
/* @0x2ab2a8 .word 0xd129320e */
/* @0x2ab2aa bne 0x2ab300 <png_init_read_transformations+0x188> */
/* @0x2ab2ac ldrh.w r2, [r4, #0x1de] */
/* @0x2ab2b0 cbz r2, 0x2ab300 <png_init_read_transformations+0x188> */
/* @0x2ab2b2 vldr s15, [r4, #544] */
/* @0x2ab2b4 vldr s14, [r4, #544] */
/* @0x2ab2b6 vldr s12, [r4, #548] */
/* @0x2ab2b8 vmul.f32 s12, s13, s18 */
/* @0x2ab2ba vmul.f32 s12, s12, s15 */
/* @0x2ab2bc .word 0xeeb76a27 */
/* @0x2ab2be vmov.f64 d7, #1.000000e+00 */
/* @0x2ab2c0 vmov.f64 d7, #1.000000e+00 */
/* @0x2ab2c2 vcvt.f64.f32 d6, s12 */
/* @0x2ab2c4 vsub.f32 s12, s13, s12 */
/* @0x2ab2c6 vsub.f64 d6, d6, d7 */
/* @0x2ab2c8 vldr d6, [pc, #284] */
/* @0x2ab2ca vldr d7, [pc, #900] */
/* @0x2ab2cc vabs.f64 d7, d17 */
/* @0x2ab2ce vabs.f64 d6, d6 */
/* @0x2ab2d0 vcmpe.f64 d6, d6 */
/* @0x2ab2d2 vcmpe.f64 d6, d7 */
/* @0x2ab2d4 vsqrt.f64 d22, d7 */
/* @0x2ab2d6 vmrs APSR_nzcv, fpscr */
/* @0x2ab2d8 ldrle pc, [r1, #-0xa10] */
/* @0x2ab2da bpl 0x2ab300 <png_init_read_transformations+0x188> */
/* @0x2ab2dc movs r3, #0x0 */
/* @0x2ab2de cmp r3, r2 */
/* @0x2ab2e0 bge 0x2ab2f4 <png_init_read_transformations+0x17c> */
/* @0x2ab2e2 ldr.w r1, [r4, #0x24c] */
/* @0x2ab2e4 stclpl p2, c1, [r9], {76} */
/* @0x2ab2e6 ldrb r1, [r1, r3] */
/* @0x2ab2e8 subs r1, #0x1 */
/* @0x2ab2ea uxtb r1, r1 */
/* @0x2ab2ec cmp r1, #0xfd */
/* @0x2ab2ee bls 0x2ab300 <png_init_read_transformations+0x188> */
/* @0x2ab2f0 adds r3, #0x1 */
/* @0x2ab2f2 b 0x2ab2de <png_init_read_transformations+0x166> */
/* @0x2ab2f4 ldr.w r3, [r4, #0x134] */
/* @0x2ab2f8 bic r3, r3, #0x2000 */
/* @0x2ab2fc str.w r3, [r4, #0x134] */
/* @0x2ab300 ldr.w r2, [r4, #0x134] */
/* @0x2ab304 ldr r3, [pc, #0x358] */
/* @0x2ab306 ands r3, r2 */
/* @0x2ab308 cmp r3, #0x0 */
/* @0x2ab30a beq.w 0x2ab89a <png_init_read_transformations+0x722> */
/* @0x2ab30c ldcl p2, c8, [r4, #792] */
/* @0x2ab30e vldr s15, [r4, #544] */
/* @0x2ab310 .word 0xeef57a88 */
/* @0x2ab312 vcmp.f32 s15, #0 */
/* @0x2ab314 vneg.f32 s15, s0 */
/* @0x2ab316 vmrs APSR_nzcv, fpscr */
/* @0x2ab318 .word 0xf000fa10 */
/* @0x2ab31a beq.w 0x2ab89a <png_init_read_transformations+0x722> */
/* @0x2ab31c .word 0x462082be */
/* @0x2ab31e mov r0, r4 */
/* @0x2ab320 ldrb.w r1, [r4, #0x1eb] */
/* @0x2ab324 bl 0x2aaca0 <png_build_gamma_table> */
/* @0x2ab328 ldr.w r2, [r4, #0x134] */
/* @0x2ab32c ands r2, r2, #0x80 */
/* @0x2ab330 beq.w 0x2ab846 <png_init_read_transformations+0x6ce> */
/* @0x2ab334 cmp.w r10, #0x3 */
/* @0x2ab338 ldrb.w r3, [r4, #0x1f4] */
/* @0x2ab33c bne.w 0x2ab5f8 <png_init_read_transformations+0x480> */
/* @0x2ab340 ldrh.w r1, [r4, #0x1dc] */
/* @0x2ab344 cmp r3, #0x2 */
/* @0x2ab346 ldr.w r11, [r4, #0x1d8] */
/* @0x2ab348 rfeia r4! */
/* @0x2ab34a ldrh.w r2, [r4, #0x1fe] */
/* @0x2ab34c strdls r2, r3, [r1, -lr] */
/* @0x2ab34e str r1, [sp, #0x4] */
/* @0x2ab350 bne 0x2ab376 <png_init_read_transformations+0x1fe> */
/* @0x2ab352 ldr.w r3, [r4, #0x228] */
/* @0x2ab354 rfeia r4! */
/* @0x2ab356 ldrh.w r0, [r4, #0x200] */
/* @0x2ab358 rfeia r4! */
/* @0x2ab35a ldrh.w r1, [r4, #0x202] */
/* @0x2ab35c ldcpl p2, c1, [pc], {2} */
/* @0x2ab35e ldrb r7, [r3, r2] */
/* @0x2ab360 ldrb r6, [r3, r0] */
/* @0x2ab362 ldrb r5, [r3, r1] */
/* @0x2ab364 ldr.w r3, [r4, #0x230] */
/* @0x2ab368 ldrb.w r9, [r3, r2] */
/* @0x2ab36c ldrb.w r8, [r3, r0] */
/* @0x2ab370 ldrb.w r12, [r3, r1] */
/* @0x2ab374 b 0x2ab50c <png_init_read_transformations+0x394> */
/* @0x2ab376 cmp r3, #0x1 */
/* @0x2ab378 vmov.f64 d7, #1.000000e+00 */
/* @0x2ab37c beq 0x2ab3a0 <png_init_read_transformations+0x228> */
/* @0x2ab37e cmp r3, #0x3 */
/* @0x2ab380 bne 0x2ab3ae <png_init_read_transformations+0x236> */
/* @0x2ab382 vldr s13, [r4, #504] */
/* @0x2ab384 vldr s12, [r4, #504] */
/* @0x2ab386 vldr s20, [r4, #548] */
/* @0x2ab388 vmul.f32 s20, s13, s18 */
/* @0x2ab38a vmul.f32 s20, s13, s20 */
/* @0x2ab38c .word 0xeeb7aa8a */
/* @0x2ab38e vcvt.f64.f32 d11, s13 */
/* @0x2ab390 vcvt.f64.f32 d11, s13 */
/* @0x2ab392 vcvt.f64.f32 d10, s20 */
/* @0x2ab394 .word 0xee87aaca */
/* @0x2ab396 vdiv.f64 d11, d7, d11 */
/* @0x2ab398 vdiv.f64 d11, d7, d11 */
/* @0x2ab39a vdiv.f64 d10, d7, d10 */
/* @0x2ab39c and r10, r10, r10, lsl #22 */
/* @0x2ab39e b 0x2ab3b6 <png_init_read_transformations+0x23e> */
/* @0x2ab3a0 vldr s22, [r4, #548] */
/* @0x2ab3a4 vmov.f64 d10, d7 */
/* @0x2ab3a8 vcvt.f64.f32 d11, s22 */
/* @0x2ab3ac b 0x2ab3b6 <png_init_read_transformations+0x23e> */
/* @0x2ab3ae vmov.f64 d10, d7 */
/* @0x2ab3b0 vmov.f64 d10, d7 */
/* @0x2ab3b2 vmov.f64 d11, d7 */
/* @0x2ab3b4 vldr d11, [pc, #284] */
/* @0x2ab3b6 vldr d6, [pc, #664] */
/* @0x2ab3b8 vldr d6, [pc, #664] */
/* @0x2ab3ba vldr d8, [pc, #668] */
/* @0x2ab3bc vadd.f64 d8, d26, d23 */
/* @0x2ab3be vsub.f64 d7, d10, d7 */
/* @0x2ab3c0 vmov.f64 d7, d7 */
/* @0x2ab3c2 vabs.f64 d7, d7 */
/* @0x2ab3c4 vcmpe.f64 d7, d7 */
/* @0x2ab3c6 vcmpe.f64 d7, d6 */
/* @0x2ab3c8 .word 0xeeb67bc6 */
/* @0x2ab3ca vmov.f64 d9, #5.000000e-01 */
/* @0x2ab3cc vmov.f64 d25, #4.000000e+00 */
/* @0x2ab3ce vmrs APSR_nzcv, fpscr */
/* @0x2ab3d0 strle pc, [r6, #-0xa10] */
/* @0x2ab3d2 bpl 0x2ab3e2 <png_init_read_transformations+0x26a> */
/* @0x2ab3d4 ldrb.w r7, [r4, #0x1fe] */
/* @0x2ab3d8 ldrb.w r6, [r4, #0x200] */
/* @0x2ab3dc ldrb.w r5, [r4, #0x202] */
/* @0x2ab3e0 b 0x2ab474 <png_init_read_transformations+0x2fc> */
/* @0x2ab3e2 vmov s12, r2 */
/* @0x2ab3e4 vmov r2, r3, s0, s1 */
/* @0x2ab3e6 vmov r2, r3, d10 */
/* @0x2ab3e8 .word 0xeeb82b1a */
/* @0x2ab3ea vcvt.f64.u32 d7, s12 */
/* @0x2ab3ec .word 0xee877b46 */
/* @0x2ab3ee vdiv.f64 d6, d7, d8 */
/* @0x2ab3f0 .word 0xec516b08 */
/* @0x2ab3f2 vmov r0, r1, d6 */
/* @0x2ab3f4 .word 0xf60b0b16 */
/* @0x2ab3f6 blx 0xb6784 <pow@plt> */
/* @0x2ab3f8 cdp p9, #0xb, c14, c0, c6, #0x6 */
/* @0x2ab3fa vmov.f64 d7, d9 */
/* @0x2ab3fc .word 0xec537b49 */
/* @0x2ab3fe vmov r2, r3, d10 */
/* @0x2ab400 vmov d10, r2, r1 */
/* @0x2ab402 vmov d6, r0, r1 */
/* @0x2ab404 rfeia r4! */
/* @0x2ab406 ldrh.w r1, [r4, #0x200] */
/* @0x2ab408 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab40a vmla.f64 d7, d6, d8 */
/* @0x2ab40c vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab40e vcvt.u32.f64 s13, d7 */
/* @0x2ab410 vmls.f64 d6, d23, d7 */
/* @0x2ab412 vmov s14, r1 */
/* @0x2ab414 .word 0xeeb81a10 */
/* @0x2ab416 vcvt.f64.u32 d7, s14 */
/* @0x2ab418 vnmla.f64 d7, d6, d7 */
/* @0x2ab41a vmov r7, s13 */
/* @0x2ab41c .word 0xee877a90 */
/* @0x2ab41e vdiv.f64 d6, d7, d8 */
/* @0x2ab420 rscslt r6, pc, #8, #22 */
/* @0x2ab422 uxtb r7, r7 */
/* @0x2ab424 vmov r0, r1, d6 */
/* @0x2ab428 blx 0xb6784 <pow@plt> */
/* @0x2ab42c vmov.f64 d7, d9 */
/* @0x2ab430 vmov r2, r3, d10 */
/* @0x2ab434 vmov d6, r0, r1 */
/* @0x2ab438 ldrh.w r1, [r4, #0x202] */
/* @0x2ab43c vmla.f64 d7, d6, d8 */
/* @0x2ab440 vcvt.u32.f64 s13, d7 */
/* @0x2ab444 vmov s14, r1 */
/* @0x2ab448 vcvt.f64.u32 d7, s14 */
/* @0x2ab44c vmov r6, s13 */
/* @0x2ab450 vdiv.f64 d6, d7, d8 */
/* @0x2ab454 uxtb r6, r6 */
/* @0x2ab456 vmov r0, r1, d6 */
/* @0x2ab458 .word 0xf60b0b16 */
/* @0x2ab45a blx 0xb6784 <pow@plt> */
/* @0x2ab45c mrc p9, #0x5, lr, c0, c4, #0x4 */
/* @0x2ab45e vmov.f64 d7, d9 */
/* @0x2ab460 .word 0xec417b49 */
/* @0x2ab462 vmov d6, r0, r1 */
/* @0x2ab464 .word 0xee060b16 */
/* @0x2ab466 vmla.f64 d7, d6, d8 */
/* @0x2ab468 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab46a vcvt.u32.f64 s13, d7 */
/* @0x2ab46c vnmla.f64 d6, d22, d7 */
/* @0x2ab46e vmov r5, s13 */
/* @0x2ab470 rsclt r5, sp, #144, #20 */
/* @0x2ab472 uxtb r5, r5 */
/* @0x2ab474 ldrh.w r1, [r4, #0x1fe] */
/* @0x2ab478 vmov r2, r3, d11 */
/* @0x2ab47c vmov s14, r1 */
/* @0x2ab480 vcvt.f64.u32 d7, s14 */
/* @0x2ab484 vdiv.f64 d6, d7, d8 */
/* @0x2ab488 vmov r0, r1, d6 */
/* @0x2ab48c blx 0xb6784 <pow@plt> */
/* @0x2ab490 vmov.f64 d7, d9 */
/* @0x2ab494 vmov r2, r3, d11 */
/* @0x2ab498 vmov d6, r0, r1 */
/* @0x2ab49c ldrh.w r1, [r4, #0x200] */
/* @0x2ab4a0 vmla.f64 d7, d6, d8 */
/* @0x2ab4a4 vcvt.u32.f64 s13, d7 */
/* @0x2ab4a8 vmov s14, r1 */
/* @0x2ab4ac vcvt.f64.u32 d7, s14 */
/* @0x2ab4b0 vmov r9, s13 */
/* @0x2ab4b4 vdiv.f64 d6, d7, d8 */
/* @0x2ab4b8 uxtb.w r9, r9 */
/* @0x2ab4bc vmov r0, r1, d6 */
/* @0x2ab4c0 blx 0xb6784 <pow@plt> */
/* @0x2ab4c4 vmov.f64 d7, d9 */
/* @0x2ab4c8 vmov r2, r3, d11 */
/* @0x2ab4cc vmov d6, r0, r1 */
/* @0x2ab4d0 ldrh.w r1, [r4, #0x202] */
/* @0x2ab4d4 vmla.f64 d7, d6, d8 */
/* @0x2ab4d8 vcvt.u32.f64 s13, d7 */
/* @0x2ab4dc vmov s14, r1 */
/* @0x2ab4e0 vcvt.f64.u32 d7, s14 */
/* @0x2ab4e4 vmov r8, s13 */
/* @0x2ab4e8 vdiv.f64 d6, d7, d8 */
/* @0x2ab4ec uxtb.w r8, r8 */
/* @0x2ab4f0 vmov r0, r1, d6 */
/* @0x2ab4f4 blx 0xb6784 <pow@plt> */
/* @0x2ab4f8 vmov d7, r0, r1 */
/* @0x2ab4fc vmla.f64 d9, d7, d8 */
/* @0x2ab500 vcvt.u32.f64 s15, d9 */
/* @0x2ab504 vmov r12, s15 */
/* @0x2ab508 uxtb.w r12, r12 */
/* @0x2ab50c add.w r3, r11, #0x1 */
/* @0x2ab510 movs r2, #0x0 */
/* @0x2ab512 ldr r1, [sp, #0x4] */
/* @0x2ab514 cmp r2, r1 */
/* @0x2ab516 bge 0x2ab5ee <png_init_read_transformations+0x476> */
/* @0x2ab518 ldrh.w r1, [r4, #0x1de] */
/* @0x2ab51c cmp r2, r1 */
/* @0x2ab51e bge 0x2ab5c6 <png_init_read_transformations+0x44e> */
/* @0x2ab520 ldr.w r1, [r4, #0x24c] */
/* @0x2ab524 ldrb r1, [r1, r2] */
/* @0x2ab526 cmp r1, #0xff */
/* @0x2ab528 beq 0x2ab5c6 <png_init_read_transformations+0x44e> */
/* @0x2ab52a cbnz r1, 0x2ab536 <png_init_read_transformations+0x3be> */
/* @0x2ab52c strb r7, [r3, #-1] */
/* @0x2ab530 strb r6, [r3] */
/* @0x2ab532 strb r5, [r3, #0x1] */
/* @0x2ab534 b 0x2ab5e8 <png_init_read_transformations+0x470> */
/* @0x2ab536 ldr.w r0, [r4, #0x230] */
/* @0x2ab538 .word 0xf8130230 */
/* @0x2ab53a ldrb r11, [r3, #-1] */
/* @0x2ab53c .word 0xf810bc01 */
/* @0x2ab53e ldrb.w r11, [r0, r11] */
/* @0x2ab540 .word 0xf1c1b00b */
/* @0x2ab542 rsb.w r0, r1, #0xff */
/* @0x2ab544 blx 0x2ab94a <png_init_read_transformations+0x7d2> */
/* @0x2ab546 mul r0, r0, r9 */
/* @0x2ab548 blx 0x5a7576 <g_SWFlineaavertbuff+0x544ae> */
/* @0x2ab54a mla r1, r11, r1, r0 */
/* @0x2ab54c .word 0xf8d40101 */
/* @0x2ab54e ldr.w r0, [r4, #0x22c] */
/* @0x2ab550 .word 0xf893022c */
/* @0x2ab552 ldrb.w r11, [r3] */
/* @0x2ab554 orrlo r11, r0, r0 */
/* @0x2ab556 adds r1, #0x80 */
/* @0x2ab558 uxth r1, r1 */
/* @0x2ab55a add.w r1, r1, r1, lsr #8 */
/* @0x2ab55c vorr.i32 d18, #0x91 */
/* @0x2ab55e ubfx r1, r1, #0x8, #0x8 */
/* @0x2ab560 mcrrpl p1, #0x0, r2, r1, c7 */
/* @0x2ab562 ldrb r1, [r0, r1] */
/* @0x2ab564 strb r1, [r3, #-1] */
/* @0x2ab568 ldr.w r1, [r4, #0x24c] */
/* @0x2ab56c ldrb r0, [r1, r2] */
/* @0x2ab56e ldr.w r1, [r4, #0x230] */
/* @0x2ab570 .word 0xf8111230 */
/* @0x2ab572 ldrb.w r11, [r1, r11] */
/* @0x2ab574 .word 0xf1c0b00b */
/* @0x2ab576 rsb.w r1, r0, #0xff */
/* @0x2ab578 blx 0x2ebd7e <FT_Done_Memory+0x210a> */
/* @0x2ab57a mul r1, r1, r8 */
/* @0x2ab57c blx 0x5a79a6 <g_SWFlineaavertbuff+0x548de> */
/* @0x2ab57e mla r1, r11, r0, r1 */
/* @0x2ab580 .word 0xf8d41100 */
/* @0x2ab582 ldr.w r0, [r4, #0x22c] */
/* @0x2ab584 .word 0xf893022c */
/* @0x2ab586 ldrb.w r11, [r3, #0x1] */
/* @0x2ab588 orrlo r11, r0, r1 */
/* @0x2ab58a adds r1, #0x80 */
/* @0x2ab58c uxth r1, r1 */
/* @0x2ab58e add.w r1, r1, r1, lsr #8 */
/* @0x2ab590 vorr.i32 d18, #0x91 */
/* @0x2ab592 ubfx r1, r1, #0x8, #0x8 */
/* @0x2ab594 mcrrpl p1, #0x0, r2, r1, c7 */
/* @0x2ab596 ldrb r1, [r0, r1] */
/* @0x2ab598 strb r1, [r3] */
/* @0x2ab59a ldr.w r1, [r4, #0x24c] */
/* @0x2ab59c stcpl p2, c1, [r8], {76} */
/* @0x2ab59e ldrb r0, [r1, r2] */
/* @0x2ab5a0 ldr.w r1, [r4, #0x230] */
/* @0x2ab5a4 ldrb.w r11, [r1, r11] */
/* @0x2ab5a8 rsb.w r1, r0, #0xff */
/* @0x2ab5ac mul r1, r1, r12 */
/* @0x2ab5b0 mla r1, r11, r0, r1 */
/* @0x2ab5b4 ldr.w r0, [r4, #0x22c] */
/* @0x2ab5b8 adds r1, #0x80 */
/* @0x2ab5ba uxth r1, r1 */
/* @0x2ab5bc add.w r1, r1, r1, lsr #8 */
/* @0x2ab5c0 ubfx r1, r1, #0x8, #0x8 */
/* @0x2ab5c4 b 0x2ab5e4 <png_init_read_transformations+0x46c> */
/* @0x2ab5c6 ldrb r0, [r3, #-1] */
/* @0x2ab5c8 .word 0xf8d40c01 */
/* @0x2ab5ca ldr.w r1, [r4, #0x228] */
/* @0x2ab5cc .word 0x5c091228 */
/* @0x2ab5ce ldrb r1, [r1, r0] */
/* @0x2ab5d0 ldrb r0, [r3] */
/* @0x2ab5d2 strb r1, [r3, #-1] */
/* @0x2ab5d4 .word 0xf8d41c01 */
/* @0x2ab5d6 ldr.w r1, [r4, #0x228] */
/* @0x2ab5d8 .word 0x5c091228 */
/* @0x2ab5da ldrb r1, [r1, r0] */
/* @0x2ab5dc ldrb r0, [r3, #0x1] */
/* @0x2ab5de strb r1, [r3] */
/* @0x2ab5e0 ldr.w r1, [r4, #0x228] */
/* @0x2ab5e4 ldrb r1, [r1, r0] */
/* @0x2ab5e6 strb r1, [r3, #0x1] */
/* @0x2ab5e8 adds r2, #0x1 */
/* @0x2ab5ea adds r3, #0x3 */
/* @0x2ab5ec b 0x2ab512 <png_init_read_transformations+0x39a> */
/* @0x2ab5ee ldr.w r3, [r4, #0x134] */
/* @0x2ab5f0 vld4.8 {d3, d5, d7, d9}, [r3:256], r4 */
/* @0x2ab5f2 bic r3, r3, #0x2080 */
/* @0x2ab5f4 .word 0xe1a75302 */
/* @0x2ab5f6 b 0x2ab948 <png_init_read_transformations+0x7d0> */
/* @0x2ab5f8 ldrb.w r2, [r4, #0x1eb] */
/* @0x2ab5fc movs r1, #0x1 */
/* @0x2ab5fe cmp r3, #0x2 */
/* @0x2ab600 vmov.f64 d9, #1.000000e+00 */
/* @0x2ab604 lsl.w r2, r1, r2 */
/* @0x2ab608 add.w r2, r2, #0xffffffff */
/* @0x2ab60c vmov s12, r2 */
/* @0x2ab610 vcvt.f64.u32 d8, s12 */
/* @0x2ab614 beq 0x2ab628 <png_init_read_transformations+0x4b0> */
/* @0x2ab616 cmp r3, #0x3 */
/* @0x2ab618 beq 0x2ab62e <png_init_read_transformations+0x4b6> */
/* @0x2ab61a cmp r3, r1 */
/* @0x2ab61c bne 0x2ab664 <png_init_read_transformations+0x4ec> */
/* @0x2ab61e vldr s20, [r4, #548] */
/* @0x2ab620 .word 0xeeb7aa89 */
/* @0x2ab622 vcvt.f64.f32 d10, s20 */
/* @0x2ab624 eor r10, r4, r10, asr #21 */
/* @0x2ab626 b 0x2ab672 <png_init_read_transformations+0x4fa> */
/* @0x2ab628 vldr s15, [r4, #544] */
/* @0x2ab62c b 0x2ab632 <png_init_read_transformations+0x4ba> */
/* @0x2ab62e vldr s15, [r4, #504] */
/* @0x2ab630 vldr s14, [r4, #504] */
/* @0x2ab632 vldr s14, [r4, #548] */
/* @0x2ab634 vmul.f32 s14, s15, s18 */
/* @0x2ab636 vmul.f32 s14, s15, s14 */
/* @0x2ab638 .word 0xeeb77a87 */
/* @0x2ab63a vcvt.f64.f32 d10, s15 */
/* @0x2ab63c vcvt.f64.f32 d10, s15 */
/* @0x2ab63e vcvt.f64.f32 d7, s14 */
/* @0x2ab640 .word 0xee897ac7 */
/* @0x2ab642 vdiv.f64 d10, d9, d10 */
/* @0x2ab644 vdiv.f64 d10, d9, d10 */
/* @0x2ab646 vdiv.f64 d9, d9, d7 */
/* @0x2ab648 ands r9, r2, r7, lsl #22 */
/* @0x2ab64a b 0x2ab672 <png_init_read_transformations+0x4fa> */
/* @0x2ab64c nop.w */
/* @0x2ab650 ldr r1, [sp, #0x268] */
/* @0x2ab652 ldr r1, [sp, #0x264] */
/* @0x2ab654 ldr r1, [sp, #0x264] */
/* @0x2ab656 subs r7, #0xa9 */
/* @0x2ab658 movs r0, r0 */
/* @0x2ab65a movs r0, r0 */
/* @0x2ab65c b 0x2ab660 <png_init_read_transformations+0x4e8> */
/* @0x2ab65e eors r7, r5 */
/* @0x2ab660 movs r0, #0x0 */
/* @0x2ab662 lsls r0, r4, #0x1 */
/* @0x2ab664 ldr r1, [pc, #0x388] */
/* @0x2ab666 mov r0, r4 */
/* @0x2ab668 vmov.f64 d10, d9 */
/* @0x2ab66c add r1, pc */
/* @0x2ab66e bl 0x2a642c <png_error> */
/* @0x2ab670 rfeia r4! */
/* @0x2ab672 ldrh.w r1, [r4, #0x204] */
/* @0x2ab674 cdp p2, #0xb, c1, c6, c4, #0x0 */
/* @0x2ab676 vmov.f64 d11, #5.000000e-01 */
/* @0x2ab678 .word 0xec53bb00 */
/* @0x2ab67a vmov r2, r3, d10 */
/* @0x2ab67c .word 0xee072b1a */
/* @0x2ab67e vmov s14, r1 */
/* @0x2ab680 .word 0xeeb81a10 */
/* @0x2ab682 vcvt.f64.u32 d7, s14 */
/* @0x2ab684 .word 0xee877b47 */
/* @0x2ab686 vdiv.f64 d6, d7, d8 */
/* @0x2ab688 .word 0xec516b08 */
/* @0x2ab68a vmov r0, r1, d6 */
/* @0x2ab68c .word 0xf60b0b16 */
/* @0x2ab68e blx 0xb6784 <pow@plt> */
/* @0x2ab690 mrc p8, #0x5, lr, c0, c10, #0x3 */
/* @0x2ab692 vmov.f64 d7, d11 */
/* @0x2ab694 .word 0xec417b4b */
/* @0x2ab696 vmov d6, r0, r1 */
/* @0x2ab698 rfeia r4! */
/* @0x2ab69a ldrh.w r1, [r4, #0x204] */
/* @0x2ab69c cdp p2, #0x0, c1, c6, c4, #0x0 */
/* @0x2ab69e vmla.f64 d7, d6, d8 */
/* @0x2ab6a0 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab6a2 vcvt.u32.f64 s13, d7 */
/* @0x2ab6a4 vmls.f64 d6, d23, d7 */
/* @0x2ab6a6 vmov s14, r1 */
/* @0x2ab6a8 .word 0xeeb81a10 */
/* @0x2ab6aa vcvt.f64.u32 d7, s14 */
/* @0x2ab6ac vnmla.f64 d7, d6, d7 */
/* @0x2ab6ae vmov r3, s13 */
/* @0x2ab6b0 .word 0xee873a90 */
/* @0x2ab6b2 vdiv.f64 d6, d7, d8 */
/* @0x2ab6b4 .word 0xf8a46b08 */
/* @0x2ab6b6 strh.w r3, [r4, #0x20e] */
/* @0x2ab6b8 mrrc p2, #0x0, r3, r3, c14 */
/* @0x2ab6ba vmov r2, r3, d9 */
/* @0x2ab6bc vmov r2, r1, d9 */
/* @0x2ab6be vmov r0, r1, d6 */
/* @0x2ab6c0 .word 0xf60b0b16 */
/* @0x2ab6c2 blx 0xb6784 <pow@plt> */
/* @0x2ab6c4 cdp p8, #0xb, c14, c0, c0, #0x3 */
/* @0x2ab6c6 vmov.f64 d7, d11 */
/* @0x2ab6c8 .word 0xec417b4b */
/* @0x2ab6ca vmov d6, r0, r1 */
/* @0x2ab6cc rfeia r4! */
/* @0x2ab6ce ldrh.w r0, [r4, #0x1fe] */
/* @0x2ab6d0 rfeia r4! */
/* @0x2ab6d2 ldrh.w r1, [r4, #0x200] */
/* @0x2ab6d4 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab6d6 vmla.f64 d7, d6, d8 */
/* @0x2ab6d8 addmi r7, r1, #8, #22 */
/* @0x2ab6da cmp r1, r0 */
/* @0x2ab6dc vcvt.u32.f64 s13, d7 */
/* @0x2ab6e0 vmov r2, s13 */
/* @0x2ab6e4 uxth r2, r2 */
/* @0x2ab6e6 strh.w r2, [r4, #0x204] */
/* @0x2ab6e8 .word 0xd1062204 */
/* @0x2ab6ea bne 0x2ab6fa <png_init_read_transformations+0x582> */
/* @0x2ab6ec ldrh.w r3, [r4, #0x202] */
/* @0x2ab6f0 cmp r3, r1 */
/* @0x2ab6f2 bne 0x2ab6fa <png_init_read_transformations+0x582> */
/* @0x2ab6f4 cmp r3, r2 */
/* @0x2ab6f6 beq.w 0x2ab82c <png_init_read_transformations+0x6b4> */
/* @0x2ab6f8 mcr p0, #0x0, r8, c6, c9, #0x4 */
/* @0x2ab6fa vmov s12, r0 */
/* @0x2ab6fc vmov r0, r3, s0, s1 */
/* @0x2ab6fe vmov r2, r3, d10 */
/* @0x2ab700 .word 0xeeb82b1a */
/* @0x2ab702 vcvt.f64.u32 d7, s12 */
/* @0x2ab704 .word 0xee877b46 */
/* @0x2ab706 vdiv.f64 d6, d7, d8 */
/* @0x2ab708 .word 0xec516b08 */
/* @0x2ab70a vmov r0, r1, d6 */
/* @0x2ab70c .word 0xf60b0b16 */
/* @0x2ab70e blx 0xb6784 <pow@plt> */
/* @0x2ab710 mrc p8, #0x5, lr, c0, c10, #0x1 */
/* @0x2ab712 vmov.f64 d7, d11 */
/* @0x2ab714 .word 0xec417b4b */
/* @0x2ab716 vmov d6, r0, r1 */
/* @0x2ab718 rfeia r4! */
/* @0x2ab71a ldrh.w r1, [r4, #0x200] */
/* @0x2ab71c cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab71e vmla.f64 d7, d6, d8 */
/* @0x2ab720 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab722 vcvt.u32.f64 s13, d7 */
/* @0x2ab724 vmls.f64 d6, d23, d7 */
/* @0x2ab726 vmov s14, r1 */
/* @0x2ab728 .word 0xeeb81a10 */
/* @0x2ab72a vcvt.f64.u32 d7, s14 */
/* @0x2ab72c vnmla.f64 d7, d6, d7 */
/* @0x2ab72e vmov r3, s13 */
/* @0x2ab730 .word 0xee873a90 */
/* @0x2ab732 vdiv.f64 d6, d7, d8 */
/* @0x2ab734 .word 0xf8a46b08 */
/* @0x2ab736 strh.w r3, [r4, #0x208] */
/* @0x2ab738 mrrc p2, #0x0, r3, r3, c8 */
/* @0x2ab73a vmov r2, r3, d10 */
/* @0x2ab73c vmov r2, r1, d10 */
/* @0x2ab73e vmov r0, r1, d6 */
/* @0x2ab740 .word 0xf60b0b16 */
/* @0x2ab742 blx 0xb6784 <pow@plt> */
/* @0x2ab744 cdp p8, #0xb, c14, c0, c0, #0x1 */
/* @0x2ab746 vmov.f64 d7, d11 */
/* @0x2ab748 .word 0xec417b4b */
/* @0x2ab74a vmov d6, r0, r1 */
/* @0x2ab74c rfeia r4! */
/* @0x2ab74e ldrh.w r1, [r4, #0x202] */
/* @0x2ab750 cdp p2, #0x0, c1, c6, c2, #0x0 */
/* @0x2ab752 vmla.f64 d7, d6, d8 */
/* @0x2ab754 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab756 vcvt.u32.f64 s13, d7 */
/* @0x2ab758 vmls.f64 d6, d23, d7 */
/* @0x2ab75a vmov s14, r1 */
/* @0x2ab75c .word 0xeeb81a10 */
/* @0x2ab75e vcvt.f64.u32 d7, s14 */
/* @0x2ab760 vnmla.f64 d7, d6, d7 */
/* @0x2ab762 vmov r3, s13 */
/* @0x2ab764 .word 0xee873a90 */
/* @0x2ab766 vdiv.f64 d6, d7, d8 */
/* @0x2ab768 .word 0xf8a46b08 */
/* @0x2ab76a strh.w r3, [r4, #0x20a] */
/* @0x2ab76c mrrc p2, #0x0, r3, r3, c10 */
/* @0x2ab76e vmov r2, r3, d10 */
/* @0x2ab770 vmov r2, r1, d10 */
/* @0x2ab772 vmov r0, r1, d6 */
/* @0x2ab774 .word 0xf60b0b16 */
/* @0x2ab776 blx 0xb6784 <pow@plt> */
/* @0x2ab778 cdp p8, #0xb, c14, c0, c6, #0x0 */
/* @0x2ab77a vmov.f64 d7, d11 */
/* @0x2ab77c .word 0xec417b4b */
/* @0x2ab77e vmov d6, r0, r1 */
/* @0x2ab780 rfeia r4! */
/* @0x2ab782 ldrh.w r1, [r4, #0x1fe] */
/* @0x2ab784 mcr p1, #0x0, r1, c6, c14, #0x7 */
/* @0x2ab786 vmla.f64 d7, d6, d8 */
/* @0x2ab788 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab78a vcvt.u32.f64 s13, d7 */
/* @0x2ab78c vmls.f64 d6, d23, d7 */
/* @0x2ab78e vmov s14, r1 */
/* @0x2ab790 .word 0xeeb81a10 */
/* @0x2ab792 vcvt.f64.u32 d7, s14 */
/* @0x2ab794 vnmla.f64 d7, d6, d7 */
/* @0x2ab796 vmov r3, s13 */
/* @0x2ab798 .word 0xee873a90 */
/* @0x2ab79a vdiv.f64 d6, d7, d8 */
/* @0x2ab79c .word 0xf8a46b08 */
/* @0x2ab79e strh.w r3, [r4, #0x20c] */
/* @0x2ab7a0 mrrc p2, #0x0, r3, r3, c12 */
/* @0x2ab7a2 vmov r2, r3, d9 */
/* @0x2ab7a4 vmov r2, r1, d9 */
/* @0x2ab7a6 vmov r0, r1, d6 */
/* @0x2ab7a8 .word 0xf60a0b16 */
/* @0x2ab7aa blx 0xb6784 <pow@plt> */
/* @0x2ab7ac cdp p15, #0xb, c14, c0, c12, #0x7 */
/* @0x2ab7ae vmov.f64 d7, d11 */
/* @0x2ab7b0 .word 0xec417b4b */
/* @0x2ab7b2 vmov d6, r0, r1 */
/* @0x2ab7b4 rfeia r4! */
/* @0x2ab7b6 ldrh.w r1, [r4, #0x200] */
/* @0x2ab7b8 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab7ba vmla.f64 d7, d6, d8 */
/* @0x2ab7bc vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab7be vcvt.u32.f64 s13, d7 */
/* @0x2ab7c0 vmls.f64 d6, d23, d7 */
/* @0x2ab7c2 vmov s14, r1 */
/* @0x2ab7c4 .word 0xeeb81a10 */
/* @0x2ab7c6 vcvt.f64.u32 d7, s14 */
/* @0x2ab7c8 vnmla.f64 d7, d6, d7 */
/* @0x2ab7ca vmov r3, s13 */
/* @0x2ab7cc .word 0xee873a90 */
/* @0x2ab7ce vdiv.f64 d6, d7, d8 */
/* @0x2ab7d0 .word 0xf8a46b08 */
/* @0x2ab7d2 strh.w r3, [r4, #0x1fe] */
/* @0x2ab7d4 mrrc p1, #0xf, r3, r3, c14 */
/* @0x2ab7d6 vmov r2, r3, d9 */
/* @0x2ab7d8 vmov r2, r1, d9 */
/* @0x2ab7da vmov r0, r1, d6 */
/* @0x2ab7dc .word 0xf60a0b16 */
/* @0x2ab7de blx 0xb6784 <pow@plt> */
/* @0x2ab7e0 mrc p15, #0x5, lr, c0, c2, #0x6 */
/* @0x2ab7e2 vmov.f64 d7, d11 */
/* @0x2ab7e4 .word 0xec417b4b */
/* @0x2ab7e6 vmov d6, r0, r1 */
/* @0x2ab7e8 rfeia r4! */
/* @0x2ab7ea ldrh.w r1, [r4, #0x202] */
/* @0x2ab7ec cdp p2, #0x0, c1, c6, c2, #0x0 */
/* @0x2ab7ee vmla.f64 d7, d6, d8 */
/* @0x2ab7f0 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab7f2 vcvt.u32.f64 s13, d7 */
/* @0x2ab7f4 vmls.f64 d6, d23, d7 */
/* @0x2ab7f6 vmov s14, r1 */
/* @0x2ab7f8 .word 0xeeb81a10 */
/* @0x2ab7fa vcvt.f64.u32 d7, s14 */
/* @0x2ab7fc vnmla.f64 d7, d6, d7 */
/* @0x2ab7fe vmov r3, s13 */
/* @0x2ab800 .word 0xee873a90 */
/* @0x2ab802 vdiv.f64 d6, d7, d8 */
/* @0x2ab804 .word 0xf8a46b08 */
/* @0x2ab806 strh.w r3, [r4, #0x200] */
/* @0x2ab808 mrrc p2, #0x0, r3, r3, c0 */
/* @0x2ab80a vmov r2, r3, d9 */
/* @0x2ab80c vmov r2, r1, d9 */
/* @0x2ab80e vmov r0, r1, d6 */
/* @0x2ab810 .word 0xf60a0b16 */
/* @0x2ab812 blx 0xb6784 <pow@plt> */
/* @0x2ab814 mcrr p15, #0xb, lr, r1, c8 */
/* @0x2ab816 vmov d7, r0, r1 */
/* @0x2ab818 .word 0xee070b17 */
/* @0x2ab81a vmla.f64 d11, d7, d8 */
/* @0x2ab81c vmov.f64 d27, #-1.875000e-01 */
/* @0x2ab81e vcvt.u32.f64 s15, d11 */
/* @0x2ab820 vnmla.f64 d7, d23, d11 */
/* @0x2ab822 vmov r3, s15 */
/* @0x2ab824 .word 0xf8a43a90 */
/* @0x2ab826 strh.w r3, [r4, #0x202] */
/* @0x2ab828 adds r3, r5, r2, lsl #4 */
/* @0x2ab82a b 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab82c ldrh.w r2, [r4, #0x20e] */
/* @0x2ab830 strh.w r3, [r4, #0x202] */
/* @0x2ab834 strh.w r3, [r4, #0x200] */
/* @0x2ab838 strh.w r2, [r4, #0x20c] */
/* @0x2ab83c strh.w r2, [r4, #0x20a] */
/* @0x2ab840 strh.w r2, [r4, #0x208] */
/* @0x2ab844 b 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab846 cmp.w r10, #0x3 */
/* @0x2ab848 .word 0xf0400f03 */
/* @0x2ab84a bne.w 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab84c rfeia r4! */
/* @0x2ab84e ldrh.w r0, [r4, #0x1dc] */
/* @0x2ab850 .word 0xf8d401dc */
/* @0x2ab852 ldr.w r3, [r4, #0x1d8] */
/* @0x2ab854 addmi r3, r2, #216, #2 */
/* @0x2ab856 cmp r2, r0 */
/* @0x2ab858 add.w r3, r3, #0x3 */
/* @0x2ab85c bge 0x2ab88c <png_init_read_transformations+0x714> */
/* @0x2ab85e ldr.w r1, [r4, #0x228] */
/* @0x2ab860 andlo r1, r1, #40, #4 */
/* @0x2ab862 adds r2, #0x1 */
/* @0x2ab864 ldrb r5, [r3, #-3] */
/* @0x2ab868 ldrb r1, [r1, r5] */
/* @0x2ab86a ldrb r5, [r3, #-2] */
/* @0x2ab86c .word 0xf8035c02 */
/* @0x2ab86e strb r1, [r3, #-3] */
/* @0x2ab870 .word 0xf8d41c03 */
/* @0x2ab872 ldr.w r1, [r4, #0x228] */
/* @0x2ab874 stclpl p2, c1, [r9, #-160] */
/* @0x2ab876 ldrb r1, [r1, r5] */
/* @0x2ab878 ldrb r5, [r3, #-1] */
/* @0x2ab87c strb r1, [r3, #-2] */
/* @0x2ab880 ldr.w r1, [r4, #0x228] */
/* @0x2ab884 ldrb r1, [r1, r5] */
/* @0x2ab886 strb r1, [r3, #-1] */
/* @0x2ab888 strb r1, [r4, r1, lsl #24]! */
/* @0x2ab88a b 0x2ab856 <png_init_read_transformations+0x6de> */
/* @0x2ab88c ldr.w r3, [r4, #0x134] */
/* @0x2ab890 bic r3, r3, #0x2000 */
/* @0x2ab894 str.w r3, [r4, #0x134] */
/* @0x2ab898 b 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab89a lsls r3, r2, #0x18 */
/* @0x2ab89c bpl 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab89e cmp.w r10, #0x3 */
/* @0x2ab8a0 cmple r9, r3, lsl #30 */
/* @0x2ab8a2 bne 0x2ab958 <png_init_read_transformations+0x7e0> */
/* @0x2ab8a4 ldrb.w r1, [r4, #0x1fe] */
/* @0x2ab8a8 movs r2, #0x0 */
/* @0x2ab8aa ldrb.w r0, [r4, #0x200] */
/* @0x2ab8ac .word 0xf8940200 */
/* @0x2ab8ae ldrb.w r5, [r4, #0x202] */
/* @0x2ab8b0 rfeia r4! */
/* @0x2ab8b2 ldrh.w r7, [r4, #0x1de] */
/* @0x2ab8b4 pkhtbmi r7, r12, lr, asr #3 */
/* @0x2ab8b6 mov r12, r1 */
/* @0x2ab8b8 ldr.w r3, [r4, #0x1d8] */
/* @0x2ab8bc mov r8, r0 */
/* @0x2ab8be mov r9, r5 */
/* @0x2ab8c0 cmp r2, r7 */
/* @0x2ab8c2 bge 0x2ab940 <png_init_read_transformations+0x7c8> */
/* @0x2ab8c4 ldr.w r6, [r4, #0x24c] */
/* @0x2ab8c8 ldrb r6, [r6, r2] */
/* @0x2ab8ca cbnz r6, 0x2ab8d4 <png_init_read_transformations+0x75c> */
/* @0x2ab8cc strb r1, [r3] */
/* @0x2ab8ce strb r0, [r3, #0x1] */
/* @0x2ab8d0 strb r5, [r3, #0x2] */
/* @0x2ab8d2 b 0x2ab93a <png_init_read_transformations+0x7c2> */
/* @0x2ab8d4 cmp r6, #0xff */
/* @0x2ab8d6 beq 0x2ab93a <png_init_read_transformations+0x7c2> */
/* @0x2ab8d8 ldrb.w r11, [r3] */
/* @0x2ab8dc mul r11, r11, r6 */
/* @0x2ab8e0 rsb.w r6, r6, #0xff */
/* @0x2ab8e4 add.w r11, r11, #0x80 */
/* @0x2ab8e8 mla r6, r6, r12, r11 */
/* @0x2ab8ec uxth r6, r6 */
/* @0x2ab8ee add.w r6, r6, r6, lsr #8 */
/* @0x2ab8f0 eorsne r2, r6, #23068672 */
/* @0x2ab8f2 asrs r6, r6, #0x8 */
/* @0x2ab8f4 strb r6, [r3] */
/* @0x2ab8f6 ldr.w r6, [r4, #0x24c] */
/* @0x2ab8f8 .word 0xf816624c */
/* @0x2ab8fa ldrb.w r11, [r6, r2] */
/* @0x2ab8fc ldmdavc lr, {r1, r12, sp, pc} ^ */
/* @0x2ab8fe ldrb r6, [r3, #0x1] */
/* @0x2ab900 mul r6, r6, r11 */
/* @0x2ab904 rsb.w r11, r11, #0xff */
/* @0x2ab908 adds r6, #0x80 */
/* @0x2ab90a mla r6, r11, r8, r6 */
/* @0x2ab90c adcslt r6, r6, #8, #12 */
/* @0x2ab90e uxth r6, r6 */
/* @0x2ab910 add.w r6, r6, r6, lsr #8 */
/* @0x2ab914 asrs r6, r6, #0x8 */
/* @0x2ab916 strb r6, [r3, #0x1] */
/* @0x2ab918 ldr.w r6, [r4, #0x24c] */
/* @0x2ab91c ldrb.w r11, [r6, r2] */
/* @0x2ab920 ldrb r6, [r3, #0x2] */
/* @0x2ab922 mul r6, r6, r11 */
/* @0x2ab924 .word 0xf1cbf60b */
/* @0x2ab926 rsb.w r11, r11, #0xff */
/* @0x2ab928 .word 0x36800bff */
/* @0x2ab92a adds r6, #0x80 */
/* @0x2ab92c mla r6, r11, r9, r6 */
/* @0x2ab930 uxth r6, r6 */
/* @0x2ab932 add.w r6, r6, r6, lsr #8 */
/* @0x2ab934 eorsne r2, r6, #23068672 */
/* @0x2ab936 asrs r6, r6, #0x8 */
/* @0x2ab938 strb r6, [r3, #0x2] */
/* @0x2ab93a adds r2, #0x1 */
/* @0x2ab93c adds r3, #0x3 */
/* @0x2ab93e b 0x2ab8c0 <png_init_read_transformations+0x748> */
/* @0x2ab940 ldr.w r3, [r4, #0x134] */
/* @0x2ab944 bic r3, r3, #0x80 */
/* @0x2ab948 str.w r3, [r4, #0x134] */
/* @0x2ab94c ldr.w r3, [r4, #0x130] */
/* @0x2ab950 orr r3, r3, #0x400000 */
/* @0x2ab954 str.w r3, [r4, #0x130] */
/* @0x2ab958 ldr.w r2, [r4, #0x134] */
/* @0x2ab95c movw r3, #0x1008 */
/* @0x2ab960 ands r3, r2 */
/* @0x2ab962 cmp r3, #0x8 */
/* @0x2ab964 bne 0x2ab9e4 <png_init_read_transformations+0x86c> */
/* @0x2ab966 cmp.w r10, #0x3 */
/* @0x2ab968 teqle r11, r3, lsl #30 */
/* @0x2ab96a bne 0x2ab9e4 <png_init_read_transformations+0x86c> */
/* @0x2ab96c ldrb.w r2, [r4, #0x240] */
/* @0x2ab970 movs r3, #0x0 */
/* @0x2ab972 ldrb.w r1, [r4, #0x241] */
/* @0x2ab974 .word 0xf8941241 */
/* @0x2ab976 ldrb.w r0, [r4, #0x242] */
/* @0x2ab978 .word 0xf1c20242 */
/* @0x2ab97a rsb.w r2, r2, #0x8 */
/* @0x2ab97c .word 0xf1c10208 */
/* @0x2ab97e rsb.w r1, r1, #0x8 */
/* @0x2ab980 rfeia r4! */
/* @0x2ab982 ldrh.w r7, [r4, #0x1dc] */
/* @0x2ab984 .word 0xf1c071dc */
/* @0x2ab986 rsb.w r0, r0, #0x8 */
/* @0x2ab988 bhs 0x4ab9b0 <SrcVerts+0x89f4> */
/* @0x2ab98a cmp r2, #0x8 */
/* @0x2ab98c it hi */
/* @0x2ab98e movhi r2, #0x0 */
/* @0x2ab990 cmp r1, #0x8 */
/* @0x2ab992 it hi */
/* @0x2ab994 movhi r1, #0x0 */
/* @0x2ab996 cmp r0, #0x8 */
/* @0x2ab998 it hi */
/* @0x2ab99a movhi r0, #0x0 */
/* @0x2ab99c uxth r5, r3 */
/* @0x2ab99e cmp r5, r7 */
/* @0x2ab9a0 bhs 0x2ab9d8 <png_init_read_transformations+0x860> */
/* @0x2ab9a2 mul r5, r10, r3 */
/* @0x2ab9a4 .word 0xf8d4f503 */
/* @0x2ab9a6 ldr.w r6, [r4, #0x1d8] */
/* @0x2ab9a8 movwlo r6, #0x11d8 */
/* @0x2ab9aa adds r3, #0x1 */
/* @0x2ab9ac ldrb.w r12, [r6, r5] */
/* @0x2ab9b0 asr.w r12, r12, r2 */
/* @0x2ab9b4 strb.w r12, [r6, r5] */
/* @0x2ab9b8 ldr.w r6, [r4, #0x1d8] */
/* @0x2ab9bc add r6, r5 */
/* @0x2ab9be ldrb.w r12, [r6, #0x1] */
/* @0x2ab9c0 blx 0x15db9cc <b2_toiTime+0xe82528> */
/* @0x2ab9c2 asr.w r12, r12, r1 */
/* @0x2ab9c4 .word 0xf886fc01 */
/* @0x2ab9c6 strb.w r12, [r6, #0x1] */
/* @0x2ab9c8 .word 0xf8d4c001 */
/* @0x2ab9ca ldr.w r6, [r4, #0x1d8] */
/* @0x2ab9cc ldrtmi r6, [r5], #-472 */
/* @0x2ab9ce add r5, r6 */
/* @0x2ab9d0 ldrb r6, [r5, #0x2] */
/* @0x2ab9d2 asrs r6, r0 */
/* @0x2ab9d4 strb r6, [r5, #0x2] */
/* @0x2ab9d6 b 0x2ab99c <png_init_read_transformations+0x824> */
/* @0x2ab9d8 ldr.w r3, [r4, #0x134] */
/* @0x2ab9dc bic r3, r3, #0x8 */
/* @0x2ab9e0 str.w r3, [r4, #0x134] */
/* @0x2ab9e4 add sp, #0xc */
/* @0x2ab9e6 vpop {d8, d9, d10, d11} */
/* @0x2ab9e8 pop {r3, r8, r9, r11, pc} */
/* @0x2ab9ea pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ab9ec svclt #0x8ff0 */
/* @0x2ab9ee nop */
/* @0x2ab9f0 asrs r0, r5, #0x11 */
/* @0x2ab9f2 movs r6, r1 */

/* ── FUNC 0x2ab9f4 · anon_2ab9f4 · size=0 · insn=1 */
/* @0x2ab9f4 andhi pc, r0, pc, lsr #7 */

/* ── FUNC 0x2ab9f8 · png_do_read_intrapixel · size=134 · insn=67 */
/* @0x2ab9f8 push {r4, r5, r6, r7, lr} */
/* @0x2ab9fa ldrb r3, [r0, #0x8] */
/* @0x2ab9fc lsls r2, r3, #0x1e */
/* @0x2ab9fe bpl 0x2aba7c <png_do_read_intrapixel+0x84> */
/* @0x2aba00 ldr r2, [r0] */
/* @0x2aba02 ldrb r0, [r0, #0x9] */
/* @0x2aba04 cmp r0, #0x8 */
/* @0x2aba06 bne 0x2aba32 <png_do_read_intrapixel+0x3a> */
/* @0x2aba08 cmp r3, #0x2 */
/* @0x2aba0a beq 0x2aba14 <png_do_read_intrapixel+0x1c> */
/* @0x2aba0c cmp r3, #0x6 */
/* @0x2aba0e bne 0x2aba7c <png_do_read_intrapixel+0x84> */
/* @0x2aba10 movs r0, #0x4 */
/* @0x2aba12 b 0x2aba16 <png_do_read_intrapixel+0x1e> */
/* @0x2aba14 movs r0, #0x3 */
/* @0x2aba16 movs r3, #0x0 */
/* @0x2aba18 cmp r3, r2 */
/* @0x2aba1a beq 0x2aba30 <png_do_read_intrapixel+0x38> */
/* @0x2aba1c ldrb r4, [r1, #0x1] */
/* @0x2aba1e adds r3, #0x1 */
/* @0x2aba20 ldrb r5, [r1] */
/* @0x2aba22 add r5, r4 */
/* @0x2aba24 strb r5, [r1] */
/* @0x2aba26 ldrb r5, [r1, #0x2] */
/* @0x2aba28 add r4, r5 */
/* @0x2aba2a strb r4, [r1, #0x2] */
/* @0x2aba2c add r1, r0 */
/* @0x2aba2e b 0x2aba18 <png_do_read_intrapixel+0x20> */
/* @0x2aba30 pop {r4, r5, r6, r7, pc} */
/* @0x2aba32 cmp r0, #0x10 */
/* @0x2aba34 bne 0x2aba7c <png_do_read_intrapixel+0x84> */
/* @0x2aba36 cmp r3, #0x2 */
/* @0x2aba38 beq 0x2aba42 <png_do_read_intrapixel+0x4a> */
/* @0x2aba3a cmp r3, #0x6 */
/* @0x2aba3c bne 0x2aba7c <png_do_read_intrapixel+0x84> */
/* @0x2aba3e movs r0, #0x8 */
/* @0x2aba40 b 0x2aba44 <png_do_read_intrapixel+0x4c> */
/* @0x2aba42 movs r0, #0x6 */
/* @0x2aba44 movs r3, #0x0 */
/* @0x2aba46 cmp r3, r2 */
/* @0x2aba48 beq 0x2aba7c <png_do_read_intrapixel+0x84> */
/* @0x2aba4a ldrb r6, [r1, #0x2] */
/* @0x2aba4c adds r3, #0x1 */
/* @0x2aba4e ldrb r4, [r1, #0x3] */
/* @0x2aba50 ldrb r5, [r1] */
/* @0x2aba52 orr.w r6, r4, r6, lsl #8 */
/* @0x2aba54 stmdavc r12, {r1, r2, r9, r10, sp} ^ */
/* @0x2aba56 ldrb r4, [r1, #0x1] */
/* @0x2aba58 ldrb r7, [r1, #0x4] */
/* @0x2aba5a orr.w r5, r4, r5, lsl #8 */
/* @0x2aba5c stmdbvc r12, {r0, r2, r8, r10, sp} ^ */
/* @0x2aba5e ldrb r4, [r1, #0x5] */
/* @0x2aba60 add r5, r6 */
/* @0x2aba62 orr.w r4, r4, r7, lsl #8 */
/* @0x2aba64 ldrtmi r2, [r4], #-1031 */
/* @0x2aba66 add r4, r6 */
/* @0x2aba68 uxth r5, r5 */
/* @0x2aba6a strb r5, [r1, #0x1] */
/* @0x2aba6c uxth r4, r4 */
/* @0x2aba6e lsrs r6, r5, #0x8 */
/* @0x2aba70 strb r4, [r1, #0x5] */
/* @0x2aba72 strb r6, [r1] */
/* @0x2aba74 lsrs r5, r4, #0x8 */
/* @0x2aba76 strb r5, [r1, #0x4] */
/* @0x2aba78 add r1, r0 */
/* @0x2aba7a b 0x2aba46 <png_do_read_intrapixel+0x4e> */
/* @0x2aba7c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2aba80 · anon_2aba80 · size=232 · insn=59 */
/* @0x2aba80 svcmi #0xf0e92d */
/* @0x2aba84 ldmdami r5!, {r2, r9, r10, lr} */
/* @0x2aba88 ldrmi r11, [r8], pc, lsl #1 */
/* @0x2aba8c blvc 0xfe9e8ea4 <b2_toiTime+0xfffffffffe28fa00> */
/* @0x2aba90 stmdavs r0, {r3, r4, r5, r6, r10, lr} */
/* @0x2aba94 .word 0xa060f8dd */
/* @0x2aba98 .word 0xf8c42500 */
/* @0x2aba9c stmdavs r3, {r3, r4, r5, r8, r12} */
/* @0x2abaa0 .word 0xf8c44681 */
/* @0x2abaa4 movwls r2, #0xd13c */
/* @0x2abaa8 ldrsblo pc, [r0, #-132]! */
/* @0x2abaac qaddhs r4, r8, r0 */
/* @0x2abab0 smlalbtlo pc, r4, r4, r8 */
/* @0x2abab4 ldrsblo pc, [r4, #-132]! */
/* @0x2abab8 smlalbtlo pc, r8, r4, r8 */
/* @0x2ababc svc #0x8ef60a */
/* @0x2abac0 ldrsbvc pc, [r4, #-132]! */
/* @0x2abac4 .word 0x3148f8d4 */
/* @0x2abac8 strmi r2, [r6], -r1, lsl #16 */
/* @0x2abacc bne 0x2a1b2c <_Z10BeginToEndv+0x320> */
/* @0x2abad0 ldcle p15, c2, [r0, #-0] */
/* @0x2abad4 svceq #0xf1b8 */
/* @0x2abad8 strmi sp, [r10, #0xc]! */
/* @0x2abadc bl 0xff421f0c <b2_toiTime+0xfffffffffecc8a68> */
/* @0x2abae0 bl 0x4ac310 <SrcVerts+0x9354> */
/* @0x2abae4 .word 0xf8d40005 */
/* @0x2abae8 adcsmi r1, r10, #112, #2 */
/* @0x2abaec ldrtmi r11, [r10], -r8, lsr #30 */
/* @0x2abaf0 stcl p6, c15, [r4, #-40]! */
/* @0x2abaf4 mcrhs p4, #0x0, r4, c0, c13, #0x1 */
/* @0x2abaf8 .word 0x2601d0d6 */
/* @0x2abafc ldrbmi r2, [r8], -r0, lsl #14 */
/* @0x2abb00 teqvc r12, r4, asr #17 */
/* @0x2abb04 b 0x9e9338 <b2_toiTime+0x28fe94> */
/* @0x2abb08 andsle r2, r10, r1, lsl #28 */
/* @0x2abb0c ldrsblo pc, [r0, #-132] */
/* @0x2abb10 ldclne p9, c11, [r3, #-812]! */
/* @0x2abb14 strlo sp, [r3], -r4 */
/* @0x2abb18 bmi 0x71fb34 <g_SWFvertbuff+0x4ca6c> */
/* @0x2abb1c and r4, r4, r10, ror r4 */
/* @0x2abb20 ldrbtmi r4, [r10], #-2576 */
/* @0x2abb24 bmi 0x6e3b30 <g_SWFvertbuff+0x10a68> */
/* @0x2abb28 teqhs r4, r10, ror r4 */
/* @0x2abb2c mvnsvc pc, #4, #10 */
/* @0x2abb30 .word 0xf60a4668 */
/* @0x2abb34 strtmi lr, [r0], -r10, asr #26 */
/* @0x2abb38 .word 0xf7fa4669 */
/* @0x2abb3c mulhs r0, r11, r12 */
/* @0x2abb40 strtmi lr, [r8], -r2 */
/* @0x2abb44 ldrtmi lr, [r8], -r0 */
/* @0x2abb48 .word 0xf8d99a0d */
/* @0x2abb4c addsmi r3, r10, #0 */
/* @0x2abb50 .word 0xf60ad001 */
/* @0x2abb54 andlt lr, pc, r0, asr #26 */
/* @0x2abb58 svchi #0xf0e8bd */
/* @0x2abb5c andseq r1, r4, r4, asr #29 */
/* @0x2abb60 andeq r1, lr, r8, lsr r0 */
/* @0x2abb64 ldrdeq r0, r1, [lr], -r0 */
/* @0x2abb68 strdeq r0, r1, [lr], -r12 */

/* ── FUNC 0x2abb6c · png_get_uint_31 · size=40 · insn=18 */
/* @0x2abb6c push {r4, lr} */
/* @0x2abb6e ldrb r3, [r1, #0x1] */
/* @0x2abb70 ldrb r2, [r1] */
/* @0x2abb72 lsls r3, r3, #0x10 */
/* @0x2abb74 add.w r3, r3, r2, lsl #24 */
/* @0x2abb78 ldrb r2, [r1, #0x3] */
/* @0x2abb7a add r3, r2 */
/* @0x2abb7c ldrb r2, [r1, #0x2] */
/* @0x2abb7e adds.w r4, r3, r2, lsl #8 */
/* @0x2abb80 strle r2, [r3, #-0x402] */
/* @0x2abb82 bpl 0x2abb8c <png_get_uint_31+0x20> */
/* @0x2abb84 ldr r1, [pc, #0x8] */
/* @0x2abb86 add r1, pc */
/* @0x2abb88 bl 0x2a642c <png_error> */
/* @0x2abb8c mov r0, r4 */
/* @0x2abb8e pop {r4, pc} */
/* @0x2abb90 lsrs r3, r7, #0x1f */
/* @0x2abb92 movs r6, r1 */

/* ── FUNC 0x2abb94 · png_read_sig · size=120 · insn=53 */
/* @0x2abb94 push {r3, r4, r5, r6, r7, lr} */
/* @0x2abb96 mov r5, r0 */
/* @0x2abb98 ldrb.w r4, [r0, #0x1f0] */
/* @0x2abb9c mov r6, r1 */
/* @0x2abb9e cmp r4, #0x7 */
/* @0x2abba0 bhi 0x2abc00 <png_read_sig+0x6c> */
/* @0x2abba2 rsb.w r7, r4, #0x8 */
/* @0x2abba4 .word 0xf1040708 */
/* @0x2abba6 add.w r1, r4, #0x20 */
/* @0x2abba8 ldrtmi r0, [r1], #-288 */
/* @0x2abbaa add r1, r6 */
/* @0x2abbac adds r6, #0x20 */
/* @0x2abbae movs r3, #0x11 */
/* @0x2abbb0 mov r2, r7 */
/* @0x2abbb2 str.w r3, [r0, #0x334] */
/* @0x2abbb4 .word 0xf7fc3334 */
/* @0x2abbb6 bl 0x2a8030 <png_read_data> */
/* @0x2abbb8 movwhs pc, #0x8a3b */
/* @0x2abbba movs r3, #0x8 */
/* @0x2abbbc mov r0, r6 */
/* @0x2abbbe strb.w r3, [r5, #0x1f0] */
/* @0x2abbc0 qsub8mi r3, r1, r0 */
/* @0x2abbc2 mov r1, r4 */
/* @0x2abbc4 mov r2, r7 */
/* @0x2abbc6 bl 0x2a5a4c <png_sig_cmp> */
/* @0x2abbc8 orrlt pc, r8, r1, asr #30 */
/* @0x2abbca cbz r0, 0x2abbf0 <png_read_sig+0x5c> */
/* @0x2abbcc cmp r4, #0x3 */
/* @0x2abbce bhi 0x2abbe6 <png_read_sig+0x52> */
/* @0x2abbd0 mov r0, r6 */
/* @0x2abbd2 mov r1, r4 */
/* @0x2abbd4 rsb.w r2, r4, #0x4 */
/* @0x2abbd8 bl 0x2a5a4c <png_sig_cmp> */
/* @0x2abbdc cbz r0, 0x2abbe6 <png_read_sig+0x52> */
/* @0x2abbde ldr r1, [pc, #0x24] */
/* @0x2abbe0 mov r0, r5 */
/* @0x2abbe2 add r1, pc */
/* @0x2abbe4 b 0x2abbec <png_read_sig+0x58> */
/* @0x2abbe6 ldr r1, [pc, #0x20] */
/* @0x2abbe8 mov r0, r5 */
/* @0x2abbea add r1, pc */
/* @0x2abbec bl 0x2a642c <png_error> */
/* @0x2abbf0 cmp r4, #0x2 */
/* @0x2abbf2 bhi 0x2abc00 <png_read_sig+0x6c> */
/* @0x2abbf4 ldr.w r3, [r5, #0x12c] */
/* @0x2abbf8 orr r3, r3, #0x1000 */
/* @0x2abbfc str.w r3, [r5, #0x12c] */
/* @0x2abc00 pop {r3, r4, r5, r6, r7, pc} */
/* @0x2abc02 nop */
/* @0x2abc04 lsrs r1, r0, #0x1f */
/* @0x2abc06 movs r6, r1 */
/* @0x2abc08 lsrs r0, r1, #0x1f */
/* @0x2abc0a movs r6, r1 */

/* ── FUNC 0x2abc0c · png_crc_read · size=30 · insn=13 */
/* @0x2abc0c push {r4, r5, r6, lr} */
/* @0x2abc0e mov r5, r1 */
/* @0x2abc10 mov r4, r2 */
/* @0x2abc12 mov r6, r0 */
/* @0x2abc14 cbz r0, 0x2abc28 <png_crc_read+0x1c> */
/* @0x2abc16 bl 0x2a8030 <png_read_data> */
/* @0x2abc18 ldrtmi pc, [r0], -r11, lsl #20 */
/* @0x2abc1a mov r0, r6 */
/* @0x2abc1c mov r1, r5 */
/* @0x2abc1e mov r2, r4 */
/* @0x2abc20 pop.w {r4, r5, r6, lr} */
/* @0x2abc24 b.w 0x2a5b08 <png_calculate_crc> */
/* @0x2abc28 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2abc2a · png_crc_error · size=104 · insn=43 */
/* @0x2abc2a push {r0, r1, r2, r4, r5, lr} */
/* @0x2abc2c mov r4, r0 */
/* @0x2abc2e ldrb.w r3, [r0, #0x1e0] */
/* @0x2abc32 ldr.w r5, [r0, #0x130] */
/* @0x2abc36 tst.w r3, #0x20 */
/* @0x2abc3a beq 0x2abc4a <png_crc_error+0x20> */
/* @0x2abc3c and r5, r5, #0x300 */
/* @0x2abc3e .word 0xf5b57540 */
/* @0x2abc40 subs.w r5, r5, #0x300 */
/* @0x2abc42 svclt #0x187540 */
/* @0x2abc44 it ne */
/* @0x2abc46 movne r5, #0x1 */
/* @0x2abc48 b 0x2abc52 <png_crc_error+0x28> */
/* @0x2abc4a eor r5, r5, #0x800 */
/* @0x2abc4e ubfx r5, r5, #0xb, #0x1 */
/* @0x2abc52 movs r3, #0x81 */
/* @0x2abc54 mov r0, r4 */
/* @0x2abc56 str.w r3, [r4, #0x334] */
/* @0x2abc5a add r1, sp, #0x4 */
/* @0x2abc5c movs r2, #0x4 */
/* @0x2abc5e bl 0x2a8030 <png_read_data> */
/* @0x2abc62 cbz r5, 0x2abc8c <png_crc_error+0x62> */
/* @0x2abc64 ldrb.w r0, [sp, #0x5] */
/* @0x2abc66 .word 0xf89d0005 */
/* @0x2abc68 ldrb.w r3, [sp, #0x4] */
/* @0x2abc6a .word 0xf89d3004 */
/* @0x2abc6c ldrb.w r5, [sp, #0x6] */
/* @0x2abc6e streq r5, [r0], #-6 */
/* @0x2abc70 lsls r0, r0, #0x10 */
/* @0x2abc72 add.w r0, r0, r3, lsl #24 */
/* @0x2abc76 ldrb.w r3, [sp, #0x7] */
/* @0x2abc7a add r0, r3 */
/* @0x2abc7c ldr.w r3, [r4, #0x1d4] */
/* @0x2abc7e bl 0x2b83d6 <jinit_phuff_decoder+0x3fa> */
/* @0x2abc80 add.w r0, r0, r5, lsl #8 */
/* @0x2abc82 bne 0xff2b3c9e <b2_toiTime+0xfffffffffeb5a7fa> */
/* @0x2abc84 subs r0, r0, r3 */
/* @0x2abc86 it ne */
/* @0x2abc88 movne r0, #0x1 */
/* @0x2abc8a b 0x2abc8e <png_crc_error+0x64> */
/* @0x2abc8c mov r0, r5 */
/* @0x2abc8e add sp, #0xc */
/* @0x2abc90 pop {r4, r5, pc} */

/* ── FUNC 0x2abc92 · anon_2abc92 · size=0 · insn=1 */
/* @0x2abc92 ldrblt r0, [r0, #-0x0]! */

/* ── FUNC 0x2abc94 · png_crc_finish · size=116 · insn=52 */
/* @0x2abc94 push {r4, r5, r6, lr} */
/* @0x2abc96 mov r4, r0 */
/* @0x2abc98 ldr.w r6, [r0, #0x174] */
/* @0x2abc9c mov r5, r1 */
/* @0x2abc9e cmp r5, r6 */
/* @0x2abca0 bls 0x2abcb4 <png_crc_finish+0x20> */
/* @0x2abca2 mov r0, r4 */
/* @0x2abca4 ldr.w r1, [r4, #0x170] */
/* @0x2abca8 ldr.w r2, [r4, #0x174] */
/* @0x2abcac subs r5, r5, r6 */
/* @0x2abcae bl 0x2abc0c <png_crc_read> */
/* @0x2abcb0 ldrb pc, [r4, sp, lsr #31]! */
/* @0x2abcb2 b 0x2abc9e <png_crc_finish+0xa> */
/* @0x2abcb4 cbz r5, 0x2abcc2 <png_crc_finish+0x2e> */
/* @0x2abcb6 mov r0, r4 */
/* @0x2abcb8 ldr.w r1, [r4, #0x170] */
/* @0x2abcbc mov r2, r5 */
/* @0x2abcbe bl 0x2abc0c <png_crc_read> */
/* @0x2abcc0 strtmi pc, [r0], -r5, lsr #31 */
/* @0x2abcc2 mov r0, r4 */
/* @0x2abcc4 bl 0x2abc2a <png_crc_error> */
/* @0x2abcc8 cbz r0, 0x2abcfc <png_crc_finish+0x68> */
/* @0x2abcca ldrb.w r3, [r4, #0x1e0] */
/* @0x2abccc .word 0xf01331e0 */
/* @0x2abcce tst.w r3, #0x20 */
/* @0x2abcd0 .word 0xf8d40f20 */
/* @0x2abcd2 ldr.w r3, [r4, #0x130] */
/* @0x2abcd4 andle r3, r2, r0, lsr r1 */
/* @0x2abcd6 beq 0x2abcde <png_crc_finish+0x4a> */
/* @0x2abcd8 lsls r2, r3, #0x16 */
/* @0x2abcda bmi 0x2abcf0 <png_crc_finish+0x5c> */
/* @0x2abcdc b 0x2abce2 <png_crc_finish+0x4e> */
/* @0x2abcde lsls r3, r3, #0x15 */
/* @0x2abce0 bpl 0x2abcf0 <png_crc_finish+0x5c> */
/* @0x2abce2 ldr r1, [pc, #0x1c] */
/* @0x2abce4 mov r0, r4 */
/* @0x2abce6 add r1, pc */
/* @0x2abce8 bl 0x2a6504 <png_chunk_warning> */
/* @0x2abcec movs r0, #0x1 */
/* @0x2abcee pop {r4, r5, r6, pc} */
/* @0x2abcf0 ldr r1, [pc, #0x10] */
/* @0x2abcf2 mov r0, r4 */
/* @0x2abcf4 add r1, pc */
/* @0x2abcf6 bl 0x2a64cc <png_chunk_error> */
/* @0x2abcf8 andhs pc, r0, r9, ror #23 */
/* @0x2abcfa movs r0, #0x0 */
/* @0x2abcfc pop {r4, r5, r6, pc} */
/* @0x2abcfe nop */
/* @0x2abd00 lsls r6, r0, #0xf */
/* @0x2abd02 movs r6, r1 */
/* @0x2abd04 lsls r0, r7, #0xe */
/* @0x2abd06 movs r6, r1 */

/* ── FUNC 0x2abd08 · png_decompress_chunk · size=328 · insn=144 */
/* @0x2abd08 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2abd0c mov r5, r3 */
/* @0x2abd0e ldr r3, [pc, #0x128] */
/* @0x2abd10 mov r6, r1 */
/* @0x2abd12 sub sp, #0x44 */
/* @0x2abd14 cmp r5, r2 */
/* @0x2abd16 add r3, pc */
/* @0x2abd18 ldr r3, [r3] */
/* @0x2abd1a mov r4, r0 */
/* @0x2abd1c ldr.w r8, [sp, #0x68] */
/* @0x2abd20 ldr r1, [r3] */
/* @0x2abd22 mov r10, r3 */
/* @0x2abd24 str r1, [sp, #0x3c] */
/* @0x2abd26 bls 0x2abd34 <png_decompress_chunk+0x2c> */
/* @0x2abd28 ldr r1, [pc, #0x110] */
/* @0x2abd2a movs r5, #0x0 */
/* @0x2abd2c add r1, pc */
/* @0x2abd2e bl 0x2a6474 <png_warning> */
/* @0x2abd30 subs pc, pc, r1, lsr #23 */
/* @0x2abd32 b 0x2abdf4 <png_decompress_chunk+0xec> */
/* @0x2abd34 cmp r6, #0x0 */
/* @0x2abd36 bne 0x2abddc <png_decompress_chunk+0xd4> */
/* @0x2abd38 ldr.w r1, [r0, #0x330] */
/* @0x2abd3c rsb r9, r5, r2 */
/* @0x2abd40 mov r3, r6 */
/* @0x2abd42 str r6, [sp] */
/* @0x2abd44 add r1, r5 */
/* @0x2abd46 mov r2, r9 */
/* @0x2abd48 bl 0x2aba80 <png_do_read_intrapixel+0x88> */
/* @0x2abd4c adds r3, r5, #0x3 */
/* @0x2abd4e mov r6, r0 */
/* @0x2abd50 bhi 0x2abd6a <png_decompress_chunk+0x62> */
/* @0x2abd52 mvn r3, #0x1 */
/* @0x2abd54 blne 0x196c960 <b2_toiTime+0x12134bc> */
/* @0x2abd56 subs r3, r3, r5 */
/* @0x2abd58 cmp r0, r3 */
/* @0x2abd5a bhs 0x2abd6a <png_decompress_chunk+0x62> */
/* @0x2abd5c ldr.w r3, [r4, #0x1a0] */
/* @0x2abd60 cbz r3, 0x2abd72 <png_decompress_chunk+0x6a> */
/* @0x2abd62 adds r2, r0, r5 */
/* @0x2abd64 subs r3, #0x1 */
/* @0x2abd66 cmp r2, r3 */
/* @0x2abd68 blo 0x2abd72 <png_decompress_chunk+0x6a> */
/* @0x2abd6a ldr r1, [pc, #0xd4] */
/* @0x2abd6c mov r0, r4 */
/* @0x2abd6e add r1, pc */
/* @0x2abd70 b 0x2abdf0 <png_decompress_chunk+0xe8> */
/* @0x2abd72 cmp r6, #0x0 */
/* @0x2abd74 beq 0x2abdf4 <png_decompress_chunk+0xec> */
/* @0x2abd76 add.w r11, r6, r5 */
/* @0x2abd78 strtmi r0, [r0], -r5, lsl #22 */
/* @0x2abd7a mov r0, r4 */
/* @0x2abd7c add.w r1, r11, #0x1 */
/* @0x2abd80 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2abd84 mov r7, r0 */
/* @0x2abd86 cbz r0, 0x2abdd4 <png_decompress_chunk+0xcc> */
/* @0x2abd88 ldr.w r1, [r4, #0x330] */
/* @0x2abd8c mov r2, r5 */
/* @0x2abd8e blx 0xb65bc <memcpy@plt> */
/* @0x2abd90 .word 0xf8d4ec16 */
/* @0x2abd92 ldr.w r1, [r4, #0x330] */
/* @0x2abd94 ldmdbne r11!, {r4, r5, r8, r9, r12} ^ */
/* @0x2abd96 adds r3, r7, r5 */
/* @0x2abd98 str r6, [sp] */
/* @0x2abd9a mov r0, r4 */
/* @0x2abd9c add r1, r5 */
/* @0x2abd9e mov r2, r9 */
/* @0x2abda0 bl 0x2aba80 <png_do_read_intrapixel+0x88> */
/* @0x2abda4 movs r3, #0x0 */
/* @0x2abda6 strb.w r3, [r7, r11] */
/* @0x2abda8 adcsmi r3, r0, #11 */
/* @0x2abdaa cmp r0, r6 */
/* @0x2abdac mov r0, r4 */
/* @0x2abdae bne 0x2abdc2 <png_decompress_chunk+0xba> */
/* @0x2abdb0 ldr.w r1, [r4, #0x330] */
/* @0x2abdb4 bl 0x2a6cfc <png_free> */
/* @0x2abdb8 str.w r7, [r4, #0x330] */
/* @0x2abdbc str.w r11, [r8] */
/* @0x2abdc0 b 0x2abe22 <png_decompress_chunk+0x11a> */
/* @0x2abdc2 ldr r1, [pc, #0x80] */
/* @0x2abdc4 add r1, pc */
/* @0x2abdc6 bl 0x2a6474 <png_warning> */
/* @0x2abdc8 qsaxmi pc, r0, r5 */
/* @0x2abdca mov r0, r4 */
/* @0x2abdcc mov r1, r7 */
/* @0x2abdce bl 0x2a6cfc <png_free> */
/* @0x2abdd0 mul pc, r5, pc */
/* @0x2abdd2 b 0x2abdf4 <png_decompress_chunk+0xec> */
/* @0x2abdd4 ldr r1, [pc, #0x70] */
/* @0x2abdd6 mov r0, r4 */
/* @0x2abdd8 add r1, pc */
/* @0x2abdda b 0x2abdf0 <png_decompress_chunk+0xe8> */
/* @0x2abddc add r7, sp, #0x8 */
/* @0x2abdde ldr r2, [pc, #0x6c] */
/* @0x2abde0 movs r1, #0x32 */
/* @0x2abde2 mov r3, r6 */
/* @0x2abde4 mov r0, r7 */
/* @0x2abde6 add r2, pc */
/* @0x2abde8 blx 0xb65c8 <snprintf@plt> */
/* @0x2abdec mov r0, r4 */
/* @0x2abdee mov r1, r7 */
/* @0x2abdf0 bl 0x2a6474 <png_warning> */
/* @0x2abdf4 mov r0, r4 */
/* @0x2abdf6 adds r1, r5, #0x1 */
/* @0x2abdf8 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2abdfc mov r6, r0 */
/* @0x2abdfe cbz r0, 0x2abe1e <png_decompress_chunk+0x116> */
/* @0x2abe00 cbz r5, 0x2abe0c <png_decompress_chunk+0x104> */
/* @0x2abe02 ldr.w r1, [r4, #0x330] */
/* @0x2abe04 qasxmi r1, r10, r0 */
/* @0x2abe06 mov r2, r5 */
/* @0x2abe08 blx 0xb65bc <memcpy@plt> */
/* @0x2abe0c mov r0, r4 */
/* @0x2abe0e ldr.w r1, [r4, #0x330] */
/* @0x2abe10 .word 0xf7fa1330 */
/* @0x2abe12 bl 0x2a6cfc <png_free> */
/* @0x2abe14 .word 0xf8c4ff73 */
/* @0x2abe16 str.w r6, [r4, #0x330] */
/* @0x2abe18 movwhs r6, #0x330 */
/* @0x2abe1a movs r3, #0x0 */
/* @0x2abe1c strb r3, [r6, r5] */
/* @0x2abe1e str.w r5, [r8] */
/* @0x2abe20 bls 0x67fe28 <g_SWFlinevertbuff+0x2cd60> */
/* @0x2abe22 ldr r2, [sp, #0x3c] */
/* @0x2abe24 ldr.w r3, [r10] */
/* @0x2abe28 cmp r2, r3 */
/* @0x2abe2a beq 0x2abe30 <png_decompress_chunk+0x128> */
/* @0x2abe2c blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2abe30 add sp, #0x44 */
/* @0x2abe32 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2abe34 svclt #0x8ff0 */
/* @0x2abe36 nop */
/* @0x2abe38 adds r6, r7, #0x0 */
/* @0x2abe3a movs r4, r2 */
/* @0x2abe3c lsrs r5, r5, #0x1a */
/* @0x2abe3e movs r6, r1 */
/* @0x2abe40 lsrs r7, r7, #0x19 */
/* @0x2abe42 movs r6, r1 */
/* @0x2abe44 lsrs r3, r2, #0x19 */
/* @0x2abe46 movs r6, r1 */
/* @0x2abe48 lsrs r7, r2, #0x19 */
/* @0x2abe4a movs r6, r1 */
/* @0x2abe4c lsrs r7, r5, #0x19 */
/* @0x2abe4e movs r6, r1 */

/* ── FUNC 0x2abe50 · png_handle_IHDR · size=276 · insn=124 */
/* @0x2abe50 ldr r3, [pc, #0x104] */
/* @0x2abe52 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2abe54 ldrbtmi r4, [r11], #-1008 */
/* @0x2abe56 add r3, pc */
/* @0x2abe58 ldr r3, [r3] */
/* @0x2abe5a mov r8, r1 */
/* @0x2abe5c ldr.w r1, [r0, #0x12c] */
/* @0x2abe60 mov r5, r2 */
/* @0x2abe62 ldr r2, [r3] */
/* @0x2abe64 sub sp, #0x34 */
/* @0x2abe66 tst.w r1, #0x1 */
/* @0x2abe68 strmi r0, [r4], -r1, lsl #30 */
/* @0x2abe6a mov r4, r0 */
/* @0x2abe6c mov r9, r3 */
/* @0x2abe6e str r2, [sp, #0x2c] */
/* @0x2abe70 beq 0x2abe7a <png_handle_IHDR+0x2a> */
/* @0x2abe72 ldr r1, [pc, #0xe8] */
/* @0x2abe74 add r1, pc */
/* @0x2abe76 bl 0x2a642c <png_error> */
/* @0x2abe78 vstrhs s30, [sp, #-868] */
/* @0x2abe7a cmp r5, #0xd */
/* @0x2abe7c beq 0x2abe88 <png_handle_IHDR+0x38> */
/* @0x2abe7e ldr r1, [pc, #0xe0] */
/* @0x2abe80 mov r0, r4 */
/* @0x2abe82 add r1, pc */
/* @0x2abe84 bl 0x2a642c <png_error> */
/* @0x2abe88 ldr.w r3, [r4, #0x12c] */
/* @0x2abe8c add r6, sp, #0x1c */
/* @0x2abe8e movs r2, #0xd */
/* @0x2abe90 mov r0, r4 */
/* @0x2abe92 orr r3, r3, #0x1 */
/* @0x2abe94 ldrtmi r0, [r1], -r1, lsl #6 */
/* @0x2abe96 mov r1, r6 */
/* @0x2abe98 str.w r3, [r4, #0x12c] */
/* @0x2abe9c bl 0x2abc0c <png_crc_read> */
/* @0x2abea0 movs r1, #0x0 */
/* @0x2abea2 mov r0, r4 */
/* @0x2abea4 bl 0x2abc94 <png_crc_finish> */
/* @0x2abea8 mov r1, r6 */
/* @0x2abeaa mov r0, r4 */
/* @0x2abeac bl 0x2abb6c <png_get_uint_31> */
/* @0x2abeb0 adds r1, r6, #0x4 */
/* @0x2abeb2 mov r5, r0 */
/* @0x2abeb4 mov r0, r4 */
/* @0x2abeb6 bl 0x2abb6c <png_get_uint_31> */
/* @0x2abeb8 .word 0xf89dfe59 */
/* @0x2abeba ldrb.w r7, [sp, #0x24] */
/* @0x2abebc .word 0xf89d7024 */
/* @0x2abebe ldrb.w r2, [sp, #0x25] */
/* @0x2abec0 .word 0xf89d2025 */
/* @0x2abec2 ldrb.w r1, [sp, #0x27] */
/* @0x2abec4 .word 0xf89d1027 */
/* @0x2abec6 ldrb.w lr, [sp, #0x28] */
/* @0x2abec8 .word 0xf8c4e028 */
/* @0x2abeca str.w r5, [r4, #0x18c] */
/* @0x2abecc .word 0xf884518c */
/* @0x2abece strb.w r7, [r4, #0x1eb] */
/* @0x2abed0 .word 0xf88471eb */
/* @0x2abed2 strb.w lr, [r4, #0x1e7] */
/* @0x2abed4 .word 0xf884e1e7 */
/* @0x2abed6 strb.w r2, [r4, #0x1ea] */
/* @0x2abed8 .word 0xf88421ea */
/* @0x2abeda strb.w r1, [r4, #0x2e4] */
/* @0x2abedc strmi r1, [r3], -r4, ror #5 */
/* @0x2abede mov r3, r0 */
/* @0x2abee0 ldrb.w r0, [sp, #0x26] */
/* @0x2abee4 str.w r3, [r4, #0x190] */
/* @0x2abee8 strb.w r0, [r4, #0x304] */
/* @0x2abeec cmp r2, #0x6 */
/* @0x2abeee bhi 0x2abf0e <png_handle_IHDR+0xbe> */
/* @0x2abef0 tbb [pc, r2] */
/* @0x2abef4 lsrs r4, r0, #0x14 */
/* @0x2abef6 lsls r6, r0, #0x10 */
/* @0x2abef8 lsrs r0, r1, #0x14 */
/* @0x2abefa movs r2, r1 */
/* @0x2abefc movs r6, #0x1 */
/* @0x2abefe b 0x2abf0a <png_handle_IHDR+0xba> */
/* @0x2abf00 movs r6, #0x3 */
/* @0x2abf02 b 0x2abf0a <png_handle_IHDR+0xba> */
/* @0x2abf04 movs r6, #0x2 */
/* @0x2abf06 b 0x2abf0a <png_handle_IHDR+0xba> */
/* @0x2abf08 movs r6, #0x4 */
/* @0x2abf0a strb.w r6, [r4, #0x1ee] */
/* @0x2abf0c .word 0xf89461ee */
/* @0x2abf0e ldrb.w r6, [r4, #0x1ee] */
/* @0x2abf10 cmnmi lr, #-2147483589 */
/* @0x2abf12 muls r6, r7, r6 */
/* @0x2abf14 uxtb r6, r6 */
/* @0x2abf16 strb.w r6, [r4, #0x1ed] */
/* @0x2abf18 cdphs p1, #0x0, c6, c7, c13, #0x7 */
/* @0x2abf1a cmp r6, #0x7 */
/* @0x2abf1c bls 0x2abf24 <png_handle_IHDR+0xd4> */
/* @0x2abf1e lsrs r6, r6, #0x3 */
/* @0x2abf20 muls r6, r5, r6 */
/* @0x2abf22 b 0x2abf2a <png_handle_IHDR+0xda> */
/* @0x2abf24 muls r6, r5, r6 */
/* @0x2abf26 adds r6, #0x7 */
/* @0x2abf28 lsrs r6, r6, #0x3 */
/* @0x2abf2a str r2, [sp, #0x4] */
/* @0x2abf2c mov r2, r5 */
/* @0x2abf2e str r0, [sp, #0xc] */
/* @0x2abf30 mov r0, r4 */
/* @0x2abf32 str r1, [sp, #0x10] */
/* @0x2abf34 mov r1, r8 */
/* @0x2abf36 str.w r6, [r4, #0x19c] */
/* @0x2abf38 .word 0x9700619c */
/* @0x2abf3a str r7, [sp] */
/* @0x2abf3c str.w lr, [sp, #0x8] */
/* @0x2abf40 bl 0x2aea84 <png_set_IHDR> */
/* @0x2abf44 ldr r2, [sp, #0x2c] */
/* @0x2abf46 ldr.w r3, [r9] */
/* @0x2abf48 addsmi r3, r10, #0 */
/* @0x2abf4a cmp r2, r3 */
/* @0x2abf4c beq 0x2abf52 <png_handle_IHDR+0x102> */
/* @0x2abf4e blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2abf50 andlt lr, sp, r2, asr #22 */
/* @0x2abf52 add sp, #0x34 */
/* @0x2abf54 pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2abf58 subs r6, r7, r3 */
/* @0x2abf5a movs r4, r2 */
/* @0x2abf5c lsrs r2, r0, #0x18 */
/* @0x2abf5e movs r6, r1 */
/* @0x2abf60 lsrs r6, r0, #0x18 */
/* @0x2abf62 movs r6, r1 */

/* ── FUNC 0x2abf64 · png_handle_PLTE · size=356 · insn=163 */
/* @0x2abf64 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2abf68 mov r5, r2 */
/* @0x2abf6a ldr.w r3, [r0, #0x12c] */
/* @0x2abf6c .word 0xf5ad312c */
/* @0x2abf6e sub.w sp, sp, #0x30c */
/* @0x2abf70 strmi r7, [r4], -r3, asr #26 */
/* @0x2abf72 mov r4, r0 */
/* @0x2abf74 mov r6, r1 */
/* @0x2abf76 lsls r2, r3, #0x1f */
/* @0x2abf78 bmi 0x2abf80 <png_handle_PLTE+0x1c> */
/* @0x2abf7a ldr r1, [pc, #0x12c] */
/* @0x2abf7c add r1, pc */
/* @0x2abf7e b 0x2abf92 <png_handle_PLTE+0x2e> */
/* @0x2abf80 lsls r7, r3, #0x1d */
/* @0x2abf82 bpl 0x2abf8a <png_handle_PLTE+0x26> */
/* @0x2abf84 ldr r1, [pc, #0x124] */
/* @0x2abf86 add r1, pc */
/* @0x2abf88 b 0x2abfb0 <png_handle_PLTE+0x4c> */
/* @0x2abf8a lsls r1, r3, #0x1e */
/* @0x2abf8c bpl 0x2abf96 <png_handle_PLTE+0x32> */
/* @0x2abf8e ldr r1, [pc, #0x120] */
/* @0x2abf90 add r1, pc */
/* @0x2abf92 bl 0x2a642c <png_error> */
/* @0x2abf94 .word 0xf894fa4b */
/* @0x2abf96 ldrb.w r7, [r4, #0x1ea] */
/* @0x2abf98 .word 0xf8d471ea */
/* @0x2abf9a ldr.w r3, [r4, #0x12c] */
/* @0x2abf9c ldreq r3, [r10, r12, lsr #2]! */
/* @0x2abf9e lsls r2, r7, #0x1e */
/* @0x2abfa0 orr r3, r3, #0x2 */
/* @0x2abfa4 str.w r3, [r4, #0x12c] */
/* @0x2abfa8 bmi 0x2abfbe <png_handle_PLTE+0x5a> */
/* @0x2abfaa ldr r1, [pc, #0x108] */
/* @0x2abfac mov r0, r4 */
/* @0x2abfae add r1, pc */
/* @0x2abfb0 bl 0x2a6474 <png_warning> */
/* @0x2abfb4 mov r0, r4 */
/* @0x2abfb6 mov r1, r5 */
/* @0x2abfb8 bl 0x2abc94 <png_crc_finish> */
/* @0x2abfbc b 0x2ac09e <png_handle_PLTE+0x13a> */
/* @0x2abfbe cmp.w r5, #0x300 */
/* @0x2abfc0 stmdale r4, {r6, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2abfc2 bhi 0x2abfce <png_handle_PLTE+0x6a> */
/* @0x2abfc4 mov r0, r5 */
/* @0x2abfc6 movs r1, #0x3 */
/* @0x2abfc8 blx 0x318cf0 <__aeabi_uidivmod> */
/* @0x2abfcc cbz r1, 0x2abfe2 <png_handle_PLTE+0x7e> */
/* @0x2abfce cmp r7, #0x3 */
/* @0x2abfd0 mov r0, r4 */
/* @0x2abfd2 beq 0x2abfda <png_handle_PLTE+0x76> */
/* @0x2abfd4 ldr r1, [pc, #0xe0] */
/* @0x2abfd6 add r1, pc */
/* @0x2abfd8 b 0x2abfb0 <png_handle_PLTE+0x4c> */
/* @0x2abfda ldr r1, [pc, #0xe0] */
/* @0x2abfdc add r1, pc */
/* @0x2abfde bl 0x2a642c <png_error> */
/* @0x2abfe0 strtmi pc, [r8], -r5, lsr #20 */
/* @0x2abfe2 mov r0, r5 */
/* @0x2abfe4 movs r1, #0x3 */
/* @0x2abfe6 blx 0x318d10 <__divsi3> */
/* @0x2abfe8 .word 0xf894ee94 */
/* @0x2abfea ldrb.w r3, [r4, #0x1ea] */
/* @0x2abfec .word 0xf10d31ea */
/* @0x2abfee add.w r11, sp, #0x8 */
/* @0x2abff0 .word 0xf10d0b08 */
/* @0x2abff2 add.w r9, sp, #0x4 */
/* @0x2abff4 blhs 0x36e40c <_ZTS13C_UTF16String+0x54b8> */
/* @0x2abff6 cmp r3, #0x3 */
/* @0x2abff8 add.w r7, r11, #0x3 */
/* @0x2abffc mov.w r10, #0x0 */
/* @0x2ac000 ittet eq */
/* @0x2ac002 ldrbeq.w r3, [r4, #0x1eb] */
/* @0x2ac004 .word 0xf04f31eb */
/* @0x2ac006 moveq.w r8, #0x1 */
/* @0x2ac008 vst2.8 {d16, d17}, [pc], r1 */
/* @0x2ac00a movne.w r8, #0x100 */
/* @0x2ac00c blx 0x4ca214 <SrcVerts+0x27258> */
/* @0x2ac00e lsleq.w r8, r8, r3 */
/* @0x2ac010 strmi pc, [r0, #0x803] */
/* @0x2ac012 cmp r8, r0 */
/* @0x2ac014 it ge */
/* @0x2ac016 movge r8, r0 */
/* @0x2ac018 cmp r10, r8 */
/* @0x2ac01a add.w r7, r7, #0x3 */
/* @0x2ac01c strtmi r0, [r0], -r3, lsl #14 */
/* @0x2ac01e mov r0, r4 */
/* @0x2ac020 bge 0x2ac048 <png_handle_PLTE+0xe4> */
/* @0x2ac022 mov r1, r9 */
/* @0x2ac024 movs r2, #0x3 */
/* @0x2ac026 bl 0x2abc0c <png_crc_read> */
/* @0x2ac028 .word 0xf899fdf1 */
/* @0x2ac02a ldrb.w r3, [r9] */
/* @0x2ac02c .word 0xf10a3000 */
/* @0x2ac02e add.w r10, r10, #0x1 */
/* @0x2ac030 .word 0xf8070a01 */
/* @0x2ac032 strb r3, [r7, #-6] */
/* @0x2ac034 .word 0xf8993c06 */
/* @0x2ac036 ldrb.w r3, [r9, #0x1] */
/* @0x2ac038 .word 0xf8073001 */
/* @0x2ac03a strb r3, [r7, #-5] */
/* @0x2ac03c .word 0xf8993c05 */
/* @0x2ac03e ldrb.w r3, [r9, #0x2] */
/* @0x2ac040 .word 0xf8073002 */
/* @0x2ac042 strb r3, [r7, #-4] */
/* @0x2ac044 strb r3, [r7, r4, lsl #24]! */
/* @0x2ac046 b 0x2ac018 <png_handle_PLTE+0xb4> */
/* @0x2ac048 mvn r1, #0x2 */
/* @0x2ac04c mla r1, r1, r8, r5 */
/* @0x2ac050 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac054 mov r3, r8 */
/* @0x2ac056 mov r0, r4 */
/* @0x2ac058 mov r1, r6 */
/* @0x2ac05a mov r2, r11 */
/* @0x2ac05c bl 0x2aec84 <png_set_PLTE> */
/* @0x2ac060 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ac064 cmp r3, #0x3 */
/* @0x2ac066 bne 0x2ac09e <png_handle_PLTE+0x13a> */
/* @0x2ac068 cbz r6, 0x2ac09e <png_handle_PLTE+0x13a> */
/* @0x2ac06a ldr r3, [r6, #0x8] */
/* @0x2ac06c lsls r3, r3, #0x1b */
/* @0x2ac06e bpl 0x2ac09e <png_handle_PLTE+0x13a> */
/* @0x2ac070 ldrh.w r3, [r4, #0x1de] */
/* @0x2ac074 uxth.w r8, r8 */
/* @0x2ac078 cmp r3, r8 */
/* @0x2ac07a bls 0x2ac08a <png_handle_PLTE+0x126> */
/* @0x2ac07c ldr r1, [pc, #0x40] */
/* @0x2ac07e mov r0, r4 */
/* @0x2ac080 add r1, pc */
/* @0x2ac082 bl 0x2a6474 <png_warning> */
/* @0x2ac084 .word 0xf8a4f9f7 */
/* @0x2ac086 strh.w r8, [r4, #0x1de] */
/* @0x2ac088 bhi 0xfff8c808 <b2_toiTime+0xffffffffff833364> */
/* @0x2ac08a ldrh r3, [r6, #0x16] */
/* @0x2ac08c cmp r3, r8 */
/* @0x2ac08e bls 0x2ac09e <png_handle_PLTE+0x13a> */
/* @0x2ac090 ldr r1, [pc, #0x30] */
/* @0x2ac092 mov r0, r4 */
/* @0x2ac094 add r1, pc */
/* @0x2ac096 bl 0x2a6474 <png_warning> */
/* @0x2ac098 .word 0xf8a6f9ed */
/* @0x2ac09a strh.w r8, [r6, #0x16] */
/* @0x2ac09c .word 0xf50d8016 */
/* @0x2ac09e add.w sp, sp, #0x30c */
/* @0x2ac0a0 pop {r0, r1, r6, r8, r10, r11, r12, sp, lr} */
/* @0x2ac0a2 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ac0a4 svclt #0x8ff0 */
/* @0x2ac0a6 nop */
/* @0x2ac0a8 lsrs r7, r3, #0x14 */
/* @0x2ac0aa movs r6, r1 */
/* @0x2ac0ac lsrs r6, r5, #0x14 */
/* @0x2ac0ae movs r6, r1 */
/* @0x2ac0b0 lsrs r4, r7, #0x14 */
/* @0x2ac0b2 movs r6, r1 */
/* @0x2ac0b4 lsrs r3, r6, #0x14 */
/* @0x2ac0b6 movs r6, r1 */
/* @0x2ac0b8 lsrs r0, r6, #0x14 */
/* @0x2ac0ba movs r6, r1 */
/* @0x2ac0bc lsrs r2, r5, #0x14 */
/* @0x2ac0be movs r6, r1 */
/* @0x2ac0c0 lsrs r4, r3, #0x12 */
/* @0x2ac0c2 movs r6, r1 */
/* @0x2ac0c4 lsrs r7, r5, #0x12 */
/* @0x2ac0c6 movs r6, r1 */

/* ── FUNC 0x2ac0c8 · png_handle_IEND · size=72 · insn=35 */
/* @0x2ac0c8 push {r3, r4, r5, lr} */
/* @0x2ac0ca mov r4, r0 */
/* @0x2ac0cc ldr.w r3, [r0, #0x12c] */
/* @0x2ac0d0 mov r5, r2 */
/* @0x2ac0d2 and r3, r3, #0x5 */
/* @0x2ac0d4 blhs 0x3eccf0 <af_shaw_script_class> */
/* @0x2ac0d6 cmp r3, #0x5 */
/* @0x2ac0d8 beq 0x2ac0e2 <png_handle_IEND+0x1a> */
/* @0x2ac0da ldr r1, [pc, #0x2c] */
/* @0x2ac0dc add r1, pc */
/* @0x2ac0de bl 0x2a642c <png_error> */
/* @0x2ac0e0 .word 0xf8d4f9a5 */
/* @0x2ac0e2 ldr.w r3, [r4, #0x12c] */
/* @0x2ac0e4 .word 0xf043312c */
/* @0x2ac0e6 orr r3, r3, #0x18 */
/* @0x2ac0e8 .word 0xf8c40318 */
/* @0x2ac0ea str.w r3, [r4, #0x12c] */
/* @0x2ac0ec .word 0xb125312c */
/* @0x2ac0ee cbz r5, 0x2ac0fa <png_handle_IEND+0x32> */
/* @0x2ac0f0 ldr r1, [pc, #0x18] */
/* @0x2ac0f2 mov r0, r4 */
/* @0x2ac0f4 add r1, pc */
/* @0x2ac0f6 bl 0x2a6474 <png_warning> */
/* @0x2ac0f8 .word 0x4620f9bd */
/* @0x2ac0fa mov r0, r4 */
/* @0x2ac0fc mov r1, r5 */
/* @0x2ac0fe pop.w {r3, r4, r5, lr} */
/* @0x2ac100 .word 0xf7ff4038 */
/* @0x2ac102 b.w 0x2abc94 <png_crc_finish> */
/* @0x2ac104 svclt #0xbdc7 */
/* @0x2ac106 nop */
/* @0x2ac108 lsrs r3, r2, #0x12 */
/* @0x2ac10a movs r6, r1 */
/* @0x2ac10c lsrs r4, r1, #0x12 */
/* @0x2ac10e movs r6, r1 */

/* ── FUNC 0x2ac110 · png_handle_gAMA · size=296 · insn=126 */
/* @0x2ac110 push {r0, r1, r4, r5, r6, lr} */
/* @0x2ac112 mov r6, r2 */
/* @0x2ac114 ldr.w r3, [r0, #0x12c] */
/* @0x2ac118 mov r4, r0 */
/* @0x2ac11a mov r5, r1 */
/* @0x2ac11c lsls r2, r3, #0x1f */
/* @0x2ac11e bmi 0x2ac12a <png_handle_gAMA+0x1a> */
/* @0x2ac120 ldr r1, [pc, #0xf0] */
/* @0x2ac122 add r1, pc */
/* @0x2ac124 bl 0x2a642c <png_error> */
/* @0x2ac128 b 0x2ac140 <png_handle_gAMA+0x30> */
/* @0x2ac12a lsls r1, r3, #0x1d */
/* @0x2ac12c bpl 0x2ac134 <png_handle_gAMA+0x24> */
/* @0x2ac12e ldr r1, [pc, #0xe8] */
/* @0x2ac130 add r1, pc */
/* @0x2ac132 b 0x2ac154 <png_handle_gAMA+0x44> */
/* @0x2ac134 lsls r2, r3, #0x1e */
/* @0x2ac136 bpl 0x2ac140 <png_handle_gAMA+0x30> */
/* @0x2ac138 ldr r1, [pc, #0xe0] */
/* @0x2ac13a add r1, pc */
/* @0x2ac13c bl 0x2a6474 <png_warning> */
/* @0x2ac140 mov r0, r4 */
/* @0x2ac142 cbz r5, 0x2ac162 <png_handle_gAMA+0x52> */
/* @0x2ac144 ldr r2, [r5, #0x8] */
/* @0x2ac146 movw r3, #0x801 */
/* @0x2ac148 andsmi r0, r3, r1, lsl #6 */
/* @0x2ac14a ands r3, r2 */
/* @0x2ac14c cmp r3, #0x1 */
/* @0x2ac14e bne 0x2ac162 <png_handle_gAMA+0x52> */
/* @0x2ac150 ldr r1, [pc, #0xcc] */
/* @0x2ac152 add r1, pc */
/* @0x2ac154 bl 0x2a6474 <png_warning> */
/* @0x2ac158 mov r0, r4 */
/* @0x2ac15a mov r1, r6 */
/* @0x2ac15c bl 0x2abc94 <png_crc_finish> */
/* @0x2ac160 b 0x2ac20a <png_handle_gAMA+0xfa> */
/* @0x2ac162 cmp r6, #0x4 */
/* @0x2ac164 beq 0x2ac16c <png_handle_gAMA+0x5c> */
/* @0x2ac166 ldr r1, [pc, #0xbc] */
/* @0x2ac168 add r1, pc */
/* @0x2ac16a b 0x2ac154 <png_handle_gAMA+0x44> */
/* @0x2ac16c add r1, sp, #0x4 */
/* @0x2ac16e mov r2, r6 */
/* @0x2ac170 bl 0x2abc0c <png_crc_read> */
/* @0x2ac174 mov r0, r4 */
/* @0x2ac176 movs r1, #0x0 */
/* @0x2ac178 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac17c cmp r0, #0x0 */
/* @0x2ac17e bne 0x2ac20a <png_handle_gAMA+0xfa> */
/* @0x2ac180 ldrb.w r6, [sp, #0x5] */
/* @0x2ac184 ldrb.w r3, [sp, #0x4] */
/* @0x2ac188 lsls r6, r6, #0x10 */
/* @0x2ac18a add.w r6, r6, r3, lsl #24 */
/* @0x2ac18c .word 0xf89d6603 */
/* @0x2ac18e ldrb.w r3, [sp, #0x7] */
/* @0x2ac190 ldrmi r3, [lr], #-7 */
/* @0x2ac192 add r6, r3 */
/* @0x2ac194 ldrb.w r3, [sp, #0x6] */
/* @0x2ac198 adds.w r6, r6, r3, lsl #8 */
/* @0x2ac19c bne 0x2ac1aa <png_handle_gAMA+0x9a> */
/* @0x2ac19e ldr r1, [pc, #0x88] */
/* @0x2ac1a0 mov r0, r4 */
/* @0x2ac1a2 add r1, pc */
/* @0x2ac1a4 bl 0x2a6474 <png_warning> */
/* @0x2ac1a8 b 0x2ac20a <png_handle_gAMA+0xfa> */
/* @0x2ac1aa cbz r5, 0x2ac1dc <png_handle_gAMA+0xcc> */
/* @0x2ac1ac ldr r3, [r5, #0x8] */
/* @0x2ac1ae lsls r3, r3, #0x14 */
/* @0x2ac1b0 bpl 0x2ac1dc <png_handle_gAMA+0xcc> */
/* @0x2ac1b2 sub.w r3, r6, #0xaf00 */
/* @0x2ac1b4 bllo 0xff4bce78 <b2_toiTime+0xfffffffffed639d4> */
/* @0x2ac1b6 subs r3, #0xc8 */
/* @0x2ac1b8 cmp.w r3, #0x3e8 */
/* @0x2ac1bc bls 0x2ac1dc <png_handle_gAMA+0xcc> */
/* @0x2ac1be ldr r1, [pc, #0x6c] */
/* @0x2ac1c0 mov r0, r4 */
/* @0x2ac1c2 add r1, pc */
/* @0x2ac1c4 bl 0x2a6474 <png_warning> */
/* @0x2ac1c8 ldr r0, [pc, #0x64] */
/* @0x2ac1ca ldr r1, [pc, #0x68] */
/* @0x2ac1cc mov r2, r6 */
/* @0x2ac1ce add r0, pc */
/* @0x2ac1d0 ldr r0, [r0] */
/* @0x2ac1d2 add r1, pc */
/* @0x2ac1d4 adds r0, #0xa8 */
/* @0x2ac1d6 blx 0xb68a4 <fprintf@plt> */
/* @0x2ac1d8 ands lr, r6, r6, ror #22 */
/* @0x2ac1da b 0x2ac20a <png_handle_gAMA+0xfa> */
/* @0x2ac1dc vmov s12, r6 */
/* @0x2ac1e0 vldr s15, [pc, #44] */
/* @0x2ac1e4 mov r0, r4 */
/* @0x2ac1e6 mov r1, r5 */
/* @0x2ac1e8 vcvt.f32.s32 s14, s12 */
/* @0x2ac1ec vdiv.f32 s15, s14, s15 */
/* @0x2ac1f0 vcvt.f64.f32 d6, s15 */
/* @0x2ac1f4 vstr s15, [r4, #544] */
/* @0x2ac1f8 vmov r2, r3, d6 */
/* @0x2ac1fc bl 0x2ae8f8 <png_set_gAMA> */
/* @0x2ac200 mov r0, r4 */
/* @0x2ac202 mov r1, r5 */
/* @0x2ac204 mov r2, r6 */
/* @0x2ac206 bl 0x2ae988 <png_set_gAMA_fixed> */
/* @0x2ac208 strhlt pc, [r2], -pc */
/* @0x2ac20a add sp, #0x8 */
/* @0x2ac20c pop {r4, r5, r6, pc} */
/* @0x2ac20e nop */
/* @0x2ac210 str r0, [r0, r0] */
/* @0x2ac212 .word 0x47c3 */
/* @0x2ac214 lsrs r2, r7, #0x11 */
/* @0x2ac216 movs r6, r1 */
/* @0x2ac218 lsrs r5, r0, #0x12 */
/* @0x2ac21a movs r6, r1 */
/* @0x2ac21c lsrs r3, r2, #0x12 */
/* @0x2ac21e movs r6, r1 */
/* @0x2ac220 lsrs r3, r2, #0x12 */
/* @0x2ac222 movs r6, r1 */
/* @0x2ac224 lsrs r2, r2, #0x12 */
/* @0x2ac226 movs r6, r1 */
/* @0x2ac228 lsrs r4, r6, #0x11 */
/* @0x2ac22a movs r6, r1 */
/* @0x2ac22c lsrs r5, r6, #0x11 */
/* @0x2ac22e movs r6, r1 */
/* @0x2ac230 strh r2, [r7, r1] */
/* @0x2ac232 movs r4, r2 */
/* @0x2ac234 lsrs r5, r3, #0x12 */
/* @0x2ac236 movs r6, r1 */

/* ── FUNC 0x2ac238 · png_handle_sBIT · size=240 · insn=104 */
/* @0x2ac238 push {r0, r1, r4, r5, r6, lr} */
/* @0x2ac23a movs r3, #0x0 */
/* @0x2ac23c strb.w r3, [sp, #0x7] */
/* @0x2ac240 mov r5, r2 */
/* @0x2ac242 strb.w r3, [sp, #0x6] */
/* @0x2ac244 strmi r3, [r4], -r6 */
/* @0x2ac246 mov r4, r0 */
/* @0x2ac248 strb.w r3, [sp, #0x5] */
/* @0x2ac24c mov r6, r1 */
/* @0x2ac24e strb.w r3, [sp, #0x4] */
/* @0x2ac250 .word 0xf8d03004 */
/* @0x2ac252 ldr.w r3, [r0, #0x12c] */
/* @0x2ac254 ldrbeq r3, [r10, r12, lsr #2] */
/* @0x2ac256 lsls r2, r3, #0x1f */
/* @0x2ac258 bmi 0x2ac264 <png_handle_sBIT+0x2c> */
/* @0x2ac25a ldr r1, [pc, #0xb8] */
/* @0x2ac25c add r1, pc */
/* @0x2ac25e bl 0x2a642c <png_error> */
/* @0x2ac260 and pc, r10, r5, ror #17 */
/* @0x2ac262 b 0x2ac27a <png_handle_sBIT+0x42> */
/* @0x2ac264 lsls r1, r3, #0x1d */
/* @0x2ac266 bpl 0x2ac26e <png_handle_sBIT+0x36> */
/* @0x2ac268 ldr r1, [pc, #0xac] */
/* @0x2ac26a add r1, pc */
/* @0x2ac26c b 0x2ac288 <png_handle_sBIT+0x50> */
/* @0x2ac26e lsls r2, r3, #0x1e */
/* @0x2ac270 bpl 0x2ac27a <png_handle_sBIT+0x42> */
/* @0x2ac272 ldr r1, [pc, #0xa8] */
/* @0x2ac274 add r1, pc */
/* @0x2ac276 bl 0x2a6474 <png_warning> */
/* @0x2ac278 .word 0xb166f8fd */
/* @0x2ac27a cbz r6, 0x2ac296 <png_handle_sBIT+0x5e> */
/* @0x2ac27c ldr r3, [r6, #0x8] */
/* @0x2ac27e lsls r3, r3, #0x1e */
/* @0x2ac280 bpl 0x2ac296 <png_handle_sBIT+0x5e> */
/* @0x2ac282 ldr r1, [pc, #0x9c] */
/* @0x2ac284 mov r0, r4 */
/* @0x2ac286 add r1, pc */
/* @0x2ac288 bl 0x2a6474 <png_warning> */
/* @0x2ac28c mov r0, r4 */
/* @0x2ac28e mov r1, r5 */
/* @0x2ac290 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac294 b 0x2ac310 <png_handle_sBIT+0xd8> */
/* @0x2ac296 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ac298 strtmi r3, [r0], -r10, ror #3 */
/* @0x2ac29a mov r0, r4 */
/* @0x2ac29c cmp r3, #0x3 */
/* @0x2ac29e it ne */
/* @0x2ac2a0 ldrbne.w r3, [r4, #0x1ee] */
/* @0x2ac2a4 cmp r5, r3 */
/* @0x2ac2a6 bne 0x2ac2ac <png_handle_sBIT+0x74> */
/* @0x2ac2a8 cmp r5, #0x4 */
/* @0x2ac2aa bls 0x2ac2b2 <png_handle_sBIT+0x7a> */
/* @0x2ac2ac ldr r1, [pc, #0x74] */
/* @0x2ac2ae add r1, pc */
/* @0x2ac2b0 b 0x2ac288 <png_handle_sBIT+0x50> */
/* @0x2ac2b2 add r1, sp, #0x4 */
/* @0x2ac2b4 mov r2, r5 */
/* @0x2ac2b6 bl 0x2abc0c <png_crc_read> */
/* @0x2ac2b8 strtmi pc, [r0], -r9, lsr #25 */
/* @0x2ac2ba mov r0, r4 */
/* @0x2ac2bc movs r1, #0x0 */
/* @0x2ac2be bl 0x2abc94 <png_crc_finish> */
/* @0x2ac2c0 bllt 0xceb66c <b2_toiTime+0x5921c8> */
/* @0x2ac2c2 cbnz r0, 0x2ac310 <png_handle_sBIT+0xd8> */
/* @0x2ac2c4 ldrb.w r3, [r4, #0x1ea] */
/* @0x2ac2c8 ldrb.w r2, [sp, #0x5] */
/* @0x2ac2cc tst.w r3, #0x2 */
/* @0x2ac2d0 ldrb.w r3, [sp, #0x4] */
/* @0x2ac2d4 beq 0x2ac2f0 <png_handle_sBIT+0xb8> */
/* @0x2ac2d6 strb.w r3, [r4, #0x240] */
/* @0x2ac2d8 .word 0xf89d3240 */
/* @0x2ac2da ldrb.w r3, [sp, #0x6] */
/* @0x2ac2dc .word 0xf8843006 */
/* @0x2ac2de strb.w r2, [r4, #0x241] */
/* @0x2ac2e0 .word 0xf8842241 */
/* @0x2ac2e2 strb.w r3, [r4, #0x242] */
/* @0x2ac2e4 .word 0xf89d3242 */
/* @0x2ac2e6 ldrb.w r3, [sp, #0x7] */
/* @0x2ac2e8 .word 0xf8843007 */
/* @0x2ac2ea strb.w r3, [r4, #0x244] */
/* @0x2ac2ec and r3, r9, r4, asr #4 */
/* @0x2ac2ee b 0x2ac304 <png_handle_sBIT+0xcc> */
/* @0x2ac2f0 strb.w r3, [r4, #0x243] */
/* @0x2ac2f4 strb.w r3, [r4, #0x240] */
/* @0x2ac2f8 strb.w r3, [r4, #0x241] */
/* @0x2ac2fc strb.w r3, [r4, #0x242] */
/* @0x2ac300 strb.w r2, [r4, #0x244] */
/* @0x2ac304 mov r0, r4 */
/* @0x2ac306 mov r1, r6 */
/* @0x2ac308 add.w r2, r4, #0x240 */
/* @0x2ac30c bl 0x2aed1c <png_set_sBIT> */
/* @0x2ac310 add sp, #0x8 */
/* @0x2ac312 pop {r4, r5, r6, pc} */
/* @0x2ac314 lsrs r7, r4, #0x10 */
/* @0x2ac316 movs r6, r1 */
/* @0x2ac318 lsrs r2, r6, #0x10 */
/* @0x2ac31a movs r6, r1 */
/* @0x2ac31c lsrs r0, r0, #0x11 */
/* @0x2ac31e movs r6, r1 */
/* @0x2ac320 lsrs r6, r0, #0x11 */
/* @0x2ac322 movs r6, r1 */
/* @0x2ac324 lsrs r3, r6, #0x10 */
/* @0x2ac326 movs r6, r1 */

/* ── FUNC 0x2ac328 · png_handle_cHRM · size=876 · insn=373 */
/* @0x2ac328 ldr r3, [pc, #0x340] */
/* @0x2ac32a push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ac32c stc p15, c4, [sp, #-960]! */
/* @0x2ac32e vpush {d8, d9, d10, d11} */
/* @0x2ac330 ldrbtmi r8, [r11], #-2824 */
/* @0x2ac332 add r3, pc */
/* @0x2ac334 ldr r3, [r3] */
/* @0x2ac336 mov r6, r2 */
/* @0x2ac338 sub sp, #0x74 */
/* @0x2ac33a ldr r2, [r3] */
/* @0x2ac33c mov r4, r0 */
/* @0x2ac33e mov r5, r1 */
/* @0x2ac340 str r3, [sp, #0x44] */
/* @0x2ac342 str r2, [sp, #0x6c] */
/* @0x2ac344 ldr.w r2, [r0, #0x12c] */
/* @0x2ac348 tst.w r2, #0x1 */
/* @0x2ac34c bne 0x2ac358 <png_handle_cHRM+0x30> */
/* @0x2ac34e ldr r1, [pc, #0x320] */
/* @0x2ac350 add r1, pc */
/* @0x2ac352 bl 0x2a642c <png_error> */
/* @0x2ac354 and pc, r10, r11, ror #16 */
/* @0x2ac356 b 0x2ac36e <png_handle_cHRM+0x46> */
/* @0x2ac358 lsls r1, r2, #0x1d */
/* @0x2ac35a bpl 0x2ac362 <png_handle_cHRM+0x3a> */
/* @0x2ac35c ldr r1, [pc, #0x314] */
/* @0x2ac35e add r1, pc */
/* @0x2ac360 b 0x2ac38c <png_handle_cHRM+0x64> */
/* @0x2ac362 lsls r2, r2, #0x1e */
/* @0x2ac364 bpl 0x2ac36e <png_handle_cHRM+0x46> */
/* @0x2ac366 ldr r1, [pc, #0x310] */
/* @0x2ac368 add r1, pc */
/* @0x2ac36a bl 0x2a6474 <png_warning> */
/* @0x2ac36c strtmi pc, [r0], -r3, lsl #17 */
/* @0x2ac36e mov r0, r4 */
/* @0x2ac370 cbz r5, 0x2ac384 <png_handle_cHRM+0x5c> */
/* @0x2ac372 ldr r2, [r5, #0x8] */
/* @0x2ac374 movw r3, #0x804 */
/* @0x2ac378 ands r3, r2 */
/* @0x2ac37a cmp r3, #0x4 */
/* @0x2ac37c bne 0x2ac384 <png_handle_cHRM+0x5c> */
/* @0x2ac37e ldr r1, [pc, #0x2fc] */
/* @0x2ac380 add r1, pc */
/* @0x2ac382 b 0x2ac38c <png_handle_cHRM+0x64> */
/* @0x2ac384 cmp r6, #0x20 */
/* @0x2ac386 beq 0x2ac39a <png_handle_cHRM+0x72> */
/* @0x2ac388 ldr r1, [pc, #0x2f4] */
/* @0x2ac38a add r1, pc */
/* @0x2ac38c bl 0x2a6474 <png_warning> */
/* @0x2ac390 mov r0, r4 */
/* @0x2ac392 mov r1, r6 */
/* @0x2ac394 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac398 b 0x2ac64e <png_handle_cHRM+0x326> */
/* @0x2ac39a add r1, sp, #0x4c */
/* @0x2ac39c mov r2, r6 */
/* @0x2ac39e bl 0x2abc0c <png_crc_read> */
/* @0x2ac3a0 qasxmi pc, r0, r5 */
/* @0x2ac3a2 mov r0, r4 */
/* @0x2ac3a4 movs r1, #0x0 */
/* @0x2ac3a6 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac3a8 stmdahs r0, {r0, r2, r4, r5, r6, r10, r11, r12, sp, lr, pc} */
/* @0x2ac3aa cmp r0, #0x0 */
/* @0x2ac3ac bne.w 0x2ac64e <png_handle_cHRM+0x326> */
/* @0x2ac3b0 ldrb.w r7, [sp, #0x4d] */
/* @0x2ac3b4 vldr s15, [pc, #688] */
/* @0x2ac3b8 ldrb.w r3, [sp, #0x4c] */
/* @0x2ac3bc ldrb.w r6, [sp, #0x51] */
/* @0x2ac3c0 lsls r7, r7, #0x10 */
/* @0x2ac3c2 ldrb.w r12, [sp, #0x55] */
/* @0x2ac3c4 bl 0x49c520 <TimingData+0x2508> */
/* @0x2ac3c6 add.w r7, r7, r3, lsl #24 */
/* @0x2ac3c8 .word 0xf89d6703 */
/* @0x2ac3ca ldrb.w r3, [sp, #0x4f] */
/* @0x2ac3cc ldrteq r3, [r6], #-79 */
/* @0x2ac3ce lsls r6, r6, #0x10 */
/* @0x2ac3d0 ldrb.w r11, [sp, #0x59] */
/* @0x2ac3d4 add r7, r3 */
/* @0x2ac3d6 ldrb.w r3, [sp, #0x4e] */
/* @0x2ac3d8 b 0x1678518 <b2_toiTime+0xf1f074> */
/* @0x2ac3da lsl.w r12, r12, #0x10 */
/* @0x2ac3dc .word 0xf89d4c0c */
/* @0x2ac3de ldrb.w r10, [sp, #0x5d] */
/* @0x2ac3e0 b 0x169455c <b2_toiTime+0xf3b0b8> */
/* @0x2ac3e2 lsl.w r11, r11, #0x10 */
/* @0x2ac3e4 .word 0xf89d4b0b */
/* @0x2ac3e6 ldrb.w r9, [sp, #0x61] */
/* @0x2ac3e8 bl 0x490574 <g_prim_v+0x568> */
/* @0x2ac3ea add.w r7, r7, r3, lsl #8 */
/* @0x2ac3ec .word 0xf89d2703 */
/* @0x2ac3ee ldrb.w r3, [sp, #0x50] */
/* @0x2ac3f0 b 0x1678538 <b2_toiTime+0xf1f094> */
/* @0x2ac3f2 lsl.w r10, r10, #0x10 */
/* @0x2ac3f4 .word 0xf89d4a0a */
/* @0x2ac3f6 ldrb.w r8, [sp, #0x65] */
/* @0x2ac3f8 b 0x168c594 <b2_toiTime+0xf330f0> */
/* @0x2ac3fa lsl.w r9, r9, #0x10 */
/* @0x2ac3fc cdp p9, #0x0, c4, c7, c9, #0x0 */
/* @0x2ac3fe vmov s14, r7 */
/* @0x2ac400 bl 0x44ac48 <g_RomDisk+0x53428> */
/* @0x2ac402 add.w r6, r6, r3, lsl #24 */
/* @0x2ac404 .word 0xf89d6603 */
/* @0x2ac406 ldrb.w r3, [sp, #0x53] */
/* @0x2ac408 b 0x167855c <b2_toiTime+0xf1f0b8> */
/* @0x2ac40a lsl.w r8, r8, #0x10 */
/* @0x2ac40c cdp p8, #0xf, c4, c8, c8, #0x0 */
/* @0x2ac40e vcvt.f32.s32 s17, s14 */
/* @0x2ac410 ldrmi r8, [lr], #-2759 */
/* @0x2ac412 add r6, r3 */
/* @0x2ac414 ldrb.w r3, [sp, #0x52] */
/* @0x2ac418 ldrb.w r2, [sp, #0x68] */
/* @0x2ac41c add.w r6, r6, r3, lsl #8 */
/* @0x2ac420 ldrb.w r3, [sp, #0x54] */
/* @0x2ac424 vmov s14, r6 */
/* @0x2ac428 add.w r12, r12, r3, lsl #24 */
/* @0x2ac42c ldrb.w r3, [sp, #0x57] */
/* @0x2ac430 vcvt.f32.s32 s23, s14 */
/* @0x2ac434 add r12, r3 */
/* @0x2ac436 ldrb.w r3, [sp, #0x56] */
/* @0x2ac438 bl 0x5b8598 <g_SWFlineaavertbuff+0x654d0> */
/* @0x2ac43a add.w r12, r12, r3, lsl #8 */
/* @0x2ac43c .word 0xf89d2c03 */
/* @0x2ac43e ldrb.w r3, [sp, #0x58] */
/* @0x2ac440 mcr p0, #0x0, r3, c7, c8, #0x2 */
/* @0x2ac442 vmov s14, r12 */
/* @0x2ac444 bl 0x59ec8c <g_SWFlineaavertbuff+0x4bbc4> */
/* @0x2ac446 add.w r11, r11, r3, lsl #24 */
/* @0x2ac448 .word 0xf89d6b03 */
/* @0x2ac44a ldrb.w r3, [sp, #0x5b] */
/* @0x2ac44c mrc p0, #0x5, r3, c8, c11, #0x2 */
/* @0x2ac44e vcvt.f32.s32 s22, s14 */
/* @0x2ac450 ldrmi r11, [r11], #2759 */
/* @0x2ac452 add r11, r3 */
/* @0x2ac454 ldrb.w r3, [sp, #0x5a] */
/* @0x2ac458 add.w r11, r11, r3, lsl #8 */
/* @0x2ac45c ldrb.w r3, [sp, #0x5c] */
/* @0x2ac460 vmov s14, r11 */
/* @0x2ac464 add.w r10, r10, r3, lsl #24 */
/* @0x2ac468 ldrb.w r3, [sp, #0x5f] */
/* @0x2ac46c vcvt.f32.s32 s21, s14 */
/* @0x2ac470 add r10, r3 */
/* @0x2ac472 ldrb.w r3, [sp, #0x5e] */
/* @0x2ac474 bl 0x5385f4 <obj_numb_event+0x1684> */
/* @0x2ac476 add.w r10, r10, r3, lsl #8 */
/* @0x2ac478 .word 0xf89d2a03 */
/* @0x2ac47a ldrb.w r3, [sp, #0x60] */
/* @0x2ac47c cdp p0, #0x0, c3, c7, c0, #0x3 */
/* @0x2ac47e vmov s14, r10 */
/* @0x2ac480 bl 0x516cc8 <SrcVerts+0x73d0c> */
/* @0x2ac482 add.w r9, r9, r3, lsl #24 */
/* @0x2ac484 .word 0xf89d6903 */
/* @0x2ac486 ldrb.w r3, [sp, #0x63] */
/* @0x2ac488 cdp p0, #0xf, c3, c8, c3, #0x3 */
/* @0x2ac48a vcvt.f32.s32 s19, s14 */
/* @0x2ac48c ldrmi r9, [r9], #2759 */
/* @0x2ac48e add r9, r3 */
/* @0x2ac490 ldrb.w r3, [sp, #0x62] */
/* @0x2ac494 add.w r9, r9, r3, lsl #8 */
/* @0x2ac498 ldrb.w r3, [sp, #0x64] */
/* @0x2ac49c vmov s14, r9 */
/* @0x2ac4a0 add.w r8, r8, r3, lsl #24 */
/* @0x2ac4a4 ldrb.w r3, [sp, #0x67] */
/* @0x2ac4a8 vcvt.f32.s32 s20, s14 */
/* @0x2ac4ac add r8, r3 */
/* @0x2ac4ae ldrb.w r3, [sp, #0x66] */
/* @0x2ac4b0 bl 0x4b8650 <SrcVerts+0x15694> */
/* @0x2ac4b2 add.w r8, r8, r3, lsl #8 */
/* @0x2ac4b4 .word 0xf89d2803 */
/* @0x2ac4b6 ldrb.w r3, [sp, #0x69] */
/* @0x2ac4b8 cdp p0, #0x0, c3, c7, c9, #0x3 */
/* @0x2ac4ba vmov s14, r8 */
/* @0x2ac4bc ldreq r8, [r11], #-2576 */
/* @0x2ac4be lsls r3, r3, #0x10 */
/* @0x2ac4c0 vdiv.f32 s17, s17, s15 */
/* @0x2ac4c4 add.w r3, r3, r2, lsl #24 */
/* @0x2ac4c8 ldrb.w r2, [sp, #0x6b] */
/* @0x2ac4cc add r3, r2 */
/* @0x2ac4ce ldrb.w r2, [sp, #0x6a] */
/* @0x2ac4d0 bl 0x374680 <_ZTS13C_UTF16String+0xb72c> */
/* @0x2ac4d2 add.w r2, r3, r2, lsl #8 */
/* @0x2ac4d4 andsls r2, r0, #536870912 */
/* @0x2ac4d6 str r2, [sp, #0x40] */
/* @0x2ac4d8 vcvt.f32.s32 s18, s14 */
/* @0x2ac4dc vmov s14, r2 */
/* @0x2ac4e0 vcvt.f32.s32 s16, s14 */
/* @0x2ac4e4 vdiv.f32 s23, s23, s15 */
/* @0x2ac4e8 vdiv.f32 s22, s22, s15 */
/* @0x2ac4ec vdiv.f32 s21, s21, s15 */
/* @0x2ac4f0 vdiv.f32 s19, s19, s15 */
/* @0x2ac4f4 vdiv.f32 s20, s20, s15 */
/* @0x2ac4f8 vdiv.f32 s18, s18, s15 */
/* @0x2ac4fc vdiv.f32 s16, s16, s15 */
/* @0x2ac500 cmp r5, #0x0 */
/* @0x2ac502 beq 0x2ac5da <png_handle_cHRM+0x2b2> */
/* @0x2ac504 ldr r3, [r5, #0x8] */
/* @0x2ac506 lsls r3, r3, #0x14 */
/* @0x2ac508 bpl 0x2ac5da <png_handle_cHRM+0x2b2> */
/* @0x2ac50a sub.w r7, r7, #0x7600 */
/* @0x2ac50c svclo #0x3e47ec */
/* @0x2ac50e subs r7, #0x3e */
/* @0x2ac510 cmp.w r7, #0x7d0 */
/* @0x2ac514 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac516 sub.w r6, r6, #0x7c80 */
/* @0x2ac518 mrclo p6, #0x0, r4, c12, c9, #0x7 */
/* @0x2ac51a subs r6, #0x1c */
/* @0x2ac51c cmp.w r6, #0x7d0 */
/* @0x2ac520 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac522 sub.w r12, r12, #0xf600 */
/* @0x2ac524 .word 0xf1ac4c76 */
/* @0x2ac526 sub.w r12, r12, #0x18 */
/* @0x2ac528 .word 0xf5bc0c18 */
/* @0x2ac52a cmp.w r12, #0x7d0 */
/* @0x2ac52c ldmdale pc, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac52e bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac530 sub.w r11, r11, #0x7d00 */
/* @0x2ac534 cmp.w r11, #0x7d0 */
/* @0x2ac538 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac53a sub.w r10, r10, #0x7100 */
/* @0x2ac53c .word 0xf1aa4ae2 */
/* @0x2ac53e sub.w r10, r10, #0x48 */
/* @0x2ac540 .word 0xf5ba0a48 */
/* @0x2ac542 cmp.w r10, #0x7d0 */
/* @0x2ac544 ldmdale r3, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac546 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac548 sub.w r9, r9, #0xe600 */
/* @0x2ac54c sub.w r9, r9, #0x78 */
/* @0x2ac550 cmp.w r9, #0x7d0 */
/* @0x2ac554 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac556 sub.w r8, r8, #0x3680 */
/* @0x2ac558 .word 0xf1a8585a */
/* @0x2ac55a sub.w r8, r8, #0x30 */
/* @0x2ac55c .word 0xf5b80830 */
/* @0x2ac55e cmp.w r8, #0x7d0 */
/* @0x2ac560 stmdale r5, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac562 bhi 0x2ac570 <png_handle_cHRM+0x248> */
/* @0x2ac564 sub.w r3, r2, #0x1380 */
/* @0x2ac568 subs r3, #0x8 */
/* @0x2ac56a cmp.w r3, #0x7d0 */
/* @0x2ac56c stmdble lr!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} ^ */
/* @0x2ac56e bls 0x2ac64e <png_handle_cHRM+0x326> */
/* @0x2ac570 ldr r1, [pc, #0x110] */
/* @0x2ac572 mov r0, r4 */
/* @0x2ac574 add r1, pc */
/* @0x2ac576 bl 0x2a6474 <png_warning> */
/* @0x2ac578 mrc p15, #0x5, apsr_nzcv, c7, c13, #0x3 */
/* @0x2ac57a vcvt.f64.f32 d7, s17 */
/* @0x2ac57c stmdami r2, {r3, r5, r6, r7, r9, r11, r12, sp, lr} ^ */
/* @0x2ac57e ldr r0, [pc, #0x108] */
/* @0x2ac580 ldr r1, [pc, #0x108] */
/* @0x2ac582 add r0, pc */
/* @0x2ac584 ldr r0, [r0] */
/* @0x2ac586 add.w r4, r0, #0xa8 */
/* @0x2ac588 ldrbtmi r0, [r9], #-1192 */
/* @0x2ac58a add r1, pc */
/* @0x2ac58c mov r0, r4 */
/* @0x2ac58e vcvt.f64.f32 d1, s23 */
/* @0x2ac590 .word 0xec531aeb */
/* @0x2ac592 vmov r2, r3, d7 */
/* @0x2ac594 .word 0xeeb72b17 */
/* @0x2ac596 vcvt.f64.f32 d2, s22 */
/* @0x2ac598 vstr s4, [sp, #812] */
/* @0x2ac59a vstr d1, [sp] */
/* @0x2ac59c vmov.f64 d1, #1.000000e+00 */
/* @0x2ac59e vcvt.f64.f32 d3, s21 */
/* @0x2ac5a0 vstr s6, [sp, #936] */
/* @0x2ac5a2 vstr d2, [sp, #8] */
/* @0x2ac5a4 vstr d2, [sp, #8] */
/* @0x2ac5a6 vstr d3, [sp, #16] */
/* @0x2ac5a8 .word 0xf60a3b04 */
/* @0x2ac5aa blx 0xb68a4 <fprintf@plt> */
/* @0x2ac5ac mrc p9, #0x5, lr, c7, c12, #0x3 */
/* @0x2ac5ae vcvt.f64.f32 d7, s16 */
/* @0x2ac5b0 ldmdbmi r7!, {r3, r6, r7, r9, r11, r12, sp, lr} */
/* @0x2ac5b2 ldr r1, [pc, #0xdc] */
/* @0x2ac5b4 mov r0, r4 */
/* @0x2ac5b6 add r1, pc */
/* @0x2ac5b8 vcvt.f64.f32 d5, s20 */
/* @0x2ac5bc vstr d7, [sp, #16] */
/* @0x2ac5c0 vcvt.f64.f32 d6, s18 */
/* @0x2ac5c4 vstr d5, [sp] */
/* @0x2ac5c8 vcvt.f64.f32 d7, s19 */
/* @0x2ac5cc vstr d6, [sp, #8] */
/* @0x2ac5d0 vmov r2, r3, d7 */
/* @0x2ac5d4 blx 0xb68a4 <fprintf@plt> */
/* @0x2ac5d8 b 0x2ac64e <png_handle_cHRM+0x326> */
/* @0x2ac5da vcvt.f64.f32 d7, s16 */
/* @0x2ac5dc strtmi r7, [r0], -r8, asr #21 */
/* @0x2ac5de mov r0, r4 */
/* @0x2ac5e0 mov r1, r5 */
/* @0x2ac5e2 str.w r12, [sp, #0x3c] */
/* @0x2ac5e4 mrc p0, #0x5, r12, c7, c12, #0x1 */
/* @0x2ac5e6 vcvt.f64.f32 d1, s23 */
/* @0x2ac5e8 vstr s2, [sp, #940] */
/* @0x2ac5ea vstr d7, [sp, #48] */
/* @0x2ac5ec vmov.f64 d7, #1.750000e+00 */
/* @0x2ac5ee vcvt.f64.f32 d2, s22 */
/* @0x2ac5f0 vstr s4, [sp, #812] */
/* @0x2ac5f2 vstr d1, [sp] */
/* @0x2ac5f4 vmov.f64 d1, #1.000000e+00 */
/* @0x2ac5f6 vcvt.f64.f32 d3, s21 */
/* @0x2ac5f8 vstr s6, [sp, #936] */
/* @0x2ac5fa vstr d2, [sp, #8] */
/* @0x2ac5fc vmov.f64 d2, #1.125000e+00 */
/* @0x2ac5fe vcvt.f64.f32 d4, s19 */
/* @0x2ac600 vstr s8, [sp, #932] */
/* @0x2ac602 vstr d3, [sp, #16] */
/* @0x2ac604 vmov.f64 d3, #1.250000e+00 */
/* @0x2ac606 vcvt.f64.f32 d5, s20 */
/* @0x2ac608 vstr s10, [sp, #808] */
/* @0x2ac60a vstr d4, [sp, #24] */
/* @0x2ac60c vmov.f64 d4, #1.375000e+00 */
/* @0x2ac60e vcvt.f64.f32 d6, s18 */
/* @0x2ac610 vstr s12, [sp, #804] */
/* @0x2ac612 vstr d5, [sp, #32] */
/* @0x2ac614 vmov.f64 d5, #1.500000e+00 */
/* @0x2ac616 vcvt.f64.f32 d7, s17 */
/* @0x2ac618 vstr s14, [sp, #928] */
/* @0x2ac61a vstr d6, [sp, #40] */
/* @0x2ac61c .word 0xec536b0a */
/* @0x2ac61e vmov r2, r3, d7 */
/* @0x2ac620 .word 0xf0022b17 */
/* @0x2ac622 bl 0x2ae6d8 <png_set_cHRM> */
/* @0x2ac624 ldmdbls r0, {r0, r3, r4, r6, r11, r12, sp, lr, pc} */
/* @0x2ac626 ldr r1, [sp, #0x40] */
/* @0x2ac628 ldr.w r12, [sp, #0x3c] */
/* @0x2ac62c mov r0, r4 */
/* @0x2ac62e str.w r11, [sp, #0x4] */
/* @0x2ac630 ldrtmi r11, [r10], -r4 */
/* @0x2ac632 mov r2, r7 */
/* @0x2ac634 str r1, [sp, #0x14] */
/* @0x2ac636 mov r3, r6 */
/* @0x2ac638 str.w r12, [sp] */
/* @0x2ac63c mov r1, r5 */
/* @0x2ac63e str.w r10, [sp, #0x8] */
/* @0x2ac640 .word 0xf8cda008 */
/* @0x2ac642 str.w r9, [sp, #0xc] */
/* @0x2ac644 .word 0xf8cd900c */
/* @0x2ac646 str.w r8, [sp, #0x10] */
/* @0x2ac648 .word 0xf0028010 */
/* @0x2ac64a bl 0x2ae7e0 <png_set_cHRM_fixed> */
/* @0x2ac64c ldmdbls r1, {r0, r3, r6, r7, r11, r12, sp, lr, pc} */
/* @0x2ac64e ldr r1, [sp, #0x44] */
/* @0x2ac650 ldr r2, [sp, #0x6c] */
/* @0x2ac652 ldr r3, [r1] */
/* @0x2ac654 cmp r2, r3 */
/* @0x2ac656 beq 0x2ac65c <png_handle_cHRM+0x334> */
/* @0x2ac658 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2ac65c add sp, #0x74 */
/* @0x2ac65e vpop {d8, d9, d10, d11} */
/* @0x2ac660 pop {r3, r8, r9, r11, pc} */
/* @0x2ac662 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ac664 svclt #0x8ff0 */
/* @0x2ac666 nop */
/* @0x2ac668 str r0, [r0, r0] */
/* @0x2ac66a .word 0x47c3 */
/* @0x2ac66c asrs r2, r4, #0x18 */
/* @0x2ac66e movs r4, r2 */
/* @0x2ac670 lsrs r5, r5, #0xe */
/* @0x2ac672 movs r6, r1 */
/* @0x2ac674 lsrs r0, r7, #0xe */
/* @0x2ac676 movs r6, r1 */
/* @0x2ac678 lsrs r6, r0, #0xf */
/* @0x2ac67a movs r6, r1 */
/* @0x2ac67c lsrs r7, r0, #0xf */
/* @0x2ac67e movs r6, r1 */
/* @0x2ac680 lsrs r2, r2, #0xf */
/* @0x2ac682 movs r6, r1 */
/* @0x2ac684 lsrs r4, r0, #0x8 */
/* @0x2ac686 movs r6, r1 */
/* @0x2ac688 ldr r6, [pc, #0x318] */
/* @0x2ac68a movs r4, r2 */
/* @0x2ac68c lsrs r6, r4, #0x8 */
/* @0x2ac68e movs r6, r1 */
/* @0x2ac690 lsrs r6, r2, #0x8 */
/* @0x2ac692 movs r6, r1 */

/* ── FUNC 0x2ac694 · png_handle_sRGB · size=384 · insn=169 */
/* @0x2ac694 push {r0, r1, r4, r5, r6, lr} */
/* @0x2ac696 mov r4, r1 */
/* @0x2ac698 ldr.w r3, [r0, #0x12c] */
/* @0x2ac69c mov r5, r0 */
/* @0x2ac69e mov r6, r2 */
/* @0x2ac6a0 lsls r1, r3, #0x1f */
/* @0x2ac6a2 bmi 0x2ac6ae <png_handle_sRGB+0x1a> */
/* @0x2ac6a4 ldr r1, [pc, #0x144] */
/* @0x2ac6a6 add r1, pc */
/* @0x2ac6a8 bl 0x2a642c <png_error> */
/* @0x2ac6ac b 0x2ac6c4 <png_handle_sRGB+0x30> */
/* @0x2ac6ae lsls r2, r3, #0x1d */
/* @0x2ac6b0 bpl 0x2ac6b8 <png_handle_sRGB+0x24> */
/* @0x2ac6b2 ldr r1, [pc, #0x13c] */
/* @0x2ac6b4 add r1, pc */
/* @0x2ac6b6 b 0x2ac6dc <png_handle_sRGB+0x48> */
/* @0x2ac6b8 lsls r3, r3, #0x1e */
/* @0x2ac6ba bpl 0x2ac6c4 <png_handle_sRGB+0x30> */
/* @0x2ac6bc ldr r1, [pc, #0x134] */
/* @0x2ac6be add r1, pc */
/* @0x2ac6c0 bl 0x2a6474 <png_warning> */
/* @0x2ac6c4 mov r0, r5 */
/* @0x2ac6c6 cbz r4, 0x2ac6d4 <png_handle_sRGB+0x40> */
/* @0x2ac6c8 ldr r3, [r4, #0x8] */
/* @0x2ac6ca lsls r1, r3, #0x14 */
/* @0x2ac6cc bpl 0x2ac6d4 <png_handle_sRGB+0x40> */
/* @0x2ac6ce ldr r1, [pc, #0x128] */
/* @0x2ac6d0 add r1, pc */
/* @0x2ac6d2 b 0x2ac6dc <png_handle_sRGB+0x48> */
/* @0x2ac6d4 cmp r6, #0x1 */
/* @0x2ac6d6 beq 0x2ac6ea <png_handle_sRGB+0x56> */
/* @0x2ac6d8 ldr r1, [pc, #0x120] */
/* @0x2ac6da add r1, pc */
/* @0x2ac6dc bl 0x2a6474 <png_warning> */
/* @0x2ac6e0 mov r0, r5 */
/* @0x2ac6e2 mov r1, r6 */
/* @0x2ac6e4 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac6e8 b 0x2ac7e6 <png_handle_sRGB+0x152> */
/* @0x2ac6ea add r1, sp, #0x4 */
/* @0x2ac6ec mov r2, r6 */
/* @0x2ac6ee bl 0x2abc0c <png_crc_read> */
/* @0x2ac6f0 strtmi pc, [r8], -sp, lsl #21 */
/* @0x2ac6f2 mov r0, r5 */
/* @0x2ac6f4 movs r1, #0x0 */
/* @0x2ac6f6 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac6f8 stmdahs r0, {r0, r2, r3, r6, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2ac6fa cmp r0, #0x0 */
/* @0x2ac6fc bne 0x2ac7e6 <png_handle_sRGB+0x152> */
/* @0x2ac6fe ldrb.w r6, [sp, #0x4] */
/* @0x2ac700 cdphs p0, #0x0, c6, c3, c4, #0x0 */
/* @0x2ac702 cmp r6, #0x3 */
/* @0x2ac704 ble 0x2ac712 <png_handle_sRGB+0x7e> */
/* @0x2ac706 ldr r1, [pc, #0xf8] */
/* @0x2ac708 mov r0, r5 */
/* @0x2ac70a add r1, pc */
/* @0x2ac70c bl 0x2a6474 <png_warning> */
/* @0x2ac710 b 0x2ac7e6 <png_handle_sRGB+0x152> */
/* @0x2ac712 cmp r4, #0x0 */
/* @0x2ac714 beq 0x2ac7ce <png_handle_sRGB+0x13a> */
/* @0x2ac716 ldr r3, [r4, #0x8] */
/* @0x2ac718 lsls r2, r3, #0x1f */
/* @0x2ac71a bpl 0x2ac74a <png_handle_sRGB+0xb6> */
/* @0x2ac71c ldr.w r3, [r4, #0xfc] */
/* @0x2ac720 sub.w r3, r3, #0xaf00 */
/* @0x2ac724 subs r3, #0xc8 */
/* @0x2ac726 cmp.w r3, #0x3e8 */
/* @0x2ac728 stmdble lr, {r1, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2ac72a bls 0x2ac74a <png_handle_sRGB+0xb6> */
/* @0x2ac72c ldr r1, [pc, #0xd4] */
/* @0x2ac72e mov r0, r5 */
/* @0x2ac730 add r1, pc */
/* @0x2ac732 bl 0x2a6474 <png_warning> */
/* @0x2ac734 ldmdami r4!, {r0, r1, r2, r3, r4, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2ac736 ldr r0, [pc, #0xd0] */
/* @0x2ac738 ldr r1, [pc, #0xd0] */
/* @0x2ac73a add r0, pc */
/* @0x2ac73c ldr r0, [r0] */
/* @0x2ac73e ldr.w r2, [r5, #0x2e0] */
/* @0x2ac740 adclo r2, r8, r0, ror #5 */
/* @0x2ac742 adds r0, #0xa8 */
/* @0x2ac744 add r1, pc */
/* @0x2ac746 blx 0xb68a4 <fprintf@plt> */
/* @0x2ac748 stmvs r3!, {r1, r2, r3, r5, r7, r11, sp, lr, pc} */
/* @0x2ac74a ldr r3, [r4, #0x8] */
/* @0x2ac74c lsls r3, r3, #0x1d */
/* @0x2ac74e bpl 0x2ac7ce <png_handle_sRGB+0x13a> */
/* @0x2ac750 ldr.w r3, [r4, #0x100] */
/* @0x2ac754 sub.w r3, r3, #0x7600 */
/* @0x2ac758 subs r3, #0x3e */
/* @0x2ac75a cmp.w r3, #0x7d0 */
/* @0x2ac75c ldmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac75e bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac760 ldr.w r3, [r4, #0x104] */
/* @0x2ac764 sub.w r3, r3, #0x7c80 */
/* @0x2ac768 subs r3, #0x1c */
/* @0x2ac76a cmp.w r3, #0x7d0 */
/* @0x2ac76c ldmdale r4!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac76e bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac770 ldr.w r3, [r4, #0x108] */
/* @0x2ac774 sub.w r3, r3, #0xf600 */
/* @0x2ac778 subs r3, #0x18 */
/* @0x2ac77a cmp.w r3, #0x7d0 */
/* @0x2ac77c stmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac77e bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac780 ldr.w r3, [r4, #0x10c] */
/* @0x2ac784 sub.w r3, r3, #0x7d00 */
/* @0x2ac788 cmp.w r3, #0x7d0 */
/* @0x2ac78c bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac78e ldr.w r3, [r4, #0x110] */
/* @0x2ac790 .word 0xf5a33110 */
/* @0x2ac792 sub.w r3, r3, #0x7100 */
/* @0x2ac794 bllo 0x14bd724 <b2_toiTime+0xd64280> */
/* @0x2ac796 subs r3, #0x48 */
/* @0x2ac798 cmp.w r3, #0x7d0 */
/* @0x2ac79c bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac79e ldr.w r3, [r4, #0x114] */
/* @0x2ac7a0 .word 0xf5a33114 */
/* @0x2ac7a2 sub.w r3, r3, #0xe600 */
/* @0x2ac7a4 bllo 0x20bd544 <b2_toiTime+0x19640a0> */
/* @0x2ac7a6 subs r3, #0x78 */
/* @0x2ac7a8 cmp.w r3, #0x7d0 */
/* @0x2ac7ac bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac7ae ldr.w r3, [r4, #0x118] */
/* @0x2ac7b0 .word 0xf5a33118 */
/* @0x2ac7b2 sub.w r3, r3, #0x3680 */
/* @0x2ac7b4 bllo 0xec1524 <b2_toiTime+0x768080> */
/* @0x2ac7b6 subs r3, #0x30 */
/* @0x2ac7b8 cmp.w r3, #0x7d0 */
/* @0x2ac7bc bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac7be ldr.w r3, [r4, #0x11c] */
/* @0x2ac7c0 .word 0xf5a3311c */
/* @0x2ac7c2 sub.w r3, r3, #0x1380 */
/* @0x2ac7c4 bllo 0x4c163c <SrcVerts+0x1e680> */
/* @0x2ac7c6 subs r3, #0x8 */
/* @0x2ac7c8 cmp.w r3, #0x7d0 */
/* @0x2ac7cc bhi 0x2ac7da <png_handle_sRGB+0x146> */
/* @0x2ac7ce mov r0, r5 */
/* @0x2ac7d0 mov r1, r4 */
/* @0x2ac7d2 mov r2, r6 */
/* @0x2ac7d4 bl 0x2aed48 <png_set_sRGB_gAMA_and_cHRM> */
/* @0x2ac7d8 b 0x2ac7e6 <png_handle_sRGB+0x152> */
/* @0x2ac7da ldr r1, [pc, #0x34] */
/* @0x2ac7dc mov r0, r5 */
/* @0x2ac7de add r1, pc */
/* @0x2ac7e0 bl 0x2a6474 <png_warning> */
/* @0x2ac7e4 b 0x2ac7ce <png_handle_sRGB+0x13a> */
/* @0x2ac7e6 add sp, #0x8 */
/* @0x2ac7e8 pop {r4, r5, r6, pc} */
/* @0x2ac7ea nop */
/* @0x2ac7ec lsrs r2, r0, #0x5 */
/* @0x2ac7ee movs r6, r1 */
/* @0x2ac7f0 lsrs r5, r1, #0x5 */
/* @0x2ac7f2 movs r6, r1 */
/* @0x2ac7f4 lsrs r3, r3, #0x5 */
/* @0x2ac7f6 movs r6, r1 */
/* @0x2ac7f8 lsrs r1, r4, #0x5 */
/* @0x2ac7fa movs r6, r1 */
/* @0x2ac7fc lsrs r4, r5, #0x5 */
/* @0x2ac7fe movs r6, r1 */
/* @0x2ac800 lsrs r0, r3, #0x5 */
/* @0x2ac802 movs r6, r1 */
/* @0x2ac804 lsls r7, r0, #0x1c */
/* @0x2ac806 movs r6, r1 */
/* @0x2ac808 ldr r5, [pc, #0x38] */
/* @0x2ac80a movs r4, r2 */
/* @0x2ac80c lsrs r2, r6, #0x4 */
/* @0x2ac80e movs r6, r1 */
/* @0x2ac810 lsls r2, r3, #0x1e */
/* @0x2ac812 movs r6, r1 */

/* ── FUNC 0x2ac814 · png_handle_iCCP · size=472 · insn=213 */
/* @0x2ac814 ldr r3, [pc, #0x1a8] */
/* @0x2ac816 push.w {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2ac818 ldrbtmi r4, [r11], #-1008 */
/* @0x2ac81a add r3, pc */
/* @0x2ac81c ldr r3, [r3] */
/* @0x2ac81e mov r5, r2 */
/* @0x2ac820 sub sp, #0x4c */
/* @0x2ac822 ldr r2, [r3] */
/* @0x2ac824 mov r4, r0 */
/* @0x2ac826 mov r7, r1 */
/* @0x2ac828 mov r8, r3 */
/* @0x2ac82a str r2, [sp, #0x44] */
/* @0x2ac82c ldr.w r2, [r0, #0x12c] */
/* @0x2ac830 tst.w r2, #0x1 */
/* @0x2ac834 bne 0x2ac840 <png_handle_iCCP+0x2c> */
/* @0x2ac836 ldr r1, [pc, #0x18c] */
/* @0x2ac838 add r1, pc */
/* @0x2ac83a bl 0x2a642c <png_error> */
/* @0x2ac83c .word 0xe00afdf7 */
/* @0x2ac83e b 0x2ac856 <png_handle_iCCP+0x42> */
/* @0x2ac840 lsls r1, r2, #0x1d */
/* @0x2ac842 bpl 0x2ac84a <png_handle_iCCP+0x36> */
/* @0x2ac844 ldr r1, [pc, #0x180] */
/* @0x2ac846 add r1, pc */
/* @0x2ac848 b 0x2ac864 <png_handle_iCCP+0x50> */
/* @0x2ac84a lsls r2, r2, #0x1e */
/* @0x2ac84c bpl 0x2ac856 <png_handle_iCCP+0x42> */
/* @0x2ac84e ldr r1, [pc, #0x17c] */
/* @0x2ac850 add r1, pc */
/* @0x2ac852 bl 0x2a6474 <png_warning> */
/* @0x2ac854 strtmi pc, [r0], -pc, lsl #28 */
/* @0x2ac856 mov r0, r4 */
/* @0x2ac858 cbz r7, 0x2ac872 <png_handle_iCCP+0x5e> */
/* @0x2ac85a ldr r3, [r7, #0x8] */
/* @0x2ac85c lsls r3, r3, #0x13 */
/* @0x2ac85e bpl 0x2ac872 <png_handle_iCCP+0x5e> */
/* @0x2ac860 ldr r1, [pc, #0x16c] */
/* @0x2ac862 add r1, pc */
/* @0x2ac864 bl 0x2a6474 <png_warning> */
/* @0x2ac868 mov r0, r4 */
/* @0x2ac86a mov r1, r5 */
/* @0x2ac86c bl 0x2abc94 <png_crc_finish> */
/* @0x2ac870 b 0x2ac9aa <png_handle_iCCP+0x196> */
/* @0x2ac872 ldr.w r1, [r4, #0x330] */
/* @0x2ac874 .word 0xf7fa1330 */
/* @0x2ac876 bl 0x2a6cfc <png_free> */
/* @0x2ac878 .word 0x1c69fa41 */
/* @0x2ac87a adds r1, r5, #0x1 */
/* @0x2ac87c mov r0, r4 */
/* @0x2ac87e bl 0x2a6ca0 <png_malloc> */
/* @0x2ac880 strtmi pc, [r10], -pc, lsl #20 */
/* @0x2ac882 mov r2, r5 */
/* @0x2ac884 mov r1, r0 */
/* @0x2ac886 str.w r0, [r4, #0x330] */
/* @0x2ac888 qasxmi r0, r0, r0 */
/* @0x2ac88a mov r0, r4 */
/* @0x2ac88c bl 0x2abc0c <png_crc_read> */
/* @0x2ac890 mov r0, r4 */
/* @0x2ac892 movs r1, #0x0 */
/* @0x2ac894 bl 0x2abc94 <png_crc_finish> */
/* @0x2ac898 cmp r0, #0x0 */
/* @0x2ac89a bne 0x2ac99a <png_handle_iCCP+0x186> */
/* @0x2ac89c ldr.w r3, [r4, #0x330] */
/* @0x2ac8a0 strb r0, [r3, r5] */
/* @0x2ac8a2 ldr.w r1, [r4, #0x330] */
/* @0x2ac8a4 .word 0x460a1330 */
/* @0x2ac8a6 mov r2, r1 */
/* @0x2ac8a8 mov r3, r2 */
/* @0x2ac8aa adds r2, #0x1 */
/* @0x2ac8ac ldrb r0, [r3] */
/* @0x2ac8ae cmp r0, #0x0 */
/* @0x2ac8b0 bne 0x2ac8a8 <png_handle_iCCP+0x94> */
/* @0x2ac8b2 cbz r5, 0x2ac8be <png_handle_iCCP+0xaa> */
/* @0x2ac8b4 mov r0, r2 */
/* @0x2ac8b6 subs r2, r5, #0x1 */
/* @0x2ac8b8 add r2, r1 */
/* @0x2ac8ba cmp r0, r2 */
/* @0x2ac8bc blo 0x2ac8d2 <png_handle_iCCP+0xbe> */
/* @0x2ac8be mov r0, r4 */
/* @0x2ac8c0 bl 0x2a6cfc <png_free> */
/* @0x2ac8c4 ldr r1, [pc, #0x10c] */
/* @0x2ac8c6 movs r3, #0x0 */
/* @0x2ac8c8 mov r0, r4 */
/* @0x2ac8ca str.w r3, [r4, #0x330] */
/* @0x2ac8cc ldrbtmi r3, [r9], #-816 */
/* @0x2ac8ce add r1, pc */
/* @0x2ac8d0 b 0x2ac984 <png_handle_iCCP+0x170> */
/* @0x2ac8d2 adds r6, r3, #0x2 */
/* @0x2ac8d4 ldrb r3, [r3, #0x1] */
/* @0x2ac8d6 cbz r3, 0x2ac8e2 <png_handle_iCCP+0xce> */
/* @0x2ac8d8 ldr r1, [pc, #0xfc] */
/* @0x2ac8da mov r0, r4 */
/* @0x2ac8dc add r1, pc */
/* @0x2ac8de bl 0x2a6474 <png_warning> */
/* @0x2ac8e0 .word 0xf8d4fdc9 */
/* @0x2ac8e2 ldr.w r3, [r4, #0x330] */
/* @0x2ac8e4 qasxmi r3, r10, r0 */
/* @0x2ac8e6 mov r2, r5 */
/* @0x2ac8e8 mov r0, r4 */
/* @0x2ac8ea movs r1, #0x0 */
/* @0x2ac8ec subs r6, r6, r3 */
/* @0x2ac8ee add r3, sp, #0xc */
/* @0x2ac8f0 str r3, [sp] */
/* @0x2ac8f2 mov r3, r6 */
/* @0x2ac8f4 bl 0x2abd08 <png_decompress_chunk> */
/* @0x2ac8f8 ldr r5, [sp, #0xc] */
/* @0x2ac8fa cmp r6, r5 */
/* @0x2ac8fc bhi 0x2ac904 <png_handle_iCCP+0xf0> */
/* @0x2ac8fe subs r5, r5, r6 */
/* @0x2ac900 cmp r5, #0x3 */
/* @0x2ac902 bhi 0x2ac91c <png_handle_iCCP+0x108> */
/* @0x2ac904 mov r0, r4 */
/* @0x2ac906 ldr.w r1, [r4, #0x330] */
/* @0x2ac908 .word 0xf7fa1330 */
/* @0x2ac90a bl 0x2a6cfc <png_free> */
/* @0x2ac90c ldmdbmi r3!, {r0, r1, r2, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2ac90e ldr r1, [pc, #0xcc] */
/* @0x2ac910 movs r3, #0x0 */
/* @0x2ac912 mov r0, r4 */
/* @0x2ac914 str.w r3, [r4, #0x330] */
/* @0x2ac918 add r1, pc */
/* @0x2ac91a b 0x2ac984 <png_handle_iCCP+0x170> */
/* @0x2ac91c ldr.w r2, [r4, #0x330] */
/* @0x2ac920 adds r1, r2, r6 */
/* @0x2ac922 ldrb r3, [r2, r6] */
/* @0x2ac924 ldrb.w r9, [r1, #0x1] */
/* @0x2ac928 lsl.w r9, r9, #0x10 */
/* @0x2ac92c orr.w r9, r9, r3, lsl #24 */
/* @0x2ac930 ldrb r3, [r1, #0x3] */
/* @0x2ac932 orr.w r9, r9, r3 */
/* @0x2ac934 stmvc r11, {r0, r1, r8, r11} */
/* @0x2ac936 ldrb r3, [r1, #0x2] */
/* @0x2ac938 orr.w r9, r9, r3, lsl #8 */
/* @0x2ac93c cmp r9, r5 */
/* @0x2ac93e blo 0x2ac98a <png_handle_iCCP+0x176> */
/* @0x2ac940 bls 0x2ac98c <png_handle_iCCP+0x178> */
/* @0x2ac942 mov r1, r2 */
/* @0x2ac944 mov r0, r4 */
/* @0x2ac946 bl 0x2a6cfc <png_free> */
/* @0x2ac948 stmdbmi r5!, {r0, r3, r4, r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2ac94a ldr r1, [pc, #0x94] */
/* @0x2ac94c movs r3, #0x0 */
/* @0x2ac94e mov r0, r4 */
/* @0x2ac950 str.w r3, [r4, #0x330] */
/* @0x2ac954 add r1, pc */
/* @0x2ac956 bl 0x2a6474 <png_warning> */
/* @0x2ac958 cdpge p13, #0x0, c15, c4, c13, #0x4 */
/* @0x2ac95a add r6, sp, #0x10 */
/* @0x2ac95c ldr r2, [pc, #0x84] */
/* @0x2ac95e mov r3, r9 */
/* @0x2ac960 movs r1, #0x32 */
/* @0x2ac962 mov r0, r6 */
/* @0x2ac964 add r2, pc */
/* @0x2ac966 blx 0xb65c8 <snprintf@plt> */
/* @0x2ac968 qasxmi lr, r0, r0 */
/* @0x2ac96a mov r0, r4 */
/* @0x2ac96c mov r1, r6 */
/* @0x2ac96e bl 0x2a6474 <png_warning> */
/* @0x2ac970 bmi 0xa2bf7c <b2_toiTime+0x2d2ad8> */
/* @0x2ac972 ldr r2, [pc, #0x74] */
/* @0x2ac974 movs r1, #0x32 */
/* @0x2ac976 mov r0, r6 */
/* @0x2ac978 add r2, pc */
/* @0x2ac97a mov r3, r5 */
/* @0x2ac97c blx 0xb65c8 <snprintf@plt> */
/* @0x2ac980 mov r0, r4 */
/* @0x2ac982 mov r1, r6 */
/* @0x2ac984 bl 0x2a6474 <png_warning> */
/* @0x2ac988 b 0x2ac9aa <png_handle_iCCP+0x196> */
/* @0x2ac98a mov r5, r9 */
/* @0x2ac98c stm.w sp, {r1, r5} */
/* @0x2ac990 mov r0, r4 */
/* @0x2ac992 mov r1, r7 */
/* @0x2ac994 movs r3, #0x0 */
/* @0x2ac996 bl 0x2aee48 <png_set_iCCP> */
/* @0x2ac998 qsaxmi pc, r0, r7 */
/* @0x2ac99a mov r0, r4 */
/* @0x2ac99c ldr.w r1, [r4, #0x330] */
/* @0x2ac9a0 bl 0x2a6cfc <png_free> */
/* @0x2ac9a4 movs r3, #0x0 */
/* @0x2ac9a6 str.w r3, [r4, #0x330] */
/* @0x2ac9a8 bls 0x6f9670 <g_SWFvertbuff+0x265a8> */
/* @0x2ac9aa ldr r2, [sp, #0x44] */
/* @0x2ac9ac ldr.w r3, [r8] */
/* @0x2ac9b0 cmp r2, r3 */
/* @0x2ac9b2 beq 0x2ac9b8 <png_handle_iCCP+0x1a4> */
/* @0x2ac9b4 blx 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2ac9b8 add sp, #0x4c */
/* @0x2ac9ba pop.w {r4, r5, r6, r7, r8, r9, pc} */
/* @0x2ac9bc svclt #0x83f0 */
/* @0x2ac9be nop */
/* @0x2ac9c0 asrs r2, r7, #0x4 */
/* @0x2ac9c2 movs r4, r2 */
/* @0x2ac9c4 lsrs r3, r3, #0x1 */
/* @0x2ac9c6 movs r6, r1 */
/* @0x2ac9c8 lsrs r6, r4, #0x1 */
/* @0x2ac9ca movs r6, r1 */
/* @0x2ac9cc lsrs r4, r6, #0x1 */
/* @0x2ac9ce movs r6, r1 */
/* @0x2ac9d0 lsrs r2, r7, #0x1 */
/* @0x2ac9d2 movs r6, r1 */
/* @0x2ac9d4 lsrs r3, r4, #0x20 */
/* @0x2ac9d6 movs r6, r1 */
/* @0x2ac9d8 lsrs r2, r5, #0x20 */
/* @0x2ac9da movs r6, r1 */
/* @0x2ac9dc lsrs r6, r3, #0x20 */
/* @0x2ac9de movs r6, r1 */
/* @0x2ac9e0 lsrs r5, r1, #0x20 */
/* @0x2ac9e2 movs r6, r1 */
/* @0x2ac9e4 lsrs r5, r3, #0x20 */
/* @0x2ac9e6 movs r6, r1 */
/* @0x2ac9e8 lsrs r5, r4, #0x20 */
/* @0x2ac9ea movs r6, r1 */

/* ── FUNC 0x2ac9ec · png_handle_sPLT · size=512 · insn=231 */
/* @0x2ac9ec push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2ac9f0 mov r4, r0 */
/* @0x2ac9f2 ldr.w r3, [r0, #0x310] */
/* @0x2ac9f4 addlt r3, r5, r0, lsl r3 */
/* @0x2ac9f6 sub sp, #0x14 */
/* @0x2ac9f8 mov r8, r1 */
/* @0x2ac9fa mov r6, r2 */
/* @0x2ac9fc cbz r3, 0x2aca1e <png_handle_sPLT+0x32> */
/* @0x2ac9fe cmp r3, #0x1 */
/* @0x2aca00 beq 0x2aca16 <png_handle_sPLT+0x2a> */
/* @0x2aca02 subs r3, #0x1 */
/* @0x2aca04 str.w r3, [r0, #0x310] */
/* @0x2aca08 cmp r3, #0x1 */
/* @0x2aca0a bne 0x2aca1e <png_handle_sPLT+0x32> */
/* @0x2aca0c ldr r1, [pc, #0x1c0] */
/* @0x2aca0e add r1, pc */
/* @0x2aca10 bl 0x2a6474 <png_warning> */
/* @0x2aca14 mov r0, r4 */
/* @0x2aca16 mov r1, r6 */
/* @0x2aca18 bl 0x2abc94 <png_crc_finish> */
/* @0x2aca1c b 0x2acbc4 <png_handle_sPLT+0x1d8> */
/* @0x2aca1e ldr.w r3, [r4, #0x12c] */
/* @0x2aca20 ldrbeq r3, [r10, r12, lsr #2] */
/* @0x2aca22 lsls r2, r3, #0x1f */
/* @0x2aca24 bmi 0x2aca32 <png_handle_sPLT+0x46> */
/* @0x2aca26 ldr r1, [pc, #0x1ac] */
/* @0x2aca28 mov r0, r4 */
/* @0x2aca2a add r1, pc */
/* @0x2aca2c bl 0x2a642c <png_error> */
/* @0x2aca30 b 0x2aca3e <png_handle_sPLT+0x52> */
/* @0x2aca32 lsls r3, r3, #0x1d */
/* @0x2aca34 bpl 0x2aca3e <png_handle_sPLT+0x52> */
/* @0x2aca36 ldr r1, [pc, #0x1a0] */
/* @0x2aca38 mov r0, r4 */
/* @0x2aca3a add r1, pc */
/* @0x2aca3c b 0x2aca10 <png_handle_sPLT+0x24> */
/* @0x2aca3e mov r0, r4 */
/* @0x2aca40 ldr.w r1, [r4, #0x330] */
/* @0x2aca44 bl 0x2a6cfc <png_free> */
/* @0x2aca48 adds r1, r6, #0x1 */
/* @0x2aca4a mov r0, r4 */
/* @0x2aca4c bl 0x2a6ca0 <png_malloc> */
/* @0x2aca50 mov r2, r6 */
/* @0x2aca52 mov r1, r0 */
/* @0x2aca54 str.w r0, [r4, #0x330] */
/* @0x2aca58 mov r0, r4 */
/* @0x2aca5a bl 0x2abc0c <png_crc_read> */
/* @0x2aca5c .word 0x4620f8d7 */
/* @0x2aca5e mov r0, r4 */
/* @0x2aca60 movs r1, #0x0 */
/* @0x2aca62 bl 0x2abc94 <png_crc_finish> */
/* @0x2aca64 .word 0xb140f917 */
/* @0x2aca66 cbz r0, 0x2aca7a <png_handle_sPLT+0x8e> */
/* @0x2aca68 mov r0, r4 */
/* @0x2aca6a ldr.w r1, [r4, #0x330] */
/* @0x2aca6c .word 0xf7fa1330 */
/* @0x2aca6e bl 0x2a6cfc <png_free> */
/* @0x2aca70 movwhs pc, #0x945 */
/* @0x2aca72 movs r3, #0x0 */
/* @0x2aca74 str.w r3, [r4, #0x330] */
/* @0x2aca78 b 0x2acbc4 <png_handle_sPLT+0x1d8> */
/* @0x2aca7a ldr.w r3, [r4, #0x330] */
/* @0x2aca7c ldrpl r3, [r8, #0x330] */
/* @0x2aca7e strb r0, [r3, r6] */
/* @0x2aca80 ldr.w r7, [r4, #0x330] */
/* @0x2aca84 mov r2, r7 */
/* @0x2aca86 mov r3, r2 */
/* @0x2aca88 adds r2, #0x1 */
/* @0x2aca8a ldrb.w r9, [r3] */
/* @0x2aca8c .word 0xf1b99000 */
/* @0x2aca8e cmp.w r9, #0x0 */
/* @0x2aca90 mvnsle r0, r0, lsl #30 */
/* @0x2aca92 bne 0x2aca86 <png_handle_sPLT+0x9a> */
/* @0x2aca94 cmp r6, #0x1 */
/* @0x2aca96 mov r1, r2 */
/* @0x2aca98 bls 0x2acaa2 <png_handle_sPLT+0xb6> */
/* @0x2aca9a subs r2, r6, #0x2 */
/* @0x2aca9c add r2, r7 */
/* @0x2aca9e cmp r1, r2 */
/* @0x2acaa0 bls 0x2acab8 <png_handle_sPLT+0xcc> */
/* @0x2acaa2 mov r0, r4 */
/* @0x2acaa4 mov r1, r7 */
/* @0x2acaa6 bl 0x2a6cfc <png_free> */
/* @0x2acaa8 stmdbmi r12, {r0, r3, r5, r8, r11, r12, sp, lr, pc} ^ */
/* @0x2acaaa ldr r1, [pc, #0x130] */
/* @0x2acaac movs r3, #0x0 */
/* @0x2acaae mov r0, r4 */
/* @0x2acab0 str.w r3, [r4, #0x330] */
/* @0x2acab4 add r1, pc */
/* @0x2acab6 b 0x2acb28 <png_handle_sPLT+0x13c> */
/* @0x2acab8 ldrb.w r10, [r3, #0x1] */
/* @0x2acabc adds r5, r3, #0x2 */
/* @0x2acabe rsb r11, r5, r7 */
/* @0x2acac0 ldrtmi r0, [r3], #2823 */
/* @0x2acac2 add r11, r6 */
/* @0x2acac4 strb.w r10, [sp, #0x4] */
/* @0x2acac8 cmp.w r10, #0x8 */
/* @0x2acacc ite ne */
/* @0x2acace movne.w r10, #0xa */
/* @0x2acad0 .word 0xf04f0a0a */
/* @0x2acad2 moveq.w r10, #0x6 */
/* @0x2acad4 ldrbmi r0, [r8], -r6, lsl #20 */
/* @0x2acad6 mov r0, r11 */
/* @0x2acad8 mov r1, r10 */
/* @0x2acada blx 0x318dec <__aeabi_idivmod> */
/* @0x2acadc strmi lr, [lr], -r8, lsl #19 */
/* @0x2acade mov r6, r1 */
/* @0x2acae0 cbz r1, 0x2acaf6 <png_handle_sPLT+0x10a> */
/* @0x2acae2 mov r0, r4 */
/* @0x2acae4 mov r1, r7 */
/* @0x2acae6 bl 0x2a6cfc <png_free> */
/* @0x2acae8 ldmdbmi sp!, {r0, r3, r8, r11, r12, sp, lr, pc} */
/* @0x2acaea ldr r1, [pc, #0xf4] */
/* @0x2acaec str.w r9, [r4, #0x330] */
/* @0x2acaf0 mov r0, r4 */
/* @0x2acaf2 add r1, pc */
/* @0x2acaf4 b 0x2acb28 <png_handle_sPLT+0x13c> */
/* @0x2acaf6 mov r1, r10 */
/* @0x2acaf8 mov r0, r11 */
/* @0x2acafa blx 0x318d10 <__divsi3> */
/* @0x2acafc bmi 0xfa6f2c <b2_toiTime+0x84da88> */
/* @0x2acafe ldr r2, [pc, #0xcc] */
/* @0x2acb00 cmp r0, r2 */
/* @0x2acb02 mov r1, r0 */
/* @0x2acb04 str r0, [sp, #0xc] */
/* @0x2acb06 bls 0x2acb10 <png_handle_sPLT+0x124> */
/* @0x2acb08 ldr r1, [pc, #0xd8] */
/* @0x2acb0a mov r0, r4 */
/* @0x2acb0c add r1, pc */
/* @0x2acb0e b 0x2acb28 <png_handle_sPLT+0x13c> */
/* @0x2acb10 movs r7, #0xa */
/* @0x2acb12 mov r0, r4 */
/* @0x2acb14 muls r1, r7, r1 */
/* @0x2acb16 bl 0x2a6d16 <png_malloc_warn> */
/* @0x2acb18 .word 0x9002f8fe */
/* @0x2acb1a str r0, [sp, #0x8] */
/* @0x2acb1c cbz r0, 0x2acb22 <png_handle_sPLT+0x136> */
/* @0x2acb1e mov r2, r6 */
/* @0x2acb20 b 0x2acb60 <png_handle_sPLT+0x174> */
/* @0x2acb22 ldr r1, [pc, #0xc4] */
/* @0x2acb24 mov r0, r4 */
/* @0x2acb26 add r1, pc */
/* @0x2acb28 bl 0x2a6474 <png_warning> */
/* @0x2acb2c b 0x2acbc4 <png_handle_sPLT+0x1d8> */
/* @0x2acb2e ldrb.w r6, [sp, #0x4] */
/* @0x2acb30 blx 0x484b4a <g_AccelX+0x8e> */
/* @0x2acb32 mul r1, r7, r2 */
/* @0x2acb34 stmdals r2, {r1, r8, r12, sp, lr, pc} */
/* @0x2acb36 ldr r0, [sp, #0x8] */
/* @0x2acb38 cmp r6, #0x8 */
/* @0x2acb3a ldrb r6, [r5] */
/* @0x2acb3c add.w r3, r0, r1 */
/* @0x2acb40 bne 0x2acb68 <png_handle_sPLT+0x17c> */
/* @0x2acb42 strh r6, [r0, r1] */
/* @0x2acb44 adds r0, r5, #0x4 */
/* @0x2acb46 ldrb r1, [r5, #0x1] */
/* @0x2acb48 strh r1, [r3, #0x2] */
/* @0x2acb4a ldrb r1, [r5, #0x2] */
/* @0x2acb4c strh r1, [r3, #0x4] */
/* @0x2acb4e ldrb r1, [r5, #0x3] */
/* @0x2acb50 strh r1, [r3, #0x6] */
/* @0x2acb52 ldrb r5, [r0] */
/* @0x2acb54 adds r2, #0x1 */
/* @0x2acb56 ldrb r1, [r0, #0x1] */
/* @0x2acb58 add.w r1, r1, r5, lsl #8 */
/* @0x2acb5c adds r5, r0, #0x2 */
/* @0x2acb5e strh r1, [r3, #0x8] */
/* @0x2acb60 ldr r3, [sp, #0xc] */
/* @0x2acb62 cmp r2, r3 */
/* @0x2acb64 blt 0x2acb2e <png_handle_sPLT+0x142> */
/* @0x2acb66 b 0x2acb96 <png_handle_sPLT+0x1aa> */
/* @0x2acb68 ldrb.w lr, [r5, #0x1] */
/* @0x2acb6c add.w r6, lr, r6, lsl #8 */
/* @0x2acb70 strh r6, [r0, r1] */
/* @0x2acb72 ldrb r0, [r5, #0x2] */
/* @0x2acb74 ldrb r1, [r5, #0x3] */
/* @0x2acb76 add.w r1, r1, r0, lsl #8 */
/* @0x2acb78 subshi r2, r9, r0, lsl #2 */
/* @0x2acb7a strh r1, [r3, #0x2] */
/* @0x2acb7c ldrb r0, [r5, #0x4] */
/* @0x2acb7e ldrb r1, [r5, #0x5] */
/* @0x2acb80 add.w r1, r1, r0, lsl #8 */
/* @0x2acb84 strh r1, [r3, #0x4] */
/* @0x2acb86 ldrb r0, [r5, #0x6] */
/* @0x2acb88 ldrb r1, [r5, #0x7] */
/* @0x2acb8a add.w r1, r1, r0, lsl #8 */
/* @0x2acb8c .word 0xf1052100 */
/* @0x2acb8e add.w r0, r5, #0x8 */
/* @0x2acb90 sbcshi r0, r9, r8 */
/* @0x2acb92 strh r1, [r3, #0x6] */
/* @0x2acb94 b 0x2acb52 <png_handle_sPLT+0x166> */
/* @0x2acb96 ldr.w r3, [r4, #0x330] */
/* @0x2acb98 bge 0x3b9860 <error_g0017+0x12504> */
/* @0x2acb9a add r2, sp, #0x10 */
/* @0x2acb9c mov r0, r4 */
/* @0x2acb9e mov r1, r8 */
/* @0x2acba0 str r3, [r2, #-16]! */
/* @0x2acba4 movs r3, #0x1 */
/* @0x2acba6 mov r2, sp */
/* @0x2acba8 bl 0x2af20c <png_set_sPLT> */
/* @0x2acbac mov r0, r4 */
/* @0x2acbae ldr.w r1, [r4, #0x330] */
/* @0x2acbb0 .word 0xf7fa1330 */
/* @0x2acbb2 bl 0x2a6cfc <png_free> */
/* @0x2acbb4 movwhs pc, #0x8a3 */
/* @0x2acbb6 movs r3, #0x0 */
/* @0x2acbb8 mov r0, r4 */
/* @0x2acbba str.w r3, [r4, #0x330] */
/* @0x2acbbc stmdbls r2, {r4, r5, r8, r9, r12, sp} */
/* @0x2acbbe ldr r1, [sp, #0x8] */
/* @0x2acbc0 bl 0x2a6cfc <png_free> */
/* @0x2acbc4 add sp, #0x14 */
/* @0x2acbc6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2acbc8 svclt #0x8ff0 */
/* @0x2acbca nop */
/* @0x2acbcc ldr r1, [sp, #0x264] */
/* @0x2acbce adds r1, r3, r6 */
/* @0x2acbd0 lsls r3, r5, #0x1e */
/* @0x2acbd2 movs r6, r1 */
/* @0x2acbd4 lsls r0, r6, #0x1e */
/* @0x2acbd6 movs r6, r1 */
/* @0x2acbd8 lsls r1, r7, #0x1e */
/* @0x2acbda movs r6, r1 */
/* @0x2acbdc lsls r7, r2, #0x1d */
/* @0x2acbde movs r6, r1 */
/* @0x2acbe0 lsls r6, r5, #0x1c */
/* @0x2acbe2 movs r6, r1 */
/* @0x2acbe4 lsls r6, r5, #0x1c */
/* @0x2acbe6 movs r6, r1 */
/* @0x2acbe8 lsls r0, r5, #0x1c */
/* @0x2acbea movs r6, r1 */
