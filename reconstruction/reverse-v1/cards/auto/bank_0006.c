/* libyoyo.so 覆盖卡组 0006
 * 函数 0xc5888..0xc7294，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc5888 · F_BUFFER_Resize(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0xc5888 push {r3, r4, r5, lr} */
/* @0xc588c mov r1, #0 */
/* @0xc5890 ldr r4, [sp, #0x10] */
/* @0xc5894 mov r0, r4 */
/* @0xc5898 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc589c cmp r0, #0 */
/* @0xc58a0 blt 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xc58a4 ldr r2, [pc, #0x54] */
/* @0xc58a8 add r2, pc, r2 */
/* @0xc58ac ldr r1, [r2] */
/* @0xc58b0 cmp r0, r1 */
/* @0xc58b4 bge 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xc58b8 ldr r2, [r2, #0x4] */
/* @0xc58bc ldr r5, [r2, r0, lsl #2] */
/* @0xc58c0 cmp r5, #0 */
/* @0xc58c4 beq 0xc58ec <_Z15F_BUFFER_ResizeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xc58c8 ldr r3, [r5] */
/* @0xc58cc mov r0, r4 */
/* @0xc58d0 mov r1, #1 */
/* @0xc58d4 ldr r4, [r3, #0x34] */
/* @0xc58d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc58dc mov r1, r0 */
/* @0xc58e0 mov r0, r5 */
/* @0xc58e4 blx r4 */
/* @0xc58e8 pop {r3, r4, r5, pc} */
/* @0xc58ec ldr r0, [pc, #0x10] */
/* @0xc58f0 mov r1, #0 */
/* @0xc58f4 pop {r3, r4, r5, lr} */
/* @0xc58f8 add r0, pc, r0 */
/* @0xc58fc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5900 eorseq r4, r11, r12, ror #16 */
/* @0xc5904 .word 0x0026b2bc */

/* ── FUNC 0xc5908 · F_BUFFER_MD5(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0xc5908 push {r4, r5, r6, r7, r8, lr} */
/* @0xc590c mov r1, #0 */
/* @0xc5910 ldr r4, [sp, #0x18] */
/* @0xc5914 mov r6, r0 */
/* @0xc5918 mov r0, r4 */
/* @0xc591c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5920 cmp r0, #0 */
/* @0xc5924 blt 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc5928 ldr r2, [pc, #0x6c] */
/* @0xc592c add r2, pc, r2 */
/* @0xc5930 ldr r12, [r2] */
/* @0xc5934 cmp r0, r12 */
/* @0xc5938 bge 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc593c ldr r2, [r2, #0x4] */
/* @0xc5940 ldr r5, [r2, r0, lsl #2] */
/* @0xc5944 cmp r5, #0 */
/* @0xc5948 beq 0xc5988 <_Z12F_BUFFER_MD5R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc594c ldr r3, [r5] */
/* @0xc5950 mov r0, r4 */
/* @0xc5954 mov r1, #1 */
/* @0xc5958 ldr r7, [r3, #0x2c] */
/* @0xc595c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5960 mov r1, #2 */
/* @0xc5964 mov r8, r0 */
/* @0xc5968 mov r0, r4 */
/* @0xc596c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5970 mov r1, r6 */
/* @0xc5974 mov r2, r8 */
/* @0xc5978 mov r3, r0 */
/* @0xc597c mov r0, r5 */
/* @0xc5980 blx r7 */
/* @0xc5984 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5988 ldr r0, [pc, #0x10] */
/* @0xc598c mov r1, #0 */
/* @0xc5990 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5994 add r0, pc, r0 */
/* @0xc5998 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc599c eorseq r4, r11, r8, ror #15 */
/* @0xc59a0 eoreq r11, r6, r0, lsr #4 */

/* ── FUNC 0xc59a4 · F_BUFFER_SHA1(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0xc59a4 push {r4, r5, r6, r7, r8, lr} */
/* @0xc59a8 mov r1, #0 */
/* @0xc59ac ldr r4, [sp, #0x18] */
/* @0xc59b0 mov r6, r0 */
/* @0xc59b4 mov r0, r4 */
/* @0xc59b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc59bc cmp r0, #0 */
/* @0xc59c0 blt 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc59c4 ldr r2, [pc, #0x6c] */
/* @0xc59c8 add r2, pc, r2 */
/* @0xc59cc ldr r12, [r2] */
/* @0xc59d0 cmp r0, r12 */
/* @0xc59d4 bge 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc59d8 ldr r2, [r2, #0x4] */
/* @0xc59dc ldr r5, [r2, r0, lsl #2] */
/* @0xc59e0 cmp r5, #0 */
/* @0xc59e4 beq 0xc5a24 <_Z13F_BUFFER_SHA1R6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc59e8 ldr r3, [r5] */
/* @0xc59ec mov r0, r4 */
/* @0xc59f0 mov r1, #1 */
/* @0xc59f4 ldr r7, [r3, #0x30] */
/* @0xc59f8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc59fc mov r1, #2 */
/* @0xc5a00 mov r8, r0 */
/* @0xc5a04 mov r0, r4 */
/* @0xc5a08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5a0c mov r1, r6 */
/* @0xc5a10 mov r2, r8 */
/* @0xc5a14 mov r3, r0 */
/* @0xc5a18 mov r0, r5 */
/* @0xc5a1c blx r7 */
/* @0xc5a20 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5a24 ldr r0, [pc, #0x10] */
/* @0xc5a28 mov r1, #0 */
/* @0xc5a2c pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5a30 add r0, pc, r0 */
/* @0xc5a34 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5a38 eorseq r4, r11, r12, asr #14 */
/* @0xc5a3c eoreq r11, r6, r4, lsl #3 */

/* ── FUNC 0xc5a40 · F_BUFFER_Base64_Encode(RValue&, CInstance*, CInstance*, int, RValue*) · size=156 · insn=39 */
/* @0xc5a40 push {r4, r5, r6, r7, r8, lr} */
/* @0xc5a44 mov r1, #0 */
/* @0xc5a48 ldr r4, [sp, #0x18] */
/* @0xc5a4c mov r6, r0 */
/* @0xc5a50 mov r0, r4 */
/* @0xc5a54 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5a58 cmp r0, #0 */
/* @0xc5a5c blt 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc5a60 ldr r2, [pc, #0x6c] */
/* @0xc5a64 add r2, pc, r2 */
/* @0xc5a68 ldr r12, [r2] */
/* @0xc5a6c cmp r0, r12 */
/* @0xc5a70 bge 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc5a74 ldr r2, [r2, #0x4] */
/* @0xc5a78 ldr r5, [r2, r0, lsl #2] */
/* @0xc5a7c cmp r5, #0 */
/* @0xc5a80 beq 0xc5ac0 <_Z22F_BUFFER_Base64_EncodeR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xc5a84 ldr r3, [r5] */
/* @0xc5a88 mov r0, r4 */
/* @0xc5a8c mov r1, #1 */
/* @0xc5a90 ldr r7, [r3, #0x24] */
/* @0xc5a94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5a98 mov r1, #2 */
/* @0xc5a9c mov r8, r0 */
/* @0xc5aa0 mov r0, r4 */
/* @0xc5aa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5aa8 mov r1, r6 */
/* @0xc5aac mov r2, r8 */
/* @0xc5ab0 mov r3, r0 */
/* @0xc5ab4 mov r0, r5 */
/* @0xc5ab8 blx r7 */
/* @0xc5abc pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5ac0 ldr r0, [pc, #0x10] */
/* @0xc5ac4 mov r1, #0 */
/* @0xc5ac8 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5acc add r0, pc, r0 */
/* @0xc5ad0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5ad4 ldrhteq r4, [r11], -r0 */
/* @0xc5ad8 eoreq r11, r6, r8, ror #1 */

/* ── FUNC 0xc5adc · F_BUFFER_Save(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0xc5adc push {r4, r5, r6, lr} */
/* @0xc5ae0 mov r4, #0 */
/* @0xc5ae4 ldr r5, [sp, #0x10] */
/* @0xc5ae8 mov r1, r4 */
/* @0xc5aec str r4, [r0, #0xc] */
/* @0xc5af0 str r4, [r0] */
/* @0xc5af4 str r4, [r0, #0x4] */
/* @0xc5af8 mov r0, r5 */
/* @0xc5afc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5b00 cmp r0, #0 */
/* @0xc5b04 blt 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5b08 ldr r2, [pc, #0x5c] */
/* @0xc5b0c add r2, pc, r2 */
/* @0xc5b10 ldr r1, [r2] */
/* @0xc5b14 cmp r0, r1 */
/* @0xc5b18 bge 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5b1c ldr r2, [r2, #0x4] */
/* @0xc5b20 ldr r6, [r2, r0, lsl #2] */
/* @0xc5b24 cmp r6, r4 */
/* @0xc5b28 beq 0xc5b58 <_Z13F_BUFFER_SaveR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5b2c ldr r3, [r6] */
/* @0xc5b30 mov r0, r5 */
/* @0xc5b34 mov r1, #1 */
/* @0xc5b38 ldr r5, [r3, #0x1c] */
/* @0xc5b3c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5b40 mov r2, r4 */
/* @0xc5b44 mvn r3, #0 */
/* @0xc5b48 mov r1, r0 */
/* @0xc5b4c mov r0, r6 */
/* @0xc5b50 blx r5 */
/* @0xc5b54 pop {r4, r5, r6, pc} */
/* @0xc5b58 ldr r0, [pc, #0x10] */
/* @0xc5b5c mov r1, #0 */
/* @0xc5b60 pop {r4, r5, r6, lr} */
/* @0xc5b64 add r0, pc, r0 */
/* @0xc5b68 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5b6c eorseq r4, r11, r8, lsl #12 */
/* @0xc5b70 eoreq r11, r6, r0, asr r0 */

/* ── FUNC 0xc5b74 · F_BUFFER_Save_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0xc5b74 push {r4, r5, r6, r7, r8, lr} */
/* @0xc5b78 mov r1, #0 */
/* @0xc5b7c ldr r4, [sp, #0x18] */
/* @0xc5b80 mov r0, r4 */
/* @0xc5b84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5b88 cmp r0, #0 */
/* @0xc5b8c blt 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xc5b90 ldr r3, [pc, #0x7c] */
/* @0xc5b94 add r3, pc, r3 */
/* @0xc5b98 ldr r2, [r3] */
/* @0xc5b9c cmp r0, r2 */
/* @0xc5ba0 bge 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xc5ba4 ldr r3, [r3, #0x4] */
/* @0xc5ba8 ldr r5, [r3, r0, lsl #2] */
/* @0xc5bac cmp r5, #0 */
/* @0xc5bb0 beq 0xc5c00 <_Z17F_BUFFER_Save_ExtR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xc5bb4 ldr r3, [r5] */
/* @0xc5bb8 mov r0, r4 */
/* @0xc5bbc mov r1, #1 */
/* @0xc5bc0 ldr r6, [r3, #0x1c] */
/* @0xc5bc4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5bc8 mov r1, #2 */
/* @0xc5bcc mov r8, r0 */
/* @0xc5bd0 mov r0, r4 */
/* @0xc5bd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5bd8 mov r1, #3 */
/* @0xc5bdc mov r7, r0 */
/* @0xc5be0 mov r0, r4 */
/* @0xc5be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5be8 mov r1, r8 */
/* @0xc5bec mov r2, r7 */
/* @0xc5bf0 mov r3, r0 */
/* @0xc5bf4 mov r0, r5 */
/* @0xc5bf8 blx r6 */
/* @0xc5bfc pop {r4, r5, r6, r7, r8, pc} */
/* @0xc5c00 ldr r0, [pc, #0x10] */
/* @0xc5c04 mov r1, #0 */
/* @0xc5c08 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc5c0c add r0, pc, r0 */
/* @0xc5c10 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5c14 eorseq r4, r11, r0, lsl #11 */
/* @0xc5c18 eoreq r10, r6, r8, lsr #31 */

