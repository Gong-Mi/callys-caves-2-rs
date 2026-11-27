/* libyoyo.so 覆盖卡组 0168
 * 函数 0x1f2770..0x1f4b64，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1f2770 · TimeLine_Load(unsigned char*, unsigned int, unsigned char*) · size=736 · insn=184 */
/* @0x1f2770 ldr r3, [pc, #0x2bc] */
/* @0x1f2774 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f2778 add r3, pc, r3 */
/* @0x1f277c ldr r9, [r0] */
/* @0x1f2780 sub sp, sp, #28 */
/* @0x1f2784 ldr r5, [r3] */
/* @0x1f2788 mov r8, r0 */
/* @0x1f278c str r2, [sp, #0x14] */
/* @0x1f2790 ldr r12, [r5] */
/* @0x1f2794 cmp r9, r12 */
/* @0x1f2798 beq 0x1f2838 <_Z13TimeLine_LoadPhjS_+0xc8> */
/* @0x1f279c cmp r9, #0 */
/* @0x1f27a0 ldr r3, [r5, #0x4] */
/* @0x1f27a4 bne 0x1f29e8 <_Z13TimeLine_LoadPhjS_+0x278> */
/* @0x1f27a8 cmp r3, #0 */
/* @0x1f27ac beq 0x1f29e8 <_Z13TimeLine_LoadPhjS_+0x278> */
/* @0x1f27b0 cmp r12, #0 */
/* @0x1f27b4 ble 0x1f2824 <_Z13TimeLine_LoadPhjS_+0xb4> */
/* @0x1f27b8 mov r4, r9 */
/* @0x1f27bc mov r7, r9 */
/* @0x1f27c0 ldr r0, [r3] */
/* @0x1f27c4 movw r2, #0xfeee */
/* @0x1f27c8 movt r2, #0xfeee */
/* @0x1f27cc movw r1, #0xfeee */
/* @0x1f27d0 cmp r0, r2 */
/* @0x1f27d4 movt r1, #0xfeee */
/* @0x1f27d8 lsl r6, r4, #2 */
/* @0x1f27dc beq 0x1f2818 <_Z13TimeLine_LoadPhjS_+0xa8> */
/* @0x1f27e0 ldr r2, [r3, r4, lsl #2] */
/* @0x1f27e4 add lr, r3, r6 */
/* @0x1f27e8 cmp r2, #0 */
/* @0x1f27ec mov r0, r2 */
/* @0x1f27f0 beq 0x1f2818 <_Z13TimeLine_LoadPhjS_+0xa8> */
/* @0x1f27f4 ldr r3, [r2] */
/* @0x1f27f8 cmp r3, r1 */
/* @0x1f27fc beq 0x1f2810 <_Z13TimeLine_LoadPhjS_+0xa0> */
/* @0x1f2800 ldr r3, [r3, #0x4] */
/* @0x1f2804 blx r3 */
/* @0x1f2808 ldm r5, {r12, lr} */
/* @0x1f280c add lr, lr, r6 */
/* @0x1f2810 str r7, [lr] */
/* @0x1f2814 ldr r3, [r5, #0x4] */
/* @0x1f2818 add r4, r4, #1 */
/* @0x1f281c cmp r4, r12 */
/* @0x1f2820 blt 0x1f27c0 <_Z13TimeLine_LoadPhjS_+0x50> */
/* @0x1f2824 mov r0, r3 */
/* @0x1f2828 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f282c mov r3, #0 */
/* @0x1f2830 str r9, [r5] */
/* @0x1f2834 str r3, [r5, #0x4] */
/* @0x1f2838 ldr r3, [pc, #0x1f8] */
/* @0x1f283c cmp r9, #0 */
/* @0x1f2840 add r3, pc, r3 */
/* @0x1f2844 ldr r5, [r3, #0x4] */
/* @0x1f2848 ldr r0, [r5, #0x4] */
/* @0x1f284c bne 0x1f29bc <_Z13TimeLine_LoadPhjS_+0x24c> */
/* @0x1f2850 cmp r0, #0 */
/* @0x1f2854 beq 0x1f29bc <_Z13TimeLine_LoadPhjS_+0x24c> */
/* @0x1f2858 ldr r3, [r5] */
/* @0x1f285c cmp r3, #0 */
/* @0x1f2860 ble 0x1f28a8 <_Z13TimeLine_LoadPhjS_+0x138> */
/* @0x1f2864 mov r4, r9 */
/* @0x1f2868 mov r7, r9 */
/* @0x1f286c ldr r0, [r0, r4, lsl #2] */
/* @0x1f2870 lsl r6, r4, #2 */
/* @0x1f2874 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f2878 cmp r0, #0 */
/* @0x1f287c beq 0x1f288c <_Z13TimeLine_LoadPhjS_+0x11c> */
/* @0x1f2880 ldr r3, [r5, #0x4] */
/* @0x1f2884 ldr r0, [r3, r4, lsl #2] */
/* @0x1f2888 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f288c ldr r2, [r5] */
/* @0x1f2890 add r4, r4, #1 */
/* @0x1f2894 ldr r3, [r5, #0x4] */
/* @0x1f2898 cmp r4, r2 */
/* @0x1f289c str r7, [r3, r6] */
/* @0x1f28a0 ldr r0, [r5, #0x4] */
/* @0x1f28a4 blt 0x1f286c <_Z13TimeLine_LoadPhjS_+0xfc> */
/* @0x1f28a8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f28ac mov r3, #0 */
/* @0x1f28b0 str r3, [r5, #0x4] */
/* @0x1f28b4 cmp r9, #0 */
/* @0x1f28b8 str r9, [r5] */
/* @0x1f28bc beq 0x1f29b0 <_Z13TimeLine_LoadPhjS_+0x240> */
/* @0x1f28c0 ldr r10, [pc, #0x174] */
/* @0x1f28c4 mov r5, #0 */
/* @0x1f28c8 mov r7, r5 */
/* @0x1f28cc str r9, [sp, #0x10] */
/* @0x1f28d0 add r10, pc, r10 */
/* @0x1f28d4 mov r11, r10 */
/* @0x1f28d8 ldr r6, [r8, #0x4]! */
/* @0x1f28dc cmp r6, #0 */
/* @0x1f28e0 moveq r9, r6 */
/* @0x1f28e4 moveq r4, r9 */
/* @0x1f28e8 beq 0x1f296c <_Z13TimeLine_LoadPhjS_+0x1fc> */
/* @0x1f28ec ldr r9, [pc, #0x14c] */
/* @0x1f28f0 ldr r9, [pc, r9] */
/* @0x1f28f4 ldr r12, [r9] */
/* @0x1f28f8 adds r1, r12, r6 */
/* @0x1f28fc moveq r9, r1 */
/* @0x1f2900 moveq r4, r9 */
/* @0x1f2904 beq 0x1f296c <_Z13TimeLine_LoadPhjS_+0x1fc> */
/* @0x1f2908 mov r0, #24 */
/* @0x1f290c str r12, [sp, #0x8] */
/* @0x1f2910 str r1, [sp, #0xc] */
/* @0x1f2914 bl 0x27c524 <_Znwj> */
/* @0x1f2918 ldr r2, [pc, #0x124] */
/* @0x1f291c ldr r2, [pc, r2] */
/* @0x1f2920 add r2, r2, #8 */
/* @0x1f2924 mov r4, r0 */
/* @0x1f2928 str r2, [r0] */
/* @0x1f292c str r7, [r0, #0x8] */
/* @0x1f2930 str r7, [r0, #0xc] */
/* @0x1f2934 str r7, [r0, #0x10] */
/* @0x1f2938 str r7, [r0, #0x14] */
/* @0x1f293c bl 0x1f1768 <_ZN9CTimeLine5ClearEv> */
/* @0x1f2940 ldr r1, [sp, #0xc] */
/* @0x1f2944 str r4, [r4, #0x4] */
/* @0x1f2948 mov r0, r4 */
/* @0x1f294c ldr r2, [sp, #0x14] */
/* @0x1f2950 bl 0x1f19b4 <_ZN9CTimeLine13LoadFromChunkEP10YYTimelinePh> */
/* @0x1f2954 ldr r12, [sp, #0x8] */
/* @0x1f2958 ldr r1, [r12, r6] */
/* @0x1f295c cmp r1, #0 */
/* @0x1f2960 ldrne r6, [r9] */
/* @0x1f2964 moveq r9, r1 */
/* @0x1f2968 addne r9, r6, r1 */
/* @0x1f296c ldr r3, [r10, #0x4] */
/* @0x1f2970 lsl r6, r5, #2 */
/* @0x1f2974 ldr r2, [r3, #0x4] */
/* @0x1f2978 ldr r0, [r2, r5, lsl #2] */
/* @0x1f297c cmp r0, #0 */
/* @0x1f2980 beq 0x1f298c <_Z13TimeLine_LoadPhjS_+0x21c> */
/* @0x1f2984 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2988 ldr r3, [r10, #0x4] */
/* @0x1f298c ldr r2, [r11] */
/* @0x1f2990 add r5, r5, #1 */
/* @0x1f2994 ldr r1, [sp, #0x10] */
/* @0x1f2998 ldr r2, [r2, #0x4] */
/* @0x1f299c cmp r5, r1 */
/* @0x1f29a0 str r4, [r2, r6] */
/* @0x1f29a4 ldr r3, [r3, #0x4] */
/* @0x1f29a8 str r9, [r3, r6] */
/* @0x1f29ac bne 0x1f28d8 <_Z13TimeLine_LoadPhjS_+0x168> */
/* @0x1f29b0 mov r0, #1 */
/* @0x1f29b4 add sp, sp, #28 */
/* @0x1f29b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f29bc lsls r4, r9, #2 */
/* @0x1f29c0 beq 0x1f2a04 <_Z13TimeLine_LoadPhjS_+0x294> */
/* @0x1f29c4 ldr r2, [pc, #0x7c] */
/* @0x1f29c8 mov r3, #0 */
/* @0x1f29cc mov r1, r4 */
/* @0x1f29d0 str r3, [sp] */
/* @0x1f29d4 add r2, pc, r2 */
/* @0x1f29d8 mov r3, #92 */
/* @0x1f29dc bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f29e0 str r0, [r5, #0x4] */
/* @0x1f29e4 b 0x1f28b4 <_Z13TimeLine_LoadPhjS_+0x144> */
/* @0x1f29e8 lsls r4, r9, #2 */
/* @0x1f29ec mov r0, r3 */
/* @0x1f29f0 bne 0x1f2a10 <_Z13TimeLine_LoadPhjS_+0x2a0> */
/* @0x1f29f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f29f8 str r4, [r5, #0x4] */
/* @0x1f29fc str r9, [r5] */
/* @0x1f2a00 b 0x1f2838 <_Z13TimeLine_LoadPhjS_+0xc8> */
/* @0x1f2a04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2a08 str r4, [r5, #0x4] */
/* @0x1f2a0c b 0x1f28b4 <_Z13TimeLine_LoadPhjS_+0x144> */
/* @0x1f2a10 ldr r2, [pc, #0x34] */
/* @0x1f2a14 mov r3, #0 */
/* @0x1f2a18 mov r1, r4 */
/* @0x1f2a1c str r3, [sp] */
/* @0x1f2a20 add r2, pc, r2 */
/* @0x1f2a24 mov r3, #135 */
/* @0x1f2a28 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f2a2c str r0, [r5, #0x4] */
/* @0x1f2a30 b 0x1f29fc <_Z13TimeLine_LoadPhjS_+0x28c> */
/* @0x1f2a34 subseq r0, r6, r4, ror r9 */
/* @0x1f2a38 subseq r0, r6, r12, lsr #17 */
/* @0x1f2a3c subseq r0, r6, r12, lsl r8 */
/* @0x1f2a40 andseq r11, pc, r4, asr r0 */
/* @0x1f2a44 andseq lr, pc, r8, lsl #10 */
/* @0x1f2a48 andseq pc, r5, r8, asr #26 */
/* @0x1f2a4c ldrsbeq r10, [r5], -r0 */

/* ── FUNC 0x1f2a50 · TrackView_Load(unsigned char*, unsigned int, unsigned char*) · size=176 · insn=44 */
/* @0x1f2a50 ldr r3, [pc, #0x98] */
/* @0x1f2a54 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1f2a58 ldr r3, [pc, r3] */
/* @0x1f2a5c ldr r8, [r0] */
/* @0x1f2a60 mov r5, r0 */
/* @0x1f2a64 ldr r4, [r3] */
/* @0x1f2a68 ldr r1, [pc, #0x84] */
/* @0x1f2a6c mov r2, r8 */
/* @0x1f2a70 ldr r3, [r4] */
/* @0x1f2a74 add r1, pc, r1 */
/* @0x1f2a78 mov r0, r4 */
/* @0x1f2a7c ldr r3, [r3, #0xc] */
/* @0x1f2a80 blx r3 */
/* @0x1f2a84 cmp r8, #0 */
/* @0x1f2a88 ble 0x1f2ae8 <_Z14TrackView_LoadPhjS_+0x98> */
/* @0x1f2a8c ldr r10, [pc, #0x64] */
/* @0x1f2a90 add r5, r5, #4 */
/* @0x1f2a94 ldr r9, [pc, #0x60] */
/* @0x1f2a98 mov r6, #0 */
/* @0x1f2a9c add r10, pc, r10 */
/* @0x1f2aa0 add r9, pc, r9 */
/* @0x1f2aa4 ldr r3, [r4] */
/* @0x1f2aa8 add r5, r5, #4 */
/* @0x1f2aac mov r0, r4 */
/* @0x1f2ab0 mov r1, r10 */
/* @0x1f2ab4 ldr r2, [r5] */
/* @0x1f2ab8 add r6, r6, #1 */
/* @0x1f2abc ldr r3, [r3, #0xc] */
/* @0x1f2ac0 ldr r7, [r5, #0x4] */
/* @0x1f2ac4 blx r3 */
/* @0x1f2ac8 ldr r3, [r4] */
/* @0x1f2acc mov r0, r4 */
/* @0x1f2ad0 mov r1, r9 */
/* @0x1f2ad4 mov r2, r7 */
/* @0x1f2ad8 ldr r3, [r3, #0xc] */
/* @0x1f2adc blx r3 */
/* @0x1f2ae0 cmp r8, r6 */
/* @0x1f2ae4 bgt 0x1f2aa4 <_Z14TrackView_LoadPhjS_+0x54> */
/* @0x1f2ae8 mov r0, #1 */
/* @0x1f2aec pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f2af0 ldrheq r10, [pc], -r12 */
/* @0x1f2af4 andseq pc, r5, r12, ror #25 */
/* @0x1f2af8 ldrsbeq pc, [r5], -r12 */
/* @0x1f2afc ldrsheq pc, [r5], -r4 */

/* ── FUNC 0x1f2b00 · TimeLine_Number() · size=24 · insn=6 */
/* @0x1f2b00 ldr r3, [pc, #0xc] */
/* @0x1f2b04 add r3, pc, r3 */
/* @0x1f2b08 ldr r3, [r3] */
/* @0x1f2b0c ldr r0, [r3] */
/* @0x1f2b10 bx lr */
/* @0x1f2b14 subseq r0, r6, r8, ror #11 */

/* ── FUNC 0x1f2b18 · TimeLine_Exists(int) · size=64 · insn=16 */
/* @0x1f2b18 cmp r0, #0 */
/* @0x1f2b1c blt 0x1f2b4c <_Z15TimeLine_Existsi+0x34> */
/* @0x1f2b20 ldr r3, [pc, #0x2c] */
/* @0x1f2b24 add r3, pc, r3 */
/* @0x1f2b28 ldr r3, [r3] */
/* @0x1f2b2c ldr r2, [r3] */
/* @0x1f2b30 cmp r0, r2 */
/* @0x1f2b34 bge 0x1f2b4c <_Z15TimeLine_Existsi+0x34> */
/* @0x1f2b38 ldr r3, [r3, #0x4] */
/* @0x1f2b3c ldr r0, [r3, r0, lsl #2] */
/* @0x1f2b40 adds r0, r0, #0 */
/* @0x1f2b44 movne r0, #1 */
/* @0x1f2b48 bx lr */
/* @0x1f2b4c mov r0, #0 */
/* @0x1f2b50 bx lr */
/* @0x1f2b54 subseq r0, r6, r8, asr #11 */

/* ── FUNC 0x1f2b58 · TimeLine_Name(int) · size=116 · insn=29 */
/* @0x1f2b58 cmp r0, #0 */
/* @0x1f2b5c blt 0x1f2ba4 <_Z13TimeLine_Namei+0x4c> */
/* @0x1f2b60 ldr r3, [pc, #0x54] */
/* @0x1f2b64 add r3, pc, r3 */
/* @0x1f2b68 ldr r2, [r3] */
/* @0x1f2b6c ldr r1, [r2] */
/* @0x1f2b70 cmp r0, r1 */
/* @0x1f2b74 bge 0x1f2b98 <_Z13TimeLine_Namei+0x40> */
/* @0x1f2b78 ldr r2, [r2, #0x4] */
/* @0x1f2b7c ldr r2, [r2, r0, lsl #2] */
/* @0x1f2b80 cmp r2, #0 */
/* @0x1f2b84 beq 0x1f2bb0 <_Z13TimeLine_Namei+0x58> */
/* @0x1f2b88 ldr r3, [r3, #0x4] */
/* @0x1f2b8c ldr r3, [r3, #0x4] */
/* @0x1f2b90 ldr r0, [r3, r0, lsl #2] */
/* @0x1f2b94 bx lr */
/* @0x1f2b98 ldr r0, [pc, #0x20] */
/* @0x1f2b9c add r0, pc, r0 */
/* @0x1f2ba0 bx lr */
/* @0x1f2ba4 ldr r0, [pc, #0x18] */
/* @0x1f2ba8 add r0, pc, r0 */
/* @0x1f2bac bx lr */
/* @0x1f2bb0 ldr r0, [pc, #0x10] */
/* @0x1f2bb4 add r0, pc, r0 */
/* @0x1f2bb8 bx lr */
/* @0x1f2bbc subseq r0, r6, r8, lsl #11 */
/* @0x1f2bc0 andseq sp, r3, r4, lsr #30 */
/* @0x1f2bc4 andseq sp, r3, r8, lsl pc */
/* @0x1f2bc8 andseq sp, r3, r12, lsl #30 */

