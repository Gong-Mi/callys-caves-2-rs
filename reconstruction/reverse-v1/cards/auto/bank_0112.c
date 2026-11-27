/* libyoyo.so 覆盖卡组 0112
 * 函数 0x1720e4..0x174288，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1720e4 · GR_Surface_Screenshot_Part(int, int, int, int, int) · size=900 · insn=225 */
/* @0x1720e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1720e8 mov r5, r3 */
/* @0x1720ec ldr r8, [pc, #0x358] */
/* @0x1720f0 sub sp, sp, #36 */
/* @0x1720f4 ldr r12, [pc, #0x354] */
/* @0x1720f8 mov r9, r0 */
/* @0x1720fc add r8, pc, r8 */
/* @0x172100 mov r6, r1 */
/* @0x172104 mov r7, r2 */
/* @0x172108 ldr r4, [sp, #0x48] */
/* @0x17210c ldr r3, [r8, r12] */
/* @0x172110 ldrb r3, [r3] */
/* @0x172114 cmp r3, #0 */
/* @0x172118 beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac> */
/* @0x17211c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x172120 mov r0, r9 */
/* @0x172124 bl 0x170f48 <_Z14GR_Surface_Geti> */
/* @0x172128 cmp r0, #0 */
/* @0x17212c beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac> */
/* @0x172130 ldr r0, [r0, #0x4] */
/* @0x172134 bl 0x17435c <_Z22GR_Texture_Get_Surfacei> */
/* @0x172138 subs r9, r0, #0 */
/* @0x17213c beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac> */
/* @0x172140 lsr r10, r6, #31 */
/* @0x172144 lsr r11, r7, #31 */
/* @0x172148 orrs r2, r10, r11 */
/* @0x17214c beq 0x1721e4 <_Z26GR_Surface_Screenshot_Partiiiii+0x100> */
/* @0x172150 ldr r0, [pc, #0x2fc] */
/* @0x172154 add r12, r6, r5 */
/* @0x172158 str r12, [sp, #0xc] */
/* @0x17215c add r12, r7, r4 */
/* @0x172160 str r12, [sp, #0x10] */
/* @0x172164 mov r2, r6 */
/* @0x172168 ldr r0, [r8, r0] */
/* @0x17216c mov r3, r7 */
/* @0x172170 ldr r1, [pc, #0x2e0] */
/* @0x172174 ldr r0, [r0] */
/* @0x172178 add r1, pc, r1 */
/* @0x17217c ldr r12, [r0] */
/* @0x172180 str r5, [sp] */
/* @0x172184 str r4, [sp, #0x4] */
/* @0x172188 ldr r12, [r12, #0xc] */
/* @0x17218c blx r12 */
/* @0x172190 mul r12, r4, r5 */
/* @0x172194 ldr r1, [pc, #0x2c0] */
/* @0x172198 mov r2, #70 */
/* @0x17219c mov r3, #1 */
/* @0x1721a0 add r1, pc, r1 */
/* @0x1721a4 lsl r12, r12, #2 */
/* @0x1721a8 str r12, [sp, #0x8] */
/* @0x1721ac mov r0, r12 */
/* @0x1721b0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1721b4 ldr r12, [sp, #0x8] */
/* @0x1721b8 mov r1, #0 */
/* @0x1721bc mov r2, r12 */
/* @0x1721c0 mov r8, r0 */
/* @0x1721c4 bl 0xb65b0 <memset@plt> */
/* @0x1721c8 cmp r10, #0 */
/* @0x1721cc bne 0x1723cc <_Z26GR_Surface_Screenshot_Partiiiii+0x2e8> */
/* @0x1721d0 ldr r12, [sp, #0xc] */
/* @0x1721d4 ldr r3, [sp, #0x10] */
/* @0x1721d8 str r10, [sp, #0x14] */
/* @0x1721dc str r5, [sp, #0xc] */
/* @0x1721e0 b 0x172274 <_Z26GR_Surface_Screenshot_Partiiiii+0x190> */
/* @0x1721e4 ldr r3, [r9, #0x4] */
/* @0x1721e8 add r12, r6, r5 */
/* @0x1721ec cmp r12, r3 */
/* @0x1721f0 addgt r3, r7, r4 */
/* @0x1721f4 strgt r3, [sp, #0x10] */
/* @0x1721f8 ble 0x17239c <_Z26GR_Surface_Screenshot_Partiiiii+0x2b8> */
/* @0x1721fc ldr r0, [pc, #0x250] */
/* @0x172200 mov lr, #0 */
/* @0x172204 str r5, [sp, #0xc] */
/* @0x172208 mov r2, r6 */
/* @0x17220c mul r10, r4, r5 */
/* @0x172210 ldr r0, [r8, r0] */
/* @0x172214 str lr, [sp, #0x14] */
/* @0x172218 mov r3, r7 */
/* @0x17221c ldr r1, [pc, #0x23c] */
/* @0x172220 ldr r0, [r0] */
/* @0x172224 add r1, pc, r1 */
/* @0x172228 lsl r10, r10, #2 */
/* @0x17222c ldr lr, [r0] */
/* @0x172230 str r5, [sp] */
/* @0x172234 str r4, [sp, #0x4] */
/* @0x172238 ldr r8, [lr, #0xc] */
/* @0x17223c str r12, [sp, #0x8] */
/* @0x172240 blx r8 */
/* @0x172244 ldr r1, [pc, #0x218] */
/* @0x172248 mov r3, #1 */
/* @0x17224c mov r2, #70 */
/* @0x172250 add r1, pc, r1 */
/* @0x172254 mov r0, r10 */
/* @0x172258 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17225c mov r2, r10 */
/* @0x172260 mov r1, #0 */
/* @0x172264 mov r8, r0 */
/* @0x172268 bl 0xb65b0 <memset@plt> */
/* @0x17226c ldr r3, [sp, #0x10] */
/* @0x172270 ldr r12, [sp, #0x8] */
/* @0x172274 cmp r11, #0 */
/* @0x172278 ldr r2, [r9, #0x4] */
/* @0x17227c rsbne r11, r7, #0 */
/* @0x172280 movne r10, r3 */
/* @0x172284 moveq r10, r4 */
/* @0x172288 movne r7, #0 */
/* @0x17228c cmp r2, r12 */
/* @0x172290 rsblt r2, r6, r2 */
/* @0x172294 strlt r2, [sp, #0xc] */
/* @0x172298 ldr r2, [r9, #0x8] */
/* @0x17229c ldr r12, [sp, #0xc] */
/* @0x1722a0 cmp r2, r3 */
/* @0x1722a4 rsblt r10, r7, r2 */
/* @0x1722a8 cmp r10, #0 */
/* @0x1722ac cmpgt r12, #0 */
/* @0x1722b0 bgt 0x1723e4 <_Z26GR_Surface_Screenshot_Partiiiii+0x300> */
/* @0x1722b4 cmp r8, #0 */
/* @0x1722b8 beq 0x172390 <_Z26GR_Surface_Screenshot_Partiiiii+0x2ac> */
/* @0x1722bc bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x1722c0 mov r1, #7 */
/* @0x1722c4 mov r7, #0 */
/* @0x1722c8 ldr r3, [r0] */
/* @0x1722cc mov r9, r0 */
/* @0x1722d0 ldr r3, [r3, #0x1c] */
/* @0x1722d4 blx r3 */
/* @0x1722d8 ldr r3, [r9] */
/* @0x1722dc mov r0, r9 */
/* @0x1722e0 mov r1, r5 */
/* @0x1722e4 ldr r3, [r3, #0xc] */
/* @0x1722e8 blx r3 */
/* @0x1722ec ldr r3, [r9] */
/* @0x1722f0 mov r0, r9 */
/* @0x1722f4 mov r1, r4 */
/* @0x1722f8 ldr r3, [r3, #0x14] */
/* @0x1722fc blx r3 */
/* @0x172300 add r2, sp, #32 */
/* @0x172304 mov r0, r9 */
/* @0x172308 mov r1, r7 */
/* @0x17230c str r7, [r2, #-0x4]! */
/* @0x172310 add r3, sp, #24 */
/* @0x172314 ldr r12, [r9] */
/* @0x172318 str r7, [sp, #0x18] */
/* @0x17231c ldr r12, [r12, #0x24] */
/* @0x172320 blx r12 */
/* @0x172324 cmp r4, r7 */
/* @0x172328 mov r10, r0 */
/* @0x17232c ble 0x172368 <_Z26GR_Surface_Screenshot_Partiiiii+0x284> */
/* @0x172330 ldr r0, [sp, #0x1c] */
/* @0x172334 lsl r5, r5, #2 */
/* @0x172338 mov r6, r8 */
/* @0x17233c mov r1, r6 */
/* @0x172340 add r7, r7, #1 */
/* @0x172344 mov r2, r5 */
/* @0x172348 add r6, r6, r5 */
/* @0x17234c bl 0xb65bc <memcpy@plt> */
/* @0x172350 ldr r0, [sp, #0x1c] */
/* @0x172354 ldr r3, [sp, #0x18] */
/* @0x172358 cmp r7, r4 */
/* @0x17235c add r0, r0, r3 */
/* @0x172360 str r0, [sp, #0x1c] */
/* @0x172364 bne 0x17233c <_Z26GR_Surface_Screenshot_Partiiiii+0x258> */
/* @0x172368 ldr r3, [r9] */
/* @0x17236c mov r1, r10 */
/* @0x172370 mov r0, r9 */
/* @0x172374 ldr r3, [r3, #0x28] */
/* @0x172378 blx r3 */
/* @0x17237c mov r0, r8 */
/* @0x172380 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172384 mov r0, r9 */
/* @0x172388 add sp, sp, #36 */
/* @0x17238c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x172390 mov r0, #0 */
/* @0x172394 add sp, sp, #36 */
/* @0x172398 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17239c ldr r3, [r9, #0x8] */
/* @0x1723a0 add lr, r7, r4 */
/* @0x1723a4 str lr, [sp, #0x10] */
/* @0x1723a8 cmp lr, r3 */
/* @0x1723ac bgt 0x1721fc <_Z26GR_Surface_Screenshot_Partiiiii+0x118> */
/* @0x1723b0 str r4, [sp] */
/* @0x1723b4 mov r1, r6 */
/* @0x1723b8 mov r2, r7 */
/* @0x1723bc mov r3, r5 */
/* @0x1723c0 bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x1723c4 mov r8, r0 */
/* @0x1723c8 b 0x1722b4 <_Z26GR_Surface_Screenshot_Partiiiii+0x1d0> */
/* @0x1723cc rsb r6, r6, #0 */
/* @0x1723d0 ldr r3, [sp, #0x10] */
/* @0x1723d4 str r6, [sp, #0x14] */
/* @0x1723d8 mov r6, #0 */
/* @0x1723dc ldr r12, [sp, #0xc] */
/* @0x1723e0 b 0x172274 <_Z26GR_Surface_Screenshot_Partiiiii+0x190> */
/* @0x1723e4 mov r3, r12 */
/* @0x1723e8 mov r0, r9 */
/* @0x1723ec mov r1, r6 */
/* @0x1723f0 mov r2, r7 */
/* @0x1723f4 str r10, [sp] */
/* @0x1723f8 lsl r6, r12, #2 */
/* @0x1723fc bl 0x17e594 <_ZN8Graphics16Surface_GrabRectEPviiii> */
/* @0x172400 ldr r12, [sp, #0x14] */
/* @0x172404 lsl r9, r5, #2 */
/* @0x172408 mla r3, r5, r11, r12 */
/* @0x17240c mov r11, #0 */
/* @0x172410 add r3, r8, r3, lsl #2 */
/* @0x172414 mov r7, r0 */
/* @0x172418 str r0, [sp, #0xc] */
/* @0x17241c mov r0, r3 */
/* @0x172420 mov r1, r7 */
/* @0x172424 mov r2, r6 */
/* @0x172428 add r11, r11, #1 */
/* @0x17242c bl 0xb65bc <memcpy@plt> */
/* @0x172430 cmp r10, r11 */
/* @0x172434 add r7, r7, r6 */
/* @0x172438 add r3, r0, r9 */
/* @0x17243c bgt 0x17241c <_Z26GR_Surface_Screenshot_Partiiiii+0x338> */
/* @0x172440 ldr r0, [sp, #0xc] */
/* @0x172444 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172448 b 0x1722b4 <_Z26GR_Surface_Screenshot_Partiiiii+0x1d0> */
/* @0x17244c eoreq pc, r7, r4, asr r11 */
/* @0x172450 .word 0xffffe4d0 */
/* @0x172454 .word 0xffffbac4 */
/* @0x172458 andseq r9, sp, r0, asr #5 */
/* @0x17245c mulseq r11, r0, lr */
/* @0x172460 andseq r9, sp, r4, lsl r2 */
/* @0x172464 andseq lr, r11, r0, ror #27 */

/* ── FUNC 0x172468 · MakeDefaultFont() · size=124 · insn=31 */
/* @0x172468 push {r4, r5, r6, lr} */
/* @0x17246c sub sp, sp, #8 */
/* @0x172470 ldr r4, [pc, #0x60] */
/* @0x172474 ldr r4, [pc, r4] */
/* @0x172478 ldr r3, [r4] */
/* @0x17247c cmp r3, #0 */
/* @0x172480 beq 0x17248c <_Z15MakeDefaultFontv+0x24> */
/* @0x172484 add sp, sp, #8 */
/* @0x172488 pop {r4, r5, r6, pc} */
/* @0x17248c ldr r3, [pc, #0x48] */
/* @0x172490 mov r1, #256 */
/* @0x172494 mov r2, #128 */
/* @0x172498 ldr r3, [pc, r3] */
/* @0x17249c ldr r0, [r3] */
/* @0x1724a0 bl 0x173bb4 <_Z14GR_Texture_AddPvii> */
/* @0x1724a4 mov r6, r0 */
/* @0x1724a8 mov r0, #144 */
/* @0x1724ac bl 0x27c524 <_Znwj> */
/* @0x1724b0 ldr r1, [pc, #0x28] */
/* @0x1724b4 mov r2, #32 */
/* @0x1724b8 str r6, [sp] */
/* @0x1724bc mov r3, #136 */
/* @0x1724c0 ldr r1, [pc, r1] */
/* @0x1724c4 mov r5, r0 */
/* @0x1724c8 bl 0xf6e8c <_ZN7CFontGMC2EPhiii> */
/* @0x1724cc str r5, [r4] */
/* @0x1724d0 add sp, sp, #8 */
/* @0x1724d4 pop {r4, r5, r6, pc} */
/* @0x1724d8 eoreq sp, r7, r0, lsr #28 */
/* @0x1724dc eoreq sp, r7, r0, lsl #28 */
/* @0x1724e0 .word 0x0027dddc */

/* ── FUNC 0x1724e4 · SetFont() · size=124 · insn=31 */
/* @0x1724e4 push {r3, r4, r5, lr} */
/* @0x1724e8 ldr r4, [pc, #0x60] */
/* @0x1724ec ldr r3, [pc, #0x60] */
/* @0x1724f0 add r4, pc, r4 */
/* @0x1724f4 ldr r5, [r4, r3] */
/* @0x1724f8 ldr r0, [r5] */
/* @0x1724fc bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x172500 cmp r0, #0 */
/* @0x172504 bne 0x17252c <_Z7SetFontv+0x48> */
/* @0x172508 ldr r3, [pc, #0x48] */
/* @0x17250c ldr r5, [r4, r3] */
/* @0x172510 ldr r3, [r5] */
/* @0x172514 cmp r3, #0 */
/* @0x172518 beq 0x172544 <_Z7SetFontv+0x60> */
/* @0x17251c ldr r2, [pc, #0x38] */
/* @0x172520 ldr r2, [r4, r2] */
/* @0x172524 str r3, [r2] */
/* @0x172528 pop {r3, r4, r5, pc} */
/* @0x17252c ldr r0, [r5] */
/* @0x172530 bl 0xfa3fc <_Z9Font_Datai> */
/* @0x172534 ldr r3, [pc, #0x20] */
/* @0x172538 ldr r3, [r4, r3] */
/* @0x17253c str r0, [r3] */
/* @0x172540 pop {r3, r4, r5, pc} */
/* @0x172544 bl 0x172468 <_Z15MakeDefaultFontv> */
/* @0x172548 ldr r3, [r5] */
/* @0x17254c b 0x17251c <_Z7SetFontv+0x38> */
/* @0x172550 eoreq pc, r7, r0, ror #14 */
/* @0x172554 .word 0xffffe650 */
/* @0x172558 .word 0xffffe644 */
/* @0x17255c .word 0xffffe654 */

