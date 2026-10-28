/* libyoyo.so 覆盖卡组 0032
 * 函数 0x105e0c..0x10859c，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x105e0c · F_DsQueueHead(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x105e0c push {r3, r4, r5, r6, r7, lr} */
/* @0x105e10 mov r1, #0 */
/* @0x105e14 mov r4, r0 */
/* @0x105e18 ldr r0, [sp, #0x18] */
/* @0x105e1c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x105e20 cmp r0, #0 */
/* @0x105e24 blt 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105e28 ldr r3, [pc, #0x288] */
/* @0x105e2c ldr r3, [pc, r3] */
/* @0x105e30 ldr r3, [r3] */
/* @0x105e34 cmp r0, r3 */
/* @0x105e38 bge 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105e3c ldr r3, [pc, #0x278] */
/* @0x105e40 ldr r3, [pc, r3] */
/* @0x105e44 ldr r3, [r3, #0x4] */
/* @0x105e48 ldr r0, [r3, r0, lsl #2] */
/* @0x105e4c cmp r0, #0 */
/* @0x105e50 beq 0x105f14 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x105e54 bl 0x202fa8 <_ZN9CDS_Queue4HeadEv> */
/* @0x105e58 subs r5, r0, #0 */
/* @0x105e5c streq r5, [r4] */
/* @0x105e60 streq r5, [r4, #0x4] */
/* @0x105e64 moveq r3, #5 */
/* @0x105e68 streq r3, [r4, #0xc] */
/* @0x105e6c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105e70 ldr r2, [r4, #0xc] */
/* @0x105e74 bic r3, r2, #-16777216 */
/* @0x105e78 cmp r3, #1 */
/* @0x105e7c beq 0x105f40 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x105e80 cmp r3, #2 */
/* @0x105e84 bne 0x105eac <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x105e88 sub r2, r2, #1 */
/* @0x105e8c bic r2, r2, #-16777216 */
/* @0x105e90 bic r2, r2, #3 */
/* @0x105e94 cmp r2, #0 */
/* @0x105e98 beq 0x106014 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x105e9c mov r2, #0 */
/* @0x105ea0 mov r3, #5 */
/* @0x105ea4 str r2, [r4, #0x8] */
/* @0x105ea8 str r3, [r4, #0xc] */
/* @0x105eac ldr r3, [r5, #0xc] */
/* @0x105eb0 mov r1, #0 */
/* @0x105eb4 ldr r2, [r5, #0x8] */
/* @0x105eb8 str r1, [r4] */
/* @0x105ebc str r3, [r4, #0xc] */
/* @0x105ec0 ldr r3, [r5, #0xc] */
/* @0x105ec4 str r2, [r4, #0x8] */
/* @0x105ec8 bic r3, r3, #-16777216 */
/* @0x105ecc cmp r3, #14 */
/* @0x105ed0 addls pc, pc, r3, lsl #2 */
/* @0x105ed4 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105ed8 b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105edc b 0x105f98 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x105ee0 b 0x105fb0 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x105ee4 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105ee8 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105eec b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105ef0 b 0x105f74 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x105ef4 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105ef8 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105efc b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105f00 b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105f04 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105f08 b 0x105f30 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x105f0c b 0x105f34 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x105f10 b 0x105f28 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x105f14 ldr r0, [pc, #0x1a4] */
/* @0x105f18 mov r1, #0 */
/* @0x105f1c pop {r3, r4, r5, r6, r7, lr} */
/* @0x105f20 add r0, pc, r0 */
/* @0x105f24 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x105f28 ldr r3, [r5] */
/* @0x105f2c str r3, [r4] */
/* @0x105f30 pop {r3, r4, r5, r6, r7, pc} */
/* @0x105f34 ldm r5, {r2, r3} */
/* @0x105f38 stm r4, {r2, r3} */
/* @0x105f3c pop {r3, r4, r5, r6, r7, pc} */
/* @0x105f40 ldr r6, [r4] */
/* @0x105f44 cmp r6, #0 */
/* @0x105f48 beq 0x105f68 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x105f4c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105f50 ldr r7, [r6, #0x4] */
/* @0x105f54 sub r7, r7, #1 */
/* @0x105f58 str r7, [r6, #0x4] */
/* @0x105f5c cmp r7, #0 */
/* @0x105f60 beq 0x105fdc <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x105f64 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x105f68 mov r3, #0 */
/* @0x105f6c str r3, [r4] */
/* @0x105f70 b 0x105eac <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x105f74 ldr r3, [r5] */
/* @0x105f78 str r3, [r4] */
/* @0x105f7c ldr r3, [r5] */
/* @0x105f80 cmp r3, #0 */
/* @0x105f84 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105f88 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x105f8c ldr r1, [r5] */
/* @0x105f90 pop {r3, r4, r5, r6, r7, lr} */
/* @0x105f94 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x105f98 ldr r3, [r5] */
/* @0x105f9c cmp r3, #0 */
/* @0x105fa0 ldrne r2, [r3, #0x4] */
/* @0x105fa4 addne r2, r2, #1 */
/* @0x105fa8 strne r2, [r3, #0x4] */
/* @0x105fac b 0x105f2c <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x105fb0 ldr r3, [r5] */
/* @0x105fb4 cmp r3, #0 */
/* @0x105fb8 str r3, [r4] */
/* @0x105fbc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x105fc0 ldr r1, [r3, #0x8] */
/* @0x105fc4 ldr r2, [r3] */
/* @0x105fc8 cmp r1, #0 */
/* @0x105fcc streq r4, [r3, #0x8] */
/* @0x105fd0 add r2, r2, #1 */
/* @0x105fd4 str r2, [r3] */
/* @0x105fd8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x105fdc ldr r0, [r6] */
/* @0x105fe0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x105fe4 str r7, [r6] */
/* @0x105fe8 str r7, [r6, #0x8] */
/* @0x105fec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x105ff0 ldr r7, [r6, #0x4] */
/* @0x105ff4 sub r7, r7, #1 */
/* @0x105ff8 str r7, [r6, #0x4] */
/* @0x105ffc cmp r7, #0 */
/* @0x106000 beq 0x106020 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x106004 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106008 mov r0, r6 */
/* @0x10600c bl 0x27d1d0 <_ZdlPv> */
/* @0x106010 b 0x105f64 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x106014 mov r0, r4 */
/* @0x106018 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10601c b 0x105e9c <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x106020 ldr r0, [r6] */
/* @0x106024 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106028 str r7, [r6] */
/* @0x10602c str r7, [r6, #0x8] */
/* @0x106030 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106034 ldr r7, [r6, #0x4] */
/* @0x106038 sub r7, r7, #1 */
/* @0x10603c str r7, [r6, #0x4] */
/* @0x106040 cmp r7, #0 */
/* @0x106044 beq 0x106058 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x106048 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10604c mov r0, r6 */
/* @0x106050 bl 0x27d1d0 <_ZdlPv> */
/* @0x106054 b 0x106004 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x106058 ldr r0, [r6] */
/* @0x10605c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106060 str r7, [r6] */
/* @0x106064 str r7, [r6, #0x8] */
/* @0x106068 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10606c ldr r3, [r6, #0x4] */
/* @0x106070 sub r3, r3, #1 */
/* @0x106074 str r3, [r6, #0x4] */
/* @0x106078 cmp r3, #0 */
/* @0x10607c beq 0x106090 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x106080 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106084 mov r0, r6 */
/* @0x106088 bl 0x27d1d0 <_ZdlPv> */
/* @0x10608c b 0x106048 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x106090 ldr r0, [r6] */
/* @0x106094 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106098 mov r3, #0 */
/* @0x10609c mov r0, r6 */
/* @0x1060a0 str r3, [r6] */
/* @0x1060a4 str r3, [r6, #0x8] */
/* @0x1060a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1060ac mov r0, r6 */
/* @0x1060b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1060b4 b 0x106080 <_Z13F_DsQueueHeadR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x1060b8 eoreq r8, lr, r0, asr #32 */
/* @0x1060bc eoreq r8, lr, r0, lsr r0 */
/* @0x1060c0 .word 0x00231cdc */

/* ── FUNC 0x1060c4 · F_DsPriorityFindMin(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x1060c4 push {r3, r4, r5, r6, r7, lr} */
/* @0x1060c8 mov r1, #0 */
/* @0x1060cc mov r4, r0 */
/* @0x1060d0 ldr r0, [sp, #0x18] */
/* @0x1060d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1060d8 cmp r0, #0 */
/* @0x1060dc blt 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1060e0 ldr r3, [pc, #0x288] */
/* @0x1060e4 ldr r3, [pc, r3] */
/* @0x1060e8 ldr r3, [r3] */
/* @0x1060ec cmp r0, r3 */
/* @0x1060f0 bge 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1060f4 ldr r3, [pc, #0x278] */
/* @0x1060f8 ldr r3, [pc, r3] */
/* @0x1060fc ldr r3, [r3, #0x4] */
/* @0x106100 ldr r0, [r3, r0, lsl #2] */
/* @0x106104 cmp r0, #0 */
/* @0x106108 beq 0x1061cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x10610c bl 0x204000 <_ZN12CDS_Priority7FindMinEv> */
/* @0x106110 subs r5, r0, #0 */
/* @0x106114 streq r5, [r4] */
/* @0x106118 streq r5, [r4, #0x4] */
/* @0x10611c moveq r3, #5 */
/* @0x106120 streq r3, [r4, #0xc] */
/* @0x106124 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106128 ldr r2, [r4, #0xc] */
/* @0x10612c bic r3, r2, #-16777216 */
/* @0x106130 cmp r3, #1 */
/* @0x106134 beq 0x1061f8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x106138 cmp r3, #2 */
/* @0x10613c bne 0x106164 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x106140 sub r2, r2, #1 */
/* @0x106144 bic r2, r2, #-16777216 */
/* @0x106148 bic r2, r2, #3 */
/* @0x10614c cmp r2, #0 */
/* @0x106150 beq 0x1062cc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x106154 mov r2, #0 */
/* @0x106158 mov r3, #5 */
/* @0x10615c str r2, [r4, #0x8] */
/* @0x106160 str r3, [r4, #0xc] */
/* @0x106164 ldr r3, [r5, #0xc] */
/* @0x106168 mov r1, #0 */
/* @0x10616c ldr r2, [r5, #0x8] */
/* @0x106170 str r1, [r4] */
/* @0x106174 str r3, [r4, #0xc] */
/* @0x106178 ldr r3, [r5, #0xc] */
/* @0x10617c str r2, [r4, #0x8] */
/* @0x106180 bic r3, r3, #-16777216 */
/* @0x106184 cmp r3, #14 */
/* @0x106188 addls pc, pc, r3, lsl #2 */
/* @0x10618c b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106190 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x106194 b 0x106250 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x106198 b 0x106268 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x10619c b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1061a0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061a4 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061a8 b 0x10622c <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1061ac b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1061b0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061b4 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061b8 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1061bc b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061c0 b 0x1061e8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1061c4 b 0x1061ec <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1061c8 b 0x1061e0 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1061cc ldr r0, [pc, #0x1a4] */
/* @0x1061d0 mov r1, #0 */
/* @0x1061d4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1061d8 add r0, pc, r0 */
/* @0x1061dc b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1061e0 ldr r3, [r5] */
/* @0x1061e4 str r3, [r4] */
/* @0x1061e8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1061ec ldm r5, {r2, r3} */
/* @0x1061f0 stm r4, {r2, r3} */
/* @0x1061f4 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1061f8 ldr r6, [r4] */
/* @0x1061fc cmp r6, #0 */
/* @0x106200 beq 0x106220 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106204 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106208 ldr r7, [r6, #0x4] */
/* @0x10620c sub r7, r7, #1 */
/* @0x106210 str r7, [r6, #0x4] */
/* @0x106214 cmp r7, #0 */
/* @0x106218 beq 0x106294 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x10621c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106220 mov r3, #0 */
/* @0x106224 str r3, [r4] */
/* @0x106228 b 0x106164 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x10622c ldr r3, [r5] */
/* @0x106230 str r3, [r4] */
/* @0x106234 ldr r3, [r5] */
/* @0x106238 cmp r3, #0 */
/* @0x10623c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106240 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x106244 ldr r1, [r5] */
/* @0x106248 pop {r3, r4, r5, r6, r7, lr} */
/* @0x10624c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x106250 ldr r3, [r5] */
/* @0x106254 cmp r3, #0 */
/* @0x106258 ldrne r2, [r3, #0x4] */
/* @0x10625c addne r2, r2, #1 */
/* @0x106260 strne r2, [r3, #0x4] */
/* @0x106264 b 0x1061e4 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106268 ldr r3, [r5] */
/* @0x10626c cmp r3, #0 */
/* @0x106270 str r3, [r4] */
/* @0x106274 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106278 ldr r1, [r3, #0x8] */
/* @0x10627c ldr r2, [r3] */
/* @0x106280 cmp r1, #0 */
/* @0x106284 streq r4, [r3, #0x8] */
/* @0x106288 add r2, r2, #1 */
/* @0x10628c str r2, [r3] */
/* @0x106290 pop {r3, r4, r5, r6, r7, pc} */
/* @0x106294 ldr r0, [r6] */
/* @0x106298 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x10629c str r7, [r6] */
/* @0x1062a0 str r7, [r6, #0x8] */
/* @0x1062a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1062a8 ldr r7, [r6, #0x4] */
/* @0x1062ac sub r7, r7, #1 */
/* @0x1062b0 str r7, [r6, #0x4] */
/* @0x1062b4 cmp r7, #0 */
/* @0x1062b8 beq 0x1062d8 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x1062bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1062c0 mov r0, r6 */
/* @0x1062c4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1062c8 b 0x10621c <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1062cc mov r0, r4 */
/* @0x1062d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1062d4 b 0x106154 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x1062d8 ldr r0, [r6] */
/* @0x1062dc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1062e0 str r7, [r6] */
/* @0x1062e4 str r7, [r6, #0x8] */
/* @0x1062e8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1062ec ldr r7, [r6, #0x4] */
/* @0x1062f0 sub r7, r7, #1 */
/* @0x1062f4 str r7, [r6, #0x4] */
/* @0x1062f8 cmp r7, #0 */
/* @0x1062fc beq 0x106310 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x106300 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106304 mov r0, r6 */
/* @0x106308 bl 0x27d1d0 <_ZdlPv> */
/* @0x10630c b 0x1062bc <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x106310 ldr r0, [r6] */
/* @0x106314 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106318 str r7, [r6] */
/* @0x10631c str r7, [r6, #0x8] */
/* @0x106320 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106324 ldr r3, [r6, #0x4] */
/* @0x106328 sub r3, r3, #1 */
/* @0x10632c str r3, [r6, #0x4] */
/* @0x106330 cmp r3, #0 */
/* @0x106334 beq 0x106348 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x106338 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10633c mov r0, r6 */
/* @0x106340 bl 0x27d1d0 <_ZdlPv> */
/* @0x106344 b 0x106300 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x106348 ldr r0, [r6] */
/* @0x10634c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106350 mov r3, #0 */
/* @0x106354 mov r0, r6 */
/* @0x106358 str r3, [r6] */
/* @0x10635c str r3, [r6, #0x8] */
/* @0x106360 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x106364 mov r0, r6 */
/* @0x106368 bl 0x27d1d0 <_ZdlPv> */
/* @0x10636c b 0x106338 <_Z19F_DsPriorityFindMinR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x106370 mlaeq lr, r0, sp, r7 */
/* @0x106374 eoreq r7, lr, r0, lsl #27 */
/* @0x106378 eoreq r1, r3, r4, lsr #20 */

