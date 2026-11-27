/* libyoyo.so 覆盖卡组 0028
 * 函数 0xfc8e8..0xfde70，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0xfc8e8 · F_DsListShuffle(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfc8e8 push {r3, lr} */
/* @0xfc8ec mov r1, #0 */
/* @0xfc8f0 ldr r0, [sp, #0x8] */
/* @0xfc8f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc8f8 cmp r0, #0 */
/* @0xfc8fc blt 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc900 ldr r3, [pc, #0x40] */
/* @0xfc904 ldr r3, [pc, r3] */
/* @0xfc908 ldr r3, [r3] */
/* @0xfc90c cmp r0, r3 */
/* @0xfc910 bge 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc914 ldr r3, [pc, #0x30] */
/* @0xfc918 ldr r3, [pc, r3] */
/* @0xfc91c ldr r3, [r3, #0x4] */
/* @0xfc920 ldr r0, [r3, r0, lsl #2] */
/* @0xfc924 cmp r0, #0 */
/* @0xfc928 beq 0xfc934 <_Z15F_DsListShuffleR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfc92c pop {r3, lr} */
/* @0xfc930 b 0x203360 <_ZN8CDS_List7ShuffleEv> */
/* @0xfc934 ldr r0, [pc, #0x14] */
/* @0xfc938 mov r1, #0 */
/* @0xfc93c pop {r3, lr} */
/* @0xfc940 add r0, pc, r0 */
/* @0xfc944 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc948 eoreq r1, pc, r8, ror r3 */
/* @0xfc94c eoreq r1, pc, r8, ror #6 */
/* @0xfc950 .word 0x0023b2bc */

/* ── FUNC 0xfc954 · F_DsListWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfc954 push {r4, lr} */
/* @0xfc958 sub sp, sp, #8 */
/* @0xfc95c mov r4, r0 */
/* @0xfc960 mov r1, #0 */
/* @0xfc964 ldr r0, [sp, #0x10] */
/* @0xfc968 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfc96c subs r2, r0, #0 */
/* @0xfc970 blt 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc974 ldr r3, [pc, #0x6c] */
/* @0xfc978 ldr r3, [pc, r3] */
/* @0xfc97c ldr r3, [r3] */
/* @0xfc980 cmp r2, r3 */
/* @0xfc984 bge 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc988 ldr r3, [pc, #0x5c] */
/* @0xfc98c ldr r3, [pc, r3] */
/* @0xfc990 ldr r3, [r3, #0x4] */
/* @0xfc994 ldr r1, [r3, r2, lsl #2] */
/* @0xfc998 cmp r1, #0 */
/* @0xfc99c beq 0xfc9d0 <_Z13F_DsListWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfc9a0 add r1, sp, #8 */
/* @0xfc9a4 mov r0, #0 */
/* @0xfc9a8 str r0, [r1, #-0x4]! */
/* @0xfc9ac ldr r0, [r3, r2, lsl #2] */
/* @0xfc9b0 bl 0x20301c <_ZN8CDS_List13WriteToStringERPKc> */
/* @0xfc9b4 mov r0, r4 */
/* @0xfc9b8 ldr r1, [sp, #0x4] */
/* @0xfc9bc bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xfc9c0 ldr r0, [sp, #0x4] */
/* @0xfc9c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xfc9c8 add sp, sp, #8 */
/* @0xfc9cc pop {r4, pc} */
/* @0xfc9d0 ldr r0, [pc, #0x18] */
/* @0xfc9d4 mov r1, #0 */
/* @0xfc9d8 add r0, pc, r0 */
/* @0xfc9dc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfc9e0 add sp, sp, #8 */
/* @0xfc9e4 pop {r4, pc} */
/* @0xfc9e8 eoreq r1, pc, r4, lsl #6 */
/* @0xfc9ec .word 0x002f12f4 */
/* @0xfc9f0 eoreq r11, r3, r4, lsr #4 */

/* ── FUNC 0xfc9f4 · F_DsListRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0xfc9f4 push {r3, r4, r5, r6, r7, lr} */
/* @0xfc9f8 mov r1, #0 */
/* @0xfc9fc ldr r5, [sp, #0x18] */
/* @0xfca00 mov r6, r3 */
/* @0xfca04 mov r0, r5 */
/* @0xfca08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfca0c mov r1, #1 */
/* @0xfca10 mov r4, r0 */
/* @0xfca14 mov r0, r5 */
/* @0xfca18 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfca1c cmp r6, #3 */
/* @0xfca20 movne r2, #0 */
/* @0xfca24 mov r7, r0 */
/* @0xfca28 beq 0xfca88 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x94> */
/* @0xfca2c cmp r4, #0 */
/* @0xfca30 blt 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfca34 ldr r3, [pc, #0x68] */
/* @0xfca38 ldr r3, [pc, r3] */
/* @0xfca3c ldr r3, [r3] */
/* @0xfca40 cmp r4, r3 */
/* @0xfca44 bge 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfca48 ldr r3, [pc, #0x58] */
/* @0xfca4c ldr r3, [pc, r3] */
/* @0xfca50 ldr r3, [r3, #0x4] */
/* @0xfca54 ldr r0, [r3, r4, lsl #2] */
/* @0xfca58 cmp r0, #0 */
/* @0xfca5c beq 0xfca74 <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfca60 cmp r7, #0 */
/* @0xfca64 popeq {r3, r4, r5, r6, r7, pc} */
/* @0xfca68 mov r1, r7 */
/* @0xfca6c pop {r3, r4, r5, r6, r7, lr} */
/* @0xfca70 b 0x20e968 <_ZN8CDS_List14ReadFromStringEPKcb> */
/* @0xfca74 ldr r0, [pc, #0x30] */
/* @0xfca78 mov r1, #0 */
/* @0xfca7c pop {r3, r4, r5, r6, r7, lr} */
/* @0xfca80 add r0, pc, r0 */
/* @0xfca84 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfca88 mov r0, r5 */
/* @0xfca8c mov r1, #2 */
/* @0xfca90 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfca94 cmp r0, #0 */
/* @0xfca98 movle r2, #0 */
/* @0xfca9c movgt r2, #1 */
/* @0xfcaa0 b 0xfca2c <_Z12F_DsListReadR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0xfcaa4 eoreq r1, pc, r4, asr #4 */
/* @0xfcaa8 eoreq r1, pc, r4, lsr r2 */
/* @0xfcaac eoreq r11, r3, r12, ror r1 */

/* ── FUNC 0xfcab0 · F_DsPriorityClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=108 · insn=27 */
/* @0xfcab0 push {r3, lr} */
/* @0xfcab4 mov r1, #0 */
/* @0xfcab8 ldr r0, [sp, #0x8] */
/* @0xfcabc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcac0 cmp r0, #0 */
/* @0xfcac4 blt 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfcac8 ldr r3, [pc, #0x40] */
/* @0xfcacc ldr r3, [pc, r3] */
/* @0xfcad0 ldr r3, [r3] */
/* @0xfcad4 cmp r0, r3 */
/* @0xfcad8 bge 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfcadc ldr r3, [pc, #0x30] */
/* @0xfcae0 ldr r3, [pc, r3] */
/* @0xfcae4 ldr r3, [r3, #0x4] */
/* @0xfcae8 ldr r0, [r3, r0, lsl #2] */
/* @0xfcaec cmp r0, #0 */
/* @0xfcaf0 beq 0xfcafc <_Z17F_DsPriorityClearR6RValueP9CInstanceS2_iPS_+0x4c> */
/* @0xfcaf4 pop {r3, lr} */
/* @0xfcaf8 b 0x209768 <_ZN12CDS_Priority5ClearEv> */
/* @0xfcafc ldr r0, [pc, #0x14] */
/* @0xfcb00 mov r1, #0 */
/* @0xfcb04 pop {r3, lr} */
/* @0xfcb08 add r0, pc, r0 */
/* @0xfcb0c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcb10 eoreq r1, pc, r8, lsr #7 */
/* @0xfcb14 mlaeq pc, r8, r3, r1 */
/* @0xfcb18 .word 0x0023b0f4 */

/* ── FUNC 0xfcb1c · F_DsPriorityCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=164 · insn=41 */
/* @0xfcb1c push {r3, r4, r5, r6, r7, lr} */
/* @0xfcb20 mov r1, #0 */
/* @0xfcb24 ldr r7, [sp, #0x18] */
/* @0xfcb28 mov r0, r7 */
/* @0xfcb2c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcb30 subs r5, r0, #0 */
/* @0xfcb34 blt 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb38 ldr r4, [pc, #0x74] */
/* @0xfcb3c ldr r4, [pc, r4] */
/* @0xfcb40 ldr r3, [r4] */
/* @0xfcb44 cmp r5, r3 */
/* @0xfcb48 bge 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb4c ldr r6, [pc, #0x64] */
/* @0xfcb50 ldr r6, [pc, r6] */
/* @0xfcb54 ldr r3, [r6, #0x4] */
/* @0xfcb58 ldr r3, [r3, r5, lsl #2] */
/* @0xfcb5c cmp r3, #0 */
/* @0xfcb60 beq 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb64 mov r0, r7 */
/* @0xfcb68 mov r1, #1 */
/* @0xfcb6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcb70 cmp r0, #0 */
/* @0xfcb74 blt 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb78 ldr r3, [r4] */
/* @0xfcb7c cmp r0, r3 */
/* @0xfcb80 bge 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb84 ldr r3, [r6, #0x4] */
/* @0xfcb88 ldr r1, [r3, r0, lsl #2] */
/* @0xfcb8c cmp r1, #0 */
/* @0xfcb90 beq 0xfcba0 <_Z16F_DsPriorityCopyR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfcb94 ldr r0, [r3, r5, lsl #2] */
/* @0xfcb98 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfcb9c b 0x209a78 <_ZN12CDS_Priority6AssignEPS_> */
/* @0xfcba0 ldr r0, [pc, #0x14] */
/* @0xfcba4 mov r1, #0 */
/* @0xfcba8 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfcbac add r0, pc, r0 */
/* @0xfcbb0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcbb4 eoreq r1, pc, r8, lsr r3 */
/* @0xfcbb8 eoreq r1, pc, r8, lsr #6 */
/* @0xfcbbc eoreq r11, r3, r0, asr r0 */