/* ── FUNC 0x172560 · Split_TextBlock(char const*, int, TStringList*) · size=1384 · insn=346 */
/* @0x172560 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x172564 subs r5, r0, #0 */
/* @0x172568 sub sp, sp, #52 */
/* @0x17256c mov r8, r1 */
/* @0x172570 str r2, [sp, #0xc] */
/* @0x172574 beq 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288> */
/* @0x172578 cmp r1, #0 */
/* @0x17257c ldr r0, [r2] */
/* @0x172580 movw r3, #0x9680 */
/* @0x172584 movt r3, #0x98 */
/* @0x172588 movlt r8, r3 */
/* @0x17258c cmp r0, #0 */
/* @0x172590 beq 0x1725a8 <_Z15Split_TextBlockPKciP11TStringList+0x48> */
/* @0x172594 ldr r4, [r0] */
/* @0x172598 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x17259c cmp r4, #0 */
/* @0x1725a0 mov r0, r4 */
/* @0x1725a4 bne 0x172594 <_Z15Split_TextBlockPKciP11TStringList+0x34> */
/* @0x1725a8 ldr r12, [sp, #0xc] */
/* @0x1725ac mov r3, #0 */
/* @0x1725b0 ldr r0, [r12, #0xc] */
/* @0x1725b4 str r3, [r12, #0x8] */
/* @0x1725b8 cmp r0, r3 */
/* @0x1725bc str r3, [r12] */
/* @0x1725c0 beq 0x1725c8 <_Z15Split_TextBlockPKciP11TStringList+0x68> */
/* @0x1725c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1725c8 ldr r12, [sp, #0xc] */
/* @0x1725cc mov r4, #0 */
/* @0x1725d0 mov r0, r5 */
/* @0x1725d4 str r4, [r12, #0xc] */
/* @0x1725d8 bl 0x212da8 <_Z19String_Replace_HashPc> */
/* @0x1725dc ldr r1, [pc, #0x4d0] */
/* @0x1725e0 mov r3, r4 */
/* @0x1725e4 movw r2, #0x117 */
/* @0x1725e8 add r1, pc, r1 */
/* @0x1725ec add r6, r0, #1 */
/* @0x1725f0 mov r11, r0 */
/* @0x1725f4 lsl r6, r6, #1 */
/* @0x1725f8 mov r0, r6 */
/* @0x1725fc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x172600 cmp r11, r4 */
/* @0x172604 str r5, [sp, #0x2c] */
/* @0x172608 str r0, [sp, #0x4] */
/* @0x17260c ble 0x172a70 <_Z15Split_TextBlockPKciP11TStringList+0x510> */
/* @0x172610 sub r4, r6, #2 */
/* @0x172614 add r6, sp, #44 */
/* @0x172618 add r4, r0, r4 */
/* @0x17261c mov r5, r0 */
/* @0x172620 mov r0, r6 */
/* @0x172624 bl 0x10fb38 <utf8_extract_char> */
/* @0x172628 strh r0, [r5], #2 */
/* @0x17262c cmp r5, r4 */
/* @0x172630 bne 0x172620 <_Z15Split_TextBlockPKciP11TStringList+0xc0> */
/* @0x172634 ldr r12, [sp, #0x4] */
/* @0x172638 mov r3, #0 */
/* @0x17263c ldr r0, [sp, #0xc] */
/* @0x172640 mov r4, r3 */
/* @0x172644 strh r3, [r5] */
/* @0x172648 ldrh r9, [r12] */
/* @0x17264c str r12, [r0, #0xc] */
/* @0x172650 movw r12, #0x9680 */
/* @0x172654 movt r12, #0x98 */
/* @0x172658 str r12, [sp, #0x18] */
/* @0x17265c ldr r12, [pc, #0x454] */
/* @0x172660 str r3, [sp, #0x8] */
/* @0x172664 add r12, pc, r12 */
/* @0x172668 str r12, [sp, #0x20] */
/* @0x17266c ldr r12, [pc, #0x448] */
/* @0x172670 str r8, [sp, #0x10] */
/* @0x172674 add r12, pc, r12 */
/* @0x172678 str r12, [sp, #0x24] */
/* @0x17267c ldr r12, [pc, #0x43c] */
/* @0x172680 add r12, pc, r12 */
/* @0x172684 str r12, [sp, #0x1c] */
/* @0x172688 ldr r12, [sp, #0x10] */
/* @0x17268c lsl r2, r4, #1 */
/* @0x172690 ldr r0, [sp, #0x18] */
/* @0x172694 cmp r12, r0 */
/* @0x172698 beq 0x172910 <_Z15Split_TextBlockPKciP11TStringList+0x3b0> */
/* @0x17269c cmp r11, r4 */
/* @0x1726a0 ble 0x1726d8 <_Z15Split_TextBlockPKciP11TStringList+0x178> */
/* @0x1726a4 ldr r12, [sp, #0x4] */
/* @0x1726a8 add r3, r12, r2 */
/* @0x1726ac ldrh r1, [r12, r2] */
/* @0x1726b0 cmp r1, #32 */
/* @0x1726b4 beq 0x1726c8 <_Z15Split_TextBlockPKciP11TStringList+0x168> */
/* @0x1726b8 b 0x1727f4 <_Z15Split_TextBlockPKciP11TStringList+0x294> */
/* @0x1726bc ldrh r2, [r3, #2]! */
/* @0x1726c0 cmp r2, #32 */
/* @0x1726c4 bne 0x1727f0 <_Z15Split_TextBlockPKciP11TStringList+0x290> */
/* @0x1726c8 add r4, r4, #1 */
/* @0x1726cc cmp r4, r11 */
/* @0x1726d0 bne 0x1726bc <_Z15Split_TextBlockPKciP11TStringList+0x15c> */
/* @0x1726d4 lsl r2, r4, #1 */
/* @0x1726d8 ldr r12, [sp, #0x4] */
/* @0x1726dc mov r1, r4 */
/* @0x1726e0 mov r5, r4 */
/* @0x1726e4 add r10, r12, r2 */
/* @0x1726e8 ldrh r2, [r12, r2] */
/* @0x1726ec cmp r2, #10 */
/* @0x1726f0 beq 0x1728b0 <_Z15Split_TextBlockPKciP11TStringList+0x350> */
/* @0x1726f4 ldr r12, [sp, #0x8] */
/* @0x1726f8 cmp r4, r12 */
/* @0x1726fc beq 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288> */
/* @0x172700 cmp r4, r11 */
/* @0x172704 beq 0x1728cc <_Z15Split_TextBlockPKciP11TStringList+0x36c> */
/* @0x172708 cmp r2, #32 */
/* @0x17270c beq 0x1729b8 <_Z15Split_TextBlockPKciP11TStringList+0x458> */
/* @0x172710 ldr r12, [sp, #0x8] */
/* @0x172714 cmp r4, r12 */
/* @0x172718 ble 0x172760 <_Z15Split_TextBlockPKciP11TStringList+0x200> */
/* @0x17271c sub r5, r4, #1 */
/* @0x172720 ldr r12, [sp, #0x4] */
/* @0x172724 lsl r3, r5, #1 */
/* @0x172728 ldrh r2, [r12, r3] */
/* @0x17272c cmp r2, #32 */
/* @0x172730 beq 0x1729b4 <_Z15Split_TextBlockPKciP11TStringList+0x454> */
/* @0x172734 add r3, r12, r3 */
/* @0x172738 ldr r1, [sp, #0x8] */
/* @0x17273c b 0x172750 <_Z15Split_TextBlockPKciP11TStringList+0x1f0> */
/* @0x172740 ldrh r2, [r3, #-2]! */
/* @0x172744 sub r5, r5, #1 */
/* @0x172748 cmp r2, #32 */
/* @0x17274c beq 0x1729b4 <_Z15Split_TextBlockPKciP11TStringList+0x454> */
/* @0x172750 cmp r5, r1 */
/* @0x172754 bne 0x172740 <_Z15Split_TextBlockPKciP11TStringList+0x1e0> */
/* @0x172758 ldr r12, [sp, #0x4] */
/* @0x17275c add r10, r12, r5, lsl #1 */
/* @0x172760 ldr r12, [sp, #0x8] */
/* @0x172764 cmp r5, r12 */
/* @0x172768 beq 0x1729d8 <_Z15Split_TextBlockPKciP11TStringList+0x478> */
/* @0x17276c ldr r12, [sp, #0xc] */
/* @0x172770 mov r1, #0 */
/* @0x172774 mov r0, #8 */
/* @0x172778 ldr r2, [r12, #0x8] */
/* @0x17277c strh r1, [r10] */
/* @0x172780 ldr r1, [sp, #0x1c] */
/* @0x172784 add r3, r2, #1 */
/* @0x172788 mov r2, #93 */
/* @0x17278c str r3, [r12, #0x8] */
/* @0x172790 mov r3, #1 */
/* @0x172794 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x172798 ldr r12, [sp, #0xc] */
/* @0x17279c ldr r1, [sp, #0x8] */
/* @0x1727a0 mov r2, #0 */
/* @0x1727a4 ldr r3, [r12] */
/* @0x1727a8 ldr r12, [sp, #0x4] */
/* @0x1727ac cmp r3, r2 */
/* @0x1727b0 add r10, r12, r1, lsl #1 */
/* @0x1727b4 ldr r12, [sp, #0xc] */
/* @0x1727b8 str r2, [r0] */
/* @0x1727bc str r10, [r0, #0x4] */
/* @0x1727c0 streq r0, [r12] */
/* @0x1727c4 ldrne r3, [r12, #0x4] */
/* @0x1727c8 ldr r12, [sp, #0xc] */
/* @0x1727cc strne r0, [r3] */
/* @0x1727d0 str r0, [r12, #0x4] */
/* @0x1727d4 add r4, r5, #1 */
/* @0x1727d8 str r4, [sp, #0x8] */
/* @0x1727dc ldr r12, [sp, #0x8] */
/* @0x1727e0 cmp r11, r12 */
/* @0x1727e4 bgt 0x172688 <_Z15Split_TextBlockPKciP11TStringList+0x128> */
/* @0x1727e8 add sp, sp, #52 */
/* @0x1727ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1727f0 lsl r2, r4, #1 */
/* @0x1727f4 ldr r12, [sp, #0x10] */
/* @0x1727f8 cmp r11, r4 */
/* @0x1727fc cmpgt r12, #0 */
/* @0x172800 ble 0x1726d8 <_Z15Split_TextBlockPKciP11TStringList+0x178> */
/* @0x172804 ldr r12, [sp, #0x4] */
/* @0x172808 add r10, r12, r2 */
/* @0x17280c ldrh r1, [r12, r2] */
/* @0x172810 cmp r1, #10 */
/* @0x172814 beq 0x172a54 <_Z15Split_TextBlockPKciP11TStringList+0x4f4> */
/* @0x172818 ldr r7, [pc, #0x2a4] */
/* @0x17281c mov r6, r10 */
/* @0x172820 str r9, [sp, #0x14] */
/* @0x172824 mov r8, #0 */
/* @0x172828 mov r9, r4 */
/* @0x17282c ldr r7, [pc, r7] */
/* @0x172830 ldr r4, [sp, #0x10] */
/* @0x172834 b 0x17284c <_Z15Split_TextBlockPKciP11TStringList+0x2ec> */
/* @0x172838 ldrh r1, [r6, #2] */
/* @0x17283c mov r9, r5 */
/* @0x172840 mov r6, r10 */
/* @0x172844 cmp r1, #10 */
/* @0x172848 beq 0x1728ac <_Z15Split_TextBlockPKciP11TStringList+0x34c> */
/* @0x17284c ldr r0, [r7] */
/* @0x172850 add r5, r9, #1 */
/* @0x172854 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi> */
/* @0x172858 add r10, r10, #2 */
/* @0x17285c add r8, r8, r0 */
/* @0x172860 cmp r4, r8 */
/* @0x172864 cmpgt r11, r5 */
/* @0x172868 bgt 0x172838 <_Z15Split_TextBlockPKciP11TStringList+0x2d8> */
/* @0x17286c ldr r12, [sp, #0x10] */
/* @0x172870 mov r4, r9 */
/* @0x172874 ldr r9, [sp, #0x14] */
/* @0x172878 cmp r12, r8 */
/* @0x17287c bge 0x172a84 <_Z15Split_TextBlockPKciP11TStringList+0x524> */
/* @0x172880 ldr r12, [sp, #0x4] */
/* @0x172884 lsl r6, r4, #1 */
/* @0x172888 ldr r0, [r7] */
/* @0x17288c mov r5, r4 */
/* @0x172890 add r10, r12, r6 */
/* @0x172894 ldrh r1, [r12, r6] */
/* @0x172898 bl 0xf6e78 <_ZN7CFontGM8GetShiftEi> */
/* @0x17289c ldr r12, [sp, #0x4] */
/* @0x1728a0 mov r1, r4 */
/* @0x1728a4 ldrh r2, [r12, r6] */
/* @0x1728a8 b 0x1726ec <_Z15Split_TextBlockPKciP11TStringList+0x18c> */
/* @0x1728ac ldr r9, [sp, #0x14] */
/* @0x1728b0 ldr r12, [sp, #0xc] */
/* @0x1728b4 mov r1, #0 */
/* @0x1728b8 mov r0, #8 */
/* @0x1728bc ldr r2, [r12, #0x8] */
/* @0x1728c0 strh r1, [r10] */
/* @0x1728c4 ldr r1, [sp, #0x24] */
/* @0x1728c8 b 0x172784 <_Z15Split_TextBlockPKciP11TStringList+0x224> */
/* @0x1728cc ldr r12, [sp, #0x4] */
/* @0x1728d0 add r1, r12, r1, lsl #1 */
/* @0x1728d4 ldrh r3, [r1, #-2] */
/* @0x1728d8 cmp r3, #32 */
/* @0x1728dc bne 0x1728f8 <_Z15Split_TextBlockPKciP11TStringList+0x398> */
/* @0x1728e0 add r3, r12, r5, lsl #1 */
/* @0x1728e4 sub r3, r3, #2 */
/* @0x1728e8 ldrh r2, [r3, #-2] */
/* @0x1728ec sub r5, r5, #1 */
/* @0x1728f0 cmp r2, #32 */
/* @0x1728f4 beq 0x1728e4 <_Z15Split_TextBlockPKciP11TStringList+0x384> */
/* @0x1728f8 ldr r12, [sp, #0x8] */
/* @0x1728fc cmp r5, r12 */
/* @0x172900 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274> */
/* @0x172904 ldr r12, [sp, #0x4] */
/* @0x172908 add r10, r12, r5, lsl #1 */
/* @0x17290c b 0x17276c <_Z15Split_TextBlockPKciP11TStringList+0x20c> */
/* @0x172910 cmp r11, r4 */
/* @0x172914 ble 0x172a5c <_Z15Split_TextBlockPKciP11TStringList+0x4fc> */
/* @0x172918 ldr r12, [sp, #0x4] */
/* @0x17291c add r3, r12, r2 */
/* @0x172920 ldrh r2, [r12, r2] */
/* @0x172924 cmp r2, #13 */
/* @0x172928 beq 0x172aa4 <_Z15Split_TextBlockPKciP11TStringList+0x544> */
/* @0x17292c cmp r2, #10 */
/* @0x172930 beq 0x172a30 <_Z15Split_TextBlockPKciP11TStringList+0x4d0> */
/* @0x172934 mov r2, r3 */
/* @0x172938 b 0x17294c <_Z15Split_TextBlockPKciP11TStringList+0x3ec> */
/* @0x17293c cmp r9, #13 */
/* @0x172940 beq 0x172a98 <_Z15Split_TextBlockPKciP11TStringList+0x538> */
/* @0x172944 cmp r9, #10 */
/* @0x172948 beq 0x172a8c <_Z15Split_TextBlockPKciP11TStringList+0x52c> */
/* @0x17294c add r4, r4, #1 */
/* @0x172950 add r3, r3, #2 */
/* @0x172954 cmp r4, r11 */
/* @0x172958 ldrh r9, [r2, #2] */
/* @0x17295c mov r2, r3 */
/* @0x172960 bne 0x17293c <_Z15Split_TextBlockPKciP11TStringList+0x3dc> */
/* @0x172964 mov r4, r9 */
/* @0x172968 mov r5, r11 */
/* @0x17296c cmp r9, #10 */
/* @0x172970 beq 0x172a1c <_Z15Split_TextBlockPKciP11TStringList+0x4bc> */
/* @0x172974 cmp r9, #13 */
/* @0x172978 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424> */
/* @0x17297c cmp r4, #10 */
/* @0x172980 beq 0x172a48 <_Z15Split_TextBlockPKciP11TStringList+0x4e8> */
/* @0x172984 ldr r12, [sp, #0xc] */
/* @0x172988 mov r1, #0 */
/* @0x17298c mov r0, #8 */
/* @0x172990 mov r9, r4 */
/* @0x172994 ldr r2, [r12, #0x8] */
/* @0x172998 strh r1, [r3] */
/* @0x17299c add r3, r2, #1 */
/* @0x1729a0 ldr r1, [sp, #0x20] */
/* @0x1729a4 str r3, [r12, #0x8] */
/* @0x1729a8 mov r2, #93 */
/* @0x1729ac mov r3, #1 */
/* @0x1729b0 b 0x172794 <_Z15Split_TextBlockPKciP11TStringList+0x234> */
/* @0x1729b4 mov r1, r5 */
/* @0x1729b8 ldr r12, [sp, #0x8] */
/* @0x1729bc cmp r5, r12 */
/* @0x1729c0 bgt 0x1728cc <_Z15Split_TextBlockPKciP11TStringList+0x36c> */
/* @0x1729c4 ldr r12, [sp, #0x4] */
/* @0x1729c8 add r10, r12, r1, lsl #1 */
/* @0x1729cc ldr r12, [sp, #0x8] */
/* @0x1729d0 cmp r5, r12 */
/* @0x1729d4 bne 0x17276c <_Z15Split_TextBlockPKciP11TStringList+0x20c> */
/* @0x1729d8 ldrh r2, [r10] */
/* @0x1729dc movw r3, #0xffdf */
/* @0x1729e0 and r3, r2, r3 */
/* @0x1729e4 cmp r3, #0 */
/* @0x1729e8 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274> */
/* @0x1729ec ldr r12, [sp, #0x4] */
/* @0x1729f0 add r2, r12, r5, lsl #1 */
/* @0x1729f4 ldrh r1, [r2, #2]! */
/* @0x1729f8 movw r3, #0xffdf */
/* @0x1729fc add r5, r5, #1 */
/* @0x172a00 and r3, r1, r3 */
/* @0x172a04 cmp r3, #0 */
/* @0x172a08 bne 0x1729f4 <_Z15Split_TextBlockPKciP11TStringList+0x494> */
/* @0x172a0c ldr r12, [sp, #0x8] */
/* @0x172a10 cmp r5, r12 */
/* @0x172a14 beq 0x1727d4 <_Z15Split_TextBlockPKciP11TStringList+0x274> */
/* @0x172a18 b 0x172904 <_Z15Split_TextBlockPKciP11TStringList+0x3a4> */
/* @0x172a1c cmp r4, #13 */
/* @0x172a20 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424> */
/* @0x172a24 add r4, r5, #1 */
/* @0x172a28 mov r9, #10 */
/* @0x172a2c b 0x1727dc <_Z15Split_TextBlockPKciP11TStringList+0x27c> */
/* @0x172a30 cmp r9, #10 */
/* @0x172a34 beq 0x172a8c <_Z15Split_TextBlockPKciP11TStringList+0x52c> */
/* @0x172a38 cmp r9, #13 */
/* @0x172a3c mov r5, r4 */
/* @0x172a40 movne r4, r2 */
/* @0x172a44 bne 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424> */
/* @0x172a48 add r4, r5, #1 */
/* @0x172a4c mov r9, #13 */
/* @0x172a50 b 0x1727dc <_Z15Split_TextBlockPKciP11TStringList+0x27c> */
/* @0x172a54 mov r5, r4 */
/* @0x172a58 b 0x1728b0 <_Z15Split_TextBlockPKciP11TStringList+0x350> */
/* @0x172a5c ldr r12, [sp, #0x4] */
/* @0x172a60 mov r5, r4 */
/* @0x172a64 add r3, r12, r2 */
/* @0x172a68 ldrh r4, [r12, r2] */
/* @0x172a6c b 0x17296c <_Z15Split_TextBlockPKciP11TStringList+0x40c> */
/* @0x172a70 ldr r12, [sp, #0x4] */
/* @0x172a74 ldr r0, [sp, #0xc] */
/* @0x172a78 strh r4, [r12] */
/* @0x172a7c str r12, [r0, #0xc] */
/* @0x172a80 b 0x1727e8 <_Z15Split_TextBlockPKciP11TStringList+0x288> */
/* @0x172a84 mov r4, r5 */
/* @0x172a88 b 0x1726d4 <_Z15Split_TextBlockPKciP11TStringList+0x174> */
/* @0x172a8c mov r5, r4 */
/* @0x172a90 mov r4, #10 */
/* @0x172a94 b 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424> */
/* @0x172a98 mov r5, r4 */
/* @0x172a9c mov r4, #13 */
/* @0x172aa0 b 0x172984 <_Z15Split_TextBlockPKciP11TStringList+0x424> */
/* @0x172aa4 cmp r9, #10 */
/* @0x172aa8 bne 0x172a98 <_Z15Split_TextBlockPKciP11TStringList+0x538> */
/* @0x172aac mov r5, r4 */
/* @0x172ab0 b 0x172a24 <_Z15Split_TextBlockPKciP11TStringList+0x4c4> */
/* @0x172ab4 andseq r8, sp, r4, lsr #29 */
/* @0x172ab8 andseq r8, sp, r4, ror #28 */
/* @0x172abc andseq r8, sp, r4, asr lr */
/* @0x172ac0 andseq r8, sp, r8, asr #28 */
/* @0x172ac4 eoreq sp, r7, r8, ror r10 */

