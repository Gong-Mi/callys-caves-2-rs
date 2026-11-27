/* libyoyo.so 覆盖卡组 0187
 * 函数 0x20e968..0x210040，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x20e968 · CDS_List::ReadFromString(char const*, bool) · size=272 · insn=68 */
/* @0x20e968 push {r3, r4, r5, r6, r7, lr} */
/* @0x20e96c mov r6, r0 */
/* @0x20e970 mov r0, #32 */
/* @0x20e974 mov r7, r2 */
/* @0x20e978 mov r4, r1 */
/* @0x20e97c bl 0x27c524 <_Znwj> */
/* @0x20e980 mov r1, #0 */
/* @0x20e984 mov r5, r0 */
/* @0x20e988 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20e98c mov r0, r5 */
/* @0x20e990 mov r1, r4 */
/* @0x20e994 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x20e998 mov r0, r5 */
/* @0x20e99c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20e9a0 sub r3, r0, #300 */
/* @0x20e9a4 sub r3, r3, #1 */
/* @0x20e9a8 cmp r3, #1 */
/* @0x20e9ac bls 0x20e9cc <_ZN8CDS_List14ReadFromStringEPKcb+0x64> */
/* @0x20e9b0 subs r0, r5, #0 */
/* @0x20e9b4 beq 0x20ea5c <_ZN8CDS_List14ReadFromStringEPKcb+0xf4> */
/* @0x20e9b8 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20e9bc mov r0, r5 */
/* @0x20e9c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20e9c4 mov r0, #0 */
/* @0x20e9c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20e9cc cmp r7, #0 */
/* @0x20e9d0 movne r7, #1 */
/* @0x20e9d4 beq 0x20ea60 <_ZN8CDS_List14ReadFromStringEPKcb+0xf8> */
/* @0x20e9d8 mov r0, r6 */
/* @0x20e9dc bl 0x20e478 <_ZN8CDS_List5ClearEv> */
/* @0x20e9e0 mov r0, r5 */
/* @0x20e9e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20e9e8 ldr r2, [pc, #0x84] */
/* @0x20e9ec movw r3, #0x48f */
/* @0x20e9f0 add r2, pc, r2 */
/* @0x20e9f4 lsl r1, r0, #4 */
/* @0x20e9f8 str r0, [r6, #0x4] */
/* @0x20e9fc add r0, r6, #12 */
/* @0x20ea00 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20ea04 ldr r3, [r6, #0x4] */
/* @0x20ea08 cmp r3, #0 */
/* @0x20ea0c str r3, [r6, #0x8] */
/* @0x20ea10 movgt r4, #0 */
/* @0x20ea14 ble 0x20ea3c <_ZN8CDS_List14ReadFromStringEPKcb+0xd4> */
/* @0x20ea18 ldr r0, [r6, #0xc] */
/* @0x20ea1c mov r1, r5 */
/* @0x20ea20 mov r2, r7 */
/* @0x20ea24 add r0, r0, r4, lsl #4 */
/* @0x20ea28 add r4, r4, #1 */
/* @0x20ea2c bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20ea30 ldr r3, [r6, #0x4] */
/* @0x20ea34 cmp r3, r4 */
/* @0x20ea38 bgt 0x20ea18 <_ZN8CDS_List14ReadFromStringEPKcb+0xb0> */
/* @0x20ea3c cmp r5, #0 */
/* @0x20ea40 beq 0x20ea54 <_ZN8CDS_List14ReadFromStringEPKcb+0xec> */
/* @0x20ea44 mov r0, r5 */
/* @0x20ea48 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20ea4c mov r0, r5 */
/* @0x20ea50 bl 0x27d1d0 <_ZdlPv> */
/* @0x20ea54 mov r0, #1 */
/* @0x20ea58 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20ea5c pop {r3, r4, r5, r6, r7, pc} */
/* @0x20ea60 movw r7, #0x12d */
/* @0x20ea64 cmp r0, r7 */
/* @0x20ea68 moveq r7, #2 */
/* @0x20ea6c movne r7, #0 */
/* @0x20ea70 b 0x20e9d8 <_ZN8CDS_List14ReadFromStringEPKcb+0x70> */
/* @0x20ea74 ldrsheq r4, [r4], -r12 */

/* ── FUNC 0x20ea78 · CDS_List::~CDS_List() · size=56 · insn=14 */
/* @0x20ea78 ldr r3, [pc, #0x2c] */
/* @0x20ea7c push {r4, lr} */
/* @0x20ea80 ldr r3, [pc, r3] */
/* @0x20ea84 mov r4, r0 */
/* @0x20ea88 add r3, r3, #8 */
/* @0x20ea8c str r3, [r0] */
/* @0x20ea90 bl 0x20e478 <_ZN8CDS_List5ClearEv> */
/* @0x20ea94 ldr r0, [r4, #0xc] */
/* @0x20ea98 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20ea9c mov r3, #0 */
/* @0x20eaa0 mov r0, r4 */
/* @0x20eaa4 str r3, [r4, #0xc] */
/* @0x20eaa8 pop {r4, pc} */
/* @0x20eaac andseq r2, lr, r4, lsl r9 */

/* ── FUNC 0x20ea78 · CDS_List::~CDS_List() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20eab0 · CDS_List::~CDS_List() · size=28 · insn=7 */
/* @0x20eab0 push {r4, lr} */
/* @0x20eab4 mov r4, r0 */
/* @0x20eab8 bl 0x20ea78 <_ZN8CDS_ListD2Ev> */
/* @0x20eabc mov r0, r4 */
/* @0x20eac0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20eac4 mov r0, r4 */
/* @0x20eac8 pop {r4, pc} */

/* ── FUNC 0x20eacc · CDS_Queue::Clear() · size=652 · insn=163 */
/* @0x20eacc ldr r3, [r0, #0xc] */
/* @0x20ead0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20ead4 mov r6, #0 */
/* @0x20ead8 cmp r3, r6 */
/* @0x20eadc sub sp, sp, #20 */
/* @0x20eae0 mov r11, r0 */
/* @0x20eae4 str r6, [r0, #0x4] */
/* @0x20eae8 str r6, [r0, #0x8] */
/* @0x20eaec movgt r10, #5 */
/* @0x20eaf0 movgt r5, r6 */
/* @0x20eaf4 bgt 0x20eb18 <_ZN9CDS_Queue5ClearEv+0x4c> */
/* @0x20eaf8 b 0x20eb84 <_ZN9CDS_Queue5ClearEv+0xb8> */
/* @0x20eafc str r5, [r7, #0x8] */
/* @0x20eb00 add r6, r6, #1 */
/* @0x20eb04 str r10, [r7, #0xc] */
/* @0x20eb08 str r5, [r9, r8] */
/* @0x20eb0c ldr r3, [r11, #0xc] */
/* @0x20eb10 cmp r3, r6 */
/* @0x20eb14 ble 0x20eb84 <_ZN9CDS_Queue5ClearEv+0xb8> */
/* @0x20eb18 ldr r9, [r11, #0x10] */
/* @0x20eb1c lsl r8, r6, #4 */
/* @0x20eb20 add r7, r9, r8 */
/* @0x20eb24 ldr r12, [r7, #0xc] */
/* @0x20eb28 sub r0, r12, #1 */
/* @0x20eb2c bic r0, r0, #-16777216 */
/* @0x20eb30 bics r4, r0, #3 */
/* @0x20eb34 bne 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20eb38 bic r12, r12, #-16777216 */
/* @0x20eb3c cmp r12, #2 */
/* @0x20eb40 beq 0x20ebbc <_ZN9CDS_Queue5ClearEv+0xf0> */
/* @0x20eb44 cmp r12, #3 */
/* @0x20eb48 beq 0x20eb94 <_ZN9CDS_Queue5ClearEv+0xc8> */
/* @0x20eb4c cmp r12, #1 */
/* @0x20eb50 bne 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20eb54 ldr r4, [r9, r8] */
/* @0x20eb58 cmp r4, #0 */
/* @0x20eb5c beq 0x20eb7c <_ZN9CDS_Queue5ClearEv+0xb0> */
/* @0x20eb60 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20eb64 ldr r3, [r4, #0x4] */
/* @0x20eb68 sub r3, r3, #1 */
/* @0x20eb6c str r3, [r4, #0x4] */
/* @0x20eb70 cmp r3, #0 */
/* @0x20eb74 beq 0x20ebfc <_ZN9CDS_Queue5ClearEv+0x130> */
/* @0x20eb78 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20eb7c str r5, [r9, r8] */
/* @0x20eb80 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20eb84 mov r3, #0 */
/* @0x20eb88 str r3, [r11, #0xc] */
/* @0x20eb8c add sp, sp, #20 */
/* @0x20eb90 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20eb94 ldr r0, [r7, #0x8] */
/* @0x20eb98 tst r0, #8 */
/* @0x20eb9c beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20eba0 ldr r0, [r9, r8] */
/* @0x20eba4 cmp r0, #0 */
/* @0x20eba8 beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20ebac ldr r12, [r0] */
/* @0x20ebb0 ldr r12, [r12, #0x4] */
/* @0x20ebb4 blx r12 */
/* @0x20ebb8 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20ebbc ldr r3, [r9, r8] */
/* @0x20ebc0 cmp r3, #0 */
/* @0x20ebc4 str r3, [sp, #0x8] */
/* @0x20ebc8 beq 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20ebcc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20ebd0 ldr r3, [sp, #0x8] */
/* @0x20ebd4 ldr r0, [r3] */
/* @0x20ebd8 ldr r12, [r3, #0x8] */
/* @0x20ebdc sub r0, r0, #1 */
/* @0x20ebe0 str r0, [r3] */
/* @0x20ebe4 cmp r7, r12 */
/* @0x20ebe8 streq r4, [r3, #0x8] */
/* @0x20ebec cmp r0, #0 */
/* @0x20ebf0 ble 0x20ec3c <_ZN9CDS_Queue5ClearEv+0x170> */
/* @0x20ebf4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ebf8 b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20ebfc ldr r0, [r4] */
/* @0x20ec00 str r3, [sp] */
/* @0x20ec04 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20ec08 ldr r3, [sp] */
/* @0x20ec0c str r3, [r4] */
/* @0x20ec10 str r3, [r4, #0x8] */
/* @0x20ec14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20ec18 ldr r3, [r4, #0x4] */
/* @0x20ec1c sub r3, r3, #1 */
/* @0x20ec20 str r3, [r4, #0x4] */
/* @0x20ec24 cmp r3, #0 */
/* @0x20ec28 beq 0x20ecc8 <_ZN9CDS_Queue5ClearEv+0x1fc> */
/* @0x20ec2c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ec30 mov r0, r4 */
/* @0x20ec34 bl 0x27d1d0 <_ZdlPv> */
/* @0x20ec38 b 0x20eb78 <_ZN9CDS_Queue5ClearEv+0xac> */
/* @0x20ec3c ldr r3, [sp, #0x8] */
/* @0x20ec40 ldr r0, [r3, #0x10] */
/* @0x20ec44 cmp r0, #0 */
/* @0x20ec48 movgt r3, #0 */
/* @0x20ec4c strgt r3, [sp, #0x4] */
/* @0x20ec50 ble 0x20ed28 <_ZN9CDS_Queue5ClearEv+0x25c> */
/* @0x20ec54 ldr r3, [sp, #0x8] */
/* @0x20ec58 ldr r0, [r3, #0x4] */
/* @0x20ec5c ldr r3, [sp, #0x4] */
/* @0x20ec60 add r3, r0, r3, lsl #3 */
/* @0x20ec64 str r3, [sp, #0xc] */
/* @0x20ec68 ldr r3, [sp, #0x4] */
/* @0x20ec6c ldr r12, [r0, r3, lsl #3] */
/* @0x20ec70 ldr r3, [sp, #0xc] */
/* @0x20ec74 ldr r4, [r3, #0x4] */
/* @0x20ec78 add r12, r4, r12, lsl #4 */
/* @0x20ec7c cmp r4, r12 */
/* @0x20ec80 blo 0x20ec9c <_ZN9CDS_Queue5ClearEv+0x1d0> */
/* @0x20ec84 b 0x20ed50 <_ZN9CDS_Queue5ClearEv+0x284> */
/* @0x20ec88 str r5, [r4, #0x8] */
/* @0x20ec8c str r10, [r4, #0xc] */
/* @0x20ec90 str r5, [r4], #16 */
/* @0x20ec94 cmp r12, r4 */
/* @0x20ec98 bls 0x20ecf4 <_ZN9CDS_Queue5ClearEv+0x228> */
/* @0x20ec9c ldr r0, [r4, #0xc] */
/* @0x20eca0 sub r0, r0, #1 */
/* @0x20eca4 bic r0, r0, #-16777216 */
/* @0x20eca8 bic r0, r0, #3 */
/* @0x20ecac cmp r0, #0 */
/* @0x20ecb0 bne 0x20ec88 <_ZN9CDS_Queue5ClearEv+0x1bc> */
/* @0x20ecb4 mov r0, r4 */
/* @0x20ecb8 str r12, [sp] */
/* @0x20ecbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20ecc0 ldr r12, [sp] */
/* @0x20ecc4 b 0x20ec88 <_ZN9CDS_Queue5ClearEv+0x1bc> */
/* @0x20ecc8 ldr r0, [r4] */
/* @0x20eccc str r3, [sp] */
/* @0x20ecd0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20ecd4 ldr r3, [sp] */
/* @0x20ecd8 mov r0, r4 */
/* @0x20ecdc str r3, [r4] */
/* @0x20ece0 str r3, [r4, #0x8] */
/* @0x20ece4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20ece8 mov r0, r4 */
/* @0x20ecec bl 0x27d1d0 <_ZdlPv> */
/* @0x20ecf0 b 0x20ec2c <_ZN9CDS_Queue5ClearEv+0x160> */
/* @0x20ecf4 ldr r3, [sp, #0xc] */
/* @0x20ecf8 ldr r0, [r3, #0x4] */
/* @0x20ecfc ldr r3, [sp, #0x4] */
/* @0x20ed00 add r3, r3, #1 */
/* @0x20ed04 str r3, [sp, #0x4] */
/* @0x20ed08 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20ed0c ldr r3, [sp, #0x8] */
/* @0x20ed10 ldr r0, [r3, #0x10] */
/* @0x20ed14 ldr r3, [sp, #0xc] */
/* @0x20ed18 str r5, [r3, #0x4] */
/* @0x20ed1c ldr r3, [sp, #0x4] */
/* @0x20ed20 cmp r3, r0 */
/* @0x20ed24 blt 0x20ec54 <_ZN9CDS_Queue5ClearEv+0x188> */
/* @0x20ed28 ldr r3, [sp, #0x8] */
/* @0x20ed2c ldr r0, [r3, #0x4] */
/* @0x20ed30 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20ed34 ldr r3, [sp, #0x8] */
/* @0x20ed38 str r5, [r3, #0x4] */
/* @0x20ed3c mov r0, r3 */
/* @0x20ed40 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20ed44 str r5, [r9, r8] */
/* @0x20ed48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ed4c b 0x20eafc <_ZN9CDS_Queue5ClearEv+0x30> */
/* @0x20ed50 mov r0, r4 */
/* @0x20ed54 b 0x20ecfc <_ZN9CDS_Queue5ClearEv+0x230> */

