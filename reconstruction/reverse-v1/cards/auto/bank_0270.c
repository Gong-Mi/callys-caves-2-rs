/* libyoyo.so 覆盖卡组 0270
 * 函数 0x2c7810..0x2c901c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2c7810 · b2ContactFilter::~b2ContactFilter() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c7828 · b2ContactFilter::~b2ContactFilter() · size=40 · insn=10 */
/* @0x2c7828 ldr r3, [pc, #0x1c] */
/* @0x2c782c push {r4, lr} */
/* @0x2c7830 ldr r3, [pc, r3] */
/* @0x2c7834 mov r4, r0 */
/* @0x2c7838 add r3, r3, #8 */
/* @0x2c783c str r3, [r0] */
/* @0x2c7840 bl 0x27d1d0 <_ZdlPv> */
/* @0x2c7844 mov r0, r4 */
/* @0x2c7848 pop {r4, pc} */
/* @0x2c784c ldrheq r10, [r2], -r0 */

/* ── FUNC 0x2c7850 · b2ContactManager::b2ContactManager() · size=68 · insn=17 */
/* @0x2c7850 push {r4, lr} */
/* @0x2c7854 mov r4, r0 */
/* @0x2c7858 bl 0x2dc7ac <_ZN12b2BroadPhaseC2Ev> */
/* @0x2c785c ldr r1, [pc, #0x28] */
/* @0x2c7860 mov r3, #0 */
/* @0x2c7864 ldr r2, [pc, #0x24] */
/* @0x2c7868 mov r0, r4 */
/* @0x2c786c ldr r1, [pc, r1] */
/* @0x2c7870 str r3, [r4, #0x3c] */
/* @0x2c7874 ldr r2, [pc, r2] */
/* @0x2c7878 str r1, [r4, #0x44] */
/* @0x2c787c str r3, [r4, #0x40] */
/* @0x2c7880 str r2, [r4, #0x48] */
/* @0x2c7884 str r3, [r4, #0x4c] */
/* @0x2c7888 pop {r4, pc} */
/* @0x2c788c andseq r10, r2, r8, ror r2 */
/* @0x2c7890 andseq r10, r2, r4, ror r2 */

/* ── FUNC 0x2c7850 · b2ContactManager::b2ContactManager() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c7894 · b2ContactManager::Destroy(b2Contact*) · size=220 · insn=55 */
/* @0x2c7894 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c7898 mov r5, r0 */
/* @0x2c789c ldr r0, [r0, #0x48] */
/* @0x2c78a0 mov r4, r1 */
/* @0x2c78a4 ldr r2, [r1, #0x30] */
/* @0x2c78a8 ldr r3, [r1, #0x34] */
/* @0x2c78ac cmp r0, #0 */
/* @0x2c78b0 ldr r7, [r2, #0x8] */
/* @0x2c78b4 ldr r6, [r3, #0x8] */
/* @0x2c78b8 beq 0x2c78d4 <_ZN16b2ContactManager7DestroyEP9b2Contact+0x40> */
/* @0x2c78bc ldr r3, [r1, #0x4] */
/* @0x2c78c0 tst r3, #2 */
/* @0x2c78c4 beq 0x2c78d4 <_ZN16b2ContactManager7DestroyEP9b2Contact+0x40> */
/* @0x2c78c8 ldr r3, [r0] */
/* @0x2c78cc ldr r3, [r3, #0xc] */
/* @0x2c78d0 blx r3 */
/* @0x2c78d4 ldr r3, [r4, #0x8] */
/* @0x2c78d8 mov r0, r4 */
/* @0x2c78dc ldr r1, [r7, #0x80] */
/* @0x2c78e0 cmp r3, #0 */
/* @0x2c78e4 ldrne r2, [r4, #0xc] */
/* @0x2c78e8 strne r2, [r3, #0xc] */
/* @0x2c78ec ldr r2, [r4, #0xc] */
/* @0x2c78f0 cmp r2, #0 */
/* @0x2c78f4 strne r3, [r2, #0x8] */
/* @0x2c78f8 ldr r3, [r5, #0x3c] */
/* @0x2c78fc cmp r3, r4 */
/* @0x2c7900 ldr r3, [r4, #0x18] */
/* @0x2c7904 streq r2, [r5, #0x3c] */
/* @0x2c7908 cmp r3, #0 */
/* @0x2c790c ldrne r2, [r4, #0x1c] */
/* @0x2c7910 strne r2, [r3, #0xc] */
/* @0x2c7914 ldr r2, [r4, #0x1c] */
/* @0x2c7918 cmp r2, #0 */
/* @0x2c791c strne r3, [r2, #0x8] */
/* @0x2c7920 add r3, r4, #16 */
/* @0x2c7924 cmp r1, r3 */
/* @0x2c7928 ldr r3, [r4, #0x28] */
/* @0x2c792c streq r2, [r7, #0x80] */
/* @0x2c7930 cmp r3, #0 */
/* @0x2c7934 ldr r1, [r6, #0x80] */
/* @0x2c7938 ldrne r2, [r4, #0x2c] */
/* @0x2c793c strne r2, [r3, #0xc] */
/* @0x2c7940 ldr r2, [r4, #0x2c] */
/* @0x2c7944 cmp r2, #0 */
/* @0x2c7948 strne r3, [r2, #0x8] */
/* @0x2c794c add r3, r4, #32 */
/* @0x2c7950 cmp r1, r3 */
/* @0x2c7954 ldr r1, [r5, #0x4c] */
/* @0x2c7958 streq r2, [r6, #0x80] */
/* @0x2c795c bl 0x2cc07c <_ZN9b2Contact7DestroyEPS_P16b2BlockAllocator> */
/* @0x2c7960 ldr r3, [r5, #0x40] */
/* @0x2c7964 sub r3, r3, #1 */
/* @0x2c7968 str r3, [r5, #0x40] */
/* @0x2c796c pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c7970 · b2ContactManager::Collide() · size=408 · insn=102 */
/* @0x2c7970 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c7974 mov r9, r0 */
/* @0x2c7978 ldr r4, [r0, #0x3c] */
/* @0x2c797c cmp r4, #0 */
/* @0x2c7980 bne 0x2c7a14 <_ZN16b2ContactManager7CollideEv+0xa4> */
/* @0x2c7984 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c7988 ldr r2, [r6] */
/* @0x2c798c cmp r2, #0 */
/* @0x2c7990 beq 0x2c7a64 <_ZN16b2ContactManager7CollideEv+0xf4> */
/* @0x2c7994 ldr r2, [r7, #0x18] */
/* @0x2c7998 rsb r10, r10, r10, lsl #3 */
/* @0x2c799c ldr r3, [r8, #0x18] */
/* @0x2c79a0 rsb r11, r11, r11, lsl #3 */
/* @0x2c79a4 add r10, r2, r10, lsl #2 */
/* @0x2c79a8 ldr r1, [r9, #0x4] */
/* @0x2c79ac add r11, r3, r11, lsl #2 */
/* @0x2c79b0 ldr r2, [r10, #0x18] */
/* @0x2c79b4 ldr r3, [r11, #0x18] */
/* @0x2c79b8 add r2, r2, r2, lsl #3 */
/* @0x2c79bc add r3, r3, r3, lsl #3 */
/* @0x2c79c0 add r2, r1, r2, lsl #2 */
/* @0x2c79c4 vldr s15, [r2, #8] */
/* @0x2c79c8 add r3, r1, r3, lsl #2 */
/* @0x2c79cc vldr s14, [r3] */
/* @0x2c79d0 vsub.f32 s15, s14, s15 */
/* @0x2c79d4 vldr s13, [r3, #4] */
/* @0x2c79d8 vldr s14, [r2, #12] */
/* @0x2c79dc vldr s11, [r2] */
/* @0x2c79e0 vldr s12, [r3, #8] */
/* @0x2c79e4 vldr s9, [r2, #4] */
/* @0x2c79e8 vldr s10, [r3, #12] */
/* @0x2c79ec vcmpe.f32 s15, #0 */
/* @0x2c79f0 vmrs APSR_nzcv, fpscr */
/* @0x2c79f4 ble 0x2c7ac8 <_ZN16b2ContactManager7CollideEv+0x158> */
/* @0x2c79f8 ldr r5, [r4, #0xc] */
/* @0x2c79fc mov r1, r4 */
/* @0x2c7a00 mov r0, r9 */
/* @0x2c7a04 bl 0x2c7894 <_ZN16b2ContactManager7DestroyEP9b2Contact> */
/* @0x2c7a08 mov r4, r5 */
/* @0x2c7a0c cmp r4, #0 */
/* @0x2c7a10 beq 0x2c7a78 <_ZN16b2ContactManager7CollideEv+0x108> */
/* @0x2c7a14 ldr r3, [r4, #0x4] */
/* @0x2c7a18 ldr r7, [r4, #0x30] */
/* @0x2c7a1c ldr r8, [r4, #0x34] */
/* @0x2c7a20 tst r3, #8 */
/* @0x2c7a24 ldr r10, [r4, #0x38] */
/* @0x2c7a28 ldr r5, [r7, #0x8] */
/* @0x2c7a2c ldr r6, [r8, #0x8] */
/* @0x2c7a30 ldr r11, [r4, #0x3c] */
/* @0x2c7a34 bne 0x2c7a7c <_ZN16b2ContactManager7CollideEv+0x10c> */
/* @0x2c7a38 ldrh r3, [r5, #4] */
/* @0x2c7a3c and r3, r3, #2 */
/* @0x2c7a40 uxth r3, r3 */
/* @0x2c7a44 cmp r3, #0 */
/* @0x2c7a48 beq 0x2c7a58 <_ZN16b2ContactManager7CollideEv+0xe8> */
/* @0x2c7a4c ldr r3, [r5] */
/* @0x2c7a50 adds r3, r3, #0 */
/* @0x2c7a54 movne r3, #1 */
/* @0x2c7a58 ldrh r2, [r6, #4] */
/* @0x2c7a5c tst r2, #2 */
/* @0x2c7a60 bne 0x2c7988 <_ZN16b2ContactManager7CollideEv+0x18> */
/* @0x2c7a64 cmp r3, #0 */
/* @0x2c7a68 bne 0x2c7994 <_ZN16b2ContactManager7CollideEv+0x24> */
/* @0x2c7a6c ldr r4, [r4, #0xc] */
/* @0x2c7a70 cmp r4, #0 */
/* @0x2c7a74 bne 0x2c7a14 <_ZN16b2ContactManager7CollideEv+0xa4> */
/* @0x2c7a78 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c7a7c mov r0, r6 */
/* @0x2c7a80 mov r1, r5 */
/* @0x2c7a84 bl 0x2c7158 <_ZNK6b2Body13ShouldCollideEPKS_> */
/* @0x2c7a88 cmp r0, #0 */
/* @0x2c7a8c beq 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88> */
/* @0x2c7a90 ldr r0, [r9, #0x44] */
/* @0x2c7a94 cmp r0, #0 */
/* @0x2c7a98 beq 0x2c7ab8 <_ZN16b2ContactManager7CollideEv+0x148> */
/* @0x2c7a9c ldr r3, [r0] */
/* @0x2c7aa0 mov r1, r7 */
/* @0x2c7aa4 mov r2, r8 */
/* @0x2c7aa8 ldr r3, [r3, #0x8] */
/* @0x2c7aac blx r3 */
/* @0x2c7ab0 cmp r0, #0 */
/* @0x2c7ab4 beq 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88> */
/* @0x2c7ab8 ldr r3, [r4, #0x4] */
/* @0x2c7abc bic r3, r3, #8 */
/* @0x2c7ac0 str r3, [r4, #0x4] */
/* @0x2c7ac4 b 0x2c7a38 <_ZN16b2ContactManager7CollideEv+0xc8> */
/* @0x2c7ac8 vsub.f32 s14, s13, s14 */
/* @0x2c7acc vcmpe.f32 s14, #0 */
/* @0x2c7ad0 vmrs APSR_nzcv, fpscr */
/* @0x2c7ad4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88> */
/* @0x2c7ad8 vsub.f32 s12, s11, s12 */
/* @0x2c7adc vcmpe.f32 s12, #0 */
/* @0x2c7ae0 vmrs APSR_nzcv, fpscr */
/* @0x2c7ae4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88> */
/* @0x2c7ae8 vsub.f32 s10, s9, s10 */
/* @0x2c7aec vcmpe.f32 s10, #0 */
/* @0x2c7af0 vmrs APSR_nzcv, fpscr */
/* @0x2c7af4 bgt 0x2c79f8 <_ZN16b2ContactManager7CollideEv+0x88> */
/* @0x2c7af8 mov r0, r4 */
/* @0x2c7afc ldr r1, [r9, #0x48] */
/* @0x2c7b00 bl 0x2cc1ec <_ZN9b2Contact6UpdateEP17b2ContactListener> */
/* @0x2c7b04 b 0x2c7a6c <_ZN16b2ContactManager7CollideEv+0xfc> */