/* ── FUNC 0xfcbc0 · F_DsPrioritySize(RValue&, CInstance*, CInstance*, int, RValue*) · size=144 · insn=36 */
/* @0xfcbc0 push {r4, lr} */
/* @0xfcbc4 mov r1, #0 */
/* @0xfcbc8 mov r4, r0 */
/* @0xfcbcc ldr r0, [sp, #0x8] */
/* @0xfcbd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcbd4 cmp r0, #0 */
/* @0xfcbd8 blt 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfcbdc ldr r3, [pc, #0x60] */
/* @0xfcbe0 ldr r3, [pc, r3] */
/* @0xfcbe4 ldr r3, [r3] */
/* @0xfcbe8 cmp r0, r3 */
/* @0xfcbec bge 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfcbf0 ldr r3, [pc, #0x50] */
/* @0xfcbf4 ldr r3, [pc, r3] */
/* @0xfcbf8 ldr r3, [r3, #0x4] */
/* @0xfcbfc ldr r0, [r3, r0, lsl #2] */
/* @0xfcc00 cmp r0, #0 */
/* @0xfcc04 beq 0xfcc30 <_Z16F_DsPrioritySizeR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0xfcc08 mov r3, #0 */
/* @0xfcc0c str r3, [r4, #0xc] */
/* @0xfcc10 bl 0x2052cc <_ZN12CDS_Priority4SizeEv> */
/* @0xfcc14 vmov s15, r0 */
/* @0xfcc18 vcvt.f64.s32 d7, s15 */
/* @0xfcc1c vmov r0, r1, d7 */
/* @0xfcc20 vmov r2, s14 */
/* @0xfcc24 mov r3, r1 */
/* @0xfcc28 stm r4, {r2, r3} */
/* @0xfcc2c pop {r4, pc} */
/* @0xfcc30 ldr r0, [pc, #0x14] */
/* @0xfcc34 mov r1, #0 */
/* @0xfcc38 pop {r4, lr} */
/* @0xfcc3c add r0, pc, r0 */
/* @0xfcc40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcc44 mlaeq pc, r4, r2, r1 */
/* @0xfcc48 eoreq r1, pc, r4, lsl #5 */
/* @0xfcc4c eoreq r10, r3, r0, asr #31 */

/* ── FUNC 0xfcc50 · F_DsPriorityEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=148 · insn=37 */
/* @0xfcc50 push {r3, r4, r5, lr} */
/* @0xfcc54 mov r1, #0 */
/* @0xfcc58 mov r4, r0 */
/* @0xfcc5c ldr r0, [sp, #0x10] */
/* @0xfcc60 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcc64 cmp r0, #0 */
/* @0xfcc68 blt 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfcc6c ldr r3, [pc, #0x64] */
/* @0xfcc70 ldr r3, [pc, r3] */
/* @0xfcc74 ldr r3, [r3] */
/* @0xfcc78 cmp r0, r3 */
/* @0xfcc7c bge 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfcc80 ldr r3, [pc, #0x54] */
/* @0xfcc84 ldr r3, [pc, r3] */
/* @0xfcc88 ldr r3, [r3, #0x4] */
/* @0xfcc8c ldr r0, [r3, r0, lsl #2] */
/* @0xfcc90 cmp r0, #0 */
/* @0xfcc94 beq 0xfccc4 <_Z17F_DsPriorityEmptyR6RValueP9CInstanceS2_iPS_+0x74> */
/* @0xfcc98 mov r5, #0 */
/* @0xfcc9c str r5, [r4, #0xc] */
/* @0xfcca0 bl 0x2040f8 <_ZN12CDS_Priority5EmptyEv> */
/* @0xfcca4 cmp r0, #0 */
/* @0xfcca8 moveq r5, r0 */
/* @0xfccac movne r3, r5 */
/* @0xfccb0 moveq r3, r5 */
/* @0xfccb4 movtne r3, #0x3ff0 */
/* @0xfccb8 str r5, [r4] */
/* @0xfccbc str r3, [r4, #0x4] */
/* @0xfccc0 pop {r3, r4, r5, pc} */
/* @0xfccc4 ldr r0, [pc, #0x14] */
/* @0xfccc8 mov r1, #0 */
/* @0xfcccc pop {r3, r4, r5, lr} */
/* @0xfccd0 add r0, pc, r0 */
/* @0xfccd4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfccd8 eoreq r1, pc, r4, lsl #4 */
/* @0xfccdc .word 0x002f11f4 */
/* @0xfcce0 eoreq r10, r3, r12, lsr #30 */

/* ── FUNC 0xfcce4 · F_DsPriorityAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0xfcce4 push {r4, lr} */
/* @0xfcce8 mov r1, #0 */
/* @0xfccec ldr r4, [sp, #0x8] */
/* @0xfccf0 mov r0, r4 */
/* @0xfccf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfccf8 cmp r0, #0 */
/* @0xfccfc blt 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcd00 ldr r3, [pc, #0x48] */
/* @0xfcd04 ldr r3, [pc, r3] */
/* @0xfcd08 ldr r3, [r3] */
/* @0xfcd0c cmp r0, r3 */
/* @0xfcd10 bge 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcd14 ldr r3, [pc, #0x38] */
/* @0xfcd18 ldr r3, [pc, r3] */
/* @0xfcd1c ldr r3, [r3, #0x4] */
/* @0xfcd20 ldr r0, [r3, r0, lsl #2] */
/* @0xfcd24 cmp r0, #0 */
/* @0xfcd28 beq 0xfcd3c <_Z15F_DsPriorityAddR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcd2c add r1, r4, #16 */
/* @0xfcd30 add r2, r4, #32 */
/* @0xfcd34 pop {r4, lr} */
/* @0xfcd38 b 0x206510 <_ZN12CDS_Priority3AddEP6RValueS1_> */
/* @0xfcd3c ldr r0, [pc, #0x14] */
/* @0xfcd40 mov r1, #0 */
/* @0xfcd44 pop {r4, lr} */
/* @0xfcd48 add r0, pc, r0 */
/* @0xfcd4c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcd50 eoreq r1, pc, r0, ror r1 */
/* @0xfcd54 eoreq r1, pc, r0, ror #2 */
/* @0xfcd58 .word 0x0023aeb4 */

/* ── FUNC 0xfcd5c · F_DsPriorityChangePriority(RValue&, CInstance*, CInstance*, int, RValue*) · size=120 · insn=30 */
/* @0xfcd5c push {r4, lr} */
/* @0xfcd60 mov r1, #0 */
/* @0xfcd64 ldr r4, [sp, #0x8] */
/* @0xfcd68 mov r0, r4 */
/* @0xfcd6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcd70 cmp r0, #0 */
/* @0xfcd74 blt 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcd78 ldr r3, [pc, #0x48] */
/* @0xfcd7c ldr r3, [pc, r3] */
/* @0xfcd80 ldr r3, [r3] */
/* @0xfcd84 cmp r0, r3 */
/* @0xfcd88 bge 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcd8c ldr r3, [pc, #0x38] */
/* @0xfcd90 ldr r3, [pc, r3] */
/* @0xfcd94 ldr r3, [r3, #0x4] */
/* @0xfcd98 ldr r0, [r3, r0, lsl #2] */
/* @0xfcd9c cmp r0, #0 */
/* @0xfcda0 beq 0xfcdb4 <_Z26F_DsPriorityChangePriorityR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0xfcda4 add r1, r4, #16 */
/* @0xfcda8 add r2, r4, #32 */
/* @0xfcdac pop {r4, lr} */
/* @0xfcdb0 b 0x20a148 <_ZN12CDS_Priority6ChangeEP6RValueS1_> */
/* @0xfcdb4 ldr r0, [pc, #0x14] */
/* @0xfcdb8 mov r1, #0 */
/* @0xfcdbc pop {r4, lr} */
/* @0xfcdc0 add r0, pc, r0 */
/* @0xfcdc4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcdc8 .word 0x002f10f8 */
/* @0xfcdcc eoreq r1, pc, r8, ror #1 */
/* @0xfcdd0 eoreq r10, r3, r12, lsr lr */

/* ── FUNC 0xfcdd4 · F_DsPriorityDeleteValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xfcdd4 push {r4, lr} */
/* @0xfcdd8 mov r1, #0 */
/* @0xfcddc ldr r4, [sp, #0x8] */
/* @0xfcde0 mov r0, r4 */
/* @0xfcde4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcde8 cmp r0, #0 */
/* @0xfcdec blt 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfcdf0 ldr r3, [pc, #0x44] */
/* @0xfcdf4 ldr r3, [pc, r3] */
/* @0xfcdf8 ldr r3, [r3] */
/* @0xfcdfc cmp r0, r3 */
/* @0xfce00 bge 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfce04 ldr r3, [pc, #0x34] */
/* @0xfce08 ldr r3, [pc, r3] */
/* @0xfce0c ldr r3, [r3, #0x4] */
/* @0xfce10 ldr r0, [r3, r0, lsl #2] */
/* @0xfce14 cmp r0, #0 */
/* @0xfce18 beq 0xfce28 <_Z23F_DsPriorityDeleteValueR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfce1c add r1, r4, #16 */
/* @0xfce20 pop {r4, lr} */
/* @0xfce24 b 0x20a424 <_ZN12CDS_Priority6DeleteEP6RValue> */
/* @0xfce28 ldr r0, [pc, #0x14] */
/* @0xfce2c mov r1, #0 */
/* @0xfce30 pop {r4, lr} */
/* @0xfce34 add r0, pc, r0 */
/* @0xfce38 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfce3c eoreq r1, pc, r0, lsl #1 */
/* @0xfce40 eoreq r1, pc, r0, ror r0 */
/* @0xfce44 eoreq r10, r3, r8, asr #27 */

