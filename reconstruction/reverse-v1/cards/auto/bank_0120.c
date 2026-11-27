/* libyoyo.so 覆盖卡组 0120
 * 函数 0x1828a4..0x183d34，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1828a4 · LoadTextureFromPNG(Texture*, eMipEnable) · size=388 · insn=97 */
/* @0x1828a4 ldr r12, [r0, #0x10] */
/* @0x1828a8 push {r4, r5, r6, r7, r8, lr} */
/* @0x1828ac sub sp, sp, #40 */
/* @0x1828b0 mov r4, r0 */
/* @0x1828b4 eor r12, r12, #2 */
/* @0x1828b8 ldr r0, [r0, #0x2c] */
/* @0x1828bc ubfx r12, r12, #0x1, #0x1 */
/* @0x1828c0 mov r6, r1 */
/* @0x1828c4 add r2, sp, #28 */
/* @0x1828c8 ldr r1, [r4, #0x30] */
/* @0x1828cc add r3, sp, #32 */
/* @0x1828d0 str r12, [sp] */
/* @0x1828d4 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0x1828d8 ldr r5, [pc, #0x12c] */
/* @0x1828dc add r5, pc, r5 */
/* @0x1828e0 subs r7, r0, #0 */
/* @0x1828e4 beq 0x1829e0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x13c> */
/* @0x1828e8 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x1828ec ldr r3, [pc, #0x11c] */
/* @0x1828f0 ldr lr, [sp, #0x20] */
/* @0x1828f4 mov r0, #1 */
/* @0x1828f8 ldr r12, [sp, #0x1c] */
/* @0x1828fc add r1, sp, #36 */
/* @0x182900 ldr r3, [r5, r3] */
/* @0x182904 movw r8, #0x1401 */
/* @0x182908 ldr r2, [pc, #0x104] */
/* @0x18290c ldr r3, [r3] */
/* @0x182910 mul r12, r3, r12 */
/* @0x182914 mul r3, lr, r3 */
/* @0x182918 str r12, [r4, #0x4] */
/* @0x18291c str r3, [r4, #0x8] */
/* @0x182920 ldr r3, [r5, r2] */
/* @0x182924 ldr r3, [r3] */
/* @0x182928 blx r3 */
/* @0x18292c ldr r3, [pc, #0xe4] */
/* @0x182930 movw r0, #0xde1 */
/* @0x182934 ldr r1, [sp, #0x24] */
/* @0x182938 ldr r3, [r5, r3] */
/* @0x18293c ldr r3, [r3] */
/* @0x182940 blx r3 */
/* @0x182944 ldr r1, [pc, #0xd0] */
/* @0x182948 ldr r2, [sp, #0x20] */
/* @0x18294c mov lr, #0 */
/* @0x182950 movw r12, #0x1908 */
/* @0x182954 ldr r3, [sp, #0x1c] */
/* @0x182958 ldr r0, [r5, r1] */
/* @0x18295c mov r1, lr */
/* @0x182960 str r2, [sp] */
/* @0x182964 mov r2, r12 */
/* @0x182968 str r7, [sp, #0x10] */
/* @0x18296c ldr r5, [r0] */
/* @0x182970 movw r0, #0xde1 */
/* @0x182974 str lr, [sp, #0x4] */
/* @0x182978 str r12, [sp, #0x8] */
/* @0x18297c str r8, [sp, #0xc] */
/* @0x182980 blx r5 */
/* @0x182984 ldr r3, [r4, #0x10] */
/* @0x182988 cmp r6, #1 */
/* @0x18298c orr r2, r3, #64 */
/* @0x182990 str r2, [r4, #0x10] */
/* @0x182994 beq 0x1829c4 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x120> */
/* @0x182998 cmp r6, #2 */
/* @0x18299c beq 0x1829bc <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0x118> */
/* @0x1829a0 bl 0x18a518 <_Z11FreePNGFilev> */
/* @0x1829a4 ldr r0, [sp, #0x24] */
/* @0x1829a8 mov r3, #6 */
/* @0x1829ac str r3, [r4] */
/* @0x1829b0 str r0, [r4, #0x14] */
/* @0x1829b4 add sp, sp, #40 */
/* @0x1829b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1829bc tst r3, #16 */
/* @0x1829c0 beq 0x1829a0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0xfc> */
/* @0x1829c4 ldr r1, [sp, #0x1c] */
/* @0x1829c8 mov r0, r4 */
/* @0x1829cc ldr r2, [sp, #0x20] */
/* @0x1829d0 mov r3, #4 */
/* @0x1829d4 str r7, [sp] */
/* @0x1829d8 bl 0x181db0 <_Z12GenerateMipsP7TextureiiiPc> */
/* @0x1829dc b 0x1829a0 <_Z18LoadTextureFromPNGP7Texture10eMipEnable+0xfc> */
/* @0x1829e0 ldr r3, [pc, #0x38] */
/* @0x1829e4 ldr r1, [pc, #0x38] */
/* @0x1829e8 ldr r3, [r5, r3] */
/* @0x1829ec add r1, pc, r1 */
/* @0x1829f0 ldr r0, [r3] */
/* @0x1829f4 ldr r3, [r0] */
/* @0x1829f8 ldr r3, [r3, #0xc] */
/* @0x1829fc blx r3 */
/* @0x182a00 mov r0, r7 */
/* @0x182a04 add sp, sp, #40 */
/* @0x182a08 pop {r4, r5, r6, r7, r8, pc} */
/* @0x182a0c eoreq pc, r6, r4, ror r3 */
/* @0x182a10 .word 0xffffc984 */
/* @0x182a14 .word 0xffffbb28 */
/* @0x182a18 .word 0xffffbb20 */
/* @0x182a1c .word 0xffffbb2c */
/* @0x182a20 .word 0xffffbac4 */
/* @0x182a24 andseq r9, r12, r0, lsl r1 */