/* ── FUNC 0x20ed58 · CDS_Queue::CDS_Queue() · size=84 · insn=21 */
/* @0x20ed58 ldr r2, [pc, #0x48] */
/* @0x20ed5c mov r3, #0 */
/* @0x20ed60 push {r4, lr} */
/* @0x20ed64 ldr r2, [pc, r2] */
/* @0x20ed68 mov r4, r0 */
/* @0x20ed6c str r3, [r0, #0x4] */
/* @0x20ed70 str r3, [r0, #0x8] */
/* @0x20ed74 add r2, r2, #8 */
/* @0x20ed78 strb r3, [r0, #0xc] */
/* @0x20ed7c str r2, [r0] */
/* @0x20ed80 strb r3, [r0, #0xd] */
/* @0x20ed84 strb r3, [r0, #0xe] */
/* @0x20ed88 strb r3, [r0, #0xf] */
/* @0x20ed8c strb r3, [r0, #0x10] */
/* @0x20ed90 strb r3, [r0, #0x11] */
/* @0x20ed94 strb r3, [r0, #0x12] */
/* @0x20ed98 strb r3, [r0, #0x13] */
/* @0x20ed9c bl 0x20eacc <_ZN9CDS_Queue5ClearEv> */
/* @0x20eda0 mov r0, r4 */
/* @0x20eda4 pop {r4, pc} */
/* @0x20eda8 andseq r2, lr, r0, asr #12 */

/* ── FUNC 0x20ed58 · CDS_Queue::CDS_Queue() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20edac · CDS_Queue::Assign(CDS_Queue*) · size=856 · insn=214 */
/* @0x20edac push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20edb0 subs r11, r1, #0 */
/* @0x20edb4 sub sp, sp, #20 */
/* @0x20edb8 str r0, [sp, #0xc] */
/* @0x20edbc beq 0x20f0f4 <_ZN9CDS_Queue6AssignEPS_+0x348> */
/* @0x20edc0 ldr r12, [sp, #0xc] */
/* @0x20edc4 mov r3, #768 */
/* @0x20edc8 ldr r2, [r11, #0x8] */
/* @0x20edcc ldr r1, [r11, #0xc] */
/* @0x20edd0 add r0, r12, #16 */
/* @0x20edd4 ldr lr, [r11, #0x4] */
/* @0x20edd8 str r2, [r12, #0x8] */
/* @0x20eddc ldr r2, [pc, #0x31c] */
/* @0x20ede0 lsl r1, r1, #4 */
/* @0x20ede4 str lr, [r12, #0x4] */
/* @0x20ede8 add r2, pc, r2 */
/* @0x20edec bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20edf0 ldr r3, [r11, #0xc] */
/* @0x20edf4 ldr r12, [sp, #0xc] */
/* @0x20edf8 str r3, [r12, #0xc] */
/* @0x20edfc ldr r3, [r11, #0xc] */
/* @0x20ee00 cmp r3, #1 */
/* @0x20ee04 ble 0x20eee0 <_ZN9CDS_Queue6AssignEPS_+0x134> */
/* @0x20ee08 mov r7, #0 */
/* @0x20ee0c mov r9, r7 */
/* @0x20ee10 ldr r12, [sp, #0xc] */
/* @0x20ee14 lsl r4, r7, #4 */
/* @0x20ee18 ldr r10, [r11, #0x10] */
/* @0x20ee1c ldr r6, [r12, #0x10] */
/* @0x20ee20 add r8, r10, r4 */
/* @0x20ee24 add r5, r6, r4 */
/* @0x20ee28 ldr r1, [r5, #0xc] */
/* @0x20ee2c bic r2, r1, #-16777216 */
/* @0x20ee30 cmp r2, #1 */
/* @0x20ee34 beq 0x20ef64 <_ZN9CDS_Queue6AssignEPS_+0x1b8> */
/* @0x20ee38 cmp r2, #2 */
/* @0x20ee3c bne 0x20ee60 <_ZN9CDS_Queue6AssignEPS_+0xb4> */
/* @0x20ee40 sub r1, r1, #1 */
/* @0x20ee44 bic r1, r1, #-16777216 */
/* @0x20ee48 bic r1, r1, #3 */
/* @0x20ee4c cmp r1, #0 */
/* @0x20ee50 beq 0x20eff4 <_ZN9CDS_Queue6AssignEPS_+0x248> */
/* @0x20ee54 mov r2, #5 */
/* @0x20ee58 str r9, [r5, #0x8] */
/* @0x20ee5c str r2, [r5, #0xc] */
/* @0x20ee60 ldr r2, [r8, #0xc] */
/* @0x20ee64 ldr r1, [r8, #0x8] */
/* @0x20ee68 str r9, [r6, r4] */
/* @0x20ee6c str r2, [r5, #0xc] */
/* @0x20ee70 ldr r2, [r8, #0xc] */
/* @0x20ee74 str r1, [r5, #0x8] */
/* @0x20ee78 bic r2, r2, #-16777216 */
/* @0x20ee7c cmp r2, #14 */
/* @0x20ee80 addls pc, pc, r2, lsl #2 */
/* @0x20ee84 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ee88 b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c> */
/* @0x20ee8c b 0x20ef4c <_ZN9CDS_Queue6AssignEPS_+0x1a0> */
/* @0x20ee90 b 0x20ef20 <_ZN9CDS_Queue6AssignEPS_+0x174> */
/* @0x20ee94 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118> */
/* @0x20ee98 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ee9c b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eea0 b 0x20eefc <_ZN9CDS_Queue6AssignEPS_+0x150> */
/* @0x20eea4 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118> */
/* @0x20eea8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eeac b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eeb0 b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c> */
/* @0x20eeb4 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eeb8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eebc b 0x20eee8 <_ZN9CDS_Queue6AssignEPS_+0x13c> */
/* @0x20eec0 b 0x20eec4 <_ZN9CDS_Queue6AssignEPS_+0x118> */
/* @0x20eec4 ldr r3, [r10, r4] */
/* @0x20eec8 str r3, [r6, r4] */
/* @0x20eecc ldr r3, [r11, #0xc] */
/* @0x20eed0 add r7, r7, #1 */
/* @0x20eed4 sub r3, r3, #1 */
/* @0x20eed8 cmp r3, r7 */
/* @0x20eedc bgt 0x20ee10 <_ZN9CDS_Queue6AssignEPS_+0x64> */
/* @0x20eee0 add sp, sp, #20 */
/* @0x20eee4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20eee8 ldr r2, [r10, r4] */
/* @0x20eeec ldr r3, [r8, #0x4] */
/* @0x20eef0 str r2, [r6, r4] */
/* @0x20eef4 str r3, [r5, #0x4] */
/* @0x20eef8 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20eefc ldr r2, [r10, r4] */
/* @0x20ef00 str r2, [r6, r4] */
/* @0x20ef04 ldr r2, [r10, r4] */
/* @0x20ef08 cmp r2, #0 */
/* @0x20ef0c beq 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ef10 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20ef14 ldr r1, [r10, r4] */
/* @0x20ef18 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20ef1c b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ef20 ldr r3, [r10, r4] */
/* @0x20ef24 cmp r3, #0 */
/* @0x20ef28 str r3, [r6, r4] */
/* @0x20ef2c beq 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ef30 ldr r1, [r3, #0x8] */
/* @0x20ef34 ldr r2, [r3] */
/* @0x20ef38 cmp r1, #0 */
/* @0x20ef3c streq r5, [r3, #0x8] */
/* @0x20ef40 add r2, r2, #1 */
/* @0x20ef44 str r2, [r3] */
/* @0x20ef48 b 0x20eecc <_ZN9CDS_Queue6AssignEPS_+0x120> */
/* @0x20ef4c ldr r3, [r10, r4] */
/* @0x20ef50 cmp r3, #0 */
/* @0x20ef54 ldrne r2, [r3, #0x4] */
/* @0x20ef58 addne r2, r2, #1 */
/* @0x20ef5c strne r2, [r3, #0x4] */
/* @0x20ef60 b 0x20eec8 <_ZN9CDS_Queue6AssignEPS_+0x11c> */
/* @0x20ef64 ldr r2, [r6, r7, lsl #4] */
/* @0x20ef68 cmp r2, #0 */
/* @0x20ef6c beq 0x20ef94 <_ZN9CDS_Queue6AssignEPS_+0x1e8> */
/* @0x20ef70 str r2, [sp, #0x4] */
/* @0x20ef74 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20ef78 ldr r2, [sp, #0x4] */
/* @0x20ef7c ldr r1, [r2, #0x4] */
/* @0x20ef80 sub r1, r1, #1 */
/* @0x20ef84 str r1, [r2, #0x4] */
/* @0x20ef88 cmp r1, #0 */
/* @0x20ef8c beq 0x20ef9c <_ZN9CDS_Queue6AssignEPS_+0x1f0> */
/* @0x20ef90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20ef94 str r9, [r6, r4] */
/* @0x20ef98 b 0x20ee60 <_ZN9CDS_Queue6AssignEPS_+0xb4> */
/* @0x20ef9c ldr r0, [r2] */
/* @0x20efa0 str r1, [sp, #0x8] */
/* @0x20efa4 str r2, [sp, #0x4] */
/* @0x20efa8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20efac ldr r2, [sp, #0x4] */
/* @0x20efb0 ldr r1, [sp, #0x8] */
/* @0x20efb4 str r1, [r2] */
/* @0x20efb8 str r1, [r2, #0x8] */
/* @0x20efbc str r2, [sp, #0x4] */
/* @0x20efc0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20efc4 ldr r2, [sp, #0x4] */
/* @0x20efc8 ldr r1, [r2, #0x4] */
/* @0x20efcc sub r1, r1, #1 */
/* @0x20efd0 str r1, [r2, #0x4] */
/* @0x20efd4 cmp r1, #0 */
/* @0x20efd8 beq 0x20f000 <_ZN9CDS_Queue6AssignEPS_+0x254> */
/* @0x20efdc str r2, [sp, #0x4] */
/* @0x20efe0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20efe4 ldr r2, [sp, #0x4] */
/* @0x20efe8 mov r0, r2 */
/* @0x20efec bl 0x27d1d0 <_ZdlPv> */
/* @0x20eff0 b 0x20ef90 <_ZN9CDS_Queue6AssignEPS_+0x1e4> */
/* @0x20eff4 mov r0, r5 */
/* @0x20eff8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20effc b 0x20ee54 <_ZN9CDS_Queue6AssignEPS_+0xa8> */
/* @0x20f000 ldr r0, [r2] */
/* @0x20f004 str r1, [sp, #0x8] */
/* @0x20f008 str r2, [sp, #0x4] */
/* @0x20f00c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f010 ldr r2, [sp, #0x4] */
/* @0x20f014 ldr r1, [sp, #0x8] */
/* @0x20f018 str r1, [r2] */
/* @0x20f01c str r1, [r2, #0x8] */
/* @0x20f020 str r2, [sp, #0x4] */
/* @0x20f024 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f028 ldr r2, [sp, #0x4] */
/* @0x20f02c ldr r1, [r2, #0x4] */
/* @0x20f030 sub r1, r1, #1 */
/* @0x20f034 str r1, [r2, #0x4] */
/* @0x20f038 cmp r1, #0 */
/* @0x20f03c beq 0x20f05c <_ZN9CDS_Queue6AssignEPS_+0x2b0> */
/* @0x20f040 str r2, [sp, #0x4] */
/* @0x20f044 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f048 ldr r2, [sp, #0x4] */
/* @0x20f04c mov r0, r2 */
/* @0x20f050 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f054 ldr r2, [sp, #0x4] */
/* @0x20f058 b 0x20efdc <_ZN9CDS_Queue6AssignEPS_+0x230> */
/* @0x20f05c ldr r0, [r2] */
/* @0x20f060 str r1, [sp, #0x8] */
/* @0x20f064 str r2, [sp, #0x4] */
/* @0x20f068 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f06c ldr r2, [sp, #0x4] */
/* @0x20f070 ldr r1, [sp, #0x8] */
/* @0x20f074 str r1, [r2] */
/* @0x20f078 str r1, [r2, #0x8] */
/* @0x20f07c str r2, [sp, #0x4] */
/* @0x20f080 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f084 ldr r2, [sp, #0x4] */
/* @0x20f088 ldr r1, [r2, #0x4] */
/* @0x20f08c sub r1, r1, #1 */
/* @0x20f090 str r1, [r2, #0x4] */
/* @0x20f094 cmp r1, #0 */
/* @0x20f098 bne 0x20f0d8 <_ZN9CDS_Queue6AssignEPS_+0x32c> */
/* @0x20f09c ldr r0, [r2] */
/* @0x20f0a0 str r1, [sp, #0x8] */
/* @0x20f0a4 str r2, [sp, #0x4] */
/* @0x20f0a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f0ac ldr r2, [sp, #0x4] */
/* @0x20f0b0 ldr r1, [sp, #0x8] */
/* @0x20f0b4 mov r0, r2 */
/* @0x20f0b8 str r1, [r2] */
/* @0x20f0bc str r1, [r2, #0x8] */
/* @0x20f0c0 str r2, [sp, #0x4] */
/* @0x20f0c4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20f0c8 ldr r2, [sp, #0x4] */
/* @0x20f0cc mov r0, r2 */
/* @0x20f0d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f0d4 ldr r2, [sp, #0x4] */
/* @0x20f0d8 str r2, [sp, #0x4] */
/* @0x20f0dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f0e0 ldr r2, [sp, #0x4] */
/* @0x20f0e4 mov r0, r2 */
/* @0x20f0e8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f0ec ldr r2, [sp, #0x4] */
/* @0x20f0f0 b 0x20f040 <_ZN9CDS_Queue6AssignEPS_+0x294> */
/* @0x20f0f4 add sp, sp, #20 */
/* @0x20f0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20f0fc b 0x20eacc <_ZN9CDS_Queue5ClearEv> */
/* @0x20f100 andseq r4, r4, r4, lsl #20 */