/* ── FUNC 0x10637c · F_DsStackTop(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x10637c push {r3, r4, r5, r6, r7, lr} */
/* @0x106380 mov r1, #0 */
/* @0x106384 mov r4, r0 */
/* @0x106388 ldr r0, [sp, #0x18] */
/* @0x10638c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x106390 cmp r0, #0 */
/* @0x106394 blt 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x106398 ldr r3, [pc, #0x288] */
/* @0x10639c ldr r3, [pc, r3] */
/* @0x1063a0 ldr r3, [r3] */
/* @0x1063a4 cmp r0, r3 */
/* @0x1063a8 bge 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1063ac ldr r3, [pc, #0x278] */
/* @0x1063b0 ldr r3, [pc, r3] */
/* @0x1063b4 ldr r3, [r3, #0x4] */
/* @0x1063b8 ldr r0, [r3, r0, lsl #2] */
/* @0x1063bc cmp r0, #0 */
/* @0x1063c0 beq 0x106484 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x1063c4 bl 0x202d24 <_ZN9CDS_Stack3TopEv> */
/* @0x1063c8 subs r5, r0, #0 */
/* @0x1063cc streq r5, [r4] */
/* @0x1063d0 streq r5, [r4, #0x4] */
/* @0x1063d4 moveq r3, #5 */
/* @0x1063d8 streq r3, [r4, #0xc] */
/* @0x1063dc popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1063e0 ldr r2, [r4, #0xc] */
/* @0x1063e4 bic r3, r2, #-16777216 */
/* @0x1063e8 cmp r3, #1 */
/* @0x1063ec beq 0x1064b0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x1063f0 cmp r3, #2 */
/* @0x1063f4 bne 0x10641c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1063f8 sub r2, r2, #1 */
/* @0x1063fc bic r2, r2, #-16777216 */
/* @0x106400 bic r2, r2, #3 */
/* @0x106404 cmp r2, #0 */
/* @0x106408 beq 0x106584 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x10640c mov r2, #0 */
/* @0x106410 mov r3, #5 */
/* @0x106414 str r2, [r4, #0x8] */
/* @0x106418 str r3, [r4, #0xc] */
/* @0x10641c ldr r3, [r5, #0xc] */
/* @0x106420 mov r1, #0 */
/* @0x106424 ldr r2, [r5, #0x8] */
/* @0x106428 str r1, [r4] */
/* @0x10642c str r3, [r4, #0xc] */
/* @0x106430 ldr r3, [r5, #0xc] */
/* @0x106434 str r2, [r4, #0x8] */
/* @0x106438 bic r3, r3, #-16777216 */
/* @0x10643c cmp r3, #14 */
/* @0x106440 addls pc, pc, r3, lsl #2 */
/* @0x106444 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106448 b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x10644c b 0x106508 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x106450 b 0x106520 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x106454 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x106458 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10645c b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106460 b 0x1064e4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x106464 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x106468 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10646c b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106470 b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x106474 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106478 b 0x1064a0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x10647c b 0x1064a4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x106480 b 0x106498 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x106484 ldr r0, [pc, #0x1a4] */
/* @0x106488 mov r1, #0 */
/* @0x10648c pop {r3, r4, r5, r6, r7, lr} */
/* @0x106490 add r0, pc, r0 */
/* @0x106494 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x106498 ldr r3, [r5] */
/* @0x10649c str r3, [r4] */
/* @0x1064a0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1064a4 ldm r5, {r2, r3} */
/* @0x1064a8 stm r4, {r2, r3} */
/* @0x1064ac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1064b0 ldr r6, [r4] */
/* @0x1064b4 cmp r6, #0 */
/* @0x1064b8 beq 0x1064d8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x1064bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1064c0 ldr r7, [r6, #0x4] */
/* @0x1064c4 sub r7, r7, #1 */
/* @0x1064c8 str r7, [r6, #0x4] */
/* @0x1064cc cmp r7, #0 */
/* @0x1064d0 beq 0x10654c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x1064d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1064d8 mov r3, #0 */
/* @0x1064dc str r3, [r4] */
/* @0x1064e0 b 0x10641c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x1064e4 ldr r3, [r5] */
/* @0x1064e8 str r3, [r4] */
/* @0x1064ec ldr r3, [r5] */
/* @0x1064f0 cmp r3, #0 */
/* @0x1064f4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1064f8 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1064fc ldr r1, [r5] */
/* @0x106500 pop {r3, r4, r5, r6, r7, lr} */
/* @0x106504 b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x106508 ldr r3, [r5] */
/* @0x10650c cmp r3, #0 */
/* @0x106510 ldrne r2, [r3, #0x4] */
/* @0x106514 addne r2, r2, #1 */
/* @0x106518 strne r2, [r3, #0x4] */
/* @0x10651c b 0x10649c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106520 ldr r3, [r5] */
/* @0x106524 cmp r3, #0 */
/* @0x106528 str r3, [r4] */
/* @0x10652c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106530 ldr r1, [r3, #0x8] */
/* @0x106534 ldr r2, [r3] */
/* @0x106538 cmp r1, #0 */
/* @0x10653c streq r4, [r3, #0x8] */
/* @0x106540 add r2, r2, #1 */
/* @0x106544 str r2, [r3] */
/* @0x106548 pop {r3, r4, r5, r6, r7, pc} */
/* @0x10654c ldr r0, [r6] */
/* @0x106550 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106554 str r7, [r6] */
/* @0x106558 str r7, [r6, #0x8] */
/* @0x10655c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106560 ldr r7, [r6, #0x4] */
/* @0x106564 sub r7, r7, #1 */
/* @0x106568 str r7, [r6, #0x4] */
/* @0x10656c cmp r7, #0 */
/* @0x106570 beq 0x106590 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x106574 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106578 mov r0, r6 */
/* @0x10657c bl 0x27d1d0 <_ZdlPv> */
/* @0x106580 b 0x1064d4 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x106584 mov r0, r4 */
/* @0x106588 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10658c b 0x10640c <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x106590 ldr r0, [r6] */
/* @0x106594 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106598 str r7, [r6] */
/* @0x10659c str r7, [r6, #0x8] */
/* @0x1065a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1065a4 ldr r7, [r6, #0x4] */
/* @0x1065a8 sub r7, r7, #1 */
/* @0x1065ac str r7, [r6, #0x4] */
/* @0x1065b0 cmp r7, #0 */
/* @0x1065b4 beq 0x1065c8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x1065b8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1065bc mov r0, r6 */
/* @0x1065c0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1065c4 b 0x106574 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x1065c8 ldr r0, [r6] */
/* @0x1065cc bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1065d0 str r7, [r6] */
/* @0x1065d4 str r7, [r6, #0x8] */
/* @0x1065d8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1065dc ldr r3, [r6, #0x4] */
/* @0x1065e0 sub r3, r3, #1 */
/* @0x1065e4 str r3, [r6, #0x4] */
/* @0x1065e8 cmp r3, #0 */
/* @0x1065ec beq 0x106600 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x1065f0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1065f4 mov r0, r6 */
/* @0x1065f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1065fc b 0x1065b8 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x106600 ldr r0, [r6] */
/* @0x106604 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106608 mov r3, #0 */
/* @0x10660c mov r0, r6 */
/* @0x106610 str r3, [r6] */
/* @0x106614 str r3, [r6, #0x8] */
/* @0x106618 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x10661c mov r0, r6 */
/* @0x106620 bl 0x27d1d0 <_ZdlPv> */
/* @0x106624 b 0x1065f0 <_Z12F_DsStackTopR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x106628 eoreq r7, lr, r0, ror #21 */
/* @0x10662c .word 0x002e7ad0 */
/* @0x106630 eoreq r1, r3, r12, ror #14 */

/* ── FUNC 0x106634 · F_DsListFindValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=736 · insn=184 */
/* @0x106634 push {r3, r4, r5, r6, r7, lr} */
/* @0x106638 mov r1, #0 */
/* @0x10663c ldr r5, [sp, #0x18] */
/* @0x106640 mov r4, r0 */
/* @0x106644 mov r0, r5 */
/* @0x106648 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10664c cmp r0, #0 */
/* @0x106650 blt 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106654 ldr r3, [pc, #0x2ac] */
/* @0x106658 ldr r3, [pc, r3] */
/* @0x10665c ldr r3, [r3] */
/* @0x106660 cmp r0, r3 */
/* @0x106664 bge 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106668 ldr r3, [pc, #0x29c] */
/* @0x10666c ldr r3, [pc, r3] */
/* @0x106670 ldr r3, [r3, #0x4] */
/* @0x106674 ldr r6, [r3, r0, lsl #2] */
/* @0x106678 cmp r6, #0 */
/* @0x10667c beq 0x106754 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106680 mov r0, r5 */
/* @0x106684 mov r1, #1 */
/* @0x106688 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10668c mov r1, r0 */
/* @0x106690 mov r0, r6 */
/* @0x106694 bl 0x2031f4 <_ZN8CDS_List8GetValueEi> */
/* @0x106698 subs r5, r0, #0 */
/* @0x10669c streq r5, [r4] */
/* @0x1066a0 streq r5, [r4, #0x4] */
/* @0x1066a4 moveq r3, #5 */
/* @0x1066a8 streq r3, [r4, #0xc] */
/* @0x1066ac popeq {r3, r4, r5, r6, r7, pc} */
/* @0x1066b0 ldr r2, [r4, #0xc] */
/* @0x1066b4 bic r3, r2, #-16777216 */
/* @0x1066b8 cmp r3, #1 */
/* @0x1066bc beq 0x106788 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x154> */
/* @0x1066c0 cmp r3, #2 */
/* @0x1066c4 bne 0x1066ec <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1066c8 sub r2, r2, #1 */
/* @0x1066cc bic r2, r2, #-16777216 */
/* @0x1066d0 bic r2, r2, #3 */
/* @0x1066d4 cmp r2, #0 */
/* @0x1066d8 beq 0x106864 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x1066dc mov r2, #0 */
/* @0x1066e0 mov r3, #5 */
/* @0x1066e4 str r2, [r4, #0x8] */
/* @0x1066e8 str r3, [r4, #0xc] */
/* @0x1066ec ldr r3, [r5, #0xc] */
/* @0x1066f0 mov r2, #0 */
/* @0x1066f4 ldr r1, [r5, #0x8] */
/* @0x1066f8 str r2, [r4] */
/* @0x1066fc str r3, [r4, #0xc] */
/* @0x106700 ldr r2, [r5, #0xc] */
/* @0x106704 str r1, [r4, #0x8] */
/* @0x106708 bic r2, r2, #-16777216 */
/* @0x10670c cmp r2, #14 */
/* @0x106710 addls pc, pc, r2, lsl #2 */
/* @0x106714 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106718 b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x10671c b 0x1067e4 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1b0> */
/* @0x106720 b 0x106800 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1cc> */
/* @0x106724 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x106728 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x10672c b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106730 b 0x1067bc <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x188> */
/* @0x106734 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x106738 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x10673c b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106740 b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106744 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106748 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x10674c b 0x10677c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106750 b 0x106768 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x106754 ldr r0, [pc, #0x1b4] */
/* @0x106758 mov r1, #0 */
/* @0x10675c pop {r3, r4, r5, r6, r7, lr} */
/* @0x106760 add r0, pc, r0 */
/* @0x106764 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x106768 ldr r2, [r5] */
/* @0x10676c str r2, [r4] */
/* @0x106770 bic r3, r3, #-16777216 */
/* @0x106774 str r3, [r4, #0xc] */
/* @0x106778 pop {r3, r4, r5, r6, r7, pc} */
/* @0x10677c ldm r5, {r1, r2} */
/* @0x106780 stm r4, {r1, r2} */
/* @0x106784 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106788 ldr r6, [r4] */
/* @0x10678c cmp r6, #0 */
/* @0x106790 beq 0x1067b0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x106794 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106798 ldr r7, [r6, #0x4] */
/* @0x10679c sub r7, r7, #1 */
/* @0x1067a0 str r7, [r6, #0x4] */
/* @0x1067a4 cmp r7, #0 */
/* @0x1067a8 beq 0x10682c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x1067ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1067b0 mov r3, #0 */
/* @0x1067b4 str r3, [r4] */
/* @0x1067b8 b 0x1066ec <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xb8> */
/* @0x1067bc ldr r2, [r5] */
/* @0x1067c0 str r2, [r4] */
/* @0x1067c4 ldr r2, [r5] */
/* @0x1067c8 cmp r2, #0 */
/* @0x1067cc beq 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1067d0 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1067d4 ldr r1, [r5] */
/* @0x1067d8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1067dc ldr r3, [r4, #0xc] */
/* @0x1067e0 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1067e4 ldr r2, [r5] */
/* @0x1067e8 cmp r2, #0 */
/* @0x1067ec ldrne r3, [r2, #0x4] */
/* @0x1067f0 addne r3, r3, #1 */
/* @0x1067f4 strne r3, [r2, #0x4] */
/* @0x1067f8 ldrne r3, [r4, #0xc] */
/* @0x1067fc b 0x10676c <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x106800 ldr r2, [r5] */
/* @0x106804 cmp r2, #0 */
/* @0x106808 str r2, [r4] */
/* @0x10680c beq 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x106810 ldr r0, [r2, #0x8] */
/* @0x106814 ldr r1, [r2] */
/* @0x106818 cmp r0, #0 */
/* @0x10681c streq r4, [r2, #0x8] */
/* @0x106820 add r1, r1, #1 */
/* @0x106824 str r1, [r2] */
/* @0x106828 b 0x106770 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x10682c ldr r0, [r6] */
/* @0x106830 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106834 str r7, [r6] */
/* @0x106838 str r7, [r6, #0x8] */
/* @0x10683c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106840 ldr r7, [r6, #0x4] */
/* @0x106844 sub r7, r7, #1 */
/* @0x106848 str r7, [r6, #0x4] */
/* @0x10684c cmp r7, #0 */
/* @0x106850 beq 0x106870 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x106854 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106858 mov r0, r6 */
/* @0x10685c bl 0x27d1d0 <_ZdlPv> */
/* @0x106860 b 0x1067ac <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x178> */
/* @0x106864 mov r0, r4 */
/* @0x106868 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10686c b 0x1066dc <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0xa8> */
/* @0x106870 ldr r0, [r6] */
/* @0x106874 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106878 str r7, [r6] */
/* @0x10687c str r7, [r6, #0x8] */
/* @0x106880 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106884 ldr r7, [r6, #0x4] */
/* @0x106888 sub r7, r7, #1 */
/* @0x10688c str r7, [r6, #0x4] */
/* @0x106890 cmp r7, #0 */
/* @0x106894 beq 0x1068a8 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x106898 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10689c mov r0, r6 */
/* @0x1068a0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1068a4 b 0x106854 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x1068a8 ldr r0, [r6] */
/* @0x1068ac bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1068b0 str r7, [r6] */
/* @0x1068b4 str r7, [r6, #0x8] */
/* @0x1068b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1068bc ldr r3, [r6, #0x4] */
/* @0x1068c0 sub r3, r3, #1 */
/* @0x1068c4 str r3, [r6, #0x4] */
/* @0x1068c8 cmp r3, #0 */
/* @0x1068cc beq 0x1068e0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x1068d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1068d4 mov r0, r6 */
/* @0x1068d8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1068dc b 0x106898 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1068e0 ldr r0, [r6] */
/* @0x1068e4 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1068e8 mov r3, #0 */
/* @0x1068ec mov r0, r6 */
/* @0x1068f0 str r3, [r6] */
/* @0x1068f4 str r3, [r6, #0x8] */
/* @0x1068f8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1068fc mov r0, r6 */
/* @0x106900 bl 0x27d1d0 <_ZdlPv> */
/* @0x106904 b 0x1068d0 <_Z17F_DsListFindValueR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x106908 eoreq r7, lr, r4, lsr #12 */
/* @0x10690c eoreq r7, lr, r4, lsl r6 */
/* @0x106910 mlaeq r3, r12, r4, r1 */