/* ── FUNC 0xfce48 · F_DsPriorityDeleteMin(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xfce48 push {r4, lr} */
/* @0xfce4c mov r1, #0 */
/* @0xfce50 mov r4, r0 */
/* @0xfce54 ldr r0, [sp, #0x8] */
/* @0xfce58 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfce5c cmp r0, #0 */
/* @0xfce60 blt 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfce64 ldr r3, [pc, #0x44] */
/* @0xfce68 ldr r3, [pc, r3] */
/* @0xfce6c ldr r3, [r3] */
/* @0xfce70 cmp r0, r3 */
/* @0xfce74 bge 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfce78 ldr r3, [pc, #0x34] */
/* @0xfce7c ldr r3, [pc, r3] */
/* @0xfce80 ldr r3, [r3, #0x4] */
/* @0xfce84 ldr r0, [r3, r0, lsl #2] */
/* @0xfce88 cmp r0, #0 */
/* @0xfce8c beq 0xfce9c <_Z21F_DsPriorityDeleteMinR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfce90 mov r1, r4 */
/* @0xfce94 pop {r4, lr} */
/* @0xfce98 b 0x20a99c <_ZN12CDS_Priority9DeleteMinEP6RValue> */
/* @0xfce9c ldr r0, [pc, #0x14] */
/* @0xfcea0 mov r1, #0 */
/* @0xfcea4 pop {r4, lr} */
/* @0xfcea8 add r0, pc, r0 */
/* @0xfceac b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfceb0 eoreq r1, pc, r12 */
/* @0xfceb4 .word 0x002f0ffc */
/* @0xfceb8 eoreq r10, r3, r4, asr sp */

/* ── FUNC 0xfcebc · F_DsPriorityDeleteMax(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xfcebc push {r4, lr} */
/* @0xfcec0 mov r1, #0 */
/* @0xfcec4 mov r4, r0 */
/* @0xfcec8 ldr r0, [sp, #0x8] */
/* @0xfcecc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfced0 cmp r0, #0 */
/* @0xfced4 blt 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfced8 ldr r3, [pc, #0x44] */
/* @0xfcedc ldr r3, [pc, r3] */
/* @0xfcee0 ldr r3, [r3] */
/* @0xfcee4 cmp r0, r3 */
/* @0xfcee8 bge 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfceec ldr r3, [pc, #0x34] */
/* @0xfcef0 ldr r3, [pc, r3] */
/* @0xfcef4 ldr r3, [r3, #0x4] */
/* @0xfcef8 ldr r0, [r3, r0, lsl #2] */
/* @0xfcefc cmp r0, #0 */
/* @0xfcf00 beq 0xfcf10 <_Z21F_DsPriorityDeleteMaxR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfcf04 mov r1, r4 */
/* @0xfcf08 pop {r4, lr} */
/* @0xfcf0c b 0x20accc <_ZN12CDS_Priority9DeleteMaxEP6RValue> */
/* @0xfcf10 ldr r0, [pc, #0x14] */
/* @0xfcf14 mov r1, #0 */
/* @0xfcf18 pop {r4, lr} */
/* @0xfcf1c add r0, pc, r0 */
/* @0xfcf20 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcf24 mlaeq pc, r8, pc, r0 */
/* @0xfcf28 eoreq r0, pc, r8, lsl #31 */
/* @0xfcf2c eoreq r10, r3, r0, ror #25 */

/* ── FUNC 0xfcf30 · F_DsPriorityWrite(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfcf30 push {r4, lr} */
/* @0xfcf34 sub sp, sp, #8 */
/* @0xfcf38 mov r4, r0 */
/* @0xfcf3c mov r1, #0 */
/* @0xfcf40 ldr r0, [sp, #0x10] */
/* @0xfcf44 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcf48 subs r2, r0, #0 */
/* @0xfcf4c blt 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfcf50 ldr r3, [pc, #0x6c] */
/* @0xfcf54 ldr r3, [pc, r3] */
/* @0xfcf58 ldr r3, [r3] */
/* @0xfcf5c cmp r2, r3 */
/* @0xfcf60 bge 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfcf64 ldr r3, [pc, #0x5c] */
/* @0xfcf68 ldr r3, [pc, r3] */
/* @0xfcf6c ldr r3, [r3, #0x4] */
/* @0xfcf70 ldr r1, [r3, r2, lsl #2] */
/* @0xfcf74 cmp r1, #0 */
/* @0xfcf78 beq 0xfcfac <_Z17F_DsPriorityWriteR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0xfcf7c add r1, sp, #8 */
/* @0xfcf80 mov r0, #0 */
/* @0xfcf84 str r0, [r1, #-0x4]! */
/* @0xfcf88 ldr r0, [r3, r2, lsl #2] */
/* @0xfcf8c bl 0x203d6c <_ZN12CDS_Priority13WriteToStringERPKc> */
/* @0xfcf90 mov r0, r4 */
/* @0xfcf94 ldr r1, [sp, #0x4] */
/* @0xfcf98 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* @0xfcf9c ldr r0, [sp, #0x4] */
/* @0xfcfa0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0xfcfa4 add sp, sp, #8 */
/* @0xfcfa8 pop {r4, pc} */
/* @0xfcfac ldr r0, [pc, #0x18] */
/* @0xfcfb0 mov r1, #0 */
/* @0xfcfb4 add r0, pc, r0 */
/* @0xfcfb8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfcfbc add sp, sp, #8 */
/* @0xfcfc0 pop {r4, pc} */
/* @0xfcfc4 eoreq r0, pc, r0, lsr #30 */
/* @0xfcfc8 eoreq r0, pc, r0, lsl pc */
/* @0xfcfcc eoreq r10, r3, r8, asr #24 */

/* ── FUNC 0xfcfd0 · F_DsPriorityRead(RValue&, CInstance*, CInstance*, int, RValue*) · size=172 · insn=43 */
/* @0xfcfd0 push {r3, r4, r5, r6, r7, lr} */
/* @0xfcfd4 mov r1, #0 */
/* @0xfcfd8 ldr r5, [sp, #0x18] */
/* @0xfcfdc mov r6, r3 */
/* @0xfcfe0 mov r0, r5 */
/* @0xfcfe4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfcfe8 mov r1, #1 */
/* @0xfcfec mov r4, r0 */
/* @0xfcff0 mov r0, r5 */
/* @0xfcff4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei> */
/* @0xfcff8 cmp r6, #3 */
/* @0xfcffc movne r2, #0 */
/* @0xfd000 mov r7, r0 */
/* @0xfd004 beq 0xfd05c <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0xfd008 cmp r4, #0 */
/* @0xfd00c blt 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfd010 ldr r3, [pc, #0x58] */
/* @0xfd014 ldr r3, [pc, r3] */
/* @0xfd018 ldr r3, [r3] */
/* @0xfd01c cmp r4, r3 */
/* @0xfd020 bge 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfd024 ldr r3, [pc, #0x48] */
/* @0xfd028 ldr r3, [pc, r3] */
/* @0xfd02c ldr r3, [r3, #0x4] */
/* @0xfd030 ldr r0, [r3, r4, lsl #2] */
/* @0xfd034 cmp r0, #0 */
/* @0xfd038 beq 0xfd048 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x78> */
/* @0xfd03c mov r1, r7 */
/* @0xfd040 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfd044 b 0x2098d0 <_ZN12CDS_Priority14ReadFromStringEPKcb> */
/* @0xfd048 ldr r0, [pc, #0x28] */
/* @0xfd04c mov r1, #0 */
/* @0xfd050 pop {r3, r4, r5, r6, r7, lr} */
/* @0xfd054 add r0, pc, r0 */
/* @0xfd058 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd05c mov r0, r5 */
/* @0xfd060 mov r1, #2 */
/* @0xfd064 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0xfd068 mov r2, r0 */
/* @0xfd06c b 0xfd008 <_Z16F_DsPriorityReadR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0xfd070 eoreq r0, pc, r0, ror #28 */
/* @0xfd074 eoreq r0, pc, r0, asr lr */
/* @0xfd078 eoreq r10, r3, r8, lsr #23 */

