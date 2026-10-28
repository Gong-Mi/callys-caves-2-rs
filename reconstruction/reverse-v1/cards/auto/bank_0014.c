/* libyoyo.so 覆盖卡组 0014
 * 函数 0xd5838..0xd8374，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xd5838 · YYprintf(char const*, ...) · size=136 · insn=34 */
/* @0xd5838 push {r0, r1, r2, r3} */
/* @0xd583c push {r4, r5, lr} */
/* @0xd5840 sub sp, sp, #1024 */
/* @0xd5844 ldr r4, [pc, #0x6c] */
/* @0xd5848 sub sp, sp, #12 */
/* @0xd584c add r5, sp, #4 */
/* @0xd5850 add r2, sp, #1040 */
/* @0xd5854 ldr r4, [pc, r4] */
/* @0xd5858 add r2, r2, #12 */
/* @0xd585c ldr r1, [sp, #0x418] */
/* @0xd5860 mov r0, r5 */
/* @0xd5864 ldr r3, [r4] */
/* @0xd5868 str r2, [sp] */
/* @0xd586c str r3, [sp, #0x404] */
/* @0xd5870 bl 0xb667c <vsprintf@plt> */
/* @0xd5874 ldr r3, [pc, #0x40] */
/* @0xd5878 mov r1, r5 */
/* @0xd587c ldr r3, [pc, r3] */
/* @0xd5880 ldr r0, [r3] */
/* @0xd5884 ldr r3, [r0] */
/* @0xd5888 ldr r3, [r3, #0xc] */
/* @0xd588c blx r3 */
/* @0xd5890 ldr r2, [sp, #0x404] */
/* @0xd5894 ldr r3, [r4] */
/* @0xd5898 cmp r2, r3 */
/* @0xd589c bne 0xd58b4 <_Z8YYprintfPKcz+0x7c> */
/* @0xd58a0 add sp, sp, #1024 */
/* @0xd58a4 add sp, sp, #12 */
/* @0xd58a8 pop {r4, r5, lr} */
/* @0xd58ac add sp, sp, #16 */
/* @0xd58b0 bx lr */
/* @0xd58b4 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd58b8 ldrshteq r8, [r1], -r12 */
/* @0xd58bc mlaseq r1, r8, lr, r7 */

/* ── FUNC 0xd58c0 · yyitoa(int, char*, int) · size=4 · insn=1 */
/* @0xd58c0 b 0xc4964 <_Z5_itoaiPci> */

/* ── FUNC 0xd58c4 · YYStrBuilder::operator<<(int) · size=244 · insn=61 */
/* @0xd58c4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xd58c8 sub sp, sp, #268 */
/* @0xd58cc ldr r5, [pc, #0xe0] */
/* @0xd58d0 add r6, sp, #4 */
/* @0xd58d4 mov r4, r0 */
/* @0xd58d8 mov r2, #10 */
/* @0xd58dc ldr r5, [pc, r5] */
/* @0xd58e0 mov r0, r1 */
/* @0xd58e4 mov r1, r6 */
/* @0xd58e8 ldr r3, [r5] */
/* @0xd58ec str r3, [sp, #0x104] */
/* @0xd58f0 bl 0xd58c0 <_Z6yyitoaiPci> */
/* @0xd58f4 mov r0, r6 */
/* @0xd58f8 bl 0xb6538 <strlen@plt> */
/* @0xd58fc ldr r2, [r4, #0x8] */
/* @0xd5900 ldr r3, [r4, #0x4] */
/* @0xd5904 add r1, r0, #1 */
/* @0xd5908 mov r7, r0 */
/* @0xd590c mvn r0, r2 */
/* @0xd5910 add r0, r3, r0 */
/* @0xd5914 cmp r1, r0 */
/* @0xd5918 ble 0xd5978 <_ZN12YYStrBuilderlsEi+0xb4> */
/* @0xd591c cmp r3, #0 */
/* @0xd5920 add r2, r1, r2 */
/* @0xd5924 ldr r9, [r4] */
/* @0xd5928 moveq r3, r1 */
/* @0xd592c add r3, r3, r3, lsl #1 */
/* @0xd5930 add r3, r3, r3, lsr #31 */
/* @0xd5934 asr r8, r3, #1 */
/* @0xd5938 cmp r8, r2 */
/* @0xd593c addlt r2, r2, r2, lsl #1 */
/* @0xd5940 addlt r2, r2, r2, lsr #31 */
/* @0xd5944 asrlt r8, r2, #1 */
/* @0xd5948 mov r0, r8 */
/* @0xd594c bl 0xcef4c <_Z7YYAlloci> */
/* @0xd5950 ldr r2, [r4, #0x4] */
/* @0xd5954 mov r1, r9 */
/* @0xd5958 str r0, [r4] */
/* @0xd595c bl 0xb65bc <memcpy@plt> */
/* @0xd5960 cmp r9, #0 */
/* @0xd5964 str r8, [r4, #0x4] */
/* @0xd5968 beq 0xd5974 <_ZN12YYStrBuilderlsEi+0xb0> */
/* @0xd596c mov r0, r9 */
/* @0xd5970 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xd5974 ldr r2, [r4, #0x8] */
/* @0xd5978 ldr r0, [r4] */
/* @0xd597c mov r1, r6 */
/* @0xd5980 add r0, r0, r2 */
/* @0xd5984 bl 0xb65a4 <strcpy@plt> */
/* @0xd5988 ldr r1, [sp, #0x104] */
/* @0xd598c ldr r2, [r5] */
/* @0xd5990 mov r0, r4 */
/* @0xd5994 ldr r3, [r4, #0x8] */
/* @0xd5998 cmp r1, r2 */
/* @0xd599c add r7, r3, r7 */
/* @0xd59a0 str r7, [r4, #0x8] */
/* @0xd59a4 bne 0xd59b0 <_ZN12YYStrBuilderlsEi+0xec> */
/* @0xd59a8 add sp, sp, #268 */
/* @0xd59ac pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xd59b0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0xd59b4 eorseq r8, r1, r4, ror r0 */

/* ── FUNC 0xd59b8 · MarkObjectAsCurrent(void*) · size=28 · insn=7 */
/* @0xd59b8 cmp r0, #0 */
/* @0xd59bc ldrne r3, [pc, #0xc] */
/* @0xd59c0 ldrne r3, [pc, r3] */
/* @0xd59c4 ldrne r3, [r3] */
/* @0xd59c8 strne r3, [r0, #0x34] */
/* @0xd59cc bx lr */
/* @0xd59d0 eorseq r8, r1, r12, lsl #5 */

/* ── FUNC 0xd59d4 · AddToSlotTraversalMap(int) · size=196 · insn=49 */
/* @0xd59d4 ldr r12, [pc, #0xa4] */
/* @0xd59d8 ldr r3, [pc, #0xa4] */
/* @0xd59dc add r12, pc, r12 */
/* @0xd59e0 ldr r1, [pc, #0xa0] */
/* @0xd59e4 push {r4, r5, r6, r7, lr} */
/* @0xd59e8 sub sp, sp, #12 */
/* @0xd59ec ldr r3, [r12, r3] */
/* @0xd59f0 mov r6, r0 */
/* @0xd59f4 ldr r2, [pc, #0x90] */
/* @0xd59f8 ldr r5, [r12, r1] */
/* @0xd59fc ldr r4, [r3] */
/* @0xd5a00 ldr r2, [r12, r2] */
/* @0xd5a04 ldr r3, [r5, r4, lsl #2] */
/* @0xd5a08 ldr r1, [r2, r4, lsl #2] */
/* @0xd5a0c cmp r3, r1 */
/* @0xd5a10 blt 0xd5a70 <_Z21AddToSlotTraversalMapi+0x9c> */
/* @0xd5a14 ldr lr, [pc, #0x74] */
/* @0xd5a18 lsls r3, r1, #1 */
/* @0xd5a1c strne r3, [r2, r4, lsl #2] */
/* @0xd5a20 mov r0, #0 */
/* @0xd5a24 moveq r3, #1 */
/* @0xd5a28 streq r3, [r2, r4, lsl #2] */
/* @0xd5a2c ldr r7, [r12, lr] */
/* @0xd5a30 mov r3, #74 */
/* @0xd5a34 ldr r2, [pc, #0x58] */
/* @0xd5a38 lslne r1, r1, #3 */
/* @0xd5a3c str r0, [sp] */
/* @0xd5a40 moveq r1, #4 */
/* @0xd5a44 add r2, pc, r2 */
/* @0xd5a48 ldr r0, [r7, r4, lsl #2] */
/* @0xd5a4c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd5a50 ldr r3, [r5, r4, lsl #2] */
/* @0xd5a54 mov r2, r0 */
/* @0xd5a58 str r0, [r7, r4, lsl #2] */
/* @0xd5a5c add r1, r3, #1 */
/* @0xd5a60 str r1, [r5, r4, lsl #2] */
/* @0xd5a64 str r6, [r2, r3, lsl #2] */
/* @0xd5a68 add sp, sp, #12 */
/* @0xd5a6c pop {r4, r5, r6, r7, pc} */
/* @0xd5a70 ldr r2, [pc, #0x18] */
/* @0xd5a74 ldr r2, [r12, r2] */
/* @0xd5a78 ldr r2, [r2, r4, lsl #2] */
/* @0xd5a7c b 0xd5a5c <_Z21AddToSlotTraversalMapi+0x88> */
/* @0xd5a80 eorseq r12, r1, r4, ror r2 */
/* @0xd5a84 .word 0xffffc000 */
/* @0xd5a88 .word 0xffffc004 */
/* @0xd5a8c .word 0xffffc008 */
/* @0xd5a90 .word 0xffffc00c */
/* @0xd5a94 eoreq r11, r5, r12, ror #11 */

/* ── FUNC 0xd5a98 · ResetSlotTraversalMap() · size=40 · insn=10 */
/* @0xd5a98 ldr r2, [pc, #0x18] */
/* @0xd5a9c mov r1, #0 */
/* @0xd5aa0 ldr r3, [pc, #0x14] */
/* @0xd5aa4 ldr r2, [pc, r2] */
/* @0xd5aa8 ldr r3, [pc, r3] */
/* @0xd5aac ldr r2, [r2] */
/* @0xd5ab0 str r1, [r3, r2, lsl #2] */
/* @0xd5ab4 bx lr */
/* @0xd5ab8 eorseq r8, r1, r12, lsr #3 */
/* @0xd5abc eorseq r8, r1, r12, lsr #3 */

/* ── FUNC 0xd5ac0 · SetCurrSlotTraversalMap(int) · size=20 · insn=5 */
/* @0xd5ac0 ldr r3, [pc, #0x8] */
/* @0xd5ac4 ldr r3, [pc, r3] */
/* @0xd5ac8 str r0, [r3] */
/* @0xd5acc bx lr */
/* @0xd5ad0 eorseq r8, r1, r12, lsl #3 */

/* ── FUNC 0xd5ad4 · GetFirstSlotTraversalDivergence(int, int) · size=140 · insn=35 */
/* @0xd5ad4 ldr r3, [pc, #0x7c] */
/* @0xd5ad8 push {r4, r5, r6} */
/* @0xd5adc ldr r3, [pc, r3] */
/* @0xd5ae0 ldr r5, [r3, r0, lsl #2] */
/* @0xd5ae4 ldr r6, [r3, r1, lsl #2] */
/* @0xd5ae8 cmp r5, r6 */
/* @0xd5aec movlt r4, r5 */
/* @0xd5af0 movge r4, r6 */
/* @0xd5af4 cmp r4, #0 */
/* @0xd5af8 ble 0xd5b50 <_Z31GetFirstSlotTraversalDivergenceii+0x7c> */
/* @0xd5afc ldr r3, [pc, #0x58] */
/* @0xd5b00 ldr r3, [pc, r3] */
/* @0xd5b04 ldr r2, [r3, r0, lsl #2] */
/* @0xd5b08 ldr r3, [r3, r1, lsl #2] */
/* @0xd5b0c ldr r0, [r2] */
/* @0xd5b10 ldr r1, [r3] */
/* @0xd5b14 cmp r0, r1 */
/* @0xd5b18 mov r0, #0 */
/* @0xd5b1c beq 0xd5b34 <_Z31GetFirstSlotTraversalDivergenceii+0x60> */
/* @0xd5b20 b 0xd5b48 <_Z31GetFirstSlotTraversalDivergenceii+0x74> */
/* @0xd5b24 ldr r12, [r2, #0x4]! */
/* @0xd5b28 ldr r1, [r3, #0x4]! */
/* @0xd5b2c cmp r12, r1 */
/* @0xd5b30 bne 0xd5b48 <_Z31GetFirstSlotTraversalDivergenceii+0x74> */
/* @0xd5b34 add r0, r0, #1 */
/* @0xd5b38 cmp r0, r4 */
/* @0xd5b3c bne 0xd5b24 <_Z31GetFirstSlotTraversalDivergenceii+0x50> */
/* @0xd5b40 cmp r5, r6 */
/* @0xd5b44 mvneq r0, #0 */
/* @0xd5b48 pop {r4, r5, r6} */
/* @0xd5b4c bx lr */
/* @0xd5b50 mov r0, #0 */
/* @0xd5b54 b 0xd5b40 <_Z31GetFirstSlotTraversalDivergenceii+0x6c> */
/* @0xd5b58 eorseq r8, r1, r8, ror r1 */
/* @0xd5b5c eorseq r8, r1, r12, asr r1 */

/* ── FUNC 0xd5b60 · RemoveGCRoot(YYObjectBase*) · size=72 · insn=18 */
/* @0xd5b60 ldr r3, [r0, #0x38] */
/* @0xd5b64 push {r4, r5, r6, lr} */
/* @0xd5b68 cmp r3, #0 */
/* @0xd5b6c mov r6, r0 */
/* @0xd5b70 poplt {r4, r5, r6, pc} */
/* @0xd5b74 ldr r4, [pc, #0x28] */
/* @0xd5b78 mov r5, #0 */
/* @0xd5b7c ldr r4, [pc, r4] */
/* @0xd5b80 mov r0, r4 */
/* @0xd5b84 mov r1, r6 */
/* @0xd5b88 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase> */
/* @0xd5b8c ldr r3, [r6, #0x38] */
/* @0xd5b90 add r5, r5, #1 */
/* @0xd5b94 add r4, r4, #88 */
/* @0xd5b98 cmp r3, r5 */
/* @0xd5b9c bge 0xd5b80 <_Z12RemoveGCRootP12YYObjectBase+0x20> */
/* @0xd5ba0 pop {r4, r5, r6, pc} */
/* @0xd5ba4 eorseq r8, r1, r4, ror #1 */

