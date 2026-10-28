/* libyoyo.so 覆盖卡组 0105
 * 函数 0x168a08..0x169f08，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x168a08 · GR_D3D_Get_Texture_Repeat_Ext(int) · size=36 · insn=9 */
/* @0x168a08 cmp r0, #7 */
/* @0x168a0c bhi 0x168a20 <_Z29GR_D3D_Get_Texture_Repeat_Exti+0x18> */
/* @0x168a10 ldr r3, [pc, #0x10] */
/* @0x168a14 ldr r3, [pc, r3] */
/* @0x168a18 ldrb r0, [r3, r0] */
/* @0x168a1c bx lr */
/* @0x168a20 mov r0, #0 */
/* @0x168a24 bx lr */
/* @0x168a28 .word 0x002876f8 */

/* ── FUNC 0x168a2c · GR_D3D_Get_Texture_Interpolation_Ext(int) · size=36 · insn=9 */
/* @0x168a2c cmp r0, #7 */
/* @0x168a30 bhi 0x168a44 <_Z36GR_D3D_Get_Texture_Interpolation_Exti+0x18> */
/* @0x168a34 ldr r3, [pc, #0x10] */
/* @0x168a38 ldr r3, [pc, r3] */
/* @0x168a3c ldrb r0, [r3, r0] */
/* @0x168a40 bx lr */
/* @0x168a44 mov r0, #1 */
/* @0x168a48 bx lr */
/* @0x168a4c .word 0x002876d0 */

/* ── FUNC 0x168a50 · GR_D3D_Settings_Init() · size=276 · insn=69 */
/* @0x168a50 push {r3, r4, r5, r6, r7, lr} */
/* @0x168a54 ldr r4, [pc, #0xdc] */
/* @0x168a58 ldr r3, [pc, #0xdc] */
/* @0x168a5c add r4, pc, r4 */
/* @0x168a60 ldr r3, [r4, r3] */
/* @0x168a64 ldrb r3, [r3] */
/* @0x168a68 cmp r3, #0 */
/* @0x168a6c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x168a70 ldr r3, [pc, #0xc8] */
/* @0x168a74 mov r7, #0 */
/* @0x168a78 ldr r6, [r4, r3] */
/* @0x168a7c str r7, [r6] */
/* @0x168a80 bl 0x1804ac <_ZN8Graphics11ResetBlendsEv> */
/* @0x168a84 ldr r3, [pc, #0xb8] */
/* @0x168a88 mov r1, #12 */
/* @0x168a8c mov r2, #1 */
/* @0x168a90 ldr r5, [r4, r3] */
/* @0x168a94 mov r0, r5 */
/* @0x168a98 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej> */
/* @0x168a9c ldr r3, [pc, #0xa4] */
/* @0x168aa0 ldr r3, [r4, r3] */
/* @0x168aa4 ldrb r0, [r3] */
/* @0x168aa8 bl 0x16841c <_Z10SetZBufferb> */
/* @0x168aac ldr r1, [pc, #0x98] */
/* @0x168ab0 ldr r2, [pc, #0x98] */
/* @0x168ab4 ldr r3, [pc, #0x98] */
/* @0x168ab8 ldr r1, [r4, r1] */
/* @0x168abc vldr s15, [r1] */
/* @0x168ac0 vcvt.s32.f32 s15, s15 */
/* @0x168ac4 ldr r1, [r4, r2] */
/* @0x168ac8 ldr r3, [r4, r3] */
/* @0x168acc ldrb r0, [r3] */
/* @0x168ad0 vmov r2, s15 */
/* @0x168ad4 vldr s15, [r1] */
/* @0x168ad8 vcvt.s32.f32 s15, s15 */
/* @0x168adc ldr r1, [pc, #0x74] */
/* @0x168ae0 ldr r1, [r4, r1] */
/* @0x168ae4 ldr r1, [r1] */
/* @0x168ae8 vmov r3, s15 */
/* @0x168aec sxth r2, r2 */
/* @0x168af0 sxth r3, r3 */
/* @0x168af4 bl 0x168520 <_Z14GR_D3D_Set_Fogbjss> */
/* @0x168af8 mov r1, r7 */
/* @0x168afc ldr r0, [r6] */
/* @0x168b00 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x168b04 ldr r3, [pc, #0x50] */
/* @0x168b08 ldr r3, [r4, r3] */
/* @0x168b0c ldrb r0, [r3] */
/* @0x168b10 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb> */
/* @0x168b14 mov r0, #1 */
/* @0x168b18 bl 0x1689c8 <_Z27GR_D3D_Set_Texture_Blendingb> */
/* @0x168b1c ldr r3, [pc, #0x3c] */
/* @0x168b20 ldr r3, [r4, r3] */
/* @0x168b24 ldrb r0, [r3] */
/* @0x168b28 bl 0x168870 <_Z25GR_D3D_Set_Texture_Repeatb> */
/* @0x168b2c mov r0, r5 */
/* @0x168b30 pop {r3, r4, r5, r6, r7, lr} */
/* @0x168b34 b 0x168294 <_ZN18RenderStateManager5ForceEv> */
/* @0x168b38 .word 0x002891f4 */
/* @0x168b3c .word 0xffffe4d0 */
/* @0x168b40 .word 0xffffe4d4 */
/* @0x168b44 .word 0xffffc0a8 */
/* @0x168b48 .word 0xffffe4b4 */
/* @0x168b4c .word 0xffffe4c8 */
/* @0x168b50 .word 0xffffe4cc */
/* @0x168b54 .word 0xffffe4c0 */
/* @0x168b58 .word 0xffffe4c4 */
/* @0x168b5c .word 0xffffe4d8 */
/* @0x168b60 .word 0xffffe4bc */

/* ── FUNC 0x168b64 · _CreateBlankTexture() · size=124 · insn=31 */
/* @0x168b64 push {r4, lr} */
/* @0x168b68 sub sp, sp, #8 */
/* @0x168b6c ldr r4, [pc, #0x60] */
/* @0x168b70 ldr r4, [pc, r4] */
/* @0x168b74 ldr r3, [r4] */
/* @0x168b78 cmn r3, #1 */
/* @0x168b7c beq 0x168b88 <_Z19_CreateBlankTexturev+0x24> */
/* @0x168b80 add sp, sp, #8 */
/* @0x168b84 pop {r4, pc} */
/* @0x168b88 add r2, sp, #8 */
/* @0x168b8c mov r0, #1 */
/* @0x168b90 mov r1, r0 */
/* @0x168b94 str r3, [r2, #-0x4]! */
/* @0x168b98 mov r3, #4 */
/* @0x168b9c bl 0x173c18 <_Z26GR_Texture_Create_And_FilliiPhj> */
/* @0x168ba0 str r0, [r4] */
/* @0x168ba4 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x168ba8 cmp r0, #0 */
/* @0x168bac beq 0x168b80 <_Z19_CreateBlankTexturev+0x1c> */
/* @0x168bb0 ldr r2, [pc, #0x20] */
/* @0x168bb4 ldr r1, [r4] */
/* @0x168bb8 ldr r2, [pc, r2] */
/* @0x168bbc ldr r3, [pc, #0x18] */
/* @0x168bc0 ldr r2, [r2, #0x4] */
/* @0x168bc4 ldr r3, [pc, r3] */
/* @0x168bc8 ldr r2, [r2, r1, lsl #2] */
/* @0x168bcc str r2, [r3] */
/* @0x168bd0 b 0x168b80 <_Z19_CreateBlankTexturev+0x1c> */
/* @0x168bd4 .word 0x002875bc */
/* @0x168bd8 eoreq r4, r8, r4, ror #26 */
/* @0x168bdc eoreq r7, r8, r12, ror #10 */

/* ── FUNC 0x168be0 · _DestroyBlankTexture() · size=64 · insn=16 */
/* @0x168be0 push {r4, lr} */
/* @0x168be4 ldr r4, [pc, #0x2c] */
/* @0x168be8 ldr r4, [pc, r4] */
/* @0x168bec ldr r0, [r4] */
/* @0x168bf0 cmn r0, #1 */
/* @0x168bf4 popeq {r4, pc} */
/* @0x168bf8 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0x168bfc ldr r3, [pc, #0x18] */
/* @0x168c00 mov r2, #0 */
/* @0x168c04 mvn r1, #0 */
/* @0x168c08 ldr r3, [pc, r3] */
/* @0x168c0c str r1, [r4] */
/* @0x168c10 str r2, [r3] */
/* @0x168c14 pop {r4, pc} */
/* @0x168c18 eoreq r7, r8, r4, asr #10 */
/* @0x168c1c eoreq r7, r8, r8, lsr #10 */

/* ── FUNC 0x168c20 · GR_D3D_PartialReset() · size=4 · insn=1 */
/* @0x168c20 b 0x17dd50 <_ZN8Graphics16UpdateWindowSizeEv> */

/* ── FUNC 0x168c24 · GR_D3D_Reset() · size=108 · insn=27 */
/* @0x168c24 push {r4, lr} */
/* @0x168c28 bl 0x171c64 <_Z18GR_Surface_FreeAllv> */
/* @0x168c2c bl 0x17dd48 <_ZN8Graphics13GraphicsResetEv> */
/* @0x168c30 subs r4, r0, #0 */
/* @0x168c34 bne 0x168c40 <_Z12GR_D3D_Resetv+0x1c> */
/* @0x168c38 mov r0, r4 */
/* @0x168c3c pop {r4, pc} */
/* @0x168c40 mov r0, #0 */
/* @0x168c44 mov r3, #7 */
/* @0x168c48 mov r1, #1065353216 */
/* @0x168c4c mov r2, r0 */
/* @0x168c50 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x168c54 ldr r3, [pc, #0x2c] */
/* @0x168c58 ldr r3, [pc, r3] */
/* @0x168c5c ldrb r3, [r3] */
/* @0x168c60 cmp r3, #0 */
/* @0x168c64 beq 0x168c7c <_Z12GR_D3D_Resetv+0x58> */
/* @0x168c68 ldr r0, [pc, #0x1c] */
/* @0x168c6c ldr r0, [pc, r0] */
/* @0x168c70 bl 0x168294 <_ZN18RenderStateManager5ForceEv> */
/* @0x168c74 mov r0, r4 */
/* @0x168c78 pop {r4, pc} */
/* @0x168c7c bl 0x168a50 <_Z20GR_D3D_Settings_Initv> */
/* @0x168c80 mov r0, r4 */
/* @0x168c84 pop {r4, pc} */
/* @0x168c88 eoreq r4, r8, r12, asr #25 */
/* @0x168c8c eoreq r5, r8, r12, lsl #1 */