/* ── FUNC 0xfd07c · F_DsGridDestroy(RValue&, CInstance*, CInstance*, int, RValue*) · size=132 · insn=33 */
/* @0xfd07c push {r4, r5, r6, lr} */
/* @0xfd080 mov r1, #0 */
/* @0xfd084 ldr r0, [sp, #0x10] */
/* @0xfd088 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd08c subs r4, r0, #0 */
/* @0xfd090 blt 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfd094 ldr r3, [pc, #0x58] */
/* @0xfd098 ldr r3, [pc, r3] */
/* @0xfd09c ldr r3, [r3] */
/* @0xfd0a0 cmp r4, r3 */
/* @0xfd0a4 bge 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfd0a8 ldr r5, [pc, #0x48] */
/* @0xfd0ac ldr r5, [pc, r5] */
/* @0xfd0b0 ldr r3, [r5, #0x4] */
/* @0xfd0b4 ldr r6, [r3, r4, lsl #2] */
/* @0xfd0b8 cmp r6, #0 */
/* @0xfd0bc beq 0xfd0e0 <_Z15F_DsGridDestroyR6RValueP9CInstanceS2_iPS_+0x64> */
/* @0xfd0c0 mov r0, r6 */
/* @0xfd0c4 bl 0x20b260 <_ZN8CDS_GridD2Ev> */
/* @0xfd0c8 mov r0, r6 */
/* @0xfd0cc bl 0x27d1d0 <_ZdlPv> */
/* @0xfd0d0 ldr r3, [r5, #0x4] */
/* @0xfd0d4 mov r2, #0 */
/* @0xfd0d8 str r2, [r3, r4, lsl #2] */
/* @0xfd0dc pop {r4, r5, r6, pc} */
/* @0xfd0e0 ldr r0, [pc, #0x14] */
/* @0xfd0e4 mov r1, #0 */
/* @0xfd0e8 pop {r4, r5, r6, lr} */
/* @0xfd0ec add r0, pc, r0 */
/* @0xfd0f0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd0f4 eoreq r0, pc, r12, ror #27 */
/* @0xfd0f8 .word 0x002f0ddc */
/* @0xfd0fc eoreq r10, r3, r0, lsl r11 */

/* ── FUNC 0xfd100 · F_DsGridResize(RValue&, CInstance*, CInstance*, int, RValue*) · size=188 · insn=47 */
/* @0xfd100 push {r4, r5, r6, lr} */
/* @0xfd104 mov r1, #0 */
/* @0xfd108 ldr r4, [sp, #0x10] */
/* @0xfd10c mov r0, r4 */
/* @0xfd110 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd114 mov r1, #1 */
/* @0xfd118 mov r5, r0 */
/* @0xfd11c mov r0, r4 */
/* @0xfd120 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd124 mov r1, #2 */
/* @0xfd128 mov r6, r0 */
/* @0xfd12c mov r0, r4 */
/* @0xfd130 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd134 cmp r5, #0 */
/* @0xfd138 mov r2, r0 */
/* @0xfd13c blt 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfd140 ldr r3, [pc, #0x64] */
/* @0xfd144 ldr r3, [pc, r3] */
/* @0xfd148 ldr r3, [r3] */
/* @0xfd14c cmp r5, r3 */
/* @0xfd150 bge 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfd154 ldr r3, [pc, #0x54] */
/* @0xfd158 ldr r3, [pc, r3] */
/* @0xfd15c ldr r3, [r3, #0x4] */
/* @0xfd160 ldr r0, [r3, r5, lsl #2] */
/* @0xfd164 cmp r0, #0 */
/* @0xfd168 beq 0xfd184 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0xfd16c cmp r6, #0 */
/* @0xfd170 cmpgt r2, #0 */
/* @0xfd174 ble 0xfd198 <_Z14F_DsGridResizeR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0xfd178 mov r1, r6 */
/* @0xfd17c pop {r4, r5, r6, lr} */
/* @0xfd180 b 0x20c3bc <_ZN8CDS_Grid6ResizeEii> */
/* @0xfd184 ldr r0, [pc, #0x28] */
/* @0xfd188 mov r1, #0 */
/* @0xfd18c pop {r4, r5, r6, lr} */
/* @0xfd190 add r0, pc, r0 */
/* @0xfd194 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd198 ldr r0, [pc, #0x18] */
/* @0xfd19c mov r1, #1 */
/* @0xfd1a0 pop {r4, r5, r6, lr} */
/* @0xfd1a4 add r0, pc, r0 */
/* @0xfd1a8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd1ac eoreq r0, pc, r0, asr #26 */
/* @0xfd1b0 eoreq r0, pc, r0, lsr sp */
/* @0xfd1b4 eoreq r10, r3, r12, ror #20 */
/* @0xfd1b8 eoreq r10, r3, r4, lsl #21 */

/* ── FUNC 0xfd1bc · F_DsGridCopy(RValue&, CInstance*, CInstance*, int, RValue*) · size=160 · insn=40 */
/* @0xfd1bc push {r3, r4, r5, lr} */
/* @0xfd1c0 mov r1, #0 */
/* @0xfd1c4 ldr r5, [sp, #0x10] */
/* @0xfd1c8 mov r0, r5 */
/* @0xfd1cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd1d0 mov r1, #1 */
/* @0xfd1d4 mov r4, r0 */
/* @0xfd1d8 mov r0, r5 */
/* @0xfd1dc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd1e0 cmp r4, #0 */
/* @0xfd1e4 blt 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd1e8 ldr r3, [pc, #0x60] */
/* @0xfd1ec ldr r3, [pc, r3] */
/* @0xfd1f0 ldr r3, [r3] */
/* @0xfd1f4 cmp r4, r3 */
/* @0xfd1f8 bge 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd1fc ldr r2, [pc, #0x50] */
/* @0xfd200 ldr r2, [pc, r2] */
/* @0xfd204 ldr r2, [r2, #0x4] */
/* @0xfd208 ldr r12, [r2, r4, lsl #2] */
/* @0xfd20c cmp r12, #0 */
/* @0xfd210 beq 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd214 cmp r0, #0 */
/* @0xfd218 blt 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd21c cmp r0, r3 */
/* @0xfd220 bge 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd224 ldr r1, [r2, r0, lsl #2] */
/* @0xfd228 cmp r1, #0 */
/* @0xfd22c beq 0xfd23c <_Z12F_DsGridCopyR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0xfd230 mov r0, r12 */
/* @0xfd234 pop {r3, r4, r5, lr} */
/* @0xfd238 b 0x20b478 <_ZN8CDS_Grid6AssignEPS_> */
/* @0xfd23c ldr r0, [pc, #0x14] */
/* @0xfd240 mov r1, #0 */
/* @0xfd244 pop {r3, r4, r5, lr} */
/* @0xfd248 add r0, pc, r0 */
/* @0xfd24c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd250 mlaeq pc, r8, r12, r0 */
/* @0xfd254 eoreq r0, pc, r8, lsl #25 */
/* @0xfd258 .word 0x0023a9b4 */

/* ── FUNC 0xfd25c · F_DsGridClear(RValue&, CInstance*, CInstance*, int, RValue*) · size=116 · insn=29 */
/* @0xfd25c push {r4, lr} */
/* @0xfd260 mov r1, #0 */
/* @0xfd264 ldr r4, [sp, #0x8] */
/* @0xfd268 mov r0, r4 */
/* @0xfd26c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd270 cmp r0, #0 */
/* @0xfd274 blt 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfd278 ldr r3, [pc, #0x44] */
/* @0xfd27c ldr r3, [pc, r3] */
/* @0xfd280 ldr r3, [r3] */
/* @0xfd284 cmp r0, r3 */
/* @0xfd288 bge 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfd28c ldr r3, [pc, #0x34] */
/* @0xfd290 ldr r3, [pc, r3] */
/* @0xfd294 ldr r3, [r3, #0x4] */
/* @0xfd298 ldr r0, [r3, r0, lsl #2] */
/* @0xfd29c cmp r0, #0 */
/* @0xfd2a0 beq 0xfd2b0 <_Z13F_DsGridClearR6RValueP9CInstanceS2_iPS_+0x54> */
/* @0xfd2a4 add r1, r4, #16 */
/* @0xfd2a8 pop {r4, lr} */
/* @0xfd2ac b 0x20c120 <_ZN8CDS_Grid5ClearEP6RValue> */
/* @0xfd2b0 ldr r0, [pc, #0x14] */
/* @0xfd2b4 mov r1, #0 */
/* @0xfd2b8 pop {r4, lr} */
/* @0xfd2bc add r0, pc, r0 */
/* @0xfd2c0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd2c4 eoreq r0, pc, r8, lsl #24 */
/* @0xfd2c8 .word 0x002f0bf8 */
/* @0xfd2cc eoreq r10, r3, r0, asr #18 */

/* ── FUNC 0xfd2d0 · F_DsGridAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfd2d0 push {r4, r5, r6, lr} */
/* @0xfd2d4 sub sp, sp, #8 */
/* @0xfd2d8 mov r1, #0 */
/* @0xfd2dc ldr r4, [sp, #0x18] */
/* @0xfd2e0 mov r0, r4 */
/* @0xfd2e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd2e8 mov r1, #1 */
/* @0xfd2ec mov r5, r0 */
/* @0xfd2f0 mov r0, r4 */
/* @0xfd2f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd2f8 mov r1, #2 */
/* @0xfd2fc mov r6, r0 */
/* @0xfd300 mov r0, r4 */
/* @0xfd304 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd308 cmp r5, #0 */
/* @0xfd30c blt 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd310 ldr r2, [pc, #0x60] */
/* @0xfd314 ldr r2, [pc, r2] */
/* @0xfd318 ldr r2, [r2] */
/* @0xfd31c cmp r5, r2 */
/* @0xfd320 bge 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd324 ldr r2, [pc, #0x50] */
/* @0xfd328 ldr r2, [pc, r2] */
/* @0xfd32c ldr r3, [r2, #0x4] */
/* @0xfd330 ldr r2, [r3, r5, lsl #2] */
/* @0xfd334 cmp r2, #0 */
/* @0xfd338 beq 0xfd360 <_Z11F_DsGridAddR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd33c add r4, r4, #48 */
/* @0xfd340 mov r1, r5 */
/* @0xfd344 stm sp, {r0, r4} */
/* @0xfd348 mov r3, r6 */
/* @0xfd34c mov r0, r2 */
/* @0xfd350 mov r2, #2 */
/* @0xfd354 bl 0x207d1c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue> */
/* @0xfd358 add sp, sp, #8 */
/* @0xfd35c pop {r4, r5, r6, pc} */
/* @0xfd360 ldr r0, [pc, #0x18] */
/* @0xfd364 mov r1, #0 */
/* @0xfd368 add r0, pc, r0 */
/* @0xfd36c add sp, sp, #8 */
/* @0xfd370 pop {r4, r5, r6, lr} */
/* @0xfd374 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd378 eoreq r0, pc, r0, ror r11 */
/* @0xfd37c eoreq r0, pc, r0, ror #22 */
/* @0xfd380 mlaeq r3, r4, r8, r10 */