/* ── FUNC 0x20f104 · CDS_Queue::ReadFromString(char const*, bool) · size=280 · insn=70 */
/* @0x20f104 push {r4, r5, r6, r7, r8, lr} */
/* @0x20f108 mov r6, r0 */
/* @0x20f10c mov r0, #32 */
/* @0x20f110 mov r7, r2 */
/* @0x20f114 mov r4, r1 */
/* @0x20f118 bl 0x27c524 <_Znwj> */
/* @0x20f11c mov r1, #0 */
/* @0x20f120 mov r5, r0 */
/* @0x20f124 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20f128 mov r0, r5 */
/* @0x20f12c mov r1, r4 */
/* @0x20f130 bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x20f134 mov r0, r5 */
/* @0x20f138 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f13c sub r3, r0, #201 */
/* @0x20f140 cmp r3, #1 */
/* @0x20f144 bls 0x20f164 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x60> */
/* @0x20f148 subs r0, r5, #0 */
/* @0x20f14c beq 0x20f204 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x100> */
/* @0x20f150 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20f154 mov r0, r5 */
/* @0x20f158 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f15c mov r0, #0 */
/* @0x20f160 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20f164 cmp r7, #0 */
/* @0x20f168 movne r8, #1 */
/* @0x20f16c beq 0x20f208 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x104> */
/* @0x20f170 mov r0, r6 */
/* @0x20f174 bl 0x20eacc <_ZN9CDS_Queue5ClearEv> */
/* @0x20f178 mov r0, r5 */
/* @0x20f17c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f180 str r0, [r6, #0x4] */
/* @0x20f184 mov r0, r5 */
/* @0x20f188 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f18c str r0, [r6, #0x8] */
/* @0x20f190 mov r0, r5 */
/* @0x20f194 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f198 ldr r2, [pc, #0x78] */
/* @0x20f19c movw r3, #0x35d */
/* @0x20f1a0 add r2, pc, r2 */
/* @0x20f1a4 mov r7, r0 */
/* @0x20f1a8 lsl r1, r0, #4 */
/* @0x20f1ac add r0, r6, #16 */
/* @0x20f1b0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20f1b4 cmp r7, #0 */
/* @0x20f1b8 str r7, [r6, #0xc] */
/* @0x20f1bc movgt r4, #0 */
/* @0x20f1c0 ble 0x20f1e4 <_ZN9CDS_Queue14ReadFromStringEPKcb+0xe0> */
/* @0x20f1c4 ldr r0, [r6, #0x10] */
/* @0x20f1c8 mov r1, r5 */
/* @0x20f1cc mov r2, r8 */
/* @0x20f1d0 add r0, r0, r4, lsl #4 */
/* @0x20f1d4 add r4, r4, #1 */
/* @0x20f1d8 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20f1dc cmp r4, r7 */
/* @0x20f1e0 bne 0x20f1c4 <_ZN9CDS_Queue14ReadFromStringEPKcb+0xc0> */
/* @0x20f1e4 cmp r5, #0 */
/* @0x20f1e8 beq 0x20f1fc <_ZN9CDS_Queue14ReadFromStringEPKcb+0xf8> */
/* @0x20f1ec mov r0, r5 */
/* @0x20f1f0 bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20f1f4 mov r0, r5 */
/* @0x20f1f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f1fc mov r0, #1 */
/* @0x20f200 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20f204 pop {r4, r5, r6, r7, r8, pc} */
/* @0x20f208 cmp r0, #201 */
/* @0x20f20c moveq r8, #2 */
/* @0x20f210 movne r8, #0 */
/* @0x20f214 b 0x20f170 <_ZN9CDS_Queue14ReadFromStringEPKcb+0x6c> */
/* @0x20f218 andseq r4, r4, r12, asr #12 */

/* ── FUNC 0x20f21c · CDS_Queue::~CDS_Queue() · size=56 · insn=14 */
/* @0x20f21c ldr r3, [pc, #0x2c] */
/* @0x20f220 push {r4, lr} */
/* @0x20f224 ldr r3, [pc, r3] */
/* @0x20f228 mov r4, r0 */
/* @0x20f22c add r3, r3, #8 */
/* @0x20f230 str r3, [r0] */
/* @0x20f234 bl 0x20eacc <_ZN9CDS_Queue5ClearEv> */
/* @0x20f238 ldr r0, [r4, #0x10] */
/* @0x20f23c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20f240 mov r3, #0 */
/* @0x20f244 mov r0, r4 */
/* @0x20f248 str r3, [r4, #0x10] */
/* @0x20f24c pop {r4, pc} */
/* @0x20f250 andseq r2, lr, r0, lsl #3 */

/* ── FUNC 0x20f21c · CDS_Queue::~CDS_Queue() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20f254 · CDS_Queue::~CDS_Queue() · size=28 · insn=7 */
/* @0x20f254 push {r4, lr} */
/* @0x20f258 mov r4, r0 */
/* @0x20f25c bl 0x20f21c <_ZN9CDS_QueueD2Ev> */
/* @0x20f260 mov r0, r4 */
/* @0x20f264 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f268 mov r0, r4 */
/* @0x20f26c pop {r4, pc} */

