/* libyoyo.so 覆盖卡组 0201
 * 函数 0x2228fc..0x2233f4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2228fc · _alutOutputStreamDestroy · size=32 · insn=8 */
/* @0x2228fc push {r4, lr} */
/* @0x222900 mov r4, r0 */
/* @0x222904 ldr r0, [r0] */
/* @0x222908 bl 0xb655c <free@plt> */
/* @0x22290c mov r0, r4 */
/* @0x222910 bl 0xb655c <free@plt> */
/* @0x222914 mov r0, #1 */
/* @0x222918 pop {r4, pc} */

/* ── FUNC 0x22291c · _alutOutputStreamGetData · size=8 · insn=2 */
/* @0x22291c ldr r0, [r0] */
/* @0x222920 bx lr */

/* ── FUNC 0x222924 · _alutOutputStreamGetLength · size=12 · insn=3 */
/* @0x222924 ldm r0, {r0, r2} */
/* @0x222928 rsb r0, r0, r2 */
/* @0x22292c bx lr */

/* ── FUNC 0x222930 · anon_222930 · size=88 · insn=22 */
/* @0x222930 push {r3, r4, r5, r6, r7, lr} */
/* @0x222934 mov r5, r2 */
/* @0x222938 ldr r6, [r0, #0x8] */
/* @0x22293c mov r4, r0 */
/* @0x222940 mov r7, r1 */
/* @0x222944 bl 0x222924 <_alutOutputStreamGetLength> */
/* @0x222948 rsb r0, r0, r6 */
/* @0x22294c cmp r0, r5 */
/* @0x222950 blo 0x222978 <_alutOutputStreamGetLength+0x54> */
/* @0x222954 mov r2, r5 */
/* @0x222958 mov r1, r7 */
/* @0x22295c ldr r0, [r4, #0x4] */
/* @0x222960 bl 0xb65bc <memcpy@plt> */
/* @0x222964 ldr r3, [r4, #0x4] */
/* @0x222968 mov r0, #1 */
/* @0x22296c add r5, r3, r5 */
/* @0x222970 str r5, [r4, #0x4] */
/* @0x222974 pop {r3, r4, r5, r6, r7, pc} */
/* @0x222978 movw r0, #0x20e */
/* @0x22297c bl 0x221940 <_alutSetError> */
/* @0x222980 mov r0, #0 */
/* @0x222984 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x222988 · _alutOutputStreamWriteInt16BE · size=44 · insn=11 */
/* @0x222988 str lr, [sp, #-0x4]! */
/* @0x22298c sub sp, sp, #12 */
/* @0x222990 mov r3, r1 */
/* @0x222994 mov r2, #2 */
/* @0x222998 add r1, sp, #4 */
/* @0x22299c strb r3, [sp, #0x5] */
/* @0x2229a0 asr r3, r3, #8 */
/* @0x2229a4 strb r3, [sp, #0x4] */
/* @0x2229a8 bl 0x222930 <_alutOutputStreamGetLength+0xc> */
/* @0x2229ac add sp, sp, #12 */
/* @0x2229b0 ldr pc, [sp], #4 */

/* ── FUNC 0x2229b4 · _alutOutputStreamWriteInt32BE · size=60 · insn=15 */
/* @0x2229b4 str lr, [sp, #-0x4]! */
/* @0x2229b8 sub sp, sp, #12 */
/* @0x2229bc mov r3, r1 */
/* @0x2229c0 mov r2, #4 */
/* @0x2229c4 add r1, sp, r2 */
/* @0x2229c8 asr lr, r3, #24 */
/* @0x2229cc asr r12, r3, #16 */
/* @0x2229d0 strb r3, [sp, #0x7] */
/* @0x2229d4 strb lr, [sp, #0x4] */
/* @0x2229d8 asr r3, r3, #8 */
/* @0x2229dc strb r12, [sp, #0x5] */
/* @0x2229e0 strb r3, [sp, #0x6] */
/* @0x2229e4 bl 0x222930 <_alutOutputStreamGetLength+0xc> */
/* @0x2229e8 add sp, sp, #12 */
/* @0x2229ec ldr pc, [sp], #4 */

/* ── FUNC 0x2229f0 · alutSleep · size=168 · insn=42 */
/* @0x2229f0 vmov s15, r0 */
/* @0x2229f4 push {r4, r5, lr} */
/* @0x2229f8 vcmpe.f32 s15, #0 */
/* @0x2229fc sub sp, sp, #20 */
/* @0x222a00 vmrs APSR_nzcv, fpscr */
/* @0x222a04 bmi 0x222a84 <alutSleep+0x94> */
/* @0x222a08 vcvt.u32.f32 s14, s15 */
/* @0x222a0c vldr s13, [pc, #128] */
/* @0x222a10 mov r2, #1000 */
/* @0x222a14 add r4, sp, #8 */
/* @0x222a18 vcvt.f32.u32 s12, s14 */
/* @0x222a1c vstr s14, [sp] */
/* @0x222a20 vsub.f32 s15, s15, s12 */
/* @0x222a24 vmul.f32 s15, s15, s13 */
/* @0x222a28 vcvt.u32.f32 s15, s15 */
/* @0x222a2c vmov r1, s15 */
/* @0x222a30 mul r3, r2, r1 */
/* @0x222a34 str r3, [sp, #0x4] */
/* @0x222a38 b 0x222a58 <alutSleep+0x68> */
/* @0x222a3c bl 0xb6bf8 <__errno@plt> */
/* @0x222a40 ldr r3, [r0] */
/* @0x222a44 cmp r3, #4 */
/* @0x222a48 bne 0x222a78 <alutSleep+0x88> */
/* @0x222a4c ldr r2, [sp, #0x8] */
/* @0x222a50 ldr r3, [sp, #0xc] */
/* @0x222a54 stm sp, {r2, r3} */
/* @0x222a58 mov r0, sp */
/* @0x222a5c mov r1, r4 */
/* @0x222a60 bl 0xb6c04 <nanosleep@plt> */
/* @0x222a64 cmp r0, #0 */
/* @0x222a68 blt 0x222a3c <alutSleep+0x4c> */
/* @0x222a6c mov r0, #1 */
/* @0x222a70 add sp, sp, #20 */
/* @0x222a74 pop {r4, r5, pc} */
/* @0x222a78 mov r0, #0 */
/* @0x222a7c add sp, sp, #20 */
/* @0x222a80 pop {r4, r5, pc} */
/* @0x222a84 movw r0, #0x202 */
/* @0x222a88 bl 0x221940 <_alutSetError> */
/* @0x222a8c mov r0, #0 */
/* @0x222a90 b 0x222a70 <alutSleep+0x80> */
/* @0x222a94 ldmdbmi r4!, {r10, sp} ^ */

