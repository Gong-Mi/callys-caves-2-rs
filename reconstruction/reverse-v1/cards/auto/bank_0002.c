/* libyoyo.so 覆盖卡组 0002
 * 函数 0xc08c8..0xc2b58，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xc08c8 · CSkeletonInstance::GetDuration(char*) const · size=104 · insn=24 */
/* @0xc08c8 push {r4, lr} */
/* @0xc08cc mov r4, r1 */
/* @0xc08d0 ldr r0, [r0, #0x30] */
/* @0xc08d4 bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0xc08d8 cmp r0, #0 */
/* @0xc08dc beq 0xc08f0 <_ZNK17CSkeletonInstance11GetDurationEPc+0x28> */
/* @0xc08e0 vldr s14, [r0, #4] */
/* @0xc08e4 vcvt.f64.f32 d7, s14 */
/* @0xc08e8 vmov r0, r1, d7 */
/* @0xc08ec pop {r4, pc} */
/* @0xc08f0 ldr r3, [pc, #0x30] */
/* @0xc08f4 mov r2, r4 */
/* @0xc08f8 ldr r1, [pc, #0x2c] */
/* @0xc08fc ldr r3, [pc, r3] */
/* @0xc0900 add r1, pc, r1 */
/* @0xc0904 ldr r0, [r3] */
/* @0xc0908 ldr r3, [r0] */
/* @0xc090c ldr r3, [r3, #0xc] */
/* @0xc0910 blx r3 */
/* @0xc0914 vldr d7, [pc, #4] */
/* @0xc0918 b 0xc08e8 <_ZNK17CSkeletonInstance11GetDurationEPc+0x20> */
/* @0xc091c nop */
/* @0xc0928 eorseq r12, r2, r8, lsl lr */
/* @0xc092c eoreq r0, r7, r4 */

/* ── FUNC 0xc0930 · CSkeletonInstance::GetFrames(char*) const · size=200 · insn=50 */
/* @0xc0930 push {r3, r4, r5, lr} */
/* @0xc0934 mov r5, r1 */
/* @0xc0938 ldr r0, [r0, #0x30] */
/* @0xc093c bl 0x28b1dc <spSkeletonData_findAnimation> */
/* @0xc0940 ldr r3, [pc, #0x98] */
/* @0xc0944 add r3, pc, r3 */
/* @0xc0948 subs r4, r0, #0 */
/* @0xc094c beq 0xc09b4 <_ZNK17CSkeletonInstance9GetFramesEPc+0x84> */
/* @0xc0950 ldr r2, [pc, #0x8c] */
/* @0xc0954 ldr r2, [r3, r2] */
/* @0xc0958 ldrb r2, [r2] */
/* @0xc095c cmp r2, #0 */
/* @0xc0960 bne 0xc0998 <_ZNK17CSkeletonInstance9GetFramesEPc+0x68> */
/* @0xc0964 ldr r2, [pc, #0x7c] */
/* @0xc0968 ldr r3, [r3, r2] */
/* @0xc096c ldr r3, [r3] */
/* @0xc0970 cmp r3, #0 */
/* @0xc0974 vldrne s13, [r3, #12] */
/* @0xc0978 vmoveq.f32 s13, #3.000000e+01 */
/* @0xc097c vcvtne.f32.s32 s13, s13 */
/* @0xc0980 vldr s14, [r4, #4] */
/* @0xc0984 vmov.f32 s15, #5.000000e-01 */
/* @0xc0988 vmla.f32 s15, s13, s14 */
/* @0xc098c vcvt.s32.f32 s15, s15 */
/* @0xc0990 vmov r0, s15 */
/* @0xc0994 pop {r3, r4, r5, pc} */
/* @0xc0998 ldr r2, [pc, #0x4c] */
/* @0xc099c ldr r0, [r3, r2] */
/* @0xc09a0 bl 0x214808 <_ZN13CTimingSource6GetFPSEv> */
/* @0xc09a4 vmov d7, r0, r1 */
/* @0xc09a8 vcvt.s32.f64 s13, d7 */
/* @0xc09ac vcvt.f32.s32 s13, s13 */
/* @0xc09b0 b 0xc0980 <_ZNK17CSkeletonInstance9GetFramesEPc+0x50> */
/* @0xc09b4 ldr r0, [pc, #0x34] */
/* @0xc09b8 mov r2, r5 */
/* @0xc09bc ldr r1, [pc, #0x30] */
/* @0xc09c0 ldr r3, [r3, r0] */
/* @0xc09c4 add r1, pc, r1 */
/* @0xc09c8 ldr r0, [r3] */
/* @0xc09cc ldr r3, [r0] */
/* @0xc09d0 ldr r3, [r3, #0xc] */
/* @0xc09d4 blx r3 */
/* @0xc09d8 mov r0, r4 */
/* @0xc09dc pop {r3, r4, r5, pc} */
/* @0xc09e0 eorseq r1, r3, r12, lsl #6 */
/* @0xc09e4 .word 0xffffbcd4 */
/* @0xc09e8 .word 0xffffbcd8 */
/* @0xc09ec .word 0xffffbcdc */
/* @0xc09f0 .word 0xffffbac4 */
/* @0xc09f4 eoreq pc, r6, r0, asr #30 */

/* ── FUNC 0xc09f8 · _RefThing<char const*>::dec() · size=132 · insn=33 */
/* @0xc09f8 push {r3, r4, r5, lr} */
/* @0xc09fc mov r4, r0 */
/* @0xc0a00 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0a04 ldr r5, [r4, #0x4] */
/* @0xc0a08 sub r5, r5, #1 */
/* @0xc0a0c str r5, [r4, #0x4] */
/* @0xc0a10 cmp r5, #0 */
/* @0xc0a14 beq 0xc0a20 <_ZN9_RefThingIPKcE3decEv+0x28> */
/* @0xc0a18 pop {r3, r4, r5, lr} */
/* @0xc0a1c b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0a20 ldr r0, [r4] */
/* @0xc0a24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0a28 str r5, [r4] */
/* @0xc0a2c str r5, [r4, #0x8] */
/* @0xc0a30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0a34 ldr r5, [r4, #0x4] */
/* @0xc0a38 sub r5, r5, #1 */
/* @0xc0a3c str r5, [r4, #0x4] */
/* @0xc0a40 cmp r5, #0 */
/* @0xc0a44 bne 0xc0a68 <_ZN9_RefThingIPKcE3decEv+0x70> */
/* @0xc0a48 ldr r0, [r4] */
/* @0xc0a4c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0a50 mov r0, r4 */
/* @0xc0a54 str r5, [r4] */
/* @0xc0a58 str r5, [r4, #0x8] */
/* @0xc0a5c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc0a60 mov r0, r4 */
/* @0xc0a64 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0a68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0a6c mov r0, r4 */
/* @0xc0a70 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0a74 pop {r3, r4, r5, lr} */
/* @0xc0a78 b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */

