/* libyoyo.so 覆盖卡组 0132
 * 函数 0x1999d0..0x19c7ec，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x1999d0 · YYObjectBase::Add(char const*, double, int) · size=108 · insn=27 */
/* @0x1999d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1999d4 mov r4, r1 */
/* @0x1999d8 mov r6, r2 */
/* @0x1999dc mov r5, r3 */
/* @0x1999e0 mov r7, r0 */
/* @0x1999e4 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x1999e8 cmp r0, #0 */
/* @0x1999ec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1999f0 mov r1, r4 */
/* @0x1999f4 mov r0, r7 */
/* @0x1999f8 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x1999fc ldr r3, [r0, #0xc] */
/* @0x199a00 mov r4, r0 */
/* @0x199a04 sub r3, r3, #1 */
/* @0x199a08 bic r3, r3, #-16777216 */
/* @0x199a0c bic r3, r3, #3 */
/* @0x199a10 cmp r3, #0 */
/* @0x199a14 beq 0x199a34 <_ZN12YYObjectBase3AddEPKcdi+0x64> */
/* @0x199a18 ldr r2, [sp, #0x18] */
/* @0x199a1c mov r3, #0 */
/* @0x199a20 str r6, [r4] */
/* @0x199a24 str r5, [r4, #0x4] */
/* @0x199a28 str r2, [r4, #0x8] */
/* @0x199a2c str r3, [r4, #0xc] */
/* @0x199a30 pop {r3, r4, r5, r6, r7, pc} */
/* @0x199a34 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199a38 b 0x199a18 <_ZN12YYObjectBase3AddEPKcdi+0x48> */

/* ── FUNC 0x199a3c · YYObjectBase::Add(char const*, long long, int) · size=108 · insn=27 */
/* @0x199a3c push {r3, r4, r5, r6, r7, lr} */
/* @0x199a40 mov r4, r1 */
/* @0x199a44 mov r6, r2 */
/* @0x199a48 mov r5, r3 */
/* @0x199a4c mov r7, r0 */
/* @0x199a50 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199a54 cmp r0, #0 */
/* @0x199a58 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x199a5c mov r1, r4 */
/* @0x199a60 mov r0, r7 */
/* @0x199a64 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199a68 ldr r3, [r0, #0xc] */
/* @0x199a6c mov r4, r0 */
/* @0x199a70 sub r3, r3, #1 */
/* @0x199a74 bic r3, r3, #-16777216 */
/* @0x199a78 bic r3, r3, #3 */
/* @0x199a7c cmp r3, #0 */
/* @0x199a80 beq 0x199aa0 <_ZN12YYObjectBase3AddEPKcxi+0x64> */
/* @0x199a84 ldr r2, [sp, #0x18] */
/* @0x199a88 mov r3, #10 */
/* @0x199a8c str r6, [r4] */
/* @0x199a90 str r5, [r4, #0x4] */
/* @0x199a94 str r2, [r4, #0x8] */
/* @0x199a98 str r3, [r4, #0xc] */
/* @0x199a9c pop {r3, r4, r5, r6, r7, pc} */
/* @0x199aa0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199aa4 b 0x199a84 <_ZN12YYObjectBase3AddEPKcxi+0x48> */

/* ── FUNC 0x199aa8 · YYObjectBase::Add(char const*, char const*, int) · size=120 · insn=30 */
/* @0x199aa8 push {r3, r4, r5, r6, r7, lr} */
/* @0x199aac mov r4, r1 */
/* @0x199ab0 mov r6, r2 */
/* @0x199ab4 mov r5, r3 */
/* @0x199ab8 mov r7, r0 */
/* @0x199abc bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199ac0 cmp r0, #0 */
/* @0x199ac4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x199ac8 mov r1, r4 */
/* @0x199acc mov r0, r7 */
/* @0x199ad0 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199ad4 ldr r3, [r0, #0xc] */
/* @0x199ad8 mov r4, r0 */
/* @0x199adc sub r3, r3, #1 */
/* @0x199ae0 bic r3, r3, #-16777216 */
/* @0x199ae4 bic r3, r3, #3 */
/* @0x199ae8 cmp r3, #0 */
/* @0x199aec beq 0x199b18 <_ZN12YYObjectBase3AddEPKcS1_i+0x70> */
/* @0x199af0 mov r3, #0 */
/* @0x199af4 mov r2, #5 */
/* @0x199af8 mov r1, r6 */
/* @0x199afc str r3, [r4, #0x8] */
/* @0x199b00 str r3, [r4] */
/* @0x199b04 mov r0, r4 */
/* @0x199b08 str r2, [r4, #0xc] */
/* @0x199b0c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x199b10 str r5, [r4, #0x8] */
/* @0x199b14 pop {r3, r4, r5, r6, r7, pc} */
/* @0x199b18 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199b1c b 0x199af0 <_ZN12YYObjectBase3AddEPKcS1_i+0x48> */

/* ── FUNC 0x199b20 · YYObjectBase::Add(char const*, void*, int) · size=100 · insn=25 */
/* @0x199b20 push {r3, r4, r5, r6, r7, lr} */
/* @0x199b24 mov r4, r1 */
/* @0x199b28 mov r6, r2 */
/* @0x199b2c mov r5, r3 */
/* @0x199b30 mov r7, r0 */
/* @0x199b34 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199b38 cmp r0, #0 */
/* @0x199b3c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x199b40 mov r1, r4 */
/* @0x199b44 mov r0, r7 */
/* @0x199b48 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199b4c ldr r3, [r0, #0xc] */
/* @0x199b50 mov r4, r0 */
/* @0x199b54 sub r3, r3, #1 */
/* @0x199b58 bic r3, r3, #-16777216 */
/* @0x199b5c bic r3, r3, #3 */
/* @0x199b60 cmp r3, #0 */
/* @0x199b64 beq 0x199b7c <_ZN12YYObjectBase3AddEPKcPvi+0x5c> */
/* @0x199b68 mov r3, #3 */
/* @0x199b6c str r6, [r4] */
/* @0x199b70 str r5, [r4, #0x8] */
/* @0x199b74 str r3, [r4, #0xc] */
/* @0x199b78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x199b7c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199b80 b 0x199b68 <_ZN12YYObjectBase3AddEPKcPvi+0x48> */

/* ── FUNC 0x199b84 · YYObjectBase::Add(char const*, RValue&, int) · size=624 · insn=156 */
/* @0x199b84 push {r4, r5, r6, r7, r8, lr} */
/* @0x199b88 mov r4, r1 */
/* @0x199b8c mov r5, r2 */
/* @0x199b90 mov r7, r3 */
/* @0x199b94 mov r6, r0 */
/* @0x199b98 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199b9c cmp r0, #0 */
/* @0x199ba0 popeq {r4, r5, r6, r7, r8, pc} */
/* @0x199ba4 mov r1, r4 */
/* @0x199ba8 mov r0, r6 */
/* @0x199bac bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199bb0 mov r4, r0 */
/* @0x199bb4 mov r0, r6 */
/* @0x199bb8 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase> */
/* @0x199bbc ldr r2, [r4, #0xc] */
/* @0x199bc0 bic r3, r2, #-16777216 */
/* @0x199bc4 cmp r3, #1 */
/* @0x199bc8 beq 0x199c80 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xfc> */
/* @0x199bcc cmp r3, #2 */
/* @0x199bd0 bne 0x199bf8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x74> */
/* @0x199bd4 sub r2, r2, #1 */
/* @0x199bd8 bic r2, r2, #-16777216 */
/* @0x199bdc bic r2, r2, #3 */
/* @0x199be0 cmp r2, #0 */
/* @0x199be4 beq 0x199d54 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1d0> */
/* @0x199be8 mov r2, #0 */
/* @0x199bec mov r3, #5 */
/* @0x199bf0 str r2, [r4, #0x8] */
/* @0x199bf4 str r3, [r4, #0xc] */
/* @0x199bf8 ldr r3, [r5, #0xc] */
/* @0x199bfc mov r1, #0 */
/* @0x199c00 ldr r2, [r5, #0x8] */
/* @0x199c04 str r1, [r4] */
/* @0x199c08 str r3, [r4, #0xc] */
/* @0x199c0c ldr r3, [r5, #0xc] */
/* @0x199c10 str r2, [r4, #0x8] */
/* @0x199c14 bic r3, r3, #-16777216 */
/* @0x199c18 cmp r3, #14 */
/* @0x199c1c addls pc, pc, r3, lsl #2 */
/* @0x199c20 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c24 b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0> */
/* @0x199c28 b 0x199cd8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x154> */
/* @0x199c2c b 0x199cf0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x16c> */
/* @0x199c30 b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc> */
/* @0x199c34 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c38 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c3c b 0x199cb4 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x130> */
/* @0x199c40 b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc> */
/* @0x199c44 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c48 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c4c b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0> */
/* @0x199c50 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c54 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c58 b 0x199c74 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xf0> */
/* @0x199c5c b 0x199c60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xdc> */
/* @0x199c60 ldr r3, [r5] */
/* @0x199c64 str r3, [r4] */
/* @0x199c68 bl 0xd3a34 <_Z15PopContextStackv> */
/* @0x199c6c str r7, [r4, #0x8] */
/* @0x199c70 pop {r4, r5, r6, r7, r8, pc} */
/* @0x199c74 ldm r5, {r2, r3} */
/* @0x199c78 stm r4, {r2, r3} */
/* @0x199c7c b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199c80 ldr r6, [r4] */
/* @0x199c84 cmp r6, #0 */
/* @0x199c88 beq 0x199ca8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x124> */
/* @0x199c8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x199c90 ldr r8, [r6, #0x4] */
/* @0x199c94 sub r8, r8, #1 */
/* @0x199c98 str r8, [r6, #0x4] */
/* @0x199c9c cmp r8, #0 */
/* @0x199ca0 beq 0x199d1c <_ZN12YYObjectBase3AddEPKcR6RValuei+0x198> */
/* @0x199ca4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x199ca8 mov r3, #0 */
/* @0x199cac str r3, [r4] */
/* @0x199cb0 b 0x199bf8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x74> */
/* @0x199cb4 ldr r3, [r5] */
/* @0x199cb8 str r3, [r4] */
/* @0x199cbc ldr r3, [r5] */
/* @0x199cc0 cmp r3, #0 */
/* @0x199cc4 beq 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199cc8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x199ccc ldr r1, [r5] */
/* @0x199cd0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x199cd4 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199cd8 ldr r3, [r5] */
/* @0x199cdc cmp r3, #0 */
/* @0x199ce0 ldrne r2, [r3, #0x4] */
/* @0x199ce4 addne r2, r2, #1 */
/* @0x199ce8 strne r2, [r3, #0x4] */
/* @0x199cec b 0x199c64 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe0> */
/* @0x199cf0 ldr r3, [r5] */
/* @0x199cf4 cmp r3, #0 */
/* @0x199cf8 str r3, [r4] */
/* @0x199cfc beq 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199d00 ldr r1, [r3, #0x8] */
/* @0x199d04 ldr r2, [r3] */
/* @0x199d08 cmp r1, #0 */
/* @0x199d0c streq r4, [r3, #0x8] */
/* @0x199d10 add r2, r2, #1 */
/* @0x199d14 str r2, [r3] */
/* @0x199d18 b 0x199c68 <_ZN12YYObjectBase3AddEPKcR6RValuei+0xe4> */
/* @0x199d1c ldr r0, [r6] */
/* @0x199d20 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x199d24 str r8, [r6] */
/* @0x199d28 str r8, [r6, #0x8] */
/* @0x199d2c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x199d30 ldr r8, [r6, #0x4] */
/* @0x199d34 sub r8, r8, #1 */
/* @0x199d38 str r8, [r6, #0x4] */
/* @0x199d3c cmp r8, #0 */
/* @0x199d40 beq 0x199d60 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1dc> */
/* @0x199d44 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x199d48 mov r0, r6 */
/* @0x199d4c bl 0x27d1d0 <_ZdlPv> */
/* @0x199d50 b 0x199ca4 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x120> */
/* @0x199d54 mov r0, r4 */
/* @0x199d58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199d5c b 0x199be8 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x64> */
/* @0x199d60 ldr r0, [r6] */
/* @0x199d64 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x199d68 str r8, [r6] */
/* @0x199d6c str r8, [r6, #0x8] */
/* @0x199d70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x199d74 ldr r8, [r6, #0x4] */
/* @0x199d78 sub r8, r8, #1 */
/* @0x199d7c str r8, [r6, #0x4] */
/* @0x199d80 cmp r8, #0 */
/* @0x199d84 beq 0x199d98 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x214> */
/* @0x199d88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x199d8c mov r0, r6 */
/* @0x199d90 bl 0x27d1d0 <_ZdlPv> */
/* @0x199d94 b 0x199d44 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x1c0> */
/* @0x199d98 ldr r0, [r6] */
/* @0x199d9c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x199da0 str r8, [r6] */
/* @0x199da4 str r8, [r6, #0x8] */
/* @0x199da8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x199dac ldr r8, [r6, #0x4] */
/* @0x199db0 sub r8, r8, #1 */
/* @0x199db4 str r8, [r6, #0x4] */
/* @0x199db8 cmp r8, #0 */
/* @0x199dbc beq 0x199dd0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x24c> */
/* @0x199dc0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x199dc4 mov r0, r6 */
/* @0x199dc8 bl 0x27d1d0 <_ZdlPv> */
/* @0x199dcc b 0x199d88 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x204> */
/* @0x199dd0 ldr r0, [r6] */
/* @0x199dd4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x199dd8 mov r0, r6 */
/* @0x199ddc str r8, [r6] */
/* @0x199de0 str r8, [r6, #0x8] */
/* @0x199de4 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x199de8 mov r0, r6 */
/* @0x199dec bl 0x27d1d0 <_ZdlPv> */
/* @0x199df0 b 0x199dc0 <_ZN12YYObjectBase3AddEPKcR6RValuei+0x23c> */

/* ── FUNC 0x199df4 · YYObjectBase::AddNull(char const*, int) · size=104 · insn=26 */
/* @0x199df4 push {r4, r5, r6, lr} */
/* @0x199df8 mov r4, r1 */
/* @0x199dfc mov r5, r2 */
/* @0x199e00 mov r6, r0 */
/* @0x199e04 bl 0x19220c <_ZN12YYObjectBase12IsExtensibleEv> */
/* @0x199e08 cmp r0, #0 */
/* @0x199e0c popeq {r4, r5, r6, pc} */
/* @0x199e10 mov r1, r4 */
/* @0x199e14 mov r0, r6 */
/* @0x199e18 bl 0x196bc4 <_ZN12YYObjectBase16FindOrAllocValueEPKc> */
/* @0x199e1c ldr r3, [r0, #0xc] */
/* @0x199e20 mov r4, r0 */
/* @0x199e24 sub r3, r3, #1 */
/* @0x199e28 bic r3, r3, #-16777216 */
/* @0x199e2c bic r3, r3, #3 */
/* @0x199e30 cmp r3, #0 */
/* @0x199e34 beq 0x199e54 <_ZN12YYObjectBase7AddNullEPKci+0x60> */
/* @0x199e38 mov r3, #0 */
/* @0x199e3c mov r2, #12 */
/* @0x199e40 str r5, [r4, #0x8] */
/* @0x199e44 str r3, [r4] */
/* @0x199e48 str r3, [r4, #0x4] */
/* @0x199e4c str r2, [r4, #0xc] */
/* @0x199e50 pop {r4, r5, r6, pc} */
/* @0x199e54 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x199e58 b 0x199e38 <_ZN12YYObjectBase7AddNullEPKci+0x44> */

/* ── FUNC 0x199e5c · InitLLVM(SLLVMVars*) · size=76 · insn=19 */
/* @0x199e5c ldr r2, [pc, #0x38] */
/* @0x199e60 mov r3, #0 */
/* @0x199e64 ldr r12, [pc, #0x34] */
/* @0x199e68 ldr r1, [pc, #0x34] */
/* @0x199e6c ldr r2, [pc, r2] */
/* @0x199e70 ldr r12, [pc, r12] */
/* @0x199e74 str r2, [r0, #0x14] */
/* @0x199e78 ldr r1, [pc, r1] */
/* @0x199e7c str r12, [r0, #0x18] */
/* @0x199e80 str r3, [r0] */
/* @0x199e84 str r1, [r0, #0x1c] */
/* @0x199e88 str r3, [r0, #0x4] */
/* @0x199e8c str r3, [r0, #0x8] */
/* @0x199e90 str r3, [r0, #0xc] */
/* @0x199e94 str r3, [r0, #0x10] */
/* @0x199e98 bx lr */
/* @0x199e9c eoreq r6, r5, r0, lsr r8 */
/* @0x199ea0 eoreq r6, r5, r0, lsr r8 */
/* @0x199ea4 eoreq r6, r5, r12, lsr #16 */

/* ── FUNC 0x199ea8 · _RefFactory<YYObjectBase*>::Alloc(YYObjectBase*, int) · size=40 · insn=10 */
/* @0x199ea8 push {r3, r4, r5, lr} */
/* @0x199eac mov r0, #100 */
/* @0x199eb0 mov r5, r1 */
/* @0x199eb4 bl 0x27c524 <_Znwj> */
/* @0x199eb8 mov r1, r5 */
/* @0x199ebc mov r2, #5 */
/* @0x199ec0 mov r4, r0 */
/* @0x199ec4 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* @0x199ec8 mov r0, r4 */
/* @0x199ecc pop {r3, r4, r5, pc} */

/* ── FUNC 0x199ed0 · _RefFactory<YYObjectBase*>::Create(YYObjectBase*, int&) · size=64 · insn=16 */
/* @0x199ed0 cmp r0, #0 */
/* @0x199ed4 mov r0, #100 */
/* @0x199ed8 push {r4, lr} */
/* @0x199edc movne r3, #100 */
/* @0x199ee0 moveq r3, #0 */
/* @0x199ee4 str r3, [r1] */
/* @0x199ee8 bl 0x27c524 <_Znwj> */
/* @0x199eec ldr r3, [pc, #0x18] */
/* @0x199ef0 mvn r2, #-16777216 */
/* @0x199ef4 ldr r3, [pc, r3] */
/* @0x199ef8 ldr r1, [r3] */
/* @0x199efc mov r4, r0 */
/* @0x199f00 bl 0x19188c <_ZN12YYObjectBaseC2Eii> */
/* @0x199f04 mov r0, r4 */
/* @0x199f08 pop {r4, pc} */
/* @0x199f0c eoreq r3, r5, r0, lsr #28 */

/* ── FUNC 0x199f10 · _RefFactory<YYObjectBase*>::Destroy(YYObjectBase*) · size=32 · insn=8 */
/* @0x199f10 push {r3, lr} */
/* @0x199f14 subs r3, r0, #0 */
/* @0x199f18 beq 0x199f28 <_ZN11_RefFactoryIP12YYObjectBaseE7DestroyES1_+0x18> */
/* @0x199f1c ldr r3, [r3] */
/* @0x199f20 ldr r3, [r3, #0x4] */
/* @0x199f24 blx r3 */
/* @0x199f28 mov r0, #0 */
/* @0x199f2c pop {r3, pc} */

/* ── FUNC 0x199f30 · _RefFactory<void*>::Alloc(void*, int) · size=4 · insn=1 */
/* @0x199f30 bx lr */

/* ── FUNC 0x199f34 · _RefFactory<void*>::Create(void*, int&) · size=20 · insn=5 */
/* @0x199f34 cmp r0, #0 */
/* @0x199f38 movne r3, #4 */
/* @0x199f3c moveq r3, #0 */
/* @0x199f40 str r3, [r1] */
/* @0x199f44 bx lr */

/* ── FUNC 0x199f48 · _RefFactory<void*>::Destroy(void*) · size=8 · insn=2 */
/* @0x199f48 mov r0, #0 */
/* @0x199f4c bx lr */

/* ── FUNC 0x199f50 · CGrid::~CGrid() · size=52 · insn=13 */
/* @0x199f50 push {r4, lr} */
/* @0x199f54 mov r4, r0 */
/* @0x199f58 ldr r0, [r0, #0x1c] */
/* @0x199f5c ldr r3, [pc, #0x1c] */
/* @0x199f60 cmp r0, #0 */
/* @0x199f64 ldr r3, [pc, r3] */
/* @0x199f68 add r3, r3, #8 */
/* @0x199f6c str r3, [r4] */
/* @0x199f70 beq 0x199f78 <_ZN5CGridD2Ev+0x28> */
/* @0x199f74 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x199f78 mov r0, r4 */
/* @0x199f7c pop {r4, pc} */
/* @0x199f80 eoreq r6, r5, r4, asr #14 */

/* ── FUNC 0x199f50 · CGrid::~CGrid() · alias of the symbol above · insn=0 */

/* ── FUNC 0x199f84 · CGrid::~CGrid() · size=60 · insn=15 */
/* @0x199f84 push {r4, lr} */
/* @0x199f88 mov r4, r0 */
/* @0x199f8c ldr r0, [r0, #0x1c] */
/* @0x199f90 ldr r3, [pc, #0x24] */
/* @0x199f94 cmp r0, #0 */
/* @0x199f98 ldr r3, [pc, r3] */
/* @0x199f9c add r3, r3, #8 */
/* @0x199fa0 str r3, [r4] */
/* @0x199fa4 beq 0x199fac <_ZN5CGridD0Ev+0x28> */
/* @0x199fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x199fac mov r0, r4 */
/* @0x199fb0 bl 0x27d1d0 <_ZdlPv> */
/* @0x199fb4 mov r0, r4 */
/* @0x199fb8 pop {r4, pc} */
/* @0x199fbc eoreq r6, r5, r0, lsl r7 */

