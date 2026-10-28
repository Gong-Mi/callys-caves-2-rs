/* libyoyo.so 覆盖卡组 0233
 * 函数 0x280b1c..0x2818e0，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x280b1c · lh_table_lookup_entry · size=144 · insn=36 */
/* @0x280b1c push {r3, r4, r5, r6, r7, lr} */
/* @0x280b20 mov r5, r0 */
/* @0x280b24 ldr r3, [r0, #0x30] */
/* @0x280b28 mov r0, r1 */
/* @0x280b2c mov r6, r1 */
/* @0x280b30 blx r3 */
/* @0x280b34 ldr r1, [r5] */
/* @0x280b38 bl 0x318cf0 <__aeabi_uidivmod> */
/* @0x280b3c ldr r3, [r5, #0x10] */
/* @0x280b40 ldr r2, [r5, #0x28] */
/* @0x280b44 add r3, r3, #1 */
/* @0x280b48 str r3, [r5, #0x10] */
/* @0x280b4c mov r4, r1 */
/* @0x280b50 b 0x280b80 <lh_table_lookup_entry+0x64> */
/* @0x280b54 cmn r3, #2 */
/* @0x280b58 beq 0x280b70 <lh_table_lookup_entry+0x54> */
/* @0x280b5c ldr r3, [r5, #0x34] */
/* @0x280b60 blx r3 */
/* @0x280b64 cmp r0, #0 */
/* @0x280b68 bne 0x280ba0 <lh_table_lookup_entry+0x84> */
/* @0x280b6c ldr r2, [r5, #0x28] */
/* @0x280b70 ldr r3, [r5] */
/* @0x280b74 add r4, r4, #1 */
/* @0x280b78 cmp r4, r3 */
/* @0x280b7c moveq r4, #0 */
/* @0x280b80 ldr r3, [r2, r4, lsl #4] */
/* @0x280b84 mov r1, r6 */
/* @0x280b88 lsl r7, r4, #4 */
/* @0x280b8c cmn r3, #1 */
/* @0x280b90 mov r0, r3 */
/* @0x280b94 bne 0x280b54 <lh_table_lookup_entry+0x38> */
/* @0x280b98 mov r0, #0 */
/* @0x280b9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x280ba0 ldr r0, [r5, #0x28] */
/* @0x280ba4 add r0, r0, r7 */
/* @0x280ba8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x280bac · lh_table_lookup · size=20 · insn=5 */
/* @0x280bac push {r3, lr} */
/* @0x280bb0 bl 0x280b1c <lh_table_lookup_entry> */
/* @0x280bb4 cmp r0, #0 */
/* @0x280bb8 ldrne r0, [r0, #0x4] */
/* @0x280bbc pop {r3, pc} */

/* ── FUNC 0x280bc0 · lh_table_delete_entry · size=224 · insn=56 */
/* @0x280bc0 push {r3, r4, r5, lr} */
/* @0x280bc4 mov r4, r0 */
/* @0x280bc8 ldr r3, [r0, #0x28] */
/* @0x280bcc rsb r2, r3, r1 */
/* @0x280bd0 asrs r2, r2, #4 */
/* @0x280bd4 bmi 0x280c98 <lh_table_delete_entry+0xd8> */
/* @0x280bd8 ldr r0, [r3, r2, lsl #4] */
/* @0x280bdc lsl r5, r2, #4 */
/* @0x280be0 add r3, r3, r5 */
/* @0x280be4 add r2, r0, #2 */
/* @0x280be8 cmp r2, #1 */
/* @0x280bec bls 0x280c90 <lh_table_delete_entry+0xd0> */
/* @0x280bf0 ldr r2, [r4, #0x2c] */
/* @0x280bf4 ldr r0, [r4, #0x4] */
/* @0x280bf8 cmp r2, #0 */
/* @0x280bfc sub r0, r0, #1 */
/* @0x280c00 str r0, [r4, #0x4] */
/* @0x280c04 beq 0x280c18 <lh_table_delete_entry+0x58> */
/* @0x280c08 mov r0, r1 */
/* @0x280c0c blx r2 */
/* @0x280c10 ldr r3, [r4, #0x28] */
/* @0x280c14 add r3, r3, r5 */
/* @0x280c18 ldr r0, [r4, #0x24] */
/* @0x280c1c mvn r1, #1 */
/* @0x280c20 mov r2, #0 */
/* @0x280c24 str r1, [r3] */
/* @0x280c28 cmp r0, r3 */
/* @0x280c2c str r2, [r3, #0x4] */
/* @0x280c30 ldr r1, [r4, #0x20] */
/* @0x280c34 beq 0x280c64 <lh_table_delete_entry+0xa4> */
/* @0x280c38 cmp r3, r1 */
/* @0x280c3c beq 0x280c80 <lh_table_delete_entry+0xc0> */
/* @0x280c40 ldr r1, [r3, #0x8] */
/* @0x280c44 ldr r2, [r3, #0xc] */
/* @0x280c48 str r1, [r2, #0x8] */
/* @0x280c4c ldr r1, [r3, #0x8] */
/* @0x280c50 str r2, [r1, #0xc] */
/* @0x280c54 mov r0, #0 */
/* @0x280c58 str r0, [r3, #0xc] */
/* @0x280c5c str r0, [r3, #0x8] */
/* @0x280c60 pop {r3, r4, r5, pc} */
/* @0x280c64 cmp r3, r1 */
/* @0x280c68 streq r2, [r4, #0x24] */
/* @0x280c6c streq r2, [r4, #0x20] */
/* @0x280c70 ldrne r1, [r3, #0xc] */
/* @0x280c74 strne r2, [r1, #0x8] */
/* @0x280c78 strne r1, [r4, #0x24] */
/* @0x280c7c b 0x280c54 <lh_table_delete_entry+0x94> */
/* @0x280c80 ldr r1, [r3, #0x8] */
/* @0x280c84 str r2, [r1, #0xc] */
/* @0x280c88 str r1, [r4, #0x20] */
/* @0x280c8c b 0x280c54 <lh_table_delete_entry+0x94> */
/* @0x280c90 mvn r0, #0 */
/* @0x280c94 pop {r3, r4, r5, pc} */
/* @0x280c98 mvn r0, #1 */
/* @0x280c9c pop {r3, r4, r5, pc} */

/* ── FUNC 0x280ca0 · lh_table_delete · size=40 · insn=10 */
/* @0x280ca0 push {r4, lr} */
/* @0x280ca4 mov r4, r0 */
/* @0x280ca8 bl 0x280b1c <lh_table_lookup_entry> */
/* @0x280cac subs r1, r0, #0 */
/* @0x280cb0 beq 0x280cc0 <lh_table_delete+0x20> */
/* @0x280cb4 mov r0, r4 */
/* @0x280cb8 pop {r4, lr} */
/* @0x280cbc b 0x280bc0 <lh_table_delete_entry> */
/* @0x280cc0 mvn r0, #0 */
/* @0x280cc4 pop {r4, pc} */