/* ── FUNC 0xc0a7c · FREE_RValue__Pre(RValue*) · size=2256 · insn=564 */
/* @0xc0a7c ldr r3, [r0, #0xc] */
/* @0xc0a80 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0a84 bic r3, r3, #-16777216 */
/* @0xc0a88 sub sp, sp, #92 */
/* @0xc0a8c cmp r3, #2 */
/* @0xc0a90 str r0, [sp, #0x2c] */
/* @0xc0a94 beq 0xc0b20 <_Z16FREE_RValue__PreP6RValue+0xa4> */
/* @0xc0a98 cmp r3, #3 */
/* @0xc0a9c beq 0xc0af0 <_Z16FREE_RValue__PreP6RValue+0x74> */
/* @0xc0aa0 cmp r3, #1 */
/* @0xc0aa4 beq 0xc0ab0 <_Z16FREE_RValue__PreP6RValue+0x34> */
/* @0xc0aa8 add sp, sp, #92 */
/* @0xc0aac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc0ab0 ldr r2, [sp, #0x2c] */
/* @0xc0ab4 ldr r4, [r2] */
/* @0xc0ab8 cmp r4, #0 */
/* @0xc0abc beq 0xc0adc <_Z16FREE_RValue__PreP6RValue+0x60> */
/* @0xc0ac0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0ac4 ldr r5, [r4, #0x4] */
/* @0xc0ac8 sub r5, r5, #1 */
/* @0xc0acc str r5, [r4, #0x4] */
/* @0xc0ad0 cmp r5, #0 */
/* @0xc0ad4 beq 0xc0b78 <_Z16FREE_RValue__PreP6RValue+0xfc> */
/* @0xc0ad8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0adc ldr r1, [sp, #0x2c] */
/* @0xc0ae0 mov r3, #0 */
/* @0xc0ae4 str r3, [r1] */
/* @0xc0ae8 add sp, sp, #92 */
/* @0xc0aec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc0af0 ldr r1, [sp, #0x2c] */
/* @0xc0af4 ldr r3, [r1, #0x8] */
/* @0xc0af8 tst r3, #8 */
/* @0xc0afc beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b00 ldr r0, [r1] */
/* @0xc0b04 cmp r0, #0 */
/* @0xc0b08 beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b0c ldr r3, [r0] */
/* @0xc0b10 ldr r3, [r3, #0x4] */
/* @0xc0b14 blx r3 */
/* @0xc0b18 add sp, sp, #92 */
/* @0xc0b1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc0b20 ldr r2, [sp, #0x2c] */
/* @0xc0b24 ldr r2, [r2] */
/* @0xc0b28 cmp r2, #0 */
/* @0xc0b2c str r2, [sp, #0x38] */
/* @0xc0b30 beq 0xc0aa8 <_Z16FREE_RValue__PreP6RValue+0x2c> */
/* @0xc0b34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0b38 ldr r3, [sp, #0x38] */
/* @0xc0b3c ldr r1, [sp, #0x2c] */
/* @0xc0b40 ldr r2, [r3, #0x8] */
/* @0xc0b44 ldr r3, [r3] */
/* @0xc0b48 cmp r2, r1 */
/* @0xc0b4c ldr r2, [sp, #0x38] */
/* @0xc0b50 sub r3, r3, #1 */
/* @0xc0b54 ldreq r1, [sp, #0x38] */
/* @0xc0b58 str r3, [r2] */
/* @0xc0b5c moveq r2, #0 */
/* @0xc0b60 streq r2, [r1, #0x8] */
/* @0xc0b64 cmp r3, #0 */
/* @0xc0b68 ble 0xc0bb0 <_Z16FREE_RValue__PreP6RValue+0x134> */
/* @0xc0b6c add sp, sp, #92 */
/* @0xc0b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc0b74 b 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0b78 ldr r0, [r4] */
/* @0xc0b7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0b80 str r5, [r4] */
/* @0xc0b84 str r5, [r4, #0x8] */
/* @0xc0b88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0b8c ldr r5, [r4, #0x4] */
/* @0xc0b90 sub r5, r5, #1 */
/* @0xc0b94 str r5, [r4, #0x4] */
/* @0xc0b98 cmp r5, #0 */
/* @0xc0b9c beq 0xc12bc <_Z16FREE_RValue__PreP6RValue+0x840> */
/* @0xc0ba0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0ba4 mov r0, r4 */
/* @0xc0ba8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0bac b 0xc0ad8 <_Z16FREE_RValue__PreP6RValue+0x5c> */
/* @0xc0bb0 ldr r2, [sp, #0x38] */
/* @0xc0bb4 ldr r3, [r2, #0x10] */
/* @0xc0bb8 cmp r3, #0 */
/* @0xc0bbc movgt r3, #0 */
/* @0xc0bc0 movgt r11, #5 */
/* @0xc0bc4 strgt r3, [sp, #0x34] */
/* @0xc0bc8 movgt r10, r3 */
/* @0xc0bcc ble 0xc0cec <_Z16FREE_RValue__PreP6RValue+0x270> */
/* @0xc0bd0 ldr r1, [sp, #0x38] */
/* @0xc0bd4 ldr r2, [sp, #0x34] */
/* @0xc0bd8 ldr r3, [r1, #0x4] */
/* @0xc0bdc ldr r1, [sp, #0x34] */
/* @0xc0be0 add r2, r3, r2, lsl #3 */
/* @0xc0be4 str r2, [sp, #0x3c] */
/* @0xc0be8 ldr r3, [r3, r1, lsl #3] */
/* @0xc0bec ldr r2, [r2, #0x4] */
/* @0xc0bf0 add r3, r2, r3, lsl #4 */
/* @0xc0bf4 str r3, [sp, #0x18] */
/* @0xc0bf8 cmp r2, r3 */
/* @0xc0bfc str r2, [sp, #0x4] */
/* @0xc0c00 bhs 0xc12b4 <_Z16FREE_RValue__PreP6RValue+0x838> */
/* @0xc0c04 add r3, r2, #16 */
/* @0xc0c08 str r3, [sp, #0x8] */
/* @0xc0c0c str r3, [sp, #0xc] */
/* @0xc0c10 b 0xc0c4c <_Z16FREE_RValue__PreP6RValue+0x1d0> */
/* @0xc0c14 ldr r3, [sp, #0x18] */
/* @0xc0c18 ldr r1, [sp, #0x8] */
/* @0xc0c1c ldr r2, [sp, #0x4] */
/* @0xc0c20 cmp r3, r1 */
/* @0xc0c24 ldr r3, [sp, #0xc] */
/* @0xc0c28 str r1, [sp, #0x4] */
/* @0xc0c2c str r10, [r2, #0x8] */
/* @0xc0c30 add r3, r3, #16 */
/* @0xc0c34 str r11, [r2, #0xc] */
/* @0xc0c38 str r10, [r3, #-0x20] */
/* @0xc0c3c str r3, [sp, #0xc] */
/* @0xc0c40 bls 0xc0cb8 <_Z16FREE_RValue__PreP6RValue+0x23c> */
/* @0xc0c44 add r1, r1, #16 */
/* @0xc0c48 str r1, [sp, #0x8] */
/* @0xc0c4c ldr r1, [sp, #0x4] */
/* @0xc0c50 ldr r2, [r1, #0xc] */
/* @0xc0c54 sub r3, r2, #1 */
/* @0xc0c58 bic r3, r3, #-16777216 */
/* @0xc0c5c bics r4, r3, #3 */
/* @0xc0c60 bne 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0c64 bic r2, r2, #-16777216 */
/* @0xc0c68 cmp r2, #2 */
/* @0xc0c6c beq 0xc0d48 <_Z16FREE_RValue__PreP6RValue+0x2cc> */
/* @0xc0c70 cmp r2, #3 */
/* @0xc0c74 beq 0xc0d18 <_Z16FREE_RValue__PreP6RValue+0x29c> */
/* @0xc0c78 cmp r2, #1 */
/* @0xc0c7c bne 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0c80 ldr r1, [sp, #0xc] */
/* @0xc0c84 ldr r4, [r1, #-0x10] */
/* @0xc0c88 cmp r4, #0 */
/* @0xc0c8c beq 0xc0cac <_Z16FREE_RValue__PreP6RValue+0x230> */
/* @0xc0c90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0c94 ldr r5, [r4, #0x4] */
/* @0xc0c98 sub r5, r5, #1 */
/* @0xc0c9c str r5, [r4, #0x4] */
/* @0xc0ca0 cmp r5, #0 */
/* @0xc0ca4 beq 0xc0d94 <_Z16FREE_RValue__PreP6RValue+0x318> */
/* @0xc0ca8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0cac ldr r2, [sp, #0xc] */
/* @0xc0cb0 str r10, [r2, #-0x10] */
/* @0xc0cb4 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0cb8 ldr r2, [sp, #0x3c] */
/* @0xc0cbc ldr r0, [r2, #0x4] */
/* @0xc0cc0 ldr r3, [sp, #0x34] */
/* @0xc0cc4 add r3, r3, #1 */
/* @0xc0cc8 str r3, [sp, #0x34] */
/* @0xc0ccc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0cd0 ldr r1, [sp, #0x38] */
/* @0xc0cd4 ldr r2, [sp, #0x3c] */
/* @0xc0cd8 ldr r3, [r1, #0x10] */
/* @0xc0cdc ldr r1, [sp, #0x34] */
/* @0xc0ce0 str r10, [r2, #0x4] */
/* @0xc0ce4 cmp r3, r1 */
/* @0xc0ce8 bgt 0xc0bd0 <_Z16FREE_RValue__PreP6RValue+0x154> */
/* @0xc0cec ldr r3, [sp, #0x38] */
/* @0xc0cf0 mov r4, #0 */
/* @0xc0cf4 ldr r0, [r3, #0x4] */
/* @0xc0cf8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0cfc ldr r1, [sp, #0x38] */
/* @0xc0d00 str r4, [r1, #0x4] */
/* @0xc0d04 mov r0, r1 */
/* @0xc0d08 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0d0c ldr r2, [sp, #0x2c] */
/* @0xc0d10 str r4, [r2] */
/* @0xc0d14 b 0xc0b6c <_Z16FREE_RValue__PreP6RValue+0xf0> */
/* @0xc0d18 ldr r2, [sp, #0x4] */
/* @0xc0d1c ldr r3, [r2, #0x8] */
/* @0xc0d20 tst r3, #8 */
/* @0xc0d24 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d28 ldr r3, [sp, #0xc] */
/* @0xc0d2c ldr r0, [r3, #-0x10] */
/* @0xc0d30 cmp r0, #0 */
/* @0xc0d34 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d38 ldr r3, [r0] */
/* @0xc0d3c ldr r3, [r3, #0x4] */
/* @0xc0d40 blx r3 */
/* @0xc0d44 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d48 ldr r3, [sp, #0xc] */
/* @0xc0d4c ldr r3, [r3, #-0x10] */
/* @0xc0d50 cmp r3, #0 */
/* @0xc0d54 str r3, [sp, #0x28] */
/* @0xc0d58 beq 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0d60 ldr r1, [sp, #0x28] */
/* @0xc0d64 ldr r2, [r1, #0x8] */
/* @0xc0d68 ldr r3, [r1] */
/* @0xc0d6c ldr r1, [sp, #0x4] */
/* @0xc0d70 sub r3, r3, #1 */
/* @0xc0d74 cmp r1, r2 */
/* @0xc0d78 ldr r2, [sp, #0x28] */
/* @0xc0d7c streq r4, [r2, #0x8] */
/* @0xc0d80 cmp r3, #0 */
/* @0xc0d84 str r3, [r2] */
/* @0xc0d88 ble 0xc0dec <_Z16FREE_RValue__PreP6RValue+0x370> */
/* @0xc0d8c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0d90 b 0xc0c14 <_Z16FREE_RValue__PreP6RValue+0x198> */
/* @0xc0d94 ldr r0, [r4] */
/* @0xc0d98 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0d9c str r5, [r4] */
/* @0xc0da0 str r5, [r4, #0x8] */
/* @0xc0da4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0da8 ldr r5, [r4, #0x4] */
/* @0xc0dac sub r5, r5, #1 */
/* @0xc0db0 str r5, [r4, #0x4] */
/* @0xc0db4 cmp r5, #0 */
/* @0xc0db8 bne 0xc0ddc <_Z16FREE_RValue__PreP6RValue+0x360> */
/* @0xc0dbc ldr r0, [r4] */
/* @0xc0dc0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0dc4 mov r0, r4 */
/* @0xc0dc8 str r5, [r4] */
/* @0xc0dcc str r5, [r4, #0x8] */
/* @0xc0dd0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc0dd4 mov r0, r4 */
/* @0xc0dd8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0ddc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0de0 mov r0, r4 */
/* @0xc0de4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0de8 b 0xc0ca8 <_Z16FREE_RValue__PreP6RValue+0x22c> */
/* @0xc0dec ldr r1, [sp, #0x28] */
/* @0xc0df0 ldr r3, [r1, #0x10] */
/* @0xc0df4 cmp r3, #0 */
/* @0xc0df8 movgt r2, #0 */
/* @0xc0dfc strgt r2, [sp, #0x24] */
/* @0xc0e00 ble 0xc0efc <_Z16FREE_RValue__PreP6RValue+0x480> */
/* @0xc0e04 ldr r1, [sp, #0x28] */
/* @0xc0e08 ldr r2, [sp, #0x24] */
/* @0xc0e0c ldr r3, [r1, #0x4] */
/* @0xc0e10 ldr r1, [sp, #0x24] */
/* @0xc0e14 add r2, r3, r2, lsl #3 */
/* @0xc0e18 str r2, [sp, #0x30] */
/* @0xc0e1c ldr r3, [r3, r1, lsl #3] */
/* @0xc0e20 ldr r8, [r2, #0x4] */
/* @0xc0e24 add r3, r8, r3, lsl #4 */
/* @0xc0e28 str r3, [sp, #0x10] */
/* @0xc0e2c cmp r8, r3 */
/* @0xc0e30 bhs 0xc12ac <_Z16FREE_RValue__PreP6RValue+0x830> */
/* @0xc0e34 add r7, r8, #16 */
/* @0xc0e38 mov r9, r8 */
/* @0xc0e3c mov r8, r7 */
/* @0xc0e40 b 0xc0e68 <_Z16FREE_RValue__PreP6RValue+0x3ec> */
/* @0xc0e44 ldr r2, [sp, #0x10] */
/* @0xc0e48 add r8, r8, #16 */
/* @0xc0e4c str r10, [r9, #0x8] */
/* @0xc0e50 cmp r2, r7 */
/* @0xc0e54 str r11, [r9, #0xc] */
/* @0xc0e58 str r10, [r8, #-0x20] */
/* @0xc0e5c mov r9, r7 */
/* @0xc0e60 bls 0xc0ec8 <_Z16FREE_RValue__PreP6RValue+0x44c> */
/* @0xc0e64 add r7, r7, #16 */
/* @0xc0e68 ldr r2, [r9, #0xc] */
/* @0xc0e6c sub r3, r2, #1 */
/* @0xc0e70 bic r3, r3, #-16777216 */
/* @0xc0e74 bics r4, r3, #3 */
/* @0xc0e78 bne 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0e7c bic r2, r2, #-16777216 */
/* @0xc0e80 cmp r2, #2 */
/* @0xc0e84 beq 0xc0f4c <_Z16FREE_RValue__PreP6RValue+0x4d0> */
/* @0xc0e88 cmp r2, #3 */
/* @0xc0e8c beq 0xc0f24 <_Z16FREE_RValue__PreP6RValue+0x4a8> */
/* @0xc0e90 cmp r2, #1 */
/* @0xc0e94 bne 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0e98 ldr r4, [r8, #-0x10] */
/* @0xc0e9c cmp r4, #0 */
/* @0xc0ea0 beq 0xc0ec0 <_Z16FREE_RValue__PreP6RValue+0x444> */
/* @0xc0ea4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0ea8 ldr r5, [r4, #0x4] */
/* @0xc0eac sub r5, r5, #1 */
/* @0xc0eb0 str r5, [r4, #0x4] */
/* @0xc0eb4 cmp r5, #0 */
/* @0xc0eb8 beq 0xc0f90 <_Z16FREE_RValue__PreP6RValue+0x514> */
/* @0xc0ebc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0ec0 str r10, [r8, #-0x10] */
/* @0xc0ec4 b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0ec8 ldr r3, [sp, #0x30] */
/* @0xc0ecc ldr r0, [r3, #0x4] */
/* @0xc0ed0 ldr r1, [sp, #0x24] */
/* @0xc0ed4 add r1, r1, #1 */
/* @0xc0ed8 str r1, [sp, #0x24] */
/* @0xc0edc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0ee0 ldr r2, [sp, #0x28] */
/* @0xc0ee4 ldr r1, [sp, #0x30] */
/* @0xc0ee8 ldr r3, [r2, #0x10] */
/* @0xc0eec ldr r2, [sp, #0x24] */
/* @0xc0ef0 str r10, [r1, #0x4] */
/* @0xc0ef4 cmp r2, r3 */
/* @0xc0ef8 blt 0xc0e04 <_Z16FREE_RValue__PreP6RValue+0x388> */
/* @0xc0efc ldr r2, [sp, #0x28] */
/* @0xc0f00 ldr r0, [r2, #0x4] */
/* @0xc0f04 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0f08 ldr r3, [sp, #0x28] */
/* @0xc0f0c str r10, [r3, #0x4] */
/* @0xc0f10 mov r0, r3 */
/* @0xc0f14 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc0f18 ldr r1, [sp, #0xc] */
/* @0xc0f1c str r10, [r1, #-0x10] */
/* @0xc0f20 b 0xc0d8c <_Z16FREE_RValue__PreP6RValue+0x310> */
/* @0xc0f24 ldr r3, [r9, #0x8] */
/* @0xc0f28 tst r3, #8 */
/* @0xc0f2c beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f30 ldr r0, [r8, #-0x10] */
/* @0xc0f34 cmp r0, #0 */
/* @0xc0f38 beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f3c ldr r3, [r0] */
/* @0xc0f40 ldr r3, [r3, #0x4] */
/* @0xc0f44 blx r3 */
/* @0xc0f48 b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f4c ldr r2, [r8, #-0x10] */
/* @0xc0f50 cmp r2, #0 */
/* @0xc0f54 str r2, [sp, #0x1c] */
/* @0xc0f58 beq 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0f60 ldr r3, [sp, #0x1c] */
/* @0xc0f64 ldr r1, [sp, #0x1c] */
/* @0xc0f68 ldr r2, [r3, #0x8] */
/* @0xc0f6c ldr r3, [r3] */
/* @0xc0f70 cmp r9, r2 */
/* @0xc0f74 streq r4, [r1, #0x8] */
/* @0xc0f78 sub r3, r3, #1 */
/* @0xc0f7c str r3, [r1] */
/* @0xc0f80 cmp r3, #0 */
/* @0xc0f84 ble 0xc0fe8 <_Z16FREE_RValue__PreP6RValue+0x56c> */
/* @0xc0f88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0f8c b 0xc0e44 <_Z16FREE_RValue__PreP6RValue+0x3c8> */
/* @0xc0f90 ldr r0, [r4] */
/* @0xc0f94 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0f98 str r5, [r4] */
/* @0xc0f9c str r5, [r4, #0x8] */
/* @0xc0fa0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc0fa4 ldr r5, [r4, #0x4] */
/* @0xc0fa8 sub r5, r5, #1 */
/* @0xc0fac str r5, [r4, #0x4] */
/* @0xc0fb0 cmp r5, #0 */
/* @0xc0fb4 bne 0xc0fd8 <_Z16FREE_RValue__PreP6RValue+0x55c> */
/* @0xc0fb8 ldr r0, [r4] */
/* @0xc0fbc bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc0fc0 mov r0, r4 */
/* @0xc0fc4 str r5, [r4] */
/* @0xc0fc8 str r5, [r4, #0x8] */
/* @0xc0fcc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc0fd0 mov r0, r4 */
/* @0xc0fd4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0fd8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc0fdc mov r0, r4 */
/* @0xc0fe0 bl 0x27d1d0 <_ZdlPv> */
/* @0xc0fe4 b 0xc0ebc <_Z16FREE_RValue__PreP6RValue+0x440> */
/* @0xc0fe8 ldr r2, [sp, #0x1c] */
/* @0xc0fec ldr r3, [r2, #0x10] */
/* @0xc0ff0 cmp r3, #0 */
/* @0xc0ff4 ble 0xc1104 <_Z16FREE_RValue__PreP6RValue+0x688> */
/* @0xc0ff8 mov r2, #0 */
/* @0xc0ffc str r9, [sp, #0x4c] */
/* @0xc1000 str r2, [sp, #0x14] */
/* @0xc1004 str r8, [sp, #0x50] */
/* @0xc1008 str r7, [sp, #0x54] */
/* @0xc100c ldr r1, [sp, #0x1c] */
/* @0xc1010 ldr r2, [sp, #0x14] */
/* @0xc1014 ldr r3, [r1, #0x4] */
/* @0xc1018 ldr r1, [sp, #0x14] */
/* @0xc101c add r2, r3, r2, lsl #3 */
/* @0xc1020 str r2, [sp, #0x20] */
/* @0xc1024 ldr r5, [r3, r1, lsl #3] */
/* @0xc1028 ldr r9, [r2, #0x4] */
/* @0xc102c add r5, r9, r5, lsl #4 */
/* @0xc1030 cmp r9, r5 */
/* @0xc1034 bhs 0xc1280 <_Z16FREE_RValue__PreP6RValue+0x804> */
/* @0xc1038 add r7, r9, #16 */
/* @0xc103c mov r8, r7 */
/* @0xc1040 b 0xc1064 <_Z16FREE_RValue__PreP6RValue+0x5e8> */
/* @0xc1044 cmp r5, r7 */
/* @0xc1048 str r10, [r9, #0x8] */
/* @0xc104c str r11, [r9, #0xc] */
/* @0xc1050 add r8, r8, #16 */
/* @0xc1054 str r10, [r8, #-0x20] */
/* @0xc1058 mov r9, r7 */
/* @0xc105c bls 0xc10c4 <_Z16FREE_RValue__PreP6RValue+0x648> */
/* @0xc1060 add r7, r7, #16 */
/* @0xc1064 ldr r0, [r9, #0xc] */
/* @0xc1068 sub r1, r0, #1 */
/* @0xc106c bic r1, r1, #-16777216 */
/* @0xc1070 bics r4, r1, #3 */
/* @0xc1074 bne 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1078 bic r0, r0, #-16777216 */
/* @0xc107c cmp r0, #2 */
/* @0xc1080 beq 0xc1150 <_Z16FREE_RValue__PreP6RValue+0x6d4> */
/* @0xc1084 cmp r0, #3 */
/* @0xc1088 beq 0xc1128 <_Z16FREE_RValue__PreP6RValue+0x6ac> */
/* @0xc108c cmp r0, #1 */
/* @0xc1090 bne 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1094 ldr r4, [r8, #-0x10] */
/* @0xc1098 cmp r4, #0 */
/* @0xc109c beq 0xc10bc <_Z16FREE_RValue__PreP6RValue+0x640> */
/* @0xc10a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc10a4 ldr r6, [r4, #0x4] */
/* @0xc10a8 sub r6, r6, #1 */
/* @0xc10ac str r6, [r4, #0x4] */
/* @0xc10b0 cmp r6, #0 */
/* @0xc10b4 beq 0xc1188 <_Z16FREE_RValue__PreP6RValue+0x70c> */
/* @0xc10b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc10bc str r10, [r8, #-0x10] */
/* @0xc10c0 b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc10c4 ldr r2, [sp, #0x20] */
/* @0xc10c8 ldr r0, [r2, #0x4] */
/* @0xc10cc ldr r3, [sp, #0x14] */
/* @0xc10d0 add r3, r3, #1 */
/* @0xc10d4 str r3, [sp, #0x14] */
/* @0xc10d8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc10dc ldr r1, [sp, #0x1c] */
/* @0xc10e0 ldr r2, [sp, #0x20] */
/* @0xc10e4 ldr r3, [r1, #0x10] */
/* @0xc10e8 ldr r1, [sp, #0x14] */
/* @0xc10ec str r10, [r2, #0x4] */
/* @0xc10f0 cmp r1, r3 */
/* @0xc10f4 blt 0xc100c <_Z16FREE_RValue__PreP6RValue+0x590> */
/* @0xc10f8 ldr r9, [sp, #0x4c] */
/* @0xc10fc ldr r8, [sp, #0x50] */
/* @0xc1100 ldr r7, [sp, #0x54] */
/* @0xc1104 ldr r3, [sp, #0x1c] */
/* @0xc1108 ldr r0, [r3, #0x4] */
/* @0xc110c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1110 ldr r1, [sp, #0x1c] */
/* @0xc1114 str r10, [r1, #0x4] */
/* @0xc1118 mov r0, r1 */
/* @0xc111c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1120 str r10, [r8, #-0x10] */
/* @0xc1124 b 0xc0f88 <_Z16FREE_RValue__PreP6RValue+0x50c> */
/* @0xc1128 ldr r1, [r9, #0x8] */
/* @0xc112c tst r1, #8 */
/* @0xc1130 beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1134 ldr r0, [r8, #-0x10] */
/* @0xc1138 cmp r0, #0 */
/* @0xc113c beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1140 ldr r1, [r0] */
/* @0xc1144 ldr r1, [r1, #0x4] */
/* @0xc1148 blx r1 */
/* @0xc114c b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1150 ldr r6, [r8, #-0x10] */
/* @0xc1154 cmp r6, #0 */
/* @0xc1158 beq 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc115c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1160 ldr r1, [r6] */
/* @0xc1164 ldr r0, [r6, #0x8] */
/* @0xc1168 sub r1, r1, #1 */
/* @0xc116c str r1, [r6] */
/* @0xc1170 cmp r9, r0 */
/* @0xc1174 streq r4, [r6, #0x8] */
/* @0xc1178 cmp r1, #0 */
/* @0xc117c ble 0xc11c0 <_Z16FREE_RValue__PreP6RValue+0x744> */
/* @0xc1180 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1184 b 0xc1044 <_Z16FREE_RValue__PreP6RValue+0x5c8> */
/* @0xc1188 ldr r0, [r4] */
/* @0xc118c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1190 str r6, [r4] */
/* @0xc1194 str r6, [r4, #0x8] */
/* @0xc1198 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc119c ldr r6, [r4, #0x4] */
/* @0xc11a0 sub r6, r6, #1 */
/* @0xc11a4 str r6, [r4, #0x4] */
/* @0xc11a8 cmp r6, #0 */
/* @0xc11ac beq 0xc1288 <_Z16FREE_RValue__PreP6RValue+0x80c> */
/* @0xc11b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc11b4 mov r0, r4 */
/* @0xc11b8 bl 0x27d1d0 <_ZdlPv> */
/* @0xc11bc b 0xc10b8 <_Z16FREE_RValue__PreP6RValue+0x63c> */
/* @0xc11c0 ldr r1, [r6, #0x10] */
/* @0xc11c4 cmp r1, #0 */
/* @0xc11c8 strgt r5, [sp, #0x40] */
/* @0xc11cc strgt r8, [sp, #0x44] */
/* @0xc11d0 movgt r4, #0 */
/* @0xc11d4 strgt r7, [sp, #0x48] */
/* @0xc11d8 ble 0xc125c <_Z16FREE_RValue__PreP6RValue+0x7e0> */
/* @0xc11dc ldr r3, [r6, #0x4] */
/* @0xc11e0 add r5, r3, r4, lsl #3 */
/* @0xc11e4 ldr r1, [r3, r4, lsl #3] */
/* @0xc11e8 ldr r7, [r5, #0x4] */
/* @0xc11ec add r8, r7, r1, lsl #4 */
/* @0xc11f0 cmp r7, r8 */
/* @0xc11f4 blo 0xc1210 <_Z16FREE_RValue__PreP6RValue+0x794> */
/* @0xc11f8 b 0xc1278 <_Z16FREE_RValue__PreP6RValue+0x7fc> */
/* @0xc11fc str r10, [r7, #0x8] */
/* @0xc1200 str r11, [r7, #0xc] */
/* @0xc1204 str r10, [r7], #16 */
/* @0xc1208 cmp r8, r7 */
/* @0xc120c bls 0xc1234 <_Z16FREE_RValue__PreP6RValue+0x7b8> */
/* @0xc1210 ldr r3, [r7, #0xc] */
/* @0xc1214 sub r3, r3, #1 */
/* @0xc1218 bic r3, r3, #-16777216 */
/* @0xc121c bic r3, r3, #3 */
/* @0xc1220 cmp r3, #0 */
/* @0xc1224 bne 0xc11fc <_Z16FREE_RValue__PreP6RValue+0x780> */
/* @0xc1228 mov r0, r7 */
/* @0xc122c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1230 b 0xc11fc <_Z16FREE_RValue__PreP6RValue+0x780> */
/* @0xc1234 ldr r0, [r5, #0x4] */
/* @0xc1238 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc123c ldr r3, [r6, #0x10] */
/* @0xc1240 add r4, r4, #1 */
/* @0xc1244 str r10, [r5, #0x4] */
/* @0xc1248 cmp r4, r3 */
/* @0xc124c blt 0xc11dc <_Z16FREE_RValue__PreP6RValue+0x760> */
/* @0xc1250 ldr r5, [sp, #0x40] */
/* @0xc1254 ldr r8, [sp, #0x44] */
/* @0xc1258 ldr r7, [sp, #0x48] */
/* @0xc125c ldr r0, [r6, #0x4] */
/* @0xc1260 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1264 str r10, [r6, #0x4] */
/* @0xc1268 mov r0, r6 */
/* @0xc126c bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1270 str r10, [r8, #-0x10] */
/* @0xc1274 b 0xc1180 <_Z16FREE_RValue__PreP6RValue+0x704> */
/* @0xc1278 mov r0, r7 */
/* @0xc127c b 0xc1238 <_Z16FREE_RValue__PreP6RValue+0x7bc> */
/* @0xc1280 mov r0, r9 */
/* @0xc1284 b 0xc10cc <_Z16FREE_RValue__PreP6RValue+0x650> */
/* @0xc1288 ldr r0, [r4] */
/* @0xc128c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1290 mov r0, r4 */
/* @0xc1294 str r6, [r4] */
/* @0xc1298 str r6, [r4, #0x8] */
/* @0xc129c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc12a0 mov r0, r4 */
/* @0xc12a4 bl 0x27d1d0 <_ZdlPv> */
/* @0xc12a8 b 0xc11b0 <_Z16FREE_RValue__PreP6RValue+0x734> */
/* @0xc12ac mov r0, r8 */
/* @0xc12b0 b 0xc0ed0 <_Z16FREE_RValue__PreP6RValue+0x454> */
/* @0xc12b4 ldr r0, [sp, #0x4] */
/* @0xc12b8 b 0xc0cc0 <_Z16FREE_RValue__PreP6RValue+0x244> */
/* @0xc12bc ldr r0, [r4] */
/* @0xc12c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc12c4 str r5, [r4] */
/* @0xc12c8 str r5, [r4, #0x8] */
/* @0xc12cc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc12d0 ldr r5, [r4, #0x4] */
/* @0xc12d4 sub r5, r5, #1 */
/* @0xc12d8 str r5, [r4, #0x4] */
/* @0xc12dc cmp r5, #0 */
/* @0xc12e0 beq 0xc12f4 <_Z16FREE_RValue__PreP6RValue+0x878> */
/* @0xc12e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc12e8 mov r0, r4 */
/* @0xc12ec bl 0x27d1d0 <_ZdlPv> */
/* @0xc12f0 b 0xc0ba0 <_Z16FREE_RValue__PreP6RValue+0x124> */
/* @0xc12f4 ldr r0, [r4] */
/* @0xc12f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc12fc str r5, [r4] */
/* @0xc1300 str r5, [r4, #0x8] */
/* @0xc1304 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1308 ldr r5, [r4, #0x4] */
/* @0xc130c sub r5, r5, #1 */
/* @0xc1310 str r5, [r4, #0x4] */
/* @0xc1314 cmp r5, #0 */
/* @0xc1318 bne 0xc133c <_Z16FREE_RValue__PreP6RValue+0x8c0> */
/* @0xc131c ldr r0, [r4] */
/* @0xc1320 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1324 mov r0, r4 */
/* @0xc1328 str r5, [r4] */
/* @0xc132c str r5, [r4, #0x8] */
/* @0xc1330 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc1334 mov r0, r4 */
/* @0xc1338 bl 0x27d1d0 <_ZdlPv> */
/* @0xc133c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1340 mov r0, r4 */
/* @0xc1344 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1348 b 0xc12e4 <_Z16FREE_RValue__PreP6RValue+0x868> */