/* ── FUNC 0x222a98 · _alutMalloc · size=48 · insn=12 */
/* @0x222a98 cmp r0, #0 */
/* @0x222a9c push {r4, lr} */
/* @0x222aa0 moveq r0, #1 */
/* @0x222aa4 bl 0xb6544 <malloc@plt> */
/* @0x222aa8 subs r4, r0, #0 */
/* @0x222aac beq 0x222ab8 <_alutMalloc+0x20> */
/* @0x222ab0 mov r0, r4 */
/* @0x222ab4 pop {r4, pc} */
/* @0x222ab8 mov r0, #512 */
/* @0x222abc bl 0x221940 <_alutSetError> */
/* @0x222ac0 mov r0, r4 */
/* @0x222ac4 pop {r4, pc} */

/* ── FUNC 0x222ac8 · _alutFormatConstruct · size=112 · insn=28 */
/* @0x222ac8 cmp r0, #1 */
/* @0x222acc beq 0x222af8 <_alutFormatConstruct+0x30> */
/* @0x222ad0 cmp r0, #2 */
/* @0x222ad4 bne 0x222b08 <_alutFormatConstruct+0x40> */
/* @0x222ad8 cmp r1, #8 */
/* @0x222adc beq 0x222b28 <_alutFormatConstruct+0x60> */
/* @0x222ae0 cmp r1, #16 */
/* @0x222ae4 bne 0x222b08 <_alutFormatConstruct+0x40> */
/* @0x222ae8 movw r3, #0x1103 */
/* @0x222aec mov r0, #1 */
/* @0x222af0 str r3, [r2] */
/* @0x222af4 bx lr */
/* @0x222af8 cmp r1, #8 */
/* @0x222afc beq 0x222b1c <_alutFormatConstruct+0x54> */
/* @0x222b00 cmp r1, #16 */
/* @0x222b04 beq 0x222b10 <_alutFormatConstruct+0x48> */
/* @0x222b08 mov r0, #0 */
/* @0x222b0c bx lr */
/* @0x222b10 movw r3, #0x1101 */
/* @0x222b14 str r3, [r2] */
/* @0x222b18 bx lr */
/* @0x222b1c mov r3, #4352 */
/* @0x222b20 str r3, [r2] */
/* @0x222b24 bx lr */
/* @0x222b28 movw r3, #0x1102 */
/* @0x222b2c mov r0, #1 */
/* @0x222b30 str r3, [r2] */
/* @0x222b34 bx lr */

/* ── FUNC 0x222b38 · _alutFormatGetNumChannels · size=68 · insn=17 */
/* @0x222b38 sub r0, r0, #4352 */
/* @0x222b3c cmp r0, #3 */
/* @0x222b40 addls pc, pc, r0, lsl #2 */
/* @0x222b44 b 0x222b74 <_alutFormatGetNumChannels+0x3c> */
/* @0x222b48 b 0x222b68 <_alutFormatGetNumChannels+0x30> */
/* @0x222b4c b 0x222b68 <_alutFormatGetNumChannels+0x30> */
/* @0x222b50 b 0x222b58 <_alutFormatGetNumChannels+0x20> */
/* @0x222b54 b 0x222b58 <_alutFormatGetNumChannels+0x20> */
/* @0x222b58 mov r3, #2 */
/* @0x222b5c mov r0, #1 */
/* @0x222b60 str r3, [r1] */
/* @0x222b64 bx lr */
/* @0x222b68 mov r0, #1 */
/* @0x222b6c str r0, [r1] */
/* @0x222b70 bx lr */
/* @0x222b74 mov r0, #0 */
/* @0x222b78 bx lr */

/* ── FUNC 0x222b7c · _alutFormatGetBitsPerSample · size=72 · insn=18 */
/* @0x222b7c sub r0, r0, #4352 */
/* @0x222b80 cmp r0, #3 */
/* @0x222b84 addls pc, pc, r0, lsl #2 */
/* @0x222b88 b 0x222bbc <_alutFormatGetBitsPerSample+0x40> */
/* @0x222b8c b 0x222bac <_alutFormatGetBitsPerSample+0x30> */
/* @0x222b90 b 0x222b9c <_alutFormatGetBitsPerSample+0x20> */
/* @0x222b94 b 0x222bac <_alutFormatGetBitsPerSample+0x30> */
/* @0x222b98 b 0x222b9c <_alutFormatGetBitsPerSample+0x20> */
/* @0x222b9c mov r3, #16 */
/* @0x222ba0 mov r0, #1 */
/* @0x222ba4 str r3, [r1] */
/* @0x222ba8 bx lr */
/* @0x222bac mov r3, #8 */
/* @0x222bb0 mov r0, #1 */
/* @0x222bb4 str r3, [r1] */
/* @0x222bb8 bx lr */
/* @0x222bbc mov r0, #0 */
/* @0x222bc0 bx lr */