/* ── FUNC 0x182a28 · Graphics::SetTexture(int, void*) · size=808 · insn=202 */
/* @0x182a28 push {r4, r5, r6, r7, r8, lr} */
/* @0x182a2c mov r7, r0 */
/* @0x182a30 ldr r4, [pc, #0x2d4] */
/* @0x182a34 mov r5, r1 */
/* @0x182a38 ldr r3, [pc, #0x2d0] */
/* @0x182a3c add r4, pc, r4 */
/* @0x182a40 ldr r6, [r4, r3] */
/* @0x182a44 ldr r3, [r6] */
/* @0x182a48 cmp r3, #0 */
/* @0x182a4c bne 0x182b18 <_ZN8Graphics10SetTextureEiPv+0xf0> */
/* @0x182a50 ldr r3, [pc, #0x2bc] */
/* @0x182a54 ldr r8, [r4, r3] */
/* @0x182a58 ldr r3, [r8] */
/* @0x182a5c cmp r3, r1 */
/* @0x182a60 beq 0x182c38 <_ZN8Graphics10SetTextureEiPv+0x210> */
/* @0x182a64 ldr r3, [pc, #0x2ac] */
/* @0x182a68 ldr r3, [r4, r3] */
/* @0x182a6c ldrb r3, [r3] */
/* @0x182a70 cmp r3, #0 */
/* @0x182a74 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x182a78 cmp r1, #0 */
/* @0x182a7c beq 0x182c74 <_ZN8Graphics10SetTextureEiPv+0x24c> */
/* @0x182a80 mov r0, r5 */
/* @0x182a84 bl 0x180884 <_Z28isTextureBoundAsRenderTargetP7Texture> */
/* @0x182a88 cmp r0, #0 */
/* @0x182a8c bne 0x182c14 <_ZN8Graphics10SetTextureEiPv+0x1ec> */
/* @0x182a90 ldr r3, [pc, #0x284] */
/* @0x182a94 mov r1, r7 */
/* @0x182a98 mov r2, #9 */
/* @0x182a9c ldr r0, [r4, r3] */
/* @0x182aa0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x182aa4 mov r1, #1 */
/* @0x182aa8 mov r2, r0 */
/* @0x182aac mov r0, r5 */
/* @0x182ab0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x182ab4 ldr r3, [pc, #0x264] */
/* @0x182ab8 movw r0, #0xde1 */
/* @0x182abc ldr r3, [r4, r3] */
/* @0x182ac0 ldr r3, [r3] */
/* @0x182ac4 blx r3 */
/* @0x182ac8 ldr r3, [pc, #0x254] */
/* @0x182acc ldr r3, [r4, r3] */
/* @0x182ad0 ldr r2, [r3] */
/* @0x182ad4 cmp r5, r2 */
/* @0x182ad8 beq 0x182b14 <_ZN8Graphics10SetTextureEiPv+0xec> */
/* @0x182adc ldr r1, [pc, #0x244] */
/* @0x182ae0 movw r0, #0xde1 */
/* @0x182ae4 str r5, [r3] */
/* @0x182ae8 ldr r2, [pc, #0x23c] */
/* @0x182aec ldr r3, [r4, r1] */
/* @0x182af0 ldr r1, [r5, #0x14] */
/* @0x182af4 ldr r12, [r3] */
/* @0x182af8 add r12, r12, #1 */
/* @0x182afc str r12, [r3] */
/* @0x182b00 ldr r3, [r4, r2] */
/* @0x182b04 ldr r3, [r3] */
/* @0x182b08 blx r3 */
/* @0x182b0c str r5, [r8] */
/* @0x182b10 bl 0x180b28 <_Z26_SetCurrentTextureSettingsv> */
/* @0x182b14 ldr r3, [r6] */
/* @0x182b18 cmp r3, #1 */
/* @0x182b1c popne {r4, r5, r6, r7, r8, pc} */
/* @0x182b20 cmp r7, #7 */
/* @0x182b24 pophi {r4, r5, r6, r7, r8, pc} */
/* @0x182b28 ldr r3, [pc, #0x200] */
/* @0x182b2c ldr r3, [r4, r3] */
/* @0x182b30 ldrb r3, [r3] */
/* @0x182b34 cmp r3, #0 */
/* @0x182b38 bne 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128> */
/* @0x182b3c ldr r3, [pc, #0x1d0] */
/* @0x182b40 ldr r3, [r4, r3] */
/* @0x182b44 ldr r3, [r3, r7, lsl #2] */
/* @0x182b48 cmp r3, r5 */
/* @0x182b4c beq 0x182cd0 <_ZN8Graphics10SetTextureEiPv+0x2a8> */
/* @0x182b50 ldr r3, [pc, #0x1c0] */
/* @0x182b54 ldr r3, [r4, r3] */
/* @0x182b58 ldrb r3, [r3] */
/* @0x182b5c cmp r3, #0 */
/* @0x182b60 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x182b64 ldr r3, [pc, #0x1c8] */
/* @0x182b68 ldr r6, [r4, r3] */
/* @0x182b6c ldr r3, [r6] */
/* @0x182b70 cmp r3, r7 */
/* @0x182b74 beq 0x182b94 <_ZN8Graphics10SetTextureEiPv+0x16c> */
/* @0x182b78 ldr r3, [pc, #0x1b8] */
/* @0x182b7c add r0, r7, #33792 */
/* @0x182b80 str r7, [r6] */
/* @0x182b84 add r0, r0, #192 */
/* @0x182b88 ldr r3, [r4, r3] */
/* @0x182b8c ldr r3, [r3] */
/* @0x182b90 blx r3 */
/* @0x182b94 cmp r5, #0 */
/* @0x182b98 beq 0x182c94 <_ZN8Graphics10SetTextureEiPv+0x26c> */
/* @0x182b9c mov r0, r5 */
/* @0x182ba0 bl 0x180884 <_Z28isTextureBoundAsRenderTargetP7Texture> */
/* @0x182ba4 cmp r0, #0 */
/* @0x182ba8 bne 0x182c64 <_ZN8Graphics10SetTextureEiPv+0x23c> */
/* @0x182bac ldr r3, [pc, #0x168] */
/* @0x182bb0 mov r1, r7 */
/* @0x182bb4 mov r2, #9 */
/* @0x182bb8 ldr r0, [r4, r3] */
/* @0x182bbc bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x182bc0 mov r1, #1 */
/* @0x182bc4 mov r2, r0 */
/* @0x182bc8 mov r0, r5 */
/* @0x182bcc bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x182bd0 ldr r3, [pc, #0x150] */
/* @0x182bd4 ldr r2, [pc, #0x150] */
/* @0x182bd8 movw r0, #0xde1 */
/* @0x182bdc ldr r1, [r5, #0x14] */
/* @0x182be0 ldr r3, [r4, r3] */
/* @0x182be4 ldr r12, [r3] */
/* @0x182be8 add r12, r12, #1 */
/* @0x182bec str r12, [r3] */
/* @0x182bf0 ldr r3, [r4, r2] */
/* @0x182bf4 ldr r3, [r3] */
/* @0x182bf8 blx r3 */
/* @0x182bfc ldr r3, [pc, #0x110] */
/* @0x182c00 ldr r2, [r6] */
/* @0x182c04 ldr r3, [r4, r3] */
/* @0x182c08 str r5, [r3, r2, lsl #2] */
/* @0x182c0c pop {r4, r5, r6, r7, r8, lr} */
/* @0x182c10 b 0x180b28 <_Z26_SetCurrentTextureSettingsv> */
/* @0x182c14 ldr r1, [pc, #0x120] */
/* @0x182c18 ldr r3, [pc, #0x120] */
/* @0x182c1c add r1, pc, r1 */
/* @0x182c20 ldr r3, [r4, r3] */
/* @0x182c24 ldr r0, [r3] */
/* @0x182c28 ldr r3, [r0] */
/* @0x182c2c ldr r3, [r3, #0xc] */
/* @0x182c30 blx r3 */
/* @0x182c34 pop {r4, r5, r6, r7, r8, pc} */
/* @0x182c38 cmp r1, #0 */
/* @0x182c3c popeq {r4, r5, r6, r7, r8, pc} */
/* @0x182c40 ldr r3, [r1, #0x14] */
/* @0x182c44 cmn r3, #1 */
/* @0x182c48 popne {r4, r5, r6, r7, r8, pc} */
/* @0x182c4c ldr r3, [pc, #0xc4] */
/* @0x182c50 ldr r3, [r4, r3] */
/* @0x182c54 ldrb r3, [r3] */
/* @0x182c58 cmp r3, #0 */
/* @0x182c5c bne 0x182a80 <_ZN8Graphics10SetTextureEiPv+0x58> */
/* @0x182c60 pop {r4, r5, r6, r7, r8, pc} */
/* @0x182c64 ldr r1, [pc, #0xd8] */
/* @0x182c68 ldr r3, [pc, #0xd0] */
/* @0x182c6c add r1, pc, r1 */
/* @0x182c70 b 0x182c20 <_ZN8Graphics10SetTextureEiPv+0x1f8> */
/* @0x182c74 ldr r3, [pc, #0xcc] */
/* @0x182c78 movw r0, #0xde1 */
/* @0x182c7c ldr r3, [r4, r3] */
/* @0x182c80 ldr r3, [r3] */
/* @0x182c84 blx r3 */
/* @0x182c88 str r5, [r8] */
/* @0x182c8c ldr r3, [r6] */
/* @0x182c90 b 0x182b18 <_ZN8Graphics10SetTextureEiPv+0xf0> */
/* @0x182c94 ldr r3, [pc, #0xb0] */
/* @0x182c98 ldr r7, [r4, r3] */
/* @0x182c9c ldr r0, [r7] */
/* @0x182ca0 cmp r0, #0 */
/* @0x182ca4 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x182ca8 mov r1, r5 */
/* @0x182cac mvn r2, #0 */
/* @0x182cb0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x182cb4 ldr r3, [pc, #0x6c] */
/* @0x182cb8 ldr r1, [r7] */
/* @0x182cbc movw r0, #0xde1 */
/* @0x182cc0 ldr r2, [pc, #0x64] */
/* @0x182cc4 ldr r3, [r4, r3] */
/* @0x182cc8 ldr r1, [r1, #0x14] */
/* @0x182ccc b 0x182be4 <_ZN8Graphics10SetTextureEiPv+0x1bc> */
/* @0x182cd0 cmp r5, #0 */
/* @0x182cd4 beq 0x182ce8 <_ZN8Graphics10SetTextureEiPv+0x2c0> */
/* @0x182cd8 ldr r3, [r5, #0x14] */
/* @0x182cdc cmn r3, #1 */
/* @0x182ce0 popne {r4, r5, r6, r7, r8, pc} */
/* @0x182ce4 b 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128> */
/* @0x182ce8 ldr r3, [pc, #0x5c] */
/* @0x182cec ldr r3, [r4, r3] */
/* @0x182cf0 ldr r3, [r3] */
/* @0x182cf4 cmp r3, #0 */
/* @0x182cf8 beq 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128> */
/* @0x182cfc ldr r3, [r3, #0x14] */
/* @0x182d00 cmn r3, #1 */
/* @0x182d04 popne {r4, r5, r6, r7, r8, pc} */
/* @0x182d08 b 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128> */
/* @0x182d0c eoreq pc, r6, r4, lsl r2 */
/* @0x182d10 .word 0xffffe7b8 */
/* @0x182d14 .word 0xffffe8e8 */
/* @0x182d18 .word 0xffffe4d0 */
/* @0x182d1c .word 0xffffc0a8 */
/* @0x182d20 .word 0xffffbad8 */
/* @0x182d24 .word 0xffffe8f4 */
/* @0x182d28 .word 0xffffe740 */
/* @0x182d2c .word 0xffffbb20 */
/* @0x182d30 .word 0xffffe904 */
/* @0x182d34 .word 0xffffe808 */
/* @0x182d38 .word 0xffffbbf0 */
/* @0x182d3c andseq r8, r12, r12, lsl #30 */
/* @0x182d40 .word 0xffffbac4 */
/* @0x182d44 ldrheq r8, [r12], -r12 */
/* @0x182d48 .word 0xffffbad0 */
/* @0x182d4c .word 0xffffe8fc */

/* ── FUNC 0x182d50 · ResetCurrentTextures() · size=80 · insn=20 */
/* @0x182d50 push {r4, r5, r6, lr} */
/* @0x182d54 mov r4, #0 */
/* @0x182d58 ldr r5, [pc, #0x38] */
/* @0x182d5c mov r3, #1 */
/* @0x182d60 ldr r6, [pc, #0x34] */
/* @0x182d64 ldr r5, [pc, r5] */
/* @0x182d68 ldr r6, [pc, r6] */
/* @0x182d6c sub r5, r5, #4 */
/* @0x182d70 strb r3, [r6] */
/* @0x182d74 mov r0, r4 */
/* @0x182d78 ldr r1, [r5, #0x4]! */
/* @0x182d7c add r4, r4, #1 */
/* @0x182d80 bl 0x182a28 <_ZN8Graphics10SetTextureEiPv> */
/* @0x182d84 cmp r4, #8 */
/* @0x182d88 bne 0x182d74 <_Z20ResetCurrentTexturesv+0x24> */
/* @0x182d8c mov r3, #0 */
/* @0x182d90 strb r3, [r6] */
/* @0x182d94 pop {r4, r5, r6, pc} */
/* @0x182d98 .word 0x0026d7d4 */
/* @0x182d9c eoreq sp, r6, r12, ror #15 */