/* ── FUNC 0xd5ba8 · MarkAndSweepGen(int, int, bool) · size=2872 · insn=718 */
/* @0xd5ba8 ldr r12, [pc, #0xad8] */
/* @0xd5bac ldr r3, [pc, #0xad8] */
/* @0xd5bb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd5bb4 vpush {d8} */
/* @0xd5bb8 add r12, pc, r12 */
/* @0xd5bbc sub sp, sp, #116 */
/* @0xd5bc0 mov r6, r2 */
/* @0xd5bc4 str r12, [sp, #0x1c] */
/* @0xd5bc8 str r0, [sp, #0x14] */
/* @0xd5bcc str r1, [sp, #0x48] */
/* @0xd5bd0 ldr r3, [r12, r3] */
/* @0xd5bd4 ldrb r3, [r3] */
/* @0xd5bd8 cmp r3, #0 */
/* @0xd5bdc beq 0xd5be8 <_Z15MarkAndSweepGeniib+0x40> */
/* @0xd5be0 cmp r0, #3 */
/* @0xd5be4 bls 0xd5bf4 <_Z15MarkAndSweepGeniib+0x4c> */
/* @0xd5be8 add sp, sp, #116 */
/* @0xd5bec vpop {d8} */
/* @0xd5bf0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd5bf4 ldr r1, [pc, #0xa94] */
/* @0xd5bf8 mov r3, #88 */
/* @0xd5bfc ldr r2, [pc, #0xa90] */
/* @0xd5c00 ldr r8, [r12, r1] */
/* @0xd5c04 ldr r1, [r8] */
/* @0xd5c08 add r1, r1, #1 */
/* @0xd5c0c str r1, [r8] */
/* @0xd5c10 ldr r2, [r12, r2] */
/* @0xd5c14 mla r11, r3, r0, r2 */
/* @0xd5c18 str r2, [sp, #0x18] */
/* @0xd5c1c bl 0x215148 <Timing_Time> */
/* @0xd5c20 ldr r12, [sp, #0x1c] */
/* @0xd5c24 ldr r2, [pc, #0xa6c] */
/* @0xd5c28 ldr r3, [pc, #0xa6c] */
/* @0xd5c2c strd r0, r1, [sp, #80] */
/* @0xd5c30 ldr r10, [r12, r2] */
/* @0xd5c34 ldr r9, [r12, r3] */
/* @0xd5c38 ldr r12, [r10, #0x4] */
/* @0xd5c3c ldr r3, [r9] */
/* @0xd5c40 adds r5, r12, #31 */
/* @0xd5c44 str r12, [sp, #0x30] */
/* @0xd5c48 ldr r12, [r10, #0x8] */
/* @0xd5c4c str r12, [sp, #0x38] */
/* @0xd5c50 ldr r12, [sp, #0x30] */
/* @0xd5c54 addmi r5, r12, #62 */
/* @0xd5c58 asr r5, r5, #5 */
/* @0xd5c5c cmp r5, r3 */
/* @0xd5c60 beq 0xd5ca4 <_Z15MarkAndSweepGeniib+0xfc> */
/* @0xd5c64 ldr r0, [pc, #0xa34] */
/* @0xd5c68 lsl r7, r5, #2 */
/* @0xd5c6c ldr lr, [sp, #0x1c] */
/* @0xd5c70 mov r12, #0 */
/* @0xd5c74 ldr r2, [pc, #0xa28] */
/* @0xd5c78 mov r3, #74 */
/* @0xd5c7c mov r1, r7 */
/* @0xd5c80 ldr r4, [lr, r0] */
/* @0xd5c84 add r2, pc, r2 */
/* @0xd5c88 ldr r0, [r4] */
/* @0xd5c8c str r12, [sp] */
/* @0xd5c90 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd5c94 str r5, [r9] */
/* @0xd5c98 mov r3, r0 */
/* @0xd5c9c str r0, [r4] */
/* @0xd5ca0 b 0xd5cb8 <_Z15MarkAndSweepGeniib+0x110> */
/* @0xd5ca4 ldr r3, [pc, #0x9f4] */
/* @0xd5ca8 lsl r7, r5, #2 */
/* @0xd5cac ldr r12, [sp, #0x1c] */
/* @0xd5cb0 ldr r4, [r12, r3] */
/* @0xd5cb4 ldr r3, [r4] */
/* @0xd5cb8 mov r0, r3 */
/* @0xd5cbc mov r2, r7 */
/* @0xd5cc0 mov r1, #0 */
/* @0xd5cc4 bl 0xb65b0 <memset@plt> */
/* @0xd5cc8 mov r0, r11 */
/* @0xd5ccc bl 0x191400 <_ZN13CGCGeneration17ResetDynamicRootsEv> */
/* @0xd5cd0 cmp r6, #0 */
/* @0xd5cd4 beq 0xd5f40 <_Z15MarkAndSweepGeniib+0x398> */
/* @0xd5cd8 ldr r3, [pc, #0x9c8] */
/* @0xd5cdc ldr r12, [sp, #0x1c] */
/* @0xd5ce0 ldr r5, [r12, r3] */
/* @0xd5ce4 ldr r3, [r5] */
/* @0xd5ce8 cmp r3, #0 */
/* @0xd5cec beq 0xd5f40 <_Z15MarkAndSweepGeniib+0x398> */
/* @0xd5cf0 ldr r1, [r3, #0x80] */
/* @0xd5cf4 cmp r1, #0 */
/* @0xd5cf8 beq 0xd5d1c <_Z15MarkAndSweepGeniib+0x174> */
/* @0xd5cfc ldr r6, [r1, #0x178] */
/* @0xd5d00 mov r0, r11 */
/* @0xd5d04 mov r2, #1 */
/* @0xd5d08 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d0c cmp r6, #0 */
/* @0xd5d10 mov r1, r6 */
/* @0xd5d14 bne 0xd5cfc <_Z15MarkAndSweepGeniib+0x154> */
/* @0xd5d18 ldr r3, [r5] */
/* @0xd5d1c ldr r1, [r3, #0x8c] */
/* @0xd5d20 cmp r1, #0 */
/* @0xd5d24 beq 0xd5d44 <_Z15MarkAndSweepGeniib+0x19c> */
/* @0xd5d28 ldr r5, [r1, #0x178] */
/* @0xd5d2c mov r0, r11 */
/* @0xd5d30 mov r2, #1 */
/* @0xd5d34 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d38 cmp r5, #0 */
/* @0xd5d3c mov r1, r5 */
/* @0xd5d40 bne 0xd5d28 <_Z15MarkAndSweepGeniib+0x180> */
/* @0xd5d44 ldr r3, [pc, #0x960] */
/* @0xd5d48 ldr r12, [sp, #0x1c] */
/* @0xd5d4c ldr r3, [r12, r3] */
/* @0xd5d50 ldr r1, [r3] */
/* @0xd5d54 cmp r1, #0 */
/* @0xd5d58 beq 0xd5d68 <_Z15MarkAndSweepGeniib+0x1c0> */
/* @0xd5d5c mov r0, r11 */
/* @0xd5d60 mov r2, #1 */
/* @0xd5d64 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d68 ldr r3, [pc, #0x940] */
/* @0xd5d6c ldr r12, [sp, #0x1c] */
/* @0xd5d70 ldr r3, [r12, r3] */
/* @0xd5d74 ldr r1, [r3, #0x8] */
/* @0xd5d78 cmp r1, #0 */
/* @0xd5d7c beq 0xd5d8c <_Z15MarkAndSweepGeniib+0x1e4> */
/* @0xd5d80 mov r0, r11 */
/* @0xd5d84 mov r2, #1 */
/* @0xd5d88 bl 0x19135c <_ZN13CGCGeneration14AddDynamicRootEP12YYObjectBaseb> */
/* @0xd5d8c add r5, sp, #92 */
/* @0xd5d90 mov r0, r5 */
/* @0xd5d94 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xd5d98 ldr r3, [pc, #0x914] */
/* @0xd5d9c ldr r12, [sp, #0x1c] */
/* @0xd5da0 ldr r7, [r12, r3] */
/* @0xd5da4 ldr r3, [r7] */
/* @0xd5da8 cmp r3, #0 */
/* @0xd5dac ble 0xd5de8 <_Z15MarkAndSweepGeniib+0x240> */
/* @0xd5db0 ldr r3, [pc, #0x900] */
/* @0xd5db4 mov r6, #0 */
/* @0xd5db8 ldr r12, [sp, #0x1c] */
/* @0xd5dbc ldr r9, [r12, r3] */
/* @0xd5dc0 ldr r3, [r9, #0x4] */
/* @0xd5dc4 mov r1, r11 */
/* @0xd5dc8 ldr r0, [r3, r6, lsl #2] */
/* @0xd5dcc add r6, r6, #1 */
/* @0xd5dd0 cmp r0, #0 */
/* @0xd5dd4 beq 0xd5ddc <_Z15MarkAndSweepGeniib+0x234> */
/* @0xd5dd8 bl 0x2037b4 <_ZN7CDS_Map6Add4GCEP13CGCGeneration> */
/* @0xd5ddc ldr r3, [r7] */
/* @0xd5de0 cmp r3, r6 */
/* @0xd5de4 bgt 0xd5dc0 <_Z15MarkAndSweepGeniib+0x218> */
/* @0xd5de8 ldr r3, [pc, #0x8cc] */
/* @0xd5dec ldr r12, [sp, #0x1c] */
/* @0xd5df0 ldr r7, [r12, r3] */
/* @0xd5df4 ldr r3, [r7] */
/* @0xd5df8 cmp r3, #0 */
/* @0xd5dfc ble 0xd5e38 <_Z15MarkAndSweepGeniib+0x290> */
/* @0xd5e00 ldr r3, [pc, #0x8b8] */
/* @0xd5e04 mov r6, #0 */
/* @0xd5e08 ldr r12, [sp, #0x1c] */
/* @0xd5e0c ldr r9, [r12, r3] */
/* @0xd5e10 ldr r3, [r9, #0x4] */
/* @0xd5e14 mov r1, r11 */
/* @0xd5e18 ldr r0, [r3, r6, lsl #2] */
/* @0xd5e1c add r6, r6, #1 */
/* @0xd5e20 cmp r0, #0 */
/* @0xd5e24 beq 0xd5e2c <_Z15MarkAndSweepGeniib+0x284> */
/* @0xd5e28 bl 0x2030f4 <_ZN8CDS_List6Add4GCEP13CGCGeneration> */
/* @0xd5e2c ldr r3, [r7] */
/* @0xd5e30 cmp r3, r6 */
/* @0xd5e34 bgt 0xd5e10 <_Z15MarkAndSweepGeniib+0x268> */
/* @0xd5e38 add r0, sp, #96 */
/* @0xd5e3c bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xd5e40 ldr r3, [sp, #0x60] */
/* @0xd5e44 cmp r3, #0 */
/* @0xd5e48 movgt r6, #0 */
/* @0xd5e4c subgt r7, r0, #4 */
/* @0xd5e50 ble 0xd5e78 <_Z15MarkAndSweepGeniib+0x2d0> */
/* @0xd5e54 ldr r0, [r7, #0x4]! */
/* @0xd5e58 mov r1, r11 */
/* @0xd5e5c add r6, r6, #1 */
/* @0xd5e60 cmp r0, #0 */
/* @0xd5e64 beq 0xd5e70 <_Z15MarkAndSweepGeniib+0x2c8> */
/* @0xd5e68 bl 0x202d98 <_ZN9CDS_Stack6Add4GCEP13CGCGeneration> */
/* @0xd5e6c ldr r3, [sp, #0x60] */
/* @0xd5e70 cmp r3, r6 */
/* @0xd5e74 bgt 0xd5e54 <_Z15MarkAndSweepGeniib+0x2ac> */
/* @0xd5e78 add r0, sp, #100 */
/* @0xd5e7c bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xd5e80 ldr r3, [sp, #0x64] */
/* @0xd5e84 cmp r3, #0 */
/* @0xd5e88 movgt r6, #0 */
/* @0xd5e8c subgt r7, r0, #4 */
/* @0xd5e90 ble 0xd5eb8 <_Z15MarkAndSweepGeniib+0x310> */
/* @0xd5e94 ldr r0, [r7, #0x4]! */
/* @0xd5e98 mov r1, r11 */
/* @0xd5e9c add r6, r6, #1 */
/* @0xd5ea0 cmp r0, #0 */
/* @0xd5ea4 beq 0xd5eb0 <_Z15MarkAndSweepGeniib+0x308> */
/* @0xd5ea8 bl 0x202f20 <_ZN9CDS_Queue6Add4GCEP13CGCGeneration> */
/* @0xd5eac ldr r3, [sp, #0x64] */
/* @0xd5eb0 cmp r3, r6 */
/* @0xd5eb4 bgt 0xd5e94 <_Z15MarkAndSweepGeniib+0x2ec> */
/* @0xd5eb8 add r0, sp, #104 */
/* @0xd5ebc bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xd5ec0 ldr r3, [sp, #0x68] */
/* @0xd5ec4 cmp r3, #0 */
/* @0xd5ec8 movgt r6, #0 */
/* @0xd5ecc subgt r7, r0, #4 */
/* @0xd5ed0 ble 0xd5ef8 <_Z15MarkAndSweepGeniib+0x350> */
/* @0xd5ed4 ldr r0, [r7, #0x4]! */
/* @0xd5ed8 mov r1, r11 */
/* @0xd5edc add r6, r6, #1 */
/* @0xd5ee0 cmp r0, #0 */
/* @0xd5ee4 beq 0xd5ef0 <_Z15MarkAndSweepGeniib+0x348> */
/* @0xd5ee8 bl 0x2051dc <_ZN8CDS_Grid6Add4GCEP13CGCGeneration> */
/* @0xd5eec ldr r3, [sp, #0x68] */
/* @0xd5ef0 cmp r3, r6 */
/* @0xd5ef4 bgt 0xd5ed4 <_Z15MarkAndSweepGeniib+0x32c> */
/* @0xd5ef8 add r0, sp, #108 */
/* @0xd5efc bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xd5f00 ldr r3, [sp, #0x6c] */
/* @0xd5f04 cmp r3, #0 */
/* @0xd5f08 movgt r6, #0 */
/* @0xd5f0c subgt r7, r0, #4 */
/* @0xd5f10 ble 0xd5f38 <_Z15MarkAndSweepGeniib+0x390> */
/* @0xd5f14 ldr r0, [r7, #0x4]! */
/* @0xd5f18 mov r1, r11 */
/* @0xd5f1c add r6, r6, #1 */
/* @0xd5f20 cmp r0, #0 */
/* @0xd5f24 beq 0xd5f30 <_Z15MarkAndSweepGeniib+0x388> */
/* @0xd5f28 bl 0x203ea4 <_ZN12CDS_Priority6Add4GCEP13CGCGeneration> */
/* @0xd5f2c ldr r3, [sp, #0x6c] */
/* @0xd5f30 cmp r3, r6 */
/* @0xd5f34 bgt 0xd5f14 <_Z15MarkAndSweepGeniib+0x36c> */
/* @0xd5f38 mov r0, r5 */
/* @0xd5f3c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xd5f40 ldr r12, [sp, #0x1c] */
/* @0xd5f44 mov r3, #0 */
/* @0xd5f48 ldr r1, [pc, #0x774] */
/* @0xd5f4c mov r9, r11 */
/* @0xd5f50 str r3, [sp, #0x40] */
/* @0xd5f54 mov r7, r3 */
/* @0xd5f58 ldr r2, [pc, #0x768] */
/* @0xd5f5c mov r5, #1 */
/* @0xd5f60 ldr r1, [r12, r1] */
/* @0xd5f64 str r1, [sp, #0x4c] */
/* @0xd5f68 str r3, [r1] */
/* @0xd5f6c ldr r6, [r12, r2] */
/* @0xd5f70 ldr r12, [sp, #0x14] */
/* @0xd5f74 mov r11, r6 */
/* @0xd5f78 str r12, [r6] */
/* @0xd5f7c mov r6, r8 */
/* @0xd5f80 ldr r8, [sp, #0x1c] */
/* @0xd5f84 ldr r2, [r9] */
/* @0xd5f88 add r3, r7, r7, lsl #1 */
/* @0xd5f8c ldr r1, [r2, #0x10] */
/* @0xd5f90 ldr r0, [r2] */
/* @0xd5f94 add r3, r1, r3, lsl #2 */
/* @0xd5f98 b 0xd5fa8 <_Z15MarkAndSweepGeniib+0x400> */
/* @0xd5f9c ldr r1, [r2, #0x8] */
/* @0xd5fa0 cmp r1, #0 */
/* @0xd5fa4 bgt 0xd65b4 <_Z15MarkAndSweepGeniib+0xa0c> */
/* @0xd5fa8 add r7, r7, #1 */
/* @0xd5fac mov r2, r3 */
/* @0xd5fb0 cmp r0, r7 */
/* @0xd5fb4 add r3, r3, #12 */
/* @0xd5fb8 bge 0xd5f9c <_Z15MarkAndSweepGeniib+0x3f4> */
/* @0xd5fbc ldr r3, [r9, #0x8] */
/* @0xd5fc0 mov r6, r11 */
/* @0xd5fc4 mov r11, r9 */
/* @0xd5fc8 cmp r3, #0 */
/* @0xd5fcc ble 0xd6018 <_Z15MarkAndSweepGeniib+0x470> */
/* @0xd5fd0 ldr r8, [sp, #0x30] */
/* @0xd5fd4 mov r7, #0 */
/* @0xd5fd8 ldr r9, [sp, #0x1c] */
/* @0xd5fdc mov r5, #1 */
/* @0xd5fe0 ldr r1, [r11, #0x4] */
/* @0xd5fe4 mov r2, r8 */
/* @0xd5fe8 ldr r12, [pc, #0x6dc] */
/* @0xd5fec ldr r0, [r1, r7, lsl #2] */
/* @0xd5ff0 add r7, r7, #1 */
/* @0xd5ff4 cmp r0, #0 */
/* @0xd5ff8 beq 0xd6010 <_Z15MarkAndSweepGeniib+0x468> */
/* @0xd5ffc ldr r3, [r9, r12] */
/* @0xd6000 ldr r1, [r4] */
/* @0xd6004 strb r5, [r3] */
/* @0xd6008 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd600c ldr r3, [r11, #0x8] */
/* @0xd6010 cmp r3, r7 */
/* @0xd6014 bgt 0xd5fe0 <_Z15MarkAndSweepGeniib+0x438> */
/* @0xd6018 ldr r12, [sp, #0x14] */
/* @0xd601c mov r3, #4 */
/* @0xd6020 ldr r10, [r10] */
/* @0xd6024 cmp r12, #0 */
/* @0xd6028 ldr r12, [r11, #0x18] */
/* @0xd602c str r3, [r6] */
/* @0xd6030 str r10, [sp, #0x44] */
/* @0xd6034 ldr r2, [r11, #0x14] */
/* @0xd6038 str r12, [sp, #0x3c] */
/* @0xd603c beq 0xd607c <_Z15MarkAndSweepGeniib+0x4d4> */
/* @0xd6040 ldr r3, [sp, #0x18] */
/* @0xd6044 mov r12, #88 */
/* @0xd6048 ldr lr, [sp, #0x14] */
/* @0xd604c ldr r1, [sp, #0x3c] */
/* @0xd6050 mla r12, r12, lr, r3 */
/* @0xd6054 ldr lr, [r3, #0x14] */
/* @0xd6058 add r3, r3, #88 */
/* @0xd605c ldr r0, [r3, #-0x40] */
/* @0xd6060 cmp r2, lr */
/* @0xd6064 movge r2, lr */
/* @0xd6068 cmp r1, r0 */
/* @0xd606c movlt r1, r0 */
/* @0xd6070 cmp r3, r12 */
/* @0xd6074 bne 0xd6054 <_Z15MarkAndSweepGeniib+0x4ac> */
/* @0xd6078 str r1, [sp, #0x3c] */
/* @0xd607c add r1, r2, #31 */
/* @0xd6080 cmp r2, #0 */
/* @0xd6084 ldr r12, [sp, #0x3c] */
/* @0xd6088 mov r7, #0 */
/* @0xd608c movlt r2, r1 */
/* @0xd6090 ldr r3, [r4] */
/* @0xd6094 adds r1, r12, #32 */
/* @0xd6098 asr r2, r2, #5 */
/* @0xd609c addmi r1, r12, #63 */
/* @0xd60a0 str r2, [sp, #0x24] */
/* @0xd60a4 ldr r12, [sp, #0x24] */
/* @0xd60a8 asr r2, r1, #5 */
/* @0xd60ac str r7, [r11, #0x28] */
/* @0xd60b0 sub r2, r2, #1 */
/* @0xd60b4 str r2, [sp, #0x34] */
/* @0xd60b8 cmp r12, r2 */
/* @0xd60bc add r3, r3, r12, lsl #2 */
/* @0xd60c0 str r3, [sp, #0x2c] */
/* @0xd60c4 bge 0xd667c <_Z15MarkAndSweepGeniib+0xad4> */
/* @0xd60c8 ldr r12, [pc, #0x600] */
/* @0xd60cc ldr lr, [sp, #0x24] */
/* @0xd60d0 add r12, pc, r12 */
/* @0xd60d4 str r12, [sp, #0x28] */
/* @0xd60d8 ldr r12, [sp, #0x24] */
/* @0xd60dc str r3, [sp, #0x20] */
/* @0xd60e0 lsl r12, r12, #5 */
/* @0xd60e4 str r12, [sp, #0x10] */
/* @0xd60e8 ldr r12, [sp, #0x44] */
/* @0xd60ec add r12, r12, lr, lsl #7 */
/* @0xd60f0 str r12, [sp, #0xc] */
/* @0xd60f4 ldr r12, [sp, #0x14] */
/* @0xd60f8 add r6, r12, #1 */
/* @0xd60fc ldr r12, [sp, #0x20] */
/* @0xd6100 str r12, [sp, #0x2c] */
/* @0xd6104 ldr r8, [r12], #4 */
/* @0xd6108 cmn r8, #1 */
/* @0xd610c str r12, [sp, #0x20] */
/* @0xd6110 addeq r7, r7, #32 */
/* @0xd6114 beq 0xd61d0 <_Z15MarkAndSweepGeniib+0x628> */
/* @0xd6118 mov r4, #0 */
/* @0xd611c mov lr, #1 */
/* @0xd6120 ands lr, r8, lr, lsl r4 */
/* @0xd6124 bne 0xd61b4 <_Z15MarkAndSweepGeniib+0x60c> */
/* @0xd6128 ldr r12, [sp, #0xc] */
/* @0xd612c ldr r5, [r12, r4, lsl #2] */
/* @0xd6130 ldr r12, [sp, #0x10] */
/* @0xd6134 cmp r5, #0 */
/* @0xd6138 add r3, r12, r4 */
/* @0xd613c beq 0xd61b8 <_Z15MarkAndSweepGeniib+0x610> */
/* @0xd6140 ldr r2, [r5, #0x38] */
/* @0xd6144 ldr r12, [sp, #0x14] */
/* @0xd6148 cmp r12, r2 */
/* @0xd614c blt 0xd61b4 <_Z15MarkAndSweepGeniib+0x60c> */
/* @0xd6150 ldr r2, [r5, #0x44] */
/* @0xd6154 cmp r3, r2 */
/* @0xd6158 beq 0xd617c <_Z15MarkAndSweepGeniib+0x5d4> */
/* @0xd615c ldr r12, [sp, #0x1c] */
/* @0xd6160 ldr r0, [pc, #0x56c] */
/* @0xd6164 ldr r1, [sp, #0x28] */
/* @0xd6168 ldr r0, [r12, r0] */
/* @0xd616c ldr r0, [r0] */
/* @0xd6170 ldr r12, [r0] */
/* @0xd6174 ldr r12, [r12, #0xc] */
/* @0xd6178 blx r12 */
/* @0xd617c ldr r10, [sp, #0x18] */
/* @0xd6180 mov r9, #0 */
/* @0xd6184 mov r0, r10 */
/* @0xd6188 add r9, r9, #1 */
/* @0xd618c mov r1, r5 */
/* @0xd6190 add r10, r10, #88 */
/* @0xd6194 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase> */
/* @0xd6198 cmp r9, r6 */
/* @0xd619c bne 0xd6184 <_Z15MarkAndSweepGeniib+0x5dc> */
/* @0xd61a0 mov r0, r5 */
/* @0xd61a4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd61a8 ldr r3, [r11, #0x28] */
/* @0xd61ac add r3, r3, #1 */
/* @0xd61b0 str r3, [r11, #0x28] */
/* @0xd61b4 add r7, r7, #1 */
/* @0xd61b8 add r4, r4, #1 */
/* @0xd61bc cmp r4, #32 */
/* @0xd61c0 bne 0xd611c <_Z15MarkAndSweepGeniib+0x574> */
/* @0xd61c4 ldr r12, [sp, #0x38] */
/* @0xd61c8 cmp r12, r7 */
/* @0xd61cc ble 0xd6210 <_Z15MarkAndSweepGeniib+0x668> */
/* @0xd61d0 ldr r12, [sp, #0x24] */
/* @0xd61d4 ldr lr, [sp, #0x34] */
/* @0xd61d8 add r12, r12, #1 */
/* @0xd61dc str r12, [sp, #0x24] */
/* @0xd61e0 ldr r12, [sp, #0x10] */
/* @0xd61e4 add r12, r12, #32 */
/* @0xd61e8 str r12, [sp, #0x10] */
/* @0xd61ec ldr r12, [sp, #0x24] */
/* @0xd61f0 cmp r12, lr */
/* @0xd61f4 ldr r12, [sp, #0xc] */
/* @0xd61f8 add r12, r12, #128 */
/* @0xd61fc str r12, [sp, #0xc] */
/* @0xd6200 ldr r12, [sp, #0x20] */
/* @0xd6204 str r12, [sp, #0x2c] */
/* @0xd6208 bne 0xd60fc <_Z15MarkAndSweepGeniib+0x554> */
/* @0xd620c mov r4, #0 */
/* @0xd6210 ldr r12, [sp, #0x24] */
/* @0xd6214 lsl r3, r12, #5 */
/* @0xd6218 ldr r12, [sp, #0x3c] */
/* @0xd621c cmp r3, r12 */
/* @0xd6220 bgt 0xd62e8 <_Z15MarkAndSweepGeniib+0x740> */
/* @0xd6224 ldr r12, [sp, #0x38] */
/* @0xd6228 cmp r7, r12 */
/* @0xd622c bge 0xd62e8 <_Z15MarkAndSweepGeniib+0x740> */
/* @0xd6230 ldr r12, [sp, #0x3c] */
/* @0xd6234 mov r7, #0 */
/* @0xd6238 ldr lr, [sp, #0x24] */
/* @0xd623c mov r10, #1 */
/* @0xd6240 add r9, r12, #1 */
/* @0xd6244 ldr r2, [sp, #0x2c] */
/* @0xd6248 ldr r12, [sp, #0x44] */
/* @0xd624c add r9, r9, r4 */
/* @0xd6250 rsb r9, r3, r9 */
/* @0xd6254 str r9, [sp, #0x10] */
/* @0xd6258 add r12, r12, lr, lsl #7 */
/* @0xd625c str r12, [sp, #0x20] */
/* @0xd6260 ldr r12, [sp, #0x14] */
/* @0xd6264 ldr r2, [r2] */
/* @0xd6268 add r6, r12, #1 */
/* @0xd626c str r2, [sp, #0xc] */
/* @0xd6270 ldr r3, [sp, #0xc] */
/* @0xd6274 ands r2, r3, r10, lsl r4 */
/* @0xd6278 bne 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd627c ldr r12, [sp, #0x20] */
/* @0xd6280 ldr r5, [r12, r7] */
/* @0xd6284 cmp r5, #0 */
/* @0xd6288 beq 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd628c ldr r3, [r5, #0x38] */
/* @0xd6290 ldr r12, [sp, #0x14] */
/* @0xd6294 cmp r12, r3 */
/* @0xd6298 blt 0xd62d4 <_Z15MarkAndSweepGeniib+0x72c> */
/* @0xd629c ldr r8, [sp, #0x18] */
/* @0xd62a0 mov r9, r2 */
/* @0xd62a4 mov r0, r8 */
/* @0xd62a8 add r9, r9, #1 */
/* @0xd62ac mov r1, r5 */
/* @0xd62b0 add r8, r8, #88 */
/* @0xd62b4 bl 0x1911c8 <_ZN13CGCGeneration10RemoveRootEP12YYObjectBase> */
/* @0xd62b8 cmp r9, r6 */
/* @0xd62bc bne 0xd62a4 <_Z15MarkAndSweepGeniib+0x6fc> */
/* @0xd62c0 mov r0, r5 */
/* @0xd62c4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd62c8 ldr r3, [r11, #0x28] */
/* @0xd62cc add r3, r3, #1 */
/* @0xd62d0 str r3, [r11, #0x28] */
/* @0xd62d4 ldr r2, [sp, #0x10] */
/* @0xd62d8 add r4, r4, #1 */
/* @0xd62dc add r7, r7, #4 */
/* @0xd62e0 cmp r4, r2 */
/* @0xd62e4 bne 0xd6270 <_Z15MarkAndSweepGeniib+0x6c8> */
/* @0xd62e8 ldr r12, [sp, #0x14] */
/* @0xd62ec subs r6, r12, #2 */
/* @0xd62f0 bmi 0xd63f0 <_Z15MarkAndSweepGeniib+0x848> */
/* @0xd62f4 ldr r12, [sp, #0x14] */
/* @0xd62f8 mov r7, #88 */
/* @0xd62fc ldr r9, [pc, #0x3d4] */
/* @0xd6300 mov r5, #0 */
/* @0xd6304 sub r3, r12, #1 */
/* @0xd6308 ldr r12, [sp, #0x18] */
/* @0xd630c add r9, pc, r9 */
/* @0xd6310 vldr s16, [pc, #876] */
/* @0xd6314 mla r7, r7, r3, r12 */
/* @0xd6318 ldr r8, [r7, #-0x58] */
/* @0xd631c mov r4, #0 */
/* @0xd6320 ldr lr, [r8] */
/* @0xd6324 ldr r0, [r8, #0x10] */
/* @0xd6328 add r3, r4, r4, lsl #1 */
/* @0xd632c add r3, r0, r3, lsl #2 */
/* @0xd6330 b 0xd6340 <_Z15MarkAndSweepGeniib+0x798> */
/* @0xd6334 ldr r1, [r2, #0x8] */
/* @0xd6338 cmp r1, #0 */
/* @0xd633c bgt 0xd6590 <_Z15MarkAndSweepGeniib+0x9e8> */
/* @0xd6340 add r4, r4, #1 */
/* @0xd6344 mov r2, r3 */
/* @0xd6348 cmp r4, lr */
/* @0xd634c add r3, r3, #12 */
/* @0xd6350 ble 0xd6334 <_Z15MarkAndSweepGeniib+0x78c> */
/* @0xd6354 cmp r0, #0 */
/* @0xd6358 beq 0xd6360 <_Z15MarkAndSweepGeniib+0x7b8> */
/* @0xd635c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd6360 str r5, [r8, #0x10] */
/* @0xd6364 mov r1, r9 */
/* @0xd6368 ldr r4, [r7, #-0x58] */
/* @0xd636c mov r2, #70 */
/* @0xd6370 mov r3, #1 */
/* @0xd6374 ldr r0, [r4] */
/* @0xd6378 sub r12, r0, #1 */
/* @0xd637c str r12, [r4, #0x8] */
/* @0xd6380 add r0, r0, r0, lsl #1 */
/* @0xd6384 lsl r8, r0, #2 */
/* @0xd6388 mov r0, r8 */
/* @0xd638c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd6390 mov r2, r8 */
/* @0xd6394 mov r1, #0 */
/* @0xd6398 str r0, [r4, #0x10] */
/* @0xd639c bl 0xb65b0 <memset@plt> */
/* @0xd63a0 ldr r2, [r4] */
/* @0xd63a4 str r5, [r4, #0x4] */
/* @0xd63a8 cmp r2, #0 */
/* @0xd63ac vmov s13, r2 */
/* @0xd63b0 vcvt.f32.s32 s15, s13 */
/* @0xd63b4 vmul.f32 s15, s15, s16 */
/* @0xd63b8 vcvt.s32.f32 s15, s15 */
/* @0xd63bc vstr s15, [r4, #12] */
/* @0xd63c0 ble 0xd63e0 <_Z15MarkAndSweepGeniib+0x838> */
/* @0xd63c4 ldr r3, [r4, #0x10] */
/* @0xd63c8 add r2, r2, r2, lsl #1 */
/* @0xd63cc add r2, r3, r2, lsl #2 */
/* @0xd63d0 str r5, [r3, #0x8] */
/* @0xd63d4 add r3, r3, #12 */
/* @0xd63d8 cmp r3, r2 */
/* @0xd63dc bne 0xd63d0 <_Z15MarkAndSweepGeniib+0x828> */
/* @0xd63e0 sub r6, r6, #1 */
/* @0xd63e4 sub r7, r7, #88 */
/* @0xd63e8 cmn r6, #1 */
/* @0xd63ec bne 0xd6318 <_Z15MarkAndSweepGeniib+0x770> */
/* @0xd63f0 ldr r12, [sp, #0x14] */
/* @0xd63f4 cmp r12, #1 */
/* @0xd63f8 ble 0xd64bc <_Z15MarkAndSweepGeniib+0x914> */
/* @0xd63fc ldr r12, [sp, #0x30] */
/* @0xd6400 mvn r3, #-2147483648 */
/* @0xd6404 mvn r4, #0 */
/* @0xd6408 cmp r12, #0 */
/* @0xd640c ldr r12, [sp, #0x18] */
/* @0xd6410 str r3, [r12, #0x14] */
/* @0xd6414 str r3, [r12, #0x6c] */
/* @0xd6418 str r3, [r12, #0xc4] */
/* @0xd641c str r3, [r12, #0x11c] */
/* @0xd6420 str r4, [r12, #0x18] */
/* @0xd6424 str r4, [r12, #0x70] */
/* @0xd6428 str r4, [r12, #0xc8] */
/* @0xd642c str r4, [r12, #0x120] */
/* @0xd6430 ble 0xd64bc <_Z15MarkAndSweepGeniib+0x914> */
/* @0xd6434 ldr r6, [sp, #0x44] */
/* @0xd6438 mov r5, #0 */
/* @0xd643c ldr r12, [sp, #0x14] */
/* @0xd6440 mov r8, #88 */
/* @0xd6444 ldr r9, [sp, #0x30] */
/* @0xd6448 mov r10, r6 */
/* @0xd644c add r7, r12, r4 */
/* @0xd6450 mov r6, r5 */
/* @0xd6454 mov r5, r10 */
/* @0xd6458 ldr lr, [r5], #4 */
/* @0xd645c cmp lr, #0 */
/* @0xd6460 beq 0xd64b0 <_Z15MarkAndSweepGeniib+0x908> */
/* @0xd6464 ldr r3, [lr, #0x38] */
/* @0xd6468 cmp r3, r7 */
/* @0xd646c addlt r3, r3, #1 */
/* @0xd6470 strlt r3, [lr, #0x38] */
/* @0xd6474 add r3, r10, r4, lsl #2 */
/* @0xd6478 b 0xd648c <_Z15MarkAndSweepGeniib+0x8e4> */
/* @0xd647c ldr r0, [r3, #0x4] */
/* @0xd6480 mov r3, r2 */
/* @0xd6484 cmp r0, #0 */
/* @0xd6488 beq 0xd6600 <_Z15MarkAndSweepGeniib+0xa58> */
/* @0xd648c add r4, r4, #1 */
/* @0xd6490 add r2, r3, #4 */
/* @0xd6494 cmp r6, r4 */
/* @0xd6498 bgt 0xd647c <_Z15MarkAndSweepGeniib+0x8d4> */
/* @0xd649c mov r1, r6 */
/* @0xd64a0 ldr r0, [lr, #0x38] */
/* @0xd64a4 ldr r12, [sp, #0x18] */
/* @0xd64a8 mla r0, r8, r0, r12 */
/* @0xd64ac bl 0x19150c <_ZN13CGCGeneration11UpdateRangeEi> */
/* @0xd64b0 add r6, r6, #1 */
/* @0xd64b4 cmp r6, r9 */
/* @0xd64b8 bne 0xd6458 <_Z15MarkAndSweepGeniib+0x8b0> */
/* @0xd64bc ldr r0, [r11, #0x1c] */
/* @0xd64c0 cmn r0, #1 */
/* @0xd64c4 beq 0xd6628 <_Z15MarkAndSweepGeniib+0xa80> */
/* @0xd64c8 ldr r12, [sp, #0x48] */
/* @0xd64cc add r3, r0, #1 */
/* @0xd64d0 cmp r3, r12 */
/* @0xd64d4 bge 0xd661c <_Z15MarkAndSweepGeniib+0xa74> */
/* @0xd64d8 ldr r12, [sp, #0x14] */
/* @0xd64dc add r2, r12, #1 */
/* @0xd64e0 cmp r2, #4 */
/* @0xd64e4 str r12, [r11, #0x38] */
/* @0xd64e8 beq 0xd661c <_Z15MarkAndSweepGeniib+0xa74> */
/* @0xd64ec ldr r12, [sp, #0x4c] */
/* @0xd64f0 ldr r1, [pc, #0x1e4] */
/* @0xd64f4 ldr r3, [r12] */
/* @0xd64f8 ldr r12, [sp, #0x1c] */
/* @0xd64fc cmp r3, #0 */
/* @0xd6500 ldr r1, [r12, r1] */
/* @0xd6504 ldr r4, [r1] */
/* @0xd6508 ble 0xd6640 <_Z15MarkAndSweepGeniib+0xa98> */
/* @0xd650c ldr r1, [sp, #0x18] */
/* @0xd6510 add r12, r1, #264 */
/* @0xd6514 mov r1, r11 */
/* @0xd6518 ldr lr, [r1, #0x74] */
/* @0xd651c add r1, r1, #88 */
/* @0xd6520 cmp r0, lr */
/* @0xd6524 bge 0xd6550 <_Z15MarkAndSweepGeniib+0x9a8> */
/* @0xd6528 vldr s13, [r11, #40] */
/* @0xd652c vcvt.f32.s32 s14, s13 */
/* @0xd6530 vmov s13, r3 */
/* @0xd6534 ldr lr, [r11, #0x34] */
/* @0xd6538 str r3, [r11, #0x20] */
/* @0xd653c str r2, [r11, #0x38] */
/* @0xd6540 str lr, [r11, #0x30] */
/* @0xd6544 vcvt.f32.s32 s15, s13 */
/* @0xd6548 vdiv.f32 s15, s14, s15 */
/* @0xd654c vstr s15, [r11, #44] */
/* @0xd6550 cmp r1, r12 */
/* @0xd6554 add r2, r2, #1 */
/* @0xd6558 bne 0xd6518 <_Z15MarkAndSweepGeniib+0x970> */
/* @0xd655c ldr r12, [sp, #0x40] */
/* @0xd6560 str r3, [r11, #0x24] */
/* @0xd6564 str r12, [r11, #0x34] */
/* @0xd6568 ldr r12, [sp, #0x48] */
/* @0xd656c str r12, [r11, #0x1c] */
/* @0xd6570 bl 0x215148 <Timing_Time> */
/* @0xd6574 ldrd r2, r3, [sp, #80] */
/* @0xd6578 subs r0, r0, r2 */
/* @0xd657c sbc r1, r1, r3 */
/* @0xd6580 strd r0, r1, [r11, #64] */
/* @0xd6584 add sp, sp, #116 */
/* @0xd6588 vpop {d8} */
/* @0xd658c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd6590 ldr r1, [r2, #0x4] */
/* @0xd6594 cmp r1, #0 */
/* @0xd6598 beq 0xd6328 <_Z15MarkAndSweepGeniib+0x780> */
/* @0xd659c mov r0, r7 */
/* @0xd65a0 bl 0x196210 <_ZN13CGCGeneration7AddRootEP12YYObjectBase> */
/* @0xd65a4 ldr r8, [r7, #-0x58] */
/* @0xd65a8 ldr lr, [r8] */
/* @0xd65ac ldr r0, [r8, #0x10] */
/* @0xd65b0 b 0xd6328 <_Z15MarkAndSweepGeniib+0x780> */
/* @0xd65b4 ldr r0, [r2, #0x4] */
/* @0xd65b8 ldr r3, [pc, #0x10c] */
/* @0xd65bc ldr r12, [sp, #0x14] */
/* @0xd65c0 ldr r2, [r0, #0x38] */
/* @0xd65c4 ldr r3, [r8, r3] */
/* @0xd65c8 cmp r2, r12 */
/* @0xd65cc strb r5, [r3] */
/* @0xd65d0 bne 0xd65f0 <_Z15MarkAndSweepGeniib+0xa48> */
/* @0xd65d4 ldr r2, [r6] */
/* @0xd65d8 ldr r3, [r0, #0x3c] */
/* @0xd65dc ldr r12, [sp, #0x40] */
/* @0xd65e0 rsb r3, r3, r2 */
/* @0xd65e4 cmp r12, r3 */
/* @0xd65e8 movlo r12, r3 */
/* @0xd65ec str r12, [sp, #0x40] */
/* @0xd65f0 ldr r1, [r4] */
/* @0xd65f4 ldr r2, [sp, #0x30] */
/* @0xd65f8 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd65fc b 0xd5f84 <_Z15MarkAndSweepGeniib+0x3dc> */
/* @0xd6600 ldr r3, [r5, #-0x4] */
/* @0xd6604 mov r1, r4 */
/* @0xd6608 str r3, [r2] */
/* @0xd660c str r0, [r5, #-0x4] */
/* @0xd6610 ldr lr, [r2] */
/* @0xd6614 str r4, [lr, #0x44] */
/* @0xd6618 b 0xd64a0 <_Z15MarkAndSweepGeniib+0x8f8> */
/* @0xd661c ldr r12, [sp, #0x4c] */
/* @0xd6620 ldr r3, [r12] */
/* @0xd6624 b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd6628 ldr r12, [sp, #0x4c] */
/* @0xd662c ldr r3, [r12] */
/* @0xd6630 ldr r12, [sp, #0x14] */
/* @0xd6634 str r3, [r11, #0x20] */
/* @0xd6638 str r12, [r11, #0x38] */
/* @0xd663c b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd6640 ldr lr, [sp, #0x18] */
/* @0xd6644 mov r1, r11 */
/* @0xd6648 add r12, lr, #264 */
/* @0xd664c ldr lr, [r1, #0x74] */
/* @0xd6650 add r1, r1, #88 */
/* @0xd6654 cmp r0, lr */
/* @0xd6658 strlt r2, [r11, #0x38] */
/* @0xd665c strlt r4, [r11, #0x2c] */
/* @0xd6660 add r2, r2, #1 */
/* @0xd6664 ldrlt lr, [r11, #0x34] */
/* @0xd6668 strlt r3, [r11, #0x20] */
/* @0xd666c strlt lr, [r11, #0x30] */
/* @0xd6670 cmp r1, r12 */
/* @0xd6674 bne 0xd664c <_Z15MarkAndSweepGeniib+0xaa4> */
/* @0xd6678 b 0xd655c <_Z15MarkAndSweepGeniib+0x9b4> */
/* @0xd667c mov r4, r7 */
/* @0xd6680 b 0xd6210 <_Z15MarkAndSweepGeniib+0x668> */
/* @0xd6684 svclo #0x19999a */
/* @0xd6688 mlaseq r1, r8, r0, r12 */
/* @0xd668c .word 0xffffbf68 */
/* @0xd6690 .word 0xffffbffc */
/* @0xd6694 .word 0xffffc010 */
/* @0xd6698 .word 0xffffc014 */
/* @0xd669c .word 0xffffc018 */
/* @0xd66a0 .word 0xffffc01c */
/* @0xd66a4 eoreq r11, r5, r12, lsr #7 */
/* @0xd66a8 .word 0xffffbcd8 */
/* @0xd66ac .word 0xffffc020 */
/* @0xd66b0 .word 0xffffc024 */
/* @0xd66b4 .word 0xffffc028 */
/* @0xd66b8 .word 0xffffbcec */
/* @0xd66bc .word 0xffffc02c */
/* @0xd66c0 .word 0xffffc030 */
/* @0xd66c4 .word 0xffffc034 */
/* @0xd66c8 .word 0xffffc038 */
/* @0xd66cc .word 0xffffc03c */
/* @0xd66d0 eoreq r12, r5, r8, lsl #20 */
/* @0xd66d4 .word 0xffffbac4 */
/* @0xd66d8 eoreq r10, r5, r4, lsr #26 */
/* @0xd66dc .word 0xffffc040 */