/* ── FUNC 0x222bc4 · alutGetMajorVersion · size=8 · insn=2 */
/* @0x222bc4 mov r0, #1 */
/* @0x222bc8 bx lr */

/* ── FUNC 0x222bcc · alutGetMinorVersion · size=8 · insn=2 */
/* @0x222bcc mov r0, #1 */
/* @0x222bd0 bx lr */

/* ── FUNC 0x222bd4 · anon_222bd4 · size=100 · insn=25 */
/* @0x222bd4 vmov.f64 d5, #5.000000e-01 */
/* @0x222bd8 vmov d4, r2, r3 */
/* @0x222bdc vmov.f64 d6, #-1.000000e+00 */
/* @0x222be0 vmov.f64 d7, #1.000000e+00 */
/* @0x222be4 vcmpe.f64 d4, d5 */
/* @0x222be8 vmrs APSR_nzcv, fpscr */
/* @0x222bec vmovlt r0, r1, d7 */
/* @0x222bf0 vmovge r0, r1, d6 */
/* @0x222bf4 bx lr */
/* @0x222bf8 vmov d5, r2, r3 */
/* @0x222bfc vmov.f64 d7, #1.000000e+00 */
/* @0x222c00 vadd.f64 d6, d5, d5 */
/* @0x222c04 vsub.f64 d5, d6, d7 */
/* @0x222c08 vmov r0, r1, d5 */
/* @0x222c0c bx lr */
/* @0x222c10 vmov.f64 d6, #1.000000e+00 */
/* @0x222c14 vldr d7, [pc, #28] */
/* @0x222c18 vmov d4, r0, r1 */
/* @0x222c1c vmov d5, r2, r3 */
/* @0x222c20 vcmpe.f64 d4, d5 */
/* @0x222c24 vmrs APSR_nzcv, fpscr */
/* @0x222c28 vmovle r0, r1, d7 */
/* @0x222c2c vmovgt r0, r1, d6 */
/* @0x222c30 bx lr */
/* @0x222c34 nop */

