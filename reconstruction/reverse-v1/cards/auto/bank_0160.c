/* libyoyo.so 覆盖卡组 0160
 * 函数 0x1dbe98..0x1dc960，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1dbe98 · EncodeScore(char const*&, char const*, int) · size=432 · insn=108 */
/* @0x1dbe98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dbe9c sub sp, sp, #6144 */
/* @0x1dbea0 ldr r4, [pc, #0x198] */
/* @0x1dbea4 sub sp, sp, #12 */
/* @0x1dbea8 add r12, sp, #8192 */
/* @0x1dbeac add r10, sp, #8 */
/* @0x1dbeb0 ldr r4, [pc, r4] */
/* @0x1dbeb4 mov r5, r0 */
/* @0x1dbeb8 mov r11, r1 */
/* @0x1dbebc mov r6, r2 */
/* @0x1dbec0 ldr r3, [r4] */
/* @0x1dbec4 movw r2, #0x401 */
/* @0x1dbec8 mov r0, sp */
/* @0x1dbecc mov r1, #0 */
/* @0x1dbed0 sub r7, r10, #8 */
/* @0x1dbed4 mov r9, sp */
/* @0x1dbed8 str r3, [r12, #-0x7fc] */
/* @0x1dbedc bl 0xb65b0 <memset@plt> */
/* @0x1dbee0 add r2, r10, #56 */
/* @0x1dbee4 asr r12, r6, #31 */
/* @0x1dbee8 cmp r6, #0 */
/* @0x1dbeec add r3, r6, #255 */
/* @0x1dbef0 lsr r12, r12, #24 */
/* @0x1dbef4 movge r3, r6 */
/* @0x1dbef8 add lr, r6, r12 */
/* @0x1dbefc asr r6, r3, #8 */
/* @0x1dbf00 uxtb lr, lr */
/* @0x1dbf04 rsb r12, r12, lr */
/* @0x1dbf08 str r12, [r9, #0x4]! */
/* @0x1dbf0c cmp r9, r2 */
/* @0x1dbf10 bne 0x1dbee4 <_Z11EncodeScoreRPKcS0_i+0x4c> */
/* @0x1dbf14 cmp r11, #0 */
/* @0x1dbf18 moveq r8, #16 */
/* @0x1dbf1c beq 0x1dbf50 <_Z11EncodeScoreRPKcS0_i+0xb8> */
/* @0x1dbf20 mov r0, r11 */
/* @0x1dbf24 bl 0xb6538 <strlen@plt> */
/* @0x1dbf28 cmp r0, #0 */
/* @0x1dbf2c subgt r2, r11, #1 */
/* @0x1dbf30 addgt r3, r10, #56 */
/* @0x1dbf34 addgt r12, r9, r0, lsl #2 */
/* @0x1dbf38 ble 0x1dbf4c <_Z11EncodeScoreRPKcS0_i+0xb4> */
/* @0x1dbf3c ldrb r1, [r2, #0x1]! */
/* @0x1dbf40 str r1, [r3, #0x4]! */
/* @0x1dbf44 cmp r3, r12 */
/* @0x1dbf48 bne 0x1dbf3c <_Z11EncodeScoreRPKcS0_i+0xa4> */
/* @0x1dbf4c add r8, r0, #16 */
/* @0x1dbf50 ldr r1, [pc, #0xec] */
/* @0x1dbf54 mov r2, r7 */
/* @0x1dbf58 mov r3, #1 */
/* @0x1dbf5c movw r0, #0x401 */
/* @0x1dbf60 ldr r1, [pc, r1] */
/* @0x1dbf64 ldr r1, [r1] */
/* @0x1dbf68 ldr lr, [r2, #0x4] */
/* @0x1dbf6c add lr, r3, lr */
/* @0x1dbf70 add r3, r3, #1 */
/* @0x1dbf74 add lr, lr, r1 */
/* @0x1dbf78 cmp r3, r0 */
/* @0x1dbf7c asr r12, lr, #31 */
/* @0x1dbf80 lsr r12, r12, #24 */
/* @0x1dbf84 add lr, lr, r12 */
/* @0x1dbf88 uxtb lr, lr */
/* @0x1dbf8c rsb r12, r12, lr */
/* @0x1dbf90 str r12, [r2, #0x4]! */
/* @0x1dbf94 bne 0x1dbf68 <_Z11EncodeScoreRPKcS0_i+0xd0> */
/* @0x1dbf98 add r6, sp, #4096 */
/* @0x1dbf9c mov r1, #0 */
/* @0x1dbfa0 add r6, r6, #8 */
/* @0x1dbfa4 str r1, [r5] */
/* @0x1dbfa8 sub r6, r6, #4 */
/* @0x1dbfac mov r2, #2048 */
/* @0x1dbfb0 mov r0, r6 */
/* @0x1dbfb4 bl 0xb65b0 <memset@plt> */
/* @0x1dbfb8 cmp r8, #0 */
/* @0x1dbfbc addgt lr, r7, r8, lsl #2 */
/* @0x1dbfc0 movgt r1, r7 */
/* @0x1dbfc4 movgt r2, r6 */
/* @0x1dbfc8 ble 0x1dc010 <_Z11EncodeScoreRPKcS0_i+0x178> */
/* @0x1dbfcc ldr r3, [r1, #0x4]! */
/* @0x1dbfd0 add r2, r2, #2 */
/* @0x1dbfd4 cmp r3, #0 */
/* @0x1dbfd8 add r0, r3, #15 */
/* @0x1dbfdc asr r12, r3, #31 */
/* @0x1dbfe0 movge r0, r3 */
/* @0x1dbfe4 cmp r1, lr */
/* @0x1dbfe8 lsr r12, r12, #28 */
/* @0x1dbfec asr r0, r0, #4 */
/* @0x1dbff0 add r3, r3, r12 */
/* @0x1dbff4 add r0, r0, #65 */
/* @0x1dbff8 and r3, r3, #15 */
/* @0x1dbffc strb r0, [r2, #-0x2] */
/* @0x1dc000 rsb r12, r12, r3 */
/* @0x1dc004 add r12, r12, #65 */
/* @0x1dc008 strb r12, [r2, #-0x1] */
/* @0x1dc00c bne 0x1dbfcc <_Z11EncodeScoreRPKcS0_i+0x134> */
/* @0x1dc010 mov r0, r6 */
/* @0x1dc014 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1dc018 add r2, sp, #8192 */
/* @0x1dc01c ldr r3, [r2, #-0x7fc] */
/* @0x1dc020 str r0, [r5] */
/* @0x1dc024 ldr r2, [r4] */
/* @0x1dc028 cmp r3, r2 */
/* @0x1dc02c bne 0x1dc03c <_Z11EncodeScoreRPKcS0_i+0x1a4> */
/* @0x1dc030 add sp, sp, #6144 */
/* @0x1dc034 add sp, sp, #12 */
/* @0x1dc038 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dc03c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dc040 eoreq r1, r1, r0, lsr #21 */
/* @0x1dc044 .word 0x00214bb4 */