/* ── FUNC 0x2c7b08 · b2ContactManager::AddPair(void*, void*) · size=460 · insn=115 */
/* @0x2c7b08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c7b0c mov r9, r0 */
/* @0x2c7b10 ldr r7, [r1, #0x10] */
/* @0x2c7b14 sub sp, sp, #12 */
/* @0x2c7b18 ldr r6, [r2, #0x10] */
/* @0x2c7b1c ldr r10, [r1, #0x14] */
/* @0x2c7b20 ldr r1, [r7, #0x8] */
/* @0x2c7b24 ldr r0, [r6, #0x8] */
/* @0x2c7b28 ldr r8, [r2, #0x14] */
/* @0x2c7b2c cmp r1, r0 */
/* @0x2c7b30 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94> */
/* @0x2c7b34 ldr r12, [r0, #0x80] */
/* @0x2c7b38 cmp r12, #0 */
/* @0x2c7b3c bne 0x2c7b50 <_ZN16b2ContactManager7AddPairEPvS0_+0x48> */
/* @0x2c7b40 b 0x2c7ba4 <_ZN16b2ContactManager7AddPairEPvS0_+0x9c> */
/* @0x2c7b44 ldr r12, [r12, #0xc] */
/* @0x2c7b48 cmp r12, #0 */
/* @0x2c7b4c beq 0x2c7ba4 <_ZN16b2ContactManager7AddPairEPvS0_+0x9c> */
/* @0x2c7b50 ldr r4, [r12] */
/* @0x2c7b54 cmp r1, r4 */
/* @0x2c7b58 bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c> */
/* @0x2c7b5c ldr r4, [r12, #0x4] */
/* @0x2c7b60 add r3, r4, #48 */
/* @0x2c7b64 ldr r2, [r4, #0x3c] */
/* @0x2c7b68 ldm r3, {r3, r5, r11} */
/* @0x2c7b6c cmp r7, r3 */
/* @0x2c7b70 cmpeq r6, r5 */
/* @0x2c7b74 bne 0x2c7b84 <_ZN16b2ContactManager7AddPairEPvS0_+0x7c> */
/* @0x2c7b78 cmp r10, r11 */
/* @0x2c7b7c cmpeq r8, r2 */
/* @0x2c7b80 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94> */
/* @0x2c7b84 cmp r6, r3 */
/* @0x2c7b88 cmpeq r7, r5 */
/* @0x2c7b8c bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c> */
/* @0x2c7b90 cmp r8, r11 */
/* @0x2c7b94 cmpeq r10, r2 */
/* @0x2c7b98 bne 0x2c7b44 <_ZN16b2ContactManager7AddPairEPvS0_+0x3c> */
/* @0x2c7b9c add sp, sp, #12 */
/* @0x2c7ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c7ba4 bl 0x2c7158 <_ZNK6b2Body13ShouldCollideEPKS_> */
/* @0x2c7ba8 cmp r0, #0 */
/* @0x2c7bac beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94> */
/* @0x2c7bb0 ldr r0, [r9, #0x44] */
/* @0x2c7bb4 cmp r0, #0 */
/* @0x2c7bb8 beq 0x2c7bd8 <_ZN16b2ContactManager7AddPairEPvS0_+0xd0> */
/* @0x2c7bbc ldr r3, [r0] */
/* @0x2c7bc0 mov r1, r7 */
/* @0x2c7bc4 mov r2, r6 */
/* @0x2c7bc8 ldr r3, [r3, #0x8] */
/* @0x2c7bcc blx r3 */
/* @0x2c7bd0 cmp r0, #0 */
/* @0x2c7bd4 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94> */
/* @0x2c7bd8 ldr r12, [r9, #0x4c] */
/* @0x2c7bdc mov r0, r7 */
/* @0x2c7be0 mov r1, r10 */
/* @0x2c7be4 mov r2, r6 */
/* @0x2c7be8 mov r3, r8 */
/* @0x2c7bec str r12, [sp] */
/* @0x2c7bf0 bl 0x2cbfbc <_ZN9b2Contact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator> */
/* @0x2c7bf4 cmp r0, #0 */
/* @0x2c7bf8 beq 0x2c7b9c <_ZN16b2ContactManager7AddPairEPvS0_+0x94> */
/* @0x2c7bfc ldr r12, [r0, #0x30] */
/* @0x2c7c00 mov r4, #0 */
/* @0x2c7c04 ldr r1, [r9, #0x3c] */
/* @0x2c7c08 ldr r5, [r0, #0x34] */
/* @0x2c7c0c ldr r2, [r12, #0x8] */
/* @0x2c7c10 cmp r1, r4 */
/* @0x2c7c14 ldr r3, [r5, #0x8] */
/* @0x2c7c18 str r1, [r0, #0xc] */
/* @0x2c7c1c str r4, [r0, #0x8] */
/* @0x2c7c20 mov r4, #0 */
/* @0x2c7c24 strne r0, [r1, #0x8] */
/* @0x2c7c28 ldr r1, [r2, #0x80] */
/* @0x2c7c2c str r0, [r9, #0x3c] */
/* @0x2c7c30 cmp r1, r4 */
/* @0x2c7c34 str r4, [r0, #0x18] */
/* @0x2c7c38 str r1, [r0, #0x1c] */
/* @0x2c7c3c add r4, r0, #16 */
/* @0x2c7c40 str r0, [r0, #0x14] */
/* @0x2c7c44 str r3, [r0, #0x10] */
/* @0x2c7c48 strne r4, [r1, #0x8] */
/* @0x2c7c4c str r4, [r2, #0x80] */
/* @0x2c7c50 mov r4, #0 */
/* @0x2c7c54 ldr r1, [r3, #0x80] */
/* @0x2c7c58 str r0, [r0, #0x24] */
/* @0x2c7c5c add r0, r0, #32 */
/* @0x2c7c60 str r2, [r0] */
/* @0x2c7c64 cmp r1, r4 */
/* @0x2c7c68 str r1, [r0, #0xc] */
/* @0x2c7c6c str r4, [r0, #0x8] */
/* @0x2c7c70 strne r0, [r1, #0x8] */
/* @0x2c7c74 ldrb r1, [r12, #0x2c] */
/* @0x2c7c78 str r0, [r3, #0x80] */
/* @0x2c7c7c cmp r1, #0 */
/* @0x2c7c80 bne 0x2c7cc0 <_ZN16b2ContactManager7AddPairEPvS0_+0x1b8> */
/* @0x2c7c84 ldrb r1, [r5, #0x2c] */
/* @0x2c7c88 cmp r1, #0 */
/* @0x2c7c8c bne 0x2c7cc0 <_ZN16b2ContactManager7AddPairEPvS0_+0x1b8> */
/* @0x2c7c90 ldrh r1, [r2, #4] */
/* @0x2c7c94 tst r1, #2 */
/* @0x2c7c98 orreq r1, r1, #2 */
/* @0x2c7c9c moveq r0, #0 */
/* @0x2c7ca0 strheq r1, [r2, #4] */
/* @0x2c7ca4 streq r0, [r2, #0xa0] */
/* @0x2c7ca8 ldrh r2, [r3, #4] */
/* @0x2c7cac tst r2, #2 */
/* @0x2c7cb0 orreq r2, r2, #2 */
/* @0x2c7cb4 strheq r2, [r3, #4] */
/* @0x2c7cb8 moveq r1, #0 */
/* @0x2c7cbc streq r1, [r3, #0xa0] */
/* @0x2c7cc0 ldr r3, [r9, #0x40] */
/* @0x2c7cc4 add r3, r3, #1 */
/* @0x2c7cc8 str r3, [r9, #0x40] */
/* @0x2c7ccc add sp, sp, #12 */
/* @0x2c7cd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2c7cd4 · void b2DynamicTree::Query<b2BroadPhase>(b2BroadPhase*, b2AABB const&) const · size=508 · insn=127 */
/* @0x2c7cd4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c7cd8 mov r10, r0 */
/* @0x2c7cdc sub sp, sp, #1040 */
/* @0x2c7ce0 ldr r12, [r10] */
/* @0x2c7ce4 add r6, sp, #16 */
/* @0x2c7ce8 mov r9, r2 */
/* @0x2c7cec sub r0, r6, #8 */
/* @0x2c7cf0 mov r2, #256 */
/* @0x2c7cf4 mov r8, r1 */
/* @0x2c7cf8 mov r3, #1 */
/* @0x2c7cfc mov r5, r0 */
/* @0x2c7d00 mov r7, r0 */
/* @0x2c7d04 stmib sp, {r0, r12} */
/* @0x2c7d08 str r2, [sp, #0x40c] */
/* @0x2c7d0c b 0x2c7d18 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x44> */
/* @0x2c7d10 cmp r3, #0 */
/* @0x2c7d14 ble 0x2c7df4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x120> */
/* @0x2c7d18 sub r3, r3, #1 */
/* @0x2c7d1c str r3, [sp, #0x408] */
/* @0x2c7d20 ldr r1, [r5, r3, lsl #2] */
/* @0x2c7d24 add r0, r5, r3, lsl #2 */
/* @0x2c7d28 cmn r1, #1 */
/* @0x2c7d2c beq 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7d30 add r4, r1, r1, lsl #3 */
/* @0x2c7d34 ldr r2, [r10, #0x4] */
/* @0x2c7d38 vldr s14, [r9] */
/* @0x2c7d3c vldr s13, [r9, #4] */
/* @0x2c7d40 add r4, r2, r4, lsl #2 */
/* @0x2c7d44 vldr s15, [r4, #8] */
/* @0x2c7d48 vsub.f32 s15, s14, s15 */
/* @0x2c7d4c vldr s11, [r4] */
/* @0x2c7d50 vldr s14, [r4, #12] */
/* @0x2c7d54 vldr s9, [r4, #4] */
/* @0x2c7d58 vldr s12, [r9, #8] */
/* @0x2c7d5c vldr s10, [r9, #12] */
/* @0x2c7d60 vcmpe.f32 s15, #0 */
/* @0x2c7d64 vmrs APSR_nzcv, fpscr */
/* @0x2c7d68 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7d6c vsub.f32 s14, s13, s14 */
/* @0x2c7d70 vcmpe.f32 s14, #0 */
/* @0x2c7d74 vmrs APSR_nzcv, fpscr */
/* @0x2c7d78 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7d7c vsub.f32 s12, s11, s12 */
/* @0x2c7d80 vcmpe.f32 s12, #0 */
/* @0x2c7d84 vmrs APSR_nzcv, fpscr */
/* @0x2c7d88 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7d8c vsub.f32 s10, s9, s10 */
/* @0x2c7d90 vcmpe.f32 s10, #0 */
/* @0x2c7d94 vmrs APSR_nzcv, fpscr */
/* @0x2c7d98 bgt 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7d9c ldr r12, [r4, #0x18] */
/* @0x2c7da0 cmn r12, #1 */
/* @0x2c7da4 beq 0x2c7e10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x13c> */
/* @0x2c7da8 ldr r2, [sp, #0x40c] */
/* @0x2c7dac cmp r3, r2 */
/* @0x2c7db0 movne r3, r12 */
/* @0x2c7db4 beq 0x2c7e6c <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x198> */
/* @0x2c7db8 str r3, [r0] */
/* @0x2c7dbc ldr r3, [sp, #0x408] */
/* @0x2c7dc0 ldr r2, [sp, #0x40c] */
/* @0x2c7dc4 add r3, r3, #1 */
/* @0x2c7dc8 str r3, [sp, #0x408] */
/* @0x2c7dcc cmp r3, r2 */
/* @0x2c7dd0 beq 0x2c7e2c <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x158> */
/* @0x2c7dd4 ldr r2, [r4, #0x1c] */
/* @0x2c7dd8 str r2, [r5, r3, lsl #2] */
/* @0x2c7ddc ldr r3, [sp, #0x408] */
/* @0x2c7de0 ldr r5, [sp, #0x4] */
/* @0x2c7de4 add r3, r3, #1 */
/* @0x2c7de8 str r3, [sp, #0x408] */
/* @0x2c7dec cmp r3, #0 */
/* @0x2c7df0 bgt 0x2c7d18 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x44> */
/* @0x2c7df4 sub r6, r6, #8 */
/* @0x2c7df8 cmp r5, r6 */
/* @0x2c7dfc beq 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134> */
/* @0x2c7e00 mov r0, r5 */
/* @0x2c7e04 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c7e08 add sp, sp, #1040 */
/* @0x2c7e0c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c7e10 mov r0, r8 */
/* @0x2c7e14 bl 0x2dc950 <_ZN12b2BroadPhase13QueryCallbackEi> */
/* @0x2c7e18 cmp r0, #0 */
/* @0x2c7e1c beq 0x2c7eb8 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x1e4> */
/* @0x2c7e20 ldr r3, [sp, #0x408] */
/* @0x2c7e24 ldr r5, [sp, #0x4] */
/* @0x2c7e28 b 0x2c7d10 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x3c> */
/* @0x2c7e2c lsl r0, r3, #3 */
/* @0x2c7e30 lsl r3, r3, #1 */
/* @0x2c7e34 str r3, [sp, #0x40c] */
/* @0x2c7e38 bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c7e3c ldr r2, [sp, #0x408] */
/* @0x2c7e40 mov r1, r5 */
/* @0x2c7e44 lsl r2, r2, #2 */
/* @0x2c7e48 str r0, [sp, #0x4] */
/* @0x2c7e4c bl 0xb65bc <memcpy@plt> */
/* @0x2c7e50 cmp r5, r7 */
/* @0x2c7e54 beq 0x2c7e60 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x18c> */
/* @0x2c7e58 mov r0, r5 */
/* @0x2c7e5c bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c7e60 ldr r5, [sp, #0x4] */
/* @0x2c7e64 ldr r3, [sp, #0x408] */
/* @0x2c7e68 b 0x2c7dd4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x100> */
/* @0x2c7e6c lsl r0, r3, #3 */
/* @0x2c7e70 ldr r5, [sp, #0x4] */
/* @0x2c7e74 lsl r3, r3, #1 */
/* @0x2c7e78 str r3, [sp, #0x40c] */
/* @0x2c7e7c bl 0x2c6a6c <_Z7b2Alloci> */
/* @0x2c7e80 ldr r2, [sp, #0x408] */
/* @0x2c7e84 mov r1, r5 */
/* @0x2c7e88 lsl r2, r2, #2 */
/* @0x2c7e8c str r0, [sp, #0x4] */
/* @0x2c7e90 bl 0xb65bc <memcpy@plt> */
/* @0x2c7e94 cmp r5, r7 */
/* @0x2c7e98 beq 0x2c7ea4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x1d0> */
/* @0x2c7e9c mov r0, r5 */
/* @0x2c7ea0 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c7ea4 ldr r0, [sp, #0x408] */
/* @0x2c7ea8 ldr r5, [sp, #0x4] */
/* @0x2c7eac ldr r3, [r4, #0x18] */
/* @0x2c7eb0 add r0, r5, r0, lsl #2 */
/* @0x2c7eb4 b 0x2c7db8 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0xe4> */
/* @0x2c7eb8 ldr r0, [sp, #0x4] */
/* @0x2c7ebc sub r6, r6, #8 */
/* @0x2c7ec0 cmp r0, r6 */
/* @0x2c7ec4 beq 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134> */
/* @0x2c7ec8 bl 0x2c6a70 <_Z6b2FreePv> */
/* @0x2c7ecc b 0x2c7e08 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB+0x134> */