/* ── FUNC 0x1f2bcc · TimeLine_Find(char const*) · size=124 · insn=31 */
/* @0x1f2bcc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1f2bd0 mov r6, r0 */
/* @0x1f2bd4 ldr r3, [pc, #0x68] */
/* @0x1f2bd8 add r3, pc, r3 */
/* @0x1f2bdc ldr r8, [r3, #0x4] */
/* @0x1f2be0 ldr r5, [r8] */
/* @0x1f2be4 cmp r5, #0 */
/* @0x1f2be8 ble 0x1f2c34 <_Z13TimeLine_FindPKc+0x68> */
/* @0x1f2bec ldr r9, [r3] */
/* @0x1f2bf0 mov r4, #0 */
/* @0x1f2bf4 ldr r7, [r9] */
/* @0x1f2bf8 cmp r4, r7 */
/* @0x1f2bfc mov r1, r6 */
/* @0x1f2c00 bge 0x1f2c28 <_Z13TimeLine_FindPKc+0x5c> */
/* @0x1f2c04 ldr r3, [r9, #0x4] */
/* @0x1f2c08 ldr r3, [r3, r4, lsl #2] */
/* @0x1f2c0c cmp r3, #0 */
/* @0x1f2c10 beq 0x1f2c28 <_Z13TimeLine_FindPKc+0x5c> */
/* @0x1f2c14 ldr r3, [r8, #0x4] */
/* @0x1f2c18 ldr r0, [r3, r4, lsl #2] */
/* @0x1f2c1c bl 0xb6574 <strcmp@plt> */
/* @0x1f2c20 cmp r0, #0 */
/* @0x1f2c24 beq 0x1f2c3c <_Z13TimeLine_FindPKc+0x70> */
/* @0x1f2c28 add r4, r4, #1 */
/* @0x1f2c2c cmp r4, r5 */
/* @0x1f2c30 bne 0x1f2bf8 <_Z13TimeLine_FindPKc+0x2c> */
/* @0x1f2c34 mvn r0, #0 */
/* @0x1f2c38 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f2c3c mov r0, r4 */
/* @0x1f2c40 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f2c44 subseq r0, r6, r4, lsl r5 */

/* ── FUNC 0x1f2c48 · TimeLine_Data(int) · size=56 · insn=14 */
/* @0x1f2c48 cmp r0, #0 */
/* @0x1f2c4c blt 0x1f2c68 <_Z13TimeLine_Datai+0x20> */
/* @0x1f2c50 ldr r3, [pc, #0x24] */
/* @0x1f2c54 add r3, pc, r3 */
/* @0x1f2c58 ldr r3, [r3] */
/* @0x1f2c5c ldr r2, [r3] */
/* @0x1f2c60 cmp r0, r2 */
/* @0x1f2c64 blt 0x1f2c70 <_Z13TimeLine_Datai+0x28> */
/* @0x1f2c68 mov r0, #0 */
/* @0x1f2c6c bx lr */
/* @0x1f2c70 ldr r3, [r3, #0x4] */
/* @0x1f2c74 ldr r0, [r3, r0, lsl #2] */
/* @0x1f2c78 bx lr */
/* @0x1f2c7c .word 0x00560498 */

/* ── FUNC 0x1f2c80 · TimeLine_Prepare() · size=124 · insn=31 */
/* @0x1f2c80 push {r3, r4, r5, lr} */
/* @0x1f2c84 ldr r3, [pc, #0x64] */
/* @0x1f2c88 ldr r2, [pc, r3] */
/* @0x1f2c8c ldr r3, [r2] */
/* @0x1f2c90 cmp r3, #0 */
/* @0x1f2c94 ble 0x1f2ce8 <_Z16TimeLine_Preparev+0x68> */
/* @0x1f2c98 ldr r5, [pc, #0x54] */
/* @0x1f2c9c mov r4, #0 */
/* @0x1f2ca0 add r5, pc, r5 */
/* @0x1f2ca4 b 0x1f2cbc <_Z16TimeLine_Preparev+0x3c> */
/* @0x1f2ca8 ldr r2, [r5] */
/* @0x1f2cac add r4, r4, #1 */
/* @0x1f2cb0 ldr r3, [r2] */
/* @0x1f2cb4 cmp r3, r4 */
/* @0x1f2cb8 ble 0x1f2ce8 <_Z16TimeLine_Preparev+0x68> */
/* @0x1f2cbc ldr r2, [r2, #0x4] */
/* @0x1f2cc0 ldr r3, [pc, #0x30] */
/* @0x1f2cc4 ldr r0, [r2, r4, lsl #2] */
/* @0x1f2cc8 cmp r0, #0 */
/* @0x1f2ccc beq 0x1f2ca8 <_Z16TimeLine_Preparev+0x28> */
/* @0x1f2cd0 ldr r3, [pc, r3] */
/* @0x1f2cd4 str r4, [r3] */
/* @0x1f2cd8 bl 0x1f1bb4 <_ZN9CTimeLine7CompileEv> */
/* @0x1f2cdc cmp r0, #0 */
/* @0x1f2ce0 bne 0x1f2ca8 <_Z16TimeLine_Preparev+0x28> */
/* @0x1f2ce4 pop {r3, r4, r5, pc} */
/* @0x1f2ce8 mov r0, #1 */
/* @0x1f2cec pop {r3, r4, r5, pc} */
/* @0x1f2cf0 subseq r0, r6, r4, ror #8 */
/* @0x1f2cf4 subseq r0, r6, r12, asr #8 */
/* @0x1f2cf8 andseq r11, pc, r8, ror #1 */

/* ── FUNC 0x1f2cfc · TimeLine_Add() · size=696 · insn=174 */
/* @0x1f2cfc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f2d00 sub sp, sp, #156 */
/* @0x1f2d04 ldr r5, [pc, #0x28c] */
/* @0x1f2d08 add r4, sp, #20 */
/* @0x1f2d0c ldr r6, [pc, #0x288] */
/* @0x1f2d10 add r5, pc, r5 */
/* @0x1f2d14 ldr r1, [pc, #0x284] */
/* @0x1f2d18 ldr r6, [pc, r6] */
/* @0x1f2d1c mov r0, r4 */
/* @0x1f2d20 ldr r2, [r5] */
/* @0x1f2d24 add r1, pc, r1 */
/* @0x1f2d28 ldr r3, [r6] */
/* @0x1f2d2c ldr r7, [r2] */
/* @0x1f2d30 str r3, [sp, #0x94] */
/* @0x1f2d34 mov r2, r7 */
/* @0x1f2d38 bl 0xb6550 <sprintf@plt> */
/* @0x1f2d3c mov r0, r4 */
/* @0x1f2d40 ldr r5, [r5, #0x4] */
/* @0x1f2d44 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1f2d48 ldr r4, [r5] */
/* @0x1f2d4c adds r10, r4, #1 */
/* @0x1f2d50 str r0, [sp, #0xc] */
/* @0x1f2d54 ldr r0, [r5, #0x4] */
/* @0x1f2d58 bne 0x1f2f34 <_Z12TimeLine_Addv+0x238> */
/* @0x1f2d5c cmp r0, #0 */
/* @0x1f2d60 beq 0x1f2db0 <_Z12TimeLine_Addv+0xb4> */
/* @0x1f2d64 cmp r4, #0 */
/* @0x1f2d68 ble 0x1f2db0 <_Z12TimeLine_Addv+0xb4> */
/* @0x1f2d6c mov r9, r10 */
/* @0x1f2d70 mov r11, r10 */
/* @0x1f2d74 ldr r0, [r0, r9, lsl #2] */
/* @0x1f2d78 lsl r8, r9, #2 */
/* @0x1f2d7c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f2d80 cmp r0, #0 */
/* @0x1f2d84 beq 0x1f2d94 <_Z12TimeLine_Addv+0x98> */
/* @0x1f2d88 ldr r2, [r5, #0x4] */
/* @0x1f2d8c ldr r0, [r2, r9, lsl #2] */
/* @0x1f2d90 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2d94 ldr r1, [r5] */
/* @0x1f2d98 add r9, r9, #1 */
/* @0x1f2d9c ldr r2, [r5, #0x4] */
/* @0x1f2da0 cmp r9, r1 */
/* @0x1f2da4 str r11, [r2, r8] */
/* @0x1f2da8 ldr r0, [r5, #0x4] */
/* @0x1f2dac blt 0x1f2d74 <_Z12TimeLine_Addv+0x78> */
/* @0x1f2db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2db4 mov r3, #0 */
/* @0x1f2db8 mov r1, r3 */
/* @0x1f2dbc str r3, [r5, #0x4] */
/* @0x1f2dc0 cmp r7, r4 */
/* @0x1f2dc4 str r10, [r5] */
/* @0x1f2dc8 bge 0x1f2df0 <_Z12TimeLine_Addv+0xf4> */
/* @0x1f2dcc lsl r3, r4, #2 */
/* @0x1f2dd0 add r2, r1, r3 */
/* @0x1f2dd4 sub r4, r4, #1 */
/* @0x1f2dd8 cmp r4, r7 */
/* @0x1f2ddc ldr r2, [r2, #-0x4] */
/* @0x1f2de0 str r2, [r1, r3] */
/* @0x1f2de4 sub r3, r3, #4 */
/* @0x1f2de8 ldr r1, [r5, #0x4] */
/* @0x1f2dec bne 0x1f2dd0 <_Z12TimeLine_Addv+0xd4> */
/* @0x1f2df0 ldr r2, [sp, #0xc] */
/* @0x1f2df4 mov r0, #24 */
/* @0x1f2df8 ldr r3, [pc, #0x1a4] */
/* @0x1f2dfc mov r9, #0 */
/* @0x1f2e00 add r3, pc, r3 */
/* @0x1f2e04 str r2, [r1, r7, lsl #2] */
/* @0x1f2e08 ldr r5, [r3] */
/* @0x1f2e0c bl 0x27c524 <_Znwj> */
/* @0x1f2e10 ldr r3, [pc, #0x190] */
/* @0x1f2e14 ldr r3, [pc, r3] */
/* @0x1f2e18 add r3, r3, #8 */
/* @0x1f2e1c str r9, [r0, #0x8] */
/* @0x1f2e20 mov r8, r0 */
/* @0x1f2e24 str r9, [r0, #0xc] */
/* @0x1f2e28 str r9, [r0, #0x10] */
/* @0x1f2e2c str r3, [r0] */
/* @0x1f2e30 str r9, [r0, #0x14] */
/* @0x1f2e34 bl 0x1f1768 <_ZN9CTimeLine5ClearEv> */
/* @0x1f2e38 ldr r4, [r5] */
/* @0x1f2e3c str r8, [r8, #0x4] */
/* @0x1f2e40 adds r10, r4, #1 */
/* @0x1f2e44 mov r1, r4 */
/* @0x1f2e48 bne 0x1f2f60 <_Z12TimeLine_Addv+0x264> */
/* @0x1f2e4c ldr r3, [r5, #0x4] */
/* @0x1f2e50 cmp r3, r9 */
/* @0x1f2e54 beq 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4> */
/* @0x1f2e58 cmp r4, r9 */
/* @0x1f2e5c ble 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4> */
/* @0x1f2e60 mov r9, r10 */
/* @0x1f2e64 mov r11, r10 */
/* @0x1f2e68 ldr r0, [r3] */
/* @0x1f2e6c movw r2, #0xfeee */
/* @0x1f2e70 movt r2, #0xfeee */
/* @0x1f2e74 cmp r0, r2 */
/* @0x1f2e78 beq 0x1f2ec4 <_Z12TimeLine_Addv+0x1c8> */
/* @0x1f2e7c ldr r0, [r3, r9, lsl #2] */
/* @0x1f2e80 lsl r2, r9, #2 */
/* @0x1f2e84 add r12, r3, r2 */
/* @0x1f2e88 cmp r0, #0 */
/* @0x1f2e8c beq 0x1f2ec4 <_Z12TimeLine_Addv+0x1c8> */
/* @0x1f2e90 ldr lr, [r0] */
/* @0x1f2e94 movw r3, #0xfeee */
/* @0x1f2e98 movt r3, #0xfeee */
/* @0x1f2e9c cmp lr, r3 */
/* @0x1f2ea0 beq 0x1f2ebc <_Z12TimeLine_Addv+0x1c0> */
/* @0x1f2ea4 ldr r3, [lr, #0x4] */
/* @0x1f2ea8 str r2, [sp, #0x8] */
/* @0x1f2eac blx r3 */
/* @0x1f2eb0 ldm r5, {r1, r12} */
/* @0x1f2eb4 ldr r2, [sp, #0x8] */
/* @0x1f2eb8 add r12, r12, r2 */
/* @0x1f2ebc str r11, [r12] */
/* @0x1f2ec0 ldr r3, [r5, #0x4] */
/* @0x1f2ec4 add r9, r9, #1 */
/* @0x1f2ec8 cmp r9, r1 */
/* @0x1f2ecc blt 0x1f2e68 <_Z12TimeLine_Addv+0x16c> */
/* @0x1f2ed0 mov r0, r3 */
/* @0x1f2ed4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f2ed8 mov r3, #0 */
/* @0x1f2edc mov r1, r3 */
/* @0x1f2ee0 str r3, [r5, #0x4] */
/* @0x1f2ee4 cmp r7, r4 */
/* @0x1f2ee8 str r10, [r5] */
/* @0x1f2eec bge 0x1f2f14 <_Z12TimeLine_Addv+0x218> */
/* @0x1f2ef0 lsl r3, r4, #2 */
/* @0x1f2ef4 add r2, r1, r3 */
/* @0x1f2ef8 sub r4, r4, #1 */
/* @0x1f2efc cmp r4, r7 */
/* @0x1f2f00 ldr r2, [r2, #-0x4] */
/* @0x1f2f04 str r2, [r1, r3] */
/* @0x1f2f08 sub r3, r3, #4 */
/* @0x1f2f0c ldr r1, [r5, #0x4] */
/* @0x1f2f10 bne 0x1f2ef4 <_Z12TimeLine_Addv+0x1f8> */
/* @0x1f2f14 ldr r2, [sp, #0x94] */
/* @0x1f2f18 mov r0, r7 */
/* @0x1f2f1c str r8, [r1, r7, lsl #2] */
/* @0x1f2f20 ldr r3, [r6] */
/* @0x1f2f24 cmp r2, r3 */
/* @0x1f2f28 bne 0x1f2f94 <_Z12TimeLine_Addv+0x298> */
/* @0x1f2f2c add sp, sp, #156 */
/* @0x1f2f30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f2f34 lsls r1, r10, #2 */
/* @0x1f2f38 beq 0x1f2db0 <_Z12TimeLine_Addv+0xb4> */
/* @0x1f2f3c ldr r2, [pc, #0x68] */
/* @0x1f2f40 mov r3, #0 */
/* @0x1f2f44 str r3, [sp] */
/* @0x1f2f48 mov r3, #92 */
/* @0x1f2f4c add r2, pc, r2 */
/* @0x1f2f50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f2f54 mov r1, r0 */
/* @0x1f2f58 str r0, [r5, #0x4] */
/* @0x1f2f5c b 0x1f2dc0 <_Z12TimeLine_Addv+0xc4> */
/* @0x1f2f60 lsls r1, r10, #2 */
/* @0x1f2f64 beq 0x1f2f8c <_Z12TimeLine_Addv+0x290> */
/* @0x1f2f68 ldr r2, [pc, #0x40] */
/* @0x1f2f6c mov r3, #135 */
/* @0x1f2f70 ldr r0, [r5, #0x4] */
/* @0x1f2f74 add r2, pc, r2 */
/* @0x1f2f78 str r9, [sp] */
/* @0x1f2f7c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f2f80 mov r1, r0 */
/* @0x1f2f84 str r0, [r5, #0x4] */
/* @0x1f2f88 b 0x1f2ee4 <_Z12TimeLine_Addv+0x1e8> */
/* @0x1f2f8c ldr r3, [r5, #0x4] */
/* @0x1f2f90 b 0x1f2ed0 <_Z12TimeLine_Addv+0x1d4> */
/* @0x1f2f94 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1f2f98 ldrsbeq r0, [r6], #-60 */
/* @0x1f2f9c andseq r10, pc, r8, lsr r12 */
/* @0x1f2fa0 andseq pc, r5, r12, lsl #21 */
/* @0x1f2fa4 subseq r0, r6, r12, ror #5 */
/* @0x1f2fa8 andseq lr, pc, r0, lsl r0 */
/* @0x1f2fac ldrsbeq pc, [r5], -r0 */
/* @0x1f2fb0 andseq r10, r5, r12, ror r3 */