/* ── FUNC 0xfd384 · F_DsGridMultiply(RValue&, CInstance*, CInstance*, int, RValue*) · size=180 · insn=45 */
/* @0xfd384 push {r4, r5, r6, lr} */
/* @0xfd388 sub sp, sp, #8 */
/* @0xfd38c mov r1, #0 */
/* @0xfd390 ldr r4, [sp, #0x18] */
/* @0xfd394 mov r0, r4 */
/* @0xfd398 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd39c mov r1, #1 */
/* @0xfd3a0 mov r5, r0 */
/* @0xfd3a4 mov r0, r4 */
/* @0xfd3a8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd3ac mov r1, #2 */
/* @0xfd3b0 mov r6, r0 */
/* @0xfd3b4 mov r0, r4 */
/* @0xfd3b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd3bc cmp r5, #0 */
/* @0xfd3c0 blt 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd3c4 ldr r2, [pc, #0x60] */
/* @0xfd3c8 ldr r2, [pc, r2] */
/* @0xfd3cc ldr r2, [r2] */
/* @0xfd3d0 cmp r5, r2 */
/* @0xfd3d4 bge 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd3d8 ldr r2, [pc, #0x50] */
/* @0xfd3dc ldr r2, [pc, r2] */
/* @0xfd3e0 ldr r3, [r2, #0x4] */
/* @0xfd3e4 ldr r2, [r3, r5, lsl #2] */
/* @0xfd3e8 cmp r2, #0 */
/* @0xfd3ec beq 0xfd414 <_Z16F_DsGridMultiplyR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0xfd3f0 add r4, r4, #48 */
/* @0xfd3f4 mov r1, r5 */
/* @0xfd3f8 stm sp, {r0, r4} */
/* @0xfd3fc mov r3, r6 */
/* @0xfd400 mov r0, r2 */
/* @0xfd404 mov r2, #3 */
/* @0xfd408 bl 0x207d1c <_ZN8CDS_Grid14Cell_OperationEiiiiP6RValue> */
/* @0xfd40c add sp, sp, #8 */
/* @0xfd410 pop {r4, r5, r6, pc} */
/* @0xfd414 ldr r0, [pc, #0x18] */
/* @0xfd418 mov r1, #0 */
/* @0xfd41c add r0, pc, r0 */
/* @0xfd420 add sp, sp, #8 */
/* @0xfd424 pop {r4, r5, r6, lr} */
/* @0xfd428 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd42c .word 0x002f0abc */
/* @0xfd430 eoreq r0, pc, r12, lsr #21 */
/* @0xfd434 eoreq r10, r3, r0, ror #15 */

/* ── FUNC 0xfd438 · F_DsGridSetRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd438 push {r4, r5, r6, r7, r8, lr} */
/* @0xfd43c sub sp, sp, #16 */
/* @0xfd440 mov r1, #0 */
/* @0xfd444 ldr r4, [sp, #0x28] */
/* @0xfd448 mov r0, r4 */
/* @0xfd44c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd450 mov r1, #1 */
/* @0xfd454 mov r5, r0 */
/* @0xfd458 mov r0, r4 */
/* @0xfd45c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd460 mov r1, #2 */
/* @0xfd464 mov r7, r0 */
/* @0xfd468 mov r0, r4 */
/* @0xfd46c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd470 mov r1, #3 */
/* @0xfd474 mov r6, r0 */
/* @0xfd478 mov r0, r4 */
/* @0xfd47c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd480 mov r1, #4 */
/* @0xfd484 mov r8, r0 */
/* @0xfd488 mov r0, r4 */
/* @0xfd48c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd490 cmp r5, #0 */
/* @0xfd494 mov r2, r0 */
/* @0xfd498 blt 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd49c ldr r1, [pc, #0x60] */
/* @0xfd4a0 ldr r1, [pc, r1] */
/* @0xfd4a4 ldr r1, [r1] */
/* @0xfd4a8 cmp r5, r1 */
/* @0xfd4ac bge 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd4b0 ldr r1, [pc, #0x50] */
/* @0xfd4b4 ldr r1, [pc, r1] */
/* @0xfd4b8 ldr r3, [r1, #0x4] */
/* @0xfd4bc ldr r0, [r3, r5, lsl #2] */
/* @0xfd4c0 cmp r0, #0 */
/* @0xfd4c4 beq 0xfd4ec <_Z17F_DsGridSetRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd4c8 add r4, r4, #80 */
/* @0xfd4cc str r8, [sp] */
/* @0xfd4d0 stmib sp, {r2, r4} */
/* @0xfd4d4 mov r3, r6 */
/* @0xfd4d8 mov r2, r7 */
/* @0xfd4dc mov r1, #1 */
/* @0xfd4e0 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue> */
/* @0xfd4e4 add sp, sp, #16 */
/* @0xfd4e8 pop {r4, r5, r6, r7, r8, pc} */
/* @0xfd4ec ldr r0, [pc, #0x18] */
/* @0xfd4f0 mov r1, #0 */
/* @0xfd4f4 add r0, pc, r0 */
/* @0xfd4f8 add sp, sp, #16 */
/* @0xfd4fc pop {r4, r5, r6, r7, r8, lr} */
/* @0xfd500 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd504 eoreq r0, pc, r4, ror #19 */
/* @0xfd508 .word 0x002f09d4 */
/* @0xfd50c eoreq r10, r3, r8, lsl #14 */

/* ── FUNC 0xfd510 · F_DsGridAddRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd510 push {r4, r5, r6, r7, r8, lr} */
/* @0xfd514 sub sp, sp, #16 */
/* @0xfd518 mov r1, #0 */
/* @0xfd51c ldr r4, [sp, #0x28] */
/* @0xfd520 mov r0, r4 */
/* @0xfd524 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd528 mov r1, #1 */
/* @0xfd52c mov r5, r0 */
/* @0xfd530 mov r0, r4 */
/* @0xfd534 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd538 mov r1, #2 */
/* @0xfd53c mov r7, r0 */
/* @0xfd540 mov r0, r4 */
/* @0xfd544 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd548 mov r1, #3 */
/* @0xfd54c mov r6, r0 */
/* @0xfd550 mov r0, r4 */
/* @0xfd554 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd558 mov r1, #4 */
/* @0xfd55c mov r8, r0 */
/* @0xfd560 mov r0, r4 */
/* @0xfd564 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd568 cmp r5, #0 */
/* @0xfd56c mov r2, r0 */
/* @0xfd570 blt 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd574 ldr r1, [pc, #0x60] */
/* @0xfd578 ldr r1, [pc, r1] */
/* @0xfd57c ldr r1, [r1] */
/* @0xfd580 cmp r5, r1 */
/* @0xfd584 bge 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd588 ldr r1, [pc, #0x50] */
/* @0xfd58c ldr r1, [pc, r1] */
/* @0xfd590 ldr r3, [r1, #0x4] */
/* @0xfd594 ldr r0, [r3, r5, lsl #2] */
/* @0xfd598 cmp r0, #0 */
/* @0xfd59c beq 0xfd5c4 <_Z17F_DsGridAddRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd5a0 add r4, r4, #80 */
/* @0xfd5a4 str r8, [sp] */
/* @0xfd5a8 stmib sp, {r2, r4} */
/* @0xfd5ac mov r3, r6 */
/* @0xfd5b0 mov r2, r7 */
/* @0xfd5b4 mov r1, #2 */
/* @0xfd5b8 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue> */
/* @0xfd5bc add sp, sp, #16 */
/* @0xfd5c0 pop {r4, r5, r6, r7, r8, pc} */
/* @0xfd5c4 ldr r0, [pc, #0x18] */
/* @0xfd5c8 mov r1, #0 */
/* @0xfd5cc add r0, pc, r0 */
/* @0xfd5d0 add sp, sp, #16 */
/* @0xfd5d4 pop {r4, r5, r6, r7, r8, lr} */
/* @0xfd5d8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd5dc eoreq r0, pc, r12, lsl #18 */
/* @0xfd5e0 .word 0x002f08fc */
/* @0xfd5e4 eoreq r10, r3, r0, lsr r6 */

