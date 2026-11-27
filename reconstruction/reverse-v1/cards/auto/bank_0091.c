/* libyoyo.so 覆盖卡组 0091
 * 函数 0x15797c..0x158e28，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x15797c · F_YoYo_GetGUIHeight(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x15797c ldr r3, [pc, #0x44] */
/* @0x157980 push {r4, lr} */
/* @0x157984 ldr r3, [pc, r3] */
/* @0x157988 mov r4, r0 */
/* @0x15798c ldr r0, [r3] */
/* @0x157990 vmov s15, r0 */
/* @0x157994 vcvt.f64.s32 d7, s15 */
/* @0x157998 vcmpe.f64 d7, #0 */
/* @0x15799c vmov r0, r1, d7 */
/* @0x1579a0 vmrs APSR_nzcv, fpscr */
/* @0x1579a4 bmi 0x1579c0 <_Z19F_YoYo_GetGUIHeightR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x1579a8 mov r3, #0 */
/* @0x1579ac mov r2, r0 */
/* @0x1579b0 str r3, [r4, #0xc] */
/* @0x1579b4 mov r3, r1 */
/* @0x1579b8 stm r4, {r2, r3} */
/* @0x1579bc pop {r4, pc} */
/* @0x1579c0 bl 0x15e62c <_Z17GetBrowserHeightMv> */
/* @0x1579c4 b 0x1579a8 <_Z19F_YoYo_GetGUIHeightR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x1579c8 .word 0x002981f0 */

/* ── FUNC 0x1579cc · GET_YoYo_GetBrowserHeight(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1579cc push {r4, lr} */
/* @0x1579d0 mov r3, #0 */
/* @0x1579d4 str r3, [r2, #0xc] */
/* @0x1579d8 mov r4, r2 */
/* @0x1579dc bl 0x15e62c <_Z17GetBrowserHeightMv> */
/* @0x1579e0 str r0, [r4] */
/* @0x1579e4 mov r0, #1 */
/* @0x1579e8 str r1, [r4, #0x4] */
/* @0x1579ec pop {r4, pc} */

/* ── FUNC 0x1579f0 · F_YoYo_Base64Encode(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0x1579f0 push {r4, r5, r6, r7, r8, r11, lr} */
/* @0x1579f4 add r11, sp, #24 */
/* @0x1579f8 ldr r4, [pc, #0x90] */
/* @0x1579fc sub sp, sp, #12 */
/* @0x157a00 mov r1, #0 */
/* @0x157a04 ldr r4, [pc, r4] */
/* @0x157a08 mov r7, r0 */
/* @0x157a0c ldr r0, [r11, #0x4] */
/* @0x157a10 ldr r3, [r4] */
/* @0x157a14 str r3, [r11, #-0x20] */
/* @0x157a18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157a1c mov r8, r0 */
/* @0x157a20 bl 0xb6538 <strlen@plt> */
/* @0x157a24 movw r2, #0x5556 */
/* @0x157a28 movt r2, #0x5555 */
/* @0x157a2c mov r1, #0 */
/* @0x157a30 lsl r3, r0, #2 */
/* @0x157a34 mov r6, r0 */
/* @0x157a38 smull r0, r2, r2, r3 */
/* @0x157a3c sub r2, r2, r3, asr #31 */
/* @0x157a40 add r3, r2, #18 */
/* @0x157a44 add r2, r2, #4 */
/* @0x157a48 bic r3, r3, #7 */
/* @0x157a4c sub sp, sp, r3 */
/* @0x157a50 mov r0, sp */
/* @0x157a54 bl 0xb65b0 <memset@plt> */
/* @0x157a58 mov r2, sp */
/* @0x157a5c mov r0, r8 */
/* @0x157a60 mov r1, r6 */
/* @0x157a64 bl 0x1d1e60 <_Z13base64_encodePKcjPc> */
/* @0x157a68 mov r0, r7 */
/* @0x157a6c mov r1, sp */
/* @0x157a70 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x157a74 ldr r2, [r11, #-0x20] */
/* @0x157a78 ldr r3, [r4] */
/* @0x157a7c cmp r2, r3 */
/* @0x157a80 bne 0x157a8c <_Z19F_YoYo_Base64EncodeR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x157a84 sub sp, r11, #24 */
/* @0x157a88 pop {r4, r5, r6, r7, r8, r11, pc} */
/* @0x157a8c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157a90 eoreq r5, r9, r12, asr #30 */

/* ── FUNC 0x157a94 · F_YoYo_Base64Decode(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x157a94 push {r4, r5, r6, r11, lr} */
/* @0x157a98 add r11, sp, #16 */
/* @0x157a9c ldr r4, [pc, #0x80] */
/* @0x157aa0 sub sp, sp, #12 */
/* @0x157aa4 mov r1, #0 */
/* @0x157aa8 ldr r4, [pc, r4] */
/* @0x157aac mov r6, r0 */
/* @0x157ab0 ldr r0, [r11, #0x4] */
/* @0x157ab4 ldr r3, [r4] */
/* @0x157ab8 str r3, [r11, #-0x18] */
/* @0x157abc bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157ac0 mov r5, r0 */
/* @0x157ac4 bl 0xb6538 <strlen@plt> */
/* @0x157ac8 mov r3, #1 */
/* @0x157acc add r2, r0, r0, lsl #1 */
/* @0x157ad0 mov r0, r5 */
/* @0x157ad4 cmp r2, #0 */
/* @0x157ad8 add r1, r2, #3 */
/* @0x157adc movlt r2, r1 */
/* @0x157ae0 asr r1, r2, #2 */
/* @0x157ae4 add r2, r1, #18 */
/* @0x157ae8 add r1, r1, #4 */
/* @0x157aec bic r2, r2, #7 */
/* @0x157af0 sub sp, sp, r2 */
/* @0x157af4 mov r2, sp */
/* @0x157af8 bl 0x1d1ff0 <_Z13base64_decodePKcjPcb> */
/* @0x157afc mov r0, r6 */
/* @0x157b00 mov r1, sp */
/* @0x157b04 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x157b08 ldr r2, [r11, #-0x18] */
/* @0x157b0c ldr r3, [r4] */
/* @0x157b10 cmp r2, r3 */
/* @0x157b14 bne 0x157b20 <_Z19F_YoYo_Base64DecodeR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x157b18 sub sp, r11, #16 */
/* @0x157b1c pop {r4, r5, r6, r11, pc} */
/* @0x157b20 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157b24 eoreq r5, r9, r8, lsr #29 */

/* ── FUNC 0x157b28 · F_YoYo_MD5Unicode(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x157b28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x157b2c add r11, sp, #32 */
/* @0x157b30 ldr r8, [pc, #0x110] */
/* @0x157b34 sub sp, sp, #116 */
/* @0x157b38 mov r1, #0 */
/* @0x157b3c ldr r8, [pc, r8] */
/* @0x157b40 mov r9, r0 */
/* @0x157b44 ldr r0, [r11, #0x4] */
/* @0x157b48 ldr r3, [r8] */
/* @0x157b4c str r3, [r11, #-0x28] */
/* @0x157b50 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157b54 mov r4, r0 */
/* @0x157b58 bl 0xb6538 <strlen@plt> */
/* @0x157b5c str r4, [r11, #-0x94] */
/* @0x157b60 lsl r3, r0, #1 */
/* @0x157b64 cmp r0, #0 */
/* @0x157b68 add r3, r3, #16 */
/* @0x157b6c lsl r6, r0, #1 */
/* @0x157b70 bic r3, r3, #7 */
/* @0x157b74 subgt r7, r11, #148 */
/* @0x157b78 sub sp, sp, r3 */
/* @0x157b7c movgt r4, #0 */
/* @0x157b80 mov r5, sp */
/* @0x157b84 ble 0x157ba0 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x157b88 mov r0, r7 */
/* @0x157b8c bl 0x10fb38 <utf8_extract_char> */
/* @0x157b90 strh r0, [r5, r4] */
/* @0x157b94 add r4, r4, #2 */
/* @0x157b98 cmp r4, r6 */
/* @0x157b9c bne 0x157b88 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x157ba0 sub r10, r11, #144 */
/* @0x157ba4 mov r3, #0 */
/* @0x157ba8 strh r3, [r5, r6] */
/* @0x157bac sub r4, r11, #57 */
/* @0x157bb0 mov r0, r10 */
/* @0x157bb4 sub r7, r11, #41 */
/* @0x157bb8 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0x157bbc mov r1, r5 */
/* @0x157bc0 mov r2, r6 */
/* @0x157bc4 mov r0, r10 */
/* @0x157bc8 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x157bcc mov r0, r10 */
/* @0x157bd0 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0x157bd4 ldr r1, [pc, #0x70] */
/* @0x157bd8 mov r0, #33 */
/* @0x157bdc movw r2, #0x977 */
/* @0x157be0 add r1, pc, r1 */
/* @0x157be4 mov r3, #1 */
/* @0x157be8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x157bec ldr r6, [pc, #0x5c] */
/* @0x157bf0 add r6, pc, r6 */
/* @0x157bf4 mov r10, r0 */
/* @0x157bf8 mov r5, r0 */
/* @0x157bfc ldrb r2, [r4, #0x1]! */
/* @0x157c00 mov r0, r5 */
/* @0x157c04 mov r1, r6 */
/* @0x157c08 add r5, r5, #2 */
/* @0x157c0c bl 0xb6550 <sprintf@plt> */
/* @0x157c10 cmp r4, r7 */
/* @0x157c14 bne 0x157bfc <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x157c18 mov r0, r9 */
/* @0x157c1c mov r1, r10 */
/* @0x157c20 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x157c24 mov r0, r10 */
/* @0x157c28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x157c2c ldr r2, [r11, #-0x28] */
/* @0x157c30 ldr r3, [r8] */
/* @0x157c34 cmp r2, r3 */
/* @0x157c38 bne 0x157c44 <_Z17F_YoYo_MD5UnicodeR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x157c3c sub sp, r11, #32 */
/* @0x157c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x157c44 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157c48 eoreq r5, r9, r4, lsl lr */
/* @0x157c4c andseq lr, lr, r4, lsl #19 */
/* @0x157c50 ldrheq r10, [sp], -r4 */