/* ── FUNC 0x280cc8 · printbuf_new · size=88 · insn=22 */
/* @0x280cc8 push {r3, r4, r5, lr} */
/* @0x280ccc mov r0, #1 */
/* @0x280cd0 mov r1, #12 */
/* @0x280cd4 bl 0xb6c34 <calloc@plt> */
/* @0x280cd8 subs r4, r0, #0 */
/* @0x280cdc beq 0x280d0c <printbuf_new+0x44> */
/* @0x280ce0 mov r0, #32 */
/* @0x280ce4 mov r3, #0 */
/* @0x280ce8 str r0, [r4, #0x8] */
/* @0x280cec str r3, [r4, #0x4] */
/* @0x280cf0 bl 0xb6544 <malloc@plt> */
/* @0x280cf4 mov r5, r0 */
/* @0x280cf8 cmp r5, #0 */
/* @0x280cfc mov r0, r4 */
/* @0x280d00 str r5, [r4] */
/* @0x280d04 beq 0x280d14 <printbuf_new+0x4c> */
/* @0x280d08 pop {r3, r4, r5, pc} */
/* @0x280d0c mov r0, r4 */
/* @0x280d10 pop {r3, r4, r5, pc} */
/* @0x280d14 bl 0xb655c <free@plt> */
/* @0x280d18 mov r0, r5 */
/* @0x280d1c pop {r3, r4, r5, pc} */

/* ── FUNC 0x280d20 · printbuf_memappend · size=156 · insn=39 */
/* @0x280d20 push {r3, r4, r5, r6, r7, lr} */
/* @0x280d24 mov r5, r2 */
/* @0x280d28 ldr r3, [r0, #0x4] */
/* @0x280d2c mov r4, r0 */
/* @0x280d30 ldr r2, [r0, #0x8] */
/* @0x280d34 mov r6, r1 */
/* @0x280d38 rsb r0, r3, r2 */
/* @0x280d3c cmp r0, r5 */
/* @0x280d40 ble 0x280d78 <printbuf_memappend+0x58> */
/* @0x280d44 ldr r0, [r4] */
/* @0x280d48 mov r2, r5 */
/* @0x280d4c add r0, r0, r3 */
/* @0x280d50 mov r1, r6 */
/* @0x280d54 bl 0xb65bc <memcpy@plt> */
/* @0x280d58 ldr r2, [r4, #0x4] */
/* @0x280d5c ldr r3, [r4] */
/* @0x280d60 mov r0, r5 */
/* @0x280d64 add r5, r5, r2 */
/* @0x280d68 mov r2, #0 */
/* @0x280d6c str r5, [r4, #0x4] */
/* @0x280d70 strb r2, [r3, r5] */
/* @0x280d74 pop {r3, r4, r5, r6, r7, pc} */
/* @0x280d78 add r7, r3, r5 */
/* @0x280d7c lsl r2, r2, #1 */
/* @0x280d80 add r7, r7, #8 */
/* @0x280d84 ldr r0, [r4] */
/* @0x280d88 cmp r7, r2 */
/* @0x280d8c movlt r7, r2 */
/* @0x280d90 mov r1, r7 */
/* @0x280d94 bl 0xb6c28 <realloc@plt> */
/* @0x280d98 subs r2, r0, #0 */
/* @0x280d9c beq 0x280db4 <printbuf_memappend+0x94> */
/* @0x280da0 ldr r3, [r4, #0x4] */
/* @0x280da4 mov r0, r2 */
/* @0x280da8 str r7, [r4, #0x8] */
/* @0x280dac str r2, [r4] */
/* @0x280db0 b 0x280d48 <printbuf_memappend+0x28> */
/* @0x280db4 mvn r0, #0 */
/* @0x280db8 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x280dbc · sprintbuf · size=224 · insn=56 */
/* @0x280dbc push {r1, r2, r3} */
/* @0x280dc0 mov r1, #128 */
/* @0x280dc4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x280dc8 sub sp, sp, #144 */
/* @0x280dcc ldr r4, [pc, #0xc4] */
/* @0x280dd0 add r5, sp, #176 */
/* @0x280dd4 ldr r8, [sp, #0xac] */
/* @0x280dd8 add r7, sp, #12 */
/* @0x280ddc ldr r4, [pc, r4] */
/* @0x280de0 mov r3, r5 */
/* @0x280de4 mov r9, r0 */
/* @0x280de8 mov r0, r7 */
/* @0x280dec ldr r12, [r4] */
/* @0x280df0 mov r2, r8 */
/* @0x280df4 str r5, [sp, #0x4] */
/* @0x280df8 str r12, [sp, #0x8c] */
/* @0x280dfc bl 0xb6610 <vsnprintf@plt> */
/* @0x280e00 cmn r0, #1 */
/* @0x280e04 mov r6, r0 */
/* @0x280e08 movne r3, #0 */
/* @0x280e0c moveq r3, #1 */
/* @0x280e10 cmp r0, #127 */
/* @0x280e14 orrgt r3, r3, #1 */
/* @0x280e18 cmp r3, #0 */
/* @0x280e1c beq 0x280e60 <sprintbuf+0xa4> */
/* @0x280e20 mov r1, r8 */
/* @0x280e24 mov r2, r5 */
/* @0x280e28 add r0, sp, #8 */
/* @0x280e2c str r5, [sp, #0x4] */
/* @0x280e30 bl 0xb6d24 <vasprintf@plt> */
/* @0x280e34 cmn r0, #1 */
/* @0x280e38 mov r6, r0 */
/* @0x280e3c beq 0x280e70 <sprintbuf+0xb4> */
/* @0x280e40 ldr r1, [sp, #0x8] */
/* @0x280e44 mov r2, r6 */
/* @0x280e48 mov r0, r9 */
/* @0x280e4c bl 0x280d20 <printbuf_memappend> */
/* @0x280e50 ldr r0, [sp, #0x8] */
/* @0x280e54 bl 0xb655c <free@plt> */
/* @0x280e58 mov r0, r6 */
/* @0x280e5c b 0x280e74 <sprintbuf+0xb8> */
/* @0x280e60 mov r0, r9 */
/* @0x280e64 mov r1, r7 */
/* @0x280e68 mov r2, r6 */
/* @0x280e6c bl 0x280d20 <printbuf_memappend> */
/* @0x280e70 mov r0, r6 */
/* @0x280e74 ldr r1, [sp, #0x8c] */
/* @0x280e78 ldr r3, [r4] */
/* @0x280e7c cmp r1, r3 */
/* @0x280e80 bne 0x280e94 <sprintbuf+0xd8> */
/* @0x280e84 add sp, sp, #144 */
/* @0x280e88 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x280e8c add sp, sp, #12 */
/* @0x280e90 bx lr */
/* @0x280e94 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x280e98 andseq r12, r6, r4, ror r11 */

/* ── FUNC 0x280e9c · printbuf_reset · size=20 · insn=5 */
/* @0x280e9c ldr r2, [r0] */
/* @0x280ea0 mov r3, #0 */
/* @0x280ea4 strb r3, [r2] */
/* @0x280ea8 str r3, [r0, #0x4] */
/* @0x280eac bx lr */

/* ── FUNC 0x280eb0 · printbuf_free · size=32 · insn=8 */
/* @0x280eb0 push {r4, lr} */
/* @0x280eb4 subs r4, r0, #0 */
/* @0x280eb8 popeq {r4, pc} */
/* @0x280ebc ldr r0, [r4] */
/* @0x280ec0 bl 0xb655c <free@plt> */
/* @0x280ec4 mov r0, r4 */
/* @0x280ec8 pop {r4, lr} */
/* @0x280ecc b 0xb655c <free@plt> */

