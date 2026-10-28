/* libyoyo.so 覆盖卡组 0244
 * 函数 0x2952dc..0x2970c0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2952dc · yySocket::Read(void*, unsigned int, unsigned int) · size=16 · insn=4 */
/* @0x2952dc ldr r12, [r0, #0xc] */
/* @0x2952e0 ldr r0, [r0] */
/* @0x2952e4 orr r3, r3, r12 */
/* @0x2952e8 b 0xb6df0 <recv@plt> */

/* ── FUNC 0x2952ec · yySocket::ReadFrom(void*, unsigned int, unsigned int, char**, int*) · size=332 · insn=83 */
/* @0x2952ec push {r4, r5, r6, r7, r8, lr} */
/* @0x2952f0 sub sp, sp, #48 */
/* @0x2952f4 ldr r4, [pc, #0x134] */
/* @0x2952f8 ldrb r12, [r0, #0xc4] */
/* @0x2952fc ldr r4, [pc, r4] */
/* @0x295300 ldr r6, [sp, #0x48] */
/* @0x295304 cmp r12, #0 */
/* @0x295308 ldr r5, [sp, #0x4c] */
/* @0x29530c ldr r12, [r4] */
/* @0x295310 str r12, [sp, #0x2c] */
/* @0x295314 beq 0x2953b4 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xc8> */
/* @0x295318 ldr r8, [r0] */
/* @0x29531c mov r12, #28 */
/* @0x295320 ldr lr, [r0, #0xc] */
/* @0x295324 str r12, [sp, #0xc] */
/* @0x295328 orr r3, r3, lr */
/* @0x29532c mov r0, r8 */
/* @0x295330 add lr, sp, #16 */
/* @0x295334 str lr, [sp] */
/* @0x295338 add lr, sp, #12 */
/* @0x29533c str lr, [sp, #0x4] */
/* @0x295340 bl 0xb6dfc <recvfrom@plt> */
/* @0x295344 ldr r7, [pc, #0xe8] */
/* @0x295348 add r1, sp, #24 */
/* @0x29534c mov r3, #256 */
/* @0x295350 add r7, pc, r7 */
/* @0x295354 mov r2, r7 */
/* @0x295358 mov r8, r0 */
/* @0x29535c mov r0, #10 */
/* @0x295360 bl 0xb6e08 <inet_ntop@plt> */
/* @0x295364 cmp r0, #0 */
/* @0x295368 beq 0x295374 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x88> */
/* @0x29536c cmp r6, #0 */
/* @0x295370 strne r7, [r6] */
/* @0x295374 cmp r5, #0 */
/* @0x295378 beq 0x295398 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xac> */
/* @0x29537c ldrh r3, [sp, #16] */
/* @0x295380 mov r2, #0 */
/* @0x295384 str r2, [r5] */
/* @0x295388 cmp r3, #2 */
/* @0x29538c beq 0x295418 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x12c> */
/* @0x295390 cmp r3, #10 */
/* @0x295394 beq 0x295418 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x12c> */
/* @0x295398 mov r0, r8 */
/* @0x29539c ldr r2, [sp, #0x2c] */
/* @0x2953a0 ldr r3, [r4] */
/* @0x2953a4 cmp r2, r3 */
/* @0x2953a8 bne 0x29542c <_ZN8yySocket8ReadFromEPvjjPPcPi+0x140> */
/* @0x2953ac add sp, sp, #48 */
/* @0x2953b0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2953b4 ldr r7, [r0] */
/* @0x2953b8 mov r12, #16 */
/* @0x2953bc ldr lr, [r0, #0xc] */
/* @0x2953c0 add r0, sp, #16 */
/* @0x2953c4 str r0, [sp] */
/* @0x2953c8 orr r3, r3, lr */
/* @0x2953cc mov r0, r7 */
/* @0x2953d0 add lr, sp, #12 */
/* @0x2953d4 str lr, [sp, #0x4] */
/* @0x2953d8 str r12, [sp, #0xc] */
/* @0x2953dc bl 0xb6dfc <recvfrom@plt> */
/* @0x2953e0 cmp r6, #0 */
/* @0x2953e4 mov r7, r0 */
/* @0x2953e8 beq 0x2953f8 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x10c> */
/* @0x2953ec ldr r0, [sp, #0x14] */
/* @0x2953f0 bl 0xb6e14 <inet_ntoa@plt> */
/* @0x2953f4 str r0, [r6] */
/* @0x2953f8 cmp r5, #0 */
/* @0x2953fc beq 0x295410 <_ZN8yySocket8ReadFromEPvjjPPcPi+0x124> */
/* @0x295400 ldrh r3, [sp, #18] */
/* @0x295404 rev16 r3, r3 */
/* @0x295408 uxth r3, r3 */
/* @0x29540c str r3, [r5] */
/* @0x295410 mov r0, r7 */
/* @0x295414 b 0x29539c <_ZN8yySocket8ReadFromEPvjjPPcPi+0xb0> */
/* @0x295418 ldrh r3, [sp, #18] */
/* @0x29541c rev16 r3, r3 */
/* @0x295420 uxth r3, r3 */
/* @0x295424 str r3, [r5] */
/* @0x295428 b 0x295398 <_ZN8yySocket8ReadFromEPvjjPPcPi+0xac> */
/* @0x29542c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x295430 andseq r8, r5, r4, asr r6 */
/* @0x295434 subeq r2, r12, r8, ror #8 */

/* ── FUNC 0x295438 · yySocket::Peek() · size=44 · insn=11 */
/* @0x295438 str lr, [sp, #-0x4]! */
/* @0x29543c sub sp, sp, #12 */
/* @0x295440 add r2, sp, #8 */
/* @0x295444 mov r3, #0 */
/* @0x295448 movw r1, #0x541b */
/* @0x29544c ldr r0, [r0] */
/* @0x295450 str r3, [r2, #-0x4]! */
/* @0x295454 bl 0xb6db4 <ioctl@plt> */
/* @0x295458 ldr r0, [sp, #0x4] */
/* @0x29545c add sp, sp, #12 */
/* @0x295460 ldr pc, [sp], #4 */

/* ── FUNC 0x295464 · yySocket::Write(void*, unsigned int) · size=16 · insn=4 */
/* @0x295464 mov r3, r0 */
/* @0x295468 ldr r0, [r0] */
/* @0x29546c ldr r3, [r3, #0xc] */
/* @0x295470 b 0xb6e20 <send@plt> */

/* ── FUNC 0x295474 · yySocket::Close() · size=52 · insn=13 */
/* @0x295474 ldr r3, [r0] */
/* @0x295478 push {r4, lr} */
/* @0x29547c cmn r3, #1 */
/* @0x295480 mov r4, r0 */
/* @0x295484 beq 0x29549c <_ZN8yySocket5CloseEv+0x28> */
/* @0x295488 ldr r0, [r0, #0x4] */
/* @0x29548c mov r1, #2 */
/* @0x295490 bl 0xb6d6c <shutdown@plt> */
/* @0x295494 ldr r0, [r4] */
/* @0x295498 bl 0xb6d78 <close@plt> */
/* @0x29549c mvn r3, #0 */
/* @0x2954a0 str r3, [r4] */
/* @0x2954a4 pop {r4, pc} */

/* ── FUNC 0x2954a8 · yySocket::Resolve(char*) · size=792 · insn=198 */
/* @0x2954a8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2954ac sub sp, sp, #108 */
/* @0x2954b0 ldr r9, [pc, #0x2dc] */
/* @0x2954b4 mov r4, r0 */
/* @0x2954b8 ldr r3, [pc, #0x2d8] */
/* @0x2954bc add r9, pc, r9 */
/* @0x2954c0 ldr r5, [r9, r3] */
/* @0x2954c4 ldr r3, [r5] */
/* @0x2954c8 str r3, [sp, #0x64] */
/* @0x2954cc bl 0x297000 <_ZN8yySocket10DetectIPv6Ev> */
/* @0x2954d0 subs r7, r0, #0 */
/* @0x2954d4 beq 0x2955f8 <_ZN8yySocket7ResolveEPc+0x150> */
/* @0x2954d8 ldr r1, [pc, #0x2bc] */
/* @0x2954dc mov r2, #70 */
/* @0x2954e0 mov r3, #1 */
/* @0x2954e4 mov r0, #28 */
/* @0x2954e8 add r1, pc, r1 */
/* @0x2954ec mov r7, #0 */
/* @0x2954f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2954f4 ldr r1, [pc, #0x2a4] */
/* @0x2954f8 mov r3, #2 */
/* @0x2954fc str r7, [sp] */
/* @0x295500 add r1, pc, r1 */
/* @0x295504 mov r6, r0 */
/* @0x295508 mov r0, r4 */
/* @0x29550c strh r3, [r6] */
/* @0x295510 bl 0xb6574 <strcmp@plt> */
/* @0x295514 cmp r0, #0 */
/* @0x295518 beq 0x295688 <_ZN8yySocket7ResolveEPc+0x1e0> */
/* @0x29551c ldr r1, [pc, #0x280] */
/* @0x295520 mov r0, r4 */
/* @0x295524 str r7, [sp, #0x4] */
/* @0x295528 add r1, pc, r1 */
/* @0x29552c str r7, [sp, #0x8] */
/* @0x295530 str r7, [sp, #0xc] */
/* @0x295534 str r7, [sp, #0x10] */
/* @0x295538 str r7, [sp, #0x14] */
/* @0x29553c str r7, [sp, #0x18] */
/* @0x295540 str r7, [sp, #0x1c] */
/* @0x295544 str r7, [sp, #0x20] */
/* @0x295548 bl 0xb6604 <strstr@plt> */
/* @0x29554c cmp r0, r7 */
/* @0x295550 beq 0x2956ac <_ZN8yySocket7ResolveEPc+0x204> */
/* @0x295554 add r8, sp, #4 */
/* @0x295558 mov r3, sp */
/* @0x29555c mov r0, r4 */
/* @0x295560 mov r1, #0 */
/* @0x295564 mov r2, r8 */
/* @0x295568 bl 0xb6e2c <getaddrinfo@plt> */
/* @0x29556c ldr r3, [pc, #0x234] */
/* @0x295570 ldr r9, [r9, r3] */
/* @0x295574 cmp r0, #0 */
/* @0x295578 str r0, [r9] */
/* @0x29557c bne 0x2956b8 <_ZN8yySocket7ResolveEPc+0x210> */
/* @0x295580 ldr r3, [sp] */
/* @0x295584 cmp r3, #0 */
/* @0x295588 beq 0x295750 <_ZN8yySocket7ResolveEPc+0x2a8> */
/* @0x29558c mov r4, r0 */
/* @0x295590 mov r12, r3 */
/* @0x295594 mov r10, r0 */
/* @0x295598 ldr lr, [r12, #0x4] */
/* @0x29559c cmp lr, #10 */
/* @0x2955a0 moveq r10, r12 */
/* @0x2955a4 beq 0x2955b0 <_ZN8yySocket7ResolveEPc+0x108> */
/* @0x2955a8 cmp lr, #2 */
/* @0x2955ac moveq r4, r12 */
/* @0x2955b0 ldr r12, [r12, #0x1c] */
/* @0x2955b4 cmp r12, #0 */
/* @0x2955b8 bne 0x295598 <_ZN8yySocket7ResolveEPc+0xf0> */
/* @0x2955bc cmp r10, #0 */
/* @0x2955c0 beq 0x2956d8 <_ZN8yySocket7ResolveEPc+0x230> */
/* @0x2955c4 mov r0, r6 */
/* @0x2955c8 ldr r1, [r10, #0x18] */
/* @0x2955cc ldr r2, [r10, #0x10] */
/* @0x2955d0 bl 0xb65bc <memcpy@plt> */
/* @0x2955d4 ldr r0, [sp] */
/* @0x2955d8 bl 0xb6e38 <freeaddrinfo@plt> */
/* @0x2955dc mov r0, r6 */
/* @0x2955e0 ldr r2, [sp, #0x64] */
/* @0x2955e4 ldr r3, [r5] */
/* @0x2955e8 cmp r2, r3 */
/* @0x2955ec bne 0x295790 <_ZN8yySocket7ResolveEPc+0x2e8> */
/* @0x2955f0 add sp, sp, #108 */
/* @0x2955f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2955f8 ldr r1, [pc, #0x1ac] */
/* @0x2955fc mov r2, #70 */
/* @0x295600 mov r3, #1 */
/* @0x295604 mov r0, #16 */
/* @0x295608 add r1, pc, r1 */
/* @0x29560c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x295610 ldr r1, [pc, #0x198] */
/* @0x295614 str r7, [sp, #0x4] */
/* @0x295618 mov r3, #2 */
/* @0x29561c add r1, pc, r1 */
/* @0x295620 mov r6, r0 */
/* @0x295624 mov r0, r4 */
/* @0x295628 strh r3, [r6] */
/* @0x29562c bl 0xb6574 <strcmp@plt> */
/* @0x295630 cmp r0, #0 */
/* @0x295634 ldreq r4, [pc, #0x178] */
/* @0x295638 addeq r4, pc, r4 */
/* @0x29563c mov r0, r4 */
/* @0x295640 bl 0xb6e44 <inet_addr@plt> */
/* @0x295644 cmn r0, #1 */
/* @0x295648 str r0, [r6, #0x4] */
/* @0x29564c movne r0, r6 */
/* @0x295650 bne 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138> */
/* @0x295654 mov r1, #0 */
/* @0x295658 add r3, sp, #4 */
/* @0x29565c mov r0, r4 */
/* @0x295660 mov r2, r1 */
/* @0x295664 bl 0xb6e2c <getaddrinfo@plt> */
/* @0x295668 ldr r3, [pc, #0x138] */
/* @0x29566c ldr r3, [r9, r3] */
/* @0x295670 cmp r0, #0 */
/* @0x295674 str r0, [r3] */
/* @0x295678 beq 0x295774 <_ZN8yySocket7ResolveEPc+0x2cc> */
/* @0x29567c mov r0, r6 */
/* @0x295680 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x295684 b 0x2956d0 <_ZN8yySocket7ResolveEPc+0x228> */
/* @0x295688 ldr r4, [pc, #0x128] */
/* @0x29568c str r0, [sp, #0x8] */
/* @0x295690 add r4, pc, r4 */
/* @0x295694 str r0, [sp, #0xc] */
/* @0x295698 str r0, [sp, #0x10] */
/* @0x29569c str r0, [sp, #0x14] */
/* @0x2956a0 str r0, [sp, #0x18] */
/* @0x2956a4 str r0, [sp, #0x1c] */
/* @0x2956a8 str r0, [sp, #0x20] */
/* @0x2956ac mov r3, #4 */
/* @0x2956b0 str r3, [sp, #0x4] */
/* @0x2956b4 b 0x295554 <_ZN8yySocket7ResolveEPc+0xac> */
/* @0x2956b8 mov r0, r6 */
/* @0x2956bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2956c0 ldr r0, [sp] */
/* @0x2956c4 cmp r0, #0 */
/* @0x2956c8 beq 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138> */
/* @0x2956cc bl 0xb6e38 <freeaddrinfo@plt> */
/* @0x2956d0 mov r0, #0 */
/* @0x2956d4 b 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138> */
/* @0x2956d8 cmp r4, #0 */
/* @0x2956dc beq 0x295750 <_ZN8yySocket7ResolveEPc+0x2a8> */
/* @0x2956e0 ldr r12, [r4, #0x18] */
/* @0x2956e4 add r4, sp, #36 */
/* @0x2956e8 ldr r1, [pc, #0xcc] */
/* @0x2956ec mov r0, r4 */
/* @0x2956f0 ldrb lr, [r12, #0x6] */
/* @0x2956f4 add r1, pc, r1 */
/* @0x2956f8 ldrb r11, [r12, #0x4] */
/* @0x2956fc ldrb r2, [r12, #0x5] */
/* @0x295700 ldrb r3, [r12, #0x7] */
/* @0x295704 orr r2, r2, r11, lsl #8 */
/* @0x295708 orr r3, r3, lr, lsl #8 */
/* @0x29570c bl 0xb6550 <sprintf@plt> */
/* @0x295710 mov r0, r4 */
/* @0x295714 mov r1, r10 */
/* @0x295718 mov r2, r8 */
/* @0x29571c mov r3, sp */
/* @0x295720 mov r12, #10 */
/* @0x295724 str r12, [sp, #0x8] */
/* @0x295728 bl 0xb6e2c <getaddrinfo@plt> */
/* @0x29572c cmp r0, #0 */
/* @0x295730 str r0, [r9] */
/* @0x295734 beq 0x295758 <_ZN8yySocket7ResolveEPc+0x2b0> */
/* @0x295738 mov r0, r6 */
/* @0x29573c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x295740 ldr r0, [sp] */
/* @0x295744 cmp r0, #0 */
/* @0x295748 bne 0x2956cc <_ZN8yySocket7ResolveEPc+0x224> */
/* @0x29574c b 0x2956d0 <_ZN8yySocket7ResolveEPc+0x228> */
/* @0x295750 mov r0, r3 */
/* @0x295754 b 0x2955d8 <_ZN8yySocket7ResolveEPc+0x130> */
/* @0x295758 ldr r3, [sp] */
/* @0x29575c mov r0, r6 */
/* @0x295760 ldr r1, [r3, #0x18] */
/* @0x295764 ldr r2, [r3, #0x10] */
/* @0x295768 bl 0xb65bc <memcpy@plt> */
/* @0x29576c ldr r0, [sp] */
/* @0x295770 b 0x2955d8 <_ZN8yySocket7ResolveEPc+0x130> */
/* @0x295774 ldr r3, [sp, #0x4] */
/* @0x295778 mov r0, r6 */
/* @0x29577c ldr r1, [r3, #0x18] */
/* @0x295780 ldr r2, [r3, #0x10] */
/* @0x295784 bl 0xb65bc <memcpy@plt> */
/* @0x295788 mov r0, r6 */
/* @0x29578c b 0x2955e0 <_ZN8yySocket7ResolveEPc+0x138> */
/* @0x295790 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x295794 mulseq r5, r4, r7 */
/* @0x295798 .word 0xffffbd00 */
/* @0x29579c andeq r11, r9, r8, asr #22 */
/* @0x2957a0 andeq r1, r11, r4, lsl #2 */
/* @0x2957a4 andeq r3, r12, r4, asr sp */
/* @0x2957a8 .word 0xfffffd40 */
/* @0x2957ac andeq r11, r9, r8, lsr #20 */
/* @0x2957b0 andeq r0, r11, r8, ror #31 */
/* @0x2957b4 andeq r3, r12, r8, lsr r12 */
/* @0x2957b8 andeq r3, r12, r0, ror #23 */
/* @0x2957bc andeq r3, r12, r12, lsl #23 */