/* ── FUNC 0x20f270 · CDS_Stack::Clear() · size=620 · insn=155 */
/* @0x20f270 ldr r3, [r0, #0x4] */
/* @0x20f274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20f278 cmp r3, #0 */
/* @0x20f27c mov r8, r0 */
/* @0x20f280 sub sp, sp, #12 */
/* @0x20f284 movgt r7, #0 */
/* @0x20f288 ldr r0, [r0, #0xc] */
/* @0x20f28c movgt r5, r7 */
/* @0x20f290 movgt r11, #5 */
/* @0x20f294 bgt 0x20f2b8 <_ZN9CDS_Stack5ClearEv+0x48> */
/* @0x20f298 b 0x20f320 <_ZN9CDS_Stack5ClearEv+0xb0> */
/* @0x20f29c str r5, [r6] */
/* @0x20f2a0 add r7, r7, #1 */
/* @0x20f2a4 ldr r3, [r8, #0x4] */
/* @0x20f2a8 str r5, [r6, #0x8] */
/* @0x20f2ac cmp r3, r7 */
/* @0x20f2b0 str r11, [r6, #0xc] */
/* @0x20f2b4 ble 0x20f320 <_ZN9CDS_Stack5ClearEv+0xb0> */
/* @0x20f2b8 add r6, r0, r7, lsl #4 */
/* @0x20f2bc ldr r1, [r6, #0xc] */
/* @0x20f2c0 sub r3, r1, #1 */
/* @0x20f2c4 bic r3, r3, #-16777216 */
/* @0x20f2c8 bics r4, r3, #3 */
/* @0x20f2cc bne 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f2d0 bic r1, r1, #-16777216 */
/* @0x20f2d4 cmp r1, #2 */
/* @0x20f2d8 beq 0x20f36c <_ZN9CDS_Stack5ClearEv+0xfc> */
/* @0x20f2dc cmp r1, #3 */
/* @0x20f2e0 beq 0x20f33c <_ZN9CDS_Stack5ClearEv+0xcc> */
/* @0x20f2e4 cmp r1, #1 */
/* @0x20f2e8 bne 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f2ec ldr r4, [r6] */
/* @0x20f2f0 cmp r4, #0 */
/* @0x20f2f4 beq 0x20f318 <_ZN9CDS_Stack5ClearEv+0xa8> */
/* @0x20f2f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f2fc ldr r9, [r4, #0x4] */
/* @0x20f300 sub r9, r9, #1 */
/* @0x20f304 str r9, [r4, #0x4] */
/* @0x20f308 cmp r9, #0 */
/* @0x20f30c beq 0x20f3a8 <_ZN9CDS_Stack5ClearEv+0x138> */
/* @0x20f310 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f314 ldr r0, [r8, #0xc] */
/* @0x20f318 str r5, [r6] */
/* @0x20f31c b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f320 mov r4, #0 */
/* @0x20f324 str r4, [r8, #0x4] */
/* @0x20f328 str r4, [r8, #0x8] */
/* @0x20f32c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x20f330 str r4, [r8, #0xc] */
/* @0x20f334 add sp, sp, #12 */
/* @0x20f338 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20f33c ldr r3, [r6, #0x8] */
/* @0x20f340 tst r3, #8 */
/* @0x20f344 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f348 ldr r3, [r6] */
/* @0x20f34c cmp r3, #0 */
/* @0x20f350 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f354 ldr r1, [r3] */
/* @0x20f358 mov r0, r3 */
/* @0x20f35c ldr r3, [r1, #0x4] */
/* @0x20f360 blx r3 */
/* @0x20f364 ldr r0, [r8, #0xc] */
/* @0x20f368 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f36c ldr r10, [r6] */
/* @0x20f370 cmp r10, #0 */
/* @0x20f374 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f378 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f37c ldr r3, [r10] */
/* @0x20f380 ldr r1, [r10, #0x8] */
/* @0x20f384 sub r3, r3, #1 */
/* @0x20f388 str r3, [r10] */
/* @0x20f38c cmp r6, r1 */
/* @0x20f390 streq r4, [r10, #0x8] */
/* @0x20f394 cmp r3, #0 */
/* @0x20f398 ble 0x20f3e0 <_ZN9CDS_Stack5ClearEv+0x170> */
/* @0x20f39c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f3a0 ldr r0, [r8, #0xc] */
/* @0x20f3a4 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f3a8 ldr r0, [r4] */
/* @0x20f3ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f3b0 str r9, [r4] */
/* @0x20f3b4 str r9, [r4, #0x8] */
/* @0x20f3b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f3bc ldr r9, [r4, #0x4] */
/* @0x20f3c0 sub r9, r9, #1 */
/* @0x20f3c4 str r9, [r4, #0x4] */
/* @0x20f3c8 cmp r9, #0 */
/* @0x20f3cc beq 0x20f45c <_ZN9CDS_Stack5ClearEv+0x1ec> */
/* @0x20f3d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f3d4 mov r0, r4 */
/* @0x20f3d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f3dc b 0x20f310 <_ZN9CDS_Stack5ClearEv+0xa0> */
/* @0x20f3e0 ldr r3, [r10, #0x10] */
/* @0x20f3e4 cmp r3, #0 */
/* @0x20f3e8 movgt r2, #0 */
/* @0x20f3ec strgt r2, [sp] */
/* @0x20f3f0 ble 0x20f4b0 <_ZN9CDS_Stack5ClearEv+0x240> */
/* @0x20f3f4 ldr r2, [sp] */
/* @0x20f3f8 ldr r3, [r10, #0x4] */
/* @0x20f3fc add r2, r3, r2, lsl #3 */
/* @0x20f400 str r2, [sp, #0x4] */
/* @0x20f404 ldr r2, [sp] */
/* @0x20f408 ldr r1, [r3, r2, lsl #3] */
/* @0x20f40c ldr r3, [sp, #0x4] */
/* @0x20f410 ldr r4, [r3, #0x4] */
/* @0x20f414 add r9, r4, r1, lsl #4 */
/* @0x20f418 cmp r4, r9 */
/* @0x20f41c blo 0x20f438 <_ZN9CDS_Stack5ClearEv+0x1c8> */
/* @0x20f420 b 0x20f4d4 <_ZN9CDS_Stack5ClearEv+0x264> */
/* @0x20f424 str r5, [r4, #0x8] */
/* @0x20f428 str r11, [r4, #0xc] */
/* @0x20f42c str r5, [r4], #16 */
/* @0x20f430 cmp r9, r4 */
/* @0x20f434 bls 0x20f480 <_ZN9CDS_Stack5ClearEv+0x210> */
/* @0x20f438 ldr r3, [r4, #0xc] */
/* @0x20f43c sub r3, r3, #1 */
/* @0x20f440 bic r3, r3, #-16777216 */
/* @0x20f444 bic r3, r3, #3 */
/* @0x20f448 cmp r3, #0 */
/* @0x20f44c bne 0x20f424 <_ZN9CDS_Stack5ClearEv+0x1b4> */
/* @0x20f450 mov r0, r4 */
/* @0x20f454 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20f458 b 0x20f424 <_ZN9CDS_Stack5ClearEv+0x1b4> */
/* @0x20f45c ldr r0, [r4] */
/* @0x20f460 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f464 mov r0, r4 */
/* @0x20f468 str r9, [r4] */
/* @0x20f46c str r9, [r4, #0x8] */
/* @0x20f470 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20f474 mov r0, r4 */
/* @0x20f478 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f47c b 0x20f3d0 <_ZN9CDS_Stack5ClearEv+0x160> */
/* @0x20f480 ldr r2, [sp, #0x4] */
/* @0x20f484 ldr r0, [r2, #0x4] */
/* @0x20f488 ldr r3, [sp] */
/* @0x20f48c add r3, r3, #1 */
/* @0x20f490 str r3, [sp] */
/* @0x20f494 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20f498 ldr r2, [sp, #0x4] */
/* @0x20f49c ldr r3, [r10, #0x10] */
/* @0x20f4a0 str r5, [r2, #0x4] */
/* @0x20f4a4 ldr r2, [sp] */
/* @0x20f4a8 cmp r2, r3 */
/* @0x20f4ac blt 0x20f3f4 <_ZN9CDS_Stack5ClearEv+0x184> */
/* @0x20f4b0 ldr r0, [r10, #0x4] */
/* @0x20f4b4 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20f4b8 mov r0, r10 */
/* @0x20f4bc str r5, [r10, #0x4] */
/* @0x20f4c0 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x20f4c4 str r5, [r6] */
/* @0x20f4c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f4cc ldr r0, [r8, #0xc] */
/* @0x20f4d0 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c> */
/* @0x20f4d4 mov r0, r4 */
/* @0x20f4d8 b 0x20f488 <_ZN9CDS_Stack5ClearEv+0x218> */

/* ── FUNC 0x20f4dc · CDS_Stack::CDS_Stack() · size=56 · insn=14 */
/* @0x20f4dc ldr r2, [pc, #0x2c] */
/* @0x20f4e0 mov r3, #0 */
/* @0x20f4e4 push {r4, lr} */
/* @0x20f4e8 ldr r2, [pc, r2] */
/* @0x20f4ec mov r4, r0 */
/* @0x20f4f0 str r3, [r0, #0x4] */
/* @0x20f4f4 str r3, [r0, #0x8] */
/* @0x20f4f8 add r2, r2, #8 */
/* @0x20f4fc str r3, [r0, #0xc] */
/* @0x20f500 str r2, [r0] */
/* @0x20f504 bl 0x20f270 <_ZN9CDS_Stack5ClearEv> */
/* @0x20f508 mov r0, r4 */
/* @0x20f50c pop {r4, pc} */
/* @0x20f510 andseq r1, lr, r0, asr #29 */