/* ── FUNC 0x222c40 · anon_222c40 · size=736 · insn=184 */
/* @0x222c40 sub r0, r0, #256 */
/* @0x222c44 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x222c48 vpush {d8, d9, d10, d11, d12} */
/* @0x222c4c vmov.f32 s18, s0 */
/* @0x222c50 vmov.f32 s20, s1 */
/* @0x222c54 cmp r0, #4 */
/* @0x222c58 addls pc, pc, r0, lsl #2 */
/* @0x222c5c b 0x222e58 <alutGetMinorVersion+0x28c> */
/* @0x222c60 b 0x222e1c <alutGetMinorVersion+0x250> */
/* @0x222c64 b 0x222c74 <alutGetMinorVersion+0xa8> */
/* @0x222c68 b 0x222e28 <alutGetMinorVersion+0x25c> */
/* @0x222c6c b 0x222e34 <alutGetMinorVersion+0x268> */
/* @0x222c70 b 0x222e40 <alutGetMinorVersion+0x274> */
/* @0x222c74 ldr r9, [pc, #0x218] */
/* @0x222c78 add r9, pc, r9 */
/* @0x222c7c vcmpe.f32 s18, #0 */
/* @0x222c80 vmrs APSR_nzcv, fpscr */
/* @0x222c84 bls 0x222e6c <alutGetMinorVersion+0x2a0> */
/* @0x222c88 vcmpe.f32 s2, #0 */
/* @0x222c8c vmrs APSR_nzcv, fpscr */
/* @0x222c90 bmi 0x222e6c <alutGetMinorVersion+0x2a0> */
/* @0x222c94 vmul.f32 s2, s18, s2 */
/* @0x222c98 vldr d8, [pc, #480] */
/* @0x222c9c vmov.f64 d7, #5.000000e-01 */
/* @0x222ca0 vcvt.f64.f32 d1, s2 */
/* @0x222ca4 vadd.f64 d6, d1, d7 */
/* @0x222ca8 vmov r0, r1, d6 */
/* @0x222cac bl 0xb6598 <floor@plt> */
/* @0x222cb0 vcvt.f64.f32 d9, s18 */
/* @0x222cb4 vmov d6, r0, r1 */
/* @0x222cb8 vdiv.f64 d7, d6, d9 */
/* @0x222cbc vmul.f64 d6, d7, d8 */
/* @0x222cc0 vmov r0, r1, d6 */
/* @0x222cc4 bl 0xb6598 <floor@plt> */
/* @0x222cc8 vmov d7, r0, r1 */
/* @0x222ccc vcvt.u32.f64 s15, d7 */
/* @0x222cd0 vmov r8, s15 */
/* @0x222cd4 lsl r4, r8, #1 */
/* @0x222cd8 add r0, r4, #24 */
/* @0x222cdc bl 0x2228a4 <_alutOutputStreamConstruct> */
/* @0x222ce0 subs r7, r0, #0 */
/* @0x222ce4 beq 0x222e4c <alutGetMinorVersion+0x280> */
/* @0x222ce8 movw r1, #0x6e64 */
/* @0x222cec movt r1, #0x2e73 */
/* @0x222cf0 bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222cf4 cmp r0, #0 */
/* @0x222cf8 beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222cfc mov r0, r7 */
/* @0x222d00 mov r1, #24 */
/* @0x222d04 bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222d08 cmp r0, #0 */
/* @0x222d0c beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222d10 mov r1, r4 */
/* @0x222d14 mov r0, r7 */
/* @0x222d18 bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222d1c cmp r0, #0 */
/* @0x222d20 beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222d24 mov r0, r7 */
/* @0x222d28 mov r1, #3 */
/* @0x222d2c bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222d30 cmp r0, #0 */
/* @0x222d34 beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222d38 mov r0, r7 */
/* @0x222d3c movw r1, #0xac44 */
/* @0x222d40 bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222d44 cmp r0, #0 */
/* @0x222d48 beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222d4c mov r0, r7 */
/* @0x222d50 mov r1, #1 */
/* @0x222d54 bl 0x2229b4 <_alutOutputStreamWriteInt32BE> */
/* @0x222d58 cmp r0, #0 */
/* @0x222d5c beq 0x222e08 <alutGetMinorVersion+0x23c> */
/* @0x222d60 vdiv.f64 d8, d9, d8 */
/* @0x222d64 vldr s15, [pc, #292] */
/* @0x222d68 vdiv.f32 s20, s20, s15 */
/* @0x222d6c vcvt.f64.f32 d10, s20 */
/* @0x222d70 vsub.f64 d8, d10, d8 */
/* @0x222d74 vmov r0, r1, d8 */
/* @0x222d78 bl 0xb6598 <floor@plt> */
/* @0x222d7c cmp r8, #0 */
/* @0x222d80 vmov d6, r0, r1 */
/* @0x222d84 vsub.f64 d6, d8, d6 */
/* @0x222d88 vmov r4, r5, d6 */
/* @0x222d8c beq 0x222e4c <alutGetMinorVersion+0x280> */
/* @0x222d90 mov r6, #0 */
/* @0x222d94 vldr d12, [pc, #228] */
/* @0x222d98 vldr d11, [pc, #232] */
/* @0x222d9c b 0x222da8 <alutGetMinorVersion+0x1dc> */
/* @0x222da0 cmp r6, r8 */
/* @0x222da4 beq 0x222e4c <alutGetMinorVersion+0x280> */
/* @0x222da8 vmov s13, r6 */
/* @0x222dac add r6, r6, #1 */
/* @0x222db0 vcvt.f64.u32 d8, s13 */
/* @0x222db4 vmul.f64 d8, d9, d8 */
/* @0x222db8 vdiv.f64 d8, d8, d12 */
/* @0x222dbc vadd.f64 d8, d10, d8 */
/* @0x222dc0 vmov r0, r1, d8 */
/* @0x222dc4 bl 0xb6598 <floor@plt> */
/* @0x222dc8 vmov d7, r0, r1 */
/* @0x222dcc mov r0, r4 */
/* @0x222dd0 mov r1, r5 */
/* @0x222dd4 vsub.f64 d8, d8, d7 */
/* @0x222dd8 vmov r2, r3, d8 */
/* @0x222ddc blx r9 */
/* @0x222de0 vmov r4, r5, d8 */
/* @0x222de4 vmov d6, r0, r1 */
/* @0x222de8 mov r0, r7 */
/* @0x222dec vmul.f64 d7, d6, d11 */
/* @0x222df0 vcvt.s32.f64 s13, d7 */
/* @0x222df4 vmov r1, s13 */
/* @0x222df8 sxth r1, r1 */
/* @0x222dfc bl 0x222988 <_alutOutputStreamWriteInt16BE> */
/* @0x222e00 subs r10, r0, #0 */
/* @0x222e04 bne 0x222da0 <alutGetMinorVersion+0x1d4> */
/* @0x222e08 mov r0, r7 */
/* @0x222e0c bl 0x2228fc <_alutOutputStreamDestroy> */
/* @0x222e10 vpop {d8, d9, d10, d11, d12} */
/* @0x222e14 mov r0, #0 */
/* @0x222e18 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x222e1c ldr r9, [pc, #0x74] */
/* @0x222e20 add r9, pc, r9 */
/* @0x222e24 b 0x222c7c <alutGetMinorVersion+0xb0> */
/* @0x222e28 ldr r9, [pc, #0x6c] */
/* @0x222e2c add r9, pc, r9 */
/* @0x222e30 b 0x222c7c <alutGetMinorVersion+0xb0> */
/* @0x222e34 ldr r9, [pc, #0x64] */
/* @0x222e38 add r9, pc, r9 */
/* @0x222e3c b 0x222c7c <alutGetMinorVersion+0xb0> */
/* @0x222e40 ldr r9, [pc, #0x5c] */
/* @0x222e44 add r9, pc, r9 */
/* @0x222e48 b 0x222c7c <alutGetMinorVersion+0xb0> */
/* @0x222e4c vpop {d8, d9, d10, d11, d12} */
/* @0x222e50 mov r0, r7 */
/* @0x222e54 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x222e58 movw r0, #0x201 */
/* @0x222e5c bl 0x221940 <_alutSetError> */
/* @0x222e60 vpop {d8, d9, d10, d11, d12} */
/* @0x222e64 mov r0, #0 */
/* @0x222e68 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x222e6c movw r0, #0x202 */
/* @0x222e70 bl 0x221940 <_alutSetError> */
/* @0x222e74 vpop {d8, d9, d10, d11, d12} */
/* @0x222e78 mov r0, #0 */
/* @0x222e7c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x222e80 andeq r0, r0, r0 */
/* @0x222e84 rscmi r8, r5, r0, lsl #17 */
/* @0x222e88 andeq r0, r0, r0 */
/* @0x222e8c sbcsmi pc, pc, r0, asr #31 */
/* @0x222e90 teqmi r4, #0 */
/* @0x222e94 .word 0xffffff54 */
/* @0x222e98 ldrdeq r0, r1, [r0], -r8 */
/* @0x222e9c .word 0xfffffdc4 */
/* @0x222ea0 andeq r0, r0, r8, rrx */
/* @0x222ea4 .word 0xfffffdc4 */
/* @0x222ea8 push {r3, lr} */
/* @0x222eac bl 0xb6c10 <lrand48@plt> */
/* @0x222eb0 movw r2, #0x7d73 */
/* @0x222eb4 movt r2, #0x7e91 */
/* @0x222eb8 movw r3, #0x953f */
/* @0x222ebc movt r3, #0x40b */
/* @0x222ec0 vldr d5, [pc, #48] */
/* @0x222ec4 vmov.f64 d6, #1.000000e+00 */
/* @0x222ec8 smull r12, r2, r2, r0 */
/* @0x222ecc asr r1, r0, #31 */
/* @0x222ed0 rsb r2, r1, r2, asr #25 */
/* @0x222ed4 mls r0, r3, r2, r0 */
/* @0x222ed8 vmov s9, r0 */
/* @0x222edc vcvt.f64.s32 d7, s9 */
/* @0x222ee0 vadd.f64 d7, d7, d7 */
/* @0x222ee4 vdiv.f64 d7, d7, d5 */
/* @0x222ee8 vsub.f64 d5, d7, d6 */
/* @0x222eec vmov r0, r1, d5 */
/* @0x222ef0 pop {r3, pc} */
/* @0x222ef4 nop */
/* @0x222ef8 .word 0xfc000000 */
/* @0x222efc orrsmi r2, r0, r4, asr lr */
/* @0x222f00 vmov d6, r2, r3 */
/* @0x222f04 vldr d7, [pc, #12] */
/* @0x222f08 vmul.f64 d6, d6, d7 */
/* @0x222f0c vmov r0, r1, d6 */
/* @0x222f10 b 0xb67d8 <sin@plt> */
/* @0x222f14 nop */
/* @0x222f18 strbpl r2, [r4], #-3352 */
/* @0x222f1c strdmi r2, r3, [r9], -r11 */