/* ── FUNC 0xd66e0 · ResetGC() · size=124 · insn=31 */
/* @0xd66e0 ldr r3, [pc, #0x60] */
/* @0xd66e4 ldr r2, [pc, #0x60] */
/* @0xd66e8 add r3, pc, r3 */
/* @0xd66ec push {r4, lr} */
/* @0xd66f0 ldr r2, [r3, r2] */
/* @0xd66f4 ldrb r2, [r2] */
/* @0xd66f8 cmp r2, #0 */
/* @0xd66fc popeq {r4, pc} */
/* @0xd6700 ldr r12, [pc, #0x48] */
/* @0xd6704 mov r2, #0 */
/* @0xd6708 ldr r0, [pc, #0x44] */
/* @0xd670c ldr r1, [pc, #0x44] */
/* @0xd6710 ldr r12, [r3, r12] */
/* @0xd6714 str r2, [r12] */
/* @0xd6718 ldr r0, [r3, r0] */
/* @0xd671c str r2, [r0] */
/* @0xd6720 ldr r4, [r3, r1] */
/* @0xd6724 mov r0, r4 */
/* @0xd6728 bl 0x19140c <_ZN13CGCGeneration5ResetEv> */
/* @0xd672c add r0, r4, #88 */
/* @0xd6730 bl 0x19140c <_ZN13CGCGeneration5ResetEv> */
/* @0xd6734 add r0, r4, #176 */
/* @0xd6738 bl 0x19140c <_ZN13CGCGeneration5ResetEv> */
/* @0xd673c add r0, r4, #264 */
/* @0xd6740 pop {r4, lr} */
/* @0xd6744 b 0x19140c <_ZN13CGCGeneration5ResetEv> */
/* @0xd6748 eorseq r11, r1, r8, ror #10 */
/* @0xd674c .word 0xffffbf68 */
/* @0xd6750 .word 0xffffc044 */
/* @0xd6754 .word 0xffffc048 */
/* @0xd6758 .word 0xffffc010 */

/* ── FUNC 0xd675c · FreeAllObjects() · size=244 · insn=61 */
/* @0xd675c push {r4, r5, r6, r7, r8, lr} */
/* @0xd6760 ldr r7, [pc, #0xc4] */
/* @0xd6764 ldr r3, [pc, #0xc4] */
/* @0xd6768 add r7, pc, r7 */
/* @0xd676c ldr r3, [r7, r3] */
/* @0xd6770 ldrb r3, [r3] */
/* @0xd6774 cmp r3, #0 */
/* @0xd6778 popeq {r4, r5, r6, r7, r8, pc} */
/* @0xd677c ldr r1, [pc, #0xb0] */
/* @0xd6780 mov r2, #0 */
/* @0xd6784 ldr r3, [pc, #0xac] */
/* @0xd6788 ldr r8, [r7, r1] */
/* @0xd678c strb r2, [r8] */
/* @0xd6790 ldr r5, [r7, r3] */
/* @0xd6794 ldr r3, [r5, #0x8] */
/* @0xd6798 cmp r3, #0 */
/* @0xd679c ble 0xd67dc <_Z14FreeAllObjectsv+0x80> */
/* @0xd67a0 ldr r6, [r5, #0x4] */
/* @0xd67a4 cmp r6, #0 */
/* @0xd67a8 ble 0xd6798 <_Z14FreeAllObjectsv+0x3c> */
/* @0xd67ac mov r4, #0 */
/* @0xd67b0 ldr r3, [r5] */
/* @0xd67b4 ldr r0, [r3, r4, lsl #2] */
/* @0xd67b8 add r4, r4, #1 */
/* @0xd67bc cmp r0, #0 */
/* @0xd67c0 beq 0xd67c8 <_Z14FreeAllObjectsv+0x6c> */
/* @0xd67c4 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd67c8 cmp r4, r6 */
/* @0xd67cc bne 0xd67b0 <_Z14FreeAllObjectsv+0x54> */
/* @0xd67d0 ldr r3, [r5, #0x8] */
/* @0xd67d4 cmp r3, #0 */
/* @0xd67d8 bgt 0xd67a0 <_Z14FreeAllObjectsv+0x44> */
/* @0xd67dc ldr r0, [pc, #0x58] */
/* @0xd67e0 mov r3, #0 */
/* @0xd67e4 ldr r5, [pc, #0x54] */
/* @0xd67e8 mvn r2, #0 */
/* @0xd67ec ldr r4, [pc, #0x50] */
/* @0xd67f0 mov r1, #1 */
/* @0xd67f4 ldr r6, [r7, r0] */
/* @0xd67f8 ldr r12, [pc, #0x48] */
/* @0xd67fc ldr r0, [pc, #0x48] */
/* @0xd6800 str r3, [r6] */
/* @0xd6804 ldr r5, [r7, r5] */
/* @0xd6808 str r3, [r5] */
/* @0xd680c ldr r4, [r7, r4] */
/* @0xd6810 str r3, [r4] */
/* @0xd6814 ldr r12, [r7, r12] */
/* @0xd6818 str r3, [r12] */
/* @0xd681c ldr r3, [r7, r0] */
/* @0xd6820 strb r1, [r8] */
/* @0xd6824 str r2, [r3] */
/* @0xd6828 pop {r4, r5, r6, r7, r8, pc} */
/* @0xd682c eorseq r11, r1, r8, ror #9 */
/* @0xd6830 .word 0xffffbf68 */
/* @0xd6834 .word 0xffffc04c */
/* @0xd6838 .word 0xffffc014 */
/* @0xd683c .word 0xffffbf64 */
/* @0xd6840 .word 0xffffc050 */
/* @0xd6844 .word 0xffffc054 */
/* @0xd6848 .word 0xffffc058 */
/* @0xd684c .word 0xffffc05c */