/* ── FUNC 0x2c7ed0 · void std::priv::__unguarded_linear_insert<b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, b2Pair, bool (*)(b2Pair const&, b2Pair const&)) · size=92 · insn=23 */
/* @0x2c7ed0 push {r4, r5, r6, r7, lr} */
/* @0x2c7ed4 sub sp, sp, #12 */
/* @0x2c7ed8 mov r5, r0 */
/* @0x2c7edc mov r7, r3 */
/* @0x2c7ee0 mov r6, sp */
/* @0x2c7ee4 sub r4, r0, #8 */
/* @0x2c7ee8 stm sp, {r1, r2} */
/* @0x2c7eec b 0x2c7efc <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x2c> */
/* @0x2c7ef0 ldm r2, {r0, r1} */
/* @0x2c7ef4 stm r5, {r0, r1} */
/* @0x2c7ef8 mov r5, r12 */
/* @0x2c7efc mov r1, r4 */
/* @0x2c7f00 mov r0, sp */
/* @0x2c7f04 blx r7 */
/* @0x2c7f08 mov r12, r4 */
/* @0x2c7f0c sub r4, r4, #8 */
/* @0x2c7f10 add r2, r4, #8 */
/* @0x2c7f14 cmp r0, #0 */
/* @0x2c7f18 bne 0x2c7ef0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x20> */
/* @0x2c7f1c ldm r6, {r0, r1} */
/* @0x2c7f20 stm r5, {r0, r1} */
/* @0x2c7f24 add sp, sp, #12 */
/* @0x2c7f28 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c7f2c · anon_2c7f2c · size=180 · insn=45 */
/* @0x2c7f2c cmp r0, r1 */
/* @0x2c7f30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c7f34 mov r7, r0 */
/* @0x2c7f38 sub sp, sp, #12 */
/* @0x2c7f3c mov r10, r1 */
/* @0x2c7f40 mov r9, r2 */
/* @0x2c7f44 beq 0x2c7fc4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xf4> */
/* @0x2c7f48 add r11, r0, #8 */
/* @0x2c7f4c cmp r1, r11 */
/* @0x2c7f50 beq 0x2c7fc4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xf4> */
/* @0x2c7f54 add r5, r0, #16 */
/* @0x2c7f58 mov r6, sp */
/* @0x2c7f5c ldmdb r5, {r0, r1} */
/* @0x2c7f60 mov r8, r5 */
/* @0x2c7f64 stm r6, {r0, r1} */
/* @0x2c7f68 mov r0, sp */
/* @0x2c7f6c mov r1, r7 */
/* @0x2c7f70 blx r9 */
/* @0x2c7f74 cmp r0, #0 */
/* @0x2c7f78 beq 0x2c7fcc <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xfc> */
/* @0x2c7f7c rsb r4, r7, r11 */
/* @0x2c7f80 asr r4, r4, #3 */
/* @0x2c7f84 cmp r4, #0 */
/* @0x2c7f88 movgt r3, r5 */
/* @0x2c7f8c ble 0x2c7fac <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xdc> */
/* @0x2c7f90 sub r2, r3, #16 */
/* @0x2c7f94 sub r12, r3, #8 */
/* @0x2c7f98 subs r4, r4, #1 */
/* @0x2c7f9c ldm r2, {r0, r1} */
/* @0x2c7fa0 mov r3, r12 */
/* @0x2c7fa4 stm r12, {r0, r1} */
/* @0x2c7fa8 bne 0x2c7f90 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xc0> */
/* @0x2c7fac ldm r6, {r0, r1} */
/* @0x2c7fb0 stm r7, {r0, r1} */
/* @0x2c7fb4 cmp r10, r8 */
/* @0x2c7fb8 add r11, r11, #8 */
/* @0x2c7fbc add r5, r5, #8 */
/* @0x2c7fc0 bne 0x2c7f5c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x8c> */
/* @0x2c7fc4 add sp, sp, #12 */
/* @0x2c7fc8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c7fcc mov r0, r11 */
/* @0x2c7fd0 ldm r6, {r1, r2} */
/* @0x2c7fd4 mov r3, r9 */
/* @0x2c7fd8 bl 0x2c7ed0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_> */
/* @0x2c7fdc b 0x2c7fb4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xe4> */

/* ── FUNC 0x2c7fe0 · void std::__adjust_heap<b2Pair*, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&)>(b2Pair*, int, int, b2Pair, bool (*)(b2Pair const&, b2Pair const&)) · size=316 · insn=79 */
/* @0x2c7fe0 sub sp, sp, #8 */
/* @0x2c7fe4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c7fe8 add r4, r1, #1 */
/* @0x2c7fec sub sp, sp, #12 */
/* @0x2c7ff0 mov r9, r1 */
/* @0x2c7ff4 lsl r4, r4, #1 */
/* @0x2c7ff8 mov r8, r2 */
/* @0x2c7ffc cmp r4, r2 */
/* @0x2c8000 str r3, [sp, #0x34] */
/* @0x2c8004 mov r5, r0 */
/* @0x2c8008 ldr r7, [sp, #0x3c] */
/* @0x2c800c movge r12, r4 */
/* @0x2c8010 addge r3, r0, r1, lsl #3 */
/* @0x2c8014 movge r4, r1 */
/* @0x2c8018 bge 0x2c8074 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x94> */
/* @0x2c801c mov r10, r1 */
/* @0x2c8020 b 0x2c8028 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x48> */
/* @0x2c8024 mov r4, r12 */
/* @0x2c8028 lsl r0, r4, #3 */
/* @0x2c802c sub r6, r0, #8 */
/* @0x2c8030 add r11, r5, r0 */
/* @0x2c8034 add r6, r5, r6 */
/* @0x2c8038 mov r0, r11 */
/* @0x2c803c mov r1, r6 */
/* @0x2c8040 blx r7 */
/* @0x2c8044 mov r3, r6 */
/* @0x2c8048 add r6, r5, r10, lsl #3 */
/* @0x2c804c cmp r0, #0 */
/* @0x2c8050 subne r4, r4, #1 */
/* @0x2c8054 add r12, r4, #1 */
/* @0x2c8058 moveq r3, r11 */
/* @0x2c805c ldm r3, {r0, r1} */
/* @0x2c8060 mov r10, r4 */
/* @0x2c8064 lsl r12, r12, #1 */
/* @0x2c8068 cmp r8, r12 */
/* @0x2c806c stm r6, {r0, r1} */
/* @0x2c8070 bgt 0x2c8024 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x44> */
/* @0x2c8074 cmp r12, r8 */
/* @0x2c8078 bne 0x2c8094 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xb4> */
/* @0x2c807c sub r2, r12, #-536870911 */
/* @0x2c8080 sub r4, r12, #1 */
/* @0x2c8084 add r2, r5, r2, lsl #3 */
/* @0x2c8088 ldm r2, {r0, r1} */
/* @0x2c808c stm r3, {r0, r1} */
/* @0x2c8090 mov r3, r2 */
/* @0x2c8094 add r2, sp, #52 */
/* @0x2c8098 cmp r4, r9 */
/* @0x2c809c mov r6, sp */
/* @0x2c80a0 ldm r2, {r0, r1} */
/* @0x2c80a4 stm sp, {r0, r1} */
/* @0x2c80a8 bgt 0x2c80c4 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xe4> */
/* @0x2c80ac ldm r6, {r0, r1} */
/* @0x2c80b0 stm r3, {r0, r1} */
/* @0x2c80b4 add sp, sp, #12 */
/* @0x2c80b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c80bc add sp, sp, #8 */
/* @0x2c80c0 bx lr */
/* @0x2c80c4 sub r10, r4, #1 */
/* @0x2c80c8 add r10, r10, r10, lsr #31 */
/* @0x2c80cc asr r10, r10, #1 */
/* @0x2c80d0 add r8, r5, r10, lsl #3 */
/* @0x2c80d4 mov r1, sp */
/* @0x2c80d8 mov r0, r8 */
/* @0x2c80dc blx r7 */
/* @0x2c80e0 sub r3, r10, #1 */
/* @0x2c80e4 add r2, r5, r4, lsl #3 */
/* @0x2c80e8 add r3, r3, r3, lsr #31 */
/* @0x2c80ec asr r3, r3, #1 */
/* @0x2c80f0 cmp r0, #0 */
/* @0x2c80f4 moveq r3, r2 */
/* @0x2c80f8 beq 0x2c80ac <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xcc> */
/* @0x2c80fc ldm r8, {r0, r1} */
/* @0x2c8100 cmp r9, r10 */
/* @0x2c8104 stm r2, {r0, r1} */
/* @0x2c8108 movge r3, r8 */
/* @0x2c810c bge 0x2c80ac <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xcc> */
/* @0x2c8110 mov r4, r10 */
/* @0x2c8114 mov r10, r3 */
/* @0x2c8118 b 0x2c80d0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0xf0> */

