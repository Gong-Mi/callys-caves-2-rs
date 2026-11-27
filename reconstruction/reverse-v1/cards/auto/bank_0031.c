/* libyoyo.so 覆盖卡组 0031
 * 函数 0x101b0c..0x105b54，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x101b0c · dsMapAddList · size=144 · insn=36 */
/* @0x101b0c vmov s15, r0 */
/* @0x101b10 mvn r3, #-16777216 */
/* @0x101b14 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x101b18 vcvt.f64.s32 d6, s15 */
/* @0x101b1c sub sp, sp, #84 */
/* @0x101b20 mov r6, #0 */
/* @0x101b24 add r7, sp, #80 */
/* @0x101b28 add r0, sp, #48 */
/* @0x101b2c mov r4, #0 */
/* @0x101b30 mov r5, #0 */
/* @0x101b34 str r3, [sp, #0x3c] */
/* @0x101b38 str r3, [sp, #0x4c] */
/* @0x101b3c str r6, [sp, #0x10] */
/* @0x101b40 vmov r8, r9, d6 */
/* @0x101b44 str r6, [sp, #0x28] */
/* @0x101b48 str r6, [sp, #0x38] */
/* @0x101b4c str r6, [sp, #0x48] */
/* @0x101b50 str r6, [sp, #0x2c] */
/* @0x101b54 strd r4, r5, [sp, #48] */
/* @0x101b58 strd r4, r5, [sp, #64] */
/* @0x101b5c strd r8, r9, [r7, #-48]! */
/* @0x101b60 str r2, [sp, #0xc] */
/* @0x101b64 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101b68 ldr r2, [sp, #0xc] */
/* @0x101b6c mov r1, r6 */
/* @0x101b70 str r7, [sp] */
/* @0x101b74 add r0, sp, #16 */
/* @0x101b78 mov r3, #3 */
/* @0x101b7c str r6, [sp, #0x4c] */
/* @0x101b80 vmov s13, r2 */
/* @0x101b84 mov r2, r6 */
/* @0x101b88 vcvt.f64.s32 d7, s13 */
/* @0x101b8c vstr d7, [sp, #64] */
/* @0x101b90 bl 0xff228 <_Z14F_DsMapAddListR6RValueP9CInstanceS2_iPS_> */
/* @0x101b94 add sp, sp, #84 */
/* @0x101b98 pop {r4, r5, r6, r7, r8, r9, pc} */

/* ── FUNC 0x101b9c · dsListCreate · size=56 · insn=14 */
/* @0x101b9c str lr, [sp, #-0x4]! */
/* @0x101ba0 sub sp, sp, #28 */
/* @0x101ba4 add r0, sp, #24 */
/* @0x101ba8 mov r3, #0 */
/* @0x101bac mov r1, r3 */
/* @0x101bb0 str r3, [sp] */
/* @0x101bb4 mov r2, r3 */
/* @0x101bb8 str r3, [r0, #-0x10]! */
/* @0x101bbc bl 0xfffc4 <_Z14F_DsListCreateR6RValueP9CInstanceS2_iPS_> */
/* @0x101bc0 vldr d7, [sp, #8] */
/* @0x101bc4 vcvt.s32.f64 s13, d7 */
/* @0x101bc8 vmov r0, s13 */
/* @0x101bcc add sp, sp, #28 */
/* @0x101bd0 ldr pc, [sp], #4 */

/* ── FUNC 0x101bd4 · dsListClear · size=68 · insn=17 */
/* @0x101bd4 vmov s13, r0 */
/* @0x101bd8 mov r12, #0 */
/* @0x101bdc str lr, [sp, #-0x4]! */
/* @0x101be0 vcvt.f64.s32 d7, s13 */
/* @0x101be4 sub sp, sp, #44 */
/* @0x101be8 mov r1, r12 */
/* @0x101bec add r3, sp, #24 */
/* @0x101bf0 mov r2, r12 */
/* @0x101bf4 str r3, [sp] */
/* @0x101bf8 add r0, sp, #8 */
/* @0x101bfc mov r3, #1 */
/* @0x101c00 str r12, [sp, #0x8] */
/* @0x101c04 str r12, [sp, #0x24] */
/* @0x101c08 vstr d7, [sp, #24] */
/* @0x101c0c bl 0xfc240 <_Z13F_DsListClearR6RValueP9CInstanceS2_iPS_> */
/* @0x101c10 add sp, sp, #44 */
/* @0x101c14 ldr pc, [sp], #4 */

/* ── FUNC 0x101c18 · dsListAddInt · size=92 · insn=23 */
/* @0x101c18 vmov s11, r1 */
/* @0x101c1c mov r12, #0 */
/* @0x101c20 str lr, [sp, #-0x4]! */
/* @0x101c24 vcvt.f64.s32 d6, s11 */
/* @0x101c28 vmov s11, r0 */
/* @0x101c2c sub sp, sp, #60 */
/* @0x101c30 add r3, sp, #24 */
/* @0x101c34 mov r1, r12 */
/* @0x101c38 str r3, [sp] */
/* @0x101c3c mov r2, r12 */
/* @0x101c40 mov r3, #2 */
/* @0x101c44 add r0, sp, #8 */
/* @0x101c48 str r12, [sp, #0x8] */
/* @0x101c4c str r12, [sp, #0x20] */
/* @0x101c50 vcvt.f64.s32 d7, s11 */
/* @0x101c54 str r12, [sp, #0x30] */
/* @0x101c58 str r12, [sp, #0x24] */
/* @0x101c5c vstr d6, [sp, #40] */
/* @0x101c60 str r12, [sp, #0x34] */
/* @0x101c64 vstr d7, [sp, #24] */
/* @0x101c68 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101c6c add sp, sp, #60 */
/* @0x101c70 ldr pc, [sp], #4 */

/* ── FUNC 0x101c74 · dsListAddInt64 · size=88 · insn=22 */
/* @0x101c74 vmov s13, r0 */
/* @0x101c78 mov r12, #0 */
/* @0x101c7c str lr, [sp, #-0x4]! */
/* @0x101c80 vcvt.f64.s32 d7, s13 */
/* @0x101c84 sub sp, sp, #60 */
/* @0x101c88 mov r1, r12 */
/* @0x101c8c add r0, sp, #8 */
/* @0x101c90 mov lr, #10 */
/* @0x101c94 strd r2, r3, [sp, #40] */
/* @0x101c98 add r3, sp, #24 */
/* @0x101c9c mov r2, r12 */
/* @0x101ca0 str r3, [sp] */
/* @0x101ca4 mov r3, #2 */
/* @0x101ca8 str r12, [sp, #0x8] */
/* @0x101cac str r12, [sp, #0x20] */
/* @0x101cb0 str r12, [sp, #0x30] */
/* @0x101cb4 vstr d7, [sp, #24] */
/* @0x101cb8 str r12, [sp, #0x24] */
/* @0x101cbc str lr, [sp, #0x34] */
/* @0x101cc0 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101cc4 add sp, sp, #60 */
/* @0x101cc8 ldr pc, [sp], #4 */

/* ── FUNC 0x101ccc · dsListAddDouble · size=84 · insn=21 */
/* @0x101ccc vmov s13, r0 */
/* @0x101cd0 mov r12, #0 */
/* @0x101cd4 str lr, [sp, #-0x4]! */
/* @0x101cd8 vcvt.f64.s32 d7, s13 */
/* @0x101cdc sub sp, sp, #60 */
/* @0x101ce0 mov r1, r12 */
/* @0x101ce4 add r0, sp, #8 */
/* @0x101ce8 strd r2, r3, [sp, #40] */
/* @0x101cec add r3, sp, #24 */
/* @0x101cf0 mov r2, r12 */
/* @0x101cf4 str r3, [sp] */
/* @0x101cf8 mov r3, #2 */
/* @0x101cfc str r12, [sp, #0x8] */
/* @0x101d00 str r12, [sp, #0x20] */
/* @0x101d04 str r12, [sp, #0x30] */
/* @0x101d08 vstr d7, [sp, #24] */
/* @0x101d0c str r12, [sp, #0x24] */
/* @0x101d10 str r12, [sp, #0x34] */
/* @0x101d14 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101d18 add sp, sp, #60 */
/* @0x101d1c ldr pc, [sp], #4 */

/* ── FUNC 0x101d20 · dsListAddString · size=108 · insn=27 */
/* @0x101d20 vmov s13, r0 */
/* @0x101d24 mov r2, #0 */
/* @0x101d28 push {r4, r5, lr} */
/* @0x101d2c vcvt.f64.s32 d7, s13 */
/* @0x101d30 sub sp, sp, #60 */
/* @0x101d34 mov r3, #0 */
/* @0x101d38 add r5, sp, #56 */
/* @0x101d3c mov r4, #0 */
/* @0x101d40 strd r2, r3, [sp, #40] */
/* @0x101d44 add r0, sp, #40 */
/* @0x101d48 mvn r12, #-16777216 */
/* @0x101d4c str r4, [sp, #0x8] */
/* @0x101d50 str r12, [sp, #0x34] */
/* @0x101d54 str r4, [sp, #0x20] */
/* @0x101d58 vmov r2, r3, d7 */
/* @0x101d5c str r4, [sp, #0x30] */
/* @0x101d60 str r4, [sp, #0x24] */
/* @0x101d64 strd r2, r3, [r5, #-32]! */
/* @0x101d68 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x101d6c mov r1, r4 */
/* @0x101d70 str r5, [sp] */
/* @0x101d74 mov r2, r4 */
/* @0x101d78 add r0, sp, #8 */
/* @0x101d7c mov r3, #2 */
/* @0x101d80 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_> */
/* @0x101d84 add sp, sp, #60 */
/* @0x101d88 pop {r4, r5, pc} */

/* ── FUNC 0x101d8c · F_DsQueueDequeue(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x101d8c push {r3, r4, r5, r6, r7, lr} */
/* @0x101d90 mov r1, #0 */
/* @0x101d94 mov r4, r0 */
/* @0x101d98 ldr r0, [sp, #0x18] */
/* @0x101d9c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x101da0 cmp r0, #0 */
/* @0x101da4 blt 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x101da8 ldr r3, [pc, #0x288] */
/* @0x101dac ldr r3, [pc, r3] */
/* @0x101db0 ldr r3, [r3] */
/* @0x101db4 cmp r0, r3 */
/* @0x101db8 bge 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x101dbc ldr r3, [pc, #0x278] */
/* @0x101dc0 ldr r3, [pc, r3] */
/* @0x101dc4 ldr r3, [r3, #0x4] */
/* @0x101dc8 ldr r0, [r3, r0, lsl #2] */
/* @0x101dcc cmp r0, #0 */
/* @0x101dd0 beq 0x101e94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x101dd4 bl 0x205ab0 <_ZN9CDS_Queue7DequeueEv> */
/* @0x101dd8 subs r5, r0, #0 */
/* @0x101ddc streq r5, [r4] */
/* @0x101de0 streq r5, [r4, #0x4] */
/* @0x101de4 moveq r3, #5 */
/* @0x101de8 streq r3, [r4, #0xc] */
/* @0x101dec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x101df0 ldr r2, [r4, #0xc] */
/* @0x101df4 bic r3, r2, #-16777216 */
/* @0x101df8 cmp r3, #1 */
/* @0x101dfc beq 0x101ec0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x101e00 cmp r3, #2 */
/* @0x101e04 bne 0x101e2c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x101e08 sub r2, r2, #1 */
/* @0x101e0c bic r2, r2, #-16777216 */
/* @0x101e10 bic r2, r2, #3 */
/* @0x101e14 cmp r2, #0 */
/* @0x101e18 beq 0x101f94 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x101e1c mov r2, #0 */
/* @0x101e20 mov r3, #5 */
/* @0x101e24 str r2, [r4, #0x8] */
/* @0x101e28 str r3, [r4, #0xc] */
/* @0x101e2c ldr r3, [r5, #0xc] */
/* @0x101e30 mov r1, #0 */
/* @0x101e34 ldr r2, [r5, #0x8] */
/* @0x101e38 str r1, [r4] */
/* @0x101e3c str r3, [r4, #0xc] */
/* @0x101e40 ldr r3, [r5, #0xc] */
/* @0x101e44 str r2, [r4, #0x8] */
/* @0x101e48 bic r3, r3, #-16777216 */
/* @0x101e4c cmp r3, #14 */
/* @0x101e50 addls pc, pc, r3, lsl #2 */
/* @0x101e54 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e58 b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x101e5c b 0x101f18 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x101e60 b 0x101f30 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x101e64 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x101e68 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e6c b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e70 b 0x101ef4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x101e74 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x101e78 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e7c b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e80 b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x101e84 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e88 b 0x101eb0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x101e8c b 0x101eb4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x101e90 b 0x101ea8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x101e94 ldr r0, [pc, #0x1a4] */
/* @0x101e98 mov r1, #0 */
/* @0x101e9c pop {r3, r4, r5, r6, r7, lr} */
/* @0x101ea0 add r0, pc, r0 */
/* @0x101ea4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x101ea8 ldr r3, [r5] */
/* @0x101eac str r3, [r4] */
/* @0x101eb0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x101eb4 ldm r5, {r2, r3} */
/* @0x101eb8 stm r4, {r2, r3} */
/* @0x101ebc pop {r3, r4, r5, r6, r7, pc} */
/* @0x101ec0 ldr r6, [r4] */
/* @0x101ec4 cmp r6, #0 */
/* @0x101ec8 beq 0x101ee8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x101ecc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x101ed0 ldr r7, [r6, #0x4] */
/* @0x101ed4 sub r7, r7, #1 */
/* @0x101ed8 str r7, [r6, #0x4] */
/* @0x101edc cmp r7, #0 */
/* @0x101ee0 beq 0x101f5c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x101ee4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x101ee8 mov r3, #0 */
/* @0x101eec str r3, [r4] */
/* @0x101ef0 b 0x101e2c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x101ef4 ldr r3, [r5] */
/* @0x101ef8 str r3, [r4] */
/* @0x101efc ldr r3, [r5] */
/* @0x101f00 cmp r3, #0 */
/* @0x101f04 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x101f08 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x101f0c ldr r1, [r5] */
/* @0x101f10 pop {r3, r4, r5, r6, r7, lr} */
/* @0x101f14 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x101f18 ldr r3, [r5] */
/* @0x101f1c cmp r3, #0 */
/* @0x101f20 ldrne r2, [r3, #0x4] */
/* @0x101f24 addne r2, r2, #1 */
/* @0x101f28 strne r2, [r3, #0x4] */
/* @0x101f2c b 0x101eac <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x101f30 ldr r3, [r5] */
/* @0x101f34 cmp r3, #0 */
/* @0x101f38 str r3, [r4] */
/* @0x101f3c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x101f40 ldr r1, [r3, #0x8] */
/* @0x101f44 ldr r2, [r3] */
/* @0x101f48 cmp r1, #0 */
/* @0x101f4c streq r4, [r3, #0x8] */
/* @0x101f50 add r2, r2, #1 */
/* @0x101f54 str r2, [r3] */
/* @0x101f58 pop {r3, r4, r5, r6, r7, pc} */
/* @0x101f5c ldr r0, [r6] */
/* @0x101f60 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x101f64 str r7, [r6] */
/* @0x101f68 str r7, [r6, #0x8] */
/* @0x101f6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x101f70 ldr r7, [r6, #0x4] */
/* @0x101f74 sub r7, r7, #1 */
/* @0x101f78 str r7, [r6, #0x4] */
/* @0x101f7c cmp r7, #0 */
/* @0x101f80 beq 0x101fa0 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x101f84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x101f88 mov r0, r6 */
/* @0x101f8c bl 0x27d1d0 <_ZdlPv> */
/* @0x101f90 b 0x101ee4 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x101f94 mov r0, r4 */
/* @0x101f98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x101f9c b 0x101e1c <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x101fa0 ldr r0, [r6] */
/* @0x101fa4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x101fa8 str r7, [r6] */
/* @0x101fac str r7, [r6, #0x8] */
/* @0x101fb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x101fb4 ldr r7, [r6, #0x4] */
/* @0x101fb8 sub r7, r7, #1 */
/* @0x101fbc str r7, [r6, #0x4] */
/* @0x101fc0 cmp r7, #0 */
/* @0x101fc4 beq 0x101fd8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x101fc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x101fcc mov r0, r6 */
/* @0x101fd0 bl 0x27d1d0 <_ZdlPv> */
/* @0x101fd4 b 0x101f84 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x101fd8 ldr r0, [r6] */
/* @0x101fdc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x101fe0 str r7, [r6] */
/* @0x101fe4 str r7, [r6, #0x8] */
/* @0x101fe8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x101fec ldr r3, [r6, #0x4] */
/* @0x101ff0 sub r3, r3, #1 */
/* @0x101ff4 str r3, [r6, #0x4] */
/* @0x101ff8 cmp r3, #0 */
/* @0x101ffc beq 0x102010 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x102000 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102004 mov r0, r6 */
/* @0x102008 bl 0x27d1d0 <_ZdlPv> */
/* @0x10200c b 0x101fc8 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x102010 ldr r0, [r6] */
/* @0x102014 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102018 mov r3, #0 */
/* @0x10201c mov r0, r6 */
/* @0x102020 str r3, [r6] */
/* @0x102024 str r3, [r6, #0x8] */
/* @0x102028 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x10202c mov r0, r6 */
/* @0x102030 bl 0x27d1d0 <_ZdlPv> */
/* @0x102034 b 0x102000 <_Z16F_DsQueueDequeueR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x102038 eoreq r12, lr, r0, asr #1 */
/* @0x10203c strhteq r12, [lr], -r0 */
/* @0x102040 eoreq r5, r3, r12, asr sp */

/* ── FUNC 0x102044 · F_DsListSetPre(RValue&, CInstance*, CInstance*, int, RValue*) · size=700 · insn=175 */
/* @0x102044 push {r3, r4, r5, r6, r7, lr} */
/* @0x102048 mov r1, #0 */
/* @0x10204c ldr r4, [sp, #0x18] */
/* @0x102050 mov r5, r0 */
/* @0x102054 mov r0, r4 */
/* @0x102058 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10205c cmp r0, #0 */
/* @0x102060 blt 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x102064 ldr r3, [pc, #0x288] */
/* @0x102068 ldr r3, [pc, r3] */
/* @0x10206c ldr r3, [r3] */
/* @0x102070 cmp r0, r3 */
/* @0x102074 bge 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x102078 ldr r3, [pc, #0x278] */
/* @0x10207c ldr r3, [pc, r3] */
/* @0x102080 ldr r3, [r3, #0x4] */
/* @0x102084 ldr r6, [r3, r0, lsl #2] */
/* @0x102088 cmp r6, #0 */
/* @0x10208c beq 0x102154 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x102090 mov r1, #1 */
/* @0x102094 mov r0, r4 */
/* @0x102098 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10209c add r2, r4, #32 */
/* @0x1020a0 mov r3, #0 */
/* @0x1020a4 mov r1, r0 */
/* @0x1020a8 mov r0, r6 */
/* @0x1020ac bl 0x2060c0 <_ZN8CDS_List3SetEiP6RValueS1_> */
/* @0x1020b0 ldr r2, [r5, #0xc] */
/* @0x1020b4 bic r3, r2, #-16777216 */
/* @0x1020b8 cmp r3, #1 */
/* @0x1020bc beq 0x102184 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1020c0 cmp r3, #2 */
/* @0x1020c4 bne 0x1020ec <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1020c8 sub r2, r2, #1 */
/* @0x1020cc bic r2, r2, #-16777216 */
/* @0x1020d0 bic r2, r2, #3 */
/* @0x1020d4 cmp r2, #0 */
/* @0x1020d8 beq 0x102258 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1020dc mov r2, #0 */
/* @0x1020e0 mov r3, #5 */
/* @0x1020e4 str r2, [r5, #0x8] */
/* @0x1020e8 str r3, [r5, #0xc] */
/* @0x1020ec ldr r3, [r4, #0x2c] */
/* @0x1020f0 mov r1, #0 */
/* @0x1020f4 ldr r2, [r4, #0x28] */
/* @0x1020f8 str r1, [r5] */
/* @0x1020fc str r3, [r5, #0xc] */
/* @0x102100 ldr r3, [r4, #0x2c] */
/* @0x102104 str r2, [r5, #0x8] */
/* @0x102108 bic r3, r3, #-16777216 */
/* @0x10210c cmp r3, #14 */
/* @0x102110 addls pc, pc, r3, lsl #2 */
/* @0x102114 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102118 b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x10211c b 0x1021dc <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x102120 b 0x1021f4 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x102124 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102128 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x10212c b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102130 b 0x1021b8 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x102134 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102138 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x10213c b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102140 b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102144 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102148 b 0x102170 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x10214c b 0x102174 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102150 b 0x102168 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102154 ldr r0, [pc, #0x1a0] */
/* @0x102158 mov r1, #0 */
/* @0x10215c pop {r3, r4, r5, r6, r7, lr} */
/* @0x102160 add r0, pc, r0 */
/* @0x102164 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x102168 ldr r3, [r4, #0x20] */
/* @0x10216c str r3, [r5] */
/* @0x102170 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102174 ldr r2, [r4, #0x20] */
/* @0x102178 ldr r3, [r4, #0x24] */
/* @0x10217c stm r5, {r2, r3} */
/* @0x102180 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102184 ldr r6, [r5] */
/* @0x102188 cmp r6, #0 */
/* @0x10218c beq 0x1021ac <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x102190 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102194 ldr r7, [r6, #0x4] */
/* @0x102198 sub r7, r7, #1 */
/* @0x10219c str r7, [r6, #0x4] */
/* @0x1021a0 cmp r7, #0 */
/* @0x1021a4 beq 0x102220 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x1021a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1021ac mov r3, #0 */
/* @0x1021b0 str r3, [r5] */
/* @0x1021b4 b 0x1020ec <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1021b8 ldr r3, [r4, #0x20] */
/* @0x1021bc str r3, [r5] */
/* @0x1021c0 ldr r3, [r4, #0x20] */
/* @0x1021c4 cmp r3, #0 */
/* @0x1021c8 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1021cc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1021d0 ldr r1, [r4, #0x20] */
/* @0x1021d4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1021d8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1021dc ldr r3, [r4, #0x20] */
/* @0x1021e0 cmp r3, #0 */
/* @0x1021e4 ldrne r2, [r3, #0x4] */
/* @0x1021e8 addne r2, r2, #1 */
/* @0x1021ec strne r2, [r3, #0x4] */
/* @0x1021f0 b 0x10216c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1021f4 ldr r3, [r4, #0x20] */
/* @0x1021f8 cmp r3, #0 */
/* @0x1021fc str r3, [r5] */
/* @0x102200 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102204 ldr r1, [r3, #0x8] */
/* @0x102208 ldr r2, [r3] */
/* @0x10220c cmp r1, #0 */
/* @0x102210 streq r5, [r3, #0x8] */
/* @0x102214 add r2, r2, #1 */
/* @0x102218 str r2, [r3] */
/* @0x10221c pop {r3, r4, r5, r6, r7, pc} */
/* @0x102220 ldr r0, [r6] */
/* @0x102224 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102228 str r7, [r6] */
/* @0x10222c str r7, [r6, #0x8] */
/* @0x102230 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102234 ldr r7, [r6, #0x4] */
/* @0x102238 sub r7, r7, #1 */
/* @0x10223c str r7, [r6, #0x4] */
/* @0x102240 cmp r7, #0 */
/* @0x102244 beq 0x102264 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x102248 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10224c mov r0, r6 */
/* @0x102250 bl 0x27d1d0 <_ZdlPv> */
/* @0x102254 b 0x1021a8 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x102258 mov r0, r5 */
/* @0x10225c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x102260 b 0x1020dc <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x102264 ldr r0, [r6] */
/* @0x102268 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10226c str r7, [r6] */
/* @0x102270 str r7, [r6, #0x8] */
/* @0x102274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102278 ldr r7, [r6, #0x4] */
/* @0x10227c sub r7, r7, #1 */
/* @0x102280 str r7, [r6, #0x4] */
/* @0x102284 cmp r7, #0 */
/* @0x102288 beq 0x10229c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x10228c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102290 mov r0, r6 */
/* @0x102294 bl 0x27d1d0 <_ZdlPv> */
/* @0x102298 b 0x102248 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x10229c ldr r0, [r6] */
/* @0x1022a0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1022a4 str r7, [r6] */
/* @0x1022a8 str r7, [r6, #0x8] */
/* @0x1022ac bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1022b0 ldr r7, [r6, #0x4] */
/* @0x1022b4 sub r7, r7, #1 */
/* @0x1022b8 str r7, [r6, #0x4] */
/* @0x1022bc cmp r7, #0 */
/* @0x1022c0 bne 0x1022e4 <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x1022c4 ldr r0, [r6] */
/* @0x1022c8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1022cc mov r0, r6 */
/* @0x1022d0 str r7, [r6] */
/* @0x1022d4 str r7, [r6, #0x8] */
/* @0x1022d8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1022dc mov r0, r6 */
/* @0x1022e0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1022e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1022e8 mov r0, r6 */
/* @0x1022ec bl 0x27d1d0 <_ZdlPv> */
/* @0x1022f0 b 0x10228c <_Z14F_DsListSetPreR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x1022f4 eoreq r11, lr, r4, lsl r12 */
/* @0x1022f8 eoreq r11, lr, r4, lsl #24 */
/* @0x1022fc mlaeq r3, r12, r10, r5 */