/* ── FUNC 0x1dc048 · DecodeScore(char const*, char const*&, int&) · size=396 · insn=99 */
/* @0x1dc048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dc04c sub sp, sp, #3088 */
/* @0x1dc050 ldr r6, [pc, #0x174] */
/* @0x1dc054 sub sp, sp, #4 */
/* @0x1dc058 add r8, sp, #16 */
/* @0x1dc05c mov r5, r0 */
/* @0x1dc060 ldr r6, [pc, r6] */
/* @0x1dc064 sub r7, r8, #8 */
/* @0x1dc068 mov r9, r1 */
/* @0x1dc06c str r2, [sp, #0x4] */
/* @0x1dc070 ldr r3, [r6] */
/* @0x1dc074 mov r0, r7 */
/* @0x1dc078 mov r1, #0 */
/* @0x1dc07c movw r2, #0x101 */
/* @0x1dc080 mov r11, r7 */
/* @0x1dc084 mov r4, r5 */
/* @0x1dc088 mov r10, #1 */
/* @0x1dc08c str r3, [sp, #0xc0c] */
/* @0x1dc090 bl 0xb65b0 <memset@plt> */
/* @0x1dc094 b 0x1dc0b4 <_Z11DecodeScorePKcRS0_Ri+0x6c> */
/* @0x1dc098 ldrb r2, [r4, #-0x2] */
/* @0x1dc09c add r10, r10, #1 */
/* @0x1dc0a0 ldrb r3, [r4, #-0x1] */
/* @0x1dc0a4 add r3, r3, r2, lsl #4 */
/* @0x1dc0a8 sub r3, r3, #1104 */
/* @0x1dc0ac sub r3, r3, #1 */
/* @0x1dc0b0 str r3, [r11, #0x4]! */
/* @0x1dc0b4 mov r0, r5 */
/* @0x1dc0b8 add r4, r4, #2 */
/* @0x1dc0bc bl 0xb6538 <strlen@plt> */
/* @0x1dc0c0 add r0, r0, r0, lsr #31 */
/* @0x1dc0c4 cmp r10, r0, asr #1 */
/* @0x1dc0c8 ble 0x1dc098 <_Z11DecodeScorePKcRS0_Ri+0x50> */
/* @0x1dc0cc ldr r2, [pc, #0xfc] */
/* @0x1dc0d0 sub r1, r8, #4 */
/* @0x1dc0d4 mov r3, #1 */
/* @0x1dc0d8 movw lr, #0x101 */
/* @0x1dc0dc ldr r2, [pc, r2] */
/* @0x1dc0e0 ldr r12, [r2] */
/* @0x1dc0e4 ldr r0, [r1], #4 */
/* @0x1dc0e8 rsb r0, r3, r0 */
/* @0x1dc0ec add r3, r3, #1 */
/* @0x1dc0f0 rsb r0, r12, r0 */
/* @0x1dc0f4 asr r2, r0, #31 */
/* @0x1dc0f8 lsr r2, r2, #24 */
/* @0x1dc0fc add r0, r0, r2 */
/* @0x1dc100 uxtb r0, r0 */
/* @0x1dc104 subs r2, r0, r2 */
/* @0x1dc108 addmi r2, r2, #256 */
/* @0x1dc10c cmp r3, lr */
/* @0x1dc110 str r2, [r1, #-0x4] */
/* @0x1dc114 bne 0x1dc0e4 <_Z11DecodeScorePKcRS0_Ri+0x9c> */
/* @0x1dc118 add r0, r7, #64 */
/* @0x1dc11c mov r2, #0 */
/* @0x1dc120 mov r3, #1 */
/* @0x1dc124 ldr r1, [r7, #0x4]! */
/* @0x1dc128 cmp r7, r0 */
/* @0x1dc12c mla r2, r3, r1, r2 */
/* @0x1dc130 lsl r3, r3, #8 */
/* @0x1dc134 bne 0x1dc124 <_Z11DecodeScorePKcRS0_Ri+0xdc> */
/* @0x1dc138 ldr r0, [r9] */
/* @0x1dc13c ldr r3, [sp, #0x4] */
/* @0x1dc140 cmp r0, #0 */
/* @0x1dc144 str r2, [r3] */
/* @0x1dc148 beq 0x1dc158 <_Z11DecodeScorePKcRS0_Ri+0x110> */
/* @0x1dc14c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dc150 mov r3, #0 */
/* @0x1dc154 str r3, [r9] */
/* @0x1dc158 add r7, sp, #1040 */
/* @0x1dc15c mov r1, #0 */
/* @0x1dc160 sub r10, r7, #4 */
/* @0x1dc164 mov r2, #2048 */
/* @0x1dc168 add r8, r8, #56 */
/* @0x1dc16c sub r7, r7, #5 */
/* @0x1dc170 mov r0, r10 */
/* @0x1dc174 mov r4, #17 */
/* @0x1dc178 bl 0xb65b0 <memset@plt> */
/* @0x1dc17c b 0x1dc18c <_Z11DecodeScorePKcRS0_Ri+0x144> */
/* @0x1dc180 ldr r3, [r8, #0x4]! */
/* @0x1dc184 add r4, r4, #1 */
/* @0x1dc188 strb r3, [r7, #0x1]! */
/* @0x1dc18c mov r0, r5 */
/* @0x1dc190 bl 0xb6538 <strlen@plt> */
/* @0x1dc194 add r0, r0, r0, lsr #31 */
/* @0x1dc198 cmp r4, r0, asr #1 */
/* @0x1dc19c ble 0x1dc180 <_Z11DecodeScorePKcRS0_Ri+0x138> */
/* @0x1dc1a0 mov r0, r10 */
/* @0x1dc1a4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1dc1a8 ldr r3, [sp, #0xc0c] */
/* @0x1dc1ac str r0, [r9] */
/* @0x1dc1b0 ldr r2, [r6] */
/* @0x1dc1b4 cmp r3, r2 */
/* @0x1dc1b8 bne 0x1dc1c8 <_Z11DecodeScorePKcRS0_Ri+0x180> */
/* @0x1dc1bc add sp, sp, #3088 */
/* @0x1dc1c0 add sp, sp, #4 */
/* @0x1dc1c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dc1c8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dc1cc .word 0x002118f0 */
/* @0x1dc1d0 eoreq r4, r1, r8, lsr r10 */