/* ── FUNC 0x1f2fb4 · TimeLine_Delete(int) · size=448 · insn=112 */
/* @0x1f2fb4 push {r4, r5, r6, r7, lr} */
/* @0x1f2fb8 subs r4, r0, #0 */
/* @0x1f2fbc sub sp, sp, #12 */
/* @0x1f2fc0 blt 0x1f3118 <_Z15TimeLine_Deletei+0x164> */
/* @0x1f2fc4 ldr r3, [pc, #0x19c] */
/* @0x1f2fc8 ldr r5, [pc, r3] */
/* @0x1f2fcc ldr r3, [r5] */
/* @0x1f2fd0 cmp r4, r3 */
/* @0x1f2fd4 bge 0x1f3118 <_Z15TimeLine_Deletei+0x164> */
/* @0x1f2fd8 ldr r3, [r5, #0x4] */
/* @0x1f2fdc lsl r6, r4, #2 */
/* @0x1f2fe0 ldr r0, [r3, r4, lsl #2] */
/* @0x1f2fe4 cmp r0, #0 */
/* @0x1f2fe8 beq 0x1f311c <_Z15TimeLine_Deletei+0x168> */
/* @0x1f2fec cmp r3, #0 */
/* @0x1f2ff0 beq 0x1f304c <_Z15TimeLine_Deletei+0x98> */
/* @0x1f2ff4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f2ff8 ldr r3, [r5] */
/* @0x1f2ffc ldr r2, [r5, #0x4] */
/* @0x1f3000 mov r1, #0 */
/* @0x1f3004 sub r3, r3, #2 */
/* @0x1f3008 cmp r4, r3 */
/* @0x1f300c str r1, [r2, r6] */
/* @0x1f3010 bge 0x1f3160 <_Z15TimeLine_Deletei+0x1ac> */
/* @0x1f3014 mov r1, r6 */
/* @0x1f3018 mov r2, r4 */
/* @0x1f301c ldr r12, [r5, #0x4] */
/* @0x1f3020 add r0, r1, #4 */
/* @0x1f3024 add r2, r2, #1 */
/* @0x1f3028 cmp r2, r3 */
/* @0x1f302c ldr lr, [r12, r0] */
/* @0x1f3030 str lr, [r12, r1] */
/* @0x1f3034 mov r1, r0 */
/* @0x1f3038 bne 0x1f301c <_Z15TimeLine_Deletei+0x68> */
/* @0x1f303c lsl r2, r2, #2 */
/* @0x1f3040 ldr r3, [r5, #0x4] */
/* @0x1f3044 mov r1, #0 */
/* @0x1f3048 str r1, [r3, r2] */
/* @0x1f304c ldr r7, [pc, #0x118] */
/* @0x1f3050 add r7, pc, r7 */
/* @0x1f3054 ldr r5, [r7, #0x4] */
/* @0x1f3058 ldr r3, [r5, #0x4] */
/* @0x1f305c add r2, r3, r6 */
/* @0x1f3060 ldr r0, [r3, r6] */
/* @0x1f3064 cmp r0, #0 */
/* @0x1f3068 beq 0x1f307c <_Z15TimeLine_Deletei+0xc8> */
/* @0x1f306c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3070 ldr r5, [r7, #0x4] */
/* @0x1f3074 ldr r2, [r5, #0x4] */
/* @0x1f3078 add r2, r2, r6 */
/* @0x1f307c mov r3, #0 */
/* @0x1f3080 str r3, [r2] */
/* @0x1f3084 ldr r3, [r5, #0x4] */
/* @0x1f3088 ldr r0, [r3, r6] */
/* @0x1f308c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f3090 cmp r0, #0 */
/* @0x1f3094 beq 0x1f30a4 <_Z15TimeLine_Deletei+0xf0> */
/* @0x1f3098 ldr r3, [r5, #0x4] */
/* @0x1f309c ldr r0, [r3, r6] */
/* @0x1f30a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f30a4 ldr r7, [r5] */
/* @0x1f30a8 mov r2, #0 */
/* @0x1f30ac ldr r3, [r5, #0x4] */
/* @0x1f30b0 sub r12, r7, #2 */
/* @0x1f30b4 cmp r12, r4 */
/* @0x1f30b8 str r2, [r3, r6] */
/* @0x1f30bc movgt r3, r6 */
/* @0x1f30c0 ble 0x1f30e4 <_Z15TimeLine_Deletei+0x130> */
/* @0x1f30c4 ldr r1, [r5, #0x4] */
/* @0x1f30c8 add r2, r3, #4 */
/* @0x1f30cc add r4, r4, #1 */
/* @0x1f30d0 cmp r4, r12 */
/* @0x1f30d4 ldr r0, [r1, r2] */
/* @0x1f30d8 str r0, [r1, r3] */
/* @0x1f30dc mov r3, r2 */
/* @0x1f30e0 bne 0x1f30c4 <_Z15TimeLine_Deletei+0x110> */
/* @0x1f30e4 cmp r7, #0 */
/* @0x1f30e8 sub r3, r7, #1 */
/* @0x1f30ec str r3, [r5] */
/* @0x1f30f0 bne 0x1f3124 <_Z15TimeLine_Deletei+0x170> */
/* @0x1f30f4 ldr r0, [r5, #0x4] */
/* @0x1f30f8 cmp r0, #0 */
/* @0x1f30fc beq 0x1f3150 <_Z15TimeLine_Deletei+0x19c> */
/* @0x1f3100 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3104 str r7, [r5, #0x4] */
/* @0x1f3108 mov r0, #1 */
/* @0x1f310c str r7, [r5] */
/* @0x1f3110 add sp, sp, #12 */
/* @0x1f3114 pop {r4, r5, r6, r7, pc} */
/* @0x1f3118 mov r0, #0 */
/* @0x1f311c add sp, sp, #12 */
/* @0x1f3120 pop {r4, r5, r6, r7, pc} */
/* @0x1f3124 lsls r1, r7, #2 */
/* @0x1f3128 ldr r0, [r5, #0x4] */
/* @0x1f312c beq 0x1f3150 <_Z15TimeLine_Deletei+0x19c> */
/* @0x1f3130 ldr r2, [pc, #0x38] */
/* @0x1f3134 mov r3, #0 */
/* @0x1f3138 str r3, [sp] */
/* @0x1f313c mov r3, #92 */
/* @0x1f3140 add r2, pc, r2 */
/* @0x1f3144 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f3148 str r0, [r5, #0x4] */
/* @0x1f314c b 0x1f3108 <_Z15TimeLine_Deletei+0x154> */
/* @0x1f3150 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3154 mov r3, #0 */
/* @0x1f3158 str r3, [r5, #0x4] */
/* @0x1f315c b 0x1f3108 <_Z15TimeLine_Deletei+0x154> */
/* @0x1f3160 mov r2, r6 */
/* @0x1f3164 b 0x1f3040 <_Z15TimeLine_Deletei+0x8c> */
/* @0x1f3168 subseq r0, r6, r4, lsr #2 */
/* @0x1f316c .word 0x0056009c */
/* @0x1f3170 ldrsbeq pc, [r5], -r12 */

/* ── FUNC 0x1f3174 · FINALIZE_Timeline_Main() · size=420 · insn=105 */
/* @0x1f3174 ldr r3, [pc, #0x18c] */
/* @0x1f3178 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f317c ldr r6, [pc, r3] */
/* @0x1f3180 cmp r6, #0 */
/* @0x1f3184 beq 0x1f3248 <_Z22FINALIZE_Timeline_Mainv+0xd4> */
/* @0x1f3188 ldr r12, [r6] */
/* @0x1f318c cmp r12, #0 */
/* @0x1f3190 beq 0x1f3230 <_Z22FINALIZE_Timeline_Mainv+0xbc> */
/* @0x1f3194 ldr r5, [r6, #0x4] */
/* @0x1f3198 cmp r5, #0 */
/* @0x1f319c beq 0x1f32f8 <_Z22FINALIZE_Timeline_Mainv+0x184> */
/* @0x1f31a0 cmp r12, #0 */
/* @0x1f31a4 ble 0x1f3218 <_Z22FINALIZE_Timeline_Mainv+0xa4> */
/* @0x1f31a8 mov r4, #0 */
/* @0x1f31ac mov r8, r4 */
/* @0x1f31b0 ldr r1, [r5] */
/* @0x1f31b4 movw r3, #0xfeee */
/* @0x1f31b8 movt r3, #0xfeee */
/* @0x1f31bc movw r2, #0xfeee */
/* @0x1f31c0 cmp r1, r3 */
/* @0x1f31c4 movt r2, #0xfeee */
/* @0x1f31c8 lsl r7, r4, #2 */
/* @0x1f31cc beq 0x1f320c <_Z22FINALIZE_Timeline_Mainv+0x98> */
/* @0x1f31d0 ldr r3, [r5, r4, lsl #2] */
/* @0x1f31d4 add r1, r5, r7 */
/* @0x1f31d8 cmp r3, #0 */
/* @0x1f31dc mov r0, r3 */
/* @0x1f31e0 beq 0x1f320c <_Z22FINALIZE_Timeline_Mainv+0x98> */
/* @0x1f31e4 ldr r3, [r3] */
/* @0x1f31e8 cmp r3, r2 */
/* @0x1f31ec beq 0x1f3204 <_Z22FINALIZE_Timeline_Mainv+0x90> */
/* @0x1f31f0 ldr r3, [r3, #0x4] */
/* @0x1f31f4 blx r3 */
/* @0x1f31f8 ldr r1, [r6, #0x4] */
/* @0x1f31fc ldr r12, [r6] */
/* @0x1f3200 add r1, r1, r7 */
/* @0x1f3204 str r8, [r1] */
/* @0x1f3208 ldr r5, [r6, #0x4] */
/* @0x1f320c add r4, r4, #1 */
/* @0x1f3210 cmp r4, r12 */
/* @0x1f3214 blt 0x1f31b0 <_Z22FINALIZE_Timeline_Mainv+0x3c> */
/* @0x1f3218 mov r0, r5 */
/* @0x1f321c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3220 mov r3, #0 */
/* @0x1f3224 str r3, [r6, #0x4] */
/* @0x1f3228 mov r3, #0 */
/* @0x1f322c str r3, [r6] */
/* @0x1f3230 mov r0, r6 */
/* @0x1f3234 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f3238 ldr r3, [pc, #0xcc] */
/* @0x1f323c mov r2, #0 */
/* @0x1f3240 add r3, pc, r3 */
/* @0x1f3244 str r2, [r3] */
/* @0x1f3248 ldr r3, [pc, #0xc0] */
/* @0x1f324c add r3, pc, r3 */
/* @0x1f3250 ldr r5, [r3, #0x4] */
/* @0x1f3254 cmp r5, #0 */
/* @0x1f3258 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x1f325c ldr r6, [r5, #0x4] */
/* @0x1f3260 cmp r6, #0 */
/* @0x1f3264 beq 0x1f32e8 <_Z22FINALIZE_Timeline_Mainv+0x174> */
/* @0x1f3268 ldr r3, [r5] */
/* @0x1f326c cmp r3, #0 */
/* @0x1f3270 ble 0x1f32b8 <_Z22FINALIZE_Timeline_Mainv+0x144> */
/* @0x1f3274 mov r4, #0 */
/* @0x1f3278 mov r7, r4 */
/* @0x1f327c ldr r0, [r6, r4, lsl #2] */
/* @0x1f3280 lsl r6, r4, #2 */
/* @0x1f3284 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1f3288 cmp r0, #0 */
/* @0x1f328c beq 0x1f329c <_Z22FINALIZE_Timeline_Mainv+0x128> */
/* @0x1f3290 ldr r3, [r5, #0x4] */
/* @0x1f3294 ldr r0, [r3, r4, lsl #2] */
/* @0x1f3298 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f329c ldr r2, [r5] */
/* @0x1f32a0 add r4, r4, #1 */
/* @0x1f32a4 ldr r3, [r5, #0x4] */
/* @0x1f32a8 cmp r4, r2 */
/* @0x1f32ac str r7, [r3, r6] */
/* @0x1f32b0 ldr r6, [r5, #0x4] */
/* @0x1f32b4 blt 0x1f327c <_Z22FINALIZE_Timeline_Mainv+0x108> */
/* @0x1f32b8 mov r0, r6 */
/* @0x1f32bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f32c0 mov r3, #0 */
/* @0x1f32c4 str r3, [r5, #0x4] */
/* @0x1f32c8 mov r4, #0 */
/* @0x1f32cc mov r0, r5 */
/* @0x1f32d0 str r4, [r5] */
/* @0x1f32d4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1f32d8 ldr r3, [pc, #0x34] */
/* @0x1f32dc add r3, pc, r3 */
/* @0x1f32e0 str r4, [r3, #0x4] */
/* @0x1f32e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f32e8 mov r0, r6 */
/* @0x1f32ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f32f0 str r6, [r5, #0x4] */
/* @0x1f32f4 b 0x1f32c8 <_Z22FINALIZE_Timeline_Mainv+0x154> */
/* @0x1f32f8 mov r0, r5 */
/* @0x1f32fc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3300 str r5, [r6, #0x4] */
/* @0x1f3304 b 0x1f3228 <_Z22FINALIZE_Timeline_Mainv+0xb4> */
/* @0x1f3308 subseq pc, r5, r0, ror pc */
/* @0x1f330c subseq pc, r5, r12, lsr #29 */
/* @0x1f3310 subseq pc, r5, r0, lsr #29 */
/* @0x1f3314 subseq pc, r5, r0, lsl lr */

/* ── FUNC 0x1f3318 · cARRAY_STRUCTURE<bool>::~cARRAY_STRUCTURE() · size=60 · insn=15 */
/* @0x1f3318 push {r3, r4, r5, lr} */
/* @0x1f331c mov r4, r0 */
/* @0x1f3320 ldr r5, [r0, #0x4] */
/* @0x1f3324 subs r0, r5, #0 */
/* @0x1f3328 beq 0x1f3348 <_ZN16cARRAY_STRUCTUREIbED2Ev+0x30> */
/* @0x1f332c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3330 mov r3, #0 */
/* @0x1f3334 str r3, [r4, #0x4] */
/* @0x1f3338 mov r3, #0 */
/* @0x1f333c mov r0, r4 */
/* @0x1f3340 str r3, [r4] */
/* @0x1f3344 pop {r3, r4, r5, pc} */
/* @0x1f3348 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f334c str r5, [r4, #0x4] */
/* @0x1f3350 b 0x1f3338 <_ZN16cARRAY_STRUCTUREIbED2Ev+0x20> */

/* ── FUNC 0x1f3318 · cARRAY_STRUCTURE<bool>::~cARRAY_STRUCTURE() · alias of the symbol above · insn=0 */

/* ── FUNC 0x1f3354 · Variable_Global_Init() · size=104 · insn=26 */
/* @0x1f3354 push {r4, r5, lr} */
/* @0x1f3358 sub sp, sp, #12 */
/* @0x1f335c ldr r4, [pc, #0x50] */
/* @0x1f3360 mov r5, #0 */
/* @0x1f3364 ldr r2, [pc, #0x4c] */
/* @0x1f3368 movw r1, #0x2710 */
/* @0x1f336c ldr r4, [pc, r4] */
/* @0x1f3370 mov r3, #106 */
/* @0x1f3374 add r2, pc, r2 */
/* @0x1f3378 ldr r0, [r4, #0x4] */
/* @0x1f337c str r5, [sp] */
/* @0x1f3380 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f3384 movw r12, #0x2710 */
/* @0x1f3388 mov r3, r5 */
/* @0x1f338c mov r1, r12 */
/* @0x1f3390 mov r2, r5 */
/* @0x1f3394 str r12, [r4] */
/* @0x1f3398 str r0, [r4, #0x4] */
/* @0x1f339c strb r2, [r0, r3] */
/* @0x1f33a0 add r3, r3, #1 */
/* @0x1f33a4 cmp r3, r1 */
/* @0x1f33a8 bne 0x1f339c <_Z20Variable_Global_Initv+0x48> */
/* @0x1f33ac add sp, sp, #12 */
/* @0x1f33b0 pop {r4, r5, pc} */
/* @0x1f33b4 ldrheq sp, [pc], -r12 */
/* @0x1f33b8 andseq r9, r5, r0, asr #29 */

/* ── FUNC 0x1f33bc · Variable_Global_Declare(int) · size=200 · insn=50 */
/* @0x1f33bc sub r0, r0, #99328 */
/* @0x1f33c0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f33c4 subs r5, r0, #672 */
/* @0x1f33c8 sub sp, sp, #8 */
/* @0x1f33cc bmi 0x1f33f0 <_Z23Variable_Global_Declarei+0x34> */
/* @0x1f33d0 ldr r4, [pc, #0xa4] */
/* @0x1f33d4 ldr r4, [pc, r4] */
/* @0x1f33d8 ldr r6, [r4] */
/* @0x1f33dc cmp r5, r6 */
/* @0x1f33e0 bge 0x1f33f8 <_Z23Variable_Global_Declarei+0x3c> */
/* @0x1f33e4 ldr r7, [r4, #0x4] */
/* @0x1f33e8 mov r3, #1 */
/* @0x1f33ec strb r3, [r7, r5] */
/* @0x1f33f0 add sp, sp, #8 */
/* @0x1f33f4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f33f8 adds r8, r6, #1000 */
/* @0x1f33fc bne 0x1f3444 <_Z23Variable_Global_Declarei+0x88> */
/* @0x1f3400 ldr r7, [r4, #0x4] */
/* @0x1f3404 subs r0, r7, #0 */
/* @0x1f3408 beq 0x1f3470 <_Z23Variable_Global_Declarei+0xb4> */
/* @0x1f340c mov r7, r8 */
/* @0x1f3410 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3414 str r8, [r4, #0x4] */
/* @0x1f3418 add r12, r6, #996 */
/* @0x1f341c sub r3, r6, #1 */
/* @0x1f3420 add r12, r12, #3 */
/* @0x1f3424 add r3, r7, r3 */
/* @0x1f3428 add r12, r7, r12 */
/* @0x1f342c mov r2, #0 */
/* @0x1f3430 str r8, [r4] */
/* @0x1f3434 strb r2, [r3, #0x1]! */
/* @0x1f3438 cmp r3, r12 */
/* @0x1f343c bne 0x1f3434 <_Z23Variable_Global_Declarei+0x78> */
/* @0x1f3440 b 0x1f33e8 <_Z23Variable_Global_Declarei+0x2c> */
/* @0x1f3444 ldr r2, [pc, #0x34] */
/* @0x1f3448 mov r3, #0 */
/* @0x1f344c ldr r0, [r4, #0x4] */
/* @0x1f3450 mov r1, r8 */
/* @0x1f3454 str r3, [sp] */
/* @0x1f3458 add r2, pc, r2 */
/* @0x1f345c mov r3, #106 */
/* @0x1f3460 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f3464 mov r7, r0 */
/* @0x1f3468 str r0, [r4, #0x4] */
/* @0x1f346c b 0x1f3418 <_Z23Variable_Global_Declarei+0x5c> */
/* @0x1f3470 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f3474 str r7, [r4, #0x4] */
/* @0x1f3478 b 0x1f3418 <_Z23Variable_Global_Declarei+0x5c> */
/* @0x1f347c andseq sp, pc, r4, asr r10 */
/* @0x1f3480 ldrsbeq r9, [r5], -r12 */

/* ── FUNC 0x1f3484 · Variable_Global_Declared(int) · size=56 · insn=14 */
/* @0x1f3484 sub r0, r0, #99328 */
/* @0x1f3488 subs r0, r0, #672 */
/* @0x1f348c bmi 0x1f34b0 <_Z24Variable_Global_Declaredi+0x2c> */
/* @0x1f3490 ldr r3, [pc, #0x20] */
/* @0x1f3494 ldr r3, [pc, r3] */
/* @0x1f3498 ldr r2, [r3] */
/* @0x1f349c cmp r0, r2 */
/* @0x1f34a0 bge 0x1f34b0 <_Z24Variable_Global_Declaredi+0x2c> */
/* @0x1f34a4 ldr r3, [r3, #0x4] */
/* @0x1f34a8 ldrb r0, [r3, r0] */
/* @0x1f34ac bx lr */
/* @0x1f34b0 mov r0, #0 */
/* @0x1f34b4 bx lr */
/* @0x1f34b8 mulseq pc, r4, r9 */

