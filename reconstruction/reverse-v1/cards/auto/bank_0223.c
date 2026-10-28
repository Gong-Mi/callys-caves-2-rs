/* libyoyo.so 覆盖卡组 0223
 * 函数 0x24f7f8..0x2524f8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x24f7f8 · JS_Array_prototype_push(RValue&, CInstance*, CInstance*, int, RValue*) · size=388 · insn=97 */
/* @0x24f7f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24f7fc mov r8, r1 */
/* @0x24f800 ldr r10, [pc, #0x160] */
/* @0x24f804 mov r4, r3 */
/* @0x24f808 ldr r1, [pc, #0x15c] */
/* @0x24f80c sub sp, sp, #60 */
/* @0x24f810 ldr r10, [pc, r10] */
/* @0x24f814 mov r9, r0 */
/* @0x24f818 add r1, pc, r1 */
/* @0x24f81c ldr r0, [r8, #0x40] */
/* @0x24f820 ldr r3, [r10] */
/* @0x24f824 ldr r6, [sp, #0x60] */
/* @0x24f828 str r3, [sp, #0x34] */
/* @0x24f82c bl 0xb6574 <strcmp@plt> */
/* @0x24f830 cmp r0, #0 */
/* @0x24f834 bne 0x24f840 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x24f838 cmp r4, #1 */
/* @0x24f83c beq 0x24f928 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x24f840 add r5, sp, #4 */
/* @0x24f844 ldr r2, [pc, #0x124] */
/* @0x24f848 mov r7, #0 */
/* @0x24f84c mov r0, r8 */
/* @0x24f850 mov r1, r5 */
/* @0x24f854 add r2, pc, r2 */
/* @0x24f858 mvn r11, #-16777216 */
/* @0x24f85c str r7, [sp, #0x4] */
/* @0x24f860 str r7, [sp, #0x8] */
/* @0x24f864 str r7, [sp, #0xc] */
/* @0x24f868 str r11, [sp, #0x10] */
/* @0x24f86c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24f870 mov r0, r5 */
/* @0x24f874 mov r1, r7 */
/* @0x24f878 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x24f87c cmp r4, r7 */
/* @0x24f880 str r7, [r9] */
/* @0x24f884 str r7, [r9, #0x4] */
/* @0x24f888 str r7, [r9, #0x8] */
/* @0x24f88c str r11, [r9, #0xc] */
/* @0x24f890 mov r5, r0 */
/* @0x24f894 ble 0x24f94c <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x24f898 ldr r11, [pc, #0xd4] */
/* @0x24f89c add r4, r0, r4 */
/* @0x24f8a0 add r7, sp, #20 */
/* @0x24f8a4 add r11, pc, r11 */
/* @0x24f8a8 mov r3, r5 */
/* @0x24f8ac mov r1, #32 */
/* @0x24f8b0 mov r2, r11 */
/* @0x24f8b4 mov r0, r7 */
/* @0x24f8b8 bl 0xb65c8 <snprintf@plt> */
/* @0x24f8bc add r5, r5, #1 */
/* @0x24f8c0 mov r1, r6 */
/* @0x24f8c4 mov r0, r8 */
/* @0x24f8c8 mov r2, r7 */
/* @0x24f8cc mov r3, #0 */
/* @0x24f8d0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f8d4 cmp r5, r4 */
/* @0x24f8d8 add r6, r6, #16 */
/* @0x24f8dc bne 0x24f8a8 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x24f8e0 vmov s15, r4 */
/* @0x24f8e4 ldr r2, [pc, #0x8c] */
/* @0x24f8e8 mov r3, #0 */
/* @0x24f8ec mov r0, r8 */
/* @0x24f8f0 vcvt.f64.u32 d7, s15 */
/* @0x24f8f4 str r3, [r9, #0xc] */
/* @0x24f8f8 mov r1, r9 */
/* @0x24f8fc add r2, pc, r2 */
/* @0x24f900 vmov r4, r5, d7 */
/* @0x24f904 vstr s14, [r9] */
/* @0x24f908 str r5, [r9, #0x4] */
/* @0x24f90c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24f910 ldr r2, [sp, #0x34] */
/* @0x24f914 ldr r3, [r10] */
/* @0x24f918 cmp r2, r3 */
/* @0x24f91c bne 0x24f964 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x24f920 add sp, sp, #60 */
/* @0x24f924 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24f928 ldr r3, [r8, #0x4] */
/* @0x24f92c cmp r3, #0 */
/* @0x24f930 beq 0x24f954 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x24f934 add r0, r3, #16 */
/* @0x24f938 ldr r0, [r0] */
/* @0x24f93c mov r2, r6 */
/* @0x24f940 ldr r1, [r0, #0x24] */
/* @0x24f944 bl 0x247904 <_Z13SetArrayEntryP12YYObjectBasejP6RValue> */
/* @0x24f948 b 0x24f910 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x24f94c mov r4, r0 */
/* @0x24f950 b 0x24f8e0 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x24f954 mov r0, r8 */
/* @0x24f958 mov r1, r4 */
/* @0x24f95c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x24f960 b 0x24f938 <_Z23JS_Array_prototype_pushR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x24f964 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24f968 andseq lr, r9, r0, asr #2 */
/* @0x24f96c andeq r5, lr, r0, lsl #2 */
/* @0x24f970 andeq r1, lr, r8, lsl r0 */
/* @0x24f974 ldrheq r6, [r0], -r12 */
/* @0x24f978 andeq r0, lr, r0, ror pc */

/* ── FUNC 0x24f97c · JS_Array_prototype_reverse(RValue&, CInstance*, CInstance*, int, RValue*) · size=652 · insn=163 */
/* @0x24f97c ldr r12, [pc, #0x278] */
/* @0x24f980 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24f984 ldr r12, [pc, r12] */
/* @0x24f988 sub sp, sp, #148 */
/* @0x24f98c ldr r2, [pc, #0x26c] */
/* @0x24f990 ldr r3, [r12] */
/* @0x24f994 add r6, sp, #28 */
/* @0x24f998 mov r5, #0 */
/* @0x24f99c str r0, [sp, #0x10] */
/* @0x24f9a0 add r2, pc, r2 */
/* @0x24f9a4 mov r0, r1 */
/* @0x24f9a8 mov r4, r1 */
/* @0x24f9ac mov r1, r6 */
/* @0x24f9b0 str r12, [sp, #0x14] */
/* @0x24f9b4 mvn r8, #-16777216 */
/* @0x24f9b8 str r3, [sp, #0x8c] */
/* @0x24f9bc str r5, [sp, #0x1c] */
/* @0x24f9c0 str r5, [sp, #0x20] */
/* @0x24f9c4 str r5, [sp, #0x24] */
/* @0x24f9c8 str r8, [sp, #0x28] */
/* @0x24f9cc bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24f9d0 mov r0, r6 */
/* @0x24f9d4 mov r1, r5 */
/* @0x24f9d8 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x24f9dc lsrs r12, r0, #1 */
/* @0x24f9e0 str r12, [sp, #0x8] */
/* @0x24f9e4 beq 0x24fb60 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x24f9e8 ldr r9, [pc, #0x214] */
/* @0x24f9ec add r12, sp, #44 */
/* @0x24f9f0 sub r0, r0, #1 */
/* @0x24f9f4 str r12, [sp] */
/* @0x24f9f8 add r9, pc, r9 */
/* @0x24f9fc add r12, sp, #60 */
/* @0x24fa00 str r0, [sp, #0xc] */
/* @0x24fa04 add r7, sp, #76 */
/* @0x24fa08 add r6, sp, #108 */
/* @0x24fa0c str r12, [sp, #0x4] */
/* @0x24fa10 mov r11, r5 */
/* @0x24fa14 b 0x24fa88 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x24fa18 eor r1, r10, #1 */
/* @0x24fa1c and r1, r0, r1 */
/* @0x24fa20 ands r1, r1, #255 */
/* @0x24fa24 bne 0x24fba4 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x24fa28 eor r0, r0, #1 */
/* @0x24fa2c and r2, r10, r0 */
/* @0x24fa30 tst r2, #255 */
/* @0x24fa34 bne 0x24fbcc <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x24fa38 ldr r3, [sp, #0x38] */
/* @0x24fa3c sub r3, r3, #1 */
/* @0x24fa40 bic r3, r3, #-16777216 */
/* @0x24fa44 bic r3, r3, #3 */
/* @0x24fa48 cmp r3, #0 */
/* @0x24fa4c beq 0x24fb98 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x24fa50 ldr r3, [sp, #0x48] */
/* @0x24fa54 mov r2, #5 */
/* @0x24fa58 str r11, [sp, #0x34] */
/* @0x24fa5c sub r3, r3, #1 */
/* @0x24fa60 str r2, [sp, #0x38] */
/* @0x24fa64 bic r3, r3, #-16777216 */
/* @0x24fa68 str r11, [sp, #0x2c] */
/* @0x24fa6c bic r3, r3, #3 */
/* @0x24fa70 cmp r3, #0 */
/* @0x24fa74 beq 0x24fb48 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x24fa78 ldr r12, [sp, #0x8] */
/* @0x24fa7c add r5, r5, #1 */
/* @0x24fa80 cmp r5, r12 */
/* @0x24fa84 beq 0x24fb60 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x24fa88 ldr r12, [sp, #0xc] */
/* @0x24fa8c mov r1, #32 */
/* @0x24fa90 mov r2, r9 */
/* @0x24fa94 mov r0, r7 */
/* @0x24fa98 rsb r3, r5, r12 */
/* @0x24fa9c bl 0xb65c8 <snprintf@plt> */
/* @0x24faa0 mov r3, r5 */
/* @0x24faa4 mov r1, #32 */
/* @0x24faa8 mov r2, r9 */
/* @0x24faac mov r0, r6 */
/* @0x24fab0 bl 0xb65c8 <snprintf@plt> */
/* @0x24fab4 mov r0, r4 */
/* @0x24fab8 add r1, sp, #44 */
/* @0x24fabc mov r2, r7 */
/* @0x24fac0 str r11, [sp, #0x2c] */
/* @0x24fac4 str r11, [sp, #0x30] */
/* @0x24fac8 str r11, [sp, #0x34] */
/* @0x24facc str r8, [sp, #0x38] */
/* @0x24fad0 str r11, [sp, #0x3c] */
/* @0x24fad4 str r11, [sp, #0x40] */
/* @0x24fad8 str r11, [sp, #0x44] */
/* @0x24fadc str r8, [sp, #0x48] */
/* @0x24fae0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24fae4 mov r2, r6 */
/* @0x24fae8 mov r0, r4 */
/* @0x24faec add r1, sp, #60 */
/* @0x24faf0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24faf4 mov r1, r6 */
/* @0x24faf8 mov r0, r4 */
/* @0x24fafc bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x24fb00 mov r1, r7 */
/* @0x24fb04 mov r10, r0 */
/* @0x24fb08 mov r0, r4 */
/* @0x24fb0c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x24fb10 and r3, r0, r10 */
/* @0x24fb14 ands r3, r3, #255 */
/* @0x24fb18 beq 0x24fa18 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x24fb1c mov r0, r4 */
/* @0x24fb20 add r1, sp, #60 */
/* @0x24fb24 mov r2, r7 */
/* @0x24fb28 mov r3, #0 */
/* @0x24fb2c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fb30 mov r0, r4 */
/* @0x24fb34 add r1, sp, #44 */
/* @0x24fb38 mov r2, r6 */
/* @0x24fb3c mov r3, #0 */
/* @0x24fb40 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fb44 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24fb48 add r0, sp, #60 */
/* @0x24fb4c add r5, r5, #1 */
/* @0x24fb50 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24fb54 ldr r12, [sp, #0x8] */
/* @0x24fb58 cmp r5, r12 */
/* @0x24fb5c bne 0x24fa88 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x10c> */
/* @0x24fb60 ldr r12, [sp, #0x10] */
/* @0x24fb64 mov r0, #6 */
/* @0x24fb68 ldr r1, [sp, #0x8c] */
/* @0x24fb6c mov r3, #0 */
/* @0x24fb70 str r4, [r12] */
/* @0x24fb74 ldr r12, [sp, #0x14] */
/* @0x24fb78 ldr r2, [r12] */
/* @0x24fb7c ldr r12, [sp, #0x10] */
/* @0x24fb80 cmp r1, r2 */
/* @0x24fb84 str r0, [r12, #0xc] */
/* @0x24fb88 str r3, [r12, #0x8] */
/* @0x24fb8c bne 0x24fbf8 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x24fb90 add sp, sp, #148 */
/* @0x24fb94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24fb98 add r0, sp, #44 */
/* @0x24fb9c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24fba0 b 0x24fa50 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x24fba4 mov r0, r4 */
/* @0x24fba8 add r1, sp, #44 */
/* @0x24fbac mov r2, r6 */
/* @0x24fbb0 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fbb4 mov r0, r4 */
/* @0x24fbb8 ldr r1, [sp, #0x10] */
/* @0x24fbbc mov r2, r7 */
/* @0x24fbc0 mov r3, #1 */
/* @0x24fbc4 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x24fbc8 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24fbcc mov r3, r1 */
/* @0x24fbd0 mov r0, r4 */
/* @0x24fbd4 add r1, sp, #60 */
/* @0x24fbd8 mov r2, r7 */
/* @0x24fbdc bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fbe0 mov r0, r4 */
/* @0x24fbe4 ldr r1, [sp, #0x10] */
/* @0x24fbe8 mov r2, r6 */
/* @0x24fbec mov r3, #1 */
/* @0x24fbf0 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x24fbf4 b 0x24fa38 <_Z26JS_Array_prototype_reverseR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x24fbf8 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x24fbfc andseq sp, r9, r12, asr #31 */
/* @0x24fc00 andeq r0, lr, r12, asr #29 */
/* @0x24fc04 andseq r6, r0, r8, ror #8 */