/* ── FUNC 0xd6850 · DoGenerationalGC() · size=604 · insn=151 */
/* @0xd6850 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd6854 vpush {d8} */
/* @0xd6858 ldr r6, [pc, #0x220] */
/* @0xd685c ldr r3, [pc, #0x220] */
/* @0xd6860 add r6, pc, r6 */
/* @0xd6864 ldr r3, [r6, r3] */
/* @0xd6868 ldrb r3, [r3] */
/* @0xd686c cmp r3, #0 */
/* @0xd6870 bne 0xd687c <_Z16DoGenerationalGCv+0x2c> */
/* @0xd6874 vpop {d8} */
/* @0xd6878 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd687c ldr r3, [pc, #0x204] */
/* @0xd6880 mov r2, #1 */
/* @0xd6884 ldr r1, [pc, #0x200] */
/* @0xd6888 mov r11, #88 */
/* @0xd688c ldr r8, [r6, r3] */
/* @0xd6890 ldr r7, [r6, r1] */
/* @0xd6894 ldr r1, [r8] */
/* @0xd6898 ldr r0, [r7] */
/* @0xd689c bl 0xd5ba8 <_Z15MarkAndSweepGeniib> */
/* @0xd68a0 ldr r3, [pc, #0x1e8] */
/* @0xd68a4 ldr r9, [r7] */
/* @0xd68a8 ldr r10, [r6, r3] */
/* @0xd68ac mla r11, r11, r9, r10 */
/* @0xd68b0 ldr r3, [r11, #0x20] */
/* @0xd68b4 cmp r3, #0 */
/* @0xd68b8 beq 0xd69a4 <_Z16DoGenerationalGCv+0x154> */
/* @0xd68bc ldr r1, [pc, #0x1d0] */
/* @0xd68c0 ldr r2, [r11, #0x24] */
/* @0xd68c4 ldr r1, [r6, r1] */
/* @0xd68c8 ldr r1, [r1] */
/* @0xd68cc cmp r2, r1 */
/* @0xd68d0 ble 0xd69a4 <_Z16DoGenerationalGCv+0x154> */
/* @0xd68d4 vmov s14, r3 */
/* @0xd68d8 vmov s12, r2 */
/* @0xd68dc vcvt.f32.s32 s13, s14 */
/* @0xd68e0 vcvt.f32.s32 s15, s12 */
/* @0xd68e4 vdiv.f32 s13, s15, s13 */
/* @0xd68e8 vmov.f32 s14, #2.000000e+00 */
/* @0xd68ec vcmpe.f32 s13, s14 */
/* @0xd68f0 vmrs APSR_nzcv, fpscr */
/* @0xd68f4 bgt 0xd69c0 <_Z16DoGenerationalGCv+0x170> */
/* @0xd68f8 cmp r2, #0 */
/* @0xd68fc ble 0xd6968 <_Z16DoGenerationalGCv+0x118> */
/* @0xd6900 vldr s14, [r11, #44] */
/* @0xd6904 vcmpe.f32 s14, #0 */
/* @0xd6908 ldr r3, [r11, #0x28] */
/* @0xd690c vmrs APSR_nzcv, fpscr */
/* @0xd6910 ble 0xd6968 <_Z16DoGenerationalGCv+0x118> */
/* @0xd6914 vmov s13, r3 */
/* @0xd6918 ldr r3, [pc, #0x178] */
/* @0xd691c vcvt.f32.s32 s12, s13 */
/* @0xd6920 ldr r3, [r6, r3] */
/* @0xd6924 vldr s13, [r3] */
/* @0xd6928 vdiv.f32 s15, s12, s15 */
/* @0xd692c vcmpe.f32 s15, s13 */
/* @0xd6930 vmrs APSR_nzcv, fpscr */
/* @0xd6934 bpl 0xd6a60 <_Z16DoGenerationalGCv+0x210> */
/* @0xd6938 vdiv.f32 s15, s15, s14 */
/* @0xd693c ldr r2, [pc, #0x158] */
/* @0xd6940 ldr r3, [pc, #0x158] */
/* @0xd6944 ldr r2, [r6, r2] */
/* @0xd6948 vldr s12, [r2] */
/* @0xd694c ldr r3, [r6, r3] */
/* @0xd6950 vldr s13, [r3] */
/* @0xd6954 vmul.f32 s14, s14, s12 */
/* @0xd6958 vcmpe.f32 s15, s13 */
/* @0xd695c vstr s14, [r11, #44] */
/* @0xd6960 vmrs APSR_nzcv, fpscr */
/* @0xd6964 bmi 0xd69c0 <_Z16DoGenerationalGCv+0x170> */
/* @0xd6968 cmp r9, #1 */
/* @0xd696c movne r3, #0 */
/* @0xd6970 beq 0xd69c8 <_Z16DoGenerationalGCv+0x178> */
/* @0xd6974 cmp r9, #1 */
/* @0xd6978 ble 0xd6a1c <_Z16DoGenerationalGCv+0x1cc> */
/* @0xd697c cmp r3, #0 */
/* @0xd6980 ble 0xd69a4 <_Z16DoGenerationalGCv+0x154> */
/* @0xd6984 add r9, r3, r9 */
/* @0xd6988 cmp r9, #3 */
/* @0xd698c strle r9, [r7] */
/* @0xd6990 ldrgt r3, [r10, #0x12c] */
/* @0xd6994 movgt r2, #0 */
/* @0xd6998 strgt r2, [r7] */
/* @0xd699c strgt r3, [r10, #0x128] */
/* @0xd69a0 b 0xd69ac <_Z16DoGenerationalGCv+0x15c> */
/* @0xd69a4 mov r3, #0 */
/* @0xd69a8 str r3, [r7] */
/* @0xd69ac vpop {d8} */
/* @0xd69b0 ldr r3, [r8] */
/* @0xd69b4 add r3, r3, #1 */
/* @0xd69b8 str r3, [r8] */
/* @0xd69bc pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd69c0 mov r3, #1 */
/* @0xd69c4 b 0xd6974 <_Z16DoGenerationalGCv+0x124> */
/* @0xd69c8 ldrd r4, r5, [r10, #64] */
/* @0xd69cc cmp r4, #1 */
/* @0xd69d0 sbcs r3, r5, #0 */
/* @0xd69d4 movlt r3, #0 */
/* @0xd69d8 blt 0xd6a1c <_Z16DoGenerationalGCv+0x1cc> */
/* @0xd69dc ldrd r0, r1, [r11, #64] */
/* @0xd69e0 bl 0x319164 <__floatdidf> */
/* @0xd69e4 vmov d8, r0, r1 */
/* @0xd69e8 mov r0, r4 */
/* @0xd69ec mov r1, r5 */
/* @0xd69f0 bl 0x319164 <__floatdidf> */
/* @0xd69f4 ldr r3, [pc, #0xa8] */
/* @0xd69f8 ldr r3, [r6, r3] */
/* @0xd69fc vldr s15, [r3] */
/* @0xd6a00 vmov d6, r0, r1 */
/* @0xd6a04 vdiv.f64 d8, d8, d6 */
/* @0xd6a08 vcvt.f32.f64 s16, d8 */
/* @0xd6a0c vcmpe.f32 s16, s15 */
/* @0xd6a10 vmrs APSR_nzcv, fpscr */
/* @0xd6a14 movle r3, #0 */
/* @0xd6a18 movgt r3, #1 */
/* @0xd6a1c ldr r1, [pc, #0x84] */
/* @0xd6a20 ldr r2, [r11, #0x34] */
/* @0xd6a24 ldr r1, [r6, r1] */
/* @0xd6a28 ldr r1, [r1] */
/* @0xd6a2c cmp r2, r1 */
/* @0xd6a30 ble 0xd697c <_Z16DoGenerationalGCv+0x12c> */
/* @0xd6a34 ldr r3, [r11, #0x38] */
/* @0xd6a38 cmp r9, r3 */
/* @0xd6a3c bge 0xd6a78 <_Z16DoGenerationalGCv+0x228> */
/* @0xd6a40 ldr r1, [r11, #0x30] */
/* @0xd6a44 cmp r2, r1 */
/* @0xd6a48 blt 0xd6a78 <_Z16DoGenerationalGCv+0x228> */
/* @0xd6a4c rsb r3, r9, r3 */
/* @0xd6a50 add r3, r3, #1 */
/* @0xd6a54 cmp r3, #2 */
/* @0xd6a58 movge r3, #2 */
/* @0xd6a5c b 0xd697c <_Z16DoGenerationalGCv+0x12c> */
/* @0xd6a60 ldr r3, [pc, #0x34] */
/* @0xd6a64 ldr r3, [r6, r3] */
/* @0xd6a68 vldr s15, [r3] */
/* @0xd6a6c vmul.f32 s14, s14, s15 */
/* @0xd6a70 vstr s14, [r11, #44] */
/* @0xd6a74 b 0xd6968 <_Z16DoGenerationalGCv+0x118> */
/* @0xd6a78 mov r3, #1 */
/* @0xd6a7c b 0xd6984 <_Z16DoGenerationalGCv+0x134> */
/* @0xd6a80 ldrshteq r11, [r1], -r0 */
/* @0xd6a84 .word 0xffffbf68 */
/* @0xd6a88 .word 0xffffc048 */
/* @0xd6a8c .word 0xffffc044 */
/* @0xd6a90 .word 0xffffc010 */
/* @0xd6a94 .word 0xffffc060 */
/* @0xd6a98 .word 0xffffc064 */
/* @0xd6a9c .word 0xffffc068 */
/* @0xd6aa0 .word 0xffffc06c */
/* @0xd6aa4 .word 0xffffc070 */
/* @0xd6aa8 .word 0xffffc074 */

/* ── FUNC 0xd6aac · MarkAndSweep(YYObjectBase*) · size=1344 · insn=336 */
/* @0xd6aac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd6ab0 mov r8, r0 */
/* @0xd6ab4 ldr r7, [pc, #0x4f0] */
/* @0xd6ab8 sub sp, sp, #52 */
/* @0xd6abc ldr r3, [pc, #0x4ec] */
/* @0xd6ac0 add r7, pc, r7 */
/* @0xd6ac4 ldr r3, [r7, r3] */
/* @0xd6ac8 ldrb r4, [r3] */
/* @0xd6acc cmp r4, #0 */
/* @0xd6ad0 bne 0xd6ae0 <_Z12MarkAndSweepP12YYObjectBase+0x34> */
/* @0xd6ad4 mov r0, r4 */
/* @0xd6ad8 add sp, sp, #52 */
/* @0xd6adc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd6ae0 ldr r0, [pc, #0x4cc] */
/* @0xd6ae4 mov r3, #1 */
/* @0xd6ae8 ldr r12, [pc, #0x4c8] */
/* @0xd6aec movw r2, #0x777 */
/* @0xd6af0 ldr r1, [pc, #0x4c4] */
/* @0xd6af4 ldr r0, [r7, r0] */
/* @0xd6af8 add r1, pc, r1 */
/* @0xd6afc ldr lr, [r0] */
/* @0xd6b00 add lr, lr, r3 */
/* @0xd6b04 str lr, [r0] */
/* @0xd6b08 ldr r0, [r7, r12] */
/* @0xd6b0c ldr r4, [r0, #0x4] */
/* @0xd6b10 str r0, [sp] */
/* @0xd6b14 adds r11, r4, #31 */
/* @0xd6b18 addmi r11, r4, #62 */
/* @0xd6b1c asr r11, r11, #5 */
/* @0xd6b20 lsl r11, r11, #2 */
/* @0xd6b24 str r11, [sp, #0x4] */
/* @0xd6b28 mov r0, r11 */
/* @0xd6b2c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd6b30 ldr r3, [pc, #0x488] */
/* @0xd6b34 mov r2, r4 */
/* @0xd6b38 ldr r3, [r7, r3] */
/* @0xd6b3c mov r1, r0 */
/* @0xd6b40 mov r5, r0 */
/* @0xd6b44 ldr r0, [r3] */
/* @0xd6b48 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd6b4c ldr r3, [pc, #0x470] */
/* @0xd6b50 ldr r6, [r7, r3] */
/* @0xd6b54 ldr r3, [r6] */
/* @0xd6b58 cmp r3, #0 */
/* @0xd6b5c beq 0xd6db0 <_Z12MarkAndSweepP12YYObjectBase+0x304> */
/* @0xd6b60 ldr r0, [r3, #0x80] */
/* @0xd6b64 cmp r0, #0 */
/* @0xd6b68 beq 0xd6b8c <_Z12MarkAndSweepP12YYObjectBase+0xe0> */
/* @0xd6b6c ldr r9, [r0, #0x178] */
/* @0xd6b70 mov r1, r5 */
/* @0xd6b74 mov r2, r4 */
/* @0xd6b78 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd6b7c cmp r9, #0 */
/* @0xd6b80 mov r0, r9 */
/* @0xd6b84 bne 0xd6b6c <_Z12MarkAndSweepP12YYObjectBase+0xc0> */
/* @0xd6b88 ldr r3, [r6] */
/* @0xd6b8c ldr r0, [r3, #0x8c] */
/* @0xd6b90 cmp r0, #0 */
/* @0xd6b94 beq 0xd6bb4 <_Z12MarkAndSweepP12YYObjectBase+0x108> */
/* @0xd6b98 ldr r6, [r0, #0x178] */
/* @0xd6b9c mov r1, r5 */
/* @0xd6ba0 mov r2, r4 */
/* @0xd6ba4 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd6ba8 cmp r6, #0 */
/* @0xd6bac mov r0, r6 */
/* @0xd6bb0 bne 0xd6b98 <_Z12MarkAndSweepP12YYObjectBase+0xec> */
/* @0xd6bb4 ldr r3, [pc, #0x40c] */
/* @0xd6bb8 ldr r3, [r7, r3] */
/* @0xd6bbc ldr r0, [r3] */
/* @0xd6bc0 cmp r0, #0 */
/* @0xd6bc4 beq 0xd6bd4 <_Z12MarkAndSweepP12YYObjectBase+0x128> */
/* @0xd6bc8 mov r1, r5 */
/* @0xd6bcc mov r2, r4 */
/* @0xd6bd0 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd6bd4 ldr r3, [pc, #0x3f0] */
/* @0xd6bd8 ldr r3, [r7, r3] */
/* @0xd6bdc ldr r0, [r3, #0x8] */
/* @0xd6be0 cmp r0, #0 */
/* @0xd6be4 beq 0xd6bf4 <_Z12MarkAndSweepP12YYObjectBase+0x148> */
/* @0xd6be8 mov r1, r5 */
/* @0xd6bec mov r2, r4 */
/* @0xd6bf0 bl 0x191bdc <_ZN12YYObjectBase7Mark4GCEPji> */
/* @0xd6bf4 add r10, sp, #28 */
/* @0xd6bf8 mov r0, r10 */
/* @0xd6bfc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xd6c00 ldr r3, [pc, #0x3c8] */
/* @0xd6c04 ldr r11, [r7, r3] */
/* @0xd6c08 ldr r2, [r11] */
/* @0xd6c0c cmp r2, #0 */
/* @0xd6c10 ble 0xd6c4c <_Z12MarkAndSweepP12YYObjectBase+0x1a0> */
/* @0xd6c14 ldr r2, [pc, #0x3b8] */
/* @0xd6c18 mov r6, #0 */
/* @0xd6c1c ldr r9, [r7, r2] */
/* @0xd6c20 ldr r3, [r9, #0x4] */
/* @0xd6c24 mov r1, r5 */
/* @0xd6c28 mov r2, r4 */
/* @0xd6c2c ldr r0, [r3, r6, lsl #2] */
/* @0xd6c30 add r6, r6, #1 */
/* @0xd6c34 cmp r0, #0 */
/* @0xd6c38 beq 0xd6c40 <_Z12MarkAndSweepP12YYObjectBase+0x194> */
/* @0xd6c3c bl 0x2036e4 <_ZN7CDS_Map7Mark4GCEPji> */
/* @0xd6c40 ldr r3, [r11] */
/* @0xd6c44 cmp r3, r6 */
/* @0xd6c48 bgt 0xd6c20 <_Z12MarkAndSweepP12YYObjectBase+0x174> */
/* @0xd6c4c ldr r3, [pc, #0x384] */
/* @0xd6c50 ldr r11, [r7, r3] */
/* @0xd6c54 ldr r2, [r11] */
/* @0xd6c58 cmp r2, #0 */
/* @0xd6c5c ble 0xd6c98 <_Z12MarkAndSweepP12YYObjectBase+0x1ec> */
/* @0xd6c60 ldr r2, [pc, #0x374] */
/* @0xd6c64 mov r6, #0 */
/* @0xd6c68 ldr r9, [r7, r2] */
/* @0xd6c6c ldr r3, [r9, #0x4] */
/* @0xd6c70 mov r1, r5 */
/* @0xd6c74 mov r2, r4 */
/* @0xd6c78 ldr r0, [r3, r6, lsl #2] */
/* @0xd6c7c add r6, r6, #1 */
/* @0xd6c80 cmp r0, #0 */
/* @0xd6c84 beq 0xd6c8c <_Z12MarkAndSweepP12YYObjectBase+0x1e0> */
/* @0xd6c88 bl 0x2030ac <_ZN8CDS_List7Mark4GCEPji> */
/* @0xd6c8c ldr r3, [r11] */
/* @0xd6c90 cmp r3, r6 */
/* @0xd6c94 bgt 0xd6c6c <_Z12MarkAndSweepP12YYObjectBase+0x1c0> */
/* @0xd6c98 add r0, sp, #32 */
/* @0xd6c9c bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xd6ca0 ldr r12, [sp, #0x20] */
/* @0xd6ca4 cmp r12, #0 */
/* @0xd6ca8 movgt r6, #0 */
/* @0xd6cac subgt r9, r0, #4 */
/* @0xd6cb0 ble 0xd6cdc <_Z12MarkAndSweepP12YYObjectBase+0x230> */
/* @0xd6cb4 ldr r0, [r9, #0x4]! */
/* @0xd6cb8 mov r1, r5 */
/* @0xd6cbc mov r2, r4 */
/* @0xd6cc0 add r6, r6, #1 */
/* @0xd6cc4 cmp r0, #0 */
/* @0xd6cc8 beq 0xd6cd4 <_Z12MarkAndSweepP12YYObjectBase+0x228> */
/* @0xd6ccc bl 0x202d50 <_ZN9CDS_Stack7Mark4GCEPji> */
/* @0xd6cd0 ldr r12, [sp, #0x20] */
/* @0xd6cd4 cmp r12, r6 */
/* @0xd6cd8 bgt 0xd6cb4 <_Z12MarkAndSweepP12YYObjectBase+0x208> */
/* @0xd6cdc add r0, sp, #36 */
/* @0xd6ce0 bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xd6ce4 ldr r12, [sp, #0x24] */
/* @0xd6ce8 cmp r12, #0 */
/* @0xd6cec movgt r6, #0 */
/* @0xd6cf0 subgt r9, r0, #4 */
/* @0xd6cf4 ble 0xd6d20 <_Z12MarkAndSweepP12YYObjectBase+0x274> */
/* @0xd6cf8 ldr r0, [r9, #0x4]! */
/* @0xd6cfc mov r1, r5 */
/* @0xd6d00 mov r2, r4 */
/* @0xd6d04 add r6, r6, #1 */
/* @0xd6d08 cmp r0, #0 */
/* @0xd6d0c beq 0xd6d18 <_Z12MarkAndSweepP12YYObjectBase+0x26c> */
/* @0xd6d10 bl 0x202ed8 <_ZN9CDS_Queue7Mark4GCEPji> */
/* @0xd6d14 ldr r12, [sp, #0x24] */
/* @0xd6d18 cmp r12, r6 */
/* @0xd6d1c bgt 0xd6cf8 <_Z12MarkAndSweepP12YYObjectBase+0x24c> */
/* @0xd6d20 add r0, sp, #40 */
/* @0xd6d24 bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xd6d28 ldr r12, [sp, #0x28] */
/* @0xd6d2c cmp r12, #0 */
/* @0xd6d30 movgt r6, #0 */
/* @0xd6d34 subgt r9, r0, #4 */
/* @0xd6d38 ble 0xd6d64 <_Z12MarkAndSweepP12YYObjectBase+0x2b8> */
/* @0xd6d3c ldr r0, [r9, #0x4]! */
/* @0xd6d40 mov r1, r5 */
/* @0xd6d44 mov r2, r4 */
/* @0xd6d48 add r6, r6, #1 */
/* @0xd6d4c cmp r0, #0 */
/* @0xd6d50 beq 0xd6d5c <_Z12MarkAndSweepP12YYObjectBase+0x2b0> */
/* @0xd6d54 bl 0x205170 <_ZN8CDS_Grid7Mark4GCEPji> */
/* @0xd6d58 ldr r12, [sp, #0x28] */
/* @0xd6d5c cmp r12, r6 */
/* @0xd6d60 bgt 0xd6d3c <_Z12MarkAndSweepP12YYObjectBase+0x290> */
/* @0xd6d64 add r0, sp, #44 */
/* @0xd6d68 bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xd6d6c ldr r12, [sp, #0x2c] */
/* @0xd6d70 cmp r12, #0 */
/* @0xd6d74 movgt r6, #0 */
/* @0xd6d78 subgt r9, r0, #4 */
/* @0xd6d7c ble 0xd6da8 <_Z12MarkAndSweepP12YYObjectBase+0x2fc> */
/* @0xd6d80 ldr r0, [r9, #0x4]! */
/* @0xd6d84 mov r1, r5 */
/* @0xd6d88 mov r2, r4 */
/* @0xd6d8c add r6, r6, #1 */
/* @0xd6d90 cmp r0, #0 */
/* @0xd6d94 beq 0xd6da0 <_Z12MarkAndSweepP12YYObjectBase+0x2f4> */
/* @0xd6d98 bl 0x203e28 <_ZN12CDS_Priority7Mark4GCEPji> */
/* @0xd6d9c ldr r12, [sp, #0x2c] */
/* @0xd6da0 cmp r12, r6 */
/* @0xd6da4 bgt 0xd6d80 <_Z12MarkAndSweepP12YYObjectBase+0x2d4> */
/* @0xd6da8 mov r0, r10 */
/* @0xd6dac bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xd6db0 cmp r8, #0 */
/* @0xd6db4 beq 0xd6e08 <_Z12MarkAndSweepP12YYObjectBase+0x35c> */
/* @0xd6db8 ldr r3, [r8, #0x44] */
/* @0xd6dbc mov r0, #1 */
/* @0xd6dc0 cmp r3, #0 */
/* @0xd6dc4 add r1, r3, #31 */
/* @0xd6dc8 asr r2, r3, #31 */
/* @0xd6dcc movge r1, r3 */
/* @0xd6dd0 lsr r2, r2, #27 */
/* @0xd6dd4 asr r1, r1, #5 */
/* @0xd6dd8 add r3, r3, r2 */
/* @0xd6ddc and r3, r3, #31 */
/* @0xd6de0 ldr r1, [r5, r1, lsl #2] */
/* @0xd6de4 rsb r2, r2, r3 */
/* @0xd6de8 ands r1, r1, r0, lsl r2 */
/* @0xd6dec movne r4, #0 */
/* @0xd6df0 moveq r4, #1 */
/* @0xd6df4 mov r0, r5 */
/* @0xd6df8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd6dfc mov r0, r4 */
/* @0xd6e00 add sp, sp, #52 */
/* @0xd6e04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd6e08 ldr r3, [pc, #0x1d0] */
/* @0xd6e0c ldr r3, [r7, r3] */
/* @0xd6e10 str r3, [sp, #0x14] */
/* @0xd6e14 ldr r3, [r3] */
/* @0xd6e18 cmp r3, #0 */
/* @0xd6e1c beq 0xd6f48 <_Z12MarkAndSweepP12YYObjectBase+0x49c> */
/* @0xd6e20 ldr r2, [pc, #0x1bc] */
/* @0xd6e24 ldr r1, [pc, #0x1bc] */
/* @0xd6e28 ldr r2, [r7, r2] */
/* @0xd6e2c ldr r1, [r7, r1] */
/* @0xd6e30 ldr r10, [r2] */
/* @0xd6e34 str r1, [sp, #0x10] */
/* @0xd6e38 ldr r1, [r1] */
/* @0xd6e3c add r10, r10, r3 */
/* @0xd6e40 asr r2, r3, #31 */
/* @0xd6e44 cmp r10, r1 */
/* @0xd6e48 movge r10, r1 */
/* @0xd6e4c ldr r1, [sp] */
/* @0xd6e50 cmp r3, #0 */
/* @0xd6e54 add r7, r3, #31 */
/* @0xd6e58 lsr r2, r2, #27 */
/* @0xd6e5c str r10, [sp, #0xc] */
/* @0xd6e60 movge r7, r3 */
/* @0xd6e64 ldr r1, [r1] */
/* @0xd6e68 adds r8, r10, #31 */
/* @0xd6e6c add r3, r3, r2 */
/* @0xd6e70 addmi r8, r10, #62 */
/* @0xd6e74 asr r7, r7, #5 */
/* @0xd6e78 tst r4, #31 */
/* @0xd6e7c and r6, r3, #31 */
/* @0xd6e80 asr r8, r8, #5 */
/* @0xd6e84 str r1, [sp, #0x8] */
/* @0xd6e88 str r8, [sp] */
/* @0xd6e8c rsb r6, r2, r6 */
/* @0xd6e90 add r3, r5, r7, lsl #2 */
/* @0xd6e94 beq 0xd6ec4 <_Z12MarkAndSweepP12YYObjectBase+0x418> */
/* @0xd6e98 ldr r0, [sp, #0x4] */
/* @0xd6e9c asr r2, r4, #31 */
/* @0xd6ea0 sub r11, r0, #4 */
/* @0xd6ea4 lsr r2, r2, #27 */
/* @0xd6ea8 add r12, r4, r2 */
/* @0xd6eac mvn r0, #0 */
/* @0xd6eb0 ldr r1, [r5, r11] */
/* @0xd6eb4 and r12, r12, #31 */
/* @0xd6eb8 rsb r2, r2, r12 */
/* @0xd6ebc orr r2, r1, r0, lsl r2 */
/* @0xd6ec0 str r2, [r5, r11] */
/* @0xd6ec4 ldr r1, [sp] */
/* @0xd6ec8 cmp r7, r1 */
/* @0xd6ecc strlt r5, [sp, #0x4] */
/* @0xd6ed0 sublt r8, r3, #4 */
/* @0xd6ed4 lsllt r4, r7, #5 */
/* @0xd6ed8 movlt r10, #1 */
/* @0xd6edc bge 0xd6f74 <_Z12MarkAndSweepP12YYObjectBase+0x4c8> */
/* @0xd6ee0 ldr r9, [r8, #0x4]! */
/* @0xd6ee4 cmn r9, #1 */
/* @0xd6ee8 beq 0xd6f2c <_Z12MarkAndSweepP12YYObjectBase+0x480> */
/* @0xd6eec cmp r6, #31 */
/* @0xd6ef0 bhi 0xd6f2c <_Z12MarkAndSweepP12YYObjectBase+0x480> */
/* @0xd6ef4 add r1, r6, r4 */
/* @0xd6ef8 ldr r3, [sp, #0x8] */
/* @0xd6efc mov r11, #0 */
/* @0xd6f00 add r5, r3, r1, lsl #2 */
/* @0xd6f04 ands r0, r9, r10, lsl r6 */
/* @0xd6f08 bne 0xd6f1c <_Z12MarkAndSweepP12YYObjectBase+0x470> */
/* @0xd6f0c ldr r0, [r5, r11] */
/* @0xd6f10 cmp r0, #0 */
/* @0xd6f14 beq 0xd6f1c <_Z12MarkAndSweepP12YYObjectBase+0x470> */
/* @0xd6f18 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd6f1c add r6, r6, #1 */
/* @0xd6f20 add r11, r11, #4 */
/* @0xd6f24 cmp r6, #32 */
/* @0xd6f28 bne 0xd6f04 <_Z12MarkAndSweepP12YYObjectBase+0x458> */
/* @0xd6f2c ldr r2, [sp] */
/* @0xd6f30 add r7, r7, #1 */
/* @0xd6f34 add r4, r4, #32 */
/* @0xd6f38 cmp r7, r2 */
/* @0xd6f3c beq 0xd6f70 <_Z12MarkAndSweepP12YYObjectBase+0x4c4> */
/* @0xd6f40 mov r6, #0 */
/* @0xd6f44 b 0xd6ee0 <_Z12MarkAndSweepP12YYObjectBase+0x434> */
/* @0xd6f48 ldr r0, [pc, #0x98] */
/* @0xd6f4c mov r1, r4 */
/* @0xd6f50 ldr r2, [pc, #0x8c] */
/* @0xd6f54 mov r10, r4 */
/* @0xd6f58 ldr r0, [r7, r0] */
/* @0xd6f5c str r0, [sp, #0x10] */
/* @0xd6f60 str r4, [r0] */
/* @0xd6f64 ldr r2, [r7, r2] */
/* @0xd6f68 str r4, [r2] */
/* @0xd6f6c b 0xd6e3c <_Z12MarkAndSweepP12YYObjectBase+0x390> */
/* @0xd6f70 ldr r5, [sp, #0x4] */
/* @0xd6f74 ldr r2, [sp, #0x10] */
/* @0xd6f78 ldr r1, [sp, #0xc] */
/* @0xd6f7c ldr r3, [r2] */
/* @0xd6f80 cmp r3, r1 */
/* @0xd6f84 beq 0xd6f9c <_Z12MarkAndSweepP12YYObjectBase+0x4f0> */
/* @0xd6f88 ldr r2, [sp, #0xc] */
/* @0xd6f8c mov r4, #0 */
/* @0xd6f90 ldr r3, [sp, #0x14] */
/* @0xd6f94 str r2, [r3] */
/* @0xd6f98 b 0xd6df4 <_Z12MarkAndSweepP12YYObjectBase+0x348> */
/* @0xd6f9c ldr r1, [sp, #0x14] */
/* @0xd6fa0 mov r4, #0 */
/* @0xd6fa4 str r4, [r1] */
/* @0xd6fa8 b 0xd6df4 <_Z12MarkAndSweepP12YYObjectBase+0x348> */
/* @0xd6fac mlaseq r1, r0, r1, r11 */
/* @0xd6fb0 .word 0xffffbf68 */
/* @0xd6fb4 .word 0xffffbffc */
/* @0xd6fb8 .word 0xffffc014 */
/* @0xd6fbc eoreq r11, r5, r4, lsl #25 */
/* @0xd6fc0 .word 0xffffbf64 */
/* @0xd6fc4 .word 0xffffbcd8 */
/* @0xd6fc8 .word 0xffffc020 */
/* @0xd6fcc .word 0xffffc024 */
/* @0xd6fd0 .word 0xffffc028 */
/* @0xd6fd4 .word 0xffffbcec */
/* @0xd6fd8 .word 0xffffc02c */
/* @0xd6fdc .word 0xffffc030 */
/* @0xd6fe0 .word 0xffffc078 */
/* @0xd6fe4 .word 0xffffc07c */
/* @0xd6fe8 .word 0xffffc080 */