/* ── FUNC 0x168c90 · GR_D3D_End() · size=28 · insn=7 */
/* @0x168c90 push {r3, lr} */
/* @0x168c94 bl 0x168be0 <_Z20_DestroyBlankTexturev> */
/* @0x168c98 bl 0x171c64 <_Z18GR_Surface_FreeAllv> */
/* @0x168c9c bl 0xc8fe8 <_Z19InvalidateFrozenVBsv> */
/* @0x168ca0 bl 0x1857d4 <_Z17FreeAllVertexDatav> */
/* @0x168ca4 pop {r3, lr} */
/* @0x168ca8 b 0x17dd54 <_ZN8Graphics4QuitEv> */

/* ── FUNC 0x168cac · GR_D3D_Get_Region(int&, int&) · size=44 · insn=11 */
/* @0x168cac ldr r2, [pc, #0x1c] */
/* @0x168cb0 ldr r3, [pc, #0x1c] */
/* @0x168cb4 ldr r2, [pc, r2] */
/* @0x168cb8 ldr r3, [pc, r3] */
/* @0x168cbc ldr r2, [r2] */
/* @0x168cc0 str r2, [r0] */
/* @0x168cc4 ldr r3, [r3] */
/* @0x168cc8 str r3, [r1] */
/* @0x168ccc bx lr */
/* @0x168cd0 eoreq r7, r8, r0, lsl #9 */
/* @0x168cd4 eoreq r7, r8, r0, lsl #9 */

/* ── FUNC 0x168cd8 · GR_D3D_Set_View_Port(int, int, int, int) · size=164 · insn=41 */
/* @0x168cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x168cdc mov r8, r0 */
/* @0x168ce0 ldr r4, [pc, #0x7c] */
/* @0x168ce4 sub sp, sp, #4 */
/* @0x168ce8 ldr r12, [pc, #0x78] */
/* @0x168cec mov r7, r1 */
/* @0x168cf0 add r4, pc, r4 */
/* @0x168cf4 mov r6, r2 */
/* @0x168cf8 mov r5, r3 */
/* @0x168cfc ldr r12, [r4, r12] */
/* @0x168d00 ldrb r12, [r12] */
/* @0x168d04 cmp r12, #0 */
/* @0x168d08 bne 0x168d14 <_Z20GR_D3D_Set_View_Portiiii+0x3c> */
/* @0x168d0c add sp, sp, #4 */
/* @0x168d10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x168d14 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x168d18 ldr r3, [pc, #0x4c] */
/* @0x168d1c ldr r10, [pc, #0x4c] */
/* @0x168d20 mov r0, r8 */
/* @0x168d24 ldr r9, [pc, #0x48] */
/* @0x168d28 mov r1, r7 */
/* @0x168d2c ldr r11, [r4, r3] */
/* @0x168d30 mov r2, r6 */
/* @0x168d34 ldr r12, [pc, #0x3c] */
/* @0x168d38 mov r3, r5 */
/* @0x168d3c str r8, [r11] */
/* @0x168d40 ldr r8, [r4, r10] */
/* @0x168d44 str r7, [r8] */
/* @0x168d48 ldr r7, [r4, r9] */
/* @0x168d4c str r6, [r7] */
/* @0x168d50 ldr r12, [r4, r12] */
/* @0x168d54 str r5, [r12] */
/* @0x168d58 add sp, sp, #4 */
/* @0x168d5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x168d60 b 0x17dfb0 <_ZN8Graphics11SetViewPortEiiii> */
/* @0x168d64 eoreq r8, r8, r0, ror #30 */
/* @0x168d68 .word 0xffffe4d0 */
/* @0x168d6c .word 0xffffe4ec */
/* @0x168d70 .word 0xffffe4f0 */
/* @0x168d74 .word 0xffffe4f4 */
/* @0x168d78 .word 0xffffe4f8 */

/* ── FUNC 0x168d7c · DirtyRoomExtents() · size=24 · insn=6 */
/* @0x168d7c ldr r3, [pc, #0xc] */
/* @0x168d80 mov r2, #1 */
/* @0x168d84 ldr r3, [pc, r3] */
/* @0x168d88 strb r2, [r3] */
/* @0x168d8c bx lr */
/* @0x168d90 eoreq r6, r8, r12, lsr #17 */

