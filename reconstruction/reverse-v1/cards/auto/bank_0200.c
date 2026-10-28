/* libyoyo.so 覆盖卡组 0200
 * 函数 0x221714..0x2228a4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x221714 · alutGetError · size=28 · insn=7 */
/* @0x221714 ldr r3, [pc, #0x10] */
/* @0x221718 mov r2, #0 */
/* @0x22171c add r3, pc, r3 */
/* @0x221720 ldr r0, [r3] */
/* @0x221724 str r2, [r3] */
/* @0x221728 bx lr */
/* @0x22172c subseq r3, r3, r8, asr #26 */

/* ── FUNC 0x221730 · alutGetErrorString · size=528 · insn=132 */
/* @0x221730 cmp r0, #520 */
/* @0x221734 beq 0x2218cc <alutGetErrorString+0x19c> */
/* @0x221738 ble 0x22177c <alutGetErrorString+0x4c> */
/* @0x22173c movw r3, #0x20d */
/* @0x221740 cmp r0, r3 */
/* @0x221744 beq 0x22189c <alutGetErrorString+0x16c> */
/* @0x221748 bgt 0x2217f8 <alutGetErrorString+0xc8> */
/* @0x22174c movw r3, #0x20a */
/* @0x221750 cmp r0, r3 */
/* @0x221754 beq 0x22184c <alutGetErrorString+0x11c> */
/* @0x221758 blt 0x2218e4 <alutGetErrorString+0x1b4> */
/* @0x22175c add r3, r3, #1 */
/* @0x221760 cmp r0, r3 */
/* @0x221764 beq 0x2218d8 <alutGetErrorString+0x1a8> */
/* @0x221768 cmp r0, #524 */
/* @0x22176c bne 0x221890 <alutGetErrorString+0x160> */
/* @0x221770 ldr r0, [pc, #0x178] */
/* @0x221774 add r0, pc, r0 */
/* @0x221778 bx lr */
/* @0x22177c movw r3, #0x203 */
/* @0x221780 cmp r0, r3 */
/* @0x221784 beq 0x2218c0 <alutGetErrorString+0x190> */
/* @0x221788 cmp r0, #516 */
/* @0x22178c bge 0x2217c0 <alutGetErrorString+0x90> */
/* @0x221790 cmp r0, #512 */
/* @0x221794 beq 0x221834 <alutGetErrorString+0x104> */
/* @0x221798 ble 0x221858 <alutGetErrorString+0x128> */
/* @0x22179c movw r3, #0x201 */
/* @0x2217a0 cmp r0, r3 */
/* @0x2217a4 beq 0x22186c <alutGetErrorString+0x13c> */
/* @0x2217a8 add r3, r3, #1 */
/* @0x2217ac cmp r0, r3 */
/* @0x2217b0 bne 0x221890 <alutGetErrorString+0x160> */
/* @0x2217b4 ldr r0, [pc, #0x138] */
/* @0x2217b8 add r0, pc, r0 */
/* @0x2217bc bx lr */
/* @0x2217c0 movw r3, #0x205 */
/* @0x2217c4 cmp r0, r3 */
/* @0x2217c8 beq 0x221828 <alutGetErrorString+0xf8> */
/* @0x2217cc cmp r0, #516 */
/* @0x2217d0 ble 0x2218b4 <alutGetErrorString+0x184> */
/* @0x2217d4 add r3, r3, #1 */
/* @0x2217d8 cmp r0, r3 */
/* @0x2217dc beq 0x2218a8 <alutGetErrorString+0x178> */
/* @0x2217e0 add r3, r3, #1 */
/* @0x2217e4 cmp r0, r3 */
/* @0x2217e8 bne 0x221890 <alutGetErrorString+0x160> */
/* @0x2217ec ldr r0, [pc, #0x104] */
/* @0x2217f0 add r0, pc, r0 */
/* @0x2217f4 bx lr */
/* @0x2217f8 movw r3, #0x20f */
/* @0x2217fc cmp r0, r3 */
/* @0x221800 beq 0x221840 <alutGetErrorString+0x110> */
/* @0x221804 blt 0x221884 <alutGetErrorString+0x154> */
/* @0x221808 cmp r0, #528 */
/* @0x22180c beq 0x221878 <alutGetErrorString+0x148> */
/* @0x221810 add r3, r3, #2 */
/* @0x221814 cmp r0, r3 */
/* @0x221818 bne 0x221890 <alutGetErrorString+0x160> */
/* @0x22181c ldr r0, [pc, #0xd8] */
/* @0x221820 add r0, pc, r0 */
/* @0x221824 bx lr */
/* @0x221828 ldr r0, [pc, #0xd0] */
/* @0x22182c add r0, pc, r0 */
/* @0x221830 bx lr */
/* @0x221834 ldr r0, [pc, #0xc8] */
/* @0x221838 add r0, pc, r0 */
/* @0x22183c bx lr */
/* @0x221840 ldr r0, [pc, #0xc0] */
/* @0x221844 add r0, pc, r0 */
/* @0x221848 bx lr */
/* @0x22184c ldr r0, [pc, #0xb8] */
/* @0x221850 add r0, pc, r0 */
/* @0x221854 bx lr */
/* @0x221858 cmp r0, #0 */
/* @0x22185c bne 0x221890 <alutGetErrorString+0x160> */
/* @0x221860 ldr r0, [pc, #0xa8] */
/* @0x221864 add r0, pc, r0 */
/* @0x221868 bx lr */
/* @0x22186c ldr r0, [pc, #0xa0] */
/* @0x221870 add r0, pc, r0 */
/* @0x221874 bx lr */
/* @0x221878 ldr r0, [pc, #0x98] */
/* @0x22187c add r0, pc, r0 */
/* @0x221880 bx lr */
/* @0x221884 ldr r0, [pc, #0x90] */
/* @0x221888 add r0, pc, r0 */
/* @0x22188c bx lr */
/* @0x221890 ldr r0, [pc, #0x88] */
/* @0x221894 add r0, pc, r0 */
/* @0x221898 bx lr */
/* @0x22189c ldr r0, [pc, #0x80] */
/* @0x2218a0 add r0, pc, r0 */
/* @0x2218a4 bx lr */
/* @0x2218a8 ldr r0, [pc, #0x78] */
/* @0x2218ac add r0, pc, r0 */
/* @0x2218b0 bx lr */
/* @0x2218b4 ldr r0, [pc, #0x70] */
/* @0x2218b8 add r0, pc, r0 */
/* @0x2218bc bx lr */
/* @0x2218c0 ldr r0, [pc, #0x68] */
/* @0x2218c4 add r0, pc, r0 */
/* @0x2218c8 bx lr */
/* @0x2218cc ldr r0, [pc, #0x60] */
/* @0x2218d0 add r0, pc, r0 */
/* @0x2218d4 bx lr */
/* @0x2218d8 ldr r0, [pc, #0x58] */
/* @0x2218dc add r0, pc, r0 */
/* @0x2218e0 bx lr */
/* @0x2218e4 ldr r0, [pc, #0x50] */
/* @0x2218e8 add r0, pc, r0 */
/* @0x2218ec bx lr */
/* @0x2218f0 andseq r3, r3, r4, asr r3 */
/* @0x2218f4 andseq r3, r3, r4, asr #2 */
/* @0x2218f8 ldrsheq r3, [r3], -r8 */
/* @0x2218fc andseq r3, r3, r0, ror #6 */
/* @0x221900 andseq r3, r3, r4, asr #2 */
/* @0x221904 andseq r3, r3, r0, lsl #1 */
/* @0x221908 andseq r3, r3, r12, ror #5 */
/* @0x22190c andseq r3, r3, r12, lsl r2 */
/* @0x221910 andseq r3, r3, r0, asr #32 */
/* @0x221914 andseq r3, r3, r0, rrx */
/* @0x221918 andseq r3, r3, r12, asr #5 */
/* @0x22191c mulseq r3, r12, r2 */
/* @0x221920 andseq r3, r3, r4, lsl r3 */
/* @0x221924 andseq r3, r3, r4, asr r2 */
/* @0x221928 andseq r3, r3, r0, lsl #2 */
/* @0x22192c mulseq r3, r8, r0 */
/* @0x221930 andseq r3, r3, r8, asr r0 */
/* @0x221934 andseq r3, r3, r4, asr #2 */
/* @0x221938 ldrheq r3, [r3], -r12 */
/* @0x22193c andseq r3, r3, r8, asr r1 */