/* ── FUNC 0x2c811c · anon_2c811c · size=484 · insn=121 */
/* @0x2c811c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c8120 mov r9, r1 */
/* @0x2c8124 rsb r1, r0, r1 */
/* @0x2c8128 sub sp, sp, #24 */
/* @0x2c812c cmp r1, #135 */
/* @0x2c8130 mov r8, r0 */
/* @0x2c8134 mov r10, r2 */
/* @0x2c8138 mov r6, r3 */
/* @0x2c813c ble 0x2c82f8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x318> */
/* @0x2c8140 cmp r2, #0 */
/* @0x2c8144 beq 0x2c8274 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x294> */
/* @0x2c8148 add r7, sp, #16 */
/* @0x2c814c asr r1, r1, #4 */
/* @0x2c8150 mov r0, r8 */
/* @0x2c8154 sub r10, r10, #1 */
/* @0x2c8158 sub r5, r9, #8 */
/* @0x2c815c add r4, r8, r1, lsl #3 */
/* @0x2c8160 mov r1, r4 */
/* @0x2c8164 blx r6 */
/* @0x2c8168 cmp r0, #0 */
/* @0x2c816c beq 0x2c8240 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x260> */
/* @0x2c8170 mov r0, r4 */
/* @0x2c8174 mov r1, r5 */
/* @0x2c8178 blx r6 */
/* @0x2c817c cmp r0, #0 */
/* @0x2c8180 movne r0, r4 */
/* @0x2c8184 bne 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0> */
/* @0x2c8188 mov r0, r8 */
/* @0x2c818c mov r1, r5 */
/* @0x2c8190 blx r6 */
/* @0x2c8194 cmp r0, #0 */
/* @0x2c8198 moveq r0, r8 */
/* @0x2c819c movne r0, r5 */
/* @0x2c81a0 ldm r0, {r0, r1} */
/* @0x2c81a4 mov r5, r9 */
/* @0x2c81a8 mov r3, r8 */
/* @0x2c81ac stm r7, {r0, r1} */
/* @0x2c81b0 mov r4, r3 */
/* @0x2c81b4 b 0x2c81bc <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1dc> */
/* @0x2c81b8 add r4, r4, #8 */
/* @0x2c81bc mov r0, r4 */
/* @0x2c81c0 mov r1, r7 */
/* @0x2c81c4 blx r6 */
/* @0x2c81c8 cmp r0, #0 */
/* @0x2c81cc bne 0x2c81b8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1d8> */
/* @0x2c81d0 sub r5, r5, #8 */
/* @0x2c81d4 mov r0, r7 */
/* @0x2c81d8 mov r1, r5 */
/* @0x2c81dc blx r6 */
/* @0x2c81e0 cmp r0, #0 */
/* @0x2c81e4 bne 0x2c81d0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1f0> */
/* @0x2c81e8 cmp r5, r4 */
/* @0x2c81ec bls 0x2c8210 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x230> */
/* @0x2c81f0 ldr r12, [r4] */
/* @0x2c81f4 add r3, r4, #8 */
/* @0x2c81f8 ldr r2, [r4, #0x4] */
/* @0x2c81fc ldm r5, {r0, r1} */
/* @0x2c8200 stm r4, {r0, r1} */
/* @0x2c8204 str r12, [r5] */
/* @0x2c8208 str r2, [r5, #0x4] */
/* @0x2c820c b 0x2c81b0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1d0> */
/* @0x2c8210 mov r1, r9 */
/* @0x2c8214 mov r0, r4 */
/* @0x2c8218 mov r2, r10 */
/* @0x2c821c mov r3, r6 */
/* @0x2c8220 bl 0x2c811c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x13c> */
/* @0x2c8224 rsb r1, r8, r4 */
/* @0x2c8228 cmp r1, #135 */
/* @0x2c822c ble 0x2c82f8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x318> */
/* @0x2c8230 cmp r10, #0 */
/* @0x2c8234 beq 0x2c8278 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x298> */
/* @0x2c8238 mov r9, r4 */
/* @0x2c823c b 0x2c814c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x16c> */
/* @0x2c8240 mov r0, r8 */
/* @0x2c8244 mov r1, r5 */
/* @0x2c8248 blx r6 */
/* @0x2c824c cmp r0, #0 */
/* @0x2c8250 movne r0, r8 */
/* @0x2c8254 bne 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0> */
/* @0x2c8258 mov r0, r4 */
/* @0x2c825c mov r1, r5 */
/* @0x2c8260 blx r6 */
/* @0x2c8264 cmp r0, #0 */
/* @0x2c8268 moveq r0, r4 */
/* @0x2c826c movne r0, r5 */
/* @0x2c8270 b 0x2c81a0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x1c0> */
/* @0x2c8274 mov r4, r9 */
/* @0x2c8278 asr r9, r1, #3 */
/* @0x2c827c sub r5, r9, #2 */
/* @0x2c8280 asr r5, r5, #1 */
/* @0x2c8284 add r7, r8, r5, lsl #3 */
/* @0x2c8288 str r6, [sp, #0x4] */
/* @0x2c828c mov r1, r5 */
/* @0x2c8290 ldr r12, [r7, #0x4] */
/* @0x2c8294 mov r0, r8 */
/* @0x2c8298 ldr r3, [r7], #-8 */
/* @0x2c829c mov r2, r9 */
/* @0x2c82a0 str r12, [sp] */
/* @0x2c82a4 bl 0x2c7fe0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_> */
/* @0x2c82a8 cmp r5, #0 */
/* @0x2c82ac sub r5, r5, #1 */
/* @0x2c82b0 bne 0x2c8288 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x2a8> */
/* @0x2c82b4 add r7, sp, #8 */
/* @0x2c82b8 sub r4, r4, #8 */
/* @0x2c82bc rsb r5, r8, r4 */
/* @0x2c82c0 ldm r4, {r0, r1} */
/* @0x2c82c4 asr r2, r5, #3 */
/* @0x2c82c8 stm r7, {r0, r1} */
/* @0x2c82cc ldm r8, {r0, r1} */
/* @0x2c82d0 ldr r12, [sp, #0xc] */
/* @0x2c82d4 ldr r3, [sp, #0x8] */
/* @0x2c82d8 stm r4, {r0, r1} */
/* @0x2c82dc mov r0, r8 */
/* @0x2c82e0 str r6, [sp, #0x4] */
/* @0x2c82e4 mov r1, #0 */
/* @0x2c82e8 str r12, [sp] */
/* @0x2c82ec bl 0x2c7fe0 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_> */
/* @0x2c82f0 cmp r5, #15 */
/* @0x2c82f4 bgt 0x2c82b8 <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x2d8> */
/* @0x2c82f8 add sp, sp, #24 */
/* @0x2c82fc pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2c8300 · void b2BroadPhase::UpdatePairs<b2ContactManager>(b2ContactManager*) · size=472 · insn=118 */
/* @0x2c8300 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2c8304 mov r4, #0 */
/* @0x2c8308 ldr r5, [r0, #0x28] */
/* @0x2c830c mov r8, r0 */
/* @0x2c8310 mov r7, r1 */
/* @0x2c8314 str r4, [r0, #0x34] */
/* @0x2c8318 cmp r5, r4 */
/* @0x2c831c ble 0x2c84c8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1c8> */
/* @0x2c8320 ldr r3, [r8, #0x20] */
/* @0x2c8324 mov r0, r8 */
/* @0x2c8328 mov r1, r8 */
/* @0x2c832c ldr r3, [r3, r4, lsl #2] */
/* @0x2c8330 add r4, r4, #1 */
/* @0x2c8334 cmn r3, #1 */
/* @0x2c8338 add r2, r3, r3, lsl #3 */
/* @0x2c833c str r3, [r8, #0x38] */
/* @0x2c8340 beq 0x2c8354 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x54> */
/* @0x2c8344 ldr r3, [r8, #0x4] */
/* @0x2c8348 add r2, r3, r2, lsl #2 */
/* @0x2c834c bl 0x2c7cd4 <_ZNK13b2DynamicTree5QueryI12b2BroadPhaseEEvPT_RK6b2AABB> */
/* @0x2c8350 ldr r5, [r8, #0x28] */
/* @0x2c8354 cmp r5, r4 */
/* @0x2c8358 bgt 0x2c8320 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x20> */
/* @0x2c835c ldr r12, [r8, #0x34] */
/* @0x2c8360 mov r2, #0 */
/* @0x2c8364 ldr r9, [r8, #0x2c] */
/* @0x2c8368 str r2, [r8, #0x28] */
/* @0x2c836c add r6, r9, r12, lsl #3 */
/* @0x2c8370 cmp r9, r6 */
/* @0x2c8374 beq 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8> */
/* @0x2c8378 rsb r4, r9, r6 */
/* @0x2c837c asr r3, r4, #3 */
/* @0x2c8380 cmp r3, #1 */
/* @0x2c8384 beq 0x2c839c <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x9c> */
/* @0x2c8388 asr r3, r3, #1 */
/* @0x2c838c add r2, r2, #1 */
/* @0x2c8390 cmp r3, #1 */
/* @0x2c8394 bne 0x2c8388 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x88> */
/* @0x2c8398 lsl r2, r2, #1 */
/* @0x2c839c ldr r5, [pc, #0x130] */
/* @0x2c83a0 mov r0, r9 */
/* @0x2c83a4 mov r1, r6 */
/* @0x2c83a8 ldr r5, [pc, r5] */
/* @0x2c83ac mov r3, r5 */
/* @0x2c83b0 bl 0x2c811c <_ZSt13__adjust_heapIP6b2PairiS0_PFbRKS0_S3_EEvT_T0_S7_T1_T2_+0x13c> */
/* @0x2c83b4 cmp r4, #135 */
/* @0x2c83b8 ble 0x2c84b0 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1b0> */
/* @0x2c83bc add r4, r9, #128 */
/* @0x2c83c0 mov r0, r9 */
/* @0x2c83c4 mov r2, r5 */
/* @0x2c83c8 mov r1, r4 */
/* @0x2c83cc bl 0x2c7f2c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x5c> */
/* @0x2c83d0 cmp r6, r4 */
/* @0x2c83d4 beq 0x2c84c0 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1c0> */
/* @0x2c83d8 mov r0, r4 */
/* @0x2c83dc ldm r4, {r1, r2} */
/* @0x2c83e0 mov r3, r5 */
/* @0x2c83e4 add r4, r4, #8 */
/* @0x2c83e8 bl 0x2c7ed0 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_> */
/* @0x2c83ec cmp r6, r4 */
/* @0x2c83f0 bne 0x2c83d8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xd8> */
/* @0x2c83f4 ldr r12, [r8, #0x34] */
/* @0x2c83f8 mov r4, #0 */
/* @0x2c83fc cmp r4, r12 */
/* @0x2c8400 bge 0x2c84ac <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x1ac> */
/* @0x2c8404 ldr r5, [r8, #0x2c] */
/* @0x2c8408 lsl r9, r4, #3 */
/* @0x2c840c ldr r3, [r8, #0x4] */
/* @0x2c8410 mov r0, r7 */
/* @0x2c8414 add r10, r5, r9 */
/* @0x2c8418 ldr r1, [r5, r4, lsl #3] */
/* @0x2c841c add r4, r4, #1 */
/* @0x2c8420 ldr r2, [r10, #0x4] */
/* @0x2c8424 add r1, r1, r1, lsl #3 */
/* @0x2c8428 add r2, r2, r2, lsl #3 */
/* @0x2c842c add r1, r3, r1, lsl #2 */
/* @0x2c8430 add r3, r3, r2, lsl #2 */
/* @0x2c8434 ldr r1, [r1, #0x10] */
/* @0x2c8438 ldr r2, [r3, #0x10] */
/* @0x2c843c bl 0x2c7b08 <_ZN16b2ContactManager7AddPairEPvS0_> */
/* @0x2c8440 ldr r12, [r8, #0x34] */
/* @0x2c8444 cmp r4, r12 */
/* @0x2c8448 bge 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc> */
/* @0x2c844c ldr r3, [r8, #0x2c] */
/* @0x2c8450 add r2, r9, #8 */
/* @0x2c8454 ldr r1, [r5, r9] */
/* @0x2c8458 add r0, r3, r2 */
/* @0x2c845c ldr r5, [r3, r2] */
/* @0x2c8460 cmp r5, r1 */
/* @0x2c8464 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc> */
/* @0x2c8468 ldr r6, [r0, #0x4] */
/* @0x2c846c ldr r2, [r10, #0x4] */
/* @0x2c8470 cmp r6, r2 */
/* @0x2c8474 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc> */
/* @0x2c8478 add r3, r3, r9 */
/* @0x2c847c add r4, r4, #1 */
/* @0x2c8480 cmp r4, r12 */
/* @0x2c8484 beq 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc> */
/* @0x2c8488 ldr r2, [r3, #0x10] */
/* @0x2c848c add r3, r3, #8 */
/* @0x2c8490 cmp r2, r5 */
/* @0x2c8494 bne 0x2c83fc <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xfc> */
/* @0x2c8498 ldr r2, [r3, #0xc] */
/* @0x2c849c cmp r2, r6 */
/* @0x2c84a0 beq 0x2c847c <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x17c> */
/* @0x2c84a4 cmp r4, r12 */
/* @0x2c84a8 blt 0x2c8404 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0x104> */
/* @0x2c84ac pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2c84b0 mov r0, r9 */
/* @0x2c84b4 mov r1, r6 */
/* @0x2c84b8 mov r2, r5 */
/* @0x2c84bc bl 0x2c7f2c <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0x5c> */
/* @0x2c84c0 ldr r12, [r8, #0x34] */
/* @0x2c84c4 b 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8> */
/* @0x2c84c8 str r4, [r0, #0x28] */
/* @0x2c84cc mov r12, r4 */
/* @0x2c84d0 b 0x2c83f8 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_+0xf8> */
/* @0x2c84d4 andseq r9, r2, r4, asr #14 */