/* ── FUNC 0x102300 · F_DsListMarkAsList(RValue&, CInstance*, CInstance*, int, RValue*) · size=720 · insn=180 */
/* @0x102300 push {r3, r4, r5, r6, r7, lr} */
/* @0x102304 mov r1, #0 */
/* @0x102308 ldr r5, [sp, #0x18] */
/* @0x10230c mov r4, r0 */
/* @0x102310 mov r0, r5 */
/* @0x102314 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102318 cmp r0, #0 */
/* @0x10231c blt 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x102320 ldr r3, [pc, #0x29c] */
/* @0x102324 ldr r3, [pc, r3] */
/* @0x102328 ldr r3, [r3] */
/* @0x10232c cmp r0, r3 */
/* @0x102330 bge 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x102334 ldr r3, [pc, #0x28c] */
/* @0x102338 ldr r3, [pc, r3] */
/* @0x10233c ldr r3, [r3, #0x4] */
/* @0x102340 ldr r6, [r3, r0, lsl #2] */
/* @0x102344 cmp r6, #0 */
/* @0x102348 beq 0x102418 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x10234c mov r0, r5 */
/* @0x102350 mov r1, #1 */
/* @0x102354 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102358 mov r1, r0 */
/* @0x10235c mov r0, r6 */
/* @0x102360 bl 0x2031f4 <_ZN8CDS_List8GetValueEi> */
/* @0x102364 subs r5, r0, #0 */
/* @0x102368 ldrne r3, [r5, #0xc] */
/* @0x10236c orrne r3, r3, #1073741824 */
/* @0x102370 strne r3, [r5, #0xc] */
/* @0x102374 ldr r2, [r4, #0xc] */
/* @0x102378 bic r3, r2, #-16777216 */
/* @0x10237c cmp r3, #1 */
/* @0x102380 beq 0x10244c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x102384 cmp r3, #2 */
/* @0x102388 bne 0x1023b0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10238c sub r2, r2, #1 */
/* @0x102390 bic r2, r2, #-16777216 */
/* @0x102394 bic r2, r2, #3 */
/* @0x102398 cmp r2, #0 */
/* @0x10239c beq 0x102528 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x1023a0 mov r2, #0 */
/* @0x1023a4 mov r3, #5 */
/* @0x1023a8 str r2, [r4, #0x8] */
/* @0x1023ac str r3, [r4, #0xc] */
/* @0x1023b0 ldr r3, [r5, #0xc] */
/* @0x1023b4 mov r2, #0 */
/* @0x1023b8 ldr r1, [r5, #0x8] */
/* @0x1023bc str r2, [r4] */
/* @0x1023c0 str r3, [r4, #0xc] */
/* @0x1023c4 ldr r2, [r5, #0xc] */
/* @0x1023c8 str r1, [r4, #0x8] */
/* @0x1023cc bic r2, r2, #-16777216 */
/* @0x1023d0 cmp r2, #14 */
/* @0x1023d4 addls pc, pc, r2, lsl #2 */
/* @0x1023d8 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1023dc b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1023e0 b 0x1024a8 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x1023e4 b 0x1024c4 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x1023e8 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x1023ec b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1023f0 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1023f4 b 0x102480 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x1023f8 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x1023fc b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102400 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102404 b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x102408 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x10240c b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102410 b 0x102440 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x102414 b 0x10242c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102418 ldr r0, [pc, #0x1ac] */
/* @0x10241c mov r1, #0 */
/* @0x102420 pop {r3, r4, r5, r6, r7, lr} */
/* @0x102424 add r0, pc, r0 */
/* @0x102428 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x10242c ldr r2, [r5] */
/* @0x102430 str r2, [r4] */
/* @0x102434 bic r3, r3, #-16777216 */
/* @0x102438 str r3, [r4, #0xc] */
/* @0x10243c pop {r3, r4, r5, r6, r7, pc} */
/* @0x102440 ldm r5, {r1, r2} */
/* @0x102444 stm r4, {r1, r2} */
/* @0x102448 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x10244c ldr r6, [r4] */
/* @0x102450 cmp r6, #0 */
/* @0x102454 beq 0x102474 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x102458 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10245c ldr r7, [r6, #0x4] */
/* @0x102460 sub r7, r7, #1 */
/* @0x102464 str r7, [r6, #0x4] */
/* @0x102468 cmp r7, #0 */
/* @0x10246c beq 0x1024f0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x102470 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102474 mov r3, #0 */
/* @0x102478 str r3, [r4] */
/* @0x10247c b 0x1023b0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x102480 ldr r2, [r5] */
/* @0x102484 str r2, [r4] */
/* @0x102488 ldr r2, [r5] */
/* @0x10248c cmp r2, #0 */
/* @0x102490 beq 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102494 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x102498 ldr r1, [r5] */
/* @0x10249c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1024a0 ldr r3, [r4, #0xc] */
/* @0x1024a4 b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1024a8 ldr r2, [r5] */
/* @0x1024ac cmp r2, #0 */
/* @0x1024b0 ldrne r3, [r2, #0x4] */
/* @0x1024b4 addne r3, r3, #1 */
/* @0x1024b8 strne r3, [r2, #0x4] */
/* @0x1024bc ldrne r3, [r4, #0xc] */
/* @0x1024c0 b 0x102430 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x1024c4 ldr r2, [r5] */
/* @0x1024c8 cmp r2, #0 */
/* @0x1024cc str r2, [r4] */
/* @0x1024d0 beq 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1024d4 ldr r0, [r2, #0x8] */
/* @0x1024d8 ldr r1, [r2] */
/* @0x1024dc cmp r0, #0 */
/* @0x1024e0 streq r4, [r2, #0x8] */
/* @0x1024e4 add r1, r1, #1 */
/* @0x1024e8 str r1, [r2] */
/* @0x1024ec b 0x102434 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1024f0 ldr r0, [r6] */
/* @0x1024f4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1024f8 str r7, [r6] */
/* @0x1024fc str r7, [r6, #0x8] */
/* @0x102500 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102504 ldr r7, [r6, #0x4] */
/* @0x102508 sub r7, r7, #1 */
/* @0x10250c str r7, [r6, #0x4] */
/* @0x102510 cmp r7, #0 */
/* @0x102514 beq 0x102534 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x102518 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10251c mov r0, r6 */
/* @0x102520 bl 0x27d1d0 <_ZdlPv> */
/* @0x102524 b 0x102470 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x102528 mov r0, r4 */
/* @0x10252c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x102530 b 0x1023a0 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x102534 ldr r0, [r6] */
/* @0x102538 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10253c str r7, [r6] */
/* @0x102540 str r7, [r6, #0x8] */
/* @0x102544 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102548 ldr r7, [r6, #0x4] */
/* @0x10254c sub r7, r7, #1 */
/* @0x102550 str r7, [r6, #0x4] */
/* @0x102554 cmp r7, #0 */
/* @0x102558 beq 0x10256c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x10255c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102560 mov r0, r6 */
/* @0x102564 bl 0x27d1d0 <_ZdlPv> */
/* @0x102568 b 0x102518 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x218> */
/* @0x10256c ldr r0, [r6] */
/* @0x102570 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102574 str r7, [r6] */
/* @0x102578 str r7, [r6, #0x8] */
/* @0x10257c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102580 ldr r7, [r6, #0x4] */
/* @0x102584 sub r7, r7, #1 */
/* @0x102588 str r7, [r6, #0x4] */
/* @0x10258c cmp r7, #0 */
/* @0x102590 bne 0x1025b4 <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x2b4> */
/* @0x102594 ldr r0, [r6] */
/* @0x102598 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10259c mov r0, r6 */
/* @0x1025a0 str r7, [r6] */
/* @0x1025a4 str r7, [r6, #0x8] */
/* @0x1025a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1025ac mov r0, r6 */
/* @0x1025b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1025b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1025b8 mov r0, r6 */
/* @0x1025bc bl 0x27d1d0 <_ZdlPv> */
/* @0x1025c0 b 0x10255c <_Z18F_DsListMarkAsListR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x1025c4 eoreq r11, lr, r8, asr r9 */
/* @0x1025c8 eoreq r11, lr, r8, asr #18 */
/* @0x1025cc .word 0x002357d8 */

/* ── FUNC 0x1025d0 · F_DsListMarkAsMap(RValue&, CInstance*, CInstance*, int, RValue*) · size=720 · insn=180 */
/* @0x1025d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1025d4 mov r1, #0 */
/* @0x1025d8 ldr r5, [sp, #0x18] */
/* @0x1025dc mov r4, r0 */
/* @0x1025e0 mov r0, r5 */
/* @0x1025e4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1025e8 cmp r0, #0 */
/* @0x1025ec blt 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1025f0 ldr r3, [pc, #0x29c] */
/* @0x1025f4 ldr r3, [pc, r3] */
/* @0x1025f8 ldr r3, [r3] */
/* @0x1025fc cmp r0, r3 */
/* @0x102600 bge 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x102604 ldr r3, [pc, #0x28c] */
/* @0x102608 ldr r3, [pc, r3] */
/* @0x10260c ldr r3, [r3, #0x4] */
/* @0x102610 ldr r6, [r3, r0, lsl #2] */
/* @0x102614 cmp r6, #0 */
/* @0x102618 beq 0x1026e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x10261c mov r0, r5 */
/* @0x102620 mov r1, #1 */
/* @0x102624 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102628 mov r1, r0 */
/* @0x10262c mov r0, r6 */
/* @0x102630 bl 0x2031f4 <_ZN8CDS_List8GetValueEi> */
/* @0x102634 subs r5, r0, #0 */
/* @0x102638 ldrne r3, [r5, #0xc] */
/* @0x10263c orrne r3, r3, #-2147483648 */
/* @0x102640 strne r3, [r5, #0xc] */
/* @0x102644 ldr r2, [r4, #0xc] */
/* @0x102648 bic r3, r2, #-16777216 */
/* @0x10264c cmp r3, #1 */
/* @0x102650 beq 0x10271c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x102654 cmp r3, #2 */
/* @0x102658 bne 0x102680 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x10265c sub r2, r2, #1 */
/* @0x102660 bic r2, r2, #-16777216 */
/* @0x102664 bic r2, r2, #3 */
/* @0x102668 cmp r2, #0 */
/* @0x10266c beq 0x1027f8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x102670 mov r2, #0 */
/* @0x102674 mov r3, #5 */
/* @0x102678 str r2, [r4, #0x8] */
/* @0x10267c str r3, [r4, #0xc] */
/* @0x102680 ldr r3, [r5, #0xc] */
/* @0x102684 mov r2, #0 */
/* @0x102688 ldr r1, [r5, #0x8] */
/* @0x10268c str r2, [r4] */
/* @0x102690 str r3, [r4, #0xc] */
/* @0x102694 ldr r2, [r5, #0xc] */
/* @0x102698 str r1, [r4, #0x8] */
/* @0x10269c bic r2, r2, #-16777216 */
/* @0x1026a0 cmp r2, #14 */
/* @0x1026a4 addls pc, pc, r2, lsl #2 */
/* @0x1026a8 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026ac b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1026b0 b 0x102778 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x1026b4 b 0x102794 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1c4> */
/* @0x1026b8 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x1026bc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026c0 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026c4 b 0x102750 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x1026c8 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x1026cc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026d0 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026d4 b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1026d8 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026dc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1026e0 b 0x102710 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1026e4 b 0x1026fc <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x1026e8 ldr r0, [pc, #0x1ac] */
/* @0x1026ec mov r1, #0 */
/* @0x1026f0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1026f4 add r0, pc, r0 */
/* @0x1026f8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1026fc ldr r2, [r5] */
/* @0x102700 str r2, [r4] */
/* @0x102704 bic r3, r3, #-16777216 */
/* @0x102708 str r3, [r4, #0xc] */
/* @0x10270c pop {r3, r4, r5, r6, r7, pc} */
/* @0x102710 ldm r5, {r1, r2} */
/* @0x102714 stm r4, {r1, r2} */
/* @0x102718 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x10271c ldr r6, [r4] */
/* @0x102720 cmp r6, #0 */
/* @0x102724 beq 0x102744 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x174> */
/* @0x102728 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10272c ldr r7, [r6, #0x4] */
/* @0x102730 sub r7, r7, #1 */
/* @0x102734 str r7, [r6, #0x4] */
/* @0x102738 cmp r7, #0 */
/* @0x10273c beq 0x1027c0 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x102740 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102744 mov r3, #0 */
/* @0x102748 str r3, [r4] */
/* @0x10274c b 0x102680 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x102750 ldr r2, [r5] */
/* @0x102754 str r2, [r4] */
/* @0x102758 ldr r2, [r5] */
/* @0x10275c cmp r2, #0 */
/* @0x102760 beq 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102764 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x102768 ldr r1, [r5] */
/* @0x10276c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x102770 ldr r3, [r4, #0xc] */
/* @0x102774 b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102778 ldr r2, [r5] */
/* @0x10277c cmp r2, #0 */
/* @0x102780 ldrne r3, [r2, #0x4] */
/* @0x102784 addne r3, r3, #1 */
/* @0x102788 strne r3, [r2, #0x4] */
/* @0x10278c ldrne r3, [r4, #0xc] */
/* @0x102790 b 0x102700 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102794 ldr r2, [r5] */
/* @0x102798 cmp r2, #0 */
/* @0x10279c str r2, [r4] */
/* @0x1027a0 beq 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1027a4 ldr r0, [r2, #0x8] */
/* @0x1027a8 ldr r1, [r2] */
/* @0x1027ac cmp r0, #0 */
/* @0x1027b0 streq r4, [r2, #0x8] */
/* @0x1027b4 add r1, r1, #1 */
/* @0x1027b8 str r1, [r2] */
/* @0x1027bc b 0x102704 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1027c0 ldr r0, [r6] */
/* @0x1027c4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1027c8 str r7, [r6] */
/* @0x1027cc str r7, [r6, #0x8] */
/* @0x1027d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1027d4 ldr r7, [r6, #0x4] */
/* @0x1027d8 sub r7, r7, #1 */
/* @0x1027dc str r7, [r6, #0x4] */
/* @0x1027e0 cmp r7, #0 */
/* @0x1027e4 beq 0x102804 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x234> */
/* @0x1027e8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1027ec mov r0, r6 */
/* @0x1027f0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1027f4 b 0x102740 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x1027f8 mov r0, r4 */
/* @0x1027fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x102800 b 0x102670 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x102804 ldr r0, [r6] */
/* @0x102808 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10280c str r7, [r6] */
/* @0x102810 str r7, [r6, #0x8] */
/* @0x102814 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102818 ldr r7, [r6, #0x4] */
/* @0x10281c sub r7, r7, #1 */
/* @0x102820 str r7, [r6, #0x4] */
/* @0x102824 cmp r7, #0 */
/* @0x102828 beq 0x10283c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x10282c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102830 mov r0, r6 */
/* @0x102834 bl 0x27d1d0 <_ZdlPv> */
/* @0x102838 b 0x1027e8 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x218> */
/* @0x10283c ldr r0, [r6] */
/* @0x102840 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102844 str r7, [r6] */
/* @0x102848 str r7, [r6, #0x8] */
/* @0x10284c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102850 ldr r7, [r6, #0x4] */
/* @0x102854 sub r7, r7, #1 */
/* @0x102858 str r7, [r6, #0x4] */
/* @0x10285c cmp r7, #0 */
/* @0x102860 bne 0x102884 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x2b4> */
/* @0x102864 ldr r0, [r6] */
/* @0x102868 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10286c mov r0, r6 */
/* @0x102870 str r7, [r6] */
/* @0x102874 str r7, [r6, #0x8] */
/* @0x102878 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x10287c mov r0, r6 */
/* @0x102880 bl 0x27d1d0 <_ZdlPv> */
/* @0x102884 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102888 mov r0, r6 */
/* @0x10288c bl 0x27d1d0 <_ZdlPv> */
/* @0x102890 b 0x10282c <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x102894 eoreq r11, lr, r8, lsl #13 */
/* @0x102898 eoreq r11, lr, r8, ror r6 */
/* @0x10289c eoreq r5, r3, r8, lsl #10 */

/* ── FUNC 0x1028a0 · dsListAddMap · size=204 · insn=51 */
/* @0x1028a0 vmov s11, r1 */
/* @0x1028a4 mov r3, #2 */
/* @0x1028a8 push {r4, r5, r6, r7, lr} */
/* @0x1028ac mov r5, r0 */
/* @0x1028b0 vcvt.f64.s32 d6, s11 */
/* @0x1028b4 sub sp, sp, #60 */
/* @0x1028b8 vmov s11, r5 */
/* @0x1028bc add r6, sp, #8 */
/* @0x1028c0 mov r4, #0 */
/* @0x1028c4 add r7, sp, #24 */
/* @0x1028c8 mov r1, r4 */
/* @0x1028cc mov r2, r4 */
/* @0x1028d0 mov r0, r6 */
/* @0x1028d4 str r7, [sp] */
/* @0x1028d8 str r4, [sp, #0x8] */
/* @0x1028dc str r4, [sp, #0x20] */
/* @0x1028e0 vcvt.f64.s32 d7, s11 */
/* @0x1028e4 vstr d6, [sp, #40] */
/* @0x1028e8 str r4, [sp, #0x30] */
/* @0x1028ec str r4, [sp, #0x24] */
/* @0x1028f0 str r4, [sp, #0x34] */
/* @0x1028f4 vstr d7, [sp, #24] */
/* @0x1028f8 bl 0xfc474 <_Z11F_DsListAddR6RValueP9CInstanceS2_iPS_> */
/* @0x1028fc cmp r5, r4 */
/* @0x102900 blt 0x10295c <dsListAddMap+0xbc> */
/* @0x102904 ldr r3, [pc, #0x58] */
/* @0x102908 ldr r3, [pc, r3] */
/* @0x10290c ldr r3, [r3] */
/* @0x102910 cmp r5, r3 */
/* @0x102914 bge 0x10295c <dsListAddMap+0xbc> */
/* @0x102918 ldr r3, [pc, #0x48] */
/* @0x10291c ldr r3, [pc, r3] */
/* @0x102920 ldr r3, [r3, #0x4] */
/* @0x102924 ldr r0, [r3, r5, lsl #2] */
/* @0x102928 cmp r0, r4 */
/* @0x10292c beq 0x10295c <dsListAddMap+0xbc> */
/* @0x102930 bl 0x2052b8 <_ZN8CDS_List4SizeEv> */
/* @0x102934 mov r1, r4 */
/* @0x102938 str r7, [sp] */
/* @0x10293c mov r2, r4 */
/* @0x102940 mov r3, #2 */
/* @0x102944 sub r0, r0, #1 */
/* @0x102948 vmov s14, r0 */
/* @0x10294c mov r0, r6 */
/* @0x102950 vcvt.f64.s32 d7, s14 */
/* @0x102954 vstr d7, [sp, #40] */
/* @0x102958 bl 0x1025d0 <_Z17F_DsListMarkAsMapR6RValueP9CInstanceS2_iPS_> */
/* @0x10295c add sp, sp, #60 */
/* @0x102960 pop {r4, r5, r6, r7, pc} */
/* @0x102964 eoreq r11, lr, r4, ror r3 */
/* @0x102968 eoreq r11, lr, r4, ror #6 */

/* ── FUNC 0x10296c · F_DsPriorityFindPriority(RValue&, CInstance*, CInstance*, int, RValue*) · size=704 · insn=176 */
/* @0x10296c push {r3, r4, r5, r6, r7, lr} */
/* @0x102970 mov r1, #0 */
/* @0x102974 ldr r5, [sp, #0x18] */
/* @0x102978 mov r4, r0 */
/* @0x10297c mov r0, r5 */
/* @0x102980 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102984 cmp r0, #0 */
/* @0x102988 blt 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x10298c ldr r3, [pc, #0x28c] */
/* @0x102990 ldr r3, [pc, r3] */
/* @0x102994 ldr r3, [r3] */
/* @0x102998 cmp r0, r3 */
/* @0x10299c bge 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x1029a0 ldr r3, [pc, #0x27c] */
/* @0x1029a4 ldr r3, [pc, r3] */
/* @0x1029a8 ldr r3, [r3, #0x4] */
/* @0x1029ac ldr r0, [r3, r0, lsl #2] */
/* @0x1029b0 cmp r0, #0 */
/* @0x1029b4 beq 0x102a7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x110> */
/* @0x1029b8 add r1, r5, #16 */
/* @0x1029bc bl 0x203f90 <_ZN12CDS_Priority4FindEP6RValue> */
/* @0x1029c0 subs r5, r0, #0 */
/* @0x1029c4 streq r5, [r4] */
/* @0x1029c8 streq r5, [r4, #0x4] */
/* @0x1029cc moveq r3, #5 */
/* @0x1029d0 streq r3, [r4, #0xc] */
/* @0x1029d4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1029d8 ldr r2, [r4, #0xc] */
/* @0x1029dc bic r3, r2, #-16777216 */
/* @0x1029e0 cmp r3, #1 */
/* @0x1029e4 beq 0x102aa8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1029e8 cmp r3, #2 */
/* @0x1029ec bne 0x102a14 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x1029f0 sub r2, r2, #1 */
/* @0x1029f4 bic r2, r2, #-16777216 */
/* @0x1029f8 bic r2, r2, #3 */
/* @0x1029fc cmp r2, #0 */
/* @0x102a00 beq 0x102b7c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x102a04 mov r2, #0 */
/* @0x102a08 mov r3, #5 */
/* @0x102a0c str r2, [r4, #0x8] */
/* @0x102a10 str r3, [r4, #0xc] */
/* @0x102a14 ldr r3, [r5, #0xc] */
/* @0x102a18 mov r1, #0 */
/* @0x102a1c ldr r2, [r5, #0x8] */
/* @0x102a20 str r1, [r4] */
/* @0x102a24 str r3, [r4, #0xc] */
/* @0x102a28 ldr r3, [r5, #0xc] */
/* @0x102a2c str r2, [r4, #0x8] */
/* @0x102a30 bic r3, r3, #-16777216 */
/* @0x102a34 cmp r3, #14 */
/* @0x102a38 addls pc, pc, r3, lsl #2 */
/* @0x102a3c b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a40 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102a44 b 0x102b00 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x102a48 b 0x102b18 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x102a4c b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102a50 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a54 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a58 b 0x102adc <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x170> */
/* @0x102a5c b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102a60 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a64 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a68 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102a6c b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a70 b 0x102a98 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x102a74 b 0x102a9c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x102a78 b 0x102a90 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102a7c ldr r0, [pc, #0x1a4] */
/* @0x102a80 mov r1, #0 */
/* @0x102a84 pop {r3, r4, r5, r6, r7, lr} */
/* @0x102a88 add r0, pc, r0 */
/* @0x102a8c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x102a90 ldr r3, [r5] */
/* @0x102a94 str r3, [r4] */
/* @0x102a98 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102a9c ldm r5, {r2, r3} */
/* @0x102aa0 stm r4, {r2, r3} */
/* @0x102aa4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102aa8 ldr r6, [r4] */
/* @0x102aac cmp r6, #0 */
/* @0x102ab0 beq 0x102ad0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x102ab4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102ab8 ldr r7, [r6, #0x4] */
/* @0x102abc sub r7, r7, #1 */
/* @0x102ac0 str r7, [r6, #0x4] */
/* @0x102ac4 cmp r7, #0 */
/* @0x102ac8 beq 0x102b44 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x102acc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102ad0 mov r3, #0 */
/* @0x102ad4 str r3, [r4] */
/* @0x102ad8 b 0x102a14 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x102adc ldr r3, [r5] */
/* @0x102ae0 str r3, [r4] */
/* @0x102ae4 ldr r3, [r5] */
/* @0x102ae8 cmp r3, #0 */
/* @0x102aec popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102af0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x102af4 ldr r1, [r5] */
/* @0x102af8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x102afc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x102b00 ldr r3, [r5] */
/* @0x102b04 cmp r3, #0 */
/* @0x102b08 ldrne r2, [r3, #0x4] */
/* @0x102b0c addne r2, r2, #1 */
/* @0x102b10 strne r2, [r3, #0x4] */
/* @0x102b14 b 0x102a94 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x102b18 ldr r3, [r5] */
/* @0x102b1c cmp r3, #0 */
/* @0x102b20 str r3, [r4] */
/* @0x102b24 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102b28 ldr r1, [r3, #0x8] */
/* @0x102b2c ldr r2, [r3] */
/* @0x102b30 cmp r1, #0 */
/* @0x102b34 streq r4, [r3, #0x8] */
/* @0x102b38 add r2, r2, #1 */
/* @0x102b3c str r2, [r3] */
/* @0x102b40 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102b44 ldr r0, [r6] */
/* @0x102b48 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102b4c str r7, [r6] */
/* @0x102b50 str r7, [r6, #0x8] */
/* @0x102b54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102b58 ldr r7, [r6, #0x4] */
/* @0x102b5c sub r7, r7, #1 */
/* @0x102b60 str r7, [r6, #0x4] */
/* @0x102b64 cmp r7, #0 */
/* @0x102b68 beq 0x102b88 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x102b6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102b70 mov r0, r6 */
/* @0x102b74 bl 0x27d1d0 <_ZdlPv> */
/* @0x102b78 b 0x102acc <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x102b7c mov r0, r4 */
/* @0x102b80 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x102b84 b 0x102a04 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x98> */
/* @0x102b88 ldr r0, [r6] */
/* @0x102b8c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102b90 str r7, [r6] */
/* @0x102b94 str r7, [r6, #0x8] */
/* @0x102b98 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102b9c ldr r7, [r6, #0x4] */
/* @0x102ba0 sub r7, r7, #1 */
/* @0x102ba4 str r7, [r6, #0x4] */
/* @0x102ba8 cmp r7, #0 */
/* @0x102bac beq 0x102bc0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x102bb0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102bb4 mov r0, r6 */
/* @0x102bb8 bl 0x27d1d0 <_ZdlPv> */
/* @0x102bbc b 0x102b6c <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x102bc0 ldr r0, [r6] */
/* @0x102bc4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102bc8 str r7, [r6] */
/* @0x102bcc str r7, [r6, #0x8] */
/* @0x102bd0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102bd4 ldr r3, [r6, #0x4] */
/* @0x102bd8 sub r3, r3, #1 */
/* @0x102bdc str r3, [r6, #0x4] */
/* @0x102be0 cmp r3, #0 */
/* @0x102be4 beq 0x102bf8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x28c> */
/* @0x102be8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102bec mov r0, r6 */
/* @0x102bf0 bl 0x27d1d0 <_ZdlPv> */
/* @0x102bf4 b 0x102bb0 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x244> */
/* @0x102bf8 ldr r0, [r6] */
/* @0x102bfc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102c00 mov r3, #0 */
/* @0x102c04 mov r0, r6 */
/* @0x102c08 str r3, [r6] */
/* @0x102c0c str r3, [r6, #0x8] */
/* @0x102c10 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x102c14 mov r0, r6 */
/* @0x102c18 bl 0x27d1d0 <_ZdlPv> */
/* @0x102c1c b 0x102be8 <_Z24F_DsPriorityFindPriorityR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x102c20 eoreq r11, lr, r4, ror #9 */
/* @0x102c24 .word 0x002eb4d4 */
/* @0x102c28 eoreq r5, r3, r4, ror r1 */