/* ── FUNC 0x106914 · F_DsStackPop(RValue&, CInstance*, CInstance*, int, RValue*) · size=696 · insn=174 */
/* @0x106914 push {r3, r4, r5, r6, r7, lr} */
/* @0x106918 mov r1, #0 */
/* @0x10691c mov r4, r0 */
/* @0x106920 ldr r0, [sp, #0x18] */
/* @0x106924 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x106928 cmp r0, #0 */
/* @0x10692c blt 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x106930 ldr r3, [pc, #0x288] */
/* @0x106934 ldr r3, [pc, r3] */
/* @0x106938 ldr r3, [r3] */
/* @0x10693c cmp r0, r3 */
/* @0x106940 bge 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x106944 ldr r3, [pc, #0x278] */
/* @0x106948 ldr r3, [pc, r3] */
/* @0x10694c ldr r3, [r3, #0x4] */
/* @0x106950 ldr r0, [r3, r0, lsl #2] */
/* @0x106954 cmp r0, #0 */
/* @0x106958 beq 0x106a1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x108> */
/* @0x10695c bl 0x202d00 <_ZN9CDS_Stack3PopEv> */
/* @0x106960 subs r5, r0, #0 */
/* @0x106964 streq r5, [r4] */
/* @0x106968 streq r5, [r4, #0x4] */
/* @0x10696c moveq r3, #5 */
/* @0x106970 streq r3, [r4, #0xc] */
/* @0x106974 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106978 ldr r2, [r4, #0xc] */
/* @0x10697c bic r3, r2, #-16777216 */
/* @0x106980 cmp r3, #1 */
/* @0x106984 beq 0x106a48 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x134> */
/* @0x106988 cmp r3, #2 */
/* @0x10698c bne 0x1069b4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x106990 sub r2, r2, #1 */
/* @0x106994 bic r2, r2, #-16777216 */
/* @0x106998 bic r2, r2, #3 */
/* @0x10699c cmp r2, #0 */
/* @0x1069a0 beq 0x106b1c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x208> */
/* @0x1069a4 mov r2, #0 */
/* @0x1069a8 mov r3, #5 */
/* @0x1069ac str r2, [r4, #0x8] */
/* @0x1069b0 str r3, [r4, #0xc] */
/* @0x1069b4 ldr r3, [r5, #0xc] */
/* @0x1069b8 mov r1, #0 */
/* @0x1069bc ldr r2, [r5, #0x8] */
/* @0x1069c0 str r1, [r4] */
/* @0x1069c4 str r3, [r4, #0xc] */
/* @0x1069c8 ldr r3, [r5, #0xc] */
/* @0x1069cc str r2, [r4, #0x8] */
/* @0x1069d0 bic r3, r3, #-16777216 */
/* @0x1069d4 cmp r3, #14 */
/* @0x1069d8 addls pc, pc, r3, lsl #2 */
/* @0x1069dc b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1069e0 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x1069e4 b 0x106aa0 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x18c> */
/* @0x1069e8 b 0x106ab8 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x1069ec b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1069f0 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1069f4 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x1069f8 b 0x106a7c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x1069fc b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x106a00 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106a04 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106a08 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x106a0c b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106a10 b 0x106a38 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x124> */
/* @0x106a14 b 0x106a3c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x128> */
/* @0x106a18 b 0x106a30 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x106a1c ldr r0, [pc, #0x1a4] */
/* @0x106a20 mov r1, #0 */
/* @0x106a24 pop {r3, r4, r5, r6, r7, lr} */
/* @0x106a28 add r0, pc, r0 */
/* @0x106a2c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x106a30 ldr r3, [r5] */
/* @0x106a34 str r3, [r4] */
/* @0x106a38 pop {r3, r4, r5, r6, r7, pc} */
/* @0x106a3c ldm r5, {r2, r3} */
/* @0x106a40 stm r4, {r2, r3} */
/* @0x106a44 pop {r3, r4, r5, r6, r7, pc} */
/* @0x106a48 ldr r6, [r4] */
/* @0x106a4c cmp r6, #0 */
/* @0x106a50 beq 0x106a70 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106a54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106a58 ldr r7, [r6, #0x4] */
/* @0x106a5c sub r7, r7, #1 */
/* @0x106a60 str r7, [r6, #0x4] */
/* @0x106a64 cmp r7, #0 */
/* @0x106a68 beq 0x106ae4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x106a6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106a70 mov r3, #0 */
/* @0x106a74 str r3, [r4] */
/* @0x106a78 b 0x1069b4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0xa0> */
/* @0x106a7c ldr r3, [r5] */
/* @0x106a80 str r3, [r4] */
/* @0x106a84 ldr r3, [r5] */
/* @0x106a88 cmp r3, #0 */
/* @0x106a8c popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106a90 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x106a94 ldr r1, [r5] */
/* @0x106a98 pop {r3, r4, r5, r6, r7, lr} */
/* @0x106a9c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x106aa0 ldr r3, [r5] */
/* @0x106aa4 cmp r3, #0 */
/* @0x106aa8 ldrne r2, [r3, #0x4] */
/* @0x106aac addne r2, r2, #1 */
/* @0x106ab0 strne r2, [r3, #0x4] */
/* @0x106ab4 b 0x106a34 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106ab8 ldr r3, [r5] */
/* @0x106abc cmp r3, #0 */
/* @0x106ac0 str r3, [r4] */
/* @0x106ac4 popeq {r3, r4, r5, r6, r7, pc} */
/* @0x106ac8 ldr r1, [r3, #0x8] */
/* @0x106acc ldr r2, [r3] */
/* @0x106ad0 cmp r1, #0 */
/* @0x106ad4 streq r4, [r3, #0x8] */
/* @0x106ad8 add r2, r2, #1 */
/* @0x106adc str r2, [r3] */
/* @0x106ae0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x106ae4 ldr r0, [r6] */
/* @0x106ae8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106aec str r7, [r6] */
/* @0x106af0 str r7, [r6, #0x8] */
/* @0x106af4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106af8 ldr r7, [r6, #0x4] */
/* @0x106afc sub r7, r7, #1 */
/* @0x106b00 str r7, [r6, #0x4] */
/* @0x106b04 cmp r7, #0 */
/* @0x106b08 beq 0x106b28 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x106b0c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106b10 mov r0, r6 */
/* @0x106b14 bl 0x27d1d0 <_ZdlPv> */
/* @0x106b18 b 0x106a6c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x106b1c mov r0, r4 */
/* @0x106b20 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x106b24 b 0x1069a4 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x90> */
/* @0x106b28 ldr r0, [r6] */
/* @0x106b2c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106b30 str r7, [r6] */
/* @0x106b34 str r7, [r6, #0x8] */
/* @0x106b38 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106b3c ldr r7, [r6, #0x4] */
/* @0x106b40 sub r7, r7, #1 */
/* @0x106b44 str r7, [r6, #0x4] */
/* @0x106b48 cmp r7, #0 */
/* @0x106b4c beq 0x106b60 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x24c> */
/* @0x106b50 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106b54 mov r0, r6 */
/* @0x106b58 bl 0x27d1d0 <_ZdlPv> */
/* @0x106b5c b 0x106b0c <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x106b60 ldr r0, [r6] */
/* @0x106b64 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106b68 str r7, [r6] */
/* @0x106b6c str r7, [r6, #0x8] */
/* @0x106b70 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106b74 ldr r3, [r6, #0x4] */
/* @0x106b78 sub r3, r3, #1 */
/* @0x106b7c str r3, [r6, #0x4] */
/* @0x106b80 cmp r3, #0 */
/* @0x106b84 beq 0x106b98 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x106b88 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106b8c mov r0, r6 */
/* @0x106b90 bl 0x27d1d0 <_ZdlPv> */
/* @0x106b94 b 0x106b50 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x106b98 ldr r0, [r6] */
/* @0x106b9c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106ba0 mov r3, #0 */
/* @0x106ba4 mov r0, r6 */
/* @0x106ba8 str r3, [r6] */
/* @0x106bac str r3, [r6, #0x8] */
/* @0x106bb0 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x106bb4 mov r0, r6 */
/* @0x106bb8 bl 0x27d1d0 <_ZdlPv> */
/* @0x106bbc b 0x106b88 <_Z12F_DsStackPopR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x106bc0 eoreq r7, lr, r8, asr #10 */
/* @0x106bc4 eoreq r7, lr, r8, lsr r5 */
/* @0x106bc8 .word 0x002311d4 */

/* ── FUNC 0x106bcc · F_DsMapFindValue(RValue&, CInstance*, CInstance*, int, RValue*) · size=792 · insn=198 */
/* @0x106bcc push {r4, r5, r6, r7, lr} */
/* @0x106bd0 sub sp, sp, #28 */
/* @0x106bd4 add r5, sp, #4 */
/* @0x106bd8 mov r4, r0 */
/* @0x106bdc ldr r6, [sp, #0x30] */
/* @0x106be0 mov r0, r5 */
/* @0x106be4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x106be8 mov r1, #0 */
/* @0x106bec mov r0, r6 */
/* @0x106bf0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x106bf4 cmp r0, #0 */
/* @0x106bf8 blt 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106bfc ldr r3, [pc, #0x2d4] */
/* @0x106c00 ldr r3, [pc, r3] */
/* @0x106c04 ldr r3, [r3] */
/* @0x106c08 cmp r0, r3 */
/* @0x106c0c bge 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106c10 ldr r3, [pc, #0x2c4] */
/* @0x106c14 ldr r3, [pc, r3] */
/* @0x106c18 ldr r3, [r3, #0x4] */
/* @0x106c1c ldr r0, [r3, r0, lsl #2] */
/* @0x106c20 cmp r0, #0 */
/* @0x106c24 beq 0x106cec <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x120> */
/* @0x106c28 add r1, r6, #16 */
/* @0x106c2c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x106c30 cmp r0, #0 */
/* @0x106c34 beq 0x106d38 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x106c38 mov r3, r0 */
/* @0x106c3c ldr r6, [r4, #0xc] */
/* @0x106c40 ldr r0, [r3, #0x10]! */
/* @0x106c44 add r12, sp, #8 */
/* @0x106c48 bic lr, r6, #-16777216 */
/* @0x106c4c cmp lr, #1 */
/* @0x106c50 ldr r2, [r3, #0x8] */
/* @0x106c54 ldr r1, [r3, #0x4] */
/* @0x106c58 ldr r3, [r3, #0xc] */
/* @0x106c5c stm r12!, {r0, r1, r2, r3} */
/* @0x106c60 ldr r2, [sp, #0x14] */
/* @0x106c64 bic r2, r2, #-16777216 */
/* @0x106c68 str r2, [sp, #0x14] */
/* @0x106c6c beq 0x106d4c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x106c70 cmp lr, #2 */
/* @0x106c74 bne 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106c78 sub r6, r6, #1 */
/* @0x106c7c bic r6, r6, #-16777216 */
/* @0x106c80 bic r6, r6, #3 */
/* @0x106c84 cmp r6, #0 */
/* @0x106c88 beq 0x106e34 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x268> */
/* @0x106c8c ldr r1, [sp, #0x10] */
/* @0x106c90 bic r3, r2, #-16777216 */
/* @0x106c94 str r2, [r4, #0xc] */
/* @0x106c98 mov r2, #0 */
/* @0x106c9c str r2, [r4] */
/* @0x106ca0 str r1, [r4, #0x8] */
/* @0x106ca4 cmp r3, #14 */
/* @0x106ca8 addls pc, pc, r3, lsl #2 */
/* @0x106cac b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cb0 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106cb4 b 0x106dac <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1e0> */
/* @0x106cb8 b 0x106dd0 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x204> */
/* @0x106cbc b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cc0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cc4 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cc8 b 0x106d84 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1b8> */
/* @0x106ccc b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cd0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cd4 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106cd8 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106cdc b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106ce0 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106ce4 b 0x106d28 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106ce8 b 0x106d0c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x106cec ldr r0, [pc, #0x1ec] */
/* @0x106cf0 mov r1, #0 */
/* @0x106cf4 add r0, pc, r0 */
/* @0x106cf8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x106cfc mov r0, r5 */
/* @0x106d00 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x106d04 add sp, sp, #28 */
/* @0x106d08 pop {r4, r5, r6, r7, pc} */
/* @0x106d0c ldr r2, [sp, #0x8] */
/* @0x106d10 str r2, [r4] */
/* @0x106d14 str r3, [r4, #0xc] */
/* @0x106d18 mov r0, r5 */
/* @0x106d1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x106d20 add sp, sp, #28 */
/* @0x106d24 pop {r4, r5, r6, r7, pc} */
/* @0x106d28 ldr r1, [sp, #0x8] */
/* @0x106d2c ldr r2, [sp, #0xc] */
/* @0x106d30 stm r4, {r1, r2} */
/* @0x106d34 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106d38 mov r2, #5 */
/* @0x106d3c str r0, [r4] */
/* @0x106d40 str r0, [r4, #0x4] */
/* @0x106d44 str r2, [r4, #0xc] */
/* @0x106d48 b 0x106d18 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x106d4c ldr r6, [r4] */
/* @0x106d50 cmp r6, #0 */
/* @0x106d54 beq 0x106d78 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1ac> */
/* @0x106d58 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106d5c ldr r7, [r6, #0x4] */
/* @0x106d60 sub r7, r7, #1 */
/* @0x106d64 str r7, [r6, #0x4] */
/* @0x106d68 cmp r7, #0 */
/* @0x106d6c beq 0x106dfc <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x106d70 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106d74 ldr r2, [sp, #0x14] */
/* @0x106d78 mov r3, #0 */
/* @0x106d7c str r3, [r4] */
/* @0x106d80 b 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106d84 ldr r2, [sp, #0x8] */
/* @0x106d88 cmp r2, #0 */
/* @0x106d8c str r2, [r4] */
/* @0x106d90 beq 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106d94 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x106d98 ldr r1, [sp, #0x8] */
/* @0x106d9c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x106da0 ldr r3, [r4, #0xc] */
/* @0x106da4 bic r3, r3, #-16777216 */
/* @0x106da8 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106dac ldr r2, [sp, #0x8] */
/* @0x106db0 cmp r2, #0 */
/* @0x106db4 beq 0x106d10 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x106db8 ldr r3, [r2, #0x4] */
/* @0x106dbc add r3, r3, #1 */
/* @0x106dc0 str r3, [r2, #0x4] */
/* @0x106dc4 ldr r3, [r4, #0xc] */
/* @0x106dc8 bic r3, r3, #-16777216 */
/* @0x106dcc b 0x106d10 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x106dd0 ldr r2, [sp, #0x8] */
/* @0x106dd4 cmp r2, #0 */
/* @0x106dd8 str r2, [r4] */
/* @0x106ddc beq 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106de0 ldr r0, [r2, #0x8] */
/* @0x106de4 ldr r1, [r2] */
/* @0x106de8 cmp r0, #0 */
/* @0x106dec streq r4, [r2, #0x8] */
/* @0x106df0 add r1, r1, #1 */
/* @0x106df4 str r1, [r2] */
/* @0x106df8 b 0x106d14 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x106dfc ldr r0, [r6] */
/* @0x106e00 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e04 str r7, [r6] */
/* @0x106e08 str r7, [r6, #0x8] */
/* @0x106e0c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e10 ldr r7, [r6, #0x4] */
/* @0x106e14 sub r7, r7, #1 */
/* @0x106e18 str r7, [r6, #0x4] */
/* @0x106e1c cmp r7, #0 */
/* @0x106e20 beq 0x106e44 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x278> */
/* @0x106e24 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106e28 mov r0, r6 */
/* @0x106e2c bl 0x27d1d0 <_ZdlPv> */
/* @0x106e30 b 0x106d70 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x1a4> */
/* @0x106e34 mov r0, r4 */
/* @0x106e38 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x106e3c ldr r2, [sp, #0x14] */
/* @0x106e40 b 0x106c8c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0xc0> */
/* @0x106e44 ldr r0, [r6] */
/* @0x106e48 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e4c str r7, [r6] */
/* @0x106e50 str r7, [r6, #0x8] */
/* @0x106e54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e58 ldr r7, [r6, #0x4] */
/* @0x106e5c sub r7, r7, #1 */
/* @0x106e60 str r7, [r6, #0x4] */
/* @0x106e64 cmp r7, #0 */
/* @0x106e68 beq 0x106e7c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2b0> */
/* @0x106e6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106e70 mov r0, r6 */
/* @0x106e74 bl 0x27d1d0 <_ZdlPv> */
/* @0x106e78 b 0x106e24 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x258> */
/* @0x106e7c ldr r0, [r6] */
/* @0x106e80 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106e84 str r7, [r6] */
/* @0x106e88 str r7, [r6, #0x8] */
/* @0x106e8c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x106e90 ldr r3, [r6, #0x4] */
/* @0x106e94 sub r3, r3, #1 */
/* @0x106e98 str r3, [r6, #0x4] */
/* @0x106e9c cmp r3, #0 */
/* @0x106ea0 bne 0x106ec8 <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2fc> */
/* @0x106ea4 ldr r0, [r6] */
/* @0x106ea8 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x106eac mov r3, #0 */
/* @0x106eb0 mov r0, r6 */
/* @0x106eb4 str r3, [r6] */
/* @0x106eb8 str r3, [r6, #0x8] */
/* @0x106ebc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x106ec0 mov r0, r6 */
/* @0x106ec4 bl 0x27d1d0 <_ZdlPv> */
/* @0x106ec8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x106ecc mov r0, r6 */
/* @0x106ed0 bl 0x27d1d0 <_ZdlPv> */
/* @0x106ed4 b 0x106e6c <_Z16F_DsMapFindValueR6RValueP9CInstanceS2_iPS_+0x2a0> */
/* @0x106ed8 eoreq r7, lr, r8, ror r0 */
/* @0x106edc eoreq r6, lr, r8, lsr #26 */
/* @0x106ee0 eoreq r0, r3, r8, lsl #30 */