/* ── FUNC 0x1dc1d4 · GetAll(int, char const*&, int&) · size=40 · insn=10 */
/* @0x1dc1d4 ldr r3, [pc, #0x1c] */
/* @0x1dc1d8 sub r0, r0, #1 */
/* @0x1dc1dc ldr r3, [pc, r3] */
/* @0x1dc1e0 add r12, r3, r0, lsl #3 */
/* @0x1dc1e4 ldr r0, [r3, r0, lsl #3] */
/* @0x1dc1e8 ldr r3, [r12, #0x4] */
/* @0x1dc1ec str r0, [r1] */
/* @0x1dc1f0 str r3, [r2] */
/* @0x1dc1f4 bx lr */
/* @0x1dc1f8 .word 0x00214ab0 */

/* ── FUNC 0x1dc1fc · GetName(char const*&, int) · size=44 · insn=11 */
/* @0x1dc1fc str lr, [sp, #-0x4]! */
/* @0x1dc200 sub sp, sp, #12 */
/* @0x1dc204 add r2, sp, #8 */
/* @0x1dc208 mov r12, r0 */
/* @0x1dc20c mov r3, #0 */
/* @0x1dc210 mov r0, r1 */
/* @0x1dc214 str r3, [r2, #-0x4]! */
/* @0x1dc218 mov r1, r12 */
/* @0x1dc21c bl 0x1dc1d4 <_Z6GetAlliRPKcRi> */
/* @0x1dc220 add sp, sp, #12 */
/* @0x1dc224 ldr pc, [sp], #4 */

/* ── FUNC 0x1dc228 · GetScore(int) · size=44 · insn=11 */
/* @0x1dc228 str lr, [sp, #-0x4]! */
/* @0x1dc22c sub sp, sp, #12 */
/* @0x1dc230 add r1, sp, #8 */
/* @0x1dc234 mov r3, #0 */
/* @0x1dc238 mov r2, sp */
/* @0x1dc23c str r3, [sp] */
/* @0x1dc240 str r3, [r1, #-0x4]! */
/* @0x1dc244 bl 0x1dc1d4 <_Z6GetAlliRPKcRi> */
/* @0x1dc248 ldr r0, [sp] */
/* @0x1dc24c add sp, sp, #12 */
/* @0x1dc250 ldr pc, [sp], #4 */

/* ── FUNC 0x1dc254 · SetAll(int, char const*, int) · size=128 · insn=32 */
/* @0x1dc254 push {r4, r5, r6, r7, lr} */
/* @0x1dc258 sub r6, r0, #1 */
/* @0x1dc25c ldr r4, [pc, #0x68] */
/* @0x1dc260 mov r3, #0 */
/* @0x1dc264 sub sp, sp, #12 */
/* @0x1dc268 mov r5, r1 */
/* @0x1dc26c ldr r4, [pc, r4] */
/* @0x1dc270 mov r7, r2 */
/* @0x1dc274 strb r3, [sp, #0x4] */
/* @0x1dc278 ldr r0, [r4, r6, lsl #3] */
/* @0x1dc27c cmp r0, r3 */
/* @0x1dc280 beq 0x1dc288 <_Z6SetAlliPKci+0x34> */
/* @0x1dc284 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dc288 cmp r5, #0 */
/* @0x1dc28c addeq r5, sp, #4 */
/* @0x1dc290 mov r0, r5 */
/* @0x1dc294 bl 0xb6538 <strlen@plt> */
/* @0x1dc298 ldr r1, [pc, #0x30] */
/* @0x1dc29c mov r3, #1 */
/* @0x1dc2a0 mov r2, #284 */
/* @0x1dc2a4 add r1, pc, r1 */
/* @0x1dc2a8 add r0, r0, r3 */
/* @0x1dc2ac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dc2b0 mov r1, r5 */
/* @0x1dc2b4 str r0, [r4, r6, lsl #3] */
/* @0x1dc2b8 add r4, r4, r6, lsl #3 */
/* @0x1dc2bc bl 0xb65a4 <strcpy@plt> */
/* @0x1dc2c0 str r7, [r4, #0x4] */
/* @0x1dc2c4 add sp, sp, #12 */
/* @0x1dc2c8 pop {r4, r5, r6, r7, pc} */
/* @0x1dc2cc eoreq r4, r1, r0, lsr #20 */
/* @0x1dc2d0 andseq r5, r7, r0, asr r3 */

/* ── FUNC 0x1dc2d4 · HighScore_Show(int) · size=4 · insn=1 */
/* @0x1dc2d4 bx lr */

/* ── FUNC 0x1dc2d8 · HighScore_Clear() · size=56 · insn=14 */
/* @0x1dc2d8 push {r3, r4, r5, lr} */
/* @0x1dc2dc mov r4, #1 */
/* @0x1dc2e0 ldr r5, [pc, #0x24] */
/* @0x1dc2e4 ldr r5, [pc, r5] */
/* @0x1dc2e8 ldr r3, [r5] */
/* @0x1dc2ec mov r0, r4 */
/* @0x1dc2f0 mov r2, #0 */
/* @0x1dc2f4 add r4, r4, #1 */
/* @0x1dc2f8 ldr r1, [r3] */
/* @0x1dc2fc bl 0x1dc254 <_Z6SetAlliPKci> */
/* @0x1dc300 cmp r4, #11 */
/* @0x1dc304 bne 0x1dc2e8 <_Z15HighScore_Clearv+0x10> */
/* @0x1dc308 pop {r3, r4, r5, pc} */
/* @0x1dc30c eoreq r2, r1, r8, ror #18 */

/* ── FUNC 0x1dc310 · HighScore_Value(int) · size=4 · insn=1 */
/* @0x1dc310 b 0x1dc228 <_Z8GetScorei> */

/* ── FUNC 0x1dc314 · HighScore_Name(char const*&, int) · size=4 · insn=1 */
/* @0x1dc314 b 0x1dc1fc <_Z7GetNameRPKci> */