/* ── FUNC 0x222f20 · alutLoadMemoryWaveform · size=136 · insn=34 */
/* @0x222f20 push {r3, r4, r5, r6, r7, lr} */
/* @0x222f24 mov r4, r0 */
/* @0x222f28 mov r7, r1 */
/* @0x222f2c mov r6, r2 */
/* @0x222f30 mov r5, r3 */
/* @0x222f34 bl 0x2219a8 <_alutSanityCheck> */
/* @0x222f38 cmp r0, #0 */
/* @0x222f3c beq 0x222fa0 <alutLoadMemoryWaveform+0x80> */
/* @0x222f40 mov r0, r4 */
/* @0x222f44 vmov s0, r7 */
/* @0x222f48 vmov s1, r6 */
/* @0x222f4c vmov s2, r5 */
/* @0x222f50 bl 0x222c40 <alutGetMinorVersion+0x74> */
/* @0x222f54 subs r4, r0, #0 */
/* @0x222f58 beq 0x222fa0 <alutLoadMemoryWaveform+0x80> */
/* @0x222f5c bl 0x22291c <_alutOutputStreamGetData> */
/* @0x222f60 mov r5, r0 */
/* @0x222f64 mov r0, r4 */
/* @0x222f68 bl 0x222924 <_alutOutputStreamGetLength> */
/* @0x222f6c mov r1, r0 */
/* @0x222f70 mov r0, r5 */
/* @0x222f74 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x222f78 subs r5, r0, #0 */
/* @0x222f7c beq 0x222f90 <alutLoadMemoryWaveform+0x70> */
/* @0x222f80 add r1, sp, #24 */
/* @0x222f84 ldm r1, {r1, r2, r3} */
/* @0x222f88 bl 0x222664 <_alutLoadMemoryFromInputStream> */
/* @0x222f8c mov r5, r0 */
/* @0x222f90 mov r0, r4 */
/* @0x222f94 bl 0x2228fc <_alutOutputStreamDestroy> */
/* @0x222f98 mov r0, r5 */
/* @0x222f9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x222fa0 mov r0, #0 */
/* @0x222fa4 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x222fa8 · alutCreateBufferWaveform · size=128 · insn=32 */
/* @0x222fa8 push {r3, r4, r5, r6, r7, lr} */
/* @0x222fac mov r7, r0 */
/* @0x222fb0 mov r6, r1 */
/* @0x222fb4 mov r5, r2 */
/* @0x222fb8 mov r4, r3 */
/* @0x222fbc bl 0x2219a8 <_alutSanityCheck> */
/* @0x222fc0 cmp r0, #0 */
/* @0x222fc4 bne 0x222fd0 <alutCreateBufferWaveform+0x28> */
/* @0x222fc8 mov r0, #0 */
/* @0x222fcc pop {r3, r4, r5, r6, r7, pc} */
/* @0x222fd0 vmov s2, r4 */
/* @0x222fd4 mov r0, r7 */
/* @0x222fd8 vmov s0, r6 */
/* @0x222fdc vmov s1, r5 */
/* @0x222fe0 bl 0x222c40 <alutGetMinorVersion+0x74> */
/* @0x222fe4 subs r4, r0, #0 */
/* @0x222fe8 beq 0x222fc8 <alutCreateBufferWaveform+0x20> */
/* @0x222fec bl 0x22291c <_alutOutputStreamGetData> */
/* @0x222ff0 mov r5, r0 */
/* @0x222ff4 mov r0, r4 */
/* @0x222ff8 bl 0x222924 <_alutOutputStreamGetLength> */
/* @0x222ffc mov r1, r0 */
/* @0x223000 mov r0, r5 */
/* @0x223004 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x223008 subs r5, r0, #0 */
/* @0x22300c beq 0x223018 <alutCreateBufferWaveform+0x70> */
/* @0x223010 bl 0x2225cc <_alutCreateBufferFromInputStream> */
/* @0x223014 mov r5, r0 */
/* @0x223018 mov r0, r4 */
/* @0x22301c bl 0x2228fc <_alutOutputStreamDestroy> */
/* @0x223020 mov r0, r5 */
/* @0x223024 pop {r3, r4, r5, r6, r7, pc} */