/* ── FUNC 0xc134c · anon_c134c · size=4 · insn=1 */
/* @0xc134c andeq r0, r0, r0 */

/* ── FUNC 0xc1350 · CSkeletonSprite::GetSlotData(CDS_List*) · size=304 · insn=74 */
/* @0xc1350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc1354 vpush {d8} */
/* @0xc1358 subs r7, r1, #0 */
/* @0xc135c sub sp, sp, #60 */
/* @0xc1360 mov r6, r0 */
/* @0xc1364 beq 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c> */
/* @0xc1368 ldr r3, [r0, #0x4] */
/* @0xc136c ldr r2, [r3, #0x18] */
/* @0xc1370 cmp r2, #0 */
/* @0xc1374 ble 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c> */
/* @0xc1378 ldr r11, [pc, #0xf0] */
/* @0xc137c add r5, sp, #40 */
/* @0xc1380 ldr r10, [pc, #0xec] */
/* @0xc1384 mov r4, #0 */
/* @0xc1388 ldr r9, [pc, #0xe8] */
/* @0xc138c add r11, pc, r11 */
/* @0xc1390 ldr r8, [pc, #0xe4] */
/* @0xc1394 add r10, pc, r10 */
/* @0xc1398 add r9, pc, r9 */
/* @0xc139c vldr d8, [pc, #196] */
/* @0xc13a0 add r8, pc, r8 */
/* @0xc13a4 b 0xc13b8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x68> */
/* @0xc13a8 ldr r3, [r6, #0x4] */
/* @0xc13ac ldr r2, [r3, #0x18] */
/* @0xc13b0 cmp r2, r4 */
/* @0xc13b4 ble 0xc145c <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x10c> */
/* @0xc13b8 ldr r3, [r3, #0x1c] */
/* @0xc13bc mov r1, r10 */
/* @0xc13c0 mov r0, #3 */
/* @0xc13c4 ldr r2, [r3, r4, lsl #2] */
/* @0xc13c8 add r4, r4, #1 */
/* @0xc13cc ldr lr, [r2, #0x8] */
/* @0xc13d0 ldr r3, [r2, #0xc] */
/* @0xc13d4 ldr r12, [r2, #0x4] */
/* @0xc13d8 ldr r2, [lr, #0x4] */
/* @0xc13dc cmp r3, #0 */
/* @0xc13e0 str r9, [sp, #0x4] */
/* @0xc13e4 vstr d8, [sp, #8] */
/* @0xc13e8 moveq r3, r11 */
/* @0xc13ec str r12, [sp] */
/* @0xc13f0 str r2, [sp, #0x10] */
/* @0xc13f4 vstr d8, [sp, #24] */
/* @0xc13f8 str r3, [sp, #0x20] */
/* @0xc13fc mov r2, #0 */
/* @0xc1400 mov r3, #0 */
/* @0xc1404 str r8, [sp, #0x14] */
/* @0xc1408 bl 0x20bdc0 <_Z11CreateDsMapiz> */
/* @0xc140c mov r1, r5 */
/* @0xc1410 mov r3, #0 */
/* @0xc1414 str r3, [sp, #0x34] */
/* @0xc1418 vmov s13, r0 */
/* @0xc141c mov r0, r7 */
/* @0xc1420 vcvt.f64.s32 d7, s13 */
/* @0xc1424 vstr d7, [sp, #40] */
/* @0xc1428 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0xc142c ldr r3, [sp, #0x34] */
/* @0xc1430 sub r3, r3, #1 */
/* @0xc1434 bic r3, r3, #-16777216 */
/* @0xc1438 bic r3, r3, #3 */
/* @0xc143c cmp r3, #0 */
/* @0xc1440 bne 0xc13a8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x58> */
/* @0xc1444 mov r0, r5 */
/* @0xc1448 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc144c ldr r3, [r6, #0x4] */
/* @0xc1450 ldr r2, [r3, #0x18] */
/* @0xc1454 cmp r2, r4 */
/* @0xc1458 bgt 0xc13b8 <_ZN15CSkeletonSprite11GetSlotDataEP8CDS_List+0x68> */
/* @0xc145c add sp, sp, #60 */
/* @0xc1460 vpop {d8} */
/* @0xc1464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc1470 eoreq pc, r6, r0, lsr #11 */
/* @0xc1474 eoreq pc, r6, r4, ror r4 */
/* @0xc1478 mlaeq r6, r12, r5, pc */
/* @0xc147c mlaeq r6, r12, r5, pc */

/* ── FUNC 0xc1480 · CSkeletonInstance::SetBoneState(char const*, int) · size=576 · insn=144 */
/* @0xc1480 push {r4, r5, r6, r7, lr} */
/* @0xc1484 sub sp, sp, #28 */
/* @0xc1488 ldr r0, [r0, #0x1c] */
/* @0xc148c mov r4, r2 */
/* @0xc1490 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0xc1494 subs r5, r0, #0 */
/* @0xc1498 moveq r0, r5 */
/* @0xc149c beq 0xc1650 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1d0> */
/* @0xc14a0 add r6, sp, #4 */
/* @0xc14a4 mov r0, r6 */
/* @0xc14a8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xc14ac ldr r3, [pc, #0x1f4] */
/* @0xc14b0 ldr r3, [pc, r3] */
/* @0xc14b4 ldr r3, [r3, #0x4] */
/* @0xc14b8 ldr r7, [r3, r4, lsl #2] */
/* @0xc14bc cmp r7, #0 */
/* @0xc14c0 beq 0xc1694 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x214> */
/* @0xc14c4 add r4, sp, #8 */
/* @0xc14c8 ldr r1, [pc, #0x1dc] */
/* @0xc14cc mov r0, r4 */
/* @0xc14d0 add r1, pc, r1 */
/* @0xc14d4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc14d8 mov r0, r7 */
/* @0xc14dc mov r1, r4 */
/* @0xc14e0 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc14e4 cmp r0, #0 */
/* @0xc14e8 ldrne r3, [r0, #0x14] */
/* @0xc14ec ldrne r2, [r0, #0x10] */
/* @0xc14f0 vmovne d6, r2, r3 */
/* @0xc14f4 ldr r3, [sp, #0x14] */
/* @0xc14f8 vcvtne.f32.f64 s15, d6 */
/* @0xc14fc sub r3, r3, #1 */
/* @0xc1500 bic r3, r3, #-16777216 */
/* @0xc1504 bic r3, r3, #3 */
/* @0xc1508 vstrne s15, [r5, #20] */
/* @0xc150c cmp r3, #0 */
/* @0xc1510 beq 0xc1688 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x208> */
/* @0xc1514 ldr r1, [pc, #0x194] */
/* @0xc1518 mov r0, r4 */
/* @0xc151c add r1, pc, r1 */
/* @0xc1520 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc1524 mov r0, r7 */
/* @0xc1528 mov r1, r4 */
/* @0xc152c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1530 cmp r0, #0 */
/* @0xc1534 ldrne r3, [r0, #0x14] */
/* @0xc1538 ldrne r2, [r0, #0x10] */
/* @0xc153c vmovne d6, r2, r3 */
/* @0xc1540 ldr r3, [sp, #0x14] */
/* @0xc1544 vcvtne.f32.f64 s15, d6 */
/* @0xc1548 sub r3, r3, #1 */
/* @0xc154c bic r3, r3, #-16777216 */
/* @0xc1550 bic r3, r3, #3 */
/* @0xc1554 vstrne s15, [r5, #24] */
/* @0xc1558 cmp r3, #0 */
/* @0xc155c beq 0xc167c <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1fc> */
/* @0xc1560 ldr r1, [pc, #0x14c] */
/* @0xc1564 mov r0, r4 */
/* @0xc1568 add r1, pc, r1 */
/* @0xc156c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc1570 mov r0, r7 */
/* @0xc1574 mov r1, r4 */
/* @0xc1578 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc157c cmp r0, #0 */
/* @0xc1580 ldrne r3, [r0, #0x14] */
/* @0xc1584 ldrne r2, [r0, #0x10] */
/* @0xc1588 vmovne d6, r2, r3 */
/* @0xc158c ldr r3, [sp, #0x14] */
/* @0xc1590 vcvtne.f32.f64 s15, d6 */
/* @0xc1594 sub r3, r3, #1 */
/* @0xc1598 bic r3, r3, #-16777216 */
/* @0xc159c bic r3, r3, #3 */
/* @0xc15a0 vstrne s15, [r5, #28] */
/* @0xc15a4 cmp r3, #0 */
/* @0xc15a8 beq 0xc1670 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1f0> */
/* @0xc15ac ldr r1, [pc, #0x104] */
/* @0xc15b0 mov r0, r4 */
/* @0xc15b4 add r1, pc, r1 */
/* @0xc15b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc15bc mov r0, r7 */
/* @0xc15c0 mov r1, r4 */
/* @0xc15c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc15c8 cmp r0, #0 */
/* @0xc15cc ldrne r3, [r0, #0x14] */
/* @0xc15d0 ldrne r2, [r0, #0x10] */
/* @0xc15d4 vmovne d6, r2, r3 */
/* @0xc15d8 ldr r3, [sp, #0x14] */
/* @0xc15dc vcvtne.f32.f64 s15, d6 */
/* @0xc15e0 sub r3, r3, #1 */
/* @0xc15e4 bic r3, r3, #-16777216 */
/* @0xc15e8 bic r3, r3, #3 */
/* @0xc15ec vstrne s15, [r5, #32] */
/* @0xc15f0 cmp r3, #0 */
/* @0xc15f4 beq 0xc1664 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1e4> */
/* @0xc15f8 ldr r1, [pc, #0xbc] */
/* @0xc15fc mov r0, r4 */
/* @0xc1600 add r1, pc, r1 */
/* @0xc1604 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc1608 mov r0, r7 */
/* @0xc160c mov r1, r4 */
/* @0xc1610 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1614 cmp r0, #0 */
/* @0xc1618 ldrne r3, [r0, #0x14] */
/* @0xc161c ldrne r2, [r0, #0x10] */
/* @0xc1620 vmovne d6, r2, r3 */
/* @0xc1624 ldr r3, [sp, #0x14] */
/* @0xc1628 vcvtne.f32.f64 s15, d6 */
/* @0xc162c sub r3, r3, #1 */
/* @0xc1630 bic r3, r3, #-16777216 */
/* @0xc1634 bic r3, r3, #3 */
/* @0xc1638 vstrne s15, [r5, #36] */
/* @0xc163c cmp r3, #0 */
/* @0xc1640 beq 0xc1658 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1d8> */
/* @0xc1644 mov r0, r6 */
/* @0xc1648 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc164c mov r0, #1 */
/* @0xc1650 add sp, sp, #28 */
/* @0xc1654 pop {r4, r5, r6, r7, pc} */
/* @0xc1658 mov r0, r4 */
/* @0xc165c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1660 b 0xc1644 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x1c4> */
/* @0xc1664 mov r0, r4 */
/* @0xc1668 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc166c b 0xc15f8 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x178> */
/* @0xc1670 mov r0, r4 */
/* @0xc1674 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1678 b 0xc15ac <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x12c> */
/* @0xc167c mov r0, r4 */
/* @0xc1680 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1684 b 0xc1560 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0xe0> */
/* @0xc1688 mov r0, r4 */
/* @0xc168c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1690 b 0xc1514 <_ZN17CSkeletonInstance12SetBoneStateEPKci+0x94> */
/* @0xc1694 mov r0, r6 */
/* @0xc1698 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc169c mov r0, r7 */
/* @0xc16a0 add sp, sp, #28 */
/* @0xc16a4 pop {r4, r5, r6, r7, pc} */
/* @0xc16a8 eorseq r12, r2, r12, lsl #9 */
/* @0xc16ac eoreq pc, r6, r4, lsr #7 */
/* @0xc16b0 eoreq pc, r6, r12, asr r3 */
/* @0xc16b4 eoreq pc, r6, r4, lsl r3 */
/* @0xc16b8 .word 0x0026f2d0 */
/* @0xc16bc eoreq pc, r6, r12, lsl #5 */