/* ── FUNC 0x2957c0 · yySocket::ResolveToString(char*) · size=152 · insn=38 */
/* @0x2957c0 push {r3, r4, r5, lr} */
/* @0x2957c4 mov r4, r0 */
/* @0x2957c8 bl 0x297000 <_ZN8yySocket10DetectIPv6Ev> */
/* @0x2957cc cmp r0, #0 */
/* @0x2957d0 mov r0, r4 */
/* @0x2957d4 beq 0x295824 <_ZN8yySocket15ResolveToStringEPc+0x64> */
/* @0x2957d8 bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x2957dc subs r5, r0, #0 */
/* @0x2957e0 beq 0x295840 <_ZN8yySocket15ResolveToStringEPc+0x80> */
/* @0x2957e4 ldr r1, [pc, #0x68] */
/* @0x2957e8 mov r2, #624 */
/* @0x2957ec mov r3, #1 */
/* @0x2957f0 mov r0, #64 */
/* @0x2957f4 add r1, pc, r1 */
/* @0x2957f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2957fc add r1, r5, #8 */
/* @0x295800 mov r3, #64 */
/* @0x295804 mov r4, r0 */
/* @0x295808 mov r2, r0 */
/* @0x29580c mov r0, #10 */
/* @0x295810 bl 0xb6e08 <inet_ntop@plt> */
/* @0x295814 subs r5, r0, #0 */
/* @0x295818 mov r0, r4 */
/* @0x29581c beq 0x295848 <_ZN8yySocket15ResolveToStringEPc+0x88> */
/* @0x295820 pop {r3, r4, r5, pc} */
/* @0x295824 bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x295828 cmp r0, #0 */
/* @0x29582c beq 0x295840 <_ZN8yySocket15ResolveToStringEPc+0x80> */
/* @0x295830 ldr r0, [r0, #0x4] */
/* @0x295834 bl 0xb6e14 <inet_ntoa@plt> */
/* @0x295838 pop {r3, r4, r5, lr} */
/* @0x29583c b 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x295840 mov r0, #0 */
/* @0x295844 pop {r3, r4, r5, pc} */
/* @0x295848 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29584c mov r0, r5 */
/* @0x295850 pop {r3, r4, r5, pc} */
/* @0x295854 strheq r3, [r12], -r4 */

/* ── FUNC 0x295858 · yySocket::Connect(char*, int) · size=880 · insn=220 */
/* @0x295858 ldrb r3, [r0, #0xc4] */
/* @0x29585c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x295860 cmp r3, #0 */
/* @0x295864 ldr r6, [pc, #0x334] */
/* @0x295868 mov r4, r0 */
/* @0x29586c sub sp, sp, #156 */
/* @0x295870 str r2, [r4, #0xac] */
/* @0x295874 mov r7, r2 */
/* @0x295878 mov r0, r1 */
/* @0x29587c add r6, pc, r6 */
/* @0x295880 beq 0x295914 <_ZN8yySocket7ConnectEPci+0xbc> */
/* @0x295884 bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x295888 subs r5, r0, #0 */
/* @0x29588c beq 0x295af0 <_ZN8yySocket7ConnectEPci+0x298> */
/* @0x295890 rev16 r7, r7 */
/* @0x295894 ldr r0, [pc, #0x308] */
/* @0x295898 add r8, r4, #108 */
/* @0x29589c strh r7, [r5, #2] */
/* @0x2958a0 add r0, pc, r0 */
/* @0x2958a4 bl 0xb6e50 <if_nametoindex@plt> */
/* @0x2958a8 mov r2, r8 */
/* @0x2958ac add r1, r5, #8 */
/* @0x2958b0 mov r3, #64 */
/* @0x2958b4 str r0, [r5, #0x18] */
/* @0x2958b8 mov r0, #10 */
/* @0x2958bc bl 0xb6e08 <inet_ntop@plt> */
/* @0x2958c0 cmp r0, #0 */
/* @0x2958c4 moveq r8, #28 */
/* @0x2958c8 beq 0x295948 <_ZN8yySocket7ConnectEPci+0xf0> */
/* @0x2958cc ldr r0, [pc, #0x2d4] */
/* @0x2958d0 mov r1, r8 */
/* @0x2958d4 mov r8, #28 */
/* @0x2958d8 add r0, pc, r0 */
/* @0x2958dc bl 0xb6964 <printf@plt> */
/* @0x2958e0 ldr r0, [r4] */
/* @0x2958e4 cmn r0, #1 */
/* @0x2958e8 bne 0x295954 <_ZN8yySocket7ConnectEPci+0xfc> */
/* @0x2958ec ldrb r0, [r4, #0xc4] */
/* @0x2958f0 mov r1, #1 */
/* @0x2958f4 mov r2, #6 */
/* @0x2958f8 cmp r0, #0 */
/* @0x2958fc moveq r0, #2 */
/* @0x295900 movne r0, #10 */
/* @0x295904 bl 0xb6da8 <socket@plt> */
/* @0x295908 mov r3, r0 */
/* @0x29590c str r3, [r4] */
/* @0x295910 b 0x295954 <_ZN8yySocket7ConnectEPci+0xfc> */
/* @0x295914 bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x295918 subs r5, r0, #0 */
/* @0x29591c beq 0x295af0 <_ZN8yySocket7ConnectEPci+0x298> */
/* @0x295920 mov r3, r7 */
/* @0x295924 rev16 r3, r3 */
/* @0x295928 strh r3, [r5, #2] */
/* @0x29592c mov r8, #16 */
/* @0x295930 ldr r0, [r5, #0x4] */
/* @0x295934 bl 0xb6e14 <inet_ntoa@plt> */
/* @0x295938 mov r1, r0 */
/* @0x29593c add r0, r4, #108 */
/* @0x295940 bl 0xb65a4 <strcpy@plt> */
/* @0x295944 str r7, [r4, #0xac] */
/* @0x295948 ldr r0, [r4] */
/* @0x29594c cmn r0, #1 */
/* @0x295950 beq 0x2958ec <_ZN8yySocket7ConnectEPci+0x94> */
/* @0x295954 mov r1, #3 */
/* @0x295958 mov r2, #0 */
/* @0x29595c bl 0xb6e5c <fcntl@plt> */
/* @0x295960 mov r1, #4 */
/* @0x295964 orr r2, r0, #2048 */
/* @0x295968 mov r9, r0 */
/* @0x29596c ldr r0, [r4] */
/* @0x295970 bl 0xb6e5c <fcntl@plt> */
/* @0x295974 mov r2, r8 */
/* @0x295978 ldr r0, [r4] */
/* @0x29597c mov r1, r5 */
/* @0x295980 bl 0xb6e68 <connect@plt> */
/* @0x295984 ldr r3, [pc, #0x220] */
/* @0x295988 ldr r7, [r6, r3] */
/* @0x29598c cmn r0, #1 */
/* @0x295990 mov r8, r0 */
/* @0x295994 str r0, [r7] */
/* @0x295998 beq 0x295b04 <_ZN8yySocket7ConnectEPci+0x2ac> */
/* @0x29599c ldr r3, [pc, #0x20c] */
/* @0x2959a0 ldr r3, [r6, r3] */
/* @0x2959a4 ldrb r8, [r3] */
/* @0x2959a8 cmp r8, #0 */
/* @0x2959ac bne 0x295a84 <_ZN8yySocket7ConnectEPci+0x22c> */
/* @0x2959b0 add r10, sp, #24 */
/* @0x2959b4 mov r1, r8 */
/* @0x2959b8 mov r2, #128 */
/* @0x2959bc mov r11, #1 */
/* @0x2959c0 mov r0, r10 */
/* @0x2959c4 bl 0xb65b0 <memset@plt> */
/* @0x2959c8 ldr r0, [r4] */
/* @0x2959cc mov r1, r8 */
/* @0x2959d0 movw lr, #0x4dd3 */
/* @0x2959d4 and r2, r0, #31 */
/* @0x2959d8 movt lr, #0x1062 */
/* @0x2959dc asr r3, r0, #5 */
/* @0x2959e0 lsl r11, r11, r2 */
/* @0x2959e4 add r2, sp, #152 */
/* @0x2959e8 mov r12, #1000 */
/* @0x2959ec add r3, r2, r3, lsl #2 */
/* @0x2959f0 mov r2, r10 */
/* @0x2959f4 add r10, sp, #16 */
/* @0x2959f8 add r0, r0, #1 */
/* @0x2959fc str r11, [r3, #-0x80] */
/* @0x295a00 mov r3, r8 */
/* @0x295a04 ldr r8, [pc, #0x1a8] */
/* @0x295a08 ldr r8, [r6, r8] */
/* @0x295a0c str r10, [sp] */
/* @0x295a10 ldr r8, [r8] */
/* @0x295a14 smull r10, lr, lr, r8 */
/* @0x295a18 asr r10, r8, #31 */
/* @0x295a1c rsb lr, r10, lr, asr #6 */
/* @0x295a20 str lr, [sp, #0x10] */
/* @0x295a24 mls lr, r12, lr, r8 */
/* @0x295a28 mul r12, r12, lr */
/* @0x295a2c str r12, [sp, #0x14] */
/* @0x295a30 bl 0xb6d84 <select@plt> */
/* @0x295a34 cmp r0, #1 */
/* @0x295a38 mov r12, r0 */
/* @0x295a3c beq 0x295b60 <_ZN8yySocket7ConnectEPci+0x308> */
/* @0x295a40 cmp r0, #0 */
/* @0x295a44 ldr r3, [pc, #0x16c] */
/* @0x295a48 bne 0x295aa8 <_ZN8yySocket7ConnectEPci+0x250> */
/* @0x295a4c ldr r3, [r6, r3] */
/* @0x295a50 ldr r1, [pc, #0x164] */
/* @0x295a54 ldr r0, [r3] */
/* @0x295a58 add r1, pc, r1 */
/* @0x295a5c ldr r3, [r0] */
/* @0x295a60 ldr r3, [r3, #0xc] */
/* @0x295a64 blx r3 */
/* @0x295a68 ldr r0, [r4] */
/* @0x295a6c bl 0xb6d78 <close@plt> */
/* @0x295a70 mvn r2, #0 */
/* @0x295a74 mvn r3, #4 */
/* @0x295a78 str r2, [r4] */
/* @0x295a7c str r3, [r7] */
/* @0x295a80 b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c> */
/* @0x295a84 mov r3, #1 */
/* @0x295a88 strb r3, [r4, #0x2d] */
/* @0x295a8c bl 0x215148 <Timing_Time> */
/* @0x295a90 strd r0, r1, [r4, #64] */
/* @0x295a94 mov r0, r5 */
/* @0x295a98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x295a9c ldr r0, [r7] */
/* @0x295aa0 add sp, sp, #156 */
/* @0x295aa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x295aa8 ldr r3, [r6, r3] */
/* @0x295aac ldr r6, [r3] */
/* @0x295ab0 ldr r3, [r6] */
/* @0x295ab4 ldr r8, [r3, #0xc] */
/* @0x295ab8 bl 0xb6bf8 <__errno@plt> */
/* @0x295abc ldr r1, [pc, #0xfc] */
/* @0x295ac0 add r1, pc, r1 */
/* @0x295ac4 mov r3, r0 */
/* @0x295ac8 mov r0, r6 */
/* @0x295acc ldr r2, [r3] */
/* @0x295ad0 blx r8 */
/* @0x295ad4 ldr r0, [r4] */
/* @0x295ad8 bl 0xb6d78 <close@plt> */
/* @0x295adc mvn r2, #0 */
/* @0x295ae0 mvn r3, #5 */
/* @0x295ae4 str r2, [r4] */
/* @0x295ae8 str r3, [r7] */
/* @0x295aec b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c> */
/* @0x295af0 ldr r3, [pc, #0xb4] */
/* @0x295af4 ldr r3, [r6, r3] */
/* @0x295af8 ldr r0, [r3] */
/* @0x295afc add sp, sp, #156 */
/* @0x295b00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x295b04 bl 0xb6bf8 <__errno@plt> */
/* @0x295b08 ldr r3, [r0] */
/* @0x295b0c cmp r3, #115 */
/* @0x295b10 beq 0x295b54 <_ZN8yySocket7ConnectEPci+0x2fc> */
/* @0x295b14 ldr r3, [pc, #0x9c] */
/* @0x295b18 ldr r3, [r6, r3] */
/* @0x295b1c ldr r6, [r3] */
/* @0x295b20 ldr r3, [r6] */
/* @0x295b24 ldr r9, [r3, #0xc] */
/* @0x295b28 bl 0xb6bf8 <__errno@plt> */
/* @0x295b2c ldr r1, [pc, #0x90] */
/* @0x295b30 add r1, pc, r1 */
/* @0x295b34 mov r3, r0 */
/* @0x295b38 mov r0, r6 */
/* @0x295b3c ldr r2, [r3] */
/* @0x295b40 blx r9 */
/* @0x295b44 ldr r0, [r4] */
/* @0x295b48 bl 0xb6d78 <close@plt> */
/* @0x295b4c str r8, [r4] */
/* @0x295b50 b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c> */
/* @0x295b54 mov r3, #0 */
/* @0x295b58 str r3, [r7] */
/* @0x295b5c b 0x29599c <_ZN8yySocket7ConnectEPci+0x144> */
/* @0x295b60 ldr r0, [r4] */
/* @0x295b64 add r3, sp, #12 */
/* @0x295b68 mov r1, r12 */
/* @0x295b6c str r3, [sp] */
/* @0x295b70 mov r2, #4 */
/* @0x295b74 add r3, sp, #11 */
/* @0x295b78 str r12, [sp, #0xc] */
/* @0x295b7c bl 0xb6d90 <getsockopt@plt> */
/* @0x295b80 ldrb r3, [sp, #0xb] */
/* @0x295b84 cmp r3, #0 */
/* @0x295b88 bne 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c> */
/* @0x295b8c ldr r0, [r4] */
/* @0x295b90 mov r2, r9 */
/* @0x295b94 mov r1, #4 */
/* @0x295b98 bl 0xb6e5c <fcntl@plt> */
/* @0x295b9c b 0x295a94 <_ZN8yySocket7ConnectEPci+0x23c> */
/* @0x295ba0 ldrsbeq r12, [r5], -r4 */
/* @0x295ba4 andeq r3, r12, r8, asr #20 */
/* @0x295ba8 andeq r3, r12, r4, lsl r10 */
/* @0x295bac .word 0xfffffd40 */
/* @0x295bb0 .word 0xfffffd44 */
/* @0x295bb4 .word 0xfffffd3c */
/* @0x295bb8 .word 0xffffbac4 */
/* @0x295bbc andeq r3, r12, r8, asr #17 */
/* @0x295bc0 andeq r3, r12, r12, ror r8 */
/* @0x295bc4 ldrdeq r3, r4, [r12], -r4 */