/* ── FUNC 0x106ee4 · F_DsMapSetPre(RValue&, CInstance*, CInstance*, int, RValue*) · size=728 · insn=182 */
/* @0x106ee4 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x106ee8 sub sp, sp, #12 */
/* @0x106eec add r7, sp, #4 */
/* @0x106ef0 mov r4, r0 */
/* @0x106ef4 ldr r5, [sp, #0x28] */
/* @0x106ef8 mov r0, r7 */
/* @0x106efc bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x106f00 mov r1, #0 */
/* @0x106f04 mov r0, r5 */
/* @0x106f08 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x106f0c ldr r2, [r4, #0xc] */
/* @0x106f10 bic r3, r2, #-16777216 */
/* @0x106f14 cmp r3, #1 */
/* @0x106f18 mov r6, r0 */
/* @0x106f1c beq 0x107040 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x15c> */
/* @0x106f20 cmp r3, #2 */
/* @0x106f24 bne 0x106f4c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x106f28 sub r2, r2, #1 */
/* @0x106f2c bic r2, r2, #-16777216 */
/* @0x106f30 bic r2, r2, #3 */
/* @0x106f34 cmp r2, #0 */
/* @0x106f38 beq 0x107114 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x106f3c mov r2, #0 */
/* @0x106f40 mov r3, #5 */
/* @0x106f44 str r2, [r4, #0x8] */
/* @0x106f48 str r3, [r4, #0xc] */
/* @0x106f4c ldr r3, [r5, #0x2c] */
/* @0x106f50 mov r1, #0 */
/* @0x106f54 ldr r2, [r5, #0x28] */
/* @0x106f58 str r1, [r4] */
/* @0x106f5c str r3, [r4, #0xc] */
/* @0x106f60 ldr r3, [r5, #0x2c] */
/* @0x106f64 str r2, [r4, #0x8] */
/* @0x106f68 bic r3, r3, #-16777216 */
/* @0x106f6c cmp r3, #14 */
/* @0x106f70 addls pc, pc, r3, lsl #2 */
/* @0x106f74 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106f78 b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x106f7c b 0x1070a0 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1bc> */
/* @0x106f80 b 0x107074 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x190> */
/* @0x106f84 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x106f88 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106f8c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106f90 b 0x1070b8 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1d4> */
/* @0x106f94 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x106f98 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106f9c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106fa0 b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x106fa4 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106fa8 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x106fac b 0x107030 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x14c> */
/* @0x106fb0 b 0x106fb4 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd0> */
/* @0x106fb4 ldr r3, [r5, #0x20] */
/* @0x106fb8 str r3, [r4] */
/* @0x106fbc cmp r6, #0 */
/* @0x106fc0 blt 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x106fc4 ldr r3, [pc, #0x1e4] */
/* @0x106fc8 ldr r3, [pc, r3] */
/* @0x106fcc ldr r3, [r3] */
/* @0x106fd0 cmp r6, r3 */
/* @0x106fd4 bge 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x106fd8 ldr r3, [pc, #0x1d4] */
/* @0x106fdc ldr r3, [pc, r3] */
/* @0x106fe0 ldr r3, [r3, #0x4] */
/* @0x106fe4 ldr r0, [r3, r6, lsl #2] */
/* @0x106fe8 cmp r0, #0 */
/* @0x106fec beq 0x107010 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x12c> */
/* @0x106ff0 add r1, r5, #16 */
/* @0x106ff4 add r2, r5, #32 */
/* @0x106ff8 mov r3, #0 */
/* @0x106ffc bl 0x208c3c <_ZN7CDS_Map3SetEP6RValueS1_S1_> */
/* @0x107000 mov r0, r7 */
/* @0x107004 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x107008 add sp, sp, #12 */
/* @0x10700c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x107010 ldr r0, [pc, #0x1a0] */
/* @0x107014 mov r1, #0 */
/* @0x107018 add r0, pc, r0 */
/* @0x10701c bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x107020 mov r0, r7 */
/* @0x107024 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x107028 add sp, sp, #12 */
/* @0x10702c pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x107030 ldr r2, [r5, #0x20] */
/* @0x107034 ldr r3, [r5, #0x24] */
/* @0x107038 stm r4, {r2, r3} */
/* @0x10703c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x107040 ldr r8, [r4] */
/* @0x107044 cmp r8, #0 */
/* @0x107048 beq 0x107068 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x184> */
/* @0x10704c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x107050 ldr r9, [r8, #0x4] */
/* @0x107054 sub r9, r9, #1 */
/* @0x107058 str r9, [r8, #0x4] */
/* @0x10705c cmp r9, #0 */
/* @0x107060 beq 0x1070dc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x1f8> */
/* @0x107064 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x107068 mov r3, #0 */
/* @0x10706c str r3, [r4] */
/* @0x107070 b 0x106f4c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x68> */
/* @0x107074 ldr r3, [r5, #0x20] */
/* @0x107078 cmp r3, #0 */
/* @0x10707c str r3, [r4] */
/* @0x107080 beq 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x107084 ldr r1, [r3, #0x8] */
/* @0x107088 ldr r2, [r3] */
/* @0x10708c cmp r1, #0 */
/* @0x107090 streq r4, [r3, #0x8] */
/* @0x107094 add r2, r2, #1 */
/* @0x107098 str r2, [r3] */
/* @0x10709c b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1070a0 ldr r3, [r5, #0x20] */
/* @0x1070a4 cmp r3, #0 */
/* @0x1070a8 ldrne r2, [r3, #0x4] */
/* @0x1070ac addne r2, r2, #1 */
/* @0x1070b0 strne r2, [r3, #0x4] */
/* @0x1070b4 b 0x106fb8 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1070b8 ldr r3, [r5, #0x20] */
/* @0x1070bc str r3, [r4] */
/* @0x1070c0 ldr r3, [r5, #0x20] */
/* @0x1070c4 cmp r3, #0 */
/* @0x1070c8 beq 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1070cc bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x1070d0 ldr r1, [r5, #0x20] */
/* @0x1070d4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x1070d8 b 0x106fbc <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0xd8> */
/* @0x1070dc ldr r0, [r8] */
/* @0x1070e0 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1070e4 str r9, [r8] */
/* @0x1070e8 str r9, [r8, #0x8] */
/* @0x1070ec bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1070f0 ldr r9, [r8, #0x4] */
/* @0x1070f4 sub r9, r9, #1 */
/* @0x1070f8 str r9, [r8, #0x4] */
/* @0x1070fc cmp r9, #0 */
/* @0x107100 beq 0x107120 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x23c> */
/* @0x107104 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x107108 mov r0, r8 */
/* @0x10710c bl 0x27d1d0 <_ZdlPv> */
/* @0x107110 b 0x107064 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x180> */
/* @0x107114 mov r0, r4 */
/* @0x107118 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x10711c b 0x106f3c <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x58> */
/* @0x107120 ldr r0, [r8] */
/* @0x107124 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107128 str r9, [r8] */
/* @0x10712c str r9, [r8, #0x8] */
/* @0x107130 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x107134 ldr r9, [r8, #0x4] */
/* @0x107138 sub r9, r9, #1 */
/* @0x10713c str r9, [r8, #0x4] */
/* @0x107140 cmp r9, #0 */
/* @0x107144 beq 0x107158 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x107148 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10714c mov r0, r8 */
/* @0x107150 bl 0x27d1d0 <_ZdlPv> */
/* @0x107154 b 0x107104 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x220> */
/* @0x107158 ldr r0, [r8] */
/* @0x10715c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107160 str r9, [r8] */
/* @0x107164 str r9, [r8, #0x8] */
/* @0x107168 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10716c ldr r9, [r8, #0x4] */
/* @0x107170 sub r9, r9, #1 */
/* @0x107174 str r9, [r8, #0x4] */
/* @0x107178 cmp r9, #0 */
/* @0x10717c bne 0x1071a0 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x2bc> */
/* @0x107180 ldr r0, [r8] */
/* @0x107184 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107188 mov r0, r8 */
/* @0x10718c str r9, [r8] */
/* @0x107190 str r9, [r8, #0x8] */
/* @0x107194 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x107198 mov r0, r8 */
/* @0x10719c bl 0x27d1d0 <_ZdlPv> */
/* @0x1071a0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1071a4 mov r0, r8 */
/* @0x1071a8 bl 0x27d1d0 <_ZdlPv> */
/* @0x1071ac b 0x107148 <_Z13F_DsMapSetPreR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x1071b0 .word 0x002e6cb0 */
/* @0x1071b4 eoreq r6, lr, r0, ror #18 */
/* @0x1071b8 eoreq r0, r3, r4, ror #23 */

/* ── FUNC 0x1071bc · F_DsMapFindPrevious(RValue&, CInstance*, CInstance*, int, RValue*) · size=788 · insn=197 */
/* @0x1071bc push {r4, r5, r6, r7, lr} */
/* @0x1071c0 sub sp, sp, #28 */
/* @0x1071c4 add r5, sp, #4 */
/* @0x1071c8 mov r4, r0 */
/* @0x1071cc ldr r6, [sp, #0x30] */
/* @0x1071d0 mov r0, r5 */
/* @0x1071d4 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x1071d8 mov r1, #0 */
/* @0x1071dc mov r0, r6 */
/* @0x1071e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1071e4 cmp r0, #0 */
/* @0x1071e8 blt 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x1071ec ldr r3, [pc, #0x2d0] */
/* @0x1071f0 ldr r3, [pc, r3] */
/* @0x1071f4 ldr r3, [r3] */
/* @0x1071f8 cmp r0, r3 */
/* @0x1071fc bge 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x107200 ldr r3, [pc, #0x2c0] */
/* @0x107204 ldr r3, [pc, r3] */
/* @0x107208 ldr r3, [r3, #0x4] */
/* @0x10720c ldr r0, [r3, r0, lsl #2] */
/* @0x107210 cmp r0, #0 */
/* @0x107214 beq 0x1072d8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x11c> */
/* @0x107218 add r1, r6, #16 */
/* @0x10721c bl 0x203a80 <_ZN7CDS_Map12FindPreviousEP6RValue> */
/* @0x107220 subs r3, r0, #0 */
/* @0x107224 beq 0x107324 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x168> */
/* @0x107228 ldr r2, [r3, #0x8] */
/* @0x10722c add r12, sp, #8 */
/* @0x107230 ldr r0, [r3] */
/* @0x107234 ldr r1, [r3, #0x4] */
/* @0x107238 ldr r6, [r4, #0xc] */
/* @0x10723c ldr r3, [r3, #0xc] */
/* @0x107240 bic lr, r6, #-16777216 */
/* @0x107244 cmp lr, #1 */
/* @0x107248 stm r12!, {r0, r1, r2, r3} */
/* @0x10724c ldr r2, [sp, #0x14] */
/* @0x107250 bic r2, r2, #-16777216 */
/* @0x107254 str r2, [sp, #0x14] */
/* @0x107258 beq 0x107338 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x17c> */
/* @0x10725c cmp lr, #2 */
/* @0x107260 bne 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x107264 sub r6, r6, #1 */
/* @0x107268 bic r6, r6, #-16777216 */
/* @0x10726c bic r6, r6, #3 */
/* @0x107270 cmp r6, #0 */
/* @0x107274 beq 0x107420 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x107278 ldr r1, [sp, #0x10] */
/* @0x10727c bic r3, r2, #-16777216 */
/* @0x107280 str r2, [r4, #0xc] */
/* @0x107284 mov r2, #0 */
/* @0x107288 str r2, [r4] */
/* @0x10728c str r1, [r4, #0x8] */
/* @0x107290 cmp r3, #14 */
/* @0x107294 addls pc, pc, r3, lsl #2 */
/* @0x107298 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x10729c b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1072a0 b 0x107398 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1dc> */
/* @0x1072a4 b 0x1073bc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x200> */
/* @0x1072a8 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1072ac b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072b0 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072b4 b 0x107370 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1b4> */
/* @0x1072b8 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1072bc b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072c0 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072c4 b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1072c8 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072cc b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1072d0 b 0x107314 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x158> */
/* @0x1072d4 b 0x1072f8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x13c> */
/* @0x1072d8 ldr r0, [pc, #0x1ec] */
/* @0x1072dc mov r1, #0 */
/* @0x1072e0 add r0, pc, r0 */
/* @0x1072e4 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1072e8 mov r0, r5 */
/* @0x1072ec bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1072f0 add sp, sp, #28 */
/* @0x1072f4 pop {r4, r5, r6, r7, pc} */
/* @0x1072f8 ldr r2, [sp, #0x8] */
/* @0x1072fc str r2, [r4] */
/* @0x107300 str r3, [r4, #0xc] */
/* @0x107304 mov r0, r5 */
/* @0x107308 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x10730c add sp, sp, #28 */
/* @0x107310 pop {r4, r5, r6, r7, pc} */
/* @0x107314 ldr r1, [sp, #0x8] */
/* @0x107318 ldr r2, [sp, #0xc] */
/* @0x10731c stm r4, {r1, r2} */
/* @0x107320 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x107324 mov r2, #5 */
/* @0x107328 str r3, [r4] */
/* @0x10732c str r3, [r4, #0x4] */
/* @0x107330 str r2, [r4, #0xc] */
/* @0x107334 b 0x107304 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x148> */
/* @0x107338 ldr r6, [r4] */
/* @0x10733c cmp r6, #0 */
/* @0x107340 beq 0x107364 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x107344 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x107348 ldr r7, [r6, #0x4] */
/* @0x10734c sub r7, r7, #1 */
/* @0x107350 str r7, [r6, #0x4] */
/* @0x107354 cmp r7, #0 */
/* @0x107358 beq 0x1073e8 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x22c> */
/* @0x10735c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x107360 ldr r2, [sp, #0x14] */
/* @0x107364 mov r3, #0 */
/* @0x107368 str r3, [r4] */
/* @0x10736c b 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x107370 ldr r2, [sp, #0x8] */
/* @0x107374 cmp r2, #0 */
/* @0x107378 str r2, [r4] */
/* @0x10737c beq 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x107380 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x107384 ldr r1, [sp, #0x8] */
/* @0x107388 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x10738c ldr r3, [r4, #0xc] */
/* @0x107390 bic r3, r3, #-16777216 */
/* @0x107394 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x107398 ldr r2, [sp, #0x8] */
/* @0x10739c cmp r2, #0 */
/* @0x1073a0 beq 0x1072fc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1073a4 ldr r3, [r2, #0x4] */
/* @0x1073a8 add r3, r3, #1 */
/* @0x1073ac str r3, [r2, #0x4] */
/* @0x1073b0 ldr r3, [r4, #0xc] */
/* @0x1073b4 bic r3, r3, #-16777216 */
/* @0x1073b8 b 0x1072fc <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x1073bc ldr r2, [sp, #0x8] */
/* @0x1073c0 cmp r2, #0 */
/* @0x1073c4 str r2, [r4] */
/* @0x1073c8 beq 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1073cc ldr r0, [r2, #0x8] */
/* @0x1073d0 ldr r1, [r2] */
/* @0x1073d4 cmp r0, #0 */
/* @0x1073d8 streq r4, [r2, #0x8] */
/* @0x1073dc add r1, r1, #1 */
/* @0x1073e0 str r1, [r2] */
/* @0x1073e4 b 0x107300 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x144> */
/* @0x1073e8 ldr r0, [r6] */
/* @0x1073ec bl 0xcef90 <_Z6YYFreePKv> */
/* @0x1073f0 str r7, [r6] */
/* @0x1073f4 str r7, [r6, #0x8] */
/* @0x1073f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x1073fc ldr r7, [r6, #0x4] */
/* @0x107400 sub r7, r7, #1 */
/* @0x107404 str r7, [r6, #0x4] */
/* @0x107408 cmp r7, #0 */
/* @0x10740c beq 0x107430 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x274> */
/* @0x107410 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x107414 mov r0, r6 */
/* @0x107418 bl 0x27d1d0 <_ZdlPv> */
/* @0x10741c b 0x10735c <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x1a0> */
/* @0x107420 mov r0, r4 */
/* @0x107424 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x107428 ldr r2, [sp, #0x14] */
/* @0x10742c b 0x107278 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x107430 ldr r0, [r6] */
/* @0x107434 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107438 str r7, [r6] */
/* @0x10743c str r7, [r6, #0x8] */
/* @0x107440 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x107444 ldr r7, [r6, #0x4] */
/* @0x107448 sub r7, r7, #1 */
/* @0x10744c str r7, [r6, #0x4] */
/* @0x107450 cmp r7, #0 */
/* @0x107454 beq 0x107468 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x107458 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x10745c mov r0, r6 */
/* @0x107460 bl 0x27d1d0 <_ZdlPv> */
/* @0x107464 b 0x107410 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x254> */
/* @0x107468 ldr r0, [r6] */
/* @0x10746c bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107470 str r7, [r6] */
/* @0x107474 str r7, [r6, #0x8] */
/* @0x107478 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv> */
/* @0x10747c ldr r3, [r6, #0x4] */
/* @0x107480 sub r3, r3, #1 */
/* @0x107484 str r3, [r6, #0x4] */
/* @0x107488 cmp r3, #0 */
/* @0x10748c bne 0x1074b4 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x2f8> */
/* @0x107490 ldr r0, [r6] */
/* @0x107494 bl 0xcef90 <_Z6YYFreePKv> */
/* @0x107498 mov r3, #0 */
/* @0x10749c mov r0, r6 */
/* @0x1074a0 str r3, [r6] */
/* @0x1074a4 str r3, [r6, #0x8] */
/* @0x1074a8 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv> */
/* @0x1074ac mov r0, r6 */
/* @0x1074b0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1074b4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv> */
/* @0x1074b8 mov r0, r6 */
/* @0x1074bc bl 0x27d1d0 <_ZdlPv> */
/* @0x1074c0 b 0x107458 <_Z19F_DsMapFindPreviousR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x1074c4 eoreq r6, lr, r8, lsl #21 */
/* @0x1074c8 eoreq r6, lr, r8, lsr r7 */
/* @0x1074cc eoreq r0, r3, r12, lsl r9 */