/* ── FUNC 0x199fc0 · Motion_Grid_Create(int, int, int, int, int, int) · size=440 · insn=110 */
/* @0x199fc0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x199fc4 sub sp, sp, #12 */
/* @0x199fc8 ldr r7, [pc, #0x190] */
/* @0x199fcc mov r11, r3 */
/* @0x199fd0 str r0, [sp] */
/* @0x199fd4 mov r10, r2 */
/* @0x199fd8 ldr r0, [pc, #0x184] */
/* @0x199fdc add r7, pc, r7 */
/* @0x199fe0 str r1, [sp, #0x4] */
/* @0x199fe4 ldr r3, [pc, #0x17c] */
/* @0x199fe8 ldr r4, [r7, r0] */
/* @0x199fec ldr r1, [r4] */
/* @0x199ff0 cmp r1, #0 */
/* @0x199ff4 ble 0x19a140 <_Z18Motion_Grid_Createiiiiii+0x180> */
/* @0x199ff8 ldr r8, [r7, r3] */
/* @0x199ffc ldr r3, [r8] */
/* @0x19a000 cmp r3, #0 */
/* @0x19a004 beq 0x19a12c <_Z18Motion_Grid_Createiiiiii+0x16c> */
/* @0x19a008 ldr r6, [r3] */
/* @0x19a00c cmp r6, #0 */
/* @0x19a010 beq 0x19a138 <_Z18Motion_Grid_Createiiiiii+0x178> */
/* @0x19a014 mov r5, #0 */
/* @0x19a018 b 0x19a028 <_Z18Motion_Grid_Createiiiiii+0x68> */
/* @0x19a01c ldr r2, [r3, #0x4]! */
/* @0x19a020 cmp r2, #0 */
/* @0x19a024 beq 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0> */
/* @0x19a028 add r5, r5, #1 */
/* @0x19a02c cmp r5, r1 */
/* @0x19a030 lsl r6, r5, #2 */
/* @0x19a034 bne 0x19a01c <_Z18Motion_Grid_Createiiiiii+0x5c> */
/* @0x19a038 add r1, r1, #1 */
/* @0x19a03c ldr r2, [pc, #0x128] */
/* @0x19a040 mov r3, #97 */
/* @0x19a044 mov r0, r8 */
/* @0x19a048 add r2, pc, r2 */
/* @0x19a04c lsl r1, r1, #2 */
/* @0x19a050 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19a054 ldr r3, [r4] */
/* @0x19a058 add r3, r3, #1 */
/* @0x19a05c str r3, [r4] */
/* @0x19a060 mov r0, #36 */
/* @0x19a064 mov r9, #0 */
/* @0x19a068 bl 0x27c524 <_Znwj> */
/* @0x19a06c ldr r12, [sp] */
/* @0x19a070 ldr r3, [pc, #0xf8] */
/* @0x19a074 mul r2, r11, r10 */
/* @0x19a078 ldr r1, [r7, r3] */
/* @0x19a07c mov r3, #55 */
/* @0x19a080 add r1, r1, #8 */
/* @0x19a084 mov r4, r0 */
/* @0x19a088 add r0, r0, #28 */
/* @0x19a08c str r12, [r4, #0x4] */
/* @0x19a090 ldr r12, [sp, #0x4] */
/* @0x19a094 str r1, [r4] */
/* @0x19a098 lsl r1, r2, #2 */
/* @0x19a09c str r2, [r4, #0x20] */
/* @0x19a0a0 str r12, [r4, #0x8] */
/* @0x19a0a4 ldr r12, [sp, #0x30] */
/* @0x19a0a8 ldr r2, [pc, #0xc4] */
/* @0x19a0ac str r10, [r4, #0x14] */
/* @0x19a0b0 str r12, [r4, #0xc] */
/* @0x19a0b4 add r2, pc, r2 */
/* @0x19a0b8 ldr r12, [sp, #0x34] */
/* @0x19a0bc str r11, [r4, #0x18] */
/* @0x19a0c0 str r9, [r4, #0x1c] */
/* @0x19a0c4 str r12, [r4, #0x10] */
/* @0x19a0c8 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci> */
/* @0x19a0cc ldr r3, [r4, #0x14] */
/* @0x19a0d0 cmp r3, r9 */
/* @0x19a0d4 ble 0x19a118 <_Z18Motion_Grid_Createiiiiii+0x158> */
/* @0x19a0d8 ldr r2, [r4, #0x18] */
/* @0x19a0dc mov r0, r9 */
/* @0x19a0e0 cmp r2, #0 */
/* @0x19a0e4 ble 0x19a10c <_Z18Motion_Grid_Createiiiiii+0x14c> */
/* @0x19a0e8 ldr r1, [r4, #0x1c] */
/* @0x19a0ec mov r3, #0 */
/* @0x19a0f0 mla r2, r2, r9, r3 */
/* @0x19a0f4 add r3, r3, #1 */
/* @0x19a0f8 str r0, [r1, r2, lsl #2] */
/* @0x19a0fc ldr r2, [r4, #0x18] */
/* @0x19a100 cmp r2, r3 */
/* @0x19a104 bgt 0x19a0f0 <_Z18Motion_Grid_Createiiiiii+0x130> */
/* @0x19a108 ldr r3, [r4, #0x14] */
/* @0x19a10c add r9, r9, #1 */
/* @0x19a110 cmp r9, r3 */
/* @0x19a114 blt 0x19a0e0 <_Z18Motion_Grid_Createiiiiii+0x120> */
/* @0x19a118 ldr r3, [r8] */
/* @0x19a11c mov r0, r5 */
/* @0x19a120 str r4, [r3, r6] */
/* @0x19a124 add sp, sp, #12 */
/* @0x19a128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19a12c mov r6, r3 */
/* @0x19a130 mov r5, r3 */
/* @0x19a134 b 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0> */
/* @0x19a138 mov r5, r6 */
/* @0x19a13c b 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0> */
/* @0x19a140 movne r6, #0 */
/* @0x19a144 ldrne r8, [r7, r3] */
/* @0x19a148 movne r5, r6 */
/* @0x19a14c bne 0x19a060 <_Z18Motion_Grid_Createiiiiii+0xa0> */
/* @0x19a150 mov r6, r1 */
/* @0x19a154 mov r5, r1 */
/* @0x19a158 ldr r8, [r7, r3] */
/* @0x19a15c b 0x19a038 <_Z18Motion_Grid_Createiiiiii+0x78> */
/* @0x19a160 eoreq r7, r5, r4, ror r12 */
/* @0x19a164 .word 0xffffea5c */
/* @0x19a168 .word 0xffffea60 */
/* @0x19a16c ldrsbeq r2, [r11], -r0 */
/* @0x19a170 .word 0xffffea58 */
/* @0x19a174 mulseq r11, r12, r12 */

/* ── FUNC 0x19a178 · Motion_Grid_Destroy(int) · size=92 · insn=23 */
/* @0x19a178 push {r3, r4, r5, lr} */
/* @0x19a17c subs r4, r0, #0 */
/* @0x19a180 poplt {r3, r4, r5, pc} */
/* @0x19a184 ldr r3, [pc, #0x40] */
/* @0x19a188 ldr r3, [pc, r3] */
/* @0x19a18c ldr r3, [r3] */
/* @0x19a190 cmp r4, r3 */
/* @0x19a194 popge {r3, r4, r5, pc} */
/* @0x19a198 ldr r5, [pc, #0x30] */
/* @0x19a19c ldr r5, [pc, r5] */
/* @0x19a1a0 ldr r3, [r5] */
/* @0x19a1a4 ldr r0, [r3, r4, lsl #2] */
/* @0x19a1a8 cmp r0, #0 */
/* @0x19a1ac popeq {r3, r4, r5, pc} */
/* @0x19a1b0 ldr r3, [r0] */
/* @0x19a1b4 ldr r3, [r3, #0x4] */
/* @0x19a1b8 blx r3 */
/* @0x19a1bc ldr r3, [r5] */
/* @0x19a1c0 mov r2, #0 */
/* @0x19a1c4 str r2, [r3, r4, lsl #2] */
/* @0x19a1c8 pop {r3, r4, r5, pc} */
/* @0x19a1cc eoreq r6, r5, r4, lsr #10 */
/* @0x19a1d0 eoreq r6, r5, r4, lsl r5 */

/* ── FUNC 0x19a1d4 · Motion_Grid_ClearAll(int) · size=152 · insn=38 */
/* @0x19a1d4 cmp r0, #0 */
/* @0x19a1d8 str r4, [sp, #-0x4]! */
/* @0x19a1dc blt 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88> */
/* @0x19a1e0 ldr r3, [pc, #0x7c] */
/* @0x19a1e4 ldr r3, [pc, r3] */
/* @0x19a1e8 ldr r3, [r3] */
/* @0x19a1ec cmp r0, r3 */
/* @0x19a1f0 bge 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88> */
/* @0x19a1f4 ldr r3, [pc, #0x6c] */
/* @0x19a1f8 ldr r3, [pc, r3] */
/* @0x19a1fc ldr r3, [r3] */
/* @0x19a200 ldr r0, [r3, r0, lsl #2] */
/* @0x19a204 cmp r0, #0 */
/* @0x19a208 beq 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88> */
/* @0x19a20c ldr r3, [r0, #0x14] */
/* @0x19a210 cmp r3, #0 */
/* @0x19a214 ble 0x19a25c <_Z20Motion_Grid_ClearAlli+0x88> */
/* @0x19a218 ldr r2, [r0, #0x18] */
/* @0x19a21c mov r1, #0 */
/* @0x19a220 mov r4, r1 */
/* @0x19a224 cmp r2, #0 */
/* @0x19a228 ble 0x19a250 <_Z20Motion_Grid_ClearAlli+0x7c> */
/* @0x19a22c ldr r12, [r0, #0x1c] */
/* @0x19a230 mov r3, #0 */
/* @0x19a234 mla r2, r2, r1, r3 */
/* @0x19a238 add r3, r3, #1 */
/* @0x19a23c str r4, [r12, r2, lsl #2] */
/* @0x19a240 ldr r2, [r0, #0x18] */
/* @0x19a244 cmp r2, r3 */
/* @0x19a248 bgt 0x19a234 <_Z20Motion_Grid_ClearAlli+0x60> */
/* @0x19a24c ldr r3, [r0, #0x14] */
/* @0x19a250 add r1, r1, #1 */
/* @0x19a254 cmp r1, r3 */
/* @0x19a258 blt 0x19a224 <_Z20Motion_Grid_ClearAlli+0x50> */
/* @0x19a25c ldr r4, [sp], #4 */
/* @0x19a260 bx lr */
/* @0x19a264 eoreq r6, r5, r8, asr #9 */
/* @0x19a268 .word 0x002564b8 */

/* ── FUNC 0x19a26c · Motion_Grid_ClearCell(int, int, int) · size=116 · insn=29 */
/* @0x19a26c cmp r0, #0 */
/* @0x19a270 bxlt lr */
/* @0x19a274 ldr r3, [pc, #0x5c] */
/* @0x19a278 ldr r3, [pc, r3] */
/* @0x19a27c ldr r3, [r3] */
/* @0x19a280 cmp r0, r3 */
/* @0x19a284 bxge lr */
/* @0x19a288 ldr r3, [pc, #0x4c] */
/* @0x19a28c ldr r3, [pc, r3] */
/* @0x19a290 ldr r3, [r3] */
/* @0x19a294 ldr r3, [r3, r0, lsl #2] */
/* @0x19a298 cmp r3, #0 */
/* @0x19a29c bxeq lr */
/* @0x19a2a0 cmp r1, #0 */
/* @0x19a2a4 bxlt lr */
/* @0x19a2a8 ldr r0, [r3, #0x14] */
/* @0x19a2ac cmp r1, r0 */
/* @0x19a2b0 bxge lr */
/* @0x19a2b4 cmp r2, #0 */
/* @0x19a2b8 bxlt lr */
/* @0x19a2bc ldr r0, [r3, #0x18] */
/* @0x19a2c0 cmp r2, r0 */
/* @0x19a2c4 mlalt r1, r0, r1, r2 */
/* @0x19a2c8 ldrlt r3, [r3, #0x1c] */
/* @0x19a2cc movlt r2, #0 */
/* @0x19a2d0 strlt r2, [r3, r1, lsl #2] */
/* @0x19a2d4 bx lr */
/* @0x19a2d8 eoreq r6, r5, r4, lsr r4 */
/* @0x19a2dc eoreq r6, r5, r4, lsr #8 */

/* ── FUNC 0x19a2e0 · Motion_Grid_ClearRectangle(int, int, int, int, int) · size=292 · insn=73 */
/* @0x19a2e0 cmp r0, #0 */
/* @0x19a2e4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x19a2e8 mov r6, r1 */
/* @0x19a2ec mov r9, r2 */
/* @0x19a2f0 mov r7, r3 */
/* @0x19a2f4 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a2f8 ldr r12, [pc, #0xfc] */
/* @0x19a2fc ldr r12, [pc, r12] */
/* @0x19a300 ldr r3, [r12] */
/* @0x19a304 cmp r0, r3 */
/* @0x19a308 popge {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a30c ldr r12, [pc, #0xec] */
/* @0x19a310 ldr r12, [pc, r12] */
/* @0x19a314 ldr r3, [r12] */
/* @0x19a318 ldr r5, [r3, r0, lsl #2] */
/* @0x19a31c cmp r5, #0 */
/* @0x19a320 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a324 ldr r4, [r5, #0xc] */
/* @0x19a328 ldr r8, [r5, #0x4] */
/* @0x19a32c mov r1, r4 */
/* @0x19a330 cmp r6, r7 */
/* @0x19a334 rsble r0, r8, r6 */
/* @0x19a338 rsbgt r0, r8, r7 */
/* @0x19a33c bl 0x318d10 <__divsi3> */
/* @0x19a340 mov r1, r4 */
/* @0x19a344 bic r4, r0, r0, asr #31 */
/* @0x19a348 cmp r6, r7 */
/* @0x19a34c rsbge r0, r8, r6 */
/* @0x19a350 rsblt r0, r8, r7 */
/* @0x19a354 bl 0x318d10 <__divsi3> */
/* @0x19a358 ldr r3, [r5, #0x14] */
/* @0x19a35c ldr r7, [r5, #0x10] */
/* @0x19a360 ldr r6, [r5, #0x8] */
/* @0x19a364 mov r1, r7 */
/* @0x19a368 cmp r0, r3 */
/* @0x19a36c mov r8, r0 */
/* @0x19a370 subge r8, r3, #1 */
/* @0x19a374 ldr r3, [sp, #0x20] */
/* @0x19a378 cmp r9, r3 */
/* @0x19a37c rsble r0, r6, r9 */
/* @0x19a380 rsbgt r0, r6, r3 */
/* @0x19a384 bl 0x318d10 <__divsi3> */
/* @0x19a388 ldr r3, [sp, #0x20] */
/* @0x19a38c mov r1, r7 */
/* @0x19a390 bic r7, r0, r0, asr #31 */
/* @0x19a394 cmp r9, r3 */
/* @0x19a398 rsbge r0, r6, r9 */
/* @0x19a39c rsblt r0, r6, r3 */
/* @0x19a3a0 bl 0x318d10 <__divsi3> */
/* @0x19a3a4 ldr r3, [r5, #0x18] */
/* @0x19a3a8 cmp r0, r3 */
/* @0x19a3ac subge r0, r3, #1 */
/* @0x19a3b0 cmp r8, r4 */
/* @0x19a3b4 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a3b8 add r8, r8, #1 */
/* @0x19a3bc add r6, r0, #1 */
/* @0x19a3c0 mov r12, #0 */
/* @0x19a3c4 cmp r0, r7 */
/* @0x19a3c8 blt 0x19a3ec <_Z26Motion_Grid_ClearRectangleiiiii+0x10c> */
/* @0x19a3cc ldr r1, [r5, #0x1c] */
/* @0x19a3d0 mov r3, r7 */
/* @0x19a3d4 ldr r2, [r5, #0x18] */
/* @0x19a3d8 mla r2, r2, r4, r3 */
/* @0x19a3dc add r3, r3, #1 */
/* @0x19a3e0 cmp r3, r6 */
/* @0x19a3e4 str r12, [r1, r2, lsl #2] */
/* @0x19a3e8 bne 0x19a3d4 <_Z26Motion_Grid_ClearRectangleiiiii+0xf4> */
/* @0x19a3ec add r4, r4, #1 */
/* @0x19a3f0 cmp r4, r8 */
/* @0x19a3f4 bne 0x19a3c4 <_Z26Motion_Grid_ClearRectangleiiiii+0xe4> */
/* @0x19a3f8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a3fc .word 0x002563b0 */
/* @0x19a400 eoreq r6, r5, r0, lsr #7 */

/* ── FUNC 0x19a404 · Motion_Grid_AddCell(int, int, int) · size=116 · insn=29 */
/* @0x19a404 cmp r0, #0 */
/* @0x19a408 bxlt lr */
/* @0x19a40c ldr r3, [pc, #0x5c] */
/* @0x19a410 ldr r3, [pc, r3] */
/* @0x19a414 ldr r3, [r3] */
/* @0x19a418 cmp r0, r3 */
/* @0x19a41c bxge lr */
/* @0x19a420 ldr r3, [pc, #0x4c] */
/* @0x19a424 ldr r3, [pc, r3] */
/* @0x19a428 ldr r3, [r3] */
/* @0x19a42c ldr r3, [r3, r0, lsl #2] */
/* @0x19a430 cmp r3, #0 */
/* @0x19a434 bxeq lr */
/* @0x19a438 cmp r1, #0 */
/* @0x19a43c bxlt lr */
/* @0x19a440 ldr r0, [r3, #0x14] */
/* @0x19a444 cmp r1, r0 */
/* @0x19a448 bxge lr */
/* @0x19a44c cmp r2, #0 */
/* @0x19a450 bxlt lr */
/* @0x19a454 ldr r0, [r3, #0x18] */
/* @0x19a458 cmp r2, r0 */
/* @0x19a45c mlalt r1, r0, r1, r2 */
/* @0x19a460 ldrlt r3, [r3, #0x1c] */
/* @0x19a464 mvnlt r2, #0 */
/* @0x19a468 strlt r2, [r3, r1, lsl #2] */
/* @0x19a46c bx lr */
/* @0x19a470 mlaeq r5, r12, r2, r6 */
/* @0x19a474 eoreq r6, r5, r12, lsl #5 */

/* ── FUNC 0x19a478 · Motion_Grid_GetCell(int, int, int) · size=124 · insn=31 */
/* @0x19a478 cmp r0, #0 */
/* @0x19a47c blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a480 ldr r3, [pc, #0x64] */
/* @0x19a484 ldr r3, [pc, r3] */
/* @0x19a488 ldr r3, [r3] */
/* @0x19a48c cmp r0, r3 */
/* @0x19a490 bge 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a494 ldr r3, [pc, #0x54] */
/* @0x19a498 ldr r3, [pc, r3] */
/* @0x19a49c ldr r3, [r3] */
/* @0x19a4a0 ldr r3, [r3, r0, lsl #2] */
/* @0x19a4a4 cmp r3, #0 */
/* @0x19a4a8 beq 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a4ac cmp r1, #0 */
/* @0x19a4b0 blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a4b4 ldr r0, [r3, #0x14] */
/* @0x19a4b8 cmp r1, r0 */
/* @0x19a4bc bge 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a4c0 cmp r2, #0 */
/* @0x19a4c4 blt 0x19a4d4 <_Z19Motion_Grid_GetCelliii+0x5c> */
/* @0x19a4c8 ldr r0, [r3, #0x18] */
/* @0x19a4cc cmp r2, r0 */
/* @0x19a4d0 blt 0x19a4dc <_Z19Motion_Grid_GetCelliii+0x64> */
/* @0x19a4d4 mvn r0, #0 */
/* @0x19a4d8 bx lr */
/* @0x19a4dc mla r1, r0, r1, r2 */
/* @0x19a4e0 ldr r3, [r3, #0x1c] */
/* @0x19a4e4 ldr r0, [r3, r1, lsl #2] */
/* @0x19a4e8 bx lr */
/* @0x19a4ec eoreq r6, r5, r8, lsr #4 */
/* @0x19a4f0 eoreq r6, r5, r8, lsl r2 */

/* ── FUNC 0x19a4f4 · Motion_Grid_AddRectangle(int, int, int, int, int) · size=292 · insn=73 */
/* @0x19a4f4 cmp r0, #0 */
/* @0x19a4f8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x19a4fc mov r6, r1 */
/* @0x19a500 mov r9, r2 */
/* @0x19a504 mov r7, r3 */
/* @0x19a508 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a50c ldr r12, [pc, #0xfc] */
/* @0x19a510 ldr r12, [pc, r12] */
/* @0x19a514 ldr r3, [r12] */
/* @0x19a518 cmp r0, r3 */
/* @0x19a51c popge {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a520 ldr r12, [pc, #0xec] */
/* @0x19a524 ldr r12, [pc, r12] */
/* @0x19a528 ldr r3, [r12] */
/* @0x19a52c ldr r5, [r3, r0, lsl #2] */
/* @0x19a530 cmp r5, #0 */
/* @0x19a534 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a538 ldr r4, [r5, #0xc] */
/* @0x19a53c ldr r8, [r5, #0x4] */
/* @0x19a540 mov r1, r4 */
/* @0x19a544 cmp r6, r7 */
/* @0x19a548 rsble r0, r8, r6 */
/* @0x19a54c rsbgt r0, r8, r7 */
/* @0x19a550 bl 0x318d10 <__divsi3> */
/* @0x19a554 mov r1, r4 */
/* @0x19a558 bic r4, r0, r0, asr #31 */
/* @0x19a55c cmp r6, r7 */
/* @0x19a560 rsbge r0, r8, r6 */
/* @0x19a564 rsblt r0, r8, r7 */
/* @0x19a568 bl 0x318d10 <__divsi3> */
/* @0x19a56c ldr r3, [r5, #0x14] */
/* @0x19a570 ldr r7, [r5, #0x10] */
/* @0x19a574 ldr r6, [r5, #0x8] */
/* @0x19a578 mov r1, r7 */
/* @0x19a57c cmp r0, r3 */
/* @0x19a580 mov r8, r0 */
/* @0x19a584 subge r8, r3, #1 */
/* @0x19a588 ldr r3, [sp, #0x20] */
/* @0x19a58c cmp r9, r3 */
/* @0x19a590 rsble r0, r6, r9 */
/* @0x19a594 rsbgt r0, r6, r3 */
/* @0x19a598 bl 0x318d10 <__divsi3> */
/* @0x19a59c ldr r3, [sp, #0x20] */
/* @0x19a5a0 mov r1, r7 */
/* @0x19a5a4 bic r7, r0, r0, asr #31 */
/* @0x19a5a8 cmp r9, r3 */
/* @0x19a5ac rsbge r0, r6, r9 */
/* @0x19a5b0 rsblt r0, r6, r3 */
/* @0x19a5b4 bl 0x318d10 <__divsi3> */
/* @0x19a5b8 ldr r3, [r5, #0x18] */
/* @0x19a5bc cmp r0, r3 */
/* @0x19a5c0 subge r0, r3, #1 */
/* @0x19a5c4 cmp r8, r4 */
/* @0x19a5c8 poplt {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a5cc add r8, r8, #1 */
/* @0x19a5d0 add r6, r0, #1 */
/* @0x19a5d4 mvn r12, #0 */
/* @0x19a5d8 cmp r0, r7 */
/* @0x19a5dc blt 0x19a600 <_Z24Motion_Grid_AddRectangleiiiii+0x10c> */
/* @0x19a5e0 ldr r1, [r5, #0x1c] */
/* @0x19a5e4 mov r3, r7 */
/* @0x19a5e8 ldr r2, [r5, #0x18] */
/* @0x19a5ec mla r2, r2, r4, r3 */
/* @0x19a5f0 add r3, r3, #1 */
/* @0x19a5f4 cmp r3, r6 */
/* @0x19a5f8 str r12, [r1, r2, lsl #2] */
/* @0x19a5fc bne 0x19a5e8 <_Z24Motion_Grid_AddRectangleiiiii+0xf4> */
/* @0x19a600 add r4, r4, #1 */
/* @0x19a604 cmp r4, r8 */
/* @0x19a608 bne 0x19a5d8 <_Z24Motion_Grid_AddRectangleiiiii+0xe4> */
/* @0x19a60c pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x19a610 mlaeq r5, r12, r1, r6 */
/* @0x19a614 eoreq r6, r5, r12, lsl #3 */