/* ── FUNC 0x2c84d8 · b2ContactManager::FindNewContacts() · size=8 · insn=2 */
/* @0x2c84d8 mov r1, r0 */
/* @0x2c84dc b 0x2c8300 <_ZN12b2BroadPhase11UpdatePairsI16b2ContactManagerEEvPT_> */

/* ── FUNC 0x2c84e0 · b2Fixture::b2Fixture() · size=60 · insn=15 */
/* @0x2c84e0 mov r1, #1 */
/* @0x2c84e4 movw r2, #0xffff */
/* @0x2c84e8 str r1, [r0, #0x20] */
/* @0x2c84ec mov r1, #0 */
/* @0x2c84f0 str r2, [r0, #0x24] */
/* @0x2c84f4 mov r2, #0 */
/* @0x2c84f8 str r1, [r0] */
/* @0x2c84fc strh r2, [r0, #40] */
/* @0x2c8500 str r2, [r0, #0x30] */
/* @0x2c8504 str r2, [r0, #0x8] */
/* @0x2c8508 str r2, [r0, #0x4] */
/* @0x2c850c str r2, [r0, #0x18] */
/* @0x2c8510 str r2, [r0, #0x1c] */
/* @0x2c8514 str r2, [r0, #0xc] */
/* @0x2c8518 bx lr */

/* ── FUNC 0x2c84e0 · b2Fixture::b2Fixture() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c851c · b2Fixture::Create(b2BlockAllocator*, b2Body*, b2FixtureDef const*) · size=212 · insn=53 */
/* @0x2c851c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c8520 mov r5, r3 */
/* @0x2c8524 mov r4, r0 */
/* @0x2c8528 ldr r8, [r3, #0x18]! */
/* @0x2c852c ldr r0, [r5, #0x4] */
/* @0x2c8530 mov r7, #0 */
/* @0x2c8534 ldr r12, [r5, #0x8] */
/* @0x2c8538 mov r9, r1 */
/* @0x2c853c ldr r6, [r5] */
/* @0x2c8540 str r0, [r4, #0x30] */
/* @0x2c8544 str r12, [r4, #0x10] */
/* @0x2c8548 ldr r0, [r5, #0xc] */
/* @0x2c854c ldr r12, [r3, #0x4] */
/* @0x2c8550 str r2, [r4, #0x8] */
/* @0x2c8554 str r8, [r4, #0x20] */
/* @0x2c8558 ldrb r2, [r5, #0x14] */
/* @0x2c855c str r0, [r4, #0x14] */
/* @0x2c8560 mov r0, r6 */
/* @0x2c8564 str r12, [r4, #0x24] */
/* @0x2c8568 ldr r6, [r6] */
/* @0x2c856c ldrh r12, [r3, #8] */
/* @0x2c8570 str r7, [r4, #0x4] */
/* @0x2c8574 ldr r3, [r6, #0x8] */
/* @0x2c8578 strh r12, [r4, #40] */
/* @0x2c857c strb r2, [r4, #0x2c] */
/* @0x2c8580 blx r3 */
/* @0x2c8584 ldr r2, [r0] */
/* @0x2c8588 str r0, [r4, #0xc] */
/* @0x2c858c ldr r3, [r2, #0xc] */
/* @0x2c8590 blx r3 */
/* @0x2c8594 rsb r8, r0, r0, lsl #3 */
/* @0x2c8598 mov r6, r0 */
/* @0x2c859c mov r0, r9 */
/* @0x2c85a0 lsl r8, r8, #2 */
/* @0x2c85a4 mov r1, r8 */
/* @0x2c85a8 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2c85ac cmp r6, r7 */
/* @0x2c85b0 movgt r12, r7 */
/* @0x2c85b4 movgt r2, r0 */
/* @0x2c85b8 str r0, [r4, #0x18] */
/* @0x2c85bc addgt r1, r2, r8 */
/* @0x2c85c0 mvngt r0, #0 */
/* @0x2c85c4 ble 0x2c85dc <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef+0xc0> */
/* @0x2c85c8 str r12, [r2, #0x10] */
/* @0x2c85cc add r2, r2, #28 */
/* @0x2c85d0 str r0, [r2, #-0x4] */
/* @0x2c85d4 cmp r2, r1 */
/* @0x2c85d8 bne 0x2c85c8 <_ZN9b2Fixture6CreateEP16b2BlockAllocatorP6b2BodyPK12b2FixtureDef+0xac> */
/* @0x2c85dc ldr r2, [r5, #0x10] */
/* @0x2c85e0 mov r3, #0 */
/* @0x2c85e4 str r3, [r4, #0x1c] */
/* @0x2c85e8 str r2, [r4] */
/* @0x2c85ec pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2c85f0 · b2Fixture::Destroy(b2BlockAllocator*) · size=244 · insn=61 */
/* @0x2c85f0 push {r4, r5, r6, lr} */
/* @0x2c85f4 mov r4, r0 */
/* @0x2c85f8 ldr r0, [r0, #0xc] */
/* @0x2c85fc mov r6, r1 */
/* @0x2c8600 ldr r2, [r0] */
/* @0x2c8604 ldr r3, [r2, #0xc] */
/* @0x2c8608 blx r3 */
/* @0x2c860c ldr r1, [r4, #0x18] */
/* @0x2c8610 rsb r2, r0, r0, lsl #3 */
/* @0x2c8614 mov r0, r6 */
/* @0x2c8618 lsl r2, r2, #2 */
/* @0x2c861c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c8620 ldr r5, [r4, #0xc] */
/* @0x2c8624 mov r3, #0 */
/* @0x2c8628 str r3, [r4, #0x18] */
/* @0x2c862c ldr r3, [r5, #0x4] */
/* @0x2c8630 cmp r3, #3 */
/* @0x2c8634 addls pc, pc, r3, lsl #2 */
/* @0x2c8638 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c> */
/* @0x2c863c b 0x2c864c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x5c> */
/* @0x2c8640 b 0x2c86c0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0xd0> */
/* @0x2c8644 b 0x2c869c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0xac> */
/* @0x2c8648 b 0x2c8678 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x88> */
/* @0x2c864c ldr r3, [r5] */
/* @0x2c8650 mov r0, r5 */
/* @0x2c8654 ldr r3, [r3] */
/* @0x2c8658 blx r3 */
/* @0x2c865c mov r0, r6 */
/* @0x2c8660 mov r1, r5 */
/* @0x2c8664 mov r2, #20 */
/* @0x2c8668 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c866c mov r3, #0 */
/* @0x2c8670 str r3, [r4, #0xc] */
/* @0x2c8674 pop {r4, r5, r6, pc} */
/* @0x2c8678 ldr r3, [r5] */
/* @0x2c867c mov r0, r5 */
/* @0x2c8680 ldr r3, [r3] */
/* @0x2c8684 blx r3 */
/* @0x2c8688 mov r0, r6 */
/* @0x2c868c mov r1, r5 */
/* @0x2c8690 mov r2, #40 */
/* @0x2c8694 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c8698 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c> */
/* @0x2c869c ldr r3, [r5] */
/* @0x2c86a0 mov r0, r5 */
/* @0x2c86a4 ldr r3, [r3] */
/* @0x2c86a8 blx r3 */
/* @0x2c86ac mov r0, r6 */
/* @0x2c86b0 mov r1, r5 */
/* @0x2c86b4 mov r2, #152 */
/* @0x2c86b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c86bc b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c> */
/* @0x2c86c0 ldr r3, [r5] */
/* @0x2c86c4 mov r0, r5 */
/* @0x2c86c8 ldr r3, [r3] */
/* @0x2c86cc blx r3 */
/* @0x2c86d0 mov r0, r6 */
/* @0x2c86d4 mov r1, r5 */
/* @0x2c86d8 mov r2, #48 */
/* @0x2c86dc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi> */
/* @0x2c86e0 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c> */