/* ── FUNC 0x168d94 · UpdateTransRoomExtents() · size=1360 · insn=340 */
/* @0x168d94 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x168d98 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x168d9c sub sp, sp, #188 */
/* @0x168da0 ldr r4, [pc, #0x530] */
/* @0x168da4 ldr r4, [pc, r4] */
/* @0x168da8 ldrb r3, [r4] */
/* @0x168dac cmp r3, #0 */
/* @0x168db0 bne 0x168dc0 <_Z22UpdateTransRoomExtentsv+0x2c> */
/* @0x168db4 add sp, sp, #188 */
/* @0x168db8 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x168dbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x168dc0 add r5, sp, #56 */
/* @0x168dc4 mov r0, #2 */
/* @0x168dc8 mov r1, r5 */
/* @0x168dcc bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf> */
/* @0x168dd0 vldr s8, [sp, #100] */
/* @0x168dd4 vldr s2, [sp, #72] */
/* @0x168dd8 vmul.f32 s0, s8, s2 */
/* @0x168ddc vldr s10, [sp, #76] */
/* @0x168de0 vldr s13, [sp, #112] */
/* @0x168de4 vldr s11, [sp, #96] */
/* @0x168de8 vldr s12, [sp, #116] */
/* @0x168dec vldr s9, [sp, #92] */
/* @0x168df0 vldr s14, [sp, #108] */
/* @0x168df4 vldr s7, [sp, #80] */
/* @0x168df8 vldr s4, [sp, #84] */
/* @0x168dfc vldr s6, [sp, #60] */
/* @0x168e00 vldr s5, [sp, #56] */
/* @0x168e04 vldr s19, [sp, #88] */
/* @0x168e08 vldr s20, [sp, #104] */
/* @0x168e0c vmul.f32 s15, s10, s8 */
/* @0x168e10 vneg.f32 s1, s2 */
/* @0x168e14 vmul.f32 s3, s13, s0 */
/* @0x168e18 vmul.f32 s17, s11, s1 */
/* @0x168e1c vmul.f32 s15, s15, s13 */
/* @0x168e20 vmul.f32 s16, s10, s11 */
/* @0x168e24 vmla.f32 s3, s12, s17 */
/* @0x168e28 vldr s17, [sp, #88] */
/* @0x168e2c vnmls.f32 s15, s16, s12 */
/* @0x168e30 vmul.f32 s22, s14, s0 */
/* @0x168e34 vmul.f32 s0, s9, s2 */
/* @0x168e38 vmul.f32 s17, s7, s17 */
/* @0x168e3c vmul.f32 s28, s4, s6 */
/* @0x168e40 vstr s17, [sp, #12] */
/* @0x168e44 vmul.f32 s18, s9, s7 */
/* @0x168e48 vmul.f32 s16, s11, s2 */
/* @0x168e4c vnmls.f32 s22, s12, s0 */
/* @0x168e50 vmul.f32 s25, s11, s5 */
/* @0x168e54 vmla.f32 s3, s12, s17 */
/* @0x168e58 vstr s25, [sp, #20] */
/* @0x168e5c vmul.f32 s21, s13, s28 */
/* @0x168e60 vmul.f32 s24, s11, s28 */
/* @0x168e64 vmul.f32 s28, s7, s6 */
/* @0x168e68 vmls.f32 s15, s12, s18 */
/* @0x168e6c vstr s28, [sp, #28] */
/* @0x168e70 vmul.f32 s18, s10, s19 */
/* @0x168e74 vmul.f32 s1, s9, s1 */
/* @0x168e78 vmul.f32 s27, s14, s16 */
/* @0x168e7c vmul.f32 s17, s4, s19 */
/* @0x168e80 vneg.f32 s25, s5 */
/* @0x168e84 vmul.f32 s26, s8, s5 */
/* @0x168e88 vmul.f32 s28, s9, s25 */
/* @0x168e8c vmul.f32 s23, s7, s20 */
/* @0x168e90 vstr s28, [sp, #16] */
/* @0x168e94 vmla.f32 s27, s13, s1 */
/* @0x168e98 vstr s23, [sp, #32] */
/* @0x168e9c vldr s16, [sp, #32] */
/* @0x168ea0 vmls.f32 s22, s12, s18 */
/* @0x168ea4 vmls.f32 s3, s13, s17 */
/* @0x168ea8 vmul.f32 s1, s4, s5 */
/* @0x168eac vmul.f32 s23, s7, s5 */
/* @0x168eb0 vmul.f32 s0, s9, s4 */
/* @0x168eb4 vmul.f32 s30, s13, s26 */
/* @0x168eb8 vmul.f32 s28, s14, s26 */
/* @0x168ebc vmul.f32 s26, s9, s5 */
/* @0x168ec0 vmla.f32 s15, s13, s0 */
/* @0x168ec4 vstr s26, [sp, #24] */
/* @0x168ec8 vmla.f32 s27, s13, s18 */
/* @0x168ecc vldr s18, [sp, #20] */
/* @0x168ed0 vmul.f32 s26, s10, s5 */
/* @0x168ed4 vmul.f32 s31, s14, s18 */
/* @0x168ed8 vmla.f32 s22, s14, s17 */
/* @0x168edc vmul.f32 s18, s14, s1 */
/* @0x168ee0 vmul.f32 s17, s9, s23 */
/* @0x168ee4 vmls.f32 s3, s8, s16 */
/* @0x168ee8 vmul.f32 s29, s8, s6 */
/* @0x168eec vmul.f32 s19, s7, s14 */
/* @0x168ef0 vnmls.f32 s18, s12, s26 */
/* @0x168ef4 vnmls.f32 s17, s11, s26 */
/* @0x168ef8 vmul.f32 s26, s4, s20 */
/* @0x168efc vneg.f32 s0, s6 */
/* @0x168f00 vmla.f32 s15, s8, s19 */
/* @0x168f04 vmul.f32 s16, s11, s0 */
/* @0x168f08 vmul.f32 s19, s7, s25 */
/* @0x168f0c vmul.f32 s0, s7, s0 */
/* @0x168f10 vstr s19, [sp, #36] */
/* @0x168f14 vmul.f32 s29, s13, s29 */
/* @0x168f18 vmul.f32 s25, s10, s25 */
/* @0x168f1c vmla.f32 s3, s11, s26 */
/* @0x168f20 vstr s25, [sp, #4] */
/* @0x168f24 vldr s25, [sp, #28] */
/* @0x168f28 vmul.f32 s19, s13, s1 */
/* @0x168f2c vmla.f32 s29, s12, s16 */
/* @0x168f30 vmla.f32 s24, s8, s0 */
/* @0x168f34 vnmls.f32 s21, s12, s25 */
/* @0x168f38 vldr s25, [sp, #16] */
/* @0x168f3c vmul.f32 s16, s14, s23 */
/* @0x168f40 vmla.f32 s28, s12, s25 */
/* @0x168f44 vldr s25, [sp, #20] */
/* @0x168f48 vstr s26, [sp, #20] */
/* @0x168f4c vmul.f32 s0, s9, s1 */
/* @0x168f50 vmul.f32 s26, s10, s20 */
/* @0x168f54 vmul.f32 s1, s11, s1 */
/* @0x168f58 vstr s26, [sp, #16] */
/* @0x168f5c vnmls.f32 s30, s12, s25 */
/* @0x168f60 vldr s25, [sp, #24] */
/* @0x168f64 vnmls.f32 s1, s8, s23 */
/* @0x168f68 vnmls.f32 s31, s13, s25 */
/* @0x168f6c vldr s25, [sp, #36] */
/* @0x168f70 vmul.f32 s23, s4, s14 */
/* @0x168f74 vmla.f32 s19, s12, s25 */
/* @0x168f78 vldr s25, [sp, #4] */
/* @0x168f7c vstr s3, [sp, #136] */
/* @0x168f80 vldr s26, [sp, #64] */
/* @0x168f84 vmla.f32 s16, s13, s25 */
/* @0x168f88 vmla.f32 s0, s8, s25 */
/* @0x168f8c vldr s25, [sp, #64] */
/* @0x168f90 vmul.f32 s25, s9, s25 */
/* @0x168f94 vmls.f32 s15, s11, s23 */
/* @0x168f98 vstr s25, [sp, #24] */
/* @0x168f9c vldr s23, [sp, #88] */
/* @0x168fa0 vldr s25, [sp, #64] */
/* @0x168fa4 vmul.f32 s23, s23, s25 */
/* @0x168fa8 vstr s15, [sp, #120] */
/* @0x168fac vmul.f32 s26, s10, s26 */
/* @0x168fb0 vstr s23, [sp, #8] */
/* @0x168fb4 vldr s23, [sp, #88] */
/* @0x168fb8 vmul.f32 s23, s23, s6 */
/* @0x168fbc vstr s26, [sp, #28] */
/* @0x168fc0 vldr s26, [sp, #12] */
/* @0x168fc4 vmul.f32 s25, s2, s25 */
/* @0x168fc8 vstr s23, [sp, #12] */
/* @0x168fcc vldr s23, [sp, #16] */
/* @0x168fd0 vmls.f32 s27, s14, s26 */
/* @0x168fd4 vmul.f32 s26, s2, s6 */
/* @0x168fd8 vmla.f32 s22, s8, s23 */
/* @0x168fdc vldr s23, [sp, #24] */
/* @0x168fe0 vmla.f32 s29, s12, s23 */
/* @0x168fe4 vldr s23, [sp, #28] */
/* @0x168fe8 vmla.f32 s24, s8, s23 */
/* @0x168fec vmls.f32 s21, s12, s23 */
/* @0x168ff0 vldr s23, [sp, #8] */
/* @0x168ff4 vmla.f32 s19, s12, s25 */
/* @0x168ff8 vmls.f32 s30, s12, s23 */
/* @0x168ffc vldr s23, [sp, #12] */
/* @0x169000 vmls.f32 s18, s12, s26 */
/* @0x169004 vmla.f32 s28, s12, s23 */
/* @0x169008 vldr s12, [sp, #68] */
/* @0x16900c vmla.f32 s16, s13, s26 */
/* @0x169010 vmla.f32 s0, s8, s26 */
/* @0x169014 vmls.f32 s17, s11, s26 */
/* @0x169018 vldr s26, [sp, #88] */
/* @0x16901c vmul.f32 s26, s26, s12 */
/* @0x169020 vmul.f32 s3, s3, s6 */
/* @0x169024 vstr s26, [sp, #4] */
/* @0x169028 vldr s26, [sp, #68] */
/* @0x16902c vmul.f32 s12, s10, s12 */
/* @0x169030 vmul.f32 s26, s9, s26 */
/* @0x169034 vmls.f32 s31, s13, s23 */
/* @0x169038 vldr s23, [sp, #16] */
/* @0x16903c vstr s26, [sp, #16] */
/* @0x169040 vmls.f32 s1, s8, s25 */
/* @0x169044 vmls.f32 s27, s11, s23 */
/* @0x169048 vldr s23, [sp, #20] */
/* @0x16904c vmls.f32 s24, s11, s12 */
/* @0x169050 vmls.f32 s22, s9, s23 */
/* @0x169054 vldr s23, [sp, #68] */
/* @0x169058 vmla.f32 s3, s15, s5 */
/* @0x16905c vstr s22, [sp, #152] */
/* @0x169060 vmul.f32 s26, s2, s23 */
/* @0x169064 vldr s23, [sp, #4] */
/* @0x169068 vmla.f32 s21, s13, s12 */
/* @0x16906c vldr s12, [sp, #16] */
/* @0x169070 vmla.f32 s30, s13, s23 */
/* @0x169074 vmls.f32 s29, s13, s12 */
/* @0x169078 vldr s12, [sp, #8] */
/* @0x16907c vmls.f32 s19, s13, s26 */
/* @0x169080 vldr s13, [sp, #64] */
/* @0x169084 vmls.f32 s28, s14, s23 */
/* @0x169088 vldr s23, [sp, #32] */
/* @0x16908c vmla.f32 s31, s14, s12 */
/* @0x169090 vmla.f32 s18, s14, s26 */
/* @0x169094 vmla.f32 s17, s9, s25 */
/* @0x169098 vmls.f32 s16, s14, s25 */
/* @0x16909c vmls.f32 s0, s9, s26 */
/* @0x1690a0 vmla.f32 s1, s11, s26 */
/* @0x1690a4 vldr s26, [sp, #64] */
/* @0x1690a8 vmla.f32 s3, s22, s26 */
/* @0x1690ac vldr s22, [sp, #24] */
/* @0x1690b0 vldr s26, [sp, #68] */
/* @0x1690b4 vmls.f32 s24, s4, s22 */
/* @0x1690b8 vmul.f32 s12, s20, s6 */
/* @0x1690bc vmul.f32 s25, s14, s13 */
/* @0x1690c0 vmul.f32 s13, s20, s13 */
/* @0x1690c4 vmla.f32 s27, s9, s23 */
/* @0x1690c8 vldr s23, [sp, #12] */
/* @0x1690cc vmls.f32 s29, s8, s25 */
/* @0x1690d0 vstr s27, [sp, #168] */
/* @0x1690d4 vmla.f32 s21, s4, s25 */
/* @0x1690d8 vldr s25, [sp, #8] */
/* @0x1690dc vmls.f32 s28, s8, s12 */
/* @0x1690e0 vmla.f32 s18, s4, s12 */
/* @0x1690e4 vmla.f32 s30, s8, s13 */
/* @0x1690e8 vmls.f32 s19, s4, s13 */
/* @0x1690ec vmla.f32 s31, s11, s12 */
/* @0x1690f0 vmls.f32 s16, s7, s12 */
/* @0x1690f4 vmls.f32 s0, s4, s23 */
/* @0x1690f8 vmla.f32 s1, s4, s25 */
/* @0x1690fc vldr s4, [sp, #16] */
/* @0x169100 vmla.f32 s17, s7, s23 */
/* @0x169104 vmla.f32 s24, s7, s4 */
/* @0x169108 vmul.f32 s12, s20, s26 */
/* @0x16910c vstr s24, [sp, #132] */
/* @0x169110 vmul.f32 s8, s14, s26 */
/* @0x169114 vmla.f32 s3, s27, s26 */
/* @0x169118 vmla.f32 s29, s11, s8 */
/* @0x16911c vmls.f32 s21, s7, s8 */
/* @0x169120 vldr s8, [sp, #4] */
/* @0x169124 vstr s29, [sp, #124] */
/* @0x169128 vmls.f32 s30, s11, s12 */
/* @0x16912c vstr s21, [sp, #128] */
/* @0x169130 vmla.f32 s19, s7, s12 */
/* @0x169134 vstr s30, [sp, #140] */
/* @0x169138 vmla.f32 s28, s9, s12 */
/* @0x16913c vstr s19, [sp, #144] */
/* @0x169140 vmls.f32 s31, s9, s13 */
/* @0x169144 vstr s28, [sp, #156] */
/* @0x169148 vmls.f32 s18, s10, s12 */
/* @0x16914c vstr s31, [sp, #172] */
/* @0x169150 vmls.f32 s17, s10, s25 */
/* @0x169154 vstr s18, [sp, #160] */
/* @0x169158 vmla.f32 s16, s10, s13 */
/* @0x16915c vstr s17, [sp, #180] */
/* @0x169160 vmla.f32 s0, s10, s8 */
/* @0x169164 vstr s16, [sp, #176] */
/* @0x169168 vmls.f32 s1, s7, s8 */
/* @0x16916c vstr s0, [sp, #164] */
/* @0x169170 vcmp.f32 s3, #0 */
/* @0x169174 vstr s1, [sp, #148] */
/* @0x169178 vmrs APSR_nzcv, fpscr */
/* @0x16917c beq 0x1691c4 <_Z22UpdateTransRoomExtentsv+0x430> */
/* @0x169180 vmov.f32 s14, #1.000000e+00 */
/* @0x169184 add r3, sp, #124 */
/* @0x169188 add r2, sp, #120 */
/* @0x16918c mov r1, r5 */
/* @0x169190 vdiv.f32 s3, s14, s3 */
/* @0x169194 b 0x16919c <_Z22UpdateTransRoomExtentsv+0x408> */
/* @0x169198 vldmia r3!, {s15} */
/* @0x16919c vmul.f32 s15, s3, s15 */
/* @0x1691a0 vstmia r1!, {s15} */
/* @0x1691a4 cmp r1, r2 */
/* @0x1691a8 bne 0x169198 <_Z22UpdateTransRoomExtentsv+0x404> */
/* @0x1691ac vldr s5, [sp, #56] */
/* @0x1691b0 vldr s2, [sp, #72] */
/* @0x1691b4 vldr s20, [sp, #104] */
/* @0x1691b8 vldr s6, [sp, #60] */
/* @0x1691bc vldr s10, [sp, #76] */
/* @0x1691c0 vldr s14, [sp, #108] */
/* @0x1691c4 ldr r0, [pc, #0x110] */
/* @0x1691c8 add r12, sp, #120 */
/* @0x1691cc mov r1, #-2147483648 */
/* @0x1691d0 mvn r2, #-2147483648 */
/* @0x1691d4 ldr r0, [pc, r0] */
/* @0x1691d8 vldr s12, [r0] */
/* @0x1691dc vldr s11, [r0, #8] */
/* @0x1691e0 vcvt.f32.s32 s12, s12 */
/* @0x1691e4 vldr s15, [r0, #4] */
/* @0x1691e8 vldr s13, [r0, #12] */
/* @0x1691ec add r11, sp, #40 */
/* @0x1691f0 str r4, [sp, #0x8] */
/* @0x1691f4 mov r8, r1 */
/* @0x1691f8 mov r7, r2 */
/* @0x1691fc mov r3, #0 */
/* @0x169200 mov r4, r12 */
/* @0x169204 vcvt.f32.s32 s11, s11 */
/* @0x169208 vstr s12, [sp, #40] */
/* @0x16920c vstr s12, [sp, #52] */
/* @0x169210 vcvt.f32.s32 s15, s15 */
/* @0x169214 vstr s11, [sp, #44] */
/* @0x169218 vstr s11, [sp, #48] */
/* @0x16921c vcvt.f32.s32 s13, s13 */
/* @0x169220 vstr s15, [sp, #120] */
/* @0x169224 vstr s15, [sp, #124] */
/* @0x169228 vstr s13, [sp, #128] */
/* @0x16922c vstr s13, [sp, #132] */
/* @0x169230 vmul.f32 s13, s2, s15 */
/* @0x169234 add r3, r3, #4 */
/* @0x169238 add r10, r11, r3 */
/* @0x16923c add r9, r4, r3 */
/* @0x169240 vmul.f32 s15, s10, s15 */
/* @0x169244 vmla.f32 s13, s5, s12 */
/* @0x169248 vmla.f32 s15, s6, s12 */
/* @0x16924c vadd.f32 s13, s13, s20 */
/* @0x169250 vadd.f32 s15, s15, s14 */
/* @0x169254 vcvt.s32.f32 s13, s13 */
/* @0x169258 vcvt.s32.f32 s15, s15 */
/* @0x16925c vmov r12, s13 */
/* @0x169260 vmov r0, s15 */
/* @0x169264 cmp r7, r12 */
/* @0x169268 movlt r6, r7 */
/* @0x16926c movge r6, r12 */
/* @0x169270 cmp r12, r8 */
/* @0x169274 movlt r12, r8 */
/* @0x169278 mov r7, r6 */
/* @0x16927c mov r8, r12 */
/* @0x169280 cmp r2, r0 */
/* @0x169284 movlt r5, r2 */
/* @0x169288 movge r5, r0 */
/* @0x16928c cmp r0, r1 */
/* @0x169290 movlt r0, r1 */
/* @0x169294 cmp r3, #16 */
/* @0x169298 mov r2, r5 */
/* @0x16929c mov r1, r0 */
/* @0x1692a0 vldrne s12, [r10] */
/* @0x1692a4 vldrne s15, [r9] */
/* @0x1692a8 bne 0x169230 <_Z22UpdateTransRoomExtentsv+0x49c> */
/* @0x1692ac ldr r3, [pc, #0x2c] */
/* @0x1692b0 mov r2, #0 */
/* @0x1692b4 ldr r4, [sp, #0x8] */
/* @0x1692b8 ldr r3, [pc, r3] */
/* @0x1692bc strb r2, [r4] */
/* @0x1692c0 str r6, [r3] */
/* @0x1692c4 stmib r3, {r5, r12} */
/* @0x1692c8 str r0, [r3, #0xc] */
/* @0x1692cc add sp, sp, #188 */
/* @0x1692d0 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1692d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1692d8 eoreq r6, r8, r12, lsl #17 */
/* @0x1692dc eoreq r6, r8, r8, ror pc */
/* @0x1692e0 mlaeq r8, r8, lr, r6 */