/* ── FUNC 0xc16c0 · CSkeletonInstance::SetBoneData(char const*, int) · size=692 · insn=173 */
/* @0xc16c0 push {r4, r5, r6, r7, r8, lr} */
/* @0xc16c4 sub sp, sp, #24 */
/* @0xc16c8 ldr r0, [r0, #0x1c] */
/* @0xc16cc mov r4, r2 */
/* @0xc16d0 bl 0x28a0c8 <spSkeleton_findBone> */
/* @0xc16d4 subs r7, r0, #0 */
/* @0xc16d8 moveq r0, r7 */
/* @0xc16dc beq 0xc18f4 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x234> */
/* @0xc16e0 add r5, sp, #4 */
/* @0xc16e4 mov r0, r5 */
/* @0xc16e8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0xc16ec ldr r3, [pc, #0x264] */
/* @0xc16f0 ldr r3, [pc, r3] */
/* @0xc16f4 ldr r3, [r3, #0x4] */
/* @0xc16f8 ldr r6, [r3, r4, lsl #2] */
/* @0xc16fc cmp r6, #0 */
/* @0xc1700 beq 0xc1944 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x284> */
/* @0xc1704 add r4, sp, #8 */
/* @0xc1708 ldr r1, [pc, #0x24c] */
/* @0xc170c ldr r8, [r7] */
/* @0xc1710 add r1, pc, r1 */
/* @0xc1714 mov r0, r4 */
/* @0xc1718 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc171c mov r0, r6 */
/* @0xc1720 mov r1, r4 */
/* @0xc1724 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1728 cmp r0, #0 */
/* @0xc172c ldrne r3, [r0, #0x14] */
/* @0xc1730 ldrne r2, [r0, #0x10] */
/* @0xc1734 vmovne d6, r2, r3 */
/* @0xc1738 ldr r3, [sp, #0x14] */
/* @0xc173c vcvtne.f32.f64 s15, d6 */
/* @0xc1740 sub r3, r3, #1 */
/* @0xc1744 bic r3, r3, #-16777216 */
/* @0xc1748 bic r3, r3, #3 */
/* @0xc174c vstrne s15, [r8, #12] */
/* @0xc1750 cmp r3, #0 */
/* @0xc1754 beq 0xc1938 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x278> */
/* @0xc1758 ldr r1, [pc, #0x200] */
/* @0xc175c mov r0, r4 */
/* @0xc1760 ldr r8, [r7] */
/* @0xc1764 add r1, pc, r1 */
/* @0xc1768 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc176c mov r0, r6 */
/* @0xc1770 mov r1, r4 */
/* @0xc1774 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1778 cmp r0, #0 */
/* @0xc177c ldrne r3, [r0, #0x14] */
/* @0xc1780 ldrne r2, [r0, #0x10] */
/* @0xc1784 vmovne d6, r2, r3 */
/* @0xc1788 ldr r3, [sp, #0x14] */
/* @0xc178c vcvtne.f32.f64 s15, d6 */
/* @0xc1790 sub r3, r3, #1 */
/* @0xc1794 bic r3, r3, #-16777216 */
/* @0xc1798 bic r3, r3, #3 */
/* @0xc179c vstrne s15, [r8, #16] */
/* @0xc17a0 cmp r3, #0 */
/* @0xc17a4 beq 0xc192c <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x26c> */
/* @0xc17a8 ldr r1, [pc, #0x1b4] */
/* @0xc17ac mov r0, r4 */
/* @0xc17b0 ldr r8, [r7] */
/* @0xc17b4 add r1, pc, r1 */
/* @0xc17b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc17bc mov r0, r6 */
/* @0xc17c0 mov r1, r4 */
/* @0xc17c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc17c8 cmp r0, #0 */
/* @0xc17cc ldrne r3, [r0, #0x14] */
/* @0xc17d0 ldrne r2, [r0, #0x10] */
/* @0xc17d4 vmovne d6, r2, r3 */
/* @0xc17d8 ldr r3, [sp, #0x14] */
/* @0xc17dc vcvtne.f32.f64 s15, d6 */
/* @0xc17e0 sub r3, r3, #1 */
/* @0xc17e4 bic r3, r3, #-16777216 */
/* @0xc17e8 bic r3, r3, #3 */
/* @0xc17ec vstrne s15, [r8, #20] */
/* @0xc17f0 cmp r3, #0 */
/* @0xc17f4 beq 0xc1920 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x260> */
/* @0xc17f8 ldr r1, [pc, #0x168] */
/* @0xc17fc mov r0, r4 */
/* @0xc1800 ldr r8, [r7] */
/* @0xc1804 add r1, pc, r1 */
/* @0xc1808 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc180c mov r0, r6 */
/* @0xc1810 mov r1, r4 */
/* @0xc1814 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1818 cmp r0, #0 */
/* @0xc181c ldrne r3, [r0, #0x14] */
/* @0xc1820 ldrne r2, [r0, #0x10] */
/* @0xc1824 vmovne d6, r2, r3 */
/* @0xc1828 ldr r3, [sp, #0x14] */
/* @0xc182c vcvtne.f32.f64 s15, d6 */
/* @0xc1830 sub r3, r3, #1 */
/* @0xc1834 bic r3, r3, #-16777216 */
/* @0xc1838 bic r3, r3, #3 */
/* @0xc183c vstrne s15, [r8, #24] */
/* @0xc1840 cmp r3, #0 */
/* @0xc1844 beq 0xc1914 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x254> */
/* @0xc1848 ldr r1, [pc, #0x11c] */
/* @0xc184c mov r0, r4 */
/* @0xc1850 ldr r8, [r7] */
/* @0xc1854 add r1, pc, r1 */
/* @0xc1858 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc185c mov r0, r6 */
/* @0xc1860 mov r1, r4 */
/* @0xc1864 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc1868 cmp r0, #0 */
/* @0xc186c ldrne r3, [r0, #0x14] */
/* @0xc1870 ldrne r2, [r0, #0x10] */
/* @0xc1874 vmovne d6, r2, r3 */
/* @0xc1878 ldr r3, [sp, #0x14] */
/* @0xc187c vcvtne.f32.f64 s15, d6 */
/* @0xc1880 sub r3, r3, #1 */
/* @0xc1884 bic r3, r3, #-16777216 */
/* @0xc1888 bic r3, r3, #3 */
/* @0xc188c vstrne s15, [r8, #28] */
/* @0xc1890 cmp r3, #0 */
/* @0xc1894 beq 0xc1908 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x248> */
/* @0xc1898 ldr r1, [pc, #0xd0] */
/* @0xc189c mov r0, r4 */
/* @0xc18a0 ldr r7, [r7] */
/* @0xc18a4 add r1, pc, r1 */
/* @0xc18a8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc18ac mov r0, r6 */
/* @0xc18b0 mov r1, r4 */
/* @0xc18b4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0xc18b8 cmp r0, #0 */
/* @0xc18bc ldrne r3, [r0, #0x14] */
/* @0xc18c0 ldrne r2, [r0, #0x10] */
/* @0xc18c4 vmovne d6, r2, r3 */
/* @0xc18c8 ldr r3, [sp, #0x14] */
/* @0xc18cc vcvtne.f32.f64 s15, d6 */
/* @0xc18d0 sub r3, r3, #1 */
/* @0xc18d4 bic r3, r3, #-16777216 */
/* @0xc18d8 bic r3, r3, #3 */
/* @0xc18dc vstrne s15, [r7, #32] */
/* @0xc18e0 cmp r3, #0 */
/* @0xc18e4 beq 0xc18fc <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x23c> */
/* @0xc18e8 mov r0, r5 */
/* @0xc18ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc18f0 mov r0, #1 */
/* @0xc18f4 add sp, sp, #24 */
/* @0xc18f8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc18fc mov r0, r4 */
/* @0xc1900 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1904 b 0xc18e8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x228> */
/* @0xc1908 mov r0, r4 */
/* @0xc190c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1910 b 0xc1898 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x1d8> */
/* @0xc1914 mov r0, r4 */
/* @0xc1918 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc191c b 0xc1848 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x188> */
/* @0xc1920 mov r0, r4 */
/* @0xc1924 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1928 b 0xc17f8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x138> */
/* @0xc192c mov r0, r4 */
/* @0xc1930 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1934 b 0xc17a8 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0xe8> */
/* @0xc1938 mov r0, r4 */
/* @0xc193c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1940 b 0xc1758 <_ZN17CSkeletonInstance11SetBoneDataEPKci+0x98> */
/* @0xc1944 mov r0, r5 */
/* @0xc1948 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0xc194c mov r0, r6 */
/* @0xc1950 add sp, sp, #24 */
/* @0xc1954 pop {r4, r5, r6, r7, r8, pc} */
/* @0xc1958 eorseq r12, r2, r12, asr #4 */
/* @0xc195c eoreq pc, r6, r12, asr r1 */
/* @0xc1960 eoreq pc, r6, r0, lsl r1 */
/* @0xc1964 eoreq pc, r6, r4, asr #1 */
/* @0xc1968 eoreq pc, r6, r8, ror r0 */
/* @0xc196c eoreq pc, r6, r0, lsr r0 */
/* @0xc1970 eoreq lr, r6, r8, ror #31 */

