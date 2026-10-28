/* libyoyo.so 覆盖卡组 0216
 * 函数 0x23c748..0x23d968，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x23c748 · C_UTF16String::~C_UTF16String() · size=72 · insn=18 */
/* @0x23c748 push {r4, lr} */
/* @0x23c74c mov r4, r0 */
/* @0x23c750 ldr r0, [r0, #0x4] */
/* @0x23c754 ldr r3, [pc, #0x2c] */
/* @0x23c758 cmp r0, #0 */
/* @0x23c75c ldr r3, [pc, r3] */
/* @0x23c760 add r3, r3, #8 */
/* @0x23c764 str r3, [r4] */
/* @0x23c768 beq 0x23c770 <_ZN13C_UTF16StringD2Ev+0x28> */
/* @0x23c76c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23c770 ldr r3, [pc, #0x14] */
/* @0x23c774 mov r0, r4 */
/* @0x23c778 ldr r3, [pc, r3] */
/* @0x23c77c add r3, r3, #8 */
/* @0x23c780 str r3, [r4] */
/* @0x23c784 pop {r4, pc} */
/* @0x23c788 mulseq r11, r12, sp */
/* @0x23c78c andseq r4, r11, r8, ror sp */

/* ── FUNC 0x23c748 · C_UTF16String::~C_UTF16String() · alias of the symbol above · insn=0 */

/* ── FUNC 0x23c790 · C_UTF16String::~C_UTF16String() · size=80 · insn=20 */
/* @0x23c790 push {r4, lr} */
/* @0x23c794 mov r4, r0 */
/* @0x23c798 ldr r0, [r0, #0x4] */
/* @0x23c79c ldr r3, [pc, #0x34] */
/* @0x23c7a0 cmp r0, #0 */
/* @0x23c7a4 ldr r3, [pc, r3] */
/* @0x23c7a8 add r3, r3, #8 */
/* @0x23c7ac str r3, [r4] */
/* @0x23c7b0 beq 0x23c7b8 <_ZN13C_UTF16StringD0Ev+0x28> */
/* @0x23c7b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x23c7b8 ldr r3, [pc, #0x1c] */
/* @0x23c7bc mov r0, r4 */
/* @0x23c7c0 ldr r3, [pc, r3] */
/* @0x23c7c4 add r3, r3, #8 */
/* @0x23c7c8 str r3, [r4] */
/* @0x23c7cc bl 0x27d1d0 <_ZdlPv> */
/* @0x23c7d0 mov r0, r4 */
/* @0x23c7d4 pop {r4, pc} */
/* @0x23c7d8 andseq r4, r11, r4, asr sp */
/* @0x23c7dc andseq r4, r11, r0, lsr sp */

/* ── FUNC 0x23c7e0 · F_JSForInIteratorDelete(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x23c7e0 push {r4, lr} */
/* @0x23c7e4 ldr r4, [sp, #0x8] */
/* @0x23c7e8 ldr r3, [r4, #0xc] */
/* @0x23c7ec bic r3, r3, #-16777216 */
/* @0x23c7f0 cmp r3, #5 */
/* @0x23c7f4 popeq {r4, pc} */
/* @0x23c7f8 cmp r3, #14 */
/* @0x23c7fc beq 0x23c80c <_Z23F_JSForInIteratorDeleteR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x23c800 ldr r0, [pc, #0x10] */
/* @0x23c804 add r0, pc, r0 */
/* @0x23c808 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x23c80c ldr r0, [r4] */
/* @0x23c810 pop {r4, lr} */
/* @0x23c814 b 0x27d1d0 <_ZdlPv> */
/* @0x23c818 andseq r8, r1, r0, asr r11 */

/* ── FUNC 0x23c81c · F_JSNewProperty(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x23c81c push {r4, r5, r6, lr} */
/* @0x23c820 mvn r1, #-16777216 */
/* @0x23c824 mov r6, r0 */
/* @0x23c828 mov r2, #0 */
/* @0x23c82c mov r0, #2 */
/* @0x23c830 ldr r5, [sp, #0x10] */
/* @0x23c834 bl 0x19198c <_ZN12YYObjectBase5AllocEjib> */
/* @0x23c838 mov r3, #2 */
/* @0x23c83c str r3, [r0, #0x48] */
/* @0x23c840 mov r4, r0 */
/* @0x23c844 str r0, [r6] */
/* @0x23c848 mov r3, #6 */
/* @0x23c84c ldr r1, [r0, #0x4] */
/* @0x23c850 str r3, [r6, #0xc] */
/* @0x23c854 cmp r1, #0 */
/* @0x23c858 beq 0x23c8c8 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x23c85c ldr r3, [r5, #0x10] */
/* @0x23c860 mov r0, r4 */
/* @0x23c864 str r3, [r1] */
/* @0x23c868 ldr r1, [r5, #0x10] */
/* @0x23c86c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x23c870 ldr r1, [r4, #0x4] */
/* @0x23c874 cmp r1, #0 */
/* @0x23c878 movne r3, #11 */
/* @0x23c87c strne r3, [r1, #0xc] */
/* @0x23c880 beq 0x23c8d4 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x23c884 add r1, r1, #16 */
/* @0x23c888 ldr r3, [r5] */
/* @0x23c88c mov r0, r4 */
/* @0x23c890 str r3, [r1] */
/* @0x23c894 ldr r1, [r5] */
/* @0x23c898 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x23c89c ldr r0, [r4, #0x4] */
/* @0x23c8a0 cmp r0, #0 */
/* @0x23c8a4 beq 0x23c8b8 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x9c> */
/* @0x23c8a8 add r0, r0, #16 */
/* @0x23c8ac mov r3, #11 */
/* @0x23c8b0 str r3, [r0, #0xc] */
/* @0x23c8b4 pop {r4, r5, r6, pc} */
/* @0x23c8b8 mov r0, r4 */
/* @0x23c8bc mov r1, #1 */
/* @0x23c8c0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23c8c4 b 0x23c8ac <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x23c8c8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23c8cc mov r1, r0 */
/* @0x23c8d0 b 0x23c85c <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x40> */
/* @0x23c8d4 mov r0, r4 */
/* @0x23c8d8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23c8dc ldr r1, [r4, #0x4] */
/* @0x23c8e0 mov r3, #11 */
/* @0x23c8e4 cmp r1, #0 */
/* @0x23c8e8 str r3, [r0, #0xc] */
/* @0x23c8ec bne 0x23c884 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x23c8f0 mov r1, #1 */
/* @0x23c8f4 mov r0, r4 */
/* @0x23c8f8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23c8fc mov r1, r0 */
/* @0x23c900 b 0x23c888 <_Z15F_JSNewPropertyR6RValueP9CInstanceS2_iPS_+0x6c> */

/* ── FUNC 0x23c904 · F_JSTypeof(RValue&, CInstance*, CInstance*, int, RValue*) · size=264 · insn=66 */
/* @0x23c904 ldr r2, [sp] */
/* @0x23c908 ldr r3, [r2, #0xc] */
/* @0x23c90c bic r3, r3, #-16777216 */
/* @0x23c910 cmp r3, #7 */
/* @0x23c914 beq 0x23c9b0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x23c918 bgt 0x23c95c <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x23c91c cmp r3, #1 */
/* @0x23c920 beq 0x23c990 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x23c924 ble 0x23c9a8 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xa4> */
/* @0x23c928 cmp r3, #5 */
/* @0x23c92c beq 0x23c984 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x23c930 cmp r3, #6 */
/* @0x23c934 bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x23c938 ldr r3, [r2] */
/* @0x23c93c cmp r3, #0 */
/* @0x23c940 beq 0x23c9dc <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x23c944 ldr r3, [r3, #0x48] */
/* @0x23c948 cmp r3, #3 */
/* @0x23c94c beq 0x23c9d0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xcc> */
/* @0x23c950 ldr r1, [pc, #0x90] */
/* @0x23c954 add r1, pc, r1 */
/* @0x23c958 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c95c cmp r3, #12 */
/* @0x23c960 beq 0x23c99c <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x23c964 ble 0x23c9bc <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x23c968 ldr r1, [pc, #0x7c] */
/* @0x23c96c cmp r3, #13 */
/* @0x23c970 add r1, pc, r1 */
/* @0x23c974 beq 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x23c978 mvn r2, #-16777216 */
/* @0x23c97c cmp r3, r2 */
/* @0x23c980 bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x23c984 ldr r1, [pc, #0x64] */
/* @0x23c988 add r1, pc, r1 */
/* @0x23c98c b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c990 ldr r1, [pc, #0x5c] */
/* @0x23c994 add r1, pc, r1 */
/* @0x23c998 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c99c ldr r1, [pc, #0x54] */
/* @0x23c9a0 add r1, pc, r1 */
/* @0x23c9a4 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c9a8 cmp r3, #0 */
/* @0x23c9ac bne 0x23c9c4 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x23c9b0 ldr r1, [pc, #0x44] */
/* @0x23c9b4 add r1, pc, r1 */
/* @0x23c9b8 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c9bc cmp r3, #10 */
/* @0x23c9c0 beq 0x23c9b0 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0xac> */
/* @0x23c9c4 ldr r1, [pc, #0x34] */
/* @0x23c9c8 add r1, pc, r1 */
/* @0x23c9cc b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23c9d0 ldr r1, [pc, #0x2c] */
/* @0x23c9d4 add r1, pc, r1 */
/* @0x23c9d8 b 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x23c9dc ldr r1, [pc, #0x24] */
/* @0x23c9e0 add r1, pc, r1 */
/* @0x23c9e4 b 0x23c958 <_Z10F_JSTypeofR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x23c9e8 andeq r5, pc, r4, ror #17 */
/* @0x23c9ec andseq r8, r1, r0, asr r10 */
/* @0x23c9f0 ldrdeq r5, r6, [pc], -r8 */
/* @0x23c9f4 muleq pc, r4, lr */
/* @0x23c9f8 muleq pc, r8, r8 */
/* @0x23c9fc muleq pc, r4, r8 */
/* @0x23ca00 andseq r8, r1, r12, ror #19 */
/* @0x23ca04 ldrsheq r8, [r1], -r4 */
/* @0x23ca08 andeq r5, pc, r8, asr r8 */