/* ── FUNC 0x1f34bc · Variable_Scope_DeleteVar(int, int) · size=292 · insn=73 */
/* @0x1f34bc ldr r3, [pc, #0x118] */
/* @0x1f34c0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f34c4 ldr r3, [pc, r3] */
/* @0x1f34c8 sub sp, sp, #36 */
/* @0x1f34cc mov r10, r0 */
/* @0x1f34d0 ldr r6, [r3] */
/* @0x1f34d4 mov r7, r1 */
/* @0x1f34d8 cmp r6, #0 */
/* @0x1f34dc beq 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8> */
/* @0x1f34e0 sub r9, r0, #99328 */
/* @0x1f34e4 mov r11, #0 */
/* @0x1f34e8 sub r9, r9, #672 */
/* @0x1f34ec mvn r4, #-16777216 */
/* @0x1f34f0 lsl r8, r9, #4 */
/* @0x1f34f4 b 0x1f3504 <_Z24Variable_Scope_DeleteVarii+0x48> */
/* @0x1f34f8 ldr r6, [r6, #0xc] */
/* @0x1f34fc cmp r6, #0 */
/* @0x1f3500 beq 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8> */
/* @0x1f3504 ldr r3, [r6, #0x24] */
/* @0x1f3508 cmp r3, #0 */
/* @0x1f350c beq 0x1f353c <_Z24Variable_Scope_DeleteVarii+0x80> */
/* @0x1f3510 ldr r1, [r6, #0x4] */
/* @0x1f3514 cmp r1, #0 */
/* @0x1f3518 add r1, r1, r8 */
/* @0x1f351c beq 0x1f3570 <_Z24Variable_Scope_DeleteVarii+0xb4> */
/* @0x1f3520 mov r2, r7 */
/* @0x1f3524 mov r0, sp */
/* @0x1f3528 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f352c ldr r3, [sp, #0xc] */
/* @0x1f3530 mvn r2, #-16777216 */
/* @0x1f3534 cmp r3, r4 */
/* @0x1f3538 bne 0x1f3584 <_Z24Variable_Scope_DeleteVarii+0xc8> */
/* @0x1f353c cmp r11, #0 */
/* @0x1f3540 bne 0x1f34f8 <_Z24Variable_Scope_DeleteVarii+0x3c> */
/* @0x1f3544 mov r0, r11 */
/* @0x1f3548 mvn r1, #10 */
/* @0x1f354c mov r2, r10 */
/* @0x1f3550 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x1f3554 ldr r6, [r6, #0xc] */
/* @0x1f3558 cmp r6, #0 */
/* @0x1f355c mov r11, r0 */
/* @0x1f3560 bne 0x1f3504 <_Z24Variable_Scope_DeleteVarii+0x48> */
/* @0x1f3564 mov r0, #1 */
/* @0x1f3568 add sp, sp, #36 */
/* @0x1f356c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f3570 mov r1, r9 */
/* @0x1f3574 mov r0, r6 */
/* @0x1f3578 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f357c mov r1, r0 */
/* @0x1f3580 b 0x1f3520 <_Z24Variable_Scope_DeleteVarii+0x64> */
/* @0x1f3584 ldr r0, [sp, #0x8] */
/* @0x1f3588 ands r0, r0, #2 */
/* @0x1f358c beq 0x1f3568 <_Z24Variable_Scope_DeleteVarii+0xac> */
/* @0x1f3590 mov r0, r6 */
/* @0x1f3594 str r2, [sp, #0x1c] */
/* @0x1f3598 mov r4, #0 */
/* @0x1f359c mov r5, #0 */
/* @0x1f35a0 strd r4, r5, [sp, #16] */
/* @0x1f35a4 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x1f35a8 ldr r3, [r6, #0x4] */
/* @0x1f35ac cmp r3, #0 */
/* @0x1f35b0 beq 0x1f35cc <_Z24Variable_Scope_DeleteVarii+0x110> */
/* @0x1f35b4 add r0, r3, r8 */
/* @0x1f35b8 mov r2, r7 */
/* @0x1f35bc add r1, sp, #16 */
/* @0x1f35c0 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f35c4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x1f35c8 b 0x1f3564 <_Z24Variable_Scope_DeleteVarii+0xa8> */
/* @0x1f35cc mov r0, r6 */
/* @0x1f35d0 mov r1, r9 */
/* @0x1f35d4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f35d8 b 0x1f35b8 <_Z24Variable_Scope_DeleteVarii+0xfc> */
/* @0x1f35dc andseq r10, pc, r4, ror #15 */

/* ── FUNC 0x1f35e0 · Variable_Scope_SetVar(int, int, RValue*) · size=440 · insn=110 */
/* @0x1f35e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f35e4 mov r11, r0 */
/* @0x1f35e8 ldr r10, [pc, #0x1a4] */
/* @0x1f35ec sub sp, sp, #12 */
/* @0x1f35f0 mov r9, r1 */
/* @0x1f35f4 mov r8, r2 */
/* @0x1f35f8 ldr r10, [pc, r10] */
/* @0x1f35fc ldr r4, [r10] */
/* @0x1f3600 cmp r4, #0 */
/* @0x1f3604 beq 0x1f3754 <_Z21Variable_Scope_SetVariiP6RValue+0x174> */
/* @0x1f3608 sub r7, r0, #99328 */
/* @0x1f360c mov r2, #0 */
/* @0x1f3610 sub r7, r7, #672 */
/* @0x1f3614 mvn r6, #-16777216 */
/* @0x1f3618 lsl r5, r7, #4 */
/* @0x1f361c b 0x1f362c <_Z21Variable_Scope_SetVariiP6RValue+0x4c> */
/* @0x1f3620 ldr r4, [r4, #0xc] */
/* @0x1f3624 cmp r4, #0 */
/* @0x1f3628 beq 0x1f3680 <_Z21Variable_Scope_SetVariiP6RValue+0xa0> */
/* @0x1f362c ldr r3, [r4, #0x24] */
/* @0x1f3630 cmp r3, #0 */
/* @0x1f3634 beq 0x1f3658 <_Z21Variable_Scope_SetVariiP6RValue+0x78> */
/* @0x1f3638 ldr r3, [r4, #0x4] */
/* @0x1f363c cmp r3, #0 */
/* @0x1f3640 add r0, r3, r5 */
/* @0x1f3644 beq 0x1f36bc <_Z21Variable_Scope_SetVariiP6RValue+0xdc> */
/* @0x1f3648 ldr r3, [r0, #0xc] */
/* @0x1f364c bic r3, r3, #-16777216 */
/* @0x1f3650 cmp r3, r6 */
/* @0x1f3654 bne 0x1f36e0 <_Z21Variable_Scope_SetVariiP6RValue+0x100> */
/* @0x1f3658 cmp r2, #0 */
/* @0x1f365c bne 0x1f3620 <_Z21Variable_Scope_SetVariiP6RValue+0x40> */
/* @0x1f3660 mov r0, r2 */
/* @0x1f3664 mvn r1, #10 */
/* @0x1f3668 mov r2, r11 */
/* @0x1f366c bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x1f3670 ldr r4, [r4, #0xc] */
/* @0x1f3674 cmp r4, #0 */
/* @0x1f3678 mov r2, r0 */
/* @0x1f367c bne 0x1f362c <_Z21Variable_Scope_SetVariiP6RValue+0x4c> */
/* @0x1f3680 ldr r0, [r10] */
/* @0x1f3684 ldr r3, [r0, #0x24] */
/* @0x1f3688 cmp r3, #0 */
/* @0x1f368c beq 0x1f36b4 <_Z21Variable_Scope_SetVariiP6RValue+0xd4> */
/* @0x1f3690 ldr r3, [r0, #0x4] */
/* @0x1f3694 sub r1, r11, #99328 */
/* @0x1f3698 sub r1, r1, #672 */
/* @0x1f369c cmp r3, #0 */
/* @0x1f36a0 beq 0x1f3784 <_Z21Variable_Scope_SetVariiP6RValue+0x1a4> */
/* @0x1f36a4 add r5, r3, r1, lsl #4 */
/* @0x1f36a8 mov r4, r0 */
/* @0x1f36ac cmp r5, #0 */
/* @0x1f36b0 bne 0x1f36f8 <_Z21Variable_Scope_SetVariiP6RValue+0x118> */
/* @0x1f36b4 add sp, sp, #12 */
/* @0x1f36b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f36bc mov r0, r4 */
/* @0x1f36c0 mov r1, r7 */
/* @0x1f36c4 str r2, [sp, #0x4] */
/* @0x1f36c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f36cc ldr r2, [sp, #0x4] */
/* @0x1f36d0 ldr r3, [r0, #0xc] */
/* @0x1f36d4 bic r3, r3, #-16777216 */
/* @0x1f36d8 cmp r3, r6 */
/* @0x1f36dc beq 0x1f3658 <_Z21Variable_Scope_SetVariiP6RValue+0x78> */
/* @0x1f36e0 ldr r3, [r4, #0x4] */
/* @0x1f36e4 cmp r3, #0 */
/* @0x1f36e8 beq 0x1f3770 <_Z21Variable_Scope_SetVariiP6RValue+0x190> */
/* @0x1f36ec add r5, r3, r5 */
/* @0x1f36f0 cmp r5, #0 */
/* @0x1f36f4 beq 0x1f3680 <_Z21Variable_Scope_SetVariiP6RValue+0xa0> */
/* @0x1f36f8 ldr r6, [r5, #0xc] */
/* @0x1f36fc mov r0, r4 */
/* @0x1f3700 bic r3, r6, #-16777216 */
/* @0x1f3704 cmp r3, #6 */
/* @0x1f3708 bne 0x1f371c <_Z21Variable_Scope_SetVariiP6RValue+0x13c> */
/* @0x1f370c ldr r3, [r5] */
/* @0x1f3710 ldr r3, [r3, #0x48] */
/* @0x1f3714 cmp r3, #2 */
/* @0x1f3718 beq 0x1f375c <_Z21Variable_Scope_SetVariiP6RValue+0x17c> */
/* @0x1f371c ldr r4, [r5, #0x8] */
/* @0x1f3720 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x1f3724 mov r0, r5 */
/* @0x1f3728 mov r1, r8 */
/* @0x1f372c mov r2, r9 */
/* @0x1f3730 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f3734 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x1f3738 mvn r3, #-16777216 */
/* @0x1f373c cmp r6, r3 */
/* @0x1f3740 strne r4, [r5, #0x8] */
/* @0x1f3744 moveq r3, #7 */
/* @0x1f3748 streq r3, [r5, #0x8] */
/* @0x1f374c add sp, sp, #12 */
/* @0x1f3750 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f3754 mov r0, r4 */
/* @0x1f3758 b 0x1f3684 <_Z21Variable_Scope_SetVariiP6RValue+0xa4> */
/* @0x1f375c mov r1, r8 */
/* @0x1f3760 mov r2, r5 */
/* @0x1f3764 add sp, sp, #12 */
/* @0x1f3768 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f376c b 0x24931c <_Z17Call_Accessor_SetP12YYObjectBaseP6RValueS2_> */
/* @0x1f3770 mov r1, r7 */
/* @0x1f3774 mov r0, r4 */
/* @0x1f3778 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f377c mov r5, r0 */
/* @0x1f3780 b 0x1f36f0 <_Z21Variable_Scope_SetVariiP6RValue+0x110> */
/* @0x1f3784 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3788 ldr r4, [r10] */
/* @0x1f378c mov r5, r0 */
/* @0x1f3790 b 0x1f36ac <_Z21Variable_Scope_SetVariiP6RValue+0xcc> */
/* @0x1f3794 ldrheq r10, [pc], -r0 */

/* ── FUNC 0x1f3798 · Variable_Scope_GetVar(int, int, RValue*) · size=352 · insn=88 */
/* @0x1f3798 ldr r3, [pc, #0x154] */
/* @0x1f379c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1f37a0 ldr r3, [pc, r3] */
/* @0x1f37a4 mvn r6, #-16777216 */
/* @0x1f37a8 sub sp, sp, #40 */
/* @0x1f37ac ldr r4, [r3] */
/* @0x1f37b0 mov r5, r2 */
/* @0x1f37b4 mov r7, r1 */
/* @0x1f37b8 str r6, [r2, #0xc] */
/* @0x1f37bc cmp r4, #0 */
/* @0x1f37c0 beq 0x1f38a8 <_Z21Variable_Scope_GetVariiP6RValue+0x110> */
/* @0x1f37c4 sub r9, r0, #99328 */
/* @0x1f37c8 sub r9, r9, #672 */
/* @0x1f37cc lsl r8, r9, #4 */
/* @0x1f37d0 b 0x1f380c <_Z21Variable_Scope_GetVariiP6RValue+0x74> */
/* @0x1f37d4 ldr r3, [r4, #0x4] */
/* @0x1f37d8 cmp r3, #0 */
/* @0x1f37dc add r1, r3, r8 */
/* @0x1f37e0 beq 0x1f384c <_Z21Variable_Scope_GetVariiP6RValue+0xb4> */
/* @0x1f37e4 mov r0, r5 */
/* @0x1f37e8 mov r2, r7 */
/* @0x1f37ec bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f37f0 ldr r3, [r5, #0xc] */
/* @0x1f37f4 cmp r3, r6 */
/* @0x1f37f8 mov r10, r0 */
/* @0x1f37fc bne 0x1f3824 <_Z21Variable_Scope_GetVariiP6RValue+0x8c> */
/* @0x1f3800 ldr r4, [r4, #0xc] */
/* @0x1f3804 cmp r4, #0 */
/* @0x1f3808 beq 0x1f3860 <_Z21Variable_Scope_GetVariiP6RValue+0xc8> */
/* @0x1f380c ldr r3, [r4, #0x24] */
/* @0x1f3810 cmp r3, #0 */
/* @0x1f3814 bne 0x1f37d4 <_Z21Variable_Scope_GetVariiP6RValue+0x3c> */
/* @0x1f3818 ldr r3, [r5, #0xc] */
/* @0x1f381c cmp r3, r6 */
/* @0x1f3820 beq 0x1f3800 <_Z21Variable_Scope_GetVariiP6RValue+0x68> */
/* @0x1f3824 bic r12, r3, #-16777216 */
/* @0x1f3828 mov r10, #1 */
/* @0x1f382c cmp r12, #6 */
/* @0x1f3830 beq 0x1f3870 <_Z21Variable_Scope_GetVariiP6RValue+0xd8> */
/* @0x1f3834 mvn r2, #-16777216 */
/* @0x1f3838 cmp r3, r2 */
/* @0x1f383c beq 0x1f38a8 <_Z21Variable_Scope_GetVariiP6RValue+0x110> */
/* @0x1f3840 mov r0, r10 */
/* @0x1f3844 add sp, sp, #40 */
/* @0x1f3848 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f384c mov r1, r9 */
/* @0x1f3850 mov r0, r4 */
/* @0x1f3854 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3858 mov r1, r0 */
/* @0x1f385c b 0x1f37e4 <_Z21Variable_Scope_GetVariiP6RValue+0x4c> */
/* @0x1f3860 ldr r3, [r5, #0xc] */
/* @0x1f3864 bic r12, r3, #-16777216 */
/* @0x1f3868 cmp r12, #6 */
/* @0x1f386c bne 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c> */
/* @0x1f3870 ldr r1, [r5] */
/* @0x1f3874 cmp r1, #0 */
/* @0x1f3878 beq 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c> */
/* @0x1f387c ldr r2, [r1, #0x48] */
/* @0x1f3880 cmp r2, #2 */
/* @0x1f3884 bne 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c> */
/* @0x1f3888 add r2, sp, #40 */
/* @0x1f388c mov r0, r4 */
/* @0x1f3890 str r12, [sp, #0x24] */
/* @0x1f3894 str r1, [r2, #-0x10]! */
/* @0x1f3898 mov r1, r5 */
/* @0x1f389c bl 0x248fec <_Z17Call_Accessor_GetP12YYObjectBaseP6RValueS2_> */
/* @0x1f38a0 ldr r3, [r5, #0xc] */
/* @0x1f38a4 b 0x1f3834 <_Z21Variable_Scope_GetVariiP6RValue+0x9c> */
/* @0x1f38a8 mov r0, #0 */
/* @0x1f38ac add r1, sp, #8 */
/* @0x1f38b0 bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1f38b4 cmp r0, #0 */
/* @0x1f38b8 beq 0x1f3840 <_Z21Variable_Scope_GetVariiP6RValue+0xa8> */
/* @0x1f38bc add r2, sp, #16 */
/* @0x1f38c0 ldr r0, [sp, #0x8] */
/* @0x1f38c4 add r1, sp, #12 */
/* @0x1f38c8 add r3, sp, #24 */
/* @0x1f38cc str r3, [sp] */
/* @0x1f38d0 add r3, sp, #20 */
/* @0x1f38d4 bl 0xcdf0c <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_> */
/* @0x1f38d8 mov r0, r5 */
/* @0x1f38dc bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue> */
/* @0x1f38e0 ldr r3, [r5] */
/* @0x1f38e4 ldr r2, [sp, #0x10] */
/* @0x1f38e8 mov r10, #1 */
/* @0x1f38ec str r2, [r3, #0x68] */
/* @0x1f38f0 b 0x1f3840 <_Z21Variable_Scope_GetVariiP6RValue+0xa8> */
/* @0x1f38f4 andseq r10, pc, r8, lsl #10 */

/* ── FUNC 0x1f38f8 · Variable_Global_SetVar(int, int, RValue*) · size=140 · insn=35 */
/* @0x1f38f8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1f38fc mov r7, r0 */
/* @0x1f3900 ldr r4, [pc, #0x78] */
/* @0x1f3904 mov r5, r1 */
/* @0x1f3908 mov r6, r2 */
/* @0x1f390c ldr r4, [pc, r4] */
/* @0x1f3910 ldr r0, [r4] */
/* @0x1f3914 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x1f3918 ldr r0, [r4] */
/* @0x1f391c ldr r12, [r0, #0x24] */
/* @0x1f3920 cmp r12, #0 */
/* @0x1f3924 beq 0x1f396c <_Z22Variable_Global_SetVariiP6RValue+0x74> */
/* @0x1f3928 ldr r12, [r0, #0x4] */
/* @0x1f392c sub r7, r7, #99328 */
/* @0x1f3930 sub r1, r7, #672 */
/* @0x1f3934 cmp r12, #0 */
/* @0x1f3938 beq 0x1f3974 <_Z22Variable_Global_SetVariiP6RValue+0x7c> */
/* @0x1f393c add r4, r12, r1, lsl #4 */
/* @0x1f3940 ldr r7, [r4, #0xc] */
/* @0x1f3944 mov r2, r5 */
/* @0x1f3948 mov r1, r6 */
/* @0x1f394c ldr r5, [r4, #0x8] */
/* @0x1f3950 mov r0, r4 */
/* @0x1f3954 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f3958 mvn r3, #-16777216 */
/* @0x1f395c cmp r7, r3 */
/* @0x1f3960 strne r5, [r4, #0x8] */
/* @0x1f3964 moveq r3, #7 */
/* @0x1f3968 streq r3, [r4, #0x8] */
/* @0x1f396c pop {r3, r4, r5, r6, r7, lr} */
/* @0x1f3970 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x1f3974 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3978 mov r4, r0 */
/* @0x1f397c b 0x1f3940 <_Z22Variable_Global_SetVariiP6RValue+0x48> */
/* @0x1f3980 andseq r10, pc, r8, lsr #5 */