/* ── FUNC 0x2c86e4 · b2Fixture::CreateProxies(b2BroadPhase*, b2Transform const&) · size=140 · insn=35 */
/* @0x2c86e4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c86e8 mov r6, r0 */
/* @0x2c86ec ldr r0, [r0, #0xc] */
/* @0x2c86f0 mov r8, r1 */
/* @0x2c86f4 mov r9, r2 */
/* @0x2c86f8 ldr r3, [r0] */
/* @0x2c86fc ldr r3, [r3, #0xc] */
/* @0x2c8700 blx r3 */
/* @0x2c8704 cmp r0, #0 */
/* @0x2c8708 str r0, [r6, #0x1c] */
/* @0x2c870c pople {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x2c8710 mov r7, #0 */
/* @0x2c8714 mov r5, r7 */
/* @0x2c8718 ldr r0, [r6, #0xc] */
/* @0x2c871c mov r3, r5 */
/* @0x2c8720 ldr r4, [r6, #0x18] */
/* @0x2c8724 mov r2, r9 */
/* @0x2c8728 ldr r12, [r0] */
/* @0x2c872c add r4, r4, r7 */
/* @0x2c8730 add r7, r7, #28 */
/* @0x2c8734 mov r1, r4 */
/* @0x2c8738 ldr r12, [r12, #0x1c] */
/* @0x2c873c blx r12 */
/* @0x2c8740 mov r0, r8 */
/* @0x2c8744 mov r1, r4 */
/* @0x2c8748 mov r2, r4 */
/* @0x2c874c bl 0x2dc888 <_ZN12b2BroadPhase11CreateProxyERK6b2AABBPv> */
/* @0x2c8750 ldr r3, [r6, #0x1c] */
/* @0x2c8754 str r5, [r4, #0x14] */
/* @0x2c8758 add r5, r5, #1 */
/* @0x2c875c cmp r3, r5 */
/* @0x2c8760 str r6, [r4, #0x10] */
/* @0x2c8764 str r0, [r4, #0x18] */
/* @0x2c8768 bgt 0x2c8718 <_ZN9b2Fixture13CreateProxiesEP12b2BroadPhaseRK11b2Transform+0x34> */
/* @0x2c876c pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2c8770 · b2Fixture::DestroyProxies(b2BroadPhase*) · size=92 · insn=23 */
/* @0x2c8770 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x2c8774 mov r7, r0 */
/* @0x2c8778 ldr r3, [r0, #0x1c] */
/* @0x2c877c mov r8, r1 */
/* @0x2c8780 cmp r3, #0 */
/* @0x2c8784 movgt r4, #0 */
/* @0x2c8788 mvngt r9, #0 */
/* @0x2c878c movgt r5, r4 */
/* @0x2c8790 ble 0x2c87c0 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase+0x50> */
/* @0x2c8794 ldr r6, [r7, #0x18] */
/* @0x2c8798 mov r0, r8 */
/* @0x2c879c add r5, r5, #1 */
/* @0x2c87a0 add r6, r6, r4 */
/* @0x2c87a4 add r4, r4, #28 */
/* @0x2c87a8 ldr r1, [r6, #0x18] */
/* @0x2c87ac bl 0x2dc924 <_ZN12b2BroadPhase12DestroyProxyEi> */
/* @0x2c87b0 ldr r3, [r7, #0x1c] */
/* @0x2c87b4 str r9, [r6, #0x18] */
/* @0x2c87b8 cmp r3, r5 */
/* @0x2c87bc bgt 0x2c8794 <_ZN9b2Fixture14DestroyProxiesEP12b2BroadPhase+0x24> */
/* @0x2c87c0 mov r3, #0 */
/* @0x2c87c4 str r3, [r7, #0x1c] */
/* @0x2c87c8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x2c87cc · b2Fixture::Synchronize(b2BroadPhase*, b2Transform const&, b2Transform const&) · size=304 · insn=76 */
/* @0x2c87cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c87d0 mov r10, r1 */
/* @0x2c87d4 ldr r1, [r0, #0x1c] */
/* @0x2c87d8 sub sp, sp, #52 */
/* @0x2c87dc mov r5, r0 */
/* @0x2c87e0 mov r8, r2 */
/* @0x2c87e4 cmp r1, #0 */
/* @0x2c87e8 mov r7, r3 */
/* @0x2c87ec ble 0x2c88f4 <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_+0x128> */
/* @0x2c87f0 mov r6, #0 */
/* @0x2c87f4 add r11, sp, #16 */
/* @0x2c87f8 mov r9, r6 */
/* @0x2c87fc add r3, sp, #32 */
/* @0x2c8800 str r3, [sp] */
/* @0x2c8804 add r3, sp, #8 */
/* @0x2c8808 str r3, [sp, #0x4] */
/* @0x2c880c ldr r0, [r5, #0xc] */
/* @0x2c8810 mov r1, r11 */
/* @0x2c8814 ldr r4, [r5, #0x18] */
/* @0x2c8818 mov r2, r8 */
/* @0x2c881c add r9, r9, #1 */
/* @0x2c8820 ldr r12, [r0] */
/* @0x2c8824 add r4, r4, r6 */
/* @0x2c8828 add r6, r6, #28 */
/* @0x2c882c ldr r3, [r4, #0x14] */
/* @0x2c8830 ldr r12, [r12, #0x1c] */
/* @0x2c8834 blx r12 */
/* @0x2c8838 ldr r0, [r5, #0xc] */
/* @0x2c883c ldr r3, [r4, #0x14] */
/* @0x2c8840 add r1, sp, #32 */
/* @0x2c8844 mov r2, r7 */
/* @0x2c8848 ldr r12, [r0] */
/* @0x2c884c ldr r12, [r12, #0x1c] */
/* @0x2c8850 blx r12 */
/* @0x2c8854 vldr s12, [sp, #16] */
/* @0x2c8858 vldr s13, [sp, #32] */
/* @0x2c885c vcmpe.f32 s12, s13 */
/* @0x2c8860 vldr s14, [sp, #20] */
/* @0x2c8864 vldr s15, [sp, #36] */
/* @0x2c8868 add r3, sp, #8 */
/* @0x2c886c mov r2, r4 */
/* @0x2c8870 mov r0, r10 */
/* @0x2c8874 ldr r1, [r4, #0x18] */
/* @0x2c8878 vmrs APSR_nzcv, fpscr */
/* @0x2c887c vcmpe.f32 s14, s15 */
/* @0x2c8880 vmovmi.f32 s13, s12 */
/* @0x2c8884 vmrs APSR_nzcv, fpscr */
/* @0x2c8888 vstr s13, [r4] */
/* @0x2c888c vmovmi.f32 s15, s14 */
/* @0x2c8890 vstr s15, [r4, #4] */
/* @0x2c8894 vldr s12, [sp, #24] */
/* @0x2c8898 vldr s13, [sp, #40] */
/* @0x2c889c vldr s14, [sp, #28] */
/* @0x2c88a0 vldr s15, [sp, #44] */
/* @0x2c88a4 vcmpe.f32 s12, s13 */
/* @0x2c88a8 vmrs APSR_nzcv, fpscr */
/* @0x2c88ac vcmpe.f32 s14, s15 */
/* @0x2c88b0 vmovgt.f32 s13, s12 */
/* @0x2c88b4 vmrs APSR_nzcv, fpscr */
/* @0x2c88b8 vstr s13, [r4, #8] */
/* @0x2c88bc vmovgt.f32 s15, s14 */
/* @0x2c88c0 vstr s15, [r4, #12] */
/* @0x2c88c4 vldr s12, [r7, #4] */
/* @0x2c88c8 vldr s14, [r8, #4] */
/* @0x2c88cc vldr s13, [r7] */
/* @0x2c88d0 vldr s15, [r8] */
/* @0x2c88d4 vsub.f32 s14, s12, s14 */
/* @0x2c88d8 vsub.f32 s15, s13, s15 */
/* @0x2c88dc vstr s14, [sp, #12] */
/* @0x2c88e0 vstr s15, [sp, #8] */
/* @0x2c88e4 bl 0x2dc8b8 <_ZN12b2BroadPhase9MoveProxyEiRK6b2AABBRK6b2Vec2> */
/* @0x2c88e8 ldr r3, [r5, #0x1c] */
/* @0x2c88ec cmp r3, r9 */
/* @0x2c88f0 bgt 0x2c880c <_ZN9b2Fixture11SynchronizeEP12b2BroadPhaseRK11b2TransformS4_+0x40> */
/* @0x2c88f4 add sp, sp, #52 */
/* @0x2c88f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2c88fc · b2Fixture::Refilter() · size=160 · insn=40 */
/* @0x2c88fc ldr r12, [r0, #0x8] */
/* @0x2c8900 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c8904 cmp r12, #0 */
/* @0x2c8908 mov r4, r0 */
/* @0x2c890c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2c8910 ldr r3, [r12, #0x80] */
/* @0x2c8914 cmp r3, #0 */
/* @0x2c8918 beq 0x2c8948 <_ZN9b2Fixture8RefilterEv+0x4c> */
/* @0x2c891c ldr r2, [r3, #0x4] */
/* @0x2c8920 ldr r3, [r3, #0xc] */
/* @0x2c8924 ldr r1, [r2, #0x30] */
/* @0x2c8928 ldr r0, [r2, #0x34] */
/* @0x2c892c cmp r4, r1 */
/* @0x2c8930 cmpne r4, r0 */
/* @0x2c8934 ldreq r1, [r2, #0x4] */
/* @0x2c8938 orreq r1, r1, #8 */
/* @0x2c893c streq r1, [r2, #0x4] */
/* @0x2c8940 cmp r3, #0 */
/* @0x2c8944 bne 0x2c891c <_ZN9b2Fixture8RefilterEv+0x20> */
/* @0x2c8948 ldr r7, [r12, #0x68] */
/* @0x2c894c cmp r7, #0 */
/* @0x2c8950 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x2c8954 ldr r3, [r4, #0x1c] */
/* @0x2c8958 add r7, r7, #102400 */
/* @0x2c895c add r7, r7, #472 */
/* @0x2c8960 cmp r3, #0 */
/* @0x2c8964 pople {r3, r4, r5, r6, r7, pc} */
/* @0x2c8968 mov r5, #0 */
/* @0x2c896c mov r6, r5 */
/* @0x2c8970 ldr r3, [r4, #0x18] */
/* @0x2c8974 mov r0, r7 */
/* @0x2c8978 add r6, r6, #1 */
/* @0x2c897c add r3, r3, r5 */
/* @0x2c8980 add r5, r5, #28 */
/* @0x2c8984 ldr r1, [r3, #0x18] */
/* @0x2c8988 bl 0x2dc8e0 <_ZN12b2BroadPhase10TouchProxyEi> */
/* @0x2c898c ldr r3, [r4, #0x1c] */
/* @0x2c8990 cmp r3, r6 */
/* @0x2c8994 bgt 0x2c8970 <_ZN9b2Fixture8RefilterEv+0x74> */
/* @0x2c8998 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c899c · b2Fixture::SetFilterData(b2Filter const&) · size=40 · insn=10 */
/* @0x2c899c str r4, [sp, #-0x4]! */
/* @0x2c89a0 add r3, r0, #32 */
/* @0x2c89a4 ldr r4, [r1] */
/* @0x2c89a8 ldr r12, [r1, #0x4] */
/* @0x2c89ac str r4, [r0, #0x20] */
/* @0x2c89b0 str r12, [r0, #0x24] */
/* @0x2c89b4 ldrh r2, [r1, #8] */
/* @0x2c89b8 ldr r4, [sp], #4 */
/* @0x2c89bc strh r2, [r3, #8] */
/* @0x2c89c0 b 0x2c88fc <_ZN9b2Fixture8RefilterEv> */

/* ── FUNC 0x2c89c4 · b2Fixture::SetSensor(bool) · size=48 · insn=12 */
/* @0x2c89c4 ldrb r3, [r0, #0x2c] */
/* @0x2c89c8 cmp r3, r1 */
/* @0x2c89cc bxeq lr */
/* @0x2c89d0 ldr r3, [r0, #0x8] */
/* @0x2c89d4 ldrh r2, [r3, #4] */
/* @0x2c89d8 tst r2, #2 */
/* @0x2c89dc orreq r2, r2, #2 */
/* @0x2c89e0 strheq r2, [r3, #4] */
/* @0x2c89e4 moveq r12, #0 */
/* @0x2c89e8 streq r12, [r3, #0xa0] */
/* @0x2c89ec strb r1, [r0, #0x2c] */
/* @0x2c89f0 bx lr */