/* ── FUNC 0x223028 · alutLoadMemoryHelloWorld · size=68 · insn=17 */
/* @0x223028 push {r4, r5, r6, lr} */
/* @0x22302c mov r6, r0 */
/* @0x223030 mov r5, r1 */
/* @0x223034 mov r4, r2 */
/* @0x223038 bl 0x2219a8 <_alutSanityCheck> */
/* @0x22303c cmp r0, #0 */
/* @0x223040 popeq {r4, r5, r6, pc} */
/* @0x223044 ldr r0, [pc, #0x1c] */
/* @0x223048 movw r1, #0x200a */
/* @0x22304c add r0, pc, r0 */
/* @0x223050 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x223054 mov r1, r6 */
/* @0x223058 mov r2, r5 */
/* @0x22305c mov r3, r4 */
/* @0x223060 pop {r4, r5, r6, lr} */
/* @0x223064 b 0x222664 <_alutLoadMemoryFromInputStream> */
/* @0x223068 andseq r2, sp, r12, lsl #5 */

/* ── FUNC 0x22306c · alutCreateBufferHelloWorld · size=44 · insn=11 */
/* @0x22306c push {r3, lr} */
/* @0x223070 bl 0x2219a8 <_alutSanityCheck> */
/* @0x223074 cmp r0, #0 */
/* @0x223078 popeq {r3, pc} */
/* @0x22307c ldr r0, [pc, #0x10] */
/* @0x223080 movw r1, #0x200a */
/* @0x223084 add r0, pc, r0 */
/* @0x223088 bl 0x221d94 <_alutInputStreamConstructFromMemory> */
/* @0x22308c pop {r3, lr} */
/* @0x223090 b 0x2225cc <_alutCreateBufferFromInputStream> */
/* @0x223094 andseq r2, sp, r4, asr r2 */

/* ── FUNC 0x223098 · OpenAL_PlayMP3(char const*, bool) · size=300 · insn=75 */
/* @0x223098 push {r4, r5, r6, r7, lr} */
/* @0x22309c sub sp, sp, #1040 */
/* @0x2230a0 ldr r5, [pc, #0x108] */
/* @0x2230a4 sub sp, sp, #4 */
/* @0x2230a8 ldr r2, [pc, #0x104] */
/* @0x2230ac mov r6, r1 */
/* @0x2230b0 add r5, pc, r5 */
/* @0x2230b4 ldrb r3, [r0] */
/* @0x2230b8 ldr r4, [r5, r2] */
/* @0x2230bc cmp r3, #46 */
/* @0x2230c0 cmpne r3, #0 */
/* @0x2230c4 ldr r2, [r4] */
/* @0x2230c8 str r2, [sp, #0x40c] */
/* @0x2230cc beq 0x2231a0 <_Z14OpenAL_PlayMP3PKcb+0x108> */
/* @0x2230d0 ldr r1, [pc, #0xe0] */
/* @0x2230d4 add r2, sp, #13 */
/* @0x2230d8 mov r7, #95 */
/* @0x2230dc ldr r1, [r5, r1] */
/* @0x2230e0 ldr r1, [r1] */
/* @0x2230e4 b 0x223114 <_Z14OpenAL_PlayMP3PKcb+0x7c> */
/* @0x2230e8 cmp r3, #95 */
/* @0x2230ec beq 0x223130 <_Z14OpenAL_PlayMP3PKcb+0x98> */
/* @0x2230f0 cmp r3, #36 */
/* @0x2230f4 strbne r7, [r2, #-0x1] */
/* @0x2230f8 beq 0x223130 <_Z14OpenAL_PlayMP3PKcb+0x98> */
/* @0x2230fc ldrb r3, [r0, #0x1]! */
/* @0x223100 mov r12, r2 */
/* @0x223104 add r2, r2, #1 */
/* @0x223108 cmp r3, #0 */
/* @0x22310c cmpne r3, #46 */
/* @0x223110 beq 0x223138 <_Z14OpenAL_PlayMP3PKcb+0xa0> */
/* @0x223114 add r3, r1, r3, lsl #1 */
/* @0x223118 ldrb r3, [r3, #0x2] */
/* @0x22311c sub lr, r3, #48 */
/* @0x223120 sub r12, r3, #97 */
/* @0x223124 cmp lr, #9 */
/* @0x223128 cmphi r12, #25 */
/* @0x22312c bhi 0x2230e8 <_Z14OpenAL_PlayMP3PKcb+0x50> */
/* @0x223130 strb r3, [r2, #-0x1] */
/* @0x223134 b 0x2230fc <_Z14OpenAL_PlayMP3PKcb+0x64> */
/* @0x223138 add r7, sp, #12 */
/* @0x22313c mov r3, #0 */
/* @0x223140 strb r3, [r12] */
/* @0x223144 bl 0x290274 <getJNIEnv> */
/* @0x223148 mov r1, r7 */
/* @0x22314c ldr r3, [r0] */
/* @0x223150 ldr r3, [r3, #0x29c] */
/* @0x223154 blx r3 */
/* @0x223158 mov r7, r0 */
/* @0x22315c bl 0x290274 <getJNIEnv> */
/* @0x223160 ldr r1, [pc, #0x54] */
/* @0x223164 mov r3, r7 */
/* @0x223168 ldr r2, [pc, #0x50] */
/* @0x22316c ldr r1, [r5, r1] */
/* @0x223170 ldr r2, [r5, r2] */
/* @0x223174 str r6, [sp] */
/* @0x223178 ldr r1, [r1] */
/* @0x22317c ldr r2, [r2] */
/* @0x223180 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x223184 ldr r2, [sp, #0x40c] */
/* @0x223188 ldr r3, [r4] */
/* @0x22318c cmp r2, r3 */
/* @0x223190 bne 0x2231ac <_Z14OpenAL_PlayMP3PKcb+0x114> */
/* @0x223194 add sp, sp, #1040 */
/* @0x223198 add sp, sp, #4 */
/* @0x22319c pop {r4, r5, r6, r7, pc} */
/* @0x2231a0 add r7, sp, #12 */
/* @0x2231a4 mov r12, r7 */
/* @0x2231a8 b 0x22313c <_Z14OpenAL_PlayMP3PKcb+0xa4> */
/* @0x2231ac bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x2231b0 andseq lr, r12, r0, lsr #23 */
/* @0x2231b4 .word 0xffffbd00 */
/* @0x2231b8 .word 0xffffbd34 */
/* @0x2231bc .word 0xffffbd54 */
/* @0x2231c0 .word 0xfffff80c */