/* ── FUNC 0x157c54 · F_YoYo_MD5Utf8(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x157c54 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x157c58 sub sp, sp, #112 */
/* @0x157c5c ldr r8, [pc, #0xc8] */
/* @0x157c60 mov r1, #0 */
/* @0x157c64 ldr r2, [sp, #0x90] */
/* @0x157c68 mov r10, r0 */
/* @0x157c6c ldr r8, [pc, r8] */
/* @0x157c70 add r5, sp, #4 */
/* @0x157c74 ldr r7, [pc, #0xb4] */
/* @0x157c78 add r4, sp, #91 */
/* @0x157c7c ldr r3, [r8] */
/* @0x157c80 mov r0, r2 */
/* @0x157c84 add r7, pc, r7 */
/* @0x157c88 add r6, sp, #107 */
/* @0x157c8c str r3, [sp, #0x6c] */
/* @0x157c90 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157c94 mov r9, r0 */
/* @0x157c98 mov r0, r5 */
/* @0x157c9c bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0x157ca0 mov r0, r9 */
/* @0x157ca4 bl 0xb6538 <strlen@plt> */
/* @0x157ca8 mov r1, r9 */
/* @0x157cac mov r2, r0 */
/* @0x157cb0 mov r0, r5 */
/* @0x157cb4 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x157cb8 mov r0, r5 */
/* @0x157cbc bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0x157cc0 ldr r1, [pc, #0x6c] */
/* @0x157cc4 mov r0, #33 */
/* @0x157cc8 movw r2, #0x989 */
/* @0x157ccc add r1, pc, r1 */
/* @0x157cd0 mov r3, #1 */
/* @0x157cd4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x157cd8 mov r9, r0 */
/* @0x157cdc mov r5, r0 */
/* @0x157ce0 ldrb r2, [r4, #0x1]! */
/* @0x157ce4 mov r0, r5 */
/* @0x157ce8 mov r1, r7 */
/* @0x157cec add r5, r5, #2 */
/* @0x157cf0 bl 0xb6550 <sprintf@plt> */
/* @0x157cf4 cmp r4, r6 */
/* @0x157cf8 bne 0x157ce0 <_Z14F_YoYo_MD5Utf8R6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x157cfc mov r0, r10 */
/* @0x157d00 mov r1, r9 */
/* @0x157d04 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x157d08 mov r0, r9 */
/* @0x157d0c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x157d10 ldr r2, [sp, #0x6c] */
/* @0x157d14 ldr r3, [r8] */
/* @0x157d18 cmp r2, r3 */
/* @0x157d1c bne 0x157d28 <_Z14F_YoYo_MD5Utf8R6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x157d20 add sp, sp, #112 */
/* @0x157d24 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x157d28 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157d2c eoreq r5, r9, r4, ror #25 */
/* @0x157d30 andseq r10, sp, r0, lsr #10 */
/* @0x157d34 mulseq lr, r8, r8 */

/* ── FUNC 0x157d38 · F_YoYo_MD5File(RValue&, CInstance*, CInstance*, int, RValue*) · size=484 · insn=121 */
/* @0x157d38 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x157d3c sub sp, sp, #2160 */
/* @0x157d40 ldr r8, [pc, #0x1c0] */
/* @0x157d44 sub sp, sp, #4 */
/* @0x157d48 mov r1, #0 */
/* @0x157d4c mov r9, r0 */
/* @0x157d50 ldr r8, [pc, r8] */
/* @0x157d54 ldr r0, [sp, #0x898] */
/* @0x157d58 ldr r3, [r8] */
/* @0x157d5c str r3, [sp, #0x86c] */
/* @0x157d60 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157d64 mov r4, r0 */
/* @0x157d68 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x157d6c mov r6, r0 */
/* @0x157d70 mov r0, r4 */
/* @0x157d74 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x157d78 orr r1, r0, r6 */
/* @0x157d7c mov r5, r0 */
/* @0x157d80 ands r10, r1, #255 */
/* @0x157d84 bne 0x157db0 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x157d88 mov r0, r9 */
/* @0x157d8c mov r1, r10 */
/* @0x157d90 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x157d94 ldr r2, [sp, #0x86c] */
/* @0x157d98 ldr r3, [r8] */
/* @0x157d9c cmp r2, r3 */
/* @0x157da0 bne 0x157f04 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x157da4 add sp, sp, #2160 */
/* @0x157da8 add sp, sp, #4 */
/* @0x157dac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x157db0 add r6, sp, #16 */
/* @0x157db4 sub r10, r6, #12 */
/* @0x157db8 mov r0, r10 */
/* @0x157dbc bl 0x2140d8 <_Z7MD5InitP7MD5_CTX> */
/* @0x157dc0 cmp r5, #0 */
/* @0x157dc4 mov r2, r4 */
/* @0x157dc8 beq 0x157e6c <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x157dcc add r7, sp, #108 */
/* @0x157dd0 mov r1, #2048 */
/* @0x157dd4 mov r0, r7 */
/* @0x157dd8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x157ddc ldr r1, [pc, #0x128] */
/* @0x157de0 mov r0, r7 */
/* @0x157de4 add r1, pc, r1 */
/* @0x157de8 bl 0xb6844 <fopen@plt> */
/* @0x157dec mov r1, #0 */
/* @0x157df0 mov r2, #2 */
/* @0x157df4 mov r11, r0 */
/* @0x157df8 bl 0xb68d4 <fseek@plt> */
/* @0x157dfc mov r0, r11 */
/* @0x157e00 bl 0xb68e0 <ftell@plt> */
/* @0x157e04 mov r1, #0 */
/* @0x157e08 mov r2, r1 */
/* @0x157e0c mov r4, r0 */
/* @0x157e10 mov r0, r11 */
/* @0x157e14 bl 0xb68d4 <fseek@plt> */
/* @0x157e18 cmp r4, #0 */
/* @0x157e1c bne 0x157e3c <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x157e20 b 0x157e60 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x157e24 mov r0, r10 */
/* @0x157e28 mov r1, r7 */
/* @0x157e2c mov r2, r5 */
/* @0x157e30 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x157e34 subs r4, r4, r5 */
/* @0x157e38 beq 0x157e60 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x157e3c cmp r4, #2048 */
/* @0x157e40 movlo r2, r4 */
/* @0x157e44 movhs r2, #2048 */
/* @0x157e48 mov r0, r7 */
/* @0x157e4c mov r1, #1 */
/* @0x157e50 mov r3, r11 */
/* @0x157e54 bl 0xb68c8 <fread@plt> */
/* @0x157e58 subs r5, r0, #0 */
/* @0x157e5c bne 0x157e24 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x157e60 mov r0, r11 */
/* @0x157e64 bl 0xb6850 <fclose@plt> */
/* @0x157e68 b 0x157eac <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x157e6c add r4, sp, #108 */
/* @0x157e70 mov r1, #2048 */
/* @0x157e74 mov r0, r4 */
/* @0x157e78 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x157e7c ldr r1, [pc, #0x8c] */
/* @0x157e80 mov r0, r4 */
/* @0x157e84 add r1, pc, r1 */
/* @0x157e88 bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x157e8c ldr r3, [r0] */
/* @0x157e90 mov r4, r0 */
/* @0x157e94 mov r0, r10 */
/* @0x157e98 ldr r1, [r3, #0xc] */
/* @0x157e9c ldr r2, [r3, #0x10] */
/* @0x157ea0 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj> */
/* @0x157ea4 mov r0, r4 */
/* @0x157ea8 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x157eac mov r0, r10 */
/* @0x157eb0 ldr r7, [pc, #0x5c] */
/* @0x157eb4 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX> */
/* @0x157eb8 ldr r1, [pc, #0x58] */
/* @0x157ebc mov r0, #33 */
/* @0x157ec0 movw r2, #0x9c4 */
/* @0x157ec4 add r1, pc, r1 */
/* @0x157ec8 mov r3, #1 */
/* @0x157ecc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x157ed0 add r4, r6, #75 */
/* @0x157ed4 add r7, pc, r7 */
/* @0x157ed8 add r6, r6, #91 */
/* @0x157edc mov r10, r0 */
/* @0x157ee0 mov r5, r0 */
/* @0x157ee4 ldrb r2, [r4, #0x1]! */
/* @0x157ee8 mov r0, r5 */
/* @0x157eec mov r1, r7 */
/* @0x157ef0 add r5, r5, #2 */
/* @0x157ef4 bl 0xb6550 <sprintf@plt> */
/* @0x157ef8 cmp r4, r6 */
/* @0x157efc bne 0x157ee4 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x157f00 b 0x157d88 <_Z14F_YoYo_MD5FileR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x157f04 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x157f08 eoreq r5, r9, r0, lsl #24 */
/* @0x157f0c andseq pc, sp, r4, lsl lr */
/* @0x157f10 andseq pc, sp, r4, ror sp */
/* @0x157f14 ldrsbeq r10, [sp], -r0 */
/* @0x157f18 andseq lr, lr, r0, lsr #13 */

