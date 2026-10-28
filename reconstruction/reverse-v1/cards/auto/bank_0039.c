/* libyoyo.so 覆盖卡组 0039
 * 函数 0x10fe28..0x111030，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x10fe28 · utf8_add_char · size=144 · insn=36 */
/* @0x10fe28 cmp r1, #127 */
/* @0x10fe2c ldr r3, [r0] */
/* @0x10fe30 bls 0x10fe78 <utf8_add_char+0x50> */
/* @0x10fe34 cmp r1, #2048 */
/* @0x10fe38 blo 0x10fe8c <utf8_add_char+0x64> */
/* @0x10fe3c lsr r12, r1, #12 */
/* @0x10fe40 ubfx r2, r1, #0x6, #0x6 */
/* @0x10fe44 sub r12, r12, #32 */
/* @0x10fe48 strb r12, [r3] */
/* @0x10fe4c ldr r3, [r0] */
/* @0x10fe50 sub r2, r2, #128 */
/* @0x10fe54 and r1, r1, #63 */
/* @0x10fe58 sub r1, r1, #128 */
/* @0x10fe5c strb r2, [r3, #0x1] */
/* @0x10fe60 ldr r3, [r0] */
/* @0x10fe64 strb r1, [r3, #0x2] */
/* @0x10fe68 ldr r3, [r0] */
/* @0x10fe6c add r3, r3, #3 */
/* @0x10fe70 str r3, [r0] */
/* @0x10fe74 bx lr */
/* @0x10fe78 strb r1, [r3] */
/* @0x10fe7c ldr r3, [r0] */
/* @0x10fe80 add r3, r3, #1 */
/* @0x10fe84 str r3, [r0] */
/* @0x10fe88 bx lr */
/* @0x10fe8c asr r2, r1, #6 */
/* @0x10fe90 and r1, r1, #63 */
/* @0x10fe94 sub r2, r2, #64 */
/* @0x10fe98 strb r2, [r3] */
/* @0x10fe9c ldr r3, [r0] */
/* @0x10fea0 sub r1, r1, #128 */
/* @0x10fea4 strb r1, [r3, #0x1] */
/* @0x10fea8 ldr r3, [r0] */
/* @0x10feac add r3, r3, #2 */
/* @0x10feb0 str r3, [r0] */
/* @0x10feb4 bx lr */

/* ── FUNC 0x10feb8 · F_StringLetters(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0x10feb8 push {r4, r5, r6, r7, r8, lr} */
/* @0x10febc sub sp, sp, #8 */
/* @0x10fec0 mov r1, #0 */
/* @0x10fec4 mov r7, r0 */
/* @0x10fec8 ldr r0, [sp, #0x20] */
/* @0x10fecc add r5, sp, #8 */
/* @0x10fed0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10fed4 mov r8, r0 */
/* @0x10fed8 bl 0xb6538 <strlen@plt> */
/* @0x10fedc ldr r1, [pc, #0x84] */
/* @0x10fee0 mov r3, #1 */
/* @0x10fee4 movw r2, #0x843 */
/* @0x10fee8 add r1, pc, r1 */
/* @0x10feec add r0, r0, r3 */
/* @0x10fef0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10fef4 str r8, [sp] */
/* @0x10fef8 mov r3, r8 */
/* @0x10fefc mov r6, r0 */
/* @0x10ff00 str r0, [r5, #-0x4]! */
/* @0x10ff04 b 0x10ff24 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x10ff08 bl 0x10fb38 <utf8_extract_char> */
/* @0x10ff0c bic r3, r0, #32 */
/* @0x10ff10 sub r3, r3, #65 */
/* @0x10ff14 uxth r3, r3 */
/* @0x10ff18 cmp r3, #25 */
/* @0x10ff1c bls 0x10ff58 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x10ff20 ldr r3, [sp] */
/* @0x10ff24 ldrb r1, [r3] */
/* @0x10ff28 mov r0, sp */
/* @0x10ff2c cmp r1, #0 */
/* @0x10ff30 bne 0x10ff08 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x10ff34 mov r0, r5 */
/* @0x10ff38 bl 0x10fe28 <utf8_add_char> */
/* @0x10ff3c mov r0, r7 */
/* @0x10ff40 mov r1, r6 */
/* @0x10ff44 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x10ff48 mov r0, r6 */
/* @0x10ff4c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10ff50 add sp, sp, #8 */
/* @0x10ff54 pop {r4, r5, r6, r7, r8, pc} */
/* @0x10ff58 mov r1, r0 */
/* @0x10ff5c mov r0, r5 */
/* @0x10ff60 bl 0x10fe28 <utf8_add_char> */
/* @0x10ff64 b 0x10ff20 <_Z15F_StringLettersR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x10ff68 eoreq r8, r2, r12, asr pc */

/* ── FUNC 0x10ff6c · F_StringDigits(RValue&, CInstance*, CInstance*, int, RValue*) · size=184 · insn=46 */
/* @0x10ff6c push {r4, r5, r6, r7, lr} */
/* @0x10ff70 sub sp, sp, #12 */
/* @0x10ff74 mov r7, r0 */
/* @0x10ff78 mov r1, #0 */
/* @0x10ff7c ldr r0, [sp, #0x20] */
/* @0x10ff80 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x10ff84 subs r4, r0, #0 */
/* @0x10ff88 moveq r0, #1 */
/* @0x10ff8c beq 0x10ff98 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x10ff90 bl 0xb6538 <strlen@plt> */
/* @0x10ff94 add r0, r0, #1 */
/* @0x10ff98 ldr r1, [pc, #0x80] */
/* @0x10ff9c mov r3, #1 */
/* @0x10ffa0 movw r2, #0x86d */
/* @0x10ffa4 add r5, sp, #8 */
/* @0x10ffa8 add r1, pc, r1 */
/* @0x10ffac bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x10ffb0 str r4, [sp] */
/* @0x10ffb4 mov r3, r4 */
/* @0x10ffb8 mov r6, r0 */
/* @0x10ffbc str r0, [r5, #-0x4]! */
/* @0x10ffc0 b 0x10ffdc <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x10ffc4 bl 0x10fb38 <utf8_extract_char> */
/* @0x10ffc8 sub r3, r0, #48 */
/* @0x10ffcc uxth r3, r3 */
/* @0x10ffd0 cmp r3, #9 */
/* @0x10ffd4 bls 0x110010 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x10ffd8 ldr r3, [sp] */
/* @0x10ffdc ldrb r1, [r3] */
/* @0x10ffe0 mov r0, sp */
/* @0x10ffe4 cmp r1, #0 */
/* @0x10ffe8 bne 0x10ffc4 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x10ffec mov r0, r5 */
/* @0x10fff0 bl 0x10fe28 <utf8_add_char> */
/* @0x10fff4 mov r0, r7 */
/* @0x10fff8 mov r1, r6 */
/* @0x10fffc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x110000 mov r0, r6 */
/* @0x110004 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x110008 add sp, sp, #12 */
/* @0x11000c pop {r4, r5, r6, r7, pc} */
/* @0x110010 mov r1, r0 */
/* @0x110014 mov r0, r5 */
/* @0x110018 bl 0x10fe28 <utf8_add_char> */
/* @0x11001c b 0x10ffd8 <_Z14F_StringDigitsR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x110020 mlaeq r2, r12, lr, r8 */

