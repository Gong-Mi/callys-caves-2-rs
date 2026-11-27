/* libyoyo.so 覆盖卡组 0137
 * 函数 0x1a47a0..0x1a6e80，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1a47a0 · ParticleSystem_DrawOrder(int, bool) · size=52 · insn=13 */
/* @0x1a47a0 push {r3, r4, r5, lr} */
/* @0x1a47a4 mov r5, r1 */
/* @0x1a47a8 mov r4, r0 */
/* @0x1a47ac bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a47b0 cmp r0, #0 */
/* @0x1a47b4 popeq {r3, r4, r5, pc} */
/* @0x1a47b8 ldr r3, [pc, #0x10] */
/* @0x1a47bc ldr r3, [pc, r3] */
/* @0x1a47c0 ldr r3, [r3, #0x4] */
/* @0x1a47c4 ldr r3, [r3, r4, lsl #2] */
/* @0x1a47c8 strb r5, [r3, #0x18] */
/* @0x1a47cc pop {r3, r4, r5, pc} */
/* @0x1a47d0 .word 0x0024bffc */

/* ── FUNC 0x1a47d4 · ParticleSystem_Depth(int, float) · size=192 · insn=48 */
/* @0x1a47d4 push {r4, r5, r6, lr} */
/* @0x1a47d8 sub sp, sp, #8 */
/* @0x1a47dc mov r6, r1 */
/* @0x1a47e0 mov r5, r0 */
/* @0x1a47e4 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a47e8 cmp r0, #0 */
/* @0x1a47ec beq 0x1a4818 <_Z20ParticleSystem_Depthif+0x44> */
/* @0x1a47f0 ldr r3, [pc, #0x90] */
/* @0x1a47f4 ldr r4, [pc, #0x90] */
/* @0x1a47f8 ldr r3, [pc, r3] */
/* @0x1a47fc ldr r4, [pc, r4] */
/* @0x1a4800 ldrb r2, [r3] */
/* @0x1a4804 ldr r3, [r4, #0x4] */
/* @0x1a4808 cmp r2, #0 */
/* @0x1a480c ldr r3, [r3, r5, lsl #2] */
/* @0x1a4810 str r6, [r3, #0x1c] */
/* @0x1a4814 bne 0x1a4820 <_Z20ParticleSystem_Depthif+0x4c> */
/* @0x1a4818 add sp, sp, #8 */
/* @0x1a481c pop {r4, r5, r6, pc} */
/* @0x1a4820 ldr r6, [pc, #0x68] */
/* @0x1a4824 mov r2, #1 */
/* @0x1a4828 ldr r1, [r3, #0x2c] */
/* @0x1a482c mov r3, #0 */
/* @0x1a4830 ldr r6, [pc, r6] */
/* @0x1a4834 ldr r0, [r6] */
/* @0x1a4838 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a483c bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv> */
/* @0x1a4840 ldr r1, [r4, #0x4] */
/* @0x1a4844 mov r12, #1 */
/* @0x1a4848 mvn lr, #0 */
/* @0x1a484c ldr r4, [r1, r5, lsl #2] */
/* @0x1a4850 vldr s15, [r4, #28] */
/* @0x1a4854 vcvt.s32.f32 s15, s15 */
/* @0x1a4858 vmov r1, s15 */
/* @0x1a485c mov r3, r0 */
/* @0x1a4860 ldr r0, [r6] */
/* @0x1a4864 str r5, [r3, #0x1c] */
/* @0x1a4868 mov r2, r3 */
/* @0x1a486c str lr, [r4, #0x30] */
/* @0x1a4870 mov r3, r12 */
/* @0x1a4874 str r12, [sp] */
/* @0x1a4878 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb> */
/* @0x1a487c str r0, [r4, #0x2c] */
/* @0x1a4880 add sp, sp, #8 */
/* @0x1a4884 pop {r4, r5, r6, pc} */
/* @0x1a4888 eoreq r9, r4, r12, lsr #2 */
/* @0x1a488c .word 0x0024bfbc */
/* @0x1a4890 .word 0x002490f8 */

/* ── FUNC 0x1a4894 · ParticleSystem_Position(int, float, float) · size=60 · insn=15 */
/* @0x1a4894 push {r4, r5, r6, lr} */
/* @0x1a4898 mov r6, r1 */
/* @0x1a489c mov r4, r0 */
/* @0x1a48a0 mov r5, r2 */
/* @0x1a48a4 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a48a8 cmp r0, #0 */
/* @0x1a48ac popeq {r4, r5, r6, pc} */
/* @0x1a48b0 ldr r3, [pc, #0x14] */
/* @0x1a48b4 ldr r3, [pc, r3] */
/* @0x1a48b8 ldr r3, [r3, #0x4] */
/* @0x1a48bc ldr r3, [r3, r4, lsl #2] */
/* @0x1a48c0 str r6, [r3, #0x20] */
/* @0x1a48c4 str r5, [r3, #0x24] */
/* @0x1a48c8 pop {r4, r5, r6, pc} */
/* @0x1a48cc eoreq r11, r4, r4, lsl #30 */

/* ── FUNC 0x1a48d0 · ParticleSystem_AutomaticUpdate(int, bool) · size=52 · insn=13 */
/* @0x1a48d0 push {r3, r4, r5, lr} */
/* @0x1a48d4 mov r5, r1 */
/* @0x1a48d8 mov r4, r0 */
/* @0x1a48dc bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a48e0 cmp r0, #0 */
/* @0x1a48e4 popeq {r3, r4, r5, pc} */
/* @0x1a48e8 ldr r3, [pc, #0x10] */
/* @0x1a48ec ldr r3, [pc, r3] */
/* @0x1a48f0 ldr r3, [r3, #0x4] */
/* @0x1a48f4 ldr r3, [r3, r4, lsl #2] */
/* @0x1a48f8 strb r5, [r3, #0x28] */
/* @0x1a48fc pop {r3, r4, r5, pc} */
/* @0x1a4900 eoreq r11, r4, r12, asr #29 */

/* ── FUNC 0x1a4904 · ParticleSystem_AutomaticDraw(int, bool) · size=52 · insn=13 */
/* @0x1a4904 push {r3, r4, r5, lr} */
/* @0x1a4908 mov r5, r1 */
/* @0x1a490c mov r4, r0 */
/* @0x1a4910 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a4914 cmp r0, #0 */
/* @0x1a4918 popeq {r3, r4, r5, pc} */
/* @0x1a491c ldr r3, [pc, #0x10] */
/* @0x1a4920 ldr r3, [pc, r3] */
/* @0x1a4924 ldr r3, [r3, #0x4] */
/* @0x1a4928 ldr r3, [r3, r4, lsl #2] */
/* @0x1a492c strb r5, [r3, #0x29] */
/* @0x1a4930 pop {r3, r4, r5, pc} */
/* @0x1a4934 mlaeq r4, r8, lr, r11 */

/* ── FUNC 0x1a4938 · HandleLife(int) · size=620 · insn=155 */
/* @0x1a4938 ldr r3, [pc, #0x258] */
/* @0x1a493c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a4940 ldr r3, [pc, r3] */
/* @0x1a4944 mov r9, r0 */
/* @0x1a4948 sub sp, sp, #20 */
/* @0x1a494c ldr r3, [r3, #0x4] */
/* @0x1a4950 ldr r6, [r3, r0, lsl #2] */
/* @0x1a4954 ldr r0, [r6, #0x8] */
/* @0x1a4958 cmp r0, #0 */
/* @0x1a495c ble 0x1a4b90 <_Z10HandleLifei+0x258> */
/* @0x1a4960 ldr r8, [pc, #0x234] */
/* @0x1a4964 mov r4, #0 */
/* @0x1a4968 ldr r11, [pc, #0x230] */
/* @0x1a496c mov r10, r4 */
/* @0x1a4970 ldr r8, [pc, r8] */
/* @0x1a4974 add r11, pc, r11 */
/* @0x1a4978 str r11, [sp, #0xc] */
/* @0x1a497c mov r11, r8 */
/* @0x1a4980 ldr r1, [r6, #0x4] */
/* @0x1a4984 lsl r7, r4, #2 */
/* @0x1a4988 ldr r12, [r11, #0x4] */
/* @0x1a498c ldr r2, [r1, r4, lsl #2] */
/* @0x1a4990 ldr r3, [r2, #0x8] */
/* @0x1a4994 ldr r8, [r2, #0xc] */
/* @0x1a4998 add r3, r3, #1 */
/* @0x1a499c ldr r5, [r2, #0x4] */
/* @0x1a49a0 cmp r3, r8 */
/* @0x1a49a4 ldr r5, [r12, r5, lsl #2] */
/* @0x1a49a8 str r3, [r2, #0x8] */
/* @0x1a49ac blt 0x1a4a8c <_Z10HandleLifei+0x154> */
/* @0x1a49b0 cmp r5, #0 */
/* @0x1a49b4 strb r10, [r2] */
/* @0x1a49b8 beq 0x1a4adc <_Z10HandleLifei+0x1a4> */
/* @0x1a49bc ldr r8, [r5, #0x30] */
/* @0x1a49c0 cmp r8, #0 */
/* @0x1a49c4 blt 0x1a4aec <_Z10HandleLifei+0x1b4> */
/* @0x1a49c8 beq 0x1a4adc <_Z10HandleLifei+0x1a4> */
/* @0x1a49cc ldr r1, [r2, #0x10] */
/* @0x1a49d0 mov r0, r9 */
/* @0x1a49d4 ldr r3, [r5, #0x2c] */
/* @0x1a49d8 ldr r2, [r2, #0x14] */
/* @0x1a49dc str r8, [sp] */
/* @0x1a49e0 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */
/* @0x1a49e4 ldr r1, [r6, #0x4] */
/* @0x1a49e8 ldr r3, [r1, r7] */
/* @0x1a49ec ldrb r3, [r3] */
/* @0x1a49f0 cmp r3, #0 */
/* @0x1a49f4 bne 0x1a4aa0 <_Z10HandleLifei+0x168> */
/* @0x1a49f8 ldr r0, [r6, #0x8] */
/* @0x1a49fc add r4, r4, #1 */
/* @0x1a4a00 cmp r0, r4 */
/* @0x1a4a04 bgt 0x1a4980 <_Z10HandleLifei+0x48> */
/* @0x1a4a08 cmp r0, #0 */
/* @0x1a4a0c ble 0x1a4b90 <_Z10HandleLifei+0x258> */
/* @0x1a4a10 mov r12, #0 */
/* @0x1a4a14 mov r3, r12 */
/* @0x1a4a18 ldr r1, [r6, #0x4] */
/* @0x1a4a1c ldr r2, [r1, r3, lsl #2] */
/* @0x1a4a20 ldrb r4, [r2] */
/* @0x1a4a24 cmp r4, #0 */
/* @0x1a4a28 beq 0x1a4a74 <_Z10HandleLifei+0x13c> */
/* @0x1a4a2c cmp r3, r12 */
/* @0x1a4a30 beq 0x1a4a70 <_Z10HandleLifei+0x138> */
/* @0x1a4a34 ldr r1, [r1, r12, lsl #2] */
/* @0x1a4a38 add r0, r2, #64 */
/* @0x1a4a3c ldr r8, [r2] */
/* @0x1a4a40 add r2, r2, #16 */
/* @0x1a4a44 ldr r7, [r2, #-0xc] */
/* @0x1a4a48 add r1, r1, #16 */
/* @0x1a4a4c ldr r5, [r2, #-0x8] */
/* @0x1a4a50 ldr r4, [r2, #-0x4] */
/* @0x1a4a54 cmp r2, r0 */
/* @0x1a4a58 str r8, [r1, #-0x10] */
/* @0x1a4a5c str r7, [r1, #-0xc] */
/* @0x1a4a60 str r5, [r1, #-0x8] */
/* @0x1a4a64 str r4, [r1, #-0x4] */
/* @0x1a4a68 bne 0x1a4a3c <_Z10HandleLifei+0x104> */
/* @0x1a4a6c ldr r0, [r6, #0x8] */
/* @0x1a4a70 add r12, r12, #1 */
/* @0x1a4a74 add r3, r3, #1 */
/* @0x1a4a78 cmp r0, r3 */
/* @0x1a4a7c bgt 0x1a4a18 <_Z10HandleLifei+0xe0> */
/* @0x1a4a80 str r12, [r6, #0x8] */
/* @0x1a4a84 add sp, sp, #20 */
/* @0x1a4a88 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a4a8c ldrb r3, [r2] */
/* @0x1a4a90 cmp r3, #0 */
/* @0x1a4a94 beq 0x1a4adc <_Z10HandleLifei+0x1a4> */
/* @0x1a4a98 cmp r5, #0 */
/* @0x1a4a9c beq 0x1a4adc <_Z10HandleLifei+0x1a4> */
/* @0x1a4aa0 ldr r8, [r5, #0x38] */
/* @0x1a4aa4 cmp r8, #0 */
/* @0x1a4aa8 blt 0x1a4b2c <_Z10HandleLifei+0x1f4> */
/* @0x1a4aac beq 0x1a49f8 <_Z10HandleLifei+0xc0> */
/* @0x1a4ab0 ldr r2, [r1, r7] */
/* @0x1a4ab4 ldr r3, [r5, #0x34] */
/* @0x1a4ab8 ldr r1, [r2, #0x4] */
/* @0x1a4abc cmp r3, r1 */
/* @0x1a4ac0 beq 0x1a4b7c <_Z10HandleLifei+0x244> */
/* @0x1a4ac4 ldr r1, [r2, #0x10] */
/* @0x1a4ac8 mov r0, r9 */
/* @0x1a4acc ldr r2, [r2, #0x14] */
/* @0x1a4ad0 str r8, [sp] */
/* @0x1a4ad4 bl 0x1a3b78 <_Z31ParticleSystem_Particles_Createiffii> */
/* @0x1a4ad8 ldr r0, [r6, #0x8] */
/* @0x1a4adc add r4, r4, #1 */
/* @0x1a4ae0 cmp r0, r4 */
/* @0x1a4ae4 bgt 0x1a4980 <_Z10HandleLifei+0x48> */
/* @0x1a4ae8 b 0x1a4a08 <_Z10HandleLifei+0xd0> */
/* @0x1a4aec mov r0, #0 */
/* @0x1a4af0 mov r1, #0 */
/* @0x1a4af4 movt r1, #0x3ff0 */
/* @0x1a4af8 rsb r8, r8, #0 */
/* @0x1a4afc bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a4b00 vmov s14, r8 */
/* @0x1a4b04 vcvt.f64.s32 d7, s14 */
/* @0x1a4b08 vmov d6, r0, r1 */
/* @0x1a4b0c vmul.f64 d7, d6, d7 */
/* @0x1a4b10 vcmp.f64 d7, #0 */
/* @0x1a4b14 vmrs APSR_nzcv, fpscr */
/* @0x1a4b18 bne 0x1a4b6c <_Z10HandleLifei+0x234> */
/* @0x1a4b1c ldr r3, [r6, #0x4] */
/* @0x1a4b20 mov r8, #1 */
/* @0x1a4b24 ldr r2, [r3, r7] */
/* @0x1a4b28 b 0x1a49cc <_Z10HandleLifei+0x94> */
/* @0x1a4b2c mov r0, #0 */
/* @0x1a4b30 mov r1, #0 */
/* @0x1a4b34 movt r1, #0x3ff0 */
/* @0x1a4b38 rsb r8, r8, #0 */
/* @0x1a4b3c bl 0xc4598 <_Z9fYYRandomd> */
/* @0x1a4b40 vmov s14, r8 */
/* @0x1a4b44 vcvt.f64.s32 d7, s14 */
/* @0x1a4b48 vmov d6, r0, r1 */
/* @0x1a4b4c vmul.f64 d7, d7, d6 */
/* @0x1a4b50 vcvt.s32.f64 s14, d7 */
/* @0x1a4b54 vmov r3, s14 */
/* @0x1a4b58 cmp r3, #0 */
/* @0x1a4b5c bne 0x1a49f8 <_Z10HandleLifei+0xc0> */
/* @0x1a4b60 ldr r1, [r6, #0x4] */
/* @0x1a4b64 mov r8, #1 */
/* @0x1a4b68 b 0x1a4ab0 <_Z10HandleLifei+0x178> */
/* @0x1a4b6c ldr r1, [r6, #0x4] */
/* @0x1a4b70 ldr r3, [r1, r7] */
/* @0x1a4b74 ldrb r3, [r3] */
/* @0x1a4b78 b 0x1a49f0 <_Z10HandleLifei+0xb8> */
/* @0x1a4b7c ldr r0, [sp, #0xc] */
/* @0x1a4b80 mov r1, #0 */
/* @0x1a4b84 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1a4b88 ldr r0, [r6, #0x8] */
/* @0x1a4b8c b 0x1a49fc <_Z10HandleLifei+0xc4> */
/* @0x1a4b90 mov r12, #0 */
/* @0x1a4b94 b 0x1a4a80 <_Z10HandleLifei+0x148> */
/* @0x1a4b98 eoreq r11, r4, r8, ror lr */
/* @0x1a4b9c eoreq r11, r4, r12, lsr lr */
/* @0x1a4ba0 andseq r8, r10, r12, lsr #14 */