/* ── FUNC 0x1692e4 · SetViewExtents(float, float, float, float, float) · size=292 · insn=73 */
/* @0x1692e4 push {r3, lr} */
/* @0x1692e8 vpush {d8, d9, d10} */
/* @0x1692ec vldr s15, [sp, #32] */
/* @0x1692f0 vabs.f32 s13, s15 */
/* @0x1692f4 vldr s14, [pc, #248] */
/* @0x1692f8 vmov s19, r0 */
/* @0x1692fc vmov s18, r1 */
/* @0x169300 vmov s17, r2 */
/* @0x169304 vcmpe.f32 s13, s14 */
/* @0x169308 vmov s16, r3 */
/* @0x16930c vmrs APSR_nzcv, fpscr */
/* @0x169310 bmi 0x1693a8 <_Z14SetViewExtentsfffff+0xc4> */
/* @0x169314 vldr s21, [pc, #220] */
/* @0x169318 vmul.f32 s21, s15, s21 */
/* @0x16931c vmov r0, s21 */
/* @0x169320 bl 0xb6580 <sinf@plt> */
/* @0x169324 vmov s14, r0 */
/* @0x169328 vmov r0, s21 */
/* @0x16932c vabs.f32 s20, s14 */
/* @0x169330 bl 0xb658c <cosf@plt> */
/* @0x169334 ldr r3, [pc, #0xc4] */
/* @0x169338 ldr r3, [pc, r3] */
/* @0x16933c vmul.f32 s13, s16, s20 */
/* @0x169340 vmov.f32 s15, #5.000000e-01 */
/* @0x169344 vmov s14, r0 */
/* @0x169348 vabs.f32 s12, s14 */
/* @0x16934c vmul.f32 s14, s16, s12 */
/* @0x169350 vmla.f32 s13, s17, s12 */
/* @0x169354 vmla.f32 s14, s17, s20 */
/* @0x169358 vsub.f32 s12, s17, s13 */
/* @0x16935c vsub.f32 s11, s16, s14 */
/* @0x169360 vadd.f32 s17, s17, s13 */
/* @0x169364 vadd.f32 s16, s16, s14 */
/* @0x169368 vmov.f32 s13, s18 */
/* @0x16936c vmov.f32 s14, s19 */
/* @0x169370 vmla.f32 s18, s16, s15 */
/* @0x169374 vmla.f32 s19, s17, s15 */
/* @0x169378 vmla.f32 s14, s12, s15 */
/* @0x16937c vmla.f32 s13, s11, s15 */
/* @0x169380 vcvt.s32.f32 s19, s19 */
/* @0x169384 vcvt.s32.f32 s18, s18 */
/* @0x169388 vstr s19, [r3, #8] */
/* @0x16938c vcvt.s32.f32 s12, s14 */
/* @0x169390 vstr s18, [r3, #12] */
/* @0x169394 vpop {d8, d9, d10} */
/* @0x169398 vcvt.s32.f32 s13, s13 */
/* @0x16939c vstr s12, [r3] */
/* @0x1693a0 vstr s13, [r3, #4] */
/* @0x1693a4 pop {r3, pc} */
/* @0x1693a8 vadd.f32 s17, s19, s17 */
/* @0x1693ac vldr s15, [pc, #72] */
/* @0x1693b0 ldr r3, [pc, #0x4c] */
/* @0x1693b4 ldr r3, [pc, r3] */
/* @0x1693b8 vadd.f32 s16, s18, s16 */
/* @0x1693bc vadd.f32 s17, s17, s15 */
/* @0x1693c0 vsub.f32 s19, s19, s15 */
/* @0x1693c4 vsub.f32 s18, s18, s15 */
/* @0x1693c8 vadd.f32 s15, s16, s15 */
/* @0x1693cc vcvt.s32.f32 s19, s19 */
/* @0x1693d0 vcvt.s32.f32 s18, s18 */
/* @0x1693d4 vstr s19, [r3] */
/* @0x1693d8 vcvt.s32.f32 s17, s17 */
/* @0x1693dc vstr s18, [r3, #4] */
/* @0x1693e0 vcvt.s32.f32 s15, s15 */
/* @0x1693e4 vstr s17, [r3, #8] */
/* @0x1693e8 vpop {d8, d9, d10} */
/* @0x1693ec vstr s15, [r3, #12] */
/* @0x1693f0 pop {r3, pc} */
/* @0x1693f4 blo 0xfe22ddb8 <b2_toiTime+0xfffffffffdad4914> */
/* @0x1693f8 vstmialo lr, {s30, s31} */
/* @0x1693fc svclo #0x7fbe77 */
/* @0x169400 eoreq r6, r8, r4, lsl lr */
/* @0x169404 mlaeq r8, r8, sp, r6 */

