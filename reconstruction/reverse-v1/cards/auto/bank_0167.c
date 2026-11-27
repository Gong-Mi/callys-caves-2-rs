/* libyoyo.so 覆盖卡组 0167
 * 函数 0x1ef03c..0x1f25b4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1ef03c · Sprite_Data(int) · size=64 · insn=16 */
/* @0x1ef03c cmp r0, #0 */
/* @0x1ef040 blt 0x1ef06c <_Z11Sprite_Datai+0x30> */
/* @0x1ef044 ldr r3, [pc, #0x28] */
/* @0x1ef048 ldr r3, [pc, r3] */
/* @0x1ef04c ldr r3, [r3] */
/* @0x1ef050 cmp r0, r3 */
/* @0x1ef054 bge 0x1ef06c <_Z11Sprite_Datai+0x30> */
/* @0x1ef058 ldr r3, [pc, #0x18] */
/* @0x1ef05c ldr r3, [pc, r3] */
/* @0x1ef060 ldr r3, [r3, #0x4] */
/* @0x1ef064 ldr r0, [r3, r0, lsl #2] */
/* @0x1ef068 bx lr */
/* @0x1ef06c mov r0, #0 */
/* @0x1ef070 bx lr */
/* @0x1ef074 eoreq r1, r0, r8, asr #27 */
/* @0x1ef078 eoreq r1, r0, r12, lsr #27 */

/* ── FUNC 0x1ef07c · Sprite_Replace_Alpha(int, char const*, int, bool, bool, int, int) · size=368 · insn=92 */
/* @0x1ef07c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ef080 sub sp, sp, #1056 */
/* @0x1ef084 ldr r4, [pc, #0x14c] */
/* @0x1ef088 sub sp, sp, #12 */
/* @0x1ef08c ldr r12, [pc, #0x148] */
/* @0x1ef090 subs r6, r0, #0 */
/* @0x1ef094 add r4, pc, r4 */
/* @0x1ef098 mov r7, r1 */
/* @0x1ef09c mov r8, r2 */
/* @0x1ef0a0 mov r9, r3 */
/* @0x1ef0a4 ldr r5, [r4, r12] */
/* @0x1ef0a8 ldrb r10, [sp, #0x450] */
/* @0x1ef0ac ldr r12, [r5] */
/* @0x1ef0b0 str r12, [sp, #0x424] */
/* @0x1ef0b4 blt 0x1ef0cc <_Z20Sprite_Replace_AlphaiPKcibbii+0x50> */
/* @0x1ef0b8 ldr r3, [pc, #0x120] */
/* @0x1ef0bc ldr r3, [r4, r3] */
/* @0x1ef0c0 ldr r3, [r3] */
/* @0x1ef0c4 cmp r6, r3 */
/* @0x1ef0c8 blt 0x1ef0ec <_Z20Sprite_Replace_AlphaiPKcibbii+0x70> */
/* @0x1ef0cc mov r0, #0 */
/* @0x1ef0d0 ldr r2, [sp, #0x424] */
/* @0x1ef0d4 ldr r3, [r5] */
/* @0x1ef0d8 cmp r2, r3 */
/* @0x1ef0dc bne 0x1ef1d4 <_Z20Sprite_Replace_AlphaiPKcibbii+0x158> */
/* @0x1ef0e0 add sp, sp, #1056 */
/* @0x1ef0e4 add sp, sp, #12 */
/* @0x1ef0e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ef0ec mov r0, r1 */
/* @0x1ef0f0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1ef0f4 cmp r0, #0 */
/* @0x1ef0f8 bne 0x1ef194 <_Z20Sprite_Replace_AlphaiPKcibbii+0x118> */
/* @0x1ef0fc mov r0, r7 */
/* @0x1ef100 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1ef104 cmp r0, #0 */
/* @0x1ef108 beq 0x1ef0cc <_Z20Sprite_Replace_AlphaiPKcibbii+0x50> */
/* @0x1ef10c add r11, sp, #36 */
/* @0x1ef110 mov r2, r7 */
/* @0x1ef114 mov r1, #1024 */
/* @0x1ef118 mov r0, r11 */
/* @0x1ef11c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1ef120 ldr r3, [pc, #0xbc] */
/* @0x1ef124 ldr r7, [r4, r3] */
/* @0x1ef128 ldr r3, [r7, #0x4] */
/* @0x1ef12c ldr r0, [r3, r6, lsl #2] */
/* @0x1ef130 cmp r0, #0 */
/* @0x1ef134 beq 0x1ef1ac <_Z20Sprite_Replace_AlphaiPKcibbii+0x130> */
/* @0x1ef138 ldr r3, [sp, #0x454] */
/* @0x1ef13c mov r12, #1 */
/* @0x1ef140 mov r2, r8 */
/* @0x1ef144 mov lr, #0 */
/* @0x1ef148 str r10, [sp, #0x8] */
/* @0x1ef14c mov r1, r11 */
/* @0x1ef150 str r3, [sp, #0xc] */
/* @0x1ef154 ldr r3, [sp, #0x458] */
/* @0x1ef158 str r12, [sp] */
/* @0x1ef15c str r12, [sp, #0x14] */
/* @0x1ef160 str r3, [sp, #0x10] */
/* @0x1ef164 mov r3, r9 */
/* @0x1ef168 str lr, [sp, #0x4] */
/* @0x1ef16c bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib> */
/* @0x1ef170 ldr r3, [r7, #0x4] */
/* @0x1ef174 ldr r2, [pc, #0x6c] */
/* @0x1ef178 ldr r3, [r3, r6, lsl #2] */
/* @0x1ef17c str r6, [r3, #0x60] */
/* @0x1ef180 ldr r2, [r4, r2] */
/* @0x1ef184 ldr r2, [r2] */
/* @0x1ef188 ldr r2, [r2, r6, lsl #2] */
/* @0x1ef18c str r2, [r3, #0x5c] */
/* @0x1ef190 b 0x1ef0d0 <_Z20Sprite_Replace_AlphaiPKcibbii+0x54> */
/* @0x1ef194 add r11, sp, #36 */
/* @0x1ef198 mov r2, r7 */
/* @0x1ef19c mov r1, #1024 */
/* @0x1ef1a0 mov r0, r11 */
/* @0x1ef1a4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1ef1a8 b 0x1ef120 <_Z20Sprite_Replace_AlphaiPKcibbii+0xa4> */
/* @0x1ef1ac mov r0, #136 */
/* @0x1ef1b0 bl 0x27c524 <_Znwj> */
/* @0x1ef1b4 str r0, [sp, #0x1c] */
/* @0x1ef1b8 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1ef1bc ldr r3, [sp, #0x1c] */
/* @0x1ef1c0 ldr r2, [r7, #0x4] */
/* @0x1ef1c4 str r3, [r2, r6, lsl #2] */
/* @0x1ef1c8 ldr r3, [r7, #0x4] */
/* @0x1ef1cc ldr r0, [r3, r6, lsl #2] */
/* @0x1ef1d0 b 0x1ef138 <_Z20Sprite_Replace_AlphaiPKcibbii+0xbc> */
/* @0x1ef1d4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1ef1d8 .word 0x00202bbc */
/* @0x1ef1dc .word 0xffffbd00 */
/* @0x1ef1e0 .word 0xfffff1c0 */
/* @0x1ef1e4 .word 0xfffff1b8 */
/* @0x1ef1e8 .word 0xfffff1bc */

/* ── FUNC 0x1ef1ec · Sprite_Delete(int) · size=616 · insn=154 */
/* @0x1ef1ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ef1f0 cmp r0, #0 */
/* @0x1ef1f4 sub sp, sp, #20 */
/* @0x1ef1f8 ldr r5, [pc, #0x240] */
/* @0x1ef1fc str r0, [sp] */
/* @0x1ef200 add r5, pc, r5 */
/* @0x1ef204 blt 0x1ef360 <_Z13Sprite_Deletei+0x174> */
/* @0x1ef208 ldr r3, [pc, #0x234] */
/* @0x1ef20c ldr r3, [r5, r3] */
/* @0x1ef210 ldr r3, [r3] */
/* @0x1ef214 cmp r0, r3 */
/* @0x1ef218 bge 0x1ef360 <_Z13Sprite_Deletei+0x174> */
/* @0x1ef21c ldr r3, [pc, #0x224] */
/* @0x1ef220 lsl r6, r0, #2 */
/* @0x1ef224 ldr r4, [r5, r3] */
/* @0x1ef228 ldr r3, [r4, #0x4] */
/* @0x1ef22c ldr r0, [r3, r0, lsl #2] */
/* @0x1ef230 cmp r0, #0 */
/* @0x1ef234 beq 0x1ef364 <_Z13Sprite_Deletei+0x178> */
/* @0x1ef238 bl 0x1e6b4c <_ZN7CSprite5ClearEv> */
/* @0x1ef23c ldr r3, [r4, #0x4] */
/* @0x1ef240 ldr r1, [sp] */
/* @0x1ef244 add r2, r3, r6 */
/* @0x1ef248 ldr r0, [r3, r1, lsl #2] */
/* @0x1ef24c cmp r0, #0 */
/* @0x1ef250 beq 0x1ef268 <_Z13Sprite_Deletei+0x7c> */
/* @0x1ef254 ldr r3, [r0] */
/* @0x1ef258 ldr r3, [r3, #0x4] */
/* @0x1ef25c blx r3 */
/* @0x1ef260 ldr r2, [r4, #0x4] */
/* @0x1ef264 add r2, r2, r6 */
/* @0x1ef268 ldr r3, [pc, #0x1dc] */
/* @0x1ef26c mov r4, #0 */
/* @0x1ef270 str r4, [r2] */
/* @0x1ef274 ldr r2, [sp] */
/* @0x1ef278 ldr r3, [r5, r3] */
/* @0x1ef27c str r3, [sp, #0xc] */
/* @0x1ef280 ldr r3, [r3] */
/* @0x1ef284 ldr r0, [r3, r2, lsl #2] */
/* @0x1ef288 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1ef28c ldr r3, [pc, #0x1bc] */
/* @0x1ef290 ldr r3, [r5, r3] */
/* @0x1ef294 ldr r2, [r3, #0x8] */
/* @0x1ef298 ldr r12, [r3, #0x10] */
/* @0x1ef29c str r3, [sp, #0x8] */
/* @0x1ef2a0 bic r0, r0, #-2147483648 */
/* @0x1ef2a4 and r3, r0, r2 */
/* @0x1ef2a8 lsl r1, r3, #1 */
/* @0x1ef2ac add lr, r1, r3 */
/* @0x1ef2b0 add lr, r12, lr, lsl #2 */
/* @0x1ef2b4 ldr lr, [lr, #0x8] */
/* @0x1ef2b8 cmp lr, r4 */
/* @0x1ef2bc beq 0x1ef32c <_Z13Sprite_Deletei+0x140> */
/* @0x1ef2c0 cmp r0, lr */
/* @0x1ef2c4 beq 0x1ef374 <_Z13Sprite_Deletei+0x188> */
/* @0x1ef2c8 ldr r1, [sp, #0x8] */
/* @0x1ef2cc and lr, r2, lr */
/* @0x1ef2d0 ldr r7, [r1] */
/* @0x1ef2d4 add r1, r3, r7 */
/* @0x1ef2d8 rsb lr, lr, r1 */
/* @0x1ef2dc tst lr, r2 */
/* @0x1ef2e0 bpl 0x1ef2f8 <_Z13Sprite_Deletei+0x10c> */
/* @0x1ef2e4 b 0x1ef32c <_Z13Sprite_Deletei+0x140> */
/* @0x1ef2e8 cmp r0, lr */
/* @0x1ef2ec beq 0x1ef36c <_Z13Sprite_Deletei+0x180> */
/* @0x1ef2f0 cmp r5, r4 */
/* @0x1ef2f4 blt 0x1ef32c <_Z13Sprite_Deletei+0x140> */
/* @0x1ef2f8 add r3, r3, #1 */
/* @0x1ef2fc add r4, r4, #1 */
/* @0x1ef300 and r3, r3, r2 */
/* @0x1ef304 add r6, r3, r7 */
/* @0x1ef308 lsl r1, r3, #1 */
/* @0x1ef30c add lr, r1, r3 */
/* @0x1ef310 add lr, r12, lr, lsl #2 */
/* @0x1ef314 ldr lr, [lr, #0x8] */
/* @0x1ef318 and r5, r2, lr */
/* @0x1ef31c cmp lr, #0 */
/* @0x1ef320 rsb r5, r5, r6 */
/* @0x1ef324 and r5, r5, r2 */
/* @0x1ef328 bne 0x1ef2e8 <_Z13Sprite_Deletei+0xfc> */
/* @0x1ef32c ldr r1, [sp, #0xc] */
/* @0x1ef330 ldr r2, [sp] */
/* @0x1ef334 ldr r3, [r1] */
/* @0x1ef338 ldr r0, [r3, r2, lsl #2] */
/* @0x1ef33c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ef340 ldr r7, [sp, #0xc] */
/* @0x1ef344 ldr r1, [sp] */
/* @0x1ef348 mov r2, #0 */
/* @0x1ef34c mov r0, #1 */
/* @0x1ef350 ldr r3, [r7] */
/* @0x1ef354 str r2, [r3, r1, lsl #2] */
/* @0x1ef358 add sp, sp, #20 */
/* @0x1ef35c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ef360 mov r0, #0 */
/* @0x1ef364 add sp, sp, #20 */
/* @0x1ef368 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ef36c cmn r3, #1 */
/* @0x1ef370 beq 0x1ef32c <_Z13Sprite_Deletei+0x140> */
/* @0x1ef374 add r5, r3, #1 */
/* @0x1ef378 and r5, r5, r2 */
/* @0x1ef37c add r4, r5, r5, lsl #1 */
/* @0x1ef380 add r4, r12, r4, lsl #2 */
/* @0x1ef384 ldr lr, [r4, #0x8] */
/* @0x1ef388 cmp lr, #0 */
/* @0x1ef38c beq 0x1ef438 <_Z13Sprite_Deletei+0x24c> */
/* @0x1ef390 ldr r7, [sp, #0x8] */
/* @0x1ef394 and r0, r2, lr */
/* @0x1ef398 ldr r7, [r7] */
/* @0x1ef39c add r6, r5, r7 */
/* @0x1ef3a0 rsb r0, r0, r6 */
/* @0x1ef3a4 str r7, [sp, #0x4] */
/* @0x1ef3a8 tst r0, r2 */
/* @0x1ef3ac bne 0x1ef3c0 <_Z13Sprite_Deletei+0x1d4> */
/* @0x1ef3b0 b 0x1ef438 <_Z13Sprite_Deletei+0x24c> */
/* @0x1ef3b4 tst r8, r2 */
/* @0x1ef3b8 beq 0x1ef410 <_Z13Sprite_Deletei+0x224> */
/* @0x1ef3bc mov r5, r0 */
/* @0x1ef3c0 add r0, r5, #1 */
/* @0x1ef3c4 add r7, r1, r3 */
/* @0x1ef3c8 and r0, r0, r2 */
/* @0x1ef3cc ldr r10, [r4] */
/* @0x1ef3d0 add r6, r12, r7, lsl #2 */
/* @0x1ef3d4 ldr r1, [sp, #0x4] */
/* @0x1ef3d8 add r11, r0, r0, lsl #1 */
/* @0x1ef3dc mov r3, r5 */
/* @0x1ef3e0 str lr, [r6, #0x8] */
/* @0x1ef3e4 add r8, r0, r1 */
/* @0x1ef3e8 ldr r9, [r4, #0x4] */
/* @0x1ef3ec add r4, r12, r11, lsl #2 */
/* @0x1ef3f0 str r10, [r12, r7, lsl #2] */
/* @0x1ef3f4 lsl r1, r5, #1 */
/* @0x1ef3f8 ldr lr, [r4, #0x8] */
/* @0x1ef3fc str r9, [r6, #0x4] */
/* @0x1ef400 cmp lr, #0 */
/* @0x1ef404 and r6, r2, lr */
/* @0x1ef408 rsb r8, r6, r8 */
/* @0x1ef40c bne 0x1ef3b4 <_Z13Sprite_Deletei+0x1c8> */
/* @0x1ef410 ldr r3, [sp, #0x8] */
/* @0x1ef414 add r5, r5, r5, lsl #1 */
/* @0x1ef418 ldr r7, [sp, #0x8] */
/* @0x1ef41c add r12, r12, r5, lsl #2 */
/* @0x1ef420 ldr r2, [r3, #0x4] */
/* @0x1ef424 mov r3, #0 */
/* @0x1ef428 str r3, [r12, #0x8] */
/* @0x1ef42c sub r2, r2, #1 */
/* @0x1ef430 str r2, [r7, #0x4] */
/* @0x1ef434 b 0x1ef32c <_Z13Sprite_Deletei+0x140> */
/* @0x1ef438 mov r5, r3 */
/* @0x1ef43c b 0x1ef410 <_Z13Sprite_Deletei+0x224> */
/* @0x1ef440 eoreq r2, r0, r0, asr r10 */
/* @0x1ef444 .word 0xfffff1c0 */
/* @0x1ef448 .word 0xfffff1b8 */
/* @0x1ef44c .word 0xfffff1bc */
/* @0x1ef450 .word 0xfffff1c4 */

/* ── FUNC 0x1ef454 · Sprite_Assign(int, int) · size=192 · insn=48 */
/* @0x1ef454 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ef458 subs r6, r1, #0 */
/* @0x1ef45c mov r4, r0 */
/* @0x1ef460 blt 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* @0x1ef464 ldr r3, [pc, #0x9c] */
/* @0x1ef468 ldr r3, [pc, r3] */
/* @0x1ef46c ldr r3, [r3] */
/* @0x1ef470 cmp r6, r3 */
/* @0x1ef474 bge 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* @0x1ef478 ldr r5, [pc, #0x8c] */
/* @0x1ef47c ldr r5, [pc, r5] */
/* @0x1ef480 ldr r2, [r5, #0x4] */
/* @0x1ef484 ldr r1, [r2, r6, lsl #2] */
/* @0x1ef488 cmp r1, #0 */
/* @0x1ef48c beq 0x1ef4c8 <_Z13Sprite_Assignii+0x74> */
/* @0x1ef490 ldr r0, [r2, r4, lsl #2] */
/* @0x1ef494 cmp r0, #0 */
/* @0x1ef498 beq 0x1ef4e0 <_Z13Sprite_Assignii+0x8c> */
/* @0x1ef49c bl 0x1e76e8 <_ZN7CSprite6AssignEPS_> */
/* @0x1ef4a0 ldr r3, [pc, #0x68] */
/* @0x1ef4a4 ldr r1, [r5, #0x4] */
/* @0x1ef4a8 mov r0, #1 */
/* @0x1ef4ac ldr r3, [pc, r3] */
/* @0x1ef4b0 ldr r2, [r3] */
/* @0x1ef4b4 ldr r3, [r1, r4, lsl #2] */
/* @0x1ef4b8 ldr r2, [r2, r4, lsl #2] */
/* @0x1ef4bc str r4, [r3, #0x60] */
/* @0x1ef4c0 str r2, [r3, #0x5c] */
/* @0x1ef4c4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ef4c8 cmp r0, #0 */
/* @0x1ef4cc blt 0x1ef4d8 <_Z13Sprite_Assignii+0x84> */
/* @0x1ef4d0 cmp r3, r0 */
/* @0x1ef4d4 bgt 0x1ef490 <_Z13Sprite_Assignii+0x3c> */
/* @0x1ef4d8 mov r0, #0 */
/* @0x1ef4dc pop {r3, r4, r5, r6, r7, pc} */
/* @0x1ef4e0 mov r0, #136 */
/* @0x1ef4e4 bl 0x27c524 <_Znwj> */
/* @0x1ef4e8 mov r7, r0 */
/* @0x1ef4ec bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1ef4f0 ldr r3, [r5, #0x4] */
/* @0x1ef4f4 str r7, [r3, r4, lsl #2] */
/* @0x1ef4f8 ldr r3, [r5, #0x4] */
/* @0x1ef4fc ldr r1, [r3, r6, lsl #2] */
/* @0x1ef500 ldr r0, [r3, r4, lsl #2] */
/* @0x1ef504 b 0x1ef49c <_Z13Sprite_Assignii+0x48> */
/* @0x1ef508 eoreq r1, r0, r8, lsr #19 */
/* @0x1ef50c eoreq r1, r0, r12, lsl #19 */
/* @0x1ef510 eoreq r1, r0, r0, ror #18 */

/* ── FUNC 0x1ef514 · FINALIZE_Sprite_Main() · size=148 · insn=37 */
/* @0x1ef514 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ef518 ldr r3, [pc, #0x7c] */
/* @0x1ef51c ldr r2, [pc, #0x7c] */
/* @0x1ef520 add r3, pc, r3 */
/* @0x1ef524 ldr r6, [r3, r2] */
/* @0x1ef528 ldr r2, [r6] */
/* @0x1ef52c cmp r2, #0 */
/* @0x1ef530 ldr r2, [pc, #0x6c] */
/* @0x1ef534 ble 0x1ef590 <_Z20FINALIZE_Sprite_Mainv+0x7c> */
/* @0x1ef538 ldr r5, [r3, r2] */
/* @0x1ef53c mov r4, #0 */
/* @0x1ef540 mov r7, r4 */
/* @0x1ef544 ldr r2, [r5] */
/* @0x1ef548 ldr r0, [r2, r4, lsl #2] */
/* @0x1ef54c cmp r0, #0 */
/* @0x1ef550 beq 0x1ef564 <_Z20FINALIZE_Sprite_Mainv+0x50> */
/* @0x1ef554 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ef558 ldr r3, [r5] */
/* @0x1ef55c str r7, [r3, r4, lsl #2] */
/* @0x1ef560 ldr r2, [r5] */
/* @0x1ef564 ldr r3, [r6] */
/* @0x1ef568 add r4, r4, #1 */
/* @0x1ef56c cmp r3, r4 */
/* @0x1ef570 bgt 0x1ef548 <_Z20FINALIZE_Sprite_Mainv+0x34> */
/* @0x1ef574 mov r0, r2 */
/* @0x1ef578 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ef57c mov r3, #0 */
/* @0x1ef580 str r3, [r5] */
/* @0x1ef584 bl 0x1eee30 <_Z19Sprite_FreeTexturesv> */
/* @0x1ef588 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1ef58c b 0x1eed3c <_Z11Sprite_Freev> */
/* @0x1ef590 ldr r5, [r3, r2] */
/* @0x1ef594 ldr r2, [r5] */
/* @0x1ef598 b 0x1ef574 <_Z20FINALIZE_Sprite_Mainv+0x60> */
/* @0x1ef59c eoreq r2, r0, r0, lsr r7 */
/* @0x1ef5a0 .word 0xfffff1c0 */
/* @0x1ef5a4 .word 0xfffff1bc */