/* ── FUNC 0x110024 · F_StringLettersDigits(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x110024 push {r4, r5, r6, r7, r8, lr} */
/* @0x110028 sub sp, sp, #8 */
/* @0x11002c mov r1, #0 */
/* @0x110030 mov r7, r0 */
/* @0x110034 ldr r0, [sp, #0x20] */
/* @0x110038 add r4, sp, #8 */
/* @0x11003c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110040 mov r8, r0 */
/* @0x110044 bl 0xb6538 <strlen@plt> */
/* @0x110048 ldr r1, [pc, #0x94] */
/* @0x11004c mov r3, #1 */
/* @0x110050 movw r2, #0x881 */
/* @0x110054 add r1, pc, r1 */
/* @0x110058 add r0, r0, r3 */
/* @0x11005c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x110060 str r8, [sp] */
/* @0x110064 mov r3, r8 */
/* @0x110068 mov r6, r0 */
/* @0x11006c str r0, [r4, #-0x4]! */
/* @0x110070 b 0x1100b0 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x110074 bl 0x10fb38 <utf8_extract_char> */
/* @0x110078 mov r3, r0 */
/* @0x11007c bic r2, r3, #32 */
/* @0x110080 sub r2, r2, #65 */
/* @0x110084 sub r3, r3, #48 */
/* @0x110088 mov r1, r0 */
/* @0x11008c mov r0, r4 */
/* @0x110090 uxth r2, r2 */
/* @0x110094 uxth r3, r3 */
/* @0x110098 cmp r2, #25 */
/* @0x11009c bls 0x1100a8 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1100a0 cmp r3, #9 */
/* @0x1100a4 bhi 0x1100ac <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1100a8 bl 0x10fe28 <utf8_add_char> */
/* @0x1100ac ldr r3, [sp] */
/* @0x1100b0 ldrb r1, [r3] */
/* @0x1100b4 mov r0, sp */
/* @0x1100b8 cmp r1, #0 */
/* @0x1100bc bne 0x110074 <_Z21F_StringLettersDigitsR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1100c0 mov r0, r4 */
/* @0x1100c4 bl 0x10fe28 <utf8_add_char> */
/* @0x1100c8 mov r0, r7 */
/* @0x1100cc mov r1, r6 */
/* @0x1100d0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1100d4 mov r0, r6 */
/* @0x1100d8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1100dc add sp, sp, #8 */
/* @0x1100e0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1100e4 .word 0x00228df0 */

/* ── FUNC 0x1100e8 · F_StringHashToNewline(RValue&, CInstance*, CInstance*, int, RValue*) · size=680 · insn=170 */
/* @0x1100e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1100ec sub sp, sp, #44 */
/* @0x1100f0 mov r4, #0 */
/* @0x1100f4 ldr r3, [sp, #0x50] */
/* @0x1100f8 str r0, [sp] */
/* @0x1100fc str r4, [sp, #0x8] */
/* @0x110100 ldr r2, [r3, #0xc] */
/* @0x110104 mov r0, r3 */
/* @0x110108 bic r2, r2, #-16777216 */
/* @0x11010c cmp r2, #1 */
/* @0x110110 beq 0x110378 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x290> */
/* @0x110114 mov r1, #1024 */
/* @0x110118 add r2, sp, #8 */
/* @0x11011c mov r3, #1 */
/* @0x110120 str r3, [sp, #0x4] */
/* @0x110124 bl 0x121ce0 <_Z14GetTextFromArgPK6RValueiPPc> */
/* @0x110128 ldr r3, [sp, #0x8] */
/* @0x11012c mov r7, #0 */
/* @0x110130 str r3, [sp, #0xc] */
/* @0x110134 str r7, [sp, #0x1c] */
/* @0x110138 str r7, [sp, #0x20] */
/* @0x11013c str r7, [sp, #0x24] */
/* @0x110140 strb r7, [sp, #0x14] */
/* @0x110144 strb r7, [sp, #0x15] */
/* @0x110148 strb r7, [sp, #0x16] */
/* @0x11014c strb r7, [sp, #0x17] */
/* @0x110150 strb r7, [sp, #0x18] */
/* @0x110154 ldrb r3, [r3] */
/* @0x110158 cmp r3, r7 */
/* @0x11015c beq 0x110364 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x110160 add r9, sp, #12 */
/* @0x110164 add r4, sp, #20 */
/* @0x110168 add r8, sp, #16 */
/* @0x11016c mov r10, r7 */
/* @0x110170 b 0x110248 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x110174 subs r3, r0, #92 */
/* @0x110178 rsbs r7, r3, #0 */
/* @0x11017c adcs r7, r7, r3 */
/* @0x110180 mov r1, r0 */
/* @0x110184 mov r0, r8 */
/* @0x110188 str r4, [sp, #0x10] */
/* @0x11018c bl 0x10fe28 <utf8_add_char> */
/* @0x110190 ldr r3, [sp, #0x10] */
/* @0x110194 mov r0, r4 */
/* @0x110198 strb r10, [r3] */
/* @0x11019c bl 0xb6538 <strlen@plt> */
/* @0x1101a0 ldr r2, [sp, #0x24] */
/* @0x1101a4 ldr r3, [sp, #0x20] */
/* @0x1101a8 add r1, r0, #1 */
/* @0x1101ac mov r5, r0 */
/* @0x1101b0 mvn r0, r2 */
/* @0x1101b4 add r0, r3, r0 */
/* @0x1101b8 cmp r1, r0 */
/* @0x1101bc ble 0x11021c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1101c0 cmp r3, #0 */
/* @0x1101c4 add r2, r1, r2 */
/* @0x1101c8 ldr r6, [sp, #0x1c] */
/* @0x1101cc moveq r3, r1 */
/* @0x1101d0 add r3, r3, r3, lsl #1 */
/* @0x1101d4 add r3, r3, r3, lsr #31 */
/* @0x1101d8 asr r11, r3, #1 */
/* @0x1101dc cmp r11, r2 */
/* @0x1101e0 addlt r2, r2, r2, lsl #1 */
/* @0x1101e4 addlt r2, r2, r2, lsr #31 */
/* @0x1101e8 asrlt r11, r2, #1 */
/* @0x1101ec mov r0, r11 */
/* @0x1101f0 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1101f4 ldr r2, [sp, #0x20] */
/* @0x1101f8 mov r1, r6 */
/* @0x1101fc str r0, [sp, #0x1c] */
/* @0x110200 bl 0xb65bc <memcpy@plt> */
/* @0x110204 cmp r6, #0 */
/* @0x110208 str r11, [sp, #0x20] */
/* @0x11020c beq 0x110218 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x110210 mov r0, r6 */
/* @0x110214 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x110218 ldr r2, [sp, #0x24] */
/* @0x11021c ldr r0, [sp, #0x1c] */
/* @0x110220 mov r1, r4 */
/* @0x110224 add r0, r0, r2 */
/* @0x110228 bl 0xb65a4 <strcpy@plt> */
/* @0x11022c ldr r3, [sp, #0xc] */
/* @0x110230 ldr r2, [sp, #0x24] */
/* @0x110234 add r5, r5, r2 */
/* @0x110238 str r5, [sp, #0x24] */
/* @0x11023c ldrb r3, [r3] */
/* @0x110240 cmp r3, #0 */
/* @0x110244 beq 0x110324 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x110248 mov r0, r9 */
/* @0x11024c bl 0x10fb38 <utf8_extract_char> */
/* @0x110250 cmp r0, #35 */
/* @0x110254 bne 0x110174 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x110258 cmp r7, #0 */
/* @0x11025c movne r7, #0 */
/* @0x110260 bne 0x110180 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x110264 mov r1, #13 */
/* @0x110268 mov r0, r8 */
/* @0x11026c str r4, [sp, #0x10] */
/* @0x110270 bl 0x10fe28 <utf8_add_char> */
/* @0x110274 ldr r3, [sp, #0x10] */
/* @0x110278 mov r0, r4 */
/* @0x11027c strb r7, [r3] */
/* @0x110280 bl 0xb6538 <strlen@plt> */
/* @0x110284 ldr r2, [sp, #0x24] */
/* @0x110288 ldr r3, [sp, #0x20] */
/* @0x11028c add r1, r0, #1 */
/* @0x110290 mov r5, r0 */
/* @0x110294 mvn r0, r2 */
/* @0x110298 add r0, r3, r0 */
/* @0x11029c cmp r1, r0 */
/* @0x1102a0 ble 0x110300 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x218> */
/* @0x1102a4 cmp r3, #0 */
/* @0x1102a8 add r2, r1, r2 */
/* @0x1102ac ldr r6, [sp, #0x1c] */
/* @0x1102b0 moveq r3, r1 */
/* @0x1102b4 add r3, r3, r3, lsl #1 */
/* @0x1102b8 add r3, r3, r3, lsr #31 */
/* @0x1102bc asr r11, r3, #1 */
/* @0x1102c0 cmp r11, r2 */
/* @0x1102c4 addlt r2, r2, r2, lsl #1 */
/* @0x1102c8 addlt r2, r2, r2, lsr #31 */
/* @0x1102cc asrlt r11, r2, #1 */
/* @0x1102d0 mov r0, r11 */
/* @0x1102d4 bl 0xcef4c <_Z7YYAlloci> */
/* @0x1102d8 ldr r2, [sp, #0x20] */
/* @0x1102dc mov r1, r6 */
/* @0x1102e0 str r0, [sp, #0x1c] */
/* @0x1102e4 bl 0xb65bc <memcpy@plt> */
/* @0x1102e8 cmp r6, #0 */
/* @0x1102ec str r11, [sp, #0x20] */
/* @0x1102f0 beq 0x1102fc <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1102f4 mov r0, r6 */
/* @0x1102f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1102fc ldr r2, [sp, #0x24] */
/* @0x110300 ldr r0, [sp, #0x1c] */
/* @0x110304 mov r1, r4 */
/* @0x110308 add r0, r0, r2 */
/* @0x11030c bl 0xb65a4 <strcpy@plt> */
/* @0x110310 ldr r3, [sp, #0x24] */
/* @0x110314 mov r0, #10 */
/* @0x110318 add r5, r3, r5 */
/* @0x11031c str r5, [sp, #0x24] */
/* @0x110320 b 0x110180 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x110324 cmp r5, #0 */
/* @0x110328 beq 0x110364 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x11032c ldr r1, [sp, #0x1c] */
/* @0x110330 ldr r0, [sp] */
/* @0x110334 mov r3, #0 */
/* @0x110338 str r3, [sp, #0x24] */
/* @0x11033c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x110340 ldr r3, [sp, #0x4] */
/* @0x110344 cmp r3, #0 */
/* @0x110348 bne 0x11036c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x11034c ldr r0, [sp, #0x1c] */
/* @0x110350 cmp r0, #0 */
/* @0x110354 beq 0x11035c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x110358 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x11035c add sp, sp, #44 */
/* @0x110360 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x110364 add r1, sp, #36 */
/* @0x110368 b 0x110330 <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x11036c ldr r0, [sp, #0x8] */
/* @0x110370 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x110374 b 0x11034c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x110378 mov r1, r4 */
/* @0x11037c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110380 str r4, [sp, #0x4] */
/* @0x110384 mov r3, r0 */
/* @0x110388 str r0, [sp, #0x8] */
/* @0x11038c b 0x11012c <_Z21F_StringHashToNewlineR6RValueP9CInstanceS2_iPS_+0x44> */