/* ── FUNC 0xc1974 · CSkeletonSprite::GetSkinList(CDS_List*) · size=612 · insn=153 */
/* @0xc1974 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc1978 subs r8, r1, #0 */
/* @0xc197c sub sp, sp, #36 */
/* @0xc1980 mov r7, r0 */
/* @0xc1984 beq 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8> */
/* @0xc1988 ldr r3, [r0, #0x4] */
/* @0xc198c ldr r2, [r3, #0x20] */
/* @0xc1990 cmp r2, #0 */
/* @0xc1994 ble 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8> */
/* @0xc1998 mov r11, #0 */
/* @0xc199c add r5, sp, #16 */
/* @0xc19a0 mov r4, r11 */
/* @0xc19a4 mov r6, #5 */
/* @0xc19a8 b 0xc19c0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x4c> */
/* @0xc19ac ldr r3, [r7, #0x4] */
/* @0xc19b0 add r11, r11, #1 */
/* @0xc19b4 ldr r1, [r3, #0x20] */
/* @0xc19b8 cmp r1, r11 */
/* @0xc19bc ble 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8> */
/* @0xc19c0 ldr r3, [r3, #0x24] */
/* @0xc19c4 mov r0, r5 */
/* @0xc19c8 ldr r3, [r3, r11, lsl #2] */
/* @0xc19cc ldr r1, [r3] */
/* @0xc19d0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc19d4 mov r1, r5 */
/* @0xc19d8 mov r0, r8 */
/* @0xc19dc bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0xc19e0 ldr r1, [sp, #0x1c] */
/* @0xc19e4 sub r3, r1, #1 */
/* @0xc19e8 bic r3, r3, #-16777216 */
/* @0xc19ec bics r9, r3, #3 */
/* @0xc19f0 bne 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc19f4 bic r1, r1, #-16777216 */
/* @0xc19f8 cmp r1, #2 */
/* @0xc19fc beq 0xc1a6c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xf8> */
/* @0xc1a00 cmp r1, #3 */
/* @0xc1a04 beq 0xc1a44 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xd0> */
/* @0xc1a08 cmp r1, #1 */
/* @0xc1a0c bne 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a10 ldr r9, [sp, #0x10] */
/* @0xc1a14 cmp r9, #0 */
/* @0xc1a18 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1a20 ldr r10, [r9, #0x4] */
/* @0xc1a24 sub r10, r10, #1 */
/* @0xc1a28 str r10, [r9, #0x4] */
/* @0xc1a2c cmp r10, #0 */
/* @0xc1a30 beq 0xc1b20 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1ac> */
/* @0xc1a34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1a38 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a3c add sp, sp, #36 */
/* @0xc1a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc1a44 ldr r3, [sp, #0x18] */
/* @0xc1a48 tst r3, #8 */
/* @0xc1a4c beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a50 ldr r0, [sp, #0x10] */
/* @0xc1a54 cmp r0, #0 */
/* @0xc1a58 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a5c ldr r3, [r0] */
/* @0xc1a60 ldr r3, [r3, #0x4] */
/* @0xc1a64 blx r3 */
/* @0xc1a68 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a6c ldr r10, [sp, #0x10] */
/* @0xc1a70 cmp r10, #0 */
/* @0xc1a74 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1a78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1a7c ldr r3, [r10] */
/* @0xc1a80 ldr r1, [r10, #0x8] */
/* @0xc1a84 sub r3, r3, #1 */
/* @0xc1a88 str r3, [r10] */
/* @0xc1a8c cmp r1, r5 */
/* @0xc1a90 streq r9, [r10, #0x8] */
/* @0xc1a94 cmp r3, #0 */
/* @0xc1a98 bgt 0xc1a34 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc0> */
/* @0xc1a9c ldr r3, [r10, #0x10] */
/* @0xc1aa0 cmp r3, #0 */
/* @0xc1aa4 movgt r2, #0 */
/* @0xc1aa8 strgt r2, [sp, #0x8] */
/* @0xc1aac ble 0xc1bb0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x23c> */
/* @0xc1ab0 ldr r2, [sp, #0x8] */
/* @0xc1ab4 ldr r3, [r10, #0x4] */
/* @0xc1ab8 add r2, r3, r2, lsl #3 */
/* @0xc1abc str r2, [sp, #0xc] */
/* @0xc1ac0 ldr r2, [sp, #0x8] */
/* @0xc1ac4 ldr r12, [r3, r2, lsl #3] */
/* @0xc1ac8 ldr r3, [sp, #0xc] */
/* @0xc1acc ldr r9, [r3, #0x4] */
/* @0xc1ad0 add r12, r9, r12, lsl #4 */
/* @0xc1ad4 cmp r9, r12 */
/* @0xc1ad8 blo 0xc1af4 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x180> */
/* @0xc1adc b 0xc1bd0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x25c> */
/* @0xc1ae0 str r4, [r9, #0x8] */
/* @0xc1ae4 str r6, [r9, #0xc] */
/* @0xc1ae8 str r4, [r9], #16 */
/* @0xc1aec cmp r12, r9 */
/* @0xc1af0 bls 0xc1b80 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x20c> */
/* @0xc1af4 ldr r1, [r9, #0xc] */
/* @0xc1af8 sub r1, r1, #1 */
/* @0xc1afc bic r1, r1, #-16777216 */
/* @0xc1b00 bic r1, r1, #3 */
/* @0xc1b04 cmp r1, #0 */
/* @0xc1b08 bne 0xc1ae0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x16c> */
/* @0xc1b0c mov r0, r9 */
/* @0xc1b10 str r12, [sp, #0x4] */
/* @0xc1b14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1b18 ldr r12, [sp, #0x4] */
/* @0xc1b1c b 0xc1ae0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x16c> */
/* @0xc1b20 ldr r0, [r9] */
/* @0xc1b24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1b28 str r10, [r9] */
/* @0xc1b2c str r10, [r9, #0x8] */
/* @0xc1b30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1b34 ldr r10, [r9, #0x4] */
/* @0xc1b38 sub r10, r10, #1 */
/* @0xc1b3c str r10, [r9, #0x4] */
/* @0xc1b40 cmp r10, #0 */
/* @0xc1b44 beq 0xc1b5c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1e8> */
/* @0xc1b48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1b4c mov r0, r9 */
/* @0xc1b50 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1b54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1b58 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1b5c ldr r0, [r9] */
/* @0xc1b60 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1b64 mov r0, r9 */
/* @0xc1b68 str r10, [r9] */
/* @0xc1b6c str r10, [r9, #0x8] */
/* @0xc1b70 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc1b74 mov r0, r9 */
/* @0xc1b78 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1b7c b 0xc1b48 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1d4> */
/* @0xc1b80 ldr r2, [sp, #0xc] */
/* @0xc1b84 ldr r0, [r2, #0x4] */
/* @0xc1b88 ldr r3, [sp, #0x8] */
/* @0xc1b8c add r3, r3, #1 */
/* @0xc1b90 str r3, [sp, #0x8] */
/* @0xc1b94 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1b98 ldr r2, [sp, #0xc] */
/* @0xc1b9c ldr r3, [r10, #0x10] */
/* @0xc1ba0 str r4, [r2, #0x4] */
/* @0xc1ba4 ldr r2, [sp, #0x8] */
/* @0xc1ba8 cmp r2, r3 */
/* @0xc1bac blt 0xc1ab0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x13c> */
/* @0xc1bb0 ldr r0, [r10, #0x4] */
/* @0xc1bb4 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1bb8 str r4, [r10, #0x4] */
/* @0xc1bbc mov r0, r10 */
/* @0xc1bc0 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1bc4 str r4, [sp, #0x10] */
/* @0xc1bc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1bcc b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38> */
/* @0xc1bd0 mov r0, r9 */
/* @0xc1bd4 b 0xc1b88 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x214> */

/* ── FUNC 0xc1bd8 · CSkeletonSprite::GetAnimationList(CDS_List*) · size=612 · insn=153 */
/* @0xc1bd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc1bdc subs r8, r1, #0 */
/* @0xc1be0 sub sp, sp, #36 */
/* @0xc1be4 mov r7, r0 */
/* @0xc1be8 beq 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100> */
/* @0xc1bec ldr r3, [r0, #0x4] */
/* @0xc1bf0 cmp r3, #0 */
/* @0xc1bf4 beq 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100> */
/* @0xc1bf8 ldr r2, [r3, #0x34] */
/* @0xc1bfc cmp r2, #0 */
/* @0xc1c00 ble 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100> */
/* @0xc1c04 mov r11, #0 */
/* @0xc1c08 add r5, sp, #16 */
/* @0xc1c0c mov r4, r11 */
/* @0xc1c10 mov r6, #5 */
/* @0xc1c14 b 0xc1c2c <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x54> */
/* @0xc1c18 ldr r3, [r7, #0x4] */
/* @0xc1c1c add r11, r11, #1 */
/* @0xc1c20 ldr r1, [r3, #0x34] */
/* @0xc1c24 cmp r1, r11 */
/* @0xc1c28 ble 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100> */
/* @0xc1c2c ldr r3, [r3, #0x38] */
/* @0xc1c30 mov r0, r5 */
/* @0xc1c34 ldr r3, [r3, r11, lsl #2] */
/* @0xc1c38 ldr r1, [r3] */
/* @0xc1c3c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0xc1c40 mov r1, r5 */
/* @0xc1c44 mov r0, r8 */
/* @0xc1c48 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue> */
/* @0xc1c4c ldr r1, [sp, #0x1c] */
/* @0xc1c50 sub r3, r1, #1 */
/* @0xc1c54 bic r3, r3, #-16777216 */
/* @0xc1c58 bics r9, r3, #3 */
/* @0xc1c5c bne 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1c60 bic r1, r1, #-16777216 */
/* @0xc1c64 cmp r1, #2 */
/* @0xc1c68 beq 0xc1d08 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x130> */
/* @0xc1c6c cmp r1, #3 */
/* @0xc1c70 beq 0xc1ce0 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x108> */
/* @0xc1c74 cmp r1, #1 */
/* @0xc1c78 bne 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1c7c ldr r9, [sp, #0x10] */
/* @0xc1c80 cmp r9, #0 */
/* @0xc1c84 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1c88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1c8c ldr r10, [r9, #0x4] */
/* @0xc1c90 sub r10, r10, #1 */
/* @0xc1c94 str r10, [r9, #0x4] */
/* @0xc1c98 cmp r10, #0 */
/* @0xc1c9c bne 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160> */
/* @0xc1ca0 ldr r0, [r9] */
/* @0xc1ca4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1ca8 str r10, [r9] */
/* @0xc1cac str r10, [r9, #0x8] */
/* @0xc1cb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1cb4 ldr r10, [r9, #0x4] */
/* @0xc1cb8 sub r10, r10, #1 */
/* @0xc1cbc str r10, [r9, #0x4] */
/* @0xc1cc0 cmp r10, #0 */
/* @0xc1cc4 beq 0xc1e18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x240> */
/* @0xc1cc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1ccc mov r0, r9 */
/* @0xc1cd0 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1cd4 b 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160> */
/* @0xc1cd8 add sp, sp, #36 */
/* @0xc1cdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc1ce0 ldr r3, [sp, #0x18] */
/* @0xc1ce4 tst r3, #8 */
/* @0xc1ce8 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1cec ldr r0, [sp, #0x10] */
/* @0xc1cf0 cmp r0, #0 */
/* @0xc1cf4 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1cf8 ldr r3, [r0] */
/* @0xc1cfc ldr r3, [r3, #0x4] */
/* @0xc1d00 blx r3 */
/* @0xc1d04 b 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1d08 ldr r10, [sp, #0x10] */
/* @0xc1d0c cmp r10, #0 */
/* @0xc1d10 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1d14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0xc1d18 ldr r3, [r10] */
/* @0xc1d1c ldr r1, [r10, #0x8] */
/* @0xc1d20 sub r3, r3, #1 */
/* @0xc1d24 str r3, [r10] */
/* @0xc1d28 cmp r1, r5 */
/* @0xc1d2c streq r9, [r10, #0x8] */
/* @0xc1d30 cmp r3, #0 */
/* @0xc1d34 ble 0xc1d40 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x168> */
/* @0xc1d38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0xc1d3c b 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40> */
/* @0xc1d40 ldr r3, [r10, #0x10] */
/* @0xc1d44 cmp r3, #0 */
/* @0xc1d48 movgt r2, #0 */
/* @0xc1d4c strgt r2, [sp, #0x8] */
/* @0xc1d50 ble 0xc1df4 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x21c> */
/* @0xc1d54 ldr r2, [sp, #0x8] */
/* @0xc1d58 ldr r3, [r10, #0x4] */
/* @0xc1d5c add r2, r3, r2, lsl #3 */
/* @0xc1d60 str r2, [sp, #0xc] */
/* @0xc1d64 ldr r2, [sp, #0x8] */
/* @0xc1d68 ldr r12, [r3, r2, lsl #3] */
/* @0xc1d6c ldr r3, [sp, #0xc] */
/* @0xc1d70 ldr r9, [r3, #0x4] */
/* @0xc1d74 add r12, r9, r12, lsl #4 */
/* @0xc1d78 cmp r9, r12 */
/* @0xc1d7c blo 0xc1d98 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1c0> */
/* @0xc1d80 b 0xc1e10 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x238> */
/* @0xc1d84 str r4, [r9, #0x8] */
/* @0xc1d88 str r6, [r9, #0xc] */
/* @0xc1d8c str r4, [r9], #16 */
/* @0xc1d90 cmp r12, r9 */
/* @0xc1d94 bls 0xc1dc4 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ec> */
/* @0xc1d98 ldr r1, [r9, #0xc] */
/* @0xc1d9c sub r1, r1, #1 */
/* @0xc1da0 bic r1, r1, #-16777216 */
/* @0xc1da4 bic r1, r1, #3 */
/* @0xc1da8 cmp r1, #0 */
/* @0xc1dac bne 0xc1d84 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ac> */
/* @0xc1db0 mov r0, r9 */
/* @0xc1db4 str r12, [sp, #0x4] */
/* @0xc1db8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0xc1dbc ldr r12, [sp, #0x4] */
/* @0xc1dc0 b 0xc1d84 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ac> */
/* @0xc1dc4 ldr r2, [sp, #0xc] */
/* @0xc1dc8 ldr r0, [r2, #0x4] */
/* @0xc1dcc ldr r3, [sp, #0x8] */
/* @0xc1dd0 add r3, r3, #1 */
/* @0xc1dd4 str r3, [sp, #0x8] */
/* @0xc1dd8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1ddc ldr r2, [sp, #0xc] */
/* @0xc1de0 ldr r3, [r10, #0x10] */
/* @0xc1de4 str r4, [r2, #0x4] */
/* @0xc1de8 ldr r2, [sp, #0x8] */
/* @0xc1dec cmp r2, r3 */
/* @0xc1df0 blt 0xc1d54 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x17c> */
/* @0xc1df4 ldr r0, [r10, #0x4] */
/* @0xc1df8 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1dfc str r4, [r10, #0x4] */
/* @0xc1e00 mov r0, r10 */
/* @0xc1e04 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0xc1e08 str r4, [sp, #0x10] */
/* @0xc1e0c b 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160> */
/* @0xc1e10 mov r0, r9 */
/* @0xc1e14 b 0xc1dcc <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1f4> */
/* @0xc1e18 ldr r0, [r9] */
/* @0xc1e1c bl 0xcef90 <_Z6YYFreePKv> */
/* @0xc1e20 mov r0, r9 */
/* @0xc1e24 str r10, [r9] */
/* @0xc1e28 str r10, [r9, #0x8] */
/* @0xc1e2c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0xc1e30 mov r0, r9 */
/* @0xc1e34 bl 0x27d1d0 <_ZdlPv> */
/* @0xc1e38 b 0xc1cc8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0xf0> */

/* ── FUNC 0xc1e3c · CBackground::FreeTexture() · size=36 · insn=9 */
/* @0xc1e3c push {r4, lr} */
/* @0xc1e40 mov r4, r0 */
/* @0xc1e44 ldr r0, [r0, #0xc] */
/* @0xc1e48 cmp r0, #0 */
/* @0xc1e4c blt 0xc1e54 <_ZN11CBackground11FreeTextureEv+0x18> */
/* @0xc1e50 bl 0x173f84 <_Z15GR_Texture_Freei> */
/* @0xc1e54 mvn r3, #0 */
/* @0xc1e58 str r3, [r4, #0xc] */
/* @0xc1e5c pop {r4, pc} */

/* ── FUNC 0xc1e60 · CBackground::InitTexture() · size=44 · insn=11 */
/* @0xc1e60 push {r4, lr} */
/* @0xc1e64 mov r4, r0 */
/* @0xc1e68 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv> */
/* @0xc1e6c ldr r0, [r4, #0x10] */
/* @0xc1e70 bl 0x173e70 <_Z24GR_Texture_Create_DirectP9CBitmap32> */
/* @0xc1e74 ldrb r3, [r4, #0xa] */
/* @0xc1e78 cmp r3, #0 */
/* @0xc1e7c str r0, [r4, #0xc] */
/* @0xc1e80 popeq {r4, pc} */
/* @0xc1e84 pop {r4, lr} */
/* @0xc1e88 b 0x174288 <_Z18GR_Texture_Preloadi> */

/* ── FUNC 0xc1e8c · CBackground::GetTexture() · size=20 · insn=5 */
/* @0xc1e8c ldr r3, [r0, #0x14] */
/* @0xc1e90 cmp r3, #0 */
/* @0xc1e94 movne r0, r3 */
/* @0xc1e98 ldreq r0, [r0, #0xc] */
/* @0xc1e9c bx lr */

/* ── FUNC 0xc1ea0 · CBackground::InitLocalTPE() · size=176 · insn=44 */
/* @0xc1ea0 push {r3, r4, r5, r6, r7, lr} */
/* @0xc1ea4 mov r4, r0 */
/* @0xc1ea8 ldr r0, [r0, #0x14] */
/* @0xc1eac cmp r0, #0 */
/* @0xc1eb0 beq 0xc1ecc <_ZN11CBackground12InitLocalTPEEv+0x2c> */
/* @0xc1eb4 ldrb r3, [r4, #0x18] */
/* @0xc1eb8 cmp r3, #0 */
/* @0xc1ebc popeq {r3, r4, r5, r6, r7, pc} */
/* @0xc1ec0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc1ec4 mov r3, #0 */
/* @0xc1ec8 str r3, [r4, #0x14] */
/* @0xc1ecc ldr r1, [pc, #0x78] */
/* @0xc1ed0 movw r2, #0x192 */
/* @0xc1ed4 mov r3, #1 */
/* @0xc1ed8 mov r0, #22 */
/* @0xc1edc add r1, pc, r1 */
/* @0xc1ee0 mov r5, #0 */
/* @0xc1ee4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0xc1ee8 mov r6, r0 */
/* @0xc1eec str r0, [r4, #0x14] */
/* @0xc1ef0 ldr r0, [r4, #0x10] */
/* @0xc1ef4 strh r5, [r6] */
/* @0xc1ef8 strh r5, [r6, #2] */
/* @0xc1efc bl 0x167960 <_ZN9CBitmap328GetWidthEv> */
/* @0xc1f00 ldr r7, [r4, #0x14] */
/* @0xc1f04 strh r0, [r6, #4] */
/* @0xc1f08 ldr r0, [r4, #0x10] */
/* @0xc1f0c bl 0x167968 <_ZN9CBitmap329GetHeightEv> */
/* @0xc1f10 ldr r3, [r4, #0x14] */
/* @0xc1f14 ldr r6, [r4, #0xc] */
/* @0xc1f18 mov r12, #1 */
/* @0xc1f1c ldrh r2, [r3, #4] */
/* @0xc1f20 strh r0, [r7, #6] */
/* @0xc1f24 ldrh r1, [r3, #6] */
/* @0xc1f28 strh r5, [r3, #8] */
/* @0xc1f2c strh r5, [r3, #10] */
/* @0xc1f30 strh r1, [r3, #14] */
/* @0xc1f34 strh r1, [r3, #18] */
/* @0xc1f38 strh r6, [r3, #20] */
/* @0xc1f3c strh r2, [r3, #12] */
/* @0xc1f40 strh r2, [r3, #16] */
/* @0xc1f44 strb r12, [r4, #0x18] */
/* @0xc1f48 pop {r3, r4, r5, r6, r7, pc} */
/* @0xc1f4c eoreq lr, r6, r12, ror #20 */