/* ── FUNC 0x2231c4 · OpenAL_PauseMP3() · size=48 · insn=12 */
/* @0x2231c4 push {r3, lr} */
/* @0x2231c8 bl 0x290274 <getJNIEnv> */
/* @0x2231cc ldr r2, [pc, #0x18] */
/* @0x2231d0 ldr r3, [pc, #0x18] */
/* @0x2231d4 ldr r2, [pc, r2] */
/* @0x2231d8 ldr r3, [pc, r3] */
/* @0x2231dc ldr r1, [r2] */
/* @0x2231e0 ldr r2, [r3] */
/* @0x2231e4 pop {r3, lr} */
/* @0x2231e8 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x2231ec ldrsbeq r10, [r12], -r0 */
/* @0x2231f0 andseq lr, r12, r8, lsl #5 */

/* ── FUNC 0x2231f4 · OpenAL_ResumeMP3() · size=48 · insn=12 */
/* @0x2231f4 push {r3, lr} */
/* @0x2231f8 bl 0x290274 <getJNIEnv> */
/* @0x2231fc ldr r2, [pc, #0x18] */
/* @0x223200 ldr r3, [pc, #0x18] */
/* @0x223204 ldr r2, [pc, r2] */
/* @0x223208 ldr r3, [pc, r3] */
/* @0x22320c ldr r1, [r2] */
/* @0x223210 ldr r2, [r3] */
/* @0x223214 pop {r3, lr} */
/* @0x223218 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x22321c andseq r10, r12, r0, lsr #15 */
/* @0x223220 andseq lr, r12, r12, asr r2 */

/* ── FUNC 0x223224 · OpenAL_StopMP3() · size=48 · insn=12 */
/* @0x223224 push {r3, lr} */
/* @0x223228 bl 0x290274 <getJNIEnv> */
/* @0x22322c ldr r2, [pc, #0x18] */
/* @0x223230 ldr r3, [pc, #0x18] */
/* @0x223234 ldr r2, [pc, r2] */
/* @0x223238 ldr r3, [pc, r3] */
/* @0x22323c ldr r1, [r2] */
/* @0x223240 ldr r2, [r3] */
/* @0x223244 pop {r3, lr} */
/* @0x223248 b 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x22324c andseq r10, r12, r0, ror r7 */
/* @0x223250 andseq lr, r12, r0, lsr r2 */

/* ── FUNC 0x223254 · OpenAL_MP3_SetVolume(float) · size=76 · insn=19 */
/* @0x223254 str lr, [sp, #-0x4]! */
/* @0x223258 vpush {d8} */
/* @0x22325c vmov s16, r0 */
/* @0x223260 sub sp, sp, #12 */
/* @0x223264 bl 0x290274 <getJNIEnv> */
/* @0x223268 vcvt.f64.f32 d7, s16 */
/* @0x22326c ldr r2, [pc, #0x24] */
/* @0x223270 ldr r3, [pc, #0x24] */
/* @0x223274 ldr r2, [pc, r2] */
/* @0x223278 ldr r3, [pc, r3] */
/* @0x22327c ldr r1, [r2] */
/* @0x223280 ldr r2, [r3] */
/* @0x223284 vstr d7, [sp] */
/* @0x223288 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz> */
/* @0x22328c add sp, sp, #12 */
/* @0x223290 vpop {d8} */
/* @0x223294 ldr pc, [sp], #4 */
/* @0x223298 andseq r10, r12, r0, lsr r7 */
/* @0x22329c ldrsheq lr, [r12], -r4 */

/* ── FUNC 0x2232a0 · OpenAL_PlayingMP3() · size=56 · insn=14 */
/* @0x2232a0 push {r3, lr} */
/* @0x2232a4 bl 0x290274 <getJNIEnv> */
/* @0x2232a8 ldr r2, [pc, #0x20] */
/* @0x2232ac ldr r3, [pc, #0x20] */
/* @0x2232b0 ldr r2, [pc, r2] */
/* @0x2232b4 ldr r3, [pc, r3] */
/* @0x2232b8 ldr r1, [r2] */
/* @0x2232bc ldr r2, [r3] */
/* @0x2232c0 bl 0x15e0b0 <_ZN7_JNIEnv23CallStaticBooleanMethodEP7_jclassP10_jmethodIDz> */
/* @0x2232c4 adds r0, r0, #0 */
/* @0x2232c8 movne r0, #1 */
/* @0x2232cc pop {r3, pc} */
/* @0x2232d0 ldrsheq r10, [r12], -r4 */
/* @0x2232d4 ldrheq lr, [r12], -r12 */

/* ── FUNC 0x2232d8 · OpenAL_Tick() · size=4 · insn=1 */
/* @0x2232d8 bx lr */

/* ── FUNC 0x2232dc · OpenAL_Close() · size=4 · insn=1 */
/* @0x2232dc bx lr */

/* ── FUNC 0x2232e0 · OpenAL_Init() · size=4 · insn=1 */
/* @0x2232e0 bx lr */

/* ── FUNC 0x2232e4 · OpenAL_Quit() · size=4 · insn=1 */
/* @0x2232e4 bx lr */