/* ── FUNC 0xc5c1c · F_BUFFER_Load_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=168 · insn=42 */
/* @0xc5c1c push {r4, r5, r6, r7, lr} */
/* @0xc5c20 sub sp, sp, #12 */
/* @0xc5c24 mov r1, #0 */
/* @0xc5c28 ldr r4, [sp, #0x20] */
/* @0xc5c2c mov r0, r4 */
/* @0xc5c30 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5c34 cmp r0, #0 */
/* @0xc5c38 blt 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xc5c3c ldr r3, [pc, #0x78] */
/* @0xc5c40 add r3, pc, r3 */
/* @0xc5c44 ldr r2, [r3] */
/* @0xc5c48 cmp r0, r2 */
/* @0xc5c4c bge 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xc5c50 ldr r3, [r3, #0x4] */
/* @0xc5c54 ldr r5, [r3, r0, lsl #2] */
/* @0xc5c58 cmp r5, #0 */
/* @0xc5c5c beq 0xc5ca4 <_Z17F_BUFFER_Load_ExtR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0xc5c60 ldr r3, [r5] */
/* @0xc5c64 mov r0, r4 */
/* @0xc5c68 mov r1, #1 */
/* @0xc5c6c ldr r6, [r3, #0x20] */
/* @0xc5c70 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5c74 mov r1, #2 */
/* @0xc5c78 mov r7, r0 */
/* @0xc5c7c mov r0, r4 */
/* @0xc5c80 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5c84 mov r1, r7 */
/* @0xc5c88 mov r2, #0 */
/* @0xc5c8c mvn r3, #0 */
/* @0xc5c90 str r0, [sp] */
/* @0xc5c94 mov r0, r5 */
/* @0xc5c98 blx r6 */
/* @0xc5c9c add sp, sp, #12 */
/* @0xc5ca0 pop {r4, r5, r6, r7, pc} */
/* @0xc5ca4 ldr r0, [pc, #0x14] */
/* @0xc5ca8 mov r1, #0 */
/* @0xc5cac add r0, pc, r0 */
/* @0xc5cb0 add sp, sp, #12 */
/* @0xc5cb4 pop {r4, r5, r6, r7, lr} */
/* @0xc5cb8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5cbc ldrsbteq r4, [r11], -r4 */
/* @0xc5cc0 eoreq r10, r6, r8, lsl #30 */

/* ── FUNC 0xc5cc4 · F_BUFFER_Load_Partial(RValue&, CInstance*, CInstance*, int, RValue*) · size=200 · insn=50 */
/* @0xc5cc4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc5cc8 sub sp, sp, #12 */
/* @0xc5ccc mov r1, #0 */
/* @0xc5cd0 ldr r4, [sp, #0x28] */
/* @0xc5cd4 mov r0, r4 */
/* @0xc5cd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5cdc cmp r0, #0 */
/* @0xc5ce0 blt 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc5ce4 ldr r3, [pc, #0x98] */
/* @0xc5ce8 add r3, pc, r3 */
/* @0xc5cec ldr r2, [r3] */
/* @0xc5cf0 cmp r0, r2 */
/* @0xc5cf4 bge 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc5cf8 ldr r3, [r3, #0x4] */
/* @0xc5cfc ldr r5, [r3, r0, lsl #2] */
/* @0xc5d00 cmp r5, #0 */
/* @0xc5d04 beq 0xc5d6c <_Z21F_BUFFER_Load_PartialR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0xc5d08 ldr r3, [r5] */
/* @0xc5d0c mov r0, r4 */
/* @0xc5d10 mov r1, #1 */
/* @0xc5d14 ldr r6, [r3, #0x20] */
/* @0xc5d18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5d1c mov r1, #2 */
/* @0xc5d20 mov r9, r0 */
/* @0xc5d24 mov r0, r4 */
/* @0xc5d28 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5d2c mov r1, #3 */
/* @0xc5d30 mov r8, r0 */
/* @0xc5d34 mov r0, r4 */
/* @0xc5d38 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5d3c mov r1, #4 */
/* @0xc5d40 mov r7, r0 */
/* @0xc5d44 mov r0, r4 */
/* @0xc5d48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5d4c mov r1, r9 */
/* @0xc5d50 mov r2, r8 */
/* @0xc5d54 mov r3, r7 */
/* @0xc5d58 str r0, [sp] */
/* @0xc5d5c mov r0, r5 */
/* @0xc5d60 blx r6 */
/* @0xc5d64 add sp, sp, #12 */
/* @0xc5d68 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc5d6c ldr r0, [pc, #0x14] */
/* @0xc5d70 mov r1, #0 */
/* @0xc5d74 add r0, pc, r0 */
/* @0xc5d78 add sp, sp, #12 */
/* @0xc5d7c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc5d80 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5d84 eorseq r4, r11, r12, lsr #8 */
/* @0xc5d88 eoreq r10, r6, r0, asr #28 */

/* ── FUNC 0xc5d8c · F_BUFFER_Base64_Decode_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=152 · insn=38 */
/* @0xc5d8c push {r3, r4, r5, r6, r7, lr} */
/* @0xc5d90 mov r1, #0 */
/* @0xc5d94 ldr r4, [sp, #0x18] */
/* @0xc5d98 mov r0, r4 */
/* @0xc5d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5da0 cmp r0, #0 */
/* @0xc5da4 blt 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5da8 ldr r3, [pc, #0x6c] */
/* @0xc5dac add r3, pc, r3 */
/* @0xc5db0 ldr r2, [r3] */
/* @0xc5db4 cmp r0, r2 */
/* @0xc5db8 bge 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5dbc ldr r3, [r3, #0x4] */
/* @0xc5dc0 ldr r5, [r3, r0, lsl #2] */
/* @0xc5dc4 cmp r5, #0 */
/* @0xc5dc8 beq 0xc5e08 <_Z26F_BUFFER_Base64_Decode_ExtR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xc5dcc ldr r3, [r5] */
/* @0xc5dd0 mov r0, r4 */
/* @0xc5dd4 mov r1, #1 */
/* @0xc5dd8 ldr r6, [r3, #0x28] */
/* @0xc5ddc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5de0 mov r1, #2 */
/* @0xc5de4 mov r7, r0 */
/* @0xc5de8 mov r0, r4 */
/* @0xc5dec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc5df0 mov r1, r7 */
/* @0xc5df4 mvn r3, #0 */
/* @0xc5df8 mov r2, r0 */
/* @0xc5dfc mov r0, r5 */
/* @0xc5e00 blx r6 */
/* @0xc5e04 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc5e08 ldr r0, [pc, #0x10] */
/* @0xc5e0c mov r1, #0 */
/* @0xc5e10 pop {r3, r4, r5, r6, r7, lr} */
/* @0xc5e14 add r0, pc, r0 */
/* @0xc5e18 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc5e1c eorseq r4, r11, r8, ror #6 */
/* @0xc5e20 eoreq r10, r6, r0, lsr #27 */

/* ── FUNC 0xc5e24 · F_BUFFER_Async_Group_Begin(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xc5e24 push {r3, r4, r5, lr} */
/* @0xc5e28 ldr r4, [pc, #0xbc] */
/* @0xc5e2c ldr r0, [sp, #0x10] */
/* @0xc5e30 ldr r4, [pc, r4] */
/* @0xc5e34 ldr r1, [r4] */
/* @0xc5e38 cmp r1, #0 */
/* @0xc5e3c beq 0xc5e50 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0xc5e40 ldr r0, [pc, #0xa8] */
/* @0xc5e44 pop {r3, r4, r5, lr} */
/* @0xc5e48 add r0, pc, r0 */
/* @0xc5e4c b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc5e50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5e54 mov r1, #32 */
/* @0xc5e58 mov r5, r0 */
/* @0xc5e5c bl 0xb6634 <strchr@plt> */
/* @0xc5e60 cmp r0, #0 */
/* @0xc5e64 beq 0xc5e78 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xc5e68 ldr r0, [pc, #0x84] */
/* @0xc5e6c pop {r3, r4, r5, lr} */
/* @0xc5e70 add r0, pc, r0 */
/* @0xc5e74 b 0xd547c <_Z7YYErrorPKcz> */
/* @0xc5e78 mov r0, r5 */
/* @0xc5e7c mov r1, #9 */
/* @0xc5e80 bl 0xb6634 <strchr@plt> */
/* @0xc5e84 cmp r0, #0 */
/* @0xc5e88 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc5e8c mov r0, r5 */
/* @0xc5e90 mov r1, #13 */
/* @0xc5e94 bl 0xb6634 <strchr@plt> */
/* @0xc5e98 cmp r0, #0 */
/* @0xc5e9c bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc5ea0 mov r0, r5 */
/* @0xc5ea4 mov r1, #10 */
/* @0xc5ea8 bl 0xb6634 <strchr@plt> */
/* @0xc5eac cmp r0, #0 */
/* @0xc5eb0 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc5eb4 mov r0, r5 */
/* @0xc5eb8 mov r1, #92 */
/* @0xc5ebc bl 0xb6634 <strchr@plt> */
/* @0xc5ec0 cmp r0, #0 */
/* @0xc5ec4 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc5ec8 mov r0, r5 */
/* @0xc5ecc mov r1, #47 */
/* @0xc5ed0 bl 0xb6634 <strchr@plt> */
/* @0xc5ed4 cmp r0, #0 */
/* @0xc5ed8 bne 0xc5e68 <_Z26F_BUFFER_Async_Group_BeginR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0xc5edc mov r0, r5 */
/* @0xc5ee0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc5ee4 str r0, [r4] */
/* @0xc5ee8 pop {r3, r4, r5, pc} */
/* @0xc5eec eorseq r7, r2, r8, lsl #23 */
/* @0xc5ef0 eoreq r10, r6, r12, lsl #28 */
/* @0xc5ef4 eoreq r10, r6, r4, lsl #28 */