/* ── FUNC 0x1f3984 · Variable_Global_GetVar(int, int, RValue*) · size=216 · insn=54 */
/* @0x1f3984 ldr r3, [pc, #0xcc] */
/* @0x1f3988 push {r4, r5, r6, r7, lr} */
/* @0x1f398c ldr r3, [pc, r3] */
/* @0x1f3990 mov r5, r0 */
/* @0x1f3994 sub sp, sp, #36 */
/* @0x1f3998 ldr r0, [r3] */
/* @0x1f399c mov r7, r1 */
/* @0x1f39a0 mov r4, r2 */
/* @0x1f39a4 ldr r12, [r0, #0x24] */
/* @0x1f39a8 cmp r12, #0 */
/* @0x1f39ac beq 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64> */
/* @0x1f39b0 ldr r12, [r0, #0x4] */
/* @0x1f39b4 sub r1, r5, #99328 */
/* @0x1f39b8 sub r1, r1, #672 */
/* @0x1f39bc cmp r12, #0 */
/* @0x1f39c0 beq 0x1f3a4c <_Z22Variable_Global_GetVariiP6RValue+0xc8> */
/* @0x1f39c4 add r1, r12, r1, lsl #4 */
/* @0x1f39c8 mov r2, r7 */
/* @0x1f39cc mov r0, r4 */
/* @0x1f39d0 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f39d4 ldr r2, [r4, #0xc] */
/* @0x1f39d8 mvn r3, #-16777216 */
/* @0x1f39dc cmp r2, r3 */
/* @0x1f39e0 mov r6, r0 */
/* @0x1f39e4 beq 0x1f39f4 <_Z22Variable_Global_GetVariiP6RValue+0x70> */
/* @0x1f39e8 mov r0, r6 */
/* @0x1f39ec add sp, sp, #36 */
/* @0x1f39f0 pop {r4, r5, r6, r7, pc} */
/* @0x1f39f4 mov r2, r5 */
/* @0x1f39f8 mvn r1, #4 */
/* @0x1f39fc mov r0, #0 */
/* @0x1f3a00 bl 0xd25fc <_Z23Code_Variable_Find_NamePKcii> */
/* @0x1f3a04 add r1, sp, #12 */
/* @0x1f3a08 bl 0xce158 <_Z18Code_Function_FindPKcPi> */
/* @0x1f3a0c cmp r0, #0 */
/* @0x1f3a10 beq 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64> */
/* @0x1f3a14 add r2, sp, #20 */
/* @0x1f3a18 ldr r0, [sp, #0xc] */
/* @0x1f3a1c add r1, sp, #16 */
/* @0x1f3a20 add r3, sp, #28 */
/* @0x1f3a24 str r3, [sp] */
/* @0x1f3a28 add r3, sp, #24 */
/* @0x1f3a2c bl 0xcdf0c <_Z30Code_Function_GET_the_functioniPPKcPPvPiS4_> */
/* @0x1f3a30 mov r0, r4 */
/* @0x1f3a34 bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue> */
/* @0x1f3a38 ldr r3, [r4] */
/* @0x1f3a3c ldr r2, [sp, #0x14] */
/* @0x1f3a40 mov r6, #1 */
/* @0x1f3a44 str r2, [r3, #0x68] */
/* @0x1f3a48 b 0x1f39e8 <_Z22Variable_Global_GetVariiP6RValue+0x64> */
/* @0x1f3a4c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3a50 mov r1, r0 */
/* @0x1f3a54 b 0x1f39c8 <_Z22Variable_Global_GetVariiP6RValue+0x44> */
/* @0x1f3a58 andseq r10, pc, r8, lsr #4 */

/* ── FUNC 0x1f3a5c · Variable_BuiltIn_Find(char const*) · size=220 · insn=55 */
/* @0x1f3a5c ldr r3, [pc, #0xd0] */
/* @0x1f3a60 push {r4, r5, r6, r7, r8, lr} */
/* @0x1f3a64 ldr r3, [pc, r3] */
/* @0x1f3a68 ldr r5, [r3] */
/* @0x1f3a6c bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_> */
/* @0x1f3a70 ldr r1, [r5, #0x8] */
/* @0x1f3a74 ldr r7, [r5, #0x10] */
/* @0x1f3a78 bic r0, r0, #-2147483648 */
/* @0x1f3a7c and r3, r0, r1 */
/* @0x1f3a80 lsl r4, r3, #1 */
/* @0x1f3a84 add r2, r4, r3 */
/* @0x1f3a88 add r2, r7, r2, lsl #2 */
/* @0x1f3a8c ldr r2, [r2, #0x8] */
/* @0x1f3a90 cmp r2, #0 */
/* @0x1f3a94 beq 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8> */
/* @0x1f3a98 cmp r0, r2 */
/* @0x1f3a9c beq 0x1f3b14 <_Z21Variable_BuiltIn_FindPKc+0xb8> */
/* @0x1f3aa0 ldr r8, [r5] */
/* @0x1f3aa4 and r2, r1, r2 */
/* @0x1f3aa8 add r12, r3, r8 */
/* @0x1f3aac rsb r2, r2, r12 */
/* @0x1f3ab0 tst r2, r1 */
/* @0x1f3ab4 bmi 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8> */
/* @0x1f3ab8 mov r12, #0 */
/* @0x1f3abc b 0x1f3ad0 <_Z21Variable_BuiltIn_FindPKc+0x74> */
/* @0x1f3ac0 cmp r0, r2 */
/* @0x1f3ac4 beq 0x1f3b0c <_Z21Variable_BuiltIn_FindPKc+0xb0> */
/* @0x1f3ac8 cmp r5, r12 */
/* @0x1f3acc blt 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8> */
/* @0x1f3ad0 add r3, r3, #1 */
/* @0x1f3ad4 add r12, r12, #1 */
/* @0x1f3ad8 and r3, r1, r3 */
/* @0x1f3adc add r6, r3, r8 */
/* @0x1f3ae0 lsl r4, r3, #1 */
/* @0x1f3ae4 add r2, r4, r3 */
/* @0x1f3ae8 add r2, r7, r2, lsl #2 */
/* @0x1f3aec ldr r2, [r2, #0x8] */
/* @0x1f3af0 and r5, r1, r2 */
/* @0x1f3af4 cmp r2, #0 */
/* @0x1f3af8 rsb r5, r5, r6 */
/* @0x1f3afc and r5, r5, r1 */
/* @0x1f3b00 bne 0x1f3ac0 <_Z21Variable_BuiltIn_FindPKc+0x64> */
/* @0x1f3b04 mvn r0, #0 */
/* @0x1f3b08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f3b0c cmn r3, #1 */
/* @0x1f3b10 beq 0x1f3b2c <_Z21Variable_BuiltIn_FindPKc+0xd0> */
/* @0x1f3b14 add r3, r4, r3 */
/* @0x1f3b18 add r7, r7, r3, lsl #2 */
/* @0x1f3b1c cmn r7, #4 */
/* @0x1f3b20 beq 0x1f3b04 <_Z21Variable_BuiltIn_FindPKc+0xa8> */
/* @0x1f3b24 ldr r0, [r7, #0x4] */
/* @0x1f3b28 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f3b2c mov r0, r3 */
/* @0x1f3b30 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f3b34 andseq sp, pc, r8, asr #7 */

/* ── FUNC 0x1f3b38 · Variable_BuiltIn_Find_Name(int) · size=84 · insn=21 */
/* @0x1f3b38 cmp r0, #0 */
/* @0x1f3b3c blt 0x1f3b70 <_Z26Variable_BuiltIn_Find_Namei+0x38> */
/* @0x1f3b40 ldr r3, [pc, #0x34] */
/* @0x1f3b44 ldr r3, [pc, r3] */
/* @0x1f3b48 ldr r3, [r3] */
/* @0x1f3b4c cmp r0, r3 */
/* @0x1f3b50 bge 0x1f3b64 <_Z26Variable_BuiltIn_Find_Namei+0x2c> */
/* @0x1f3b54 ldr r3, [pc, #0x24] */
/* @0x1f3b58 ldr r3, [pc, r3] */
/* @0x1f3b5c ldr r0, [r3, r0, lsl #4] */
/* @0x1f3b60 bx lr */
/* @0x1f3b64 ldr r0, [pc, #0x18] */
/* @0x1f3b68 add r0, pc, r0 */
/* @0x1f3b6c bx lr */
/* @0x1f3b70 ldr r0, [pc, #0x10] */
/* @0x1f3b74 add r0, pc, r0 */
/* @0x1f3b78 bx lr */
/* @0x1f3b7c ldrsheq r10, [pc], -r0 */
/* @0x1f3b80 andseq r10, pc, r0, ror #1 */
/* @0x1f3b84 andseq lr, r5, r8, asr r12 */
/* @0x1f3b88 andseq lr, r5, r12, asr #24 */

/* ── FUNC 0x1f3b8c · Variable_GetValue_Direct(YYObjectBase*, int, int, RValue*) · size=156 · insn=39 */
/* @0x1f3b8c mov r12, r1 */
/* @0x1f3b90 movw r1, #0x270f */
/* @0x1f3b94 cmp r12, r1 */
/* @0x1f3b98 push {r4, lr} */
/* @0x1f3b9c sub sp, sp, #8 */
/* @0x1f3ba0 bls 0x1f3be4 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x58> */
/* @0x1f3ba4 ldr r1, [r0, #0x24] */
/* @0x1f3ba8 cmp r1, #0 */
/* @0x1f3bac beq 0x1f3bd8 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x4c> */
/* @0x1f3bb0 ldr r4, [r0, #0x4] */
/* @0x1f3bb4 sub r12, r12, #99328 */
/* @0x1f3bb8 sub r1, r12, #672 */
/* @0x1f3bbc cmp r4, #0 */
/* @0x1f3bc0 beq 0x1f3c08 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x7c> */
/* @0x1f3bc4 add r1, r4, r1, lsl #4 */
/* @0x1f3bc8 mov r0, r3 */
/* @0x1f3bcc add sp, sp, #8 */
/* @0x1f3bd0 pop {r4, lr} */
/* @0x1f3bd4 b 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f3bd8 mov r0, #0 */
/* @0x1f3bdc add sp, sp, #8 */
/* @0x1f3be0 pop {r4, pc} */
/* @0x1f3be4 ldr lr, [pc, #0x38] */
/* @0x1f3be8 mov r1, r2 */
/* @0x1f3bec mov r2, r3 */
/* @0x1f3bf0 ldr lr, [pc, lr] */
/* @0x1f3bf4 add r12, lr, r12, lsl #4 */
/* @0x1f3bf8 ldr r3, [r12, #0x4] */
/* @0x1f3bfc blx r3 */
/* @0x1f3c00 add sp, sp, #8 */
/* @0x1f3c04 pop {r4, pc} */
/* @0x1f3c08 str r2, [sp, #0x4] */
/* @0x1f3c0c str r3, [sp] */
/* @0x1f3c10 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3c14 ldr r3, [sp] */
/* @0x1f3c18 ldr r2, [sp, #0x4] */
/* @0x1f3c1c mov r1, r0 */
/* @0x1f3c20 b 0x1f3bc8 <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue+0x3c> */
/* @0x1f3c24 andseq r10, pc, r8, asr #32 */

/* ── FUNC 0x1f3c28 · Variable_SetValue_Direct(YYObjectBase*, int, int, RValue*) · size=184 · insn=46 */
/* @0x1f3c28 movw r12, #0x270f */
/* @0x1f3c2c cmp r1, r12 */
/* @0x1f3c30 push {r4, lr} */
/* @0x1f3c34 mov r12, r0 */
/* @0x1f3c38 sub sp, sp, #8 */
/* @0x1f3c3c bgt 0x1f3c64 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x3c> */
/* @0x1f3c40 ldr r12, [pc, #0x94] */
/* @0x1f3c44 ldr r12, [pc, r12] */
/* @0x1f3c48 add r1, r12, r1, lsl #4 */
/* @0x1f3c4c ldrb r12, [r1, #0xc] */
/* @0x1f3c50 cmp r12, #0 */
/* @0x1f3c54 bne 0x1f3ca4 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x7c> */
/* @0x1f3c58 mov r0, r12 */
/* @0x1f3c5c add sp, sp, #8 */
/* @0x1f3c60 pop {r4, pc} */
/* @0x1f3c64 ldr r4, [r0, #0x24] */
/* @0x1f3c68 cmp r4, #0 */
/* @0x1f3c6c moveq r12, #1 */
/* @0x1f3c70 beq 0x1f3c58 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x30> */
/* @0x1f3c74 ldr r12, [r12, #0x4] */
/* @0x1f3c78 sub r1, r1, #99328 */
/* @0x1f3c7c sub r1, r1, #672 */
/* @0x1f3c80 cmp r12, #0 */
/* @0x1f3c84 beq 0x1f3cc4 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x9c> */
/* @0x1f3c88 add r0, r12, r1, lsl #4 */
/* @0x1f3c8c mov r1, r3 */
/* @0x1f3c90 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f3c94 mov r12, #1 */
/* @0x1f3c98 mov r0, r12 */
/* @0x1f3c9c add sp, sp, #8 */
/* @0x1f3ca0 pop {r4, pc} */
/* @0x1f3ca4 ldr r12, [r1, #0x8] */
/* @0x1f3ca8 mov r1, r2 */
/* @0x1f3cac mov r2, r3 */
/* @0x1f3cb0 blx r12 */
/* @0x1f3cb4 mov r12, r0 */
/* @0x1f3cb8 mov r0, r12 */
/* @0x1f3cbc add sp, sp, #8 */
/* @0x1f3cc0 pop {r4, pc} */
/* @0x1f3cc4 str r2, [sp, #0x4] */
/* @0x1f3cc8 str r3, [sp] */
/* @0x1f3ccc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f3cd0 ldr r3, [sp] */
/* @0x1f3cd4 ldr r2, [sp, #0x4] */
/* @0x1f3cd8 b 0x1f3c8c <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue+0x64> */
/* @0x1f3cdc ldrsheq r9, [pc], -r4 */

/* ── FUNC 0x1f3ce0 · Variable_GetValue(int, int, int, RValue*) · size=684 · insn=171 */
/* @0x1f3ce0 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3ce4 cmn r0, #3 */
/* @0x1f3ce8 ldr r6, [pc, #0x280] */
/* @0x1f3cec mov r4, #0 */
/* @0x1f3cf0 ldr r12, [pc, #0x27c] */
/* @0x1f3cf4 add r6, pc, r6 */
/* @0x1f3cf8 ldr r7, [r6, r12] */
/* @0x1f3cfc strb r4, [r7] */
/* @0x1f3d00 beq 0x1f3f0c <_Z17Variable_GetValueiiiP6RValue+0x22c> */
/* @0x1f3d04 cmp r0, #0 */
/* @0x1f3d08 blt 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3d0c movw r12, #0x869f */
/* @0x1f3d10 movt r12, #0x1 */
/* @0x1f3d14 cmp r0, r12 */
/* @0x1f3d18 ble 0x1f3e7c <_Z17Variable_GetValueiiiP6RValue+0x19c> */
/* @0x1f3d1c ldr r12, [pc, #0x254] */
/* @0x1f3d20 ldr r12, [r6, r12] */
/* @0x1f3d24 ldr r4, [r12, #0x4] */
/* @0x1f3d28 ldr r12, [r12] */
/* @0x1f3d2c and r4, r0, r4 */
/* @0x1f3d30 ldr r12, [r12, r4, lsl #3] */
/* @0x1f3d34 cmp r12, #0 */
/* @0x1f3d38 bne 0x1f3d4c <_Z17Variable_GetValueiiiP6RValue+0x6c> */
/* @0x1f3d3c b 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3d40 ldr r12, [r12, #0x4] */
/* @0x1f3d44 cmp r12, #0 */
/* @0x1f3d48 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3d4c ldr r4, [r12, #0x8] */
/* @0x1f3d50 cmp r0, r4 */
/* @0x1f3d54 bne 0x1f3d40 <_Z17Variable_GetValueiiiP6RValue+0x60> */
/* @0x1f3d58 ldr r0, [r12, #0xc] */
/* @0x1f3d5c cmp r0, #0 */
/* @0x1f3d60 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3d64 ldrb r12, [r0, #0x68] */
/* @0x1f3d68 cmp r12, #0 */
/* @0x1f3d6c bne 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3d70 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3d74 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f3d78 ldr r12, [pc, #0x1fc] */
/* @0x1f3d7c ldr r10, [r6, r12] */
/* @0x1f3d80 ldr r11, [r10, #0x8] */
/* @0x1f3d84 cmp r11, #0 */
/* @0x1f3d88 ble 0x1f3df0 <_Z17Variable_GetValueiiiP6RValue+0x110> */
/* @0x1f3d8c mov r8, #0 */
/* @0x1f3d90 ldr r12, [r10] */
/* @0x1f3d94 ldr r9, [r12, r8, lsl #2] */
/* @0x1f3d98 ldr r12, [r9, #0x80] */
/* @0x1f3d9c cmp r12, #0 */
/* @0x1f3da0 beq 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */
/* @0x1f3da4 ldr r4, [r12, #0x18] */
/* @0x1f3da8 ldr r12, [r12, #0x48] */
/* @0x1f3dac cmp r0, r4 */
/* @0x1f3db0 movne r5, #0 */
/* @0x1f3db4 moveq r5, #1 */
/* @0x1f3db8 cmp r0, r4 */
/* @0x1f3dbc cmpne r12, #0 */
/* @0x1f3dc0 bne 0x1f3da4 <_Z17Variable_GetValueiiiP6RValue+0xc4> */
/* @0x1f3dc4 cmp r5, #0 */
/* @0x1f3dc8 beq 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */
/* @0x1f3dcc ldrb r12, [r9, #0x68] */
/* @0x1f3dd0 cmp r12, #0 */
/* @0x1f3dd4 bne 0x1f3de4 <_Z17Variable_GetValueiiiP6RValue+0x104> */
/* @0x1f3dd8 ldrb r12, [r9, #0x69] */
/* @0x1f3ddc cmp r12, #0 */
/* @0x1f3de0 beq 0x1f3f58 <_Z17Variable_GetValueiiiP6RValue+0x278> */
/* @0x1f3de4 add r8, r8, #1 */
/* @0x1f3de8 cmp r8, r11 */
/* @0x1f3dec bne 0x1f3d90 <_Z17Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f3df0 ldr r12, [pc, #0x188] */
/* @0x1f3df4 ldr r9, [r6, r12] */
/* @0x1f3df8 ldr r10, [r9, #0x8] */
/* @0x1f3dfc cmp r10, #0 */
/* @0x1f3e00 ble 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3e04 mov r6, #0 */
/* @0x1f3e08 ldr r12, [r9] */
/* @0x1f3e0c ldr r8, [r12, r6, lsl #2] */
/* @0x1f3e10 ldr r12, [r8, #0x80] */
/* @0x1f3e14 cmp r12, #0 */
/* @0x1f3e18 beq 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */
/* @0x1f3e1c ldr r4, [r12, #0x18] */
/* @0x1f3e20 ldr r12, [r12, #0x48] */
/* @0x1f3e24 subs r11, r0, r4 */
/* @0x1f3e28 rsbs r5, r11, #0 */
/* @0x1f3e2c adcs r5, r5, r11 */
/* @0x1f3e30 cmp r0, r4 */
/* @0x1f3e34 cmpne r12, #0 */
/* @0x1f3e38 bne 0x1f3e1c <_Z17Variable_GetValueiiiP6RValue+0x13c> */
/* @0x1f3e3c cmp r5, #0 */
/* @0x1f3e40 beq 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */
/* @0x1f3e44 ldrb r12, [r8, #0x68] */
/* @0x1f3e48 cmp r12, #0 */
/* @0x1f3e4c bne 0x1f3e5c <_Z17Variable_GetValueiiiP6RValue+0x17c> */
/* @0x1f3e50 ldrb r12, [r8, #0x69] */
/* @0x1f3e54 cmp r12, #0 */
/* @0x1f3e58 beq 0x1f3f64 <_Z17Variable_GetValueiiiP6RValue+0x284> */
/* @0x1f3e5c add r6, r6, #1 */
/* @0x1f3e60 cmp r6, r10 */
/* @0x1f3e64 bne 0x1f3e08 <_Z17Variable_GetValueiiiP6RValue+0x128> */
/* @0x1f3e68 mov r3, #1 */
/* @0x1f3e6c mov r0, #0 */
/* @0x1f3e70 strb r3, [r7] */
/* @0x1f3e74 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3e78 bx lr */
/* @0x1f3e7c ldr r12, [pc, #0x100] */
/* @0x1f3e80 ldr r12, [r6, r12] */
/* @0x1f3e84 ldr r12, [r12] */
/* @0x1f3e88 ldr r4, [r12, #0x4] */
/* @0x1f3e8c ldr r12, [r12] */
/* @0x1f3e90 and r4, r0, r4 */
/* @0x1f3e94 ldr r12, [r12, r4, lsl #3] */
/* @0x1f3e98 cmp r12, #0 */
/* @0x1f3e9c bne 0x1f3eb0 <_Z17Variable_GetValueiiiP6RValue+0x1d0> */
/* @0x1f3ea0 b 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */
/* @0x1f3ea4 ldr r12, [r12, #0x4] */
/* @0x1f3ea8 cmp r12, #0 */
/* @0x1f3eac beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */
/* @0x1f3eb0 ldr r4, [r12, #0x8] */
/* @0x1f3eb4 cmp r0, r4 */
/* @0x1f3eb8 bne 0x1f3ea4 <_Z17Variable_GetValueiiiP6RValue+0x1c4> */
/* @0x1f3ebc ldr r12, [r12, #0xc] */
/* @0x1f3ec0 cmp r12, #0 */
/* @0x1f3ec4 ldrne r12, [r12, #0xd0] */
/* @0x1f3ec8 beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */
/* @0x1f3ecc cmp r12, #0 */
/* @0x1f3ed0 beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */
/* @0x1f3ed4 ldr r4, [r12, #0x8] */
/* @0x1f3ed8 cmp r4, #0 */
/* @0x1f3edc beq 0x1f3d78 <_Z17Variable_GetValueiiiP6RValue+0x98> */
/* @0x1f3ee0 ldr r4, [r12, #0x8] */
/* @0x1f3ee4 ldr r12, [r12] */
/* @0x1f3ee8 ldrb r5, [r4, #0x68] */
/* @0x1f3eec cmp r5, #0 */
/* @0x1f3ef0 bne 0x1f3ecc <_Z17Variable_GetValueiiiP6RValue+0x1ec> */
/* @0x1f3ef4 ldrb r5, [r4, #0x69] */
/* @0x1f3ef8 cmp r5, #0 */
/* @0x1f3efc bne 0x1f3ecc <_Z17Variable_GetValueiiiP6RValue+0x1ec> */
/* @0x1f3f00 mov r0, r4 */
/* @0x1f3f04 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f08 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f3f0c ldr r0, [pc, #0x74] */
/* @0x1f3f10 ldr r0, [r6, r0] */
/* @0x1f3f14 ldr r0, [r0] */
/* @0x1f3f18 ldr r0, [r0, #0x80] */
/* @0x1f3f1c cmp r0, r4 */
/* @0x1f3f20 bne 0x1f3f34 <_Z17Variable_GetValueiiiP6RValue+0x254> */
/* @0x1f3f24 b 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3f28 cmp r12, #0 */
/* @0x1f3f2c mov r0, r12 */
/* @0x1f3f30 beq 0x1f3e68 <_Z17Variable_GetValueiiiP6RValue+0x188> */
/* @0x1f3f34 ldrb r4, [r0, #0x68] */
/* @0x1f3f38 ldr r12, [r0, #0x178] */
/* @0x1f3f3c cmp r4, #0 */
/* @0x1f3f40 bne 0x1f3f28 <_Z17Variable_GetValueiiiP6RValue+0x248> */
/* @0x1f3f44 ldrb r4, [r0, #0x69] */
/* @0x1f3f48 cmp r4, #0 */
/* @0x1f3f4c bne 0x1f3f28 <_Z17Variable_GetValueiiiP6RValue+0x248> */
/* @0x1f3f50 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f54 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f3f58 mov r0, r9 */
/* @0x1f3f5c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f60 b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f3f64 mov r0, r8 */
/* @0x1f3f68 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1f3f6c b 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f3f70 andseq sp, pc, r12, asr pc */
/* @0x1f3f74 .word 0xffffc110 */
/* @0x1f3f78 .word 0xffffbff4 */
/* @0x1f3f7c .word 0xffffbff0 */
/* @0x1f3f80 .word 0xffffbff8 */
/* @0x1f3f84 .word 0xffffbfec */
/* @0x1f3f88 .word 0xffffbcd8 */