/* ── FUNC 0x280ed0 · anon_280ed0 · size=108 · insn=28 */
/* @0x280ed0 push {r4, r5, r6, r7, r8, lr} */
/* @0x280ed4 vpush {d8} */
/* @0x280ed8 mov r8, r0 */
/* @0x280edc mov r0, r1 */
/* @0x280ee0 mov r1, r2 */
/* @0x280ee4 mov r7, r2 */
/* @0x280ee8 vmov.f32 s16, s0 */
/* @0x280eec bl 0x318d10 <__divsi3> */
/* @0x280ef0 subs r0, r0, #2 */
/* @0x280ef4 moveq r0, r7 */
/* @0x280ef8 beq 0x280f38 <printbuf_free+0x88> */
/* @0x280efc asr r4, r0, #1 */
/* @0x280f00 mov r12, #0 */
/* @0x280f04 add r5, r4, #1 */
/* @0x280f08 mul r6, r7, r5 */
/* @0x280f0c add r6, r8, r6, lsl #2 */
/* @0x280f10 vldr s15, [r6] */
/* @0x280f14 vcmpe.f32 s15, s16 */
/* @0x280f18 vmrs APSR_nzcv, fpscr */
/* @0x280f1c movls r12, r5 */
/* @0x280f20 movhi r0, r4 */
/* @0x280f24 add r4, r12, r0 */
/* @0x280f28 cmp r12, r0 */
/* @0x280f2c asr r4, r4, #1 */
/* @0x280f30 bne 0x280f04 <printbuf_free+0x54> */
/* @0x280f34 mla r0, r12, r7, r7 */
/* @0x280f38 vpop {d8} */
/* @0x280f3c pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x280f40 · _spEventTimeline_apply · size=468 · insn=117 */
/* @0x280f40 push {r4, r5, r6, r7, r8, lr} */
/* @0x280f44 vpush {d8} */
/* @0x280f48 sub sp, sp, #16 */
/* @0x280f4c mov r4, r0 */
/* @0x280f50 vmov s15, r2 */
/* @0x280f54 ldr r5, [sp, #0x30] */
/* @0x280f58 vmov s16, r3 */
/* @0x280f5c ldr r6, [sp, #0x34] */
/* @0x280f60 cmp r5, #0 */
/* @0x280f64 beq 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x280f68 vcmpe.f32 s15, s16 */
/* @0x280f6c vmrs APSR_nzcv, fpscr */
/* @0x280f70 bgt 0x281040 <_spEventTimeline_apply+0x100> */
/* @0x280f74 ldr r3, [r0, #0x8] */
/* @0x280f78 ldr r0, [r0, #0xc] */
/* @0x280f7c add r3, r0, r3, lsl #2 */
/* @0x280f80 vldr s14, [r3, #-4] */
/* @0x280f84 vcmpe.f32 s15, s14 */
/* @0x280f88 vmrs APSR_nzcv, fpscr */
/* @0x280f8c bge 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x280f90 vldr s14, [r0] */
/* @0x280f94 vcmpe.f32 s16, s14 */
/* @0x280f98 vmrs APSR_nzcv, fpscr */
/* @0x280f9c bmi 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x280fa0 vcmpe.f32 s15, s14 */
/* @0x280fa4 ldr r8, [r4, #0x8] */
/* @0x280fa8 vmrs APSR_nzcv, fpscr */
/* @0x280fac movmi r3, #0 */
/* @0x280fb0 bpl 0x281074 <_spEventTimeline_apply+0x134> */
/* @0x280fb4 cmp r3, r8 */
/* @0x280fb8 bge 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x280fbc lsl r1, r3, #2 */
/* @0x280fc0 add r0, r0, r1 */
/* @0x280fc4 vldr s15, [r0] */
/* @0x280fc8 vcmpe.f32 s16, s15 */
/* @0x280fcc vmrs APSR_nzcv, fpscr */
/* @0x280fd0 blt 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x280fd4 ldr r0, [r6] */
/* @0x280fd8 add r2, r1, #4 */
/* @0x280fdc add r8, r0, #1 */
/* @0x280fe0 rsb r8, r3, r8 */
/* @0x280fe4 add r0, r5, r0, lsl #2 */
/* @0x280fe8 b 0x281008 <_spEventTimeline_apply+0xc8> */
/* @0x280fec ldr r12, [r4, #0xc] */
/* @0x280ff0 add r2, r12, r2 */
/* @0x280ff4 vldr s15, [r2] */
/* @0x280ff8 vcmpe.f32 s16, s15 */
/* @0x280ffc mov r2, r7 */
/* @0x281000 vmrs APSR_nzcv, fpscr */
/* @0x281004 blt 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x281008 ldr r5, [r4, #0x10] */
/* @0x28100c add r12, r8, r3 */
/* @0x281010 add r3, r3, #1 */
/* @0x281014 add r7, r2, #4 */
/* @0x281018 ldr r5, [r5, r1] */
/* @0x28101c mov r1, r2 */
/* @0x281020 str r5, [r0], #4 */
/* @0x281024 str r12, [r6] */
/* @0x281028 ldr r12, [r4, #0x8] */
/* @0x28102c cmp r12, r3 */
/* @0x281030 bgt 0x280fec <_spEventTimeline_apply+0xac> */
/* @0x281034 add sp, sp, #16 */
/* @0x281038 vpop {d8} */
/* @0x28103c pop {r4, r5, r6, r7, r8, pc} */
/* @0x281040 vldr s15, [sp, #56] */
/* @0x281044 str r5, [sp] */
/* @0x281048 vstr s15, [sp, #8] */
/* @0x28104c str r6, [sp, #0x4] */
/* @0x281050 mov r3, #1325400064 */
/* @0x281054 bl 0x280f40 <_spEventTimeline_apply> */
/* @0x281058 ldr r0, [r4, #0xc] */
/* @0x28105c vldr s14, [r0] */
/* @0x281060 vcmpe.f32 s16, s14 */
/* @0x281064 vmov.f32 s15, #-1.000000e+00 */
/* @0x281068 vmrs APSR_nzcv, fpscr */
/* @0x28106c bpl 0x280fa0 <_spEventTimeline_apply+0x60> */
/* @0x281070 b 0x281034 <_spEventTimeline_apply+0xf4> */
/* @0x281074 subs r2, r8, #2 */
/* @0x281078 beq 0x281108 <_spEventTimeline_apply+0x1c8> */
/* @0x28107c asr r1, r2, #1 */
/* @0x281080 mov r3, #0 */
/* @0x281084 add r12, r1, #1 */
/* @0x281088 add r7, r0, r12, lsl #2 */
/* @0x28108c vldr s14, [r7] */
/* @0x281090 vcmpe.f32 s15, s14 */
/* @0x281094 vmrs APSR_nzcv, fpscr */
/* @0x281098 movge r3, r12 */
/* @0x28109c movlt r2, r1 */
/* @0x2810a0 add r1, r3, r2 */
/* @0x2810a4 cmp r3, r2 */
/* @0x2810a8 asr r1, r1, #1 */
/* @0x2810ac bne 0x281084 <_spEventTimeline_apply+0x144> */
/* @0x2810b0 add r3, r3, #1 */
/* @0x2810b4 cmp r3, #0 */
/* @0x2810b8 lsl r2, r3, #2 */
/* @0x2810bc add r1, r0, r2 */
/* @0x2810c0 vldr s14, [r1] */
/* @0x2810c4 ble 0x280fb4 <_spEventTimeline_apply+0x74> */
/* @0x2810c8 sub r2, r2, #4 */
/* @0x2810cc add r2, r0, r2 */
/* @0x2810d0 vldr s15, [r2] */
/* @0x2810d4 vcmp.f32 s15, s14 */
/* @0x2810d8 vmrs APSR_nzcv, fpscr */
/* @0x2810dc bne 0x280fb4 <_spEventTimeline_apply+0x74> */
/* @0x2810e0 add r2, r0, r3, lsl #2 */
/* @0x2810e4 b 0x2810f8 <_spEventTimeline_apply+0x1b8> */
/* @0x2810e8 vldr s15, [r2, #-4] */
/* @0x2810ec vcmp.f32 s15, s14 */
/* @0x2810f0 vmrs APSR_nzcv, fpscr */
/* @0x2810f4 bne 0x280fb4 <_spEventTimeline_apply+0x74> */
/* @0x2810f8 subs r3, r3, #1 */
/* @0x2810fc sub r2, r2, #4 */
/* @0x281100 bne 0x2810e8 <_spEventTimeline_apply+0x1a8> */
/* @0x281104 b 0x280fb4 <_spEventTimeline_apply+0x74> */
/* @0x281108 vldr s14, [r0, #4] */
/* @0x28110c mov r3, #1 */
/* @0x281110 b 0x2810cc <_spEventTimeline_apply+0x18c> */