/* ── FUNC 0x1a4ba4 · HandleMotion(int) · size=592 · insn=148 */
/* @0x1a4ba4 ldr r3, [pc, #0x240] */
/* @0x1a4ba8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a4bac vpush {d8, d9} */
/* @0x1a4bb0 ldr r3, [pc, r3] */
/* @0x1a4bb4 vldr s16, [pc, #556] */
/* @0x1a4bb8 sub sp, sp, #28 */
/* @0x1a4bbc vstr s16, [sp, #8] */
/* @0x1a4bc0 ldr r3, [r3, #0x4] */
/* @0x1a4bc4 vstr s16, [sp, #12] */
/* @0x1a4bc8 vstr s16, [sp, #16] */
/* @0x1a4bcc vstr s16, [sp, #20] */
/* @0x1a4bd0 ldr r7, [r3, r0, lsl #2] */
/* @0x1a4bd4 ldr r3, [r7, #0x8] */
/* @0x1a4bd8 cmp r3, #0 */
/* @0x1a4bdc ble 0x1a4ddc <_Z12HandleMotioni+0x238> */
/* @0x1a4be0 ldr r10, [pc, #0x208] */
/* @0x1a4be4 movw r11, #0xaaab */
/* @0x1a4be8 movw r1, #0x6667 */
/* @0x1a4bec vmov.f32 s19, #6.000000e+00 */
/* @0x1a4bf0 movt r1, #0x6666 */
/* @0x1a4bf4 ldr r10, [pc, r10] */
/* @0x1a4bf8 movt r11, #0x2aaa */
/* @0x1a4bfc str r1, [sp, #0x4] */
/* @0x1a4c00 mov r6, #0 */
/* @0x1a4c04 vmov.f32 s18, #2.000000e+00 */
/* @0x1a4c08 vmov.f32 s17, #1.000000e+00 */
/* @0x1a4c0c b 0x1a4cf0 <_Z12HandleMotioni+0x14c> */
/* @0x1a4c10 ldr r2, [r4, #0x3c] */
/* @0x1a4c14 vmov.f32 s11, #5.000000e+00 */
/* @0x1a4c18 ldr r3, [r4, #0x8] */
/* @0x1a4c1c add r1, r2, r2, lsl #1 */
/* @0x1a4c20 add r3, r1, r3 */
/* @0x1a4c24 smull r1, r0, r11, r3 */
/* @0x1a4c28 asr r1, r3, #31 */
/* @0x1a4c2c rsb r1, r1, r0, asr #2 */
/* @0x1a4c30 add r1, r1, r1, lsl #1 */
/* @0x1a4c34 sub r1, r3, r1, lsl #3 */
/* @0x1a4c38 add r3, r3, r2 */
/* @0x1a4c3c ldr r2, [sp, #0x4] */
/* @0x1a4c40 vmov s10, r1 */
/* @0x1a4c44 vcvt.f32.s32 s13, s10 */
/* @0x1a4c48 smull r2, r1, r2, r3 */
/* @0x1a4c4c asr r2, r3, #31 */
/* @0x1a4c50 vdiv.f32 s13, s13, s19 */
/* @0x1a4c54 rsb r2, r2, r1, asr #3 */
/* @0x1a4c58 add r2, r2, r2, lsl #2 */
/* @0x1a4c5c sub r3, r3, r2, lsl #2 */
/* @0x1a4c60 mov r2, r9 */
/* @0x1a4c64 vmov s10, r3 */
/* @0x1a4c68 mov r3, r8 */
/* @0x1a4c6c vcmpe.f32 s13, s18 */
/* @0x1a4c70 vmrs APSR_nzcv, fpscr */
/* @0x1a4c74 vmovgt.f32 s14, #4.000000e+00 */
/* @0x1a4c78 vsubgt.f32 s13, s14, s13 */
/* @0x1a4c7c vcvt.f32.s32 s14, s10 */
/* @0x1a4c80 vldr s10, [r5, #88] */
/* @0x1a4c84 vdiv.f32 s14, s14, s11 */
/* @0x1a4c88 vcmpe.f32 s14, s18 */
/* @0x1a4c8c vmrs APSR_nzcv, fpscr */
/* @0x1a4c90 vmovgt.f32 s11, #4.000000e+00 */
/* @0x1a4c94 vsubgt.f32 s14, s11, s14 */
/* @0x1a4c98 vldr s11, [r5, #72] */
/* @0x1a4c9c vsub.f32 s13, s13, s17 */
/* @0x1a4ca0 vsub.f32 s14, s14, s17 */
/* @0x1a4ca4 vmla.f32 s12, s13, s10 */
/* @0x1a4ca8 vmla.f32 s15, s14, s11 */
/* @0x1a4cac vmov r0, s12 */
/* @0x1a4cb0 vmov r1, s15 */
/* @0x1a4cb4 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_> */
/* @0x1a4cb8 vldr s12, [r4, #16] */
/* @0x1a4cbc vldr s13, [r4, #20] */
/* @0x1a4cc0 vldr s14, [sp, #8] */
/* @0x1a4cc4 vldr s15, [sp, #12] */
/* @0x1a4cc8 vadd.f32 s14, s12, s14 */
/* @0x1a4ccc ldr r3, [r7, #0x8] */
/* @0x1a4cd0 vadd.f32 s15, s13, s15 */
/* @0x1a4cd4 vadd.f32 s14, s14, s16 */
/* @0x1a4cd8 vadd.f32 s15, s15, s16 */
/* @0x1a4cdc vstr s14, [r4, #16] */
/* @0x1a4ce0 vstr s15, [r4, #20] */
/* @0x1a4ce4 add r6, r6, #1 */
/* @0x1a4ce8 cmp r3, r6 */
/* @0x1a4cec ble 0x1a4ddc <_Z12HandleMotioni+0x238> */
/* @0x1a4cf0 ldr r1, [r7, #0x4] */
/* @0x1a4cf4 ldr r2, [r10, #0x4] */
/* @0x1a4cf8 ldr r4, [r1, r6, lsl #2] */
/* @0x1a4cfc ldr r1, [r4, #0x4] */
/* @0x1a4d00 ldr r5, [r2, r1, lsl #2] */
/* @0x1a4d04 cmp r5, #0 */
/* @0x1a4d08 beq 0x1a4ce4 <_Z12HandleMotioni+0x140> */
/* @0x1a4d0c vldr s15, [r5, #68] */
/* @0x1a4d10 vldr s14, [r4, #32] */
/* @0x1a4d14 vadd.f32 s15, s14, s15 */
/* @0x1a4d18 vldr s12, [r4, #36] */
/* @0x1a4d1c vldr s14, [r5, #84] */
/* @0x1a4d20 vldr s11, [r4, #40] */
/* @0x1a4d24 vldr s13, [r5, #92] */
/* @0x1a4d28 ldr r2, [r4, #0x10] */
/* @0x1a4d2c ldr r3, [r4, #0x14] */
/* @0x1a4d30 add r9, sp, #8 */
/* @0x1a4d34 add r8, sp, #12 */
/* @0x1a4d38 str r2, [r4, #0x18] */
/* @0x1a4d3c str r3, [r4, #0x1c] */
/* @0x1a4d40 vadd.f32 s12, s12, s14 */
/* @0x1a4d44 vldr s14, [r5, #108] */
/* @0x1a4d48 vadd.f32 s14, s11, s14 */
/* @0x1a4d4c vstr s12, [r4, #36] */
/* @0x1a4d50 vcmpe.f32 s15, #0 */
/* @0x1a4d54 vstr s14, [r4, #40] */
/* @0x1a4d58 vmrs APSR_nzcv, fpscr */
/* @0x1a4d5c vcmp.f32 s13, #0 */
/* @0x1a4d60 vstrpl s15, [r4, #32] */
/* @0x1a4d64 vstrmi s16, [r4, #32] */
/* @0x1a4d68 vldrmi s15, [pc, #120] */
/* @0x1a4d6c vmrs APSR_nzcv, fpscr */
/* @0x1a4d70 beq 0x1a4c10 <_Z12HandleMotioni+0x6c> */
/* @0x1a4d74 vmov r0, s12 */
/* @0x1a4d78 mov r2, r9 */
/* @0x1a4d7c vmov r1, s15 */
/* @0x1a4d80 mov r3, r8 */
/* @0x1a4d84 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_> */
/* @0x1a4d88 ldr r0, [r5, #0x60] */
/* @0x1a4d8c ldr r1, [r5, #0x5c] */
/* @0x1a4d90 add r2, sp, #16 */
/* @0x1a4d94 add r3, sp, #20 */
/* @0x1a4d98 bl 0x1a2a38 <_Z19Direction_To_VectorffPfS_> */
/* @0x1a4d9c vldr s12, [sp, #8] */
/* @0x1a4da0 vldr s13, [sp, #12] */
/* @0x1a4da4 vldr s14, [sp, #16] */
/* @0x1a4da8 vldr s15, [sp, #20] */
/* @0x1a4dac vadd.f32 s14, s12, s14 */
/* @0x1a4db0 add r2, r4, #36 */
/* @0x1a4db4 add r3, r4, #32 */
/* @0x1a4db8 vadd.f32 s15, s13, s15 */
/* @0x1a4dbc vstr s14, [sp, #8] */
/* @0x1a4dc0 vmov r0, s14 */
/* @0x1a4dc4 vmov r1, s15 */
/* @0x1a4dc8 vstr s15, [sp, #12] */
/* @0x1a4dcc bl 0x1a2920 <_Z19Vector_To_DirectionffPfS_> */
/* @0x1a4dd0 vldr s12, [r4, #36] */
/* @0x1a4dd4 vldr s15, [r4, #32] */
/* @0x1a4dd8 b 0x1a4c10 <_Z12HandleMotioni+0x6c> */
/* @0x1a4ddc add sp, sp, #28 */
/* @0x1a4de0 vpop {d8, d9} */
/* @0x1a4de4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a4de8 andeq r0, r0, r0 */
/* @0x1a4dec eoreq r11, r4, r8, lsl #24 */
/* @0x1a4df0 .word 0x0024bbb8 */

/* ── FUNC 0x1a4df4 · HandleShape(int) · size=292 · insn=73 */
/* @0x1a4df4 ldr r3, [pc, #0x114] */
/* @0x1a4df8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a4dfc vpush {d8, d9} */
/* @0x1a4e00 ldr r3, [pc, r3] */
/* @0x1a4e04 ldr r3, [r3, #0x4] */
/* @0x1a4e08 ldr r7, [r3, r0, lsl #2] */
/* @0x1a4e0c ldr r3, [r7, #0x8] */
/* @0x1a4e10 cmp r3, #0 */
/* @0x1a4e14 ble 0x1a4f04 <_Z11HandleShapei+0x110> */
/* @0x1a4e18 ldr r8, [pc, #0xf4] */
/* @0x1a4e1c vmov.f32 s16, #1.000000e+00 */
/* @0x1a4e20 mov r6, #0 */
/* @0x1a4e24 vldr s17, [pc, #224] */
/* @0x1a4e28 ldr r8, [pc, r8] */
/* @0x1a4e2c vmov.f32 s18, #2.000000e+00 */
/* @0x1a4e30 b 0x1a4e84 <_Z11HandleShapei+0x90> */
/* @0x1a4e34 vmov s15, r3 */
/* @0x1a4e38 vcvt.f32.s32 s13, s15 */
/* @0x1a4e3c vldr s15, [r4, #8] */
/* @0x1a4e40 vcvt.f32.s32 s14, s15 */
/* @0x1a4e44 vadd.f32 s14, s14, s14 */
/* @0x1a4e48 vdiv.f32 s15, s14, s13 */
/* @0x1a4e4c vcmpe.f32 s15, s16 */
/* @0x1a4e50 vmrs APSR_nzcv, fpscr */
/* @0x1a4e54 bmi 0x1a4edc <_Z11HandleShapei+0xe8> */
/* @0x1a4e58 vsub.f32 s12, s18, s15 */
/* @0x1a4e5c vsub.f32 s15, s15, s16 */
/* @0x1a4e60 vldr s13, [r5, #156] */
/* @0x1a4e64 vldr s14, [r5, #152] */
/* @0x1a4e68 ldr r3, [r7, #0x8] */
/* @0x1a4e6c vmul.f32 s15, s15, s13 */
/* @0x1a4e70 vmla.f32 s15, s12, s14 */
/* @0x1a4e74 vstr s15, [r4, #48] */
/* @0x1a4e78 add r6, r6, #1 */
/* @0x1a4e7c cmp r3, r6 */
/* @0x1a4e80 ble 0x1a4f04 <_Z11HandleShapei+0x110> */
/* @0x1a4e84 ldr r1, [r7, #0x4] */
/* @0x1a4e88 ldr r2, [r8, #0x4] */
/* @0x1a4e8c ldr r4, [r1, r6, lsl #2] */
/* @0x1a4e90 ldr r1, [r4, #0x4] */
/* @0x1a4e94 mov r0, r4 */
/* @0x1a4e98 ldr r5, [r2, r1, lsl #2] */
/* @0x1a4e9c cmp r5, #0 */
/* @0x1a4ea0 beq 0x1a4e78 <_Z11HandleShapei+0x84> */
/* @0x1a4ea4 vldr s14, [r4, #52] */
/* @0x1a4ea8 vldr s15, [r5, #20] */
/* @0x1a4eac vadd.f32 s15, s14, s15 */
/* @0x1a4eb0 vcmpe.f32 s15, #0 */
/* @0x1a4eb4 vmrs APSR_nzcv, fpscr */
/* @0x1a4eb8 vmovmi.f32 s15, s17 */
/* @0x1a4ebc vstr s15, [r4, #52] */
/* @0x1a4ec0 bl 0x1a2a98 <_Z13Compute_ColorR9RParticle> */
/* @0x1a4ec4 ldr r3, [r4, #0xc] */
/* @0x1a4ec8 cmp r3, #0 */
/* @0x1a4ecc bgt 0x1a4e34 <_Z11HandleShapei+0x40> */
/* @0x1a4ed0 vmov.f32 s12, #1.000000e+00 */
/* @0x1a4ed4 vldr s15, [pc, #48] */
/* @0x1a4ed8 b 0x1a4e60 <_Z11HandleShapei+0x6c> */
/* @0x1a4edc vldr s14, [r5, #152] */
/* @0x1a4ee0 vmul.f32 s14, s15, s14 */
/* @0x1a4ee4 vldr s13, [r5, #148] */
/* @0x1a4ee8 ldr r3, [r7, #0x8] */
/* @0x1a4eec add r6, r6, #1 */
/* @0x1a4ef0 cmp r3, r6 */
/* @0x1a4ef4 vsub.f32 s15, s16, s15 */
/* @0x1a4ef8 vmla.f32 s14, s15, s13 */
/* @0x1a4efc vstr s14, [r4, #48] */
/* @0x1a4f00 bgt 0x1a4e84 <_Z11HandleShapei+0x90> */
/* @0x1a4f04 vpop {d8, d9} */
/* @0x1a4f08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a4f0c andeq r0, r0, r0 */
/* @0x1a4f10 .word 0x0024b9b8 */
/* @0x1a4f14 eoreq r11, r4, r4, lsl #19 */

/* ── FUNC 0x1a4f18 · ParticleSystem_Update(int) · size=164 · insn=41 */
/* @0x1a4f18 push {r4, r5, r6, lr} */
/* @0x1a4f1c mov r6, r0 */
/* @0x1a4f20 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a4f24 cmp r0, #0 */
/* @0x1a4f28 popeq {r4, r5, r6, pc} */
/* @0x1a4f2c mov r0, r6 */
/* @0x1a4f30 bl 0x1a4938 <_Z10HandleLifei> */
/* @0x1a4f34 mov r0, r6 */
/* @0x1a4f38 bl 0x1a4ba4 <_Z12HandleMotioni> */
/* @0x1a4f3c mov r0, r6 */
/* @0x1a4f40 bl 0x1a4df4 <_Z11HandleShapei> */
/* @0x1a4f44 ldr r3, [pc, #0x6c] */
/* @0x1a4f48 ldr r3, [pc, r3] */
/* @0x1a4f4c ldr r3, [r3, #0x4] */
/* @0x1a4f50 ldr r5, [r3, r6, lsl #2] */
/* @0x1a4f54 ldr r1, [r5, #0x14] */
/* @0x1a4f58 cmp r1, #0 */
/* @0x1a4f5c pople {r4, r5, r6, pc} */
/* @0x1a4f60 mov r4, #0 */
/* @0x1a4f64 b 0x1a4f74 <_Z21ParticleSystem_Updatei+0x5c> */
/* @0x1a4f68 add r4, r4, #1 */
/* @0x1a4f6c cmp r1, r4 */
/* @0x1a4f70 ble 0x1a4fb4 <_Z21ParticleSystem_Updatei+0x9c> */
/* @0x1a4f74 ldr r3, [r5, #0x10] */
/* @0x1a4f78 ldr r2, [r3, r4, lsl #2] */
/* @0x1a4f7c ldrb r3, [r2] */
/* @0x1a4f80 cmp r3, #0 */
/* @0x1a4f84 beq 0x1a4f68 <_Z21ParticleSystem_Updatei+0x50> */
/* @0x1a4f88 ldr r3, [r2, #0x4] */
/* @0x1a4f8c cmp r3, #0 */
/* @0x1a4f90 beq 0x1a4f68 <_Z21ParticleSystem_Updatei+0x50> */
/* @0x1a4f94 mov r1, r4 */
/* @0x1a4f98 ldr r2, [r2, #0x20] */
/* @0x1a4f9c mov r0, r6 */
/* @0x1a4fa0 add r4, r4, #1 */
/* @0x1a4fa4 bl 0x1a3cf0 <_Z28ParticleSystem_Emitter_Burstiiii> */
/* @0x1a4fa8 ldr r1, [r5, #0x14] */
/* @0x1a4fac cmp r1, r4 */
/* @0x1a4fb0 bgt 0x1a4f74 <_Z21ParticleSystem_Updatei+0x5c> */
/* @0x1a4fb4 pop {r4, r5, r6, pc} */
/* @0x1a4fb8 eoreq r11, r4, r0, ror r8 */

/* ── FUNC 0x1a4fbc · ParticleSystem_UpdateAll() · size=216 · insn=54 */
/* @0x1a4fbc push {r3, r4, r5, r6, r7, lr} */
/* @0x1a4fc0 ldr r6, [pc, #0xb8] */
/* @0x1a4fc4 ldr r3, [pc, #0xb8] */
/* @0x1a4fc8 add r6, pc, r6 */
/* @0x1a4fcc ldr r7, [r6, r3] */
/* @0x1a4fd0 ldrb r3, [r7] */
/* @0x1a4fd4 cmp r3, #0 */
/* @0x1a4fd8 bne 0x1a5068 <_Z24ParticleSystem_UpdateAllv+0xac> */
/* @0x1a4fdc ldr r3, [pc, #0xa4] */
/* @0x1a4fe0 ldr r5, [r6, r3] */
/* @0x1a4fe4 ldr r3, [r5] */
/* @0x1a4fe8 cmp r3, #0 */
/* @0x1a4fec movgt r4, #0 */
/* @0x1a4ff0 bgt 0x1a5008 <_Z24ParticleSystem_UpdateAllv+0x4c> */
/* @0x1a4ff4 b 0x1a504c <_Z24ParticleSystem_UpdateAllv+0x90> */
/* @0x1a4ff8 ldr r3, [r5] */
/* @0x1a4ffc add r4, r4, #1 */
/* @0x1a5000 cmp r3, r4 */
/* @0x1a5004 ble 0x1a504c <_Z24ParticleSystem_UpdateAllv+0x90> */
/* @0x1a5008 mov r0, r4 */
/* @0x1a500c bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a5010 ldr r3, [pc, #0x74] */
/* @0x1a5014 cmp r0, #0 */
/* @0x1a5018 beq 0x1a4ff8 <_Z24ParticleSystem_UpdateAllv+0x3c> */
/* @0x1a501c ldr r3, [r6, r3] */
/* @0x1a5020 ldr r3, [r3, #0x4] */
/* @0x1a5024 ldr r3, [r3, r4, lsl #2] */
/* @0x1a5028 ldrb r3, [r3, #0x28] */
/* @0x1a502c cmp r3, #0 */
/* @0x1a5030 beq 0x1a4ff8 <_Z24ParticleSystem_UpdateAllv+0x3c> */
/* @0x1a5034 mov r0, r4 */
/* @0x1a5038 add r4, r4, #1 */
/* @0x1a503c bl 0x1a4f18 <_Z21ParticleSystem_Updatei> */
/* @0x1a5040 ldr r3, [r5] */
/* @0x1a5044 cmp r3, r4 */
/* @0x1a5048 bgt 0x1a5008 <_Z24ParticleSystem_UpdateAllv+0x4c> */
/* @0x1a504c ldrb r3, [r7] */
/* @0x1a5050 cmp r3, #0 */
/* @0x1a5054 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a5058 ldr r3, [pc, #0x30] */
/* @0x1a505c ldr r0, [r6, r3] */
/* @0x1a5060 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1a5064 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x1a5068 ldr r3, [pc, #0x20] */
/* @0x1a506c mov r1, #6 */
/* @0x1a5070 mov r2, #11 */
/* @0x1a5074 ldr r0, [r6, r3] */
/* @0x1a5078 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x1a507c b 0x1a4fdc <_Z24ParticleSystem_UpdateAllv+0x20> */
/* @0x1a5080 eoreq r12, r4, r8, lsl #25 */
/* @0x1a5084 .word 0xffffbf18 */
/* @0x1a5088 .word 0xffffeb64 */
/* @0x1a508c .word 0xffffeb68 */
/* @0x1a5090 .word 0xffffbf1c */