/* ── FUNC 0x19a618 · Motion_Grid_AddInstance(int, CInstance*, bool) · size=736 · insn=184 */
/* @0x19a618 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19a61c vpush {d8} */
/* @0x19a620 cmp r0, #0 */
/* @0x19a624 sub sp, sp, #36 */
/* @0x19a628 mov r10, r2 */
/* @0x19a62c str r1, [sp, #0xc] */
/* @0x19a630 blt 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218> */
/* @0x19a634 ldr r3, [pc, #0x2b4] */
/* @0x19a638 ldr r3, [pc, r3] */
/* @0x19a63c ldr r3, [r3] */
/* @0x19a640 cmp r0, r3 */
/* @0x19a644 bge 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218> */
/* @0x19a648 ldr r3, [pc, #0x2a4] */
/* @0x19a64c ldr r3, [pc, r3] */
/* @0x19a650 ldr r3, [r3] */
/* @0x19a654 ldr r5, [r3, r0, lsl #2] */
/* @0x19a658 cmp r5, #0 */
/* @0x19a65c beq 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218> */
/* @0x19a660 cmp r1, #0 */
/* @0x19a664 beq 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218> */
/* @0x19a668 ldrb r4, [r1, #0x64] */
/* @0x19a66c cmp r4, #0 */
/* @0x19a670 bne 0x19a83c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x224> */
/* @0x19a674 ldr r2, [sp, #0xc] */
/* @0x19a678 ldr r8, [r5, #0xc] */
/* @0x19a67c ldr r7, [r5, #0x4] */
/* @0x19a680 ldr r0, [r2, #0xe8] */
/* @0x19a684 mov r1, r8 */
/* @0x19a688 rsb r0, r7, r0 */
/* @0x19a68c bl 0x318d10 <__divsi3> */
/* @0x19a690 bic r6, r0, r0, asr #31 */
/* @0x19a694 ldr r1, [sp, #0xc] */
/* @0x19a698 ldr r0, [r1, #0xf0] */
/* @0x19a69c mov r1, r8 */
/* @0x19a6a0 rsb r0, r7, r0 */
/* @0x19a6a4 bl 0x318d10 <__divsi3> */
/* @0x19a6a8 ldr r3, [r5, #0x14] */
/* @0x19a6ac cmp r0, r3 */
/* @0x19a6b0 str r0, [sp, #0x1c] */
/* @0x19a6b4 subge r3, r3, #1 */
/* @0x19a6b8 strge r3, [sp, #0x1c] */
/* @0x19a6bc cmp r4, #0 */
/* @0x19a6c0 bne 0x19a898 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x280> */
/* @0x19a6c4 ldr r3, [sp, #0xc] */
/* @0x19a6c8 ldr r7, [r5, #0x10] */
/* @0x19a6cc ldr r4, [r5, #0x8] */
/* @0x19a6d0 ldr r0, [r3, #0xec] */
/* @0x19a6d4 mov r1, r7 */
/* @0x19a6d8 rsb r0, r4, r0 */
/* @0x19a6dc bl 0x318d10 <__divsi3> */
/* @0x19a6e0 bic r0, r0, r0, asr #31 */
/* @0x19a6e4 str r0, [sp, #0x14] */
/* @0x19a6e8 ldr r2, [sp, #0xc] */
/* @0x19a6ec mov r1, r7 */
/* @0x19a6f0 ldr r0, [r2, #0xf4] */
/* @0x19a6f4 rsb r0, r4, r0 */
/* @0x19a6f8 bl 0x318d10 <__divsi3> */
/* @0x19a6fc ldr r3, [r5, #0x18] */
/* @0x19a700 cmp r0, r3 */
/* @0x19a704 mov r9, r0 */
/* @0x19a708 subge r9, r3, #1 */
/* @0x19a70c ldr r3, [sp, #0x1c] */
/* @0x19a710 cmp r3, r6 */
/* @0x19a714 blt 0x19a830 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x218> */
/* @0x19a718 vmov.f32 s16, #1.000000e+00 */
/* @0x19a71c add r12, r6, #1 */
/* @0x19a720 mvn r11, #0 */
/* @0x19a724 ldr r3, [sp, #0x14] */
/* @0x19a728 sub r8, r12, #1 */
/* @0x19a72c str r12, [sp, #0x18] */
/* @0x19a730 cmp r9, r3 */
/* @0x19a734 blt 0x19a81c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x204> */
/* @0x19a738 ldr r1, [sp, #0x14] */
/* @0x19a73c str r12, [sp, #0x10] */
/* @0x19a740 add r4, r1, #1 */
/* @0x19a744 cmp r10, #0 */
/* @0x19a748 mov r6, r4 */
/* @0x19a74c sub r7, r4, #1 */
/* @0x19a750 beq 0x19a7fc <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1e4> */
/* @0x19a754 ldr r2, [r5, #0x18] */
/* @0x19a758 mov r6, r4 */
/* @0x19a75c ldr r3, [r5, #0x1c] */
/* @0x19a760 ldr r0, [sp, #0xc] */
/* @0x19a764 mla r2, r2, r8, r7 */
/* @0x19a768 ldr r3, [r3, r2, lsl #2] */
/* @0x19a76c cmp r3, #0 */
/* @0x19a770 blt 0x19a80c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1f4> */
/* @0x19a774 ldr r2, [r5, #0x10] */
/* @0x19a778 vldr s13, [r5, #8] */
/* @0x19a77c vcvt.f32.s32 s15, s13 */
/* @0x19a780 ldr r3, [r5, #0xc] */
/* @0x19a784 vldr s14, [r5, #4] */
/* @0x19a788 mul r1, r4, r2 */
/* @0x19a78c mul r2, r7, r2 */
/* @0x19a790 vcvt.f32.s32 s14, s14 */
/* @0x19a794 vmov s10, r1 */
/* @0x19a798 ldr r1, [sp, #0x10] */
/* @0x19a79c mul r1, r1, r3 */
/* @0x19a7a0 mul r3, r8, r3 */
/* @0x19a7a4 vcvt.f32.s32 s10, s10 */
/* @0x19a7a8 vmov s11, r1 */
/* @0x19a7ac mov r1, #1 */
/* @0x19a7b0 str r1, [sp, #0x4] */
/* @0x19a7b4 vadd.f32 s10, s15, s10 */
/* @0x19a7b8 vsub.f32 s10, s10, s16 */
/* @0x19a7bc vcvt.f32.s32 s11, s11 */
/* @0x19a7c0 vstr s10, [sp] */
/* @0x19a7c4 vmov s10, r3 */
/* @0x19a7c8 vadd.f32 s11, s14, s11 */
/* @0x19a7cc vcvt.f32.s32 s12, s10 */
/* @0x19a7d0 vmov s10, r2 */
/* @0x19a7d4 vcvt.f32.s32 s13, s10 */
/* @0x19a7d8 vsub.f32 s11, s11, s16 */
/* @0x19a7dc vadd.f32 s12, s14, s12 */
/* @0x19a7e0 vmov r3, s11 */
/* @0x19a7e4 vadd.f32 s13, s15, s13 */
/* @0x19a7e8 vmov r1, s12 */
/* @0x19a7ec vmov r2, s13 */
/* @0x19a7f0 bl 0x1946f4 <_ZN9CInstance19Collision_RectangleEffffb> */
/* @0x19a7f4 cmp r0, #0 */
/* @0x19a7f8 beq 0x19a80c <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x1f4> */
/* @0x19a7fc ldr r2, [r5, #0x18] */
/* @0x19a800 ldr r3, [r5, #0x1c] */
/* @0x19a804 mla r7, r2, r8, r7 */
/* @0x19a808 str r11, [r3, r7, lsl #2] */
/* @0x19a80c cmp r9, r6 */
/* @0x19a810 add r4, r4, #1 */
/* @0x19a814 bge 0x19a744 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x12c> */
/* @0x19a818 ldr r12, [sp, #0x10] */
/* @0x19a81c ldr r1, [sp, #0x1c] */
/* @0x19a820 add r12, r12, #1 */
/* @0x19a824 ldr r2, [sp, #0x18] */
/* @0x19a828 cmp r1, r2 */
/* @0x19a82c bge 0x19a724 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x10c> */
/* @0x19a830 add sp, sp, #36 */
/* @0x19a834 vpop {d8} */
/* @0x19a838 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19a83c mov r0, r1 */
/* @0x19a840 mov r1, #1 */
/* @0x19a844 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x19a848 ldr r1, [sp, #0xc] */
/* @0x19a84c ldr r8, [r5, #0xc] */
/* @0x19a850 ldr r7, [r5, #0x4] */
/* @0x19a854 ldr r0, [r1, #0xe8] */
/* @0x19a858 mov r1, r8 */
/* @0x19a85c rsb r0, r7, r0 */
/* @0x19a860 bl 0x318d10 <__divsi3> */
/* @0x19a864 ldr r2, [sp, #0xc] */
/* @0x19a868 ldrb r4, [r2, #0x64] */
/* @0x19a86c cmp r4, #0 */
/* @0x19a870 bic r6, r0, r0, asr #31 */
/* @0x19a874 beq 0x19a694 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x7c> */
/* @0x19a878 mov r0, r2 */
/* @0x19a87c mov r1, #1 */
/* @0x19a880 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x19a884 ldr r3, [sp, #0xc] */
/* @0x19a888 ldr r7, [r5, #0x4] */
/* @0x19a88c ldr r8, [r5, #0xc] */
/* @0x19a890 ldrb r4, [r3, #0x64] */
/* @0x19a894 b 0x19a694 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0x7c> */
/* @0x19a898 ldr r0, [sp, #0xc] */
/* @0x19a89c mov r1, #1 */
/* @0x19a8a0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x19a8a4 ldr r2, [sp, #0xc] */
/* @0x19a8a8 ldr r7, [r5, #0x10] */
/* @0x19a8ac ldr r4, [r5, #0x8] */
/* @0x19a8b0 ldr r0, [r2, #0xec] */
/* @0x19a8b4 mov r1, r7 */
/* @0x19a8b8 rsb r0, r4, r0 */
/* @0x19a8bc bl 0x318d10 <__divsi3> */
/* @0x19a8c0 ldr r1, [sp, #0xc] */
/* @0x19a8c4 ldrb r3, [r1, #0x64] */
/* @0x19a8c8 cmp r3, #0 */
/* @0x19a8cc bic r0, r0, r0, asr #31 */
/* @0x19a8d0 str r0, [sp, #0x14] */
/* @0x19a8d4 beq 0x19a6e8 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0xd0> */
/* @0x19a8d8 mov r0, r1 */
/* @0x19a8dc mov r1, #1 */
/* @0x19a8e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x19a8e4 ldr r4, [r5, #0x8] */
/* @0x19a8e8 ldr r7, [r5, #0x10] */
/* @0x19a8ec b 0x19a6e8 <_Z23Motion_Grid_AddInstanceiP9CInstanceb+0xd0> */
/* @0x19a8f0 eoreq r6, r5, r4, ror r0 */
/* @0x19a8f4 eoreq r6, r5, r4, rrx */