/* ── FUNC 0x102c2c · F_DsPriorityFindMax(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x102c2c push {r3, r4, r5, r6, r7, lr} */
/* @0x102c30 mov r1, #0 */
/* @0x102c34 mov r4, r0 */
/* @0x102c38 ldr r0, [sp, #0x18] */
/* @0x102c3c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102c40 cmp r0, #0 */
/* @0x102c44 blt 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x102c48 ldr r3, [pc, #0x288] */
/* @0x102c4c ldr r3, [pc, r3] */
/* @0x102c50 ldr r3, [r3] */
/* @0x102c54 cmp r0, r3 */
/* @0x102c58 bge 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x102c5c ldr r3, [pc, #0x278] */
/* @0x102c60 ldr r3, [pc, r3] */
/* @0x102c64 ldr r3, [r3, #0x4] */
/* @0x102c68 ldr r0, [r3, r0, lsl #2] */
/* @0x102c6c cmp r0, #0 */
/* @0x102c70 beq 0x102d34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x102c74 bl 0x20407c <_ZN12CDS_Priority7FindMaxEv> */
/* @0x102c78 subs r5, r0, #0 */
/* @0x102c7c streq r5, [r4] */
/* @0x102c80 streq r5, [r4, #0x4] */
/* @0x102c84 moveq r3, #5 */
/* @0x102c88 streq r3, [r4, #0xc] */
/* @0x102c8c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102c90 ldr r2, [r4, #0xc] */
/* @0x102c94 bic r3, r2, #-16777216 */
/* @0x102c98 cmp r3, #1 */
/* @0x102c9c beq 0x102d60 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x102ca0 cmp r3, #2 */
/* @0x102ca4 bne 0x102ccc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x102ca8 sub r2, r2, #1 */
/* @0x102cac bic r2, r2, #-16777216 */
/* @0x102cb0 bic r2, r2, #3 */
/* @0x102cb4 cmp r2, #0 */
/* @0x102cb8 beq 0x102e34 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x102cbc mov r2, #0 */
/* @0x102cc0 mov r3, #5 */
/* @0x102cc4 str r2, [r4, #0x8] */
/* @0x102cc8 str r3, [r4, #0xc] */
/* @0x102ccc ldr r3, [r5, #0xc] */
/* @0x102cd0 mov r1, #0 */
/* @0x102cd4 ldr r2, [r5, #0x8] */
/* @0x102cd8 str r1, [r4] */
/* @0x102cdc str r3, [r4, #0xc] */
/* @0x102ce0 ldr r3, [r5, #0xc] */
/* @0x102ce4 str r2, [r4, #0x8] */
/* @0x102ce8 bic r3, r3, #-16777216 */
/* @0x102cec cmp r3, #14 */
/* @0x102cf0 addls pc, pc, r3, lsl #2 */
/* @0x102cf4 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102cf8 b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x102cfc b 0x102db8 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x102d00 b 0x102dd0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x102d04 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x102d08 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d0c b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d10 b 0x102d94 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x102d14 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x102d18 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d1c b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d20 b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x102d24 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d28 b 0x102d50 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x102d2c b 0x102d54 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x102d30 b 0x102d48 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x102d34 ldr r0, [pc, #0x1a4] */
/* @0x102d38 mov r1, #0 */
/* @0x102d3c pop {r3, r4, r5, r6, r7, lr} */
/* @0x102d40 add r0, pc, r0 */
/* @0x102d44 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x102d48 ldr r3, [r5] */
/* @0x102d4c str r3, [r4] */
/* @0x102d50 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102d54 ldm r5, {r2, r3} */
/* @0x102d58 stm r4, {r2, r3} */
/* @0x102d5c pop {r3, r4, r5, r6, r7, pc} */
/* @0x102d60 ldr r6, [r4] */
/* @0x102d64 cmp r6, #0 */
/* @0x102d68 beq 0x102d88 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x102d6c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102d70 ldr r7, [r6, #0x4] */
/* @0x102d74 sub r7, r7, #1 */
/* @0x102d78 str r7, [r6, #0x4] */
/* @0x102d7c cmp r7, #0 */
/* @0x102d80 beq 0x102dfc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x102d84 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102d88 mov r3, #0 */
/* @0x102d8c str r3, [r4] */
/* @0x102d90 b 0x102ccc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x102d94 ldr r3, [r5] */
/* @0x102d98 str r3, [r4] */
/* @0x102d9c ldr r3, [r5] */
/* @0x102da0 cmp r3, #0 */
/* @0x102da4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102da8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x102dac ldr r1, [r5] */
/* @0x102db0 pop {r3, r4, r5, r6, r7, lr} */
/* @0x102db4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x102db8 ldr r3, [r5] */
/* @0x102dbc cmp r3, #0 */
/* @0x102dc0 ldrne r2, [r3, #0x4] */
/* @0x102dc4 addne r2, r2, #1 */
/* @0x102dc8 strne r2, [r3, #0x4] */
/* @0x102dcc b 0x102d4c <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x102dd0 ldr r3, [r5] */
/* @0x102dd4 cmp r3, #0 */
/* @0x102dd8 str r3, [r4] */
/* @0x102ddc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x102de0 ldr r1, [r3, #0x8] */
/* @0x102de4 ldr r2, [r3] */
/* @0x102de8 cmp r1, #0 */
/* @0x102dec streq r4, [r3, #0x8] */
/* @0x102df0 add r2, r2, #1 */
/* @0x102df4 str r2, [r3] */
/* @0x102df8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x102dfc ldr r0, [r6] */
/* @0x102e00 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102e04 str r7, [r6] */
/* @0x102e08 str r7, [r6, #0x8] */
/* @0x102e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102e10 ldr r7, [r6, #0x4] */
/* @0x102e14 sub r7, r7, #1 */
/* @0x102e18 str r7, [r6, #0x4] */
/* @0x102e1c cmp r7, #0 */
/* @0x102e20 beq 0x102e40 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x102e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102e28 mov r0, r6 */
/* @0x102e2c bl 0x27d1d0 <_ZdlPv> */
/* @0x102e30 b 0x102d84 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x102e34 mov r0, r4 */
/* @0x102e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x102e3c b 0x102cbc <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x102e40 ldr r0, [r6] */
/* @0x102e44 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102e48 str r7, [r6] */
/* @0x102e4c str r7, [r6, #0x8] */
/* @0x102e50 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102e54 ldr r7, [r6, #0x4] */
/* @0x102e58 sub r7, r7, #1 */
/* @0x102e5c str r7, [r6, #0x4] */
/* @0x102e60 cmp r7, #0 */
/* @0x102e64 beq 0x102e78 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x102e68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102e6c mov r0, r6 */
/* @0x102e70 bl 0x27d1d0 <_ZdlPv> */
/* @0x102e74 b 0x102e24 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x102e78 ldr r0, [r6] */
/* @0x102e7c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102e80 str r7, [r6] */
/* @0x102e84 str r7, [r6, #0x8] */
/* @0x102e88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x102e8c ldr r3, [r6, #0x4] */
/* @0x102e90 sub r3, r3, #1 */
/* @0x102e94 str r3, [r6, #0x4] */
/* @0x102e98 cmp r3, #0 */
/* @0x102e9c beq 0x102eb0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x102ea0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x102ea4 mov r0, r6 */
/* @0x102ea8 bl 0x27d1d0 <_ZdlPv> */
/* @0x102eac b 0x102e68 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x102eb0 ldr r0, [r6] */
/* @0x102eb4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x102eb8 mov r3, #0 */
/* @0x102ebc mov r0, r6 */
/* @0x102ec0 str r3, [r6] */
/* @0x102ec4 str r3, [r6, #0x8] */
/* @0x102ec8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x102ecc mov r0, r6 */
/* @0x102ed0 bl 0x27d1d0 <_ZdlPv> */
/* @0x102ed4 b 0x102ea0 <_Z19F_DsPriorityFindMaxR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x102ed8 eoreq r11, lr, r8, lsr #4 */
/* @0x102edc eoreq r11, lr, r8, lsl r2 */
/* @0x102ee0 .word 0x00234ebc */

/* ── FUNC 0x102ee4 · F_DsGridSet_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=648 · insn=162 */
/* @0x102ee4 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x102ee8 mov r1, #0 */
/* @0x102eec ldr r4, [sp, #0x20] */
/* @0x102ef0 mov r0, r4 */
/* @0x102ef4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102ef8 mov r1, #1 */
/* @0x102efc mov r6, r0 */
/* @0x102f00 mov r0, r4 */
/* @0x102f04 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102f08 mov r1, #2 */
/* @0x102f0c mov r5, r0 */
/* @0x102f10 mov r0, r4 */
/* @0x102f14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x102f18 ldr r3, [pc, #0x248] */
/* @0x102f1c ldr r3, [pc, r3] */
/* @0x102f20 ldr r3, [r3, #0x4] */
/* @0x102f24 ldr r3, [r3, r6, lsl #2] */
/* @0x102f28 ldm r3, {r6, r7} */
/* @0x102f2c mla r7, r7, r0, r5 */
/* @0x102f30 add r5, r6, r7, lsl #4 */
/* @0x102f34 ldr r2, [r5, #0xc] */
/* @0x102f38 bic r3, r2, #-16777216 */
/* @0x102f3c cmp r3, #1 */
/* @0x102f40 beq 0x102ff8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x102f44 cmp r3, #2 */
/* @0x102f48 bne 0x102f70 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x102f4c sub r2, r2, #1 */
/* @0x102f50 bic r2, r2, #-16777216 */
/* @0x102f54 bic r2, r2, #3 */
/* @0x102f58 cmp r2, #0 */
/* @0x102f5c beq 0x1030cc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x102f60 mov r2, #0 */
/* @0x102f64 mov r3, #5 */
/* @0x102f68 str r2, [r5, #0x8] */
/* @0x102f6c str r3, [r5, #0xc] */
/* @0x102f70 ldr r3, [r4, #0x3c] */
/* @0x102f74 mov r1, #0 */
/* @0x102f78 ldr r2, [r4, #0x38] */
/* @0x102f7c str r1, [r6, r7, lsl #4] */
/* @0x102f80 str r3, [r5, #0xc] */
/* @0x102f84 ldr r3, [r4, #0x3c] */
/* @0x102f88 str r2, [r5, #0x8] */
/* @0x102f8c bic r3, r3, #-16777216 */
/* @0x102f90 cmp r3, #14 */
/* @0x102f94 addls pc, pc, r3, lsl #2 */
/* @0x102f98 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102f9c b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x102fa0 b 0x103050 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x102fa4 b 0x103068 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x102fa8 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x102fac b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fb0 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fb4 b 0x10302c <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x102fb8 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x102fbc b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fc0 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fc4 b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x102fc8 b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fcc b 0x102fe0 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x102fd0 b 0x102fe4 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x102fd4 b 0x102fd8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x102fd8 ldr r3, [r4, #0x30] */
/* @0x102fdc str r3, [r6, r7, lsl #4] */
/* @0x102fe0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x102fe4 ldr r2, [r4, #0x30] */
/* @0x102fe8 ldr r3, [r4, #0x34] */
/* @0x102fec str r2, [r6, r7, lsl #4] */
/* @0x102ff0 str r3, [r5, #0x4] */
/* @0x102ff4 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x102ff8 ldr r8, [r6, r7, lsl #4] */
/* @0x102ffc cmp r8, #0 */
/* @0x103000 beq 0x103020 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x103004 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103008 ldr r9, [r8, #0x4] */
/* @0x10300c sub r9, r9, #1 */
/* @0x103010 str r9, [r8, #0x4] */
/* @0x103014 cmp r9, #0 */
/* @0x103018 beq 0x103094 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x10301c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103020 mov r3, #0 */
/* @0x103024 str r3, [r6, r7, lsl #4] */
/* @0x103028 b 0x102f70 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10302c ldr r3, [r4, #0x30] */
/* @0x103030 str r3, [r6, r7, lsl #4] */
/* @0x103034 ldr r3, [r4, #0x30] */
/* @0x103038 cmp r3, #0 */
/* @0x10303c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x103040 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x103044 ldr r1, [r4, #0x30] */
/* @0x103048 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x10304c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103050 ldr r3, [r4, #0x30] */
/* @0x103054 cmp r3, #0 */
/* @0x103058 ldrne r2, [r3, #0x4] */
/* @0x10305c addne r2, r2, #1 */
/* @0x103060 strne r2, [r3, #0x4] */
/* @0x103064 b 0x102fdc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x103068 ldr r3, [r4, #0x30] */
/* @0x10306c cmp r3, #0 */
/* @0x103070 str r3, [r6, r7, lsl #4] */
/* @0x103074 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x103078 ldr r1, [r3, #0x8] */
/* @0x10307c ldr r2, [r3] */
/* @0x103080 cmp r1, #0 */
/* @0x103084 streq r5, [r3, #0x8] */
/* @0x103088 add r2, r2, #1 */
/* @0x10308c str r2, [r3] */
/* @0x103090 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x103094 ldr r0, [r8] */
/* @0x103098 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10309c str r9, [r8] */
/* @0x1030a0 str r9, [r8, #0x8] */
/* @0x1030a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1030a8 ldr r9, [r8, #0x4] */
/* @0x1030ac sub r9, r9, #1 */
/* @0x1030b0 str r9, [r8, #0x4] */
/* @0x1030b4 cmp r9, #0 */
/* @0x1030b8 beq 0x1030d8 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x1030bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1030c0 mov r0, r8 */
/* @0x1030c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1030c8 b 0x10301c <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1030cc mov r0, r5 */
/* @0x1030d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1030d4 b 0x102f60 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x7c> */
/* @0x1030d8 ldr r0, [r8] */
/* @0x1030dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1030e0 str r9, [r8] */
/* @0x1030e4 str r9, [r8, #0x8] */
/* @0x1030e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1030ec ldr r9, [r8, #0x4] */
/* @0x1030f0 sub r9, r9, #1 */
/* @0x1030f4 str r9, [r8, #0x4] */
/* @0x1030f8 cmp r9, #0 */
/* @0x1030fc beq 0x103110 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x103100 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103104 mov r0, r8 */
/* @0x103108 bl 0x27d1d0 <_ZdlPv> */
/* @0x10310c b 0x1030bc <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x103110 ldr r0, [r8] */
/* @0x103114 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103118 str r9, [r8] */
/* @0x10311c str r9, [r8, #0x8] */
/* @0x103120 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103124 ldr r9, [r8, #0x4] */
/* @0x103128 sub r9, r9, #1 */
/* @0x10312c str r9, [r8, #0x4] */
/* @0x103130 cmp r9, #0 */
/* @0x103134 bne 0x103158 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x103138 ldr r0, [r8] */
/* @0x10313c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103140 mov r0, r8 */
/* @0x103144 str r9, [r8] */
/* @0x103148 str r9, [r8, #0x8] */
/* @0x10314c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x103150 mov r0, r8 */
/* @0x103154 bl 0x27d1d0 <_ZdlPv> */
/* @0x103158 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10315c mov r0, r8 */
/* @0x103160 bl 0x27d1d0 <_ZdlPv> */
/* @0x103164 b 0x103100 <_Z19F_DsGridSet_releaseR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x103168 eoreq r10, lr, r12, ror #30 */

/* ── FUNC 0x10316c · F_DsGridSet_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=728 · insn=182 */
/* @0x10316c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x103170 sub sp, sp, #20 */
/* @0x103174 mov r1, #0 */
/* @0x103178 ldr r4, [sp, #0x30] */
/* @0x10317c mov r0, r4 */
/* @0x103180 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103184 mov r1, #1 */
/* @0x103188 mov r5, r0 */
/* @0x10318c mov r0, r4 */
/* @0x103190 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103194 mov r1, #2 */
/* @0x103198 mov r6, r0 */
/* @0x10319c mov r0, r4 */
/* @0x1031a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1031a4 cmp r5, #0 */
/* @0x1031a8 mov r12, r0 */
/* @0x1031ac blt 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1031b0 ldr r2, [pc, #0x278] */
/* @0x1031b4 ldr r2, [pc, r2] */
/* @0x1031b8 ldr r3, [r2] */
/* @0x1031bc cmp r5, r3 */
/* @0x1031c0 bge 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1031c4 ldr r3, [pc, #0x268] */
/* @0x1031c8 ldr r3, [pc, r3] */
/* @0x1031cc ldr r3, [r3, #0x4] */
/* @0x1031d0 ldr r3, [r3, r5, lsl #2] */
/* @0x1031d4 cmp r3, #0 */
/* @0x1031d8 beq 0x1032b4 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1031dc cmp r6, #0 */
/* @0x1031e0 ldr r7, [r3, #0x4] */
/* @0x1031e4 blt 0x1032cc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1031e8 cmp r6, r7 */
/* @0x1031ec bge 0x1032cc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x1031f0 cmp r0, #0 */
/* @0x1031f4 ldr r8, [r3, #0x8] */
/* @0x1031f8 blt 0x1032d0 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x1031fc cmp r0, r8 */
/* @0x103200 bge 0x1032d0 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x103204 mla r6, r7, r0, r6 */
/* @0x103208 ldr r8, [r3] */
/* @0x10320c add r5, r8, r6, lsl #4 */
/* @0x103210 ldr r2, [r5, #0xc] */
/* @0x103214 bic r3, r2, #-16777216 */
/* @0x103218 cmp r3, #1 */
/* @0x10321c beq 0x103394 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x103220 cmp r3, #2 */
/* @0x103224 bne 0x10324c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x103228 sub r3, r2, #1 */
/* @0x10322c bic r3, r3, #-16777216 */
/* @0x103230 bic r3, r3, #3 */
/* @0x103234 cmp r3, #0 */
/* @0x103238 beq 0x103424 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x10323c mov r2, #0 */
/* @0x103240 mov r3, #5 */
/* @0x103244 str r2, [r5, #0x8] */
/* @0x103248 str r3, [r5, #0xc] */
/* @0x10324c ldr r3, [r4, #0x3c] */
/* @0x103250 mov r1, #0 */
/* @0x103254 ldr r2, [r4, #0x38] */
/* @0x103258 str r1, [r8, r6, lsl #4] */
/* @0x10325c str r3, [r5, #0xc] */
/* @0x103260 ldr r3, [r4, #0x3c] */
/* @0x103264 str r2, [r5, #0x8] */
/* @0x103268 bic r3, r3, #-16777216 */
/* @0x10326c cmp r3, #14 */
/* @0x103270 addls pc, pc, r3, lsl #2 */
/* @0x103274 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103278 b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x10327c b 0x103354 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x103280 b 0x103328 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x103284 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x103288 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x10328c b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103290 b 0x10336c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x103294 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x103298 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x10329c b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1032a0 b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x1032a4 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1032a8 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x1032ac b 0x103314 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x1032b0 b 0x103308 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x1032b4 ldr r0, [pc, #0x17c] */
/* @0x1032b8 mov r1, #0 */
/* @0x1032bc add r0, pc, r0 */
/* @0x1032c0 add sp, sp, #20 */
/* @0x1032c4 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1032c8 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1032cc ldr r8, [r3, #0x8] */
/* @0x1032d0 ldr r0, [pc, #0x164] */
/* @0x1032d4 mov r2, r5 */
/* @0x1032d8 ldr r1, [pc, #0x160] */
/* @0x1032dc mov r3, r6 */
/* @0x1032e0 ldr r0, [pc, r0] */
/* @0x1032e4 add r1, pc, r1 */
/* @0x1032e8 ldr r0, [r0] */
/* @0x1032ec ldr lr, [r0] */
/* @0x1032f0 str r12, [sp] */
/* @0x1032f4 stmib sp, {r7, r8} */
/* @0x1032f8 ldr r12, [lr, #0xc] */
/* @0x1032fc blx r12 */
/* @0x103300 add sp, sp, #20 */
/* @0x103304 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x103308 ldr r3, [r4, #0x30] */
/* @0x10330c str r3, [r8, r6, lsl #4] */
/* @0x103310 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103314 ldr r2, [r4, #0x30] */
/* @0x103318 ldr r3, [r4, #0x34] */
/* @0x10331c str r2, [r8, r6, lsl #4] */
/* @0x103320 str r3, [r5, #0x4] */
/* @0x103324 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103328 ldr r3, [r4, #0x30] */
/* @0x10332c cmp r3, #0 */
/* @0x103330 str r3, [r8, r6, lsl #4] */
/* @0x103334 beq 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103338 ldr r1, [r3, #0x8] */
/* @0x10333c ldr r2, [r3] */
/* @0x103340 cmp r1, #0 */
/* @0x103344 streq r5, [r3, #0x8] */
/* @0x103348 add r2, r2, #1 */
/* @0x10334c str r2, [r3] */
/* @0x103350 b 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103354 ldr r3, [r4, #0x30] */
/* @0x103358 cmp r3, #0 */
/* @0x10335c ldrne r2, [r3, #0x4] */
/* @0x103360 addne r2, r2, #1 */
/* @0x103364 strne r2, [r3, #0x4] */
/* @0x103368 b 0x10330c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x10336c ldr r3, [r4, #0x30] */
/* @0x103370 str r3, [r8, r6, lsl #4] */
/* @0x103374 ldr r3, [r4, #0x30] */
/* @0x103378 cmp r3, #0 */
/* @0x10337c beq 0x103300 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103380 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x103384 ldr r1, [r4, #0x30] */
/* @0x103388 add sp, sp, #20 */
/* @0x10338c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x103390 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103394 ldr r7, [r8, r6, lsl #4] */
/* @0x103398 cmp r7, #0 */
/* @0x10339c beq 0x1033bc <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x1033a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1033a4 ldr r3, [r7, #0x4] */
/* @0x1033a8 sub r3, r3, #1 */
/* @0x1033ac str r3, [r7, #0x4] */
/* @0x1033b0 cmp r3, #0 */
/* @0x1033b4 beq 0x1033c8 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x25c> */
/* @0x1033b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1033bc mov r3, #0 */
/* @0x1033c0 str r3, [r8, r6, lsl #4] */
/* @0x1033c4 b 0x10324c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xe0> */
/* @0x1033c8 ldr r0, [r7] */
/* @0x1033cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1033d0 mov r3, #0 */
/* @0x1033d4 str r3, [r7] */
/* @0x1033d8 str r3, [r7, #0x8] */
/* @0x1033dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1033e0 ldr r9, [r7, #0x4] */
/* @0x1033e4 sub r9, r9, #1 */
/* @0x1033e8 str r9, [r7, #0x4] */
/* @0x1033ec cmp r9, #0 */
/* @0x1033f0 bne 0x103414 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x1033f4 ldr r0, [r7] */
/* @0x1033f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1033fc mov r0, r7 */
/* @0x103400 str r9, [r7] */
/* @0x103404 str r9, [r7, #0x8] */
/* @0x103408 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x10340c mov r0, r7 */
/* @0x103410 bl 0x27d1d0 <_ZdlPv> */
/* @0x103414 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103418 mov r0, r7 */
/* @0x10341c bl 0x27d1d0 <_ZdlPv> */
/* @0x103420 b 0x1033b8 <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x103424 mov r0, r5 */
/* @0x103428 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10342c b 0x10323c <_Z17F_DsGridSet_debugR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x103430 .word 0x002eacd0 */
/* @0x103434 eoreq r10, lr, r0, asr #25 */
/* @0x103438 eoreq r4, r3, r0, asr #18 */
/* @0x10343c eoreq r10, lr, r0, ror #12 */
/* @0x103440 eoreq r5, r3, r8, lsr #7 */