/* ── FUNC 0x1a5094 · DrawParticles(RParticleSystem*, int, int, int) · size=1560 · insn=390 */
/* @0x1a5094 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a5098 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a509c cmp r1, r2 */
/* @0x1a50a0 vldr s19, [r0, #32] */
/* @0x1a50a4 sub sp, sp, #60 */
/* @0x1a50a8 ldr r11, [pc, #0x43c] */
/* @0x1a50ac mov r10, r0 */
/* @0x1a50b0 vldr s20, [r0, #36] */
/* @0x1a50b4 str r2, [sp, #0x28] */
/* @0x1a50b8 add r11, pc, r11 */
/* @0x1a50bc str r3, [sp, #0x24] */
/* @0x1a50c0 beq 0x1a5470 <_Z13DrawParticlesP15RParticleSystemiii+0x3dc> */
/* @0x1a50c4 ldr r3, [r0, #0x4] */
/* @0x1a50c8 ldr r4, [r3, r1, lsl #2] */
/* @0x1a50cc ldr r3, [r4, #0xc] */
/* @0x1a50d0 cmp r3, #0 */
/* @0x1a50d4 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac> */
/* @0x1a50d8 ldr r2, [sp, #0x24] */
/* @0x1a50dc vldr s23, [pc, #1008] */
/* @0x1a50e0 ldr r3, [pc, #0x408] */
/* @0x1a50e4 vldr s22, [pc, #1004] */
/* @0x1a50e8 add r6, r1, r2 */
/* @0x1a50ec vldr s25, [pc, #1000] */
/* @0x1a50f0 lsl r1, r2, #2 */
/* @0x1a50f4 mov r2, #0 */
/* @0x1a50f8 str r1, [sp, #0x2c] */
/* @0x1a50fc lsl r7, r6, #2 */
/* @0x1a5100 str r2, [sp, #0x30] */
/* @0x1a5104 vldr s24, [pc, #980] */
/* @0x1a5108 ldr r9, [r11, r3] */
/* @0x1a510c vldr s18, [pc, #976] */
/* @0x1a5110 vldr s21, [pc, #976] */
/* @0x1a5114 b 0x1a51bc <_Z13DrawParticlesP15RParticleSystemiii+0x128> */
/* @0x1a5118 cmp r1, #0 */
/* @0x1a511c bne 0x1a55e8 <_Z13DrawParticlesP15RParticleSystemiii+0x554> */
/* @0x1a5120 cmp r8, #0 */
/* @0x1a5124 beq 0x1a52fc <_Z13DrawParticlesP15RParticleSystemiii+0x268> */
/* @0x1a5128 vldr s14, [r4, #20] */
/* @0x1a512c vadd.f32 s14, s20, s14 */
/* @0x1a5130 ldr r2, [r4, #0x4] */
/* @0x1a5134 vldr s15, [r4, #16] */
/* @0x1a5138 ldr r3, [r9, #0x4] */
/* @0x1a513c mov r1, #1107296256 */
/* @0x1a5140 ldr r0, [r8, #0x4] */
/* @0x1a5144 ldr r3, [r3, r2, lsl #2] */
/* @0x1a5148 mov r2, r1 */
/* @0x1a514c vstr s14, [sp] */
/* @0x1a5150 vldr s14, [r3, #28] */
/* @0x1a5154 vmul.f32 s14, s16, s14 */
/* @0x1a5158 vmul.f32 s17, s17, s21 */
/* @0x1a515c vstr s14, [sp, #4] */
/* @0x1a5160 vldr s14, [r3, #32] */
/* @0x1a5164 vmul.f32 s16, s16, s14 */
/* @0x1a5168 vstr s17, [sp, #12] */
/* @0x1a516c vadd.f32 s15, s19, s15 */
/* @0x1a5170 vstr s16, [sp, #8] */
/* @0x1a5174 ldr r12, [r4, #0x2c] */
/* @0x1a5178 str r12, [sp, #0x10] */
/* @0x1a517c ldr r12, [r4, #0x30] */
/* @0x1a5180 str r12, [sp, #0x14] */
/* @0x1a5184 vmov r3, s15 */
/* @0x1a5188 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0x1a518c ldr r2, [sp, #0x28] */
/* @0x1a5190 cmp r2, r6 */
/* @0x1a5194 beq 0x1a5470 <_Z13DrawParticlesP15RParticleSystemiii+0x3dc> */
/* @0x1a5198 ldr r3, [r10, #0x4] */
/* @0x1a519c ldr r1, [sp, #0x24] */
/* @0x1a51a0 ldr r2, [sp, #0x2c] */
/* @0x1a51a4 ldr r4, [r3, r7] */
/* @0x1a51a8 add r6, r6, r1 */
/* @0x1a51ac add r7, r7, r2 */
/* @0x1a51b0 ldr r3, [r4, #0xc] */
/* @0x1a51b4 cmp r3, #0 */
/* @0x1a51b8 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac> */
/* @0x1a51bc ldr r2, [r4, #0x4] */
/* @0x1a51c0 ldr r3, [r9, #0x4] */
/* @0x1a51c4 ldr r3, [r3, r2, lsl #2] */
/* @0x1a51c8 cmp r3, #0 */
/* @0x1a51cc beq 0x1a518c <_Z13DrawParticlesP15RParticleSystemiii+0xf8> */
/* @0x1a51d0 ldr r0, [r3] */
/* @0x1a51d4 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1a51d8 cmp r0, #0 */
/* @0x1a51dc bne 0x1a5484 <_Z13DrawParticlesP15RParticleSystemiii+0x3f0> */
/* @0x1a51e0 ldr r3, [r9, #0x4] */
/* @0x1a51e4 ldr r1, [r4, #0x4] */
/* @0x1a51e8 ldr r5, [r3, r1, lsl #2] */
/* @0x1a51ec ldr r3, [r5, #0x8] */
/* @0x1a51f0 cmp r3, #13 */
/* @0x1a51f4 bhi 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac> */
/* @0x1a51f8 ldr r1, [pc, #0x2f4] */
/* @0x1a51fc ldr r1, [r11, r1] */
/* @0x1a5200 ldr r8, [r1, r3, lsl #2] */
/* @0x1a5204 cmp r8, #0 */
/* @0x1a5208 beq 0x1a561c <_Z13DrawParticlesP15RParticleSystemiii+0x588> */
/* @0x1a520c ldr r3, [r4, #0x8] */
/* @0x1a5210 mov r2, r0 */
/* @0x1a5214 mov r12, r0 */
/* @0x1a5218 ldr r1, [r4, #0x3c] */
/* @0x1a521c vmov.f32 s14, #2.000000e+00 */
/* @0x1a5220 vldr s13, [r5, #112] */
/* @0x1a5224 vldr s16, [r4, #52] */
/* @0x1a5228 add r3, r3, r1, lsl #1 */
/* @0x1a522c asr r0, r3, #31 */
/* @0x1a5230 lsr r0, r0, #28 */
/* @0x1a5234 add lr, r3, r0 */
/* @0x1a5238 rsb r3, r1, r3 */
/* @0x1a523c and lr, lr, #15 */
/* @0x1a5240 ldr r1, [sp, #0x30] */
/* @0x1a5244 rsb lr, r0, lr */
/* @0x1a5248 vmov.f32 s12, #1.000000e+00 */
/* @0x1a524c ldrb r0, [r5, #0x74] */
/* @0x1a5250 vmov s15, lr */
/* @0x1a5254 vcvt.f32.s32 s15, s15, #2 */
/* @0x1a5258 vcmpe.f32 s15, s14 */
/* @0x1a525c vmrs APSR_nzcv, fpscr */
/* @0x1a5260 vmovgt.f32 s14, #4.000000e+00 */
/* @0x1a5264 vsubgt.f32 s15, s14, s15 */
/* @0x1a5268 cmp r0, #0 */
/* @0x1a526c asr r0, r3, #31 */
/* @0x1a5270 vldr s14, [r4, #40] */
/* @0x1a5274 lsr r0, r0, #28 */
/* @0x1a5278 add r3, r3, r0 */
/* @0x1a527c and r3, r3, #15 */
/* @0x1a5280 rsb r3, r0, r3 */
/* @0x1a5284 vmov.f32 s11, #2.000000e+00 */
/* @0x1a5288 vsub.f32 s12, s15, s12 */
/* @0x1a528c vldrne s15, [r4, #36] */
/* @0x1a5290 vaddne.f32 s14, s14, s15 */
/* @0x1a5294 vmov s15, r3 */
/* @0x1a5298 ldrb r3, [r5, #0xa0] */
/* @0x1a529c vcvt.f32.s32 s15, s15, #2 */
/* @0x1a52a0 vcmpe.f32 s15, s11 */
/* @0x1a52a4 vmov.f32 s17, s14 */
/* @0x1a52a8 vmrs APSR_nzcv, fpscr */
/* @0x1a52ac vmovgt.f32 s14, #4.000000e+00 */
/* @0x1a52b0 vmla.f32 s17, s12, s13 */
/* @0x1a52b4 vsubgt.f32 s15, s14, s15 */
/* @0x1a52b8 cmp r3, #0 */
/* @0x1a52bc vldr s14, [r5, #24] */
/* @0x1a52c0 vmov.f32 s13, #1.000000e+00 */
/* @0x1a52c4 vsub.f32 s15, s15, s13 */
/* @0x1a52c8 vmla.f32 s16, s15, s14 */
/* @0x1a52cc beq 0x1a5118 <_Z13DrawParticlesP15RParticleSystemiii+0x84> */
/* @0x1a52d0 cmp r1, #0 */
/* @0x1a52d4 bne 0x1a5120 <_Z13DrawParticlesP15RParticleSystemiii+0x8c> */
/* @0x1a52d8 mov r0, #1 */
/* @0x1a52dc str r2, [sp, #0x1c] */
/* @0x1a52e0 str r12, [sp, #0x18] */
/* @0x1a52e4 str r0, [sp, #0x30] */
/* @0x1a52e8 bl 0x168360 <_Z16GR_D3D_Set_Blendi> */
/* @0x1a52ec cmp r8, #0 */
/* @0x1a52f0 ldr r2, [sp, #0x1c] */
/* @0x1a52f4 ldr r12, [sp, #0x18] */
/* @0x1a52f8 bne 0x1a5128 <_Z13DrawParticlesP15RParticleSystemiii+0x94> */
/* @0x1a52fc cmp r2, #0 */
/* @0x1a5300 beq 0x1a564c <_Z13DrawParticlesP15RParticleSystemiii+0x5b8> */
/* @0x1a5304 mov r1, r2 */
/* @0x1a5308 mov r3, #6 */
/* @0x1a530c mov r2, #24 */
/* @0x1a5310 mov r0, #4 */
/* @0x1a5314 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1a5318 ldr r2, [r4, #0x4] */
/* @0x1a531c ldr r3, [r9, #0x4] */
/* @0x1a5320 vldr s31, [r4, #16] */
/* @0x1a5324 vldr s30, [r4, #20] */
/* @0x1a5328 vadd.f32 s31, s19, s31 */
/* @0x1a532c ldr r3, [r3, r2, lsl #2] */
/* @0x1a5330 vldr s14, [r3, #32] */
/* @0x1a5334 vldr s15, [r3, #28] */
/* @0x1a5338 vmul.f32 s15, s16, s15 */
/* @0x1a533c vmul.f32 s16, s16, s14 */
/* @0x1a5340 mov r5, r0 */
/* @0x1a5344 vnmul.f32 s27, s15, s23 */
/* @0x1a5348 vnmul.f32 s26, s16, s23 */
/* @0x1a534c vadd.f32 s30, s20, s30 */
/* @0x1a5350 vabs.f32 s14, s17 */
/* @0x1a5354 vmov.f32 s29, s27 */
/* @0x1a5358 vcmpe.f32 s14, s25 */
/* @0x1a535c vmov.f32 s28, s26 */
/* @0x1a5360 vmrs APSR_nzcv, fpscr */
/* @0x1a5364 vmla.f32 s29, s15, s22 */
/* @0x1a5368 vmla.f32 s28, s16, s22 */
/* @0x1a536c vcvt.s32.f32 s31, s31 */
/* @0x1a5370 vcvt.s32.f32 s30, s30 */
/* @0x1a5374 bpl 0x1a5548 <_Z13DrawParticlesP15RParticleSystemiii+0x4b4> */
/* @0x1a5378 vcvt.f32.s32 s31, s31 */
/* @0x1a537c vcvt.f32.s32 s30, s30 */
/* @0x1a5380 vadd.f32 s27, s31, s27 */
/* @0x1a5384 vadd.f32 s29, s29, s31 */
/* @0x1a5388 vstr s27, [r0, #120] */
/* @0x1a538c vstr s27, [r0, #96] */
/* @0x1a5390 vstr s27, [r0] */
/* @0x1a5394 vadd.f32 s26, s30, s26 */
/* @0x1a5398 vstr s29, [r0, #72] */
/* @0x1a539c vstr s29, [r0, #48] */
/* @0x1a53a0 vstr s29, [r0, #24] */
/* @0x1a53a4 vadd.f32 s28, s28, s30 */
/* @0x1a53a8 vstr s26, [r0, #124] */
/* @0x1a53ac vstr s26, [r0, #28] */
/* @0x1a53b0 vstr s26, [r0, #4] */
/* @0x1a53b4 vstr s28, [r0, #100] */
/* @0x1a53b8 vstr s28, [r0, #52] */
/* @0x1a53bc vstr s28, [r0, #76] */
/* @0x1a53c0 vldr s15, [r4, #48] */
/* @0x1a53c4 vmul.f32 s15, s15, s24 */
/* @0x1a53c8 ldr r3, [pc, #0x128] */
/* @0x1a53cc ldr r1, [r4, #0x2c] */
/* @0x1a53d0 ldr r3, [r11, r3] */
/* @0x1a53d4 ldr r2, [r3] */
/* @0x1a53d8 str r2, [r5, #0x80] */
/* @0x1a53dc str r2, [r5, #0x68] */
/* @0x1a53e0 vcvt.s32.f32 s15, s15 */
/* @0x1a53e4 str r2, [r5, #0x50] */
/* @0x1a53e8 str r2, [r5, #0x38] */
/* @0x1a53ec str r2, [r5, #0x20] */
/* @0x1a53f0 str r2, [r5, #0x8] */
/* @0x1a53f4 vmov r3, s15 */
/* @0x1a53f8 cmp r3, #255 */
/* @0x1a53fc movgt r3, #-16777216 */
/* @0x1a5400 bgt 0x1a5410 <_Z13DrawParticlesP15RParticleSystemiii+0x37c> */
/* @0x1a5404 cmp r3, #0 */
/* @0x1a5408 lslge r3, r3, #24 */
/* @0x1a540c movlt r3, #0 */
/* @0x1a5410 mov r2, #1065353216 */
/* @0x1a5414 str r2, [r5, #0x74] */
/* @0x1a5418 str r2, [r5, #0x5c] */
/* @0x1a541c bic r1, r1, #-16777216 */
/* @0x1a5420 str r2, [r5, #0x58] */
/* @0x1a5424 orr r3, r3, r1 */
/* @0x1a5428 str r2, [r5, #0x44] */
/* @0x1a542c vstr s18, [r5, #140] */
/* @0x1a5430 str r2, [r5, #0x40] */
/* @0x1a5434 vstr s18, [r5, #136] */
/* @0x1a5438 str r2, [r5, #0x28] */
/* @0x1a543c vstr s18, [r5, #112] */
/* @0x1a5440 ldr r2, [sp, #0x28] */
/* @0x1a5444 vstr s18, [r5, #44] */
/* @0x1a5448 str r3, [r5, #0x84] */
/* @0x1a544c vstr s18, [r5, #20] */
/* @0x1a5450 cmp r2, r6 */
/* @0x1a5454 str r3, [r5, #0x6c] */
/* @0x1a5458 str r3, [r5, #0x54] */
/* @0x1a545c vstr s18, [r5, #16] */
/* @0x1a5460 str r3, [r5, #0x3c] */
/* @0x1a5464 str r3, [r5, #0x24] */
/* @0x1a5468 str r3, [r5, #0xc] */
/* @0x1a546c bne 0x1a5198 <_Z13DrawParticlesP15RParticleSystemiii+0x104> */
/* @0x1a5470 mov r0, #0 */
/* @0x1a5474 add sp, sp, #60 */
/* @0x1a5478 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a547c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a5480 b 0x168360 <_Z16GR_D3D_Set_Blendi> */
/* @0x1a5484 ldr r2, [r4, #0x4] */
/* @0x1a5488 ldr r3, [r9, #0x4] */
/* @0x1a548c ldr r3, [r3, r2, lsl #2] */
/* @0x1a5490 ldr r0, [r3] */
/* @0x1a5494 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1a5498 mov r12, r0 */
/* @0x1a549c ldr r0, [r12, #0x18] */
/* @0x1a54a0 cmp r0, #0 */
/* @0x1a54a4 ble 0x1a5640 <_Z13DrawParticlesP15RParticleSystemiii+0x5ac> */
/* @0x1a54a8 ldr r2, [r4, #0x4] */
/* @0x1a54ac ldr r3, [r9, #0x4] */
/* @0x1a54b0 ldr r5, [r3, r2, lsl #2] */
/* @0x1a54b4 ldrb r8, [r5, #0x4] */
/* @0x1a54b8 cmp r8, #0 */
/* @0x1a54bc bne 0x1a5500 <_Z13DrawParticlesP15RParticleSystemiii+0x46c> */
/* @0x1a54c0 ldr r3, [r4, #0x38] */
/* @0x1a54c4 mov r2, r8 */
/* @0x1a54c8 str r3, [sp, #0x34] */
/* @0x1a54cc ldr r3, [r4, #0x8] */
/* @0x1a54d0 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184> */
/* @0x1a54d4 andmi r0, r0, #0 */
/* @0x1a54d8 addmi r0, r0, #0 */
/* @0x1a54dc ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ */
/* @0x1a54e0 cmnmi pc, #0 */
/* @0x1a54e4 andeq r0, r0, r0 */
/* @0x1a54e8 vstmialo lr, {s30, s31} */
/* @0x1a54ec mlaeq r4, r8, r11, r12 */
/* @0x1a54f0 .word 0xffffeb5c */
/* @0x1a54f4 .word 0xffffeb6c */
/* @0x1a54f8 .word 0xffffbcd0 */
/* @0x1a54fc .word 0xffffeb70 */
/* @0x1a5500 ldrb r8, [r5, #0x5] */
/* @0x1a5504 ldr r3, [r4, #0x8] */
/* @0x1a5508 cmp r8, #0 */
/* @0x1a550c beq 0x1a5608 <_Z13DrawParticlesP15RParticleSystemiii+0x574> */
/* @0x1a5510 ldr r1, [r4, #0xc] */
/* @0x1a5514 mov r8, #0 */
/* @0x1a5518 mul r0, r3, r0 */
/* @0x1a551c str r3, [sp, #0x20] */
/* @0x1a5520 str r12, [sp, #0x18] */
/* @0x1a5524 str r8, [sp, #0x1c] */
/* @0x1a5528 bl 0x318d10 <__divsi3> */
/* @0x1a552c ldr r1, [r4, #0x38] */
/* @0x1a5530 ldr r2, [sp, #0x1c] */
/* @0x1a5534 ldr r3, [sp, #0x20] */
/* @0x1a5538 ldr r12, [sp, #0x18] */
/* @0x1a553c add r1, r0, r1 */
/* @0x1a5540 str r1, [sp, #0x34] */
/* @0x1a5544 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184> */
/* @0x1a5548 vmul.f32 s17, s17, s21 */
/* @0x1a554c vmov r0, s17 */
/* @0x1a5550 bl 0xb6580 <sinf@plt> */
/* @0x1a5554 vcvt.f32.s32 s31, s31 */
/* @0x1a5558 vcvt.f32.s32 s30, s30 */
/* @0x1a555c vmov s16, r0 */
/* @0x1a5560 vmov r0, s17 */
/* @0x1a5564 bl 0xb658c <cosf@plt> */
/* @0x1a5568 vmov.f32 s13, s31 */
/* @0x1a556c vmov.f32 s14, s30 */
/* @0x1a5570 vmls.f32 s30, s29, s16 */
/* @0x1a5574 vmls.f32 s14, s27, s16 */
/* @0x1a5578 vmov s15, r0 */
/* @0x1a557c vmla.f32 s13, s27, s15 */
/* @0x1a5580 vmla.f32 s31, s29, s15 */
/* @0x1a5584 vmul.f32 s11, s26, s16 */
/* @0x1a5588 vmul.f32 s26, s26, s15 */
/* @0x1a558c vmul.f32 s16, s28, s16 */
/* @0x1a5590 vmul.f32 s15, s28, s15 */
/* @0x1a5594 vadd.f32 s12, s13, s11 */
/* @0x1a5598 vadd.f32 s11, s31, s11 */
/* @0x1a559c vstr s12, [r5, #120] */
/* @0x1a55a0 vstr s12, [r5] */
/* @0x1a55a4 vadd.f32 s31, s16, s31 */
/* @0x1a55a8 vstr s11, [r5, #24] */
/* @0x1a55ac vadd.f32 s16, s16, s13 */
/* @0x1a55b0 vstr s31, [r5, #72] */
/* @0x1a55b4 vstr s31, [r5, #48] */
/* @0x1a55b8 vadd.f32 s13, s14, s26 */
/* @0x1a55bc vstr s16, [r5, #96] */
/* @0x1a55c0 vadd.f32 s26, s30, s26 */
/* @0x1a55c4 vstr s13, [r5, #4] */
/* @0x1a55c8 vstr s13, [r5, #124] */
/* @0x1a55cc vadd.f32 s30, s15, s30 */
/* @0x1a55d0 vstr s26, [r5, #28] */
/* @0x1a55d4 vadd.f32 s15, s15, s14 */
/* @0x1a55d8 vstr s30, [r5, #76] */
/* @0x1a55dc vstr s30, [r5, #52] */
/* @0x1a55e0 vstr s15, [r5, #100] */
/* @0x1a55e4 b 0x1a53c0 <_Z13DrawParticlesP15RParticleSystemiii+0x32c> */
/* @0x1a55e8 mov r0, r3 */
/* @0x1a55ec str r2, [sp, #0x1c] */
/* @0x1a55f0 str r12, [sp, #0x18] */
/* @0x1a55f4 str r3, [sp, #0x30] */
/* @0x1a55f8 bl 0x168360 <_Z16GR_D3D_Set_Blendi> */
/* @0x1a55fc ldr r12, [sp, #0x18] */
/* @0x1a5600 ldr r2, [sp, #0x1c] */
/* @0x1a5604 b 0x1a5120 <_Z13DrawParticlesP15RParticleSystemiii+0x8c> */
/* @0x1a5608 ldr r1, [r4, #0x38] */
/* @0x1a560c mov r2, r8 */
/* @0x1a5610 add r1, r3, r1 */
/* @0x1a5614 str r1, [sp, #0x34] */
/* @0x1a5618 b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184> */
/* @0x1a561c ldr r2, [pc, #-0x128] */
/* @0x1a5620 ldr r2, [r11, r2] */
/* @0x1a5624 ldr r2, [r2, r3, lsl #2] */
/* @0x1a5628 cmp r2, #0 */
/* @0x1a562c moveq r12, r2 */
/* @0x1a5630 beq 0x1a549c <_Z13DrawParticlesP15RParticleSystemiii+0x408> */
/* @0x1a5634 ldr r3, [r4, #0x8] */
/* @0x1a5638 mov r12, r8 */
/* @0x1a563c b 0x1a5218 <_Z13DrawParticlesP15RParticleSystemiii+0x184> */
/* @0x1a5640 add sp, sp, #60 */
/* @0x1a5644 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a5648 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a564c vldr s14, [r4, #16] */
/* @0x1a5650 vadd.f32 s14, s19, s14 */
/* @0x1a5654 ldr r1, [r4, #0x4] */
/* @0x1a5658 vldr s15, [r4, #20] */
/* @0x1a565c ldr r3, [r9, #0x4] */
/* @0x1a5660 mov r0, r12 */
/* @0x1a5664 ldr r3, [r3, r1, lsl #2] */
/* @0x1a5668 ldr r1, [sp, #0x34] */
/* @0x1a566c vmov r2, s14 */
/* @0x1a5670 vldr s14, [r3, #28] */
/* @0x1a5674 vmul.f32 s14, s16, s14 */
/* @0x1a5678 vstr s14, [sp] */
/* @0x1a567c vldr s14, [r3, #32] */
/* @0x1a5680 vmul.f32 s16, s16, s14 */
/* @0x1a5684 vstr s17, [sp, #8] */
/* @0x1a5688 vadd.f32 s15, s20, s15 */
/* @0x1a568c vstr s16, [sp, #4] */
/* @0x1a5690 ldr r12, [r4, #0x2c] */
/* @0x1a5694 str r12, [sp, #0xc] */
/* @0x1a5698 ldr r12, [r4, #0x30] */
/* @0x1a569c str r12, [sp, #0x10] */
/* @0x1a56a0 vmov r3, s15 */
/* @0x1a56a4 bl 0x1ec720 <_ZN7CSprite4DrawEifffffjf> */
/* @0x1a56a8 b 0x1a518c <_Z13DrawParticlesP15RParticleSystemiii+0xf8> */