/* ── FUNC 0x1dc318 · HighScore_Add(char const*, int) · size=160 · insn=40 */
/* @0x1dc318 push {r4, r5, r6, lr} */
/* @0x1dc31c mov r4, #0 */
/* @0x1dc320 ldr r5, [pc, #0x84] */
/* @0x1dc324 ldr r5, [pc, r5] */
/* @0x1dc328 lsl r2, r4, #3 */
/* @0x1dc32c add r3, r5, r2 */
/* @0x1dc330 ldr r3, [r3, #0x4] */
/* @0x1dc334 cmp r3, r1 */
/* @0x1dc338 blt 0x1dc34c <_Z13HighScore_AddPKci+0x34> */
/* @0x1dc33c add r4, r4, #1 */
/* @0x1dc340 cmp r4, #10 */
/* @0x1dc344 bne 0x1dc328 <_Z13HighScore_AddPKci+0x10> */
/* @0x1dc348 pop {r4, r5, r6, pc} */
/* @0x1dc34c ldr r3, [pc, #0x5c] */
/* @0x1dc350 cmp r4, #9 */
/* @0x1dc354 subne r6, r5, #72 */
/* @0x1dc358 ldr r3, [pc, r3] */
/* @0x1dc35c addne r6, r6, r2 */
/* @0x1dc360 str r4, [r3] */
/* @0x1dc364 movne r3, r5 */
/* @0x1dc368 beq 0x1dc388 <_Z13HighScore_AddPKci+0x70> */
/* @0x1dc36c ldr lr, [r3, #0x44] */
/* @0x1dc370 sub r3, r3, #8 */
/* @0x1dc374 ldr r12, [r3, #0x48] */
/* @0x1dc378 str lr, [r3, #0x54] */
/* @0x1dc37c str r12, [r3, #0x50] */
/* @0x1dc380 cmp r3, r6 */
/* @0x1dc384 bne 0x1dc36c <_Z13HighScore_AddPKci+0x54> */
/* @0x1dc388 add r2, r5, r2 */
/* @0x1dc38c str r1, [r2, #0x4] */
/* @0x1dc390 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1dc394 ldr r3, [pc, #0x18] */
/* @0x1dc398 mov r2, #1 */
/* @0x1dc39c ldr r3, [pc, r3] */
/* @0x1dc3a0 strb r2, [r3] */
/* @0x1dc3a4 str r0, [r5, r4, lsl #3] */
/* @0x1dc3a8 pop {r4, r5, r6, pc} */
/* @0x1dc3ac eoreq r4, r1, r8, ror #18 */
/* @0x1dc3b0 eoreq r4, r1, r8, lsr r9 */
/* @0x1dc3b4 .word 0x002148f8 */

/* ── FUNC 0x1dc3b8 · INITIALIZE_Score() · size=4 · insn=1 */
/* @0x1dc3b8 b 0x1dc2d8 <_Z15HighScore_Clearv> */