/* ── FUNC 0xfd5e8 · F_DsGridMultiplyRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd5e8 push {r4, r5, r6, r7, r8, lr} */
/* @0xfd5ec sub sp, sp, #16 */
/* @0xfd5f0 mov r1, #0 */
/* @0xfd5f4 ldr r4, [sp, #0x28] */
/* @0xfd5f8 mov r0, r4 */
/* @0xfd5fc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd600 mov r1, #1 */
/* @0xfd604 mov r5, r0 */
/* @0xfd608 mov r0, r4 */
/* @0xfd60c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd610 mov r1, #2 */
/* @0xfd614 mov r7, r0 */
/* @0xfd618 mov r0, r4 */
/* @0xfd61c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd620 mov r1, #3 */
/* @0xfd624 mov r6, r0 */
/* @0xfd628 mov r0, r4 */
/* @0xfd62c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd630 mov r1, #4 */
/* @0xfd634 mov r8, r0 */
/* @0xfd638 mov r0, r4 */
/* @0xfd63c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd640 cmp r5, #0 */
/* @0xfd644 mov r2, r0 */
/* @0xfd648 blt 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd64c ldr r1, [pc, #0x60] */
/* @0xfd650 ldr r1, [pc, r1] */
/* @0xfd654 ldr r1, [r1] */
/* @0xfd658 cmp r5, r1 */
/* @0xfd65c bge 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd660 ldr r1, [pc, #0x50] */
/* @0xfd664 ldr r1, [pc, r1] */
/* @0xfd668 ldr r3, [r1, #0x4] */
/* @0xfd66c ldr r0, [r3, r5, lsl #2] */
/* @0xfd670 cmp r0, #0 */
/* @0xfd674 beq 0xfd69c <_Z22F_DsGridMultiplyRegionR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd678 add r4, r4, #80 */
/* @0xfd67c str r8, [sp] */
/* @0xfd680 stmib sp, {r2, r4} */
/* @0xfd684 mov r3, r6 */
/* @0xfd688 mov r2, r7 */
/* @0xfd68c mov r1, #3 */
/* @0xfd690 bl 0x207db4 <_ZN8CDS_Grid16Region_OperationEiiiiiP6RValue> */
/* @0xfd694 add sp, sp, #16 */
/* @0xfd698 pop {r4, r5, r6, r7, r8, pc} */
/* @0xfd69c ldr r0, [pc, #0x18] */
/* @0xfd6a0 mov r1, #0 */
/* @0xfd6a4 add r0, pc, r0 */
/* @0xfd6a8 add sp, sp, #16 */
/* @0xfd6ac pop {r4, r5, r6, r7, r8, lr} */
/* @0xfd6b0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd6b4 eoreq r0, pc, r4, lsr r8 */
/* @0xfd6b8 eoreq r0, pc, r4, lsr #16 */
/* @0xfd6bc eoreq r10, r3, r8, asr r5 */

/* ── FUNC 0xfd6c0 · F_DsGridSetDisk(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd6c0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd6c4 sub sp, sp, #28 */
/* @0xfd6c8 mov r1, #0 */
/* @0xfd6cc ldr r8, [sp, #0x38] */
/* @0xfd6d0 mov r0, r8 */
/* @0xfd6d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd6d8 mov r1, #1 */
/* @0xfd6dc mov r9, r0 */
/* @0xfd6e0 mov r0, r8 */
/* @0xfd6e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd6e8 mov r4, r0 */
/* @0xfd6ec mov r5, r1 */
/* @0xfd6f0 mov r0, r8 */
/* @0xfd6f4 mov r1, #2 */
/* @0xfd6f8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd6fc mov r6, r0 */
/* @0xfd700 mov r7, r1 */
/* @0xfd704 mov r0, r8 */
/* @0xfd708 mov r1, #3 */
/* @0xfd70c bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd710 cmp r9, #0 */
/* @0xfd714 mov r2, r0 */
/* @0xfd718 mov r3, r1 */
/* @0xfd71c blt 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd720 ldr r1, [pc, #0x64] */
/* @0xfd724 ldr r1, [pc, r1] */
/* @0xfd728 ldr r1, [r1] */
/* @0xfd72c cmp r9, r1 */
/* @0xfd730 bge 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd734 ldr r1, [pc, #0x54] */
/* @0xfd738 ldr r1, [pc, r1] */
/* @0xfd73c ldr r1, [r1, #0x4] */
/* @0xfd740 ldr r0, [r1, r9, lsl #2] */
/* @0xfd744 cmp r0, #0 */
/* @0xfd748 beq 0xfd774 <_Z15F_DsGridSetDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd74c strd r2, r3, [sp, #8] */
/* @0xfd750 add r8, r8, #64 */
/* @0xfd754 strd r6, r7, [sp] */
/* @0xfd758 mov r2, r4 */
/* @0xfd75c str r8, [sp, #0x10] */
/* @0xfd760 mov r3, r5 */
/* @0xfd764 mov r1, #1 */
/* @0xfd768 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue> */
/* @0xfd76c add sp, sp, #28 */
/* @0xfd770 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfd774 ldr r0, [pc, #0x18] */
/* @0xfd778 mov r1, #0 */
/* @0xfd77c add r0, pc, r0 */
/* @0xfd780 add sp, sp, #28 */
/* @0xfd784 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd788 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd78c eoreq r0, pc, r0, ror #14 */
/* @0xfd790 eoreq r0, pc, r0, asr r7 */
/* @0xfd794 eoreq r10, r3, r0, lsl #9 */

/* ── FUNC 0xfd798 · F_DsGridAddDisk(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd798 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd79c sub sp, sp, #28 */
/* @0xfd7a0 mov r1, #0 */
/* @0xfd7a4 ldr r8, [sp, #0x38] */
/* @0xfd7a8 mov r0, r8 */
/* @0xfd7ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd7b0 mov r1, #1 */
/* @0xfd7b4 mov r9, r0 */
/* @0xfd7b8 mov r0, r8 */
/* @0xfd7bc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd7c0 mov r4, r0 */
/* @0xfd7c4 mov r5, r1 */
/* @0xfd7c8 mov r0, r8 */
/* @0xfd7cc mov r1, #2 */
/* @0xfd7d0 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd7d4 mov r6, r0 */
/* @0xfd7d8 mov r7, r1 */
/* @0xfd7dc mov r0, r8 */
/* @0xfd7e0 mov r1, #3 */
/* @0xfd7e4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd7e8 cmp r9, #0 */
/* @0xfd7ec mov r2, r0 */
/* @0xfd7f0 mov r3, r1 */
/* @0xfd7f4 blt 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd7f8 ldr r1, [pc, #0x64] */
/* @0xfd7fc ldr r1, [pc, r1] */
/* @0xfd800 ldr r1, [r1] */
/* @0xfd804 cmp r9, r1 */
/* @0xfd808 bge 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd80c ldr r1, [pc, #0x54] */
/* @0xfd810 ldr r1, [pc, r1] */
/* @0xfd814 ldr r1, [r1, #0x4] */
/* @0xfd818 ldr r0, [r1, r9, lsl #2] */
/* @0xfd81c cmp r0, #0 */
/* @0xfd820 beq 0xfd84c <_Z15F_DsGridAddDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd824 strd r2, r3, [sp, #8] */
/* @0xfd828 add r8, r8, #64 */
/* @0xfd82c strd r6, r7, [sp] */
/* @0xfd830 mov r2, r4 */
/* @0xfd834 str r8, [sp, #0x10] */
/* @0xfd838 mov r3, r5 */
/* @0xfd83c mov r1, #2 */
/* @0xfd840 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue> */
/* @0xfd844 add sp, sp, #28 */
/* @0xfd848 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfd84c ldr r0, [pc, #0x18] */
/* @0xfd850 mov r1, #0 */
/* @0xfd854 add r0, pc, r0 */
/* @0xfd858 add sp, sp, #28 */
/* @0xfd85c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd860 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd864 eoreq r0, pc, r8, lsl #13 */
/* @0xfd868 eoreq r0, pc, r8, ror r6 */
/* @0xfd86c eoreq r10, r3, r8, lsr #7 */

/* ── FUNC 0xfd870 · F_DsGridMultiplyDisk(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfd870 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd874 sub sp, sp, #28 */
/* @0xfd878 mov r1, #0 */
/* @0xfd87c ldr r8, [sp, #0x38] */
/* @0xfd880 mov r0, r8 */
/* @0xfd884 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd888 mov r1, #1 */
/* @0xfd88c mov r9, r0 */
/* @0xfd890 mov r0, r8 */
/* @0xfd894 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd898 mov r4, r0 */
/* @0xfd89c mov r5, r1 */
/* @0xfd8a0 mov r0, r8 */
/* @0xfd8a4 mov r1, #2 */
/* @0xfd8a8 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd8ac mov r6, r0 */
/* @0xfd8b0 mov r7, r1 */
/* @0xfd8b4 mov r0, r8 */
/* @0xfd8b8 mov r1, #3 */
/* @0xfd8bc bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0xfd8c0 cmp r9, #0 */
/* @0xfd8c4 mov r2, r0 */
/* @0xfd8c8 mov r3, r1 */
/* @0xfd8cc blt 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd8d0 ldr r1, [pc, #0x64] */
/* @0xfd8d4 ldr r1, [pc, r1] */
/* @0xfd8d8 ldr r1, [r1] */
/* @0xfd8dc cmp r9, r1 */
/* @0xfd8e0 bge 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd8e4 ldr r1, [pc, #0x54] */
/* @0xfd8e8 ldr r1, [pc, r1] */
/* @0xfd8ec ldr r1, [r1, #0x4] */
/* @0xfd8f0 ldr r0, [r1, r9, lsl #2] */
/* @0xfd8f4 cmp r0, #0 */
/* @0xfd8f8 beq 0xfd924 <_Z20F_DsGridMultiplyDiskR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfd8fc strd r2, r3, [sp, #8] */
/* @0xfd900 add r8, r8, #64 */
/* @0xfd904 strd r6, r7, [sp] */
/* @0xfd908 mov r2, r4 */
/* @0xfd90c str r8, [sp, #0x10] */
/* @0xfd910 mov r3, r5 */
/* @0xfd914 mov r1, #3 */
/* @0xfd918 bl 0x207e8c <_ZN8CDS_Grid14Disk_OperationEidddP6RValue> */
/* @0xfd91c add sp, sp, #28 */
/* @0xfd920 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfd924 ldr r0, [pc, #0x18] */
/* @0xfd928 mov r1, #0 */
/* @0xfd92c add r0, pc, r0 */
/* @0xfd930 add sp, sp, #28 */
/* @0xfd934 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfd938 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfd93c .word 0x002f05b0 */
/* @0xfd940 eoreq r0, pc, r0, lsr #11 */
/* @0xfd944 .word 0x0023a2d0 */