/* ── FUNC 0x221940 · _alutSetError · size=104 · insn=26 */
/* @0x221940 push {r4, lr} */
/* @0x221944 mov r4, r0 */
/* @0x221948 ldr r0, [pc, #0x48] */
/* @0x22194c add r0, pc, r0 */
/* @0x221950 bl 0xb6a24 <getenv@plt> */
/* @0x221954 cmp r0, #0 */
/* @0x221958 beq 0x221980 <_alutSetError+0x40> */
/* @0x22195c mov r0, r4 */
/* @0x221960 bl 0x221730 <alutGetErrorString> */
/* @0x221964 ldr r1, [pc, #0x30] */
/* @0x221968 add r1, pc, r1 */
/* @0x22196c mov r2, r0 */
/* @0x221970 ldr r0, [pc, #0x28] */
/* @0x221974 ldr r0, [pc, r0] */
/* @0x221978 add r0, r0, #168 */
/* @0x22197c bl 0xb68a4 <fprintf@plt> */
/* @0x221980 ldr r3, [pc, #0x1c] */
/* @0x221984 add r3, pc, r3 */
/* @0x221988 ldr r2, [r3] */
/* @0x22198c cmp r2, #0 */
/* @0x221990 streq r4, [r3] */
/* @0x221994 pop {r4, pc} */
/* @0x221998 mulseq r3, r0, r2 */
/* @0x22199c andseq r3, r3, r0, lsl #5 */
/* @0x2219a0 ldrsbeq pc, [r12], -r0 */
/* @0x2219a4 subseq r3, r3, r0, ror #21 */

/* ── FUNC 0x2219a8 · _alutSanityCheck · size=140 · insn=35 */
/* @0x2219a8 push {r3, r4, r5, lr} */
/* @0x2219ac ldr r3, [pc, #0x7c] */
/* @0x2219b0 ldr r4, [pc, r3] */
/* @0x2219b4 cmp r4, #0 */
/* @0x2219b8 beq 0x221a00 <_alutSanityCheck+0x58> */
/* @0x2219bc bl 0xb6a3c <alcGetCurrentContext@plt> */
/* @0x2219c0 subs r5, r0, #0 */
/* @0x2219c4 beq 0x221a20 <_alutSanityCheck+0x78> */
/* @0x2219c8 bl 0xb6a54 <alGetError@plt> */
/* @0x2219cc subs r4, r0, #0 */
/* @0x2219d0 bne 0x2219f0 <_alutSanityCheck+0x48> */
/* @0x2219d4 mov r0, r5 */
/* @0x2219d8 bl 0xb6b98 <alcGetContextsDevice@plt> */
/* @0x2219dc bl 0xb6ba4 <alcGetError@plt> */
/* @0x2219e0 cmp r0, #0 */
/* @0x2219e4 bne 0x221a10 <_alutSanityCheck+0x68> */
/* @0x2219e8 mov r0, #1 */
/* @0x2219ec pop {r3, r4, r5, pc} */
/* @0x2219f0 movw r0, #0x205 */
/* @0x2219f4 bl 0x221940 <_alutSetError> */
/* @0x2219f8 mov r0, #0 */
/* @0x2219fc pop {r3, r4, r5, pc} */
/* @0x221a00 movw r0, #0x203 */
/* @0x221a04 bl 0x221940 <_alutSetError> */
/* @0x221a08 mov r0, r4 */
/* @0x221a0c pop {r3, r4, r5, pc} */
/* @0x221a10 movw r0, #0x206 */
/* @0x221a14 bl 0x221940 <_alutSetError> */
/* @0x221a18 mov r0, r4 */
/* @0x221a1c pop {r3, r4, r5, pc} */
/* @0x221a20 mov r0, #516 */
/* @0x221a24 bl 0x221940 <_alutSetError> */
/* @0x221a28 mov r0, r5 */
/* @0x221a2c pop {r3, r4, r5, pc} */
/* @0x221a30 ldrheq r3, [r3], #-168 */

/* ── FUNC 0x221a34 · alutInit · size=220 · insn=55 */
/* @0x221a34 push {r3, r4, r5, r6, r7, lr} */
/* @0x221a38 ldr r4, [pc, #0xcc] */
/* @0x221a3c add r4, pc, r4 */
/* @0x221a40 ldr r6, [r4] */
/* @0x221a44 cmp r6, #0 */
/* @0x221a48 bne 0x221ab4 <alutInit+0x80> */
/* @0x221a4c rsbs r5, r1, #1 */
/* @0x221a50 movlo r5, #0 */
/* @0x221a54 cmp r0, #0 */
/* @0x221a58 eoreq r5, r5, #1 */
/* @0x221a5c cmp r5, #0 */
/* @0x221a60 bne 0x221aa4 <alutInit+0x70> */
/* @0x221a64 mov r0, r5 */
/* @0x221a68 bl 0xb6bb0 <alcOpenDevice@plt> */
/* @0x221a6c subs r7, r0, #0 */
/* @0x221a70 beq 0x221ae4 <alutInit+0xb0> */
/* @0x221a74 mov r1, r5 */
/* @0x221a78 bl 0xb6bbc <alcCreateContext@plt> */
/* @0x221a7c subs r5, r0, #0 */
/* @0x221a80 beq 0x221af4 <alutInit+0xc0> */
/* @0x221a84 bl 0xb6bc8 <alcMakeContextCurrent@plt> */
/* @0x221a88 subs r6, r0, #0 */
/* @0x221a8c beq 0x221ac4 <alutInit+0x90> */
/* @0x221a90 mov r3, #1 */
/* @0x221a94 str r5, [r4, #0x4] */
/* @0x221a98 mov r0, r3 */
/* @0x221a9c str r3, [r4] */
/* @0x221aa0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221aa4 movw r0, #0x202 */
/* @0x221aa8 bl 0x221940 <_alutSetError> */
/* @0x221aac mov r0, r6 */
/* @0x221ab0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221ab4 movw r0, #0x203 */
/* @0x221ab8 bl 0x221940 <_alutSetError> */
/* @0x221abc mov r0, #0 */
/* @0x221ac0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221ac4 mov r0, r5 */
/* @0x221ac8 bl 0xb6bd4 <alcDestroyContext@plt> */
/* @0x221acc mov r0, r7 */
/* @0x221ad0 bl 0xb6be0 <alcCloseDevice@plt> */
/* @0x221ad4 movw r0, #0x20a */
/* @0x221ad8 bl 0x221940 <_alutSetError> */
/* @0x221adc mov r0, r6 */
/* @0x221ae0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221ae4 movw r0, #0x207 */
/* @0x221ae8 bl 0x221940 <_alutSetError> */
/* @0x221aec mov r0, r7 */
/* @0x221af0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221af4 mov r0, r7 */
/* @0x221af8 bl 0xb6be0 <alcCloseDevice@plt> */
/* @0x221afc movw r0, #0x209 */
/* @0x221b00 bl 0x221940 <_alutSetError> */
/* @0x221b04 mov r0, r5 */
/* @0x221b08 pop {r3, r4, r5, r6, r7, pc} */
/* @0x221b0c subseq r3, r3, r12, lsr #20 */

/* ── FUNC 0x221b10 · alutInitWithoutContext · size=104 · insn=26 */
/* @0x221b10 ldr r3, [pc, #0x5c] */
/* @0x221b14 push {r4, lr} */
/* @0x221b18 add r3, pc, r3 */
/* @0x221b1c ldr r4, [r3] */
/* @0x221b20 cmp r4, #0 */
/* @0x221b24 bne 0x221b54 <alutInitWithoutContext+0x44> */
/* @0x221b28 rsbs r1, r1, #1 */
/* @0x221b2c movlo r1, #0 */
/* @0x221b30 cmp r0, #0 */
/* @0x221b34 movne r0, r1 */
/* @0x221b38 eoreq r0, r1, #1 */
/* @0x221b3c cmp r0, #0 */
/* @0x221b40 bne 0x221b64 <alutInitWithoutContext+0x54> */
/* @0x221b44 mov r2, #2 */
/* @0x221b48 mov r0, #1 */
/* @0x221b4c str r2, [r3] */
/* @0x221b50 pop {r4, pc} */
/* @0x221b54 movw r0, #0x203 */
/* @0x221b58 bl 0x221940 <_alutSetError> */
/* @0x221b5c mov r0, #0 */
/* @0x221b60 pop {r4, pc} */
/* @0x221b64 movw r0, #0x202 */
/* @0x221b68 bl 0x221940 <_alutSetError> */
/* @0x221b6c mov r0, r4 */
/* @0x221b70 pop {r4, pc} */
/* @0x221b74 subseq r3, r3, r0, asr r9 */