/* ── FUNC 0x281114 · _spAttachmentTimeline_apply · size=188 · insn=47 */
/* @0x281114 vmov s15, r3 */
/* @0x281118 push {r4, r5, r6, lr} */
/* @0x28111c ldr r5, [r0, #0xc] */
/* @0x281120 vldr s14, [r5] */
/* @0x281124 vcmpe.f32 s14, s15 */
/* @0x281128 vmrs APSR_nzcv, fpscr */
/* @0x28112c popgt {r4, r5, r6, pc} */
/* @0x281130 ldr r12, [r0, #0x8] */
/* @0x281134 sub r3, r12, #-1073741823 */
/* @0x281138 lsl r3, r3, #2 */
/* @0x28113c add r2, r5, r3 */
/* @0x281140 vldr s14, [r2] */
/* @0x281144 vcmpe.f32 s15, s14 */
/* @0x281148 vmrs APSR_nzcv, fpscr */
/* @0x28114c blt 0x28118c <_spAttachmentTimeline_apply+0x78> */
/* @0x281150 ldr r2, [r0, #0x14] */
/* @0x281154 ldr r12, [r0, #0x10] */
/* @0x281158 ldr r0, [r1, #0x14] */
/* @0x28115c ldr r2, [r2, r3] */
/* @0x281160 cmp r2, #0 */
/* @0x281164 ldr r4, [r0, r12, lsl #2] */
/* @0x281168 moveq r1, r2 */
/* @0x28116c beq 0x281180 <_spAttachmentTimeline_apply+0x6c> */
/* @0x281170 mov r0, r1 */
/* @0x281174 mov r1, r12 */
/* @0x281178 bl 0x28a314 <spSkeleton_getAttachmentForSlotIndex> */
/* @0x28117c mov r1, r0 */
/* @0x281180 mov r0, r4 */
/* @0x281184 pop {r4, r5, r6, lr} */
/* @0x281188 b 0x28ee1c <spSlot_setAttachment> */
/* @0x28118c subs r3, r12, #2 */
/* @0x281190 beq 0x281150 <_spAttachmentTimeline_apply+0x3c> */
/* @0x281194 asr r12, r3, #1 */
/* @0x281198 mov r2, #0 */
/* @0x28119c add r4, r12, #1 */
/* @0x2811a0 add r6, r5, r4, lsl #2 */
/* @0x2811a4 vldr s14, [r6] */
/* @0x2811a8 vcmpe.f32 s15, s14 */
/* @0x2811ac vmrs APSR_nzcv, fpscr */
/* @0x2811b0 movge r2, r4 */
/* @0x2811b4 movlt r3, r12 */
/* @0x2811b8 add r12, r2, r3 */
/* @0x2811bc cmp r2, r3 */
/* @0x2811c0 asr r12, r12, #1 */
/* @0x2811c4 bne 0x28119c <_spAttachmentTimeline_apply+0x88> */
/* @0x2811c8 lsl r3, r2, #2 */
/* @0x2811cc b 0x281150 <_spAttachmentTimeline_apply+0x3c> */

/* ── FUNC 0x2811d0 · _spDrawOrderTimeline_apply · size=228 · insn=57 */
/* @0x2811d0 vmov s15, r3 */
/* @0x2811d4 push {r4, r5, r6} */
/* @0x2811d8 ldr r5, [r0, #0xc] */
/* @0x2811dc vldr s14, [r5] */
/* @0x2811e0 vcmpe.f32 s14, s15 */
/* @0x2811e4 vmrs APSR_nzcv, fpscr */
/* @0x2811e8 bgt 0x281250 <_spDrawOrderTimeline_apply+0x80> */
/* @0x2811ec ldr r12, [r0, #0x8] */
/* @0x2811f0 sub r3, r12, #-1073741823 */
/* @0x2811f4 lsl r3, r3, #2 */
/* @0x2811f8 add r2, r5, r3 */
/* @0x2811fc vldr s14, [r2] */
/* @0x281200 vcmpe.f32 s15, s14 */
/* @0x281204 vmrs APSR_nzcv, fpscr */
/* @0x281208 blt 0x281258 <_spDrawOrderTimeline_apply+0x88> */
/* @0x28120c ldr r12, [r0, #0x10] */
/* @0x281210 ldr r4, [r12, r3] */
/* @0x281214 cmp r4, #0 */
/* @0x281218 beq 0x28129c <_spDrawOrderTimeline_apply+0xcc> */
/* @0x28121c ldr r5, [r0, #0x14] */
/* @0x281220 cmp r5, #0 */
/* @0x281224 lslgt r5, r5, #2 */
/* @0x281228 movgt r3, #0 */
/* @0x28122c ble 0x281250 <_spDrawOrderTimeline_apply+0x80> */
/* @0x281230 ldr r12, [r4, r3] */
/* @0x281234 ldr r0, [r1, #0x14] */
/* @0x281238 ldr r2, [r1, #0x18] */
/* @0x28123c ldr r0, [r0, r12, lsl #2] */
/* @0x281240 str r0, [r2, r3] */
/* @0x281244 add r3, r3, #4 */
/* @0x281248 cmp r3, r5 */
/* @0x28124c bne 0x281230 <_spDrawOrderTimeline_apply+0x60> */
/* @0x281250 pop {r4, r5, r6} */
/* @0x281254 bx lr */
/* @0x281258 subs r3, r12, #2 */
/* @0x28125c beq 0x28120c <_spDrawOrderTimeline_apply+0x3c> */
/* @0x281260 asr r12, r3, #1 */
/* @0x281264 mov r2, #0 */
/* @0x281268 add r4, r12, #1 */
/* @0x28126c add r6, r5, r4, lsl #2 */
/* @0x281270 vldr s14, [r6] */
/* @0x281274 vcmpe.f32 s15, s14 */
/* @0x281278 vmrs APSR_nzcv, fpscr */
/* @0x28127c movge r2, r4 */
/* @0x281280 movlt r3, r12 */
/* @0x281284 add r12, r2, r3 */
/* @0x281288 cmp r2, r3 */
/* @0x28128c asr r12, r12, #1 */
/* @0x281290 bne 0x281268 <_spDrawOrderTimeline_apply+0x98> */
/* @0x281294 lsl r3, r2, #2 */
/* @0x281298 b 0x28120c <_spDrawOrderTimeline_apply+0x3c> */
/* @0x28129c ldr r2, [r0, #0x14] */
/* @0x2812a0 pop {r4, r5, r6} */
/* @0x2812a4 ldr r0, [r1, #0x18] */
/* @0x2812a8 lsl r2, r2, #2 */
/* @0x2812ac ldr r1, [r1, #0x14] */
/* @0x2812b0 b 0xb65bc <memcpy@plt> */