/* ── FUNC 0x1ef5a8 · Sprite_Replace(int, char const*, int, bool, bool, bool, bool, int, int) · size=744 · insn=186 */
/* @0x1ef5a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ef5ac subs r5, r0, #0 */
/* @0x1ef5b0 ldr r4, [pc, #0x2ac] */
/* @0x1ef5b4 sub sp, sp, #1072 */
/* @0x1ef5b8 ldr r0, [pc, #0x2a8] */
/* @0x1ef5bc mov r8, r3 */
/* @0x1ef5c0 add r4, pc, r4 */
/* @0x1ef5c4 sub sp, sp, #4 */
/* @0x1ef5c8 mov r9, r2 */
/* @0x1ef5cc mov r6, r1 */
/* @0x1ef5d0 ldr r0, [r4, r0] */
/* @0x1ef5d4 ldrb r7, [sp, #0x458] */
/* @0x1ef5d8 ldrb r11, [sp, #0x45c] */
/* @0x1ef5dc ldr r3, [r0] */
/* @0x1ef5e0 str r0, [sp, #0x24] */
/* @0x1ef5e4 ldrb r10, [sp, #0x460] */
/* @0x1ef5e8 str r3, [sp, #0x42c] */
/* @0x1ef5ec blt 0x1ef6e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x140> */
/* @0x1ef5f0 ldr r3, [pc, #0x274] */
/* @0x1ef5f4 ldr r3, [r4, r3] */
/* @0x1ef5f8 ldr r3, [r3] */
/* @0x1ef5fc cmp r5, r3 */
/* @0x1ef600 bge 0x1ef6e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x140> */
/* @0x1ef604 ldr r0, [pc, #0x264] */
/* @0x1ef608 mov r2, #7 */
/* @0x1ef60c add r0, pc, r0 */
/* @0x1ef610 bl 0xb65e0 <strncmp@plt> */
/* @0x1ef614 cmp r0, #0 */
/* @0x1ef618 beq 0x1ef638 <_Z14Sprite_ReplaceiPKcibbbbii+0x90> */
/* @0x1ef61c ldr r0, [pc, #0x250] */
/* @0x1ef620 mov r1, r6 */
/* @0x1ef624 mov r2, #8 */
/* @0x1ef628 add r0, pc, r0 */
/* @0x1ef62c bl 0xb65e0 <strncmp@plt> */
/* @0x1ef630 cmp r0, #0 */
/* @0x1ef634 bne 0x1ef710 <_Z14Sprite_ReplaceiPKcibbbbii+0x168> */
/* @0x1ef638 ldr r3, [pc, #0x238] */
/* @0x1ef63c ldr r3, [r4, r3] */
/* @0x1ef640 ldr r2, [r3, #0x4] */
/* @0x1ef644 ldr r2, [r2, r5, lsl #2] */
/* @0x1ef648 cmp r2, #0 */
/* @0x1ef64c beq 0x1ef808 <_Z14Sprite_ReplaceiPKcibbbbii+0x260> */
/* @0x1ef650 mov r0, #20 */
/* @0x1ef654 mov r12, #0 */
/* @0x1ef658 str r12, [sp, #0x20] */
/* @0x1ef65c bl 0x27c524 <_Znwj> */
/* @0x1ef660 cmp r7, #0 */
/* @0x1ef664 ldr r1, [sp, #0x464] */
/* @0x1ef668 ldr r2, [sp, #0x468] */
/* @0x1ef66c movne r7, #2 */
/* @0x1ef670 moveq r7, #0 */
/* @0x1ef674 cmp r11, #0 */
/* @0x1ef678 ldr r3, [pc, #0x1fc] */
/* @0x1ef67c orr r8, r7, r8 */
/* @0x1ef680 mov r7, #1 */
/* @0x1ef684 movne r11, #4 */
/* @0x1ef688 moveq r11, #0 */
/* @0x1ef68c cmp r10, #0 */
/* @0x1ef690 orr r8, r8, r11 */
/* @0x1ef694 movne r10, #8 */
/* @0x1ef698 moveq r10, #0 */
/* @0x1ef69c orr r10, r8, r10 */
/* @0x1ef6a0 mov lr, r0 */
/* @0x1ef6a4 str r5, [r0] */
/* @0x1ef6a8 str r10, [r0, #0x10] */
/* @0x1ef6ac str r9, [r0, #0x4] */
/* @0x1ef6b0 mov r0, r6 */
/* @0x1ef6b4 str r1, [lr, #0x8] */
/* @0x1ef6b8 mov r1, #5 */
/* @0x1ef6bc str r2, [lr, #0xc] */
/* @0x1ef6c0 ldr r2, [pc, #0x1b8] */
/* @0x1ef6c4 ldr r5, [r4, r3] */
/* @0x1ef6c8 ldr r3, [pc, #0x1b4] */
/* @0x1ef6cc strb r7, [r5] */
/* @0x1ef6d0 ldr r2, [r4, r2] */
/* @0x1ef6d4 ldr r3, [r4, r3] */
/* @0x1ef6d8 str lr, [sp] */
/* @0x1ef6dc bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x1ef6e0 ldr r12, [sp, #0x20] */
/* @0x1ef6e4 b 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144> */
/* @0x1ef6e8 mov r12, #0 */
/* @0x1ef6ec mov r0, r12 */
/* @0x1ef6f0 ldr r12, [sp, #0x24] */
/* @0x1ef6f4 ldr r2, [sp, #0x42c] */
/* @0x1ef6f8 ldr r3, [r12] */
/* @0x1ef6fc cmp r2, r3 */
/* @0x1ef700 bne 0x1ef860 <_Z14Sprite_ReplaceiPKcibbbbii+0x2b8> */
/* @0x1ef704 add sp, sp, #1072 */
/* @0x1ef708 add sp, sp, #4 */
/* @0x1ef70c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1ef710 mov r0, r6 */
/* @0x1ef714 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1ef718 cmp r0, #0 */
/* @0x1ef71c bne 0x1ef7e8 <_Z14Sprite_ReplaceiPKcibbbbii+0x240> */
/* @0x1ef720 mov r0, r6 */
/* @0x1ef724 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1ef728 cmp r0, #0 */
/* @0x1ef72c moveq r12, r0 */
/* @0x1ef730 beq 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144> */
/* @0x1ef734 add r3, sp, #44 */
/* @0x1ef738 mov r2, r6 */
/* @0x1ef73c mov r1, #1024 */
/* @0x1ef740 str r3, [sp, #0x1c] */
/* @0x1ef744 mov r0, r3 */
/* @0x1ef748 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1ef74c ldr r3, [sp, #0x1c] */
/* @0x1ef750 ldr r2, [pc, #0x120] */
/* @0x1ef754 ldr r6, [r4, r2] */
/* @0x1ef758 ldr r2, [r6, #0x4] */
/* @0x1ef75c ldr r0, [r2, r5, lsl #2] */
/* @0x1ef760 cmp r0, #0 */
/* @0x1ef764 beq 0x1ef830 <_Z14Sprite_ReplaceiPKcibbbbii+0x288> */
/* @0x1ef768 mov r1, r3 */
/* @0x1ef76c ldr r12, [sp, #0x468] */
/* @0x1ef770 ldr r3, [sp, #0x464] */
/* @0x1ef774 mov r2, r9 */
/* @0x1ef778 str r7, [sp] */
/* @0x1ef77c eor r7, r7, #1 */
/* @0x1ef780 str r12, [sp, #0x10] */
/* @0x1ef784 str r3, [sp, #0xc] */
/* @0x1ef788 mov r3, r8 */
/* @0x1ef78c str r11, [sp, #0x4] */
/* @0x1ef790 str r7, [sp, #0x14] */
/* @0x1ef794 str r10, [sp, #0x8] */
/* @0x1ef798 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib> */
/* @0x1ef79c ldr r1, [r6, #0x4] */
/* @0x1ef7a0 ldr r3, [pc, #0xe0] */
/* @0x1ef7a4 mov r2, r5 */
/* @0x1ef7a8 ldr r1, [r1, r5, lsl #2] */
/* @0x1ef7ac str r5, [r1, #0x60] */
/* @0x1ef7b0 ldr r3, [r4, r3] */
/* @0x1ef7b4 ldr r3, [r3] */
/* @0x1ef7b8 ldr lr, [r3, r5, lsl #2] */
/* @0x1ef7bc str lr, [r1, #0x5c] */
/* @0x1ef7c0 ldr r1, [r3, r5, lsl #2] */
/* @0x1ef7c4 mov r12, r0 */
/* @0x1ef7c8 ldr r0, [pc, #0xbc] */
/* @0x1ef7cc ldr r0, [r4, r0] */
/* @0x1ef7d0 str r12, [sp, #0x20] */
/* @0x1ef7d4 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1ef7d8 mov r0, r5 */
/* @0x1ef7dc bl 0x130cac <_Z20MarkInstancesAsDirtyi> */
/* @0x1ef7e0 ldr r12, [sp, #0x20] */
/* @0x1ef7e4 b 0x1ef6ec <_Z14Sprite_ReplaceiPKcibbbbii+0x144> */
/* @0x1ef7e8 add r3, sp, #44 */
/* @0x1ef7ec mov r2, r6 */
/* @0x1ef7f0 mov r1, #1024 */
/* @0x1ef7f4 str r3, [sp, #0x1c] */
/* @0x1ef7f8 mov r0, r3 */
/* @0x1ef7fc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1ef800 ldr r3, [sp, #0x1c] */
/* @0x1ef804 b 0x1ef750 <_Z14Sprite_ReplaceiPKcibbbbii+0x1a8> */
/* @0x1ef808 mov r0, #136 */
/* @0x1ef80c str r3, [sp, #0x1c] */
/* @0x1ef810 bl 0x27c524 <_Znwj> */
/* @0x1ef814 str r0, [sp, #0x20] */
/* @0x1ef818 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1ef81c ldr r3, [sp, #0x1c] */
/* @0x1ef820 ldr r2, [sp, #0x20] */
/* @0x1ef824 ldr r3, [r3, #0x4] */
/* @0x1ef828 str r2, [r3, r5, lsl #2] */
/* @0x1ef82c b 0x1ef650 <_Z14Sprite_ReplaceiPKcibbbbii+0xa8> */
/* @0x1ef830 mov r0, #136 */
/* @0x1ef834 str r3, [sp, #0x1c] */
/* @0x1ef838 bl 0x27c524 <_Znwj> */
/* @0x1ef83c str r0, [sp, #0x20] */
/* @0x1ef840 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1ef844 ldr r2, [sp, #0x20] */
/* @0x1ef848 ldr r1, [r6, #0x4] */
/* @0x1ef84c ldr r3, [sp, #0x1c] */
/* @0x1ef850 str r2, [r1, r5, lsl #2] */
/* @0x1ef854 ldr r2, [r6, #0x4] */
/* @0x1ef858 ldr r0, [r2, r5, lsl #2] */
/* @0x1ef85c b 0x1ef768 <_Z14Sprite_ReplaceiPKcibbbbii+0x1c0> */
/* @0x1ef860 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1ef864 mlaeq r0, r0, r6, r2 */
/* @0x1ef868 .word 0xffffbd00 */
/* @0x1ef86c .word 0xfffff1c0 */
/* @0x1ef870 ldrsbeq r1, [r4], -r4 */
/* @0x1ef874 andseq r1, r4, r0, asr #9 */
/* @0x1ef878 .word 0xfffff1b8 */
/* @0x1ef87c .word 0xffffbd04 */
/* @0x1ef880 .word 0xfffff1c8 */
/* @0x1ef884 .word 0xfffff1cc */
/* @0x1ef888 .word 0xfffff1bc */
/* @0x1ef88c .word 0xfffff1c4 */

/* ── FUNC 0x1ef890 · Sprite_AddEmpty() · size=840 · insn=210 */
/* @0x1ef890 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ef894 sub sp, sp, #284 */
/* @0x1ef898 ldr r4, [pc, #0x314] */
/* @0x1ef89c movw r3, #0x3cd */
/* @0x1ef8a0 ldr r2, [pc, #0x310] */
/* @0x1ef8a4 add r4, pc, r4 */
/* @0x1ef8a8 ldr r1, [pc, #0x30c] */
/* @0x1ef8ac ldr r0, [pc, #0x30c] */
/* @0x1ef8b0 ldr r2, [r4, r2] */
/* @0x1ef8b4 ldr r5, [pc, #0x308] */
/* @0x1ef8b8 ldr r12, [r2] */
/* @0x1ef8bc add r5, pc, r5 */
/* @0x1ef8c0 str r2, [sp, #0xc] */
/* @0x1ef8c4 mov r2, r5 */
/* @0x1ef8c8 str r12, [sp, #0x114] */
/* @0x1ef8cc ldr r6, [r4, r1] */
/* @0x1ef8d0 ldr r1, [r6] */
/* @0x1ef8d4 add r1, r1, #1 */
/* @0x1ef8d8 str r1, [r6] */
/* @0x1ef8dc ldr r0, [r4, r0] */
/* @0x1ef8e0 lsl r1, r1, #2 */
/* @0x1ef8e4 str r0, [sp, #0x4] */
/* @0x1ef8e8 add r0, r0, #4 */
/* @0x1ef8ec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1ef8f0 ldr r12, [sp, #0x4] */
/* @0x1ef8f4 ldr r1, [r6] */
/* @0x1ef8f8 mov r2, r5 */
/* @0x1ef8fc ldr r0, [pc, #0x2c4] */
/* @0x1ef900 movw r3, #0x3cf */
/* @0x1ef904 add r5, sp, #20 */
/* @0x1ef908 str r1, [r12] */
/* @0x1ef90c lsl r1, r1, #2 */
/* @0x1ef910 ldr r0, [r4, r0] */
/* @0x1ef914 str r0, [sp, #0x8] */
/* @0x1ef918 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1ef91c ldr r3, [r6] */
/* @0x1ef920 mov r1, #256 */
/* @0x1ef924 ldr r2, [pc, #0x2a0] */
/* @0x1ef928 mov r0, r5 */
/* @0x1ef92c sub r3, r3, #1 */
/* @0x1ef930 add r2, pc, r2 */
/* @0x1ef934 bl 0xb65c8 <snprintf@plt> */
/* @0x1ef938 ldr r12, [sp, #0x8] */
/* @0x1ef93c mov r0, r5 */
/* @0x1ef940 ldr r8, [r6] */
/* @0x1ef944 ldr r7, [r12] */
/* @0x1ef948 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1ef94c ldr r3, [pc, #0x27c] */
/* @0x1ef950 sub r8, r8, #-1073741823 */
/* @0x1ef954 ldr r5, [r6] */
/* @0x1ef958 ldr r12, [sp, #0x8] */
/* @0x1ef95c sub r2, r5, #-1073741823 */
/* @0x1ef960 sub r5, r5, #1 */
/* @0x1ef964 str r0, [r7, r8, lsl #2] */
/* @0x1ef968 ldr r7, [r4, r3] */
/* @0x1ef96c ldr r0, [r12] */
/* @0x1ef970 ldr r3, [r7, #0x4] */
/* @0x1ef974 ldr r1, [r7, #0xc] */
/* @0x1ef978 ldr r4, [r0, r2, lsl #2] */
/* @0x1ef97c cmp r3, r1 */
/* @0x1ef980 bgt 0x1efabc <_Z15Sprite_AddEmptyv+0x22c> */
/* @0x1ef984 mov r0, r4 */
/* @0x1ef988 add r3, r3, #1 */
/* @0x1ef98c str r3, [r7, #0x4] */
/* @0x1ef990 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1ef994 ldr lr, [r7, #0x8] */
/* @0x1ef998 ldr r10, [r7, #0x10] */
/* @0x1ef99c bic r0, r0, #-2147483648 */
/* @0x1ef9a0 and r3, r0, lr */
/* @0x1ef9a4 add r2, r3, r3, lsl #1 */
/* @0x1ef9a8 add r2, r10, r2, lsl #2 */
/* @0x1ef9ac ldr r1, [r2, #0x8] */
/* @0x1ef9b0 cmp r1, #0 */
/* @0x1ef9b4 ldrne r11, [r7] */
/* @0x1ef9b8 movne r8, #0 */
/* @0x1ef9bc bne 0x1efa04 <_Z15Sprite_AddEmptyv+0x174> */
/* @0x1ef9c0 b 0x1efa50 <_Z15Sprite_AddEmptyv+0x1c0> */
/* @0x1ef9c4 ldr r9, [r2] */
/* @0x1ef9c8 ldr r8, [r2, #0x4] */
/* @0x1ef9cc str r0, [r2, #0x8] */
/* @0x1ef9d0 mov r0, r1 */
/* @0x1ef9d4 str r4, [r2] */
/* @0x1ef9d8 mov r4, r9 */
/* @0x1ef9dc str r5, [r2, #0x4] */
/* @0x1ef9e0 mov r5, r8 */
/* @0x1ef9e4 add r3, r3, #1 */
/* @0x1ef9e8 add r8, r12, #1 */
/* @0x1ef9ec and r3, r3, lr */
/* @0x1ef9f0 add r2, r3, r3, lsl #1 */
/* @0x1ef9f4 add r2, r10, r2, lsl #2 */
/* @0x1ef9f8 ldr r1, [r2, #0x8] */
/* @0x1ef9fc cmp r1, #0 */
/* @0x1efa00 beq 0x1efa50 <_Z15Sprite_AddEmptyv+0x1c0> */
/* @0x1efa04 add r12, r11, r3 */
/* @0x1efa08 and r9, r1, lr */
/* @0x1efa0c rsb r12, r9, r12 */
/* @0x1efa10 and r12, r12, lr */
/* @0x1efa14 cmp r12, r8 */
/* @0x1efa18 blt 0x1ef9c4 <_Z15Sprite_AddEmptyv+0x134> */
/* @0x1efa1c movne r12, r8 */
/* @0x1efa20 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154> */
/* @0x1efa24 cmp r1, r0 */
/* @0x1efa28 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154> */
/* @0x1efa2c ldr r8, [r2] */
/* @0x1efa30 cmp r4, r8 */
/* @0x1efa34 bne 0x1ef9e4 <_Z15Sprite_AddEmptyv+0x154> */
/* @0x1efa38 ldr r3, [r7, #0x4] */
/* @0x1efa3c str r1, [r2, #0x8] */
/* @0x1efa40 stm r2, {r4, r5} */
/* @0x1efa44 sub r3, r3, #1 */
/* @0x1efa48 str r3, [r7, #0x4] */
/* @0x1efa4c b 0x1efa58 <_Z15Sprite_AddEmptyv+0x1c8> */
/* @0x1efa50 stm r2, {r4, r5} */
/* @0x1efa54 str r0, [r2, #0x8] */
/* @0x1efa58 mov r0, #136 */
/* @0x1efa5c bl 0x27c524 <_Znwj> */
/* @0x1efa60 mov r5, r0 */
/* @0x1efa64 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1efa68 ldr r1, [r6] */
/* @0x1efa6c ldr r6, [sp, #0x4] */
/* @0x1efa70 sub r3, r1, #-1073741823 */
/* @0x1efa74 ldr r12, [sp, #0x8] */
/* @0x1efa78 ldr r4, [sp, #0x114] */
/* @0x1efa7c sub r1, r1, #1 */
/* @0x1efa80 ldr r2, [r6, #0x4] */
/* @0x1efa84 mov r0, r1 */
/* @0x1efa88 str r5, [r2, r3, lsl #2] */
/* @0x1efa8c ldr r2, [r6, #0x4] */
/* @0x1efa90 ldr r6, [sp, #0xc] */
/* @0x1efa94 ldr r5, [r12] */
/* @0x1efa98 ldr r2, [r2, r3, lsl #2] */
/* @0x1efa9c ldr r12, [r6] */
/* @0x1efaa0 ldr r3, [r5, r3, lsl #2] */
/* @0x1efaa4 cmp r4, r12 */
/* @0x1efaa8 str r1, [r2, #0x60] */
/* @0x1efaac str r3, [r2, #0x5c] */
/* @0x1efab0 bne 0x1efbac <_Z15Sprite_AddEmptyv+0x31c> */
/* @0x1efab4 add sp, sp, #284 */
/* @0x1efab8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1efabc ldr r10, [r7] */
/* @0x1efac0 mov r3, #1 */
/* @0x1efac4 ldr r1, [pc, #0x108] */
/* @0x1efac8 mov r2, #70 */
/* @0x1efacc ldr r9, [r7, #0x10] */
/* @0x1efad0 lsl r0, r10, r3 */
/* @0x1efad4 add r1, pc, r1 */
/* @0x1efad8 add r8, r0, r10, lsl #2 */
/* @0x1efadc str r0, [r7] */
/* @0x1efae0 sub r0, r0, #1 */
/* @0x1efae4 str r0, [r7, #0x8] */
/* @0x1efae8 lsl r8, r8, #2 */
/* @0x1efaec mov r0, r8 */
/* @0x1efaf0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1efaf4 mov r2, r8 */
/* @0x1efaf8 mov r1, #0 */
/* @0x1efafc str r0, [r7, #0x10] */
/* @0x1efb00 bl 0xb65b0 <memset@plt> */
/* @0x1efb04 ldr r2, [r7] */
/* @0x1efb08 vldr s15, [pc, #160] */
/* @0x1efb0c mov r1, #0 */
/* @0x1efb10 str r1, [r7, #0x4] */
/* @0x1efb14 cmp r2, r1 */
/* @0x1efb18 vmov s13, r2 */
/* @0x1efb1c vcvt.f32.s32 s14, s13 */
/* @0x1efb20 vmul.f32 s15, s14, s15 */
/* @0x1efb24 vcvt.s32.f32 s15, s15 */
/* @0x1efb28 vstr s15, [r7, #12] */
/* @0x1efb2c ble 0x1efb4c <_Z15Sprite_AddEmptyv+0x2bc> */
/* @0x1efb30 add r2, r2, r2, lsl #1 */
/* @0x1efb34 ldr r3, [r7, #0x10] */
/* @0x1efb38 add r2, r3, r2, lsl #2 */
/* @0x1efb3c str r1, [r3, #0x8] */
/* @0x1efb40 add r3, r3, #12 */
/* @0x1efb44 cmp r3, r2 */
/* @0x1efb48 bne 0x1efb3c <_Z15Sprite_AddEmptyv+0x2ac> */
/* @0x1efb4c cmp r10, #0 */
/* @0x1efb50 movgt r8, r9 */
/* @0x1efb54 movgt r11, #0 */
/* @0x1efb58 ble 0x1efb84 <_Z15Sprite_AddEmptyv+0x2f4> */
/* @0x1efb5c ldr r3, [r8, #0x8] */
/* @0x1efb60 cmp r3, #0 */
/* @0x1efb64 ble 0x1efb74 <_Z15Sprite_AddEmptyv+0x2e4> */
/* @0x1efb68 mov r0, r7 */
/* @0x1efb6c ldm r8, {r1, r2} */
/* @0x1efb70 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1efb74 add r11, r11, #1 */
/* @0x1efb78 add r8, r8, #12 */
/* @0x1efb7c cmp r11, r10 */
/* @0x1efb80 bne 0x1efb5c <_Z15Sprite_AddEmptyv+0x2cc> */
/* @0x1efb84 mov r0, r9 */
/* @0x1efb88 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1efb8c vldr s13, [r7] */
/* @0x1efb90 vcvt.f32.s32 s14, s13 */
/* @0x1efb94 vldr s15, [pc, #20] */
/* @0x1efb98 ldr r3, [r7, #0x4] */
/* @0x1efb9c vmul.f32 s15, s14, s15 */
/* @0x1efba0 vcvt.s32.f32 s15, s15 */
/* @0x1efba4 vstr s15, [r7, #12] */
/* @0x1efba8 b 0x1ef984 <_Z15Sprite_AddEmptyv+0xf4> */
/* @0x1efbac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1efbb0 svclo #0x19999a */
/* @0x1efbb4 eoreq r2, r0, r12, lsr #7 */
/* @0x1efbb8 .word 0xffffbd00 */
/* @0x1efbbc .word 0xfffff1c0 */
/* @0x1efbc0 .word 0xfffff1b8 */
/* @0x1efbc4 andseq r2, r6, r4, lsl #27 */
/* @0x1efbc8 .word 0xfffff1bc */
/* @0x1efbcc andseq r2, r6, r8, asr #26 */
/* @0x1efbd0 .word 0xfffff1c4 */
/* @0x1efbd4 andseq r1, r4, r12, asr r5 */

/* ── FUNC 0x1efbd8 · Sprite_Add_BIN(void*, int, int, int, bool, bool, int, int) · size=996 · insn=249 */
/* @0x1efbd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1efbdc sub sp, sp, #340 */
/* @0x1efbe0 ldr r4, [pc, #0x3b0] */
/* @0x1efbe4 ldr r12, [pc, #0x3b0] */
/* @0x1efbe8 add r4, pc, r4 */
/* @0x1efbec str r0, [sp, #0x30] */
/* @0x1efbf0 str r1, [sp, #0x34] */
/* @0x1efbf4 str r2, [sp, #0x38] */
/* @0x1efbf8 str r3, [sp, #0x3c] */
/* @0x1efbfc movw r3, #0x255 */
/* @0x1efc00 ldr r12, [r4, r12] */
/* @0x1efc04 ldr r1, [pc, #0x394] */
/* @0x1efc08 ldr r0, [pc, #0x394] */
/* @0x1efc0c str r12, [sp, #0x2c] */
/* @0x1efc10 ldr lr, [sp, #0x2c] */
/* @0x1efc14 ldrb r12, [sp, #0x178] */
/* @0x1efc18 ldr r5, [pc, #0x388] */
/* @0x1efc1c str r12, [sp, #0x40] */
/* @0x1efc20 add r5, pc, r5 */
/* @0x1efc24 ldr r12, [lr] */
/* @0x1efc28 ldrb lr, [sp, #0x17c] */
/* @0x1efc2c mov r2, r5 */
/* @0x1efc30 str r12, [sp, #0x14c] */
/* @0x1efc34 str lr, [sp, #0x44] */
/* @0x1efc38 ldr r6, [r4, r1] */
/* @0x1efc3c ldr r1, [r6] */
/* @0x1efc40 add r1, r1, #1 */
/* @0x1efc44 str r1, [r6] */
/* @0x1efc48 ldr r0, [r4, r0] */
/* @0x1efc4c lsl r1, r1, #2 */
/* @0x1efc50 str r0, [sp, #0x24] */
/* @0x1efc54 add r0, r0, #4 */
/* @0x1efc58 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1efc5c ldr r1, [r6] */
/* @0x1efc60 mov r2, r5 */
/* @0x1efc64 ldr r0, [pc, #0x340] */
/* @0x1efc68 ldr r5, [sp, #0x24] */
/* @0x1efc6c movw r3, #0x257 */
/* @0x1efc70 str r1, [r5] */
/* @0x1efc74 lsl r1, r1, #2 */
/* @0x1efc78 ldr r0, [r4, r0] */
/* @0x1efc7c add r5, sp, #76 */
/* @0x1efc80 str r0, [sp, #0x28] */
/* @0x1efc84 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1efc88 ldr r3, [r6] */
/* @0x1efc8c mov r1, #256 */
/* @0x1efc90 ldr r2, [pc, #0x318] */
/* @0x1efc94 mov r0, r5 */
/* @0x1efc98 sub r3, r3, #1 */
/* @0x1efc9c add r2, pc, r2 */
/* @0x1efca0 bl 0xb65c8 <snprintf@plt> */
/* @0x1efca4 ldr r12, [sp, #0x28] */
/* @0x1efca8 mov r0, r5 */
/* @0x1efcac ldr r8, [r6] */
/* @0x1efcb0 ldr r7, [r12] */
/* @0x1efcb4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1efcb8 ldr r2, [pc, #0x2f4] */
/* @0x1efcbc sub r8, r8, #-1073741823 */
/* @0x1efcc0 ldr r5, [r6] */
/* @0x1efcc4 sub r3, r5, #-1073741823 */
/* @0x1efcc8 sub r5, r5, #1 */
/* @0x1efccc str r0, [r7, r8, lsl #2] */
/* @0x1efcd0 ldr r7, [r4, r2] */
/* @0x1efcd4 ldr r4, [sp, #0x28] */
/* @0x1efcd8 ldr r2, [r7, #0x4] */
/* @0x1efcdc ldr r1, [r7, #0xc] */
/* @0x1efce0 ldr r0, [r4] */
/* @0x1efce4 cmp r2, r1 */
/* @0x1efce8 ldr r4, [r0, r3, lsl #2] */
/* @0x1efcec bgt 0x1efe8c <_Z14Sprite_Add_BINPviiibbii+0x2b4> */
/* @0x1efcf0 mov r0, r4 */
/* @0x1efcf4 add r2, r2, #1 */
/* @0x1efcf8 str r2, [r7, #0x4] */
/* @0x1efcfc bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1efd00 ldr lr, [r7, #0x8] */
/* @0x1efd04 ldr r10, [r7, #0x10] */
/* @0x1efd08 bic r0, r0, #-2147483648 */
/* @0x1efd0c and r3, r0, lr */
/* @0x1efd10 add r2, r3, r3, lsl #1 */
/* @0x1efd14 add r2, r10, r2, lsl #2 */
/* @0x1efd18 ldr r1, [r2, #0x8] */
/* @0x1efd1c cmp r1, #0 */
/* @0x1efd20 ldrne r11, [r7] */
/* @0x1efd24 movne r8, #0 */
/* @0x1efd28 bne 0x1efd70 <_Z14Sprite_Add_BINPviiibbii+0x198> */
/* @0x1efd2c b 0x1efdbc <_Z14Sprite_Add_BINPviiibbii+0x1e4> */
/* @0x1efd30 ldr r9, [r2] */
/* @0x1efd34 ldr r8, [r2, #0x4] */
/* @0x1efd38 str r0, [r2, #0x8] */
/* @0x1efd3c mov r0, r1 */
/* @0x1efd40 str r4, [r2] */
/* @0x1efd44 mov r4, r9 */
/* @0x1efd48 str r5, [r2, #0x4] */
/* @0x1efd4c mov r5, r8 */
/* @0x1efd50 add r3, r3, #1 */
/* @0x1efd54 add r8, r12, #1 */
/* @0x1efd58 and r3, r3, lr */
/* @0x1efd5c add r2, r3, r3, lsl #1 */
/* @0x1efd60 add r2, r10, r2, lsl #2 */
/* @0x1efd64 ldr r1, [r2, #0x8] */
/* @0x1efd68 cmp r1, #0 */
/* @0x1efd6c beq 0x1efdbc <_Z14Sprite_Add_BINPviiibbii+0x1e4> */
/* @0x1efd70 add r12, r11, r3 */
/* @0x1efd74 and r9, r1, lr */
/* @0x1efd78 rsb r12, r9, r12 */
/* @0x1efd7c and r12, r12, lr */
/* @0x1efd80 cmp r12, r8 */
/* @0x1efd84 blt 0x1efd30 <_Z14Sprite_Add_BINPviiibbii+0x158> */
/* @0x1efd88 movne r12, r8 */
/* @0x1efd8c bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178> */
/* @0x1efd90 cmp r1, r0 */
/* @0x1efd94 bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178> */
/* @0x1efd98 ldr r8, [r2] */
/* @0x1efd9c cmp r4, r8 */
/* @0x1efda0 bne 0x1efd50 <_Z14Sprite_Add_BINPviiibbii+0x178> */
/* @0x1efda4 ldr r3, [r7, #0x4] */
/* @0x1efda8 str r1, [r2, #0x8] */
/* @0x1efdac stm r2, {r4, r5} */
/* @0x1efdb0 sub r3, r3, #1 */
/* @0x1efdb4 str r3, [r7, #0x4] */
/* @0x1efdb8 b 0x1efdc4 <_Z14Sprite_Add_BINPviiibbii+0x1ec> */
/* @0x1efdbc stm r2, {r4, r5} */
/* @0x1efdc0 str r0, [r2, #0x8] */
/* @0x1efdc4 mov r0, #136 */
/* @0x1efdc8 bl 0x27c524 <_Znwj> */
/* @0x1efdcc mov r4, r0 */
/* @0x1efdd0 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1efdd4 ldr r5, [sp, #0x24] */
/* @0x1efdd8 mov r12, #0 */
/* @0x1efddc ldr r0, [r6] */
/* @0x1efde0 ldr r1, [sp, #0x30] */
/* @0x1efde4 ldr lr, [r5, #0x4] */
/* @0x1efde8 sub r0, r0, #-1073741823 */
/* @0x1efdec ldr r2, [sp, #0x34] */
/* @0x1efdf0 ldr r3, [sp, #0x38] */
/* @0x1efdf4 str r4, [lr, r0, lsl #2] */
/* @0x1efdf8 mov lr, #1 */
/* @0x1efdfc ldr r4, [r5, #0x4] */
/* @0x1efe00 ldr r5, [sp, #0x40] */
/* @0x1efe04 ldr r0, [r4, r0, lsl #2] */
/* @0x1efe08 ldr r4, [sp, #0x3c] */
/* @0x1efe0c str r5, [sp, #0x4] */
/* @0x1efe10 ldr r5, [sp, #0x180] */
/* @0x1efe14 str r4, [sp] */
/* @0x1efe18 ldr r4, [sp, #0x44] */
/* @0x1efe1c str r5, [sp, #0x10] */
/* @0x1efe20 str r12, [sp, #0x8] */
/* @0x1efe24 str r4, [sp, #0xc] */
/* @0x1efe28 ldr r4, [sp, #0x184] */
/* @0x1efe2c str lr, [sp, #0x18] */
/* @0x1efe30 str r4, [sp, #0x14] */
/* @0x1efe34 bl 0x1e6fd4 <_ZN7CSprite12LoadFromDataEPviiibbbiib> */
/* @0x1efe38 cmp r0, #0 */
/* @0x1efe3c beq 0x1eff7c <_Z14Sprite_Add_BINPviiibbii+0x3a4> */
/* @0x1efe40 ldr r5, [sp, #0x24] */
/* @0x1efe44 ldr r12, [sp, #0x28] */
/* @0x1efe48 ldr r2, [r6] */
/* @0x1efe4c ldr r3, [r5, #0x4] */
/* @0x1efe50 ldr r0, [r12] */
/* @0x1efe54 sub r1, r2, #-1073741823 */
/* @0x1efe58 sub r2, r2, #1 */
/* @0x1efe5c ldr r3, [r3, r1, lsl #2] */
/* @0x1efe60 ldr r1, [r0, r1, lsl #2] */
/* @0x1efe64 mov r0, r2 */
/* @0x1efe68 str r2, [r3, #0x60] */
/* @0x1efe6c str r1, [r3, #0x5c] */
/* @0x1efe70 ldr r4, [sp, #0x2c] */
/* @0x1efe74 ldr r2, [sp, #0x14c] */
/* @0x1efe78 ldr r3, [r4] */
/* @0x1efe7c cmp r2, r3 */
/* @0x1efe80 bne 0x1eff90 <_Z14Sprite_Add_BINPviiibbii+0x3b8> */
/* @0x1efe84 add sp, sp, #340 */
/* @0x1efe88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1efe8c ldr r10, [r7] */
/* @0x1efe90 mov r3, #1 */
/* @0x1efe94 ldr r1, [pc, #0x11c] */
/* @0x1efe98 mov r2, #70 */
/* @0x1efe9c ldr r9, [r7, #0x10] */
/* @0x1efea0 lsl r0, r10, r3 */
/* @0x1efea4 add r1, pc, r1 */
/* @0x1efea8 add r8, r0, r10, lsl #2 */
/* @0x1efeac str r0, [r7] */
/* @0x1efeb0 sub r0, r0, #1 */
/* @0x1efeb4 str r0, [r7, #0x8] */
/* @0x1efeb8 lsl r8, r8, #2 */
/* @0x1efebc mov r0, r8 */
/* @0x1efec0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1efec4 mov r2, r8 */
/* @0x1efec8 mov r1, #0 */
/* @0x1efecc str r0, [r7, #0x10] */
/* @0x1efed0 bl 0xb65b0 <memset@plt> */
/* @0x1efed4 ldr r2, [r7] */
/* @0x1efed8 vldr s15, [pc, #180] */
/* @0x1efedc mov r1, #0 */
/* @0x1efee0 str r1, [r7, #0x4] */
/* @0x1efee4 cmp r2, r1 */
/* @0x1efee8 vmov s13, r2 */
/* @0x1efeec vcvt.f32.s32 s14, s13 */
/* @0x1efef0 vmul.f32 s15, s14, s15 */
/* @0x1efef4 vcvt.s32.f32 s15, s15 */
/* @0x1efef8 vstr s15, [r7, #12] */
/* @0x1efefc ble 0x1eff1c <_Z14Sprite_Add_BINPviiibbii+0x344> */
/* @0x1eff00 add r2, r2, r2, lsl #1 */
/* @0x1eff04 ldr r3, [r7, #0x10] */
/* @0x1eff08 add r2, r3, r2, lsl #2 */
/* @0x1eff0c str r1, [r3, #0x8] */
/* @0x1eff10 add r3, r3, #12 */
/* @0x1eff14 cmp r3, r2 */
/* @0x1eff18 bne 0x1eff0c <_Z14Sprite_Add_BINPviiibbii+0x334> */
/* @0x1eff1c cmp r10, #0 */
/* @0x1eff20 movgt r8, r9 */
/* @0x1eff24 movgt r11, #0 */
/* @0x1eff28 ble 0x1eff54 <_Z14Sprite_Add_BINPviiibbii+0x37c> */
/* @0x1eff2c ldr r3, [r8, #0x8] */
/* @0x1eff30 cmp r3, #0 */
/* @0x1eff34 ble 0x1eff44 <_Z14Sprite_Add_BINPviiibbii+0x36c> */
/* @0x1eff38 mov r0, r7 */
/* @0x1eff3c ldm r8, {r1, r2} */
/* @0x1eff40 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1eff44 add r11, r11, #1 */
/* @0x1eff48 add r8, r8, #12 */
/* @0x1eff4c cmp r11, r10 */
/* @0x1eff50 bne 0x1eff2c <_Z14Sprite_Add_BINPviiibbii+0x354> */
/* @0x1eff54 mov r0, r9 */
/* @0x1eff58 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1eff5c vldr s13, [r7] */
/* @0x1eff60 vcvt.f32.s32 s14, s13 */
/* @0x1eff64 vldr s15, [pc, #40] */
/* @0x1eff68 ldr r2, [r7, #0x4] */
/* @0x1eff6c vmul.f32 s15, s14, s15 */
/* @0x1eff70 vcvt.s32.f32 s15, s15 */
/* @0x1eff74 vstr s15, [r7, #12] */
/* @0x1eff78 b 0x1efcf0 <_Z14Sprite_Add_BINPviiibbii+0x118> */
/* @0x1eff7c ldr r3, [r6] */
/* @0x1eff80 mvn r0, #0 */
/* @0x1eff84 add r3, r3, r0 */
/* @0x1eff88 str r3, [r6] */
/* @0x1eff8c b 0x1efe70 <_Z14Sprite_Add_BINPviiibbii+0x298> */
/* @0x1eff90 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1eff94 svclo #0x19999a */
/* @0x1eff98 eoreq r2, r0, r8, rrx */
/* @0x1eff9c .word 0xffffbd00 */
/* @0x1effa0 .word 0xfffff1c0 */
/* @0x1effa4 .word 0xfffff1b8 */
/* @0x1effa8 andseq r2, r6, r0, lsr #20 */
/* @0x1effac .word 0xfffff1bc */
/* @0x1effb0 ldrsbeq r2, [r6], -r12 */
/* @0x1effb4 .word 0xfffff1c4 */
/* @0x1effb8 andseq r1, r4, r12, lsl #3 */