/* ── FUNC 0xc5ef8 · F_BUFFER_Async_Group_Option(RValue&, CInstance*, CInstance*, int, RValue*) · size=604 · insn=151 */
/* @0xc5ef8 push {r3, r4, r5, r6, r7, lr} */
/* @0xc5efc mov r3, #0 */
/* @0xc5f00 ldr r6, [sp, #0x18] */
/* @0xc5f04 mov r4, r0 */
/* @0xc5f08 str r3, [r0] */
/* @0xc5f0c mov r1, r3 */
/* @0xc5f10 str r3, [r0, #0x4] */
/* @0xc5f14 str r3, [r0, #0xc] */
/* @0xc5f18 mov r0, r6 */
/* @0xc5f1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5f20 ldr r5, [pc, #0x1e8] */
/* @0xc5f24 add r5, pc, r5 */
/* @0xc5f28 subs r7, r0, #0 */
/* @0xc5f2c popeq {r3, r4, r5, r6, r7, pc} */
/* @0xc5f30 ldr r1, [pc, #0x1dc] */
/* @0xc5f34 add r1, pc, r1 */
/* @0xc5f38 bl 0xb6574 <strcmp@plt> */
/* @0xc5f3c cmp r0, #0 */
/* @0xc5f40 beq 0xc5f9c <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0xc5f44 ldr r1, [pc, #0x1cc] */
/* @0xc5f48 mov r0, r7 */
/* @0xc5f4c add r1, pc, r1 */
/* @0xc5f50 bl 0xb6574 <strcmp@plt> */
/* @0xc5f54 cmp r0, #0 */
/* @0xc5f58 bne 0xc5fa4 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc5f5c ldr r2, [pc, #0x1b8] */
/* @0xc5f60 str r0, [r4] */
/* @0xc5f64 mov r3, #0 */
/* @0xc5f68 movt r3, #0x3ff0 */
/* @0xc5f6c str r3, [r4, #0x4] */
/* @0xc5f70 ldr r4, [r5, r2] */
/* @0xc5f74 ldr r0, [r4] */
/* @0xc5f78 cmp r0, #0 */
/* @0xc5f7c beq 0xc5f84 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xc5f80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc5f84 mov r1, #1 */
/* @0xc5f88 mov r0, r6 */
/* @0xc5f8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc5f90 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc5f94 str r0, [r4] */
/* @0xc5f98 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc5f9c ldr r2, [pc, #0x17c] */
/* @0xc5fa0 b 0xc5f60 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0xc5fa4 ldr r1, [pc, #0x178] */
/* @0xc5fa8 mov r0, r7 */
/* @0xc5fac add r1, pc, r1 */
/* @0xc5fb0 bl 0xb6574 <strcmp@plt> */
/* @0xc5fb4 subs r1, r0, #0 */
/* @0xc5fb8 beq 0xc6044 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0xc5fbc ldr r1, [pc, #0x164] */
/* @0xc5fc0 mov r0, r7 */
/* @0xc5fc4 add r1, pc, r1 */
/* @0xc5fc8 bl 0xb6574 <strcmp@plt> */
/* @0xc5fcc cmp r0, #0 */
/* @0xc5fd0 beq 0xc6098 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0xc5fd4 ldr r1, [pc, #0x150] */
/* @0xc5fd8 mov r0, r7 */
/* @0xc5fdc add r1, pc, r1 */
/* @0xc5fe0 bl 0xb6574 <strcmp@plt> */
/* @0xc5fe4 cmp r0, #0 */
/* @0xc5fe8 beq 0xc60d8 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0xc5fec ldr r1, [pc, #0x13c] */
/* @0xc5ff0 mov r0, r7 */
/* @0xc5ff4 add r1, pc, r1 */
/* @0xc5ff8 bl 0xb6574 <strcmp@plt> */
/* @0xc5ffc cmp r0, #0 */
/* @0xc6000 beq 0xc60f4 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0xc6004 ldr r1, [pc, #0x128] */
/* @0xc6008 mov r0, r7 */
/* @0xc600c add r1, pc, r1 */
/* @0xc6010 bl 0xb6574 <strcmp@plt> */
/* @0xc6014 cmp r0, #0 */
/* @0xc6018 beq 0xc607c <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0xc601c ldr r3, [pc, #0x114] */
/* @0xc6020 mov r2, r7 */
/* @0xc6024 ldr r1, [pc, #0x110] */
/* @0xc6028 ldr r3, [r5, r3] */
/* @0xc602c add r1, pc, r1 */
/* @0xc6030 ldr r0, [r3] */
/* @0xc6034 ldr r3, [r0] */
/* @0xc6038 ldr r3, [r3, #0xc] */
/* @0xc603c blx r3 */
/* @0xc6040 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc6044 add r0, r6, #16 */
/* @0xc6048 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xc604c ldr r3, [pc, #0xec] */
/* @0xc6050 cmp r0, #0 */
/* @0xc6054 ldrne r3, [r5, r3] */
/* @0xc6058 movne r2, #1 */
/* @0xc605c ldreq r3, [r5, r3] */
/* @0xc6060 strbne r2, [r3] */
/* @0xc6064 strbeq r0, [r3] */
/* @0xc6068 mov r3, #0 */
/* @0xc606c mov r2, r3 */
/* @0xc6070 movt r3, #0x3ff0 */
/* @0xc6074 stm r4, {r2, r3} */
/* @0xc6078 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc607c mov r0, r6 */
/* @0xc6080 mov r1, #1 */
/* @0xc6084 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6088 ldr r3, [pc, #0xb4] */
/* @0xc608c ldr r3, [r5, r3] */
/* @0xc6090 str r0, [r3] */
/* @0xc6094 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc6098 mov r0, #12 */
/* @0xc609c bl 0x27c524 <_Znwj> */
/* @0xc60a0 mov r1, #1 */
/* @0xc60a4 mov r4, r0 */
/* @0xc60a8 mov r0, r6 */
/* @0xc60ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc60b0 bl 0xb6640 <strdup@plt> */
/* @0xc60b4 ldr r3, [pc, #0x8c] */
/* @0xc60b8 mov r2, #1 */
/* @0xc60bc strb r2, [r4, #0x8] */
/* @0xc60c0 str r0, [r4, #0x4] */
/* @0xc60c4 ldr r3, [r5, r3] */
/* @0xc60c8 ldr r2, [r3] */
/* @0xc60cc str r2, [r4] */
/* @0xc60d0 str r4, [r3] */
/* @0xc60d4 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc60d8 mov r0, r6 */
/* @0xc60dc mov r1, #1 */
/* @0xc60e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc60e4 ldr r3, [pc, #0x60] */
/* @0xc60e8 ldr r3, [r5, r3] */
/* @0xc60ec str r0, [r3] */
/* @0xc60f0 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc60f4 mov r0, r6 */
/* @0xc60f8 mov r1, #1 */
/* @0xc60fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6100 ldr r3, [pc, #0x48] */
/* @0xc6104 ldr r3, [r5, r3] */
/* @0xc6108 str r0, [r3] */
/* @0xc610c pop {r3, r4, r5, r6, r7, pc} */
/* @0xc6110 eorseq r11, r2, r12, lsr #26 */
/* @0xc6114 eoreq r10, r6, r0, lsl #27 */
/* @0xc6118 eoreq r10, r6, r4, ror sp */
/* @0xc611c .word 0xffffbd6c */
/* @0xc6120 .word 0xffffbd70 */
/* @0xc6124 eoreq r10, r6, r0, lsr #26 */
/* @0xc6128 eoreq r10, r6, r4, lsl sp */
/* @0xc612c eoreq r10, r6, r8, lsl #26 */
/* @0xc6130 eoreq r10, r6, r0, lsl #26 */
/* @0xc6134 .word 0x0026acf8 */
/* @0xc6138 .word 0xffffbac4 */
/* @0xc613c eoreq r10, r6, r12, ror #25 */
/* @0xc6140 .word 0xffffbd74 */
/* @0xc6144 .word 0xffffbd78 */
/* @0xc6148 .word 0xffffbd7c */
/* @0xc614c .word 0xffffbd80 */
/* @0xc6150 .word 0xffffbd84 */

/* ── FUNC 0xc6154 · F_BUFFER_GetSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=244 · insn=61 */
/* @0xc6154 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc6158 sub sp, sp, #12 */
/* @0xc615c mov r1, #0 */
/* @0xc6160 ldr r4, [sp, #0x28] */
/* @0xc6164 mov r0, r4 */
/* @0xc6168 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc616c subs r5, r0, #0 */
/* @0xc6170 blt 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0xc6174 ldr r6, [pc, #0xc0] */
/* @0xc6178 add r6, pc, r6 */
/* @0xc617c ldr r3, [r6] */
/* @0xc6180 cmp r5, r3 */
/* @0xc6184 bge 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0xc6188 ldr r3, [r6, #0x4] */
/* @0xc618c ldr r3, [r3, r5, lsl #2] */
/* @0xc6190 cmp r3, #0 */
/* @0xc6194 beq 0xc6210 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0xc6198 mov r1, #1 */
/* @0xc619c mov r0, r4 */
/* @0xc61a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc61a4 mov r7, r0 */
/* @0xc61a8 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0xc61ac subs r1, r0, #0 */
/* @0xc61b0 beq 0xc6228 <_Z19F_BUFFER_GetSurfaceR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0xc61b4 ldr r3, [r6, #0x4] */
/* @0xc61b8 mov r0, r4 */
/* @0xc61bc mov r1, #2 */
/* @0xc61c0 ldr r5, [r3, r5, lsl #2] */
/* @0xc61c4 ldr r3, [r5] */
/* @0xc61c8 ldr r6, [r3, #0x40] */
/* @0xc61cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc61d0 mov r1, #3 */
/* @0xc61d4 mov r9, r0 */
/* @0xc61d8 mov r0, r4 */
/* @0xc61dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc61e0 mov r1, #4 */
/* @0xc61e4 mov r8, r0 */
/* @0xc61e8 mov r0, r4 */
/* @0xc61ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc61f0 mov r2, r9 */
/* @0xc61f4 mov r3, r8 */
/* @0xc61f8 mov r1, r7 */
/* @0xc61fc str r0, [sp] */
/* @0xc6200 mov r0, r5 */
/* @0xc6204 blx r6 */
/* @0xc6208 add sp, sp, #12 */
/* @0xc620c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xc6210 ldr r0, [pc, #0x28] */
/* @0xc6214 mov r1, #0 */
/* @0xc6218 add r0, pc, r0 */
/* @0xc621c add sp, sp, #12 */
/* @0xc6220 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc6224 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6228 ldr r0, [pc, #0x14] */
/* @0xc622c add r0, pc, r0 */
/* @0xc6230 add sp, sp, #12 */
/* @0xc6234 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc6238 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc623c mlaseq r11, r12, pc, r3 */
/* @0xc6240 eoreq r10, r6, r12, lsr r11 */
/* @0xc6244 eoreq r10, r6, r12, asr r11 */

/* ── FUNC 0xc6248 · F_BUFFER_SetSurface(RValue&, CInstance*, CInstance*, int, RValue*) · size=208 · insn=52 */
/* @0xc6248 push {r4, r5, r6, r7, r8, lr} */
/* @0xc624c mov r1, #0 */
/* @0xc6250 ldr r4, [sp, #0x18] */
/* @0xc6254 mov r0, r4 */
/* @0xc6258 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc625c subs r5, r0, #0 */
/* @0xc6260 blt 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0xc6264 ldr r6, [pc, #0xa0] */
/* @0xc6268 add r6, pc, r6 */
/* @0xc626c ldr r3, [r6] */
/* @0xc6270 cmp r5, r3 */
/* @0xc6274 bge 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0xc6278 ldr r3, [r6, #0x4] */
/* @0xc627c ldr r3, [r3, r5, lsl #2] */
/* @0xc6280 cmp r3, #0 */
/* @0xc6284 beq 0xc62e8 <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0xc6288 mov r1, #1 */
/* @0xc628c mov r0, r4 */
/* @0xc6290 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6294 mov r7, r0 */
/* @0xc6298 bl 0x1714c0 <_Z17GR_Surface_Existsi> */
/* @0xc629c subs r1, r0, #0 */
/* @0xc62a0 beq 0xc62fc <_Z19F_BUFFER_SetSurfaceR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xc62a4 ldr r3, [r6, #0x4] */
/* @0xc62a8 mov r0, r4 */
/* @0xc62ac mov r1, #3 */
/* @0xc62b0 ldr r5, [r3, r5, lsl #2] */
/* @0xc62b4 ldr r3, [r5] */
/* @0xc62b8 ldr r6, [r3, #0x44] */
/* @0xc62bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc62c0 mov r1, #4 */
/* @0xc62c4 mov r8, r0 */
/* @0xc62c8 mov r0, r4 */
/* @0xc62cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc62d0 mov r1, r7 */
/* @0xc62d4 mov r2, r8 */
/* @0xc62d8 mov r3, r0 */
/* @0xc62dc mov r0, r5 */
/* @0xc62e0 blx r6 */
/* @0xc62e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc62e8 ldr r0, [pc, #0x20] */
/* @0xc62ec mov r1, #0 */
/* @0xc62f0 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc62f4 add r0, pc, r0 */
/* @0xc62f8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc62fc ldr r0, [pc, #0x10] */
/* @0xc6300 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc6304 add r0, pc, r0 */
/* @0xc6308 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc630c eorseq r3, r11, r12, lsr #29 */
/* @0xc6310 eoreq r10, r6, r12, asr #21 */
/* @0xc6314 .word 0x0026aaf0 */