/* ── FUNC 0x295bc8 · yySocket::Broadcast(int, unsigned char*, int) · size=864 · insn=216 */
/* @0x295bc8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x295bcc mov r4, r0 */
/* @0x295bd0 ldr r5, [pc, #0x328] */
/* @0x295bd4 mov r7, r3 */
/* @0x295bd8 ldr r0, [pc, #0x324] */
/* @0x295bdc sub sp, sp, #60 */
/* @0x295be0 add r5, pc, r5 */
/* @0x295be4 ldrb lr, [r4, #0xc4] */
/* @0x295be8 mov r9, r1 */
/* @0x295bec mov r8, r2 */
/* @0x295bf0 ldr r6, [r5, r0] */
/* @0x295bf4 cmp lr, #0 */
/* @0x295bf8 ldr r3, [r6] */
/* @0x295bfc str r3, [sp, #0x34] */
/* @0x295c00 bne 0x295c8c <_ZN8yySocket9BroadcastEiPhi+0xc4> */
/* @0x295c04 ldr r0, [r4, #0x4] */
/* @0x295c08 cmn r0, #1 */
/* @0x295c0c beq 0x295d24 <_ZN8yySocket9BroadcastEiPhi+0x15c> */
/* @0x295c10 mov r3, #0 */
/* @0x295c14 mov r2, #2 */
/* @0x295c18 mov r12, r9 */
/* @0x295c1c str r3, [sp, #0x20] */
/* @0x295c20 str r3, [sp, #0x24] */
/* @0x295c24 strh r2, [sp, #24] */
/* @0x295c28 rev16 r12, r12 */
/* @0x295c2c mov r2, #16 */
/* @0x295c30 add r1, sp, #24 */
/* @0x295c34 str r2, [sp, #0x4] */
/* @0x295c38 mov r2, r7 */
/* @0x295c3c str r1, [sp] */
/* @0x295c40 mov r1, r8 */
/* @0x295c44 strh r12, [sp, #26] */
/* @0x295c48 mvn r12, #0 */
/* @0x295c4c str r12, [sp, #0x1c] */
/* @0x295c50 bl 0xb6e74 <sendto@plt> */
/* @0x295c54 cmp r0, #0 */
/* @0x295c58 blt 0x295c84 <_ZN8yySocket9BroadcastEiPhi+0xbc> */
/* @0x295c5c cmp r7, r0 */
/* @0x295c60 mvngt r12, #2 */
/* @0x295c64 movle r12, #0 */
/* @0x295c68 ldr r2, [sp, #0x34] */
/* @0x295c6c mov r0, r12 */
/* @0x295c70 ldr r3, [r6] */
/* @0x295c74 cmp r2, r3 */
/* @0x295c78 bne 0x295efc <_ZN8yySocket9BroadcastEiPhi+0x334> */
/* @0x295c7c add sp, sp, #60 */
/* @0x295c80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x295c84 mvn r12, #1 */
/* @0x295c88 b 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0> */
/* @0x295c8c ldr r0, [pc, #0x274] */
/* @0x295c90 add r0, pc, r0 */
/* @0x295c94 bl 0xb6e50 <if_nametoindex@plt> */
/* @0x295c98 ldr r3, [r4, #0x4] */
/* @0x295c9c cmn r3, #1 */
/* @0x295ca0 addne r10, sp, #24 */
/* @0x295ca4 str r0, [sp, #0x10] */
/* @0x295ca8 movne r3, r0 */
/* @0x295cac beq 0x295d70 <_ZN8yySocket9BroadcastEiPhi+0x1a8> */
/* @0x295cb0 mov r5, #0 */
/* @0x295cb4 mov r0, #10 */
/* @0x295cb8 str r5, [sp, #0x1c] */
/* @0x295cbc str r5, [sp, #0x20] */
/* @0x295cc0 str r5, [sp, #0x24] */
/* @0x295cc4 str r5, [sp, #0x28] */
/* @0x295cc8 str r5, [sp, #0x2c] */
/* @0x295ccc strh r0, [sp, #24] */
/* @0x295cd0 rev16 r9, r9 */
/* @0x295cd4 ldr r1, [pc, #0x230] */
/* @0x295cd8 add r2, sp, #32 */
/* @0x295cdc str r3, [sp, #0x30] */
/* @0x295ce0 add r1, pc, r1 */
/* @0x295ce4 strh r9, [sp, #26] */
/* @0x295ce8 bl 0xb6dc0 <inet_pton@plt> */
/* @0x295cec ldr r0, [r4, #0x4] */
/* @0x295cf0 mov r12, #28 */
/* @0x295cf4 mov r1, r8 */
/* @0x295cf8 str r10, [sp] */
/* @0x295cfc mov r3, r5 */
/* @0x295d00 mov r2, r7 */
/* @0x295d04 str r12, [sp, #0x4] */
/* @0x295d08 bl 0xb6e74 <sendto@plt> */
/* @0x295d0c cmp r0, #0 */
/* @0x295d10 blt 0x295c84 <_ZN8yySocket9BroadcastEiPhi+0xbc> */
/* @0x295d14 cmp r7, r0 */
/* @0x295d18 mvngt r12, #2 */
/* @0x295d1c movle r12, r5 */
/* @0x295d20 b 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0> */
/* @0x295d24 mov r0, #2 */
/* @0x295d28 mov r2, lr */
/* @0x295d2c mov r1, r0 */
/* @0x295d30 bl 0xb6da8 <socket@plt> */
/* @0x295d34 cmn r0, #1 */
/* @0x295d38 mov r12, r0 */
/* @0x295d3c str r0, [r4, #0x4] */
/* @0x295d40 beq 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0> */
/* @0x295d44 add r3, sp, #56 */
/* @0x295d48 mov r1, #1 */
/* @0x295d4c mov r12, #4 */
/* @0x295d50 mov r2, #6 */
/* @0x295d54 str r1, [r3, #-0x24]! */
/* @0x295d58 str r12, [sp] */
/* @0x295d5c bl 0xb6d9c <setsockopt@plt> */
/* @0x295d60 cmp r0, #0 */
/* @0x295d64 blt 0x295e34 <_ZN8yySocket9BroadcastEiPhi+0x26c> */
/* @0x295d68 ldr r0, [r4, #0x4] */
/* @0x295d6c b 0x295c10 <_ZN8yySocket9BroadcastEiPhi+0x48> */
/* @0x295d70 mov r0, #10 */
/* @0x295d74 mov r1, #2 */
/* @0x295d78 mov r2, #0 */
/* @0x295d7c bl 0xb6da8 <socket@plt> */
/* @0x295d80 cmn r0, #1 */
/* @0x295d84 mov r12, r0 */
/* @0x295d88 str r0, [r4, #0x4] */
/* @0x295d8c beq 0x295c68 <_ZN8yySocket9BroadcastEiPhi+0xa0> */
/* @0x295d90 add r3, sp, #56 */
/* @0x295d94 mov r1, #0 */
/* @0x295d98 mov r2, #4 */
/* @0x295d9c str r1, [r3, #-0x24]! */
/* @0x295da0 mov r1, #41 */
/* @0x295da4 str r2, [sp] */
/* @0x295da8 mov r2, #26 */
/* @0x295dac bl 0xb6d9c <setsockopt@plt> */
/* @0x295db0 cmp r0, #0 */
/* @0x295db4 blt 0x295ec8 <_ZN8yySocket9BroadcastEiPhi+0x300> */
/* @0x295db8 add r10, sp, #24 */
/* @0x295dbc ldr r1, [pc, #0x14c] */
/* @0x295dc0 mov r0, #10 */
/* @0x295dc4 mov r3, #0 */
/* @0x295dc8 add r1, pc, r1 */
/* @0x295dcc mov r2, r10 */
/* @0x295dd0 str r3, [sp, #0x18] */
/* @0x295dd4 str r3, [sp, #0x1c] */
/* @0x295dd8 str r3, [sp, #0x20] */
/* @0x295ddc str r3, [sp, #0x24] */
/* @0x295de0 str r3, [sp, #0x28] */
/* @0x295de4 bl 0xb6dc0 <inet_pton@plt> */
/* @0x295de8 ldr r0, [r4, #0x4] */
/* @0x295dec mov r2, #20 */
/* @0x295df0 mov r3, r10 */
/* @0x295df4 str r2, [sp] */
/* @0x295df8 mov r1, #41 */
/* @0x295dfc bl 0xb6d9c <setsockopt@plt> */
/* @0x295e00 cmp r0, #0 */
/* @0x295e04 blt 0x295e8c <_ZN8yySocket9BroadcastEiPhi+0x2c4> */
/* @0x295e08 ldr r0, [r4, #0x4] */
/* @0x295e0c mov r3, #4 */
/* @0x295e10 mov r1, #41 */
/* @0x295e14 str r3, [sp] */
/* @0x295e18 mov r2, #17 */
/* @0x295e1c add r3, sp, #16 */
/* @0x295e20 bl 0xb6d9c <setsockopt@plt> */
/* @0x295e24 cmp r0, #0 */
/* @0x295e28 blt 0x295e58 <_ZN8yySocket9BroadcastEiPhi+0x290> */
/* @0x295e2c ldr r3, [sp, #0x10] */
/* @0x295e30 b 0x295cb0 <_ZN8yySocket9BroadcastEiPhi+0xe8> */
/* @0x295e34 ldr r3, [pc, #0xd8] */
/* @0x295e38 ldr r1, [pc, #0xd8] */
/* @0x295e3c ldr r3, [r5, r3] */
/* @0x295e40 add r1, pc, r1 */
/* @0x295e44 ldr r0, [r3] */
/* @0x295e48 ldr r3, [r0] */
/* @0x295e4c ldr r3, [r3, #0xc] */
/* @0x295e50 blx r3 */
/* @0x295e54 b 0x295d68 <_ZN8yySocket9BroadcastEiPhi+0x1a0> */
/* @0x295e58 ldr r3, [pc, #0xb4] */
/* @0x295e5c ldr r3, [r5, r3] */
/* @0x295e60 ldr r5, [r3] */
/* @0x295e64 ldr r3, [r5] */
/* @0x295e68 ldr r11, [r3, #0xc] */
/* @0x295e6c bl 0xb6bf8 <__errno@plt> */
/* @0x295e70 ldr r1, [pc, #0xa4] */
/* @0x295e74 add r1, pc, r1 */
/* @0x295e78 mov r3, r0 */
/* @0x295e7c mov r0, r5 */
/* @0x295e80 ldr r2, [r3] */
/* @0x295e84 blx r11 */
/* @0x295e88 b 0x295e2c <_ZN8yySocket9BroadcastEiPhi+0x264> */
/* @0x295e8c ldr r3, [pc, #0x80] */
/* @0x295e90 ldr r3, [r5, r3] */
/* @0x295e94 ldr r11, [r3] */
/* @0x295e98 ldr r3, [r11] */
/* @0x295e9c ldr r3, [r3, #0xc] */
/* @0x295ea0 str r3, [sp, #0xc] */
/* @0x295ea4 bl 0xb6bf8 <__errno@plt> */
/* @0x295ea8 ldr r1, [pc, #0x70] */
/* @0x295eac ldr r3, [sp, #0xc] */
/* @0x295eb0 add r1, pc, r1 */
/* @0x295eb4 mov r2, r0 */
/* @0x295eb8 mov r0, r11 */
/* @0x295ebc ldr r2, [r2] */
/* @0x295ec0 blx r3 */
/* @0x295ec4 b 0x295e08 <_ZN8yySocket9BroadcastEiPhi+0x240> */
/* @0x295ec8 ldr r3, [pc, #0x44] */
/* @0x295ecc ldr r3, [r5, r3] */
/* @0x295ed0 ldr r10, [r3] */
/* @0x295ed4 ldr r3, [r10] */
/* @0x295ed8 ldr r11, [r3, #0xc] */
/* @0x295edc bl 0xb6bf8 <__errno@plt> */
/* @0x295ee0 ldr r1, [pc, #0x3c] */
/* @0x295ee4 add r1, pc, r1 */
/* @0x295ee8 mov r3, r0 */
/* @0x295eec mov r0, r10 */
/* @0x295ef0 ldr r2, [r3] */
/* @0x295ef4 blx r11 */
/* @0x295ef8 b 0x295db8 <_ZN8yySocket9BroadcastEiPhi+0x1f0> */
/* @0x295efc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x295f00 andseq r12, r5, r0, ror r0 */
/* @0x295f04 .word 0xffffbd00 */
/* @0x295f08 andeq r3, r12, r8, asr r6 */
/* @0x295f0c andeq r3, r12, r8, ror #9 */
/* @0x295f10 andeq r3, r12, r0, lsl #8 */
/* @0x295f14 .word 0xffffbac4 */
/* @0x295f18 andeq r3, r12, r4, lsl #11 */
/* @0x295f1c andeq r3, r12, r8, lsr #10 */
/* @0x295f20 andeq r3, r12, r8, asr #9 */
/* @0x295f24 andeq r3, r12, r4, ror r4 */