/* ── FUNC 0x1a56ac · ParticleSystem_Draw(int) · size=96 · insn=24 */
/* @0x1a56ac push {r4, lr} */
/* @0x1a56b0 mov r4, r0 */
/* @0x1a56b4 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a56b8 cmp r0, #0 */
/* @0x1a56bc popeq {r4, pc} */
/* @0x1a56c0 ldr r3, [pc, #0x40] */
/* @0x1a56c4 ldr r3, [pc, r3] */
/* @0x1a56c8 ldr r3, [r3, #0x4] */
/* @0x1a56cc ldr r0, [r3, r4, lsl #2] */
/* @0x1a56d0 ldrb r3, [r0, #0x18] */
/* @0x1a56d4 cmp r3, #0 */
/* @0x1a56d8 bne 0x1a56f4 <_Z19ParticleSystem_Drawi+0x48> */
/* @0x1a56dc ldr r1, [r0, #0x8] */
/* @0x1a56e0 mvn r2, #0 */
/* @0x1a56e4 mov r3, r2 */
/* @0x1a56e8 add r1, r1, r2 */
/* @0x1a56ec pop {r4, lr} */
/* @0x1a56f0 b 0x1a5094 <_Z13DrawParticlesP15RParticleSystemiii> */
/* @0x1a56f4 mov r1, #0 */
/* @0x1a56f8 ldr r2, [r0, #0x8] */
/* @0x1a56fc mov r3, #1 */
/* @0x1a5700 pop {r4, lr} */
/* @0x1a5704 b 0x1a5094 <_Z13DrawParticlesP15RParticleSystemiii> */
/* @0x1a5708 .word 0x0024b0f4 */

/* ── FUNC 0x1a570c · ParticleSystem_LargestDepth() · size=144 · insn=36 */
/* @0x1a570c push {r3, r4, r5, lr} */
/* @0x1a5710 vpush {d8} */
/* @0x1a5714 ldr r5, [pc, #0x78] */
/* @0x1a5718 ldr r5, [pc, r5] */
/* @0x1a571c ldr r3, [r5] */
/* @0x1a5720 cmp r3, #0 */
/* @0x1a5724 ble 0x1a5788 <_Z27ParticleSystem_LargestDepthv+0x7c> */
/* @0x1a5728 mov r4, #0 */
/* @0x1a572c vldr s16, [pc, #92] */
/* @0x1a5730 mov r0, r4 */
/* @0x1a5734 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a5738 ldr r3, [pc, #0x58] */
/* @0x1a573c cmp r0, #0 */
/* @0x1a5740 beq 0x1a576c <_Z27ParticleSystem_LargestDepthv+0x60> */
/* @0x1a5744 ldr r3, [pc, r3] */
/* @0x1a5748 ldr r3, [r3, #0x4] */
/* @0x1a574c ldr r3, [r3, r4, lsl #2] */
/* @0x1a5750 ldrb r2, [r3, #0x29] */
/* @0x1a5754 cmp r2, #0 */
/* @0x1a5758 beq 0x1a576c <_Z27ParticleSystem_LargestDepthv+0x60> */
/* @0x1a575c vldr s15, [r3, #28] */
/* @0x1a5760 vcmp.f32 s15, s16 */
/* @0x1a5764 vmrs APSR_nzcv, fpscr */
/* @0x1a5768 vmovgt.f32 s16, s15 */
/* @0x1a576c ldr r3, [r5] */
/* @0x1a5770 add r4, r4, #1 */
/* @0x1a5774 cmp r3, r4 */
/* @0x1a5778 bgt 0x1a5730 <_Z27ParticleSystem_LargestDepthv+0x24> */
/* @0x1a577c vmov r0, s16 */
/* @0x1a5780 vpop {d8} */
/* @0x1a5784 pop {r3, r4, r5, pc} */
/* @0x1a5788 vldr s16, [pc] */
/* @0x1a578c b 0x1a577c <_Z27ParticleSystem_LargestDepthv+0x70> */
/* @0x1a5790 vmulgt.f64 d22, d14, d24 */
/* @0x1a5794 mlaeq r4, r12, r0, r11 */
/* @0x1a5798 eoreq r11, r4, r4, ror r0 */

/* ── FUNC 0x1a579c · ParticleSystem_NextDepth(float) · size=160 · insn=40 */
/* @0x1a579c push {r3, r4, r5, lr} */
/* @0x1a57a0 vpush {d8} */
/* @0x1a57a4 vmov s17, r0 */
/* @0x1a57a8 ldr r5, [pc, #0x84] */
/* @0x1a57ac ldr r5, [pc, r5] */
/* @0x1a57b0 ldr r3, [r5] */
/* @0x1a57b4 cmp r3, #0 */
/* @0x1a57b8 ble 0x1a5828 <_Z24ParticleSystem_NextDepthf+0x8c> */
/* @0x1a57bc mov r4, #0 */
/* @0x1a57c0 vldr s16, [pc, #104] */
/* @0x1a57c4 mov r0, r4 */
/* @0x1a57c8 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a57cc ldr r3, [pc, #0x64] */
/* @0x1a57d0 cmp r0, #0 */
/* @0x1a57d4 beq 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70> */
/* @0x1a57d8 ldr r3, [pc, r3] */
/* @0x1a57dc ldr r3, [r3, #0x4] */
/* @0x1a57e0 ldr r3, [r3, r4, lsl #2] */
/* @0x1a57e4 ldrb r2, [r3, #0x29] */
/* @0x1a57e8 cmp r2, #0 */
/* @0x1a57ec beq 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70> */
/* @0x1a57f0 vldr s15, [r3, #28] */
/* @0x1a57f4 vcmpe.f32 s15, s16 */
/* @0x1a57f8 vmrs APSR_nzcv, fpscr */
/* @0x1a57fc ble 0x1a580c <_Z24ParticleSystem_NextDepthf+0x70> */
/* @0x1a5800 vcmp.f32 s15, s17 */
/* @0x1a5804 vmrs APSR_nzcv, fpscr */
/* @0x1a5808 vmovmi.f32 s16, s15 */
/* @0x1a580c ldr r3, [r5] */
/* @0x1a5810 add r4, r4, #1 */
/* @0x1a5814 cmp r3, r4 */
/* @0x1a5818 bgt 0x1a57c4 <_Z24ParticleSystem_NextDepthf+0x28> */
/* @0x1a581c vmov r0, s16 */
/* @0x1a5820 vpop {d8} */
/* @0x1a5824 pop {r3, r4, r5, pc} */
/* @0x1a5828 vldr s16, [pc] */
/* @0x1a582c b 0x1a581c <_Z24ParticleSystem_NextDepthf+0x80> */
/* @0x1a5830 vmulgt.f64 d22, d14, d24 */
/* @0x1a5834 eoreq r11, r4, r8 */
/* @0x1a5838 eoreq r10, r4, r0, ror #31 */

/* ── FUNC 0x1a583c · ParticleSystem_DrawDepth(float) · size=156 · insn=39 */
/* @0x1a583c push {r3, r4, r5, lr} */
/* @0x1a5840 vpush {d8} */
/* @0x1a5844 vmov s16, r0 */
/* @0x1a5848 ldr r5, [pc, #0x80] */
/* @0x1a584c ldr r5, [pc, r5] */
/* @0x1a5850 ldr r3, [r5] */
/* @0x1a5854 cmp r3, #0 */
/* @0x1a5858 ble 0x1a58b8 <_Z24ParticleSystem_DrawDepthf+0x7c> */
/* @0x1a585c mov r4, #0 */
/* @0x1a5860 vldr s17, [pc, #100] */
/* @0x1a5864 mov r0, r4 */
/* @0x1a5868 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a586c ldr r3, [pc, #0x60] */
/* @0x1a5870 cmp r0, #0 */
/* @0x1a5874 beq 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c> */
/* @0x1a5878 ldr r3, [pc, r3] */
/* @0x1a587c ldr r3, [r3, #0x4] */
/* @0x1a5880 ldr r3, [r3, r4, lsl #2] */
/* @0x1a5884 ldrb r2, [r3, #0x29] */
/* @0x1a5888 cmp r2, #0 */
/* @0x1a588c beq 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c> */
/* @0x1a5890 vldr s15, [r3, #28] */
/* @0x1a5894 vsub.f32 s15, s15, s16 */
/* @0x1a5898 vabs.f32 s15, s15 */
/* @0x1a589c vcmpe.f32 s15, s17 */
/* @0x1a58a0 vmrs APSR_nzcv, fpscr */
/* @0x1a58a4 bmi 0x1a58c0 <_Z24ParticleSystem_DrawDepthf+0x84> */
/* @0x1a58a8 ldr r3, [r5] */
/* @0x1a58ac add r4, r4, #1 */
/* @0x1a58b0 cmp r3, r4 */
/* @0x1a58b4 bgt 0x1a5864 <_Z24ParticleSystem_DrawDepthf+0x28> */
/* @0x1a58b8 vpop {d8} */
/* @0x1a58bc pop {r3, r4, r5, pc} */
/* @0x1a58c0 mov r0, r4 */
/* @0x1a58c4 bl 0x1a56ac <_Z19ParticleSystem_Drawi> */
/* @0x1a58c8 b 0x1a58a8 <_Z24ParticleSystem_DrawDepthf+0x6c> */
/* @0x1a58cc stclo p7, c13, [r3], #-40 */
/* @0x1a58d0 eoreq r10, r4, r8, ror #30 */
/* @0x1a58d4 eoreq r10, r4, r0, asr #30 */

/* ── FUNC 0x1a58d8 · Part_SetupEmbeddedImages() · size=356 · insn=89 */
/* @0x1a58d8 ldr r0, [pc, #0x120] */
/* @0x1a58dc mov r1, #1 */
/* @0x1a58e0 push {r4, lr} */
/* @0x1a58e4 add r0, pc, r0 */
/* @0x1a58e8 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a58ec ldr r4, [pc, #0x110] */
/* @0x1a58f0 mov r1, #1 */
/* @0x1a58f4 ldr r4, [pc, r4] */
/* @0x1a58f8 str r0, [r4] */
/* @0x1a58fc ldr r0, [pc, #0x104] */
/* @0x1a5900 add r0, pc, r0 */
/* @0x1a5904 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5908 mov r1, #1 */
/* @0x1a590c str r0, [r4, #0x4] */
/* @0x1a5910 ldr r0, [pc, #0xf4] */
/* @0x1a5914 add r0, pc, r0 */
/* @0x1a5918 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a591c mov r1, #1 */
/* @0x1a5920 str r0, [r4, #0x8] */
/* @0x1a5924 ldr r0, [pc, #0xe4] */
/* @0x1a5928 add r0, pc, r0 */
/* @0x1a592c bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5930 mov r1, #1 */
/* @0x1a5934 str r0, [r4, #0xc] */
/* @0x1a5938 ldr r0, [pc, #0xd4] */
/* @0x1a593c add r0, pc, r0 */
/* @0x1a5940 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5944 mov r1, #1 */
/* @0x1a5948 str r0, [r4, #0x10] */
/* @0x1a594c ldr r0, [pc, #0xc4] */
/* @0x1a5950 add r0, pc, r0 */
/* @0x1a5954 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5958 mov r1, #1 */
/* @0x1a595c str r0, [r4, #0x14] */
/* @0x1a5960 ldr r0, [pc, #0xb4] */
/* @0x1a5964 add r0, pc, r0 */
/* @0x1a5968 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a596c mov r1, #1 */
/* @0x1a5970 str r0, [r4, #0x18] */
/* @0x1a5974 ldr r0, [pc, #0xa4] */
/* @0x1a5978 add r0, pc, r0 */
/* @0x1a597c bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5980 mov r1, #1 */
/* @0x1a5984 str r0, [r4, #0x1c] */
/* @0x1a5988 ldr r0, [pc, #0x94] */
/* @0x1a598c add r0, pc, r0 */
/* @0x1a5990 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a5994 mov r1, #1 */
/* @0x1a5998 str r0, [r4, #0x20] */
/* @0x1a599c ldr r0, [pc, #0x84] */
/* @0x1a59a0 add r0, pc, r0 */
/* @0x1a59a4 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a59a8 mov r1, #1 */
/* @0x1a59ac str r0, [r4, #0x24] */
/* @0x1a59b0 ldr r0, [pc, #0x74] */
/* @0x1a59b4 add r0, pc, r0 */
/* @0x1a59b8 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a59bc mov r1, #1 */
/* @0x1a59c0 str r0, [r4, #0x28] */
/* @0x1a59c4 ldr r0, [pc, #0x64] */
/* @0x1a59c8 add r0, pc, r0 */
/* @0x1a59cc bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a59d0 mov r1, #1 */
/* @0x1a59d4 str r0, [r4, #0x2c] */
/* @0x1a59d8 ldr r0, [pc, #0x54] */
/* @0x1a59dc add r0, pc, r0 */
/* @0x1a59e0 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a59e4 mov r1, #1 */
/* @0x1a59e8 str r0, [r4, #0x30] */
/* @0x1a59ec ldr r0, [pc, #0x44] */
/* @0x1a59f0 add r0, pc, r0 */
/* @0x1a59f4 bl 0x1768f0 <_Z18EmbeddedImage_FindPcb> */
/* @0x1a59f8 str r0, [r4, #0x34] */
/* @0x1a59fc pop {r4, pc} */
/* @0x1a5a00 mulseq r9, r12, r8 */
/* @0x1a5a04 eoreq r10, r4, r8, asr #29 */
/* @0x1a5a08 mulseq r9, r0, r8 */
/* @0x1a5a0c andseq r0, r9, r12, lsl #17 */
/* @0x1a5a10 andseq r0, r9, r8, lsl #17 */
/* @0x1a5a14 andseq r0, r9, r4, lsl #17 */
/* @0x1a5a18 andseq r0, r9, r0, lsl #17 */
/* @0x1a5a1c andseq r0, r9, r12, ror r8 */
/* @0x1a5a20 andseq r0, r9, r8, ror r8 */
/* @0x1a5a24 andseq r0, r9, r4, ror r8 */
/* @0x1a5a28 andseq r0, r9, r0, ror r8 */
/* @0x1a5a2c andseq r0, r9, r12, ror #16 */
/* @0x1a5a30 andseq r0, r9, r12, ror #16 */
/* @0x1a5a34 andseq r0, r9, r8, ror #16 */
/* @0x1a5a38 andseq r0, r9, r4, ror #16 */

/* ── FUNC 0x1a5a3c · Part_CreateTextures() · size=352 · insn=88 */
/* @0x1a5a3c push {r4, lr} */
/* @0x1a5a40 mov r1, #0 */
/* @0x1a5a44 ldr r4, [pc, #0x144] */
/* @0x1a5a48 sub sp, sp, #40 */
/* @0x1a5a4c mov r2, #64 */
/* @0x1a5a50 ldr r4, [pc, r4] */
/* @0x1a5a54 mov r0, r4 */
/* @0x1a5a58 bl 0xb65b0 <memset@plt> */
/* @0x1a5a5c mov r0, #1 */
/* @0x1a5a60 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5a64 str r0, [r4] */
/* @0x1a5a68 mov r0, #2 */
/* @0x1a5a6c bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5a70 str r0, [r4, #0x4] */
/* @0x1a5a74 mov r0, #3 */
/* @0x1a5a78 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5a7c str r0, [r4, #0x8] */
/* @0x1a5a80 mov r0, #4 */
/* @0x1a5a84 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5a88 str r0, [r4, #0xc] */
/* @0x1a5a8c mov r0, #5 */
/* @0x1a5a90 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5a94 str r0, [r4, #0x10] */
/* @0x1a5a98 mov r0, #6 */
/* @0x1a5a9c bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5aa0 str r0, [r4, #0x14] */
/* @0x1a5aa4 mov r0, #7 */
/* @0x1a5aa8 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5aac str r0, [r4, #0x18] */
/* @0x1a5ab0 mov r0, #8 */
/* @0x1a5ab4 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5ab8 str r0, [r4, #0x1c] */
/* @0x1a5abc mov r0, #9 */
/* @0x1a5ac0 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5ac4 str r0, [r4, #0x20] */
/* @0x1a5ac8 mov r0, #10 */
/* @0x1a5acc bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5ad0 str r0, [r4, #0x24] */
/* @0x1a5ad4 mov r0, #11 */
/* @0x1a5ad8 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5adc str r0, [r4, #0x28] */
/* @0x1a5ae0 mov r0, #12 */
/* @0x1a5ae4 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5ae8 str r0, [r4, #0x2c] */
/* @0x1a5aec mov r0, #13 */
/* @0x1a5af0 bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5af4 str r0, [r4, #0x30] */
/* @0x1a5af8 mov r0, #14 */
/* @0x1a5afc bl 0x1a8750 <_ZN7RomDisk11LoadTextureEi> */
/* @0x1a5b00 ldr r1, [pc, #0x8c] */
/* @0x1a5b04 movw r2, #0xa1f */
/* @0x1a5b08 mov r3, #1 */
/* @0x1a5b0c add r1, pc, r1 */
/* @0x1a5b10 str r0, [r4, #0x34] */
/* @0x1a5b14 movw r0, #0x4010 */
/* @0x1a5b18 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a5b1c mov r3, #4 */
/* @0x1a5b20 mvn r12, #0 */
/* @0x1a5b24 movw r1, #0x1004 */
/* @0x1a5b28 add r2, r0, #12 */
/* @0x1a5b2c mov lr, r0 */
/* @0x1a5b30 add r3, r3, #1 */
/* @0x1a5b34 str r12, [r2, #0x4]! */
/* @0x1a5b38 cmp r3, r1 */
/* @0x1a5b3c bne 0x1a5b30 <_Z19Part_CreateTexturesv+0xf4> */
/* @0x1a5b40 mov r3, #0 */
/* @0x1a5b44 mov r12, #1 */
/* @0x1a5b48 str r3, [lr, #0xc] */
/* @0x1a5b4c mov r0, lr */
/* @0x1a5b50 movw r1, #0x4010 */
/* @0x1a5b54 movw r2, #0x4152 */
/* @0x1a5b58 movt r2, #0x2057 */
/* @0x1a5b5c str r2, [lr] */
/* @0x1a5b60 mov r2, #64 */
/* @0x1a5b64 str r2, [lr, #0x4] */
/* @0x1a5b68 str r2, [lr, #0x8] */
/* @0x1a5b6c add r2, sp, #12 */
/* @0x1a5b70 str r12, [sp] */
/* @0x1a5b74 bl 0x182f3c <_ZN8Graphics21CreateTextureFromFileEPhjP9ImageInfo14eTextureFormatb> */
/* @0x1a5b78 ldr r3, [pc, #0x18] */
/* @0x1a5b7c ldr r3, [pc, r3] */
/* @0x1a5b80 str r0, [r4, #0x38] */
/* @0x1a5b84 str r0, [r3] */
/* @0x1a5b88 add sp, sp, #40 */
/* @0x1a5b8c pop {r4, pc} */
/* @0x1a5b90 eoreq r10, r4, r0, ror sp */
/* @0x1a5b94 andseq r7, r10, r4, ror r4 */
/* @0x1a5b98 eoreq r10, r4, r8, asr #24 */