/* ── FUNC 0xc6318 · F_BUFFER_GetAddress(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0xc6318 push {r4, lr} */
/* @0xc631c mov r2, #3 */
/* @0xc6320 ldr r3, [sp, #0x8] */
/* @0xc6324 mov r4, r0 */
/* @0xc6328 str r2, [r0, #0xc] */
/* @0xc632c mov r1, #0 */
/* @0xc6330 mov r0, r3 */
/* @0xc6334 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6338 cmp r0, #0 */
/* @0xc633c blt 0xc636c <_Z19F_BUFFER_GetAddressR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xc6340 ldr r3, [pc, #0x38] */
/* @0xc6344 add r3, pc, r3 */
/* @0xc6348 ldr r2, [r3] */
/* @0xc634c cmp r0, r2 */
/* @0xc6350 bge 0xc636c <_Z19F_BUFFER_GetAddressR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xc6354 ldr r3, [r3, #0x4] */
/* @0xc6358 ldr r3, [r3, r0, lsl #2] */
/* @0xc635c cmp r3, #0 */
/* @0xc6360 ldrne r3, [r3, #0xc] */
/* @0xc6364 strne r3, [r4] */
/* @0xc6368 popne {r4, pc} */
/* @0xc636c ldr r0, [pc, #0x10] */
/* @0xc6370 mov r1, #0 */
/* @0xc6374 pop {r4, lr} */
/* @0xc6378 add r0, pc, r0 */
/* @0xc637c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6380 ldrsbteq r3, [r11], -r0 */
/* @0xc6384 .word 0x0026aab4 */

/* ── FUNC 0xc6388 · F_BUFFER_Tell(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0xc6388 push {r4, lr} */
/* @0xc638c mov r1, #0 */
/* @0xc6390 ldr r2, [sp, #0x8] */
/* @0xc6394 mov r3, r1 */
/* @0xc6398 str r1, [r0, #0xc] */
/* @0xc639c movt r3, #0xbff0 */
/* @0xc63a0 mov r4, r0 */
/* @0xc63a4 stm r0, {r1, r3} */
/* @0xc63a8 mov r0, r2 */
/* @0xc63ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc63b0 cmp r0, #0 */
/* @0xc63b4 blt 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc63b8 ldr r3, [pc, #0x48] */
/* @0xc63bc add r3, pc, r3 */
/* @0xc63c0 ldr r2, [r3] */
/* @0xc63c4 cmp r0, r2 */
/* @0xc63c8 bge 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc63cc ldr r3, [r3, #0x4] */
/* @0xc63d0 ldr r3, [r3, r0, lsl #2] */
/* @0xc63d4 cmp r3, #0 */
/* @0xc63d8 beq 0xc63f4 <_Z13F_BUFFER_TellR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc63dc ldr r2, [r3, #0x1c] */
/* @0xc63e0 vmov s15, r2 */
/* @0xc63e4 vcvt.f64.s32 d7, s15 */
/* @0xc63e8 vmov r2, r3, d7 */
/* @0xc63ec stm r4, {r2, r3} */
/* @0xc63f0 pop {r4, pc} */
/* @0xc63f4 ldr r0, [pc, #0x10] */
/* @0xc63f8 mov r1, #0 */
/* @0xc63fc pop {r4, lr} */
/* @0xc6400 add r0, pc, r0 */
/* @0xc6404 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6408 eorseq r3, r11, r8, asr sp */
/* @0xc640c .word 0x0026a7b4 */

/* ── FUNC 0xc6410 · F_BUFFER_Get_Size(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0xc6410 push {r4, lr} */
/* @0xc6414 mov r1, #0 */
/* @0xc6418 ldr r2, [sp, #0x8] */
/* @0xc641c mov r3, r1 */
/* @0xc6420 str r1, [r0, #0xc] */
/* @0xc6424 movt r3, #0xbff0 */
/* @0xc6428 mov r4, r0 */
/* @0xc642c stm r0, {r1, r3} */
/* @0xc6430 mov r0, r2 */
/* @0xc6434 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6438 cmp r0, #0 */
/* @0xc643c blt 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc6440 ldr r3, [pc, #0x48] */
/* @0xc6444 add r3, pc, r3 */
/* @0xc6448 ldr r2, [r3] */
/* @0xc644c cmp r0, r2 */
/* @0xc6450 bge 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc6454 ldr r3, [r3, #0x4] */
/* @0xc6458 ldr r3, [r3, r0, lsl #2] */
/* @0xc645c cmp r3, #0 */
/* @0xc6460 beq 0xc647c <_Z17F_BUFFER_Get_SizeR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0xc6464 ldr r2, [r3, #0x10] */
/* @0xc6468 vmov s15, r2 */
/* @0xc646c vcvt.f64.s32 d7, s15 */
/* @0xc6470 vmov r2, r3, d7 */
/* @0xc6474 stm r4, {r2, r3} */
/* @0xc6478 pop {r4, pc} */
/* @0xc647c ldr r0, [pc, #0x10] */
/* @0xc6480 mov r1, #0 */
/* @0xc6484 pop {r4, lr} */
/* @0xc6488 add r0, pc, r0 */
/* @0xc648c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6490 ldrsbteq r3, [r11], -r0 */
/* @0xc6494 eoreq r10, r6, r12, lsr #14 */

/* ── FUNC 0xc6498 · F_BUFFER_Copy_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=532 · insn=133 */
/* @0xc6498 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc649c sub sp, sp, #24 */
/* @0xc64a0 mov r1, #0 */
/* @0xc64a4 ldr r4, [sp, #0x38] */
/* @0xc64a8 mov r0, r4 */
/* @0xc64ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc64b0 mov r1, #1 */
/* @0xc64b4 mov r7, r0 */
/* @0xc64b8 mov r0, r4 */
/* @0xc64bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc64c0 mov r1, #2 */
/* @0xc64c4 mov r5, r0 */
/* @0xc64c8 mov r0, r4 */
/* @0xc64cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc64d0 mov r1, #3 */
/* @0xc64d4 mov r6, r0 */
/* @0xc64d8 mov r0, r4 */
/* @0xc64dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc64e0 mov r1, #4 */
/* @0xc64e4 mov r8, r0 */
/* @0xc64e8 mov r0, r4 */
/* @0xc64ec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc64f0 mov r9, r0 */
/* @0xc64f4 mov r0, r7 */
/* @0xc64f8 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc64fc subs r4, r0, #0 */
/* @0xc6500 beq 0xc665c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0xc6504 ldrb r1, [r4, #0x20] */
/* @0xc6508 ldr r0, [pc, #0x178] */
/* @0xc650c cmp r1, #0 */
/* @0xc6510 add r0, pc, r0 */
/* @0xc6514 bne 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0xc6518 ldr r12, [r4, #0x1c] */
/* @0xc651c cmp r12, #0 */
/* @0xc6520 beq 0xc6644 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0xc6524 ldr r0, [r4, #0x28] */
/* @0xc6528 cmn r0, #1 */
/* @0xc652c beq 0xc6644 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0xc6530 cmp r6, #0 */
/* @0xc6534 ble 0xc666c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0xc6538 cmp r5, #0 */
/* @0xc653c blt 0xc6650 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0xc6540 cmp r5, r12 */
/* @0xc6544 bge 0xc6650 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0xc6548 add r3, r5, r6 */
/* @0xc654c cmp r12, r3 */
/* @0xc6550 rsblt r6, r5, r12 */
/* @0xc6554 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc6558 subs r7, r0, #0 */
/* @0xc655c beq 0xc6678 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0xc6560 cmp r8, #0 */
/* @0xc6564 ldr r12, [r7, #0x14] */
/* @0xc6568 blt 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0xc656c ldr r3, [pc, #0x118] */
/* @0xc6570 add r3, pc, r3 */
/* @0xc6574 ldr r2, [r3] */
/* @0xc6578 cmp r8, r2 */
/* @0xc657c bge 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0xc6580 ldr r3, [r3, #0x4] */
/* @0xc6584 ldr r0, [r3, r8, lsl #2] */
/* @0xc6588 cmp r0, #0 */
/* @0xc658c beq 0xc662c <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0xc6590 ldr r10, [r0, #0x18] */
/* @0xc6594 ldr r2, [r4, #0x1c] */
/* @0xc6598 cmp r10, #1 */
/* @0xc659c mul r3, r12, r5 */
/* @0xc65a0 moveq lr, r10 */
/* @0xc65a4 mul r2, r2, r12 */
/* @0xc65a8 beq 0xc65b8 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0xc65ac ldr lr, [r0, #0x10] */
/* @0xc65b0 rsbs lr, lr, #1 */
/* @0xc65b4 movlo lr, #0 */
/* @0xc65b8 mul r12, r12, r6 */
/* @0xc65bc subs r5, r10, #2 */
/* @0xc65c0 ldr r1, [r4] */
/* @0xc65c4 rsbs r4, r5, #0 */
/* @0xc65c8 adcs r4, r4, r5 */
/* @0xc65cc str lr, [sp, #0x8] */
/* @0xc65d0 str r9, [sp, #0x4] */
/* @0xc65d4 str r4, [sp, #0xc] */
/* @0xc65d8 str r12, [sp] */
/* @0xc65dc mov r12, #0 */
/* @0xc65e0 str r12, [sp, #0x10] */
/* @0xc65e4 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xc65e8 bl 0x212e98 <_Z11IsBigEndianv> */
/* @0xc65ec cmp r0, #0 */
/* @0xc65f0 beq 0xc6624 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0xc65f4 ldr r1, [pc, #0x94] */
/* @0xc65f8 mov r0, r7 */
/* @0xc65fc mov r2, r6 */
/* @0xc6600 mov r3, r9 */
/* @0xc6604 add r1, pc, r1 */
/* @0xc6608 ldr r1, [r1, #0x4] */
/* @0xc660c ldr r12, [r1, r8, lsl #2] */
/* @0xc6610 ldr r1, [r12, #0xc] */
/* @0xc6614 ldr r12, [r12, #0x10] */
/* @0xc6618 str r4, [sp, #0x4] */
/* @0xc661c str r12, [sp] */
/* @0xc6620 bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib> */
/* @0xc6624 add sp, sp, #24 */
/* @0xc6628 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc662c ldr r0, [pc, #0x60] */
/* @0xc6630 add r0, pc, r0 */
/* @0xc6634 mov r1, #0 */
/* @0xc6638 add sp, sp, #24 */
/* @0xc663c pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc6640 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6644 ldr r0, [pc, #0x4c] */
/* @0xc6648 add r0, pc, r0 */
/* @0xc664c b 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0xc6650 ldr r0, [pc, #0x44] */
/* @0xc6654 add r0, pc, r0 */
/* @0xc6658 b 0xc6634 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0xc665c ldr r0, [pc, #0x3c] */
/* @0xc6660 mov r1, r4 */
/* @0xc6664 add r0, pc, r0 */
/* @0xc6668 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0xc666c ldr r0, [pc, #0x30] */
/* @0xc6670 add r0, pc, r0 */
/* @0xc6674 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0xc6678 ldr r0, [pc, #0x28] */
/* @0xc667c mov r1, r7 */
/* @0xc6680 add r0, pc, r0 */
/* @0xc6684 b 0xc6638 <_Z32F_BUFFER_Copy_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0xc6688 eoreq r10, r6, r4, lsl #19 */
/* @0xc668c eorseq r3, r11, r4, lsr #23 */
/* @0xc6690 eorseq r3, r11, r0, lsl r11 */
/* @0xc6694 .word 0x0026a9bc */
/* @0xc6698 mlaeq r6, r4, r8, r10 */
/* @0xc669c eoreq r10, r6, r4, lsl r9 */
/* @0xc66a0 .word 0x0026a7f4 */
/* @0xc66a4 .word 0x0026a8b4 */
/* @0xc66a8 eoreq r10, r6, r0, lsr r9 */