/* ── FUNC 0x24fc08 · JS_Array_prototype_shift(RValue&, CInstance*, CInstance*, int, RValue*) · size=1116 · insn=279 */
/* @0x24fc08 ldr r2, [pc, #0x43c] */
/* @0x24fc0c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x24fc10 sub sp, sp, #132 */
/* @0x24fc14 ldr r2, [pc, r2] */
/* @0x24fc18 add r3, sp, #12 */
/* @0x24fc1c ldr r8, [pc, #0x42c] */
/* @0x24fc20 mov r5, r1 */
/* @0x24fc24 str r3, [sp, #0x4] */
/* @0x24fc28 mov r1, r3 */
/* @0x24fc2c add r8, pc, r8 */
/* @0x24fc30 ldr r3, [r2] */
/* @0x24fc34 mov r4, #0 */
/* @0x24fc38 str r2, [sp] */
/* @0x24fc3c mov r6, r0 */
/* @0x24fc40 mov r2, r8 */
/* @0x24fc44 mov r0, r5 */
/* @0x24fc48 str r3, [sp, #0x7c] */
/* @0x24fc4c mvn r7, #-16777216 */
/* @0x24fc50 str r4, [sp, #0xc] */
/* @0x24fc54 str r4, [sp, #0x10] */
/* @0x24fc58 str r4, [sp, #0x14] */
/* @0x24fc5c str r7, [sp, #0x18] */
/* @0x24fc60 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24fc64 add r0, sp, #12 */
/* @0x24fc68 mov r1, r4 */
/* @0x24fc6c bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x24fc70 mov r3, #5 */
/* @0x24fc74 str r3, [r6, #0xc] */
/* @0x24fc78 subs r11, r0, #0 */
/* @0x24fc7c mov r0, r5 */
/* @0x24fc80 beq 0x24fd44 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x24fc84 ldr r2, [pc, #0x3c8] */
/* @0x24fc88 add r1, sp, #44 */
/* @0x24fc8c str r4, [sp, #0x1c] */
/* @0x24fc90 add r2, pc, r2 */
/* @0x24fc94 str r4, [sp, #0x20] */
/* @0x24fc98 str r4, [sp, #0x24] */
/* @0x24fc9c str r7, [sp, #0x28] */
/* @0x24fca0 str r4, [sp, #0x2c] */
/* @0x24fca4 str r4, [sp, #0x30] */
/* @0x24fca8 str r4, [sp, #0x34] */
/* @0x24fcac str r7, [sp, #0x38] */
/* @0x24fcb0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24fcb4 ldr r2, [r6, #0xc] */
/* @0x24fcb8 and r3, r2, r7 */
/* @0x24fcbc cmp r3, #1 */
/* @0x24fcc0 beq 0x24fecc <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x24fcc4 cmp r3, #2 */
/* @0x24fcc8 bne 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x24fccc sub r3, r2, #1 */
/* @0x24fcd0 bic r3, r3, #-16777216 */
/* @0x24fcd4 bic r3, r3, #3 */
/* @0x24fcd8 cmp r3, #0 */
/* @0x24fcdc beq 0x24ffac <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3a4> */
/* @0x24fce0 ldr r2, [sp, #0x38] */
/* @0x24fce4 mov r0, #0 */
/* @0x24fce8 ldr r1, [sp, #0x34] */
/* @0x24fcec bic r3, r2, #-16777216 */
/* @0x24fcf0 str r0, [r6] */
/* @0x24fcf4 str r2, [r6, #0xc] */
/* @0x24fcf8 str r1, [r6, #0x8] */
/* @0x24fcfc cmp r3, #14 */
/* @0x24fd00 addls pc, pc, r3, lsl #2 */
/* @0x24fd04 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd08 b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x24fd0c b 0x24ff5c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x354> */
/* @0x24fd10 b 0x24ff30 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x328> */
/* @0x24fd14 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x24fd18 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd1c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd20 b 0x24ff10 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x24fd24 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x24fd28 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd2c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd30 b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x24fd34 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd38 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24fd3c b 0x24ff00 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x24fd40 b 0x24fd7c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x24fd44 add r1, sp, #12 */
/* @0x24fd48 mov r2, r8 */
/* @0x24fd4c mov r3, r11 */
/* @0x24fd50 str r11, [sp, #0x18] */
/* @0x24fd54 str r11, [sp, #0xc] */
/* @0x24fd58 str r11, [sp, #0x10] */
/* @0x24fd5c bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fd60 ldr r1, [sp] */
/* @0x24fd64 ldr r2, [sp, #0x7c] */
/* @0x24fd68 ldr r3, [r1] */
/* @0x24fd6c cmp r2, r3 */
/* @0x24fd70 bne 0x250048 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x440> */
/* @0x24fd74 add sp, sp, #132 */
/* @0x24fd78 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x24fd7c ldr r3, [sp, #0x2c] */
/* @0x24fd80 str r3, [r6] */
/* @0x24fd84 cmp r11, #1 */
/* @0x24fd88 bls 0x24fe5c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x24fd8c ldr r9, [pc, #0x2c4] */
/* @0x24fd90 add r6, sp, #60 */
/* @0x24fd94 add r10, sp, #28 */
/* @0x24fd98 add r8, sp, #92 */
/* @0x24fd9c add r9, pc, r9 */
/* @0x24fda0 mov r4, #1 */
/* @0x24fda4 mov r7, #0 */
/* @0x24fda8 b 0x24fdfc <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x24fdac mov r2, r6 */
/* @0x24fdb0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x24fdb4 mov r0, r5 */
/* @0x24fdb8 mov r1, r10 */
/* @0x24fdbc mov r2, r8 */
/* @0x24fdc0 mov r3, #0 */
/* @0x24fdc4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fdc8 ldr r3, [sp, #0x28] */
/* @0x24fdcc sub r3, r3, #1 */
/* @0x24fdd0 bic r3, r3, #-16777216 */
/* @0x24fdd4 bic r3, r3, #3 */
/* @0x24fdd8 cmp r3, #0 */
/* @0x24fddc beq 0x24fe50 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x24fde0 add r4, r4, #1 */
/* @0x24fde4 mov r1, #5 */
/* @0x24fde8 cmp r4, r11 */
/* @0x24fdec str r7, [sp, #0x24] */
/* @0x24fdf0 str r1, [sp, #0x28] */
/* @0x24fdf4 str r7, [sp, #0x1c] */
/* @0x24fdf8 beq 0x24fe64 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x24fdfc mov r1, #32 */
/* @0x24fe00 mov r2, r9 */
/* @0x24fe04 mov r3, r4 */
/* @0x24fe08 mov r0, r6 */
/* @0x24fe0c bl 0xb65c8 <snprintf@plt> */
/* @0x24fe10 mov r1, #32 */
/* @0x24fe14 mov r2, r9 */
/* @0x24fe18 sub r3, r4, #1 */
/* @0x24fe1c mov r0, r8 */
/* @0x24fe20 bl 0xb65c8 <snprintf@plt> */
/* @0x24fe24 mov r1, r6 */
/* @0x24fe28 mov r0, r5 */
/* @0x24fe2c bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x24fe30 mov r1, r10 */
/* @0x24fe34 cmp r0, #0 */
/* @0x24fe38 mov r0, r5 */
/* @0x24fe3c bne 0x24fdac <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x24fe40 mov r2, r8 */
/* @0x24fe44 mov r3, #1 */
/* @0x24fe48 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x24fe4c b 0x24fdc8 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x24fe50 mov r0, r10 */
/* @0x24fe54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24fe58 b 0x24fde0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x24fe5c add r6, sp, #60 */
/* @0x24fe60 add r10, sp, #28 */
/* @0x24fe64 sub r11, r11, #1 */
/* @0x24fe68 ldr r2, [pc, #0x1ec] */
/* @0x24fe6c mov r0, r6 */
/* @0x24fe70 mov r1, #32 */
/* @0x24fe74 mov r3, r11 */
/* @0x24fe78 add r2, pc, r2 */
/* @0x24fe7c bl 0xb65c8 <snprintf@plt> */
/* @0x24fe80 mov r0, r5 */
/* @0x24fe84 mov r1, r10 */
/* @0x24fe88 mov r2, r6 */
/* @0x24fe8c mov r3, #1 */
/* @0x24fe90 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x24fe94 vmov s15, r11 */
/* @0x24fe98 ldr r2, [pc, #0x1c0] */
/* @0x24fe9c mov r12, #0 */
/* @0x24fea0 vcvt.f64.u32 d7, s15 */
/* @0x24fea4 mov r0, r5 */
/* @0x24fea8 add r1, sp, #12 */
/* @0x24feac mov r3, r12 */
/* @0x24feb0 add r2, pc, r2 */
/* @0x24feb4 str r12, [sp, #0x18] */
/* @0x24feb8 vmov r6, r7, d7 */
/* @0x24febc vstr s14, [sp, #12] */
/* @0x24fec0 str r7, [sp, #0x10] */
/* @0x24fec4 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x24fec8 b 0x24fd60 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x24fecc ldr r4, [r6] */
/* @0x24fed0 cmp r4, #0 */
/* @0x24fed4 beq 0x24fef4 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2ec> */
/* @0x24fed8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24fedc ldr r7, [r4, #0x4] */
/* @0x24fee0 sub r7, r7, #1 */
/* @0x24fee4 str r7, [r4, #0x4] */
/* @0x24fee8 cmp r7, #0 */
/* @0x24feec beq 0x24ff74 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x36c> */
/* @0x24fef0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24fef4 mov r3, #0 */
/* @0x24fef8 str r3, [r6] */
/* @0x24fefc b 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x24ff00 ldr r2, [sp, #0x2c] */
/* @0x24ff04 ldr r3, [sp, #0x30] */
/* @0x24ff08 stm r6, {r2, r3} */
/* @0x24ff0c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24ff10 ldr r3, [sp, #0x2c] */
/* @0x24ff14 cmp r3, #0 */
/* @0x24ff18 str r3, [r6] */
/* @0x24ff1c beq 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24ff20 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x24ff24 ldr r1, [sp, #0x2c] */
/* @0x24ff28 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x24ff2c b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24ff30 ldr r3, [sp, #0x2c] */
/* @0x24ff34 cmp r3, #0 */
/* @0x24ff38 str r3, [r6] */
/* @0x24ff3c beq 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24ff40 ldr r1, [r3, #0x8] */
/* @0x24ff44 ldr r2, [r3] */
/* @0x24ff48 cmp r1, #0 */
/* @0x24ff4c streq r6, [r3, #0x8] */
/* @0x24ff50 add r2, r2, #1 */
/* @0x24ff54 str r2, [r3] */
/* @0x24ff58 b 0x24fd84 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x24ff5c ldr r3, [sp, #0x2c] */
/* @0x24ff60 cmp r3, #0 */
/* @0x24ff64 ldrne r2, [r3, #0x4] */
/* @0x24ff68 addne r2, r2, #1 */
/* @0x24ff6c strne r2, [r3, #0x4] */
/* @0x24ff70 b 0x24fd80 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x24ff74 ldr r0, [r4] */
/* @0x24ff78 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ff7c str r7, [r4] */
/* @0x24ff80 str r7, [r4, #0x8] */
/* @0x24ff84 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ff88 ldr r7, [r4, #0x4] */
/* @0x24ff8c sub r7, r7, #1 */
/* @0x24ff90 str r7, [r4, #0x4] */
/* @0x24ff94 cmp r7, #0 */
/* @0x24ff98 beq 0x24ffb8 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3b0> */
/* @0x24ff9c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24ffa0 mov r0, r4 */
/* @0x24ffa4 bl 0x27d1d0 <_ZdlPv> */
/* @0x24ffa8 b 0x24fef0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x2e8> */
/* @0x24ffac mov r0, r6 */
/* @0x24ffb0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x24ffb4 b 0x24fce0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x24ffb8 ldr r0, [r4] */
/* @0x24ffbc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24ffc0 str r7, [r4] */
/* @0x24ffc4 str r7, [r4, #0x8] */
/* @0x24ffc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x24ffcc ldr r7, [r4, #0x4] */
/* @0x24ffd0 sub r7, r7, #1 */
/* @0x24ffd4 str r7, [r4, #0x4] */
/* @0x24ffd8 cmp r7, #0 */
/* @0x24ffdc beq 0x24fff0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3e8> */
/* @0x24ffe0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x24ffe4 mov r0, r4 */
/* @0x24ffe8 bl 0x27d1d0 <_ZdlPv> */
/* @0x24ffec b 0x24ff9c <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x394> */
/* @0x24fff0 ldr r0, [r4] */
/* @0x24fff4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x24fff8 str r7, [r4] */
/* @0x24fffc str r7, [r4, #0x8] */
/* @0x250000 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x250004 ldr r7, [r4, #0x4] */
/* @0x250008 sub r7, r7, #1 */
/* @0x25000c str r7, [r4, #0x4] */
/* @0x250010 cmp r7, #0 */
/* @0x250014 bne 0x250038 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x430> */
/* @0x250018 ldr r0, [r4] */
/* @0x25001c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x250020 mov r0, r4 */
/* @0x250024 str r7, [r4] */
/* @0x250028 str r7, [r4, #0x8] */
/* @0x25002c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x250030 mov r0, r4 */
/* @0x250034 bl 0x27d1d0 <_ZdlPv> */
/* @0x250038 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25003c mov r0, r4 */
/* @0x250040 bl 0x27d1d0 <_ZdlPv> */
/* @0x250044 b 0x24ffe0 <_Z24JS_Array_prototype_shiftR6RValueP9CInstanceS2_iPS_+0x3d8> */
/* @0x250048 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x25004c andseq sp, r9, r12, lsr sp */
/* @0x250050 andeq r0, lr, r0, asr #24 */
/* @0x250054 andeq r2, lr, r12, asr r8 */
/* @0x250058 andseq r6, r0, r4, asr #1 */
/* @0x25005c andseq r5, r0, r8, ror #31 */
/* @0x250060 strheq r0, [lr], -r12 */