/* ── FUNC 0x182da0 · _GetCPUSideTextureData(Texture*, bool&) · size=220 · insn=55 */
/* @0x182da0 ldr r3, [r0, #0x2c] */
/* @0x182da4 push {r4, r5, lr} */
/* @0x182da8 mov r4, #0 */
/* @0x182dac cmp r3, r4 */
/* @0x182db0 sub sp, sp, #20 */
/* @0x182db4 mov r5, r1 */
/* @0x182db8 strb r4, [r1] */
/* @0x182dbc ldreq r0, [r0, #0x28] */
/* @0x182dc0 beq 0x182e20 <_Z22_GetCPUSideTextureDataP7TextureRb+0x80> */
/* @0x182dc4 ldr r12, [r3] */
/* @0x182dc8 movw r2, #0x4152 */
/* @0x182dcc movt r2, #0x2057 */
/* @0x182dd0 cmp r12, r2 */
/* @0x182dd4 beq 0x182e34 <_Z22_GetCPUSideTextureDataP7TextureRb+0x94> */
/* @0x182dd8 movw r2, #0x5089 */
/* @0x182ddc movt r2, #0x474e */
/* @0x182de0 cmp r12, r2 */
/* @0x182de4 beq 0x182e4c <_Z22_GetCPUSideTextureDataP7TextureRb+0xac> */
/* @0x182de8 ldr r2, [r3, #0x2c] */
/* @0x182dec movw r3, #0x5650 */
/* @0x182df0 movt r3, #0x2152 */
/* @0x182df4 cmp r2, r3 */
/* @0x182df8 beq 0x182e28 <_Z22_GetCPUSideTextureDataP7TextureRb+0x88> */
/* @0x182dfc ldr r3, [pc, #0x70] */
/* @0x182e00 ldr r1, [pc, #0x70] */
/* @0x182e04 ldr r3, [pc, r3] */
/* @0x182e08 add r1, pc, r1 */
/* @0x182e0c ldr r0, [r3] */
/* @0x182e10 ldr r3, [r0] */
/* @0x182e14 ldr r3, [r3, #0xc] */
/* @0x182e18 blx r3 */
/* @0x182e1c mov r0, r4 */
/* @0x182e20 add sp, sp, #20 */
/* @0x182e24 pop {r4, r5, pc} */
/* @0x182e28 mov r0, r4 */
/* @0x182e2c add sp, sp, #20 */
/* @0x182e30 pop {r4, r5, pc} */
/* @0x182e34 ldr r2, [r3, #0xc] */
/* @0x182e38 cmp r2, #1 */
/* @0x182e3c beq 0x182e28 <_Z22_GetCPUSideTextureDataP7TextureRb+0x88> */
/* @0x182e40 add r0, r3, #16 */
/* @0x182e44 add sp, sp, #20 */
/* @0x182e48 pop {r4, r5, pc} */
/* @0x182e4c ldr r1, [r0, #0x30] */
/* @0x182e50 add r2, sp, #8 */
/* @0x182e54 mov r0, r3 */
/* @0x182e58 str r4, [sp] */
/* @0x182e5c add r3, sp, #12 */
/* @0x182e60 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0x182e64 cmp r0, #0 */
/* @0x182e68 movne r3, #1 */
/* @0x182e6c strbne r3, [r5] */
/* @0x182e70 b 0x182e20 <_Z22_GetCPUSideTextureDataP7TextureRb+0x80> */
/* @0x182e74 eoreq r10, r6, r0, lsl r9 */
/* @0x182e78 andseq r8, r12, r12, ror #25 */

/* ── FUNC 0x182e7c · _SetTextureInfo(Texture*) · size=136 · insn=34 */
/* @0x182e7c ldr r3, [r0, #0x2c] */
/* @0x182e80 movw r1, #0x4152 */
/* @0x182e84 movt r1, #0x2057 */
/* @0x182e88 mov r2, r0 */
/* @0x182e8c ldr r12, [r3] */
/* @0x182e90 cmp r12, r1 */
/* @0x182e94 beq 0x182ed8 <_Z15_SetTextureInfoP7Texture+0x5c> */
/* @0x182e98 movw r1, #0x5089 */
/* @0x182e9c movt r1, #0x474e */
/* @0x182ea0 cmp r12, r1 */
/* @0x182ea4 beq 0x182f00 <_Z15_SetTextureInfoP7Texture+0x84> */
/* @0x182ea8 ldr r0, [r3, #0x2c] */
/* @0x182eac movw r1, #0x5650 */
/* @0x182eb0 movt r1, #0x2152 */
/* @0x182eb4 cmp r0, r1 */
/* @0x182eb8 bxne lr */
/* @0x182ebc ldr r1, [r3, #0x4] */
/* @0x182ec0 mov r0, #6 */
/* @0x182ec4 ldr r3, [r3, #0x8] */
/* @0x182ec8 str r0, [r2] */
/* @0x182ecc str r1, [r2, #0x8] */
/* @0x182ed0 str r3, [r2, #0x4] */
/* @0x182ed4 bx lr */
/* @0x182ed8 ldr r0, [r3, #0xc] */
/* @0x182edc ldr r1, [r3, #0x8] */
/* @0x182ee0 ldr r3, [r3, #0x4] */
/* @0x182ee4 cmp r0, #1 */
/* @0x182ee8 str r1, [r2, #0x8] */
/* @0x182eec str r3, [r2, #0x4] */
/* @0x182ef0 moveq r3, #11 */
/* @0x182ef4 movne r3, #6 */
/* @0x182ef8 str r3, [r2] */
/* @0x182efc bx lr */
/* @0x182f00 b 0x189968 <_Z14getTextureInfoP7Texture> */

/* ── FUNC 0x182f04 · Graphics::PrefetchTexture(void*) · size=56 · insn=14 */
/* @0x182f04 push {r4, lr} */
/* @0x182f08 subs r4, r0, #0 */
/* @0x182f0c popeq {r4, pc} */
/* @0x182f10 ldr r0, [pc, #0x20] */
/* @0x182f14 mov r1, #0 */
/* @0x182f18 mov r2, #9 */
/* @0x182f1c ldr r0, [pc, r0] */
/* @0x182f20 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState> */
/* @0x182f24 mov r1, #1 */
/* @0x182f28 mov r2, r0 */
/* @0x182f2c mov r0, r4 */
/* @0x182f30 pop {r4, lr} */
/* @0x182f34 b 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x182f38 .word 0x0026addc */

/* ── FUNC 0x182f3c · Graphics::CreateTextureFromFile(unsigned char*, unsigned int, ImageInfo*, eTextureFormat, bool) · size=196 · insn=49 */
/* @0x182f3c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x182f40 mov r6, r0 */
/* @0x182f44 mov r0, #56 */
/* @0x182f48 mov r5, r2 */
/* @0x182f4c mov r7, r1 */
/* @0x182f50 mov r8, r3 */
/* @0x182f54 ldrb r9, [sp, #0x20] */
/* @0x182f58 bl 0x27c524 <_Znwj> */
/* @0x182f5c ldr r12, [pc, #0x98] */
/* @0x182f60 mvn r2, #0 */
/* @0x182f64 cmp r9, #0 */
/* @0x182f68 ldr r12, [pc, r12] */
/* @0x182f6c ldr r3, [r12] */
/* @0x182f70 mov r4, r0 */
/* @0x182f74 str r6, [r0, #0x2c] */
/* @0x182f78 str r4, [r12] */
/* @0x182f7c mov r0, #0 */
/* @0x182f80 str r3, [r4, #0x34] */
/* @0x182f84 moveq r3, #2 */
/* @0x182f88 str r0, [r4, #0x10] */
/* @0x182f8c str r0, [r4, #0x4] */
/* @0x182f90 streq r3, [r4, #0x10] */
/* @0x182f94 str r0, [r4, #0x8] */
/* @0x182f98 str r0, [r4, #0xc] */
/* @0x182f9c str r0, [r4, #0x24] */
/* @0x182fa0 str r0, [r4, #0x28] */
/* @0x182fa4 mov r0, r4 */
/* @0x182fa8 str r2, [r4, #0x14] */
/* @0x182fac str r2, [r4, #0x18] */
/* @0x182fb0 str r2, [r4, #0x1c] */
/* @0x182fb4 str r2, [r4, #0x20] */
/* @0x182fb8 str r7, [r4, #0x30] */
/* @0x182fbc str r8, [r4] */
/* @0x182fc0 bl 0x182e7c <_Z15_SetTextureInfoP7Texture> */
/* @0x182fc4 ldr r3, [r4] */
/* @0x182fc8 ldr r12, [r4, #0x8] */
/* @0x182fcc mov r0, r4 */
/* @0x182fd0 ldr r2, [r4, #0x4] */
/* @0x182fd4 cmp r3, #6 */
/* @0x182fd8 str r3, [r5, #0x18] */
/* @0x182fdc mov r3, #0 */
/* @0x182fe0 movne r1, #16 */
/* @0x182fe4 moveq r1, #32 */
/* @0x182fe8 str r12, [r5, #0x4] */
/* @0x182fec str r2, [r5] */
/* @0x182ff0 str r3, [r5, #0xc] */
/* @0x182ff4 str r1, [r5, #0x8] */
/* @0x182ff8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x182ffc eoreq sp, r6, r12, asr #6 */

/* ── FUNC 0x183000 · Graphics::CopySurface(void*, int, int, int, void*) · size=220 · insn=55 */
/* @0x183000 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x183004 mov r9, r0 */
/* @0x183008 ldr r0, [r0, #0x8] */
/* @0x18300c mov r7, r2 */
/* @0x183010 mov r4, r3 */
/* @0x183014 ldr r5, [sp, #0x20] */
/* @0x183018 cmp r0, #0 */
/* @0x18301c beq 0x18302c <_ZN8Graphics11CopySurfaceEPviiiS0_+0x2c> */
/* @0x183020 ldr r8, [r9, #0x4] */
/* @0x183024 cmp r8, #0 */
/* @0x183028 bne 0x183034 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x34> */
/* @0x18302c mov r0, #1 */
/* @0x183030 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x183034 cmp r3, #0 */
/* @0x183038 cmpne r2, #0 */
/* @0x18303c movne r1, #0 */
/* @0x183040 moveq r1, #1 */
/* @0x183044 beq 0x18302c <_ZN8Graphics11CopySurfaceEPviiiS0_+0x2c> */
/* @0x183048 cmp r8, r7 */
/* @0x18304c cmple r0, r4 */
/* @0x183050 ldr r6, [r9, #0x28] */
/* @0x183054 bgt 0x1830c0 <_ZN8Graphics11CopySurfaceEPviiiS0_+0xc0> */
/* @0x183058 cmp r4, #0 */
/* @0x18305c lslgt r7, r7, #2 */
/* @0x183060 lslgt r8, r8, #2 */
/* @0x183064 ble 0x183088 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x88> */
/* @0x183068 mov r0, r6 */
/* @0x18306c mov r1, r5 */
/* @0x183070 mov r2, r7 */
/* @0x183074 add r6, r6, r8 */
/* @0x183078 bl 0xb65bc <memcpy@plt> */
/* @0x18307c subs r4, r4, #1 */
/* @0x183080 add r5, r5, r7 */
/* @0x183084 bne 0x183068 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x68> */
/* @0x183088 mov r0, r9 */
/* @0x18308c mvn r2, #0 */
/* @0x183090 mov r1, #1 */
/* @0x183094 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x183098 ldr r3, [pc, #0x34] */
/* @0x18309c ldr r1, [pc, #0x34] */
/* @0x1830a0 ldr r3, [pc, r3] */
/* @0x1830a4 add r1, pc, r1 */
/* @0x1830a8 ldr r0, [r3] */
/* @0x1830ac ldr r3, [r0] */
/* @0x1830b0 ldr r3, [r3, #0xc] */
/* @0x1830b4 blx r3 */
/* @0x1830b8 mov r0, #1 */
/* @0x1830bc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1830c0 mul r2, r8, r0 */
/* @0x1830c4 mov r0, r6 */
/* @0x1830c8 lsl r2, r2, #2 */
/* @0x1830cc bl 0xb65b0 <memset@plt> */
/* @0x1830d0 b 0x183058 <_ZN8Graphics11CopySurfaceEPviiiS0_+0x58> */
/* @0x1830d4 eoreq r10, r6, r4, ror r6 */
/* @0x1830d8 andseq r8, r12, r8, asr #21 */