/* ── FUNC 0x169408 · GR_D3D_Set_View_Area(float, float, float, float, float) · size=820 · insn=205 */
/* @0x169408 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x16940c vpush {d8, d9, d10} */
/* @0x169410 sub sp, sp, #180 */
/* @0x169414 vldr s21, [pc, #748] */
/* @0x169418 ldr r5, [pc, #0x2ec] */
/* @0x16941c mov r4, #0 */
/* @0x169420 ldr r9, [pc, #0x2e8] */
/* @0x169424 mov r6, #1065353216 */
/* @0x169428 add r5, pc, r5 */
/* @0x16942c ldr r8, [pc, #0x2e0] */
/* @0x169430 str r4, [sp, #0x68] */
/* @0x169434 vmov s18, r3 */
/* @0x169438 str r4, [sp, #0x64] */
/* @0x16943c vmov s20, r0 */
/* @0x169440 str r4, [sp, #0x60] */
/* @0x169444 vmov s19, r1 */
/* @0x169448 str r4, [sp, #0x5c] */
/* @0x16944c vmov s17, r2 */
/* @0x169450 str r6, [sp, #0x6c] */
/* @0x169454 str r6, [sp, #0x58] */
/* @0x169458 str r6, [sp, #0x44] */
/* @0x16945c str r6, [sp, #0x30] */
/* @0x169460 str r6, [sp, #0xac] */
/* @0x169464 str r6, [sp, #0x98] */
/* @0x169468 str r6, [sp, #0x84] */
/* @0x16946c str r6, [sp, #0x70] */
/* @0x169470 str r4, [sp, #0x54] */
/* @0x169474 str r4, [sp, #0x50] */
/* @0x169478 str r4, [sp, #0x4c] */
/* @0x16947c str r4, [sp, #0x48] */
/* @0x169480 str r4, [sp, #0x40] */
/* @0x169484 str r4, [sp, #0x3c] */
/* @0x169488 str r4, [sp, #0x38] */
/* @0x16948c str r4, [sp, #0x34] */
/* @0x169490 str r4, [sp, #0xa8] */
/* @0x169494 str r4, [sp, #0xa4] */
/* @0x169498 str r4, [sp, #0xa0] */
/* @0x16949c str r4, [sp, #0x9c] */
/* @0x1694a0 str r4, [sp, #0x94] */
/* @0x1694a4 str r4, [sp, #0x90] */
/* @0x1694a8 str r4, [sp, #0x8c] */
/* @0x1694ac str r4, [sp, #0x88] */
/* @0x1694b0 str r4, [sp, #0x80] */
/* @0x1694b4 str r4, [sp, #0x7c] */
/* @0x1694b8 str r4, [sp, #0x78] */
/* @0x1694bc str r4, [sp, #0x74] */
/* @0x1694c0 vldr s16, [sp, #232] */
/* @0x1694c4 ldr r9, [r5, r9] */
/* @0x1694c8 ldr r7, [pc, #0x248] */
/* @0x1694cc ldr lr, [pc, #0x248] */
/* @0x1694d0 str r0, [r9] */
/* @0x1694d4 ldr r8, [r5, r8] */
/* @0x1694d8 ldr r12, [pc, #0x240] */
/* @0x1694dc str r1, [r8] */
/* @0x1694e0 ldr r7, [r5, r7] */
/* @0x1694e4 str r2, [r7] */
/* @0x1694e8 ldr lr, [r5, lr] */
/* @0x1694ec str r3, [lr] */
/* @0x1694f0 ldr r12, [r5, r12] */
/* @0x1694f4 vstr s16, [sp] */
/* @0x1694f8 vstr s16, [r12] */
/* @0x1694fc bl 0x1692e4 <_Z14SetViewExtentsfffff> */
/* @0x169500 ldr r3, [pc, #0x21c] */
/* @0x169504 vmov.f32 s15, #5.000000e-01 */
/* @0x169508 ldr r7, [r5, r3] */
/* @0x16950c ldrb r3, [r7] */
/* @0x169510 cmp r3, #0 */
/* @0x169514 beq 0x16952c <_Z20GR_D3D_Set_View_Areafffff+0x124> */
/* @0x169518 ldr r3, [pc, #0x208] */
/* @0x16951c ldr r3, [r5, r3] */
/* @0x169520 ldrb r3, [r3] */
/* @0x169524 cmp r3, #0 */
/* @0x169528 bne 0x169620 <_Z20GR_D3D_Set_View_Areafffff+0x218> */
/* @0x16952c vmla.f32 s20, s17, s15 */
/* @0x169530 mov r6, #0 */
/* @0x169534 mov r3, #0 */
/* @0x169538 str r6, [sp, #0x20] */
/* @0x16953c movt r3, #0xc67a */
/* @0x169540 str r3, [sp, #0x14] */
/* @0x169544 add r4, sp, #48 */
/* @0x169548 vmla.f32 s19, s18, s15 */
/* @0x16954c vstr s20, [sp, #12] */
/* @0x169550 vstr s20, [sp, #24] */
/* @0x169554 vnmul.f32 s15, s16, s21 */
/* @0x169558 vstr s19, [sp, #16] */
/* @0x16955c vstr s19, [sp, #28] */
/* @0x169560 vmov r0, s15 */
/* @0x169564 bl 0xb6580 <sinf@plt> */
/* @0x169568 vmul.f32 s21, s16, s21 */
/* @0x16956c mov r8, r0 */
/* @0x169570 vmov r0, s21 */
/* @0x169574 bl 0xb658c <cosf@plt> */
/* @0x169578 add r1, sp, #12 */
/* @0x16957c add r2, sp, #24 */
/* @0x169580 add r3, sp, #36 */
/* @0x169584 str r6, [sp, #0x2c] */
/* @0x169588 add r6, sp, #112 */
/* @0x16958c str r8, [sp, #0x24] */
/* @0x169590 str r0, [sp, #0x28] */
/* @0x169594 mov r0, r4 */
/* @0x169598 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x16959c ldr r0, [pc, #0x188] */
/* @0x1695a0 ldr r1, [pc, #0x188] */
/* @0x1695a4 mov lr, #1 */
/* @0x1695a8 ldrb r2, [r7] */
/* @0x1695ac mov r3, #1065353216 */
/* @0x1695b0 ldr r0, [r5, r0] */
/* @0x1695b4 mov r12, #0 */
/* @0x1695b8 cmp r2, #0 */
/* @0x1695bc ldr r2, [pc, #0x170] */
/* @0x1695c0 movt r12, #0x46fa */
/* @0x1695c4 strb lr, [r0] */
/* @0x1695c8 mov r0, r6 */
/* @0x1695cc ldr r1, [r5, r1] */
/* @0x1695d0 str r3, [r1] */
/* @0x1695d4 ldr r2, [r5, r2] */
/* @0x1695d8 vmov r1, s17 */
/* @0x1695dc str r12, [r2] */
/* @0x1695e0 ldr r2, [pc, #0x150] */
/* @0x1695e4 ldr r2, [r5, r2] */
/* @0x1695e8 str r12, [sp] */
/* @0x1695ec vldr s15, [r2] */
/* @0x1695f0 vcvt.f32.s32 s15, s15 */
/* @0x1695f4 vmulne.f32 s15, s15, s18 */
/* @0x1695f8 vnmuleq.f32 s15, s18, s15 */
/* @0x1695fc vmov r2, s15 */
/* @0x169600 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff> */
/* @0x169604 mov r1, r4 */
/* @0x169608 mov r2, r6 */
/* @0x16960c mov r0, #0 */
/* @0x169610 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x169614 add sp, sp, #180 */
/* @0x169618 vpop {d8, d9, d10} */
/* @0x16961c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x169620 vmla.f32 s20, s17, s15 */
/* @0x169624 str r4, [sp, #0x20] */
/* @0x169628 mov r7, #0 */
/* @0x16962c vmla.f32 s19, s18, s15 */
/* @0x169630 vstr s20, [sp, #12] */
/* @0x169634 vstr s20, [sp, #24] */
/* @0x169638 vnmul.f32 s14, s16, s21 */
/* @0x16963c vstr s19, [sp, #16] */
/* @0x169640 vstr s19, [sp, #28] */
/* @0x169644 vneg.f32 s15, s17 */
/* @0x169648 vmov r0, s14 */
/* @0x16964c vstr s15, [sp, #20] */
/* @0x169650 bl 0xb6580 <sinf@plt> */
/* @0x169654 vmul.f32 s21, s16, s21 */
/* @0x169658 mov r8, r0 */
/* @0x16965c vmov r0, s21 */
/* @0x169660 bl 0xb658c <cosf@plt> */
/* @0x169664 str r8, [sp, #0x24] */
/* @0x169668 add r8, sp, #48 */
/* @0x16966c add r1, sp, #12 */
/* @0x169670 add r2, sp, #24 */
/* @0x169674 add r3, sp, #36 */
/* @0x169678 str r4, [sp, #0x2c] */
/* @0x16967c add r4, sp, #112 */
/* @0x169680 str r0, [sp, #0x28] */
/* @0x169684 mov r0, r8 */
/* @0x169688 bl 0x27acb0 <_ZN8yyMatrix8LookAtLHEPS_P9yyVector3S2_S2_> */
/* @0x16968c vdiv.f32 s18, s18, s17 */
/* @0x169690 ldr r3, [pc, #0x94] */
/* @0x169694 mov r2, #0 */
/* @0x169698 ldr lr, [pc, #0x90] */
/* @0x16969c movt r2, #0x46fa */
/* @0x1696a0 ldr r12, [pc, #0x8c] */
/* @0x1696a4 mov r0, r4 */
/* @0x1696a8 ldr r9, [r5, r3] */
/* @0x1696ac mov r3, r6 */
/* @0x1696b0 ldr r1, [pc, #0x80] */
/* @0x1696b4 strb r7, [r9] */
/* @0x1696b8 ldr lr, [r5, lr] */
/* @0x1696bc str r6, [lr] */
/* @0x1696c0 ldr r12, [r5, r12] */
/* @0x1696c4 str r2, [r12] */
/* @0x1696c8 ldr r1, [r5, r1] */
/* @0x1696cc str r2, [sp] */
/* @0x1696d0 vldr s15, [r1] */
/* @0x1696d4 vdiv.f32 s17, s17, s17 */
/* @0x1696d8 vcvt.f32.s32 s15, s15 */
/* @0x1696dc vmov r1, s17 */
/* @0x1696e0 vmul.f32 s15, s18, s15 */
/* @0x1696e4 vmov r2, s15 */
/* @0x1696e8 bl 0x27b180 <_ZN8yyMatrix13PerspectiveLHEPS_ffff> */
/* @0x1696ec mov r0, r7 */
/* @0x1696f0 mov r1, r8 */
/* @0x1696f4 mov r2, r4 */
/* @0x1696f8 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_> */
/* @0x1696fc add sp, sp, #180 */
/* @0x169700 vpop {d8, d9, d10} */
/* @0x169704 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x169708 vstmialo lr, {s30, s31} */
/* @0x16970c eoreq r8, r8, r8, lsr #16 */
/* @0x169710 .word 0xffffe504 */
/* @0x169714 .word 0xffffe508 */
/* @0x169718 .word 0xffffe50c */
/* @0x16971c .word 0xffffe510 */
/* @0x169720 .word 0xffffe514 */
/* @0x169724 .word 0xffffc0b4 */
/* @0x169728 .word 0xffffe4b0 */
/* @0x16972c .word 0xffffe480 */
/* @0x169730 .word 0xffffe484 */
/* @0x169734 .word 0xffffe488 */
/* @0x169738 .word 0xffffe48c */

