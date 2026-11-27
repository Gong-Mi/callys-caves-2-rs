/* libyoyo.so 覆盖卡组 0297
 * 函数 0x31afa4..0x31b220，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x31afa4 · __gtdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afac · __ledf2 · size=144 · insn=2 */
/* @0x31afac mov r12, #1 */
/* @0x31afb0 b 0x31afb8 <__nedf2+0x4> */

/* ── FUNC 0x31afac · __ltdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afb4 · __cmpdf2 · size=136 · insn=34 */
/* @0x31afb4 mov r12, #1 */
/* @0x31afb8 str r12, [sp, #-0x4]! */
/* @0x31afbc lsl r12, r1, #1 */
/* @0x31afc0 mvns r12, r12, asr #21 */
/* @0x31afc4 lsl r12, r3, #1 */
/* @0x31afc8 mvnsne r12, r12, asr #21 */
/* @0x31afcc beq 0x31b00c <__nedf2+0x58> */
/* @0x31afd0 add sp, sp, #4 */
/* @0x31afd4 orrs r12, r0, r1, lsl #1 */
/* @0x31afd8 orrseq r12, r2, r3, lsl #1 */
/* @0x31afdc teqne r1, r3 */
/* @0x31afe0 teqeq r0, r2 */
/* @0x31afe4 moveq r0, #0 */
/* @0x31afe8 bxeq lr */
/* @0x31afec cmn r0, #0 */
/* @0x31aff0 teq r1, r3 */
/* @0x31aff4 cmppl r1, r3 */
/* @0x31aff8 cmpeq r0, r2 */
/* @0x31affc asrhs r0, r3, #31 */
/* @0x31b000 mvnlo r0, r3, asr #31 */
/* @0x31b004 orr r0, r0, #1 */
/* @0x31b008 bx lr */
/* @0x31b00c lsl r12, r1, #1 */
/* @0x31b010 mvns r12, r12, asr #21 */
/* @0x31b014 bne 0x31b020 <__nedf2+0x6c> */
/* @0x31b018 orrs r12, r0, r1, lsl #12 */
/* @0x31b01c bne 0x31b034 <__nedf2+0x80> */
/* @0x31b020 lsl r12, r3, #1 */
/* @0x31b024 mvns r12, r12, asr #21 */
/* @0x31b028 bne 0x31afd0 <__nedf2+0x1c> */
/* @0x31b02c orrs r12, r2, r3, lsl #12 */
/* @0x31b030 beq 0x31afd0 <__nedf2+0x1c> */
/* @0x31b034 ldr r0, [sp], #4 */
/* @0x31b038 bx lr */

/* ── FUNC 0x31afb4 · __eqdf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31afb4 · __nedf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b03c · __aeabi_cdrcmple · size=48 · insn=7 */
/* @0x31b03c mov r12, r0 */
/* @0x31b040 mov r0, r2 */
/* @0x31b044 mov r2, r12 */
/* @0x31b048 mov r12, r1 */
/* @0x31b04c mov r1, r3 */
/* @0x31b050 mov r3, r12 */
/* @0x31b054 b 0x31b058 <__aeabi_cdcmple> */

/* ── FUNC 0x31b058 · __aeabi_cdcmpeq · size=20 · insn=5 */
/* @0x31b058 push {r0, lr} */
/* @0x31b05c bl 0x31afb4 <__nedf2> */
/* @0x31b060 cmp r0, #0 */
/* @0x31b064 cmnmi r0, #0 */
/* @0x31b068 pop {r0, pc} */

/* ── FUNC 0x31b058 · __aeabi_cdcmple · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b06c · __aeabi_dcmpeq · size=20 · insn=5 */
/* @0x31b06c str lr, [sp, #-0x8]! */
/* @0x31b070 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b074 moveq r0, #1 */
/* @0x31b078 movne r0, #0 */
/* @0x31b07c ldr pc, [sp], #8 */

/* ── FUNC 0x31b080 · __aeabi_dcmplt · size=20 · insn=5 */
/* @0x31b080 str lr, [sp, #-0x8]! */
/* @0x31b084 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b088 movlo r0, #1 */
/* @0x31b08c movhs r0, #0 */
/* @0x31b090 ldr pc, [sp], #8 */