/* ── FUNC 0x221b78 · alutExit · size=208 · insn=52 */
/* @0x221b78 push {r4, r5, r6, lr} */
/* @0x221b7c ldr r5, [pc, #0xc0] */
/* @0x221b80 add r5, pc, r5 */
/* @0x221b84 ldr r4, [r5] */
/* @0x221b88 cmp r4, #0 */
/* @0x221b8c beq 0x221c04 <alutExit+0x8c> */
/* @0x221b90 cmp r4, #2 */
/* @0x221b94 beq 0x221bf4 <alutExit+0x7c> */
/* @0x221b98 bl 0x2219a8 <_alutSanityCheck> */
/* @0x221b9c cmp r0, #0 */
/* @0x221ba0 popeq {r4, r5, r6, pc} */
/* @0x221ba4 mov r0, #0 */
/* @0x221ba8 bl 0xb6bc8 <alcMakeContextCurrent@plt> */
/* @0x221bac subs r4, r0, #0 */
/* @0x221bb0 beq 0x221c14 <alutExit+0x9c> */
/* @0x221bb4 ldr r0, [r5, #0x4] */
/* @0x221bb8 bl 0xb6b98 <alcGetContextsDevice@plt> */
/* @0x221bbc mov r4, r0 */
/* @0x221bc0 ldr r0, [r5, #0x4] */
/* @0x221bc4 bl 0xb6bd4 <alcDestroyContext@plt> */
/* @0x221bc8 mov r0, r4 */
/* @0x221bcc bl 0xb6ba4 <alcGetError@plt> */
/* @0x221bd0 subs r6, r0, #0 */
/* @0x221bd4 bne 0x221c24 <alutExit+0xac> */
/* @0x221bd8 mov r0, r4 */
/* @0x221bdc bl 0xb6be0 <alcCloseDevice@plt> */
/* @0x221be0 subs r4, r0, #0 */
/* @0x221be4 beq 0x221c34 <alutExit+0xbc> */
/* @0x221be8 str r6, [r5] */
/* @0x221bec mov r0, #1 */
/* @0x221bf0 pop {r4, r5, r6, pc} */
/* @0x221bf4 mov r3, #0 */
/* @0x221bf8 mov r0, #1 */
/* @0x221bfc str r3, [r5] */
/* @0x221c00 pop {r4, r5, r6, pc} */
/* @0x221c04 movw r0, #0x203 */
/* @0x221c08 bl 0x221940 <_alutSetError> */
/* @0x221c0c mov r0, r4 */
/* @0x221c10 pop {r4, r5, r6, pc} */
/* @0x221c14 movw r0, #0x20a */
/* @0x221c18 bl 0x221940 <_alutSetError> */
/* @0x221c1c mov r0, r4 */
/* @0x221c20 pop {r4, r5, r6, pc} */
/* @0x221c24 movw r0, #0x20b */
/* @0x221c28 bl 0x221940 <_alutSetError> */
/* @0x221c2c mov r0, #0 */
/* @0x221c30 pop {r4, r5, r6, pc} */
/* @0x221c34 mov r0, #520 */
/* @0x221c38 bl 0x221940 <_alutSetError> */
/* @0x221c3c mov r0, r4 */
/* @0x221c40 pop {r4, r5, r6, pc} */
/* @0x221c44 subseq r3, r3, r8, ror #17 */

/* ── FUNC 0x221c48 · anon_221c48 · size=152 · insn=38 */
/* @0x221c48 push {r4, r5, r6, lr} */
/* @0x221c4c mov r4, r0 */
/* @0x221c50 ldrb r6, [r0] */
/* @0x221c54 mov r5, r2 */
/* @0x221c58 cmp r6, #0 */
/* @0x221c5c bne 0x221c9c <alutExit+0x124> */
/* @0x221c60 ldr r3, [r0, #0x8] */
/* @0x221c64 cmp r2, r3 */
/* @0x221c68 bhi 0x221c8c <alutExit+0x114> */
/* @0x221c6c mov r0, r1 */
/* @0x221c70 ldr r1, [r4, #0xc] */
/* @0x221c74 bl 0xb65bc <memcpy@plt> */
/* @0x221c78 ldr r3, [r4, #0xc] */
/* @0x221c7c mov r0, #1 */
/* @0x221c80 add r5, r3, r5 */
/* @0x221c84 str r5, [r4, #0xc] */
/* @0x221c88 pop {r4, r5, r6, pc} */
/* @0x221c8c movw r0, #0x211 */
/* @0x221c90 bl 0x221940 <_alutSetError> */
/* @0x221c94 mov r0, r6 */
/* @0x221c98 pop {r4, r5, r6, pc} */
/* @0x221c9c mov r0, r1 */
/* @0x221ca0 ldr r3, [r4, #0xc] */
/* @0x221ca4 mov r1, #1 */
/* @0x221ca8 bl 0xb68c8 <fread@plt> */
/* @0x221cac cmp r5, r0 */
/* @0x221cb0 beq 0x221cd8 <alutExit+0x160> */
/* @0x221cb4 ldr r2, [r4, #0xc] */
/* @0x221cb8 movw r3, #0x20e */
/* @0x221cbc movw r0, #0x211 */
/* @0x221cc0 ldrh r2, [r2, #12] */
/* @0x221cc4 tst r2, #64 */
/* @0x221cc8 movne r0, r3 */
/* @0x221ccc bl 0x221940 <_alutSetError> */
/* @0x221cd0 mov r0, #0 */
/* @0x221cd4 pop {r4, r5, r6, pc} */
/* @0x221cd8 mov r0, #1 */
/* @0x221cdc pop {r4, r5, r6, pc} */

/* ── FUNC 0x221ce0 · _alutInputStreamConstructFromFile · size=180 · insn=45 */
/* @0x221ce0 push {r4, r5, r6, r7, lr} */
/* @0x221ce4 mov r5, r0 */
/* @0x221ce8 sub sp, sp, #108 */
/* @0x221cec mov r0, #16 */
/* @0x221cf0 bl 0x222a98 <_alutMalloc> */
/* @0x221cf4 subs r4, r0, #0 */
/* @0x221cf8 beq 0x221d88 <_alutInputStreamConstructFromFile+0xa8> */
/* @0x221cfc mov r0, r5 */
/* @0x221d00 mov r1, sp */
/* @0x221d04 bl 0xb69f4 <stat@plt> */
/* @0x221d08 cmp r0, #0 */
/* @0x221d0c bne 0x221d68 <_alutInputStreamConstructFromFile+0x88> */
/* @0x221d10 ldr r1, [pc, #0x78] */
/* @0x221d14 mov r0, r5 */
/* @0x221d18 add r1, pc, r1 */
/* @0x221d1c bl 0xb6844 <fopen@plt> */
/* @0x221d20 subs r6, r0, #0 */
/* @0x221d24 beq 0x221d68 <_alutInputStreamConstructFromFile+0x88> */
/* @0x221d28 mov r0, r5 */
/* @0x221d2c bl 0xb6538 <strlen@plt> */
/* @0x221d30 add r0, r0, #1 */
/* @0x221d34 bl 0x222a98 <_alutMalloc> */
/* @0x221d38 subs r7, r0, #0 */
/* @0x221d3c beq 0x221d70 <_alutInputStreamConstructFromFile+0x90> */
/* @0x221d40 mov r3, #1 */
/* @0x221d44 mov r1, r5 */
/* @0x221d48 strb r3, [r4] */
/* @0x221d4c bl 0xb65a4 <strcpy@plt> */
/* @0x221d50 ldr r2, [sp, #0x30] */
/* @0x221d54 mov r3, r4 */
/* @0x221d58 stmib r4, {r0, r2, r6} */
/* @0x221d5c mov r0, r3 */
/* @0x221d60 add sp, sp, #108 */
/* @0x221d64 pop {r4, r5, r6, r7, pc} */
/* @0x221d68 movw r0, #0x20e */
/* @0x221d6c bl 0x221940 <_alutSetError> */
/* @0x221d70 mov r0, r4 */
/* @0x221d74 bl 0xb655c <free@plt> */
/* @0x221d78 mov r3, #0 */
/* @0x221d7c mov r0, r3 */
/* @0x221d80 add sp, sp, #108 */
/* @0x221d84 pop {r4, r5, r6, r7, pc} */
/* @0x221d88 mov r3, r4 */
/* @0x221d8c b 0x221d5c <_alutInputStreamConstructFromFile+0x7c> */
/* @0x221d90 andseq r5, r1, r0, ror #29 */