/* ── FUNC 0xd6fec · IncrementalMarkAndSweep() · size=1872 · insn=468 */
/* @0xd6fec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd6ff0 sub sp, sp, #100 */
/* @0xd6ff4 ldr r6, [pc, #0x6b0] */
/* @0xd6ff8 ldr r3, [pc, #0x6b0] */
/* @0xd6ffc add r6, pc, r6 */
/* @0xd7000 ldr r3, [r6, r3] */
/* @0xd7004 ldrb r3, [r3] */
/* @0xd7008 cmp r3, #0 */
/* @0xd700c beq 0xd7258 <_Z23IncrementalMarkAndSweepv+0x26c> */
/* @0xd7010 ldr r2, [pc, #0x69c] */
/* @0xd7014 mov r7, #10 */
/* @0xd7018 str r7, [sp, #0x18] */
/* @0xd701c ldr r7, [pc, #0x694] */
/* @0xd7020 ldr r3, [pc, #0x694] */
/* @0xd7024 add r7, pc, r7 */
/* @0xd7028 str r7, [sp, #0x24] */
/* @0xd702c ldr r2, [r6, r2] */
/* @0xd7030 ldr r7, [pc, #0x688] */
/* @0xd7034 str r2, [sp, #0x20] */
/* @0xd7038 add r7, pc, r7 */
/* @0xd703c ldr r3, [r6, r3] */
/* @0xd7040 str r7, [sp, #0x38] */
/* @0xd7044 ldr r7, [pc, #0x678] */
/* @0xd7048 str r3, [sp, #0x2c] */
/* @0xd704c add r7, pc, r7 */
/* @0xd7050 str r7, [sp, #0x34] */
/* @0xd7054 ldr r7, [pc, #0x66c] */
/* @0xd7058 add r7, pc, r7 */
/* @0xd705c str r7, [sp, #0x3c] */
/* @0xd7060 ldr r7, [pc, #0x664] */
/* @0xd7064 add r7, pc, r7 */
/* @0xd7068 str r7, [sp, #0x40] */
/* @0xd706c ldr r7, [pc, #0x65c] */
/* @0xd7070 add r7, pc, r7 */
/* @0xd7074 str r7, [sp, #0x44] */
/* @0xd7078 ldr r7, [sp, #0x20] */
/* @0xd707c ldr r5, [r7, #0x4] */
/* @0xd7080 ldr r7, [sp, #0x24] */
/* @0xd7084 adds r12, r5, #31 */
/* @0xd7088 addmi r12, r5, #62 */
/* @0xd708c ldr r3, [r7, #0xc] */
/* @0xd7090 asr r12, r12, #5 */
/* @0xd7094 cmp r12, r3 */
/* @0xd7098 bhi 0xd72e4 <_Z23IncrementalMarkAndSweepv+0x2f8> */
/* @0xd709c ldr r7, [sp, #0x2c] */
/* @0xd70a0 ldrb r3, [r7] */
/* @0xd70a4 cmp r3, #0 */
/* @0xd70a8 bne 0xd7260 <_Z23IncrementalMarkAndSweepv+0x274> */
/* @0xd70ac ldr r3, [pc, #0x620] */
/* @0xd70b0 ldr r3, [r6, r3] */
/* @0xd70b4 str r3, [sp, #0x28] */
/* @0xd70b8 ldr r2, [pc, #0x618] */
/* @0xd70bc ldr r1, [sp, #0x28] */
/* @0xd70c0 ldr r7, [sp, #0x20] */
/* @0xd70c4 ldr r3, [pc, #0x610] */
/* @0xd70c8 ldr r4, [r1] */
/* @0xd70cc ldr r7, [r7] */
/* @0xd70d0 ldr r1, [r6, r2] */
/* @0xd70d4 ldr r2, [pc, #0x604] */
/* @0xd70d8 str r7, [sp, #0x14] */
/* @0xd70dc str r4, [r1] */
/* @0xd70e0 add r2, pc, r2 */
/* @0xd70e4 ldr r3, [r6, r3] */
/* @0xd70e8 str r3, [sp, #0x30] */
/* @0xd70ec ldr r1, [sp, #0x30] */
/* @0xd70f0 ldr r3, [r2, #0x10] */
/* @0xd70f4 ldr r0, [r1] */
/* @0xd70f8 cmp r0, #0 */
/* @0xd70fc add r7, r4, r0 */
/* @0xd7100 asr r1, r0, #31 */
/* @0xd7104 add r12, r0, #31 */
/* @0xd7108 movge r12, r0 */
/* @0xd710c cmp r7, r4 */
/* @0xd7110 movge r7, r4 */
/* @0xd7114 adds r4, r7, #31 */
/* @0xd7118 lsr r1, r1, #27 */
/* @0xd711c asr r9, r12, #5 */
/* @0xd7120 add r0, r0, r1 */
/* @0xd7124 addmi r12, r7, #62 */
/* @0xd7128 movpl r12, r4 */
/* @0xd712c tst r5, #31 */
/* @0xd7130 and r4, r0, #31 */
/* @0xd7134 str r7, [sp, #0x1c] */
/* @0xd7138 asr r12, r12, #5 */
/* @0xd713c rsb r4, r1, r4 */
/* @0xd7140 str r12, [sp, #0x10] */
/* @0xd7144 add r8, r3, r9, lsl #2 */
/* @0xd7148 beq 0xd7178 <_Z23IncrementalMarkAndSweepv+0x18c> */
/* @0xd714c asr r1, r5, #31 */
/* @0xd7150 ldr r2, [r2, #0xc] */
/* @0xd7154 mvn r0, #0 */
/* @0xd7158 sub r2, r2, #-1073741823 */
/* @0xd715c lsr r1, r1, #27 */
/* @0xd7160 add r5, r5, r1 */
/* @0xd7164 ldr r7, [r3, r2, lsl #2] */
/* @0xd7168 and r5, r5, #31 */
/* @0xd716c rsb r1, r1, r5 */
/* @0xd7170 orr r1, r7, r0, lsl r1 */
/* @0xd7174 str r1, [r3, r2, lsl #2] */
/* @0xd7178 ldr r1, [sp, #0x10] */
/* @0xd717c cmp r9, r1 */
/* @0xd7180 bge 0xd7224 <_Z23IncrementalMarkAndSweepv+0x238> */
/* @0xd7184 lsl r7, r9, #5 */
/* @0xd7188 mov r11, #1 */
/* @0xd718c mov r10, r6 */
/* @0xd7190 sub r8, r8, #4 */
/* @0xd7194 str r8, [sp, #0xc] */
/* @0xd7198 ldr r1, [sp, #0xc] */
/* @0xd719c ldr r6, [r1, #0x4]! */
/* @0xd71a0 cmn r6, #1 */
/* @0xd71a4 str r1, [sp, #0xc] */
/* @0xd71a8 beq 0xd7208 <_Z23IncrementalMarkAndSweepv+0x21c> */
/* @0xd71ac cmp r4, #31 */
/* @0xd71b0 bhi 0xd7208 <_Z23IncrementalMarkAndSweepv+0x21c> */
/* @0xd71b4 add r1, r7, r4 */
/* @0xd71b8 ldr r3, [sp, #0x14] */
/* @0xd71bc mov r5, #0 */
/* @0xd71c0 add r8, r3, r1, lsl #2 */
/* @0xd71c4 ands r0, r6, r11, lsl r4 */
/* @0xd71c8 ldr r2, [pc, #0x514] */
/* @0xd71cc add r4, r4, #1 */
/* @0xd71d0 bne 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210> */
/* @0xd71d4 ldr r3, [r8, r5] */
/* @0xd71d8 cmp r3, #0 */
/* @0xd71dc mov r0, r3 */
/* @0xd71e0 beq 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210> */
/* @0xd71e4 ldr r1, [r10, r2] */
/* @0xd71e8 ldr r2, [r3, #0x34] */
/* @0xd71ec ldr r3, [r1] */
/* @0xd71f0 cmp r2, r3 */
/* @0xd71f4 beq 0xd71fc <_Z23IncrementalMarkAndSweepv+0x210> */
/* @0xd71f8 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_> */
/* @0xd71fc cmp r4, #32 */
/* @0xd7200 add r5, r5, #4 */
/* @0xd7204 bne 0xd71c4 <_Z23IncrementalMarkAndSweepv+0x1d8> */
/* @0xd7208 ldr r2, [sp, #0x10] */
/* @0xd720c add r9, r9, #1 */
/* @0xd7210 add r7, r7, #32 */
/* @0xd7214 cmp r9, r2 */
/* @0xd7218 movne r4, #0 */
/* @0xd721c bne 0xd7198 <_Z23IncrementalMarkAndSweepv+0x1ac> */
/* @0xd7220 mov r6, r10 */
/* @0xd7224 ldr r2, [sp, #0x28] */
/* @0xd7228 ldr r7, [sp, #0x1c] */
/* @0xd722c ldr r3, [r2] */
/* @0xd7230 cmp r7, r3 */
/* @0xd7234 beq 0xd7628 <_Z23IncrementalMarkAndSweepv+0x63c> */
/* @0xd7238 ldr r1, [sp, #0x1c] */
/* @0xd723c ldr r2, [sp, #0x30] */
/* @0xd7240 str r1, [r2] */
/* @0xd7244 ldr r7, [sp, #0x18] */
/* @0xd7248 sub r7, r7, #1 */
/* @0xd724c str r7, [sp, #0x18] */
/* @0xd7250 cmn r7, #1 */
/* @0xd7254 bne 0xd7078 <_Z23IncrementalMarkAndSweepv+0x8c> */
/* @0xd7258 add sp, sp, #100 */
/* @0xd725c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd7260 ldr r3, [pc, #0x480] */
/* @0xd7264 ldr r10, [r6, r3] */
/* @0xd7268 ldr r1, [r10] */
/* @0xd726c cmp r1, #0 */
/* @0xd7270 movne r7, r1 */
/* @0xd7274 beq 0xd730c <_Z23IncrementalMarkAndSweepv+0x320> */
/* @0xd7278 add r4, r5, r7 */
/* @0xd727c ldr r0, [sp, #0x20] */
/* @0xd7280 cmp r4, r5 */
/* @0xd7284 movge r4, r5 */
/* @0xd7288 cmp r4, r7 */
/* @0xd728c ldr r3, [r0] */
/* @0xd7290 ble 0xd72c4 <_Z23IncrementalMarkAndSweepv+0x2d8> */
/* @0xd7294 sub r8, r7, #-1073741823 */
/* @0xd7298 ldr r9, [sp, #0x34] */
/* @0xd729c add r8, r3, r8, lsl #2 */
/* @0xd72a0 ldr r0, [r8, #0x4]! */
/* @0xd72a4 mov r2, r5 */
/* @0xd72a8 add r7, r7, #1 */
/* @0xd72ac cmp r0, #0 */
/* @0xd72b0 beq 0xd72bc <_Z23IncrementalMarkAndSweepv+0x2d0> */
/* @0xd72b4 ldr r1, [r9, #0x10] */
/* @0xd72b8 bl 0x191f84 <_ZN12YYObjectBase19MarkOnlyChildren4GCEPji> */
/* @0xd72bc cmp r7, r4 */
/* @0xd72c0 bne 0xd72a0 <_Z23IncrementalMarkAndSweepv+0x2b4> */
/* @0xd72c4 cmp r5, r4 */
/* @0xd72c8 str r4, [r10] */
/* @0xd72cc beq 0xd7604 <_Z23IncrementalMarkAndSweepv+0x618> */
/* @0xd72d0 ldr r7, [sp, #0x2c] */
/* @0xd72d4 ldrb r3, [r7] */
/* @0xd72d8 cmp r3, #0 */
/* @0xd72dc bne 0xd7244 <_Z23IncrementalMarkAndSweepv+0x258> */
/* @0xd72e0 b 0xd70ac <_Z23IncrementalMarkAndSweepv+0xc0> */
/* @0xd72e4 ldr r0, [r7, #0x10] */
/* @0xd72e8 mov r3, #0 */
/* @0xd72ec lsl r1, r12, #2 */
/* @0xd72f0 str r3, [sp] */
/* @0xd72f4 ldr r2, [sp, #0x38] */
/* @0xd72f8 mov r3, #752 */
/* @0xd72fc str r12, [r7, #0xc] */
/* @0xd7300 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd7304 str r0, [r7, #0x10] */
/* @0xd7308 b 0xd709c <_Z23IncrementalMarkAndSweepv+0xb0> */
/* @0xd730c ldr r3, [pc, #0x3d0] */
/* @0xd7310 ldr r7, [sp, #0x3c] */
/* @0xd7314 ldr r3, [r6, r3] */
/* @0xd7318 ldr r4, [r7, #0x10] */
/* @0xd731c ldr r2, [r7, #0xc] */
/* @0xd7320 ldr r12, [r3] */
/* @0xd7324 mov r0, r4 */
/* @0xd7328 lsl r2, r2, #2 */
/* @0xd732c add r12, r12, #1 */
/* @0xd7330 str r12, [r3] */
/* @0xd7334 bl 0xb65b0 <memset@plt> */
/* @0xd7338 ldr r3, [pc, #0x3ac] */
/* @0xd733c mov r1, r4 */
/* @0xd7340 mov r2, r5 */
/* @0xd7344 ldr r3, [r6, r3] */
/* @0xd7348 ldr r0, [r3] */
/* @0xd734c bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0xd7350 ldr r3, [pc, #0x398] */
/* @0xd7354 ldr r7, [r6, r3] */
/* @0xd7358 ldr r3, [r7] */
/* @0xd735c cmp r3, #0 */
/* @0xd7360 beq 0xd75fc <_Z23IncrementalMarkAndSweepv+0x610> */
/* @0xd7364 ldr r0, [r3, #0x80] */
/* @0xd7368 cmp r0, #0 */
/* @0xd736c beq 0xd7398 <_Z23IncrementalMarkAndSweepv+0x3ac> */
/* @0xd7370 ldr r4, [pc, #0x37c] */
/* @0xd7374 add r4, pc, r4 */
/* @0xd7378 ldr r8, [r0, #0x178] */
/* @0xd737c mov r2, r5 */
/* @0xd7380 ldr r1, [r4, #0x10] */
/* @0xd7384 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0xd7388 cmp r8, #0 */
/* @0xd738c mov r0, r8 */
/* @0xd7390 bne 0xd7378 <_Z23IncrementalMarkAndSweepv+0x38c> */
/* @0xd7394 ldr r3, [r7] */
/* @0xd7398 ldr r0, [r3, #0x8c] */
/* @0xd739c cmp r0, #0 */
/* @0xd73a0 ldrne r7, [sp, #0x40] */
/* @0xd73a4 beq 0xd73c4 <_Z23IncrementalMarkAndSweepv+0x3d8> */
/* @0xd73a8 ldr r4, [r0, #0x178] */
/* @0xd73ac mov r2, r5 */
/* @0xd73b0 ldr r1, [r7, #0x10] */
/* @0xd73b4 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0xd73b8 cmp r4, #0 */
/* @0xd73bc mov r0, r4 */
/* @0xd73c0 bne 0xd73a8 <_Z23IncrementalMarkAndSweepv+0x3bc> */
/* @0xd73c4 ldr r3, [pc, #0x32c] */
/* @0xd73c8 ldr r3, [r6, r3] */
/* @0xd73cc ldr r0, [r3] */
/* @0xd73d0 cmp r0, #0 */
/* @0xd73d4 beq 0xd73ec <_Z23IncrementalMarkAndSweepv+0x400> */
/* @0xd73d8 ldr r3, [pc, #0x31c] */
/* @0xd73dc mov r2, r5 */
/* @0xd73e0 add r3, pc, r3 */
/* @0xd73e4 ldr r1, [r3, #0x10] */
/* @0xd73e8 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0xd73ec ldr r3, [pc, #0x30c] */
/* @0xd73f0 ldr r3, [r6, r3] */
/* @0xd73f4 ldr r0, [r3, #0x8] */
/* @0xd73f8 cmp r0, #0 */
/* @0xd73fc beq 0xd7414 <_Z23IncrementalMarkAndSweepv+0x428> */
/* @0xd7400 ldr r3, [pc, #0x2fc] */
/* @0xd7404 mov r2, r5 */
/* @0xd7408 add r3, pc, r3 */
/* @0xd740c ldr r1, [r3, #0x10] */
/* @0xd7410 bl 0x191f0c <_ZN12YYObjectBase15MarkThisOnly4GCEPji> */
/* @0xd7414 add r11, sp, #76 */
/* @0xd7418 mov r0, r11 */
/* @0xd741c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xd7420 ldr r3, [pc, #0x2e0] */
/* @0xd7424 ldr r7, [r6, r3] */
/* @0xd7428 ldr r3, [r7] */
/* @0xd742c cmp r3, #0 */
/* @0xd7430 ble 0xd7470 <_Z23IncrementalMarkAndSweepv+0x484> */
/* @0xd7434 ldr r3, [pc, #0x2d0] */
/* @0xd7438 mov r4, #0 */
/* @0xd743c ldr r9, [sp, #0x44] */
/* @0xd7440 ldr r8, [r6, r3] */
/* @0xd7444 ldr r3, [r8, #0x4] */
/* @0xd7448 mov r2, r5 */
/* @0xd744c ldr r0, [r3, r4, lsl #2] */
/* @0xd7450 add r4, r4, #1 */
/* @0xd7454 cmp r0, #0 */
/* @0xd7458 beq 0xd7464 <_Z23IncrementalMarkAndSweepv+0x478> */
/* @0xd745c ldr r1, [r9, #0x10] */
/* @0xd7460 bl 0x203878 <_ZN7CDS_Map19MarkOnlyChildren4GCEPji> */
/* @0xd7464 ldr r3, [r7] */
/* @0xd7468 cmp r3, r4 */
/* @0xd746c bgt 0xd7444 <_Z23IncrementalMarkAndSweepv+0x458> */
/* @0xd7470 ldr r3, [pc, #0x298] */
/* @0xd7474 ldr r8, [r6, r3] */
/* @0xd7478 ldr r3, [r8] */
/* @0xd747c cmp r3, #0 */
/* @0xd7480 ble 0xd74c4 <_Z23IncrementalMarkAndSweepv+0x4d8> */
/* @0xd7484 ldr r3, [pc, #0x288] */
/* @0xd7488 mov r4, #0 */
/* @0xd748c ldr r7, [pc, #0x284] */
/* @0xd7490 ldr r9, [r6, r3] */
/* @0xd7494 add r7, pc, r7 */
/* @0xd7498 ldr r3, [r9, #0x4] */
/* @0xd749c mov r2, r5 */
/* @0xd74a0 ldr r0, [r3, r4, lsl #2] */
/* @0xd74a4 add r4, r4, #1 */
/* @0xd74a8 cmp r0, #0 */
/* @0xd74ac beq 0xd74b8 <_Z23IncrementalMarkAndSweepv+0x4cc> */
/* @0xd74b0 ldr r1, [r7, #0x10] */
/* @0xd74b4 bl 0x203134 <_ZN8CDS_List19MarkOnlyChildren4GCEPji> */
/* @0xd74b8 ldr r3, [r8] */
/* @0xd74bc cmp r3, r4 */
/* @0xd74c0 bgt 0xd7498 <_Z23IncrementalMarkAndSweepv+0x4ac> */
/* @0xd74c4 add r0, sp, #80 */
/* @0xd74c8 ldr r4, [pc, #0x24c] */
/* @0xd74cc bl 0xffc9c <_Z12GetTheStacksRi> */
/* @0xd74d0 ldr r3, [sp, #0x50] */
/* @0xd74d4 add r4, pc, r4 */
/* @0xd74d8 mov r7, #0 */
/* @0xd74dc cmp r3, #0 */
/* @0xd74e0 sub r8, r0, #4 */
/* @0xd74e4 ble 0xd7510 <_Z23IncrementalMarkAndSweepv+0x524> */
/* @0xd74e8 ldr r0, [r8, #0x4]! */
/* @0xd74ec mov r2, r5 */
/* @0xd74f0 add r7, r7, #1 */
/* @0xd74f4 cmp r0, #0 */
/* @0xd74f8 beq 0xd7508 <_Z23IncrementalMarkAndSweepv+0x51c> */
/* @0xd74fc ldr r1, [r4, #0x10] */
/* @0xd7500 bl 0x202dd8 <_ZN9CDS_Stack19MarkOnlyChildren4GCEPji> */
/* @0xd7504 ldr r3, [sp, #0x50] */
/* @0xd7508 cmp r3, r7 */
/* @0xd750c bgt 0xd74e8 <_Z23IncrementalMarkAndSweepv+0x4fc> */
/* @0xd7510 add r0, sp, #84 */
/* @0xd7514 ldr r4, [pc, #0x204] */
/* @0xd7518 bl 0xffee8 <_Z12GetTheQueuesRi> */
/* @0xd751c ldr r3, [sp, #0x54] */
/* @0xd7520 add r4, pc, r4 */
/* @0xd7524 mov r7, #0 */
/* @0xd7528 cmp r3, #0 */
/* @0xd752c sub r8, r0, #4 */
/* @0xd7530 ble 0xd755c <_Z23IncrementalMarkAndSweepv+0x570> */
/* @0xd7534 ldr r0, [r8, #0x4]! */
/* @0xd7538 mov r2, r5 */
/* @0xd753c add r7, r7, #1 */
/* @0xd7540 cmp r0, #0 */
/* @0xd7544 beq 0xd7554 <_Z23IncrementalMarkAndSweepv+0x568> */
/* @0xd7548 ldr r1, [r4, #0x10] */
/* @0xd754c bl 0x202f60 <_ZN9CDS_Queue19MarkOnlyChildren4GCEPji> */
/* @0xd7550 ldr r3, [sp, #0x54] */
/* @0xd7554 cmp r3, r7 */
/* @0xd7558 bgt 0xd7534 <_Z23IncrementalMarkAndSweepv+0x548> */
/* @0xd755c add r0, sp, #88 */
/* @0xd7560 ldr r4, [pc, #0x1bc] */
/* @0xd7564 bl 0x10026c <_Z11GetTheGridsRi> */
/* @0xd7568 ldr r3, [sp, #0x58] */
/* @0xd756c add r4, pc, r4 */
/* @0xd7570 mov r7, #0 */
/* @0xd7574 cmp r3, #0 */
/* @0xd7578 sub r8, r0, #4 */
/* @0xd757c ble 0xd75a8 <_Z23IncrementalMarkAndSweepv+0x5bc> */
/* @0xd7580 ldr r0, [r8, #0x4]! */
/* @0xd7584 mov r2, r5 */
/* @0xd7588 add r7, r7, #1 */
/* @0xd758c cmp r0, #0 */
/* @0xd7590 beq 0xd75a0 <_Z23IncrementalMarkAndSweepv+0x5b4> */
/* @0xd7594 ldr r1, [r4, #0x10] */
/* @0xd7598 bl 0x205240 <_ZN8CDS_Grid19MarkOnlyChildren4GCEPji> */
/* @0xd759c ldr r3, [sp, #0x58] */
/* @0xd75a0 cmp r3, r7 */
/* @0xd75a4 bgt 0xd7580 <_Z23IncrementalMarkAndSweepv+0x594> */
/* @0xd75a8 add r0, sp, #92 */
/* @0xd75ac ldr r4, [pc, #0x174] */
/* @0xd75b0 bl 0x100244 <_Z20GetThePriorityQueuesRi> */
/* @0xd75b4 ldr r3, [sp, #0x5c] */
/* @0xd75b8 add r4, pc, r4 */
/* @0xd75bc mov r7, #0 */
/* @0xd75c0 cmp r3, #0 */
/* @0xd75c4 sub r8, r0, #4 */
/* @0xd75c8 ble 0xd75f4 <_Z23IncrementalMarkAndSweepv+0x608> */
/* @0xd75cc ldr r0, [r8, #0x4]! */
/* @0xd75d0 mov r2, r5 */
/* @0xd75d4 add r7, r7, #1 */
/* @0xd75d8 cmp r0, #0 */
/* @0xd75dc beq 0xd75ec <_Z23IncrementalMarkAndSweepv+0x600> */
/* @0xd75e0 ldr r1, [r4, #0x10] */
/* @0xd75e4 bl 0x203f14 <_ZN12CDS_Priority19MarkOnlyChildren4GCEPji> */
/* @0xd75e8 ldr r3, [sp, #0x5c] */
/* @0xd75ec cmp r3, r7 */
/* @0xd75f0 bgt 0xd75cc <_Z23IncrementalMarkAndSweepv+0x5e0> */
/* @0xd75f4 mov r0, r11 */
/* @0xd75f8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xd75fc ldr r7, [r10] */
/* @0xd7600 b 0xd7278 <_Z23IncrementalMarkAndSweepv+0x28c> */
/* @0xd7604 ldr r2, [pc, #0xc8] */
/* @0xd7608 mov r3, #0 */
/* @0xd760c ldr r7, [sp, #0x2c] */
/* @0xd7610 strb r3, [r7] */
/* @0xd7614 ldr r2, [r6, r2] */
/* @0xd7618 str r3, [r10] */
/* @0xd761c str r2, [sp, #0x28] */
/* @0xd7620 str r5, [r2] */
/* @0xd7624 b 0xd70b8 <_Z23IncrementalMarkAndSweepv+0xcc> */
/* @0xd7628 ldr r7, [sp, #0x18] */
/* @0xd762c mov r3, #0 */
/* @0xd7630 ldr r1, [sp, #0x30] */
/* @0xd7634 cmp r7, #0 */
/* @0xd7638 ldr r7, [sp, #0x2c] */
/* @0xd763c str r3, [r1] */
/* @0xd7640 mov r3, #1 */
/* @0xd7644 strb r3, [r7] */
/* @0xd7648 bne 0xd7244 <_Z23IncrementalMarkAndSweepv+0x258> */
/* @0xd764c ldr r4, [pc, #0xd8] */
/* @0xd7650 mov r3, #74 */
/* @0xd7654 ldr r1, [pc, #0xd4] */
/* @0xd7658 add r4, pc, r4 */
/* @0xd765c ldr r7, [sp, #0x18] */
/* @0xd7660 ldr r2, [pc, #0xcc] */
/* @0xd7664 ldr r5, [r6, r1] */
/* @0xd7668 ldr r1, [r4, #0xc] */
/* @0xd766c add r2, pc, r2 */
/* @0xd7670 str r7, [sp] */
/* @0xd7674 ldr r0, [r5] */
/* @0xd7678 lsl r1, r1, #2 */
/* @0xd767c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xd7680 ldr r12, [pc, #0xb0] */
/* @0xd7684 ldr r3, [r4, #0xc] */
/* @0xd7688 ldr r1, [r4, #0x10] */
/* @0xd768c lsl r2, r3, #2 */
/* @0xd7690 str r0, [r5] */
/* @0xd7694 ldr r12, [r6, r12] */
/* @0xd7698 str r3, [r12] */
/* @0xd769c bl 0xb65bc <memcpy@plt> */
/* @0xd76a0 ldr r0, [sp, #0x18] */
/* @0xd76a4 bl 0xd6aac <_Z12MarkAndSweepP12YYObjectBase> */
/* @0xd76a8 b 0xd7258 <_Z23IncrementalMarkAndSweepv+0x26c> */
/* @0xd76ac eorseq r10, r1, r4, asr r12 */
/* @0xd76b0 .word 0xffffbf68 */
/* @0xd76b4 .word 0xffffc014 */
/* @0xd76b8 mlaseq r10, r0, r1, r3 */
/* @0xd76bc .word 0xffffc084 */
/* @0xd76c0 eoreq r11, r5, r4, asr #14 */
/* @0xd76c4 eorseq r3, r10, r8, ror #2 */
/* @0xd76c8 eorseq r3, r10, r12, asr r1 */
/* @0xd76cc eorseq r3, r10, r0, asr r1 */
/* @0xd76d0 eorseq r3, r10, r4, asr #2 */
/* @0xd76d4 .word 0xffffc080 */
/* @0xd76d8 .word 0xffffc07c */
/* @0xd76dc .word 0xffffc078 */
/* @0xd76e0 ldrsbteq r3, [r10], -r4 */
/* @0xd76e4 .word 0xffffbffc */
/* @0xd76e8 .word 0xffffc088 */
/* @0xd76ec .word 0xffffbf64 */
/* @0xd76f0 .word 0xffffbcd8 */
/* @0xd76f4 eorseq r2, r10, r0, asr #28 */
/* @0xd76f8 .word 0xffffc020 */
/* @0xd76fc ldrsbteq r2, [r10], -r4 */
/* @0xd7700 .word 0xffffc024 */
/* @0xd7704 eorseq r2, r10, r12, lsr #27 */
/* @0xd7708 .word 0xffffc028 */
/* @0xd770c .word 0xffffbcec */
/* @0xd7710 .word 0xffffc02c */
/* @0xd7714 .word 0xffffc030 */
/* @0xd7718 eorseq r2, r10, r0, lsr #26 */
/* @0xd771c eorseq r2, r10, r0, ror #25 */
/* @0xd7720 mlaseq r10, r4, r12, r2 */
/* @0xd7724 eorseq r2, r10, r8, asr #24 */
/* @0xd7728 ldrshteq r2, [r10], -r12 */
/* @0xd772c eorseq r2, r10, r12, asr r11 */
/* @0xd7730 .word 0xffffc08c */
/* @0xd7734 eoreq r9, r5, r4, asr #19 */
/* @0xd7738 .word 0xffffc090 */