/* ── FUNC 0x1effbc · Sprite_Load(unsigned char*, int, unsigned char*) · size=1040 · insn=260 */
/* @0x1effbc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1effc0 vpush {d8} */
/* @0x1effc4 sub sp, sp, #52 */
/* @0x1effc8 ldr r12, [pc, #0x3d8] */
/* @0x1effcc mov r3, #228 */
/* @0x1effd0 ldr r1, [pc, #0x3d4] */
/* @0x1effd4 mov r5, r0 */
/* @0x1effd8 add r12, pc, r12 */
/* @0x1effdc str r12, [sp, #0x1c] */
/* @0x1effe0 ldr r12, [r0] */
/* @0x1effe4 str r2, [sp, #0x24] */
/* @0x1effe8 ldr r2, [pc, #0x3c0] */
/* @0x1effec str r12, [sp, #0x20] */
/* @0x1efff0 ldr r12, [sp, #0x1c] */
/* @0x1efff4 ldr r6, [pc, #0x3b8] */
/* @0x1efff8 ldr r4, [r12, r1] */
/* @0x1efffc add r6, pc, r6 */
/* @0x1f0000 ldr r12, [sp, #0x20] */
/* @0x1f0004 lsl r1, r12, #2 */
/* @0x1f0008 str r12, [r4] */
/* @0x1f000c ldr r12, [sp, #0x1c] */
/* @0x1f0010 ldr r2, [r12, r2] */
/* @0x1f0014 str r2, [sp, #0x14] */
/* @0x1f0018 mov r2, r6 */
/* @0x1f001c ldr r12, [sp, #0x14] */
/* @0x1f0020 add r0, r12, #4 */
/* @0x1f0024 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0028 ldr r1, [r4] */
/* @0x1f002c ldr r12, [sp, #0x14] */
/* @0x1f0030 mov r2, r6 */
/* @0x1f0034 ldr r0, [pc, #0x37c] */
/* @0x1f0038 mov r3, #230 */
/* @0x1f003c str r1, [r12] */
/* @0x1f0040 lsl r1, r1, #2 */
/* @0x1f0044 ldr r12, [sp, #0x1c] */
/* @0x1f0048 ldr r0, [r12, r0] */
/* @0x1f004c str r0, [sp, #0xc] */
/* @0x1f0050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0054 ldr r12, [sp, #0x20] */
/* @0x1f0058 cmp r12, #0 */
/* @0x1f005c beq 0x1f0298 <_Z11Sprite_LoadPhiS_+0x2dc> */
/* @0x1f0060 ldr r12, [pc, #0x354] */
/* @0x1f0064 vldr s16, [pc, #824] */
/* @0x1f0068 str r5, [sp, #0x18] */
/* @0x1f006c add r12, pc, r12 */
/* @0x1f0070 str r12, [sp, #0x28] */
/* @0x1f0074 mov r12, #0 */
/* @0x1f0078 str r12, [sp, #0x4] */
/* @0x1f007c ldr r12, [pc, #0x33c] */
/* @0x1f0080 add r12, pc, r12 */
/* @0x1f0084 str r12, [sp, #0x2c] */
/* @0x1f0088 ldr r12, [sp, #0x18] */
/* @0x1f008c ldr r5, [r12, #0x4]! */
/* @0x1f0090 cmp r5, #0 */
/* @0x1f0094 str r12, [sp, #0x18] */
/* @0x1f0098 streq r5, [sp, #0x8] */
/* @0x1f009c streq r5, [sp, #0x10] */
/* @0x1f00a0 beq 0x1f020c <_Z11Sprite_LoadPhiS_+0x250> */
/* @0x1f00a4 ldr r3, [pc, #0x318] */
/* @0x1f00a8 ldr r12, [sp, #0x1c] */
/* @0x1f00ac ldr r4, [r12, r3] */
/* @0x1f00b0 ldr r6, [r4] */
/* @0x1f00b4 adds r7, r6, r5 */
/* @0x1f00b8 streq r7, [sp, #0x8] */
/* @0x1f00bc streq r7, [sp, #0x10] */
/* @0x1f00c0 beq 0x1f020c <_Z11Sprite_LoadPhiS_+0x250> */
/* @0x1f00c4 mov r0, #136 */
/* @0x1f00c8 bl 0x27c524 <_Znwj> */
/* @0x1f00cc str r0, [sp, #0x10] */
/* @0x1f00d0 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1f00d4 mov r1, r7 */
/* @0x1f00d8 ldr r2, [sp, #0x24] */
/* @0x1f00dc ldr r0, [sp, #0x10] */
/* @0x1f00e0 bl 0x1e972c <_ZN7CSprite13LoadFromChunkEP8YYSpritePh> */
/* @0x1f00e4 ldr r3, [r6, r5] */
/* @0x1f00e8 cmp r3, #0 */
/* @0x1f00ec ldrne r4, [r4] */
/* @0x1f00f0 moveq r4, r3 */
/* @0x1f00f4 addne r4, r4, r3 */
/* @0x1f00f8 mov r0, r4 */
/* @0x1f00fc bl 0xb6538 <strlen@plt> */
/* @0x1f0100 mov r3, #1 */
/* @0x1f0104 mov r2, #242 */
/* @0x1f0108 ldr r1, [sp, #0x28] */
/* @0x1f010c add r0, r0, r3 */
/* @0x1f0110 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f0114 mov r1, r4 */
/* @0x1f0118 str r0, [sp, #0x8] */
/* @0x1f011c bl 0xb65a4 <strcpy@plt> */
/* @0x1f0120 ldr r3, [pc, #0x2a0] */
/* @0x1f0124 ldr r12, [sp, #0x1c] */
/* @0x1f0128 ldr r8, [r12, r3] */
/* @0x1f012c ldr r3, [r8, #0x4] */
/* @0x1f0130 ldr r2, [r8, #0xc] */
/* @0x1f0134 cmp r3, r2 */
/* @0x1f0138 bgt 0x1f02bc <_Z11Sprite_LoadPhiS_+0x300> */
/* @0x1f013c ldr r0, [sp, #0x8] */
/* @0x1f0140 add r3, r3, #1 */
/* @0x1f0144 str r3, [r8, #0x4] */
/* @0x1f0148 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f014c ldr r4, [r8, #0x8] */
/* @0x1f0150 ldr r10, [r8, #0x10] */
/* @0x1f0154 bic r7, r0, #-2147483648 */
/* @0x1f0158 and r3, r7, r4 */
/* @0x1f015c add r2, r3, r3, lsl #1 */
/* @0x1f0160 add r2, r10, r2, lsl #2 */
/* @0x1f0164 ldr r1, [r2, #0x8] */
/* @0x1f0168 cmp r1, #0 */
/* @0x1f016c beq 0x1f02a8 <_Z11Sprite_LoadPhiS_+0x2ec> */
/* @0x1f0170 ldr r11, [r8] */
/* @0x1f0174 mov r5, #0 */
/* @0x1f0178 ldr r9, [sp, #0x4] */
/* @0x1f017c ldr r0, [sp, #0x8] */
/* @0x1f0180 b 0x1f01c4 <_Z11Sprite_LoadPhiS_+0x208> */
/* @0x1f0184 ldr r6, [r2] */
/* @0x1f0188 ldr r5, [r2, #0x4] */
/* @0x1f018c str r7, [r2, #0x8] */
/* @0x1f0190 mov r7, r1 */
/* @0x1f0194 str r0, [r2] */
/* @0x1f0198 mov r0, r6 */
/* @0x1f019c str r9, [r2, #0x4] */
/* @0x1f01a0 mov r9, r5 */
/* @0x1f01a4 add r3, r3, #1 */
/* @0x1f01a8 add r5, r12, #1 */
/* @0x1f01ac and r3, r3, r4 */
/* @0x1f01b0 add r2, r3, r3, lsl #1 */
/* @0x1f01b4 add r2, r10, r2, lsl #2 */
/* @0x1f01b8 ldr r1, [r2, #0x8] */
/* @0x1f01bc cmp r1, #0 */
/* @0x1f01c0 beq 0x1f02b0 <_Z11Sprite_LoadPhiS_+0x2f4> */
/* @0x1f01c4 add r12, r3, r11 */
/* @0x1f01c8 and r6, r1, r4 */
/* @0x1f01cc rsb r12, r6, r12 */
/* @0x1f01d0 and r12, r12, r4 */
/* @0x1f01d4 cmp r12, r5 */
/* @0x1f01d8 blt 0x1f0184 <_Z11Sprite_LoadPhiS_+0x1c8> */
/* @0x1f01dc movne r12, r5 */
/* @0x1f01e0 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8> */
/* @0x1f01e4 cmp r1, r7 */
/* @0x1f01e8 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8> */
/* @0x1f01ec ldr r5, [r2] */
/* @0x1f01f0 cmp r0, r5 */
/* @0x1f01f4 bne 0x1f01a4 <_Z11Sprite_LoadPhiS_+0x1e8> */
/* @0x1f01f8 ldr r3, [r8, #0x4] */
/* @0x1f01fc str r1, [r2, #0x8] */
/* @0x1f0200 stm r2, {r0, r9} */
/* @0x1f0204 sub r3, r3, #1 */
/* @0x1f0208 str r3, [r8, #0x4] */
/* @0x1f020c ldr r12, [sp, #0xc] */
/* @0x1f0210 ldr r3, [r12] */
/* @0x1f0214 ldr r12, [sp, #0x4] */
/* @0x1f0218 ldr r0, [r3, r12, lsl #2] */
/* @0x1f021c lsl r4, r12, #2 */
/* @0x1f0220 cmp r0, #0 */
/* @0x1f0224 beq 0x1f0240 <_Z11Sprite_LoadPhiS_+0x284> */
/* @0x1f0228 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f022c ldr r12, [sp, #0xc] */
/* @0x1f0230 mov r0, #0 */
/* @0x1f0234 ldr r3, [r12] */
/* @0x1f0238 ldr r12, [sp, #0x4] */
/* @0x1f023c str r0, [r3, r12, lsl #2] */
/* @0x1f0240 ldr r12, [sp, #0x14] */
/* @0x1f0244 ldr r0, [sp, #0x20] */
/* @0x1f0248 ldr r3, [r12, #0x4] */
/* @0x1f024c ldr r12, [sp, #0x10] */
/* @0x1f0250 str r12, [r3, r4] */
/* @0x1f0254 ldr r12, [sp, #0xc] */
/* @0x1f0258 ldr r3, [r12] */
/* @0x1f025c ldr r12, [sp, #0x8] */
/* @0x1f0260 str r12, [r3, r4] */
/* @0x1f0264 ldr r12, [sp, #0x14] */
/* @0x1f0268 ldr r3, [r12, #0x4] */
/* @0x1f026c ldr r12, [sp, #0xc] */
/* @0x1f0270 ldr r3, [r3, r4] */
/* @0x1f0274 ldr r2, [r12] */
/* @0x1f0278 ldr r12, [sp, #0x4] */
/* @0x1f027c ldr r2, [r2, r4] */
/* @0x1f0280 str r12, [r3, #0x60] */
/* @0x1f0284 add r12, r12, #1 */
/* @0x1f0288 cmp r12, r0 */
/* @0x1f028c str r12, [sp, #0x4] */
/* @0x1f0290 str r2, [r3, #0x5c] */
/* @0x1f0294 bne 0x1f0088 <_Z11Sprite_LoadPhiS_+0xcc> */
/* @0x1f0298 mov r0, #1 */
/* @0x1f029c add sp, sp, #52 */
/* @0x1f02a0 vpop {d8} */
/* @0x1f02a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f02a8 ldr r9, [sp, #0x4] */
/* @0x1f02ac ldr r0, [sp, #0x8] */
/* @0x1f02b0 stm r2, {r0, r9} */
/* @0x1f02b4 str r7, [r2, #0x8] */
/* @0x1f02b8 b 0x1f020c <_Z11Sprite_LoadPhiS_+0x250> */
/* @0x1f02bc ldr r5, [r8] */
/* @0x1f02c0 mov r3, #1 */
/* @0x1f02c4 ldr r1, [sp, #0x2c] */
/* @0x1f02c8 mov r2, #70 */
/* @0x1f02cc ldr r7, [r8, #0x10] */
/* @0x1f02d0 lsl r0, r5, r3 */
/* @0x1f02d4 str r0, [r8] */
/* @0x1f02d8 add r4, r0, r5, lsl #2 */
/* @0x1f02dc sub r0, r0, #1 */
/* @0x1f02e0 str r0, [r8, #0x8] */
/* @0x1f02e4 lsl r4, r4, #2 */
/* @0x1f02e8 mov r0, r4 */
/* @0x1f02ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f02f0 mov r2, r4 */
/* @0x1f02f4 mov r1, #0 */
/* @0x1f02f8 str r0, [r8, #0x10] */
/* @0x1f02fc bl 0xb65b0 <memset@plt> */
/* @0x1f0300 ldr r2, [r8] */
/* @0x1f0304 mov r0, #0 */
/* @0x1f0308 str r0, [r8, #0x4] */
/* @0x1f030c cmp r2, r0 */
/* @0x1f0310 vmov s14, r2 */
/* @0x1f0314 vcvt.f32.s32 s15, s14 */
/* @0x1f0318 vmul.f32 s15, s15, s16 */
/* @0x1f031c vcvt.s32.f32 s15, s15 */
/* @0x1f0320 vstr s15, [r8, #12] */
/* @0x1f0324 ble 0x1f0348 <_Z11Sprite_LoadPhiS_+0x38c> */
/* @0x1f0328 add r2, r2, r2, lsl #1 */
/* @0x1f032c ldr r3, [r8, #0x10] */
/* @0x1f0330 add r2, r3, r2, lsl #2 */
/* @0x1f0334 mov r0, #0 */
/* @0x1f0338 add r3, r3, #12 */
/* @0x1f033c str r0, [r3, #-0x4] */
/* @0x1f0340 cmp r3, r2 */
/* @0x1f0344 bne 0x1f0334 <_Z11Sprite_LoadPhiS_+0x378> */
/* @0x1f0348 cmp r5, #0 */
/* @0x1f034c movgt r4, r7 */
/* @0x1f0350 movgt r6, #0 */
/* @0x1f0354 ble 0x1f0380 <_Z11Sprite_LoadPhiS_+0x3c4> */
/* @0x1f0358 ldr r3, [r4, #0x8] */
/* @0x1f035c mov r0, r8 */
/* @0x1f0360 add r6, r6, #1 */
/* @0x1f0364 cmp r3, #0 */
/* @0x1f0368 ble 0x1f0374 <_Z11Sprite_LoadPhiS_+0x3b8> */
/* @0x1f036c ldm r4, {r1, r2} */
/* @0x1f0370 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f0374 cmp r6, r5 */
/* @0x1f0378 add r4, r4, #12 */
/* @0x1f037c bne 0x1f0358 <_Z11Sprite_LoadPhiS_+0x39c> */
/* @0x1f0380 mov r0, r7 */
/* @0x1f0384 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f0388 vldr s14, [r8] */
/* @0x1f038c vcvt.f32.s32 s15, s14 */
/* @0x1f0390 ldr r3, [r8, #0x4] */
/* @0x1f0394 vmul.f32 s15, s15, s16 */
/* @0x1f0398 vcvt.s32.f32 s15, s15 */
/* @0x1f039c vstr s15, [r8, #12] */
/* @0x1f03a0 b 0x1f013c <_Z11Sprite_LoadPhiS_+0x180> */
/* @0x1f03a4 svclo #0x19999a */
/* @0x1f03a8 eoreq r1, r0, r8, ror r12 */
/* @0x1f03ac .word 0xfffff1c0 */
/* @0x1f03b0 .word 0xfffff1b8 */
/* @0x1f03b4 andseq r2, r6, r4, asr #12 */
/* @0x1f03b8 .word 0xfffff1bc */
/* @0x1f03bc ldrsbeq r2, [r6], -r4 */
/* @0x1f03c0 ldrheq r0, [r4], -r0 */
/* @0x1f03c4 .word 0xffffbcf4 */
/* @0x1f03c8 .word 0xfffff1c4 */