/* ── FUNC 0x157f1c · F_YoYo_IsNetworkConnected(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x157f1c push {r3, r4, r5, lr} */
/* @0x157f20 mov r5, #0 */
/* @0x157f24 str r5, [r0, #0xc] */
/* @0x157f28 mov r4, r0 */
/* @0x157f2c bl 0x15f26c <_Z21GetIsNetworkConnectedv> */
/* @0x157f30 cmp r0, #0 */
/* @0x157f34 movne r0, r5 */
/* @0x157f38 moveq r3, r0 */
/* @0x157f3c movne r3, r0 */
/* @0x157f40 movtne r3, #0x3ff0 */
/* @0x157f44 stm r4, {r0, r3} */
/* @0x157f48 pop {r3, r4, r5, pc} */

/* ── FUNC 0x157f4c · F_YoYo_SHA1Unicode(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x157f4c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x157f50 add r11, sp, #32 */
/* @0x157f54 ldr r7, [pc, #0x110] */
/* @0x157f58 sub sp, sp, #116 */
/* @0x157f5c mov r1, #0 */
/* @0x157f60 ldr r7, [pc, r7] */
/* @0x157f64 mov r8, r0 */
/* @0x157f68 ldr r0, [r11, #0x4] */
/* @0x157f6c sub r9, r11, #148 */
/* @0x157f70 ldr r3, [r7] */
/* @0x157f74 str r3, [r11, #-0x28] */
/* @0x157f78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x157f7c mov r4, r0 */
/* @0x157f80 bl 0xb6538 <strlen@plt> */
/* @0x157f84 str r4, [r11, #-0x94] */
/* @0x157f88 lsl r3, r0, #1 */
/* @0x157f8c cmp r0, #0 */
/* @0x157f90 add r3, r3, #16 */
/* @0x157f94 lsl r6, r0, #1 */
/* @0x157f98 bic r3, r3, #7 */
/* @0x157f9c movgt r4, #0 */
/* @0x157fa0 sub sp, sp, r3 */
/* @0x157fa4 mov r5, sp */
/* @0x157fa8 ble 0x157fc4 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x157fac mov r0, r9 */
/* @0x157fb0 bl 0x10fb38 <utf8_extract_char> */
/* @0x157fb4 strh r0, [r5, r4] */
/* @0x157fb8 add r4, r4, #2 */
/* @0x157fbc cmp r4, r6 */
/* @0x157fc0 bne 0x157fac <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x157fc4 sub r10, r11, #144 */
/* @0x157fc8 mov r3, #0 */
/* @0x157fcc strh r3, [r5, r6] */
/* @0x157fd0 mov r4, r9 */
/* @0x157fd4 mov r0, r10 */
/* @0x157fd8 sub r9, r11, #128 */
/* @0x157fdc bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0x157fe0 mov r1, r5 */
/* @0x157fe4 mov r2, r6 */
/* @0x157fe8 mov r0, r10 */
/* @0x157fec bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0x157ff0 mov r0, r10 */
/* @0x157ff4 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0x157ff8 ldr r1, [pc, #0x70] */
/* @0x157ffc mov r0, #45 */
/* @0x158000 movw r2, #0x9e7 */
/* @0x158004 add r1, pc, r1 */
/* @0x158008 mov r3, #1 */
/* @0x15800c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x158010 ldr r6, [pc, #0x5c] */
/* @0x158014 add r6, pc, r6 */
/* @0x158018 mov r10, r0 */
/* @0x15801c mov r5, r0 */
/* @0x158020 ldr r2, [r4, #0x4]! */
/* @0x158024 mov r0, r5 */
/* @0x158028 mov r1, r6 */
/* @0x15802c add r5, r5, #8 */
/* @0x158030 bl 0xb6550 <sprintf@plt> */
/* @0x158034 cmp r4, r9 */
/* @0x158038 bne 0x158020 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x15803c mov r0, r8 */
/* @0x158040 mov r1, r10 */
/* @0x158044 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x158048 mov r0, r10 */
/* @0x15804c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x158050 ldr r2, [r11, #-0x28] */
/* @0x158054 ldr r3, [r7] */
/* @0x158058 cmp r2, r3 */
/* @0x15805c bne 0x158068 <_Z18F_YoYo_SHA1UnicodeR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x158060 sub sp, r11, #32 */
/* @0x158064 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x158068 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15806c .word 0x002959f0 */
/* @0x158070 andseq lr, lr, r0, ror #10 */
/* @0x158074 mulseq sp, r8, r1 */

/* ── FUNC 0x158078 · F_YoYo_SHA1Utf8(RValue&, CInstance*, CInstance*, int, RValue*) · size=228 · insn=57 */
/* @0x158078 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x15807c sub sp, sp, #112 */
/* @0x158080 ldr r8, [pc, #0xc8] */
/* @0x158084 mov r1, #0 */
/* @0x158088 ldr r2, [sp, #0x90] */
/* @0x15808c mov r10, r0 */
/* @0x158090 ldr r8, [pc, r8] */
/* @0x158094 add r5, sp, #4 */
/* @0x158098 ldr r7, [pc, #0xb4] */
/* @0x15809c add r6, sp, #20 */
/* @0x1580a0 ldr r3, [r8] */
/* @0x1580a4 mov r0, r2 */
/* @0x1580a8 add r7, pc, r7 */
/* @0x1580ac mov r4, sp */
/* @0x1580b0 str r3, [sp, #0x6c] */
/* @0x1580b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1580b8 mov r9, r0 */
/* @0x1580bc mov r0, r5 */
/* @0x1580c0 bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0x1580c4 mov r0, r9 */
/* @0x1580c8 bl 0xb6538 <strlen@plt> */
/* @0x1580cc mov r1, r9 */
/* @0x1580d0 mov r2, r0 */
/* @0x1580d4 mov r0, r5 */
/* @0x1580d8 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0x1580dc mov r0, r5 */
/* @0x1580e0 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0x1580e4 ldr r1, [pc, #0x6c] */
/* @0x1580e8 mov r0, #45 */
/* @0x1580ec movw r2, #0x9f9 */
/* @0x1580f0 add r1, pc, r1 */
/* @0x1580f4 mov r3, #1 */
/* @0x1580f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1580fc mov r9, r0 */
/* @0x158100 mov r5, r0 */
/* @0x158104 ldr r2, [r4, #0x4]! */
/* @0x158108 mov r0, r5 */
/* @0x15810c mov r1, r7 */
/* @0x158110 add r5, r5, #8 */
/* @0x158114 bl 0xb6550 <sprintf@plt> */
/* @0x158118 cmp r4, r6 */
/* @0x15811c bne 0x158104 <_Z15F_YoYo_SHA1Utf8R6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x158120 mov r0, r10 */
/* @0x158124 mov r1, r9 */
/* @0x158128 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x15812c mov r0, r9 */
/* @0x158130 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x158134 ldr r2, [sp, #0x6c] */
/* @0x158138 ldr r3, [r8] */
/* @0x15813c cmp r2, r3 */
/* @0x158140 bne 0x15814c <_Z15F_YoYo_SHA1Utf8R6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x158144 add sp, sp, #112 */
/* @0x158148 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x15814c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x158150 eoreq r5, r9, r0, asr #17 */
/* @0x158154 andseq r10, sp, r4, lsl #2 */
/* @0x158158 andseq lr, lr, r4, ror r4 */