/* ── FUNC 0x31b094 · __aeabi_dcmple · size=20 · insn=5 */
/* @0x31b094 str lr, [sp, #-0x8]! */
/* @0x31b098 bl 0x31b058 <__aeabi_cdcmple> */
/* @0x31b09c movls r0, #1 */
/* @0x31b0a0 movhi r0, #0 */
/* @0x31b0a4 ldr pc, [sp], #8 */

/* ── FUNC 0x31b0a8 · __aeabi_dcmpge · size=20 · insn=5 */
/* @0x31b0a8 str lr, [sp, #-0x8]! */
/* @0x31b0ac bl 0x31b03c <__aeabi_cdrcmple> */
/* @0x31b0b0 movls r0, #1 */
/* @0x31b0b4 movhi r0, #0 */
/* @0x31b0b8 ldr pc, [sp], #8 */

/* ── FUNC 0x31b0bc · __aeabi_dcmpgt · size=20 · insn=5 */
/* @0x31b0bc str lr, [sp, #-0x8]! */
/* @0x31b0c0 bl 0x31b03c <__aeabi_cdrcmple> */
/* @0x31b0c4 movlo r0, #1 */
/* @0x31b0c8 movhs r0, #0 */
/* @0x31b0cc ldr pc, [sp], #8 */

/* ── FUNC 0x31b0d0 · __aeabi_d2uiz · size=84 · insn=21 */
/* @0x31b0d0 lsls r2, r1, #1 */
/* @0x31b0d4 bhs 0x31b104 <__fixunsdfsi+0x34> */
/* @0x31b0d8 adds r2, r2, #2097152 */
/* @0x31b0dc bhs 0x31b10c <__fixunsdfsi+0x3c> */
/* @0x31b0e0 bpl 0x31b104 <__fixunsdfsi+0x34> */
/* @0x31b0e4 mvn r3, #992 */
/* @0x31b0e8 subs r2, r3, r2, asr #21 */
/* @0x31b0ec bmi 0x31b114 <__fixunsdfsi+0x44> */
/* @0x31b0f0 lsl r3, r1, #11 */
/* @0x31b0f4 orr r3, r3, #-2147483648 */
/* @0x31b0f8 orr r3, r3, r0, lsr #21 */
/* @0x31b0fc lsr r0, r3, r2 */
/* @0x31b100 bx lr */
/* @0x31b104 mov r0, #0 */
/* @0x31b108 bx lr */
/* @0x31b10c orrs r0, r0, r1, lsl #12 */
/* @0x31b110 bne 0x31b11c <__fixunsdfsi+0x4c> */
/* @0x31b114 mvn r0, #0 */
/* @0x31b118 bx lr */
/* @0x31b11c mov r0, #0 */
/* @0x31b120 bx lr */

/* ── FUNC 0x31b0d0 · __fixunsdfsi · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b124 · __gesf2 · size=116 · insn=2 */
/* @0x31b124 mvn r12, #0 */
/* @0x31b128 b 0x31b138 <__nesf2+0x4> */

/* ── FUNC 0x31b124 · __gtsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b12c · __lesf2 · size=108 · insn=2 */
/* @0x31b12c mov r12, #1 */
/* @0x31b130 b 0x31b138 <__nesf2+0x4> */