/* ── FUNC 0x110390 · utf8_char_size · size=32 · insn=8 */
/* @0x110390 cmp r0, #127 */
/* @0x110394 bls 0x1103a8 <utf8_char_size+0x18> */
/* @0x110398 cmp r0, #2048 */
/* @0x11039c movlo r0, #2 */
/* @0x1103a0 movhs r0, #3 */
/* @0x1103a4 bx lr */
/* @0x1103a8 mov r0, #1 */
/* @0x1103ac bx lr */

/* ── FUNC 0x1103b0 · F_StringLower(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x1103b0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1103b4 sub sp, sp, #8 */
/* @0x1103b8 mov r1, #0 */
/* @0x1103bc mov r7, r0 */
/* @0x1103c0 ldr r0, [sp, #0x20] */
/* @0x1103c4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1103c8 ldr r1, [pc, #0x120] */
/* @0x1103cc add r1, pc, r1 */
/* @0x1103d0 mov r8, r0 */
/* @0x1103d4 mov r0, #6 */
/* @0x1103d8 bl 0xb679c <setlocale@plt> */
/* @0x1103dc str r8, [sp] */
/* @0x1103e0 ldrb r3, [r8] */
/* @0x1103e4 cmp r3, #0 */
/* @0x1103e8 beq 0x1104e0 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1103ec mov r6, #0 */
/* @0x1103f0 mov r0, sp */
/* @0x1103f4 bl 0x10fb38 <utf8_extract_char> */
/* @0x1103f8 mov r4, r0 */
/* @0x1103fc bl 0xb67a8 <iswupper@plt> */
/* @0x110400 mov r3, r4 */
/* @0x110404 cmp r0, #0 */
/* @0x110408 mov r0, r4 */
/* @0x11040c beq 0x110418 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x110410 bl 0xb67b4 <towlower@plt> */
/* @0x110414 uxth r3, r0 */
/* @0x110418 mov r0, r3 */
/* @0x11041c bl 0x110390 <utf8_char_size> */
/* @0x110420 ldr r3, [sp] */
/* @0x110424 ldrb r3, [r3] */
/* @0x110428 cmp r3, #0 */
/* @0x11042c add r6, r6, r0 */
/* @0x110430 bne 0x1103f0 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x110434 add r0, r6, #1 */
/* @0x110438 ldr r1, [pc, #0xb4] */
/* @0x11043c mov r3, #1 */
/* @0x110440 movw r2, #0x7ec */
/* @0x110444 add r1, pc, r1 */
/* @0x110448 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x11044c str r8, [sp] */
/* @0x110450 str r0, [sp, #0x4] */
/* @0x110454 mov r6, r0 */
/* @0x110458 ldrb r3, [r8] */
/* @0x11045c cmp r3, #0 */
/* @0x110460 beq 0x1104e8 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x110464 add r8, sp, #4 */
/* @0x110468 mov r0, sp */
/* @0x11046c bl 0x10fb38 <utf8_extract_char> */
/* @0x110470 mov r4, r0 */
/* @0x110474 bl 0xb67a8 <iswupper@plt> */
/* @0x110478 mov r1, r4 */
/* @0x11047c cmp r0, #0 */
/* @0x110480 mov r0, r4 */
/* @0x110484 beq 0x110490 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x110488 bl 0xb67b4 <towlower@plt> */
/* @0x11048c uxth r1, r0 */
/* @0x110490 mov r0, r8 */
/* @0x110494 bl 0x10fe28 <utf8_add_char> */
/* @0x110498 ldr r3, [sp] */
/* @0x11049c ldrb r3, [r3] */
/* @0x1104a0 cmp r3, #0 */
/* @0x1104a4 bne 0x110468 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1104a8 ldr r2, [sp, #0x4] */
/* @0x1104ac ldr r1, [pc, #0x44] */
/* @0x1104b0 mov r3, #0 */
/* @0x1104b4 mov r0, #6 */
/* @0x1104b8 strb r3, [r2] */
/* @0x1104bc add r1, pc, r1 */
/* @0x1104c0 bl 0xb679c <setlocale@plt> */
/* @0x1104c4 mov r0, r7 */
/* @0x1104c8 mov r1, r6 */
/* @0x1104cc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1104d0 mov r0, r6 */
/* @0x1104d4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1104d8 add sp, sp, #8 */
/* @0x1104dc pop {r4, r5, r6, r7, r8, pc} */
/* @0x1104e0 mov r0, #1 */
/* @0x1104e4 b 0x110438 <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x1104e8 mov r2, r0 */
/* @0x1104ec b 0x1104ac <_Z13F_StringLowerR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x1104f0 eoreq lr, r1, r10, ror #14 */
/* @0x1104f4 eoreq r8, r2, r0, lsl #20 */
/* @0x1104f8 eoreq r8, r2, r4, ror #23 */