/* ── FUNC 0x23ca0c · F_JSTryHook(RValue&, CInstance*, CInstance*, int, RValue*) · size=96 · insn=24 */
/* @0x23ca0c ldr r3, [pc, #0x54] */
/* @0x23ca10 push {r4, r5, r6, lr} */
/* @0x23ca14 ldr r3, [pc, r3] */
/* @0x23ca18 ldr r6, [sp, #0x10] */
/* @0x23ca1c ldr r3, [r3] */
/* @0x23ca20 ldr r5, [r3, #0x28] */
/* @0x23ca24 cmp r5, #0 */
/* @0x23ca28 popeq {r4, r5, r6, pc} */
/* @0x23ca2c mov r0, #12 */
/* @0x23ca30 bl 0x27c524 <_Znwj> */
/* @0x23ca34 ldr r3, [r5, #0x28] */
/* @0x23ca38 mov r1, #0 */
/* @0x23ca3c mov r4, r0 */
/* @0x23ca40 mov r0, r6 */
/* @0x23ca44 str r3, [r4] */
/* @0x23ca48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x23ca4c mov r1, #1 */
/* @0x23ca50 str r0, [r4, #0x4] */
/* @0x23ca54 mov r0, r6 */
/* @0x23ca58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x23ca5c str r0, [r4, #0x8] */
/* @0x23ca60 str r4, [r5, #0x28] */
/* @0x23ca64 pop {r4, r5, r6, pc} */
/* @0x23ca68 mulseq r11, r4, r1 */

/* ── FUNC 0x23ca6c · F_JSError(RValue&, CInstance*, CInstance*, int, RValue*) · size=24 · insn=6 */
/* @0x23ca6c push {r3, lr} */
/* @0x23ca70 mov r1, #0 */
/* @0x23ca74 ldr r0, [sp, #0x8] */
/* @0x23ca78 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x23ca7c pop {r3, lr} */
/* @0x23ca80 b 0xd547c <_Z7YYErrorPKcz> */

/* ── FUNC 0x23ca84 · F_JSPrint(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x23ca84 push {r3, r4, r5, lr} */
/* @0x23ca88 mov r1, #0 */
/* @0x23ca8c ldr r3, [pc, #0x24] */
/* @0x23ca90 ldr r0, [sp, #0x10] */
/* @0x23ca94 ldr r3, [pc, r3] */
/* @0x23ca98 ldr r4, [r3] */
/* @0x23ca9c ldr r3, [r4] */
/* @0x23caa0 ldr r5, [r3, #0xc] */
/* @0x23caa4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0x23caa8 mov r1, r0 */
/* @0x23caac mov r0, r4 */
/* @0x23cab0 blx r5 */
/* @0x23cab4 pop {r3, r4, r5, pc} */
/* @0x23cab8 andseq r0, r11, r0, lsl #25 */

/* ── FUNC 0x23cabc · JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*) · size=136 · insn=34 */
/* @0x23cabc push {r3, r4, r5, lr} */
/* @0x23cac0 mov r4, r0 */
/* @0x23cac4 bl 0xdc37c <_Z13YYSetInstanceP6RValue> */
/* @0x23cac8 ldr r5, [pc, #0x5c] */
/* @0x23cacc ldr r3, [pc, #0x5c] */
/* @0x23cad0 add r5, pc, r5 */
/* @0x23cad4 ldr r4, [r4] */
/* @0x23cad8 ldr r3, [r5, r3] */
/* @0x23cadc mov r0, r4 */
/* @0x23cae0 ldr r1, [r3] */
/* @0x23cae4 str r1, [r4, #0x18] */
/* @0x23cae8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x23caec ldr r3, [pc, #0x40] */
/* @0x23caf0 ldr r1, [r4, #0x28] */
/* @0x23caf4 ldr r2, [pc, #0x3c] */
/* @0x23caf8 orr r1, r1, #1 */
/* @0x23cafc str r1, [r4, #0x28] */
/* @0x23cb00 add r2, pc, r2 */
/* @0x23cb04 str r2, [r4, #0x40] */
/* @0x23cb08 ldr r2, [pc, #0x2c] */
/* @0x23cb0c ldr r1, [r5, r3] */
/* @0x23cb10 ldr r3, [pc, #0x28] */
/* @0x23cb14 str r1, [r4, #0x4c] */
/* @0x23cb18 ldr r2, [r5, r2] */
/* @0x23cb1c str r2, [r4, #0x50] */
/* @0x23cb20 ldr r3, [r5, r3] */
/* @0x23cb24 str r3, [r4, #0x54] */
/* @0x23cb28 pop {r3, r4, r5, pc} */
/* @0x23cb2c andseq r5, r11, r0, lsl #3 */
/* @0x23cb30 .word 0xffffc050 */
/* @0x23cb34 .word 0xfffff8ac */
/* @0x23cb38 ldrsbeq r8, [r1], -r4 */
/* @0x23cb3c .word 0xfffff8b0 */
/* @0x23cb40 .word 0xfffff8b4 */

/* ── FUNC 0x23cb44 · F_JS_Object_prototype_toString(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0x23cb44 push {r4, r5, r6, r7, r11, lr} */
/* @0x23cb48 add r11, sp, #20 */
/* @0x23cb4c ldr r4, [pc, #0x80] */
/* @0x23cb50 sub sp, sp, #16 */
/* @0x23cb54 mov r7, r0 */
/* @0x23cb58 ldr r4, [pc, r4] */
/* @0x23cb5c ldr r6, [r1, #0x40] */
/* @0x23cb60 ldr r3, [r4] */
/* @0x23cb64 mov r0, r6 */
/* @0x23cb68 str r3, [r11, #-0x18] */
/* @0x23cb6c bl 0xb6538 <strlen@plt> */
/* @0x23cb70 ldr r3, [pc, #0x60] */
/* @0x23cb74 add r3, pc, r3 */
/* @0x23cb78 add r2, r0, #24 */
/* @0x23cb7c add r1, r0, #10 */
/* @0x23cb80 bic r2, r2, #7 */
/* @0x23cb84 sub sp, sp, r2 */
/* @0x23cb88 ldr r2, [pc, #0x4c] */
/* @0x23cb8c add r5, sp, #8 */
/* @0x23cb90 str r3, [sp, #0x4] */
/* @0x23cb94 add r2, pc, r2 */
/* @0x23cb98 ldr r3, [pc, #0x40] */
/* @0x23cb9c mov r0, r5 */
/* @0x23cba0 str r6, [sp] */
/* @0x23cba4 add r3, pc, r3 */
/* @0x23cba8 bl 0xb65c8 <snprintf@plt> */
/* @0x23cbac mov r0, r7 */
/* @0x23cbb0 mov r1, r5 */
/* @0x23cbb4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23cbb8 ldr r2, [r11, #-0x18] */
/* @0x23cbbc ldr r3, [r4] */
/* @0x23cbc0 cmp r2, r3 */
/* @0x23cbc4 bne 0x23cbd0 <_Z30F_JS_Object_prototype_toStringR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x23cbc8 sub sp, r11, #20 */
/* @0x23cbcc pop {r4, r5, r6, r7, r11, pc} */
/* @0x23cbd0 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x23cbd4 ldrsheq r0, [r11], -r8 */
/* @0x23cbd8 andseq r8, r1, r4, ror r8 */
/* @0x23cbdc andeq r10, pc, r12, lsr #25 */
/* @0x23cbe0 andseq r8, r1, r8, lsr r8 */