/* ── FUNC 0x1830dc · SetupBlankTexture() · size=156 · insn=39 */
/* @0x1830dc push {r4, r11, lr} */
/* @0x1830e0 add r11, sp, #8 */
/* @0x1830e4 ldr r4, [pc, #0x84] */
/* @0x1830e8 sub sp, sp, #20 */
/* @0x1830ec mov r0, #16 */
/* @0x1830f0 ldr r4, [pc, r4] */
/* @0x1830f4 mov r12, #6 */
/* @0x1830f8 mov r1, r0 */
/* @0x1830fc mov r2, #1 */
/* @0x183100 ldr lr, [r4] */
/* @0x183104 mov r3, #0 */
/* @0x183108 str lr, [r11, #-0x10] */
/* @0x18310c str r12, [sp] */
/* @0x183110 bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat> */
/* @0x183114 ldr r12, [pc, #0x58] */
/* @0x183118 sub r1, sp, #1024 */
/* @0x18311c mov r3, #0 */
/* @0x183120 ldr r12, [pc, r12] */
/* @0x183124 sub sp, r1, #8 */
/* @0x183128 mvn r2, #0 */
/* @0x18312c str r0, [r12] */
/* @0x183130 str r2, [r1, r3] */
/* @0x183134 add r3, r3, #4 */
/* @0x183138 cmp r3, #1024 */
/* @0x18313c bne 0x183130 <_Z17SetupBlankTexturev+0x54> */
/* @0x183140 mov r2, #16 */
/* @0x183144 str r1, [sp] */
/* @0x183148 mov r3, r2 */
/* @0x18314c mov r1, #0 */
/* @0x183150 bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_> */
/* @0x183154 ldr r2, [r11, #-0x10] */
/* @0x183158 ldr r3, [r4] */
/* @0x18315c cmp r2, r3 */
/* @0x183160 bne 0x18316c <_Z17SetupBlankTexturev+0x90> */
/* @0x183164 sub sp, r11, #8 */
/* @0x183168 pop {r4, r11, pc} */
/* @0x18316c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x183170 eoreq r10, r6, r0, ror #16 */
/* @0x183174 eoreq sp, r6, r12, lsr #8 */

/* ── FUNC 0x183178 · InitTextureResources() · size=16 · insn=4 */
/* @0x183178 push {r3, lr} */
/* @0x18317c bl 0x181190 <_Z20FreeTextureResourcesv> */
/* @0x183180 pop {r3, lr} */
/* @0x183184 b 0x1830dc <_Z17SetupBlankTexturev> */

/* ── FUNC 0x183188 · Graphics::CreateTextureFromData(unsigned char*, int, int, ImageInfo*, eTextureFormat) · size=184 · insn=46 */
/* @0x183188 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x18318c mov r9, r0 */
/* @0x183190 sub sp, sp, #12 */
/* @0x183194 mov r0, r1 */
/* @0x183198 mov r4, r3 */
/* @0x18319c mov r5, r2 */
/* @0x1831a0 mov r6, r1 */
/* @0x1831a4 bl 0x181320 <_Z11GetPOW2Sizei> */
/* @0x1831a8 mov r7, #0 */
/* @0x1831ac mov r8, r0 */
/* @0x1831b0 mov r0, r5 */
/* @0x1831b4 bl 0x181320 <_Z11GetPOW2Sizei> */
/* @0x1831b8 ldr r3, [pc, #0x7c] */
/* @0x1831bc mvn r2, #0 */
/* @0x1831c0 str r2, [r4, #0x14] */
/* @0x1831c4 ldr r3, [pc, r3] */
/* @0x1831c8 str r7, [r4, #0xc] */
/* @0x1831cc mov r1, #32 */
/* @0x1831d0 str r1, [r4, #0x8] */
/* @0x1831d4 ldrb r2, [r3] */
/* @0x1831d8 mov r1, r5 */
/* @0x1831dc mov r3, #6 */
/* @0x1831e0 str r3, [r4, #0x18] */
/* @0x1831e4 cmp r2, r7 */
/* @0x1831e8 str r3, [r4, #0x10] */
/* @0x1831ec mov r2, r7 */
/* @0x1831f0 str r3, [sp] */
/* @0x1831f4 movne r8, r6 */
/* @0x1831f8 mov r3, r7 */
/* @0x1831fc str r8, [r4] */
/* @0x183200 moveq r12, r0 */
/* @0x183204 movne r12, r5 */
/* @0x183208 mov r0, r6 */
/* @0x18320c str r12, [r4, #0x4] */
/* @0x183210 bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat> */
/* @0x183214 subs r4, r0, #0 */
/* @0x183218 beq 0x183230 <_ZN8Graphics21CreateTextureFromDataEPhiiP9ImageInfo14eTextureFormat+0xa8> */
/* @0x18321c str r9, [sp] */
/* @0x183220 mov r1, r7 */
/* @0x183224 mov r2, r6 */
/* @0x183228 mov r3, r5 */
/* @0x18322c bl 0x183000 <_ZN8Graphics11CopySurfaceEPviiiS0_> */
/* @0x183230 mov r0, r4 */
/* @0x183234 add sp, sp, #12 */
/* @0x183238 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x18323c eoreq sp, r6, r8, asr r2 */

/* ── FUNC 0x183240 · Graphics::UpdateRegion(void*, int, int, int, int) · size=388 · insn=97 */
/* @0x183240 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x183244 subs r4, r0, #0 */
/* @0x183248 sub sp, sp, #36 */
/* @0x18324c beq 0x1833a8 <_ZN8Graphics12UpdateRegionEPviiii+0x168> */
/* @0x183250 ldr r5, [r4, #0x28] */
/* @0x183254 cmp r5, #0 */
/* @0x183258 beq 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c> */
/* @0x18325c ldr r0, [r4, #0x14] */
/* @0x183260 cmn r0, #1 */
/* @0x183264 beq 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158> */
/* @0x183268 ldr r9, [r4, #0x4] */
/* @0x18326c bic r6, r1, r1, asr #31 */
/* @0x183270 ldr r0, [r4, #0x8] */
/* @0x183274 cmp r9, r6 */
/* @0x183278 ble 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158> */
/* @0x18327c bic r8, r2, r2, asr #31 */
/* @0x183280 cmp r8, r0 */
/* @0x183284 bge 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158> */
/* @0x183288 adds r1, r1, r3 */
/* @0x18328c bmi 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158> */
/* @0x183290 ldr r3, [sp, #0x48] */
/* @0x183294 adds r2, r2, r3 */
/* @0x183298 bmi 0x183398 <_ZN8Graphics12UpdateRegionEPviiii+0x158> */
/* @0x18329c cmp r9, r1 */
/* @0x1832a0 rsble r1, r6, r9 */
/* @0x1832a4 rsbgt r1, r6, r1 */
/* @0x1832a8 cmp r0, r2 */
/* @0x1832ac rsble r7, r8, r0 */
/* @0x1832b0 rsbgt r7, r8, r2 */
/* @0x1832b4 cmp r1, #0 */
/* @0x1832b8 cmpgt r7, #0 */
/* @0x1832bc str r1, [sp, #0x18] */
/* @0x1832c0 movgt r5, #0 */
/* @0x1832c4 movle r5, #1 */
/* @0x1832c8 ble 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c> */
/* @0x1832cc lsl r11, r1, #2 */
/* @0x1832d0 ldr r1, [pc, #0xe0] */
/* @0x1832d4 mov r2, #70 */
/* @0x1832d8 mov r3, #1 */
/* @0x1832dc add r1, pc, r1 */
/* @0x1832e0 mov r10, r5 */
/* @0x1832e4 mul r0, r7, r11 */
/* @0x1832e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1832ec ldr r2, [r4, #0x28] */
/* @0x1832f0 mla r1, r9, r8, r6 */
/* @0x1832f4 lsl r9, r9, #2 */
/* @0x1832f8 add r5, r2, r1, lsl #2 */
/* @0x1832fc mov r12, r0 */
/* @0x183300 str r0, [sp, #0x1c] */
/* @0x183304 mov r0, r12 */
/* @0x183308 mov r1, r5 */
/* @0x18330c mov r2, r11 */
/* @0x183310 add r10, r10, #1 */
/* @0x183314 bl 0xb65bc <memcpy@plt> */
/* @0x183318 cmp r7, r10 */
/* @0x18331c add r5, r5, r9 */
/* @0x183320 add r12, r0, r11 */
/* @0x183324 bgt 0x183304 <_ZN8Graphics12UpdateRegionEPviiii+0xc4> */
/* @0x183328 bl 0x182598 <_Z23_InvalidateTextureStatev> */
/* @0x18332c ldr r3, [pc, #0x88] */
/* @0x183330 ldr r1, [r4, #0x14] */
/* @0x183334 movw r0, #0xde1 */
/* @0x183338 ldr r3, [pc, r3] */
/* @0x18333c mov r5, #1 */
/* @0x183340 ldr r3, [r3] */
/* @0x183344 blx r3 */
/* @0x183348 ldr r12, [pc, #0x70] */
/* @0x18334c ldr r0, [sp, #0x18] */
/* @0x183350 mov r2, r6 */
/* @0x183354 ldr r3, [sp, #0x1c] */
/* @0x183358 ldr r12, [pc, r12] */
/* @0x18335c str r7, [sp, #0x4] */
/* @0x183360 movw r1, #0x1401 */
/* @0x183364 str r0, [sp] */
/* @0x183368 movw r0, #0x1908 */
/* @0x18336c str r3, [sp, #0x10] */
/* @0x183370 mov r3, r8 */
/* @0x183374 str r0, [sp, #0x8] */
/* @0x183378 movw r0, #0xde1 */
/* @0x18337c str r1, [sp, #0xc] */
/* @0x183380 mov r1, #0 */
/* @0x183384 ldr r12, [r12] */
/* @0x183388 blx r12 */
/* @0x18338c ldr r0, [sp, #0x1c] */
/* @0x183390 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x183394 b 0x18339c <_ZN8Graphics12UpdateRegionEPviiii+0x15c> */
/* @0x183398 mov r5, #1 */
/* @0x18339c mov r0, r5 */
/* @0x1833a0 add sp, sp, #36 */
/* @0x1833a4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1833a8 mov r5, r4 */
/* @0x1833ac mov r0, r5 */
/* @0x1833b0 add sp, sp, #36 */
/* @0x1833b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1833b8 andseq sp, r10, r4, asr sp */
/* @0x1833bc eoreq r10, r6, r8, lsr r4 */
/* @0x1833c0 eoreq r10, r6, r8, lsr #8 */