/* ── FUNC 0xc66ac · ASYNC_SAVE_LOAD_REQ_CONTEXT::~ASYNC_SAVE_LOAD_REQ_CONTEXT() · size=116 · insn=29 */
/* @0xc66ac push {r4, r5, r6, lr} */
/* @0xc66b0 mov r6, r0 */
/* @0xc66b4 ldr r4, [r0, #0x44] */
/* @0xc66b8 ldr r3, [pc, #0x5c] */
/* @0xc66bc cmp r4, #0 */
/* @0xc66c0 ldr r3, [pc, r3] */
/* @0xc66c4 add r3, r3, #8 */
/* @0xc66c8 str r3, [r0] */
/* @0xc66cc beq 0xc66f0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD0Ev+0x44> */
/* @0xc66d0 ldr r5, [r4] */
/* @0xc66d4 ldr r0, [r4, #0x8] */
/* @0xc66d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc66dc ldr r0, [r4, #0xc] */
/* @0xc66e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc66e4 cmp r5, #0 */
/* @0xc66e8 mov r4, r5 */
/* @0xc66ec bne 0xc66d0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXTD0Ev+0x24> */
/* @0xc66f0 ldr r0, [r6, #0x48] */
/* @0xc66f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc66f8 mov r3, #0 */
/* @0xc66fc mov r0, r6 */
/* @0xc6700 str r3, [r6, #0x44] */
/* @0xc6704 str r3, [r6, #0x48] */
/* @0xc6708 bl 0x18d724 <_ZN16HTTP_REQ_CONTEXTD2Ev> */
/* @0xc670c mov r0, r6 */
/* @0xc6710 bl 0x27d1d0 <_ZdlPv> */
/* @0xc6714 mov r0, r6 */
/* @0xc6718 pop {r4, r5, r6, pc} */
/* @0xc671c ldrshteq r7, [r2], -r4 */

/* ── FUNC 0xc6720 · GetIBuffer(int) · size=52 · insn=13 */
/* @0xc6720 cmp r0, #0 */
/* @0xc6724 blt 0xc6748 <_Z10GetIBufferi+0x28> */
/* @0xc6728 ldr r3, [pc, #0x20] */
/* @0xc672c add r3, pc, r3 */
/* @0xc6730 ldr r2, [r3] */
/* @0xc6734 cmp r0, r2 */
/* @0xc6738 bge 0xc6748 <_Z10GetIBufferi+0x28> */
/* @0xc673c ldr r3, [r3, #0x4] */
/* @0xc6740 ldr r0, [r3, r0, lsl #2] */
/* @0xc6744 bx lr */
/* @0xc6748 mov r0, #0 */
/* @0xc674c bx lr */
/* @0xc6750 eorseq r3, r11, r8, ror #19 */

/* ── FUNC 0xc6754 · GetIBuffer(void*) · size=92 · insn=23 */
/* @0xc6754 ldr r3, [pc, #0x50] */
/* @0xc6758 str r4, [sp, #-0x4]! */
/* @0xc675c add r3, pc, r3 */
/* @0xc6760 ldr r4, [r3] */
/* @0xc6764 cmp r4, #0 */
/* @0xc6768 ble 0xc679c <_Z10GetIBufferPv+0x48> */
/* @0xc676c ldr r1, [r3, #0x4] */
/* @0xc6770 mov r3, #0 */
/* @0xc6774 sub r1, r1, #4 */
/* @0xc6778 ldr r2, [r1, #0x4]! */
/* @0xc677c add r3, r3, #1 */
/* @0xc6780 cmp r2, #0 */
/* @0xc6784 beq 0xc6794 <_Z10GetIBufferPv+0x40> */
/* @0xc6788 ldr r12, [r2, #0xc] */
/* @0xc678c cmp r12, r0 */
/* @0xc6790 beq 0xc67a0 <_Z10GetIBufferPv+0x4c> */
/* @0xc6794 cmp r3, r4 */
/* @0xc6798 bne 0xc6778 <_Z10GetIBufferPv+0x24> */
/* @0xc679c mov r2, #0 */
/* @0xc67a0 mov r0, r2 */
/* @0xc67a4 ldr r4, [sp], #4 */
/* @0xc67a8 bx lr */
/* @0xc67ac ldrhteq r3, [r11], -r8 */

/* ── FUNC 0xc67b0 · AllocBuffer() · size=200 · insn=50 */
/* @0xc67b0 ldr r3, [pc, #0xb0] */
/* @0xc67b4 push {r4, lr} */
/* @0xc67b8 add r3, pc, r3 */
/* @0xc67bc sub sp, sp, #8 */
/* @0xc67c0 ldr r4, [r3] */
/* @0xc67c4 ldr r0, [r3, #0x4] */
/* @0xc67c8 cmp r4, #0 */
/* @0xc67cc ble 0xc6854 <_Z11AllocBufferv+0xa4> */
/* @0xc67d0 ldr r3, [r0] */
/* @0xc67d4 cmp r3, #0 */
/* @0xc67d8 beq 0xc6844 <_Z11AllocBufferv+0x94> */
/* @0xc67dc mov r2, r0 */
/* @0xc67e0 mov r3, #0 */
/* @0xc67e4 b 0xc67f4 <_Z11AllocBufferv+0x44> */
/* @0xc67e8 ldr r1, [r2, #0x4]! */
/* @0xc67ec cmp r1, #0 */
/* @0xc67f0 beq 0xc6844 <_Z11AllocBufferv+0x94> */
/* @0xc67f4 add r3, r3, #1 */
/* @0xc67f8 cmp r3, r4 */
/* @0xc67fc bne 0xc67e8 <_Z11AllocBufferv+0x38> */
/* @0xc6800 ldr r3, [pc, #0x64] */
/* @0xc6804 lsl r1, r4, #3 */
/* @0xc6808 lsl r2, r4, #1 */
/* @0xc680c add r3, pc, r3 */
/* @0xc6810 str r2, [r3] */
/* @0xc6814 ldr r2, [pc, #0x54] */
/* @0xc6818 mov r3, #0 */
/* @0xc681c str r3, [sp] */
/* @0xc6820 mov r3, #74 */
/* @0xc6824 add r2, pc, r2 */
/* @0xc6828 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0xc682c ldr r3, [pc, #0x40] */
/* @0xc6830 add r3, pc, r3 */
/* @0xc6834 str r0, [r3, #0x4] */
/* @0xc6838 mov r0, r4 */
/* @0xc683c add sp, sp, #8 */
/* @0xc6840 pop {r4, pc} */
/* @0xc6844 mov r4, r3 */
/* @0xc6848 mov r0, r4 */
/* @0xc684c add sp, sp, #8 */
/* @0xc6850 pop {r4, pc} */
/* @0xc6854 moveq r2, #32 */
/* @0xc6858 moveq r1, #128 */
/* @0xc685c streq r2, [r3] */
/* @0xc6860 beq 0xc6814 <_Z11AllocBufferv+0x64> */
/* @0xc6864 b 0xc6800 <_Z11AllocBufferv+0x50> */
/* @0xc6868 eorseq r3, r11, r12, asr r9 */
/* @0xc686c eorseq r3, r11, r8, lsl #18 */
/* @0xc6870 eoreq r10, r6, r12, lsl #16 */
/* @0xc6874 eorseq r3, r11, r4, ror #17 */

/* ── FUNC 0xc6878 · F_BUFFER_Load(RValue&, CInstance*, CInstance*, int, RValue*) · size=212 · insn=53 */
/* @0xc6878 push {r4, r5, r6, r7, lr} */
/* @0xc687c mov r3, #0 */
/* @0xc6880 sub sp, sp, #12 */
/* @0xc6884 mov r5, r0 */
/* @0xc6888 mov r4, r3 */
/* @0xc688c movt r3, #0xbff0 */
/* @0xc6890 str r4, [r0, #0xc] */
/* @0xc6894 mov r0, #64 */
/* @0xc6898 str r3, [r5, #0x4] */
/* @0xc689c str r4, [r5] */
/* @0xc68a0 ldr r7, [sp, #0x20] */
/* @0xc68a4 bl 0x27c524 <_Znwj> */
/* @0xc68a8 mov r6, r0 */
/* @0xc68ac bl 0xcc900 <_ZN7IBufferC2Ev> */
/* @0xc68b0 ldr r3, [pc, #0x88] */
/* @0xc68b4 mov r1, r4 */
/* @0xc68b8 mov r0, r7 */
/* @0xc68bc ldr r3, [pc, r3] */
/* @0xc68c0 add r3, r3, #8 */
/* @0xc68c4 str r3, [r6] */
/* @0xc68c8 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc68cc str r4, [sp] */
/* @0xc68d0 mov r2, r4 */
/* @0xc68d4 mvn r3, #0 */
/* @0xc68d8 mov r1, r0 */
/* @0xc68dc mov r0, r6 */
/* @0xc68e0 bl 0xcd91c <_ZN7IBuffer4LoadEPKciii> */
/* @0xc68e4 subs r4, r0, #0 */
/* @0xc68e8 bne 0xc6914 <_Z13F_BUFFER_LoadR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0xc68ec ldr r3, [r6] */
/* @0xc68f0 mov r0, r6 */
/* @0xc68f4 ldr r3, [r3, #0x4] */
/* @0xc68f8 blx r3 */
/* @0xc68fc ldr r0, [pc, #0x40] */
/* @0xc6900 mov r1, r4 */
/* @0xc6904 add r0, pc, r0 */
/* @0xc6908 add sp, sp, #12 */
/* @0xc690c pop {r4, r5, r6, r7, lr} */
/* @0xc6910 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6914 bl 0xc67b0 <_Z11AllocBufferv> */
/* @0xc6918 ldr r1, [pc, #0x28] */
/* @0xc691c add r1, pc, r1 */
/* @0xc6920 ldr r1, [r1, #0x4] */
/* @0xc6924 vmov s15, r0 */
/* @0xc6928 str r6, [r1, r0, lsl #2] */
/* @0xc692c vcvt.f64.s32 d7, s15 */
/* @0xc6930 vmov r2, r3, d7 */
/* @0xc6934 stm r5, {r2, r3} */
/* @0xc6938 add sp, sp, #12 */
/* @0xc693c pop {r4, r5, r6, r7, pc} */
/* @0xc6940 ldrshteq r7, [r2], -r4 */
/* @0xc6944 eoreq r10, r6, r0, ror #14 */
/* @0xc6948 ldrshteq r3, [r11], -r8 */

/* ── FUNC 0xc694c · F_BUFFER_Base64_Decode(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0xc694c push {r3, r4, r5, r6, r7, lr} */
/* @0xc6950 mov r5, r0 */
/* @0xc6954 mov r3, #0 */
/* @0xc6958 ldr r7, [sp, #0x18] */
/* @0xc695c mov r4, r3 */
/* @0xc6960 movt r3, #0xbff0 */
/* @0xc6964 str r4, [r0, #0xc] */
/* @0xc6968 mov r0, #64 */
/* @0xc696c str r3, [r5, #0x4] */
/* @0xc6970 str r4, [r5] */
/* @0xc6974 bl 0x27c524 <_Znwj> */
/* @0xc6978 mov r6, r0 */
/* @0xc697c bl 0xcc900 <_ZN7IBufferC2Ev> */
/* @0xc6980 ldr r3, [pc, #0x7c] */
/* @0xc6984 mov r1, r4 */
/* @0xc6988 mov r0, r7 */
/* @0xc698c ldr r3, [pc, r3] */
/* @0xc6990 add r3, r3, #8 */
/* @0xc6994 str r3, [r6] */
/* @0xc6998 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc699c mov r2, r4 */
/* @0xc69a0 mvn r3, #0 */
/* @0xc69a4 mov r1, r0 */
/* @0xc69a8 mov r0, r6 */
/* @0xc69ac bl 0xcda18 <_ZN7IBuffer12Base64decodeEPKcii> */
/* @0xc69b0 subs r4, r0, #0 */
/* @0xc69b4 bne 0xc69dc <_Z22F_BUFFER_Base64_DecodeR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xc69b8 ldr r3, [r6] */
/* @0xc69bc mov r0, r6 */
/* @0xc69c0 ldr r3, [r3, #0x4] */
/* @0xc69c4 blx r3 */
/* @0xc69c8 ldr r0, [pc, #0x38] */
/* @0xc69cc mov r1, r4 */
/* @0xc69d0 add r0, pc, r0 */
/* @0xc69d4 pop {r3, r4, r5, r6, r7, lr} */
/* @0xc69d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc69dc bl 0xc67b0 <_Z11AllocBufferv> */
/* @0xc69e0 ldr r1, [pc, #0x24] */
/* @0xc69e4 add r1, pc, r1 */
/* @0xc69e8 ldr r1, [r1, #0x4] */
/* @0xc69ec vmov s15, r0 */
/* @0xc69f0 str r6, [r1, r0, lsl #2] */
/* @0xc69f4 vcvt.f64.s32 d7, s15 */
/* @0xc69f8 vmov r2, r3, d7 */
/* @0xc69fc stm r5, {r2, r3} */
/* @0xc6a00 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc6a04 eorseq r7, r2, r4, lsr #32 */
/* @0xc6a08 mlaeq r6, r4, r6, r10 */
/* @0xc6a0c eorseq r3, r11, r0, lsr r7 */