/* ── FUNC 0x103444 · F_DsGridSetPre(RValue&, CInstance*, CInstance*, int, RValue*) · size=1176 · insn=294 */
/* @0x103444 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x103448 sub sp, sp, #16 */
/* @0x10344c mov r1, #0 */
/* @0x103450 mov r7, r0 */
/* @0x103454 ldr r4, [sp, #0x30] */
/* @0x103458 mov r0, r4 */
/* @0x10345c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103460 mov r1, #1 */
/* @0x103464 mov r5, r0 */
/* @0x103468 mov r0, r4 */
/* @0x10346c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103470 mov r1, #2 */
/* @0x103474 mov r6, r0 */
/* @0x103478 mov r0, r4 */
/* @0x10347c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103480 cmp r5, #0 */
/* @0x103484 mov r12, r0 */
/* @0x103488 blt 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x10348c ldr r2, [pc, #0x434] */
/* @0x103490 ldr r2, [pc, r2] */
/* @0x103494 ldr r3, [r2] */
/* @0x103498 cmp r5, r3 */
/* @0x10349c bge 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x1034a0 ldr r3, [pc, #0x424] */
/* @0x1034a4 ldr r3, [pc, r3] */
/* @0x1034a8 ldr r3, [r3, #0x4] */
/* @0x1034ac ldr r3, [r3, r5, lsl #2] */
/* @0x1034b0 cmp r3, #0 */
/* @0x1034b4 beq 0x103590 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x1034b8 cmp r6, #0 */
/* @0x1034bc ldr r8, [r3, #0x4] */
/* @0x1034c0 blt 0x1035a8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x1034c4 cmp r6, r8 */
/* @0x1034c8 bge 0x1035a8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x1034cc cmp r0, #0 */
/* @0x1034d0 ldr r9, [r3, #0x8] */
/* @0x1034d4 blt 0x1035ac <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1034d8 cmp r0, r9 */
/* @0x1034dc bge 0x1035ac <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1034e0 mla r6, r8, r0, r6 */
/* @0x1034e4 ldr r9, [r3] */
/* @0x1034e8 add r5, r9, r6, lsl #4 */
/* @0x1034ec ldr r2, [r5, #0xc] */
/* @0x1034f0 bic r3, r2, #-16777216 */
/* @0x1034f4 cmp r3, #1 */
/* @0x1034f8 beq 0x1037c8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x384> */
/* @0x1034fc cmp r3, #2 */
/* @0x103500 bne 0x103528 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x103504 sub r3, r2, #1 */
/* @0x103508 bic r3, r3, #-16777216 */
/* @0x10350c bic r3, r3, #3 */
/* @0x103510 cmp r3, #0 */
/* @0x103514 beq 0x1038b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x46c> */
/* @0x103518 mov r2, #0 */
/* @0x10351c mov r3, #5 */
/* @0x103520 str r2, [r5, #0x8] */
/* @0x103524 str r3, [r5, #0xc] */
/* @0x103528 ldr r3, [r4, #0x3c] */
/* @0x10352c mov r1, #0 */
/* @0x103530 ldr r2, [r4, #0x38] */
/* @0x103534 str r1, [r9, r6, lsl #4] */
/* @0x103538 str r3, [r5, #0xc] */
/* @0x10353c ldr r3, [r4, #0x3c] */
/* @0x103540 str r2, [r5, #0x8] */
/* @0x103544 bic r3, r3, #-16777216 */
/* @0x103548 cmp r3, #14 */
/* @0x10354c addls pc, pc, r3, lsl #2 */
/* @0x103550 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103554 b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x103558 b 0x1036c0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x27c> */
/* @0x10355c b 0x103768 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x324> */
/* @0x103560 b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x103564 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103568 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x10356c b 0x103744 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x103570 b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x103574 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103578 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x10357c b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x103580 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103584 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103588 b 0x10369c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x10358c b 0x1035e4 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x103590 ldr r0, [pc, #0x338] */
/* @0x103594 mov r1, #0 */
/* @0x103598 add r0, pc, r0 */
/* @0x10359c add sp, sp, #16 */
/* @0x1035a0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1035a4 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1035a8 ldr r9, [r3, #0x8] */
/* @0x1035ac ldr r0, [pc, #0x320] */
/* @0x1035b0 mov r2, r5 */
/* @0x1035b4 ldr r1, [pc, #0x31c] */
/* @0x1035b8 mov r3, r6 */
/* @0x1035bc ldr r0, [pc, r0] */
/* @0x1035c0 add r1, pc, r1 */
/* @0x1035c4 ldr r0, [r0] */
/* @0x1035c8 ldr lr, [r0] */
/* @0x1035cc str r12, [sp] */
/* @0x1035d0 stmib sp, {r8, r9} */
/* @0x1035d4 ldr r12, [lr, #0xc] */
/* @0x1035d8 blx r12 */
/* @0x1035dc add sp, sp, #16 */
/* @0x1035e0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1035e4 ldr r3, [r4, #0x30] */
/* @0x1035e8 str r3, [r9, r6, lsl #4] */
/* @0x1035ec ldr r2, [r7, #0xc] */
/* @0x1035f0 bic r3, r2, #-16777216 */
/* @0x1035f4 cmp r3, #1 */
/* @0x1035f8 beq 0x103794 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x350> */
/* @0x1035fc cmp r3, #2 */
/* @0x103600 bne 0x103628 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x103604 sub r3, r2, #1 */
/* @0x103608 bic r3, r3, #-16777216 */
/* @0x10360c bic r3, r3, #3 */
/* @0x103610 cmp r3, #0 */
/* @0x103614 beq 0x1038bc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x478> */
/* @0x103618 mov r2, #0 */
/* @0x10361c mov r3, #5 */
/* @0x103620 str r2, [r7, #0x8] */
/* @0x103624 str r3, [r7, #0xc] */
/* @0x103628 ldr r3, [r4, #0x3c] */
/* @0x10362c mov r1, #0 */
/* @0x103630 ldr r2, [r4, #0x38] */
/* @0x103634 str r1, [r7] */
/* @0x103638 str r3, [r7, #0xc] */
/* @0x10363c ldr r3, [r4, #0x3c] */
/* @0x103640 str r2, [r7, #0x8] */
/* @0x103644 bic r3, r3, #-16777216 */
/* @0x103648 cmp r3, #14 */
/* @0x10364c addls pc, pc, r3, lsl #2 */
/* @0x103650 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103654 b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x103658 b 0x10372c <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x2e8> */
/* @0x10365c b 0x103700 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x103660 b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x103664 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103668 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10366c b 0x1036d8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x103670 b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x103674 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103678 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10367c b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x103680 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103684 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103688 b 0x1036b0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x26c> */
/* @0x10368c b 0x103690 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x103690 ldr r3, [r4, #0x30] */
/* @0x103694 str r3, [r7] */
/* @0x103698 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10369c ldr r2, [r4, #0x30] */
/* @0x1036a0 ldr r3, [r4, #0x34] */
/* @0x1036a4 str r2, [r9, r6, lsl #4] */
/* @0x1036a8 str r3, [r5, #0x4] */
/* @0x1036ac b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x1036b0 ldr r2, [r4, #0x30] */
/* @0x1036b4 ldr r3, [r4, #0x34] */
/* @0x1036b8 stm r7, {r2, r3} */
/* @0x1036bc b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x1036c0 ldr r3, [r4, #0x30] */
/* @0x1036c4 cmp r3, #0 */
/* @0x1036c8 ldrne r2, [r3, #0x4] */
/* @0x1036cc addne r2, r2, #1 */
/* @0x1036d0 strne r2, [r3, #0x4] */
/* @0x1036d4 b 0x1035e8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x1036d8 ldr r3, [r4, #0x30] */
/* @0x1036dc str r3, [r7] */
/* @0x1036e0 ldr r3, [r4, #0x30] */
/* @0x1036e4 cmp r3, #0 */
/* @0x1036e8 beq 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x1036ec bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1036f0 ldr r1, [r4, #0x30] */
/* @0x1036f4 add sp, sp, #16 */
/* @0x1036f8 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1036fc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103700 ldr r3, [r4, #0x30] */
/* @0x103704 cmp r3, #0 */
/* @0x103708 str r3, [r7] */
/* @0x10370c beq 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103710 ldr r1, [r3, #0x8] */
/* @0x103714 ldr r2, [r3] */
/* @0x103718 cmp r1, #0 */
/* @0x10371c streq r7, [r3, #0x8] */
/* @0x103720 add r2, r2, #1 */
/* @0x103724 str r2, [r3] */
/* @0x103728 b 0x1035dc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x10372c ldr r3, [r4, #0x30] */
/* @0x103730 cmp r3, #0 */
/* @0x103734 ldrne r2, [r3, #0x4] */
/* @0x103738 addne r2, r2, #1 */
/* @0x10373c strne r2, [r3, #0x4] */
/* @0x103740 b 0x103694 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x103744 ldr r3, [r4, #0x30] */
/* @0x103748 str r3, [r9, r6, lsl #4] */
/* @0x10374c ldr r3, [r4, #0x30] */
/* @0x103750 cmp r3, #0 */
/* @0x103754 beq 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103758 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x10375c ldr r1, [r4, #0x30] */
/* @0x103760 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103764 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103768 ldr r3, [r4, #0x30] */
/* @0x10376c cmp r3, #0 */
/* @0x103770 str r3, [r9, r6, lsl #4] */
/* @0x103774 beq 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103778 ldr r1, [r3, #0x8] */
/* @0x10377c ldr r2, [r3] */
/* @0x103780 cmp r1, #0 */
/* @0x103784 streq r5, [r3, #0x8] */
/* @0x103788 add r2, r2, #1 */
/* @0x10378c str r2, [r3] */
/* @0x103790 b 0x1035ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x103794 ldr r5, [r7] */
/* @0x103798 cmp r5, #0 */
/* @0x10379c beq 0x1037bc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x378> */
/* @0x1037a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1037a4 ldr r6, [r5, #0x4] */
/* @0x1037a8 sub r6, r6, #1 */
/* @0x1037ac str r6, [r5, #0x4] */
/* @0x1037b0 cmp r6, #0 */
/* @0x1037b4 beq 0x1037fc <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3b8> */
/* @0x1037b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1037bc mov r3, #0 */
/* @0x1037c0 str r3, [r7] */
/* @0x1037c4 b 0x103628 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1e4> */
/* @0x1037c8 ldr r8, [r9, r6, lsl #4] */
/* @0x1037cc cmp r8, #0 */
/* @0x1037d0 beq 0x1037f0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3ac> */
/* @0x1037d4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1037d8 ldr r3, [r8, #0x4] */
/* @0x1037dc sub r3, r3, #1 */
/* @0x1037e0 str r3, [r8, #0x4] */
/* @0x1037e4 cmp r3, #0 */
/* @0x1037e8 beq 0x103854 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x410> */
/* @0x1037ec bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1037f0 mov r3, #0 */
/* @0x1037f4 str r3, [r9, r6, lsl #4] */
/* @0x1037f8 b 0x103528 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x1037fc ldr r0, [r5] */
/* @0x103800 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103804 str r6, [r5] */
/* @0x103808 str r6, [r5, #0x8] */
/* @0x10380c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103810 ldr r6, [r5, #0x4] */
/* @0x103814 sub r6, r6, #1 */
/* @0x103818 str r6, [r5, #0x4] */
/* @0x10381c cmp r6, #0 */
/* @0x103820 bne 0x103844 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x400> */
/* @0x103824 ldr r0, [r5] */
/* @0x103828 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10382c mov r0, r5 */
/* @0x103830 str r6, [r5] */
/* @0x103834 str r6, [r5, #0x8] */
/* @0x103838 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x10383c mov r0, r5 */
/* @0x103840 bl 0x27d1d0 <_ZdlPv> */
/* @0x103844 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103848 mov r0, r5 */
/* @0x10384c bl 0x27d1d0 <_ZdlPv> */
/* @0x103850 b 0x1037b8 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x103854 ldr r0, [r8] */
/* @0x103858 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10385c mov r3, #0 */
/* @0x103860 str r3, [r8] */
/* @0x103864 str r3, [r8, #0x8] */
/* @0x103868 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10386c ldr r10, [r8, #0x4] */
/* @0x103870 sub r10, r10, #1 */
/* @0x103874 str r10, [r8, #0x4] */
/* @0x103878 cmp r10, #0 */
/* @0x10387c bne 0x1038a0 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x45c> */
/* @0x103880 ldr r0, [r8] */
/* @0x103884 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103888 mov r0, r8 */
/* @0x10388c str r10, [r8] */
/* @0x103890 str r10, [r8, #0x8] */
/* @0x103894 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x103898 mov r0, r8 */
/* @0x10389c bl 0x27d1d0 <_ZdlPv> */
/* @0x1038a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1038a4 mov r0, r8 */
/* @0x1038a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1038ac b 0x1037ec <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x3a8> */
/* @0x1038b0 mov r0, r5 */
/* @0x1038b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1038b8 b 0x103518 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1038bc mov r0, r7 */
/* @0x1038c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1038c4 b 0x103618 <_Z14F_DsGridSetPreR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x1038c8 .word 0x002ea9f4 */
/* @0x1038cc eoreq r10, lr, r4, ror #19 */
/* @0x1038d0 eoreq r4, r3, r4, ror #12 */
/* @0x1038d4 eoreq r10, lr, r4, lsl #7 */
/* @0x1038d8 eoreq r5, r3, r12, asr #1 */

/* ── FUNC 0x1038dc · F_DsGridSetPost(RValue&, CInstance*, CInstance*, int, RValue*) · size=1204 · insn=301 */
/* @0x1038dc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1038e0 sub sp, sp, #16 */
/* @0x1038e4 mov r1, #0 */
/* @0x1038e8 mov r7, r0 */
/* @0x1038ec ldr r4, [sp, #0x30] */
/* @0x1038f0 mov r0, r4 */
/* @0x1038f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1038f8 mov r1, #1 */
/* @0x1038fc mov r5, r0 */
/* @0x103900 mov r0, r4 */
/* @0x103904 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103908 mov r1, #2 */
/* @0x10390c mov r6, r0 */
/* @0x103910 mov r0, r4 */
/* @0x103914 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103918 cmp r5, #0 */
/* @0x10391c mov r12, r0 */
/* @0x103920 blt 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x103924 ldr r2, [pc, #0x450] */
/* @0x103928 ldr r2, [pc, r2] */
/* @0x10392c ldr r3, [r2] */
/* @0x103930 cmp r5, r3 */
/* @0x103934 bge 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x103938 ldr r3, [pc, #0x440] */
/* @0x10393c ldr r3, [pc, r3] */
/* @0x103940 ldr r3, [r3, #0x4] */
/* @0x103944 ldr r3, [r3, r5, lsl #2] */
/* @0x103948 cmp r3, #0 */
/* @0x10394c beq 0x103a28 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x103950 cmp r6, #0 */
/* @0x103954 ldr r8, [r3, #0x4] */
/* @0x103958 blt 0x103a40 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x10395c cmp r6, r8 */
/* @0x103960 bge 0x103a40 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x103964 cmp r0, #0 */
/* @0x103968 ldr r9, [r3, #0x8] */
/* @0x10396c blt 0x103a44 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x103970 cmp r0, r9 */
/* @0x103974 bge 0x103a44 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x103978 mla r6, r8, r0, r6 */
/* @0x10397c ldr r2, [r7, #0xc] */
/* @0x103980 ldr r9, [r3] */
/* @0x103984 bic r3, r2, #-16777216 */
/* @0x103988 cmp r3, #1 */
/* @0x10398c add r5, r9, r6, lsl #4 */
/* @0x103990 beq 0x103c7c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3a0> */
/* @0x103994 cmp r3, #2 */
/* @0x103998 bne 0x1039c0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x10399c sub r3, r2, #1 */
/* @0x1039a0 bic r3, r3, #-16777216 */
/* @0x1039a4 bic r3, r3, #3 */
/* @0x1039a8 cmp r3, #0 */
/* @0x1039ac beq 0x103d64 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x488> */
/* @0x1039b0 mov r2, #0 */
/* @0x1039b4 mov r3, #5 */
/* @0x1039b8 str r2, [r7, #0x8] */
/* @0x1039bc str r3, [r7, #0xc] */
/* @0x1039c0 ldr r2, [r5, #0xc] */
/* @0x1039c4 mov r1, #0 */
/* @0x1039c8 ldr r3, [r5, #0x8] */
/* @0x1039cc str r1, [r7] */
/* @0x1039d0 str r2, [r7, #0xc] */
/* @0x1039d4 ldr r2, [r5, #0xc] */
/* @0x1039d8 str r3, [r7, #0x8] */
/* @0x1039dc bic r3, r2, #-16777216 */
/* @0x1039e0 cmp r3, #14 */
/* @0x1039e4 addls pc, pc, r3, lsl #2 */
/* @0x1039e8 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x1039ec b 0x103c6c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x390> */
/* @0x1039f0 b 0x103c48 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x36c> */
/* @0x1039f4 b 0x103c1c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x340> */
/* @0x1039f8 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x1039fc b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a00 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a04 b 0x103a7c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x103a08 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x103a0c b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a10 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a14 b 0x103ba0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2c4> */
/* @0x103a18 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a1c b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103a20 b 0x103c6c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x390> */
/* @0x103a24 b 0x103ae0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x103a28 ldr r0, [pc, #0x354] */
/* @0x103a2c mov r1, #0 */
/* @0x103a30 add r0, pc, r0 */
/* @0x103a34 add sp, sp, #16 */
/* @0x103a38 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x103a3c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x103a40 ldr r9, [r3, #0x8] */
/* @0x103a44 ldr r0, [pc, #0x33c] */
/* @0x103a48 mov r2, r5 */
/* @0x103a4c ldr r1, [pc, #0x338] */
/* @0x103a50 mov r3, r6 */
/* @0x103a54 ldr r0, [pc, r0] */
/* @0x103a58 add r1, pc, r1 */
/* @0x103a5c ldr r0, [r0] */
/* @0x103a60 ldr lr, [r0] */
/* @0x103a64 str r12, [sp] */
/* @0x103a68 stmib sp, {r8, r9} */
/* @0x103a6c ldr r12, [lr, #0xc] */
/* @0x103a70 blx r12 */
/* @0x103a74 add sp, sp, #16 */
/* @0x103a78 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x103a7c ldr r3, [r9, r6, lsl #4] */
/* @0x103a80 str r3, [r7] */
/* @0x103a84 ldr r3, [r9, r6, lsl #4] */
/* @0x103a88 cmp r3, #0 */
/* @0x103a8c beq 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x103a90 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x103a94 ldr r1, [r9, r6, lsl #4] */
/* @0x103a98 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103a9c ldr r2, [r5, #0xc] */
/* @0x103aa0 bic r3, r2, #-16777216 */
/* @0x103aa4 cmp r3, #1 */
/* @0x103aa8 bne 0x103b70 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x294> */
/* @0x103aac ldr r7, [r9, r6, lsl #4] */
/* @0x103ab0 cmp r7, #0 */
/* @0x103ab4 beq 0x103ad4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x103ab8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103abc ldr r8, [r7, #0x4] */
/* @0x103ac0 sub r8, r8, #1 */
/* @0x103ac4 str r8, [r7, #0x4] */
/* @0x103ac8 cmp r8, #0 */
/* @0x103acc beq 0x103cb0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3d4> */
/* @0x103ad0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103ad4 mov r3, #0 */
/* @0x103ad8 str r3, [r9, r6, lsl #4] */
/* @0x103adc b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x103ae0 ldr r3, [r9, r6, lsl #4] */
/* @0x103ae4 str r3, [r7] */
/* @0x103ae8 ldr r3, [r4, #0x3c] */
/* @0x103aec mov r1, #0 */
/* @0x103af0 ldr r2, [r4, #0x38] */
/* @0x103af4 str r1, [r9, r6, lsl #4] */
/* @0x103af8 str r3, [r5, #0xc] */
/* @0x103afc ldr r3, [r4, #0x3c] */
/* @0x103b00 str r2, [r5, #0x8] */
/* @0x103b04 bic r3, r3, #-16777216 */
/* @0x103b08 cmp r3, #14 */
/* @0x103b0c addls pc, pc, r3, lsl #2 */
/* @0x103b10 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b14 b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x103b18 b 0x103c04 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x328> */
/* @0x103b1c b 0x103bd8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x103b20 b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x103b24 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b28 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b2c b 0x103bb0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2d4> */
/* @0x103b30 b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x103b34 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b38 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b3c b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x103b40 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b44 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b48 b 0x103b5c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x280> */
/* @0x103b4c b 0x103b50 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x103b50 ldr r3, [r4, #0x30] */
/* @0x103b54 str r3, [r9, r6, lsl #4] */
/* @0x103b58 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b5c ldr r2, [r4, #0x30] */
/* @0x103b60 ldr r3, [r4, #0x34] */
/* @0x103b64 str r2, [r9, r6, lsl #4] */
/* @0x103b68 str r3, [r5, #0x4] */
/* @0x103b6c b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103b70 cmp r3, #2 */
/* @0x103b74 bne 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x103b78 sub r3, r2, #1 */
/* @0x103b7c bic r3, r3, #-16777216 */
/* @0x103b80 bic r3, r3, #3 */
/* @0x103b84 cmp r3, #0 */
/* @0x103b88 beq 0x103d70 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x494> */
/* @0x103b8c mov r2, #0 */
/* @0x103b90 mov r3, #5 */
/* @0x103b94 str r2, [r5, #0x8] */
/* @0x103b98 str r3, [r5, #0xc] */
/* @0x103b9c b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x103ba0 ldr r2, [r9, r6, lsl #4] */
/* @0x103ba4 ldr r3, [r5, #0x4] */
/* @0x103ba8 stm r7, {r2, r3} */
/* @0x103bac b 0x103ae8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x20c> */
/* @0x103bb0 ldr r3, [r4, #0x30] */
/* @0x103bb4 str r3, [r9, r6, lsl #4] */
/* @0x103bb8 ldr r3, [r4, #0x30] */
/* @0x103bbc cmp r3, #0 */
/* @0x103bc0 beq 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103bc4 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x103bc8 ldr r1, [r4, #0x30] */
/* @0x103bcc add sp, sp, #16 */
/* @0x103bd0 pop {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x103bd4 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103bd8 ldr r3, [r4, #0x30] */
/* @0x103bdc cmp r3, #0 */
/* @0x103be0 str r3, [r9, r6, lsl #4] */
/* @0x103be4 beq 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103be8 ldr r1, [r3, #0x8] */
/* @0x103bec ldr r2, [r3] */
/* @0x103bf0 cmp r1, #0 */
/* @0x103bf4 streq r5, [r3, #0x8] */
/* @0x103bf8 add r2, r2, #1 */
/* @0x103bfc str r2, [r3] */
/* @0x103c00 b 0x103a74 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x198> */
/* @0x103c04 ldr r3, [r4, #0x30] */
/* @0x103c08 cmp r3, #0 */
/* @0x103c0c ldrne r2, [r3, #0x4] */
/* @0x103c10 addne r2, r2, #1 */
/* @0x103c14 strne r2, [r3, #0x4] */
/* @0x103c18 b 0x103b54 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x103c1c ldr r3, [r9, r6, lsl #4] */
/* @0x103c20 cmp r3, #0 */
/* @0x103c24 str r3, [r7] */
/* @0x103c28 beq 0x103b78 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x103c2c ldr r0, [r3, #0x8] */
/* @0x103c30 ldr r1, [r3] */
/* @0x103c34 cmp r0, #0 */
/* @0x103c38 streq r7, [r3, #0x8] */
/* @0x103c3c add r1, r1, #1 */
/* @0x103c40 str r1, [r3] */
/* @0x103c44 b 0x103b78 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x103c48 ldr r1, [r9, r6, lsl #4] */
/* @0x103c4c cmp r1, #0 */
/* @0x103c50 ldrne r3, [r1, #0x4] */
/* @0x103c54 addne r3, r3, #1 */
/* @0x103c58 strne r3, [r1, #0x4] */
/* @0x103c5c ldrne r2, [r5, #0xc] */
/* @0x103c60 str r1, [r7] */
/* @0x103c64 bicne r3, r2, #-16777216 */
/* @0x103c68 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103c6c ldr r0, [r9, r6, lsl #4] */
/* @0x103c70 ldr r1, [r5, #0x4] */
/* @0x103c74 stm r7, {r0, r1} */
/* @0x103c78 b 0x103aa4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1c8> */
/* @0x103c7c ldr r8, [r7] */
/* @0x103c80 cmp r8, #0 */
/* @0x103c84 beq 0x103ca4 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3c8> */
/* @0x103c88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103c8c ldr r3, [r8, #0x4] */
/* @0x103c90 sub r3, r3, #1 */
/* @0x103c94 str r3, [r8, #0x4] */
/* @0x103c98 cmp r3, #0 */
/* @0x103c9c beq 0x103d08 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x42c> */
/* @0x103ca0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103ca4 mov r3, #0 */
/* @0x103ca8 str r3, [r7] */
/* @0x103cac b 0x1039c0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x103cb0 ldr r0, [r7] */
/* @0x103cb4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103cb8 str r8, [r7] */
/* @0x103cbc str r8, [r7, #0x8] */
/* @0x103cc0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103cc4 ldr r8, [r7, #0x4] */
/* @0x103cc8 sub r8, r8, #1 */
/* @0x103ccc str r8, [r7, #0x4] */
/* @0x103cd0 cmp r8, #0 */
/* @0x103cd4 bne 0x103cf8 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x41c> */
/* @0x103cd8 ldr r0, [r7] */
/* @0x103cdc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103ce0 mov r0, r7 */
/* @0x103ce4 str r8, [r7] */
/* @0x103ce8 str r8, [r7, #0x8] */
/* @0x103cec bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x103cf0 mov r0, r7 */
/* @0x103cf4 bl 0x27d1d0 <_ZdlPv> */
/* @0x103cf8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103cfc mov r0, r7 */
/* @0x103d00 bl 0x27d1d0 <_ZdlPv> */
/* @0x103d04 b 0x103ad0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x103d08 ldr r0, [r8] */
/* @0x103d0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103d10 mov r3, #0 */
/* @0x103d14 str r3, [r8] */
/* @0x103d18 str r3, [r8, #0x8] */
/* @0x103d1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103d20 ldr r10, [r8, #0x4] */
/* @0x103d24 sub r10, r10, #1 */
/* @0x103d28 str r10, [r8, #0x4] */
/* @0x103d2c cmp r10, #0 */
/* @0x103d30 bne 0x103d54 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x478> */
/* @0x103d34 ldr r0, [r8] */
/* @0x103d38 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x103d3c mov r0, r8 */
/* @0x103d40 str r10, [r8] */
/* @0x103d44 str r10, [r8, #0x8] */
/* @0x103d48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x103d4c mov r0, r8 */
/* @0x103d50 bl 0x27d1d0 <_ZdlPv> */
/* @0x103d54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103d58 mov r0, r8 */
/* @0x103d5c bl 0x27d1d0 <_ZdlPv> */
/* @0x103d60 b 0x103ca0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x3c4> */
/* @0x103d64 mov r0, r7 */
/* @0x103d68 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x103d6c b 0x1039b0 <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x103d70 mov r0, r5 */
/* @0x103d74 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x103d78 b 0x103b8c <_Z15F_DsGridSetPostR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x103d7c eoreq r10, lr, r12, asr r5 */
/* @0x103d80 eoreq r10, lr, r12, asr #10 */
/* @0x103d84 eoreq r4, r3, r12, asr #3 */
/* @0x103d88 eoreq r9, lr, r12, ror #29 */
/* @0x103d8c eoreq r4, r3, r4, lsr r12 */