/* ── FUNC 0x1dc3bc · FINALIZE_Score() · size=580 · insn=145 */
/* @0x1dc3bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dc3c0 sub sp, sp, #1056 */
/* @0x1dc3c4 ldr r5, [pc, #0x21c] */
/* @0x1dc3c8 sub sp, sp, #12 */
/* @0x1dc3cc ldr r2, [pc, #0x218] */
/* @0x1dc3d0 add r5, pc, r5 */
/* @0x1dc3d4 ldr r3, [pc, #0x214] */
/* @0x1dc3d8 ldr r2, [r5, r2] */
/* @0x1dc3dc str r2, [sp] */
/* @0x1dc3e0 ldr r2, [r2] */
/* @0x1dc3e4 str r2, [sp, #0x424] */
/* @0x1dc3e8 ldr r3, [r5, r3] */
/* @0x1dc3ec str r3, [sp, #0x4] */
/* @0x1dc3f0 ldrb r3, [r3] */
/* @0x1dc3f4 cmp r3, #0 */
/* @0x1dc3f8 bne 0x1dc41c <_Z14FINALIZE_Scorev+0x60> */
/* @0x1dc3fc ldr r1, [sp] */
/* @0x1dc400 ldr r2, [sp, #0x424] */
/* @0x1dc404 ldr r3, [r1] */
/* @0x1dc408 cmp r2, r3 */
/* @0x1dc40c bne 0x1dc5e4 <_Z14FINALIZE_Scorev+0x228> */
/* @0x1dc410 add sp, sp, #1056 */
/* @0x1dc414 add sp, sp, #12 */
/* @0x1dc418 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dc41c ldr r3, [pc, #0x1d0] */
/* @0x1dc420 add r4, sp, #36 */
/* @0x1dc424 mov r1, #1024 */
/* @0x1dc428 add r11, sp, #40 */
/* @0x1dc42c mov r0, r4 */
/* @0x1dc430 ldr r3, [r5, r3] */
/* @0x1dc434 ldr r2, [r3] */
/* @0x1dc438 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1dc43c mov r0, r4 */
/* @0x1dc440 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc> */
/* @0x1dc444 ldr r1, [pc, #0x1ac] */
/* @0x1dc448 mov r0, r4 */
/* @0x1dc44c add r1, pc, r1 */
/* @0x1dc450 bl 0xb6844 <fopen@plt> */
/* @0x1dc454 subs r4, r0, #0 */
/* @0x1dc458 beq 0x1dc5a4 <_Z14FINALIZE_Scorev+0x1e8> */
/* @0x1dc45c add r0, sp, #1056 */
/* @0x1dc460 mov r1, #4 */
/* @0x1dc464 add r0, r0, #8 */
/* @0x1dc468 mov r2, #1 */
/* @0x1dc46c movw r3, #0x4948 */
/* @0x1dc470 movt r3, #0x4353 */
/* @0x1dc474 str r3, [r0, #-0x410]! */
/* @0x1dc478 mov r3, r4 */
/* @0x1dc47c sub r11, r11, #12 */
/* @0x1dc480 str r11, [sp, #0x8] */
/* @0x1dc484 bl 0xb68bc <fwrite@plt> */
/* @0x1dc488 mov r0, r4 */
/* @0x1dc48c bl 0xb68e0 <ftell@plt> */
/* @0x1dc490 mov r3, r4 */
/* @0x1dc494 mov r1, #4 */
/* @0x1dc498 mov r2, #1 */
/* @0x1dc49c mov r12, #0 */
/* @0x1dc4a0 str r12, [sp, #0x1c] */
/* @0x1dc4a4 add r9, sp, #32 */
/* @0x1dc4a8 add r7, sp, #23 */
/* @0x1dc4ac mvn r6, #15 */
/* @0x1dc4b0 str r0, [sp, #0xc] */
/* @0x1dc4b4 add r0, sp, #28 */
/* @0x1dc4b8 bl 0xb68bc <fwrite@plt> */
/* @0x1dc4bc ldr r3, [pc, #0x138] */
/* @0x1dc4c0 ldr r10, [r5, r3] */
/* @0x1dc4c4 add r8, r10, #4 */
/* @0x1dc4c8 add r10, r10, #84 */
/* @0x1dc4cc ldr r12, [r8, #-0x4] */
/* @0x1dc4d0 cmp r12, #0 */
/* @0x1dc4d4 beq 0x1dc5b4 <_Z14FINALIZE_Scorev+0x1f8> */
/* @0x1dc4d8 mov r0, r12 */
/* @0x1dc4dc bl 0xb6538 <strlen@plt> */
/* @0x1dc4e0 mov r1, #1 */
/* @0x1dc4e4 mov r2, #4 */
/* @0x1dc4e8 mov r3, r4 */
/* @0x1dc4ec str r0, [sp, #0x20] */
/* @0x1dc4f0 mov r0, r9 */
/* @0x1dc4f4 bl 0xb68bc <fwrite@plt> */
/* @0x1dc4f8 mov r3, r4 */
/* @0x1dc4fc ldr r0, [r8, #-0x4] */
/* @0x1dc500 mov r1, #1 */
/* @0x1dc504 ldr r2, [sp, #0x20] */
/* @0x1dc508 bl 0xb68bc <fwrite@plt> */
/* @0x1dc50c ldr r3, [sp, #0x20] */
/* @0x1dc510 add r11, r3, #3 */
/* @0x1dc514 bic r11, r11, #3 */
/* @0x1dc518 rsb r11, r3, r11 */
/* @0x1dc51c cmp r11, #0 */
/* @0x1dc520 movgt r5, #0 */
/* @0x1dc524 ble 0x1dc54c <_Z14FINALIZE_Scorev+0x190> */
/* @0x1dc528 mov r1, #1 */
/* @0x1dc52c mov r0, r7 */
/* @0x1dc530 add r5, r5, r1 */
/* @0x1dc534 mov r2, r1 */
/* @0x1dc538 mov r3, r4 */
/* @0x1dc53c strb r6, [sp, #0x17] */
/* @0x1dc540 bl 0xb68bc <fwrite@plt> */
/* @0x1dc544 cmp r5, r11 */
/* @0x1dc548 bne 0x1dc528 <_Z14FINALIZE_Scorev+0x16c> */
/* @0x1dc54c mov r0, r8 */
/* @0x1dc550 mov r1, #4 */
/* @0x1dc554 mov r2, #1 */
/* @0x1dc558 mov r3, r4 */
/* @0x1dc55c bl 0xb68bc <fwrite@plt> */
/* @0x1dc560 add r8, r8, #8 */
/* @0x1dc564 cmp r8, r10 */
/* @0x1dc568 bne 0x1dc4cc <_Z14FINALIZE_Scorev+0x110> */
/* @0x1dc56c mov r0, r4 */
/* @0x1dc570 bl 0xb68e0 <ftell@plt> */
/* @0x1dc574 ldr r1, [sp, #0xc] */
/* @0x1dc578 mov r2, #0 */
/* @0x1dc57c str r0, [sp, #0x1c] */
/* @0x1dc580 mov r0, r4 */
/* @0x1dc584 bl 0xb68d4 <fseek@plt> */
/* @0x1dc588 add r0, sp, #28 */
/* @0x1dc58c mov r1, #4 */
/* @0x1dc590 mov r2, #1 */
/* @0x1dc594 mov r3, r4 */
/* @0x1dc598 bl 0xb68bc <fwrite@plt> */
/* @0x1dc59c mov r0, r4 */
/* @0x1dc5a0 bl 0xb6850 <fclose@plt> */
/* @0x1dc5a4 ldr r1, [sp, #0x4] */
/* @0x1dc5a8 mov r3, #0 */
/* @0x1dc5ac strb r3, [r1] */
/* @0x1dc5b0 b 0x1dc3fc <_Z14FINALIZE_Scorev+0x40> */
/* @0x1dc5b4 mov r3, r4 */
/* @0x1dc5b8 mov r0, r9 */
/* @0x1dc5bc mov r1, #4 */
/* @0x1dc5c0 mov r2, #1 */
/* @0x1dc5c4 str r12, [sp, #0x20] */
/* @0x1dc5c8 bl 0xb68bc <fwrite@plt> */
/* @0x1dc5cc mov r0, r9 */
/* @0x1dc5d0 mov r1, #4 */
/* @0x1dc5d4 mov r2, #1 */
/* @0x1dc5d8 mov r3, r4 */
/* @0x1dc5dc bl 0xb68bc <fwrite@plt> */
/* @0x1dc5e0 b 0x1dc560 <_Z14FINALIZE_Scorev+0x1a4> */
/* @0x1dc5e4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dc5e8 eoreq r5, r1, r0, lsl #17 */
/* @0x1dc5ec .word 0xffffbd00 */
/* @0x1dc5f0 .word 0xfffff044 */
/* @0x1dc5f4 .word 0xfffff048 */
/* @0x1dc5f8 ldrsheq r3, [r6], -r8 */
/* @0x1dc5fc .word 0xfffff03c */