/* ── FUNC 0x1f03cc · Sprite_Add_Alpha(char const*, int, bool, bool, int, int) · size=1060 · insn=265 */
/* @0x1f03cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f03d0 sub sp, sp, #1344 */
/* @0x1f03d4 sub sp, sp, #4 */
/* @0x1f03d8 ldr r4, [pc, #0x3ec] */
/* @0x1f03dc mov r5, r0 */
/* @0x1f03e0 str r1, [sp, #0x2c] */
/* @0x1f03e4 add r4, pc, r4 */
/* @0x1f03e8 ldr r1, [pc, #0x3e0] */
/* @0x1f03ec str r3, [sp, #0x34] */
/* @0x1f03f0 str r2, [sp, #0x30] */
/* @0x1f03f4 ldr r1, [r4, r1] */
/* @0x1f03f8 ldr r3, [r1] */
/* @0x1f03fc str r1, [sp, #0x24] */
/* @0x1f0400 str r3, [sp, #0x53c] */
/* @0x1f0404 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1f0408 cmp r0, #0 */
/* @0x1f040c beq 0x1f068c <_Z16Sprite_Add_AlphaPKcibbii+0x2c0> */
/* @0x1f0410 add r3, sp, #316 */
/* @0x1f0414 mov r2, r5 */
/* @0x1f0418 mov r1, #1024 */
/* @0x1f041c str r3, [sp, #0x28] */
/* @0x1f0420 mov r0, r3 */
/* @0x1f0424 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1f0428 ldr r2, [pc, #0x3a4] */
/* @0x1f042c movw r3, #0x2d7 */
/* @0x1f0430 ldr r0, [pc, #0x3a0] */
/* @0x1f0434 ldr r5, [pc, #0x3a0] */
/* @0x1f0438 ldr r6, [r4, r2] */
/* @0x1f043c add r5, pc, r5 */
/* @0x1f0440 ldr r1, [r6] */
/* @0x1f0444 mov r2, r5 */
/* @0x1f0448 add r1, r1, #1 */
/* @0x1f044c str r1, [r6] */
/* @0x1f0450 ldr r0, [r4, r0] */
/* @0x1f0454 lsl r1, r1, #2 */
/* @0x1f0458 str r0, [sp, #0x1c] */
/* @0x1f045c add r0, r0, #4 */
/* @0x1f0460 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0464 ldr r1, [r6] */
/* @0x1f0468 mov r2, r5 */
/* @0x1f046c ldr r0, [pc, #0x36c] */
/* @0x1f0470 ldr r5, [sp, #0x1c] */
/* @0x1f0474 movw r3, #0x2d9 */
/* @0x1f0478 str r1, [r5] */
/* @0x1f047c lsl r1, r1, #2 */
/* @0x1f0480 ldr r0, [r4, r0] */
/* @0x1f0484 add r5, sp, #60 */
/* @0x1f0488 str r0, [sp, #0x20] */
/* @0x1f048c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0490 ldr r3, [r6] */
/* @0x1f0494 mov r1, #256 */
/* @0x1f0498 ldr r2, [pc, #0x344] */
/* @0x1f049c mov r0, r5 */
/* @0x1f04a0 sub r3, r3, #1 */
/* @0x1f04a4 add r2, pc, r2 */
/* @0x1f04a8 bl 0xb65c8 <snprintf@plt> */
/* @0x1f04ac ldr r12, [sp, #0x20] */
/* @0x1f04b0 mov r0, r5 */
/* @0x1f04b4 ldr r8, [r6] */
/* @0x1f04b8 ldr r7, [r12] */
/* @0x1f04bc bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1f04c0 ldr r2, [pc, #0x320] */
/* @0x1f04c4 sub r8, r8, #-1073741823 */
/* @0x1f04c8 ldr r5, [r6] */
/* @0x1f04cc ldr r12, [sp, #0x20] */
/* @0x1f04d0 sub r3, r5, #-1073741823 */
/* @0x1f04d4 sub r5, r5, #1 */
/* @0x1f04d8 str r0, [r7, r8, lsl #2] */
/* @0x1f04dc ldr r7, [r4, r2] */
/* @0x1f04e0 ldr r0, [r12] */
/* @0x1f04e4 ldr r2, [r7, #0x4] */
/* @0x1f04e8 ldr r1, [r7, #0xc] */
/* @0x1f04ec ldr r4, [r0, r3, lsl #2] */
/* @0x1f04f0 cmp r2, r1 */
/* @0x1f04f4 bgt 0x1f06b8 <_Z16Sprite_Add_AlphaPKcibbii+0x2ec> */
/* @0x1f04f8 mov r0, r4 */
/* @0x1f04fc add r2, r2, #1 */
/* @0x1f0500 str r2, [r7, #0x4] */
/* @0x1f0504 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f0508 ldr lr, [r7, #0x8] */
/* @0x1f050c ldr r10, [r7, #0x10] */
/* @0x1f0510 bic r0, r0, #-2147483648 */
/* @0x1f0514 and r3, r0, lr */
/* @0x1f0518 add r2, r3, r3, lsl #1 */
/* @0x1f051c add r2, r10, r2, lsl #2 */
/* @0x1f0520 ldr r1, [r2, #0x8] */
/* @0x1f0524 cmp r1, #0 */
/* @0x1f0528 ldrne r11, [r7] */
/* @0x1f052c movne r8, #0 */
/* @0x1f0530 bne 0x1f0578 <_Z16Sprite_Add_AlphaPKcibbii+0x1ac> */
/* @0x1f0534 b 0x1f05c4 <_Z16Sprite_Add_AlphaPKcibbii+0x1f8> */
/* @0x1f0538 ldr r9, [r2] */
/* @0x1f053c ldr r8, [r2, #0x4] */
/* @0x1f0540 str r0, [r2, #0x8] */
/* @0x1f0544 mov r0, r1 */
/* @0x1f0548 str r4, [r2] */
/* @0x1f054c mov r4, r9 */
/* @0x1f0550 str r5, [r2, #0x4] */
/* @0x1f0554 mov r5, r8 */
/* @0x1f0558 add r3, r3, #1 */
/* @0x1f055c add r8, r12, #1 */
/* @0x1f0560 and r3, r3, lr */
/* @0x1f0564 add r2, r3, r3, lsl #1 */
/* @0x1f0568 add r2, r10, r2, lsl #2 */
/* @0x1f056c ldr r1, [r2, #0x8] */
/* @0x1f0570 cmp r1, #0 */
/* @0x1f0574 beq 0x1f05c4 <_Z16Sprite_Add_AlphaPKcibbii+0x1f8> */
/* @0x1f0578 add r12, r3, r11 */
/* @0x1f057c and r9, r1, lr */
/* @0x1f0580 rsb r12, r9, r12 */
/* @0x1f0584 and r12, r12, lr */
/* @0x1f0588 cmp r12, r8 */
/* @0x1f058c blt 0x1f0538 <_Z16Sprite_Add_AlphaPKcibbii+0x16c> */
/* @0x1f0590 movne r12, r8 */
/* @0x1f0594 bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c> */
/* @0x1f0598 cmp r1, r0 */
/* @0x1f059c bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c> */
/* @0x1f05a0 ldr r8, [r2] */
/* @0x1f05a4 cmp r4, r8 */
/* @0x1f05a8 bne 0x1f0558 <_Z16Sprite_Add_AlphaPKcibbii+0x18c> */
/* @0x1f05ac ldr r3, [r7, #0x4] */
/* @0x1f05b0 str r1, [r2, #0x8] */
/* @0x1f05b4 stm r2, {r4, r5} */
/* @0x1f05b8 sub r3, r3, #1 */
/* @0x1f05bc str r3, [r7, #0x4] */
/* @0x1f05c0 b 0x1f05cc <_Z16Sprite_Add_AlphaPKcibbii+0x200> */
/* @0x1f05c4 stm r2, {r4, r5} */
/* @0x1f05c8 str r0, [r2, #0x8] */
/* @0x1f05cc mov r0, #136 */
/* @0x1f05d0 bl 0x27c524 <_Znwj> */
/* @0x1f05d4 mov r4, r0 */
/* @0x1f05d8 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1f05dc ldr r5, [sp, #0x1c] */
/* @0x1f05e0 mov r12, #1 */
/* @0x1f05e4 ldr lr, [r6] */
/* @0x1f05e8 ldr r1, [sp, #0x28] */
/* @0x1f05ec ldr r0, [r5, #0x4] */
/* @0x1f05f0 sub lr, lr, #-1073741823 */
/* @0x1f05f4 ldr r2, [sp, #0x2c] */
/* @0x1f05f8 ldr r3, [sp, #0x30] */
/* @0x1f05fc str r4, [r0, lr, lsl #2] */
/* @0x1f0600 mov r4, #0 */
/* @0x1f0604 ldr r0, [r5, #0x4] */
/* @0x1f0608 ldr r5, [sp, #0x34] */
/* @0x1f060c ldr r0, [r0, lr, lsl #2] */
/* @0x1f0610 str r5, [sp, #0x8] */
/* @0x1f0614 ldr lr, [sp, #0x568] */
/* @0x1f0618 ldr r5, [sp, #0x56c] */
/* @0x1f061c str r12, [sp] */
/* @0x1f0620 str lr, [sp, #0xc] */
/* @0x1f0624 str r5, [sp, #0x10] */
/* @0x1f0628 str r12, [sp, #0x14] */
/* @0x1f062c str r4, [sp, #0x4] */
/* @0x1f0630 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib> */
/* @0x1f0634 cmp r0, r4 */
/* @0x1f0638 beq 0x1f07b0 <_Z16Sprite_Add_AlphaPKcibbii+0x3e4> */
/* @0x1f063c ldr r12, [sp, #0x1c] */
/* @0x1f0640 ldr r5, [sp, #0x20] */
/* @0x1f0644 ldr r2, [r6] */
/* @0x1f0648 ldr r3, [r12, #0x4] */
/* @0x1f064c ldr r0, [r5] */
/* @0x1f0650 sub r1, r2, #-1073741823 */
/* @0x1f0654 sub r2, r2, #1 */
/* @0x1f0658 ldr r3, [r3, r1, lsl #2] */
/* @0x1f065c ldr r1, [r0, r1, lsl #2] */
/* @0x1f0660 mov r0, r2 */
/* @0x1f0664 str r2, [r3, #0x60] */
/* @0x1f0668 str r1, [r3, #0x5c] */
/* @0x1f066c ldr r12, [sp, #0x24] */
/* @0x1f0670 ldr r2, [sp, #0x53c] */
/* @0x1f0674 ldr r3, [r12] */
/* @0x1f0678 cmp r2, r3 */
/* @0x1f067c bne 0x1f07c4 <_Z16Sprite_Add_AlphaPKcibbii+0x3f8> */
/* @0x1f0680 add sp, sp, #1344 */
/* @0x1f0684 add sp, sp, #4 */
/* @0x1f0688 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f068c mov r0, r5 */
/* @0x1f0690 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1f0694 cmp r0, #0 */
/* @0x1f0698 beq 0x1f07a8 <_Z16Sprite_Add_AlphaPKcibbii+0x3dc> */
/* @0x1f069c add r3, sp, #316 */
/* @0x1f06a0 mov r2, r5 */
/* @0x1f06a4 mov r1, #1024 */
/* @0x1f06a8 str r3, [sp, #0x28] */
/* @0x1f06ac mov r0, r3 */
/* @0x1f06b0 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1f06b4 b 0x1f0428 <_Z16Sprite_Add_AlphaPKcibbii+0x5c> */
/* @0x1f06b8 ldr r9, [r7] */
/* @0x1f06bc mov r3, #1 */
/* @0x1f06c0 ldr r1, [pc, #0x124] */
/* @0x1f06c4 mov r2, #70 */
/* @0x1f06c8 ldr r11, [r7, #0x10] */
/* @0x1f06cc lsl r0, r9, r3 */
/* @0x1f06d0 add r1, pc, r1 */
/* @0x1f06d4 add r8, r0, r9, lsl #2 */
/* @0x1f06d8 str r0, [r7] */
/* @0x1f06dc sub r0, r0, #1 */
/* @0x1f06e0 str r0, [r7, #0x8] */
/* @0x1f06e4 lsl r8, r8, #2 */
/* @0x1f06e8 mov r0, r8 */
/* @0x1f06ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f06f0 mov r2, r8 */
/* @0x1f06f4 mov r1, #0 */
/* @0x1f06f8 str r0, [r7, #0x10] */
/* @0x1f06fc bl 0xb65b0 <memset@plt> */
/* @0x1f0700 ldr r2, [r7] */
/* @0x1f0704 vldr s15, [pc, #188] */
/* @0x1f0708 mov r1, #0 */
/* @0x1f070c str r1, [r7, #0x4] */
/* @0x1f0710 cmp r2, r1 */
/* @0x1f0714 vmov s13, r2 */
/* @0x1f0718 vcvt.f32.s32 s14, s13 */
/* @0x1f071c vmul.f32 s15, s14, s15 */
/* @0x1f0720 vcvt.s32.f32 s15, s15 */
/* @0x1f0724 vstr s15, [r7, #12] */
/* @0x1f0728 ble 0x1f0748 <_Z16Sprite_Add_AlphaPKcibbii+0x37c> */
/* @0x1f072c add r2, r2, r2, lsl #1 */
/* @0x1f0730 ldr r3, [r7, #0x10] */
/* @0x1f0734 add r2, r3, r2, lsl #2 */
/* @0x1f0738 str r1, [r3, #0x8] */
/* @0x1f073c add r3, r3, #12 */
/* @0x1f0740 cmp r3, r2 */
/* @0x1f0744 bne 0x1f0738 <_Z16Sprite_Add_AlphaPKcibbii+0x36c> */
/* @0x1f0748 cmp r9, #0 */
/* @0x1f074c movgt r8, r11 */
/* @0x1f0750 movgt r10, #0 */
/* @0x1f0754 ble 0x1f0780 <_Z16Sprite_Add_AlphaPKcibbii+0x3b4> */
/* @0x1f0758 ldr r3, [r8, #0x8] */
/* @0x1f075c cmp r3, #0 */
/* @0x1f0760 ble 0x1f0770 <_Z16Sprite_Add_AlphaPKcibbii+0x3a4> */
/* @0x1f0764 mov r0, r7 */
/* @0x1f0768 ldm r8, {r1, r2} */
/* @0x1f076c bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f0770 add r10, r10, #1 */
/* @0x1f0774 add r8, r8, #12 */
/* @0x1f0778 cmp r10, r9 */
/* @0x1f077c bne 0x1f0758 <_Z16Sprite_Add_AlphaPKcibbii+0x38c> */
/* @0x1f0780 mov r0, r11 */
/* @0x1f0784 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f0788 vldr s13, [r7] */
/* @0x1f078c vcvt.f32.s32 s14, s13 */
/* @0x1f0790 vldr s15, [pc, #48] */
/* @0x1f0794 ldr r2, [r7, #0x4] */
/* @0x1f0798 vmul.f32 s15, s14, s15 */
/* @0x1f079c vcvt.s32.f32 s15, s15 */
/* @0x1f07a0 vstr s15, [r7, #12] */
/* @0x1f07a4 b 0x1f04f8 <_Z16Sprite_Add_AlphaPKcibbii+0x12c> */
/* @0x1f07a8 mvn r0, #0 */
/* @0x1f07ac b 0x1f066c <_Z16Sprite_Add_AlphaPKcibbii+0x2a0> */
/* @0x1f07b0 ldr r3, [r6] */
/* @0x1f07b4 mvn r0, #0 */
/* @0x1f07b8 add r3, r3, r0 */
/* @0x1f07bc str r3, [r6] */
/* @0x1f07c0 b 0x1f066c <_Z16Sprite_Add_AlphaPKcibbii+0x2a0> */
/* @0x1f07c4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1f07c8 svclo #0x19999a */
/* @0x1f07cc eoreq r1, r0, r12, ror #16 */
/* @0x1f07d0 .word 0xffffbd00 */
/* @0x1f07d4 .word 0xfffff1c0 */
/* @0x1f07d8 .word 0xfffff1b8 */
/* @0x1f07dc andseq r2, r6, r4, lsl #4 */
/* @0x1f07e0 .word 0xfffff1bc */
/* @0x1f07e4 ldrsbeq r2, [r6], -r4 */
/* @0x1f07e8 .word 0xfffff1c4 */
/* @0x1f07ec andseq r0, r4, r0, ror #18 */

/* ── FUNC 0x1f07f0 · Sprite_Duplicate(int) · size=1336 · insn=334 */
/* @0x1f07f0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f07f4 sub sp, sp, #284 */
/* @0x1f07f8 ldr r4, [pc, #0x500] */
/* @0x1f07fc cmp r0, #0 */
/* @0x1f0800 ldr r3, [pc, #0x4fc] */
/* @0x1f0804 add r4, pc, r4 */
/* @0x1f0808 str r0, [sp, #0x8] */
/* @0x1f080c ldr r3, [r4, r3] */
/* @0x1f0810 str r3, [sp, #0xc] */
/* @0x1f0814 ldr r3, [r3] */
/* @0x1f0818 str r3, [sp, #0x114] */
/* @0x1f081c blt 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4> */
/* @0x1f0820 ldr r3, [pc, #0x4e0] */
/* @0x1f0824 ldr r5, [r4, r3] */
/* @0x1f0828 ldr r3, [r5] */
/* @0x1f082c cmp r0, r3 */
/* @0x1f0830 bge 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4> */
/* @0x1f0834 ldr r2, [pc, #0x4d0] */
/* @0x1f0838 ldr r2, [r4, r2] */
/* @0x1f083c str r2, [sp] */
/* @0x1f0840 ldr r2, [r2, #0x4] */
/* @0x1f0844 ldr r2, [r2, r0, lsl #2] */
/* @0x1f0848 cmp r2, #0 */
/* @0x1f084c beq 0x1f0ce4 <_Z16Sprite_Duplicatei+0x4f4> */
/* @0x1f0850 ldr r6, [pc, #0x4b8] */
/* @0x1f0854 add r2, r3, #1 */
/* @0x1f0858 ldr r12, [sp] */
/* @0x1f085c movw r3, #0x357 */
/* @0x1f0860 add r6, pc, r6 */
/* @0x1f0864 lsl r1, r2, #2 */
/* @0x1f0868 add r0, r12, #4 */
/* @0x1f086c str r2, [r5] */
/* @0x1f0870 mov r2, r6 */
/* @0x1f0874 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0878 ldr r1, [r5] */
/* @0x1f087c ldr r12, [sp] */
/* @0x1f0880 mov r2, r6 */
/* @0x1f0884 ldr r0, [pc, #0x488] */
/* @0x1f0888 movw r3, #0x359 */
/* @0x1f088c str r1, [r12] */
/* @0x1f0890 lsl r1, r1, #2 */
/* @0x1f0894 ldr r0, [r4, r0] */
/* @0x1f0898 str r0, [sp, #0x4] */
/* @0x1f089c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f08a0 ldr r7, [r5] */
/* @0x1f08a4 add r5, sp, #20 */
/* @0x1f08a8 ldr r2, [pc, #0x468] */
/* @0x1f08ac mov r1, #256 */
/* @0x1f08b0 sub r7, r7, #1 */
/* @0x1f08b4 mov r0, r5 */
/* @0x1f08b8 add r2, pc, r2 */
/* @0x1f08bc mov r3, r7 */
/* @0x1f08c0 bl 0xb65c8 <snprintf@plt> */
/* @0x1f08c4 ldr r12, [sp, #0x4] */
/* @0x1f08c8 mov r0, r5 */
/* @0x1f08cc ldr r5, [r12] */
/* @0x1f08d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1f08d4 ldr r3, [pc, #0x440] */
/* @0x1f08d8 ldr r12, [sp, #0x4] */
/* @0x1f08dc str r0, [r5, r7, lsl #2] */
/* @0x1f08e0 ldr r8, [r4, r3] */
/* @0x1f08e4 ldr r1, [r12] */
/* @0x1f08e8 ldr r3, [r8, #0x4] */
/* @0x1f08ec ldr r2, [r8, #0xc] */
/* @0x1f08f0 ldr r6, [r1, r7, lsl #2] */
/* @0x1f08f4 cmp r3, r2 */
/* @0x1f08f8 bgt 0x1f0a50 <_Z16Sprite_Duplicatei+0x260> */
/* @0x1f08fc mov r0, r6 */
/* @0x1f0900 add r3, r3, #1 */
/* @0x1f0904 str r3, [r8, #0x4] */
/* @0x1f0908 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f090c ldr r4, [r8, #0x8] */
/* @0x1f0910 ldr r10, [r8, #0x10] */
/* @0x1f0914 bic r0, r0, #-2147483648 */
/* @0x1f0918 and r2, r0, r4 */
/* @0x1f091c add r1, r2, r2, lsl #1 */
/* @0x1f0920 add r1, r10, r1, lsl #2 */
/* @0x1f0924 ldr r12, [r1, #0x8] */
/* @0x1f0928 cmp r12, #0 */
/* @0x1f092c beq 0x1f09c8 <_Z16Sprite_Duplicatei+0x1d8> */
/* @0x1f0930 ldr r11, [r8] */
/* @0x1f0934 mov r9, r7 */
/* @0x1f0938 mov r5, #0 */
/* @0x1f093c b 0x1f097c <_Z16Sprite_Duplicatei+0x18c> */
/* @0x1f0940 ldm r1, {r5, lr} */
/* @0x1f0944 str r0, [r1, #0x8] */
/* @0x1f0948 mov r0, r12 */
/* @0x1f094c str r6, [r1] */
/* @0x1f0950 str r9, [r1, #0x4] */
/* @0x1f0954 mov r6, r5 */
/* @0x1f0958 mov r9, lr */
/* @0x1f095c add r2, r2, #1 */
/* @0x1f0960 add r5, r3, #1 */
/* @0x1f0964 and r2, r2, r4 */
/* @0x1f0968 add r1, r2, r2, lsl #1 */
/* @0x1f096c add r1, r10, r1, lsl #2 */
/* @0x1f0970 ldr r12, [r1, #0x8] */
/* @0x1f0974 cmp r12, #0 */
/* @0x1f0978 beq 0x1f09cc <_Z16Sprite_Duplicatei+0x1dc> */
/* @0x1f097c add r3, r2, r11 */
/* @0x1f0980 and lr, r12, r4 */
/* @0x1f0984 rsb r3, lr, r3 */
/* @0x1f0988 and r3, r3, r4 */
/* @0x1f098c cmp r3, r5 */
/* @0x1f0990 blt 0x1f0940 <_Z16Sprite_Duplicatei+0x150> */
/* @0x1f0994 movne r3, r5 */
/* @0x1f0998 bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c> */
/* @0x1f099c cmp r12, r0 */
/* @0x1f09a0 bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c> */
/* @0x1f09a4 ldr lr, [r1] */
/* @0x1f09a8 cmp r6, lr */
/* @0x1f09ac bne 0x1f095c <_Z16Sprite_Duplicatei+0x16c> */
/* @0x1f09b0 ldr r3, [r8, #0x4] */
/* @0x1f09b4 str r12, [r1, #0x8] */
/* @0x1f09b8 stm r1, {r6, r9} */
/* @0x1f09bc sub r3, r3, #1 */
/* @0x1f09c0 str r3, [r8, #0x4] */
/* @0x1f09c4 b 0x1f09d4 <_Z16Sprite_Duplicatei+0x1e4> */
/* @0x1f09c8 mov r9, r7 */
/* @0x1f09cc stm r1, {r6, r9} */
/* @0x1f09d0 str r0, [r1, #0x8] */
/* @0x1f09d4 mov r0, #136 */
/* @0x1f09d8 bl 0x27c524 <_Znwj> */
/* @0x1f09dc mov r4, r0 */
/* @0x1f09e0 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1f09e4 ldr r12, [sp] */
/* @0x1f09e8 ldr r3, [r12, #0x4] */
/* @0x1f09ec str r4, [r3, r7, lsl #2] */
/* @0x1f09f0 ldr r3, [r12, #0x4] */
/* @0x1f09f4 ldr r12, [sp, #0x8] */
/* @0x1f09f8 ldr r0, [r3, r7, lsl #2] */
/* @0x1f09fc ldr r1, [r3, r12, lsl #2] */
/* @0x1f0a00 bl 0x1e76e8 <_ZN7CSprite6AssignEPS_> */
/* @0x1f0a04 ldr r12, [sp] */
/* @0x1f0a08 ldr r3, [r12, #0x4] */
/* @0x1f0a0c ldr r3, [r3, r7, lsl #2] */
/* @0x1f0a10 ldr r5, [r3, #0x44] */
/* @0x1f0a14 cmp r5, #0 */
/* @0x1f0a18 beq 0x1f0b40 <_Z16Sprite_Duplicatei+0x350> */
/* @0x1f0a1c ldr r12, [sp, #0x4] */
/* @0x1f0a20 mov r0, r7 */
/* @0x1f0a24 str r7, [r3, #0x60] */
/* @0x1f0a28 ldr r2, [r12] */
/* @0x1f0a2c ldr r2, [r2, r7, lsl #2] */
/* @0x1f0a30 str r2, [r3, #0x5c] */
/* @0x1f0a34 ldr r12, [sp, #0xc] */
/* @0x1f0a38 ldr r2, [sp, #0x114] */
/* @0x1f0a3c ldr r3, [r12] */
/* @0x1f0a40 cmp r2, r3 */
/* @0x1f0a44 bne 0x1f0cf8 <_Z16Sprite_Duplicatei+0x508> */
/* @0x1f0a48 add sp, sp, #284 */
/* @0x1f0a4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f0a50 ldr r9, [r8] */
/* @0x1f0a54 mov r3, #1 */
/* @0x1f0a58 ldr r1, [pc, #0x2c0] */
/* @0x1f0a5c mov r2, #70 */
/* @0x1f0a60 ldr r5, [r8, #0x10] */
/* @0x1f0a64 lsl r0, r9, r3 */
/* @0x1f0a68 add r1, pc, r1 */
/* @0x1f0a6c add r4, r0, r9, lsl #2 */
/* @0x1f0a70 str r0, [r8] */
/* @0x1f0a74 sub r0, r0, #1 */
/* @0x1f0a78 str r0, [r8, #0x8] */
/* @0x1f0a7c lsl r4, r4, #2 */
/* @0x1f0a80 mov r0, r4 */
/* @0x1f0a84 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f0a88 mov r2, r4 */
/* @0x1f0a8c mov r1, #0 */
/* @0x1f0a90 str r0, [r8, #0x10] */
/* @0x1f0a94 bl 0xb65b0 <memset@plt> */
/* @0x1f0a98 ldr r2, [r8] */
/* @0x1f0a9c vldr s15, [pc, #600] */
/* @0x1f0aa0 mov r1, #0 */
/* @0x1f0aa4 str r1, [r8, #0x4] */
/* @0x1f0aa8 cmp r2, r1 */
/* @0x1f0aac vmov s13, r2 */
/* @0x1f0ab0 vcvt.f32.s32 s14, s13 */
/* @0x1f0ab4 vmul.f32 s15, s14, s15 */
/* @0x1f0ab8 vcvt.s32.f32 s15, s15 */
/* @0x1f0abc vstr s15, [r8, #12] */
/* @0x1f0ac0 ble 0x1f0ae0 <_Z16Sprite_Duplicatei+0x2f0> */
/* @0x1f0ac4 add r2, r2, r2, lsl #1 */
/* @0x1f0ac8 ldr r3, [r8, #0x10] */
/* @0x1f0acc add r2, r3, r2, lsl #2 */
/* @0x1f0ad0 str r1, [r3, #0x8] */
/* @0x1f0ad4 add r3, r3, #12 */
/* @0x1f0ad8 cmp r3, r2 */
/* @0x1f0adc bne 0x1f0ad0 <_Z16Sprite_Duplicatei+0x2e0> */
/* @0x1f0ae0 cmp r9, #0 */
/* @0x1f0ae4 movgt r4, r5 */
/* @0x1f0ae8 movgt r10, #0 */
/* @0x1f0aec ble 0x1f0b18 <_Z16Sprite_Duplicatei+0x328> */
/* @0x1f0af0 ldr r3, [r4, #0x8] */
/* @0x1f0af4 cmp r3, #0 */
/* @0x1f0af8 ble 0x1f0b08 <_Z16Sprite_Duplicatei+0x318> */
/* @0x1f0afc mov r0, r8 */
/* @0x1f0b00 ldm r4, {r1, r2} */
/* @0x1f0b04 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f0b08 add r10, r10, #1 */
/* @0x1f0b0c add r4, r4, #12 */
/* @0x1f0b10 cmp r10, r9 */
/* @0x1f0b14 bne 0x1f0af0 <_Z16Sprite_Duplicatei+0x300> */
/* @0x1f0b18 mov r0, r5 */
/* @0x1f0b1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f0b20 vldr s13, [r8] */
/* @0x1f0b24 vcvt.f32.s32 s14, s13 */
/* @0x1f0b28 vldr s15, [pc, #460] */
/* @0x1f0b2c ldr r3, [r8, #0x4] */
/* @0x1f0b30 vmul.f32 s15, s14, s15 */
/* @0x1f0b34 vcvt.s32.f32 s15, s15 */
/* @0x1f0b38 vstr s15, [r8, #12] */
/* @0x1f0b3c b 0x1f08fc <_Z16Sprite_Duplicatei+0x10c> */
/* @0x1f0b40 mov r0, r3 */
/* @0x1f0b44 bl 0x1e65d8 <_ZN7CSprite18GenerateBitmapDataEv> */
/* @0x1f0b48 ldr r12, [sp] */
/* @0x1f0b4c ldr r3, [r12, #0x4] */
/* @0x1f0b50 cmp r0, #0 */
/* @0x1f0b54 beq 0x1f0cc0 <_Z16Sprite_Duplicatei+0x4d0> */
/* @0x1f0b58 ldr r0, [r3, r7, lsl #2] */
/* @0x1f0b5c ldr r3, [r0, #0x54] */
/* @0x1f0b60 cmp r3, #0 */
/* @0x1f0b64 beq 0x1f0cc8 <_Z16Sprite_Duplicatei+0x4d8> */
/* @0x1f0b68 ldr r3, [r0, #0x18] */
/* @0x1f0b6c cmp r3, #0 */
/* @0x1f0b70 ble 0x1f0cc8 <_Z16Sprite_Duplicatei+0x4d8> */
/* @0x1f0b74 ldr r1, [pc, #0x1a8] */
/* @0x1f0b78 mov r0, #22 */
/* @0x1f0b7c mul r0, r0, r3 */
/* @0x1f0b80 add r1, pc, r1 */
/* @0x1f0b84 mov r2, #70 */
/* @0x1f0b88 mov r3, #1 */
/* @0x1f0b8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f0b90 ldr r12, [sp] */
/* @0x1f0b94 ldr r10, [r12, #0x4] */
/* @0x1f0b98 mov r4, r0 */
/* @0x1f0b9c ldr r0, [r10, r7, lsl #2] */
/* @0x1f0ba0 ldr r9, [r0, #0x18] */
/* @0x1f0ba4 cmp r9, #0 */
/* @0x1f0ba8 ble 0x1f0bfc <_Z16Sprite_Duplicatei+0x40c> */
/* @0x1f0bac ldr lr, [r0, #0x54] */
/* @0x1f0bb0 mov r1, r5 */
/* @0x1f0bb4 add r9, lr, r9, lsl #2 */
/* @0x1f0bb8 ldr r3, [lr], #4 */
/* @0x1f0bbc add r2, r4, r1 */
/* @0x1f0bc0 cmp lr, r9 */
/* @0x1f0bc4 ldr r12, [r3] */
/* @0x1f0bc8 ldr r8, [r3, #0x4] */
/* @0x1f0bcc ldr r6, [r3, #0x8] */
/* @0x1f0bd0 ldr r5, [r3, #0xc] */
/* @0x1f0bd4 str r12, [r4, r1] */
/* @0x1f0bd8 add r1, r1, #22 */
/* @0x1f0bdc str r8, [r2, #0x4] */
/* @0x1f0be0 str r6, [r2, #0x8] */
/* @0x1f0be4 str r5, [r2, #0xc] */
/* @0x1f0be8 ldr r12, [r3, #0x10] */
/* @0x1f0bec str r12, [r2, #0x10] */
/* @0x1f0bf0 ldrh r3, [r3, #20] */
/* @0x1f0bf4 strh r3, [r2, #20] */
/* @0x1f0bf8 bne 0x1f0bb8 <_Z16Sprite_Duplicatei+0x3c8> */
/* @0x1f0bfc ldrb r3, [r0, #0x36] */
/* @0x1f0c00 cmp r3, #0 */
/* @0x1f0c04 beq 0x1f0cec <_Z16Sprite_Duplicatei+0x4fc> */
/* @0x1f0c08 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1f0c0c ldr r12, [sp] */
/* @0x1f0c10 ldr r3, [r12, #0x4] */
/* @0x1f0c14 ldr r0, [r3, r7, lsl #2] */
/* @0x1f0c18 bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1f0c1c cmp r4, #0 */
/* @0x1f0c20 beq 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0> */
/* @0x1f0c24 ldr r12, [sp] */
/* @0x1f0c28 ldr r3, [r12, #0x4] */
/* @0x1f0c2c ldr r3, [r3, r7, lsl #2] */
/* @0x1f0c30 ldr r1, [r3, #0x54] */
/* @0x1f0c34 cmp r1, #0 */
/* @0x1f0c38 beq 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0> */
/* @0x1f0c3c ldr lr, [r3, #0x18] */
/* @0x1f0c40 cmp lr, #0 */
/* @0x1f0c44 ble 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0> */
/* @0x1f0c48 add lr, r1, lr, lsl #2 */
/* @0x1f0c4c mov r2, r4 */
/* @0x1f0c50 ldrsh r3, [r2, #12] */
/* @0x1f0c54 add r2, r2, #22 */
/* @0x1f0c58 ldrsh r12, [r2, #-18] */
/* @0x1f0c5c vmov s14, r3 */
/* @0x1f0c60 ldr r3, [r1], #4 */
/* @0x1f0c64 vmov s15, r12 */
/* @0x1f0c68 vcvt.f32.s32 s14, s14 */
/* @0x1f0c6c cmp r1, lr */
/* @0x1f0c70 ldrh r12, [r3, #12] */
/* @0x1f0c74 ldrh r5, [r3, #14] */
/* @0x1f0c78 vcvt.f32.s32 s15, s15 */
/* @0x1f0c7c vdiv.f32 s15, s14, s15 */
/* @0x1f0c80 vcvt.s32.f32 s15, s15 */
/* @0x1f0c84 vmov r0, s15 */
/* @0x1f0c88 uxth r0, r0 */
/* @0x1f0c8c mul r12, r12, r0 */
/* @0x1f0c90 mul r0, r5, r0 */
/* @0x1f0c94 uxth r12, r12 */
/* @0x1f0c98 strh r12, [r3, #12] */
/* @0x1f0c9c strh r12, [r3, #16] */
/* @0x1f0ca0 uxth r0, r0 */
/* @0x1f0ca4 strh r0, [r3, #14] */
/* @0x1f0ca8 strh r0, [r3, #18] */
/* @0x1f0cac bne 0x1f0c50 <_Z16Sprite_Duplicatei+0x460> */
/* @0x1f0cb0 mov r0, r4 */
/* @0x1f0cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f0cb8 ldr r12, [sp] */
/* @0x1f0cbc ldr r3, [r12, #0x4] */
/* @0x1f0cc0 ldr r3, [r3, r7, lsl #2] */
/* @0x1f0cc4 b 0x1f0a1c <_Z16Sprite_Duplicatei+0x22c> */
/* @0x1f0cc8 bl 0x1e5748 <_ZN7CSprite11InitTextureEv> */
/* @0x1f0ccc ldr r12, [sp] */
/* @0x1f0cd0 mov r4, #0 */
/* @0x1f0cd4 ldr r3, [r12, #0x4] */
/* @0x1f0cd8 ldr r0, [r3, r7, lsl #2] */
/* @0x1f0cdc bl 0x1e5854 <_ZN7CSprite12InitLocalTPEEv> */
/* @0x1f0ce0 b 0x1f0cb0 <_Z16Sprite_Duplicatei+0x4c0> */
/* @0x1f0ce4 mvn r0, #0 */
/* @0x1f0ce8 b 0x1f0a34 <_Z16Sprite_Duplicatei+0x244> */
/* @0x1f0cec str r3, [r0, #0x54] */
/* @0x1f0cf0 ldr r0, [r10, r7, lsl #2] */
/* @0x1f0cf4 b 0x1f0c08 <_Z16Sprite_Duplicatei+0x418> */
/* @0x1f0cf8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1f0cfc svclo #0x19999a */
/* @0x1f0d00 eoreq r1, r0, r12, asr #8 */
/* @0x1f0d04 .word 0xffffbd00 */
/* @0x1f0d08 .word 0xfffff1c0 */
/* @0x1f0d0c .word 0xfffff1b8 */
/* @0x1f0d10 andseq r1, r6, r0, ror #27 */
/* @0x1f0d14 .word 0xfffff1bc */
/* @0x1f0d18 andseq r1, r6, r0, asr #27 */
/* @0x1f0d1c .word 0xfffff1c4 */
/* @0x1f0d20 andseq r0, r4, r8, asr #11 */
/* @0x1f0d24 ldrheq r0, [r4], -r0 */