/* ── FUNC 0x16973c · GR_D3D_Init(void*, int, int, int) · size=432 · insn=108 */
/* @0x16973c push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x169740 sub sp, sp, #72 */
/* @0x169744 mov r6, r1 */
/* @0x169748 mov r10, r0 */
/* @0x16974c mov r4, r2 */
/* @0x169750 mov r9, r3 */
/* @0x169754 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x169758 ldr r5, [pc, #0x170] */
/* @0x16975c add r5, pc, r5 */
/* @0x169760 cmp r0, r6 */
/* @0x169764 movgt r0, r6 */
/* @0x169768 ble 0x1698c8 <_Z11GR_D3D_InitPviii+0x18c> */
/* @0x16976c ldr r3, [pc, #0x160] */
/* @0x169770 ldr r8, [r5, r3] */
/* @0x169774 str r0, [r8] */
/* @0x169778 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x16977c cmp r0, r4 */
/* @0x169780 movgt r0, r4 */
/* @0x169784 ble 0x1698c0 <_Z11GR_D3D_InitPviii+0x184> */
/* @0x169788 ldr r3, [pc, #0x148] */
/* @0x16978c ldr r7, [r5, r3] */
/* @0x169790 str r0, [r7] */
/* @0x169794 bl 0x17db54 <_Z17DisplayColorDepthv> */
/* @0x169798 cmp r0, #16 */
/* @0x16979c beq 0x1697c4 <_Z11GR_D3D_InitPviii+0x88> */
/* @0x1697a0 bl 0x17db54 <_Z17DisplayColorDepthv> */
/* @0x1697a4 cmp r0, #32 */
/* @0x1697a8 beq 0x1697c4 <_Z11GR_D3D_InitPviii+0x88> */
/* @0x1697ac ldr r0, [pc, #0x128] */
/* @0x1697b0 add r0, pc, r0 */
/* @0x1697b4 bl 0xc4b0c <_Z11ShowMessagePKc> */
/* @0x1697b8 mov r0, #0 */
/* @0x1697bc add sp, sp, #72 */
/* @0x1697c0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1697c4 ldr r2, [r7] */
/* @0x1697c8 mov r3, r9 */
/* @0x1697cc ldr r1, [r8] */
/* @0x1697d0 mov r0, r10 */
/* @0x1697d4 bl 0x17dbcc <_ZN8Graphics10OpenWindowEPviii> */
/* @0x1697d8 add r1, sp, #8 */
/* @0x1697dc mov r4, #0 */
/* @0x1697e0 mov r6, #1065353216 */
/* @0x1697e4 str r4, [sp, #0x40] */
/* @0x1697e8 str r6, [sp, #0x44] */
/* @0x1697ec str r6, [sp, #0x30] */
/* @0x1697f0 str r6, [sp, #0x1c] */
/* @0x1697f4 str r6, [sp, #0x8] */
/* @0x1697f8 str r4, [sp, #0x3c] */
/* @0x1697fc str r4, [sp, #0x38] */
/* @0x169800 str r4, [sp, #0x34] */
/* @0x169804 str r4, [sp, #0x2c] */
/* @0x169808 str r4, [sp, #0x28] */
/* @0x16980c str r4, [sp, #0x24] */
/* @0x169810 str r4, [sp, #0x20] */
/* @0x169814 str r4, [sp, #0x18] */
/* @0x169818 str r4, [sp, #0x14] */
/* @0x16981c str r4, [sp, #0x10] */
/* @0x169820 str r4, [sp, #0xc] */
/* @0x169824 mov r7, r0 */
/* @0x169828 mov r0, #2 */
/* @0x16982c bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf> */
/* @0x169830 bl 0x173db0 <_Z15GR_Texture_Initv> */
/* @0x169834 ldr r3, [pc, #0xa4] */
/* @0x169838 ldr r0, [r5, r3] */
/* @0x16983c bl 0x167c34 <_ZN18RenderStateManager5ResetEv> */
/* @0x169840 bl 0x168a50 <_Z20GR_D3D_Settings_Initv> */
/* @0x169844 mov r0, #0 */
/* @0x169848 mov r1, r6 */
/* @0x16984c mov r2, r0 */
/* @0x169850 mov r3, #7 */
/* @0x169854 bl 0x17eec4 <_ZN8Graphics5ClearEjfi11eClearFlags> */
/* @0x169858 ldr r2, [pc, #0x84] */
/* @0x16985c ldr r3, [pc, #0x84] */
/* @0x169860 mov r0, #0 */
/* @0x169864 mov r1, r0 */
/* @0x169868 ldr r6, [r5, r2] */
/* @0x16986c ldr r5, [r5, r3] */
/* @0x169870 ldr r2, [r6] */
/* @0x169874 ldr r3, [r5] */
/* @0x169878 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x16987c ldr r2, [r6] */
/* @0x169880 str r4, [sp] */
/* @0x169884 mov r0, r4 */
/* @0x169888 ldr r3, [r5] */
/* @0x16988c mov r1, r4 */
/* @0x169890 vmov s15, r2 */
/* @0x169894 vcvt.f32.s32 s15, s15 */
/* @0x169898 vmov r2, s15 */
/* @0x16989c vmov s15, r3 */
/* @0x1698a0 vcvt.f32.s32 s15, s15 */
/* @0x1698a4 vmov r3, s15 */
/* @0x1698a8 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x1698ac bl 0x17f38c <_ZN8Graphics4InitEv> */
/* @0x1698b0 bl 0x168b64 <_Z19_CreateBlankTexturev> */
/* @0x1698b4 mov r0, r7 */
/* @0x1698b8 add sp, sp, #72 */
/* @0x1698bc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1698c0 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x1698c4 b 0x169788 <_Z11GR_D3D_InitPviii+0x4c> */
/* @0x1698c8 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x1698cc b 0x16976c <_Z11GR_D3D_InitPviii+0x30> */
/* @0x1698d0 .word 0x002884f4 */
/* @0x1698d4 .word 0xffffe4e4 */
/* @0x1698d8 .word 0xffffe4e8 */
/* @0x1698dc andseq r1, lr, r8 */
/* @0x1698e0 .word 0xffffc0a8 */
/* @0x1698e4 .word 0xffffe24c */
/* @0x1698e8 .word 0xffffe250 */

/* ── FUNC 0x1698ec · GR_D3D_Set_Region(int, int) · size=212 · insn=53 */
/* @0x1698ec push {r4, r5, r6, r7, lr} */
/* @0x1698f0 sub sp, sp, #12 */
/* @0x1698f4 mov r4, r0 */
/* @0x1698f8 mov r5, r1 */
/* @0x1698fc bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x169900 ldr r6, [pc, #0xac] */
/* @0x169904 add r6, pc, r6 */
/* @0x169908 cmp r0, r4 */
/* @0x16990c blt 0x1699a8 <_Z17GR_D3D_Set_Regionii+0xbc> */
/* @0x169910 bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x169914 cmp r0, r5 */
/* @0x169918 blt 0x16999c <_Z17GR_D3D_Set_Regionii+0xb0> */
/* @0x16991c ldr r3, [pc, #0x94] */
/* @0x169920 ldr r7, [r6, r3] */
/* @0x169924 ldr r3, [r7] */
/* @0x169928 cmp r4, r3 */
/* @0x16992c ldr r3, [pc, #0x88] */
/* @0x169930 ldr r6, [r6, r3] */
/* @0x169934 beq 0x16998c <_Z17GR_D3D_Set_Regionii+0xa0> */
/* @0x169938 mov r0, #0 */
/* @0x16993c mov r2, r4 */
/* @0x169940 mov r1, r0 */
/* @0x169944 mov r3, r5 */
/* @0x169948 str r4, [r7] */
/* @0x16994c str r5, [r6] */
/* @0x169950 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii> */
/* @0x169954 ldr r2, [r7] */
/* @0x169958 mov r1, #0 */
/* @0x16995c ldr r3, [r6] */
/* @0x169960 mov r0, r1 */
/* @0x169964 str r1, [sp] */
/* @0x169968 vmov s15, r2 */
/* @0x16996c vcvt.f32.s32 s15, s15 */
/* @0x169970 vmov r2, s15 */
/* @0x169974 vmov s15, r3 */
/* @0x169978 vcvt.f32.s32 s15, s15 */
/* @0x16997c vmov r3, s15 */
/* @0x169980 bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff> */
/* @0x169984 add sp, sp, #12 */
/* @0x169988 pop {r4, r5, r6, r7, pc} */
/* @0x16998c ldr r3, [r6] */
/* @0x169990 cmp r5, r3 */
/* @0x169994 bne 0x169938 <_Z17GR_D3D_Set_Regionii+0x4c> */
/* @0x169998 b 0x169984 <_Z17GR_D3D_Set_Regionii+0x98> */
/* @0x16999c bl 0x17db38 <_Z22Graphics_DisplayHeightv> */
/* @0x1699a0 mov r5, r0 */
/* @0x1699a4 b 0x16991c <_Z17GR_D3D_Set_Regionii+0x30> */
/* @0x1699a8 bl 0x17db24 <_Z21Graphics_DisplayWidthv> */
/* @0x1699ac mov r4, r0 */
/* @0x1699b0 b 0x169910 <_Z17GR_D3D_Set_Regionii+0x24> */
/* @0x1699b4 eoreq r8, r8, r12, asr #6 */
/* @0x1699b8 .word 0xffffe4e4 */
/* @0x1699bc .word 0xffffe4e8 */

/* ── FUNC 0x1699c0 · GR_D3D_Start_Frame() · size=152 · insn=38 */
/* @0x1699c0 push {r4, r5, r6, lr} */
/* @0x1699c4 ldr r4, [pc, #0x7c] */
/* @0x1699c8 ldr r3, [pc, #0x7c] */
/* @0x1699cc add r4, pc, r4 */
/* @0x1699d0 ldr r3, [r4, r3] */
/* @0x1699d4 ldrb r5, [r3] */
/* @0x1699d8 cmp r5, #0 */
/* @0x1699dc beq 0x169a04 <_Z18GR_D3D_Start_Framev+0x44> */
/* @0x1699e0 ldr r3, [pc, #0x68] */
/* @0x1699e4 ldr r6, [r4, r3] */
/* @0x1699e8 ldrb r3, [r6] */
/* @0x1699ec cmp r3, #0 */
/* @0x1699f0 bne 0x169a20 <_Z18GR_D3D_Start_Framev+0x60> */
/* @0x1699f4 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv> */
/* @0x1699f8 ldrb r3, [r6] */
/* @0x1699fc cmp r3, #0 */
/* @0x169a00 bne 0x169a0c <_Z18GR_D3D_Start_Framev+0x4c> */
/* @0x169a04 mov r0, r5 */
/* @0x169a08 pop {r4, r5, r6, pc} */
/* @0x169a0c ldr r3, [pc, #0x40] */
/* @0x169a10 ldr r0, [r4, r3] */
/* @0x169a14 bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x169a18 mov r0, r5 */
/* @0x169a1c pop {r4, r5, r6, pc} */
/* @0x169a20 ldr r3, [pc, #0x2c] */
/* @0x169a24 mov r1, #6 */
/* @0x169a28 mov r2, #25 */
/* @0x169a2c ldr r0, [r4, r3] */
/* @0x169a30 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x169a34 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv> */
/* @0x169a38 ldrb r3, [r6] */
/* @0x169a3c cmp r3, #0 */
/* @0x169a40 beq 0x169a04 <_Z18GR_D3D_Start_Framev+0x44> */
/* @0x169a44 b 0x169a0c <_Z18GR_D3D_Start_Framev+0x4c> */
/* @0x169a48 eoreq r8, r8, r4, lsl #5 */
/* @0x169a4c .word 0xffffe4d0 */
/* @0x169a50 .word 0xffffbf18 */
/* @0x169a54 .word 0xffffbf1c */