/* ── FUNC 0x1833c4 · Graphics::PreLoadTexture(void*) · size=4 · insn=1 */
/* @0x1833c4 bx lr */

/* ── FUNC 0x1833c8 · Graphics::SetTexturePriority(void*, int) · size=4 · insn=1 */
/* @0x1833c8 bx lr */

/* ── FUNC 0x1833cc · Graphics::SaveRenderTarget() · size=56 · insn=14 */
/* @0x1833cc push {r3, lr} */
/* @0x1833d0 movw r0, #0xba2 */
/* @0x1833d4 ldr r3, [pc, #0x20] */
/* @0x1833d8 ldr r1, [pc, #0x20] */
/* @0x1833dc ldr r3, [pc, r3] */
/* @0x1833e0 add r1, pc, r1 */
/* @0x1833e4 add r1, r1, #2800 */
/* @0x1833e8 ldr r3, [r3] */
/* @0x1833ec add r1, r1, #4 */
/* @0x1833f0 blx r3 */
/* @0x1833f4 pop {r3, lr} */
/* @0x1833f8 b 0x18072c <_Z21pushRenderBufferStackv> */
/* @0x1833fc .word 0x0026a3bc */
/* @0x183400 eorseq pc, r1, r12, lsl r0 */

/* ── FUNC 0x183404 · Graphics::RestoreRenderTarget() · size=396 · insn=99 */
/* @0x183404 push {r4, r5, r6, r7, r8, lr} */
/* @0x183408 sub sp, sp, #40 */
/* @0x18340c bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x183410 ldr r5, [pc, #0x148] */
/* @0x183414 bl 0x1806fc <_Z22countRenderBufferStackv> */
/* @0x183418 add r5, pc, r5 */
/* @0x18341c cmp r0, #0 */
/* @0x183420 beq 0x183524 <_ZN8Graphics19RestoreRenderTargetEv+0x120> */
/* @0x183424 ldr r3, [pc, #0x138] */
/* @0x183428 ldr r2, [pc, #0x138] */
/* @0x18342c ldr r8, [r5, r3] */
/* @0x183430 add r2, pc, r2 */
/* @0x183434 add r1, r2, #4 */
/* @0x183438 ldr r3, [r2] */
/* @0x18343c ldr r2, [r8] */
/* @0x183440 rsb r3, r3, r3, lsl #3 */
/* @0x183444 cmp r2, #1 */
/* @0x183448 add r6, r1, r3, lsl #2 */
/* @0x18344c movwgt r4, #0x8ce1 */
/* @0x183450 movgt r7, #0 */
/* @0x183454 ble 0x1834b8 <_ZN8Graphics19RestoreRenderTargetEv+0xb4> */
/* @0x183458 ldr r3, [r6, #0x8] */
/* @0x18345c add r6, r6, #4 */
/* @0x183460 ldr r12, [pc, #0x104] */
/* @0x183464 cmp r3, #0 */
/* @0x183468 beq 0x1834a0 <_ZN8Graphics19RestoreRenderTargetEv+0x9c> */
/* @0x18346c ldr r12, [r5, r12] */
/* @0x183470 mov r1, r4 */
/* @0x183474 ldr lr, [pc, #0xf4] */
/* @0x183478 movw r0, #0x8d40 */
/* @0x18347c movw r2, #0xde1 */
/* @0x183480 mov r3, #0 */
/* @0x183484 ldr r12, [r12] */
/* @0x183488 cmp r12, #1 */
/* @0x18348c beq 0x183548 <_ZN8Graphics19RestoreRenderTargetEv+0x144> */
/* @0x183490 ldr r12, [r5, lr] */
/* @0x183494 str r7, [sp] */
/* @0x183498 ldr r12, [r12] */
/* @0x18349c blx r12 */
/* @0x1834a0 sub r3, r4, #35840 */
/* @0x1834a4 ldr r2, [r8] */
/* @0x1834a8 sub r3, r3, #223 */
/* @0x1834ac add r4, r4, #1 */
/* @0x1834b0 cmp r2, r3 */
/* @0x1834b4 bgt 0x183458 <_ZN8Graphics19RestoreRenderTargetEv+0x54> */
/* @0x1834b8 add r0, sp, #12 */
/* @0x1834bc bl 0x1807ec <_Z20topRenderBufferStackv> */
/* @0x1834c0 ldr r3, [pc, #0xac] */
/* @0x1834c4 ldr r4, [sp, #0xc] */
/* @0x1834c8 movw r2, #0x87f */
/* @0x1834cc ldr r1, [pc, #0xa4] */
/* @0x1834d0 ldr r3, [r5, r3] */
/* @0x1834d4 mov r0, r4 */
/* @0x1834d8 add r1, pc, r1 */
/* @0x1834dc stm r3, {r1, r2} */
/* @0x1834e0 bl 0x1805b4 <_Z20DBG_BIND_FRAMEBUFFERi> */
/* @0x1834e4 ldr r3, [pc, #0x90] */
/* @0x1834e8 ldr r1, [pc, #0x90] */
/* @0x1834ec ldr r0, [sp, #0x20] */
/* @0x1834f0 ldr r12, [r5, r3] */
/* @0x1834f4 ldr r3, [pc, #0x88] */
/* @0x1834f8 ldr r2, [sp, #0x24] */
/* @0x1834fc str r4, [r12] */
/* @0x183500 ldr r1, [r5, r1] */
/* @0x183504 str r0, [r1] */
/* @0x183508 ldr r3, [r5, r3] */
/* @0x18350c str r2, [r3] */
/* @0x183510 bl 0x1807a8 <_Z20popRenderBufferStackv> */
/* @0x183514 bl 0x1806fc <_Z22countRenderBufferStackv> */
/* @0x183518 cmp r0, #0 */
/* @0x18351c movgt r0, #1 */
/* @0x183520 ble 0x18352c <_ZN8Graphics19RestoreRenderTargetEv+0x128> */
/* @0x183524 add sp, sp, #40 */
/* @0x183528 pop {r4, r5, r6, r7, r8, pc} */
/* @0x18352c ldr r2, [pc, #0x54] */
/* @0x183530 mov r3, #1 */
/* @0x183534 mov r0, r3 */
/* @0x183538 ldr r2, [r5, r2] */
/* @0x18353c str r3, [r2] */
/* @0x183540 add sp, sp, #40 */
/* @0x183544 pop {r4, r5, r6, r7, r8, pc} */
/* @0x183548 ldr r12, [pc, #0x3c] */
/* @0x18354c ldr r12, [r5, r12] */
/* @0x183550 str r7, [sp] */
/* @0x183554 ldr r12, [r12] */
/* @0x183558 blx r12 */
/* @0x18355c b 0x1834a0 <_ZN8Graphics19RestoreRenderTargetEv+0x9c> */
/* @0x183560 eoreq lr, r6, r8, lsr r8 */
/* @0x183564 .word 0xffffe8e0 */
/* @0x183568 eorseq lr, r1, r12, asr #31 */
/* @0x18356c .word 0xffffe7b8 */
/* @0x183570 .word 0xffffbc7c */
/* @0x183574 .word 0xffffe81c */
/* @0x183578 andseq r8, r12, r4, ror #9 */
/* @0x18357c .word 0xffffe820 */
/* @0x183580 .word 0xffffe834 */
/* @0x183584 .word 0xffffe838 */
/* @0x183588 .word 0xffffe48c */
/* @0x18358c .word 0xffffbb6c */