/* ── FUNC 0x15815c · F_YoYo_SHA1File(RValue&, CInstance*, CInstance*, int, RValue*) · size=484 · insn=121 */
/* @0x15815c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x158160 sub sp, sp, #2160 */
/* @0x158164 ldr r6, [pc, #0x1c0] */
/* @0x158168 sub sp, sp, #4 */
/* @0x15816c mov r1, #0 */
/* @0x158170 mov r9, r0 */
/* @0x158174 ldr r6, [pc, r6] */
/* @0x158178 ldr r0, [sp, #0x898] */
/* @0x15817c ldr r3, [r6] */
/* @0x158180 str r3, [sp, #0x86c] */
/* @0x158184 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158188 mov r4, r0 */
/* @0x15818c bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x158190 mov r7, r0 */
/* @0x158194 mov r0, r4 */
/* @0x158198 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x15819c orr r1, r0, r7 */
/* @0x1581a0 mov r5, r0 */
/* @0x1581a4 ands r7, r1, #255 */
/* @0x1581a8 bne 0x1581d4 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x1581ac mov r0, r9 */
/* @0x1581b0 mov r1, r7 */
/* @0x1581b4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x1581b8 ldr r2, [sp, #0x86c] */
/* @0x1581bc ldr r3, [r6] */
/* @0x1581c0 cmp r2, r3 */
/* @0x1581c4 bne 0x158328 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x1581c8 add sp, sp, #2160 */
/* @0x1581cc add sp, sp, #4 */
/* @0x1581d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1581d4 add r10, sp, #16 */
/* @0x1581d8 sub r8, r10, #12 */
/* @0x1581dc mov r0, r8 */
/* @0x1581e0 bl 0x214294 <_Z9SHA1ResetP11SHA1Context> */
/* @0x1581e4 cmp r5, #0 */
/* @0x1581e8 mov r2, r4 */
/* @0x1581ec beq 0x158290 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1581f0 add r7, sp, #108 */
/* @0x1581f4 mov r1, #2048 */
/* @0x1581f8 mov r0, r7 */
/* @0x1581fc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x158200 ldr r1, [pc, #0x128] */
/* @0x158204 mov r0, r7 */
/* @0x158208 add r1, pc, r1 */
/* @0x15820c bl 0xb6844 <fopen@plt> */
/* @0x158210 mov r1, #0 */
/* @0x158214 mov r2, #2 */
/* @0x158218 mov r11, r0 */
/* @0x15821c bl 0xb68d4 <fseek@plt> */
/* @0x158220 mov r0, r11 */
/* @0x158224 bl 0xb68e0 <ftell@plt> */
/* @0x158228 mov r1, #0 */
/* @0x15822c mov r2, r1 */
/* @0x158230 mov r4, r0 */
/* @0x158234 mov r0, r11 */
/* @0x158238 bl 0xb68d4 <fseek@plt> */
/* @0x15823c cmp r4, #0 */
/* @0x158240 bne 0x158260 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x158244 b 0x158284 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x158248 mov r0, r8 */
/* @0x15824c mov r1, r7 */
/* @0x158250 mov r2, r5 */
/* @0x158254 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0x158258 subs r4, r4, r5 */
/* @0x15825c beq 0x158284 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x158260 cmp r4, #2048 */
/* @0x158264 movlo r2, r4 */
/* @0x158268 movhs r2, #2048 */
/* @0x15826c mov r0, r7 */
/* @0x158270 mov r1, #1 */
/* @0x158274 mov r3, r11 */
/* @0x158278 bl 0xb68c8 <fread@plt> */
/* @0x15827c subs r5, r0, #0 */
/* @0x158280 bne 0x158248 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x158284 mov r0, r11 */
/* @0x158288 bl 0xb6850 <fclose@plt> */
/* @0x15828c b 0x1582d0 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x158290 add r4, sp, #108 */
/* @0x158294 mov r1, #2048 */
/* @0x158298 mov r0, r4 */
/* @0x15829c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1582a0 ldr r1, [pc, #0x8c] */
/* @0x1582a4 mov r0, r4 */
/* @0x1582a8 add r1, pc, r1 */
/* @0x1582ac bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x1582b0 ldr r3, [r0] */
/* @0x1582b4 mov r4, r0 */
/* @0x1582b8 mov r0, r8 */
/* @0x1582bc ldr r1, [r3, #0xc] */
/* @0x1582c0 ldr r2, [r3, #0x10] */
/* @0x1582c4 bl 0x214538 <_Z9SHA1InputP11SHA1ContextPKhj> */
/* @0x1582c8 mov r0, r4 */
/* @0x1582cc bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x1582d0 mov r0, r8 */
/* @0x1582d4 ldr r8, [pc, #0x5c] */
/* @0x1582d8 bl 0x2146e4 <_Z10SHA1ResultP11SHA1Context> */
/* @0x1582dc ldr r1, [pc, #0x58] */
/* @0x1582e0 mov r0, #45 */
/* @0x1582e4 movw r2, #0xa34 */
/* @0x1582e8 add r1, pc, r1 */
/* @0x1582ec mov r3, #1 */
/* @0x1582f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1582f4 sub r4, r10, #16 */
/* @0x1582f8 add r8, pc, r8 */
/* @0x1582fc add r10, r10, #4 */
/* @0x158300 mov r7, r0 */
/* @0x158304 mov r5, r0 */
/* @0x158308 ldr r2, [r4, #0x4]! */
/* @0x15830c mov r0, r5 */
/* @0x158310 mov r1, r8 */
/* @0x158314 add r5, r5, #8 */
/* @0x158318 bl 0xb6550 <sprintf@plt> */
/* @0x15831c cmp r4, r10 */
/* @0x158320 bne 0x158308 <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x158324 b 0x1581ac <_Z15F_YoYo_SHA1FileR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x158328 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x15832c .word 0x002957dc */
/* @0x158330 ldrsheq pc, [sp], -r0 */
/* @0x158334 andseq pc, sp, r0, asr r9 */
/* @0x158338 ldrheq r9, [sp], -r4 */
/* @0x15833c andseq lr, lr, r12, ror r2 */

/* ── FUNC 0x158340 · F_YoYo_PowersaveEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x158340 push {r3, lr} */
/* @0x158344 mov r1, #0 */
/* @0x158348 ldr r0, [sp, #0x8] */
/* @0x15834c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x158350 pop {r3, lr} */
/* @0x158354 b 0x15f2a4 <_Z17YYPowersaveEnableb> */

/* ── FUNC 0x158358 · F_YoYo_AnalyticsEvent(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x158358 push {r3, lr} */
/* @0x15835c mov r1, #0 */
/* @0x158360 ldr r0, [sp, #0x8] */
/* @0x158364 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158368 pop {r3, lr} */
/* @0x15836c b 0x15f380 <_Z16YYAnalyticsEventPKc> */

/* ── FUNC 0x158370 · F_GMLApplicationSurfaceDrawEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x158370 push {r3, lr} */
/* @0x158374 mov r1, #0 */
/* @0x158378 ldr r0, [sp, #0x8] */
/* @0x15837c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x158380 vmov.f64 d7, #5.000000e-01 */
/* @0x158384 ldr r3, [pc, #0x1c] */
/* @0x158388 ldr r3, [pc, r3] */
/* @0x15838c vmov d6, r0, r1 */
/* @0x158390 vcmpe.f64 d6, d7 */
/* @0x158394 vmrs APSR_nzcv, fpscr */
/* @0x158398 movle r2, #0 */
/* @0x15839c movgt r2, #1 */
/* @0x1583a0 strb r2, [r3] */
/* @0x1583a4 pop {r3, pc} */
/* @0x1583a8 .word 0x002977fc */

/* ── FUNC 0x1583ac · F_AppSurfaceEnable(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0x1583ac ldr r3, [pc, #0x74] */
/* @0x1583b0 ldr r2, [pc, #0x74] */
/* @0x1583b4 add r3, pc, r3 */
/* @0x1583b8 push {r4, lr} */
/* @0x1583bc ldr r4, [r3, r2] */
/* @0x1583c0 ldr r0, [sp, #0x8] */
/* @0x1583c4 ldrb r2, [r4] */
/* @0x1583c8 cmp r2, #0 */
/* @0x1583cc beq 0x158400 <_Z18F_AppSurfaceEnableR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x1583d0 ldr r12, [pc, #0x58] */
/* @0x1583d4 ldr r1, [pc, #0x58] */
/* @0x1583d8 ldr r2, [pc, #0x58] */
/* @0x1583dc ldr lr, [r3, r12] */
/* @0x1583e0 ldr r12, [r3, r1] */
/* @0x1583e4 ldr r1, [pc, #0x50] */
/* @0x1583e8 ldr lr, [lr] */
/* @0x1583ec str lr, [r12] */
/* @0x1583f0 ldr r2, [r3, r2] */
/* @0x1583f4 ldr r3, [r3, r1] */
/* @0x1583f8 ldr r2, [r2] */
/* @0x1583fc str r2, [r3] */
/* @0x158400 mov r1, #0 */
/* @0x158404 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x158408 vmov.f64 d7, #5.000000e-01 */
/* @0x15840c vmov d6, r0, r1 */
/* @0x158410 vcmpe.f64 d6, d7 */
/* @0x158414 vmrs APSR_nzcv, fpscr */
/* @0x158418 movle r3, #0 */
/* @0x15841c movgt r3, #1 */
/* @0x158420 strb r3, [r4] */
/* @0x158424 pop {r4, pc} */
/* @0x158428 mlaeq r9, r12, r8, r9 */
/* @0x15842c .word 0xffffdef8 */
/* @0x158430 .word 0xffffdf38 */
/* @0x158434 .word 0xffffdf3c */
/* @0x158438 .word 0xffffdf40 */
/* @0x15843c .word 0xffffdf44 */