/* ── FUNC 0x23cbe4 · F_NewGMLArray(RValue&, CInstance*, CInstance*, int, RValue*) · size=92 · insn=23 */
/* @0x23cbe4 push {r3, r4, r5, r6, r7, lr} */
/* @0x23cbe8 mov r2, #2 */
/* @0x23cbec str r2, [r0, #0xc] */
/* @0x23cbf0 mov r7, r3 */
/* @0x23cbf4 mov r6, r0 */
/* @0x23cbf8 ldr r5, [sp, #0x18] */
/* @0x23cbfc bl 0xced9c <_Z14ARRAY_RefAllocPv> */
/* @0x23cc00 str r0, [r6] */
/* @0x23cc04 mov r0, #0 */
/* @0x23cc08 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x23cc0c cmp r7, #0 */
/* @0x23cc10 movgt r4, #0 */
/* @0x23cc14 ble 0x23cc38 <_Z13F_NewGMLArrayR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0x23cc18 mov r1, r5 */
/* @0x23cc1c mov r2, r4 */
/* @0x23cc20 mov r0, r6 */
/* @0x23cc24 add r4, r4, #1 */
/* @0x23cc28 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i> */
/* @0x23cc2c cmp r4, r7 */
/* @0x23cc30 add r5, r5, #16 */
/* @0x23cc34 bne 0x23cc18 <_Z13F_NewGMLArrayR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x23cc38 pop {r3, r4, r5, r6, r7, lr} */
/* @0x23cc3c b 0xd3a34 <_Z15PopContextStackv> */

/* ── FUNC 0x23cc40 · JS_Math_random(RValue&, CInstance*, CInstance*, int, RValue*) · size=56 · insn=14 */
/* @0x23cc40 push {r4, lr} */
/* @0x23cc44 mov r3, #0 */
/* @0x23cc48 str r3, [r0, #0xc] */
/* @0x23cc4c mov r4, r0 */
/* @0x23cc50 bl 0xb6c10 <lrand48@plt> */
/* @0x23cc54 vldr d7, [pc, #20] */
/* @0x23cc58 vmov s10, r0 */
/* @0x23cc5c vcvt.f64.s32 d6, s10 */
/* @0x23cc60 vdiv.f64 d5, d6, d7 */
/* @0x23cc64 vmov r2, r3, d5 */
/* @0x23cc68 stm r4, {r2, r3} */
/* @0x23cc6c pop {r4, pc} */
/* @0x23cc70 .word 0xffc00000 */
/* @0x23cc74 ldrshmi pc, [pc, #255] */

/* ── FUNC 0x23cc78 · JS_JSON_stringify(RValue&, CInstance*, CInstance*, int, RValue*) · size=36 · insn=9 */
/* @0x23cc78 push {r4, lr} */
/* @0x23cc7c mov r4, r0 */
/* @0x23cc80 ldr r0, [sp, #0x8] */
/* @0x23cc84 bl 0x13be2c <_Z11EncodeValueP6RValue> */
/* @0x23cc88 bl 0x27e830 <json_object_to_json_string> */
/* @0x23cc8c mov r1, r0 */
/* @0x23cc90 mov r0, r4 */
/* @0x23cc94 pop {r4, lr} */
/* @0x23cc98 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */

/* ── FUNC 0x23cc9c · F_JS_Object_prototype_isPrototypeOf(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0x23cc9c ldr r3, [sp] */
/* @0x23cca0 ldr r2, [r3, #0xc] */
/* @0x23cca4 cmp r2, #6 */
/* @0x23cca8 beq 0x23ccc0 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x24> */
/* @0x23ccac mov r3, #0 */
/* @0x23ccb0 str r3, [r0, #0xc] */
/* @0x23ccb4 str r3, [r0] */
/* @0x23ccb8 str r3, [r0, #0x4] */
/* @0x23ccbc bx lr */
/* @0x23ccc0 ldr r3, [r3] */
/* @0x23ccc4 b 0x23ccd0 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x34> */
/* @0x23ccc8 cmp r1, r3 */
/* @0x23cccc beq 0x23ccf4 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x23ccd0 ldr r3, [r3, #0x18] */
/* @0x23ccd4 cmp r3, #0 */
/* @0x23ccd8 bne 0x23ccc8 <_Z35F_JS_Object_prototype_isPrototypeOfR6RValueP9CInstanceS2_iPS_+0x2c> */
/* @0x23ccdc mov r3, #0 */
/* @0x23cce0 mov r2, #13 */
/* @0x23cce4 str r3, [r0] */
/* @0x23cce8 str r2, [r0, #0xc] */
/* @0x23ccec str r3, [r0, #0x4] */
/* @0x23ccf0 bx lr */
/* @0x23ccf4 mov r3, #0 */
/* @0x23ccf8 mov r2, #13 */
/* @0x23ccfc movt r3, #0x3ff0 */
/* @0x23cd00 str r2, [r0, #0xc] */
/* @0x23cd04 str r3, [r0, #0x4] */
/* @0x23cd08 mov r3, #0 */
/* @0x23cd0c str r3, [r0] */
/* @0x23cd10 bx lr */

/* ── FUNC 0x23cd14 · F_JS_Array_isArray(RValue&, CInstance*, CInstance*, int, RValue*) · size=112 · insn=28 */
/* @0x23cd14 cmp r3, #0 */
/* @0x23cd18 mov r3, #13 */
/* @0x23cd1c push {r4, lr} */
/* @0x23cd20 mov r4, r0 */
/* @0x23cd24 str r3, [r0, #0xc] */
/* @0x23cd28 beq 0x23cd3c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x23cd2c ldr r2, [sp, #0x8] */
/* @0x23cd30 ldr r3, [r2, #0xc] */
/* @0x23cd34 cmp r3, #6 */
/* @0x23cd38 beq 0x23cd4c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x23cd3c mov r3, #0 */
/* @0x23cd40 str r3, [r4] */
/* @0x23cd44 str r3, [r4, #0x4] */
/* @0x23cd48 pop {r4, pc} */
/* @0x23cd4c ldr r2, [sp, #0x8] */
/* @0x23cd50 ldr r1, [pc, #0x28] */
/* @0x23cd54 ldr r3, [r2] */
/* @0x23cd58 add r1, pc, r1 */
/* @0x23cd5c ldr r0, [r3, #0x40] */
/* @0x23cd60 bl 0xb6574 <strcmp@plt> */
/* @0x23cd64 cmp r0, #0 */
/* @0x23cd68 bne 0x23cd3c <_Z18F_JS_Array_isArrayR6RValueP9CInstanceS2_iPS_+0x28> */
/* @0x23cd6c mov r3, #0 */
/* @0x23cd70 str r0, [r4] */
/* @0x23cd74 movt r3, #0x3ff0 */
/* @0x23cd78 str r3, [r4, #0x4] */
/* @0x23cd7c pop {r4, pc} */
/* @0x23cd80 andeq r7, pc, r0, asr #23 */

/* ── FUNC 0x23cd84 · HasInstance(YYObjectBase*, RValue*) · size=160 · insn=40 */
/* @0x23cd84 ldr r3, [r1, #0xc] */
/* @0x23cd88 push {r4, r5, r6, lr} */
/* @0x23cd8c bic r3, r3, #-16777216 */
/* @0x23cd90 cmp r3, #6 */
/* @0x23cd94 mov r5, r1 */
/* @0x23cd98 beq 0x23cda4 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x20> */
/* @0x23cd9c mov r0, #0 */
/* @0x23cda0 pop {r4, r5, r6, pc} */
/* @0x23cda4 ldr r6, [r0, #0x4] */
/* @0x23cda8 cmp r6, #0 */
/* @0x23cdac beq 0x23ce14 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x90> */
/* @0x23cdb0 ldr r3, [r6, #0xc] */
/* @0x23cdb4 bic r3, r3, #-16777216 */
/* @0x23cdb8 cmp r3, #6 */
/* @0x23cdbc beq 0x23cdc8 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x44> */
/* @0x23cdc0 mov r0, #2 */
/* @0x23cdc4 pop {r4, r5, r6, pc} */
/* @0x23cdc8 ldr r0, [r5] */
/* @0x23cdcc ldr r4, [r0, #0x18] */
/* @0x23cdd0 cmp r4, #0 */
/* @0x23cdd4 beq 0x23cd9c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x18> */
/* @0x23cdd8 ldr r3, [r6] */
/* @0x23cddc cmp r4, r3 */
/* @0x23cde0 bne 0x23cdec <_Z11HasInstanceP12YYObjectBaseP6RValue+0x68> */
/* @0x23cde4 b 0x23ce0c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x88> */
/* @0x23cde8 ldr r0, [r5] */
/* @0x23cdec ldr r4, [r4, #0x18] */
/* @0x23cdf0 mov r1, r4 */
/* @0x23cdf4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x23cdf8 cmp r4, #0 */
/* @0x23cdfc beq 0x23cd9c <_Z11HasInstanceP12YYObjectBaseP6RValue+0x18> */
/* @0x23ce00 ldr r3, [r6] */
/* @0x23ce04 cmp r3, r4 */
/* @0x23ce08 bne 0x23cde8 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x64> */
/* @0x23ce0c mov r0, #1 */
/* @0x23ce10 pop {r4, r5, r6, pc} */
/* @0x23ce14 mov r1, r6 */
/* @0x23ce18 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23ce1c mov r6, r0 */
/* @0x23ce20 b 0x23cdb0 <_Z11HasInstanceP12YYObjectBaseP6RValue+0x2c> */