/* ── FUNC 0x31b12c · __ltsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b134 · __cmpsf2 · size=100 · insn=25 */
/* @0x31b134 mov r12, #1 */
/* @0x31b138 str r12, [sp, #-0x4]! */
/* @0x31b13c lsl r2, r0, #1 */
/* @0x31b140 lsl r3, r1, #1 */
/* @0x31b144 mvns r12, r2, asr #24 */
/* @0x31b148 mvnsne r12, r3, asr #24 */
/* @0x31b14c beq 0x31b170 <__nesf2+0x3c> */
/* @0x31b150 add sp, sp, #4 */
/* @0x31b154 orrs r12, r2, r3, lsr #1 */
/* @0x31b158 teqne r0, r1 */
/* @0x31b15c subspl r0, r2, r3 */
/* @0x31b160 asrhi r0, r1, #31 */
/* @0x31b164 mvnlo r0, r1, asr #31 */
/* @0x31b168 orrne r0, r0, #1 */
/* @0x31b16c bx lr */
/* @0x31b170 mvns r12, r2, asr #24 */
/* @0x31b174 bne 0x31b180 <__nesf2+0x4c> */
/* @0x31b178 lsls r12, r0, #9 */
/* @0x31b17c bne 0x31b190 <__nesf2+0x5c> */
/* @0x31b180 mvns r12, r3, asr #24 */
/* @0x31b184 bne 0x31b150 <__nesf2+0x1c> */
/* @0x31b188 lsls r12, r1, #9 */
/* @0x31b18c beq 0x31b150 <__nesf2+0x1c> */
/* @0x31b190 ldr r0, [sp], #4 */
/* @0x31b194 bx lr */

/* ── FUNC 0x31b134 · __eqsf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b134 · __nesf2 · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b198 · __aeabi_cfrcmple · size=36 · insn=4 */
/* @0x31b198 mov r12, r0 */
/* @0x31b19c mov r0, r1 */
/* @0x31b1a0 mov r1, r12 */
/* @0x31b1a4 b 0x31b1a8 <__aeabi_cfcmple> */

/* ── FUNC 0x31b1a8 · __aeabi_cfcmpeq · size=20 · insn=5 */
/* @0x31b1a8 push {r0, r1, r2, r3, lr} */
/* @0x31b1ac bl 0x31b134 <__nesf2> */
/* @0x31b1b0 cmp r0, #0 */
/* @0x31b1b4 cmnmi r0, #0 */
/* @0x31b1b8 pop {r0, r1, r2, r3, pc} */

/* ── FUNC 0x31b1a8 · __aeabi_cfcmple · alias of the symbol above · insn=0 */

/* ── FUNC 0x31b1bc · __aeabi_fcmpeq · size=20 · insn=5 */
/* @0x31b1bc str lr, [sp, #-0x8]! */
/* @0x31b1c0 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1c4 moveq r0, #1 */
/* @0x31b1c8 movne r0, #0 */
/* @0x31b1cc ldr pc, [sp], #8 */

/* ── FUNC 0x31b1d0 · __aeabi_fcmplt · size=20 · insn=5 */
/* @0x31b1d0 str lr, [sp, #-0x8]! */
/* @0x31b1d4 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1d8 movlo r0, #1 */
/* @0x31b1dc movhs r0, #0 */
/* @0x31b1e0 ldr pc, [sp], #8 */

/* ── FUNC 0x31b1e4 · __aeabi_fcmple · size=20 · insn=5 */
/* @0x31b1e4 str lr, [sp, #-0x8]! */
/* @0x31b1e8 bl 0x31b1a8 <__aeabi_cfcmple> */
/* @0x31b1ec movls r0, #1 */
/* @0x31b1f0 movhi r0, #0 */
/* @0x31b1f4 ldr pc, [sp], #8 */

/* ── FUNC 0x31b1f8 · __aeabi_fcmpge · size=20 · insn=5 */
/* @0x31b1f8 str lr, [sp, #-0x8]! */
/* @0x31b1fc bl 0x31b198 <__aeabi_cfrcmple> */
/* @0x31b200 movls r0, #1 */
/* @0x31b204 movhi r0, #0 */
/* @0x31b208 ldr pc, [sp], #8 */

/* ── FUNC 0x31b20c · __aeabi_fcmpgt · size=20 · insn=5 */
/* @0x31b20c str lr, [sp, #-0x8]! */
/* @0x31b210 bl 0x31b198 <__aeabi_cfrcmple> */
/* @0x31b214 movlo r0, #1 */
/* @0x31b218 movhs r0, #0 */
/* @0x31b21c ldr pc, [sp], #8 */