/* ── FUNC 0x295f28 · yySocket::SendTo(char*, int, unsigned char*, int) · size=196 · insn=49 */
/* @0x295f28 push {r4, r5, r6, r7, lr} */
/* @0x295f2c mov r4, r0 */
/* @0x295f30 ldrb r12, [r4, #0xc4] */
/* @0x295f34 sub sp, sp, #12 */
/* @0x295f38 mov r0, r1 */
/* @0x295f3c mov r6, r2 */
/* @0x295f40 cmp r12, #0 */
/* @0x295f44 mov r7, r3 */
/* @0x295f48 ldr r5, [sp, #0x20] */
/* @0x295f4c beq 0x295f6c <_ZN8yySocket6SendToEPciPhi+0x44> */
/* @0x295f50 bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x295f54 subs r12, r0, #0 */
/* @0x295f58 beq 0x295fcc <_ZN8yySocket6SendToEPciPhi+0xa4> */
/* @0x295f5c rev16 r6, r6 */
/* @0x295f60 mov r3, #28 */
/* @0x295f64 strh r6, [r12, #2] */
/* @0x295f68 b 0x295f84 <_ZN8yySocket6SendToEPciPhi+0x5c> */
/* @0x295f6c bl 0x2954a8 <_ZN8yySocket7ResolveEPc> */
/* @0x295f70 subs r12, r0, #0 */
/* @0x295f74 beq 0x295fbc <_ZN8yySocket6SendToEPciPhi+0x94> */
/* @0x295f78 rev16 r6, r6 */
/* @0x295f7c mov r3, #16 */
/* @0x295f80 strh r6, [r12, #2] */
/* @0x295f84 ldr r0, [r4] */
/* @0x295f88 mov r1, r7 */
/* @0x295f8c str r3, [sp, #0x4] */
/* @0x295f90 mov r2, r5 */
/* @0x295f94 str r12, [sp] */
/* @0x295f98 mov r3, #0 */
/* @0x295f9c bl 0xb6e74 <sendto@plt> */
/* @0x295fa0 cmp r0, #0 */
/* @0x295fa4 blt 0x295fdc <_ZN8yySocket6SendToEPciPhi+0xb4> */
/* @0x295fa8 cmp r5, r0 */
/* @0x295fac movle r0, #0 */
/* @0x295fb0 mvngt r0, #2 */
/* @0x295fb4 add sp, sp, #12 */
/* @0x295fb8 pop {r4, r5, r6, r7, pc} */
/* @0x295fbc ldr r3, [pc, #0x20] */
/* @0x295fc0 ldr r3, [pc, r3] */
/* @0x295fc4 ldr r0, [r3] */
/* @0x295fc8 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c> */
/* @0x295fcc ldr r3, [pc, #0x14] */
/* @0x295fd0 ldr r3, [pc, r3] */
/* @0x295fd4 ldr r0, [r3] */
/* @0x295fd8 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c> */
/* @0x295fdc mvn r0, #1 */
/* @0x295fe0 b 0x295fb4 <_ZN8yySocket6SendToEPciPhi+0x8c> */
/* @0x295fe4 ldrsbeq r11, [r5], -r0 */
/* @0x295fe8 andseq r11, r5, r0, asr #19 */

/* ── FUNC 0x295fec · yySocket::CreateSocket() · size=88 · insn=22 */
/* @0x295fec ldr r3, [r0, #0x8] */
/* @0x295ff0 push {r4, lr} */
/* @0x295ff4 cmp r3, #1 */
/* @0x295ff8 mov r4, r0 */
/* @0x295ffc ldrb r0, [r0, #0xc4] */
/* @0x296000 beq 0x296024 <_ZN8yySocket12CreateSocketEv+0x38> */
/* @0x296004 cmp r0, #0 */
/* @0x296008 mov r1, #1 */
/* @0x29600c mov r2, #6 */
/* @0x296010 moveq r0, #2 */
/* @0x296014 movne r0, #10 */
/* @0x296018 bl 0xb6da8 <socket@plt> */
/* @0x29601c str r0, [r4] */
/* @0x296020 pop {r4, pc} */
/* @0x296024 cmp r0, #0 */
/* @0x296028 mov r1, #2 */
/* @0x29602c mov r2, #17 */
/* @0x296030 moveq r0, r1 */
/* @0x296034 movne r0, #10 */
/* @0x296038 bl 0xb6da8 <socket@plt> */
/* @0x29603c str r0, [r4] */
/* @0x296040 pop {r4, pc} */

/* ── FUNC 0x296044 · yySocket::CommonDestructor() · size=60 · insn=15 */
/* @0x296044 push {r4, lr} */
/* @0x296048 mov r4, r0 */
/* @0x29604c ldr r0, [r0, #0x50] */
/* @0x296050 cmp r0, #0 */
/* @0x296054 beq 0x296064 <_ZN8yySocket16CommonDestructorEv+0x20> */
/* @0x296058 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x29605c mov r3, #0 */
/* @0x296060 str r3, [r4, #0x50] */
/* @0x296064 ldr r0, [r4, #0x60] */
/* @0x296068 cmp r0, #0 */
/* @0x29606c popeq {r4, pc} */
/* @0x296070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x296074 mov r3, #0 */
/* @0x296078 str r3, [r4, #0x60] */
/* @0x29607c pop {r4, pc} */

/* ── FUNC 0x296080 · yySocket::AllocateBuffer(int) · size=52 · insn=13 */
/* @0x296080 push {r3, r4, r5, lr} */
/* @0x296084 mov r5, r1 */
/* @0x296088 ldr r1, [pc, #0x20] */
/* @0x29608c mov r4, r0 */
/* @0x296090 mov r2, #190 */
/* @0x296094 mov r0, r5 */
/* @0x296098 add r1, pc, r1 */
/* @0x29609c mov r3, #1 */
/* @0x2960a0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x2960a4 str r5, [r4, #0x54] */
/* @0x2960a8 str r0, [r4, #0x50] */
/* @0x2960ac pop {r3, r4, r5, pc} */
/* @0x2960b0 andeq r3, r12, r8, asr #6 */

/* ── FUNC 0x2960b4 · yySocket::ReadDataStream(int) · size=224 · insn=56 */
/* @0x2960b4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x2960b8 mov r5, r0 */
/* @0x2960bc ldr r6, [r0, #0x50] */
/* @0x2960c0 sub sp, sp, #12 */
/* @0x2960c4 mov r7, r1 */
/* @0x2960c8 cmp r6, #0 */
/* @0x2960cc beq 0x296184 <_ZN8yySocket14ReadDataStreamEi+0xd0> */
/* @0x2960d0 ldr r8, [pc, #0xb8] */
/* @0x2960d4 mov r9, #0 */
/* @0x2960d8 ldr r4, [r0, #0x54] */
/* @0x2960dc add r8, pc, r8 */
/* @0x2960e0 b 0x296118 <_ZN8yySocket14ReadDataStreamEi+0x64> */
/* @0x2960e4 cmp r7, r4 */
/* @0x2960e8 movlt r2, r7 */
/* @0x2960ec movge r2, r4 */
/* @0x2960f0 mov r0, r5 */
/* @0x2960f4 mov r1, r6 */
/* @0x2960f8 mov r3, #0 */
/* @0x2960fc bl 0x2952dc <_ZN8yySocket4ReadEPvjj> */
/* @0x296100 cmp r0, #0 */
/* @0x296104 rsb r4, r0, r4 */
/* @0x296108 ble 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0> */
/* @0x29610c cmp r0, r7 */
/* @0x296110 add r6, r6, r0 */
/* @0x296114 beq 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0> */
/* @0x296118 mov r0, r5 */
/* @0x29611c bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x296120 cmp r0, #0 */
/* @0x296124 ble 0x296174 <_ZN8yySocket14ReadDataStreamEi+0xc0> */
/* @0x296128 cmp r4, r0 */
/* @0x29612c bge 0x2960e4 <_ZN8yySocket14ReadDataStreamEi+0x30> */
/* @0x296130 rsb r1, r4, r0 */
/* @0x296134 ldr r4, [r5, #0x50] */
/* @0x296138 ldr r3, [r5, #0x54] */
/* @0x29613c add r1, r1, #16384 */
/* @0x296140 str r9, [sp] */
/* @0x296144 mov r2, r8 */
/* @0x296148 add r1, r1, r3 */
/* @0x29614c mov r0, r4 */
/* @0x296150 mov r3, #74 */
/* @0x296154 str r1, [r5, #0x54] */
/* @0x296158 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x29615c ldr r3, [r5, #0x54] */
/* @0x296160 rsb r4, r4, r6 */
/* @0x296164 add r6, r0, r4 */
/* @0x296168 str r0, [r5, #0x50] */
/* @0x29616c rsb r4, r4, r3 */
/* @0x296170 b 0x2960e4 <_ZN8yySocket14ReadDataStreamEi+0x30> */
/* @0x296174 ldr r0, [r5, #0x50] */
/* @0x296178 rsb r0, r0, r6 */
/* @0x29617c add sp, sp, #12 */
/* @0x296180 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x296184 mov r0, r6 */
/* @0x296188 add sp, sp, #12 */
/* @0x29618c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x296190 andeq r10, r9, r4, asr pc */