/* ── FUNC 0xc6a10 · AllocateIBuffer(void*, int, bool) · size=120 · insn=30 */
/* @0xc6a10 push {r4, r5, r6, r7, r8, lr} */
/* @0xc6a14 sub sp, sp, #8 */
/* @0xc6a18 mov r6, r1 */
/* @0xc6a1c mov r8, r2 */
/* @0xc6a20 mov r7, r0 */
/* @0xc6a24 bl 0xc67b0 <_Z11AllocBufferv> */
/* @0xc6a28 mov r4, r0 */
/* @0xc6a2c mov r0, #64 */
/* @0xc6a30 bl 0x27c524 <_Znwj> */
/* @0xc6a34 mov r2, r6 */
/* @0xc6a38 mov r12, #1 */
/* @0xc6a3c str r8, [sp, #0x4] */
/* @0xc6a40 mov r1, r7 */
/* @0xc6a44 mov r3, #0 */
/* @0xc6a48 str r12, [sp] */
/* @0xc6a4c mov r5, r0 */
/* @0xc6a50 bl 0xcca38 <_ZN7IBufferC2EPvi14eBuffer_Formatib> */
/* @0xc6a54 ldr r2, [pc, #0x24] */
/* @0xc6a58 mov r0, r4 */
/* @0xc6a5c ldr r3, [pc, #0x20] */
/* @0xc6a60 add r2, pc, r2 */
/* @0xc6a64 ldr r3, [pc, r3] */
/* @0xc6a68 ldr r2, [r2, #0x4] */
/* @0xc6a6c add r3, r3, #8 */
/* @0xc6a70 str r3, [r5] */
/* @0xc6a74 str r5, [r2, r4, lsl #2] */
/* @0xc6a78 add sp, sp, #8 */
/* @0xc6a7c pop {r4, r5, r6, r7, r8, pc} */
/* @0xc6a80 ldrhteq r3, [r11], -r4 */
/* @0xc6a84 eorseq r6, r2, r12, asr #30 */

/* ── FUNC 0xc6a88 · FreeIBuffer(int) · size=72 · insn=18 */
/* @0xc6a88 push {r3, r4, r5, lr} */
/* @0xc6a8c lsl r4, r0, #2 */
/* @0xc6a90 ldr r5, [pc, #0x34] */
/* @0xc6a94 add r5, pc, r5 */
/* @0xc6a98 ldr r3, [r5, #0x4] */
/* @0xc6a9c add r2, r3, r4 */
/* @0xc6aa0 ldr r0, [r3, r0, lsl #2] */
/* @0xc6aa4 cmp r0, #0 */
/* @0xc6aa8 beq 0xc6ac0 <_Z11FreeIBufferi+0x38> */
/* @0xc6aac ldr r3, [r0] */
/* @0xc6ab0 ldr r3, [r3, #0x4] */
/* @0xc6ab4 blx r3 */
/* @0xc6ab8 ldr r2, [r5, #0x4] */
/* @0xc6abc add r2, r2, r4 */
/* @0xc6ac0 mov r3, #0 */
/* @0xc6ac4 str r3, [r2] */
/* @0xc6ac8 pop {r3, r4, r5, pc} */
/* @0xc6acc eorseq r3, r11, r0, lsl #13 */

/* ── FUNC 0xc6ad0 · CreateBuffer(int, eBuffer_Format, int) · size=232 · insn=58 */
/* @0xc6ad0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc6ad4 mov r7, r0 */
/* @0xc6ad8 mov r4, r1 */
/* @0xc6adc mov r6, r2 */
/* @0xc6ae0 bl 0xc67b0 <_Z11AllocBufferv> */
/* @0xc6ae4 mov r5, r0 */
/* @0xc6ae8 cmp r4, #4 */
/* @0xc6aec addls pc, pc, r4, lsl #2 */
/* @0xc6af0 b 0xc6b90 <_Z12CreateBufferi14eBuffer_Formati+0xc0> */
/* @0xc6af4 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c> */
/* @0xc6af8 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c> */
/* @0xc6afc b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c> */
/* @0xc6b00 b 0xc6b08 <_Z12CreateBufferi14eBuffer_Formati+0x38> */
/* @0xc6b04 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c> */
/* @0xc6b08 mov r0, #64 */
/* @0xc6b0c bl 0x27c524 <_Znwj> */
/* @0xc6b10 mov r2, r4 */
/* @0xc6b14 mov r3, r6 */
/* @0xc6b18 mov r1, r7 */
/* @0xc6b1c mov r8, r0 */
/* @0xc6b20 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0xc6b24 ldr r2, [pc, #0x78] */
/* @0xc6b28 mov r0, r5 */
/* @0xc6b2c ldr r3, [pc, #0x74] */
/* @0xc6b30 add r2, pc, r2 */
/* @0xc6b34 ldr r3, [pc, r3] */
/* @0xc6b38 ldr r2, [r2, #0x4] */
/* @0xc6b3c add r3, r3, #8 */
/* @0xc6b40 str r3, [r8] */
/* @0xc6b44 str r8, [r2, r5, lsl #2] */
/* @0xc6b48 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc6b4c mov r0, #64 */
/* @0xc6b50 bl 0x27c524 <_Znwj> */
/* @0xc6b54 mov r2, r4 */
/* @0xc6b58 mov r3, r6 */
/* @0xc6b5c mov r1, r7 */
/* @0xc6b60 mov r8, r0 */
/* @0xc6b64 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati> */
/* @0xc6b68 ldr r2, [pc, #0x3c] */
/* @0xc6b6c mov r0, r5 */
/* @0xc6b70 ldr r3, [pc, #0x38] */
/* @0xc6b74 add r2, pc, r2 */
/* @0xc6b78 ldr r3, [pc, r3] */
/* @0xc6b7c ldr r2, [r2, #0x4] */
/* @0xc6b80 add r3, r3, #8 */
/* @0xc6b84 str r3, [r8] */
/* @0xc6b88 str r8, [r2, r5, lsl #2] */
/* @0xc6b8c pop {r4, r5, r6, r7, r8, pc} */
/* @0xc6b90 ldr r0, [pc, #0x1c] */
/* @0xc6b94 add r0, pc, r0 */
/* @0xc6b98 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xc6b9c mov r0, r5 */
/* @0xc6ba0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc6ba4 eorseq r3, r11, r4, ror #11 */
/* @0xc6ba8 eorseq r6, r2, r8, ror lr */
/* @0xc6bac eorseq r3, r11, r0, lsr #11 */
/* @0xc6bb0 eorseq r6, r2, r8, lsr lr */
/* @0xc6bb4 eoreq r10, r6, r8, ror #9 */

/* ── FUNC 0xc6bb8 · F_BUFFER_Create(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0xc6bb8 push {r4, r5, r6, r7, r8, lr} */
/* @0xc6bbc mov r5, #0 */
/* @0xc6bc0 ldr r6, [sp, #0x18] */
/* @0xc6bc4 mov r1, r5 */
/* @0xc6bc8 str r5, [r0, #0xc] */
/* @0xc6bcc mov r4, r0 */
/* @0xc6bd0 str r5, [r0] */
/* @0xc6bd4 mov r3, r5 */
/* @0xc6bd8 movt r3, #0xbff0 */
/* @0xc6bdc str r3, [r0, #0x4] */
/* @0xc6be0 mov r0, r6 */
/* @0xc6be4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6be8 mov r1, #1 */
/* @0xc6bec mov r7, r0 */
/* @0xc6bf0 mov r0, r6 */
/* @0xc6bf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6bf8 mov r1, #2 */
/* @0xc6bfc mov r8, r0 */
/* @0xc6c00 mov r0, r6 */
/* @0xc6c04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6c08 cmp r7, r5 */
/* @0xc6c0c mov r2, r0 */
/* @0xc6c10 ble 0xc6c5c <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0xc6c14 sub r3, r0, #1 */
/* @0xc6c18 cmp r3, #1024 */
/* @0xc6c1c bhs 0xc6c48 <_Z15F_BUFFER_CreateR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xc6c20 mov r1, r8 */
/* @0xc6c24 mov r0, r7 */
/* @0xc6c28 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0xc6c2c vmov s15, r0 */
/* @0xc6c30 vcvt.f64.s32 d7, s15 */
/* @0xc6c34 vmov r0, r1, d7 */
/* @0xc6c38 vmov r2, s14 */
/* @0xc6c3c mov r3, r1 */
/* @0xc6c40 stm r4, {r2, r3} */
/* @0xc6c44 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc6c48 ldr r0, [pc, #0x20] */
/* @0xc6c4c mov r1, r5 */
/* @0xc6c50 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc6c54 add r0, pc, r0 */
/* @0xc6c58 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6c5c ldr r0, [pc, #0x10] */
/* @0xc6c60 mov r1, r5 */
/* @0xc6c64 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc6c68 add r0, pc, r0 */
/* @0xc6c6c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6c70 .word 0x0026a4b0 */
/* @0xc6c74 eoreq r10, r6, r0, lsl #9 */