/* ── FUNC 0x172ac8 · GR_Text_Set_Font(int) · size=104 · insn=26 */
/* @0x172ac8 push {r3, r4, r5, lr} */
/* @0x172acc mov r5, r0 */
/* @0x172ad0 bl 0xfa2a8 <_Z11Font_Existsi> */
/* @0x172ad4 ldr r4, [pc, #0x48] */
/* @0x172ad8 add r4, pc, r4 */
/* @0x172adc cmp r0, #0 */
/* @0x172ae0 bne 0x172b0c <_Z16GR_Text_Set_Fonti+0x44> */
/* @0x172ae4 ldr r3, [pc, #0x3c] */
/* @0x172ae8 ldr r3, [r4, r3] */
/* @0x172aec ldr r3, [r3] */
/* @0x172af0 cmp r3, #0 */
/* @0x172af4 beq 0x172b1c <_Z16GR_Text_Set_Fonti+0x54> */
/* @0x172af8 ldr r3, [pc, #0x2c] */
/* @0x172afc mvn r2, #0 */
/* @0x172b00 ldr r3, [r4, r3] */
/* @0x172b04 str r2, [r3] */
/* @0x172b08 pop {r3, r4, r5, pc} */
/* @0x172b0c ldr r3, [pc, #0x18] */
/* @0x172b10 ldr r3, [r4, r3] */
/* @0x172b14 str r5, [r3] */
/* @0x172b18 pop {r3, r4, r5, pc} */
/* @0x172b1c bl 0x172468 <_Z15MakeDefaultFontv> */
/* @0x172b20 b 0x172af8 <_Z16GR_Text_Set_Fonti+0x30> */
/* @0x172b24 eoreq pc, r7, r8, ror r1 */
/* @0x172b28 .word 0xffffe644 */
/* @0x172b2c .word 0xffffe650 */

/* ── FUNC 0x172b30 · GR_Text_Set_HAlign(int) · size=76 · insn=19 */
/* @0x172b30 cmp r0, #1 */
/* @0x172b34 ldr r3, [pc, #0x38] */
/* @0x172b38 add r3, pc, r3 */
/* @0x172b3c beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34> */
/* @0x172b40 cmp r0, #2 */
/* @0x172b44 beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34> */
/* @0x172b48 cmp r0, #0 */
/* @0x172b4c beq 0x172b64 <_Z18GR_Text_Set_HAligni+0x34> */
/* @0x172b50 ldr r1, [pc, #0x20] */
/* @0x172b54 mov r2, #0 */
/* @0x172b58 ldr r3, [r3, r1] */
/* @0x172b5c str r2, [r3] */
/* @0x172b60 bx lr */
/* @0x172b64 ldr r2, [pc, #0xc] */
/* @0x172b68 ldr r3, [r3, r2] */
/* @0x172b6c str r0, [r3] */
/* @0x172b70 bx lr */
/* @0x172b74 eoreq pc, r7, r8, lsl r1 */
/* @0x172b78 .word 0xffffe658 */

/* ── FUNC 0x172b7c · GR_Text_Set_VAlign(int) · size=76 · insn=19 */
/* @0x172b7c cmp r0, #1 */
/* @0x172b80 ldr r3, [pc, #0x38] */
/* @0x172b84 add r3, pc, r3 */
/* @0x172b88 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34> */
/* @0x172b8c cmp r0, #2 */
/* @0x172b90 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34> */
/* @0x172b94 cmp r0, #0 */
/* @0x172b98 beq 0x172bb0 <_Z18GR_Text_Set_VAligni+0x34> */
/* @0x172b9c ldr r1, [pc, #0x20] */
/* @0x172ba0 mov r2, #0 */
/* @0x172ba4 ldr r3, [r3, r1] */
/* @0x172ba8 str r2, [r3] */
/* @0x172bac bx lr */
/* @0x172bb0 ldr r2, [pc, #0xc] */
/* @0x172bb4 ldr r3, [r3, r2] */
/* @0x172bb8 str r0, [r3] */
/* @0x172bbc bx lr */
/* @0x172bc0 eoreq pc, r7, r12, asr #1 */
/* @0x172bc4 .word 0xffffe65c */

/* ── FUNC 0x172bc8 · GR_Text_Width(char const*, int, int) · size=320 · insn=80 */
/* @0x172bc8 push {r4, r5, r6, lr} */
/* @0x172bcc sub sp, sp, #16 */
/* @0x172bd0 mov r5, r2 */
/* @0x172bd4 mov r6, r0 */
/* @0x172bd8 mov r4, #0 */
/* @0x172bdc str r4, [sp, #0x4] */
/* @0x172be0 str r4, [sp] */
/* @0x172be4 str r4, [sp, #0xc] */
/* @0x172be8 str r4, [sp, #0x8] */
/* @0x172bec bl 0x1724e4 <_Z7SetFontv> */
/* @0x172bf0 mov r0, r6 */
/* @0x172bf4 mov r1, r5 */
/* @0x172bf8 mov r2, sp */
/* @0x172bfc bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x172c00 ldr r3, [sp, #0x8] */
/* @0x172c04 cmp r3, r4 */
/* @0x172c08 ble 0x172cfc <_Z13GR_Text_WidthPKcii+0x134> */
/* @0x172c0c ldr r5, [pc, #0xf0] */
/* @0x172c10 mov r6, r4 */
/* @0x172c14 ldr r5, [pc, r5] */
/* @0x172c18 ldr r1, [sp] */
/* @0x172c1c ldr r0, [r5] */
/* @0x172c20 cmp r1, #0 */
/* @0x172c24 beq 0x172c4c <_Z13GR_Text_WidthPKcii+0x84> */
/* @0x172c28 cmp r4, #0 */
/* @0x172c2c movne r3, r4 */
/* @0x172c30 bne 0x172c40 <_Z13GR_Text_WidthPKcii+0x78> */
/* @0x172c34 b 0x172cec <_Z13GR_Text_WidthPKcii+0x124> */
/* @0x172c38 subs r3, r3, #1 */
/* @0x172c3c beq 0x172cec <_Z13GR_Text_WidthPKcii+0x124> */
/* @0x172c40 ldr r1, [r1] */
/* @0x172c44 cmp r1, #0 */
/* @0x172c48 bne 0x172c38 <_Z13GR_Text_WidthPKcii+0x70> */
/* @0x172c4c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x172c50 cmp r0, r6 */
/* @0x172c54 blt 0x172c94 <_Z13GR_Text_WidthPKcii+0xcc> */
/* @0x172c58 ldr r1, [sp] */
/* @0x172c5c ldr r0, [r5] */
/* @0x172c60 cmp r1, #0 */
/* @0x172c64 beq 0x172c8c <_Z13GR_Text_WidthPKcii+0xc4> */
/* @0x172c68 cmp r4, #0 */
/* @0x172c6c movne r3, r4 */
/* @0x172c70 bne 0x172c80 <_Z13GR_Text_WidthPKcii+0xb8> */
/* @0x172c74 b 0x172cf4 <_Z13GR_Text_WidthPKcii+0x12c> */
/* @0x172c78 subs r3, r3, #1 */
/* @0x172c7c beq 0x172cf4 <_Z13GR_Text_WidthPKcii+0x12c> */
/* @0x172c80 ldr r1, [r1] */
/* @0x172c84 cmp r1, #0 */
/* @0x172c88 bne 0x172c78 <_Z13GR_Text_WidthPKcii+0xb0> */
/* @0x172c8c bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x172c90 mov r6, r0 */
/* @0x172c94 ldr r3, [sp, #0x8] */
/* @0x172c98 add r4, r4, #1 */
/* @0x172c9c cmp r3, r4 */
/* @0x172ca0 bgt 0x172c18 <_Z13GR_Text_WidthPKcii+0x50> */
/* @0x172ca4 ldr r0, [sp] */
/* @0x172ca8 cmp r0, #0 */
/* @0x172cac beq 0x172cc4 <_Z13GR_Text_WidthPKcii+0xfc> */
/* @0x172cb0 ldr r4, [r0] */
/* @0x172cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172cb8 cmp r4, #0 */
/* @0x172cbc mov r0, r4 */
/* @0x172cc0 bne 0x172cb0 <_Z13GR_Text_WidthPKcii+0xe8> */
/* @0x172cc4 ldr r0, [sp, #0xc] */
/* @0x172cc8 mov r3, #0 */
/* @0x172ccc str r3, [sp, #0x8] */
/* @0x172cd0 cmp r0, r3 */
/* @0x172cd4 str r3, [sp] */
/* @0x172cd8 beq 0x172ce0 <_Z13GR_Text_WidthPKcii+0x118> */
/* @0x172cdc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172ce0 mov r0, r6 */
/* @0x172ce4 add sp, sp, #16 */
/* @0x172ce8 pop {r4, r5, r6, pc} */
/* @0x172cec ldr r1, [r1, #0x4] */
/* @0x172cf0 b 0x172c4c <_Z13GR_Text_WidthPKcii+0x84> */
/* @0x172cf4 ldr r1, [r1, #0x4] */
/* @0x172cf8 b 0x172c8c <_Z13GR_Text_WidthPKcii+0xc4> */
/* @0x172cfc mov r6, r4 */
/* @0x172d00 b 0x172ca4 <_Z13GR_Text_WidthPKcii+0xdc> */
/* @0x172d04 mlaeq r7, r0, r6, sp */