/* ── FUNC 0x183590 · Graphics::SetRenderTarget(int, void*) · size=328 · insn=82 */
/* @0x183590 push {r4, r5, r6, r7, lr} */
/* @0x183594 sub sp, sp, #12 */
/* @0x183598 mov r4, r0 */
/* @0x18359c mov r6, r1 */
/* @0x1835a0 ldr r5, [pc, #0x110] */
/* @0x1835a4 bl 0x1852ec <_ZN8Graphics5FlushEv> */
/* @0x1835a8 cmp r4, #0 */
/* @0x1835ac add r5, pc, r5 */
/* @0x1835b0 blt 0x1835c8 <_ZN8Graphics15SetRenderTargetEiPv+0x38> */
/* @0x1835b4 ldr r3, [pc, #0x100] */
/* @0x1835b8 ldr r3, [r5, r3] */
/* @0x1835bc ldr r3, [r3] */
/* @0x1835c0 cmp r4, r3 */
/* @0x1835c4 blt 0x1835d4 <_ZN8Graphics15SetRenderTargetEiPv+0x44> */
/* @0x1835c8 mov r0, #0 */
/* @0x1835cc add sp, sp, #12 */
/* @0x1835d0 pop {r4, r5, r6, r7, pc} */
/* @0x1835d4 mov r0, r6 */
/* @0x1835d8 mov r1, #1 */
/* @0x1835dc mvn r2, #0 */
/* @0x1835e0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable> */
/* @0x1835e4 cmp r4, #0 */
/* @0x1835e8 beq 0x183680 <_ZN8Graphics15SetRenderTargetEiPv+0xf0> */
/* @0x1835ec ldr r3, [pc, #0xcc] */
/* @0x1835f0 ldr r1, [pc, #0xcc] */
/* @0x1835f4 add r3, pc, r3 */
/* @0x1835f8 add r2, r3, #4 */
/* @0x1835fc ldr r3, [r3] */
/* @0x183600 ldr r1, [r5, r1] */
/* @0x183604 rsb r3, r3, r3, lsl #3 */
/* @0x183608 ldr r1, [r1] */
/* @0x18360c lsl r3, r3, #2 */
/* @0x183610 add r7, r2, r3 */
/* @0x183614 ldr r3, [r2, r3] */
/* @0x183618 cmp r3, r1 */
/* @0x18361c beq 0x18368c <_ZN8Graphics15SetRenderTargetEiPv+0xfc> */
/* @0x183620 cmp r3, #0 */
/* @0x183624 beq 0x18368c <_ZN8Graphics15SetRenderTargetEiPv+0xfc> */
/* @0x183628 ldr r3, [pc, #0x98] */
/* @0x18362c ldr r2, [pc, #0x98] */
/* @0x183630 ldr r3, [r5, r3] */
/* @0x183634 ldr r3, [r3] */
/* @0x183638 cmp r3, #1 */
/* @0x18363c ldrne r2, [pc, #0x8c] */
/* @0x183640 ldr r12, [r5, r2] */
/* @0x183644 add r1, r4, #35840 */
/* @0x183648 ldr r3, [r6, #0x14] */
/* @0x18364c mov lr, #0 */
/* @0x183650 movw r0, #0x8d40 */
/* @0x183654 str lr, [sp] */
/* @0x183658 add r1, r1, #224 */
/* @0x18365c movw r2, #0xde1 */
/* @0x183660 ldr r12, [r12] */
/* @0x183664 add r4, r7, r4, lsl #2 */
/* @0x183668 blx r12 */
/* @0x18366c ldr r3, [r6, #0x14] */
/* @0x183670 str r3, [r4, #0x4] */
/* @0x183674 bl 0x180904 <_Z24_UpdateActiveDrawBuffersv> */
/* @0x183678 mov r0, #1 */
/* @0x18367c b 0x1835cc <_ZN8Graphics15SetRenderTargetEiPv+0x3c> */
/* @0x183680 ldr r0, [r6, #0x18] */
/* @0x183684 cmp r0, #0 */
/* @0x183688 bne 0x183698 <_ZN8Graphics15SetRenderTargetEiPv+0x108> */
/* @0x18368c mov r0, #1 */
/* @0x183690 add sp, sp, #12 */
/* @0x183694 pop {r4, r5, r6, r7, pc} */
/* @0x183698 ldmib r6, {r1, r2} */
/* @0x18369c bl 0x180908 <_Z7bindFBOiii> */
/* @0x1836a0 ldr r3, [pc, #0x2c] */
/* @0x1836a4 mvn r2, #0 */
/* @0x1836a8 mov r0, #1 */
/* @0x1836ac ldr r3, [r5, r3] */
/* @0x1836b0 str r2, [r3] */
/* @0x1836b4 b 0x1835cc <_ZN8Graphics15SetRenderTargetEiPv+0x3c> */
/* @0x1836b8 eoreq lr, r6, r4, lsr #13 */
/* @0x1836bc .word 0xffffe8e0 */
/* @0x1836c0 eorseq lr, r1, r8, lsl #28 */
/* @0x1836c4 .word 0xffffe908 */
/* @0x1836c8 .word 0xffffe7b8 */
/* @0x1836cc .word 0xffffbb6c */
/* @0x1836d0 .word 0xffffbc7c */
/* @0x1836d4 .word 0xffffe48c */

/* ── FUNC 0x1836d8 · Graphics::SetTextureBlending(bool) · size=84 · insn=21 */
/* @0x1836d8 push {r3, lr} */
/* @0x1836dc ldr r3, [pc, #0x3c] */
/* @0x1836e0 ldr r2, [pc, #0x3c] */
/* @0x1836e4 add r3, pc, r3 */
/* @0x1836e8 ldr r2, [r3, r2] */
/* @0x1836ec ldr r2, [r2] */
/* @0x1836f0 cmp r2, #0 */
/* @0x1836f4 popne {r3, pc} */
/* @0x1836f8 ldr r12, [pc, #0x28] */
/* @0x1836fc cmp r0, #0 */
/* @0x183700 mov r1, #8704 */
/* @0x183704 mov r0, #8960 */
/* @0x183708 movne r2, #8448 */
/* @0x18370c movweq r2, #0x1e01 */
/* @0x183710 ldr r3, [r3, r12] */
/* @0x183714 ldr r3, [r3] */
/* @0x183718 blx r3 */
/* @0x18371c pop {r3, pc} */
/* @0x183720 eoreq lr, r6, r12, ror #10 */
/* @0x183724 .word 0xffffe7b8 */
/* @0x183728 .word 0xffffbca0 */

/* ── FUNC 0x18372c · Graphics::UpdateTexture(Texture*) · size=16 · insn=4 */
/* @0x18372c ldr r3, [r0, #0x10] */
/* @0x183730 bic r3, r3, #1 */
/* @0x183734 str r3, [r0, #0x10] */
/* @0x183738 bx lr */

/* ── FUNC 0x18373c · VertexBuffer::~VertexBuffer() · size=72 · insn=18 */
/* @0x18373c push {r3, r4, r5, lr} */
/* @0x183740 mov r4, r0 */
/* @0x183744 ldr r5, [r0, #0xc] */
/* @0x183748 cmp r5, #0 */
/* @0x18374c beq 0x183778 <_ZN12VertexBufferD2Ev+0x3c> */
/* @0x183750 ldr r3, [pc, #0x28] */
/* @0x183754 mov r0, #1 */
/* @0x183758 mov r1, r5 */
/* @0x18375c ldr r3, [pc, r3] */
/* @0x183760 ldr r3, [r3] */
/* @0x183764 blx r3 */
/* @0x183768 mov r0, r5 */
/* @0x18376c bl 0x27d1d0 <_ZdlPv> */
/* @0x183770 mov r3, #0 */
/* @0x183774 str r3, [r4, #0xc] */
/* @0x183778 mov r0, r4 */
/* @0x18377c pop {r3, r4, r5, pc} */
/* @0x183780 eoreq r10, r6, r8, lsr #32 */

/* ── FUNC 0x18373c · VertexBuffer::~VertexBuffer() · alias of the symbol above · insn=0 */

/* ── FUNC 0x183784 · VertexBuffer::Lock() · size=4 · insn=1 */
/* @0x183784 bx lr */

/* ── FUNC 0x183788 · VertexBuffer::Unlock() · size=4 · insn=1 */
/* @0x183788 bx lr */

/* ── FUNC 0x18378c · VertexBuffer::Init(int, int, int) · size=308 · insn=77 */
/* @0x18378c push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x183790 tst r1, #16777216 */
/* @0x183794 ldr r7, [pc, #0x108] */
/* @0x183798 mov r6, r0 */
/* @0x18379c mov r8, r2 */
/* @0x1837a0 mov r4, r1 */
/* @0x1837a4 add r7, pc, r7 */
/* @0x1837a8 str r1, [r6, #0x20] */
/* @0x1837ac mov r9, r3 */
/* @0x1837b0 moveq r2, r1 */
/* @0x1837b4 beq 0x1837cc <_ZN12VertexBuffer4InitEiii+0x40> */
/* @0x1837b8 mov r0, r1 */
/* @0x1837bc bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0x1837c0 cmp r0, #0 */
/* @0x1837c4 ldrne r2, [r0, #0x14] */
/* @0x1837c8 beq 0x183878 <_ZN12VertexBuffer4InitEiii+0xec> */
/* @0x1837cc ldr r3, [pc, #0xd4] */
/* @0x1837d0 mov r4, #0 */
/* @0x1837d4 str r2, [r6, #0x24] */
/* @0x1837d8 mov r5, #0 */
/* @0x1837dc str r8, [r6, #0x30] */
/* @0x1837e0 str r9, [r6, #0x8] */
/* @0x1837e4 strd r4, r5, [r6, #56] */
/* @0x1837e8 ldr r3, [r7, r3] */
/* @0x1837ec ldrb r0, [r3] */
/* @0x1837f0 cmp r0, #0 */
/* @0x1837f4 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1837f8 ldr r4, [r6, #0xc] */
/* @0x1837fc cmp r4, #0 */
/* @0x183800 beq 0x18382c <_ZN12VertexBuffer4InitEiii+0xa0> */
/* @0x183804 ldr r3, [pc, #0xa0] */
/* @0x183808 mov r0, #1 */
/* @0x18380c mov r1, r4 */
/* @0x183810 ldr r3, [r7, r3] */
/* @0x183814 ldr r3, [r3] */
/* @0x183818 blx r3 */
/* @0x18381c mov r0, r4 */
/* @0x183820 bl 0x27d1d0 <_ZdlPv> */
/* @0x183824 mov r3, #0 */
/* @0x183828 str r3, [r6, #0xc] */
/* @0x18382c mov r0, #8 */
/* @0x183830 bl 0x27c524 <_Znwj> */
/* @0x183834 ldr r3, [pc, #0x74] */
/* @0x183838 mvn r2, #0 */
/* @0x18383c mov r1, #0 */
/* @0x183840 stm r0, {r1, r2} */
/* @0x183844 mov r4, r0 */
/* @0x183848 ldr r3, [r7, r3] */
/* @0x18384c mov r1, r0 */
/* @0x183850 mov r0, #1 */
/* @0x183854 ldr r3, [r3] */
/* @0x183858 blx r3 */
/* @0x18385c ldr r3, [pc, #0x50] */
/* @0x183860 mov r0, #1 */
/* @0x183864 ldr r3, [r7, r3] */
/* @0x183868 ldr r3, [r3] */
/* @0x18386c str r3, [r4, #0x4] */
/* @0x183870 str r4, [r6, #0xc] */
/* @0x183874 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x183878 ldr r3, [pc, #0x38] */
/* @0x18387c mov r2, r4 */
/* @0x183880 ldr r1, [pc, #0x34] */
/* @0x183884 ldr r3, [r7, r3] */
/* @0x183888 add r1, pc, r1 */
/* @0x18388c ldr r0, [r3] */
/* @0x183890 ldr r3, [r0] */
/* @0x183894 ldr r3, [r3, #0xc] */
/* @0x183898 blx r3 */
/* @0x18389c mov r2, #1 */
/* @0x1838a0 b 0x1837cc <_ZN12VertexBuffer4InitEiii+0x40> */
/* @0x1838a4 eoreq lr, r6, r12, lsr #9 */
/* @0x1838a8 .word 0xffffe7e0 */
/* @0x1838ac .word 0xffffbb34 */
/* @0x1838b0 .word 0xffffbb38 */
/* @0x1838b4 .word 0xffffe90c */
/* @0x1838b8 .word 0xffffbac4 */
/* @0x1838bc ldrsheq r8, [r12], -r4 */