/* ── FUNC 0x169a58 · GR_D3D_Finish_Frame(bool) · size=196 · insn=49 */
/* @0x169a58 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x169a5c mov r9, r0 */
/* @0x169a60 ldr r6, [pc, #0xa0] */
/* @0x169a64 ldr r3, [pc, #0xa0] */
/* @0x169a68 add r6, pc, r6 */
/* @0x169a6c ldr r3, [r6, r3] */
/* @0x169a70 ldrb r7, [r3] */
/* @0x169a74 cmp r7, #0 */
/* @0x169a78 beq 0x169acc <_Z19GR_D3D_Finish_Frameb+0x74> */
/* @0x169a7c ldr r3, [pc, #0x8c] */
/* @0x169a80 ldr r8, [r6, r3] */
/* @0x169a84 ldrb r3, [r8] */
/* @0x169a88 cmp r3, #0 */
/* @0x169a8c bne 0x169af0 <_Z19GR_D3D_Finish_Frameb+0x98> */
/* @0x169a90 bl 0x17de74 <_ZN8Graphics8SceneEndEv> */
/* @0x169a94 bl 0x215148 <Timing_Time> */
/* @0x169a98 cmp r9, #0 */
/* @0x169a9c mov r4, r0 */
/* @0x169aa0 mov r5, r1 */
/* @0x169aa4 bne 0x169ae8 <_Z19GR_D3D_Finish_Frameb+0x90> */
/* @0x169aa8 bl 0x215148 <Timing_Time> */
/* @0x169aac ldr r3, [pc, #0x60] */
/* @0x169ab0 ldrb r2, [r8] */
/* @0x169ab4 ldr r3, [r6, r3] */
/* @0x169ab8 subs r0, r0, r4 */
/* @0x169abc sbc r1, r1, r5 */
/* @0x169ac0 cmp r2, #0 */
/* @0x169ac4 strd r0, r1, [r3] */
/* @0x169ac8 bne 0x169ad4 <_Z19GR_D3D_Finish_Frameb+0x7c> */
/* @0x169acc mov r0, r7 */
/* @0x169ad0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x169ad4 ldr r3, [pc, #0x3c] */
/* @0x169ad8 ldr r0, [r6, r3] */
/* @0x169adc bl 0x2a08ac <_ZN9CProfiler3PopEv> */
/* @0x169ae0 mov r0, r7 */
/* @0x169ae4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x169ae8 bl 0x17df14 <_ZN8Graphics4FlipEv> */
/* @0x169aec b 0x169aa8 <_Z19GR_D3D_Finish_Frameb+0x50> */
/* @0x169af0 ldr r3, [pc, #0x20] */
/* @0x169af4 mov r1, #6 */
/* @0x169af8 mov r2, #26 */
/* @0x169afc ldr r0, [r6, r3] */
/* @0x169b00 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* @0x169b04 b 0x169a90 <_Z19GR_D3D_Finish_Frameb+0x38> */
/* @0x169b08 eoreq r8, r8, r8, ror #3 */
/* @0x169b0c .word 0xffffe4d0 */
/* @0x169b10 .word 0xffffbf18 */
/* @0x169b14 .word 0xffffe518 */
/* @0x169b18 .word 0xffffbf1c */

/* ── FUNC 0x169b1c · GR_D3D_Refresh() · size=24 · insn=6 */
/* @0x169b1c push {r3, lr} */
/* @0x169b20 bl 0x17dd58 <_ZN8Graphics10SceneBeginEv> */
/* @0x169b24 bl 0x17de74 <_ZN8Graphics8SceneEndEv> */
/* @0x169b28 bl 0x17df14 <_ZN8Graphics4FlipEv> */
/* @0x169b2c mov r0, #1 */
/* @0x169b30 pop {r3, pc} */

/* ── FUNC 0x169b34 · GR_D3D_Screenshot_Part(int, int, int, int) · size=416 · insn=104 */
/* @0x169b34 ldr r12, [pc, #0x194] */
/* @0x169b38 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x169b3c ldr r12, [pc, r12] */
/* @0x169b40 sub sp, sp, #28 */
/* @0x169b44 bic r4, r0, r0, asr #31 */
/* @0x169b48 ldr r9, [r12, #0x8] */
/* @0x169b4c add r0, r2, r4 */
/* @0x169b50 str r3, [sp, #0x8] */
/* @0x169b54 mov r5, r2 */
/* @0x169b58 ldr r3, [r12] */
/* @0x169b5c bic r7, r1, r1, asr #31 */
/* @0x169b60 str r2, [sp, #0xc] */
/* @0x169b64 rsb r9, r3, r9 */
/* @0x169b68 ldr r8, [r12, #0xc] */
/* @0x169b6c cmp r9, r0 */
/* @0x169b70 ldr r3, [r12, #0x4] */
/* @0x169b74 rsblt r2, r4, r9 */
/* @0x169b78 strlt r2, [sp, #0xc] */
/* @0x169b7c movge r2, r5 */
/* @0x169b80 ldr r5, [sp, #0x8] */
/* @0x169b84 rsb r8, r3, r8 */
/* @0x169b88 add r3, r5, r7 */
/* @0x169b8c cmp r8, r3 */
/* @0x169b90 rsblt r5, r7, r8 */
/* @0x169b94 strlt r5, [sp, #0x8] */
/* @0x169b98 cmp r2, #0 */
/* @0x169b9c cmpgt r5, #0 */
/* @0x169ba0 movgt r5, #0 */
/* @0x169ba4 movle r5, #1 */
/* @0x169ba8 movle r0, #0 */
/* @0x169bac ble 0x169cc8 <_Z22GR_D3D_Screenshot_Partiiii+0x194> */
/* @0x169bb0 bl 0x1a912c <_ZN7IBitmap6CreateEv> */
/* @0x169bb4 ldr r1, [sp, #0xc] */
/* @0x169bb8 ldr r3, [r0] */
/* @0x169bbc mov r6, r0 */
/* @0x169bc0 ldr r3, [r3, #0xc] */
/* @0x169bc4 blx r3 */
/* @0x169bc8 ldr r3, [r6] */
/* @0x169bcc mov r0, r6 */
/* @0x169bd0 ldr r1, [sp, #0x8] */
/* @0x169bd4 ldr r3, [r3, #0x14] */
/* @0x169bd8 blx r3 */
/* @0x169bdc ldr r3, [r6] */
/* @0x169be0 mov r0, r6 */
/* @0x169be4 mov r1, #7 */
/* @0x169be8 ldr r3, [r3, #0x1c] */
/* @0x169bec blx r3 */
/* @0x169bf0 mov r1, r8 */
/* @0x169bf4 add r12, sp, #12 */
/* @0x169bf8 mov r0, r9 */
/* @0x169bfc str r12, [sp] */
/* @0x169c00 mov r2, r4 */
/* @0x169c04 add r12, sp, #8 */
/* @0x169c08 mov r3, r7 */
/* @0x169c0c str r12, [sp, #0x4] */
/* @0x169c10 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */
/* @0x169c14 subs r8, r0, #0 */
/* @0x169c18 beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188> */
/* @0x169c1c str r5, [sp, #0x10] */
/* @0x169c20 mov r0, r6 */
/* @0x169c24 ldr r12, [r6] */
/* @0x169c28 mov r1, r5 */
/* @0x169c2c add r2, sp, #16 */
/* @0x169c30 add r3, sp, #20 */
/* @0x169c34 ldr r7, [sp, #0xc] */
/* @0x169c38 ldr r12, [r12, #0x24] */
/* @0x169c3c blx r12 */
/* @0x169c40 mov r9, r0 */
/* @0x169c44 ldr r0, [sp, #0x10] */
/* @0x169c48 cmp r0, #0 */
/* @0x169c4c beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188> */
/* @0x169c50 ldr r3, [sp, #0x14] */
/* @0x169c54 cmp r3, #0 */
/* @0x169c58 beq 0x169cbc <_Z22GR_D3D_Screenshot_Partiiii+0x188> */
/* @0x169c5c ldr r3, [sp, #0x8] */
/* @0x169c60 cmp r3, #0 */
/* @0x169c64 lslgt r7, r7, #2 */
/* @0x169c68 movgt r4, r8 */
/* @0x169c6c bgt 0x169c78 <_Z22GR_D3D_Screenshot_Partiiii+0x144> */
/* @0x169c70 b 0x169ca8 <_Z22GR_D3D_Screenshot_Partiiii+0x174> */
/* @0x169c74 mov r0, r3 */
/* @0x169c78 mov r1, r4 */
/* @0x169c7c mov r2, r7 */
/* @0x169c80 bl 0xb65bc <memcpy@plt> */
/* @0x169c84 ldr r3, [sp, #0x8] */
/* @0x169c88 add r5, r5, #1 */
/* @0x169c8c ldr r2, [sp, #0x10] */
/* @0x169c90 cmp r3, r5 */
/* @0x169c94 ldr r3, [sp, #0x14] */
/* @0x169c98 add r4, r4, r7 */
/* @0x169c9c add r3, r2, r3 */
/* @0x169ca0 str r3, [sp, #0x10] */
/* @0x169ca4 bgt 0x169c74 <_Z22GR_D3D_Screenshot_Partiiii+0x140> */
/* @0x169ca8 ldr r3, [r6] */
/* @0x169cac mov r1, r9 */
/* @0x169cb0 mov r0, r6 */
/* @0x169cb4 ldr r3, [r3, #0x28] */
/* @0x169cb8 blx r3 */
/* @0x169cbc mov r0, r8 */
/* @0x169cc0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x169cc4 mov r0, r6 */
/* @0x169cc8 add sp, sp, #28 */
/* @0x169ccc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x169cd0 eoreq r6, r8, r0, lsl r6 */