/* ── FUNC 0x1104fc · F_StringUpper(RValue&, CInstance*, CInstance*, int, RValue*) · size=332 · insn=83 */
/* @0x1104fc push {r4, r5, r6, r7, r8, lr} */
/* @0x110500 sub sp, sp, #8 */
/* @0x110504 mov r1, #0 */
/* @0x110508 mov r7, r0 */
/* @0x11050c ldr r0, [sp, #0x20] */
/* @0x110510 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110514 ldr r1, [pc, #0x120] */
/* @0x110518 add r1, pc, r1 */
/* @0x11051c mov r8, r0 */
/* @0x110520 mov r0, #6 */
/* @0x110524 bl 0xb679c <setlocale@plt> */
/* @0x110528 str r8, [sp] */
/* @0x11052c ldrb r3, [r8] */
/* @0x110530 cmp r3, #0 */
/* @0x110534 beq 0x11062c <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x110538 mov r6, #0 */
/* @0x11053c mov r0, sp */
/* @0x110540 bl 0x10fb38 <utf8_extract_char> */
/* @0x110544 mov r4, r0 */
/* @0x110548 bl 0xb67c0 <iswlower@plt> */
/* @0x11054c mov r3, r4 */
/* @0x110550 cmp r0, #0 */
/* @0x110554 mov r0, r4 */
/* @0x110558 beq 0x110564 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11055c bl 0xb67cc <towupper@plt> */
/* @0x110560 uxth r3, r0 */
/* @0x110564 mov r0, r3 */
/* @0x110568 bl 0x110390 <utf8_char_size> */
/* @0x11056c ldr r3, [sp] */
/* @0x110570 ldrb r3, [r3] */
/* @0x110574 cmp r3, #0 */
/* @0x110578 add r6, r6, r0 */
/* @0x11057c bne 0x11053c <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x110580 add r0, r6, #1 */
/* @0x110584 ldr r1, [pc, #0xb4] */
/* @0x110588 mov r3, #1 */
/* @0x11058c movw r2, #0x80b */
/* @0x110590 add r1, pc, r1 */
/* @0x110594 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x110598 str r8, [sp] */
/* @0x11059c str r0, [sp, #0x4] */
/* @0x1105a0 mov r6, r0 */
/* @0x1105a4 ldrb r3, [r8] */
/* @0x1105a8 cmp r3, #0 */
/* @0x1105ac beq 0x110634 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1105b0 add r8, sp, #4 */
/* @0x1105b4 mov r0, sp */
/* @0x1105b8 bl 0x10fb38 <utf8_extract_char> */
/* @0x1105bc mov r4, r0 */
/* @0x1105c0 bl 0xb67c0 <iswlower@plt> */
/* @0x1105c4 mov r1, r4 */
/* @0x1105c8 cmp r0, #0 */
/* @0x1105cc mov r0, r4 */
/* @0x1105d0 beq 0x1105dc <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x1105d4 bl 0xb67cc <towupper@plt> */
/* @0x1105d8 uxth r1, r0 */
/* @0x1105dc mov r0, r8 */
/* @0x1105e0 bl 0x10fe28 <utf8_add_char> */
/* @0x1105e4 ldr r3, [sp] */
/* @0x1105e8 ldrb r3, [r3] */
/* @0x1105ec cmp r3, #0 */
/* @0x1105f0 bne 0x1105b4 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1105f4 ldr r2, [sp, #0x4] */
/* @0x1105f8 ldr r1, [pc, #0x44] */
/* @0x1105fc mov r3, #0 */
/* @0x110600 mov r0, #6 */
/* @0x110604 strb r3, [r2] */
/* @0x110608 add r1, pc, r1 */
/* @0x11060c bl 0xb679c <setlocale@plt> */
/* @0x110610 mov r0, r7 */
/* @0x110614 mov r1, r6 */
/* @0x110618 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x11061c mov r0, r6 */
/* @0x110620 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x110624 add sp, sp, #8 */
/* @0x110628 pop {r4, r5, r6, r7, r8, pc} */
/* @0x11062c mov r0, #1 */
/* @0x110630 b 0x110584 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x110634 mov r2, r0 */
/* @0x110638 b 0x1105f8 <_Z13F_StringUpperR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x11063c eoreq lr, r1, lr, lsl r6 */
/* @0x110640 .word 0x002288b4 */
/* @0x110644 mlaeq r2, r8, r10, r8 */

/* ── FUNC 0x110648 · utf8_strlen · size=72 · insn=18 */
/* @0x110648 push {r4, r5, lr} */
/* @0x11064c sub sp, sp, #12 */
/* @0x110650 str r0, [sp, #0x4] */
/* @0x110654 ldrb r4, [r0] */
/* @0x110658 cmp r4, #0 */
/* @0x11065c beq 0x110684 <utf8_strlen+0x3c> */
/* @0x110660 add r5, sp, #4 */
/* @0x110664 mov r4, #0 */
/* @0x110668 mov r0, r5 */
/* @0x11066c add r4, r4, #1 */
/* @0x110670 bl 0x10fb38 <utf8_extract_char> */
/* @0x110674 ldr r3, [sp, #0x4] */
/* @0x110678 ldrb r3, [r3] */
/* @0x11067c cmp r3, #0 */
/* @0x110680 bne 0x110668 <utf8_strlen+0x20> */
/* @0x110684 mov r0, r4 */
/* @0x110688 add sp, sp, #12 */
/* @0x11068c pop {r4, r5, pc} */

/* ── FUNC 0x110690 · F_StringLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x110690 push {r4, lr} */
/* @0x110694 mov r1, #0 */
/* @0x110698 mov r4, r0 */
/* @0x11069c ldr r0, [sp, #0x8] */
/* @0x1106a0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1106a4 cmp r0, #0 */
/* @0x1106a8 beq 0x1106d8 <_Z14F_StringLengthR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x1106ac bl 0x110648 <utf8_strlen> */
/* @0x1106b0 vmov s15, r0 */
/* @0x1106b4 vcvt.f64.s32 d7, s15 */
/* @0x1106b8 vmov r2, r3, d7 */
/* @0x1106bc mov r1, r2 */
/* @0x1106c0 mov r2, r3 */
/* @0x1106c4 str r1, [r4] */
/* @0x1106c8 mov r3, #0 */
/* @0x1106cc str r2, [r4, #0x4] */
/* @0x1106d0 str r3, [r4, #0xc] */
/* @0x1106d4 pop {r4, pc} */
/* @0x1106d8 mov r2, #0 */
/* @0x1106dc mov r3, #0 */
/* @0x1106e0 b 0x1106bc <_Z14F_StringLengthR6RValueP9CInstanceS2_iPS_+0x2c> */

/* ── FUNC 0x1106e4 · F_StringCharAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=204 · insn=51 */
/* @0x1106e4 push {r4, r5, r6, r7, lr} */
/* @0x1106e8 sub sp, sp, #20 */
/* @0x1106ec mov r1, #0 */
/* @0x1106f0 mov r7, r0 */
/* @0x1106f4 ldr r5, [sp, #0x28] */
/* @0x1106f8 mov r0, r5 */
/* @0x1106fc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110700 mov r1, #1 */
/* @0x110704 mov r4, r0 */
/* @0x110708 mov r0, r5 */
/* @0x11070c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x110710 cmp r4, #0 */
/* @0x110714 beq 0x110794 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x110718 sub r5, r0, #1 */
/* @0x11071c mov r0, r4 */
/* @0x110720 bl 0x110648 <utf8_strlen> */
/* @0x110724 bic r5, r5, r5, asr #31 */
/* @0x110728 cmp r0, r5 */
/* @0x11072c ble 0x110794 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x110730 cmp r5, #0 */
/* @0x110734 str r4, [sp] */
/* @0x110738 ble 0x110754 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x11073c mov r4, #0 */
/* @0x110740 add r4, r4, #1 */
/* @0x110744 mov r0, sp */
/* @0x110748 bl 0x10fb38 <utf8_extract_char> */
/* @0x11074c cmp r4, r5 */
/* @0x110750 bne 0x110740 <_Z14F_StringCharAtR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x110754 add r4, sp, #16 */
/* @0x110758 mov r0, sp */
/* @0x11075c add r5, sp, #8 */
/* @0x110760 str r5, [r4, #-0xc]! */
/* @0x110764 bl 0x10fb38 <utf8_extract_char> */
/* @0x110768 mov r1, r0 */
/* @0x11076c mov r0, r4 */
/* @0x110770 bl 0x10fe28 <utf8_add_char> */
/* @0x110774 ldr r3, [sp, #0x4] */
/* @0x110778 mov r2, #0 */
/* @0x11077c mov r1, r5 */
/* @0x110780 mov r0, r7 */
/* @0x110784 strb r2, [r3] */
/* @0x110788 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x11078c add sp, sp, #20 */
/* @0x110790 pop {r4, r5, r6, r7, pc} */
/* @0x110794 ldr r1, [pc, #0x10] */
/* @0x110798 mov r0, r7 */
/* @0x11079c add r1, pc, r1 */
/* @0x1107a0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1107a4 add sp, sp, #20 */
/* @0x1107a8 pop {r4, r5, r6, r7, pc} */
/* @0x1107ac mlaeq r1, r10, r3, lr */