/* ── FUNC 0x20f4dc · CDS_Stack::CDS_Stack() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20f514 · CDS_Stack::Assign(CDS_Stack*) · size=844 · insn=211 */
/* @0x20f514 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20f518 subs r11, r1, #0 */
/* @0x20f51c sub sp, sp, #20 */
/* @0x20f520 str r0, [sp, #0xc] */
/* @0x20f524 beq 0x20f850 <_ZN9CDS_Stack6AssignEPS_+0x33c> */
/* @0x20f528 ldr r12, [sp, #0xc] */
/* @0x20f52c movw r3, #0x1e2 */
/* @0x20f530 ldr r1, [r11, #0x8] */
/* @0x20f534 ldr lr, [r11, #0x4] */
/* @0x20f538 add r0, r12, #12 */
/* @0x20f53c ldr r2, [pc, #0x318] */
/* @0x20f540 lsl r1, r1, #4 */
/* @0x20f544 str lr, [r12, #0x4] */
/* @0x20f548 add r2, pc, r2 */
/* @0x20f54c bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20f550 ldr r3, [r11, #0x8] */
/* @0x20f554 ldr r12, [sp, #0xc] */
/* @0x20f558 str r3, [r12, #0x8] */
/* @0x20f55c ldr r3, [r11, #0x8] */
/* @0x20f560 cmp r3, #0 */
/* @0x20f564 ble 0x20f63c <_ZN9CDS_Stack6AssignEPS_+0x128> */
/* @0x20f568 mov r7, #0 */
/* @0x20f56c mov r9, r7 */
/* @0x20f570 ldr r12, [sp, #0xc] */
/* @0x20f574 lsl r4, r7, #4 */
/* @0x20f578 ldr r10, [r11, #0xc] */
/* @0x20f57c ldr r6, [r12, #0xc] */
/* @0x20f580 add r8, r10, r4 */
/* @0x20f584 add r5, r6, r4 */
/* @0x20f588 ldr r1, [r5, #0xc] */
/* @0x20f58c bic r2, r1, #-16777216 */
/* @0x20f590 cmp r2, #1 */
/* @0x20f594 beq 0x20f6c0 <_ZN9CDS_Stack6AssignEPS_+0x1ac> */
/* @0x20f598 cmp r2, #2 */
/* @0x20f59c bne 0x20f5c0 <_ZN9CDS_Stack6AssignEPS_+0xac> */
/* @0x20f5a0 sub r1, r1, #1 */
/* @0x20f5a4 bic r1, r1, #-16777216 */
/* @0x20f5a8 bic r1, r1, #3 */
/* @0x20f5ac cmp r1, #0 */
/* @0x20f5b0 beq 0x20f750 <_ZN9CDS_Stack6AssignEPS_+0x23c> */
/* @0x20f5b4 mov r2, #5 */
/* @0x20f5b8 str r9, [r5, #0x8] */
/* @0x20f5bc str r2, [r5, #0xc] */
/* @0x20f5c0 ldr r2, [r8, #0xc] */
/* @0x20f5c4 ldr r1, [r8, #0x8] */
/* @0x20f5c8 str r9, [r6, r4] */
/* @0x20f5cc str r2, [r5, #0xc] */
/* @0x20f5d0 ldr r2, [r8, #0xc] */
/* @0x20f5d4 str r1, [r5, #0x8] */
/* @0x20f5d8 bic r2, r2, #-16777216 */
/* @0x20f5dc cmp r2, #14 */
/* @0x20f5e0 addls pc, pc, r2, lsl #2 */
/* @0x20f5e4 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f5e8 b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130> */
/* @0x20f5ec b 0x20f6a8 <_ZN9CDS_Stack6AssignEPS_+0x194> */
/* @0x20f5f0 b 0x20f67c <_ZN9CDS_Stack6AssignEPS_+0x168> */
/* @0x20f5f4 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110> */
/* @0x20f5f8 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f5fc b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f600 b 0x20f658 <_ZN9CDS_Stack6AssignEPS_+0x144> */
/* @0x20f604 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110> */
/* @0x20f608 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f60c b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f610 b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130> */
/* @0x20f614 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f618 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f61c b 0x20f644 <_ZN9CDS_Stack6AssignEPS_+0x130> */
/* @0x20f620 b 0x20f624 <_ZN9CDS_Stack6AssignEPS_+0x110> */
/* @0x20f624 ldr r3, [r10, r4] */
/* @0x20f628 str r3, [r6, r4] */
/* @0x20f62c ldr r3, [r11, #0x8] */
/* @0x20f630 add r7, r7, #1 */
/* @0x20f634 cmp r3, r7 */
/* @0x20f638 bgt 0x20f570 <_ZN9CDS_Stack6AssignEPS_+0x5c> */
/* @0x20f63c add sp, sp, #20 */
/* @0x20f640 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x20f644 ldr r2, [r10, r4] */
/* @0x20f648 ldr r3, [r8, #0x4] */
/* @0x20f64c str r2, [r6, r4] */
/* @0x20f650 str r3, [r5, #0x4] */
/* @0x20f654 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f658 ldr r2, [r10, r4] */
/* @0x20f65c str r2, [r6, r4] */
/* @0x20f660 ldr r2, [r10, r4] */
/* @0x20f664 cmp r2, #0 */
/* @0x20f668 beq 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f66c bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x20f670 ldr r1, [r10, r4] */
/* @0x20f674 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x20f678 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f67c ldr r3, [r10, r4] */
/* @0x20f680 cmp r3, #0 */
/* @0x20f684 str r3, [r6, r4] */
/* @0x20f688 beq 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f68c ldr r1, [r3, #0x8] */
/* @0x20f690 ldr r2, [r3] */
/* @0x20f694 cmp r1, #0 */
/* @0x20f698 streq r5, [r3, #0x8] */
/* @0x20f69c add r2, r2, #1 */
/* @0x20f6a0 str r2, [r3] */
/* @0x20f6a4 b 0x20f62c <_ZN9CDS_Stack6AssignEPS_+0x118> */
/* @0x20f6a8 ldr r3, [r10, r4] */
/* @0x20f6ac cmp r3, #0 */
/* @0x20f6b0 ldrne r2, [r3, #0x4] */
/* @0x20f6b4 addne r2, r2, #1 */
/* @0x20f6b8 strne r2, [r3, #0x4] */
/* @0x20f6bc b 0x20f628 <_ZN9CDS_Stack6AssignEPS_+0x114> */
/* @0x20f6c0 ldr r2, [r6, r7, lsl #4] */
/* @0x20f6c4 cmp r2, #0 */
/* @0x20f6c8 beq 0x20f6f0 <_ZN9CDS_Stack6AssignEPS_+0x1dc> */
/* @0x20f6cc str r2, [sp, #0x4] */
/* @0x20f6d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f6d4 ldr r2, [sp, #0x4] */
/* @0x20f6d8 ldr r1, [r2, #0x4] */
/* @0x20f6dc sub r1, r1, #1 */
/* @0x20f6e0 str r1, [r2, #0x4] */
/* @0x20f6e4 cmp r1, #0 */
/* @0x20f6e8 beq 0x20f6f8 <_ZN9CDS_Stack6AssignEPS_+0x1e4> */
/* @0x20f6ec bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f6f0 str r9, [r6, r4] */
/* @0x20f6f4 b 0x20f5c0 <_ZN9CDS_Stack6AssignEPS_+0xac> */
/* @0x20f6f8 ldr r0, [r2] */
/* @0x20f6fc str r1, [sp, #0x8] */
/* @0x20f700 str r2, [sp, #0x4] */
/* @0x20f704 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f708 ldr r2, [sp, #0x4] */
/* @0x20f70c ldr r1, [sp, #0x8] */
/* @0x20f710 str r1, [r2] */
/* @0x20f714 str r1, [r2, #0x8] */
/* @0x20f718 str r2, [sp, #0x4] */
/* @0x20f71c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f720 ldr r2, [sp, #0x4] */
/* @0x20f724 ldr r1, [r2, #0x4] */
/* @0x20f728 sub r1, r1, #1 */
/* @0x20f72c str r1, [r2, #0x4] */
/* @0x20f730 cmp r1, #0 */
/* @0x20f734 beq 0x20f75c <_ZN9CDS_Stack6AssignEPS_+0x248> */
/* @0x20f738 str r2, [sp, #0x4] */
/* @0x20f73c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f740 ldr r2, [sp, #0x4] */
/* @0x20f744 mov r0, r2 */
/* @0x20f748 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f74c b 0x20f6ec <_ZN9CDS_Stack6AssignEPS_+0x1d8> */
/* @0x20f750 mov r0, r5 */
/* @0x20f754 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x20f758 b 0x20f5b4 <_ZN9CDS_Stack6AssignEPS_+0xa0> */
/* @0x20f75c ldr r0, [r2] */
/* @0x20f760 str r1, [sp, #0x8] */
/* @0x20f764 str r2, [sp, #0x4] */
/* @0x20f768 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f76c ldr r2, [sp, #0x4] */
/* @0x20f770 ldr r1, [sp, #0x8] */
/* @0x20f774 str r1, [r2] */
/* @0x20f778 str r1, [r2, #0x8] */
/* @0x20f77c str r2, [sp, #0x4] */
/* @0x20f780 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f784 ldr r2, [sp, #0x4] */
/* @0x20f788 ldr r1, [r2, #0x4] */
/* @0x20f78c sub r1, r1, #1 */
/* @0x20f790 str r1, [r2, #0x4] */
/* @0x20f794 cmp r1, #0 */
/* @0x20f798 beq 0x20f7b8 <_ZN9CDS_Stack6AssignEPS_+0x2a4> */
/* @0x20f79c str r2, [sp, #0x4] */
/* @0x20f7a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f7a4 ldr r2, [sp, #0x4] */
/* @0x20f7a8 mov r0, r2 */
/* @0x20f7ac bl 0x27d1d0 <_ZdlPv> */
/* @0x20f7b0 ldr r2, [sp, #0x4] */
/* @0x20f7b4 b 0x20f738 <_ZN9CDS_Stack6AssignEPS_+0x224> */
/* @0x20f7b8 ldr r0, [r2] */
/* @0x20f7bc str r1, [sp, #0x8] */
/* @0x20f7c0 str r2, [sp, #0x4] */
/* @0x20f7c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f7c8 ldr r2, [sp, #0x4] */
/* @0x20f7cc ldr r1, [sp, #0x8] */
/* @0x20f7d0 str r1, [r2] */
/* @0x20f7d4 str r1, [r2, #0x8] */
/* @0x20f7d8 str r2, [sp, #0x4] */
/* @0x20f7dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x20f7e0 ldr r2, [sp, #0x4] */
/* @0x20f7e4 ldr r1, [r2, #0x4] */
/* @0x20f7e8 sub r1, r1, #1 */
/* @0x20f7ec str r1, [r2, #0x4] */
/* @0x20f7f0 cmp r1, #0 */
/* @0x20f7f4 bne 0x20f834 <_ZN9CDS_Stack6AssignEPS_+0x320> */
/* @0x20f7f8 ldr r0, [r2] */
/* @0x20f7fc str r1, [sp, #0x8] */
/* @0x20f800 str r2, [sp, #0x4] */
/* @0x20f804 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x20f808 ldr r2, [sp, #0x4] */
/* @0x20f80c ldr r1, [sp, #0x8] */
/* @0x20f810 mov r0, r2 */
/* @0x20f814 str r1, [r2] */
/* @0x20f818 str r1, [r2, #0x8] */
/* @0x20f81c str r2, [sp, #0x4] */
/* @0x20f820 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x20f824 ldr r2, [sp, #0x4] */
/* @0x20f828 mov r0, r2 */
/* @0x20f82c bl 0x27d1d0 <_ZdlPv> */
/* @0x20f830 ldr r2, [sp, #0x4] */
/* @0x20f834 str r2, [sp, #0x4] */
/* @0x20f838 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x20f83c ldr r2, [sp, #0x4] */
/* @0x20f840 mov r0, r2 */
/* @0x20f844 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f848 ldr r2, [sp, #0x4] */
/* @0x20f84c b 0x20f79c <_ZN9CDS_Stack6AssignEPS_+0x288> */
/* @0x20f850 add sp, sp, #20 */
/* @0x20f854 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x20f858 b 0x20f270 <_ZN9CDS_Stack5ClearEv> */
/* @0x20f85c andseq r4, r4, r4, lsr #5 */

/* ── FUNC 0x20f860 · CDS_Stack::ReadFromString(char const*, bool) · size=264 · insn=66 */
/* @0x20f860 push {r3, r4, r5, r6, r7, lr} */
/* @0x20f864 mov r6, r0 */
/* @0x20f868 mov r0, #32 */
/* @0x20f86c mov r7, r2 */
/* @0x20f870 mov r4, r1 */
/* @0x20f874 bl 0x27c524 <_Znwj> */
/* @0x20f878 mov r1, #0 */
/* @0x20f87c mov r5, r0 */
/* @0x20f880 bl 0x2010ec <_ZN7CStreamC2Ei> */
/* @0x20f884 mov r0, r5 */
/* @0x20f888 mov r1, r4 */
/* @0x20f88c bl 0x2025b0 <_ZN7CStream17ConvertFromStringEPKc> */
/* @0x20f890 mov r0, r5 */
/* @0x20f894 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f898 sub r3, r0, #101 */
/* @0x20f89c cmp r3, #1 */
/* @0x20f8a0 bls 0x20f8c0 <_ZN9CDS_Stack14ReadFromStringEPKcb+0x60> */
/* @0x20f8a4 subs r0, r5, #0 */
/* @0x20f8a8 beq 0x20f950 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xf0> */
/* @0x20f8ac bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20f8b0 mov r0, r5 */
/* @0x20f8b4 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f8b8 mov r0, #0 */
/* @0x20f8bc pop {r3, r4, r5, r6, r7, pc} */
/* @0x20f8c0 cmp r7, #0 */
/* @0x20f8c4 movne r7, #1 */
/* @0x20f8c8 beq 0x20f954 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xf4> */
/* @0x20f8cc mov r0, r6 */
/* @0x20f8d0 bl 0x20f270 <_ZN9CDS_Stack5ClearEv> */
/* @0x20f8d4 mov r0, r5 */
/* @0x20f8d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x20f8dc ldr r2, [pc, #0x80] */
/* @0x20f8e0 movw r3, #0x22d */
/* @0x20f8e4 add r2, pc, r2 */
/* @0x20f8e8 lsl r1, r0, #4 */
/* @0x20f8ec str r0, [r6, #0x4] */
/* @0x20f8f0 add r0, r6, #12 */
/* @0x20f8f4 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x20f8f8 ldr r3, [r6, #0x4] */
/* @0x20f8fc cmp r3, #0 */
/* @0x20f900 str r3, [r6, #0x8] */
/* @0x20f904 movgt r4, #0 */
/* @0x20f908 ble 0x20f930 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xd0> */
/* @0x20f90c ldr r0, [r6, #0xc] */
/* @0x20f910 mov r1, r5 */
/* @0x20f914 mov r2, r7 */
/* @0x20f918 add r0, r0, r4, lsl #4 */
/* @0x20f91c add r4, r4, #1 */
/* @0x20f920 bl 0x208638 <_Z9ReadValueR6RValueR7CStreami> */
/* @0x20f924 ldr r3, [r6, #0x4] */
/* @0x20f928 cmp r3, r4 */
/* @0x20f92c bgt 0x20f90c <_ZN9CDS_Stack14ReadFromStringEPKcb+0xac> */
/* @0x20f930 cmp r5, #0 */
/* @0x20f934 beq 0x20f948 <_ZN9CDS_Stack14ReadFromStringEPKcb+0xe8> */
/* @0x20f938 mov r0, r5 */
/* @0x20f93c bl 0x201328 <_ZN7CStreamD2Ev> */
/* @0x20f940 mov r0, r5 */
/* @0x20f944 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f948 mov r0, #1 */
/* @0x20f94c pop {r3, r4, r5, r6, r7, pc} */
/* @0x20f950 pop {r3, r4, r5, r6, r7, pc} */
/* @0x20f954 cmp r0, #101 */
/* @0x20f958 moveq r7, #2 */
/* @0x20f95c movne r7, #0 */
/* @0x20f960 b 0x20f8cc <_ZN9CDS_Stack14ReadFromStringEPKcb+0x6c> */
/* @0x20f964 andseq r3, r4, r8, lsl #30 */