/* ── FUNC 0x172d08 · GR_Text_Height(char const*, int, int) · size=240 · insn=60 */
/* @0x172d08 push {r4, r5, r6, lr} */
/* @0x172d0c sub sp, sp, #16 */
/* @0x172d10 mov r5, r2 */
/* @0x172d14 mov r6, r0 */
/* @0x172d18 mov r3, #0 */
/* @0x172d1c mov r4, r1 */
/* @0x172d20 str r3, [sp, #0x4] */
/* @0x172d24 str r3, [sp] */
/* @0x172d28 str r3, [sp, #0xc] */
/* @0x172d2c str r3, [sp, #0x8] */
/* @0x172d30 bl 0x1724e4 <_Z7SetFontv> */
/* @0x172d34 mov r0, r6 */
/* @0x172d38 mov r1, r5 */
/* @0x172d3c mov r2, sp */
/* @0x172d40 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x172d44 cmp r4, #0 */
/* @0x172d48 blt 0x172dc8 <_Z14GR_Text_HeightPKcii+0xc0> */
/* @0x172d4c ldr r3, [sp, #0x8] */
/* @0x172d50 cmp r3, #0 */
/* @0x172d54 movle r5, #0 */
/* @0x172d58 ble 0x172d80 <_Z14GR_Text_HeightPKcii+0x78> */
/* @0x172d5c ldr r3, [pc, #0x84] */
/* @0x172d60 ldr r1, [pc, #0x84] */
/* @0x172d64 ldr r3, [pc, r3] */
/* @0x172d68 add r1, pc, r1 */
/* @0x172d6c ldr r0, [r3] */
/* @0x172d70 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x172d74 ldr r5, [sp, #0x8] */
/* @0x172d78 sub r5, r5, #1 */
/* @0x172d7c mla r5, r4, r5, r0 */
/* @0x172d80 ldr r0, [sp] */
/* @0x172d84 cmp r0, #0 */
/* @0x172d88 beq 0x172da0 <_Z14GR_Text_HeightPKcii+0x98> */
/* @0x172d8c ldr r4, [r0] */
/* @0x172d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172d94 cmp r4, #0 */
/* @0x172d98 mov r0, r4 */
/* @0x172d9c bne 0x172d8c <_Z14GR_Text_HeightPKcii+0x84> */
/* @0x172da0 ldr r0, [sp, #0xc] */
/* @0x172da4 mov r3, #0 */
/* @0x172da8 str r3, [sp, #0x8] */
/* @0x172dac cmp r0, r3 */
/* @0x172db0 str r3, [sp] */
/* @0x172db4 beq 0x172dbc <_Z14GR_Text_HeightPKcii+0xb4> */
/* @0x172db8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172dbc mov r0, r5 */
/* @0x172dc0 add sp, sp, #16 */
/* @0x172dc4 pop {r4, r5, r6, pc} */
/* @0x172dc8 ldr r3, [pc, #0x20] */
/* @0x172dcc ldr r1, [pc, #0x20] */
/* @0x172dd0 ldr r3, [pc, r3] */
/* @0x172dd4 add r1, pc, r1 */
/* @0x172dd8 ldr r0, [r3] */
/* @0x172ddc bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x172de0 mov r4, r0 */
/* @0x172de4 b 0x172d4c <_Z14GR_Text_HeightPKcii+0x44> */
/* @0x172de8 eoreq sp, r7, r0, asr #10 */
/* @0x172dec andseq r8, sp, r0, lsr #15 */
/* @0x172df0 .word 0x0027d4d4 */
/* @0x172df4 andseq r8, sp, r4, lsr r7 */

/* ── FUNC 0x172df8 · GR_Text_Draw(float, float, char const*, int, int) · size=624 · insn=156 */
/* @0x172df8 push {r4, r5, r6, r7, r8, lr} */
/* @0x172dfc vpush {d8, d9, d10} */
/* @0x172e00 sub sp, sp, #24 */
/* @0x172e04 vmov s16, r1 */
/* @0x172e08 ldr r1, [pc, #0x240] */
/* @0x172e0c ldr r5, [sp, #0x48] */
/* @0x172e10 mov r6, r2 */
/* @0x172e14 add r1, pc, r1 */
/* @0x172e18 vmov s19, r0 */
/* @0x172e1c mov r0, #65280 */
/* @0x172e20 movt r0, #0xff */
/* @0x172e24 mov r12, #0 */
/* @0x172e28 mov r4, r3 */
/* @0x172e2c str r12, [sp, #0xc] */
/* @0x172e30 str r12, [sp, #0x8] */
/* @0x172e34 str r12, [sp, #0x14] */
/* @0x172e38 str r12, [sp, #0x10] */
/* @0x172e3c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x172e40 bl 0x1724e4 <_Z7SetFontv> */
/* @0x172e44 mov r0, r6 */
/* @0x172e48 mov r1, r5 */
/* @0x172e4c add r2, sp, #8 */
/* @0x172e50 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x172e54 ldr r6, [pc, #0x1f8] */
/* @0x172e58 cmp r4, #0 */
/* @0x172e5c add r6, pc, r6 */
/* @0x172e60 blt 0x17302c <_Z12GR_Text_DrawffPKcii+0x234> */
/* @0x172e64 ldr r3, [pc, #0x1ec] */
/* @0x172e68 ldr r1, [sp, #0x10] */
/* @0x172e6c ldr r3, [r6, r3] */
/* @0x172e70 ldr r3, [r3] */
/* @0x172e74 cmp r3, #1 */
/* @0x172e78 beq 0x173010 <_Z12GR_Text_DrawffPKcii+0x218> */
/* @0x172e7c cmp r3, #2 */
/* @0x172e80 muleq r3, r1, r4 */
/* @0x172e84 vmoveq s15, r3 */
/* @0x172e88 vcvteq.f32.s32 s15, s15 */
/* @0x172e8c vsubeq.f32 s16, s16, s15 */
/* @0x172e90 cmp r1, #0 */
/* @0x172e94 ble 0x172ee8 <_Z12GR_Text_DrawffPKcii+0xf0> */
/* @0x172e98 vmov s14, r4 */
/* @0x172e9c mov r4, #0 */
/* @0x172ea0 vldr s20, [pc, #420] */
/* @0x172ea4 vcvt.f32.s32 s17, s14 */
/* @0x172ea8 ldr r3, [sp, #0x8] */
/* @0x172eac cmp r3, #0 */
/* @0x172eb0 beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0> */
/* @0x172eb4 cmp r4, #0 */
/* @0x172eb8 movne r2, r4 */
/* @0x172ebc bne 0x172ecc <_Z12GR_Text_DrawffPKcii+0xd4> */
/* @0x172ec0 b 0x172f34 <_Z12GR_Text_DrawffPKcii+0x13c> */
/* @0x172ec4 subs r2, r2, #1 */
/* @0x172ec8 beq 0x172f34 <_Z12GR_Text_DrawffPKcii+0x13c> */
/* @0x172ecc ldr r3, [r3] */
/* @0x172ed0 cmp r3, #0 */
/* @0x172ed4 bne 0x172ec4 <_Z12GR_Text_DrawffPKcii+0xcc> */
/* @0x172ed8 add r4, r4, #1 */
/* @0x172edc vadd.f32 s16, s16, s17 */
/* @0x172ee0 cmp r1, r4 */
/* @0x172ee4 bgt 0x172ea8 <_Z12GR_Text_DrawffPKcii+0xb0> */
/* @0x172ee8 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x172eec ldr r0, [sp, #0x8] */
/* @0x172ef0 cmp r0, #0 */
/* @0x172ef4 beq 0x172f0c <_Z12GR_Text_DrawffPKcii+0x114> */
/* @0x172ef8 ldr r4, [r0] */
/* @0x172efc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172f00 cmp r4, #0 */
/* @0x172f04 mov r0, r4 */
/* @0x172f08 bne 0x172ef8 <_Z12GR_Text_DrawffPKcii+0x100> */
/* @0x172f0c ldr r0, [sp, #0x14] */
/* @0x172f10 mov r3, #0 */
/* @0x172f14 str r3, [sp, #0x10] */
/* @0x172f18 cmp r0, r3 */
/* @0x172f1c str r3, [sp, #0x8] */
/* @0x172f20 beq 0x172f28 <_Z12GR_Text_DrawffPKcii+0x130> */
/* @0x172f24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x172f28 add sp, sp, #24 */
/* @0x172f2c vpop {d8, d9, d10} */
/* @0x172f30 pop {r4, r5, r6, r7, r8, pc} */
/* @0x172f34 ldr r5, [r3, #0x4] */
/* @0x172f38 cmp r5, #0 */
/* @0x172f3c beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0> */
/* @0x172f40 ldrh r3, [r5] */
/* @0x172f44 cmp r3, #0 */
/* @0x172f48 beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0> */
/* @0x172f4c ldr r3, [pc, #0x108] */
/* @0x172f50 ldr r8, [r6, r3] */
/* @0x172f54 ldr r3, [r8] */
/* @0x172f58 cmp r3, #1 */
/* @0x172f5c beq 0x172fc0 <_Z12GR_Text_DrawffPKcii+0x1c8> */
/* @0x172f60 ldr r2, [pc, #0xf8] */
/* @0x172f64 cmp r3, #2 */
/* @0x172f68 vldr s15, [pc, #220] */
/* @0x172f6c ldr r7, [r6, r2] */
/* @0x172f70 beq 0x172ff4 <_Z12GR_Text_DrawffPKcii+0x1fc> */
/* @0x172f74 vadd.f32 s18, s19, s15 */
/* @0x172f78 ldr r7, [r7] */
/* @0x172f7c bl 0x169ecc <_Z17GR_Draw_Get_Colorv> */
/* @0x172f80 add r4, r4, #1 */
/* @0x172f84 mov r8, r0 */
/* @0x172f88 bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x172f8c vadd.f32 s15, s16, s20 */
/* @0x172f90 str r8, [sp] */
/* @0x172f94 vmov r1, s18 */
/* @0x172f98 mov r3, r5 */
/* @0x172f9c vmov r2, s15 */
/* @0x172fa0 str r0, [sp, #0x4] */
/* @0x172fa4 mov r0, r7 */
/* @0x172fa8 bl 0xf7eec <_ZN7CFontGM11Draw_StringEffPtjf> */
/* @0x172fac ldr r1, [sp, #0x10] */
/* @0x172fb0 vadd.f32 s16, s16, s17 */
/* @0x172fb4 cmp r1, r4 */
/* @0x172fb8 bgt 0x172ea8 <_Z12GR_Text_DrawffPKcii+0xb0> */
/* @0x172fbc b 0x172ee8 <_Z12GR_Text_DrawffPKcii+0xf0> */
/* @0x172fc0 ldr r3, [pc, #0x98] */
/* @0x172fc4 mov r1, r5 */
/* @0x172fc8 ldr r7, [r6, r3] */
/* @0x172fcc ldr r0, [r7] */
/* @0x172fd0 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x172fd4 ldr r3, [r8] */
/* @0x172fd8 cmp r3, #2 */
/* @0x172fdc add r0, r0, r0, lsr #31 */
/* @0x172fe0 asr r2, r0, #1 */
/* @0x172fe4 rsb r2, r2, #0 */
/* @0x172fe8 vmov s14, r2 */
/* @0x172fec vcvt.f32.s32 s15, s14 */
/* @0x172ff0 bne 0x172f74 <_Z12GR_Text_DrawffPKcii+0x17c> */
/* @0x172ff4 ldr r0, [r7] */
/* @0x172ff8 mov r1, r5 */
/* @0x172ffc bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x173000 rsb r0, r0, #0 */
/* @0x173004 vmov s14, r0 */
/* @0x173008 vcvt.f32.s32 s15, s14 */
/* @0x17300c b 0x172f74 <_Z12GR_Text_DrawffPKcii+0x17c> */
/* @0x173010 mul r3, r1, r4 */
/* @0x173014 add r3, r3, r3, lsr #31 */
/* @0x173018 asr r3, r3, #1 */
/* @0x17301c vmov s14, r3 */
/* @0x173020 vcvt.f32.s32 s15, s14 */
/* @0x173024 vsub.f32 s16, s16, s15 */
/* @0x173028 b 0x172e90 <_Z12GR_Text_DrawffPKcii+0x98> */
/* @0x17302c ldr r3, [pc, #0x2c] */
/* @0x173030 ldr r1, [pc, #0x2c] */
/* @0x173034 ldr r7, [r6, r3] */
/* @0x173038 add r1, pc, r1 */
/* @0x17303c ldr r0, [r7] */
/* @0x173040 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x173044 mov r4, r0 */
/* @0x173048 b 0x172e64 <_Z12GR_Text_DrawffPKcii+0x6c> */
/* @0x17304c andeq r0, r0, r0 */
/* @0x173050 ldrsheq r8, [sp], -r8 */
/* @0x173054 .word 0x0027edf4 */
/* @0x173058 .word 0xffffe65c */
/* @0x17305c .word 0xffffe658 */
/* @0x173060 .word 0xffffe654 */
/* @0x173064 ldrsbeq r8, [sp], -r0 */