/* ── FUNC 0x1f3f8c · Variable_GetObjectName(int, int) · size=320 · insn=80 */
/* @0x1f3f8c cmn r0, #3 */
/* @0x1f3f90 mov r2, r0 */
/* @0x1f3f94 beq 0x1f4010 <_Z22Variable_GetObjectNameii+0x84> */
/* @0x1f3f98 cmp r0, #0 */
/* @0x1f3f9c blt 0x1f4084 <_Z22Variable_GetObjectNameii+0xf8> */
/* @0x1f3fa0 movw r3, #0x869f */
/* @0x1f3fa4 movt r3, #0x1 */
/* @0x1f3fa8 cmp r0, r3 */
/* @0x1f3fac ble 0x1f4058 <_Z22Variable_GetObjectNameii+0xcc> */
/* @0x1f3fb0 ldr r3, [pc, #0xf0] */
/* @0x1f3fb4 ldr r3, [pc, r3] */
/* @0x1f3fb8 ldr r1, [r3, #0x4] */
/* @0x1f3fbc ldr r3, [r3] */
/* @0x1f3fc0 and r1, r0, r1 */
/* @0x1f3fc4 ldr r3, [r3, r1, lsl #3] */
/* @0x1f3fc8 cmp r3, #0 */
/* @0x1f3fcc bne 0x1f3fe0 <_Z22Variable_GetObjectNameii+0x54> */
/* @0x1f3fd0 b 0x1f4090 <_Z22Variable_GetObjectNameii+0x104> */
/* @0x1f3fd4 ldr r3, [r3, #0x4] */
/* @0x1f3fd8 cmp r3, #0 */
/* @0x1f3fdc beq 0x1f405c <_Z22Variable_GetObjectNameii+0xd0> */
/* @0x1f3fe0 ldr r1, [r3, #0x8] */
/* @0x1f3fe4 cmp r2, r1 */
/* @0x1f3fe8 bne 0x1f3fd4 <_Z22Variable_GetObjectNameii+0x48> */
/* @0x1f3fec ldr r3, [r3, #0xc] */
/* @0x1f3ff0 cmp r3, #0 */
/* @0x1f3ff4 beq 0x1f409c <_Z22Variable_GetObjectNameii+0x110> */
/* @0x1f3ff8 ldrb r2, [r3, #0x68] */
/* @0x1f3ffc cmp r2, #0 */
/* @0x1f4000 beq 0x1f4054 <_Z22Variable_GetObjectNameii+0xc8> */
/* @0x1f4004 ldr r0, [pc, #0xa0] */
/* @0x1f4008 add r0, pc, r0 */
/* @0x1f400c bx lr */
/* @0x1f4010 ldr r3, [pc, #0x98] */
/* @0x1f4014 ldr r3, [pc, r3] */
/* @0x1f4018 ldr r3, [r3] */
/* @0x1f401c ldr r3, [r3, #0x80] */
/* @0x1f4020 cmp r3, #0 */
/* @0x1f4024 bne 0x1f4038 <_Z22Variable_GetObjectNameii+0xac> */
/* @0x1f4028 b 0x1f4068 <_Z22Variable_GetObjectNameii+0xdc> */
/* @0x1f402c cmp r2, #0 */
/* @0x1f4030 mov r3, r2 */
/* @0x1f4034 beq 0x1f4068 <_Z22Variable_GetObjectNameii+0xdc> */
/* @0x1f4038 ldrb r1, [r3, #0x68] */
/* @0x1f403c ldr r2, [r3, #0x178] */
/* @0x1f4040 cmp r1, #0 */
/* @0x1f4044 bne 0x1f402c <_Z22Variable_GetObjectNameii+0xa0> */
/* @0x1f4048 ldrb r1, [r3, #0x69] */
/* @0x1f404c cmp r1, #0 */
/* @0x1f4050 bne 0x1f402c <_Z22Variable_GetObjectNameii+0xa0> */
/* @0x1f4054 ldr r0, [r3, #0x7c] */
/* @0x1f4058 b 0x19ed54 <_Z11Object_Namei> */
/* @0x1f405c ldr r0, [pc, #0x50] */
/* @0x1f4060 add r0, pc, r0 */
/* @0x1f4064 bx lr */
/* @0x1f4068 ldr r3, [pc, #0x48] */
/* @0x1f406c mov r2, #1 */
/* @0x1f4070 ldr r0, [pc, #0x44] */
/* @0x1f4074 ldr r3, [pc, r3] */
/* @0x1f4078 add r0, pc, r0 */
/* @0x1f407c strb r2, [r3] */
/* @0x1f4080 bx lr */
/* @0x1f4084 ldr r0, [pc, #0x34] */
/* @0x1f4088 add r0, pc, r0 */
/* @0x1f408c bx lr */
/* @0x1f4090 ldr r0, [pc, #0x2c] */
/* @0x1f4094 add r0, pc, r0 */
/* @0x1f4098 bx lr */
/* @0x1f409c ldr r0, [pc, #0x24] */
/* @0x1f40a0 add r0, pc, r0 */
/* @0x1f40a4 bx lr */
/* @0x1f40a8 mulseq pc, r0, r12 */
/* @0x1f40ac ldrsbeq lr, [r5], -r4 */
/* @0x1f40b0 andseq r9, pc, r4, lsl r9 */
/* @0x1f40b4 andseq lr, r5, r12, ror r7 */
/* @0x1f40b8 andseq r9, pc, r12, ror #25 */
/* @0x1f40bc andseq lr, r5, r4, ror #14 */
/* @0x1f40c0 andseq lr, r5, r4, asr r7 */
/* @0x1f40c4 andseq lr, r5, r8, asr #14 */
/* @0x1f40c8 andseq lr, r5, r12, lsr r7 */

/* ── FUNC 0x1f40cc · YYGML_Variable_GetValue(int, int, int, RValue*) · size=636 · insn=159 */
/* @0x1f40cc push {r4, r5, r6, r7, r8, lr} */
/* @0x1f40d0 cmn r0, #3 */
/* @0x1f40d4 ldr r6, [pc, #0x254] */
/* @0x1f40d8 sub sp, sp, #8 */
/* @0x1f40dc add r6, pc, r6 */
/* @0x1f40e0 beq 0x1f4230 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x164> */
/* @0x1f40e4 cmp r0, #0 */
/* @0x1f40e8 blt 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f40ec movw r12, #0x869f */
/* @0x1f40f0 movt r12, #0x1 */
/* @0x1f40f4 cmp r0, r12 */
/* @0x1f40f8 ble 0x1f4188 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xbc> */
/* @0x1f40fc ldr r12, [pc, #0x230] */
/* @0x1f4100 ldr r12, [r6, r12] */
/* @0x1f4104 ldr r4, [r12, #0x4] */
/* @0x1f4108 ldr r12, [r12] */
/* @0x1f410c and r4, r0, r4 */
/* @0x1f4110 ldr r12, [r12, r4, lsl #3] */
/* @0x1f4114 cmp r12, #0 */
/* @0x1f4118 bne 0x1f412c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x60> */
/* @0x1f411c b 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f4120 ldr r12, [r12, #0x4] */
/* @0x1f4124 cmp r12, #0 */
/* @0x1f4128 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f412c ldr r4, [r12, #0x8] */
/* @0x1f4130 cmp r0, r4 */
/* @0x1f4134 bne 0x1f4120 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x54> */
/* @0x1f4138 ldr r0, [r12, #0xc] */
/* @0x1f413c cmp r0, #0 */
/* @0x1f4140 beq 0x1f4180 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb4> */
/* @0x1f4144 ldrb r12, [r0, #0x68] */
/* @0x1f4148 cmp r12, #0 */
/* @0x1f414c bne 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f4150 ldr r12, [r0, #0x4] */
/* @0x1f4154 cmp r12, #0 */
/* @0x1f4158 addne r1, r12, r1, lsl #4 */
/* @0x1f415c bne 0x1f421c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x150> */
/* @0x1f4160 str r2, [sp, #0x4] */
/* @0x1f4164 str r3, [sp] */
/* @0x1f4168 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f416c ldr r3, [sp] */
/* @0x1f4170 ldr r2, [sp, #0x4] */
/* @0x1f4174 mov r1, r0 */
/* @0x1f4178 b 0x1f421c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x150> */
/* @0x1f417c mov r0, #0 */
/* @0x1f4180 add sp, sp, #8 */
/* @0x1f4184 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f4188 ldr r12, [pc, #0x1a8] */
/* @0x1f418c ldr r12, [r6, r12] */
/* @0x1f4190 ldr r12, [r12] */
/* @0x1f4194 ldr r4, [r12, #0x4] */
/* @0x1f4198 ldr r12, [r12] */
/* @0x1f419c and r4, r0, r4 */
/* @0x1f41a0 ldr r12, [r12, r4, lsl #3] */
/* @0x1f41a4 cmp r12, #0 */
/* @0x1f41a8 bne 0x1f41bc <_Z23YYGML_Variable_GetValueiiiP6RValue+0xf0> */
/* @0x1f41ac b 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac> */
/* @0x1f41b0 ldr r12, [r12, #0x4] */
/* @0x1f41b4 cmp r12, #0 */
/* @0x1f41b8 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac> */
/* @0x1f41bc ldr r4, [r12, #0x8] */
/* @0x1f41c0 cmp r0, r4 */
/* @0x1f41c4 bne 0x1f41b0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0xe4> */
/* @0x1f41c8 ldr r12, [r12, #0xc] */
/* @0x1f41cc cmp r12, #0 */
/* @0x1f41d0 ldrne r12, [r12, #0xd0] */
/* @0x1f41d4 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac> */
/* @0x1f41d8 cmp r12, #0 */
/* @0x1f41dc beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac> */
/* @0x1f41e0 ldr r4, [r12, #0x8] */
/* @0x1f41e4 cmp r4, #0 */
/* @0x1f41e8 beq 0x1f4278 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1ac> */
/* @0x1f41ec ldr r4, [r12, #0x8] */
/* @0x1f41f0 ldr r12, [r12] */
/* @0x1f41f4 ldrb r5, [r4, #0x68] */
/* @0x1f41f8 cmp r5, #0 */
/* @0x1f41fc bne 0x1f41d8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x10c> */
/* @0x1f4200 ldrb r5, [r4, #0x69] */
/* @0x1f4204 cmp r5, #0 */
/* @0x1f4208 bne 0x1f41d8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x10c> */
/* @0x1f420c ldr r0, [r4, #0x4] */
/* @0x1f4210 cmp r0, #0 */
/* @0x1f4214 addne r1, r0, r1, lsl #4 */
/* @0x1f4218 beq 0x1f4328 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x25c> */
/* @0x1f421c mov r0, r3 */
/* @0x1f4220 bl 0xd13bc <_Z10GET_RValueP6RValueS0_i> */
/* @0x1f4224 mov r0, #1 */
/* @0x1f4228 add sp, sp, #8 */
/* @0x1f422c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1f4230 ldr r0, [pc, #0x104] */
/* @0x1f4234 ldr r0, [r6, r0] */
/* @0x1f4238 ldr r0, [r0] */
/* @0x1f423c ldr r4, [r0, #0x80] */
/* @0x1f4240 cmp r4, #0 */
/* @0x1f4244 bne 0x1f4258 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x18c> */
/* @0x1f4248 b 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f424c cmp r12, #0 */
/* @0x1f4250 mov r4, r12 */
/* @0x1f4254 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f4258 ldrb r0, [r4, #0x68] */
/* @0x1f425c ldr r12, [r4, #0x178] */
/* @0x1f4260 cmp r0, #0 */
/* @0x1f4264 bne 0x1f424c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x180> */
/* @0x1f4268 ldrb r0, [r4, #0x69] */
/* @0x1f426c cmp r0, #0 */
/* @0x1f4270 bne 0x1f424c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x180> */
/* @0x1f4274 b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140> */
/* @0x1f4278 ldr r12, [pc, #0xc0] */
/* @0x1f427c ldr r12, [r6, r12] */
/* @0x1f4280 ldr r7, [r12, #0x8] */
/* @0x1f4284 cmp r7, #0 */
/* @0x1f4288 ble 0x1f42d0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x204> */
/* @0x1f428c ldr r8, [r12] */
/* @0x1f4290 mov r12, #0 */
/* @0x1f4294 b 0x1f42a0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1d4> */
/* @0x1f4298 cmp r12, r7 */
/* @0x1f429c beq 0x1f42d0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x204> */
/* @0x1f42a0 ldr r4, [r8, r12, lsl #2] */
/* @0x1f42a4 add r12, r12, #1 */
/* @0x1f42a8 ldr r5, [r4, #0x7c] */
/* @0x1f42ac cmp r0, r5 */
/* @0x1f42b0 bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc> */
/* @0x1f42b4 ldrb r5, [r4, #0x68] */
/* @0x1f42b8 cmp r5, #0 */
/* @0x1f42bc bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc> */
/* @0x1f42c0 ldrb r5, [r4, #0x69] */
/* @0x1f42c4 cmp r5, #0 */
/* @0x1f42c8 bne 0x1f4298 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x1cc> */
/* @0x1f42cc b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140> */
/* @0x1f42d0 ldr r12, [pc, #0x6c] */
/* @0x1f42d4 ldr r12, [r6, r12] */
/* @0x1f42d8 ldr r6, [r12, #0x8] */
/* @0x1f42dc cmp r6, #0 */
/* @0x1f42e0 ble 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f42e4 ldr r7, [r12] */
/* @0x1f42e8 mov r12, #0 */
/* @0x1f42ec b 0x1f42f8 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x22c> */
/* @0x1f42f0 cmp r12, r6 */
/* @0x1f42f4 beq 0x1f417c <_Z23YYGML_Variable_GetValueiiiP6RValue+0xb0> */
/* @0x1f42f8 ldr r4, [r7, r12, lsl #2] */
/* @0x1f42fc add r12, r12, #1 */
/* @0x1f4300 ldr r5, [r4, #0x7c] */
/* @0x1f4304 cmp r0, r5 */
/* @0x1f4308 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224> */
/* @0x1f430c ldrb r5, [r4, #0x68] */
/* @0x1f4310 cmp r5, #0 */
/* @0x1f4314 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224> */
/* @0x1f4318 ldrb r5, [r4, #0x69] */
/* @0x1f431c cmp r5, #0 */
/* @0x1f4320 bne 0x1f42f0 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x224> */
/* @0x1f4324 b 0x1f420c <_Z23YYGML_Variable_GetValueiiiP6RValue+0x140> */
/* @0x1f4328 mov r0, r4 */
/* @0x1f432c b 0x1f4160 <_Z23YYGML_Variable_GetValueiiiP6RValue+0x94> */
/* @0x1f4330 andseq sp, pc, r4, ror r11 */
/* @0x1f4334 .word 0xffffbff4 */
/* @0x1f4338 .word 0xffffbfec */
/* @0x1f433c .word 0xffffbcd8 */
/* @0x1f4340 .word 0xffffbff0 */
/* @0x1f4344 .word 0xffffbff8 */