/* ── FUNC 0x1838c0 · VertexBuffer::UpdateFromBuffer(void*, int) · size=152 · insn=38 */
/* @0x1838c0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1838c4 mov r5, r0 */
/* @0x1838c8 ldr r3, [pc, #0x7c] */
/* @0x1838cc mov r6, r1 */
/* @0x1838d0 mov r7, r2 */
/* @0x1838d4 ldr r3, [pc, r3] */
/* @0x1838d8 ldrb r3, [r3] */
/* @0x1838dc cmp r3, #0 */
/* @0x1838e0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1838e4 ldr r3, [r0, #0xc] */
/* @0x1838e8 cmp r3, #0 */
/* @0x1838ec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1838f0 ldr r4, [pc, #0x58] */
/* @0x1838f4 movw r0, #0x8892 */
/* @0x1838f8 ldr r1, [r3] */
/* @0x1838fc ldr r4, [pc, r4] */
/* @0x183900 ldr r3, [r4] */
/* @0x183904 blx r3 */
/* @0x183908 ldr r3, [r5, #0x8] */
/* @0x18390c ldr r0, [pc, #0x40] */
/* @0x183910 movw r12, #0x88e4 */
/* @0x183914 tst r3, #2 */
/* @0x183918 movw r3, #0x88e0 */
/* @0x18391c ldr r0, [pc, r0] */
/* @0x183920 mov r1, r7 */
/* @0x183924 moveq r3, r12 */
/* @0x183928 mov r2, r6 */
/* @0x18392c ldr r12, [r0] */
/* @0x183930 movw r0, #0x8892 */
/* @0x183934 blx r12 */
/* @0x183938 ldr r3, [r4] */
/* @0x18393c movw r0, #0x8892 */
/* @0x183940 mov r1, #0 */
/* @0x183944 blx r3 */
/* @0x183948 pop {r3, r4, r5, r6, r7, pc} */
/* @0x18394c eoreq r12, r6, r12, asr r11 */
/* @0x183950 mlaeq r6, r0, lr, r9 */
/* @0x183954 eoreq r9, r6, r4, ror lr */

/* ── FUNC 0x183958 · VertexBuffer::IsValid() · size=80 · insn=20 */
/* @0x183958 ldr r3, [pc, #0x40] */
/* @0x18395c ldr r3, [pc, r3] */
/* @0x183960 ldrb r3, [r3] */
/* @0x183964 cmp r3, #0 */
/* @0x183968 beq 0x183998 <_ZN12VertexBuffer7IsValidEv+0x40> */
/* @0x18396c ldr r0, [r0, #0xc] */
/* @0x183970 cmp r0, #0 */
/* @0x183974 bxeq lr */
/* @0x183978 ldr r2, [pc, #0x24] */
/* @0x18397c ldr r0, [r0, #0x4] */
/* @0x183980 ldr r2, [pc, r2] */
/* @0x183984 ldr r3, [r2] */
/* @0x183988 subs r3, r0, r3 */
/* @0x18398c rsbs r0, r3, #0 */
/* @0x183990 adcs r0, r0, r3 */
/* @0x183994 bx lr */
/* @0x183998 mov r0, r3 */
/* @0x18399c bx lr */
/* @0x1839a0 .word 0x0026cad4 */
/* @0x1839a4 .word 0x0026cbdc */

/* ── FUNC 0x1839a8 · Graphics::GetFVF(int) · size=8 · insn=2 */
/* @0x1839a8 mov r0, #0 */
/* @0x1839ac bx lr */

/* ── FUNC 0x1839b0 · GenerateShaderVariation(int, char*, char*, char*, bool) · size=448 · insn=112 */
/* @0x1839b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1839b4 mov r7, r3 */
/* @0x1839b8 ldr r5, [pc, #0x198] */
/* @0x1839bc sub sp, sp, #84 */
/* @0x1839c0 mov r6, r0 */
/* @0x1839c4 mov r0, r1 */
/* @0x1839c8 ldr r5, [pc, r5] */
/* @0x1839cc mov r10, r1 */
/* @0x1839d0 mov r8, r2 */
/* @0x1839d4 ldrb r9, [sp, #0x78] */
/* @0x1839d8 ldr r3, [r5] */
/* @0x1839dc ubfx r11, r6, #0x1, #0x1 */
/* @0x1839e0 str r3, [sp, #0x4c] */
/* @0x1839e4 bl 0xb6538 <strlen@plt> */
/* @0x1839e8 ands r3, r6, #1 */
/* @0x1839ec str r3, [sp, #0x4] */
/* @0x1839f0 moveq r4, r0 */
/* @0x1839f4 addne r4, r0, #16 */
/* @0x1839f8 cmp r11, #0 */
/* @0x1839fc mov r0, r8 */
/* @0x183a00 addne r4, r4, #22 */
/* @0x183a04 cmp r9, #0 */
/* @0x183a08 addne r4, r4, #24 */
/* @0x183a0c bl 0xb6538 <strlen@plt> */
/* @0x183a10 mov r12, r0 */
/* @0x183a14 mov r0, r7 */
/* @0x183a18 str r12, [sp] */
/* @0x183a1c bl 0xb6538 <strlen@plt> */
/* @0x183a20 ldr r12, [sp] */
/* @0x183a24 mov r3, #1 */
/* @0x183a28 ldr r1, [pc, #0x12c] */
/* @0x183a2c mov r2, #70 */
/* @0x183a30 add r1, pc, r1 */
/* @0x183a34 add r0, r0, r12 */
/* @0x183a38 add r0, r0, r4 */
/* @0x183a3c add r0, r0, r3 */
/* @0x183a40 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x183a44 mov r1, r10 */
/* @0x183a48 mov r4, r0 */
/* @0x183a4c bl 0xb65a4 <strcpy@plt> */
/* @0x183a50 ldr r3, [sp, #0x4] */
/* @0x183a54 cmp r3, #0 */
/* @0x183a58 bne 0x183b1c <_Z23GenerateShaderVariationiPcS_S_b+0x16c> */
/* @0x183a5c cmp r11, #0 */
/* @0x183a60 bne 0x183ad4 <_Z23GenerateShaderVariationiPcS_S_b+0x124> */
/* @0x183a64 cmp r9, #0 */
/* @0x183a68 beq 0x183aa0 <_Z23GenerateShaderVariationiPcS_S_b+0xf0> */
/* @0x183a6c ubfx r6, r6, #0x2, #0x2 */
/* @0x183a70 mov r3, #1 */
/* @0x183a74 lsl r3, r3, r6 */
/* @0x183a78 ldr r1, [pc, #0xe0] */
/* @0x183a7c add r6, sp, #12 */
/* @0x183a80 ldr r2, [pc, #0xdc] */
/* @0x183a84 add r1, pc, r1 */
/* @0x183a88 mov r0, r6 */
/* @0x183a8c add r2, pc, r2 */
/* @0x183a90 bl 0xb6550 <sprintf@plt> */
/* @0x183a94 mov r0, r4 */
/* @0x183a98 mov r1, r6 */
/* @0x183a9c bl 0xb6628 <strcat@plt> */
/* @0x183aa0 mov r1, r8 */
/* @0x183aa4 mov r0, r4 */
/* @0x183aa8 bl 0xb6628 <strcat@plt> */
/* @0x183aac mov r0, r4 */
/* @0x183ab0 mov r1, r7 */
/* @0x183ab4 bl 0xb6628 <strcat@plt> */
/* @0x183ab8 ldr r2, [sp, #0x4c] */
/* @0x183abc ldr r3, [r5] */
/* @0x183ac0 mov r0, r4 */
/* @0x183ac4 cmp r2, r3 */
/* @0x183ac8 bne 0x183b54 <_Z23GenerateShaderVariationiPcS_S_b+0x1a4> */
/* @0x183acc add sp, sp, #84 */
/* @0x183ad0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x183ad4 mov r0, r4 */
/* @0x183ad8 bl 0xb6538 <strlen@plt> */
/* @0x183adc ldr r12, [pc, #0x84] */
/* @0x183ae0 add r12, pc, r12 */
/* @0x183ae4 add lr, r4, r0 */
/* @0x183ae8 mov r10, r0 */
/* @0x183aec ldm r12!, {r0, r1, r2, r3} */
/* @0x183af0 str r0, [r4, r10] */
/* @0x183af4 ldrh r10, [r12, #4] */
/* @0x183af8 ldr r0, [r12] */
/* @0x183afc ldrb r12, [r12, #0x6] */
/* @0x183b00 str r1, [lr, #0x4] */
/* @0x183b04 str r2, [lr, #0x8] */
/* @0x183b08 str r3, [lr, #0xc] */
/* @0x183b0c str r0, [lr, #0x10] */
/* @0x183b10 strh r10, [lr, #20] */
/* @0x183b14 strb r12, [lr, #0x16] */
/* @0x183b18 b 0x183a64 <_Z23GenerateShaderVariationiPcS_S_b+0xb4> */
/* @0x183b1c mov r0, r4 */
/* @0x183b20 bl 0xb6538 <strlen@plt> */
/* @0x183b24 ldr r12, [pc, #0x40] */
/* @0x183b28 add r12, pc, r12 */
/* @0x183b2c add lr, r4, r0 */
/* @0x183b30 mov r10, r0 */
/* @0x183b34 ldm r12!, {r0, r1, r2, r3} */
/* @0x183b38 ldrb r12, [r12] */
/* @0x183b3c str r0, [r4, r10] */
/* @0x183b40 str r1, [lr, #0x4] */
/* @0x183b44 strb r12, [lr, #0x10] */
/* @0x183b48 str r2, [lr, #0x8] */
/* @0x183b4c str r3, [lr, #0xc] */
/* @0x183b50 b 0x183a5c <_Z23GenerateShaderVariationiPcS_S_b+0xac> */
/* @0x183b54 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x183b58 eoreq r9, r6, r8, lsl #31 */
/* @0x183b5c andseq sp, r10, r0, lsl #12 */
/* @0x183b60 andseq r8, r12, r4, asr #2 */
/* @0x183b64 andseq r8, r12, r4, asr #2 */
/* @0x183b68 ldrsbeq r8, [r12], -r0 */
/* @0x183b6c andseq r8, r12, r4, ror r0 */