/* ── FUNC 0x20f968 · CDS_Stack::~CDS_Stack() · size=40 · insn=10 */
/* @0x20f968 ldr r3, [pc, #0x1c] */
/* @0x20f96c push {r4, lr} */
/* @0x20f970 ldr r3, [pc, r3] */
/* @0x20f974 mov r4, r0 */
/* @0x20f978 add r3, r3, #8 */
/* @0x20f97c str r3, [r0] */
/* @0x20f980 bl 0x20f270 <_ZN9CDS_Stack5ClearEv> */
/* @0x20f984 mov r0, r4 */
/* @0x20f988 pop {r4, pc} */
/* @0x20f98c andseq r1, lr, r8, lsr r10 */

/* ── FUNC 0x20f968 · CDS_Stack::~CDS_Stack() · alias of the symbol above · insn=0 */

/* ── FUNC 0x20f990 · CDS_Stack::~CDS_Stack() · size=28 · insn=7 */
/* @0x20f990 push {r4, lr} */
/* @0x20f994 mov r4, r0 */
/* @0x20f998 bl 0x20f968 <_ZN9CDS_StackD2Ev> */
/* @0x20f99c mov r0, r4 */
/* @0x20f9a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x20f9a4 mov r0, r4 */
/* @0x20f9a8 pop {r4, pc} */

/* ── FUNC 0x20f9ac · Color_RGB(int, int, int) · size=44 · insn=11 */
/* @0x20f9ac uxtb r2, r2 */
/* @0x20f9b0 uxtb r1, r1 */
/* @0x20f9b4 mov r3, #0 */
/* @0x20f9b8 bfi r3, r2, #0, #8 */
/* @0x20f9bc uxtb r0, r0 */
/* @0x20f9c0 bfi r3, r1, #8, #8 */
/* @0x20f9c4 bfi r3, r0, #16, #8 */
/* @0x20f9c8 sub sp, sp, #8 */
/* @0x20f9cc mov r0, r3 */
/* @0x20f9d0 add sp, sp, #8 */
/* @0x20f9d4 bx lr */

/* ── FUNC 0x20f9d8 · Color_HSV(int, int, int) · size=40 · insn=10 */
/* @0x20f9d8 uxtb r3, r0 */
/* @0x20f9dc uxtb r1, r1 */
/* @0x20f9e0 mov r0, #0 */
/* @0x20f9e4 bfi r0, r3, #0, #8 */
/* @0x20f9e8 uxtb r2, r2 */
/* @0x20f9ec bfi r0, r1, #8, #8 */
/* @0x20f9f0 bfi r0, r2, #16, #8 */
/* @0x20f9f4 sub sp, sp, #8 */
/* @0x20f9f8 add sp, sp, #8 */
/* @0x20f9fc bx lr */

/* ── FUNC 0x20fa00 · Color_ColorToRGB(unsigned int&) · size=44 · insn=11 */
/* @0x20fa00 ldr r3, [r0] */
/* @0x20fa04 mov r0, #0 */
/* @0x20fa08 sub sp, sp, #8 */
/* @0x20fa0c ubfx r1, r3, #0x10, #0x8 */
/* @0x20fa10 ubfx r2, r3, #0x8, #0x8 */
/* @0x20fa14 bfi r0, r1, #0, #8 */
/* @0x20fa18 uxtb r3, r3 */
/* @0x20fa1c bfi r0, r2, #8, #8 */
/* @0x20fa20 bfi r0, r3, #16, #8 */
/* @0x20fa24 add sp, sp, #8 */
/* @0x20fa28 bx lr */

/* ── FUNC 0x20fa2c · Color_RGBToColor(TRGB&) · size=28 · insn=7 */
/* @0x20fa2c ldrb r1, [r0, #0x1] */
/* @0x20fa30 ldrb r2, [r0] */
/* @0x20fa34 ldrb r3, [r0, #0x2] */
/* @0x20fa38 lsl r0, r1, #8 */
/* @0x20fa3c add r0, r0, r2, lsl #16 */
/* @0x20fa40 add r0, r0, r3 */
/* @0x20fa44 bx lr */

/* ── FUNC 0x20fa48 · Color_RGBtoHSV(TRGB) · size=608 · insn=152 */
/* @0x20fa48 ubfx r3, r0, #0x10, #0x8 */
/* @0x20fa4c vldr s13, [pc, #576] */
/* @0x20fa50 sub sp, sp, #16 */
/* @0x20fa54 vmov s14, r3 */
/* @0x20fa58 ubfx r3, r0, #0x8, #0x8 */
/* @0x20fa5c uxtb r0, r0 */
/* @0x20fa60 vmov s15, r3 */
/* @0x20fa64 vcvt.f32.s32 s14, s14 */
/* @0x20fa68 vmov s11, r0 */
/* @0x20fa6c vcvt.f32.s32 s15, s15 */
/* @0x20fa70 vdiv.f32 s14, s14, s13 */
/* @0x20fa74 vdiv.f32 s15, s15, s13 */
/* @0x20fa78 vcvt.f32.s32 s12, s11 */
/* @0x20fa7c vcmpe.f32 s14, s15 */
/* @0x20fa80 vdiv.f32 s12, s12, s13 */
/* @0x20fa84 vmrs APSR_nzcv, fpscr */
/* @0x20fa88 bpl 0x20fb38 <_Z14Color_RGBtoHSV4TRGB+0xf0> */
/* @0x20fa8c vcmpe.f32 s14, s12 */
/* @0x20fa90 vmrs APSR_nzcv, fpscr */
/* @0x20fa94 bpl 0x20fb80 <_Z14Color_RGBtoHSV4TRGB+0x138> */
/* @0x20fa98 vmov.f32 s11, s14 */
/* @0x20fa9c vcmpe.f32 s14, s15 */
/* @0x20faa0 vmrs APSR_nzcv, fpscr */
/* @0x20faa4 ble 0x20fb5c <_Z14Color_RGBtoHSV4TRGB+0x114> */
/* @0x20faa8 vcmpe.f32 s14, s12 */
/* @0x20faac vmrs APSR_nzcv, fpscr */
/* @0x20fab0 ble 0x20fb88 <_Z14Color_RGBtoHSV4TRGB+0x140> */
/* @0x20fab4 vmov.f32 s13, s14 */
/* @0x20fab8 vcmp.f32 s13, #0 */
/* @0x20fabc vmrs APSR_nzcv, fpscr */
/* @0x20fac0 beq 0x20fb98 <_Z14Color_RGBtoHSV4TRGB+0x150> */
/* @0x20fac4 vsub.f32 s11, s13, s11 */
/* @0x20fac8 vdiv.f32 s10, s11, s13 */
/* @0x20facc vcmp.f32 s10, #0 */
/* @0x20fad0 vmrs APSR_nzcv, fpscr */
/* @0x20fad4 beq 0x20fc7c <_Z14Color_RGBtoHSV4TRGB+0x234> */
/* @0x20fad8 vcmp.f32 s13, s14 */
/* @0x20fadc vmrs APSR_nzcv, fpscr */
/* @0x20fae0 bne 0x20fbfc <_Z14Color_RGBtoHSV4TRGB+0x1b4> */
/* @0x20fae4 vsub.f32 s15, s15, s12 */
/* @0x20fae8 vldr s9, [pc, #424] */
/* @0x20faec vmul.f32 s15, s15, s9 */
/* @0x20faf0 vdiv.f32 s11, s15, s11 */
/* @0x20faf4 vcmpe.f32 s11, #0 */
/* @0x20faf8 vmrs APSR_nzcv, fpscr */
/* @0x20fafc bpl 0x20fc2c <_Z14Color_RGBtoHSV4TRGB+0x1e4> */
/* @0x20fb00 vldr s9, [pc, #404] */
/* @0x20fb04 vadd.f32 s11, s11, s9 */
/* @0x20fb08 vldr s14, [pc, #388] */
/* @0x20fb0c vmul.f32 s15, s11, s14 */
/* @0x20fb10 vdiv.f32 s9, s15, s9 */
/* @0x20fb14 vmov.f32 s15, #5.000000e-01 */
/* @0x20fb18 vmov.f32 s11, s15 */
/* @0x20fb1c vmla.f32 s11, s10, s14 */
/* @0x20fb20 vadd.f32 s15, s9, s15 */
/* @0x20fb24 vcvt.s32.f32 s14, s11 */
/* @0x20fb28 vcvt.s32.f32 s15, s15 */
/* @0x20fb2c vmov r2, s14 */
/* @0x20fb30 vmov r3, s15 */
/* @0x20fb34 b 0x20fba0 <_Z14Color_RGBtoHSV4TRGB+0x158> */
/* @0x20fb38 vcmpe.f32 s15, s12 */
/* @0x20fb3c vmrs APSR_nzcv, fpscr */
/* @0x20fb40 bpl 0x20fb80 <_Z14Color_RGBtoHSV4TRGB+0x138> */
/* @0x20fb44 vcmpe.f32 s14, s15 */
/* @0x20fb48 vmrs APSR_nzcv, fpscr */
/* @0x20fb4c vmovpl.f32 s11, s15 */
/* @0x20fb50 bpl 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54> */
/* @0x20fb54 vmov.f32 s11, s14 */
/* @0x20fb58 b 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54> */
/* @0x20fb5c vcmpe.f32 s15, s12 */
/* @0x20fb60 vmrs APSR_nzcv, fpscr */
/* @0x20fb64 ble 0x20fb88 <_Z14Color_RGBtoHSV4TRGB+0x140> */
/* @0x20fb68 vcmpe.f32 s14, s15 */
/* @0x20fb6c vmrs APSR_nzcv, fpscr */
/* @0x20fb70 vmovle.f32 s13, s15 */
/* @0x20fb74 ble 0x20fab8 <_Z14Color_RGBtoHSV4TRGB+0x70> */
/* @0x20fb78 vmov.f32 s13, s14 */
/* @0x20fb7c b 0x20fab8 <_Z14Color_RGBtoHSV4TRGB+0x70> */
/* @0x20fb80 vmov.f32 s11, s12 */
/* @0x20fb84 b 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54> */
/* @0x20fb88 vmov.f32 s13, s12 */
/* @0x20fb8c vcmp.f32 s13, #0 */
/* @0x20fb90 vmrs APSR_nzcv, fpscr */
/* @0x20fb94 bne 0x20fac4 <_Z14Color_RGBtoHSV4TRGB+0x7c> */
/* @0x20fb98 mov r2, #0 */
/* @0x20fb9c mov r3, #0 */
/* @0x20fba0 vmov.f32 s15, #5.000000e-01 */
/* @0x20fba4 vldr s14, [pc, #232] */
/* @0x20fba8 mov r0, #0 */
/* @0x20fbac vmla.f32 s15, s13, s14 */
/* @0x20fbb0 vcvt.s32.f32 s15, s15 */
/* @0x20fbb4 vmov r1, s15 */
/* @0x20fbb8 cmp r1, #254 */
/* @0x20fbbc bicle r1, r1, r1, asr #31 */
/* @0x20fbc0 movgt r1, #255 */
/* @0x20fbc4 uxtble r1, r1 */
/* @0x20fbc8 cmp r2, #254 */
/* @0x20fbcc bicle r2, r2, r2, asr #31 */
/* @0x20fbd0 movgt r2, #255 */
/* @0x20fbd4 uxtble r2, r2 */
/* @0x20fbd8 cmp r3, #254 */
/* @0x20fbdc bicle r3, r3, r3, asr #31 */
/* @0x20fbe0 movgt r3, #255 */
/* @0x20fbe4 uxtble r3, r3 */
/* @0x20fbe8 bfi r0, r3, #0, #8 */
/* @0x20fbec bfi r0, r2, #8, #8 */
/* @0x20fbf0 bfi r0, r1, #16, #8 */
/* @0x20fbf4 add sp, sp, #16 */
/* @0x20fbf8 bx lr */
/* @0x20fbfc vcmp.f32 s13, s15 */
/* @0x20fc00 vmrs APSR_nzcv, fpscr */
/* @0x20fc04 bne 0x20fc60 <_Z14Color_RGBtoHSV4TRGB+0x218> */
/* @0x20fc08 vsub.f32 s14, s12, s14 */
/* @0x20fc0c vldr s8, [pc, #132] */
/* @0x20fc10 vldr s9, [pc, #136] */
/* @0x20fc14 vmul.f32 s14, s14, s8 */
/* @0x20fc18 vdiv.f32 s11, s14, s11 */
/* @0x20fc1c vadd.f32 s11, s11, s9 */
/* @0x20fc20 vcmpe.f32 s11, #0 */
/* @0x20fc24 vmrs APSR_nzcv, fpscr */
/* @0x20fc28 bmi 0x20fb00 <_Z14Color_RGBtoHSV4TRGB+0xb8> */
/* @0x20fc2c vldr s14, [pc, #96] */
/* @0x20fc30 vmul.f32 s11, s11, s14 */
/* @0x20fc34 vldr s15, [pc, #96] */
/* @0x20fc38 vdiv.f32 s11, s11, s15 */
/* @0x20fc3c vmov.f32 s15, #5.000000e-01 */
/* @0x20fc40 vmov.f32 s12, s15 */
/* @0x20fc44 vmla.f32 s12, s10, s14 */
/* @0x20fc48 vadd.f32 s15, s11, s15 */
/* @0x20fc4c vcvt.s32.f32 s14, s12 */
/* @0x20fc50 vcvt.s32.f32 s15, s15 */
/* @0x20fc54 vmov r2, s14 */
/* @0x20fc58 vmov r3, s15 */
/* @0x20fc5c b 0x20fba0 <_Z14Color_RGBtoHSV4TRGB+0x158> */
/* @0x20fc60 vsub.f32 s15, s14, s15 */
/* @0x20fc64 vldr s9, [pc, #44] */
/* @0x20fc68 vldr s12, [pc, #52] */
/* @0x20fc6c vmul.f32 s15, s15, s9 */
/* @0x20fc70 vdiv.f32 s11, s15, s11 */
/* @0x20fc74 vadd.f32 s11, s11, s12 */
/* @0x20fc78 b 0x20faf4 <_Z14Color_RGBtoHSV4TRGB+0xac> */
/* @0x20fc7c vmov.f32 s15, #5.000000e-01 */
/* @0x20fc80 vldr s14, [pc, #12] */
/* @0x20fc84 vmla.f32 s15, s10, s14 */
/* @0x20fc88 vcvt.s32.f32 s15, s15 */
/* @0x20fc8c vmov r2, s15 */
/* @0x20fc90 b 0x20fb9c <_Z14Color_RGBtoHSV4TRGB+0x154> */
/* @0x20fc94 cmnmi pc, #0 */
/* @0x20fc98 rsbsmi r0, r0, #0 */
/* @0x20fc9c .word 0x43b40000 */
/* @0x20fca0 rscsmi r0, r0, #0 */
/* @0x20fca4 cmnmi r0, #0 */