/* ── FUNC 0x2232e8 · OpenAL_Setup(IniFile*) · size=268 · insn=67 */
/* @0x2232e8 push {r3, r4, r5, r6, r7, lr} */
/* @0x2232ec mov r4, r0 */
/* @0x2232f0 ldr r3, [pc, #0xd8] */
/* @0x2232f4 ldr r1, [pc, #0xd8] */
/* @0x2232f8 ldr r3, [pc, r3] */
/* @0x2232fc add r1, pc, r1 */
/* @0x223300 ldr r6, [r3] */
/* @0x223304 ldr r3, [r6] */
/* @0x223308 mov r0, r6 */
/* @0x22330c ldr r3, [r3, #0xc] */
/* @0x223310 blx r3 */
/* @0x223314 ldr r1, [pc, #0xbc] */
/* @0x223318 ldr r2, [pc, #0xbc] */
/* @0x22331c mov r0, r4 */
/* @0x223320 add r1, pc, r1 */
/* @0x223324 add r2, pc, r2 */
/* @0x223328 bl 0x235ad0 <_ZN7IniFile6GetKeyEPKcS1_> */
/* @0x22332c cmp r0, #0 */
/* @0x223330 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x223334 bl 0x2a2e90 <android_getCpuFamily> */
/* @0x223338 ldr r3, [r6] */
/* @0x22333c ldr r1, [pc, #0x9c] */
/* @0x223340 ldr r3, [r3, #0xc] */
/* @0x223344 add r1, pc, r1 */
/* @0x223348 mov r7, r0 */
/* @0x22334c mov r2, r0 */
/* @0x223350 mov r0, r6 */
/* @0x223354 blx r3 */
/* @0x223358 cmp r7, #1 */
/* @0x22335c popne {r3, r4, r5, r6, r7, pc} */
/* @0x223360 ldr r3, [r6] */
/* @0x223364 mov r0, r6 */
/* @0x223368 ldr r1, [pc, #0x74] */
/* @0x22336c mov r4, #1 */
/* @0x223370 mov r5, #0 */
/* @0x223374 ldr r3, [r3, #0xc] */
/* @0x223378 add r1, pc, r1 */
/* @0x22337c blx r3 */
/* @0x223380 bl 0x2a2ebc <android_getCpuFeatures> */
/* @0x223384 and r0, r0, r4 */
/* @0x223388 and r1, r1, r5 */
/* @0x22338c orrs r3, r0, r1 */
/* @0x223390 ldr r3, [r6] */
/* @0x223394 mov r0, r6 */
/* @0x223398 beq 0x2233b0 <_Z12OpenAL_SetupP7IniFile+0xc8> */
/* @0x22339c ldr r1, [pc, #0x44] */
/* @0x2233a0 ldr r3, [r3, #0xc] */
/* @0x2233a4 add r1, pc, r1 */
/* @0x2233a8 blx r3 */
/* @0x2233ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x2233b0 ldr r1, [pc, #0x34] */
/* @0x2233b4 ldr r3, [r3, #0xc] */
/* @0x2233b8 add r1, pc, r1 */
/* @0x2233bc blx r3 */
/* @0x2233c0 ldr r3, [pc, #0x28] */
/* @0x2233c4 ldr r3, [pc, r3] */
/* @0x2233c8 strb r7, [r3] */
/* @0x2233cc pop {r3, r4, r5, r6, r7, pc} */
/* @0x2233d0 andseq r10, r12, r12, lsl r4 */
/* @0x2233d4 andseq r1, r3, r8, lsr #18 */
/* @0x2233d8 andseq r1, r3, r4, lsl r9 */
/* @0x2233dc andseq r1, r3, r0, lsr #18 */
/* @0x2233e0 andseq r1, r3, r0, lsl r9 */
/* @0x2233e4 andseq r1, r3, r4, lsl #18 */
/* @0x2233e8 andseq r1, r3, r0, lsl r9 */
/* @0x2233ec andseq r1, r3, r4, ror #17 */
/* @0x2233f0 andseq lr, r12, r0, ror r0 */

/* ── FUNC 0x2233f4 · SOggChannel::SOggChannel() · size=128 · insn=32 */
/* @0x2233f4 push {r4, lr} */
/* @0x2233f8 mov r1, #0 */
/* @0x2233fc mov r2, #664 */
/* @0x223400 mov r4, r0 */
/* @0x223404 bl 0xb65b0 <memset@plt> */
/* @0x223408 mov r0, #752 */
/* @0x22340c mov r12, #1065353216 */
/* @0x223410 mvn r3, #0 */
/* @0x223414 mov r1, #3 */
/* @0x223418 str r3, [r4, #0x2b8] */
/* @0x22341c str r1, [r4, #0x2f8] */
/* @0x223420 mvn r2, #0 */
/* @0x223424 mov r1, #0 */
/* @0x223428 mvn r3, #-2147483648 */
/* @0x22342c strd r2, r3, [r4, r0] */
/* @0x223430 mov r0, r4 */
/* @0x223434 str r1, [r4, #0x298] */
/* @0x223438 str r1, [r4, #0x2bc] */
/* @0x22343c str r1, [r4, #0x2c0] */
/* @0x223440 str r1, [r4, #0x2c4] */
/* @0x223444 strb r1, [r4, #0x2d5] */
/* @0x223448 str r12, [r4, #0x2ec] */
/* @0x22344c strb r1, [r4, #0x2d6] */
/* @0x223450 str r1, [r4, #0x2d8] */
/* @0x223454 strb r1, [r4, #0x2d4] */
/* @0x223458 str r1, [r4, #0x2e0] */
/* @0x22345c strb r1, [r4, #0x2fc] */
/* @0x223460 str r1, [r4, #0x2a8] */
/* @0x223464 str r1, [r4, #0x29c] */
/* @0x223468 str r1, [r4, #0x2a0] */
/* @0x22346c str r1, [r4, #0x2a4] */
/* @0x223470 pop {r4, pc} */

/* ── FUNC 0x2233f4 · SOggChannel::SOggChannel() · alias of the symbol above · insn=0 */