/* ── FUNC 0xc6c78 · F_BUFFER_Create_From_Vertex_Buffer(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=106 */
/* @0xc6c78 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc6c7c sub sp, sp, #24 */
/* @0xc6c80 mov r4, #0 */
/* @0xc6c84 mov r6, r0 */
/* @0xc6c88 ldr r5, [sp, #0x38] */
/* @0xc6c8c mov r1, r4 */
/* @0xc6c90 str r4, [r0, #0xc] */
/* @0xc6c94 mov r3, r4 */
/* @0xc6c98 str r4, [r0] */
/* @0xc6c9c movt r3, #0xbff0 */
/* @0xc6ca0 str r3, [r0, #0x4] */
/* @0xc6ca4 mov r0, r5 */
/* @0xc6ca8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6cac bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc6cb0 subs r7, r0, #0 */
/* @0xc6cb4 beq 0xc6dfc <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0xc6cb8 ldrb r8, [r7, #0x20] */
/* @0xc6cbc mov r1, r4 */
/* @0xc6cc0 ldr r0, [pc, #0x144] */
/* @0xc6cc4 cmp r8, #0 */
/* @0xc6cc8 add r0, pc, r0 */
/* @0xc6ccc bne 0xc6da4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0xc6cd0 ldr r3, [r7, #0x1c] */
/* @0xc6cd4 cmp r3, #0 */
/* @0xc6cd8 beq 0xc6db0 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0xc6cdc ldr r3, [r7, #0x28] */
/* @0xc6ce0 cmn r3, #1 */
/* @0xc6ce4 beq 0xc6db0 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0xc6ce8 mov r0, r5 */
/* @0xc6cec mov r1, #2 */
/* @0xc6cf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6cf4 sub r3, r0, #1 */
/* @0xc6cf8 mov r4, r0 */
/* @0xc6cfc cmp r3, #1024 */
/* @0xc6d00 bhs 0xc6de4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0xc6d04 ldr r0, [r7, #0x28] */
/* @0xc6d08 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc6d0c ldr r3, [r7, #0x1c] */
/* @0xc6d10 mov r1, #1 */
/* @0xc6d14 ldr r10, [r0, #0x14] */
/* @0xc6d18 mov r9, r0 */
/* @0xc6d1c mov r0, r5 */
/* @0xc6d20 mul r10, r10, r3 */
/* @0xc6d24 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6d28 mov r2, r4 */
/* @0xc6d2c mov r1, r0 */
/* @0xc6d30 mov r0, r10 */
/* @0xc6d34 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0xc6d38 vmov s15, r0 */
/* @0xc6d3c vcvt.f64.s32 d7, s15 */
/* @0xc6d40 vmov r4, r5, d7 */
/* @0xc6d44 vmov r2, s14 */
/* @0xc6d48 mov r3, r5 */
/* @0xc6d4c stm r6, {r2, r3} */
/* @0xc6d50 bl 0xc6720 <_Z10GetIBufferi> */
/* @0xc6d54 subs r5, r0, #0 */
/* @0xc6d58 beq 0xc6d98 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0xc6d5c ldr r1, [r7] */
/* @0xc6d60 mov r2, r10 */
/* @0xc6d64 mov r3, r8 */
/* @0xc6d68 str r8, [sp, #0x4] */
/* @0xc6d6c mvn r4, #0 */
/* @0xc6d70 str r8, [sp, #0x8] */
/* @0xc6d74 str r8, [sp, #0xc] */
/* @0xc6d78 str r8, [sp, #0x10] */
/* @0xc6d7c str r4, [sp] */
/* @0xc6d80 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xc6d84 bl 0x212e98 <_Z11IsBigEndianv> */
/* @0xc6d88 cmp r0, #0 */
/* @0xc6d8c bne 0xc6dc8 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0xc6d90 add sp, sp, #24 */
/* @0xc6d94 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc6d98 ldr r0, [pc, #0x70] */
/* @0xc6d9c mov r1, r5 */
/* @0xc6da0 add r0, pc, r0 */
/* @0xc6da4 add sp, sp, #24 */
/* @0xc6da8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc6dac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6db0 ldr r0, [pc, #0x5c] */
/* @0xc6db4 mov r1, #0 */
/* @0xc6db8 add r0, pc, r0 */
/* @0xc6dbc add sp, sp, #24 */
/* @0xc6dc0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc6dc4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6dc8 ldr r1, [r5, #0xc] */
/* @0xc6dcc mov r0, r9 */
/* @0xc6dd0 ldr r2, [r7, #0x1c] */
/* @0xc6dd4 mov r3, r8 */
/* @0xc6dd8 stm sp, {r4, r8} */
/* @0xc6ddc bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib> */
/* @0xc6de0 b 0xc6d90 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0xc6de4 ldr r0, [pc, #0x2c] */
/* @0xc6de8 mov r1, r8 */
/* @0xc6dec add r0, pc, r0 */
/* @0xc6df0 add sp, sp, #24 */
/* @0xc6df4 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc6df8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6dfc ldr r0, [pc, #0x18] */
/* @0xc6e00 mov r1, r7 */
/* @0xc6e04 add r0, pc, r0 */
/* @0xc6e08 b 0xc6da4 <_Z34F_BUFFER_Create_From_Vertex_BufferR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0xc6e0c .word 0x0026a4b0 */
/* @0xc6e10 .word 0x0026a4b8 */
/* @0xc6e14 eoreq r10, r6, r4, lsl r4 */
/* @0xc6e18 eoreq r10, r6, r0, lsr r4 */
/* @0xc6e1c eoreq r10, r6, r8, lsr #6 */

/* ── FUNC 0xc6e20 · F_BUFFER_Create_From_Vertex_Buffer_Ext(RValue&, CInstance*, CInstance*, int, RValue*) · size=580 · insn=145 */
/* @0xc6e20 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc6e24 sub sp, sp, #28 */
/* @0xc6e28 mov r4, #0 */
/* @0xc6e2c mov r6, r0 */
/* @0xc6e30 ldr r5, [sp, #0x40] */
/* @0xc6e34 mov r1, r4 */
/* @0xc6e38 str r4, [r0, #0xc] */
/* @0xc6e3c mov r3, r4 */
/* @0xc6e40 str r4, [r0] */
/* @0xc6e44 movt r3, #0xbff0 */
/* @0xc6e48 str r3, [r0, #0x4] */
/* @0xc6e4c mov r0, r5 */
/* @0xc6e50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6e54 bl 0xc8860 <_Z15GetBufferVertexi> */
/* @0xc6e58 subs r7, r0, #0 */
/* @0xc6e5c beq 0xc7004 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0xc6e60 ldrb r8, [r7, #0x20] */
/* @0xc6e64 mov r1, r4 */
/* @0xc6e68 ldr r0, [pc, #0x1d4] */
/* @0xc6e6c cmp r8, #0 */
/* @0xc6e70 add r0, pc, r0 */
/* @0xc6e74 bne 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc6e78 ldr r3, [r7, #0x1c] */
/* @0xc6e7c cmp r3, #0 */
/* @0xc6e80 beq 0xc6ed8 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc6e84 ldr r3, [r7, #0x28] */
/* @0xc6e88 cmn r3, #1 */
/* @0xc6e8c beq 0xc6ed8 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0xc6e90 mov r0, r5 */
/* @0xc6e94 mov r1, #2 */
/* @0xc6e98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6e9c vmov.f32 s15, #1.000000e+00 */
/* @0xc6ea0 vmov s13, r0 */
/* @0xc6ea4 mov r4, r0 */
/* @0xc6ea8 vcvt.f32.s32 s14, s13 */
/* @0xc6eac vcmpe.f32 s14, s15 */
/* @0xc6eb0 vmrs APSR_nzcv, fpscr */
/* @0xc6eb4 bmi 0xc6ec0 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0xc6eb8 cmp r0, #1024 */
/* @0xc6ebc ble 0xc6ef0 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0xc6ec0 ldr r0, [pc, #0x180] */
/* @0xc6ec4 mov r1, #0 */
/* @0xc6ec8 add r0, pc, r0 */
/* @0xc6ecc add sp, sp, #28 */
/* @0xc6ed0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc6ed4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6ed8 ldr r0, [pc, #0x16c] */
/* @0xc6edc mov r1, #0 */
/* @0xc6ee0 add r0, pc, r0 */
/* @0xc6ee4 add sp, sp, #28 */
/* @0xc6ee8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc6eec b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc6ef0 mov r1, #3 */
/* @0xc6ef4 mov r0, r5 */
/* @0xc6ef8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6efc mov r1, #4 */
/* @0xc6f00 mov r9, r0 */
/* @0xc6f04 mov r0, r5 */
/* @0xc6f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6f0c subs r10, r0, #0 */
/* @0xc6f10 ble 0xc7014 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0xc6f14 cmp r9, #0 */
/* @0xc6f18 blt 0xc6fd4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0xc6f1c ldr r3, [r7, #0x1c] */
/* @0xc6f20 cmp r9, r3 */
/* @0xc6f24 bge 0xc6fd4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0xc6f28 add r2, r9, r10 */
/* @0xc6f2c ldr r0, [r7, #0x28] */
/* @0xc6f30 cmp r3, r2 */
/* @0xc6f34 rsblt r10, r9, r3 */
/* @0xc6f38 bl 0x1e2cd0 <_Z15GetVertexFormati> */
/* @0xc6f3c subs r8, r0, #0 */
/* @0xc6f40 beq 0xc7024 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0xc6f44 mov r0, r5 */
/* @0xc6f48 mov r1, #1 */
/* @0xc6f4c ldr r11, [r8, #0x14] */
/* @0xc6f50 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc6f54 mov r2, r4 */
/* @0xc6f58 mul r11, r11, r10 */
/* @0xc6f5c mov r1, r0 */
/* @0xc6f60 mov r0, r11 */
/* @0xc6f64 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0xc6f68 vmov s15, r0 */
/* @0xc6f6c vcvt.f64.s32 d7, s15 */
/* @0xc6f70 vmov r4, r5, d7 */
/* @0xc6f74 vmov r2, s14 */
/* @0xc6f78 mov r3, r5 */
/* @0xc6f7c stm r6, {r2, r3} */
/* @0xc6f80 bl 0xc6720 <_Z10GetIBufferi> */
/* @0xc6f84 subs r6, r0, #0 */
/* @0xc6f88 beq 0xc7034 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0xc6f8c ldr r12, [r8, #0x14] */
/* @0xc6f90 mov r4, #0 */
/* @0xc6f94 ldr r1, [r7] */
/* @0xc6f98 mov r2, r11 */
/* @0xc6f9c mov r3, r4 */
/* @0xc6fa0 str r4, [sp, #0x4] */
/* @0xc6fa4 str r4, [sp, #0x8] */
/* @0xc6fa8 mvn r5, #0 */
/* @0xc6fac mla r1, r12, r9, r1 */
/* @0xc6fb0 str r4, [sp, #0xc] */
/* @0xc6fb4 str r4, [sp, #0x10] */
/* @0xc6fb8 str r5, [sp] */
/* @0xc6fbc bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb> */
/* @0xc6fc0 bl 0x212e98 <_Z11IsBigEndianv> */
/* @0xc6fc4 cmp r0, r4 */
/* @0xc6fc8 bne 0xc6fe4 <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0xc6fcc add sp, sp, #28 */
/* @0xc6fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc6fd4 ldr r0, [pc, #0x74] */
/* @0xc6fd8 mov r1, #0 */
/* @0xc6fdc add r0, pc, r0 */
/* @0xc6fe0 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc6fe4 ldr r1, [r6, #0xc] */
/* @0xc6fe8 mov r0, r8 */
/* @0xc6fec str r5, [sp] */
/* @0xc6ff0 mov r2, r10 */
/* @0xc6ff4 str r4, [sp, #0x4] */
/* @0xc6ff8 mov r3, r4 */
/* @0xc6ffc bl 0x1e251c <_ZN12VertexFormat16EndianSwapBufferEPhiiib> */
/* @0xc7000 b 0xc6fcc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0xc7004 ldr r0, [pc, #0x48] */
/* @0xc7008 mov r1, r7 */
/* @0xc700c add r0, pc, r0 */
/* @0xc7010 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc7014 ldr r0, [pc, #0x3c] */
/* @0xc7018 mov r1, r8 */
/* @0xc701c add r0, pc, r0 */
/* @0xc7020 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc7024 ldr r0, [pc, #0x30] */
/* @0xc7028 mov r1, r8 */
/* @0xc702c add r0, pc, r0 */
/* @0xc7030 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc7034 ldr r0, [pc, #0x24] */
/* @0xc7038 mov r1, r6 */
/* @0xc703c add r0, pc, r0 */
/* @0xc7040 b 0xc6ecc <_Z38F_BUFFER_Create_From_Vertex_Buffer_ExtR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0xc7044 eoreq r10, r6, r8, ror r4 */
/* @0xc7048 eoreq r10, r6, r12, asr #9 */
/* @0xc704c eoreq r10, r6, r0, ror #8 */
/* @0xc7050 eoreq r10, r6, r4, asr #8 */
/* @0xc7054 eoreq r10, r6, r12, lsl #5 */
/* @0xc7058 .word 0x0026a3b8 */
/* @0xc705c eoreq r10, r6, r0, asr #8 */
/* @0xc7060 eoreq r10, r6, r12, lsl r2 */

/* ── FUNC 0xc7064 · YYGML_BUFFER_Write(int, int, YYRValue const&) · size=96 · insn=24 */
/* @0xc7064 cmp r0, #0 */
/* @0xc7068 push {r3, lr} */
/* @0xc706c blt 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40> */
/* @0xc7070 ldr r3, [pc, #0x44] */
/* @0xc7074 add r3, pc, r3 */
/* @0xc7078 ldr r12, [r3] */
/* @0xc707c cmp r0, r12 */
/* @0xc7080 bge 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40> */
/* @0xc7084 ldr r3, [r3, #0x4] */
/* @0xc7088 ldr r0, [r3, r0, lsl #2] */
/* @0xc708c cmp r0, #0 */
/* @0xc7090 beq 0xc70a4 <_Z18YYGML_BUFFER_WriteiiRK8YYRValue+0x40> */
/* @0xc7094 ldr r3, [r0] */
/* @0xc7098 ldr r3, [r3, #0x8] */
/* @0xc709c blx r3 */
/* @0xc70a0 pop {r3, pc} */
/* @0xc70a4 ldr r0, [pc, #0x14] */
/* @0xc70a8 mov r1, #0 */
/* @0xc70ac add r0, pc, r0 */
/* @0xc70b0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xc70b4 mvn r0, #0 */
/* @0xc70b8 pop {r3, pc} */
/* @0xc70bc eorseq r3, r11, r0, lsr #1 */
/* @0xc70c0 eoreq r9, r6, r8, lsl #22 */