/* ── FUNC 0x296194 · yySocket::ReadMessageHeader() · size=284 · insn=71 */
/* @0x296194 push {r4, lr} */
/* @0x296198 sub sp, sp, #8 */
/* @0x29619c mov r4, r0 */
/* @0x2961a0 bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x2961a4 cmp r0, #0 */
/* @0x2961a8 ble 0x296220 <_ZN8yySocket17ReadMessageHeaderEv+0x8c> */
/* @0x2961ac mov r0, r4 */
/* @0x2961b0 ldr r1, [r4, #0x50] */
/* @0x2961b4 mov r2, #12 */
/* @0x2961b8 mov r3, #0 */
/* @0x2961bc bl 0x2952dc <_ZN8yySocket4ReadEPvjj> */
/* @0x2961c0 cmp r0, #0 */
/* @0x2961c4 blt 0x296220 <_ZN8yySocket17ReadMessageHeaderEv+0x8c> */
/* @0x2961c8 cmp r0, #11 */
/* @0x2961cc ble 0x296230 <_ZN8yySocket17ReadMessageHeaderEv+0x9c> */
/* @0x2961d0 ldr r1, [r4, #0xc0] */
/* @0x2961d4 movw r2, #0xc0de */
/* @0x2961d8 ldr r3, [r4, #0x50] */
/* @0x2961dc movt r2, #0xdead */
/* @0x2961e0 str r0, [r4, #0xc0] */
/* @0x2961e4 add r0, r3, r1 */
/* @0x2961e8 ldr r1, [r3, r1] */
/* @0x2961ec ldr r12, [r0, #0x4] */
/* @0x2961f0 cmp r1, r2 */
/* @0x2961f4 beq 0x29625c <_ZN8yySocket17ReadMessageHeaderEv+0xc8> */
/* @0x2961f8 movw r2, #0xc0de */
/* @0x2961fc movt r2, #0xbe11 */
/* @0x296200 cmp r1, r2 */
/* @0x296204 beq 0x29624c <_ZN8yySocket17ReadMessageHeaderEv+0xb8> */
/* @0x296208 mov r3, #1 */
/* @0x29620c mvn r2, #0 */
/* @0x296210 str r2, [r4, #0xbc] */
/* @0x296214 mov r0, r3 */
/* @0x296218 add sp, sp, #8 */
/* @0x29621c pop {r4, pc} */
/* @0x296220 mov r3, #0 */
/* @0x296224 mov r0, r3 */
/* @0x296228 add sp, sp, #8 */
/* @0x29622c pop {r4, pc} */
/* @0x296230 mov r3, #1 */
/* @0x296234 str r0, [r4, #0xc0] */
/* @0x296238 mvn r2, #0 */
/* @0x29623c mov r0, r3 */
/* @0x296240 str r2, [r4, #0xbc] */
/* @0x296244 add sp, sp, #8 */
/* @0x296248 pop {r4, pc} */
/* @0x29624c cmp r12, #44 */
/* @0x296250 bne 0x296208 <_ZN8yySocket17ReadMessageHeaderEv+0x74> */
/* @0x296254 ldr r1, [r0, #0x8] */
/* @0x296258 b 0x29626c <_ZN8yySocket17ReadMessageHeaderEv+0xd8> */
/* @0x29625c cmp r12, #12 */
/* @0x296260 bne 0x296208 <_ZN8yySocket17ReadMessageHeaderEv+0x74> */
/* @0x296264 ldr r1, [r0, #0x8] */
/* @0x296268 add r1, r1, #12 */
/* @0x29626c ldr r2, [r4, #0x54] */
/* @0x296270 str r1, [r4, #0xbc] */
/* @0x296274 cmp r1, r2 */
/* @0x296278 movle r3, #1 */
/* @0x29627c ble 0x296214 <_ZN8yySocket17ReadMessageHeaderEv+0x80> */
/* @0x296280 ldr r2, [pc, #0x24] */
/* @0x296284 mov r0, r3 */
/* @0x296288 str r1, [r4, #0x54] */
/* @0x29628c mov r12, #0 */
/* @0x296290 mov r3, #74 */
/* @0x296294 add r2, pc, r2 */
/* @0x296298 str r12, [sp] */
/* @0x29629c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2962a0 mov r3, #1 */
/* @0x2962a4 str r0, [r4, #0x50] */
/* @0x2962a8 b 0x296214 <_ZN8yySocket17ReadMessageHeaderEv+0x80> */
/* @0x2962ac muleq r9, r12, sp */

/* ── FUNC 0x2962b0 · yySocket::WaitForData(int, int) · size=112 · insn=28 */
/* @0x2962b0 push {r4, r5, r6, r8, r9, r10, r11, lr} */
/* @0x2962b4 mov r4, r1 */
/* @0x2962b8 mov r11, r0 */
/* @0x2962bc mov r10, r2 */
/* @0x2962c0 bl 0x215148 <Timing_Time> */
/* @0x2962c4 mov r6, #1000 */
/* @0x2962c8 mul r6, r6, r4 */
/* @0x2962cc asr r5, r6, #31 */
/* @0x2962d0 mov r4, r6 */
/* @0x2962d4 mov r8, r0 */
/* @0x2962d8 mov r9, r1 */
/* @0x2962dc mov r0, r11 */
/* @0x2962e0 mov r1, r10 */
/* @0x2962e4 bl 0x2960b4 <_ZN8yySocket14ReadDataStreamEi> */
/* @0x2962e8 subs r6, r0, #0 */
/* @0x2962ec beq 0x2962fc <_ZN8yySocket11WaitForDataEii+0x4c> */
/* @0x2962f0 bl 0x215148 <Timing_Time> */
/* @0x2962f4 mov r0, r6 */
/* @0x2962f8 pop {r4, r5, r6, r8, r9, r10, r11, pc} */
/* @0x2962fc bl 0x298db4 <_Z15PollServersOnlyv> */
/* @0x296300 bl 0x215148 <Timing_Time> */
/* @0x296304 subs r0, r0, r8 */
/* @0x296308 sbc r1, r1, r9 */
/* @0x29630c cmp r4, r0 */
/* @0x296310 sbcs r3, r5, r1 */
/* @0x296314 bge 0x2962dc <_ZN8yySocket11WaitForDataEii+0x2c> */
/* @0x296318 mov r0, r6 */
/* @0x29631c pop {r4, r5, r6, r8, r9, r10, r11, pc} */

/* ── FUNC 0x296320 · yySocket::ProcessGMSHandshake() · size=908 · insn=227 */
/* @0x296320 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x296324 sub sp, sp, #64 */
/* @0x296328 ldr r6, [pc, #0x34c] */
/* @0x29632c mov r8, r0 */
/* @0x296330 ldr r3, [pc, #0x348] */
/* @0x296334 add r6, pc, r6 */
/* @0x296338 ldr r9, [r0, #0x34] */
/* @0x29633c ldr r7, [r6, r3] */
/* @0x296340 cmp r9, #1 */
/* @0x296344 ldr r3, [r7] */
/* @0x296348 str r3, [sp, #0x3c] */
/* @0x29634c beq 0x2964d0 <_ZN8yySocket19ProcessGMSHandshakeEv+0x1b0> */
/* @0x296350 cmp r9, #3 */
/* @0x296354 beq 0x2963c8 <_ZN8yySocket19ProcessGMSHandshakeEv+0xa8> */
/* @0x296358 cmp r9, #0 */
/* @0x29635c beq 0x296380 <_ZN8yySocket19ProcessGMSHandshakeEv+0x60> */
/* @0x296360 mov r9, #1 */
/* @0x296364 ldr r2, [sp, #0x3c] */
/* @0x296368 mov r0, r9 */
/* @0x29636c ldr r3, [r7] */
/* @0x296370 cmp r2, r3 */
/* @0x296374 bne 0x296678 <_ZN8yySocket19ProcessGMSHandshakeEv+0x358> */
/* @0x296378 add sp, sp, #64 */
/* @0x29637c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x296380 bl 0x215148 <Timing_Time> */
/* @0x296384 mov r4, r0 */
/* @0x296388 ldr r0, [pc, #0x2f4] */
/* @0x29638c mov r5, r1 */
/* @0x296390 strd r4, r5, [r8, #56] */
/* @0x296394 mov r3, r1 */
/* @0x296398 ldr r1, [pc, #0x2e8] */
/* @0x29639c ldr r0, [r6, r0] */
/* @0x2963a0 mov r2, r4 */
/* @0x2963a4 add r1, pc, r1 */
/* @0x2963a8 ldr r0, [r0] */
/* @0x2963ac ldr r12, [r0] */
/* @0x2963b0 ldr r12, [r12, #0xc] */
/* @0x2963b4 blx r12 */
/* @0x2963b8 mov r3, #1 */
/* @0x2963bc mov r9, r3 */
/* @0x2963c0 str r3, [r8, #0x34] */
/* @0x2963c4 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x2963c8 bl 0x215148 <Timing_Time> */
/* @0x2963cc ldr r12, [pc, #0x2b8] */
/* @0x2963d0 mov r4, #1000 */
/* @0x2963d4 ldrd r2, r3, [r8, #56] */
/* @0x2963d8 ldr r12, [r6, r12] */
/* @0x2963dc ldr r12, [r12] */
/* @0x2963e0 mul r4, r4, r12 */
/* @0x2963e4 asr r5, r4, #31 */
/* @0x2963e8 subs r2, r0, r2 */
/* @0x2963ec sbc r3, r1, r3 */
/* @0x2963f0 mov r0, r8 */
/* @0x2963f4 cmp r4, r2 */
/* @0x2963f8 sbcs r1, r5, r3 */
/* @0x2963fc movge r9, #0 */
/* @0x296400 movlt r9, #1 */
/* @0x296404 bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x296408 ldr r3, [pc, #0x274] */
/* @0x29640c ldr r1, [pc, #0x27c] */
/* @0x296410 ldr r3, [r6, r3] */
/* @0x296414 add r1, pc, r1 */
/* @0x296418 ldr r5, [r3] */
/* @0x29641c ldr r3, [r5] */
/* @0x296420 ldr r3, [r3, #0xc] */
/* @0x296424 mov r4, r0 */
/* @0x296428 mov r2, r0 */
/* @0x29642c mov r0, r5 */
/* @0x296430 blx r3 */
/* @0x296434 cmp r4, #0 */
/* @0x296438 movne r3, #0 */
/* @0x29643c andeq r3, r9, #1 */
/* @0x296440 cmp r3, #0 */
/* @0x296444 bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x296448 cmp r9, #0 */
/* @0x29644c bne 0x296458 <_ZN8yySocket19ProcessGMSHandshakeEv+0x138> */
/* @0x296450 cmp r4, #12 */
/* @0x296454 blo 0x296360 <_ZN8yySocket19ProcessGMSHandshakeEv+0x40> */
/* @0x296458 cmp r4, #12 */
/* @0x29645c bne 0x296360 <_ZN8yySocket19ProcessGMSHandshakeEv+0x40> */
/* @0x296460 mov r2, r4 */
/* @0x296464 mov r0, r8 */
/* @0x296468 add r1, sp, #28 */
/* @0x29646c mov r3, #0 */
/* @0x296470 bl 0x2952dc <_ZN8yySocket4ReadEPvjj> */
/* @0x296474 cmp r0, #11 */
/* @0x296478 bls 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x29647c ldr r2, [sp, #0x1c] */
/* @0x296480 movw r3, #0xbead */
/* @0x296484 movt r3, #0xdeaf */
/* @0x296488 cmp r2, r3 */
/* @0x29648c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x296490 ldr r2, [sp, #0x20] */
/* @0x296494 movw r3, #0xbeeb */
/* @0x296498 movt r3, #0xf00d */
/* @0x29649c cmp r2, r3 */
/* @0x2964a0 bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x2964a4 ldr r3, [sp, #0x24] */
/* @0x2964a8 cmp r3, #12 */
/* @0x2964ac bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x2964b0 ldr r3, [r5] */
/* @0x2964b4 mov r0, r5 */
/* @0x2964b8 ldr r1, [pc, #0x1d4] */
/* @0x2964bc mov r9, #2 */
/* @0x2964c0 add r1, pc, r1 */
/* @0x2964c4 ldr r3, [r3, #0xc] */
/* @0x2964c8 blx r3 */
/* @0x2964cc b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x2964d0 bl 0x215148 <Timing_Time> */
/* @0x2964d4 ldr r12, [pc, #0x1b0] */
/* @0x2964d8 mov r4, #1000 */
/* @0x2964dc ldrd r2, r3, [r8, #56] */
/* @0x2964e0 ldr r12, [r6, r12] */
/* @0x2964e4 ldr r12, [r12] */
/* @0x2964e8 mul r4, r4, r12 */
/* @0x2964ec asr r5, r4, #31 */
/* @0x2964f0 subs r2, r0, r2 */
/* @0x2964f4 sbc r3, r1, r3 */
/* @0x2964f8 mov r0, r8 */
/* @0x2964fc cmp r4, r2 */
/* @0x296500 sbcs r1, r5, r3 */
/* @0x296504 movge r5, #0 */
/* @0x296508 movlt r5, #1 */
/* @0x29650c bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x296510 ldr r3, [pc, #0x16c] */
/* @0x296514 ldr r1, [pc, #0x17c] */
/* @0x296518 ldr r3, [r6, r3] */
/* @0x29651c add r1, pc, r1 */
/* @0x296520 ldr r6, [r3] */
/* @0x296524 ldr r3, [r6] */
/* @0x296528 ldr r3, [r3, #0xc] */
/* @0x29652c mov r4, r0 */
/* @0x296530 mov r2, r0 */
/* @0x296534 mov r0, r6 */
/* @0x296538 blx r3 */
/* @0x29653c cmp r4, #0 */
/* @0x296540 movne r3, #0 */
/* @0x296544 andeq r3, r5, #1 */
/* @0x296548 cmp r3, #0 */
/* @0x29654c bne 0x2965bc <_ZN8yySocket19ProcessGMSHandshakeEv+0x29c> */
/* @0x296550 eor r5, r5, #1 */
/* @0x296554 cmp r4, #17 */
/* @0x296558 movgt r3, #0 */
/* @0x29655c andle r3, r5, #1 */
/* @0x296560 cmp r3, #0 */
/* @0x296564 bne 0x296654 <_ZN8yySocket19ProcessGMSHandshakeEv+0x334> */
/* @0x296568 cmp r4, #18 */
/* @0x29656c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x296570 add r5, sp, #28 */
/* @0x296574 mov r2, r4 */
/* @0x296578 mov r0, r8 */
/* @0x29657c mov r1, r5 */
/* @0x296580 bl 0x2952dc <_ZN8yySocket4ReadEPvjj> */
/* @0x296584 ldr r3, [r6] */
/* @0x296588 ldr r1, [pc, #0x10c] */
/* @0x29658c ldr r3, [r3, #0xc] */
/* @0x296590 add r1, pc, r1 */
/* @0x296594 mov r4, r0 */
/* @0x296598 mov r2, r0 */
/* @0x29659c mov r0, r6 */
/* @0x2965a0 blx r3 */
/* @0x2965a4 cmp r4, #17 */
/* @0x2965a8 bgt 0x2965f8 <_ZN8yySocket19ProcessGMSHandshakeEv+0x2d8> */
/* @0x2965ac mov r0, r8 */
/* @0x2965b0 mov r9, #0 */
/* @0x2965b4 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x2965b8 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x2965bc ldr r3, [r6] */
/* @0x2965c0 mov r9, #0 */
/* @0x2965c4 ldrd r4, r5, [r8, #56] */
/* @0x2965c8 ldr r10, [r3, #0xc] */
/* @0x2965cc bl 0x215148 <Timing_Time> */
/* @0x2965d0 mov r2, r4 */
/* @0x2965d4 mov r3, r5 */
/* @0x2965d8 strd r0, r1, [sp] */
/* @0x2965dc mov r0, r6 */
/* @0x2965e0 ldr r1, [pc, #0xb8] */
/* @0x2965e4 add r1, pc, r1 */
/* @0x2965e8 blx r10 */
/* @0x2965ec mov r0, r8 */
/* @0x2965f0 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x2965f4 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x2965f8 ldr r0, [pc, #0xa4] */
/* @0x2965fc mov r1, r5 */
/* @0x296600 add r0, pc, r0 */
/* @0x296604 bl 0xb6574 <strcmp@plt> */
/* @0x296608 cmp r0, #0 */
/* @0x29660c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c> */
/* @0x296610 mov r3, #16 */
/* @0x296614 add r1, sp, #12 */
/* @0x296618 mov r2, r3 */
/* @0x29661c mov r0, r8 */
/* @0x296620 str r3, [sp, #0x14] */
/* @0x296624 movw lr, #0xbabe */
/* @0x296628 movw r12, #0xb00b */
/* @0x29662c movt lr, #0xcafe */
/* @0x296630 movt r12, #0xdead */
/* @0x296634 str lr, [sp, #0xc] */
/* @0x296638 str r12, [sp, #0x10] */
/* @0x29663c bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x296640 bl 0x215148 <Timing_Time> */
/* @0x296644 mov r3, #3 */
/* @0x296648 str r3, [r8, #0x34] */
/* @0x29664c strd r0, r1, [r8, #56] */
/* @0x296650 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x296654 ldr r12, [r6] */
/* @0x296658 mov r2, r4 */
/* @0x29665c ldr r1, [pc, #0x44] */
/* @0x296660 mov r0, r6 */
/* @0x296664 mov r3, #18 */
/* @0x296668 add r1, pc, r1 */
/* @0x29666c ldr r12, [r12, #0xc] */
/* @0x296670 blx r12 */
/* @0x296674 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44> */
/* @0x296678 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x29667c andseq r11, r5, r12, lsl r9 */
/* @0x296680 .word 0xffffbd00 */
/* @0x296684 .word 0xffffbac4 */
/* @0x296688 andeq r3, r12, r4, ror r0 */
/* @0x29668c .word 0xfffffd3c */
/* @0x296690 andeq r3, r12, r12, lsr #1 */
/* @0x296694 andeq r3, r12, r12, lsl r0 */
/* @0x296698 andeq r2, r12, r4, lsl pc */
/* @0x29669c andeq r2, r12, r0, lsl #30 */
/* @0x2966a0 andeq r2, r12, r8, ror #28 */
/* @0x2966a4 andeq r2, r12, r12, lsr #29 */
/* @0x2966a8 andeq r2, r12, r12, lsl #28 */