/* ── FUNC 0x20fca8 · Color_ColorToHSV(unsigned int) · size=92 · insn=23 */
/* @0x20fca8 str lr, [sp, #-0x4]! */
/* @0x20fcac sub sp, sp, #20 */
/* @0x20fcb0 add r3, sp, #16 */
/* @0x20fcb4 str r0, [r3, #-0xc]! */
/* @0x20fcb8 mov r0, r3 */
/* @0x20fcbc bl 0x20fa00 <_Z16Color_ColorToRGBRj> */
/* @0x20fcc0 strb r0, [sp, #0xc] */
/* @0x20fcc4 ubfx r3, r0, #0x8, #0x8 */
/* @0x20fcc8 ubfx r0, r0, #0x10, #0x8 */
/* @0x20fccc strb r3, [sp, #0xd] */
/* @0x20fcd0 strb r0, [sp, #0xe] */
/* @0x20fcd4 ldr r0, [sp, #0xc] */
/* @0x20fcd8 bl 0x20fa48 <_Z14Color_RGBtoHSV4TRGB> */
/* @0x20fcdc mov r3, #0 */
/* @0x20fce0 uxtb r1, r0 */
/* @0x20fce4 ubfx r2, r0, #0x8, #0x8 */
/* @0x20fce8 bfi r3, r1, #0, #8 */
/* @0x20fcec ubfx r0, r0, #0x10, #0x8 */
/* @0x20fcf0 bfi r3, r2, #8, #8 */
/* @0x20fcf4 bfi r3, r0, #16, #8 */
/* @0x20fcf8 mov r0, r3 */
/* @0x20fcfc add sp, sp, #20 */
/* @0x20fd00 ldr pc, [sp], #4 */

/* ── FUNC 0x20fd04 · Color_HSVToRGB(THSV&) · size=424 · insn=106 */
/* @0x20fd04 ldrb r3, [r0] */
/* @0x20fd08 vldr s11, [pc, #396] */
/* @0x20fd0c vldr s13, [pc, #396] */
/* @0x20fd10 vldr s10, [pc, #396] */
/* @0x20fd14 sub sp, sp, #8 */
/* @0x20fd18 vmov s14, r3 */
/* @0x20fd1c ldrb r3, [r0, #0x1] */
/* @0x20fd20 ldrb r0, [r0, #0x2] */
/* @0x20fd24 vcvt.f32.s32 s14, s14 */
/* @0x20fd28 vmov s12, r3 */
/* @0x20fd2c vmov s15, r0 */
/* @0x20fd30 vmul.f32 s14, s14, s11 */
/* @0x20fd34 vcvt.f32.u32 s12, s12 */
/* @0x20fd38 vdiv.f32 s14, s14, s13 */
/* @0x20fd3c vcvt.f32.u32 s15, s15 */
/* @0x20fd40 vdiv.f32 s12, s12, s13 */
/* @0x20fd44 vdiv.f32 s15, s15, s13 */
/* @0x20fd48 vcmp.f32 s14, s11 */
/* @0x20fd4c vmrs APSR_nzcv, fpscr */
/* @0x20fd50 vcmp.f32 s12, s10 */
/* @0x20fd54 vmoveq.f32 s14, s10 */
/* @0x20fd58 vmrs APSR_nzcv, fpscr */
/* @0x20fd5c vmoveq.f32 s12, s15 */
/* @0x20fd60 vmoveq.f32 s13, s15 */
/* @0x20fd64 beq 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fd68 vldr s13, [pc, #312] */
/* @0x20fd6c vdiv.f32 s14, s14, s13 */
/* @0x20fd70 vcvt.s32.f32 s10, s14 */
/* @0x20fd74 vcvt.f32.s32 s13, s10 */
/* @0x20fd78 vmov r3, s10 */
/* @0x20fd7c vmov.f32 s11, #1.000000e+00 */
/* @0x20fd80 vsub.f32 s14, s14, s13 */
/* @0x20fd84 vsub.f32 s9, s11, s14 */
/* @0x20fd88 vmov.f32 s13, s11 */
/* @0x20fd8c vmls.f32 s13, s12, s14 */
/* @0x20fd90 vmov.f32 s14, s11 */
/* @0x20fd94 vmls.f32 s14, s9, s12 */
/* @0x20fd98 vsub.f32 s12, s11, s12 */
/* @0x20fd9c vmul.f32 s14, s14, s15 */
/* @0x20fda0 vmul.f32 s13, s13, s15 */
/* @0x20fda4 vmul.f32 s12, s12, s15 */
/* @0x20fda8 cmp r3, #4 */
/* @0x20fdac addls pc, pc, r3, lsl #2 */
/* @0x20fdb0 b 0x20fe88 <_Z14Color_HSVToRGBR4THSV+0x184> */
/* @0x20fdb4 b 0x20fe5c <_Z14Color_HSVToRGBR4THSV+0x158> */
/* @0x20fdb8 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fdbc b 0x20fe68 <_Z14Color_HSVToRGBR4THSV+0x164> */
/* @0x20fdc0 b 0x20fe74 <_Z14Color_HSVToRGBR4THSV+0x170> */
/* @0x20fdc4 b 0x20fdc8 <_Z14Color_HSVToRGBR4THSV+0xc4> */
/* @0x20fdc8 vmov.f32 s11, s15 */
/* @0x20fdcc vmov.f32 s13, s14 */
/* @0x20fdd0 vmov.f32 s15, s12 */
/* @0x20fdd4 vmov.f32 s12, s11 */
/* @0x20fdd8 vldr s11, [pc, #192] */
/* @0x20fddc mov r0, #0 */
/* @0x20fde0 vmov.f32 s14, #5.000000e-01 */
/* @0x20fde4 vmla.f32 s14, s13, s11 */
/* @0x20fde8 vldr s13, [pc, #176] */
/* @0x20fdec vcvt.s32.f32 s14, s14 */
/* @0x20fdf0 vmov r3, s14 */
/* @0x20fdf4 vmov.f32 s14, #5.000000e-01 */
/* @0x20fdf8 vmla.f32 s14, s15, s13 */
/* @0x20fdfc cmp r3, #254 */
/* @0x20fe00 bicle r3, r3, r3, asr #31 */
/* @0x20fe04 movgt r2, #255 */
/* @0x20fe08 uxtble r2, r3 */
/* @0x20fe0c vmov.f32 s15, #5.000000e-01 */
/* @0x20fe10 vcvt.s32.f32 s14, s14 */
/* @0x20fe14 vmov r3, s14 */
/* @0x20fe18 vldr s14, [pc, #128] */
/* @0x20fe1c vmla.f32 s15, s12, s14 */
/* @0x20fe20 cmp r3, #254 */
/* @0x20fe24 bicle r3, r3, r3, asr #31 */
/* @0x20fe28 vcvt.s32.f32 s15, s15 */
/* @0x20fe2c movgt r1, #255 */
/* @0x20fe30 uxtble r1, r3 */
/* @0x20fe34 vmov r3, s15 */
/* @0x20fe38 cmp r3, #254 */
/* @0x20fe3c bicle r3, r3, r3, asr #31 */
/* @0x20fe40 movgt r3, #255 */
/* @0x20fe44 uxtble r3, r3 */
/* @0x20fe48 bfi r0, r3, #0, #8 */
/* @0x20fe4c bfi r0, r1, #8, #8 */
/* @0x20fe50 bfi r0, r2, #16, #8 */
/* @0x20fe54 add sp, sp, #8 */
/* @0x20fe58 bx lr */
/* @0x20fe5c vmov.f32 s13, s15 */
/* @0x20fe60 vmov.f32 s15, s14 */
/* @0x20fe64 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fe68 vmov.f32 s13, s12 */
/* @0x20fe6c vmov.f32 s12, s14 */
/* @0x20fe70 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fe74 vmov.f32 s14, s13 */
/* @0x20fe78 vmov.f32 s13, s12 */
/* @0x20fe7c vmov.f32 s12, s15 */
/* @0x20fe80 vmov.f32 s15, s14 */
/* @0x20fe84 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fe88 vmov.f32 s14, s13 */
/* @0x20fe8c vmov.f32 s13, s15 */
/* @0x20fe90 vmov.f32 s15, s12 */
/* @0x20fe94 vmov.f32 s12, s14 */
/* @0x20fe98 b 0x20fdd8 <_Z14Color_HSVToRGBR4THSV+0xd4> */
/* @0x20fe9c .word 0x43b40000 */
/* @0x20fea0 cmnmi pc, #0 */
/* @0x20fea4 andeq r0, r0, r0 */
/* @0x20fea8 rsbsmi r0, r0, #0 */