/* ── FUNC 0x103d90 · F_DsGridGet_debug(RValue&, CInstance*, CInstance*, int, RValue*) · size=752 · insn=188 */
/* @0x103d90 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x103d94 sub sp, sp, #20 */
/* @0x103d98 mov r1, #0 */
/* @0x103d9c mov r6, r0 */
/* @0x103da0 ldr r4, [sp, #0x30] */
/* @0x103da4 mov r0, r4 */
/* @0x103da8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103dac mov r1, #1 */
/* @0x103db0 mov r5, r0 */
/* @0x103db4 mov r0, r4 */
/* @0x103db8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103dbc mov r1, #2 */
/* @0x103dc0 mov r7, r0 */
/* @0x103dc4 mov r0, r4 */
/* @0x103dc8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x103dcc cmp r5, #0 */
/* @0x103dd0 mov r12, r0 */
/* @0x103dd4 blt 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x103dd8 ldr r2, [pc, #0x28c] */
/* @0x103ddc ldr r2, [pc, r2] */
/* @0x103de0 ldr r3, [r2] */
/* @0x103de4 cmp r5, r3 */
/* @0x103de8 bge 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x103dec ldr r3, [pc, #0x27c] */
/* @0x103df0 ldr r3, [pc, r3] */
/* @0x103df4 ldr r3, [r3, #0x4] */
/* @0x103df8 ldr r3, [r3, r5, lsl #2] */
/* @0x103dfc cmp r3, #0 */
/* @0x103e00 beq 0x103f2c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x103e04 cmp r7, #0 */
/* @0x103e08 ldr r4, [r3, #0x4] */
/* @0x103e0c blt 0x103edc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x103e10 cmp r7, r4 */
/* @0x103e14 bge 0x103edc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x103e18 cmp r0, #0 */
/* @0x103e1c ldr r8, [r3, #0x8] */
/* @0x103e20 blt 0x103ee0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x103e24 cmp r0, r8 */
/* @0x103e28 bge 0x103ee0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x103e2c mla r7, r4, r0, r7 */
/* @0x103e30 ldr r2, [r6, #0xc] */
/* @0x103e34 ldr r8, [r3] */
/* @0x103e38 bic r3, r2, #-16777216 */
/* @0x103e3c cmp r3, #1 */
/* @0x103e40 add r5, r8, r7, lsl #4 */
/* @0x103e44 beq 0x103fcc <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x103e48 cmp r3, #2 */
/* @0x103e4c bne 0x103e74 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x103e50 sub r3, r2, #1 */
/* @0x103e54 bic r3, r3, #-16777216 */
/* @0x103e58 bic r3, r3, #3 */
/* @0x103e5c cmp r3, #0 */
/* @0x103e60 beq 0x10403c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x103e64 mov r2, #0 */
/* @0x103e68 mov r3, #5 */
/* @0x103e6c str r2, [r6, #0x8] */
/* @0x103e70 str r3, [r6, #0xc] */
/* @0x103e74 ldr r3, [r5, #0xc] */
/* @0x103e78 mov r1, #0 */
/* @0x103e7c ldr r2, [r5, #0x8] */
/* @0x103e80 str r1, [r6] */
/* @0x103e84 str r3, [r6, #0xc] */
/* @0x103e88 ldr r3, [r5, #0xc] */
/* @0x103e8c str r2, [r6, #0x8] */
/* @0x103e90 bic r3, r3, #-16777216 */
/* @0x103e94 cmp r3, #14 */
/* @0x103e98 addls pc, pc, r3, lsl #2 */
/* @0x103e9c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103ea0 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x103ea4 b 0x103f8c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x103ea8 b 0x103f60 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x103eac b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x103eb0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103eb4 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103eb8 b 0x103fa4 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x103ebc b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x103ec0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103ec4 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103ec8 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x103ecc b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103ed0 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103ed4 b 0x103f50 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1c0> */
/* @0x103ed8 b 0x103f44 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x103edc ldr r8, [r3, #0x8] */
/* @0x103ee0 ldr r0, [pc, #0x18c] */
/* @0x103ee4 mov r2, r5 */
/* @0x103ee8 ldr r1, [pc, #0x188] */
/* @0x103eec mov r3, r7 */
/* @0x103ef0 ldr r0, [pc, r0] */
/* @0x103ef4 add r1, pc, r1 */
/* @0x103ef8 ldr r0, [r0] */
/* @0x103efc ldr lr, [r0] */
/* @0x103f00 str r12, [sp] */
/* @0x103f04 stmib sp, {r4, r8} */
/* @0x103f08 ldr r12, [lr, #0xc] */
/* @0x103f0c blx r12 */
/* @0x103f10 mov r3, #0 */
/* @0x103f14 mov r2, #5 */
/* @0x103f18 str r3, [r6] */
/* @0x103f1c str r2, [r6, #0xc] */
/* @0x103f20 str r3, [r6, #0x4] */
/* @0x103f24 add sp, sp, #20 */
/* @0x103f28 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x103f2c ldr r0, [pc, #0x148] */
/* @0x103f30 mov r1, #0 */
/* @0x103f34 add r0, pc, r0 */
/* @0x103f38 add sp, sp, #20 */
/* @0x103f3c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x103f40 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x103f44 ldr r3, [r8, r7, lsl #4] */
/* @0x103f48 str r3, [r6] */
/* @0x103f4c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103f50 ldr r2, [r8, r7, lsl #4] */
/* @0x103f54 ldr r3, [r5, #0x4] */
/* @0x103f58 stm r6, {r2, r3} */
/* @0x103f5c b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103f60 ldr r3, [r8, r7, lsl #4] */
/* @0x103f64 cmp r3, #0 */
/* @0x103f68 str r3, [r6] */
/* @0x103f6c beq 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103f70 ldr r1, [r3, #0x8] */
/* @0x103f74 ldr r2, [r3] */
/* @0x103f78 cmp r1, #0 */
/* @0x103f7c streq r6, [r3, #0x8] */
/* @0x103f80 add r2, r2, #1 */
/* @0x103f84 str r2, [r3] */
/* @0x103f88 b 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103f8c ldr r3, [r8, r7, lsl #4] */
/* @0x103f90 cmp r3, #0 */
/* @0x103f94 ldrne r2, [r3, #0x4] */
/* @0x103f98 addne r2, r2, #1 */
/* @0x103f9c strne r2, [r3, #0x4] */
/* @0x103fa0 b 0x103f48 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x103fa4 ldr r3, [r8, r7, lsl #4] */
/* @0x103fa8 str r3, [r6] */
/* @0x103fac ldr r3, [r8, r7, lsl #4] */
/* @0x103fb0 cmp r3, #0 */
/* @0x103fb4 beq 0x103f24 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x194> */
/* @0x103fb8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x103fbc ldr r1, [r8, r7, lsl #4] */
/* @0x103fc0 add sp, sp, #20 */
/* @0x103fc4 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x103fc8 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x103fcc ldr r4, [r6] */
/* @0x103fd0 cmp r4, #0 */
/* @0x103fd4 beq 0x103ff4 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x103fd8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x103fdc ldr r3, [r4, #0x4] */
/* @0x103fe0 sub r3, r3, #1 */
/* @0x103fe4 str r3, [r4, #0x4] */
/* @0x103fe8 cmp r3, #0 */
/* @0x103fec beq 0x104000 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x103ff0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x103ff4 mov r3, #0 */
/* @0x103ff8 str r3, [r6] */
/* @0x103ffc b 0x103e74 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x104000 ldr r0, [r4] */
/* @0x104004 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104008 mov r3, #0 */
/* @0x10400c str r3, [r4] */
/* @0x104010 str r3, [r4, #0x8] */
/* @0x104014 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104018 ldr r9, [r4, #0x4] */
/* @0x10401c sub r9, r9, #1 */
/* @0x104020 str r9, [r4, #0x4] */
/* @0x104024 cmp r9, #0 */
/* @0x104028 beq 0x104048 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x2b8> */
/* @0x10402c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104030 mov r0, r4 */
/* @0x104034 bl 0x27d1d0 <_ZdlPv> */
/* @0x104038 b 0x103ff0 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x10403c mov r0, r6 */
/* @0x104040 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104044 b 0x103e64 <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x104048 ldr r0, [r4] */
/* @0x10404c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104050 mov r0, r4 */
/* @0x104054 str r9, [r4] */
/* @0x104058 str r9, [r4, #0x8] */
/* @0x10405c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x104060 mov r0, r4 */
/* @0x104064 bl 0x27d1d0 <_ZdlPv> */
/* @0x104068 b 0x10402c <_Z17F_DsGridGet_debugR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x10406c eoreq r10, lr, r8, lsr #1 */
/* @0x104070 mlaeq lr, r8, r0, r10 */
/* @0x104074 eoreq r9, lr, r0, asr r10 */
/* @0x104078 mlaeq r3, r8, r7, r4 */
/* @0x10407c eoreq r3, r3, r8, asr #25 */

/* ── FUNC 0x104080 · F_DsMapFindNext(RValue&, CInstance*, CInstance*, int, RValue*) · size=788 · insn=197 */
/* @0x104080 push {r4, r5, r6, r7, lr} */
/* @0x104084 sub sp, sp, #28 */
/* @0x104088 add r5, sp, #4 */
/* @0x10408c mov r4, r0 */
/* @0x104090 ldr r6, [sp, #0x30] */
/* @0x104094 mov r0, r5 */
/* @0x104098 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x10409c mov r1, #0 */
/* @0x1040a0 mov r0, r6 */
/* @0x1040a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1040a8 cmp r0, #0 */
/* @0x1040ac blt 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1040b0 ldr r3, [pc, #0x2d0] */
/* @0x1040b4 ldr r3, [pc, r3] */
/* @0x1040b8 ldr r3, [r3] */
/* @0x1040bc cmp r0, r3 */
/* @0x1040c0 bge 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1040c4 ldr r3, [pc, #0x2c0] */
/* @0x1040c8 ldr r3, [pc, r3] */
/* @0x1040cc ldr r3, [r3, #0x4] */
/* @0x1040d0 ldr r0, [r3, r0, lsl #2] */
/* @0x1040d4 cmp r0, #0 */
/* @0x1040d8 beq 0x10419c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1040dc add r1, r6, #16 */
/* @0x1040e0 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue> */
/* @0x1040e4 subs r3, r0, #0 */
/* @0x1040e8 beq 0x1041e8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1040ec ldr r2, [r3, #0x8] */
/* @0x1040f0 add r12, sp, #8 */
/* @0x1040f4 ldr r0, [r3] */
/* @0x1040f8 ldr r1, [r3, #0x4] */
/* @0x1040fc ldr r6, [r4, #0xc] */
/* @0x104100 ldr r3, [r3, #0xc] */
/* @0x104104 bic lr, r6, #-16777216 */
/* @0x104108 cmp lr, #1 */
/* @0x10410c stm r12!, {r0, r1, r2, r3} */
/* @0x104110 ldr r2, [sp, #0x14] */
/* @0x104114 bic r2, r2, #-16777216 */
/* @0x104118 str r2, [sp, #0x14] */
/* @0x10411c beq 0x1041fc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x104120 cmp lr, #2 */
/* @0x104124 bne 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x104128 sub r6, r6, #1 */
/* @0x10412c bic r6, r6, #-16777216 */
/* @0x104130 bic r6, r6, #3 */
/* @0x104134 cmp r6, #0 */
/* @0x104138 beq 0x1042e4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x10413c ldr r1, [sp, #0x10] */
/* @0x104140 bic r3, r2, #-16777216 */
/* @0x104144 str r2, [r4, #0xc] */
/* @0x104148 mov r2, #0 */
/* @0x10414c str r2, [r4] */
/* @0x104150 str r1, [r4, #0x8] */
/* @0x104154 cmp r3, #14 */
/* @0x104158 addls pc, pc, r3, lsl #2 */
/* @0x10415c b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104160 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x104164 b 0x10425c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x104168 b 0x104280 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x10416c b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x104170 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104174 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104178 b 0x104234 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x10417c b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x104180 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104184 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104188 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x10418c b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104190 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104194 b 0x1041d8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x104198 b 0x1041bc <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x10419c ldr r0, [pc, #0x1ec] */
/* @0x1041a0 mov r1, #0 */
/* @0x1041a4 add r0, pc, r0 */
/* @0x1041a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1041ac mov r0, r5 */
/* @0x1041b0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1041b4 add sp, sp, #28 */
/* @0x1041b8 pop {r4, r5, r6, r7, pc} */
/* @0x1041bc ldr r2, [sp, #0x8] */
/* @0x1041c0 str r2, [r4] */
/* @0x1041c4 str r3, [r4, #0xc] */
/* @0x1041c8 mov r0, r5 */
/* @0x1041cc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1041d0 add sp, sp, #28 */
/* @0x1041d4 pop {r4, r5, r6, r7, pc} */
/* @0x1041d8 ldr r1, [sp, #0x8] */
/* @0x1041dc ldr r2, [sp, #0xc] */
/* @0x1041e0 stm r4, {r1, r2} */
/* @0x1041e4 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1041e8 mov r2, #5 */
/* @0x1041ec str r3, [r4] */
/* @0x1041f0 str r3, [r4, #0x4] */
/* @0x1041f4 str r2, [r4, #0xc] */
/* @0x1041f8 b 0x1041c8 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1041fc ldr r6, [r4] */
/* @0x104200 cmp r6, #0 */
/* @0x104204 beq 0x104228 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x104208 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10420c ldr r7, [r6, #0x4] */
/* @0x104210 sub r7, r7, #1 */
/* @0x104214 str r7, [r6, #0x4] */
/* @0x104218 cmp r7, #0 */
/* @0x10421c beq 0x1042ac <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x104220 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104224 ldr r2, [sp, #0x14] */
/* @0x104228 mov r3, #0 */
/* @0x10422c str r3, [r4] */
/* @0x104230 b 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x104234 ldr r2, [sp, #0x8] */
/* @0x104238 cmp r2, #0 */
/* @0x10423c str r2, [r4] */
/* @0x104240 beq 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104244 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x104248 ldr r1, [sp, #0x8] */
/* @0x10424c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x104250 ldr r3, [r4, #0xc] */
/* @0x104254 bic r3, r3, #-16777216 */
/* @0x104258 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10425c ldr r2, [sp, #0x8] */
/* @0x104260 cmp r2, #0 */
/* @0x104264 beq 0x1041c0 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104268 ldr r3, [r2, #0x4] */
/* @0x10426c add r3, r3, #1 */
/* @0x104270 str r3, [r2, #0x4] */
/* @0x104274 ldr r3, [r4, #0xc] */
/* @0x104278 bic r3, r3, #-16777216 */
/* @0x10427c b 0x1041c0 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104280 ldr r2, [sp, #0x8] */
/* @0x104284 cmp r2, #0 */
/* @0x104288 str r2, [r4] */
/* @0x10428c beq 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x104290 ldr r0, [r2, #0x8] */
/* @0x104294 ldr r1, [r2] */
/* @0x104298 cmp r0, #0 */
/* @0x10429c streq r4, [r2, #0x8] */
/* @0x1042a0 add r1, r1, #1 */
/* @0x1042a4 str r1, [r2] */
/* @0x1042a8 b 0x1041c4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1042ac ldr r0, [r6] */
/* @0x1042b0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1042b4 str r7, [r6] */
/* @0x1042b8 str r7, [r6, #0x8] */
/* @0x1042bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1042c0 ldr r7, [r6, #0x4] */
/* @0x1042c4 sub r7, r7, #1 */
/* @0x1042c8 str r7, [r6, #0x4] */
/* @0x1042cc cmp r7, #0 */
/* @0x1042d0 beq 0x1042f4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x1042d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1042d8 mov r0, r6 */
/* @0x1042dc bl 0x27d1d0 <_ZdlPv> */
/* @0x1042e0 b 0x104220 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x1042e4 mov r0, r4 */
/* @0x1042e8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1042ec ldr r2, [sp, #0x14] */
/* @0x1042f0 b 0x10413c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1042f4 ldr r0, [r6] */
/* @0x1042f8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1042fc str r7, [r6] */
/* @0x104300 str r7, [r6, #0x8] */
/* @0x104304 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104308 ldr r7, [r6, #0x4] */
/* @0x10430c sub r7, r7, #1 */
/* @0x104310 str r7, [r6, #0x4] */
/* @0x104314 cmp r7, #0 */
/* @0x104318 beq 0x10432c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x10431c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104320 mov r0, r6 */
/* @0x104324 bl 0x27d1d0 <_ZdlPv> */
/* @0x104328 b 0x1042d4 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x10432c ldr r0, [r6] */
/* @0x104330 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104334 str r7, [r6] */
/* @0x104338 str r7, [r6, #0x8] */
/* @0x10433c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104340 ldr r3, [r6, #0x4] */
/* @0x104344 sub r3, r3, #1 */
/* @0x104348 str r3, [r6, #0x4] */
/* @0x10434c cmp r3, #0 */
/* @0x104350 bne 0x104378 <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x104354 ldr r0, [r6] */
/* @0x104358 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10435c mov r3, #0 */
/* @0x104360 mov r0, r6 */
/* @0x104364 str r3, [r6] */
/* @0x104368 str r3, [r6, #0x8] */
/* @0x10436c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x104370 mov r0, r6 */
/* @0x104374 bl 0x27d1d0 <_ZdlPv> */
/* @0x104378 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10437c mov r0, r6 */
/* @0x104380 bl 0x27d1d0 <_ZdlPv> */
/* @0x104384 b 0x10431c <_Z15F_DsMapFindNextR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x104388 eoreq r9, lr, r4, asr #23 */
/* @0x10438c eoreq r9, lr, r4, ror r8 */
/* @0x104390 eoreq r3, r3, r8, asr r10 */

/* ── FUNC 0x104394 · F_DsMapFindFirst(RValue&, CInstance*, CInstance*, int, RValue*) · size=784 · insn=196 */
/* @0x104394 push {r4, r5, r6, r7, lr} */
/* @0x104398 sub sp, sp, #28 */
/* @0x10439c add r5, sp, #4 */
/* @0x1043a0 mov r4, r0 */
/* @0x1043a4 ldr r6, [sp, #0x30] */
/* @0x1043a8 mov r0, r5 */
/* @0x1043ac bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1043b0 mov r1, #0 */
/* @0x1043b4 mov r0, r6 */
/* @0x1043b8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1043bc cmp r0, #0 */
/* @0x1043c0 blt 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1043c4 ldr r3, [pc, #0x2cc] */
/* @0x1043c8 ldr r3, [pc, r3] */
/* @0x1043cc ldr r3, [r3] */
/* @0x1043d0 cmp r0, r3 */
/* @0x1043d4 bge 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1043d8 ldr r3, [pc, #0x2bc] */
/* @0x1043dc ldr r3, [pc, r3] */
/* @0x1043e0 ldr r3, [r3, #0x4] */
/* @0x1043e4 ldr r0, [r3, r0, lsl #2] */
/* @0x1043e8 cmp r0, #0 */
/* @0x1043ec beq 0x1044ac <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1043f0 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv> */
/* @0x1043f4 subs r3, r0, #0 */
/* @0x1043f8 beq 0x1044f8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x1043fc ldr r2, [r3, #0x8] */
/* @0x104400 add r12, sp, #8 */
/* @0x104404 ldr r0, [r3] */
/* @0x104408 ldr r1, [r3, #0x4] */
/* @0x10440c ldr r6, [r4, #0xc] */
/* @0x104410 ldr r3, [r3, #0xc] */
/* @0x104414 bic lr, r6, #-16777216 */
/* @0x104418 cmp lr, #1 */
/* @0x10441c stm r12!, {r0, r1, r2, r3} */
/* @0x104420 ldr r2, [sp, #0x14] */
/* @0x104424 bic r2, r2, #-16777216 */
/* @0x104428 str r2, [sp, #0x14] */
/* @0x10442c beq 0x10450c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x104430 cmp lr, #2 */
/* @0x104434 bne 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104438 sub r6, r6, #1 */
/* @0x10443c bic r6, r6, #-16777216 */
/* @0x104440 bic r6, r6, #3 */
/* @0x104444 cmp r6, #0 */
/* @0x104448 beq 0x1045f4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x10444c ldr r1, [sp, #0x10] */
/* @0x104450 bic r3, r2, #-16777216 */
/* @0x104454 str r2, [r4, #0xc] */
/* @0x104458 mov r2, #0 */
/* @0x10445c str r2, [r4] */
/* @0x104460 str r1, [r4, #0x8] */
/* @0x104464 cmp r3, #14 */
/* @0x104468 addls pc, pc, r3, lsl #2 */
/* @0x10446c b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104470 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x104474 b 0x10456c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x104478 b 0x104590 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x10447c b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x104480 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104484 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104488 b 0x104544 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x10448c b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x104490 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104494 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104498 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x10449c b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1044a0 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1044a4 b 0x1044e8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1044a8 b 0x1044cc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1044ac ldr r0, [pc, #0x1ec] */
/* @0x1044b0 mov r1, #0 */
/* @0x1044b4 add r0, pc, r0 */
/* @0x1044b8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1044bc mov r0, r5 */
/* @0x1044c0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1044c4 add sp, sp, #28 */
/* @0x1044c8 pop {r4, r5, r6, r7, pc} */
/* @0x1044cc ldr r2, [sp, #0x8] */
/* @0x1044d0 str r2, [r4] */
/* @0x1044d4 str r3, [r4, #0xc] */
/* @0x1044d8 mov r0, r5 */
/* @0x1044dc bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1044e0 add sp, sp, #28 */
/* @0x1044e4 pop {r4, r5, r6, r7, pc} */
/* @0x1044e8 ldr r1, [sp, #0x8] */
/* @0x1044ec ldr r2, [sp, #0xc] */
/* @0x1044f0 stm r4, {r1, r2} */
/* @0x1044f4 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1044f8 mov r2, #5 */
/* @0x1044fc str r3, [r4] */
/* @0x104500 str r3, [r4, #0x4] */
/* @0x104504 str r2, [r4, #0xc] */
/* @0x104508 b 0x1044d8 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10450c ldr r6, [r4] */
/* @0x104510 cmp r6, #0 */
/* @0x104514 beq 0x104538 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x104518 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10451c ldr r7, [r6, #0x4] */
/* @0x104520 sub r7, r7, #1 */
/* @0x104524 str r7, [r6, #0x4] */
/* @0x104528 cmp r7, #0 */
/* @0x10452c beq 0x1045bc <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x104530 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104534 ldr r2, [sp, #0x14] */
/* @0x104538 mov r3, #0 */
/* @0x10453c str r3, [r4] */
/* @0x104540 b 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104544 ldr r2, [sp, #0x8] */
/* @0x104548 cmp r2, #0 */
/* @0x10454c str r2, [r4] */
/* @0x104550 beq 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104554 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x104558 ldr r1, [sp, #0x8] */
/* @0x10455c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x104560 ldr r3, [r4, #0xc] */
/* @0x104564 bic r3, r3, #-16777216 */
/* @0x104568 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x10456c ldr r2, [sp, #0x8] */
/* @0x104570 cmp r2, #0 */
/* @0x104574 beq 0x1044d0 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x104578 ldr r3, [r2, #0x4] */
/* @0x10457c add r3, r3, #1 */
/* @0x104580 str r3, [r2, #0x4] */
/* @0x104584 ldr r3, [r4, #0xc] */
/* @0x104588 bic r3, r3, #-16777216 */
/* @0x10458c b 0x1044d0 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x104590 ldr r2, [sp, #0x8] */
/* @0x104594 cmp r2, #0 */
/* @0x104598 str r2, [r4] */
/* @0x10459c beq 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1045a0 ldr r0, [r2, #0x8] */
/* @0x1045a4 ldr r1, [r2] */
/* @0x1045a8 cmp r0, #0 */
/* @0x1045ac streq r4, [r2, #0x8] */
/* @0x1045b0 add r1, r1, #1 */
/* @0x1045b4 str r1, [r2] */
/* @0x1045b8 b 0x1044d4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1045bc ldr r0, [r6] */
/* @0x1045c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1045c4 str r7, [r6] */
/* @0x1045c8 str r7, [r6, #0x8] */
/* @0x1045cc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1045d0 ldr r7, [r6, #0x4] */
/* @0x1045d4 sub r7, r7, #1 */
/* @0x1045d8 str r7, [r6, #0x4] */
/* @0x1045dc cmp r7, #0 */
/* @0x1045e0 beq 0x104604 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x1045e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1045e8 mov r0, r6 */
/* @0x1045ec bl 0x27d1d0 <_ZdlPv> */
/* @0x1045f0 b 0x104530 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x1045f4 mov r0, r4 */
/* @0x1045f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1045fc ldr r2, [sp, #0x14] */
/* @0x104600 b 0x10444c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104604 ldr r0, [r6] */
/* @0x104608 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10460c str r7, [r6] */
/* @0x104610 str r7, [r6, #0x8] */
/* @0x104614 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104618 ldr r7, [r6, #0x4] */
/* @0x10461c sub r7, r7, #1 */
/* @0x104620 str r7, [r6, #0x4] */
/* @0x104624 cmp r7, #0 */
/* @0x104628 beq 0x10463c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x10462c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104630 mov r0, r6 */
/* @0x104634 bl 0x27d1d0 <_ZdlPv> */
/* @0x104638 b 0x1045e4 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x10463c ldr r0, [r6] */
/* @0x104640 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104644 str r7, [r6] */
/* @0x104648 str r7, [r6, #0x8] */
/* @0x10464c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104650 ldr r3, [r6, #0x4] */
/* @0x104654 sub r3, r3, #1 */
/* @0x104658 str r3, [r6, #0x4] */
/* @0x10465c cmp r3, #0 */
/* @0x104660 bne 0x104688 <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x2f4> */
/* @0x104664 ldr r0, [r6] */
/* @0x104668 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10466c mov r3, #0 */
/* @0x104670 mov r0, r6 */
/* @0x104674 str r3, [r6] */
/* @0x104678 str r3, [r6, #0x8] */
/* @0x10467c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x104680 mov r0, r6 */
/* @0x104684 bl 0x27d1d0 <_ZdlPv> */
/* @0x104688 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10468c mov r0, r6 */
/* @0x104690 bl 0x27d1d0 <_ZdlPv> */
/* @0x104694 b 0x10462c <_Z16F_DsMapFindFirstR6RValueP9CInstanceS2_iPS_+0x298> */
/* @0x104698 .word 0x002e98b0 */
/* @0x10469c eoreq r9, lr, r0, ror #10 */
/* @0x1046a0 eoreq r3, r3, r8, asr #14 */