/* ── FUNC 0x221d94 · _alutInputStreamConstructFromMemory · size=48 · insn=12 */
/* @0x221d94 push {r3, r4, r5, lr} */
/* @0x221d98 mov r4, r0 */
/* @0x221d9c mov r0, #16 */
/* @0x221da0 mov r5, r1 */
/* @0x221da4 bl 0x222a98 <_alutMalloc> */
/* @0x221da8 cmp r0, #0 */
/* @0x221dac strne r5, [r0, #0x8] */
/* @0x221db0 strne r4, [r0, #0xc] */
/* @0x221db4 movne r3, #0 */
/* @0x221db8 strbne r3, [r0] */
/* @0x221dbc strne r3, [r0, #0x4] */
/* @0x221dc0 pop {r3, r4, r5, pc} */

/* ── FUNC 0x221dc4 · _alutInputGetData · size=8 · insn=2 */
/* @0x221dc4 ldr r0, [r0, #0xc] */
/* @0x221dc8 bx lr */

/* ── FUNC 0x221dcc · _alutInputStreamDestroy · size=76 · insn=19 */
/* @0x221dcc push {r3, r4, r5, lr} */
/* @0x221dd0 mov r4, r0 */
/* @0x221dd4 ldrb r3, [r0] */
/* @0x221dd8 cmp r3, #0 */
/* @0x221ddc moveq r5, #1 */
/* @0x221de0 bne 0x221e04 <_alutInputStreamDestroy+0x38> */
/* @0x221de4 ldr r0, [r4, #0x4] */
/* @0x221de8 cmp r0, #0 */
/* @0x221dec beq 0x221df4 <_alutInputStreamDestroy+0x28> */
/* @0x221df0 bl 0xb655c <free@plt> */
/* @0x221df4 mov r0, r4 */
/* @0x221df8 bl 0xb655c <free@plt> */
/* @0x221dfc mov r0, r5 */
/* @0x221e00 pop {r3, r4, r5, pc} */
/* @0x221e04 ldr r0, [r0, #0xc] */
/* @0x221e08 bl 0xb6850 <fclose@plt> */
/* @0x221e0c rsbs r5, r0, #1 */
/* @0x221e10 movlo r5, #0 */
/* @0x221e14 b 0x221de4 <_alutInputStreamDestroy+0x18> */

/* ── FUNC 0x221e18 · _alutInputStreamGetFileName · size=8 · insn=2 */
/* @0x221e18 ldr r0, [r0, #0x4] */
/* @0x221e1c bx lr */

/* ── FUNC 0x221e20 · _alutInputStreamGetRemainingLength · size=8 · insn=2 */
/* @0x221e20 ldr r0, [r0, #0x8] */
/* @0x221e24 bx lr */

/* ── FUNC 0x221e28 · _alutInputStreamEOF · size=80 · insn=20 */
/* @0x221e28 push {r3, r4, r5, lr} */
/* @0x221e2c mov r4, r0 */
/* @0x221e30 ldrb r3, [r0] */
/* @0x221e34 cmp r3, #0 */
/* @0x221e38 bne 0x221e4c <_alutInputStreamEOF+0x24> */
/* @0x221e3c ldr r0, [r0, #0x8] */
/* @0x221e40 rsbs r0, r0, #1 */
/* @0x221e44 movlo r0, #0 */
/* @0x221e48 pop {r3, r4, r5, pc} */
/* @0x221e4c ldr r0, [r0, #0xc] */
/* @0x221e50 bl 0xb6880 <fgetc@plt> */
/* @0x221e54 cmn r0, #1 */
/* @0x221e58 mov r5, r0 */
/* @0x221e5c beq 0x221e68 <_alutInputStreamEOF+0x40> */
/* @0x221e60 ldr r1, [r4, #0xc] */
/* @0x221e64 bl 0xb6bec <ungetc@plt> */
/* @0x221e68 cmn r5, #1 */
/* @0x221e6c movne r0, #0 */
/* @0x221e70 moveq r0, #1 */
/* @0x221e74 pop {r3, r4, r5, pc} */

/* ── FUNC 0x221e78 · _alutInputStreamRead · size=80 · insn=20 */
/* @0x221e78 push {r4, r5, r6, lr} */
/* @0x221e7c mov r6, r0 */
/* @0x221e80 mov r0, r1 */
/* @0x221e84 mov r4, r1 */
/* @0x221e88 bl 0x222a98 <_alutMalloc> */
/* @0x221e8c subs r5, r0, #0 */
/* @0x221e90 beq 0x221eb4 <_alutInputStreamRead+0x3c> */
/* @0x221e94 mov r2, r4 */
/* @0x221e98 mov r0, r6 */
/* @0x221e9c mov r1, r5 */
/* @0x221ea0 bl 0x221c48 <alutExit+0xd0> */
/* @0x221ea4 subs r4, r0, #0 */
/* @0x221ea8 mov r0, r5 */
/* @0x221eac beq 0x221ebc <_alutInputStreamRead+0x44> */
/* @0x221eb0 pop {r4, r5, r6, pc} */
/* @0x221eb4 mov r0, r5 */
/* @0x221eb8 pop {r4, r5, r6, pc} */
/* @0x221ebc bl 0xb655c <free@plt> */
/* @0x221ec0 mov r0, r4 */
/* @0x221ec4 pop {r4, r5, r6, pc} */

/* ── FUNC 0x221ec8 · _alutInputStreamSkip · size=84 · insn=21 */
/* @0x221ec8 push {r4, r5, r6, lr} */
/* @0x221ecc subs r4, r1, #0 */
/* @0x221ed0 mov r5, r0 */
/* @0x221ed4 bne 0x221ee0 <_alutInputStreamSkip+0x18> */
/* @0x221ed8 mov r0, #1 */
/* @0x221edc pop {r4, r5, r6, pc} */
/* @0x221ee0 mov r0, r4 */
/* @0x221ee4 bl 0x222a98 <_alutMalloc> */
/* @0x221ee8 subs r6, r0, #0 */
/* @0x221eec beq 0x221f14 <_alutInputStreamSkip+0x4c> */
/* @0x221ef0 mov r2, r4 */
/* @0x221ef4 mov r1, r6 */
/* @0x221ef8 mov r0, r5 */
/* @0x221efc bl 0x221c48 <alutExit+0xd0> */
/* @0x221f00 mov r4, r0 */
/* @0x221f04 mov r0, r6 */
/* @0x221f08 bl 0xb655c <free@plt> */
/* @0x221f0c mov r0, r4 */
/* @0x221f10 pop {r4, r5, r6, pc} */
/* @0x221f14 mov r0, r6 */
/* @0x221f18 pop {r4, r5, r6, pc} */

/* ── FUNC 0x221f1c · _alutInputStreamReadUInt16LE · size=56 · insn=14 */
/* @0x221f1c push {r4, lr} */
/* @0x221f20 sub sp, sp, #8 */
/* @0x221f24 mov r2, #2 */
/* @0x221f28 mov r4, r1 */
/* @0x221f2c add r1, sp, #4 */
/* @0x221f30 bl 0x221c48 <alutExit+0xd0> */
/* @0x221f34 cmp r0, #0 */
/* @0x221f38 ldrbne r3, [sp, #0x4] */
/* @0x221f3c movne r0, #1 */
/* @0x221f40 ldrbne r2, [sp, #0x5] */
/* @0x221f44 orrne r3, r3, r2, lsl #8 */
/* @0x221f48 strhne r3, [r4] */
/* @0x221f4c add sp, sp, #8 */
/* @0x221f50 pop {r4, pc} */

/* ── FUNC 0x221f54 · _alutInputStreamReadInt32BE · size=80 · insn=20 */
/* @0x221f54 push {r4, lr} */
/* @0x221f58 sub sp, sp, #8 */
/* @0x221f5c mov r2, #4 */
/* @0x221f60 mov r4, r1 */
/* @0x221f64 add r1, sp, r2 */
/* @0x221f68 bl 0x221c48 <alutExit+0xd0> */
/* @0x221f6c cmp r0, #0 */
/* @0x221f70 beq 0x221f9c <_alutInputStreamReadInt32BE+0x48> */
/* @0x221f74 ldrb r3, [sp, #0x5] */
/* @0x221f78 mov r0, #1 */
/* @0x221f7c ldrb r12, [sp, #0x4] */
/* @0x221f80 ldrb r1, [sp, #0x7] */
/* @0x221f84 lsl r3, r3, #16 */
/* @0x221f88 ldrb r2, [sp, #0x6] */
/* @0x221f8c orr r3, r3, r12, lsl #24 */
/* @0x221f90 orr r3, r3, r1 */
/* @0x221f94 orr r3, r3, r2, lsl #8 */
/* @0x221f98 str r3, [r4] */
/* @0x221f9c add sp, sp, #8 */
/* @0x221fa0 pop {r4, pc} */