/* ── FUNC 0x1f4348 · Variable_SetValue(int, int, int, RValue*) · size=1060 · insn=265 */
/* @0x1f4348 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f434c cmn r0, #3 */
/* @0x1f4350 ldr r9, [pc, #0x3ec] */
/* @0x1f4354 sub sp, sp, #12 */
/* @0x1f4358 mov r4, r0 */
/* @0x1f435c mov r8, r1 */
/* @0x1f4360 mov r7, r2 */
/* @0x1f4364 mov r6, r3 */
/* @0x1f4368 add r9, pc, r9 */
/* @0x1f436c beq 0x1f4600 <_Z17Variable_SetValueiiiP6RValue+0x2b8> */
/* @0x1f4370 cmp r0, #0 */
/* @0x1f4374 blt 0x1f4684 <_Z17Variable_SetValueiiiP6RValue+0x33c> */
/* @0x1f4378 movw r3, #0x869f */
/* @0x1f437c movt r3, #0x1 */
/* @0x1f4380 cmp r0, r3 */
/* @0x1f4384 bgt 0x1f46a0 <_Z17Variable_SetValueiiiP6RValue+0x358> */
/* @0x1f4388 ldr r3, [pc, #0x3b8] */
/* @0x1f438c ldr r3, [r9, r3] */
/* @0x1f4390 ldr r3, [r3] */
/* @0x1f4394 ldr r2, [r3, #0x4] */
/* @0x1f4398 ldr r3, [r3] */
/* @0x1f439c and r2, r0, r2 */
/* @0x1f43a0 ldr r3, [r3, r2, lsl #3] */
/* @0x1f43a4 cmp r3, #0 */
/* @0x1f43a8 bne 0x1f43bc <_Z17Variable_SetValueiiiP6RValue+0x74> */
/* @0x1f43ac b 0x1f4690 <_Z17Variable_SetValueiiiP6RValue+0x348> */
/* @0x1f43b0 ldr r3, [r3, #0x4] */
/* @0x1f43b4 cmp r3, #0 */
/* @0x1f43b8 beq 0x1f4690 <_Z17Variable_SetValueiiiP6RValue+0x348> */
/* @0x1f43bc ldr r2, [r3, #0x8] */
/* @0x1f43c0 cmp r4, r2 */
/* @0x1f43c4 bne 0x1f43b0 <_Z17Variable_SetValueiiiP6RValue+0x68> */
/* @0x1f43c8 ldr r3, [r3, #0xc] */
/* @0x1f43cc cmp r3, #0 */
/* @0x1f43d0 str r3, [sp] */
/* @0x1f43d4 beq 0x1f4694 <_Z17Variable_SetValueiiiP6RValue+0x34c> */
/* @0x1f43d8 ldr r3, [sp] */
/* @0x1f43dc ldr r5, [r3, #0xd0] */
/* @0x1f43e0 cmp r5, #0 */
/* @0x1f43e4 beq 0x1f4738 <_Z17Variable_SetValueiiiP6RValue+0x3f0> */
/* @0x1f43e8 ldr r12, [r5, #0x8] */
/* @0x1f43ec cmp r12, #0 */
/* @0x1f43f0 moveq r10, r12 */
/* @0x1f43f4 beq 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f43f8 mov r12, #0 */
/* @0x1f43fc mov r10, r12 */
/* @0x1f4400 b 0x1f4410 <_Z17Variable_SetValueiiiP6RValue+0xc8> */
/* @0x1f4404 ldr r3, [r5, #0x8] */
/* @0x1f4408 cmp r3, #0 */
/* @0x1f440c beq 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f4410 ldr r0, [r5, #0x8] */
/* @0x1f4414 ldr r5, [r5] */
/* @0x1f4418 ldrb r3, [r0, #0x68] */
/* @0x1f441c cmp r3, #0 */
/* @0x1f4420 bne 0x1f4448 <_Z17Variable_SetValueiiiP6RValue+0x100> */
/* @0x1f4424 ldrb r11, [r0, #0x69] */
/* @0x1f4428 mov r1, r8 */
/* @0x1f442c mov r2, r7 */
/* @0x1f4430 mov r3, r6 */
/* @0x1f4434 cmp r11, #0 */
/* @0x1f4438 bne 0x1f4448 <_Z17Variable_SetValueiiiP6RValue+0x100> */
/* @0x1f443c bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f4440 mov r12, #1 */
/* @0x1f4444 mov r10, r0 */
/* @0x1f4448 cmp r5, #0 */
/* @0x1f444c bne 0x1f4404 <_Z17Variable_SetValueiiiP6RValue+0xbc> */
/* @0x1f4450 ldr r3, [pc, #0x2f4] */
/* @0x1f4454 ldr r11, [r9, r3] */
/* @0x1f4458 ldr r3, [r11, #0x8] */
/* @0x1f445c cmp r3, #0 */
/* @0x1f4460 ble 0x1f4514 <_Z17Variable_SetValueiiiP6RValue+0x1cc> */
/* @0x1f4464 mov r5, #0 */
/* @0x1f4468 mov r0, r10 */
/* @0x1f446c str r9, [sp, #0x4] */
/* @0x1f4470 mov r10, r6 */
/* @0x1f4474 mov r9, r7 */
/* @0x1f4478 mov r1, r12 */
/* @0x1f447c mov r6, r5 */
/* @0x1f4480 mov r7, r11 */
/* @0x1f4484 ldr r3, [r7] */
/* @0x1f4488 ldr r2, [r3, r6, lsl #2] */
/* @0x1f448c ldr r5, [r2, #0x80] */
/* @0x1f4490 cmp r5, #0 */
/* @0x1f4494 beq 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f4498 ldr r12, [r5, #0x18] */
/* @0x1f449c ldr r5, [r5, #0x48] */
/* @0x1f44a0 subs r11, r4, r12 */
/* @0x1f44a4 rsbs r3, r11, #0 */
/* @0x1f44a8 adcs r3, r3, r11 */
/* @0x1f44ac cmp r4, r12 */
/* @0x1f44b0 cmpne r5, #0 */
/* @0x1f44b4 bne 0x1f4498 <_Z17Variable_SetValueiiiP6RValue+0x150> */
/* @0x1f44b8 cmp r3, #0 */
/* @0x1f44bc beq 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44c0 ldrb r3, [r2, #0x68] */
/* @0x1f44c4 cmp r3, #0 */
/* @0x1f44c8 bne 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44cc ldrb r3, [r2, #0x69] */
/* @0x1f44d0 cmp r3, #0 */
/* @0x1f44d4 bne 0x1f44f0 <_Z17Variable_SetValueiiiP6RValue+0x1a8> */
/* @0x1f44d8 mov r0, r2 */
/* @0x1f44dc mov r1, r8 */
/* @0x1f44e0 mov r2, r9 */
/* @0x1f44e4 mov r3, r10 */
/* @0x1f44e8 bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f44ec mov r1, #1 */
/* @0x1f44f0 ldr r3, [r7, #0x8] */
/* @0x1f44f4 add r6, r6, #1 */
/* @0x1f44f8 cmp r3, r6 */
/* @0x1f44fc bgt 0x1f4484 <_Z17Variable_SetValueiiiP6RValue+0x13c> */
/* @0x1f4500 mov r7, r9 */
/* @0x1f4504 ldr r9, [sp, #0x4] */
/* @0x1f4508 mov r6, r10 */
/* @0x1f450c mov r12, r1 */
/* @0x1f4510 mov r10, r0 */
/* @0x1f4514 ldr r3, [pc, #0x234] */
/* @0x1f4518 ldr r9, [r9, r3] */
/* @0x1f451c ldr r3, [r9, #0x8] */
/* @0x1f4520 cmp r3, #0 */
/* @0x1f4524 ble 0x1f45cc <_Z17Variable_SetValueiiiP6RValue+0x284> */
/* @0x1f4528 mov r5, #0 */
/* @0x1f452c mov r0, r10 */
/* @0x1f4530 str r8, [sp, #0x4] */
/* @0x1f4534 mov r2, r12 */
/* @0x1f4538 mov r8, r9 */
/* @0x1f453c mov r10, r6 */
/* @0x1f4540 mov r9, r7 */
/* @0x1f4544 mov r7, r5 */
/* @0x1f4548 ldr r3, [r8] */
/* @0x1f454c ldr r3, [r3, r7, lsl #2] */
/* @0x1f4550 ldr r11, [r3, #0x80] */
/* @0x1f4554 cmp r11, #0 */
/* @0x1f4558 beq 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f455c ldr r5, [r11, #0x18] */
/* @0x1f4560 ldr r11, [r11, #0x48] */
/* @0x1f4564 subs r1, r4, r5 */
/* @0x1f4568 rsbs r6, r1, #0 */
/* @0x1f456c adcs r6, r6, r1 */
/* @0x1f4570 cmp r4, r5 */
/* @0x1f4574 cmpne r11, #0 */
/* @0x1f4578 bne 0x1f455c <_Z17Variable_SetValueiiiP6RValue+0x214> */
/* @0x1f457c cmp r6, #0 */
/* @0x1f4580 beq 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f4584 ldrb r1, [r3, #0x68] */
/* @0x1f4588 cmp r1, #0 */
/* @0x1f458c bne 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f4590 ldrb r1, [r3, #0x69] */
/* @0x1f4594 cmp r1, #0 */
/* @0x1f4598 bne 0x1f45b4 <_Z17Variable_SetValueiiiP6RValue+0x26c> */
/* @0x1f459c mov r0, r3 */
/* @0x1f45a0 mov r2, r9 */
/* @0x1f45a4 ldr r1, [sp, #0x4] */
/* @0x1f45a8 mov r3, r10 */
/* @0x1f45ac bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f45b0 mov r2, #1 */
/* @0x1f45b4 ldr r3, [r8, #0x8] */
/* @0x1f45b8 add r7, r7, #1 */
/* @0x1f45bc cmp r3, r7 */
/* @0x1f45c0 bgt 0x1f4548 <_Z17Variable_SetValueiiiP6RValue+0x200> */
/* @0x1f45c4 mov r10, r0 */
/* @0x1f45c8 mov r12, r2 */
/* @0x1f45cc cmp r12, #0 */
/* @0x1f45d0 bne 0x1f4668 <_Z17Variable_SetValueiiiP6RValue+0x320> */
/* @0x1f45d4 ldr r3, [sp] */
/* @0x1f45d8 cmp r3, #0 */
/* @0x1f45dc beq 0x1f472c <_Z17Variable_SetValueiiiP6RValue+0x3e4> */
/* @0x1f45e0 ldr r2, [r3, #0x14] */
/* @0x1f45e4 ldr r0, [pc, #0x168] */
/* @0x1f45e8 mov r1, r4 */
/* @0x1f45ec add r0, pc, r0 */
/* @0x1f45f0 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1f45f4 mov r0, r10 */
/* @0x1f45f8 add sp, sp, #12 */
/* @0x1f45fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4600 ldr r3, [pc, #0x150] */
/* @0x1f4604 ldr r3, [r9, r3] */
/* @0x1f4608 ldr r3, [r3] */
/* @0x1f460c ldr r0, [r3, #0x80] */
/* @0x1f4610 cmp r0, #0 */
/* @0x1f4614 beq 0x1f470c <_Z17Variable_SetValueiiiP6RValue+0x3c4> */
/* @0x1f4618 mov r5, #0 */
/* @0x1f461c mov r10, r5 */
/* @0x1f4620 ldrb r12, [r0, #0x68] */
/* @0x1f4624 ldr r4, [r0, #0x178] */
/* @0x1f4628 cmp r12, #0 */
/* @0x1f462c bne 0x1f4654 <_Z17Variable_SetValueiiiP6RValue+0x30c> */
/* @0x1f4630 ldrb r12, [r0, #0x69] */
/* @0x1f4634 mov r1, r8 */
/* @0x1f4638 mov r2, r7 */
/* @0x1f463c mov r3, r6 */
/* @0x1f4640 cmp r12, #0 */
/* @0x1f4644 bne 0x1f4654 <_Z17Variable_SetValueiiiP6RValue+0x30c> */
/* @0x1f4648 bl 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f464c mov r5, #1 */
/* @0x1f4650 mov r10, r0 */
/* @0x1f4654 cmp r4, #0 */
/* @0x1f4658 mov r0, r4 */
/* @0x1f465c bne 0x1f4620 <_Z17Variable_SetValueiiiP6RValue+0x2d8> */
/* @0x1f4660 cmp r5, #0 */
/* @0x1f4664 beq 0x1f4710 <_Z17Variable_SetValueiiiP6RValue+0x3c8> */
/* @0x1f4668 mov r0, r10 */
/* @0x1f466c add sp, sp, #12 */
/* @0x1f4670 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4674 ldr r0, [pc, #0xe0] */
/* @0x1f4678 mov r1, r4 */
/* @0x1f467c add r0, pc, r0 */
/* @0x1f4680 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1f4684 mov r0, #0 */
/* @0x1f4688 add sp, sp, #12 */
/* @0x1f468c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f4690 str r3, [sp] */
/* @0x1f4694 mov r12, r3 */
/* @0x1f4698 mov r10, r3 */
/* @0x1f469c b 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f46a0 ldr r3, [pc, #0xb8] */
/* @0x1f46a4 ldr r3, [r9, r3] */
/* @0x1f46a8 ldr r2, [r3, #0x4] */
/* @0x1f46ac ldr r3, [r3] */
/* @0x1f46b0 and r2, r0, r2 */
/* @0x1f46b4 ldr r3, [r3, r2, lsl #3] */
/* @0x1f46b8 cmp r3, #0 */
/* @0x1f46bc bne 0x1f46d0 <_Z17Variable_SetValueiiiP6RValue+0x388> */
/* @0x1f46c0 b 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> */
/* @0x1f46c4 ldr r3, [r3, #0x4] */
/* @0x1f46c8 cmp r3, #0 */
/* @0x1f46cc beq 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> */
/* @0x1f46d0 ldr r2, [r3, #0x8] */
/* @0x1f46d4 cmp r4, r2 */
/* @0x1f46d8 bne 0x1f46c4 <_Z17Variable_SetValueiiiP6RValue+0x37c> */
/* @0x1f46dc ldr r0, [r3, #0xc] */
/* @0x1f46e0 cmp r0, #0 */
/* @0x1f46e4 beq 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> */
/* @0x1f46e8 ldrb r3, [r0, #0x68] */
/* @0x1f46ec cmp r3, #0 */
/* @0x1f46f0 bne 0x1f4674 <_Z17Variable_SetValueiiiP6RValue+0x32c> */
/* @0x1f46f4 mov r1, r8 */
/* @0x1f46f8 mov r2, r7 */
/* @0x1f46fc mov r3, r6 */
/* @0x1f4700 add sp, sp, #12 */
/* @0x1f4704 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1f4708 b 0x1f3c28 <_Z24Variable_SetValue_DirectP12YYObjectBaseiiP6RValue> */
/* @0x1f470c mov r10, r0 */
/* @0x1f4710 ldr r0, [pc, #0x4c] */
/* @0x1f4714 mvn r1, #2 */
/* @0x1f4718 add r0, pc, r0 */
/* @0x1f471c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1f4720 mov r0, r10 */
/* @0x1f4724 add sp, sp, #12 */
/* @0x1f4728 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1f472c ldr r2, [pc, #0x34] */
/* @0x1f4730 add r2, pc, r2 */
/* @0x1f4734 b 0x1f45e4 <_Z17Variable_SetValueiiiP6RValue+0x29c> */
/* @0x1f4738 mov r12, r5 */
/* @0x1f473c mov r10, r5 */
/* @0x1f4740 b 0x1f4450 <_Z17Variable_SetValueiiiP6RValue+0x108> */
/* @0x1f4744 andseq sp, pc, r8, ror #17 */
/* @0x1f4748 .word 0xffffbfec */
/* @0x1f474c .word 0xffffbff0 */
/* @0x1f4750 .word 0xffffbff8 */
/* @0x1f4754 andseq r0, r4, r4, lsr r3 */
/* @0x1f4758 .word 0xffffbcd8 */
/* @0x1f475c andseq lr, r5, r12, ror r1 */
/* @0x1f4760 .word 0xffffbff4 */
/* @0x1f4764 andseq lr, r5, r0, ror #1 */
/* @0x1f4768 andseq lr, r5, r0, asr #1 */