/* ── FUNC 0x1046a4 · F_DsMapFindLast(RValue&, CInstance*, CInstance*, int, RValue*) · size=784 · insn=196 */
/* @0x1046a4 push {r4, r5, r6, r7, lr} */
/* @0x1046a8 sub sp, sp, #28 */
/* @0x1046ac add r5, sp, #4 */
/* @0x1046b0 mov r4, r0 */
/* @0x1046b4 ldr r6, [sp, #0x30] */
/* @0x1046b8 mov r0, r5 */
/* @0x1046bc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1046c0 mov r1, #0 */
/* @0x1046c4 mov r0, r6 */
/* @0x1046c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1046cc cmp r0, #0 */
/* @0x1046d0 blt 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1046d4 ldr r3, [pc, #0x2cc] */
/* @0x1046d8 ldr r3, [pc, r3] */
/* @0x1046dc ldr r3, [r3] */
/* @0x1046e0 cmp r0, r3 */
/* @0x1046e4 bge 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x1046e8 ldr r3, [pc, #0x2bc] */
/* @0x1046ec ldr r3, [pc, r3] */
/* @0x1046f0 ldr r3, [r3, #0x4] */
/* @0x1046f4 ldr r0, [r3, r0, lsl #2] */
/* @0x1046f8 cmp r0, #0 */
/* @0x1046fc beq 0x1047bc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x104700 bl 0x203cc4 <_ZN7CDS_Map8FindLastEv> */
/* @0x104704 subs r3, r0, #0 */
/* @0x104708 beq 0x104808 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x164> */
/* @0x10470c ldr r2, [r3, #0x8] */
/* @0x104710 add r12, sp, #8 */
/* @0x104714 ldr r0, [r3] */
/* @0x104718 ldr r1, [r3, #0x4] */
/* @0x10471c ldr r6, [r4, #0xc] */
/* @0x104720 ldr r3, [r3, #0xc] */
/* @0x104724 bic lr, r6, #-16777216 */
/* @0x104728 cmp lr, #1 */
/* @0x10472c stm r12!, {r0, r1, r2, r3} */
/* @0x104730 ldr r2, [sp, #0x14] */
/* @0x104734 bic r2, r2, #-16777216 */
/* @0x104738 str r2, [sp, #0x14] */
/* @0x10473c beq 0x10481c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x104740 cmp lr, #2 */
/* @0x104744 bne 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104748 sub r6, r6, #1 */
/* @0x10474c bic r6, r6, #-16777216 */
/* @0x104750 bic r6, r6, #3 */
/* @0x104754 cmp r6, #0 */
/* @0x104758 beq 0x104904 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x260> */
/* @0x10475c ldr r1, [sp, #0x10] */
/* @0x104760 bic r3, r2, #-16777216 */
/* @0x104764 str r2, [r4, #0xc] */
/* @0x104768 mov r2, #0 */
/* @0x10476c str r2, [r4] */
/* @0x104770 str r1, [r4, #0x8] */
/* @0x104774 cmp r3, #14 */
/* @0x104778 addls pc, pc, r3, lsl #2 */
/* @0x10477c b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104780 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x104784 b 0x10487c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x104788 b 0x1048a0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1fc> */
/* @0x10478c b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x104790 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104794 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104798 b 0x104854 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x10479c b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1047a0 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1047a4 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1047a8 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1047ac b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1047b0 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1047b4 b 0x1047f8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1047b8 b 0x1047dc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1047bc ldr r0, [pc, #0x1ec] */
/* @0x1047c0 mov r1, #0 */
/* @0x1047c4 add r0, pc, r0 */
/* @0x1047c8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1047cc mov r0, r5 */
/* @0x1047d0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1047d4 add sp, sp, #28 */
/* @0x1047d8 pop {r4, r5, r6, r7, pc} */
/* @0x1047dc ldr r2, [sp, #0x8] */
/* @0x1047e0 str r2, [r4] */
/* @0x1047e4 str r3, [r4, #0xc] */
/* @0x1047e8 mov r0, r5 */
/* @0x1047ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1047f0 add sp, sp, #28 */
/* @0x1047f4 pop {r4, r5, r6, r7, pc} */
/* @0x1047f8 ldr r1, [sp, #0x8] */
/* @0x1047fc ldr r2, [sp, #0xc] */
/* @0x104800 stm r4, {r1, r2} */
/* @0x104804 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104808 mov r2, #5 */
/* @0x10480c str r3, [r4] */
/* @0x104810 str r3, [r4, #0x4] */
/* @0x104814 str r2, [r4, #0xc] */
/* @0x104818 b 0x1047e8 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10481c ldr r6, [r4] */
/* @0x104820 cmp r6, #0 */
/* @0x104824 beq 0x104848 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x104828 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10482c ldr r7, [r6, #0x4] */
/* @0x104830 sub r7, r7, #1 */
/* @0x104834 str r7, [r6, #0x4] */
/* @0x104838 cmp r7, #0 */
/* @0x10483c beq 0x1048cc <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x104840 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104844 ldr r2, [sp, #0x14] */
/* @0x104848 mov r3, #0 */
/* @0x10484c str r3, [r4] */
/* @0x104850 b 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104854 ldr r2, [sp, #0x8] */
/* @0x104858 cmp r2, #0 */
/* @0x10485c str r2, [r4] */
/* @0x104860 beq 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x104864 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x104868 ldr r1, [sp, #0x8] */
/* @0x10486c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x104870 ldr r3, [r4, #0xc] */
/* @0x104874 bic r3, r3, #-16777216 */
/* @0x104878 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x10487c ldr r2, [sp, #0x8] */
/* @0x104880 cmp r2, #0 */
/* @0x104884 beq 0x1047e0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x104888 ldr r3, [r2, #0x4] */
/* @0x10488c add r3, r3, #1 */
/* @0x104890 str r3, [r2, #0x4] */
/* @0x104894 ldr r3, [r4, #0xc] */
/* @0x104898 bic r3, r3, #-16777216 */
/* @0x10489c b 0x1047e0 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1048a0 ldr r2, [sp, #0x8] */
/* @0x1048a4 cmp r2, #0 */
/* @0x1048a8 str r2, [r4] */
/* @0x1048ac beq 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1048b0 ldr r0, [r2, #0x8] */
/* @0x1048b4 ldr r1, [r2] */
/* @0x1048b8 cmp r0, #0 */
/* @0x1048bc streq r4, [r2, #0x8] */
/* @0x1048c0 add r1, r1, #1 */
/* @0x1048c4 str r1, [r2] */
/* @0x1048c8 b 0x1047e4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1048cc ldr r0, [r6] */
/* @0x1048d0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1048d4 str r7, [r6] */
/* @0x1048d8 str r7, [r6, #0x8] */
/* @0x1048dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1048e0 ldr r7, [r6, #0x4] */
/* @0x1048e4 sub r7, r7, #1 */
/* @0x1048e8 str r7, [r6, #0x4] */
/* @0x1048ec cmp r7, #0 */
/* @0x1048f0 beq 0x104914 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x270> */
/* @0x1048f4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1048f8 mov r0, r6 */
/* @0x1048fc bl 0x27d1d0 <_ZdlPv> */
/* @0x104900 b 0x104840 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x19c> */
/* @0x104904 mov r0, r4 */
/* @0x104908 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10490c ldr r2, [sp, #0x14] */
/* @0x104910 b 0x10475c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x104914 ldr r0, [r6] */
/* @0x104918 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10491c str r7, [r6] */
/* @0x104920 str r7, [r6, #0x8] */
/* @0x104924 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104928 ldr r7, [r6, #0x4] */
/* @0x10492c sub r7, r7, #1 */
/* @0x104930 str r7, [r6, #0x4] */
/* @0x104934 cmp r7, #0 */
/* @0x104938 beq 0x10494c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x2a8> */
/* @0x10493c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104940 mov r0, r6 */
/* @0x104944 bl 0x27d1d0 <_ZdlPv> */
/* @0x104948 b 0x1048f4 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x250> */
/* @0x10494c ldr r0, [r6] */
/* @0x104950 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104954 str r7, [r6] */
/* @0x104958 str r7, [r6, #0x8] */
/* @0x10495c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104960 ldr r3, [r6, #0x4] */
/* @0x104964 sub r3, r3, #1 */
/* @0x104968 str r3, [r6, #0x4] */
/* @0x10496c cmp r3, #0 */
/* @0x104970 bne 0x104998 <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x2f4> */
/* @0x104974 ldr r0, [r6] */
/* @0x104978 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10497c mov r3, #0 */
/* @0x104980 mov r0, r6 */
/* @0x104984 str r3, [r6] */
/* @0x104988 str r3, [r6, #0x8] */
/* @0x10498c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x104990 mov r0, r6 */
/* @0x104994 bl 0x27d1d0 <_ZdlPv> */
/* @0x104998 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10499c mov r0, r6 */
/* @0x1049a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1049a4 b 0x10493c <_Z15F_DsMapFindLastR6RValueP9CInstanceS2_iPS_+0x298> */
/* @0x1049a8 eoreq r9, lr, r0, lsr #11 */
/* @0x1049ac eoreq r9, lr, r0, asr r2 */
/* @0x1049b0 eoreq r3, r3, r8, lsr r4 */

/* ── FUNC 0x1049b4 · YYGML_ds_grid_set(int, int, int, YYRValue const&) · size=992 · insn=248 */
/* @0x1049b4 ldr r12, [pc, #0x3bc] */
/* @0x1049b8 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1049bc add r12, pc, r12 */
/* @0x1049c0 ldr r5, [pc, #0x3b4] */
/* @0x1049c4 sub sp, sp, #20 */
/* @0x1049c8 mov r8, r2 */
/* @0x1049cc mov r4, r3 */
/* @0x1049d0 ldr r5, [r12, r5] */
/* @0x1049d4 ldrb r5, [r5] */
/* @0x1049d8 cmp r5, #0 */
/* @0x1049dc bne 0x104aa0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0xec> */
/* @0x1049e0 ldr r3, [pc, #0x398] */
/* @0x1049e4 ldr r3, [r12, r3] */
/* @0x1049e8 ldr r3, [r3, #0x4] */
/* @0x1049ec ldr r3, [r3, r0, lsl #2] */
/* @0x1049f0 ldm r3, {r6, r7} */
/* @0x1049f4 mla r7, r7, r2, r1 */
/* @0x1049f8 add r5, r6, r7, lsl #4 */
/* @0x1049fc ldr r2, [r5, #0xc] */
/* @0x104a00 bic r3, r2, #-16777216 */
/* @0x104a04 cmp r3, #1 */
/* @0x104a08 beq 0x104b88 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1d4> */
/* @0x104a0c cmp r3, #2 */
/* @0x104a10 bne 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84> */
/* @0x104a14 sub r2, r2, #1 */
/* @0x104a18 bic r2, r2, #-16777216 */
/* @0x104a1c bic r2, r2, #3 */
/* @0x104a20 cmp r2, #0 */
/* @0x104a24 beq 0x104b24 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x170> */
/* @0x104a28 mov r2, #0 */
/* @0x104a2c mov r3, #5 */
/* @0x104a30 str r2, [r5, #0x8] */
/* @0x104a34 str r3, [r5, #0xc] */
/* @0x104a38 ldr r3, [r4, #0xc] */
/* @0x104a3c mov r1, #0 */
/* @0x104a40 ldr r2, [r4, #0x8] */
/* @0x104a44 str r1, [r6, r7, lsl #4] */
/* @0x104a48 str r3, [r5, #0xc] */
/* @0x104a4c ldr r3, [r4, #0xc] */
/* @0x104a50 str r2, [r5, #0x8] */
/* @0x104a54 bic r3, r3, #-16777216 */
/* @0x104a58 cmp r3, #14 */
/* @0x104a5c addls pc, pc, r3, lsl #2 */
/* @0x104a60 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a64 b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208> */
/* @0x104a68 b 0x104c0c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x258> */
/* @0x104a6c b 0x104b48 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x194> */
/* @0x104a70 b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4> */
/* @0x104a74 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a78 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a7c b 0x104c24 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x270> */
/* @0x104a80 b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4> */
/* @0x104a84 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a88 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a8c b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208> */
/* @0x104a90 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a94 b 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104a98 b 0x104bbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x208> */
/* @0x104a9c b 0x104b78 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c4> */
/* @0x104aa0 cmp r0, #0 */
/* @0x104aa4 blt 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c> */
/* @0x104aa8 ldr r3, [pc, #0x2d4] */
/* @0x104aac ldr r3, [r12, r3] */
/* @0x104ab0 ldr r3, [r3] */
/* @0x104ab4 cmp r0, r3 */
/* @0x104ab8 bge 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c> */
/* @0x104abc ldr r3, [pc, #0x2bc] */
/* @0x104ac0 ldr r3, [r12, r3] */
/* @0x104ac4 ldr r3, [r3, #0x4] */
/* @0x104ac8 ldr r3, [r3, r0, lsl #2] */
/* @0x104acc cmp r3, #0 */
/* @0x104ad0 beq 0x104b30 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x17c> */
/* @0x104ad4 ldr r7, [r3, #0x4] */
/* @0x104ad8 ldr r5, [r3, #0x8] */
/* @0x104adc cmp r1, r7 */
/* @0x104ae0 bhs 0x104bd0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x21c> */
/* @0x104ae4 cmp r2, r5 */
/* @0x104ae8 bhs 0x104bd0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x21c> */
/* @0x104aec mla r7, r7, r2, r1 */
/* @0x104af0 ldr r6, [r3] */
/* @0x104af4 add r5, r6, r7, lsl #4 */
/* @0x104af8 ldr r2, [r5, #0xc] */
/* @0x104afc bic r3, r2, #-16777216 */
/* @0x104b00 cmp r3, #1 */
/* @0x104b04 beq 0x104cbc <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x308> */
/* @0x104b08 cmp r3, #2 */
/* @0x104b0c bne 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84> */
/* @0x104b10 sub r3, r2, #1 */
/* @0x104b14 bic r3, r3, #-16777216 */
/* @0x104b18 bic r3, r3, #3 */
/* @0x104b1c cmp r3, #0 */
/* @0x104b20 bne 0x104a28 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x74> */
/* @0x104b24 mov r0, r5 */
/* @0x104b28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104b2c b 0x104a28 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x74> */
/* @0x104b30 ldr r0, [pc, #0x250] */
/* @0x104b34 mov r1, #0 */
/* @0x104b38 add r0, pc, r0 */
/* @0x104b3c add sp, sp, #20 */
/* @0x104b40 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x104b44 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x104b48 ldr r3, [r4] */
/* @0x104b4c cmp r3, #0 */
/* @0x104b50 str r3, [r6, r7, lsl #4] */
/* @0x104b54 beq 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104b58 ldr r1, [r3, #0x8] */
/* @0x104b5c ldr r2, [r3] */
/* @0x104b60 cmp r1, #0 */
/* @0x104b64 streq r5, [r3, #0x8] */
/* @0x104b68 add r2, r2, #1 */
/* @0x104b6c str r2, [r3] */
/* @0x104b70 add sp, sp, #20 */
/* @0x104b74 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104b78 ldr r3, [r4] */
/* @0x104b7c str r3, [r6, r7, lsl #4] */
/* @0x104b80 add sp, sp, #20 */
/* @0x104b84 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104b88 ldr r8, [r6, r7, lsl #4] */
/* @0x104b8c cmp r8, #0 */
/* @0x104b90 beq 0x104bb0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1fc> */
/* @0x104b94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104b98 ldr r9, [r8, #0x4] */
/* @0x104b9c sub r9, r9, #1 */
/* @0x104ba0 str r9, [r8, #0x4] */
/* @0x104ba4 cmp r9, #0 */
/* @0x104ba8 beq 0x104c4c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x298> */
/* @0x104bac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104bb0 mov r3, #0 */
/* @0x104bb4 str r3, [r6, r7, lsl #4] */
/* @0x104bb8 b 0x104a38 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x84> */
/* @0x104bbc ldm r4, {r2, r3} */
/* @0x104bc0 str r2, [r6, r7, lsl #4] */
/* @0x104bc4 str r3, [r5, #0x4] */
/* @0x104bc8 add sp, sp, #20 */
/* @0x104bcc pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104bd0 ldr lr, [pc, #0x1b4] */
/* @0x104bd4 mov r2, r0 */
/* @0x104bd8 mov r3, r1 */
/* @0x104bdc ldr r1, [pc, #0x1ac] */
/* @0x104be0 ldr r0, [r12, lr] */
/* @0x104be4 add r1, pc, r1 */
/* @0x104be8 ldr r0, [r0] */
/* @0x104bec ldr r12, [r0] */
/* @0x104bf0 str r8, [sp] */
/* @0x104bf4 str r7, [sp, #0x4] */
/* @0x104bf8 str r5, [sp, #0x8] */
/* @0x104bfc ldr r12, [r12, #0xc] */
/* @0x104c00 blx r12 */
/* @0x104c04 add sp, sp, #20 */
/* @0x104c08 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104c0c ldr r3, [r4] */
/* @0x104c10 cmp r3, #0 */
/* @0x104c14 ldrne r2, [r3, #0x4] */
/* @0x104c18 addne r2, r2, #1 */
/* @0x104c1c strne r2, [r3, #0x4] */
/* @0x104c20 b 0x104b7c <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1c8> */
/* @0x104c24 ldr r3, [r4] */
/* @0x104c28 str r3, [r6, r7, lsl #4] */
/* @0x104c2c ldr r3, [r4] */
/* @0x104c30 cmp r3, #0 */
/* @0x104c34 beq 0x104b70 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1bc> */
/* @0x104c38 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x104c3c ldr r1, [r4] */
/* @0x104c40 add sp, sp, #20 */
/* @0x104c44 pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x104c48 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x104c4c ldr r0, [r8] */
/* @0x104c50 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104c54 str r9, [r8] */
/* @0x104c58 str r9, [r8, #0x8] */
/* @0x104c5c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104c60 ldr r9, [r8, #0x4] */
/* @0x104c64 sub r9, r9, #1 */
/* @0x104c68 str r9, [r8, #0x4] */
/* @0x104c6c cmp r9, #0 */
/* @0x104c70 beq 0x104c84 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2d0> */
/* @0x104c74 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104c78 mov r0, r8 */
/* @0x104c7c bl 0x27d1d0 <_ZdlPv> */
/* @0x104c80 b 0x104bac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1f8> */
/* @0x104c84 ldr r0, [r8] */
/* @0x104c88 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104c8c str r9, [r8] */
/* @0x104c90 str r9, [r8, #0x8] */
/* @0x104c94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104c98 ldr r9, [r8, #0x4] */
/* @0x104c9c sub r9, r9, #1 */
/* @0x104ca0 str r9, [r8, #0x4] */
/* @0x104ca4 cmp r9, #0 */
/* @0x104ca8 beq 0x104d20 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x36c> */
/* @0x104cac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104cb0 mov r0, r8 */
/* @0x104cb4 bl 0x27d1d0 <_ZdlPv> */
/* @0x104cb8 b 0x104c74 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2c0> */
/* @0x104cbc ldr r8, [r6, r7, lsl #4] */
/* @0x104cc0 cmp r8, #0 */
/* @0x104cc4 beq 0x104bb0 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1fc> */
/* @0x104cc8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104ccc ldr r9, [r8, #0x4] */
/* @0x104cd0 sub r9, r9, #1 */
/* @0x104cd4 str r9, [r8, #0x4] */
/* @0x104cd8 cmp r9, #0 */
/* @0x104cdc bne 0x104bac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x1f8> */
/* @0x104ce0 ldr r0, [r8] */
/* @0x104ce4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104ce8 str r9, [r8] */
/* @0x104cec str r9, [r8, #0x8] */
/* @0x104cf0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104cf4 ldr r3, [r8, #0x4] */
/* @0x104cf8 sub r3, r3, #1 */
/* @0x104cfc str r3, [r8, #0x4] */
/* @0x104d00 cmp r3, #0 */
/* @0x104d04 bne 0x104c74 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2c0> */
/* @0x104d08 ldr r0, [r8] */
/* @0x104d0c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104d10 mov r3, #0 */
/* @0x104d14 str r3, [r8] */
/* @0x104d18 str r3, [r8, #0x8] */
/* @0x104d1c b 0x104c94 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2e0> */
/* @0x104d20 ldr r0, [r8] */
/* @0x104d24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104d28 str r9, [r8] */
/* @0x104d2c str r9, [r8, #0x8] */
/* @0x104d30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x104d34 ldr r9, [r8, #0x4] */
/* @0x104d38 sub r9, r9, #1 */
/* @0x104d3c str r9, [r8, #0x4] */
/* @0x104d40 cmp r9, #0 */
/* @0x104d44 bne 0x104d68 <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x3b4> */
/* @0x104d48 ldr r0, [r8] */
/* @0x104d4c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x104d50 mov r0, r8 */
/* @0x104d54 str r9, [r8] */
/* @0x104d58 str r9, [r8, #0x8] */
/* @0x104d5c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x104d60 mov r0, r8 */
/* @0x104d64 bl 0x27d1d0 <_ZdlPv> */
/* @0x104d68 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x104d6c mov r0, r8 */
/* @0x104d70 bl 0x27d1d0 <_ZdlPv> */
/* @0x104d74 b 0x104cac <_Z17YYGML_ds_grid_setiiiRK8YYRValue+0x2f8> */
/* @0x104d78 mlaeq lr, r4, r2, sp */
/* @0x104d7c .word 0xffffc240 */
/* @0x104d80 .word 0xffffc238 */
/* @0x104d84 .word 0xffffc234 */
/* @0x104d88 eoreq r3, r3, r4, asr #1 */
/* @0x104d8c .word 0xffffbcf0 */
/* @0x104d90 eoreq r3, r3, r8, lsr #21 */

/* ── FUNC 0x104d94 · F_DsMapAdd_Internal(int, char*, double) · size=232 · insn=58 */
/* @0x104d94 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x104d98 sub sp, sp, #44 */
/* @0x104d9c add r8, sp, #4 */
/* @0x104da0 add r7, sp, #8 */
/* @0x104da4 mov r6, r1 */
/* @0x104da8 mov r9, r0 */
/* @0x104dac mov r0, r8 */
/* @0x104db0 mov r4, r2 */
/* @0x104db4 mov r5, r3 */
/* @0x104db8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x104dbc mov r1, r6 */
/* @0x104dc0 mov r0, r7 */
/* @0x104dc4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x104dc8 ldr r3, [pc, #0xa8] */
/* @0x104dcc add r6, sp, #40 */
/* @0x104dd0 mov r0, #0 */
/* @0x104dd4 ldr r3, [pc, r3] */
/* @0x104dd8 str r0, [sp, #0x24] */
/* @0x104ddc strd r4, r5, [r6, #-16]! */
/* @0x104de0 mov r1, r7 */
/* @0x104de4 ldr r3, [r3, #0x4] */
/* @0x104de8 mov r2, r6 */
/* @0x104dec ldr r0, [r3, r9, lsl #2] */
/* @0x104df0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x104df4 ldr r3, [sp, #0x24] */
/* @0x104df8 sub r3, r3, #1 */
/* @0x104dfc bic r3, r3, #-16777216 */
/* @0x104e00 bic r3, r3, #3 */
/* @0x104e04 cmp r3, #0 */
/* @0x104e08 mov r4, r0 */
/* @0x104e0c beq 0x104e6c <_Z19F_DsMapAdd_InternaliPcd+0xd8> */
/* @0x104e10 ldr r1, [sp, #0x14] */
/* @0x104e14 mov r3, #0 */
/* @0x104e18 str r3, [sp, #0x20] */
/* @0x104e1c mov r2, #5 */
/* @0x104e20 sub r1, r1, #1 */
/* @0x104e24 str r3, [sp, #0x18] */
/* @0x104e28 bic r3, r1, #-16777216 */
/* @0x104e2c str r2, [sp, #0x24] */
/* @0x104e30 bic r3, r3, #3 */
/* @0x104e34 cmp r3, #0 */
/* @0x104e38 bne 0x104e44 <_Z19F_DsMapAdd_InternaliPcd+0xb0> */
/* @0x104e3c mov r0, r7 */
/* @0x104e40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104e44 mov r0, r8 */
/* @0x104e48 mov r3, #0 */
/* @0x104e4c mov r2, #5 */
/* @0x104e50 str r3, [sp, #0x10] */
/* @0x104e54 str r3, [sp, #0x8] */
/* @0x104e58 str r2, [sp, #0x14] */
/* @0x104e5c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x104e60 mov r0, r4 */
/* @0x104e64 add sp, sp, #44 */
/* @0x104e68 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104e6c mov r0, r6 */
/* @0x104e70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104e74 b 0x104e10 <_Z19F_DsMapAdd_InternaliPcd+0x7c> */
/* @0x104e78 eoreq r8, lr, r8, ror #22 */