/* ── FUNC 0x1dc600 · HighScore_InitLoad() · size=348 · insn=87 */
/* @0x1dc600 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dc604 sub sp, sp, #1024 */
/* @0x1dc608 ldr r11, [pc, #0x134] */
/* @0x1dc60c sub sp, sp, #12 */
/* @0x1dc610 ldr r2, [pc, #0x130] */
/* @0x1dc614 add r5, sp, #4 */
/* @0x1dc618 add r11, pc, r11 */
/* @0x1dc61c ldr r3, [pc, #0x128] */
/* @0x1dc620 mov r1, #1024 */
/* @0x1dc624 mov r0, r5 */
/* @0x1dc628 ldr r7, [r11, r2] */
/* @0x1dc62c add r4, sp, #8 */
/* @0x1dc630 mov r9, #0 */
/* @0x1dc634 ldr r2, [r7] */
/* @0x1dc638 str r2, [sp, #0x404] */
/* @0x1dc63c ldr r3, [r11, r3] */
/* @0x1dc640 ldr r2, [r3] */
/* @0x1dc644 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1dc648 mov r0, r5 */
/* @0x1dc64c sub r1, r4, #8 */
/* @0x1dc650 str r9, [sp] */
/* @0x1dc654 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0x1dc658 cmp r0, #0 */
/* @0x1dc65c beq 0x1dc674 <_Z18HighScore_InitLoadv+0x74> */
/* @0x1dc660 ldr r2, [r0] */
/* @0x1dc664 movw r3, #0x4948 */
/* @0x1dc668 movt r3, #0x4353 */
/* @0x1dc66c cmp r2, r3 */
/* @0x1dc670 beq 0x1dc6a0 <_Z18HighScore_InitLoadv+0xa0> */
/* @0x1dc674 ldr r3, [pc, #0xd4] */
/* @0x1dc678 mov r2, #0 */
/* @0x1dc67c ldr r0, [sp, #0x404] */
/* @0x1dc680 ldr r1, [r7] */
/* @0x1dc684 ldr r3, [r11, r3] */
/* @0x1dc688 cmp r0, r1 */
/* @0x1dc68c strb r2, [r3] */
/* @0x1dc690 bne 0x1dc740 <_Z18HighScore_InitLoadv+0x140> */
/* @0x1dc694 add sp, sp, #1024 */
/* @0x1dc698 add sp, sp, #12 */
/* @0x1dc69c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dc6a0 ldr r2, [r0, #0x4] */
/* @0x1dc6a4 ldr r3, [sp] */
/* @0x1dc6a8 cmp r2, r3 */
/* @0x1dc6ac bgt 0x1dc674 <_Z18HighScore_InitLoadv+0x74> */
/* @0x1dc6b0 ldr r3, [pc, #0x9c] */
/* @0x1dc6b4 add r5, r0, #8 */
/* @0x1dc6b8 ldr r10, [pc, #0x98] */
/* @0x1dc6bc ldr r8, [r11, r3] */
/* @0x1dc6c0 add r10, pc, r10 */
/* @0x1dc6c4 add r4, r8, #8 */
/* @0x1dc6c8 add r8, r8, #88 */
/* @0x1dc6cc b 0x1dc6e4 <_Z18HighScore_InitLoadv+0xe4> */
/* @0x1dc6d0 ldr r3, [r5], #4 */
/* @0x1dc6d4 add r4, r4, #8 */
/* @0x1dc6d8 str r3, [r4, #-0xc] */
/* @0x1dc6dc cmp r4, r8 */
/* @0x1dc6e0 beq 0x1dc674 <_Z18HighScore_InitLoadv+0x74> */
/* @0x1dc6e4 ldr r0, [r4, #-0x8] */
/* @0x1dc6e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1dc6ec ldr r6, [r5], #4 */
/* @0x1dc6f0 cmp r6, #256 */
/* @0x1dc6f4 bgt 0x1dc674 <_Z18HighScore_InitLoadv+0x74> */
/* @0x1dc6f8 cmp r6, #0 */
/* @0x1dc6fc streq r6, [r4, #-0x8] */
/* @0x1dc700 beq 0x1dc6d0 <_Z18HighScore_InitLoadv+0xd0> */
/* @0x1dc704 mov r3, #1 */
/* @0x1dc708 mov r1, r10 */
/* @0x1dc70c movw r2, #0x24e */
/* @0x1dc710 add r0, r6, #1 */
/* @0x1dc714 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1dc718 mov r1, r5 */
/* @0x1dc71c mov r2, r6 */
/* @0x1dc720 str r0, [r4, #-0x8] */
/* @0x1dc724 bl 0xb65bc <memcpy@plt> */
/* @0x1dc728 ldr r3, [r4, #-0x8] */
/* @0x1dc72c add r2, r6, #3 */
/* @0x1dc730 bic r2, r2, #3 */
/* @0x1dc734 add r5, r5, r2 */
/* @0x1dc738 strb r9, [r3, r6] */
/* @0x1dc73c b 0x1dc6d0 <_Z18HighScore_InitLoadv+0xd0> */
/* @0x1dc740 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dc744 eoreq r5, r1, r8, lsr r6 */
/* @0x1dc748 .word 0xffffbd00 */
/* @0x1dc74c .word 0xfffff048 */
/* @0x1dc750 .word 0xfffff044 */
/* @0x1dc754 .word 0xfffff03c */
/* @0x1dc758 andseq r4, r7, r4, lsr pc */

/* ── FUNC 0x1dc75c · HandleJoystick() · size=4 · insn=1 */
/* @0x1dc75c bx lr */

/* ── FUNC 0x1dc760 · Run_Score::ShowM() · size=4 · insn=1 */
/* @0x1dc760 bx lr */

/* ── FUNC 0x1dc764 · Run_Score::KeyPressM(void*, unsigned int) · size=4 · insn=1 */
/* @0x1dc764 bx lr */

/* ── FUNC 0x1dc768 · RenderPause() · size=4 · insn=1 */
/* @0x1dc768 bx lr */

/* ── FUNC 0x1dc76c · AdaptWindow() · size=4 · insn=1 */
/* @0x1dc76c bx lr */

/* ── FUNC 0x1dc770 · StopShow() · size=4 · insn=1 */
/* @0x1dc770 bx lr */

/* ── FUNC 0x1dc774 · Splash_Show_Movie(char const*, bool) · size=8 · insn=2 */
/* @0x1dc774 mov r0, #1 */
/* @0x1dc778 bx lr */

/* ── FUNC 0x1dc77c · Splash_Show_Image(char const*, int) · size=8 · insn=2 */
/* @0x1dc77c mov r0, #1 */
/* @0x1dc780 bx lr */

/* ── FUNC 0x1dc784 · Splash_Show_Text(char const*, int) · size=8 · insn=2 */
/* @0x1dc784 mov r0, #1 */
/* @0x1dc788 bx lr */

/* ── FUNC 0x1dc78c · Splash_Is_Shown_In_Main() · size=20 · insn=5 */
/* @0x1dc78c ldr r3, [pc, #0x8] */
/* @0x1dc790 ldr r3, [pc, r3] */
/* @0x1dc794 ldrb r0, [r3] */
/* @0x1dc798 bx lr */
/* @0x1dc79c eoreq r4, r1, r12, lsl #10 */

/* ── FUNC 0x1dc7a0 · Splash_Close_In_Main(short) · size=4 · insn=1 */
/* @0x1dc7a0 bx lr */