/* ── FUNC 0x1f476c · YYGML_Variable_SetValue(int, int, int, RValue*) · size=700 · insn=175 */
/* @0x1f476c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1f4770 cmn r0, #3 */
/* @0x1f4774 ldr r9, [pc, #0x298] */
/* @0x1f4778 mov r5, r0 */
/* @0x1f477c mov r8, r1 */
/* @0x1f4780 mov r6, r2 */
/* @0x1f4784 mov r7, r3 */
/* @0x1f4788 add r9, pc, r9 */
/* @0x1f478c beq 0x1f4900 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x194> */
/* @0x1f4790 cmp r0, #0 */
/* @0x1f4794 blt 0x1f49e0 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x274> */
/* @0x1f4798 movw r3, #0x869f */
/* @0x1f479c movt r3, #0x1 */
/* @0x1f47a0 cmp r0, r3 */
/* @0x1f47a4 bgt 0x1f4968 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1fc> */
/* @0x1f47a8 ldr r3, [pc, #0x268] */
/* @0x1f47ac ldr r3, [r9, r3] */
/* @0x1f47b0 ldr r3, [r3] */
/* @0x1f47b4 ldr r2, [r3, #0x4] */
/* @0x1f47b8 ldr r3, [r3] */
/* @0x1f47bc and r2, r0, r2 */
/* @0x1f47c0 ldr r12, [r3, r2, lsl #3] */
/* @0x1f47c4 cmp r12, #0 */
/* @0x1f47c8 bne 0x1f47dc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x70> */
/* @0x1f47cc b 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f47d0 ldr r12, [r12, #0x4] */
/* @0x1f47d4 cmp r12, #0 */
/* @0x1f47d8 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f47dc ldr r3, [r12, #0x8] */
/* @0x1f47e0 cmp r5, r3 */
/* @0x1f47e4 bne 0x1f47d0 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x64> */
/* @0x1f47e8 ldr r3, [r12, #0xc] */
/* @0x1f47ec cmp r3, #0 */
/* @0x1f47f0 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f47f4 ldr r4, [r3, #0xd0] */
/* @0x1f47f8 cmp r4, #0 */
/* @0x1f47fc beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f4800 ldr r3, [r4, #0x8] */
/* @0x1f4804 cmp r3, #0 */
/* @0x1f4808 beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f480c lsl r10, r8, #4 */
/* @0x1f4810 b 0x1f4820 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xb4> */
/* @0x1f4814 ldr r3, [r4, #0x8] */
/* @0x1f4818 cmp r3, #0 */
/* @0x1f481c beq 0x1f4864 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf8> */
/* @0x1f4820 ldr r3, [r4, #0x8] */
/* @0x1f4824 ldr r4, [r4] */
/* @0x1f4828 ldrb r2, [r3, #0x68] */
/* @0x1f482c cmp r2, #0 */
/* @0x1f4830 bne 0x1f485c <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf0> */
/* @0x1f4834 ldrb r2, [r3, #0x69] */
/* @0x1f4838 cmp r2, #0 */
/* @0x1f483c bne 0x1f485c <_Z23YYGML_Variable_SetValueiiiP6RValue+0xf0> */
/* @0x1f4840 ldr r0, [r3, #0x4] */
/* @0x1f4844 cmp r0, #0 */
/* @0x1f4848 add r0, r0, r10 */
/* @0x1f484c beq 0x1f49e8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x27c> */
/* @0x1f4850 mov r1, r7 */
/* @0x1f4854 mov r2, r6 */
/* @0x1f4858 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f485c cmp r4, #0 */
/* @0x1f4860 bne 0x1f4814 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xa8> */
/* @0x1f4864 ldr r3, [pc, #0x1b0] */
/* @0x1f4868 ldr r9, [r9, r3] */
/* @0x1f486c ldr r3, [r9, #0x8] */
/* @0x1f4870 cmp r3, #0 */
/* @0x1f4874 lslgt r10, r8, #4 */
/* @0x1f4878 movgt r4, #0 */
/* @0x1f487c bgt 0x1f4894 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x128> */
/* @0x1f4880 b 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f4884 ldr r3, [r9, #0x8] */
/* @0x1f4888 add r4, r4, #1 */
/* @0x1f488c cmp r3, r4 */
/* @0x1f4890 ble 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f4894 ldr r3, [r9] */
/* @0x1f4898 ldr r12, [r3, r4, lsl #2] */
/* @0x1f489c ldr r3, [r12, #0x7c] */
/* @0x1f48a0 cmp r5, r3 */
/* @0x1f48a4 bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118> */
/* @0x1f48a8 ldrb r3, [r12, #0x68] */
/* @0x1f48ac cmp r3, #0 */
/* @0x1f48b0 bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118> */
/* @0x1f48b4 ldrb r3, [r12, #0x69] */
/* @0x1f48b8 cmp r3, #0 */
/* @0x1f48bc bne 0x1f4884 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x118> */
/* @0x1f48c0 ldr r0, [r12, #0x4] */
/* @0x1f48c4 cmp r0, #0 */
/* @0x1f48c8 add r0, r0, r10 */
/* @0x1f48cc bne 0x1f48dc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x170> */
/* @0x1f48d0 mov r0, r12 */
/* @0x1f48d4 mov r1, r8 */
/* @0x1f48d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f48dc mov r1, r7 */
/* @0x1f48e0 mov r2, r6 */
/* @0x1f48e4 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f48e8 ldr r3, [r9, #0x8] */
/* @0x1f48ec add r4, r4, #1 */
/* @0x1f48f0 cmp r3, r4 */
/* @0x1f48f4 bgt 0x1f4894 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x128> */
/* @0x1f48f8 mov r0, #1 */
/* @0x1f48fc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f4900 ldr r3, [pc, #0x118] */
/* @0x1f4904 ldr r3, [r9, r3] */
/* @0x1f4908 ldr r3, [r3] */
/* @0x1f490c ldr r3, [r3, #0x80] */
/* @0x1f4910 cmp r3, #0 */
/* @0x1f4914 lslne r5, r1, #4 */
/* @0x1f4918 beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f491c ldrb r2, [r3, #0x68] */
/* @0x1f4920 ldr r4, [r3, #0x178] */
/* @0x1f4924 cmp r2, #0 */
/* @0x1f4928 bne 0x1f4954 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1e8> */
/* @0x1f492c ldrb r2, [r3, #0x69] */
/* @0x1f4930 cmp r2, #0 */
/* @0x1f4934 bne 0x1f4954 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1e8> */
/* @0x1f4938 ldr r0, [r3, #0x4] */
/* @0x1f493c cmp r0, #0 */
/* @0x1f4940 add r0, r0, r5 */
/* @0x1f4944 beq 0x1f49f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x28c> */
/* @0x1f4948 mov r1, r7 */
/* @0x1f494c mov r2, r6 */
/* @0x1f4950 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f4954 cmp r4, #0 */
/* @0x1f4958 mov r3, r4 */
/* @0x1f495c bne 0x1f491c <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1b0> */
/* @0x1f4960 mov r0, #1 */
/* @0x1f4964 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f4968 ldr r3, [pc, #0xb4] */
/* @0x1f496c ldr r3, [r9, r3] */
/* @0x1f4970 ldr r2, [r3, #0x4] */
/* @0x1f4974 ldr r3, [r3] */
/* @0x1f4978 and r2, r0, r2 */
/* @0x1f497c ldr r3, [r3, r2, lsl #3] */
/* @0x1f4980 cmp r3, #0 */
/* @0x1f4984 bne 0x1f4998 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x22c> */
/* @0x1f4988 b 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f498c ldr r3, [r3, #0x4] */
/* @0x1f4990 cmp r3, #0 */
/* @0x1f4994 beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f4998 ldr r2, [r3, #0x8] */
/* @0x1f499c cmp r5, r2 */
/* @0x1f49a0 bne 0x1f498c <_Z23YYGML_Variable_SetValueiiiP6RValue+0x220> */
/* @0x1f49a4 ldr r0, [r3, #0xc] */
/* @0x1f49a8 cmp r0, #0 */
/* @0x1f49ac beq 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f49b0 ldrb r3, [r0, #0x68] */
/* @0x1f49b4 cmp r3, #0 */
/* @0x1f49b8 bne 0x1f48f8 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x18c> */
/* @0x1f49bc ldr r3, [r0, #0x4] */
/* @0x1f49c0 cmp r3, #0 */
/* @0x1f49c4 addne r0, r3, r8, lsl #4 */
/* @0x1f49c8 beq 0x1f4a08 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x29c> */
/* @0x1f49cc mov r1, r7 */
/* @0x1f49d0 mov r2, r6 */
/* @0x1f49d4 bl 0xd0b24 <_Z10SET_RValueP6RValueS0_i> */
/* @0x1f49d8 mov r0, #1 */
/* @0x1f49dc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f49e0 mov r0, #0 */
/* @0x1f49e4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f49e8 mov r0, r3 */
/* @0x1f49ec mov r1, r8 */
/* @0x1f49f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f49f4 b 0x1f4850 <_Z23YYGML_Variable_SetValueiiiP6RValue+0xe4> */
/* @0x1f49f8 mov r0, r3 */
/* @0x1f49fc mov r1, r8 */
/* @0x1f4a00 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f4a04 b 0x1f4948 <_Z23YYGML_Variable_SetValueiiiP6RValue+0x1dc> */
/* @0x1f4a08 mov r1, r8 */
/* @0x1f4a0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f4a10 b 0x1f49cc <_Z23YYGML_Variable_SetValueiiiP6RValue+0x260> */
/* @0x1f4a14 andseq sp, pc, r8, asr #9 */
/* @0x1f4a18 .word 0xffffbfec */
/* @0x1f4a1c .word 0xffffbff0 */
/* @0x1f4a20 .word 0xffffbcd8 */
/* @0x1f4a24 .word 0xffffbff4 */

/* ── FUNC 0x1f4a28 · Variable_Global_Serialise(IBuffer*) · size=316 · insn=79 */
/* @0x1f4a28 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1f4a2c add r7, r0, #44 */
/* @0x1f4a30 ldr r8, [pc, #0x120] */
/* @0x1f4a34 mov r6, r0 */
/* @0x1f4a38 ldr r3, [r0] */
/* @0x1f4a3c mov r9, #0 */
/* @0x1f4a40 ldr r8, [pc, r8] */
/* @0x1f4a44 vldr s15, [r8] */
/* @0x1f4a48 vcvt.f64.s32 d7, s15 */
/* @0x1f4a4c str r9, [r0, #0x38] */
/* @0x1f4a50 mov r2, r7 */
/* @0x1f4a54 mov r1, #6 */
/* @0x1f4a58 vmov r4, r5, d7 */
/* @0x1f4a5c vstr s14, [r6, #44] */
/* @0x1f4a60 str r5, [r6, #0x30] */
/* @0x1f4a64 ldr r3, [r3, #0x8] */
/* @0x1f4a68 blx r3 */
/* @0x1f4a6c ldr r3, [r8] */
/* @0x1f4a70 cmp r3, r9 */
/* @0x1f4a74 ble 0x1f4ab0 <_Z25Variable_Global_SerialiseP7IBuffer+0x88> */
/* @0x1f4a78 ldr r5, [pc, #0xdc] */
/* @0x1f4a7c mov r4, r9 */
/* @0x1f4a80 ldr r5, [pc, r5] */
/* @0x1f4a84 ldr r2, [r5] */
/* @0x1f4a88 ldr r3, [r2, #0x4] */
/* @0x1f4a8c cmp r3, #0 */
/* @0x1f4a90 add r0, r3, r4, lsl #4 */
/* @0x1f4a94 beq 0x1f4b48 <_Z25Variable_Global_SerialiseP7IBuffer+0x120> */
/* @0x1f4a98 mov r1, r6 */
/* @0x1f4a9c add r4, r4, #1 */
/* @0x1f4aa0 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer> */
/* @0x1f4aa4 ldr r3, [r8] */
/* @0x1f4aa8 cmp r3, r4 */
/* @0x1f4aac bgt 0x1f4a84 <_Z25Variable_Global_SerialiseP7IBuffer+0x5c> */
/* @0x1f4ab0 ldr r9, [pc, #0xa8] */
/* @0x1f4ab4 mov r8, #0 */
/* @0x1f4ab8 ldr r3, [r6] */
/* @0x1f4abc mov r0, r6 */
/* @0x1f4ac0 ldr r9, [pc, r9] */
/* @0x1f4ac4 vldr s15, [r9] */
/* @0x1f4ac8 vcvt.f64.s32 d7, s15 */
/* @0x1f4acc str r8, [r6, #0x38] */
/* @0x1f4ad0 mov r1, #6 */
/* @0x1f4ad4 mov r2, r7 */
/* @0x1f4ad8 vmov r4, r5, d7 */
/* @0x1f4adc vstr s14, [r6, #44] */
/* @0x1f4ae0 str r5, [r6, #0x30] */
/* @0x1f4ae4 ldr r3, [r3, #0x8] */
/* @0x1f4ae8 blx r3 */
/* @0x1f4aec ldr r3, [r9] */
/* @0x1f4af0 cmp r3, r8 */
/* @0x1f4af4 pople {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f4af8 mov r10, r8 */
/* @0x1f4afc ldr r12, [r9, #0x4] */
/* @0x1f4b00 mov r0, r6 */
/* @0x1f4b04 ldr r3, [r6] */
/* @0x1f4b08 mov r1, #6 */
/* @0x1f4b0c mov r2, r7 */
/* @0x1f4b10 ldrb r4, [r12, r8] */
/* @0x1f4b14 add r8, r8, #1 */
/* @0x1f4b18 str r10, [r6, #0x38] */
/* @0x1f4b1c vmov s15, r4 */
/* @0x1f4b20 vcvt.f64.u32 d7, s15 */
/* @0x1f4b24 vmov r4, r5, d7 */
/* @0x1f4b28 vstr s14, [r6, #44] */
/* @0x1f4b2c str r5, [r6, #0x30] */
/* @0x1f4b30 ldr r3, [r3, #0x8] */
/* @0x1f4b34 blx r3 */
/* @0x1f4b38 ldr r3, [r9] */
/* @0x1f4b3c cmp r3, r8 */
/* @0x1f4b40 bgt 0x1f4afc <_Z25Variable_Global_SerialiseP7IBuffer+0xd4> */
/* @0x1f4b44 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1f4b48 mov r0, r2 */
/* @0x1f4b4c mov r1, r4 */
/* @0x1f4b50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f4b54 b 0x1f4a98 <_Z25Variable_Global_SerialiseP7IBuffer+0x70> */
/* @0x1f4b58 andseq r9, pc, r8, asr #5 */
/* @0x1f4b5c andseq r9, pc, r4, lsr r1 */
/* @0x1f4b60 andseq r12, pc, r8, ror #6 */

/* ── FUNC 0x1f4b64 · Variable_Global_DeSerialise(IBuffer*) · size=428 · insn=107 */
/* @0x1f4b64 ldr r3, [r0] */
/* @0x1f4b68 mov r1, #6 */
/* @0x1f4b6c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1f4b70 add r6, r0, #44 */
/* @0x1f4b74 ldr r3, [r3, #0xc] */
/* @0x1f4b78 sub sp, sp, #12 */
/* @0x1f4b7c mov r2, r6 */
/* @0x1f4b80 mov r5, r0 */
/* @0x1f4b84 blx r3 */
/* @0x1f4b88 mov r0, r6 */
/* @0x1f4b8c mov r1, #0 */
/* @0x1f4b90 ldr r9, [pc, #0x160] */
/* @0x1f4b94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1f4b98 ldr r3, [pc, #0x15c] */
/* @0x1f4b9c add r9, pc, r9 */
/* @0x1f4ba0 ldr r7, [r9, r3] */
/* @0x1f4ba4 ldr r3, [r7] */
/* @0x1f4ba8 cmp r3, r0 */
/* @0x1f4bac beq 0x1f4bc0 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x5c> */
/* @0x1f4bb0 ldr r0, [pc, #0x148] */
/* @0x1f4bb4 add r0, pc, r0 */
/* @0x1f4bb8 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1f4bbc ldr r3, [r7] */
/* @0x1f4bc0 cmp r3, #0 */
/* @0x1f4bc4 ble 0x1f4c00 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x9c> */
/* @0x1f4bc8 ldr r3, [pc, #0x134] */
/* @0x1f4bcc mov r4, #0 */
/* @0x1f4bd0 ldr r8, [r9, r3] */
/* @0x1f4bd4 ldr r2, [r8] */
/* @0x1f4bd8 ldr r3, [r2, #0x4] */
/* @0x1f4bdc cmp r3, #0 */
/* @0x1f4be0 add r0, r3, r4, lsl #4 */
/* @0x1f4be4 beq 0x1f4ca8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x144> */
/* @0x1f4be8 mov r1, r5 */
/* @0x1f4bec add r4, r4, #1 */
/* @0x1f4bf0 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */
/* @0x1f4bf4 ldr r3, [r7] */
/* @0x1f4bf8 cmp r3, r4 */
/* @0x1f4bfc bgt 0x1f4bd4 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x70> */
/* @0x1f4c00 ldr r3, [r5] */
/* @0x1f4c04 mov r1, #6 */
/* @0x1f4c08 mov r2, r6 */
/* @0x1f4c0c mov r0, r5 */
/* @0x1f4c10 ldr r3, [r3, #0xc] */
/* @0x1f4c14 blx r3 */
/* @0x1f4c18 mov r0, r6 */
/* @0x1f4c1c mov r1, #0 */
/* @0x1f4c20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1f4c24 subs r7, r0, #0 */
/* @0x1f4c28 beq 0x1f4cb8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x154> */
/* @0x1f4c2c ldr r0, [pc, #0xd4] */
/* @0x1f4c30 mov r4, #0 */
/* @0x1f4c34 ldr r2, [pc, #0xd0] */
/* @0x1f4c38 mov r1, r7 */
/* @0x1f4c3c mov r3, #106 */
/* @0x1f4c40 ldr r8, [r9, r0] */
/* @0x1f4c44 add r2, pc, r2 */
/* @0x1f4c48 ldr r0, [r8, #0x4] */
/* @0x1f4c4c str r4, [sp] */
/* @0x1f4c50 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1f4c54 cmp r7, r4 */
/* @0x1f4c58 str r7, [r8] */
/* @0x1f4c5c str r0, [r8, #0x4] */
/* @0x1f4c60 ble 0x1f4c9c <_Z27Variable_Global_DeSerialiseP7IBuffer+0x138> */
/* @0x1f4c64 ldr r3, [r5] */
/* @0x1f4c68 mov r1, #6 */
/* @0x1f4c6c mov r2, r6 */
/* @0x1f4c70 mov r0, r5 */
/* @0x1f4c74 ldr r3, [r3, #0xc] */
/* @0x1f4c78 blx r3 */
/* @0x1f4c7c mov r0, r6 */
/* @0x1f4c80 mov r1, #0 */
/* @0x1f4c84 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1f4c88 ldr r3, [r8, #0x4] */
/* @0x1f4c8c strb r0, [r3, r4] */
/* @0x1f4c90 add r4, r4, #1 */
/* @0x1f4c94 cmp r4, r7 */
/* @0x1f4c98 bne 0x1f4c64 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x100> */
/* @0x1f4c9c mov r0, #1 */
/* @0x1f4ca0 add sp, sp, #12 */
/* @0x1f4ca4 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f4ca8 mov r0, r2 */
/* @0x1f4cac mov r1, r4 */
/* @0x1f4cb0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x1f4cb4 b 0x1f4be8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x84> */
/* @0x1f4cb8 ldr r3, [pc, #0x48] */
/* @0x1f4cbc ldr r8, [r9, r3] */
/* @0x1f4cc0 ldr r4, [r8, #0x4] */
/* @0x1f4cc4 cmp r4, #0 */
/* @0x1f4cc8 beq 0x1f4cec <_Z27Variable_Global_DeSerialiseP7IBuffer+0x188> */
/* @0x1f4ccc mov r0, r4 */
/* @0x1f4cd0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4cd4 str r7, [r8, #0x4] */
/* @0x1f4cd8 mov r3, #0 */
/* @0x1f4cdc mov r0, #1 */
/* @0x1f4ce0 str r3, [r8] */
/* @0x1f4ce4 add sp, sp, #12 */
/* @0x1f4ce8 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x1f4cec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1f4cf0 str r4, [r8, #0x4] */
/* @0x1f4cf4 b 0x1f4cd8 <_Z27Variable_Global_DeSerialiseP7IBuffer+0x174> */
/* @0x1f4cf8 ldrheq sp, [pc], -r4 */
/* @0x1f4cfc .word 0xffffc0b8 */
/* @0x1f4d00 andseq sp, r5, r8, ror r12 */
/* @0x1f4d04 .word 0xffffbf64 */
/* @0x1f4d08 .word 0xfffff1d8 */
/* @0x1f4d0c ldrsheq r8, [r5], -r0 */