/* ── FUNC 0x23ce24 · F_JS_Array_getLength(RValue&, CInstance*, CInstance*, int, RValue*) · size=128 · insn=32 */
/* @0x23ce24 push {r3, r4, r5, lr} */
/* @0x23ce28 mov r5, r1 */
/* @0x23ce2c ldr r1, [pc, #0x6c] */
/* @0x23ce30 mov r3, #0 */
/* @0x23ce34 mov r4, r0 */
/* @0x23ce38 str r3, [r0] */
/* @0x23ce3c str r3, [r0, #0x4] */
/* @0x23ce40 add r1, pc, r1 */
/* @0x23ce44 str r3, [r0, #0xc] */
/* @0x23ce48 ldr r0, [r5, #0x40] */
/* @0x23ce4c bl 0xb6574 <strcmp@plt> */
/* @0x23ce50 cmp r0, #0 */
/* @0x23ce54 popne {r3, r4, r5, pc} */
/* @0x23ce58 ldr r0, [r5, #0x4] */
/* @0x23ce5c cmp r0, #0 */
/* @0x23ce60 beq 0x23ce90 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x6c> */
/* @0x23ce64 add r0, r0, #16 */
/* @0x23ce68 ldr r3, [r0, #0xc] */
/* @0x23ce6c cmp r3, #6 */
/* @0x23ce70 popne {r3, r4, r5, pc} */
/* @0x23ce74 ldr r3, [r0] */
/* @0x23ce78 ldr r2, [r3, #0x24] */
/* @0x23ce7c vmov s15, r2 */
/* @0x23ce80 vcvt.f64.u32 d7, s15 */
/* @0x23ce84 vmov r2, r3, d7 */
/* @0x23ce88 stm r4, {r2, r3} */
/* @0x23ce8c pop {r3, r4, r5, pc} */
/* @0x23ce90 mov r0, r5 */
/* @0x23ce94 mov r1, #1 */
/* @0x23ce98 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */
/* @0x23ce9c b 0x23ce68 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x23cea0 ldrdeq r7, r8, [pc], -r8 */

/* ── FUNC 0x23cea4 · anon_23cea4 · size=588 · insn=147 */
/* @0x23cea4 andeq r0, r0, r0 */
/* @0x23cea8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23ceac mov r5, r3 */
/* @0x23ceb0 add r11, sp, #32 */
/* @0x23ceb4 ldr r8, [pc, #0x22c] */
/* @0x23ceb8 sub sp, sp, #20 */
/* @0x23cebc add r3, r3, r3, lsl #1 */
/* @0x23cec0 str r1, [r11, #-0x30] */
/* @0x23cec4 lsl r3, r3, #1 */
/* @0x23cec8 ldr r8, [pc, r8] */
/* @0x23cecc add r1, r3, #15 */
/* @0x23ced0 mov r7, r0 */
/* @0x23ced4 bic r1, r1, #7 */
/* @0x23ced8 ldr r0, [r8] */
/* @0x23cedc sub sp, sp, r1 */
/* @0x23cee0 mov r4, r2 */
/* @0x23cee4 mov r1, #0 */
/* @0x23cee8 add r2, r3, #1 */
/* @0x23ceec str r0, [r11, #-0x28] */
/* @0x23cef0 add r5, r5, r4 */
/* @0x23cef4 mov r0, sp */
/* @0x23cef8 mov r6, sp */
/* @0x23cefc bl 0xb65b0 <memset@plt> */
/* @0x23cf00 cmp r4, r5 */
/* @0x23cf04 bge 0x23cfe8 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x23cf08 movw r10, #0xfffe */
/* @0x23cf0c movt r10, #0x1f */
/* @0x23cf10 mov r0, #0 */
/* @0x23cf14 movw r9, #0x7fe */
/* @0x23cf18 vldr d6, [pc, #432] */
/* @0x23cf1c vldr d5, [pc, #436] */
/* @0x23cf20 vldr d4, [pc, #440] */
/* @0x23cf24 sub r1, r4, #-2147483647 */
/* @0x23cf28 ldr r3, [r7] */
/* @0x23cf2c mov r12, #0 */
/* @0x23cf30 mov lr, #1 */
/* @0x23cf34 add r1, r3, r1, lsl #1 */
/* @0x23cf38 b 0x23cf40 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x23cf3c mov lr, r2 */
/* @0x23cf40 ldrh r3, [r1, #2]! */
/* @0x23cf44 vmov s7, r3 */
/* @0x23cf48 vcvt.f64.u32 d7, s7 */
/* @0x23cf4c vcmpe.f64 d7, d6 */
/* @0x23cf50 vmrs APSR_nzcv, fpscr */
/* @0x23cf54 bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x23cf58 vcmpe.f64 d7, d5 */
/* @0x23cf5c vmrs APSR_nzcv, fpscr */
/* @0x23cf60 ble 0x23cf70 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x23cf64 vcmpe.f64 d7, d4 */
/* @0x23cf68 vmrs APSR_nzcv, fpscr */
/* @0x23cf6c bls 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x23cf70 and r2, r3, #1024 */
/* @0x23cf74 uxth r2, r2 */
/* @0x23cf78 cmp r2, #0 */
/* @0x23cf7c bne 0x23d00c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x23cf80 add r4, r4, #1 */
/* @0x23cf84 cmp r5, r4 */
/* @0x23cf88 beq 0x23d01c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x23cf8c sub r12, r3, #55296 */
/* @0x23cf90 lsl r12, r12, #10 */
/* @0x23cf94 add r12, r12, #65536 */
/* @0x23cf98 bgt 0x23cf3c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x23cf9c cmp r12, #126 */
/* @0x23cfa0 strble r12, [r6, r0] */
/* @0x23cfa4 addle r0, r0, #1 */
/* @0x23cfa8 ble 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x23cfac cmp r12, r9 */
/* @0x23cfb0 bgt 0x23d024 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x23cfb4 ubfx r3, r12, #0x6, #0x5 */
/* @0x23cfb8 and r12, r12, #63 */
/* @0x23cfbc add r2, r0, #1 */
/* @0x23cfc0 mvn r3, r3, lsl #26 */
/* @0x23cfc4 mvn r12, r12, lsl #25 */
/* @0x23cfc8 mvn r3, r3, lsr #26 */
/* @0x23cfcc strb r3, [r6, r0] */
/* @0x23cfd0 add r0, r0, #2 */
/* @0x23cfd4 mvn r12, r12, lsr #25 */
/* @0x23cfd8 strb r12, [r6, r2] */
/* @0x23cfdc add r4, r4, #1 */
/* @0x23cfe0 cmp r5, r4 */
/* @0x23cfe4 bgt 0x23cf24 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x23cfe8 ldr r0, [r11, #-0x30] */
/* @0x23cfec mov r1, r6 */
/* @0x23cff0 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0x23cff4 ldr r2, [r11, #-0x28] */
/* @0x23cff8 ldr r3, [r8] */
/* @0x23cffc cmp r2, r3 */
/* @0x23d000 bne 0x23d0cc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x23d004 sub sp, r11, #32 */
/* @0x23d008 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23d00c cmp lr, #0 */
/* @0x23d010 subeq r3, r3, #56320 */
/* @0x23d014 orreq r12, r12, r3 */
/* @0x23d018 beq 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x23d01c mov r12, r3 */
/* @0x23d020 b 0x23cf9c <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x23d024 movw r3, #0xfffe */
/* @0x23d028 cmp r12, r3 */
/* @0x23d02c bgt 0x23d070 <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x23d030 ubfx r2, r12, #0xc, #0x4 */
/* @0x23d034 ubfx lr, r12, #0x6, #0x6 */
/* @0x23d038 and r12, r12, #63 */
/* @0x23d03c add r1, r0, #2 */
/* @0x23d040 mov r3, r6 */
/* @0x23d044 mvn r2, r2, lsl #27 */
/* @0x23d048 mvn lr, lr, lsl #25 */
/* @0x23d04c mvn r12, r12, lsl #25 */
/* @0x23d050 mvn r2, r2, lsr #27 */
/* @0x23d054 mvn lr, lr, lsr #25 */
/* @0x23d058 strb r2, [r3, r0]! */
/* @0x23d05c mvn r12, r12, lsr #25 */
/* @0x23d060 strb lr, [r3, #0x1] */
/* @0x23d064 add r0, r0, #3 */
/* @0x23d068 strb r12, [r6, r1] */
/* @0x23d06c b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x23d070 cmp r12, r10 */
/* @0x23d074 bgt 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x23d078 and r2, r12, #3670016 */
/* @0x23d07c mov r3, r6 */
/* @0x23d080 ubfx lr, r12, #0xc, #0x6 */
/* @0x23d084 ubfx r1, r12, #0x6, #0x6 */
/* @0x23d088 asr r2, r2, #18 */
/* @0x23d08c and r12, r12, #63 */
/* @0x23d090 mvn lr, lr, lsl #25 */
/* @0x23d094 mvn r1, r1, lsl #25 */
/* @0x23d098 mvn r2, r2, lsl #28 */
/* @0x23d09c mvn r12, r12, lsl #25 */
/* @0x23d0a0 mvn r2, r2, lsr #28 */
/* @0x23d0a4 strb r2, [r3, r0]! */
/* @0x23d0a8 add r2, r0, #3 */
/* @0x23d0ac mvn lr, lr, lsr #25 */
/* @0x23d0b0 mvn r1, r1, lsr #25 */
/* @0x23d0b4 strb lr, [r3, #0x1] */
/* @0x23d0b8 mvn r12, r12, lsr #25 */
/* @0x23d0bc strb r1, [r3, #0x2] */
/* @0x23d0c0 add r0, r0, #4 */
/* @0x23d0c4 strb r12, [r6, r2] */
/* @0x23d0c8 b 0x23cfdc <_Z20F_JS_Array_getLengthR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x23d0cc bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x23d0d0 andeq r0, r0, r0 */
/* @0x23d0d4 rscmi pc, r10, r0, ror #31 */
/* @0x23d0d8 andeq r0, r0, r0 */
/* @0x23d0dc rscmi r0, r12, r0 */
/* @0x23d0e0 andeq r0, r0, r0 */
/* @0x23d0e4 rscmi pc, pc, r0, ror #31 */
/* @0x23d0e8 andseq r0, r11, r8, lsl #21 */
/* @0x23d0ec nop */