/* ── FUNC 0x183b70 · InitShaderVariations(int*, char*, char*, bool) · size=272 · insn=68 */
/* @0x183b70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x183b74 mov r9, r1 */
/* @0x183b78 ldr r1, [r0] */
/* @0x183b7c mov r6, r3 */
/* @0x183b80 ldr r3, [pc, #0xe4] */
/* @0x183b84 sub sp, sp, #36 */
/* @0x183b88 cmn r1, #1 */
/* @0x183b8c mov r10, r2 */
/* @0x183b90 add r3, pc, r3 */
/* @0x183b94 beq 0x183ba0 <_Z20InitShaderVariationsPiPcS0_b+0x30> */
/* @0x183b98 add sp, sp, #36 */
/* @0x183b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x183ba0 ldr r12, [pc, #0xc8] */
/* @0x183ba4 mov r4, #0 */
/* @0x183ba8 cmp r6, r4 */
/* @0x183bac sub r8, r0, #4 */
/* @0x183bb0 ldr r0, [pc, #0xbc] */
/* @0x183bb4 mov r7, r4 */
/* @0x183bb8 moveq r2, #4 */
/* @0x183bbc movne r2, #16 */
/* @0x183bc0 str r2, [sp, #0xc] */
/* @0x183bc4 ldr r12, [r3, r12] */
/* @0x183bc8 ldr r1, [pc, #0xa8] */
/* @0x183bcc ldr r2, [pc, #0xa8] */
/* @0x183bd0 str r12, [sp, #0x10] */
/* @0x183bd4 ldr r0, [r3, r0] */
/* @0x183bd8 str r0, [sp, #0x18] */
/* @0x183bdc ldr r1, [r3, r1] */
/* @0x183be0 str r1, [sp, #0x14] */
/* @0x183be4 ldr r2, [r3, r2] */
/* @0x183be8 str r2, [sp, #0x1c] */
/* @0x183bec mov r0, r4 */
/* @0x183bf0 ldr r1, [sp, #0x10] */
/* @0x183bf4 ldr r2, [sp, #0x18] */
/* @0x183bf8 mov r3, r9 */
/* @0x183bfc str r6, [sp] */
/* @0x183c00 bl 0x1839b0 <_Z23GenerateShaderVariationiPcS_S_b> */
/* @0x183c04 ldr r1, [sp, #0x14] */
/* @0x183c08 ldr r2, [sp, #0x1c] */
/* @0x183c0c mov r3, r10 */
/* @0x183c10 str r6, [sp] */
/* @0x183c14 mov r5, r0 */
/* @0x183c18 mov r0, r4 */
/* @0x183c1c bl 0x1839b0 <_Z23GenerateShaderVariationiPcS_S_b> */
/* @0x183c20 mov r2, #0 */
/* @0x183c24 mov r3, r2 */
/* @0x183c28 str r7, [sp] */
/* @0x183c2c str r7, [sp, #0x4] */
/* @0x183c30 add r4, r4, #1 */
/* @0x183c34 mov r11, r0 */
/* @0x183c38 mov r0, r5 */
/* @0x183c3c mov r1, r11 */
/* @0x183c40 bl 0x187b7c <_Z10Shader_AddPcS_PS_PbiS0_> */
/* @0x183c44 str r0, [r8, #0x4]! */
/* @0x183c48 mov r0, r5 */
/* @0x183c4c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x183c50 mov r0, r11 */
/* @0x183c54 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x183c58 ldr r3, [sp, #0xc] */
/* @0x183c5c cmp r4, r3 */
/* @0x183c60 blt 0x183bec <_Z20InitShaderVariationsPiPcS0_b+0x7c> */
/* @0x183c64 add sp, sp, #36 */
/* @0x183c68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x183c6c eoreq lr, r6, r0, asr #1 */
/* @0x183c70 .word 0xffffe910 */
/* @0x183c74 .word 0xffffe914 */
/* @0x183c78 .word 0xffffe918 */
/* @0x183c7c .word 0xffffe91c */

/* ── FUNC 0x183c80 · InitVertexBuilderResources() · size=176 · insn=44 */
/* @0x183c80 push {r4, r5, r6, lr} */
/* @0x183c84 mov r3, #0 */
/* @0x183c88 ldr r4, [pc, #0x78] */
/* @0x183c8c ldr r5, [pc, #0x78] */
/* @0x183c90 ldr r1, [pc, #0x78] */
/* @0x183c94 add r4, pc, r4 */
/* @0x183c98 ldr r2, [pc, #0x74] */
/* @0x183c9c add r5, pc, r5 */
/* @0x183ca0 ldr r1, [r4, r1] */
/* @0x183ca4 mov r0, r5 */
/* @0x183ca8 ldr r2, [r4, r2] */
/* @0x183cac bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b> */
/* @0x183cb0 ldr r1, [pc, #0x60] */
/* @0x183cb4 ldr r2, [pc, #0x60] */
/* @0x183cb8 add r0, r5, #16 */
/* @0x183cbc mov r3, #0 */
/* @0x183cc0 ldr r1, [r4, r1] */
/* @0x183cc4 ldr r2, [r4, r2] */
/* @0x183cc8 bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b> */
/* @0x183ccc ldr r1, [pc, #0x4c] */
/* @0x183cd0 ldr r2, [pc, #0x4c] */
/* @0x183cd4 add r0, r5, #32 */
/* @0x183cd8 mov r3, #1 */
/* @0x183cdc ldr r1, [r4, r1] */
/* @0x183ce0 ldr r2, [r4, r2] */
/* @0x183ce4 bl 0x183b70 <_Z20InitShaderVariationsPiPcS0_b> */
/* @0x183ce8 ldr r1, [pc, #0x38] */
/* @0x183cec ldr r2, [pc, #0x38] */
/* @0x183cf0 add r0, r5, #96 */
/* @0x183cf4 mov r3, #0 */
/* @0x183cf8 ldr r1, [r4, r1] */
/* @0x183cfc ldr r2, [r4, r2] */
/* @0x183d00 pop {r4, r5, r6, lr} */
/* @0x183d04 b 0x183b70 <_Z20InitShaderVariationsPiPcS0_b> */
/* @0x183d08 .word 0x0026dfbc */
/* @0x183d0c eoreq lr, r6, r12, lsl #24 */
/* @0x183d10 .word 0xffffe920 */
/* @0x183d14 .word 0xffffe924 */
/* @0x183d18 .word 0xffffe928 */
/* @0x183d1c .word 0xffffe92c */
/* @0x183d20 .word 0xffffe930 */
/* @0x183d24 .word 0xffffe934 */
/* @0x183d28 .word 0xffffe938 */
/* @0x183d2c .word 0xffffe93c */

/* ── FUNC 0x183d30 · FreeVertexBuilderResources() · size=4 · insn=1 */
/* @0x183d30 b 0xc8fe8 <_Z19InvalidateFrozenVBsv> */

/* ── FUNC 0x183d34 · DeleteVertexBuilderResources() · size=84 · insn=21 */
/* @0x183d34 push {r4, lr} */
/* @0x183d38 mvn r1, #0 */
/* @0x183d3c ldr r4, [pc, #0x40] */
/* @0x183d40 mov r2, #16 */
/* @0x183d44 add r4, pc, r4 */
/* @0x183d48 mov r0, r4 */
/* @0x183d4c bl 0xb65b0 <memset@plt> */
/* @0x183d50 add r0, r4, #16 */
/* @0x183d54 mvn r1, #0 */
/* @0x183d58 mov r2, #16 */
/* @0x183d5c bl 0xb65b0 <memset@plt> */
/* @0x183d60 add r0, r4, #32 */
/* @0x183d64 mvn r1, #0 */
/* @0x183d68 mov r2, #64 */
/* @0x183d6c bl 0xb65b0 <memset@plt> */
/* @0x183d70 add r0, r4, #96 */
/* @0x183d74 mvn r1, #0 */
/* @0x183d78 mov r2, #16 */
/* @0x183d7c pop {r4, lr} */
/* @0x183d80 b 0xb65b0 <memset@plt> */
/* @0x183d84 eoreq lr, r6, r4, ror #22 */