/* ── FUNC 0x158440 · F_YoYo_AnalyticsEventExt(RValue&, CInstance*, CInstance*, int, RValue*) · size=312 · insn=78 */
/* @0x158440 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x158444 add r11, sp, #32 */
/* @0x158448 ldr r8, [pc, #0x120] */
/* @0x15844c sub sp, sp, #20 */
/* @0x158450 mov r6, r3 */
/* @0x158454 ldr r8, [pc, r8] */
/* @0x158458 ldr r9, [r11, #0x4] */
/* @0x15845c mov r1, #0 */
/* @0x158460 ldr r3, [r8] */
/* @0x158464 mov r0, r9 */
/* @0x158468 str r3, [r11, #-0x28] */
/* @0x15846c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158470 sub r2, r6, #1 */
/* @0x158474 cmp r2, #1 */
/* @0x158478 add r2, r2, r2, lsr #31 */
/* @0x15847c asr r2, r2, #1 */
/* @0x158480 lsl r2, r2, #4 */
/* @0x158484 add r2, r2, #8 */
/* @0x158488 sub sp, sp, r2 */
/* @0x15848c mov r2, sp */
/* @0x158490 mov r3, r0 */
/* @0x158494 ble 0x15854c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x158498 mov r4, r9 */
/* @0x15849c mov r10, sp */
/* @0x1584a0 mov r7, #0 */
/* @0x1584a4 mov r5, #1 */
/* @0x1584a8 b 0x1584c0 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1584ac add r5, r5, #2 */
/* @0x1584b0 add r4, r4, #32 */
/* @0x1584b4 rsb r1, r5, r6 */
/* @0x1584b8 cmp r1, #1 */
/* @0x1584bc ble 0x158518 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1584c0 ldr r1, [r4, #0x1c] */
/* @0x1584c4 cmp r1, #1 */
/* @0x1584c8 movne r7, #1 */
/* @0x1584cc bne 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1584d0 ldr r0, [r4, #0x2c] */
/* @0x1584d4 cmp r0, #0 */
/* @0x1584d8 movne r7, r1 */
/* @0x1584dc bne 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x1584e0 mov r1, r5 */
/* @0x1584e4 mov r0, r9 */
/* @0x1584e8 str r2, [r11, #-0x34] */
/* @0x1584ec add r10, r10, #16 */
/* @0x1584f0 str r3, [r11, #-0x30] */
/* @0x1584f4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x1584f8 add r1, r5, #1 */
/* @0x1584fc str r0, [r10, #-0x10] */
/* @0x158500 mov r0, r9 */
/* @0x158504 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x158508 ldr r2, [r11, #-0x34] */
/* @0x15850c ldr r3, [r11, #-0x30] */
/* @0x158510 strd r0, r1, [r10, #-8] */
/* @0x158514 b 0x1584ac <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x158518 cmp r7, #0 */
/* @0x15851c bne 0x158558 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x158520 rsb r10, r2, r10 */
/* @0x158524 asrs r1, r10, #4 */
/* @0x158528 beq 0x15854c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x15852c mov r0, r3 */
/* @0x158530 bl 0x15f3d0 <_Z19YYAnalyticsEventExtPKciPK15SKeyValueNumber> */
/* @0x158534 ldr r2, [r11, #-0x28] */
/* @0x158538 ldr r3, [r8] */
/* @0x15853c cmp r2, r3 */
/* @0x158540 bne 0x15856c <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x158544 sub sp, r11, #32 */
/* @0x158548 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x15854c mov r0, r3 */
/* @0x158550 bl 0x15f380 <_Z16YYAnalyticsEventPKc> */
/* @0x158554 b 0x158534 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x158558 ldr r0, [pc, #0x14] */
/* @0x15855c mov r1, #0 */
/* @0x158560 add r0, pc, r0 */
/* @0x158564 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x158568 b 0x158534 <_Z24F_YoYo_AnalyticsEventExtR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x15856c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x158570 .word 0x002954fc */
/* @0x158574 andseq lr, lr, r0, ror #2 */

/* ── FUNC 0x158578 · F_YoYo_WinPhone_SetTile_Cycle_CycleImages(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=87 */
/* @0x158578 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x15857c add r11, sp, #32 */
/* @0x158580 ldr r4, [pc, #0x134] */
/* @0x158584 sub sp, sp, #20 */
/* @0x158588 ldr r2, [pc, #0x130] */
/* @0x15858c add r4, pc, r4 */
/* @0x158590 sub r1, r3, #1 */
/* @0x158594 cmp r1, #8 */
/* @0x158598 mov r1, #0 */
/* @0x15859c ldr r6, [r4, r2] */
/* @0x1585a0 ldr r7, [r11, #0x4] */
/* @0x1585a4 str r1, [r0, #0xc] */
/* @0x1585a8 ldr r2, [r6] */
/* @0x1585ac str r1, [r0, #0x4] */
/* @0x1585b0 str r1, [r0] */
/* @0x1585b4 str r2, [r11, #-0x28] */
/* @0x1585b8 bhi 0x1585c8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x1585bc ldr r2, [r7, #0xc] */
/* @0x1585c0 cmp r2, #1 */
/* @0x1585c4 beq 0x158610 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x1585c8 ldr r3, [pc, #0xf4] */
/* @0x1585cc ldr r1, [pc, #0xf4] */
/* @0x1585d0 ldr r3, [r4, r3] */
/* @0x1585d4 add r1, pc, r1 */
/* @0x1585d8 ldr r0, [r3] */
/* @0x1585dc ldr r3, [r0] */
/* @0x1585e0 ldr r3, [r3, #0xc] */
/* @0x1585e4 blx r3 */
/* @0x1585e8 ldr r0, [pc, #0xdc] */
/* @0x1585ec mov r1, #0 */
/* @0x1585f0 add r0, pc, r0 */
/* @0x1585f4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1585f8 ldr r2, [r11, #-0x28] */
/* @0x1585fc ldr r3, [r6] */
/* @0x158600 cmp r2, r3 */
/* @0x158604 bne 0x1586b8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x158608 sub sp, r11, #32 */
/* @0x15860c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x158610 lsl r2, r3, #2 */
/* @0x158614 mov r5, r1 */
/* @0x158618 add r2, r2, #14 */
/* @0x15861c mov r8, r1 */
/* @0x158620 bic r2, r2, #7 */
/* @0x158624 mov r10, r7 */
/* @0x158628 sub sp, sp, r2 */
/* @0x15862c mov r9, sp */
/* @0x158630 b 0x158644 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x158634 add r5, r5, #1 */
/* @0x158638 add r10, r10, #16 */
/* @0x15863c cmp r5, r3 */
/* @0x158640 beq 0x158694 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x158644 ldr r2, [r10, #0xc] */
/* @0x158648 cmp r2, #1 */
/* @0x15864c bne 0x158634 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x158650 mov r1, r5 */
/* @0x158654 mov r0, r7 */
/* @0x158658 str r3, [r11, #-0x34] */
/* @0x15865c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158660 str r0, [r11, #-0x30] */
/* @0x158664 bl 0xb6538 <strlen@plt> */
/* @0x158668 ldr r1, [r11, #-0x30] */
/* @0x15866c add r12, r0, #15 */
/* @0x158670 add r2, r0, #1 */
/* @0x158674 bic r12, r12, #7 */
/* @0x158678 sub sp, sp, r12 */
/* @0x15867c str sp, [r9, r8, lsl #2] */
/* @0x158680 add r8, r8, #1 */
/* @0x158684 mov r0, sp */
/* @0x158688 bl 0xb65bc <memcpy@plt> */
/* @0x15868c ldr r3, [r11, #-0x34] */
/* @0x158690 b 0x158634 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x158694 ldr r3, [pc, #0x28] */
/* @0x158698 ldr r1, [pc, #0x30] */
/* @0x15869c ldr r3, [r4, r3] */
/* @0x1586a0 add r1, pc, r1 */
/* @0x1586a4 ldr r0, [r3] */
/* @0x1586a8 ldr r3, [r0] */
/* @0x1586ac ldr r3, [r3, #0xc] */
/* @0x1586b0 blx r3 */
/* @0x1586b4 b 0x1585f8 <_Z41F_YoYo_WinPhone_SetTile_Cycle_CycleImagesR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x1586b8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1586bc eoreq r9, r9, r4, asr #13 */
/* @0x1586c0 .word 0xffffbd00 */
/* @0x1586c4 .word 0xffffbac4 */
/* @0x1586c8 andseq lr, lr, r8, lsr #2 */
/* @0x1586cc ldrsbeq sp, [lr], -r8 */
/* @0x1586d0 andseq sp, lr, r12, ror #28 */

/* ── FUNC 0x1586d4 · F_GMLReleaseMode(RValue&, CInstance*, CInstance*, int, RValue*) · size=48 · insn=12 */
/* @0x1586d4 push {r3, lr} */
/* @0x1586d8 mov r1, #0 */
/* @0x1586dc ldr r0, [sp, #0x8] */
/* @0x1586e0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1586e4 vmov.f64 d7, #5.000000e-01 */
/* @0x1586e8 pop {r3, lr} */
/* @0x1586ec vmov d6, r0, r1 */
/* @0x1586f0 vcmpe.f64 d6, d7 */
/* @0x1586f4 vmrs APSR_nzcv, fpscr */
/* @0x1586f8 movpl r0, #0 */
/* @0x1586fc movmi r0, #1 */
/* @0x158700 b 0x2a28ec <_Z12SetDebugModeb> */

/* ── FUNC 0x158704 · F_MouseXToGUI(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x158704 push {r4, lr} */
/* @0x158708 mov r1, #0 */
/* @0x15870c mov r4, r0 */
/* @0x158710 ldr r0, [sp, #0x8] */
/* @0x158714 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x158718 cmp r0, #9 */
/* @0x15871c mov r2, r0 */
/* @0x158720 pophi {r4, pc} */
/* @0x158724 ldr r0, [pc, #0x5c] */
/* @0x158728 mov r3, #0 */
/* @0x15872c str r3, [r4, #0xc] */
/* @0x158730 ldr r0, [pc, r0] */
/* @0x158734 ldr r1, [pc, #0x50] */
/* @0x158738 ldr r3, [pc, #0x50] */
/* @0x15873c ldr r0, [r0, r2, lsl #2] */
/* @0x158740 ldr r1, [pc, r1] */
/* @0x158744 ldr r3, [pc, r3] */
/* @0x158748 vldr s11, [r3, #16] */
/* @0x15874c ldr r1, [r1, r2, lsl #2] */
/* @0x158750 vldr s13, [r3] */
/* @0x158754 vmov s15, r0 */
/* @0x158758 vldr s14, [r3, #48] */
/* @0x15875c vcvt.f32.s32 s15, s15 */
/* @0x158760 vmov s12, r1 */
/* @0x158764 vmul.f32 s15, s15, s11 */
/* @0x158768 vcvt.f32.s32 s12, s12 */
/* @0x15876c vmla.f32 s15, s12, s13 */
/* @0x158770 vadd.f32 s15, s15, s14 */
/* @0x158774 vcvt.f64.f32 d6, s15 */
/* @0x158778 vmov r0, r1, d6 */
/* @0x15877c bl 0xb6598 <floor@plt> */
/* @0x158780 stm r4, {r0, r1} */
/* @0x158784 pop {r4, pc} */
/* @0x158788 eoreq r7, r9, r8, ror #8 */
/* @0x15878c eoreq r7, r9, r12, asr r4 */
/* @0x158790 eoreq r7, r9, r12, asr r4 */