/* ── FUNC 0x221fa4 · _alutInputStreamReadUInt32LE · size=80 · insn=20 */
/* @0x221fa4 push {r4, lr} */
/* @0x221fa8 sub sp, sp, #8 */
/* @0x221fac mov r2, #4 */
/* @0x221fb0 mov r4, r1 */
/* @0x221fb4 add r1, sp, r2 */
/* @0x221fb8 bl 0x221c48 <alutExit+0xd0> */
/* @0x221fbc cmp r0, #0 */
/* @0x221fc0 beq 0x221fec <_alutInputStreamReadUInt32LE+0x48> */
/* @0x221fc4 ldrb r3, [sp, #0x6] */
/* @0x221fc8 mov r0, #1 */
/* @0x221fcc ldrb r12, [sp, #0x7] */
/* @0x221fd0 ldrb r1, [sp, #0x4] */
/* @0x221fd4 lsl r3, r3, #16 */
/* @0x221fd8 ldrb r2, [sp, #0x5] */
/* @0x221fdc orr r3, r3, r12, lsl #24 */
/* @0x221fe0 orr r3, r3, r1 */
/* @0x221fe4 orr r3, r3, r2, lsl #8 */
/* @0x221fe8 str r3, [r4] */
/* @0x221fec add sp, sp, #8 */
/* @0x221ff0 pop {r4, pc} */