/* ── FUNC 0x31b220 · __divdi3 · size=1144 · insn=286 */
/* @0x31b220 cmp r1, #0 */
/* @0x31b224 mov r12, r2 */
/* @0x31b228 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x31b22c mov r5, r0 */
/* @0x31b230 sub sp, sp, #20 */
/* @0x31b234 mov r7, r1 */
/* @0x31b238 mov r8, r3 */
/* @0x31b23c movge r4, #0 */
/* @0x31b240 bge 0x31b258 <__divdi3+0x38> */
/* @0x31b244 rsbs r0, r0, #0 */
/* @0x31b248 rsc r1, r1, #0 */
/* @0x31b24c mvn r4, #0 */
/* @0x31b250 mov r5, r0 */
/* @0x31b254 mov r7, r1 */
/* @0x31b258 cmp r3, #0 */
/* @0x31b25c bge 0x31b274 <__divdi3+0x54> */
/* @0x31b260 rsbs r2, r2, #0 */
/* @0x31b264 rsc r3, r3, #0 */
/* @0x31b268 mvn r4, r4 */
/* @0x31b26c mov r12, r2 */
/* @0x31b270 mov r8, r3 */
/* @0x31b274 cmp r8, #0 */
/* @0x31b278 mov r6, r12 */
/* @0x31b27c mov r9, r5 */
/* @0x31b280 mov r10, r7 */
/* @0x31b284 bne 0x31b514 <__divdi3+0x2f4> */
/* @0x31b288 cmp r12, r7 */
/* @0x31b28c bls 0x31b354 <__divdi3+0x134> */
/* @0x31b290 clz r3, r12 */
/* @0x31b294 cmp r3, #0 */
/* @0x31b298 lslne r6, r12, r3 */
/* @0x31b29c rsbne r2, r3, #32 */
/* @0x31b2a0 lsrne r2, r5, r2 */
/* @0x31b2a4 lslne r9, r5, r3 */
/* @0x31b2a8 orrne r10, r2, r7, lsl r3 */
/* @0x31b2ac lsr r5, r6, #16 */
/* @0x31b2b0 uxth r8, r6 */
/* @0x31b2b4 mov r0, r10 */
/* @0x31b2b8 mov r1, r5 */
/* @0x31b2bc bl 0x318c48 <__udivsi3> */
/* @0x31b2c0 mov r1, r5 */
/* @0x31b2c4 mov r7, r0 */
/* @0x31b2c8 mul r11, r8, r0 */
/* @0x31b2cc mov r0, r10 */
/* @0x31b2d0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b2d4 lsr r3, r9, #16 */
/* @0x31b2d8 orr r1, r3, r1, lsl #16 */
/* @0x31b2dc cmp r1, r11 */
/* @0x31b2e0 movhs r10, r7 */
/* @0x31b2e4 bhs 0x31b300 <__divdi3+0xe0> */
/* @0x31b2e8 adds r1, r1, r6 */
/* @0x31b2ec sub r10, r7, #1 */
/* @0x31b2f0 bhs 0x31b300 <__divdi3+0xe0> */
/* @0x31b2f4 cmp r1, r11 */
/* @0x31b2f8 sublo r10, r7, #2 */
/* @0x31b2fc addlo r1, r1, r6 */
/* @0x31b300 rsb r11, r11, r1 */
/* @0x31b304 mov r1, r5 */
/* @0x31b308 uxth r9, r9 */
/* @0x31b30c mov r0, r11 */
/* @0x31b310 bl 0x318c48 <__udivsi3> */
/* @0x31b314 mov r1, r5 */
/* @0x31b318 mov r7, r0 */
/* @0x31b31c mul r8, r8, r0 */
/* @0x31b320 mov r0, r11 */
/* @0x31b324 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b328 orr r1, r9, r1, lsl #16 */
/* @0x31b32c cmp r1, r8 */
/* @0x31b330 movhs r12, r7 */
/* @0x31b334 bhs 0x31b34c <__divdi3+0x12c> */
/* @0x31b338 adds r6, r1, r6 */
/* @0x31b33c sub r12, r7, #1 */
/* @0x31b340 bhs 0x31b34c <__divdi3+0x12c> */
/* @0x31b344 cmp r6, r8 */
/* @0x31b348 sublo r12, r7, #2 */
/* @0x31b34c orr r12, r12, r10, lsl #16 */
/* @0x31b350 b 0x31b668 <__divdi3+0x448> */
/* @0x31b354 cmp r12, #0 */
/* @0x31b358 bne 0x31b36c <__divdi3+0x14c> */
/* @0x31b35c mov r0, #1 */
/* @0x31b360 mov r1, r8 */
/* @0x31b364 bl 0x318c48 <__udivsi3> */
/* @0x31b368 mov r6, r0 */
/* @0x31b36c clz r3, r6 */
/* @0x31b370 cmp r3, #0 */
/* @0x31b374 rsbeq r3, r6, r7 */
/* @0x31b378 moveq r5, #1 */
/* @0x31b37c beq 0x31b45c <__divdi3+0x23c> */
/* @0x31b380 lsl r6, r6, r3 */
/* @0x31b384 rsb r1, r3, #32 */
/* @0x31b388 lsr r2, r7, r1 */
/* @0x31b38c lsr r1, r5, r1 */
/* @0x31b390 lsr r8, r6, #16 */
/* @0x31b394 orr r7, r1, r7, lsl r3 */
/* @0x31b398 mov r0, r2 */
/* @0x31b39c lsl r9, r5, r3 */
/* @0x31b3a0 mov r1, r8 */
/* @0x31b3a4 str r2, [sp, #0x4] */
/* @0x31b3a8 bl 0x318c48 <__udivsi3> */
/* @0x31b3ac uxth r11, r6 */
/* @0x31b3b0 ldr r2, [sp, #0x4] */
/* @0x31b3b4 mov r1, r8 */
/* @0x31b3b8 mul r12, r11, r0 */
/* @0x31b3bc mov r10, r0 */
/* @0x31b3c0 mov r0, r2 */
/* @0x31b3c4 str r12, [sp, #0xc] */
/* @0x31b3c8 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b3cc lsr r3, r7, #16 */
/* @0x31b3d0 ldr r12, [sp, #0xc] */
/* @0x31b3d4 orr r1, r3, r1, lsl #16 */
/* @0x31b3d8 cmp r1, r12 */
/* @0x31b3dc movhs r5, r10 */
/* @0x31b3e0 bhs 0x31b3fc <__divdi3+0x1dc> */
/* @0x31b3e4 adds r1, r1, r6 */
/* @0x31b3e8 sub r5, r10, #1 */
/* @0x31b3ec bhs 0x31b3fc <__divdi3+0x1dc> */
/* @0x31b3f0 cmp r1, r12 */
/* @0x31b3f4 sublo r5, r10, #2 */
/* @0x31b3f8 addlo r1, r1, r6 */
/* @0x31b3fc rsb r3, r12, r1 */
/* @0x31b400 mov r1, r8 */
/* @0x31b404 str r3, [sp, #0x8] */
/* @0x31b408 uxth r7, r7 */
/* @0x31b40c mov r0, r3 */
/* @0x31b410 bl 0x318c48 <__udivsi3> */
/* @0x31b414 ldr r3, [sp, #0x8] */
/* @0x31b418 mov r1, r8 */
/* @0x31b41c mov r10, r0 */
/* @0x31b420 mul r11, r11, r0 */
/* @0x31b424 mov r0, r3 */
/* @0x31b428 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b42c orr r1, r7, r1, lsl #16 */
/* @0x31b430 cmp r1, r11 */
/* @0x31b434 movhs r2, r10 */
/* @0x31b438 bhs 0x31b454 <__divdi3+0x234> */
/* @0x31b43c adds r1, r1, r6 */
/* @0x31b440 sub r2, r10, #1 */
/* @0x31b444 bhs 0x31b454 <__divdi3+0x234> */
/* @0x31b448 cmp r1, r11 */
/* @0x31b44c sublo r2, r10, #2 */
/* @0x31b450 addlo r1, r1, r6 */
/* @0x31b454 rsb r3, r11, r1 */
/* @0x31b458 orr r5, r2, r5, lsl #16 */
/* @0x31b45c lsr r8, r6, #16 */
/* @0x31b460 mov r0, r3 */
/* @0x31b464 str r3, [sp, #0x8] */
/* @0x31b468 uxth r10, r6 */
/* @0x31b46c mov r1, r8 */
/* @0x31b470 bl 0x318c48 <__udivsi3> */
/* @0x31b474 ldr r3, [sp, #0x8] */
/* @0x31b478 mov r1, r8 */
/* @0x31b47c mov r11, r0 */
/* @0x31b480 mul r7, r10, r0 */
/* @0x31b484 mov r0, r3 */
/* @0x31b488 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b48c lsr r3, r9, #16 */
/* @0x31b490 orr r1, r3, r1, lsl #16 */
/* @0x31b494 cmp r1, r7 */
/* @0x31b498 movhs r2, r11 */
/* @0x31b49c bhs 0x31b4b8 <__divdi3+0x298> */
/* @0x31b4a0 adds r1, r1, r6 */
/* @0x31b4a4 sub r2, r11, #1 */
/* @0x31b4a8 bhs 0x31b4b8 <__divdi3+0x298> */
/* @0x31b4ac cmp r1, r7 */
/* @0x31b4b0 sublo r2, r11, #2 */
/* @0x31b4b4 addlo r1, r1, r6 */
/* @0x31b4b8 rsb r11, r7, r1 */
/* @0x31b4bc mov r1, r8 */
/* @0x31b4c0 str r2, [sp, #0x4] */
/* @0x31b4c4 uxth r9, r9 */
/* @0x31b4c8 mov r0, r11 */
/* @0x31b4cc bl 0x318c48 <__udivsi3> */
/* @0x31b4d0 mov r1, r8 */
/* @0x31b4d4 mov r7, r0 */
/* @0x31b4d8 mul r10, r10, r0 */
/* @0x31b4dc mov r0, r11 */
/* @0x31b4e0 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b4e4 ldr r2, [sp, #0x4] */
/* @0x31b4e8 orr r1, r9, r1, lsl #16 */
/* @0x31b4ec cmp r1, r10 */
/* @0x31b4f0 movhs r12, r7 */
/* @0x31b4f4 bhs 0x31b50c <__divdi3+0x2ec> */
/* @0x31b4f8 adds r6, r1, r6 */
/* @0x31b4fc sub r12, r7, #1 */
/* @0x31b500 bhs 0x31b50c <__divdi3+0x2ec> */
/* @0x31b504 cmp r6, r10 */
/* @0x31b508 sublo r12, r7, #2 */
/* @0x31b50c orr r12, r12, r2, lsl #16 */
/* @0x31b510 b 0x31b678 <__divdi3+0x458> */
/* @0x31b514 cmp r8, r7 */
/* @0x31b518 bhi 0x31b670 <__divdi3+0x450> */
/* @0x31b51c clz r9, r8 */
/* @0x31b520 cmp r9, #0 */
/* @0x31b524 bne 0x31b548 <__divdi3+0x328> */
/* @0x31b528 cmp r7, r8 */
/* @0x31b52c cmpls r5, r12 */
/* @0x31b530 movlo r5, #0 */
/* @0x31b534 movhs r5, #1 */
/* @0x31b538 movhs r12, #1 */
/* @0x31b53c movhs r5, r9 */
/* @0x31b540 bhs 0x31b678 <__divdi3+0x458> */
/* @0x31b544 b 0x31b674 <__divdi3+0x454> */
/* @0x31b548 rsb r3, r9, #32 */
/* @0x31b54c lsl r10, r12, r9 */
/* @0x31b550 lsr r6, r12, r3 */
/* @0x31b554 lsr r2, r7, r3 */
/* @0x31b558 orr r6, r6, r8, lsl r9 */
/* @0x31b55c lsr r3, r5, r3 */
/* @0x31b560 mov r0, r2 */
/* @0x31b564 orr r7, r3, r7, lsl r9 */
/* @0x31b568 lsr r8, r6, #16 */
/* @0x31b56c str r2, [sp, #0x4] */
/* @0x31b570 uxth r11, r6 */
/* @0x31b574 mov r1, r8 */
/* @0x31b578 bl 0x318c48 <__udivsi3> */
/* @0x31b57c ldr r2, [sp, #0x4] */
/* @0x31b580 mov r1, r8 */
/* @0x31b584 mul r12, r11, r0 */
/* @0x31b588 mov r3, r0 */
/* @0x31b58c mov r0, r2 */
/* @0x31b590 str r3, [sp, #0x8] */
/* @0x31b594 str r12, [sp, #0xc] */
/* @0x31b598 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b59c lsr r2, r7, #16 */
/* @0x31b5a0 ldr r12, [sp, #0xc] */
/* @0x31b5a4 ldr r3, [sp, #0x8] */
/* @0x31b5a8 orr r1, r2, r1, lsl #16 */
/* @0x31b5ac cmp r1, r12 */
/* @0x31b5b0 movhs r2, r3 */
/* @0x31b5b4 bhs 0x31b5d0 <__divdi3+0x3b0> */
/* @0x31b5b8 adds r1, r1, r6 */
/* @0x31b5bc sub r2, r3, #1 */
/* @0x31b5c0 bhs 0x31b5d0 <__divdi3+0x3b0> */
/* @0x31b5c4 cmp r1, r12 */
/* @0x31b5c8 sublo r2, r3, #2 */
/* @0x31b5cc addlo r1, r1, r6 */
/* @0x31b5d0 rsb r12, r12, r1 */
/* @0x31b5d4 mov r1, r8 */
/* @0x31b5d8 str r2, [sp, #0x4] */
/* @0x31b5dc uxth r7, r7 */
/* @0x31b5e0 mov r0, r12 */
/* @0x31b5e4 str r12, [sp, #0xc] */
/* @0x31b5e8 bl 0x318c48 <__udivsi3> */
/* @0x31b5ec ldr r12, [sp, #0xc] */
/* @0x31b5f0 mov r1, r8 */
/* @0x31b5f4 mov r3, r0 */
/* @0x31b5f8 str r3, [sp, #0x8] */
/* @0x31b5fc mul r11, r11, r0 */
/* @0x31b600 mov r0, r12 */
/* @0x31b604 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x31b608 ldmib sp, {r2, r3} */
/* @0x31b60c orr r1, r7, r1, lsl #16 */
/* @0x31b610 cmp r1, r11 */
/* @0x31b614 movhs r12, r3 */
/* @0x31b618 bhs 0x31b634 <__divdi3+0x414> */
/* @0x31b61c adds r1, r1, r6 */
/* @0x31b620 sub r12, r3, #1 */
/* @0x31b624 bhs 0x31b634 <__divdi3+0x414> */
/* @0x31b628 cmp r1, r11 */
/* @0x31b62c sublo r12, r3, #2 */
/* @0x31b630 addlo r1, r1, r6 */
/* @0x31b634 orr r12, r12, r2, lsl #16 */
/* @0x31b638 rsb r11, r11, r1 */
/* @0x31b63c umull r2, r3, r12, r10 */
/* @0x31b640 cmp r3, r11 */
/* @0x31b644 bhi 0x31b664 <__divdi3+0x444> */
/* @0x31b648 movne r3, #0 */
/* @0x31b64c moveq r3, #1 */
/* @0x31b650 cmp r2, r5, lsl r9 */
/* @0x31b654 movls r5, #0 */
/* @0x31b658 andhi r5, r3, #1 */
/* @0x31b65c cmp r5, #0 */
/* @0x31b660 beq 0x31b678 <__divdi3+0x458> */
/* @0x31b664 sub r12, r12, #1 */
/* @0x31b668 mov r5, #0 */
/* @0x31b66c b 0x31b678 <__divdi3+0x458> */
/* @0x31b670 mov r5, #0 */
/* @0x31b674 mov r12, r5 */
/* @0x31b678 cmp r4, #0 */
/* @0x31b67c mov r0, r12 */
/* @0x31b680 mov r1, r5 */
/* @0x31b684 beq 0x31b690 <__divdi3+0x470> */
/* @0x31b688 rsbs r0, r0, #0 */
/* @0x31b68c rsc r1, r1, #0 */
/* @0x31b690 add sp, sp, #20 */
/* @0x31b694 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