/* ── FUNC 0x2812b4 · spAnimation_create · size=116 · insn=29 */
/* @0x2812b4 push {r3, r4, r5, r6, r7, lr} */
/* @0x2812b8 mov r3, #38 */
/* @0x2812bc ldr r5, [pc, #0x60] */
/* @0x2812c0 mov r6, r0 */
/* @0x2812c4 mov r7, r1 */
/* @0x2812c8 mov r0, #1 */
/* @0x2812cc add r5, pc, r5 */
/* @0x2812d0 mov r1, #16 */
/* @0x2812d4 mov r2, r5 */
/* @0x2812d8 bl 0x285c4c <_calloc> */
/* @0x2812dc mov r4, r0 */
/* @0x2812e0 mov r0, r6 */
/* @0x2812e4 bl 0xb6538 <strlen@plt> */
/* @0x2812e8 mov r1, r5 */
/* @0x2812ec mov r2, #39 */
/* @0x2812f0 add r0, r0, #1 */
/* @0x2812f4 bl 0x285c10 <_malloc> */
/* @0x2812f8 mov r1, r6 */
/* @0x2812fc str r0, [r4] */
/* @0x281300 bl 0xb65a4 <strcpy@plt> */
/* @0x281304 str r7, [r4, #0x8] */
/* @0x281308 lsl r0, r7, #2 */
/* @0x28130c mov r1, r5 */
/* @0x281310 mov r2, #41 */
/* @0x281314 bl 0x285c10 <_malloc> */
/* @0x281318 str r0, [r4, #0xc] */
/* @0x28131c mov r0, r4 */
/* @0x281320 pop {r3, r4, r5, r6, r7, pc} */
/* @0x281324 andeq r6, sp, r4, lsl #3 */

/* ── FUNC 0x281328 · _spTimeline_init · size=60 · insn=15 */
/* @0x281328 push {r4, r5, r6, lr} */
/* @0x28132c mov r6, r2 */
/* @0x281330 ldr r2, [pc, #0x28] */
/* @0x281334 mov r4, r0 */
/* @0x281338 str r1, [r0] */
/* @0x28133c mov r5, r3 */
/* @0x281340 mov r0, #1 */
/* @0x281344 mov r1, #8 */
/* @0x281348 add r2, pc, r2 */
/* @0x28134c mov r3, #93 */
/* @0x281350 bl 0x285c4c <_calloc> */
/* @0x281354 str r0, [r4, #0x4] */
/* @0x281358 stm r0, {r5, r6} */
/* @0x28135c pop {r4, r5, r6, pc} */
/* @0x281360 andeq r6, sp, r8, lsl #2 */

/* ── FUNC 0x281364 · _spTimeline_deinit · size=8 · insn=2 */
/* @0x281364 ldr r0, [r0, #0x4] */
/* @0x281368 b 0x285c80 <_free> */

/* ── FUNC 0x28136c · _spAttachmentTimeline_dispose · size=84 · insn=21 */
/* @0x28136c push {r3, r4, r5, lr} */
/* @0x281370 mov r5, r0 */
/* @0x281374 bl 0x281364 <_spTimeline_deinit> */
/* @0x281378 ldr r3, [r5, #0x8] */
/* @0x28137c cmp r3, #0 */
/* @0x281380 movgt r4, #0 */
/* @0x281384 ble 0x2813a4 <_spAttachmentTimeline_dispose+0x38> */
/* @0x281388 ldr r3, [r5, #0x14] */
/* @0x28138c ldr r0, [r3, r4, lsl #2] */
/* @0x281390 add r4, r4, #1 */
/* @0x281394 bl 0x285c80 <_free> */
/* @0x281398 ldr r3, [r5, #0x8] */
/* @0x28139c cmp r3, r4 */
/* @0x2813a0 bgt 0x281388 <_spAttachmentTimeline_dispose+0x1c> */
/* @0x2813a4 ldr r0, [r5, #0x14] */
/* @0x2813a8 bl 0x285c80 <_free> */
/* @0x2813ac ldr r0, [r5, #0xc] */
/* @0x2813b0 bl 0x285c80 <_free> */
/* @0x2813b4 mov r0, r5 */
/* @0x2813b8 pop {r3, r4, r5, lr} */
/* @0x2813bc b 0x285c80 <_free> */

/* ── FUNC 0x2813c0 · _spEventTimeline_dispose · size=84 · insn=21 */
/* @0x2813c0 push {r3, r4, r5, lr} */
/* @0x2813c4 mov r5, r0 */
/* @0x2813c8 bl 0x281364 <_spTimeline_deinit> */
/* @0x2813cc ldr r3, [r5, #0x8] */
/* @0x2813d0 cmp r3, #0 */
/* @0x2813d4 movgt r4, #0 */
/* @0x2813d8 ble 0x2813f8 <_spEventTimeline_dispose+0x38> */
/* @0x2813dc ldr r3, [r5, #0x10] */
/* @0x2813e0 ldr r0, [r3, r4, lsl #2] */
/* @0x2813e4 add r4, r4, #1 */
/* @0x2813e8 bl 0x285b78 <spEvent_dispose> */
/* @0x2813ec ldr r3, [r5, #0x8] */
/* @0x2813f0 cmp r3, r4 */
/* @0x2813f4 bgt 0x2813dc <_spEventTimeline_dispose+0x1c> */
/* @0x2813f8 ldr r0, [r5, #0x10] */
/* @0x2813fc bl 0x285c80 <_free> */
/* @0x281400 ldr r0, [r5, #0xc] */
/* @0x281404 bl 0x285c80 <_free> */
/* @0x281408 mov r0, r5 */
/* @0x28140c pop {r3, r4, r5, lr} */
/* @0x281410 b 0x285c80 <_free> */

/* ── FUNC 0x281414 · _spDrawOrderTimeline_dispose · size=84 · insn=21 */
/* @0x281414 push {r3, r4, r5, lr} */
/* @0x281418 mov r5, r0 */
/* @0x28141c bl 0x281364 <_spTimeline_deinit> */
/* @0x281420 ldr r3, [r5, #0x8] */
/* @0x281424 cmp r3, #0 */
/* @0x281428 movgt r4, #0 */
/* @0x28142c ble 0x28144c <_spDrawOrderTimeline_dispose+0x38> */
/* @0x281430 ldr r3, [r5, #0x10] */
/* @0x281434 ldr r0, [r3, r4, lsl #2] */
/* @0x281438 add r4, r4, #1 */
/* @0x28143c bl 0x285c80 <_free> */
/* @0x281440 ldr r3, [r5, #0x8] */
/* @0x281444 cmp r3, r4 */
/* @0x281448 bgt 0x281430 <_spDrawOrderTimeline_dispose+0x1c> */
/* @0x28144c ldr r0, [r5, #0x10] */
/* @0x281450 bl 0x285c80 <_free> */
/* @0x281454 ldr r0, [r5, #0xc] */
/* @0x281458 bl 0x285c80 <_free> */
/* @0x28145c mov r0, r5 */
/* @0x281460 pop {r3, r4, r5, lr} */
/* @0x281464 b 0x285c80 <_free> */

/* ── FUNC 0x281468 · spTimeline_dispose · size=20 · insn=5 */
/* @0x281468 push {r3, lr} */
/* @0x28146c ldr r3, [r0, #0x4] */
/* @0x281470 ldr r3, [r3, #0x4] */
/* @0x281474 blx r3 */
/* @0x281478 pop {r3, pc} */