/* ── FUNC 0x173068 · GR_Text_Draw_Transformed(float, float, char const*, int, int, float, float, float) · size=720 · insn=180 */
/* @0x173068 push {r4, r5, r6, r7, r8, lr} */
/* @0x17306c vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x173070 sub sp, sp, #40 */
/* @0x173074 vldr s27, [sp, #132] */
/* @0x173078 vmov s17, r1 */
/* @0x17307c ldr r1, [pc, #0x29c] */
/* @0x173080 ldr r5, [sp, #0x78] */
/* @0x173084 mov r6, r2 */
/* @0x173088 add r1, pc, r1 */
/* @0x17308c vmov s16, r0 */
/* @0x173090 mov r0, #65280 */
/* @0x173094 movt r0, #0xff */
/* @0x173098 mov r12, #0 */
/* @0x17309c mov r4, r3 */
/* @0x1730a0 str r12, [sp, #0x1c] */
/* @0x1730a4 vldr s26, [sp, #124] */
/* @0x1730a8 str r12, [sp, #0x18] */
/* @0x1730ac vldr s25, [sp, #128] */
/* @0x1730b0 str r12, [sp, #0x24] */
/* @0x1730b4 vldr s18, [pc, #600] */
/* @0x1730b8 str r12, [sp, #0x20] */
/* @0x1730bc bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc> */
/* @0x1730c0 bl 0x1724e4 <_Z7SetFontv> */
/* @0x1730c4 mov r0, r6 */
/* @0x1730c8 mov r1, r5 */
/* @0x1730cc add r2, sp, #24 */
/* @0x1730d0 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x1730d4 vmul.f32 s18, s27, s18 */
/* @0x1730d8 vldr s15, [pc, #568] */
/* @0x1730dc ldr r6, [pc, #0x240] */
/* @0x1730e0 add r6, pc, r6 */
/* @0x1730e4 vdiv.f32 s18, s18, s15 */
/* @0x1730e8 vmov r0, s18 */
/* @0x1730ec bl 0xb6580 <sinf@plt> */
/* @0x1730f0 vmov s22, r0 */
/* @0x1730f4 vmov r0, s18 */
/* @0x1730f8 bl 0xb658c <cosf@plt> */
/* @0x1730fc cmp r4, #0 */
/* @0x173100 vmov s23, r0 */
/* @0x173104 blt 0x1732f4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x28c> */
/* @0x173108 vmul.f32 s20, s22, s25 */
/* @0x17310c ldr r3, [pc, #0x214] */
/* @0x173110 vmov s14, r4 */
/* @0x173114 ldr r1, [sp, #0x20] */
/* @0x173118 ldr r3, [r6, r3] */
/* @0x17311c ldr r3, [r3] */
/* @0x173120 cmp r3, #1 */
/* @0x173124 vmul.f32 s21, s23, s25 */
/* @0x173128 vcvt.f32.s32 s15, s14 */
/* @0x17312c vmul.f32 s20, s20, s15 */
/* @0x173130 vmul.f32 s21, s15, s21 */
/* @0x173134 beq 0x1732d4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x26c> */
/* @0x173138 cmp r3, #2 */
/* @0x17313c vmoveq s14, r1 */
/* @0x173140 vcvteq.f32.s32 s15, s14 */
/* @0x173144 vmlseq.f32 s17, s15, s21 */
/* @0x173148 vmlseq.f32 s16, s20, s15 */
/* @0x17314c cmp r1, #0 */
/* @0x173150 ble 0x1731a4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x13c> */
/* @0x173154 mov r4, #0 */
/* @0x173158 vldr s24, [pc, #444] */
/* @0x17315c vmov.f32 s28, #5.000000e-01 */
/* @0x173160 ldr r3, [sp, #0x18] */
/* @0x173164 cmp r3, #0 */
/* @0x173168 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128> */
/* @0x17316c cmp r4, #0 */
/* @0x173170 movne r2, r4 */
/* @0x173174 bne 0x173184 <_Z24GR_Text_Draw_TransformedffPKciifff+0x11c> */
/* @0x173178 b 0x1731f0 <_Z24GR_Text_Draw_TransformedffPKciifff+0x188> */
/* @0x17317c subs r2, r2, #1 */
/* @0x173180 beq 0x1731f0 <_Z24GR_Text_Draw_TransformedffPKciifff+0x188> */
/* @0x173184 ldr r3, [r3] */
/* @0x173188 cmp r3, #0 */
/* @0x17318c bne 0x17317c <_Z24GR_Text_Draw_TransformedffPKciifff+0x114> */
/* @0x173190 add r4, r4, #1 */
/* @0x173194 vadd.f32 s16, s16, s20 */
/* @0x173198 cmp r1, r4 */
/* @0x17319c vadd.f32 s17, s17, s21 */
/* @0x1731a0 bgt 0x173160 <_Z24GR_Text_Draw_TransformedffPKciifff+0xf8> */
/* @0x1731a4 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv> */
/* @0x1731a8 ldr r0, [sp, #0x18] */
/* @0x1731ac cmp r0, #0 */
/* @0x1731b0 beq 0x1731c8 <_Z24GR_Text_Draw_TransformedffPKciifff+0x160> */
/* @0x1731b4 ldr r4, [r0] */
/* @0x1731b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1731bc cmp r4, #0 */
/* @0x1731c0 mov r0, r4 */
/* @0x1731c4 bne 0x1731b4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x14c> */
/* @0x1731c8 ldr r0, [sp, #0x24] */
/* @0x1731cc mov r3, #0 */
/* @0x1731d0 str r3, [sp, #0x20] */
/* @0x1731d4 cmp r0, r3 */
/* @0x1731d8 str r3, [sp, #0x18] */
/* @0x1731dc beq 0x1731e4 <_Z24GR_Text_Draw_TransformedffPKciifff+0x17c> */
/* @0x1731e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1731e4 add sp, sp, #40 */
/* @0x1731e8 vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1731ec pop {r4, r5, r6, r7, r8, pc} */
/* @0x1731f0 ldr r5, [r3, #0x4] */
/* @0x1731f4 cmp r5, #0 */
/* @0x1731f8 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128> */
/* @0x1731fc ldrh r3, [r5] */
/* @0x173200 cmp r3, #0 */
/* @0x173204 beq 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128> */
/* @0x173208 ldr r3, [pc, #0x11c] */
/* @0x17320c ldr r8, [r6, r3] */
/* @0x173210 ldr r3, [r8] */
/* @0x173214 cmp r3, #1 */
/* @0x173218 beq 0x173288 <_Z24GR_Text_Draw_TransformedffPKciifff+0x220> */
/* @0x17321c ldr r2, [pc, #0x10c] */
/* @0x173220 cmp r3, #2 */
/* @0x173224 vldr s15, [pc, #240] */
/* @0x173228 ldr r7, [r6, r2] */
/* @0x17322c beq 0x1732b8 <_Z24GR_Text_Draw_TransformedffPKciifff+0x250> */
/* @0x173230 vmov.f32 s19, s16 */
/* @0x173234 ldr r7, [r7] */
/* @0x173238 vmov.f32 s18, s17 */
/* @0x17323c vmla.f32 s19, s23, s15 */
/* @0x173240 vmls.f32 s18, s22, s15 */
/* @0x173244 bl 0x169ecc <_Z17GR_Draw_Get_Colorv> */
/* @0x173248 mov r8, r0 */
/* @0x17324c bl 0x169f1c <_Z17GR_Draw_Get_Alphav> */
/* @0x173250 vmla.f32 s19, s22, s24 */
/* @0x173254 str r8, [sp, #0xc] */
/* @0x173258 vstr s26, [sp] */
/* @0x17325c vstr s25, [sp, #4] */
/* @0x173260 vstr s27, [sp, #8] */
/* @0x173264 mov r3, r5 */
/* @0x173268 vmla.f32 s18, s23, s24 */
/* @0x17326c vmov r1, s19 */
/* @0x173270 str r0, [sp, #0x10] */
/* @0x173274 mov r0, r7 */
/* @0x173278 vmov r2, s18 */
/* @0x17327c bl 0xf830c <_ZN7CFontGM23Draw_String_TransformedEffPtfffjf> */
/* @0x173280 ldr r1, [sp, #0x20] */
/* @0x173284 b 0x173190 <_Z24GR_Text_Draw_TransformedffPKciifff+0x128> */
/* @0x173288 ldr r3, [pc, #0xa0] */
/* @0x17328c mov r1, r5 */
/* @0x173290 ldr r7, [r6, r3] */
/* @0x173294 ldr r0, [r7] */
/* @0x173298 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x17329c ldr r3, [r8] */
/* @0x1732a0 cmp r3, #2 */
/* @0x1732a4 vmov s14, r0 */
/* @0x1732a8 vcvt.f32.s32 s15, s14 */
/* @0x1732ac vmul.f32 s15, s15, s26 */
/* @0x1732b0 vnmul.f32 s15, s28, s15 */
/* @0x1732b4 bne 0x173230 <_Z24GR_Text_Draw_TransformedffPKciifff+0x1c8> */
/* @0x1732b8 ldr r0, [r7] */
/* @0x1732bc mov r1, r5 */
/* @0x1732c0 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x1732c4 vmov s14, r0 */
/* @0x1732c8 vcvt.f32.s32 s15, s14 */
/* @0x1732cc vnmul.f32 s15, s26, s15 */
/* @0x1732d0 b 0x173230 <_Z24GR_Text_Draw_TransformedffPKciifff+0x1c8> */
/* @0x1732d4 vmov s14, r1 */
/* @0x1732d8 vcvt.f32.s32 s15, s14 */
/* @0x1732dc vmul.f32 s13, s15, s21 */
/* @0x1732e0 vmul.f32 s14, s20, s15 */
/* @0x1732e4 vmov.f32 s15, #5.000000e-01 */
/* @0x1732e8 vmls.f32 s17, s13, s15 */
/* @0x1732ec vmls.f32 s16, s14, s15 */
/* @0x1732f0 b 0x17314c <_Z24GR_Text_Draw_TransformedffPKciifff+0xe4> */
/* @0x1732f4 ldr r3, [pc, #0x34] */
/* @0x1732f8 ldr r1, [pc, #0x34] */
/* @0x1732fc ldr r7, [r6, r3] */
/* @0x173300 add r1, pc, r1 */
/* @0x173304 ldr r0, [r7] */
/* @0x173308 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x17330c mov r4, r0 */
/* @0x173310 b 0x173108 <_Z24GR_Text_Draw_TransformedffPKciifff+0xa0> */
/* @0x173314 ldrdmi r0, r1, [r9], #-251 */
/* @0x173318 teqmi r4, #0 */
/* @0x17331c andeq r0, r0, r0 */
/* @0x173320 andseq r8, sp, r4, lsl #9 */
/* @0x173324 eoreq lr, r7, r0, ror r11 */
/* @0x173328 .word 0xffffe65c */
/* @0x17332c .word 0xffffe658 */
/* @0x173330 .word 0xffffe654 */
/* @0x173334 andseq r8, sp, r8, lsl #4 */

/* ── FUNC 0x173338 · GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=616 · insn=154 */
/* @0x173338 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x17333c vpush {d8, d9, d10} */
/* @0x173340 sub sp, sp, #52 */
/* @0x173344 vldr s19, [sp, #132] */
/* @0x173348 add r5, sp, #116 */
/* @0x17334c mov r10, r2 */
/* @0x173350 ldr r9, [sp, #0x70] */
/* @0x173354 mov r12, #0 */
/* @0x173358 mov r4, r3 */
/* @0x17335c vmov s18, r0 */
/* @0x173360 str r12, [sp, #0x24] */
/* @0x173364 vmov s16, r1 */
/* @0x173368 str r12, [sp, #0x20] */
/* @0x17336c str r12, [sp, #0x2c] */
/* @0x173370 str r12, [sp, #0x28] */
/* @0x173374 ldm r5, {r5, r6, r7, r8} */
/* @0x173378 bl 0x1724e4 <_Z7SetFontv> */
/* @0x17337c mov r1, r9 */
/* @0x173380 mov r0, r10 */
/* @0x173384 add r2, sp, #32 */
/* @0x173388 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x17338c ldr r9, [pc, #0x1f8] */
/* @0x173390 cmp r4, #0 */
/* @0x173394 add r9, pc, r9 */
/* @0x173398 blt 0x173568 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x230> */
/* @0x17339c ldr r3, [pc, #0x1ec] */
/* @0x1733a0 ldr r1, [sp, #0x28] */
/* @0x1733a4 ldr r3, [r9, r3] */
/* @0x1733a8 ldr r3, [r3] */
/* @0x1733ac cmp r3, #1 */
/* @0x1733b0 beq 0x17354c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x214> */
/* @0x1733b4 cmp r3, #2 */
/* @0x1733b8 muleq r2, r1, r4 */
/* @0x1733bc vmoveq s15, r2 */
/* @0x1733c0 vcvteq.f32.s32 s15, s15 */
/* @0x1733c4 vsubeq.f32 s16, s16, s15 */
/* @0x1733c8 cmp r1, #0 */
/* @0x1733cc ldrle r0, [sp, #0x20] */
/* @0x1733d0 ble 0x173428 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf0> */
/* @0x1733d4 vmov s14, r4 */
/* @0x1733d8 ldr r0, [sp, #0x20] */
/* @0x1733dc mov r4, #0 */
/* @0x1733e0 vldr s20, [pc, #416] */
/* @0x1733e4 vcvt.f32.s32 s17, s14 */
/* @0x1733e8 cmp r0, #0 */
/* @0x1733ec beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0> */
/* @0x1733f0 cmp r4, #0 */
/* @0x1733f4 movne r2, r4 */
/* @0x1733f8 movne r3, r0 */
/* @0x1733fc bne 0x17340c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xd4> */
/* @0x173400 b 0x17346c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x134> */
/* @0x173404 subs r2, r2, #1 */
/* @0x173408 beq 0x173470 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x138> */
/* @0x17340c ldr r3, [r3] */
/* @0x173410 cmp r3, #0 */
/* @0x173414 bne 0x173404 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xcc> */
/* @0x173418 add r4, r4, #1 */
/* @0x17341c vadd.f32 s16, s16, s17 */
/* @0x173420 cmp r1, r4 */
/* @0x173424 bgt 0x1733e8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xb0> */
/* @0x173428 cmp r0, #0 */
/* @0x17342c beq 0x173444 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x10c> */
/* @0x173430 ldr r4, [r0] */
/* @0x173434 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x173438 cmp r4, #0 */
/* @0x17343c mov r0, r4 */
/* @0x173440 bne 0x173430 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf8> */
/* @0x173444 ldr r0, [sp, #0x2c] */
/* @0x173448 mov r3, #0 */
/* @0x17344c str r3, [sp, #0x28] */
/* @0x173450 cmp r0, r3 */
/* @0x173454 str r3, [sp, #0x20] */
/* @0x173458 beq 0x173460 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x128> */
/* @0x17345c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x173460 add sp, sp, #52 */
/* @0x173464 vpop {d8, d9, d10} */
/* @0x173468 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x17346c mov r3, r0 */
/* @0x173470 ldr r10, [r3, #0x4] */
/* @0x173474 cmp r10, #0 */
/* @0x173478 beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0> */
/* @0x17347c ldrh r3, [r10] */
/* @0x173480 cmp r3, #0 */
/* @0x173484 beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0> */
/* @0x173488 ldr r3, [pc, #0x104] */
/* @0x17348c ldr r3, [r9, r3] */
/* @0x173490 str r3, [sp, #0x1c] */
/* @0x173494 ldr r3, [r3] */
/* @0x173498 cmp r3, #1 */
/* @0x17349c beq 0x1734f8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x1c0> */
/* @0x1734a0 ldr r2, [pc, #0xf0] */
/* @0x1734a4 cmp r3, #2 */
/* @0x1734a8 vldr s15, [pc, #216] */
/* @0x1734ac ldr r11, [r9, r2] */
/* @0x1734b0 beq 0x173530 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x1f8> */
/* @0x1734b4 vadd.f32 s15, s18, s15 */
/* @0x1734b8 ldr r0, [r11] */
/* @0x1734bc mov r3, r10 */
/* @0x1734c0 str r5, [sp] */
/* @0x1734c4 vstr s19, [sp, #16] */
/* @0x1734c8 stmib sp, {r6, r7, r8} */
/* @0x1734cc add r4, r4, #1 */
/* @0x1734d0 vmov r1, s15 */
/* @0x1734d4 vadd.f32 s15, s16, s20 */
/* @0x1734d8 vmov r2, s15 */
/* @0x1734dc bl 0xf8b58 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf> */
/* @0x1734e0 ldr r1, [sp, #0x28] */
/* @0x1734e4 ldr r0, [sp, #0x20] */
/* @0x1734e8 vadd.f32 s16, s16, s17 */
/* @0x1734ec cmp r1, r4 */
/* @0x1734f0 bgt 0x1733e8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xb0> */
/* @0x1734f4 b 0x173428 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf0> */
/* @0x1734f8 ldr r3, [pc, #0x98] */
/* @0x1734fc mov r1, r10 */
/* @0x173500 ldr r11, [r9, r3] */
/* @0x173504 ldr r0, [r11] */
/* @0x173508 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x17350c ldr r2, [sp, #0x1c] */
/* @0x173510 ldr r3, [r2] */
/* @0x173514 cmp r3, #2 */
/* @0x173518 add r0, r0, r0, lsr #31 */
/* @0x17351c asr r1, r0, #1 */
/* @0x173520 rsb r1, r1, #0 */
/* @0x173524 vmov s14, r1 */
/* @0x173528 vcvt.f32.s32 s15, s14 */
/* @0x17352c bne 0x1734b4 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x17c> */
/* @0x173530 ldr r0, [r11] */
/* @0x173534 mov r1, r10 */
/* @0x173538 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x17353c rsb r0, r0, #0 */
/* @0x173540 vmov s14, r0 */
/* @0x173544 vcvt.f32.s32 s15, s14 */
/* @0x173548 b 0x1734b4 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x17c> */
/* @0x17354c mul r3, r1, r4 */
/* @0x173550 add r3, r3, r3, lsr #31 */
/* @0x173554 asr r3, r3, #1 */
/* @0x173558 vmov s14, r3 */
/* @0x17355c vcvt.f32.s32 s15, s14 */
/* @0x173560 vsub.f32 s16, s16, s15 */
/* @0x173564 b 0x1733c8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x90> */
/* @0x173568 ldr r3, [pc, #0x28] */
/* @0x17356c ldr r1, [pc, #0x28] */
/* @0x173570 ldr r11, [r9, r3] */
/* @0x173574 add r1, pc, r1 */
/* @0x173578 ldr r0, [r11] */
/* @0x17357c bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x173580 mov r4, r0 */
/* @0x173584 b 0x17339c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x64> */
/* @0x173588 andeq r0, r0, r0 */
/* @0x17358c .word 0x0027e8bc */
/* @0x173590 .word 0xffffe65c */
/* @0x173594 .word 0xffffe658 */
/* @0x173598 .word 0xffffe654 */
/* @0x17359c mulseq sp, r4, pc */