/* ── FUNC 0x2966ac · yySocket::ConnectGMS(char*, int) · size=316 · insn=79 */
/* @0x2966ac push {r4, r5, lr} */
/* @0x2966b0 sub sp, sp, #20 */
/* @0x2966b4 mov r4, r0 */
/* @0x2966b8 bl 0x295858 <_ZN8yySocket7ConnectEPci> */
/* @0x2966bc cmp r0, #0 */
/* @0x2966c0 movne r5, r0 */
/* @0x2966c4 bne 0x2966e8 <_ZN8yySocket10ConnectGMSEPci+0x3c> */
/* @0x2966c8 ldr r3, [pc, #0x108] */
/* @0x2966cc ldr r3, [pc, r3] */
/* @0x2966d0 ldrb r3, [r3] */
/* @0x2966d4 cmp r3, #0 */
/* @0x2966d8 beq 0x2966f4 <_ZN8yySocket10ConnectGMSEPci+0x48> */
/* @0x2966dc mov r5, r0 */
/* @0x2966e0 mov r3, #1 */
/* @0x2966e4 strb r3, [r4, #0x2e] */
/* @0x2966e8 mov r0, r5 */
/* @0x2966ec add sp, sp, #20 */
/* @0x2966f0 pop {r4, r5, pc} */
/* @0x2966f4 mov r0, r4 */
/* @0x2966f8 movw r1, #0x1388 */
/* @0x2966fc mov r2, #18 */
/* @0x296700 bl 0x2962b0 <_ZN8yySocket11WaitForDataEii> */
/* @0x296704 cmp r0, #18 */
/* @0x296708 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c> */
/* @0x29670c ldr r0, [pc, #0xc8] */
/* @0x296710 ldr r1, [r4, #0x50] */
/* @0x296714 add r0, pc, r0 */
/* @0x296718 bl 0xb6574 <strcmp@plt> */
/* @0x29671c subs r5, r0, #0 */
/* @0x296720 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c> */
/* @0x296724 mov r3, #16 */
/* @0x296728 mov r1, sp */
/* @0x29672c mov r2, r3 */
/* @0x296730 mov r0, r4 */
/* @0x296734 str r3, [sp, #0x8] */
/* @0x296738 movw lr, #0xbabe */
/* @0x29673c movw r12, #0xb00b */
/* @0x296740 movt lr, #0xcafe */
/* @0x296744 movt r12, #0xdead */
/* @0x296748 str lr, [sp] */
/* @0x29674c str r12, [sp, #0x4] */
/* @0x296750 bl 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x296754 movw r1, #0x1388 */
/* @0x296758 mov r2, #12 */
/* @0x29675c mov r0, r4 */
/* @0x296760 bl 0x2962b0 <_ZN8yySocket11WaitForDataEii> */
/* @0x296764 ldr r3, [r4, #0x50] */
/* @0x296768 movw r2, #0xbead */
/* @0x29676c movt r2, #0xdeaf */
/* @0x296770 ldr r1, [r3] */
/* @0x296774 cmp r1, r2 */
/* @0x296778 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c> */
/* @0x29677c ldr r1, [r3, #0x4] */
/* @0x296780 movw r2, #0xbeeb */
/* @0x296784 movt r2, #0xf00d */
/* @0x296788 cmp r1, r2 */
/* @0x29678c bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c> */
/* @0x296790 ldr r3, [r3, #0x8] */
/* @0x296794 cmp r3, #12 */
/* @0x296798 bne 0x2967c8 <_ZN8yySocket10ConnectGMSEPci+0x11c> */
/* @0x29679c ldr r3, [pc, #0x3c] */
/* @0x2967a0 ldr r1, [pc, #0x3c] */
/* @0x2967a4 ldr r3, [pc, r3] */
/* @0x2967a8 add r1, pc, r1 */
/* @0x2967ac ldr r0, [r3] */
/* @0x2967b0 ldr r3, [r0] */
/* @0x2967b4 ldr r3, [r3, #0xc] */
/* @0x2967b8 blx r3 */
/* @0x2967bc mov r0, r5 */
/* @0x2967c0 add sp, sp, #20 */
/* @0x2967c4 pop {r4, r5, pc} */
/* @0x2967c8 mov r0, r4 */
/* @0x2967cc mvn r5, #0 */
/* @0x2967d0 bl 0x295474 <_ZN8yySocket5CloseEv> */
/* @0x2967d4 b 0x2966e8 <_ZN8yySocket10ConnectGMSEPci+0x3c> */
/* @0x2967d8 andseq r11, r5, r8, asr #5 */
/* @0x2967dc muleq r12, r8, sp */
/* @0x2967e0 andseq r6, r5, r0, ror pc */
/* @0x2967e4 andeq r2, r12, r4, lsr sp */

/* ── FUNC 0x2967e8 · debug_display_buffer(tagIConsole&, unsigned char*, int) · size=348 · insn=87 */
/* @0x2967e8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2967ec add r6, r1, r2 */
/* @0x2967f0 cmp r1, r6 */
/* @0x2967f4 sub sp, sp, #20 */
/* @0x2967f8 mov r9, r1 */
/* @0x2967fc mov r11, r0 */
/* @0x296800 bhs 0x296924 <_Z20debug_display_bufferR11tagIConsolePhi+0x13c> */
/* @0x296804 ldr r3, [pc, #0x120] */
/* @0x296808 add r10, r1, #16 */
/* @0x29680c ldr r7, [pc, #0x11c] */
/* @0x296810 add r3, pc, r3 */
/* @0x296814 ldr r8, [pc, #0x118] */
/* @0x296818 str r3, [sp, #0x4] */
/* @0x29681c add r7, pc, r7 */
/* @0x296820 ldr r3, [pc, #0x110] */
/* @0x296824 add r8, pc, r8 */
/* @0x296828 mov r5, r10 */
/* @0x29682c str r1, [sp] */
/* @0x296830 add r3, pc, r3 */
/* @0x296834 str r3, [sp, #0x8] */
/* @0x296838 ldr r3, [pc, #0xfc] */
/* @0x29683c add r3, pc, r3 */
/* @0x296840 str r3, [sp, #0xc] */
/* @0x296844 ldr r12, [r11] */
/* @0x296848 mov r0, r11 */
/* @0x29684c ldr r3, [sp] */
/* @0x296850 mov r4, r9 */
/* @0x296854 ldr r1, [sp, #0x4] */
/* @0x296858 rsb r2, r3, r9 */
/* @0x29685c ldr r12, [r12, #0xc] */
/* @0x296860 blx r12 */
/* @0x296864 cmp r6, r4 */
/* @0x296868 mov r3, r4 */
/* @0x29686c mov r0, r11 */
/* @0x296870 mov r1, r7 */
/* @0x296874 add r4, r4, #1 */
/* @0x296878 bls 0x296894 <_Z20debug_display_bufferR11tagIConsolePhi+0xac> */
/* @0x29687c ldr r12, [r11] */
/* @0x296880 ldrb r2, [r3] */
/* @0x296884 ldr r3, [r12, #0xc] */
/* @0x296888 blx r3 */
/* @0x29688c cmp r4, r5 */
/* @0x296890 bne 0x296864 <_Z20debug_display_bufferR11tagIConsolePhi+0x7c> */
/* @0x296894 ldr r2, [r11] */
/* @0x296898 mov r0, r11 */
/* @0x29689c ldr r1, [sp, #0x8] */
/* @0x2968a0 ldr r2, [r2, #0xc] */
/* @0x2968a4 blx r2 */
/* @0x2968a8 cmp r9, r6 */
/* @0x2968ac ldr r3, [pc, #0x8c] */
/* @0x2968b0 bhs 0x2968fc <_Z20debug_display_bufferR11tagIConsolePhi+0x114> */
/* @0x2968b4 ldr r3, [pc, r3] */
/* @0x2968b8 ldrb r12, [r9], #1 */
/* @0x2968bc ldr r0, [r11] */
/* @0x2968c0 ldr r1, [r3] */
/* @0x2968c4 mov r2, r12 */
/* @0x2968c8 add r1, r1, r12 */
/* @0x2968cc ldr r3, [r0, #0xc] */
/* @0x2968d0 ldrb r1, [r1, #0x1] */
/* @0x2968d4 tst r1, #7 */
/* @0x2968d8 bne 0x2968e8 <_Z20debug_display_bufferR11tagIConsolePhi+0x100> */
/* @0x2968dc tst r1, #4 */
/* @0x2968e0 movne r2, r12 */
/* @0x2968e4 moveq r2, #46 */
/* @0x2968e8 mov r0, r11 */
/* @0x2968ec mov r1, r8 */
/* @0x2968f0 blx r3 */
/* @0x2968f4 cmp r9, r5 */
/* @0x2968f8 bne 0x2968a8 <_Z20debug_display_bufferR11tagIConsolePhi+0xc0> */
/* @0x2968fc ldr r2, [r11] */
/* @0x296900 mov r0, r11 */
/* @0x296904 ldr r1, [sp, #0xc] */
/* @0x296908 add r5, r5, #16 */
/* @0x29690c mov r9, r10 */
/* @0x296910 ldr r2, [r2, #0xc] */
/* @0x296914 blx r2 */
/* @0x296918 cmp r6, r10 */
/* @0x29691c addhi r10, r10, #16 */
/* @0x296920 bhi 0x296844 <_Z20debug_display_bufferR11tagIConsolePhi+0x5c> */
/* @0x296924 add sp, sp, #20 */
/* @0x296928 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x29692c andeq r2, r12, r0, ror #25 */
/* @0x296930 andeq r2, r12, r0, ror #25 */
/* @0x296934 andeq r2, r12, r0, ror #25 */
/* @0x296938 andeq r0, r12, r12, lsr #21 */
/* @0x29693c andeq r12, r9, r12, asr r4 */
/* @0x296940 andseq r7, r5, r12, asr #1 */