/* ── FUNC 0x104e7c · F_DsMapAdd_Internal(int, char*, long long, bool) · size=232 · insn=58 */
/* @0x104e7c push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x104e80 sub sp, sp, #44 */
/* @0x104e84 add r8, sp, #4 */
/* @0x104e88 add r7, sp, #8 */
/* @0x104e8c mov r6, r1 */
/* @0x104e90 mov r9, r0 */
/* @0x104e94 mov r0, r8 */
/* @0x104e98 mov r4, r2 */
/* @0x104e9c mov r5, r3 */
/* @0x104ea0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x104ea4 mov r1, r6 */
/* @0x104ea8 mov r0, r7 */
/* @0x104eac bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x104eb0 ldr r3, [pc, #0xa8] */
/* @0x104eb4 add r6, sp, #40 */
/* @0x104eb8 mov r0, #10 */
/* @0x104ebc ldr r3, [pc, r3] */
/* @0x104ec0 str r0, [sp, #0x24] */
/* @0x104ec4 strd r4, r5, [r6, #-16]! */
/* @0x104ec8 mov r1, r7 */
/* @0x104ecc ldr r3, [r3, #0x4] */
/* @0x104ed0 mov r2, r6 */
/* @0x104ed4 ldr r0, [r3, r9, lsl #2] */
/* @0x104ed8 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x104edc ldr r3, [sp, #0x24] */
/* @0x104ee0 sub r3, r3, #1 */
/* @0x104ee4 bic r3, r3, #-16777216 */
/* @0x104ee8 bic r3, r3, #3 */
/* @0x104eec cmp r3, #0 */
/* @0x104ef0 mov r4, r0 */
/* @0x104ef4 beq 0x104f54 <_Z19F_DsMapAdd_InternaliPcxb+0xd8> */
/* @0x104ef8 ldr r1, [sp, #0x14] */
/* @0x104efc mov r3, #0 */
/* @0x104f00 str r3, [sp, #0x20] */
/* @0x104f04 mov r2, #5 */
/* @0x104f08 sub r1, r1, #1 */
/* @0x104f0c str r3, [sp, #0x18] */
/* @0x104f10 bic r3, r1, #-16777216 */
/* @0x104f14 str r2, [sp, #0x24] */
/* @0x104f18 bic r3, r3, #3 */
/* @0x104f1c cmp r3, #0 */
/* @0x104f20 bne 0x104f2c <_Z19F_DsMapAdd_InternaliPcxb+0xb0> */
/* @0x104f24 mov r0, r7 */
/* @0x104f28 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104f2c mov r0, r8 */
/* @0x104f30 mov r3, #0 */
/* @0x104f34 mov r2, #5 */
/* @0x104f38 str r3, [sp, #0x10] */
/* @0x104f3c str r3, [sp, #0x8] */
/* @0x104f40 str r2, [sp, #0x14] */
/* @0x104f44 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x104f48 mov r0, r4 */
/* @0x104f4c add sp, sp, #44 */
/* @0x104f50 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x104f54 mov r0, r6 */
/* @0x104f58 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x104f5c b 0x104ef8 <_Z19F_DsMapAdd_InternaliPcxb+0x7c> */
/* @0x104f60 eoreq r8, lr, r0, lsl #21 */

/* ── FUNC 0x104f64 · F_DsMapAdd_Internal(int, char*, char*) · size=228 · insn=57 */
/* @0x104f64 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x104f68 sub sp, sp, #44 */
/* @0x104f6c add r6, sp, #4 */
/* @0x104f70 add r4, sp, #8 */
/* @0x104f74 mov r7, r0 */
/* @0x104f78 mov r9, r1 */
/* @0x104f7c add r5, sp, #24 */
/* @0x104f80 mov r0, r6 */
/* @0x104f84 mov r8, r2 */
/* @0x104f88 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x104f8c mov r1, r9 */
/* @0x104f90 mov r0, r4 */
/* @0x104f94 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x104f98 mov r1, r8 */
/* @0x104f9c mov r0, r5 */
/* @0x104fa0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x104fa4 ldr r3, [pc, #0x98] */
/* @0x104fa8 mov r1, r4 */
/* @0x104fac mov r2, r5 */
/* @0x104fb0 ldr r3, [pc, r3] */
/* @0x104fb4 ldr r3, [r3, #0x4] */
/* @0x104fb8 ldr r0, [r3, r7, lsl #2] */
/* @0x104fbc bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x104fc0 ldr r3, [sp, #0x24] */
/* @0x104fc4 sub r3, r3, #1 */
/* @0x104fc8 bic r3, r3, #-16777216 */
/* @0x104fcc bic r3, r3, #3 */
/* @0x104fd0 cmp r3, #0 */
/* @0x104fd4 mov r7, r0 */
/* @0x104fd8 beq 0x105038 <_Z19F_DsMapAdd_InternaliPcS_+0xd4> */
/* @0x104fdc ldr r1, [sp, #0x14] */
/* @0x104fe0 mov r3, #0 */
/* @0x104fe4 str r3, [sp, #0x20] */
/* @0x104fe8 mov r2, #5 */
/* @0x104fec sub r1, r1, #1 */
/* @0x104ff0 str r3, [sp, #0x18] */
/* @0x104ff4 bic r3, r1, #-16777216 */
/* @0x104ff8 str r2, [sp, #0x24] */
/* @0x104ffc bic r3, r3, #3 */
/* @0x105000 cmp r3, #0 */
/* @0x105004 bne 0x105010 <_Z19F_DsMapAdd_InternaliPcS_+0xac> */
/* @0x105008 mov r0, r4 */
/* @0x10500c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105010 mov r0, r6 */
/* @0x105014 mov r3, #0 */
/* @0x105018 mov r2, #5 */
/* @0x10501c str r3, [sp, #0x10] */
/* @0x105020 str r3, [sp, #0x8] */
/* @0x105024 str r2, [sp, #0x14] */
/* @0x105028 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x10502c mov r0, r7 */
/* @0x105030 add sp, sp, #44 */
/* @0x105034 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x105038 mov r0, r5 */
/* @0x10503c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105040 b 0x104fdc <_Z19F_DsMapAdd_InternaliPcS_+0x78> */
/* @0x105044 eoreq r8, lr, r12, lsl #19 */

/* ── FUNC 0x105048 · F_DsMapAdd_Internal(int, double, char*) · size=232 · insn=58 */
/* @0x105048 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x10504c sub sp, sp, #44 */
/* @0x105050 add r7, sp, #4 */
/* @0x105054 add r6, sp, #24 */
/* @0x105058 ldr r8, [sp, #0x48] */
/* @0x10505c mov r9, r0 */
/* @0x105060 mov r0, r7 */
/* @0x105064 mov r4, r2 */
/* @0x105068 mov r5, r3 */
/* @0x10506c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x105070 mov r1, r8 */
/* @0x105074 mov r0, r6 */
/* @0x105078 strd r4, r5, [sp, #8] */
/* @0x10507c mov r3, #0 */
/* @0x105080 str r3, [sp, #0x14] */
/* @0x105084 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x105088 ldr r3, [pc, #0x9c] */
/* @0x10508c add r4, sp, #8 */
/* @0x105090 mov r2, r6 */
/* @0x105094 ldr r3, [pc, r3] */
/* @0x105098 mov r1, r4 */
/* @0x10509c ldr r3, [r3, #0x4] */
/* @0x1050a0 ldr r0, [r3, r9, lsl #2] */
/* @0x1050a4 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x1050a8 ldr r3, [sp, #0x24] */
/* @0x1050ac sub r3, r3, #1 */
/* @0x1050b0 bic r3, r3, #-16777216 */
/* @0x1050b4 bic r3, r3, #3 */
/* @0x1050b8 cmp r3, #0 */
/* @0x1050bc mov r5, r0 */
/* @0x1050c0 beq 0x105120 <_Z19F_DsMapAdd_InternalidPc+0xd8> */
/* @0x1050c4 ldr r1, [sp, #0x14] */
/* @0x1050c8 mov r3, #0 */
/* @0x1050cc str r3, [sp, #0x20] */
/* @0x1050d0 mov r2, #5 */
/* @0x1050d4 sub r1, r1, #1 */
/* @0x1050d8 str r3, [sp, #0x18] */
/* @0x1050dc bic r3, r1, #-16777216 */
/* @0x1050e0 str r2, [sp, #0x24] */
/* @0x1050e4 bic r3, r3, #3 */
/* @0x1050e8 cmp r3, #0 */
/* @0x1050ec bne 0x1050f8 <_Z19F_DsMapAdd_InternalidPc+0xb0> */
/* @0x1050f0 mov r0, r4 */
/* @0x1050f4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1050f8 mov r0, r7 */
/* @0x1050fc mov r3, #0 */
/* @0x105100 mov r2, #5 */
/* @0x105104 str r3, [sp, #0x10] */
/* @0x105108 str r3, [sp, #0x8] */
/* @0x10510c str r2, [sp, #0x14] */
/* @0x105110 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x105114 mov r0, r5 */
/* @0x105118 add sp, sp, #44 */
/* @0x10511c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x105120 mov r0, r6 */
/* @0x105124 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105128 b 0x1050c4 <_Z19F_DsMapAdd_InternalidPc+0x7c> */
/* @0x10512c eoreq r8, lr, r8, lsr #17 */

/* ── FUNC 0x105130 · dsMapAddRValue · size=700 · insn=175 */
/* @0x105130 vmov s13, r0 */
/* @0x105134 mov r3, #0 */
/* @0x105138 push {r4, r5, r6, lr} */
/* @0x10513c vcvt.f64.s32 d7, s13 */
/* @0x105140 sub sp, sp, #72 */
/* @0x105144 mov r4, #0 */
/* @0x105148 add r0, sp, #40 */
/* @0x10514c mov r5, #0 */
/* @0x105150 str r3, [sp, #0x10] */
/* @0x105154 mov r6, r2 */
/* @0x105158 str r3, [sp, #0x20] */
/* @0x10515c mvn r2, #-16777216 */
/* @0x105160 str r3, [sp, #0x30] */
/* @0x105164 str r3, [sp, #0x40] */
/* @0x105168 str r3, [sp, #0x24] */
/* @0x10516c vstr d7, [sp, #24] */
/* @0x105170 str r2, [sp, #0x14] */
/* @0x105174 str r2, [sp, #0x34] */
/* @0x105178 str r2, [sp, #0x44] */
/* @0x10517c strd r4, r5, [sp, #8] */
/* @0x105180 strd r4, r5, [sp, #40] */
/* @0x105184 strd r4, r5, [sp, #56] */
/* @0x105188 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x10518c ldr r2, [sp, #0x44] */
/* @0x105190 bic r3, r2, #-16777216 */
/* @0x105194 cmp r3, #1 */
/* @0x105198 beq 0x105268 <dsMapAddRValue+0x138> */
/* @0x10519c cmp r3, #2 */
/* @0x1051a0 bne 0x1051b8 <dsMapAddRValue+0x88> */
/* @0x1051a4 sub r2, r2, #1 */
/* @0x1051a8 bic r2, r2, #-16777216 */
/* @0x1051ac bic r2, r2, #3 */
/* @0x1051b0 cmp r2, #0 */
/* @0x1051b4 beq 0x105350 <dsMapAddRValue+0x220> */
/* @0x1051b8 ldr r2, [r6, #0xc] */
/* @0x1051bc mov r0, #0 */
/* @0x1051c0 ldr r1, [r6, #0x8] */
/* @0x1051c4 bic r3, r2, #-16777216 */
/* @0x1051c8 str r0, [sp, #0x38] */
/* @0x1051cc str r2, [sp, #0x44] */
/* @0x1051d0 str r1, [sp, #0x40] */
/* @0x1051d4 cmp r3, #14 */
/* @0x1051d8 addls pc, pc, r3, lsl #2 */
/* @0x1051dc b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1051e0 b 0x1052a4 <dsMapAddRValue+0x174> */
/* @0x1051e4 b 0x1052b0 <dsMapAddRValue+0x180> */
/* @0x1051e8 b 0x1052c8 <dsMapAddRValue+0x198> */
/* @0x1051ec b 0x10521c <dsMapAddRValue+0xec> */
/* @0x1051f0 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1051f4 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1051f8 b 0x1052f8 <dsMapAddRValue+0x1c8> */
/* @0x1051fc b 0x10521c <dsMapAddRValue+0xec> */
/* @0x105200 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105204 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105208 b 0x105294 <dsMapAddRValue+0x164> */
/* @0x10520c b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105210 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105214 b 0x1052a4 <dsMapAddRValue+0x174> */
/* @0x105218 b 0x10521c <dsMapAddRValue+0xec> */
/* @0x10521c ldr r3, [r6] */
/* @0x105220 str r3, [sp, #0x38] */
/* @0x105224 mov r1, #0 */
/* @0x105228 add r3, sp, #24 */
/* @0x10522c mov r2, r1 */
/* @0x105230 str r3, [sp] */
/* @0x105234 add r0, sp, #8 */
/* @0x105238 mov r3, #3 */
/* @0x10523c bl 0xff014 <_Z10F_DsMapAddR6RValueP9CInstanceS2_iPS_> */
/* @0x105240 ldr r3, [sp, #0x44] */
/* @0x105244 sub r3, r3, #1 */
/* @0x105248 bic r3, r3, #-16777216 */
/* @0x10524c bic r3, r3, #3 */
/* @0x105250 cmp r3, #0 */
/* @0x105254 bne 0x105260 <dsMapAddRValue+0x130> */
/* @0x105258 add r0, sp, #56 */
/* @0x10525c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105260 add sp, sp, #72 */
/* @0x105264 pop {r4, r5, r6, pc} */
/* @0x105268 ldr r4, [sp, #0x38] */
/* @0x10526c cmp r4, #0 */
/* @0x105270 beq 0x1051b8 <dsMapAddRValue+0x88> */
/* @0x105274 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105278 ldr r5, [r4, #0x4] */
/* @0x10527c sub r5, r5, #1 */
/* @0x105280 str r5, [r4, #0x4] */
/* @0x105284 cmp r5, #0 */
/* @0x105288 beq 0x105318 <dsMapAddRValue+0x1e8> */
/* @0x10528c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105290 b 0x1051b8 <dsMapAddRValue+0x88> */
/* @0x105294 ldm r6, {r2, r3} */
/* @0x105298 str r2, [sp, #0x38] */
/* @0x10529c str r3, [sp, #0x3c] */
/* @0x1052a0 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1052a4 ldm r6, {r0, r1} */
/* @0x1052a8 strd r0, r1, [sp, #56] */
/* @0x1052ac b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1052b0 ldr r3, [r6] */
/* @0x1052b4 cmp r3, #0 */
/* @0x1052b8 ldrne r2, [r3, #0x4] */
/* @0x1052bc addne r2, r2, #1 */
/* @0x1052c0 strne r2, [r3, #0x4] */
/* @0x1052c4 b 0x105220 <dsMapAddRValue+0xf0> */
/* @0x1052c8 ldr r3, [r6] */
/* @0x1052cc cmp r3, #0 */
/* @0x1052d0 str r3, [sp, #0x38] */
/* @0x1052d4 beq 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1052d8 ldr r1, [r3, #0x8] */
/* @0x1052dc ldr r2, [r3] */
/* @0x1052e0 cmp r1, #0 */
/* @0x1052e4 add r2, r2, #1 */
/* @0x1052e8 str r2, [r3] */
/* @0x1052ec addeq r2, sp, #56 */
/* @0x1052f0 streq r2, [r3, #0x8] */
/* @0x1052f4 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x1052f8 ldr r3, [r6] */
/* @0x1052fc cmp r3, #0 */
/* @0x105300 str r3, [sp, #0x38] */
/* @0x105304 beq 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105308 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x10530c ldr r1, [r6] */
/* @0x105310 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x105314 b 0x105224 <dsMapAddRValue+0xf4> */
/* @0x105318 ldr r0, [r4] */
/* @0x10531c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105320 str r5, [r4] */
/* @0x105324 str r5, [r4, #0x8] */
/* @0x105328 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10532c ldr r5, [r4, #0x4] */
/* @0x105330 sub r5, r5, #1 */
/* @0x105334 str r5, [r4, #0x4] */
/* @0x105338 cmp r5, #0 */
/* @0x10533c beq 0x10535c <dsMapAddRValue+0x22c> */
/* @0x105340 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105344 mov r0, r4 */
/* @0x105348 bl 0x27d1d0 <_ZdlPv> */
/* @0x10534c b 0x10528c <dsMapAddRValue+0x15c> */
/* @0x105350 add r0, sp, #56 */
/* @0x105354 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105358 b 0x1051b8 <dsMapAddRValue+0x88> */
/* @0x10535c ldr r0, [r4] */
/* @0x105360 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105364 str r5, [r4] */
/* @0x105368 str r5, [r4, #0x8] */
/* @0x10536c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105370 ldr r5, [r4, #0x4] */
/* @0x105374 sub r5, r5, #1 */
/* @0x105378 str r5, [r4, #0x4] */
/* @0x10537c cmp r5, #0 */
/* @0x105380 beq 0x105394 <dsMapAddRValue+0x264> */
/* @0x105384 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105388 mov r0, r4 */
/* @0x10538c bl 0x27d1d0 <_ZdlPv> */
/* @0x105390 b 0x105340 <dsMapAddRValue+0x210> */
/* @0x105394 ldr r0, [r4] */
/* @0x105398 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10539c str r5, [r4] */
/* @0x1053a0 str r5, [r4, #0x8] */
/* @0x1053a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1053a8 ldr r5, [r4, #0x4] */
/* @0x1053ac sub r5, r5, #1 */
/* @0x1053b0 str r5, [r4, #0x4] */
/* @0x1053b4 cmp r5, #0 */
/* @0x1053b8 bne 0x1053dc <dsMapAddRValue+0x2ac> */
/* @0x1053bc ldr r0, [r4] */
/* @0x1053c0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1053c4 mov r0, r4 */
/* @0x1053c8 str r5, [r4] */
/* @0x1053cc str r5, [r4, #0x8] */
/* @0x1053d0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1053d4 mov r0, r4 */
/* @0x1053d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1053dc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1053e0 mov r0, r4 */
/* @0x1053e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1053e8 b 0x105384 <dsMapAddRValue+0x254> */

/* ── FUNC 0x1053ec · F_DsMapAdd_Internal(int, char*, RValue*) · size=588 · insn=147 */
/* @0x1053ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1053f0 sub sp, sp, #36 */
/* @0x1053f4 add r6, sp, #12 */
/* @0x1053f8 add r4, sp, #16 */
/* @0x1053fc mov r5, r0 */
/* @0x105400 mov r8, r1 */
/* @0x105404 mov r0, r6 */
/* @0x105408 mov r7, r2 */
/* @0x10540c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x105410 mov r1, r8 */
/* @0x105414 mov r0, r4 */
/* @0x105418 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x10541c ldr r3, [pc, #0x210] */
/* @0x105420 mov r2, r7 */
/* @0x105424 mov r1, r4 */
/* @0x105428 ldr r3, [pc, r3] */
/* @0x10542c ldr r3, [r3, #0x4] */
/* @0x105430 ldr r0, [r3, r5, lsl #2] */
/* @0x105434 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x105438 ldr r2, [sp, #0x1c] */
/* @0x10543c sub r3, r2, #1 */
/* @0x105440 bic r3, r3, #-16777216 */
/* @0x105444 bics r5, r3, #3 */
/* @0x105448 mov r7, r0 */
/* @0x10544c beq 0x105478 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x8c> */
/* @0x105450 mov r0, r6 */
/* @0x105454 mov r3, #0 */
/* @0x105458 mov r2, #5 */
/* @0x10545c str r3, [sp, #0x18] */
/* @0x105460 str r3, [sp, #0x10] */
/* @0x105464 str r2, [sp, #0x1c] */
/* @0x105468 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x10546c mov r0, r7 */
/* @0x105470 add sp, sp, #36 */
/* @0x105474 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x105478 bic r2, r2, #-16777216 */
/* @0x10547c cmp r2, #2 */
/* @0x105480 beq 0x1054e8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xfc> */
/* @0x105484 cmp r2, #3 */
/* @0x105488 beq 0x1054c0 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xd4> */
/* @0x10548c cmp r2, #1 */
/* @0x105490 bne 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x105494 ldr r4, [sp, #0x10] */
/* @0x105498 cmp r4, #0 */
/* @0x10549c beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1054a4 ldr r5, [r4, #0x4] */
/* @0x1054a8 sub r5, r5, #1 */
/* @0x1054ac str r5, [r4, #0x4] */
/* @0x1054b0 cmp r5, #0 */
/* @0x1054b4 beq 0x10558c <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1a0> */
/* @0x1054b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1054bc b 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054c0 ldr r3, [sp, #0x18] */
/* @0x1054c4 tst r3, #8 */
/* @0x1054c8 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054cc ldr r0, [sp, #0x10] */
/* @0x1054d0 cmp r0, #0 */
/* @0x1054d4 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054d8 ldr r3, [r0] */
/* @0x1054dc ldr r3, [r3, #0x4] */
/* @0x1054e0 blx r3 */
/* @0x1054e4 b 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054e8 ldr r9, [sp, #0x10] */
/* @0x1054ec cmp r9, #0 */
/* @0x1054f0 beq 0x105450 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x64> */
/* @0x1054f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1054f8 ldr r3, [r9] */
/* @0x1054fc ldr r2, [r9, #0x8] */
/* @0x105500 sub r3, r3, #1 */
/* @0x105504 str r3, [r9] */
/* @0x105508 cmp r2, r4 */
/* @0x10550c streq r5, [r9, #0x8] */
/* @0x105510 cmp r3, #0 */
/* @0x105514 bgt 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc> */
/* @0x105518 ldr r3, [r9, #0x10] */
/* @0x10551c cmp r3, #0 */
/* @0x105520 movgt r8, #0 */
/* @0x105524 movgt r10, #5 */
/* @0x105528 movgt r5, r8 */
/* @0x10552c ble 0x1055e8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1fc> */
/* @0x105530 ldr r3, [r9, #0x4] */
/* @0x105534 add r2, r3, r8, lsl #3 */
/* @0x105538 str r2, [sp, #0x4] */
/* @0x10553c ldr r11, [r3, r8, lsl #3] */
/* @0x105540 ldr r4, [r2, #0x4] */
/* @0x105544 add r11, r4, r11, lsl #4 */
/* @0x105548 cmp r4, r11 */
/* @0x10554c blo 0x105568 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x17c> */
/* @0x105550 b 0x105608 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x21c> */
/* @0x105554 str r5, [r4, #0x8] */
/* @0x105558 str r10, [r4, #0xc] */
/* @0x10555c str r5, [r4], #16 */
/* @0x105560 cmp r11, r4 */
/* @0x105564 bls 0x1055c4 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1d8> */
/* @0x105568 ldr r3, [r4, #0xc] */
/* @0x10556c sub r3, r3, #1 */
/* @0x105570 bic r3, r3, #-16777216 */
/* @0x105574 bic r3, r3, #3 */
/* @0x105578 cmp r3, #0 */
/* @0x10557c bne 0x105554 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x168> */
/* @0x105580 mov r0, r4 */
/* @0x105584 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105588 b 0x105554 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x168> */
/* @0x10558c ldr r0, [r4] */
/* @0x105590 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105594 str r5, [r4] */
/* @0x105598 str r5, [r4, #0x8] */
/* @0x10559c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1055a0 ldr r5, [r4, #0x4] */
/* @0x1055a4 sub r5, r5, #1 */
/* @0x1055a8 str r5, [r4, #0x4] */
/* @0x1055ac cmp r5, #0 */
/* @0x1055b0 beq 0x105610 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x224> */
/* @0x1055b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1055b8 mov r0, r4 */
/* @0x1055bc bl 0x27d1d0 <_ZdlPv> */
/* @0x1055c0 b 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc> */
/* @0x1055c4 ldr r3, [sp, #0x4] */
/* @0x1055c8 ldr r0, [r3, #0x4] */
/* @0x1055cc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1055d0 ldr r3, [r9, #0x10] */
/* @0x1055d4 add r8, r8, #1 */
/* @0x1055d8 ldr r2, [sp, #0x4] */
/* @0x1055dc cmp r8, r3 */
/* @0x1055e0 str r5, [r2, #0x4] */
/* @0x1055e4 blt 0x105530 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x144> */
/* @0x1055e8 ldr r0, [r9, #0x4] */
/* @0x1055ec mov r4, #0 */
/* @0x1055f0 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x1055f4 str r4, [r9, #0x4] */
/* @0x1055f8 mov r0, r9 */
/* @0x1055fc bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x105600 str r4, [sp, #0x10] */
/* @0x105604 b 0x1054b8 <_Z19F_DsMapAdd_InternaliPcP6RValue+0xcc> */
/* @0x105608 mov r0, r4 */
/* @0x10560c b 0x1055cc <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1e0> */
/* @0x105610 ldr r0, [r4] */
/* @0x105614 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105618 mov r0, r4 */
/* @0x10561c str r5, [r4] */
/* @0x105620 str r5, [r4, #0x8] */
/* @0x105624 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x105628 mov r0, r4 */
/* @0x10562c bl 0x27d1d0 <_ZdlPv> */
/* @0x105630 b 0x1055b4 <_Z19F_DsMapAdd_InternaliPcP6RValue+0x1c8> */
/* @0x105634 eoreq r8, lr, r4, lsl r5 */