/* ── FUNC 0x158794 · F_MouseYToGUI(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0x158794 push {r4, lr} */
/* @0x158798 mov r1, #0 */
/* @0x15879c mov r4, r0 */
/* @0x1587a0 ldr r0, [sp, #0x8] */
/* @0x1587a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1587a8 cmp r0, #9 */
/* @0x1587ac mov r2, r0 */
/* @0x1587b0 pophi {r4, pc} */
/* @0x1587b4 ldr r0, [pc, #0x5c] */
/* @0x1587b8 mov r3, #0 */
/* @0x1587bc str r3, [r4, #0xc] */
/* @0x1587c0 ldr r0, [pc, r0] */
/* @0x1587c4 ldr r1, [pc, #0x50] */
/* @0x1587c8 ldr r3, [pc, #0x50] */
/* @0x1587cc ldr r0, [r0, r2, lsl #2] */
/* @0x1587d0 ldr r1, [pc, r1] */
/* @0x1587d4 ldr r3, [pc, r3] */
/* @0x1587d8 vldr s11, [r3, #20] */
/* @0x1587dc ldr r1, [r1, r2, lsl #2] */
/* @0x1587e0 vldr s13, [r3, #4] */
/* @0x1587e4 vmov s15, r0 */
/* @0x1587e8 vldr s14, [r3, #52] */
/* @0x1587ec vcvt.f32.s32 s15, s15 */
/* @0x1587f0 vmov s12, r1 */
/* @0x1587f4 vmul.f32 s15, s15, s11 */
/* @0x1587f8 vcvt.f32.s32 s12, s12 */
/* @0x1587fc vmla.f32 s15, s12, s13 */
/* @0x158800 vadd.f32 s15, s15, s14 */
/* @0x158804 vcvt.f64.f32 d6, s15 */
/* @0x158808 vmov r0, r1, d6 */
/* @0x15880c bl 0xb6598 <floor@plt> */
/* @0x158810 stm r4, {r0, r1} */
/* @0x158814 pop {r4, pc} */
/* @0x158818 .word 0x002973d8 */
/* @0x15881c eoreq r7, r9, r12, asr #7 */
/* @0x158820 eoreq r7, r9, r12, asr #7 */

/* ── FUNC 0x158824 · F_PlayerRun(RValue&, CInstance*, CInstance*, int, RValue*) · size=348 · insn=87 */
/* @0x158824 push {r4, r5, r6, r7, r8, lr} */
/* @0x158828 sub sp, sp, #2048 */
/* @0x15882c ldr r4, [pc, #0x12c] */
/* @0x158830 sub sp, sp, #8 */
/* @0x158834 ldr r3, [pc, #0x128] */
/* @0x158838 mov r1, #0 */
/* @0x15883c add r4, pc, r4 */
/* @0x158840 ldr r7, [sp, #0x820] */
/* @0x158844 ldr r6, [r4, r3] */
/* @0x158848 mov r0, r7 */
/* @0x15884c ldr r3, [r6] */
/* @0x158850 str r3, [sp, #0x804] */
/* @0x158854 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158858 mov r1, #1 */
/* @0x15885c mov r5, r0 */
/* @0x158860 mov r0, r7 */
/* @0x158864 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x158868 mov r8, r0 */
/* @0x15886c mov r0, r5 */
/* @0x158870 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x158874 cmp r0, #0 */
/* @0x158878 bne 0x158944 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x15887c mov r0, r5 */
/* @0x158880 add r7, sp, #4 */
/* @0x158884 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x158888 mov r2, r5 */
/* @0x15888c mov r1, #1024 */
/* @0x158890 cmp r0, #0 */
/* @0x158894 mov r0, r7 */
/* @0x158898 bne 0x15893c <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x15889c bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1588a0 add r5, sp, #1024 */
/* @0x1588a4 mov r1, #1024 */
/* @0x1588a8 add r5, r5, #8 */
/* @0x1588ac mov r2, r8 */
/* @0x1588b0 sub r5, r5, #4 */
/* @0x1588b4 mov r0, r5 */
/* @0x1588b8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1588bc mov r0, r5 */
/* @0x1588c0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1588c4 ldr r3, [pc, #0x9c] */
/* @0x1588c8 ldr r3, [r4, r3] */
/* @0x1588cc str r0, [r3] */
/* @0x1588d0 mov r0, r7 */
/* @0x1588d4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1588d8 ldr r2, [pc, #0x8c] */
/* @0x1588dc ldr r3, [pc, #0x8c] */
/* @0x1588e0 ldr r2, [r4, r2] */
/* @0x1588e4 str r0, [r2] */
/* @0x1588e8 ldr r3, [r4, r3] */
/* @0x1588ec ldr r0, [r3] */
/* @0x1588f0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1588f4 ldr r2, [pc, #0x78] */
/* @0x1588f8 ldr r3, [pc, #0x78] */
/* @0x1588fc ldr r1, [pc, #0x78] */
/* @0x158900 ldr r2, [r4, r2] */
/* @0x158904 add r1, pc, r1 */
/* @0x158908 str r0, [r2] */
/* @0x15890c ldr r3, [r4, r3] */
/* @0x158910 ldr r0, [r3] */
/* @0x158914 ldr r3, [r0] */
/* @0x158918 ldr r3, [r3, #0xc] */
/* @0x15891c blx r3 */
/* @0x158920 ldr r2, [sp, #0x804] */
/* @0x158924 ldr r3, [r6] */
/* @0x158928 cmp r2, r3 */
/* @0x15892c bne 0x15895c <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x158930 add sp, sp, #2048 */
/* @0x158934 add sp, sp, #8 */
/* @0x158938 pop {r4, r5, r6, r7, r8, pc} */
/* @0x15893c bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x158940 b 0x1588a0 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x158944 add r7, sp, #4 */
/* @0x158948 mov r2, r5 */
/* @0x15894c mov r1, #1024 */
/* @0x158950 mov r0, r7 */
/* @0x158954 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x158958 b 0x1588a0 <_Z11F_PlayerRunR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x15895c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x158960 eoreq r9, r9, r4, lsl r4 */
/* @0x158964 .word 0xffffbd00 */
/* @0x158968 .word 0xffffdf54 */
/* @0x15896c .word 0xffffdf58 */
/* @0x158970 .word 0xffffdf5c */
/* @0x158974 .word 0xffffdf60 */
/* @0x158978 .word 0xffffbac4 */
/* @0x15897c andseq sp, lr, r8, asr lr */

/* ── FUNC 0x158980 · F_ApplicationGetPos(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x158980 push {r4, lr} */
/* @0x158984 sub sp, sp, #40 */
/* @0x158988 mov r4, r0 */
/* @0x15898c add r1, sp, #28 */
/* @0x158990 add r0, sp, #24 */
/* @0x158994 add r2, sp, #32 */
/* @0x158998 add r3, sp, #36 */
/* @0x15899c bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_> */
/* @0x1589a0 vldr s11, [sp, #28] */
/* @0x1589a4 vcvt.f64.s32 d7, s11 */
/* @0x1589a8 vldr s11, [sp, #32] */
/* @0x1589ac mov r0, r4 */
/* @0x1589b0 mov r1, #4 */
/* @0x1589b4 vcvt.f64.s32 d6, s11 */
/* @0x1589b8 vstr d7, [sp] */
/* @0x1589bc vldr s11, [sp, #36] */
/* @0x1589c0 vcvt.f64.s32 d7, s11 */
/* @0x1589c4 vstr d6, [sp, #8] */
/* @0x1589c8 vstr d7, [sp, #16] */
/* @0x1589cc vldr s15, [sp, #24] */
/* @0x1589d0 vcvt.f64.s32 d7, s15 */
/* @0x1589d4 vmov r2, r3, d7 */
/* @0x1589d8 bl 0x120eb4 <_Z11CreateArrayP6RValueiz> */
/* @0x1589dc add sp, sp, #40 */
/* @0x1589e0 pop {r4, pc} */

/* ── FUNC 0x1589e4 · GET_YoYo_GetOSVersion(CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x1589e4 push {r4, lr} */
/* @0x1589e8 mov r3, #0 */
/* @0x1589ec str r3, [r2, #0xc] */
/* @0x1589f0 mov r4, r2 */
/* @0x1589f4 bl 0x15e5f8 <_Z11GetVersionMv> */
/* @0x1589f8 str r0, [r4] */
/* @0x1589fc mov r0, #1 */
/* @0x158a00 str r1, [r4, #0x4] */
/* @0x158a04 pop {r4, pc} */