/* ── FUNC 0xfd948 · F_DsGridSetGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0xfd948 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfd94c sub sp, sp, #28 */
/* @0xfd950 mov r1, #0 */
/* @0xfd954 ldr r4, [sp, #0x40] */
/* @0xfd958 mov r0, r4 */
/* @0xfd95c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd960 mov r1, #1 */
/* @0xfd964 mov r5, r0 */
/* @0xfd968 mov r0, r4 */
/* @0xfd96c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd970 mov r1, #2 */
/* @0xfd974 mov r11, r0 */
/* @0xfd978 mov r0, r4 */
/* @0xfd97c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd980 mov r1, #3 */
/* @0xfd984 mov r7, r0 */
/* @0xfd988 mov r0, r4 */
/* @0xfd98c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd990 mov r1, #4 */
/* @0xfd994 mov r10, r0 */
/* @0xfd998 mov r0, r4 */
/* @0xfd99c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd9a0 mov r1, #5 */
/* @0xfd9a4 mov r9, r0 */
/* @0xfd9a8 mov r0, r4 */
/* @0xfd9ac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd9b0 mov r1, #6 */
/* @0xfd9b4 mov r8, r0 */
/* @0xfd9b8 mov r0, r4 */
/* @0xfd9bc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd9c0 mov r1, #7 */
/* @0xfd9c4 mov r6, r0 */
/* @0xfd9c8 mov r0, r4 */
/* @0xfd9cc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfd9d0 cmp r5, #0 */
/* @0xfd9d4 mov r12, r0 */
/* @0xfd9d8 blt 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfd9dc ldr r2, [pc, #0x80] */
/* @0xfd9e0 ldr r2, [pc, r2] */
/* @0xfd9e4 ldr r3, [r2] */
/* @0xfd9e8 cmp r5, r3 */
/* @0xfd9ec bge 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfd9f0 ldr r2, [pc, #0x70] */
/* @0xfd9f4 ldr r2, [pc, r2] */
/* @0xfd9f8 ldr r2, [r2, #0x4] */
/* @0xfd9fc ldr r0, [r2, r5, lsl #2] */
/* @0xfda00 cmp r0, #0 */
/* @0xfda04 beq 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfda08 cmp r11, #0 */
/* @0xfda0c blt 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfda10 cmp r11, r3 */
/* @0xfda14 bge 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfda18 ldr r2, [r2, r11, lsl #2] */
/* @0xfda1c cmp r2, #0 */
/* @0xfda20 beq 0xfda4c <_Z21F_DsGridSetGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfda24 str r10, [sp] */
/* @0xfda28 mov r3, r7 */
/* @0xfda2c str r9, [sp, #0x4] */
/* @0xfda30 mov r1, #1 */
/* @0xfda34 str r8, [sp, #0x8] */
/* @0xfda38 str r6, [sp, #0xc] */
/* @0xfda3c str r12, [sp, #0x10] */
/* @0xfda40 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii> */
/* @0xfda44 add sp, sp, #28 */
/* @0xfda48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfda4c ldr r0, [pc, #0x18] */
/* @0xfda50 mov r1, #0 */
/* @0xfda54 add r0, pc, r0 */
/* @0xfda58 add sp, sp, #28 */
/* @0xfda5c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfda60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfda64 eoreq r0, pc, r4, lsr #9 */
/* @0xfda68 mlaeq pc, r4, r4, r0 */
/* @0xfda6c eoreq r10, r3, r8, lsr #3 */

/* ── FUNC 0xfda70 · F_DsGridAddGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0xfda70 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfda74 sub sp, sp, #28 */
/* @0xfda78 mov r1, #0 */
/* @0xfda7c ldr r4, [sp, #0x40] */
/* @0xfda80 mov r0, r4 */
/* @0xfda84 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfda88 mov r1, #1 */
/* @0xfda8c mov r5, r0 */
/* @0xfda90 mov r0, r4 */
/* @0xfda94 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfda98 mov r1, #2 */
/* @0xfda9c mov r11, r0 */
/* @0xfdaa0 mov r0, r4 */
/* @0xfdaa4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdaa8 mov r1, #3 */
/* @0xfdaac mov r7, r0 */
/* @0xfdab0 mov r0, r4 */
/* @0xfdab4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdab8 mov r1, #4 */
/* @0xfdabc mov r10, r0 */
/* @0xfdac0 mov r0, r4 */
/* @0xfdac4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdac8 mov r1, #5 */
/* @0xfdacc mov r9, r0 */
/* @0xfdad0 mov r0, r4 */
/* @0xfdad4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdad8 mov r1, #6 */
/* @0xfdadc mov r8, r0 */
/* @0xfdae0 mov r0, r4 */
/* @0xfdae4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdae8 mov r1, #7 */
/* @0xfdaec mov r6, r0 */
/* @0xfdaf0 mov r0, r4 */
/* @0xfdaf4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdaf8 cmp r5, #0 */
/* @0xfdafc mov r12, r0 */
/* @0xfdb00 blt 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb04 ldr r2, [pc, #0x80] */
/* @0xfdb08 ldr r2, [pc, r2] */
/* @0xfdb0c ldr r3, [r2] */
/* @0xfdb10 cmp r5, r3 */
/* @0xfdb14 bge 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb18 ldr r2, [pc, #0x70] */
/* @0xfdb1c ldr r2, [pc, r2] */
/* @0xfdb20 ldr r2, [r2, #0x4] */
/* @0xfdb24 ldr r0, [r2, r5, lsl #2] */
/* @0xfdb28 cmp r0, #0 */
/* @0xfdb2c beq 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb30 cmp r11, #0 */
/* @0xfdb34 blt 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb38 cmp r11, r3 */
/* @0xfdb3c bge 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb40 ldr r2, [r2, r11, lsl #2] */
/* @0xfdb44 cmp r2, #0 */
/* @0xfdb48 beq 0xfdb74 <_Z21F_DsGridAddGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdb4c str r10, [sp] */
/* @0xfdb50 mov r3, r7 */
/* @0xfdb54 str r9, [sp, #0x4] */
/* @0xfdb58 mov r1, #2 */
/* @0xfdb5c str r8, [sp, #0x8] */
/* @0xfdb60 str r6, [sp, #0xc] */
/* @0xfdb64 str r12, [sp, #0x10] */
/* @0xfdb68 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii> */
/* @0xfdb6c add sp, sp, #28 */
/* @0xfdb70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfdb74 ldr r0, [pc, #0x18] */
/* @0xfdb78 mov r1, #0 */
/* @0xfdb7c add r0, pc, r0 */
/* @0xfdb80 add sp, sp, #28 */
/* @0xfdb84 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfdb88 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfdb8c eoreq r0, pc, r12, ror r3 */
/* @0xfdb90 eoreq r0, pc, r12, ror #6 */
/* @0xfdb94 eoreq r10, r3, r0, lsl #1 */

/* ── FUNC 0xfdb98 · F_DsGridMultiplyGridRegion(RValue&, CInstance*, CInstance*, int, RValue*) · size=296 · insn=74 */
/* @0xfdb98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfdb9c sub sp, sp, #28 */
/* @0xfdba0 mov r1, #0 */
/* @0xfdba4 ldr r4, [sp, #0x40] */
/* @0xfdba8 mov r0, r4 */
/* @0xfdbac bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdbb0 mov r1, #1 */
/* @0xfdbb4 mov r5, r0 */
/* @0xfdbb8 mov r0, r4 */
/* @0xfdbbc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdbc0 mov r1, #2 */
/* @0xfdbc4 mov r11, r0 */
/* @0xfdbc8 mov r0, r4 */
/* @0xfdbcc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdbd0 mov r1, #3 */
/* @0xfdbd4 mov r7, r0 */
/* @0xfdbd8 mov r0, r4 */
/* @0xfdbdc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdbe0 mov r1, #4 */
/* @0xfdbe4 mov r10, r0 */
/* @0xfdbe8 mov r0, r4 */
/* @0xfdbec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdbf0 mov r1, #5 */
/* @0xfdbf4 mov r9, r0 */
/* @0xfdbf8 mov r0, r4 */
/* @0xfdbfc bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdc00 mov r1, #6 */
/* @0xfdc04 mov r8, r0 */
/* @0xfdc08 mov r0, r4 */
/* @0xfdc0c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdc10 mov r1, #7 */
/* @0xfdc14 mov r6, r0 */
/* @0xfdc18 mov r0, r4 */
/* @0xfdc1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdc20 cmp r5, #0 */
/* @0xfdc24 mov r12, r0 */
/* @0xfdc28 blt 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc2c ldr r2, [pc, #0x80] */
/* @0xfdc30 ldr r2, [pc, r2] */
/* @0xfdc34 ldr r3, [r2] */
/* @0xfdc38 cmp r5, r3 */
/* @0xfdc3c bge 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc40 ldr r2, [pc, #0x70] */
/* @0xfdc44 ldr r2, [pc, r2] */
/* @0xfdc48 ldr r2, [r2, #0x4] */
/* @0xfdc4c ldr r0, [r2, r5, lsl #2] */
/* @0xfdc50 cmp r0, #0 */
/* @0xfdc54 beq 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc58 cmp r11, #0 */
/* @0xfdc5c blt 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc60 cmp r11, r3 */
/* @0xfdc64 bge 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc68 ldr r2, [r2, r11, lsl #2] */
/* @0xfdc6c cmp r2, #0 */
/* @0xfdc70 beq 0xfdc9c <_Z26F_DsGridMultiplyGridRegionR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0xfdc74 str r10, [sp] */
/* @0xfdc78 mov r3, r7 */
/* @0xfdc7c str r9, [sp, #0x4] */
/* @0xfdc80 mov r1, #3 */
/* @0xfdc84 str r8, [sp, #0x8] */
/* @0xfdc88 str r6, [sp, #0xc] */
/* @0xfdc8c str r12, [sp, #0x10] */
/* @0xfdc90 bl 0x207fe8 <_ZN8CDS_Grid14Grid_OperationEiPS_iiiiii> */
/* @0xfdc94 add sp, sp, #28 */
/* @0xfdc98 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0xfdc9c ldr r0, [pc, #0x18] */
/* @0xfdca0 mov r1, #0 */
/* @0xfdca4 add r0, pc, r0 */
/* @0xfdca8 add sp, sp, #28 */
/* @0xfdcac pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0xfdcb0 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfdcb4 eoreq r0, pc, r4, asr r2 */
/* @0xfdcb8 eoreq r0, pc, r4, asr #4 */
/* @0xfdcbc eoreq r9, r3, r8, asr pc */