/* ── FUNC 0x28147c · spAnimation_dispose · size=80 · insn=20 */
/* @0x28147c push {r3, r4, r5, lr} */
/* @0x281480 mov r5, r0 */
/* @0x281484 ldr r3, [r0, #0x8] */
/* @0x281488 cmp r3, #0 */
/* @0x28148c movgt r4, #0 */
/* @0x281490 ble 0x2814b0 <spAnimation_dispose+0x34> */
/* @0x281494 ldr r3, [r5, #0xc] */
/* @0x281498 ldr r0, [r3, r4, lsl #2] */
/* @0x28149c add r4, r4, #1 */
/* @0x2814a0 bl 0x281468 <spTimeline_dispose> */
/* @0x2814a4 ldr r3, [r5, #0x8] */
/* @0x2814a8 cmp r3, r4 */
/* @0x2814ac bgt 0x281494 <spAnimation_dispose+0x18> */
/* @0x2814b0 ldr r0, [r5, #0xc] */
/* @0x2814b4 bl 0x285c80 <_free> */
/* @0x2814b8 ldr r0, [r5] */
/* @0x2814bc bl 0x285c80 <_free> */
/* @0x2814c0 mov r0, r5 */
/* @0x2814c4 pop {r3, r4, r5, lr} */
/* @0x2814c8 b 0x285c80 <_free> */

/* ── FUNC 0x2814cc · spTimeline_apply · size=52 · insn=13 */
/* @0x2814cc push {r4, lr} */
/* @0x2814d0 sub sp, sp, #16 */
/* @0x2814d4 ldr r12, [r0, #0x4] */
/* @0x2814d8 ldr r4, [sp, #0x18] */
/* @0x2814dc ldr lr, [sp, #0x1c] */
/* @0x2814e0 str r4, [sp] */
/* @0x2814e4 ldr r4, [sp, #0x20] */
/* @0x2814e8 str lr, [sp, #0x4] */
/* @0x2814ec str r4, [sp, #0x8] */
/* @0x2814f0 ldr r12, [r12] */
/* @0x2814f4 blx r12 */
/* @0x2814f8 add sp, sp, #16 */
/* @0x2814fc pop {r4, pc} */

/* ── FUNC 0x281500 · spAnimation_apply · size=236 · insn=59 */
/* @0x281500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x281504 vpush {d8} */
/* @0x281508 sub sp, sp, #20 */
/* @0x28150c mov r11, r0 */
/* @0x281510 mov r8, r1 */
/* @0x281514 ldr r12, [sp, #0x40] */
/* @0x281518 mov r7, r2 */
/* @0x28151c mov r6, r3 */
/* @0x281520 ldr r5, [r0, #0x8] */
/* @0x281524 cmp r12, #0 */
/* @0x281528 ldr r9, [sp, #0x44] */
/* @0x28152c ldr r10, [sp, #0x48] */
/* @0x281530 beq 0x281544 <spAnimation_apply+0x44> */
/* @0x281534 vldr s15, [r0, #4] */
/* @0x281538 vcmp.f32 s15, #0 */
/* @0x28153c vmrs APSR_nzcv, fpscr */
/* @0x281540 bne 0x281590 <spAnimation_apply+0x90> */
/* @0x281544 cmp r5, #0 */
/* @0x281548 ble 0x281584 <spAnimation_apply+0x84> */
/* @0x28154c vmov.f32 s16, #1.000000e+00 */
/* @0x281550 mov r4, #0 */
/* @0x281554 ldr r0, [r11, #0xc] */
/* @0x281558 mov r1, r8 */
/* @0x28155c mov r2, r7 */
/* @0x281560 mov r3, r6 */
/* @0x281564 ldr r0, [r0, r4, lsl #2] */
/* @0x281568 vstr s16, [sp, #8] */
/* @0x28156c str r9, [sp] */
/* @0x281570 add r4, r4, #1 */
/* @0x281574 str r10, [sp, #0x4] */
/* @0x281578 bl 0x2814cc <spTimeline_apply> */
/* @0x28157c cmp r4, r5 */
/* @0x281580 bne 0x281554 <spAnimation_apply+0x54> */
/* @0x281584 add sp, sp, #20 */
/* @0x281588 vpop {d8} */
/* @0x28158c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x281590 vmov s13, r3 */
/* @0x281594 vcvt.f64.f32 d6, s13 */
/* @0x281598 vmov r0, r1, d6 */
/* @0x28159c vcvt.f64.f32 d6, s15 */
/* @0x2815a0 vmov r2, r3, d6 */
/* @0x2815a4 bl 0xb66ac <fmod@plt> */
/* @0x2815a8 vmov s13, r7 */
/* @0x2815ac vcmpe.f32 s13, #0 */
/* @0x2815b0 vmrs APSR_nzcv, fpscr */
/* @0x2815b4 vmov d7, r0, r1 */
/* @0x2815b8 vcvt.f32.f64 s15, d7 */
/* @0x2815bc vmov r6, s15 */
/* @0x2815c0 ble 0x281544 <spAnimation_apply+0x44> */
/* @0x2815c4 vcvt.f64.f32 d6, s13 */
/* @0x2815c8 vldr s15, [r11, #4] */
/* @0x2815cc vmov r0, r1, d6 */
/* @0x2815d0 vcvt.f64.f32 d6, s15 */
/* @0x2815d4 vmov r2, r3, d6 */
/* @0x2815d8 bl 0xb66ac <fmod@plt> */
/* @0x2815dc vmov d7, r0, r1 */
/* @0x2815e0 vcvt.f32.f64 s15, d7 */
/* @0x2815e4 vmov r7, s15 */
/* @0x2815e8 b 0x281544 <spAnimation_apply+0x44> */

/* ── FUNC 0x2815ec · spAnimation_mix · size=236 · insn=59 */
/* @0x2815ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2815f0 vpush {d8} */
/* @0x2815f4 sub sp, sp, #20 */
/* @0x2815f8 vldr s16, [sp, #76] */
/* @0x2815fc mov r11, r0 */
/* @0x281600 mov r8, r1 */
/* @0x281604 ldr r12, [sp, #0x40] */
/* @0x281608 mov r7, r2 */
/* @0x28160c mov r6, r3 */
/* @0x281610 ldr r5, [r0, #0x8] */
/* @0x281614 cmp r12, #0 */
/* @0x281618 ldr r9, [sp, #0x44] */
/* @0x28161c ldr r10, [sp, #0x48] */
/* @0x281620 beq 0x281634 <spAnimation_mix+0x48> */
/* @0x281624 vldr s15, [r0, #4] */
/* @0x281628 vcmp.f32 s15, #0 */
/* @0x28162c vmrs APSR_nzcv, fpscr */
/* @0x281630 bne 0x28167c <spAnimation_mix+0x90> */
/* @0x281634 cmp r5, #0 */
/* @0x281638 ble 0x281670 <spAnimation_mix+0x84> */
/* @0x28163c mov r4, #0 */
/* @0x281640 ldr r0, [r11, #0xc] */
/* @0x281644 mov r1, r8 */
/* @0x281648 mov r2, r7 */
/* @0x28164c mov r3, r6 */
/* @0x281650 ldr r0, [r0, r4, lsl #2] */
/* @0x281654 vstr s16, [sp, #8] */
/* @0x281658 str r9, [sp] */
/* @0x28165c add r4, r4, #1 */
/* @0x281660 str r10, [sp, #0x4] */
/* @0x281664 bl 0x2814cc <spTimeline_apply> */
/* @0x281668 cmp r4, r5 */
/* @0x28166c bne 0x281640 <spAnimation_mix+0x54> */
/* @0x281670 add sp, sp, #20 */
/* @0x281674 vpop {d8} */
/* @0x281678 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x28167c vmov s13, r3 */
/* @0x281680 vcvt.f64.f32 d6, s13 */
/* @0x281684 vmov r0, r1, d6 */
/* @0x281688 vcvt.f64.f32 d6, s15 */
/* @0x28168c vmov r2, r3, d6 */
/* @0x281690 bl 0xb66ac <fmod@plt> */
/* @0x281694 vmov s13, r7 */
/* @0x281698 vcmpe.f32 s13, #0 */
/* @0x28169c vmrs APSR_nzcv, fpscr */
/* @0x2816a0 vmov d7, r0, r1 */
/* @0x2816a4 vcvt.f32.f64 s15, d7 */
/* @0x2816a8 vmov r6, s15 */
/* @0x2816ac ble 0x281634 <spAnimation_mix+0x48> */
/* @0x2816b0 vcvt.f64.f32 d6, s13 */
/* @0x2816b4 vldr s15, [r11, #4] */
/* @0x2816b8 vmov r0, r1, d6 */
/* @0x2816bc vcvt.f64.f32 d6, s15 */
/* @0x2816c0 vmov r2, r3, d6 */
/* @0x2816c4 bl 0xb66ac <fmod@plt> */
/* @0x2816c8 vmov d7, r0, r1 */
/* @0x2816cc vcvt.f32.f64 s15, d7 */
/* @0x2816d0 vmov r7, s15 */
/* @0x2816d4 b 0x281634 <spAnimation_mix+0x48> */