/* ── FUNC 0x250064 · JS_Array_prototype_splice(RValue&, CInstance*, CInstance*, int, RValue*) · size=1516 · insn=379 */
/* @0x250064 ldr r12, [pc, #0x5c4] */
/* @0x250068 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x25006c sub sp, sp, #172 */
/* @0x250070 mov r4, #0 */
/* @0x250074 mov r5, r1 */
/* @0x250078 str r12, [sp, #0x1c] */
/* @0x25007c add r12, sp, #52 */
/* @0x250080 str r12, [sp, #0x24] */
/* @0x250084 ldr r12, [sp, #0x1c] */
/* @0x250088 ldr lr, [sp, #0xd0] */
/* @0x25008c ldr r12, [pc, r12] */
/* @0x250090 str r12, [sp, #0x1c] */
/* @0x250094 str r3, [sp, #0x14] */
/* @0x250098 mov r3, r4 */
/* @0x25009c ldr r12, [r12] */
/* @0x2500a0 str r4, [sp] */
/* @0x2500a4 str lr, [sp, #0x20] */
/* @0x2500a8 str r12, [sp, #0xa4] */
/* @0x2500ac str r0, [sp, #0x10] */
/* @0x2500b0 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x2500b4 ldr r2, [pc, #0x578] */
/* @0x2500b8 mov r0, r5 */
/* @0x2500bc add r1, sp, #52 */
/* @0x2500c0 mvn r3, #-16777216 */
/* @0x2500c4 add r2, pc, r2 */
/* @0x2500c8 str r3, [sp, #0x40] */
/* @0x2500cc str r4, [sp, #0x34] */
/* @0x2500d0 str r4, [sp, #0x38] */
/* @0x2500d4 str r4, [sp, #0x3c] */
/* @0x2500d8 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2500dc mov r1, r4 */
/* @0x2500e0 add r0, sp, #52 */
/* @0x2500e4 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x2500e8 mov r1, r4 */
/* @0x2500ec str r0, [sp, #0x18] */
/* @0x2500f0 ldr r0, [sp, #0x20] */
/* @0x2500f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2500f8 cmp r0, #0 */
/* @0x2500fc blt 0x250608 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5a4> */
/* @0x250100 ldr r2, [sp, #0x18] */
/* @0x250104 mov r3, #0 */
/* @0x250108 mov r7, r3 */
/* @0x25010c asr r3, r0, #31 */
/* @0x250110 mov r6, r2 */
/* @0x250114 mov r2, r0 */
/* @0x250118 cmp r6, r2 */
/* @0x25011c sbcs r12, r7, r3 */
/* @0x250120 movlt r2, r6 */
/* @0x250124 mov r4, r2 */
/* @0x250128 ldr r0, [sp, #0x20] */
/* @0x25012c mov r1, #1 */
/* @0x250130 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x250134 cmp r0, #0 */
/* @0x250138 movle r0, #0 */
/* @0x25013c ble 0x25014c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xe8> */
/* @0x250140 ldr r0, [sp, #0x20] */
/* @0x250144 mov r1, #1 */
/* @0x250148 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x25014c ldr r12, [sp, #0x18] */
/* @0x250150 rsb r11, r4, r12 */
/* @0x250154 cmp r0, r11 */
/* @0x250158 blt 0x250498 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x434> */
/* @0x25015c cmp r11, #0 */
/* @0x250160 beq 0x2504ac <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x448> */
/* @0x250164 ldr r6, [pc, #0x4cc] */
/* @0x250168 mov r10, #0 */
/* @0x25016c add r12, sp, #132 */
/* @0x250170 add r7, sp, #100 */
/* @0x250174 add r6, pc, r6 */
/* @0x250178 str r12, [sp, #0xc] */
/* @0x25017c add r9, sp, #84 */
/* @0x250180 mov r8, r10 */
/* @0x250184 b 0x250194 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x250188 add r10, r10, #1 */
/* @0x25018c cmp r10, r11 */
/* @0x250190 beq 0x250244 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x250194 mov r1, #32 */
/* @0x250198 mov r2, r6 */
/* @0x25019c add r3, r10, r4 */
/* @0x2501a0 mov r0, r7 */
/* @0x2501a4 bl 0xb65c8 <snprintf@plt> */
/* @0x2501a8 mov r0, r5 */
/* @0x2501ac mov r1, r7 */
/* @0x2501b0 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x2501b4 cmp r0, #0 */
/* @0x2501b8 beq 0x250188 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x2501bc mov r3, r10 */
/* @0x2501c0 mov r1, #32 */
/* @0x2501c4 mov r2, r6 */
/* @0x2501c8 add r0, sp, #132 */
/* @0x2501cc bl 0xb65c8 <snprintf@plt> */
/* @0x2501d0 mov r0, r5 */
/* @0x2501d4 mov r1, r9 */
/* @0x2501d8 mov r2, r7 */
/* @0x2501dc mvn lr, #-16777216 */
/* @0x2501e0 str r8, [sp, #0x54] */
/* @0x2501e4 str lr, [sp, #0x60] */
/* @0x2501e8 str r8, [sp, #0x58] */
/* @0x2501ec str r8, [sp, #0x5c] */
/* @0x2501f0 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2501f4 ldr r12, [sp, #0x10] */
/* @0x2501f8 mov r3, #0 */
/* @0x2501fc ldr lr, [sp, #0x5c] */
/* @0x250200 add r1, sp, #132 */
/* @0x250204 mov r2, r9 */
/* @0x250208 ldr r0, [r12] */
/* @0x25020c orr lr, lr, #7 */
/* @0x250210 str lr, [sp, #0x5c] */
/* @0x250214 bl 0x248394 <_Z20JS_DefineOwnPropertyP12YYObjectBasePKcP6RValueb> */
/* @0x250218 ldr r3, [sp, #0x60] */
/* @0x25021c sub r3, r3, #1 */
/* @0x250220 bic r3, r3, #-16777216 */
/* @0x250224 bic r3, r3, #3 */
/* @0x250228 cmp r3, #0 */
/* @0x25022c bne 0x250188 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x250230 mov r0, r9 */
/* @0x250234 add r10, r10, #1 */
/* @0x250238 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x25023c cmp r10, r11 */
/* @0x250240 bne 0x250194 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x250244 ldr r12, [sp, #0x14] */
/* @0x250248 mov r2, #0 */
/* @0x25024c mvn r3, #-16777216 */
/* @0x250250 str r2, [sp, #0x44] */
/* @0x250254 sub r12, r12, #2 */
/* @0x250258 str r2, [sp, #0x48] */
/* @0x25025c cmp r11, r12 */
/* @0x250260 str r12, [sp, #0x14] */
/* @0x250264 str r12, [sp, #0x10] */
/* @0x250268 str r2, [sp, #0x4c] */
/* @0x25026c str r3, [sp, #0x50] */
/* @0x250270 bls 0x2504d4 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x470> */
/* @0x250274 ldr r12, [sp, #0x18] */
/* @0x250278 rsb r12, r11, r12 */
/* @0x25027c str r12, [sp, #0xc] */
/* @0x250280 cmp r4, r12 */
/* @0x250284 bhs 0x250378 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x314> */
/* @0x250288 ldr r9, [pc, #0x3ac] */
/* @0x25028c add r12, sp, #68 */
/* @0x250290 add r6, sp, #132 */
/* @0x250294 str r12, [sp, #0x28] */
/* @0x250298 add r9, pc, r9 */
/* @0x25029c mov r8, r4 */
/* @0x2502a0 str r4, [sp, #0x2c] */
/* @0x2502a4 ldr r10, [sp, #0x14] */
/* @0x2502a8 b 0x250314 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x2502ac add r4, sp, #84 */
/* @0x2502b0 mov r0, r5 */
/* @0x2502b4 mov r2, r7 */
/* @0x2502b8 mov lr, #0 */
/* @0x2502bc mov r1, r4 */
/* @0x2502c0 mvn r3, #-16777216 */
/* @0x2502c4 str lr, [sp, #0x54] */
/* @0x2502c8 str lr, [sp, #0x58] */
/* @0x2502cc str lr, [sp, #0x5c] */
/* @0x2502d0 str r3, [sp, #0x60] */
/* @0x2502d4 bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x2502d8 mov r3, #0 */
/* @0x2502dc mov r0, r5 */
/* @0x2502e0 mov r1, r4 */
/* @0x2502e4 mov r2, r6 */
/* @0x2502e8 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x2502ec ldr r3, [sp, #0x60] */
/* @0x2502f0 sub r3, r3, #1 */
/* @0x2502f4 bic r3, r3, #-16777216 */
/* @0x2502f8 bic r3, r3, #3 */
/* @0x2502fc cmp r3, #0 */
/* @0x250300 beq 0x2505f0 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x58c> */
/* @0x250304 ldr r12, [sp, #0xc] */
/* @0x250308 add r8, r8, #1 */
/* @0x25030c cmp r8, r12 */
/* @0x250310 bhs 0x250374 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x310> */
/* @0x250314 mov r1, #32 */
/* @0x250318 mov r2, r9 */
/* @0x25031c add r3, r8, r11 */
/* @0x250320 mov r0, r7 */
/* @0x250324 bl 0xb65c8 <snprintf@plt> */
/* @0x250328 mov r1, #32 */
/* @0x25032c mov r2, r9 */
/* @0x250330 add r3, r10, r8 */
/* @0x250334 mov r0, r6 */
/* @0x250338 bl 0xb65c8 <snprintf@plt> */
/* @0x25033c mov r0, r5 */
/* @0x250340 mov r1, r7 */
/* @0x250344 bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x250348 cmp r0, #0 */
/* @0x25034c bne 0x2502ac <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x250350 mov r0, r5 */
/* @0x250354 add r1, sp, #68 */
/* @0x250358 mov r2, r6 */
/* @0x25035c mov r3, #1 */
/* @0x250360 bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x250364 ldr r12, [sp, #0xc] */
/* @0x250368 add r8, r8, #1 */
/* @0x25036c cmp r8, r12 */
/* @0x250370 blo 0x250314 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x250374 ldr r4, [sp, #0x2c] */
/* @0x250378 ldr r12, [sp, #0xc] */
/* @0x25037c ldr lr, [sp, #0x14] */
/* @0x250380 add r7, r12, lr */
/* @0x250384 ldr r12, [sp, #0x18] */
/* @0x250388 cmp r12, r7 */
/* @0x25038c bls 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x250390 ldr r9, [pc, #0x2a8] */
/* @0x250394 add r6, sp, #132 */
/* @0x250398 ldr r10, [sp, #0x18] */
/* @0x25039c add r8, sp, #68 */
/* @0x2503a0 add r9, pc, r9 */
/* @0x2503a4 sub r10, r10, #1 */
/* @0x2503a8 mov r1, #32 */
/* @0x2503ac mov r2, r9 */
/* @0x2503b0 mov r0, r6 */
/* @0x2503b4 mov r3, r10 */
/* @0x2503b8 bl 0xb65c8 <snprintf@plt> */
/* @0x2503bc mov r0, r5 */
/* @0x2503c0 mov r1, r8 */
/* @0x2503c4 mov r2, r6 */
/* @0x2503c8 mov r3, #1 */
/* @0x2503cc bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x2503d0 cmp r10, r7 */
/* @0x2503d4 bhi 0x2503a4 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x2503d8 ldr r12, [sp, #0x10] */
/* @0x2503dc cmp r12, #0 */
/* @0x2503e0 beq 0x250438 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x3d4> */
/* @0x2503e4 ldr r12, [sp, #0x20] */
/* @0x2503e8 add r6, sp, #132 */
/* @0x2503ec ldr r9, [pc, #0x250] */
/* @0x2503f0 add r7, r12, #32 */
/* @0x2503f4 ldr r12, [sp, #0x10] */
/* @0x2503f8 add r9, pc, r9 */
/* @0x2503fc add r8, r12, r4 */
/* @0x250400 mov r3, r4 */
/* @0x250404 mov r1, #32 */
/* @0x250408 mov r2, r9 */
/* @0x25040c mov r0, r6 */
/* @0x250410 bl 0xb65c8 <snprintf@plt> */
/* @0x250414 add r4, r4, #1 */
/* @0x250418 mov r1, r7 */
/* @0x25041c mov r0, r5 */
/* @0x250420 mov r2, r6 */
/* @0x250424 mov r3, #0 */
/* @0x250428 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x25042c cmp r4, r8 */
/* @0x250430 add r7, r7, #16 */
/* @0x250434 bne 0x250400 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x39c> */
/* @0x250438 ldr r12, [sp, #0x10] */
/* @0x25043c mov r0, r5 */
/* @0x250440 ldr lr, [sp, #0x18] */
/* @0x250444 add r1, sp, #52 */
/* @0x250448 ldr r2, [pc, #0x1f8] */
/* @0x25044c add r4, r12, lr */
/* @0x250450 mov r12, #0 */
/* @0x250454 rsb r4, r11, r4 */
/* @0x250458 mov r3, r12 */
/* @0x25045c add r2, pc, r2 */
/* @0x250460 str r12, [sp, #0x40] */
/* @0x250464 vmov s15, r4 */
/* @0x250468 vcvt.f64.u32 d7, s15 */
/* @0x25046c vmov r4, r5, d7 */
/* @0x250470 vstr s14, [sp, #52] */
/* @0x250474 str r5, [sp, #0x38] */
/* @0x250478 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x25047c ldr r12, [sp, #0x1c] */
/* @0x250480 ldr r2, [sp, #0xa4] */
/* @0x250484 ldr r3, [r12] */
/* @0x250488 cmp r2, r3 */
/* @0x25048c bne 0x25062c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5c8> */
/* @0x250490 add sp, sp, #172 */
/* @0x250494 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250498 ldr r0, [sp, #0x20] */
/* @0x25049c mov r1, #1 */
/* @0x2504a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x2504a4 cmp r0, #0 */
/* @0x2504a8 bgt 0x250618 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x5b4> */
/* @0x2504ac mov r3, #0 */
/* @0x2504b0 ldr r12, [sp, #0x14] */
/* @0x2504b4 mov r11, r3 */
/* @0x2504b8 mvn r2, #-16777216 */
/* @0x2504bc sub r12, r12, #2 */
/* @0x2504c0 str r3, [sp, #0x44] */
/* @0x2504c4 str r12, [sp, #0x10] */
/* @0x2504c8 str r3, [sp, #0x48] */
/* @0x2504cc str r3, [sp, #0x4c] */
/* @0x2504d0 str r2, [sp, #0x50] */
/* @0x2504d4 ldr r12, [sp, #0x10] */
/* @0x2504d8 cmp r12, r11 */
/* @0x2504dc bls 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2504e0 ldr r12, [sp, #0x18] */
/* @0x2504e4 rsb r8, r11, r12 */
/* @0x2504e8 cmp r4, r8 */
/* @0x2504ec bhs 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2504f0 ldr r9, [pc, #0x154] */
/* @0x2504f4 sub r12, r11, #1 */
/* @0x2504f8 ldr lr, [sp, #0x10] */
/* @0x2504fc add r1, sp, #68 */
/* @0x250500 str r11, [sp, #0x28] */
/* @0x250504 add r9, pc, r9 */
/* @0x250508 sub lr, lr, #1 */
/* @0x25050c add r7, sp, #100 */
/* @0x250510 str lr, [sp, #0xc] */
/* @0x250514 add r6, sp, #132 */
/* @0x250518 str r1, [sp, #0x14] */
/* @0x25051c mov r11, r12 */
/* @0x250520 b 0x250588 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x250524 add r10, sp, #84 */
/* @0x250528 mov r0, r5 */
/* @0x25052c mov r2, r7 */
/* @0x250530 mov lr, #0 */
/* @0x250534 mov r1, r10 */
/* @0x250538 mvn r3, #-16777216 */
/* @0x25053c str lr, [sp, #0x54] */
/* @0x250540 str lr, [sp, #0x58] */
/* @0x250544 str lr, [sp, #0x5c] */
/* @0x250548 str r3, [sp, #0x60] */
/* @0x25054c bl 0x249240 <_Z15F_JS_Object_GetP12YYObjectBaseP6RValuePKc> */
/* @0x250550 mov r3, #0 */
/* @0x250554 mov r0, r5 */
/* @0x250558 mov r1, r10 */
/* @0x25055c mov r2, r6 */
/* @0x250560 bl 0x24f118 <_Z13JS_Object_PutP12YYObjectBaseP6RValuePKcb> */
/* @0x250564 ldr r3, [sp, #0x60] */
/* @0x250568 sub r3, r3, #1 */
/* @0x25056c bic r3, r3, #-16777216 */
/* @0x250570 bic r3, r3, #3 */
/* @0x250574 cmp r3, #0 */
/* @0x250578 beq 0x2505fc <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x598> */
/* @0x25057c sub r8, r8, #1 */
/* @0x250580 cmp r4, r8 */
/* @0x250584 bhs 0x2505e8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x584> */
/* @0x250588 mov r1, #32 */
/* @0x25058c mov r2, r9 */
/* @0x250590 add r3, r11, r8 */
/* @0x250594 mov r0, r7 */
/* @0x250598 bl 0xb65c8 <snprintf@plt> */
/* @0x25059c ldr r12, [sp, #0xc] */
/* @0x2505a0 mov r1, #32 */
/* @0x2505a4 mov r2, r9 */
/* @0x2505a8 add r3, r12, r8 */
/* @0x2505ac mov r0, r6 */
/* @0x2505b0 bl 0xb65c8 <snprintf@plt> */
/* @0x2505b4 mov r0, r5 */
/* @0x2505b8 mov r1, r7 */
/* @0x2505bc bl 0x241924 <_Z14JS_HasPropertyP12YYObjectBasePKc> */
/* @0x2505c0 cmp r0, #0 */
/* @0x2505c4 bne 0x250524 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x4c0> */
/* @0x2505c8 mov r0, r5 */
/* @0x2505cc add r1, sp, #68 */
/* @0x2505d0 mov r2, r6 */
/* @0x2505d4 mov r3, #1 */
/* @0x2505d8 sub r8, r8, #1 */
/* @0x2505dc bl 0x24edf4 <_Z17JS_DeletePropertyP12YYObjectBaseP6RValuePKcb> */
/* @0x2505e0 cmp r4, r8 */
/* @0x2505e4 blo 0x250588 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x524> */
/* @0x2505e8 ldr r11, [sp, #0x28] */
/* @0x2505ec b 0x2503d8 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x2505f0 mov r0, r4 */
/* @0x2505f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x2505f8 b 0x250304 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x2505fc mov r0, r10 */
/* @0x250600 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x250604 b 0x25057c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0x518> */
/* @0x250608 ldr r12, [sp, #0x18] */
/* @0x25060c add r0, r0, r12 */
/* @0x250610 bic r4, r0, r0, asr #31 */
/* @0x250614 b 0x250128 <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x250618 ldr r0, [sp, #0x20] */
/* @0x25061c mov r1, #1 */
/* @0x250620 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x250624 mov r11, r0 */
/* @0x250628 b 0x25015c <_Z25JS_Array_prototype_spliceR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x25062c bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x250630 andseq sp, r9, r4, asr #17 */
/* @0x250634 andeq r0, lr, r8, lsr #15 */
/* @0x250638 andseq r5, r0, r12, ror #25 */
/* @0x25063c andseq r5, r0, r8, asr #23 */
/* @0x250640 andseq r5, r0, r0, asr #21 */
/* @0x250644 andseq r5, r0, r8, ror #20 */
/* @0x250648 andeq r0, lr, r0, lsl r4 */
/* @0x25064c andseq r5, r0, r12, asr r9 */

/* ── FUNC 0x250650 · F_JS_Object_getPrototypeOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x250650 cmp r3, #0 */
/* @0x250654 ldr r3, [sp] */
/* @0x250658 beq 0x25066c <_Z26F_JS_Object_getPrototypeOfR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x25065c ldr r2, [r3, #0xc] */
/* @0x250660 bic r2, r2, #-16777216 */
/* @0x250664 cmp r2, #6 */
/* @0x250668 beq 0x250678 <_Z26F_JS_Object_getPrototypeOfR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x25066c ldr r0, [pc, #0x18] */
/* @0x250670 add r0, pc, r0 */
/* @0x250674 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250678 ldr r3, [r3] */
/* @0x25067c str r2, [r0, #0xc] */
/* @0x250680 ldr r3, [r3, #0x18] */
/* @0x250684 str r3, [r0] */
/* @0x250688 bx lr */
/* @0x25068c ldrsbeq r5, [r0], -r8 */

/* ── FUNC 0x250690 · F_JS_Object_isExtensible(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x250690 cmp r3, #0 */
/* @0x250694 ldr r3, [sp] */
/* @0x250698 beq 0x2506ac <_Z24F_JS_Object_isExtensibleR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x25069c ldr r2, [r3, #0xc] */
/* @0x2506a0 bic r2, r2, #-16777216 */
/* @0x2506a4 cmp r2, #6 */
/* @0x2506a8 beq 0x2506b8 <_Z24F_JS_Object_isExtensibleR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2506ac ldr r0, [pc, #0x34] */
/* @0x2506b0 add r0, pc, r0 */
/* @0x2506b4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2506b8 ldr r3, [r3] */
/* @0x2506bc mov r2, #13 */
/* @0x2506c0 str r2, [r0, #0xc] */
/* @0x2506c4 ldr r3, [r3, #0x28] */
/* @0x2506c8 ands r3, r3, #1 */
/* @0x2506cc movne r2, #0 */
/* @0x2506d0 moveq r2, r3 */
/* @0x2506d4 movne r3, r2 */
/* @0x2506d8 movtne r2, #0x3ff0 */
/* @0x2506dc str r3, [r0] */
/* @0x2506e0 str r2, [r0, #0x4] */
/* @0x2506e4 bx lr */
/* @0x2506e8 mulseq r0, r8, r8 */

/* ── FUNC 0x2506ec · F_JS_Object_isSealed(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x2506ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2506f0 cmp r3, #0 */
/* @0x2506f4 sub sp, sp, #68 */
/* @0x2506f8 mov r10, r0 */
/* @0x2506fc ldr r6, [sp, #0x68] */
/* @0x250700 beq 0x250714 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x250704 ldr r3, [r6, #0xc] */
/* @0x250708 bic r3, r3, #-16777216 */
/* @0x25070c cmp r3, #6 */
/* @0x250710 beq 0x250728 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x250714 ldr r0, [pc, #0xac] */
/* @0x250718 add r0, pc, r0 */
/* @0x25071c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250720 add sp, sp, #68 */
/* @0x250724 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250728 ldr r4, [r6] */
/* @0x25072c add r5, sp, #36 */
/* @0x250730 mov r3, #13 */
/* @0x250734 mov r2, #1 */
/* @0x250738 mov r0, r5 */
/* @0x25073c str r3, [r10, #0xc] */
/* @0x250740 mov r1, r4 */
/* @0x250744 add r8, sp, #4 */
/* @0x250748 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x25074c mov r9, #5 */
/* @0x250750 add r7, sp, #20 */
/* @0x250754 b 0x250774 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x250758 ldr r3, [sp, #0x4] */
/* @0x25075c str r9, [sp, #0x20] */
/* @0x250760 ldr r2, [r3] */
/* @0x250764 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x250768 ldr r3, [sp, #0x1c] */
/* @0x25076c tst r3, #2 */
/* @0x250770 bne 0x2507b8 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x250774 mov r1, r8 */
/* @0x250778 mov r0, r5 */
/* @0x25077c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250780 mov r1, r7 */
/* @0x250784 subs r11, r0, #0 */
/* @0x250788 mov r0, r4 */
/* @0x25078c bne 0x250758 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x250790 ldr r0, [r6] */
/* @0x250794 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x250798 cmp r0, #0 */
/* @0x25079c streq r0, [r10] */
/* @0x2507a0 strne r11, [r10] */
/* @0x2507a4 moveq r3, #0 */
/* @0x2507a8 strne r11, [r10, #0x4] */
/* @0x2507ac movteq r3, #0x3ff0 */
/* @0x2507b0 streq r3, [r10, #0x4] */
/* @0x2507b4 b 0x250720 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2507b8 mov r3, #0 */
/* @0x2507bc str r3, [r10] */
/* @0x2507c0 str r3, [r10, #0x4] */
/* @0x2507c4 b 0x250720 <_Z20F_JS_Object_isSealedR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2507c8 andseq r5, r0, r0, lsr r8 */

/* ── FUNC 0x2507cc · F_JS_Object_isFrozen(RValue&, CInstance*, CInstance*, int, RValue*) · size=252 · insn=63 */
/* @0x2507cc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2507d0 cmp r3, #0 */
/* @0x2507d4 sub sp, sp, #68 */
/* @0x2507d8 mov r10, r0 */
/* @0x2507dc ldr r7, [sp, #0x68] */
/* @0x2507e0 beq 0x2507f4 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2507e4 ldr r3, [r7, #0xc] */
/* @0x2507e8 bic r3, r3, #-16777216 */
/* @0x2507ec cmp r3, #6 */
/* @0x2507f0 beq 0x250808 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x2507f4 ldr r0, [pc, #0xc8] */
/* @0x2507f8 add r0, pc, r0 */
/* @0x2507fc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250800 add sp, sp, #68 */
/* @0x250804 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250808 ldr r5, [r7] */
/* @0x25080c add r6, sp, #36 */
/* @0x250810 mov r3, #13 */
/* @0x250814 mov r2, #1 */
/* @0x250818 mov r0, r6 */
/* @0x25081c str r3, [r10, #0xc] */
/* @0x250820 mov r1, r5 */
/* @0x250824 add r8, sp, #4 */
/* @0x250828 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x25082c mov r9, #5 */
/* @0x250830 add r4, sp, #20 */
/* @0x250834 b 0x250840 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x250838 tst r3, #2 */
/* @0x25083c bne 0x250888 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x250840 mov r1, r8 */
/* @0x250844 mov r0, r6 */
/* @0x250848 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x25084c mov r1, r4 */
/* @0x250850 subs r11, r0, #0 */
/* @0x250854 mov r0, r5 */
/* @0x250858 beq 0x25089c <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x25085c ldr r3, [sp, #0x4] */
/* @0x250860 str r9, [sp, #0x20] */
/* @0x250864 ldr r2, [r3] */
/* @0x250868 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x25086c mov r0, r4 */
/* @0x250870 bl 0x2407e8 <_Z19JS_IsDataDescriptorP6RValue> */
/* @0x250874 ldr r3, [sp, #0x1c] */
/* @0x250878 cmp r0, #0 */
/* @0x25087c beq 0x250838 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x250880 tst r3, #4 */
/* @0x250884 beq 0x250838 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x250888 mov r3, #0 */
/* @0x25088c str r3, [r10] */
/* @0x250890 str r3, [r10, #0x4] */
/* @0x250894 add sp, sp, #68 */
/* @0x250898 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25089c ldr r0, [r7] */
/* @0x2508a0 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x2508a4 cmp r0, #0 */
/* @0x2508a8 streq r0, [r10] */
/* @0x2508ac strne r11, [r10] */
/* @0x2508b0 moveq r3, #0 */
/* @0x2508b4 strne r11, [r10, #0x4] */
/* @0x2508b8 movteq r3, #0x3ff0 */
/* @0x2508bc streq r3, [r10, #0x4] */
/* @0x2508c0 b 0x250800 <_Z20F_JS_Object_isFrozenR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2508c4 andseq r5, r0, r0, asr r7 */