/* ── FUNC 0x23d0f0 · JS_DefaultGetOwnProperty(YYObjectBase*, RValue*, char const*) · size=264 · insn=66 */
/* @0x23d0f0 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23d0f4 mvn r12, #-16777216 */
/* @0x23d0f8 ldr r3, [r0, #0x60] */
/* @0x23d0fc mov r4, r0 */
/* @0x23d100 mov r8, r1 */
/* @0x23d104 str r12, [r1, #0xc] */
/* @0x23d108 cmp r3, #0 */
/* @0x23d10c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d110 mov r1, r2 */
/* @0x23d114 bl 0xd2c84 <_Z38Code_Variable_FindAlloc_Slot_From_NameP12YYObjectBasePKc> */
/* @0x23d118 ldr r4, [r4, #0x60] */
/* @0x23d11c bl 0x190f40 <_Z21CHashMapCalculateHashIiEjT_> */
/* @0x23d120 ldr r12, [r4, #0x8] */
/* @0x23d124 ldr r1, [r4, #0x10] */
/* @0x23d128 bic r0, r0, #-2147483648 */
/* @0x23d12c and r3, r0, r12 */
/* @0x23d130 lsl r5, r3, #1 */
/* @0x23d134 add r2, r5, r3 */
/* @0x23d138 add r2, r1, r2, lsl #2 */
/* @0x23d13c ldr r2, [r2, #0x8] */
/* @0x23d140 cmp r2, #0 */
/* @0x23d144 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d148 cmp r0, r2 */
/* @0x23d14c beq 0x23d1c0 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0xd0> */
/* @0x23d150 ldr r9, [r4] */
/* @0x23d154 and r2, r12, r2 */
/* @0x23d158 add r4, r3, r9 */
/* @0x23d15c rsb r2, r2, r4 */
/* @0x23d160 tst r2, r12 */
/* @0x23d164 popmi {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d168 mov r4, #0 */
/* @0x23d16c b 0x23d180 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0x90> */
/* @0x23d170 cmp r0, r2 */
/* @0x23d174 beq 0x23d1b8 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0xc8> */
/* @0x23d178 cmp r6, r4 */
/* @0x23d17c poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d180 add r3, r3, #1 */
/* @0x23d184 add r4, r4, #1 */
/* @0x23d188 and r3, r12, r3 */
/* @0x23d18c add r7, r3, r9 */
/* @0x23d190 lsl r5, r3, #1 */
/* @0x23d194 add r2, r5, r3 */
/* @0x23d198 add r2, r1, r2, lsl #2 */
/* @0x23d19c ldr r2, [r2, #0x8] */
/* @0x23d1a0 and r6, r12, r2 */
/* @0x23d1a4 cmp r2, #0 */
/* @0x23d1a8 rsb r6, r6, r7 */
/* @0x23d1ac and r6, r6, r12 */
/* @0x23d1b0 bne 0x23d170 <_Z24JS_DefaultGetOwnPropertyP12YYObjectBaseP6RValuePKc+0x80> */
/* @0x23d1b4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d1b8 cmn r3, #1 */
/* @0x23d1bc popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d1c0 add r3, r5, r3 */
/* @0x23d1c4 add r1, r1, r3, lsl #2 */
/* @0x23d1c8 cmn r1, #4 */
/* @0x23d1cc popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d1d0 ldr r3, [r1, #0x4] */
/* @0x23d1d4 ldr r0, [r3] */
/* @0x23d1d8 ldr r1, [r3, #0x4] */
/* @0x23d1dc ldr r2, [r3, #0x8] */
/* @0x23d1e0 ldr r3, [r3, #0xc] */
/* @0x23d1e4 str r0, [r8] */
/* @0x23d1e8 str r1, [r8, #0x4] */
/* @0x23d1ec str r2, [r8, #0x8] */
/* @0x23d1f0 str r3, [r8, #0xc] */
/* @0x23d1f4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x23d1f8 · Balloc_D2A · size=168 · insn=42 */
/* @0x23d1f8 cmp r0, #9 */
/* @0x23d1fc push {r3, r4, r5, lr} */
/* @0x23d200 mov r4, r0 */
/* @0x23d204 bgt 0x23d228 <Balloc_D2A+0x30> */
/* @0x23d208 ldr r3, [pc, #0x88] */
/* @0x23d20c add r3, pc, r3 */
/* @0x23d210 ldr r0, [r3, r0, lsl #2] */
/* @0x23d214 cmp r0, #0 */
/* @0x23d218 beq 0x23d258 <Balloc_D2A+0x60> */
/* @0x23d21c ldr r2, [r0] */
/* @0x23d220 str r2, [r3, r4, lsl #2] */
/* @0x23d224 b 0x23d248 <Balloc_D2A+0x50> */
/* @0x23d228 mov r5, #1 */
/* @0x23d22c lsl r5, r5, r0 */
/* @0x23d230 lsl r2, r5, #2 */
/* @0x23d234 add r2, r2, #27 */
/* @0x23d238 lsr r2, r2, #3 */
/* @0x23d23c lsl r0, r2, #3 */
/* @0x23d240 bl 0xb6544 <malloc@plt> */
/* @0x23d244 stmib r0, {r4, r5} */
/* @0x23d248 mov r3, #0 */
/* @0x23d24c str r3, [r0, #0x10] */
/* @0x23d250 str r3, [r0, #0xc] */
/* @0x23d254 pop {r3, r4, r5, pc} */
/* @0x23d258 ldr r1, [pc, #0x3c] */
/* @0x23d25c mov r5, #1 */
/* @0x23d260 lsl r5, r5, r4 */
/* @0x23d264 add r3, r3, #40 */
/* @0x23d268 add r1, pc, r1 */
/* @0x23d26c lsl r2, r5, #2 */
/* @0x23d270 ldr r0, [r1] */
/* @0x23d274 add r2, r2, #27 */
/* @0x23d278 rsb r3, r3, r0 */
/* @0x23d27c lsr r2, r2, #3 */
/* @0x23d280 add r3, r2, r3, asr #3 */
/* @0x23d284 cmp r3, #288 */
/* @0x23d288 addls r2, r0, r2, lsl #3 */
/* @0x23d28c strls r2, [r1] */
/* @0x23d290 bls 0x23d244 <Balloc_D2A+0x4c> */
/* @0x23d294 b 0x23d23c <Balloc_D2A+0x44> */
/* @0x23d298 .word 0x00518894 */
/* @0x23d29c andseq r10, r11, r0, lsr r2 */

/* ── FUNC 0x23d2a0 · Bfree_D2A · size=52 · insn=13 */
/* @0x23d2a0 subs r3, r0, #0 */
/* @0x23d2a4 bxeq lr */
/* @0x23d2a8 ldr r2, [r3, #0x4] */
/* @0x23d2ac cmp r2, #9 */
/* @0x23d2b0 bgt 0x23d2cc <Bfree_D2A+0x2c> */
/* @0x23d2b4 ldr r1, [pc, #0x14] */
/* @0x23d2b8 add r1, pc, r1 */
/* @0x23d2bc ldr r0, [r1, r2, lsl #2] */
/* @0x23d2c0 str r3, [r1, r2, lsl #2] */
/* @0x23d2c4 str r0, [r3] */
/* @0x23d2c8 bx lr */
/* @0x23d2cc b 0xb655c <free@plt> */
/* @0x23d2d0 subseq r8, r1, r8, ror #15 */