/* ── FUNC 0xd773c · DoConvIntToVariable(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=36 · insn=9 */
/* @0xd773c vldr s15, [r1] */
/* @0xd7740 vcvt.f64.s32 d7, s15 */
/* @0xd7744 mov r0, r1 */
/* @0xd7748 mov r12, #0 */
/* @0xd774c vmov r2, r3, d7 */
/* @0xd7750 vstr s14, [r1, #-12] */
/* @0xd7754 str r3, [r1, #-0x8] */
/* @0xd7758 str r12, [r0], #-12 */
/* @0xd775c bx lr */

/* ── FUNC 0xd7760 · ParamSizeOnStack(int) · size=36 · insn=9 */
/* @0xd7760 cmp r0, #6 */
/* @0xd7764 bhi 0xd7778 <_Z16ParamSizeOnStacki+0x18> */
/* @0xd7768 ldr r3, [pc, #0x10] */
/* @0xd776c add r3, pc, r3 */
/* @0xd7770 ldr r0, [r3, r0, lsl #2] */
/* @0xd7774 bx lr */
/* @0xd7778 mov r0, #0 */
/* @0xd777c bx lr */
/* @0xd7780 .word 0x002850f4 */

/* ── FUNC 0xd7784 · boxType(RValue&, eVM_Type, unsigned char*) · size=388 · insn=97 */
/* @0xd7784 push {r4, r5, r6, lr} */
/* @0xd7788 mov r6, r0 */
/* @0xd778c sub sp, sp, #8 */
/* @0xd7790 cmp r1, #9 */
/* @0xd7794 addls pc, pc, r1, lsl #2 */
/* @0xd7798 b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* @0xd779c b 0xd780c <_Z7boxTypeR6RValue8eVM_TypePh+0x88> */
/* @0xd77a0 b 0xd7830 <_Z7boxTypeR6RValue8eVM_TypePh+0xac> */
/* @0xd77a4 b 0xd785c <_Z7boxTypeR6RValue8eVM_TypePh+0xd8> */
/* @0xd77a8 b 0xd77c4 <_Z7boxTypeR6RValue8eVM_TypePh+0x40> */
/* @0xd77ac b 0xd788c <_Z7boxTypeR6RValue8eVM_TypePh+0x108> */
/* @0xd77b0 b 0xd78bc <_Z7boxTypeR6RValue8eVM_TypePh+0x138> */
/* @0xd77b4 b 0xd78ec <_Z7boxTypeR6RValue8eVM_TypePh+0x168> */
/* @0xd77b8 b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* @0xd77bc b 0xd77e0 <_Z7boxTypeR6RValue8eVM_TypePh+0x5c> */
/* @0xd77c0 b 0xd77ec <_Z7boxTypeR6RValue8eVM_TypePh+0x68> */
/* @0xd77c4 ldrd r0, r1, [r2], #8 */
/* @0xd77c8 mov r3, #0 */
/* @0xd77cc str r3, [r6, #0xc] */
/* @0xd77d0 str r2, [sp, #0x4] */
/* @0xd77d4 bl 0x319164 <__floatdidf> */
/* @0xd77d8 stm r6, {r0, r1} */
/* @0xd77dc ldr r2, [sp, #0x4] */
/* @0xd77e0 mov r0, r2 */
/* @0xd77e4 add sp, sp, #8 */
/* @0xd77e8 pop {r4, r5, r6, pc} */
/* @0xd77ec mov r3, #0 */
/* @0xd77f0 mov r1, #5 */
/* @0xd77f4 str r3, [r0] */
/* @0xd77f8 str r1, [r0, #0xc] */
/* @0xd77fc str r3, [r0, #0x4] */
/* @0xd7800 mov r0, r2 */
/* @0xd7804 add sp, sp, #8 */
/* @0xd7808 pop {r4, r5, r6, pc} */
/* @0xd780c ldr r1, [r2] */
/* @0xd7810 add r2, r2, #8 */
/* @0xd7814 ldr r3, [r2, #-0x4] */
/* @0xd7818 mov r0, #0 */
/* @0xd781c str r0, [r6, #0xc] */
/* @0xd7820 mov r0, r2 */
/* @0xd7824 stm r6, {r1, r3} */
/* @0xd7828 add sp, sp, #8 */
/* @0xd782c pop {r4, r5, r6, pc} */
/* @0xd7830 vldmia r2!, {s15} */
/* @0xd7834 vcvt.f64.f32 d6, s15 */
/* @0xd7838 mov r3, #0 */
/* @0xd783c str r3, [r0, #0xc] */
/* @0xd7840 vmov r4, r5, d6 */
/* @0xd7844 vmov r1, s12 */
/* @0xd7848 mov r3, r5 */
/* @0xd784c stm r0, {r1, r3} */
/* @0xd7850 mov r0, r2 */
/* @0xd7854 add sp, sp, #8 */
/* @0xd7858 pop {r4, r5, r6, pc} */
/* @0xd785c mov r3, #0 */
/* @0xd7860 str r3, [r0, #0xc] */
/* @0xd7864 ldr r4, [r2], #4 */
/* @0xd7868 vmov s13, r4 */
/* @0xd786c vcvt.f64.s32 d6, s13 */
/* @0xd7870 vmov r4, r5, d6 */
/* @0xd7874 vmov r1, s12 */
/* @0xd7878 mov r3, r5 */
/* @0xd787c stm r0, {r1, r3} */
/* @0xd7880 mov r0, r2 */
/* @0xd7884 add sp, sp, #8 */
/* @0xd7888 pop {r4, r5, r6, pc} */
/* @0xd788c mov r3, #13 */
/* @0xd7890 str r3, [r0, #0xc] */
/* @0xd7894 ldr r4, [r2], #4 */
/* @0xd7898 vmov s15, r4 */
/* @0xd789c vcvt.f64.s32 d7, s15 */
/* @0xd78a0 vmov r4, r5, d7 */
/* @0xd78a4 vmov r1, s14 */
/* @0xd78a8 mov r3, r5 */
/* @0xd78ac stm r0, {r1, r3} */
/* @0xd78b0 mov r0, r2 */
/* @0xd78b4 add sp, sp, #8 */
/* @0xd78b8 pop {r4, r5, r6, pc} */
/* @0xd78bc ldr r12, [r2] */
/* @0xd78c0 add r2, r2, #16 */
/* @0xd78c4 ldr r0, [r2, #-0xc] */
/* @0xd78c8 ldr r1, [r2, #-0x8] */
/* @0xd78cc ldr r3, [r2, #-0x4] */
/* @0xd78d0 str r0, [r6, #0x4] */
/* @0xd78d4 mov r0, r2 */
/* @0xd78d8 str r12, [r6] */
/* @0xd78dc str r1, [r6, #0x8] */
/* @0xd78e0 str r3, [r6, #0xc] */
/* @0xd78e4 add sp, sp, #8 */
/* @0xd78e8 pop {r4, r5, r6, pc} */
/* @0xd78ec ldr r3, [r2], #4 */
/* @0xd78f0 mov r1, #1 */
/* @0xd78f4 str r1, [r0, #0xc] */
/* @0xd78f8 str r3, [r0] */
/* @0xd78fc mov r0, r2 */
/* @0xd7900 add sp, sp, #8 */
/* @0xd7904 pop {r4, r5, r6, pc} */