/* ── FUNC 0x221ff4 · anon_221ff4 · size=1496 · insn=374 */
/* @0x221ff4 cmn r0, #1 */
/* @0x221ff8 bxeq lr */
/* @0x221ffc ldr r3, [pc, #0x34] */
/* @0x222000 ldr r3, [pc, r3] */
/* @0x222004 ldr r3, [r3] */
/* @0x222008 uxtab r3, r3, r0 */
/* @0x22200c ldrb r3, [r3, #0x1] */
/* @0x222010 tst r3, #1 */
/* @0x222014 bxeq lr */
/* @0x222018 cmp r0, #255 */
/* @0x22201c bxhi lr */
/* @0x222020 ldr r3, [pc, #0x14] */
/* @0x222024 ldr r3, [pc, r3] */
/* @0x222028 ldr r3, [r3] */
/* @0x22202c add r0, r3, r0, lsl #1 */
/* @0x222030 ldrsh r0, [r0, #2] */
/* @0x222034 bx lr */
/* @0x222038 andseq r11, r12, r0, lsl #19 */
/* @0x22203c andseq r11, r12, r0, ror #18 */
/* @0x222040 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x222044 sub sp, sp, #68 */
/* @0x222048 mov r4, r0 */
/* @0x22204c bl 0x221e18 <_alutInputStreamGetFileName> */
/* @0x222050 ldr r5, [pc, #0x550] */
/* @0x222054 add r5, pc, r5 */
/* @0x222058 cmp r0, #0 */
/* @0x22205c beq 0x2220f4 <_alutInputStreamReadUInt32LE+0x150> */
/* @0x222060 ldrb r2, [r0] */
/* @0x222064 cmp r2, #0 */
/* @0x222068 beq 0x2223c0 <_alutInputStreamReadUInt32LE+0x41c> */
/* @0x22206c add r2, r0, #1 */
/* @0x222070 mov r3, r2 */
/* @0x222074 add r2, r2, #1 */
/* @0x222078 ldrb r1, [r3] */
/* @0x22207c cmp r1, #0 */
/* @0x222080 bne 0x222070 <_alutInputStreamReadUInt32LE+0xcc> */
/* @0x222084 rsb lr, r0, r3 */
/* @0x222088 ldr r2, [pc, #0x51c] */
/* @0x22208c add r2, pc, r2 */
/* @0x222090 add r2, r2, #1 */
/* @0x222094 mov r1, r2 */
/* @0x222098 add r2, r2, #1 */
/* @0x22209c ldrb r0, [r1] */
/* @0x2220a0 cmp r0, #0 */
/* @0x2220a4 bne 0x222094 <_alutInputStreamReadUInt32LE+0xf0> */
/* @0x2220a8 ldr r12, [pc, #0x500] */
/* @0x2220ac add r12, pc, r12 */
/* @0x2220b0 rsb r12, r12, r1 */
/* @0x2220b4 cmp r12, lr */
/* @0x2220b8 bgt 0x2220f4 <_alutInputStreamReadUInt32LE+0x150> */
/* @0x2220bc ldr r9, [pc, #0x4f0] */
/* @0x2220c0 mov r6, r1 */
/* @0x2220c4 mov r7, r3 */
/* @0x2220c8 add r9, pc, r9 */
/* @0x2220cc b 0x2220d8 <_alutInputStreamReadUInt32LE+0x134> */
/* @0x2220d0 cmp r6, r9 */
/* @0x2220d4 beq 0x222270 <_alutInputStreamReadUInt32LE+0x2cc> */
/* @0x2220d8 ldrb r0, [r6, #-0x1]! */
/* @0x2220dc bl 0x221ff4 <_alutInputStreamReadUInt32LE+0x50> */
/* @0x2220e0 mov r8, r0 */
/* @0x2220e4 ldrb r0, [r7, #-0x1]! */
/* @0x2220e8 bl 0x221ff4 <_alutInputStreamReadUInt32LE+0x50> */
/* @0x2220ec cmp r8, r0 */
/* @0x2220f0 beq 0x2220d0 <_alutInputStreamReadUInt32LE+0x12c> */
/* @0x2220f4 mov r0, r4 */
/* @0x2220f8 add r1, sp, #40 */
/* @0x2220fc bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222100 cmp r0, #0 */
/* @0x222104 beq 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222108 ldr r2, [sp, #0x28] */
/* @0x22210c movw r3, #0x4646 */
/* @0x222110 movt r3, #0x5249 */
/* @0x222114 cmp r2, r3 */
/* @0x222118 beq 0x2222b4 <_alutInputStreamReadUInt32LE+0x310> */
/* @0x22211c movw r3, #0x6e64 */
/* @0x222120 movt r3, #0x2e73 */
/* @0x222124 cmp r2, r3 */
/* @0x222128 bne 0x22225c <_alutInputStreamReadUInt32LE+0x2b8> */
/* @0x22212c mov r0, r4 */
/* @0x222130 add r1, sp, #44 */
/* @0x222134 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222138 cmp r0, #0 */
/* @0x22213c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222140 mov r0, r4 */
/* @0x222144 add r1, sp, #48 */
/* @0x222148 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x22214c cmp r0, #0 */
/* @0x222150 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222154 mov r0, r4 */
/* @0x222158 add r1, sp, #52 */
/* @0x22215c bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222160 cmp r0, #0 */
/* @0x222164 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222168 mov r0, r4 */
/* @0x22216c add r1, sp, #56 */
/* @0x222170 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222174 cmp r0, #0 */
/* @0x222178 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22217c mov r0, r4 */
/* @0x222180 add r1, sp, #60 */
/* @0x222184 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222188 cmp r0, #0 */
/* @0x22218c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222190 ldr r6, [sp, #0x30] */
/* @0x222194 cmn r6, #1 */
/* @0x222198 ldrne r1, [sp, #0x2c] */
/* @0x22219c beq 0x222530 <_alutInputStreamReadUInt32LE+0x58c> */
/* @0x2221a0 cmp r1, #23 */
/* @0x2221a4 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221a8 cmp r6, #0 */
/* @0x2221ac beq 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221b0 ldr r3, [sp, #0x38] */
/* @0x2221b4 cmp r3, #0 */
/* @0x2221b8 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221bc ldr r3, [sp, #0x3c] */
/* @0x2221c0 cmp r3, #0 */
/* @0x2221c4 ble 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x2221c8 sub r1, r1, #24 */
/* @0x2221cc mov r0, r4 */
/* @0x2221d0 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2221d4 cmp r0, #0 */
/* @0x2221d8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2221dc ldr r3, [sp, #0x34] */
/* @0x2221e0 sub r3, r3, #1 */
/* @0x2221e4 cmp r3, #26 */
/* @0x2221e8 addls pc, pc, r3, lsl #2 */
/* @0x2221ec b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2221f0 b 0x22242c <_alutInputStreamReadUInt32LE+0x488> */
/* @0x2221f4 b 0x2223cc <_alutInputStreamReadUInt32LE+0x428> */
/* @0x2221f8 b 0x22240c <_alutInputStreamReadUInt32LE+0x468> */
/* @0x2221fc b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222200 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222204 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222208 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22220c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222210 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222214 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222218 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22221c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222220 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222224 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222228 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22222c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222230 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222234 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222238 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22223c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222240 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222244 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222248 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x22224c b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222250 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222254 b 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x222258 b 0x22241c <_alutInputStreamReadUInt32LE+0x478> */
/* @0x22225c movw r0, #0x20f */
/* @0x222260 bl 0x221940 <_alutSetError> */
/* @0x222264 mov r0, #0 */
/* @0x222268 add sp, sp, #68 */
/* @0x22226c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x222270 mov r0, r4 */
/* @0x222274 bl 0x221e20 <_alutInputStreamGetRemainingLength> */
/* @0x222278 mov r5, r0 */
/* @0x22227c mov r0, r4 */
/* @0x222280 mov r1, r5 */
/* @0x222284 bl 0x221e78 <_alutInputStreamRead> */
/* @0x222288 subs r3, r0, #0 */
/* @0x22228c beq 0x222560 <_alutInputStreamReadUInt32LE+0x5bc> */
/* @0x222290 mov r1, r5 */
/* @0x222294 mov r2, #1 */
/* @0x222298 mov r3, #0 */
/* @0x22229c movt r3, #0x45fa */
/* @0x2222a0 str r3, [sp] */
/* @0x2222a4 mov r3, #8 */
/* @0x2222a8 bl 0x221508 <_alutCodecLinear> */
/* @0x2222ac add sp, sp, #68 */
/* @0x2222b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2222b4 add r6, sp, #48 */
/* @0x2222b8 mov r0, r4 */
/* @0x2222bc mov r1, r6 */
/* @0x2222c0 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x2222c4 cmp r0, #0 */
/* @0x2222c8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2222cc add r7, sp, #52 */
/* @0x2222d0 mov r0, r4 */
/* @0x2222d4 mov r1, r7 */
/* @0x2222d8 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x2222dc cmp r0, #0 */
/* @0x2222e0 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2222e4 ldr r2, [sp, #0x34] */
/* @0x2222e8 movw r3, #0x5645 */
/* @0x2222ec movt r3, #0x5741 */
/* @0x2222f0 cmp r2, r3 */
/* @0x2222f4 bne 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2222f8 ldr r3, [pc, #0x2b8] */
/* @0x2222fc mov r2, #0 */
/* @0x222300 str r2, [sp, #0x18] */
/* @0x222304 movw r8, #0x7420 */
/* @0x222308 movw r9, #0x7461 */
/* @0x22230c movt r8, #0x666d */
/* @0x222310 ldr r3, [r5, r3] */
/* @0x222314 movt r9, #0x6461 */
/* @0x222318 add r11, sp, #34 */
/* @0x22231c add r10, sp, #36 */
/* @0x222320 add r12, sp, #60 */
/* @0x222324 str r12, [sp, #0x14] */
/* @0x222328 str r3, [sp, #0xc] */
/* @0x22232c add r3, sp, #56 */
/* @0x222330 ldr r2, [sp, #0xc] */
/* @0x222334 str r3, [sp, #0x10] */
/* @0x222338 str r2, [sp, #0x1c] */
/* @0x22233c mov r0, r4 */
/* @0x222340 mov r1, r7 */
/* @0x222344 bl 0x221f54 <_alutInputStreamReadInt32BE> */
/* @0x222348 cmp r0, #0 */
/* @0x22234c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222350 mov r0, r4 */
/* @0x222354 mov r1, r6 */
/* @0x222358 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x22235c cmp r0, #0 */
/* @0x222360 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222364 ldr r3, [sp, #0x34] */
/* @0x222368 cmp r3, r8 */
/* @0x22236c beq 0x22244c <_alutInputStreamReadUInt32LE+0x4a8> */
/* @0x222370 cmp r3, r9 */
/* @0x222374 beq 0x222568 <_alutInputStreamReadUInt32LE+0x5c4> */
/* @0x222378 mov r0, r4 */
/* @0x22237c ldr r1, [sp, #0x30] */
/* @0x222380 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x222384 cmp r0, #0 */
/* @0x222388 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22238c ldr r3, [sp, #0x30] */
/* @0x222390 tst r3, #1 */
/* @0x222394 beq 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x222398 mov r0, r4 */
/* @0x22239c bl 0x221e28 <_alutInputStreamEOF> */
/* @0x2223a0 cmp r0, #0 */
/* @0x2223a4 bne 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x2223a8 mov r0, r4 */
/* @0x2223ac mov r1, #1 */
/* @0x2223b0 bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2223b4 cmp r0, #0 */
/* @0x2223b8 bne 0x22233c <_alutInputStreamReadUInt32LE+0x398> */
/* @0x2223bc b 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2223c0 mov r3, r0 */
/* @0x2223c4 mov lr, r2 */
/* @0x2223c8 b 0x222088 <_alutInputStreamReadUInt32LE+0xe4> */
/* @0x2223cc ldr r3, [pc, #0x1e8] */
/* @0x2223d0 mov r7, #8 */
/* @0x2223d4 ldr r5, [r5, r3] */
/* @0x2223d8 mov r0, r4 */
/* @0x2223dc mov r1, r6 */
/* @0x2223e0 bl 0x221e78 <_alutInputStreamRead> */
/* @0x2223e4 cmp r0, #0 */
/* @0x2223e8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2223ec vldr s14, [sp, #56] */
/* @0x2223f0 vcvt.f32.s32 s15, s14 */
/* @0x2223f4 mov r1, r6 */
/* @0x2223f8 ldr r2, [sp, #0x3c] */
/* @0x2223fc mov r3, r7 */
/* @0x222400 vstr s15, [sp] */
/* @0x222404 blx r5 */
/* @0x222408 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x22240c ldr r3, [pc, #0x1ac] */
/* @0x222410 mov r7, #16 */
/* @0x222414 ldr r5, [r5, r3] */
/* @0x222418 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22241c ldr r3, [pc, #0x1a0] */
/* @0x222420 mov r7, #16 */
/* @0x222424 ldr r5, [r5, r3] */
/* @0x222428 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22242c ldr r3, [pc, #0x194] */
/* @0x222430 mov r7, #16 */
/* @0x222434 ldr r5, [r5, r3] */
/* @0x222438 b 0x2223d8 <_alutInputStreamReadUInt32LE+0x434> */
/* @0x22243c mov r0, #528 */
/* @0x222440 bl 0x221940 <_alutSetError> */
/* @0x222444 mov r0, #0 */
/* @0x222448 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x22244c ldr r3, [sp, #0x30] */
/* @0x222450 cmp r3, #15 */
/* @0x222454 bls 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x222458 mov r0, r4 */
/* @0x22245c mov r1, r11 */
/* @0x222460 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x222464 cmp r0, #0 */
/* @0x222468 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x22246c mov r0, r4 */
/* @0x222470 mov r1, r10 */
/* @0x222474 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x222478 cmp r0, #0 */
/* @0x22247c beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222480 mov r0, r4 */
/* @0x222484 add r1, sp, #56 */
/* @0x222488 bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x22248c cmp r0, #0 */
/* @0x222490 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222494 mov r0, r4 */
/* @0x222498 add r1, sp, #60 */
/* @0x22249c bl 0x221fa4 <_alutInputStreamReadUInt32LE> */
/* @0x2224a0 cmp r0, #0 */
/* @0x2224a4 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224a8 mov r0, r4 */
/* @0x2224ac add r1, sp, #38 */
/* @0x2224b0 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x2224b4 cmp r0, #0 */
/* @0x2224b8 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224bc mov r0, r4 */
/* @0x2224c0 add r1, sp, #44 */
/* @0x2224c4 bl 0x221f1c <_alutInputStreamReadUInt16LE> */
/* @0x2224c8 cmp r0, #0 */
/* @0x2224cc beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224d0 ldr r1, [sp, #0x30] */
/* @0x2224d4 mov r0, r4 */
/* @0x2224d8 sub r1, r1, #16 */
/* @0x2224dc bl 0x221ec8 <_alutInputStreamSkip> */
/* @0x2224e0 cmp r0, #0 */
/* @0x2224e4 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x2224e8 ldrh r3, [sp, #34] */
/* @0x2224ec cmp r3, #1 */
/* @0x2224f0 beq 0x222550 <_alutInputStreamReadUInt32LE+0x5ac> */
/* @0x2224f4 cmp r3, #7 */
/* @0x2224f8 bne 0x22243c <_alutInputStreamReadUInt32LE+0x498> */
/* @0x2224fc ldrh r2, [sp, #44] */
/* @0x222500 mov r3, #1 */
/* @0x222504 str r3, [sp, #0x18] */
/* @0x222508 ldr r3, [pc, #0xb8] */
/* @0x22250c lsl r2, r2, #1 */
/* @0x222510 strh r2, [sp, #44] */
/* @0x222514 ldr r3, [r5, r3] */
/* @0x222518 str r3, [sp, #0x1c] */
/* @0x22251c b 0x22238c <_alutInputStreamReadUInt32LE+0x3e8> */
/* @0x222520 movw r0, #0x211 */
/* @0x222524 bl 0x221940 <_alutSetError> */
/* @0x222528 mov r0, #0 */
/* @0x22252c b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222530 mov r0, r4 */
/* @0x222534 movw r6, #0xffe8 */
/* @0x222538 bl 0x221e20 <_alutInputStreamGetRemainingLength> */
/* @0x22253c ldr r1, [sp, #0x2c] */
/* @0x222540 movt r6, #0xffff */
/* @0x222544 rsb r6, r1, r6 */
/* @0x222548 add r6, r6, r0 */
/* @0x22254c b 0x2221a0 <_alutInputStreamReadUInt32LE+0x1fc> */
/* @0x222550 ldr r2, [sp, #0xc] */
/* @0x222554 str r3, [sp, #0x18] */
/* @0x222558 str r2, [sp, #0x1c] */
/* @0x22255c b 0x22238c <_alutInputStreamReadUInt32LE+0x3e8> */
/* @0x222560 mov r0, r3 */
/* @0x222564 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x222568 ldr r12, [sp, #0x18] */
/* @0x22256c cmp r12, #0 */
/* @0x222570 beq 0x222520 <_alutInputStreamReadUInt32LE+0x57c> */
/* @0x222574 mov r0, r4 */
/* @0x222578 bl 0x221dc4 <_alutInputGetData> */
/* @0x22257c cmp r0, #0 */
/* @0x222580 beq 0x222264 <_alutInputStreamReadUInt32LE+0x2c0> */
/* @0x222584 vldr s14, [sp, #56] */
/* @0x222588 vcvt.f32.u32 s15, s14 */
/* @0x22258c ldr r1, [sp, #0x30] */
/* @0x222590 ldrh r2, [sp, #36] */
/* @0x222594 ldrh r3, [sp, #44] */
/* @0x222598 ldr r12, [sp, #0x1c] */
/* @0x22259c vstr s15, [sp] */
/* @0x2225a0 blx r12 */
/* @0x2225a4 b 0x222268 <_alutInputStreamReadUInt32LE+0x2c4> */
/* @0x2225a8 ldrsheq pc, [r12], -r12 */
/* @0x2225ac andseq r2, r3, r12, ror #22 */
/* @0x2225b0 andseq r2, r3, r12, asr #22 */
/* @0x2225b4 andseq r2, r3, r0, lsr r11 */
/* @0x2225b8 .word 0xfffff7f8 */
/* @0x2225bc .word 0xfffff7fc */
/* @0x2225c0 .word 0xfffff800 */
/* @0x2225c4 .word 0xfffff804 */
/* @0x2225c8 .word 0xfffff808 */