/* ── FUNC 0x23d2d4 · lo0bits_D2A · size=148 · insn=37 */
/* @0x23d2d4 ldr r3, [r0] */
/* @0x23d2d8 mov r2, r0 */
/* @0x23d2dc ands r0, r3, #7 */
/* @0x23d2e0 beq 0x23d308 <lo0bits_D2A+0x34> */
/* @0x23d2e4 tst r3, #1 */
/* @0x23d2e8 bne 0x23d360 <lo0bits_D2A+0x8c> */
/* @0x23d2ec tst r3, #2 */
/* @0x23d2f0 lsrne r3, r3, #1 */
/* @0x23d2f4 lsreq r3, r3, #2 */
/* @0x23d2f8 movne r0, #1 */
/* @0x23d2fc moveq r0, #2 */
/* @0x23d300 str r3, [r2] */
/* @0x23d304 bx lr */
/* @0x23d308 uxth r1, r3 */
/* @0x23d30c cmp r1, #0 */
/* @0x23d310 lsreq r3, r3, #16 */
/* @0x23d314 moveq r0, #16 */
/* @0x23d318 tst r3, #255 */
/* @0x23d31c lsreq r3, r3, #8 */
/* @0x23d320 addeq r0, r0, #8 */
/* @0x23d324 tst r3, #15 */
/* @0x23d328 lsreq r3, r3, #4 */
/* @0x23d32c addeq r0, r0, #4 */
/* @0x23d330 tst r3, #3 */
/* @0x23d334 lsreq r3, r3, #2 */
/* @0x23d338 addeq r0, r0, #2 */
/* @0x23d33c tst r3, #1 */
/* @0x23d340 bne 0x23d358 <lo0bits_D2A+0x84> */
/* @0x23d344 lsrs r3, r3, #1 */
/* @0x23d348 bne 0x23d354 <lo0bits_D2A+0x80> */
/* @0x23d34c mov r0, #32 */
/* @0x23d350 bx lr */
/* @0x23d354 add r0, r0, #1 */
/* @0x23d358 str r3, [r2] */
/* @0x23d35c bx lr */
/* @0x23d360 mov r0, #0 */
/* @0x23d364 bx lr */

/* ── FUNC 0x23d368 · multadd_D2A · size=180 · insn=45 */
/* @0x23d368 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23d36c mov r9, r0 */
/* @0x23d370 ldr r8, [r0, #0x10] */
/* @0x23d374 add r0, r0, #20 */
/* @0x23d378 mov r6, r2 */
/* @0x23d37c asr r7, r2, #31 */
/* @0x23d380 asr r3, r1, #31 */
/* @0x23d384 mov r2, r1 */
/* @0x23d388 mov r1, #0 */
/* @0x23d38c ldr r12, [r0] */
/* @0x23d390 add r1, r1, #1 */
/* @0x23d394 umull r4, r5, r12, r2 */
/* @0x23d398 adds r4, r4, r6 */
/* @0x23d39c str r4, [r0], #4 */
/* @0x23d3a0 mla r5, r12, r3, r5 */
/* @0x23d3a4 adc r5, r5, r7 */
/* @0x23d3a8 cmp r8, r1 */
/* @0x23d3ac mov r7, #0 */
/* @0x23d3b0 mov r6, r5 */
/* @0x23d3b4 bgt 0x23d38c <multadd_D2A+0x24> */
/* @0x23d3b8 orrs r3, r6, r7 */
/* @0x23d3bc beq 0x23d3dc <multadd_D2A+0x74> */
/* @0x23d3c0 ldr r3, [r9, #0x8] */
/* @0x23d3c4 cmp r8, r3 */
/* @0x23d3c8 bge 0x23d3e4 <multadd_D2A+0x7c> */
/* @0x23d3cc add r3, r9, r8, lsl #2 */
/* @0x23d3d0 add r8, r8, #1 */
/* @0x23d3d4 str r6, [r3, #0x14] */
/* @0x23d3d8 str r8, [r9, #0x10] */
/* @0x23d3dc mov r0, r9 */
/* @0x23d3e0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d3e4 ldr r0, [r9, #0x4] */
/* @0x23d3e8 add r0, r0, #1 */
/* @0x23d3ec bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d3f0 ldr r2, [r9, #0x10] */
/* @0x23d3f4 add r1, r9, #12 */
/* @0x23d3f8 lsl r2, r2, #2 */
/* @0x23d3fc add r2, r2, #8 */
/* @0x23d400 mov r4, r0 */
/* @0x23d404 add r0, r0, #12 */
/* @0x23d408 bl 0xb65bc <memcpy@plt> */
/* @0x23d40c mov r0, r9 */
/* @0x23d410 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23d414 mov r9, r4 */
/* @0x23d418 b 0x23d3cc <multadd_D2A+0x64> */

/* ── FUNC 0x23d41c · hi0bits_D2A · size=92 · insn=23 */
/* @0x23d41c lsrs r3, r0, #16 */
/* @0x23d420 lsleq r0, r0, #16 */
/* @0x23d424 moveq r3, #16 */
/* @0x23d428 movne r3, #0 */
/* @0x23d42c tst r0, #-16777216 */
/* @0x23d430 lsleq r0, r0, #8 */
/* @0x23d434 addeq r3, r3, #8 */
/* @0x23d438 tst r0, #-268435456 */
/* @0x23d43c lsleq r0, r0, #4 */
/* @0x23d440 addeq r3, r3, #4 */
/* @0x23d444 tst r0, #-1073741824 */
/* @0x23d448 lsleq r0, r0, #2 */
/* @0x23d44c addeq r3, r3, #2 */
/* @0x23d450 cmp r0, #0 */
/* @0x23d454 blt 0x23d470 <hi0bits_D2A+0x54> */
/* @0x23d458 tst r0, #1073741824 */
/* @0x23d45c bne 0x23d468 <hi0bits_D2A+0x4c> */
/* @0x23d460 mov r0, #32 */
/* @0x23d464 bx lr */
/* @0x23d468 add r0, r3, #1 */
/* @0x23d46c bx lr */
/* @0x23d470 mov r0, r3 */
/* @0x23d474 bx lr */

/* ── FUNC 0x23d478 · i2b_D2A · size=32 · insn=8 */
/* @0x23d478 push {r4, lr} */
/* @0x23d47c mov r4, r0 */
/* @0x23d480 mov r0, #1 */
/* @0x23d484 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d488 mov r2, #1 */
/* @0x23d48c str r4, [r0, #0x14] */
/* @0x23d490 str r2, [r0, #0x10] */
/* @0x23d494 pop {r4, pc} */