/* ── FUNC 0x1a5b9c · ParticleSystem_AddAllToLayers() · size=316 · insn=79 */
/* @0x1a5b9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a5ba0 sub sp, sp, #12 */
/* @0x1a5ba4 ldr r8, [pc, #0x11c] */
/* @0x1a5ba8 ldr r3, [pc, #0x11c] */
/* @0x1a5bac add r8, pc, r8 */
/* @0x1a5bb0 ldr r3, [r8, r3] */
/* @0x1a5bb4 ldrb r3, [r3] */
/* @0x1a5bb8 cmp r3, #0 */
/* @0x1a5bbc beq 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c> */
/* @0x1a5bc0 ldr r3, [pc, #0x108] */
/* @0x1a5bc4 ldr r5, [r8, r3] */
/* @0x1a5bc8 ldr r3, [r5] */
/* @0x1a5bcc cmp r3, #0 */
/* @0x1a5bd0 ble 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c> */
/* @0x1a5bd4 mov r4, #0 */
/* @0x1a5bd8 mov r7, #1 */
/* @0x1a5bdc b 0x1a5bf0 <_Z29ParticleSystem_AddAllToLayersv+0x54> */
/* @0x1a5be0 ldr r3, [r5] */
/* @0x1a5be4 add r4, r4, #1 */
/* @0x1a5be8 cmp r3, r4 */
/* @0x1a5bec ble 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c> */
/* @0x1a5bf0 ldr r3, [r5, #0x4] */
/* @0x1a5bf4 lsl r6, r4, #2 */
/* @0x1a5bf8 ldr r3, [r3, r4, lsl #2] */
/* @0x1a5bfc cmp r3, #0 */
/* @0x1a5c00 beq 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44> */
/* @0x1a5c04 ldr r3, [r3, #0x2c] */
/* @0x1a5c08 cmn r3, #1 */
/* @0x1a5c0c bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44> */
/* @0x1a5c10 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv> */
/* @0x1a5c14 ldr r3, [r5, #0x4] */
/* @0x1a5c18 ldr r2, [pc, #0xb4] */
/* @0x1a5c1c ldr r9, [r3, r6] */
/* @0x1a5c20 ldr r1, [r9, #0x30] */
/* @0x1a5c24 cmn r1, #1 */
/* @0x1a5c28 mov r10, r0 */
/* @0x1a5c2c str r4, [r0, #0x1c] */
/* @0x1a5c30 beq 0x1a5c6c <_Z29ParticleSystem_AddAllToLayersv+0xd0> */
/* @0x1a5c34 ldr r9, [r8, r2] */
/* @0x1a5c38 ldr r0, [r9] */
/* @0x1a5c3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1a5c40 mov r2, r10 */
/* @0x1a5c44 mov r3, #1 */
/* @0x1a5c48 subs r1, r0, #0 */
/* @0x1a5c4c beq 0x1a5cb0 <_Z29ParticleSystem_AddAllToLayersv+0x114> */
/* @0x1a5c50 ldr r12, [r5, #0x4] */
/* @0x1a5c54 ldr r0, [r9] */
/* @0x1a5c58 ldr r11, [r12, r6] */
/* @0x1a5c5c bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1a5c60 ldr r3, [r5, #0x4] */
/* @0x1a5c64 ldr r9, [r3, r6] */
/* @0x1a5c68 str r0, [r11, #0x2c] */
/* @0x1a5c6c ldr r3, [r9, #0x2c] */
/* @0x1a5c70 cmn r3, #1 */
/* @0x1a5c74 bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44> */
/* @0x1a5c78 vldr s15, [r9, #28] */
/* @0x1a5c7c vcvt.s32.f32 s15, s15 */
/* @0x1a5c80 ldr r0, [pc, #0x4c] */
/* @0x1a5c84 mov r2, r10 */
/* @0x1a5c88 mov r3, #1 */
/* @0x1a5c8c ldr r0, [r8, r0] */
/* @0x1a5c90 str r7, [sp] */
/* @0x1a5c94 vmov r1, s15 */
/* @0x1a5c98 ldr r0, [r0] */
/* @0x1a5c9c bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb> */
/* @0x1a5ca0 str r0, [r9, #0x2c] */
/* @0x1a5ca4 b 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44> */
/* @0x1a5ca8 add sp, sp, #12 */
/* @0x1a5cac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1a5cb0 ldr r3, [r5, #0x4] */
/* @0x1a5cb4 ldr r9, [r3, r6] */
/* @0x1a5cb8 ldr r3, [r9, #0x2c] */
/* @0x1a5cbc cmn r3, #1 */
/* @0x1a5cc0 bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44> */
/* @0x1a5cc4 b 0x1a5c78 <_Z29ParticleSystem_AddAllToLayersv+0xdc> */
/* @0x1a5cc8 eoreq r12, r4, r4, lsr #1 */
/* @0x1a5ccc .word 0xffffbcd4 */
/* @0x1a5cd0 .word 0xffffeb68 */
/* @0x1a5cd4 .word 0xffffbcd8 */

/* ── FUNC 0x1a5cd8 · ParticleSystem_RemoveAllFromLayers() · size=192 · insn=48 */
/* @0x1a5cd8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a5cdc ldr r3, [pc, #0xa8] */
/* @0x1a5ce0 ldr r3, [pc, r3] */
/* @0x1a5ce4 ldrb r3, [r3] */
/* @0x1a5ce8 cmp r3, #0 */
/* @0x1a5cec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1a5cf0 ldr r5, [pc, #0x98] */
/* @0x1a5cf4 ldr r5, [pc, r5] */
/* @0x1a5cf8 ldr r3, [r5] */
/* @0x1a5cfc cmp r3, #0 */
/* @0x1a5d00 pople {r3, r4, r5, r6, r7, pc} */
/* @0x1a5d04 mov r4, #0 */
/* @0x1a5d08 mvn r6, #0 */
/* @0x1a5d0c b 0x1a5d20 <_Z34ParticleSystem_RemoveAllFromLayersv+0x48> */
/* @0x1a5d10 ldr r3, [r5] */
/* @0x1a5d14 add r4, r4, #1 */
/* @0x1a5d18 cmp r3, r4 */
/* @0x1a5d1c ble 0x1a5d88 <_Z34ParticleSystem_RemoveAllFromLayersv+0xb0> */
/* @0x1a5d20 ldr r1, [r5, #0x4] */
/* @0x1a5d24 mov r3, #0 */
/* @0x1a5d28 ldr r12, [pc, #0x64] */
/* @0x1a5d2c mov r2, #1 */
/* @0x1a5d30 lsl r7, r4, #2 */
/* @0x1a5d34 ldr r0, [r1, r4, lsl #2] */
/* @0x1a5d38 cmp r0, r3 */
/* @0x1a5d3c beq 0x1a5d10 <_Z34ParticleSystem_RemoveAllFromLayersv+0x38> */
/* @0x1a5d40 ldr r1, [r0, #0x2c] */
/* @0x1a5d44 cmn r1, #1 */
/* @0x1a5d48 beq 0x1a5d64 <_Z34ParticleSystem_RemoveAllFromLayersv+0x8c> */
/* @0x1a5d4c ldr r12, [pc, r12] */
/* @0x1a5d50 ldr r0, [r12] */
/* @0x1a5d54 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb> */
/* @0x1a5d58 ldr r3, [r5, #0x4] */
/* @0x1a5d5c ldr r0, [r3, r7] */
/* @0x1a5d60 str r6, [r0, #0x2c] */
/* @0x1a5d64 ldrb r3, [r0, #0x34] */
/* @0x1a5d68 cmp r3, #0 */
/* @0x1a5d6c beq 0x1a5d10 <_Z34ParticleSystem_RemoveAllFromLayersv+0x38> */
/* @0x1a5d70 mov r0, r4 */
/* @0x1a5d74 add r4, r4, #1 */
/* @0x1a5d78 bl 0x1a454c <_Z22ParticleSystem_Destroyi> */
/* @0x1a5d7c ldr r3, [r5] */
/* @0x1a5d80 cmp r3, r4 */
/* @0x1a5d84 bgt 0x1a5d20 <_Z34ParticleSystem_RemoveAllFromLayersv+0x48> */
/* @0x1a5d88 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a5d8c eoreq r7, r4, r4, asr #24 */
/* @0x1a5d90 eoreq r10, r4, r4, asr #21 */
/* @0x1a5d94 .word 0x00247bdc */

/* ── FUNC 0x1a5d98 · ParticleSystem_AutoDraw(int) · size=64 · insn=16 */
/* @0x1a5d98 push {r4, lr} */
/* @0x1a5d9c mov r4, r0 */
/* @0x1a5da0 bl 0x1a3770 <_Z21ParticleSystem_Existsi> */
/* @0x1a5da4 cmp r0, #0 */
/* @0x1a5da8 popeq {r4, pc} */
/* @0x1a5dac ldr r3, [pc, #0x20] */
/* @0x1a5db0 ldr r3, [pc, r3] */
/* @0x1a5db4 ldr r3, [r3, #0x4] */
/* @0x1a5db8 ldr r3, [r3, r4, lsl #2] */
/* @0x1a5dbc ldrb r3, [r3, #0x29] */
/* @0x1a5dc0 cmp r3, #0 */
/* @0x1a5dc4 popeq {r4, pc} */
/* @0x1a5dc8 mov r0, r4 */
/* @0x1a5dcc pop {r4, lr} */
/* @0x1a5dd0 b 0x1a56ac <_Z19ParticleSystem_Drawi> */
/* @0x1a5dd4 eoreq r10, r4, r8, lsl #20 */

/* ── FUNC 0x1a5dd8 · INITIALIZE_Particle_Main() · size=16 · insn=4 */
/* @0x1a5dd8 push {r3, lr} */
/* @0x1a5ddc bl 0x1a2d90 <_Z23ParticleType_DestroyAllv> */
/* @0x1a5de0 pop {r3, lr} */
/* @0x1a5de4 b 0x1a4590 <_Z25ParticleSystem_DestroyAllv> */

/* ── FUNC 0x1a5de8 · FINALIZE_Particle_Main() · size=332 · insn=83 */
/* @0x1a5de8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a5dec mov r8, #0 */
/* @0x1a5df0 ldr r6, [pc, #0x130] */
/* @0x1a5df4 mov r7, r8 */
/* @0x1a5df8 ldr r6, [pc, r6] */
/* @0x1a5dfc ldr r2, [r6] */
/* @0x1a5e00 cmp r8, r2 */
/* @0x1a5e04 bge 0x1a5ee0 <_Z22FINALIZE_Particle_Mainv+0xf8> */
/* @0x1a5e08 ldr r3, [r6, #0x4] */
/* @0x1a5e0c lsl r5, r8, #2 */
/* @0x1a5e10 ldr r3, [r3, r8, lsl #2] */
/* @0x1a5e14 cmp r3, #0 */
/* @0x1a5e18 beq 0x1a5ed4 <_Z22FINALIZE_Particle_Mainv+0xec> */
/* @0x1a5e1c ldr r2, [r3] */
/* @0x1a5e20 cmp r2, #0 */
/* @0x1a5e24 ble 0x1a5e60 <_Z22FINALIZE_Particle_Mainv+0x78> */
/* @0x1a5e28 mov r4, #0 */
/* @0x1a5e2c ldr r3, [r3, #0x4] */
/* @0x1a5e30 ldr r0, [r3, r4, lsl #2] */
/* @0x1a5e34 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a5e38 ldr r3, [r6, #0x4] */
/* @0x1a5e3c ldr r3, [r3, r5] */
/* @0x1a5e40 ldr r3, [r3, #0x4] */
/* @0x1a5e44 str r7, [r3, r4, lsl #2] */
/* @0x1a5e48 add r4, r4, #1 */
/* @0x1a5e4c ldr r3, [r6, #0x4] */
/* @0x1a5e50 ldr r3, [r3, r5] */
/* @0x1a5e54 ldr r2, [r3] */
/* @0x1a5e58 cmp r2, r4 */
/* @0x1a5e5c bgt 0x1a5e2c <_Z22FINALIZE_Particle_Mainv+0x44> */
/* @0x1a5e60 ldr r0, [r3, #0x4] */
/* @0x1a5e64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a5e68 ldr r3, [r6, #0x4] */
/* @0x1a5e6c ldr r2, [r3, r5] */
/* @0x1a5e70 str r7, [r2, #0x4] */
/* @0x1a5e74 ldr r3, [r3, r5] */
/* @0x1a5e78 ldr r2, [r3, #0xc] */
/* @0x1a5e7c str r7, [r3] */
/* @0x1a5e80 cmp r2, #0 */
/* @0x1a5e84 str r7, [r3, #0x8] */
/* @0x1a5e88 ble 0x1a5eb4 <_Z22FINALIZE_Particle_Mainv+0xcc> */
/* @0x1a5e8c mov r4, #0 */
/* @0x1a5e90 ldr r3, [r3, #0x10] */
/* @0x1a5e94 ldr r0, [r3, r4, lsl #2] */
/* @0x1a5e98 add r4, r4, #1 */
/* @0x1a5e9c bl 0x27d1d0 <_ZdlPv> */
/* @0x1a5ea0 ldr r3, [r6, #0x4] */
/* @0x1a5ea4 ldr r3, [r3, r5] */
/* @0x1a5ea8 ldr r2, [r3, #0xc] */
/* @0x1a5eac cmp r2, r4 */
/* @0x1a5eb0 bgt 0x1a5e90 <_Z22FINALIZE_Particle_Mainv+0xa8> */
/* @0x1a5eb4 ldr r0, [r3, #0x10] */
/* @0x1a5eb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1a5ebc ldm r6, {r2, r3} */
/* @0x1a5ec0 ldr r1, [r3, r5] */
/* @0x1a5ec4 str r7, [r1, #0x10] */
/* @0x1a5ec8 ldr r3, [r3, r5] */
/* @0x1a5ecc str r7, [r3, #0xc] */
/* @0x1a5ed0 str r7, [r3, #0x14] */
/* @0x1a5ed4 add r8, r8, #1 */
/* @0x1a5ed8 cmp r8, r2 */
/* @0x1a5edc blt 0x1a5e08 <_Z22FINALIZE_Particle_Mainv+0x20> */
/* @0x1a5ee0 ldr r4, [pc, #0x44] */
/* @0x1a5ee4 bl 0x1a2d90 <_Z23ParticleType_DestroyAllv> */
/* @0x1a5ee8 bl 0x1a4590 <_Z25ParticleSystem_DestroyAllv> */
/* @0x1a5eec mov r6, #0 */
/* @0x1a5ef0 ldr r4, [pc, r4] */
/* @0x1a5ef4 add r5, r4, #60 */
/* @0x1a5ef8 ldr r0, [r4], #4 */
/* @0x1a5efc cmp r0, #0 */
/* @0x1a5f00 beq 0x1a5f0c <_Z22FINALIZE_Particle_Mainv+0x124> */
/* @0x1a5f04 bl 0x180f98 <_ZN8Graphics11FreeTextureEPv> */
/* @0x1a5f08 str r6, [r4, #-0x4] */
/* @0x1a5f0c cmp r4, r5 */
/* @0x1a5f10 bne 0x1a5ef8 <_Z22FINALIZE_Particle_Mainv+0x110> */
/* @0x1a5f14 ldr r3, [pc, #0x14] */
/* @0x1a5f18 mov r2, #0 */
/* @0x1a5f1c ldr r3, [pc, r3] */
/* @0x1a5f20 str r2, [r3] */
/* @0x1a5f24 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1a5f28 eoreq r10, r4, r0, asr #19 */
/* @0x1a5f2c .word 0x0024a8d0 */
/* @0x1a5f30 eoreq r10, r4, r8, lsr #17 */

/* ── FUNC 0x1a5f34 · CPath::GetPoint(int) · size=68 · insn=17 */
/* @0x1a5f34 cmp r1, #0 */
/* @0x1a5f38 blt 0x1a5f64 <_ZN5CPath8GetPointEi+0x30> */
/* @0x1a5f3c ldr r3, [r0, #0x10] */
/* @0x1a5f40 cmp r1, r3 */
/* @0x1a5f44 bge 0x1a5f58 <_ZN5CPath8GetPointEi+0x24> */
/* @0x1a5f48 add r1, r1, r1, lsl #1 */
/* @0x1a5f4c ldr r3, [r0, #0x4] */
/* @0x1a5f50 add r0, r3, r1, lsl #2 */
/* @0x1a5f54 bx lr */
/* @0x1a5f58 ldr r0, [pc, #0x10] */
/* @0x1a5f5c ldr r0, [pc, r0] */
/* @0x1a5f60 bx lr */
/* @0x1a5f64 ldr r0, [pc, #0x8] */
/* @0x1a5f68 ldr r0, [pc, r0] */
/* @0x1a5f6c bx lr */
/* @0x1a5f70 eoreq r10, r4, r12, ror #16 */
/* @0x1a5f74 eoreq r10, r4, r0, ror #16 */