/* ── FUNC 0x19a8f8 · Motion_Grid_Path(int, CPath*, int, int, int, int, bool) · size=6324 · insn=1581 */
/* @0x19a8f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19a8fc sub sp, sp, #124 */
/* @0x19a900 mov r11, r1 */
/* @0x19a904 ldr r4, [pc, #0xe28] */
/* @0x19a908 ldrb r1, [sp, #0xa8] */
/* @0x19a90c cmp r0, #0 */
/* @0x19a910 add r4, pc, r4 */
/* @0x19a914 mov r10, r2 */
/* @0x19a918 mov r8, r3 */
/* @0x19a91c str r1, [sp, #0x1c] */
/* @0x19a920 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a924 ldr r3, [pc, #0xe0c] */
/* @0x19a928 ldr r3, [r4, r3] */
/* @0x19a92c ldr r3, [r3] */
/* @0x19a930 cmp r0, r3 */
/* @0x19a934 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a938 ldr r3, [pc, #0xdfc] */
/* @0x19a93c ldr r3, [r4, r3] */
/* @0x19a940 ldr r3, [r3] */
/* @0x19a944 ldr r9, [r3, r0, lsl #2] */
/* @0x19a948 cmp r9, #0 */
/* @0x19a94c moveq r0, r9 */
/* @0x19a950 beq 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */
/* @0x19a954 cmp r11, #0 */
/* @0x19a958 beq 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a95c ldr r3, [pc, #0xddc] */
/* @0x19a960 ldr r3, [r4, r3] */
/* @0x19a964 ldr r6, [r3] */
/* @0x19a968 str r3, [sp, #0x20] */
/* @0x19a96c cmp r6, #0 */
/* @0x19a970 beq 0x19ae34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x53c> */
/* @0x19a974 ldr r2, [pc, #0xdc8] */
/* @0x19a978 ldr r3, [pc, #0xdc8] */
/* @0x19a97c ldr r12, [r4, r2] */
/* @0x19a980 ldr r7, [r4, r3] */
/* @0x19a984 ldr r2, [pc, #0xdc0] */
/* @0x19a988 mov r3, #0 */
/* @0x19a98c ldr r5, [r9, #0x4] */
/* @0x19a990 ldr r2, [r4, r2] */
/* @0x19a994 cmp r10, r5 */
/* @0x19a998 str r3, [r7] */
/* @0x19a99c str r3, [r12] */
/* @0x19a9a0 str r2, [sp, #0x14] */
/* @0x19a9a4 str r3, [r2] */
/* @0x19a9a8 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9ac ldr r6, [r9, #0xc] */
/* @0x19a9b0 ldr r3, [r9, #0x14] */
/* @0x19a9b4 mla r3, r3, r6, r5 */
/* @0x19a9b8 cmp r10, r3 */
/* @0x19a9bc bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9c0 ldr r2, [r9, #0x8] */
/* @0x19a9c4 cmp r8, r2 */
/* @0x19a9c8 str r2, [sp, #0x10] */
/* @0x19a9cc blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9d0 ldr r2, [r9, #0x18] */
/* @0x19a9d4 ldr r1, [sp, #0x10] */
/* @0x19a9d8 str r2, [sp, #0x24] */
/* @0x19a9dc ldr r0, [sp, #0x24] */
/* @0x19a9e0 ldr r2, [r9, #0x10] */
/* @0x19a9e4 str r2, [sp, #0x28] */
/* @0x19a9e8 mla r2, r2, r0, r1 */
/* @0x19a9ec cmp r8, r2 */
/* @0x19a9f0 str r2, [sp, #0x30] */
/* @0x19a9f4 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19a9f8 mov r1, r6 */
/* @0x19a9fc rsb r0, r5, r10 */
/* @0x19aa00 str r3, [sp, #0xc] */
/* @0x19aa04 str r12, [sp, #0x8] */
/* @0x19aa08 bl 0x318d10 <__divsi3> */
/* @0x19aa0c ldr r2, [sp, #0x10] */
/* @0x19aa10 ldr r1, [sp, #0x28] */
/* @0x19aa14 str r0, [sp, #0x38] */
/* @0x19aa18 rsb r0, r2, r8 */
/* @0x19aa1c bl 0x318d10 <__divsi3> */
/* @0x19aa20 ldr r1, [sp, #0x38] */
/* @0x19aa24 ldr r2, [sp, #0x24] */
/* @0x19aa28 ldr r3, [sp, #0xc] */
/* @0x19aa2c mla r2, r1, r2, r0 */
/* @0x19aa30 str r0, [sp, #0x3c] */
/* @0x19aa34 str r2, [sp, #0x2c] */
/* @0x19aa38 ldr r0, [sp, #0x2c] */
/* @0x19aa3c ldr r2, [r9, #0x1c] */
/* @0x19aa40 ldr r1, [r2, r0, lsl #2] */
/* @0x19aa44 str r2, [sp, #0x34] */
/* @0x19aa48 cmp r1, #0 */
/* @0x19aa4c blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa50 ldr r1, [sp, #0xa0] */
/* @0x19aa54 cmp r1, r5 */
/* @0x19aa58 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa5c cmp r1, r3 */
/* @0x19aa60 bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa64 ldr r2, [sp, #0xa4] */
/* @0x19aa68 ldr r3, [sp, #0x10] */
/* @0x19aa6c cmp r2, r3 */
/* @0x19aa70 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa74 ldr r3, [sp, #0x30] */
/* @0x19aa78 cmp r2, r3 */
/* @0x19aa7c bge 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aa80 rsb r0, r5, r1 */
/* @0x19aa84 mov r1, r6 */
/* @0x19aa88 bl 0x318d10 <__divsi3> */
/* @0x19aa8c ldr r2, [sp, #0x10] */
/* @0x19aa90 ldr lr, [sp, #0xa4] */
/* @0x19aa94 ldr r1, [sp, #0x28] */
/* @0x19aa98 str r0, [sp, #0x40] */
/* @0x19aa9c rsb r0, r2, lr */
/* @0x19aaa0 bl 0x318d10 <__divsi3> */
/* @0x19aaa4 ldr r2, [sp, #0x24] */
/* @0x19aaa8 ldr r1, [sp, #0x40] */
/* @0x19aaac ldr r12, [sp, #0x8] */
/* @0x19aab0 mla r3, r1, r2, r0 */
/* @0x19aab4 ldr r2, [sp, #0x34] */
/* @0x19aab8 str r0, [sp, #0x44] */
/* @0x19aabc ldr r1, [r2, r3, lsl #2] */
/* @0x19aac0 cmp r1, #0 */
/* @0x19aac4 blt 0x19ae28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x530> */
/* @0x19aac8 ldr r3, [sp, #0x2c] */
/* @0x19aacc mov r1, #1 */
/* @0x19aad0 ldr r0, [sp, #0x20] */
/* @0x19aad4 str r1, [r2, r3, lsl #2] */
/* @0x19aad8 ldr r6, [r0] */
/* @0x19aadc ldr r3, [r12] */
/* @0x19aae0 ldr r0, [r7] */
/* @0x19aae4 add r2, r3, r1 */
/* @0x19aae8 sub r1, r6, #1 */
/* @0x19aaec and r2, r1, r2 */
/* @0x19aaf0 ldr r5, [r9, #0x18] */
/* @0x19aaf4 cmp r2, r0 */
/* @0x19aaf8 ldr r1, [sp, #0x38] */
/* @0x19aafc ldr r2, [sp, #0x3c] */
/* @0x19ab00 mla r5, r5, r1, r2 */
/* @0x19ab04 str r5, [sp, #0x24] */
/* @0x19ab08 beq 0x19bec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x15cc> */
/* @0x19ab0c ldr r2, [pc, #0xc64] */
/* @0x19ab10 ldr r5, [r4, r2] */
/* @0x19ab14 ldr r1, [pc, #0xc34] */
/* @0x19ab18 ldr r2, [r5] */
/* @0x19ab1c add r1, pc, r1 */
/* @0x19ab20 str r1, [sp, #0x5c] */
/* @0x19ab24 ldr r1, [sp, #0x24] */
/* @0x19ab28 ldr r0, [pc, #0xc24] */
/* @0x19ab2c str r10, [sp, #0x70] */
/* @0x19ab30 mov r10, r12 */
/* @0x19ab34 str r1, [r2, r3, lsl #2] */
/* @0x19ab38 add r0, pc, r0 */
/* @0x19ab3c ldr r2, [sp, #0x14] */
/* @0x19ab40 ldr r3, [sp, #0x20] */
/* @0x19ab44 str r0, [sp, #0x60] */
/* @0x19ab48 ldr r0, [r2] */
/* @0x19ab4c ldr r2, [r3] */
/* @0x19ab50 ldr r3, [r12] */
/* @0x19ab54 add r0, r0, #1 */
/* @0x19ab58 sub r2, r2, #1 */
/* @0x19ab5c ldr r1, [sp, #0x14] */
/* @0x19ab60 add r3, r3, #1 */
/* @0x19ab64 str r11, [sp, #0x6c] */
/* @0x19ab68 and r3, r2, r3 */
/* @0x19ab6c str r3, [r12] */
/* @0x19ab70 ldr r12, [sp, #0x20] */
/* @0x19ab74 ldr r2, [pc, #0xbdc] */
/* @0x19ab78 ldr r3, [pc, #0xbdc] */
/* @0x19ab7c add r2, pc, r2 */
/* @0x19ab80 str r0, [r1] */
/* @0x19ab84 add r3, pc, r3 */
/* @0x19ab88 str r2, [sp, #0x64] */
/* @0x19ab8c str r3, [sp, #0x68] */
/* @0x19ab90 str r8, [sp, #0x74] */
/* @0x19ab94 cmp r0, #0 */
/* @0x19ab98 beq 0x19adcc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4d4> */
/* @0x19ab9c ldr r8, [r5] */
/* @0x19aba0 sub r2, r0, #1 */
/* @0x19aba4 ldr r3, [r7] */
/* @0x19aba8 ldr r0, [r12] */
/* @0x19abac str r8, [sp, #0x2c] */
/* @0x19abb0 add r1, r3, #1 */
/* @0x19abb4 ldr lr, [sp, #0x2c] */
/* @0x19abb8 sub r0, r0, #1 */
/* @0x19abbc ldr r8, [r9, #0x18] */
/* @0x19abc0 and r1, r0, r1 */
/* @0x19abc4 ldr r0, [sp, #0x14] */
/* @0x19abc8 ldr r11, [lr, r3, lsl #2] */
/* @0x19abcc str r1, [r7] */
/* @0x19abd0 mov r1, r8 */
/* @0x19abd4 str r2, [r0] */
/* @0x19abd8 mov r0, r11 */
/* @0x19abdc str r12, [sp, #0x8] */
/* @0x19abe0 bl 0x318d10 <__divsi3> */
/* @0x19abe4 mov r1, r8 */
/* @0x19abe8 mov r4, r0 */
/* @0x19abec mov r0, r11 */
/* @0x19abf0 bl 0x318dec <__aeabi_idivmod> */
/* @0x19abf4 ldr r2, [sp, #0x44] */
/* @0x19abf8 ldr r12, [sp, #0x8] */
/* @0x19abfc mov r6, r1 */
/* @0x19ac00 ldr r1, [sp, #0x40] */
/* @0x19ac04 cmp r1, r4 */
/* @0x19ac08 cmpeq r2, r6 */
/* @0x19ac0c movne r1, #0 */
/* @0x19ac10 moveq r1, #1 */
/* @0x19ac14 str r1, [sp, #0x34] */
/* @0x19ac18 beq 0x19b77c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe84> */
/* @0x19ac1c ldr r3, [r9, #0x1c] */
/* @0x19ac20 cmp r4, #0 */
/* @0x19ac24 sub r1, r8, #1 */
/* @0x19ac28 ldr r2, [r3, r11, lsl #2] */
/* @0x19ac2c add r2, r2, #1 */
/* @0x19ac30 str r2, [sp, #0x30] */
/* @0x19ac34 ble 0x19afe4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6ec> */
/* @0x19ac38 cmp r6, r1 */
/* @0x19ac3c blt 0x19af5c <_Z16Motion_Grid_PathiP5CPathiiiib+0x664> */
/* @0x19ac40 ldr r2, [r9, #0x14] */
/* @0x19ac44 mov r11, #0 */
/* @0x19ac48 str r11, [sp, #0x50] */
/* @0x19ac4c sub r2, r2, #1 */
/* @0x19ac50 str r11, [sp, #0x20] */
/* @0x19ac54 mov r11, #0 */
/* @0x19ac58 str r11, [sp, #0x48] */
/* @0x19ac5c cmp r4, #0 */
/* @0x19ac60 ble 0x19b1cc <_Z16Motion_Grid_PathiP5CPathiiiib+0x8d4> */
/* @0x19ac64 sub r1, r4, #1 */
/* @0x19ac68 mla r1, r1, r8, r6 */
/* @0x19ac6c ldr r1, [r3, r1, lsl #2] */
/* @0x19ac70 rsbs r1, r1, #1 */
/* @0x19ac74 movlo r1, #0 */
/* @0x19ac78 str r1, [sp, #0x24] */
/* @0x19ac7c cmp r4, r2 */
/* @0x19ac80 movge r11, #0 */
/* @0x19ac84 strge r11, [sp, #0x28] */
/* @0x19ac88 bge 0x19aca4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3ac> */
/* @0x19ac8c mla r1, r4, r8, r8 */
/* @0x19ac90 add r1, r6, r1 */
/* @0x19ac94 ldr r1, [r3, r1, lsl #2] */
/* @0x19ac98 rsbs r1, r1, #1 */
/* @0x19ac9c movlo r1, #0 */
/* @0x19aca0 str r1, [sp, #0x28] */
/* @0x19aca4 cmp r6, #0 */
/* @0x19aca8 movle r1, #0 */
/* @0x19acac movgt r1, #1 */
/* @0x19acb0 cmp r4, #0 */
/* @0x19acb4 cmpgt r6, #0 */
/* @0x19acb8 ble 0x19af40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x648> */
/* @0x19acbc sub r0, r6, #1 */
/* @0x19acc0 sub r11, r4, #1 */
/* @0x19acc4 mla r11, r11, r8, r0 */
/* @0x19acc8 ldr r11, [r3, r11, lsl #2] */
/* @0x19accc cmp r11, #0 */
/* @0x19acd0 bne 0x19af50 <_Z16Motion_Grid_PathiP5CPathiiiib+0x658> */
/* @0x19acd4 ldr r11, [sp, #0x1c] */
/* @0x19acd8 str r11, [sp, #0x4c] */
/* @0x19acdc mla r0, r4, r8, r0 */
/* @0x19ace0 ldr r0, [r3, r0, lsl #2] */
/* @0x19ace4 cmp r0, #0 */
/* @0x19ace8 moveq r11, #1 */
/* @0x19acec beq 0x19acf4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3fc> */
/* @0x19acf0 mov r11, #0 */
/* @0x19acf4 cmp r4, r2 */
/* @0x19acf8 bge 0x19ad28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x430> */
/* @0x19acfc cmp r1, #0 */
/* @0x19ad00 streq r1, [sp, #0x34] */
/* @0x19ad04 beq 0x19ad28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x430> */
/* @0x19ad08 mla r2, r4, r8, r8 */
/* @0x19ad0c ldr r0, [sp, #0x1c] */
/* @0x19ad10 add r2, r6, r2 */
/* @0x19ad14 sub r2, r2, #1 */
/* @0x19ad18 ldr r2, [r3, r2, lsl #2] */
/* @0x19ad1c cmp r2, #0 */
/* @0x19ad20 movne r0, #0 */
/* @0x19ad24 str r0, [sp, #0x34] */
/* @0x19ad28 ldr r1, [sp, #0x24] */
/* @0x19ad2c cmp r1, #0 */
/* @0x19ad30 bne 0x19affc <_Z16Motion_Grid_PathiP5CPathiiiib+0x704> */
/* @0x19ad34 ldr r8, [sp, #0x28] */
/* @0x19ad38 cmp r8, #0 */
/* @0x19ad3c bne 0x19b158 <_Z16Motion_Grid_PathiP5CPathiiiib+0x860> */
/* @0x19ad40 cmp r11, #0 */
/* @0x19ad44 bne 0x19b068 <_Z16Motion_Grid_PathiP5CPathiiiib+0x770> */
/* @0x19ad48 ldr r8, [sp, #0x20] */
/* @0x19ad4c cmp r8, #0 */
/* @0x19ad50 bne 0x19b0e0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x7e8> */
/* @0x19ad54 ldr r8, [sp, #0x50] */
/* @0x19ad58 cmp r8, #0 */
/* @0x19ad5c beq 0x19ad70 <_Z16Motion_Grid_PathiP5CPathiiiib+0x478> */
/* @0x19ad60 ldr r8, [sp, #0x24] */
/* @0x19ad64 ldr r0, [sp, #0x20] */
/* @0x19ad68 tst r8, r0 */
/* @0x19ad6c bne 0x19b2e0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x9e8> */
/* @0x19ad70 ldr r8, [sp, #0x4c] */
/* @0x19ad74 cmp r8, #0 */
/* @0x19ad78 beq 0x19ad88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x490> */
/* @0x19ad7c ldr r8, [sp, #0x24] */
/* @0x19ad80 tst r8, r11 */
/* @0x19ad84 bne 0x19b36c <_Z16Motion_Grid_PathiP5CPathiiiib+0xa74> */
/* @0x19ad88 ldr r8, [sp, #0x48] */
/* @0x19ad8c cmp r8, #0 */
/* @0x19ad90 beq 0x19ada4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ac> */
/* @0x19ad94 ldr r8, [sp, #0x28] */
/* @0x19ad98 ldr r0, [sp, #0x20] */
/* @0x19ad9c tst r8, r0 */
/* @0x19ada0 bne 0x19b1d8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x8e0> */
/* @0x19ada4 ldr r8, [sp, #0x34] */
/* @0x19ada8 cmp r8, #0 */
/* @0x19adac beq 0x19adbc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4c4> */
/* @0x19adb0 ldr r8, [sp, #0x28] */
/* @0x19adb4 tst r8, r11 */
/* @0x19adb8 bne 0x19b264 <_Z16Motion_Grid_PathiP5CPathiiiib+0x96c> */
/* @0x19adbc ldr r11, [sp, #0x14] */
/* @0x19adc0 ldr r0, [r11] */
/* @0x19adc4 cmp r0, #0 */
/* @0x19adc8 bne 0x19ab9c <_Z16Motion_Grid_PathiP5CPathiiiib+0x2a4> */
/* @0x19adcc ldr r3, [r9, #0x14] */
/* @0x19add0 cmp r3, #0 */
/* @0x19add4 ble 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */
/* @0x19add8 ldr r2, [r9, #0x18] */
/* @0x19addc mov r5, #0 */
/* @0x19ade0 mov r6, r5 */
/* @0x19ade4 cmp r2, #0 */
/* @0x19ade8 ble 0x19ae18 <_Z16Motion_Grid_PathiP5CPathiiiib+0x520> */
/* @0x19adec ldr r4, [r9, #0x1c] */
/* @0x19adf0 mov r3, #0 */
/* @0x19adf4 mla r1, r2, r5, r3 */
/* @0x19adf8 add r3, r3, #1 */
/* @0x19adfc ldr r12, [r4, r1, lsl #2] */
/* @0x19ae00 cmp r12, #0 */
/* @0x19ae04 strgt r6, [r4, r1, lsl #2] */
/* @0x19ae08 ldrgt r2, [r9, #0x18] */
/* @0x19ae0c cmp r2, r3 */
/* @0x19ae10 bgt 0x19adf4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4fc> */
/* @0x19ae14 ldr r3, [r9, #0x14] */
/* @0x19ae18 add r5, r5, #1 */
/* @0x19ae1c cmp r5, r3 */
/* @0x19ae20 blt 0x19ade4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ec> */
/* @0x19ae24 b 0x19ae2c <_Z16Motion_Grid_PathiP5CPathiiiib+0x534> */
/* @0x19ae28 mov r0, #0 */
/* @0x19ae2c add sp, sp, #124 */
/* @0x19ae30 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19ae34 ldr r1, [pc, #0x924] */
/* @0x19ae38 mov r2, #212 */
/* @0x19ae3c mov r3, #1 */
/* @0x19ae40 mov r0, r6 */
/* @0x19ae44 add r1, pc, r1 */
/* @0x19ae48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19ae4c ldr r3, [sp, #0x20] */
/* @0x19ae50 ldr r1, [pc, #0x8ec] */
/* @0x19ae54 ldr r2, [r3] */
/* @0x19ae58 cmp r2, #0 */
/* @0x19ae5c str r0, [sp, #0x14] */
/* @0x19ae60 ble 0x19af28 <_Z16Motion_Grid_PathiP5CPathiiiib+0x630> */
/* @0x19ae64 ldr r3, [pc, #0x8dc] */
/* @0x19ae68 ldr r12, [r4, r1] */
/* @0x19ae6c ldr r7, [r4, r3] */
/* @0x19ae70 ldr r1, [r12] */
/* @0x19ae74 ldr r3, [r7] */
/* @0x19ae78 cmp r1, r3 */
/* @0x19ae7c bgt 0x19aedc <_Z16Motion_Grid_PathiP5CPathiiiib+0x5e4> */
/* @0x19ae80 ldr r1, [pc, #0x8f0] */
/* @0x19ae84 rsb r2, r3, r2 */
/* @0x19ae88 lsl r6, r2, #2 */
/* @0x19ae8c ldr r5, [r4, r1] */
/* @0x19ae90 mov r2, r6 */
/* @0x19ae94 ldr r1, [r5] */
/* @0x19ae98 str r12, [sp, #0x8] */
/* @0x19ae9c add r1, r1, r3, lsl #2 */
/* @0x19aea0 bl 0xb65bc <memcpy@plt> */
/* @0x19aea4 ldr r12, [sp, #0x8] */
/* @0x19aea8 ldr r3, [sp, #0x14] */
/* @0x19aeac ldr r1, [r5] */
/* @0x19aeb0 ldr r2, [r12] */
/* @0x19aeb4 add r0, r3, r6 */
/* @0x19aeb8 lsl r2, r2, #2 */
/* @0x19aebc bl 0xb65bc <memcpy@plt> */
/* @0x19aec0 ldr r12, [sp, #0x8] */
/* @0x19aec4 ldr r3, [sp, #0x14] */
/* @0x19aec8 ldr r0, [sp, #0x20] */
/* @0x19aecc str r3, [r5] */
/* @0x19aed0 mov r3, #0 */
/* @0x19aed4 str r3, [r0] */
/* @0x19aed8 b 0x19a984 <_Z16Motion_Grid_PathiP5CPathiiiib+0x8c> */
/* @0x19aedc ldr lr, [pc, #0x894] */
/* @0x19aee0 rsb r2, r3, r1 */
/* @0x19aee4 lsl r2, r2, #2 */
/* @0x19aee8 ldr r5, [r4, lr] */
/* @0x19aeec ldr r1, [r5] */
/* @0x19aef0 str r12, [sp, #0x8] */
/* @0x19aef4 add r1, r1, r3, lsl #2 */
/* @0x19aef8 bl 0xb65bc <memcpy@plt> */
/* @0x19aefc ldr r12, [sp, #0x8] */
/* @0x19af00 ldr r3, [r7] */
/* @0x19af04 ldr r0, [r5] */
/* @0x19af08 ldr r2, [r12] */
/* @0x19af0c str r6, [r7] */
/* @0x19af10 rsb r3, r3, r2 */
/* @0x19af14 str r3, [r12] */
/* @0x19af18 str r12, [sp, #0x8] */
/* @0x19af1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19af20 ldr r12, [sp, #0x8] */
/* @0x19af24 b 0x19aec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x5cc> */
/* @0x19af28 ldr r2, [pc, #0x818] */
/* @0x19af2c ldr r3, [pc, #0x844] */
/* @0x19af30 ldr r12, [r4, r1] */
/* @0x19af34 ldr r7, [r4, r2] */
/* @0x19af38 ldr r5, [r4, r3] */
/* @0x19af3c b 0x19aec4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x5cc> */
/* @0x19af40 cmp r1, #0 */
/* @0x19af44 streq r1, [sp, #0x4c] */
/* @0x19af48 beq 0x19acf0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x3f8> */
/* @0x19af4c sub r0, r6, #1 */
/* @0x19af50 mov r11, #0 */
/* @0x19af54 str r11, [sp, #0x4c] */
/* @0x19af58 b 0x19acdc <_Z16Motion_Grid_PathiP5CPathiiiib+0x3e4> */
/* @0x19af5c add r2, r6, #1 */
/* @0x19af60 sub r0, r4, #1 */
/* @0x19af64 mla r0, r0, r8, r2 */
/* @0x19af68 ldr r0, [r3, r0, lsl #2] */
/* @0x19af6c cmp r0, #0 */
/* @0x19af70 bne 0x19aff0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6f8> */
/* @0x19af74 ldr r11, [sp, #0x1c] */
/* @0x19af78 str r11, [sp, #0x50] */
/* @0x19af7c mla r2, r4, r8, r2 */
/* @0x19af80 ldr r2, [r3, r2, lsl #2] */
/* @0x19af84 cmp r2, #0 */
/* @0x19af88 ldr r2, [r9, #0x14] */
/* @0x19af8c sub r2, r2, #1 */
/* @0x19af90 bne 0x19afc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6d0> */
/* @0x19af94 cmp r4, r2 */
/* @0x19af98 mov r11, #1 */
/* @0x19af9c str r11, [sp, #0x20] */
/* @0x19afa0 bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afa4 mla r1, r4, r8, r8 */
/* @0x19afa8 add r1, r6, r1 */
/* @0x19afac add r1, r1, #1 */
/* @0x19afb0 ldr r1, [r3, r1, lsl #2] */
/* @0x19afb4 cmp r1, #0 */
/* @0x19afb8 bne 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afbc ldr r11, [sp, #0x1c] */
/* @0x19afc0 str r11, [sp, #0x48] */
/* @0x19afc4 b 0x19ac5c <_Z16Motion_Grid_PathiP5CPathiiiib+0x364> */
/* @0x19afc8 cmp r4, r2 */
/* @0x19afcc mov r11, #0 */
/* @0x19afd0 str r11, [sp, #0x20] */
/* @0x19afd4 bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afd8 cmp r6, r1 */
/* @0x19afdc bge 0x19ac54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x35c> */
/* @0x19afe0 b 0x19afa4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x6ac> */
/* @0x19afe4 cmp r6, r1 */
/* @0x19afe8 addlt r2, r6, #1 */
/* @0x19afec bge 0x19ac40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x348> */
/* @0x19aff0 mov r11, #0 */
/* @0x19aff4 str r11, [sp, #0x50] */
/* @0x19aff8 b 0x19af7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x684> */
/* @0x19affc sub r2, r4, #1 */
/* @0x19b000 ldr r0, [sp, #0x30] */
/* @0x19b004 mla r8, r2, r8, r6 */
/* @0x19b008 str r0, [r3, r8, lsl #2] */
/* @0x19b00c ldr r3, [r10] */
/* @0x19b010 ldr r1, [r12] */
/* @0x19b014 add r0, r3, #1 */
/* @0x19b018 sub r8, r1, #1 */
/* @0x19b01c and r0, r8, r0 */
/* @0x19b020 ldr r8, [r7] */
/* @0x19b024 cmp r0, r8 */
/* @0x19b028 ldr r0, [r9, #0x18] */
/* @0x19b02c mla r8, r0, r2, r6 */
/* @0x19b030 ldrne r2, [sp, #0x2c] */
/* @0x19b034 beq 0x19b4c4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xbcc> */
/* @0x19b038 str r8, [r2, r3, lsl #2] */
/* @0x19b03c ldr r8, [sp, #0x14] */
/* @0x19b040 ldr r2, [r10] */
/* @0x19b044 ldr r1, [r12] */
/* @0x19b048 ldr r3, [r8] */
/* @0x19b04c add r2, r2, #1 */
/* @0x19b050 sub r1, r1, #1 */
/* @0x19b054 and r2, r1, r2 */
/* @0x19b058 add r3, r3, #1 */
/* @0x19b05c str r2, [r10] */
/* @0x19b060 str r3, [r8] */
/* @0x19b064 b 0x19ad34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x43c> */
/* @0x19b068 ldr r2, [r9, #0x18] */
/* @0x19b06c ldr r3, [r9, #0x1c] */
/* @0x19b070 ldr r8, [sp, #0x30] */
/* @0x19b074 mla r2, r2, r4, r6 */
/* @0x19b078 sub r2, r2, #-1073741823 */
/* @0x19b07c str r8, [r3, r2, lsl #2] */
/* @0x19b080 ldr r8, [r9, #0x18] */
/* @0x19b084 ldr r3, [r10] */
/* @0x19b088 ldr r2, [r12] */
/* @0x19b08c add r1, r3, #1 */
/* @0x19b090 sub r0, r2, #1 */
/* @0x19b094 and r1, r0, r1 */
/* @0x19b098 ldr r0, [r7] */
/* @0x19b09c mla r8, r8, r4, r6 */
/* @0x19b0a0 cmp r1, r0 */
/* @0x19b0a4 sub r8, r8, #1 */
/* @0x19b0a8 beq 0x19b664 <_Z16Motion_Grid_PathiP5CPathiiiib+0xd6c> */
/* @0x19b0ac ldr r2, [r5] */
/* @0x19b0b0 str r8, [r2, r3, lsl #2] */
/* @0x19b0b4 ldr r8, [sp, #0x14] */
/* @0x19b0b8 ldr r2, [r10] */
/* @0x19b0bc ldr r1, [r12] */
/* @0x19b0c0 ldr r3, [r8] */
/* @0x19b0c4 add r2, r2, #1 */
/* @0x19b0c8 sub r1, r1, #1 */
/* @0x19b0cc and r2, r1, r2 */
/* @0x19b0d0 add r3, r3, #1 */
/* @0x19b0d4 str r2, [r10] */
/* @0x19b0d8 str r3, [r8] */
/* @0x19b0dc b 0x19ad48 <_Z16Motion_Grid_PathiP5CPathiiiib+0x450> */
/* @0x19b0e0 ldr r2, [r9, #0x18] */
/* @0x19b0e4 ldr r3, [r9, #0x1c] */
/* @0x19b0e8 ldr r8, [sp, #0x30] */
/* @0x19b0ec mla r2, r2, r4, r6 */
/* @0x19b0f0 add r2, r2, #1 */
/* @0x19b0f4 str r8, [r3, r2, lsl #2] */
/* @0x19b0f8 ldr r8, [r9, #0x18] */
/* @0x19b0fc ldr r3, [r10] */
/* @0x19b100 ldr r2, [r12] */
/* @0x19b104 add r1, r3, #1 */
/* @0x19b108 sub r0, r2, #1 */
/* @0x19b10c and r1, r0, r1 */
/* @0x19b110 ldr r0, [r7] */
/* @0x19b114 mla r8, r8, r4, r6 */
/* @0x19b118 cmp r1, r0 */
/* @0x19b11c add r8, r8, #1 */
/* @0x19b120 beq 0x19b594 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc9c> */
/* @0x19b124 ldr r2, [r5] */
/* @0x19b128 str r8, [r2, r3, lsl #2] */
/* @0x19b12c ldr r8, [sp, #0x14] */
/* @0x19b130 ldr r2, [r10] */
/* @0x19b134 ldr r1, [r12] */
/* @0x19b138 ldr r3, [r8] */
/* @0x19b13c add r2, r2, #1 */
/* @0x19b140 sub r1, r1, #1 */
/* @0x19b144 and r2, r1, r2 */
/* @0x19b148 add r3, r3, #1 */
/* @0x19b14c str r2, [r10] */
/* @0x19b150 str r3, [r8] */
/* @0x19b154 b 0x19ad54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x45c> */
/* @0x19b158 ldr r2, [r9, #0x18] */
/* @0x19b15c add r8, r4, #1 */
/* @0x19b160 ldr r3, [r9, #0x1c] */
/* @0x19b164 ldr r0, [sp, #0x30] */
/* @0x19b168 mla r2, r2, r8, r6 */
/* @0x19b16c str r0, [r3, r2, lsl #2] */
/* @0x19b170 ldr r3, [r10] */
/* @0x19b174 ldr r2, [r12] */
/* @0x19b178 add r1, r3, #1 */
/* @0x19b17c sub r0, r2, #1 */
/* @0x19b180 and r1, r0, r1 */
/* @0x19b184 ldr r0, [r7] */
/* @0x19b188 cmp r1, r0 */
/* @0x19b18c ldr r1, [r9, #0x18] */
/* @0x19b190 mla r8, r1, r8, r6 */
/* @0x19b194 beq 0x19b3f8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xb00> */
/* @0x19b198 ldr r2, [r5] */
/* @0x19b19c str r8, [r2, r3, lsl #2] */
/* @0x19b1a0 ldr r8, [sp, #0x14] */
/* @0x19b1a4 ldr r2, [r10] */
/* @0x19b1a8 ldr r1, [r12] */
/* @0x19b1ac ldr r3, [r8] */
/* @0x19b1b0 add r2, r2, #1 */
/* @0x19b1b4 sub r1, r1, #1 */
/* @0x19b1b8 and r2, r1, r2 */
/* @0x19b1bc add r3, r3, #1 */
/* @0x19b1c0 str r2, [r10] */
/* @0x19b1c4 str r3, [r8] */
/* @0x19b1c8 b 0x19ad40 <_Z16Motion_Grid_PathiP5CPathiiiib+0x448> */
/* @0x19b1cc mov r11, #0 */
/* @0x19b1d0 str r11, [sp, #0x24] */
/* @0x19b1d4 b 0x19ac7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x384> */
/* @0x19b1d8 ldr r2, [r9, #0x18] */
/* @0x19b1dc add r1, r4, #1 */
/* @0x19b1e0 ldr r3, [r9, #0x1c] */
/* @0x19b1e4 ldr r8, [sp, #0x30] */
/* @0x19b1e8 mla r2, r2, r1, r6 */
/* @0x19b1ec add r2, r2, #1 */
/* @0x19b1f0 str r8, [r3, r2, lsl #2] */
/* @0x19b1f4 ldr r0, [r9, #0x18] */
/* @0x19b1f8 ldr r3, [r10] */
/* @0x19b1fc ldr r2, [r12] */
/* @0x19b200 mla r0, r0, r1, r6 */
/* @0x19b204 sub r8, r2, #1 */
/* @0x19b208 ldr r1, [r7] */
/* @0x19b20c str r0, [sp, #0x10] */
/* @0x19b210 add r0, r3, #1 */
/* @0x19b214 and r0, r8, r0 */
/* @0x19b218 ldr r8, [sp, #0x10] */
/* @0x19b21c cmp r0, r1 */
/* @0x19b220 add r8, r8, #1 */
/* @0x19b224 str r8, [sp, #0x20] */
/* @0x19b228 beq 0x19bd54 <_Z16Motion_Grid_PathiP5CPathiiiib+0x145c> */
/* @0x19b22c ldr r2, [r5] */
/* @0x19b230 ldr r8, [sp, #0x20] */
/* @0x19b234 str r8, [r2, r3, lsl #2] */
/* @0x19b238 ldr r8, [sp, #0x14] */
/* @0x19b23c ldr r2, [r10] */
/* @0x19b240 ldr r1, [r12] */
/* @0x19b244 ldr r3, [r8] */
/* @0x19b248 add r2, r2, #1 */
/* @0x19b24c sub r1, r1, #1 */
/* @0x19b250 and r2, r1, r2 */
/* @0x19b254 add r3, r3, #1 */
/* @0x19b258 str r2, [r10] */
/* @0x19b25c str r3, [r8] */
/* @0x19b260 b 0x19ada4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x4ac> */
/* @0x19b264 ldr r2, [r9, #0x18] */
/* @0x19b268 add r4, r4, #1 */
/* @0x19b26c ldr r3, [r9, #0x1c] */
/* @0x19b270 ldr r11, [sp, #0x30] */
/* @0x19b274 mla r2, r2, r4, r6 */
/* @0x19b278 sub r2, r2, #-1073741823 */
/* @0x19b27c str r11, [r3, r2, lsl #2] */
/* @0x19b280 ldr r1, [r9, #0x18] */
/* @0x19b284 ldr r3, [r10] */
/* @0x19b288 ldr r2, [r12] */
/* @0x19b28c mla r6, r1, r4, r6 */
/* @0x19b290 sub r0, r2, #1 */
/* @0x19b294 add r1, r3, #1 */
/* @0x19b298 ldr r4, [r7] */
/* @0x19b29c and r1, r0, r1 */
/* @0x19b2a0 cmp r1, r4 */
/* @0x19b2a4 sub r8, r6, #1 */
/* @0x19b2a8 beq 0x19bb34 <_Z16Motion_Grid_PathiP5CPathiiiib+0x123c> */
/* @0x19b2ac ldr r2, [r5] */
/* @0x19b2b0 str r8, [r2, r3, lsl #2] */
/* @0x19b2b4 ldr r8, [sp, #0x14] */
/* @0x19b2b8 ldr r3, [r10] */
/* @0x19b2bc ldr r2, [r12] */
/* @0x19b2c0 ldr r0, [r8] */
/* @0x19b2c4 add r3, r3, #1 */
/* @0x19b2c8 sub r2, r2, #1 */
/* @0x19b2cc add r0, r0, #1 */
/* @0x19b2d0 and r3, r2, r3 */
/* @0x19b2d4 str r0, [r8] */
/* @0x19b2d8 str r3, [r10] */
/* @0x19b2dc b 0x19ab94 <_Z16Motion_Grid_PathiP5CPathiiiib+0x29c> */
/* @0x19b2e0 ldr r2, [r9, #0x18] */
/* @0x19b2e4 sub r1, r4, #1 */
/* @0x19b2e8 ldr r3, [r9, #0x1c] */
/* @0x19b2ec ldr r8, [sp, #0x30] */
/* @0x19b2f0 mla r2, r2, r1, r6 */
/* @0x19b2f4 add r2, r2, #1 */
/* @0x19b2f8 str r8, [r3, r2, lsl #2] */
/* @0x19b2fc ldr r0, [r9, #0x18] */
/* @0x19b300 ldr r3, [r10] */
/* @0x19b304 ldr r2, [r12] */
/* @0x19b308 mla r0, r0, r1, r6 */
/* @0x19b30c sub r8, r2, #1 */
/* @0x19b310 ldr r1, [r7] */
/* @0x19b314 str r0, [sp, #0x10] */
/* @0x19b318 add r0, r3, #1 */
/* @0x19b31c and r0, r8, r0 */
/* @0x19b320 ldr r8, [sp, #0x10] */
/* @0x19b324 cmp r0, r1 */
/* @0x19b328 add r8, r8, #1 */
/* @0x19b32c str r8, [sp, #0x2c] */
/* @0x19b330 beq 0x19bbdc <_Z16Motion_Grid_PathiP5CPathiiiib+0x12e4> */
/* @0x19b334 ldr r2, [r5] */
/* @0x19b338 ldr r8, [sp, #0x2c] */
/* @0x19b33c str r8, [r2, r3, lsl #2] */
/* @0x19b340 ldr r8, [sp, #0x14] */
/* @0x19b344 ldr r2, [r10] */
/* @0x19b348 ldr r1, [r12] */
/* @0x19b34c ldr r3, [r8] */
/* @0x19b350 add r2, r2, #1 */
/* @0x19b354 sub r1, r1, #1 */
/* @0x19b358 and r2, r1, r2 */
/* @0x19b35c add r3, r3, #1 */
/* @0x19b360 str r2, [r10] */
/* @0x19b364 str r3, [r8] */
/* @0x19b368 b 0x19ad70 <_Z16Motion_Grid_PathiP5CPathiiiib+0x478> */
/* @0x19b36c ldr r2, [r9, #0x18] */
/* @0x19b370 sub r1, r4, #1 */
/* @0x19b374 ldr r3, [r9, #0x1c] */
/* @0x19b378 ldr r8, [sp, #0x30] */
/* @0x19b37c mla r2, r2, r1, r6 */
/* @0x19b380 sub r2, r2, #-1073741823 */
/* @0x19b384 str r8, [r3, r2, lsl #2] */
/* @0x19b388 ldr r0, [r9, #0x18] */
/* @0x19b38c ldr r3, [r10] */
/* @0x19b390 ldr r2, [r12] */
/* @0x19b394 mla r0, r0, r1, r6 */
/* @0x19b398 sub r8, r2, #1 */
/* @0x19b39c ldr r1, [r7] */
/* @0x19b3a0 str r0, [sp, #0x10] */
/* @0x19b3a4 add r0, r3, #1 */
/* @0x19b3a8 and r0, r8, r0 */
/* @0x19b3ac ldr r8, [sp, #0x10] */
/* @0x19b3b0 cmp r0, r1 */
/* @0x19b3b4 sub r8, r8, #1 */
/* @0x19b3b8 str r8, [sp, #0x24] */
/* @0x19b3bc beq 0x19bc98 <_Z16Motion_Grid_PathiP5CPathiiiib+0x13a0> */
/* @0x19b3c0 ldr r2, [r5] */
/* @0x19b3c4 ldr r8, [sp, #0x24] */
/* @0x19b3c8 str r8, [r2, r3, lsl #2] */
/* @0x19b3cc ldr r8, [sp, #0x14] */
/* @0x19b3d0 ldr r2, [r10] */
/* @0x19b3d4 ldr r1, [r12] */
/* @0x19b3d8 ldr r3, [r8] */
/* @0x19b3dc add r2, r2, #1 */
/* @0x19b3e0 sub r1, r1, #1 */
/* @0x19b3e4 and r2, r1, r2 */
/* @0x19b3e8 add r3, r3, #1 */
/* @0x19b3ec str r2, [r10] */
/* @0x19b3f0 str r3, [r8] */
/* @0x19b3f4 b 0x19ad88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x490> */
/* @0x19b3f8 cmp r2, #0 */
/* @0x19b3fc ldr r1, [pc, #0x360] */
/* @0x19b400 lslge r2, r2, #1 */
/* @0x19b404 str r12, [sp, #0x8] */
/* @0x19b408 movlt r2, #4096 */
/* @0x19b40c str r2, [sp, #0x2c] */
/* @0x19b410 ldr r3, [sp, #0x2c] */
/* @0x19b414 mov r2, #212 */
/* @0x19b418 add r1, pc, r1 */
/* @0x19b41c lsl r0, r3, #2 */
/* @0x19b420 mov r3, #1 */
/* @0x19b424 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b428 ldr r12, [sp, #0x8] */
/* @0x19b42c ldr r2, [r12] */
/* @0x19b430 cmp r2, #0 */
/* @0x19b434 str r0, [sp, #0x54] */
/* @0x19b438 ble 0x19b4ac <_Z16Motion_Grid_PathiP5CPathiiiib+0xbb4> */
/* @0x19b43c ldr r3, [r10] */
/* @0x19b440 ldr r1, [r7] */
/* @0x19b444 cmp r3, r1 */
/* @0x19b448 bgt 0x19be10 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1518> */
/* @0x19b44c rsb r2, r1, r2 */
/* @0x19b450 str r2, [sp, #0x58] */
/* @0x19b454 ldr lr, [sp, #0x58] */
/* @0x19b458 ldr r2, [r5] */
/* @0x19b45c str r12, [sp, #0x8] */
/* @0x19b460 lsl r3, lr, #2 */
/* @0x19b464 add r1, r2, r1, lsl #2 */
/* @0x19b468 str r3, [sp, #0xc] */
/* @0x19b46c mov r2, r3 */
/* @0x19b470 bl 0xb65bc <memcpy@plt> */
/* @0x19b474 ldr r2, [r10] */
/* @0x19b478 ldr r3, [sp, #0xc] */
/* @0x19b47c ldr r1, [sp, #0x54] */
/* @0x19b480 lsl r2, r2, #2 */
/* @0x19b484 add r0, r1, r3 */
/* @0x19b488 ldr r1, [r5] */
/* @0x19b48c bl 0xb65bc <memcpy@plt> */
/* @0x19b490 ldr r12, [sp, #0x8] */
/* @0x19b494 ldr r3, [r10] */
/* @0x19b498 mov r2, #0 */
/* @0x19b49c ldr r0, [sp, #0x58] */
/* @0x19b4a0 str r2, [r7] */
/* @0x19b4a4 add r3, r0, r3 */
/* @0x19b4a8 str r3, [r10] */
/* @0x19b4ac ldr r2, [sp, #0x54] */
/* @0x19b4b0 ldr r1, [sp, #0x2c] */
/* @0x19b4b4 ldr r3, [r10] */
/* @0x19b4b8 str r2, [r5] */
/* @0x19b4bc str r1, [r12] */
/* @0x19b4c0 b 0x19b19c <_Z16Motion_Grid_PathiP5CPathiiiib+0x8a4> */
/* @0x19b4c4 cmp r1, #0 */
/* @0x19b4c8 mov r3, #1 */
/* @0x19b4cc lslge r1, r1, #1 */
/* @0x19b4d0 str r12, [sp, #0x8] */
/* @0x19b4d4 movlt r1, #4096 */
/* @0x19b4d8 str r1, [sp, #0x2c] */
/* @0x19b4dc ldr r2, [sp, #0x2c] */
/* @0x19b4e0 ldr r1, [pc, #0x280] */
/* @0x19b4e4 lsl r0, r2, #2 */
/* @0x19b4e8 add r1, pc, r1 */
/* @0x19b4ec mov r2, #212 */
/* @0x19b4f0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b4f4 ldr r12, [sp, #0x8] */
/* @0x19b4f8 ldr r2, [r12] */
/* @0x19b4fc cmp r2, #0 */
/* @0x19b500 str r0, [sp, #0x54] */
/* @0x19b504 ble 0x19b578 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc80> */
/* @0x19b508 ldr r3, [r10] */
/* @0x19b50c ldr r1, [r7] */
/* @0x19b510 cmp r3, r1 */
/* @0x19b514 bgt 0x19be4c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1554> */
/* @0x19b518 rsb r2, r1, r2 */
/* @0x19b51c str r2, [sp, #0x58] */
/* @0x19b520 ldr lr, [sp, #0x58] */
/* @0x19b524 ldr r2, [r5] */
/* @0x19b528 str r12, [sp, #0x8] */
/* @0x19b52c lsl r3, lr, #2 */
/* @0x19b530 add r1, r2, r1, lsl #2 */
/* @0x19b534 str r3, [sp, #0xc] */
/* @0x19b538 mov r2, r3 */
/* @0x19b53c bl 0xb65bc <memcpy@plt> */
/* @0x19b540 ldr r2, [r10] */
/* @0x19b544 ldr r3, [sp, #0xc] */
/* @0x19b548 ldr r1, [sp, #0x54] */
/* @0x19b54c lsl r2, r2, #2 */
/* @0x19b550 add r0, r1, r3 */
/* @0x19b554 ldr r1, [r5] */
/* @0x19b558 bl 0xb65bc <memcpy@plt> */
/* @0x19b55c ldr r12, [sp, #0x8] */
/* @0x19b560 ldr r3, [r10] */
/* @0x19b564 mov r2, #0 */
/* @0x19b568 ldr r0, [sp, #0x58] */
/* @0x19b56c str r2, [r7] */
/* @0x19b570 add r3, r0, r3 */
/* @0x19b574 str r3, [r10] */
/* @0x19b578 ldr r3, [sp, #0x54] */
/* @0x19b57c ldr r0, [sp, #0x2c] */
/* @0x19b580 str r3, [r5] */
/* @0x19b584 mov r2, r3 */
/* @0x19b588 str r0, [r12] */
/* @0x19b58c ldr r3, [r10] */
/* @0x19b590 b 0x19b038 <_Z16Motion_Grid_PathiP5CPathiiiib+0x740> */
/* @0x19b594 cmp r2, #0 */
/* @0x19b598 mov r3, #1 */
/* @0x19b59c lslge r2, r2, #1 */
/* @0x19b5a0 strge r2, [sp, #0x2c] */
/* @0x19b5a4 movlt r1, #4096 */
/* @0x19b5a8 strlt r1, [sp, #0x2c] */
/* @0x19b5ac ldr r2, [sp, #0x2c] */
/* @0x19b5b0 ldr r1, [pc, #0x1b4] */
/* @0x19b5b4 str r12, [sp, #0x8] */
/* @0x19b5b8 lsl r0, r2, #2 */
/* @0x19b5bc add r1, pc, r1 */
/* @0x19b5c0 mov r2, #212 */
/* @0x19b5c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b5c8 ldr r12, [sp, #0x8] */
/* @0x19b5cc ldr r2, [r12] */
/* @0x19b5d0 cmp r2, #0 */
/* @0x19b5d4 str r0, [sp, #0x54] */
/* @0x19b5d8 ble 0x19b64c <_Z16Motion_Grid_PathiP5CPathiiiib+0xd54> */
/* @0x19b5dc ldr r3, [r10] */
/* @0x19b5e0 ldr r1, [r7] */
/* @0x19b5e4 cmp r3, r1 */
/* @0x19b5e8 bgt 0x19be88 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1590> */
/* @0x19b5ec rsb r2, r1, r2 */
/* @0x19b5f0 str r2, [sp, #0x58] */
/* @0x19b5f4 ldr lr, [sp, #0x58] */
/* @0x19b5f8 ldr r2, [r5] */
/* @0x19b5fc str r12, [sp, #0x8] */
/* @0x19b600 lsl r3, lr, #2 */
/* @0x19b604 add r1, r2, r1, lsl #2 */
/* @0x19b608 str r3, [sp, #0xc] */
/* @0x19b60c mov r2, r3 */
/* @0x19b610 bl 0xb65bc <memcpy@plt> */
/* @0x19b614 ldr r2, [r10] */
/* @0x19b618 ldr r3, [sp, #0xc] */
/* @0x19b61c ldr r1, [sp, #0x54] */
/* @0x19b620 lsl r2, r2, #2 */
/* @0x19b624 add r0, r1, r3 */
/* @0x19b628 ldr r1, [r5] */
/* @0x19b62c bl 0xb65bc <memcpy@plt> */
/* @0x19b630 ldr r12, [sp, #0x8] */
/* @0x19b634 ldr r3, [r10] */
/* @0x19b638 mov r2, #0 */
/* @0x19b63c ldr r0, [sp, #0x58] */
/* @0x19b640 str r2, [r7] */
/* @0x19b644 add r3, r0, r3 */
/* @0x19b648 str r3, [r10] */
/* @0x19b64c ldr r2, [sp, #0x54] */
/* @0x19b650 ldr r1, [sp, #0x2c] */
/* @0x19b654 ldr r3, [r10] */
/* @0x19b658 str r2, [r5] */
/* @0x19b65c str r1, [r12] */
/* @0x19b660 b 0x19b128 <_Z16Motion_Grid_PathiP5CPathiiiib+0x830> */
/* @0x19b664 cmp r2, #0 */
/* @0x19b668 mov r3, #1 */
/* @0x19b66c lslge r2, r2, #1 */
/* @0x19b670 strge r2, [sp, #0x2c] */
/* @0x19b674 movlt r1, #4096 */
/* @0x19b678 strlt r1, [sp, #0x2c] */
/* @0x19b67c ldr r2, [sp, #0x2c] */
/* @0x19b680 ldr r1, [pc, #0xe8] */
/* @0x19b684 str r12, [sp, #0x8] */
/* @0x19b688 lsl r0, r2, #2 */
/* @0x19b68c add r1, pc, r1 */
/* @0x19b690 mov r2, #212 */
/* @0x19b694 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19b698 ldr r12, [sp, #0x8] */
/* @0x19b69c ldr r2, [r12] */
/* @0x19b6a0 cmp r2, #0 */
/* @0x19b6a4 str r0, [sp, #0x54] */
/* @0x19b6a8 ble 0x19b71c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe24> */
/* @0x19b6ac ldr r3, [r10] */
/* @0x19b6b0 ldr r1, [r7] */
/* @0x19b6b4 cmp r3, r1 */
/* @0x19b6b8 bgt 0x19bf94 <_Z16Motion_Grid_PathiP5CPathiiiib+0x169c> */
/* @0x19b6bc rsb r2, r1, r2 */
/* @0x19b6c0 str r2, [sp, #0x58] */
/* @0x19b6c4 ldr lr, [sp, #0x58] */
/* @0x19b6c8 ldr r2, [r5] */
/* @0x19b6cc str r12, [sp, #0x8] */
/* @0x19b6d0 lsl r3, lr, #2 */
/* @0x19b6d4 add r1, r2, r1, lsl #2 */
/* @0x19b6d8 str r3, [sp, #0xc] */
/* @0x19b6dc mov r2, r3 */
/* @0x19b6e0 bl 0xb65bc <memcpy@plt> */
/* @0x19b6e4 ldr r2, [r10] */
/* @0x19b6e8 ldr r3, [sp, #0xc] */
/* @0x19b6ec ldr r1, [sp, #0x54] */
/* @0x19b6f0 lsl r2, r2, #2 */
/* @0x19b6f4 add r0, r1, r3 */
/* @0x19b6f8 ldr r1, [r5] */
/* @0x19b6fc bl 0xb65bc <memcpy@plt> */
/* @0x19b700 ldr r12, [sp, #0x8] */
/* @0x19b704 ldr r3, [r10] */
/* @0x19b708 mov r2, #0 */
/* @0x19b70c ldr r0, [sp, #0x58] */
/* @0x19b710 str r2, [r7] */
/* @0x19b714 add r3, r0, r3 */
/* @0x19b718 str r3, [r10] */
/* @0x19b71c ldr r2, [sp, #0x54] */
/* @0x19b720 ldr r1, [sp, #0x2c] */
/* @0x19b724 ldr r3, [r10] */
/* @0x19b728 str r2, [r5] */
/* @0x19b72c str r1, [r12] */
/* @0x19b730 b 0x19b0b0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x7b8> */
/* @0x19b734 eoreq r7, r5, r0, asr #6 */
/* @0x19b738 .word 0xffffea5c */
/* @0x19b73c .word 0xffffea60 */
/* @0x19b740 .word 0xffffea64 */
/* @0x19b744 .word 0xffffea68 */
/* @0x19b748 .word 0xffffea6c */
/* @0x19b74c .word 0xffffea70 */
/* @0x19b750 andseq r2, r11, r4, lsr r2 */
/* @0x19b754 andseq r2, r11, r8, lsl r2 */
/* @0x19b758 ldrsbeq r2, [r11], -r4 */
/* @0x19b75c andseq r2, r11, r12, asr #3 */
/* @0x19b760 andseq r1, r11, r12, lsl #30 */
/* @0x19b764 andseq r1, r11, r8, lsr r9 */
/* @0x19b768 andseq r1, r11, r8, ror #16 */
/* @0x19b76c mulseq r11, r4, r7 */
/* @0x19b770 andseq r1, r11, r4, asr #13 */
/* @0x19b774 andseq r0, r11, r8, ror lr */
/* @0x19b778 .word 0xffffea74 */
/* @0x19b77c ldr r11, [sp, #0x6c] */
/* @0x19b780 ldr r10, [sp, #0x70] */
/* @0x19b784 ldr r8, [sp, #0x74] */
/* @0x19b788 mov r0, r11 */
/* @0x19b78c bl 0x1a6f98 <_ZN5CPath5ClearEv> */
/* @0x19b790 mov r0, r11 */
/* @0x19b794 mov r1, #0 */
/* @0x19b798 bl 0x1a6e64 <_ZN5CPath7SetKindEi> */
/* @0x19b79c mov r0, r11 */
/* @0x19b7a0 mov r1, #0 */
/* @0x19b7a4 bl 0x1a6e78 <_ZN5CPath9SetClosedEb> */
/* @0x19b7a8 vldr s15, [sp, #160] */
/* @0x19b7ac vldr s11, [sp, #164] */
/* @0x19b7b0 vcvt.f32.s32 s15, s15 */
/* @0x19b7b4 mov r0, r11 */
/* @0x19b7b8 mov r3, #0 */
/* @0x19b7bc movt r3, #0x42c8 */
/* @0x19b7c0 vcvt.f32.s32 s11, s11 */
/* @0x19b7c4 vmov r1, s15 */
/* @0x19b7c8 vmov r2, s11 */
/* @0x19b7cc bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19b7d0 ldr r4, [sp, #0x40] */
/* @0x19b7d4 ldr r5, [sp, #0x44] */
/* @0x19b7d8 str r11, [sp, #0x28] */
/* @0x19b7dc str r10, [sp, #0x30] */
/* @0x19b7e0 str r8, [sp, #0x34] */
/* @0x19b7e4 ldr r8, [sp, #0x38] */
/* @0x19b7e8 ldr r10, [sp, #0x3c] */
/* @0x19b7ec subs r12, r8, r4 */
/* @0x19b7f0 movne r12, #1 */
/* @0x19b7f4 subs r6, r10, r5 */
/* @0x19b7f8 movne r6, #1 */
/* @0x19b7fc orrs r11, r6, r12 */
/* @0x19b800 beq 0x19baf0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11f8> */
/* @0x19b804 ldr r1, [r9, #0x18] */
/* @0x19b808 cmp r4, #0 */
/* @0x19b80c ldr r2, [r9, #0x1c] */
/* @0x19b810 sub r8, r1, #1 */
/* @0x19b814 mul r0, r4, r1 */
/* @0x19b818 add lr, r0, r5 */
/* @0x19b81c ldr r7, [r2, lr, lsl #2] */
/* @0x19b820 ble 0x19ba80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1188> */
/* @0x19b824 cmp r5, r8 */
/* @0x19b828 blt 0x19b9fc <_Z16Motion_Grid_PathiP5CPathiiiib+0x1104> */
/* @0x19b82c ldr lr, [r9, #0x14] */
/* @0x19b830 mov r3, #0 */
/* @0x19b834 str r3, [sp, #0x24] */
/* @0x19b838 sub lr, lr, #1 */
/* @0x19b83c str r3, [sp, #0x20] */
/* @0x19b840 mov r3, #0 */
/* @0x19b844 str r3, [sp, #0x14] */
/* @0x19b848 cmp r4, #0 */
/* @0x19b84c ble 0x19ba98 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11a0> */
/* @0x19b850 rsb r8, r1, r0 */
/* @0x19b854 sub r3, r7, #1 */
/* @0x19b858 add r8, r5, r8 */
/* @0x19b85c ldr r8, [r2, r8, lsl #2] */
/* @0x19b860 subs r11, r8, r3 */
/* @0x19b864 rsbs r3, r11, #0 */
/* @0x19b868 adcs r3, r3, r11 */
/* @0x19b86c str r3, [sp, #0x10] */
/* @0x19b870 cmp r4, lr */
/* @0x19b874 movge r11, #0 */
/* @0x19b878 strge r11, [sp, #0x18] */
/* @0x19b87c bge 0x19b8a0 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfa8> */
/* @0x19b880 add r8, r1, r0 */
/* @0x19b884 sub r3, r7, #1 */
/* @0x19b888 add r8, r8, r5 */
/* @0x19b88c ldr r8, [r2, r8, lsl #2] */
/* @0x19b890 subs r10, r8, r3 */
/* @0x19b894 rsbs r3, r10, #0 */
/* @0x19b898 adcs r3, r3, r10 */
/* @0x19b89c str r3, [sp, #0x18] */
/* @0x19b8a0 cmp r5, #0 */
/* @0x19b8a4 movle r8, #0 */
/* @0x19b8a8 movgt r8, #1 */
/* @0x19b8ac cmp r4, #0 */
/* @0x19b8b0 cmpgt r5, #0 */
/* @0x19b8b4 ble 0x19b9e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x10ec> */
/* @0x19b8b8 sub r10, r5, #1 */
/* @0x19b8bc rsb r11, r1, r0 */
/* @0x19b8c0 add r11, r11, r10 */
/* @0x19b8c4 sub r3, r7, #1 */
/* @0x19b8c8 ldr r11, [r2, r11, lsl #2] */
/* @0x19b8cc cmp r11, r3 */
/* @0x19b8d0 beq 0x19bac8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11d0> */
/* @0x19b8d4 mov r11, #0 */
/* @0x19b8d8 add r10, r0, r10 */
/* @0x19b8dc ldr r10, [r2, r10, lsl #2] */
/* @0x19b8e0 cmp r10, r3 */
/* @0x19b8e4 beq 0x19bac0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11c8> */
/* @0x19b8e8 mov r3, #0 */
/* @0x19b8ec cmp r4, lr */
/* @0x19b8f0 movge r2, #0 */
/* @0x19b8f4 bge 0x19b924 <_Z16Motion_Grid_PathiP5CPathiiiib+0x102c> */
/* @0x19b8f8 cmp r8, #0 */
/* @0x19b8fc moveq r2, r8 */
/* @0x19b900 beq 0x19b924 <_Z16Motion_Grid_PathiP5CPathiiiib+0x102c> */
/* @0x19b904 add r1, r1, r0 */
/* @0x19b908 sub r7, r7, #1 */
/* @0x19b90c add r1, r1, r5 */
/* @0x19b910 sub r1, r1, #1 */
/* @0x19b914 ldr r2, [r2, r1, lsl #2] */
/* @0x19b918 subs r1, r2, r7 */
/* @0x19b91c rsbs r2, r1, #0 */
/* @0x19b920 adcs r2, r2, r1 */
/* @0x19b924 ldr lr, [sp, #0x10] */
/* @0x19b928 cmp lr, #0 */
/* @0x19b92c beq 0x19b9c4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x10cc> */
/* @0x19b930 ldr r8, [sp, #0x38] */
/* @0x19b934 sub r4, r4, #1 */
/* @0x19b938 subs r12, r8, r4 */
/* @0x19b93c movne r12, #1 */
/* @0x19b940 orrs r12, r6, r12 */
/* @0x19b944 beq 0x19b7e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xeec> */
/* @0x19b948 ldr r2, [r9, #0xc] */
/* @0x19b94c vldr s11, [r9, #4] */
/* @0x19b950 ldr r3, [r9, #0x10] */
/* @0x19b954 vcvt.f32.s32 s10, s11 */
/* @0x19b958 vldr s13, [r9, #8] */
/* @0x19b95c ldr r0, [sp, #0x28] */
/* @0x19b960 mul lr, r2, r4 */
/* @0x19b964 add r2, r2, r2, lsr #31 */
/* @0x19b968 mul r1, r3, r5 */
/* @0x19b96c add r3, r3, r3, lsr #31 */
/* @0x19b970 asr r2, r2, #1 */
/* @0x19b974 vcvt.f32.s32 s11, s13 */
/* @0x19b978 asr r3, r3, #1 */
/* @0x19b97c vmov s12, lr */
/* @0x19b980 vmov s15, r3 */
/* @0x19b984 mov r3, #0 */
/* @0x19b988 vmov s14, r1 */
/* @0x19b98c movt r3, #0x42c8 */
/* @0x19b990 vcvt.f32.s32 s12, s12 */
/* @0x19b994 vcvt.f32.s32 s14, s14 */
/* @0x19b998 vadd.f32 s12, s10, s12 */
/* @0x19b99c vadd.f32 s14, s11, s14 */
/* @0x19b9a0 vmov s11, r2 */
/* @0x19b9a4 vcvt.f32.s32 s15, s15 */
/* @0x19b9a8 vcvt.f32.s32 s13, s11 */
/* @0x19b9ac vadd.f32 s15, s14, s15 */
/* @0x19b9b0 vadd.f32 s13, s12, s13 */
/* @0x19b9b4 vmov r2, s15 */
/* @0x19b9b8 vmov r1, s13 */
/* @0x19b9bc bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19b9c0 b 0x19b7e4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xeec> */
/* @0x19b9c4 ldr r10, [sp, #0x18] */
/* @0x19b9c8 cmp r10, #0 */
/* @0x19b9cc beq 0x19baa4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11ac> */
/* @0x19b9d0 ldr r11, [sp, #0x38] */
/* @0x19b9d4 add r4, r4, #1 */
/* @0x19b9d8 subs r12, r11, r4 */
/* @0x19b9dc movne r12, #1 */
/* @0x19b9e0 b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19b9e4 cmp r8, #0 */
/* @0x19b9e8 moveq r11, r8 */
/* @0x19b9ec beq 0x19b8e8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xff0> */
/* @0x19b9f0 sub r3, r7, #1 */
/* @0x19b9f4 sub r10, r5, #1 */
/* @0x19b9f8 b 0x19b8d4 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfdc> */
/* @0x19b9fc rsb r10, r1, r0 */
/* @0x19ba00 sub r3, r7, #1 */
/* @0x19ba04 add r10, r5, r10 */
/* @0x19ba08 add r10, r10, #1 */
/* @0x19ba0c ldr r10, [r2, r10, lsl #2] */
/* @0x19ba10 subs r11, r10, r3 */
/* @0x19ba14 rsbs r10, r11, #0 */
/* @0x19ba18 adcs r10, r10, r11 */
/* @0x19ba1c str r10, [sp, #0x24] */
/* @0x19ba20 add lr, lr, #1 */
/* @0x19ba24 ldr lr, [r2, lr, lsl #2] */
/* @0x19ba28 cmp lr, r3 */
/* @0x19ba2c ldr lr, [r9, #0x14] */
/* @0x19ba30 sub lr, lr, #1 */
/* @0x19ba34 beq 0x19c190 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1898> */
/* @0x19ba38 cmp r4, lr */
/* @0x19ba3c bge 0x19ba74 <_Z16Motion_Grid_PathiP5CPathiiiib+0x117c> */
/* @0x19ba40 cmp r5, r8 */
/* @0x19ba44 mov r11, #0 */
/* @0x19ba48 str r11, [sp, #0x20] */
/* @0x19ba4c bge 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba50 add r8, r1, r0 */
/* @0x19ba54 add r8, r8, r5 */
/* @0x19ba58 add r8, r8, #1 */
/* @0x19ba5c ldr r8, [r2, r8, lsl #2] */
/* @0x19ba60 cmp r8, r3 */
/* @0x19ba64 bne 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba68 mov r8, #1 */
/* @0x19ba6c str r8, [sp, #0x14] */
/* @0x19ba70 b 0x19b848 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf50> */
/* @0x19ba74 mov r10, #0 */
/* @0x19ba78 str r10, [sp, #0x20] */
/* @0x19ba7c b 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19ba80 cmp r5, r8 */
/* @0x19ba84 bge 0x19b82c <_Z16Motion_Grid_PathiP5CPathiiiib+0xf34> */
/* @0x19ba88 mov r10, #0 */
/* @0x19ba8c sub r3, r7, #1 */
/* @0x19ba90 str r10, [sp, #0x24] */
/* @0x19ba94 b 0x19ba20 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1128> */
/* @0x19ba98 mov r10, #0 */
/* @0x19ba9c str r10, [sp, #0x10] */
/* @0x19baa0 b 0x19b870 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf78> */
/* @0x19baa4 cmp r3, #0 */
/* @0x19baa8 beq 0x19bad0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x11d8> */
/* @0x19baac ldr r8, [sp, #0x3c] */
/* @0x19bab0 sub r5, r5, #1 */
/* @0x19bab4 subs r6, r8, r5 */
/* @0x19bab8 movne r6, #1 */
/* @0x19babc b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19bac0 mov r3, #1 */
/* @0x19bac4 b 0x19b8ec <_Z16Motion_Grid_PathiP5CPathiiiib+0xff4> */
/* @0x19bac8 mov r11, #1 */
/* @0x19bacc b 0x19b8d8 <_Z16Motion_Grid_PathiP5CPathiiiib+0xfe0> */
/* @0x19bad0 ldr r10, [sp, #0x20] */
/* @0x19bad4 cmp r10, #0 */
/* @0x19bad8 beq 0x19bfd0 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16d8> */
/* @0x19badc ldr r11, [sp, #0x3c] */
/* @0x19bae0 add r5, r5, #1 */
/* @0x19bae4 subs r6, r11, r5 */
/* @0x19bae8 movne r6, #1 */
/* @0x19baec b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19baf0 ldr r10, [sp, #0x30] */
/* @0x19baf4 mov r3, #0 */
/* @0x19baf8 ldr r8, [sp, #0x34] */
/* @0x19bafc movt r3, #0x42c8 */
/* @0x19bb00 ldr r11, [sp, #0x28] */
/* @0x19bb04 vmov s11, r10 */
/* @0x19bb08 vmov s13, r8 */
/* @0x19bb0c vcvt.f32.s32 s11, s11 */
/* @0x19bb10 mov r0, r11 */
/* @0x19bb14 vcvt.f32.s32 s13, s13 */
/* @0x19bb18 vmov r1, s11 */
/* @0x19bb1c vmov r2, s13 */
/* @0x19bb20 bl 0x1a72c0 <_ZN5CPath8AddPointEfff> */
/* @0x19bb24 mov r0, r11 */
/* @0x19bb28 bl 0x1a76b4 <_ZN5CPath7ReverseEv> */
/* @0x19bb2c mov r0, #1 */
/* @0x19bb30 b 0x19adcc <_Z16Motion_Grid_PathiP5CPathiiiib+0x4d4> */
/* @0x19bb34 cmp r2, #0 */
/* @0x19bb38 ldr r1, [sp, #0x68] */
/* @0x19bb3c lslge r11, r2, #1 */
/* @0x19bb40 mov r3, #1 */
/* @0x19bb44 movlt r11, #4096 */
/* @0x19bb48 mov r2, #212 */
/* @0x19bb4c lsl r0, r11, #2 */
/* @0x19bb50 str r12, [sp, #0x8] */
/* @0x19bb54 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bb58 ldr r12, [sp, #0x8] */
/* @0x19bb5c ldr r4, [r12] */
/* @0x19bb60 cmp r4, #0 */
/* @0x19bb64 str r0, [sp, #0x20] */
/* @0x19bb68 ble 0x19bbc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x12d0> */
/* @0x19bb6c ldr r2, [r10] */
/* @0x19bb70 ldr r3, [r7] */
/* @0x19bb74 cmp r2, r3 */
/* @0x19bb78 bgt 0x19c0f8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1800> */
/* @0x19bb7c rsb r4, r3, r4 */
/* @0x19bb80 ldr r1, [r5] */
/* @0x19bb84 str r12, [sp, #0x8] */
/* @0x19bb88 lsl r6, r4, #2 */
/* @0x19bb8c add r1, r1, r3, lsl #2 */
/* @0x19bb90 mov r2, r6 */
/* @0x19bb94 bl 0xb65bc <memcpy@plt> */
/* @0x19bb98 ldr r2, [r10] */
/* @0x19bb9c ldr r3, [sp, #0x20] */
/* @0x19bba0 ldr r1, [r5] */
/* @0x19bba4 add r0, r3, r6 */
/* @0x19bba8 lsl r2, r2, #2 */
/* @0x19bbac bl 0xb65bc <memcpy@plt> */
/* @0x19bbb0 ldr r12, [sp, #0x8] */
/* @0x19bbb4 ldr r3, [r10] */
/* @0x19bbb8 mov r0, #0 */
/* @0x19bbbc str r0, [r7] */
/* @0x19bbc0 add r4, r4, r3 */
/* @0x19bbc4 str r4, [r10] */
/* @0x19bbc8 ldr r3, [sp, #0x20] */
/* @0x19bbcc str r11, [r12] */
/* @0x19bbd0 str r3, [r5] */
/* @0x19bbd4 ldr r3, [r10] */
/* @0x19bbd8 b 0x19b2ac <_Z16Motion_Grid_PathiP5CPathiiiib+0x9b4> */
/* @0x19bbdc cmp r2, #0 */
/* @0x19bbe0 ldr r1, [sp, #0x5c] */
/* @0x19bbe4 lslge r2, r2, #1 */
/* @0x19bbe8 strge r2, [sp, #0x50] */
/* @0x19bbec movlt r8, #4096 */
/* @0x19bbf0 strlt r8, [sp, #0x50] */
/* @0x19bbf4 ldr r8, [sp, #0x50] */
/* @0x19bbf8 mov r2, #212 */
/* @0x19bbfc mov r3, #1 */
/* @0x19bc00 str r12, [sp, #0x8] */
/* @0x19bc04 lsl r0, r8, #2 */
/* @0x19bc08 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bc0c ldr r12, [sp, #0x8] */
/* @0x19bc10 ldr r8, [r12] */
/* @0x19bc14 cmp r8, #0 */
/* @0x19bc18 str r0, [sp, #0x54] */
/* @0x19bc1c ble 0x19bc80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1388> */
/* @0x19bc20 ldr r2, [r10] */
/* @0x19bc24 ldr r3, [r7] */
/* @0x19bc28 cmp r2, r3 */
/* @0x19bc2c bgt 0x19c0bc <_Z16Motion_Grid_PathiP5CPathiiiib+0x17c4> */
/* @0x19bc30 rsb r8, r3, r8 */
/* @0x19bc34 ldr r1, [r5] */
/* @0x19bc38 str r12, [sp, #0x8] */
/* @0x19bc3c lsl r2, r8, #2 */
/* @0x19bc40 add r1, r1, r3, lsl #2 */
/* @0x19bc44 str r2, [sp, #0x58] */
/* @0x19bc48 bl 0xb65bc <memcpy@plt> */
/* @0x19bc4c ldr r2, [r10] */
/* @0x19bc50 ldr r3, [sp, #0x54] */
/* @0x19bc54 ldr lr, [sp, #0x58] */
/* @0x19bc58 ldr r1, [r5] */
/* @0x19bc5c lsl r2, r2, #2 */
/* @0x19bc60 add r0, r3, lr */
/* @0x19bc64 bl 0xb65bc <memcpy@plt> */
/* @0x19bc68 ldr r12, [sp, #0x8] */
/* @0x19bc6c ldr r3, [r10] */
/* @0x19bc70 mov r0, #0 */
/* @0x19bc74 str r0, [r7] */
/* @0x19bc78 add r8, r8, r3 */
/* @0x19bc7c str r8, [r10] */
/* @0x19bc80 ldr r3, [sp, #0x54] */
/* @0x19bc84 ldr r8, [sp, #0x50] */
/* @0x19bc88 str r3, [r5] */
/* @0x19bc8c str r8, [r12] */
/* @0x19bc90 ldr r3, [r10] */
/* @0x19bc94 b 0x19b334 <_Z16Motion_Grid_PathiP5CPathiiiib+0xa3c> */
/* @0x19bc98 cmp r2, #0 */
/* @0x19bc9c ldr r1, [sp, #0x60] */
/* @0x19bca0 lslge r2, r2, #1 */
/* @0x19bca4 strge r2, [sp, #0x2c] */
/* @0x19bca8 movlt r8, #4096 */
/* @0x19bcac strlt r8, [sp, #0x2c] */
/* @0x19bcb0 ldr r8, [sp, #0x2c] */
/* @0x19bcb4 mov r2, #212 */
/* @0x19bcb8 mov r3, #1 */
/* @0x19bcbc str r12, [sp, #0x8] */
/* @0x19bcc0 lsl r0, r8, #2 */
/* @0x19bcc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bcc8 ldr r12, [sp, #0x8] */
/* @0x19bccc ldr r8, [r12] */
/* @0x19bcd0 cmp r8, #0 */
/* @0x19bcd4 str r0, [sp, #0x4c] */
/* @0x19bcd8 ble 0x19bd3c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1444> */
/* @0x19bcdc ldr r2, [r10] */
/* @0x19bce0 ldr r3, [r7] */
/* @0x19bce4 cmp r2, r3 */
/* @0x19bce8 bgt 0x19c040 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1748> */
/* @0x19bcec rsb r8, r3, r8 */
/* @0x19bcf0 ldr r1, [r5] */
/* @0x19bcf4 str r12, [sp, #0x8] */
/* @0x19bcf8 lsl r2, r8, #2 */
/* @0x19bcfc add r1, r1, r3, lsl #2 */
/* @0x19bd00 str r2, [sp, #0x50] */
/* @0x19bd04 bl 0xb65bc <memcpy@plt> */
/* @0x19bd08 ldr r2, [r10] */
/* @0x19bd0c ldr r3, [sp, #0x4c] */
/* @0x19bd10 ldr lr, [sp, #0x50] */
/* @0x19bd14 ldr r1, [r5] */
/* @0x19bd18 lsl r2, r2, #2 */
/* @0x19bd1c add r0, r3, lr */
/* @0x19bd20 bl 0xb65bc <memcpy@plt> */
/* @0x19bd24 ldr r12, [sp, #0x8] */
/* @0x19bd28 ldr r3, [r10] */
/* @0x19bd2c mov r0, #0 */
/* @0x19bd30 str r0, [r7] */
/* @0x19bd34 add r8, r8, r3 */
/* @0x19bd38 str r8, [r10] */
/* @0x19bd3c ldr r3, [sp, #0x4c] */
/* @0x19bd40 ldr r8, [sp, #0x2c] */
/* @0x19bd44 str r3, [r5] */
/* @0x19bd48 str r8, [r12] */
/* @0x19bd4c ldr r3, [r10] */
/* @0x19bd50 b 0x19b3c0 <_Z16Motion_Grid_PathiP5CPathiiiib+0xac8> */
/* @0x19bd54 cmp r2, #0 */
/* @0x19bd58 ldr r1, [sp, #0x64] */
/* @0x19bd5c lslge r2, r2, #1 */
/* @0x19bd60 strge r2, [sp, #0x24] */
/* @0x19bd64 movlt r8, #4096 */
/* @0x19bd68 strlt r8, [sp, #0x24] */
/* @0x19bd6c ldr r8, [sp, #0x24] */
/* @0x19bd70 mov r2, #212 */
/* @0x19bd74 mov r3, #1 */
/* @0x19bd78 str r12, [sp, #0x8] */
/* @0x19bd7c lsl r0, r8, #2 */
/* @0x19bd80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19bd84 ldr r12, [sp, #0x8] */
/* @0x19bd88 ldr r8, [r12] */
/* @0x19bd8c cmp r8, #0 */
/* @0x19bd90 str r0, [sp, #0x2c] */
/* @0x19bd94 ble 0x19bdf8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1500> */
/* @0x19bd98 ldr r2, [r10] */
/* @0x19bd9c ldr r3, [r7] */
/* @0x19bda0 cmp r2, r3 */
/* @0x19bda4 bgt 0x19c004 <_Z16Motion_Grid_PathiP5CPathiiiib+0x170c> */
/* @0x19bda8 rsb r8, r3, r8 */
/* @0x19bdac ldr r1, [r5] */
/* @0x19bdb0 str r12, [sp, #0x8] */
/* @0x19bdb4 lsl r2, r8, #2 */
/* @0x19bdb8 add r1, r1, r3, lsl #2 */
/* @0x19bdbc str r2, [sp, #0x48] */
/* @0x19bdc0 bl 0xb65bc <memcpy@plt> */
/* @0x19bdc4 ldr r2, [r10] */
/* @0x19bdc8 ldr r3, [sp, #0x2c] */
/* @0x19bdcc ldr lr, [sp, #0x48] */
/* @0x19bdd0 ldr r1, [r5] */
/* @0x19bdd4 lsl r2, r2, #2 */
/* @0x19bdd8 add r0, r3, lr */
/* @0x19bddc bl 0xb65bc <memcpy@plt> */
/* @0x19bde0 ldr r12, [sp, #0x8] */
/* @0x19bde4 ldr r3, [r10] */
/* @0x19bde8 mov r0, #0 */
/* @0x19bdec str r0, [r7] */
/* @0x19bdf0 add r8, r8, r3 */
/* @0x19bdf4 str r8, [r10] */
/* @0x19bdf8 ldr r3, [sp, #0x2c] */
/* @0x19bdfc ldr r8, [sp, #0x24] */
/* @0x19be00 str r3, [r5] */
/* @0x19be04 str r8, [r12] */
/* @0x19be08 ldr r3, [r10] */
/* @0x19be0c b 0x19b22c <_Z16Motion_Grid_PathiP5CPathiiiib+0x934> */
/* @0x19be10 rsb r2, r1, r3 */
/* @0x19be14 ldr r3, [r5] */
/* @0x19be18 lsl r2, r2, #2 */
/* @0x19be1c add r1, r3, r1, lsl #2 */
/* @0x19be20 bl 0xb65bc <memcpy@plt> */
/* @0x19be24 ldr r2, [r10] */
/* @0x19be28 ldr r3, [r7] */
/* @0x19be2c mov lr, #0 */
/* @0x19be30 ldr r0, [r5] */
/* @0x19be34 rsb r3, r3, r2 */
/* @0x19be38 str lr, [r7] */
/* @0x19be3c str r3, [r10] */
/* @0x19be40 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19be44 ldr r12, [sp, #0x8] */
/* @0x19be48 b 0x19b4ac <_Z16Motion_Grid_PathiP5CPathiiiib+0xbb4> */
/* @0x19be4c rsb r2, r1, r3 */
/* @0x19be50 ldr r3, [r5] */
/* @0x19be54 lsl r2, r2, #2 */
/* @0x19be58 add r1, r3, r1, lsl #2 */
/* @0x19be5c bl 0xb65bc <memcpy@plt> */
/* @0x19be60 ldr r2, [r10] */
/* @0x19be64 ldr r3, [r7] */
/* @0x19be68 mov lr, #0 */
/* @0x19be6c ldr r0, [r5] */
/* @0x19be70 rsb r3, r3, r2 */
/* @0x19be74 str lr, [r7] */
/* @0x19be78 str r3, [r10] */
/* @0x19be7c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19be80 ldr r12, [sp, #0x8] */
/* @0x19be84 b 0x19b578 <_Z16Motion_Grid_PathiP5CPathiiiib+0xc80> */
/* @0x19be88 rsb r2, r1, r3 */
/* @0x19be8c ldr r3, [r5] */
/* @0x19be90 lsl r2, r2, #2 */
/* @0x19be94 add r1, r3, r1, lsl #2 */
/* @0x19be98 bl 0xb65bc <memcpy@plt> */
/* @0x19be9c ldr r2, [r10] */
/* @0x19bea0 ldr r3, [r7] */
/* @0x19bea4 mov lr, #0 */
/* @0x19bea8 ldr r0, [r5] */
/* @0x19beac rsb r3, r3, r2 */
/* @0x19beb0 str lr, [r7] */
/* @0x19beb4 str r3, [r10] */
/* @0x19beb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19bebc ldr r12, [sp, #0x8] */
/* @0x19bec0 b 0x19b64c <_Z16Motion_Grid_PathiP5CPathiiiib+0xd54> */
/* @0x19bec4 cmp r6, #0 */
/* @0x19bec8 ldr r1, [pc, #-0x75c] */
/* @0x19becc lslge r6, r6, #1 */
/* @0x19bed0 mov r3, #1 */
/* @0x19bed4 movlt r6, #4096 */
/* @0x19bed8 add r1, pc, r1 */
/* @0x19bedc lsl r0, r6, #2 */
/* @0x19bee0 mov r2, #212 */
/* @0x19bee4 str r12, [sp, #0x8] */
/* @0x19bee8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x19beec ldr r3, [sp, #0x20] */
/* @0x19bef0 ldr r12, [sp, #0x8] */
/* @0x19bef4 ldr r1, [r3] */
/* @0x19bef8 cmp r1, #0 */
/* @0x19befc str r0, [sp, #0x28] */
/* @0x19bf00 ble 0x19c184 <_Z16Motion_Grid_PathiP5CPathiiiib+0x188c> */
/* @0x19bf04 ldr r2, [r12] */
/* @0x19bf08 ldr r3, [r7] */
/* @0x19bf0c cmp r2, r3 */
/* @0x19bf10 bgt 0x19c134 <_Z16Motion_Grid_PathiP5CPathiiiib+0x183c> */
/* @0x19bf14 ldr r2, [pc, #-0x7a4] */
/* @0x19bf18 rsb r1, r3, r1 */
/* @0x19bf1c str r1, [sp, #0x30] */
/* @0x19bf20 lsl lr, r1, #2 */
/* @0x19bf24 str lr, [sp, #0x34] */
/* @0x19bf28 ldr r5, [r4, r2] */
/* @0x19bf2c mov r2, lr */
/* @0x19bf30 ldr r1, [r5] */
/* @0x19bf34 str r12, [sp, #0x8] */
/* @0x19bf38 add r1, r1, r3, lsl #2 */
/* @0x19bf3c bl 0xb65bc <memcpy@plt> */
/* @0x19bf40 ldr r12, [sp, #0x8] */
/* @0x19bf44 ldr r3, [sp, #0x28] */
/* @0x19bf48 ldr lr, [sp, #0x34] */
/* @0x19bf4c ldr r2, [r12] */
/* @0x19bf50 add r0, r3, lr */
/* @0x19bf54 ldr r1, [r5] */
/* @0x19bf58 lsl r2, r2, #2 */
/* @0x19bf5c bl 0xb65bc <memcpy@plt> */
/* @0x19bf60 ldr r12, [sp, #0x8] */
/* @0x19bf64 ldr r0, [sp, #0x30] */
/* @0x19bf68 mov r2, #0 */
/* @0x19bf6c str r2, [r7] */
/* @0x19bf70 ldr r3, [r12] */
/* @0x19bf74 add r3, r0, r3 */
/* @0x19bf78 str r3, [r12] */
/* @0x19bf7c ldr r3, [sp, #0x28] */
/* @0x19bf80 ldr r0, [sp, #0x20] */
/* @0x19bf84 str r3, [r5] */
/* @0x19bf88 str r6, [r0] */
/* @0x19bf8c ldr r3, [r12] */
/* @0x19bf90 b 0x19ab14 <_Z16Motion_Grid_PathiP5CPathiiiib+0x21c> */
/* @0x19bf94 rsb r2, r1, r3 */
/* @0x19bf98 ldr r3, [r5] */
/* @0x19bf9c lsl r2, r2, #2 */
/* @0x19bfa0 add r1, r3, r1, lsl #2 */
/* @0x19bfa4 bl 0xb65bc <memcpy@plt> */
/* @0x19bfa8 ldr r2, [r10] */
/* @0x19bfac ldr r3, [r7] */
/* @0x19bfb0 mov lr, #0 */
/* @0x19bfb4 ldr r0, [r5] */
/* @0x19bfb8 rsb r3, r3, r2 */
/* @0x19bfbc str lr, [r7] */
/* @0x19bfc0 str r3, [r10] */
/* @0x19bfc4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19bfc8 ldr r12, [sp, #0x8] */
/* @0x19bfcc b 0x19b71c <_Z16Motion_Grid_PathiP5CPathiiiib+0xe24> */
/* @0x19bfd0 ldr lr, [sp, #0x24] */
/* @0x19bfd4 ldr r8, [sp, #0x1c] */
/* @0x19bfd8 tst lr, r8 */
/* @0x19bfdc beq 0x19c07c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1784> */
/* @0x19bfe0 sub r4, r4, #1 */
/* @0x19bfe4 add r5, r5, #1 */
/* @0x19bfe8 ldr r10, [sp, #0x38] */
/* @0x19bfec ldr r11, [sp, #0x3c] */
/* @0x19bff0 subs r12, r10, r4 */
/* @0x19bff4 movne r12, #1 */
/* @0x19bff8 subs r6, r11, r5 */
/* @0x19bffc movne r6, #1 */
/* @0x19c000 b 0x19b940 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1048> */
/* @0x19c004 rsb r2, r3, r2 */
/* @0x19c008 ldr r1, [r5] */
/* @0x19c00c lsl r2, r2, #2 */
/* @0x19c010 add r1, r1, r3, lsl #2 */
/* @0x19c014 bl 0xb65bc <memcpy@plt> */
/* @0x19c018 ldr r2, [r10] */
/* @0x19c01c ldr r3, [r7] */
/* @0x19c020 mov lr, #0 */
/* @0x19c024 ldr r0, [r5] */
/* @0x19c028 rsb r3, r3, r2 */
/* @0x19c02c str lr, [r7] */
/* @0x19c030 str r3, [r10] */
/* @0x19c034 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c038 ldr r12, [sp, #0x8] */
/* @0x19c03c b 0x19bdf8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1500> */
/* @0x19c040 rsb r2, r3, r2 */
/* @0x19c044 ldr r1, [r5] */
/* @0x19c048 lsl r2, r2, #2 */
/* @0x19c04c add r1, r1, r3, lsl #2 */
/* @0x19c050 bl 0xb65bc <memcpy@plt> */
/* @0x19c054 ldr r2, [r10] */
/* @0x19c058 ldr r3, [r7] */
/* @0x19c05c mov lr, #0 */
/* @0x19c060 ldr r0, [r5] */
/* @0x19c064 rsb r3, r3, r2 */
/* @0x19c068 str lr, [r7] */
/* @0x19c06c str r3, [r10] */
/* @0x19c070 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c074 ldr r12, [sp, #0x8] */
/* @0x19c078 b 0x19bd3c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1444> */
/* @0x19c07c ldr lr, [sp, #0x14] */
/* @0x19c080 ldr r8, [sp, #0x1c] */
/* @0x19c084 tst lr, r8 */
/* @0x19c088 addne r4, r4, #1 */
/* @0x19c08c addne r5, r5, #1 */
/* @0x19c090 bne 0x19bfe8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16f0> */
/* @0x19c094 ldr r8, [sp, #0x1c] */
/* @0x19c098 tst r11, r8 */
/* @0x19c09c subne r4, r4, #1 */
/* @0x19c0a0 bne 0x19c0b4 <_Z16Motion_Grid_PathiP5CPathiiiib+0x17bc> */
/* @0x19c0a4 ldr r8, [sp, #0x1c] */
/* @0x19c0a8 tst r2, r8 */
/* @0x19c0ac beq 0x19b948 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1050> */
/* @0x19c0b0 add r4, r4, #1 */
/* @0x19c0b4 sub r5, r5, #1 */
/* @0x19c0b8 b 0x19bfe8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x16f0> */
/* @0x19c0bc rsb r2, r3, r2 */
/* @0x19c0c0 ldr r1, [r5] */
/* @0x19c0c4 lsl r2, r2, #2 */
/* @0x19c0c8 add r1, r1, r3, lsl #2 */
/* @0x19c0cc bl 0xb65bc <memcpy@plt> */
/* @0x19c0d0 ldr r2, [r10] */
/* @0x19c0d4 ldr r3, [r7] */
/* @0x19c0d8 mov lr, #0 */
/* @0x19c0dc ldr r0, [r5] */
/* @0x19c0e0 rsb r3, r3, r2 */
/* @0x19c0e4 str lr, [r7] */
/* @0x19c0e8 str r3, [r10] */
/* @0x19c0ec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c0f0 ldr r12, [sp, #0x8] */
/* @0x19c0f4 b 0x19bc80 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1388> */
/* @0x19c0f8 rsb r2, r3, r2 */
/* @0x19c0fc ldr r1, [r5] */
/* @0x19c100 lsl r2, r2, #2 */
/* @0x19c104 add r1, r1, r3, lsl #2 */
/* @0x19c108 bl 0xb65bc <memcpy@plt> */
/* @0x19c10c ldr r2, [r10] */
/* @0x19c110 ldr r3, [r7] */
/* @0x19c114 mov lr, #0 */
/* @0x19c118 ldr r0, [r5] */
/* @0x19c11c rsb r3, r3, r2 */
/* @0x19c120 str lr, [r7] */
/* @0x19c124 str r3, [r10] */
/* @0x19c128 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c12c ldr r12, [sp, #0x8] */
/* @0x19c130 b 0x19bbc8 <_Z16Motion_Grid_PathiP5CPathiiiib+0x12d0> */
/* @0x19c134 ldr r1, [pc, #-0x9c4] */
/* @0x19c138 rsb r2, r3, r2 */
/* @0x19c13c lsl r2, r2, #2 */
/* @0x19c140 ldr r5, [r4, r1] */
/* @0x19c144 ldr r1, [r5] */
/* @0x19c148 str r12, [sp, #0x8] */
/* @0x19c14c add r1, r1, r3, lsl #2 */
/* @0x19c150 bl 0xb65bc <memcpy@plt> */
/* @0x19c154 ldr r12, [sp, #0x8] */
/* @0x19c158 ldr r3, [r7] */
/* @0x19c15c mov r2, #0 */
/* @0x19c160 ldr r0, [r5] */
/* @0x19c164 ldr r1, [r12] */
/* @0x19c168 str r2, [r7] */
/* @0x19c16c rsb r3, r3, r1 */
/* @0x19c170 str r3, [r12] */
/* @0x19c174 str r12, [sp, #0x8] */
/* @0x19c178 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c17c ldr r12, [sp, #0x8] */
/* @0x19c180 b 0x19bf7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1684> */
/* @0x19c184 ldr r3, [pc, #-0xa14] */
/* @0x19c188 ldr r5, [r4, r3] */
/* @0x19c18c b 0x19bf7c <_Z16Motion_Grid_PathiP5CPathiiiib+0x1684> */
/* @0x19c190 cmp r4, lr */
/* @0x19c194 movge r3, #1 */
/* @0x19c198 strge r3, [sp, #0x20] */
/* @0x19c19c bge 0x19b840 <_Z16Motion_Grid_PathiP5CPathiiiib+0xf48> */
/* @0x19c1a0 mov r8, #1 */
/* @0x19c1a4 str r8, [sp, #0x20] */
/* @0x19c1a8 b 0x19ba50 <_Z16Motion_Grid_PathiP5CPathiiiib+0x1158> */