/* ── FUNC 0x1f0d28 · Sprite_Load(CStream*) · size=1060 · insn=265 */
/* @0x1f0d28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f0d2c vpush {d8} */
/* @0x1f0d30 sub sp, sp, #44 */
/* @0x1f0d34 ldr r6, [pc, #0x3f4] */
/* @0x1f0d38 str r0, [sp, #0x18] */
/* @0x1f0d3c add r6, pc, r6 */
/* @0x1f0d40 str r6, [sp, #0x20] */
/* @0x1f0d44 bl 0x1eebbc <_Z11Sprite_Initv> */
/* @0x1f0d48 ldr r0, [sp, #0x18] */
/* @0x1f0d4c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1f0d50 cmp r0, #800 */
/* @0x1f0d54 cmpne r0, #400 */
/* @0x1f0d58 str r0, [sp, #0xc] */
/* @0x1f0d5c moveq r4, #0 */
/* @0x1f0d60 movne r4, #1 */
/* @0x1f0d64 beq 0x1f0d78 <_Z11Sprite_LoadP7CStream+0x50> */
/* @0x1f0d68 mov r0, #0 */
/* @0x1f0d6c add sp, sp, #44 */
/* @0x1f0d70 vpop {d8} */
/* @0x1f0d74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f0d78 ldr r0, [sp, #0x18] */
/* @0x1f0d7c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1f0d80 ldr r6, [sp, #0x20] */
/* @0x1f0d84 ldr lr, [pc, #0x3a8] */
/* @0x1f0d88 mov r3, #184 */
/* @0x1f0d8c ldr r12, [pc, #0x3a4] */
/* @0x1f0d90 ldr r5, [pc, #0x3a4] */
/* @0x1f0d94 ldr lr, [r6, lr] */
/* @0x1f0d98 add r5, pc, r5 */
/* @0x1f0d9c str lr, [sp, #0x1c] */
/* @0x1f0da0 mov r2, r5 */
/* @0x1f0da4 str r0, [lr] */
/* @0x1f0da8 lsl r1, r0, #2 */
/* @0x1f0dac ldr r8, [r6, r12] */
/* @0x1f0db0 add r0, r8, #4 */
/* @0x1f0db4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0db8 ldr r12, [sp, #0x1c] */
/* @0x1f0dbc ldr r0, [pc, #0x37c] */
/* @0x1f0dc0 mov r3, #186 */
/* @0x1f0dc4 mov r2, r5 */
/* @0x1f0dc8 ldr r1, [r12] */
/* @0x1f0dcc str r1, [r8] */
/* @0x1f0dd0 lsl r1, r1, #2 */
/* @0x1f0dd4 ldr r0, [r6, r0] */
/* @0x1f0dd8 str r0, [sp, #0x10] */
/* @0x1f0ddc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f0de0 ldr r6, [sp, #0x1c] */
/* @0x1f0de4 ldr r3, [r6] */
/* @0x1f0de8 cmp r3, #0 */
/* @0x1f0dec ble 0x1f111c <_Z11Sprite_LoadP7CStream+0x3f4> */
/* @0x1f0df0 ldr r12, [pc, #0x34c] */
/* @0x1f0df4 mov r7, r4 */
/* @0x1f0df8 vldr s16, [pc, #812] */
/* @0x1f0dfc add r12, pc, r12 */
/* @0x1f0e00 str r12, [sp, #0x24] */
/* @0x1f0e04 b 0x1f0e28 <_Z11Sprite_LoadP7CStream+0x100> */
/* @0x1f0e08 ldr r12, [sp, #0xc] */
/* @0x1f0e0c cmp r12, #800 */
/* @0x1f0e10 beq 0x1f0fb4 <_Z11Sprite_LoadP7CStream+0x28c> */
/* @0x1f0e14 ldr r6, [sp, #0x1c] */
/* @0x1f0e18 add r7, r7, #1 */
/* @0x1f0e1c ldr r3, [r6] */
/* @0x1f0e20 cmp r3, r7 */
/* @0x1f0e24 ble 0x1f111c <_Z11Sprite_LoadP7CStream+0x3f4> */
/* @0x1f0e28 ldr r6, [sp, #0xc] */
/* @0x1f0e2c cmp r6, #800 */
/* @0x1f0e30 beq 0x1f1000 <_Z11Sprite_LoadP7CStream+0x2d8> */
/* @0x1f0e34 ldr r12, [sp, #0x18] */
/* @0x1f0e38 str r12, [sp, #0x4] */
/* @0x1f0e3c ldr r0, [sp, #0x4] */
/* @0x1f0e40 lsl r6, r7, #2 */
/* @0x1f0e44 str r6, [sp, #0x14] */
/* @0x1f0e48 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1f0e4c ldr r3, [r8, #0x4] */
/* @0x1f0e50 mov r12, #0 */
/* @0x1f0e54 ldr r6, [sp, #0x10] */
/* @0x1f0e58 str r12, [r3, r7, lsl #2] */
/* @0x1f0e5c ldr r3, [r6] */
/* @0x1f0e60 str r12, [r3, r7, lsl #2] */
/* @0x1f0e64 cmp r0, r12 */
/* @0x1f0e68 beq 0x1f0e08 <_Z11Sprite_LoadP7CStream+0xe0> */
/* @0x1f0e6c ldr r6, [sp, #0x10] */
/* @0x1f0e70 ldr r12, [sp, #0x14] */
/* @0x1f0e74 ldr r0, [sp, #0x4] */
/* @0x1f0e78 ldr r1, [r6] */
/* @0x1f0e7c add r1, r1, r12 */
/* @0x1f0e80 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* @0x1f0e84 mov r0, #136 */
/* @0x1f0e88 bl 0x27c524 <_Znwj> */
/* @0x1f0e8c mov r4, r0 */
/* @0x1f0e90 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1f0e94 ldr r3, [r8, #0x4] */
/* @0x1f0e98 ldr r1, [pc, #0x2a8] */
/* @0x1f0e9c str r4, [r3, r7, lsl #2] */
/* @0x1f0ea0 ldr r3, [r6] */
/* @0x1f0ea4 ldr r2, [r8, #0x4] */
/* @0x1f0ea8 ldr r6, [sp, #0x20] */
/* @0x1f0eac ldr r0, [r3, r7, lsl #2] */
/* @0x1f0eb0 ldr r2, [r2, r7, lsl #2] */
/* @0x1f0eb4 str r0, [r2, #0x5c] */
/* @0x1f0eb8 str r7, [r2, #0x60] */
/* @0x1f0ebc ldr r2, [r6, r1] */
/* @0x1f0ec0 ldr r5, [r3, r7, lsl #2] */
/* @0x1f0ec4 str r2, [sp, #0x8] */
/* @0x1f0ec8 ldr r3, [r2, #0x4] */
/* @0x1f0ecc ldr r2, [r2, #0xc] */
/* @0x1f0ed0 cmp r3, r2 */
/* @0x1f0ed4 bgt 0x1f1010 <_Z11Sprite_LoadP7CStream+0x2e8> */
/* @0x1f0ed8 ldr r6, [sp, #0x8] */
/* @0x1f0edc mov r0, r5 */
/* @0x1f0ee0 add r3, r3, #1 */
/* @0x1f0ee4 str r3, [r6, #0x4] */
/* @0x1f0ee8 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f0eec ldr lr, [r6, #0x8] */
/* @0x1f0ef0 ldr r10, [r6, #0x10] */
/* @0x1f0ef4 bic r0, r0, #-2147483648 */
/* @0x1f0ef8 and r3, r0, lr */
/* @0x1f0efc add r2, r3, r3, lsl #1 */
/* @0x1f0f00 add r2, r10, r2, lsl #2 */
/* @0x1f0f04 ldr r1, [r2, #0x8] */
/* @0x1f0f08 cmp r1, #0 */
/* @0x1f0f0c beq 0x1f0fd4 <_Z11Sprite_LoadP7CStream+0x2ac> */
/* @0x1f0f10 ldr r12, [sp, #0x8] */
/* @0x1f0f14 mov r9, r7 */
/* @0x1f0f18 mov r4, #0 */
/* @0x1f0f1c ldr r11, [r12] */
/* @0x1f0f20 b 0x1f0f64 <_Z11Sprite_LoadP7CStream+0x23c> */
/* @0x1f0f24 ldr r6, [r2] */
/* @0x1f0f28 ldr r4, [r2, #0x4] */
/* @0x1f0f2c str r0, [r2, #0x8] */
/* @0x1f0f30 mov r0, r1 */
/* @0x1f0f34 str r5, [r2] */
/* @0x1f0f38 mov r5, r6 */
/* @0x1f0f3c str r9, [r2, #0x4] */
/* @0x1f0f40 mov r9, r4 */
/* @0x1f0f44 add r3, r3, #1 */
/* @0x1f0f48 add r4, r12, #1 */
/* @0x1f0f4c and r3, r3, lr */
/* @0x1f0f50 add r2, r3, r3, lsl #1 */
/* @0x1f0f54 add r2, r10, r2, lsl #2 */
/* @0x1f0f58 ldr r1, [r2, #0x8] */
/* @0x1f0f5c cmp r1, #0 */
/* @0x1f0f60 beq 0x1f0fd8 <_Z11Sprite_LoadP7CStream+0x2b0> */
/* @0x1f0f64 add r12, r11, r3 */
/* @0x1f0f68 and r6, r1, lr */
/* @0x1f0f6c rsb r12, r6, r12 */
/* @0x1f0f70 and r12, r12, lr */
/* @0x1f0f74 cmp r12, r4 */
/* @0x1f0f78 blt 0x1f0f24 <_Z11Sprite_LoadP7CStream+0x1fc> */
/* @0x1f0f7c movne r12, r4 */
/* @0x1f0f80 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c> */
/* @0x1f0f84 cmp r1, r0 */
/* @0x1f0f88 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c> */
/* @0x1f0f8c ldr r4, [r2] */
/* @0x1f0f90 cmp r5, r4 */
/* @0x1f0f94 bne 0x1f0f44 <_Z11Sprite_LoadP7CStream+0x21c> */
/* @0x1f0f98 ldr r12, [sp, #0x8] */
/* @0x1f0f9c str r1, [r2, #0x8] */
/* @0x1f0fa0 ldr r3, [r12, #0x4] */
/* @0x1f0fa4 stm r2, {r5, r9} */
/* @0x1f0fa8 sub r3, r3, #1 */
/* @0x1f0fac str r3, [r12, #0x4] */
/* @0x1f0fb0 b 0x1f0fe0 <_Z11Sprite_LoadP7CStream+0x2b8> */
/* @0x1f0fb4 ldr r12, [sp, #0x4] */
/* @0x1f0fb8 cmp r12, #0 */
/* @0x1f0fbc beq 0x1f0e14 <_Z11Sprite_LoadP7CStream+0xec> */
/* @0x1f0fc0 mov r0, r12 */
/* @0x1f0fc4 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x1f0fc8 ldr r0, [sp, #0x4] */
/* @0x1f0fcc bl 0x27d1d0 <_ZdlPv> */
/* @0x1f0fd0 b 0x1f0e14 <_Z11Sprite_LoadP7CStream+0xec> */
/* @0x1f0fd4 mov r9, r7 */
/* @0x1f0fd8 stm r2, {r5, r9} */
/* @0x1f0fdc str r0, [r2, #0x8] */
/* @0x1f0fe0 ldr r3, [r8, #0x4] */
/* @0x1f0fe4 ldr r6, [sp, #0x14] */
/* @0x1f0fe8 ldr r1, [sp, #0x4] */
/* @0x1f0fec ldr r0, [r3, r6] */
/* @0x1f0ff0 bl 0x1e7854 <_ZN7CSprite14LoadFromStreamEP7CStream> */
/* @0x1f0ff4 cmp r0, #0 */
/* @0x1f0ff8 bne 0x1f0e08 <_Z11Sprite_LoadP7CStream+0xe0> */
/* @0x1f0ffc b 0x1f0d68 <_Z11Sprite_LoadP7CStream+0x40> */
/* @0x1f1000 ldr r0, [sp, #0x18] */
/* @0x1f1004 bl 0x201db0 <_ZN7CStream20ReadCompressedStreamEv> */
/* @0x1f1008 str r0, [sp, #0x4] */
/* @0x1f100c b 0x1f0e3c <_Z11Sprite_LoadP7CStream+0x114> */
/* @0x1f1010 ldr r12, [sp, #0x8] */
/* @0x1f1014 mov r3, #1 */
/* @0x1f1018 ldr r1, [sp, #0x24] */
/* @0x1f101c mov r2, #70 */
/* @0x1f1020 ldr r6, [r12] */
/* @0x1f1024 ldr r10, [r12, #0x10] */
/* @0x1f1028 lsl r0, r6, r3 */
/* @0x1f102c str r0, [r12] */
/* @0x1f1030 add r4, r0, r6, lsl #2 */
/* @0x1f1034 sub r0, r0, #1 */
/* @0x1f1038 str r0, [r12, #0x8] */
/* @0x1f103c lsl r4, r4, #2 */
/* @0x1f1040 mov r0, r4 */
/* @0x1f1044 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f1048 ldr r12, [sp, #0x8] */
/* @0x1f104c mov r2, r4 */
/* @0x1f1050 mov r1, #0 */
/* @0x1f1054 str r0, [r12, #0x10] */
/* @0x1f1058 bl 0xb65b0 <memset@plt> */
/* @0x1f105c ldr r12, [sp, #0x8] */
/* @0x1f1060 mov lr, #0 */
/* @0x1f1064 ldr r2, [r12] */
/* @0x1f1068 str lr, [r12, #0x4] */
/* @0x1f106c cmp r2, lr */
/* @0x1f1070 vmov s14, r2 */
/* @0x1f1074 vcvt.f32.s32 s15, s14 */
/* @0x1f1078 vmul.f32 s15, s15, s16 */
/* @0x1f107c vcvt.s32.f32 s15, s15 */
/* @0x1f1080 vstr s15, [r12, #12] */
/* @0x1f1084 ble 0x1f10ac <_Z11Sprite_LoadP7CStream+0x384> */
/* @0x1f1088 ldr r12, [sp, #0x8] */
/* @0x1f108c add r2, r2, r2, lsl #1 */
/* @0x1f1090 ldr r3, [r12, #0x10] */
/* @0x1f1094 add r2, r3, r2, lsl #2 */
/* @0x1f1098 mov lr, #0 */
/* @0x1f109c add r3, r3, #12 */
/* @0x1f10a0 str lr, [r3, #-0x4] */
/* @0x1f10a4 cmp r3, r2 */
/* @0x1f10a8 bne 0x1f1098 <_Z11Sprite_LoadP7CStream+0x370> */
/* @0x1f10ac cmp r6, #0 */
/* @0x1f10b0 ble 0x1f10e8 <_Z11Sprite_LoadP7CStream+0x3c0> */
/* @0x1f10b4 ldr r11, [sp, #0x8] */
/* @0x1f10b8 mov r4, r10 */
/* @0x1f10bc mov r9, #0 */
/* @0x1f10c0 ldr r3, [r4, #0x8] */
/* @0x1f10c4 mov r0, r11 */
/* @0x1f10c8 add r9, r9, #1 */
/* @0x1f10cc cmp r3, #0 */
/* @0x1f10d0 ble 0x1f10dc <_Z11Sprite_LoadP7CStream+0x3b4> */
/* @0x1f10d4 ldm r4, {r1, r2} */
/* @0x1f10d8 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f10dc cmp r9, r6 */
/* @0x1f10e0 add r4, r4, #12 */
/* @0x1f10e4 bne 0x1f10c0 <_Z11Sprite_LoadP7CStream+0x398> */
/* @0x1f10e8 mov r0, r10 */
/* @0x1f10ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f10f0 ldr r6, [sp, #0x8] */
/* @0x1f10f4 ldr r12, [sp, #0x8] */
/* @0x1f10f8 ldr r6, [r6] */
/* @0x1f10fc ldr r3, [r12, #0x4] */
/* @0x1f1100 vmov s14, r6 */
/* @0x1f1104 str r6, [sp] */
/* @0x1f1108 vcvt.f32.s32 s15, s14 */
/* @0x1f110c vmul.f32 s15, s15, s16 */
/* @0x1f1110 vcvt.s32.f32 s15, s15 */
/* @0x1f1114 vstr s15, [r12, #12] */
/* @0x1f1118 b 0x1f0ed8 <_Z11Sprite_LoadP7CStream+0x1b0> */
/* @0x1f111c mov r0, #1 */
/* @0x1f1120 add sp, sp, #44 */
/* @0x1f1124 vpop {d8} */
/* @0x1f1128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f112c svclo #0x19999a */
/* @0x1f1130 eoreq r0, r0, r4, lsl pc */
/* @0x1f1134 .word 0xfffff1c0 */
/* @0x1f1138 .word 0xfffff1b8 */
/* @0x1f113c andseq r1, r6, r8, lsr #17 */
/* @0x1f1140 .word 0xfffff1bc */
/* @0x1f1144 andseq r0, r4, r4, lsr r2 */
/* @0x1f1148 .word 0xfffff1c4 */