/* ── FUNC 0xd7908 · DoNot(unsigned int, unsigned char*, unsigned char const*, VMExec*) · size=812 · insn=203 */
/* @0xd7908 ubfx r2, r0, #0x8, #0x4 */
/* @0xd790c cmp r2, #0 */
/* @0xd7910 push {r4, r5, r6, lr} */
/* @0xd7914 mov r6, r1 */
/* @0xd7918 sub sp, sp, #32 */
/* @0xd791c lsr r1, r0, #16 */
/* @0xd7920 beq 0xd7934 <_Z5DoNotjPhPKhP6VMExec+0x2c> */
/* @0xd7924 cmp r2, #1 */
/* @0xd7928 beq 0xd7a78 <_Z5DoNotjPhPKhP6VMExec+0x170> */
/* @0xd792c cmp r2, #2 */
/* @0xd7930 beq 0xd7ac0 <_Z5DoNotjPhPKhP6VMExec+0x1b8> */
/* @0xd7934 and r2, r1, #15 */
/* @0xd7938 cmp r2, #6 */
/* @0xd793c addls pc, pc, r2, lsl #2 */
/* @0xd7940 b 0xd7c10 <_Z5DoNotjPhPKhP6VMExec+0x308> */
/* @0xd7944 b 0xd7a24 <_Z5DoNotjPhPKhP6VMExec+0x11c> */
/* @0xd7948 b 0xd7a4c <_Z5DoNotjPhPKhP6VMExec+0x144> */
/* @0xd794c b 0xd7960 <_Z5DoNotjPhPKhP6VMExec+0x58> */
/* @0xd7950 b 0xd797c <_Z5DoNotjPhPKhP6VMExec+0x74> */
/* @0xd7954 b 0xd799c <_Z5DoNotjPhPKhP6VMExec+0x94> */
/* @0xd7958 b 0xd79bc <_Z5DoNotjPhPKhP6VMExec+0xb4> */
/* @0xd795c b 0xd7a04 <_Z5DoNotjPhPKhP6VMExec+0xfc> */
/* @0xd7960 ldr r3, [r6] */
/* @0xd7964 mov r12, r6 */
/* @0xd7968 mvn r3, r3 */
/* @0xd796c str r3, [r6] */
/* @0xd7970 mov r0, r12 */
/* @0xd7974 add sp, sp, #32 */
/* @0xd7978 pop {r4, r5, r6, pc} */
/* @0xd797c ldrd r4, r5, [r6] */
/* @0xd7980 mov r12, r6 */
/* @0xd7984 mov r0, r12 */
/* @0xd7988 mvn r4, r4 */
/* @0xd798c mvn r5, r5 */
/* @0xd7990 strd r4, r5, [r6] */
/* @0xd7994 add sp, sp, #32 */
/* @0xd7998 pop {r4, r5, r6, pc} */
/* @0xd799c ldr r3, [r6] */
/* @0xd79a0 mov r12, r6 */
/* @0xd79a4 mov r0, r12 */
/* @0xd79a8 rsbs r3, r3, #1 */
/* @0xd79ac movlo r3, #0 */
/* @0xd79b0 str r3, [r6] */
/* @0xd79b4 add sp, sp, #32 */
/* @0xd79b8 pop {r4, r5, r6, pc} */
/* @0xd79bc ldr r2, [r6, #0xc] */
/* @0xd79c0 cmp r2, #13 */
/* @0xd79c4 addls pc, pc, r2, lsl #2 */
/* @0xd79c8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79cc b 0xd7b84 <_Z5DoNotjPhPKhP6VMExec+0x27c> */
/* @0xd79d0 b 0xd7b6c <_Z5DoNotjPhPKhP6VMExec+0x264> */
/* @0xd79d4 b 0xd7ba4 <_Z5DoNotjPhPKhP6VMExec+0x29c> */
/* @0xd79d8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79dc b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e0 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e4 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79e8 b 0xd7960 <_Z5DoNotjPhPKhP6VMExec+0x58> */
/* @0xd79ec b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79f0 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79f4 b 0xd7b50 <_Z5DoNotjPhPKhP6VMExec+0x248> */
/* @0xd79f8 b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd79fc b 0xd7be4 <_Z5DoNotjPhPKhP6VMExec+0x2dc> */
/* @0xd7a00 b 0xd7b84 <_Z5DoNotjPhPKhP6VMExec+0x27c> */
/* @0xd7a04 ldr r1, [pc, #0x20c] */
/* @0xd7a08 mov r0, r3 */
/* @0xd7a0c add r1, pc, r1 */
/* @0xd7a10 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7a14 mov r12, r6 */
/* @0xd7a18 mov r0, r12 */
/* @0xd7a1c add sp, sp, #32 */
/* @0xd7a20 pop {r4, r5, r6, pc} */
/* @0xd7a24 ldrd r0, r1, [r6] */
/* @0xd7a28 bl 0x3194a0 <__fixdfdi> */
/* @0xd7a2c mvn r0, r0 */
/* @0xd7a30 mvn r1, r1 */
/* @0xd7a34 bl 0x319164 <__floatdidf> */
/* @0xd7a38 mov r12, r6 */
/* @0xd7a3c strd r0, r1, [r6] */
/* @0xd7a40 mov r0, r12 */
/* @0xd7a44 add sp, sp, #32 */
/* @0xd7a48 pop {r4, r5, r6, pc} */
/* @0xd7a4c vldr s15, [r6] */
/* @0xd7a50 vcvt.s32.f32 s15, s15 */
/* @0xd7a54 mov r12, r6 */
/* @0xd7a58 mov r0, r12 */
/* @0xd7a5c vmov r3, s15 */
/* @0xd7a60 mvn r3, r3 */
/* @0xd7a64 vmov s15, r3 */
/* @0xd7a68 vcvt.f32.s32 s15, s15 */
/* @0xd7a6c vstr s15, [r6] */
/* @0xd7a70 add sp, sp, #32 */
/* @0xd7a74 pop {r4, r5, r6, pc} */
/* @0xd7a78 add r4, sp, #16 */
/* @0xd7a7c mov r2, r6 */
/* @0xd7a80 and r1, r1, #15 */
/* @0xd7a84 mov r0, r4 */
/* @0xd7a88 bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xd7a8c ldr r2, [sp, #0x1c] */
/* @0xd7a90 mvn r3, #-16777216 */
/* @0xd7a94 and r2, r2, r3 */
/* @0xd7a98 cmp r2, r3 */
/* @0xd7a9c mov r5, r0 */
/* @0xd7aa0 beq 0xd7bbc <_Z5DoNotjPhPKhP6VMExec+0x2b4> */
/* @0xd7aa4 mov r0, r4 */
/* @0xd7aa8 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0xd7aac sub r12, r5, #4 */
/* @0xd7ab0 eor r0, r0, #1 */
/* @0xd7ab4 uxtb r3, r0 */
/* @0xd7ab8 str r3, [r5, #-0x4] */
/* @0xd7abc b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7ac0 mov r2, r6 */
/* @0xd7ac4 and r1, r1, #15 */
/* @0xd7ac8 mov r0, sp */
/* @0xd7acc bl 0xd7784 <_Z7boxTypeR6RValue8eVM_TypePh> */
/* @0xd7ad0 ldr r2, [sp, #0xc] */
/* @0xd7ad4 mvn r3, #-16777216 */
/* @0xd7ad8 and r2, r2, r3 */
/* @0xd7adc cmp r2, r3 */
/* @0xd7ae0 mov r4, r0 */
/* @0xd7ae4 beq 0xd7bd0 <_Z5DoNotjPhPKhP6VMExec+0x2c8> */
/* @0xd7ae8 mov r1, sp */
/* @0xd7aec add r0, sp, #16 */
/* @0xd7af0 str r3, [sp, #0x1c] */
/* @0xd7af4 mov r2, #0 */
/* @0xd7af8 mov r3, #0 */
/* @0xd7afc mov r12, #0 */
/* @0xd7b00 strd r2, r3, [sp, #16] */
/* @0xd7b04 str r12, [sp, #0x18] */
/* @0xd7b08 bl 0x24d5c8 <_Z12F_JS_ToInt32R6RValueS0_> */
/* @0xd7b0c cmp r0, #1 */
/* @0xd7b10 beq 0xd7bfc <_Z5DoNotjPhPKhP6VMExec+0x2f4> */
/* @0xd7b14 cmp r0, #0 */
/* @0xd7b18 movne r12, r4 */
/* @0xd7b1c bne 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b20 vldr d7, [sp, #16] */
/* @0xd7b24 vcvt.s32.f64 s13, d7 */
/* @0xd7b28 sub r12, r4, #16 */
/* @0xd7b2c str r0, [r4, #-0x4] */
/* @0xd7b30 vmov r2, s13 */
/* @0xd7b34 mvn r2, r2 */
/* @0xd7b38 vmov s15, r2 */
/* @0xd7b3c vcvt.f64.s32 d7, s15 */
/* @0xd7b40 vmov r2, r3, d7 */
/* @0xd7b44 vstr s14, [r4, #-16] */
/* @0xd7b48 str r3, [r4, #-0xc] */
/* @0xd7b4c b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b50 ldr r4, [r6] */
/* @0xd7b54 mov r12, r6 */
/* @0xd7b58 ldr r5, [r6, #0x4] */
/* @0xd7b5c mvn r4, r4 */
/* @0xd7b60 mvn r5, r5 */
/* @0xd7b64 stm r6, {r4, r5} */
/* @0xd7b68 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b6c ldr r1, [pc, #0xa8] */
/* @0xd7b70 mov r0, r3 */
/* @0xd7b74 add r1, pc, r1 */
/* @0xd7b78 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7b7c mov r12, r6 */
/* @0xd7b80 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7b84 ldm r6, {r0, r1} */
/* @0xd7b88 bl 0x3194a0 <__fixdfdi> */
/* @0xd7b8c mvn r0, r0 */
/* @0xd7b90 mvn r1, r1 */
/* @0xd7b94 bl 0x319164 <__floatdidf> */
/* @0xd7b98 mov r12, r6 */
/* @0xd7b9c stm r6, {r0, r1} */
/* @0xd7ba0 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7ba4 ldr r1, [pc, #0x74] */
/* @0xd7ba8 mov r0, r3 */
/* @0xd7bac add r1, pc, r1 */
/* @0xd7bb0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7bb4 mov r12, r6 */
/* @0xd7bb8 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bbc ldr r0, [pc, #0x60] */
/* @0xd7bc0 add r0, pc, r0 */
/* @0xd7bc4 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xd7bc8 mov r12, r5 */
/* @0xd7bcc b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bd0 ldr r0, [pc, #0x50] */
/* @0xd7bd4 add r0, pc, r0 */
/* @0xd7bd8 bl 0x254b04 <_Z21JSThrowReferenceErrorPKc> */
/* @0xd7bdc mov r12, r4 */
/* @0xd7be0 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7be4 ldr r1, [pc, #0x40] */
/* @0xd7be8 mov r0, r3 */
/* @0xd7bec add r1, pc, r1 */
/* @0xd7bf0 bl 0xd4210 <_Z7VMErrorP6VMExecPKcz> */
/* @0xd7bf4 mov r12, r6 */
/* @0xd7bf8 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7bfc ldr r0, [pc, #0x2c] */
/* @0xd7c00 add r0, pc, r0 */
/* @0xd7c04 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0xd7c08 mov r12, r4 */
/* @0xd7c0c b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7c10 mov r12, r6 */
/* @0xd7c14 b 0xd7970 <_Z5DoNotjPhPKhP6VMExec+0x68> */
/* @0xd7c18 eoreq r11, r5, r0, lsl #3 */
/* @0xd7c1c eoreq r11, r5, r8, lsl r0 */
/* @0xd7c20 eoreq r11, r5, r12, lsl r0 */
/* @0xd7c24 eoreq r10, r5, r8, asr #30 */
/* @0xd7c28 eoreq r10, r5, r0, ror #30 */
/* @0xd7c2c .word 0x0025aff8 */
/* @0xd7c30 eoreq r10, r5, r0, ror #30 */

/* ── FUNC 0xd7c34 · YYGML_CallScriptFunction(CInstance*, CInstance*, YYRValue&, int, int, YYRValue**) · size=108 · insn=27 */
/* @0xd7c34 push {r4, r5, r6, r7, lr} */
/* @0xd7c38 sub sp, sp, #12 */
/* @0xd7c3c mov r5, r0 */
/* @0xd7c40 mov r4, r2 */
/* @0xd7c44 ldr r0, [sp, #0x20] */
/* @0xd7c48 mov r7, r1 */
/* @0xd7c4c mov r6, r3 */
/* @0xd7c50 bl 0x1e069c <_Z11Script_Datai> */
/* @0xd7c54 mov r2, #0 */
/* @0xd7c58 str r2, [r4, #0xc] */
/* @0xd7c5c str r2, [r4] */
/* @0xd7c60 str r2, [r4, #0x4] */
/* @0xd7c64 ldr r2, [r0, #0x10] */
/* @0xd7c68 cmp r2, #0 */
/* @0xd7c6c blt 0xd7c94 <_Z24YYGML_CallScriptFunctionP9CInstanceS0_R8YYRValueiiPPS1_+0x60> */
/* @0xd7c70 ldr r12, [r0, #0xc] */
/* @0xd7c74 mov r1, r7 */
/* @0xd7c78 ldr r3, [sp, #0x24] */
/* @0xd7c7c mov r0, r5 */
/* @0xd7c80 mov r2, r4 */
/* @0xd7c84 str r3, [sp] */
/* @0xd7c88 mov r3, r6 */
/* @0xd7c8c ldr r12, [r12, #0x4] */
/* @0xd7c90 blx r12 */
/* @0xd7c94 mov r0, r4 */
/* @0xd7c98 add sp, sp, #12 */
/* @0xd7c9c pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0xd7ca0 · AddActiveInstances(CObjectGM*) · size=96 · insn=24 */
/* @0xd7ca0 push {r4, lr} */
/* @0xd7ca4 ldr r4, [r0, #0xd0] */
/* @0xd7ca8 cmp r4, #0 */
/* @0xd7cac popeq {r4, pc} */
/* @0xd7cb0 ldr r3, [r4, #0x8] */
/* @0xd7cb4 cmp r3, #0 */
/* @0xd7cb8 popeq {r4, pc} */
/* @0xd7cbc ldr r0, [r4, #0x8] */
/* @0xd7cc0 ldr r4, [r4] */
/* @0xd7cc4 cmp r0, #0 */
/* @0xd7cc8 beq 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48> */
/* @0xd7ccc ldrb r3, [r0, #0x68] */
/* @0xd7cd0 cmp r3, #0 */
/* @0xd7cd4 bne 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48> */
/* @0xd7cd8 ldrb r3, [r0, #0x69] */
/* @0xd7cdc cmp r3, #0 */
/* @0xd7ce0 bne 0xd7ce8 <_Z18AddActiveInstancesP9CObjectGM+0x48> */
/* @0xd7ce4 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance> */
/* @0xd7ce8 cmp r4, #0 */
/* @0xd7cec popeq {r4, pc} */
/* @0xd7cf0 ldr r3, [r4, #0x8] */
/* @0xd7cf4 cmp r3, #0 */
/* @0xd7cf8 bne 0xd7cbc <_Z18AddActiveInstancesP9CObjectGM+0x1c> */
/* @0xd7cfc pop {r4, pc} */

/* ── FUNC 0xd7d00 · AddChangingInstances(CObjectGM*) · size=124 · insn=31 */
/* @0xd7d00 push {r4, r5, r6, lr} */
/* @0xd7d04 ldr r5, [pc, #0x6c] */
/* @0xd7d08 ldr r6, [r0, #0x18] */
/* @0xd7d0c ldr r5, [pc, r5] */
/* @0xd7d10 ldr r3, [r5, #0x8] */
/* @0xd7d14 cmp r3, #0 */
/* @0xd7d18 pople {r4, r5, r6, pc} */
/* @0xd7d1c mov r4, #0 */
/* @0xd7d20 b 0xd7d34 <_Z20AddChangingInstancesP9CObjectGM+0x34> */
/* @0xd7d24 ldr r3, [r5, #0x8] */
/* @0xd7d28 add r4, r4, #1 */
/* @0xd7d2c cmp r3, r4 */
/* @0xd7d30 ble 0xd7d74 <_Z20AddChangingInstancesP9CObjectGM+0x74> */
/* @0xd7d34 ldr r3, [r5] */
/* @0xd7d38 ldr r0, [r3, r4, lsl #2] */
/* @0xd7d3c ldr r3, [r0, #0x7c] */
/* @0xd7d40 cmp r6, r3 */
/* @0xd7d44 bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24> */
/* @0xd7d48 ldrb r3, [r0, #0x68] */
/* @0xd7d4c cmp r3, #0 */
/* @0xd7d50 bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24> */
/* @0xd7d54 ldrb r3, [r0, #0x69] */
/* @0xd7d58 cmp r3, #0 */
/* @0xd7d5c bne 0xd7d24 <_Z20AddChangingInstancesP9CObjectGM+0x24> */
/* @0xd7d60 bl 0xd3fd0 <_Z14HandleInstanceP9CInstance> */
/* @0xd7d64 ldr r3, [r5, #0x8] */
/* @0xd7d68 add r4, r4, #1 */
/* @0xd7d6c cmp r3, r4 */
/* @0xd7d70 bgt 0xd7d34 <_Z20AddChangingInstancesP9CObjectGM+0x34> */
/* @0xd7d74 pop {r4, r5, r6, pc} */
/* @0xd7d78 eorseq r5, r1, r4, lsr pc */

/* ── FUNC 0xd7d7c · AddDeactivatingInstances(CObjectGM*) · size=124 · insn=31 */
/* @0xd7d7c push {r4, r5, r6, lr} */
/* @0xd7d80 ldr r5, [pc, #0x6c] */
/* @0xd7d84 ldr r6, [r0, #0x18] */
/* @0xd7d88 ldr r5, [pc, r5] */
/* @0xd7d8c ldr r3, [r5, #0x8] */
/* @0xd7d90 cmp r3, #0 */
/* @0xd7d94 pople {r4, r5, r6, pc} */
/* @0xd7d98 mov r4, #0 */
/* @0xd7d9c b 0xd7db0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x34> */
/* @0xd7da0 ldr r3, [r5, #0x8] */
/* @0xd7da4 add r4, r4, #1 */
/* @0xd7da8 cmp r3, r4 */
/* @0xd7dac ble 0xd7df0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x74> */
/* @0xd7db0 ldr r3, [r5] */
/* @0xd7db4 ldr r0, [r3, r4, lsl #2] */
/* @0xd7db8 ldr r3, [r0, #0x7c] */
/* @0xd7dbc cmp r6, r3 */
/* @0xd7dc0 bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24> */
/* @0xd7dc4 ldrb r3, [r0, #0x68] */
/* @0xd7dc8 cmp r3, #0 */
/* @0xd7dcc bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24> */
/* @0xd7dd0 ldrb r3, [r0, #0x69] */
/* @0xd7dd4 cmp r3, #0 */
/* @0xd7dd8 bne 0xd7da0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x24> */
/* @0xd7ddc bl 0xd3fd0 <_Z14HandleInstanceP9CInstance> */
/* @0xd7de0 ldr r3, [r5, #0x8] */
/* @0xd7de4 add r4, r4, #1 */
/* @0xd7de8 cmp r3, r4 */
/* @0xd7dec bgt 0xd7db0 <_Z24AddDeactivatingInstancesP9CObjectGM+0x34> */
/* @0xd7df0 pop {r4, r5, r6, pc} */
/* @0xd7df4 eorseq r5, r1, r0, asr #29 */