/* ── FUNC 0x2816d8 · _spCurveTimeline_init · size=68 · insn=17 */
/* @0x2816d8 push {r3, r4, r5, lr} */
/* @0x2816dc mov r5, r2 */
/* @0x2816e0 mov r2, r3 */
/* @0x2816e4 ldr r3, [sp, #0x10] */
/* @0x2816e8 mov r4, r0 */
/* @0x2816ec bl 0x281328 <_spTimeline_init> */
/* @0x2816f0 sub r12, r5, #1 */
/* @0x2816f4 ldr r2, [pc, #0x1c] */
/* @0x2816f8 mov r1, #4 */
/* @0x2816fc mov r3, #121 */
/* @0x281700 add r0, r12, r12, lsl #3 */
/* @0x281704 add r2, pc, r2 */
/* @0x281708 add r0, r12, r0, lsl #1 */
/* @0x28170c bl 0x285c4c <_calloc> */
/* @0x281710 str r0, [r4, #0x8] */
/* @0x281714 pop {r3, r4, r5, pc} */
/* @0x281718 andeq r5, sp, r12, asr #26 */

/* ── FUNC 0x28171c · _spCurveTimeline_deinit · size=24 · insn=6 */
/* @0x28171c push {r4, lr} */
/* @0x281720 mov r4, r0 */
/* @0x281724 bl 0x281364 <_spTimeline_deinit> */
/* @0x281728 ldr r0, [r4, #0x8] */
/* @0x28172c pop {r4, lr} */
/* @0x281730 b 0x285c80 <_free> */

/* ── FUNC 0x281734 · _spBaseTimeline_dispose · size=32 · insn=8 */
/* @0x281734 push {r4, lr} */
/* @0x281738 mov r4, r0 */
/* @0x28173c bl 0x28171c <_spCurveTimeline_deinit> */
/* @0x281740 ldr r0, [r4, #0x10] */
/* @0x281744 bl 0x285c80 <_free> */
/* @0x281748 mov r0, r4 */
/* @0x28174c pop {r4, lr} */
/* @0x281750 b 0x285c80 <_free> */

/* ── FUNC 0x281754 · _spDeformTimeline_dispose · size=84 · insn=21 */
/* @0x281754 push {r3, r4, r5, lr} */
/* @0x281758 mov r5, r0 */
/* @0x28175c bl 0x28171c <_spCurveTimeline_deinit> */
/* @0x281760 ldr r3, [r5, #0xc] */
/* @0x281764 cmp r3, #0 */
/* @0x281768 movgt r4, #0 */
/* @0x28176c ble 0x28178c <_spDeformTimeline_dispose+0x38> */
/* @0x281770 ldr r3, [r5, #0x18] */
/* @0x281774 ldr r0, [r3, r4, lsl #2] */
/* @0x281778 add r4, r4, #1 */
/* @0x28177c bl 0x285c80 <_free> */
/* @0x281780 ldr r3, [r5, #0xc] */
/* @0x281784 cmp r3, r4 */
/* @0x281788 bgt 0x281770 <_spDeformTimeline_dispose+0x1c> */
/* @0x28178c ldr r0, [r5, #0x18] */
/* @0x281790 bl 0x285c80 <_free> */
/* @0x281794 ldr r0, [r5, #0x10] */
/* @0x281798 bl 0x285c80 <_free> */
/* @0x28179c mov r0, r5 */
/* @0x2817a0 pop {r3, r4, r5, lr} */
/* @0x2817a4 b 0x285c80 <_free> */

/* ── FUNC 0x2817a8 · spCurveTimeline_setLinear · size=24 · insn=6 */
/* @0x2817a8 ldr r3, [r0, #0x8] */
/* @0x2817ac mov r2, #76 */
/* @0x2817b0 mov r0, #0 */
/* @0x2817b4 mla r1, r2, r1, r3 */
/* @0x2817b8 str r0, [r1] */
/* @0x2817bc bx lr */

/* ── FUNC 0x2817c0 · spCurveTimeline_setStepped · size=24 · insn=6 */
/* @0x2817c0 ldr r3, [r0, #0x8] */
/* @0x2817c4 mov r2, #76 */
/* @0x2817c8 mov r12, #1065353216 */
/* @0x2817cc mla r1, r2, r1, r3 */
/* @0x2817d0 str r12, [r1] */
/* @0x2817d4 bx lr */

/* ── FUNC 0x2817d8 · spCurveTimeline_setCurve · size=264 · insn=66 */
/* @0x2817d8 vmov s14, r2 */
/* @0x2817dc vldr s6, [sp] */
/* @0x2817e0 vmov s15, r3 */
/* @0x2817e4 vldr s9, [sp, #4] */
/* @0x2817e8 vneg.f32 s12, s14 */
/* @0x2817ec vldr s8, [pc, #220] */
/* @0x2817f0 vldr s7, [pc, #220] */
/* @0x2817f4 vldr s10, [pc, #220] */
/* @0x2817f8 vldr s11, [pc, #220] */
/* @0x2817fc add r2, r1, r1, lsl #3 */
/* @0x281800 ldr r3, [r0, #0x8] */
/* @0x281804 vadd.f32 s12, s12, s12 */
/* @0x281808 add r1, r1, r2, lsl #1 */
/* @0x28180c add r12, r1, #2 */
/* @0x281810 add r2, r1, #1 */
/* @0x281814 add r0, r1, #19 */
/* @0x281818 add r1, r3, r1, lsl #2 */
/* @0x28181c add r3, r3, r12, lsl #2 */
/* @0x281820 mov r12, #1073741824 */
/* @0x281824 str r12, [r1] */
/* @0x281828 vneg.f32 s13, s15 */
/* @0x28182c vadd.f32 s13, s13, s13 */
/* @0x281830 vadd.f32 s12, s12, s6 */
/* @0x281834 vsub.f32 s5, s15, s9 */
/* @0x281838 vadd.f32 s13, s13, s9 */
/* @0x28183c vmov.f32 s9, #1.000000e+00 */
/* @0x281840 vmul.f32 s12, s12, s8 */
/* @0x281844 vsub.f32 s4, s14, s6 */
/* @0x281848 vmov.f32 s6, #3.000000e+00 */
/* @0x28184c vmul.f32 s13, s13, s8 */
/* @0x281850 vmov.f32 s8, s9 */
/* @0x281854 vmla.f32 s9, s5, s6 */
/* @0x281858 vmla.f32 s8, s4, s6 */
/* @0x28185c vmov.f32 s6, s12 */
/* @0x281860 vmla.f32 s6, s14, s7 */
/* @0x281864 vmov.f32 s14, s6 */
/* @0x281868 vmov.f32 s6, s13 */
/* @0x28186c vmla.f32 s6, s15, s7 */
/* @0x281870 vmul.f32 s8, s8, s10 */
/* @0x281874 vmul.f32 s9, s9, s10 */
/* @0x281878 vmov.f32 s15, s6 */
/* @0x28187c vmla.f32 s14, s8, s11 */
/* @0x281880 vmla.f32 s15, s9, s11 */
/* @0x281884 vadd.f32 s12, s12, s12 */
/* @0x281888 vadd.f32 s13, s13, s13 */
/* @0x28188c vadd.f32 s12, s12, s8 */
/* @0x281890 vadd.f32 s13, s13, s9 */
/* @0x281894 vmov.f32 s10, s14 */
/* @0x281898 vmov.f32 s11, s15 */
/* @0x28189c vmov r1, s11 */
/* @0x2818a0 add r2, r2, #2 */
/* @0x2818a4 cmp r2, r0 */
/* @0x2818a8 vstr s10, [r3, #-4] */
/* @0x2818ac vadd.f32 s14, s14, s12 */
/* @0x2818b0 vadd.f32 s15, s15, s13 */
/* @0x2818b4 str r1, [r3], #8 */
/* @0x2818b8 vadd.f32 s10, s10, s14 */
/* @0x2818bc vadd.f32 s11, s11, s15 */
/* @0x2818c0 vadd.f32 s12, s12, s8 */
/* @0x2818c4 vadd.f32 s13, s13, s9 */
/* @0x2818c8 bne 0x28189c <spCurveTimeline_setCurve+0xc4> */
/* @0x2818cc bx lr */
/* @0x2818d0 ldcllo p2, c12, [r5], #572 */
/* @0x2818d4 mrclo p9, #0x4, r9, c9, c10, #0x4 */
/* @0x2818d8 bllo 0xff3a8778 <b2_toiTime+0xfffffffffec4f2d4> */
/* @0x2818dc vmullo.f32 s20, s21, s23 */