/* ── FUNC 0x1074d0 · F_TransitionDefine(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1074d0 mov r2, #0 */
/* @0x1074d4 mov r3, r2 */
/* @0x1074d8 movt r2, #0xbff0 */
/* @0x1074dc str r3, [r0, #0xc] */
/* @0x1074e0 str r2, [r0, #0x4] */
/* @0x1074e4 str r3, [r0] */
/* @0x1074e8 bx lr */

/* ── FUNC 0x1074ec · F_TransitionExists(RValue&, CInstance*, CInstance*, int, RValue*) · size=28 · insn=7 */
/* @0x1074ec mov r2, #0 */
/* @0x1074f0 mov r3, r2 */
/* @0x1074f4 movt r2, #0xbff0 */
/* @0x1074f8 str r3, [r0, #0xc] */
/* @0x1074fc str r2, [r0, #0x4] */
/* @0x107500 str r3, [r0] */
/* @0x107504 bx lr */

/* ── FUNC 0x107508 · F_MoveRandom(RValue&, CInstance*, CInstance*, int, RValue*) · size=916 · insn=229 */
/* @0x107508 ldr r3, [pc, #0x388] */
/* @0x10750c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x107510 vpush {d8, d9} */
/* @0x107514 ldr r3, [pc, r3] */
/* @0x107518 sub sp, sp, #12 */
/* @0x10751c ldr r0, [r1, #0x8c] */
/* @0x107520 ldr r3, [r3] */
/* @0x107524 mov r4, r1 */
/* @0x107528 ldr r10, [sp, #0x40] */
/* @0x10752c ldr r8, [r3, #0x10] */
/* @0x107530 ldr r9, [r3, #0x14] */
/* @0x107534 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x107538 cmp r0, #0 */
/* @0x10753c beq 0x1076f4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1ec> */
/* @0x107540 ldrb r3, [r4, #0x64] */
/* @0x107544 cmp r3, #0 */
/* @0x107548 bne 0x107888 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x380> */
/* @0x10754c vldr s12, [r4, #232] */
/* @0x107550 vcvt.f32.s32 s15, s12 */
/* @0x107554 vldr s14, [r4, #180] */
/* @0x107558 vsub.f32 s15, s14, s15 */
/* @0x10755c vcvt.f64.f32 d6, s15 */
/* @0x107560 vmov r0, r1, d6 */
/* @0x107564 bl 0xb66e8 <lrint@plt> */
/* @0x107568 vldr s15, [r4, #180] */
/* @0x10756c vmov s13, r8 */
/* @0x107570 vldr s12, [r4, #240] */
/* @0x107574 vcvt.f32.s32 s14, s13 */
/* @0x107578 vadd.f32 s14, s14, s15 */
/* @0x10757c vcvt.f32.s32 s15, s12 */
/* @0x107580 vsub.f32 s15, s14, s15 */
/* @0x107584 mov r11, r0 */
/* @0x107588 mov r6, r0 */
/* @0x10758c vcvt.f64.f32 d6, s15 */
/* @0x107590 vmov r0, r1, d6 */
/* @0x107594 bl 0xb66e8 <lrint@plt> */
/* @0x107598 vldr s13, [r4, #236] */
/* @0x10759c vcvt.f32.s32 s15, s13 */
/* @0x1075a0 vldr s14, [r4, #184] */
/* @0x1075a4 vsub.f32 s15, s14, s15 */
/* @0x1075a8 vcvt.f64.f32 d6, s15 */
/* @0x1075ac mov r8, r0 */
/* @0x1075b0 vmov r0, r1, d6 */
/* @0x1075b4 bl 0xb66e8 <lrint@plt> */
/* @0x1075b8 vldr s15, [r4, #184] */
/* @0x1075bc vmov s13, r9 */
/* @0x1075c0 vldr s12, [r4, #244] */
/* @0x1075c4 vcvt.f32.s32 s14, s13 */
/* @0x1075c8 vadd.f32 s14, s14, s15 */
/* @0x1075cc vcvt.f32.s32 s15, s12 */
/* @0x1075d0 vsub.f32 s15, s14, s15 */
/* @0x1075d4 str r0, [sp, #0x4] */
/* @0x1075d8 mov r5, r0 */
/* @0x1075dc vcvt.f64.f32 d6, s15 */
/* @0x1075e0 vmov r0, r1, d6 */
/* @0x1075e4 bl 0xb66e8 <lrint@plt> */
/* @0x1075e8 mov r9, r0 */
/* @0x1075ec mov r0, r10 */
/* @0x1075f0 mov r1, #0 */
/* @0x1075f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1075f8 mov r1, #1 */
/* @0x1075fc rsb r8, r11, r8 */
/* @0x107600 mov r7, r0 */
/* @0x107604 mov r0, r10 */
/* @0x107608 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x10760c ldr r3, [sp, #0x4] */
/* @0x107610 cmp r7, #0 */
/* @0x107614 rsb r9, r3, r9 */
/* @0x107618 mov r10, r0 */
/* @0x10761c ble 0x107718 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x210> */
/* @0x107620 cmp r0, #0 */
/* @0x107624 ble 0x1077f8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x107628 vmov s12, r0 */
/* @0x10762c mov r11, #100 */
/* @0x107630 vmov s13, r7 */
/* @0x107634 vcvt.f32.s32 s19, s12 */
/* @0x107638 vcvt.f32.s32 s18, s13 */
/* @0x10763c b 0x107648 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x140> */
/* @0x107640 subs r11, r11, #1 */
/* @0x107644 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107648 mov r0, r8 */
/* @0x10764c bl 0xc4600 <_Z8YYRandomi> */
/* @0x107650 add r0, r0, r6 */
/* @0x107654 vmov s14, r0 */
/* @0x107658 vcvt.f32.u32 s15, s14 */
/* @0x10765c vdiv.f32 s15, s15, s18 */
/* @0x107660 vcvt.f64.f32 d6, s15 */
/* @0x107664 vmov r0, r1, d6 */
/* @0x107668 bl 0xb6598 <floor@plt> */
/* @0x10766c vmov d7, r0, r1 */
/* @0x107670 mov r0, r9 */
/* @0x107674 vcvt.s32.f64 s17, d7 */
/* @0x107678 vmov r3, s17 */
/* @0x10767c mul r3, r7, r3 */
/* @0x107680 vmov s17, r3 */
/* @0x107684 bl 0xc4600 <_Z8YYRandomi> */
/* @0x107688 vcvt.f32.s32 s17, s17 */
/* @0x10768c add r0, r0, r5 */
/* @0x107690 vmov s12, r0 */
/* @0x107694 vcvt.f32.u32 s15, s12 */
/* @0x107698 vdiv.f32 s15, s15, s19 */
/* @0x10769c vcvt.f64.f32 d6, s15 */
/* @0x1076a0 vmov r0, r1, d6 */
/* @0x1076a4 bl 0xb6598 <floor@plt> */
/* @0x1076a8 vmov d7, r0, r1 */
/* @0x1076ac mov r0, r4 */
/* @0x1076b0 vcvt.s32.f64 s16, d7 */
/* @0x1076b4 vmov r1, s17 */
/* @0x1076b8 vmov r3, s16 */
/* @0x1076bc mul r3, r10, r3 */
/* @0x1076c0 vmov s16, r3 */
/* @0x1076c4 vcvt.f32.s32 s16, s16 */
/* @0x1076c8 vmov r2, s16 */
/* @0x1076cc bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1076d0 cmp r0, #0 */
/* @0x1076d4 beq 0x107640 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x138> */
/* @0x1076d8 vmov r1, s17 */
/* @0x1076dc mov r0, r4 */
/* @0x1076e0 vmov r2, s16 */
/* @0x1076e4 add sp, sp, #12 */
/* @0x1076e8 vpop {d8, d9} */
/* @0x1076ec pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1076f0 b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1076f4 ldr r0, [r4, #0xac] */
/* @0x1076f8 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1076fc cmp r0, #0 */
/* @0x107700 bne 0x107540 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x38> */
/* @0x107704 mov r5, r0 */
/* @0x107708 mov r6, r0 */
/* @0x10770c str r0, [sp, #0x4] */
/* @0x107710 mov r11, r0 */
/* @0x107714 b 0x1075ec <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0xe4> */
/* @0x107718 cmp r0, #0 */
/* @0x10771c ble 0x1077a4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x29c> */
/* @0x107720 vmov s12, r0 */
/* @0x107724 mov r7, #100 */
/* @0x107728 vcvt.f32.s32 s19, s12 */
/* @0x10772c b 0x107738 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x107730 subs r7, r7, #1 */
/* @0x107734 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107738 mov r0, r8 */
/* @0x10773c bl 0xc4600 <_Z8YYRandomi> */
/* @0x107740 add r0, r0, r6 */
/* @0x107744 vmov s17, r0 */
/* @0x107748 mov r0, r9 */
/* @0x10774c bl 0xc4600 <_Z8YYRandomi> */
/* @0x107750 vcvt.f32.u32 s17, s17 */
/* @0x107754 add r0, r0, r5 */
/* @0x107758 vmov s13, r0 */
/* @0x10775c vcvt.f32.u32 s15, s13 */
/* @0x107760 vdiv.f32 s15, s15, s19 */
/* @0x107764 vcvt.f64.f32 d6, s15 */
/* @0x107768 vmov r0, r1, d6 */
/* @0x10776c bl 0xb6598 <floor@plt> */
/* @0x107770 vmov d7, r0, r1 */
/* @0x107774 mov r0, r4 */
/* @0x107778 vcvt.s32.f64 s16, d7 */
/* @0x10777c vmov r1, s17 */
/* @0x107780 vmov r3, s16 */
/* @0x107784 mul r3, r10, r3 */
/* @0x107788 vmov s16, r3 */
/* @0x10778c vcvt.f32.s32 s16, s16 */
/* @0x107790 vmov r2, s16 */
/* @0x107794 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x107798 cmp r0, #0 */
/* @0x10779c beq 0x107730 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x1077a0 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x1077a4 mov r7, #100 */
/* @0x1077a8 b 0x1077b4 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2ac> */
/* @0x1077ac subs r7, r7, #1 */
/* @0x1077b0 beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x1077b4 mov r0, r8 */
/* @0x1077b8 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1077bc add r0, r0, r6 */
/* @0x1077c0 vmov s17, r0 */
/* @0x1077c4 mov r0, r9 */
/* @0x1077c8 bl 0xc4600 <_Z8YYRandomi> */
/* @0x1077cc vcvt.f32.u32 s17, s17 */
/* @0x1077d0 vmov r1, s17 */
/* @0x1077d4 add r0, r0, r5 */
/* @0x1077d8 vmov s16, r0 */
/* @0x1077dc mov r0, r4 */
/* @0x1077e0 vcvt.f32.u32 s16, s16 */
/* @0x1077e4 vmov r2, s16 */
/* @0x1077e8 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1077ec cmp r0, #0 */
/* @0x1077f0 beq 0x1077ac <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x1077f4 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x1077f8 vmov s12, r7 */
/* @0x1077fc mov r10, #100 */
/* @0x107800 vcvt.f32.s32 s18, s12 */
/* @0x107804 b 0x107810 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x107808 subs r10, r10, #1 */
/* @0x10780c beq 0x10787c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107810 mov r0, r8 */
/* @0x107814 bl 0xc4600 <_Z8YYRandomi> */
/* @0x107818 add r0, r0, r6 */
/* @0x10781c vmov s13, r0 */
/* @0x107820 vcvt.f32.u32 s15, s13 */
/* @0x107824 vdiv.f32 s15, s15, s18 */
/* @0x107828 vcvt.f64.f32 d6, s15 */
/* @0x10782c vmov r0, r1, d6 */
/* @0x107830 bl 0xb6598 <floor@plt> */
/* @0x107834 vmov d7, r0, r1 */
/* @0x107838 mov r0, r9 */
/* @0x10783c vcvt.s32.f64 s17, d7 */
/* @0x107840 vmov r3, s17 */
/* @0x107844 mul r3, r7, r3 */
/* @0x107848 vmov s17, r3 */
/* @0x10784c bl 0xc4600 <_Z8YYRandomi> */
/* @0x107850 vcvt.f32.s32 s17, s17 */
/* @0x107854 vmov r1, s17 */
/* @0x107858 add r0, r0, r5 */
/* @0x10785c vmov s16, r0 */
/* @0x107860 mov r0, r4 */
/* @0x107864 vcvt.f32.u32 s16, s16 */
/* @0x107868 vmov r2, s16 */
/* @0x10786c bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x107870 cmp r0, #0 */
/* @0x107874 beq 0x107808 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x300> */
/* @0x107878 b 0x1076d8 <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x1d0> */
/* @0x10787c add sp, sp, #12 */
/* @0x107880 vpop {d8, d9} */
/* @0x107884 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x107888 mov r0, r4 */
/* @0x10788c mov r1, #1 */
/* @0x107890 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x107894 b 0x10754c <_Z12F_MoveRandomR6RValueP9CInstanceS2_iPS_+0x44> */
/* @0x107898 eoreq r6, lr, r4, lsl r4 */