/* ── FUNC 0x158a08 · F_YoYo_WinPhone_SetTile_Common_Title(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158a08 cmp r3, #1 */
/* @0x158a0c push {r3, lr} */
/* @0x158a10 mov r3, #0 */
/* @0x158a14 str r3, [r0, #0xc] */
/* @0x158a18 str r3, [r0] */
/* @0x158a1c str r3, [r0, #0x4] */
/* @0x158a20 beq 0x158a48 <_Z36F_YoYo_WinPhone_SetTile_Common_TitleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158a24 ldr r3, [pc, #0x50] */
/* @0x158a28 ldr r1, [pc, #0x50] */
/* @0x158a2c ldr r3, [pc, r3] */
/* @0x158a30 add r1, pc, r1 */
/* @0x158a34 ldr r0, [r3] */
/* @0x158a38 ldr r3, [r0] */
/* @0x158a3c ldr r3, [r3, #0xc] */
/* @0x158a40 blx r3 */
/* @0x158a44 pop {r3, pc} */
/* @0x158a48 ldr r2, [sp, #0x8] */
/* @0x158a4c ldr r3, [r2, #0xc] */
/* @0x158a50 cmp r3, #1 */
/* @0x158a54 bne 0x158a24 <_Z36F_YoYo_WinPhone_SetTile_Common_TitleR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158a58 ldr r3, [pc, #0x24] */
/* @0x158a5c ldr r1, [pc, #0x24] */
/* @0x158a60 ldr r3, [pc, r3] */
/* @0x158a64 add r1, pc, r1 */
/* @0x158a68 ldr r0, [r3] */
/* @0x158a6c ldr r3, [r0] */
/* @0x158a70 ldr r3, [r3, #0xc] */
/* @0x158a74 blx r3 */
/* @0x158a78 pop {r3, pc} */
/* @0x158a7c eoreq r4, r9, r8, ror #25 */
/* @0x158a80 andseq sp, lr, r4, asr sp */
/* @0x158a84 .word 0x00294cb4 */
/* @0x158a88 andseq sp, lr, r8, lsr #21 */

/* ── FUNC 0x158a8c · F_YoYo_WinPhone_SetTile_Flip_BackTitle(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158a8c cmp r3, #1 */
/* @0x158a90 push {r3, lr} */
/* @0x158a94 mov r3, #0 */
/* @0x158a98 str r3, [r0, #0xc] */
/* @0x158a9c str r3, [r0] */
/* @0x158aa0 str r3, [r0, #0x4] */
/* @0x158aa4 beq 0x158acc <_Z38F_YoYo_WinPhone_SetTile_Flip_BackTitleR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158aa8 ldr r3, [pc, #0x50] */
/* @0x158aac ldr r1, [pc, #0x50] */
/* @0x158ab0 ldr r3, [pc, r3] */
/* @0x158ab4 add r1, pc, r1 */
/* @0x158ab8 ldr r0, [r3] */
/* @0x158abc ldr r3, [r0] */
/* @0x158ac0 ldr r3, [r3, #0xc] */
/* @0x158ac4 blx r3 */
/* @0x158ac8 pop {r3, pc} */
/* @0x158acc ldr r2, [sp, #0x8] */
/* @0x158ad0 ldr r3, [r2, #0xc] */
/* @0x158ad4 cmp r3, #1 */
/* @0x158ad8 bne 0x158aa8 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackTitleR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158adc ldr r3, [pc, #0x24] */
/* @0x158ae0 ldr r1, [pc, #0x24] */
/* @0x158ae4 ldr r3, [pc, r3] */
/* @0x158ae8 add r1, pc, r1 */
/* @0x158aec ldr r0, [r3] */
/* @0x158af0 ldr r3, [r0] */
/* @0x158af4 ldr r3, [r3, #0xc] */
/* @0x158af8 blx r3 */
/* @0x158afc pop {r3, pc} */
/* @0x158b00 eoreq r4, r9, r4, ror #24 */
/* @0x158b04 andseq sp, lr, r8, lsl #26 */
/* @0x158b08 eoreq r4, r9, r0, lsr r12 */
/* @0x158b0c andseq sp, lr, r4, lsr #20 */

/* ── FUNC 0x158b10 · F_YoYo_WinPhone_SetTile_Flip_BackContent(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158b10 cmp r3, #1 */
/* @0x158b14 push {r3, lr} */
/* @0x158b18 mov r3, #0 */
/* @0x158b1c str r3, [r0, #0xc] */
/* @0x158b20 str r3, [r0] */
/* @0x158b24 str r3, [r0, #0x4] */
/* @0x158b28 beq 0x158b50 <_Z40F_YoYo_WinPhone_SetTile_Flip_BackContentR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158b2c ldr r3, [pc, #0x50] */
/* @0x158b30 ldr r1, [pc, #0x50] */
/* @0x158b34 ldr r3, [pc, r3] */
/* @0x158b38 add r1, pc, r1 */
/* @0x158b3c ldr r0, [r3] */
/* @0x158b40 ldr r3, [r0] */
/* @0x158b44 ldr r3, [r3, #0xc] */
/* @0x158b48 blx r3 */
/* @0x158b4c pop {r3, pc} */
/* @0x158b50 ldr r2, [sp, #0x8] */
/* @0x158b54 ldr r3, [r2, #0xc] */
/* @0x158b58 cmp r3, #1 */
/* @0x158b5c bne 0x158b2c <_Z40F_YoYo_WinPhone_SetTile_Flip_BackContentR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158b60 ldr r3, [pc, #0x24] */
/* @0x158b64 ldr r1, [pc, #0x24] */
/* @0x158b68 ldr r3, [pc, r3] */
/* @0x158b6c add r1, pc, r1 */
/* @0x158b70 ldr r0, [r3] */
/* @0x158b74 ldr r3, [r0] */
/* @0x158b78 ldr r3, [r3, #0xc] */
/* @0x158b7c blx r3 */
/* @0x158b80 pop {r3, pc} */
/* @0x158b84 eoreq r4, r9, r0, ror #23 */
/* @0x158b88 andseq sp, lr, r0, asr #25 */
/* @0x158b8c eoreq r4, r9, r12, lsr #23 */
/* @0x158b90 andseq sp, lr, r0, lsr #19 */

/* ── FUNC 0x158b94 · F_YoYo_WinPhone_SetTile_Flip_BackContentWide(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158b94 cmp r3, #1 */
/* @0x158b98 push {r3, lr} */
/* @0x158b9c mov r3, #0 */
/* @0x158ba0 str r3, [r0, #0xc] */
/* @0x158ba4 str r3, [r0] */
/* @0x158ba8 str r3, [r0, #0x4] */
/* @0x158bac beq 0x158bd4 <_Z44F_YoYo_WinPhone_SetTile_Flip_BackContentWideR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158bb0 ldr r3, [pc, #0x50] */
/* @0x158bb4 ldr r1, [pc, #0x50] */
/* @0x158bb8 ldr r3, [pc, r3] */
/* @0x158bbc add r1, pc, r1 */
/* @0x158bc0 ldr r0, [r3] */
/* @0x158bc4 ldr r3, [r0] */
/* @0x158bc8 ldr r3, [r3, #0xc] */
/* @0x158bcc blx r3 */
/* @0x158bd0 pop {r3, pc} */
/* @0x158bd4 ldr r2, [sp, #0x8] */
/* @0x158bd8 ldr r3, [r2, #0xc] */
/* @0x158bdc cmp r3, #1 */
/* @0x158be0 bne 0x158bb0 <_Z44F_YoYo_WinPhone_SetTile_Flip_BackContentWideR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158be4 ldr r3, [pc, #0x24] */
/* @0x158be8 ldr r1, [pc, #0x24] */
/* @0x158bec ldr r3, [pc, r3] */
/* @0x158bf0 add r1, pc, r1 */
/* @0x158bf4 ldr r0, [r3] */
/* @0x158bf8 ldr r3, [r0] */
/* @0x158bfc ldr r3, [r3, #0xc] */
/* @0x158c00 blx r3 */
/* @0x158c04 pop {r3, pc} */
/* @0x158c08 eoreq r4, r9, r12, asr r11 */
/* @0x158c0c andseq sp, lr, r12, ror r12 */
/* @0x158c10 eoreq r4, r9, r8, lsr #22 */
/* @0x158c14 andseq sp, lr, r12, lsl r9 */

/* ── FUNC 0x158c18 · F_YoYo_WinPhone_SetTile_Flip_FrontImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158c18 cmp r3, #1 */
/* @0x158c1c push {r3, lr} */
/* @0x158c20 mov r3, #0 */
/* @0x158c24 str r3, [r0, #0xc] */
/* @0x158c28 str r3, [r0] */
/* @0x158c2c str r3, [r0, #0x4] */
/* @0x158c30 beq 0x158c58 <_Z39F_YoYo_WinPhone_SetTile_Flip_FrontImageR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158c34 ldr r3, [pc, #0x50] */
/* @0x158c38 ldr r1, [pc, #0x50] */
/* @0x158c3c ldr r3, [pc, r3] */
/* @0x158c40 add r1, pc, r1 */
/* @0x158c44 ldr r0, [r3] */
/* @0x158c48 ldr r3, [r0] */
/* @0x158c4c ldr r3, [r3, #0xc] */
/* @0x158c50 blx r3 */
/* @0x158c54 pop {r3, pc} */
/* @0x158c58 ldr r2, [sp, #0x8] */
/* @0x158c5c ldr r3, [r2, #0xc] */
/* @0x158c60 cmp r3, #1 */
/* @0x158c64 bne 0x158c34 <_Z39F_YoYo_WinPhone_SetTile_Flip_FrontImageR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158c68 ldr r3, [pc, #0x24] */
/* @0x158c6c ldr r1, [pc, #0x24] */
/* @0x158c70 ldr r3, [pc, r3] */
/* @0x158c74 add r1, pc, r1 */
/* @0x158c78 ldr r0, [r3] */
/* @0x158c7c ldr r3, [r0] */
/* @0x158c80 ldr r3, [r3, #0xc] */
/* @0x158c84 blx r3 */
/* @0x158c88 pop {r3, pc} */
/* @0x158c8c .word 0x00294ad8 */
/* @0x158c90 andseq sp, lr, r12, lsr r12 */
/* @0x158c94 eoreq r4, r9, r4, lsr #21 */
/* @0x158c98 mulseq lr, r8, r8 */