/* ── FUNC 0x19c1ac · Motion_Grid_Draw(int) · size=288 · insn=72 */
/* @0x19c1ac cmp r0, #0 */
/* @0x19c1b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19c1b4 sub sp, sp, #28 */
/* @0x19c1b8 blt 0x19c2bc <_Z16Motion_Grid_Drawi+0x110> */
/* @0x19c1bc ldr r3, [pc, #0x100] */
/* @0x19c1c0 ldr r3, [pc, r3] */
/* @0x19c1c4 ldr r3, [r3] */
/* @0x19c1c8 cmp r0, r3 */
/* @0x19c1cc bge 0x19c2bc <_Z16Motion_Grid_Drawi+0x110> */
/* @0x19c1d0 ldr r3, [pc, #0xf0] */
/* @0x19c1d4 ldr r3, [pc, r3] */
/* @0x19c1d8 ldr r3, [r3] */
/* @0x19c1dc ldr r4, [r3, r0, lsl #2] */
/* @0x19c1e0 cmp r4, #0 */
/* @0x19c1e4 beq 0x19c2bc <_Z16Motion_Grid_Drawi+0x110> */
/* @0x19c1e8 ldr r3, [r4, #0x14] */
/* @0x19c1ec cmp r3, #0 */
/* @0x19c1f0 ble 0x19c2bc <_Z16Motion_Grid_Drawi+0x110> */
/* @0x19c1f4 ldr r1, [r4, #0x18] */
/* @0x19c1f8 mov r6, #1 */
/* @0x19c1fc mov r7, #0 */
/* @0x19c200 cmp r1, #0 */
/* @0x19c204 mov r8, r6 */
/* @0x19c208 sub r9, r6, #1 */
/* @0x19c20c movgt r5, #0 */
/* @0x19c210 ble 0x19c2b0 <_Z16Motion_Grid_Drawi+0x104> */
/* @0x19c214 ldr r3, [r4, #0x10] */
/* @0x19c218 ldr r10, [r4, #0x8] */
/* @0x19c21c mla r1, r9, r1, r5 */
/* @0x19c220 ldr r11, [r4, #0x1c] */
/* @0x19c224 mul lr, r3, r5 */
/* @0x19c228 ldr r12, [r4, #0xc] */
/* @0x19c22c ldr r2, [r4, #0x4] */
/* @0x19c230 add r5, r5, #1 */
/* @0x19c234 add r3, lr, r3 */
/* @0x19c238 ldr r11, [r11, r1, lsl #2] */
/* @0x19c23c add r3, r10, r3 */
/* @0x19c240 add r1, r10, lr */
/* @0x19c244 mla r0, r9, r12, r2 */
/* @0x19c248 vmov s15, r3 */
/* @0x19c24c mla r2, r6, r12, r2 */
/* @0x19c250 vcvt.f32.s32 s15, s15 */
/* @0x19c254 cmp r11, #0 */
/* @0x19c258 str r7, [sp, #0x10] */
/* @0x19c25c movge r12, #32768 */
/* @0x19c260 movlt r12, #255 */
/* @0x19c264 str r12, [sp] */
/* @0x19c268 str r12, [sp, #0x4] */
/* @0x19c26c str r12, [sp, #0x8] */
/* @0x19c270 vmov r3, s15 */
/* @0x19c274 vmov s15, r1 */
/* @0x19c278 str r12, [sp, #0xc] */
/* @0x19c27c vcvt.f32.s32 s15, s15 */
/* @0x19c280 vmov r1, s15 */
/* @0x19c284 vmov s15, r0 */
/* @0x19c288 vcvt.f32.s32 s15, s15 */
/* @0x19c28c vmov r0, s15 */
/* @0x19c290 vmov s15, r2 */
/* @0x19c294 vcvt.f32.s32 s15, s15 */
/* @0x19c298 vmov r2, s15 */
/* @0x19c29c bl 0x16ac60 <_Z21GR_Draw_Rectangle_Extffffjjjjb> */
/* @0x19c2a0 ldr r1, [r4, #0x18] */
/* @0x19c2a4 cmp r1, r5 */
/* @0x19c2a8 bgt 0x19c214 <_Z16Motion_Grid_Drawi+0x68> */
/* @0x19c2ac ldr r3, [r4, #0x14] */
/* @0x19c2b0 cmp r3, r8 */
/* @0x19c2b4 add r6, r6, #1 */
/* @0x19c2b8 bgt 0x19c200 <_Z16Motion_Grid_Drawi+0x54> */
/* @0x19c2bc add sp, sp, #28 */
/* @0x19c2c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19c2c4 eoreq r4, r5, r12, ror #9 */
/* @0x19c2c8 .word 0x002544dc */