/* ── FUNC 0x1107b0 · F_StringOrdAt(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1107b0 push {r4, r5, r6, r7, lr} */
/* @0x1107b4 sub sp, sp, #12 */
/* @0x1107b8 mov r7, r0 */
/* @0x1107bc mov r1, #0 */
/* @0x1107c0 ldr r5, [sp, #0x20] */
/* @0x1107c4 mov r4, r1 */
/* @0x1107c8 mov r0, r5 */
/* @0x1107cc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1107d0 mov r1, #1 */
/* @0x1107d4 str r0, [sp, #0x4] */
/* @0x1107d8 mov r0, r5 */
/* @0x1107dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1107e0 mov r3, r4 */
/* @0x1107e4 str r4, [r7, #0xc] */
/* @0x1107e8 movt r3, #0xbff0 */
/* @0x1107ec str r4, [r7] */
/* @0x1107f0 str r3, [r7, #0x4] */
/* @0x1107f4 sub r5, r0, #1 */
/* @0x1107f8 ldr r0, [sp, #0x4] */
/* @0x1107fc bl 0x110648 <utf8_strlen> */
/* @0x110800 bic r5, r5, r5, asr #31 */
/* @0x110804 cmp r0, r5 */
/* @0x110808 ble 0x11084c <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x11080c cmp r5, r4 */
/* @0x110810 add r6, sp, #4 */
/* @0x110814 ble 0x11082c <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x110818 add r4, r4, #1 */
/* @0x11081c mov r0, r6 */
/* @0x110820 bl 0x10fb38 <utf8_extract_char> */
/* @0x110824 cmp r4, r5 */
/* @0x110828 bne 0x110818 <_Z13F_StringOrdAtR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x11082c mov r0, r6 */
/* @0x110830 bl 0x10fb38 <utf8_extract_char> */
/* @0x110834 vmov s15, r0 */
/* @0x110838 vcvt.f64.u32 d7, s15 */
/* @0x11083c vmov r0, r1, d7 */
/* @0x110840 vmov r2, s14 */
/* @0x110844 mov r3, r1 */
/* @0x110848 stm r7, {r2, r3} */
/* @0x11084c add sp, sp, #12 */
/* @0x110850 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x110854 · F_StringInsert(RValue&, CInstance*, CInstance*, int, RValue*) · size=376 · insn=94 */
/* @0x110854 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x110858 sub sp, sp, #20 */
/* @0x11085c mov r1, #0 */
/* @0x110860 ldr r4, [sp, #0x38] */
/* @0x110864 str r0, [sp, #0x4] */
/* @0x110868 mov r0, r4 */
/* @0x11086c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110870 mov r1, #1 */
/* @0x110874 mov r10, r0 */
/* @0x110878 mov r0, r4 */
/* @0x11087c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110880 mov r1, #2 */
/* @0x110884 mov r5, r0 */
/* @0x110888 mov r0, r4 */
/* @0x11088c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x110890 sub r4, r0, #1 */
/* @0x110894 mov r0, r5 */
/* @0x110898 bl 0x110648 <utf8_strlen> */
/* @0x11089c mov r7, r0 */
/* @0x1108a0 mov r0, r10 */
/* @0x1108a4 bl 0xb6538 <strlen@plt> */
/* @0x1108a8 mov r9, r0 */
/* @0x1108ac mov r0, r5 */
/* @0x1108b0 bl 0xb6538 <strlen@plt> */
/* @0x1108b4 cmp r4, #0 */
/* @0x1108b8 blt 0x110998 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1108bc add r6, r0, r9 */
/* @0x1108c0 cmp r4, r7 */
/* @0x1108c4 movge r4, r7 */
/* @0x1108c8 add r6, r6, #1 */
/* @0x1108cc mov r0, r6 */
/* @0x1108d0 bl 0x27d14c <_Znaj> */
/* @0x1108d4 mov r2, r6 */
/* @0x1108d8 mov r1, #0 */
/* @0x1108dc mov r8, r0 */
/* @0x1108e0 bl 0xb65b0 <memset@plt> */
/* @0x1108e4 cmp r4, #0 */
/* @0x1108e8 str r8, [sp, #0x8] */
/* @0x1108ec str r5, [sp, #0xc] */
/* @0x1108f0 movle r0, r8 */
/* @0x1108f4 movle r4, #0 */
/* @0x1108f8 ble 0x11092c <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1108fc add r6, sp, #12 */
/* @0x110900 add r5, sp, #8 */
/* @0x110904 mov r11, #0 */
/* @0x110908 mov r0, r6 */
/* @0x11090c add r11, r11, #1 */
/* @0x110910 bl 0x10fb38 <utf8_extract_char> */
/* @0x110914 mov r1, r0 */
/* @0x110918 mov r0, r5 */
/* @0x11091c bl 0x10fe28 <utf8_add_char> */
/* @0x110920 cmp r11, r4 */
/* @0x110924 bne 0x110908 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x110928 ldr r0, [sp, #0x8] */
/* @0x11092c mov r2, r9 */
/* @0x110930 mov r1, r10 */
/* @0x110934 bl 0xb65bc <memcpy@plt> */
/* @0x110938 cmp r7, r4 */
/* @0x11093c ldr r3, [sp, #0x8] */
/* @0x110940 addgt r6, sp, #12 */
/* @0x110944 addgt r5, sp, #8 */
/* @0x110948 add r9, r3, r9 */
/* @0x11094c str r9, [sp, #0x8] */
/* @0x110950 ble 0x110974 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x110954 mov r0, r6 */
/* @0x110958 add r4, r4, #1 */
/* @0x11095c bl 0x10fb38 <utf8_extract_char> */
/* @0x110960 mov r1, r0 */
/* @0x110964 mov r0, r5 */
/* @0x110968 bl 0x10fe28 <utf8_add_char> */
/* @0x11096c cmp r4, r7 */
/* @0x110970 bne 0x110954 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x110974 ldr r0, [sp, #0x4] */
/* @0x110978 mov r1, r8 */
/* @0x11097c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x110980 cmp r8, #0 */
/* @0x110984 beq 0x110990 <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x110988 mov r0, r8 */
/* @0x11098c bl 0x27d1d4 <_ZdaPv> */
/* @0x110990 add sp, sp, #20 */
/* @0x110994 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x110998 add r0, r0, r9 */
/* @0x11099c mov r4, #0 */
/* @0x1109a0 add r6, r0, #1 */
/* @0x1109a4 mov r0, r6 */
/* @0x1109a8 bl 0x27d14c <_Znaj> */
/* @0x1109ac mov r2, r6 */
/* @0x1109b0 mov r1, r4 */
/* @0x1109b4 mov r8, r0 */
/* @0x1109b8 bl 0xb65b0 <memset@plt> */
/* @0x1109bc str r8, [sp, #0x8] */
/* @0x1109c0 mov r0, r8 */
/* @0x1109c4 str r5, [sp, #0xc] */
/* @0x1109c8 b 0x11092c <_Z14F_StringInsertR6RValueP9CInstanceS2_iPS_+0xd8> */

/* ── FUNC 0x1109cc · utf8_strcpy(char*, char const*) · size=40 · insn=10 */
/* @0x1109cc push {r3, r4, r5, lr} */
/* @0x1109d0 mov r5, r0 */
/* @0x1109d4 mov r0, r1 */
/* @0x1109d8 mov r4, r1 */
/* @0x1109dc bl 0xb6538 <strlen@plt> */
/* @0x1109e0 mov r1, r4 */
/* @0x1109e4 add r2, r0, #1 */
/* @0x1109e8 mov r0, r5 */
/* @0x1109ec pop {r3, r4, r5, lr} */
/* @0x1109f0 b 0xb65bc <memcpy@plt> */