/* ── FUNC 0x2508c8 · F_JS_Object_freeze(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x2508c8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2508cc cmp r3, #0 */
/* @0x2508d0 sub sp, sp, #64 */
/* @0x2508d4 mov r9, r0 */
/* @0x2508d8 ldr r6, [sp, #0x60] */
/* @0x2508dc beq 0x2508f0 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2508e0 ldr r3, [r6, #0xc] */
/* @0x2508e4 bic r3, r3, #-16777216 */
/* @0x2508e8 cmp r3, #6 */
/* @0x2508ec beq 0x250904 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x2508f0 ldr r0, [pc, #0xcc] */
/* @0x2508f4 add r0, pc, r0 */
/* @0x2508f8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2508fc add sp, sp, #64 */
/* @0x250900 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x250904 ldr r4, [r6] */
/* @0x250908 add r7, sp, #36 */
/* @0x25090c mov r2, #0 */
/* @0x250910 add r8, sp, #4 */
/* @0x250914 mov r0, r7 */
/* @0x250918 mov r10, #5 */
/* @0x25091c mov r1, r4 */
/* @0x250920 add r5, sp, #20 */
/* @0x250924 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250928 b 0x250968 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x25092c ldr r3, [sp, #0x4] */
/* @0x250930 str r10, [sp, #0x20] */
/* @0x250934 ldr r2, [r3] */
/* @0x250938 bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x25093c ldr r1, [sp, #0x4] */
/* @0x250940 ldr r12, [sp, #0x1c] */
/* @0x250944 mov r0, r4 */
/* @0x250948 mov r2, r5 */
/* @0x25094c mov r3, #1 */
/* @0x250950 ldr r1, [r1] */
/* @0x250954 bic r12, r12, #6 */
/* @0x250958 str r12, [sp, #0x1c] */
/* @0x25095c bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb> */
/* @0x250960 cmp r0, #2 */
/* @0x250964 beq 0x2509b4 <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x250968 mov r1, r8 */
/* @0x25096c mov r0, r7 */
/* @0x250970 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250974 mov r1, r5 */
/* @0x250978 cmp r0, #0 */
/* @0x25097c mov r0, r4 */
/* @0x250980 bne 0x25092c <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x250984 ldr r3, [r4, #0x28] */
/* @0x250988 bic r3, r3, #1 */
/* @0x25098c str r3, [r4, #0x28] */
/* @0x250990 ldr r0, [r6] */
/* @0x250994 ldr r1, [r6, #0x4] */
/* @0x250998 ldr r2, [r6, #0x8] */
/* @0x25099c ldr r3, [r6, #0xc] */
/* @0x2509a0 str r0, [r9] */
/* @0x2509a4 str r1, [r9, #0x4] */
/* @0x2509a8 str r2, [r9, #0x8] */
/* @0x2509ac str r3, [r9, #0xc] */
/* @0x2509b0 b 0x2508fc <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2509b4 ldr r0, [pc, #0xc] */
/* @0x2509b8 add r0, pc, r0 */
/* @0x2509bc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2509c0 b 0x2508fc <_Z18F_JS_Object_freezeR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x2509c4 andseq r5, r0, r4, asr r6 */
/* @0x2509c8 mulseq r0, r0, r5 */

/* ── FUNC 0x2509cc · F_JS_Object_seal(RValue&, CInstance*, CInstance*, int, RValue*) · size=260 · insn=65 */
/* @0x2509cc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x2509d0 cmp r3, #0 */
/* @0x2509d4 sub sp, sp, #64 */
/* @0x2509d8 mov r9, r0 */
/* @0x2509dc ldr r6, [sp, #0x60] */
/* @0x2509e0 beq 0x2509f4 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x2509e4 ldr r3, [r6, #0xc] */
/* @0x2509e8 bic r3, r3, #-16777216 */
/* @0x2509ec cmp r3, #6 */
/* @0x2509f0 beq 0x250a08 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x3c> */
/* @0x2509f4 ldr r0, [pc, #0xcc] */
/* @0x2509f8 add r0, pc, r0 */
/* @0x2509fc bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250a00 add sp, sp, #64 */
/* @0x250a04 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x250a08 ldr r4, [r6] */
/* @0x250a0c add r7, sp, #36 */
/* @0x250a10 mov r2, #0 */
/* @0x250a14 add r8, sp, #4 */
/* @0x250a18 mov r0, r7 */
/* @0x250a1c mov r10, #5 */
/* @0x250a20 mov r1, r4 */
/* @0x250a24 add r5, sp, #20 */
/* @0x250a28 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250a2c b 0x250a6c <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x250a30 ldr r3, [sp, #0x4] */
/* @0x250a34 str r10, [sp, #0x20] */
/* @0x250a38 ldr r2, [r3] */
/* @0x250a3c bl 0x241890 <_Z17JS_GetOwnPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x250a40 ldr r1, [sp, #0x4] */
/* @0x250a44 ldr r12, [sp, #0x1c] */
/* @0x250a48 mov r0, r4 */
/* @0x250a4c mov r2, r5 */
/* @0x250a50 mov r3, #1 */
/* @0x250a54 ldr r1, [r1] */
/* @0x250a58 bic r12, r12, #2 */
/* @0x250a5c str r12, [sp, #0x1c] */
/* @0x250a60 bl 0x247d44 <_Z29JS_DefineOwnProperty_InternalP12YYObjectBasePKcP6RValueb> */
/* @0x250a64 cmp r0, #2 */
/* @0x250a68 beq 0x250ab8 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x250a6c mov r1, r8 */
/* @0x250a70 mov r0, r7 */
/* @0x250a74 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250a78 mov r1, r5 */
/* @0x250a7c cmp r0, #0 */
/* @0x250a80 mov r0, r4 */
/* @0x250a84 bne 0x250a30 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0x250a88 ldr r3, [r4, #0x28] */
/* @0x250a8c bic r3, r3, #1 */
/* @0x250a90 str r3, [r4, #0x28] */
/* @0x250a94 ldr r0, [r6] */
/* @0x250a98 ldr r1, [r6, #0x4] */
/* @0x250a9c ldr r2, [r6, #0x8] */
/* @0x250aa0 ldr r3, [r6, #0xc] */
/* @0x250aa4 str r0, [r9] */
/* @0x250aa8 str r1, [r9, #0x4] */
/* @0x250aac str r2, [r9, #0x8] */
/* @0x250ab0 str r3, [r9, #0xc] */
/* @0x250ab4 b 0x250a00 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x250ab8 ldr r0, [pc, #0xc] */
/* @0x250abc add r0, pc, r0 */
/* @0x250ac0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250ac4 b 0x250a00 <_Z16F_JS_Object_sealR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x250ac8 andseq r5, r0, r0, asr r5 */
/* @0x250acc andseq r5, r0, r12, lsl #9 */

/* ── FUNC 0x250ad0 · F_JS_Object_preventExtensions(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x250ad0 cmp r3, #0 */
/* @0x250ad4 ldr r3, [sp] */
/* @0x250ad8 beq 0x250aec <_Z29F_JS_Object_preventExtensionsR6RValueP9CInstanceS2_iPS_+0x1c> */
/* @0x250adc ldr r2, [r3, #0xc] */
/* @0x250ae0 bic r2, r2, #-16777216 */
/* @0x250ae4 cmp r2, #6 */
/* @0x250ae8 beq 0x250af8 <_Z29F_JS_Object_preventExtensionsR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x250aec ldr r0, [pc, #0x38] */
/* @0x250af0 add r0, pc, r0 */
/* @0x250af4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250af8 ldr r2, [r3] */
/* @0x250afc ldr r1, [r2, #0x28] */
/* @0x250b00 bic r1, r1, #1 */
/* @0x250b04 str r1, [r2, #0x28] */
/* @0x250b08 ldr r12, [r3] */
/* @0x250b0c ldr r1, [r3, #0x4] */
/* @0x250b10 ldr r2, [r3, #0x8] */
/* @0x250b14 ldr r3, [r3, #0xc] */
/* @0x250b18 str r12, [r0] */
/* @0x250b1c str r1, [r0, #0x4] */
/* @0x250b20 str r2, [r0, #0x8] */
/* @0x250b24 str r3, [r0, #0xc] */
/* @0x250b28 bx lr */
/* @0x250b2c andseq r5, r0, r8, asr r4 */

/* ── FUNC 0x250b30 · F_JS_Object_getOwnPropertyNames(RValue&, CInstance*, CInstance*, int, RValue*) · size=888 · insn=222 */
/* @0x250b30 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x250b34 cmp r3, #0 */
/* @0x250b38 sub sp, sp, #92 */
/* @0x250b3c mov r8, r0 */
/* @0x250b40 mov r11, r1 */
/* @0x250b44 mov r9, r2 */
/* @0x250b48 ldr r5, [sp, #0x80] */
/* @0x250b4c beq 0x250b60 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x250b50 ldr r3, [r5, #0xc] */
/* @0x250b54 bic r3, r3, #-16777216 */
/* @0x250b58 cmp r3, #6 */
/* @0x250b5c beq 0x250b74 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x250b60 ldr r0, [pc, #0x33c] */
/* @0x250b64 add r0, pc, r0 */
/* @0x250b68 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250b6c add sp, sp, #92 */
/* @0x250b70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250b74 ldr r10, [r5] */
/* @0x250b78 add r7, sp, #32 */
/* @0x250b7c mov r2, #0 */
/* @0x250b80 add r6, sp, #16 */
/* @0x250b84 mov r0, r7 */
/* @0x250b88 mov r4, r2 */
/* @0x250b8c mov r1, r10 */
/* @0x250b90 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250b94 b 0x250b9c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x250b98 add r4, r4, #1 */
/* @0x250b9c mov r0, r7 */
/* @0x250ba0 mov r1, r6 */
/* @0x250ba4 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250ba8 cmp r0, #0 */
/* @0x250bac bne 0x250b98 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x250bb0 mov r3, r4 */
/* @0x250bb4 mov r0, r8 */
/* @0x250bb8 str r5, [sp] */
/* @0x250bbc mov r1, r11 */
/* @0x250bc0 mov r2, r9 */
/* @0x250bc4 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x250bc8 ldr r0, [r8] */
/* @0x250bcc ldr r3, [r0, #0x4] */
/* @0x250bd0 cmp r3, #0 */
/* @0x250bd4 beq 0x250e98 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x250bd8 add r0, r3, #16 */
/* @0x250bdc ldr r9, [r0] */
/* @0x250be0 add r8, sp, #60 */
/* @0x250be4 mov r1, r10 */
/* @0x250be8 mov r2, #0 */
/* @0x250bec mov r0, r8 */
/* @0x250bf0 mov r5, r2 */
/* @0x250bf4 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250bf8 mov r0, r9 */
/* @0x250bfc bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x250c00 mov r7, r5 */
/* @0x250c04 mov r10, #7 */
/* @0x250c08 mov r0, r8 */
/* @0x250c0c mov r1, r6 */
/* @0x250c10 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250c14 cmp r0, #0 */
/* @0x250c18 beq 0x250dc4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x250c1c ldr r4, [r9, #0x4] */
/* @0x250c20 str r10, [sp, #0x18] */
/* @0x250c24 cmp r4, #0 */
/* @0x250c28 beq 0x250ddc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x250c2c add r4, r4, r5, lsl #4 */
/* @0x250c30 ldr r2, [r4, #0xc] */
/* @0x250c34 bic r3, r2, #-16777216 */
/* @0x250c38 cmp r3, #1 */
/* @0x250c3c beq 0x250d54 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x250c40 cmp r3, #2 */
/* @0x250c44 bne 0x250c68 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x250c48 sub r2, r2, #1 */
/* @0x250c4c bic r2, r2, #-16777216 */
/* @0x250c50 bic r2, r2, #3 */
/* @0x250c54 cmp r2, #0 */
/* @0x250c58 beq 0x250dd0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x250c5c mov r3, #5 */
/* @0x250c60 str r7, [r4, #0x8] */
/* @0x250c64 str r3, [r4, #0xc] */
/* @0x250c68 ldr r3, [sp, #0x1c] */
/* @0x250c6c ldr r2, [sp, #0x18] */
/* @0x250c70 str r7, [r4] */
/* @0x250c74 str r3, [r4, #0xc] */
/* @0x250c78 ldr r3, [sp, #0x1c] */
/* @0x250c7c str r2, [r4, #0x8] */
/* @0x250c80 bic r3, r3, #-16777216 */
/* @0x250c84 cmp r3, #14 */
/* @0x250c88 addls pc, pc, r3, lsl #2 */
/* @0x250c8c b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250c90 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x250c94 b 0x250d3c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x250c98 b 0x250d10 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x250c9c b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x250ca0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250ca4 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250ca8 b 0x250cec <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x250cac b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x250cb0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250cb4 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250cb8 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x250cbc b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250cc0 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250cc4 b 0x250cdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x250cc8 b 0x250ccc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x250ccc ldr r3, [sp, #0x10] */
/* @0x250cd0 str r3, [r4] */
/* @0x250cd4 add r5, r5, #1 */
/* @0x250cd8 b 0x250c08 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x250cdc ldr r2, [sp, #0x10] */
/* @0x250ce0 ldr r3, [sp, #0x14] */
/* @0x250ce4 stm r4, {r2, r3} */
/* @0x250ce8 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250cec ldr r3, [sp, #0x10] */
/* @0x250cf0 str r3, [r4] */
/* @0x250cf4 ldr r3, [sp, #0x10] */
/* @0x250cf8 cmp r3, #0 */
/* @0x250cfc beq 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250d00 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x250d04 ldr r1, [sp, #0x10] */
/* @0x250d08 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x250d0c b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250d10 ldr r3, [sp, #0x10] */
/* @0x250d14 cmp r3, #0 */
/* @0x250d18 str r3, [r4] */
/* @0x250d1c beq 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250d20 ldr r1, [r3, #0x8] */
/* @0x250d24 ldr r2, [r3] */
/* @0x250d28 cmp r1, #0 */
/* @0x250d2c streq r4, [r3, #0x8] */
/* @0x250d30 add r2, r2, #1 */
/* @0x250d34 str r2, [r3] */
/* @0x250d38 b 0x250cd4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x250d3c ldr r3, [sp, #0x10] */
/* @0x250d40 cmp r3, #0 */
/* @0x250d44 ldrne r2, [r3, #0x4] */
/* @0x250d48 addne r2, r2, #1 */
/* @0x250d4c strne r2, [r3, #0x4] */
/* @0x250d50 b 0x250cd0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x250d54 ldr r11, [r4] */
/* @0x250d58 cmp r11, #0 */
/* @0x250d5c beq 0x250d7c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x250d60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x250d64 ldr r2, [r11, #0x4] */
/* @0x250d68 sub r2, r2, #1 */
/* @0x250d6c str r2, [r11, #0x4] */
/* @0x250d70 cmp r2, #0 */
/* @0x250d74 beq 0x250d84 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x250d78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x250d7c str r7, [r4] */
/* @0x250d80 b 0x250c68 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x250d84 ldr r0, [r11] */
/* @0x250d88 str r2, [sp, #0xc] */
/* @0x250d8c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x250d90 ldr r2, [sp, #0xc] */
/* @0x250d94 str r2, [r11] */
/* @0x250d98 str r2, [r11, #0x8] */
/* @0x250d9c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x250da0 ldr r2, [r11, #0x4] */
/* @0x250da4 sub r2, r2, #1 */
/* @0x250da8 str r2, [r11, #0x4] */
/* @0x250dac cmp r2, #0 */
/* @0x250db0 beq 0x250df0 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x250db4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x250db8 mov r0, r11 */
/* @0x250dbc bl 0x27d1d0 <_ZdlPv> */
/* @0x250dc0 b 0x250d78 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x250dc4 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x250dc8 add sp, sp, #92 */
/* @0x250dcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250dd0 mov r0, r4 */
/* @0x250dd4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x250dd8 b 0x250c5c <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x250ddc mov r0, r9 */
/* @0x250de0 mov r1, r5 */
/* @0x250de4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x250de8 mov r4, r0 */
/* @0x250dec b 0x250c30 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x250df0 ldr r0, [r11] */
/* @0x250df4 str r2, [sp, #0xc] */
/* @0x250df8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x250dfc ldr r2, [sp, #0xc] */
/* @0x250e00 str r2, [r11] */
/* @0x250e04 str r2, [r11, #0x8] */
/* @0x250e08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x250e0c ldr r2, [r11, #0x4] */
/* @0x250e10 sub r2, r2, #1 */
/* @0x250e14 str r2, [r11, #0x4] */
/* @0x250e18 cmp r2, #0 */
/* @0x250e1c beq 0x250e30 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x250e20 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x250e24 mov r0, r11 */
/* @0x250e28 bl 0x27d1d0 <_ZdlPv> */
/* @0x250e2c b 0x250db4 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x250e30 ldr r0, [r11] */
/* @0x250e34 str r2, [sp, #0xc] */
/* @0x250e38 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x250e3c ldr r2, [sp, #0xc] */
/* @0x250e40 str r2, [r11] */
/* @0x250e44 str r2, [r11, #0x8] */
/* @0x250e48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x250e4c ldr r2, [r11, #0x4] */
/* @0x250e50 sub r2, r2, #1 */
/* @0x250e54 str r2, [r11, #0x4] */
/* @0x250e58 cmp r2, #0 */
/* @0x250e5c bne 0x250e88 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x250e60 ldr r0, [r11] */
/* @0x250e64 str r2, [sp, #0xc] */
/* @0x250e68 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x250e6c ldr r2, [sp, #0xc] */
/* @0x250e70 mov r0, r11 */
/* @0x250e74 str r2, [r11] */
/* @0x250e78 str r2, [r11, #0x8] */
/* @0x250e7c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x250e80 mov r0, r11 */
/* @0x250e84 bl 0x27d1d0 <_ZdlPv> */
/* @0x250e88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x250e8c mov r0, r11 */
/* @0x250e90 bl 0x27d1d0 <_ZdlPv> */
/* @0x250e94 b 0x250e20 <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x250e98 mov r1, #1 */
/* @0x250e9c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x250ea0 b 0x250bdc <_Z31F_JS_Object_getOwnPropertyNamesR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x250ea4 andseq r5, r0, r4, ror #7 */