/* ── FUNC 0x1f114c · Sprite_Add(char const*, int, bool, bool, bool, bool, int, int) · size=1448 · insn=362 */
/* @0x1f114c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f1150 subs r10, r0, #0 */
/* @0x1f1154 ldr r4, [pc, #0x55c] */
/* @0x1f1158 sub sp, sp, #1344 */
/* @0x1f115c ldr r0, [pc, #0x558] */
/* @0x1f1160 sub sp, sp, #4 */
/* @0x1f1164 add r4, pc, r4 */
/* @0x1f1168 mov r6, r3 */
/* @0x1f116c ldrb r12, [sp, #0x568] */
/* @0x1f1170 str r1, [sp, #0x28] */
/* @0x1f1174 str r2, [sp, #0x2c] */
/* @0x1f1178 ldr r0, [r4, r0] */
/* @0x1f117c str r12, [sp, #0x30] */
/* @0x1f1180 ldrb r12, [sp, #0x56c] */
/* @0x1f1184 ldr r3, [r0] */
/* @0x1f1188 str r0, [sp, #0x24] */
/* @0x1f118c str r12, [sp, #0x34] */
/* @0x1f1190 str r3, [sp, #0x53c] */
/* @0x1f1194 beq 0x1f16a8 <_Z10Sprite_AddPKcibbbbii+0x55c> */
/* @0x1f1198 ldr r2, [pc, #0x520] */
/* @0x1f119c movw r3, #0x1fe */
/* @0x1f11a0 ldr r0, [pc, #0x51c] */
/* @0x1f11a4 ldr r9, [pc, #0x51c] */
/* @0x1f11a8 ldr r8, [r4, r2] */
/* @0x1f11ac add r9, pc, r9 */
/* @0x1f11b0 ldr r1, [r8] */
/* @0x1f11b4 mov r2, r9 */
/* @0x1f11b8 add r1, r1, #1 */
/* @0x1f11bc str r1, [r8] */
/* @0x1f11c0 ldr r5, [r4, r0] */
/* @0x1f11c4 lsl r1, r1, #2 */
/* @0x1f11c8 add r0, r5, #4 */
/* @0x1f11cc bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f11d0 ldr r1, [r8] */
/* @0x1f11d4 ldr r0, [pc, #0x4f0] */
/* @0x1f11d8 mov r2, r9 */
/* @0x1f11dc mov r3, #512 */
/* @0x1f11e0 add r9, sp, #60 */
/* @0x1f11e4 str r1, [r5] */
/* @0x1f11e8 lsl r1, r1, #2 */
/* @0x1f11ec ldr r11, [r4, r0] */
/* @0x1f11f0 mov r0, r11 */
/* @0x1f11f4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1f11f8 ldr r3, [r8] */
/* @0x1f11fc ldr r2, [pc, #0x4cc] */
/* @0x1f1200 mov r1, #256 */
/* @0x1f1204 sub r3, r3, #1 */
/* @0x1f1208 mov r0, r9 */
/* @0x1f120c add r2, pc, r2 */
/* @0x1f1210 bl 0xb65c8 <snprintf@plt> */
/* @0x1f1214 ldr r3, [r8] */
/* @0x1f1218 mov r0, r9 */
/* @0x1f121c ldr r9, [r11] */
/* @0x1f1220 sub r7, r3, #-1073741823 */
/* @0x1f1224 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1f1228 str r0, [r9, r7, lsl #2] */
/* @0x1f122c mov r0, #136 */
/* @0x1f1230 bl 0x27c524 <_Znwj> */
/* @0x1f1234 mov r9, r0 */
/* @0x1f1238 bl 0x1e761c <_ZN7CSpriteC2Ev> */
/* @0x1f123c ldr r3, [r8] */
/* @0x1f1240 mov r1, r10 */
/* @0x1f1244 ldr r12, [r5, #0x4] */
/* @0x1f1248 mov r2, #7 */
/* @0x1f124c sub r3, r3, #-1073741823 */
/* @0x1f1250 ldr r0, [pc, #0x47c] */
/* @0x1f1254 str r9, [r12, r3, lsl #2] */
/* @0x1f1258 add r0, pc, r0 */
/* @0x1f125c bl 0xb65e0 <strncmp@plt> */
/* @0x1f1260 cmp r0, #0 */
/* @0x1f1264 beq 0x1f1284 <_Z10Sprite_AddPKcibbbbii+0x138> */
/* @0x1f1268 ldr r0, [pc, #0x468] */
/* @0x1f126c mov r1, r10 */
/* @0x1f1270 mov r2, #8 */
/* @0x1f1274 add r0, pc, r0 */
/* @0x1f1278 bl 0xb65e0 <strncmp@plt> */
/* @0x1f127c cmp r0, #0 */
/* @0x1f1280 bne 0x1f1468 <_Z10Sprite_AddPKcibbbbii+0x31c> */
/* @0x1f1284 mov r0, #20 */
/* @0x1f1288 mov r5, #1 */
/* @0x1f128c bl 0x27c524 <_Znwj> */
/* @0x1f1290 cmp r6, #0 */
/* @0x1f1294 ldr r2, [sp, #0x30] */
/* @0x1f1298 movne r6, #2 */
/* @0x1f129c moveq r6, #0 */
/* @0x1f12a0 cmp r2, #0 */
/* @0x1f12a4 ldr r3, [pc, #0x430] */
/* @0x1f12a8 ldr r2, [r8] */
/* @0x1f12ac movne r1, #4 */
/* @0x1f12b0 moveq r1, #0 */
/* @0x1f12b4 sub r2, r2, #1 */
/* @0x1f12b8 mov r12, r0 */
/* @0x1f12bc ldr r0, [sp, #0x2c] */
/* @0x1f12c0 str r2, [r12] */
/* @0x1f12c4 orr r7, r6, r0 */
/* @0x1f12c8 ldr r0, [sp, #0x34] */
/* @0x1f12cc orr r7, r7, r1 */
/* @0x1f12d0 ldr r2, [pc, #0x408] */
/* @0x1f12d4 cmp r0, #0 */
/* @0x1f12d8 ldr r0, [sp, #0x28] */
/* @0x1f12dc movne r1, #8 */
/* @0x1f12e0 moveq r1, #0 */
/* @0x1f12e4 str r0, [r12, #0x4] */
/* @0x1f12e8 orr r1, r7, r1 */
/* @0x1f12ec ldr r0, [sp, #0x570] */
/* @0x1f12f0 str r1, [r12, #0x10] */
/* @0x1f12f4 ldr r1, [sp, #0x574] */
/* @0x1f12f8 str r0, [r12, #0x8] */
/* @0x1f12fc mov r0, r10 */
/* @0x1f1300 str r1, [r12, #0xc] */
/* @0x1f1304 mov r1, #5 */
/* @0x1f1308 ldr lr, [r4, r3] */
/* @0x1f130c ldr r3, [pc, #0x3d0] */
/* @0x1f1310 strb r5, [lr] */
/* @0x1f1314 ldr r2, [r4, r2] */
/* @0x1f1318 ldr r3, [r4, r3] */
/* @0x1f131c str r12, [sp] */
/* @0x1f1320 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_> */
/* @0x1f1324 ldr r7, [r8] */
/* @0x1f1328 ldr r3, [r11] */
/* @0x1f132c sub r2, r7, #-1073741823 */
/* @0x1f1330 sub r7, r7, #1 */
/* @0x1f1334 add r2, r3, r2, lsl #2 */
/* @0x1f1338 ldr r3, [pc, #0x3a8] */
/* @0x1f133c ldr r6, [r2] */
/* @0x1f1340 ldr r3, [r4, r3] */
/* @0x1f1344 str r3, [sp, #0x20] */
/* @0x1f1348 ldr r12, [sp, #0x20] */
/* @0x1f134c ldr r3, [r3, #0x4] */
/* @0x1f1350 ldr r2, [r12, #0xc] */
/* @0x1f1354 cmp r3, r2 */
/* @0x1f1358 bgt 0x1f151c <_Z10Sprite_AddPKcibbbbii+0x3d0> */
/* @0x1f135c ldr r12, [sp, #0x20] */
/* @0x1f1360 mov r0, r6 */
/* @0x1f1364 add r3, r3, #1 */
/* @0x1f1368 str r3, [r12, #0x4] */
/* @0x1f136c bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f1370 ldr r12, [sp, #0x20] */
/* @0x1f1374 ldr r4, [r12, #0x8] */
/* @0x1f1378 ldr r10, [r12, #0x10] */
/* @0x1f137c bic r0, r0, #-2147483648 */
/* @0x1f1380 and r3, r0, r4 */
/* @0x1f1384 add r2, r3, r3, lsl #1 */
/* @0x1f1388 add r2, r10, r2, lsl #2 */
/* @0x1f138c ldr r1, [r2, #0x8] */
/* @0x1f1390 cmp r1, #0 */
/* @0x1f1394 beq 0x1f1438 <_Z10Sprite_AddPKcibbbbii+0x2ec> */
/* @0x1f1398 ldr r12, [sp, #0x20] */
/* @0x1f139c mov r5, #0 */
/* @0x1f13a0 ldr r11, [r12] */
/* @0x1f13a4 b 0x1f13e8 <_Z10Sprite_AddPKcibbbbii+0x29c> */
/* @0x1f13a8 ldr r9, [r2] */
/* @0x1f13ac ldr r5, [r2, #0x4] */
/* @0x1f13b0 str r0, [r2, #0x8] */
/* @0x1f13b4 mov r0, r1 */
/* @0x1f13b8 str r6, [r2] */
/* @0x1f13bc mov r6, r9 */
/* @0x1f13c0 str r7, [r2, #0x4] */
/* @0x1f13c4 mov r7, r5 */
/* @0x1f13c8 add r3, r3, #1 */
/* @0x1f13cc add r5, r12, #1 */
/* @0x1f13d0 and r3, r3, r4 */
/* @0x1f13d4 add r2, r3, r3, lsl #1 */
/* @0x1f13d8 add r2, r10, r2, lsl #2 */
/* @0x1f13dc ldr r1, [r2, #0x8] */
/* @0x1f13e0 cmp r1, #0 */
/* @0x1f13e4 beq 0x1f1438 <_Z10Sprite_AddPKcibbbbii+0x2ec> */
/* @0x1f13e8 add r12, r3, r11 */
/* @0x1f13ec and r9, r1, r4 */
/* @0x1f13f0 rsb r12, r9, r12 */
/* @0x1f13f4 and r12, r12, r4 */
/* @0x1f13f8 cmp r12, r5 */
/* @0x1f13fc blt 0x1f13a8 <_Z10Sprite_AddPKcibbbbii+0x25c> */
/* @0x1f1400 movne r12, r5 */
/* @0x1f1404 bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c> */
/* @0x1f1408 cmp r1, r0 */
/* @0x1f140c bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c> */
/* @0x1f1410 ldr r5, [r2] */
/* @0x1f1414 cmp r6, r5 */
/* @0x1f1418 bne 0x1f13c8 <_Z10Sprite_AddPKcibbbbii+0x27c> */
/* @0x1f141c ldr r12, [sp, #0x20] */
/* @0x1f1420 str r1, [r2, #0x8] */
/* @0x1f1424 ldr r3, [r12, #0x4] */
/* @0x1f1428 stm r2, {r6, r7} */
/* @0x1f142c sub r3, r3, #1 */
/* @0x1f1430 str r3, [r12, #0x4] */
/* @0x1f1434 b 0x1f1440 <_Z10Sprite_AddPKcibbbbii+0x2f4> */
/* @0x1f1438 stm r2, {r6, r7} */
/* @0x1f143c str r0, [r2, #0x8] */
/* @0x1f1440 ldr r0, [r8] */
/* @0x1f1444 sub r0, r0, #1 */
/* @0x1f1448 ldr r12, [sp, #0x24] */
/* @0x1f144c ldr r2, [sp, #0x53c] */
/* @0x1f1450 ldr r3, [r12] */
/* @0x1f1454 cmp r2, r3 */
/* @0x1f1458 bne 0x1f16b0 <_Z10Sprite_AddPKcibbbbii+0x564> */
/* @0x1f145c add sp, sp, #1344 */
/* @0x1f1460 add sp, sp, #4 */
/* @0x1f1464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f1468 mov r0, r10 */
/* @0x1f146c bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1f1470 cmp r0, #0 */
/* @0x1f1474 bne 0x1f162c <_Z10Sprite_AddPKcibbbbii+0x4e0> */
/* @0x1f1478 mov r0, r10 */
/* @0x1f147c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1f1480 cmp r0, #0 */
/* @0x1f1484 beq 0x1f169c <_Z10Sprite_AddPKcibbbbii+0x550> */
/* @0x1f1488 add r9, sp, #316 */
/* @0x1f148c mov r2, r10 */
/* @0x1f1490 mov r1, #1024 */
/* @0x1f1494 mov r0, r9 */
/* @0x1f1498 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1f149c mov r0, r9 */
/* @0x1f14a0 bl 0x215008 <_Z14ExtractFileExtPKc> */
/* @0x1f14a4 ldr r1, [pc, #0x240] */
/* @0x1f14a8 add r1, pc, r1 */
/* @0x1f14ac mov r10, r0 */
/* @0x1f14b0 bl 0xb66d0 <strcasecmp@plt> */
/* @0x1f14b4 cmp r0, #0 */
/* @0x1f14b8 mov r0, r10 */
/* @0x1f14bc bne 0x1f1644 <_Z10Sprite_AddPKcibbbbii+0x4f8> */
/* @0x1f14c0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f14c4 ldr r12, [r8] */
/* @0x1f14c8 ldr r0, [r5, #0x4] */
/* @0x1f14cc mov r1, r9 */
/* @0x1f14d0 sub r12, r12, #-1073741823 */
/* @0x1f14d4 ldr r2, [sp, #0x570] */
/* @0x1f14d8 ldr r3, [sp, #0x574] */
/* @0x1f14dc ldr r0, [r0, r12, lsl #2] */
/* @0x1f14e0 bl 0x1e9b68 <_ZN7CSprite15LoadFromYYSFileEPKcii> */
/* @0x1f14e4 cmp r0, #0 */
/* @0x1f14e8 beq 0x1f169c <_Z10Sprite_AddPKcibbbbii+0x550> */
/* @0x1f14ec ldr r0, [r8] */
/* @0x1f14f0 ldr r2, [r5, #0x4] */
/* @0x1f14f4 ldr r12, [r11] */
/* @0x1f14f8 sub r3, r0, #-1073741823 */
/* @0x1f14fc sub r0, r0, #1 */
/* @0x1f1500 ldr r1, [r2, r3, lsl #2] */
/* @0x1f1504 add r2, r12, r3, lsl #2 */
/* @0x1f1508 ldr r3, [r12, r3, lsl #2] */
/* @0x1f150c mov r7, r0 */
/* @0x1f1510 str r0, [r1, #0x60] */
/* @0x1f1514 str r3, [r1, #0x5c] */
/* @0x1f1518 b 0x1f1338 <_Z10Sprite_AddPKcibbbbii+0x1ec> */
/* @0x1f151c ldr r9, [r12] */
/* @0x1f1520 mov r3, #1 */
/* @0x1f1524 ldr r1, [pc, #0x1c4] */
/* @0x1f1528 mov r2, #70 */
/* @0x1f152c ldr r5, [r12, #0x10] */
/* @0x1f1530 lsl r0, r9, r3 */
/* @0x1f1534 add r1, pc, r1 */
/* @0x1f1538 add r4, r0, r9, lsl #2 */
/* @0x1f153c str r0, [r12] */
/* @0x1f1540 sub r0, r0, #1 */
/* @0x1f1544 str r0, [r12, #0x8] */
/* @0x1f1548 lsl r4, r4, #2 */
/* @0x1f154c mov r0, r4 */
/* @0x1f1550 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1f1554 ldr r12, [sp, #0x20] */
/* @0x1f1558 mov r2, r4 */
/* @0x1f155c mov r1, #0 */
/* @0x1f1560 str r0, [r12, #0x10] */
/* @0x1f1564 bl 0xb65b0 <memset@plt> */
/* @0x1f1568 ldr r12, [sp, #0x20] */
/* @0x1f156c vldr s15, [pc, #320] */
/* @0x1f1570 mov r1, #0 */
/* @0x1f1574 ldr r2, [r12] */
/* @0x1f1578 str r1, [r12, #0x4] */
/* @0x1f157c cmp r2, r1 */
/* @0x1f1580 vmov s13, r2 */
/* @0x1f1584 vcvt.f32.s32 s14, s13 */
/* @0x1f1588 vmul.f32 s15, s14, s15 */
/* @0x1f158c vcvt.s32.f32 s15, s15 */
/* @0x1f1590 vstr s15, [r12, #12] */
/* @0x1f1594 ble 0x1f15b8 <_Z10Sprite_AddPKcibbbbii+0x46c> */
/* @0x1f1598 ldr r12, [sp, #0x20] */
/* @0x1f159c add r2, r2, r2, lsl #1 */
/* @0x1f15a0 ldr r3, [r12, #0x10] */
/* @0x1f15a4 add r2, r3, r2, lsl #2 */
/* @0x1f15a8 str r1, [r3, #0x8] */
/* @0x1f15ac add r3, r3, #12 */
/* @0x1f15b0 cmp r3, r2 */
/* @0x1f15b4 bne 0x1f15a8 <_Z10Sprite_AddPKcibbbbii+0x45c> */
/* @0x1f15b8 cmp r9, #0 */
/* @0x1f15bc ble 0x1f15f4 <_Z10Sprite_AddPKcibbbbii+0x4a8> */
/* @0x1f15c0 ldr r11, [sp, #0x20] */
/* @0x1f15c4 mov r4, r5 */
/* @0x1f15c8 mov r10, #0 */
/* @0x1f15cc ldr r3, [r4, #0x8] */
/* @0x1f15d0 cmp r3, #0 */
/* @0x1f15d4 ble 0x1f15e4 <_Z10Sprite_AddPKcibbbbii+0x498> */
/* @0x1f15d8 mov r0, r11 */
/* @0x1f15dc ldm r4, {r1, r2} */
/* @0x1f15e0 bl 0xd261c <_ZN8CHashMapIPKciLi7EE6InsertES1_i> */
/* @0x1f15e4 add r10, r10, #1 */
/* @0x1f15e8 add r4, r4, #12 */
/* @0x1f15ec cmp r10, r9 */
/* @0x1f15f0 bne 0x1f15cc <_Z10Sprite_AddPKcibbbbii+0x480> */
/* @0x1f15f4 mov r0, r5 */
/* @0x1f15f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f15fc ldr r12, [sp, #0x20] */
/* @0x1f1600 vldr s15, [pc, #172] */
/* @0x1f1604 ldr r12, [r12] */
/* @0x1f1608 str r12, [sp, #0x1c] */
/* @0x1f160c vldr s13, [sp, #28] */
/* @0x1f1610 vcvt.f32.s32 s14, s13 */
/* @0x1f1614 ldr r12, [sp, #0x20] */
/* @0x1f1618 ldr r3, [r12, #0x4] */
/* @0x1f161c vmul.f32 s15, s14, s15 */
/* @0x1f1620 vcvt.s32.f32 s15, s15 */
/* @0x1f1624 vstr s15, [r12, #12] */
/* @0x1f1628 b 0x1f135c <_Z10Sprite_AddPKcibbbbii+0x210> */
/* @0x1f162c add r9, sp, #316 */
/* @0x1f1630 mov r2, r10 */
/* @0x1f1634 mov r1, #1024 */
/* @0x1f1638 mov r0, r9 */
/* @0x1f163c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1f1640 b 0x1f149c <_Z10Sprite_AddPKcibbbbii+0x350> */
/* @0x1f1644 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1648 ldr r12, [r8] */
/* @0x1f164c ldr r0, [r5, #0x4] */
/* @0x1f1650 eor lr, r6, #1 */
/* @0x1f1654 sub r12, r12, #-1073741823 */
/* @0x1f1658 mov r1, r9 */
/* @0x1f165c ldr r2, [sp, #0x28] */
/* @0x1f1660 ldr r0, [r0, r12, lsl #2] */
/* @0x1f1664 ldr r12, [sp, #0x30] */
/* @0x1f1668 ldr r3, [sp, #0x2c] */
/* @0x1f166c str r6, [sp] */
/* @0x1f1670 str r12, [sp, #0x4] */
/* @0x1f1674 ldr r12, [sp, #0x34] */
/* @0x1f1678 str lr, [sp, #0x14] */
/* @0x1f167c str r12, [sp, #0x8] */
/* @0x1f1680 ldr r12, [sp, #0x570] */
/* @0x1f1684 str r12, [sp, #0xc] */
/* @0x1f1688 ldr r12, [sp, #0x574] */
/* @0x1f168c str r12, [sp, #0x10] */
/* @0x1f1690 bl 0x1e7270 <_ZN7CSprite12LoadFromFileEPKcibbbbiib> */
/* @0x1f1694 cmp r0, #0 */
/* @0x1f1698 bne 0x1f14ec <_Z10Sprite_AddPKcibbbbii+0x3a0> */
/* @0x1f169c ldr r3, [r8] */
/* @0x1f16a0 sub r3, r3, #1 */
/* @0x1f16a4 str r3, [r8] */
/* @0x1f16a8 mvn r0, #0 */
/* @0x1f16ac b 0x1f1448 <_Z10Sprite_AddPKcibbbbii+0x2fc> */
/* @0x1f16b0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1f16b4 svclo #0x19999a */
/* @0x1f16b8 eoreq r0, r0, r12, ror #21 */
/* @0x1f16bc .word 0xffffbd00 */
/* @0x1f16c0 .word 0xfffff1c0 */
/* @0x1f16c4 .word 0xfffff1b8 */
/* @0x1f16c8 mulseq r6, r4, r4 */
/* @0x1f16cc .word 0xfffff1bc */
/* @0x1f16d0 andseq r1, r6, r12, ror #8 */
/* @0x1f16d4 andseq pc, r3, r8, lsl #17 */
/* @0x1f16d8 andseq pc, r3, r4, ror r8 */
/* @0x1f16dc .word 0xffffbd04 */
/* @0x1f16e0 .word 0xfffff1c8 */
/* @0x1f16e4 .word 0xfffff1cc */
/* @0x1f16e8 .word 0xfffff1c4 */
/* @0x1f16ec andseq r1, r6, r0, ror #3 */
/* @0x1f16f0 ldrsheq pc, [r3], -r12 */

/* ── FUNC 0x1f16f4 · CTimeLine::Free() · size=28 · insn=7 */
/* @0x1f16f4 push {r3, lr} */
/* @0x1f16f8 subs r3, r0, #0 */
/* @0x1f16fc popeq {r3, pc} */
/* @0x1f1700 ldr r3, [r3] */
/* @0x1f1704 ldr r3, [r3, #0x4] */
/* @0x1f1708 blx r3 */
/* @0x1f170c pop {r3, pc} */

/* ── FUNC 0x1f1710 · CTimeLine::GetEvent(int) · size=40 · insn=10 */
/* @0x1f1710 cmp r1, #0 */
/* @0x1f1714 blt 0x1f1724 <_ZN9CTimeLine8GetEventEi+0x14> */
/* @0x1f1718 ldr r3, [r0, #0x8] */
/* @0x1f171c cmp r1, r3 */
/* @0x1f1720 blt 0x1f172c <_ZN9CTimeLine8GetEventEi+0x1c> */
/* @0x1f1724 mov r0, #0 */
/* @0x1f1728 bx lr */
/* @0x1f172c ldr r3, [r0, #0xc] */
/* @0x1f1730 ldr r0, [r3, r1, lsl #2] */
/* @0x1f1734 bx lr */

/* ── FUNC 0x1f1738 · CTimeLine::GetStep(int) · size=40 · insn=10 */
/* @0x1f1738 cmp r1, #0 */
/* @0x1f173c blt 0x1f174c <_ZN9CTimeLine7GetStepEi+0x14> */
/* @0x1f1740 ldr r3, [r0, #0x8] */
/* @0x1f1744 cmp r1, r3 */
/* @0x1f1748 blt 0x1f1754 <_ZN9CTimeLine7GetStepEi+0x1c> */
/* @0x1f174c mov r0, #0 */
/* @0x1f1750 bx lr */
/* @0x1f1754 ldr r3, [r0, #0x14] */
/* @0x1f1758 ldr r0, [r3, r1, lsl #2] */
/* @0x1f175c bx lr */

/* ── FUNC 0x1f1760 · CTimeLine::GetCount() · size=8 · insn=2 */
/* @0x1f1760 ldr r0, [r0, #0x8] */
/* @0x1f1764 bx lr */

/* ── FUNC 0x1f1768 · CTimeLine::Clear() · size=296 · insn=74 */
/* @0x1f1768 ldr r12, [r0, #0x8] */
/* @0x1f176c push {r4, r5, r6, r7, r8, lr} */
/* @0x1f1770 subs r3, r12, #1 */
/* @0x1f1774 mov r5, r0 */
/* @0x1f1778 lslpl r2, r3, #2 */
/* @0x1f177c movpl lr, #0 */
/* @0x1f1780 bmi 0x1f17ac <_ZN9CTimeLine5ClearEv+0x44> */
/* @0x1f1784 cmp r12, r3 */
/* @0x1f1788 sub r3, r3, #1 */
/* @0x1f178c ble 0x1f17a0 <_ZN9CTimeLine5ClearEv+0x38> */
/* @0x1f1790 ldr r1, [r5, #0xc] */
/* @0x1f1794 ldr r0, [r1, r2] */
/* @0x1f1798 tst r0, #1 */
/* @0x1f179c strne lr, [r1, r2] */
/* @0x1f17a0 cmn r3, #1 */
/* @0x1f17a4 sub r2, r2, #4 */
/* @0x1f17a8 bne 0x1f1784 <_ZN9CTimeLine5ClearEv+0x1c> */
/* @0x1f17ac cmp r12, #0 */
/* @0x1f17b0 beq 0x1f1850 <_ZN9CTimeLine5ClearEv+0xe8> */
/* @0x1f17b4 ldr r6, [r5, #0xc] */
/* @0x1f17b8 cmp r6, #0 */
/* @0x1f17bc beq 0x1f1880 <_ZN9CTimeLine5ClearEv+0x118> */
/* @0x1f17c0 cmp r12, #0 */
/* @0x1f17c4 ble 0x1f1838 <_ZN9CTimeLine5ClearEv+0xd0> */
/* @0x1f17c8 mov r4, #0 */
/* @0x1f17cc mov r8, r4 */
/* @0x1f17d0 ldr r1, [r6] */
/* @0x1f17d4 movw r3, #0xfeee */
/* @0x1f17d8 movt r3, #0xfeee */
/* @0x1f17dc movw r2, #0xfeee */
/* @0x1f17e0 cmp r1, r3 */
/* @0x1f17e4 movt r2, #0xfeee */
/* @0x1f17e8 lsl r7, r4, #2 */
/* @0x1f17ec beq 0x1f1828 <_ZN9CTimeLine5ClearEv+0xc0> */
/* @0x1f17f0 ldr r3, [r6, r4, lsl #2] */
/* @0x1f17f4 add r1, r6, r7 */
/* @0x1f17f8 cmp r3, #0 */
/* @0x1f17fc mov r0, r3 */
/* @0x1f1800 beq 0x1f1828 <_ZN9CTimeLine5ClearEv+0xc0> */
/* @0x1f1804 ldr r3, [r3] */
/* @0x1f1808 cmp r3, r2 */
/* @0x1f180c beq 0x1f1820 <_ZN9CTimeLine5ClearEv+0xb8> */
/* @0x1f1810 ldr r3, [r3, #0x4] */
/* @0x1f1814 blx r3 */
/* @0x1f1818 ldr r1, [r5, #0xc] */
/* @0x1f181c add r1, r1, r7 */
/* @0x1f1820 str r8, [r1] */
/* @0x1f1824 ldr r6, [r5, #0xc] */
/* @0x1f1828 ldr r3, [r5, #0x8] */
/* @0x1f182c add r4, r4, #1 */
/* @0x1f1830 cmp r4, r3 */
/* @0x1f1834 blt 0x1f17d0 <_ZN9CTimeLine5ClearEv+0x68> */
/* @0x1f1838 mov r0, r6 */
/* @0x1f183c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1840 mov r3, #0 */
/* @0x1f1844 str r3, [r5, #0xc] */
/* @0x1f1848 mov r3, #0 */
/* @0x1f184c str r3, [r5, #0x8] */
/* @0x1f1850 ldr r4, [r5, #0x14] */
/* @0x1f1854 subs r0, r4, #0 */
/* @0x1f1858 beq 0x1f1874 <_ZN9CTimeLine5ClearEv+0x10c> */
/* @0x1f185c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1860 mov r3, #0 */
/* @0x1f1864 str r3, [r5, #0x14] */
/* @0x1f1868 mov r3, #0 */
/* @0x1f186c str r3, [r5, #0x10] */
/* @0x1f1870 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f1874 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1878 str r4, [r5, #0x14] */
/* @0x1f187c b 0x1f1868 <_ZN9CTimeLine5ClearEv+0x100> */
/* @0x1f1880 mov r0, r6 */
/* @0x1f1884 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1888 str r6, [r5, #0xc] */
/* @0x1f188c b 0x1f1848 <_ZN9CTimeLine5ClearEv+0xe0> */

/* ── FUNC 0x1f1890 · CTimeLine::~CTimeLine() · size=264 · insn=66 */
/* @0x1f1890 ldr r3, [pc, #0xfc] */
/* @0x1f1894 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f1898 ldr r3, [pc, r3] */
/* @0x1f189c mov r6, r0 */
/* @0x1f18a0 add r3, r3, #8 */
/* @0x1f18a4 str r3, [r0] */
/* @0x1f18a8 bl 0x1f1768 <_ZN9CTimeLine5ClearEv> */
/* @0x1f18ac ldr r4, [r6, #0x14] */
/* @0x1f18b0 subs r0, r4, #0 */
/* @0x1f18b4 beq 0x1f1978 <_ZN9CTimeLineD2Ev+0xe8> */
/* @0x1f18b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f18bc mov r3, #0 */
/* @0x1f18c0 str r3, [r6, #0x14] */
/* @0x1f18c4 ldr r12, [r6, #0x8] */
/* @0x1f18c8 mov r4, #0 */
/* @0x1f18cc str r4, [r6, #0x10] */
/* @0x1f18d0 cmp r12, r4 */
/* @0x1f18d4 beq 0x1f1970 <_ZN9CTimeLineD2Ev+0xe0> */
/* @0x1f18d8 ldr r5, [r6, #0xc] */
/* @0x1f18dc cmp r5, r4 */
/* @0x1f18e0 beq 0x1f1984 <_ZN9CTimeLineD2Ev+0xf4> */
/* @0x1f18e4 cmp r12, r4 */
/* @0x1f18e8 ble 0x1f1958 <_ZN9CTimeLineD2Ev+0xc8> */
/* @0x1f18ec mov r8, r4 */
/* @0x1f18f0 ldr r1, [r5] */
/* @0x1f18f4 movw r3, #0xfeee */
/* @0x1f18f8 movt r3, #0xfeee */
/* @0x1f18fc movw r2, #0xfeee */
/* @0x1f1900 cmp r1, r3 */
/* @0x1f1904 movt r2, #0xfeee */
/* @0x1f1908 lsl r7, r4, #2 */
/* @0x1f190c beq 0x1f194c <_ZN9CTimeLineD2Ev+0xbc> */
/* @0x1f1910 ldr r3, [r5, r4, lsl #2] */
/* @0x1f1914 add r1, r5, r7 */
/* @0x1f1918 cmp r3, #0 */
/* @0x1f191c mov r0, r3 */
/* @0x1f1920 beq 0x1f194c <_ZN9CTimeLineD2Ev+0xbc> */
/* @0x1f1924 ldr r3, [r3] */
/* @0x1f1928 cmp r3, r2 */
/* @0x1f192c beq 0x1f1944 <_ZN9CTimeLineD2Ev+0xb4> */
/* @0x1f1930 ldr r3, [r3, #0x4] */
/* @0x1f1934 blx r3 */
/* @0x1f1938 ldr r1, [r6, #0xc] */
/* @0x1f193c ldr r12, [r6, #0x8] */
/* @0x1f1940 add r1, r1, r7 */
/* @0x1f1944 str r8, [r1] */
/* @0x1f1948 ldr r5, [r6, #0xc] */
/* @0x1f194c add r4, r4, #1 */
/* @0x1f1950 cmp r4, r12 */
/* @0x1f1954 blt 0x1f18f0 <_ZN9CTimeLineD2Ev+0x60> */
/* @0x1f1958 mov r0, r5 */
/* @0x1f195c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1960 mov r3, #0 */
/* @0x1f1964 str r3, [r6, #0xc] */
/* @0x1f1968 mov r3, #0 */
/* @0x1f196c str r3, [r6, #0x8] */
/* @0x1f1970 mov r0, r6 */
/* @0x1f1974 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f1978 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f197c str r4, [r6, #0x14] */
/* @0x1f1980 b 0x1f18c4 <_ZN9CTimeLineD2Ev+0x34> */
/* @0x1f1984 mov r0, r5 */
/* @0x1f1988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f198c str r5, [r6, #0xc] */
/* @0x1f1990 b 0x1f1968 <_ZN9CTimeLineD2Ev+0xd8> */
/* @0x1f1994 andseq pc, pc, r12, lsl #11 */

/* ── FUNC 0x1f1890 · CTimeLine::~CTimeLine() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f1998 · CTimeLine::~CTimeLine() · size=28 · insn=7 */
/* @0x1f1998 push {r4, lr} */
/* @0x1f199c mov r4, r0 */
/* @0x1f19a0 bl 0x1f1890 <_ZN9CTimeLineD2Ev> */
/* @0x1f19a4 mov r0, r4 */
/* @0x1f19a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f19ac mov r0, r4 */
/* @0x1f19b0 pop {r4, pc} */