/* ── FUNC 0xc70c4 · KickAsyncBuffer(bool, SAsyncBuffer*, char const*, bool) · size=464 · insn=116 */
/* @0xc70c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc70c8 mov r8, r0 */
/* @0xc70cc ldr r6, [pc, #0x194] */
/* @0xc70d0 sub sp, sp, #28 */
/* @0xc70d4 ldr r0, [pc, #0x190] */
/* @0xc70d8 mov r11, r3 */
/* @0xc70dc add r6, pc, r6 */
/* @0xc70e0 str r2, [sp, #0x14] */
/* @0xc70e4 mov r9, r1 */
/* @0xc70e8 ldr r3, [r6, r0] */
/* @0xc70ec ldr r2, [r3] */
/* @0xc70f0 cmp r2, #0 */
/* @0xc70f4 movne r2, #0 */
/* @0xc70f8 strne r2, [r3] */
/* @0xc70fc ldr r3, [pc, #0x16c] */
/* @0xc7100 ldr r3, [r6, r3] */
/* @0xc7104 ldr r2, [r3] */
/* @0xc7108 cmp r2, #0 */
/* @0xc710c movne r2, #0 */
/* @0xc7110 strne r2, [r3] */
/* @0xc7114 cmp r8, #0 */
/* @0xc7118 bne 0xc71a4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0xe0> */
/* @0xc711c cmp r1, #0 */
/* @0xc7120 ldr r3, [pc, #0x14c] */
/* @0xc7124 beq 0xc7224 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x160> */
/* @0xc7128 ldr r3, [r6, r3] */
/* @0xc712c mov r4, r1 */
/* @0xc7130 ldr r7, [pc, #0x140] */
/* @0xc7134 mov r10, r8 */
/* @0xc7138 add r7, pc, r7 */
/* @0xc713c ldr r5, [r3] */
/* @0xc7140 b 0xc7150 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x8c> */
/* @0xc7144 ldr r4, [r4] */
/* @0xc7148 cmp r4, #0 */
/* @0xc714c beq 0xc7230 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x16c> */
/* @0xc7150 ldr r3, [r5] */
/* @0xc7154 mov r0, r5 */
/* @0xc7158 mov r1, r7 */
/* @0xc715c ldr r2, [r4, #0x8] */
/* @0xc7160 add r10, r10, #1 */
/* @0xc7164 ldr r3, [r3, #0xc] */
/* @0xc7168 blx r3 */
/* @0xc716c ldr r0, [r4, #0x8] */
/* @0xc7170 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc7174 cmp r0, #0 */
/* @0xc7178 beq 0xc7144 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x80> */
/* @0xc717c ldr lr, [r5] */
/* @0xc7180 mov r0, r5 */
/* @0xc7184 ldr r1, [pc, #0xf0] */
/* @0xc7188 mov r2, r10 */
/* @0xc718c mov r3, #1 */
/* @0xc7190 add r1, pc, r1 */
/* @0xc7194 ldr r4, [lr, #0xc] */
/* @0xc7198 blx r4 */
/* @0xc719c cmp r10, #1 */
/* @0xc71a0 bne 0xc7254 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x190> */
/* @0xc71a4 mov r0, #92 */
/* @0xc71a8 mov r5, #0 */
/* @0xc71ac bl 0x27c524 <_Znwj> */
/* @0xc71b0 ldr r3, [pc, #0xc8] */
/* @0xc71b4 mov r2, r5 */
/* @0xc71b8 mov r1, r5 */
/* @0xc71bc ldr r3, [r6, r3] */
/* @0xc71c0 str r5, [sp] */
/* @0xc71c4 str r5, [sp, #0x4] */
/* @0xc71c8 str r5, [sp, #0x8] */
/* @0xc71cc mov r4, r0 */
/* @0xc71d0 bl 0x18d834 <_ZN16HTTP_REQ_CONTEXTC2EPKciPFiPS_PvPiEPFvS2_ES3_b> */
/* @0xc71d4 ldr r3, [pc, #0xa8] */
/* @0xc71d8 ldr r0, [sp, #0x14] */
/* @0xc71dc ldr r3, [r6, r3] */
/* @0xc71e0 str r9, [r4, #0x44] */
/* @0xc71e4 add r3, r3, #8 */
/* @0xc71e8 str r3, [r4] */
/* @0xc71ec bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc71f0 ldr r2, [pc, #0x90] */
/* @0xc71f4 mov r3, #1 */
/* @0xc71f8 strb r8, [r4, #0x4c] */
/* @0xc71fc str r3, [r4, #0x50] */
/* @0xc7200 str r5, [r4, #0x54] */
/* @0xc7204 strb r11, [r4, #0x58] */
/* @0xc7208 ldr r3, [r4, #0x24] */
/* @0xc720c str r0, [r4, #0x48] */
/* @0xc7210 ldr r2, [r6, r2] */
/* @0xc7214 str r2, [r4, #0x18] */
/* @0xc7218 mov r0, r3 */
/* @0xc721c add sp, sp, #28 */
/* @0xc7220 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc7224 ldr r3, [r6, r3] */
/* @0xc7228 mov r10, r1 */
/* @0xc722c ldr r5, [r3] */
/* @0xc7230 ldr lr, [r5] */
/* @0xc7234 mov r2, r10 */
/* @0xc7238 ldr r1, [pc, #0x4c] */
/* @0xc723c mov r0, r5 */
/* @0xc7240 mov r3, #0 */
/* @0xc7244 add r1, pc, r1 */
/* @0xc7248 ldr r12, [lr, #0xc] */
/* @0xc724c blx r12 */
/* @0xc7250 b 0xc71a4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0xe0> */
/* @0xc7254 ldr r0, [pc, #0x34] */
/* @0xc7258 add r0, pc, r0 */
/* @0xc725c bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xc7260 mvn r3, #0 */
/* @0xc7264 b 0xc7218 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb+0x154> */
/* @0xc7268 eorseq r10, r2, r4, ror r11 */
/* @0xc726c .word 0xffffbd88 */
/* @0xc7270 .word 0xffffbd8c */
/* @0xc7274 .word 0xffffbac4 */
/* @0xc7278 eoreq r10, r6, r4, ror r3 */
/* @0xc727c eoreq r10, r6, r4, lsr r3 */
/* @0xc7280 .word 0xffffbd90 */
/* @0xc7284 .word 0xffffbd64 */
/* @0xc7288 .word 0xffffbd94 */
/* @0xc728c eoreq r10, r6, r0, lsl #5 */
/* @0xc7290 mlaeq r6, r4, r2, r10 */

/* ── FUNC 0xc7294 · F_BUFFER_Save_Async(RValue&, CInstance*, CInstance*, int, RValue*) · size=352 · insn=88 */
/* @0xc7294 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc7298 mov r3, #0 */
/* @0xc729c ldr r4, [sp, #0x20] */
/* @0xc72a0 mov r6, r0 */
/* @0xc72a4 mov r5, r3 */
/* @0xc72a8 mov r1, #1 */
/* @0xc72ac movt r3, #0xbff0 */
/* @0xc72b0 str r5, [r0] */
/* @0xc72b4 str r3, [r0, #0x4] */
/* @0xc72b8 mov r0, r4 */
/* @0xc72bc str r5, [r6, #0xc] */
/* @0xc72c0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xc72c4 mov r1, r5 */
/* @0xc72c8 mov r9, r0 */
/* @0xc72cc mov r0, r4 */
/* @0xc72d0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc72d4 mov r1, #2 */
/* @0xc72d8 mov r10, r0 */
/* @0xc72dc mov r0, r4 */
/* @0xc72e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc72e4 mov r1, #3 */
/* @0xc72e8 mov r8, r0 */
/* @0xc72ec mov r0, r4 */
/* @0xc72f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xc72f4 ldr r3, [pc, #0xdc] */
/* @0xc72f8 ldr r3, [pc, r3] */
/* @0xc72fc ldr r3, [r3] */
/* @0xc7300 cmp r3, r5 */
/* @0xc7304 mov r7, r0 */
/* @0xc7308 beq 0xc7318 <_Z19F_BUFFER_Save_AsyncR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xc730c ldr r0, [pc, #0xc8] */
/* @0xc7310 add r0, pc, r0 */
/* @0xc7314 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0xc7318 mov r0, #24 */
/* @0xc731c ldr r5, [pc, #0xbc] */
/* @0xc7320 bl 0x27c524 <_Znwj> */
/* @0xc7324 ldr r5, [pc, r5] */
/* @0xc7328 ldr r3, [r5] */
/* @0xc732c mov r4, r0 */
/* @0xc7330 mov r0, r9 */
/* @0xc7334 str r3, [r4] */
/* @0xc7338 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0xc733c ldr r1, [pc, #0xa0] */
/* @0xc7340 movw r2, #0x241 */
/* @0xc7344 mov r3, #1 */
/* @0xc7348 add r1, pc, r1 */
/* @0xc734c str r0, [r4, #0x8] */
/* @0xc7350 mov r0, r7 */
/* @0xc7354 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc7358 ldr r3, [pc, #0x88] */
/* @0xc735c str r7, [r4, #0x10] */
/* @0xc7360 mov r2, r7 */
/* @0xc7364 add r3, pc, r3 */
/* @0xc7368 str r8, [r4, #0x14] */
/* @0xc736c ldr r3, [r3, #0x4] */
/* @0xc7370 str r0, [r4, #0xc] */
/* @0xc7374 ldr r3, [r3, r10, lsl #2] */
/* @0xc7378 ldr r1, [r3, #0xc] */
/* @0xc737c add r1, r1, r8 */
/* @0xc7380 bl 0xb65bc <memcpy@plt> */
/* @0xc7384 ldr r3, [pc, #0x60] */
/* @0xc7388 str r4, [r5] */
/* @0xc738c ldr r3, [pc, r3] */
/* @0xc7390 ldr r7, [r3] */
/* @0xc7394 cmp r7, #0 */
/* @0xc7398 popne {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc739c ldr r2, [pc, #0x4c] */
/* @0xc73a0 mov r1, r4 */
/* @0xc73a4 mov r3, r7 */
/* @0xc73a8 str r7, [r6, #0xc] */
/* @0xc73ac add r2, pc, r2 */
/* @0xc73b0 mov r0, #1 */
/* @0xc73b4 bl 0xc70c4 <_Z15KickAsyncBufferbP12SAsyncBufferPKcb> */
/* @0xc73b8 vmov s15, r0 */
/* @0xc73bc vcvt.f64.s32 d7, s15 */
/* @0xc73c0 vmov r0, r1, d7 */
/* @0xc73c4 vmov r2, s14 */
/* @0xc73c8 mov r3, r1 */
/* @0xc73cc stm r6, {r2, r3} */
/* @0xc73d0 str r7, [r5] */
/* @0xc73d4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc73d8 eorseq r6, r2, r4, ror #13 */
/* @0xc73dc eoreq r10, r6, r12, lsl r2 */
/* @0xc73e0 ldrhteq r6, [r2], -r4 */
/* @0xc73e4 eoreq r10, r6, r4, lsl r2 */
/* @0xc73e8 ldrhteq r2, [r11], -r0 */
/* @0xc73ec eorseq r6, r2, r12, lsr #12 */
/* @0xc73f0 eoreq r10, r6, r12, ror #3 */