/* ── FUNC 0x1735a0 · GR_Text_Draw_Transformed_Color(float, float, char const*, int, int, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=740 · insn=185 */
/* @0x1735a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1735a4 vpush {d8, d9, d10, d11, d12, d13, d14} */
/* @0x1735a8 sub sp, sp, #52 */
/* @0x1735ac vldr s24, [sp, #156] */
/* @0x1735b0 add r5, sp, #160 */
/* @0x1735b4 mov r10, r2 */
/* @0x1735b8 ldr r9, [sp, #0x90] */
/* @0x1735bc mov r4, r3 */
/* @0x1735c0 vmov s16, r0 */
/* @0x1735c4 vldr s25, [sp, #148] */
/* @0x1735c8 vmov s17, r1 */
/* @0x1735cc vldr s22, [sp, #152] */
/* @0x1735d0 ldm r5, {r5, r6, r7, r8} */
/* @0x1735d4 vldr s26, [sp, #176] */
/* @0x1735d8 bl 0x1724e4 <_Z7SetFontv> */
/* @0x1735dc mov r1, r9 */
/* @0x1735e0 add r2, sp, #32 */
/* @0x1735e4 mov r0, r10 */
/* @0x1735e8 mov r12, #0 */
/* @0x1735ec vldr s18, [pc, #624] */
/* @0x1735f0 str r12, [sp, #0x24] */
/* @0x1735f4 str r12, [sp, #0x20] */
/* @0x1735f8 str r12, [sp, #0x2c] */
/* @0x1735fc str r12, [sp, #0x28] */
/* @0x173600 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList> */
/* @0x173604 vmul.f32 s18, s24, s18 */
/* @0x173608 vldr s15, [pc, #600] */
/* @0x17360c ldr r9, [pc, #0x25c] */
/* @0x173610 add r9, pc, r9 */
/* @0x173614 vdiv.f32 s18, s18, s15 */
/* @0x173618 vmov r0, s18 */
/* @0x17361c bl 0xb6580 <sinf@plt> */
/* @0x173620 vmov s20, r0 */
/* @0x173624 vmov r0, s18 */
/* @0x173628 bl 0xb658c <cosf@plt> */
/* @0x17362c cmp r4, #0 */
/* @0x173630 vmov s21, r0 */
/* @0x173634 blt 0x173844 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x2a4> */
/* @0x173638 vmul.f32 s18, s20, s22 */
/* @0x17363c ldr r3, [pc, #0x230] */
/* @0x173640 vmov s13, r4 */
/* @0x173644 ldr r1, [sp, #0x28] */
/* @0x173648 ldr r3, [r9, r3] */
/* @0x17364c ldr r3, [r3] */
/* @0x173650 cmp r3, #1 */
/* @0x173654 vmul.f32 s19, s21, s22 */
/* @0x173658 vcvt.f32.s32 s15, s13 */
/* @0x17365c vmul.f32 s18, s18, s15 */
/* @0x173660 vmul.f32 s19, s15, s19 */
/* @0x173664 beq 0x173824 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x284> */
/* @0x173668 cmp r3, #2 */
/* @0x17366c vmoveq s13, r1 */
/* @0x173670 vcvteq.f32.s32 s15, s13 */
/* @0x173674 vmlseq.f32 s17, s15, s19 */
/* @0x173678 vmlseq.f32 s16, s18, s15 */
/* @0x17367c cmp r1, #0 */
/* @0x173680 ldrle r0, [sp, #0x20] */
/* @0x173684 ble 0x1736e0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x140> */
/* @0x173688 ldr r0, [sp, #0x20] */
/* @0x17368c mov r4, #0 */
/* @0x173690 vldr s23, [pc, #468] */
/* @0x173694 vmov.f32 s28, #5.000000e-01 */
/* @0x173698 vneg.f32 s27, s25 */
/* @0x17369c cmp r0, #0 */
/* @0x1736a0 beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c> */
/* @0x1736a4 cmp r4, #0 */
/* @0x1736a8 movne r2, r4 */
/* @0x1736ac movne r3, r0 */
/* @0x1736b0 bne 0x1736c0 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x120> */
/* @0x1736b4 b 0x173724 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x184> */
/* @0x1736b8 subs r2, r2, #1 */
/* @0x1736bc beq 0x173728 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x188> */
/* @0x1736c0 ldr r3, [r3] */
/* @0x1736c4 cmp r3, #0 */
/* @0x1736c8 bne 0x1736b8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x118> */
/* @0x1736cc add r4, r4, #1 */
/* @0x1736d0 vadd.f32 s16, s16, s18 */
/* @0x1736d4 cmp r1, r4 */
/* @0x1736d8 vadd.f32 s17, s17, s19 */
/* @0x1736dc bgt 0x17369c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0xfc> */
/* @0x1736e0 cmp r0, #0 */
/* @0x1736e4 beq 0x1736fc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x15c> */
/* @0x1736e8 ldr r4, [r0] */
/* @0x1736ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1736f0 cmp r4, #0 */
/* @0x1736f4 mov r0, r4 */
/* @0x1736f8 bne 0x1736e8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x148> */
/* @0x1736fc ldr r0, [sp, #0x2c] */
/* @0x173700 mov r3, #0 */
/* @0x173704 str r3, [sp, #0x28] */
/* @0x173708 cmp r0, r3 */
/* @0x17370c str r3, [sp, #0x20] */
/* @0x173710 beq 0x173718 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x178> */
/* @0x173714 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x173718 add sp, sp, #52 */
/* @0x17371c vpop {d8, d9, d10, d11, d12, d13, d14} */
/* @0x173720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x173724 mov r3, r0 */
/* @0x173728 ldr r10, [r3, #0x4] */
/* @0x17372c cmp r10, #0 */
/* @0x173730 beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c> */
/* @0x173734 ldrh r3, [r10] */
/* @0x173738 cmp r3, #0 */
/* @0x17373c beq 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c> */
/* @0x173740 ldr r3, [pc, #0x130] */
/* @0x173744 ldr r11, [r9, r3] */
/* @0x173748 ldr r3, [r11] */
/* @0x17374c cmp r3, #1 */
/* @0x173750 beq 0x1737f8 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x258> */
/* @0x173754 vldr s15, [pc, #272] */
/* @0x173758 cmp r3, #2 */
/* @0x17375c beq 0x1737d4 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x234> */
/* @0x173760 ldrh r3, [r10] */
/* @0x173764 cmp r3, #0 */
/* @0x173768 bne 0x173778 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1d8> */
/* @0x17376c ldr r0, [sp, #0x20] */
/* @0x173770 ldr r1, [sp, #0x28] */
/* @0x173774 b 0x1736cc <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x12c> */
/* @0x173778 vmov.f32 s13, s17 */
/* @0x17377c ldr r2, [pc, #0xf8] */
/* @0x173780 mov r3, r10 */
/* @0x173784 ldr r2, [r9, r2] */
/* @0x173788 vstr s25, [sp] */
/* @0x17378c vmov.f32 s14, s16 */
/* @0x173790 vstr s22, [sp, #4] */
/* @0x173794 vstr s24, [sp, #8] */
/* @0x173798 str r5, [sp, #0xc] */
/* @0x17379c vstr s26, [sp, #28] */
/* @0x1737a0 ldr r0, [r2] */
/* @0x1737a4 str r6, [sp, #0x10] */
/* @0x1737a8 vmls.f32 s13, s20, s15 */
/* @0x1737ac str r7, [sp, #0x14] */
/* @0x1737b0 str r8, [sp, #0x18] */
/* @0x1737b4 vmla.f32 s14, s21, s15 */
/* @0x1737b8 vmov.f32 s15, s13 */
/* @0x1737bc vmla.f32 s14, s20, s23 */
/* @0x1737c0 vmla.f32 s15, s21, s23 */
/* @0x1737c4 vmov r1, s14 */
/* @0x1737c8 vmov r2, s15 */
/* @0x1737cc bl 0xf8f58 <_ZN7CFontGM29Draw_String_Transformed_ColorEffPtfffjjjjf> */
/* @0x1737d0 b 0x17376c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1cc> */
/* @0x1737d4 ldr r3, [pc, #0xa0] */
/* @0x1737d8 mov r1, r10 */
/* @0x1737dc ldr r3, [r9, r3] */
/* @0x1737e0 ldr r0, [r3] */
/* @0x1737e4 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x1737e8 vmov s13, r0 */
/* @0x1737ec vcvt.f32.s32 s15, s13 */
/* @0x1737f0 vmul.f32 s15, s27, s15 */
/* @0x1737f4 b 0x173760 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1c0> */
/* @0x1737f8 ldr r3, [pc, #0x7c] */
/* @0x1737fc mov r1, r10 */
/* @0x173800 ldr r3, [r9, r3] */
/* @0x173804 ldr r0, [r3] */
/* @0x173808 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt> */
/* @0x17380c ldr r3, [r11] */
/* @0x173810 vmov s14, r0 */
/* @0x173814 vcvt.f32.s32 s15, s14 */
/* @0x173818 vmul.f32 s15, s27, s15 */
/* @0x17381c vmul.f32 s15, s15, s28 */
/* @0x173820 b 0x173758 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x1b8> */
/* @0x173824 vmov s14, r1 */
/* @0x173828 vcvt.f32.s32 s15, s14 */
/* @0x17382c vmul.f32 s13, s15, s19 */
/* @0x173830 vmul.f32 s14, s18, s15 */
/* @0x173834 vmov.f32 s15, #5.000000e-01 */
/* @0x173838 vmls.f32 s17, s13, s15 */
/* @0x17383c vmls.f32 s16, s14, s15 */
/* @0x173840 b 0x17367c <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0xdc> */
/* @0x173844 ldr r3, [pc, #0x30] */
/* @0x173848 ldr r1, [pc, #0x30] */
/* @0x17384c ldr r3, [r9, r3] */
/* @0x173850 add r1, pc, r1 */
/* @0x173854 ldr r0, [r3] */
/* @0x173858 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt> */
/* @0x17385c mov r4, r0 */
/* @0x173860 b 0x173638 <_Z30GR_Text_Draw_Transformed_ColorffPKciifffjjjjf+0x98> */
/* @0x173864 ldrdmi r0, r1, [r9], #-251 */
/* @0x173868 teqmi r4, #0 */
/* @0x17386c andeq r0, r0, r0 */
/* @0x173870 eoreq lr, r7, r0, asr #12 */
/* @0x173874 .word 0xffffe65c */
/* @0x173878 .word 0xffffe658 */
/* @0x17387c .word 0xffffe654 */
/* @0x173880 ldrheq r7, [sp], -r8 */

/* ── FUNC 0x173884 · GR_Text_ResetToDefault() · size=120 · insn=30 */
/* @0x173884 ldr r3, [pc, #0x58] */
/* @0x173888 mov r2, #0 */
/* @0x17388c ldr r0, [pc, #0x54] */
/* @0x173890 mov r12, #-16777216 */
/* @0x173894 add r3, pc, r3 */
/* @0x173898 mov r1, #255 */
/* @0x17389c push {r4, r5, r6, r7, r8} */
/* @0x1738a0 mvn r8, #0 */
/* @0x1738a4 ldr r7, [r3, r0] */
/* @0x1738a8 ldr r6, [pc, #0x3c] */
/* @0x1738ac ldr r5, [pc, #0x3c] */
/* @0x1738b0 str r8, [r7] */
/* @0x1738b4 ldr r6, [r3, r6] */
/* @0x1738b8 ldr r4, [pc, #0x34] */
/* @0x1738bc ldr r0, [pc, #0x34] */
/* @0x1738c0 str r2, [r6] */
/* @0x1738c4 ldr r5, [r3, r5] */
/* @0x1738c8 str r2, [r5] */
/* @0x1738cc ldr r2, [r3, r4] */
/* @0x1738d0 pop {r4, r5, r6, r7, r8} */
/* @0x1738d4 str r12, [r2] */
/* @0x1738d8 ldr r3, [r3, r0] */
/* @0x1738dc str r1, [r3] */
/* @0x1738e0 bx lr */
/* @0x1738e4 .word 0x0027e3bc */
/* @0x1738e8 .word 0xffffe650 */
/* @0x1738ec .word 0xffffe658 */
/* @0x1738f0 .word 0xffffe65c */
/* @0x1738f4 .word 0xffffc0ac */
/* @0x1738f8 .word 0xffffc0b0 */

/* ── FUNC 0x1738fc · FINALIZE_Graphics_Text() · size=72 · insn=18 */
/* @0x1738fc push {r3, r4, r5, lr} */
/* @0x173900 mov r5, #0 */
/* @0x173904 ldr r4, [pc, #0x30] */
/* @0x173908 ldr r3, [pc, #0x30] */
/* @0x17390c ldr r4, [pc, r4] */
/* @0x173910 ldr r3, [pc, r3] */
/* @0x173914 ldr r0, [r4] */
/* @0x173918 str r5, [r3] */
/* @0x17391c cmp r0, r5 */
/* @0x173920 beq 0x173934 <_Z22FINALIZE_Graphics_Textv+0x38> */
/* @0x173924 ldr r3, [r0] */
/* @0x173928 ldr r3, [r3, #0x4] */
/* @0x17392c blx r3 */
/* @0x173930 str r5, [r4] */
/* @0x173934 pop {r3, r4, r5, lr} */
/* @0x173938 b 0x173884 <_Z22GR_Text_ResetToDefaultv> */
/* @0x17393c eoreq r12, r7, r8, lsl #19 */
/* @0x173940 eoreq r12, r7, r8, lsl #19 */

/* ── FUNC 0x173944 · AllocTexture() · size=224 · insn=56 */
/* @0x173944 push {r3, r4, r5, r6, r7, lr} */
/* @0x173948 ldr r3, [pc, #0xc4] */
/* @0x17394c ldr r2, [pc, #0xc4] */
/* @0x173950 add r3, pc, r3 */
/* @0x173954 ldr r6, [r3, r2] */
/* @0x173958 ldr r0, [r6] */
/* @0x17395c cmp r0, #0 */
/* @0x173960 ble 0x1739fc <_Z12AllocTexturev+0xb8> */
/* @0x173964 ldr r2, [pc, #0xb0] */
/* @0x173968 ldr r5, [r3, r2] */
/* @0x17396c ldr r3, [r5, #0x4] */
/* @0x173970 ldr r2, [r3] */
/* @0x173974 ldrb r4, [r2, #0x10] */
/* @0x173978 cmp r4, #0 */
/* @0x17397c beq 0x1739f4 <_Z12AllocTexturev+0xb0> */
/* @0x173980 mov r4, #0 */
/* @0x173984 b 0x173998 <_Z12AllocTexturev+0x54> */
/* @0x173988 ldr r2, [r3, #0x4]! */
/* @0x17398c ldrb r2, [r2, #0x10] */
/* @0x173990 cmp r2, #0 */
/* @0x173994 beq 0x1739f4 <_Z12AllocTexturev+0xb0> */
/* @0x173998 add r4, r4, #1 */
/* @0x17399c cmp r4, r0 */
/* @0x1739a0 bne 0x173988 <_Z12AllocTexturev+0x44> */
/* @0x1739a4 ldr r7, [pc, #0x74] */
/* @0x1739a8 add r1, r0, #1 */
/* @0x1739ac mov r3, #72 */
/* @0x1739b0 add r0, r5, #4 */
/* @0x1739b4 add r7, pc, r7 */
/* @0x1739b8 lsl r1, r1, #2 */
/* @0x1739bc mov r2, r7 */
/* @0x1739c0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1739c4 ldr lr, [r6] */
/* @0x1739c8 mov r1, r7 */
/* @0x1739cc mov r3, #1 */
/* @0x1739d0 mov r0, #20 */
/* @0x1739d4 mov r2, #77 */
/* @0x1739d8 add r12, lr, r3 */
/* @0x1739dc add r7, lr, #1073741824 */
/* @0x1739e0 str r12, [r5] */
/* @0x1739e4 str r12, [r6] */
/* @0x1739e8 ldr r5, [r5, #0x4] */
/* @0x1739ec bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1739f0 str r0, [r5, r7, lsl #2] */
/* @0x1739f4 mov r0, r4 */
/* @0x1739f8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1739fc movne r4, #0 */
/* @0x173a00 bne 0x1739f4 <_Z12AllocTexturev+0xb0> */
/* @0x173a04 ldr r2, [pc, #0x10] */
/* @0x173a08 mov r4, r0 */
/* @0x173a0c ldr r5, [r3, r2] */
/* @0x173a10 b 0x1739a4 <_Z12AllocTexturev+0x60> */
/* @0x173a14 eoreq lr, r7, r0, lsl #6 */
/* @0x173a18 .word 0xffffe660 */
/* @0x173a1c .word 0xffffbccc */
/* @0x173a20 andseq r7, sp, r0, ror #22 */