/* ── FUNC 0x1109f4 · utf8_strcmp · size=128 · insn=32 */
/* @0x1109f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1109f8 sub sp, sp, #8 */
/* @0x1109fc add r7, sp, #4 */
/* @0x110a00 str r0, [sp, #0x4] */
/* @0x110a04 str r1, [sp] */
/* @0x110a08 b 0x110a34 <utf8_strcmp+0x40> */
/* @0x110a0c ldr r5, [sp] */
/* @0x110a10 ldrb r3, [r5] */
/* @0x110a14 cmp r3, #0 */
/* @0x110a18 beq 0x110a48 <utf8_strcmp+0x54> */
/* @0x110a1c bl 0x10fb38 <utf8_extract_char> */
/* @0x110a20 mov r6, r0 */
/* @0x110a24 mov r0, sp */
/* @0x110a28 bl 0x10fb38 <utf8_extract_char> */
/* @0x110a2c cmp r6, r0 */
/* @0x110a30 bne 0x110a68 <utf8_strcmp+0x74> */
/* @0x110a34 ldr r4, [sp, #0x4] */
/* @0x110a38 mov r0, r7 */
/* @0x110a3c ldrb r3, [r4] */
/* @0x110a40 cmp r3, #0 */
/* @0x110a44 bne 0x110a0c <utf8_strcmp+0x18> */
/* @0x110a48 mov r0, r7 */
/* @0x110a4c bl 0x10fb38 <utf8_extract_char> */
/* @0x110a50 mov r4, r0 */
/* @0x110a54 mov r0, sp */
/* @0x110a58 bl 0x10fb38 <utf8_extract_char> */
/* @0x110a5c rsb r0, r0, r4 */
/* @0x110a60 add sp, sp, #8 */
/* @0x110a64 pop {r4, r5, r6, r7, r8, pc} */
/* @0x110a68 str r4, [sp, #0x4] */
/* @0x110a6c str r5, [sp] */
/* @0x110a70 b 0x110a48 <utf8_strcmp+0x54> */

/* ── FUNC 0x110a74 · utf8_stricmp · size=192 · insn=48 */
/* @0x110a74 push {r4, r5, r6, r7, r8, lr} */
/* @0x110a78 sub sp, sp, #8 */
/* @0x110a7c add r5, sp, #4 */
/* @0x110a80 str r0, [sp, #0x4] */
/* @0x110a84 str r1, [sp] */
/* @0x110a88 b 0x110aec <utf8_stricmp+0x78> */
/* @0x110a8c ldr r8, [sp] */
/* @0x110a90 ldrb r3, [r8] */
/* @0x110a94 cmp r3, #0 */
/* @0x110a98 beq 0x110b00 <utf8_stricmp+0x8c> */
/* @0x110a9c bl 0x10fb38 <utf8_extract_char> */
/* @0x110aa0 mov r4, r0 */
/* @0x110aa4 mov r0, sp */
/* @0x110aa8 bl 0x10fb38 <utf8_extract_char> */
/* @0x110aac ldr r2, [pc, #0x78] */
/* @0x110ab0 cmp r4, #255 */
/* @0x110ab4 mov r1, r4 */
/* @0x110ab8 ldrls r2, [pc, r2] */
/* @0x110abc ldr r12, [pc, #0x6c] */
/* @0x110ac0 ldrls r2, [r2] */
/* @0x110ac4 addls r4, r2, r4, lsl #1 */
/* @0x110ac8 ldrshls r1, [r4, #2] */
/* @0x110acc cmp r0, #255 */
/* @0x110ad0 mov r2, r0 */
/* @0x110ad4 ldrls r12, [pc, r12] */
/* @0x110ad8 ldrls r2, [r12] */
/* @0x110adc addls r3, r2, r0, lsl #1 */
/* @0x110ae0 ldrshls r2, [r3, #2] */
/* @0x110ae4 cmp r1, r2 */
/* @0x110ae8 bne 0x110b20 <utf8_stricmp+0xac> */
/* @0x110aec ldr r7, [sp, #0x4] */
/* @0x110af0 mov r0, r5 */
/* @0x110af4 ldrb r3, [r7] */
/* @0x110af8 cmp r3, #0 */
/* @0x110afc bne 0x110a8c <utf8_stricmp+0x18> */
/* @0x110b00 mov r0, r5 */
/* @0x110b04 bl 0x10fb38 <utf8_extract_char> */
/* @0x110b08 mov r4, r0 */
/* @0x110b0c mov r0, sp */
/* @0x110b10 bl 0x10fb38 <utf8_extract_char> */
/* @0x110b14 rsb r0, r0, r4 */
/* @0x110b18 add sp, sp, #8 */
/* @0x110b1c pop {r4, r5, r6, r7, r8, pc} */
/* @0x110b20 str r7, [sp, #0x4] */
/* @0x110b24 str r8, [sp] */
/* @0x110b28 b 0x110b00 <utf8_stricmp+0x8c> */
/* @0x110b2c eoreq r12, sp, r12, asr #29 */
/* @0x110b30 .word 0x002dceb0 */

/* ── FUNC 0x110b34 · utf8_strncmp · size=208 · insn=52 */
/* @0x110b34 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x110b38 sub sp, sp, #12 */
/* @0x110b3c mov r5, r0 */
/* @0x110b40 mov r4, r2 */
/* @0x110b44 str r0, [sp, #0x4] */
/* @0x110b48 str r1, [sp] */
/* @0x110b4c ldrb r3, [r0] */
/* @0x110b50 cmp r3, #0 */
/* @0x110b54 beq 0x110be8 <utf8_strncmp+0xb4> */
/* @0x110b58 ldrb r3, [r1] */
/* @0x110b5c mov r6, r1 */
/* @0x110b60 cmp r3, #0 */
/* @0x110b64 beq 0x110be8 <utf8_strncmp+0xb4> */
/* @0x110b68 cmp r2, #0 */
/* @0x110b6c ble 0x110be8 <utf8_strncmp+0xb4> */
/* @0x110b70 add r9, sp, #4 */
/* @0x110b74 b 0x110ba0 <utf8_strncmp+0x6c> */
/* @0x110b78 ldr r5, [sp, #0x4] */
/* @0x110b7c ldrb r3, [r5] */
/* @0x110b80 cmp r3, #0 */
/* @0x110b84 beq 0x110be8 <utf8_strncmp+0xb4> */
/* @0x110b88 ldr r6, [sp] */
/* @0x110b8c ldrb r3, [r6] */
/* @0x110b90 cmp r3, #0 */
/* @0x110b94 beq 0x110be8 <utf8_strncmp+0xb4> */
/* @0x110b98 cmp r4, #0 */
/* @0x110b9c beq 0x110bf0 <utf8_strncmp+0xbc> */
/* @0x110ba0 mov r0, r9 */
/* @0x110ba4 sub r4, r4, #1 */
/* @0x110ba8 bl 0x10fb38 <utf8_extract_char> */
/* @0x110bac mov r7, r0 */
/* @0x110bb0 mov r0, sp */
/* @0x110bb4 bl 0x10fb38 <utf8_extract_char> */
/* @0x110bb8 cmp r7, r0 */
/* @0x110bbc beq 0x110b78 <utf8_strncmp+0x44> */
/* @0x110bc0 str r5, [sp, #0x4] */
/* @0x110bc4 str r6, [sp] */
/* @0x110bc8 mov r0, r9 */
/* @0x110bcc bl 0x10fb38 <utf8_extract_char> */
/* @0x110bd0 mov r4, r0 */
/* @0x110bd4 mov r0, sp */
/* @0x110bd8 bl 0x10fb38 <utf8_extract_char> */
/* @0x110bdc rsb r0, r0, r4 */
/* @0x110be0 add sp, sp, #12 */
/* @0x110be4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x110be8 cmp r4, #0 */
/* @0x110bec bne 0x110bfc <utf8_strncmp+0xc8> */
/* @0x110bf0 mov r0, r4 */
/* @0x110bf4 add sp, sp, #12 */
/* @0x110bf8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x110bfc add r9, sp, #4 */
/* @0x110c00 b 0x110bc8 <utf8_strncmp+0x94> */