/* ── FUNC 0xc1f50 · CBackground::SetAlphaFromBackground(CBackground*) · size=100 · insn=25 */
/* @0xc1f50 push {r4, lr} */
/* @0xc1f54 mov r4, r0 */
/* @0xc1f58 ldr r0, [r0, #0x10] */
/* @0xc1f5c cmp r0, #0 */
/* @0xc1f60 beq 0xc1f88 <_ZN11CBackground22SetAlphaFromBackgroundEPS_+0x38> */
/* @0xc1f64 ldr r1, [r1, #0x10] */
/* @0xc1f68 cmp r1, #0 */
/* @0xc1f6c beq 0xc1f88 <_ZN11CBackground22SetAlphaFromBackgroundEPS_+0x38> */
/* @0xc1f70 bl 0x1672d0 <_ZN9CBitmap3218SetAlphaFromBitmapEPS_> */
/* @0xc1f74 mov r0, r4 */
/* @0xc1f78 bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc1f7c mov r0, r4 */
/* @0xc1f80 pop {r4, lr} */
/* @0xc1f84 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */
/* @0xc1f88 ldr r3, [pc, #0x1c] */
/* @0xc1f8c ldr r1, [pc, #0x1c] */
/* @0xc1f90 ldr r3, [pc, r3] */
/* @0xc1f94 add r1, pc, r1 */
/* @0xc1f98 ldr r0, [r3] */
/* @0xc1f9c ldr r3, [r0] */
/* @0xc1fa0 ldr r3, [r3, #0xc] */
/* @0xc1fa4 blx r3 */
/* @0xc1fa8 pop {r4, pc} */
/* @0xc1fac eorseq r11, r2, r4, lsl #15 */
/* @0xc1fb0 .word 0x0026e9f4 */

/* ── FUNC 0xc1fb4 · CBackground::DrawSimple(float, float) · size=28 · insn=7 */
/* @0xc1fb4 ldr r3, [r0, #0x14] */
/* @0xc1fb8 cmp r3, #0 */
/* @0xc1fbc beq 0xc1fc8 <_ZN11CBackground10DrawSimpleEff+0x14> */
/* @0xc1fc0 mov r0, r3 */
/* @0xc1fc4 b 0x174868 <_Z22GR_Texture_Draw_SimpleP12YYTPageEntryff> */
/* @0xc1fc8 ldr r0, [r0, #0xc] */
/* @0xc1fcc b 0x174498 <_Z22GR_Texture_Draw_Simpleiff> */

/* ── FUNC 0xc1fd0 · CBackground::Draw(float, float, float, float, float, unsigned int, float) · size=196 · insn=49 */
/* @0xc1fd0 ldr r12, [r0, #0x14] */
/* @0xc1fd4 vldr s15, [pc, #176] */
/* @0xc1fd8 str lr, [sp, #-0x4]! */
/* @0xc1fdc cmp r12, #0 */
/* @0xc1fe0 sub sp, sp, #28 */
/* @0xc1fe4 mov lr, r1 */
/* @0xc1fe8 beq 0xc203c <_ZN11CBackground4DrawEfffffjf+0x6c> */
/* @0xc1fec vldr s13, [sp, #36] */
/* @0xc1ff0 vmul.f32 s15, s13, s15 */
/* @0xc1ff4 vldr s14, [pc, #148] */
/* @0xc1ff8 str r3, [sp, #0x4] */
/* @0xc1ffc ldr r3, [sp, #0x28] */
/* @0xc2000 mov r1, #0 */
/* @0xc2004 vldr s13, [sp, #32] */
/* @0xc2008 str r2, [sp] */
/* @0xc200c vstr s13, [sp, #8] */
/* @0xc2010 mov r0, r12 */
/* @0xc2014 str r3, [sp, #0x10] */
/* @0xc2018 vldr s13, [sp, #44] */
/* @0xc201c mov r3, lr */
/* @0xc2020 vstr s13, [sp, #20] */
/* @0xc2024 mov r2, r1 */
/* @0xc2028 vdiv.f32 s15, s15, s14 */
/* @0xc202c vstr s15, [sp, #12] */
/* @0xc2030 bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0xc2034 add sp, sp, #28 */
/* @0xc2038 ldr pc, [sp], #4 */
/* @0xc203c vldr s14, [sp, #36] */
/* @0xc2040 vmul.f32 s15, s14, s15 */
/* @0xc2044 vldr s14, [pc, #68] */
/* @0xc2048 ldr r0, [r0, #0xc] */
/* @0xc204c str r3, [sp, #0x4] */
/* @0xc2050 mov r1, #0 */
/* @0xc2054 ldr r3, [sp, #0x28] */
/* @0xc2058 vldr s13, [sp, #32] */
/* @0xc205c str r2, [sp] */
/* @0xc2060 vstr s13, [sp, #8] */
/* @0xc2064 mov r2, r1 */
/* @0xc2068 vldr s13, [sp, #44] */
/* @0xc206c str r3, [sp, #0x10] */
/* @0xc2070 vstr s13, [sp, #20] */
/* @0xc2074 mov r3, lr */
/* @0xc2078 vdiv.f32 s15, s15, s14 */
/* @0xc207c vstr s15, [sp, #12] */
/* @0xc2080 bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0xc2084 add sp, sp, #28 */
/* @0xc2088 ldr pc, [sp], #4 */
/* @0xc208c ldrdmi r0, r1, [r9], #-251 */
/* @0xc2090 teqmi r4, #0 */

/* ── FUNC 0xc2094 · CBackground::DrawStretched(float, float, float, float, unsigned int, float) · size=240 · insn=60 */
/* @0xc2094 vmov s15, r3 */
/* @0xc2098 mov r12, #0 */
/* @0xc209c push {r4, r5, lr} */
/* @0xc20a0 vcmpe.f32 s15, #0 */
/* @0xc20a4 sub sp, sp, #28 */
/* @0xc20a8 mov r3, r1 */
/* @0xc20ac vldr s14, [sp, #40] */
/* @0xc20b0 vmrs APSR_nzcv, fpscr */
/* @0xc20b4 bls 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c> */
/* @0xc20b8 vcmpe.f32 s14, #0 */
/* @0xc20bc vmrs APSR_nzcv, fpscr */
/* @0xc20c0 bls 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c> */
/* @0xc20c4 ldr r4, [r0] */
/* @0xc20c8 cmp r4, #0 */
/* @0xc20cc ble 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c> */
/* @0xc20d0 ldr r5, [r0, #0x4] */
/* @0xc20d4 cmp r5, #0 */
/* @0xc20d8 ble 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c> */
/* @0xc20dc ldr lr, [r0, #0x14] */
/* @0xc20e0 cmp lr, #0 */
/* @0xc20e4 beq 0xc2138 <_ZN11CBackground13DrawStretchedEffffjf+0xa4> */
/* @0xc20e8 vmov s11, r4 */
/* @0xc20ec str r2, [sp] */
/* @0xc20f0 ldr r2, [sp, #0x2c] */
/* @0xc20f4 mov r1, r12 */
/* @0xc20f8 vcvt.f32.s32 s12, s11 */
/* @0xc20fc vldr s11, [sp, #48] */
/* @0xc2100 vstr s11, [sp, #20] */
/* @0xc2104 vmov s11, r5 */
/* @0xc2108 str r2, [sp, #0x10] */
/* @0xc210c mov r0, lr */
/* @0xc2110 str r12, [sp, #0xc] */
/* @0xc2114 mov r2, r12 */
/* @0xc2118 vcvt.f32.s32 s13, s11 */
/* @0xc211c vdiv.f32 s15, s15, s12 */
/* @0xc2120 vdiv.f32 s14, s14, s13 */
/* @0xc2124 vstr s15, [sp, #4] */
/* @0xc2128 vstr s14, [sp, #8] */
/* @0xc212c bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf> */
/* @0xc2130 add sp, sp, #28 */
/* @0xc2134 pop {r4, r5, pc} */
/* @0xc2138 ldr r0, [r0, #0xc] */
/* @0xc213c vmov s13, r4 */
/* @0xc2140 vldr s11, [sp, #48] */
/* @0xc2144 vstr s11, [sp, #20] */
/* @0xc2148 vmov s11, r5 */
/* @0xc214c str r2, [sp] */
/* @0xc2150 vcvt.f32.s32 s12, s13 */
/* @0xc2154 ldr r2, [sp, #0x2c] */
/* @0xc2158 mov r1, r12 */
/* @0xc215c str r12, [sp, #0xc] */
/* @0xc2160 str r2, [sp, #0x10] */
/* @0xc2164 mov r2, r12 */
/* @0xc2168 vcvt.f32.s32 s13, s11 */
/* @0xc216c vdiv.f32 s15, s15, s12 */
/* @0xc2170 vdiv.f32 s14, s14, s13 */
/* @0xc2174 vstr s15, [sp, #4] */
/* @0xc2178 vstr s14, [sp, #8] */
/* @0xc217c bl 0x174c40 <_Z15GR_Texture_Drawifffffffjf> */
/* @0xc2180 b 0xc2130 <_ZN11CBackground13DrawStretchedEffffjf+0x9c> */

/* ── FUNC 0xc2184 · CBackground::DrawPart(float, float, float, float, float, float, float, float, unsigned int, float) · size=180 · insn=45 */
/* @0xc2184 ldr r12, [r0, #0x14] */
/* @0xc2188 str lr, [sp, #-0x4]! */
/* @0xc218c cmp r12, #0 */
/* @0xc2190 sub sp, sp, #36 */
/* @0xc2194 beq 0xc21e8 <_ZN11CBackground8DrawPartEffffffffjf+0x64> */
/* @0xc2198 ldr r0, [sp, #0x3c] */
/* @0xc219c vldr s15, [sp, #40] */
/* @0xc21a0 vstr s15, [sp] */
/* @0xc21a4 vldr s15, [sp, #44] */
/* @0xc21a8 vstr s15, [sp, #4] */
/* @0xc21ac vldr s15, [sp, #48] */
/* @0xc21b0 str r0, [sp, #0x18] */
/* @0xc21b4 vstr s15, [sp, #8] */
/* @0xc21b8 mov r0, r12 */
/* @0xc21bc vldr s15, [sp, #52] */
/* @0xc21c0 mov r12, #0 */
/* @0xc21c4 vstr s15, [sp, #12] */
/* @0xc21c8 str r12, [sp, #0x14] */
/* @0xc21cc vldr s15, [sp, #56] */
/* @0xc21d0 vstr s15, [sp, #16] */
/* @0xc21d4 vldr s15, [sp, #64] */
/* @0xc21d8 vstr s15, [sp, #28] */
/* @0xc21dc bl 0x175450 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf> */
/* @0xc21e0 add sp, sp, #36 */
/* @0xc21e4 ldr pc, [sp], #4 */
/* @0xc21e8 ldr r12, [sp, #0x3c] */
/* @0xc21ec vldr s15, [sp, #40] */
/* @0xc21f0 ldr r0, [r0, #0xc] */
/* @0xc21f4 vstr s15, [sp] */
/* @0xc21f8 vldr s15, [sp, #44] */
/* @0xc21fc vstr s15, [sp, #4] */
/* @0xc2200 str r12, [sp, #0x18] */
/* @0xc2204 vldr s15, [sp, #48] */
/* @0xc2208 mov r12, #0 */
/* @0xc220c vstr s15, [sp, #8] */
/* @0xc2210 str r12, [sp, #0x14] */
/* @0xc2214 vldr s15, [sp, #52] */
/* @0xc2218 vstr s15, [sp, #12] */
/* @0xc221c vldr s15, [sp, #56] */
/* @0xc2220 vstr s15, [sp, #16] */
/* @0xc2224 vldr s15, [sp, #64] */
/* @0xc2228 vstr s15, [sp, #28] */
/* @0xc222c bl 0x175208 <_Z20GR_Texture_Draw_Partifffffffffjf> */
/* @0xc2230 add sp, sp, #36 */
/* @0xc2234 ldr pc, [sp], #4 */

/* ── FUNC 0xc2238 · CBackground::DrawGeneral(float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float) · size=160 · insn=40 */
/* @0xc2238 ldr r12, [r0, #0x14] */
/* @0xc223c vldr s12, [pc, #140] */
/* @0xc2240 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0xc2244 cmp r12, #0 */
/* @0xc2248 vldr s15, [sp, #52] */
/* @0xc224c vldr s13, [sp, #32] */
/* @0xc2250 vmul.f32 s15, s15, s12 */
/* @0xc2254 vldr s14, [sp, #36] */
/* @0xc2258 ldr r11, [sp, #0x28] */
/* @0xc225c ldr r10, [sp, #0x2c] */
/* @0xc2260 vldr s12, [pc, #108] */
/* @0xc2264 ldr r9, [sp, #0x30] */
/* @0xc2268 ldr r7, [sp, #0x38] */
/* @0xc226c ldr r6, [sp, #0x3c] */
/* @0xc2270 ldr r5, [sp, #0x40] */
/* @0xc2274 ldr r4, [sp, #0x44] */
/* @0xc2278 ldr r8, [sp, #0x48] */
/* @0xc227c beq 0xc2294 <_ZN11CBackground11DrawGeneralEfffffffffjjjjf+0x5c> */
/* @0xc2280 mov r0, r12 */
/* @0xc2284 vdiv.f32 s15, s15, s12 */
/* @0xc2288 vstr s15, [sp, #52] */
/* @0xc228c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0xc2290 b 0x175a90 <_Z26GR_Texture_Draw_Part_ColorP12YYTPageEntryfffffffffjjjjf> */
/* @0xc2294 vdiv.f32 s15, s15, s12 */
/* @0xc2298 ldr r0, [r0, #0xc] */
/* @0xc229c vstr s13, [sp, #32] */
/* @0xc22a0 vstr s14, [sp, #36] */
/* @0xc22a4 str r11, [sp, #0x28] */
/* @0xc22a8 str r10, [sp, #0x2c] */
/* @0xc22ac str r9, [sp, #0x30] */
/* @0xc22b0 str r7, [sp, #0x38] */
/* @0xc22b4 str r6, [sp, #0x3c] */
/* @0xc22b8 str r5, [sp, #0x40] */
/* @0xc22bc str r4, [sp, #0x44] */
/* @0xc22c0 str r8, [sp, #0x48] */
/* @0xc22c4 vstr s15, [sp, #52] */
/* @0xc22c8 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0xc22cc b 0x175834 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf> */
/* @0xc22d0 ldrdmi r0, r1, [r9], #-251 */
/* @0xc22d4 teqmi r4, #0 */