/* ── FUNC 0x158c9c · F_YoYo_WinPhone_SetTile_Flip_FrontImageSmall(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158c9c cmp r3, #1 */
/* @0x158ca0 push {r3, lr} */
/* @0x158ca4 mov r3, #0 */
/* @0x158ca8 str r3, [r0, #0xc] */
/* @0x158cac str r3, [r0] */
/* @0x158cb0 str r3, [r0, #0x4] */
/* @0x158cb4 beq 0x158cdc <_Z44F_YoYo_WinPhone_SetTile_Flip_FrontImageSmallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158cb8 ldr r3, [pc, #0x50] */
/* @0x158cbc ldr r1, [pc, #0x50] */
/* @0x158cc0 ldr r3, [pc, r3] */
/* @0x158cc4 add r1, pc, r1 */
/* @0x158cc8 ldr r0, [r3] */
/* @0x158ccc ldr r3, [r0] */
/* @0x158cd0 ldr r3, [r3, #0xc] */
/* @0x158cd4 blx r3 */
/* @0x158cd8 pop {r3, pc} */
/* @0x158cdc ldr r2, [sp, #0x8] */
/* @0x158ce0 ldr r3, [r2, #0xc] */
/* @0x158ce4 cmp r3, #1 */
/* @0x158ce8 bne 0x158cb8 <_Z44F_YoYo_WinPhone_SetTile_Flip_FrontImageSmallR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158cec ldr r3, [pc, #0x24] */
/* @0x158cf0 ldr r1, [pc, #0x24] */
/* @0x158cf4 ldr r3, [pc, r3] */
/* @0x158cf8 add r1, pc, r1 */
/* @0x158cfc ldr r0, [r3] */
/* @0x158d00 ldr r3, [r0] */
/* @0x158d04 ldr r3, [r3, #0xc] */
/* @0x158d08 blx r3 */
/* @0x158d0c pop {r3, pc} */
/* @0x158d10 eoreq r4, r9, r4, asr r10 */
/* @0x158d14 ldrsheq sp, [lr], -r8 */
/* @0x158d18 eoreq r4, r9, r0, lsr #20 */
/* @0x158d1c andseq sp, lr, r4, lsl r8 */

/* ── FUNC 0x158d20 · F_YoYo_WinPhone_SetTile_Flip_FrontImageWide(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158d20 cmp r3, #1 */
/* @0x158d24 push {r3, lr} */
/* @0x158d28 mov r3, #0 */
/* @0x158d2c str r3, [r0, #0xc] */
/* @0x158d30 str r3, [r0] */
/* @0x158d34 str r3, [r0, #0x4] */
/* @0x158d38 beq 0x158d60 <_Z43F_YoYo_WinPhone_SetTile_Flip_FrontImageWideR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158d3c ldr r3, [pc, #0x50] */
/* @0x158d40 ldr r1, [pc, #0x50] */
/* @0x158d44 ldr r3, [pc, r3] */
/* @0x158d48 add r1, pc, r1 */
/* @0x158d4c ldr r0, [r3] */
/* @0x158d50 ldr r3, [r0] */
/* @0x158d54 ldr r3, [r3, #0xc] */
/* @0x158d58 blx r3 */
/* @0x158d5c pop {r3, pc} */
/* @0x158d60 ldr r2, [sp, #0x8] */
/* @0x158d64 ldr r3, [r2, #0xc] */
/* @0x158d68 cmp r3, #1 */
/* @0x158d6c bne 0x158d3c <_Z43F_YoYo_WinPhone_SetTile_Flip_FrontImageWideR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158d70 ldr r3, [pc, #0x24] */
/* @0x158d74 ldr r1, [pc, #0x24] */
/* @0x158d78 ldr r3, [pc, r3] */
/* @0x158d7c add r1, pc, r1 */
/* @0x158d80 ldr r0, [r3] */
/* @0x158d84 ldr r3, [r0] */
/* @0x158d88 ldr r3, [r3, #0xc] */
/* @0x158d8c blx r3 */
/* @0x158d90 pop {r3, pc} */
/* @0x158d94 .word 0x002949d0 */
/* @0x158d98 ldrheq sp, [lr], -r8 */
/* @0x158d9c mlaeq r9, r12, r9, r4 */
/* @0x158da0 mulseq lr, r0, r7 */

/* ── FUNC 0x158da4 · F_YoYo_WinPhone_SetTile_Flip_BackImage(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158da4 cmp r3, #1 */
/* @0x158da8 push {r3, lr} */
/* @0x158dac mov r3, #0 */
/* @0x158db0 str r3, [r0, #0xc] */
/* @0x158db4 str r3, [r0] */
/* @0x158db8 str r3, [r0, #0x4] */
/* @0x158dbc beq 0x158de4 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackImageR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158dc0 ldr r3, [pc, #0x50] */
/* @0x158dc4 ldr r1, [pc, #0x50] */
/* @0x158dc8 ldr r3, [pc, r3] */
/* @0x158dcc add r1, pc, r1 */
/* @0x158dd0 ldr r0, [r3] */
/* @0x158dd4 ldr r3, [r0] */
/* @0x158dd8 ldr r3, [r3, #0xc] */
/* @0x158ddc blx r3 */
/* @0x158de0 pop {r3, pc} */
/* @0x158de4 ldr r2, [sp, #0x8] */
/* @0x158de8 ldr r3, [r2, #0xc] */
/* @0x158dec cmp r3, #1 */
/* @0x158df0 bne 0x158dc0 <_Z38F_YoYo_WinPhone_SetTile_Flip_BackImageR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158df4 ldr r3, [pc, #0x24] */
/* @0x158df8 ldr r1, [pc, #0x24] */
/* @0x158dfc ldr r3, [pc, r3] */
/* @0x158e00 add r1, pc, r1 */
/* @0x158e04 ldr r0, [r3] */
/* @0x158e08 ldr r3, [r0] */
/* @0x158e0c ldr r3, [r3, #0xc] */
/* @0x158e10 blx r3 */
/* @0x158e14 pop {r3, pc} */
/* @0x158e18 eoreq r4, r9, r12, asr #18 */
/* @0x158e1c andseq sp, lr, r8, ror r11 */
/* @0x158e20 eoreq r4, r9, r8, lsl r9 */
/* @0x158e24 andseq sp, lr, r12, lsl #14 */

/* ── FUNC 0x158e28 · F_YoYo_WinPhone_SetTile_Flip_BackImageWide(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0x158e28 cmp r3, #1 */
/* @0x158e2c push {r3, lr} */
/* @0x158e30 mov r3, #0 */
/* @0x158e34 str r3, [r0, #0xc] */
/* @0x158e38 str r3, [r0] */
/* @0x158e3c str r3, [r0, #0x4] */
/* @0x158e40 beq 0x158e68 <_Z42F_YoYo_WinPhone_SetTile_Flip_BackImageWideR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x158e44 ldr r3, [pc, #0x50] */
/* @0x158e48 ldr r1, [pc, #0x50] */
/* @0x158e4c ldr r3, [pc, r3] */
/* @0x158e50 add r1, pc, r1 */
/* @0x158e54 ldr r0, [r3] */
/* @0x158e58 ldr r3, [r0] */
/* @0x158e5c ldr r3, [r3, #0xc] */
/* @0x158e60 blx r3 */
/* @0x158e64 pop {r3, pc} */
/* @0x158e68 ldr r2, [sp, #0x8] */
/* @0x158e6c ldr r3, [r2, #0xc] */
/* @0x158e70 cmp r3, #1 */
/* @0x158e74 bne 0x158e44 <_Z42F_YoYo_WinPhone_SetTile_Flip_BackImageWideR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x158e78 ldr r3, [pc, #0x24] */
/* @0x158e7c ldr r1, [pc, #0x24] */
/* @0x158e80 ldr r3, [pc, r3] */
/* @0x158e84 add r1, pc, r1 */
/* @0x158e88 ldr r0, [r3] */
/* @0x158e8c ldr r3, [r0] */
/* @0x158e90 ldr r3, [r3, #0xc] */
/* @0x158e94 blx r3 */
/* @0x158e98 pop {r3, pc} */
/* @0x158e9c eoreq r4, r9, r8, asr #17 */
/* @0x158ea0 andseq sp, lr, r4, lsr r11 */
/* @0x158ea4 mlaeq r9, r4, r8, r4 */
/* @0x158ea8 andseq sp, lr, r8, lsl #13 */