/* ── FUNC 0x2818e0 · spCurveTimeline_getCurvePercent · size=332 · insn=83 */
/* @0x2818e0 vmov s15, r2 */
/* @0x2818e4 add r3, r1, r1, lsl #3 */
/* @0x2818e8 ldr r0, [r0, #0x8] */
/* @0x2818ec vcmpe.f32 s15, #0 */
/* @0x2818f0 add r1, r1, r3, lsl #1 */
/* @0x2818f4 push {r4, r5} */
/* @0x2818f8 add r3, r0, r1, lsl #2 */
/* @0x2818fc vldr s14, [r3] */
/* @0x281900 vmrs APSR_nzcv, fpscr */
/* @0x281904 bmi 0x2819d0 <spCurveTimeline_getCurvePercent+0xf0> */
/* @0x281908 vmov.f32 s13, #1.000000e+00 */
/* @0x28190c vcmp.f32 s15, s13 */
/* @0x281910 vmrs APSR_nzcv, fpscr */
/* @0x281914 vmovgt.f32 s15, s13 */
/* @0x281918 vcmp.f32 s14, #0 */
/* @0x28191c vmrs APSR_nzcv, fpscr */
/* @0x281920 beq 0x2819b4 <spCurveTimeline_getCurvePercent+0xd4> */
/* @0x281924 vmov.f32 s13, #1.000000e+00 */
/* @0x281928 vcmp.f32 s14, s13 */
/* @0x28192c vmrs APSR_nzcv, fpscr */
/* @0x281930 beq 0x2819c0 <spCurveTimeline_getCurvePercent+0xe0> */
/* @0x281934 add r4, r1, #1 */
/* @0x281938 lsl r2, r4, #2 */
/* @0x28193c mov r12, r4 */
/* @0x281940 add r3, r0, r2 */
/* @0x281944 vldr s14, [r3] */
/* @0x281948 vcmpe.f32 s15, s14 */
/* @0x28194c vmrs APSR_nzcv, fpscr */
/* @0x281950 addhi r2, r2, #8 */
/* @0x281954 addhi r1, r1, #19 */
/* @0x281958 addhi r2, r0, r2 */
/* @0x28195c movhi r3, r4 */
/* @0x281960 bhi 0x281980 <spCurveTimeline_getCurvePercent+0xa0> */
/* @0x281964 b 0x281a1c <spCurveTimeline_getCurvePercent+0x13c> */
/* @0x281968 mov r5, r2 */
/* @0x28196c vldr s14, [r5] */
/* @0x281970 vcmpe.f32 s15, s14 */
/* @0x281974 add r2, r2, #8 */
/* @0x281978 vmrs APSR_nzcv, fpscr */
/* @0x28197c bls 0x2819d8 <spCurveTimeline_getCurvePercent+0xf8> */
/* @0x281980 add r3, r3, #2 */
/* @0x281984 cmp r3, r1 */
/* @0x281988 mov r12, r3 */
/* @0x28198c bne 0x281968 <spCurveTimeline_getCurvePercent+0x88> */
/* @0x281990 vmov.f32 s12, #1.000000e+00 */
/* @0x281994 add r3, r0, r3, lsl #2 */
/* @0x281998 vldr s13, [r3, #-4] */
/* @0x28199c vsub.f32 s15, s15, s14 */
/* @0x2819a0 vsub.f32 s11, s12, s13 */
/* @0x2819a4 vmul.f32 s15, s11, s15 */
/* @0x2819a8 vsub.f32 s14, s12, s14 */
/* @0x2819ac vdiv.f32 s15, s15, s14 */
/* @0x2819b0 vadd.f32 s15, s15, s13 */
/* @0x2819b4 vmov r0, s15 */
/* @0x2819b8 pop {r4, r5} */
/* @0x2819bc bx lr */
/* @0x2819c0 vldr s15, [pc, #96] */
/* @0x2819c4 pop {r4, r5} */
/* @0x2819c8 vmov r0, s15 */
/* @0x2819cc bx lr */
/* @0x2819d0 vldr s15, [pc, #80] */
/* @0x2819d4 b 0x281918 <spCurveTimeline_getCurvePercent+0x38> */
/* @0x2819d8 cmp r4, r12 */
/* @0x2819dc beq 0x281a1c <spCurveTimeline_getCurvePercent+0x13c> */
/* @0x2819e0 sub r3, r12, #-1073741822 */
/* @0x2819e4 add r3, r0, r3, lsl #2 */
/* @0x2819e8 vldr s12, [r3] */
/* @0x2819ec vldr s13, [r3, #4] */
/* @0x2819f0 add r0, r0, r12, lsl #2 */
/* @0x2819f4 vsub.f32 s15, s15, s12 */
/* @0x2819f8 vldr s11, [r0, #4] */
/* @0x2819fc pop {r4, r5} */
/* @0x281a00 vsub.f32 s11, s11, s13 */
/* @0x281a04 vmul.f32 s15, s11, s15 */
/* @0x281a08 vsub.f32 s14, s14, s12 */
/* @0x281a0c vdiv.f32 s15, s15, s14 */
/* @0x281a10 vadd.f32 s15, s15, s13 */
/* @0x281a14 vmov r0, s15 */
/* @0x281a18 bx lr */
/* @0x281a1c vldr s13, [pc, #4] */
/* @0x281a20 vmov.f32 s12, s13 */
/* @0x281a24 b 0x2819f0 <spCurveTimeline_getCurvePercent+0x110> */
/* @0x281a28 andeq r0, r0, r0 */