/* ── FUNC 0x250ea8 · F_JS_Object_keys(RValue&, CInstance*, CInstance*, int, RValue*) · size=888 · insn=222 */
/* @0x250ea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x250eac cmp r3, #0 */
/* @0x250eb0 sub sp, sp, #92 */
/* @0x250eb4 mov r8, r0 */
/* @0x250eb8 mov r11, r1 */
/* @0x250ebc mov r9, r2 */
/* @0x250ec0 ldr r5, [sp, #0x80] */
/* @0x250ec4 beq 0x250ed8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x250ec8 ldr r3, [r5, #0xc] */
/* @0x250ecc bic r3, r3, #-16777216 */
/* @0x250ed0 cmp r3, #6 */
/* @0x250ed4 beq 0x250eec <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x250ed8 ldr r0, [pc, #0x33c] */
/* @0x250edc add r0, pc, r0 */
/* @0x250ee0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x250ee4 add sp, sp, #92 */
/* @0x250ee8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x250eec ldr r10, [r5] */
/* @0x250ef0 add r7, sp, #32 */
/* @0x250ef4 mov r2, #1 */
/* @0x250ef8 mov r4, #0 */
/* @0x250efc mov r0, r7 */
/* @0x250f00 add r6, sp, #16 */
/* @0x250f04 mov r1, r10 */
/* @0x250f08 bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250f0c b 0x250f14 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x250f10 add r4, r4, #1 */
/* @0x250f14 mov r0, r7 */
/* @0x250f18 mov r1, r6 */
/* @0x250f1c bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250f20 cmp r0, #0 */
/* @0x250f24 bne 0x250f10 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x250f28 mov r3, r4 */
/* @0x250f2c mov r0, r8 */
/* @0x250f30 str r5, [sp] */
/* @0x250f34 mov r1, r11 */
/* @0x250f38 mov r2, r9 */
/* @0x250f3c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x250f40 ldr r0, [r8] */
/* @0x250f44 ldr r3, [r0, #0x4] */
/* @0x250f48 cmp r3, #0 */
/* @0x250f4c beq 0x251210 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x368> */
/* @0x250f50 add r0, r3, #16 */
/* @0x250f54 ldr r9, [r0] */
/* @0x250f58 add r8, sp, #60 */
/* @0x250f5c mov r1, r10 */
/* @0x250f60 mov r2, #1 */
/* @0x250f64 mov r0, r8 */
/* @0x250f68 mov r5, #0 */
/* @0x250f6c bl 0x2400ec <_ZN29YYObject_PropertyNameIteratorC2EP12YYObjectBasei> */
/* @0x250f70 mov r0, r9 */
/* @0x250f74 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x250f78 mov r7, r5 */
/* @0x250f7c mov r10, #7 */
/* @0x250f80 mov r0, r8 */
/* @0x250f84 mov r1, r6 */
/* @0x250f88 bl 0x24a1fc <_ZN29YYObject_PropertyNameIterator4NextEP6RValue> */
/* @0x250f8c cmp r0, #0 */
/* @0x250f90 beq 0x25113c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x250f94 ldr r4, [r9, #0x4] */
/* @0x250f98 str r10, [sp, #0x18] */
/* @0x250f9c cmp r4, #0 */
/* @0x250fa0 beq 0x251154 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x250fa4 add r4, r4, r5, lsl #4 */
/* @0x250fa8 ldr r2, [r4, #0xc] */
/* @0x250fac bic r3, r2, #-16777216 */
/* @0x250fb0 cmp r3, #1 */
/* @0x250fb4 beq 0x2510cc <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x250fb8 cmp r3, #2 */
/* @0x250fbc bne 0x250fe0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x250fc0 sub r2, r2, #1 */
/* @0x250fc4 bic r2, r2, #-16777216 */
/* @0x250fc8 bic r2, r2, #3 */
/* @0x250fcc cmp r2, #0 */
/* @0x250fd0 beq 0x251148 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x250fd4 mov r3, #5 */
/* @0x250fd8 str r7, [r4, #0x8] */
/* @0x250fdc str r3, [r4, #0xc] */
/* @0x250fe0 ldr r3, [sp, #0x1c] */
/* @0x250fe4 ldr r2, [sp, #0x18] */
/* @0x250fe8 str r7, [r4] */
/* @0x250fec str r3, [r4, #0xc] */
/* @0x250ff0 ldr r3, [sp, #0x1c] */
/* @0x250ff4 str r2, [r4, #0x8] */
/* @0x250ff8 bic r3, r3, #-16777216 */
/* @0x250ffc cmp r3, #14 */
/* @0x251000 addls pc, pc, r3, lsl #2 */
/* @0x251004 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251008 b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x25100c b 0x2510b4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x251010 b 0x251088 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x251014 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x251018 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x25101c b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251020 b 0x251064 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x251024 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x251028 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x25102c b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251030 b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x251034 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251038 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x25103c b 0x251054 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x251040 b 0x251044 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x251044 ldr r3, [sp, #0x10] */
/* @0x251048 str r3, [r4] */
/* @0x25104c add r5, r5, #1 */
/* @0x251050 b 0x250f80 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x251054 ldr r2, [sp, #0x10] */
/* @0x251058 ldr r3, [sp, #0x14] */
/* @0x25105c stm r4, {r2, r3} */
/* @0x251060 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251064 ldr r3, [sp, #0x10] */
/* @0x251068 str r3, [r4] */
/* @0x25106c ldr r3, [sp, #0x10] */
/* @0x251070 cmp r3, #0 */
/* @0x251074 beq 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251078 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x25107c ldr r1, [sp, #0x10] */
/* @0x251080 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x251084 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251088 ldr r3, [sp, #0x10] */
/* @0x25108c cmp r3, #0 */
/* @0x251090 str r3, [r4] */
/* @0x251094 beq 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251098 ldr r1, [r3, #0x8] */
/* @0x25109c ldr r2, [r3] */
/* @0x2510a0 cmp r1, #0 */
/* @0x2510a4 streq r4, [r3, #0x8] */
/* @0x2510a8 add r2, r2, #1 */
/* @0x2510ac str r2, [r3] */
/* @0x2510b0 b 0x25104c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x2510b4 ldr r3, [sp, #0x10] */
/* @0x2510b8 cmp r3, #0 */
/* @0x2510bc ldrne r2, [r3, #0x4] */
/* @0x2510c0 addne r2, r2, #1 */
/* @0x2510c4 strne r2, [r3, #0x4] */
/* @0x2510c8 b 0x251048 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x2510cc ldr r11, [r4] */
/* @0x2510d0 cmp r11, #0 */
/* @0x2510d4 beq 0x2510f4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x2510d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2510dc ldr r2, [r11, #0x4] */
/* @0x2510e0 sub r2, r2, #1 */
/* @0x2510e4 str r2, [r11, #0x4] */
/* @0x2510e8 cmp r2, #0 */
/* @0x2510ec beq 0x2510fc <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x2510f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x2510f4 str r7, [r4] */
/* @0x2510f8 b 0x250fe0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x2510fc ldr r0, [r11] */
/* @0x251100 str r2, [sp, #0xc] */
/* @0x251104 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x251108 ldr r2, [sp, #0xc] */
/* @0x25110c str r2, [r11] */
/* @0x251110 str r2, [r11, #0x8] */
/* @0x251114 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x251118 ldr r2, [r11, #0x4] */
/* @0x25111c sub r2, r2, #1 */
/* @0x251120 str r2, [r11, #0x4] */
/* @0x251124 cmp r2, #0 */
/* @0x251128 beq 0x251168 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x25112c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x251130 mov r0, r11 */
/* @0x251134 bl 0x27d1d0 <_ZdlPv> */
/* @0x251138 b 0x2510f0 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x25113c bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x251140 add sp, sp, #92 */
/* @0x251144 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251148 mov r0, r4 */
/* @0x25114c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x251150 b 0x250fd4 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x251154 mov r0, r9 */
/* @0x251158 mov r1, r5 */
/* @0x25115c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251160 mov r4, r0 */
/* @0x251164 b 0x250fa8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x251168 ldr r0, [r11] */
/* @0x25116c str r2, [sp, #0xc] */
/* @0x251170 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x251174 ldr r2, [sp, #0xc] */
/* @0x251178 str r2, [r11] */
/* @0x25117c str r2, [r11, #0x8] */
/* @0x251180 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x251184 ldr r2, [r11, #0x4] */
/* @0x251188 sub r2, r2, #1 */
/* @0x25118c str r2, [r11, #0x4] */
/* @0x251190 cmp r2, #0 */
/* @0x251194 beq 0x2511a8 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x251198 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x25119c mov r0, r11 */
/* @0x2511a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2511a4 b 0x25112c <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x2511a8 ldr r0, [r11] */
/* @0x2511ac str r2, [sp, #0xc] */
/* @0x2511b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2511b4 ldr r2, [sp, #0xc] */
/* @0x2511b8 str r2, [r11] */
/* @0x2511bc str r2, [r11, #0x8] */
/* @0x2511c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x2511c4 ldr r2, [r11, #0x4] */
/* @0x2511c8 sub r2, r2, #1 */
/* @0x2511cc str r2, [r11, #0x4] */
/* @0x2511d0 cmp r2, #0 */
/* @0x2511d4 bne 0x251200 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x358> */
/* @0x2511d8 ldr r0, [r11] */
/* @0x2511dc str r2, [sp, #0xc] */
/* @0x2511e0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x2511e4 ldr r2, [sp, #0xc] */
/* @0x2511e8 mov r0, r11 */
/* @0x2511ec str r2, [r11] */
/* @0x2511f0 str r2, [r11, #0x8] */
/* @0x2511f4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x2511f8 mov r0, r11 */
/* @0x2511fc bl 0x27d1d0 <_ZdlPv> */
/* @0x251200 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x251204 mov r0, r11 */
/* @0x251208 bl 0x27d1d0 <_ZdlPv> */
/* @0x25120c b 0x251198 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x251210 mov r1, #1 */
/* @0x251214 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251218 b 0x250f54 <_Z16F_JS_Object_keysR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x25121c andseq r5, r0, r12, rrx */

/* ── FUNC 0x251220 · F_JS_Object_prototype_toLocaleString(RValue&, CInstance*, CInstance*, int, RValue*) · size=124 · insn=31 */
/* @0x251220 push {r4, r5, r6, lr} */
/* @0x251224 sub sp, sp, #24 */
/* @0x251228 add r4, sp, #8 */
/* @0x25122c ldr r2, [pc, #0x60] */
/* @0x251230 mov r5, r1 */
/* @0x251234 mov r6, r0 */
/* @0x251238 add r2, pc, r2 */
/* @0x25123c mov r0, r1 */
/* @0x251240 mov r1, r4 */
/* @0x251244 mov r3, #5 */
/* @0x251248 str r3, [sp, #0x14] */
/* @0x25124c bl 0x2418dc <_Z14JS_GetPropertyP12YYObjectBaseP6RValuePKc> */
/* @0x251250 mov r0, r4 */
/* @0x251254 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251258 cmp r0, #0 */
/* @0x25125c beq 0x251280 <_Z36F_JS_Object_prototype_toLocaleStringR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x251260 mov r3, #0 */
/* @0x251264 mov r0, r5 */
/* @0x251268 mov r1, r6 */
/* @0x25126c mov r2, r4 */
/* @0x251270 str r3, [sp] */
/* @0x251274 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x251278 add sp, sp, #24 */
/* @0x25127c pop {r4, r5, r6, pc} */
/* @0x251280 ldr r0, [pc, #0x10] */
/* @0x251284 add r0, pc, r0 */
/* @0x251288 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25128c add sp, sp, #24 */
/* @0x251290 pop {r4, r5, r6, pc} */
/* @0x251294 ldrdeq r1, r2, [lr], -r8 */
/* @0x251298 andseq r4, r0, r4, asr #25 */

/* ── FUNC 0x25129c · JS_String_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=104 · insn=26 */
/* @0x25129c push {r4, r5, r6, lr} */
/* @0x2512a0 mov r4, r1 */
/* @0x2512a4 ldr r1, [pc, #0x4c] */
/* @0x2512a8 mov r5, r0 */
/* @0x2512ac ldr r0, [r4, #0x40] */
/* @0x2512b0 add r1, pc, r1 */
/* @0x2512b4 bl 0xb6574 <strcmp@plt> */
/* @0x2512b8 subs r6, r0, #0 */
/* @0x2512bc bne 0x2512e8 <_Z28JS_String_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x2512c0 ldr r1, [pc, #0x34] */
/* @0x2512c4 mov r0, r4 */
/* @0x2512c8 add r1, pc, r1 */
/* @0x2512cc bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc> */
/* @0x2512d0 mov r1, r6 */
/* @0x2512d4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x2512d8 mov r1, r0 */
/* @0x2512dc mov r0, r5 */
/* @0x2512e0 pop {r4, r5, r6, lr} */
/* @0x2512e4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x2512e8 ldr r0, [pc, #0x10] */
/* @0x2512ec pop {r4, r5, r6, lr} */
/* @0x2512f0 add r0, pc, r0 */
/* @0x2512f4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2512f8 andseq r4, r0, r0, lsl #11 */
/* @0x2512fc andseq r4, r0, r8, asr #4 */
/* @0x251300 andseq r4, r0, r8, asr r12 */

/* ── FUNC 0x251304 · JS_Array_prototype_sort(RValue&, CInstance*, CInstance*, int, RValue*) · size=224 · insn=56 */
/* @0x251304 ldr r2, [r1, #0x4] */
/* @0x251308 push {r4, r5, r6, r7, r8, lr} */
/* @0x25130c cmp r2, #0 */
/* @0x251310 sub sp, sp, #16 */
/* @0x251314 mov r6, r1 */
/* @0x251318 mov r7, r0 */
/* @0x25131c ldr r5, [sp, #0x28] */
/* @0x251320 beq 0x2513b0 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x251324 add r0, r2, #16 */
/* @0x251328 ldr r4, [r0] */
/* @0x25132c cmp r3, #0 */
/* @0x251330 ldr r8, [r4, #0x24] */
/* @0x251334 ble 0x25138c <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x88> */
/* @0x251338 mov r0, r5 */
/* @0x25133c bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251340 cmp r0, #0 */
/* @0x251344 beq 0x25139c <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x251348 ldr r12, [pc, #0x84] */
/* @0x25134c ldr r12, [pc, r12] */
/* @0x251350 ldr r0, [r4, #0x4] */
/* @0x251354 sub r2, r8, #1 */
/* @0x251358 str r12, [sp] */
/* @0x25135c mov r3, r5 */
/* @0x251360 mov r1, #0 */
/* @0x251364 bl 0x242f54 <_Z6mysortP6RValueiiS0_PF11E_MYSORTVALS0_S0_S0_E> */
/* @0x251368 cmn r0, #4 */
/* @0x25136c beq 0x251384 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x251370 cmn r0, #5 */
/* @0x251374 strne r6, [r7] */
/* @0x251378 movne r3, #6 */
/* @0x25137c strne r3, [r7, #0xc] */
/* @0x251380 beq 0x2513c8 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x251384 add sp, sp, #16 */
/* @0x251388 pop {r4, r5, r6, r7, r8, pc} */
/* @0x25138c ldr r12, [pc, #0x44] */
/* @0x251390 mov r5, #0 */
/* @0x251394 ldr r12, [pc, r12] */
/* @0x251398 b 0x251350 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0x25139c ldr r0, [pc, #0x38] */
/* @0x2513a0 add r0, pc, r0 */
/* @0x2513a4 add sp, sp, #16 */
/* @0x2513a8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x2513ac b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2513b0 mov r0, r1 */
/* @0x2513b4 mov r1, #1 */
/* @0x2513b8 str r3, [sp, #0xc] */
/* @0x2513bc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2513c0 ldr r3, [sp, #0xc] */
/* @0x2513c4 b 0x251328 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x2513c8 ldr r0, [pc, #0x10] */
/* @0x2513cc add r0, pc, r0 */
/* @0x2513d0 b 0x2513a4 <_Z23JS_Array_prototype_sortR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x2513d4 andseq r0, r10, r0, lsl #9 */
/* @0x2513d8 andseq r0, r10, r12, lsr r4 */
/* @0x2513dc andseq r4, r0, r8, lsr #27 */
/* @0x2513e0 ldrheq r4, [r0], -r12 */