/* ── FUNC 0x1f19b4 · CTimeLine::LoadFromChunk(YYTimeline*, unsigned char*) · size=512 · insn=128 */
/* @0x1f19b4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1f19b8 mov r9, r1 */
/* @0x1f19bc mov r6, r0 */
/* @0x1f19c0 sub sp, sp, #8 */
/* @0x1f19c4 mov r10, r2 */
/* @0x1f19c8 bl 0x1f1768 <_ZN9CTimeLine5ClearEv> */
/* @0x1f19cc ldr r5, [r9, #0x4] */
/* @0x1f19d0 ldr r12, [r6, #0x8] */
/* @0x1f19d4 cmp r5, r12 */
/* @0x1f19d8 beq 0x1f1a80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xcc> */
/* @0x1f19dc cmp r5, #0 */
/* @0x1f19e0 bne 0x1f1b4c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x198> */
/* @0x1f19e4 ldr r3, [r6, #0xc] */
/* @0x1f19e8 cmp r3, #0 */
/* @0x1f19ec beq 0x1f1a68 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xb4> */
/* @0x1f19f0 cmp r12, #0 */
/* @0x1f19f4 ble 0x1f1a68 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xb4> */
/* @0x1f19f8 mov r4, r5 */
/* @0x1f19fc mov r8, r5 */
/* @0x1f1a00 ldr r0, [r3] */
/* @0x1f1a04 movw r2, #0xfeee */
/* @0x1f1a08 movt r2, #0xfeee */
/* @0x1f1a0c movw r1, #0xfeee */
/* @0x1f1a10 cmp r0, r2 */
/* @0x1f1a14 movt r1, #0xfeee */
/* @0x1f1a18 lsl r7, r4, #2 */
/* @0x1f1a1c beq 0x1f1a5c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa8> */
/* @0x1f1a20 ldr r2, [r3, r4, lsl #2] */
/* @0x1f1a24 add lr, r3, r7 */
/* @0x1f1a28 cmp r2, #0 */
/* @0x1f1a2c mov r0, r2 */
/* @0x1f1a30 beq 0x1f1a5c <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa8> */
/* @0x1f1a34 ldr r3, [r2] */
/* @0x1f1a38 cmp r3, r1 */
/* @0x1f1a3c beq 0x1f1a54 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xa0> */
/* @0x1f1a40 ldr r3, [r3, #0x4] */
/* @0x1f1a44 blx r3 */
/* @0x1f1a48 ldr lr, [r6, #0xc] */
/* @0x1f1a4c ldr r12, [r6, #0x8] */
/* @0x1f1a50 add lr, lr, r7 */
/* @0x1f1a54 str r8, [lr] */
/* @0x1f1a58 ldr r3, [r6, #0xc] */
/* @0x1f1a5c add r4, r4, #1 */
/* @0x1f1a60 cmp r4, r12 */
/* @0x1f1a64 blt 0x1f1a00 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x4c> */
/* @0x1f1a68 mov r0, r3 */
/* @0x1f1a6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1a70 mov r3, #0 */
/* @0x1f1a74 str r3, [r6, #0xc] */
/* @0x1f1a78 str r5, [r6, #0x8] */
/* @0x1f1a7c ldr r5, [r9, #0x4] */
/* @0x1f1a80 cmp r5, #0 */
/* @0x1f1a84 ldr r0, [r6, #0x14] */
/* @0x1f1a88 bne 0x1f1aa0 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xec> */
/* @0x1f1a8c cmp r0, #0 */
/* @0x1f1a90 beq 0x1f1b80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1cc> */
/* @0x1f1a94 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1a98 str r5, [r6, #0x14] */
/* @0x1f1a9c b 0x1f1ac4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x110> */
/* @0x1f1aa0 lsls r1, r5, #2 */
/* @0x1f1aa4 beq 0x1f1b80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1cc> */
/* @0x1f1aa8 ldr r2, [pc, #0xf8] */
/* @0x1f1aac mov r3, #0 */
/* @0x1f1ab0 str r3, [sp] */
/* @0x1f1ab4 mov r3, #106 */
/* @0x1f1ab8 add r2, pc, r2 */
/* @0x1f1abc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f1ac0 str r0, [r6, #0x14] */
/* @0x1f1ac4 ldr r3, [r9, #0x4] */
/* @0x1f1ac8 str r5, [r6, #0x10] */
/* @0x1f1acc cmp r3, #0 */
/* @0x1f1ad0 ble 0x1f1b40 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x18c> */
/* @0x1f1ad4 add r5, r9, #16 */
/* @0x1f1ad8 mov r4, #0 */
/* @0x1f1adc ldr r2, [r5, #-0x8] */
/* @0x1f1ae0 mov r0, #12 */
/* @0x1f1ae4 ldr r3, [r6, #0x14] */
/* @0x1f1ae8 lsl r8, r4, #2 */
/* @0x1f1aec add r5, r5, #8 */
/* @0x1f1af0 str r2, [r3, r4, lsl #2] */
/* @0x1f1af4 add r4, r4, #1 */
/* @0x1f1af8 bl 0x27c524 <_Znwj> */
/* @0x1f1afc mov r7, r0 */
/* @0x1f1b00 bl 0xf2d0c <_ZN6CEventC2Ev> */
/* @0x1f1b04 ldr r3, [r5, #-0xc] */
/* @0x1f1b08 mov r0, r7 */
/* @0x1f1b0c ldr r2, [pc, #0x98] */
/* @0x1f1b10 cmp r3, #0 */
/* @0x1f1b14 ldrne r2, [pc, r2] */
/* @0x1f1b18 mov r1, r3 */
/* @0x1f1b1c ldrne r1, [r2] */
/* @0x1f1b20 mov r2, r10 */
/* @0x1f1b24 addne r1, r1, r3 */
/* @0x1f1b28 bl 0xf2d84 <_ZN6CEvent13LoadFromChunkEP7YYEventPh> */
/* @0x1f1b2c ldr r2, [r9, #0x4] */
/* @0x1f1b30 ldr r3, [r6, #0xc] */
/* @0x1f1b34 cmp r2, r4 */
/* @0x1f1b38 str r7, [r3, r8] */
/* @0x1f1b3c bgt 0x1f1adc <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x128> */
/* @0x1f1b40 mov r0, #1 */
/* @0x1f1b44 add sp, sp, #8 */
/* @0x1f1b48 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f1b4c lsls r1, r5, #2 */
/* @0x1f1b50 beq 0x1f1b90 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x1dc> */
/* @0x1f1b54 ldr r2, [pc, #0x54] */
/* @0x1f1b58 mov r3, #0 */
/* @0x1f1b5c ldr r0, [r6, #0xc] */
/* @0x1f1b60 add r2, pc, r2 */
/* @0x1f1b64 str r3, [sp] */
/* @0x1f1b68 mov r3, #135 */
/* @0x1f1b6c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f1b70 str r5, [r6, #0x8] */
/* @0x1f1b74 ldr r5, [r9, #0x4] */
/* @0x1f1b78 str r0, [r6, #0xc] */
/* @0x1f1b7c b 0x1f1a80 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xcc> */
/* @0x1f1b80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1b84 mov r3, #0 */
/* @0x1f1b88 str r3, [r6, #0x14] */
/* @0x1f1b8c b 0x1f1ac4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0x110> */
/* @0x1f1b90 ldr r3, [r6, #0xc] */
/* @0x1f1b94 mov r0, r3 */
/* @0x1f1b98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1b9c mov r3, #0 */
/* @0x1f1ba0 str r3, [r6, #0xc] */
/* @0x1f1ba4 b 0x1f1a78 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh+0xc4> */
/* @0x1f1ba8 andseq r0, r6, r12, lsl r12 */
/* @0x1f1bac andseq r11, pc, r0, lsr lr */
/* @0x1f1bb0 andseq r0, r6, r0, lsr r11 */

/* ── FUNC 0x1f1bb4 · CTimeLine::Compile() · size=116 · insn=29 */
/* @0x1f1bb4 ldr r3, [pc, #0x64] */
/* @0x1f1bb8 movw r2, #0x86a0 */
/* @0x1f1bbc ldr r1, [r0, #0x8] */
/* @0x1f1bc0 movt r2, #0x1 */
/* @0x1f1bc4 ldr r3, [pc, r3] */
/* @0x1f1bc8 cmp r1, #0 */
/* @0x1f1bcc push {r4, r5, r6, lr} */
/* @0x1f1bd0 mov r5, r0 */
/* @0x1f1bd4 str r2, [r3] */
/* @0x1f1bd8 ble 0x1f1c18 <_ZN9CTimeLine7CompileEv+0x64> */
/* @0x1f1bdc ldr r6, [pc, #0x40] */
/* @0x1f1be0 mov r4, #0 */
/* @0x1f1be4 ldr r6, [pc, r6] */
/* @0x1f1be8 ldr r3, [r5, #0x14] */
/* @0x1f1bec ldr r2, [r5, #0xc] */
/* @0x1f1bf0 ldr r3, [r3, r4, lsl #2] */
/* @0x1f1bf4 ldr r0, [r2, r4, lsl #2] */
/* @0x1f1bf8 add r4, r4, #1 */
/* @0x1f1bfc str r3, [r6] */
/* @0x1f1c00 bl 0xf2e10 <_ZN6CEvent7CompileEv> */
/* @0x1f1c04 cmp r0, #0 */
/* @0x1f1c08 popeq {r4, r5, r6, pc} */
/* @0x1f1c0c ldr r3, [r5, #0x8] */
/* @0x1f1c10 cmp r3, r4 */
/* @0x1f1c14 bgt 0x1f1be8 <_ZN9CTimeLine7CompileEv+0x34> */
/* @0x1f1c18 mov r0, #1 */
/* @0x1f1c1c pop {r4, r5, r6, pc} */
/* @0x1f1c20 andseq r12, pc, r12, ror #3 */
/* @0x1f1c24 ldrsbeq r12, [pc], -r0 */

/* ── FUNC 0x1f1c28 · CTimeLine::Find(int) · size=72 · insn=18 */
/* @0x1f1c28 ldr r12, [r0, #0x10] */
/* @0x1f1c2c cmp r12, #0 */
/* @0x1f1c30 ble 0x1f1c64 <_ZN9CTimeLine4FindEi+0x3c> */
/* @0x1f1c34 ldr r3, [r0, #0x14] */
/* @0x1f1c38 mov r0, #0 */
/* @0x1f1c3c ldr r2, [r3] */
/* @0x1f1c40 cmp r2, r1 */
/* @0x1f1c44 bne 0x1f1c58 <_ZN9CTimeLine4FindEi+0x30> */
/* @0x1f1c48 b 0x1f1c6c <_ZN9CTimeLine4FindEi+0x44> */
/* @0x1f1c4c ldr r2, [r3, #0x4]! */
/* @0x1f1c50 cmp r2, r1 */
/* @0x1f1c54 bxeq lr */
/* @0x1f1c58 add r0, r0, #1 */
/* @0x1f1c5c cmp r0, r12 */
/* @0x1f1c60 bne 0x1f1c4c <_ZN9CTimeLine4FindEi+0x24> */
/* @0x1f1c64 mvn r0, #0 */
/* @0x1f1c68 bx lr */
/* @0x1f1c6c bx lr */

/* ── FUNC 0x1f1c70 · CTimeLine::FindLarger(double) · size=148 · insn=37 */
/* @0x1f1c70 vmov d6, r2, r3 */
/* @0x1f1c74 ldr r2, [r0, #0x10] */
/* @0x1f1c78 cmp r2, #0 */
/* @0x1f1c7c beq 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78> */
/* @0x1f1c80 ldr r1, [r0, #0x14] */
/* @0x1f1c84 sub r3, r2, #1 */
/* @0x1f1c88 ldr r3, [r1, r3, lsl #2] */
/* @0x1f1c8c vmov s14, r3 */
/* @0x1f1c90 vcvt.f64.s32 d7, s14 */
/* @0x1f1c94 vcmpe.f64 d7, d6 */
/* @0x1f1c98 vmrs APSR_nzcv, fpscr */
/* @0x1f1c9c bmi 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78> */
/* @0x1f1ca0 cmp r2, #0 */
/* @0x1f1ca4 ble 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78> */
/* @0x1f1ca8 vldr s11, [r1] */
/* @0x1f1cac vcvt.f64.s32 d7, s11 */
/* @0x1f1cb0 vcmpe.f64 d6, d7 */
/* @0x1f1cb4 vmrs APSR_nzcv, fpscr */
/* @0x1f1cb8 bls 0x1f1cfc <_ZN9CTimeLine10FindLargerEd+0x8c> */
/* @0x1f1cbc mov r3, #0 */
/* @0x1f1cc0 b 0x1f1cdc <_ZN9CTimeLine10FindLargerEd+0x6c> */
/* @0x1f1cc4 ldr r0, [r1, #0x4]! */
/* @0x1f1cc8 vmov s14, r0 */
/* @0x1f1ccc vcvt.f64.s32 d7, s14 */
/* @0x1f1cd0 vcmpe.f64 d6, d7 */
/* @0x1f1cd4 vmrs APSR_nzcv, fpscr */
/* @0x1f1cd8 bls 0x1f1cf0 <_ZN9CTimeLine10FindLargerEd+0x80> */
/* @0x1f1cdc add r3, r3, #1 */
/* @0x1f1ce0 cmp r3, r2 */
/* @0x1f1ce4 bne 0x1f1cc4 <_ZN9CTimeLine10FindLargerEd+0x54> */
/* @0x1f1ce8 mov r0, r2 */
/* @0x1f1cec bx lr */
/* @0x1f1cf0 mov r2, r3 */
/* @0x1f1cf4 mov r0, r2 */
/* @0x1f1cf8 bx lr */
/* @0x1f1cfc mov r2, #0 */
/* @0x1f1d00 b 0x1f1ce8 <_ZN9CTimeLine10FindLargerEd+0x78> */

/* ── FUNC 0x1f1d04 · CTimeLine::FindSmaller(double) · size=124 · insn=31 */
/* @0x1f1d04 vmov d6, r2, r3 */
/* @0x1f1d08 ldr r2, [r0, #0x10] */
/* @0x1f1d0c cmp r2, #0 */
/* @0x1f1d10 beq 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74> */
/* @0x1f1d14 ldr r3, [r0, #0x14] */
/* @0x1f1d18 vldr s11, [r3] */
/* @0x1f1d1c vcvt.f64.s32 d7, s11 */
/* @0x1f1d20 vcmpe.f64 d7, d6 */
/* @0x1f1d24 vmrs APSR_nzcv, fpscr */
/* @0x1f1d28 bgt 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74> */
/* @0x1f1d2c subs r0, r2, #1 */
/* @0x1f1d30 bmi 0x1f1d78 <_ZN9CTimeLine11FindSmallerEd+0x74> */
/* @0x1f1d34 ldr r1, [r3, r0, lsl #2] */
/* @0x1f1d38 lsl r2, r0, #2 */
/* @0x1f1d3c vmov s11, r1 */
/* @0x1f1d40 vcvt.f64.s32 d7, s11 */
/* @0x1f1d44 vcmpe.f64 d6, d7 */
/* @0x1f1d48 vmrs APSR_nzcv, fpscr */
/* @0x1f1d4c bxge lr */
/* @0x1f1d50 add r3, r3, r2 */
/* @0x1f1d54 b 0x1f1d6c <_ZN9CTimeLine11FindSmallerEd+0x68> */
/* @0x1f1d58 vldmdb r3!, {s14} */
/* @0x1f1d5c vcvt.f64.s32 d7, s14 */
/* @0x1f1d60 vcmpe.f64 d6, d7 */
/* @0x1f1d64 vmrs APSR_nzcv, fpscr */
/* @0x1f1d68 bxge lr */
/* @0x1f1d6c subs r0, r0, #1 */
/* @0x1f1d70 bhs 0x1f1d58 <_ZN9CTimeLine11FindSmallerEd+0x54> */
/* @0x1f1d74 bx lr */
/* @0x1f1d78 mvn r0, #0 */
/* @0x1f1d7c bx lr */

/* ── FUNC 0x1f1d80 · CTimeLine::AddMomentScript(int, int) · size=540 · insn=135 */
/* @0x1f1d80 vmov s15, r1 */
/* @0x1f1d84 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f1d88 vcvt.f64.s32 d7, s15 */
/* @0x1f1d8c sub sp, sp, #12 */
/* @0x1f1d90 mov r7, r2 */
/* @0x1f1d94 mov r8, r1 */
/* @0x1f1d98 mov r5, r0 */
/* @0x1f1d9c vmov r2, r3, d7 */
/* @0x1f1da0 bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd> */
/* @0x1f1da4 cmn r0, #1 */
/* @0x1f1da8 beq 0x1f1db8 <_ZN9CTimeLine15AddMomentScriptEii+0x38> */
/* @0x1f1dac ldr r4, [r5, #0x10] */
/* @0x1f1db0 cmp r0, r4 */
/* @0x1f1db4 blt 0x1f1f0c <_ZN9CTimeLine15AddMomentScriptEii+0x18c> */
/* @0x1f1db8 ldr r4, [r5, #0x10] */
/* @0x1f1dbc add r6, r0, #1 */
/* @0x1f1dc0 ldr r3, [r5, #0x14] */
/* @0x1f1dc4 adds r9, r4, #1 */
/* @0x1f1dc8 beq 0x1f1f28 <_ZN9CTimeLine15AddMomentScriptEii+0x1a8> */
/* @0x1f1dcc lsls r1, r9, #2 */
/* @0x1f1dd0 beq 0x1f1f74 <_ZN9CTimeLine15AddMomentScriptEii+0x1f4> */
/* @0x1f1dd4 ldr r2, [pc, #0x1b8] */
/* @0x1f1dd8 mov r0, r3 */
/* @0x1f1ddc mov r3, #0 */
/* @0x1f1de0 str r3, [sp] */
/* @0x1f1de4 add r2, pc, r2 */
/* @0x1f1de8 mov r3, #106 */
/* @0x1f1dec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f1df0 mov r2, r0 */
/* @0x1f1df4 str r0, [r5, #0x14] */
/* @0x1f1df8 cmp r6, r4 */
/* @0x1f1dfc str r9, [r5, #0x10] */
/* @0x1f1e00 addlt r3, r2, r4, lsl #2 */
/* @0x1f1e04 bge 0x1f1e1c <_ZN9CTimeLine15AddMomentScriptEii+0x9c> */
/* @0x1f1e08 sub r4, r4, #1 */
/* @0x1f1e0c ldr r0, [r3, #-0x4] */
/* @0x1f1e10 cmp r4, r6 */
/* @0x1f1e14 str r0, [r3], #-4 */
/* @0x1f1e18 bne 0x1f1e08 <_ZN9CTimeLine15AddMomentScriptEii+0x88> */
/* @0x1f1e1c str r8, [r2, r6, lsl #2] */
/* @0x1f1e20 lsl r7, r7, #1 */
/* @0x1f1e24 ldr r4, [r5, #0x8] */
/* @0x1f1e28 orr r7, r7, #1 */
/* @0x1f1e2c adds r9, r4, #1 */
/* @0x1f1e30 mov r12, r4 */
/* @0x1f1e34 bne 0x1f1f44 <_ZN9CTimeLine15AddMomentScriptEii+0x1c4> */
/* @0x1f1e38 ldr r3, [r5, #0xc] */
/* @0x1f1e3c cmp r3, #0 */
/* @0x1f1e40 beq 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c> */
/* @0x1f1e44 cmp r4, #0 */
/* @0x1f1e48 ble 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c> */
/* @0x1f1e4c mov r8, r9 */
/* @0x1f1e50 mov r11, r9 */
/* @0x1f1e54 ldr r0, [r3] */
/* @0x1f1e58 movw r2, #0xfeee */
/* @0x1f1e5c movt r2, #0xfeee */
/* @0x1f1e60 movw r1, #0xfeee */
/* @0x1f1e64 cmp r0, r2 */
/* @0x1f1e68 movt r1, #0xfeee */
/* @0x1f1e6c lsl r10, r8, #2 */
/* @0x1f1e70 beq 0x1f1eb0 <_ZN9CTimeLine15AddMomentScriptEii+0x130> */
/* @0x1f1e74 ldr r2, [r3, r8, lsl #2] */
/* @0x1f1e78 add lr, r3, r10 */
/* @0x1f1e7c cmp r2, #0 */
/* @0x1f1e80 mov r0, r2 */
/* @0x1f1e84 beq 0x1f1eb0 <_ZN9CTimeLine15AddMomentScriptEii+0x130> */
/* @0x1f1e88 ldr r3, [r2] */
/* @0x1f1e8c cmp r3, r1 */
/* @0x1f1e90 beq 0x1f1ea8 <_ZN9CTimeLine15AddMomentScriptEii+0x128> */
/* @0x1f1e94 ldr r3, [r3, #0x4] */
/* @0x1f1e98 blx r3 */
/* @0x1f1e9c ldr lr, [r5, #0xc] */
/* @0x1f1ea0 ldr r12, [r5, #0x8] */
/* @0x1f1ea4 add lr, lr, r10 */
/* @0x1f1ea8 str r11, [lr] */
/* @0x1f1eac ldr r3, [r5, #0xc] */
/* @0x1f1eb0 add r8, r8, #1 */
/* @0x1f1eb4 cmp r8, r12 */
/* @0x1f1eb8 blt 0x1f1e54 <_ZN9CTimeLine15AddMomentScriptEii+0xd4> */
/* @0x1f1ebc mov r0, r3 */
/* @0x1f1ec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1ec4 mov r3, #0 */
/* @0x1f1ec8 mov r1, r3 */
/* @0x1f1ecc str r3, [r5, #0xc] */
/* @0x1f1ed0 cmp r6, r4 */
/* @0x1f1ed4 str r9, [r5, #0x8] */
/* @0x1f1ed8 bge 0x1f1f00 <_ZN9CTimeLine15AddMomentScriptEii+0x180> */
/* @0x1f1edc lsl r3, r4, #2 */
/* @0x1f1ee0 add r0, r1, r3 */
/* @0x1f1ee4 sub r4, r4, #1 */
/* @0x1f1ee8 cmp r4, r6 */
/* @0x1f1eec ldr r0, [r0, #-0x4] */
/* @0x1f1ef0 str r0, [r1, r3] */
/* @0x1f1ef4 sub r3, r3, #4 */
/* @0x1f1ef8 ldr r1, [r5, #0xc] */
/* @0x1f1efc bne 0x1f1ee0 <_ZN9CTimeLine15AddMomentScriptEii+0x160> */
/* @0x1f1f00 str r7, [r1, r6, lsl #2] */
/* @0x1f1f04 add sp, sp, #12 */
/* @0x1f1f08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f1f0c ldr r3, [r5, #0x14] */
/* @0x1f1f10 ldr r2, [r3, r0, lsl #2] */
/* @0x1f1f14 cmp r2, r8 */
/* @0x1f1f18 beq 0x1f1f04 <_ZN9CTimeLine15AddMomentScriptEii+0x184> */
/* @0x1f1f1c adds r9, r4, #1 */
/* @0x1f1f20 add r6, r0, #1 */
/* @0x1f1f24 bne 0x1f1dcc <_ZN9CTimeLine15AddMomentScriptEii+0x4c> */
/* @0x1f1f28 cmp r3, #0 */
/* @0x1f1f2c beq 0x1f1f74 <_ZN9CTimeLine15AddMomentScriptEii+0x1f4> */
/* @0x1f1f30 mov r0, r3 */
/* @0x1f1f34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1f38 str r9, [r5, #0x14] */
/* @0x1f1f3c mov r2, r9 */
/* @0x1f1f40 b 0x1f1df8 <_ZN9CTimeLine15AddMomentScriptEii+0x78> */
/* @0x1f1f44 lsls r1, r9, #2 */
/* @0x1f1f48 beq 0x1f1f8c <_ZN9CTimeLine15AddMomentScriptEii+0x20c> */
/* @0x1f1f4c ldr r2, [pc, #0x44] */
/* @0x1f1f50 mov r3, #0 */
/* @0x1f1f54 ldr r0, [r5, #0xc] */
/* @0x1f1f58 add r2, pc, r2 */
/* @0x1f1f5c str r3, [sp] */
/* @0x1f1f60 mov r3, #135 */
/* @0x1f1f64 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f1f68 mov r1, r0 */
/* @0x1f1f6c str r0, [r5, #0xc] */
/* @0x1f1f70 b 0x1f1ed0 <_ZN9CTimeLine15AddMomentScriptEii+0x150> */
/* @0x1f1f74 mov r0, r3 */
/* @0x1f1f78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f1f7c mov r3, #0 */
/* @0x1f1f80 mov r2, r3 */
/* @0x1f1f84 str r3, [r5, #0x14] */
/* @0x1f1f88 b 0x1f1df8 <_ZN9CTimeLine15AddMomentScriptEii+0x78> */
/* @0x1f1f8c ldr r3, [r5, #0xc] */
/* @0x1f1f90 b 0x1f1ebc <_ZN9CTimeLine15AddMomentScriptEii+0x13c> */
/* @0x1f1f94 ldrsheq r0, [r6], -r0 */
/* @0x1f1f98 andseq r0, r6, r8, lsr r7 */

/* ── FUNC 0x1f1f9c · CTimeLine::MakeMomentScript(int, int) · size=124 · insn=31 */
/* @0x1f1f9c vmov s15, r1 */
/* @0x1f1fa0 push {r4, r5, lr} */
/* @0x1f1fa4 vcvt.f64.s32 d7, s15 */
/* @0x1f1fa8 sub sp, sp, #12 */
/* @0x1f1fac mov r5, r2 */
/* @0x1f1fb0 mov r4, r0 */
/* @0x1f1fb4 str r1, [sp, #0x4] */
/* @0x1f1fb8 vmov r2, r3, d7 */
/* @0x1f1fbc bl 0x1f1d04 <_ZN9CTimeLine11FindSmallerEd> */
/* @0x1f1fc0 ldr r1, [sp, #0x4] */
/* @0x1f1fc4 cmn r0, #1 */
/* @0x1f1fc8 beq 0x1f2010 <_ZN9CTimeLine16MakeMomentScriptEii+0x74> */
/* @0x1f1fcc ldr r3, [r4, #0x10] */
/* @0x1f1fd0 cmp r0, r3 */
/* @0x1f1fd4 lslge r3, r0, #2 */
/* @0x1f1fd8 blt 0x1f1ff4 <_ZN9CTimeLine16MakeMomentScriptEii+0x58> */
/* @0x1f1fdc ldr r2, [r4, #0xc] */
/* @0x1f1fe0 lsl r5, r5, #1 */
/* @0x1f1fe4 orr r5, r5, #1 */
/* @0x1f1fe8 str r5, [r2, r3] */
/* @0x1f1fec add sp, sp, #12 */
/* @0x1f1ff0 pop {r4, r5, pc} */
/* @0x1f1ff4 ldr r2, [r4, #0x14] */
/* @0x1f1ff8 lsl r3, r0, #2 */
/* @0x1f1ffc ldr r2, [r2, r0, lsl #2] */
/* @0x1f2000 cmp r2, r1 */
/* @0x1f2004 bne 0x1f1fdc <_ZN9CTimeLine16MakeMomentScriptEii+0x40> */
/* @0x1f2008 add sp, sp, #12 */
/* @0x1f200c pop {r4, r5, pc} */
/* @0x1f2010 mov r3, #0 */
/* @0x1f2014 b 0x1f1fdc <_ZN9CTimeLine16MakeMomentScriptEii+0x40> */