/* ── FUNC 0x19c2cc · FINALIZE_Motion_Grid() · size=140 · insn=35 */
/* @0x19c2cc push {r3, r4, r5, r6, r7, lr} */
/* @0x19c2d0 ldr r5, [pc, #0x78] */
/* @0x19c2d4 ldr r5, [pc, r5] */
/* @0x19c2d8 ldr r2, [r5] */
/* @0x19c2dc cmp r2, #0 */
/* @0x19c2e0 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x19c2e4 ldr r6, [pc, #0x68] */
/* @0x19c2e8 ldr r6, [pc, r6] */
/* @0x19c2ec ldr r3, [r6] */
/* @0x19c2f0 cmp r3, #0 */
/* @0x19c2f4 ble 0x19c338 <_Z20FINALIZE_Motion_Gridv+0x6c> */
/* @0x19c2f8 mov r4, #0 */
/* @0x19c2fc mov r7, r4 */
/* @0x19c300 ldr r3, [r2, r4, lsl #2] */
/* @0x19c304 cmp r3, #0 */
/* @0x19c308 mov r0, r3 */
/* @0x19c30c beq 0x19c328 <_Z20FINALIZE_Motion_Gridv+0x5c> */
/* @0x19c310 ldr r3, [r3] */
/* @0x19c314 ldr r3, [r3, #0x4] */
/* @0x19c318 blx r3 */
/* @0x19c31c ldr r3, [r5] */
/* @0x19c320 str r7, [r3, r4, lsl #2] */
/* @0x19c324 ldr r2, [r5] */
/* @0x19c328 ldr r3, [r6] */
/* @0x19c32c add r4, r4, #1 */
/* @0x19c330 cmp r3, r4 */
/* @0x19c334 bgt 0x19c300 <_Z20FINALIZE_Motion_Gridv+0x34> */
/* @0x19c338 mov r0, r2 */
/* @0x19c33c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x19c340 mov r3, #0 */
/* @0x19c344 str r3, [r5] */
/* @0x19c348 str r3, [r6] */
/* @0x19c34c pop {r3, r4, r5, r6, r7, pc} */
/* @0x19c350 .word 0x002543dc */
/* @0x19c354 eoreq r4, r5, r4, asr #7 */