/* ── FUNC 0x2c89f4 · b2Fixture::Dump(int) · size=1052 · insn=263 */
/* @0x2c89f4 push {r4, r5, r6, r7, r8, lr} */
/* @0x2c89f8 mov r4, r0 */
/* @0x2c89fc ldr r0, [pc, #0x384] */
/* @0x2c8a00 sub sp, sp, #8 */
/* @0x2c8a04 mov r7, r1 */
/* @0x2c8a08 add r0, pc, r0 */
/* @0x2c8a0c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a10 vldr s15, [r4, #16] */
/* @0x2c8a14 vcvt.f64.f32 d5, s15 */
/* @0x2c8a18 ldr r0, [pc, #0x36c] */
/* @0x2c8a1c add r0, pc, r0 */
/* @0x2c8a20 vmov r2, r3, d5 */
/* @0x2c8a24 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a28 vldr s15, [r4, #20] */
/* @0x2c8a2c vcvt.f64.f32 d6, s15 */
/* @0x2c8a30 ldr r0, [pc, #0x358] */
/* @0x2c8a34 add r0, pc, r0 */
/* @0x2c8a38 vmov r2, r3, d6 */
/* @0x2c8a3c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a40 vldr s15, [r4] */
/* @0x2c8a44 vcvt.f64.f32 d5, s15 */
/* @0x2c8a48 ldr r0, [pc, #0x344] */
/* @0x2c8a4c add r0, pc, r0 */
/* @0x2c8a50 vmov r2, r3, d5 */
/* @0x2c8a54 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a58 ldr r0, [pc, #0x338] */
/* @0x2c8a5c ldrb r1, [r4, #0x2c] */
/* @0x2c8a60 add r0, pc, r0 */
/* @0x2c8a64 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a68 ldr r0, [pc, #0x32c] */
/* @0x2c8a6c ldr r1, [r4, #0x20] */
/* @0x2c8a70 add r0, pc, r0 */
/* @0x2c8a74 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a78 ldr r0, [pc, #0x320] */
/* @0x2c8a7c ldr r1, [r4, #0x24] */
/* @0x2c8a80 add r0, pc, r0 */
/* @0x2c8a84 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a88 ldr r0, [pc, #0x314] */
/* @0x2c8a8c ldrsh r1, [r4, #40] */
/* @0x2c8a90 add r0, pc, r0 */
/* @0x2c8a94 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8a98 ldr r4, [r4, #0xc] */
/* @0x2c8a9c ldr r3, [r4, #0x4] */
/* @0x2c8aa0 cmp r3, #3 */
/* @0x2c8aa4 addls pc, pc, r3, lsl #2 */
/* @0x2c8aa8 b 0x2c8d80 <_ZN9b2Fixture4DumpEi+0x38c> */
/* @0x2c8aac b 0x2c8c24 <_ZN9b2Fixture4DumpEi+0x230> */
/* @0x2c8ab0 b 0x2c8ca8 <_ZN9b2Fixture4DumpEi+0x2b4> */
/* @0x2c8ab4 b 0x2c8ba4 <_ZN9b2Fixture4DumpEi+0x1b0> */
/* @0x2c8ab8 b 0x2c8abc <_ZN9b2Fixture4DumpEi+0xc8> */
/* @0x2c8abc ldr r0, [pc, #0x2e4] */
/* @0x2c8ac0 add r0, pc, r0 */
/* @0x2c8ac4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8ac8 ldr r0, [pc, #0x2dc] */
/* @0x2c8acc ldr r1, [r4, #0x10] */
/* @0x2c8ad0 add r0, pc, r0 */
/* @0x2c8ad4 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8ad8 ldr r1, [r4, #0x10] */
/* @0x2c8adc cmp r1, #0 */
/* @0x2c8ae0 ble 0x2c8b2c <_ZN9b2Fixture4DumpEi+0x138> */
/* @0x2c8ae4 ldr r6, [pc, #0x2c4] */
/* @0x2c8ae8 mov r5, #0 */
/* @0x2c8aec add r6, pc, r6 */
/* @0x2c8af0 ldr r3, [r4, #0xc] */
/* @0x2c8af4 mov r1, r5 */
/* @0x2c8af8 mov r0, r6 */
/* @0x2c8afc add r3, r3, r5, lsl #3 */
/* @0x2c8b00 vldr s14, [r3, #4] */
/* @0x2c8b04 vldr s13, [r3] */
/* @0x2c8b08 vcvt.f64.f32 d7, s14 */
/* @0x2c8b0c add r5, r5, #1 */
/* @0x2c8b10 vcvt.f64.f32 d5, s13 */
/* @0x2c8b14 vstr d7, [sp] */
/* @0x2c8b18 vmov r2, r3, d5 */
/* @0x2c8b1c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8b20 ldr r1, [r4, #0x10] */
/* @0x2c8b24 cmp r1, r5 */
/* @0x2c8b28 bgt 0x2c8af0 <_ZN9b2Fixture4DumpEi+0xfc> */
/* @0x2c8b2c ldr r0, [pc, #0x280] */
/* @0x2c8b30 add r0, pc, r0 */
/* @0x2c8b34 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8b38 vldr s14, [r4, #24] */
/* @0x2c8b3c vcvt.f64.f32 d7, s14 */
/* @0x2c8b40 vldr s13, [r4, #20] */
/* @0x2c8b44 ldr r0, [pc, #0x26c] */
/* @0x2c8b48 add r0, pc, r0 */
/* @0x2c8b4c vstr d7, [sp] */
/* @0x2c8b50 vcvt.f64.f32 d7, s13 */
/* @0x2c8b54 vmov r2, r3, d7 */
/* @0x2c8b58 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8b5c vldr s13, [r4, #28] */
/* @0x2c8b60 vldr s14, [r4, #32] */
/* @0x2c8b64 vcvt.f64.f32 d5, s13 */
/* @0x2c8b68 ldr r0, [pc, #0x24c] */
/* @0x2c8b6c add r0, pc, r0 */
/* @0x2c8b70 vcvt.f64.f32 d7, s14 */
/* @0x2c8b74 vmov r2, r3, d5 */
/* @0x2c8b78 vstr d7, [sp] */
/* @0x2c8b7c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8b80 ldr r0, [pc, #0x238] */
/* @0x2c8b84 ldrb r1, [r4, #0x24] */
/* @0x2c8b88 add r0, pc, r0 */
/* @0x2c8b8c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8b90 ldr r0, [pc, #0x22c] */
/* @0x2c8b94 ldrb r1, [r4, #0x25] */
/* @0x2c8b98 add r0, pc, r0 */
/* @0x2c8b9c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8ba0 b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278> */
/* @0x2c8ba4 ldr r0, [pc, #0x21c] */
/* @0x2c8ba8 add r0, pc, r0 */
/* @0x2c8bac bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8bb0 ldr r0, [pc, #0x214] */
/* @0x2c8bb4 mov r1, #8 */
/* @0x2c8bb8 add r0, pc, r0 */
/* @0x2c8bbc bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8bc0 ldr r1, [r4, #0x94] */
/* @0x2c8bc4 cmp r1, #0 */
/* @0x2c8bc8 ble 0x2c8c14 <_ZN9b2Fixture4DumpEi+0x220> */
/* @0x2c8bcc ldr r8, [pc, #0x1fc] */
/* @0x2c8bd0 add r6, r4, #20 */
/* @0x2c8bd4 mov r5, #0 */
/* @0x2c8bd8 add r8, pc, r8 */
/* @0x2c8bdc vldr s14, [r6, #4] */
/* @0x2c8be0 vcvt.f64.f32 d7, s14 */
/* @0x2c8be4 vldr s13, [r6] */
/* @0x2c8be8 mov r1, r5 */
/* @0x2c8bec mov r0, r8 */
/* @0x2c8bf0 add r5, r5, #1 */
/* @0x2c8bf4 add r6, r6, #8 */
/* @0x2c8bf8 vstr d7, [sp] */
/* @0x2c8bfc vcvt.f64.f32 d7, s13 */
/* @0x2c8c00 vmov r2, r3, d7 */
/* @0x2c8c04 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c08 ldr r1, [r4, #0x94] */
/* @0x2c8c0c cmp r1, r5 */
/* @0x2c8c10 bgt 0x2c8bdc <_ZN9b2Fixture4DumpEi+0x1e8> */
/* @0x2c8c14 ldr r0, [pc, #0x1b8] */
/* @0x2c8c18 add r0, pc, r0 */
/* @0x2c8c1c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c20 b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278> */
/* @0x2c8c24 ldr r0, [pc, #0x1ac] */
/* @0x2c8c28 add r0, pc, r0 */
/* @0x2c8c2c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c30 vldr s15, [r4, #8] */
/* @0x2c8c34 vcvt.f64.f32 d6, s15 */
/* @0x2c8c38 ldr r0, [pc, #0x19c] */
/* @0x2c8c3c add r0, pc, r0 */
/* @0x2c8c40 vmov r2, r3, d6 */
/* @0x2c8c44 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c48 vldr s14, [r4, #16] */
/* @0x2c8c4c vldr s13, [r4, #12] */
/* @0x2c8c50 vcvt.f64.f32 d7, s14 */
/* @0x2c8c54 ldr r0, [pc, #0x184] */
/* @0x2c8c58 add r0, pc, r0 */
/* @0x2c8c5c vcvt.f64.f32 d5, s13 */
/* @0x2c8c60 vstr d7, [sp] */
/* @0x2c8c64 vmov r2, r3, d5 */
/* @0x2c8c68 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c6c ldr r4, [pc, #0x170] */
/* @0x2c8c70 add r4, pc, r4 */
/* @0x2c8c74 mov r0, r4 */
/* @0x2c8c78 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c7c ldr r0, [pc, #0x164] */
/* @0x2c8c80 add r0, pc, r0 */
/* @0x2c8c84 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c88 mov r0, r4 */
/* @0x2c8c8c bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8c90 ldr r0, [pc, #0x154] */
/* @0x2c8c94 mov r1, r7 */
/* @0x2c8c98 add r0, pc, r0 */
/* @0x2c8c9c add sp, sp, #8 */
/* @0x2c8ca0 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2c8ca4 b 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8ca8 ldr r0, [pc, #0x140] */
/* @0x2c8cac add r0, pc, r0 */
/* @0x2c8cb0 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8cb4 vldr s15, [r4, #8] */
/* @0x2c8cb8 vcvt.f64.f32 d6, s15 */
/* @0x2c8cbc ldr r0, [pc, #0x130] */
/* @0x2c8cc0 add r0, pc, r0 */
/* @0x2c8cc4 vmov r2, r3, d6 */
/* @0x2c8cc8 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8ccc vldr s13, [r4, #28] */
/* @0x2c8cd0 vldr s14, [r4, #32] */
/* @0x2c8cd4 vcvt.f64.f32 d5, s13 */
/* @0x2c8cd8 ldr r0, [pc, #0x118] */
/* @0x2c8cdc add r0, pc, r0 */
/* @0x2c8ce0 vcvt.f64.f32 d7, s14 */
/* @0x2c8ce4 vmov r2, r3, d5 */
/* @0x2c8ce8 vstr d7, [sp] */
/* @0x2c8cec bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8cf0 vldr s13, [r4, #12] */
/* @0x2c8cf4 vldr s14, [r4, #16] */
/* @0x2c8cf8 vcvt.f64.f32 d5, s13 */
/* @0x2c8cfc ldr r0, [pc, #0xf8] */
/* @0x2c8d00 add r0, pc, r0 */
/* @0x2c8d04 vcvt.f64.f32 d7, s14 */
/* @0x2c8d08 vmov r2, r3, d5 */
/* @0x2c8d0c vstr d7, [sp] */
/* @0x2c8d10 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8d14 vldr s13, [r4, #20] */
/* @0x2c8d18 vldr s14, [r4, #24] */
/* @0x2c8d1c vcvt.f64.f32 d5, s13 */
/* @0x2c8d20 ldr r0, [pc, #0xd8] */
/* @0x2c8d24 add r0, pc, r0 */
/* @0x2c8d28 vcvt.f64.f32 d7, s14 */
/* @0x2c8d2c vmov r2, r3, d5 */
/* @0x2c8d30 vstr d7, [sp] */
/* @0x2c8d34 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8d38 vldr s13, [r4, #36] */
/* @0x2c8d3c vldr s14, [r4, #40] */
/* @0x2c8d40 vcvt.f64.f32 d5, s13 */
/* @0x2c8d44 ldr r0, [pc, #0xb8] */
/* @0x2c8d48 add r0, pc, r0 */
/* @0x2c8d4c vcvt.f64.f32 d7, s14 */
/* @0x2c8d50 vmov r2, r3, d5 */
/* @0x2c8d54 vstr d7, [sp] */
/* @0x2c8d58 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8d5c ldr r0, [pc, #0xa4] */
/* @0x2c8d60 ldrb r1, [r4, #0x2c] */
/* @0x2c8d64 add r0, pc, r0 */
/* @0x2c8d68 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8d6c ldr r0, [pc, #0x98] */
/* @0x2c8d70 ldrb r1, [r4, #0x2d] */
/* @0x2c8d74 add r0, pc, r0 */
/* @0x2c8d78 bl 0x2c6a74 <_Z5b2LogPKcz> */
/* @0x2c8d7c b 0x2c8c6c <_ZN9b2Fixture4DumpEi+0x278> */
/* @0x2c8d80 add sp, sp, #8 */
/* @0x2c8d84 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2c8d88 andeq r2, r9, r0, asr #30 */
/* @0x2c8d8c andeq r2, r9, r4, asr #30 */
/* @0x2c8d90 andeq r2, r9, r8, asr #30 */
/* @0x2c8d94 andeq r2, r9, r0, asr pc */
/* @0x2c8d98 andeq r2, r9, r8, asr pc */
/* @0x2c8d9c andeq r2, r9, r8, ror #30 */
/* @0x2c8da0 andeq r2, r9, r4, lsl #31 */
/* @0x2c8da4 muleq r9, r12, pc */
/* @0x2c8da8 andeq r3, r9, r4, ror r1 */
/* @0x2c8dac andeq r3, r9, r4, lsl r1 */
/* @0x2c8db0 andeq r3, r9, r12, lsl #2 */
/* @0x2c8db4 andeq r3, r9, r0, lsr #2 */
/* @0x2c8db8 andeq r3, r9, r8, lsr #2 */
/* @0x2c8dbc andeq r3, r9, r4, lsr r1 */
/* @0x2c8dc0 andeq r3, r9, r8, asr #2 */
/* @0x2c8dc4 andeq r3, r9, r0, ror #2 */
/* @0x2c8dc8 andeq r3, r9, r0, lsr #32 */
/* @0x2c8dcc andeq r3, r9, r12, lsr #32 */
/* @0x2c8dd0 andeq r3, r9, r0, lsr #32 */
/* @0x2c8dd4 andeq r3, r9, r4 */
/* @0x2c8dd8 andeq r2, r9, r12, lsr #28 */
/* @0x2c8ddc andeq r2, r9, r4, lsr lr */
/* @0x2c8de0 andeq r2, r9, r8, lsr lr */
/* @0x2c8de4 andeq r10, r6, r8, lsr #32 */
/* @0x2c8de8 andeq r3, r9, r0, lsr #1 */
/* @0x2c8dec andeq r3, r9, r0, lsr #1 */
/* @0x2c8df0 andeq r2, r9, r12, lsl #28 */
/* @0x2c8df4 strheq r2, [r9], -r0 */
/* @0x2c8df8 strdeq r2, r3, [r9], -r4 */
/* @0x2c8dfc strdeq r2, r3, [r9], -r12 */
/* @0x2c8e00 andeq r2, r9, r4, lsl #28 */
/* @0x2c8e04 andeq r2, r9, r12, lsl #28 */
/* @0x2c8e08 andeq r2, r9, r12, lsl lr */
/* @0x2c8e0c andeq r2, r9, r0, lsr lr */