/* ── FUNC 0x2513e4 · JS_Array_prototype_every(RValue&, CInstance*, CInstance*, int, RValue*) · size=424 · insn=106 */
/* @0x2513e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2513e8 mov r2, #0 */
/* @0x2513ec str r2, [r0] */
/* @0x2513f0 sub sp, sp, #84 */
/* @0x2513f4 str r2, [r0, #0x4] */
/* @0x2513f8 mov r4, r3 */
/* @0x2513fc ldr r2, [r1, #0x4] */
/* @0x251400 mov r3, #13 */
/* @0x251404 str r0, [sp, #0xc] */
/* @0x251408 cmp r2, #0 */
/* @0x25140c str r3, [r0, #0xc] */
/* @0x251410 beq 0x251574 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x251414 add r0, r2, #16 */
/* @0x251418 ldr r6, [r0] */
/* @0x25141c cmp r4, #0 */
/* @0x251420 ldr r8, [r6, #0x24] */
/* @0x251424 ble 0x251438 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x251428 ldr r0, [sp, #0x78] */
/* @0x25142c bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251430 cmp r0, #0 */
/* @0x251434 bne 0x25144c <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x251438 ldr r0, [pc, #0x144] */
/* @0x25143c add r0, pc, r0 */
/* @0x251440 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251444 add sp, sp, #84 */
/* @0x251448 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x25144c cmp r4, #1 */
/* @0x251450 moveq r12, #0 */
/* @0x251454 streq r12, [sp, #0x8] */
/* @0x251458 ldrne r12, [sp, #0x78] */
/* @0x25145c ldrne r12, [r12, #0x10] */
/* @0x251460 strne r12, [sp, #0x8] */
/* @0x251464 cmp r8, #0 */
/* @0x251468 beq 0x251544 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x25146c mov r10, #0 */
/* @0x251470 add r5, sp, #32 */
/* @0x251474 add r7, sp, #16 */
/* @0x251478 mov r4, r10 */
/* @0x25147c mov r11, r10 */
/* @0x251480 mvn r9, #-16777216 */
/* @0x251484 b 0x251518 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x251488 add r0, r0, r10 */
/* @0x25148c ldr r3, [r0, #0xc] */
/* @0x251490 bic r3, r3, #-16777216 */
/* @0x251494 cmp r3, r9 */
/* @0x251498 beq 0x251508 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x25149c ldr r0, [r6, #0x4] */
/* @0x2514a0 cmp r0, #0 */
/* @0x2514a4 beq 0x251534 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x2514a8 add r0, r0, r10 */
/* @0x2514ac vmov s13, r4 */
/* @0x2514b0 mov r12, #6 */
/* @0x2514b4 ldm r0, {r0, r1, r2, r3} */
/* @0x2514b8 vcvt.f64.u32 d7, s13 */
/* @0x2514bc str r5, [sp] */
/* @0x2514c0 str r11, [sp, #0x3c] */
/* @0x2514c4 str r12, [sp, #0x4c] */
/* @0x2514c8 stm r5, {r0, r1, r2, r3} */
/* @0x2514cc mov r1, r7 */
/* @0x2514d0 ldr r0, [sp, #0x8] */
/* @0x2514d4 mov r3, #3 */
/* @0x2514d8 ldr r2, [sp, #0x78] */
/* @0x2514dc vstr d7, [sp, #48] */
/* @0x2514e0 str r6, [sp, #0x40] */
/* @0x2514e4 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x2514e8 cmp r0, #2 */
/* @0x2514ec beq 0x251444 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x2514f0 cmp r0, #1 */
/* @0x2514f4 beq 0x251560 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x2514f8 mov r0, r7 */
/* @0x2514fc bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x251500 cmp r0, #0 */
/* @0x251504 beq 0x251444 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x251508 add r4, r4, #1 */
/* @0x25150c add r10, r10, #16 */
/* @0x251510 cmp r4, r8 */
/* @0x251514 beq 0x251544 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x251518 ldr r0, [r6, #0x4] */
/* @0x25151c cmp r0, #0 */
/* @0x251520 bne 0x251488 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x251524 mov r0, r6 */
/* @0x251528 mov r1, r4 */
/* @0x25152c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251530 b 0x25148c <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x251534 mov r0, r6 */
/* @0x251538 mov r1, r4 */
/* @0x25153c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251540 b 0x2514ac <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0xc8> */
/* @0x251544 ldr r12, [sp, #0xc] */
/* @0x251548 mov r3, #0 */
/* @0x25154c mov r2, r3 */
/* @0x251550 movt r3, #0x3ff0 */
/* @0x251554 stm r12, {r2, r3} */
/* @0x251558 add sp, sp, #84 */
/* @0x25155c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251560 ldr r0, [pc, #0x20] */
/* @0x251564 add r0, pc, r0 */
/* @0x251568 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25156c add sp, sp, #84 */
/* @0x251570 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251574 mov r0, r1 */
/* @0x251578 mov r1, #1 */
/* @0x25157c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251580 b 0x251418 <_Z24JS_Array_prototype_everyR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x251584 ldrsbeq r4, [r0], -r8 */
/* @0x251588 andseq r4, r0, r0, ror r12 */

/* ── FUNC 0x25158c · JS_Array_prototype_some(RValue&, CInstance*, CInstance*, int, RValue*) · size=432 · insn=108 */
/* @0x25158c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x251590 sub sp, sp, #84 */
/* @0x251594 mov r4, r3 */
/* @0x251598 mov r3, #13 */
/* @0x25159c str r0, [sp, #0xc] */
/* @0x2515a0 mov r0, #0 */
/* @0x2515a4 ldr r12, [sp, #0xc] */
/* @0x2515a8 mov r2, r0 */
/* @0x2515ac movt r2, #0x3ff0 */
/* @0x2515b0 str r0, [r12] */
/* @0x2515b4 str r2, [r12, #0x4] */
/* @0x2515b8 ldr r2, [r1, #0x4] */
/* @0x2515bc str r3, [r12, #0xc] */
/* @0x2515c0 cmp r2, r0 */
/* @0x2515c4 beq 0x251724 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x2515c8 add r0, r2, #16 */
/* @0x2515cc ldr r6, [r0] */
/* @0x2515d0 cmp r4, #0 */
/* @0x2515d4 ldr r8, [r6, #0x24] */
/* @0x2515d8 ble 0x2515ec <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x2515dc ldr r0, [sp, #0x78] */
/* @0x2515e0 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x2515e4 cmp r0, #0 */
/* @0x2515e8 bne 0x251600 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0x2515ec ldr r0, [pc, #0x140] */
/* @0x2515f0 add r0, pc, r0 */
/* @0x2515f4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2515f8 add sp, sp, #84 */
/* @0x2515fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251600 cmp r4, #1 */
/* @0x251604 moveq r12, #0 */
/* @0x251608 streq r12, [sp, #0x8] */
/* @0x25160c ldrne r12, [sp, #0x78] */
/* @0x251610 ldrne r12, [r12, #0x10] */
/* @0x251614 strne r12, [sp, #0x8] */
/* @0x251618 cmp r8, #0 */
/* @0x25161c beq 0x2516f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x251620 mov r10, #0 */
/* @0x251624 add r5, sp, #32 */
/* @0x251628 add r7, sp, #16 */
/* @0x25162c mov r4, r10 */
/* @0x251630 mov r11, r10 */
/* @0x251634 mvn r9, #-16777216 */
/* @0x251638 b 0x2516cc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x25163c add r0, r0, r10 */
/* @0x251640 ldr r3, [r0, #0xc] */
/* @0x251644 bic r3, r3, #-16777216 */
/* @0x251648 cmp r3, r9 */
/* @0x25164c beq 0x2516bc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x251650 ldr r0, [r6, #0x4] */
/* @0x251654 cmp r0, #0 */
/* @0x251658 beq 0x2516e8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x25165c add r0, r0, r10 */
/* @0x251660 vmov s13, r4 */
/* @0x251664 mov r12, #6 */
/* @0x251668 ldm r0, {r0, r1, r2, r3} */
/* @0x25166c vcvt.f64.u32 d7, s13 */
/* @0x251670 str r5, [sp] */
/* @0x251674 str r11, [sp, #0x3c] */
/* @0x251678 str r12, [sp, #0x4c] */
/* @0x25167c stm r5, {r0, r1, r2, r3} */
/* @0x251680 mov r1, r7 */
/* @0x251684 ldr r0, [sp, #0x8] */
/* @0x251688 mov r3, #3 */
/* @0x25168c ldr r2, [sp, #0x78] */
/* @0x251690 vstr d7, [sp, #48] */
/* @0x251694 str r6, [sp, #0x40] */
/* @0x251698 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x25169c cmp r0, #2 */
/* @0x2516a0 beq 0x2515f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x2516a4 cmp r0, #1 */
/* @0x2516a8 beq 0x251710 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x2516ac mov r0, r7 */
/* @0x2516b0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x2516b4 cmp r0, #0 */
/* @0x2516b8 bne 0x2515f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x2516bc add r4, r4, #1 */
/* @0x2516c0 add r10, r10, #16 */
/* @0x2516c4 cmp r4, r8 */
/* @0x2516c8 beq 0x2516f8 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x2516cc ldr r0, [r6, #0x4] */
/* @0x2516d0 cmp r0, #0 */
/* @0x2516d4 bne 0x25163c <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x2516d8 mov r0, r6 */
/* @0x2516dc mov r1, r4 */
/* @0x2516e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2516e4 b 0x251640 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x2516e8 mov r0, r6 */
/* @0x2516ec mov r1, r4 */
/* @0x2516f0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2516f4 b 0x251660 <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x2516f8 ldr r12, [sp, #0xc] */
/* @0x2516fc mov r3, #0 */
/* @0x251700 str r3, [r12] */
/* @0x251704 str r3, [r12, #0x4] */
/* @0x251708 add sp, sp, #84 */
/* @0x25170c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251710 ldr r0, [pc, #0x20] */
/* @0x251714 add r0, pc, r0 */
/* @0x251718 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25171c add sp, sp, #84 */
/* @0x251720 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251724 mov r0, r1 */
/* @0x251728 mov r1, #1 */
/* @0x25172c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251730 b 0x2515cc <_Z23JS_Array_prototype_someR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x251734 andseq r4, r0, r4, lsr #25 */
/* @0x251738 andseq r4, r0, r0, asr #22 */

/* ── FUNC 0x25173c · JS_Array_prototype_forEach(RValue&, CInstance*, CInstance*, int, RValue*) · size=364 · insn=91 */
/* @0x25173c ldr r2, [r1, #0x4] */
/* @0x251740 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x251744 cmp r2, #0 */
/* @0x251748 mov r4, r3 */
/* @0x25174c sub sp, sp, #84 */
/* @0x251750 mov r3, #5 */
/* @0x251754 str r3, [r0, #0xc] */
/* @0x251758 beq 0x251890 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x25175c add r0, r2, #16 */
/* @0x251760 ldr r9, [r0] */
/* @0x251764 cmp r4, #0 */
/* @0x251768 ldr r7, [r9, #0x24] */
/* @0x25176c ble 0x251780 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x251770 ldr r0, [sp, #0x78] */
/* @0x251774 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251778 cmp r0, #0 */
/* @0x25177c bne 0x251794 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x251780 ldr r0, [pc, #0x118] */
/* @0x251784 add r0, pc, r0 */
/* @0x251788 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25178c add sp, sp, #84 */
/* @0x251790 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251794 cmp r4, #1 */
/* @0x251798 moveq r12, #0 */
/* @0x25179c streq r12, [sp, #0xc] */
/* @0x2517a0 ldrne r12, [sp, #0x78] */
/* @0x2517a4 ldrne r12, [r12, #0x10] */
/* @0x2517a8 strne r12, [sp, #0xc] */
/* @0x2517ac cmp r7, #0 */
/* @0x2517b0 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2517b4 mov r4, #0 */
/* @0x2517b8 add r6, sp, #32 */
/* @0x2517bc add r11, sp, #16 */
/* @0x2517c0 mov r5, r4 */
/* @0x2517c4 mov r10, r4 */
/* @0x2517c8 mvn r8, #-16777216 */
/* @0x2517cc b 0x25184c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x2517d0 ldr r3, [r0, #0xc] */
/* @0x2517d4 bic r3, r3, #-16777216 */
/* @0x2517d8 cmp r3, r8 */
/* @0x2517dc beq 0x25183c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x2517e0 ldr r0, [r9, #0x4] */
/* @0x2517e4 cmp r0, #0 */
/* @0x2517e8 add r0, r0, r4 */
/* @0x2517ec beq 0x25186c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x2517f0 vmov s13, r5 */
/* @0x2517f4 mov r12, #6 */
/* @0x2517f8 ldm r0, {r0, r1, r2, r3} */
/* @0x2517fc vcvt.f64.u32 d7, s13 */
/* @0x251800 str r6, [sp] */
/* @0x251804 str r10, [sp, #0x3c] */
/* @0x251808 str r12, [sp, #0x4c] */
/* @0x25180c stm r6, {r0, r1, r2, r3} */
/* @0x251810 mov r1, r11 */
/* @0x251814 ldr r0, [sp, #0xc] */
/* @0x251818 mov r3, #3 */
/* @0x25181c ldr r2, [sp, #0x78] */
/* @0x251820 vstr d7, [sp, #48] */
/* @0x251824 str r9, [sp, #0x40] */
/* @0x251828 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x25182c cmp r0, #2 */
/* @0x251830 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x251834 cmp r0, #1 */
/* @0x251838 beq 0x25187c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x25183c add r5, r5, #1 */
/* @0x251840 add r4, r4, #16 */
/* @0x251844 cmp r5, r7 */
/* @0x251848 beq 0x25178c <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x25184c ldr r0, [r9, #0x4] */
/* @0x251850 cmp r0, #0 */
/* @0x251854 add r0, r0, r4 */
/* @0x251858 bne 0x2517d0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x25185c mov r0, r9 */
/* @0x251860 mov r1, r5 */
/* @0x251864 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251868 b 0x2517d0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0x25186c mov r0, r9 */
/* @0x251870 mov r1, r5 */
/* @0x251874 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251878 b 0x2517f0 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x25187c ldr r0, [pc, #0x20] */
/* @0x251880 add r0, pc, r0 */
/* @0x251884 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251888 add sp, sp, #84 */
/* @0x25188c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251890 mov r0, r1 */
/* @0x251894 mov r1, #1 */
/* @0x251898 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25189c b 0x251760 <_Z26JS_Array_prototype_forEachR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x2518a0 mulseq r0, r4, r11 */
/* @0x2518a4 andseq r4, r0, r4, asr r10 */

/* ── FUNC 0x2518a8 · JS_Array_prototype_map(RValue&, CInstance*, CInstance*, int, RValue*) · size=600 · insn=150 */
/* @0x2518a8 ldr r12, [pc, #0x244] */
/* @0x2518ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2518b0 sub sp, sp, #236 */
/* @0x2518b4 mov r4, r1 */
/* @0x2518b8 mov r5, r3 */
/* @0x2518bc str r12, [sp, #0x1c] */
/* @0x2518c0 mov r6, r2 */
/* @0x2518c4 ldr r12, [r1, #0x4] */
/* @0x2518c8 mov r2, #5 */
/* @0x2518cc ldr r1, [sp, #0x1c] */
/* @0x2518d0 cmp r12, #0 */
/* @0x2518d4 str r0, [sp, #0xc] */
/* @0x2518d8 ldr r1, [pc, r1] */
/* @0x2518dc str r1, [sp, #0x1c] */
/* @0x2518e0 str r2, [r0, #0xc] */
/* @0x2518e4 ldr r3, [r1] */
/* @0x2518e8 ldr r1, [sp, #0x110] */
/* @0x2518ec str r3, [sp, #0xe4] */
/* @0x2518f0 str r1, [sp, #0x10] */
/* @0x2518f4 beq 0x251ae0 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x238> */
/* @0x2518f8 add r0, r12, #16 */
/* @0x2518fc ldr r7, [r0] */
/* @0x251900 cmp r5, #0 */
/* @0x251904 ldr r12, [r7, #0x24] */
/* @0x251908 str r12, [sp, #0x14] */
/* @0x25190c ble 0x251920 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x251910 ldr r0, [sp, #0x10] */
/* @0x251914 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251918 cmp r0, #0 */
/* @0x25191c bne 0x251948 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x251920 ldr r0, [pc, #0x1d0] */
/* @0x251924 add r0, pc, r0 */
/* @0x251928 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25192c ldr r12, [sp, #0x1c] */
/* @0x251930 ldr r2, [sp, #0xe4] */
/* @0x251934 ldr r3, [r12] */
/* @0x251938 cmp r2, r3 */
/* @0x25193c bne 0x251af0 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x251940 add sp, sp, #236 */
/* @0x251944 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251948 cmp r5, #1 */
/* @0x25194c moveq r12, #0 */
/* @0x251950 streq r12, [sp, #0x18] */
/* @0x251954 ldrne r12, [sp, #0x10] */
/* @0x251958 ldrne r12, [r12, #0x10] */
/* @0x25195c strne r12, [sp, #0x18] */
/* @0x251960 ldr r12, [sp, #0x10] */
/* @0x251964 mov r1, r4 */
/* @0x251968 mov r2, r6 */
/* @0x25196c ldr r0, [sp, #0xc] */
/* @0x251970 mov r3, #0 */
/* @0x251974 str r12, [sp] */
/* @0x251978 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x25197c ldr r12, [sp, #0x14] */
/* @0x251980 cmp r12, #0 */
/* @0x251984 beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251988 mov r6, #0 */
/* @0x25198c add r9, sp, #100 */
/* @0x251990 add r5, sp, #52 */
/* @0x251994 mov r4, r6 */
/* @0x251998 b 0x251a40 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25199c ldr r0, [r7, #0x4] */
/* @0x2519a0 cmp r0, #0 */
/* @0x2519a4 beq 0x251aac <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x2519a8 add r0, r0, r6 */
/* @0x2519ac vmov s15, r4 */
/* @0x2519b0 add r8, sp, #36 */
/* @0x2519b4 ldm r0, {r0, r1, r2, r3} */
/* @0x2519b8 vcvt.f64.u32 d7, s15 */
/* @0x2519bc str r5, [sp] */
/* @0x2519c0 mov r12, #0 */
/* @0x2519c4 str r12, [sp, #0x50] */
/* @0x2519c8 mov r12, #6 */
/* @0x2519cc str r12, [sp, #0x60] */
/* @0x2519d0 stm r5, {r0, r1, r2, r3} */
/* @0x2519d4 mov r1, r8 */
/* @0x2519d8 ldr r0, [sp, #0x18] */
/* @0x2519dc mov r3, #3 */
/* @0x2519e0 vmov r10, r11, d7 */
/* @0x2519e4 vstr s14, [sp, #68] */
/* @0x2519e8 ldr r2, [sp, #0x10] */
/* @0x2519ec str r7, [sp, #0x54] */
/* @0x2519f0 str r11, [sp, #0x48] */
/* @0x2519f4 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x2519f8 cmp r0, #2 */
/* @0x2519fc beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251a00 cmp r0, #1 */
/* @0x251a04 beq 0x251abc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x251a08 mov r1, r9 */
/* @0x251a0c mov r2, #10 */
/* @0x251a10 mov r0, r4 */
/* @0x251a14 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x251a18 ldr r12, [sp, #0xc] */
/* @0x251a1c mov r1, r8 */
/* @0x251a20 mov r2, r9 */
/* @0x251a24 ldr r0, [r12] */
/* @0x251a28 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x251a2c ldr r12, [sp, #0x14] */
/* @0x251a30 add r4, r4, #1 */
/* @0x251a34 add r6, r6, #16 */
/* @0x251a38 cmp r4, r12 */
/* @0x251a3c beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251a40 ldr r0, [r7, #0x4] */
/* @0x251a44 cmp r0, #0 */
/* @0x251a48 beq 0x251a9c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x251a4c add r0, r0, r6 */
/* @0x251a50 ldr r3, [r0, #0xc] */
/* @0x251a54 mvn r1, #-16777216 */
/* @0x251a58 bic r3, r3, #-16777216 */
/* @0x251a5c cmp r3, r1 */
/* @0x251a60 bne 0x25199c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x251a64 mov r1, r9 */
/* @0x251a68 mov r0, r4 */
/* @0x251a6c mov r2, #10 */
/* @0x251a70 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x251a74 ldr r1, [r7, #0x4] */
/* @0x251a78 ldr r12, [sp, #0xc] */
/* @0x251a7c cmp r1, #0 */
/* @0x251a80 ldr r8, [r12] */
/* @0x251a84 beq 0x251acc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x251a88 add r1, r1, r6 */
/* @0x251a8c mov r0, r8 */
/* @0x251a90 mov r2, r9 */
/* @0x251a94 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x251a98 b 0x251a2c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x251a9c mov r0, r7 */
/* @0x251aa0 mov r1, r4 */
/* @0x251aa4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251aa8 b 0x251a50 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x251aac mov r0, r7 */
/* @0x251ab0 mov r1, r4 */
/* @0x251ab4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251ab8 b 0x2519ac <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x251abc ldr r0, [pc, #0x38] */
/* @0x251ac0 add r0, pc, r0 */
/* @0x251ac4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251ac8 b 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251acc mov r1, r4 */
/* @0x251ad0 mov r0, r7 */
/* @0x251ad4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251ad8 mov r1, r0 */
/* @0x251adc b 0x251a8c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x251ae0 mov r0, r4 */
/* @0x251ae4 mov r1, #1 */
/* @0x251ae8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251aec b 0x2518fc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x251af0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x251af4 andseq r12, r9, r8, ror r0 */
/* @0x251af8 andseq r4, r0, r4, ror r10 */
/* @0x251afc mulseq r0, r8, r8 */