/* ── FUNC 0x296944 · yySocket::SendPacket(unsigned char*, int) · size=244 · insn=61 */
/* @0x296944 ldr r3, [pc, #0xdc] */
/* @0x296948 push {r4, r5, r6, r7, lr} */
/* @0x29694c ldr r3, [pc, r3] */
/* @0x296950 sub sp, sp, #12 */
/* @0x296954 mov r4, r0 */
/* @0x296958 ldrb r3, [r3] */
/* @0x29695c mov r7, r1 */
/* @0x296960 mov r5, r2 */
/* @0x296964 cmp r3, #0 */
/* @0x296968 bne 0x2969f0 <_ZN8yySocket10SendPacketEPhi+0xac> */
/* @0x29696c ldr r3, [r4, #0x5c] */
/* @0x296970 add r6, r5, #12 */
/* @0x296974 cmp r6, r3 */
/* @0x296978 bgt 0x2969c4 <_ZN8yySocket10SendPacketEPhi+0x80> */
/* @0x29697c ldr r3, [r4, #0x58] */
/* @0x296980 mov r1, r7 */
/* @0x296984 mov r2, r5 */
/* @0x296988 add r0, r3, #12 */
/* @0x29698c bl 0xb65bc <memcpy@plt> */
/* @0x296990 ldr r3, [r4, #0x58] */
/* @0x296994 mov r12, #12 */
/* @0x296998 mov r2, r6 */
/* @0x29699c movw r1, #0xc0de */
/* @0x2969a0 mov r0, r4 */
/* @0x2969a4 movt r1, #0xdead */
/* @0x2969a8 str r5, [r3, #0x8] */
/* @0x2969ac str r1, [r3] */
/* @0x2969b0 mov r1, r3 */
/* @0x2969b4 str r12, [r3, #0x4] */
/* @0x2969b8 add sp, sp, #12 */
/* @0x2969bc pop {r4, r5, r6, r7, lr} */
/* @0x2969c0 b 0x295464 <_ZN8yySocket5WriteEPvj> */
/* @0x2969c4 ldr r2, [pc, #0x60] */
/* @0x2969c8 mov r3, #0 */
/* @0x2969cc ldr r0, [r4, #0x58] */
/* @0x2969d0 mov r1, r6 */
/* @0x2969d4 str r3, [sp] */
/* @0x2969d8 add r2, pc, r2 */
/* @0x2969dc mov r3, #74 */
/* @0x2969e0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x2969e4 mov r3, r0 */
/* @0x2969e8 str r0, [r4, #0x58] */
/* @0x2969ec b 0x296980 <_ZN8yySocket10SendPacketEPhi+0x3c> */
/* @0x2969f0 ldr r3, [pc, #0x38] */
/* @0x2969f4 ldr r1, [pc, #0x38] */
/* @0x2969f8 ldr r3, [pc, r3] */
/* @0x2969fc add r1, pc, r1 */
/* @0x296a00 ldr r6, [r3] */
/* @0x296a04 ldr r3, [r6] */
/* @0x296a08 mov r0, r6 */
/* @0x296a0c ldr r3, [r3, #0xc] */
/* @0x296a10 blx r3 */
/* @0x296a14 mov r0, r6 */
/* @0x296a18 mov r1, r7 */
/* @0x296a1c mov r2, r5 */
/* @0x296a20 bl 0x2967e8 <_Z20debug_display_bufferR11tagIConsolePhi> */
/* @0x296a24 b 0x29696c <_ZN8yySocket10SendPacketEPhi+0x28> */
/* @0x296a28 andseq r11, r5, r12, asr #32 */
/* @0x296a2c andeq r10, r9, r8, asr r6 */
/* @0x296a30 andseq r6, r5, r12, lsl sp */
/* @0x296a34 andeq r2, r12, r12, lsl #22 */

/* ── FUNC 0x296a38 · yySocket::SendUDPPacket(char*, int, unsigned char*, int, bool) · size=208 · insn=52 */
/* @0x296a38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x296a3c sub sp, sp, #12 */
/* @0x296a40 mov r11, r3 */
/* @0x296a44 ldr r3, [r0, #0x5c] */
/* @0x296a48 ldrb r6, [sp, #0x34] */
/* @0x296a4c mov r4, r0 */
/* @0x296a50 ldr r7, [sp, #0x30] */
/* @0x296a54 mov r10, r1 */
/* @0x296a58 cmp r6, #0 */
/* @0x296a5c mov r9, r2 */
/* @0x296a60 movne r8, #12 */
/* @0x296a64 moveq r5, r6 */
/* @0x296a68 movne r5, r8 */
/* @0x296a6c add r5, r5, r7 */
/* @0x296a70 moveq r8, r6 */
/* @0x296a74 cmp r5, r3 */
/* @0x296a78 bgt 0x296ad8 <_ZN8yySocket13SendUDPPacketEPciPhib+0xa0> */
/* @0x296a7c ldr r3, [r0, #0x58] */
/* @0x296a80 mov r2, r7 */
/* @0x296a84 add r0, r3, r8 */
/* @0x296a88 mov r1, r11 */
/* @0x296a8c bl 0xb65bc <memcpy@plt> */
/* @0x296a90 cmp r6, #0 */
/* @0x296a94 ldrne r0, [r4, #0x58] */
/* @0x296a98 movwne r2, #0xc0de */
/* @0x296a9c ldreq r3, [r4, #0x58] */
/* @0x296aa0 movne r1, #12 */
/* @0x296aa4 movtne r2, #0xdead */
/* @0x296aa8 stmibne r0, {r1, r7} */
/* @0x296aac strne r2, [r0] */
/* @0x296ab0 movne r3, r0 */
/* @0x296ab4 str r5, [sp] */
/* @0x296ab8 mov r0, r4 */
/* @0x296abc mov r1, r10 */
/* @0x296ac0 mov r2, r9 */
/* @0x296ac4 bl 0x295f28 <_ZN8yySocket6SendToEPciPhi> */
/* @0x296ac8 cmp r0, #0 */
/* @0x296acc movge r0, r5 */
/* @0x296ad0 add sp, sp, #12 */
/* @0x296ad4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x296ad8 ldr r2, [pc, #0x24] */
/* @0x296adc mov r3, #0 */
/* @0x296ae0 ldr r0, [r0, #0x58] */
/* @0x296ae4 mov r1, r5 */
/* @0x296ae8 str r3, [sp] */
/* @0x296aec add r2, pc, r2 */
/* @0x296af0 mov r3, #74 */
/* @0x296af4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x296af8 mov r3, r0 */
/* @0x296afc str r0, [r4, #0x58] */
/* @0x296b00 b 0x296a80 <_ZN8yySocket13SendUDPPacketEPciPhib+0x48> */
/* @0x296b04 andeq r10, r9, r4, asr #10 */

/* ── FUNC 0x296b08 · yySocket::SendDataToEvent(int, unsigned char*) · size=432 · insn=108 */
/* @0x296b08 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x296b0c vpush {d8} */
/* @0x296b10 sub sp, sp, #72 */
/* @0x296b14 vmov s13, r1 */
/* @0x296b18 mov r3, #0 */
/* @0x296b1c str r3, [sp, #0x24] */
/* @0x296b20 subs r10, r2, #0 */
/* @0x296b24 str r3, [sp, #0x34] */
/* @0x296b28 vcvt.f64.s32 d8, s13 */
/* @0x296b2c str r3, [sp, #0x44] */
/* @0x296b30 mov r4, #0 */
/* @0x296b34 ldr r3, [pc, #0x16c] */
/* @0x296b38 mov r5, #0 */
/* @0x296b3c ldreq r10, [r0, #0x50] */
/* @0x296b40 movt r5, #0x3ff0 */
/* @0x296b44 ldr r3, [pc, r3] */
/* @0x296b48 mov r6, #0 */
/* @0x296b4c mov r7, #0 */
/* @0x296b50 mov r8, r1 */
/* @0x296b54 ldrb r3, [r3] */
/* @0x296b58 mov r9, r0 */
/* @0x296b5c strd r6, r7, [sp, #40] */
/* @0x296b60 vstr d8, [sp, #24] */
/* @0x296b64 cmp r3, #0 */
/* @0x296b68 strd r4, r5, [sp, #56] */
/* @0x296b6c bne 0x296c70 <_ZN8yySocket15SendDataToEventEiPh+0x168> */
/* @0x296b70 ldr r3, [r9, #0x64] */
/* @0x296b74 ldr r0, [r9, #0x60] */
/* @0x296b78 cmp r8, r3 */
/* @0x296b7c bgt 0x296c44 <_ZN8yySocket15SendDataToEventEiPh+0x13c> */
/* @0x296b80 mov r2, r8 */
/* @0x296b84 mov r1, r10 */
/* @0x296b88 bl 0xb65bc <memcpy@plt> */
/* @0x296b8c ldr r5, [r9, #0x60] */
/* @0x296b90 movw r3, #0xc0de */
/* @0x296b94 movt r3, #0xdead */
/* @0x296b98 ldr r2, [r5] */
/* @0x296b9c cmp r2, r3 */
/* @0x296ba0 bne 0x296bbc <_ZN8yySocket15SendDataToEventEiPh+0xb4> */
/* @0x296ba4 ldr r3, [r5, #0x4] */
/* @0x296ba8 cmp r3, #12 */
/* @0x296bac ldreq r8, [r5, #0x8] */
/* @0x296bb0 addeq r5, r5, #12 */
/* @0x296bb4 vmoveq s15, r8 */
/* @0x296bb8 vcvteq.f64.s32 d8, s15 */
/* @0x296bbc add r6, sp, #8 */
/* @0x296bc0 mov r1, #0 */
/* @0x296bc4 mov r3, #3 */
/* @0x296bc8 mov r2, r1 */
/* @0x296bcc mov r0, r6 */
/* @0x296bd0 add r7, sp, #24 */
/* @0x296bd4 str r7, [sp] */
/* @0x296bd8 vstr d8, [sp, #24] */
/* @0x296bdc bl 0xc6bb8 <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_> */
/* @0x296be0 vldr d7, [sp, #8] */
/* @0x296be4 vcvt.s32.f64 s13, d7 */
/* @0x296be8 vmov r0, s13 */
/* @0x296bec vmov r4, s13 */
/* @0x296bf0 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x296bf4 mov r1, r5 */
/* @0x296bf8 mov r2, r8 */
/* @0x296bfc ldr r0, [r0, #0xc] */
/* @0x296c00 bl 0xb65bc <memcpy@plt> */
/* @0x296c04 ldr r0, [r9, #0x68] */
/* @0x296c08 mov r2, r8 */
/* @0x296c0c mov r1, r4 */
/* @0x296c10 bl 0x298b9c <_Z17ThrowNetworkEventiii> */
/* @0x296c14 vmov s13, r4 */
/* @0x296c18 mov r1, #0 */
/* @0x296c1c str r7, [sp] */
/* @0x296c20 vcvt.f64.s32 d7, s13 */
/* @0x296c24 mov r0, r6 */
/* @0x296c28 mov r2, r1 */
/* @0x296c2c mov r3, #1 */
/* @0x296c30 vstr d7, [sp, #24] */
/* @0x296c34 bl 0xc52a4 <_Z15F_BUFFER_DeleteR6RValueP9CInstanceS2_iPS_> */
/* @0x296c38 add sp, sp, #72 */
/* @0x296c3c vpop {d8} */
/* @0x296c40 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x296c44 ldr r2, [pc, #0x60] */
/* @0x296c48 mov r3, #0 */
/* @0x296c4c str r8, [r9, #0x64] */
/* @0x296c50 mov r1, r8 */
/* @0x296c54 str r3, [sp] */
/* @0x296c58 add r2, pc, r2 */
/* @0x296c5c mov r3, #74 */
/* @0x296c60 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x296c64 mov r3, r0 */
/* @0x296c68 str r3, [r9, #0x60] */
/* @0x296c6c b 0x296b80 <_ZN8yySocket15SendDataToEventEiPh+0x78> */
/* @0x296c70 ldr r3, [pc, #0x38] */
/* @0x296c74 ldr r1, [pc, #0x38] */
/* @0x296c78 ldr r3, [pc, r3] */
/* @0x296c7c add r1, pc, r1 */
/* @0x296c80 ldr r4, [r3] */
/* @0x296c84 ldr r3, [r4] */
/* @0x296c88 mov r0, r4 */
/* @0x296c8c ldr r3, [r3, #0xc] */
/* @0x296c90 blx r3 */
/* @0x296c94 mov r0, r4 */
/* @0x296c98 mov r1, r10 */
/* @0x296c9c mov r2, r8 */
/* @0x296ca0 bl 0x2967e8 <_Z20debug_display_bufferR11tagIConsolePhi> */
/* @0x296ca4 b 0x296b70 <_ZN8yySocket15SendDataToEventEiPh+0x68> */
/* @0x296ca8 andseq r10, r5, r4, asr lr */
/* @0x296cac ldrdeq r10, r11, [r9], -r8 */
/* @0x296cb0 mulseq r5, r12, r10 */
/* @0x296cb4 muleq r12, r4, r8 */

/* ── FUNC 0x296cb8 · yySocket::ProcessUDP() · size=288 · insn=72 */
/* @0x296cb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x296cbc sub sp, sp, #28 */
/* @0x296cc0 ldr r7, [r0, #0x50] */
/* @0x296cc4 add r10, r0, #108 */
/* @0x296cc8 ldr r6, [r0, #0x54] */
/* @0x296ccc add r9, sp, #16 */
/* @0x296cd0 ldr r3, [pc, #0xfc] */
/* @0x296cd4 add r8, sp, #20 */
/* @0x296cd8 mov r4, r0 */
/* @0x296cdc add r3, pc, r3 */
/* @0x296ce0 str r3, [sp, #0xc] */
/* @0x296ce4 mov r0, r4 */
/* @0x296ce8 bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x296cec ldr r3, [r4, #0x54] */
/* @0x296cf0 cmp r0, r3 */
/* @0x296cf4 mov r5, r0 */
/* @0x296cf8 bgt 0x296d90 <_ZN8yySocket10ProcessUDPEv+0xd8> */
/* @0x296cfc mov r3, #0 */
/* @0x296d00 cmp r5, r3 */
/* @0x296d04 mov r2, r6 */
/* @0x296d08 mov r1, r7 */
/* @0x296d0c mov r0, r4 */
/* @0x296d10 ble 0x296dcc <_ZN8yySocket10ProcessUDPEv+0x114> */
/* @0x296d14 str r9, [sp] */
/* @0x296d18 str r8, [sp, #0x4] */
/* @0x296d1c bl 0x2952ec <_ZN8yySocket8ReadFromEPvjjPPcPi> */
/* @0x296d20 subs r5, r0, #0 */
/* @0x296d24 mov r0, r10 */
/* @0x296d28 ble 0x296dcc <_ZN8yySocket10ProcessUDPEv+0x114> */
/* @0x296d2c ldr r11, [sp, #0x10] */
/* @0x296d30 mov r1, r11 */
/* @0x296d34 bl 0xb65a4 <strcpy@plt> */
/* @0x296d38 ldrb lr, [r4, #0x30] */
/* @0x296d3c ldr r12, [sp, #0x14] */
/* @0x296d40 mov r2, r5 */
/* @0x296d44 cmp lr, #0 */
/* @0x296d48 mov r3, r11 */
/* @0x296d4c mov r0, r4 */
/* @0x296d50 mov r1, r5 */
/* @0x296d54 str r12, [r4, #0xac] */
/* @0x296d58 beq 0x296dc0 <_ZN8yySocket10ProcessUDPEv+0x108> */
/* @0x296d5c str r12, [sp] */
/* @0x296d60 ldr r0, [r4, #0x68] */
/* @0x296d64 ldr r1, [r4, #0x50] */
/* @0x296d68 bl 0x29a4ac <_Z24RelyFilterIncomingPacketiPhiPci> */
/* @0x296d6c subs r3, r0, #0 */
/* @0x296d70 mov r0, r4 */
/* @0x296d74 mov r2, r3 */
/* @0x296d78 beq 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c> */
/* @0x296d7c ldr r1, [r4, #0x50] */
/* @0x296d80 rsb r1, r1, r3 */
/* @0x296d84 rsb r1, r1, r5 */
/* @0x296d88 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh> */
/* @0x296d8c b 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c> */
/* @0x296d90 add r6, r3, #32768 */
/* @0x296d94 ldr r2, [sp, #0xc] */
/* @0x296d98 mov r3, #0 */
/* @0x296d9c str r3, [sp] */
/* @0x296da0 mov r1, r6 */
/* @0x296da4 ldr r0, [r4, #0x50] */
/* @0x296da8 str r6, [r4, #0x54] */
/* @0x296dac mov r3, #74 */
/* @0x296db0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x296db4 mov r7, r0 */
/* @0x296db8 str r0, [r4, #0x50] */
/* @0x296dbc b 0x296cfc <_ZN8yySocket10ProcessUDPEv+0x44> */
/* @0x296dc0 ldr r2, [r4, #0x50] */
/* @0x296dc4 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh> */
/* @0x296dc8 b 0x296ce4 <_ZN8yySocket10ProcessUDPEv+0x2c> */
/* @0x296dcc add sp, sp, #28 */
/* @0x296dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x296dd4 andeq r10, r9, r4, asr r3 */