/* ── FUNC 0x2c8e10 · b2World::b2World(b2Vec2 const&) · size=356 · insn=89 */
/* @0x2c8e10 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2c8e14 sub sp, sp, #12 */
/* @0x2c8e18 mov r4, r0 */
/* @0x2c8e1c mov r6, r1 */
/* @0x2c8e20 add r5, r4, #102400 */
/* @0x2c8e24 bl 0x2c64d0 <_ZN16b2BlockAllocatorC2Ev> */
/* @0x2c8e28 add r0, r4, #68 */
/* @0x2c8e2c movw r7, #0x9244 */
/* @0x2c8e30 bl 0x2e0f04 <_ZN16b2StackAllocatorC2Ev> */
/* @0x2c8e34 add r0, r5, #472 */
/* @0x2c8e38 bl 0x2c7850 <_ZN16b2ContactManagerC2Ev> */
/* @0x2c8e3c add r0, r5, #628 */
/* @0x2c8e40 bl 0x2d4fbc <_ZN16b2ParticleSystemC2Ev> */
/* @0x2c8e44 ldr r2, [pc, #0x120] */
/* @0x2c8e48 ldm r6, {r0, r1} */
/* @0x2c8e4c movt r7, #0x1 */
/* @0x2c8e50 ldr r2, [pc, r2] */
/* @0x2c8e54 movw r6, #0x9248 */
/* @0x2c8e58 movw lr, #0x9228 */
/* @0x2c8e5c movt r6, #0x1 */
/* @0x2c8e60 ldr r2, [r2] */
/* @0x2c8e64 movt lr, #0x1 */
/* @0x2c8e68 movw r12, #0x922c */
/* @0x2c8e6c movt r12, #0x1 */
/* @0x2c8e70 mov r3, #1 */
/* @0x2c8e74 movw r10, #0x9238 */
/* @0x2c8e78 bfi r10, r3, #16, #16 */
/* @0x2c8e7c str r2, [sp, #0x4] */
/* @0x2c8e80 add r10, r4, r10 */
/* @0x2c8e84 mov r2, #0 */
/* @0x2c8e88 movw r9, #0x9230 */
/* @0x2c8e8c str r2, [r4, r7] */
/* @0x2c8e90 movt r9, #0x1 */
/* @0x2c8e94 str r2, [r4, r6] */
/* @0x2c8e98 movw r8, #0x9234 */
/* @0x2c8e9c str r2, [r4, lr] */
/* @0x2c8ea0 movt r8, #0x1 */
/* @0x2c8ea4 str r2, [r4, r12] */
/* @0x2c8ea8 movw r7, #0x9250 */
/* @0x2c8eac movw r6, #0x9251 */
/* @0x2c8eb0 movt r7, #0x1 */
/* @0x2c8eb4 bfi r6, r3, #16, #16 */
/* @0x2c8eb8 movw lr, #0x9252 */
/* @0x2c8ebc movw r12, #0x9253 */
/* @0x2c8ec0 bfi lr, r3, #16, #16 */
/* @0x2c8ec4 bfi r12, r3, #16, #16 */
/* @0x2c8ec8 movw r11, #0x9240 */
/* @0x2c8ecc bfi r11, r3, #16, #16 */
/* @0x2c8ed0 str r2, [r4, r9] */
/* @0x2c8ed4 movw r9, #0x91d4 */
/* @0x2c8ed8 str r2, [r4, r8] */
/* @0x2c8edc bfi r9, r3, #16, #16 */
/* @0x2c8ee0 strb r3, [r4, r7] */
/* @0x2c8ee4 movw r8, #0x9224 */
/* @0x2c8ee8 strb r3, [r4, r6] */
/* @0x2c8eec bfi r8, r3, #16, #16 */
/* @0x2c8ef0 strb r2, [r4, lr] */
/* @0x2c8ef4 movw r7, #0x9348 */
/* @0x2c8ef8 strb r3, [r4, r12] */
/* @0x2c8efc bfi r7, r3, #16, #16 */
/* @0x2c8f00 strb r3, [r4, r11] */
/* @0x2c8f04 movw r6, #0x934c */
/* @0x2c8f08 stm r10, {r0, r1} */
/* @0x2c8f0c movw r10, #0x924c */
/* @0x2c8f10 bfi r10, r3, #16, #16 */
/* @0x2c8f14 bfi r6, r3, #16, #16 */
/* @0x2c8f18 add r10, r4, r10 */
/* @0x2c8f1c movw lr, #0x9350 */
/* @0x2c8f20 bfi lr, r3, #16, #16 */
/* @0x2c8f24 mov r3, #4 */
/* @0x2c8f28 str r3, [r4, r9] */
/* @0x2c8f2c mov r3, #0 */
/* @0x2c8f30 str r3, [r10] */
/* @0x2c8f34 mov r1, r2 */
/* @0x2c8f38 ldr r3, [sp, #0x4] */
/* @0x2c8f3c add r0, r5, #596 */
/* @0x2c8f40 ldr r12, [pc, #0x28] */
/* @0x2c8f44 mov r2, #32 */
/* @0x2c8f48 str r4, [r4, r8] */
/* @0x2c8f4c ldr r12, [pc, r12] */
/* @0x2c8f50 str r4, [r4, r7] */
/* @0x2c8f54 str r12, [r4, r6] */
/* @0x2c8f58 str r3, [r4, lr] */
/* @0x2c8f5c bl 0xb65b0 <memset@plt> */
/* @0x2c8f60 mov r0, r4 */
/* @0x2c8f64 add sp, sp, #12 */
/* @0x2c8f68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2c8f6c andseq r8, r2, r8, lsr #25 */
/* @0x2c8f70 ldrheq r8, [r2], -r0 */

/* ── FUNC 0x2c8e10 · b2World::b2World(b2Vec2 const&) · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c8f74 · b2World::~b2World() · size=136 · insn=34 */
/* @0x2c8f74 push {r3, r4, r5, r6, r7, lr} */
/* @0x2c8f78 movw r3, #0x9228 */
/* @0x2c8f7c movt r3, #0x1 */
/* @0x2c8f80 mov r5, r0 */
/* @0x2c8f84 ldr r2, [r0, r3] */
/* @0x2c8f88 cmp r2, #0 */
/* @0x2c8f8c beq 0x2c8fd0 <_ZN7b2WorldD2Ev+0x5c> */
/* @0x2c8f90 mov r6, #0 */
/* @0x2c8f94 ldr r3, [r2, #0x74] */
/* @0x2c8f98 ldr r7, [r2, #0x70] */
/* @0x2c8f9c cmp r3, #0 */
/* @0x2c8fa0 beq 0x2c8fc4 <_ZN7b2WorldD2Ev+0x50> */
/* @0x2c8fa4 ldr r4, [r3, #0x4] */
/* @0x2c8fa8 mov r0, r3 */
/* @0x2c8fac str r6, [r3, #0x1c] */
/* @0x2c8fb0 mov r1, r5 */
/* @0x2c8fb4 bl 0x2c85f0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator> */
/* @0x2c8fb8 cmp r4, #0 */
/* @0x2c8fbc mov r3, r4 */
/* @0x2c8fc0 bne 0x2c8fa4 <_ZN7b2WorldD2Ev+0x30> */
/* @0x2c8fc4 cmp r7, #0 */
/* @0x2c8fc8 movne r2, r7 */
/* @0x2c8fcc bne 0x2c8f94 <_ZN7b2WorldD2Ev+0x20> */
/* @0x2c8fd0 add r4, r5, #102400 */
/* @0x2c8fd4 add r0, r4, #628 */
/* @0x2c8fd8 bl 0x2d50c8 <_ZN16b2ParticleSystemD2Ev> */
/* @0x2c8fdc add r0, r4, #472 */
/* @0x2c8fe0 bl 0x2dc7f4 <_ZN12b2BroadPhaseD2Ev> */
/* @0x2c8fe4 add r0, r5, #68 */
/* @0x2c8fe8 bl 0x2e0f40 <_ZN16b2StackAllocatorD2Ev> */
/* @0x2c8fec mov r0, r5 */
/* @0x2c8ff0 bl 0x2c6578 <_ZN16b2BlockAllocatorD2Ev> */
/* @0x2c8ff4 mov r0, r5 */
/* @0x2c8ff8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x2c8f74 · b2World::~b2World() · alias of the symbol above · insn=0 */

/* ── FUNC 0x2c8ffc · b2World::SetDestructionListener(b2DestructionListener*) · size=16 · insn=4 */
/* @0x2c8ffc movw r3, #0x9244 */
/* @0x2c9000 movt r3, #0x1 */
/* @0x2c9004 str r1, [r0, r3] */
/* @0x2c9008 bx lr */

/* ── FUNC 0x2c900c · b2World::SetContactFilter(b2ContactFilter*) · size=16 · insn=4 */
/* @0x2c900c movw r3, #0x921c */
/* @0x2c9010 movt r3, #0x1 */
/* @0x2c9014 str r1, [r0, r3] */
/* @0x2c9018 bx lr */

/* ── FUNC 0x2c901c · b2World::SetContactListener(b2ContactListener*) · size=16 · insn=4 */
/* @0x2c901c movw r3, #0x9220 */
/* @0x2c9020 movt r3, #0x1 */
/* @0x2c9024 str r1, [r0, r3] */
/* @0x2c9028 bx lr */