/* ── FUNC 0xc22d8 · CBackground::DrawTiled(float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) · size=232 · insn=58 */
/* @0xc22d8 ldr r12, [r0, #0x14] */
/* @0xc22dc push {r4, r5, lr} */
/* @0xc22e0 cmp r12, #0 */
/* @0xc22e4 sub sp, sp, #52 */
/* @0xc22e8 mov lr, r1 */
/* @0xc22ec ldrb r5, [sp, #0x44] */
/* @0xc22f0 ldrb r4, [sp, #0x48] */
/* @0xc22f4 beq 0xc235c <_ZN11CBackground9DrawTiledEffffbbffffjf+0x84> */
/* @0xc22f8 str r3, [sp, #0x4] */
/* @0xc22fc mov r1, #0 */
/* @0xc2300 ldr r3, [sp, #0x5c] */
/* @0xc2304 vldr s15, [sp, #64] */
/* @0xc2308 str r2, [sp] */
/* @0xc230c vstr s15, [sp, #8] */
/* @0xc2310 str r5, [sp, #0xc] */
/* @0xc2314 vldr s15, [sp, #76] */
/* @0xc2318 str r3, [sp, #0x24] */
/* @0xc231c vstr s15, [sp, #20] */
/* @0xc2320 str r4, [sp, #0x10] */
/* @0xc2324 vldr s15, [sp, #80] */
/* @0xc2328 mov r0, r12 */
/* @0xc232c vstr s15, [sp, #24] */
/* @0xc2330 mov r3, lr */
/* @0xc2334 vldr s15, [sp, #84] */
/* @0xc2338 mov r2, r1 */
/* @0xc233c vstr s15, [sp, #28] */
/* @0xc2340 vldr s15, [sp, #88] */
/* @0xc2344 vstr s15, [sp, #32] */
/* @0xc2348 vldr s15, [sp, #96] */
/* @0xc234c vstr s15, [sp, #40] */
/* @0xc2350 bl 0x1762b0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf> */
/* @0xc2354 add sp, sp, #52 */
/* @0xc2358 pop {r4, r5, pc} */
/* @0xc235c ldr r0, [r0, #0xc] */
/* @0xc2360 mov r1, #0 */
/* @0xc2364 str r3, [sp, #0x4] */
/* @0xc2368 vldr s15, [sp, #64] */
/* @0xc236c ldr r3, [sp, #0x5c] */
/* @0xc2370 vstr s15, [sp, #8] */
/* @0xc2374 str r2, [sp] */
/* @0xc2378 vldr s15, [sp, #76] */
/* @0xc237c str r5, [sp, #0xc] */
/* @0xc2380 vstr s15, [sp, #20] */
/* @0xc2384 str r3, [sp, #0x24] */
/* @0xc2388 vldr s15, [sp, #80] */
/* @0xc238c str r4, [sp, #0x10] */
/* @0xc2390 vstr s15, [sp, #24] */
/* @0xc2394 mov r3, lr */
/* @0xc2398 vldr s15, [sp, #84] */
/* @0xc239c mov r2, r1 */
/* @0xc23a0 vstr s15, [sp, #28] */
/* @0xc23a4 vldr s15, [sp, #88] */
/* @0xc23a8 vstr s15, [sp, #32] */
/* @0xc23ac vldr s15, [sp, #96] */
/* @0xc23b0 vstr s15, [sp, #40] */
/* @0xc23b4 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf> */
/* @0xc23b8 add sp, sp, #52 */
/* @0xc23bc pop {r4, r5, pc} */

/* ── FUNC 0xc23c0 · CBackground::Clear() · size=140 · insn=35 */
/* @0xc23c0 push {r3, r4, r5, lr} */
/* @0xc23c4 mov r4, r0 */
/* @0xc23c8 ldr r0, [r0, #0x10] */
/* @0xc23cc cmp r0, #0 */
/* @0xc23d0 beq 0xc23e0 <_ZN11CBackground5ClearEv+0x20> */
/* @0xc23d4 ldr r3, [r0] */
/* @0xc23d8 ldr r3, [r3, #0x4] */
/* @0xc23dc blx r3 */
/* @0xc23e0 ldr r0, [r4, #0x14] */
/* @0xc23e4 mov r5, #0 */
/* @0xc23e8 str r5, [r4, #0x10] */
/* @0xc23ec cmp r0, r5 */
/* @0xc23f0 str r5, [r4] */
/* @0xc23f4 str r5, [r4, #0x4] */
/* @0xc23f8 strb r5, [r4, #0x8] */
/* @0xc23fc strb r5, [r4, #0x9] */
/* @0xc2400 strb r5, [r4, #0xa] */
/* @0xc2404 beq 0xc241c <_ZN11CBackground5ClearEv+0x5c> */
/* @0xc2408 ldrb r3, [r4, #0x18] */
/* @0xc240c cmp r3, r5 */
/* @0xc2410 beq 0xc241c <_ZN11CBackground5ClearEv+0x5c> */
/* @0xc2414 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc2418 strb r5, [r4, #0x18] */
/* @0xc241c mov r5, #0 */
/* @0xc2420 mov r0, r4 */
/* @0xc2424 str r5, [r4, #0x14] */
/* @0xc2428 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv> */
/* @0xc242c mvn r3, #0 */
/* @0xc2430 str r5, [r4, #0x1c] */
/* @0xc2434 str r5, [r4, #0x20] */
/* @0xc2438 str r5, [r4, #0x24] */
/* @0xc243c str r5, [r4, #0x28] */
/* @0xc2440 str r5, [r4, #0x2c] */
/* @0xc2444 str r3, [r4, #0xc] */
/* @0xc2448 pop {r3, r4, r5, pc} */

/* ── FUNC 0xc244c · CBackground::CreateFromBitmap(IBitmap*, bool, bool, bool, bool) · size=460 · insn=115 */
/* @0xc244c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc2450 sub sp, sp, #12 */
/* @0xc2454 mov r5, r1 */
/* @0xc2458 mov r4, r0 */
/* @0xc245c mov r6, r2 */
/* @0xc2460 mov r9, r3 */
/* @0xc2464 ldrb r8, [sp, #0x28] */
/* @0xc2468 ldrb r7, [sp, #0x2c] */
/* @0xc246c bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2470 ldr r3, [r5] */
/* @0xc2474 mov r0, r5 */
/* @0xc2478 strb r6, [r4, #0x8] */
/* @0xc247c strb r9, [r4, #0x9] */
/* @0xc2480 ldr r3, [r3, #0x10] */
/* @0xc2484 strb r8, [r4, #0xa] */
/* @0xc2488 blx r3 */
/* @0xc248c ldr r3, [r5] */
/* @0xc2490 ldr r3, [r3, #0x18] */
/* @0xc2494 str r0, [r4] */
/* @0xc2498 mov r0, r5 */
/* @0xc249c blx r3 */
/* @0xc24a0 str r0, [r4, #0x4] */
/* @0xc24a4 bl 0x181374 <_ZN8Graphics17GetMaxTextureSizeEv> */
/* @0xc24a8 ldr r3, [r4] */
/* @0xc24ac cmp r0, r3 */
/* @0xc24b0 mov r6, r0 */
/* @0xc24b4 blt 0xc2540 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xf4> */
/* @0xc24b8 ldr r3, [r4, #0x4] */
/* @0xc24bc cmp r0, r3 */
/* @0xc24c0 movge r6, #0 */
/* @0xc24c4 blt 0xc2540 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xf4> */
/* @0xc24c8 cmp r7, #0 */
/* @0xc24cc ldr r0, [r4, #0x10] */
/* @0xc24d0 beq 0xc25d8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x18c> */
/* @0xc24d4 cmp r0, #0 */
/* @0xc24d8 beq 0xc24e8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x9c> */
/* @0xc24dc ldr r3, [r0] */
/* @0xc24e0 ldr r3, [r3, #0x4] */
/* @0xc24e4 blx r3 */
/* @0xc24e8 mov r0, #24 */
/* @0xc24ec bl 0x27c524 <_Znwj> */
/* @0xc24f0 ldrb r2, [r4, #0x8] */
/* @0xc24f4 ldrb r3, [r4, #0x9] */
/* @0xc24f8 mov r12, #0 */
/* @0xc24fc mov r1, r5 */
/* @0xc2500 str r12, [sp] */
/* @0xc2504 mov r7, r0 */
/* @0xc2508 bl 0x166fd0 <_ZN9CBitmap32C2EP7IBitmapbbi> */
/* @0xc250c str r7, [r4, #0x10] */
/* @0xc2510 cmp r6, #0 */
/* @0xc2514 beq 0xc2528 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xdc> */
/* @0xc2518 ldr r3, [r6] */
/* @0xc251c mov r0, r6 */
/* @0xc2520 ldr r3, [r3, #0x4] */
/* @0xc2524 blx r3 */
/* @0xc2528 mov r0, r4 */
/* @0xc252c bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc2530 mov r0, r4 */
/* @0xc2534 add sp, sp, #12 */
/* @0xc2538 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc253c b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */
/* @0xc2540 ldr r3, [pc, #0xc8] */
/* @0xc2544 mov r2, r6 */
/* @0xc2548 ldr r1, [pc, #0xc4] */
/* @0xc254c ldr r3, [pc, r3] */
/* @0xc2550 add r1, pc, r1 */
/* @0xc2554 ldr r0, [r3] */
/* @0xc2558 ldr r3, [r0] */
/* @0xc255c ldr r3, [r3, #0xc] */
/* @0xc2560 blx r3 */
/* @0xc2564 ldm r4, {r2, r3} */
/* @0xc2568 mov r0, #24 */
/* @0xc256c cmp r2, r6 */
/* @0xc2570 strle r2, [r4] */
/* @0xc2574 strgt r6, [r4] */
/* @0xc2578 cmp r3, r6 */
/* @0xc257c strle r3, [r4, #0x4] */
/* @0xc2580 strgt r6, [r4, #0x4] */
/* @0xc2584 bl 0x27c524 <_Znwj> */
/* @0xc2588 ldr r1, [r4] */
/* @0xc258c ldr r2, [r4, #0x4] */
/* @0xc2590 mov r3, #255 */
/* @0xc2594 movt r3, #0xff00 */
/* @0xc2598 mov r6, r0 */
/* @0xc259c bl 0x166140 <_ZN9CBitmap32C2Eiij> */
/* @0xc25a0 mov r0, r6 */
/* @0xc25a4 bl 0x167724 <_ZN9CBitmap3214CreateBitmap32Ev> */
/* @0xc25a8 cmp r6, #0 */
/* @0xc25ac mov r5, r0 */
/* @0xc25b0 moveq r6, r0 */
/* @0xc25b4 beq 0xc24c8 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x7c> */
/* @0xc25b8 ldr r3, [r6] */
/* @0xc25bc mov r0, r6 */
/* @0xc25c0 mov r6, r5 */
/* @0xc25c4 ldr r3, [r3, #0x4] */
/* @0xc25c8 blx r3 */
/* @0xc25cc cmp r7, #0 */
/* @0xc25d0 ldr r0, [r4, #0x10] */
/* @0xc25d4 bne 0xc24d4 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x88> */
/* @0xc25d8 cmp r0, #0 */
/* @0xc25dc beq 0xc25ec <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0x1a0> */
/* @0xc25e0 ldr r3, [r0] */
/* @0xc25e4 ldr r3, [r3, #0x4] */
/* @0xc25e8 blx r3 */
/* @0xc25ec mov r0, #24 */
/* @0xc25f0 bl 0x27c524 <_Znwj> */
/* @0xc25f4 mov r1, r5 */
/* @0xc25f8 ldrb r2, [r4, #0x8] */
/* @0xc25fc ldrb r3, [r4, #0x9] */
/* @0xc2600 mov r7, r0 */
/* @0xc2604 bl 0x166e70 <_ZN9CBitmap32C2EP7IBitmapbb> */
/* @0xc2608 str r7, [r4, #0x10] */
/* @0xc260c b 0xc2510 <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb+0xc4> */
/* @0xc2610 eorseq r11, r2, r8, asr #3 */
/* @0xc2614 eoreq lr, r6, r4, ror #8 */