/* ── FUNC 0x2225cc · _alutCreateBufferFromInputStream · size=72 · insn=18 */
/* @0x2225cc push {r3, r4, r5, lr} */
/* @0x2225d0 subs r5, r0, #0 */
/* @0x2225d4 beq 0x22260c <_alutCreateBufferFromInputStream+0x40> */
/* @0x2225d8 bl 0x222040 <_alutInputStreamReadUInt32LE+0x9c> */
/* @0x2225dc mov r4, r0 */
/* @0x2225e0 mov r0, r5 */
/* @0x2225e4 bl 0x221dcc <_alutInputStreamDestroy> */
/* @0x2225e8 cmp r4, #0 */
/* @0x2225ec beq 0x22260c <_alutCreateBufferFromInputStream+0x40> */
/* @0x2225f0 mov r0, r4 */
/* @0x2225f4 bl 0x221424 <_alutPassBufferData> */
/* @0x2225f8 mov r5, r0 */
/* @0x2225fc mov r0, r4 */
/* @0x222600 bl 0x2213b8 <_alutBufferDataDestroy> */
/* @0x222604 mov r0, r5 */
/* @0x222608 pop {r3, r4, r5, pc} */
/* @0x22260c mov r0, #0 */
/* @0x222610 pop {r3, r4, r5, pc} */

/* ── FUNC 0x222614 · alutCreateBufferFromFile · size=36 · insn=9 */
/* @0x222614 push {r4, lr} */
/* @0x222618 mov r4, r0 */
/* @0x22261c bl 0x2219a8 <_alutSanityCheck> */
/* @0x222620 cmp r0, #0 */
/* @0x222624 popeq {r4, pc} */
/* @0x222628 mov r0, r4 */
/* @0x22262c bl 0x221ce0 <_alutInputStreamConstructFromFile> */
/* @0x222630 pop {r4, lr} */
/* @0x222634 b 0x2225cc <_alutCreateBufferFromInputStream> */

/* ── FUNC 0x222638 · alutCreateBufferFromFileImage · size=44 · insn=11 */
/* @0x222638 push {r3, r4, r5, lr} */
/* @0x22263c mov r5, r0 */
/* @0x222640 mov r4, r1 */
/* @0x222644 bl 0x2219a8 <_alutSanityCheck> */
/* @0x222648 cmp r0, #0 */
/* @0x22264c popeq {r3, r4, r5, pc} */
/* @0x222650 mov r0, r5 */
/* @0x222654 mov r1, r4 */
/* @0x222658 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x22265c pop {r3, r4, r5, lr} */
/* @0x222660 b 0x2225cc <_alutCreateBufferFromInputStream> */

/* ── FUNC 0x222664 · _alutLoadMemoryFromInputStream · size=180 · insn=45 */
/* @0x222664 push {r4, r5, r6, r7, r8, lr} */
/* @0x222668 subs r8, r0, #0 */
/* @0x22266c sub sp, sp, #8 */
/* @0x222670 mov r5, r1 */
/* @0x222674 mov r7, r2 */
/* @0x222678 mov r6, r3 */
/* @0x22267c beq 0x222704 <_alutLoadMemoryFromInputStream+0xa0> */
/* @0x222680 bl 0x222040 <_alutInputStreamReadUInt32LE+0x9c> */
/* @0x222684 subs r4, r0, #0 */
/* @0x222688 mov r0, r8 */
/* @0x22268c beq 0x22270c <_alutLoadMemoryFromInputStream+0xa8> */
/* @0x222690 bl 0x221dcc <_alutInputStreamDestroy> */
/* @0x222694 mov r0, r4 */
/* @0x222698 add r1, sp, #4 */
/* @0x22269c bl 0x2213ec <_alutGetFormat> */
/* @0x2226a0 subs r8, r0, #0 */
/* @0x2226a4 beq 0x2226f0 <_alutLoadMemoryFromInputStream+0x8c> */
/* @0x2226a8 cmp r7, #0 */
/* @0x2226ac beq 0x2226bc <_alutLoadMemoryFromInputStream+0x58> */
/* @0x2226b0 mov r0, r4 */
/* @0x2226b4 bl 0x2213dc <_alutBufferDataGetLength> */
/* @0x2226b8 str r0, [r7] */
/* @0x2226bc cmp r5, #0 */
/* @0x2226c0 ldrne r3, [sp, #0x4] */
/* @0x2226c4 strne r3, [r5] */
/* @0x2226c8 cmp r6, #0 */
/* @0x2226cc beq 0x2226dc <_alutLoadMemoryFromInputStream+0x78> */
/* @0x2226d0 mov r0, r4 */
/* @0x2226d4 bl 0x2213e4 <_alutBufferDataGetSampleFrequency> */
/* @0x2226d8 str r0, [r6] */
/* @0x2226dc mov r0, r4 */
/* @0x2226e0 bl 0x2213c8 <_alutBufferDataGetData> */
/* @0x2226e4 mov r8, r0 */
/* @0x2226e8 mov r0, r4 */
/* @0x2226ec bl 0x2213d0 <_alutBufferDataDetachData> */
/* @0x2226f0 mov r0, r4 */
/* @0x2226f4 bl 0x2213b8 <_alutBufferDataDestroy> */
/* @0x2226f8 mov r0, r8 */
/* @0x2226fc add sp, sp, #8 */
/* @0x222700 pop {r4, r5, r6, r7, r8, pc} */
/* @0x222704 mov r0, r8 */
/* @0x222708 b 0x2226fc <_alutLoadMemoryFromInputStream+0x98> */
/* @0x22270c bl 0x221dcc <_alutInputStreamDestroy> */
/* @0x222710 mov r0, r4 */
/* @0x222714 b 0x2226fc <_alutLoadMemoryFromInputStream+0x98> */