/* ── FUNC 0x251b00 · JS_Array_prototype_filter(RValue&, CInstance*, CInstance*, int, RValue*) · size=644 · insn=161 */
/* @0x251b00 ldr r12, [pc, #0x270] */
/* @0x251b04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x251b08 sub sp, sp, #244 */
/* @0x251b0c mov r4, r1 */
/* @0x251b10 mov r5, r3 */
/* @0x251b14 str r12, [sp, #0x20] */
/* @0x251b18 mov r6, r2 */
/* @0x251b1c str r0, [sp, #0x1c] */
/* @0x251b20 mov r2, #5 */
/* @0x251b24 ldr r0, [sp, #0x20] */
/* @0x251b28 ldr r12, [r1, #0x4] */
/* @0x251b2c ldr r0, [pc, r0] */
/* @0x251b30 ldr r1, [sp, #0x118] */
/* @0x251b34 str r0, [sp, #0x20] */
/* @0x251b38 cmp r12, #0 */
/* @0x251b3c ldr r3, [r0] */
/* @0x251b40 ldr r0, [sp, #0x1c] */
/* @0x251b44 str r1, [sp, #0x14] */
/* @0x251b48 str r3, [sp, #0xec] */
/* @0x251b4c str r2, [r0, #0xc] */
/* @0x251b50 beq 0x251d58 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x251b54 add r0, r12, #16 */
/* @0x251b58 ldr r8, [r0] */
/* @0x251b5c cmp r5, #0 */
/* @0x251b60 ldr r10, [r8, #0x24] */
/* @0x251b64 ble 0x251b78 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0x251b68 ldr r0, [sp, #0x14] */
/* @0x251b6c bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251b70 cmp r0, #0 */
/* @0x251b74 bne 0x251ba0 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x251b78 ldr r0, [pc, #0x1fc] */
/* @0x251b7c add r0, pc, r0 */
/* @0x251b80 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251b84 ldr r12, [sp, #0x20] */
/* @0x251b88 ldr r2, [sp, #0xec] */
/* @0x251b8c ldr r3, [r12] */
/* @0x251b90 cmp r2, r3 */
/* @0x251b94 bne 0x251d74 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x251b98 add sp, sp, #244 */
/* @0x251b9c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251ba0 cmp r5, #1 */
/* @0x251ba4 moveq r12, #0 */
/* @0x251ba8 streq r12, [sp, #0x18] */
/* @0x251bac ldrne r12, [sp, #0x14] */
/* @0x251bb0 ldrne r12, [r12, #0x10] */
/* @0x251bb4 strne r12, [sp, #0x18] */
/* @0x251bb8 ldr r12, [sp, #0x14] */
/* @0x251bbc mov r3, #0 */
/* @0x251bc0 ldr r0, [sp, #0x1c] */
/* @0x251bc4 mov r1, r4 */
/* @0x251bc8 mov r2, r6 */
/* @0x251bcc str r12, [sp] */
/* @0x251bd0 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x251bd4 ldr r12, [sp, #0x1c] */
/* @0x251bd8 ldr r0, [r12] */
/* @0x251bdc ldr r3, [r0, #0x4] */
/* @0x251be0 cmp r3, #0 */
/* @0x251be4 beq 0x251d68 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x251be8 add r0, r3, #16 */
/* @0x251bec ldr r0, [r0] */
/* @0x251bf0 cmp r10, #0 */
/* @0x251bf4 str r0, [sp, #0x24] */
/* @0x251bf8 beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251bfc mov r11, #0 */
/* @0x251c00 add r7, sp, #60 */
/* @0x251c04 add r9, sp, #44 */
/* @0x251c08 mov r6, r11 */
/* @0x251c0c b 0x251c20 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x251c10 add r6, r6, #1 */
/* @0x251c14 add r11, r11, #16 */
/* @0x251c18 cmp r6, r10 */
/* @0x251c1c beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251c20 ldr r0, [r8, #0x4] */
/* @0x251c24 cmp r0, #0 */
/* @0x251c28 beq 0x251d04 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x251c2c add r0, r0, r11 */
/* @0x251c30 ldr r3, [r0, #0xc] */
/* @0x251c34 mvn r0, #-16777216 */
/* @0x251c38 bic r3, r3, #-16777216 */
/* @0x251c3c cmp r3, r0 */
/* @0x251c40 beq 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x251c44 ldr r0, [r8, #0x4] */
/* @0x251c48 cmp r0, #0 */
/* @0x251c4c beq 0x251d14 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x251c50 add r0, r0, r11 */
/* @0x251c54 vmov s15, r6 */
/* @0x251c58 mov r12, #0 */
/* @0x251c5c ldm r0, {r0, r1, r2, r3} */
/* @0x251c60 vcvt.f64.u32 d7, s15 */
/* @0x251c64 str r12, [sp, #0x58] */
/* @0x251c68 mov r12, #6 */
/* @0x251c6c str r7, [sp] */
/* @0x251c70 str r12, [sp, #0x68] */
/* @0x251c74 stm r7, {r0, r1, r2, r3} */
/* @0x251c78 mov r1, r9 */
/* @0x251c7c ldr r0, [sp, #0x18] */
/* @0x251c80 mov r3, #3 */
/* @0x251c84 vmov r4, r5, d7 */
/* @0x251c88 vstr s14, [sp, #76] */
/* @0x251c8c ldr r2, [sp, #0x14] */
/* @0x251c90 str r8, [sp, #0x5c] */
/* @0x251c94 str r5, [sp, #0x50] */
/* @0x251c98 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x251c9c cmp r0, #2 */
/* @0x251ca0 beq 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251ca4 cmp r0, #1 */
/* @0x251ca8 beq 0x251d24 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x224> */
/* @0x251cac mov r0, r9 */
/* @0x251cb0 bl 0x2404bc <_Z12JS_ToBooleanR6RValue> */
/* @0x251cb4 cmp r0, #0 */
/* @0x251cb8 beq 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x251cbc ldr r12, [sp, #0x24] */
/* @0x251cc0 add r3, sp, #108 */
/* @0x251cc4 mov r2, #10 */
/* @0x251cc8 mov r1, r3 */
/* @0x251ccc ldr r0, [r12, #0x24] */
/* @0x251cd0 str r3, [sp, #0xc] */
/* @0x251cd4 bl 0xc4964 <_Z5_itoaiPci> */
/* @0x251cd8 ldr r1, [r8, #0x4] */
/* @0x251cdc ldr r12, [sp, #0x1c] */
/* @0x251ce0 cmp r1, #0 */
/* @0x251ce4 ldr r3, [sp, #0xc] */
/* @0x251ce8 ldr r2, [r12] */
/* @0x251cec beq 0x251d34 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x251cf0 add r1, r1, r11 */
/* @0x251cf4 mov r0, r2 */
/* @0x251cf8 mov r2, r3 */
/* @0x251cfc bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc> */
/* @0x251d00 b 0x251c10 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x251d04 mov r0, r8 */
/* @0x251d08 mov r1, r6 */
/* @0x251d0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251d10 b 0x251c30 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x251d14 mov r0, r8 */
/* @0x251d18 mov r1, r6 */
/* @0x251d1c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251d20 b 0x251c54 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x251d24 ldr r0, [pc, #0x54] */
/* @0x251d28 add r0, pc, r0 */
/* @0x251d2c bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251d30 b 0x251b84 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x251d34 mov r1, r6 */
/* @0x251d38 mov r0, r8 */
/* @0x251d3c str r2, [sp, #0x10] */
/* @0x251d40 str r3, [sp, #0xc] */
/* @0x251d44 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251d48 ldr r3, [sp, #0xc] */
/* @0x251d4c ldr r2, [sp, #0x10] */
/* @0x251d50 mov r1, r0 */
/* @0x251d54 b 0x251cf4 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x251d58 mov r0, r4 */
/* @0x251d5c mov r1, #1 */
/* @0x251d60 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251d64 b 0x251b58 <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x251d68 mov r1, #1 */
/* @0x251d6c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251d70 b 0x251bec <_Z25JS_Array_prototype_filterR6RValueP9CInstanceS2_iPS_+0xec> */
/* @0x251d74 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x251d78 andseq r11, r9, r4, lsr #28 */
/* @0x251d7c mulseq r0, r12, r8 */
/* @0x251d80 andseq r4, r0, r12, lsr #13 */

/* ── FUNC 0x251d84 · JS_Array_prototype_reduce(RValue&, CInstance*, CInstance*, int, RValue*) · size=480 · insn=120 */
/* @0x251d84 ldr r12, [r1, #0x4] */
/* @0x251d88 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x251d8c cmp r12, #0 */
/* @0x251d90 sub sp, sp, #116 */
/* @0x251d94 mov r5, r3 */
/* @0x251d98 mov r6, r1 */
/* @0x251d9c mov r3, #5 */
/* @0x251da0 str r0, [sp, #0xc] */
/* @0x251da4 mov r7, r2 */
/* @0x251da8 str r3, [r0, #0xc] */
/* @0x251dac beq 0x251f3c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x251db0 add r0, r12, #16 */
/* @0x251db4 ldr r11, [r0] */
/* @0x251db8 cmp r5, #0 */
/* @0x251dbc ldr r9, [r11, #0x24] */
/* @0x251dc0 ble 0x251ef0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x251dc4 ldr r0, [sp, #0x98] */
/* @0x251dc8 bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251dcc cmp r0, #0 */
/* @0x251dd0 beq 0x251ef0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x251dd4 ldr r1, [r11, #0x4] */
/* @0x251dd8 cmp r1, #0 */
/* @0x251ddc beq 0x251f4c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x251de0 cmp r5, #1 */
/* @0x251de4 addeq r4, sp, #16 */
/* @0x251de8 addne r4, sp, #16 */
/* @0x251dec ldrne r12, [sp, #0x98] */
/* @0x251df0 movne r5, #0 */
/* @0x251df4 ldmeq r1, {r0, r1, r2, r3} */
/* @0x251df8 addne r3, r12, #16 */
/* @0x251dfc ldr r12, [sp, #0x98] */
/* @0x251e00 ldmne r3, {r0, r1, r2, r3} */
/* @0x251e04 stm r4, {r0, r1, r2, r3} */
/* @0x251e08 mov r1, r6 */
/* @0x251e0c mov r2, r7 */
/* @0x251e10 str r12, [sp] */
/* @0x251e14 ldr r0, [sp, #0xc] */
/* @0x251e18 mov r3, #0 */
/* @0x251e1c bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x251e20 cmp r5, r9 */
/* @0x251e24 lsllo r7, r5, #4 */
/* @0x251e28 addlo r6, sp, #48 */
/* @0x251e2c addlo r8, sp, #32 */
/* @0x251e30 mvnlo r10, #-16777216 */
/* @0x251e34 blo 0x251ed4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x251e38 b 0x251f14 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x251e3c add r0, r0, r7 */
/* @0x251e40 ldr r3, [r0, #0xc] */
/* @0x251e44 bic r3, r3, #-16777216 */
/* @0x251e48 cmp r3, r10 */
/* @0x251e4c beq 0x251ec4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x251e50 ldm r4, {r0, r1, r2, r3} */
/* @0x251e54 ldr lr, [r11, #0x4] */
/* @0x251e58 cmp lr, #0 */
/* @0x251e5c stm r6, {r0, r1, r2, r3} */
/* @0x251e60 beq 0x251f04 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x251e64 add r0, lr, r7 */
/* @0x251e68 vmov s13, r5 */
/* @0x251e6c add lr, sp, #64 */
/* @0x251e70 ldm r0, {r0, r1, r2, r3} */
/* @0x251e74 vcvt.f64.u32 d7, s13 */
/* @0x251e78 str r6, [sp] */
/* @0x251e7c mov r12, #0 */
/* @0x251e80 str r12, [sp, #0x5c] */
/* @0x251e84 mov r12, #6 */
/* @0x251e88 str r12, [sp, #0x6c] */
/* @0x251e8c stm lr, {r0, r1, r2, r3} */
/* @0x251e90 mov r0, #0 */
/* @0x251e94 mov r1, r8 */
/* @0x251e98 ldr r2, [sp, #0x98] */
/* @0x251e9c mov r3, #3 */
/* @0x251ea0 str r11, [sp, #0x60] */
/* @0x251ea4 vstr d7, [sp, #80] */
/* @0x251ea8 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x251eac cmp r0, #2 */
/* @0x251eb0 beq 0x251efc <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x251eb4 cmp r0, #1 */
/* @0x251eb8 beq 0x251f28 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x251ebc ldm r8, {r0, r1, r2, r3} */
/* @0x251ec0 stm r4, {r0, r1, r2, r3} */
/* @0x251ec4 add r5, r5, #1 */
/* @0x251ec8 add r7, r7, #16 */
/* @0x251ecc cmp r9, r5 */
/* @0x251ed0 bls 0x251f14 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x251ed4 ldr r0, [r11, #0x4] */
/* @0x251ed8 cmp r0, #0 */
/* @0x251edc bne 0x251e3c <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x251ee0 mov r0, r11 */
/* @0x251ee4 mov r1, r5 */
/* @0x251ee8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251eec b 0x251e40 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x251ef0 ldr r0, [pc, #0x64] */
/* @0x251ef4 add r0, pc, r0 */
/* @0x251ef8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251efc add sp, sp, #116 */
/* @0x251f00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251f04 mov r0, r11 */
/* @0x251f08 mov r1, r5 */
/* @0x251f0c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251f10 b 0x251e68 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x251f14 ldm r4, {r0, r1, r2, r3} */
/* @0x251f18 ldr r12, [sp, #0xc] */
/* @0x251f1c stm r12, {r0, r1, r2, r3} */
/* @0x251f20 add sp, sp, #116 */
/* @0x251f24 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251f28 ldr r0, [pc, #0x30] */
/* @0x251f2c add r0, pc, r0 */
/* @0x251f30 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x251f34 add sp, sp, #116 */
/* @0x251f38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x251f3c mov r0, r1 */
/* @0x251f40 mov r1, #1 */
/* @0x251f44 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251f48 b 0x251db4 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x30> */
/* @0x251f4c mov r0, r11 */
/* @0x251f50 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x251f54 mov r1, r0 */
/* @0x251f58 b 0x251de0 <_Z25JS_Array_prototype_reduceR6RValueP9CInstanceS2_iPS_+0x5c> */
/* @0x251f5c andseq r4, r0, r8, lsr #11 */
/* @0x251f60 andseq r4, r0, r12, lsr #10 */