/* ── FUNC 0x105638 · F_DsMapAdd_Internal(int, double, double) · size=660 · insn=165 */
/* @0x105638 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x10563c sub sp, sp, #52 */
/* @0x105640 add r8, sp, #12 */
/* @0x105644 mov r11, r0 */
/* @0x105648 mov r4, r2 */
/* @0x10564c mov r5, r3 */
/* @0x105650 mov r0, r8 */
/* @0x105654 ldrd r6, r7, [sp, #88] */
/* @0x105658 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x10565c ldr r3, [pc, #0x264] */
/* @0x105660 add r10, sp, #16 */
/* @0x105664 add r9, sp, #32 */
/* @0x105668 ldr r3, [pc, r3] */
/* @0x10566c strd r6, r7, [sp, #32] */
/* @0x105670 strd r4, r5, [sp, #16] */
/* @0x105674 mov r1, r10 */
/* @0x105678 ldr r0, [r3, #0x4] */
/* @0x10567c mov r2, r9 */
/* @0x105680 mov r3, #0 */
/* @0x105684 str r3, [sp, #0x1c] */
/* @0x105688 str r3, [sp, #0x2c] */
/* @0x10568c ldr r0, [r0, r11, lsl #2] */
/* @0x105690 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_> */
/* @0x105694 ldr r3, [sp, #0x2c] */
/* @0x105698 sub r3, r3, #1 */
/* @0x10569c bic r3, r3, #-16777216 */
/* @0x1056a0 bic r3, r3, #3 */
/* @0x1056a4 cmp r3, #0 */
/* @0x1056a8 mov r6, r0 */
/* @0x1056ac beq 0x105748 <_Z19F_DsMapAdd_Internalidd+0x110> */
/* @0x1056b0 ldr r1, [sp, #0x1c] */
/* @0x1056b4 mov r2, #0 */
/* @0x1056b8 mov r0, #5 */
/* @0x1056bc str r2, [sp, #0x28] */
/* @0x1056c0 sub r3, r1, #1 */
/* @0x1056c4 str r2, [sp, #0x20] */
/* @0x1056c8 bic r3, r3, #-16777216 */
/* @0x1056cc str r0, [sp, #0x2c] */
/* @0x1056d0 bics r4, r3, #3 */
/* @0x1056d4 beq 0x105700 <_Z19F_DsMapAdd_Internalidd+0xc8> */
/* @0x1056d8 mov r0, r8 */
/* @0x1056dc mov r3, #0 */
/* @0x1056e0 mov r2, #5 */
/* @0x1056e4 str r3, [sp, #0x18] */
/* @0x1056e8 str r3, [sp, #0x10] */
/* @0x1056ec str r2, [sp, #0x1c] */
/* @0x1056f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1056f4 mov r0, r6 */
/* @0x1056f8 add sp, sp, #52 */
/* @0x1056fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x105700 bic r1, r1, #-16777216 */
/* @0x105704 cmp r1, #2 */
/* @0x105708 beq 0x10577c <_Z19F_DsMapAdd_Internalidd+0x144> */
/* @0x10570c cmp r1, #3 */
/* @0x105710 beq 0x105754 <_Z19F_DsMapAdd_Internalidd+0x11c> */
/* @0x105714 cmp r1, #1 */
/* @0x105718 bne 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x10571c ldr r4, [sp, #0x10] */
/* @0x105720 cmp r4, #0 */
/* @0x105724 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x105728 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10572c ldr r5, [r4, #0x4] */
/* @0x105730 sub r5, r5, #1 */
/* @0x105734 str r5, [r4, #0x4] */
/* @0x105738 cmp r5, #0 */
/* @0x10573c beq 0x105820 <_Z19F_DsMapAdd_Internalidd+0x1e8> */
/* @0x105740 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105744 b 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x105748 mov r0, r9 */
/* @0x10574c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105750 b 0x1056b0 <_Z19F_DsMapAdd_Internalidd+0x78> */
/* @0x105754 ldr r3, [sp, #0x18] */
/* @0x105758 tst r3, #8 */
/* @0x10575c beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x105760 ldr r0, [sp, #0x10] */
/* @0x105764 cmp r0, #0 */
/* @0x105768 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x10576c ldr r3, [r0] */
/* @0x105770 ldr r3, [r3, #0x4] */
/* @0x105774 blx r3 */
/* @0x105778 b 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x10577c ldr r9, [sp, #0x10] */
/* @0x105780 cmp r9, #0 */
/* @0x105784 beq 0x1056d8 <_Z19F_DsMapAdd_Internalidd+0xa0> */
/* @0x105788 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10578c ldr r3, [r9] */
/* @0x105790 ldr r2, [r9, #0x8] */
/* @0x105794 sub r3, r3, #1 */
/* @0x105798 str r3, [r9] */
/* @0x10579c cmp r2, r10 */
/* @0x1057a0 streq r4, [r9, #0x8] */
/* @0x1057a4 cmp r3, #0 */
/* @0x1057a8 bgt 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108> */
/* @0x1057ac ldr r3, [r9, #0x10] */
/* @0x1057b0 cmp r3, #0 */
/* @0x1057b4 movgt r7, #0 */
/* @0x1057b8 movgt r10, #5 */
/* @0x1057bc movgt r5, r7 */
/* @0x1057c0 ble 0x10587c <_Z19F_DsMapAdd_Internalidd+0x244> */
/* @0x1057c4 ldr r3, [r9, #0x4] */
/* @0x1057c8 add r2, r3, r7, lsl #3 */
/* @0x1057cc str r2, [sp, #0x4] */
/* @0x1057d0 ldr r11, [r3, r7, lsl #3] */
/* @0x1057d4 ldr r4, [r2, #0x4] */
/* @0x1057d8 add r11, r4, r11, lsl #4 */
/* @0x1057dc cmp r4, r11 */
/* @0x1057e0 blo 0x1057fc <_Z19F_DsMapAdd_Internalidd+0x1c4> */
/* @0x1057e4 b 0x10589c <_Z19F_DsMapAdd_Internalidd+0x264> */
/* @0x1057e8 str r5, [r4, #0x8] */
/* @0x1057ec str r10, [r4, #0xc] */
/* @0x1057f0 str r5, [r4], #16 */
/* @0x1057f4 cmp r11, r4 */
/* @0x1057f8 bls 0x105858 <_Z19F_DsMapAdd_Internalidd+0x220> */
/* @0x1057fc ldr r3, [r4, #0xc] */
/* @0x105800 sub r3, r3, #1 */
/* @0x105804 bic r3, r3, #-16777216 */
/* @0x105808 bic r3, r3, #3 */
/* @0x10580c cmp r3, #0 */
/* @0x105810 bne 0x1057e8 <_Z19F_DsMapAdd_Internalidd+0x1b0> */
/* @0x105814 mov r0, r4 */
/* @0x105818 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10581c b 0x1057e8 <_Z19F_DsMapAdd_Internalidd+0x1b0> */
/* @0x105820 ldr r0, [r4] */
/* @0x105824 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105828 str r5, [r4] */
/* @0x10582c str r5, [r4, #0x8] */
/* @0x105830 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105834 ldr r5, [r4, #0x4] */
/* @0x105838 sub r5, r5, #1 */
/* @0x10583c str r5, [r4, #0x4] */
/* @0x105840 cmp r5, #0 */
/* @0x105844 beq 0x1058a4 <_Z19F_DsMapAdd_Internalidd+0x26c> */
/* @0x105848 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10584c mov r0, r4 */
/* @0x105850 bl 0x27d1d0 <_ZdlPv> */
/* @0x105854 b 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108> */
/* @0x105858 ldr r3, [sp, #0x4] */
/* @0x10585c ldr r0, [r3, #0x4] */
/* @0x105860 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x105864 ldr r3, [r9, #0x10] */
/* @0x105868 add r7, r7, #1 */
/* @0x10586c ldr r2, [sp, #0x4] */
/* @0x105870 cmp r7, r3 */
/* @0x105874 str r5, [r2, #0x4] */
/* @0x105878 blt 0x1057c4 <_Z19F_DsMapAdd_Internalidd+0x18c> */
/* @0x10587c ldr r0, [r9, #0x4] */
/* @0x105880 mov r4, #0 */
/* @0x105884 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x105888 str r4, [r9, #0x4] */
/* @0x10588c mov r0, r9 */
/* @0x105890 bl 0xdc414 <_Z9YYStrFreePKc> */
/* @0x105894 str r4, [sp, #0x10] */
/* @0x105898 b 0x105740 <_Z19F_DsMapAdd_Internalidd+0x108> */
/* @0x10589c mov r0, r4 */
/* @0x1058a0 b 0x105860 <_Z19F_DsMapAdd_Internalidd+0x228> */
/* @0x1058a4 ldr r0, [r4] */
/* @0x1058a8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1058ac mov r0, r4 */
/* @0x1058b0 str r5, [r4] */
/* @0x1058b4 str r5, [r4, #0x8] */
/* @0x1058b8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1058bc mov r0, r4 */
/* @0x1058c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1058c4 b 0x105848 <_Z19F_DsMapAdd_Internalidd+0x210> */
/* @0x1058c8 .word 0x002e82d4 */

/* ── FUNC 0x1058cc · F_DsGridGet_release(RValue&, CInstance*, CInstance*, int, RValue*) · size=648 · insn=162 */
/* @0x1058cc push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1058d0 mov r1, #0 */
/* @0x1058d4 ldr r5, [sp, #0x20] */
/* @0x1058d8 mov r4, r0 */
/* @0x1058dc mov r0, r5 */
/* @0x1058e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1058e4 mov r1, #1 */
/* @0x1058e8 mov r6, r0 */
/* @0x1058ec mov r0, r5 */
/* @0x1058f0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1058f4 mov r1, #2 */
/* @0x1058f8 mov r7, r0 */
/* @0x1058fc mov r0, r5 */
/* @0x105900 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x105904 ldr r3, [pc, #0x244] */
/* @0x105908 ldr r1, [r4, #0xc] */
/* @0x10590c ldr r3, [pc, r3] */
/* @0x105910 bic r2, r1, #-16777216 */
/* @0x105914 ldr r3, [r3, #0x4] */
/* @0x105918 cmp r2, #1 */
/* @0x10591c ldr r3, [r3, r6, lsl #2] */
/* @0x105920 ldm r3, {r6, r12} */
/* @0x105924 mla r7, r12, r0, r7 */
/* @0x105928 add r5, r6, r7, lsl #4 */
/* @0x10592c beq 0x1059e0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x114> */
/* @0x105930 cmp r2, #2 */
/* @0x105934 bne 0x10595c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x105938 sub r1, r1, #1 */
/* @0x10593c bic r1, r1, #-16777216 */
/* @0x105940 bic r1, r1, #3 */
/* @0x105944 cmp r1, #0 */
/* @0x105948 beq 0x105ab4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1e8> */
/* @0x10594c mov r2, #0 */
/* @0x105950 mov r3, #5 */
/* @0x105954 str r2, [r4, #0x8] */
/* @0x105958 str r3, [r4, #0xc] */
/* @0x10595c ldr r3, [r5, #0xc] */
/* @0x105960 mov r1, #0 */
/* @0x105964 ldr r2, [r5, #0x8] */
/* @0x105968 str r1, [r4] */
/* @0x10596c str r3, [r4, #0xc] */
/* @0x105970 ldr r3, [r5, #0xc] */
/* @0x105974 str r2, [r4, #0x8] */
/* @0x105978 bic r3, r3, #-16777216 */
/* @0x10597c cmp r3, #14 */
/* @0x105980 addls pc, pc, r3, lsl #2 */
/* @0x105984 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x105988 b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x10598c b 0x105a38 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x105990 b 0x105a50 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x105994 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x105998 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x10599c b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1059a0 b 0x105a14 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x1059a4 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1059a8 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1059ac b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1059b0 b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1059b4 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1059b8 b 0x1059cc <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x1059bc b 0x1059d0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x104> */
/* @0x1059c0 b 0x1059c4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xf8> */
/* @0x1059c4 ldr r3, [r6, r7, lsl #4] */
/* @0x1059c8 str r3, [r4] */
/* @0x1059cc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1059d0 ldr r2, [r6, r7, lsl #4] */
/* @0x1059d4 ldr r3, [r5, #0x4] */
/* @0x1059d8 stm r4, {r2, r3} */
/* @0x1059dc pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1059e0 ldr r8, [r4] */
/* @0x1059e4 cmp r8, #0 */
/* @0x1059e8 beq 0x105a08 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1059ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1059f0 ldr r9, [r8, #0x4] */
/* @0x1059f4 sub r9, r9, #1 */
/* @0x1059f8 str r9, [r8, #0x4] */
/* @0x1059fc cmp r9, #0 */
/* @0x105a00 beq 0x105a7c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x105a04 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105a08 mov r3, #0 */
/* @0x105a0c str r3, [r4] */
/* @0x105a10 b 0x10595c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x105a14 ldr r3, [r6, r7, lsl #4] */
/* @0x105a18 str r3, [r4] */
/* @0x105a1c ldr r3, [r6, r7, lsl #4] */
/* @0x105a20 cmp r3, #0 */
/* @0x105a24 popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x105a28 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x105a2c ldr r1, [r6, r7, lsl #4] */
/* @0x105a30 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x105a34 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x105a38 ldr r3, [r6, r7, lsl #4] */
/* @0x105a3c cmp r3, #0 */
/* @0x105a40 ldrne r2, [r3, #0x4] */
/* @0x105a44 addne r2, r2, #1 */
/* @0x105a48 strne r2, [r3, #0x4] */
/* @0x105a4c b 0x1059c8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x105a50 ldr r3, [r6, r7, lsl #4] */
/* @0x105a54 cmp r3, #0 */
/* @0x105a58 str r3, [r4] */
/* @0x105a5c popeq {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x105a60 ldr r1, [r3, #0x8] */
/* @0x105a64 ldr r2, [r3] */
/* @0x105a68 cmp r1, #0 */
/* @0x105a6c streq r4, [r3, #0x8] */
/* @0x105a70 add r2, r2, #1 */
/* @0x105a74 str r2, [r3] */
/* @0x105a78 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x105a7c ldr r0, [r8] */
/* @0x105a80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105a84 str r9, [r8] */
/* @0x105a88 str r9, [r8, #0x8] */
/* @0x105a8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105a90 ldr r9, [r8, #0x4] */
/* @0x105a94 sub r9, r9, #1 */
/* @0x105a98 str r9, [r8, #0x4] */
/* @0x105a9c cmp r9, #0 */
/* @0x105aa0 beq 0x105ac0 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1f4> */
/* @0x105aa4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105aa8 mov r0, r8 */
/* @0x105aac bl 0x27d1d0 <_ZdlPv> */
/* @0x105ab0 b 0x105a04 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x105ab4 mov r0, r4 */
/* @0x105ab8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105abc b 0x10594c <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x80> */
/* @0x105ac0 ldr r0, [r8] */
/* @0x105ac4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105ac8 str r9, [r8] */
/* @0x105acc str r9, [r8, #0x8] */
/* @0x105ad0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105ad4 ldr r9, [r8, #0x4] */
/* @0x105ad8 sub r9, r9, #1 */
/* @0x105adc str r9, [r8, #0x4] */
/* @0x105ae0 cmp r9, #0 */
/* @0x105ae4 beq 0x105af8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x105ae8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105aec mov r0, r8 */
/* @0x105af0 bl 0x27d1d0 <_ZdlPv> */
/* @0x105af4 b 0x105aa4 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x105af8 ldr r0, [r8] */
/* @0x105afc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105b00 str r9, [r8] */
/* @0x105b04 str r9, [r8, #0x8] */
/* @0x105b08 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105b0c ldr r9, [r8, #0x4] */
/* @0x105b10 sub r9, r9, #1 */
/* @0x105b14 str r9, [r8, #0x4] */
/* @0x105b18 cmp r9, #0 */
/* @0x105b1c bne 0x105b40 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x105b20 ldr r0, [r8] */
/* @0x105b24 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105b28 mov r0, r8 */
/* @0x105b2c str r9, [r8] */
/* @0x105b30 str r9, [r8, #0x8] */
/* @0x105b34 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x105b38 mov r0, r8 */
/* @0x105b3c bl 0x27d1d0 <_ZdlPv> */
/* @0x105b40 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105b44 mov r0, r8 */
/* @0x105b48 bl 0x27d1d0 <_ZdlPv> */
/* @0x105b4c b 0x105ae8 <_Z19F_DsGridGet_releaseR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x105b50 eoreq r8, lr, r12, ror r5 */

/* ── FUNC 0x105b54 · F_DsQueueTail(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x105b54 push {r3, r4, r5, r6, r7, lr} */
/* @0x105b58 mov r1, #0 */
/* @0x105b5c mov r4, r0 */
/* @0x105b60 ldr r0, [sp, #0x18] */
/* @0x105b64 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x105b68 cmp r0, #0 */
/* @0x105b6c blt 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105b70 ldr r3, [pc, #0x288] */
/* @0x105b74 ldr r3, [pc, r3] */
/* @0x105b78 ldr r3, [r3] */
/* @0x105b7c cmp r0, r3 */
/* @0x105b80 bge 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105b84 ldr r3, [pc, #0x278] */
/* @0x105b88 ldr r3, [pc, r3] */
/* @0x105b8c ldr r3, [r3, #0x4] */
/* @0x105b90 ldr r0, [r3, r0, lsl #2] */
/* @0x105b94 cmp r0, #0 */
/* @0x105b98 beq 0x105c5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105b9c bl 0x202fc0 <_ZN9CDS_Queue4TailEv> */
/* @0x105ba0 subs r5, r0, #0 */
/* @0x105ba4 streq r5, [r4] */
/* @0x105ba8 streq r5, [r4, #0x4] */
/* @0x105bac moveq r3, #5 */
/* @0x105bb0 streq r3, [r4, #0xc] */
/* @0x105bb4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105bb8 ldr r2, [r4, #0xc] */
/* @0x105bbc bic r3, r2, #-16777216 */
/* @0x105bc0 cmp r3, #1 */
/* @0x105bc4 beq 0x105c88 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x105bc8 cmp r3, #2 */
/* @0x105bcc bne 0x105bf4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x105bd0 sub r2, r2, #1 */
/* @0x105bd4 bic r2, r2, #-16777216 */
/* @0x105bd8 bic r2, r2, #3 */
/* @0x105bdc cmp r2, #0 */
/* @0x105be0 beq 0x105d5c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x105be4 mov r2, #0 */
/* @0x105be8 mov r3, #5 */
/* @0x105bec str r2, [r4, #0x8] */
/* @0x105bf0 str r3, [r4, #0xc] */
/* @0x105bf4 ldr r3, [r5, #0xc] */
/* @0x105bf8 mov r1, #0 */
/* @0x105bfc ldr r2, [r5, #0x8] */
/* @0x105c00 str r1, [r4] */
/* @0x105c04 str r3, [r4, #0xc] */
/* @0x105c08 ldr r3, [r5, #0xc] */
/* @0x105c0c str r2, [r4, #0x8] */
/* @0x105c10 bic r3, r3, #-16777216 */
/* @0x105c14 cmp r3, #14 */
/* @0x105c18 addls pc, pc, r3, lsl #2 */
/* @0x105c1c b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c20 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105c24 b 0x105ce0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x105c28 b 0x105cf8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x105c2c b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105c30 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c34 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c38 b 0x105cbc <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x105c3c b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105c40 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c44 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c48 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105c4c b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c50 b 0x105c78 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105c54 b 0x105c7c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105c58 b 0x105c70 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105c5c ldr r0, [pc, #0x1a4] */
/* @0x105c60 mov r1, #0 */
/* @0x105c64 pop {r3, r4, r5, r6, r7, lr} */
/* @0x105c68 add r0, pc, r0 */
/* @0x105c6c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x105c70 ldr r3, [r5] */
/* @0x105c74 str r3, [r4] */
/* @0x105c78 pop {r3, r4, r5, r6, r7, pc} */
/* @0x105c7c ldm r5, {r2, r3} */
/* @0x105c80 stm r4, {r2, r3} */
/* @0x105c84 pop {r3, r4, r5, r6, r7, pc} */
/* @0x105c88 ldr r6, [r4] */
/* @0x105c8c cmp r6, #0 */
/* @0x105c90 beq 0x105cb0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x105c94 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105c98 ldr r7, [r6, #0x4] */
/* @0x105c9c sub r7, r7, #1 */
/* @0x105ca0 str r7, [r6, #0x4] */
/* @0x105ca4 cmp r7, #0 */
/* @0x105ca8 beq 0x105d24 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x105cac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105cb0 mov r3, #0 */
/* @0x105cb4 str r3, [r4] */
/* @0x105cb8 b 0x105bf4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x105cbc ldr r3, [r5] */
/* @0x105cc0 str r3, [r4] */
/* @0x105cc4 ldr r3, [r5] */
/* @0x105cc8 cmp r3, #0 */
/* @0x105ccc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105cd0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x105cd4 ldr r1, [r5] */
/* @0x105cd8 pop {r3, r4, r5, r6, r7, lr} */
/* @0x105cdc b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x105ce0 ldr r3, [r5] */
/* @0x105ce4 cmp r3, #0 */
/* @0x105ce8 ldrne r2, [r3, #0x4] */
/* @0x105cec addne r2, r2, #1 */
/* @0x105cf0 strne r2, [r3, #0x4] */
/* @0x105cf4 b 0x105c74 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x105cf8 ldr r3, [r5] */
/* @0x105cfc cmp r3, #0 */
/* @0x105d00 str r3, [r4] */
/* @0x105d04 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105d08 ldr r1, [r3, #0x8] */
/* @0x105d0c ldr r2, [r3] */
/* @0x105d10 cmp r1, #0 */
/* @0x105d14 streq r4, [r3, #0x8] */
/* @0x105d18 add r2, r2, #1 */
/* @0x105d1c str r2, [r3] */
/* @0x105d20 pop {r3, r4, r5, r6, r7, pc} */
/* @0x105d24 ldr r0, [r6] */
/* @0x105d28 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105d2c str r7, [r6] */
/* @0x105d30 str r7, [r6, #0x8] */
/* @0x105d34 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105d38 ldr r7, [r6, #0x4] */
/* @0x105d3c sub r7, r7, #1 */
/* @0x105d40 str r7, [r6, #0x4] */
/* @0x105d44 cmp r7, #0 */
/* @0x105d48 beq 0x105d68 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x105d4c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105d50 mov r0, r6 */
/* @0x105d54 bl 0x27d1d0 <_ZdlPv> */
/* @0x105d58 b 0x105cac <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x105d5c mov r0, r4 */
/* @0x105d60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x105d64 b 0x105be4 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x105d68 ldr r0, [r6] */
/* @0x105d6c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105d70 str r7, [r6] */
/* @0x105d74 str r7, [r6, #0x8] */
/* @0x105d78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105d7c ldr r7, [r6, #0x4] */
/* @0x105d80 sub r7, r7, #1 */
/* @0x105d84 str r7, [r6, #0x4] */
/* @0x105d88 cmp r7, #0 */
/* @0x105d8c beq 0x105da0 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x105d90 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105d94 mov r0, r6 */
/* @0x105d98 bl 0x27d1d0 <_ZdlPv> */
/* @0x105d9c b 0x105d4c <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x105da0 ldr r0, [r6] */
/* @0x105da4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105da8 str r7, [r6] */
/* @0x105dac str r7, [r6, #0x8] */
/* @0x105db0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105db4 ldr r3, [r6, #0x4] */
/* @0x105db8 sub r3, r3, #1 */
/* @0x105dbc str r3, [r6, #0x4] */
/* @0x105dc0 cmp r3, #0 */
/* @0x105dc4 beq 0x105dd8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x105dc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105dcc mov r0, r6 */
/* @0x105dd0 bl 0x27d1d0 <_ZdlPv> */
/* @0x105dd4 b 0x105d90 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x105dd8 ldr r0, [r6] */
/* @0x105ddc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105de0 mov r3, #0 */
/* @0x105de4 mov r0, r6 */
/* @0x105de8 str r3, [r6] */
/* @0x105dec str r3, [r6, #0x8] */
/* @0x105df0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x105df4 mov r0, r6 */
/* @0x105df8 bl 0x27d1d0 <_ZdlPv> */
/* @0x105dfc b 0x105dc8 <_Z13F_DsQueueTailR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x105e00 .word 0x002e82f8 */
/* @0x105e04 eoreq r8, lr, r8, ror #5 */
/* @0x105e08 mlaeq r3, r4, pc, r1 */