/* ── FUNC 0x19c358 · Motion_Grid_to_dsGrid(int, int) · size=924 · insn=231 */
/* @0x19c358 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19c35c sub sp, sp, #60 */
/* @0x19c360 mov r4, r0 */
/* @0x19c364 add r0, sp, #36 */
/* @0x19c368 mov r5, r1 */
/* @0x19c36c bl 0x10026c <_Z11GetTheGridsRi> */
/* @0x19c370 cmp r4, #0 */
/* @0x19c374 blt 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34> */
/* @0x19c378 ldr r3, [pc, #0x364] */
/* @0x19c37c ldr r3, [pc, r3] */
/* @0x19c380 ldr r3, [r3] */
/* @0x19c384 cmp r4, r3 */
/* @0x19c388 blt 0x19c3a4 <_Z21Motion_Grid_to_dsGridii+0x4c> */
/* @0x19c38c ldr r0, [pc, #0x354] */
/* @0x19c390 mov r1, #0 */
/* @0x19c394 add r0, pc, r0 */
/* @0x19c398 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x19c39c add sp, sp, #60 */
/* @0x19c3a0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x19c3a4 cmp r5, #0 */
/* @0x19c3a8 blt 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34> */
/* @0x19c3ac ldr r3, [sp, #0x24] */
/* @0x19c3b0 cmp r5, r3 */
/* @0x19c3b4 bge 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34> */
/* @0x19c3b8 ldr r3, [pc, #0x32c] */
/* @0x19c3bc ldr r8, [r0, r5, lsl #2] */
/* @0x19c3c0 ldr r3, [pc, r3] */
/* @0x19c3c4 ldr r3, [r3] */
/* @0x19c3c8 ldr r12, [r3, r4, lsl #2] */
/* @0x19c3cc cmp r12, #0 */
/* @0x19c3d0 cmpne r8, #0 */
/* @0x19c3d4 movne r1, #0 */
/* @0x19c3d8 moveq r1, #1 */
/* @0x19c3dc beq 0x19c38c <_Z21Motion_Grid_to_dsGridii+0x34> */
/* @0x19c3e0 ldr r2, [r12, #0x14] */
/* @0x19c3e4 ldr r3, [r12, #0x18] */
/* @0x19c3e8 str r2, [sp, #0x14] */
/* @0x19c3ec str r3, [sp, #0x1c] */
/* @0x19c3f0 ldr r2, [r8, #0x8] */
/* @0x19c3f4 ldr r3, [r8, #0x4] */
/* @0x19c3f8 ldr r4, [sp, #0x1c] */
/* @0x19c3fc ldr r0, [sp, #0x14] */
/* @0x19c400 cmp r0, r3 */
/* @0x19c404 cmpeq r4, r2 */
/* @0x19c408 moveq r3, #0 */
/* @0x19c40c movne r3, #1 */
/* @0x19c410 bne 0x19c6d4 <_Z21Motion_Grid_to_dsGridii+0x37c> */
/* @0x19c414 cmp r4, #0 */
/* @0x19c418 ble 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44> */
/* @0x19c41c mov r11, r3 */
/* @0x19c420 ldr r2, [sp, #0x14] */
/* @0x19c424 cmp r2, #0 */
/* @0x19c428 ble 0x19c5bc <_Z21Motion_Grid_to_dsGridii+0x264> */
/* @0x19c42c ldr r4, [sp, #0x30] */
/* @0x19c430 mov r6, #0 */
/* @0x19c434 mov r10, r12 */
/* @0x19c438 mov r9, r3 */
/* @0x19c43c str r4, [sp, #0x18] */
/* @0x19c440 b 0x19c500 <_Z21Motion_Grid_to_dsGridii+0x1a8> */
/* @0x19c444 ldr r3, [r10, #0x18] */
/* @0x19c448 cmp r3, r9 */
/* @0x19c44c ble 0x19c50c <_Z21Motion_Grid_to_dsGridii+0x1b4> */
/* @0x19c450 mla r3, r3, r6, r9 */
/* @0x19c454 ldr r2, [r10, #0x1c] */
/* @0x19c458 ldr r3, [r2, r3, lsl #2] */
/* @0x19c45c vmov s15, r3 */
/* @0x19c460 vcvt.f64.s32 d7, s15 */
/* @0x19c464 vstr d7, [sp, #8] */
/* @0x19c468 ldm r8, {r5, r7} */
/* @0x19c46c mla r7, r7, r9, r6 */
/* @0x19c470 add r4, r5, r7, lsl #4 */
/* @0x19c474 ldr r3, [r4, #0xc] */
/* @0x19c478 sub r3, r3, #1 */
/* @0x19c47c bic r3, r3, #-16777216 */
/* @0x19c480 bic r3, r3, #3 */
/* @0x19c484 cmp r3, #0 */
/* @0x19c488 beq 0x19c550 <_Z21Motion_Grid_to_dsGridii+0x1f8> */
/* @0x19c48c str r11, [r4, #0x8] */
/* @0x19c490 mov r0, #5 */
/* @0x19c494 str r0, [r4, #0xc] */
/* @0x19c498 str r11, [r5, r7, lsl #4] */
/* @0x19c49c ldm r8, {r5, r7} */
/* @0x19c4a0 mla r7, r7, r9, r6 */
/* @0x19c4a4 add r4, r5, r7, lsl #4 */
/* @0x19c4a8 ldr r2, [r4, #0xc] */
/* @0x19c4ac bic r3, r2, #-16777216 */
/* @0x19c4b0 cmp r3, #1 */
/* @0x19c4b4 beq 0x19c518 <_Z21Motion_Grid_to_dsGridii+0x1c0> */
/* @0x19c4b8 cmp r3, #2 */
/* @0x19c4bc bne 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c> */
/* @0x19c4c0 sub r2, r2, #1 */
/* @0x19c4c4 bic r2, r2, #-16777216 */
/* @0x19c4c8 bic r2, r2, #3 */
/* @0x19c4cc cmp r2, #0 */
/* @0x19c4d0 beq 0x19c5d0 <_Z21Motion_Grid_to_dsGridii+0x278> */
/* @0x19c4d4 ldr r3, [sp, #0x18] */
/* @0x19c4d8 add r6, r6, #1 */
/* @0x19c4dc ldr r2, [sp, #0x14] */
/* @0x19c4e0 str r11, [r4, #0xc] */
/* @0x19c4e4 str r3, [r4, #0x8] */
/* @0x19c4e8 cmp r6, r2 */
/* @0x19c4ec ldr r3, [sp, #0xc] */
/* @0x19c4f0 ldr r2, [sp, #0x8] */
/* @0x19c4f4 str r2, [r5, r7, lsl #4] */
/* @0x19c4f8 str r3, [r4, #0x4] */
/* @0x19c4fc beq 0x19c5b4 <_Z21Motion_Grid_to_dsGridii+0x25c> */
/* @0x19c500 ldr r3, [r10, #0x14] */
/* @0x19c504 cmp r3, r6 */
/* @0x19c508 bgt 0x19c444 <_Z21Motion_Grid_to_dsGridii+0xec> */
/* @0x19c50c vmov.f64 d7, #-1.000000e+00 */
/* @0x19c510 vstr d7, [sp, #8] */
/* @0x19c514 b 0x19c468 <_Z21Motion_Grid_to_dsGridii+0x110> */
/* @0x19c518 ldr r3, [r5, r7, lsl #4] */
/* @0x19c51c cmp r3, #0 */
/* @0x19c520 beq 0x19c548 <_Z21Motion_Grid_to_dsGridii+0x1f0> */
/* @0x19c524 str r3, [sp] */
/* @0x19c528 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x19c52c ldr r3, [sp] */
/* @0x19c530 ldr r2, [r3, #0x4] */
/* @0x19c534 sub r2, r2, #1 */
/* @0x19c538 str r2, [r3, #0x4] */
/* @0x19c53c cmp r2, #0 */
/* @0x19c540 beq 0x19c55c <_Z21Motion_Grid_to_dsGridii+0x204> */
/* @0x19c544 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x19c548 str r11, [r5, r7, lsl #4] */
/* @0x19c54c b 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c> */
/* @0x19c550 mov r0, r4 */
/* @0x19c554 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x19c558 b 0x19c48c <_Z21Motion_Grid_to_dsGridii+0x134> */
/* @0x19c55c ldr r0, [r3] */
/* @0x19c560 str r2, [sp, #0x4] */
/* @0x19c564 str r3, [sp] */
/* @0x19c568 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x19c56c ldr r3, [sp] */
/* @0x19c570 ldr r2, [sp, #0x4] */
/* @0x19c574 str r2, [r3] */
/* @0x19c578 str r2, [r3, #0x8] */
/* @0x19c57c str r3, [sp] */
/* @0x19c580 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x19c584 ldr r3, [sp] */
/* @0x19c588 ldr r2, [r3, #0x4] */
/* @0x19c58c sub r2, r2, #1 */
/* @0x19c590 str r2, [r3, #0x4] */
/* @0x19c594 cmp r2, #0 */
/* @0x19c598 beq 0x19c5dc <_Z21Motion_Grid_to_dsGridii+0x284> */
/* @0x19c59c str r3, [sp] */
/* @0x19c5a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x19c5a4 ldr r3, [sp] */
/* @0x19c5a8 mov r0, r3 */
/* @0x19c5ac bl 0x27d1d0 <_ZdlPv> */
/* @0x19c5b0 b 0x19c544 <_Z21Motion_Grid_to_dsGridii+0x1ec> */
/* @0x19c5b4 mov r12, r10 */
/* @0x19c5b8 mov r3, r9 */
/* @0x19c5bc ldr r4, [sp, #0x1c] */
/* @0x19c5c0 add r3, r3, #1 */
/* @0x19c5c4 cmp r3, r4 */
/* @0x19c5c8 bne 0x19c420 <_Z21Motion_Grid_to_dsGridii+0xc8> */
/* @0x19c5cc b 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44> */
/* @0x19c5d0 mov r0, r4 */
/* @0x19c5d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x19c5d8 b 0x19c4d4 <_Z21Motion_Grid_to_dsGridii+0x17c> */
/* @0x19c5dc ldr r0, [r3] */
/* @0x19c5e0 str r2, [sp, #0x4] */
/* @0x19c5e4 str r3, [sp] */
/* @0x19c5e8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x19c5ec ldr r3, [sp] */
/* @0x19c5f0 ldr r2, [sp, #0x4] */
/* @0x19c5f4 str r2, [r3] */
/* @0x19c5f8 str r2, [r3, #0x8] */
/* @0x19c5fc str r3, [sp] */
/* @0x19c600 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x19c604 ldr r3, [sp] */
/* @0x19c608 ldr r2, [r3, #0x4] */
/* @0x19c60c sub r2, r2, #1 */
/* @0x19c610 str r2, [r3, #0x4] */
/* @0x19c614 cmp r2, #0 */
/* @0x19c618 beq 0x19c638 <_Z21Motion_Grid_to_dsGridii+0x2e0> */
/* @0x19c61c str r3, [sp] */
/* @0x19c620 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x19c624 ldr r3, [sp] */
/* @0x19c628 mov r0, r3 */
/* @0x19c62c bl 0x27d1d0 <_ZdlPv> */
/* @0x19c630 ldr r3, [sp] */
/* @0x19c634 b 0x19c59c <_Z21Motion_Grid_to_dsGridii+0x244> */
/* @0x19c638 ldr r0, [r3] */
/* @0x19c63c str r2, [sp, #0x4] */
/* @0x19c640 str r3, [sp] */
/* @0x19c644 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x19c648 ldr r3, [sp] */
/* @0x19c64c ldr r2, [sp, #0x4] */
/* @0x19c650 str r2, [r3] */
/* @0x19c654 str r2, [r3, #0x8] */
/* @0x19c658 str r3, [sp] */
/* @0x19c65c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x19c660 ldr r3, [sp] */
/* @0x19c664 ldr r2, [r3, #0x4] */
/* @0x19c668 sub r2, r2, #1 */
/* @0x19c66c str r2, [r3, #0x4] */
/* @0x19c670 cmp r2, #0 */
/* @0x19c674 beq 0x19c694 <_Z21Motion_Grid_to_dsGridii+0x33c> */
/* @0x19c678 str r3, [sp] */
/* @0x19c67c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x19c680 ldr r3, [sp] */
/* @0x19c684 mov r0, r3 */
/* @0x19c688 bl 0x27d1d0 <_ZdlPv> */
/* @0x19c68c ldr r3, [sp] */
/* @0x19c690 b 0x19c61c <_Z21Motion_Grid_to_dsGridii+0x2c4> */
/* @0x19c694 ldr r0, [r3] */
/* @0x19c698 str r2, [sp, #0x4] */
/* @0x19c69c str r3, [sp] */
/* @0x19c6a0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x19c6a4 ldr r3, [sp] */
/* @0x19c6a8 ldr r2, [sp, #0x4] */
/* @0x19c6ac mov r0, r3 */
/* @0x19c6b0 str r2, [r3] */
/* @0x19c6b4 str r2, [r3, #0x8] */
/* @0x19c6b8 str r3, [sp] */
/* @0x19c6bc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x19c6c0 ldr r3, [sp] */
/* @0x19c6c4 mov r0, r3 */
/* @0x19c6c8 bl 0x27d1d0 <_ZdlPv> */
/* @0x19c6cc ldr r3, [sp] */
/* @0x19c6d0 b 0x19c678 <_Z21Motion_Grid_to_dsGridii+0x320> */
/* @0x19c6d4 ldr r0, [pc, #0x14] */
/* @0x19c6d8 add r0, pc, r0 */
/* @0x19c6dc bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x19c6e0 b 0x19c39c <_Z21Motion_Grid_to_dsGridii+0x44> */
/* @0x19c6e4 eoreq r4, r5, r0, lsr r3 */
/* @0x19c6e8 ldrsheq r0, [r11], -r0 */
/* @0x19c6ec .word 0x002542f0 */
/* @0x19c6f0 ldrsbeq r0, [r11], -r0 */