/* ── FUNC 0x10789c · F_PlaceFree(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x10789c push {r4, r5, r6, r7, r8, lr} */
/* @0x1078a0 mov r5, #0 */
/* @0x1078a4 ldr r6, [sp, #0x18] */
/* @0x1078a8 mov r4, r0 */
/* @0x1078ac str r5, [r0, #0xc] */
/* @0x1078b0 mov r8, r1 */
/* @0x1078b4 mov r1, r5 */
/* @0x1078b8 mov r0, r6 */
/* @0x1078bc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1078c0 mov r1, #1 */
/* @0x1078c4 mov r7, r0 */
/* @0x1078c8 mov r0, r6 */
/* @0x1078cc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1078d0 mov r1, r7 */
/* @0x1078d4 mov r2, r0 */
/* @0x1078d8 mov r0, r8 */
/* @0x1078dc bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1078e0 cmp r0, #0 */
/* @0x1078e4 moveq r5, r0 */
/* @0x1078e8 movne r3, r5 */
/* @0x1078ec moveq r3, r5 */
/* @0x1078f0 movtne r3, #0x3ff0 */
/* @0x1078f4 str r5, [r4] */
/* @0x1078f8 str r3, [r4, #0x4] */
/* @0x1078fc pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x107900 · F_Point_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=196 · insn=49 */
/* @0x107900 push {r4, r5, r6, lr} */
/* @0x107904 vpush {d8, d9, d10} */
/* @0x107908 mov r5, #0 */
/* @0x10790c ldr r4, [sp, #0x28] */
/* @0x107910 mov r1, r5 */
/* @0x107914 str r5, [r0, #0xc] */
/* @0x107918 mov r6, r0 */
/* @0x10791c str r5, [r0] */
/* @0x107920 str r5, [r0, #0x4] */
/* @0x107924 mov r0, r4 */
/* @0x107928 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10792c mov r1, #1 */
/* @0x107930 vmov s16, r0 */
/* @0x107934 mov r0, r4 */
/* @0x107938 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10793c mov r1, #2 */
/* @0x107940 vmov s19, r0 */
/* @0x107944 mov r0, r4 */
/* @0x107948 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10794c mov r1, #3 */
/* @0x107950 vmov s17, r0 */
/* @0x107954 mov r0, r4 */
/* @0x107958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10795c mov r1, #4 */
/* @0x107960 vmov s20, r0 */
/* @0x107964 mov r0, r4 */
/* @0x107968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10796c mov r1, #5 */
/* @0x107970 vmov s18, r0 */
/* @0x107974 mov r0, r4 */
/* @0x107978 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x10797c vcmpe.f32 s16, s17 */
/* @0x107980 vmrs APSR_nzcv, fpscr */
/* @0x107984 vmov s15, r0 */
/* @0x107988 blt 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x10798c vcmpe.f32 s16, s18 */
/* @0x107990 vmrs APSR_nzcv, fpscr */
/* @0x107994 bhi 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x107998 vcmpe.f32 s19, s20 */
/* @0x10799c vmrs APSR_nzcv, fpscr */
/* @0x1079a0 blt 0x1079bc <_Z20F_Point_In_RectangleR6RValueP9CInstanceS2_iPS_+0xbc> */
/* @0x1079a4 vcmpe.f32 s19, s15 */
/* @0x1079a8 vmrs APSR_nzcv, fpscr */
/* @0x1079ac movls r3, r5 */
/* @0x1079b0 strls r5, [r6] */
/* @0x1079b4 movtls r3, #0x3ff0 */
/* @0x1079b8 strls r3, [r6, #0x4] */
/* @0x1079bc vpop {d8, d9, d10} */
/* @0x1079c0 pop {r4, r5, r6, pc} */

/* ── FUNC 0x1079c4 · F_Rectangle_In_Rectangle(RValue&, CInstance*, CInstance*, int, RValue*) · size=1060 · insn=265 */
/* @0x1079c4 push {r3, r4, r5, lr} */
/* @0x1079c8 vpush {d8, d9, d10, d11} */
/* @0x1079cc mov r1, #0 */
/* @0x1079d0 ldr r4, [sp, #0x30] */
/* @0x1079d4 mov r5, r0 */
/* @0x1079d8 str r1, [r0, #0xc] */
/* @0x1079dc mov r0, r4 */
/* @0x1079e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1079e4 mov r1, #1 */
/* @0x1079e8 vmov s18, r0 */
/* @0x1079ec mov r0, r4 */
/* @0x1079f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1079f4 mov r1, #2 */
/* @0x1079f8 vmov s21, r0 */
/* @0x1079fc mov r0, r4 */
/* @0x107a00 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a04 mov r1, #3 */
/* @0x107a08 vmov s17, r0 */
/* @0x107a0c mov r0, r4 */
/* @0x107a10 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a14 mov r1, #4 */
/* @0x107a18 vmov s20, r0 */
/* @0x107a1c mov r0, r4 */
/* @0x107a20 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a24 mov r1, #5 */
/* @0x107a28 vmov s19, r0 */
/* @0x107a2c mov r0, r4 */
/* @0x107a30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a34 mov r1, #6 */
/* @0x107a38 vmov s22, r0 */
/* @0x107a3c mov r0, r4 */
/* @0x107a40 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a44 mov r1, #7 */
/* @0x107a48 vmov s16, r0 */
/* @0x107a4c mov r0, r4 */
/* @0x107a50 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107a54 vcmpe.f32 s18, s17 */
/* @0x107a58 vmrs APSR_nzcv, fpscr */
/* @0x107a5c vcmpe.f32 s21, s20 */
/* @0x107a60 vmovle.f32 s14, s17 */
/* @0x107a64 vmovle.f32 s17, s18 */
/* @0x107a68 vmovle.f32 s18, s14 */
/* @0x107a6c vmrs APSR_nzcv, fpscr */
/* @0x107a70 vmov s15, r0 */
/* @0x107a74 vmovle.f32 s14, s20 */
/* @0x107a78 vcmpe.f32 s19, s16 */
/* @0x107a7c vmovle.f32 s20, s21 */
/* @0x107a80 vmovle.f32 s21, s14 */
/* @0x107a84 vmrs APSR_nzcv, fpscr */
/* @0x107a88 vcmpe.f32 s22, s15 */
/* @0x107a8c vmovle.f32 s14, s16 */
/* @0x107a90 vmovle.f32 s16, s19 */
/* @0x107a94 vmovle.f32 s19, s14 */
/* @0x107a98 vmrs APSR_nzcv, fpscr */
/* @0x107a9c vcmpe.f32 s16, s17 */
/* @0x107aa0 vmovle.f32 s14, s15 */
/* @0x107aa4 vmovle.f32 s15, s22 */
/* @0x107aa8 vmovle.f32 s22, s14 */
/* @0x107aac vmrs APSR_nzcv, fpscr */
/* @0x107ab0 bhi 0x107ac0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x107ab4 vcmpe.f32 s19, s17 */
/* @0x107ab8 vmrs APSR_nzcv, fpscr */
/* @0x107abc bge 0x107c28 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x264> */
/* @0x107ac0 mov r3, #0 */
/* @0x107ac4 vcmpe.f32 s16, s18 */
/* @0x107ac8 vmrs APSR_nzcv, fpscr */
/* @0x107acc bhi 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x107ad0 vcmpe.f32 s19, s18 */
/* @0x107ad4 vmrs APSR_nzcv, fpscr */
/* @0x107ad8 bge 0x107bf4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x230> */
/* @0x107adc vcmpe.f32 s16, s17 */
/* @0x107ae0 vmrs APSR_nzcv, fpscr */
/* @0x107ae4 bhi 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x107ae8 vcmpe.f32 s19, s17 */
/* @0x107aec vmrs APSR_nzcv, fpscr */
/* @0x107af0 blt 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x107af4 vcmpe.f32 s15, s21 */
/* @0x107af8 vmrs APSR_nzcv, fpscr */
/* @0x107afc bhi 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x107b00 vcmpe.f32 s22, s21 */
/* @0x107b04 vmrs APSR_nzcv, fpscr */
/* @0x107b08 blt 0x107b30 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x16c> */
/* @0x107b0c orr r3, r3, #8 */
/* @0x107b10 cmp r3, #15 */
/* @0x107b14 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107b18 mov r3, #0 */
/* @0x107b1c mov r2, r3 */
/* @0x107b20 movt r3, #0x3ff0 */
/* @0x107b24 stm r5, {r2, r3} */
/* @0x107b28 vpop {d8, d9, d10, d11} */
/* @0x107b2c pop {r3, r4, r5, pc} */
/* @0x107b30 cmp r3, #0 */
/* @0x107b34 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107b38 vcmpe.f32 s16, s17 */
/* @0x107b3c vmrs APSR_nzcv, fpscr */
/* @0x107b40 blt 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x107b44 vcmpe.f32 s16, s18 */
/* @0x107b48 vmrs APSR_nzcv, fpscr */
/* @0x107b4c bhi 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x107b50 vcmpe.f32 s15, s20 */
/* @0x107b54 vmrs APSR_nzcv, fpscr */
/* @0x107b58 blt 0x107b6c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1a8> */
/* @0x107b5c vcmpe.f32 s15, s21 */
/* @0x107b60 vmrs APSR_nzcv, fpscr */
/* @0x107b64 movhi r3, #0 */
/* @0x107b68 movls r3, #1 */
/* @0x107b6c vcmpe.f32 s19, s17 */
/* @0x107b70 vmrs APSR_nzcv, fpscr */
/* @0x107b74 blt 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x107b78 vcmpe.f32 s19, s18 */
/* @0x107b7c vmrs APSR_nzcv, fpscr */
/* @0x107b80 bhi 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x107b84 vcmpe.f32 s15, s20 */
/* @0x107b88 vmrs APSR_nzcv, fpscr */
/* @0x107b8c blt 0x107b9c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1d8> */
/* @0x107b90 vcmpe.f32 s15, s21 */
/* @0x107b94 vmrs APSR_nzcv, fpscr */
/* @0x107b98 orrls r3, r3, #2 */
/* @0x107b9c vcmpe.f32 s22, s20 */
/* @0x107ba0 vmrs APSR_nzcv, fpscr */
/* @0x107ba4 blt 0x107bb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x1f0> */
/* @0x107ba8 vcmpe.f32 s22, s21 */
/* @0x107bac vmrs APSR_nzcv, fpscr */
/* @0x107bb0 orrls r3, r3, #4 */
/* @0x107bb4 vcmpe.f32 s16, s17 */
/* @0x107bb8 vmrs APSR_nzcv, fpscr */
/* @0x107bbc blt 0x107c48 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x284> */
/* @0x107bc0 vcmpe.f32 s16, s18 */
/* @0x107bc4 vmrs APSR_nzcv, fpscr */
/* @0x107bc8 bhi 0x107ddc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x418> */
/* @0x107bcc vcmpe.f32 s22, s20 */
/* @0x107bd0 vmrs APSR_nzcv, fpscr */
/* @0x107bd4 bge 0x107dcc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x408> */
/* @0x107bd8 cmp r3, #0 */
/* @0x107bdc beq 0x107c68 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2a4> */
/* @0x107be0 mov r2, #0 */
/* @0x107be4 mov r3, #1073741824 */
/* @0x107be8 stm r5, {r2, r3} */
/* @0x107bec vpop {d8, d9, d10, d11} */
/* @0x107bf0 pop {r3, r4, r5, pc} */
/* @0x107bf4 vcmpe.f32 s15, s20 */
/* @0x107bf8 vmrs APSR_nzcv, fpscr */
/* @0x107bfc bhi 0x107c0c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x248> */
/* @0x107c00 vcmpe.f32 s22, s20 */
/* @0x107c04 vmrs APSR_nzcv, fpscr */
/* @0x107c08 orrge r3, r3, #2 */
/* @0x107c0c vcmpe.f32 s15, s21 */
/* @0x107c10 vmrs APSR_nzcv, fpscr */
/* @0x107c14 bhi 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x107c18 vcmpe.f32 s22, s21 */
/* @0x107c1c vmrs APSR_nzcv, fpscr */
/* @0x107c20 orrge r3, r3, #4 */
/* @0x107c24 b 0x107adc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x118> */
/* @0x107c28 vcmpe.f32 s15, s20 */
/* @0x107c2c vmrs APSR_nzcv, fpscr */
/* @0x107c30 bhi 0x107ac0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x107c34 vcmpe.f32 s22, s20 */
/* @0x107c38 vmrs APSR_nzcv, fpscr */
/* @0x107c3c movlt r3, #0 */
/* @0x107c40 movge r3, #1 */
/* @0x107c44 b 0x107ac4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x100> */
/* @0x107c48 cmp r3, #0 */
/* @0x107c4c bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107c50 vcmpe.f32 s16, s17 */
/* @0x107c54 vmrs APSR_nzcv, fpscr */
/* @0x107c58 blt 0x107c84 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x107c5c vcmpe.f32 s16, s18 */
/* @0x107c60 vmrs APSR_nzcv, fpscr */
/* @0x107c64 bhi 0x107dc4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x400> */
/* @0x107c68 vcmpe.f32 s15, s20 */
/* @0x107c6c vmrs APSR_nzcv, fpscr */
/* @0x107c70 bhi 0x107dc4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x400> */
/* @0x107c74 vcmpe.f32 s22, s20 */
/* @0x107c78 vmrs APSR_nzcv, fpscr */
/* @0x107c7c movlt r3, #0 */
/* @0x107c80 movge r3, #1 */
/* @0x107c84 vcmpe.f32 s19, s17 */
/* @0x107c88 vmrs APSR_nzcv, fpscr */
/* @0x107c8c blt 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x107c90 vcmpe.f32 s19, s18 */
/* @0x107c94 vmrs APSR_nzcv, fpscr */
/* @0x107c98 bhi 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x107c9c vcmpe.f32 s15, s20 */
/* @0x107ca0 vmrs APSR_nzcv, fpscr */
/* @0x107ca4 bhi 0x107cb4 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2f0> */
/* @0x107ca8 vcmpe.f32 s22, s20 */
/* @0x107cac vmrs APSR_nzcv, fpscr */
/* @0x107cb0 orrge r3, r3, #2 */
/* @0x107cb4 vcmpe.f32 s15, s21 */
/* @0x107cb8 vmrs APSR_nzcv, fpscr */
/* @0x107cbc bhi 0x107ccc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x308> */
/* @0x107cc0 vcmpe.f32 s22, s21 */
/* @0x107cc4 vmrs APSR_nzcv, fpscr */
/* @0x107cc8 orrge r3, r3, #4 */
/* @0x107ccc vcmpe.f32 s16, s17 */
/* @0x107cd0 vmrs APSR_nzcv, fpscr */
/* @0x107cd4 blt 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338> */
/* @0x107cd8 vcmpe.f32 s16, s18 */
/* @0x107cdc vmrs APSR_nzcv, fpscr */
/* @0x107ce0 bhi 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338> */
/* @0x107ce4 vcmpe.f32 s15, s21 */
/* @0x107ce8 vmrs APSR_nzcv, fpscr */
/* @0x107cec bhi 0x107cfc <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x338> */
/* @0x107cf0 vcmpe.f32 s22, s21 */
/* @0x107cf4 vmrs APSR_nzcv, fpscr */
/* @0x107cf8 bge 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107cfc cmp r3, #0 */
/* @0x107d00 bne 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107d04 vcmpe.f32 s16, s17 */
/* @0x107d08 vmrs APSR_nzcv, fpscr */
/* @0x107d0c bhi 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107d10 vcmpe.f32 s19, s17 */
/* @0x107d14 vmrs APSR_nzcv, fpscr */
/* @0x107d18 blt 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107d1c vcmpe.f32 s15, s20 */
/* @0x107d20 vmrs APSR_nzcv, fpscr */
/* @0x107d24 blt 0x107d38 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x374> */
/* @0x107d28 vcmpe.f32 s15, s21 */
/* @0x107d2c vmrs APSR_nzcv, fpscr */
/* @0x107d30 movhi r3, #0 */
/* @0x107d34 movls r3, #1 */
/* @0x107d38 vcmpe.f32 s16, s18 */
/* @0x107d3c vmrs APSR_nzcv, fpscr */
/* @0x107d40 bhi 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x107d44 vcmpe.f32 s19, s18 */
/* @0x107d48 vmrs APSR_nzcv, fpscr */
/* @0x107d4c blt 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x107d50 vcmpe.f32 s15, s20 */
/* @0x107d54 vmrs APSR_nzcv, fpscr */
/* @0x107d58 blt 0x107d68 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3a4> */
/* @0x107d5c vcmpe.f32 s15, s21 */
/* @0x107d60 vmrs APSR_nzcv, fpscr */
/* @0x107d64 orrls r3, r3, #2 */
/* @0x107d68 vcmpe.f32 s22, s20 */
/* @0x107d6c vmrs APSR_nzcv, fpscr */
/* @0x107d70 blt 0x107d80 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3bc> */
/* @0x107d74 vcmpe.f32 s22, s21 */
/* @0x107d78 vmrs APSR_nzcv, fpscr */
/* @0x107d7c orrls r3, r3, #4 */
/* @0x107d80 vcmpe.f32 s16, s17 */
/* @0x107d84 vmrs APSR_nzcv, fpscr */
/* @0x107d88 bhi 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x107d8c vcmpe.f32 s19, s17 */
/* @0x107d90 vmrs APSR_nzcv, fpscr */
/* @0x107d94 blt 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x107d98 vcmpe.f32 s22, s20 */
/* @0x107d9c vmrs APSR_nzcv, fpscr */
/* @0x107da0 blt 0x107db0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x3ec> */
/* @0x107da4 vcmpe.f32 s22, s21 */
/* @0x107da8 vmrs APSR_nzcv, fpscr */
/* @0x107dac bls 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107db0 cmp r3, #0 */
/* @0x107db4 streq r3, [r5] */
/* @0x107db8 streq r3, [r5, #0x4] */
/* @0x107dbc beq 0x107bec <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x228> */
/* @0x107dc0 b 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107dc4 mov r3, #0 */
/* @0x107dc8 b 0x107c84 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x2c0> */
/* @0x107dcc vcmpe.f32 s22, s21 */
/* @0x107dd0 vmrs APSR_nzcv, fpscr */
/* @0x107dd4 bls 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */
/* @0x107dd8 b 0x107bd8 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x214> */
/* @0x107ddc cmp r3, #0 */
/* @0x107de0 beq 0x107c5c <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x298> */
/* @0x107de4 b 0x107be0 <_Z24F_Rectangle_In_RectangleR6RValueP9CInstanceS2_iPS_+0x21c> */