/* ── FUNC 0x251f64 · JS_Array_prototype_reduceRight(RValue&, CInstance*, CInstance*, int, RValue*) · size=516 · insn=129 */
/* @0x251f64 ldr r12, [r1, #0x4] */
/* @0x251f68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x251f6c cmp r12, #0 */
/* @0x251f70 sub sp, sp, #116 */
/* @0x251f74 mov r4, r3 */
/* @0x251f78 mov r6, r1 */
/* @0x251f7c mov r3, #5 */
/* @0x251f80 str r0, [sp, #0xc] */
/* @0x251f84 mov r7, r2 */
/* @0x251f88 str r3, [r0, #0xc] */
/* @0x251f8c ldr r10, [sp, #0x98] */
/* @0x251f90 beq 0x252134 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x251f94 add r0, r12, #16 */
/* @0x251f98 ldr r11, [r0] */
/* @0x251f9c cmp r4, #0 */
/* @0x251fa0 ldr r8, [r11, #0x24] */
/* @0x251fa4 ble 0x2520e8 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x251fa8 mov r0, r10 */
/* @0x251fac bl 0x24076c <_Z13JS_IsCallableR6RValue> */
/* @0x251fb0 cmp r0, #0 */
/* @0x251fb4 beq 0x2520e8 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x251fb8 ldr r0, [r11, #0x4] */
/* @0x251fbc sub r5, r8, #1 */
/* @0x251fc0 cmp r0, #0 */
/* @0x251fc4 addne r0, r0, r5, lsl #4 */
/* @0x251fc8 beq 0x252150 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x251fcc cmp r4, #1 */
/* @0x251fd0 addne r3, r10, #16 */
/* @0x251fd4 addeq r4, sp, #16 */
/* @0x251fd8 ldmeq r0, {r0, r1, r2, r3} */
/* @0x251fdc addne r4, sp, #16 */
/* @0x251fe0 ldmne r3, {r0, r1, r2, r3} */
/* @0x251fe4 subeq r5, r8, #2 */
/* @0x251fe8 stm r4, {r0, r1, r2, r3} */
/* @0x251fec mov r3, #0 */
/* @0x251ff0 ldr r0, [sp, #0xc] */
/* @0x251ff4 mov r1, r6 */
/* @0x251ff8 str r10, [sp] */
/* @0x251ffc mov r2, r7 */
/* @0x252000 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_> */
/* @0x252004 ldr r12, [sp, #0xc] */
/* @0x252008 ldr r0, [r12] */
/* @0x25200c ldr r3, [r0, #0x4] */
/* @0x252010 cmp r3, #0 */
/* @0x252014 beq 0x252144 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x252018 cmp r5, #0 */
/* @0x25201c lslge r7, r5, #4 */
/* @0x252020 addge r6, sp, #48 */
/* @0x252024 addge r8, sp, #32 */
/* @0x252028 mvnge r9, #-16777216 */
/* @0x25202c bge 0x2520cc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x252030 b 0x25210c <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x252034 add r0, r0, r7 */
/* @0x252038 ldr r3, [r0, #0xc] */
/* @0x25203c bic r3, r3, #-16777216 */
/* @0x252040 cmp r3, r9 */
/* @0x252044 beq 0x2520bc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x252048 ldm r4, {r0, r1, r2, r3} */
/* @0x25204c ldr r12, [r11, #0x4] */
/* @0x252050 cmp r12, #0 */
/* @0x252054 stm r6, {r0, r1, r2, r3} */
/* @0x252058 beq 0x2520fc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x25205c add r0, r12, r7 */
/* @0x252060 vmov s13, r5 */
/* @0x252064 mov r12, #0 */
/* @0x252068 ldm r0, {r0, r1, r2, r3} */
/* @0x25206c vcvt.f64.s32 d7, s13 */
/* @0x252070 str r12, [sp, #0x5c] */
/* @0x252074 mov r12, #6 */
/* @0x252078 str r12, [sp, #0x6c] */
/* @0x25207c add r12, sp, #64 */
/* @0x252080 str r6, [sp] */
/* @0x252084 stm r12, {r0, r1, r2, r3} */
/* @0x252088 mov r0, #0 */
/* @0x25208c mov r1, r8 */
/* @0x252090 mov r2, r10 */
/* @0x252094 mov r3, #3 */
/* @0x252098 str r11, [sp, #0x60] */
/* @0x25209c vstr d7, [sp, #80] */
/* @0x2520a0 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_> */
/* @0x2520a4 cmp r0, #2 */
/* @0x2520a8 beq 0x2520f4 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x2520ac cmp r0, #1 */
/* @0x2520b0 beq 0x252120 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x2520b4 ldm r8, {r0, r1, r2, r3} */
/* @0x2520b8 stm r4, {r0, r1, r2, r3} */
/* @0x2520bc sub r5, r5, #1 */
/* @0x2520c0 sub r7, r7, #16 */
/* @0x2520c4 cmn r5, #1 */
/* @0x2520c8 beq 0x25210c <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x2520cc ldr r0, [r11, #0x4] */
/* @0x2520d0 cmp r0, #0 */
/* @0x2520d4 bne 0x252034 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x2520d8 mov r0, r11 */
/* @0x2520dc mov r1, r5 */
/* @0x2520e0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x2520e4 b 0x252038 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x2520e8 ldr r0, [pc, #0x70] */
/* @0x2520ec add r0, pc, r0 */
/* @0x2520f0 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2520f4 add sp, sp, #116 */
/* @0x2520f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2520fc mov r0, r11 */
/* @0x252100 mov r1, r5 */
/* @0x252104 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x252108 b 0x252060 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x25210c ldm r4, {r0, r1, r2, r3} */
/* @0x252110 ldr r12, [sp, #0xc] */
/* @0x252114 stm r12, {r0, r1, r2, r3} */
/* @0x252118 add sp, sp, #116 */
/* @0x25211c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x252120 ldr r0, [pc, #0x3c] */
/* @0x252124 add r0, pc, r0 */
/* @0x252128 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25212c add sp, sp, #116 */
/* @0x252130 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x252134 mov r0, r1 */
/* @0x252138 mov r1, #1 */
/* @0x25213c bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x252140 b 0x251f98 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x252144 mov r1, #1 */
/* @0x252148 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25214c b 0x252018 <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x252150 mov r0, r11 */
/* @0x252154 mov r1, r5 */
/* @0x252158 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x25215c b 0x251fcc <_Z30JS_Array_prototype_reduceRightR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x252160 andseq r4, r0, r8, lsr r4 */
/* @0x252164 ldrheq r4, [r0], -r8 */

/* ── FUNC 0x252168 · JS_Math_abs(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0x252168 cmp r3, #0 */
/* @0x25216c push {r3, r4, r5, lr} */
/* @0x252170 mov r5, #0 */
/* @0x252174 mov r4, r0 */
/* @0x252178 ldr r1, [sp, #0x10] */
/* @0x25217c str r5, [r0, #0xc] */
/* @0x252180 ble 0x2521b8 <_Z11JS_Math_absR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252184 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252188 cmp r0, #1 */
/* @0x25218c beq 0x2521c8 <_Z11JS_Math_absR6RValueP9CInstanceS2_iPS_+0x60> */
/* @0x252190 mov r1, r5 */
/* @0x252194 mov r0, r4 */
/* @0x252198 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x25219c vmov d7, r0, r1 */
/* @0x2521a0 vabs.f64 d7, d7 */
/* @0x2521a4 vmov r0, r1, d7 */
/* @0x2521a8 vmov r2, s14 */
/* @0x2521ac mov r3, r1 */
/* @0x2521b0 stm r4, {r2, r3} */
/* @0x2521b4 pop {r3, r4, r5, pc} */
/* @0x2521b8 mvn r2, #0 */
/* @0x2521bc mvn r3, #-2147483648 */
/* @0x2521c0 stm r0, {r2, r3} */
/* @0x2521c4 pop {r3, r4, r5, pc} */
/* @0x2521c8 ldr r0, [pc, #0x8] */
/* @0x2521cc pop {r3, r4, r5, lr} */
/* @0x2521d0 add r0, pc, r0 */
/* @0x2521d4 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2521d8 andseq r3, r0, r8, ror sp */

/* ── FUNC 0x2521dc · JS_Math_acos(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x2521dc cmp r3, #0 */
/* @0x2521e0 push {r3, r4, r5, lr} */
/* @0x2521e4 mov r5, #0 */
/* @0x2521e8 mov r4, r0 */
/* @0x2521ec ldr r1, [sp, #0x10] */
/* @0x2521f0 str r5, [r0, #0xc] */
/* @0x2521f4 ble 0x25221c <_Z12JS_Math_acosR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2521f8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2521fc cmp r0, #1 */
/* @0x252200 beq 0x25222c <_Z12JS_Math_acosR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252204 mov r1, r5 */
/* @0x252208 mov r0, r4 */
/* @0x25220c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252210 bl 0xb6c4c <acos@plt> */
/* @0x252214 stm r4, {r0, r1} */
/* @0x252218 pop {r3, r4, r5, pc} */
/* @0x25221c mvn r2, #0 */
/* @0x252220 mvn r3, #-2147483648 */
/* @0x252224 stm r0, {r2, r3} */
/* @0x252228 pop {r3, r4, r5, pc} */
/* @0x25222c ldr r0, [pc, #0x8] */
/* @0x252230 pop {r3, r4, r5, lr} */
/* @0x252234 add r0, pc, r0 */
/* @0x252238 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25223c andseq r3, r0, r4, lsl sp */

/* ── FUNC 0x252240 · JS_Math_asin(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x252240 cmp r3, #0 */
/* @0x252244 push {r3, r4, r5, lr} */
/* @0x252248 mov r5, #0 */
/* @0x25224c mov r4, r0 */
/* @0x252250 ldr r1, [sp, #0x10] */
/* @0x252254 str r5, [r0, #0xc] */
/* @0x252258 ble 0x252280 <_Z12JS_Math_asinR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x25225c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252260 cmp r0, #1 */
/* @0x252264 beq 0x252290 <_Z12JS_Math_asinR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252268 mov r1, r5 */
/* @0x25226c mov r0, r4 */
/* @0x252270 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252274 bl 0xb6c58 <asin@plt> */
/* @0x252278 stm r4, {r0, r1} */
/* @0x25227c pop {r3, r4, r5, pc} */
/* @0x252280 mvn r2, #0 */
/* @0x252284 mvn r3, #-2147483648 */
/* @0x252288 stm r0, {r2, r3} */
/* @0x25228c pop {r3, r4, r5, pc} */
/* @0x252290 ldr r0, [pc, #0x8] */
/* @0x252294 pop {r3, r4, r5, lr} */
/* @0x252298 add r0, pc, r0 */
/* @0x25229c b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2522a0 ldrheq r3, [r0], -r0 */

/* ── FUNC 0x2522a4 · JS_Math_atan(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x2522a4 cmp r3, #0 */
/* @0x2522a8 push {r3, r4, r5, lr} */
/* @0x2522ac mov r5, #0 */
/* @0x2522b0 mov r4, r0 */
/* @0x2522b4 ldr r1, [sp, #0x10] */
/* @0x2522b8 str r5, [r0, #0xc] */
/* @0x2522bc ble 0x2522e4 <_Z12JS_Math_atanR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2522c0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2522c4 cmp r0, #1 */
/* @0x2522c8 beq 0x2522f4 <_Z12JS_Math_atanR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2522cc mov r1, r5 */
/* @0x2522d0 mov r0, r4 */
/* @0x2522d4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2522d8 bl 0xb6c64 <atan@plt> */
/* @0x2522dc stm r4, {r0, r1} */
/* @0x2522e0 pop {r3, r4, r5, pc} */
/* @0x2522e4 mvn r2, #0 */
/* @0x2522e8 mvn r3, #-2147483648 */
/* @0x2522ec stm r0, {r2, r3} */
/* @0x2522f0 pop {r3, r4, r5, pc} */
/* @0x2522f4 ldr r0, [pc, #0x8] */
/* @0x2522f8 pop {r3, r4, r5, lr} */
/* @0x2522fc add r0, pc, r0 */
/* @0x252300 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252304 andseq r3, r0, r12, asr #24 */

/* ── FUNC 0x252308 · JS_Math_atan2(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x252308 cmp r3, #1 */
/* @0x25230c push {r4, r5, r6, r7, r8, lr} */
/* @0x252310 mov r7, #0 */
/* @0x252314 sub sp, sp, #32 */
/* @0x252318 mov r6, r0 */
/* @0x25231c str r7, [r0, #0xc] */
/* @0x252320 ble 0x2523b4 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x252324 ldr r1, [sp, #0x38] */
/* @0x252328 mov r0, sp */
/* @0x25232c mov r3, #5 */
/* @0x252330 str r3, [sp, #0xc] */
/* @0x252334 str r3, [sp, #0x1c] */
/* @0x252338 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x25233c cmp r0, #1 */
/* @0x252340 beq 0x2523a0 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x252344 ldr r3, [sp, #0x38] */
/* @0x252348 add r8, sp, #16 */
/* @0x25234c add r1, r3, #16 */
/* @0x252350 mov r0, r8 */
/* @0x252354 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252358 cmp r0, #1 */
/* @0x25235c beq 0x2523a0 <_Z13JS_Math_atan2R6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x252360 mov r0, sp */
/* @0x252364 mov r1, r7 */
/* @0x252368 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x25236c mov r4, r0 */
/* @0x252370 mov r5, r1 */
/* @0x252374 mov r0, r8 */
/* @0x252378 mov r1, r7 */
/* @0x25237c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252380 mov r2, r0 */
/* @0x252384 mov r3, r1 */
/* @0x252388 mov r0, r4 */
/* @0x25238c mov r1, r5 */
/* @0x252390 bl 0xb6c70 <atan2@plt> */
/* @0x252394 stm r6, {r0, r1} */
/* @0x252398 add sp, sp, #32 */
/* @0x25239c pop {r4, r5, r6, r7, r8, pc} */
/* @0x2523a0 ldr r0, [pc, #0x20] */
/* @0x2523a4 add r0, pc, r0 */
/* @0x2523a8 bl 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2523ac add sp, sp, #32 */
/* @0x2523b0 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2523b4 mvn r2, #0 */
/* @0x2523b8 mvn r3, #-2147483648 */
/* @0x2523bc stm r0, {r2, r3} */
/* @0x2523c0 add sp, sp, #32 */
/* @0x2523c4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x2523c8 andseq r3, r0, r4, lsr #23 */

/* ── FUNC 0x2523cc · JS_Math_ceil(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x2523cc cmp r3, #0 */
/* @0x2523d0 push {r3, r4, r5, lr} */
/* @0x2523d4 mov r5, #0 */
/* @0x2523d8 mov r4, r0 */
/* @0x2523dc ldr r1, [sp, #0x10] */
/* @0x2523e0 str r5, [r0, #0xc] */
/* @0x2523e4 ble 0x25240c <_Z12JS_Math_ceilR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2523e8 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2523ec cmp r0, #1 */
/* @0x2523f0 beq 0x25241c <_Z12JS_Math_ceilR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2523f4 mov r1, r5 */
/* @0x2523f8 mov r0, r4 */
/* @0x2523fc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252400 bl 0xb670c <ceil@plt> */
/* @0x252404 stm r4, {r0, r1} */
/* @0x252408 pop {r3, r4, r5, pc} */
/* @0x25240c mvn r2, #0 */
/* @0x252410 mvn r3, #-2147483648 */
/* @0x252414 stm r0, {r2, r3} */
/* @0x252418 pop {r3, r4, r5, pc} */
/* @0x25241c ldr r0, [pc, #0x8] */
/* @0x252420 pop {r3, r4, r5, lr} */
/* @0x252424 add r0, pc, r0 */
/* @0x252428 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x25242c andseq r3, r0, r4, lsr #22 */

/* ── FUNC 0x252430 · JS_Math_cos(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x252430 cmp r3, #0 */
/* @0x252434 push {r3, r4, r5, lr} */
/* @0x252438 mov r5, #0 */
/* @0x25243c mov r4, r0 */
/* @0x252440 ldr r1, [sp, #0x10] */
/* @0x252444 str r5, [r0, #0xc] */
/* @0x252448 ble 0x252470 <_Z11JS_Math_cosR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x25244c bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252450 cmp r0, #1 */
/* @0x252454 beq 0x252480 <_Z11JS_Math_cosR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252458 mov r1, r5 */
/* @0x25245c mov r0, r4 */
/* @0x252460 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x252464 bl 0xb67e4 <cos@plt> */
/* @0x252468 stm r4, {r0, r1} */
/* @0x25246c pop {r3, r4, r5, pc} */
/* @0x252470 mvn r2, #0 */
/* @0x252474 mvn r3, #-2147483648 */
/* @0x252478 stm r0, {r2, r3} */
/* @0x25247c pop {r3, r4, r5, pc} */
/* @0x252480 ldr r0, [pc, #0x8] */
/* @0x252484 pop {r3, r4, r5, lr} */
/* @0x252488 add r0, pc, r0 */
/* @0x25248c b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252490 andseq r3, r0, r0, asr #21 */

/* ── FUNC 0x252494 · JS_Math_exp(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x252494 cmp r3, #0 */
/* @0x252498 push {r3, r4, r5, lr} */
/* @0x25249c mov r5, #0 */
/* @0x2524a0 mov r4, r0 */
/* @0x2524a4 ldr r1, [sp, #0x10] */
/* @0x2524a8 str r5, [r0, #0xc] */
/* @0x2524ac ble 0x2524d4 <_Z11JS_Math_expR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x2524b0 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x2524b4 cmp r0, #1 */
/* @0x2524b8 beq 0x2524e4 <_Z11JS_Math_expR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x2524bc mov r1, r5 */
/* @0x2524c0 mov r0, r4 */
/* @0x2524c4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x2524c8 bl 0xb6724 <exp@plt> */
/* @0x2524cc stm r4, {r0, r1} */
/* @0x2524d0 pop {r3, r4, r5, pc} */
/* @0x2524d4 mvn r2, #0 */
/* @0x2524d8 mvn r3, #-2147483648 */
/* @0x2524dc stm r0, {r2, r3} */
/* @0x2524e0 pop {r3, r4, r5, pc} */
/* @0x2524e4 ldr r0, [pc, #0x8] */
/* @0x2524e8 pop {r3, r4, r5, lr} */
/* @0x2524ec add r0, pc, r0 */
/* @0x2524f0 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x2524f4 andseq r3, r0, r12, asr r10 */

/* ── FUNC 0x2524f8 · JS_Math_floor(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x2524f8 cmp r3, #0 */
/* @0x2524fc push {r3, r4, r5, lr} */
/* @0x252500 mov r5, #0 */
/* @0x252504 mov r4, r0 */
/* @0x252508 ldr r1, [sp, #0x10] */
/* @0x25250c str r5, [r0, #0xc] */
/* @0x252510 ble 0x252538 <_Z13JS_Math_floorR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x252514 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_> */
/* @0x252518 cmp r0, #1 */
/* @0x25251c beq 0x252548 <_Z13JS_Math_floorR6RValueP9CInstanceS2_iPS_+0x50> */
/* @0x252520 mov r1, r5 */
/* @0x252524 mov r0, r4 */
/* @0x252528 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x25252c bl 0xb6598 <floor@plt> */
/* @0x252530 stm r4, {r0, r1} */
/* @0x252534 pop {r3, r4, r5, pc} */
/* @0x252538 mvn r2, #0 */
/* @0x25253c mvn r3, #-2147483648 */
/* @0x252540 stm r0, {r2, r3} */
/* @0x252544 pop {r3, r4, r5, pc} */
/* @0x252548 ldr r0, [pc, #0x8] */
/* @0x25254c pop {r3, r4, r5, lr} */
/* @0x252550 add r0, pc, r0 */
/* @0x252554 b 0x24e58c <_Z16JSThrowTypeErrorPKc> */
/* @0x252558 ldrsheq r3, [r0], -r8 */