/* ── FUNC 0x19c6f4 · TestFree(CInstance*, float, float, int, bool) · size=76 · insn=19 */
/* @0x19c6f4 cmn r3, #3 */
/* @0x19c6f8 mov r12, r2 */
/* @0x19c6fc push {r3, r4, r5, lr} */
/* @0x19c700 mov r4, r1 */
/* @0x19c704 ldrb r5, [sp, #0x10] */
/* @0x19c708 beq 0x19c728 <_Z8TestFreeP9CInstanceffib+0x34> */
/* @0x19c70c mov r1, r3 */
/* @0x19c710 mov r2, r4 */
/* @0x19c714 mov r3, r12 */
/* @0x19c718 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff> */
/* @0x19c71c eor r0, r0, #1 */
/* @0x19c720 uxtb r0, r0 */
/* @0x19c724 pop {r3, r4, r5, pc} */
/* @0x19c728 cmp r5, #0 */
/* @0x19c72c beq 0x19c738 <_Z8TestFreeP9CInstanceffib+0x44> */
/* @0x19c730 pop {r3, r4, r5, lr} */
/* @0x19c734 b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */
/* @0x19c738 pop {r3, r4, r5, lr} */
/* @0x19c73c b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */

/* ── FUNC 0x19c740 · ComputeDir(float, float, float, float) · size=172 · insn=43 */
/* @0x19c740 vmov s12, r2 */
/* @0x19c744 vmov s13, r0 */
/* @0x19c748 push {r3, lr} */
/* @0x19c74c vsub.f32 s15, s12, s13 */
/* @0x19c750 vmov s12, r3 */
/* @0x19c754 vmov s13, r1 */
/* @0x19c758 vcmp.f32 s15, #0 */
/* @0x19c75c vsub.f32 s14, s12, s13 */
/* @0x19c760 vmrs APSR_nzcv, fpscr */
/* @0x19c764 bne 0x19c790 <_Z10ComputeDirffff+0x50> */
/* @0x19c768 vcmpe.f32 s14, #0 */
/* @0x19c76c vmrs APSR_nzcv, fpscr */
/* @0x19c770 ble 0x19c780 <_Z10ComputeDirffff+0x40> */
/* @0x19c774 vldr s15, [pc, #88] */
/* @0x19c778 vmov r0, s15 */
/* @0x19c77c pop {r3, pc} */
/* @0x19c780 bmi 0x19c7cc <_Z10ComputeDirffff+0x8c> */
/* @0x19c784 vldr s15, [pc, #76] */
/* @0x19c788 vmov r0, s15 */
/* @0x19c78c pop {r3, pc} */
/* @0x19c790 vmov r1, s15 */
/* @0x19c794 vmov r0, s14 */
/* @0x19c798 bl 0xb6778 <atan2f@plt> */
/* @0x19c79c vldr s15, [pc, #56] */
/* @0x19c7a0 vldr s14, [pc, #56] */
/* @0x19c7a4 vmov s12, r0 */
/* @0x19c7a8 vmul.f32 s15, s12, s15 */
/* @0x19c7ac vdiv.f32 s15, s15, s14 */
/* @0x19c7b0 vcmpe.f32 s15, #0 */
/* @0x19c7b4 vmrs APSR_nzcv, fpscr */
/* @0x19c7b8 vldrhi s14, [pc, #36] */
/* @0x19c7bc vsubhi.f32 s15, s14, s15 */
/* @0x19c7c0 vnegls.f32 s15, s15 */
/* @0x19c7c4 vmov r0, s15 */
/* @0x19c7c8 pop {r3, pc} */
/* @0x19c7cc vldr s15, [pc, #20] */
/* @0x19c7d0 b 0x19c778 <_Z10ComputeDirffff+0x38> */
/* @0x19c7d4 orrmi r0, r7, #0 */
/* @0x19c7d8 andeq r0, r0, r0 */
/* @0x19c7dc teqmi r4, #0 */
/* @0x19c7e0 ldrdmi r0, r1, [r9], #-251 */
/* @0x19c7e4 .word 0x43b40000 */
/* @0x19c7e8 adcsmi r0, r4, #0 */

/* ── FUNC 0x19c7ec · DiffDir(float, float) · size=188 · insn=47 */
/* @0x19c7ec vmov s15, r0 */
/* @0x19c7f0 vmov s14, r1 */
/* @0x19c7f4 vcmpe.f32 s15, #0 */
/* @0x19c7f8 vmrs APSR_nzcv, fpscr */
/* @0x19c7fc bhi 0x19c814 <_Z7DiffDirff+0x28> */
/* @0x19c800 vldr s13, [pc, #152] */
/* @0x19c804 vadd.f32 s15, s15, s13 */
/* @0x19c808 vcmpe.f32 s15, #0 */
/* @0x19c80c vmrs APSR_nzcv, fpscr */
/* @0x19c810 bls 0x19c804 <_Z7DiffDirff+0x18> */
/* @0x19c814 vldr s13, [pc, #132] */
/* @0x19c818 vcmpe.f32 s15, s13 */
/* @0x19c81c vmrs APSR_nzcv, fpscr */
/* @0x19c820 blt 0x19c834 <_Z7DiffDirff+0x48> */
/* @0x19c824 vsub.f32 s15, s15, s13 */
/* @0x19c828 vcmpe.f32 s15, s13 */
/* @0x19c82c vmrs APSR_nzcv, fpscr */
/* @0x19c830 bge 0x19c824 <_Z7DiffDirff+0x38> */
/* @0x19c834 vcmpe.f32 s14, #0 */
/* @0x19c838 vmrs APSR_nzcv, fpscr */
/* @0x19c83c bpl 0x19c854 <_Z7DiffDirff+0x68> */
/* @0x19c840 vldr s13, [pc, #88] */
/* @0x19c844 vadd.f32 s14, s14, s13 */
/* @0x19c848 vcmpe.f32 s14, #0 */
/* @0x19c84c vmrs APSR_nzcv, fpscr */
/* @0x19c850 bmi 0x19c844 <_Z7DiffDirff+0x58> */
/* @0x19c854 vldr s13, [pc, #68] */
/* @0x19c858 vcmpe.f32 s14, s13 */
/* @0x19c85c vmrs APSR_nzcv, fpscr */
/* @0x19c860 blt 0x19c874 <_Z7DiffDirff+0x88> */
/* @0x19c864 vsub.f32 s14, s14, s13 */
/* @0x19c868 vcmpe.f32 s14, s13 */
/* @0x19c86c vmrs APSR_nzcv, fpscr */
/* @0x19c870 bge 0x19c864 <_Z7DiffDirff+0x78> */
/* @0x19c874 vsub.f32 s15, s14, s15 */
/* @0x19c878 vldr s14, [pc, #36] */
/* @0x19c87c vcmpe.f32 s15, #0 */
/* @0x19c880 vmrs APSR_nzcv, fpscr */
/* @0x19c884 vnegmi.f32 s15, s15 */
/* @0x19c888 vcmpe.f32 s15, s14 */
/* @0x19c88c vmrs APSR_nzcv, fpscr */
/* @0x19c890 vldrgt s14, [pc, #8] */
/* @0x19c894 vsubgt.f32 s15, s14, s15 */
/* @0x19c898 vmov r0, s15 */
/* @0x19c89c bx lr */
/* @0x19c8a0 .word 0x43b40000 */
/* @0x19c8a4 teqmi r4, #0 */