/* ── FUNC 0x107de8 · F_Rectangle_In_Circle(RValue&, CInstance*, CInstance*, int, RValue*) · size=360 · insn=90 */
/* @0x107de8 push {r4, r5, r6, lr} */
/* @0x107dec vpush {d8, d9, d10} */
/* @0x107df0 mov r5, #0 */
/* @0x107df4 ldr r4, [sp, #0x28] */
/* @0x107df8 mov r6, r0 */
/* @0x107dfc str r5, [r0, #0xc] */
/* @0x107e00 mov r1, r5 */
/* @0x107e04 mov r0, r4 */
/* @0x107e08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e0c mov r1, #1 */
/* @0x107e10 vmov s19, r0 */
/* @0x107e14 mov r0, r4 */
/* @0x107e18 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e1c mov r1, #2 */
/* @0x107e20 vmov s18, r0 */
/* @0x107e24 mov r0, r4 */
/* @0x107e28 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e2c mov r1, #3 */
/* @0x107e30 vmov s20, r0 */
/* @0x107e34 mov r0, r4 */
/* @0x107e38 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e3c mov r1, #4 */
/* @0x107e40 vmov s21, r0 */
/* @0x107e44 mov r0, r4 */
/* @0x107e48 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e4c mov r1, #5 */
/* @0x107e50 vmov s16, r0 */
/* @0x107e54 mov r0, r4 */
/* @0x107e58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e5c mov r1, #6 */
/* @0x107e60 vmov s17, r0 */
/* @0x107e64 mov r0, r4 */
/* @0x107e68 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107e6c vcmpe.f32 s19, s16 */
/* @0x107e70 vmrs APSR_nzcv, fpscr */
/* @0x107e74 vmovle.f32 s15, s16 */
/* @0x107e78 vmovgt.f32 s15, s19 */
/* @0x107e7c vcmp.f32 s15, s20 */
/* @0x107e80 vmrs APSR_nzcv, fpscr */
/* @0x107e84 vcmpe.f32 s18, s17 */
/* @0x107e88 vmovgt.f32 s15, s20 */
/* @0x107e8c vmrs APSR_nzcv, fpscr */
/* @0x107e90 vmovle.f32 s14, s17 */
/* @0x107e94 vmovgt.f32 s14, s18 */
/* @0x107e98 vcmp.f32 s14, s21 */
/* @0x107e9c vmrs APSR_nzcv, fpscr */
/* @0x107ea0 vmovgt.f32 s14, s21 */
/* @0x107ea4 vsub.f32 s14, s14, s17 */
/* @0x107ea8 vmov s12, r0 */
/* @0x107eac vmul.f32 s14, s14, s14 */
/* @0x107eb0 vsub.f32 s15, s15, s16 */
/* @0x107eb4 vmla.f32 s14, s15, s15 */
/* @0x107eb8 vmul.f32 s15, s12, s12 */
/* @0x107ebc vcmpe.f32 s15, s14 */
/* @0x107ec0 vmrs APSR_nzcv, fpscr */
/* @0x107ec4 strlt r5, [r6] */
/* @0x107ec8 strlt r5, [r6, #0x4] */
/* @0x107ecc blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x107ed0 vsub.f32 s19, s19, s16 */
/* @0x107ed4 mov r3, #1073741824 */
/* @0x107ed8 str r5, [r6] */
/* @0x107edc str r3, [r6, #0x4] */
/* @0x107ee0 vsub.f32 s18, s18, s17 */
/* @0x107ee4 vmul.f32 s19, s19, s19 */
/* @0x107ee8 vmul.f32 s18, s18, s18 */
/* @0x107eec vadd.f32 s14, s19, s18 */
/* @0x107ef0 vcmpe.f32 s15, s14 */
/* @0x107ef4 vmrs APSR_nzcv, fpscr */
/* @0x107ef8 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x107efc vsub.f32 s16, s20, s16 */
/* @0x107f00 vmul.f32 s16, s16, s16 */
/* @0x107f04 vadd.f32 s18, s18, s16 */
/* @0x107f08 vcmpe.f32 s15, s18 */
/* @0x107f0c vmrs APSR_nzcv, fpscr */
/* @0x107f10 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x107f14 vsub.f32 s17, s21, s17 */
/* @0x107f18 vmul.f32 s17, s17, s17 */
/* @0x107f1c vadd.f32 s16, s16, s17 */
/* @0x107f20 vcmpe.f32 s15, s16 */
/* @0x107f24 vmrs APSR_nzcv, fpscr */
/* @0x107f28 blt 0x107f48 <_Z21F_Rectangle_In_CircleR6RValueP9CInstanceS2_iPS_+0x160> */
/* @0x107f2c vadd.f32 s17, s19, s17 */
/* @0x107f30 vcmpe.f32 s15, s17 */
/* @0x107f34 vmrs APSR_nzcv, fpscr */
/* @0x107f38 movge r3, #0 */
/* @0x107f3c strge r5, [r6] */
/* @0x107f40 movtge r3, #0x3ff0 */
/* @0x107f44 strge r3, [r6, #0x4] */
/* @0x107f48 vpop {d8, d9, d10} */
/* @0x107f4c pop {r4, r5, r6, pc} */

/* ── FUNC 0x107f50 · F_PlaceEmpty(RValue&, CInstance*, CInstance*, int, RValue*) · size=100 · insn=25 */
/* @0x107f50 push {r4, r5, r6, r7, r8, lr} */
/* @0x107f54 mov r5, #0 */
/* @0x107f58 ldr r6, [sp, #0x18] */
/* @0x107f5c mov r4, r0 */
/* @0x107f60 str r5, [r0, #0xc] */
/* @0x107f64 mov r8, r1 */
/* @0x107f68 mov r1, r5 */
/* @0x107f6c mov r0, r6 */
/* @0x107f70 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107f74 mov r1, #1 */
/* @0x107f78 mov r7, r0 */
/* @0x107f7c mov r0, r6 */
/* @0x107f80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x107f84 mov r1, r7 */
/* @0x107f88 mov r2, r0 */
/* @0x107f8c mov r0, r8 */
/* @0x107f90 bl 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */
/* @0x107f94 cmp r0, #0 */
/* @0x107f98 moveq r5, r0 */
/* @0x107f9c movne r3, r5 */
/* @0x107fa0 moveq r3, r5 */
/* @0x107fa4 movtne r3, #0x3ff0 */
/* @0x107fa8 str r5, [r4] */
/* @0x107fac str r3, [r4, #0x4] */
/* @0x107fb0 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x107fb4 · F_PlaceMeeting(RValue&, CInstance*, CInstance*, int, RValue*) · size=192 · insn=48 */
/* @0x107fb4 push {r4, r5, r6, r7, r8, lr} */
/* @0x107fb8 mov r3, #0 */
/* @0x107fbc ldr r6, [sp, #0x18] */
/* @0x107fc0 mov r7, r1 */
/* @0x107fc4 str r3, [r0, #0xc] */
/* @0x107fc8 mov r5, r0 */
/* @0x107fcc mov r1, #2 */
/* @0x107fd0 mov r8, r2 */
/* @0x107fd4 mov r0, r6 */
/* @0x107fd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x107fdc adds r3, r7, #0 */
/* @0x107fe0 movne r3, #1 */
/* @0x107fe4 cmn r0, #1 */
/* @0x107fe8 mov r4, r0 */
/* @0x107fec movne r3, #0 */
/* @0x107ff0 cmp r3, #0 */
/* @0x107ff4 ldrne r4, [r7, #0x78] */
/* @0x107ff8 adds r3, r8, #0 */
/* @0x107ffc movne r3, #1 */
/* @0x108000 cmn r4, #2 */
/* @0x108004 movne r3, #0 */
/* @0x108008 cmp r3, #0 */
/* @0x10800c ldrne r4, [r8, #0x78] */
/* @0x108010 cmn r4, #4 */
/* @0x108014 beq 0x108064 <_Z14F_PlaceMeetingR6RValueP9CInstanceS2_iPS_+0xb0> */
/* @0x108018 mov r1, #0 */
/* @0x10801c mov r0, r6 */
/* @0x108020 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108024 mov r1, #1 */
/* @0x108028 mov r8, r0 */
/* @0x10802c mov r0, r6 */
/* @0x108030 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108034 mov r1, r4 */
/* @0x108038 mov r2, r8 */
/* @0x10803c mov r3, r0 */
/* @0x108040 mov r0, r7 */
/* @0x108044 bl 0x1ca9f8 <_Z17Command_IsMeetingP9CInstanceiff> */
/* @0x108048 cmp r0, #0 */
/* @0x10804c movne r3, #0 */
/* @0x108050 moveq r3, r0 */
/* @0x108054 movne r0, r3 */
/* @0x108058 movtne r3, #0x3ff0 */
/* @0x10805c stm r5, {r0, r3} */
/* @0x108060 pop {r4, r5, r6, r7, r8, pc} */
/* @0x108064 mov r3, #0 */
/* @0x108068 str r3, [r5] */
/* @0x10806c str r3, [r5, #0x4] */
/* @0x108070 pop {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x108074 · anon_108074 · size=4 · insn=1 */
/* @0x108074 andeq r0, r0, r0 */

/* ── FUNC 0x108078 · F_PlaceSnapped(RValue&, CInstance*, CInstance*, int, RValue*) · size=232 · insn=58 */
/* @0x108078 push {r4, r5, r6, lr} */
/* @0x10807c vpush {d8, d9, d10} */
/* @0x108080 mov r3, #0 */
/* @0x108084 ldr r5, [sp, #0x28] */
/* @0x108088 mov r4, r0 */
/* @0x10808c str r3, [r0, #0xc] */
/* @0x108090 mov r6, r1 */
/* @0x108094 str r3, [r0] */
/* @0x108098 mov r1, r3 */
/* @0x10809c str r3, [r4, #0x4] */
/* @0x1080a0 mov r0, r5 */
/* @0x1080a4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1080a8 vmov d8, r0, r1 */
/* @0x1080ac mov r0, r5 */
/* @0x1080b0 mov r1, #1 */
/* @0x1080b4 bl 0xceb24 <_Z9YYGetRealPK6RValuei> */
/* @0x1080b8 vcmpe.f64 d8, #0 */
/* @0x1080bc vmrs APSR_nzcv, fpscr */
/* @0x1080c0 vmov d9, r0, r1 */
/* @0x1080c4 ble 0x1080fc <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0x84> */
/* @0x1080c8 vldr s20, [r6, #180] */
/* @0x1080cc vcvt.f64.f32 d10, s20 */
/* @0x1080d0 vdiv.f64 d7, d10, d8 */
/* @0x1080d4 vmov r0, r1, d7 */
/* @0x1080d8 bl 0xb66e8 <lrint@plt> */
/* @0x1080dc vldr d7, [pc, #116] */
/* @0x1080e0 vmov s11, r0 */
/* @0x1080e4 vcvt.f64.s32 d6, s11 */
/* @0x1080e8 vmls.f64 d10, d6, d8 */
/* @0x1080ec vabs.f64 d10, d10 */
/* @0x1080f0 vcmpe.f64 d10, d7 */
/* @0x1080f4 vmrs APSR_nzcv, fpscr */
/* @0x1080f8 bge 0x10814c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x1080fc vcmpe.f64 d9, #0 */
/* @0x108100 vmrs APSR_nzcv, fpscr */
/* @0x108104 ble 0x10813c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xc4> */
/* @0x108108 vldr s16, [r6, #184] */
/* @0x10810c vcvt.f64.f32 d8, s16 */
/* @0x108110 vdiv.f64 d7, d8, d9 */
/* @0x108114 vmov r0, r1, d7 */
/* @0x108118 bl 0xb66e8 <lrint@plt> */
/* @0x10811c vldr d7, [pc, #52] */
/* @0x108120 vmov s11, r0 */
/* @0x108124 vcvt.f64.s32 d6, s11 */
/* @0x108128 vmls.f64 d8, d6, d9 */
/* @0x10812c vabs.f64 d8, d8 */
/* @0x108130 vcmpe.f64 d8, d7 */
/* @0x108134 vmrs APSR_nzcv, fpscr */
/* @0x108138 bge 0x10814c <_Z14F_PlaceSnappedR6RValueP9CInstanceS2_iPS_+0xd4> */
/* @0x10813c mov r3, #0 */
/* @0x108140 mov r2, r3 */
/* @0x108144 movt r3, #0x3ff0 */
/* @0x108148 stm r4, {r2, r3} */
/* @0x10814c vpop {d8, d9, d10} */
/* @0x108150 pop {r4, r5, r6, pc} */
/* @0x108154 nop */
/* @0x108158 rscsle r10, r1, #252, #18 */
/* @0x10815c svclo #0x50624d */