/* ── FUNC 0x173a24 · GR_Texture_Create_Empty(int, int, bool, bool, int) · size=252 · insn=63 */
/* @0x173a24 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x173a28 sub sp, sp, #12 */
/* @0x173a2c mov r8, r2 */
/* @0x173a30 mov r9, r3 */
/* @0x173a34 mov r5, r0 */
/* @0x173a38 mov r4, r1 */
/* @0x173a3c ldr r7, [sp, #0x28] */
/* @0x173a40 bl 0x173944 <_Z12AllocTexturev> */
/* @0x173a44 cmp r8, #0 */
/* @0x173a48 moveq r3, r8 */
/* @0x173a4c mov r6, r0 */
/* @0x173a50 beq 0x173a74 <_Z23GR_Texture_Create_Emptyiibbi+0x50> */
/* @0x173a54 ldr r2, [pc, #0xbc] */
/* @0x173a58 cmp r9, #0 */
/* @0x173a5c ldr r2, [pc, r2] */
/* @0x173a60 movne r3, #10 */
/* @0x173a64 moveq r3, #2 */
/* @0x173a68 ldrb r2, [r2] */
/* @0x173a6c cmp r2, #0 */
/* @0x173a70 orrne r3, r3, #4 */
/* @0x173a74 cmp r7, #1 */
/* @0x173a78 moveq r7, #12 */
/* @0x173a7c beq 0x173a8c <_Z23GR_Texture_Create_Emptyiibbi+0x68> */
/* @0x173a80 cmp r7, #2 */
/* @0x173a84 moveq r7, #13 */
/* @0x173a88 movne r7, #6 */
/* @0x173a8c mov r2, #1 */
/* @0x173a90 str r7, [sp] */
/* @0x173a94 mov r0, r5 */
/* @0x173a98 mov r1, r4 */
/* @0x173a9c bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat> */
/* @0x173aa0 ldr r3, [pc, #0x74] */
/* @0x173aa4 mov r2, #1 */
/* @0x173aa8 ldr r3, [pc, r3] */
/* @0x173aac ldr r3, [r3, #0x4] */
/* @0x173ab0 ldr r3, [r3, r6, lsl #2] */
/* @0x173ab4 strh r5, [r3, #4] */
/* @0x173ab8 strh r4, [r3, #6] */
/* @0x173abc strb r2, [r3, #0x10] */
/* @0x173ac0 cmp r0, #0 */
/* @0x173ac4 beq 0x173afc <_Z23GR_Texture_Create_Emptyiibbi+0xd8> */
/* @0x173ac8 vmov.f32 s15, #1.000000e+00 */
/* @0x173acc vldr s12, [r0, #4] */
/* @0x173ad0 vcvt.f32.s32 s14, s12 */
/* @0x173ad4 vldr s12, [r0, #8] */
/* @0x173ad8 str r0, [r3] */
/* @0x173adc mov r0, r6 */
/* @0x173ae0 vcvt.f32.s32 s13, s12 */
/* @0x173ae4 vdiv.f32 s14, s15, s14 */
/* @0x173ae8 vdiv.f32 s15, s15, s13 */
/* @0x173aec vstr s14, [r3, #8] */
/* @0x173af0 vstr s15, [r3, #12] */
/* @0x173af4 add sp, sp, #12 */
/* @0x173af8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x173afc mov r1, #1065353216 */
/* @0x173b00 str r0, [r3] */
/* @0x173b04 str r1, [r3, #0x8] */
/* @0x173b08 mov r0, r6 */
/* @0x173b0c str r1, [r3, #0xc] */
/* @0x173b10 add sp, sp, #12 */
/* @0x173b14 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x173b18 eoreq r10, r7, r4, ror #22 */
/* @0x173b1c eoreq r9, r7, r4, ror lr */

/* ── FUNC 0x173b20 · GR_Texture_Create_From_File(unsigned char*, unsigned int) · size=148 · insn=37 */
/* @0x173b20 push {r4, r5, r6, lr} */
/* @0x173b24 sub sp, sp, #40 */
/* @0x173b28 mov r5, r0 */
/* @0x173b2c mov r6, r1 */
/* @0x173b30 bl 0x173944 <_Z12AllocTexturev> */
/* @0x173b34 mov r1, r6 */
/* @0x173b38 add r2, sp, #12 */
/* @0x173b3c mov r3, #0 */
/* @0x173b40 str r3, [sp] */
/* @0x173b44 mov r3, #6 */
/* @0x173b48 mov r4, r0 */
/* @0x173b4c mov r0, r5 */
/* @0x173b50 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb> */
/* @0x173b54 ldr r2, [sp, #0x10] */
/* @0x173b58 vmov.f32 s15, #1.000000e+00 */
/* @0x173b5c vldr s12, [sp, #12] */
/* @0x173b60 vmov r12, s12 */
/* @0x173b64 mov r1, #1 */
/* @0x173b68 ldr r3, [pc, #0x40] */
/* @0x173b6c ldr r3, [pc, r3] */
/* @0x173b70 ldr r3, [r3, #0x4] */
/* @0x173b74 ldr r3, [r3, r4, lsl #2] */
/* @0x173b78 vcvt.f32.u32 s14, s12 */
/* @0x173b7c vmov s12, r2 */
/* @0x173b80 strh r2, [r3, #6] */
/* @0x173b84 strb r1, [r3, #0x10] */
/* @0x173b88 vcvt.f32.u32 s13, s12 */
/* @0x173b8c strh r12, [r3, #4] */
/* @0x173b90 vdiv.f32 s14, s15, s14 */
/* @0x173b94 str r0, [r3] */
/* @0x173b98 mov r0, r4 */
/* @0x173b9c vdiv.f32 s15, s15, s13 */
/* @0x173ba0 vstr s14, [r3, #8] */
/* @0x173ba4 vstr s15, [r3, #12] */
/* @0x173ba8 add sp, sp, #40 */
/* @0x173bac pop {r4, r5, r6, pc} */
/* @0x173bb0 .word 0x00279db0 */

/* ── FUNC 0x173bb4 · GR_Texture_Add(void*, int, int) · size=100 · insn=25 */
/* @0x173bb4 push {r4, r5, r6, lr} */
/* @0x173bb8 mov r5, r1 */
/* @0x173bbc mov r4, r2 */
/* @0x173bc0 mov r6, r0 */
/* @0x173bc4 bl 0x173944 <_Z12AllocTexturev> */
/* @0x173bc8 vmov s12, r5 */
/* @0x173bcc vmov.f32 s15, #1.000000e+00 */
/* @0x173bd0 ldr r3, [pc, #0x3c] */
/* @0x173bd4 mov r2, #1 */
/* @0x173bd8 ldr r3, [pc, r3] */
/* @0x173bdc ldr r3, [r3, #0x4] */
/* @0x173be0 vcvt.f32.s32 s14, s12 */
/* @0x173be4 vmov s12, r4 */
/* @0x173be8 vcvt.f32.s32 s13, s12 */
/* @0x173bec vdiv.f32 s14, s15, s14 */
/* @0x173bf0 ldr r3, [r3, r0, lsl #2] */
/* @0x173bf4 str r6, [r3] */
/* @0x173bf8 strh r5, [r3, #4] */
/* @0x173bfc strh r4, [r3, #6] */
/* @0x173c00 strb r2, [r3, #0x10] */
/* @0x173c04 vdiv.f32 s15, s15, s13 */
/* @0x173c08 vstr s14, [r3, #8] */
/* @0x173c0c vstr s15, [r3, #12] */
/* @0x173c10 pop {r4, r5, r6, pc} */
/* @0x173c14 eoreq r9, r7, r4, asr #26 */

/* ── FUNC 0x173c18 · GR_Texture_Create_And_Fill(int, int, unsigned char*, unsigned int) · size=196 · insn=49 */
/* @0x173c18 push {r4, r5, r6, r7, r8, lr} */
/* @0x173c1c sub sp, sp, #40 */
/* @0x173c20 mov r7, r3 */
/* @0x173c24 mov r5, r0 */
/* @0x173c28 mov r4, r1 */
/* @0x173c2c mov r8, r2 */
/* @0x173c30 bl 0x173944 <_Z12AllocTexturev> */
/* @0x173c34 mul r3, r4, r5 */
/* @0x173c38 cmp r7, r3, lsl #2 */
/* @0x173c3c mov r6, r0 */
/* @0x173c40 mov r0, r8 */
/* @0x173c44 beq 0x173cb8 <_Z26GR_Texture_Create_And_FilliiPhj+0xa0> */
/* @0x173c48 mov r1, r7 */
/* @0x173c4c mov r3, #0 */
/* @0x173c50 add r2, sp, #12 */
/* @0x173c54 str r3, [sp] */
/* @0x173c58 mov r3, #6 */
/* @0x173c5c bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb> */
/* @0x173c60 mov r1, r0 */
/* @0x173c64 vmov.f32 s15, #1.000000e+00 */
/* @0x173c68 vldr s13, [sp, #16] */
/* @0x173c6c vldr s12, [sp, #12] */
/* @0x173c70 ldr r3, [pc, #0x60] */
/* @0x173c74 mov r0, r6 */
/* @0x173c78 mov r2, #1 */
/* @0x173c7c ldr r3, [pc, r3] */
/* @0x173c80 ldr r3, [r3, #0x4] */
/* @0x173c84 ldr r3, [r3, r6, lsl #2] */
/* @0x173c88 vcvt.f32.u32 s14, s12 */
/* @0x173c8c strh r5, [r3, #4] */
/* @0x173c90 strh r4, [r3, #6] */
/* @0x173c94 strb r2, [r3, #0x10] */
/* @0x173c98 str r1, [r3] */
/* @0x173c9c vcvt.f32.u32 s13, s13 */
/* @0x173ca0 vdiv.f32 s14, s15, s14 */
/* @0x173ca4 vdiv.f32 s15, s15, s13 */
/* @0x173ca8 vstr s14, [r3, #8] */
/* @0x173cac vstr s15, [r3, #12] */
/* @0x173cb0 add sp, sp, #40 */
/* @0x173cb4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x173cb8 mov r3, #6 */
/* @0x173cbc mov r1, r5 */
/* @0x173cc0 str r3, [sp] */
/* @0x173cc4 mov r2, r4 */
/* @0x173cc8 add r3, sp, #12 */
/* @0x173ccc bl 0x183188 <_ZN8Graphics21CreateTextureFromDataEPhiiP9ImageInfo14eTextureFormat> */
/* @0x173cd0 mov r1, r0 */
/* @0x173cd4 b 0x173c64 <_Z26GR_Texture_Create_And_FilliiPhj+0x4c> */
/* @0x173cd8 eoreq r9, r7, r0, lsr #25 */

/* ── FUNC 0x173cdc · GR_Texture_Create(unsigned char*, unsigned int, bool, bool) · size=148 · insn=37 */
/* @0x173cdc push {r4, r5, r6, r7, lr} */
/* @0x173ce0 sub sp, sp, #44 */
/* @0x173ce4 mov r7, r3 */
/* @0x173ce8 mov r5, r0 */
/* @0x173cec mov r6, r1 */
/* @0x173cf0 bl 0x173944 <_Z12AllocTexturev> */
/* @0x173cf4 mov r1, r6 */
/* @0x173cf8 add r2, sp, #12 */
/* @0x173cfc str r7, [sp] */
/* @0x173d00 mov r3, #6 */
/* @0x173d04 mov r4, r0 */
/* @0x173d08 mov r0, r5 */
/* @0x173d0c bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb> */
/* @0x173d10 ldr r2, [sp, #0x10] */
/* @0x173d14 vmov.f32 s15, #1.000000e+00 */
/* @0x173d18 vldr s12, [sp, #12] */
/* @0x173d1c vmov r12, s12 */
/* @0x173d20 mov r1, #1 */
/* @0x173d24 ldr r3, [pc, #0x40] */
/* @0x173d28 ldr r3, [pc, r3] */
/* @0x173d2c ldr r3, [r3, #0x4] */
/* @0x173d30 ldr r3, [r3, r4, lsl #2] */
/* @0x173d34 vcvt.f32.u32 s14, s12 */
/* @0x173d38 vmov s12, r2 */
/* @0x173d3c strh r2, [r3, #6] */
/* @0x173d40 strb r1, [r3, #0x10] */
/* @0x173d44 vcvt.f32.u32 s13, s12 */
/* @0x173d48 strh r12, [r3, #4] */
/* @0x173d4c vdiv.f32 s14, s15, s14 */
/* @0x173d50 str r0, [r3] */
/* @0x173d54 mov r0, r4 */
/* @0x173d58 vdiv.f32 s15, s15, s13 */
/* @0x173d5c vstr s14, [r3, #8] */
/* @0x173d60 vstr s15, [r3, #12] */
/* @0x173d64 add sp, sp, #44 */
/* @0x173d68 pop {r4, r5, r6, r7, pc} */
/* @0x173d6c .word 0x00279bf4 */

/* ── FUNC 0x173d70 · GR_Texture_Fill(int, TDWordArray*) · size=64 · insn=16 */
/* @0x173d70 ldr r3, [pc, #0x34] */
/* @0x173d74 ldr r12, [r1, #0x4] */
/* @0x173d78 mov r1, #0 */
/* @0x173d7c ldr r3, [pc, r3] */
/* @0x173d80 str lr, [sp, #-0x4]! */
/* @0x173d84 sub sp, sp, #12 */
/* @0x173d88 ldr r3, [r3, #0x4] */
/* @0x173d8c ldr r3, [r3, r0, lsl #2] */
/* @0x173d90 ldrsh r2, [r3, #4] */
/* @0x173d94 ldr r0, [r3] */
/* @0x173d98 ldrsh r3, [r3, #6] */
/* @0x173d9c str r12, [sp] */
/* @0x173da0 bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_> */
/* @0x173da4 add sp, sp, #12 */
/* @0x173da8 ldr pc, [sp], #4 */
/* @0x173dac eoreq r9, r7, r0, lsr #23 */

/* ── FUNC 0x173db0 · GR_Texture_Init() · size=124 · insn=31 */
/* @0x173db0 push {r4, r5, r6, lr} */
/* @0x173db4 ldr r5, [pc, #0x68] */
/* @0x173db8 ldr r5, [pc, r5] */
/* @0x173dbc ldr r0, [r5, #0x4] */
/* @0x173dc0 cmp r0, #0 */
/* @0x173dc4 beq 0x173e0c <_Z15GR_Texture_Initv+0x5c> */
/* @0x173dc8 ldr r3, [r5] */
/* @0x173dcc cmp r3, #0 */
/* @0x173dd0 ble 0x173e00 <_Z15GR_Texture_Initv+0x50> */
/* @0x173dd4 mov r4, #0 */
/* @0x173dd8 mov r6, r4 */
/* @0x173ddc ldr r0, [r0, r4, lsl #2] */
/* @0x173de0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x173de4 ldr r2, [r5, #0x4] */
/* @0x173de8 ldr r3, [r5] */
/* @0x173dec str r6, [r2, r4, lsl #2] */
/* @0x173df0 add r4, r4, #1 */
/* @0x173df4 cmp r3, r4 */
/* @0x173df8 ldr r0, [r5, #0x4] */
/* @0x173dfc bgt 0x173ddc <_Z15GR_Texture_Initv+0x2c> */
/* @0x173e00 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x173e04 mov r3, #0 */
/* @0x173e08 str r3, [r5, #0x4] */
/* @0x173e0c ldr r3, [pc, #0x14] */
/* @0x173e10 mov r2, #0 */
/* @0x173e14 str r2, [r5] */
/* @0x173e18 ldr r3, [pc, r3] */
/* @0x173e1c str r2, [r3] */
/* @0x173e20 pop {r4, r5, r6, pc} */
/* @0x173e24 eoreq r9, r7, r4, ror #22 */
/* @0x173e28 mlaeq r7, r8, r4, r12 */

/* ── FUNC 0x173e2c · GR_Texture_Exists(int) · size=68 · insn=17 */
/* @0x173e2c cmp r0, #0 */
/* @0x173e30 blt 0x173e60 <_Z17GR_Texture_Existsi+0x34> */
/* @0x173e34 ldr r3, [pc, #0x2c] */
/* @0x173e38 ldr r3, [pc, r3] */
/* @0x173e3c ldr r3, [r3] */
/* @0x173e40 cmp r0, r3 */
/* @0x173e44 bge 0x173e60 <_Z17GR_Texture_Existsi+0x34> */
/* @0x173e48 ldr r3, [pc, #0x1c] */
/* @0x173e4c ldr r3, [pc, r3] */
/* @0x173e50 ldr r3, [r3, #0x4] */
/* @0x173e54 ldr r3, [r3, r0, lsl #2] */
/* @0x173e58 ldrb r0, [r3, #0x10] */
/* @0x173e5c bx lr */
/* @0x173e60 mov r0, #0 */
/* @0x173e64 bx lr */
/* @0x173e68 eoreq r12, r7, r8, ror r4 */
/* @0x173e6c .word 0x00279ad0 */