/* ── FUNC 0x169cd4 · GR_D3D_Screenshot_Full() · size=44 · insn=11 */
/* @0x169cd4 ldr r2, [pc, #0x1c] */
/* @0x169cd8 mov r0, #0 */
/* @0x169cdc ldr r3, [pc, #0x18] */
/* @0x169ce0 mov r1, r0 */
/* @0x169ce4 ldr r2, [pc, r2] */
/* @0x169ce8 ldr r3, [pc, r3] */
/* @0x169cec ldr r2, [r2] */
/* @0x169cf0 ldr r3, [r3] */
/* @0x169cf4 b 0x169b34 <_Z22GR_D3D_Screenshot_Partiiii> */
/* @0x169cf8 eoreq r6, r8, r0, asr r4 */
/* @0x169cfc eoreq r6, r8, r0, asr r4 */

/* ── FUNC 0x169d00 · GR_D3D_GetPixel(int, int) · size=112 · insn=28 */
/* @0x169d00 push {r4, lr} */
/* @0x169d04 sub sp, sp, #16 */
/* @0x169d08 ldr r12, [pc, #0x58] */
/* @0x169d0c mov r3, r1 */
/* @0x169d10 ldr lr, [pc, #0x54] */
/* @0x169d14 mov r2, r0 */
/* @0x169d18 ldr r12, [pc, r12] */
/* @0x169d1c ldr lr, [pc, lr] */
/* @0x169d20 ldr r0, [r12] */
/* @0x169d24 add r12, sp, #8 */
/* @0x169d28 ldr r1, [lr] */
/* @0x169d2c add lr, sp, #12 */
/* @0x169d30 str r12, [sp] */
/* @0x169d34 mov r12, #1 */
/* @0x169d38 str lr, [sp, #0x4] */
/* @0x169d3c str r12, [sp, #0x8] */
/* @0x169d40 str r12, [sp, #0xc] */
/* @0x169d44 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */
/* @0x169d48 subs r3, r0, #0 */
/* @0x169d4c moveq r0, r3 */
/* @0x169d50 beq 0x169d60 <_Z15GR_D3D_GetPixelii+0x60> */
/* @0x169d54 ldr r4, [r3] */
/* @0x169d58 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x169d5c mov r0, r4 */
/* @0x169d60 add sp, sp, #16 */
/* @0x169d64 pop {r4, pc} */
/* @0x169d68 eoreq r6, r8, r12, lsl r4 */
/* @0x169d6c eoreq r6, r8, r12, lsl r4 */

/* ── FUNC 0x169d70 · D3DXVector3(float, float, float, yyVector3&) · size=16 · insn=4 */
/* @0x169d70 str r0, [r3] */
/* @0x169d74 str r1, [r3, #0x4] */
/* @0x169d78 str r2, [r3, #0x8] */
/* @0x169d7c bx lr */

/* ── FUNC 0x169d80 · GR_Draw_Create_Color(int, int, int) · size=24 · insn=6 */
/* @0x169d80 lsl r1, r1, #8 */
/* @0x169d84 uxtb r2, r2 */
/* @0x169d88 uxth r1, r1 */
/* @0x169d8c add r1, r1, r2, lsl #16 */
/* @0x169d90 uxtab r0, r1, r0 */
/* @0x169d94 bx lr */

/* ── FUNC 0x169d98 · YYGML_draw_set_colour(unsigned int) · size=44 · insn=11 */
/* @0x169d98 ldr r3, [pc, #0x1c] */
/* @0x169d9c bic r0, r0, #-16777216 */
/* @0x169da0 ldr r2, [pc, #0x18] */
/* @0x169da4 ldr r3, [pc, r3] */
/* @0x169da8 ldr r2, [pc, r2] */
/* @0x169dac ldr r3, [r3] */
/* @0x169db0 orr r0, r0, r3, lsl #24 */
/* @0x169db4 str r0, [r2] */
/* @0x169db8 bx lr */
/* @0x169dbc eoreq r3, r8, r12, asr pc */
/* @0x169dc0 eoreq r3, r8, r4, asr pc */

/* ── FUNC 0x169dc4 · YYGML_draw_set_alpha(float) · size=112 · insn=28 */
/* @0x169dc4 vmov.f32 s14, #1.000000e+00 */
/* @0x169dc8 vmov s15, r0 */
/* @0x169dcc push {r4, lr} */
/* @0x169dd0 vcmpe.f32 s15, s14 */
/* @0x169dd4 vmrs APSR_nzcv, fpscr */
/* @0x169dd8 movgt r2, #255 */
/* @0x169ddc ble 0x169e08 <_Z20YYGML_draw_set_alphaf+0x44> */
/* @0x169de0 ldr r4, [pc, #0x44] */
/* @0x169de4 mov r1, r2 */
/* @0x169de8 ldr r3, [pc, #0x40] */
/* @0x169dec ldr r4, [pc, r4] */
/* @0x169df0 ldr r3, [pc, r3] */
/* @0x169df4 ldr r0, [r4] */
/* @0x169df8 str r2, [r3] */
/* @0x169dfc bl 0x16ca9c <_Z24GR_D3DColor_Change_Alphajj> */
/* @0x169e00 str r0, [r4] */
/* @0x169e04 pop {r4, pc} */
/* @0x169e08 vcmpe.f32 s15, #0 */
/* @0x169e0c vmrs APSR_nzcv, fpscr */
/* @0x169e10 vldrpl s14, [pc, #16] */
/* @0x169e14 vmulpl.f32 s15, s15, s14 */
/* @0x169e18 movmi r2, #0 */
/* @0x169e1c vcvtpl.u32.f32 s15, s15 */
/* @0x169e20 vmovpl r2, s15 */
/* @0x169e24 b 0x169de0 <_Z20YYGML_draw_set_alphaf+0x1c> */
/* @0x169e28 cmnmi pc, #0 */
/* @0x169e2c eoreq r3, r8, r0, lsl pc */
/* @0x169e30 eoreq r3, r8, r0, lsl pc */

/* ── FUNC 0x169e34 · GR_Draw_Set_Color3(int, int, int) · size=44 · insn=11 */
/* @0x169e34 push {r3, lr} */
/* @0x169e38 ldr r3, [pc, #0x18] */
/* @0x169e3c ldr r3, [pc, r3] */
/* @0x169e40 ldr r3, [r3] */
/* @0x169e44 bl 0x16ca74 <_Z19GR_RGBA_To_D3DColoriiij> */
/* @0x169e48 ldr r3, [pc, #0xc] */
/* @0x169e4c ldr r3, [pc, r3] */
/* @0x169e50 str r0, [r3] */
/* @0x169e54 pop {r3, pc} */
/* @0x169e58 eoreq r3, r8, r4, asr #29 */
/* @0x169e5c .word 0x00283eb0 */

/* ── FUNC 0x169e60 · GR_Draw_Set_Color4(int, int, int, float) · size=108 · insn=27 */
/* @0x169e60 vmov.f32 s14, #1.000000e+00 */
/* @0x169e64 vmov s15, r3 */
/* @0x169e68 push {r3, lr} */
/* @0x169e6c vcmpe.f32 s15, s14 */
/* @0x169e70 vmrs APSR_nzcv, fpscr */
/* @0x169e74 movgt lr, #255 */
/* @0x169e78 ble 0x169ea0 <_Z18GR_Draw_Set_Color4iiif+0x40> */
/* @0x169e7c ldr r12, [pc, #0x40] */
/* @0x169e80 mov r3, lr */
/* @0x169e84 ldr r12, [pc, r12] */
/* @0x169e88 str lr, [r12] */
/* @0x169e8c bl 0x16ca74 <_Z19GR_RGBA_To_D3DColoriiij> */
/* @0x169e90 ldr r3, [pc, #0x30] */
/* @0x169e94 ldr r3, [pc, r3] */
/* @0x169e98 str r0, [r3] */
/* @0x169e9c pop {r3, pc} */
/* @0x169ea0 vcmpe.f32 s15, #0 */
/* @0x169ea4 vmrs APSR_nzcv, fpscr */
/* @0x169ea8 vldrpl s14, [pc, #16] */
/* @0x169eac vmulpl.f32 s15, s15, s14 */
/* @0x169eb0 movmi lr, #0 */
/* @0x169eb4 vcvtpl.u32.f32 s15, s15 */
/* @0x169eb8 vmovpl lr, s15 */
/* @0x169ebc b 0x169e7c <_Z18GR_Draw_Set_Color4iiif+0x1c> */
/* @0x169ec0 cmnmi pc, #0 */
/* @0x169ec4 eoreq r3, r8, r12, ror lr */
/* @0x169ec8 eoreq r3, r8, r8, ror #28 */

/* ── FUNC 0x169ecc · GR_Draw_Get_Color() · size=20 · insn=5 */
/* @0x169ecc ldr r3, [pc, #0x8] */
/* @0x169ed0 ldr r3, [pc, r3] */
/* @0x169ed4 ldr r0, [r3] */
/* @0x169ed8 bx lr */
/* @0x169edc eoreq r3, r8, r12, lsr #28 */

/* ── FUNC 0x169ee0 · GR_Draw_Get_Color_Red() · size=20 · insn=5 */
/* @0x169ee0 ldr r3, [pc, #0x8] */
/* @0x169ee4 ldr r3, [pc, r3] */
/* @0x169ee8 ldrb r0, [r3, #0x2] */
/* @0x169eec bx lr */
/* @0x169ef0 eoreq r3, r8, r8, lsl lr */

/* ── FUNC 0x169ef4 · GR_Draw_Get_Color_Green() · size=20 · insn=5 */
/* @0x169ef4 ldr r3, [pc, #0x8] */
/* @0x169ef8 ldr r3, [pc, r3] */
/* @0x169efc ldrb r0, [r3, #0x1] */
/* @0x169f00 bx lr */
/* @0x169f04 eoreq r3, r8, r4, lsl #28 */

/* ── FUNC 0x169f08 · GR_Draw_Get_Color_Blue() · size=20 · insn=5 */
/* @0x169f08 ldr r3, [pc, #0x8] */
/* @0x169f0c ldr r3, [pc, r3] */
/* @0x169f10 ldrb r0, [r3] */
/* @0x169f14 bx lr */
/* @0x169f18 .word 0x00283df0 */