/* ── FUNC 0x110c04 · utf8_strstr(char const*, char const*) · size=132 · insn=33 */
/* @0x110c04 push {r4, r5, r6, r7, r8, lr} */
/* @0x110c08 sub sp, sp, #8 */
/* @0x110c0c mov r4, r0 */
/* @0x110c10 mov r5, r1 */
/* @0x110c14 bl 0x110648 <utf8_strlen> */
/* @0x110c18 mov r6, r0 */
/* @0x110c1c mov r0, r5 */
/* @0x110c20 bl 0x110648 <utf8_strlen> */
/* @0x110c24 cmp r6, #0 */
/* @0x110c28 str r4, [sp, #0x4] */
/* @0x110c2c addgt r8, sp, #4 */
/* @0x110c30 mov r7, r0 */
/* @0x110c34 movgt r0, r4 */
/* @0x110c38 movgt r4, #0 */
/* @0x110c3c bgt 0x110c54 <_Z11utf8_strstrPKcS0_+0x50> */
/* @0x110c40 b 0x110c7c <_Z11utf8_strstrPKcS0_+0x78> */
/* @0x110c44 bl 0x10fb38 <utf8_extract_char> */
/* @0x110c48 cmp r4, r6 */
/* @0x110c4c beq 0x110c7c <_Z11utf8_strstrPKcS0_+0x78> */
/* @0x110c50 ldr r0, [sp, #0x4] */
/* @0x110c54 mov r1, r5 */
/* @0x110c58 mov r2, r7 */
/* @0x110c5c bl 0x110b34 <utf8_strncmp> */
/* @0x110c60 add r4, r4, #1 */
/* @0x110c64 cmp r0, #0 */
/* @0x110c68 mov r0, r8 */
/* @0x110c6c bne 0x110c44 <_Z11utf8_strstrPKcS0_+0x40> */
/* @0x110c70 ldr r0, [sp, #0x4] */
/* @0x110c74 add sp, sp, #8 */
/* @0x110c78 pop {r4, r5, r6, r7, r8, pc} */
/* @0x110c7c mov r0, #0 */
/* @0x110c80 add sp, sp, #8 */
/* @0x110c84 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x110c88 · F_StringCount(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x110c88 push {r4, r5, r6, r7, r8, lr} */
/* @0x110c8c mov r1, #0 */
/* @0x110c90 ldr r4, [sp, #0x18] */
/* @0x110c94 mov r8, r0 */
/* @0x110c98 mov r0, r4 */
/* @0x110c9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110ca0 mov r1, #1 */
/* @0x110ca4 mov r7, r0 */
/* @0x110ca8 mov r0, r4 */
/* @0x110cac bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x110cb0 mov r4, r0 */
/* @0x110cb4 bl 0xb6538 <strlen@plt> */
/* @0x110cb8 add r6, r4, r0 */
/* @0x110cbc cmp r4, r6 */
/* @0x110cc0 bhs 0x110d0c <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x110cc4 mov r5, #0 */
/* @0x110cc8 b 0x110cd8 <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x110ccc cmp r6, r4 */
/* @0x110cd0 add r5, r5, #1 */
/* @0x110cd4 bls 0x110cf0 <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x110cd8 mov r0, r4 */
/* @0x110cdc mov r1, r7 */
/* @0x110ce0 bl 0x110c04 <_Z11utf8_strstrPKcS0_> */
/* @0x110ce4 cmp r0, #0 */
/* @0x110ce8 add r4, r0, #1 */
/* @0x110cec bne 0x110ccc <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x110cf0 vmov s15, r5 */
/* @0x110cf4 vcvt.f64.s32 d7, s15 */
/* @0x110cf8 vmov r2, r3, d7 */
/* @0x110cfc mov r1, #0 */
/* @0x110d00 stm r8, {r2, r3} */
/* @0x110d04 str r1, [r8, #0xc] */
/* @0x110d08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x110d0c mov r2, #0 */
/* @0x110d10 mov r3, #0 */
/* @0x110d14 b 0x110cfc <_Z13F_StringCountR6RValueP9CInstanceS2_iPS_+0x74> */

/* ── FUNC 0x110d18 · iScript_Random(long long) · size=128 · insn=32 */
/* @0x110d18 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x110d1c mov r5, r1 */
/* @0x110d20 mov r4, r0 */
/* @0x110d24 bl 0xc44ec <_Z8YYRandomv> */
/* @0x110d28 mvn r7, #-2147483648 */
/* @0x110d2c mvn r6, #0 */
/* @0x110d30 mov r10, r0 */
/* @0x110d34 bl 0xc44ec <_Z8YYRandomv> */
/* @0x110d38 mov r2, #0 */
/* @0x110d3c mov r3, #0 */
/* @0x110d40 cmp r4, r2 */
/* @0x110d44 sbcs r3, r5, r3 */
/* @0x110d48 mov r2, #0 */
/* @0x110d4c orr r8, r2, r10 */
/* @0x110d50 mov r3, r0 */
/* @0x110d54 and r1, r3, r7 */
/* @0x110d58 mvnlt r7, #0 */
/* @0x110d5c movge r7, #1 */
/* @0x110d60 mov r9, r0 */
/* @0x110d64 and r0, r8, r6 */
/* @0x110d68 mul r12, r7, r5 */
/* @0x110d6c movge r8, r2 */
/* @0x110d70 movlt r8, r7 */
/* @0x110d74 mla r12, r8, r4, r12 */
/* @0x110d78 umull r2, r3, r7, r4 */
/* @0x110d7c add r3, r12, r3 */
/* @0x110d80 bl 0x319414 <__aeabi_ldivmod> */
/* @0x110d84 mul r3, r7, r3 */
/* @0x110d88 umull r0, r1, r7, r2 */
/* @0x110d8c mla r2, r2, r8, r3 */
/* @0x110d90 add r1, r2, r1 */
/* @0x110d94 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x110d98 · F_IRandom(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x110d98 push {r6, lr} */
/* @0x110d9c mov r1, #0 */
/* @0x110da0 mov r6, r0 */
/* @0x110da4 ldr r0, [sp, #0x8] */
/* @0x110da8 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0x110dac mov r2, r0 */
/* @0x110db0 mov r3, r1 */
/* @0x110db4 cmp r2, #0 */
/* @0x110db8 sbcs r1, r3, #0 */
/* @0x110dbc mov r1, #0 */
/* @0x110dc0 str r1, [r6, #0xc] */
/* @0x110dc4 mvnlt r0, #0 */
/* @0x110dc8 mvnlt r1, #0 */
/* @0x110dcc movge r1, #0 */
/* @0x110dd0 movge r0, #1 */
/* @0x110dd4 adds r0, r0, r2 */
/* @0x110dd8 adc r1, r1, r3 */
/* @0x110ddc bl 0x110d18 <_Z14iScript_Randomx> */
/* @0x110de0 bl 0x319164 <__floatdidf> */
/* @0x110de4 stm r6, {r0, r1} */
/* @0x110de8 pop {r6, pc} */

/* ── FUNC 0x110dec · F_IRandomRange(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x110dec push {r4, r5, r6, r7, r8, lr} */
/* @0x110df0 mov r1, #0 */
/* @0x110df4 ldr r4, [sp, #0x18] */
/* @0x110df8 mov r8, r0 */
/* @0x110dfc mov r0, r4 */
/* @0x110e00 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0x110e04 mov r6, r0 */
/* @0x110e08 mov r7, r1 */
/* @0x110e0c mov r0, r4 */
/* @0x110e10 mov r1, #1 */
/* @0x110e14 bl 0xcea30 <_Z10YYGetInt64PK6RValuei> */
/* @0x110e18 mov r4, r0 */
/* @0x110e1c mov r5, r1 */
/* @0x110e20 cmp r6, r4 */
/* @0x110e24 sbcs r3, r7, r5 */
/* @0x110e28 blt 0x110e5c <_Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x110e2c subs r6, r6, r4 */
/* @0x110e30 sbc r7, r7, r5 */
/* @0x110e34 adds r0, r6, #1 */
/* @0x110e38 adc r1, r7, #0 */
/* @0x110e3c mov r3, #0 */
/* @0x110e40 str r3, [r8, #0xc] */
/* @0x110e44 bl 0x110d18 <_Z14iScript_Randomx> */
/* @0x110e48 adds r0, r0, r4 */
/* @0x110e4c adc r1, r1, r5 */
/* @0x110e50 bl 0x319164 <__floatdidf> */
/* @0x110e54 stm r8, {r0, r1} */
/* @0x110e58 pop {r4, r5, r6, r7, r8, pc} */
/* @0x110e5c mov r2, r0 */
/* @0x110e60 mov r3, r1 */
/* @0x110e64 subs r2, r2, r6 */
/* @0x110e68 sbc r3, r3, r7 */
/* @0x110e6c mov r4, r6 */
/* @0x110e70 adds r0, r2, #1 */
/* @0x110e74 mov r5, r7 */
/* @0x110e78 adc r1, r3, #0 */
/* @0x110e7c b 0x110e3c <_Z14F_IRandomRangeR6RValueP9CInstanceS2_iPS_+0x50> */