/* ── FUNC 0x1a5f78 · CPath::ComputeLength() · size=240 · insn=60 */
/* @0x1a5f78 push {r3, r4, r5, r6, r7, lr} */
/* @0x1a5f7c vpush {d8} */
/* @0x1a5f80 mov r4, r0 */
/* @0x1a5f84 ldr r0, [r0, #0x20] */
/* @0x1a5f88 mov r2, #0 */
/* @0x1a5f8c str r2, [r4, #0x28] */
/* @0x1a5f90 cmp r0, #0 */
/* @0x1a5f94 str r2, [r4, #0x24] */
/* @0x1a5f98 ble 0x1a6044 <_ZN5CPath13ComputeLengthEv+0xcc> */
/* @0x1a5f9c ldr r3, [r4, #0xc] */
/* @0x1a5fa0 cmp r0, #1 */
/* @0x1a5fa4 str r2, [r3, #0xc] */
/* @0x1a5fa8 beq 0x1a6044 <_ZN5CPath13ComputeLengthEv+0xcc> */
/* @0x1a5fac vmov.f32 s17, #5.000000e-01 */
/* @0x1a5fb0 mov r6, #0 */
/* @0x1a5fb4 mov r5, #1 */
/* @0x1a5fb8 vldr s16, [pc, #164] */
/* @0x1a5fbc lsl r7, r5, #4 */
/* @0x1a5fc0 add r2, r3, r6 */
/* @0x1a5fc4 add r1, r3, r7 */
/* @0x1a5fc8 vldr s15, [r2, #4] */
/* @0x1a5fcc vldr s14, [r1, #4] */
/* @0x1a5fd0 vldr s13, [r1] */
/* @0x1a5fd4 add r5, r5, #1 */
/* @0x1a5fd8 vsub.f32 s14, s14, s15 */
/* @0x1a5fdc vldr s15, [r2] */
/* @0x1a5fe0 vmul.f32 s14, s14, s14 */
/* @0x1a5fe4 vsub.f32 s15, s13, s15 */
/* @0x1a5fe8 vmla.f32 s14, s15, s15 */
/* @0x1a5fec vsqrt.f32 s15, s14 */
/* @0x1a5ff0 vcmp.f32 s15, s15 */
/* @0x1a5ff4 vmrs APSR_nzcv, fpscr */
/* @0x1a5ff8 bne 0x1a604c <_ZN5CPath13ComputeLengthEv+0xd4> */
/* @0x1a5ffc add r7, r3, r7 */
/* @0x1a6000 add r2, r3, r6 */
/* @0x1a6004 vldr s11, [r7, #8] */
/* @0x1a6008 vldr s14, [r2, #8] */
/* @0x1a600c vadd.f32 s14, s11, s14 */
/* @0x1a6010 vldr s13, [r4, #40] */
/* @0x1a6014 vldr s12, [r4, #36] */
/* @0x1a6018 cmp r0, r5 */
/* @0x1a601c add r6, r6, #16 */
/* @0x1a6020 vmul.f32 s14, s14, s17 */
/* @0x1a6024 vdiv.f32 s14, s14, s16 */
/* @0x1a6028 vdiv.f32 s14, s15, s14 */
/* @0x1a602c vadd.f32 s15, s15, s12 */
/* @0x1a6030 vadd.f32 s14, s13, s14 */
/* @0x1a6034 vstr s15, [r4, #36] */
/* @0x1a6038 vstr s15, [r7, #12] */
/* @0x1a603c vstr s14, [r4, #40] */
/* @0x1a6040 bgt 0x1a5fbc <_ZN5CPath13ComputeLengthEv+0x44> */
/* @0x1a6044 vpop {d8} */
/* @0x1a6048 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a604c vmov r0, s14 */
/* @0x1a6050 bl 0xb6700 <sqrtf@plt> */
/* @0x1a6054 ldr r3, [r4, #0xc] */
/* @0x1a6058 vmov s15, r0 */
/* @0x1a605c ldr r0, [r4, #0x20] */
/* @0x1a6060 b 0x1a5ffc <_ZN5CPath13ComputeLengthEv+0x84> */
/* @0x1a6064 sbcmi r0, r8, #0 */

/* ── FUNC 0x1a6068 · CPath::AddInternalPoint(float, float, float) · size=116 · insn=29 */
/* @0x1a6068 ldr r12, [r0, #0x20] */
/* @0x1a606c push {r3, r4, r5, r6, r7, lr} */
/* @0x1a6070 mov r6, r2 */
/* @0x1a6074 ldr r2, [r0, #0x8] */
/* @0x1a6078 mov r4, r0 */
/* @0x1a607c add r0, r12, #1 */
/* @0x1a6080 mov r7, r1 */
/* @0x1a6084 cmp r0, r2 */
/* @0x1a6088 mov r5, r3 */
/* @0x1a608c str r0, [r4, #0x20] */
/* @0x1a6090 ble 0x1a60bc <_ZN5CPath16AddInternalPointEfff+0x54> */
/* @0x1a6094 add r1, r12, #11 */
/* @0x1a6098 ldr r2, [pc, #0x38] */
/* @0x1a609c add r0, r4, #12 */
/* @0x1a60a0 mov r3, #158 */
/* @0x1a60a4 add r2, pc, r2 */
/* @0x1a60a8 lsl r1, r1, #4 */
/* @0x1a60ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x1a60b0 ldr r0, [r4, #0x20] */
/* @0x1a60b4 add r3, r0, #10 */
/* @0x1a60b8 str r3, [r4, #0x8] */
/* @0x1a60bc ldr r3, [r4, #0xc] */
/* @0x1a60c0 sub r0, r0, #-268435455 */
/* @0x1a60c4 add r0, r3, r0, lsl #4 */
/* @0x1a60c8 str r7, [r0] */
/* @0x1a60cc str r6, [r0, #0x4] */
/* @0x1a60d0 str r5, [r0, #0x8] */
/* @0x1a60d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1a60d8 andseq r7, r10, r4, lsr r0 */

/* ── FUNC 0x1a60dc · CPath::ComputeLinear() · size=120 · insn=30 */
/* @0x1a60dc ldr r3, [r0, #0x10] */
/* @0x1a60e0 push {r4, r5, r6, lr} */
/* @0x1a60e4 mov r5, #0 */
/* @0x1a60e8 cmp r3, r5 */
/* @0x1a60ec mov r4, r0 */
/* @0x1a60f0 str r5, [r0, #0x20] */
/* @0x1a60f4 pople {r4, r5, r6, pc} */
/* @0x1a60f8 mov r6, r5 */
/* @0x1a60fc ldr r3, [r4, #0x4] */
/* @0x1a6100 mov r0, r4 */
/* @0x1a6104 add r6, r6, #1 */
/* @0x1a6108 add r3, r3, r5 */
/* @0x1a610c add r5, r5, #12 */
/* @0x1a6110 ldr r1, [r3] */
/* @0x1a6114 ldr r2, [r3, #0x4] */
/* @0x1a6118 ldr r3, [r3, #0x8] */
/* @0x1a611c bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6120 ldr r3, [r4, #0x10] */
/* @0x1a6124 cmp r3, r6 */
/* @0x1a6128 bgt 0x1a60fc <_ZN5CPath13ComputeLinearEv+0x20> */
/* @0x1a612c ldrb r3, [r4, #0x18] */
/* @0x1a6130 cmp r3, #0 */
/* @0x1a6134 popeq {r4, r5, r6, pc} */
/* @0x1a6138 ldr r3, [r4, #0x4] */
/* @0x1a613c mov r0, r4 */
/* @0x1a6140 pop {r4, r5, r6, lr} */
/* @0x1a6144 ldr r1, [r3] */
/* @0x1a6148 ldr r2, [r3, #0x4] */
/* @0x1a614c ldr r3, [r3, #0x8] */
/* @0x1a6150 b 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */

/* ── FUNC 0x1a6154 · CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float) · size=2660 · insn=665 */
/* @0x1a6154 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a6158 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a615c cmp r1, #0 */
/* @0x1a6160 sub sp, sp, #196 */
/* @0x1a6164 mov r5, r0 */
/* @0x1a6168 vmov s15, r2 */
/* @0x1a616c vldr s12, [sp, #296] */
/* @0x1a6170 str r1, [sp, #0xac] */
/* @0x1a6174 vmov s14, r3 */
/* @0x1a6178 beq 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58> */
/* @0x1a617c vmov.f32 s28, #2.500000e-01 */
/* @0x1a6180 vmov.f32 s30, #1.600000e+01 */
/* @0x1a6184 vmov.f32 s31, #5.000000e-01 */
/* @0x1a6188 b 0x1a6224 <_ZN5CPath11HandlePieceEifffffffff+0xd0> */
/* @0x1a618c mov r0, r5 */
/* @0x1a6190 ldr r1, [sp, #0x9c] */
/* @0x1a6194 ldr r2, [sp, #0xa0] */
/* @0x1a6198 ldr r3, [sp, #0xb0] */
/* @0x1a619c bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a61a0 vldr s7, [sp, #304] */
/* @0x1a61a4 vldr s8, [sp, #316] */
/* @0x1a61a8 vsub.f32 s15, s7, s8 */
/* @0x1a61ac vldr s9, [sp, #300] */
/* @0x1a61b0 vldr s10, [sp, #312] */
/* @0x1a61b4 vmul.f32 s15, s15, s15 */
/* @0x1a61b8 vsub.f32 s14, s9, s10 */
/* @0x1a61bc vmla.f32 s15, s14, s14 */
/* @0x1a61c0 vcmpe.f32 s15, s30 */
/* @0x1a61c4 vmrs APSR_nzcv, fpscr */
/* @0x1a61c8 ble 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58> */
/* @0x1a61cc vldr s8, [sp, #300] */
/* @0x1a61d0 vldr s9, [sp, #312] */
/* @0x1a61d4 vldr s5, [sp, #304] */
/* @0x1a61d8 vadd.f32 s13, s8, s9 */
/* @0x1a61dc vldr s7, [sp, #316] */
/* @0x1a61e0 vldr s8, [sp, #308] */
/* @0x1a61e4 vldr s9, [sp, #320] */
/* @0x1a61e8 ldr r3, [sp, #0xac] */
/* @0x1a61ec subs r3, r3, #1 */
/* @0x1a61f0 str r3, [sp, #0xac] */
/* @0x1a61f4 vadd.f32 s14, s5, s7 */
/* @0x1a61f8 vadd.f32 s15, s8, s9 */
/* @0x1a61fc vmul.f32 s13, s13, s31 */
/* @0x1a6200 vmul.f32 s14, s14, s31 */
/* @0x1a6204 vstr s13, [sp, #300] */
/* @0x1a6208 vmul.f32 s15, s15, s31 */
/* @0x1a620c vstr s14, [sp, #304] */
/* @0x1a6210 vstr s15, [sp, #308] */
/* @0x1a6214 beq 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58> */
/* @0x1a6218 vldr s12, [sp, #176] */
/* @0x1a621c vldr s14, [sp, #160] */
/* @0x1a6220 vldr s15, [sp, #156] */
/* @0x1a6224 vldr s5, [sp, #304] */
/* @0x1a6228 vsub.f32 s13, s5, s14 */
/* @0x1a622c vldr s7, [sp, #300] */
/* @0x1a6230 vmul.f32 s13, s13, s13 */
/* @0x1a6234 vsub.f32 s8, s7, s15 */
/* @0x1a6238 vadd.f32 s9, s15, s7 */
/* @0x1a623c vadd.f32 s10, s14, s5 */
/* @0x1a6240 vldr s5, [sp, #308] */
/* @0x1a6244 vadd.f32 s11, s12, s5 */
/* @0x1a6248 vmla.f32 s13, s8, s8 */
/* @0x1a624c vldr s8, [sp, #304] */
/* @0x1a6250 vadd.f32 s6, s9, s7 */
/* @0x1a6254 vadd.f32 s7, s10, s8 */
/* @0x1a6258 vadd.f32 s8, s11, s5 */
/* @0x1a625c vldr s5, [sp, #312] */
/* @0x1a6260 vadd.f32 s6, s6, s5 */
/* @0x1a6264 vldr s5, [sp, #316] */
/* @0x1a6268 vadd.f32 s7, s7, s5 */
/* @0x1a626c vldr s5, [sp, #320] */
/* @0x1a6270 vadd.f32 s8, s8, s5 */
/* @0x1a6274 vmul.f32 s6, s6, s28 */
/* @0x1a6278 vmul.f32 s7, s7, s28 */
/* @0x1a627c vstr s6, [sp, #156] */
/* @0x1a6280 vmul.f32 s8, s8, s28 */
/* @0x1a6284 vstr s7, [sp, #160] */
/* @0x1a6288 vcmpe.f32 s13, s30 */
/* @0x1a628c vstr s8, [sp, #176] */
/* @0x1a6290 vmrs APSR_nzcv, fpscr */
/* @0x1a6294 ble 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38> */
/* @0x1a6298 vmul.f32 s9, s9, s31 */
/* @0x1a629c ldr r3, [sp, #0xac] */
/* @0x1a62a0 cmp r3, #1 */
/* @0x1a62a4 vmul.f32 s10, s10, s31 */
/* @0x1a62a8 vstr s9, [sp, #136] */
/* @0x1a62ac vmul.f32 s11, s11, s31 */
/* @0x1a62b0 vstr s10, [sp, #140] */
/* @0x1a62b4 vstr s11, [sp, #184] */
/* @0x1a62b8 beq 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38> */
/* @0x1a62bc sub r11, r3, #2 */
/* @0x1a62c0 b 0x1a6358 <_ZN5CPath11HandlePieceEifffffffff+0x204> */
/* @0x1a62c4 mov r0, r5 */
/* @0x1a62c8 ldr r1, [sp, #0x98] */
/* @0x1a62cc ldr r2, [sp, #0xa4] */
/* @0x1a62d0 ldr r3, [sp, #0xb4] */
/* @0x1a62d4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a62d8 vldr s7, [sp, #140] */
/* @0x1a62dc vldr s8, [sp, #160] */
/* @0x1a62e0 vsub.f32 s15, s7, s8 */
/* @0x1a62e4 vldr s9, [sp, #136] */
/* @0x1a62e8 vldr s10, [sp, #156] */
/* @0x1a62ec vmul.f32 s15, s15, s15 */
/* @0x1a62f0 vsub.f32 s14, s9, s10 */
/* @0x1a62f4 vmla.f32 s15, s14, s14 */
/* @0x1a62f8 vcmpe.f32 s15, s30 */
/* @0x1a62fc vmrs APSR_nzcv, fpscr */
/* @0x1a6300 ble 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38> */
/* @0x1a6304 vldr s15, [sp, #140] */
/* @0x1a6308 vldr s11, [sp, #136] */
/* @0x1a630c vldr s7, [sp, #184] */
/* @0x1a6310 vldr s10, [sp, #156] */
/* @0x1a6314 vldr s12, [sp, #160] */
/* @0x1a6318 vadd.f32 s13, s10, s11 */
/* @0x1a631c vldr s5, [sp, #176] */
/* @0x1a6320 cmp r11, #0 */
/* @0x1a6324 sub r11, r11, #1 */
/* @0x1a6328 vadd.f32 s14, s12, s15 */
/* @0x1a632c vadd.f32 s15, s5, s7 */
/* @0x1a6330 vmul.f32 s13, s13, s31 */
/* @0x1a6334 vmul.f32 s14, s14, s31 */
/* @0x1a6338 vstr s13, [sp, #136] */
/* @0x1a633c vmul.f32 s15, s15, s31 */
/* @0x1a6340 vstr s14, [sp, #140] */
/* @0x1a6344 vstr s15, [sp, #184] */
/* @0x1a6348 beq 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38> */
/* @0x1a634c vldr s12, [sp, #180] */
/* @0x1a6350 vldr s14, [sp, #164] */
/* @0x1a6354 vldr s15, [sp, #152] */
/* @0x1a6358 vldr s5, [sp, #140] */
/* @0x1a635c vsub.f32 s13, s5, s14 */
/* @0x1a6360 vldr s7, [sp, #136] */
/* @0x1a6364 vmul.f32 s13, s13, s13 */
/* @0x1a6368 vsub.f32 s8, s7, s15 */
/* @0x1a636c vadd.f32 s9, s15, s7 */
/* @0x1a6370 vadd.f32 s10, s14, s5 */
/* @0x1a6374 vldr s5, [sp, #184] */
/* @0x1a6378 vadd.f32 s11, s12, s5 */
/* @0x1a637c vmla.f32 s13, s8, s8 */
/* @0x1a6380 vldr s8, [sp, #140] */
/* @0x1a6384 vadd.f32 s6, s7, s9 */
/* @0x1a6388 vadd.f32 s7, s8, s10 */
/* @0x1a638c vadd.f32 s8, s5, s11 */
/* @0x1a6390 vldr s5, [sp, #156] */
/* @0x1a6394 vadd.f32 s6, s5, s6 */
/* @0x1a6398 vldr s5, [sp, #160] */
/* @0x1a639c vadd.f32 s7, s5, s7 */
/* @0x1a63a0 vldr s5, [sp, #176] */
/* @0x1a63a4 vadd.f32 s8, s5, s8 */
/* @0x1a63a8 vmul.f32 s6, s6, s28 */
/* @0x1a63ac vmul.f32 s7, s7, s28 */
/* @0x1a63b0 vstr s6, [sp, #152] */
/* @0x1a63b4 vmul.f32 s8, s8, s28 */
/* @0x1a63b8 vstr s7, [sp, #164] */
/* @0x1a63bc vcmpe.f32 s13, s30 */
/* @0x1a63c0 vstr s8, [sp, #180] */
/* @0x1a63c4 vmrs APSR_nzcv, fpscr */
/* @0x1a63c8 ble 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170> */
/* @0x1a63cc vmul.f32 s9, s9, s31 */
/* @0x1a63d0 cmp r11, #0 */
/* @0x1a63d4 str r11, [sp, #0xa8] */
/* @0x1a63d8 vmul.f32 s10, s10, s31 */
/* @0x1a63dc vstr s9, [sp, #144] */
/* @0x1a63e0 vmul.f32 s11, s11, s31 */
/* @0x1a63e4 vstr s10, [sp, #148] */
/* @0x1a63e8 vstr s11, [sp, #188] */
/* @0x1a63ec bne 0x1a648c <_ZN5CPath11HandlePieceEifffffffff+0x338> */
/* @0x1a63f0 b 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170> */
/* @0x1a63f4 mov r0, r5 */
/* @0x1a63f8 ldr r1, [sp, #0x80] */
/* @0x1a63fc ldr r2, [sp, #0x78] */
/* @0x1a6400 ldr r3, [sp, #0x84] */
/* @0x1a6404 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6408 vldr s7, [sp, #148] */
/* @0x1a640c vldr s8, [sp, #164] */
/* @0x1a6410 vsub.f32 s15, s7, s8 */
/* @0x1a6414 vldr s9, [sp, #144] */
/* @0x1a6418 vldr s10, [sp, #152] */
/* @0x1a641c vmul.f32 s15, s15, s15 */
/* @0x1a6420 vsub.f32 s14, s9, s10 */
/* @0x1a6424 vmla.f32 s15, s14, s14 */
/* @0x1a6428 vcmpe.f32 s15, s30 */
/* @0x1a642c vmrs APSR_nzcv, fpscr */
/* @0x1a6430 ble 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170> */
/* @0x1a6434 vldr s15, [sp, #144] */
/* @0x1a6438 vldr s14, [sp, #152] */
/* @0x1a643c vldr s7, [sp, #148] */
/* @0x1a6440 vadd.f32 s13, s14, s15 */
/* @0x1a6444 vldr s9, [sp, #188] */
/* @0x1a6448 vldr s5, [sp, #164] */
/* @0x1a644c vldr s8, [sp, #180] */
/* @0x1a6450 ldr r3, [sp, #0xa8] */
/* @0x1a6454 subs r3, r3, #1 */
/* @0x1a6458 str r3, [sp, #0xa8] */
/* @0x1a645c vadd.f32 s14, s5, s7 */
/* @0x1a6460 vadd.f32 s15, s8, s9 */
/* @0x1a6464 vmul.f32 s13, s13, s31 */
/* @0x1a6468 vmul.f32 s14, s14, s31 */
/* @0x1a646c vstr s13, [sp, #144] */
/* @0x1a6470 vmul.f32 s15, s15, s31 */
/* @0x1a6474 vstr s14, [sp, #148] */
/* @0x1a6478 vstr s15, [sp, #188] */
/* @0x1a647c beq 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170> */
/* @0x1a6480 vldr s12, [sp, #132] */
/* @0x1a6484 vldr s14, [sp, #120] */
/* @0x1a6488 vldr s15, [sp, #128] */
/* @0x1a648c vldr s11, [sp, #148] */
/* @0x1a6490 vsub.f32 s13, s11, s14 */
/* @0x1a6494 vldr s5, [sp, #144] */
/* @0x1a6498 vldr s7, [sp, #188] */
/* @0x1a649c vmul.f32 s13, s13, s13 */
/* @0x1a64a0 vsub.f32 s8, s5, s15 */
/* @0x1a64a4 vadd.f32 s9, s15, s5 */
/* @0x1a64a8 vadd.f32 s10, s14, s11 */
/* @0x1a64ac vadd.f32 s11, s12, s7 */
/* @0x1a64b0 vmla.f32 s13, s8, s8 */
/* @0x1a64b4 vldr s8, [sp, #148] */
/* @0x1a64b8 vadd.f32 s6, s5, s9 */
/* @0x1a64bc vldr s5, [sp, #188] */
/* @0x1a64c0 vadd.f32 s7, s8, s10 */
/* @0x1a64c4 vadd.f32 s8, s5, s11 */
/* @0x1a64c8 vldr s5, [sp, #152] */
/* @0x1a64cc vadd.f32 s6, s5, s6 */
/* @0x1a64d0 vldr s5, [sp, #164] */
/* @0x1a64d4 vadd.f32 s7, s5, s7 */
/* @0x1a64d8 vldr s5, [sp, #180] */
/* @0x1a64dc vadd.f32 s8, s5, s8 */
/* @0x1a64e0 vmul.f32 s6, s6, s28 */
/* @0x1a64e4 vmul.f32 s7, s7, s28 */
/* @0x1a64e8 vstr s6, [sp, #128] */
/* @0x1a64ec vmul.f32 s8, s8, s28 */
/* @0x1a64f0 vstr s7, [sp, #120] */
/* @0x1a64f4 vcmpe.f32 s13, s30 */
/* @0x1a64f8 vstr s8, [sp, #132] */
/* @0x1a64fc vmrs APSR_nzcv, fpscr */
/* @0x1a6500 ble 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0> */
/* @0x1a6504 vmul.f32 s9, s9, s31 */
/* @0x1a6508 ldr r3, [sp, #0xa8] */
/* @0x1a650c cmp r3, #1 */
/* @0x1a6510 vmul.f32 s10, s10, s31 */
/* @0x1a6514 vstr s9, [sp, #116] */
/* @0x1a6518 vmul.f32 s11, s11, s31 */
/* @0x1a651c vstr s10, [sp, #112] */
/* @0x1a6520 vstr s11, [sp, #124] */
/* @0x1a6524 beq 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0> */
/* @0x1a6528 sub r10, r3, #2 */
/* @0x1a652c b 0x1a65c4 <_ZN5CPath11HandlePieceEifffffffff+0x470> */
/* @0x1a6530 mov r0, r5 */
/* @0x1a6534 ldr r1, [sp, #0x64] */
/* @0x1a6538 ldr r2, [sp, #0x68] */
/* @0x1a653c ldr r3, [sp, #0x6c] */
/* @0x1a6540 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6544 vldr s7, [sp, #112] */
/* @0x1a6548 vldr s8, [sp, #120] */
/* @0x1a654c vsub.f32 s15, s7, s8 */
/* @0x1a6550 vldr s9, [sp, #116] */
/* @0x1a6554 vldr s10, [sp, #128] */
/* @0x1a6558 vmul.f32 s15, s15, s15 */
/* @0x1a655c vsub.f32 s14, s9, s10 */
/* @0x1a6560 vmla.f32 s15, s14, s14 */
/* @0x1a6564 vcmpe.f32 s15, s30 */
/* @0x1a6568 vmrs APSR_nzcv, fpscr */
/* @0x1a656c ble 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0> */
/* @0x1a6570 vldr s8, [sp, #116] */
/* @0x1a6574 vldr s10, [sp, #112] */
/* @0x1a6578 vldr s12, [sp, #124] */
/* @0x1a657c vldr s7, [sp, #128] */
/* @0x1a6580 vldr s9, [sp, #120] */
/* @0x1a6584 vadd.f32 s13, s7, s8 */
/* @0x1a6588 vldr s11, [sp, #132] */
/* @0x1a658c cmp r10, #0 */
/* @0x1a6590 sub r10, r10, #1 */
/* @0x1a6594 vadd.f32 s14, s9, s10 */
/* @0x1a6598 vadd.f32 s15, s11, s12 */
/* @0x1a659c vmul.f32 s13, s13, s31 */
/* @0x1a65a0 vmul.f32 s14, s14, s31 */
/* @0x1a65a4 vstr s13, [sp, #116] */
/* @0x1a65a8 vmul.f32 s15, s15, s31 */
/* @0x1a65ac vstr s14, [sp, #112] */
/* @0x1a65b0 vstr s15, [sp, #124] */
/* @0x1a65b4 beq 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0> */
/* @0x1a65b8 vldr s15, [sp, #100] */
/* @0x1a65bc vldr s14, [sp, #104] */
/* @0x1a65c0 vldr s12, [sp, #108] */
/* @0x1a65c4 vldr s5, [sp, #112] */
/* @0x1a65c8 vsub.f32 s13, s5, s14 */
/* @0x1a65cc vldr s7, [sp, #116] */
/* @0x1a65d0 vmul.f32 s13, s13, s13 */
/* @0x1a65d4 vsub.f32 s11, s7, s15 */
/* @0x1a65d8 vadd.f32 s8, s15, s7 */
/* @0x1a65dc vadd.f32 s9, s14, s5 */
/* @0x1a65e0 vldr s5, [sp, #124] */
/* @0x1a65e4 vadd.f32 s10, s12, s5 */
/* @0x1a65e8 vmla.f32 s13, s11, s11 */
/* @0x1a65ec vldr s11, [sp, #112] */
/* @0x1a65f0 vadd.f32 s6, s7, s8 */
/* @0x1a65f4 vadd.f32 s7, s11, s9 */
/* @0x1a65f8 vadd.f32 s11, s5, s10 */
/* @0x1a65fc vldr s5, [sp, #128] */
/* @0x1a6600 vadd.f32 s6, s5, s6 */
/* @0x1a6604 vldr s5, [sp, #120] */
/* @0x1a6608 vadd.f32 s7, s5, s7 */
/* @0x1a660c vldr s5, [sp, #132] */
/* @0x1a6610 vadd.f32 s11, s5, s11 */
/* @0x1a6614 vmul.f32 s6, s6, s28 */
/* @0x1a6618 vmul.f32 s7, s7, s28 */
/* @0x1a661c vstr s6, [sp, #100] */
/* @0x1a6620 vmul.f32 s11, s11, s28 */
/* @0x1a6624 vstr s7, [sp, #104] */
/* @0x1a6628 vcmpe.f32 s13, s30 */
/* @0x1a662c vstr s11, [sp, #108] */
/* @0x1a6630 vmrs APSR_nzcv, fpscr */
/* @0x1a6634 ble 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc> */
/* @0x1a6638 vmul.f32 s8, s8, s31 */
/* @0x1a663c cmp r10, #0 */
/* @0x1a6640 mov r9, r10 */
/* @0x1a6644 vmul.f32 s9, s9, s31 */
/* @0x1a6648 vstr s8, [sp, #92] */
/* @0x1a664c vmul.f32 s10, s10, s31 */
/* @0x1a6650 vstr s9, [sp, #88] */
/* @0x1a6654 vstr s10, [sp, #96] */
/* @0x1a6658 bne 0x1a66f0 <_ZN5CPath11HandlePieceEifffffffff+0x59c> */
/* @0x1a665c b 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc> */
/* @0x1a6660 mov r0, r5 */
/* @0x1a6664 ldr r1, [sp, #0x4c] */
/* @0x1a6668 ldr r2, [sp, #0x50] */
/* @0x1a666c ldr r3, [sp, #0x54] */
/* @0x1a6670 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6674 vldr s7, [sp, #88] */
/* @0x1a6678 vldr s8, [sp, #104] */
/* @0x1a667c vsub.f32 s15, s7, s8 */
/* @0x1a6680 vldr s9, [sp, #92] */
/* @0x1a6684 vldr s10, [sp, #100] */
/* @0x1a6688 vmul.f32 s15, s15, s15 */
/* @0x1a668c vsub.f32 s14, s9, s10 */
/* @0x1a6690 vmla.f32 s15, s14, s14 */
/* @0x1a6694 vcmpe.f32 s15, s30 */
/* @0x1a6698 vmrs APSR_nzcv, fpscr */
/* @0x1a669c ble 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc> */
/* @0x1a66a0 vldr s9, [sp, #92] */
/* @0x1a66a4 vldr s11, [sp, #88] */
/* @0x1a66a8 vldr s5, [sp, #96] */
/* @0x1a66ac vldr s8, [sp, #100] */
/* @0x1a66b0 vldr s10, [sp, #104] */
/* @0x1a66b4 vadd.f32 s13, s8, s9 */
/* @0x1a66b8 vldr s12, [sp, #108] */
/* @0x1a66bc subs r9, r9, #1 */
/* @0x1a66c0 vadd.f32 s14, s10, s11 */
/* @0x1a66c4 vadd.f32 s15, s12, s5 */
/* @0x1a66c8 vmul.f32 s13, s13, s31 */
/* @0x1a66cc vmul.f32 s14, s14, s31 */
/* @0x1a66d0 vstr s13, [sp, #92] */
/* @0x1a66d4 vmul.f32 s15, s15, s31 */
/* @0x1a66d8 vstr s14, [sp, #88] */
/* @0x1a66dc vstr s15, [sp, #96] */
/* @0x1a66e0 beq 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc> */
/* @0x1a66e4 vldr s15, [sp, #76] */
/* @0x1a66e8 vldr s14, [sp, #80] */
/* @0x1a66ec vldr s12, [sp, #84] */
/* @0x1a66f0 vldr s11, [sp, #88] */
/* @0x1a66f4 vsub.f32 s13, s11, s14 */
/* @0x1a66f8 vldr s5, [sp, #92] */
/* @0x1a66fc vldr s7, [sp, #88] */
/* @0x1a6700 vmul.f32 s13, s13, s13 */
/* @0x1a6704 vsub.f32 s11, s5, s15 */
/* @0x1a6708 vadd.f32 s8, s15, s5 */
/* @0x1a670c vldr s5, [sp, #96] */
/* @0x1a6710 vadd.f32 s9, s14, s7 */
/* @0x1a6714 vldr s7, [sp, #92] */
/* @0x1a6718 vadd.f32 s10, s12, s5 */
/* @0x1a671c vmla.f32 s13, s11, s11 */
/* @0x1a6720 vldr s11, [sp, #88] */
/* @0x1a6724 vadd.f32 s6, s7, s8 */
/* @0x1a6728 vadd.f32 s7, s11, s9 */
/* @0x1a672c vadd.f32 s11, s5, s10 */
/* @0x1a6730 vldr s5, [sp, #100] */
/* @0x1a6734 vadd.f32 s6, s5, s6 */
/* @0x1a6738 vldr s5, [sp, #104] */
/* @0x1a673c vadd.f32 s7, s5, s7 */
/* @0x1a6740 vldr s5, [sp, #108] */
/* @0x1a6744 vadd.f32 s11, s5, s11 */
/* @0x1a6748 vmul.f32 s6, s6, s28 */
/* @0x1a674c vmul.f32 s7, s7, s28 */
/* @0x1a6750 vstr s6, [sp, #76] */
/* @0x1a6754 vmul.f32 s11, s11, s28 */
/* @0x1a6758 vstr s7, [sp, #80] */
/* @0x1a675c vcmpe.f32 s13, s30 */
/* @0x1a6760 vstr s11, [sp, #84] */
/* @0x1a6764 vmrs APSR_nzcv, fpscr */
/* @0x1a6768 ble 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c> */
/* @0x1a676c vmul.f32 s8, s8, s31 */
/* @0x1a6770 cmp r9, #1 */
/* @0x1a6774 vmul.f32 s9, s9, s31 */
/* @0x1a6778 vstr s8, [sp, #64] */
/* @0x1a677c vmul.f32 s10, s10, s31 */
/* @0x1a6780 vstr s9, [sp, #68] */
/* @0x1a6784 vstr s10, [sp, #72] */
/* @0x1a6788 beq 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c> */
/* @0x1a678c sub r8, r9, #2 */
/* @0x1a6790 b 0x1a6828 <_ZN5CPath11HandlePieceEifffffffff+0x6d4> */
/* @0x1a6794 mov r0, r5 */
/* @0x1a6798 ldr r1, [sp, #0x34] */
/* @0x1a679c ldr r2, [sp, #0x38] */
/* @0x1a67a0 ldr r3, [sp, #0x3c] */
/* @0x1a67a4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a67a8 vldr s7, [sp, #68] */
/* @0x1a67ac vldr s8, [sp, #80] */
/* @0x1a67b0 vsub.f32 s15, s7, s8 */
/* @0x1a67b4 vldr s9, [sp, #64] */
/* @0x1a67b8 vldr s10, [sp, #76] */
/* @0x1a67bc vmul.f32 s15, s15, s15 */
/* @0x1a67c0 vsub.f32 s14, s9, s10 */
/* @0x1a67c4 vmla.f32 s15, s14, s14 */
/* @0x1a67c8 vcmpe.f32 s15, s30 */
/* @0x1a67cc vmrs APSR_nzcv, fpscr */
/* @0x1a67d0 ble 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c> */
/* @0x1a67d4 vldr s10, [sp, #64] */
/* @0x1a67d8 vldr s12, [sp, #68] */
/* @0x1a67dc vldr s7, [sp, #72] */
/* @0x1a67e0 vldr s9, [sp, #76] */
/* @0x1a67e4 vldr s11, [sp, #80] */
/* @0x1a67e8 vadd.f32 s13, s9, s10 */
/* @0x1a67ec vldr s5, [sp, #84] */
/* @0x1a67f0 cmp r8, #0 */
/* @0x1a67f4 sub r8, r8, #1 */
/* @0x1a67f8 vadd.f32 s14, s11, s12 */
/* @0x1a67fc vadd.f32 s15, s5, s7 */
/* @0x1a6800 vmul.f32 s13, s13, s31 */
/* @0x1a6804 vmul.f32 s14, s14, s31 */
/* @0x1a6808 vstr s13, [sp, #64] */
/* @0x1a680c vmul.f32 s15, s15, s31 */
/* @0x1a6810 vstr s14, [sp, #68] */
/* @0x1a6814 vstr s15, [sp, #72] */
/* @0x1a6818 beq 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c> */
/* @0x1a681c vldr s15, [sp, #52] */
/* @0x1a6820 vldr s12, [sp, #60] */
/* @0x1a6824 vldr s14, [sp, #56] */
/* @0x1a6828 vldr s11, [sp, #68] */
/* @0x1a682c vsub.f32 s13, s11, s14 */
/* @0x1a6830 vldr s5, [sp, #64] */
/* @0x1a6834 vldr s7, [sp, #68] */
/* @0x1a6838 vmul.f32 s13, s13, s13 */
/* @0x1a683c vsub.f32 s11, s5, s15 */
/* @0x1a6840 vadd.f32 s8, s15, s5 */
/* @0x1a6844 vldr s5, [sp, #72] */
/* @0x1a6848 vadd.f32 s9, s14, s7 */
/* @0x1a684c vldr s7, [sp, #64] */
/* @0x1a6850 vadd.f32 s10, s12, s5 */
/* @0x1a6854 vmla.f32 s13, s11, s11 */
/* @0x1a6858 vldr s11, [sp, #68] */
/* @0x1a685c vadd.f32 s6, s7, s8 */
/* @0x1a6860 vadd.f32 s7, s11, s9 */
/* @0x1a6864 vadd.f32 s11, s5, s10 */
/* @0x1a6868 vldr s5, [sp, #76] */
/* @0x1a686c vadd.f32 s6, s5, s6 */
/* @0x1a6870 vldr s5, [sp, #80] */
/* @0x1a6874 vadd.f32 s7, s5, s7 */
/* @0x1a6878 vldr s5, [sp, #84] */
/* @0x1a687c vadd.f32 s11, s5, s11 */
/* @0x1a6880 vmul.f32 s6, s6, s28 */
/* @0x1a6884 vmul.f32 s7, s7, s28 */
/* @0x1a6888 vstr s6, [sp, #52] */
/* @0x1a688c vmul.f32 s11, s11, s28 */
/* @0x1a6890 vstr s7, [sp, #56] */
/* @0x1a6894 vcmpe.f32 s13, s30 */
/* @0x1a6898 vstr s11, [sp, #60] */
/* @0x1a689c vmrs APSR_nzcv, fpscr */
/* @0x1a68a0 ble 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640> */
/* @0x1a68a4 vmul.f32 s8, s8, s31 */
/* @0x1a68a8 cmp r8, #0 */
/* @0x1a68ac mov r7, r8 */
/* @0x1a68b0 vmul.f32 s9, s9, s31 */
/* @0x1a68b4 vstr s8, [sp, #40] */
/* @0x1a68b8 vmul.f32 s10, s10, s31 */
/* @0x1a68bc vstr s9, [sp, #44] */
/* @0x1a68c0 vstr s10, [sp, #48] */
/* @0x1a68c4 bne 0x1a695c <_ZN5CPath11HandlePieceEifffffffff+0x808> */
/* @0x1a68c8 b 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640> */
/* @0x1a68cc mov r0, r5 */
/* @0x1a68d0 ldr r1, [sp, #0x20] */
/* @0x1a68d4 vmov r2, s29 */
/* @0x1a68d8 ldr r3, [sp, #0x24] */
/* @0x1a68dc bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a68e0 vldr s8, [sp, #44] */
/* @0x1a68e4 vldr s9, [sp, #56] */
/* @0x1a68e8 vsub.f32 s15, s8, s9 */
/* @0x1a68ec vldr s10, [sp, #40] */
/* @0x1a68f0 vldr s11, [sp, #52] */
/* @0x1a68f4 vmul.f32 s15, s15, s15 */
/* @0x1a68f8 vsub.f32 s14, s10, s11 */
/* @0x1a68fc vmla.f32 s15, s14, s14 */
/* @0x1a6900 vcmpe.f32 s15, s30 */
/* @0x1a6904 vmrs APSR_nzcv, fpscr */
/* @0x1a6908 ble 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640> */
/* @0x1a690c vldr s12, [sp, #40] */
/* @0x1a6910 vldr s15, [sp, #56] */
/* @0x1a6914 vldr s5, [sp, #44] */
/* @0x1a6918 vldr s8, [sp, #48] */
/* @0x1a691c vadd.f32 s14, s15, s5 */
/* @0x1a6920 vldr s11, [sp, #52] */
/* @0x1a6924 vldr s7, [sp, #60] */
/* @0x1a6928 subs r7, r7, #1 */
/* @0x1a692c vadd.f32 s13, s11, s12 */
/* @0x1a6930 vadd.f32 s15, s7, s8 */
/* @0x1a6934 vmul.f32 s13, s13, s31 */
/* @0x1a6938 vmul.f32 s14, s14, s31 */
/* @0x1a693c vstr s13, [sp, #40] */
/* @0x1a6940 vmul.f32 s15, s15, s31 */
/* @0x1a6944 vstr s14, [sp, #44] */
/* @0x1a6948 vstr s15, [sp, #48] */
/* @0x1a694c beq 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640> */
/* @0x1a6950 vmov.f32 s14, s29 */
/* @0x1a6954 vldr s12, [sp, #36] */
/* @0x1a6958 vldr s15, [sp, #32] */
/* @0x1a695c vldr s11, [sp, #44] */
/* @0x1a6960 vldr s5, [sp, #40] */
/* @0x1a6964 vsub.f32 s13, s11, s14 */
/* @0x1a6968 vldr s8, [sp, #48] */
/* @0x1a696c vldr s7, [sp, #44] */
/* @0x1a6970 vldr s9, [sp, #52] */
/* @0x1a6974 vmul.f32 s13, s13, s13 */
/* @0x1a6978 vsub.f32 s11, s5, s15 */
/* @0x1a697c vadd.f32 s25, s15, s5 */
/* @0x1a6980 vadd.f32 s27, s12, s8 */
/* @0x1a6984 vadd.f32 s26, s14, s7 */
/* @0x1a6988 vmla.f32 s13, s11, s11 */
/* @0x1a698c vadd.f32 s10, s5, s25 */
/* @0x1a6990 vldr s5, [sp, #56] */
/* @0x1a6994 vadd.f32 s11, s8, s27 */
/* @0x1a6998 vadd.f32 s29, s7, s26 */
/* @0x1a699c vldr s7, [sp, #60] */
/* @0x1a69a0 vadd.f32 s10, s9, s10 */
/* @0x1a69a4 vadd.f32 s11, s7, s11 */
/* @0x1a69a8 vmul.f32 s10, s10, s28 */
/* @0x1a69ac vmul.f32 s11, s11, s28 */
/* @0x1a69b0 vstr s10, [sp, #32] */
/* @0x1a69b4 vadd.f32 s29, s5, s29 */
/* @0x1a69b8 vstr s11, [sp, #36] */
/* @0x1a69bc vcmpe.f32 s13, s30 */
/* @0x1a69c0 vmul.f32 s29, s29, s28 */
/* @0x1a69c4 vmrs APSR_nzcv, fpscr */
/* @0x1a69c8 ble 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778> */
/* @0x1a69cc cmp r7, #1 */
/* @0x1a69d0 vmul.f32 s25, s25, s31 */
/* @0x1a69d4 vmul.f32 s26, s26, s31 */
/* @0x1a69d8 vmul.f32 s27, s27, s31 */
/* @0x1a69dc beq 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778> */
/* @0x1a69e0 sub r6, r7, #2 */
/* @0x1a69e4 b 0x1a6a54 <_ZN5CPath11HandlePieceEifffffffff+0x900> */
/* @0x1a69e8 mov r0, r5 */
/* @0x1a69ec vmov r1, s19 */
/* @0x1a69f0 vmov r2, s20 */
/* @0x1a69f4 vmov r3, s24 */
/* @0x1a69f8 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a69fc vsub.f32 s15, s26, s29 */
/* @0x1a6a00 vldr s8, [sp, #32] */
/* @0x1a6a04 vmul.f32 s15, s15, s15 */
/* @0x1a6a08 vsub.f32 s14, s25, s8 */
/* @0x1a6a0c vmla.f32 s15, s14, s14 */
/* @0x1a6a10 vcmpe.f32 s15, s30 */
/* @0x1a6a14 vmrs APSR_nzcv, fpscr */
/* @0x1a6a18 ble 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778> */
/* @0x1a6a1c vldr s9, [sp, #32] */
/* @0x1a6a20 vadd.f32 s26, s29, s26 */
/* @0x1a6a24 vldr s10, [sp, #36] */
/* @0x1a6a28 cmp r6, #0 */
/* @0x1a6a2c sub r6, r6, #1 */
/* @0x1a6a30 vadd.f32 s25, s9, s25 */
/* @0x1a6a34 vadd.f32 s27, s10, s27 */
/* @0x1a6a38 vmul.f32 s25, s25, s31 */
/* @0x1a6a3c vmul.f32 s26, s26, s31 */
/* @0x1a6a40 vmul.f32 s27, s27, s31 */
/* @0x1a6a44 beq 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778> */
/* @0x1a6a48 vmov.f32 s12, s24 */
/* @0x1a6a4c vmov.f32 s14, s20 */
/* @0x1a6a50 vmov.f32 s15, s19 */
/* @0x1a6a54 vldr s5, [sp, #32] */
/* @0x1a6a58 vldr s7, [sp, #36] */
/* @0x1a6a5c vsub.f32 s13, s26, s14 */
/* @0x1a6a60 vmul.f32 s13, s13, s13 */
/* @0x1a6a64 vsub.f32 s11, s25, s15 */
/* @0x1a6a68 vadd.f32 s17, s15, s25 */
/* @0x1a6a6c vadd.f32 s16, s14, s26 */
/* @0x1a6a70 vadd.f32 s18, s12, s27 */
/* @0x1a6a74 vmla.f32 s13, s11, s11 */
/* @0x1a6a78 vadd.f32 s19, s25, s17 */
/* @0x1a6a7c vadd.f32 s20, s26, s16 */
/* @0x1a6a80 vadd.f32 s24, s27, s18 */
/* @0x1a6a84 vadd.f32 s19, s5, s19 */
/* @0x1a6a88 vadd.f32 s20, s29, s20 */
/* @0x1a6a8c vadd.f32 s24, s7, s24 */
/* @0x1a6a90 vcmpe.f32 s13, s30 */
/* @0x1a6a94 vmul.f32 s19, s19, s28 */
/* @0x1a6a98 vmrs APSR_nzcv, fpscr */
/* @0x1a6a9c vmul.f32 s20, s20, s28 */
/* @0x1a6aa0 vmul.f32 s24, s24, s28 */
/* @0x1a6aa4 ble 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894> */
/* @0x1a6aa8 cmp r6, #0 */
/* @0x1a6aac mov r4, r6 */
/* @0x1a6ab0 vmul.f32 s17, s17, s31 */
/* @0x1a6ab4 vmul.f32 s16, s16, s31 */
/* @0x1a6ab8 vmul.f32 s18, s18, s31 */
/* @0x1a6abc bne 0x1a6b20 <_ZN5CPath11HandlePieceEifffffffff+0x9cc> */
/* @0x1a6ac0 b 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894> */
/* @0x1a6ac4 mov r0, r5 */
/* @0x1a6ac8 vmov r1, s21 */
/* @0x1a6acc vmov r2, s22 */
/* @0x1a6ad0 vmov r3, s23 */
/* @0x1a6ad4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6ad8 vsub.f32 s13, s16, s20 */
/* @0x1a6adc vmul.f32 s13, s13, s13 */
/* @0x1a6ae0 vsub.f32 s11, s17, s19 */
/* @0x1a6ae4 vmla.f32 s13, s11, s11 */
/* @0x1a6ae8 vcmpe.f32 s13, s30 */
/* @0x1a6aec vmov.f32 s12, s23 */
/* @0x1a6af0 vmrs APSR_nzcv, fpscr */
/* @0x1a6af4 vmov.f32 s14, s22 */
/* @0x1a6af8 vmov.f32 s15, s21 */
/* @0x1a6afc ble 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894> */
/* @0x1a6b00 subs r4, r4, #1 */
/* @0x1a6b04 vadd.f32 s17, s19, s17 */
/* @0x1a6b08 vadd.f32 s16, s20, s16 */
/* @0x1a6b0c vadd.f32 s18, s24, s18 */
/* @0x1a6b10 vmul.f32 s17, s17, s31 */
/* @0x1a6b14 vmul.f32 s16, s16, s31 */
/* @0x1a6b18 vmul.f32 s18, s18, s31 */
/* @0x1a6b1c beq 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894> */
/* @0x1a6b20 vsub.f32 s13, s16, s14 */
/* @0x1a6b24 vmul.f32 s13, s13, s13 */
/* @0x1a6b28 vsub.f32 s11, s17, s15 */
/* @0x1a6b2c vadd.f32 s8, s15, s17 */
/* @0x1a6b30 vadd.f32 s9, s14, s16 */
/* @0x1a6b34 vadd.f32 s10, s12, s18 */
/* @0x1a6b38 vmla.f32 s13, s11, s11 */
/* @0x1a6b3c vadd.f32 s21, s17, s8 */
/* @0x1a6b40 vadd.f32 s22, s16, s9 */
/* @0x1a6b44 vadd.f32 s23, s18, s10 */
/* @0x1a6b48 vadd.f32 s21, s19, s21 */
/* @0x1a6b4c vadd.f32 s22, s20, s22 */
/* @0x1a6b50 vadd.f32 s23, s24, s23 */
/* @0x1a6b54 vcmpe.f32 s13, s30 */
/* @0x1a6b58 vmul.f32 s21, s21, s28 */
/* @0x1a6b5c vmrs APSR_nzcv, fpscr */
/* @0x1a6b60 vmul.f32 s22, s22, s28 */
/* @0x1a6b64 vmul.f32 s23, s23, s28 */
/* @0x1a6b68 ble 0x1a6ac4 <_ZN5CPath11HandlePieceEifffffffff+0x970> */
/* @0x1a6b6c vstr s12, [sp] */
/* @0x1a6b70 vstr s21, [sp, #16] */
/* @0x1a6b74 vstr s22, [sp, #20] */
/* @0x1a6b78 mov r0, r5 */
/* @0x1a6b7c sub r1, r4, #1 */
/* @0x1a6b80 vmov r2, s15 */
/* @0x1a6b84 vmov r3, s14 */
/* @0x1a6b88 vstr s23, [sp, #24] */
/* @0x1a6b8c vmul.f32 s8, s8, s31 */
/* @0x1a6b90 vmul.f32 s9, s9, s31 */
/* @0x1a6b94 vstr s8, [sp, #4] */
/* @0x1a6b98 vmul.f32 s10, s10, s31 */
/* @0x1a6b9c vstr s9, [sp, #8] */
/* @0x1a6ba0 vstr s10, [sp, #12] */
/* @0x1a6ba4 bl 0x1a6154 <_ZN5CPath11HandlePieceEifffffffff> */
/* @0x1a6ba8 b 0x1a6ac4 <_ZN5CPath11HandlePieceEifffffffff+0x970> */
/* @0x1a6bac add sp, sp, #196 */
/* @0x1a6bb0 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a6bb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1a6bb8 · CPath::ComputeCurved() · size=632 · insn=158 */
/* @0x1a6bb8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a6bbc vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a6bc0 mov r3, #0 */
/* @0x1a6bc4 ldr r7, [r0, #0x10] */
/* @0x1a6bc8 sub sp, sp, #36 */
/* @0x1a6bcc mov r5, r0 */
/* @0x1a6bd0 str r3, [r0, #0x20] */
/* @0x1a6bd4 cmp r7, r3 */
/* @0x1a6bd8 ble 0x1a6e24 <_ZN5CPath13ComputeCurvedEv+0x26c> */
/* @0x1a6bdc ldrb r3, [r0, #0x18] */
/* @0x1a6be0 cmp r3, #0 */
/* @0x1a6be4 beq 0x1a6df8 <_ZN5CPath13ComputeCurvedEv+0x240> */
/* @0x1a6be8 sub r11, r7, #1 */
/* @0x1a6bec cmp r11, #0 */
/* @0x1a6bf0 blt 0x1a6dac <_ZN5CPath13ComputeCurvedEv+0x1f4> */
/* @0x1a6bf4 vmov.f32 s18, #5.000000e-01 */
/* @0x1a6bf8 mov r10, #0 */
/* @0x1a6bfc mov r6, #1 */
/* @0x1a6c00 vmov.f32 s26, #2.500000e-01 */
/* @0x1a6c04 vmov.f32 s29, #1.600000e+01 */
/* @0x1a6c08 mov r0, r10 */
/* @0x1a6c0c mov r1, r7 */
/* @0x1a6c10 bl 0x318dec <__aeabi_idivmod> */
/* @0x1a6c14 mov r0, r6 */
/* @0x1a6c18 mov r10, r6 */
/* @0x1a6c1c add r6, r6, #1 */
/* @0x1a6c20 ldr r8, [r5, #0x4] */
/* @0x1a6c24 ldr r4, [r5, #0x1c] */
/* @0x1a6c28 add r9, r1, r1, lsl #1 */
/* @0x1a6c2c mov r1, r7 */
/* @0x1a6c30 bl 0x318dec <__aeabi_idivmod> */
/* @0x1a6c34 mov r0, r6 */
/* @0x1a6c38 add r9, r8, r9, lsl #2 */
/* @0x1a6c3c vldr s21, [r9] */
/* @0x1a6c40 vldr s20, [r9, #4] */
/* @0x1a6c44 vldr s27, [r9, #8] */
/* @0x1a6c48 add r3, r1, r1, lsl #1 */
/* @0x1a6c4c mov r1, r7 */
/* @0x1a6c50 add r3, r8, r3, lsl #2 */
/* @0x1a6c54 vldr s17, [r3] */
/* @0x1a6c58 vldr s16, [r3, #4] */
/* @0x1a6c5c vldr s19, [r3, #8] */
/* @0x1a6c60 bl 0x318dec <__aeabi_idivmod> */
/* @0x1a6c64 vadd.f32 s21, s17, s21 */
/* @0x1a6c68 cmp r4, #0 */
/* @0x1a6c6c vadd.f32 s20, s16, s20 */
/* @0x1a6c70 vadd.f32 s27, s19, s27 */
/* @0x1a6c74 vmul.f32 s21, s21, s18 */
/* @0x1a6c78 add r1, r1, r1, lsl #1 */
/* @0x1a6c7c add r8, r8, r1, lsl #2 */
/* @0x1a6c80 vldr s25, [r8] */
/* @0x1a6c84 vldr s24, [r8, #4] */
/* @0x1a6c88 vldr s28, [r8, #8] */
/* @0x1a6c8c vadd.f32 s25, s17, s25 */
/* @0x1a6c90 vadd.f32 s24, s16, s24 */
/* @0x1a6c94 vadd.f32 s28, s19, s28 */
/* @0x1a6c98 vmul.f32 s20, s20, s18 */
/* @0x1a6c9c vmul.f32 s27, s27, s18 */
/* @0x1a6ca0 vmul.f32 s25, s25, s18 */
/* @0x1a6ca4 vmul.f32 s24, s24, s18 */
/* @0x1a6ca8 vmul.f32 s28, s28, s18 */
/* @0x1a6cac bne 0x1a6d10 <_ZN5CPath13ComputeCurvedEv+0x158> */
/* @0x1a6cb0 b 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4> */
/* @0x1a6cb4 mov r0, r5 */
/* @0x1a6cb8 vmov r1, s23 */
/* @0x1a6cbc vmov r2, s30 */
/* @0x1a6cc0 vmov r3, s22 */
/* @0x1a6cc4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6cc8 vsub.f32 s15, s16, s24 */
/* @0x1a6ccc vmul.f32 s15, s15, s15 */
/* @0x1a6cd0 vsub.f32 s14, s17, s25 */
/* @0x1a6cd4 vmla.f32 s15, s14, s14 */
/* @0x1a6cd8 vcmpe.f32 s15, s29 */
/* @0x1a6cdc vmov.f32 s20, s30 */
/* @0x1a6ce0 vmrs APSR_nzcv, fpscr */
/* @0x1a6ce4 vmov.f32 s21, s23 */
/* @0x1a6ce8 vmov.f32 s27, s22 */
/* @0x1a6cec ble 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4> */
/* @0x1a6cf0 subs r4, r4, #1 */
/* @0x1a6cf4 vadd.f32 s17, s25, s17 */
/* @0x1a6cf8 vadd.f32 s16, s24, s16 */
/* @0x1a6cfc vadd.f32 s19, s28, s19 */
/* @0x1a6d00 vmul.f32 s17, s17, s18 */
/* @0x1a6d04 vmul.f32 s16, s16, s18 */
/* @0x1a6d08 vmul.f32 s19, s19, s18 */
/* @0x1a6d0c beq 0x1a6d9c <_ZN5CPath13ComputeCurvedEv+0x1e4> */
/* @0x1a6d10 vsub.f32 s15, s16, s20 */
/* @0x1a6d14 vmul.f32 s15, s15, s15 */
/* @0x1a6d18 vsub.f32 s14, s17, s21 */
/* @0x1a6d1c vadd.f32 s11, s21, s17 */
/* @0x1a6d20 vadd.f32 s12, s20, s16 */
/* @0x1a6d24 vadd.f32 s13, s27, s19 */
/* @0x1a6d28 vmla.f32 s15, s14, s14 */
/* @0x1a6d2c vadd.f32 s23, s17, s11 */
/* @0x1a6d30 vadd.f32 s30, s16, s12 */
/* @0x1a6d34 vadd.f32 s22, s19, s13 */
/* @0x1a6d38 vadd.f32 s23, s25, s23 */
/* @0x1a6d3c vadd.f32 s30, s24, s30 */
/* @0x1a6d40 vadd.f32 s22, s28, s22 */
/* @0x1a6d44 vcmpe.f32 s15, s29 */
/* @0x1a6d48 vmul.f32 s23, s23, s26 */
/* @0x1a6d4c vmrs APSR_nzcv, fpscr */
/* @0x1a6d50 vmul.f32 s30, s30, s26 */
/* @0x1a6d54 vmul.f32 s22, s22, s26 */
/* @0x1a6d58 ble 0x1a6cb4 <_ZN5CPath13ComputeCurvedEv+0xfc> */
/* @0x1a6d5c vstr s27, [sp] */
/* @0x1a6d60 vstr s23, [sp, #16] */
/* @0x1a6d64 vstr s30, [sp, #20] */
/* @0x1a6d68 mov r0, r5 */
/* @0x1a6d6c sub r1, r4, #1 */
/* @0x1a6d70 vmov r2, s21 */
/* @0x1a6d74 vmov r3, s20 */
/* @0x1a6d78 vstr s22, [sp, #24] */
/* @0x1a6d7c vmul.f32 s11, s11, s18 */
/* @0x1a6d80 vmul.f32 s12, s12, s18 */
/* @0x1a6d84 vstr s11, [sp, #4] */
/* @0x1a6d88 vmul.f32 s13, s13, s18 */
/* @0x1a6d8c vstr s12, [sp, #8] */
/* @0x1a6d90 vstr s13, [sp, #12] */
/* @0x1a6d94 bl 0x1a6154 <_ZN5CPath11HandlePieceEifffffffff> */
/* @0x1a6d98 b 0x1a6cb4 <_ZN5CPath13ComputeCurvedEv+0xfc> */
/* @0x1a6d9c cmp r11, r10 */
/* @0x1a6da0 ldrge r7, [r5, #0x10] */
/* @0x1a6da4 bge 0x1a6c08 <_ZN5CPath13ComputeCurvedEv+0x50> */
/* @0x1a6da8 ldrb r3, [r5, #0x18] */
/* @0x1a6dac cmp r3, #0 */
/* @0x1a6db0 beq 0x1a6dd8 <_ZN5CPath13ComputeCurvedEv+0x220> */
/* @0x1a6db4 ldr r3, [r5, #0xc] */
/* @0x1a6db8 mov r0, r5 */
/* @0x1a6dbc ldr r1, [r3] */
/* @0x1a6dc0 ldr r2, [r3, #0x4] */
/* @0x1a6dc4 ldr r3, [r3, #0x8] */
/* @0x1a6dc8 add sp, sp, #36 */
/* @0x1a6dcc vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a6dd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1a6dd4 b 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6dd8 ldr r2, [r5, #0x10] */
/* @0x1a6ddc mov r0, r5 */
/* @0x1a6de0 ldr r1, [r5, #0x4] */
/* @0x1a6de4 add r2, r2, r2, lsl #1 */
/* @0x1a6de8 lsl r3, r2, #2 */
/* @0x1a6dec sub r3, r3, #12 */
/* @0x1a6df0 add r3, r1, r3 */
/* @0x1a6df4 b 0x1a6dbc <_ZN5CPath13ComputeCurvedEv+0x204> */
/* @0x1a6df8 ldr r3, [r0, #0x4] */
/* @0x1a6dfc ldr r1, [r3] */
/* @0x1a6e00 ldr r2, [r3, #0x4] */
/* @0x1a6e04 ldr r3, [r3, #0x8] */
/* @0x1a6e08 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff> */
/* @0x1a6e0c ldrb r3, [r5, #0x18] */
/* @0x1a6e10 ldr r7, [r5, #0x10] */
/* @0x1a6e14 cmp r3, #0 */
/* @0x1a6e18 subeq r11, r7, #3 */
/* @0x1a6e1c beq 0x1a6bec <_ZN5CPath13ComputeCurvedEv+0x34> */
/* @0x1a6e20 b 0x1a6be8 <_ZN5CPath13ComputeCurvedEv+0x30> */
/* @0x1a6e24 add sp, sp, #36 */
/* @0x1a6e28 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1a6e2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x1a6e30 · CPath::ComputeInternal() · size=52 · insn=13 */
/* @0x1a6e30 ldr r3, [r0, #0x14] */
/* @0x1a6e34 push {r4, lr} */
/* @0x1a6e38 cmp r3, #1 */
/* @0x1a6e3c mov r4, r0 */
/* @0x1a6e40 beq 0x1a6e54 <_ZN5CPath15ComputeInternalEv+0x24> */
/* @0x1a6e44 bl 0x1a60dc <_ZN5CPath13ComputeLinearEv> */
/* @0x1a6e48 mov r0, r4 */
/* @0x1a6e4c pop {r4, lr} */
/* @0x1a6e50 b 0x1a5f78 <_ZN5CPath13ComputeLengthEv> */
/* @0x1a6e54 bl 0x1a6bb8 <_ZN5CPath13ComputeCurvedEv> */
/* @0x1a6e58 mov r0, r4 */
/* @0x1a6e5c pop {r4, lr} */
/* @0x1a6e60 b 0x1a5f78 <_ZN5CPath13ComputeLengthEv> */

/* ── FUNC 0x1a6e64 · CPath::SetKind(int) · size=20 · insn=5 */
/* @0x1a6e64 cmp r1, #1 */
/* @0x1a6e68 strls r1, [r0, #0x14] */
/* @0x1a6e6c movhi r3, #0 */
/* @0x1a6e70 strhi r3, [r0, #0x14] */
/* @0x1a6e74 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */

/* ── FUNC 0x1a6e78 · CPath::SetClosed(bool) · size=8 · insn=2 */
/* @0x1a6e78 strb r1, [r0, #0x18] */
/* @0x1a6e7c b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */

/* ── FUNC 0x1a6e80 · CPath::SetPrecision(int) · size=28 · insn=7 */
/* @0x1a6e80 cmp r1, #0 */
/* @0x1a6e84 movlt r1, #0 */
/* @0x1a6e88 blt 0x1a6e94 <_ZN5CPath12SetPrecisionEi+0x14> */
/* @0x1a6e8c cmp r1, #8 */
/* @0x1a6e90 movge r1, #8 */
/* @0x1a6e94 str r1, [r0, #0x1c] */
/* @0x1a6e98 b 0x1a6e30 <_ZN5CPath15ComputeInternalEv> */