/* ── FUNC 0x296dd8 · yySocket::HandleMessage(yyServer*) · size=68 · insn=17 */
/* @0x296dd8 cmp r1, #0 */
/* @0x296ddc ldr r3, [r0, #0xc0] */
/* @0x296de0 push {r4, lr} */
/* @0x296de4 mov r4, r0 */
/* @0x296de8 beq 0x296e0c <_ZN8yySocket13HandleMessageEP8yyServer+0x34> */
/* @0x296dec mov r0, r1 */
/* @0x296df0 ldr r2, [r4, #0x50] */
/* @0x296df4 mov r1, r4 */
/* @0x296df8 bl 0x2975a4 <_ZN8yyServer17ProcessDataPacketEP8yySocketPhi> */
/* @0x296dfc mov r3, #0 */
/* @0x296e00 str r3, [r4, #0xbc] */
/* @0x296e04 str r3, [r4, #0xc0] */
/* @0x296e08 pop {r4, pc} */
/* @0x296e0c mov r1, r3 */
/* @0x296e10 ldr r2, [r0, #0x50] */
/* @0x296e14 bl 0x296b08 <_ZN8yySocket15SendDataToEventEiPh> */
/* @0x296e18 b 0x296dfc <_ZN8yySocket13HandleMessageEP8yyServer+0x24> */

/* ── FUNC 0x296e1c · yySocket::ReadAndProcessDataStream(yyServer*) · size=328 · insn=82 */
/* @0x296e1c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x296e20 mov r6, #0 */
/* @0x296e24 ldr r8, [pc, #0x134] */
/* @0x296e28 sub sp, sp, #12 */
/* @0x296e2c mov r4, r0 */
/* @0x296e30 mov r9, r1 */
/* @0x296e34 add r8, pc, r8 */
/* @0x296e38 mov r7, r6 */
/* @0x296e3c ldr r3, [r4, #0xbc] */
/* @0x296e40 cmp r3, #0 */
/* @0x296e44 beq 0x296ed0 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0xb4> */
/* @0x296e48 cmp r3, #0 */
/* @0x296e4c ldr r5, [r4, #0xc0] */
/* @0x296e50 mov r0, r4 */
/* @0x296e54 ldr r11, [r4, #0x50] */
/* @0x296e58 ldrle r10, [r4, #0x54] */
/* @0x296e5c rsbgt r10, r5, r3 */
/* @0x296e60 rsble r10, r5, r10 */
/* @0x296e64 bl 0x295438 <_ZN8yySocket4PeekEv> */
/* @0x296e68 cmp r0, #0 */
/* @0x296e6c bgt 0x296eec <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0xd0> */
/* @0x296e70 ldr r3, [r4, #0xbc] */
/* @0x296e74 cmp r3, #0 */
/* @0x296e78 ble 0x296f3c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x120> */
/* @0x296e7c ldr r2, [r4, #0xc0] */
/* @0x296e80 cmp r3, r2 */
/* @0x296e84 bgt 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138> */
/* @0x296e88 mov r0, r4 */
/* @0x296e8c mov r1, r9 */
/* @0x296e90 bl 0x296dd8 <_ZN8yySocket13HandleMessageEP8yyServer> */
/* @0x296e94 ldr r0, [r4, #0xc0] */
/* @0x296e98 ldr r3, [r4, #0x54] */
/* @0x296e9c cmp r3, r0 */
/* @0x296ea0 bgt 0x296e3c <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x20> */
/* @0x296ea4 lsl r1, r3, #1 */
/* @0x296ea8 ldr r0, [r4, #0x50] */
/* @0x296eac mov r3, #74 */
/* @0x296eb0 str r7, [sp] */
/* @0x296eb4 mov r2, r8 */
/* @0x296eb8 str r1, [r4, #0x54] */
/* @0x296ebc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x296ec0 ldr r3, [r4, #0xbc] */
/* @0x296ec4 cmp r3, #0 */
/* @0x296ec8 str r0, [r4, #0x50] */
/* @0x296ecc bne 0x296e48 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x2c> */
/* @0x296ed0 mov r0, r4 */
/* @0x296ed4 bl 0x296194 <_ZN8yySocket17ReadMessageHeaderEv> */
/* @0x296ed8 cmp r0, #0 */
/* @0x296edc beq 0x296f30 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x114> */
/* @0x296ee0 ldr r3, [r4, #0xbc] */
/* @0x296ee4 mov r6, #1 */
/* @0x296ee8 b 0x296e48 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x2c> */
/* @0x296eec add r1, r11, r5 */
/* @0x296ef0 mov r2, r10 */
/* @0x296ef4 mov r0, r4 */
/* @0x296ef8 mov r3, #0 */
/* @0x296efc bl 0x2952dc <_ZN8yySocket4ReadEPvjj> */
/* @0x296f00 cmp r0, #0 */
/* @0x296f04 ble 0x296f30 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x114> */
/* @0x296f08 ldr r3, [r4, #0xbc] */
/* @0x296f0c mov r6, #1 */
/* @0x296f10 ldr r2, [r4, #0xc0] */
/* @0x296f14 cmp r3, #0 */
/* @0x296f18 add r0, r0, r2 */
/* @0x296f1c str r0, [r4, #0xc0] */
/* @0x296f20 ble 0x296e98 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x7c> */
/* @0x296f24 cmp r0, r3 */
/* @0x296f28 blt 0x296e98 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x7c> */
/* @0x296f2c b 0x296e88 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x6c> */
/* @0x296f30 ldr r3, [r4, #0xbc] */
/* @0x296f34 cmp r3, #0 */
/* @0x296f38 bgt 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138> */
/* @0x296f3c ldr r3, [r4, #0xc0] */
/* @0x296f40 cmp r3, #0 */
/* @0x296f44 ble 0x296f54 <_ZN8yySocket24ReadAndProcessDataStreamEP8yyServer+0x138> */
/* @0x296f48 mov r0, r4 */
/* @0x296f4c mov r1, r9 */
/* @0x296f50 bl 0x296dd8 <_ZN8yySocket13HandleMessageEP8yyServer> */
/* @0x296f54 mov r0, r6 */
/* @0x296f58 add sp, sp, #12 */
/* @0x296f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x296f60 strdeq r10, r11, [r9], -r12 */

/* ── FUNC 0x296f64 · yySocket::ResolveIP() · size=156 · insn=39 */
/* @0x296f64 push {r4, r5, r6, lr} */
/* @0x296f68 mov r5, r0 */
/* @0x296f6c ldr r4, [pc, #0x84] */
/* @0x296f70 sub sp, sp, #40 */
/* @0x296f74 add r1, sp, #20 */
/* @0x296f78 add r2, sp, #16 */
/* @0x296f7c ldr r4, [pc, r4] */
/* @0x296f80 mov r6, r0 */
/* @0x296f84 ldr r0, [r5], #108 */
/* @0x296f88 mov r12, #16 */
/* @0x296f8c ldr r3, [r4] */
/* @0x296f90 str r12, [sp, #0x10] */
/* @0x296f94 str r3, [sp, #0x24] */
/* @0x296f98 bl 0xb6e80 <getpeername@plt> */
/* @0x296f9c ldrb r2, [sp, #0x1b] */
/* @0x296fa0 mov r0, r5 */
/* @0x296fa4 ldrb lr, [sp, #0x19] */
/* @0x296fa8 mov r1, #15 */
/* @0x296fac ldrb r12, [sp, #0x1a] */
/* @0x296fb0 str r2, [sp, #0x8] */
/* @0x296fb4 ldr r2, [pc, #0x40] */
/* @0x296fb8 ldrb r3, [sp, #0x18] */
/* @0x296fbc str lr, [sp] */
/* @0x296fc0 add r2, pc, r2 */
/* @0x296fc4 str r12, [sp, #0x4] */
/* @0x296fc8 bl 0xb65c8 <snprintf@plt> */
/* @0x296fcc ldrh r3, [sp, #22] */
/* @0x296fd0 rev16 r3, r3 */
/* @0x296fd4 ldr r1, [sp, #0x24] */
/* @0x296fd8 uxth r3, r3 */
/* @0x296fdc ldr r2, [r4] */
/* @0x296fe0 str r3, [r6, #0xb0] */
/* @0x296fe4 cmp r1, r2 */
/* @0x296fe8 bne 0x296ff4 <_ZN8yySocket9ResolveIPEv+0x90> */
/* @0x296fec add sp, sp, #40 */
/* @0x296ff0 pop {r4, r5, r6, pc} */
/* @0x296ff4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x296ff8 ldrsbeq r6, [r5], -r4 */
/* @0x296ffc andeq r2, r12, r8, asr r5 */

/* ── FUNC 0x297000 · yySocket::DetectIPv6() · size=8 · insn=2 */
/* @0x297000 mov r0, #0 */
/* @0x297004 bx lr */

/* ── FUNC 0x297008 · yySocket::InitSocket(eSocketType) · size=164 · insn=41 */
/* @0x297008 ldr r12, [pc, #0x98] */
/* @0x29700c mov r2, #0 */
/* @0x297010 push {r3, r4, r5, lr} */
/* @0x297014 ldr r12, [pc, r12] */
/* @0x297018 mov r5, #0 */
/* @0x29701c str r1, [r0, #0x8] */
/* @0x297020 mov r3, #0 */
/* @0x297024 str r5, [r0, #0xc] */
/* @0x297028 strd r2, r3, [r0, #64] */
/* @0x29702c mvn r2, #0 */
/* @0x297030 mov r3, #120 */
/* @0x297034 str r2, [r0] */
/* @0x297038 str r2, [r0, #0x4] */
/* @0x29703c mov r4, r0 */
/* @0x297040 str r5, [r0, #0x10] */
/* @0x297044 str r5, [r0, #0x14] */
/* @0x297048 str r5, [r0, #0x28] */
/* @0x29704c strb r5, [r0, #0x2c] */
/* @0x297050 str r5, [r0, #0x4c] */
/* @0x297054 str r5, [r0, #0x50] */
/* @0x297058 str r5, [r0, #0x54] */
/* @0x29705c str r5, [r0, #0x58] */
/* @0x297060 str r5, [r0, #0x5c] */
/* @0x297064 str r5, [r0, #0x60] */
/* @0x297068 str r5, [r0, #0x64] */
/* @0x29706c str r5, [r0, #0xbc] */
/* @0x297070 str r5, [r0, #0xc0] */
/* @0x297074 strb r5, [r0, #0x2d] */
/* @0x297078 strb r5, [r0, #0x2f] */
/* @0x29707c strb r5, [r0, #0x30] */
/* @0x297080 str r3, [r0, #0xb4] */
/* @0x297084 str r3, [r0, #0xb8] */
/* @0x297088 str r5, [r12] */
/* @0x29708c bl 0x297000 <_ZN8yySocket10DetectIPv6Ev> */
/* @0x297090 mov r1, r5 */
/* @0x297094 mov r2, #64 */
/* @0x297098 strb r0, [r4, #0xc4] */
/* @0x29709c add r0, r4, #108 */
/* @0x2970a0 pop {r3, r4, r5, lr} */
/* @0x2970a4 b 0xb65b0 <memset@plt> */
/* @0x2970a8 andseq r10, r5, r12, ror r9 */

/* ── FUNC 0x2970ac · yySocket::yySocket(eSocketType) · size=20 · insn=5 */
/* @0x2970ac push {r4, lr} */
/* @0x2970b0 mov r4, r0 */
/* @0x2970b4 bl 0x297008 <_ZN8yySocket10InitSocketE11eSocketType> */
/* @0x2970b8 mov r0, r4 */
/* @0x2970bc pop {r4, pc} */

/* ── FUNC 0x2970ac · yySocket::yySocket(eSocketType) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2970c0 · yySocket::yySocket(int, eSocketType, bool) · size=56 · insn=14 */
/* @0x2970c0 push {r4, r5, r6, lr} */
/* @0x2970c4 mov r5, r1 */
/* @0x2970c8 mov r1, r2 */
/* @0x2970cc mov r6, r3 */
/* @0x2970d0 mov r4, r0 */
/* @0x2970d4 bl 0x297008 <_ZN8yySocket10InitSocketE11eSocketType> */
/* @0x2970d8 cmp r6, #0 */
/* @0x2970dc str r5, [r4] */
/* @0x2970e0 beq 0x2970f0 <_ZN8yySocketC2Ei11eSocketTypeb+0x30> */
/* @0x2970e4 mov r0, r4 */
/* @0x2970e8 mov r1, #4096 */
/* @0x2970ec bl 0x296080 <_ZN8yySocket14AllocateBufferEi> */
/* @0x2970f0 mov r0, r4 */
/* @0x2970f4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x2970c0 · yySocket::yySocket(int, eSocketType, bool) · alias of the symbol above · insn=0 */