/* ── FUNC 0x110e80 · YYGML_random(double) · size=48 · insn=12 */
/* @0x110e80 push {r3, lr} */
/* @0x110e84 vpush {d8} */
/* @0x110e88 vmov d8, r0, r1 */
/* @0x110e8c mov r0, #0 */
/* @0x110e90 mov r1, #0 */
/* @0x110e94 movt r1, #0x3ff0 */
/* @0x110e98 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x110e9c vmov d7, r0, r1 */
/* @0x110ea0 vmul.f64 d7, d7, d8 */
/* @0x110ea4 vpop {d8} */
/* @0x110ea8 vmov r0, r1, d7 */
/* @0x110eac pop {r3, pc} */

/* ── FUNC 0x110eb0 · YYGML_random_range(double, double) · size=76 · insn=19 */
/* @0x110eb0 vmov d7, r2, r3 */
/* @0x110eb4 push {r3, lr} */
/* @0x110eb8 vpush {d8, d9} */
/* @0x110ebc vmov d8, r0, r1 */
/* @0x110ec0 mov r0, #0 */
/* @0x110ec4 mov r1, #0 */
/* @0x110ec8 vcmpe.f64 d8, d7 */
/* @0x110ecc movt r1, #0x3ff0 */
/* @0x110ed0 vmrs APSR_nzcv, fpscr */
/* @0x110ed4 vsubpl.f64 d9, d8, d7 */
/* @0x110ed8 vsubmi.f64 d9, d7, d8 */
/* @0x110edc vmovpl.f64 d8, d7 */
/* @0x110ee0 bl 0xc4598 <_Z9fYYRandomd> */
/* @0x110ee4 vmov.f64 d6, d8 */
/* @0x110ee8 vmov d7, r0, r1 */
/* @0x110eec vmla.f64 d6, d7, d9 */
/* @0x110ef0 vpop {d8, d9} */
/* @0x110ef4 vmov r0, r1, d6 */
/* @0x110ef8 pop {r3, pc} */

/* ── FUNC 0x110efc · F_RandomRange(RValue&, CInstance*, CInstance*, int, RValue*) · size=76 · insn=19 */
/* @0x110efc push {r3, r4, r5, r6, r7, lr} */
/* @0x110f00 mov r1, #0 */
/* @0x110f04 ldr r7, [sp, #0x18] */
/* @0x110f08 mov r6, r0 */
/* @0x110f0c str r1, [r0, #0xc] */
/* @0x110f10 mov r0, r7 */
/* @0x110f14 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x110f18 mov r4, r0 */
/* @0x110f1c mov r5, r1 */
/* @0x110f20 mov r0, r7 */
/* @0x110f24 mov r1, #1 */
/* @0x110f28 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x110f2c mov r2, r0 */
/* @0x110f30 mov r3, r1 */
/* @0x110f34 mov r0, r4 */
/* @0x110f38 mov r1, r5 */
/* @0x110f3c bl 0x110eb0 <_Z18YYGML_random_rangedd> */
/* @0x110f40 stm r6, {r0, r1} */
/* @0x110f44 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x110f48 · YYGML_irandom_range(int, int) · size=48 · insn=12 */
/* @0x110f48 cmp r0, r1 */
/* @0x110f4c rsblt r1, r0, r1 */
/* @0x110f50 push {r4, lr} */
/* @0x110f54 mov r4, r0 */
/* @0x110f58 rsbge r0, r1, r4 */
/* @0x110f5c addlt r0, r1, #1 */
/* @0x110f60 addge r0, r0, #1 */
/* @0x110f64 movge r4, r1 */
/* @0x110f68 asr r1, r0, #31 */
/* @0x110f6c bl 0x110d18 <_Z14iScript_Randomx> */
/* @0x110f70 add r0, r4, r0 */
/* @0x110f74 pop {r4, pc} */

/* ── FUNC 0x110f78 · YYGML_irandom(int) · size=48 · insn=12 */
/* @0x110f78 vmov.f64 d5, #1.000000e+00 */
/* @0x110f7c cmp r0, #0 */
/* @0x110f80 push {r3, lr} */
/* @0x110f84 vmov s9, r0 */
/* @0x110f88 vmov.f64 d6, #-1.000000e+00 */
/* @0x110f8c vcvt.f64.s32 d7, s9 */
/* @0x110f90 vmovge.f64 d6, d5 */
/* @0x110f94 vadd.f64 d5, d6, d7 */
/* @0x110f98 vmov r0, r1, d5 */
/* @0x110f9c bl 0x3194a0 <__fixdfdi> */
/* @0x110fa0 bl 0x110d18 <_Z14iScript_Randomx> */
/* @0x110fa4 pop {r3, pc} */

/* ── FUNC 0x110fa8 · YYGML_abs(double) · size=16 · insn=4 */
/* @0x110fa8 vmov d7, r0, r1 */
/* @0x110fac vabs.f64 d7, d7 */
/* @0x110fb0 vmov r0, r1, d7 */
/* @0x110fb4 bx lr */

/* ── FUNC 0x110fb8 · YYGML_sign(double) · size=52 · insn=13 */
/* @0x110fb8 vmov d7, r0, r1 */
/* @0x110fbc vcmpe.f64 d7, #0 */
/* @0x110fc0 vmrs APSR_nzcv, fpscr */
/* @0x110fc4 vmovlt.f64 d7, #-1.000000e+00 */
/* @0x110fc8 blt 0x110fe4 <_Z10YYGML_signd+0x2c> */
/* @0x110fcc vcmp.f64 d7, #0 */
/* @0x110fd0 vmrs APSR_nzcv, fpscr */
/* @0x110fd4 moveq r3, #0 */
/* @0x110fd8 movne r3, #1 */
/* @0x110fdc vmov s14, r3 */
/* @0x110fe0 vcvt.f64.s32 d7, s14 */
/* @0x110fe4 vmov r0, r1, d7 */
/* @0x110fe8 bx lr */

/* ── FUNC 0x110fec · anon_110fec · size=0 · insn=1 */
/* @0x110fec andeq r0, r0, r0 */

/* ── FUNC 0x110ff0 · YYGML_sins(double) · size=64 · insn=14 */
/* @0x110ff0 push {r3, lr} */
/* @0x110ff4 bl 0xb67d8 <sin@plt> */
/* @0x110ff8 vldr d5, [pc, #32] */
/* @0x110ffc vldr d6, [pc, #36] */
/* @0x111000 vmov d7, r0, r1 */
/* @0x111004 vabs.f64 d4, d7 */
/* @0x111008 vcmpe.f64 d4, d5 */
/* @0x11100c vmrs APSR_nzcv, fpscr */
/* @0x111010 vmovpl r0, r1, d7 */
/* @0x111014 vmovmi r0, r1, d6 */
/* @0x111018 pop {r3, pc} */
/* @0x11101c nop */
/* @0x111020 andhi r0, r0, r0 */
/* @0x111024 mcrlo p8, #0x7, pc, c4, c5, #0x5 */

/* ── FUNC 0x111030 · YYGML_cos(double) · size=64 · insn=14 */
/* @0x111030 push {r3, lr} */
/* @0x111034 bl 0xb67e4 <cos@plt> */
/* @0x111038 vldr d5, [pc, #32] */
/* @0x11103c vldr d6, [pc, #36] */
/* @0x111040 vmov d7, r0, r1 */
/* @0x111044 vabs.f64 d4, d7 */
/* @0x111048 vcmpe.f64 d4, d5 */
/* @0x11104c vmrs APSR_nzcv, fpscr */
/* @0x111050 vmovpl r0, r1, d7 */
/* @0x111054 vmovmi r0, r1, d6 */
/* @0x111058 pop {r3, pc} */
/* @0x11105c nop */
/* @0x111060 andhi r0, r0, r0 */
/* @0x111064 mcrlo p8, #0x7, pc, c4, c5, #0x5 */