/* ── FUNC 0xfdcc0 · F_DsGridGetSum(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfdcc0 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfdcc4 sub sp, sp, #12 */
/* @0xfdcc8 mov r1, #0 */
/* @0xfdccc mov r8, r0 */
/* @0xfdcd0 ldr r4, [sp, #0x28] */
/* @0xfdcd4 mov r0, r4 */
/* @0xfdcd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdcdc mov r1, #1 */
/* @0xfdce0 mov r5, r0 */
/* @0xfdce4 mov r0, r4 */
/* @0xfdce8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdcec mov r1, #2 */
/* @0xfdcf0 mov r7, r0 */
/* @0xfdcf4 mov r0, r4 */
/* @0xfdcf8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdcfc mov r1, #3 */
/* @0xfdd00 mov r6, r0 */
/* @0xfdd04 mov r0, r4 */
/* @0xfdd08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdd0c mov r1, #4 */
/* @0xfdd10 mov r9, r0 */
/* @0xfdd14 mov r0, r4 */
/* @0xfdd18 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdd1c cmp r5, #0 */
/* @0xfdd20 mov r2, r0 */
/* @0xfdd24 blt 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdd28 ldr r12, [pc, #0x5c] */
/* @0xfdd2c ldr r12, [pc, r12] */
/* @0xfdd30 ldr r3, [r12] */
/* @0xfdd34 cmp r5, r3 */
/* @0xfdd38 bge 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdd3c ldr r12, [pc, #0x4c] */
/* @0xfdd40 ldr r12, [pc, r12] */
/* @0xfdd44 ldr r3, [r12, #0x4] */
/* @0xfdd48 ldr r0, [r3, r5, lsl #2] */
/* @0xfdd4c cmp r0, #0 */
/* @0xfdd50 beq 0xfdd74 <_Z14F_DsGridGetSumR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdd54 str r2, [sp, #0x4] */
/* @0xfdd58 mov r1, r8 */
/* @0xfdd5c str r9, [sp] */
/* @0xfdd60 mov r2, r7 */
/* @0xfdd64 mov r3, r6 */
/* @0xfdd68 bl 0x2041c8 <_ZN8CDS_Grid7Get_SumER6RValueiiii> */
/* @0xfdd6c add sp, sp, #12 */
/* @0xfdd70 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfdd74 ldr r0, [pc, #0x18] */
/* @0xfdd78 mov r1, #0 */
/* @0xfdd7c add r0, pc, r0 */
/* @0xfdd80 add sp, sp, #12 */
/* @0xfdd84 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfdd88 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfdd8c eoreq r0, pc, r8, asr r1 */
/* @0xfdd90 eoreq r0, pc, r8, asr #2 */
/* @0xfdd94 eoreq r9, r3, r0, lsl #29 */

/* ── FUNC 0xfdd98 · F_DsGridGetMax(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfdd98 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfdd9c sub sp, sp, #12 */
/* @0xfdda0 mov r1, #0 */
/* @0xfdda4 mov r8, r0 */
/* @0xfdda8 ldr r4, [sp, #0x28] */
/* @0xfddac mov r0, r4 */
/* @0xfddb0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfddb4 mov r1, #1 */
/* @0xfddb8 mov r5, r0 */
/* @0xfddbc mov r0, r4 */
/* @0xfddc0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfddc4 mov r1, #2 */
/* @0xfddc8 mov r7, r0 */
/* @0xfddcc mov r0, r4 */
/* @0xfddd0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfddd4 mov r1, #3 */
/* @0xfddd8 mov r6, r0 */
/* @0xfdddc mov r0, r4 */
/* @0xfdde0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdde4 mov r1, #4 */
/* @0xfdde8 mov r9, r0 */
/* @0xfddec mov r0, r4 */
/* @0xfddf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfddf4 cmp r5, #0 */
/* @0xfddf8 mov r2, r0 */
/* @0xfddfc blt 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfde00 ldr r12, [pc, #0x5c] */
/* @0xfde04 ldr r12, [pc, r12] */
/* @0xfde08 ldr r3, [r12] */
/* @0xfde0c cmp r5, r3 */
/* @0xfde10 bge 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfde14 ldr r12, [pc, #0x4c] */
/* @0xfde18 ldr r12, [pc, r12] */
/* @0xfde1c ldr r3, [r12, #0x4] */
/* @0xfde20 ldr r0, [r3, r5, lsl #2] */
/* @0xfde24 cmp r0, #0 */
/* @0xfde28 beq 0xfde4c <_Z14F_DsGridGetMaxR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfde2c str r2, [sp, #0x4] */
/* @0xfde30 mov r1, r8 */
/* @0xfde34 str r9, [sp] */
/* @0xfde38 mov r2, r7 */
/* @0xfde3c mov r3, r6 */
/* @0xfde40 bl 0x206924 <_ZN8CDS_Grid7Get_MaxER6RValueiiii> */
/* @0xfde44 add sp, sp, #12 */
/* @0xfde48 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfde4c ldr r0, [pc, #0x18] */
/* @0xfde50 mov r1, #0 */
/* @0xfde54 add r0, pc, r0 */
/* @0xfde58 add sp, sp, #12 */
/* @0xfde5c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfde60 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfde64 eoreq r0, pc, r0, lsl #1 */
/* @0xfde68 eoreq r0, pc, r0, ror r0 */
/* @0xfde6c eoreq r9, r3, r8, lsr #27 */

/* ── FUNC 0xfde70 · F_DsGridGetMin(RValue&, CInstance*, CInstance*, int, RValue*) · size=216 · insn=54 */
/* @0xfde70 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfde74 sub sp, sp, #12 */
/* @0xfde78 mov r1, #0 */
/* @0xfde7c mov r8, r0 */
/* @0xfde80 ldr r4, [sp, #0x28] */
/* @0xfde84 mov r0, r4 */
/* @0xfde88 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfde8c mov r1, #1 */
/* @0xfde90 mov r5, r0 */
/* @0xfde94 mov r0, r4 */
/* @0xfde98 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfde9c mov r1, #2 */
/* @0xfdea0 mov r7, r0 */
/* @0xfdea4 mov r0, r4 */
/* @0xfdea8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdeac mov r1, #3 */
/* @0xfdeb0 mov r6, r0 */
/* @0xfdeb4 mov r0, r4 */
/* @0xfdeb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdebc mov r1, #4 */
/* @0xfdec0 mov r9, r0 */
/* @0xfdec4 mov r0, r4 */
/* @0xfdec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0xfdecc cmp r5, #0 */
/* @0xfded0 mov r2, r0 */
/* @0xfded4 blt 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfded8 ldr r12, [pc, #0x5c] */
/* @0xfdedc ldr r12, [pc, r12] */
/* @0xfdee0 ldr r3, [r12] */
/* @0xfdee4 cmp r5, r3 */
/* @0xfdee8 bge 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdeec ldr r12, [pc, #0x4c] */
/* @0xfdef0 ldr r12, [pc, r12] */
/* @0xfdef4 ldr r3, [r12, #0x4] */
/* @0xfdef8 ldr r0, [r3, r5, lsl #2] */
/* @0xfdefc cmp r0, #0 */
/* @0xfdf00 beq 0xfdf24 <_Z14F_DsGridGetMinR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0xfdf04 str r2, [sp, #0x4] */
/* @0xfdf08 mov r1, r8 */
/* @0xfdf0c str r9, [sp] */
/* @0xfdf10 mov r2, r7 */
/* @0xfdf14 mov r3, r6 */
/* @0xfdf18 bl 0x206d14 <_ZN8CDS_Grid7Get_MinER6RValueiiii> */
/* @0xfdf1c add sp, sp, #12 */
/* @0xfdf20 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0xfdf24 ldr r0, [pc, #0x18] */
/* @0xfdf28 mov r1, #0 */
/* @0xfdf2c add r0, pc, r0 */
/* @0xfdf30 add sp, sp, #12 */
/* @0xfdf34 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0xfdf38 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0xfdf3c eoreq pc, lr, r8, lsr #31 */
/* @0xfdf40 mlaeq lr, r8, pc, pc */
/* @0xfdf44 .word 0x00239cd0 */