/* ── FUNC 0x1dc7a4 · Code_Patch_Instruction(unsigned char*, int, void*) · size=40 · insn=10 */
/* @0x1dc7a4 ldr r0, [r0, r1] */
/* @0x1dc7a8 push {r4, lr} */
/* @0x1dc7ac tst r0, #1073741824 */
/* @0x1dc7b0 add r4, r1, #4 */
/* @0x1dc7b4 beq 0x1dc7c4 <_Z22Code_Patch_InstructionPhiPv+0x20> */
/* @0x1dc7b8 ubfx r0, r0, #0x10, #0x8 */
/* @0x1dc7bc bl 0xec108 <_Z9ParamSizei> */
/* @0x1dc7c0 add r4, r4, r0 */
/* @0x1dc7c4 mov r0, r4 */
/* @0x1dc7c8 pop {r4, pc} */

/* ── FUNC 0x1dc7cc · Code_Patch(unsigned char*, void*, int) · size=52 · insn=13 */
/* @0x1dc7cc push {r4, r5, r6, lr} */
/* @0x1dc7d0 subs r6, r2, #0 */
/* @0x1dc7d4 mov r4, r0 */
/* @0x1dc7d8 mov r5, r1 */
/* @0x1dc7dc pople {r4, r5, r6, pc} */
/* @0x1dc7e0 mov r1, #0 */
/* @0x1dc7e4 mov r0, r4 */
/* @0x1dc7e8 mov r2, r5 */
/* @0x1dc7ec bl 0x1dc7a4 <_Z22Code_Patch_InstructionPhiPv> */
/* @0x1dc7f0 cmp r6, r0 */
/* @0x1dc7f4 mov r1, r0 */
/* @0x1dc7f8 bgt 0x1dc7e4 <_Z10Code_PatchPhPvi+0x18> */
/* @0x1dc7fc pop {r4, r5, r6, pc} */

/* ── FUNC 0x1dc800 · Code_Load(unsigned char*, unsigned int, unsigned char*) · size=48 · insn=12 */
/* @0x1dc800 mov r1, r0 */
/* @0x1dc804 ldr r2, [pc, #0x1c] */
/* @0x1dc808 ldr r3, [pc, #0x1c] */
/* @0x1dc80c mov r0, #1 */
/* @0x1dc810 ldr r12, [r1], #4 */
/* @0x1dc814 ldr r2, [pc, r2] */
/* @0x1dc818 ldr r3, [pc, r3] */
/* @0x1dc81c str r1, [r2] */
/* @0x1dc820 str r12, [r3] */
/* @0x1dc824 bx lr */
/* @0x1dc828 eoreq r1, r1, r4, lsr r3 */
/* @0x1dc82c eoreq r1, r1, r12, lsr #6 */

/* ── FUNC 0x1dc830 · RewriteOldCodeInstruction(unsigned char*, int, void*) · size=96 · insn=24 */
/* @0x1dc830 ldr r2, [r0, r1] */
/* @0x1dc834 push {r3, r4, r5, lr} */
/* @0x1dc838 bic r4, r2, #520093696 */
/* @0x1dc83c ldr r3, [pc, #0x48] */
/* @0x1dc840 lsr r12, r2, #24 */
/* @0x1dc844 and r5, r12, #31 */
/* @0x1dc848 ldr r3, [pc, r3] */
/* @0x1dc84c ldrb r3, [r5, r3] */
/* @0x1dc850 cmp r3, #21 */
/* @0x1dc854 subeq r5, r12, #16 */
/* @0x1dc858 orr r3, r4, r3, lsl #24 */
/* @0x1dc85c biceq r4, r3, #65280 */
/* @0x1dc860 moveq r3, r5 */
/* @0x1dc864 orreq r3, r4, r3, lsl #8 */
/* @0x1dc868 tst r12, #64 */
/* @0x1dc86c str r3, [r0, r1] */
/* @0x1dc870 add r4, r1, #4 */
/* @0x1dc874 beq 0x1dc884 <_Z25RewriteOldCodeInstructionPhiPv+0x54> */
/* @0x1dc878 ubfx r0, r2, #0x10, #0x8 */
/* @0x1dc87c bl 0xec108 <_Z9ParamSizei> */
/* @0x1dc880 add r4, r4, r0 */
/* @0x1dc884 mov r0, r4 */
/* @0x1dc888 pop {r3, r4, r5, pc} */
/* @0x1dc88c eoreq r4, r1, r8, asr r4 */

/* ── FUNC 0x1dc890 · RewriteOldCode(unsigned char*, void*, int) · size=52 · insn=13 */
/* @0x1dc890 push {r4, r5, r6, lr} */
/* @0x1dc894 subs r6, r2, #0 */
/* @0x1dc898 mov r4, r0 */
/* @0x1dc89c mov r5, r1 */
/* @0x1dc8a0 pople {r4, r5, r6, pc} */
/* @0x1dc8a4 mov r1, #0 */
/* @0x1dc8a8 mov r0, r4 */
/* @0x1dc8ac mov r2, r5 */
/* @0x1dc8b0 bl 0x1dc830 <_Z25RewriteOldCodeInstructionPhiPv> */
/* @0x1dc8b4 cmp r6, r0 */
/* @0x1dc8b8 mov r1, r0 */
/* @0x1dc8bc bgt 0x1dc8a8 <_Z14RewriteOldCodePhPvi+0x18> */
/* @0x1dc8c0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1dc8c4 · Code_Patch(unsigned char*, unsigned int, unsigned char*) · size=156 · insn=39 */
/* @0x1dc8c4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1dc8c8 mov r5, r2 */
/* @0x1dc8cc ldr r10, [r0] */
/* @0x1dc8d0 cmp r10, #0 */
/* @0x1dc8d4 beq 0x1dc954 <_Z10Code_PatchPhjS_+0x90> */
/* @0x1dc8d8 ldr r9, [pc, #0x7c] */
/* @0x1dc8dc mov r8, r0 */
/* @0x1dc8e0 mov r4, #0 */
/* @0x1dc8e4 ldr r9, [pc, r9] */
/* @0x1dc8e8 b 0x1dc924 <_Z10Code_PatchPhjS_+0x60> */
/* @0x1dc8ec ldr r2, [r3, #0x10] */
/* @0x1dc8f0 ldr r7, [r3, #0x4] */
/* @0x1dc8f4 cmp r2, #0 */
/* @0x1dc8f8 bne 0x1dc918 <_Z10Code_PatchPhjS_+0x54> */
/* @0x1dc8fc add r6, r3, #12 */
/* @0x1dc900 ldr r3, [r3, #0xc] */
/* @0x1dc904 add r6, r6, r3 */
/* @0x1dc908 mov r0, r6 */
/* @0x1dc90c mov r2, r7 */
/* @0x1dc910 mov r1, r5 */
/* @0x1dc914 bl 0x1dc7cc <_Z10Code_PatchPhPvi> */
/* @0x1dc918 add r4, r4, #1 */
/* @0x1dc91c cmp r4, r10 */
/* @0x1dc920 beq 0x1dc954 <_Z10Code_PatchPhjS_+0x90> */
/* @0x1dc924 ldrb r2, [r9] */
/* @0x1dc928 mov r1, r5 */
/* @0x1dc92c ldr r3, [r8, #0x4]! */
/* @0x1dc930 cmp r2, #0 */
/* @0x1dc934 add r3, r5, r3 */
/* @0x1dc938 add r6, r3, #8 */
/* @0x1dc93c bne 0x1dc8ec <_Z10Code_PatchPhjS_+0x28> */
/* @0x1dc940 ldr r7, [r3, #0x4] */
/* @0x1dc944 mov r0, r6 */
/* @0x1dc948 mov r2, r7 */
/* @0x1dc94c bl 0x1dc890 <_Z14RewriteOldCodePhPvi> */
/* @0x1dc950 b 0x1dc908 <_Z10Code_PatchPhjS_+0x44> */
/* @0x1dc954 mov r0, #1 */
/* @0x1dc958 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1dc95c eoreq r1, r1, r0, ror r2 */