/* ── FUNC 0x23d498 · mult_D2A · size=340 · insn=85 */
/* @0x23d498 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23d49c mov r4, r0 */
/* @0x23d4a0 ldr r7, [r0, #0x10] */
/* @0x23d4a4 sub sp, sp, #20 */
/* @0x23d4a8 ldr r5, [r1, #0x10] */
/* @0x23d4ac mov r8, r1 */
/* @0x23d4b0 cmp r7, r5 */
/* @0x23d4b4 bge 0x23d4cc <mult_D2A+0x34> */
/* @0x23d4b8 mov r2, r7 */
/* @0x23d4bc mov r4, r1 */
/* @0x23d4c0 mov r7, r5 */
/* @0x23d4c4 mov r8, r0 */
/* @0x23d4c8 mov r5, r2 */
/* @0x23d4cc ldr r3, [r4, #0x8] */
/* @0x23d4d0 add r2, r7, r5 */
/* @0x23d4d4 ldr r0, [r4, #0x4] */
/* @0x23d4d8 cmp r2, r3 */
/* @0x23d4dc str r2, [sp, #0x4] */
/* @0x23d4e0 addgt r0, r0, #1 */
/* @0x23d4e4 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d4e8 ldr r3, [sp, #0x4] */
/* @0x23d4ec add r9, r0, #20 */
/* @0x23d4f0 str r0, [sp] */
/* @0x23d4f4 add r10, r9, r3, lsl #2 */
/* @0x23d4f8 cmp r9, r10 */
/* @0x23d4fc movlo r3, r9 */
/* @0x23d500 movlo r2, #0 */
/* @0x23d504 bhs 0x23d514 <mult_D2A+0x7c> */
/* @0x23d508 str r2, [r3], #4 */
/* @0x23d50c cmp r10, r3 */
/* @0x23d510 bhi 0x23d508 <mult_D2A+0x70> */
/* @0x23d514 add r8, r8, #20 */
/* @0x23d518 add r4, r4, #20 */
/* @0x23d51c add r5, r8, r5, lsl #2 */
/* @0x23d520 str r4, [sp, #0x8] */
/* @0x23d524 cmp r8, r5 */
/* @0x23d528 add r7, r4, r7, lsl #2 */
/* @0x23d52c strlo r10, [sp, #0xc] */
/* @0x23d530 movlo r10, r5 */
/* @0x23d534 bhs 0x23d5a0 <mult_D2A+0x108> */
/* @0x23d538 ldr r6, [r8], #4 */
/* @0x23d53c cmp r6, #0 */
/* @0x23d540 beq 0x23d590 <mult_D2A+0xf8> */
/* @0x23d544 mov r0, #0 */
/* @0x23d548 mov r1, #0 */
/* @0x23d54c mov r4, r9 */
/* @0x23d550 ldr r5, [sp, #0x8] */
/* @0x23d554 b 0x23d55c <mult_D2A+0xc4> */
/* @0x23d558 mov r4, r12 */
/* @0x23d55c ldr r11, [r5], #4 */
/* @0x23d560 mov r3, #0 */
/* @0x23d564 ldr r2, [r4] */
/* @0x23d568 mov r12, r4 */
/* @0x23d56c umlal r2, r3, r11, r6 */
/* @0x23d570 adds r2, r2, r0 */
/* @0x23d574 str r2, [r12], #4 */
/* @0x23d578 adc r3, r3, r1 */
/* @0x23d57c cmp r7, r5 */
/* @0x23d580 mov r1, #0 */
/* @0x23d584 mov r0, r3 */
/* @0x23d588 bhi 0x23d558 <mult_D2A+0xc0> */
/* @0x23d58c str r3, [r4, #0x4] */
/* @0x23d590 cmp r10, r8 */
/* @0x23d594 add r9, r9, #4 */
/* @0x23d598 bhi 0x23d538 <mult_D2A+0xa0> */
/* @0x23d59c ldr r10, [sp, #0xc] */
/* @0x23d5a0 ldr r2, [sp, #0x4] */
/* @0x23d5a4 cmp r2, #0 */
/* @0x23d5a8 ble 0x23d5d8 <mult_D2A+0x140> */
/* @0x23d5ac ldr r3, [r10, #-0x4] */
/* @0x23d5b0 cmp r3, #0 */
/* @0x23d5b4 bne 0x23d5d8 <mult_D2A+0x140> */
/* @0x23d5b8 ldr r3, [sp, #0x4] */
/* @0x23d5bc sub r10, r10, #4 */
/* @0x23d5c0 subs r3, r3, #1 */
/* @0x23d5c4 beq 0x23d5d4 <mult_D2A+0x13c> */
/* @0x23d5c8 ldr r2, [r10, #-0x4]! */
/* @0x23d5cc cmp r2, #0 */
/* @0x23d5d0 beq 0x23d5c0 <mult_D2A+0x128> */
/* @0x23d5d4 str r3, [sp, #0x4] */
/* @0x23d5d8 ldm sp, {r2, r3} */
/* @0x23d5dc mov r0, r2 */
/* @0x23d5e0 str r3, [r2, #0x10] */
/* @0x23d5e4 add sp, sp, #20 */
/* @0x23d5e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x23d5ec · pow5mult_D2A · size=224 · insn=56 */
/* @0x23d5ec push {r3, r4, r5, r6, r7, lr} */
/* @0x23d5f0 ands r3, r1, #3 */
/* @0x23d5f4 mov r4, r1 */
/* @0x23d5f8 mov r6, r0 */
/* @0x23d5fc bne 0x23d688 <pow5mult_D2A+0x9c> */
/* @0x23d600 asrs r4, r4, #2 */
/* @0x23d604 beq 0x23d668 <pow5mult_D2A+0x7c> */
/* @0x23d608 ldr r7, [pc, #0xb4] */
/* @0x23d60c add r7, pc, r7 */
/* @0x23d610 ldr r5, [r7, #0x928] */
/* @0x23d614 cmp r5, #0 */
/* @0x23d618 beq 0x23d6a8 <pow5mult_D2A+0xbc> */
/* @0x23d61c mov r7, #0 */
/* @0x23d620 b 0x23d63c <pow5mult_D2A+0x50> */
/* @0x23d624 asrs r4, r4, #1 */
/* @0x23d628 beq 0x23d668 <pow5mult_D2A+0x7c> */
/* @0x23d62c ldr r0, [r5] */
/* @0x23d630 cmp r0, #0 */
/* @0x23d634 beq 0x23d670 <pow5mult_D2A+0x84> */
/* @0x23d638 mov r5, r0 */
/* @0x23d63c tst r4, #1 */
/* @0x23d640 beq 0x23d624 <pow5mult_D2A+0x38> */
/* @0x23d644 mov r0, r6 */
/* @0x23d648 mov r1, r5 */
/* @0x23d64c bl 0x23d498 <mult_D2A> */
/* @0x23d650 mov r3, r0 */
/* @0x23d654 mov r0, r6 */
/* @0x23d658 mov r6, r3 */
/* @0x23d65c bl 0x23d2a0 <Bfree_D2A> */
/* @0x23d660 asrs r4, r4, #1 */
/* @0x23d664 bne 0x23d62c <pow5mult_D2A+0x40> */
/* @0x23d668 mov r0, r6 */
/* @0x23d66c pop {r3, r4, r5, r6, r7, pc} */
/* @0x23d670 mov r0, r5 */
/* @0x23d674 mov r1, r5 */
/* @0x23d678 bl 0x23d498 <mult_D2A> */
/* @0x23d67c str r0, [r5] */
/* @0x23d680 str r7, [r0] */
/* @0x23d684 b 0x23d638 <pow5mult_D2A+0x4c> */
/* @0x23d688 ldr r1, [pc, #0x38] */
/* @0x23d68c sub r3, r3, #1 */
/* @0x23d690 mov r2, #0 */
/* @0x23d694 add r1, pc, r1 */
/* @0x23d698 ldr r1, [r1, r3, lsl #2] */
/* @0x23d69c bl 0x23d368 <multadd_D2A> */
/* @0x23d6a0 mov r6, r0 */
/* @0x23d6a4 b 0x23d600 <pow5mult_D2A+0x14> */
/* @0x23d6a8 movw r0, #0x271 */
/* @0x23d6ac bl 0x23d478 <i2b_D2A> */
/* @0x23d6b0 mov r3, #0 */
/* @0x23d6b4 mov r5, r0 */
/* @0x23d6b8 str r0, [r7, #0x928] */
/* @0x23d6bc str r3, [r0] */
/* @0x23d6c0 b 0x23d61c <pow5mult_D2A+0x30> */
/* @0x23d6c4 .word 0x00518494 */
/* @0x23d6c8 andseq r11, r2, r12, asr #17 */

/* ── FUNC 0x23d6cc · lshift_D2A · size=252 · insn=63 */
/* @0x23d6cc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x23d6d0 asr r5, r1, #5 */
/* @0x23d6d4 ldr r7, [r0, #0x10] */
/* @0x23d6d8 mov r6, r0 */
/* @0x23d6dc ldr r3, [r0, #0x8] */
/* @0x23d6e0 mov r9, r1 */
/* @0x23d6e4 add r7, r5, r7 */
/* @0x23d6e8 ldr r0, [r0, #0x4] */
/* @0x23d6ec add r4, r7, #1 */
/* @0x23d6f0 cmp r4, r3 */
/* @0x23d6f4 ble 0x23d708 <lshift_D2A+0x3c> */
/* @0x23d6f8 lsl r3, r3, #1 */
/* @0x23d6fc add r0, r0, #1 */
/* @0x23d700 cmp r4, r3 */
/* @0x23d704 bgt 0x23d6f8 <lshift_D2A+0x2c> */
/* @0x23d708 bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d70c cmp r5, #0 */
/* @0x23d710 mov r8, r0 */
/* @0x23d714 add r2, r0, #20 */
/* @0x23d718 ble 0x23d73c <lshift_D2A+0x70> */
/* @0x23d71c mov r3, #0 */
/* @0x23d720 mov r12, r2 */
/* @0x23d724 mov r0, r3 */
/* @0x23d728 add r3, r3, #1 */
/* @0x23d72c str r0, [r12], #4 */
/* @0x23d730 cmp r3, r5 */
/* @0x23d734 bne 0x23d728 <lshift_D2A+0x5c> */
/* @0x23d738 add r2, r2, r3, lsl #2 */
/* @0x23d73c ldr r0, [r6, #0x10] */
/* @0x23d740 ands r1, r9, #31 */
/* @0x23d744 add r3, r6, #20 */
/* @0x23d748 add r0, r3, r0, lsl #2 */
/* @0x23d74c beq 0x23d7a4 <lshift_D2A+0xd8> */
/* @0x23d750 rsb r5, r1, #32 */
/* @0x23d754 mov lr, #0 */
/* @0x23d758 b 0x23d760 <lshift_D2A+0x94> */
/* @0x23d75c mov r2, r12 */
/* @0x23d760 ldr r9, [r3] */
/* @0x23d764 mov r12, r2 */
/* @0x23d768 orr lr, lr, r9, lsl r1 */
/* @0x23d76c str lr, [r12], #4 */
/* @0x23d770 ldr lr, [r3], #4 */
/* @0x23d774 cmp r3, r0 */
/* @0x23d778 lsr lr, lr, r5 */
/* @0x23d77c blo 0x23d75c <lshift_D2A+0x90> */
/* @0x23d780 cmp lr, #0 */
/* @0x23d784 str lr, [r2, #0x4] */
/* @0x23d788 addne r4, r7, #2 */
/* @0x23d78c mov r0, r6 */
/* @0x23d790 sub r4, r4, #1 */
/* @0x23d794 str r4, [r8, #0x10] */
/* @0x23d798 bl 0x23d2a0 <Bfree_D2A> */
/* @0x23d79c mov r0, r8 */
/* @0x23d7a0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x23d7a4 ldr r1, [r3], #4 */
/* @0x23d7a8 cmp r0, r3 */
/* @0x23d7ac str r1, [r2], #4 */
/* @0x23d7b0 bls 0x23d78c <lshift_D2A+0xc0> */
/* @0x23d7b4 ldr r1, [r3], #4 */
/* @0x23d7b8 cmp r0, r3 */
/* @0x23d7bc str r1, [r2], #4 */
/* @0x23d7c0 bhi 0x23d7a4 <lshift_D2A+0xd8> */
/* @0x23d7c4 b 0x23d78c <lshift_D2A+0xc0> */