/* ── FUNC 0x222718 · alutLoadMemoryFromFile · size=60 · insn=15 */
/* @0x222718 push {r4, r5, r6, r7, r8, lr} */
/* @0x22271c mov r7, r0 */
/* @0x222720 mov r6, r1 */
/* @0x222724 mov r5, r2 */
/* @0x222728 mov r4, r3 */
/* @0x22272c bl 0x2219a8 <_alutSanityCheck> */
/* @0x222730 cmp r0, #0 */
/* @0x222734 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x222738 mov r0, r7 */
/* @0x22273c bl 0x221ce0 <_alutInputStreamConstructFromFile> */
/* @0x222740 mov r1, r6 */
/* @0x222744 mov r2, r5 */
/* @0x222748 mov r3, r4 */
/* @0x22274c pop {r4, r5, r6, r7, r8, lr} */
/* @0x222750 b 0x222664 <_alutLoadMemoryFromInputStream> */

/* ── FUNC 0x222754 · alutLoadMemoryFromFileImage · size=68 · insn=17 */
/* @0x222754 push {r4, r5, r6, r7, r8, lr} */
/* @0x222758 mov r7, r0 */
/* @0x22275c mov r8, r1 */
/* @0x222760 mov r6, r2 */
/* @0x222764 mov r5, r3 */
/* @0x222768 ldr r4, [sp, #0x18] */
/* @0x22276c bl 0x2219a8 <_alutSanityCheck> */
/* @0x222770 cmp r0, #0 */
/* @0x222774 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x222778 mov r1, r8 */
/* @0x22277c mov r0, r7 */
/* @0x222780 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x222784 mov r1, r6 */
/* @0x222788 mov r2, r5 */
/* @0x22278c mov r3, r4 */
/* @0x222790 pop {r4, r5, r6, r7, r8, lr} */
/* @0x222794 b 0x222664 <_alutLoadMemoryFromInputStream> */

/* ── FUNC 0x222798 · alutLoadWAVFile · size=96 · insn=24 */
/* @0x222798 push {r4, r5, r6, r7, r8, lr} */
/* @0x22279c sub sp, sp, #8 */
/* @0x2227a0 mov r7, r3 */
/* @0x2227a4 mov r8, r1 */
/* @0x2227a8 mov r6, r2 */
/* @0x2227ac ldr r5, [sp, #0x20] */
/* @0x2227b0 ldr r4, [sp, #0x24] */
/* @0x2227b4 bl 0x221ce0 <_alutInputStreamConstructFromFile> */
/* @0x2227b8 mov r1, r8 */
/* @0x2227bc mov r2, r7 */
/* @0x2227c0 add r3, sp, #4 */
/* @0x2227c4 bl 0x222664 <_alutLoadMemoryFromInputStream> */
/* @0x2227c8 cmp r0, #0 */
/* @0x2227cc str r0, [r6] */
/* @0x2227d0 beq 0x2227f0 <alutLoadWAVFile+0x58> */
/* @0x2227d4 cmp r5, #0 */
/* @0x2227d8 vldrne s15, [sp, #4] */
/* @0x2227dc vcvtne.s32.f32 s15, s15 */
/* @0x2227e0 vstrne s15, [r5] */
/* @0x2227e4 cmp r4, #0 */
/* @0x2227e8 movne r3, #0 */
/* @0x2227ec strbne r3, [r4] */
/* @0x2227f0 add sp, sp, #8 */
/* @0x2227f4 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2227f8 · alutLoadWAVMemory · size=100 · insn=25 */
/* @0x2227f8 push {r4, r5, r6, r7, r8, lr} */
/* @0x2227fc sub sp, sp, #8 */
/* @0x222800 mov r8, r3 */
/* @0x222804 mov r7, r1 */
/* @0x222808 mvn r1, #-2147483648 */
/* @0x22280c mov r6, r2 */
/* @0x222810 ldr r5, [sp, #0x20] */
/* @0x222814 ldr r4, [sp, #0x24] */
/* @0x222818 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x22281c add r3, sp, #4 */
/* @0x222820 mov r1, r7 */
/* @0x222824 mov r2, r8 */
/* @0x222828 bl 0x222664 <_alutLoadMemoryFromInputStream> */
/* @0x22282c ldr r3, [r6] */
/* @0x222830 cmp r3, #0 */
/* @0x222834 beq 0x222854 <alutLoadWAVMemory+0x5c> */
/* @0x222838 cmp r5, #0 */
/* @0x22283c vldrne s15, [sp, #4] */
/* @0x222840 vcvtne.s32.f32 s15, s15 */
/* @0x222844 vstrne s15, [r5] */
/* @0x222848 cmp r4, #0 */
/* @0x22284c movne r3, #0 */
/* @0x222850 strbne r3, [r4] */
/* @0x222854 add sp, sp, #8 */
/* @0x222858 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x22285c · alutUnloadWAV · size=8 · insn=2 */
/* @0x22285c mov r0, r1 */
/* @0x222860 b 0xb655c <free@plt> */

/* ── FUNC 0x222864 · alutGetMIMETypes · size=64 · insn=16 */
/* @0x222864 push {r4, lr} */
/* @0x222868 mov r4, r0 */
/* @0x22286c bl 0x2219a8 <_alutSanityCheck> */
/* @0x222870 cmp r0, #0 */
/* @0x222874 popeq {r4, pc} */
/* @0x222878 sub r4, r4, #768 */
/* @0x22287c cmp r4, #1 */
/* @0x222880 bhi 0x222890 <alutGetMIMETypes+0x2c> */
/* @0x222884 ldr r0, [pc, #0x14] */
/* @0x222888 add r0, pc, r0 */
/* @0x22288c pop {r4, pc} */
/* @0x222890 movw r0, #0x201 */
/* @0x222894 bl 0x221940 <_alutSetError> */
/* @0x222898 mov r0, #0 */
/* @0x22289c pop {r4, pc} */
/* @0x2228a0 andseq r2, r3, r8, ror r3 */

/* ── FUNC 0x2228a4 · _alutOutputStreamConstruct · size=88 · insn=22 */
/* @0x2228a4 push {r4, r5, r6, lr} */
/* @0x2228a8 mov r6, r0 */
/* @0x2228ac mov r0, #12 */
/* @0x2228b0 bl 0x222a98 <_alutMalloc> */
/* @0x2228b4 subs r4, r0, #0 */
/* @0x2228b8 beq 0x2228e4 <_alutOutputStreamConstruct+0x40> */
/* @0x2228bc mov r0, r6 */
/* @0x2228c0 bl 0x222a98 <_alutMalloc> */
/* @0x2228c4 cmp r0, #0 */
/* @0x2228c8 mov r5, r0 */
/* @0x2228cc str r0, [r4] */
/* @0x2228d0 beq 0x2228ec <_alutOutputStreamConstruct+0x48> */
/* @0x2228d4 str r0, [r4, #0x4] */
/* @0x2228d8 mov r0, r4 */
/* @0x2228dc str r6, [r4, #0x8] */
/* @0x2228e0 pop {r4, r5, r6, pc} */
/* @0x2228e4 mov r0, r4 */
/* @0x2228e8 pop {r4, r5, r6, pc} */
/* @0x2228ec mov r0, r4 */
/* @0x2228f0 bl 0xb655c <free@plt> */
/* @0x2228f4 mov r0, r5 */
/* @0x2228f8 pop {r4, r5, r6, pc} */