/* ── FUNC 0x1dc960 · OLD_VARI_Load(unsigned char*, unsigned int, unsigned char*) · size=300 · insn=75 */
/* @0x1dc960 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1dc964 sub sp, sp, #1024 */
/* @0x1dc968 ldr r8, [pc, #0x10c] */
/* @0x1dc96c sub sp, sp, #12 */
/* @0x1dc970 ldr r9, [pc, #0x108] */
/* @0x1dc974 subs r10, r1, #0 */
/* @0x1dc978 ldr r8, [pc, r8] */
/* @0x1dc97c add r7, sp, #4 */
/* @0x1dc980 add r9, pc, r9 */
/* @0x1dc984 mov r6, r0 */
/* @0x1dc988 ldr r3, [r8] */
/* @0x1dc98c mov r5, r2 */
/* @0x1dc990 str r3, [sp, #0x404] */
/* @0x1dc994 beq 0x1dca14 <_Z13OLD_VARI_LoadPhjS_+0xb4> */
/* @0x1dc998 ldr r0, [r6] */
/* @0x1dc99c cmp r0, #0 */
/* @0x1dc9a0 moveq r11, r0 */
/* @0x1dc9a4 ldrne r3, [pc, #0xd8] */
/* @0x1dc9a8 ldrne r3, [pc, r3] */
/* @0x1dc9ac ldrne r11, [r3] */
/* @0x1dc9b0 addne r11, r11, r0 */
/* @0x1dc9b4 mov r0, r11 */
/* @0x1dc9b8 bl 0xd1d60 <_Z18Code_Variable_FindPKc> */
/* @0x1dc9bc subs r4, r0, #0 */
/* @0x1dc9c0 blt 0x1dca34 <_Z13OLD_VARI_LoadPhjS_+0xd4> */
/* @0x1dc9c4 ldr r11, [r6, #0x4] */
/* @0x1dc9c8 sub r10, r10, #12 */
/* @0x1dc9cc ldr r3, [r6, #0x8] */
/* @0x1dc9d0 add r6, r6, #12 */
/* @0x1dc9d4 cmp r11, #0 */
/* @0x1dc9d8 bicgt r0, r4, #-268435456 */
/* @0x1dc9dc movgt r12, #0 */
/* @0x1dc9e0 ble 0x1dca0c <_Z13OLD_VARI_LoadPhjS_+0xac> */
/* @0x1dc9e4 add r4, r3, #4 */
/* @0x1dc9e8 add r12, r12, #1 */
/* @0x1dc9ec cmp r12, r11 */
/* @0x1dc9f0 ldr r2, [r5, r4] */
/* @0x1dc9f4 and r1, r2, #-268435456 */
/* @0x1dc9f8 sbfx r2, r2, #0x0, #0x1d */
/* @0x1dc9fc orr r1, r1, r0 */
/* @0x1dca00 add r3, r3, r2 */
/* @0x1dca04 str r1, [r5, r4] */
/* @0x1dca08 bne 0x1dc9e4 <_Z13OLD_VARI_LoadPhjS_+0x84> */
/* @0x1dca0c cmp r10, #0 */
/* @0x1dca10 bne 0x1dc998 <_Z13OLD_VARI_LoadPhjS_+0x38> */
/* @0x1dca14 ldr r2, [sp, #0x404] */
/* @0x1dca18 mov r0, #1 */
/* @0x1dca1c ldr r3, [r8] */
/* @0x1dca20 cmp r2, r3 */
/* @0x1dca24 bne 0x1dca70 <_Z13OLD_VARI_LoadPhjS_+0x110> */
/* @0x1dca28 add sp, sp, #1024 */
/* @0x1dca2c add sp, sp, #12 */
/* @0x1dca30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1dca34 mov r3, r11 */
/* @0x1dca38 mov r1, #1024 */
/* @0x1dca3c mov r2, r9 */
/* @0x1dca40 mov r0, r7 */
/* @0x1dca44 bl 0xb65c8 <snprintf@plt> */
/* @0x1dca48 mov r0, r7 */
/* @0x1dca4c mov r1, #1 */
/* @0x1dca50 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1dca54 ldr r3, [pc, #0x2c] */
/* @0x1dca58 ldr r3, [pc, r3] */
/* @0x1dca5c ldrb r3, [r3] */
/* @0x1dca60 cmp r3, #0 */
/* @0x1dca64 beq 0x1dca74 <_Z13OLD_VARI_LoadPhjS_+0x114> */
/* @0x1dca68 bl 0x10c320 <_Z14YYGML_game_endv> */
/* @0x1dca6c b 0x1dc9c4 <_Z13OLD_VARI_LoadPhjS_+0x64> */
/* @0x1dca70 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1dca74 mov r0, #1 */
/* @0x1dca78 bl 0xb6688 <exit@plt> */
/* @0x1dca7c .word 0x00210fd8 */
/* @0x1dca80 andseq r4, r7, r4, lsl sp */
/* @0x1dca84 mlaeq r1, r12, pc, r0 */
/* @0x1dca88 .word 0x002111d8 */