/* ── FUNC 0x173e70 · GR_Texture_Create_Direct(CBitmap32*) · size=100 · insn=25 */
/* @0x173e70 push {r4, r5, r6, r7, r8, lr} */
/* @0x173e74 subs r4, r0, #0 */
/* @0x173e78 beq 0x173ecc <_Z24GR_Texture_Create_DirectP9CBitmap32+0x5c> */
/* @0x173e7c bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x173e80 mov r5, r0 */
/* @0x173e84 mov r0, r4 */
/* @0x173e88 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x173e8c mov r7, r0 */
/* @0x173e90 mov r0, r4 */
/* @0x173e94 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x173e98 ldr r8, [r0, #0x4] */
/* @0x173e9c mov r0, r4 */
/* @0x173ea0 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x173ea4 mov r6, r0 */
/* @0x173ea8 mov r0, r4 */
/* @0x173eac bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x173eb0 mov r2, r8 */
/* @0x173eb4 mov r1, r7 */
/* @0x173eb8 mul r3, r0, r6 */
/* @0x173ebc mov r0, r5 */
/* @0x173ec0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x173ec4 lsl r3, r3, #2 */
/* @0x173ec8 b 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0x173ecc mvn r0, #0 */
/* @0x173ed0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x173ed4 · GR_Texture_Create_Bitmap(IBitmap*, bool, bool) · size=176 · insn=44 */
/* @0x173ed4 push {r4, r5, r6, r7, r8, lr} */
/* @0x173ed8 subs r7, r0, #0 */
/* @0x173edc mov r6, r1 */
/* @0x173ee0 mov r5, r2 */
/* @0x173ee4 beq 0x173f7c <_Z24GR_Texture_Create_BitmapP7IBitmapbb+0xa8> */
/* @0x173ee8 mov r0, #24 */
/* @0x173eec bl 0x27c524 <_Znwj> */
/* @0x173ef0 mov r1, r7 */
/* @0x173ef4 mov r2, r6 */
/* @0x173ef8 mov r3, r5 */
/* @0x173efc mov r4, r0 */
/* @0x173f00 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0x173f04 mov r0, r4 */
/* @0x173f08 bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x173f0c mov r5, r0 */
/* @0x173f10 mov r0, r4 */
/* @0x173f14 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x173f18 mov r8, r0 */
/* @0x173f1c mov r0, r4 */
/* @0x173f20 bl 0x167970 <_ZN9CBitmap327GetDataEv> */
/* @0x173f24 mov r7, r0 */
/* @0x173f28 mov r0, r4 */
/* @0x173f2c bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0x173f30 mov r6, r0 */
/* @0x173f34 mov r0, r4 */
/* @0x173f38 bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0x173f3c mov r1, r8 */
/* @0x173f40 mov r2, r7 */
/* @0x173f44 mul r3, r0, r6 */
/* @0x173f48 mov r0, r5 */
/* @0x173f4c lsl r3, r3, #2 */
/* @0x173f50 bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0x173f54 cmp r4, #0 */
/* @0x173f58 mov r5, r0 */
/* @0x173f5c beq 0x173f78 <_Z24GR_Texture_Create_BitmapP7IBitmapbb+0xa4> */
/* @0x173f60 ldr r3, [r4] */
/* @0x173f64 mov r0, r4 */
/* @0x173f68 ldr r3, [r3, #0x4] */
/* @0x173f6c blx r3 */
/* @0x173f70 mov r0, r5 */
/* @0x173f74 pop {r4, r5, r6, r7, r8, pc} */
/* @0x173f78 pop {r4, r5, r6, r7, r8, pc} */
/* @0x173f7c mvn r0, #0 */
/* @0x173f80 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x173f84 · GR_Texture_Free(int) · size=88 · insn=22 */
/* @0x173f84 push {r3, r4, r5, lr} */
/* @0x173f88 mov r5, r0 */
/* @0x173f8c bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x173f90 cmp r0, #0 */
/* @0x173f94 popeq {r3, r4, r5, pc} */
/* @0x173f98 ldr r4, [pc, #0x38] */
/* @0x173f9c ldr r4, [pc, r4] */
/* @0x173fa0 ldr r3, [r4, #0x4] */
/* @0x173fa4 ldr r3, [r3, r5, lsl #2] */
/* @0x173fa8 ldr r0, [r3] */
/* @0x173fac cmp r0, #0 */
/* @0x173fb0 beq 0x173fcc <_Z15GR_Texture_Freei+0x48> */
/* @0x173fb4 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv> */
/* @0x173fb8 ldr r3, [r4, #0x4] */
/* @0x173fbc mov r1, #0 */
/* @0x173fc0 ldr r2, [r3, r5, lsl #2] */
/* @0x173fc4 str r1, [r2] */
/* @0x173fc8 ldr r3, [r3, r5, lsl #2] */
/* @0x173fcc mov r2, #0 */
/* @0x173fd0 strb r2, [r3, #0x10] */
/* @0x173fd4 pop {r3, r4, r5, pc} */
/* @0x173fd8 eoreq r9, r7, r0, lsl #19 */

/* ── FUNC 0x173fdc · GR_Texture_Create_Bytes(int, int, DynamicArrayOfByte*) · size=260 · insn=65 */
/* @0x173fdc push {r4, r5, r6, r7, r8, lr} */
/* @0x173fe0 mov r6, r1 */
/* @0x173fe4 mul r8, r1, r0 */
/* @0x173fe8 ldr r1, [pc, #0xec] */
/* @0x173fec sub sp, sp, #16 */
/* @0x173ff0 mov r5, r0 */
/* @0x173ff4 mov r7, r2 */
/* @0x173ff8 add r1, pc, r1 */
/* @0x173ffc movw r2, #0x1dd */
/* @0x174000 mov r3, #1 */
/* @0x174004 mov r4, #0 */
/* @0x174008 str r4, [sp, #0x8] */
/* @0x17400c lsl r8, r8, #2 */
/* @0x174010 str r4, [sp, #0xc] */
/* @0x174014 mov r0, r8 */
/* @0x174018 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x17401c cmp r6, r4 */
/* @0x174020 str r8, [sp, #0x8] */
/* @0x174024 str r0, [sp, #0xc] */
/* @0x174028 ble 0x174088 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xac> */
/* @0x17402c sub r0, r0, #4 */
/* @0x174030 lsl r8, r5, #2 */
/* @0x174034 mov r2, r4 */
/* @0x174038 mov r1, r4 */
/* @0x17403c cmp r5, #0 */
/* @0x174040 ble 0x174074 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x98> */
/* @0x174044 ldr r12, [r7, #0x4] */
/* @0x174048 mov lr, r0 */
/* @0x17404c add r4, r12, r5 */
/* @0x174050 add r12, r12, r2 */
/* @0x174054 add r4, r4, r2 */
/* @0x174058 ldrb r3, [r12], #1 */
/* @0x17405c cmp r12, r4 */
/* @0x174060 lsl r3, r3, #24 */
/* @0x174064 add r3, r3, #16777216 */
/* @0x174068 sub r3, r3, #1 */
/* @0x17406c str r3, [lr, #0x4]! */
/* @0x174070 bne 0x174058 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x7c> */
/* @0x174074 add r1, r1, #1 */
/* @0x174078 add r0, r0, r8 */
/* @0x17407c cmp r1, r6 */
/* @0x174080 add r2, r2, r5 */
/* @0x174084 bne 0x17403c <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0x60> */
/* @0x174088 mov r2, #0 */
/* @0x17408c mov r12, #4 */
/* @0x174090 mov r1, r6 */
/* @0x174094 mov r3, r2 */
/* @0x174098 str r12, [sp] */
/* @0x17409c mov r0, r5 */
/* @0x1740a0 bl 0x173a24 <_Z23GR_Texture_Create_Emptyiibbi> */
/* @0x1740a4 add r1, sp, #8 */
/* @0x1740a8 mov r4, r0 */
/* @0x1740ac bl 0x173d70 <_Z15GR_Texture_FilliP11TDWordArray> */
/* @0x1740b0 cmp r0, #0 */
/* @0x1740b4 beq 0x1740cc <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xf0> */
/* @0x1740b8 ldr r0, [sp, #0xc] */
/* @0x1740bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1740c0 mov r0, r4 */
/* @0x1740c4 add sp, sp, #16 */
/* @0x1740c8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1740cc mov r0, r4 */
/* @0x1740d0 mvn r4, #0 */
/* @0x1740d4 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x1740d8 b 0x1740b8 <_Z23GR_Texture_Create_BytesiiP18DynamicArrayOfByte+0xdc> */
/* @0x1740dc andseq r7, sp, r12, lsl r5 */

/* ── FUNC 0x1740e0 · GR_Texture_End() · size=280 · insn=70 */
/* @0x1740e0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1740e4 ldr r7, [pc, #0x100] */
/* @0x1740e8 ldr r7, [pc, r7] */
/* @0x1740ec ldr r3, [r7] */
/* @0x1740f0 cmp r3, #0 */
/* @0x1740f4 movgt r4, #0 */
/* @0x1740f8 ble 0x174114 <_Z14GR_Texture_Endv+0x34> */
/* @0x1740fc mov r0, r4 */
/* @0x174100 add r4, r4, #1 */
/* @0x174104 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x174108 ldr r3, [r7] */
/* @0x17410c cmp r3, r4 */
/* @0x174110 bgt 0x1740fc <_Z14GR_Texture_Endv+0x1c> */
/* @0x174114 ldr r5, [pc, #0xd4] */
/* @0x174118 ldr r5, [pc, r5] */
/* @0x17411c ldr r0, [r5, #0x4] */
/* @0x174120 cmp r0, #0 */
/* @0x174124 beq 0x17416c <_Z14GR_Texture_Endv+0x8c> */
/* @0x174128 ldr r3, [r5] */
/* @0x17412c cmp r3, #0 */
/* @0x174130 ble 0x174160 <_Z14GR_Texture_Endv+0x80> */
/* @0x174134 mov r4, #0 */
/* @0x174138 mov r6, r4 */
/* @0x17413c ldr r0, [r0, r4, lsl #2] */
/* @0x174140 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x174144 ldr r2, [r5, #0x4] */
/* @0x174148 ldr r3, [r5] */
/* @0x17414c str r6, [r2, r4, lsl #2] */
/* @0x174150 add r4, r4, #1 */
/* @0x174154 cmp r3, r4 */
/* @0x174158 ldr r0, [r5, #0x4] */
/* @0x17415c bgt 0x17413c <_Z14GR_Texture_Endv+0x5c> */
/* @0x174160 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x174164 mov r3, #0 */
/* @0x174168 str r3, [r5, #0x4] */
/* @0x17416c ldr r6, [pc, #0x80] */
/* @0x174170 mov r9, #0 */
/* @0x174174 str r9, [r5] */
/* @0x174178 ldr r6, [pc, r6] */
/* @0x17417c str r9, [r7] */
/* @0x174180 ldr r8, [r6, #0x4] */
/* @0x174184 cmp r8, r9 */
/* @0x174188 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x17418c lsl r7, r8, #3 */
/* @0x174190 ldr r3, [r6] */
/* @0x174194 add r2, r3, r7 */
/* @0x174198 ldr r4, [r3, r7] */
/* @0x17419c str r9, [r3, r7] */
/* @0x1741a0 cmp r4, #0 */
/* @0x1741a4 str r9, [r2, #0x4] */
/* @0x1741a8 beq 0x1741d8 <_Z14GR_Texture_Endv+0xf8> */
/* @0x1741ac ldr r5, [r4, #0x4] */
/* @0x1741b0 ldr r0, [r4, #0xc] */
/* @0x1741b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1741b8 mov r0, r4 */
/* @0x1741bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1741c0 ldr r3, [r6, #0x8] */
/* @0x1741c4 cmp r5, #0 */
/* @0x1741c8 mov r4, r5 */
/* @0x1741cc sub r3, r3, #1 */
/* @0x1741d0 str r3, [r6, #0x8] */
/* @0x1741d4 bne 0x1741ac <_Z14GR_Texture_Endv+0xcc> */
/* @0x1741d8 sub r8, r8, #1 */
/* @0x1741dc sub r7, r7, #8 */
/* @0x1741e0 cmn r8, #1 */
/* @0x1741e4 bne 0x174190 <_Z14GR_Texture_Endv+0xb0> */
/* @0x1741e8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1741ec eoreq r12, r7, r8, asr #3 */
/* @0x1741f0 eoreq r9, r7, r4, lsl #16 */
/* @0x1741f4 mlaeq r7, r8, r9, r9 */

/* ── FUNC 0x1741f8 · GR_Texture_Get_Width(int) · size=72 · insn=18 */
/* @0x1741f8 push {r4, lr} */
/* @0x1741fc mov r4, r0 */
/* @0x174200 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174204 cmp r0, #0 */
/* @0x174208 vmoveq.f32 s15, #1.000000e+00 */
/* @0x17420c beq 0x174234 <_Z20GR_Texture_Get_Widthi+0x3c> */
/* @0x174210 ldr r3, [pc, #0x24] */
/* @0x174214 ldr r3, [pc, r3] */
/* @0x174218 ldr r3, [r3, #0x4] */
/* @0x17421c ldr r3, [r3, r4, lsl #2] */
/* @0x174220 vldr s14, [r3, #8] */
/* @0x174224 ldrsh r3, [r3, #4] */
/* @0x174228 vmov s15, r3 */
/* @0x17422c vcvt.f32.s32 s15, s15 */
/* @0x174230 vmul.f32 s15, s15, s14 */
/* @0x174234 vmov r0, s15 */
/* @0x174238 pop {r4, pc} */
/* @0x17423c eoreq r9, r7, r8, lsl #14 */

/* ── FUNC 0x174240 · GR_Texture_Get_Height(int) · size=72 · insn=18 */
/* @0x174240 push {r4, lr} */
/* @0x174244 mov r4, r0 */
/* @0x174248 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x17424c cmp r0, #0 */
/* @0x174250 vmoveq.f32 s15, #1.000000e+00 */
/* @0x174254 beq 0x17427c <_Z21GR_Texture_Get_Heighti+0x3c> */
/* @0x174258 ldr r3, [pc, #0x24] */
/* @0x17425c ldr r3, [pc, r3] */
/* @0x174260 ldr r3, [r3, #0x4] */
/* @0x174264 ldr r3, [r3, r4, lsl #2] */
/* @0x174268 vldr s14, [r3, #12] */
/* @0x17426c ldrsh r3, [r3, #6] */
/* @0x174270 vmov s15, r3 */
/* @0x174274 vcvt.f32.s32 s15, s15 */
/* @0x174278 vmul.f32 s15, s15, s14 */
/* @0x17427c vmov r0, s15 */
/* @0x174280 pop {r4, pc} */
/* @0x174284 eoreq r9, r7, r0, asr #13 */

/* ── FUNC 0x174288 · GR_Texture_Preload(int) · size=52 · insn=13 */
/* @0x174288 push {r4, lr} */
/* @0x17428c mov r4, r0 */
/* @0x174290 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x174294 cmp r0, #0 */
/* @0x174298 popeq {r4, pc} */
/* @0x17429c ldr r3, [pc, #0x14] */
/* @0x1742a0 ldr r3, [pc, r3] */
/* @0x1742a4 ldr r3, [r3, #0x4] */
/* @0x1742a8 ldr r3, [r3, r4, lsl #2] */
/* @0x1742ac pop {r4, lr} */
/* @0x1742b0 ldr r0, [r3] */
/* @0x1742b4 b 0x1833c4 <_ZN8Graphics14PreLoadTextureEPv> */
/* @0x1742b8 eoreq r9, r7, r12, ror r6 */