/* ── FUNC 0x20feac · Color_HSVToColor(THSV&) · size=52 · insn=13 */
/* @0x20feac str lr, [sp, #-0x4]! */
/* @0x20feb0 sub sp, sp, #12 */
/* @0x20feb4 bl 0x20fd04 <_Z14Color_HSVToRGBR4THSV> */
/* @0x20feb8 mov r3, r0 */
/* @0x20febc add r0, sp, #4 */
/* @0x20fec0 ubfx r2, r3, #0x8, #0x8 */
/* @0x20fec4 strb r3, [sp, #0x4] */
/* @0x20fec8 strb r2, [sp, #0x5] */
/* @0x20fecc ubfx r3, r3, #0x10, #0x8 */
/* @0x20fed0 strb r3, [sp, #0x6] */
/* @0x20fed4 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB> */
/* @0x20fed8 add sp, sp, #12 */
/* @0x20fedc ldr pc, [sp], #4 */

/* ── FUNC 0x20fee0 · Color_MergeRGB(TRGB, TRGB, float) · size=216 · insn=54 */
/* @0x20fee0 ubfx r3, r1, #0x10, #0x8 */
/* @0x20fee4 push {r4, r5, lr} */
/* @0x20fee8 vpush {d8} */
/* @0x20feec vmov s15, r3 */
/* @0x20fef0 vmov.f32 s17, #1.000000e+00 */
/* @0x20fef4 ubfx r3, r0, #0x10, #0x8 */
/* @0x20fef8 vmov s16, r2 */
/* @0x20fefc sub sp, sp, #20 */
/* @0x20ff00 vmov s14, r3 */
/* @0x20ff04 str r0, [sp, #0x4] */
/* @0x20ff08 str r1, [sp] */
/* @0x20ff0c vcvt.f32.s32 s15, s15 */
/* @0x20ff10 vmul.f32 s15, s15, s16 */
/* @0x20ff14 vsub.f32 s17, s17, s16 */
/* @0x20ff18 vcvt.f32.s32 s14, s14 */
/* @0x20ff1c vmla.f32 s15, s14, s17 */
/* @0x20ff20 vcvt.f64.f32 d6, s15 */
/* @0x20ff24 vmov r0, r1, d6 */
/* @0x20ff28 bl 0xb66e8 <lrint@plt> */
/* @0x20ff2c ldrb r3, [sp, #0x1] */
/* @0x20ff30 vmov s15, r3 */
/* @0x20ff34 ldrb r3, [sp, #0x5] */
/* @0x20ff38 vcvt.f32.s32 s15, s15 */
/* @0x20ff3c vmov s14, r3 */
/* @0x20ff40 vmul.f32 s15, s15, s16 */
/* @0x20ff44 vcvt.f32.s32 s14, s14 */
/* @0x20ff48 vmla.f32 s15, s14, s17 */
/* @0x20ff4c mov r4, r0 */
/* @0x20ff50 uxtb r4, r4 */
/* @0x20ff54 vcvt.f64.f32 d6, s15 */
/* @0x20ff58 vmov r0, r1, d6 */
/* @0x20ff5c bl 0xb66e8 <lrint@plt> */
/* @0x20ff60 ldrb r3, [sp] */
/* @0x20ff64 vmov s14, r3 */
/* @0x20ff68 ldrb r3, [sp, #0x4] */
/* @0x20ff6c vcvt.f32.s32 s14, s14 */
/* @0x20ff70 vmov s15, r3 */
/* @0x20ff74 vmul.f32 s16, s14, s16 */
/* @0x20ff78 vcvt.f32.s32 s15, s15 */
/* @0x20ff7c vmla.f32 s16, s15, s17 */
/* @0x20ff80 mov r5, r0 */
/* @0x20ff84 uxtb r5, r5 */
/* @0x20ff88 vcvt.f64.f32 d6, s16 */
/* @0x20ff8c vmov r0, r1, d6 */
/* @0x20ff90 bl 0xb66e8 <lrint@plt> */
/* @0x20ff94 mov r3, #0 */
/* @0x20ff98 uxtb r0, r0 */
/* @0x20ff9c bfi r3, r0, #0, #8 */
/* @0x20ffa0 bfi r3, r5, #8, #8 */
/* @0x20ffa4 bfi r3, r4, #16, #8 */
/* @0x20ffa8 mov r0, r3 */
/* @0x20ffac add sp, sp, #20 */
/* @0x20ffb0 vpop {d8} */
/* @0x20ffb4 pop {r4, r5, pc} */

/* ── FUNC 0x20ffb8 · Color_Merge(unsigned int, unsigned int, float) · size=136 · insn=34 */
/* @0x20ffb8 push {r4, lr} */
/* @0x20ffbc sub sp, sp, #24 */
/* @0x20ffc0 mov r4, r2 */
/* @0x20ffc4 str r0, [sp, #0x4] */
/* @0x20ffc8 add r0, sp, #4 */
/* @0x20ffcc str r1, [sp] */
/* @0x20ffd0 bl 0x20fa00 <_Z16Color_ColorToRGBRj> */
/* @0x20ffd4 mov r3, r0 */
/* @0x20ffd8 mov r0, sp */
/* @0x20ffdc ubfx r2, r3, #0x8, #0x8 */
/* @0x20ffe0 strb r3, [sp, #0xc] */
/* @0x20ffe4 strb r2, [sp, #0xd] */
/* @0x20ffe8 ubfx r3, r3, #0x10, #0x8 */
/* @0x20ffec strb r3, [sp, #0xe] */
/* @0x20fff0 bl 0x20fa00 <_Z16Color_ColorToRGBRj> */
/* @0x20fff4 mov r2, r4 */
/* @0x20fff8 strb r0, [sp, #0x10] */
/* @0x20fffc ubfx r3, r0, #0x8, #0x8 */
/* @0x210000 ubfx r0, r0, #0x10, #0x8 */
/* @0x210004 strb r3, [sp, #0x11] */
/* @0x210008 strb r0, [sp, #0x12] */
/* @0x21000c ldr r1, [sp, #0x10] */
/* @0x210010 ldr r0, [sp, #0xc] */
/* @0x210014 bl 0x20fee0 <_Z14Color_MergeRGB4TRGBS_f> */
/* @0x210018 mov r3, r0 */
/* @0x21001c add r0, sp, #20 */
/* @0x210020 ubfx r2, r3, #0x8, #0x8 */
/* @0x210024 strb r3, [sp, #0x14] */
/* @0x210028 strb r2, [sp, #0x15] */
/* @0x21002c ubfx r3, r3, #0x10, #0x8 */
/* @0x210030 strb r3, [sp, #0x16] */
/* @0x210034 bl 0x20fa2c <_Z16Color_RGBToColorR4TRGB> */
/* @0x210038 add sp, sp, #24 */
/* @0x21003c pop {r4, pc} */

/* ── FUNC 0x210040 · cARRAY_CLASS<DLL_RFunction*>::~cARRAY_CLASS() · size=236 · insn=59 */
/* @0x210040 ldr r12, [r0] */
/* @0x210044 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x210048 cmp r12, #0 */
/* @0x21004c mov r7, r0 */
/* @0x210050 beq 0x210114 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xd4> */
/* @0x210054 ldr r5, [r0, #0x4] */
/* @0x210058 cmp r5, #0 */
/* @0x21005c beq 0x21011c <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xdc> */
/* @0x210060 cmp r12, #0 */
/* @0x210064 ble 0x2100fc <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xbc> */
/* @0x210068 mov r4, #0 */
/* @0x21006c mov r8, r4 */
/* @0x210070 ldr r1, [r5] */
/* @0x210074 movw r3, #0xfeee */
/* @0x210078 movt r3, #0xfeee */
/* @0x21007c movw r2, #0xfeee */
/* @0x210080 cmp r1, r3 */
/* @0x210084 movt r2, #0xfeee */
/* @0x210088 lsl r9, r4, #2 */
/* @0x21008c beq 0x2100f0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xb0> */
/* @0x210090 ldr r6, [r5, r4, lsl #2] */
/* @0x210094 add r1, r5, r9 */
/* @0x210098 cmp r6, #0 */
/* @0x21009c beq 0x2100f0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xb0> */
/* @0x2100a0 ldr r3, [r6] */
/* @0x2100a4 cmp r3, r2 */
/* @0x2100a8 mov r0, r3 */
/* @0x2100ac beq 0x2100e8 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xa8> */
/* @0x2100b0 cmp r3, #0 */
/* @0x2100b4 beq 0x2100c0 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x80> */
/* @0x2100b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2100bc str r8, [r6] */
/* @0x2100c0 ldr r0, [r6, #0x8] */
/* @0x2100c4 cmp r0, #0 */
/* @0x2100c8 beq 0x2100d4 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x94> */
/* @0x2100cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x2100d0 str r8, [r6, #0x8] */
/* @0x2100d4 mov r0, r6 */
/* @0x2100d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2100dc ldr r1, [r7, #0x4] */
/* @0x2100e0 ldr r12, [r7] */
/* @0x2100e4 add r1, r1, r9 */
/* @0x2100e8 str r8, [r1] */
/* @0x2100ec ldr r5, [r7, #0x4] */
/* @0x2100f0 add r4, r4, #1 */
/* @0x2100f4 cmp r4, r12 */
/* @0x2100f8 blt 0x210070 <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0x30> */
/* @0x2100fc mov r0, r5 */
/* @0x210100 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x210104 mov r3, #0 */
/* @0x210108 str r3, [r7, #0x4] */
/* @0x21010c mov r3, #0 */
/* @0x210110 str r3, [r7] */
/* @0x210114 mov r0, r7 */
/* @0x210118 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x21011c mov r0, r5 */
/* @0x210120 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x210124 str r5, [r7, #0x4] */
/* @0x210128 b 0x21010c <_ZN12cARRAY_CLASSIP13DLL_RFunctionED2Ev+0xcc> */

/* ── FUNC 0x210040 · cARRAY_CLASS<DLL_RFunction*>::~cARRAY_CLASS() · alias of the symbol above · insn=0 */