/* ── FUNC 0xd7df8 · YYGML_NewWithIteratorEx(SWithIterator*, YYObjectBase**, YYObjectBase**, int) · size=352 · insn=88 */
/* @0xd7df8 ldr r12, [pc, #0x14c] */
/* @0xd7dfc push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xd7e00 ldr r12, [pc, r12] */
/* @0xd7e04 mov r10, r2 */
/* @0xd7e08 mov r6, r1 */
/* @0xd7e0c ldr r2, [r12] */
/* @0xd7e10 mov r5, r0 */
/* @0xd7e14 ldr r1, [r2, #0x4] */
/* @0xd7e18 ldr r2, [r2] */
/* @0xd7e1c and r1, r3, r1 */
/* @0xd7e20 ldr r12, [r2, r1, lsl #3] */
/* @0xd7e24 cmp r12, #0 */
/* @0xd7e28 beq 0xd7e54 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd7e2c ldr r2, [r12, #0x8] */
/* @0xd7e30 cmp r3, r2 */
/* @0xd7e34 bne 0xd7e48 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x50> */
/* @0xd7e38 b 0xd7e60 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x68> */
/* @0xd7e3c ldr r4, [r12, #0x8] */
/* @0xd7e40 cmp r3, r4 */
/* @0xd7e44 beq 0xd7e60 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x68> */
/* @0xd7e48 ldr r12, [r12, #0x4] */
/* @0xd7e4c cmp r12, #0 */
/* @0xd7e50 bne 0xd7e3c <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x44> */
/* @0xd7e54 mov r8, r12 */
/* @0xd7e58 mov r0, r8 */
/* @0xd7e5c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd7e60 ldr r8, [r12, #0xc] */
/* @0xd7e64 cmp r8, #0 */
/* @0xd7e68 beq 0xd7e58 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x60> */
/* @0xd7e6c bl 0xd3edc <_Z26InitialiseHandledContainerv> */
/* @0xd7e70 bl 0xd3ee0 <_Z21ClearHandledContainerv> */
/* @0xd7e74 mov r0, r8 */
/* @0xd7e78 bl 0xd7ca0 <_Z18AddActiveInstancesP9CObjectGM> */
/* @0xd7e7c mov r0, r8 */
/* @0xd7e80 bl 0xd7d00 <_Z20AddChangingInstancesP9CObjectGM> */
/* @0xd7e84 mov r0, r8 */
/* @0xd7e88 bl 0xd7d7c <_Z24AddDeactivatingInstancesP9CObjectGM> */
/* @0xd7e8c bl 0xd40d8 <_Z14CountInstancesv> */
/* @0xd7e90 subs r8, r0, #0 */
/* @0xd7e94 ble 0xd7e58 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x60> */
/* @0xd7e98 ldr r1, [pc, #0xb0] */
/* @0xd7e9c mov r3, #1 */
/* @0xd7ea0 lsl r0, r8, #2 */
/* @0xd7ea4 movw r2, #0x20db */
/* @0xd7ea8 add r1, pc, r1 */
/* @0xd7eac ldr r7, [pc, #0xa0] */
/* @0xd7eb0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd7eb4 ldr r3, [r5] */
/* @0xd7eb8 add r7, pc, r7 */
/* @0xd7ebc str r0, [r5, #0x8] */
/* @0xd7ec0 mov r9, r0 */
/* @0xd7ec4 str r3, [r10] */
/* @0xd7ec8 ldr r3, [r7] */
/* @0xd7ecc cmp r3, r7 */
/* @0xd7ed0 beq 0xd7f44 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x14c> */
/* @0xd7ed4 mov r1, #0 */
/* @0xd7ed8 mov r2, r0 */
/* @0xd7edc mov r10, r7 */
/* @0xd7ee0 mov r0, r1 */
/* @0xd7ee4 ldr r4, [r7, #0x8] */
/* @0xd7ee8 str r1, [r2], #4 */
/* @0xd7eec mov r9, r2 */
/* @0xd7ef0 rsb r4, r4, r3 */
/* @0xd7ef4 ldr r3, [r3] */
/* @0xd7ef8 add lr, r4, #420 */
/* @0xd7efc ldr r12, [r4, #0x1ac] */
/* @0xd7f00 mov r1, r4 */
/* @0xd7f04 cmp r12, r7 */
/* @0xd7f08 ldreq r11, [r4, #0x1a8] */
/* @0xd7f0c ldreq r12, [r4, #0x1a4] */
/* @0xd7f10 streq r11, [r12, #0x4] */
/* @0xd7f14 ldreq r11, [r4, #0x1a8] */
/* @0xd7f18 streq r12, [r11] */
/* @0xd7f1c cmp r3, r10 */
/* @0xd7f20 str lr, [r4, #0x1a4] */
/* @0xd7f24 str lr, [r4, #0x1a8] */
/* @0xd7f28 str r0, [r4, #0x1ac] */
/* @0xd7f2c bne 0xd7ee4 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0xec> */
/* @0xd7f30 bl 0xd3ee0 <_Z21ClearHandledContainerv> */
/* @0xd7f34 str r4, [r6] */
/* @0xd7f38 mov r0, r8 */
/* @0xd7f3c str r9, [r5, #0xc] */
/* @0xd7f40 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xd7f44 mov r4, #0 */
/* @0xd7f48 b 0xd7f30 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i+0x138> */
/* @0xd7f4c eorseq r5, r1, r12, lsr lr */
/* @0xd7f50 .word 0x0025a8d4 */
/* @0xd7f54 ldrshteq r2, [r10], -r12 */

/* ── FUNC 0xd7f58 · YYGML_NewWithIterator(SWithIterator*, YYObjectBase**, YYObjectBase**, int) · size=672 · insn=168 */
/* @0xd7f58 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xd7f5c mov r4, r0 */
/* @0xd7f60 ldr r0, [r1] */
/* @0xd7f64 mov r8, r2 */
/* @0xd7f68 add r2, r3, #7 */
/* @0xd7f6c mov r7, r1 */
/* @0xd7f70 mov r1, #0 */
/* @0xd7f74 str r0, [r4] */
/* @0xd7f78 ldr r0, [r8] */
/* @0xd7f7c str r1, [r4, #0x8] */
/* @0xd7f80 str r1, [r4, #0xc] */
/* @0xd7f84 str r0, [r4, #0x4] */
/* @0xd7f88 cmp r2, #6 */
/* @0xd7f8c addls pc, pc, r2, lsl #2 */
/* @0xd7f90 b 0xd8108 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1b0> */
/* @0xd7f94 b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58> */
/* @0xd7f98 b 0xd80c4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x16c> */
/* @0xd7f9c b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58> */
/* @0xd7fa0 b 0xd7fb0 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x58> */
/* @0xd7fa4 b 0xd8008 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xb0> */
/* @0xd7fa8 b 0xd7fbc <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x64> */
/* @0xd7fac b 0xd80c4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x16c> */
/* @0xd7fb0 mvn r6, #0 */
/* @0xd7fb4 mov r0, r6 */
/* @0xd7fb8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd7fbc ldr r1, [pc, #0x21c] */
/* @0xd7fc0 movw r2, #0x2125 */
/* @0xd7fc4 mov r3, #1 */
/* @0xd7fc8 mov r0, #4 */
/* @0xd7fcc add r1, pc, r1 */
/* @0xd7fd0 mov r6, #1 */
/* @0xd7fd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd7fd8 mov r3, #0 */
/* @0xd7fdc str r0, [r4, #0x8] */
/* @0xd7fe0 str r3, [r0] */
/* @0xd7fe4 mov r0, r6 */
/* @0xd7fe8 ldr r3, [r4, #0x4] */
/* @0xd7fec ldr r2, [r4, #0x8] */
/* @0xd7ff0 add r2, r2, #4 */
/* @0xd7ff4 str r2, [r4, #0xc] */
/* @0xd7ff8 str r3, [r7] */
/* @0xd7ffc ldr r3, [r4] */
/* @0xd8000 str r3, [r8] */
/* @0xd8004 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd8008 ldr r9, [pc, #0x1d4] */
/* @0xd800c ldr r9, [pc, r9] */
/* @0xd8010 ldr r3, [r9] */
/* @0xd8014 ldr r3, [r3, #0x80] */
/* @0xd8018 cmp r3, #0 */
/* @0xd801c beq 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc> */
/* @0xd8020 mov r6, #0 */
/* @0xd8024 ldrb r0, [r3, #0x68] */
/* @0xd8028 ldr r5, [r3, #0x178] */
/* @0xd802c cmp r0, #0 */
/* @0xd8030 bne 0xd8040 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xe8> */
/* @0xd8034 ldrb r3, [r3, #0x69] */
/* @0xd8038 cmp r3, #0 */
/* @0xd803c addeq r6, r6, #1 */
/* @0xd8040 cmp r5, #0 */
/* @0xd8044 mov r3, r5 */
/* @0xd8048 bne 0xd8024 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0xcc> */
/* @0xd804c cmp r6, #0 */
/* @0xd8050 beq 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd8054 ldr r1, [pc, #0x18c] */
/* @0xd8058 mov r3, #1 */
/* @0xd805c lsl r0, r6, #2 */
/* @0xd8060 movw r2, #0x2141 */
/* @0xd8064 add r1, pc, r1 */
/* @0xd8068 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd806c ldr r3, [r4] */
/* @0xd8070 str r0, [r4, #0x8] */
/* @0xd8074 str r3, [r8] */
/* @0xd8078 ldr r3, [r9] */
/* @0xd807c ldr r3, [r3, #0x80] */
/* @0xd8080 cmp r3, #0 */
/* @0xd8084 beq 0xd80b4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x15c> */
/* @0xd8088 ldrb r1, [r3, #0x68] */
/* @0xd808c ldr r2, [r3, #0x178] */
/* @0xd8090 cmp r1, #0 */
/* @0xd8094 bne 0xd80a8 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x150> */
/* @0xd8098 ldrb r1, [r3, #0x69] */
/* @0xd809c cmp r1, #0 */
/* @0xd80a0 streq r5, [r0], #4 */
/* @0xd80a4 moveq r5, r3 */
/* @0xd80a8 cmp r2, #0 */
/* @0xd80ac mov r3, r2 */
/* @0xd80b0 bne 0xd8088 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x130> */
/* @0xd80b4 str r5, [r7] */
/* @0xd80b8 str r0, [r4, #0xc] */
/* @0xd80bc mov r0, r6 */
/* @0xd80c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd80c4 ldr r1, [pc, #0x120] */
/* @0xd80c8 movw r2, #0x211b */
/* @0xd80cc mov r3, #1 */
/* @0xd80d0 mov r0, #4 */
/* @0xd80d4 add r1, pc, r1 */
/* @0xd80d8 mov r6, #1 */
/* @0xd80dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd80e0 mov r3, #0 */
/* @0xd80e4 str r0, [r4, #0x8] */
/* @0xd80e8 str r3, [r0] */
/* @0xd80ec mov r0, r6 */
/* @0xd80f0 ldr r3, [r4] */
/* @0xd80f4 ldr r2, [r4, #0x8] */
/* @0xd80f8 add r2, r2, #4 */
/* @0xd80fc str r2, [r4, #0xc] */
/* @0xd8100 str r3, [r8] */
/* @0xd8104 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd8108 cmp r3, #0 */
/* @0xd810c blt 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc> */
/* @0xd8110 movw r2, #0x869f */
/* @0xd8114 movt r2, #0x1 */
/* @0xd8118 cmp r3, r2 */
/* @0xd811c bgt 0xd8140 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1e8> */
/* @0xd8120 mov r0, r4 */
/* @0xd8124 mov r1, r7 */
/* @0xd8128 mov r2, r8 */
/* @0xd812c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xd8130 b 0xd7df8 <_Z23YYGML_NewWithIteratorExP13SWithIteratorPP12YYObjectBaseS3_i> */
/* @0xd8134 mov r6, #0 */
/* @0xd8138 mov r0, r6 */
/* @0xd813c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xd8140 ldr r2, [pc, #0xa8] */
/* @0xd8144 ldr r2, [pc, r2] */
/* @0xd8148 ldr r1, [r2, #0x4] */
/* @0xd814c ldr r2, [r2] */
/* @0xd8150 and r1, r3, r1 */
/* @0xd8154 ldr r6, [r2, r1, lsl #3] */
/* @0xd8158 cmp r6, #0 */
/* @0xd815c bne 0xd8170 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x218> */
/* @0xd8160 b 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd8164 ldr r6, [r6, #0x4] */
/* @0xd8168 cmp r6, #0 */
/* @0xd816c beq 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd8170 ldr r2, [r6, #0x8] */
/* @0xd8174 cmp r3, r2 */
/* @0xd8178 bne 0xd8164 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x20c> */
/* @0xd817c ldr r5, [r6, #0xc] */
/* @0xd8180 cmp r5, #0 */
/* @0xd8184 beq 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc> */
/* @0xd8188 ldrb r6, [r5, #0x68] */
/* @0xd818c cmp r6, #0 */
/* @0xd8190 bne 0xd8134 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x1dc> */
/* @0xd8194 ldrb r9, [r5, #0x69] */
/* @0xd8198 cmp r9, #0 */
/* @0xd819c bne 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd81a0 ldr r1, [pc, #0x4c] */
/* @0xd81a4 movw r2, #0x2178 */
/* @0xd81a8 mov r3, #1 */
/* @0xd81ac mov r0, #4 */
/* @0xd81b0 add r1, pc, r1 */
/* @0xd81b4 mov r6, #1 */
/* @0xd81b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xd81bc str r0, [r4, #0x8] */
/* @0xd81c0 str r9, [r0] */
/* @0xd81c4 ldr r3, [r4] */
/* @0xd81c8 ldr r2, [r4, #0x8] */
/* @0xd81cc add r2, r2, #4 */
/* @0xd81d0 str r2, [r4, #0xc] */
/* @0xd81d4 str r3, [r8] */
/* @0xd81d8 str r5, [r7] */
/* @0xd81dc b 0xd7fb4 <_Z21YYGML_NewWithIteratorP13SWithIteratorPP12YYObjectBaseS3_i+0x5c> */
/* @0xd81e0 .word 0x0025a7b0 */
/* @0xd81e4 eorseq r5, r1, r12, lsl r9 */
/* @0xd81e8 eoreq r10, r5, r8, lsl r7 */
/* @0xd81ec eoreq r10, r5, r8, lsr #13 */
/* @0xd81f0 eorseq r5, r1, r0, lsl #22 */
/* @0xd81f4 eoreq r10, r5, r12, asr #11 */

/* ── FUNC 0xd81f8 · YYGML_WithIteratorNext(SWithIterator*, YYObjectBase**, YYObjectBase**) · size=56 · insn=14 */
/* @0xd81f8 ldr r3, [r0, #0x8] */
/* @0xd81fc cmp r3, #0 */
/* @0xd8200 beq 0xd8228 <_Z22YYGML_WithIteratorNextP13SWithIteratorPP12YYObjectBaseS3_+0x30> */
/* @0xd8204 ldr r3, [r0, #0xc] */
/* @0xd8208 sub r2, r3, #4 */
/* @0xd820c str r2, [r0, #0xc] */
/* @0xd8210 ldr r3, [r3, #-0x4] */
/* @0xd8214 cmp r3, #0 */
/* @0xd8218 beq 0xd8228 <_Z22YYGML_WithIteratorNextP13SWithIteratorPP12YYObjectBaseS3_+0x30> */
/* @0xd821c mov r0, #1 */
/* @0xd8220 str r3, [r1] */
/* @0xd8224 bx lr */
/* @0xd8228 mov r0, #0 */
/* @0xd822c bx lr */

/* ── FUNC 0xd8230 · YYGML_DeleteWithIterator(SWithIterator*, YYObjectBase**, YYObjectBase**) · size=60 · insn=15 */
/* @0xd8230 push {r4, r5, r6, lr} */
/* @0xd8234 mov r4, r0 */
/* @0xd8238 ldr r0, [r0, #0x8] */
/* @0xd823c mov r5, r1 */
/* @0xd8240 mov r6, r2 */
/* @0xd8244 cmp r0, #0 */
/* @0xd8248 beq 0xd8258 <_Z24YYGML_DeleteWithIteratorP13SWithIteratorPP12YYObjectBaseS3_+0x28> */
/* @0xd824c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xd8250 mov r3, #0 */
/* @0xd8254 str r3, [r4, #0x8] */
/* @0xd8258 ldr r3, [r4] */
/* @0xd825c str r3, [r5] */
/* @0xd8260 ldr r3, [r4, #0x4] */
/* @0xd8264 str r3, [r6] */
/* @0xd8268 pop {r4, r5, r6, pc} */

/* ── FUNC 0xd826c · VM::Quit() · size=4 · insn=1 */
/* @0xd826c bx lr */

/* ── FUNC 0xd8270 · VM::SetBreakpoint(unsigned int*, unsigned int, unsigned char*) · size=124 · insn=31 */
/* @0xd8270 push {r4, r5} */
/* @0xd8274 mov r3, #0 */
/* @0xd8278 ldr r4, [pc, #0x68] */
/* @0xd827c ldr r4, [pc, r4] */
/* @0xd8280 b 0xd828c <_ZN2VM13SetBreakpointEPjjPh+0x1c> */
/* @0xd8284 cmp r3, #4080 */
/* @0xd8288 beq 0xd82a8 <_ZN2VM13SetBreakpointEPjjPh+0x38> */
/* @0xd828c add r12, r4, r3 */
/* @0xd8290 add r3, r3, #16 */
/* @0xd8294 ldr r12, [r12, #0x4] */
/* @0xd8298 cmp r12, r0 */
/* @0xd829c bne 0xd8284 <_ZN2VM13SetBreakpointEPjjPh+0x14> */
/* @0xd82a0 pop {r4, r5} */
/* @0xd82a4 bx lr */
/* @0xd82a8 mov r3, #0 */
/* @0xd82ac b 0xd82bc <_ZN2VM13SetBreakpointEPjjPh+0x4c> */
/* @0xd82b0 add r3, r3, #1 */
/* @0xd82b4 cmp r3, #255 */
/* @0xd82b8 beq 0xd82a0 <_ZN2VM13SetBreakpointEPjjPh+0x30> */
/* @0xd82bc add r12, r4, r3, lsl #4 */
/* @0xd82c0 ldr r5, [r12, #0x4] */
/* @0xd82c4 cmn r5, #1 */
/* @0xd82c8 bne 0xd82b0 <_ZN2VM13SetBreakpointEPjjPh+0x40> */
/* @0xd82cc str r1, [r12, #0x8] */
/* @0xd82d0 ldr r1, [r0] */
/* @0xd82d4 str r0, [r12, #0x4] */
/* @0xd82d8 str r2, [r12, #0xc] */
/* @0xd82dc str r1, [r4, r3, lsl #4] */
/* @0xd82e0 pop {r4, r5} */
/* @0xd82e4 bx lr */
/* @0xd82e8 eorseq r5, r1, r8, ror #20 */

/* ── FUNC 0xd82ec · VM::GetBreakpoint(unsigned int*) · size=64 · insn=16 */
/* @0xd82ec ldr r12, [pc, #0x34] */
/* @0xd82f0 mov r3, #0 */
/* @0xd82f4 ldr r12, [pc, r12] */
/* @0xd82f8 b 0xd8304 <_ZN2VM13GetBreakpointEPj+0x18> */
/* @0xd82fc cmp r3, #255 */
/* @0xd8300 beq 0xd8320 <_ZN2VM13GetBreakpointEPj+0x34> */
/* @0xd8304 add r2, r12, r3, lsl #4 */
/* @0xd8308 add r3, r3, #1 */
/* @0xd830c ldr r1, [r2, #0x4] */
/* @0xd8310 cmp r1, r0 */
/* @0xd8314 bne 0xd82fc <_ZN2VM13GetBreakpointEPj+0x10> */
/* @0xd8318 mov r0, r2 */
/* @0xd831c bx lr */
/* @0xd8320 mov r0, #0 */
/* @0xd8324 bx lr */
/* @0xd8328 ldrshteq r5, [r1], -r0 */

/* ── FUNC 0xd832c · VM::ClearBreakpoint(unsigned int*) · size=72 · insn=18 */
/* @0xd832c ldr r12, [pc, #0x3c] */
/* @0xd8330 mov r3, #0 */
/* @0xd8334 ldr r12, [pc, r12] */
/* @0xd8338 b 0xd8348 <_ZN2VM15ClearBreakpointEPj+0x1c> */
/* @0xd833c add r3, r3, #1 */
/* @0xd8340 cmp r3, #255 */
/* @0xd8344 beq 0xd836c <_ZN2VM15ClearBreakpointEPj+0x40> */
/* @0xd8348 add r2, r12, r3, lsl #4 */
/* @0xd834c ldr r1, [r2, #0x4] */
/* @0xd8350 cmp r1, r0 */
/* @0xd8354 bne 0xd833c <_ZN2VM15ClearBreakpointEPj+0x10> */
/* @0xd8358 mvn r0, #0 */
/* @0xd835c mov r1, #0 */
/* @0xd8360 str r0, [r2, #0x4] */
/* @0xd8364 str r1, [r12, r3, lsl #4] */
/* @0xd8368 bx lr */
/* @0xd836c bx lr */
/* @0xd8370 ldrhteq r5, [r1], -r0 */

/* ── FUNC 0xd8374 · VM::ResetBreakpoints() · size=52 · insn=13 */
/* @0xd8374 ldr r2, [pc, #0x28] */
/* @0xd8378 mov r3, #0 */
/* @0xd837c mov r12, r3 */
/* @0xd8380 mvn r0, #0 */
/* @0xd8384 ldr r2, [pc, r2] */
/* @0xd8388 add r1, r2, r3 */
/* @0xd838c str r0, [r1, #0x4] */
/* @0xd8390 str r12, [r2, r3] */
/* @0xd8394 add r3, r3, #16 */
/* @0xd8398 cmp r3, #4096 */
/* @0xd839c bne 0xd8388 <_ZN2VM16ResetBreakpointsEv+0x14> */
/* @0xd83a0 bx lr */
/* @0xd83a4 eorseq r5, r1, r0, ror #18 */