/* ── FUNC 0x23d7c8 · cmp_D2A · size=96 · insn=24 */
/* @0x23d7c8 ldr r2, [r0, #0x10] */
/* @0x23d7cc ldr r3, [r1, #0x10] */
/* @0x23d7d0 subs r2, r2, r3 */
/* @0x23d7d4 bne 0x23d818 <cmp_D2A+0x50> */
/* @0x23d7d8 lsl r2, r3, #2 */
/* @0x23d7dc add r0, r0, #20 */
/* @0x23d7e0 add r1, r1, #20 */
/* @0x23d7e4 add r3, r0, r2 */
/* @0x23d7e8 add r1, r1, r2 */
/* @0x23d7ec b 0x23d7f8 <cmp_D2A+0x30> */
/* @0x23d7f0 cmp r0, r3 */
/* @0x23d7f4 bhs 0x23d820 <cmp_D2A+0x58> */
/* @0x23d7f8 ldr r2, [r3, #-0x4]! */
/* @0x23d7fc ldr r12, [r1, #-0x4]! */
/* @0x23d800 cmp r2, r12 */
/* @0x23d804 beq 0x23d7f0 <cmp_D2A+0x28> */
/* @0x23d808 cmp r12, r2 */
/* @0x23d80c movls r0, #1 */
/* @0x23d810 mvnhi r0, #0 */
/* @0x23d814 bx lr */
/* @0x23d818 mov r0, r2 */
/* @0x23d81c bx lr */
/* @0x23d820 mov r0, #0 */
/* @0x23d824 bx lr */

/* ── FUNC 0x23d828 · diff_D2A · size=320 · insn=80 */
/* @0x23d828 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x23d82c sub sp, sp, #28 */
/* @0x23d830 mov r5, r0 */
/* @0x23d834 mov r4, r1 */
/* @0x23d838 bl 0x23d7c8 <cmp_D2A> */
/* @0x23d83c subs r8, r0, #0 */
/* @0x23d840 beq 0x23d94c <diff_D2A+0x124> */
/* @0x23d844 movlt r3, r5 */
/* @0x23d848 movlt r5, r4 */
/* @0x23d84c ldr r0, [r5, #0x4] */
/* @0x23d850 movlt r4, r3 */
/* @0x23d854 movge r11, #0 */
/* @0x23d858 movlt r11, #1 */
/* @0x23d85c bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d860 ldr r3, [r4, #0x10] */
/* @0x23d864 ldr r8, [r5, #0x10] */
/* @0x23d868 add r1, r4, #20 */
/* @0x23d86c strd r6, r7, [sp, #16] */
/* @0x23d870 mov r4, #0 */
/* @0x23d874 add r3, r1, r3, lsl #2 */
/* @0x23d878 mov r6, r3 */
/* @0x23d87c str r0, [sp, #0xc] */
/* @0x23d880 add r0, r5, #20 */
/* @0x23d884 ldr r2, [sp, #0xc] */
/* @0x23d888 add r9, r0, r8, lsl #2 */
/* @0x23d88c mov r5, #0 */
/* @0x23d890 add r12, r2, #20 */
/* @0x23d894 str r11, [r2, #0xc] */
/* @0x23d898 ldr r3, [r1], #4 */
/* @0x23d89c mov r11, #0 */
/* @0x23d8a0 ldr r2, [r0], #4 */
/* @0x23d8a4 subs r2, r2, r3 */
/* @0x23d8a8 sbc r3, r2, r2 */
/* @0x23d8ac subs r2, r2, r4 */
/* @0x23d8b0 sbc r3, r3, r5 */
/* @0x23d8b4 cmp r6, r1 */
/* @0x23d8b8 mov r4, #1 */
/* @0x23d8bc mov r5, #0 */
/* @0x23d8c0 str r2, [r12], #4 */
/* @0x23d8c4 and r4, r4, r3 */
/* @0x23d8c8 and r5, r5, r11 */
/* @0x23d8cc bhi 0x23d898 <diff_D2A+0x70> */
/* @0x23d8d0 cmp r9, r0 */
/* @0x23d8d4 mov r10, r12 */
/* @0x23d8d8 mov r1, r0 */
/* @0x23d8dc bls 0x23d920 <diff_D2A+0xf8> */
/* @0x23d8e0 ldr r11, [r0], #4 */
/* @0x23d8e4 mov r7, #0 */
/* @0x23d8e8 rsbs r2, r4, r11 */
/* @0x23d8ec rsc r3, r5, #0 */
/* @0x23d8f0 cmp r9, r0 */
/* @0x23d8f4 mov r4, #1 */
/* @0x23d8f8 mov r5, #0 */
/* @0x23d8fc str r2, [r12], #4 */
/* @0x23d900 and r4, r4, r3 */
/* @0x23d904 and r5, r5, r7 */
/* @0x23d908 bhi 0x23d8e0 <diff_D2A+0xb8> */
/* @0x23d90c mvn r12, r1 */
/* @0x23d910 add r12, r12, r9 */
/* @0x23d914 bic r12, r12, #3 */
/* @0x23d918 add r12, r12, #4 */
/* @0x23d91c add r12, r10, r12 */
/* @0x23d920 cmp r2, #0 */
/* @0x23d924 sub r12, r12, #4 */
/* @0x23d928 bne 0x23d93c <diff_D2A+0x114> */
/* @0x23d92c ldr r3, [r12, #-0x4]! */
/* @0x23d930 sub r8, r8, #1 */
/* @0x23d934 cmp r3, #0 */
/* @0x23d938 beq 0x23d92c <diff_D2A+0x104> */
/* @0x23d93c ldr r0, [sp, #0xc] */
/* @0x23d940 str r8, [r0, #0x10] */
/* @0x23d944 add sp, sp, #28 */
/* @0x23d948 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x23d94c bl 0x23d1f8 <Balloc_D2A> */
/* @0x23d950 mov r2, #1 */
/* @0x23d954 mov r3, r0 */
/* @0x23d958 str r8, [r0, #0x14] */
/* @0x23d95c str r2, [r3, #0x10] */
/* @0x23d960 add sp, sp, #28 */
/* @0x23d964 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x23d968 · b2d_D2A · size=188 · insn=47 */
/* @0x23d968 push {r4, r5, r6, r7, r8, lr} */
/* @0x23d96c add r6, r0, #20 */
/* @0x23d970 ldr r4, [r0, #0x10] */
/* @0x23d974 mov r8, r1 */
/* @0x23d978 add r4, r6, r4, lsl #2 */
/* @0x23d97c sub r7, r4, #4 */
/* @0x23d980 ldr r5, [r4, #-0x4] */
/* @0x23d984 mov r0, r5 */
/* @0x23d988 bl 0x23d41c <hi0bits_D2A> */
/* @0x23d98c cmp r0, #10 */
/* @0x23d990 rsb r3, r0, #32 */
/* @0x23d994 str r3, [r8] */
/* @0x23d998 bgt 0x23d9d0 <b2d_D2A+0x68> */
/* @0x23d99c rsb r1, r0, #11 */
/* @0x23d9a0 cmp r6, r7 */
/* @0x23d9a4 lsr r12, r5, r1 */
/* @0x23d9a8 add r0, r0, #21 */
/* @0x23d9ac orr r12, r12, #1069547520 */
/* @0x23d9b0 movhs r1, #0 */
/* @0x23d9b4 orr r3, r12, #3145728 */
/* @0x23d9b8 ldrlo r12, [r4, #-0x8] */
/* @0x23d9bc lsrlo r1, r12, r1 */
/* @0x23d9c0 orr r2, r1, r5, lsl r0 */
/* @0x23d9c4 mov r0, r2 */
/* @0x23d9c8 mov r1, r3 */
/* @0x23d9cc pop {r4, r5, r6, r7, r8, pc} */
/* @0x23d9d0 cmp r6, r7 */
/* @0x23d9d4 sublo r7, r4, #8 */
/* @0x23d9d8 ldrlo r1, [r4, #-0x8] */
/* @0x23d9dc movhs r1, #0 */
/* @0x23d9e0 subs r12, r0, #11 */
/* @0x23d9e4 beq 0x23da14 <b2d_D2A+0xac> */
/* @0x23d9e8 cmp r7, r6 */
/* @0x23d9ec lsl r5, r5, r12 */
/* @0x23d9f0 orr r5, r5, #1069547520 */
/* @0x23d9f4 rsb r0, r0, #43 */
/* @0x23d9f8 ldrhi r4, [r7, #-0x4] */
/* @0x23d9fc orr r5, r5, #3145728 */
/* @0x23da00 orr r3, r5, r1, lsr r0 */
/* @0x23da04 movls r0, #0 */
/* @0x23da08 lsrhi r0, r4, r0 */
/* @0x23da0c orr r2, r0, r1, lsl r12 */
/* @0x23da10 b 0x23d9c4 <b2d_D2A+0x5c> */
/* @0x23da14 orr r5, r5, #1069547520 */
/* @0x23da18 mov r2, r1 */
/* @0x23da1c orr r3, r5, #3145728 */
/* @0x23da20 b 0x23d9c4 <b2d_D2A+0x5c> */