/* ── FUNC 0x108160 · F_MoveSnap(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x108160 push {r4, r5, r6, lr} */
/* @0x108164 mov r6, r1 */
/* @0x108168 ldr r4, [sp, #0x10] */
/* @0x10816c mov r1, #0 */
/* @0x108170 mov r0, r4 */
/* @0x108174 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108178 mov r1, #1 */
/* @0x10817c mov r5, r0 */
/* @0x108180 mov r0, r4 */
/* @0x108184 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108188 mov r1, r5 */
/* @0x10818c mov r2, r0 */
/* @0x108190 mov r0, r6 */
/* @0x108194 pop {r4, r5, r6, lr} */
/* @0x108198 b 0x1c9594 <_Z12Command_SnapP9CInstanceff> */

/* ── FUNC 0x10819c · F_MoveTowardsPoint(RValue&, CInstance*, CInstance*, int, RValue*) · size=80 · insn=20 */
/* @0x10819c push {r4, r5, r6, r7, r8, lr} */
/* @0x1081a0 mov r7, r1 */
/* @0x1081a4 ldr r4, [sp, #0x18] */
/* @0x1081a8 mov r1, #0 */
/* @0x1081ac mov r0, r4 */
/* @0x1081b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081b4 mov r1, #1 */
/* @0x1081b8 mov r6, r0 */
/* @0x1081bc mov r0, r4 */
/* @0x1081c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081c4 mov r1, #2 */
/* @0x1081c8 mov r5, r0 */
/* @0x1081cc mov r0, r4 */
/* @0x1081d0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1081d4 mov r1, r6 */
/* @0x1081d8 mov r2, r5 */
/* @0x1081dc mov r3, r0 */
/* @0x1081e0 mov r0, r7 */
/* @0x1081e4 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1081e8 b 0x1c97ec <_Z19Command_MoveTowardsP9CInstancefff> */

/* ── FUNC 0x1081ec · F_MoveWrap(RValue&, CInstance*, CInstance*, int, RValue*) · size=400 · insn=100 */
/* @0x1081ec push {r4, r5, r6, r7, r8, lr} */
/* @0x1081f0 vpush {d8} */
/* @0x1081f4 mov r5, r1 */
/* @0x1081f8 ldr r4, [sp, #0x20] */
/* @0x1081fc mov r1, #0 */
/* @0x108200 ldr r6, [pc, #0x16c] */
/* @0x108204 mov r0, r4 */
/* @0x108208 add r6, pc, r6 */
/* @0x10820c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108210 mov r1, #1 */
/* @0x108214 mov r8, r0 */
/* @0x108218 mov r0, r4 */
/* @0x10821c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108220 mov r1, #2 */
/* @0x108224 mov r7, r0 */
/* @0x108228 mov r0, r4 */
/* @0x10822c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108230 cmp r8, #0 */
/* @0x108234 vmov s16, r0 */
/* @0x108238 beq 0x108278 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10823c vldr s14, [pc, #300] */
/* @0x108240 vsub.f32 s14, s14, s16 */
/* @0x108244 vldr s15, [r5, #180] */
/* @0x108248 ldr r3, [pc, #0x128] */
/* @0x10824c vcmpe.f32 s15, s14 */
/* @0x108250 vmrs APSR_nzcv, fpscr */
/* @0x108254 bmi 0x10833c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x150> */
/* @0x108258 ldr r4, [r6, r3] */
/* @0x10825c ldr r3, [r4] */
/* @0x108260 vldr s14, [r3, #16] */
/* @0x108264 vcvt.f32.s32 s14, s14 */
/* @0x108268 vadd.f32 s13, s14, s16 */
/* @0x10826c vcmpe.f32 s13, s15 */
/* @0x108270 vmrs APSR_nzcv, fpscr */
/* @0x108274 bmi 0x10831c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x130> */
/* @0x108278 cmp r7, #0 */
/* @0x10827c beq 0x1082e0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x108280 vldr s14, [pc, #232] */
/* @0x108284 vsub.f32 s14, s14, s16 */
/* @0x108288 vldr s15, [r5, #184] */
/* @0x10828c ldr r3, [pc, #0xe4] */
/* @0x108290 vcmpe.f32 s15, s14 */
/* @0x108294 vmrs APSR_nzcv, fpscr */
/* @0x108298 bmi 0x1082e8 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xfc> */
/* @0x10829c ldr r4, [r6, r3] */
/* @0x1082a0 ldr r3, [r4] */
/* @0x1082a4 vldr s14, [r3, #20] */
/* @0x1082a8 vcvt.f32.s32 s14, s14 */
/* @0x1082ac vadd.f32 s13, s14, s16 */
/* @0x1082b0 vcmpe.f32 s13, s15 */
/* @0x1082b4 vmrs APSR_nzcv, fpscr */
/* @0x1082b8 bpl 0x1082e0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xf4> */
/* @0x1082bc vsub.f32 s15, s15, s14 */
/* @0x1082c0 mov r0, r5 */
/* @0x1082c4 ldr r1, [r5, #0xb4] */
/* @0x1082c8 vadd.f32 s16, s16, s16 */
/* @0x1082cc vsub.f32 s16, s15, s16 */
/* @0x1082d0 vmov r2, s16 */
/* @0x1082d4 vpop {d8} */
/* @0x1082d8 pop {r4, r5, r6, r7, r8, lr} */
/* @0x1082dc b 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1082e0 vpop {d8} */
/* @0x1082e4 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1082e8 ldr r4, [r6, r3] */
/* @0x1082ec vadd.f32 s14, s16, s16 */
/* @0x1082f0 mov r0, r5 */
/* @0x1082f4 ldr r1, [r5, #0xb4] */
/* @0x1082f8 ldr r3, [r4] */
/* @0x1082fc vldr s13, [r3, #20] */
/* @0x108300 vcvt.f32.s32 s13, s13 */
/* @0x108304 vadd.f32 s15, s15, s13 */
/* @0x108308 vadd.f32 s14, s15, s14 */
/* @0x10830c vmov r2, s14 */
/* @0x108310 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x108314 vldr s15, [r5, #184] */
/* @0x108318 b 0x1082a0 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0xb4> */
/* @0x10831c vsub.f32 s15, s15, s14 */
/* @0x108320 mov r0, r5 */
/* @0x108324 ldr r2, [r5, #0xb8] */
/* @0x108328 vadd.f32 s13, s16, s16 */
/* @0x10832c vsub.f32 s13, s15, s13 */
/* @0x108330 vmov r1, s13 */
/* @0x108334 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x108338 b 0x108278 <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x8c> */
/* @0x10833c ldr r4, [r6, r3] */
/* @0x108340 vadd.f32 s14, s16, s16 */
/* @0x108344 mov r0, r5 */
/* @0x108348 ldr r2, [r5, #0xb8] */
/* @0x10834c ldr r3, [r4] */
/* @0x108350 vldr s13, [r3, #16] */
/* @0x108354 vcvt.f32.s32 s13, s13 */
/* @0x108358 vadd.f32 s15, s15, s13 */
/* @0x10835c vadd.f32 s14, s15, s14 */
/* @0x108360 vmov r1, s14 */
/* @0x108364 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x108368 vldr s15, [r5, #180] */
/* @0x10836c b 0x10825c <_Z10F_MoveWrapR6RValueP9CInstanceS2_iPS_+0x70> */
/* @0x108370 andeq r0, r0, r0 */
/* @0x108374 eoreq r9, lr, r8, asr #20 */
/* @0x108378 .word 0xffffbcd8 */

/* ── FUNC 0x10837c · F_MoveBounceSolid(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x10837c push {r4, lr} */
/* @0x108380 mov r4, r1 */
/* @0x108384 ldr r0, [sp, #0x8] */
/* @0x108388 mov r1, #0 */
/* @0x10838c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x108390 mov r2, #0 */
/* @0x108394 mov r1, r0 */
/* @0x108398 mov r0, r4 */
/* @0x10839c pop {r4, lr} */
/* @0x1083a0 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */

/* ── FUNC 0x1083a4 · F_MoveBounceAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=40 · insn=10 */
/* @0x1083a4 push {r4, lr} */
/* @0x1083a8 mov r4, r1 */
/* @0x1083ac ldr r0, [sp, #0x8] */
/* @0x1083b0 mov r1, #0 */
/* @0x1083b4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1083b8 mov r2, #1 */
/* @0x1083bc mov r1, r0 */
/* @0x1083c0 mov r0, r4 */
/* @0x1083c4 pop {r4, lr} */
/* @0x1083c8 b 0x1cafa0 <_Z14Command_BounceP9CInstancebb> */

/* ── FUNC 0x1083cc · F_MoveContactSolid(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x1083cc push {r4, r5, r6, lr} */
/* @0x1083d0 mov r6, r1 */
/* @0x1083d4 ldr r4, [sp, #0x10] */
/* @0x1083d8 mov r1, #0 */
/* @0x1083dc mov r0, r4 */
/* @0x1083e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1083e4 mov r1, #1 */
/* @0x1083e8 mov r5, r0 */
/* @0x1083ec mov r0, r4 */
/* @0x1083f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1083f4 mov r1, r5 */
/* @0x1083f8 mov r3, #0 */
/* @0x1083fc mov r2, r0 */
/* @0x108400 mov r0, r6 */
/* @0x108404 pop {r4, r5, r6, lr} */
/* @0x108408 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb> */

/* ── FUNC 0x10840c · F_MoveContactAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x10840c push {r4, r5, r6, lr} */
/* @0x108410 mov r6, r1 */
/* @0x108414 ldr r4, [sp, #0x10] */
/* @0x108418 mov r1, #0 */
/* @0x10841c mov r0, r4 */
/* @0x108420 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108424 mov r1, #1 */
/* @0x108428 mov r5, r0 */
/* @0x10842c mov r0, r4 */
/* @0x108430 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108434 mov r1, r5 */
/* @0x108438 mov r3, #1 */
/* @0x10843c mov r2, r0 */
/* @0x108440 mov r0, r6 */
/* @0x108444 pop {r4, r5, r6, lr} */
/* @0x108448 b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb> */

/* ── FUNC 0x10844c · F_MoveOutsideSolid(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x10844c push {r4, r5, r6, lr} */
/* @0x108450 mov r6, r1 */
/* @0x108454 ldr r4, [sp, #0x10] */
/* @0x108458 mov r1, #0 */
/* @0x10845c mov r0, r4 */
/* @0x108460 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108464 mov r1, #1 */
/* @0x108468 mov r5, r0 */
/* @0x10846c mov r0, r4 */
/* @0x108470 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108474 mov r1, r5 */
/* @0x108478 mov r3, #0 */
/* @0x10847c mov r2, r0 */
/* @0x108480 mov r0, r6 */
/* @0x108484 pop {r4, r5, r6, lr} */
/* @0x108488 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb> */

/* ── FUNC 0x10848c · F_MoveOutsideAll(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x10848c push {r4, r5, r6, lr} */
/* @0x108490 mov r6, r1 */
/* @0x108494 ldr r4, [sp, #0x10] */
/* @0x108498 mov r1, #0 */
/* @0x10849c mov r0, r4 */
/* @0x1084a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1084a4 mov r1, #1 */
/* @0x1084a8 mov r5, r0 */
/* @0x1084ac mov r0, r4 */
/* @0x1084b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1084b4 mov r1, r5 */
/* @0x1084b8 mov r3, #1 */
/* @0x1084bc mov r2, r0 */
/* @0x1084c0 mov r0, r6 */
/* @0x1084c4 pop {r4, r5, r6, lr} */
/* @0x1084c8 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb> */

/* ── FUNC 0x1084cc · F_MoveContact(RValue&, CInstance*, CInstance*, int, RValue*) · size=84 · insn=21 */
/* @0x1084cc push {r4, r5, r6, lr} */
/* @0x1084d0 mov r4, r1 */
/* @0x1084d4 ldr r0, [sp, #0x10] */
/* @0x1084d8 mov r1, #0 */
/* @0x1084dc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1084e0 ldr r1, [r4, #0xb4] */
/* @0x1084e4 ldr r2, [r4, #0xb8] */
/* @0x1084e8 mov r5, r0 */
/* @0x1084ec mov r0, r4 */
/* @0x1084f0 bl 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1084f4 mov r2, #0 */
/* @0x1084f8 mov r1, r5 */
/* @0x1084fc movt r2, #0xbf80 */
/* @0x108500 subs r3, r0, #0 */
/* @0x108504 mov r0, r4 */
/* @0x108508 bne 0x108514 <_Z13F_MoveContactR6RValueP9CInstanceS2_iPS_+0x48> */
/* @0x10850c pop {r4, r5, r6, lr} */
/* @0x108510 b 0x1cae64 <_Z19Command_MoveOutsideP9CInstanceffb> */
/* @0x108514 mov r3, #0 */
/* @0x108518 pop {r4, r5, r6, lr} */
/* @0x10851c b 0x1cad28 <_Z19Command_MoveContactP9CInstanceffb> */

/* ── FUNC 0x108520 · F_MotionSet(RValue&, CInstance*, CInstance*, int, RValue*) · size=64 · insn=16 */
/* @0x108520 push {r3, r4, r5, lr} */
/* @0x108524 mov r4, r1 */
/* @0x108528 ldr r5, [sp, #0x10] */
/* @0x10852c mov r1, #0 */
/* @0x108530 mov r0, r5 */
/* @0x108534 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108538 mov r1, r0 */
/* @0x10853c mov r0, r4 */
/* @0x108540 bl 0x193064 <_ZN9CInstance12SetDirectionEf> */
/* @0x108544 mov r0, r5 */
/* @0x108548 mov r1, #1 */
/* @0x10854c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108550 mov r1, r0 */
/* @0x108554 mov r0, r4 */
/* @0x108558 pop {r3, r4, r5, lr} */
/* @0x10855c b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */

/* ── FUNC 0x108560 · F_MotionAdd(RValue&, CInstance*, CInstance*, int, RValue*) · size=60 · insn=15 */
/* @0x108560 push {r4, r5, r6, lr} */
/* @0x108564 mov r6, r1 */
/* @0x108568 ldr r4, [sp, #0x10] */
/* @0x10856c mov r1, #0 */
/* @0x108570 mov r0, r4 */
/* @0x108574 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108578 mov r1, #1 */
/* @0x10857c mov r5, r0 */
/* @0x108580 mov r0, r4 */
/* @0x108584 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x108588 mov r1, r5 */
/* @0x10858c mov r2, r0 */
/* @0x108590 mov r0, r6 */
/* @0x108594 pop {r4, r5, r6, lr} */
/* @0x108598 b 0x193ec0 <_ZN9CInstance11AddTo_SpeedEff> */

/* ── FUNC 0x10859c · anon_10859c · size=4 · insn=1 */
/* @0x10859c andeq r0, r0, r0 */