/* ── FUNC 0x1f2018 · CTimeLine::AddMoment(int) · size=568 · insn=142 */
/* @0x1f2018 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f201c mov r7, r0 */
/* @0x1f2020 ldr r5, [r0, #0x10] */
/* @0x1f2024 sub sp, sp, #20 */
/* @0x1f2028 mov r8, r1 */
/* @0x1f202c cmp r5, #0 */
/* @0x1f2030 ble 0x1f2238 <_ZN9CTimeLine9AddMomentEi+0x220> */
/* @0x1f2034 ldr r0, [r0, #0x14] */
/* @0x1f2038 ldr r3, [r0] */
/* @0x1f203c cmp r1, r3 */
/* @0x1f2040 ble 0x1f21bc <_ZN9CTimeLine9AddMomentEi+0x1a4> */
/* @0x1f2044 mov r2, r0 */
/* @0x1f2048 mov r4, #0 */
/* @0x1f204c b 0x1f205c <_ZN9CTimeLine9AddMomentEi+0x44> */
/* @0x1f2050 ldr r3, [r2, #0x4]! */
/* @0x1f2054 cmp r3, r8 */
/* @0x1f2058 bge 0x1f21c4 <_ZN9CTimeLine9AddMomentEi+0x1ac> */
/* @0x1f205c add r4, r4, #1 */
/* @0x1f2060 cmp r4, r5 */
/* @0x1f2064 lsl r6, r4, #2 */
/* @0x1f2068 bne 0x1f2050 <_ZN9CTimeLine9AddMomentEi+0x38> */
/* @0x1f206c adds r9, r5, #1 */
/* @0x1f2070 beq 0x1f21d4 <_ZN9CTimeLine9AddMomentEi+0x1bc> */
/* @0x1f2074 lsls r1, r9, #2 */
/* @0x1f2078 beq 0x1f221c <_ZN9CTimeLine9AddMomentEi+0x204> */
/* @0x1f207c ldr r2, [pc, #0x1c4] */
/* @0x1f2080 mov r3, #0 */
/* @0x1f2084 str r3, [sp] */
/* @0x1f2088 mov r3, #106 */
/* @0x1f208c add r2, pc, r2 */
/* @0x1f2090 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f2094 mov r12, r0 */
/* @0x1f2098 str r0, [r7, #0x14] */
/* @0x1f209c cmp r5, r4 */
/* @0x1f20a0 str r9, [r7, #0x10] */
/* @0x1f20a4 addgt r3, r12, r5, lsl #2 */
/* @0x1f20a8 addgt r1, r12, r4, lsl #2 */
/* @0x1f20ac ble 0x1f20c0 <_ZN9CTimeLine9AddMomentEi+0xa8> */
/* @0x1f20b0 ldr r2, [r3, #-0x4] */
/* @0x1f20b4 str r2, [r3], #-4 */
/* @0x1f20b8 cmp r3, r1 */
/* @0x1f20bc bne 0x1f20b0 <_ZN9CTimeLine9AddMomentEi+0x98> */
/* @0x1f20c0 str r8, [r12, r6] */
/* @0x1f20c4 mov r0, #12 */
/* @0x1f20c8 bl 0x27c524 <_Znwj> */
/* @0x1f20cc str r0, [sp, #0xc] */
/* @0x1f20d0 bl 0xf2d0c <_ZN6CEventC2Ev> */
/* @0x1f20d4 ldr r5, [r7, #0x8] */
/* @0x1f20d8 adds r9, r5, #1 */
/* @0x1f20dc mov lr, r5 */
/* @0x1f20e0 bne 0x1f21ec <_ZN9CTimeLine9AddMomentEi+0x1d4> */
/* @0x1f20e4 ldr r3, [r7, #0xc] */
/* @0x1f20e8 cmp r3, #0 */
/* @0x1f20ec beq 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150> */
/* @0x1f20f0 cmp r5, #0 */
/* @0x1f20f4 ble 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150> */
/* @0x1f20f8 mov r8, r9 */
/* @0x1f20fc mov r11, r9 */
/* @0x1f2100 ldr r0, [r3] */
/* @0x1f2104 movw r2, #0xfeee */
/* @0x1f2108 movt r2, #0xfeee */
/* @0x1f210c movw r1, #0xfeee */
/* @0x1f2110 cmp r0, r2 */
/* @0x1f2114 movt r1, #0xfeee */
/* @0x1f2118 lsl r10, r8, #2 */
/* @0x1f211c beq 0x1f215c <_ZN9CTimeLine9AddMomentEi+0x144> */
/* @0x1f2120 ldr r2, [r3, r8, lsl #2] */
/* @0x1f2124 add r12, r3, r10 */
/* @0x1f2128 cmp r2, #0 */
/* @0x1f212c mov r0, r2 */
/* @0x1f2130 beq 0x1f215c <_ZN9CTimeLine9AddMomentEi+0x144> */
/* @0x1f2134 ldr r3, [r2] */
/* @0x1f2138 cmp r3, r1 */
/* @0x1f213c beq 0x1f2154 <_ZN9CTimeLine9AddMomentEi+0x13c> */
/* @0x1f2140 ldr r3, [r3, #0x4] */
/* @0x1f2144 blx r3 */
/* @0x1f2148 ldr r12, [r7, #0xc] */
/* @0x1f214c ldr lr, [r7, #0x8] */
/* @0x1f2150 add r12, r12, r10 */
/* @0x1f2154 str r11, [r12] */
/* @0x1f2158 ldr r3, [r7, #0xc] */
/* @0x1f215c add r8, r8, #1 */
/* @0x1f2160 cmp r8, lr */
/* @0x1f2164 blt 0x1f2100 <_ZN9CTimeLine9AddMomentEi+0xe8> */
/* @0x1f2168 mov r0, r3 */
/* @0x1f216c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2170 mov r3, #0 */
/* @0x1f2174 mov r2, r3 */
/* @0x1f2178 str r3, [r7, #0xc] */
/* @0x1f217c cmp r5, r4 */
/* @0x1f2180 str r9, [r7, #0x8] */
/* @0x1f2184 ble 0x1f21ac <_ZN9CTimeLine9AddMomentEi+0x194> */
/* @0x1f2188 lsl r3, r5, #2 */
/* @0x1f218c add r1, r2, r3 */
/* @0x1f2190 sub r5, r5, #1 */
/* @0x1f2194 cmp r5, r4 */
/* @0x1f2198 ldr r1, [r1, #-0x4] */
/* @0x1f219c str r1, [r2, r3] */
/* @0x1f21a0 sub r3, r3, #4 */
/* @0x1f21a4 ldr r2, [r7, #0xc] */
/* @0x1f21a8 bne 0x1f218c <_ZN9CTimeLine9AddMomentEi+0x174> */
/* @0x1f21ac ldr r3, [sp, #0xc] */
/* @0x1f21b0 str r3, [r2, r6] */
/* @0x1f21b4 add sp, sp, #20 */
/* @0x1f21b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f21bc mov r6, #0 */
/* @0x1f21c0 mov r4, r6 */
/* @0x1f21c4 cmp r8, r3 */
/* @0x1f21c8 beq 0x1f21b4 <_ZN9CTimeLine9AddMomentEi+0x19c> */
/* @0x1f21cc adds r9, r5, #1 */
/* @0x1f21d0 bne 0x1f2074 <_ZN9CTimeLine9AddMomentEi+0x5c> */
/* @0x1f21d4 cmp r0, #0 */
/* @0x1f21d8 beq 0x1f221c <_ZN9CTimeLine9AddMomentEi+0x204> */
/* @0x1f21dc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f21e0 str r9, [r7, #0x14] */
/* @0x1f21e4 mov r12, r9 */
/* @0x1f21e8 b 0x1f209c <_ZN9CTimeLine9AddMomentEi+0x84> */
/* @0x1f21ec lsls r1, r9, #2 */
/* @0x1f21f0 beq 0x1f2230 <_ZN9CTimeLine9AddMomentEi+0x218> */
/* @0x1f21f4 ldr r2, [pc, #0x50] */
/* @0x1f21f8 mov r3, #0 */
/* @0x1f21fc ldr r0, [r7, #0xc] */
/* @0x1f2200 add r2, pc, r2 */
/* @0x1f2204 str r3, [sp] */
/* @0x1f2208 mov r3, #135 */
/* @0x1f220c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f2210 mov r2, r0 */
/* @0x1f2214 str r0, [r7, #0xc] */
/* @0x1f2218 b 0x1f217c <_ZN9CTimeLine9AddMomentEi+0x164> */
/* @0x1f221c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2220 mov r3, #0 */
/* @0x1f2224 mov r12, r3 */
/* @0x1f2228 str r3, [r7, #0x14] */
/* @0x1f222c b 0x1f209c <_ZN9CTimeLine9AddMomentEi+0x84> */
/* @0x1f2230 ldr r3, [r7, #0xc] */
/* @0x1f2234 b 0x1f2168 <_ZN9CTimeLine9AddMomentEi+0x150> */
/* @0x1f2238 lsl r6, r5, #2 */
/* @0x1f223c ldr r0, [r0, #0x14] */
/* @0x1f2240 mov r4, r5 */
/* @0x1f2244 b 0x1f206c <_ZN9CTimeLine9AddMomentEi+0x54> */
/* @0x1f2248 andseq r0, r6, r8, asr #12 */
/* @0x1f224c mulseq r6, r0, r4 */

/* ── FUNC 0x1f2250 · CTimeLine::DeleteMoment(int) · size=460 · insn=115 */
/* @0x1f2250 push {r4, r5, r6, r7, lr} */
/* @0x1f2254 mov r6, r0 */
/* @0x1f2258 ldr r5, [r0, #0x10] */
/* @0x1f225c sub sp, sp, #12 */
/* @0x1f2260 cmp r5, #0 */
/* @0x1f2264 beq 0x1f22bc <_ZN9CTimeLine12DeleteMomentEi+0x6c> */
/* @0x1f2268 sub r12, r5, #1 */
/* @0x1f226c ldr r0, [r0, #0x14] */
/* @0x1f2270 ble 0x1f23fc <_ZN9CTimeLine12DeleteMomentEi+0x1ac> */
/* @0x1f2274 ldr r3, [r0] */
/* @0x1f2278 cmp r1, r3 */
/* @0x1f227c ble 0x1f240c <_ZN9CTimeLine12DeleteMomentEi+0x1bc> */
/* @0x1f2280 mov r2, r0 */
/* @0x1f2284 mov r4, #0 */
/* @0x1f2288 b 0x1f2298 <_ZN9CTimeLine12DeleteMomentEi+0x48> */
/* @0x1f228c ldr r3, [r2, #0x4]! */
/* @0x1f2290 cmp r3, r1 */
/* @0x1f2294 bge 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64> */
/* @0x1f2298 add r4, r4, #1 */
/* @0x1f229c cmp r4, r5 */
/* @0x1f22a0 lsl r7, r4, #2 */
/* @0x1f22a4 bne 0x1f228c <_ZN9CTimeLine12DeleteMomentEi+0x3c> */
/* @0x1f22a8 ldr r3, [r0, r12, lsl #2] */
/* @0x1f22ac lsl r7, r12, #2 */
/* @0x1f22b0 mov r4, r12 */
/* @0x1f22b4 cmp r1, r3 */
/* @0x1f22b8 beq 0x1f22c4 <_ZN9CTimeLine12DeleteMomentEi+0x74> */
/* @0x1f22bc add sp, sp, #12 */
/* @0x1f22c0 pop {r4, r5, r6, r7, pc} */
/* @0x1f22c4 ldr lr, [r6, #0x8] */
/* @0x1f22c8 cmp r4, lr */
/* @0x1f22cc bge 0x1f236c <_ZN9CTimeLine12DeleteMomentEi+0x11c> */
/* @0x1f22d0 ldr r3, [r6, #0xc] */
/* @0x1f22d4 ldr r2, [r3, r7] */
/* @0x1f22d8 tst r2, #1 */
/* @0x1f22dc movne r2, #0 */
/* @0x1f22e0 strne r2, [r3, r7] */
/* @0x1f22e4 cmp r4, #0 */
/* @0x1f22e8 blt 0x1f2368 <_ZN9CTimeLine12DeleteMomentEi+0x118> */
/* @0x1f22ec ldr r3, [r6, #0xc] */
/* @0x1f22f0 cmp r3, #0 */
/* @0x1f22f4 beq 0x1f2368 <_ZN9CTimeLine12DeleteMomentEi+0x118> */
/* @0x1f22f8 ldr r0, [r3, r7] */
/* @0x1f22fc add r2, r3, r7 */
/* @0x1f2300 cmp r0, #0 */
/* @0x1f2304 beq 0x1f2328 <_ZN9CTimeLine12DeleteMomentEi+0xd8> */
/* @0x1f2308 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f230c ldr r3, [r6, #0xc] */
/* @0x1f2310 mov r2, #0 */
/* @0x1f2314 ldr lr, [r6, #0x8] */
/* @0x1f2318 ldr r5, [r6, #0x10] */
/* @0x1f231c str r2, [r3, r7] */
/* @0x1f2320 ldr r3, [r6, #0xc] */
/* @0x1f2324 add r2, r3, r7 */
/* @0x1f2328 sub lr, lr, #2 */
/* @0x1f232c cmp r4, lr */
/* @0x1f2330 bge 0x1f2360 <_ZN9CTimeLine12DeleteMomentEi+0x110> */
/* @0x1f2334 lsl r1, r4, #2 */
/* @0x1f2338 mov r2, r4 */
/* @0x1f233c add r0, r1, #4 */
/* @0x1f2340 add r2, r2, #1 */
/* @0x1f2344 cmp r2, lr */
/* @0x1f2348 ldr r12, [r3, r0] */
/* @0x1f234c str r12, [r3, r1] */
/* @0x1f2350 mov r1, r0 */
/* @0x1f2354 ldr r3, [r6, #0xc] */
/* @0x1f2358 bne 0x1f233c <_ZN9CTimeLine12DeleteMomentEi+0xec> */
/* @0x1f235c add r2, r3, r2, lsl #2 */
/* @0x1f2360 mov r3, #0 */
/* @0x1f2364 str r3, [r2] */
/* @0x1f2368 ldr r0, [r6, #0x14] */
/* @0x1f236c sub r3, r5, #2 */
/* @0x1f2370 cmp r4, r3 */
/* @0x1f2374 bge 0x1f2398 <_ZN9CTimeLine12DeleteMomentEi+0x148> */
/* @0x1f2378 add r3, r0, r4, lsl #2 */
/* @0x1f237c ldr r2, [r3, #0x4] */
/* @0x1f2380 add r4, r4, #1 */
/* @0x1f2384 str r2, [r3], #4 */
/* @0x1f2388 ldr r5, [r6, #0x10] */
/* @0x1f238c sub r2, r5, #2 */
/* @0x1f2390 cmp r4, r2 */
/* @0x1f2394 blt 0x1f237c <_ZN9CTimeLine12DeleteMomentEi+0x12c> */
/* @0x1f2398 cmp r5, #0 */
/* @0x1f239c sub r3, r5, #1 */
/* @0x1f23a0 str r3, [r6, #0x10] */
/* @0x1f23a4 beq 0x1f23d8 <_ZN9CTimeLine12DeleteMomentEi+0x188> */
/* @0x1f23a8 lsls r1, r5, #2 */
/* @0x1f23ac beq 0x1f23ec <_ZN9CTimeLine12DeleteMomentEi+0x19c> */
/* @0x1f23b0 ldr r2, [pc, #0x60] */
/* @0x1f23b4 mov r3, #0 */
/* @0x1f23b8 str r3, [sp] */
/* @0x1f23bc mov r3, #106 */
/* @0x1f23c0 add r2, pc, r2 */
/* @0x1f23c4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f23c8 str r0, [r6, #0x14] */
/* @0x1f23cc str r5, [r6, #0x10] */
/* @0x1f23d0 add sp, sp, #12 */
/* @0x1f23d4 pop {r4, r5, r6, r7, pc} */
/* @0x1f23d8 cmp r0, #0 */
/* @0x1f23dc beq 0x1f23ec <_ZN9CTimeLine12DeleteMomentEi+0x19c> */
/* @0x1f23e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f23e4 str r5, [r6, #0x14] */
/* @0x1f23e8 b 0x1f23cc <_ZN9CTimeLine12DeleteMomentEi+0x17c> */
/* @0x1f23ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f23f0 mov r3, #0 */
/* @0x1f23f4 str r3, [r6, #0x14] */
/* @0x1f23f8 b 0x1f23cc <_ZN9CTimeLine12DeleteMomentEi+0x17c> */
/* @0x1f23fc lsl r7, r12, #2 */
/* @0x1f2400 mov r4, r12 */
/* @0x1f2404 ldr r3, [r0, r12, lsl #2] */
/* @0x1f2408 b 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64> */
/* @0x1f240c mov r7, #0 */
/* @0x1f2410 mov r4, r7 */
/* @0x1f2414 b 0x1f22b4 <_ZN9CTimeLine12DeleteMomentEi+0x64> */
/* @0x1f2418 andseq r0, r6, r4, lsl r3 */

/* ── FUNC 0x1f241c · TimeLine_Quit() · size=408 · insn=102 */
/* @0x1f241c ldr r3, [pc, #0x184] */
/* @0x1f2420 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f2424 ldr r6, [pc, r3] */
/* @0x1f2428 cmp r6, #0 */
/* @0x1f242c beq 0x1f24e0 <_Z13TimeLine_Quitv+0xc4> */
/* @0x1f2430 ldr r12, [r6] */
/* @0x1f2434 cmp r12, #0 */
/* @0x1f2438 beq 0x1f24d8 <_Z13TimeLine_Quitv+0xbc> */
/* @0x1f243c ldr r5, [r6, #0x4] */
/* @0x1f2440 cmp r5, #0 */
/* @0x1f2444 beq 0x1f2598 <_Z13TimeLine_Quitv+0x17c> */
/* @0x1f2448 cmp r12, #0 */
/* @0x1f244c ble 0x1f24c0 <_Z13TimeLine_Quitv+0xa4> */
/* @0x1f2450 mov r4, #0 */
/* @0x1f2454 mov r8, r4 */
/* @0x1f2458 ldr r1, [r5] */
/* @0x1f245c movw r3, #0xfeee */
/* @0x1f2460 movt r3, #0xfeee */
/* @0x1f2464 movw r2, #0xfeee */
/* @0x1f2468 cmp r1, r3 */
/* @0x1f246c movt r2, #0xfeee */
/* @0x1f2470 lsl r7, r4, #2 */
/* @0x1f2474 beq 0x1f24b4 <_Z13TimeLine_Quitv+0x98> */
/* @0x1f2478 ldr r3, [r5, r4, lsl #2] */
/* @0x1f247c add r1, r5, r7 */
/* @0x1f2480 cmp r3, #0 */
/* @0x1f2484 mov r0, r3 */
/* @0x1f2488 beq 0x1f24b4 <_Z13TimeLine_Quitv+0x98> */
/* @0x1f248c ldr r3, [r3] */
/* @0x1f2490 cmp r3, r2 */
/* @0x1f2494 beq 0x1f24ac <_Z13TimeLine_Quitv+0x90> */
/* @0x1f2498 ldr r3, [r3, #0x4] */
/* @0x1f249c blx r3 */
/* @0x1f24a0 ldr r1, [r6, #0x4] */
/* @0x1f24a4 ldr r12, [r6] */
/* @0x1f24a8 add r1, r1, r7 */
/* @0x1f24ac str r8, [r1] */
/* @0x1f24b0 ldr r5, [r6, #0x4] */
/* @0x1f24b4 add r4, r4, #1 */
/* @0x1f24b8 cmp r4, r12 */
/* @0x1f24bc blt 0x1f2458 <_Z13TimeLine_Quitv+0x3c> */
/* @0x1f24c0 mov r0, r5 */
/* @0x1f24c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f24c8 mov r3, #0 */
/* @0x1f24cc str r3, [r6, #0x4] */
/* @0x1f24d0 mov r3, #0 */
/* @0x1f24d4 str r3, [r6] */
/* @0x1f24d8 mov r0, r6 */
/* @0x1f24dc bl 0x27d1d0 <_ZdlPv> */
/* @0x1f24e0 ldr r3, [pc, #0xc4] */
/* @0x1f24e4 add r3, pc, r3 */
/* @0x1f24e8 ldr r5, [r3, #0x4] */
/* @0x1f24ec cmp r5, #0 */
/* @0x1f24f0 beq 0x1f2570 <_Z13TimeLine_Quitv+0x154> */
/* @0x1f24f4 ldr r6, [r5, #0x4] */
/* @0x1f24f8 cmp r6, #0 */
/* @0x1f24fc beq 0x1f2588 <_Z13TimeLine_Quitv+0x16c> */
/* @0x1f2500 ldr r3, [r5] */
/* @0x1f2504 cmp r3, #0 */
/* @0x1f2508 ble 0x1f2550 <_Z13TimeLine_Quitv+0x134> */
/* @0x1f250c mov r4, #0 */
/* @0x1f2510 mov r7, r4 */
/* @0x1f2514 ldr r0, [r6, r4, lsl #2] */
/* @0x1f2518 lsl r6, r4, #2 */
/* @0x1f251c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f2520 cmp r0, #0 */
/* @0x1f2524 beq 0x1f2534 <_Z13TimeLine_Quitv+0x118> */
/* @0x1f2528 ldr r3, [r5, #0x4] */
/* @0x1f252c ldr r0, [r3, r4, lsl #2] */
/* @0x1f2530 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2534 ldr r2, [r5] */
/* @0x1f2538 add r4, r4, #1 */
/* @0x1f253c ldr r3, [r5, #0x4] */
/* @0x1f2540 cmp r4, r2 */
/* @0x1f2544 str r7, [r3, r6] */
/* @0x1f2548 ldr r6, [r5, #0x4] */
/* @0x1f254c blt 0x1f2514 <_Z13TimeLine_Quitv+0xf8> */
/* @0x1f2550 mov r0, r6 */
/* @0x1f2554 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2558 mov r3, #0 */
/* @0x1f255c str r3, [r5, #0x4] */
/* @0x1f2560 mov r3, #0 */
/* @0x1f2564 mov r0, r5 */
/* @0x1f2568 str r3, [r5] */
/* @0x1f256c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f2570 ldr r3, [pc, #0x38] */
/* @0x1f2574 mov r2, #0 */
/* @0x1f2578 add r3, pc, r3 */
/* @0x1f257c str r2, [r3] */
/* @0x1f2580 str r2, [r3, #0x4] */
/* @0x1f2584 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f2588 mov r0, r6 */
/* @0x1f258c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2590 str r6, [r5, #0x4] */
/* @0x1f2594 b 0x1f2560 <_Z13TimeLine_Quitv+0x144> */
/* @0x1f2598 mov r0, r5 */
/* @0x1f259c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f25a0 str r5, [r6, #0x4] */
/* @0x1f25a4 b 0x1f24d0 <_Z13TimeLine_Quitv+0xb4> */
/* @0x1f25a8 subseq r0, r6, r8, asr #25 */
/* @0x1f25ac subseq r0, r6, r8, lsl #24 */
/* @0x1f25b0 subseq r0, r6, r4, ror r11 */

/* ── FUNC 0x1f25b4 · TimeLine_Init() · size=444 · insn=111 */
/* @0x1f25b4 ldr r3, [pc, #0x1a8] */
/* @0x1f25b8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f25bc ldr r6, [pc, r3] */
/* @0x1f25c0 cmp r6, #0 */
/* @0x1f25c4 beq 0x1f2678 <_Z13TimeLine_Initv+0xc4> */
/* @0x1f25c8 ldr r12, [r6] */
/* @0x1f25cc cmp r12, #0 */
/* @0x1f25d0 beq 0x1f2670 <_Z13TimeLine_Initv+0xbc> */
/* @0x1f25d4 ldr r5, [r6, #0x4] */
/* @0x1f25d8 cmp r5, #0 */
/* @0x1f25dc beq 0x1f2754 <_Z13TimeLine_Initv+0x1a0> */
/* @0x1f25e0 cmp r12, #0 */
/* @0x1f25e4 ble 0x1f2658 <_Z13TimeLine_Initv+0xa4> */
/* @0x1f25e8 mov r4, #0 */
/* @0x1f25ec mov r8, r4 */
/* @0x1f25f0 ldr r1, [r5] */
/* @0x1f25f4 movw r3, #0xfeee */
/* @0x1f25f8 movt r3, #0xfeee */
/* @0x1f25fc movw r2, #0xfeee */
/* @0x1f2600 cmp r1, r3 */
/* @0x1f2604 movt r2, #0xfeee */
/* @0x1f2608 lsl r7, r4, #2 */
/* @0x1f260c beq 0x1f264c <_Z13TimeLine_Initv+0x98> */
/* @0x1f2610 ldr r3, [r5, r4, lsl #2] */
/* @0x1f2614 add r1, r5, r7 */
/* @0x1f2618 cmp r3, #0 */
/* @0x1f261c mov r0, r3 */
/* @0x1f2620 beq 0x1f264c <_Z13TimeLine_Initv+0x98> */
/* @0x1f2624 ldr r3, [r3] */
/* @0x1f2628 cmp r3, r2 */
/* @0x1f262c beq 0x1f2644 <_Z13TimeLine_Initv+0x90> */
/* @0x1f2630 ldr r3, [r3, #0x4] */
/* @0x1f2634 blx r3 */
/* @0x1f2638 ldr r1, [r6, #0x4] */
/* @0x1f263c ldr r12, [r6] */
/* @0x1f2640 add r1, r1, r7 */
/* @0x1f2644 str r8, [r1] */
/* @0x1f2648 ldr r5, [r6, #0x4] */
/* @0x1f264c add r4, r4, #1 */
/* @0x1f2650 cmp r4, r12 */
/* @0x1f2654 blt 0x1f25f0 <_Z13TimeLine_Initv+0x3c> */
/* @0x1f2658 mov r0, r5 */
/* @0x1f265c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2660 mov r3, #0 */
/* @0x1f2664 str r3, [r6, #0x4] */
/* @0x1f2668 mov r3, #0 */
/* @0x1f266c str r3, [r6] */
/* @0x1f2670 mov r0, r6 */
/* @0x1f2674 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f2678 mov r0, #8 */
/* @0x1f267c mov r4, #0 */
/* @0x1f2680 bl 0x27c524 <_Znwj> */
/* @0x1f2684 ldr r3, [pc, #0xdc] */
/* @0x1f2688 add r3, pc, r3 */
/* @0x1f268c ldr r5, [r3, #0x4] */
/* @0x1f2690 cmp r5, r4 */
/* @0x1f2694 str r4, [r0] */
/* @0x1f2698 str r4, [r0, #0x4] */
/* @0x1f269c str r0, [r3] */
/* @0x1f26a0 beq 0x1f2720 <_Z13TimeLine_Initv+0x16c> */
/* @0x1f26a4 ldr r6, [r5, #0x4] */
/* @0x1f26a8 cmp r6, r4 */
/* @0x1f26ac beq 0x1f2744 <_Z13TimeLine_Initv+0x190> */
/* @0x1f26b0 ldr r3, [r5] */
/* @0x1f26b4 cmp r3, r4 */
/* @0x1f26b8 ble 0x1f2700 <_Z13TimeLine_Initv+0x14c> */
/* @0x1f26bc mov r7, r4 */
/* @0x1f26c0 ldr r3, [r5, #0x4] */
/* @0x1f26c4 lsl r6, r4, #2 */
/* @0x1f26c8 ldr r0, [r3, r4, lsl #2] */
/* @0x1f26cc bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f26d0 cmp r0, #0 */
/* @0x1f26d4 beq 0x1f26e4 <_Z13TimeLine_Initv+0x130> */
/* @0x1f26d8 ldr r3, [r5, #0x4] */
/* @0x1f26dc ldr r0, [r3, r4, lsl #2] */
/* @0x1f26e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f26e4 ldr r2, [r5] */
/* @0x1f26e8 add r4, r4, #1 */
/* @0x1f26ec ldr r3, [r5, #0x4] */
/* @0x1f26f0 cmp r4, r2 */
/* @0x1f26f4 str r7, [r3, r6] */
/* @0x1f26f8 blt 0x1f26c0 <_Z13TimeLine_Initv+0x10c> */
/* @0x1f26fc ldr r6, [r5, #0x4] */
/* @0x1f2700 mov r0, r6 */
/* @0x1f2704 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2708 mov r3, #0 */
/* @0x1f270c str r3, [r5, #0x4] */
/* @0x1f2710 mov r3, #0 */
/* @0x1f2714 mov r0, r5 */
/* @0x1f2718 str r3, [r5] */
/* @0x1f271c bl 0x27d1d0 <_ZdlPv> */
/* @0x1f2720 mov r0, #8 */
/* @0x1f2724 bl 0x27c524 <_Znwj> */
/* @0x1f2728 ldr r2, [pc, #0x3c] */
/* @0x1f272c mov r3, #0 */
/* @0x1f2730 add r2, pc, r2 */
/* @0x1f2734 str r3, [r0] */
/* @0x1f2738 str r3, [r0, #0x4] */
/* @0x1f273c str r0, [r2, #0x4] */
/* @0x1f2740 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f2744 mov r0, r6 */
/* @0x1f2748 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f274c str r6, [r5, #0x4] */
/* @0x1f2750 b 0x1f2710 <_Z13TimeLine_Initv+0x15c> */
/* @0x1f2754 mov r0, r5 */
/* @0x1f2758 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f275c str r5, [r6, #0x4] */
/* @0x1f2760 b 0x1f2668 <_Z13TimeLine_Initv+0xb4> */
/* @0x1f2764 subseq r0, r6, r0, lsr r11 */
/* @0x1f2768 subseq r0, r6, r4, ror #20 */
/* @0x1f276c ldrheq r0, [r6], #-156 */