/* ── FUNC 0xc2618 · CBackground::LoadFromData(void*, int, int, bool, bool, bool, bool) · size=148 · insn=37 */
/* @0xc2618 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc261c sub sp, sp, #8 */
/* @0xc2620 mov r6, r0 */
/* @0xc2624 mov r0, r1 */
/* @0xc2628 mov r1, r2 */
/* @0xc262c mov r2, r3 */
/* @0xc2630 ldrb r9, [sp, #0x28] */
/* @0xc2634 ldrb r7, [sp, #0x2c] */
/* @0xc2638 ldrb r10, [sp, #0x30] */
/* @0xc263c ldrb r8, [sp, #0x34] */
/* @0xc2640 bl 0x1a928c <_ZN13IBitmapLoader6CreateEPvii> */
/* @0xc2644 mov r1, #0 */
/* @0xc2648 ldr r3, [r0] */
/* @0xc264c mov r5, r0 */
/* @0xc2650 ldr r3, [r3, #0x10] */
/* @0xc2654 blx r3 */
/* @0xc2658 str r10, [sp] */
/* @0xc265c mov r2, r9 */
/* @0xc2660 str r8, [sp, #0x4] */
/* @0xc2664 mov r3, r7 */
/* @0xc2668 mov r4, r0 */
/* @0xc266c mov r0, r6 */
/* @0xc2670 mov r1, r4 */
/* @0xc2674 bl 0xc244c <_ZN11CBackground16CreateFromBitmapEP7IBitmapbbbb> */
/* @0xc2678 cmp r4, #0 */
/* @0xc267c beq 0xc2690 <_ZN11CBackground12LoadFromDataEPviibbbb+0x78> */
/* @0xc2680 ldr r3, [r4] */
/* @0xc2684 mov r0, r4 */
/* @0xc2688 ldr r3, [r3, #0x4] */
/* @0xc268c blx r3 */
/* @0xc2690 ldr r3, [r5] */
/* @0xc2694 mov r0, r5 */
/* @0xc2698 ldr r3, [r3, #0x4] */
/* @0xc269c blx r3 */
/* @0xc26a0 mov r0, #1 */
/* @0xc26a4 add sp, sp, #8 */
/* @0xc26a8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0xc26ac · CBackground::LoadFromPNGData(void*, int, bool, bool, bool, bool) · size=112 · insn=28 */
/* @0xc26ac push {r4, r5, r6, r7, r8, lr} */
/* @0xc26b0 sub sp, sp, #24 */
/* @0xc26b4 mov r8, r0 */
/* @0xc26b8 mov r7, r3 */
/* @0xc26bc mov r0, r1 */
/* @0xc26c0 mov r3, #0 */
/* @0xc26c4 mov r1, r2 */
/* @0xc26c8 str r3, [sp] */
/* @0xc26cc add r2, sp, #16 */
/* @0xc26d0 add r3, sp, #20 */
/* @0xc26d4 ldrb r4, [sp, #0x38] */
/* @0xc26d8 ldrb r6, [sp, #0x30] */
/* @0xc26dc ldrb r5, [sp, #0x34] */
/* @0xc26e0 bl 0x18a24c <_Z11ReadPNGFilePviPiS0_b> */
/* @0xc26e4 ldr r2, [sp, #0x10] */
/* @0xc26e8 ldr r3, [sp, #0x14] */
/* @0xc26ec str r4, [sp, #0xc] */
/* @0xc26f0 str r7, [sp] */
/* @0xc26f4 str r6, [sp, #0x4] */
/* @0xc26f8 str r5, [sp, #0x8] */
/* @0xc26fc mov r1, r0 */
/* @0xc2700 mov r0, r8 */
/* @0xc2704 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb> */
/* @0xc2708 mov r4, r0 */
/* @0xc270c bl 0x18a518 <_Z11FreePNGFilev> */
/* @0xc2710 mov r0, r4 */
/* @0xc2714 add sp, sp, #24 */
/* @0xc2718 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0xc271c · CBackground::LoadFromJPEGData(void*, int, bool, bool, bool, bool) · size=128 · insn=32 */
/* @0xc271c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc2720 sub sp, sp, #28 */
/* @0xc2724 mov r12, #0 */
/* @0xc2728 mov r9, r0 */
/* @0xc272c mov r8, r3 */
/* @0xc2730 mov r0, r1 */
/* @0xc2734 str r12, [sp] */
/* @0xc2738 mov r1, r2 */
/* @0xc273c add r3, sp, #20 */
/* @0xc2740 add r2, sp, #16 */
/* @0xc2744 ldrb r5, [sp, #0x40] */
/* @0xc2748 ldrb r7, [sp, #0x38] */
/* @0xc274c ldrb r6, [sp, #0x3c] */
/* @0xc2750 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b> */
/* @0xc2754 subs r4, r0, #0 */
/* @0xc2758 moveq r5, r4 */
/* @0xc275c beq 0xc2790 <_ZN11CBackground16LoadFromJPEGDataEPvibbbb+0x74> */
/* @0xc2760 str r5, [sp, #0xc] */
/* @0xc2764 mov r0, r9 */
/* @0xc2768 ldr r2, [sp, #0x10] */
/* @0xc276c mov r1, r4 */
/* @0xc2770 ldr r3, [sp, #0x14] */
/* @0xc2774 str r8, [sp] */
/* @0xc2778 str r7, [sp, #0x4] */
/* @0xc277c str r6, [sp, #0x8] */
/* @0xc2780 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb> */
/* @0xc2784 mov r5, r0 */
/* @0xc2788 mov r0, r4 */
/* @0xc278c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc2790 mov r0, r5 */
/* @0xc2794 add sp, sp, #28 */
/* @0xc2798 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0xc279c · CBackground::LoadFromGIFData(void*, int, bool, bool, bool, bool) · size=128 · insn=32 */
/* @0xc279c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xc27a0 sub sp, sp, #28 */
/* @0xc27a4 mov r12, #0 */
/* @0xc27a8 mov r9, r0 */
/* @0xc27ac mov r8, r3 */
/* @0xc27b0 mov r0, r1 */
/* @0xc27b4 str r12, [sp] */
/* @0xc27b8 mov r1, r2 */
/* @0xc27bc add r3, sp, #20 */
/* @0xc27c0 add r2, sp, #16 */
/* @0xc27c4 ldrb r5, [sp, #0x40] */
/* @0xc27c8 ldrb r7, [sp, #0x38] */
/* @0xc27cc ldrb r6, [sp, #0x3c] */
/* @0xc27d0 bl 0x18a918 <_Z11ReadGIFFilePviPiS0_b> */
/* @0xc27d4 subs r4, r0, #0 */
/* @0xc27d8 moveq r5, r4 */
/* @0xc27dc beq 0xc2810 <_ZN11CBackground15LoadFromGIFDataEPvibbbb+0x74> */
/* @0xc27e0 str r5, [sp, #0xc] */
/* @0xc27e4 mov r0, r9 */
/* @0xc27e8 ldr r2, [sp, #0x10] */
/* @0xc27ec mov r1, r4 */
/* @0xc27f0 ldr r3, [sp, #0x14] */
/* @0xc27f4 str r8, [sp] */
/* @0xc27f8 str r7, [sp, #0x4] */
/* @0xc27fc str r6, [sp, #0x8] */
/* @0xc2800 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb> */
/* @0xc2804 mov r5, r0 */
/* @0xc2808 mov r0, r4 */
/* @0xc280c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc2810 mov r0, r5 */
/* @0xc2814 add sp, sp, #28 */
/* @0xc2818 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0xc281c · CBackground::LoadFromFileData(char const*, void*, int, bool, bool, bool, bool) · size=360 · insn=90 */
/* @0xc281c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xc2820 sub sp, sp, #20 */
/* @0xc2824 ldrb r12, [r2] */
/* @0xc2828 mov r4, r2 */
/* @0xc282c mov r5, r1 */
/* @0xc2830 mov r7, r3 */
/* @0xc2834 cmp r12, #255 */
/* @0xc2838 mov r11, r0 */
/* @0xc283c ldrb r6, [sp, #0x38] */
/* @0xc2840 ldrb r10, [sp, #0x3c] */
/* @0xc2844 ldrb r9, [sp, #0x40] */
/* @0xc2848 ldrb r8, [sp, #0x44] */
/* @0xc284c beq 0xc2900 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xe4> */
/* @0xc2850 cmp r12, #71 */
/* @0xc2854 bne 0xc28a8 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x8c> */
/* @0xc2858 ldrb r3, [r4, #0x1] */
/* @0xc285c cmp r3, #73 */
/* @0xc2860 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc2864 ldrb r3, [r4, #0x2] */
/* @0xc2868 cmp r3, #70 */
/* @0xc286c bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc2870 ldrb r3, [r4, #0x3] */
/* @0xc2874 cmp r3, #56 */
/* @0xc2878 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc287c str r10, [sp] */
/* @0xc2880 mov r0, r11 */
/* @0xc2884 str r9, [sp, #0x4] */
/* @0xc2888 mov r1, r4 */
/* @0xc288c str r8, [sp, #0x8] */
/* @0xc2890 mov r2, r7 */
/* @0xc2894 mov r3, r6 */
/* @0xc2898 bl 0xc279c <_ZN11CBackground15LoadFromGIFDataEPvibbbb> */
/* @0xc289c cmp r0, #0 */
/* @0xc28a0 bne 0xc296c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x150> */
/* @0xc28a4 ldrb r12, [r4] */
/* @0xc28a8 cmp r12, #137 */
/* @0xc28ac bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc28b0 ldrb r3, [r4, #0x1] */
/* @0xc28b4 cmp r3, #80 */
/* @0xc28b8 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc28bc ldrb r3, [r4, #0x2] */
/* @0xc28c0 cmp r3, #78 */
/* @0xc28c4 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc28c8 ldrb r3, [r4, #0x3] */
/* @0xc28cc cmp r3, #71 */
/* @0xc28d0 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc28d4 str r10, [sp] */
/* @0xc28d8 mov r0, r11 */
/* @0xc28dc str r9, [sp, #0x4] */
/* @0xc28e0 mov r1, r4 */
/* @0xc28e4 str r8, [sp, #0x8] */
/* @0xc28e8 mov r2, r7 */
/* @0xc28ec mov r3, r6 */
/* @0xc28f0 bl 0xc26ac <_ZN11CBackground15LoadFromPNGDataEPvibbbb> */
/* @0xc28f4 cmp r0, #0 */
/* @0xc28f8 bne 0xc2934 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x118> */
/* @0xc28fc b 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc2900 ldrb r3, [r2, #0x1] */
/* @0xc2904 cmp r3, #216 */
/* @0xc2908 beq 0xc293c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x120> */
/* @0xc290c ldr r3, [pc, #0x68] */
/* @0xc2910 mov r2, r5 */
/* @0xc2914 ldr r1, [pc, #0x64] */
/* @0xc2918 ldr r3, [pc, r3] */
/* @0xc291c add r1, pc, r1 */
/* @0xc2920 ldr r0, [r3] */
/* @0xc2924 ldr r3, [r0] */
/* @0xc2928 ldr r3, [r3, #0xc] */
/* @0xc292c blx r3 */
/* @0xc2930 mov r0, #0 */
/* @0xc2934 add sp, sp, #20 */
/* @0xc2938 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xc293c ldrb r3, [r2, #0x2] */
/* @0xc2940 cmp r3, #255 */
/* @0xc2944 bne 0xc290c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0xf0> */
/* @0xc2948 mov r1, r2 */
/* @0xc294c str r10, [sp] */
/* @0xc2950 str r9, [sp, #0x4] */
/* @0xc2954 mov r2, r7 */
/* @0xc2958 str r8, [sp, #0x8] */
/* @0xc295c mov r3, r6 */
/* @0xc2960 bl 0xc271c <_ZN11CBackground16LoadFromJPEGDataEPvibbbb> */
/* @0xc2964 cmp r0, #0 */
/* @0xc2968 beq 0xc2974 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x158> */
/* @0xc296c mov r0, #1 */
/* @0xc2970 b 0xc2934 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x118> */
/* @0xc2974 ldrb r12, [r4] */
/* @0xc2978 b 0xc2850 <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb+0x34> */
/* @0xc297c ldrshteq r10, [r2], -r12 */
/* @0xc2980 .word 0x0026e0f0 */

/* ── FUNC 0xc2984 · CBackground::LoadFromFile(char const*, bool, bool, bool, bool) · size=188 · insn=47 */
/* @0xc2984 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc2988 sub sp, sp, #24 */
/* @0xc298c mov r6, r0 */
/* @0xc2990 mov r0, r1 */
/* @0xc2994 mov r4, r1 */
/* @0xc2998 mov r10, r2 */
/* @0xc299c mov r1, #0 */
/* @0xc29a0 mov r9, r3 */
/* @0xc29a4 ldrb r8, [sp, #0x38] */
/* @0xc29a8 str r1, [sp, #0x14] */
/* @0xc29ac ldrb r7, [sp, #0x3c] */
/* @0xc29b0 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0xc29b4 cmp r0, #0 */
/* @0xc29b8 mov r0, r4 */
/* @0xc29bc beq 0xc2a14 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x90> */
/* @0xc29c0 add r1, sp, #20 */
/* @0xc29c4 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi> */
/* @0xc29c8 mov r5, r0 */
/* @0xc29cc mov r0, r6 */
/* @0xc29d0 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv> */
/* @0xc29d4 cmp r5, #0 */
/* @0xc29d8 beq 0xc2a00 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x7c> */
/* @0xc29dc ldr r3, [sp, #0x14] */
/* @0xc29e0 mov r0, r6 */
/* @0xc29e4 str r10, [sp] */
/* @0xc29e8 mov r1, r4 */
/* @0xc29ec str r9, [sp, #0x4] */
/* @0xc29f0 mov r2, r5 */
/* @0xc29f4 str r8, [sp, #0x8] */
/* @0xc29f8 str r7, [sp, #0xc] */
/* @0xc29fc bl 0xc281c <_ZN11CBackground16LoadFromFileDataEPKcPvibbbb> */
/* @0xc2a00 mov r0, r5 */
/* @0xc2a04 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0xc2a08 mov r0, #1 */
/* @0xc2a0c add sp, sp, #24 */
/* @0xc2a10 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0xc2a14 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0xc2a18 subs r5, r0, #0 */
/* @0xc2a1c bne 0xc2a2c <_ZN11CBackground12LoadFromFileEPKcbbbb+0xa8> */
/* @0xc2a20 mov r0, r6 */
/* @0xc2a24 bl 0xc1e3c <_ZN11CBackground11FreeTextureEv> */
/* @0xc2a28 b 0xc2a00 <_ZN11CBackground12LoadFromFileEPKcbbbb+0x7c> */
/* @0xc2a2c mov r0, r4 */
/* @0xc2a30 add r1, sp, #20 */
/* @0xc2a34 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi> */
/* @0xc2a38 mov r5, r0 */
/* @0xc2a3c b 0xc29cc <_ZN11CBackground12LoadFromFileEPKcbbbb+0x48> */

/* ── FUNC 0xc2a40 · CBackground::CreateColor(int, int, unsigned int, bool) · size=128 · insn=32 */
/* @0xc2a40 push {r4, r5, r6, r7, r8, lr} */
/* @0xc2a44 mov r4, r0 */
/* @0xc2a48 mov r5, r2 */
/* @0xc2a4c mov r6, r1 */
/* @0xc2a50 ldrb r8, [sp, #0x18] */
/* @0xc2a54 mov r7, r3 */
/* @0xc2a58 bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2a5c ldr r0, [r4, #0x10] */
/* @0xc2a60 mov r2, #0 */
/* @0xc2a64 str r6, [r4] */
/* @0xc2a68 cmp r0, r2 */
/* @0xc2a6c strb r8, [r4, #0xa] */
/* @0xc2a70 str r5, [r4, #0x4] */
/* @0xc2a74 strb r2, [r4, #0x8] */
/* @0xc2a78 strb r2, [r4, #0x9] */
/* @0xc2a7c beq 0xc2a8c <_ZN11CBackground11CreateColorEiijb+0x4c> */
/* @0xc2a80 ldr r3, [r0] */
/* @0xc2a84 ldr r3, [r3, #0x4] */
/* @0xc2a88 blx r3 */
/* @0xc2a8c mov r0, #24 */
/* @0xc2a90 bl 0x27c524 <_Znwj> */
/* @0xc2a94 mov r1, r6 */
/* @0xc2a98 mov r2, r5 */
/* @0xc2a9c mov r3, r7 */
/* @0xc2aa0 mov r8, r0 */
/* @0xc2aa4 bl 0x166140 <_ZN9CBitmap32C2Eiij> */
/* @0xc2aa8 mov r0, r4 */
/* @0xc2aac str r8, [r4, #0x10] */
/* @0xc2ab0 bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc2ab4 mov r0, r4 */
/* @0xc2ab8 pop {r4, r5, r6, r7, r8, lr} */
/* @0xc2abc b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */

/* ── FUNC 0xc2ac0 · CBackground::CreateGradient(int, int, unsigned int, unsigned int, int, bool) · size=152 · insn=38 */
/* @0xc2ac0 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc2ac4 sub sp, sp, #8 */
/* @0xc2ac8 mov r4, r0 */
/* @0xc2acc mov r5, r2 */
/* @0xc2ad0 mov r6, r1 */
/* @0xc2ad4 ldrb r10, [sp, #0x30] */
/* @0xc2ad8 mov r7, r3 */
/* @0xc2adc ldr r9, [sp, #0x28] */
/* @0xc2ae0 ldr r8, [sp, #0x2c] */
/* @0xc2ae4 bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2ae8 ldr r0, [r4, #0x10] */
/* @0xc2aec mov r2, #0 */
/* @0xc2af0 str r6, [r4] */
/* @0xc2af4 cmp r0, r2 */
/* @0xc2af8 strb r10, [r4, #0xa] */
/* @0xc2afc str r5, [r4, #0x4] */
/* @0xc2b00 strb r2, [r4, #0x8] */
/* @0xc2b04 strb r2, [r4, #0x9] */
/* @0xc2b08 beq 0xc2b18 <_ZN11CBackground14CreateGradientEiijjib+0x58> */
/* @0xc2b0c ldr r3, [r0] */
/* @0xc2b10 ldr r3, [r3, #0x4] */
/* @0xc2b14 blx r3 */
/* @0xc2b18 mov r0, #24 */
/* @0xc2b1c bl 0x27c524 <_Znwj> */
/* @0xc2b20 mov r1, r6 */
/* @0xc2b24 mov r2, r5 */
/* @0xc2b28 mov r3, r7 */
/* @0xc2b2c str r9, [sp] */
/* @0xc2b30 str r8, [sp, #0x4] */
/* @0xc2b34 mov r10, r0 */
/* @0xc2b38 bl 0x166768 <_ZN9CBitmap32C2Eiijji> */
/* @0xc2b3c mov r0, r4 */
/* @0xc2b40 str r10, [r4, #0x10] */
/* @0xc2b44 bl 0xc1e60 <_ZN11CBackground11InitTextureEv> */
/* @0xc2b48 mov r0, r4 */
/* @0xc2b4c add sp, sp, #8 */
/* @0xc2b50 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0xc2b54 b 0xc1ea0 <_ZN11CBackground12InitLocalTPEEv> */

/* ── FUNC 0xc2b58 · CBackground::CBackground() · size=40 · insn=10 */
/* @0xc2b58 push {r4, lr} */
/* @0xc2b5c mov r3, #0 */
/* @0xc2b60 mov r4, r0 */
/* @0xc2b64 mvn r2, #0 */
/* @0xc2b68 str r3, [r0, #0x10] */
/* @0xc2b6c str r2, [r0, #0xc] */
/* @0xc2b70 strb r3, [r0, #0x18] */
/* @0xc2b74 bl 0xc23c0 <_ZN11CBackground5ClearEv> */
/* @0xc2b78 mov r0, r4 */
/* @0xc2b7c pop {r4, pc} */
