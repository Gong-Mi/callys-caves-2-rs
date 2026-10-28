/* libyoyo.so 覆盖卡组 0226
 * 函数 0x25883c..0x25f6d4，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x25883c · JS_String_prototype_split(RValue&, CInstance*, CInstance*, int, RValue*) · size=1536 · insn=384 */
/* @0x25883c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x258840 add r11, sp, #32 */
/* @0x258844 ldr r4, [pc, #0x5d8] */
/* @0x258848 sub sp, sp, #268 */
/* @0x25884c sub r8, r11, #36 */
/* @0x258850 ldr r4, [pc, r4] */
/* @0x258854 str r2, [r11, #-0x100] */
/* @0x258858 str r1, [r8, #-0xd4]! */
/* @0x25885c mov r7, r0 */
/* @0x258860 ldr r2, [r4] */
/* @0x258864 mov r0, r8 */
/* @0x258868 mov r5, r1 */
/* @0x25886c mov r9, r3 */
/* @0x258870 ldr r6, [r11, #0x4] */
/* @0x258874 mov r3, #6 */
/* @0x258878 str r2, [r11, #-0x28] */
/* @0x25887c str r3, [r11, #-0xec] */
/* @0x258880 bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x258884 cmp r0, #1 */
/* @0x258888 beq 0x258a08 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x25888c sub r12, r11, #232 */
/* @0x258890 mov r1, r8 */
/* @0x258894 mov r10, #0 */
/* @0x258898 str r12, [r11, #-0x104] */
/* @0x25889c mov r0, r12 */
/* @0x2588a0 mvn r8, #-16777216 */
/* @0x2588a4 str r10, [r11, #-0xe8] */
/* @0x2588a8 str r10, [r11, #-0xe4] */
/* @0x2588ac str r10, [r11, #-0xe0] */
/* @0x2588b0 str r8, [r11, #-0xdc] */
/* @0x2588b4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2588b8 cmp r0, #2 */
/* @0x2588bc beq 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x2588c0 cmp r0, #1 */
/* @0x2588c4 beq 0x258a08 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x2588c8 str r6, [sp] */
/* @0x2588cc mov r1, r5 */
/* @0x2588d0 ldr r2, [r11, #-0x100] */
/* @0x2588d4 mov r0, r7 */
/* @0x2588d8 mov r3, r10 */
/* @0x2588dc bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x2588e0 cmp r9, #1 */
/* @0x2588e4 ble 0x258a18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x2588e8 ldr r3, [r6, #0x1c] */
/* @0x2588ec cmp r3, #5 */
/* @0x2588f0 mvneq r12, #0 */
/* @0x2588f4 streq r12, [r11, #-0x110] */
/* @0x2588f8 beq 0x25892c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0xf0> */
/* @0x2588fc sub r0, r11, #184 */
/* @0x258900 add r1, r6, #16 */
/* @0x258904 str r10, [r11, #-0xb8] */
/* @0x258908 str r10, [r11, #-0xb4] */
/* @0x25890c str r10, [r11, #-0xb0] */
/* @0x258910 str r8, [r11, #-0xac] */
/* @0x258914 bl 0x24d4f4 <_Z13F_JS_ToUint32R6RValueS0_> */
/* @0x258918 ldr r2, [r11, #-0xb8] */
/* @0x25891c ldr r3, [r11, #-0xb4] */
/* @0x258920 vmov d7, r2, r3 */
/* @0x258924 vcvt.s32.f64 s15, d7 */
/* @0x258928 vstr s15, [r11, #-272] */
/* @0x25892c ldr r5, [r11, #-0xe8] */
/* @0x258930 ldr r0, [r5] */
/* @0x258934 bl 0xb6538 <strlen@plt> */
/* @0x258938 mov r3, #0 */
/* @0x25893c mvn r2, #-16777216 */
/* @0x258940 str r3, [r11, #-0xd8] */
/* @0x258944 str r3, [r11, #-0xd4] */
/* @0x258948 str r3, [r11, #-0xd0] */
/* @0x25894c str r2, [r11, #-0xcc] */
/* @0x258950 str r0, [r11, #-0x100] */
/* @0x258954 ldr r3, [r6, #0xc] */
/* @0x258958 cmp r3, #5 */
/* @0x25895c beq 0x258a40 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x258960 bic r3, r3, #-16777216 */
/* @0x258964 cmp r3, #6 */
/* @0x258968 beq 0x258a58 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x25896c sub r12, r11, #216 */
/* @0x258970 mov r1, r6 */
/* @0x258974 str r12, [r11, #-0x118] */
/* @0x258978 mov r0, r12 */
/* @0x25897c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x258980 cmp r0, #2 */
/* @0x258984 beq 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258988 cmp r0, #1 */
/* @0x25898c beq 0x258aa8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x258990 ldr r12, [r11, #-0x110] */
/* @0x258994 cmp r12, #0 */
/* @0x258998 bne 0x258ad0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x25899c ldr r3, [r11, #-0xcc] */
/* @0x2589a0 sub r3, r3, #1 */
/* @0x2589a4 bic r3, r3, #-16777216 */
/* @0x2589a8 bic r3, r3, #3 */
/* @0x2589ac cmp r3, #0 */
/* @0x2589b0 bne 0x2589bc <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x2589b4 sub r0, r11, #216 */
/* @0x2589b8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2589bc ldr r1, [r11, #-0xdc] */
/* @0x2589c0 mov r3, #0 */
/* @0x2589c4 str r3, [r11, #-0xd0] */
/* @0x2589c8 mov r2, #5 */
/* @0x2589cc sub r1, r1, #1 */
/* @0x2589d0 str r3, [r11, #-0xd8] */
/* @0x2589d4 bic r3, r1, #-16777216 */
/* @0x2589d8 str r2, [r11, #-0xcc] */
/* @0x2589dc bic r3, r3, #3 */
/* @0x2589e0 cmp r3, #0 */
/* @0x2589e4 bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x2589e8 sub r0, r11, #232 */
/* @0x2589ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2589f0 ldr r2, [r11, #-0x28] */
/* @0x2589f4 ldr r3, [r4] */
/* @0x2589f8 cmp r2, r3 */
/* @0x2589fc bne 0x258e14 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5d8> */
/* @0x258a00 sub sp, r11, #32 */
/* @0x258a04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x258a08 ldr r0, [pc, #0x418] */
/* @0x258a0c add r0, pc, r0 */
/* @0x258a10 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x258a14 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258a18 ldr r5, [r11, #-0xe8] */
/* @0x258a1c ldr r0, [r5] */
/* @0x258a20 bl 0xb6538 <strlen@plt> */
/* @0x258a24 cmp r9, #0 */
/* @0x258a28 str r10, [r11, #-0xd8] */
/* @0x258a2c str r10, [r11, #-0xd4] */
/* @0x258a30 str r10, [r11, #-0xd0] */
/* @0x258a34 str r8, [r11, #-0xcc] */
/* @0x258a38 str r0, [r11, #-0x100] */
/* @0x258a3c bne 0x258e18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5dc> */
/* @0x258a40 ldr r2, [pc, #0x3e4] */
/* @0x258a44 sub r1, r11, #232 */
/* @0x258a48 ldr r0, [r7] */
/* @0x258a4c add r2, pc, r2 */
/* @0x258a50 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x258a54 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258a58 ldr r8, [r6] */
/* @0x258a5c ldr r1, [pc, #0x3cc] */
/* @0x258a60 ldr r0, [r8, #0x40] */
/* @0x258a64 add r1, pc, r1 */
/* @0x258a68 bl 0xb6574 <strcmp@plt> */
/* @0x258a6c cmp r0, #0 */
/* @0x258a70 bne 0x25896c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x258a74 ldr r12, [r11, #-0x110] */
/* @0x258a78 cmp r12, #0 */
/* @0x258a7c beq 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x258a80 ldr r12, [r11, #-0x100] */
/* @0x258a84 sub r3, r11, #232 */
/* @0x258a88 ldr r2, [r5] */
/* @0x258a8c mov r0, r7 */
/* @0x258a90 str r3, [sp, #0x4] */
/* @0x258a94 mov r1, r8 */
/* @0x258a98 str r12, [sp] */
/* @0x258a9c ldr r3, [r11, #-0x110] */
/* @0x258aa0 bl 0x2486b8 <_Z31JS_String_prototype_split_RegExR6RValueP12YYObjectBasePKciiPS_> */
/* @0x258aa4 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x258aa8 ldr r0, [pc, #0x384] */
/* @0x258aac add r0, pc, r0 */
/* @0x258ab0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x258ab4 ldr r3, [r11, #-0xdc] */
/* @0x258ab8 sub r3, r3, #1 */
/* @0x258abc bic r3, r3, #-16777216 */
/* @0x258ac0 bic r3, r3, #3 */
/* @0x258ac4 cmp r3, #0 */
/* @0x258ac8 bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258acc b 0x2589e8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x258ad0 ldr r12, [r11, #-0x100] */
/* @0x258ad4 cmp r12, #0 */
/* @0x258ad8 beq 0x258dac <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x570> */
/* @0x258adc mov r10, #0 */
/* @0x258ae0 mov r3, r7 */
/* @0x258ae4 sub r12, r11, #184 */
/* @0x258ae8 mov r8, r10 */
/* @0x258aec str r12, [r11, #-0x114] */
/* @0x258af0 mov r9, r10 */
/* @0x258af4 sub r12, r11, #200 */
/* @0x258af8 mov r5, r10 */
/* @0x258afc str r12, [r11, #-0x108] */
/* @0x258b00 mov r7, r10 */
/* @0x258b04 sub r12, r11, #168 */
/* @0x258b08 str r4, [r11, #-0x11c] */
/* @0x258b0c str r12, [r11, #-0x10c] */
/* @0x258b10 mov r10, r3 */
/* @0x258b14 b 0x258c28 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x258b18 rsb r12, r8, r7 */
/* @0x258b1c mov r1, #0 */
/* @0x258b20 add r3, r12, #15 */
/* @0x258b24 add r2, r12, #1 */
/* @0x258b28 bic r3, r3, #7 */
/* @0x258b2c str r12, [r11, #-0x120] */
/* @0x258b30 sub sp, sp, r3 */
/* @0x258b34 add r7, sp, #8 */
/* @0x258b38 mov r0, r7 */
/* @0x258b3c bl 0xb65b0 <memset@plt> */
/* @0x258b40 ldr r1, [r11, #-0xe8] */
/* @0x258b44 ldr r12, [r11, #-0x120] */
/* @0x258b48 mov r0, r7 */
/* @0x258b4c ldr r1, [r1] */
/* @0x258b50 mov r2, r12 */
/* @0x258b54 add r1, r1, r8 */
/* @0x258b58 bl 0xb6568 <strncpy@plt> */
/* @0x258b5c mov r1, r7 */
/* @0x258b60 sub r0, r11, #200 */
/* @0x258b64 mvn r3, #-16777216 */
/* @0x258b68 str r5, [r11, #-0xc8] */
/* @0x258b6c str r3, [r11, #-0xbc] */
/* @0x258b70 str r5, [r11, #-0xc4] */
/* @0x258b74 str r5, [r11, #-0xc0] */
/* @0x258b78 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x258b7c mov r2, #0 */
/* @0x258b80 ldr r1, [r10] */
/* @0x258b84 mov r3, r2 */
/* @0x258b88 sub r0, r11, #184 */
/* @0x258b8c str r5, [sp] */
/* @0x258b90 mvn r12, #-16777216 */
/* @0x258b94 str r5, [r11, #-0xb8] */
/* @0x258b98 str r12, [r11, #-0xac] */
/* @0x258b9c str r5, [r11, #-0xb4] */
/* @0x258ba0 str r5, [r11, #-0xb0] */
/* @0x258ba4 bl 0x23ce24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_> */
/* @0x258ba8 vldr s14, [r11, #-184] */
/* @0x258bac vldr s15, [r11, #-180] */
/* @0x258bb0 vcvt.s32.f64 s13, d7 */
/* @0x258bb4 sub r1, r11, #168 */
/* @0x258bb8 mov r2, #10 */
/* @0x258bbc vmov r0, s13 */
/* @0x258bc0 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x258bc4 ldr r0, [r10] */
/* @0x258bc8 sub r1, r11, #200 */
/* @0x258bcc sub r2, r11, #168 */
/* @0x258bd0 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x258bd4 ldr r3, [r11, #-0xbc] */
/* @0x258bd8 sub r3, r3, #1 */
/* @0x258bdc bic r3, r3, #-16777216 */
/* @0x258be0 bic r3, r3, #3 */
/* @0x258be4 cmp r3, #0 */
/* @0x258be8 beq 0x258c5c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x420> */
/* @0x258bec ldr r12, [r11, #-0x110] */
/* @0x258bf0 add r9, r9, #1 */
/* @0x258bf4 mov r3, #5 */
/* @0x258bf8 str r5, [r11, #-0xc0] */
/* @0x258bfc cmp r9, r12 */
/* @0x258c00 str r3, [r11, #-0xbc] */
/* @0x258c04 str r5, [r11, #-0xc8] */
/* @0x258c08 beq 0x258dd4 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x598> */
/* @0x258c0c mov r7, r4 */
/* @0x258c10 mov r8, r4 */
/* @0x258c14 mov r0, r6 */
/* @0x258c18 bl 0x27d1d0 <_ZdlPv> */
/* @0x258c1c ldr r12, [r11, #-0x100] */
/* @0x258c20 cmp r7, r12 */
/* @0x258c24 beq 0x258c68 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x42c> */
/* @0x258c28 ldr r2, [r11, #-0xe8] */
/* @0x258c2c mov r1, r7 */
/* @0x258c30 ldr r3, [r11, #-0xd8] */
/* @0x258c34 ldr r0, [r2] */
/* @0x258c38 ldr r2, [r3] */
/* @0x258c3c bl 0x242604 <_Z13JS_SplitMatchPKciS0_> */
/* @0x258c40 subs r6, r0, #0 */
/* @0x258c44 beq 0x258c54 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x418> */
/* @0x258c48 ldr r4, [r6] */
/* @0x258c4c cmp r4, r8 */
/* @0x258c50 bne 0x258b18 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x2dc> */
/* @0x258c54 add r7, r7, #1 */
/* @0x258c58 b 0x258c14 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3d8> */
/* @0x258c5c sub r0, r11, #200 */
/* @0x258c60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x258c64 b 0x258bec <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x3b0> */
/* @0x258c68 mov r3, r10 */
/* @0x258c6c mov r10, r7 */
/* @0x258c70 rsb r10, r8, r10 */
/* @0x258c74 mov r7, r3 */
/* @0x258c78 add r3, r10, #15 */
/* @0x258c7c mov r1, #0 */
/* @0x258c80 bic r3, r3, #7 */
/* @0x258c84 add r2, r10, #1 */
/* @0x258c88 sub sp, sp, r3 */
/* @0x258c8c mov r5, r1 */
/* @0x258c90 add r9, sp, #8 */
/* @0x258c94 ldr r4, [r11, #-0x11c] */
/* @0x258c98 mvn r6, #-16777216 */
/* @0x258c9c mov r0, r9 */
/* @0x258ca0 bl 0xb65b0 <memset@plt> */
/* @0x258ca4 ldr r3, [r11, #-0xe8] */
/* @0x258ca8 mov r2, r10 */
/* @0x258cac mov r0, r9 */
/* @0x258cb0 ldr r1, [r3] */
/* @0x258cb4 add r1, r1, r8 */
/* @0x258cb8 bl 0xb6568 <strncpy@plt> */
/* @0x258cbc mov r1, r9 */
/* @0x258cc0 sub r0, r11, #200 */
/* @0x258cc4 str r5, [r11, #-0xc8] */
/* @0x258cc8 str r5, [r11, #-0xc4] */
/* @0x258ccc str r5, [r11, #-0xc0] */
/* @0x258cd0 str r6, [r11, #-0xbc] */
/* @0x258cd4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x258cd8 mov r3, r5 */
/* @0x258cdc ldr r1, [r7] */
/* @0x258ce0 mov r2, r5 */
/* @0x258ce4 sub r0, r11, #184 */
/* @0x258ce8 str r5, [sp] */
/* @0x258cec str r5, [r11, #-0xb8] */
/* @0x258cf0 str r5, [r11, #-0xb4] */
/* @0x258cf4 str r5, [r11, #-0xb0] */
/* @0x258cf8 str r6, [r11, #-0xac] */
/* @0x258cfc bl 0x23ce24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_> */
/* @0x258d00 ldr r8, [r11, #-0xb8] */
/* @0x258d04 sub r1, r11, #168 */
/* @0x258d08 ldr r9, [r11, #-0xb4] */
/* @0x258d0c mov r2, #10 */
/* @0x258d10 vmov d7, r8, r9 */
/* @0x258d14 vcvt.s32.f64 s15, d7 */
/* @0x258d18 vmov r0, s15 */
/* @0x258d1c bl 0xc4964 <_Z5_itoaiPci> */
/* @0x258d20 ldr r0, [r7] */
/* @0x258d24 sub r2, r11, #168 */
/* @0x258d28 sub r1, r11, #200 */
/* @0x258d2c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x258d30 ldr r3, [r11, #-0xcc] */
/* @0x258d34 sub r3, r3, #1 */
/* @0x258d38 and r3, r3, r6 */
/* @0x258d3c bic r3, r3, #3 */
/* @0x258d40 cmp r3, r5 */
/* @0x258d44 beq 0x258dec <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5b0> */
/* @0x258d48 ldr r1, [r11, #-0xdc] */
/* @0x258d4c mov r3, #0 */
/* @0x258d50 str r3, [r11, #-0xd0] */
/* @0x258d54 mov r2, #5 */
/* @0x258d58 sub r1, r1, #1 */
/* @0x258d5c str r3, [r11, #-0xd8] */
/* @0x258d60 bic r3, r1, #-16777216 */
/* @0x258d64 str r2, [r11, #-0xcc] */
/* @0x258d68 bic r3, r3, #3 */
/* @0x258d6c cmp r3, #0 */
/* @0x258d70 beq 0x258de0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5a4> */
/* @0x258d74 ldr r1, [r11, #-0xbc] */
/* @0x258d78 mov r3, #0 */
/* @0x258d7c str r3, [r11, #-0xe0] */
/* @0x258d80 mov r2, #5 */
/* @0x258d84 sub r1, r1, #1 */
/* @0x258d88 str r3, [r11, #-0xe8] */
/* @0x258d8c bic r3, r1, #-16777216 */
/* @0x258d90 str r2, [r11, #-0xdc] */
/* @0x258d94 bic r3, r3, #3 */
/* @0x258d98 cmp r3, #0 */
/* @0x258d9c bne 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258da0 sub r0, r11, #200 */
/* @0x258da4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x258da8 b 0x2589f0 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x258dac ldr r2, [r11, #-0xe8] */
/* @0x258db0 mov r1, r12 */
/* @0x258db4 ldr r3, [r11, #-0xd8] */
/* @0x258db8 ldr r0, [r2] */
/* @0x258dbc ldr r2, [r3] */
/* @0x258dc0 bl 0x242604 <_Z13JS_SplitMatchPKciS0_> */
/* @0x258dc4 cmp r0, #0 */
/* @0x258dc8 beq 0x258df8 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x5bc> */
/* @0x258dcc bl 0x27d1d0 <_ZdlPv> */
/* @0x258dd0 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x258dd4 ldr r4, [r11, #-0x11c] */
/* @0x258dd8 mov r0, r6 */
/* @0x258ddc b 0x258dcc <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x590> */
/* @0x258de0 sub r0, r11, #232 */
/* @0x258de4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x258de8 b 0x258d74 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x538> */
/* @0x258dec sub r0, r11, #216 */
/* @0x258df0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x258df4 b 0x258d48 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x50c> */
/* @0x258df8 bl 0x27d1d0 <_ZdlPv> */
/* @0x258dfc ldr r2, [pc, #0x34] */
/* @0x258e00 ldr r0, [r7] */
/* @0x258e04 sub r1, r11, #232 */
/* @0x258e08 add r2, pc, r2 */
/* @0x258e0c bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x258e10 b 0x25899c <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x258e14 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x258e18 mvn r12, #0 */
/* @0x258e1c str r12, [r11, #-0x110] */
/* @0x258e20 b 0x258954 <_Z25JS_String_prototype_splitR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x258e24 andseq r5, r9, r0, lsl #2 */
/* @0x258e28 andeq sp, pc, r12, lsr r5 */
/* @0x258e2c andeq r9, sp, r0, lsr #21 */
/* @0x258e30 andeq sp, pc, r8, asr #3 */
/* @0x258e34 muleq pc, r12, r4 */
/* @0x258e38 andeq r9, sp, r4, ror #13 */

/* ── FUNC 0x258e3c · JS_String_prototype_replace_RegEx(RValue&, CInstance*, CInstance*, YYObjectBase*, RValue*, RValue*) · size=1040 · insn=260 */
/* @0x258e3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x258e40 add r11, sp, #32 */
/* @0x258e44 sub sp, sp, #948 */
/* @0x258e48 ldr r2, [pc, #0x3ec] */
/* @0x258e4c str r3, [r11, #-0x394] */
/* @0x258e50 ldr r3, [r11, #0x8] */
/* @0x258e54 ldr r2, [pc, r2] */
/* @0x258e58 ldr lr, [r11, #0x4] */
/* @0x258e5c sub r4, r11, #888 */
/* @0x258e60 str r2, [r11, #-0x3a4] */
/* @0x258e64 mov r5, #0 */
/* @0x258e68 str r3, [r11, #-0x3a0] */
/* @0x258e6c ldr r3, [r2] */
/* @0x258e70 ldr r2, [pc, #0x3c8] */
/* @0x258e74 str r0, [r11, #-0x3b8] */
/* @0x258e78 add r2, pc, r2 */
/* @0x258e7c str r1, [r11, #-0x3b0] */
/* @0x258e80 ldr r0, [r11, #-0x394] */
/* @0x258e84 mov r1, r4 */
/* @0x258e88 str r3, [r11, #-0x28] */
/* @0x258e8c str lr, [r11, #-0x3ac] */
/* @0x258e90 str r5, [r11, #-0x378] */
/* @0x258e94 str r5, [r11, #-0x374] */
/* @0x258e98 str r5, [r11, #-0x370] */
/* @0x258e9c str r5, [r11, #-0x36c] */
/* @0x258ea0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x258ea4 mov r0, r4 */
/* @0x258ea8 mov r1, r5 */
/* @0x258eac bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x258eb0 str r5, [r11, #-0x368] */
/* @0x258eb4 str r5, [r11, #-0x364] */
/* @0x258eb8 str r5, [r11, #-0x360] */
/* @0x258ebc str r5, [r11, #-0x35c] */
/* @0x258ec0 mov r4, r0 */
/* @0x258ec4 ldr r0, [r11, #-0x3a0] */
/* @0x258ec8 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x258ecc cmp r0, #0 */
/* @0x258ed0 str r0, [r11, #-0x3a8] */
/* @0x258ed4 bne 0x25908c <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x250> */
/* @0x258ed8 ldr r2, [r11, #-0x3a8] */
/* @0x258edc sub r0, r11, #872 */
/* @0x258ee0 ldr r1, [r11, #-0x3a0] */
/* @0x258ee4 mvn r3, #-16777216 */
/* @0x258ee8 str r3, [r11, #-0x35c] */
/* @0x258eec str r2, [r11, #-0x368] */
/* @0x258ef0 str r2, [r11, #-0x364] */
/* @0x258ef4 str r2, [r11, #-0x360] */
/* @0x258ef8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x258efc cmp r0, #1 */
/* @0x258f00 beq 0x259228 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3ec> */
/* @0x258f04 mov r5, #0 */
/* @0x258f08 ldr r0, [r11, #-0x3ac] */
/* @0x258f0c mov r1, r5 */
/* @0x258f10 str r5, [r11, #-0x384] */
/* @0x258f14 str r5, [r11, #-0x380] */
/* @0x258f18 str r5, [r11, #-0x37c] */
/* @0x258f1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x258f20 mov r6, r0 */
/* @0x258f24 bl 0xb6538 <strlen@plt> */
/* @0x258f28 ldr lr, [r11, #-0x394] */
/* @0x258f2c mov r2, #2 */
/* @0x258f30 sub r3, r11, #908 */
/* @0x258f34 str r5, [r11, #-0x388] */
/* @0x258f38 ldr r1, [lr, #0x20] */
/* @0x258f3c str r0, [r11, #-0x398] */
/* @0x258f40 ldr r0, [lr, #0x1c] */
/* @0x258f44 bl 0x25ee20 <pcre_fullinfo> */
/* @0x258f48 cmp r4, r5 */
/* @0x258f4c bne 0x2590ac <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x270> */
/* @0x258f50 sub r5, r11, #840 */
/* @0x258f54 str r4, [sp, #0x8] */
/* @0x258f58 ldr r2, [r11, #-0x398] */
/* @0x258f5c mov r1, #100 */
/* @0x258f60 mov r3, r5 */
/* @0x258f64 str r1, [sp] */
/* @0x258f68 ldr r0, [r11, #-0x394] */
/* @0x258f6c sub r1, r11, #904 */
/* @0x258f70 str r1, [sp, #0x4] */
/* @0x258f74 mov r1, r6 */
/* @0x258f78 bl 0x24f2b0 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i> */
/* @0x258f7c ldr r2, [r11, #-0x388] */
/* @0x258f80 cmp r2, #0 */
/* @0x258f84 add r3, r2, r2, lsl #1 */
/* @0x258f88 str r2, [r11, #-0x1b8] */
/* @0x258f8c movgt r8, r4 */
/* @0x258f90 movgt r7, r5 */
/* @0x258f94 lsl r3, r3, #2 */
/* @0x258f98 add r3, r3, #14 */
/* @0x258f9c bic r3, r3, #7 */
/* @0x258fa0 sub sp, sp, r3 */
/* @0x258fa4 add r1, sp, #24 */
/* @0x258fa8 str r1, [r11, #-0x1b4] */
/* @0x258fac mov r9, r0 */
/* @0x258fb0 bgt 0x258fbc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x180> */
/* @0x258fb4 b 0x259000 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x1c4> */
/* @0x258fb8 ldr r1, [r11, #-0x1b4] */
/* @0x258fbc ldr r0, [r7] */
/* @0x258fc0 add r3, r1, r4 */
/* @0x258fc4 add r12, r3, #8 */
/* @0x258fc8 add r7, r7, #8 */
/* @0x258fcc str r0, [r1, r4] */
/* @0x258fd0 mov r0, r6 */
/* @0x258fd4 ldr lr, [r7, #-0x4] */
/* @0x258fd8 mov r1, r5 */
/* @0x258fdc add r4, r4, #12 */
/* @0x258fe0 str lr, [r3, #0x4] */
/* @0x258fe4 mov r3, r8 */
/* @0x258fe8 str r12, [sp] */
/* @0x258fec add r8, r8, #1 */
/* @0x258ff0 bl 0x25f5e8 <pcre_get_substring> */
/* @0x258ff4 ldr r2, [r11, #-0x388] */
/* @0x258ff8 cmp r2, r8 */
/* @0x258ffc bgt 0x258fb8 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x17c> */
/* @0x259000 ldr r1, [r11, #-0x3ac] */
/* @0x259004 mov r0, #0 */
/* @0x259008 mov r12, #1 */
/* @0x25900c str r0, [sp, #0x4] */
/* @0x259010 str r12, [sp, #0xc] */
/* @0x259014 sub r0, r11, #856 */
/* @0x259018 str r1, [sp] */
/* @0x25901c sub r12, r11, #440 */
/* @0x259020 str r0, [sp, #0x8] */
/* @0x259024 sub r0, r11, #900 */
/* @0x259028 ldr r1, [r11, #-0x3b0] */
/* @0x25902c str r9, [sp, #0x10] */
/* @0x259030 ldr r2, [r11, #-0x3a8] */
/* @0x259034 ldr r3, [r11, #-0x3a0] */
/* @0x259038 str r12, [r11, #-0x358] */
/* @0x25903c bl 0x24a99c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii> */
/* @0x259040 ldr r3, [r11, #-0x37c] */
/* @0x259044 ldr r0, [r11, #-0x3b8] */
/* @0x259048 cmp r3, #0 */
/* @0x25904c mov r3, #0 */
/* @0x259050 subeq r1, r11, #892 */
/* @0x259054 str r3, [r11, #-0x37c] */
/* @0x259058 ldrne r1, [r11, #-0x384] */
/* @0x25905c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x259060 ldr r0, [r11, #-0x384] */
/* @0x259064 cmp r0, #0 */
/* @0x259068 beq 0x259070 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x234> */
/* @0x25906c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259070 ldr r1, [r11, #-0x3a4] */
/* @0x259074 ldr r2, [r11, #-0x28] */
/* @0x259078 ldr r3, [r1] */
/* @0x25907c cmp r2, r3 */
/* @0x259080 bne 0x259238 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3fc> */
/* @0x259084 sub sp, r11, #32 */
/* @0x259088 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25908c ldr r3, [r11, #-0x3a0] */
/* @0x259090 sub r12, r11, #872 */
/* @0x259094 ldr r0, [r3] */
/* @0x259098 ldr r1, [r3, #0x4] */
/* @0x25909c ldr r2, [r3, #0x8] */
/* @0x2590a0 ldr r3, [r3, #0xc] */
/* @0x2590a4 stm r12!, {r0, r1, r2, r3} */
/* @0x2590a8 b 0x258f04 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0xc8> */
/* @0x2590ac sub r2, r11, #440 */
/* @0x2590b0 str r2, [r11, #-0x3b4] */
/* @0x2590b4 ldr r2, [pc, #0x188] */
/* @0x2590b8 mov r3, r5 */
/* @0x2590bc ldr r0, [r11, #-0x394] */
/* @0x2590c0 sub r1, r11, #856 */
/* @0x2590c4 add r2, pc, r2 */
/* @0x2590c8 str r5, [r11, #-0x34c] */
/* @0x2590cc str r5, [r11, #-0x358] */
/* @0x2590d0 str r5, [r11, #-0x390] */
/* @0x2590d4 str r5, [r11, #-0x354] */
/* @0x2590d8 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x2590dc mov r1, r5 */
/* @0x2590e0 sub r5, r11, #840 */
/* @0x2590e4 sub r0, r11, #440 */
/* @0x2590e8 mov r2, #400 */
/* @0x2590ec ldr r9, [r11, #-0x390] */
/* @0x2590f0 bl 0xb65b0 <memset@plt> */
/* @0x2590f4 sub r3, r11, #904 */
/* @0x2590f8 str r3, [r11, #-0x39c] */
/* @0x2590fc mov r3, #100 */
/* @0x259100 sub lr, r11, #904 */
/* @0x259104 str r3, [sp] */
/* @0x259108 mov r1, r6 */
/* @0x25910c ldr r0, [r11, #-0x394] */
/* @0x259110 mov r3, r5 */
/* @0x259114 str lr, [sp, #0x4] */
/* @0x259118 str r9, [sp, #0x8] */
/* @0x25911c ldr r2, [r11, #-0x398] */
/* @0x259120 bl 0x24f2b0 <_Z12DoRegExpExecP12YYObjectBasePKciPiiS3_i> */
/* @0x259124 cmn r0, #1 */
/* @0x259128 mov r8, r0 */
/* @0x25912c beq 0x2591ec <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3b0> */
/* @0x259130 ldr r2, [r11, #-0x388] */
/* @0x259134 sub sp, sp, #24 */
/* @0x259138 add r7, sp, #24 */
/* @0x25913c cmp r2, #0 */
/* @0x259140 add r3, r2, r2, lsl #1 */
/* @0x259144 str r2, [r7] */
/* @0x259148 movgt r10, r5 */
/* @0x25914c movgt r4, #0 */
/* @0x259150 lsl r3, r3, #2 */
/* @0x259154 add r3, r3, #14 */
/* @0x259158 bic r3, r3, #7 */
/* @0x25915c sub sp, sp, r3 */
/* @0x259160 add r3, sp, #24 */
/* @0x259164 str r3, [r7, #0x4] */
/* @0x259168 bgt 0x259174 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x338> */
/* @0x25916c b 0x2591b8 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x37c> */
/* @0x259170 ldr r3, [r7, #0x4] */
/* @0x259174 ldr r12, [r10] */
/* @0x259178 add r1, r4, r4, lsl #1 */
/* @0x25917c mov r0, r6 */
/* @0x259180 add r10, r10, #8 */
/* @0x259184 str r12, [r3, r1, lsl #2] */
/* @0x259188 add r3, r3, r1, lsl #2 */
/* @0x25918c ldr lr, [r10, #-0x4] */
/* @0x259190 add r12, r3, #8 */
/* @0x259194 mov r1, r5 */
/* @0x259198 str lr, [r3, #0x4] */
/* @0x25919c mov r3, r4 */
/* @0x2591a0 str r12, [sp] */
/* @0x2591a4 add r4, r4, #1 */
/* @0x2591a8 bl 0x25f5e8 <pcre_get_substring> */
/* @0x2591ac ldr r2, [r11, #-0x388] */
/* @0x2591b0 cmp r2, r4 */
/* @0x2591b4 bgt 0x259170 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x334> */
/* @0x2591b8 ldr lr, [r11, #-0x390] */
/* @0x2591bc cmp lr, #99 */
/* @0x2591c0 bhi 0x2591dc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x3a0> */
/* @0x2591c4 ldr r1, [r11, #-0x390] */
/* @0x2591c8 sub r2, r11, #36 */
/* @0x2591cc add r3, r2, r1, lsl #2 */
/* @0x2591d0 add r1, r1, #1 */
/* @0x2591d4 str r1, [r11, #-0x390] */
/* @0x2591d8 str r7, [r3, #-0x194] */
/* @0x2591dc cmp r9, r8 */
/* @0x2591e0 addeq r8, r8, #1 */
/* @0x2591e4 mov r9, r8 */
/* @0x2591e8 b 0x2590fc <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x2c0> */
/* @0x2591ec ldr r1, [r11, #-0x3ac] */
/* @0x2591f0 sub r2, r11, #440 */
/* @0x2591f4 ldr r3, [r11, #-0x390] */
/* @0x2591f8 mov r12, #0 */
/* @0x2591fc str r2, [sp, #0x8] */
/* @0x259200 sub r0, r11, #900 */
/* @0x259204 str r1, [sp] */
/* @0x259208 str r3, [sp, #0xc] */
/* @0x25920c ldr r1, [r11, #-0x3b0] */
/* @0x259210 ldr r2, [r11, #-0x3a8] */
/* @0x259214 ldr r3, [r11, #-0x3a0] */
/* @0x259218 str r12, [sp, #0x4] */
/* @0x25921c str r12, [sp, #0x10] */
/* @0x259220 bl 0x24a99c <_Z9DoReplaceR12YYStrBuilderP9CInstancebP6RValueS4_iPP8SMatchesii> */
/* @0x259224 b 0x259040 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x204> */
/* @0x259228 ldr r0, [pc, #0x18] */
/* @0x25922c add r0, pc, r0 */
/* @0x259230 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259234 b 0x259070 <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_+0x234> */
/* @0x259238 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x25923c ldrsheq r4, [r9], -r12 */
/* @0x259240 andeq r12, sp, r0, rrx */
/* @0x259244 ldrdeq r12, sp, [pc], -r12 */
/* @0x259248 andeq r12, pc, r12, lsl sp */

/* ── FUNC 0x25924c · JS_String_prototype_replace(RValue&, CInstance*, CInstance*, int, RValue*) · size=1136 · insn=284 */
/* @0x25924c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x259250 add r11, sp, #32 */
/* @0x259254 ldr r4, [pc, #0x43c] */
/* @0x259258 sub sp, sp, #164 */
/* @0x25925c sub r10, r11, #36 */
/* @0x259260 ldr r4, [pc, r4] */
/* @0x259264 str r0, [r11, #-0xa0] */
/* @0x259268 str r1, [r10, #-0x74]! */
/* @0x25926c mov r0, r10 */
/* @0x259270 ldr r3, [r4] */
/* @0x259274 mov r7, r1 */
/* @0x259278 mov r9, r2 */
/* @0x25927c ldr r5, [r11, #0x4] */
/* @0x259280 mov r2, #6 */
/* @0x259284 str r2, [r11, #-0x8c] */
/* @0x259288 str r3, [r11, #-0x28] */
/* @0x25928c bl 0x2423a4 <_Z23JS_CheckObjectCoercibleR6RValue> */
/* @0x259290 cmp r0, #1 */
/* @0x259294 beq 0x259428 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x259298 sub r8, r11, #136 */
/* @0x25929c mov r1, r10 */
/* @0x2592a0 mov r3, #0 */
/* @0x2592a4 mvn r2, #-16777216 */
/* @0x2592a8 mov r0, r8 */
/* @0x2592ac str r3, [r11, #-0x88] */
/* @0x2592b0 str r3, [r11, #-0x84] */
/* @0x2592b4 str r3, [r11, #-0x80] */
/* @0x2592b8 str r2, [r11, #-0x7c] */
/* @0x2592bc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2592c0 cmp r0, #1 */
/* @0x2592c4 beq 0x259428 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x2592c8 ldr r2, [r5, #0xc] */
/* @0x2592cc ldr r3, [r11, #-0x88] */
/* @0x2592d0 bic r2, r2, #-16777216 */
/* @0x2592d4 cmp r2, #6 */
/* @0x2592d8 ldr r6, [r3] */
/* @0x2592dc beq 0x25944c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x2592e0 sub r9, r11, #120 */
/* @0x2592e4 mov r1, r5 */
/* @0x2592e8 mov r7, #0 */
/* @0x2592ec mvn r10, #-16777216 */
/* @0x2592f0 mov r0, r9 */
/* @0x2592f4 str r7, [r11, #-0x78] */
/* @0x2592f8 str r7, [r11, #-0x74] */
/* @0x2592fc str r7, [r11, #-0x70] */
/* @0x259300 str r10, [r11, #-0x6c] */
/* @0x259304 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259308 cmp r0, #1 */
/* @0x25930c beq 0x25948c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x240> */
/* @0x259310 ldr r3, [r11, #-0x78] */
/* @0x259314 mov r0, r6 */
/* @0x259318 ldr r3, [r3] */
/* @0x25931c mov r1, r3 */
/* @0x259320 str r3, [r11, #-0xa8] */
/* @0x259324 bl 0x110c04 <_Z11utf8_strstrPKcS0_> */
/* @0x259328 cmp r0, #0 */
/* @0x25932c str r0, [r11, #-0xac] */
/* @0x259330 beq 0x2595e4 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x398> */
/* @0x259334 add r5, r5, #16 */
/* @0x259338 mov r0, r5 */
/* @0x25933c bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x259340 cmp r0, #0 */
/* @0x259344 str r0, [r11, #-0xa4] */
/* @0x259348 beq 0x25949c <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x25934c ldr r12, [r11, #-0xac] */
/* @0x259350 sub lr, r11, #88 */
/* @0x259354 ldm r9, {r0, r1, r2, r3} */
/* @0x259358 rsb r9, r6, r12 */
/* @0x25935c ldr r12, [pc, #0x338] */
/* @0x259360 vmov s13, r9 */
/* @0x259364 str r7, [r11, #-0x68] */
/* @0x259368 ldr r12, [pc, r12] */
/* @0x25936c str r7, [r11, #-0x64] */
/* @0x259370 vcvt.f64.s32 d7, s13 */
/* @0x259374 str r7, [r11, #-0x60] */
/* @0x259378 stm lr, {r0, r1, r2, r3} */
/* @0x25937c ldm r8, {r0, r1, r2, r3} */
/* @0x259380 ldr r12, [r12] */
/* @0x259384 str lr, [sp] */
/* @0x259388 sub lr, r11, #56 */
/* @0x25938c str r10, [r11, #-0x5c] */
/* @0x259390 stm lr, {r0, r1, r2, r3} */
/* @0x259394 vstr s14, [r11, #-72] */
/* @0x259398 mov r2, r5 */
/* @0x25939c vstr s15, [r11, #-68] */
/* @0x2593a0 sub r1, r11, #104 */
/* @0x2593a4 mov r0, r12 */
/* @0x2593a8 mov r3, #3 */
/* @0x2593ac str r7, [r11, #-0x3c] */
/* @0x2593b0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x2593b4 ldr r3, [r11, #-0x68] */
/* @0x2593b8 ldr r8, [r3] */
/* @0x2593bc mov r0, r8 */
/* @0x2593c0 bl 0xb6538 <strlen@plt> */
/* @0x2593c4 mov r7, r0 */
/* @0x2593c8 mov r0, r6 */
/* @0x2593cc bl 0xb6538 <strlen@plt> */
/* @0x2593d0 add r7, r0, r7 */
/* @0x2593d4 ldr r0, [r11, #-0xa8] */
/* @0x2593d8 add r3, r7, #14 */
/* @0x2593dc bic r3, r3, #7 */
/* @0x2593e0 sub sp, sp, r3 */
/* @0x2593e4 bl 0xb6538 <strlen@plt> */
/* @0x2593e8 add r5, sp, #16 */
/* @0x2593ec ldr lr, [r11, #-0xac] */
/* @0x2593f0 mov r1, r7 */
/* @0x2593f4 ldr r2, [pc, #0x2a4] */
/* @0x2593f8 mov r3, r9 */
/* @0x2593fc str r8, [sp, #0x4] */
/* @0x259400 str r6, [sp] */
/* @0x259404 add r2, pc, r2 */
/* @0x259408 add r12, lr, r0 */
/* @0x25940c mov r0, r5 */
/* @0x259410 str r12, [sp, #0x8] */
/* @0x259414 bl 0xb65c8 <snprintf@plt> */
/* @0x259418 ldr r0, [r11, #-0xa0] */
/* @0x25941c mov r1, r5 */
/* @0x259420 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x259424 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x259428 ldr r0, [pc, #0x274] */
/* @0x25942c add r0, pc, r0 */
/* @0x259430 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259434 ldr r2, [r11, #-0x28] */
/* @0x259438 ldr r3, [r4] */
/* @0x25943c cmp r2, r3 */
/* @0x259440 bne 0x259694 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x448> */
/* @0x259444 sub sp, r11, #32 */
/* @0x259448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25944c ldr r10, [r5] */
/* @0x259450 ldr r1, [pc, #0x250] */
/* @0x259454 ldr r0, [r10, #0x40] */
/* @0x259458 add r1, pc, r1 */
/* @0x25945c bl 0xb6574 <strcmp@plt> */
/* @0x259460 cmp r0, #0 */
/* @0x259464 bne 0x2592e0 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x259468 add r5, r5, #16 */
/* @0x25946c str r8, [sp] */
/* @0x259470 str r5, [sp, #0x4] */
/* @0x259474 mov r1, r7 */
/* @0x259478 ldr r0, [r11, #-0xa0] */
/* @0x25947c mov r2, r9 */
/* @0x259480 mov r3, r10 */
/* @0x259484 bl 0x258e3c <_Z33JS_String_prototype_replace_RegExR6RValueP9CInstanceS2_P12YYObjectBasePS_S5_> */
/* @0x259488 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x25948c ldr r0, [pc, #0x218] */
/* @0x259490 add r0, pc, r0 */
/* @0x259494 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259498 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x25949c ldr r12, [r11, #-0xa4] */
/* @0x2594a0 mov r1, r5 */
/* @0x2594a4 sub r0, r11, #88 */
/* @0x2594a8 str r10, [r11, #-0x4c] */
/* @0x2594ac str r12, [r11, #-0x58] */
/* @0x2594b0 str r12, [r11, #-0x54] */
/* @0x2594b4 str r12, [r11, #-0x50] */
/* @0x2594b8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2594bc cmp r0, #1 */
/* @0x2594c0 beq 0x259684 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x438> */
/* @0x2594c4 cmp r0, #2 */
/* @0x2594c8 beq 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x2594cc ldr r12, [r11, #-0xac] */
/* @0x2594d0 ldr r3, [r11, #-0x58] */
/* @0x2594d4 rsb r10, r6, r12 */
/* @0x2594d8 ldr r1, [r11, #-0xa4] */
/* @0x2594dc add r0, r10, #15 */
/* @0x2594e0 add r2, r10, #1 */
/* @0x2594e4 bic r0, r0, #7 */
/* @0x2594e8 ldr r12, [r3] */
/* @0x2594ec sub sp, sp, r0 */
/* @0x2594f0 add r5, sp, #23 */
/* @0x2594f4 str r12, [r11, #-0xb0] */
/* @0x2594f8 lsr r5, r5, #3 */
/* @0x2594fc lsl r9, r5, #3 */
/* @0x259500 mov r0, r9 */
/* @0x259504 bl 0xb65b0 <memset@plt> */
/* @0x259508 mov r2, r10 */
/* @0x25950c mov r1, r6 */
/* @0x259510 mov r0, r9 */
/* @0x259514 bl 0xb6568 <strncpy@plt> */
/* @0x259518 ldr lr, [r11, #-0xa4] */
/* @0x25951c ldr r0, [r11, #-0xa8] */
/* @0x259520 strb lr, [r10, r5, lsl #3] */
/* @0x259524 bl 0xb6538 <strlen@plt> */
/* @0x259528 ldr r1, [pc, #0x180] */
/* @0x25952c mov r3, #1 */
/* @0x259530 mov r2, #242 */
/* @0x259534 add r1, pc, r1 */
/* @0x259538 add r10, r0, r10 */
/* @0x25953c mov r0, #32768 */
/* @0x259540 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x259544 mov r1, r9 */
/* @0x259548 add r10, r6, r10 */
/* @0x25954c mov r5, r0 */
/* @0x259550 bl 0xb6628 <strcat@plt> */
/* @0x259554 ldr r12, [r11, #-0xb0] */
/* @0x259558 ldrb r3, [r12] */
/* @0x25955c cmp r3, #0 */
/* @0x259560 beq 0x259618 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3cc> */
/* @0x259564 ldr r2, [pc, #0x148] */
/* @0x259568 sub r8, r11, #104 */
/* @0x25956c ldr r7, [r11, #-0xa4] */
/* @0x259570 add r2, pc, r2 */
/* @0x259574 str r4, [r11, #-0xa4] */
/* @0x259578 str r2, [r11, #-0xac] */
/* @0x25957c b 0x2595a8 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x35c> */
/* @0x259580 mov r0, r5 */
/* @0x259584 mov r1, r8 */
/* @0x259588 strh r7, [r11, #-104] */
/* @0x25958c mov r6, r12 */
/* @0x259590 strb r3, [r11, #-0x68] */
/* @0x259594 bl 0xb6628 <strcat@plt> */
/* @0x259598 ldrb r3, [r6, #0x1] */
/* @0x25959c add r12, r6, #1 */
/* @0x2595a0 cmp r3, #0 */
/* @0x2595a4 beq 0x259614 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3c8> */
/* @0x2595a8 cmp r3, #36 */
/* @0x2595ac bne 0x259580 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x334> */
/* @0x2595b0 mov r6, r12 */
/* @0x2595b4 ldrb r4, [r6, #0x1]! */
/* @0x2595b8 cmp r4, #38 */
/* @0x2595bc beq 0x259674 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x428> */
/* @0x2595c0 bls 0x2595f4 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3a8> */
/* @0x2595c4 cmp r4, #39 */
/* @0x2595c8 beq 0x259664 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x418> */
/* @0x2595cc cmp r4, #96 */
/* @0x2595d0 bne 0x259634 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3e8> */
/* @0x2595d4 mov r0, r5 */
/* @0x2595d8 mov r1, r9 */
/* @0x2595dc bl 0xb6628 <strcat@plt> */
/* @0x2595e0 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x2595e4 ldr r0, [r11, #-0xa0] */
/* @0x2595e8 mov r1, r6 */
/* @0x2595ec bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2595f0 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x2595f4 cmp r4, #36 */
/* @0x2595f8 bne 0x259634 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x3e8> */
/* @0x2595fc mov r0, r5 */
/* @0x259600 bl 0xb6538 <strlen@plt> */
/* @0x259604 ldr r12, [r11, #-0xac] */
/* @0x259608 ldrh r3, [r12] */
/* @0x25960c strh r3, [r5, r0] */
/* @0x259610 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x259614 ldr r4, [r11, #-0xa4] */
/* @0x259618 mov r1, r10 */
/* @0x25961c mov r0, r5 */
/* @0x259620 bl 0xb6628 <strcat@plt> */
/* @0x259624 ldr r0, [r11, #-0xa0] */
/* @0x259628 mov r1, r5 */
/* @0x25962c bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x259630 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x259634 mov r1, r8 */
/* @0x259638 mov r0, r5 */
/* @0x25963c strh r7, [r11, #-104] */
/* @0x259640 mov lr, #36 */
/* @0x259644 strb lr, [r11, #-0x68] */
/* @0x259648 bl 0xb6628 <strcat@plt> */
/* @0x25964c mov r0, r5 */
/* @0x259650 mov r1, r8 */
/* @0x259654 strh r7, [r11, #-104] */
/* @0x259658 strb r4, [r11, #-0x68] */
/* @0x25965c bl 0xb6628 <strcat@plt> */
/* @0x259660 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x259664 mov r0, r5 */
/* @0x259668 mov r1, r10 */
/* @0x25966c bl 0xb6628 <strcat@plt> */
/* @0x259670 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x259674 mov r0, r5 */
/* @0x259678 ldr r1, [r11, #-0xa8] */
/* @0x25967c bl 0xb6628 <strcat@plt> */
/* @0x259680 b 0x259598 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x259684 ldr r0, [pc, #0x2c] */
/* @0x259688 add r0, pc, r0 */
/* @0x25968c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259690 b 0x259434 <_Z27JS_String_prototype_replaceR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x259694 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x259698 ldrsheq r4, [r9], -r0 */
/* @0x25969c andseq r4, r9, r0, asr #18 */
/* @0x2596a0 muleq pc, r12, r7 */
/* @0x2596a4 andeq r12, pc, r12, lsl r11 */
/* @0x2596a8 ldrdeq r12, sp, [pc], -r4 */
/* @0x2596ac strheq r12, [pc], -r8 */
/* @0x2596b0 andeq sp, pc, r8, ror r6 */
/* @0x2596b4 andeq r12, pc, r12, ror #17 */
/* @0x2596b8 andeq r12, pc, r0, asr #17 */

/* ── FUNC 0x2596bc · JS_Array_prototype_join(RValue&, CInstance*, CInstance*, int, RValue*) · size=1084 · insn=271 */
/* @0x2596bc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2596c0 sub sp, sp, #148 */
/* @0x2596c4 ldr r2, [pc, #0x414] */
/* @0x2596c8 cmp r3, #0 */
/* @0x2596cc str r0, [sp, #0x1c] */
/* @0x2596d0 mov r11, r1 */
/* @0x2596d4 ldr r2, [pc, r2] */
/* @0x2596d8 str r2, [sp, #0x14] */
/* @0x2596dc ldr r0, [sp, #0x14] */
/* @0x2596e0 mov r2, #5 */
/* @0x2596e4 ldr r1, [sp, #0xb8] */
/* @0x2596e8 str r2, [sp, #0x38] */
/* @0x2596ec ldr r3, [r0] */
/* @0x2596f0 str r3, [sp, #0x8c] */
/* @0x2596f4 ble 0x259a88 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3cc> */
/* @0x2596f8 add r4, sp, #44 */
/* @0x2596fc mov r0, r4 */
/* @0x259700 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259704 cmp r0, #1 */
/* @0x259708 beq 0x259a98 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3dc> */
/* @0x25970c mov r0, r4 */
/* @0x259710 mov r1, #0 */
/* @0x259714 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x259718 str r0, [sp, #0xc] */
/* @0x25971c add r2, sp, #60 */
/* @0x259720 str r2, [sp, #0x18] */
/* @0x259724 ldr r2, [pc, #0x3b8] */
/* @0x259728 mov r0, r11 */
/* @0x25972c add r1, sp, #60 */
/* @0x259730 mov r7, #5 */
/* @0x259734 add r2, pc, r2 */
/* @0x259738 str r7, [sp, #0x48] */
/* @0x25973c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x259740 add r0, sp, #60 */
/* @0x259744 mov r1, #0 */
/* @0x259748 mov r4, #0 */
/* @0x25974c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x259750 str r4, [sp, #0x20] */
/* @0x259754 str r4, [sp, #0x24] */
/* @0x259758 str r4, [sp, #0x28] */
/* @0x25975c cmp r0, #0 */
/* @0x259760 str r0, [sp, #0x8] */
/* @0x259764 beq 0x259a80 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3c4> */
/* @0x259768 ldr r3, [pc, #0x378] */
/* @0x25976c add r5, sp, #108 */
/* @0x259770 add r6, sp, #76 */
/* @0x259774 add r3, pc, r3 */
/* @0x259778 str r3, [sp, #0x4] */
/* @0x25977c mov r3, r4 */
/* @0x259780 mov r1, #32 */
/* @0x259784 ldr r2, [sp, #0x4] */
/* @0x259788 mov r0, r5 */
/* @0x25978c bl 0xb65c8 <snprintf@plt> */
/* @0x259790 mov r2, r5 */
/* @0x259794 mov r0, r11 */
/* @0x259798 mov r1, r6 */
/* @0x25979c str r7, [sp, #0x58] */
/* @0x2597a0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2597a4 ldr r2, [sp, #0x58] */
/* @0x2597a8 bic r3, r2, #-16777216 */
/* @0x2597ac cmp r3, #12 */
/* @0x2597b0 beq 0x2599b0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2f4> */
/* @0x2597b4 mvn r1, #-16777216 */
/* @0x2597b8 cmp r3, r1 */
/* @0x2597bc beq 0x2599a8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* @0x2597c0 cmp r3, #5 */
/* @0x2597c4 beq 0x2599b0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2f4> */
/* @0x2597c8 add r8, sp, #92 */
/* @0x2597cc mov r1, r6 */
/* @0x2597d0 str r7, [sp, #0x68] */
/* @0x2597d4 mov r0, r8 */
/* @0x2597d8 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x2597dc cmp r0, #1 */
/* @0x2597e0 beq 0x259aa8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x2597e4 mov r0, r8 */
/* @0x2597e8 mov r1, #0 */
/* @0x2597ec bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2597f0 subs r3, r0, #0 */
/* @0x2597f4 str r3, [sp, #0x10] */
/* @0x2597f8 beq 0x2598a0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x2597fc bl 0xb6538 <strlen@plt> */
/* @0x259800 ldr r2, [sp, #0x28] */
/* @0x259804 ldr r3, [sp, #0x24] */
/* @0x259808 add r1, r0, #1 */
/* @0x25980c mov r9, r0 */
/* @0x259810 mvn r0, r2 */
/* @0x259814 add r0, r3, r0 */
/* @0x259818 cmp r1, r0 */
/* @0x25981c ble 0x259884 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x259820 cmp r3, #0 */
/* @0x259824 add r2, r1, r2 */
/* @0x259828 ldr r10, [sp, #0x20] */
/* @0x25982c moveq r3, r1 */
/* @0x259830 add r3, r3, r3, lsl #1 */
/* @0x259834 add r3, r3, r3, lsr #31 */
/* @0x259838 asr r3, r3, #1 */
/* @0x25983c cmp r3, r2 */
/* @0x259840 addlt r2, r2, r2, lsl #1 */
/* @0x259844 addlt r2, r2, r2, lsr #31 */
/* @0x259848 asrlt r3, r2, #1 */
/* @0x25984c str r3, [sp] */
/* @0x259850 mov r0, r3 */
/* @0x259854 bl 0xcef4c <_Z7YYAlloci> */
/* @0x259858 ldr r2, [sp, #0x24] */
/* @0x25985c mov r1, r10 */
/* @0x259860 str r0, [sp, #0x20] */
/* @0x259864 bl 0xb65bc <memcpy@plt> */
/* @0x259868 ldr r3, [sp] */
/* @0x25986c cmp r10, #0 */
/* @0x259870 str r3, [sp, #0x24] */
/* @0x259874 beq 0x259880 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x259878 mov r0, r10 */
/* @0x25987c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259880 ldr r2, [sp, #0x28] */
/* @0x259884 ldr r0, [sp, #0x20] */
/* @0x259888 ldr r1, [sp, #0x10] */
/* @0x25988c add r0, r0, r2 */
/* @0x259890 bl 0xb65a4 <strcpy@plt> */
/* @0x259894 ldr r3, [sp, #0x28] */
/* @0x259898 add r9, r3, r9 */
/* @0x25989c str r9, [sp, #0x28] */
/* @0x2598a0 ldr r3, [sp, #0x68] */
/* @0x2598a4 sub r3, r3, #1 */
/* @0x2598a8 bic r3, r3, #-16777216 */
/* @0x2598ac bic r3, r3, #3 */
/* @0x2598b0 cmp r3, #0 */
/* @0x2598b4 beq 0x259a74 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3b8> */
/* @0x2598b8 ldr r2, [sp, #0x58] */
/* @0x2598bc mov r8, #0 */
/* @0x2598c0 sub r2, r2, #1 */
/* @0x2598c4 bic r2, r2, #-16777216 */
/* @0x2598c8 bic r2, r2, #3 */
/* @0x2598cc cmp r2, #0 */
/* @0x2598d0 beq 0x2599b8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x2598d4 ldr r0, [sp, #0x8] */
/* @0x2598d8 add r4, r4, #1 */
/* @0x2598dc cmp r4, r0 */
/* @0x2598e0 beq 0x2599d0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x2598e4 eor r8, r8, #1 */
/* @0x2598e8 cmp r4, #0 */
/* @0x2598ec moveq r8, #0 */
/* @0x2598f0 andne r8, r8, #1 */
/* @0x2598f4 cmp r8, #0 */
/* @0x2598f8 beq 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x2598fc ldr r0, [sp, #0xc] */
/* @0x259900 cmp r0, #0 */
/* @0x259904 beq 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x259908 bl 0xb6538 <strlen@plt> */
/* @0x25990c ldr r2, [sp, #0x28] */
/* @0x259910 ldr r3, [sp, #0x24] */
/* @0x259914 add r1, r0, #1 */
/* @0x259918 mov r8, r0 */
/* @0x25991c mvn r0, r2 */
/* @0x259920 add r0, r3, r0 */
/* @0x259924 cmp r1, r0 */
/* @0x259928 ble 0x259988 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2cc> */
/* @0x25992c cmp r3, #0 */
/* @0x259930 add r2, r1, r2 */
/* @0x259934 ldr r10, [sp, #0x20] */
/* @0x259938 moveq r3, r1 */
/* @0x25993c add r3, r3, r3, lsl #1 */
/* @0x259940 add r3, r3, r3, lsr #31 */
/* @0x259944 asr r9, r3, #1 */
/* @0x259948 cmp r9, r2 */
/* @0x25994c addlt r2, r2, r2, lsl #1 */
/* @0x259950 addlt r2, r2, r2, lsr #31 */
/* @0x259954 asrlt r9, r2, #1 */
/* @0x259958 mov r0, r9 */
/* @0x25995c bl 0xcef4c <_Z7YYAlloci> */
/* @0x259960 ldr r2, [sp, #0x24] */
/* @0x259964 mov r1, r10 */
/* @0x259968 str r0, [sp, #0x20] */
/* @0x25996c bl 0xb65bc <memcpy@plt> */
/* @0x259970 cmp r10, #0 */
/* @0x259974 str r9, [sp, #0x24] */
/* @0x259978 beq 0x259984 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x2c8> */
/* @0x25997c mov r0, r10 */
/* @0x259980 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259984 ldr r2, [sp, #0x28] */
/* @0x259988 ldr r0, [sp, #0x20] */
/* @0x25998c ldr r1, [sp, #0xc] */
/* @0x259990 add r0, r0, r2 */
/* @0x259994 bl 0xb65a4 <strcpy@plt> */
/* @0x259998 ldr r3, [sp, #0x28] */
/* @0x25999c add r8, r3, r8 */
/* @0x2599a0 str r8, [sp, #0x28] */
/* @0x2599a4 b 0x25977c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x2599a8 mov r8, #1 */
/* @0x2599ac b 0x2598c0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x2599b0 mov r8, #0 */
/* @0x2599b4 b 0x2598c0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x2599b8 mov r0, r6 */
/* @0x2599bc add r4, r4, #1 */
/* @0x2599c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2599c4 ldr r0, [sp, #0x8] */
/* @0x2599c8 cmp r4, r0 */
/* @0x2599cc bne 0x2598e4 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x2599d0 ldr r3, [sp, #0x28] */
/* @0x2599d4 cmp r3, #0 */
/* @0x2599d8 beq 0x259a80 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x3c4> */
/* @0x2599dc ldr r1, [sp, #0x20] */
/* @0x2599e0 ldr r0, [sp, #0x1c] */
/* @0x2599e4 mov r3, #0 */
/* @0x2599e8 str r3, [sp, #0x28] */
/* @0x2599ec bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2599f0 ldr r3, [sp, #0x38] */
/* @0x2599f4 sub r3, r3, #1 */
/* @0x2599f8 bic r3, r3, #-16777216 */
/* @0x2599fc bic r3, r3, #3 */
/* @0x259a00 cmp r3, #0 */
/* @0x259a04 beq 0x259ad0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x414> */
/* @0x259a08 ldr r1, [sp, #0x48] */
/* @0x259a0c mov r3, #0 */
/* @0x259a10 str r3, [sp, #0x34] */
/* @0x259a14 mov r2, #5 */
/* @0x259a18 sub r1, r1, #1 */
/* @0x259a1c str r3, [sp, #0x2c] */
/* @0x259a20 bic r3, r1, #-16777216 */
/* @0x259a24 str r2, [sp, #0x38] */
/* @0x259a28 bic r3, r3, #3 */
/* @0x259a2c cmp r3, #0 */
/* @0x259a30 beq 0x259ac4 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x408> */
/* @0x259a34 ldr r0, [sp, #0x20] */
/* @0x259a38 mov r3, #0 */
/* @0x259a3c mov r2, #5 */
/* @0x259a40 str r3, [sp, #0x44] */
/* @0x259a44 cmp r0, r3 */
/* @0x259a48 str r3, [sp, #0x3c] */
/* @0x259a4c str r2, [sp, #0x48] */
/* @0x259a50 beq 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x259a54 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259a58 ldr r1, [sp, #0x14] */
/* @0x259a5c ldr r2, [sp, #0x8c] */
/* @0x259a60 ldr r3, [r1] */
/* @0x259a64 cmp r2, r3 */
/* @0x259a68 bne 0x259adc <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x420> */
/* @0x259a6c add sp, sp, #148 */
/* @0x259a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x259a74 mov r0, r8 */
/* @0x259a78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x259a7c b 0x2598b8 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x259a80 add r1, sp, #40 */
/* @0x259a84 b 0x2599e0 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x324> */
/* @0x259a88 ldr r1, [pc, #0x5c] */
/* @0x259a8c add r1, pc, r1 */
/* @0x259a90 str r1, [sp, #0xc] */
/* @0x259a94 b 0x25971c <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x259a98 ldr r0, [pc, #0x50] */
/* @0x259a9c add r0, pc, r0 */
/* @0x259aa0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259aa4 b 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x259aa8 ldr r0, [pc, #0x44] */
/* @0x259aac add r0, pc, r0 */
/* @0x259ab0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259ab4 ldr r0, [sp, #0x20] */
/* @0x259ab8 cmp r0, #0 */
/* @0x259abc bne 0x259a54 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x398> */
/* @0x259ac0 b 0x259a58 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x259ac4 add r0, sp, #60 */
/* @0x259ac8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x259acc b 0x259a34 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x378> */
/* @0x259ad0 add r0, sp, #44 */
/* @0x259ad4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x259ad8 b 0x259a08 <_Z23JS_Array_prototype_joinR6RValueP9CInstanceS2_iPS_+0x34c> */
/* @0x259adc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x259ae0 andseq r4, r9, r12, ror r2 */
/* @0x259ae4 andeq r7, sp, r8, lsr r1 */
/* @0x259ae8 andeq r12, pc, r12, ror #13 */
/* @0x259aec muleq sp, r8, r10 */
/* @0x259af0 andeq sp, pc, r4, asr r1 */
/* @0x259af4 andeq sp, pc, r8, ror r1 */

/* ── FUNC 0x259af8 · JS_Array_prototype_concat(RValue&, CInstance*, CInstance*, int, RValue*) · size=436 · insn=109 */
/* @0x259af8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x259afc sub sp, sp, #52 */
/* @0x259b00 mov r12, #0 */
/* @0x259b04 mov r5, r0 */
/* @0x259b08 str r3, [sp, #0x8] */
/* @0x259b0c mov r3, r12 */
/* @0x259b10 str r12, [sp] */
/* @0x259b14 mov r4, r1 */
/* @0x259b18 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x259b1c ldr r0, [r5] */
/* @0x259b20 mov r3, #6 */
/* @0x259b24 str r3, [sp, #0x1c] */
/* @0x259b28 str r4, [sp, #0x10] */
/* @0x259b2c ldr r3, [r0, #0x4] */
/* @0x259b30 cmp r3, #0 */
/* @0x259b34 beq 0x259c98 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x259b38 add r0, r3, #16 */
/* @0x259b3c ldr r12, [sp, #0x8] */
/* @0x259b40 ldr r8, [r0] */
/* @0x259b44 cmp r12, #0 */
/* @0x259b48 blt 0x259c18 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x259b4c ldr r3, [pc, #0x150] */
/* @0x259b50 mov r6, #0 */
/* @0x259b54 add r5, sp, #16 */
/* @0x259b58 add r9, sp, #32 */
/* @0x259b5c mov r4, r6 */
/* @0x259b60 mvn r7, #-16777216 */
/* @0x259b64 add r3, pc, r3 */
/* @0x259b68 str r3, [sp, #0xc] */
/* @0x259b6c ldr r3, [r5, #0xc] */
/* @0x259b70 bic r3, r3, #-16777216 */
/* @0x259b74 cmp r3, #6 */
/* @0x259b78 bne 0x259c20 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x259b7c ldr r10, [r5] */
/* @0x259b80 ldr r1, [sp, #0xc] */
/* @0x259b84 ldr r0, [r10, #0x40] */
/* @0x259b88 bl 0xb6574 <strcmp@plt> */
/* @0x259b8c cmp r0, #0 */
/* @0x259b90 bne 0x259c20 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x259b94 ldr r2, [r10, #0x4] */
/* @0x259b98 cmp r2, #0 */
/* @0x259b9c beq 0x259c88 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x259ba0 add r0, r2, #16 */
/* @0x259ba4 ldr r3, [r0] */
/* @0x259ba8 ldr r11, [r3, #0x2c] */
/* @0x259bac ldr r10, [r3, #0x4] */
/* @0x259bb0 cmp r11, #0 */
/* @0x259bb4 bne 0x259bc8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x259bb8 b 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x259bbc subs r11, r11, #1 */
/* @0x259bc0 add r10, r10, #16 */
/* @0x259bc4 beq 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x259bc8 ldr r3, [r10, #0xc] */
/* @0x259bcc bic r3, r3, #-16777216 */
/* @0x259bd0 cmp r3, r7 */
/* @0x259bd4 beq 0x259bbc <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x259bd8 mov r1, r4 */
/* @0x259bdc mov r2, r10 */
/* @0x259be0 mov r0, r8 */
/* @0x259be4 add r4, r4, #1 */
/* @0x259be8 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue> */
/* @0x259bec subs r11, r11, #1 */
/* @0x259bf0 add r10, r10, #16 */
/* @0x259bf4 bne 0x259bc8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x259bf8 cmp r6, #0 */
/* @0x259bfc ldr r12, [sp, #0x8] */
/* @0x259c00 add r6, r6, #1 */
/* @0x259c04 ldreq r3, [sp, #0x58] */
/* @0x259c08 subeq r5, r3, #16 */
/* @0x259c0c cmp r12, r6 */
/* @0x259c10 add r5, r5, #16 */
/* @0x259c14 bge 0x259b6c <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x259c18 add sp, sp, #52 */
/* @0x259c1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x259c20 mov r0, r9 */
/* @0x259c24 mov r1, r5 */
/* @0x259c28 mov r12, #5 */
/* @0x259c2c str r12, [sp, #0x2c] */
/* @0x259c30 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259c34 cmp r0, #1 */
/* @0x259c38 beq 0x259c74 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x259c3c mov r1, r4 */
/* @0x259c40 mov r0, r8 */
/* @0x259c44 mov r2, r9 */
/* @0x259c48 add r4, r4, #1 */
/* @0x259c4c bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue> */
/* @0x259c50 ldr r3, [sp, #0x2c] */
/* @0x259c54 sub r3, r3, #1 */
/* @0x259c58 bic r3, r3, #-16777216 */
/* @0x259c5c bic r3, r3, #3 */
/* @0x259c60 cmp r3, #0 */
/* @0x259c64 bne 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x259c68 mov r0, r9 */
/* @0x259c6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x259c70 b 0x259bf8 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x259c74 ldr r0, [pc, #0x2c] */
/* @0x259c78 add r0, pc, r0 */
/* @0x259c7c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x259c80 add sp, sp, #52 */
/* @0x259c84 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x259c88 mov r0, r10 */
/* @0x259c8c mov r1, #1 */
/* @0x259c90 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x259c94 b 0x259ba4 <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x259c98 mov r1, #1 */
/* @0x259c9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x259ca0 b 0x259b3c <_Z25JS_Array_prototype_concatR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x259ca4 strheq r10, [sp], -r4 */
/* @0x259ca8 andeq r12, pc, r0, ror #31 */

/* ── FUNC 0x259cac · JS_DateCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=508 · insn=127 */
/* @0x259cac push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x259cb0 sub sp, sp, #24 */
/* @0x259cb4 add r4, sp, #8 */
/* @0x259cb8 mov r5, r0 */
/* @0x259cbc ldr r12, [sp, #0x38] */
/* @0x259cc0 mov r0, r4 */
/* @0x259cc4 str r12, [sp] */
/* @0x259cc8 bl 0x246108 <_Z19JS_Date_constructorR6RValueP9CInstanceS2_iPS_> */
/* @0x259ccc mov r0, r5 */
/* @0x259cd0 mov r1, r4 */
/* @0x259cd4 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259cd8 ldr r2, [sp, #0x14] */
/* @0x259cdc sub r3, r2, #1 */
/* @0x259ce0 bic r3, r3, #-16777216 */
/* @0x259ce4 bics r5, r3, #3 */
/* @0x259ce8 beq 0x259cf4 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x259cec add sp, sp, #24 */
/* @0x259cf0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x259cf4 bic r2, r2, #-16777216 */
/* @0x259cf8 cmp r2, #2 */
/* @0x259cfc beq 0x259d68 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x259d00 cmp r2, #3 */
/* @0x259d04 beq 0x259d40 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x259d08 cmp r2, #1 */
/* @0x259d0c bne 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d10 ldr r4, [sp, #0x8] */
/* @0x259d14 cmp r4, #0 */
/* @0x259d18 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x259d20 ldr r5, [r4, #0x4] */
/* @0x259d24 sub r5, r5, #1 */
/* @0x259d28 str r5, [r4, #0x4] */
/* @0x259d2c cmp r5, #0 */
/* @0x259d30 beq 0x259e08 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x259d34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x259d38 add sp, sp, #24 */
/* @0x259d3c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x259d40 ldr r3, [sp, #0x10] */
/* @0x259d44 tst r3, #8 */
/* @0x259d48 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d4c ldr r0, [sp, #0x8] */
/* @0x259d50 cmp r0, #0 */
/* @0x259d54 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d58 ldr r3, [r0] */
/* @0x259d5c ldr r3, [r3, #0x4] */
/* @0x259d60 blx r3 */
/* @0x259d64 b 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d68 ldr r7, [sp, #0x8] */
/* @0x259d6c cmp r7, #0 */
/* @0x259d70 beq 0x259cec <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x259d74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x259d78 ldr r3, [r7] */
/* @0x259d7c ldr r2, [r7, #0x8] */
/* @0x259d80 sub r3, r3, #1 */
/* @0x259d84 str r3, [r7] */
/* @0x259d88 cmp r2, r4 */
/* @0x259d8c streq r5, [r7, #0x8] */
/* @0x259d90 cmp r3, #0 */
/* @0x259d94 bgt 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x259d98 ldr r3, [r7, #0x10] */
/* @0x259d9c cmp r3, #0 */
/* @0x259da0 movgt r6, #0 */
/* @0x259da4 movgt r10, #5 */
/* @0x259da8 movgt r5, r6 */
/* @0x259dac ble 0x259e5c <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x259db0 ldr r3, [r7, #0x4] */
/* @0x259db4 add r8, r3, r6, lsl #3 */
/* @0x259db8 ldr r9, [r3, r6, lsl #3] */
/* @0x259dbc ldr r4, [r8, #0x4] */
/* @0x259dc0 add r9, r4, r9, lsl #4 */
/* @0x259dc4 cmp r4, r9 */
/* @0x259dc8 blo 0x259de4 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x259dcc b 0x259e7c <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x259dd0 str r5, [r4, #0x8] */
/* @0x259dd4 str r10, [r4, #0xc] */
/* @0x259dd8 str r5, [r4], #16 */
/* @0x259ddc cmp r9, r4 */
/* @0x259de0 bls 0x259e40 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x259de4 ldr r3, [r4, #0xc] */
/* @0x259de8 sub r3, r3, #1 */
/* @0x259dec bic r3, r3, #-16777216 */
/* @0x259df0 bic r3, r3, #3 */
/* @0x259df4 cmp r3, #0 */
/* @0x259df8 bne 0x259dd0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x259dfc mov r0, r4 */
/* @0x259e00 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x259e04 b 0x259dd0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x259e08 ldr r0, [r4] */
/* @0x259e0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259e10 str r5, [r4] */
/* @0x259e14 str r5, [r4, #0x8] */
/* @0x259e18 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x259e1c ldr r5, [r4, #0x4] */
/* @0x259e20 sub r5, r5, #1 */
/* @0x259e24 str r5, [r4, #0x4] */
/* @0x259e28 cmp r5, #0 */
/* @0x259e2c beq 0x259e84 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x259e30 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x259e34 mov r0, r4 */
/* @0x259e38 bl 0x27d1d0 <_ZdlPv> */
/* @0x259e3c b 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x259e40 ldr r0, [r8, #0x4] */
/* @0x259e44 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x259e48 ldr r3, [r7, #0x10] */
/* @0x259e4c add r6, r6, #1 */
/* @0x259e50 str r5, [r8, #0x4] */
/* @0x259e54 cmp r6, r3 */
/* @0x259e58 blt 0x259db0 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x259e5c ldr r0, [r7, #0x4] */
/* @0x259e60 mov r4, #0 */
/* @0x259e64 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x259e68 str r4, [r7, #0x4] */
/* @0x259e6c mov r0, r7 */
/* @0x259e70 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x259e74 str r4, [sp, #0x8] */
/* @0x259e78 b 0x259d34 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x259e7c mov r0, r4 */
/* @0x259e80 b 0x259e44 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x259e84 ldr r0, [r4] */
/* @0x259e88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x259e8c mov r0, r4 */
/* @0x259e90 str r5, [r4] */
/* @0x259e94 str r5, [r4, #0x8] */
/* @0x259e98 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x259e9c mov r0, r4 */
/* @0x259ea0 bl 0x27d1d0 <_ZdlPv> */
/* @0x259ea4 b 0x259e30 <_Z11JS_DateCallR6RValueP9CInstanceS2_iPS_+0x184> */

/* ── FUNC 0x259ea8 · JS_RegExp(RValue&, CInstance*, CInstance*, int, RValue*) · size=1344 · insn=336 */
/* @0x259ea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x259eac add r11, sp, #32 */
/* @0x259eb0 ldr r5, [pc, #0x4e4] */
/* @0x259eb4 sub sp, sp, #116 */
/* @0x259eb8 mov r4, r0 */
/* @0x259ebc ldr r5, [pc, r5] */
/* @0x259ec0 ldr r7, [r11, #0x4] */
/* @0x259ec4 mov r8, r3 */
/* @0x259ec8 mov r6, #5 */
/* @0x259ecc ldr r12, [r5] */
/* @0x259ed0 str r7, [sp] */
/* @0x259ed4 str r12, [r11, #-0x28] */
/* @0x259ed8 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x259edc ldr r2, [pc, #0x4bc] */
/* @0x259ee0 ldr r4, [r4] */
/* @0x259ee4 ldr r2, [pc, r2] */
/* @0x259ee8 ldr r3, [pc, #0x4b4] */
/* @0x259eec ldr r1, [r2] */
/* @0x259ef0 add r3, pc, r3 */
/* @0x259ef4 mov r0, r4 */
/* @0x259ef8 str r3, [r4, #0x40] */
/* @0x259efc str r1, [r4, #0x18] */
/* @0x259f00 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x259f04 ldr r3, [r4, #0x28] */
/* @0x259f08 cmp r8, #0 */
/* @0x259f0c mov r2, #0 */
/* @0x259f10 orr r3, r3, #1 */
/* @0x259f14 str r2, [r11, #-0x78] */
/* @0x259f18 str r2, [r11, #-0x74] */
/* @0x259f1c str r3, [r4, #0x28] */
/* @0x259f20 str r2, [r11, #-0x70] */
/* @0x259f24 str r6, [r11, #-0x6c] */
/* @0x259f28 ble 0x25a1a0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x259f2c cmp r8, #1 */
/* @0x259f30 ldr r3, [r7, #0xc] */
/* @0x259f34 subeq r9, r11, #120 */
/* @0x259f38 addne r9, r7, #16 */
/* @0x259f3c ldrne r6, [r7, #0x1c] */
/* @0x259f40 biceq r3, r3, #-16777216 */
/* @0x259f44 bicne r3, r3, #-16777216 */
/* @0x259f48 bicne r6, r6, #-16777216 */
/* @0x259f4c cmp r3, #6 */
/* @0x259f50 beq 0x25a15c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2b4> */
/* @0x259f54 cmp r3, #5 */
/* @0x259f58 beq 0x25a1a4 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x259f5c sub r8, r11, #56 */
/* @0x259f60 mov r1, r7 */
/* @0x259f64 mvn r3, #-16777216 */
/* @0x259f68 mov r7, #0 */
/* @0x259f6c mov r0, r8 */
/* @0x259f70 str r7, [r11, #-0x38] */
/* @0x259f74 str r7, [r11, #-0x34] */
/* @0x259f78 str r7, [r11, #-0x30] */
/* @0x259f7c str r3, [r11, #-0x2c] */
/* @0x259f80 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259f84 cmp r0, #2 */
/* @0x259f88 beq 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x259f8c cmp r0, #1 */
/* @0x259f90 beq 0x25a1f0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x348> */
/* @0x259f94 mov r1, r7 */
/* @0x259f98 mov r0, r8 */
/* @0x259f9c bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x259fa0 cmp r6, #5 */
/* @0x259fa4 mov r10, r0 */
/* @0x259fa8 beq 0x25a1c0 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x318> */
/* @0x259fac mov r1, r9 */
/* @0x259fb0 mov r0, r8 */
/* @0x259fb4 mov r6, #0 */
/* @0x259fb8 mvn r3, #-16777216 */
/* @0x259fbc str r6, [r11, #-0x38] */
/* @0x259fc0 str r6, [r11, #-0x34] */
/* @0x259fc4 str r6, [r11, #-0x30] */
/* @0x259fc8 str r3, [r11, #-0x2c] */
/* @0x259fcc bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x259fd0 cmp r0, #2 */
/* @0x259fd4 beq 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x259fd8 cmp r0, #1 */
/* @0x259fdc beq 0x25a21c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x259fe0 mov r1, r6 */
/* @0x259fe4 mov r0, r8 */
/* @0x259fe8 sub r12, r11, #72 */
/* @0x259fec str r12, [r11, #-0x84] */
/* @0x259ff0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x259ff4 str r0, [r11, #-0x80] */
/* @0x259ff8 ldr r12, [r11, #-0x80] */
/* @0x259ffc ldrb r3, [r12] */
/* @0x25a000 cmp r3, #0 */
/* @0x25a004 beq 0x25a1dc <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x334> */
/* @0x25a008 mov r2, #0 */
/* @0x25a00c mov r1, r12 */
/* @0x25a010 mov r7, r2 */
/* @0x25a014 mov r6, r2 */
/* @0x25a018 mov r9, r2 */
/* @0x25a01c b 0x25a048 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x25a020 cmp r3, #109 */
/* @0x25a024 beq 0x25a190 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x2e8> */
/* @0x25a028 cmp r3, #103 */
/* @0x25a02c orreq r2, r9, r2 */
/* @0x25a030 moveq r9, #1 */
/* @0x25a034 uxtbeq r2, r2 */
/* @0x25a038 movne r2, #1 */
/* @0x25a03c ldrb r3, [r1, #0x1]! */
/* @0x25a040 cmp r3, #0 */
/* @0x25a044 beq 0x25a068 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x25a048 cmp r3, #105 */
/* @0x25a04c bne 0x25a020 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x25a050 ldrb r3, [r1, #0x1]! */
/* @0x25a054 orr r2, r6, r2 */
/* @0x25a058 mov r6, #1 */
/* @0x25a05c cmp r3, #0 */
/* @0x25a060 uxtb r2, r2 */
/* @0x25a064 bne 0x25a048 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x25a068 cmp r2, #0 */
/* @0x25a06c bne 0x25a200 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x25a070 cmp r6, #0 */
/* @0x25a074 movne r1, #1 */
/* @0x25a078 movtne r1, #0x200 */
/* @0x25a07c beq 0x25a1e8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x25a080 cmp r7, #0 */
/* @0x25a084 mov r3, r8 */
/* @0x25a088 orrne r1, r1, #2 */
/* @0x25a08c mov r8, #0 */
/* @0x25a090 mov r0, r10 */
/* @0x25a094 str r8, [sp] */
/* @0x25a098 ldr r2, [r11, #-0x84] */
/* @0x25a09c bl 0x268f88 <pcre_compile> */
/* @0x25a0a0 subs r3, r0, #0 */
/* @0x25a0a4 beq 0x25a210 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x25a0a8 str r3, [r4, #0x1c] */
/* @0x25a0ac mov r1, r8 */
/* @0x25a0b0 ldr r2, [r11, #-0x84] */
/* @0x25a0b4 bl 0x2665e0 <pcre_study> */
/* @0x25a0b8 ldr r1, [pc, #0x2e8] */
/* @0x25a0bc mov r2, r10 */
/* @0x25a0c0 mov r3, r8 */
/* @0x25a0c4 add r1, pc, r1 */
/* @0x25a0c8 str r0, [r4, #0x20] */
/* @0x25a0cc mov r0, r4 */
/* @0x25a0d0 bl 0x199aa8 <_ZN12YYObjectBase3AddEPKcS1_i> */
/* @0x25a0d4 ldr r1, [pc, #0x2d0] */
/* @0x25a0d8 mov r0, r4 */
/* @0x25a0dc mov r2, r9 */
/* @0x25a0e0 add r1, pc, r1 */
/* @0x25a0e4 mov r3, r8 */
/* @0x25a0e8 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi> */
/* @0x25a0ec ldr r1, [pc, #0x2bc] */
/* @0x25a0f0 mov r0, r4 */
/* @0x25a0f4 mov r2, r6 */
/* @0x25a0f8 add r1, pc, r1 */
/* @0x25a0fc mov r3, r8 */
/* @0x25a100 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi> */
/* @0x25a104 ldr r1, [pc, #0x2a8] */
/* @0x25a108 mov r0, r4 */
/* @0x25a10c mov r2, r7 */
/* @0x25a110 add r1, pc, r1 */
/* @0x25a114 mov r3, r8 */
/* @0x25a118 bl 0x1998e0 <_ZN12YYObjectBase3AddEPKcbi> */
/* @0x25a11c ldr r1, [pc, #0x294] */
/* @0x25a120 mov r0, r4 */
/* @0x25a124 mov r2, r8 */
/* @0x25a128 add r1, pc, r1 */
/* @0x25a12c mov r3, #4 */
/* @0x25a130 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii> */
/* @0x25a134 mov r0, r10 */
/* @0x25a138 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25a13c ldr r0, [r11, #-0x80] */
/* @0x25a140 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25a144 ldr r2, [r11, #-0x28] */
/* @0x25a148 ldr r3, [r5] */
/* @0x25a14c cmp r2, r3 */
/* @0x25a150 bne 0x25a398 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x4f0> */
/* @0x25a154 sub sp, r11, #32 */
/* @0x25a158 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25a15c ldr r8, [r7] */
/* @0x25a160 ldr r1, [pc, #0x254] */
/* @0x25a164 ldr r0, [r8, #0x40] */
/* @0x25a168 add r1, pc, r1 */
/* @0x25a16c bl 0xb6574 <strcmp@plt> */
/* @0x25a170 subs r3, r0, #0 */
/* @0x25a174 bne 0x259f5c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25a178 cmp r6, #5 */
/* @0x25a17c beq 0x25a22c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x25a180 ldr r0, [pc, #0x238] */
/* @0x25a184 add r0, pc, r0 */
/* @0x25a188 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25a18c b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x25a190 orr r2, r7, r2 */
/* @0x25a194 mov r7, #1 */
/* @0x25a198 uxtb r2, r2 */
/* @0x25a19c b 0x25a03c <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x25a1a0 sub r9, r11, #120 */
/* @0x25a1a4 ldr r0, [pc, #0x218] */
/* @0x25a1a8 sub r8, r11, #56 */
/* @0x25a1ac add r0, pc, r0 */
/* @0x25a1b0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x25a1b4 cmp r6, #5 */
/* @0x25a1b8 mov r10, r0 */
/* @0x25a1bc bne 0x259fac <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x25a1c0 ldr r0, [pc, #0x200] */
/* @0x25a1c4 sub r12, r11, #72 */
/* @0x25a1c8 str r12, [r11, #-0x84] */
/* @0x25a1cc add r0, pc, r0 */
/* @0x25a1d0 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x25a1d4 str r0, [r11, #-0x80] */
/* @0x25a1d8 b 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x25a1dc mov r6, r3 */
/* @0x25a1e0 mov r7, r3 */
/* @0x25a1e4 mov r9, r3 */
/* @0x25a1e8 mov r1, #33554432 */
/* @0x25a1ec b 0x25a080 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x25a1f0 ldr r0, [pc, #0x1d4] */
/* @0x25a1f4 add r0, pc, r0 */
/* @0x25a1f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25a1fc b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x25a200 ldr r0, [pc, #0x1c8] */
/* @0x25a204 add r0, pc, r0 */
/* @0x25a208 bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc> */
/* @0x25a20c b 0x25a070 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x25a210 ldr r0, [r11, #-0x48] */
/* @0x25a214 bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc> */
/* @0x25a218 b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x25a21c ldr r0, [pc, #0x1b0] */
/* @0x25a220 add r0, pc, r0 */
/* @0x25a224 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25a228 b 0x25a144 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x25a22c sub r6, r11, #104 */
/* @0x25a230 ldr r2, [pc, #0x1a0] */
/* @0x25a234 mov r0, r8 */
/* @0x25a238 sub r12, r11, #72 */
/* @0x25a23c add r2, pc, r2 */
/* @0x25a240 mov r1, r6 */
/* @0x25a244 str r12, [r11, #-0x84] */
/* @0x25a248 sub r9, r11, #88 */
/* @0x25a24c str r3, [r11, #-0x68] */
/* @0x25a250 sub r8, r11, #56 */
/* @0x25a254 str r3, [r11, #-0x64] */
/* @0x25a258 str r3, [r11, #-0x60] */
/* @0x25a25c str r3, [r11, #-0x5c] */
/* @0x25a260 str r3, [r11, #-0x58] */
/* @0x25a264 str r3, [r11, #-0x54] */
/* @0x25a268 str r3, [r11, #-0x50] */
/* @0x25a26c str r3, [r11, #-0x4c] */
/* @0x25a270 str r3, [r11, #-0x48] */
/* @0x25a274 str r3, [r11, #-0x44] */
/* @0x25a278 str r3, [r11, #-0x40] */
/* @0x25a27c str r3, [r11, #-0x3c] */
/* @0x25a280 str r3, [r11, #-0x38] */
/* @0x25a284 str r3, [r11, #-0x34] */
/* @0x25a288 str r3, [r11, #-0x30] */
/* @0x25a28c str r3, [r11, #-0x2c] */
/* @0x25a290 str r3, [r11, #-0x88] */
/* @0x25a294 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25a298 ldr r2, [pc, #0x13c] */
/* @0x25a29c mov r1, r9 */
/* @0x25a2a0 ldr r0, [r7] */
/* @0x25a2a4 add r2, pc, r2 */
/* @0x25a2a8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25a2ac ldr r2, [pc, #0x12c] */
/* @0x25a2b0 ldr r0, [r7] */
/* @0x25a2b4 ldr r1, [r11, #-0x84] */
/* @0x25a2b8 add r2, pc, r2 */
/* @0x25a2bc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25a2c0 ldr r2, [pc, #0x11c] */
/* @0x25a2c4 ldr r0, [r7] */
/* @0x25a2c8 mov r1, r8 */
/* @0x25a2cc add r2, pc, r2 */
/* @0x25a2d0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x25a2d4 ldr r3, [r11, #-0x88] */
/* @0x25a2d8 mov r0, r6 */
/* @0x25a2dc mov r1, r3 */
/* @0x25a2e0 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x25a2e4 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x25a2e8 ldr r3, [r11, #-0x88] */
/* @0x25a2ec mov r1, r3 */
/* @0x25a2f0 mov r10, r0 */
/* @0x25a2f4 mov r0, r9 */
/* @0x25a2f8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x25a2fc ldr r3, [r11, #-0x88] */
/* @0x25a300 mov r1, r3 */
/* @0x25a304 mov r9, r0 */
/* @0x25a308 ldr r0, [r11, #-0x84] */
/* @0x25a30c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x25a310 ldr r3, [r11, #-0x88] */
/* @0x25a314 mov r1, r3 */
/* @0x25a318 mov r7, r0 */
/* @0x25a31c mov r0, r8 */
/* @0x25a320 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x25a324 sub sp, sp, #16 */
/* @0x25a328 cmp r9, #0 */
/* @0x25a32c add r2, sp, #8 */
/* @0x25a330 addne r3, r2, #1 */
/* @0x25a334 movne r1, #103 */
/* @0x25a338 moveq r3, r2 */
/* @0x25a33c strbne r1, [r2] */
/* @0x25a340 cmp r7, #0 */
/* @0x25a344 movne r1, #105 */
/* @0x25a348 strbne r1, [r3] */
/* @0x25a34c addne r3, r3, #1 */
/* @0x25a350 cmp r0, #0 */
/* @0x25a354 mov r0, r2 */
/* @0x25a358 mov r2, #0 */
/* @0x25a35c movne r1, #109 */
/* @0x25a360 strbne r1, [r3] */
/* @0x25a364 addne r3, r3, #1 */
/* @0x25a368 strb r2, [r3] */
/* @0x25a36c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x25a370 ldr r3, [r11, #-0x5c] */
/* @0x25a374 sub r3, r3, #1 */
/* @0x25a378 bic r3, r3, #-16777216 */
/* @0x25a37c bic r3, r3, #3 */
/* @0x25a380 cmp r3, #0 */
/* @0x25a384 str r0, [r11, #-0x80] */
/* @0x25a388 bne 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x25a38c mov r0, r6 */
/* @0x25a390 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25a394 b 0x259ff8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x25a398 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x25a39c mulseq r9, r4, r10 */
/* @0x25a3a0 andseq r7, r9, r8, ror #16 */
/* @0x25a3a4 andeq r11, pc, r12, lsr sp */
/* @0x25a3a8 andeq r12, pc, r8, ror #10 */
/* @0x25a3ac strdeq r10, r11, [sp], -r8 */
/* @0x25a3b0 andeq r12, pc, r12, lsr r5 */
/* @0x25a3b4 andeq r12, pc, r0, lsr r5 */
/* @0x25a3b8 andeq r11, pc, r8, ror pc */
/* @0x25a3bc andeq r11, pc, r4, asr #21 */
/* @0x25a3c0 andeq r12, pc, r8, lsl #22 */
/* @0x25a3c4 andeq r4, sp, r10, lsl #19 */
/* @0x25a3c8 andeq r4, sp, r10, ror #18 */
/* @0x25a3cc andeq r12, pc, r0, lsl r9 */
/* @0x25a3d0 strdeq r12, sp, [pc], -r4 */
/* @0x25a3d4 muleq pc, r12, r10 */
/* @0x25a3d8 strdeq r12, sp, [pc], -r0 */
/* @0x25a3dc andeq r10, sp, r4, lsr r12 */
/* @0x25a3e0 andeq r12, pc, r12, ror r3 */
/* @0x25a3e4 andeq r12, pc, r4, ror r3 */

/* ── FUNC 0x25a3e8 · F_JSRegExpCall(RValue&, CInstance*, CInstance*, int, RValue*) · size=4 · insn=1 */
/* @0x25a3e8 b 0x259ea8 <_Z9JS_RegExpR6RValueP9CInstanceS2_iPS_> */

/* ── FUNC 0x25a3ec · JS_JSON_parse(RValue&, CInstance*, CInstance*, int, RValue*) · size=300 · insn=75 */
/* @0x25a3ec push {r4, r5, r6, r7, r8, lr} */
/* @0x25a3f0 sub sp, sp, #1040 */
/* @0x25a3f4 ldr r4, [pc, #0x10c] */
/* @0x25a3f8 sub sp, sp, #8 */
/* @0x25a3fc mov r5, r0 */
/* @0x25a400 add r0, sp, #4 */
/* @0x25a404 ldr r4, [pc, r4] */
/* @0x25a408 ldr r1, [sp, #0x430] */
/* @0x25a40c mov r3, #0 */
/* @0x25a410 mvn r2, #-16777216 */
/* @0x25a414 ldr r12, [r4] */
/* @0x25a418 str r3, [sp, #0x4] */
/* @0x25a41c str r3, [sp, #0x8] */
/* @0x25a420 str r12, [sp, #0x414] */
/* @0x25a424 str r3, [sp, #0xc] */
/* @0x25a428 str r2, [sp, #0x10] */
/* @0x25a42c bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_> */
/* @0x25a430 cmp r0, #2 */
/* @0x25a434 beq 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25a438 cmp r0, #1 */
/* @0x25a43c beq 0x25a4e4 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x25a440 ldr r3, [sp, #0x4] */
/* @0x25a444 ldr r8, [r3] */
/* @0x25a448 mov r0, r8 */
/* @0x25a44c bl 0xb6538 <strlen@plt> */
/* @0x25a450 mov r7, r0 */
/* @0x25a454 bl 0x27eff0 <json_tokener_new> */
/* @0x25a458 mov r1, r8 */
/* @0x25a45c mov r2, r7 */
/* @0x25a460 mov r6, r0 */
/* @0x25a464 bl 0x27f048 <json_tokener_parse_ex> */
/* @0x25a468 ldr r3, [r6, #0x18] */
/* @0x25a46c ldr r2, [r6, #0x14] */
/* @0x25a470 cmp r3, #0 */
/* @0x25a474 mov r8, r0 */
/* @0x25a478 rsbne r8, r3, #0 */
/* @0x25a47c cmp r7, r2 */
/* @0x25a480 ble 0x25a4bc <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x25a484 add r5, sp, #20 */
/* @0x25a488 ldr r1, [pc, #0x7c] */
/* @0x25a48c mov r0, r5 */
/* @0x25a490 add r1, pc, r1 */
/* @0x25a494 bl 0xb6550 <sprintf@plt> */
/* @0x25a498 mov r0, r5 */
/* @0x25a49c bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc> */
/* @0x25a4a0 ldr r2, [sp, #0x414] */
/* @0x25a4a4 ldr r3, [r4] */
/* @0x25a4a8 cmp r2, r3 */
/* @0x25a4ac bne 0x25a504 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x25a4b0 add sp, sp, #1040 */
/* @0x25a4b4 add sp, sp, #8 */
/* @0x25a4b8 pop {r4, r5, r6, r7, r8, pc} */
/* @0x25a4bc mov r0, r6 */
/* @0x25a4c0 bl 0x27f020 <json_tokener_free> */
/* @0x25a4c4 cmn r8, #4000 */
/* @0x25a4c8 bhi 0x25a4f4 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25a4cc mov r0, r8 */
/* @0x25a4d0 mov r1, r5 */
/* @0x25a4d4 bl 0x24beac <_Z10json_parseP11json_objectR6RValue> */
/* @0x25a4d8 mov r0, r8 */
/* @0x25a4dc bl 0x27e7c8 <json_object_put> */
/* @0x25a4e0 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25a4e4 ldr r0, [pc, #0x24] */
/* @0x25a4e8 add r0, pc, r0 */
/* @0x25a4ec bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25a4f0 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25a4f4 ldr r0, [pc, #0x18] */
/* @0x25a4f8 add r0, pc, r0 */
/* @0x25a4fc bl 0x253d88 <_Z18JSThrowSyntaxErrorPKc> */
/* @0x25a500 b 0x25a4a0 <_Z13JS_JSON_parseR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25a504 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x25a508 andseq r3, r9, r12, asr #10 */
/* @0x25a50c andeq r12, pc, r4, asr #17 */
/* @0x25a510 andeq r12, pc, r12, lsr #16 */
/* @0x25a514 andeq r12, pc, r0, lsr #17 */

/* ── FUNC 0x25a518 · JS_Global_abstractRelationalComparison(RValue&, RValue&, RValue&, bool) · size=764 · insn=191 */
/* @0x25a518 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x25a51c cmp r3, #0 */
/* @0x25a520 sub sp, sp, #68 */
/* @0x25a524 mov r4, #0 */
/* @0x25a528 mov r5, #0 */
/* @0x25a52c mov r6, r0 */
/* @0x25a530 mov r7, r2 */
/* @0x25a534 mov r9, r1 */
/* @0x25a538 mov r2, #0 */
/* @0x25a53c strd r4, r5, [sp] */
/* @0x25a540 str r2, [r0, #0xc] */
/* @0x25a544 mvn r0, #-16777216 */
/* @0x25a548 str r2, [sp, #0x8] */
/* @0x25a54c str r2, [sp, #0x18] */
/* @0x25a550 strd r4, r5, [sp, #16] */
/* @0x25a554 str r0, [sp, #0xc] */
/* @0x25a558 str r0, [sp, #0x1c] */
/* @0x25a55c beq 0x25a664 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x14c> */
/* @0x25a560 mov r0, sp */
/* @0x25a564 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25a568 cmp r0, #1 */
/* @0x25a56c beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190> */
/* @0x25a570 cmp r0, #0 */
/* @0x25a574 bne 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170> */
/* @0x25a578 add r4, sp, #16 */
/* @0x25a57c mov r2, r0 */
/* @0x25a580 mov r1, r7 */
/* @0x25a584 mov r0, r4 */
/* @0x25a588 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25a58c cmp r0, #1 */
/* @0x25a590 beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190> */
/* @0x25a594 cmp r0, #0 */
/* @0x25a598 bne 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170> */
/* @0x25a59c ldr r2, [sp, #0x1c] */
/* @0x25a5a0 ldr r3, [sp, #0xc] */
/* @0x25a5a4 bic r2, r2, #-16777216 */
/* @0x25a5a8 bic r3, r3, #-16777216 */
/* @0x25a5ac cmp r3, #1 */
/* @0x25a5b0 cmpeq r2, #1 */
/* @0x25a5b4 bne 0x25a6c0 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x1a8> */
/* @0x25a5b8 ldr r2, [sp] */
/* @0x25a5bc ldr r3, [sp, #0x10] */
/* @0x25a5c0 ldr r4, [r2] */
/* @0x25a5c4 ldr r8, [r3] */
/* @0x25a5c8 mov r0, r4 */
/* @0x25a5cc mov r1, r8 */
/* @0x25a5d0 bl 0xb6604 <strstr@plt> */
/* @0x25a5d4 cmp r4, r0 */
/* @0x25a5d8 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a5dc mov r0, r8 */
/* @0x25a5e0 mov r1, r4 */
/* @0x25a5e4 bl 0xb6604 <strstr@plt> */
/* @0x25a5e8 cmp r8, r0 */
/* @0x25a5ec beq 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130> */
/* @0x25a5f0 add r5, sp, #32 */
/* @0x25a5f4 add r7, sp, #48 */
/* @0x25a5f8 mov r1, r4 */
/* @0x25a5fc mov r0, r5 */
/* @0x25a600 bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x25a604 mov r1, r8 */
/* @0x25a608 mov r0, r7 */
/* @0x25a60c bl 0x2423d8 <_ZN23CCodepointIterator_UTF8C2EPKc> */
/* @0x25a610 b 0x25a61c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x104> */
/* @0x25a614 cmp r4, r0 */
/* @0x25a618 bne 0x25a7f0 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2d8> */
/* @0x25a61c mov r0, r5 */
/* @0x25a620 bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x25a624 mov r4, r0 */
/* @0x25a628 mov r0, r7 */
/* @0x25a62c bl 0x242408 <_ZN23CCodepointIterator_UTF87GetNextEv> */
/* @0x25a630 cmp r4, #0 */
/* @0x25a634 cmpne r0, #0 */
/* @0x25a638 bne 0x25a614 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0xfc> */
/* @0x25a63c ldr r0, [pc, #0x1c8] */
/* @0x25a640 add r0, pc, r0 */
/* @0x25a644 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x25a648 mov r0, #0 */
/* @0x25a64c str r0, [r6] */
/* @0x25a650 mov r3, r0 */
/* @0x25a654 movt r3, #0x3ff0 */
/* @0x25a658 str r3, [r6, #0x4] */
/* @0x25a65c add sp, sp, #68 */
/* @0x25a660 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x25a664 add r4, sp, #16 */
/* @0x25a668 mov r1, r7 */
/* @0x25a66c mov r2, r3 */
/* @0x25a670 mov r0, r4 */
/* @0x25a674 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25a678 cmp r0, #1 */
/* @0x25a67c beq 0x25a6a8 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x190> */
/* @0x25a680 cmp r0, #0 */
/* @0x25a684 beq 0x25a690 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x178> */
/* @0x25a688 add sp, sp, #68 */
/* @0x25a68c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x25a690 mov r2, r0 */
/* @0x25a694 mov r1, r9 */
/* @0x25a698 mov r0, sp */
/* @0x25a69c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25a6a0 cmp r0, #1 */
/* @0x25a6a4 bne 0x25a594 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x7c> */
/* @0x25a6a8 ldr r0, [pc, #0x160] */
/* @0x25a6ac add r0, pc, r0 */
/* @0x25a6b0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25a6b4 mov r0, #1 */
/* @0x25a6b8 add sp, sp, #68 */
/* @0x25a6bc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x25a6c0 add r5, sp, #32 */
/* @0x25a6c4 add r7, sp, #48 */
/* @0x25a6c8 mov r1, sp */
/* @0x25a6cc mov r2, #0 */
/* @0x25a6d0 mov r0, r5 */
/* @0x25a6d4 mov r3, #0 */
/* @0x25a6d8 strd r2, r3, [sp, #32] */
/* @0x25a6dc strd r2, r3, [sp, #48] */
/* @0x25a6e0 mov r2, #0 */
/* @0x25a6e4 mvn r3, #-16777216 */
/* @0x25a6e8 str r2, [sp, #0x28] */
/* @0x25a6ec str r2, [sp, #0x38] */
/* @0x25a6f0 str r3, [sp, #0x2c] */
/* @0x25a6f4 str r3, [sp, #0x3c] */
/* @0x25a6f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25a6fc mov r1, r4 */
/* @0x25a700 mov r0, r7 */
/* @0x25a704 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25a708 vldr d7, [sp, #32] */
/* @0x25a70c vcmp.f64 d7, d7 */
/* @0x25a710 vmrs APSR_nzcv, fpscr */
/* @0x25a714 bvs 0x25a7fc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2e4> */
/* @0x25a718 vldr d6, [sp, #48] */
/* @0x25a71c vcmp.f64 d6, d6 */
/* @0x25a720 vmrs APSR_nzcv, fpscr */
/* @0x25a724 bvs 0x25a7fc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2e4> */
/* @0x25a728 vcmp.f64 d7, d6 */
/* @0x25a72c vmrs APSR_nzcv, fpscr */
/* @0x25a730 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a734 vcmp.f64 d7, #0 */
/* @0x25a738 vmrs APSR_nzcv, fpscr */
/* @0x25a73c bne 0x25a74c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x234> */
/* @0x25a740 vcmp.f64 d6, #0 */
/* @0x25a744 vmrs APSR_nzcv, fpscr */
/* @0x25a748 beq 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a74c mov r0, r5 */
/* @0x25a750 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x25a754 cmp r0, #0 */
/* @0x25a758 beq 0x25a76c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x254> */
/* @0x25a75c vldr d7, [sp, #32] */
/* @0x25a760 vcmpe.f64 d7, #0 */
/* @0x25a764 vmrs APSR_nzcv, fpscr */
/* @0x25a768 bgt 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a76c mov r0, r7 */
/* @0x25a770 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x25a774 cmp r0, #0 */
/* @0x25a778 beq 0x25a78c <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x274> */
/* @0x25a77c vldr d7, [sp, #48] */
/* @0x25a780 vcmpe.f64 d7, #0 */
/* @0x25a784 vmrs APSR_nzcv, fpscr */
/* @0x25a788 bgt 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130> */
/* @0x25a78c mov r0, r7 */
/* @0x25a790 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x25a794 cmp r0, #0 */
/* @0x25a798 beq 0x25a7ac <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x294> */
/* @0x25a79c vldr d7, [sp, #48] */
/* @0x25a7a0 vcmpe.f64 d7, #0 */
/* @0x25a7a4 vmrs APSR_nzcv, fpscr */
/* @0x25a7a8 bmi 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a7ac mov r0, r5 */
/* @0x25a7b0 bl 0x240970 <_Z7yyisinfR6RValue> */
/* @0x25a7b4 vldr d7, [sp, #32] */
/* @0x25a7b8 cmp r0, #0 */
/* @0x25a7bc beq 0x25a7cc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2b4> */
/* @0x25a7c0 vcmpe.f64 d7, #0 */
/* @0x25a7c4 vmrs APSR_nzcv, fpscr */
/* @0x25a7c8 bmi 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130> */
/* @0x25a7cc vldr d6, [sp, #48] */
/* @0x25a7d0 vcmpe.f64 d7, d6 */
/* @0x25a7d4 vmrs APSR_nzcv, fpscr */
/* @0x25a7d8 bmi 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130> */
/* @0x25a7dc mov r0, #0 */
/* @0x25a7e0 str r0, [r6] */
/* @0x25a7e4 str r0, [r6, #0x4] */
/* @0x25a7e8 add sp, sp, #68 */
/* @0x25a7ec pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x25a7f0 cmp r4, r0 */
/* @0x25a7f4 blt 0x25a648 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x130> */
/* @0x25a7f8 b 0x25a7dc <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x2c4> */
/* @0x25a7fc mov r3, #5 */
/* @0x25a800 mov r0, #0 */
/* @0x25a804 str r3, [r6, #0xc] */
/* @0x25a808 b 0x25a688 <_Z38JS_Global_abstractRelationalComparisonR6RValueS0_S0_b+0x170> */
/* @0x25a80c andeq r12, pc, r0, asr #15 */
/* @0x25a810 andeq r12, pc, r4, lsl r7 */

/* ── FUNC 0x25a814 · JS_Global_abstractEqualityComparison(RValue&, RValue&, RValue&) · size=1216 · insn=304 */
/* @0x25a814 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x25a818 mov r10, r2 */
/* @0x25a81c ldr r3, [r1, #0xc] */
/* @0x25a820 mov r8, r0 */
/* @0x25a824 ldr r2, [r2, #0xc] */
/* @0x25a828 sub sp, sp, #16 */
/* @0x25a82c bic r3, r3, #-16777216 */
/* @0x25a830 mov r9, r1 */
/* @0x25a834 bic r0, r2, #-16777216 */
/* @0x25a838 cmp r3, r0 */
/* @0x25a83c beq 0x25a8d0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xbc> */
/* @0x25a840 cmp r3, #5 */
/* @0x25a844 cmpeq r0, #12 */
/* @0x25a848 beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25a84c cmp r3, #12 */
/* @0x25a850 cmpeq r0, #5 */
/* @0x25a854 movne r2, #0 */
/* @0x25a858 moveq r2, #1 */
/* @0x25a85c beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25a860 cmp r3, #0 */
/* @0x25a864 cmpeq r0, #1 */
/* @0x25a868 movne r12, #0 */
/* @0x25a86c moveq r12, #1 */
/* @0x25a870 beq 0x25a938 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x124> */
/* @0x25a874 cmp r3, #1 */
/* @0x25a878 cmpeq r0, #0 */
/* @0x25a87c movne r4, #0 */
/* @0x25a880 moveq r4, #1 */
/* @0x25a884 beq 0x25a9c0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x1ac> */
/* @0x25a888 cmp r3, #13 */
/* @0x25a88c beq 0x25abd8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x3c4> */
/* @0x25a890 cmp r0, #13 */
/* @0x25a894 beq 0x25aa30 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x21c> */
/* @0x25a898 cmp r3, #1 */
/* @0x25a89c cmpls r0, #6 */
/* @0x25a8a0 movne r12, #0 */
/* @0x25a8a4 moveq r12, #1 */
/* @0x25a8a8 beq 0x25aafc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2e8> */
/* @0x25a8ac cmp r0, #1 */
/* @0x25a8b0 cmpls r3, #6 */
/* @0x25a8b4 beq 0x25ab68 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x354> */
/* @0x25a8b8 mov r3, #0 */
/* @0x25a8bc str r3, [r8] */
/* @0x25a8c0 mov r0, r3 */
/* @0x25a8c4 str r3, [r8, #0x4] */
/* @0x25a8c8 add sp, sp, #16 */
/* @0x25a8cc pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25a8d0 cmp r3, #5 */
/* @0x25a8d4 beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25a8d8 cmp r3, #12 */
/* @0x25a8dc beq 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25a8e0 cmp r3, #0 */
/* @0x25a8e4 bne 0x25a994 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x180> */
/* @0x25a8e8 vldr s14, [r1] */
/* @0x25a8ec vldr s15, [r1, #4] */
/* @0x25a8f0 vcmp.f64 d7, d7 */
/* @0x25a8f4 vmrs APSR_nzcv, fpscr */
/* @0x25a8f8 bvs 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25a8fc vldr s12, [r10] */
/* @0x25a900 vldr s13, [r10, #4] */
/* @0x25a904 vcmp.f64 d6, d6 */
/* @0x25a908 vmrs APSR_nzcv, fpscr */
/* @0x25a90c bvs 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25a910 vcmp.f64 d7, d6 */
/* @0x25a914 vmrs APSR_nzcv, fpscr */
/* @0x25a918 bne 0x25aaa0 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x28c> */
/* @0x25a91c mov r0, #0 */
/* @0x25a920 str r0, [r8] */
/* @0x25a924 mov r3, r0 */
/* @0x25a928 movt r3, #0x3ff0 */
/* @0x25a92c str r3, [r8, #0x4] */
/* @0x25a930 add sp, sp, #16 */
/* @0x25a934 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25a938 mov r1, r10 */
/* @0x25a93c mov r0, sp */
/* @0x25a940 mov r4, #0 */
/* @0x25a944 mvn r3, #-16777216 */
/* @0x25a948 str r2, [sp, #0x8] */
/* @0x25a94c mov r5, #0 */
/* @0x25a950 str r3, [sp, #0xc] */
/* @0x25a954 strd r4, r5, [sp] */
/* @0x25a958 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25a95c cmp r0, #1 */
/* @0x25a960 mov r4, r0 */
/* @0x25a964 beq 0x25ac44 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x430> */
/* @0x25a968 cmp r4, #0 */
/* @0x25a96c beq 0x25aaec <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2d8> */
/* @0x25a970 ldr r3, [sp, #0xc] */
/* @0x25a974 sub r3, r3, #1 */
/* @0x25a978 bic r3, r3, #-16777216 */
/* @0x25a97c bic r3, r3, #3 */
/* @0x25a980 cmp r3, #0 */
/* @0x25a984 beq 0x25aa94 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x280> */
/* @0x25a988 mov r0, r4 */
/* @0x25a98c add sp, sp, #16 */
/* @0x25a990 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25a994 cmp r3, #13 */
/* @0x25a998 beq 0x25ab40 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x32c> */
/* @0x25a99c cmp r3, #1 */
/* @0x25a9a0 beq 0x25aabc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2a8> */
/* @0x25a9a4 cmp r3, #6 */
/* @0x25a9a8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25a9ac ldr r2, [r1] */
/* @0x25a9b0 ldr r3, [r10] */
/* @0x25a9b4 cmp r2, r3 */
/* @0x25a9b8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25a9bc b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25a9c0 mov r0, sp */
/* @0x25a9c4 mov r4, #0 */
/* @0x25a9c8 mvn r3, #-16777216 */
/* @0x25a9cc str r12, [sp, #0x8] */
/* @0x25a9d0 mov r5, #0 */
/* @0x25a9d4 str r3, [sp, #0xc] */
/* @0x25a9d8 strd r4, r5, [sp] */
/* @0x25a9dc bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25a9e0 cmp r0, #1 */
/* @0x25a9e4 mov r4, r0 */
/* @0x25a9e8 beq 0x25aadc <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x2c8> */
/* @0x25a9ec cmp r0, #0 */
/* @0x25a9f0 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25a9f4 mov r0, r8 */
/* @0x25a9f8 mov r2, r10 */
/* @0x25a9fc mov r1, sp */
/* @0x25aa00 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0x25aa04 ldr r3, [sp, #0xc] */
/* @0x25aa08 sub r3, r3, #1 */
/* @0x25aa0c bic r3, r3, #-16777216 */
/* @0x25aa10 subs r4, r0, #0 */
/* @0x25aa14 bne 0x25a97c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x168> */
/* @0x25aa18 bics r5, r3, #3 */
/* @0x25aa1c bne 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174> */
/* @0x25aa20 mov r0, sp */
/* @0x25aa24 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25aa28 mov r0, r5 */
/* @0x25aa2c b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c> */
/* @0x25aa30 mov r1, r10 */
/* @0x25aa34 mov r0, sp */
/* @0x25aa38 str r4, [sp, #0x8] */
/* @0x25aa3c mov r2, #0 */
/* @0x25aa40 mov r3, #0 */
/* @0x25aa44 strd r2, r3, [sp] */
/* @0x25aa48 mvn r3, #-16777216 */
/* @0x25aa4c str r3, [sp, #0xc] */
/* @0x25aa50 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25aa54 cmp r0, #1 */
/* @0x25aa58 mov r4, r0 */
/* @0x25aa5c beq 0x25ac9c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x488> */
/* @0x25aa60 cmp r0, #0 */
/* @0x25aa64 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25aa68 mov r0, r8 */
/* @0x25aa6c mov r1, r9 */
/* @0x25aa70 mov r2, sp */
/* @0x25aa74 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0x25aa78 ldr r3, [sp, #0xc] */
/* @0x25aa7c sub r3, r3, #1 */
/* @0x25aa80 bic r3, r3, #-16777216 */
/* @0x25aa84 subs r4, r0, #0 */
/* @0x25aa88 bne 0x25a97c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x168> */
/* @0x25aa8c bics r4, r3, #3 */
/* @0x25aa90 bne 0x25ac3c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x428> */
/* @0x25aa94 mov r0, sp */
/* @0x25aa98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25aa9c b 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174> */
/* @0x25aaa0 vcmp.f64 d7, #0 */
/* @0x25aaa4 vmrs APSR_nzcv, fpscr */
/* @0x25aaa8 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25aaac vcmp.f64 d6, #0 */
/* @0x25aab0 vmrs APSR_nzcv, fpscr */
/* @0x25aab4 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25aab8 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25aabc ldr r2, [r1] */
/* @0x25aac0 ldr r3, [r10] */
/* @0x25aac4 ldr r0, [r2] */
/* @0x25aac8 ldr r1, [r3] */
/* @0x25aacc bl 0xb6574 <strcmp@plt> */
/* @0x25aad0 cmp r0, #0 */
/* @0x25aad4 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25aad8 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25aadc ldr r0, [pc, #0x1d8] */
/* @0x25aae0 add r0, pc, r0 */
/* @0x25aae4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25aae8 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25aaec mov r0, r8 */
/* @0x25aaf0 mov r1, r9 */
/* @0x25aaf4 mov r2, sp */
/* @0x25aaf8 b 0x25aa00 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x1ec> */
/* @0x25aafc mov r2, r4 */
/* @0x25ab00 mov r1, r10 */
/* @0x25ab04 mov r0, sp */
/* @0x25ab08 str r4, [sp, #0x8] */
/* @0x25ab0c mvn r3, #-16777216 */
/* @0x25ab10 mov r4, #0 */
/* @0x25ab14 mov r5, #0 */
/* @0x25ab18 str r3, [sp, #0xc] */
/* @0x25ab1c strd r4, r5, [sp] */
/* @0x25ab20 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25ab24 cmp r0, #1 */
/* @0x25ab28 mov r4, r0 */
/* @0x25ab2c bne 0x25a968 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x154> */
/* @0x25ab30 ldr r0, [pc, #0x188] */
/* @0x25ab34 add r0, pc, r0 */
/* @0x25ab38 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25ab3c b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25ab40 ldr r6, [r1] */
/* @0x25ab44 ldr r4, [r10] */
/* @0x25ab48 ldr r7, [r1, #0x4] */
/* @0x25ab4c ldr r5, [r10, #0x4] */
/* @0x25ab50 vmov d6, r6, r7 */
/* @0x25ab54 vmov d7, r4, r5 */
/* @0x25ab58 vcmp.f64 d6, d7 */
/* @0x25ab5c vmrs APSR_nzcv, fpscr */
/* @0x25ab60 bne 0x25a8b8 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0xa4> */
/* @0x25ab64 b 0x25a91c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x108> */
/* @0x25ab68 mov r2, r12 */
/* @0x25ab6c mov r0, sp */
/* @0x25ab70 mov r4, #0 */
/* @0x25ab74 mvn r3, #-16777216 */
/* @0x25ab78 str r12, [sp, #0x8] */
/* @0x25ab7c mov r5, #0 */
/* @0x25ab80 str r3, [sp, #0xc] */
/* @0x25ab84 strd r4, r5, [sp] */
/* @0x25ab88 bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25ab8c cmp r0, #1 */
/* @0x25ab90 mov r4, r0 */
/* @0x25ab94 beq 0x25ac60 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x44c> */
/* @0x25ab98 cmp r4, #0 */
/* @0x25ab9c bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25aba0 mov r0, r8 */
/* @0x25aba4 mov r2, r10 */
/* @0x25aba8 mov r1, sp */
/* @0x25abac bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0x25abb0 ldr r3, [sp, #0xc] */
/* @0x25abb4 sub r3, r3, #1 */
/* @0x25abb8 bic r3, r3, #-16777216 */
/* @0x25abbc bic r3, r3, #3 */
/* @0x25abc0 subs r5, r0, #0 */
/* @0x25abc4 beq 0x25ac54 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x440> */
/* @0x25abc8 cmp r3, #0 */
/* @0x25abcc movne r0, r5 */
/* @0x25abd0 bne 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c> */
/* @0x25abd4 b 0x25aa20 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x20c> */
/* @0x25abd8 mov r0, sp */
/* @0x25abdc str r4, [sp, #0x8] */
/* @0x25abe0 mov r2, #0 */
/* @0x25abe4 mov r3, #0 */
/* @0x25abe8 mvn r12, #-16777216 */
/* @0x25abec strd r2, r3, [sp] */
/* @0x25abf0 str r12, [sp, #0xc] */
/* @0x25abf4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25abf8 cmp r0, #1 */
/* @0x25abfc mov r4, r0 */
/* @0x25ac00 beq 0x25ac8c <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x478> */
/* @0x25ac04 cmp r0, #0 */
/* @0x25ac08 bne 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25ac0c mov r0, r8 */
/* @0x25ac10 mov r2, r10 */
/* @0x25ac14 mov r1, sp */
/* @0x25ac18 bl 0x25a814 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_> */
/* @0x25ac1c ldr r3, [sp, #0xc] */
/* @0x25ac20 sub r3, r3, #1 */
/* @0x25ac24 bic r3, r3, #-16777216 */
/* @0x25ac28 bic r3, r3, #3 */
/* @0x25ac2c subs r4, r0, #0 */
/* @0x25ac30 bne 0x25ac54 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x440> */
/* @0x25ac34 cmp r3, #0 */
/* @0x25ac38 beq 0x25acac <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x498> */
/* @0x25ac3c mov r0, #0 */
/* @0x25ac40 b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c> */
/* @0x25ac44 ldr r0, [pc, #0x78] */
/* @0x25ac48 add r0, pc, r0 */
/* @0x25ac4c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25ac50 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25ac54 cmp r3, #0 */
/* @0x25ac58 bne 0x25a988 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x174> */
/* @0x25ac5c b 0x25aa94 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x280> */
/* @0x25ac60 mov r1, r9 */
/* @0x25ac64 mov r0, sp */
/* @0x25ac68 mov r2, #0 */
/* @0x25ac6c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i> */
/* @0x25ac70 cmp r0, #1 */
/* @0x25ac74 mov r4, r0 */
/* @0x25ac78 bne 0x25ab98 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x384> */
/* @0x25ac7c ldr r0, [pc, #0x44] */
/* @0x25ac80 add r0, pc, r0 */
/* @0x25ac84 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25ac88 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25ac8c ldr r0, [pc, #0x38] */
/* @0x25ac90 add r0, pc, r0 */
/* @0x25ac94 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25ac98 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25ac9c ldr r0, [pc, #0x2c] */
/* @0x25aca0 add r0, pc, r0 */
/* @0x25aca4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25aca8 b 0x25a970 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x15c> */
/* @0x25acac mov r0, sp */
/* @0x25acb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25acb4 mov r0, #0 */
/* @0x25acb8 b 0x25a930 <_Z36JS_Global_abstractEqualityComparisonR6RValueS0_S0_+0x11c> */
/* @0x25acbc andeq r12, pc, r12, ror r3 */
/* @0x25acc0 andeq r12, pc, r12, asr r3 */
/* @0x25acc4 ldrdeq r12, sp, [pc], -r12 */
/* @0x25acc8 andeq r12, pc, r8, asr #4 */
/* @0x25accc andeq r12, pc, r12, asr #3 */
/* @0x25acd0 andeq r12, pc, r4, lsl #3 */

/* ── FUNC 0x25acd4 · F_JSNewObject(RValue&, CInstance*, CInstance*, int, RValue*) · size=1108 · insn=277 */
/* @0x25acd4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25acd8 sub sp, sp, #28 */
/* @0x25acdc mov r4, r0 */
/* @0x25ace0 mov r6, r3 */
/* @0x25ace4 ldr r12, [sp, #0x40] */
/* @0x25ace8 str r12, [sp] */
/* @0x25acec str r12, [sp, #0x10] */
/* @0x25acf0 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_> */
/* @0x25acf4 ldr r5, [r4] */
/* @0x25acf8 mov r0, r5 */
/* @0x25acfc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x25ad00 cmp r6, #0 */
/* @0x25ad04 ble 0x25ae2c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x25ad08 ldr r3, [sp, #0x10] */
/* @0x25ad0c mov r8, #0 */
/* @0x25ad10 ldr r12, [sp, #0x10] */
/* @0x25ad14 add r3, r3, #16 */
/* @0x25ad18 str r3, [sp, #0x14] */
/* @0x25ad1c add r7, r12, #28 */
/* @0x25ad20 mov r10, r3 */
/* @0x25ad24 ldr r2, [r10, #-0x10] */
/* @0x25ad28 mov r0, r5 */
/* @0x25ad2c sub r9, r10, #16 */
/* @0x25ad30 ldr r1, [r2] */
/* @0x25ad34 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x25ad38 ldr r4, [r5, #0x4] */
/* @0x25ad3c cmp r4, #0 */
/* @0x25ad40 mov r11, r0 */
/* @0x25ad44 beq 0x25af64 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x290> */
/* @0x25ad48 add r4, r4, r0, lsl #4 */
/* @0x25ad4c ldr r1, [r4, #0xc] */
/* @0x25ad50 bic r2, r1, #-16777216 */
/* @0x25ad54 cmp r2, #1 */
/* @0x25ad58 beq 0x25aec8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x25ad5c cmp r2, #2 */
/* @0x25ad60 bne 0x25ad84 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x25ad64 sub r1, r1, #1 */
/* @0x25ad68 bic r1, r1, #-16777216 */
/* @0x25ad6c bic r1, r1, #3 */
/* @0x25ad70 cmp r1, #0 */
/* @0x25ad74 beq 0x25af58 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x25ad78 mov r3, #5 */
/* @0x25ad7c str r8, [r4, #0x8] */
/* @0x25ad80 str r3, [r4, #0xc] */
/* @0x25ad84 ldr r12, [sp, #0x10] */
/* @0x25ad88 ldr r3, [sp, #0x14] */
/* @0x25ad8c rsb r2, r12, r10 */
/* @0x25ad90 str r8, [r4] */
/* @0x25ad94 add r2, r3, r2 */
/* @0x25ad98 ldr r1, [r2, #-0x4] */
/* @0x25ad9c str r1, [r4, #0xc] */
/* @0x25ada0 ldr r1, [r2, #-0x8] */
/* @0x25ada4 str r1, [r4, #0x8] */
/* @0x25ada8 ldr r2, [r2, #-0x4] */
/* @0x25adac bic r2, r2, #-16777216 */
/* @0x25adb0 cmp r2, #14 */
/* @0x25adb4 addls pc, pc, r2, lsl #2 */
/* @0x25adb8 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25adbc b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x25adc0 b 0x25ae8c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x25adc4 b 0x25ae60 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x25adc8 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x25adcc b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25add0 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25add4 b 0x25aea4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x25add8 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x25addc b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25ade0 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25ade4 b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x25ade8 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25adec b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25adf0 b 0x25ae38 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x25adf4 b 0x25adf8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x25adf8 ldr r2, [r7, #-0xc] */
/* @0x25adfc str r2, [r4] */
/* @0x25ae00 ldr r0, [r5, #0x4] */
/* @0x25ae04 cmp r0, #0 */
/* @0x25ae08 beq 0x25ae50 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x25ae0c add r0, r0, r11, lsl #4 */
/* @0x25ae10 sub r6, r6, #2 */
/* @0x25ae14 mov r12, #7 */
/* @0x25ae18 cmp r6, #0 */
/* @0x25ae1c str r12, [r0, #0x8] */
/* @0x25ae20 add r7, r7, #32 */
/* @0x25ae24 add r10, r10, #32 */
/* @0x25ae28 bgt 0x25ad24 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x25ae2c add sp, sp, #28 */
/* @0x25ae30 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25ae34 b 0xd3a34 <_Z15PopContextStackv> */
/* @0x25ae38 ldr r1, [r9, #0x10] */
/* @0x25ae3c ldr r2, [r9, #0x14] */
/* @0x25ae40 stm r4, {r1, r2} */
/* @0x25ae44 ldr r0, [r5, #0x4] */
/* @0x25ae48 cmp r0, #0 */
/* @0x25ae4c bne 0x25ae0c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x25ae50 mov r1, r11 */
/* @0x25ae54 mov r0, r5 */
/* @0x25ae58 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25ae5c b 0x25ae10 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x25ae60 ldr r2, [r7, #-0xc] */
/* @0x25ae64 cmp r2, #0 */
/* @0x25ae68 str r2, [r4] */
/* @0x25ae6c beq 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25ae70 ldr r0, [r2, #0x8] */
/* @0x25ae74 ldr r1, [r2] */
/* @0x25ae78 cmp r0, #0 */
/* @0x25ae7c streq r4, [r2, #0x8] */
/* @0x25ae80 add r1, r1, #1 */
/* @0x25ae84 str r1, [r2] */
/* @0x25ae88 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25ae8c ldr r2, [r7, #-0xc] */
/* @0x25ae90 cmp r2, #0 */
/* @0x25ae94 ldrne r1, [r2, #0x4] */
/* @0x25ae98 addne r1, r1, #1 */
/* @0x25ae9c strne r1, [r2, #0x4] */
/* @0x25aea0 b 0x25adfc <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x25aea4 ldr r2, [r7, #-0xc] */
/* @0x25aea8 str r2, [r4] */
/* @0x25aeac ldr r2, [r7, #-0xc] */
/* @0x25aeb0 cmp r2, #0 */
/* @0x25aeb4 beq 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25aeb8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x25aebc ldr r1, [r7, #-0xc] */
/* @0x25aec0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x25aec4 b 0x25ae00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x25aec8 ldr r2, [r4] */
/* @0x25aecc cmp r2, #0 */
/* @0x25aed0 beq 0x25aef8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x25aed4 str r2, [sp, #0x8] */
/* @0x25aed8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25aedc ldr r2, [sp, #0x8] */
/* @0x25aee0 ldr r1, [r2, #0x4] */
/* @0x25aee4 sub r1, r1, #1 */
/* @0x25aee8 str r1, [r2, #0x4] */
/* @0x25aeec cmp r1, #0 */
/* @0x25aef0 beq 0x25af00 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x25aef4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25aef8 str r8, [r4] */
/* @0x25aefc b 0x25ad84 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x25af00 ldr r0, [r2] */
/* @0x25af04 str r1, [sp, #0xc] */
/* @0x25af08 str r2, [sp, #0x8] */
/* @0x25af0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25af10 ldr r2, [sp, #0x8] */
/* @0x25af14 ldr r1, [sp, #0xc] */
/* @0x25af18 str r1, [r2] */
/* @0x25af1c str r1, [r2, #0x8] */
/* @0x25af20 str r2, [sp, #0x8] */
/* @0x25af24 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25af28 ldr r2, [sp, #0x8] */
/* @0x25af2c ldr r1, [r2, #0x4] */
/* @0x25af30 sub r1, r1, #1 */
/* @0x25af34 str r1, [r2, #0x4] */
/* @0x25af38 cmp r1, #0 */
/* @0x25af3c beq 0x25af78 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x25af40 str r2, [sp, #0x8] */
/* @0x25af44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25af48 ldr r2, [sp, #0x8] */
/* @0x25af4c mov r0, r2 */
/* @0x25af50 bl 0x27d1d0 <_ZdlPv> */
/* @0x25af54 b 0x25aef4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x25af58 mov r0, r4 */
/* @0x25af5c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25af60 b 0x25ad78 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x25af64 mov r0, r5 */
/* @0x25af68 mov r1, r11 */
/* @0x25af6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25af70 mov r4, r0 */
/* @0x25af74 b 0x25ad4c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x25af78 ldr r0, [r2] */
/* @0x25af7c str r1, [sp, #0xc] */
/* @0x25af80 str r2, [sp, #0x8] */
/* @0x25af84 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25af88 ldr r2, [sp, #0x8] */
/* @0x25af8c ldr r1, [sp, #0xc] */
/* @0x25af90 str r1, [r2] */
/* @0x25af94 str r1, [r2, #0x8] */
/* @0x25af98 str r2, [sp, #0x8] */
/* @0x25af9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25afa0 ldr r2, [sp, #0x8] */
/* @0x25afa4 ldr r1, [r2, #0x4] */
/* @0x25afa8 sub r1, r1, #1 */
/* @0x25afac str r1, [r2, #0x4] */
/* @0x25afb0 cmp r1, #0 */
/* @0x25afb4 beq 0x25afd4 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x25afb8 str r2, [sp, #0x8] */
/* @0x25afbc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25afc0 ldr r2, [sp, #0x8] */
/* @0x25afc4 mov r0, r2 */
/* @0x25afc8 bl 0x27d1d0 <_ZdlPv> */
/* @0x25afcc ldr r2, [sp, #0x8] */
/* @0x25afd0 b 0x25af40 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x25afd4 ldr r0, [r2] */
/* @0x25afd8 str r1, [sp, #0xc] */
/* @0x25afdc str r2, [sp, #0x8] */
/* @0x25afe0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25afe4 ldr r2, [sp, #0x8] */
/* @0x25afe8 ldr r1, [sp, #0xc] */
/* @0x25afec str r1, [r2] */
/* @0x25aff0 str r1, [r2, #0x8] */
/* @0x25aff4 str r2, [sp, #0x8] */
/* @0x25aff8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25affc ldr r2, [sp, #0x8] */
/* @0x25b000 ldr r1, [r2, #0x4] */
/* @0x25b004 sub r1, r1, #1 */
/* @0x25b008 str r1, [r2, #0x4] */
/* @0x25b00c cmp r1, #0 */
/* @0x25b010 beq 0x25b030 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x35c> */
/* @0x25b014 str r2, [sp, #0x8] */
/* @0x25b018 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b01c ldr r2, [sp, #0x8] */
/* @0x25b020 mov r0, r2 */
/* @0x25b024 bl 0x27d1d0 <_ZdlPv> */
/* @0x25b028 ldr r2, [sp, #0x8] */
/* @0x25b02c b 0x25afb8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x2e4> */
/* @0x25b030 ldr r0, [r2] */
/* @0x25b034 str r1, [sp, #0xc] */
/* @0x25b038 str r2, [sp, #0x8] */
/* @0x25b03c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b040 ldr r2, [sp, #0x8] */
/* @0x25b044 ldr r1, [sp, #0xc] */
/* @0x25b048 str r1, [r2] */
/* @0x25b04c str r1, [r2, #0x8] */
/* @0x25b050 str r2, [sp, #0x8] */
/* @0x25b054 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b058 ldr r2, [sp, #0x8] */
/* @0x25b05c ldr r1, [r2, #0x4] */
/* @0x25b060 sub r1, r1, #1 */
/* @0x25b064 str r1, [r2, #0x4] */
/* @0x25b068 cmp r1, #0 */
/* @0x25b06c beq 0x25b08c <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x3b8> */
/* @0x25b070 str r2, [sp, #0x8] */
/* @0x25b074 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b078 ldr r2, [sp, #0x8] */
/* @0x25b07c mov r0, r2 */
/* @0x25b080 bl 0x27d1d0 <_ZdlPv> */
/* @0x25b084 ldr r2, [sp, #0x8] */
/* @0x25b088 b 0x25b014 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x25b08c ldr r0, [r2] */
/* @0x25b090 str r1, [sp, #0xc] */
/* @0x25b094 str r2, [sp, #0x8] */
/* @0x25b098 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b09c ldr r2, [sp, #0x8] */
/* @0x25b0a0 ldr r1, [sp, #0xc] */
/* @0x25b0a4 str r1, [r2] */
/* @0x25b0a8 str r1, [r2, #0x8] */
/* @0x25b0ac str r2, [sp, #0x8] */
/* @0x25b0b0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b0b4 ldr r2, [sp, #0x8] */
/* @0x25b0b8 ldr r1, [r2, #0x4] */
/* @0x25b0bc sub r1, r1, #1 */
/* @0x25b0c0 str r1, [r2, #0x4] */
/* @0x25b0c4 cmp r1, #0 */
/* @0x25b0c8 beq 0x25b0e8 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x414> */
/* @0x25b0cc str r2, [sp, #0x8] */
/* @0x25b0d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b0d4 ldr r2, [sp, #0x8] */
/* @0x25b0d8 mov r0, r2 */
/* @0x25b0dc bl 0x27d1d0 <_ZdlPv> */
/* @0x25b0e0 ldr r2, [sp, #0x8] */
/* @0x25b0e4 b 0x25b070 <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x25b0e8 ldr r0, [r2] */
/* @0x25b0ec str r1, [sp, #0xc] */
/* @0x25b0f0 str r2, [sp, #0x8] */
/* @0x25b0f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b0f8 ldr r2, [sp, #0x8] */
/* @0x25b0fc ldr r1, [sp, #0xc] */
/* @0x25b100 mov r0, r2 */
/* @0x25b104 str r1, [r2] */
/* @0x25b108 str r1, [r2, #0x8] */
/* @0x25b10c str r2, [sp, #0x8] */
/* @0x25b110 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x25b114 ldr r2, [sp, #0x8] */
/* @0x25b118 mov r0, r2 */
/* @0x25b11c bl 0x27d1d0 <_ZdlPv> */
/* @0x25b120 ldr r2, [sp, #0x8] */
/* @0x25b124 b 0x25b0cc <_Z13F_JSNewObjectR6RValueP9CInstanceS2_iPS_+0x3f8> */

/* ── FUNC 0x25b128 · JS_Array_prototype_unshift(RValue&, CInstance*, CInstance*, int, RValue*) · size=1020 · insn=255 */
/* @0x25b128 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25b12c sub sp, sp, #28 */
/* @0x25b130 ldr r2, [r1, #0x4] */
/* @0x25b134 mov r9, r3 */
/* @0x25b138 ldr r3, [sp, #0x40] */
/* @0x25b13c mov r6, r0 */
/* @0x25b140 cmp r2, #0 */
/* @0x25b144 str r3, [sp, #0x14] */
/* @0x25b148 beq 0x25b448 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x320> */
/* @0x25b14c add r0, r2, #16 */
/* @0x25b150 ldr r8, [r0] */
/* @0x25b154 cmp r9, #0 */
/* @0x25b158 mov r11, #0 */
/* @0x25b15c ldr r10, [r8, #0x24] */
/* @0x25b160 str r11, [r6, #0xc] */
/* @0x25b164 add r7, r9, r10 */
/* @0x25b168 vmov s15, r7 */
/* @0x25b16c vcvt.f64.u32 d7, s15 */
/* @0x25b170 vmov r4, r5, d7 */
/* @0x25b174 vmov r1, s14 */
/* @0x25b178 mov r2, r5 */
/* @0x25b17c stm r6, {r1, r2} */
/* @0x25b180 ble 0x25b3e4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x25b184 mov r0, r8 */
/* @0x25b188 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x25b18c ldr r2, [pc, #0x38c] */
/* @0x25b190 ldr r0, [r8, #0x4] */
/* @0x25b194 lsl r1, r7, #4 */
/* @0x25b198 str r11, [sp] */
/* @0x25b19c add r2, pc, r2 */
/* @0x25b1a0 mov r3, #74 */
/* @0x25b1a4 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x25b1a8 str r7, [r8, #0x2c] */
/* @0x25b1ac str r7, [r8, #0x24] */
/* @0x25b1b0 cmp r0, r11 */
/* @0x25b1b4 str r0, [r8, #0x4] */
/* @0x25b1b8 beq 0x25b4f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3cc> */
/* @0x25b1bc add r4, r0, r9, lsl #4 */
/* @0x25b1c0 mov r1, r0 */
/* @0x25b1c4 lsl r2, r10, #4 */
/* @0x25b1c8 mov r0, r4 */
/* @0x25b1cc bl 0xb6694 <memmove@plt> */
/* @0x25b1d0 ldr r3, [sp, #0x14] */
/* @0x25b1d4 mov r6, #0 */
/* @0x25b1d8 add r11, r3, #12 */
/* @0x25b1dc mov r7, r6 */
/* @0x25b1e0 mov r10, r6 */
/* @0x25b1e4 mov r5, r3 */
/* @0x25b1e8 ldr r4, [r8, #0x4] */
/* @0x25b1ec cmp r4, #0 */
/* @0x25b1f0 beq 0x25b3d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x25b1f4 add r4, r4, r6 */
/* @0x25b1f8 ldr r1, [r4, #0xc] */
/* @0x25b1fc bic r3, r1, #-16777216 */
/* @0x25b200 cmp r3, #1 */
/* @0x25b204 beq 0x25b334 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x25b208 cmp r3, #2 */
/* @0x25b20c bne 0x25b230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25b210 sub r1, r1, #1 */
/* @0x25b214 bic r1, r1, #-16777216 */
/* @0x25b218 bic r1, r1, #3 */
/* @0x25b21c cmp r1, #0 */
/* @0x25b220 beq 0x25b3c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x25b224 mov r3, #5 */
/* @0x25b228 str r10, [r4, #0x8] */
/* @0x25b22c str r3, [r4, #0xc] */
/* @0x25b230 str r10, [r4] */
/* @0x25b234 ldr r3, [r5, #0xc] */
/* @0x25b238 str r3, [r4, #0xc] */
/* @0x25b23c ldr r3, [r5, #0x8] */
/* @0x25b240 str r3, [r4, #0x8] */
/* @0x25b244 ldr r3, [r5, #0xc] */
/* @0x25b248 bic r3, r3, #-16777216 */
/* @0x25b24c cmp r3, #14 */
/* @0x25b250 addls pc, pc, r3, lsl #2 */
/* @0x25b254 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b258 b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25b25c b 0x25b2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x25b260 b 0x25b2cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x25b264 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x25b268 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b26c b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b270 b 0x25b310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x25b274 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x25b278 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b27c b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b280 b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25b284 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b288 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b28c b 0x25b2c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25b290 b 0x25b294 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x25b294 ldr r3, [r11, #-0xc] */
/* @0x25b298 str r3, [r4] */
/* @0x25b29c add r7, r7, #1 */
/* @0x25b2a0 add r11, r11, #16 */
/* @0x25b2a4 cmp r7, r9 */
/* @0x25b2a8 add r6, r6, #16 */
/* @0x25b2ac add r5, r5, #16 */
/* @0x25b2b0 bne 0x25b1e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x25b2b4 add sp, sp, #28 */
/* @0x25b2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25b2bc b 0xd3a34 <_Z15PopContextStackv> */
/* @0x25b2c0 ldm r5, {r1, r3} */
/* @0x25b2c4 stm r4, {r1, r3} */
/* @0x25b2c8 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b2cc ldr r3, [r11, #-0xc] */
/* @0x25b2d0 cmp r3, #0 */
/* @0x25b2d4 str r3, [r4] */
/* @0x25b2d8 beq 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b2dc ldr r0, [r3, #0x8] */
/* @0x25b2e0 ldr r1, [r3] */
/* @0x25b2e4 cmp r0, #0 */
/* @0x25b2e8 streq r4, [r3, #0x8] */
/* @0x25b2ec add r1, r1, #1 */
/* @0x25b2f0 str r1, [r3] */
/* @0x25b2f4 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b2f8 ldr r3, [r11, #-0xc] */
/* @0x25b2fc cmp r3, #0 */
/* @0x25b300 ldrne r1, [r3, #0x4] */
/* @0x25b304 addne r1, r1, #1 */
/* @0x25b308 strne r1, [r3, #0x4] */
/* @0x25b30c b 0x25b298 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x25b310 ldr r3, [r11, #-0xc] */
/* @0x25b314 str r3, [r4] */
/* @0x25b318 ldr r3, [r11, #-0xc] */
/* @0x25b31c cmp r3, #0 */
/* @0x25b320 beq 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b324 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x25b328 ldr r1, [r11, #-0xc] */
/* @0x25b32c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x25b330 b 0x25b29c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x25b334 ldr r3, [r4] */
/* @0x25b338 cmp r3, #0 */
/* @0x25b33c beq 0x25b364 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x25b340 str r3, [sp, #0xc] */
/* @0x25b344 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b348 ldr r3, [sp, #0xc] */
/* @0x25b34c ldr r1, [r3, #0x4] */
/* @0x25b350 sub r1, r1, #1 */
/* @0x25b354 str r1, [r3, #0x4] */
/* @0x25b358 cmp r1, #0 */
/* @0x25b35c beq 0x25b36c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x25b360 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b364 str r10, [r4] */
/* @0x25b368 b 0x25b230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x25b36c ldr r0, [r3] */
/* @0x25b370 str r1, [sp, #0x10] */
/* @0x25b374 str r3, [sp, #0xc] */
/* @0x25b378 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b37c ldr r3, [sp, #0xc] */
/* @0x25b380 ldr r1, [sp, #0x10] */
/* @0x25b384 str r1, [r3] */
/* @0x25b388 str r1, [r3, #0x8] */
/* @0x25b38c str r3, [sp, #0xc] */
/* @0x25b390 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b394 ldr r3, [sp, #0xc] */
/* @0x25b398 ldr r1, [r3, #0x4] */
/* @0x25b39c sub r1, r1, #1 */
/* @0x25b3a0 str r1, [r3, #0x4] */
/* @0x25b3a4 cmp r1, #0 */
/* @0x25b3a8 beq 0x25b3ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x25b3ac str r3, [sp, #0xc] */
/* @0x25b3b0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b3b4 ldr r3, [sp, #0xc] */
/* @0x25b3b8 mov r0, r3 */
/* @0x25b3bc bl 0x27d1d0 <_ZdlPv> */
/* @0x25b3c0 b 0x25b360 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x25b3c4 mov r0, r4 */
/* @0x25b3c8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25b3cc b 0x25b224 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x25b3d0 mov r0, r8 */
/* @0x25b3d4 mov r1, r7 */
/* @0x25b3d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25b3dc mov r4, r0 */
/* @0x25b3e0 b 0x25b1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x25b3e4 add sp, sp, #28 */
/* @0x25b3e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25b3ec ldr r0, [r3] */
/* @0x25b3f0 str r1, [sp, #0x10] */
/* @0x25b3f4 str r3, [sp, #0xc] */
/* @0x25b3f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b3fc ldr r3, [sp, #0xc] */
/* @0x25b400 ldr r1, [sp, #0x10] */
/* @0x25b404 str r1, [r3] */
/* @0x25b408 str r1, [r3, #0x8] */
/* @0x25b40c str r3, [sp, #0xc] */
/* @0x25b410 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b414 ldr r3, [sp, #0xc] */
/* @0x25b418 ldr r1, [r3, #0x4] */
/* @0x25b41c sub r1, r1, #1 */
/* @0x25b420 str r1, [r3, #0x4] */
/* @0x25b424 cmp r1, #0 */
/* @0x25b428 beq 0x25b458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x330> */
/* @0x25b42c str r3, [sp, #0xc] */
/* @0x25b430 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b434 ldr r3, [sp, #0xc] */
/* @0x25b438 mov r0, r3 */
/* @0x25b43c bl 0x27d1d0 <_ZdlPv> */
/* @0x25b440 ldr r3, [sp, #0xc] */
/* @0x25b444 b 0x25b3ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x25b448 mov r0, r1 */
/* @0x25b44c mov r1, #1 */
/* @0x25b450 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25b454 b 0x25b150 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x25b458 ldr r0, [r3] */
/* @0x25b45c str r1, [sp, #0x10] */
/* @0x25b460 str r3, [sp, #0xc] */
/* @0x25b464 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b468 ldr r3, [sp, #0xc] */
/* @0x25b46c ldr r1, [sp, #0x10] */
/* @0x25b470 str r1, [r3] */
/* @0x25b474 str r1, [r3, #0x8] */
/* @0x25b478 str r3, [sp, #0xc] */
/* @0x25b47c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x25b480 ldr r3, [sp, #0xc] */
/* @0x25b484 ldr r1, [r3, #0x4] */
/* @0x25b488 sub r1, r1, #1 */
/* @0x25b48c str r1, [r3, #0x4] */
/* @0x25b490 cmp r1, #0 */
/* @0x25b494 beq 0x25b4b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x38c> */
/* @0x25b498 str r3, [sp, #0xc] */
/* @0x25b49c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25b4a0 ldr r3, [sp, #0xc] */
/* @0x25b4a4 mov r0, r3 */
/* @0x25b4a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x25b4ac ldr r3, [sp, #0xc] */
/* @0x25b4b0 b 0x25b42c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x304> */
/* @0x25b4b4 ldr r0, [r3] */
/* @0x25b4b8 str r1, [sp, #0x10] */
/* @0x25b4bc str r3, [sp, #0xc] */
/* @0x25b4c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x25b4c4 ldr r3, [sp, #0xc] */
/* @0x25b4c8 ldr r1, [sp, #0x10] */
/* @0x25b4cc mov r0, r3 */
/* @0x25b4d0 str r1, [r3] */
/* @0x25b4d4 str r1, [r3, #0x8] */
/* @0x25b4d8 str r3, [sp, #0xc] */
/* @0x25b4dc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x25b4e0 ldr r3, [sp, #0xc] */
/* @0x25b4e4 mov r0, r3 */
/* @0x25b4e8 bl 0x27d1d0 <_ZdlPv> */
/* @0x25b4ec ldr r3, [sp, #0xc] */
/* @0x25b4f0 b 0x25b498 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x370> */
/* @0x25b4f4 mov r1, r9 */
/* @0x25b4f8 mov r0, r8 */
/* @0x25b4fc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25b500 ldr r1, [r8, #0x4] */
/* @0x25b504 cmp r1, #0 */
/* @0x25b508 mov r4, r0 */
/* @0x25b50c bne 0x25b1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x25b510 mov r0, r8 */
/* @0x25b514 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25b518 mov r1, r0 */
/* @0x25b51c b 0x25b1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x25b520 muleq sp, r4, lr */

/* ── FUNC 0x25b524 · anon_25b524 · size=10860 · insn=2715 */
/* @0x25b524 ldrb r3, [r0] */
/* @0x25b528 cmp r3, #128 */
/* @0x25b52c bhi 0x25b56c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x444> */
/* @0x25b530 cmp r3, #126 */
/* @0x25b534 bhs 0x25b57c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x454> */
/* @0x25b538 cmp r3, #4 */
/* @0x25b53c bxlo lr */
/* @0x25b540 cmp r3, #5 */
/* @0x25b544 bhi 0x25b5b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x488> */
/* @0x25b548 cmp r1, #0 */
/* @0x25b54c bxeq lr */
/* @0x25b550 ldr r2, [pc, #0x64] */
/* @0x25b554 ldr r2, [pc, r2] */
/* @0x25b558 ldrb r3, [r2, r3] */
/* @0x25b55c add r0, r0, r3 */
/* @0x25b560 ldrb r3, [r0] */
/* @0x25b564 cmp r3, #128 */
/* @0x25b568 bls 0x25b530 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x408> */
/* @0x25b56c sub r2, r3, #141 */
/* @0x25b570 cmp r2, #4 */
/* @0x25b574 bxhi lr */
/* @0x25b578 b 0x25b550 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x428> */
/* @0x25b57c cmp r1, #0 */
/* @0x25b580 bxeq lr */
/* @0x25b584 ldrb r2, [r0, #0x1] */
/* @0x25b588 ldrb r3, [r0, #0x2] */
/* @0x25b58c orr r3, r3, r2, lsl #8 */
/* @0x25b590 ldrb r3, [r0, r3]! */
/* @0x25b594 cmp r3, #119 */
/* @0x25b598 beq 0x25b584 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x45c> */
/* @0x25b59c ldr r2, [pc, #0x1c] */
/* @0x25b5a0 ldr r2, [pc, r2] */
/* @0x25b5a4 ldrb r3, [r2, r3] */
/* @0x25b5a8 add r0, r0, r3 */
/* @0x25b5ac b 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25b5b0 cmp r3, #118 */
/* @0x25b5b4 beq 0x25b550 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x428> */
/* @0x25b5b8 bx lr */
/* @0x25b5bc andseq r6, r9, r8, lsl #5 */
/* @0x25b5c0 andseq r6, r9, r12, lsr r2 */
/* @0x25b5c4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25b5c8 mov r9, r3 */
/* @0x25b5cc ldrb r3, [r0, #0x3] */
/* @0x25b5d0 sub sp, sp, #28 */
/* @0x25b5d4 ldr r6, [pc, #0x5c8] */
/* @0x25b5d8 add r4, r0, #3 */
/* @0x25b5dc mov r7, r1 */
/* @0x25b5e0 mov r5, #0 */
/* @0x25b5e4 mvn r10, #0 */
/* @0x25b5e8 mov r11, #1 */
/* @0x25b5ec mov r8, r2 */
/* @0x25b5f0 add r6, pc, r6 */
/* @0x25b5f4 add r2, sp, #16 */
/* @0x25b5f8 str r2, [sp, #0xc] */
/* @0x25b5fc cmp r3, #161 */
/* @0x25b600 addls pc, pc, r3, lsl #2 */
/* @0x25b604 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b608 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b60c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b610 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b614 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b618 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b61c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b620 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b624 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b628 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b62c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b630 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b634 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b638 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b63c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b640 b 0x25b8d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7ac> */
/* @0x25b644 b 0x25b8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x78c> */
/* @0x25b648 b 0x25b8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x78c> */
/* @0x25b64c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b650 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b654 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b658 b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b65c b 0x25b8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x790> */
/* @0x25b660 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b664 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b668 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b66c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b670 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b674 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b678 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b67c b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b680 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b684 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b688 b 0x25bb34 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa0c> */
/* @0x25b68c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b690 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b694 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b698 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b69c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6a8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6ac b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b6b0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6b4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6b8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6bc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6c8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6cc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6d8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6dc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6e0 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b6e4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6e8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6ec b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6f8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b6fc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b700 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b704 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b708 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b70c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b710 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b714 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b718 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b71c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b720 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b724 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b728 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b72c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b730 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b734 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b738 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b73c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b740 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b744 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b748 b 0x25bad4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9ac> */
/* @0x25b74c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b750 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b754 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b758 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b75c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b760 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b764 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b768 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b76c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b770 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b774 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b778 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b77c b 0x25bb08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9e0> */
/* @0x25b780 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b784 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b788 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b78c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b790 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b794 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b798 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b79c b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a0 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a4 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7a8 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7ac b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b0 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b4 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7b8 b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7bc b 0x25bb6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa44> */
/* @0x25b7c0 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7c4 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7c8 b 0x25ba5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x934> */
/* @0x25b7cc b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7d8 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7dc b 0x25b990 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x868> */
/* @0x25b7e0 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b7e4 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b7e8 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b7ec b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f0 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f4 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b7f8 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b7fc b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b800 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b804 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b808 b 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b80c b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b810 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b814 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b818 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b81c b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b820 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b824 b 0x25b938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x810> */
/* @0x25b828 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b82c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b830 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b834 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b838 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b83c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b840 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b844 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b848 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b84c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b850 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b854 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b858 b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b85c b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b860 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b864 b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b868 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b86c b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b870 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b874 b 0x25b91c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7f4> */
/* @0x25b878 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b87c b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b880 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b884 b 0x25b8f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7cc> */
/* @0x25b888 b 0x25b8e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7b8> */
/* @0x25b88c b 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b890 ldrb r2, [r4, #0x1] */
/* @0x25b894 ldrb r3, [r4, #0x2] */
/* @0x25b898 orr r3, r3, r2, lsl #8 */
/* @0x25b89c ldrb r3, [r4, r3]! */
/* @0x25b8a0 cmp r3, #119 */
/* @0x25b8a4 beq 0x25b890 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x768> */
/* @0x25b8a8 ldrb r3, [r4, #0x3] */
/* @0x25b8ac add r4, r4, #3 */
/* @0x25b8b0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8b4 add r4, r4, #2 */
/* @0x25b8b8 ldrb r3, [r4, #0x1] */
/* @0x25b8bc add r5, r5, #1 */
/* @0x25b8c0 add r4, r4, #1 */
/* @0x25b8c4 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8c8 mvn r0, #0 */
/* @0x25b8cc add sp, sp, #28 */
/* @0x25b8d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25b8d4 mvn r0, #1 */
/* @0x25b8d8 add sp, sp, #28 */
/* @0x25b8dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25b8e0 ldr r2, [pc, #0x2c0] */
/* @0x25b8e4 ldr r2, [r6, r2] */
/* @0x25b8e8 ldrb r3, [r2, r3] */
/* @0x25b8ec ldrb r3, [r4, r3]! */
/* @0x25b8f0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b8f4 cmp r10, #0 */
/* @0x25b8f8 blt 0x25bb8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa64> */
/* @0x25b8fc cmp r10, r5 */
/* @0x25b900 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b904 cmp r3, #119 */
/* @0x25b908 bne 0x25bb9c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa74> */
/* @0x25b90c ldrb r3, [r4, #0x3] */
/* @0x25b910 mov r5, #0 */
/* @0x25b914 add r4, r4, #3 */
/* @0x25b918 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b91c ldr r1, [pc, #0x284] */
/* @0x25b920 ldrb r2, [r4, #0x1] */
/* @0x25b924 ldr r1, [r6, r1] */
/* @0x25b928 ldrb r3, [r1, r3] */
/* @0x25b92c add r3, r2, r3 */
/* @0x25b930 ldrb r3, [r4, r3]! */
/* @0x25b934 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b938 cmp r3, #133 */
/* @0x25b93c ldr r3, [sp, #0x40] */
/* @0x25b940 mov r1, r7 */
/* @0x25b944 mov r2, r8 */
/* @0x25b948 moveq r0, #2 */
/* @0x25b94c movne r0, #0 */
/* @0x25b950 str r3, [sp] */
/* @0x25b954 add r0, r4, r0 */
/* @0x25b958 mov r3, r9 */
/* @0x25b95c bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x25b960 cmp r0, #0 */
/* @0x25b964 blt 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25b968 add r5, r5, r0 */
/* @0x25b96c ldrb r2, [r4, #0x1] */
/* @0x25b970 ldrb r3, [r4, #0x2] */
/* @0x25b974 orr r3, r3, r2, lsl #8 */
/* @0x25b978 ldrb r3, [r4, r3]! */
/* @0x25b97c cmp r3, #119 */
/* @0x25b980 beq 0x25b96c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x844> */
/* @0x25b984 ldrb r3, [r4, #0x3] */
/* @0x25b988 add r4, r4, #3 */
/* @0x25b98c b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25b990 cmp r8, #0 */
/* @0x25b994 beq 0x25bb94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa6c> */
/* @0x25b998 ldrb r12, [r4, #0x1] */
/* @0x25b99c ldrb r2, [r4, #0x2] */
/* @0x25b9a0 ldr r3, [r9, #0x14] */
/* @0x25b9a4 orr r12, r2, r12, lsl #8 */
/* @0x25b9a8 add r12, r3, r12 */
/* @0x25b9ac mov r3, r12 */
/* @0x25b9b0 ldrb r1, [r3, #0x1] */
/* @0x25b9b4 ldrb r2, [r3, #0x2] */
/* @0x25b9b8 orr r2, r2, r1, lsl #8 */
/* @0x25b9bc ldrb r2, [r3, r2]! */
/* @0x25b9c0 cmp r2, #119 */
/* @0x25b9c4 beq 0x25b9b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x888> */
/* @0x25b9c8 cmp r4, r3 */
/* @0x25b9cc movhs r3, #0 */
/* @0x25b9d0 movlo r3, #1 */
/* @0x25b9d4 cmp r4, r12 */
/* @0x25b9d8 movls r3, #0 */
/* @0x25b9dc cmp r3, #0 */
/* @0x25b9e0 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b9e4 ldr r2, [sp, #0x40] */
/* @0x25b9e8 cmp r2, #0 */
/* @0x25b9ec beq 0x25ba1c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8f4> */
/* @0x25b9f0 ldr r3, [r2, #0x4] */
/* @0x25b9f4 cmp r12, r3 */
/* @0x25b9f8 beq 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25b9fc mov r3, r2 */
/* @0x25ba00 b 0x25ba10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8e8> */
/* @0x25ba04 ldr r2, [r3, #0x4] */
/* @0x25ba08 cmp r12, r2 */
/* @0x25ba0c beq 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25ba10 ldr r3, [r3] */
/* @0x25ba14 cmp r3, #0 */
/* @0x25ba18 bne 0x25ba04 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x8dc> */
/* @0x25ba1c ldr lr, [sp, #0x40] */
/* @0x25ba20 add r3, sp, #16 */
/* @0x25ba24 add r0, r12, #2 */
/* @0x25ba28 str r3, [sp] */
/* @0x25ba2c mov r1, r7 */
/* @0x25ba30 mov r2, r8 */
/* @0x25ba34 mov r3, r9 */
/* @0x25ba38 str lr, [sp, #0x10] */
/* @0x25ba3c str r12, [sp, #0x14] */
/* @0x25ba40 bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c> */
/* @0x25ba44 cmp r0, #0 */
/* @0x25ba48 blt 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25ba4c ldrb r3, [r4, #0x3] */
/* @0x25ba50 add r5, r5, r0 */
/* @0x25ba54 add r4, r4, #3 */
/* @0x25ba58 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25ba5c cmp r3, #112 */
/* @0x25ba60 addne r4, r4, #33 */
/* @0x25ba64 ldrbeq r2, [r4, #0x1] */
/* @0x25ba68 ldrbeq r3, [r4, #0x2] */
/* @0x25ba6c orreq r3, r3, r2, lsl #8 */
/* @0x25ba70 addeq r4, r4, r3 */
/* @0x25ba74 ldrb r3, [r4] */
/* @0x25ba78 sub r2, r3, #98 */
/* @0x25ba7c uxtb r2, r2 */
/* @0x25ba80 cmp r2, #11 */
/* @0x25ba84 bhi 0x25bb84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa5c> */
/* @0x25ba88 lsl r2, r11, r2 */
/* @0x25ba8c movw r1, #0x73f */
/* @0x25ba90 and r1, r2, r1 */
/* @0x25ba94 cmp r1, #0 */
/* @0x25ba98 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25ba9c tst r2, #2240 */
/* @0x25baa0 beq 0x25bb84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa5c> */
/* @0x25baa4 ldrb r0, [r4, #0x1] */
/* @0x25baa8 ldrb r1, [r4, #0x3] */
/* @0x25baac ldrb r3, [r4, #0x2] */
/* @0x25bab0 ldrb r2, [r4, #0x4] */
/* @0x25bab4 orr r3, r3, r0, lsl #8 */
/* @0x25bab8 orr r2, r2, r1, lsl #8 */
/* @0x25babc cmp r3, r2 */
/* @0x25bac0 bne 0x25b8c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a0> */
/* @0x25bac4 add r5, r5, r3 */
/* @0x25bac8 add r4, r4, #5 */
/* @0x25bacc ldrb r3, [r4] */
/* @0x25bad0 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bad4 ldrb r1, [r4, #0x1] */
/* @0x25bad8 cmp r7, #0 */
/* @0x25badc ldrb r3, [r4, #0x2] */
/* @0x25bae0 add r2, r4, #4 */
/* @0x25bae4 orr r3, r3, r1, lsl #8 */
/* @0x25bae8 add r5, r5, r3 */
/* @0x25baec beq 0x25bafc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x9d4> */
/* @0x25baf0 ldrb r3, [r4, #0x3] */
/* @0x25baf4 cmp r3, #191 */
/* @0x25baf8 bhi 0x25bb50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa28> */
/* @0x25bafc ldrb r3, [r4, #0x4] */
/* @0x25bb00 mov r4, r2 */
/* @0x25bb04 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb08 ldrb r1, [r4, #0x3] */
/* @0x25bb0c ldrb r2, [r4, #0x1] */
/* @0x25bb10 sub r1, r1, #15 */
/* @0x25bb14 ldrb r3, [r4, #0x2] */
/* @0x25bb18 cmp r1, #1 */
/* @0x25bb1c addls r4, r4, #2 */
/* @0x25bb20 orr r3, r3, r2, lsl #8 */
/* @0x25bb24 add r5, r3, r5 */
/* @0x25bb28 add r4, r4, #4 */
/* @0x25bb2c ldrb r3, [r4] */
/* @0x25bb30 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb34 cmp r7, #0 */
/* @0x25bb38 add r5, r5, #1 */
/* @0x25bb3c add r2, r4, #2 */
/* @0x25bb40 beq 0x25bb78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa50> */
/* @0x25bb44 ldrb r3, [r4, #0x1] */
/* @0x25bb48 cmp r3, #191 */
/* @0x25bb4c bls 0x25bb78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa50> */
/* @0x25bb50 ldr r1, [pc, #0x54] */
/* @0x25bb54 and r3, r3, #63 */
/* @0x25bb58 ldr r1, [r6, r1] */
/* @0x25bb5c ldrb r3, [r1, r3] */
/* @0x25bb60 add r4, r2, r3 */
/* @0x25bb64 ldrb r3, [r2, r3] */
/* @0x25bb68 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb6c mvn r0, #3 */
/* @0x25bb70 add sp, sp, #28 */
/* @0x25bb74 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25bb78 ldrb r3, [r4, #0x2] */
/* @0x25bb7c mov r4, r2 */
/* @0x25bb80 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb84 add r5, r5, #1 */
/* @0x25bb88 b 0x25b5fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x4d4> */
/* @0x25bb8c mov r10, r5 */
/* @0x25bb90 b 0x25b904 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7dc> */
/* @0x25bb94 mvn r0, #2 */
/* @0x25bb98 b 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25bb9c mov r0, r10 */
/* @0x25bba0 b 0x25b8cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x7a4> */
/* @0x25bba4 andseq r6, r9, r0, ror #12 */
/* @0x25bba8 .word 0xfffffb8c */
/* @0x25bbac .word 0xfffffb90 */
/* @0x25bbb0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25bbb4 mov r8, r3 */
/* @0x25bbb8 ldr r10, [pc, #0x6a0] */
/* @0x25bbbc sub sp, sp, #28 */
/* @0x25bbc0 ldr lr, [pc, #0x69c] */
/* @0x25bbc4 mov r7, r1 */
/* @0x25bbc8 add r10, pc, r10 */
/* @0x25bbcc ldrb r12, [r0] */
/* @0x25bbd0 mov r1, #1 */
/* @0x25bbd4 mov r9, r2 */
/* @0x25bbd8 ldr r6, [r10, lr] */
/* @0x25bbdc ldrb r3, [r6, r12] */
/* @0x25bbe0 add r0, r0, r3 */
/* @0x25bbe4 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25bbe8 cmp r0, r7 */
/* @0x25bbec mov r4, r0 */
/* @0x25bbf0 addlo r1, sp, #16 */
/* @0x25bbf4 strlo r10, [sp, #0xc] */
/* @0x25bbf8 strlo r1, [sp, #0x8] */
/* @0x25bbfc bhs 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bc00 ldrb r3, [r4] */
/* @0x25bc04 cmp r3, #125 */
/* @0x25bc08 beq 0x25bd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbf8> */
/* @0x25bc0c cmp r3, #117 */
/* @0x25bc10 beq 0x25bd7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc54> */
/* @0x25bc14 add r2, r3, #110 */
/* @0x25bc18 uxtb r2, r2 */
/* @0x25bc1c cmp r3, #161 */
/* @0x25bc20 cmpne r2, #2 */
/* @0x25bc24 bls 0x25bd58 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc30> */
/* @0x25bc28 add r2, r3, #120 */
/* @0x25bc2c uxtb r2, r2 */
/* @0x25bc30 cmp r2, #3 */
/* @0x25bc34 bls 0x25bd3c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc14> */
/* @0x25bc38 add r2, r3, #127 */
/* @0x25bc3c uxtb r2, r2 */
/* @0x25bc40 cmp r2, #6 */
/* @0x25bc44 bhi 0x25bf20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdf8> */
/* @0x25bc48 ldrb r5, [r4, #0x1] */
/* @0x25bc4c ldrb r11, [r4, #0x2] */
/* @0x25bc50 orrs r2, r11, r5, lsl #8 */
/* @0x25bc54 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bc58 cmp r3, #135 */
/* @0x25bc5c beq 0x25c190 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1068> */
/* @0x25bc60 ldrb r10, [r4, r2] */
/* @0x25bc64 mov r3, r6 */
/* @0x25bc68 lsl r5, r5, #8 */
/* @0x25bc6c mov r6, r10 */
/* @0x25bc70 mov r0, #0 */
/* @0x25bc74 mov r10, r3 */
/* @0x25bc78 b 0x25bca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb78> */
/* @0x25bc7c cmp r6, #119 */
/* @0x25bc80 orr r11, r5, r11 */
/* @0x25bc84 add r4, r4, r11 */
/* @0x25bc88 bne 0x25bce0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbb8> */
/* @0x25bc8c ldrb r5, [r4, #0x1] */
/* @0x25bc90 ldrb r11, [r4, #0x2] */
/* @0x25bc94 lsl r5, r5, #8 */
/* @0x25bc98 orr r3, r5, r11 */
/* @0x25bc9c ldrb r6, [r4, r3] */
/* @0x25bca0 cmp r0, #0 */
/* @0x25bca4 mov r0, #1 */
/* @0x25bca8 bne 0x25bc7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb54> */
/* @0x25bcac ldr r2, [sp, #0x40] */
/* @0x25bcb0 mov r0, r4 */
/* @0x25bcb4 mov r1, r7 */
/* @0x25bcb8 mov r3, r8 */
/* @0x25bcbc orr r11, r5, r11 */
/* @0x25bcc0 str r2, [sp] */
/* @0x25bcc4 mov r2, r9 */
/* @0x25bcc8 bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88> */
/* @0x25bccc add r4, r4, r11 */
/* @0x25bcd0 adds r0, r0, #0 */
/* @0x25bcd4 movne r0, #1 */
/* @0x25bcd8 cmp r6, #119 */
/* @0x25bcdc beq 0x25bc8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb64> */
/* @0x25bce0 cmp r0, #0 */
/* @0x25bce4 mov r3, r10 */
/* @0x25bce8 mov r10, r6 */
/* @0x25bcec mov r6, r3 */
/* @0x25bcf0 beq 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bcf4 mov r12, r10 */
/* @0x25bcf8 ldrb r0, [r6, r12] */
/* @0x25bcfc mov r1, #1 */
/* @0x25bd00 add r0, r4, r0 */
/* @0x25bd04 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25bd08 cmp r7, r0 */
/* @0x25bd0c mov r4, r0 */
/* @0x25bd10 bhi 0x25bc00 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xad8> */
/* @0x25bd14 mov r0, #1 */
/* @0x25bd18 add sp, sp, #28 */
/* @0x25bd1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25bd20 ldrb r2, [r4, #0x1] */
/* @0x25bd24 ldrb r3, [r4, #0x2] */
/* @0x25bd28 orr r3, r3, r2, lsl #8 */
/* @0x25bd2c ldrb r12, [r4, r3]! */
/* @0x25bd30 cmp r12, #119 */
/* @0x25bd34 beq 0x25bd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbf8> */
/* @0x25bd38 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd3c ldrb r2, [r4, #0x1] */
/* @0x25bd40 ldrb r3, [r4, #0x2] */
/* @0x25bd44 orr r3, r3, r2, lsl #8 */
/* @0x25bd48 ldrb r12, [r4, r3]! */
/* @0x25bd4c cmp r12, #119 */
/* @0x25bd50 beq 0x25bd3c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc14> */
/* @0x25bd54 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd58 ldrb r3, [r6, r3] */
/* @0x25bd5c add r4, r4, r3 */
/* @0x25bd60 ldrb r2, [r4, #0x1] */
/* @0x25bd64 ldrb r3, [r4, #0x2] */
/* @0x25bd68 orr r3, r3, r2, lsl #8 */
/* @0x25bd6c ldrb r12, [r4, r3]! */
/* @0x25bd70 cmp r12, #119 */
/* @0x25bd74 beq 0x25bd60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xc38> */
/* @0x25bd78 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25bd7c ldrb r11, [r4, #0x1] */
/* @0x25bd80 ldr r12, [r8, #0x10] */
/* @0x25bd84 ldrb r2, [r4, #0x2] */
/* @0x25bd88 ldr r3, [r8, #0x14] */
/* @0x25bd8c cmp r12, #0 */
/* @0x25bd90 orr r11, r2, r11, lsl #8 */
/* @0x25bd94 add r11, r3, r11 */
/* @0x25bd98 beq 0x25beb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd88> */
/* @0x25bd9c ldr r5, [r8, #0x20] */
/* @0x25bda0 cmp r12, r5 */
/* @0x25bda4 bhs 0x25bde8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcc0> */
/* @0x25bda8 ldrb r1, [r12] */
/* @0x25bdac add r0, r4, #1 */
/* @0x25bdb0 ldrb r2, [r12, #0x1] */
/* @0x25bdb4 rsb r3, r3, r0 */
/* @0x25bdb8 orr r2, r2, r1, lsl #8 */
/* @0x25bdbc cmp r2, r3 */
/* @0x25bdc0 bne 0x25bddc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcb4> */
/* @0x25bdc4 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bdc8 ldrb r1, [r12] */
/* @0x25bdcc ldrb r2, [r12, #0x1] */
/* @0x25bdd0 orr r2, r2, r1, lsl #8 */
/* @0x25bdd4 cmp r2, r3 */
/* @0x25bdd8 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bddc add r12, r12, #2 */
/* @0x25bde0 cmp r12, r5 */
/* @0x25bde4 blo 0x25bdc8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xca0> */
/* @0x25bde8 ldrb r2, [r11, #0x1] */
/* @0x25bdec ldrb r1, [r11, #0x2] */
/* @0x25bdf0 orrs r3, r1, r2, lsl #8 */
/* @0x25bdf4 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25bdf8 mov r3, r11 */
/* @0x25bdfc b 0x25be08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xce0> */
/* @0x25be00 ldrb r2, [r3, #0x1] */
/* @0x25be04 ldrb r1, [r3, #0x2] */
/* @0x25be08 orr r2, r1, r2, lsl #8 */
/* @0x25be0c ldrb r2, [r3, r2]! */
/* @0x25be10 cmp r2, #119 */
/* @0x25be14 beq 0x25be00 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcd8> */
/* @0x25be18 cmp r3, r4 */
/* @0x25be1c cmphs r4, r11 */
/* @0x25be20 bhs 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be24 ldr r1, [sp, #0x40] */
/* @0x25be28 cmp r1, #0 */
/* @0x25be2c beq 0x25be5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd34> */
/* @0x25be30 ldr r3, [r1, #0x4] */
/* @0x25be34 cmp r3, r11 */
/* @0x25be38 beq 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be3c mov r3, r1 */
/* @0x25be40 b 0x25be50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd28> */
/* @0x25be44 ldr r2, [r3, #0x4] */
/* @0x25be48 cmp r2, r11 */
/* @0x25be4c beq 0x25bea8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd80> */
/* @0x25be50 ldr r3, [r3] */
/* @0x25be54 cmp r3, #0 */
/* @0x25be58 bne 0x25be44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd1c> */
/* @0x25be5c ldr r2, [sp, #0x40] */
/* @0x25be60 add r5, sp, #16 */
/* @0x25be64 str r11, [sp, #0x14] */
/* @0x25be68 str r2, [sp, #0x10] */
/* @0x25be6c b 0x25be88 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd60> */
/* @0x25be70 ldrb r2, [r11, #0x1] */
/* @0x25be74 ldrb r3, [r11, #0x2] */
/* @0x25be78 orr r3, r3, r2, lsl #8 */
/* @0x25be7c ldrb r0, [r11, r3]! */
/* @0x25be80 cmp r0, #119 */
/* @0x25be84 bne 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25be88 str r5, [sp] */
/* @0x25be8c mov r0, r11 */
/* @0x25be90 mov r1, r7 */
/* @0x25be94 mov r2, r9 */
/* @0x25be98 mov r3, r8 */
/* @0x25be9c bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88> */
/* @0x25bea0 cmp r0, #0 */
/* @0x25bea4 beq 0x25be70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd48> */
/* @0x25bea8 mov r12, #117 */
/* @0x25beac b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25beb0 ldrb r2, [r11, #0x1] */
/* @0x25beb4 ldrb r1, [r11, #0x2] */
/* @0x25beb8 b 0x25bdf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xcd0> */
/* @0x25bebc ldrb r1, [r4, #0x1] */
/* @0x25bec0 ldrb r2, [r4, #0x2] */
/* @0x25bec4 orr r2, r2, r1, lsl #8 */
/* @0x25bec8 add r4, r4, r2 */
/* @0x25becc mov r2, r4 */
/* @0x25bed0 ldrb r0, [r2] */
/* @0x25bed4 sub r0, r0, #98 */
/* @0x25bed8 uxtb r0, r0 */
/* @0x25bedc cmp r0, #11 */
/* @0x25bee0 bhi 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bee4 mov r1, #1 */
/* @0x25bee8 lsl r0, r1, r0 */
/* @0x25beec movw r1, #0x533 */
/* @0x25bef0 and r1, r0, r1 */
/* @0x25bef4 cmp r1, #0 */
/* @0x25bef8 bne 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25befc tst r0, #2240 */
/* @0x25bf00 beq 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf04 ldrb r1, [r2, #0x1] */
/* @0x25bf08 ldrb r2, [r2, #0x2] */
/* @0x25bf0c orrs r2, r2, r1, lsl #8 */
/* @0x25bf10 beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf14 mov r0, #0 */
/* @0x25bf18 add sp, sp, #28 */
/* @0x25bf1c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25bf20 cmp r3, #140 */
/* @0x25bf24 beq 0x25c248 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1120> */
/* @0x25bf28 sub r2, r3, #6 */
/* @0x25bf2c cmp r2, #149 */
/* @0x25bf30 addls pc, pc, r2, lsl #2 */
/* @0x25bf34 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf38 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf3c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf40 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf44 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf48 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf4c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf50 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf54 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf58 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf5c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf60 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf64 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf68 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf6c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf70 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf74 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf78 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf7c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf80 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf84 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf88 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf8c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf90 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25bf94 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf98 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bf9c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfa0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfa4 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfa8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfac b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfb0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfb4 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfb8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfbc b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfc0 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfc4 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfc8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfcc b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfd0 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfd4 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bfd8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfdc b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfe0 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfe4 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bfe8 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bfec b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25bff0 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bff4 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25bff8 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25bffc b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c000 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c004 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c008 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c00c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c010 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c014 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c018 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c01c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c020 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c024 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c028 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c02c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c030 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c034 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c038 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c03c b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c040 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c044 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c048 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c04c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c050 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c054 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c058 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c05c b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c060 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c064 b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c068 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c06c b 0x25c230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1108> */
/* @0x25c070 b 0x25c1f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10d0> */
/* @0x25c074 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c078 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c07c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c080 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c084 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c088 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c08c b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c090 b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c094 b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c098 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c09c b 0x25bf14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xdec> */
/* @0x25c0a0 b 0x25c1ac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1084> */
/* @0x25c0a4 b 0x25c1dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10b4> */
/* @0x25c0a8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0ac b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0b8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0bc b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0c8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0cc b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0d8 b 0x25c1d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10ac> */
/* @0x25c0dc b 0x25c1d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10ac> */
/* @0x25c0e0 b 0x25bebc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xd94> */
/* @0x25c0e4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0e8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0ec b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f0 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f4 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0f8 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c0fc b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c100 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c104 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c108 b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c10c b 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c110 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c114 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c118 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c11c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c120 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c124 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c128 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c12c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c130 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c134 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c138 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c13c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c140 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c144 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c148 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c14c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c150 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c154 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c158 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c15c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c160 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c164 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c168 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c16c b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c170 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c174 b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c178 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c17c b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c180 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c184 b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c188 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c18c b 0x25c1c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x109c> */
/* @0x25c190 ldrb r12, [r4, r2] */
/* @0x25c194 add r2, r4, r2 */
/* @0x25c198 cmp r12, #119 */
/* @0x25c19c mov r10, r12 */
/* @0x25c1a0 movne r4, r2 */
/* @0x25c1a4 bne 0x25bcf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbcc> */
/* @0x25c1a8 b 0x25bc64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb3c> */
/* @0x25c1ac ldrb r2, [r4, #0x1] */
/* @0x25c1b0 sub r2, r2, #15 */
/* @0x25c1b4 cmp r2, #1 */
/* @0x25c1b8 bls 0x25c1ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10c4> */
/* @0x25c1bc mov r12, r3 */
/* @0x25c1c0 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1c4 ldrb r2, [r4, #0x1] */
/* @0x25c1c8 mov r12, r3 */
/* @0x25c1cc add r4, r4, r2 */
/* @0x25c1d0 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1d4 add r2, r4, #33 */
/* @0x25c1d8 b 0x25bed0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xda8> */
/* @0x25c1dc ldrb r2, [r4, #0x3] */
/* @0x25c1e0 sub r2, r2, #15 */
/* @0x25c1e4 cmp r2, #1 */
/* @0x25c1e8 bhi 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c1ec add r4, r4, #2 */
/* @0x25c1f0 mov r12, r3 */
/* @0x25c1f4 b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c1f8 cmp r9, #0 */
/* @0x25c1fc beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c200 ldrb r2, [r4, #0x3] */
/* @0x25c204 cmp r2, #191 */
/* @0x25c208 bls 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c20c ldr r1, [pc, #0x54] */
/* @0x25c210 mov r12, r3 */
/* @0x25c214 and r2, r2, #63 */
/* @0x25c218 mov r3, r1 */
/* @0x25c21c ldr r1, [sp, #0xc] */
/* @0x25c220 ldr r3, [r1, r3] */
/* @0x25c224 ldrb r3, [r3, r2] */
/* @0x25c228 add r4, r4, r3 */
/* @0x25c22c b 0x25bcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbd0> */
/* @0x25c230 cmp r9, #0 */
/* @0x25c234 beq 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c238 ldrb r2, [r4, #0x1] */
/* @0x25c23c cmp r2, #191 */
/* @0x25c240 bhi 0x25c20c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x10e4> */
/* @0x25c244 b 0x25c1bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1094> */
/* @0x25c248 ldrb r5, [r4, #0x1] */
/* @0x25c24c ldrb r11, [r4, #0x2] */
/* @0x25c250 orrs r3, r11, r5, lsl #8 */
/* @0x25c254 beq 0x25bd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xbec> */
/* @0x25c258 ldrb r10, [r4, r3] */
/* @0x25c25c b 0x25bc64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xb3c> */
/* @0x25c260 andseq r6, r9, r8, lsl #1 */
/* @0x25c264 .word 0xfffffb8c */
/* @0x25c268 .word 0xfffffb90 */
/* @0x25c26c ldrb r3, [r0, #0x2] */
/* @0x25c270 add r2, r0, #2 */
/* @0x25c274 ldrb r12, [r0, #0x1] */
/* @0x25c278 cmp r3, #0 */
/* @0x25c27c bne 0x25c2b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1188> */
/* @0x25c280 b 0x25c2dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11b4> */
/* @0x25c284 cmp r3, #91 */
/* @0x25c288 beq 0x25c2d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11a8> */
/* @0x25c28c cmp r3, #93 */
/* @0x25c290 beq 0x25c2dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11b4> */
/* @0x25c294 ldrb r0, [r2, #0x1] */
/* @0x25c298 cmp r12, r3 */
/* @0x25c29c beq 0x25c2e4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11bc> */
/* @0x25c2a0 cmp r0, #0 */
/* @0x25c2a4 add r2, r2, #1 */
/* @0x25c2a8 bxeq lr */
/* @0x25c2ac mov r3, r0 */
/* @0x25c2b0 cmp r3, #92 */
/* @0x25c2b4 bne 0x25c284 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x115c> */
/* @0x25c2b8 ldrb r0, [r2, #0x1] */
/* @0x25c2bc sub r3, r0, #92 */
/* @0x25c2c0 cmp r3, #1 */
/* @0x25c2c4 ldrbls r0, [r2, #0x2] */
/* @0x25c2c8 addls r2, r2, #1 */
/* @0x25c2cc b 0x25c2a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1178> */
/* @0x25c2d0 ldrb r0, [r2, #0x1] */
/* @0x25c2d4 cmp r0, r12 */
/* @0x25c2d8 bne 0x25c298 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1170> */
/* @0x25c2dc mov r0, #0 */
/* @0x25c2e0 bx lr */
/* @0x25c2e4 cmp r0, #93 */
/* @0x25c2e8 bne 0x25c2a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1178> */
/* @0x25c2ec str r2, [r1] */
/* @0x25c2f0 mov r0, #1 */
/* @0x25c2f4 bx lr */
/* @0x25c2f8 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x25c2fc mov r4, r0 */
/* @0x25c300 ldr r7, [sp, #0x20] */
/* @0x25c304 ldr r8, [r3, #0x10] */
/* @0x25c308 ldr r6, [r3, #0x20] */
/* @0x25c30c add r8, r8, r7 */
/* @0x25c310 ldrb r12, [r4] */
/* @0x25c314 cmp r12, #0 */
/* @0x25c318 beq 0x25c4b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1388> */
/* @0x25c31c cmp r12, #117 */
/* @0x25c320 beq 0x25c540 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1418> */
/* @0x25c324 cmp r12, #112 */
/* @0x25c328 beq 0x25c52c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1404> */
/* @0x25c32c sub r5, r12, #85 */
/* @0x25c330 cmp r5, #70 */
/* @0x25c334 addls pc, pc, r5, lsl #2 */
/* @0x25c338 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c33c b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c340 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c344 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c348 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c34c b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c350 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c354 b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c358 b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c35c b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c360 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c364 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c368 b 0x25c518 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13f0> */
/* @0x25c36c b 0x25c504 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13dc> */
/* @0x25c370 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c374 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c378 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c37c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c380 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c384 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c388 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c38c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c390 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c394 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c398 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c39c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3a8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3ac b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3b8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3bc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3c8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3cc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3d8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3dc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3e8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3ec b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f0 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f4 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3f8 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c3fc b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c400 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c404 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c408 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c40c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c410 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c414 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c418 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c41c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c420 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c424 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c428 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c42c b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c430 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c434 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c438 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c43c b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c440 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c444 b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c448 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c44c b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c450 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c454 b 0x25c458 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1330> */
/* @0x25c458 ldrb r5, [r4, #0x1] */
/* @0x25c45c add r4, r4, r5 */
/* @0x25c460 ldr r5, [pc, #0x16c] */
/* @0x25c464 cmp r2, #0 */
/* @0x25c468 ldr r5, [pc, r5] */
/* @0x25c46c ldrb r5, [r5, r12] */
/* @0x25c470 add r4, r4, r5 */
/* @0x25c474 beq 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c478 sub r12, r12, #29 */
/* @0x25c47c cmp r12, #55 */
/* @0x25c480 bhi 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c484 ldrb r12, [r4, #-0x1] */
/* @0x25c488 cmp r12, #191 */
/* @0x25c48c bls 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c490 ldr r5, [pc, #0x140] */
/* @0x25c494 and r12, r12, #63 */
/* @0x25c498 ldr r5, [pc, r5] */
/* @0x25c49c ldrb r12, [r5, r12] */
/* @0x25c4a0 add r4, r4, r12 */
/* @0x25c4a4 ldrb r12, [r4] */
/* @0x25c4a8 cmp r12, #0 */
/* @0x25c4ac bne 0x25c31c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11f4> */
/* @0x25c4b0 cmp r8, r6 */
/* @0x25c4b4 bhs 0x25c4fc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x13d4> */
/* @0x25c4b8 add r2, r8, #2 */
/* @0x25c4bc uxtb r5, r1 */
/* @0x25c4c0 mov r0, r2 */
/* @0x25c4c4 ldrb r4, [r0, #-0x2] */
/* @0x25c4c8 add r0, r0, #2 */
/* @0x25c4cc ldrb r12, [r8, #0x1] */
/* @0x25c4d0 orr r12, r12, r4, lsl #8 */
/* @0x25c4d4 add r4, r12, r1 */
/* @0x25c4d8 add r12, r5, r12 */
/* @0x25c4dc asr r4, r4, #8 */
/* @0x25c4e0 strb r4, [r0, #-0x4] */
/* @0x25c4e4 strb r12, [r8, #0x1] */
/* @0x25c4e8 mov r8, r2 */
/* @0x25c4ec ldr r12, [r3, #0x20] */
/* @0x25c4f0 cmp r12, r2 */
/* @0x25c4f4 add r2, r2, #2 */
/* @0x25c4f8 bhi 0x25c4c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x139c> */
/* @0x25c4fc pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x25c500 bx lr */
/* @0x25c504 ldrb r5, [r4, #0x3] */
/* @0x25c508 sub r5, r5, #15 */
/* @0x25c50c cmp r5, #1 */
/* @0x25c510 addls r4, r4, #2 */
/* @0x25c514 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c518 ldrb r5, [r4, #0x1] */
/* @0x25c51c sub r5, r5, #15 */
/* @0x25c520 cmp r5, #1 */
/* @0x25c524 addls r4, r4, #2 */
/* @0x25c528 b 0x25c460 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1338> */
/* @0x25c52c ldrb r5, [r4, #0x1] */
/* @0x25c530 ldrb r12, [r4, #0x2] */
/* @0x25c534 orr r12, r12, r5, lsl #8 */
/* @0x25c538 add r4, r4, r12 */
/* @0x25c53c b 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c540 cmp r8, r6 */
/* @0x25c544 mov r12, r8 */
/* @0x25c548 ldrhs r9, [r3, #0x14] */
/* @0x25c54c bhs 0x25c598 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1470> */
/* @0x25c550 ldrb r11, [r8] */
/* @0x25c554 add r10, r4, #1 */
/* @0x25c558 ldrb r5, [r8, #0x1] */
/* @0x25c55c ldr r9, [r3, #0x14] */
/* @0x25c560 orr r5, r5, r11, lsl #8 */
/* @0x25c564 add r5, r9, r5 */
/* @0x25c568 cmp r10, r5 */
/* @0x25c56c bne 0x25c58c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1464> */
/* @0x25c570 b 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c574 ldrb r11, [r12] */
/* @0x25c578 ldrb r5, [r12, #0x1] */
/* @0x25c57c orr r5, r5, r11, lsl #8 */
/* @0x25c580 add r5, r9, r5 */
/* @0x25c584 cmp r10, r5 */
/* @0x25c588 beq 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c58c add r12, r12, #2 */
/* @0x25c590 cmp r12, r6 */
/* @0x25c594 blo 0x25c574 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x144c> */
/* @0x25c598 ldrb r5, [r4, #0x1] */
/* @0x25c59c ldrb r12, [r4, #0x2] */
/* @0x25c5a0 orr r12, r12, r5, lsl #8 */
/* @0x25c5a4 add r9, r9, r12 */
/* @0x25c5a8 cmp r0, r9 */
/* @0x25c5ac bhi 0x25c5cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14a4> */
/* @0x25c5b0 add r12, r12, r1 */
/* @0x25c5b4 strb r12, [r4, #0x2] */
/* @0x25c5b8 asr r12, r12, #8 */
/* @0x25c5bc strb r12, [r4, #0x1] */
/* @0x25c5c0 ldr r8, [r3, #0x10] */
/* @0x25c5c4 ldr r6, [r3, #0x20] */
/* @0x25c5c8 add r8, r8, r7 */
/* @0x25c5cc add r4, r4, #3 */
/* @0x25c5d0 b 0x25c310 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11e8> */
/* @0x25c5d4 andseq r5, r9, r4, ror r3 */
/* @0x25c5d8 andseq r5, r9, r8, asr #6 */
/* @0x25c5dc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x25c5e0 mov r4, r0 */
/* @0x25c5e4 ldr r5, [pc, #0x198] */
/* @0x25c5e8 mov r8, r3 */
/* @0x25c5ec ldrb r0, [r0] */
/* @0x25c5f0 add r10, r3, #1 */
/* @0x25c5f4 ldr r5, [pc, r5] */
/* @0x25c5f8 mov r6, r1 */
/* @0x25c5fc mov r7, r2 */
/* @0x25c600 mov r9, #1 */
/* @0x25c604 b 0x25c6a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1578> */
/* @0x25c608 add r2, r12, #118 */
/* @0x25c60c sub r1, r12, #133 */
/* @0x25c610 uxtb r2, r2 */
/* @0x25c614 cmp r2, #1 */
/* @0x25c618 cmphi r1, #1 */
/* @0x25c61c bls 0x25c6e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x15c0> */
/* @0x25c620 cmp r12, #125 */
/* @0x25c624 cmpne r12, #135 */
/* @0x25c628 movne r1, #0 */
/* @0x25c62c moveq r1, #1 */
/* @0x25c630 beq 0x25c734 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x160c> */
/* @0x25c634 sub r2, r12, #129 */
/* @0x25c638 cmp r2, #1 */
/* @0x25c63c bls 0x25c758 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1630> */
/* @0x25c640 sub r2, r12, #85 */
/* @0x25c644 cmp r12, #94 */
/* @0x25c648 cmpne r2, #1 */
/* @0x25c64c movhi r2, #0 */
/* @0x25c650 movls r2, #1 */
/* @0x25c654 bhi 0x25c71c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x15f4> */
/* @0x25c658 ldrb r3, [r0, #0x1] */
/* @0x25c65c cmp r3, #13 */
/* @0x25c660 bne 0x25c774 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x164c> */
/* @0x25c664 ldr r3, [r7, #0x50] */
/* @0x25c668 ands r3, r6, r3 */
/* @0x25c66c bne 0x25c774 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x164c> */
/* @0x25c670 cmp r8, #0 */
/* @0x25c674 bgt 0x25c77c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1654> */
/* @0x25c678 ldr r2, [r7, #0x70] */
/* @0x25c67c cmp r2, #0 */
/* @0x25c680 bne 0x25c77c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1654> */
/* @0x25c684 ldrb r2, [r4, #0x1] */
/* @0x25c688 ldrb r3, [r4, #0x2] */
/* @0x25c68c orr r3, r3, r2, lsl #8 */
/* @0x25c690 ldrb r3, [r4, r3]! */
/* @0x25c694 cmp r3, #119 */
/* @0x25c698 bne 0x25c750 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1628> */
/* @0x25c69c mov r0, r3 */
/* @0x25c6a0 ldrb r0, [r5, r0] */
/* @0x25c6a4 mov r1, #0 */
/* @0x25c6a8 add r0, r4, r0 */
/* @0x25c6ac bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c6b0 ldrb r12, [r0] */
/* @0x25c6b4 add r2, r12, #120 */
/* @0x25c6b8 sub r1, r12, #131 */
/* @0x25c6bc uxtb r2, r2 */
/* @0x25c6c0 cmp r2, #1 */
/* @0x25c6c4 cmphi r1, #1 */
/* @0x25c6c8 bhi 0x25c608 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14e0> */
/* @0x25c6cc mov r1, r6 */
/* @0x25c6d0 mov r2, r7 */
/* @0x25c6d4 mov r3, r8 */
/* @0x25c6d8 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4> */
/* @0x25c6dc cmp r0, #0 */
/* @0x25c6e0 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c> */
/* @0x25c6e4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c6e8 ldrb r1, [r0, #0x3] */
/* @0x25c6ec mov r3, r8 */
/* @0x25c6f0 ldrb r2, [r0, #0x4] */
/* @0x25c6f4 orr r2, r2, r1, lsl #8 */
/* @0x25c6f8 cmp r2, #31 */
/* @0x25c6fc lslle r1, r9, r2 */
/* @0x25c700 mov r2, r7 */
/* @0x25c704 movgt r1, #1 */
/* @0x25c708 orr r1, r1, r6 */
/* @0x25c70c bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4> */
/* @0x25c710 cmp r0, #0 */
/* @0x25c714 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c> */
/* @0x25c718 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c71c sub r3, r12, #1 */
/* @0x25c720 cmp r12, #27 */
/* @0x25c724 cmpne r3, #1 */
/* @0x25c728 bls 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c> */
/* @0x25c72c mov r0, r2 */
/* @0x25c730 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c734 mov r1, r6 */
/* @0x25c738 mov r2, r7 */
/* @0x25c73c mov r3, r8 */
/* @0x25c740 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4> */
/* @0x25c744 cmp r0, #0 */
/* @0x25c748 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c> */
/* @0x25c74c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c750 mov r0, #1 */
/* @0x25c754 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c758 mov r1, r6 */
/* @0x25c75c mov r2, r7 */
/* @0x25c760 mov r3, r10 */
/* @0x25c764 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4> */
/* @0x25c768 cmp r0, #0 */
/* @0x25c76c bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c> */
/* @0x25c770 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c774 mov r0, r1 */
/* @0x25c778 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c77c mov r0, r3 */
/* @0x25c780 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25c784 andseq r5, r9, r8, ror #3 */
/* @0x25c788 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25c78c sub sp, sp, #20 */
/* @0x25c790 ldr r8, [pc, #0x1ec] */
/* @0x25c794 mov r11, r0 */
/* @0x25c798 mov r7, r3 */
/* @0x25c79c ldrb r0, [r0] */
/* @0x25c7a0 add r3, r3, #1 */
/* @0x25c7a4 ldr r9, [sp, #0x38] */
/* @0x25c7a8 str r3, [sp, #0xc] */
/* @0x25c7ac ldr r8, [pc, r8] */
/* @0x25c7b0 mov r5, r1 */
/* @0x25c7b4 mov r6, r2 */
/* @0x25c7b8 mov r10, #1 */
/* @0x25c7bc b 0x25c840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1718> */
/* @0x25c7c0 sub r1, r3, #133 */
/* @0x25c7c4 sub r2, r3, #138 */
/* @0x25c7c8 cmp r2, #1 */
/* @0x25c7cc cmphi r1, #1 */
/* @0x25c7d0 bls 0x25c894 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x176c> */
/* @0x25c7d4 cmp r3, #125 */
/* @0x25c7d8 beq 0x25c950 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1828> */
/* @0x25c7dc sub r1, r3, #129 */
/* @0x25c7e0 cmp r1, #1 */
/* @0x25c7e4 bls 0x25c958 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1830> */
/* @0x25c7e8 sub r1, r3, #85 */
/* @0x25c7ec cmp r3, #94 */
/* @0x25c7f0 cmpne r1, #1 */
/* @0x25c7f4 bhi 0x25c938 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1810> */
/* @0x25c7f8 ldrb r3, [r0, #0x1] */
/* @0x25c7fc cmp r3, #12 */
/* @0x25c800 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c804 ldr r3, [r6, #0x50] */
/* @0x25c808 ands r3, r5, r3 */
/* @0x25c80c bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c810 cmp r7, #0 */
/* @0x25c814 bgt 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c818 ldr r2, [r6, #0x70] */
/* @0x25c81c orrs r2, r9, r2 */
/* @0x25c820 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c824 ldrb r2, [r11, #0x1] */
/* @0x25c828 ldrb r3, [r11, #0x2] */
/* @0x25c82c orr r3, r3, r2, lsl #8 */
/* @0x25c830 ldrb r3, [r11, r3]! */
/* @0x25c834 cmp r3, #119 */
/* @0x25c838 bne 0x25c978 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1850> */
/* @0x25c83c mov r0, r3 */
/* @0x25c840 ldrb r0, [r8, r0] */
/* @0x25c844 mov r1, #0 */
/* @0x25c848 add r0, r11, r0 */
/* @0x25c84c bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c850 ldrb r3, [r0] */
/* @0x25c854 cmp r3, #135 */
/* @0x25c858 beq 0x25c8b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1790> */
/* @0x25c85c sub r1, r3, #136 */
/* @0x25c860 sub r2, r3, #131 */
/* @0x25c864 cmp r2, #1 */
/* @0x25c868 cmphi r1, #1 */
/* @0x25c86c strls r9, [sp] */
/* @0x25c870 bhi 0x25c7c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1698> */
/* @0x25c874 mov r1, r5 */
/* @0x25c878 mov r2, r6 */
/* @0x25c87c mov r3, r7 */
/* @0x25c880 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c884 cmp r0, #0 */
/* @0x25c888 bne 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c88c add sp, sp, #20 */
/* @0x25c890 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25c894 ldrb r2, [r0, #0x3] */
/* @0x25c898 ldrb r3, [r0, #0x4] */
/* @0x25c89c str r9, [sp] */
/* @0x25c8a0 orr r3, r3, r2, lsl #8 */
/* @0x25c8a4 cmp r3, #31 */
/* @0x25c8a8 lslle r1, r10, r3 */
/* @0x25c8ac movgt r1, #1 */
/* @0x25c8b0 orr r1, r1, r5 */
/* @0x25c8b4 b 0x25c878 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1750> */
/* @0x25c8b8 ldrb r3, [r0, #0x3] */
/* @0x25c8bc cmp r3, #118 */
/* @0x25c8c0 addne r4, r0, #3 */
/* @0x25c8c4 addeq r4, r0, #9 */
/* @0x25c8c8 ldrbeq r3, [r0, #0x9] */
/* @0x25c8cc add r3, r3, #115 */
/* @0x25c8d0 uxtb r3, r3 */
/* @0x25c8d4 cmp r3, #16 */
/* @0x25c8d8 bhi 0x25c8ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x17c4> */
/* @0x25c8dc mov r2, #31 */
/* @0x25c8e0 movt r2, #0x1 */
/* @0x25c8e4 ands r2, r2, r10, lsl r3 */
/* @0x25c8e8 bne 0x25c944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x181c> */
/* @0x25c8ec str r10, [sp] */
/* @0x25c8f0 mov r0, r4 */
/* @0x25c8f4 mov r1, r5 */
/* @0x25c8f8 mov r2, r6 */
/* @0x25c8fc mov r3, r7 */
/* @0x25c900 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c904 cmp r0, #0 */
/* @0x25c908 beq 0x25c88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1764> */
/* @0x25c90c ldrb r2, [r4, #0x1] */
/* @0x25c910 ldrb r3, [r4, #0x2] */
/* @0x25c914 orr r3, r3, r2, lsl #8 */
/* @0x25c918 ldrb r3, [r4, r3]! */
/* @0x25c91c cmp r3, #119 */
/* @0x25c920 beq 0x25c90c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x17e4> */
/* @0x25c924 add r0, r4, #3 */
/* @0x25c928 mov r1, #0 */
/* @0x25c92c bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c930 ldrb r3, [r0] */
/* @0x25c934 b 0x25c85c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1734> */
/* @0x25c938 sub r3, r3, #27 */
/* @0x25c93c cmp r3, #1 */
/* @0x25c940 bls 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c944 mov r0, #0 */
/* @0x25c948 add sp, sp, #20 */
/* @0x25c94c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25c950 str r10, [sp] */
/* @0x25c954 b 0x25c874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x174c> */
/* @0x25c958 str r9, [sp] */
/* @0x25c95c mov r1, r5 */
/* @0x25c960 mov r2, r6 */
/* @0x25c964 ldr r3, [sp, #0xc] */
/* @0x25c968 bl 0x25c788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1660> */
/* @0x25c96c cmp r0, #0 */
/* @0x25c970 bne 0x25c824 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x16fc> */
/* @0x25c974 b 0x25c88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1764> */
/* @0x25c978 mov r0, #1 */
/* @0x25c97c add sp, sp, #20 */
/* @0x25c980 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25c984 andseq r5, r9, r0, lsr r0 */
/* @0x25c988 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x25c98c mvn r5, #0 */
/* @0x25c990 sub sp, sp, #12 */
/* @0x25c994 str r5, [r1] */
/* @0x25c998 ldrb r3, [r0] */
/* @0x25c99c add r9, sp, #4 */
/* @0x25c9a0 mov r8, r1 */
/* @0x25c9a4 mov r4, r0 */
/* @0x25c9a8 mov r7, r2 */
/* @0x25c9ac mov r6, #0 */
/* @0x25c9b0 add r2, r3, #118 */
/* @0x25c9b4 add r3, r3, #123 */
/* @0x25c9b8 mov r1, #1 */
/* @0x25c9bc uxtb r2, r2 */
/* @0x25c9c0 uxtb r3, r3 */
/* @0x25c9c4 cmp r3, r1 */
/* @0x25c9c8 cmphi r2, r1 */
/* @0x25c9cc movhi r0, #3 */
/* @0x25c9d0 movls r0, #5 */
/* @0x25c9d4 add r0, r4, r0 */
/* @0x25c9d8 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc> */
/* @0x25c9dc ldrb r2, [r0] */
/* @0x25c9e0 sub r3, r2, #29 */
/* @0x25c9e4 cmp r3, #110 */
/* @0x25c9e8 addls pc, pc, r3, lsl #2 */
/* @0x25c9ec b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25c9f0 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc> */
/* @0x25c9f4 b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88> */
/* @0x25c9f8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25c9fc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca00 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca04 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca08 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc> */
/* @0x25ca0c b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc> */
/* @0x25ca10 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca14 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca18 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca1c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca20 b 0x25cbf0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ac8> */
/* @0x25ca24 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca28 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc> */
/* @0x25ca2c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca30 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca34 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca38 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca3c b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88> */
/* @0x25ca40 b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88> */
/* @0x25ca44 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca48 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca4c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca50 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca54 b 0x25cbac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a84> */
/* @0x25ca58 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca5c b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88> */
/* @0x25ca60 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca64 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca68 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca6c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca70 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca74 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca78 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca7c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca80 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca84 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca88 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca8c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca90 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca94 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca98 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25ca9c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caa0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caa4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caa8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caac b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cab0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cab4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cab8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cabc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cac0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cac4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cac8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cacc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cad0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cad4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cad8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cadc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cae0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cae4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cae8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caec b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caf0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caf4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25caf8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cafc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb00 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb04 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb08 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb0c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb10 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb14 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb18 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb1c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb20 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb24 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb28 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb2c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb30 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb34 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb38 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb3c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb40 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb44 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb48 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb4c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb50 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb54 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb58 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb5c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb60 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb64 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb68 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb6c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb70 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb74 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb78 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb7c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb80 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb84 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb88 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb8c b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb90 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb94 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cb98 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cb9c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cba0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cba4 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cba8 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8> */
/* @0x25cbac add r0, r0, #2 */
/* @0x25cbb0 cmp r7, #0 */
/* @0x25cbb4 beq 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cbb8 cmn r5, #1 */
/* @0x25cbbc beq 0x25cc54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b2c> */
/* @0x25cbc0 ldrb r3, [r0, #0x1] */
/* @0x25cbc4 cmp r3, r6 */
/* @0x25cbc8 bne 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cbcc ldrb r2, [r4, #0x1] */
/* @0x25cbd0 ldrb r3, [r4, #0x2] */
/* @0x25cbd4 orr r3, r3, r2, lsl #8 */
/* @0x25cbd8 ldrb r3, [r4, r3]! */
/* @0x25cbdc cmp r3, #119 */
/* @0x25cbe0 beq 0x25c9b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1888> */
/* @0x25cbe4 mov r0, r6 */
/* @0x25cbe8 str r5, [r8] */
/* @0x25cbec b 0x25cc4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b24> */
/* @0x25cbf0 add r0, r0, #2 */
/* @0x25cbf4 cmp r7, #0 */
/* @0x25cbf8 beq 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cbfc cmn r5, #1 */
/* @0x25cc00 bne 0x25cbc0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a98> */
/* @0x25cc04 ldrb r6, [r0, #0x1] */
/* @0x25cc08 mov r5, #0 */
/* @0x25cc0c b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4> */
/* @0x25cc10 subs r3, r2, #125 */
/* @0x25cc14 mov r1, r9 */
/* @0x25cc18 rsbs r2, r3, #0 */
/* @0x25cc1c adcs r2, r2, r3 */
/* @0x25cc20 bl 0x25c988 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1860> */
/* @0x25cc24 ldr r3, [sp, #0x4] */
/* @0x25cc28 cmp r3, #0 */
/* @0x25cc2c blt 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cc30 cmn r5, #1 */
/* @0x25cc34 beq 0x25cc60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b38> */
/* @0x25cc38 cmp r6, r0 */
/* @0x25cc3c bne 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20> */
/* @0x25cc40 cmp r5, r3 */
/* @0x25cc44 beq 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4> */
/* @0x25cc48 mov r0, #0 */
/* @0x25cc4c add sp, sp, #12 */
/* @0x25cc50 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x25cc54 ldrb r6, [r0, #0x1] */
/* @0x25cc58 mov r5, #1 */
/* @0x25cc5c b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4> */
/* @0x25cc60 mov r5, r3 */
/* @0x25cc64 mov r6, r0 */
/* @0x25cc68 b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4> */
/* @0x25cc6c ldr r12, [r3, #0xc] */
/* @0x25cc70 cmp r2, #0 */
/* @0x25cc74 push {r4, r5, r6, r7} */
/* @0x25cc78 ldr r5, [r3, #0x74] */
/* @0x25cc7c ldr r6, [r12, r0, lsl #2] */
/* @0x25cc80 add r12, r5, r6 */
/* @0x25cc84 blt 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c> */
/* @0x25cc88 ldr r0, [sp, #0x10] */
/* @0x25cc8c cmp r0, #0 */
/* @0x25cc90 addeq r0, r1, r2 */
/* @0x25cc94 moveq r2, r1 */
/* @0x25cc98 beq 0x25cd30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c08> */
/* @0x25cc9c cmp r2, #0 */
/* @0x25cca0 beq 0x25cd5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c34> */
/* @0x25cca4 ldr r7, [r3, #0x78] */
/* @0x25cca8 cmp r1, r7 */
/* @0x25ccac bhs 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28> */
/* @0x25ccb0 ldr r4, [r3, #0x38] */
/* @0x25ccb4 ldrb r0, [r5, r6] */
/* @0x25ccb8 ldrb r3, [r1] */
/* @0x25ccbc ldrb r0, [r4, r0] */
/* @0x25ccc0 ldrb r3, [r4, r3] */
/* @0x25ccc4 cmp r0, r3 */
/* @0x25ccc8 bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c> */
/* @0x25cccc add r2, r1, r2 */
/* @0x25ccd0 add r3, r1, #1 */
/* @0x25ccd4 b 0x25ccfc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bd4> */
/* @0x25ccd8 cmp r3, r7 */
/* @0x25ccdc add r3, r3, #1 */
/* @0x25cce0 beq 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28> */
/* @0x25cce4 ldrb r5, [r5] */
/* @0x25cce8 ldrb r0, [r12, #0x1]! */
/* @0x25ccec ldrb r5, [r4, r5] */
/* @0x25ccf0 ldrb r6, [r4, r0] */
/* @0x25ccf4 cmp r6, r5 */
/* @0x25ccf8 bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c> */
/* @0x25ccfc cmp r3, r2 */
/* @0x25cd00 mov r5, r3 */
/* @0x25cd04 bne 0x25ccd8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bb0> */
/* @0x25cd08 rsb r0, r1, r3 */
/* @0x25cd0c pop {r4, r5, r6, r7} */
/* @0x25cd10 bx lr */
/* @0x25cd14 ldr r4, [r3, #0x78] */
/* @0x25cd18 cmp r2, r4 */
/* @0x25cd1c bhs 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28> */
/* @0x25cd20 ldrb r5, [r12], #1 */
/* @0x25cd24 ldrb r4, [r2], #1 */
/* @0x25cd28 cmp r5, r4 */
/* @0x25cd2c bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c> */
/* @0x25cd30 cmp r2, r0 */
/* @0x25cd34 bne 0x25cd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bec> */
/* @0x25cd38 rsb r0, r1, r2 */
/* @0x25cd3c pop {r4, r5, r6, r7} */
/* @0x25cd40 bx lr */
/* @0x25cd44 mvn r0, #0 */
/* @0x25cd48 pop {r4, r5, r6, r7} */
/* @0x25cd4c bx lr */
/* @0x25cd50 mvn r0, #1 */
/* @0x25cd54 pop {r4, r5, r6, r7} */
/* @0x25cd58 bx lr */
/* @0x25cd5c mov r0, r2 */
/* @0x25cd60 b 0x25cd48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c20> */
/* @0x25cd64 ldr r3, [r0, #0x3c] */
/* @0x25cd68 push {r4, r5, r6, lr} */
/* @0x25cd6c cmp r3, #409600 */
/* @0x25cd70 mov r4, r0 */
/* @0x25cd74 blt 0x25cd80 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c58> */
/* @0x25cd78 mov r0, #72 */
/* @0x25cd7c pop {r4, r5, r6, pc} */
/* @0x25cd80 lsl r5, r3, #1 */
/* @0x25cd84 cmp r5, #409600 */
/* @0x25cd88 movge r5, #409600 */
/* @0x25cd8c rsb r3, r3, r5 */
/* @0x25cd90 cmp r3, #99 */
/* @0x25cd94 ble 0x25cd78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c50> */
/* @0x25cd98 ldr r3, [pc, #0x6c] */
/* @0x25cd9c mov r0, r5 */
/* @0x25cda0 ldr r3, [pc, r3] */
/* @0x25cda4 ldr r3, [r3] */
/* @0x25cda8 blx r3 */
/* @0x25cdac subs r6, r0, #0 */
/* @0x25cdb0 beq 0x25cdf0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cc8> */
/* @0x25cdb4 ldr r2, [r4, #0x3c] */
/* @0x25cdb8 ldr r1, [r4, #0x10] */
/* @0x25cdbc bl 0xb65bc <memcpy@plt> */
/* @0x25cdc0 ldr r2, [r4, #0x3c] */
/* @0x25cdc4 ldr r3, [r4, #0x20] */
/* @0x25cdc8 ldr r0, [r4, #0x10] */
/* @0x25cdcc cmp r2, #4096 */
/* @0x25cdd0 rsb r3, r0, r3 */
/* @0x25cdd4 add r3, r6, r3 */
/* @0x25cdd8 str r3, [r4, #0x20] */
/* @0x25cddc bgt 0x25cdf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cd0> */
/* @0x25cde0 str r6, [r4, #0x10] */
/* @0x25cde4 mov r0, #0 */
/* @0x25cde8 str r5, [r4, #0x3c] */
/* @0x25cdec pop {r4, r5, r6, pc} */
/* @0x25cdf0 mov r0, #21 */
/* @0x25cdf4 pop {r4, r5, r6, pc} */
/* @0x25cdf8 ldr r3, [pc, #0x10] */
/* @0x25cdfc ldr r3, [pc, r3] */
/* @0x25ce00 ldr r3, [r3] */
/* @0x25ce04 blx r3 */
/* @0x25ce08 b 0x25cde0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cb8> */
/* @0x25ce0c andseq r4, r9, r4, asr #20 */
/* @0x25ce10 andseq r3, r9, r12, lsl #17 */
/* @0x25ce14 ldrb r3, [r0, #0x1] */
/* @0x25ce18 add r1, r0, #1 */
/* @0x25ce1c sub r2, r3, #48 */
/* @0x25ce20 cmp r2, #9 */
/* @0x25ce24 bhi 0x25ce40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d18> */
/* @0x25ce28 add r0, r0, #2 */
/* @0x25ce2c mov r1, r0 */
/* @0x25ce30 ldrb r3, [r0], #1 */
/* @0x25ce34 sub r2, r3, #48 */
/* @0x25ce38 cmp r2, #9 */
/* @0x25ce3c bls 0x25ce2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d04> */
/* @0x25ce40 cmp r3, #125 */
/* @0x25ce44 beq 0x25cea4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d7c> */
/* @0x25ce48 cmp r3, #44 */
/* @0x25ce4c beq 0x25ce58 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d30> */
/* @0x25ce50 mov r0, #0 */
/* @0x25ce54 bx lr */
/* @0x25ce58 ldrb r3, [r1, #0x1] */
/* @0x25ce5c cmp r3, #125 */
/* @0x25ce60 beq 0x25cea4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d7c> */
/* @0x25ce64 sub r3, r3, #48 */
/* @0x25ce68 cmp r3, #9 */
/* @0x25ce6c bhi 0x25ce50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d28> */
/* @0x25ce70 ldrb r3, [r1, #0x2] */
/* @0x25ce74 add r1, r1, #2 */
/* @0x25ce78 sub r2, r3, #48 */
/* @0x25ce7c cmp r2, #9 */
/* @0x25ce80 bhi 0x25ce94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d6c> */
/* @0x25ce84 ldrb r3, [r1, #0x1]! */
/* @0x25ce88 sub r2, r3, #48 */
/* @0x25ce8c cmp r2, #9 */
/* @0x25ce90 bls 0x25ce84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d5c> */
/* @0x25ce94 subs r3, r3, #125 */
/* @0x25ce98 rsbs r0, r3, #0 */
/* @0x25ce9c adcs r0, r0, r3 */
/* @0x25cea0 bx lr */
/* @0x25cea4 mov r0, #1 */
/* @0x25cea8 bx lr */
/* @0x25ceac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25ceb0 mov r7, r0 */
/* @0x25ceb4 sub sp, sp, #20 */
/* @0x25ceb8 ldr r0, [r0] */
/* @0x25cebc ldr r6, [sp, #0x38] */
/* @0x25cec0 ldrb r4, [r0, #0x1] */
/* @0x25cec4 ubfx r12, r6, #0xb, #0x1 */
/* @0x25cec8 cmp r4, #191 */
/* @0x25cecc movls r5, #0 */
/* @0x25ced0 andhi r5, r12, #1 */
/* @0x25ced4 cmp r5, #0 */
/* @0x25ced8 addeq r9, r0, #2 */
/* @0x25cedc beq 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25cee0 tst r4, #32 */
/* @0x25cee4 bne 0x25cf54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e2c> */
/* @0x25cee8 ldrb r5, [r0, #0x2] */
/* @0x25ceec and r4, r4, #31 */
/* @0x25cef0 add r9, r0, #3 */
/* @0x25cef4 and r0, r5, #63 */
/* @0x25cef8 orr r4, r0, r4, lsl #6 */
/* @0x25cefc sub r5, r9, #1 */
/* @0x25cf00 cmp r4, #0 */
/* @0x25cf04 mov r11, r5 */
/* @0x25cf08 bne 0x25cf40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e18> */
/* @0x25cf0c mov r8, r4 */
/* @0x25cf10 mov r3, #1 */
/* @0x25cf14 str r3, [r2] */
/* @0x25cf18 tst r6, #536870912 */
/* @0x25cf1c beq 0x25cf2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e04> */
/* @0x25cf20 sub r3, r8, #6 */
/* @0x25cf24 cmp r3, #5 */
/* @0x25cf28 addls r8, r8, #23 */
/* @0x25cf2c str r5, [r7] */
/* @0x25cf30 mov r0, r8 */
/* @0x25cf34 str r4, [r1] */
/* @0x25cf38 add sp, sp, #20 */
/* @0x25cf3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25cf40 sub r10, r4, #48 */
/* @0x25cf44 cmp r10, #74 */
/* @0x25cf48 bls 0x25cf94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e6c> */
/* @0x25cf4c mov r8, #0 */
/* @0x25cf50 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25cf54 tst r4, #16 */
/* @0x25cf58 beq 0x25d0e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1fc0> */
/* @0x25cf5c tst r4, #8 */
/* @0x25cf60 bne 0x25d110 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1fe8> */
/* @0x25cf64 ldrb r8, [r0, #0x4] */
/* @0x25cf68 and r10, r4, #7 */
/* @0x25cf6c ldrb r5, [r0, #0x2] */
/* @0x25cf70 add r9, r0, #5 */
/* @0x25cf74 ldrb r4, [r0, #0x3] */
/* @0x25cf78 and r8, r8, #63 */
/* @0x25cf7c and r5, r5, #63 */
/* @0x25cf80 orr r0, r8, r10, lsl #18 */
/* @0x25cf84 and r4, r4, #63 */
/* @0x25cf88 orr r0, r0, r5, lsl #12 */
/* @0x25cf8c orr r4, r0, r4, lsl #6 */
/* @0x25cf90 b 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25cf94 ldr r8, [pc, #0xa5c] */
/* @0x25cf98 lsl r0, r10, #1 */
/* @0x25cf9c add r8, pc, r8 */
/* @0x25cfa0 ldrsh r8, [r8, r0] */
/* @0x25cfa4 cmp r8, #0 */
/* @0x25cfa8 beq 0x25cfb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e90> */
/* @0x25cfac ble 0x25d4f4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23cc> */
/* @0x25cfb0 mov r4, r8 */
/* @0x25cfb4 b 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25cfb8 cmp r10, #72 */
/* @0x25cfbc addls pc, pc, r10, lsl #2 */
/* @0x25cfc0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cfc4 b 0x25d170 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2048> */
/* @0x25cfc8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfcc b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd0 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd4 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfd8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfdc b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe0 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe4 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfe8 b 0x25d324 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21fc> */
/* @0x25cfec b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cff8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25cffc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d000 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d004 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d008 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d00c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d010 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d014 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d018 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d01c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d020 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d024 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d028 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d02c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d030 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d034 b 0x25d314 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21ec> */
/* @0x25d038 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d03c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d040 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d044 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d048 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d04c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d050 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d054 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d058 b 0x25d4b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x238c> */
/* @0x25d05c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d060 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d064 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d068 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d06c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d070 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d074 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d078 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d07c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d080 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d084 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d088 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d08c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d090 b 0x25d3e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x22b8> */
/* @0x25d094 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d098 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d09c b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0a0 b 0x25d400 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x22d8> */
/* @0x25d0a4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0a8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0ac b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0b0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0b4 b 0x25d314 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21ec> */
/* @0x25d0b8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0bc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0c0 b 0x25d3c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x229c> */
/* @0x25d0c4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0c8 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0cc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d4 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0d8 b 0x25d244 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x211c> */
/* @0x25d0dc b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0e0 b 0x25d4e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23b8> */
/* @0x25d0e4 b 0x25d1cc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20a4> */
/* @0x25d0e8 ldrb r5, [r0, #0x3] */
/* @0x25d0ec lsl r4, r4, #12 */
/* @0x25d0f0 ldrb r8, [r0, #0x2] */
/* @0x25d0f4 add r9, r0, #4 */
/* @0x25d0f8 uxth r4, r4 */
/* @0x25d0fc and r5, r5, #63 */
/* @0x25d100 and r0, r8, #63 */
/* @0x25d104 orr r4, r4, r5 */
/* @0x25d108 orr r4, r4, r0, lsl #6 */
/* @0x25d10c b 0x25cefc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1dd4> */
/* @0x25d110 tst r4, #4 */
/* @0x25d114 beq 0x25d14c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2024> */
/* @0x25d118 ldrb r8, [r0, #0x6] */
/* @0x25d11c and r4, r4, #1 */
/* @0x25d120 ldrb r11, [r0, #0x2] */
/* @0x25d124 add r9, r0, #7 */
/* @0x25d128 ldrb r10, [r0, #0x3] */
/* @0x25d12c and r8, r8, #63 */
/* @0x25d130 orr r8, r8, r4, lsl #30 */
/* @0x25d134 ldrb r5, [r0, #0x4] */
/* @0x25d138 ldrb r4, [r0, #0x5] */
/* @0x25d13c and r11, r11, #63 */
/* @0x25d140 and r10, r10, #63 */
/* @0x25d144 orr r8, r8, r11, lsl #24 */
/* @0x25d148 b 0x25cf7c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e54> */
/* @0x25d14c ldrb r8, [r0, #0x5] */
/* @0x25d150 and r11, r4, #3 */
/* @0x25d154 ldrb r10, [r0, #0x2] */
/* @0x25d158 add r9, r0, #6 */
/* @0x25d15c ldrb r5, [r0, #0x3] */
/* @0x25d160 and r8, r8, #63 */
/* @0x25d164 and r10, r10, #63 */
/* @0x25d168 ldrb r4, [r0, #0x4] */
/* @0x25d16c b 0x25d144 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x201c> */
/* @0x25d170 mov r4, #0 */
/* @0x25d174 ldrb r0, [r11, #0x1] */
/* @0x25d178 sub r3, r0, #48 */
/* @0x25d17c cmp r3, #7 */
/* @0x25d180 bhi 0x25d1a8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2080> */
/* @0x25d184 ldrb r3, [r11, #0x2] */
/* @0x25d188 add r4, r0, r4, lsl #3 */
/* @0x25d18c sub r4, r4, #48 */
/* @0x25d190 add r5, r11, #1 */
/* @0x25d194 sub r3, r3, #48 */
/* @0x25d198 uxtb r0, r3 */
/* @0x25d19c cmp r0, #7 */
/* @0x25d1a0 addls r5, r11, #2 */
/* @0x25d1a4 addls r4, r3, r4, lsl #3 */
/* @0x25d1a8 eor r8, r12, #1 */
/* @0x25d1ac cmp r4, #255 */
/* @0x25d1b0 movls r8, #0 */
/* @0x25d1b4 andhi r8, r8, #1 */
/* @0x25d1b8 cmp r8, #0 */
/* @0x25d1bc movne r3, #51 */
/* @0x25d1c0 movne r8, #0 */
/* @0x25d1c4 strne r3, [r2] */
/* @0x25d1c8 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d1cc ands r8, r6, #33554432 */
/* @0x25d1d0 beq 0x25d540 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2418> */
/* @0x25d1d4 ldr r12, [pc, #0x820] */
/* @0x25d1d8 ldrb r2, [r9] */
/* @0x25d1dc add r12, pc, r12 */
/* @0x25d1e0 add r3, r12, r2 */
/* @0x25d1e4 ldrb r3, [r3, #0x98] */
/* @0x25d1e8 and r3, r3, #8 */
/* @0x25d1ec ands r8, r3, #255 */
/* @0x25d1f0 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d1f4 ldrb r3, [r9, #0x1] */
/* @0x25d1f8 add r12, r12, r3 */
/* @0x25d1fc ldrb r0, [r12, #0x98] */
/* @0x25d200 and r0, r0, #8 */
/* @0x25d204 ands r0, r0, #255 */
/* @0x25d208 beq 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d20c cmp r2, #96 */
/* @0x25d210 bls 0x25d8b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x278c> */
/* @0x25d214 sub r2, r2, #32 */
/* @0x25d218 mov r0, #55 */
/* @0x25d21c cmp r3, #96 */
/* @0x25d220 rsb r2, r0, r2 */
/* @0x25d224 bls 0x25d860 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2738> */
/* @0x25d228 sub r3, r3, #32 */
/* @0x25d22c add r3, r3, r2, lsl #4 */
/* @0x25d230 mov r0, #55 */
/* @0x25d234 rsb r4, r0, r3 */
/* @0x25d238 add r5, r9, #1 */
/* @0x25d23c mov r8, #0 */
/* @0x25d240 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d244 ands r8, r6, #33554432 */
/* @0x25d248 beq 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d24c ldr r10, [pc, #0x7ac] */
/* @0x25d250 ldrb r3, [r9] */
/* @0x25d254 add r10, pc, r10 */
/* @0x25d258 add r3, r10, r3 */
/* @0x25d25c ldrb r3, [r3, #0x98] */
/* @0x25d260 and r3, r3, #8 */
/* @0x25d264 ands r8, r3, #255 */
/* @0x25d268 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d26c ldrb r3, [r9, #0x1] */
/* @0x25d270 add r3, r10, r3 */
/* @0x25d274 ldrb r3, [r3, #0x98] */
/* @0x25d278 and r3, r3, #8 */
/* @0x25d27c ands r3, r3, #255 */
/* @0x25d280 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d284 ldrb r3, [r9, #0x2] */
/* @0x25d288 add r3, r10, r3 */
/* @0x25d28c ldrb r3, [r3, #0x98] */
/* @0x25d290 and r3, r3, #8 */
/* @0x25d294 ands r3, r3, #255 */
/* @0x25d298 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d29c ldrb r3, [r9, #0x3] */
/* @0x25d2a0 add r10, r10, r3 */
/* @0x25d2a4 ldrb r3, [r10, #0x98] */
/* @0x25d2a8 and r3, r3, #8 */
/* @0x25d2ac ands r3, r3, #255 */
/* @0x25d2b0 beq 0x25d684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x255c> */
/* @0x25d2b4 add r9, r9, #3 */
/* @0x25d2b8 mov r4, #0 */
/* @0x25d2bc ldrb r3, [r5, #0x1]! */
/* @0x25d2c0 mov r0, #48 */
/* @0x25d2c4 cmp r3, #96 */
/* @0x25d2c8 sub r8, r3, #32 */
/* @0x25d2cc add r8, r8, r4, lsl #4 */
/* @0x25d2d0 bhi 0x25d858 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2730> */
/* @0x25d2d4 cmp r3, #64 */
/* @0x25d2d8 add r8, r3, r4, lsl #4 */
/* @0x25d2dc bhi 0x25d858 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2730> */
/* @0x25d2e0 cmp r5, r9 */
/* @0x25d2e4 rsb r4, r0, r8 */
/* @0x25d2e8 bne 0x25d2bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2194> */
/* @0x25d2ec cmp r12, #0 */
/* @0x25d2f0 movw r3, #0xffff */
/* @0x25d2f4 movt r3, #0x10 */
/* @0x25d2f8 moveq r3, #255 */
/* @0x25d2fc cmp r3, r4 */
/* @0x25d300 bhs 0x25d9d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28a8> */
/* @0x25d304 mov r3, #76 */
/* @0x25d308 mov r8, #0 */
/* @0x25d30c str r3, [r2] */
/* @0x25d310 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d314 mov r3, #37 */
/* @0x25d318 mov r8, #0 */
/* @0x25d31c str r3, [r2] */
/* @0x25d320 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d324 ldr r0, [sp, #0x3c] */
/* @0x25d328 cmp r0, #0 */
/* @0x25d32c bne 0x25d38c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2264> */
/* @0x25d330 ldrb r0, [r9] */
/* @0x25d334 sub r0, r0, #48 */
/* @0x25d338 uxtb r8, r0 */
/* @0x25d33c cmp r8, #9 */
/* @0x25d340 bhi 0x25d378 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2250> */
/* @0x25d344 movw r9, #0xcccb */
/* @0x25d348 movt r9, #0xccc */
/* @0x25d34c b 0x25d358 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2230> */
/* @0x25d350 cmp r10, r9 */
/* @0x25d354 bgt 0x25d3a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2278> */
/* @0x25d358 add r5, r5, #1 */
/* @0x25d35c add r10, r10, r10, lsl #2 */
/* @0x25d360 ldrb r8, [r5, #0x1] */
/* @0x25d364 add r10, r0, r10, lsl #1 */
/* @0x25d368 sub r0, r8, #48 */
/* @0x25d36c uxtb r8, r0 */
/* @0x25d370 cmp r8, #9 */
/* @0x25d374 bls 0x25d350 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2228> */
/* @0x25d378 cmp r10, #7 */
/* @0x25d37c cmpgt r10, r3 */
/* @0x25d380 rsble r8, r10, #0 */
/* @0x25d384 ble 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d388 mov r5, r11 */
/* @0x25d38c ldrb r4, [r11] */
/* @0x25d390 cmp r4, #55 */
/* @0x25d394 subls r4, r4, #48 */
/* @0x25d398 bls 0x25d174 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x204c> */
/* @0x25d39c b 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d3a0 add r5, r5, #1 */
/* @0x25d3a4 ldrb r3, [r5, #0x1] */
/* @0x25d3a8 sub r3, r3, #48 */
/* @0x25d3ac cmp r3, #9 */
/* @0x25d3b0 bls 0x25d3a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2278> */
/* @0x25d3b4 mov r3, #61 */
/* @0x25d3b8 mov r8, #0 */
/* @0x25d3bc str r3, [r2] */
/* @0x25d3c0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d3c4 ldrb r3, [r9] */
/* @0x25d3c8 cmp r3, #123 */
/* @0x25d3cc beq 0x25d5f0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24c8> */
/* @0x25d3d0 mov r3, #81 */
/* @0x25d3d4 mov r8, #0 */
/* @0x25d3d8 str r3, [r2] */
/* @0x25d3dc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d3e0 ldrb r4, [r9] */
/* @0x25d3e4 cmp r4, #0 */
/* @0x25d3e8 bne 0x25d5d4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24ac> */
/* @0x25d3ec mov r3, #2 */
/* @0x25d3f0 mov r5, r9 */
/* @0x25d3f4 mov r8, r4 */
/* @0x25d3f8 str r3, [r2] */
/* @0x25d3fc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d400 ldr r0, [sp, #0x3c] */
/* @0x25d404 cmp r0, #0 */
/* @0x25d408 bne 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d40c ldrb r8, [r9] */
/* @0x25d410 cmp r8, #60 */
/* @0x25d414 cmpne r8, #39 */
/* @0x25d418 moveq r8, #27 */
/* @0x25d41c beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d420 cmp r8, #123 */
/* @0x25d424 ldrne r11, [sp, #0x3c] */
/* @0x25d428 beq 0x25d7e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26c0> */
/* @0x25d42c cmp r8, #45 */
/* @0x25d430 ldrbeq r8, [r5, #0x2] */
/* @0x25d434 moveq r12, #1 */
/* @0x25d438 streq r12, [sp, #0xc] */
/* @0x25d43c addeq r5, r5, r12 */
/* @0x25d440 sub r12, r8, #48 */
/* @0x25d444 movne r0, #0 */
/* @0x25d448 strne r0, [sp, #0xc] */
/* @0x25d44c uxtb r0, r12 */
/* @0x25d450 cmp r0, #9 */
/* @0x25d454 bhi 0x25d9f0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28c8> */
/* @0x25d458 movw r10, #0xcccb */
/* @0x25d45c mov r0, #0 */
/* @0x25d460 movt r10, #0xccc */
/* @0x25d464 b 0x25d470 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2348> */
/* @0x25d468 cmp r0, r10 */
/* @0x25d46c bgt 0x25d4c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23a0> */
/* @0x25d470 add r5, r5, #1 */
/* @0x25d474 add r0, r0, r0, lsl #2 */
/* @0x25d478 ldrb r8, [r5, #0x1] */
/* @0x25d47c add r0, r12, r0, lsl #1 */
/* @0x25d480 sub r12, r8, #48 */
/* @0x25d484 uxtb r9, r12 */
/* @0x25d488 cmp r9, #9 */
/* @0x25d48c bls 0x25d468 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2340> */
/* @0x25d490 cmp r11, #0 */
/* @0x25d494 beq 0x25d840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2718> */
/* @0x25d498 cmp r8, #125 */
/* @0x25d49c add r5, r5, #1 */
/* @0x25d4a0 beq 0x25d840 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2718> */
/* @0x25d4a4 mov r3, #57 */
/* @0x25d4a8 mov r8, #0 */
/* @0x25d4ac str r3, [r2] */
/* @0x25d4b0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4b4 ands r8, r6, #33554432 */
/* @0x25d4b8 bne 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d4bc mov r3, #37 */
/* @0x25d4c0 str r3, [r2] */
/* @0x25d4c4 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4c8 add r5, r5, #1 */
/* @0x25d4cc ldrb r3, [r5, #0x1] */
/* @0x25d4d0 sub r3, r3, #48 */
/* @0x25d4d4 cmp r3, #9 */
/* @0x25d4d8 bls 0x25d4c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23a0> */
/* @0x25d4dc b 0x25d3b4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x228c> */
/* @0x25d4e0 ands r8, r6, #64 */
/* @0x25d4e4 movne r3, #3 */
/* @0x25d4e8 movne r8, #0 */
/* @0x25d4ec strne r3, [r2] */
/* @0x25d4f0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d4f4 rsb r8, r8, #0 */
/* @0x25d4f8 cmp r8, #12 */
/* @0x25d4fc bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d500 ldrb r3, [r5, #0x1] */
/* @0x25d504 cmp r3, #123 */
/* @0x25d508 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d50c ldrb r3, [r5, #0x2] */
/* @0x25d510 sub r3, r3, #48 */
/* @0x25d514 cmp r3, #9 */
/* @0x25d518 bhi 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d51c add r0, r5, #2 */
/* @0x25d520 str r1, [sp, #0x8] */
/* @0x25d524 str r2, [sp, #0x4] */
/* @0x25d528 bl 0x25ce14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cec> */
/* @0x25d52c ldr r1, [sp, #0x8] */
/* @0x25d530 ldr r2, [sp, #0x4] */
/* @0x25d534 cmp r0, #0 */
/* @0x25d538 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d53c b 0x25d4bc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2394> */
/* @0x25d540 ldrb r3, [r9] */
/* @0x25d544 cmp r3, #123 */
/* @0x25d548 beq 0x25d6e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25b8> */
/* @0x25d54c ldr r2, [pc, #0x4b0] */
/* @0x25d550 add r2, pc, r2 */
/* @0x25d554 add r2, r2, r3 */
/* @0x25d558 ldrb r2, [r2, #0x98] */
/* @0x25d55c and r2, r2, #8 */
/* @0x25d560 ands r2, r2, #255 */
/* @0x25d564 moveq r4, r2 */
/* @0x25d568 moveq r8, r4 */
/* @0x25d56c beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d570 cmp r3, #96 */
/* @0x25d574 bls 0x25d68c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2564> */
/* @0x25d578 sub r3, r3, #32 */
/* @0x25d57c mov r4, #55 */
/* @0x25d580 rsb r4, r4, r3 */
/* @0x25d584 ldr r3, [pc, #0x47c] */
/* @0x25d588 ldrb r2, [r9, #0x1] */
/* @0x25d58c add r3, pc, r3 */
/* @0x25d590 add r3, r3, r2 */
/* @0x25d594 ldrb r3, [r3, #0x98] */
/* @0x25d598 and r3, r3, #8 */
/* @0x25d59c ands r3, r3, #255 */
/* @0x25d5a0 beq 0x25d680 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2558> */
/* @0x25d5a4 cmp r2, #96 */
/* @0x25d5a8 add r5, r9, #1 */
/* @0x25d5ac addhi r4, r2, r4, lsl #4 */
/* @0x25d5b0 subhi r4, r4, #32 */
/* @0x25d5b4 bhi 0x25d69c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2574> */
/* @0x25d5b8 cmp r2, #64 */
/* @0x25d5bc add r4, r2, r4, lsl #4 */
/* @0x25d5c0 movls r3, #48 */
/* @0x25d5c4 bhi 0x25d69c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2574> */
/* @0x25d5c8 rsb r4, r3, r4 */
/* @0x25d5cc mov r8, #0 */
/* @0x25d5d0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d5d4 cmp r4, #127 */
/* @0x25d5d8 bls 0x25d664 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x253c> */
/* @0x25d5dc mov r3, #68 */
/* @0x25d5e0 mov r5, r9 */
/* @0x25d5e4 mov r8, #0 */
/* @0x25d5e8 str r3, [r2] */
/* @0x25d5ec b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d5f0 ldrb r3, [r9, #0x1] */
/* @0x25d5f4 cmp r3, #125 */
/* @0x25d5f8 moveq r3, #86 */
/* @0x25d5fc moveq r8, #0 */
/* @0x25d600 streq r3, [r2] */
/* @0x25d604 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d608 cmp r12, #0 */
/* @0x25d60c add r0, r9, #1 */
/* @0x25d610 beq 0x25d788 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2660> */
/* @0x25d614 movw r10, #0xffff */
/* @0x25d618 mov r4, #0 */
/* @0x25d61c movt r10, #0x10 */
/* @0x25d620 b 0x25d634 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x250c> */
/* @0x25d624 cmp r4, r10 */
/* @0x25d628 bhi 0x25d874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x274c> */
/* @0x25d62c ldrb r3, [r0, #0x1] */
/* @0x25d630 mov r0, r8 */
/* @0x25d634 sub r5, r3, #48 */
/* @0x25d638 add r9, r3, r4, lsl #3 */
/* @0x25d63c cmp r5, #7 */
/* @0x25d640 add r8, r0, #1 */
/* @0x25d644 mov r5, r0 */
/* @0x25d648 bhi 0x25d6a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x257c> */
/* @0x25d64c cmp r3, #48 */
/* @0x25d650 cmpeq r4, #0 */
/* @0x25d654 sub r4, r9, #48 */
/* @0x25d658 bne 0x25d624 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24fc> */
/* @0x25d65c mov r4, #0 */
/* @0x25d660 b 0x25d62c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2504> */
/* @0x25d664 sub r3, r4, #97 */
/* @0x25d668 mov r5, r9 */
/* @0x25d66c cmp r3, #25 */
/* @0x25d670 mov r8, #0 */
/* @0x25d674 subls r4, r4, #32 */
/* @0x25d678 eor r4, r4, #64 */
/* @0x25d67c b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d680 mov r5, r9 */
/* @0x25d684 mov r8, r3 */
/* @0x25d688 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d68c cmp r3, #64 */
/* @0x25d690 movls r4, #48 */
/* @0x25d694 bls 0x25d580 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2458> */
/* @0x25d698 b 0x25d57c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2454> */
/* @0x25d69c mov r3, #55 */
/* @0x25d6a0 b 0x25d5c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x24a0> */
/* @0x25d6a4 cmp r3, #125 */
/* @0x25d6a8 movne r3, #80 */
/* @0x25d6ac movne r8, #0 */
/* @0x25d6b0 strne r3, [r2] */
/* @0x25d6b4 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d6b8 sub r3, r4, #55296 */
/* @0x25d6bc cmp r3, #2048 */
/* @0x25d6c0 movhs r12, #0 */
/* @0x25d6c4 andlo r12, r12, #1 */
/* @0x25d6c8 cmp r12, #0 */
/* @0x25d6cc beq 0x25cf4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1e24> */
/* @0x25d6d0 mov r3, #73 */
/* @0x25d6d4 mov r8, #0 */
/* @0x25d6d8 str r3, [r2] */
/* @0x25d6dc b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d6e0 ldrb r3, [r9, #0x1] */
/* @0x25d6e4 add r5, r9, #1 */
/* @0x25d6e8 cmp r3, #125 */
/* @0x25d6ec beq 0x25d944 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x281c> */
/* @0x25d6f0 cmp r12, #0 */
/* @0x25d6f4 beq 0x25d8c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x279c> */
/* @0x25d6f8 ldr r11, [pc, #0x30c] */
/* @0x25d6fc mov r0, r5 */
/* @0x25d700 mov r4, r8 */
/* @0x25d704 movw r5, #0xffff */
/* @0x25d708 add r11, pc, r11 */
/* @0x25d70c movt r5, #0x10 */
/* @0x25d710 str r5, [sp, #0xc] */
/* @0x25d714 b 0x25d750 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2628> */
/* @0x25d718 cmp r3, #96 */
/* @0x25d71c add r10, r3, r4, lsl #4 */
/* @0x25d720 sub r10, r10, #32 */
/* @0x25d724 mov r5, #48 */
/* @0x25d728 bhi 0x25d780 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2658> */
/* @0x25d72c cmp r3, #64 */
/* @0x25d730 add r10, r3, r4, lsl #4 */
/* @0x25d734 bhi 0x25d780 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2658> */
/* @0x25d738 ldr r3, [sp, #0xc] */
/* @0x25d73c rsb r4, r5, r10 */
/* @0x25d740 cmp r4, r3 */
/* @0x25d744 bhi 0x25d97c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2854> */
/* @0x25d748 ldrb r3, [r0, #0x1] */
/* @0x25d74c mov r0, r9 */
/* @0x25d750 add r8, r11, r3 */
/* @0x25d754 add r9, r0, #1 */
/* @0x25d758 mov r5, r0 */
/* @0x25d75c ldrb r10, [r8, #0x98] */
/* @0x25d760 mov r8, r9 */
/* @0x25d764 tst r10, #8 */
/* @0x25d768 beq 0x25d7d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26a8> */
/* @0x25d76c cmp r3, #48 */
/* @0x25d770 cmpeq r4, #0 */
/* @0x25d774 bne 0x25d718 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25f0> */
/* @0x25d778 mov r4, #0 */
/* @0x25d77c b 0x25d748 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2620> */
/* @0x25d780 mov r5, #55 */
/* @0x25d784 b 0x25d738 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2610> */
/* @0x25d788 mov r4, r12 */
/* @0x25d78c b 0x25d7a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2678> */
/* @0x25d790 cmp r4, #255 */
/* @0x25d794 bhi 0x25d874 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x274c> */
/* @0x25d798 ldrb r3, [r0, #0x1] */
/* @0x25d79c mov r0, r8 */
/* @0x25d7a0 sub r5, r3, #48 */
/* @0x25d7a4 add r9, r3, r4, lsl #3 */
/* @0x25d7a8 cmp r5, #7 */
/* @0x25d7ac add r8, r0, #1 */
/* @0x25d7b0 mov r5, r0 */
/* @0x25d7b4 bhi 0x25d6a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x257c> */
/* @0x25d7b8 cmp r3, #48 */
/* @0x25d7bc cmpeq r4, #0 */
/* @0x25d7c0 sub r4, r9, #48 */
/* @0x25d7c4 bne 0x25d790 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2668> */
/* @0x25d7c8 mov r4, #0 */
/* @0x25d7cc b 0x25d798 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2670> */
/* @0x25d7d0 cmp r3, #125 */
/* @0x25d7d4 movne r3, #79 */
/* @0x25d7d8 movne r8, #0 */
/* @0x25d7dc strne r3, [r2] */
/* @0x25d7e0 bne 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d7e4 b 0x25d6b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2590> */
/* @0x25d7e8 ldrb r10, [r9, #0x1] */
/* @0x25d7ec add r12, r9, #1 */
/* @0x25d7f0 cmp r10, #0 */
/* @0x25d7f4 cmpne r10, #125 */
/* @0x25d7f8 beq 0x25d830 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2708> */
/* @0x25d7fc sub r0, r10, #48 */
/* @0x25d800 cmp r10, #45 */
/* @0x25d804 cmpne r0, #9 */
/* @0x25d808 bls 0x25d81c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26f4> */
/* @0x25d80c b 0x25d974 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284c> */
/* @0x25d810 cmp r0, #45 */
/* @0x25d814 cmpne r8, #9 */
/* @0x25d818 bhi 0x25d974 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x284c> */
/* @0x25d81c ldrb r0, [r12, #0x1]! */
/* @0x25d820 cmp r0, #125 */
/* @0x25d824 cmpne r0, #0 */
/* @0x25d828 sub r8, r0, #48 */
/* @0x25d82c bne 0x25d810 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26e8> */
/* @0x25d830 mov r8, r10 */
/* @0x25d834 mov r5, r9 */
/* @0x25d838 mov r11, #1 */
/* @0x25d83c b 0x25d42c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2304> */
/* @0x25d840 cmp r0, #0 */
/* @0x25d844 bne 0x25d950 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2828> */
/* @0x25d848 mov r3, #58 */
/* @0x25d84c mov r8, r0 */
/* @0x25d850 str r3, [r2] */
/* @0x25d854 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d858 mov r0, #55 */
/* @0x25d85c b 0x25d2e0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x21b8> */
/* @0x25d860 cmp r3, #64 */
/* @0x25d864 add r3, r3, r2, lsl #4 */
/* @0x25d868 movls r0, #48 */
/* @0x25d86c bls 0x25d234 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x210c> */
/* @0x25d870 b 0x25d230 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2108> */
/* @0x25d874 ldrb r3, [r8] */
/* @0x25d878 mov r5, r8 */
/* @0x25d87c sub r3, r3, #48 */
/* @0x25d880 cmp r3, #7 */
/* @0x25d884 bhi 0x25d8a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x277c> */
/* @0x25d888 add r3, r8, #1 */
/* @0x25d88c mov r5, r3 */
/* @0x25d890 add r3, r3, #1 */
/* @0x25d894 ldrb r0, [r5] */
/* @0x25d898 sub r0, r0, #48 */
/* @0x25d89c cmp r0, #7 */
/* @0x25d8a0 bls 0x25d88c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2764> */
/* @0x25d8a4 mov r3, #34 */
/* @0x25d8a8 mov r8, #0 */
/* @0x25d8ac str r3, [r2] */
/* @0x25d8b0 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d8b4 cmp r2, #64 */
/* @0x25d8b8 movls r0, #48 */
/* @0x25d8bc bls 0x25d21c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20f4> */
/* @0x25d8c0 b 0x25d218 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x20f0> */
/* @0x25d8c4 ldr r9, [pc, #0x144] */
/* @0x25d8c8 mov r0, r5 */
/* @0x25d8cc mov r4, r12 */
/* @0x25d8d0 add r9, pc, r9 */
/* @0x25d8d4 b 0x25d900 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27d8> */
/* @0x25d8d8 cmp r3, #96 */
/* @0x25d8dc bls 0x25d930 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2808> */
/* @0x25d8e0 add r3, r3, r4, lsl #4 */
/* @0x25d8e4 sub r3, r3, #32 */
/* @0x25d8e8 mov r4, #55 */
/* @0x25d8ec rsb r4, r4, r3 */
/* @0x25d8f0 cmp r4, #255 */
/* @0x25d8f4 bhi 0x25d97c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2854> */
/* @0x25d8f8 ldrb r3, [r0, #0x1] */
/* @0x25d8fc mov r0, r5 */
/* @0x25d900 add r8, r9, r3 */
/* @0x25d904 mov r5, r0 */
/* @0x25d908 ldrb r8, [r8, #0x98] */
/* @0x25d90c tst r8, #8 */
/* @0x25d910 beq 0x25d7d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x26a8> */
/* @0x25d914 add r5, r0, #1 */
/* @0x25d918 cmp r3, #48 */
/* @0x25d91c cmpeq r4, #0 */
/* @0x25d920 mov r8, r5 */
/* @0x25d924 bne 0x25d8d8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27b0> */
/* @0x25d928 mov r4, #0 */
/* @0x25d92c b 0x25d8f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27d0> */
/* @0x25d930 cmp r3, #64 */
/* @0x25d934 add r3, r3, r4, lsl #4 */
/* @0x25d938 movls r4, #48 */
/* @0x25d93c bls 0x25d8ec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27c4> */
/* @0x25d940 b 0x25d8e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x27c0> */
/* @0x25d944 mov r3, #86 */
/* @0x25d948 str r3, [r2] */
/* @0x25d94c b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d950 ldr r12, [sp, #0xc] */
/* @0x25d954 cmp r12, #0 */
/* @0x25d958 beq 0x25d9c8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x28a0> */
/* @0x25d95c cmp r3, r0 */
/* @0x25d960 bge 0x25d9c0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2898> */
/* @0x25d964 mov r3, #15 */
/* @0x25d968 mov r8, #0 */
/* @0x25d96c str r3, [r2] */
/* @0x25d970 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d974 mov r8, #28 */
/* @0x25d978 b 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d97c ldr r12, [pc, #0x90] */
/* @0x25d980 ldrb r3, [r8] */
/* @0x25d984 add r12, pc, r12 */
/* @0x25d988 add r3, r12, r3 */
/* @0x25d98c ldrb r3, [r3, #0x98] */
/* @0x25d990 tst r3, #8 */
/* @0x25d994 beq 0x25d9b8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2890> */
/* @0x25d998 add r3, r8, #1 */
/* @0x25d99c mov r8, r3 */
/* @0x25d9a0 add r3, r3, #1 */
/* @0x25d9a4 ldrb r0, [r8] */
/* @0x25d9a8 add r0, r12, r0 */
/* @0x25d9ac ldrb r0, [r0, #0x98] */
/* @0x25d9b0 tst r0, #8 */
/* @0x25d9b4 bne 0x25d99c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2874> */
/* @0x25d9b8 mov r5, r8 */
/* @0x25d9bc b 0x25d8a4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x277c> */
/* @0x25d9c0 rsb r0, r0, #1 */
/* @0x25d9c4 add r0, r0, r3 */
/* @0x25d9c8 rsb r8, r0, #0 */
/* @0x25d9cc b 0x25d4f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x23d0> */
/* @0x25d9d0 sub r3, r4, #55296 */
/* @0x25d9d4 cmp r3, #2048 */
/* @0x25d9d8 movhs r12, #0 */
/* @0x25d9dc andlo r12, r12, #1 */
/* @0x25d9e0 cmp r12, #0 */
/* @0x25d9e4 moveq r8, r12 */
/* @0x25d9e8 beq 0x25cf18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1df0> */
/* @0x25d9ec b 0x25d6d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x25a8> */
/* @0x25d9f0 mov r0, #0 */
/* @0x25d9f4 b 0x25d490 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2368> */
/* @0x25d9f8 ldrheq r12, [r2], -r4 */
/* @0x25d9fc andseq r12, r2, r4, ror r9 */
/* @0x25da00 ldrsheq r12, [r2], -r12 */
/* @0x25da04 andseq r12, r2, r0, lsl #12 */
/* @0x25da08 andseq r12, r2, r4, asr #11 */
/* @0x25da0c andseq r12, r2, r8, asr #8 */
/* @0x25da10 andseq r12, r2, r0, lsl #5 */
/* @0x25da14 andseq r12, r2, r12, asr #3 */
/* @0x25da18 push {r4, r5, r6, r7} */
/* @0x25da1c mov r4, #1 */
/* @0x25da20 ldrb r12, [r1] */
/* @0x25da24 ldr r5, [sp, #0x14] */
/* @0x25da28 and r6, r12, #7 */
/* @0x25da2c cmp r5, #0 */
/* @0x25da30 cmpne r12, #127 */
/* @0x25da34 ldrb r5, [r0, r12, lsr #3] */
/* @0x25da38 orr r5, r5, r4, lsl r6 */
/* @0x25da3c strb r5, [r0, r12, lsr #3] */
/* @0x25da40 bls 0x25da8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2964> */
/* @0x25da44 ldrb r3, [r1] */
/* @0x25da48 cmp r3, #191 */
/* @0x25da4c addls r0, r1, r4 */
/* @0x25da50 bls 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c> */
/* @0x25da54 tst r3, #32 */
/* @0x25da58 addeq r0, r1, #2 */
/* @0x25da5c beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c> */
/* @0x25da60 tst r3, #16 */
/* @0x25da64 addeq r0, r1, #3 */
/* @0x25da68 beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c> */
/* @0x25da6c tst r3, #8 */
/* @0x25da70 addeq r0, r1, #4 */
/* @0x25da74 beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c> */
/* @0x25da78 tst r3, #4 */
/* @0x25da7c addeq r0, r1, #5 */
/* @0x25da80 addne r0, r1, #6 */
/* @0x25da84 pop {r4, r5, r6, r7} */
/* @0x25da88 bx lr */
/* @0x25da8c cmp r2, #0 */
/* @0x25da90 beq 0x25dac4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x299c> */
/* @0x25da94 ldr r5, [sp, #0x10] */
/* @0x25da98 ldr r2, [r5] */
/* @0x25da9c ldrb r2, [r2, r12] */
/* @0x25daa0 tst r2, #2 */
/* @0x25daa4 beq 0x25dac4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x299c> */
/* @0x25daa8 ldr r3, [r3] */
/* @0x25daac ldrb r3, [r3, r12] */
/* @0x25dab0 and r12, r3, #7 */
/* @0x25dab4 lsr r3, r3, #3 */
/* @0x25dab8 ldrb r2, [r0, r3] */
/* @0x25dabc orr r4, r2, r4, lsl r12 */
/* @0x25dac0 strb r4, [r0, r3] */
/* @0x25dac4 add r0, r1, #1 */
/* @0x25dac8 pop {r4, r5, r6, r7} */
/* @0x25dacc bx lr */
/* @0x25dad0 cmp r2, #0 */
/* @0x25dad4 push {r4, r5, r6} */
/* @0x25dad8 beq 0x25db18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29f0> */
/* @0x25dadc sub r1, r1, #1 */
/* @0x25dae0 add r6, r0, r2 */
/* @0x25dae4 rsb r1, r0, r1 */
/* @0x25dae8 mov r12, r0 */
/* @0x25daec ldrb r5, [r12], #1 */
/* @0x25daf0 ldr r4, [r3] */
/* @0x25daf4 cmp r12, r6 */
/* @0x25daf8 add r4, r4, r12 */
/* @0x25dafc ldrb r4, [r4, r1] */
/* @0x25db00 mvn r4, r4 */
/* @0x25db04 orr r4, r4, r5 */
/* @0x25db08 strb r4, [r12, #-0x1] */
/* @0x25db0c bne 0x25daec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29c4> */
/* @0x25db10 cmp r2, #32 */
/* @0x25db14 beq 0x25db30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a08> */
/* @0x25db18 mov r3, #24 */
/* @0x25db1c mvn r2, #0 */
/* @0x25db20 strb r2, [r0, r3] */
/* @0x25db24 add r3, r3, #1 */
/* @0x25db28 cmp r3, #32 */
/* @0x25db2c bne 0x25db20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29f8> */
/* @0x25db30 pop {r4, r5, r6} */
/* @0x25db34 bx lr */
/* @0x25db38 push {r4, r5, r6, r7} */
/* @0x25db3c mov r4, r0 */
/* @0x25db40 ldrb r12, [r4], #1 */
/* @0x25db44 sub r5, r12, #33 */
/* @0x25db48 cmp r5, #64 */
/* @0x25db4c str r12, [r3] */
/* @0x25db50 movhi r0, #0 */
/* @0x25db54 strhi r0, [r3, #0x4] */
/* @0x25db58 bhi 0x25dc68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b40> */
/* @0x25db5c cmp r12, #84 */
/* @0x25db60 movhi r6, #85 */
/* @0x25db64 bls 0x25dcf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bd0> */
/* @0x25db68 rsb r5, r6, r12 */
/* @0x25db6c uxtb r5, r5 */
/* @0x25db70 sub r7, r5, #6 */
/* @0x25db74 cmp r5, #12 */
/* @0x25db78 cmpne r7, #2 */
/* @0x25db7c addls r4, r0, #3 */
/* @0x25db80 and r0, r5, #253 */
/* @0x25db84 sub r5, r5, #2 */
/* @0x25db88 cmp r0, #8 */
/* @0x25db8c cmpne r5, #1 */
/* @0x25db90 movls r5, #0 */
/* @0x25db94 movhi r5, #1 */
/* @0x25db98 cmp r6, #59 */
/* @0x25db9c str r5, [r3, #0x4] */
/* @0x25dba0 beq 0x25ddb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c90> */
/* @0x25dba4 bhi 0x25dc50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b28> */
/* @0x25dba8 cmp r6, #33 */
/* @0x25dbac beq 0x25dd6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c44> */
/* @0x25dbb0 cmp r6, #46 */
/* @0x25dbb4 bne 0x25dc68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b40> */
/* @0x25dbb8 mov r12, #30 */
/* @0x25dbbc cmp r12, #29 */
/* @0x25dbc0 str r12, [r3] */
/* @0x25dbc4 bls 0x25dcd0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ba8> */
/* @0x25dbc8 cmp r12, #32 */
/* @0x25dbcc beq 0x25dd88 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c60> */
/* @0x25dbd0 bls 0x25dcb4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b8c> */
/* @0x25dbd4 sub r2, r12, #110 */
/* @0x25dbd8 cmp r2, #2 */
/* @0x25dbdc bhi 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dbe0 cmp r12, #112 */
/* @0x25dbe4 addne r0, r4, #32 */
/* @0x25dbe8 ldrbeq r0, [r4] */
/* @0x25dbec ldrbeq r2, [r4, #0x1] */
/* @0x25dbf0 orreq r0, r2, r0, lsl #8 */
/* @0x25dbf4 subeq r0, r0, #1 */
/* @0x25dbf8 addeq r0, r4, r0 */
/* @0x25dbfc ldrb r2, [r0] */
/* @0x25dc00 sub r2, r2, #98 */
/* @0x25dc04 uxtb r2, r2 */
/* @0x25dc08 cmp r2, #11 */
/* @0x25dc0c bhi 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25dc10 mov r12, #1 */
/* @0x25dc14 movw r1, #0x533 */
/* @0x25dc18 lsl r2, r12, r2 */
/* @0x25dc1c and r1, r2, r1 */
/* @0x25dc20 cmp r1, #0 */
/* @0x25dc24 strne r12, [r3, #0x4] */
/* @0x25dc28 addne r0, r0, #1 */
/* @0x25dc2c bne 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25dc30 tst r2, #2240 */
/* @0x25dc34 bne 0x25de98 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d70> */
/* @0x25dc38 tst r2, #524 */
/* @0x25dc3c addne r0, r0, #1 */
/* @0x25dc40 rsb r4, r4, r0 */
/* @0x25dc44 str r4, [r3, #0x8] */
/* @0x25dc48 pop {r4, r5, r6, r7} */
/* @0x25dc4c bx lr */
/* @0x25dc50 cmp r6, #72 */
/* @0x25dc54 beq 0x25dd78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c50> */
/* @0x25dc58 cmp r6, #85 */
/* @0x25dc5c ldrbeq r0, [r4], #1 */
/* @0x25dc60 moveq r12, r0 */
/* @0x25dc64 streq r0, [r3] */
/* @0x25dc68 cmp r12, #29 */
/* @0x25dc6c bne 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25dc70 ldrb r2, [r4] */
/* @0x25dc74 cmp r1, #0 */
/* @0x25dc78 cmpne r2, #191 */
/* @0x25dc7c addls r0, r4, #1 */
/* @0x25dc80 bls 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25dc84 tst r2, #32 */
/* @0x25dc88 bne 0x25ddc8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ca0> */
/* @0x25dc8c ldrb r1, [r4, #0x1] */
/* @0x25dc90 and r2, r2, #31 */
/* @0x25dc94 add r0, r4, #2 */
/* @0x25dc98 and r1, r1, #63 */
/* @0x25dc9c orr r2, r1, r2, lsl #6 */
/* @0x25dca0 str r2, [r3, #0x8] */
/* @0x25dca4 mvn r2, #0 */
/* @0x25dca8 pop {r4, r5, r6, r7} */
/* @0x25dcac str r2, [r3, #0xc] */
/* @0x25dcb0 bx lr */
/* @0x25dcb4 cmp r12, #30 */
/* @0x25dcb8 beq 0x25dd20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bf8> */
/* @0x25dcbc cmp r12, #31 */
/* @0x25dcc0 beq 0x25dc70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b48> */
/* @0x25dcc4 mov r0, #0 */
/* @0x25dcc8 pop {r4, r5, r6, r7} */
/* @0x25dccc bx lr */
/* @0x25dcd0 cmp r12, #6 */
/* @0x25dcd4 blo 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dcd8 cmp r12, #13 */
/* @0x25dcdc bls 0x25dcec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bc4> */
/* @0x25dce0 sub r12, r12, #17 */
/* @0x25dce4 cmp r12, #9 */
/* @0x25dce8 bhi 0x25dcc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b9c> */
/* @0x25dcec mov r0, r4 */
/* @0x25dcf0 pop {r4, r5, r6, r7} */
/* @0x25dcf4 bx lr */
/* @0x25dcf8 cmp r12, #71 */
/* @0x25dcfc movhi r6, #72 */
/* @0x25dd00 bhi 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd04 cmp r12, #58 */
/* @0x25dd08 movhi r6, #59 */
/* @0x25dd0c bhi 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd10 cmp r12, #45 */
/* @0x25dd14 movls r6, #33 */
/* @0x25dd18 movhi r6, #46 */
/* @0x25dd1c b 0x25db68 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a40> */
/* @0x25dd20 mov r0, #29 */
/* @0x25dd24 str r0, [r3] */
/* @0x25dd28 ldrb r12, [r4] */
/* @0x25dd2c cmp r1, #0 */
/* @0x25dd30 cmpne r12, #191 */
/* @0x25dd34 bls 0x25dd90 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c68> */
/* @0x25dd38 tst r12, #32 */
/* @0x25dd3c bne 0x25de08 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2ce0> */
/* @0x25dd40 ldrb r1, [r4, #0x1] */
/* @0x25dd44 and r12, r12, #31 */
/* @0x25dd48 add r0, r4, #2 */
/* @0x25dd4c and r1, r1, #63 */
/* @0x25dd50 orr r12, r1, r12, lsl #6 */
/* @0x25dd54 cmp r12, #255 */
/* @0x25dd58 str r12, [r3, #0x8] */
/* @0x25dd5c bls 0x25dd98 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c70> */
/* @0x25dd60 mvn r2, #0 */
/* @0x25dd64 str r2, [r3, #0xc] */
/* @0x25dd68 b 0x25dc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b20> */
/* @0x25dd6c mov r2, #29 */
/* @0x25dd70 str r2, [r3] */
/* @0x25dd74 b 0x25dc70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b48> */
/* @0x25dd78 mov r12, #32 */
/* @0x25dd7c str r12, [r3] */
/* @0x25dd80 cmp r12, #29 */
/* @0x25dd84 b 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25dd88 mov r0, #31 */
/* @0x25dd8c b 0x25dd24 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2bfc> */
/* @0x25dd90 add r0, r4, #1 */
/* @0x25dd94 str r12, [r3, #0x8] */
/* @0x25dd98 ldrb r2, [r2, r12] */
/* @0x25dd9c cmp r2, r12 */
/* @0x25dda0 str r2, [r3, #0xc] */
/* @0x25dda4 mvnne r2, #0 */
/* @0x25dda8 strne r2, [r3, #0x10] */
/* @0x25ddac beq 0x25dd60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c38> */
/* @0x25ddb0 pop {r4, r5, r6, r7} */
/* @0x25ddb4 bx lr */
/* @0x25ddb8 mov r12, #31 */
/* @0x25ddbc str r12, [r3] */
/* @0x25ddc0 cmp r12, #29 */
/* @0x25ddc4 b 0x25dbc4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a9c> */
/* @0x25ddc8 tst r2, #16 */
/* @0x25ddcc beq 0x25de48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d20> */
/* @0x25ddd0 tst r2, #8 */
/* @0x25ddd4 bne 0x25deb8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d90> */
/* @0x25ddd8 ldrb r12, [r4, #0x1] */
/* @0x25dddc and r2, r2, #7 */
/* @0x25dde0 ldrb r5, [r4, #0x3] */
/* @0x25dde4 add r0, r4, #4 */
/* @0x25dde8 ldrb r1, [r4, #0x2] */
/* @0x25ddec and r12, r12, #63 */
/* @0x25ddf0 and r4, r5, #63 */
/* @0x25ddf4 orr r2, r4, r2, lsl #18 */
/* @0x25ddf8 and r1, r1, #63 */
/* @0x25ddfc orr r2, r2, r12, lsl #12 */
/* @0x25de00 orr r2, r2, r1, lsl #6 */
/* @0x25de04 b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25de08 tst r12, #16 */
/* @0x25de0c beq 0x25de70 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d48> */
/* @0x25de10 tst r12, #8 */
/* @0x25de14 bne 0x25defc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dd4> */
/* @0x25de18 ldrb r1, [r4, #0x3] */
/* @0x25de1c and r5, r12, #7 */
/* @0x25de20 ldrb r6, [r4, #0x1] */
/* @0x25de24 add r0, r4, #4 */
/* @0x25de28 ldrb r12, [r4, #0x2] */
/* @0x25de2c and r1, r1, #63 */
/* @0x25de30 and r4, r6, #63 */
/* @0x25de34 orr r1, r1, r5, lsl #18 */
/* @0x25de38 and r12, r12, #63 */
/* @0x25de3c orr r1, r1, r4, lsl #12 */
/* @0x25de40 orr r12, r1, r12, lsl #6 */
/* @0x25de44 b 0x25dd54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c2c> */
/* @0x25de48 lsl r2, r2, #12 */
/* @0x25de4c ldrb r12, [r4, #0x2] */
/* @0x25de50 ldrb r1, [r4, #0x1] */
/* @0x25de54 add r0, r4, #3 */
/* @0x25de58 uxth r2, r2 */
/* @0x25de5c and r12, r12, #63 */
/* @0x25de60 and r1, r1, #63 */
/* @0x25de64 orr r2, r2, r12 */
/* @0x25de68 orr r2, r2, r1, lsl #6 */
/* @0x25de6c b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25de70 lsl r5, r12, #12 */
/* @0x25de74 ldrb r1, [r4, #0x2] */
/* @0x25de78 ldrb r12, [r4, #0x1] */
/* @0x25de7c add r0, r4, #3 */
/* @0x25de80 and r1, r1, #63 */
/* @0x25de84 uxth r4, r5 */
/* @0x25de88 and r12, r12, #63 */
/* @0x25de8c orr r1, r4, r1 */
/* @0x25de90 orr r12, r1, r12, lsl #6 */
/* @0x25de94 b 0x25dd54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2c2c> */
/* @0x25de98 ldrb r2, [r0, #0x2] */
/* @0x25de9c add r0, r0, #5 */
/* @0x25dea0 ldrb r1, [r0, #-0x4] */
/* @0x25dea4 orrs r2, r2, r1, lsl #8 */
/* @0x25dea8 movne r2, #0 */
/* @0x25deac moveq r2, #1 */
/* @0x25deb0 str r2, [r3, #0x4] */
/* @0x25deb4 b 0x25dc40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b18> */
/* @0x25deb8 tst r2, #4 */
/* @0x25debc bne 0x25df2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2e04> */
/* @0x25dec0 ldrb r6, [r4, #0x4] */
/* @0x25dec4 and r2, r2, #3 */
/* @0x25dec8 ldrb r5, [r4, #0x1] */
/* @0x25decc add r0, r4, #5 */
/* @0x25ded0 and r6, r6, #63 */
/* @0x25ded4 ldrb r12, [r4, #0x2] */
/* @0x25ded8 ldrb r1, [r4, #0x3] */
/* @0x25dedc and r5, r5, #63 */
/* @0x25dee0 orr r2, r6, r2, lsl #24 */
/* @0x25dee4 and r12, r12, #63 */
/* @0x25dee8 orr r2, r2, r5, lsl #18 */
/* @0x25deec and r1, r1, #63 */
/* @0x25def0 orr r2, r2, r12, lsl #12 */
/* @0x25def4 orr r2, r2, r1, lsl #6 */
/* @0x25def8 b 0x25dca0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2b78> */
/* @0x25defc tst r12, #4 */
/* @0x25df00 bne 0x25df60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2e38> */
/* @0x25df04 ldrb r1, [r4, #0x4] */
/* @0x25df08 and r7, r12, #3 */
/* @0x25df0c ldrb r5, [r4, #0x1] */
/* @0x25df10 add r0, r4, #5 */
/* @0x25df14 ldrb r6, [r4, #0x2] */
/* @0x25df18 and r1, r1, #63 */
/* @0x25df1c ldrb r12, [r4, #0x3] */
/* @0x25df20 and r5, r5, #63 */
/* @0x25df24 orr r1, r1, r7, lsl #24 */
/* @0x25df28 b 0x25de30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2d08> */
/* @0x25df2c ldrb r1, [r4, #0x5] */
/* @0x25df30 and r2, r2, #1 */
/* @0x25df34 ldrb r6, [r4, #0x1] */
/* @0x25df38 add r0, r4, #6 */
/* @0x25df3c and r1, r1, #63 */
/* @0x25df40 ldrb r5, [r4, #0x2] */
/* @0x25df44 and r6, r6, #63 */
/* @0x25df48 orr r2, r1, r2, lsl #30 */
/* @0x25df4c ldrb r12, [r4, #0x3] */
/* @0x25df50 and r5, r5, #63 */
/* @0x25df54 ldrb r1, [r4, #0x4] */
/* @0x25df58 orr r2, r2, r6, lsl #24 */
/* @0x25df5c b 0x25dee4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dbc> */
/* @0x25df60 ldrb r1, [r4, #0x5] */
/* @0x25df64 and r12, r12, #1 */
/* @0x25df68 ldrb r7, [r4, #0x1] */
/* @0x25df6c add r0, r4, #6 */
/* @0x25df70 ldrb r5, [r4, #0x2] */
/* @0x25df74 and r1, r1, #63 */
/* @0x25df78 orr r1, r1, r12, lsl #30 */
/* @0x25df7c and r7, r7, #63 */
/* @0x25df80 ldrb r6, [r4, #0x3] */
/* @0x25df84 and r5, r5, #63 */
/* @0x25df88 ldrb r12, [r4, #0x4] */
/* @0x25df8c b 0x25df24 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2dfc> */

/* ── FUNC 0x25df90 · pcre_pattern_to_host_byte_order · size=364 · insn=91 */
/* @0x25df90 cmp r0, #0 */
/* @0x25df94 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x25df98 beq 0x25e0f4 <pcre_pattern_to_host_byte_order+0x164> */
/* @0x25df9c ldr r12, [r0] */
/* @0x25dfa0 movw r3, #0x5245 */
/* @0x25dfa4 movt r3, #0x5043 */
/* @0x25dfa8 cmp r12, r3 */
/* @0x25dfac beq 0x25e0c0 <pcre_pattern_to_host_byte_order+0x130> */
/* @0x25dfb0 movw r4, #0x4350 */
/* @0x25dfb4 movt r4, #0x4552 */
/* @0x25dfb8 cmp r12, r4 */
/* @0x25dfbc bne 0x25e0dc <pcre_pattern_to_host_byte_order+0x14c> */
/* @0x25dfc0 ldr r12, [r0, #0xc] */
/* @0x25dfc4 rev r12, r12 */
/* @0x25dfc8 tst r12, #1 */
/* @0x25dfcc beq 0x25e0ec <pcre_pattern_to_host_byte_order+0x15c> */
/* @0x25dfd0 ldrh r11, [r0, #28] */
/* @0x25dfd4 cmp r1, #0 */
/* @0x25dfd8 ldr r9, [r0, #0x4] */
/* @0x25dfdc ldr r8, [r0, #0x8] */
/* @0x25dfe0 ldr r7, [r0, #0x10] */
/* @0x25dfe4 rev r9, r9 */
/* @0x25dfe8 ldr r6, [r0, #0x14] */
/* @0x25dfec rev r8, r8 */
/* @0x25dff0 ldrh r5, [r0, #24] */
/* @0x25dff4 rev r7, r7 */
/* @0x25dff8 ldrh r4, [r0, #26] */
/* @0x25dffc rev r6, r6 */
/* @0x25e000 ldrh r10, [r0, #30] */
/* @0x25e004 rev16 r5, r5 */
/* @0x25e008 str r3, [r0] */
/* @0x25e00c rev16 r3, r11 */
/* @0x25e010 str r12, [r0, #0xc] */
/* @0x25e014 rev16 r4, r4 */
/* @0x25e018 ldrh r11, [r0, #32] */
/* @0x25e01c rev16 r10, r10 */
/* @0x25e020 ldrh r12, [r0, #34] */
/* @0x25e024 str r2, [r0, #0x30] */
/* @0x25e028 rev16 r11, r11 */
/* @0x25e02c ldrh r2, [r0, #36] */
/* @0x25e030 rev16 r12, r12 */
/* @0x25e034 str r9, [r0, #0x4] */
/* @0x25e038 str r8, [r0, #0x8] */
/* @0x25e03c rev16 r2, r2 */
/* @0x25e040 ldrh r9, [r0, #38] */
/* @0x25e044 ldrh r8, [r0, #40] */
/* @0x25e048 rev16 r9, r9 */
/* @0x25e04c str r7, [r0, #0x10] */
/* @0x25e050 rev16 r8, r8 */
/* @0x25e054 str r6, [r0, #0x14] */
/* @0x25e058 strh r5, [r0, #24] */
/* @0x25e05c strh r4, [r0, #26] */
/* @0x25e060 strh r3, [r0, #28] */
/* @0x25e064 strh r10, [r0, #30] */
/* @0x25e068 strh r11, [r0, #32] */
/* @0x25e06c strh r12, [r0, #34] */
/* @0x25e070 strh r2, [r0, #36] */
/* @0x25e074 strh r9, [r0, #38] */
/* @0x25e078 strh r8, [r0, #40] */
/* @0x25e07c beq 0x25e0e4 <pcre_pattern_to_host_byte_order+0x154> */
/* @0x25e080 ldr r0, [r1] */
/* @0x25e084 ands r0, r0, #1 */
/* @0x25e088 beq 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128> */
/* @0x25e08c ldr r3, [r1, #0x4] */
/* @0x25e090 mov r0, #0 */
/* @0x25e094 ldr r12, [r3] */
/* @0x25e098 ldr r1, [r3, #0x4] */
/* @0x25e09c ldr r2, [r3, #0x28] */
/* @0x25e0a0 rev r12, r12 */
/* @0x25e0a4 rev r1, r1 */
/* @0x25e0a8 str r12, [r3] */
/* @0x25e0ac rev r2, r2 */
/* @0x25e0b0 str r1, [r3, #0x4] */
/* @0x25e0b4 str r2, [r3, #0x28] */
/* @0x25e0b8 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x25e0bc bx lr */
/* @0x25e0c0 ldr r3, [r0, #0xc] */
/* @0x25e0c4 tst r3, #1 */
/* @0x25e0c8 beq 0x25e0ec <pcre_pattern_to_host_byte_order+0x15c> */
/* @0x25e0cc str r2, [r0, #0x30] */
/* @0x25e0d0 mov r0, #0 */
/* @0x25e0d4 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x25e0d8 bx lr */
/* @0x25e0dc mvn r0, #3 */
/* @0x25e0e0 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128> */
/* @0x25e0e4 mov r0, r1 */
/* @0x25e0e8 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128> */
/* @0x25e0ec mvn r0, #27 */
/* @0x25e0f0 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128> */
/* @0x25e0f4 mvn r0, #1 */
/* @0x25e0f8 b 0x25e0b8 <pcre_pattern_to_host_byte_order+0x128> */

/* ── FUNC 0x25e0fc · _pcre_find_bracket · size=596 · insn=149 */
/* @0x25e0fc push {r4, r5} */
/* @0x25e100 ldr r5, [pc, #0x23c] */
/* @0x25e104 add r5, pc, r5 */
/* @0x25e108 ldrb r3, [r0] */
/* @0x25e10c cmp r3, #0 */
/* @0x25e110 beq 0x25e2c4 <_pcre_find_bracket+0x1c8> */
/* @0x25e114 cmp r3, #112 */
/* @0x25e118 beq 0x25e320 <_pcre_find_bracket+0x224> */
/* @0x25e11c cmp r3, #124 */
/* @0x25e120 beq 0x25e334 <_pcre_find_bracket+0x238> */
/* @0x25e124 add r4, r3, #123 */
/* @0x25e128 add r12, r3, #118 */
/* @0x25e12c uxtb r4, r4 */
/* @0x25e130 uxtb r12, r12 */
/* @0x25e134 cmp r12, #1 */
/* @0x25e138 cmphi r4, #1 */
/* @0x25e13c bls 0x25e2f8 <_pcre_find_bracket+0x1fc> */
/* @0x25e140 sub r12, r3, #85 */
/* @0x25e144 cmp r12, #70 */
/* @0x25e148 addls pc, pc, r12, lsl #2 */
/* @0x25e14c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e150 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e154 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e158 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e15c b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e160 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e164 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e168 b 0x25e2e4 <_pcre_find_bracket+0x1e8> */
/* @0x25e16c b 0x25e2e4 <_pcre_find_bracket+0x1e8> */
/* @0x25e170 b 0x25e2e4 <_pcre_find_bracket+0x1e8> */
/* @0x25e174 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e178 b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e17c b 0x25e2d0 <_pcre_find_bracket+0x1d4> */
/* @0x25e180 b 0x25e2e4 <_pcre_find_bracket+0x1e8> */
/* @0x25e184 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e188 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e18c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e190 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e194 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e198 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e19c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1a0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1a4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1a8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1ac b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1b0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1b4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1b8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1bc b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1c0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1c4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1c8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1cc b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1d0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1d4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1d8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1dc b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1e0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1e4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1e8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1ec b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1f0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1f4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1f8 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e1fc b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e200 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e204 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e208 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e20c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e210 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e214 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e218 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e21c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e220 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e224 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e228 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e22c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e230 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e234 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e238 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e23c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e240 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e244 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e248 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e24c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e250 b 0x25e26c <_pcre_find_bracket+0x170> */
/* @0x25e254 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e258 b 0x25e26c <_pcre_find_bracket+0x170> */
/* @0x25e25c b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e260 b 0x25e26c <_pcre_find_bracket+0x170> */
/* @0x25e264 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e268 b 0x25e26c <_pcre_find_bracket+0x170> */
/* @0x25e26c ldrb r12, [r0, #0x1] */
/* @0x25e270 add r0, r0, r12 */
/* @0x25e274 ldr r12, [pc, #0xcc] */
/* @0x25e278 cmp r1, #0 */
/* @0x25e27c ldr r12, [r5, r12] */
/* @0x25e280 ldrb r12, [r12, r3] */
/* @0x25e284 add r0, r0, r12 */
/* @0x25e288 beq 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e28c sub r3, r3, #29 */
/* @0x25e290 cmp r3, #55 */
/* @0x25e294 bhi 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e298 ldrb r3, [r0, #-0x1] */
/* @0x25e29c cmp r3, #191 */
/* @0x25e2a0 bls 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e2a4 ldr r12, [pc, #0xa0] */
/* @0x25e2a8 and r3, r3, #63 */
/* @0x25e2ac ldr r12, [r5, r12] */
/* @0x25e2b0 ldrb r3, [r12, r3] */
/* @0x25e2b4 add r0, r0, r3 */
/* @0x25e2b8 ldrb r3, [r0] */
/* @0x25e2bc cmp r3, #0 */
/* @0x25e2c0 bne 0x25e114 <_pcre_find_bracket+0x18> */
/* @0x25e2c4 mov r0, r3 */
/* @0x25e2c8 pop {r4, r5} */
/* @0x25e2cc bx lr */
/* @0x25e2d0 ldrb r12, [r0, #0x1] */
/* @0x25e2d4 sub r12, r12, #15 */
/* @0x25e2d8 cmp r12, #1 */
/* @0x25e2dc addls r0, r0, #2 */
/* @0x25e2e0 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e2e4 ldrb r12, [r0, #0x3] */
/* @0x25e2e8 sub r12, r12, #15 */
/* @0x25e2ec cmp r12, #1 */
/* @0x25e2f0 addls r0, r0, #2 */
/* @0x25e2f4 b 0x25e274 <_pcre_find_bracket+0x178> */
/* @0x25e2f8 ldrb r4, [r0, #0x3] */
/* @0x25e2fc ldrb r12, [r0, #0x4] */
/* @0x25e300 orr r12, r12, r4, lsl #8 */
/* @0x25e304 cmp r12, r2 */
/* @0x25e308 beq 0x25e2c8 <_pcre_find_bracket+0x1cc> */
/* @0x25e30c ldr r12, [pc, #0x34] */
/* @0x25e310 ldr r12, [r5, r12] */
/* @0x25e314 ldrb r3, [r12, r3] */
/* @0x25e318 add r0, r0, r3 */
/* @0x25e31c b 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e320 ldrb r12, [r0, #0x1] */
/* @0x25e324 ldrb r3, [r0, #0x2] */
/* @0x25e328 orr r3, r3, r12, lsl #8 */
/* @0x25e32c add r0, r0, r3 */
/* @0x25e330 b 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e334 cmp r2, #0 */
/* @0x25e338 blt 0x25e2c8 <_pcre_find_bracket+0x1cc> */
/* @0x25e33c add r0, r0, #3 */
/* @0x25e340 b 0x25e108 <_pcre_find_bracket+0xc> */
/* @0x25e344 andseq r3, r9, r12, asr #22 */
/* @0x25e348 .word 0xfffffb8c */
/* @0x25e34c .word 0xfffffb90 */

/* ── FUNC 0x25e350 · anon_25e350 · size=2580 · insn=645 */
/* @0x25e350 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25e354 sub sp, sp, #52 */
/* @0x25e358 ubfx r10, r3, #0xb, #0x1 */
/* @0x25e35c ldr r8, [pc, #0x9f4] */
/* @0x25e360 ldr r12, [sp, #0x5c] */
/* @0x25e364 mov r7, r2 */
/* @0x25e368 str r3, [sp, #0xc] */
/* @0x25e36c add r8, pc, r8 */
/* @0x25e370 str r0, [sp, #0x10] */
/* @0x25e374 ldr r3, [r12] */
/* @0x25e378 ldr r6, [sp, #0x58] */
/* @0x25e37c cmp r3, #1000 */
/* @0x25e380 add r3, r3, #1 */
/* @0x25e384 str r3, [r12] */
/* @0x25e388 bgt 0x25e710 <_pcre_find_bracket+0x614> */
/* @0x25e38c ldrb r3, [r1] */
/* @0x25e390 mov r5, #0 */
/* @0x25e394 ldr r12, [sp, #0xc] */
/* @0x25e398 add r2, r3, #123 */
/* @0x25e39c add r3, r3, #118 */
/* @0x25e3a0 and r12, r12, #33554432 */
/* @0x25e3a4 str r5, [sp, #0x14] */
/* @0x25e3a8 uxtb r3, r3 */
/* @0x25e3ac uxtb r2, r2 */
/* @0x25e3b0 cmp r3, #1 */
/* @0x25e3b4 cmphi r2, #1 */
/* @0x25e3b8 str r12, [sp, #0x20] */
/* @0x25e3bc addhi r4, r1, #3 */
/* @0x25e3c0 addls r4, r1, #5 */
/* @0x25e3c4 mvn r12, #0 */
/* @0x25e3c8 str r12, [sp, #0x18] */
/* @0x25e3cc ldrb r3, [r4] */
/* @0x25e3d0 add r12, sp, #40 */
/* @0x25e3d4 str r12, [sp, #0x1c] */
/* @0x25e3d8 cmp r3, #161 */
/* @0x25e3dc addls pc, pc, r3, lsl #2 */
/* @0x25e3e0 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e3e4 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e3e8 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3ec b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f0 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f4 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3f8 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e3fc b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e400 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e404 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e408 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e40c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e410 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e414 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e418 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e41c b 0x25e708 <_pcre_find_bracket+0x60c> */
/* @0x25e420 b 0x25e698 <_pcre_find_bracket+0x59c> */
/* @0x25e424 b 0x25e698 <_pcre_find_bracket+0x59c> */
/* @0x25e428 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e42c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e430 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e434 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e438 b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e43c b 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e440 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e444 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e448 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e44c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e450 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e454 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e458 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e45c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e460 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e464 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e468 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e46c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e470 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e474 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e478 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e47c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e480 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e484 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e488 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e48c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e490 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e494 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e498 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e49c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4a0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4a4 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4a8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4ac b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4b8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4bc b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e4c0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4c4 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4c8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4cc b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4d8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4dc b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4e0 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4e4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4e8 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4ec b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4f0 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e4f4 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e4f8 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e4fc b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e500 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e504 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e508 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e50c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e510 b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e514 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e518 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e51c b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e520 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e524 b 0x25e964 <_pcre_find_bracket+0x868> */
/* @0x25e528 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e52c b 0x25ea60 <_pcre_find_bracket+0x964> */
/* @0x25e530 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e534 b 0x25e9a8 <_pcre_find_bracket+0x8ac> */
/* @0x25e538 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e53c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e540 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e544 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e548 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e54c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e550 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e554 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e558 b 0x25e9e4 <_pcre_find_bracket+0x8e8> */
/* @0x25e55c b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e560 b 0x25eb64 <_pcre_find_bracket+0xa68> */
/* @0x25e564 b 0x25ebac <_pcre_find_bracket+0xab0> */
/* @0x25e568 b 0x25eb84 <_pcre_find_bracket+0xa88> */
/* @0x25e56c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e570 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e574 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e578 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e57c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e580 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e584 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e588 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e58c b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e590 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e594 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e598 b 0x25e6fc <_pcre_find_bracket+0x600> */
/* @0x25e59c b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a0 b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a4 b 0x25eb08 <_pcre_find_bracket+0xa0c> */
/* @0x25e5a8 b 0x25eaa4 <_pcre_find_bracket+0x9a8> */
/* @0x25e5ac b 0x25eaa4 <_pcre_find_bracket+0x9a8> */
/* @0x25e5b0 b 0x25e830 <_pcre_find_bracket+0x734> */
/* @0x25e5b4 b 0x25e830 <_pcre_find_bracket+0x734> */
/* @0x25e5b8 b 0x25e778 <_pcre_find_bracket+0x67c> */
/* @0x25e5bc b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e5c0 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5c4 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5c8 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5cc b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5d0 b 0x25ea10 <_pcre_find_bracket+0x914> */
/* @0x25e5d4 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e5d8 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5dc b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e0 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e4 b 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e5e8 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5ec b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f0 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f4 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5f8 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e5fc b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e600 b 0x25e750 <_pcre_find_bracket+0x654> */
/* @0x25e604 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e608 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e60c b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e610 b 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e614 b 0x25e750 <_pcre_find_bracket+0x654> */
/* @0x25e618 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e61c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e620 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e624 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e628 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e62c b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e630 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e634 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e638 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e63c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e640 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e644 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e648 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e64c b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e650 b 0x25ea88 <_pcre_find_bracket+0x98c> */
/* @0x25e654 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e658 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e65c b 0x25e710 <_pcre_find_bracket+0x614> */
/* @0x25e660 b 0x25e710 <_pcre_find_bracket+0x614> */
/* @0x25e664 b 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25e668 b 0x25e71c <_pcre_find_bracket+0x620> */
/* @0x25e66c ldrb r2, [r4, #0x1] */
/* @0x25e670 ldrb r3, [r4, #0x2] */
/* @0x25e674 orr r3, r3, r2, lsl #8 */
/* @0x25e678 ldrb r3, [r4, r3]! */
/* @0x25e67c cmp r3, #119 */
/* @0x25e680 beq 0x25e66c <_pcre_find_bracket+0x570> */
/* @0x25e684 ldr r2, [pc, #0x6d0] */
/* @0x25e688 ldr r2, [r8, r2] */
/* @0x25e68c ldrb r3, [r2, r3] */
/* @0x25e690 ldrb r3, [r4, r3]! */
/* @0x25e694 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e698 add r4, r4, #2 */
/* @0x25e69c ldrb r3, [r4, #0x1] */
/* @0x25e6a0 add r5, r5, #1 */
/* @0x25e6a4 add r4, r4, #1 */
/* @0x25e6a8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e6ac ldr r12, [sp, #0x5c] */
/* @0x25e6b0 mov r1, r4 */
/* @0x25e6b4 str r6, [sp] */
/* @0x25e6b8 mov r2, r7 */
/* @0x25e6bc ldr r0, [sp, #0x10] */
/* @0x25e6c0 str r12, [sp, #0x4] */
/* @0x25e6c4 ldr r3, [sp, #0xc] */
/* @0x25e6c8 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e6cc cmp r0, #0 */
/* @0x25e6d0 blt 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25e6d4 add r5, r5, r0 */
/* @0x25e6d8 ldrb r2, [r4, #0x1] */
/* @0x25e6dc ldrb r3, [r4, #0x2] */
/* @0x25e6e0 orr r3, r3, r2, lsl #8 */
/* @0x25e6e4 ldrb r3, [r4, r3]! */
/* @0x25e6e8 cmp r3, #119 */
/* @0x25e6ec beq 0x25e6d8 <_pcre_find_bracket+0x5dc> */
/* @0x25e6f0 ldrb r3, [r4, #0x3] */
/* @0x25e6f4 add r4, r4, #3 */
/* @0x25e6f8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e6fc mvn r0, #2 */
/* @0x25e700 add sp, sp, #52 */
/* @0x25e704 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25e708 cmp r10, #0 */
/* @0x25e70c beq 0x25e69c <_pcre_find_bracket+0x5a0> */
/* @0x25e710 mvn r0, #0 */
/* @0x25e714 add sp, sp, #52 */
/* @0x25e718 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25e71c ldr r2, [pc, #0x638] */
/* @0x25e720 ldr r2, [r8, r2] */
/* @0x25e724 ldrb r3, [r2, r3] */
/* @0x25e728 add r3, r4, r3 */
/* @0x25e72c ldrb r1, [r3, #0x1] */
/* @0x25e730 ldrb r2, [r3, #0x2] */
/* @0x25e734 orr r2, r2, r1, lsl #8 */
/* @0x25e738 ldrb r2, [r3, r2]! */
/* @0x25e73c cmp r2, #119 */
/* @0x25e740 beq 0x25e72c <_pcre_find_bracket+0x630> */
/* @0x25e744 add r4, r3, #3 */
/* @0x25e748 ldrb r3, [r3, #0x3] */
/* @0x25e74c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e750 ldrb r2, [r4, #0x1] */
/* @0x25e754 ldrb r3, [r4, #0x2] */
/* @0x25e758 orr r3, r3, r2, lsl #8 */
/* @0x25e75c add r2, r4, r3 */
/* @0x25e760 ldrb r3, [r4, r3] */
/* @0x25e764 cmp r3, #119 */
/* @0x25e768 beq 0x25e6ac <_pcre_find_bracket+0x5b0> */
/* @0x25e76c add r4, r2, #3 */
/* @0x25e770 ldrb r3, [r2, #0x3] */
/* @0x25e774 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e778 ldrb r12, [r4, #0x1] */
/* @0x25e77c ldrb r3, [r4, #0x2] */
/* @0x25e780 orr r12, r3, r12, lsl #8 */
/* @0x25e784 add r12, r7, r12 */
/* @0x25e788 mov r3, r12 */
/* @0x25e78c ldrb r1, [r3, #0x1] */
/* @0x25e790 ldrb r2, [r3, #0x2] */
/* @0x25e794 orr r2, r2, r1, lsl #8 */
/* @0x25e798 ldrb r2, [r3, r2]! */
/* @0x25e79c cmp r2, #119 */
/* @0x25e7a0 beq 0x25e78c <_pcre_find_bracket+0x690> */
/* @0x25e7a4 cmp r4, r3 */
/* @0x25e7a8 movhs r3, #0 */
/* @0x25e7ac movlo r3, #1 */
/* @0x25e7b0 cmp r4, r12 */
/* @0x25e7b4 movls r3, #0 */
/* @0x25e7b8 cmp r3, #0 */
/* @0x25e7bc bne 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7c0 cmp r6, #0 */
/* @0x25e7c4 beq 0x25e7f4 <_pcre_find_bracket+0x6f8> */
/* @0x25e7c8 ldr r3, [r6, #0x4] */
/* @0x25e7cc cmp r12, r3 */
/* @0x25e7d0 beq 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7d4 mov r3, r6 */
/* @0x25e7d8 b 0x25e7e8 <_pcre_find_bracket+0x6ec> */
/* @0x25e7dc ldr r2, [r3, #0x4] */
/* @0x25e7e0 cmp r12, r2 */
/* @0x25e7e4 beq 0x25ebe4 <_pcre_find_bracket+0xae8> */
/* @0x25e7e8 ldr r3, [r3] */
/* @0x25e7ec cmp r3, #0 */
/* @0x25e7f0 bne 0x25e7dc <_pcre_find_bracket+0x6e0> */
/* @0x25e7f4 ldr r0, [sp, #0x5c] */
/* @0x25e7f8 add r3, sp, #40 */
/* @0x25e7fc mov r1, r12 */
/* @0x25e800 str r3, [sp] */
/* @0x25e804 mov r2, r7 */
/* @0x25e808 ldr r3, [sp, #0xc] */
/* @0x25e80c str r0, [sp, #0x4] */
/* @0x25e810 add r4, r4, #3 */
/* @0x25e814 ldr r0, [sp, #0x10] */
/* @0x25e818 str r6, [sp, #0x28] */
/* @0x25e81c str r12, [sp, #0x2c] */
/* @0x25e820 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e824 ldrb r3, [r4] */
/* @0x25e828 add r5, r5, r0 */
/* @0x25e82c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e830 ldr r12, [sp, #0x20] */
/* @0x25e834 cmp r12, #0 */
/* @0x25e838 bne 0x25ec10 <_pcre_find_bracket+0xb14> */
/* @0x25e83c ldr r12, [sp, #0x10] */
/* @0x25e840 ldrb r1, [r4, #0x1] */
/* @0x25e844 ldrb r3, [r4, #0x2] */
/* @0x25e848 ldrh r9, [r12, #36] */
/* @0x25e84c ldrh r2, [r12, #34] */
/* @0x25e850 orr r1, r3, r1, lsl #8 */
/* @0x25e854 ldrb r11, [r4, #0x3] */
/* @0x25e858 ldrb r3, [r4, #0x4] */
/* @0x25e85c mla r9, r9, r1, r2 */
/* @0x25e860 orr r11, r3, r11, lsl #8 */
/* @0x25e864 cmp r11, #0 */
/* @0x25e868 ldr r0, [sp, #0x10] */
/* @0x25e86c sub r12, r11, #1 */
/* @0x25e870 mvn r11, #-2147483648 */
/* @0x25e874 add r9, r0, r9 */
/* @0x25e878 beq 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25e87c str r5, [sp, #0x24] */
/* @0x25e880 mov r5, r12 */
/* @0x25e884 ldrb r2, [r9] */
/* @0x25e888 mov r0, r7 */
/* @0x25e88c ldrb r3, [r9, #0x1] */
/* @0x25e890 mov r1, r10 */
/* @0x25e894 orr r2, r3, r2, lsl #8 */
/* @0x25e898 bl 0x25e0fc <_pcre_find_bracket> */
/* @0x25e89c subs r12, r0, #0 */
/* @0x25e8a0 beq 0x25ed2c <_pcre_find_bracket+0xc30> */
/* @0x25e8a4 mov r3, r12 */
/* @0x25e8a8 ldrb r1, [r3, #0x1] */
/* @0x25e8ac ldrb r2, [r3, #0x2] */
/* @0x25e8b0 orr r2, r2, r1, lsl #8 */
/* @0x25e8b4 ldrb r2, [r3, r2]! */
/* @0x25e8b8 cmp r2, #119 */
/* @0x25e8bc beq 0x25e8a8 <_pcre_find_bracket+0x7ac> */
/* @0x25e8c0 cmp r4, r3 */
/* @0x25e8c4 movhs r3, #0 */
/* @0x25e8c8 movlo r3, #1 */
/* @0x25e8cc cmp r4, r12 */
/* @0x25e8d0 movls r3, #0 */
/* @0x25e8d4 cmp r3, #0 */
/* @0x25e8d8 bne 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e8dc cmp r6, #0 */
/* @0x25e8e0 beq 0x25e910 <_pcre_find_bracket+0x814> */
/* @0x25e8e4 ldr r2, [r6, #0x4] */
/* @0x25e8e8 cmp r2, r12 */
/* @0x25e8ec beq 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e8f0 mov r3, r6 */
/* @0x25e8f4 b 0x25e904 <_pcre_find_bracket+0x808> */
/* @0x25e8f8 ldr r2, [r3, #0x4] */
/* @0x25e8fc cmp r2, r12 */
/* @0x25e900 beq 0x25ebf8 <_pcre_find_bracket+0xafc> */
/* @0x25e904 ldr r3, [r3] */
/* @0x25e908 cmp r3, #0 */
/* @0x25e90c bne 0x25e8f8 <_pcre_find_bracket+0x7fc> */
/* @0x25e910 ldr r2, [sp, #0x5c] */
/* @0x25e914 add r0, sp, #40 */
/* @0x25e918 mov r1, r12 */
/* @0x25e91c str r0, [sp] */
/* @0x25e920 ldr r3, [sp, #0xc] */
/* @0x25e924 sub r5, r5, #1 */
/* @0x25e928 str r2, [sp, #0x4] */
/* @0x25e92c mov r2, r7 */
/* @0x25e930 ldr r0, [sp, #0x10] */
/* @0x25e934 str r12, [sp, #0x2c] */
/* @0x25e938 str r6, [sp, #0x28] */
/* @0x25e93c bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25e940 ldr r12, [sp, #0x10] */
/* @0x25e944 ldrh r3, [r12, #36] */
/* @0x25e948 add r9, r9, r3 */
/* @0x25e94c cmp r11, r0 */
/* @0x25e950 movge r11, r0 */
/* @0x25e954 cmn r5, #1 */
/* @0x25e958 bne 0x25e884 <_pcre_find_bracket+0x788> */
/* @0x25e95c ldr r5, [sp, #0x24] */
/* @0x25e960 b 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25e964 ldrb r1, [r4, #0x1] */
/* @0x25e968 cmp r10, #0 */
/* @0x25e96c ldrb r3, [r4, #0x2] */
/* @0x25e970 add r2, r4, #4 */
/* @0x25e974 orr r3, r3, r1, lsl #8 */
/* @0x25e978 add r5, r3, r5 */
/* @0x25e97c beq 0x25ebd8 <_pcre_find_bracket+0xadc> */
/* @0x25e980 ldrb r3, [r4, #0x3] */
/* @0x25e984 cmp r3, #191 */
/* @0x25e988 bls 0x25ebd8 <_pcre_find_bracket+0xadc> */
/* @0x25e98c ldr r1, [pc, #0x3cc] */
/* @0x25e990 and r3, r3, #63 */
/* @0x25e994 ldr r1, [r8, r1] */
/* @0x25e998 ldrb r3, [r1, r3] */
/* @0x25e99c add r4, r2, r3 */
/* @0x25e9a0 ldrb r3, [r2, r3] */
/* @0x25e9a4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e9a8 ldr r2, [pc, #0x3ac] */
/* @0x25e9ac cmp r10, #0 */
/* @0x25e9b0 ldr r2, [r8, r2] */
/* @0x25e9b4 ldrb r3, [r2, r3] */
/* @0x25e9b8 add r4, r4, r3 */
/* @0x25e9bc beq 0x25ebd0 <_pcre_find_bracket+0xad4> */
/* @0x25e9c0 ldrb r3, [r4, #-0x1] */
/* @0x25e9c4 cmp r3, #191 */
/* @0x25e9c8 bls 0x25ebd0 <_pcre_find_bracket+0xad4> */
/* @0x25e9cc ldr r2, [pc, #0x38c] */
/* @0x25e9d0 and r3, r3, #63 */
/* @0x25e9d4 ldr r2, [r8, r2] */
/* @0x25e9d8 ldrb r3, [r2, r3] */
/* @0x25e9dc ldrb r3, [r4, r3]! */
/* @0x25e9e0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25e9e4 ldrb r1, [r4, #0x3] */
/* @0x25e9e8 ldrb r2, [r4, #0x1] */
/* @0x25e9ec sub r1, r1, #15 */
/* @0x25e9f0 ldrb r3, [r4, #0x2] */
/* @0x25e9f4 cmp r1, #1 */
/* @0x25e9f8 orr r2, r3, r2, lsl #8 */
/* @0x25e9fc movhi r1, #4 */
/* @0x25ea00 movls r1, #6 */
/* @0x25ea04 ldrb r3, [r4, r1]! */
/* @0x25ea08 add r5, r2, r5 */
/* @0x25ea0c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea10 ldr r12, [sp, #0x18] */
/* @0x25ea14 cmp r12, #0 */
/* @0x25ea18 strlt r5, [sp, #0x18] */
/* @0x25ea1c blt 0x25ea44 <_pcre_find_bracket+0x948> */
/* @0x25ea20 ldr r12, [sp, #0x14] */
/* @0x25ea24 eor r2, r12, #1 */
/* @0x25ea28 ldr r12, [sp, #0x18] */
/* @0x25ea2c cmp r5, r12 */
/* @0x25ea30 movge r2, #0 */
/* @0x25ea34 andlt r2, r2, #1 */
/* @0x25ea38 cmp r2, #0 */
/* @0x25ea3c movne r12, r5 */
/* @0x25ea40 str r12, [sp, #0x18] */
/* @0x25ea44 cmp r3, #119 */
/* @0x25ea48 bne 0x25ed50 <_pcre_find_bracket+0xc54> */
/* @0x25ea4c mov r5, #0 */
/* @0x25ea50 ldrb r3, [r4, #0x3] */
/* @0x25ea54 str r5, [sp, #0x14] */
/* @0x25ea58 add r4, r4, #3 */
/* @0x25ea5c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea60 cmp r10, #0 */
/* @0x25ea64 add r5, r5, #1 */
/* @0x25ea68 add r2, r4, #2 */
/* @0x25ea6c beq 0x25ea7c <_pcre_find_bracket+0x980> */
/* @0x25ea70 ldrb r3, [r4, #0x1] */
/* @0x25ea74 cmp r3, #191 */
/* @0x25ea78 bhi 0x25e98c <_pcre_find_bracket+0x890> */
/* @0x25ea7c ldrb r3, [r4, #0x2] */
/* @0x25ea80 mov r4, r2 */
/* @0x25ea84 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ea88 ldr r1, [pc, #0x2cc] */
/* @0x25ea8c ldrb r2, [r4, #0x1] */
/* @0x25ea90 ldr r1, [r8, r1] */
/* @0x25ea94 ldrb r3, [r1, r3] */
/* @0x25ea98 add r3, r3, r2 */
/* @0x25ea9c ldrb r3, [r4, r3]! */
/* @0x25eaa0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eaa4 ldr r12, [sp, #0x20] */
/* @0x25eaa8 cmp r12, #0 */
/* @0x25eaac movne r11, #0 */
/* @0x25eab0 beq 0x25ec5c <_pcre_find_bracket+0xb60> */
/* @0x25eab4 add r4, r4, #3 */
/* @0x25eab8 ldrb r3, [r4] */
/* @0x25eabc sub r2, r3, #98 */
/* @0x25eac0 uxtb r2, r2 */
/* @0x25eac4 cmp r2, #11 */
/* @0x25eac8 movhi r2, r11 */
/* @0x25eacc bhi 0x25eb00 <_pcre_find_bracket+0xa04> */
/* @0x25ead0 mov r0, #1 */
/* @0x25ead4 movw r1, #0x533 */
/* @0x25ead8 lsl r2, r0, r2 */
/* @0x25eadc and r1, r2, r1 */
/* @0x25eae0 cmp r1, #0 */
/* @0x25eae4 bne 0x25ec18 <_pcre_find_bracket+0xb1c> */
/* @0x25eae8 tst r2, #2240 */
/* @0x25eaec bne 0x25ec3c <_pcre_find_bracket+0xb40> */
/* @0x25eaf0 tst r2, #524 */
/* @0x25eaf4 mov r2, r11 */
/* @0x25eaf8 ldrbne r3, [r4, #0x1] */
/* @0x25eafc addne r4, r4, #1 */
/* @0x25eb00 add r5, r5, r2 */
/* @0x25eb04 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb08 cmp r3, #112 */
/* @0x25eb0c addne r4, r4, #33 */
/* @0x25eb10 ldrbeq r2, [r4, #0x1] */
/* @0x25eb14 ldrbeq r3, [r4, #0x2] */
/* @0x25eb18 orreq r3, r3, r2, lsl #8 */
/* @0x25eb1c addeq r4, r4, r3 */
/* @0x25eb20 ldrb r3, [r4] */
/* @0x25eb24 sub r2, r3, #98 */
/* @0x25eb28 uxtb r2, r2 */
/* @0x25eb2c cmp r2, #11 */
/* @0x25eb30 bhi 0x25eb5c <_pcre_find_bracket+0xa60> */
/* @0x25eb34 mov r0, #1 */
/* @0x25eb38 movw r1, #0x533 */
/* @0x25eb3c lsl r2, r0, r2 */
/* @0x25eb40 and r1, r2, r1 */
/* @0x25eb44 cmp r1, #0 */
/* @0x25eb48 bne 0x25ec30 <_pcre_find_bracket+0xb34> */
/* @0x25eb4c tst r2, #2240 */
/* @0x25eb50 bne 0x25ed34 <_pcre_find_bracket+0xc38> */
/* @0x25eb54 tst r2, #524 */
/* @0x25eb58 bne 0x25ec2c <_pcre_find_bracket+0xb30> */
/* @0x25eb5c add r5, r5, #1 */
/* @0x25eb60 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb64 ldrb r3, [r4, #0x1] */
/* @0x25eb68 add r5, r5, #1 */
/* @0x25eb6c sub r3, r3, #15 */
/* @0x25eb70 cmp r3, #1 */
/* @0x25eb74 movhi r3, #2 */
/* @0x25eb78 movls r3, #4 */
/* @0x25eb7c ldrb r3, [r4, r3]! */
/* @0x25eb80 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25eb84 ldrb r2, [r4, #0x3] */
/* @0x25eb88 sub r2, r2, #15 */
/* @0x25eb8c cmp r2, #1 */
/* @0x25eb90 bhi 0x25e684 <_pcre_find_bracket+0x588> */
/* @0x25eb94 ldr r2, [pc, #0x1c0] */
/* @0x25eb98 add r4, r4, #2 */
/* @0x25eb9c ldr r2, [r8, r2] */
/* @0x25eba0 ldrb r3, [r2, r3] */
/* @0x25eba4 ldrb r3, [r4, r3]! */
/* @0x25eba8 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebac ldrb r2, [r4, #0x1] */
/* @0x25ebb0 sub r2, r2, #15 */
/* @0x25ebb4 cmp r2, #1 */
/* @0x25ebb8 bls 0x25eb94 <_pcre_find_bracket+0xa98> */
/* @0x25ebbc ldr r2, [pc, #0x198] */
/* @0x25ebc0 ldr r2, [r8, r2] */
/* @0x25ebc4 ldrb r3, [r2, r3] */
/* @0x25ebc8 ldrb r3, [r4, r3]! */
/* @0x25ebcc b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebd0 ldrb r3, [r4] */
/* @0x25ebd4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebd8 ldrb r3, [r4, #0x4] */
/* @0x25ebdc mov r4, r2 */
/* @0x25ebe0 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebe4 mov r12, #1 */
/* @0x25ebe8 add r4, r4, #3 */
/* @0x25ebec str r12, [sp, #0x14] */
/* @0x25ebf0 ldrb r3, [r4] */
/* @0x25ebf4 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ebf8 ldr r5, [sp, #0x24] */
/* @0x25ebfc mov r11, #0 */
/* @0x25ec00 mov r12, #1 */
/* @0x25ec04 str r12, [sp, #0x14] */
/* @0x25ec08 add r4, r4, #5 */
/* @0x25ec0c b 0x25eab8 <_pcre_find_bracket+0x9bc> */
/* @0x25ec10 mov r11, #0 */
/* @0x25ec14 b 0x25ec08 <_pcre_find_bracket+0xb0c> */
/* @0x25ec18 ldrb r3, [r4, #0x1] */
/* @0x25ec1c mov r2, #0 */
/* @0x25ec20 add r4, r4, #1 */
/* @0x25ec24 add r5, r5, r2 */
/* @0x25ec28 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec2c add r5, r5, r0 */
/* @0x25ec30 ldrb r3, [r4, #0x1] */
/* @0x25ec34 add r4, r4, #1 */
/* @0x25ec38 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec3c ldrb r1, [r4, #0x1] */
/* @0x25ec40 add r4, r4, #5 */
/* @0x25ec44 ldrb r2, [r4, #-0x3] */
/* @0x25ec48 ldrb r3, [r4] */
/* @0x25ec4c orr r2, r2, r1, lsl #8 */
/* @0x25ec50 mul r2, r2, r11 */
/* @0x25ec54 add r5, r5, r2 */
/* @0x25ec58 b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ec5c ldrb r2, [r4, #0x1] */
/* @0x25ec60 mov r0, r7 */
/* @0x25ec64 ldrb r3, [r4, #0x2] */
/* @0x25ec68 mov r1, r10 */
/* @0x25ec6c orr r2, r3, r2, lsl #8 */
/* @0x25ec70 bl 0x25e0fc <_pcre_find_bracket> */
/* @0x25ec74 subs r12, r0, #0 */
/* @0x25ec78 beq 0x25ed2c <_pcre_find_bracket+0xc30> */
/* @0x25ec7c mov r3, r12 */
/* @0x25ec80 ldrb r1, [r3, #0x1] */
/* @0x25ec84 ldrb r2, [r3, #0x2] */
/* @0x25ec88 orr r2, r2, r1, lsl #8 */
/* @0x25ec8c ldrb r2, [r3, r2]! */
/* @0x25ec90 cmp r2, #119 */
/* @0x25ec94 beq 0x25ec80 <_pcre_find_bracket+0xb84> */
/* @0x25ec98 cmp r4, r3 */
/* @0x25ec9c movhs r3, #0 */
/* @0x25eca0 movlo r3, #1 */
/* @0x25eca4 cmp r4, r12 */
/* @0x25eca8 movls r3, #0 */
/* @0x25ecac cmp r3, #0 */
/* @0x25ecb0 bne 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecb4 cmp r6, #0 */
/* @0x25ecb8 beq 0x25ece8 <_pcre_find_bracket+0xbec> */
/* @0x25ecbc ldr r2, [r6, #0x4] */
/* @0x25ecc0 cmp r2, r12 */
/* @0x25ecc4 beq 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecc8 mov r3, r6 */
/* @0x25eccc b 0x25ecdc <_pcre_find_bracket+0xbe0> */
/* @0x25ecd0 ldr r2, [r3, #0x4] */
/* @0x25ecd4 cmp r2, r12 */
/* @0x25ecd8 beq 0x25ed1c <_pcre_find_bracket+0xc20> */
/* @0x25ecdc ldr r3, [r3] */
/* @0x25ece0 cmp r3, #0 */
/* @0x25ece4 bne 0x25ecd0 <_pcre_find_bracket+0xbd4> */
/* @0x25ece8 ldr r2, [sp, #0x5c] */
/* @0x25ecec add r0, sp, #40 */
/* @0x25ecf0 mov r1, r12 */
/* @0x25ecf4 str r0, [sp] */
/* @0x25ecf8 ldr r3, [sp, #0xc] */
/* @0x25ecfc str r2, [sp, #0x4] */
/* @0x25ed00 mov r2, r7 */
/* @0x25ed04 ldr r0, [sp, #0x10] */
/* @0x25ed08 str r6, [sp, #0x28] */
/* @0x25ed0c str r12, [sp, #0x2c] */
/* @0x25ed10 bl 0x25e350 <_pcre_find_bracket+0x254> */
/* @0x25ed14 mov r11, r0 */
/* @0x25ed18 b 0x25eab4 <_pcre_find_bracket+0x9b8> */
/* @0x25ed1c mov r12, #1 */
/* @0x25ed20 mov r11, #0 */
/* @0x25ed24 str r12, [sp, #0x14] */
/* @0x25ed28 b 0x25eab4 <_pcre_find_bracket+0x9b8> */
/* @0x25ed2c mvn r0, #1 */
/* @0x25ed30 b 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25ed34 ldrb r1, [r4, #0x1] */
/* @0x25ed38 add r4, r4, #5 */
/* @0x25ed3c ldrb r2, [r4, #-0x3] */
/* @0x25ed40 ldrb r3, [r4] */
/* @0x25ed44 orr r2, r2, r1, lsl #8 */
/* @0x25ed48 add r5, r2, r5 */
/* @0x25ed4c b 0x25e3d8 <_pcre_find_bracket+0x2dc> */
/* @0x25ed50 ldr r0, [sp, #0x18] */
/* @0x25ed54 b 0x25e700 <_pcre_find_bracket+0x604> */
/* @0x25ed58 andseq r3, r9, r4, ror #17 */
/* @0x25ed5c .word 0xfffffb8c */
/* @0x25ed60 .word 0xfffffb90 */

/* ── FUNC 0x25ed64 · pcre_config · size=188 · insn=47 */
/* @0x25ed64 cmp r0, #13 */
/* @0x25ed68 addls pc, pc, r0, lsl #2 */
/* @0x25ed6c b 0x25ee18 <pcre_config+0xb4> */
/* @0x25ed70 b 0x25edc4 <pcre_config+0x60> */
/* @0x25ed74 b 0x25edb4 <pcre_config+0x50> */
/* @0x25ed78 b 0x25edf8 <pcre_config+0x94> */
/* @0x25ed7c b 0x25edb4 <pcre_config+0x50> */
/* @0x25ed80 b 0x25edd4 <pcre_config+0x70> */
/* @0x25ed84 b 0x25edc4 <pcre_config+0x60> */
/* @0x25ed88 b 0x25eda8 <pcre_config+0x44> */
/* @0x25ed8c b 0x25edd4 <pcre_config+0x70> */
/* @0x25ed90 b 0x25eda8 <pcre_config+0x44> */
/* @0x25ed94 b 0x25eda8 <pcre_config+0x44> */
/* @0x25ed98 b 0x25ede8 <pcre_config+0x84> */
/* @0x25ed9c b 0x25eda8 <pcre_config+0x44> */
/* @0x25eda0 b 0x25ede8 <pcre_config+0x84> */
/* @0x25eda4 b 0x25ee08 <pcre_config+0xa4> */
/* @0x25eda8 mov r0, #0 */
/* @0x25edac str r0, [r1] */
/* @0x25edb0 bx lr */
/* @0x25edb4 mov r3, #10 */
/* @0x25edb8 mov r0, #0 */
/* @0x25edbc str r3, [r1] */
/* @0x25edc0 bx lr */
/* @0x25edc4 mov r3, #1 */
/* @0x25edc8 mov r0, #0 */
/* @0x25edcc str r3, [r1] */
/* @0x25edd0 bx lr */
/* @0x25edd4 movw r3, #0x9680 */
/* @0x25edd8 mov r0, #0 */
/* @0x25eddc movt r3, #0x98 */
/* @0x25ede0 str r3, [r1] */
/* @0x25ede4 bx lr */
/* @0x25ede8 mov r3, #0 */
/* @0x25edec mvn r0, #2 */
/* @0x25edf0 str r3, [r1] */
/* @0x25edf4 bx lr */
/* @0x25edf8 mov r3, #2 */
/* @0x25edfc mov r0, #0 */
/* @0x25ee00 str r3, [r1] */
/* @0x25ee04 bx lr */
/* @0x25ee08 mov r3, #250 */
/* @0x25ee0c mov r0, #0 */
/* @0x25ee10 str r3, [r1] */
/* @0x25ee14 bx lr */
/* @0x25ee18 mvn r0, #2 */
/* @0x25ee1c bx lr */

/* ── FUNC 0x25ee20 · pcre_fullinfo · size=808 · insn=202 */
/* @0x25ee20 cmp r3, #0 */
/* @0x25ee24 cmpne r0, #0 */
/* @0x25ee28 push {r4, r5} */
/* @0x25ee2c beq 0x25f10c <pcre_fullinfo+0x2ec> */
/* @0x25ee30 cmp r1, #0 */
/* @0x25ee34 moveq r5, r1 */
/* @0x25ee38 beq 0x25ee4c <pcre_fullinfo+0x2c> */
/* @0x25ee3c ldr r12, [r1] */
/* @0x25ee40 ands r12, r12, #1 */
/* @0x25ee44 ldrne r5, [r1, #0x4] */
/* @0x25ee48 moveq r5, r12 */
/* @0x25ee4c ldr r4, [r0] */
/* @0x25ee50 movw r12, #0x5245 */
/* @0x25ee54 movt r12, #0x5043 */
/* @0x25ee58 cmp r4, r12 */
/* @0x25ee5c beq 0x25ee80 <pcre_fullinfo+0x60> */
/* @0x25ee60 movw r3, #0x4350 */
/* @0x25ee64 movt r3, #0x4552 */
/* @0x25ee68 cmp r4, r3 */
/* @0x25ee6c mvnne r2, #3 */
/* @0x25ee70 mvneq r2, #28 */
/* @0x25ee74 mov r0, r2 */
/* @0x25ee78 pop {r4, r5} */
/* @0x25ee7c bx lr */
/* @0x25ee80 ldr r12, [r0, #0xc] */
/* @0x25ee84 tst r12, #1 */
/* @0x25ee88 beq 0x25f114 <pcre_fullinfo+0x2f4> */
/* @0x25ee8c cmp r2, #25 */
/* @0x25ee90 addls pc, pc, r2, lsl #2 */
/* @0x25ee94 b 0x25f13c <pcre_fullinfo+0x31c> */
/* @0x25ee98 b 0x25ef10 <pcre_fullinfo+0xf0> */
/* @0x25ee9c b 0x25ef2c <pcre_fullinfo+0x10c> */
/* @0x25eea0 b 0x25ef3c <pcre_fullinfo+0x11c> */
/* @0x25eea4 b 0x25ef4c <pcre_fullinfo+0x12c> */
/* @0x25eea8 b 0x25ef5c <pcre_fullinfo+0x13c> */
/* @0x25eeac b 0x25ef74 <pcre_fullinfo+0x154> */
/* @0x25eeb0 b 0x25efb8 <pcre_fullinfo+0x198> */
/* @0x25eeb4 b 0x25ef98 <pcre_fullinfo+0x178> */
/* @0x25eeb8 b 0x25efa8 <pcre_fullinfo+0x188> */
/* @0x25eebc b 0x25efc8 <pcre_fullinfo+0x1a8> */
/* @0x25eec0 b 0x25f100 <pcre_fullinfo+0x2e0> */
/* @0x25eec4 b 0x25f0d8 <pcre_fullinfo+0x2b8> */
/* @0x25eec8 b 0x25f0ec <pcre_fullinfo+0x2cc> */
/* @0x25eecc b 0x25f074 <pcre_fullinfo+0x254> */
/* @0x25eed0 b 0x25f084 <pcre_fullinfo+0x264> */
/* @0x25eed4 b 0x25f094 <pcre_fullinfo+0x274> */
/* @0x25eed8 b 0x25f0b0 <pcre_fullinfo+0x290> */
/* @0x25eedc b 0x25efdc <pcre_fullinfo+0x1bc> */
/* @0x25eee0 b 0x25efe8 <pcre_fullinfo+0x1c8> */
/* @0x25eee4 b 0x25eff8 <pcre_fullinfo+0x1d8> */
/* @0x25eee8 b 0x25f00c <pcre_fullinfo+0x1ec> */
/* @0x25eeec b 0x25f028 <pcre_fullinfo+0x208> */
/* @0x25eef0 b 0x25f034 <pcre_fullinfo+0x214> */
/* @0x25eef4 b 0x25f044 <pcre_fullinfo+0x224> */
/* @0x25eef8 b 0x25f05c <pcre_fullinfo+0x23c> */
/* @0x25eefc b 0x25ef00 <pcre_fullinfo+0xe0> */
/* @0x25ef00 ubfx r12, r12, #0xf, #0x1 */
/* @0x25ef04 mov r2, #0 */
/* @0x25ef08 str r12, [r3] */
/* @0x25ef0c b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef10 ldr r0, [r0, #0x8] */
/* @0x25ef14 movw r1, #0x7a7f */
/* @0x25ef18 movt r1, #0x27ff */
/* @0x25ef1c mov r2, #0 */
/* @0x25ef20 and r1, r0, r1 */
/* @0x25ef24 str r1, [r3] */
/* @0x25ef28 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef2c ldr r1, [r0, #0x4] */
/* @0x25ef30 mov r2, #0 */
/* @0x25ef34 str r1, [r3] */
/* @0x25ef38 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef3c ldrh r1, [r0, #30] */
/* @0x25ef40 mov r2, #0 */
/* @0x25ef44 str r1, [r3] */
/* @0x25ef48 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef4c ldrh r1, [r0, #32] */
/* @0x25ef50 mov r2, #0 */
/* @0x25ef54 str r1, [r3] */
/* @0x25ef58 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef5c tst r12, #16 */
/* @0x25ef60 beq 0x25f124 <pcre_fullinfo+0x304> */
/* @0x25ef64 ldrh r2, [r0, #24] */
/* @0x25ef68 str r2, [r3] */
/* @0x25ef6c mov r2, #0 */
/* @0x25ef70 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef74 cmp r5, #0 */
/* @0x25ef78 beq 0x25ef8c <pcre_fullinfo+0x16c> */
/* @0x25ef7c ldr r2, [r5, #0x4] */
/* @0x25ef80 ands r5, r2, #1 */
/* @0x25ef84 ldrne r5, [r1, #0x4] */
/* @0x25ef88 addne r5, r5, #8 */
/* @0x25ef8c str r5, [r3] */
/* @0x25ef90 mov r2, #0 */
/* @0x25ef94 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25ef98 ldrh r1, [r0, #36] */
/* @0x25ef9c mov r2, #0 */
/* @0x25efa0 str r1, [r3] */
/* @0x25efa4 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25efa8 ldrh r1, [r0, #38] */
/* @0x25efac mov r2, #0 */
/* @0x25efb0 str r1, [r3] */
/* @0x25efb4 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25efb8 tst r12, #64 */
/* @0x25efbc beq 0x25f11c <pcre_fullinfo+0x2fc> */
/* @0x25efc0 ldrh r2, [r0, #26] */
/* @0x25efc4 b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25efc8 ldrh r1, [r0, #34] */
/* @0x25efcc mov r2, #0 */
/* @0x25efd0 add r0, r0, r1 */
/* @0x25efd4 str r0, [r3] */
/* @0x25efd8 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25efdc mov r2, #0 */
/* @0x25efe0 str r2, [r3] */
/* @0x25efe4 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25efe8 ldrh r1, [r0, #28] */
/* @0x25efec mov r2, #0 */
/* @0x25eff0 str r1, [r3] */
/* @0x25eff4 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25eff8 ands r12, r12, #16 */
/* @0x25effc ldrhne r12, [r0, #24] */
/* @0x25f000 str r12, [r3] */
/* @0x25f004 mov r2, #0 */
/* @0x25f008 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f00c tst r12, #16 */
/* @0x25f010 movne r2, #1 */
/* @0x25f014 bne 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f018 tst r12, #256 */
/* @0x25f01c moveq r2, #0 */
/* @0x25f020 movne r2, #2 */
/* @0x25f024 b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f028 ands r12, r12, #64 */
/* @0x25f02c ldrhne r12, [r0, #26] */
/* @0x25f030 b 0x25f000 <pcre_fullinfo+0x1e0> */
/* @0x25f034 ubfx r12, r12, #0x6, #0x1 */
/* @0x25f038 mov r2, #0 */
/* @0x25f03c str r12, [r3] */
/* @0x25f040 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f044 tst r12, #8192 */
/* @0x25f048 beq 0x25f134 <pcre_fullinfo+0x314> */
/* @0x25f04c ldr r1, [r0, #0x10] */
/* @0x25f050 mov r2, #0 */
/* @0x25f054 str r1, [r3] */
/* @0x25f058 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f05c tst r12, #16384 */
/* @0x25f060 beq 0x25f134 <pcre_fullinfo+0x314> */
/* @0x25f064 ldr r1, [r0, #0x14] */
/* @0x25f068 mov r2, #0 */
/* @0x25f06c str r1, [r3] */
/* @0x25f070 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f074 ubfx r12, r12, #0xa, #0x1 */
/* @0x25f078 mov r2, #0 */
/* @0x25f07c str r12, [r3] */
/* @0x25f080 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f084 ubfx r12, r12, #0xb, #0x1 */
/* @0x25f088 mov r2, #0 */
/* @0x25f08c str r12, [r3] */
/* @0x25f090 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f094 cmp r5, #0 */
/* @0x25f098 beq 0x25f11c <pcre_fullinfo+0x2fc> */
/* @0x25f09c ldr r2, [r5, #0x4] */
/* @0x25f0a0 tst r2, #2 */
/* @0x25f0a4 beq 0x25f11c <pcre_fullinfo+0x2fc> */
/* @0x25f0a8 ldr r2, [r5, #0x28] */
/* @0x25f0ac b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f0b0 cmp r1, #0 */
/* @0x25f0b4 moveq r2, r1 */
/* @0x25f0b8 beq 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f0bc ldr r2, [r1] */
/* @0x25f0c0 ands r2, r2, #64 */
/* @0x25f0c4 beq 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f0c8 ldr r2, [r1, #0x1c] */
/* @0x25f0cc adds r2, r2, #0 */
/* @0x25f0d0 movne r2, #1 */
/* @0x25f0d4 b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f0d8 ldr r1, [pc, #0x64] */
/* @0x25f0dc mov r2, #0 */
/* @0x25f0e0 ldr r1, [pc, r1] */
/* @0x25f0e4 str r1, [r3] */
/* @0x25f0e8 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f0ec eor r1, r12, #512 */
/* @0x25f0f0 mov r2, #0 */
/* @0x25f0f4 ubfx r1, r1, #0x9, #0x1 */
/* @0x25f0f8 str r1, [r3] */
/* @0x25f0fc b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f100 cmp r5, #0 */
/* @0x25f104 ldrne r5, [r5] */
/* @0x25f108 b 0x25ef8c <pcre_fullinfo+0x16c> */
/* @0x25f10c mvn r2, #1 */
/* @0x25f110 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f114 mvn r2, #27 */
/* @0x25f118 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f11c mvn r2, #0 */
/* @0x25f120 b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f124 tst r12, #256 */
/* @0x25f128 mvneq r2, #1 */
/* @0x25f12c mvnne r2, #0 */
/* @0x25f130 b 0x25ef68 <pcre_fullinfo+0x148> */
/* @0x25f134 mvn r2, #32 */
/* @0x25f138 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f13c mvn r2, #2 */
/* @0x25f140 b 0x25ee74 <pcre_fullinfo+0x54> */
/* @0x25f144 andseq r2, r9, r8, lsl #14 */

/* ── FUNC 0x25f148 · pcre_get_stringnumber · size=212 · insn=53 */
/* @0x25f148 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x25f14c sub sp, sp, #16 */
/* @0x25f150 mov r2, #8 */
/* @0x25f154 mov r7, r1 */
/* @0x25f158 add r3, sp, r2 */
/* @0x25f15c mov r1, #0 */
/* @0x25f160 mov r4, r0 */
/* @0x25f164 bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f168 subs r1, r0, #0 */
/* @0x25f16c bne 0x25f194 <pcre_get_stringnumber+0x4c> */
/* @0x25f170 ldr r3, [sp, #0x8] */
/* @0x25f174 cmp r3, #0 */
/* @0x25f178 ble 0x25f204 <pcre_get_stringnumber+0xbc> */
/* @0x25f17c mov r0, r4 */
/* @0x25f180 mov r2, #7 */
/* @0x25f184 add r3, sp, #4 */
/* @0x25f188 bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f18c subs r1, r0, #0 */
/* @0x25f190 beq 0x25f1a0 <pcre_get_stringnumber+0x58> */
/* @0x25f194 mov r0, r1 */
/* @0x25f198 add sp, sp, #16 */
/* @0x25f19c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x25f1a0 mov r0, r4 */
/* @0x25f1a4 mov r2, #9 */
/* @0x25f1a8 add r3, sp, #12 */
/* @0x25f1ac bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f1b0 cmp r0, #0 */
/* @0x25f1b4 bne 0x25f198 <pcre_get_stringnumber+0x50> */
/* @0x25f1b8 mov r5, r0 */
/* @0x25f1bc ldr r6, [sp, #0x8] */
/* @0x25f1c0 ldr r9, [sp, #0xc] */
/* @0x25f1c4 ldr r8, [sp, #0x4] */
/* @0x25f1c8 b 0x25f1f0 <pcre_get_stringnumber+0xa8> */
/* @0x25f1cc asr r4, r4, #1 */
/* @0x25f1d0 mla r10, r4, r8, r9 */
/* @0x25f1d4 add r1, r10, #2 */
/* @0x25f1d8 bl 0xb6574 <strcmp@plt> */
/* @0x25f1dc cmp r0, #0 */
/* @0x25f1e0 beq 0x25f20c <pcre_get_stringnumber+0xc4> */
/* @0x25f1e4 addgt r5, r4, #1 */
/* @0x25f1e8 movle r6, r4 */
/* @0x25f1ec strle r4, [sp, #0x8] */
/* @0x25f1f0 add r4, r5, r6 */
/* @0x25f1f4 cmp r5, r6 */
/* @0x25f1f8 mov r0, r7 */
/* @0x25f1fc add r4, r4, r4, lsr #31 */
/* @0x25f200 blt 0x25f1cc <pcre_get_stringnumber+0x84> */
/* @0x25f204 mvn r0, #6 */
/* @0x25f208 b 0x25f198 <pcre_get_stringnumber+0x50> */
/* @0x25f20c ldrb r0, [r10] */
/* @0x25f210 ldrb r3, [r10, #0x1] */
/* @0x25f214 orr r0, r3, r0, lsl #8 */
/* @0x25f218 b 0x25f198 <pcre_get_stringnumber+0x50> */

/* ── FUNC 0x25f21c · pcre_get_stringtable_entries · size=352 · insn=88 */
/* @0x25f21c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25f220 sub sp, sp, #28 */
/* @0x25f224 mov r6, r1 */
/* @0x25f228 mov r10, r2 */
/* @0x25f22c str r3, [sp] */
/* @0x25f230 mov r1, #0 */
/* @0x25f234 mov r2, #8 */
/* @0x25f238 add r3, sp, #16 */
/* @0x25f23c mov r4, r0 */
/* @0x25f240 bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f244 subs r1, r0, #0 */
/* @0x25f248 bne 0x25f270 <pcre_get_stringtable_entries+0x54> */
/* @0x25f24c ldr r3, [sp, #0x10] */
/* @0x25f250 cmp r3, #0 */
/* @0x25f254 ble 0x25f2e8 <pcre_get_stringtable_entries+0xcc> */
/* @0x25f258 mov r0, r4 */
/* @0x25f25c mov r2, #7 */
/* @0x25f260 add r3, sp, #12 */
/* @0x25f264 bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f268 subs r1, r0, #0 */
/* @0x25f26c beq 0x25f27c <pcre_get_stringtable_entries+0x60> */
/* @0x25f270 mov r0, r1 */
/* @0x25f274 add sp, sp, #28 */
/* @0x25f278 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25f27c mov r0, r4 */
/* @0x25f280 mov r2, #9 */
/* @0x25f284 add r3, sp, #20 */
/* @0x25f288 bl 0x25ee20 <pcre_fullinfo> */
/* @0x25f28c cmp r0, #0 */
/* @0x25f290 bne 0x25f274 <pcre_get_stringtable_entries+0x58> */
/* @0x25f294 ldr r2, [sp, #0x10] */
/* @0x25f298 mov r9, r0 */
/* @0x25f29c ldr r8, [sp, #0x14] */
/* @0x25f2a0 ldr r7, [sp, #0xc] */
/* @0x25f2a4 str r2, [sp, #0x4] */
/* @0x25f2a8 mov r11, r2 */
/* @0x25f2ac b 0x25f2d4 <pcre_get_stringtable_entries+0xb8> */
/* @0x25f2b0 asr r5, r5, #1 */
/* @0x25f2b4 mla r4, r5, r7, r8 */
/* @0x25f2b8 add r1, r4, #2 */
/* @0x25f2bc bl 0xb6574 <strcmp@plt> */
/* @0x25f2c0 cmp r0, #0 */
/* @0x25f2c4 beq 0x25f2f0 <pcre_get_stringtable_entries+0xd4> */
/* @0x25f2c8 addgt r9, r5, #1 */
/* @0x25f2cc movle r11, r5 */
/* @0x25f2d0 strle r5, [sp, #0x10] */
/* @0x25f2d4 add r5, r9, r11 */
/* @0x25f2d8 cmp r9, r11 */
/* @0x25f2dc mov r0, r6 */
/* @0x25f2e0 add r5, r5, r5, lsr #31 */
/* @0x25f2e4 blt 0x25f2b0 <pcre_get_stringtable_entries+0x94> */
/* @0x25f2e8 mvn r0, #6 */
/* @0x25f2ec b 0x25f274 <pcre_get_stringtable_entries+0x58> */
/* @0x25f2f0 cmp r8, r4 */
/* @0x25f2f4 bhs 0x25f374 <pcre_get_stringtable_entries+0x158> */
/* @0x25f2f8 rsb r5, r7, #2 */
/* @0x25f2fc mov r11, r4 */
/* @0x25f300 b 0x25f310 <pcre_get_stringtable_entries+0xf4> */
/* @0x25f304 rsb r11, r7, r11 */
/* @0x25f308 cmp r8, r11 */
/* @0x25f30c bhs 0x25f324 <pcre_get_stringtable_entries+0x108> */
/* @0x25f310 mov r0, r6 */
/* @0x25f314 add r1, r11, r5 */
/* @0x25f318 bl 0xb6574 <strcmp@plt> */
/* @0x25f31c cmp r0, #0 */
/* @0x25f320 beq 0x25f304 <pcre_get_stringtable_entries+0xe8> */
/* @0x25f324 ldr r2, [sp, #0x4] */
/* @0x25f328 sub r3, r2, #1 */
/* @0x25f32c mla r8, r7, r3, r8 */
/* @0x25f330 cmp r8, r4 */
/* @0x25f334 addhi r5, r7, #2 */
/* @0x25f338 bhi 0x25f34c <pcre_get_stringtable_entries+0x130> */
/* @0x25f33c b 0x25f360 <pcre_get_stringtable_entries+0x144> */
/* @0x25f340 add r4, r4, r7 */
/* @0x25f344 cmp r8, r4 */
/* @0x25f348 bls 0x25f360 <pcre_get_stringtable_entries+0x144> */
/* @0x25f34c mov r0, r6 */
/* @0x25f350 add r1, r4, r5 */
/* @0x25f354 bl 0xb6574 <strcmp@plt> */
/* @0x25f358 cmp r0, #0 */
/* @0x25f35c beq 0x25f340 <pcre_get_stringtable_entries+0x124> */
/* @0x25f360 ldr r3, [sp] */
/* @0x25f364 mov r0, r7 */
/* @0x25f368 str r11, [r10] */
/* @0x25f36c str r4, [r3] */
/* @0x25f370 b 0x25f274 <pcre_get_stringtable_entries+0x58> */
/* @0x25f374 mov r11, r4 */
/* @0x25f378 b 0x25f324 <pcre_get_stringtable_entries+0x108> */

/* ── FUNC 0x25f37c · anon_25f37c · size=168 · insn=42 */
/* @0x25f37c push {r4, r5, r6, r7, lr} */
/* @0x25f380 mov r7, r2 */
/* @0x25f384 ldr r2, [r0, #0x8] */
/* @0x25f388 mov r6, r3 */
/* @0x25f38c sub sp, sp, #12 */
/* @0x25f390 mov r12, r0 */
/* @0x25f394 tst r2, #524288 */
/* @0x25f398 mov r3, r1 */
/* @0x25f39c bne 0x25f3ac <pcre_get_stringtable_entries+0x190> */
/* @0x25f3a0 ldr r2, [r0, #0xc] */
/* @0x25f3a4 tst r2, #1024 */
/* @0x25f3a8 beq 0x25f418 <pcre_get_stringtable_entries+0x1fc> */
/* @0x25f3ac mov r1, r3 */
/* @0x25f3b0 mov r0, r12 */
/* @0x25f3b4 mov r2, sp */
/* @0x25f3b8 add r3, sp, #4 */
/* @0x25f3bc bl 0x25f21c <pcre_get_stringtable_entries> */
/* @0x25f3c0 cmp r0, #0 */
/* @0x25f3c4 ble 0x25f3fc <pcre_get_stringtable_entries+0x1e0> */
/* @0x25f3c8 ldm sp, {r1, r5} */
/* @0x25f3cc cmp r1, r5 */
/* @0x25f3d0 bhi 0x25f404 <pcre_get_stringtable_entries+0x1e8> */
/* @0x25f3d4 ldrb r12, [r1] */
/* @0x25f3d8 ldrb r4, [r1, #0x1] */
/* @0x25f3dc add r1, r1, r0 */
/* @0x25f3e0 orr r12, r4, r12, lsl #8 */
/* @0x25f3e4 cmp r12, r6 */
/* @0x25f3e8 bge 0x25f3cc <pcre_get_stringtable_entries+0x1b0> */
/* @0x25f3ec ldr r3, [r7, r12, lsl #3] */
/* @0x25f3f0 cmp r3, #0 */
/* @0x25f3f4 blt 0x25f3cc <pcre_get_stringtable_entries+0x1b0> */
/* @0x25f3f8 mov r0, r12 */
/* @0x25f3fc add sp, sp, #12 */
/* @0x25f400 pop {r4, r5, r6, r7, pc} */
/* @0x25f404 ldrb r0, [r1] */
/* @0x25f408 ldrb r3, [r1, #0x1] */
/* @0x25f40c orr r0, r3, r0, lsl #8 */
/* @0x25f410 add sp, sp, #12 */
/* @0x25f414 pop {r4, r5, r6, r7, pc} */
/* @0x25f418 bl 0x25f148 <pcre_get_stringnumber> */
/* @0x25f41c add sp, sp, #12 */
/* @0x25f420 pop {r4, r5, r6, r7, pc} */

/* ── FUNC 0x25f424 · pcre_copy_substring · size=104 · insn=26 */
/* @0x25f424 push {r3, r4, r5, lr} */
/* @0x25f428 lsr r5, r3, #31 */
/* @0x25f42c cmp r3, r2 */
/* @0x25f430 orrge r5, r5, #1 */
/* @0x25f434 ldr r12, [sp, #0x10] */
/* @0x25f438 cmp r5, #0 */
/* @0x25f43c bne 0x25f484 <pcre_copy_substring+0x60> */
/* @0x25f440 lsl r3, r3, #1 */
/* @0x25f444 add r2, r3, #1 */
/* @0x25f448 ldr r3, [r1, r3, lsl #2] */
/* @0x25f44c ldr r4, [r1, r2, lsl #2] */
/* @0x25f450 ldr r2, [sp, #0x14] */
/* @0x25f454 rsb r4, r3, r4 */
/* @0x25f458 cmp r4, r2 */
/* @0x25f45c bge 0x25f47c <pcre_copy_substring+0x58> */
/* @0x25f460 add r1, r0, r3 */
/* @0x25f464 mov r2, r4 */
/* @0x25f468 mov r0, r12 */
/* @0x25f46c bl 0xb65bc <memcpy@plt> */
/* @0x25f470 strb r5, [r0, r4] */
/* @0x25f474 mov r0, r4 */
/* @0x25f478 pop {r3, r4, r5, pc} */
/* @0x25f47c mvn r0, #5 */
/* @0x25f480 pop {r3, r4, r5, pc} */
/* @0x25f484 mvn r0, #6 */
/* @0x25f488 pop {r3, r4, r5, pc} */

/* ── FUNC 0x25f48c · pcre_copy_named_substring · size=68 · insn=17 */
/* @0x25f48c push {r4, r5, r6, r7, r8, lr} */
/* @0x25f490 mov r7, r1 */
/* @0x25f494 ldr r1, [sp, #0x18] */
/* @0x25f498 mov r4, r3 */
/* @0x25f49c mov r5, r2 */
/* @0x25f4a0 ldr r8, [sp, #0x1c] */
/* @0x25f4a4 ldr r6, [sp, #0x20] */
/* @0x25f4a8 bl 0x25f37c <pcre_get_stringtable_entries+0x160> */
/* @0x25f4ac subs r3, r0, #0 */
/* @0x25f4b0 pople {r4, r5, r6, r7, r8, pc} */
/* @0x25f4b4 str r8, [sp, #0x18] */
/* @0x25f4b8 mov r0, r7 */
/* @0x25f4bc str r6, [sp, #0x1c] */
/* @0x25f4c0 mov r1, r5 */
/* @0x25f4c4 mov r2, r4 */
/* @0x25f4c8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x25f4cc b 0x25f424 <pcre_copy_substring> */

/* ── FUNC 0x25f4d0 · pcre_get_substring_list · size=252 · insn=63 */
/* @0x25f4d0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25f4d4 lsl r6, r2, #1 */
/* @0x25f4d8 cmp r6, #0 */
/* @0x25f4dc mov r10, r2 */
/* @0x25f4e0 mov r7, r0 */
/* @0x25f4e4 mov r4, r1 */
/* @0x25f4e8 mov r8, r3 */
/* @0x25f4ec ble 0x25f5b8 <pcre_get_substring_list+0xe8> */
/* @0x25f4f0 add r2, r1, r6, lsl #2 */
/* @0x25f4f4 add r12, r1, #4 */
/* @0x25f4f8 add r2, r2, #4 */
/* @0x25f4fc mov lr, #4 */
/* @0x25f500 ldr r5, [r12] */
/* @0x25f504 add lr, lr, #5 */
/* @0x25f508 ldr r0, [r12, #-0x4] */
/* @0x25f50c add r12, r12, #8 */
/* @0x25f510 cmp r5, r0 */
/* @0x25f514 rsb r3, r0, r5 */
/* @0x25f518 addgt lr, lr, r3 */
/* @0x25f51c cmp r12, r2 */
/* @0x25f520 bne 0x25f500 <pcre_get_substring_list+0x30> */
/* @0x25f524 mov r0, lr */
/* @0x25f528 ldr r3, [pc, #0x98] */
/* @0x25f52c ldr r3, [pc, r3] */
/* @0x25f530 ldr r3, [r3] */
/* @0x25f534 blx r3 */
/* @0x25f538 subs r9, r0, #0 */
/* @0x25f53c beq 0x25f5c0 <pcre_get_substring_list+0xf0> */
/* @0x25f540 add r3, r10, #1 */
/* @0x25f544 cmp r6, #0 */
/* @0x25f548 str r9, [r8] */
/* @0x25f54c add r3, r9, r3, lsl #2 */
/* @0x25f550 ble 0x25f5ac <pcre_get_substring_list+0xdc> */
/* @0x25f554 mov r10, #0 */
/* @0x25f558 add r4, r4, #4 */
/* @0x25f55c mov r8, r10 */
/* @0x25f560 mov r11, r9 */
/* @0x25f564 ldr r2, [r4] */
/* @0x25f568 mov r5, #0 */
/* @0x25f56c ldr r1, [r4, #-0x4] */
/* @0x25f570 mov r0, r3 */
/* @0x25f574 add r10, r10, #2 */
/* @0x25f578 add r4, r4, #8 */
/* @0x25f57c cmp r2, r1 */
/* @0x25f580 rsbgt r5, r1, r2 */
/* @0x25f584 add r1, r7, r1 */
/* @0x25f588 mov r2, r5 */
/* @0x25f58c bl 0xb65bc <memcpy@plt> */
/* @0x25f590 cmp r6, r10 */
/* @0x25f594 add r5, r0, r5 */
/* @0x25f598 str r0, [r11], #4 */
/* @0x25f59c add r3, r5, #1 */
/* @0x25f5a0 strb r8, [r5] */
/* @0x25f5a4 bgt 0x25f564 <pcre_get_substring_list+0x94> */
/* @0x25f5a8 add r9, r9, r6, lsl #1 */
/* @0x25f5ac mov r0, #0 */
/* @0x25f5b0 str r0, [r9] */
/* @0x25f5b4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25f5b8 mov r0, #4 */
/* @0x25f5bc b 0x25f528 <pcre_get_substring_list+0x58> */
/* @0x25f5c0 mvn r0, #5 */
/* @0x25f5c4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25f5c8 ldrheq r2, [r9], -r8 */

/* ── FUNC 0x25f5cc · pcre_free_substring_list · size=28 · insn=7 */
/* @0x25f5cc push {r3, lr} */
/* @0x25f5d0 ldr r3, [pc, #0xc] */
/* @0x25f5d4 ldr r3, [pc, r3] */
/* @0x25f5d8 ldr r3, [r3] */
/* @0x25f5dc blx r3 */
/* @0x25f5e0 pop {r3, pc} */
/* @0x25f5e4 ldrheq r1, [r9], -r4 */

/* ── FUNC 0x25f5e8 · pcre_get_substring · size=136 · insn=34 */
/* @0x25f5e8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x25f5ec lsr r7, r3, #31 */
/* @0x25f5f0 cmp r3, r2 */
/* @0x25f5f4 orrge r7, r7, #1 */
/* @0x25f5f8 mov r4, r3 */
/* @0x25f5fc cmp r7, #0 */
/* @0x25f600 mov r9, r0 */
/* @0x25f604 mov r6, r1 */
/* @0x25f608 bne 0x25f65c <pcre_get_substring+0x74> */
/* @0x25f60c add r1, r1, r3, lsl #3 */
/* @0x25f610 ldr r3, [pc, #0x54] */
/* @0x25f614 ldr r2, [r6, r4, lsl #3] */
/* @0x25f618 ldr r5, [r1, #0x4] */
/* @0x25f61c ldr r3, [pc, r3] */
/* @0x25f620 rsb r5, r2, r5 */
/* @0x25f624 ldr r3, [r3] */
/* @0x25f628 add r0, r5, #1 */
/* @0x25f62c blx r3 */
/* @0x25f630 subs r8, r0, #0 */
/* @0x25f634 beq 0x25f664 <pcre_get_substring+0x7c> */
/* @0x25f638 ldr r1, [r6, r4, lsl #3] */
/* @0x25f63c mov r2, r5 */
/* @0x25f640 add r1, r9, r1 */
/* @0x25f644 bl 0xb65bc <memcpy@plt> */
/* @0x25f648 ldr r3, [sp, #0x20] */
/* @0x25f64c strb r7, [r8, r5] */
/* @0x25f650 mov r0, r5 */
/* @0x25f654 str r8, [r3] */
/* @0x25f658 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x25f65c mvn r0, #6 */
/* @0x25f660 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x25f664 mvn r0, #5 */
/* @0x25f668 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x25f66c andseq r2, r9, r8, asr #3 */

/* ── FUNC 0x25f670 · pcre_get_named_substring · size=60 · insn=15 */
/* @0x25f670 push {r4, r5, r6, r7, r8, lr} */
/* @0x25f674 mov r6, r1 */
/* @0x25f678 ldr r1, [sp, #0x18] */
/* @0x25f67c mov r4, r3 */
/* @0x25f680 mov r5, r2 */
/* @0x25f684 ldr r7, [sp, #0x1c] */
/* @0x25f688 bl 0x25f37c <pcre_get_stringtable_entries+0x160> */
/* @0x25f68c subs r3, r0, #0 */
/* @0x25f690 pople {r4, r5, r6, r7, r8, pc} */
/* @0x25f694 str r7, [sp, #0x18] */
/* @0x25f698 mov r0, r6 */
/* @0x25f69c mov r1, r5 */
/* @0x25f6a0 mov r2, r4 */
/* @0x25f6a4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x25f6a8 b 0x25f5e8 <pcre_get_substring> */

/* ── FUNC 0x25f6ac · pcre_free_substring · size=28 · insn=7 */
/* @0x25f6ac push {r3, lr} */
/* @0x25f6b0 ldr r3, [pc, #0xc] */
/* @0x25f6b4 ldr r3, [pc, r3] */
/* @0x25f6b8 ldr r3, [r3] */
/* @0x25f6bc blx r3 */
/* @0x25f6c0 pop {r3, pc} */
/* @0x25f6c4 ldrsbeq r0, [r9], -r4 */

/* ── FUNC 0x25f6c8 · pcre_jit_stack_alloc · size=8 · insn=2 */
/* @0x25f6c8 mov r0, #0 */
/* @0x25f6cc bx lr */

/* ── FUNC 0x25f6d0 · pcre_jit_stack_free · size=4 · insn=1 */
/* @0x25f6d0 bx lr */

/* ── FUNC 0x25f6d4 · pcre_assign_jit_stack · size=4 · insn=1 */
/* @0x25f6d4 bx lr */
