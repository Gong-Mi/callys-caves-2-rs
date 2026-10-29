/* cally 逆向卡：All_39 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 50 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/50 Buffer_Network::Read(eBuffer_Type, RValue*)  0xcb324  size 628  157 条（0xcb324..0xcb598）
 * @func 0xcb324 0xcb598  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Buffer_Network::Read(eBuffer_Type, RValue*)+0xe8 / __floatundidf / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / 0xb65bc / YYCreateString(RValue*, char const*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0xc×11 / 0x1c×8 / 0x4×5 / 0x10×2 / 0x24×1 / 0x14×1 / 0x64×1
 * VFP 指令 14 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcb324 push {r4, r5, r6, r7, r8, lr}
 *   @0xcb328 mov r4, #0
 *   @0xcb32c mov r7, r2
 *   @0xcb330 str r4, [r2]
 *   @0xcb334 str r4, [r2, #0x4]
 *   @0xcb338 sub sp, sp, #8
 *   @0xcb33c ldr r3, [r0, #0x1c]
 *   @0xcb340 mov r6, r0
 *   @0xcb344 ldr r2, [r0, #0x10]
 *   @0xcb348 str r4, [r7, #0xc]
 *   @0xcb34c cmp r3, r2
 *   @0xcb350 bge 0xcb58c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x268>
 *   @0xcb354 ldr r2, [r0, #0x24]
 *   @0xcb358 cmp r1, #11
 *   @0xcb35c cmpne r1, #13
 *   @0xcb360 ldr r0, [r0, #0x14]
 *   @0xcb364 add r3, r3, r2
 *   @0xcb368 sub r12, r0, #1
 *   @0xcb36c rsb r0, r0, #0
 *   @0xcb370 add r3, r3, r12
 *   @0xcb374 and r3, r3, r0
 *   @0xcb378 rsb r3, r2, r3
 *   @0xcb37c str r3, [r6, #0x1c]
 *   @0xcb380 beq 0xcb518 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x1f4>
 *   @0xcb384 sub r1, r1, #1
 *   @0xcb388 cmp r1, #11
 *   @0xcb38c addls pc, pc, r1, lsl #2
 *   @0xcb390 b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260>
 *   @0xcb394 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcb398 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcb39c b 0xcb41c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf8>
 *   @0xcb3a0 b 0xcb434 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x110>
 *   @0xcb3a4 b 0xcb45c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x138>
 *   @0xcb3a8 b 0xcb488 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x164>
 *   @0xcb3ac b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260>
 *   @0xcb3b0 b 0xcb4a0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x17c>
 *   @0xcb3b4 b 0xcb4b8 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x194>
 *   @0xcb3b8 b 0xcb3c4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xa0>
 *   @0xcb3bc b 0xcb584 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x260>
 *   @0xcb3c0 b 0xcb4e4 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x1c0>
 *   @0xcb3c4 ldr r2, [r6, #0xc]
 *   @0xcb3c8 mov r12, #1
 *   @0xcb3cc ldrb r2, [r2, r3]
 *   @0xcb3d0 vmov s15, r2
 *   @0xcb3d4 vcvt.f64.u32 d7, s15
 *   @0xcb3d8 vmov r2, r3, d7
 *   @0xcb3dc stm r7, {r2, r3}
 *   @0xcb3e0 ldr r3, [r6, #0x1c]
 *   @0xcb3e4 ldr r2, [r6, #0x10]
 *   @0xcb3e8 add r3, r12, r3
 *   @0xcb3ec cmp r3, r2
 *   @0xcb3f0 ble 0xcb40c <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xe8>
 *   @0xcb3f4 mov r3, #0
 *   @0xcb3f8 mov r2, r3
 *   @0xcb3fc movt r3, #0xc008
 *   @0xcb400 stm r7, {r2, r3}
 *   @0xcb404 ldr r3, [r6, #0x1c]
 *   @0xcb408 add r3, r12, r3
 *   @0xcb40c mov r0, #0
 *   @0xcb410 str r3, [r6, #0x1c]
 *   @0xcb414 add sp, sp, #8
 *   @0xcb418 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcb41c ldr r2, [r6, #0xc]
 *   @0xcb420 ldrh r2, [r2, r3]
 *   @0xcb424 rev16 r2, r2
 *   @0xcb428 mov r12, #2
 *   @0xcb42c uxth r2, r2
 *   @0xcb430 b 0xcb3d0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xac>
 *   @0xcb434 ldr r2, [r6, #0xc]
 *   @0xcb438 ldrh r2, [r2, r3]
 *   @0xcb43c rev16 r2, r2
 *   @0xcb440 sxth r2, r2
 *   @0xcb444 mov r12, #2
 *   @0xcb448 vmov s15, r2
 *   @0xcb44c vcvt.f64.s32 d7, s15
 *   @0xcb450 vmov r2, r3, d7
 *   @0xcb454 stm r7, {r2, r3}
 *   @0xcb458 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc>
 *   @0xcb45c ldr r2, [r6, #0xc]
 *   @0xcb460 ldr r4, [r2, r3]
 *   @0xcb464 rev r4, r4
 *   @0xcb468 vmov s15, r4
 *   @0xcb46c vcvt.f64.u32 d7, s15
 *   @0xcb470 vmov r4, r5, d7
 *   @0xcb474 mov r12, #4
 *   @0xcb478 vmov r2, s14
 *   @0xcb47c mov r3, r5
 *   @0xcb480 stm r7, {r2, r3}
 *   @0xcb484 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc>
 *   @0xcb488 ldr r2, [r6, #0xc]
 *   @0xcb48c ldr r4, [r2, r3]
 *   @0xcb490 rev r4, r4
 *   @0xcb494 vmov s15, r4
 *   @0xcb498 vcvt.f64.s32 d7, s15
 *   @0xcb49c b 0xcb470 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x14c>
 *   @0xcb4a0 ldr r2, [r6, #0xc]
 *   @0xcb4a4 ldr r4, [r2, r3]
 *   @0xcb4a8 rev r4, r4
 *   @0xcb4ac vmov s15, r4
 *   @0xcb4b0 vcvt.f64.f32 d7, s15
 *   @0xcb4b4 b 0xcb470 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0x14c>
 *   @0xcb4b8 ldr r2, [r6, #0xc]
 *   @0xcb4bc add r1, r2, r3
 *   @0xcb4c0 ldr r3, [r2, r3]
 *   @0xcb4c4 rev r3, r3
 *   @0xcb4c8 str r3, [sp]
 *   @0xcb4cc ldr r2, [r1, #0x4]
 *   @0xcb4d0 rev r2, r2
 *   @0xcb4d4 mov r12, #8
 *   @0xcb4d8 str r3, [r7]
 *   @0xcb4dc str r2, [r7, #0x4]
 *   @0xcb4e0 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc>
 *   @0xcb4e4 ldr r2, [r6, #0xc]
 *   @0xcb4e8 add r1, r2, r3
 *   @0xcb4ec ldr r3, [r2, r3]
 *   @0xcb4f0 rev r3, r3
 *   @0xcb4f4 str r3, [sp]
 *   @0xcb4f8 ldr r3, [r1, #0x4]
 *   @0xcb4fc rev r3, r3
 *   @0xcb500 str r3, [sp, #0x4]
 *   @0xcb504 ldrd r0, r1, [sp]
 *   @0xcb508 bl 0x319150 <__floatundidf>
 *   @0xcb50c mov r12, #8
 *   @0xcb510 stm r7, {r0, r1}
 *   @0xcb514 b 0xcb3e0 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xbc>
 *   @0xcb518 ldr r0, [r6, #0xc]
 *   @0xcb51c add r0, r0, r3
 *   @0xcb520 bl 0xb6538 <strlen@plt>
 *   @0xcb524 mov r3, #1
 *   @0xcb528 ldr r1, [pc, #0x64]
 *   @0xcb52c mov r2, #158
 *   @0xcb530 add r1, pc, r1
 *   @0xcb534 add r5, r0, r3
 *   @0xcb538 mov r0, r5
 *   @0xcb53c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xcb540 ldr r3, [r6, #0x1c]
 *   @0xcb544 ldr r1, [r6, #0xc]
 *   @0xcb548 mov r2, r5
 *   @0xcb54c add r1, r1, r3
 *   @0xcb550 mov r8, r0
 *   @0xcb554 bl 0xb65bc <memcpy@plt>
 *   @0xcb558 mov r0, r7
 *   @0xcb55c mov r1, r8
 *   @0xcb560 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0xcb564 mov r0, r8
 *   @0xcb568 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xcb56c ldr r3, [r6, #0x1c]
 *   @0xcb570 mov r0, r4
 *   @0xcb574 add r5, r3, r5
 *   @0xcb578 str r5, [r6, #0x1c]
 *   @0xcb57c add sp, sp, #8
 *   @0xcb580 pop {r4, r5, r6, r7, r8, pc}
 *   @0xcb584 mvn r0, #0
 *   @0xcb588 b 0xcb414 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf0>
 *   @0xcb58c mvn r0, #1
 *   @0xcb590 b 0xcb414 <_ZN14Buffer_Network4ReadE12eBuffer_TypeP6RValue+0xf0>
 *   @0xcb594 eoreq r6, r6, r4, lsl #24
 *
 * ══ §2/50 F_ArraySetPre(RValue&, CInstance*, CInstance*, int, RValue*)  0x112cd8  size 628  157 条（0x112cd8..0x112f4c）
 * @func 0x112cd8 0x112f4c  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYFree(void const*)×3 / operator delete(void*)×3 / YYGetInt32(RValue const*, int) / SET_RValue_Array(RValue*, RValue*, int) / GetContextStackTop() / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x20×7 / 0x8×6 / 0x4×6 / 0xc×4 / 0x2c×2 / 0x18×1 / 0x244×1 / 0x238×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x112cd8 push {r3, r4, r5, r6, r7, lr}
 *   @0x112cdc cmp r3, #3
 *   @0x112ce0 ldr r4, [sp, #0x18]
 *   @0x112ce4 mov r5, r0
 *   @0x112ce8 ldr r3, [r4, #0xc]
 *   @0x112cec beq 0x112d18 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x112cf0 cmp r3, #2
 *   @0x112cf4 beq 0x112d08 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x112cf8 ldr r0, [pc, #0x244]
 *   @0x112cfc pop {r3, r4, r5, r6, r7, lr}
 *   @0x112d00 add r0, pc, r0
 *   @0x112d04 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x112d08 ldr r0, [pc, #0x238]
 *   @0x112d0c pop {r3, r4, r5, r6, r7, lr}
 *   @0x112d10 add r0, pc, r0
 *   @0x112d14 b 0xd547c <_Z7YYErrorPKcz>
 *   @0x112d18 cmp r3, #2
 *   @0x112d1c bne 0x112cf8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x20>
 *   @0x112d20 ldr r3, [r4]
 *   @0x112d24 cmp r3, #0
 *   @0x112d28 beq 0x112d08 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x30>
 *   @0x112d2c mov r1, #1
 *   @0x112d30 mov r0, r4
 *   @0x112d34 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x112d38 add r1, r4, #32
 *   @0x112d3c mov r2, r0
 *   @0x112d40 mov r0, r4
 *   @0x112d44 bl 0xcfcb4 <_Z16SET_RValue_ArrayP6RValueS0_i>
 *   @0x112d48 ldr r2, [r5, #0xc]
 *   @0x112d4c bic r3, r2, #-16777216
 *   @0x112d50 cmp r3, #1
 *   @0x112d54 beq 0x112df8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x112d58 cmp r3, #2
 *   @0x112d5c bne 0x112d84 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x112d60 sub r3, r2, #1
 *   @0x112d64 bic r3, r3, #-16777216
 *   @0x112d68 bic r3, r3, #3
 *   @0x112d6c cmp r3, #0
 *   @0x112d70 beq 0x112ee0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x112d74 mov r2, #0
 *   @0x112d78 mov r3, #5
 *   @0x112d7c str r2, [r5, #0x8]
 *   @0x112d80 str r3, [r5, #0xc]
 *   @0x112d84 ldr r3, [r4, #0x2c]
 *   @0x112d88 mov r1, #0
 *   @0x112d8c ldr r2, [r4, #0x28]
 *   @0x112d90 str r1, [r5]
 *   @0x112d94 str r3, [r5, #0xc]
 *   @0x112d98 ldr r3, [r4, #0x2c]
 *   @0x112d9c str r2, [r5, #0x8]
 *   @0x112da0 bic r3, r3, #-16777216
 *   @0x112da4 cmp r3, #14
 *   @0x112da8 addls pc, pc, r3, lsl #2
 *   @0x112dac b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112db0 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x112db4 b 0x112e8c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1b4>
 *   @0x112db8 b 0x112e60 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x188>
 *   @0x112dbc b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x112dc0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112dc4 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112dc8 b 0x112e3c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x112dcc b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x112dd0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112dd4 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112dd8 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x112ddc b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112de0 b 0x112ea4 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x112de4 b 0x112e2c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x154>
 *   @0x112de8 b 0x112dec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x112dec ldr r3, [r4, #0x20]
 *   @0x112df0 str r3, [r5]
 *   @0x112df4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x112df8 ldr r6, [r5]
 *   @0x112dfc cmp r6, #0
 *   @0x112e00 beq 0x112e20 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x148>
 *   @0x112e04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x112e08 ldr r7, [r6, #0x4]
 *   @0x112e0c sub r7, r7, #1
 *   @0x112e10 str r7, [r6, #0x4]
 *   @0x112e14 cmp r7, #0
 *   @0x112e18 beq 0x112ea8 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x112e1c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x112e20 mov r3, #0
 *   @0x112e24 str r3, [r5]
 *   @0x112e28 b 0x112d84 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0x112e2c ldr r2, [r4, #0x20]
 *   @0x112e30 ldr r3, [r4, #0x24]
 *   @0x112e34 stm r5, {r2, r3}
 *   @0x112e38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x112e3c ldr r3, [r4, #0x20]
 *   @0x112e40 str r3, [r5]
 *   @0x112e44 ldr r3, [r4, #0x20]
 *   @0x112e48 cmp r3, #0
 *   @0x112e4c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x112e50 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x112e54 ldr r1, [r4, #0x20]
 *   @0x112e58 pop {r3, r4, r5, r6, r7, lr}
 *   @0x112e5c b 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x112e60 ldr r3, [r4, #0x20]
 *   @0x112e64 cmp r3, #0
 *   @0x112e68 str r3, [r5]
 *   @0x112e6c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x112e70 ldr r1, [r3, #0x8]
 *   @0x112e74 ldr r2, [r3]
 *   @0x112e78 cmp r1, #0
 *   @0x112e7c streq r5, [r3, #0x8]
 *   @0x112e80 add r2, r2, #1
 *   @0x112e84 str r2, [r3]
 *   @0x112e88 pop {r3, r4, r5, r6, r7, pc}
 *   @0x112e8c ldr r3, [r4, #0x20]
 *   @0x112e90 cmp r3, #0
 *   @0x112e94 ldrne r2, [r3, #0x4]
 *   @0x112e98 addne r2, r2, #1
 *   @0x112e9c strne r2, [r3, #0x4]
 *   @0x112ea0 b 0x112df0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x118>
 *   @0x112ea4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x112ea8 ldr r0, [r6]
 *   @0x112eac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x112eb0 str r7, [r6]
 *   @0x112eb4 str r7, [r6, #0x8]
 *   @0x112eb8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x112ebc ldr r7, [r6, #0x4]
 *   @0x112ec0 sub r7, r7, #1
 *   @0x112ec4 str r7, [r6, #0x4]
 *   @0x112ec8 cmp r7, #0
 *   @0x112ecc beq 0x112eec <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x112ed0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x112ed4 mov r0, r6
 *   @0x112ed8 bl 0x27d1d0 <_ZdlPv>
 *   @0x112edc b 0x112e1c <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x144>
 *   @0x112ee0 mov r0, r5
 *   @0x112ee4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x112ee8 b 0x112d74 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x112eec ldr r0, [r6]
 *   @0x112ef0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x112ef4 str r7, [r6]
 *   @0x112ef8 str r7, [r6, #0x8]
 *   @0x112efc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x112f00 ldr r7, [r6, #0x4]
 *   @0x112f04 sub r7, r7, #1
 *   @0x112f08 str r7, [r6, #0x4]
 *   @0x112f0c cmp r7, #0
 *   @0x112f10 bne 0x112f34 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x25c>
 *   @0x112f14 ldr r0, [r6]
 *   @0x112f18 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x112f1c mov r0, r6
 *   @0x112f20 str r7, [r6]
 *   @0x112f24 str r7, [r6, #0x8]
 *   @0x112f28 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x112f2c mov r0, r6
 *   @0x112f30 bl 0x27d1d0 <_ZdlPv>
 *   @0x112f34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x112f38 mov r0, r6
 *   @0x112f3c bl 0x27d1d0 <_ZdlPv>
 *   @0x112f40 b 0x112ed0 <_Z13F_ArraySetPreR6RValueP9CInstanceS2_iPS_+0x1f8>
 *   @0x112f44 eoreq r6, r2, r0, ror #3
 *   @0x112f48 .word 0x002261f8
 *
 * ══ §3/50 F_PhysicsCreateRopeJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ef5c  size 628  157 条（0x14ef5c..0x14f1d0）
 * @func 0x14ef5c 0x14f1d0  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14effc→0x54298c, 0x14f0e0→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetBool(RValue const*, int) / CPhysicsWorld::CreateRopeJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x12c×2 / 0x84×2 / 0xb4×2 / 0x1c×2 / 0x20×2 / 0x24×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ef5c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14ef60 sub sp, sp, #308
 *   @0x14ef64 ldr r6, [pc, #0x248]
 *   @0x14ef68 mov r8, r2
 *   @0x14ef6c ldr r12, [pc, #0x244]
 *   @0x14ef70 mov r3, #0
 *   @0x14ef74 add r6, pc, r6
 *   @0x14ef78 ldr r4, [sp, #0x158]
 *   @0x14ef7c mov r5, r0
 *   @0x14ef80 mov r9, r1
 *   @0x14ef84 ldr r7, [r6, r12]
 *   @0x14ef88 mov r0, r3
 *   @0x14ef8c mov r1, r3
 *   @0x14ef90 movt r0, #0xbff0
 *   @0x14ef94 str r3, [r5, #0xc]
 *   @0x14ef98 ldr r2, [r7]
 *   @0x14ef9c str r0, [r5, #0x4]
 *   @0x14efa0 mov r0, r4
 *   @0x14efa4 str r3, [r5]
 *   @0x14efa8 str r2, [sp, #0x12c]
 *   @0x14efac bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14efb0 mov r1, r9
 *   @0x14efb4 mov r2, r8
 *   @0x14efb8 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14efbc subs r10, r0, #0
 *   @0x14efc0 beq 0x14f120 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14efc4 mov r1, #1
 *   @0x14efc8 mov r0, r4
 *   @0x14efcc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14efd0 mov r1, r9
 *   @0x14efd4 mov r2, r8
 *   @0x14efd8 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14efdc subs r9, r0, #0
 *   @0x14efe0 beq 0x14f168 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14efe4 ldr r8, [r10, #0x84]
 *   @0x14efe8 cmp r8, #0
 *   @0x14efec beq 0x14f0e0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x14eff0 ldr r9, [r9, #0x84]
 *   @0x14eff4 cmp r9, #0
 *   @0x14eff8 beq 0x14f0e0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x14effc ldr r3, [pc, #0x1b8]
 *   @0x14f000 ldr r3, [r6, r3]
 *   @0x14f004 ldr r3, [r3]
 *   @0x14f008 ldr r6, [r3, #0xb4]
 *   @0x14f00c cmp r6, #0
 *   @0x14f010 beq 0x14f10c <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x14f014 mov r1, #2
 *   @0x14f018 mov r0, r4
 *   @0x14f01c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f020 mov r1, #3
 *   @0x14f024 mov r10, r0
 *   @0x14f028 mov r0, r4
 *   @0x14f02c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f030 mov r1, #4
 *   @0x14f034 mov r12, r0
 *   @0x14f038 mov r0, r4
 *   @0x14f03c str r12, [sp, #0x1c]
 *   @0x14f040 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f044 mov r1, #5
 *   @0x14f048 mov r2, r0
 *   @0x14f04c mov r0, r4
 *   @0x14f050 str r2, [sp, #0x20]
 *   @0x14f054 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f058 mov r1, #6
 *   @0x14f05c mov r3, r0
 *   @0x14f060 mov r0, r4
 *   @0x14f064 str r3, [sp, #0x24]
 *   @0x14f068 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14f06c mov r1, #7
 *   @0x14f070 mov r11, r0
 *   @0x14f074 mov r0, r4
 *   @0x14f078 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14f07c ldr r2, [sp, #0x20]
 *   @0x14f080 ldr r3, [sp, #0x24]
 *   @0x14f084 mov r1, r8
 *   @0x14f088 ldr r12, [sp, #0x1c]
 *   @0x14f08c str r2, [sp, #0x4]
 *   @0x14f090 mov r2, r9
 *   @0x14f094 str r3, [sp, #0x8]
 *   @0x14f098 mov r3, r10
 *   @0x14f09c str r12, [sp]
 *   @0x14f0a0 str r11, [sp, #0xc]
 *   @0x14f0a4 str r0, [sp, #0x10]
 *   @0x14f0a8 mov r0, r6
 *   @0x14f0ac bl 0x238f60 <_ZN13CPhysicsWorld15CreateRopeJointEP14CPhysicsObjectS1_fffffb>
 *   @0x14f0b0 vmov s15, r0
 *   @0x14f0b4 vcvt.f64.s32 d7, s15
 *   @0x14f0b8 vmov r0, r1, d7
 *   @0x14f0bc vmov r2, s14
 *   @0x14f0c0 mov r3, r1
 *   @0x14f0c4 stm r5, {r2, r3}
 *   @0x14f0c8 ldr r2, [sp, #0x12c]
 *   @0x14f0cc ldr r3, [r7]
 *   @0x14f0d0 cmp r2, r3
 *   @0x14f0d4 bne 0x14f1b0 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x14f0d8 add sp, sp, #308
 *   @0x14f0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14f0e0 ldr r3, [pc, #0xd4]
 *   @0x14f0e4 ldr r3, [r6, r3]
 *   @0x14f0e8 ldr r3, [r3]
 *   @0x14f0ec ldr r3, [r3, #0xb4]
 *   @0x14f0f0 cmp r3, #0
 *   @0x14f0f4 beq 0x14f10c <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x14f0f8 ldr r0, [pc, #0xc0]
 *   @0x14f0fc mov r1, #0
 *   @0x14f100 add r0, pc, r0
 *   @0x14f104 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f108 b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x14f10c ldr r0, [pc, #0xb0]
 *   @0x14f110 mov r1, #0
 *   @0x14f114 add r0, pc, r0
 *   @0x14f118 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f11c b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x14f120 add r5, sp, #44
 *   @0x14f124 mov r1, r10
 *   @0x14f128 mov r2, #256
 *   @0x14f12c mov r0, r5
 *   @0x14f130 bl 0xb65b0 <memset@plt>
 *   @0x14f134 mov r1, r10
 *   @0x14f138 mov r0, r4
 *   @0x14f13c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f140 ldr r2, [pc, #0x80]
 *   @0x14f144 mov r1, #256
 *   @0x14f148 add r2, pc, r2
 *   @0x14f14c mov r3, r0
 *   @0x14f150 mov r0, r5
 *   @0x14f154 bl 0xb65c8 <snprintf@plt>
 *   @0x14f158 mov r0, r5
 *   @0x14f15c mov r1, r10
 *   @0x14f160 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f164 b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x14f168 add r5, sp, #44
 *   @0x14f16c mov r1, r9
 *   @0x14f170 mov r2, #256
 *   @0x14f174 mov r0, r5
 *   @0x14f178 bl 0xb65b0 <memset@plt>
 *   @0x14f17c mov r0, r4
 *   @0x14f180 mov r1, #1
 *   @0x14f184 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14f188 ldr r2, [pc, #0x3c]
 *   @0x14f18c mov r1, #256
 *   @0x14f190 add r2, pc, r2
 *   @0x14f194 mov r3, r0
 *   @0x14f198 mov r0, r5
 *   @0x14f19c bl 0xb65c8 <snprintf@plt>
 *   @0x14f1a0 mov r0, r5
 *   @0x14f1a4 mov r1, r9
 *   @0x14f1a8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14f1ac b 0x14f0c8 <_Z24F_PhysicsCreateRopeJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x14f1b0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14f1b4 .word 0x002a2cdc
 *   @0x14f1b8 .word 0xffffbd00
 *   @0x14f1bc .word 0xffffbcd8
 *   @0x14f1c0 andseq r5, pc, r12, lsl sp
 *   @0x14f1c4 andseq r4, pc, r0, lsl sp
 *   @0x14f1c8 andseq r5, pc, r8, asr r12
 *   @0x14f1cc andseq r5, pc, r0, lsl r12
 *
 * ══ §4/50 F_PhysicsCreateWeldJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ff68  size 628  157 条（0x14ff68..0x1501dc）
 * @func 0x14ff68 0x1501ec  size 644  161 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x150008→0x54298c, 0x1500ec→0x54298c
 * 调用序列: YYGetFloat(RValue const*, int)×5 / YYGetInt32(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetBool(RValue const*, int) / CPhysicsWorld::CreateWeldJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, float, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x12c×2 / 0x84×2 / 0xb4×2 / 0x1c×2 / 0x20×2 / 0x24×2
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ff68 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14ff6c sub sp, sp, #308
 *   @0x14ff70 ldr r6, [pc, #0x248]
 *   @0x14ff74 mov r8, r2
 *   @0x14ff78 ldr r12, [pc, #0x244]
 *   @0x14ff7c mov r3, #0
 *   @0x14ff80 add r6, pc, r6
 *   @0x14ff84 ldr r4, [sp, #0x158]
 *   @0x14ff88 mov r5, r0
 *   @0x14ff8c mov r9, r1
 *   @0x14ff90 ldr r7, [r6, r12]
 *   @0x14ff94 mov r0, r3
 *   @0x14ff98 mov r1, r3
 *   @0x14ff9c movt r0, #0xbff0
 *   @0x14ffa0 str r3, [r5, #0xc]
 *   @0x14ffa4 ldr r2, [r7]
 *   @0x14ffa8 str r0, [r5, #0x4]
 *   @0x14ffac mov r0, r4
 *   @0x14ffb0 str r3, [r5]
 *   @0x14ffb4 str r2, [sp, #0x12c]
 *   @0x14ffb8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ffbc mov r1, r9
 *   @0x14ffc0 mov r2, r8
 *   @0x14ffc4 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14ffc8 subs r10, r0, #0
 *   @0x14ffcc beq 0x15012c <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1c4>
 *   @0x14ffd0 mov r1, #1
 *   @0x14ffd4 mov r0, r4
 *   @0x14ffd8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ffdc mov r1, r9
 *   @0x14ffe0 mov r2, r8
 *   @0x14ffe4 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14ffe8 subs r9, r0, #0
 *   @0x14ffec beq 0x150174 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x20c>
 *   @0x14fff0 ldr r8, [r10, #0x84]
 *   @0x14fff4 cmp r8, #0
 *   @0x14fff8 beq 0x1500ec <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x14fffc ldr r9, [r9, #0x84]
 *   @0x150000 cmp r9, #0
 *   @0x150004 beq 0x1500ec <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x150008 ldr r3, [pc, #0x1b8]
 *   @0x15000c ldr r3, [r6, r3]
 *   @0x150010 ldr r3, [r3]
 *   @0x150014 ldr r6, [r3, #0xb4]
 *   @0x150018 cmp r6, #0
 *   @0x15001c beq 0x150118 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x150020 mov r1, #2
 *   @0x150024 mov r0, r4
 *   @0x150028 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x15002c mov r1, #3
 *   @0x150030 mov r10, r0
 *   @0x150034 mov r0, r4
 *   @0x150038 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x15003c mov r1, #4
 *   @0x150040 mov r12, r0
 *   @0x150044 mov r0, r4
 *   @0x150048 str r12, [sp, #0x1c]
 *   @0x15004c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x150050 mov r1, #5
 *   @0x150054 mov r2, r0
 *   @0x150058 mov r0, r4
 *   @0x15005c str r2, [sp, #0x20]
 *   @0x150060 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x150064 mov r1, #6
 *   @0x150068 mov r3, r0
 *   @0x15006c mov r0, r4
 *   @0x150070 str r3, [sp, #0x24]
 *   @0x150074 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x150078 mov r1, #7
 *   @0x15007c mov r11, r0
 *   @0x150080 mov r0, r4
 *   @0x150084 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x150088 ldr r2, [sp, #0x20]
 *   @0x15008c ldr r3, [sp, #0x24]
 *   @0x150090 mov r1, r8
 *   @0x150094 ldr r12, [sp, #0x1c]
 *   @0x150098 str r2, [sp, #0x4]
 *   @0x15009c mov r2, r9
 *   @0x1500a0 str r3, [sp, #0x8]
 *   @0x1500a4 mov r3, r10
 *   @0x1500a8 str r12, [sp]
 *   @0x1500ac str r11, [sp, #0xc]
 *   @0x1500b0 str r0, [sp, #0x10]
 *   @0x1500b4 mov r0, r6
 *   @0x1500b8 bl 0x239570 <_ZN13CPhysicsWorld15CreateWeldJointEP14CPhysicsObjectS1_fffffb>
 *   @0x1500bc vmov s15, r0
 *   @0x1500c0 vcvt.f64.s32 d7, s15
 *   @0x1500c4 vmov r0, r1, d7
 *   @0x1500c8 vmov r2, s14
 *   @0x1500cc mov r3, r1
 *   @0x1500d0 stm r5, {r2, r3}
 *   @0x1500d4 ldr r2, [sp, #0x12c]
 *   @0x1500d8 ldr r3, [r7]
 *   @0x1500dc cmp r2, r3
 *   @0x1500e0 bne 0x1501bc <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x254>
 *   @0x1500e4 add sp, sp, #308
 *   @0x1500e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1500ec ldr r3, [pc, #0xd4]
 *   @0x1500f0 ldr r3, [r6, r3]
 *   @0x1500f4 ldr r3, [r3]
 *   @0x1500f8 ldr r3, [r3, #0xb4]
 *   @0x1500fc cmp r3, #0
 *   @0x150100 beq 0x150118 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x1b0>
 *   @0x150104 ldr r0, [pc, #0xc0]
 *   @0x150108 mov r1, #0
 *   @0x15010c add r0, pc, r0
 *   @0x150110 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x150114 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x150118 ldr r0, [pc, #0xb0]
 *   @0x15011c mov r1, #0
 *   @0x150120 add r0, pc, r0
 *   @0x150124 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x150128 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x15012c add r5, sp, #44
 *   @0x150130 mov r1, r10
 *   @0x150134 mov r2, #256
 *   @0x150138 mov r0, r5
 *   @0x15013c bl 0xb65b0 <memset@plt>
 *   @0x150140 mov r1, r10
 *   @0x150144 mov r0, r4
 *   @0x150148 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x15014c ldr r2, [pc, #0x80]
 *   @0x150150 mov r1, #256
 *   @0x150154 add r2, pc, r2
 *   @0x150158 mov r3, r0
 *   @0x15015c mov r0, r5
 *   @0x150160 bl 0xb65c8 <snprintf@plt>
 *   @0x150164 mov r0, r5
 *   @0x150168 mov r1, r10
 *   @0x15016c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x150170 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x150174 add r5, sp, #44
 *   @0x150178 mov r1, r9
 *   @0x15017c mov r2, #256
 *   @0x150180 mov r0, r5
 *   @0x150184 bl 0xb65b0 <memset@plt>
 *   @0x150188 mov r0, r4
 *   @0x15018c mov r1, #1
 *   @0x150190 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x150194 ldr r2, [pc, #0x3c]
 *   @0x150198 mov r1, #256
 *   @0x15019c add r2, pc, r2
 *   @0x1501a0 mov r3, r0
 *   @0x1501a4 mov r0, r5
 *   @0x1501a8 bl 0xb65c8 <snprintf@plt>
 *   @0x1501ac mov r0, r5
 *   @0x1501b0 mov r1, r9
 *   @0x1501b4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1501b8 b 0x1500d4 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x1501bc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1501c0 .word 0x002a1cd0
 *   @0x1501c4 .word 0xffffbd00
 *   @0x1501c8 .word 0xffffbcd8
 *   @0x1501cc andseq r4, pc, r0, lsr lr
 *   @0x1501d0 andseq r3, pc, r4, lsl #26
 *   @0x1501d4 andseq r4, pc, r12, asr #24
 *   @0x1501d8 andseq r4, pc, r4, lsl #24
 *
 * ══ §5/50 CPhysicsObject::DebugRenderJoints(float)  0x237468  size 628  157 条（0x237468..0x2376dc）
 * @func 0x237468 0x2376dc  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Draw_Line(float, float, float, float)×6 / b2PulleyJoint::GetGroundAnchorB() const×3 / b2PulleyJoint::GetGroundAnchorA() const×3
 * 字段偏移 top8: 0x4×5 / 0x7c×1 / 0x30×1 / 0xc×1
 * VFP 指令 68 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x237468 ldr r3, [r0]
 *   @0x23746c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x237470 vpush {d8, d9, d10}
 *   @0x237474 mov r6, r0
 *   @0x237478 ldr r10, [r3, #0x7c]
 *   @0x23747c sub sp, sp, #68
 *   @0x237480 vmov s16, r1
 *   @0x237484 cmp r10, #0
 *   @0x237488 beq 0x2375a4 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x13c>
 *   @0x23748c add r9, sp, #32
 *   @0x237490 add r8, sp, #40
 *   @0x237494 add r7, sp, #48
 *   @0x237498 add r5, sp, #56
 *   @0x23749c add r11, sp, #16
 *   @0x2374a0 add r3, sp, #24
 *   @0x2374a4 str r3, [sp, #0x4]
 *   @0x2374a8 ldr r4, [r10, #0x4]
 *   @0x2374ac ldr r3, [r4, #0x4]
 *   @0x2374b0 sub r3, r3, #1
 *   @0x2374b4 cmp r3, #3
 *   @0x2374b8 addls pc, pc, r3, lsl #2
 *   @0x2374bc b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130>
 *   @0x2374c0 b 0x237600 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x198>
 *   @0x2374c4 b 0x2375b0 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x148>
 *   @0x2374c8 b 0x237664 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x1fc>
 *   @0x2374cc b 0x2374d0 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x68>
 *   @0x2374d0 ldr r3, [r6]
 *   @0x2374d4 mov r0, r11
 *   @0x2374d8 ldr r2, [r4, #0x30]
 *   @0x2374dc mov r1, r4
 *   @0x2374e0 cmp r2, r3
 *   @0x2374e4 ldr r3, [r4]
 *   @0x2374e8 beq 0x2376c4 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x25c>
 *   @0x2374ec ldr r3, [r3, #0x4]
 *   @0x2374f0 blx r3
 *   @0x2374f4 add r0, sp, #24
 *   @0x2374f8 mov r1, r4
 *   @0x2374fc bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv>
 *   @0x237500 vldr s12, [sp, #16]
 *   @0x237504 vldr s13, [sp, #20]
 *   @0x237508 vmul.f32 s12, s16, s12
 *   @0x23750c vldr s14, [sp, #24]
 *   @0x237510 vldr s15, [sp, #28]
 *   @0x237514 vmul.f32 s13, s16, s13
 *   @0x237518 vmov r0, s12
 *   @0x23751c vmul.f32 s15, s16, s15
 *   @0x237520 vmov r1, s13
 *   @0x237524 vmul.f32 s14, s16, s14
 *   @0x237528 vmov r3, s15
 *   @0x23752c vmov r2, s14
 *   @0x237530 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x237534 mov r0, r9
 *   @0x237538 mov r1, r4
 *   @0x23753c bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv>
 *   @0x237540 mov r0, r8
 *   @0x237544 mov r1, r4
 *   @0x237548 vldr s19, [sp, #32]
 *   @0x23754c bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv>
 *   @0x237550 mov r0, r7
 *   @0x237554 mov r1, r4
 *   @0x237558 vldr s18, [sp, #44]
 *   @0x23755c bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv>
 *   @0x237560 mov r1, r4
 *   @0x237564 mov r0, r5
 *   @0x237568 vldr s17, [sp, #48]
 *   @0x23756c vmul.f32 s19, s16, s19
 *   @0x237570 bl 0x2d116c <_ZNK13b2PulleyJoint16GetGroundAnchorBEv>
 *   @0x237574 vldr s15, [sp, #60]
 *   @0x237578 vmul.f32 s18, s16, s18
 *   @0x23757c vmov r0, s19
 *   @0x237580 vmul.f32 s17, s16, s17
 *   @0x237584 vmov r1, s18
 *   @0x237588 vmul.f32 s15, s16, s15
 *   @0x23758c vmov r2, s17
 *   @0x237590 vmov r3, s15
 *   @0x237594 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x237598 ldr r10, [r10, #0xc]
 *   @0x23759c cmp r10, #0
 *   @0x2375a0 bne 0x2374a8 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x40>
 *   @0x2375a4 add sp, sp, #68
 *   @0x2375a8 vpop {d8, d9, d10}
 *   @0x2375ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2375b0 ldr r3, [r4]
 *   @0x2375b4 mov r1, r4
 *   @0x2375b8 mov r0, r5
 *   @0x2375bc ldr r3, [r3]
 *   @0x2375c0 blx r3
 *   @0x2375c4 ldr r3, [r6]
 *   @0x2375c8 vldr s14, [sp, #56]
 *   @0x2375cc vldr s15, [sp, #60]
 *   @0x2375d0 vldr s12, [r3, #12]
 *   @0x2375d4 vldr s13, [r3, #16]
 *   @0x2375d8 vmul.f32 s12, s16, s12
 *   @0x2375dc vmul.f32 s13, s16, s13
 *   @0x2375e0 vmov r2, s12
 *   @0x2375e4 vmul.f32 s14, s16, s14
 *   @0x2375e8 vmov r3, s13
 *   @0x2375ec vmul.f32 s15, s16, s15
 *   @0x2375f0 vmov r0, s14
 *   @0x2375f4 vmov r1, s15
 *   @0x2375f8 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x2375fc b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130>
 *   @0x237600 ldr r3, [r4]
 *   @0x237604 mov r1, r4
 *   @0x237608 add r0, sp, #8
 *   @0x23760c ldr r3, [r3]
 *   @0x237610 blx r3
 *   @0x237614 vldr s18, [sp, #8]
 *   @0x237618 vldr s19, [sp, #12]
 *   @0x23761c vmul.f32 s18, s16, s18
 *   @0x237620 vmul.f32 s19, s16, s19
 *   @0x237624 vmov.f32 s15, #2.000000e+00
 *   @0x237628 vsub.f32 s20, s18, s15
 *   @0x23762c vsub.f32 s17, s19, s15
 *   @0x237630 vmov r0, s20
 *   @0x237634 vadd.f32 s18, s18, s15
 *   @0x237638 vmov r1, s17
 *   @0x23763c vadd.f32 s19, s19, s15
 *   @0x237640 vmov r2, s18
 *   @0x237644 vmov r3, s19
 *   @0x237648 bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x23764c vmov r0, s20
 *   @0x237650 vmov r1, s19
 *   @0x237654 vmov r2, s18
 *   @0x237658 vmov r3, s17
 *   @0x23765c bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x237660 b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130>
 *   @0x237664 ldr r3, [r4]
 *   @0x237668 mov r0, r7
 *   @0x23766c mov r1, r4
 *   @0x237670 ldr r3, [r3]
 *   @0x237674 blx r3
 *   @0x237678 ldr r3, [r4]
 *   @0x23767c mov r1, r4
 *   @0x237680 mov r0, r5
 *   @0x237684 ldr r3, [r3, #0x4]
 *   @0x237688 blx r3
 *   @0x23768c vldr s12, [sp, #48]
 *   @0x237690 vldr s13, [sp, #52]
 *   @0x237694 vldr s14, [sp, #56]
 *   @0x237698 vldr s15, [sp, #60]
 *   @0x23769c vmul.f32 s12, s16, s12
 *   @0x2376a0 vmul.f32 s13, s16, s13
 *   @0x2376a4 vmov r0, s12
 *   @0x2376a8 vmul.f32 s14, s16, s14
 *   @0x2376ac vmov r1, s13
 *   @0x2376b0 vmul.f32 s15, s16, s15
 *   @0x2376b4 vmov r2, s14
 *   @0x2376b8 vmov r3, s15
 *   @0x2376bc bl 0x16a21c <_Z12GR_Draw_Lineffff>
 *   @0x2376c0 b 0x237598 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x130>
 *   @0x2376c4 ldr r3, [r3]
 *   @0x2376c8 blx r3
 *   @0x2376cc add r0, sp, #24
 *   @0x2376d0 mov r1, r4
 *   @0x2376d4 bl 0x2d1154 <_ZNK13b2PulleyJoint16GetGroundAnchorAEv>
 *   @0x2376d8 b 0x237500 <_ZN14CPhysicsObject17DebugRenderJointsEf+0x98>
 *
 * ══ §6/50 CLangMan::Language_Load(unsigned char*, unsigned int, unsigned char*)  0x27a4c8  size 628  157 条（0x27a4c8..0x27a73c）
 * @func 0x27a4c8 0x27a73c  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x27a4d8→0x756494, 0x27a4e4→0x756490, 0x27a538→0x756488, 0x27a564→0x75648c, 0x27a59c→0x544c44, 0x27a610→0x544c44, 0x27a62c→0x544c44, 0x27a688→0x544c44
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / CLangMan::Language_Load(unsigned char*, unsigned int, unsigned char*)+0x210×2 / CLangMan::Language_Load(unsigned char*, unsigned int, unsigned char*)+0x238×2
 * 字段偏移 top8: 0x8×6 / 0x4×5 / 0xc×3 / 0x240×1 / 0x23c×1 / 0x234×1 / 0x20c×1 / 0x1e8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27a4c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27a4cc sub sp, sp, #20
 *   @0x27a4d0 ldr r6, [pc, #0x240]
 *   @0x27a4d4 mov r4, r0
 *   @0x27a4d8 ldr r2, [pc, #0x23c]
 *   @0x27a4dc add r6, pc, r6
 *   @0x27a4e0 ldr r3, [r0, #0x4]
 *   @0x27a4e4 ldr r1, [pc, #0x234]
 *   @0x27a4e8 ldr r9, [r6, r2]
 *   @0x27a4ec cmp r3, #0
 *   @0x27a4f0 ldr r2, [r0, #0x8]
 *   @0x27a4f4 str r3, [r9]
 *   @0x27a4f8 ldr r1, [r6, r1]
 *   @0x27a4fc str r1, [sp]
 *   @0x27a500 str r2, [r1]
 *   @0x27a504 ble 0x27a6d8 <_ZN8CLangMan13Language_LoadEPhjS0_+0x210>
 *   @0x27a508 cmp r2, #0
 *   @0x27a50c ble 0x27a6d8 <_ZN8CLangMan13Language_LoadEPhjS0_+0x210>
 *   @0x27a510 ldr r5, [pc, #0x20c]
 *   @0x27a514 add r0, r3, r3, lsl #1
 *   @0x27a518 mov r2, #26
 *   @0x27a51c mov r3, #1
 *   @0x27a520 add r5, pc, r5
 *   @0x27a524 lsl r0, r0, #2
 *   @0x27a528 add r10, r4, #12
 *   @0x27a52c mov r1, r5
 *   @0x27a530 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27a534 ldr r1, [sp]
 *   @0x27a538 ldr lr, [pc, #0x1e8]
 *   @0x27a53c mov r2, #27
 *   @0x27a540 mov r3, #1
 *   @0x27a544 ldr r12, [r1]
 *   @0x27a548 mov r1, r5
 *   @0x27a54c ldr lr, [r6, lr]
 *   @0x27a550 str lr, [sp, #0x4]
 *   @0x27a554 str r0, [lr]
 *   @0x27a558 lsl r0, r12, #2
 *   @0x27a55c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27a560 ldr r2, [sp]
 *   @0x27a564 ldr r3, [pc, #0x1c0]
 *   @0x27a568 ldr r11, [r2]
 *   @0x27a56c ldr r7, [r6, r3]
 *   @0x27a570 cmp r11, #0
 *   @0x27a574 lsl r8, r11, #2
 *   @0x27a578 addgt r5, r4, r8
 *   @0x27a57c movgt r3, r4
 *   @0x27a580 str r0, [r7]
 *   @0x27a584 movgt r1, r0
 *   @0x27a588 bgt 0x27a594 <_ZN8CLangMan13Language_LoadEPhjS0_+0xcc>
 *   @0x27a58c b 0x27a5c8 <_ZN8CLangMan13Language_LoadEPhjS0_+0x100>
 *   @0x27a590 ldr r1, [r7]
 *   @0x27a594 ldr r2, [r3, #0xc]
 *   @0x27a598 rsb r0, r4, r3
 *   @0x27a59c ldr r12, [pc, #0x18c]
 *   @0x27a5a0 add r0, r1, r0
 *   @0x27a5a4 cmp r2, #0
 *   @0x27a5a8 add r3, r3, #4
 *   @0x27a5ac mov r1, r2
 *   @0x27a5b0 ldrne r1, [r6, r12]
 *   @0x27a5b4 ldrne r1, [r1]
 *   @0x27a5b8 addne r1, r1, r2
 *   @0x27a5bc cmp r3, r5
 *   @0x27a5c0 str r1, [r0]
 *   @0x27a5c4 bne 0x27a590 <_ZN8CLangMan13Language_LoadEPhjS0_+0xc8>
 *   @0x27a5c8 ldr r3, [r9]
 *   @0x27a5cc add r4, r10, r8
 *   @0x27a5d0 add r8, r8, #8
 *   @0x27a5d4 str r8, [sp, #0x8]
 *   @0x27a5d8 cmp r3, #0
 *   @0x27a5dc ble 0x27a700 <_ZN8CLangMan13Language_LoadEPhjS0_+0x238>
 *   @0x27a5e0 ldr r3, [pc, #0x14c]
 *   @0x27a5e4 mov r7, #0
 *   @0x27a5e8 mov r0, r11
 *   @0x27a5ec mov r8, r7
 *   @0x27a5f0 add r3, pc, r3
 *   @0x27a5f4 str r3, [sp, #0xc]
 *   @0x27a5f8 ldr lr, [sp, #0x4]
 *   @0x27a5fc ldr r3, [r4]
 *   @0x27a600 ldr r5, [lr]
 *   @0x27a604 cmp r3, #0
 *   @0x27a608 add r5, r5, r7
 *   @0x27a60c moveq r2, r3
 *   @0x27a610 ldrne r2, [pc, #0x118]
 *   @0x27a614 ldrne r2, [r6, r2]
 *   @0x27a618 ldrne r2, [r2]
 *   @0x27a61c addne r2, r2, r3
 *   @0x27a620 ldr r3, [r4, #0x4]
 *   @0x27a624 str r2, [r5]
 *   @0x27a628 cmp r3, #0
 *   @0x27a62c ldrne r2, [pc, #0xfc]
 *   @0x27a630 ldrne r2, [r6, r2]
 *   @0x27a634 ldrne r2, [r2]
 *   @0x27a638 addne r3, r2, r3
 *   @0x27a63c str r3, [r5, #0x4]
 *   @0x27a640 lsl r0, r0, #2
 *   @0x27a644 ldr r1, [sp, #0xc]
 *   @0x27a648 mov r3, #1
 *   @0x27a64c mov r2, #47
 *   @0x27a650 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x27a654 ldr r1, [sp]
 *   @0x27a658 ldr r11, [r1]
 *   @0x27a65c cmp r11, #0
 *   @0x27a660 addgt r10, r4, r11, lsl #2
 *   @0x27a664 movgt r3, r4
 *   @0x27a668 movgt r1, r0
 *   @0x27a66c str r0, [r5, #0x8]
 *   @0x27a670 movgt r0, r1
 *   @0x27a674 bgt 0x27a680 <_ZN8CLangMan13Language_LoadEPhjS0_+0x1b8>
 *   @0x27a678 b 0x27a6b4 <_ZN8CLangMan13Language_LoadEPhjS0_+0x1ec>
 *   @0x27a67c ldr r0, [r5, #0x8]
 *   @0x27a680 ldr r2, [r3, #0x8]
 *   @0x27a684 rsb r1, r4, r3
 *   @0x27a688 ldr r12, [pc, #0xa0]
 *   @0x27a68c add r1, r0, r1
 *   @0x27a690 cmp r2, #0
 *   @0x27a694 add r3, r3, #4
 *   @0x27a698 mov r0, r2
 *   @0x27a69c ldrne r0, [r6, r12]
 *   @0x27a6a0 ldrne r0, [r0]
 *   @0x27a6a4 addne r0, r0, r2
 *   @0x27a6a8 cmp r3, r10
 *   @0x27a6ac str r0, [r1]
 *   @0x27a6b0 bne 0x27a67c <_ZN8CLangMan13Language_LoadEPhjS0_+0x1b4>
 *   @0x27a6b4 ldr r3, [r9]
 *   @0x27a6b8 add r8, r8, #1
 *   @0x27a6bc ldr r2, [sp, #0x8]
 *   @0x27a6c0 add r7, r7, #12
 *   @0x27a6c4 cmp r3, r8
 *   @0x27a6c8 add r4, r4, r2
 *   @0x27a6cc ble 0x27a700 <_ZN8CLangMan13Language_LoadEPhjS0_+0x238>
 *   @0x27a6d0 mov r0, r11
 *   @0x27a6d4 b 0x27a5f8 <_ZN8CLangMan13Language_LoadEPhjS0_+0x130>
 *   @0x27a6d8 ldr r1, [pc, #0x58]
 *   @0x27a6dc mov r3, #0
 *   @0x27a6e0 ldr r0, [sp]
 *   @0x27a6e4 mvn r2, #0
 *   @0x27a6e8 str r3, [r9]
 *   @0x27a6ec str r3, [r0]
 *   @0x27a6f0 ldr r3, [r6, r1]
 *   @0x27a6f4 str r2, [r3]
 *   @0x27a6f8 add sp, sp, #20
 *   @0x27a6fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27a700 ldr r3, [pc, #0x30]
 *   @0x27a704 mov r2, #0
 *   @0x27a708 ldr r3, [r6, r3]
 *   @0x27a70c str r2, [r3]
 *   @0x27a710 add sp, sp, #20
 *   @0x27a714 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27a718 andseq r7, r7, r4, ror r7
 *   @0x27a71c .word 0xfffffbb8
 *   @0x27a720 .word 0xfffffbbc
 *   @0x27a724 andeq r12, sp, r12, asr #24
 *   @0x27a728 .word 0xfffffbc0
 *   @0x27a72c .word 0xfffffbc4
 *   @0x27a730 .word 0xffffbcf4
 *   @0x27a734 andeq r12, sp, r12, ror r11
 *   @0x27a738 .word 0xfffffbc8
 *
 * ══ §7/50 DGifSlurp(GifFileType*)  0x2c2918  size 628  157 条（0x2c2918..0x2c2b8c）
 * @func 0x2c2918 0x2c2b8c  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GifAddExtensionBlock(int*, ExtensionBlock**, int, unsigned int, unsigned char*)×2 / DGifGetLine(GifFileType*, unsigned char*, int)×2 / DGifGetRecordType(GifFileType*, GifRecordType*) / DGifGetExtension(GifFileType*, int*, unsigned char**) / DGifGetExtensionNext(GifFileType*, unsigned char**) / DGifGetImageDesc(GifFileType*) / DGifSlurp(GifFileType*)+0x1f0 / 0xb6544
 * 字段偏移 top8: 0xc×6 / 0x1c×4 / 0x20×4 / 0x10×3 / 0x3c×3 / 0x38×3 / 0x18×3 / 0x1×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c2918 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c291c sub sp, sp, #76
 *   @0x2c2920 ldr r2, [pc, #0x260]
 *   @0x2c2924 add r10, sp, #28
 *   @0x2c2928 add r9, sp, #32
 *   @0x2c292c mov r8, r0
 *   @0x2c2930 mov r5, r0
 *   @0x2c2934 add r2, pc, r2
 *   @0x2c2938 mov r3, #0
 *   @0x2c293c str r2, [sp, #0x10]
 *   @0x2c2940 str r3, [r0, #0x3c]
 *   @0x2c2944 add r2, sp, #36
 *   @0x2c2948 str r3, [r8, #0x38]!
 *   @0x2c294c str r2, [sp, #0x14]
 *   @0x2c2950 str r8, [sp, #0xc]
 *   @0x2c2954 mov r0, r5
 *   @0x2c2958 mov r1, r10
 *   @0x2c295c bl 0x2c1db8 <_Z17DGifGetRecordTypeP11GifFileTypeP13GifRecordType>
 *   @0x2c2960 cmp r0, #0
 *   @0x2c2964 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2968 ldr r3, [sp, #0x1c]
 *   @0x2c296c cmp r3, #2
 *   @0x2c2970 beq 0x2c2a00 <_Z9DGifSlurpP11GifFileType+0xe8>
 *   @0x2c2974 cmp r3, #3
 *   @0x2c2978 bne 0x2c29ec <_Z9DGifSlurpP11GifFileType+0xd4>
 *   @0x2c297c mov r0, r5
 *   @0x2c2980 add r1, sp, #36
 *   @0x2c2984 mov r2, r9
 *   @0x2c2988 bl 0x2c2348 <_Z16DGifGetExtensionP11GifFileTypePiPPh>
 *   @0x2c298c cmp r0, #0
 *   @0x2c2990 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2994 ldr r12, [sp, #0x20]
 *   @0x2c2998 add r4, r5, #60
 *   @0x2c299c ldr r2, [sp, #0x24]
 *   @0x2c29a0 ldr r0, [sp, #0xc]
 *   @0x2c29a4 mov r1, r4
 *   @0x2c29a8 ldrb r3, [r12], #1
 *   @0x2c29ac str r12, [sp]
 *   @0x2c29b0 bl 0x2c2f3c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh>
 *   @0x2c29b4 cmp r0, #0
 *   @0x2c29b8 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c29bc ldr r3, [sp, #0x20]
 *   @0x2c29c0 mov r1, r9
 *   @0x2c29c4 mov r0, r5
 *   @0x2c29c8 cmp r3, #0
 *   @0x2c29cc beq 0x2c29e8 <_Z9DGifSlurpP11GifFileType+0xd0>
 *   @0x2c29d0 bl 0x2c2270 <_Z20DGifGetExtensionNextP11GifFileTypePPh>
 *   @0x2c29d4 cmp r0, #0
 *   @0x2c29d8 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c29dc ldr r3, [sp, #0x20]
 *   @0x2c29e0 cmp r3, #0
 *   @0x2c29e4 bne 0x2c2ad8 <_Z9DGifSlurpP11GifFileType+0x1c0>
 *   @0x2c29e8 ldr r3, [sp, #0x1c]
 *   @0x2c29ec cmp r3, #4
 *   @0x2c29f0 bne 0x2c2954 <_Z9DGifSlurpP11GifFileType+0x3c>
 *   @0x2c29f4 mov r0, #1
 *   @0x2c29f8 add sp, sp, #76
 *   @0x2c29fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c2a00 mov r0, r5
 *   @0x2c2a04 bl 0x2c1ea8 <_Z16DGifGetImageDescP11GifFileType>
 *   @0x2c2a08 cmp r0, #0
 *   @0x2c2a0c beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2a10 ldr r3, [r5, #0x18]
 *   @0x2c2a14 ldr r4, [r5, #0x34]
 *   @0x2c2a18 add r3, r3, r3, lsl #3
 *   @0x2c2a1c lsl r3, r3, #2
 *   @0x2c2a20 sub r3, r3, #36
 *   @0x2c2a24 add r4, r4, r3
 *   @0x2c2a28 ldr r6, [r4, #0x8]
 *   @0x2c2a2c ldr r11, [r4, #0xc]
 *   @0x2c2a30 cmp r6, #0
 *   @0x2c2a34 blt 0x2c2b08 <_Z9DGifSlurpP11GifFileType+0x1f0>
 *   @0x2c2a38 mul r6, r11, r6
 *   @0x2c2a3c mov r0, r6
 *   @0x2c2a40 bl 0xb6544 <malloc@plt>
 *   @0x2c2a44 cmp r0, #0
 *   @0x2c2a48 str r0, [r4, #0x18]
 *   @0x2c2a4c beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2a50 ldrb r3, [r4, #0x10]
 *   @0x2c2a54 cmp r3, #0
 *   @0x2c2a58 beq 0x2c2b3c <_Z9DGifSlurpP11GifFileType+0x224>
 *   @0x2c2a5c ldr r2, [sp, #0x10]
 *   @0x2c2a60 add r8, sp, #40
 *   @0x2c2a64 add r6, sp, #56
 *   @0x2c2a68 mov r7, #0
 *   @0x2c2a6c add r3, r2, #28
 *   @0x2c2a70 add r12, r2, #44
 *   @0x2c2a74 ldm r3, {r0, r1, r2, r3}
 *   @0x2c2a78 stm r8, {r0, r1, r2, r3}
 *   @0x2c2a7c ldm r12, {r0, r1, r2, r3}
 *   @0x2c2a80 stm r6, {r0, r1, r2, r3}
 *   @0x2c2a84 mov r3, r11
 *   @0x2c2a88 mov r11, r7
 *   @0x2c2a8c mov r7, r8
 *   @0x2c2a90 ldr r8, [r7, r11]
 *   @0x2c2a94 cmp r8, r3
 *   @0x2c2a98 blt 0x2c2ab4 <_Z9DGifSlurpP11GifFileType+0x19c>
 *   @0x2c2a9c b 0x2c2b28 <_Z9DGifSlurpP11GifFileType+0x210>
 *   @0x2c2aa0 ldr r2, [r6, r11]
 *   @0x2c2aa4 ldr r3, [r4, #0xc]
 *   @0x2c2aa8 add r8, r8, r2
 *   @0x2c2aac cmp r3, r8
 *   @0x2c2ab0 ble 0x2c2b28 <_Z9DGifSlurpP11GifFileType+0x210>
 *   @0x2c2ab4 ldr r3, [r4, #0x8]
 *   @0x2c2ab8 mov r0, r5
 *   @0x2c2abc ldr r1, [r4, #0x18]
 *   @0x2c2ac0 mov r2, r3
 *   @0x2c2ac4 mla r1, r8, r3, r1
 *   @0x2c2ac8 bl 0x2c26a8 <_Z11DGifGetLineP11GifFileTypePhi>
 *   @0x2c2acc cmp r0, #0
 *   @0x2c2ad0 bne 0x2c2aa0 <_Z9DGifSlurpP11GifFileType+0x188>
 *   @0x2c2ad4 b 0x2c29f8 <_Z9DGifSlurpP11GifFileType+0xe0>
 *   @0x2c2ad8 mov r12, r3
 *   @0x2c2adc ldr r0, [sp, #0xc]
 *   @0x2c2ae0 ldrb r3, [r12], #1
 *   @0x2c2ae4 mov r1, r4
 *   @0x2c2ae8 mov r2, #0
 *   @0x2c2aec str r12, [sp]
 *   @0x2c2af0 bl 0x2c2f3c <_Z20GifAddExtensionBlockPiPP14ExtensionBlockijPh>
 *   @0x2c2af4 cmp r0, #0
 *   @0x2c2af8 bne 0x2c29bc <_Z9DGifSlurpP11GifFileType+0xa4>
 *   @0x2c2afc mov r0, #0
 *   @0x2c2b00 add sp, sp, #76
 *   @0x2c2b04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c2b08 cmp r11, #0
 *   @0x2c2b0c bge 0x2c2a38 <_Z9DGifSlurpP11GifFileType+0x120>
 *   @0x2c2b10 mvn r0, #-2147483648
 *   @0x2c2b14 mov r1, r11
 *   @0x2c2b18 bl 0x318d10 <__divsi3>
 *   @0x2c2b1c cmp r6, r0
 *   @0x2c2b20 ble 0x2c2a38 <_Z9DGifSlurpP11GifFileType+0x120>
 *   @0x2c2b24 b 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2b28 add r11, r11, #4
 *   @0x2c2b2c cmp r11, #16
 *   @0x2c2b30 beq 0x2c2b54 <_Z9DGifSlurpP11GifFileType+0x23c>
 *   @0x2c2b34 ldr r3, [r4, #0xc]
 *   @0x2c2b38 b 0x2c2a90 <_Z9DGifSlurpP11GifFileType+0x178>
 *   @0x2c2b3c mov r1, r0
 *   @0x2c2b40 mov r2, r6
 *   @0x2c2b44 mov r0, r5
 *   @0x2c2b48 bl 0x2c26a8 <_Z11DGifGetLineP11GifFileTypePhi>
 *   @0x2c2b4c cmp r0, #0
 *   @0x2c2b50 beq 0x2c2afc <_Z9DGifSlurpP11GifFileType+0x1e4>
 *   @0x2c2b54 ldr r3, [r5, #0x3c]
 *   @0x2c2b58 cmp r3, #0
 *   @0x2c2b5c beq 0x2c29e8 <_Z9DGifSlurpP11GifFileType+0xd0>
 *   @0x2c2b60 ldr r2, [r5, #0x38]
 *   @0x2c2b64 str r3, [r4, #0x20]
 *   @0x2c2b68 ldr r3, [sp, #0x1c]
 *   @0x2c2b6c str r2, [r4, #0x1c]
 *   @0x2c2b70 mov r2, #0
 *   @0x2c2b74 cmp r3, #4
 *   @0x2c2b78 str r2, [r5, #0x3c]
 *   @0x2c2b7c str r2, [r5, #0x38]
 *   @0x2c2b80 bne 0x2c2954 <_Z9DGifSlurpP11GifFileType+0x3c>
 *   @0x2c2b84 b 0x2c29f4 <_Z9DGifSlurpP11GifFileType+0xdc>
 *   @0x2c2b88 andeq sp, r12, r12, lsr #18
 *
 * ══ §8/50 GR_Text_Draw(float, float, char const*, int, int)  0x172df8  size 624  155 条（0x172df8..0x173068）｜其中 1 条已由别的卡落锚，本节不再重复
 * @func 0x172df8 0x173068  size 624  155 条
 * 部分覆盖: 本节 155/156 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CFontGM::TextWidth(unsigned short*)×2 / GraphicsPerf::Push(unsigned int, char const*) / SetFont() / Split_TextBlock(char const*, int, TStringList*) / GR_Text_Draw(float, float, char const*, int, int)+0x234 / GR_Text_Draw(float, float, char const*, int, int)+0xf0 / GraphicsPerf::Pop()
 * 字段偏移 top8: 0x8×4 / 0x10×4 / 0x14×2 / 0x4×2 / 0x2c×2 / 0x240×1 / 0x48×1 / 0xc×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x172df8 push {r4, r5, r6, r7, r8, lr}
 *   @0x172dfc vpush {d8, d9, d10}
 *   @0x172e00 sub sp, sp, #24
 *   @0x172e04 vmov s16, r1
 *   @0x172e08 ldr r1, [pc, #0x240]
 *   @0x172e0c ldr r5, [sp, #0x48]
 *   @0x172e10 mov r6, r2
 *   @0x172e14 add r1, pc, r1
 *   @0x172e18 vmov s19, r0
 *   @0x172e1c mov r0, #65280
 *   @0x172e20 movt r0, #0xff
 *   @0x172e24 mov r12, #0
 *   @0x172e28 mov r4, r3
 *   @0x172e2c str r12, [sp, #0xc]
 *   @0x172e30 str r12, [sp, #0x8]
 *   @0x172e34 str r12, [sp, #0x14]
 *   @0x172e38 str r12, [sp, #0x10]
 *   @0x172e3c bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc>
 *   @0x172e40 bl 0x1724e4 <_Z7SetFontv>
 *   @0x172e44 mov r0, r6
 *   @0x172e48 mov r1, r5
 *   @0x172e4c add r2, sp, #8
 *   @0x172e54 ldr r6, [pc, #0x1f8]
 *   @0x172e58 cmp r4, #0
 *   @0x172e5c add r6, pc, r6
 *   @0x172e60 blt 0x17302c <_Z12GR_Text_DrawffPKcii+0x234>
 *   @0x172e64 ldr r3, [pc, #0x1ec]
 *   @0x172e68 ldr r1, [sp, #0x10]
 *   @0x172e6c ldr r3, [r6, r3]
 *   @0x172e70 ldr r3, [r3]
 *   @0x172e74 cmp r3, #1
 *   @0x172e78 beq 0x173010 <_Z12GR_Text_DrawffPKcii+0x218>
 *   @0x172e7c cmp r3, #2
 *   @0x172e80 muleq r3, r1, r4
 *   @0x172e84 vmoveq s15, r3
 *   @0x172e88 vcvteq.f32.s32 s15, s15
 *   @0x172e8c vsubeq.f32 s16, s16, s15
 *   @0x172e90 cmp r1, #0
 *   @0x172e94 ble 0x172ee8 <_Z12GR_Text_DrawffPKcii+0xf0>
 *   @0x172e98 vmov s14, r4
 *   @0x172e9c mov r4, #0
 *   @0x172ea0 vldr s20, [pc, #420]
 *   @0x172ea4 vcvt.f32.s32 s17, s14
 *   @0x172ea8 ldr r3, [sp, #0x8]
 *   @0x172eac cmp r3, #0
 *   @0x172eb0 beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0>
 *   @0x172eb4 cmp r4, #0
 *   @0x172eb8 movne r2, r4
 *   @0x172ebc bne 0x172ecc <_Z12GR_Text_DrawffPKcii+0xd4>
 *   @0x172ec0 b 0x172f34 <_Z12GR_Text_DrawffPKcii+0x13c>
 *   @0x172ec4 subs r2, r2, #1
 *   @0x172ec8 beq 0x172f34 <_Z12GR_Text_DrawffPKcii+0x13c>
 *   @0x172ecc ldr r3, [r3]
 *   @0x172ed0 cmp r3, #0
 *   @0x172ed4 bne 0x172ec4 <_Z12GR_Text_DrawffPKcii+0xcc>
 *   @0x172ed8 add r4, r4, #1
 *   @0x172edc vadd.f32 s16, s16, s17
 *   @0x172ee0 cmp r1, r4
 *   @0x172ee4 bgt 0x172ea8 <_Z12GR_Text_DrawffPKcii+0xb0>
 *   @0x172ee8 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv>
 *   @0x172eec ldr r0, [sp, #0x8]
 *   @0x172ef0 cmp r0, #0
 *   @0x172ef4 beq 0x172f0c <_Z12GR_Text_DrawffPKcii+0x114>
 *   @0x172ef8 ldr r4, [r0]
 *   @0x172efc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172f00 cmp r4, #0
 *   @0x172f04 mov r0, r4
 *   @0x172f08 bne 0x172ef8 <_Z12GR_Text_DrawffPKcii+0x100>
 *   @0x172f0c ldr r0, [sp, #0x14]
 *   @0x172f10 mov r3, #0
 *   @0x172f14 str r3, [sp, #0x10]
 *   @0x172f18 cmp r0, r3
 *   @0x172f1c str r3, [sp, #0x8]
 *   @0x172f20 beq 0x172f28 <_Z12GR_Text_DrawffPKcii+0x130>
 *   @0x172f24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x172f28 add sp, sp, #24
 *   @0x172f2c vpop {d8, d9, d10}
 *   @0x172f30 pop {r4, r5, r6, r7, r8, pc}
 *   @0x172f34 ldr r5, [r3, #0x4]
 *   @0x172f38 cmp r5, #0
 *   @0x172f3c beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0>
 *   @0x172f40 ldrh r3, [r5]
 *   @0x172f44 cmp r3, #0
 *   @0x172f48 beq 0x172ed8 <_Z12GR_Text_DrawffPKcii+0xe0>
 *   @0x172f4c ldr r3, [pc, #0x108]
 *   @0x172f50 ldr r8, [r6, r3]
 *   @0x172f54 ldr r3, [r8]
 *   @0x172f58 cmp r3, #1
 *   @0x172f5c beq 0x172fc0 <_Z12GR_Text_DrawffPKcii+0x1c8>
 *   @0x172f60 ldr r2, [pc, #0xf8]
 *   @0x172f64 cmp r3, #2
 *   @0x172f68 vldr s15, [pc, #220]
 *   @0x172f6c ldr r7, [r6, r2]
 *   @0x172f70 beq 0x172ff4 <_Z12GR_Text_DrawffPKcii+0x1fc>
 *   @0x172f74 vadd.f32 s18, s19, s15
 *   @0x172f78 ldr r7, [r7]
 *   @0x172f7c bl 0x169ecc <_Z17GR_Draw_Get_Colorv>
 *   @0x172f80 add r4, r4, #1
 *   @0x172f84 mov r8, r0
 *   @0x172f88 bl 0x169f1c <_Z17GR_Draw_Get_Alphav>
 *   @0x172f8c vadd.f32 s15, s16, s20
 *   @0x172f90 str r8, [sp]
 *   @0x172f94 vmov r1, s18
 *   @0x172f98 mov r3, r5
 *   @0x172f9c vmov r2, s15
 *   @0x172fa0 str r0, [sp, #0x4]
 *   @0x172fa4 mov r0, r7
 *   @0x172fa8 bl 0xf7eec <_ZN7CFontGM11Draw_StringEffPtjf>
 *   @0x172fac ldr r1, [sp, #0x10]
 *   @0x172fb0 vadd.f32 s16, s16, s17
 *   @0x172fb4 cmp r1, r4
 *   @0x172fb8 bgt 0x172ea8 <_Z12GR_Text_DrawffPKcii+0xb0>
 *   @0x172fbc b 0x172ee8 <_Z12GR_Text_DrawffPKcii+0xf0>
 *   @0x172fc0 ldr r3, [pc, #0x98]
 *   @0x172fc4 mov r1, r5
 *   @0x172fc8 ldr r7, [r6, r3]
 *   @0x172fcc ldr r0, [r7]
 *   @0x172fd0 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x172fd4 ldr r3, [r8]
 *   @0x172fd8 cmp r3, #2
 *   @0x172fdc add r0, r0, r0, lsr #31
 *   @0x172fe0 asr r2, r0, #1
 *   @0x172fe4 rsb r2, r2, #0
 *   @0x172fe8 vmov s14, r2
 *   @0x172fec vcvt.f32.s32 s15, s14
 *   @0x172ff0 bne 0x172f74 <_Z12GR_Text_DrawffPKcii+0x17c>
 *   @0x172ff4 ldr r0, [r7]
 *   @0x172ff8 mov r1, r5
 *   @0x172ffc bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x173000 rsb r0, r0, #0
 *   @0x173004 vmov s14, r0
 *   @0x173008 vcvt.f32.s32 s15, s14
 *   @0x17300c b 0x172f74 <_Z12GR_Text_DrawffPKcii+0x17c>
 *   @0x173010 mul r3, r1, r4
 *   @0x173014 add r3, r3, r3, lsr #31
 *   @0x173018 asr r3, r3, #1
 *   @0x17301c vmov s14, r3
 *   @0x173020 vcvt.f32.s32 s15, s14
 *   @0x173024 vsub.f32 s16, s16, s15
 *   @0x173028 b 0x172e90 <_Z12GR_Text_DrawffPKcii+0x98>
 *   @0x17302c ldr r3, [pc, #0x2c]
 *   @0x173030 ldr r1, [pc, #0x2c]
 *   @0x173034 ldr r7, [r6, r3]
 *   @0x173038 add r1, pc, r1
 *   @0x17303c ldr r0, [r7]
 *   @0x173040 bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x173044 mov r4, r0
 *   @0x173048 b 0x172e64 <_Z12GR_Text_DrawffPKcii+0x6c>
 *   @0x17304c andeq r0, r0, r0
 *   @0x173050 ldrsheq r8, [sp], -r8
 *   @0x173054 .word 0x0027edf4
 *   @0x173058 .word 0xffffe65c
 *   @0x17305c .word 0xffffe658
 *   @0x173060 .word 0xffffe654
 *   @0x173064 ldrsbeq r8, [sp], -r0
 *
 * ══ §9/50 LoadSave::fopen(char const*, char const*)  0x18db48  size 624  156 条（0x18db48..0x18ddb8）
 * @func 0x18db48 0x18ddb8  size 624  156 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6634×5 / operator new(unsigned int)×4 / IBuffer::IBuffer(int, eBuffer_Format, int)×2 / LoadSave::ReadBundleFile(char const*, int*) / 0xb65bc / MemoryManager::Free(void const*) / 0xb6538 / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0x4×4 / 0xc×2 / 0x8×2 / 0x10×2 / 0x1b4×1 / 0x-4×1 / 0x134×1 / 0xd8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18db48 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x18db4c mov r4, r1
 *   @0x18db50 sub sp, sp, #8
 *   @0x18db54 mov r1, #116
 *   @0x18db58 mov r6, r0
 *   @0x18db5c mov r0, r4
 *   @0x18db60 bl 0xb6634 <strchr@plt>
 *   @0x18db64 mov r1, #114
 *   @0x18db68 adds r7, r0, #0
 *   @0x18db6c mov r0, r4
 *   @0x18db70 movne r7, #1
 *   @0x18db74 bl 0xb6634 <strchr@plt>
 *   @0x18db78 mov r1, #119
 *   @0x18db7c mov r8, r0
 *   @0x18db80 mov r0, r4
 *   @0x18db84 bl 0xb6634 <strchr@plt>
 *   @0x18db88 mov r1, #97
 *   @0x18db8c mov r9, r0
 *   @0x18db90 mov r0, r4
 *   @0x18db94 bl 0xb6634 <strchr@plt>
 *   @0x18db98 cmp r0, #0
 *   @0x18db9c movne r5, #1
 *   @0x18dba0 movne r9, r5
 *   @0x18dba4 movne r8, r5
 *   @0x18dba8 beq 0x18dd24 <_ZN8LoadSave5fopenEPKcS1_+0x1dc>
 *   @0x18dbac mov r0, r4
 *   @0x18dbb0 mov r1, #43
 *   @0x18dbb4 bl 0xb6634 <strchr@plt>
 *   @0x18dbb8 cmp r0, #0
 *   @0x18dbbc beq 0x18dc08 <_ZN8LoadSave5fopenEPKcS1_+0xc0>
 *   @0x18dbc0 cmp r8, #0
 *   @0x18dbc4 bne 0x18dc28 <_ZN8LoadSave5fopenEPKcS1_+0xe0>
 *   @0x18dbc8 mov r0, #16
 *   @0x18dbcc bl 0x27c524 <_Znwj>
 *   @0x18dbd0 mov r4, r0
 *   @0x18dbd4 mov r0, #64
 *   @0x18dbd8 bl 0x27c524 <_Znwj>
 *   @0x18dbdc mov r2, #1
 *   @0x18dbe0 mov r3, r2
 *   @0x18dbe4 mov r1, #0
 *   @0x18dbe8 mov r5, r0
 *   @0x18dbec bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0x18dbf0 ldr r3, [pc, #0x1b4]
 *   @0x18dbf4 ldr r3, [pc, r3]
 *   @0x18dbf8 add r3, r3, #8
 *   @0x18dbfc str r3, [r5]
 *   @0x18dc00 str r5, [r4]
 *   @0x18dc04 b 0x18dccc <_ZN8LoadSave5fopenEPKcS1_+0x184>
 *   @0x18dc08 cmp r8, #0
 *   @0x18dc0c bne 0x18dc2c <_ZN8LoadSave5fopenEPKcS1_+0xe4>
 *   @0x18dc10 cmp r9, #0
 *   @0x18dc14 moveq r4, r9
 *   @0x18dc18 bne 0x18dbc8 <_ZN8LoadSave5fopenEPKcS1_+0x80>
 *   @0x18dc1c mov r0, r4
 *   @0x18dc20 add sp, sp, #8
 *   @0x18dc24 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x18dc28 mov r9, #1
 *   @0x18dc2c add r4, sp, #8
 *   @0x18dc30 mov r3, #0
 *   @0x18dc34 mov r0, r6
 *   @0x18dc38 str r3, [r4, #-0x4]!
 *   @0x18dc3c mov r1, r4
 *   @0x18dc40 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x18dc44 subs r10, r0, #0
 *   @0x18dc48 beq 0x18dd94 <_ZN8LoadSave5fopenEPKcS1_+0x24c>
 *   @0x18dc4c mov r0, #16
 *   @0x18dc50 bl 0x27c524 <_Znwj>
 *   @0x18dc54 mov r4, r0
 *   @0x18dc58 mov r0, #64
 *   @0x18dc5c bl 0x27c524 <_Znwj>
 *   @0x18dc60 mov r2, #1
 *   @0x18dc64 mov r3, r2
 *   @0x18dc68 ldr r1, [sp, #0x4]
 *   @0x18dc6c mov r8, r0
 *   @0x18dc70 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0x18dc74 ldr r3, [pc, #0x134]
 *   @0x18dc78 mov r1, r10
 *   @0x18dc7c ldr r2, [sp, #0x4]
 *   @0x18dc80 ldr r3, [pc, r3]
 *   @0x18dc84 ldr r0, [r8, #0xc]
 *   @0x18dc88 add r3, r3, #8
 *   @0x18dc8c str r3, [r8]
 *   @0x18dc90 str r8, [r4]
 *   @0x18dc94 bl 0xb65bc <memcpy@plt>
 *   @0x18dc98 cmp r7, #0
 *   @0x18dc9c mov r1, #0
 *   @0x18dca0 str r1, [r4, #0x8]
 *   @0x18dca4 beq 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c>
 *   @0x18dca8 ldr r3, [sp, #0x4]
 *   @0x18dcac cmp r3, #2
 *   @0x18dcb0 bgt 0x18dd58 <_ZN8LoadSave5fopenEPKcS1_+0x210>
 *   @0x18dcb4 mov r0, r10
 *   @0x18dcb8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x18dcbc cmp r9, #0
 *   @0x18dcc0 beq 0x18dd10 <_ZN8LoadSave5fopenEPKcS1_+0x1c8>
 *   @0x18dcc4 cmp r5, #0
 *   @0x18dcc8 bne 0x18dd3c <_ZN8LoadSave5fopenEPKcS1_+0x1f4>
 *   @0x18dccc mov r0, r6
 *   @0x18dcd0 bl 0xb6538 <strlen@plt>
 *   @0x18dcd4 ldr r1, [pc, #0xd8]
 *   @0x18dcd8 mov r3, #1
 *   @0x18dcdc mov r2, #344
 *   @0x18dce0 add r1, pc, r1
 *   @0x18dce4 add r0, r0, r3
 *   @0x18dce8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x18dcec mov r1, r6
 *   @0x18dcf0 str r0, [r4, #0x8]
 *   @0x18dcf4 bl 0xb65a4 <strcpy@plt>
 *   @0x18dcf8 mov r3, #1
 *   @0x18dcfc strb r3, [r4, #0xc]
 *   @0x18dd00 mov r0, r4
 *   @0x18dd04 strb r7, [r4, #0x4]
 *   @0x18dd08 add sp, sp, #8
 *   @0x18dd0c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x18dd10 cmp r4, #0
 *   @0x18dd14 bne 0x18dd00 <_ZN8LoadSave5fopenEPKcS1_+0x1b8>
 *   @0x18dd18 mov r0, r4
 *   @0x18dd1c add sp, sp, #8
 *   @0x18dd20 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x18dd24 adds r8, r8, #0
 *   @0x18dd28 mov r5, r0
 *   @0x18dd2c movne r8, #1
 *   @0x18dd30 adds r9, r9, #0
 *   @0x18dd34 movne r9, #1
 *   @0x18dd38 b 0x18dbac <_ZN8LoadSave5fopenEPKcS1_+0x64>
 *   @0x18dd3c ldr r0, [r4]
 *   @0x18dd40 mov r1, #2
 *   @0x18dd44 mov r2, #0
 *   @0x18dd48 ldr r3, [r0]
 *   @0x18dd4c ldr r3, [r3, #0x10]
 *   @0x18dd50 blx r3
 *   @0x18dd54 b 0x18dccc <_ZN8LoadSave5fopenEPKcS1_+0x184>
 *   @0x18dd58 ldrb r3, [r10]
 *   @0x18dd5c cmp r3, #239
 *   @0x18dd60 bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c>
 *   @0x18dd64 ldrb r3, [r10, #0x1]
 *   @0x18dd68 cmp r3, #187
 *   @0x18dd6c bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c>
 *   @0x18dd70 ldrb r3, [r10, #0x2]
 *   @0x18dd74 cmp r3, #191
 *   @0x18dd78 bne 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c>
 *   @0x18dd7c ldr r0, [r4]
 *   @0x18dd80 mov r2, #3
 *   @0x18dd84 ldr r3, [r0]
 *   @0x18dd88 ldr r3, [r3, #0x10]
 *   @0x18dd8c blx r3
 *   @0x18dd90 b 0x18dcb4 <_ZN8LoadSave5fopenEPKcS1_+0x16c>
 *   @0x18dd94 mov r1, r4
 *   @0x18dd98 mov r0, r6
 *   @0x18dd9c bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0x18dda0 subs r10, r0, #0
 *   @0x18dda4 beq 0x18dc10 <_ZN8LoadSave5fopenEPKcS1_+0xc8>
 *   @0x18dda8 b 0x18dc4c <_ZN8LoadSave5fopenEPKcS1_+0x104>
 *   @0x18ddac .word 0x0025fdbc
 *   @0x18ddb0 eoreq pc, r5, r0, lsr sp
 *   @0x18ddb4 ldrsheq lr, [r11], -r8
 *
 * ══ §10/50 ParticleSystem_Create(int, bool)  0x1a42dc  size 624  149 条（0x1a42dc..0x1a454c）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1a42dc 0x1a454c  size 624  149 条
 * 部分覆盖: 本节 149/156 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a42ec→0x5428e8, 0x1a4330→0x54298c, 0x1a4364→0x54245c, 0x1a436c→0x542460, 0x1a4498→0x54298c
 * 调用序列: CLayerManager::GetNewParticleElement()×2 / CLayerManager::AddNewElementAtDepth(CRoom*, int, CLayerElementBase*, bool, bool)×2 / CLayerManager::GetTargetRoomObj() / CLayerManager::GetLayerFromID(CRoom*, int) / ParticleSystem_Create(int, bool)+0x224 / MemoryManager::SetLength(void**, unsigned int, char const*, int) / MemoryManager::Alloc(unsigned int, char const*, int, bool) / ParticleSystem_Clear(int)
 * 字段偏移 top8: 0x4×6 / 0xc×2 / 0x244×1 / 0x240×1 / 0x200×1 / 0x1d0×1 / 0x1cc×1 / 0x178×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a42dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a42e0 mov r10, r0
 *   @0x1a4300 cmp r9, #0
 *   @0x1a4304 beq 0x1a4364 <_Z21ParticleSystem_Createib+0x88>
 *   @0x1a4308 cmn r0, #1
 *   @0x1a430c beq 0x1a4494 <_Z21ParticleSystem_Createib+0x1b8>
 *   @0x1a4310 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1a4314 subs r4, r0, #0
 *   @0x1a4318 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218>
 *   @0x1a431c mov r1, r10
 *   @0x1a4320 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1a4324 subs r6, r0, #0
 *   @0x1a4328 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218>
 *   @0x1a432c bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv>
 *   @0x1a4330 ldr r3, [pc, #0x200]
 *   @0x1a4334 ldr r3, [r5, r3]
 *   @0x1a4338 mov r9, r0
 *   @0x1a433c ldr r0, [r3]
 *   @0x1a4340 cmp r4, r0
 *   @0x1a4344 beq 0x1a44c4 <_Z21ParticleSystem_Createib+0x1e8>
 *   @0x1a4348 mov r3, #1
 *   @0x1a434c mov r1, #0
 *   @0x1a4350 str r3, [sp]
 *   @0x1a4354 mov r2, r9
 *   @0x1a4358 bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb>
 *   @0x1a435c cmp r9, #0
 *   @0x1a4360 beq 0x1a44f4 <_Z21ParticleSystem_Createib+0x218>
 *   @0x1a4364 ldr r3, [pc, #0x1d0]
 *   @0x1a4368 ldr r12, [r5, r3]
 *   @0x1a436c ldr r3, [pc, #0x1cc]
 *   @0x1a4370 ldr r1, [r12]
 *   @0x1a4374 cmp r1, #0
 *   @0x1a4378 ble 0x1a4500 <_Z21ParticleSystem_Createib+0x224>
 *   @0x1a437c ldr r7, [r5, r3]
 *   @0x1a4380 ldr r5, [r7, #0x4]
 *   @0x1a4384 ldr r6, [r5]
 *   @0x1a4388 cmp r6, #0
 *   @0x1a438c beq 0x1a4518 <_Z21ParticleSystem_Createib+0x23c>
 *   @0x1a4390 add r3, r5, #4
 *   @0x1a4394 mov r4, #0
 *   @0x1a4398 b 0x1a43a8 <_Z21ParticleSystem_Createib+0xcc>
 *   @0x1a439c ldr r2, [r5]
 *   @0x1a43a0 cmp r2, #0
 *   @0x1a43a4 beq 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c>
 *   @0x1a43a8 add r4, r4, #1
 *   @0x1a43ac mov r5, r3
 *   @0x1a43b0 cmp r4, r1
 *   @0x1a43b4 add r3, r3, #4
 *   @0x1a43b8 lsl r6, r4, #2
 *   @0x1a43bc bne 0x1a439c <_Z21ParticleSystem_Createib+0xc0>
 *   @0x1a43c0 add lr, r4, #1
 *   @0x1a43c4 ldr r2, [pc, #0x178]
 *   @0x1a43c8 movw r3, #0x637
 *   @0x1a43cc add r0, r7, #4
 *   @0x1a43d0 add r2, pc, r2
 *   @0x1a43d4 lsl r1, lr, #2
 *   @0x1a43d8 str lr, [r12]
 *   @0x1a43dc str r12, [sp, #0xc]
 *   @0x1a43e0 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x1a43e4 ldr r12, [sp, #0xc]
 *   @0x1a43e8 ldr r5, [r7, #0x4]
 *   @0x1a43ec ldr r3, [r12]
 *   @0x1a43f0 add r5, r5, r6
 *   @0x1a43f4 str r3, [r7]
 *   @0x1a43f8 ldr r1, [pc, #0x148]
 *   @0x1a43fc movw r2, #0x63c
 *   @0x1a4400 mov r3, #1
 *   @0x1a4404 mov r0, #56
 *   @0x1a4408 add r1, pc, r1
 *   @0x1a440c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x1a4410 ldrb r3, [r8]
 *   @0x1a4414 cmp r3, #0
 *   @0x1a4418 mvnne r2, #0
 *   @0x1a441c str r0, [r5]
 *   @0x1a4420 mov r0, r4
 *   @0x1a4424 ldrne r3, [r7, #0x4]
 *   @0x1a4428 ldrne r3, [r3, r6]
 *   @0x1a442c strne r2, [r3, #0x2c]
 *   @0x1a4430 strne r2, [r3, #0x30]
 *   @0x1a4434 bl 0x1a4180 <_Z20ParticleSystem_Cleari>
 *   @0x1a4438 ldrb r3, [r8]
 *   @0x1a443c cmp r3, #0
 *   @0x1a4440 beq 0x1a4488 <_Z21ParticleSystem_Createib+0x1ac>
 *   @0x1a4444 ldr r3, [r7, #0x4]
 *   @0x1a4448 cmn r10, #1
 *   @0x1a444c ldr r2, [r9, #0x4]
 *   @0x1a4450 eor r11, r11, #1
 *   @0x1a4454 str r4, [r9, #0x1c]
 *   @0x1a4458 ldr r3, [r3, r6]
 *   @0x1a445c str r2, [r3, #0x2c]
 *   @0x1a4460 strb r11, [r3, #0x34]
 *   @0x1a4464 beq 0x1a4488 <_Z21ParticleSystem_Createib+0x1ac>
 *   @0x1a4468 ldr r2, [r9, #0x10]
 *   @0x1a446c vldr s15, [r2, #4]
 *   @0x1a4470 vcvt.f32.s32 s15, s15
 *   @0x1a4474 mov r0, r4
 *   @0x1a4478 str r10, [r3, #0x30]
 *   @0x1a447c vstr s15, [r3, #28]
 *   @0x1a4480 add sp, sp, #20
 *   @0x1a4484 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a4488 mov r0, r4
 *   @0x1a448c add sp, sp, #20
 *   @0x1a4490 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a4494 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv>
 *   @0x1a4498 ldr r12, [pc, #0x98]
 *   @0x1a449c mov r1, #0
 *   @0x1a44a0 ldr r12, [r5, r12]
 *   @0x1a44a4 mov r9, r0
 *   @0x1a44a8 mov r0, #1
 *   @0x1a44ac mov r3, r0
 *   @0x1a44b0 str r0, [sp]
 *   @0x1a44b4 mov r2, r9
 *   @0x1a44b8 ldr r0, [r12]
 *   @0x1a44bc bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb>
 *   @0x1a44c0 b 0x1a435c <_Z21ParticleSystem_Createib+0x80>
 *   @0x1a44c4 mov r1, r6
 *   @0x1a44c8 mov r0, r4
 *   @0x1a44cc mov r2, r9
 *   @0x1a44d0 mov r3, #1
 *   @0x1a44d4 bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1a44d8 cmn r0, #1
 *   @0x1a44dc bne 0x1a435c <_Z21ParticleSystem_Createib+0x80>
 *   @0x1a44e0 mov r0, r4
 *   @0x1a44e4 ldr r1, [r9, #0x4]
 *   @0x1a44e8 mov r2, #1
 *   @0x1a44ec mov r3, #0
 *   @0x1a44f0 bl 0x1c013c <_ZN13CLayerManager13RemoveElementEP5CRoomibb>
 *   @0x1a44f4 mvn r0, #0
 *   @0x1a44f8 add sp, sp, #20
 *   @0x1a44fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a4500 beq 0x1a4520 <_Z21ParticleSystem_Createib+0x244>
 *   @0x1a4504 ldr r7, [r5, r3]
 *   @0x1a4508 mov r6, #0
 *   @0x1a450c mov r4, r6
 *   @0x1a4510 ldr r5, [r7, #0x4]
 *   @0x1a4514 b 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c>
 *   @0x1a4518 mov r4, r6
 *   @0x1a451c b 0x1a43f8 <_Z21ParticleSystem_Createib+0x11c>
 *   @0x1a4520 mov r6, r1
 *   @0x1a4524 mov r4, r1
 *   @0x1a4528 ldr r7, [r5, r3]
 *   @0x1a452c b 0x1a43c0 <_Z21ParticleSystem_Createib+0xe4>
 *   @0x1a4530 eoreq sp, r4, r12, asr r9
 *   @0x1a4534 .word 0xffffbcd4
 *   @0x1a4538 .word 0xffffbcd8
 *   @0x1a453c .word 0xffffeb64
 *   @0x1a4540 .word 0xffffeb68
 *   @0x1a4544 ldrheq r8, [r10], -r0
 *   @0x1a4548 andseq r8, r10, r8, ror r11
 *
 * ══ §11/50 CDS_Stack::Clear()  0x20f270  size 620  155 条（0x20f270..0x20f4dc）
 * @func 0x20f270 0x20f4dc  size 620  155 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×4 / LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / YYFree(void const*)×2 / operator delete(void*)×2 / CDS_Stack::Clear()+0xb0 / MemoryManager::Free(void const*) / CDS_Stack::Clear()+0x170
 * 字段偏移 top8: 0x4×18 / 0xc×10 / 0x8×7 / 0x10×3 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20f270 ldr r3, [r0, #0x4]
 *   @0x20f274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20f278 cmp r3, #0
 *   @0x20f27c mov r8, r0
 *   @0x20f280 sub sp, sp, #12
 *   @0x20f284 movgt r7, #0
 *   @0x20f288 ldr r0, [r0, #0xc]
 *   @0x20f28c movgt r5, r7
 *   @0x20f290 movgt r11, #5
 *   @0x20f294 bgt 0x20f2b8 <_ZN9CDS_Stack5ClearEv+0x48>
 *   @0x20f298 b 0x20f320 <_ZN9CDS_Stack5ClearEv+0xb0>
 *   @0x20f29c str r5, [r6]
 *   @0x20f2a0 add r7, r7, #1
 *   @0x20f2a4 ldr r3, [r8, #0x4]
 *   @0x20f2a8 str r5, [r6, #0x8]
 *   @0x20f2ac cmp r3, r7
 *   @0x20f2b0 str r11, [r6, #0xc]
 *   @0x20f2b4 ble 0x20f320 <_ZN9CDS_Stack5ClearEv+0xb0>
 *   @0x20f2b8 add r6, r0, r7, lsl #4
 *   @0x20f2bc ldr r1, [r6, #0xc]
 *   @0x20f2c0 sub r3, r1, #1
 *   @0x20f2c4 bic r3, r3, #-16777216
 *   @0x20f2c8 bics r4, r3, #3
 *   @0x20f2cc bne 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f2d0 bic r1, r1, #-16777216
 *   @0x20f2d4 cmp r1, #2
 *   @0x20f2d8 beq 0x20f36c <_ZN9CDS_Stack5ClearEv+0xfc>
 *   @0x20f2dc cmp r1, #3
 *   @0x20f2e0 beq 0x20f33c <_ZN9CDS_Stack5ClearEv+0xcc>
 *   @0x20f2e4 cmp r1, #1
 *   @0x20f2e8 bne 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f2ec ldr r4, [r6]
 *   @0x20f2f0 cmp r4, #0
 *   @0x20f2f4 beq 0x20f318 <_ZN9CDS_Stack5ClearEv+0xa8>
 *   @0x20f2f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f2fc ldr r9, [r4, #0x4]
 *   @0x20f300 sub r9, r9, #1
 *   @0x20f304 str r9, [r4, #0x4]
 *   @0x20f308 cmp r9, #0
 *   @0x20f30c beq 0x20f3a8 <_ZN9CDS_Stack5ClearEv+0x138>
 *   @0x20f310 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f314 ldr r0, [r8, #0xc]
 *   @0x20f318 str r5, [r6]
 *   @0x20f31c b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f320 mov r4, #0
 *   @0x20f324 str r4, [r8, #0x4]
 *   @0x20f328 str r4, [r8, #0x8]
 *   @0x20f32c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x20f330 str r4, [r8, #0xc]
 *   @0x20f334 add sp, sp, #12
 *   @0x20f338 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20f33c ldr r3, [r6, #0x8]
 *   @0x20f340 tst r3, #8
 *   @0x20f344 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f348 ldr r3, [r6]
 *   @0x20f34c cmp r3, #0
 *   @0x20f350 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f354 ldr r1, [r3]
 *   @0x20f358 mov r0, r3
 *   @0x20f35c ldr r3, [r1, #0x4]
 *   @0x20f360 blx r3
 *   @0x20f364 ldr r0, [r8, #0xc]
 *   @0x20f368 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f36c ldr r10, [r6]
 *   @0x20f370 cmp r10, #0
 *   @0x20f374 beq 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f378 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f37c ldr r3, [r10]
 *   @0x20f380 ldr r1, [r10, #0x8]
 *   @0x20f384 sub r3, r3, #1
 *   @0x20f388 str r3, [r10]
 *   @0x20f38c cmp r6, r1
 *   @0x20f390 streq r4, [r10, #0x8]
 *   @0x20f394 cmp r3, #0
 *   @0x20f398 ble 0x20f3e0 <_ZN9CDS_Stack5ClearEv+0x170>
 *   @0x20f39c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f3a0 ldr r0, [r8, #0xc]
 *   @0x20f3a4 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f3a8 ldr r0, [r4]
 *   @0x20f3ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f3b0 str r9, [r4]
 *   @0x20f3b4 str r9, [r4, #0x8]
 *   @0x20f3b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20f3bc ldr r9, [r4, #0x4]
 *   @0x20f3c0 sub r9, r9, #1
 *   @0x20f3c4 str r9, [r4, #0x4]
 *   @0x20f3c8 cmp r9, #0
 *   @0x20f3cc beq 0x20f45c <_ZN9CDS_Stack5ClearEv+0x1ec>
 *   @0x20f3d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f3d4 mov r0, r4
 *   @0x20f3d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f3dc b 0x20f310 <_ZN9CDS_Stack5ClearEv+0xa0>
 *   @0x20f3e0 ldr r3, [r10, #0x10]
 *   @0x20f3e4 cmp r3, #0
 *   @0x20f3e8 movgt r2, #0
 *   @0x20f3ec strgt r2, [sp]
 *   @0x20f3f0 ble 0x20f4b0 <_ZN9CDS_Stack5ClearEv+0x240>
 *   @0x20f3f4 ldr r2, [sp]
 *   @0x20f3f8 ldr r3, [r10, #0x4]
 *   @0x20f3fc add r2, r3, r2, lsl #3
 *   @0x20f400 str r2, [sp, #0x4]
 *   @0x20f404 ldr r2, [sp]
 *   @0x20f408 ldr r1, [r3, r2, lsl #3]
 *   @0x20f40c ldr r3, [sp, #0x4]
 *   @0x20f410 ldr r4, [r3, #0x4]
 *   @0x20f414 add r9, r4, r1, lsl #4
 *   @0x20f418 cmp r4, r9
 *   @0x20f41c blo 0x20f438 <_ZN9CDS_Stack5ClearEv+0x1c8>
 *   @0x20f420 b 0x20f4d4 <_ZN9CDS_Stack5ClearEv+0x264>
 *   @0x20f424 str r5, [r4, #0x8]
 *   @0x20f428 str r11, [r4, #0xc]
 *   @0x20f42c str r5, [r4], #16
 *   @0x20f430 cmp r9, r4
 *   @0x20f434 bls 0x20f480 <_ZN9CDS_Stack5ClearEv+0x210>
 *   @0x20f438 ldr r3, [r4, #0xc]
 *   @0x20f43c sub r3, r3, #1
 *   @0x20f440 bic r3, r3, #-16777216
 *   @0x20f444 bic r3, r3, #3
 *   @0x20f448 cmp r3, #0
 *   @0x20f44c bne 0x20f424 <_ZN9CDS_Stack5ClearEv+0x1b4>
 *   @0x20f450 mov r0, r4
 *   @0x20f454 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20f458 b 0x20f424 <_ZN9CDS_Stack5ClearEv+0x1b4>
 *   @0x20f45c ldr r0, [r4]
 *   @0x20f460 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20f464 mov r0, r4
 *   @0x20f468 str r9, [r4]
 *   @0x20f46c str r9, [r4, #0x8]
 *   @0x20f470 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20f474 mov r0, r4
 *   @0x20f478 bl 0x27d1d0 <_ZdlPv>
 *   @0x20f47c b 0x20f3d0 <_ZN9CDS_Stack5ClearEv+0x160>
 *   @0x20f480 ldr r2, [sp, #0x4]
 *   @0x20f484 ldr r0, [r2, #0x4]
 *   @0x20f488 ldr r3, [sp]
 *   @0x20f48c add r3, r3, #1
 *   @0x20f490 str r3, [sp]
 *   @0x20f494 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20f498 ldr r2, [sp, #0x4]
 *   @0x20f49c ldr r3, [r10, #0x10]
 *   @0x20f4a0 str r5, [r2, #0x4]
 *   @0x20f4a4 ldr r2, [sp]
 *   @0x20f4a8 cmp r2, r3
 *   @0x20f4ac blt 0x20f3f4 <_ZN9CDS_Stack5ClearEv+0x184>
 *   @0x20f4b0 ldr r0, [r10, #0x4]
 *   @0x20f4b4 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20f4b8 mov r0, r10
 *   @0x20f4bc str r5, [r10, #0x4]
 *   @0x20f4c0 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x20f4c4 str r5, [r6]
 *   @0x20f4c8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20f4cc ldr r0, [r8, #0xc]
 *   @0x20f4d0 b 0x20f29c <_ZN9CDS_Stack5ClearEv+0x2c>
 *   @0x20f4d4 mov r0, r4
 *   @0x20f4d8 b 0x20f488 <_ZN9CDS_Stack5ClearEv+0x218>
 *
 * ══ §12/50 ASYNCFunc_BackgroundAdd(HTTP_REQ_CONTEXT*, void*, int*)  0xc3034  size 616  154 条（0xc3034..0xc329c）
 * @func 0xc3034 0xc329c  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CreateDsMap(int, ...) / ASYNCFunc_BackgroundAdd(HTTP_REQ_CONTEXT*, void*, int*)+0xb0 / CBackground::LoadFromJPEGData(void*, int, bool, bool, bool, bool) / CBackground::LoadFromGIFData(void*, int, bool, bool, bool, bool) / CBackground::LoadFromPNGData(void*, int, bool, bool, bool, bool)
 * 字段偏移 top8: 0x4×7 / 0x2×6 / 0x3c×4 / 0x20×3 / 0x34×3 / 0x1×3 / 0x8×3 / 0x144×2
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc3034 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc3038 vldr s12, [r0, #40]
 *   @0xc303c vmov.f64 d7, #-1.000000e+00
 *   @0xc3040 ldr r8, [r1]
 *   @0xc3044 mov r7, r1
 *   @0xc3048 ldr r1, [r0, #0x3c]
 *   @0xc304c sub sp, sp, #60
 *   @0xc3050 mov r12, #0
 *   @0xc3054 mov r9, r2
 *   @0xc3058 vmov s13, r8
 *   @0xc305c cmp r1, r12
 *   @0xc3060 ldr r1, [pc, #0x210]
 *   @0xc3064 mov r4, #0
 *   @0xc3068 ldr r2, [r0, #0x20]
 *   @0xc306c mov r5, #0
 *   @0xc3070 add r1, pc, r1
 *   @0xc3074 ldr r3, [pc, #0x200]
 *   @0xc3078 str r1, [sp, #0x24]
 *   @0xc307c mov r6, r0
 *   @0xc3080 ldr lr, [pc, #0x1f8]
 *   @0xc3084 add r3, pc, r3
 *   @0xc3088 vcvt.f64.s32 d5, s13
 *   @0xc308c ldr r1, [pc, #0x1f0]
 *   @0xc3090 stm sp, {r2, r3}
 *   @0xc3094 vmovgt d7, r4, r5
 *   @0xc3098 add lr, pc, lr
 *   @0xc309c mov r3, r5
 *   @0xc30a0 str r12, [sp, #0x10]
 *   @0xc30a4 mov r0, #4
 *   @0xc30a8 str r12, [sp, #0x20]
 *   @0xc30ac mov r2, r4
 *   @0xc30b0 str r12, [sp, #0x30]
 *   @0xc30b4 add r1, pc, r1
 *   @0xc30b8 str lr, [sp, #0x14]
 *   @0xc30bc vstr d7, [sp, #40]
 *   @0xc30c0 vcvt.f64.s32 d6, s12
 *   @0xc30c4 vstr d5, [sp, #8]
 *   @0xc30c8 vstr d6, [sp, #24]
 *   @0xc30cc bl 0x20bdc0 <_Z11CreateDsMapiz>
 *   @0xc30d0 str r0, [r9]
 *   @0xc30d4 ldr r3, [r6, #0x28]
 *   @0xc30d8 ldr r12, [r7, #0x4]
 *   @0xc30dc cmp r3, #200
 *   @0xc30e0 beq 0xc30f0 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xbc>
 *   @0xc30e4 mov r0, #60
 *   @0xc30e8 add sp, sp, #60
 *   @0xc30ec pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc30f0 ldr r2, [r6, #0x3c]
 *   @0xc30f4 cmp r2, #0
 *   @0xc30f8 ble 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0>
 *   @0xc30fc ldr r3, [pc, #0x184]
 *   @0xc3100 add r3, pc, r3
 *   @0xc3104 ldr r3, [r3, #0x4]
 *   @0xc3108 ldr r0, [r3, r8, lsl #2]
 *   @0xc310c cmp r0, #0
 *   @0xc3110 beq 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0>
 *   @0xc3114 ldr r4, [r6, #0x34]
 *   @0xc3118 and r3, r12, #1
 *   @0xc311c eor r5, r3, #1
 *   @0xc3120 ldrb r1, [r4]
 *   @0xc3124 cmp r1, #255
 *   @0xc3128 beq 0xc3170 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x13c>
 *   @0xc312c cmp r1, #71
 *   @0xc3130 bne 0xc320c <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x1d8>
 *   @0xc3134 ldrb r3, [r4, #0x1]
 *   @0xc3138 cmp r3, #73
 *   @0xc313c beq 0xc31b4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x180>
 *   @0xc3140 ldr r3, [pc, #0x144]
 *   @0xc3144 ldr r1, [pc, #0x144]
 *   @0xc3148 ldr r3, [pc, r3]
 *   @0xc314c ldr r2, [r6, #0x20]
 *   @0xc3150 add r1, pc, r1
 *   @0xc3154 ldr r0, [r3]
 *   @0xc3158 ldr r3, [r0]
 *   @0xc315c ldr r3, [r3, #0xc]
 *   @0xc3160 blx r3
 *   @0xc3164 mov r0, #60
 *   @0xc3168 add sp, sp, #60
 *   @0xc316c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xc3170 ldrb r1, [r4, #0x1]
 *   @0xc3174 cmp r1, #216
 *   @0xc3178 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc317c ldrb r1, [r4, #0x2]
 *   @0xc3180 cmp r1, #255
 *   @0xc3184 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc3188 ubfx r1, r12, #0x1, #0x1
 *   @0xc318c str r5, [sp, #0x8]
 *   @0xc3190 ubfx r12, r12, #0x2, #0x1
 *   @0xc3194 str r1, [sp]
 *   @0xc3198 str r12, [sp, #0x4]
 *   @0xc319c mov r1, r4
 *   @0xc31a0 bl 0xc271c <_ZN11CBackground16LoadFromJPEGDataEPvibbbb>
 *   @0xc31a4 cmp r0, #0
 *   @0xc31a8 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0>
 *   @0xc31ac ldrb r1, [r4]
 *   @0xc31b0 b 0xc312c <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xf8>
 *   @0xc31b4 ldrb r3, [r4, #0x2]
 *   @0xc31b8 cmp r3, #70
 *   @0xc31bc bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc31c0 ldrb r3, [r4, #0x3]
 *   @0xc31c4 cmp r3, #56
 *   @0xc31c8 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc31cc ldr r2, [pc, #0xc0]
 *   @0xc31d0 ldr r3, [r7, #0x4]
 *   @0xc31d4 add r2, pc, r2
 *   @0xc31d8 str r5, [sp, #0x8]
 *   @0xc31dc ubfx r0, r3, #0x1, #0x1
 *   @0xc31e0 ubfx r1, r3, #0x2, #0x1
 *   @0xc31e4 ldr r2, [r2, #0x4]
 *   @0xc31e8 and r3, r3, #1
 *   @0xc31ec stm sp, {r0, r1}
 *   @0xc31f0 ldr r1, [r6, #0x34]
 *   @0xc31f4 ldr r0, [r2, r8, lsl #2]
 *   @0xc31f8 ldr r2, [r6, #0x3c]
 *   @0xc31fc bl 0xc279c <_ZN11CBackground15LoadFromGIFDataEPvibbbb>
 *   @0xc3200 cmp r0, #0
 *   @0xc3204 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0>
 *   @0xc3208 ldrb r1, [r4]
 *   @0xc320c cmp r1, #137
 *   @0xc3210 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc3214 ldrb r3, [r4, #0x1]
 *   @0xc3218 cmp r3, #80
 *   @0xc321c bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc3220 ldrb r3, [r4, #0x2]
 *   @0xc3224 cmp r3, #78
 *   @0xc3228 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc322c ldrb r3, [r4, #0x3]
 *   @0xc3230 cmp r3, #71
 *   @0xc3234 bne 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc3238 ldr r2, [pc, #0x58]
 *   @0xc323c ldr r3, [r7, #0x4]
 *   @0xc3240 add r2, pc, r2
 *   @0xc3244 str r5, [sp, #0x8]
 *   @0xc3248 ubfx r0, r3, #0x1, #0x1
 *   @0xc324c ubfx r1, r3, #0x2, #0x1
 *   @0xc3250 ldr r2, [r2, #0x4]
 *   @0xc3254 and r3, r3, #1
 *   @0xc3258 stm sp, {r0, r1}
 *   @0xc325c ldr r1, [r6, #0x34]
 *   @0xc3260 ldr r0, [r2, r8, lsl #2]
 *   @0xc3264 ldr r2, [r6, #0x3c]
 *   @0xc3268 bl 0xc26ac <_ZN11CBackground15LoadFromPNGDataEPvibbbb>
 *   @0xc326c cmp r0, #0
 *   @0xc3270 bne 0xc30e4 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0xb0>
 *   @0xc3274 b 0xc3140 <_Z23ASYNCFunc_BackgroundAddP16HTTP_REQ_CONTEXTPvPi+0x10c>
 *   @0xc3278 eoreq sp, r6, r0, ror #19
 *   @0xc327c .word 0x0026d9bc
 *   @0xc3280 eoreq sp, r6, r12, lsr #19
 *   @0xc3284 eoreq sp, r6, r0, lsl #19
 *   @0xc3288 eorseq r6, r11, r8, lsr #23
 *   @0xc328c eorseq r10, r2, r12, asr #11
 *   @0xc3290 eoreq sp, r6, r8, lsl #18
 *   @0xc3294 ldrsbteq r6, [r11], -r4
 *   @0xc3298 eorseq r6, r11, r8, ror #20
 *
 * ══ §13/50 RValue::Serialise(IBuffer*)  0xcf47c  size 616  154 条（0xcf47c..0xcf6e4）
 * @func 0xcf47c 0xcf6e4  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RValue::Serialise(IBuffer*)+0x1dc / RValue::Serialise(IBuffer*)
 * 字段偏移 top8: 0x38×7 / 0x30×7 / 0x8×7 / 0x4×4 / 0x2c×3 / 0x10×3 / 0xc×2 / 0x3×2
 * VFP 指令 16 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcf47c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcf480 add r8, r1, #44
 *   @0xcf484 ldr r4, [r0, #0xc]
 *   @0xcf488 mov r6, r1
 *   @0xcf48c ldr r3, [r1]
 *   @0xcf490 mov r7, r0
 *   @0xcf494 mov r1, #0
 *   @0xcf498 mov r2, r8
 *   @0xcf49c vmov s15, r4
 *   @0xcf4a0 str r1, [r6, #0x38]
 *   @0xcf4a4 mov r0, r6
 *   @0xcf4a8 mov r1, #6
 *   @0xcf4ac vcvt.f64.s32 d7, s15
 *   @0xcf4b0 vmov r4, r5, d7
 *   @0xcf4b4 vstr s14, [r6, #44]
 *   @0xcf4b8 str r5, [r6, #0x30]
 *   @0xcf4bc ldr r3, [r3, #0x8]
 *   @0xcf4c0 blx r3
 *   @0xcf4c4 ldr r3, [r7, #0xc]
 *   @0xcf4c8 cmp r3, #13
 *   @0xcf4cc addls pc, pc, r3, lsl #2
 *   @0xcf4d0 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4d4 b 0xcf544 <_ZN6RValue9SerialiseEP7IBuffer+0xc8>
 *   @0xcf4d8 b 0xcf578 <_ZN6RValue9SerialiseEP7IBuffer+0xfc>
 *   @0xcf4dc b 0xcf594 <_ZN6RValue9SerialiseEP7IBuffer+0x118>
 *   @0xcf4e0 b 0xcf670 <_ZN6RValue9SerialiseEP7IBuffer+0x1f4>
 *   @0xcf4e4 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4e8 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4ec b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4f0 b 0xcf6a8 <_ZN6RValue9SerialiseEP7IBuffer+0x22c>
 *   @0xcf4f4 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4f8 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf4fc b 0xcf510 <_ZN6RValue9SerialiseEP7IBuffer+0x94>
 *   @0xcf500 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf504 b 0xcf50c <_ZN6RValue9SerialiseEP7IBuffer+0x90>
 *   @0xcf508 b 0xcf544 <_ZN6RValue9SerialiseEP7IBuffer+0xc8>
 *   @0xcf50c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf510 ldr r1, [r7]
 *   @0xcf514 mov r12, #10
 *   @0xcf518 ldr lr, [r7, #0x4]
 *   @0xcf51c mov r2, r8
 *   @0xcf520 ldr r3, [r6]
 *   @0xcf524 mov r0, r6
 *   @0xcf528 str r1, [r6, #0x2c]
 *   @0xcf52c mov r1, #12
 *   @0xcf530 str lr, [r6, #0x30]
 *   @0xcf534 str r12, [r6, #0x38]
 *   @0xcf538 ldr r3, [r3, #0x8]
 *   @0xcf53c blx r3
 *   @0xcf540 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf544 ldr r1, [r7]
 *   @0xcf548 mov r12, #0
 *   @0xcf54c ldr lr, [r7, #0x4]
 *   @0xcf550 mov r2, r8
 *   @0xcf554 ldr r3, [r6]
 *   @0xcf558 mov r0, r6
 *   @0xcf55c str r1, [r6, #0x2c]
 *   @0xcf560 mov r1, #9
 *   @0xcf564 str lr, [r6, #0x30]
 *   @0xcf568 str r12, [r6, #0x38]
 *   @0xcf56c ldr r3, [r3, #0x8]
 *   @0xcf570 blx r3
 *   @0xcf574 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf578 ldr r3, [r7]
 *   @0xcf57c mov r0, r6
 *   @0xcf580 cmp r3, #0
 *   @0xcf584 ldrne r1, [r3]
 *   @0xcf588 moveq r1, r3
 *   @0xcf58c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xcf590 b 0xcddb8 <_ZN7IBuffer5WriteEPKc>
 *   @0xcf594 ldr r3, [r7]
 *   @0xcf598 cmp r3, #0
 *   @0xcf59c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf5a0 ldr r4, [r3, #0x10]
 *   @0xcf5a4 mov r9, #0
 *   @0xcf5a8 ldr r3, [r6]
 *   @0xcf5ac mov r2, r8
 *   @0xcf5b0 mov r0, r6
 *   @0xcf5b4 str r9, [r6, #0x38]
 *   @0xcf5b8 vmov s15, r4
 *   @0xcf5bc mov r1, #6
 *   @0xcf5c0 vcvt.f64.s32 d7, s15
 *   @0xcf5c4 vmov r4, r5, d7
 *   @0xcf5c8 vstr s14, [r6, #44]
 *   @0xcf5cc str r5, [r6, #0x30]
 *   @0xcf5d0 ldr r3, [r3, #0x8]
 *   @0xcf5d4 blx r3
 *   @0xcf5d8 ldr r3, [r7]
 *   @0xcf5dc ldr r2, [r3, #0x10]
 *   @0xcf5e0 cmp r2, r9
 *   @0xcf5e4 pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf5e8 ldr r10, [r3, #0x4]
 *   @0xcf5ec mov r0, r6
 *   @0xcf5f0 ldr r12, [r6]
 *   @0xcf5f4 mov r3, #0
 *   @0xcf5f8 mov r1, #6
 *   @0xcf5fc mov r2, r8
 *   @0xcf600 ldr r4, [r10, r9, lsl #3]
 *   @0xcf604 add r11, r10, r9, lsl #3
 *   @0xcf608 str r3, [r6, #0x38]
 *   @0xcf60c vmov s15, r4
 *   @0xcf610 vcvt.f64.s32 d7, s15
 *   @0xcf614 vmov r4, r5, d7
 *   @0xcf618 vstr s14, [r6, #44]
 *   @0xcf61c str r5, [r6, #0x30]
 *   @0xcf620 ldr r12, [r12, #0x8]
 *   @0xcf624 blx r12
 *   @0xcf628 ldr r3, [r10, r9, lsl #3]
 *   @0xcf62c cmp r3, #0
 *   @0xcf630 movgt r4, #0
 *   @0xcf634 ble 0xcf658 <_ZN6RValue9SerialiseEP7IBuffer+0x1dc>
 *   @0xcf638 ldr r0, [r11, #0x4]
 *   @0xcf63c mov r1, r6
 *   @0xcf640 add r0, r0, r4, lsl #4
 *   @0xcf644 add r4, r4, #1
 *   @0xcf648 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer>
 *   @0xcf64c ldr r3, [r11]
 *   @0xcf650 cmp r3, r4
 *   @0xcf654 bgt 0xcf638 <_ZN6RValue9SerialiseEP7IBuffer+0x1bc>
 *   @0xcf658 ldr r3, [r7]
 *   @0xcf65c add r9, r9, #1
 *   @0xcf660 ldr r2, [r3, #0x10]
 *   @0xcf664 cmp r2, r9
 *   @0xcf668 bgt 0xcf5e8 <_ZN6RValue9SerialiseEP7IBuffer+0x16c>
 *   @0xcf66c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf670 ldr r3, [r7]
 *   @0xcf674 mov r1, #10
 *   @0xcf678 ldr r12, [r6]
 *   @0xcf67c mov r2, r8
 *   @0xcf680 str r1, [r6, #0x38]
 *   @0xcf684 mov r0, r6
 *   @0xcf688 asr r5, r3, #31
 *   @0xcf68c mov r4, r3
 *   @0xcf690 str r3, [r6, #0x2c]
 *   @0xcf694 mov r1, #12
 *   @0xcf698 str r5, [r6, #0x30]
 *   @0xcf69c ldr r3, [r12, #0x8]
 *   @0xcf6a0 blx r3
 *   @0xcf6a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xcf6a8 ldr r4, [r7]
 *   @0xcf6ac mov r1, #0
 *   @0xcf6b0 ldr r3, [r6]
 *   @0xcf6b4 mov r2, r8
 *   @0xcf6b8 str r1, [r6, #0x38]
 *   @0xcf6bc mov r0, r6
 *   @0xcf6c0 vmov s15, r4
 *   @0xcf6c4 mov r1, #6
 *   @0xcf6c8 vcvt.f64.s32 d7, s15
 *   @0xcf6cc vmov r4, r5, d7
 *   @0xcf6d0 vstr s14, [r6, #44]
 *   @0xcf6d4 str r5, [r6, #0x30]
 *   @0xcf6d8 ldr r3, [r3, #0x8]
 *   @0xcf6dc blx r3
 *   @0xcf6e0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §14/50 GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x173338  size 616  154 条（0x173338..0x1735a0）
 * @func 0x173338 0x1735a0  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / CFontGM::TextWidth(unsigned short*)×2 / SetFont() / Split_TextBlock(char const*, int, TStringList*) / GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float)+0x230 / GR_Text_Draw_Color(float, float, char const*, int, int, unsigned int, unsigned int, unsigned int, unsigned int, float)+0xf0 / CFontGM::Draw_String_Color(float, float, unsigned short*, unsigned int, unsigned int, unsigned int, unsigned int, float) / CFontGM::TextHeight(unsigned short*)
 * 字段偏移 top8: 0x28×6 / 0x20×4 / 0x2c×2 / 0x1c×2 / 0x70×1 / 0x24×1 / 0x1f8×1 / 0x1ec×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173338 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17333c vpush {d8, d9, d10}
 *   @0x173340 sub sp, sp, #52
 *   @0x173344 vldr s19, [sp, #132]
 *   @0x173348 add r5, sp, #116
 *   @0x17334c mov r10, r2
 *   @0x173350 ldr r9, [sp, #0x70]
 *   @0x173354 mov r12, #0
 *   @0x173358 mov r4, r3
 *   @0x17335c vmov s18, r0
 *   @0x173360 str r12, [sp, #0x24]
 *   @0x173364 vmov s16, r1
 *   @0x173368 str r12, [sp, #0x20]
 *   @0x17336c str r12, [sp, #0x2c]
 *   @0x173370 str r12, [sp, #0x28]
 *   @0x173374 ldm r5, {r5, r6, r7, r8}
 *   @0x173378 bl 0x1724e4 <_Z7SetFontv>
 *   @0x17337c mov r1, r9
 *   @0x173380 mov r0, r10
 *   @0x173384 add r2, sp, #32
 *   @0x173388 bl 0x172560 <_Z15Split_TextBlockPKciP11TStringList>
 *   @0x17338c ldr r9, [pc, #0x1f8]
 *   @0x173390 cmp r4, #0
 *   @0x173394 add r9, pc, r9
 *   @0x173398 blt 0x173568 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x230>
 *   @0x17339c ldr r3, [pc, #0x1ec]
 *   @0x1733a0 ldr r1, [sp, #0x28]
 *   @0x1733a4 ldr r3, [r9, r3]
 *   @0x1733a8 ldr r3, [r3]
 *   @0x1733ac cmp r3, #1
 *   @0x1733b0 beq 0x17354c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x214>
 *   @0x1733b4 cmp r3, #2
 *   @0x1733b8 muleq r2, r1, r4
 *   @0x1733bc vmoveq s15, r2
 *   @0x1733c0 vcvteq.f32.s32 s15, s15
 *   @0x1733c4 vsubeq.f32 s16, s16, s15
 *   @0x1733c8 cmp r1, #0
 *   @0x1733cc ldrle r0, [sp, #0x20]
 *   @0x1733d0 ble 0x173428 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf0>
 *   @0x1733d4 vmov s14, r4
 *   @0x1733d8 ldr r0, [sp, #0x20]
 *   @0x1733dc mov r4, #0
 *   @0x1733e0 vldr s20, [pc, #416]
 *   @0x1733e4 vcvt.f32.s32 s17, s14
 *   @0x1733e8 cmp r0, #0
 *   @0x1733ec beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0>
 *   @0x1733f0 cmp r4, #0
 *   @0x1733f4 movne r2, r4
 *   @0x1733f8 movne r3, r0
 *   @0x1733fc bne 0x17340c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xd4>
 *   @0x173400 b 0x17346c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x134>
 *   @0x173404 subs r2, r2, #1
 *   @0x173408 beq 0x173470 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x138>
 *   @0x17340c ldr r3, [r3]
 *   @0x173410 cmp r3, #0
 *   @0x173414 bne 0x173404 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xcc>
 *   @0x173418 add r4, r4, #1
 *   @0x17341c vadd.f32 s16, s16, s17
 *   @0x173420 cmp r1, r4
 *   @0x173424 bgt 0x1733e8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xb0>
 *   @0x173428 cmp r0, #0
 *   @0x17342c beq 0x173444 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x10c>
 *   @0x173430 ldr r4, [r0]
 *   @0x173434 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x173438 cmp r4, #0
 *   @0x17343c mov r0, r4
 *   @0x173440 bne 0x173430 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf8>
 *   @0x173444 ldr r0, [sp, #0x2c]
 *   @0x173448 mov r3, #0
 *   @0x17344c str r3, [sp, #0x28]
 *   @0x173450 cmp r0, r3
 *   @0x173454 str r3, [sp, #0x20]
 *   @0x173458 beq 0x173460 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x128>
 *   @0x17345c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x173460 add sp, sp, #52
 *   @0x173464 vpop {d8, d9, d10}
 *   @0x173468 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17346c mov r3, r0
 *   @0x173470 ldr r10, [r3, #0x4]
 *   @0x173474 cmp r10, #0
 *   @0x173478 beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0>
 *   @0x17347c ldrh r3, [r10]
 *   @0x173480 cmp r3, #0
 *   @0x173484 beq 0x173418 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xe0>
 *   @0x173488 ldr r3, [pc, #0x104]
 *   @0x17348c ldr r3, [r9, r3]
 *   @0x173490 str r3, [sp, #0x1c]
 *   @0x173494 ldr r3, [r3]
 *   @0x173498 cmp r3, #1
 *   @0x17349c beq 0x1734f8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x1c0>
 *   @0x1734a0 ldr r2, [pc, #0xf0]
 *   @0x1734a4 cmp r3, #2
 *   @0x1734a8 vldr s15, [pc, #216]
 *   @0x1734ac ldr r11, [r9, r2]
 *   @0x1734b0 beq 0x173530 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x1f8>
 *   @0x1734b4 vadd.f32 s15, s18, s15
 *   @0x1734b8 ldr r0, [r11]
 *   @0x1734bc mov r3, r10
 *   @0x1734c0 str r5, [sp]
 *   @0x1734c4 vstr s19, [sp, #16]
 *   @0x1734c8 stmib sp, {r6, r7, r8}
 *   @0x1734cc add r4, r4, #1
 *   @0x1734d0 vmov r1, s15
 *   @0x1734d4 vadd.f32 s15, s16, s20
 *   @0x1734d8 vmov r2, s15
 *   @0x1734dc bl 0xf8b58 <_ZN7CFontGM17Draw_String_ColorEffPtjjjjf>
 *   @0x1734e0 ldr r1, [sp, #0x28]
 *   @0x1734e4 ldr r0, [sp, #0x20]
 *   @0x1734e8 vadd.f32 s16, s16, s17
 *   @0x1734ec cmp r1, r4
 *   @0x1734f0 bgt 0x1733e8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xb0>
 *   @0x1734f4 b 0x173428 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0xf0>
 *   @0x1734f8 ldr r3, [pc, #0x98]
 *   @0x1734fc mov r1, r10
 *   @0x173500 ldr r11, [r9, r3]
 *   @0x173504 ldr r0, [r11]
 *   @0x173508 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x17350c ldr r2, [sp, #0x1c]
 *   @0x173510 ldr r3, [r2]
 *   @0x173514 cmp r3, #2
 *   @0x173518 add r0, r0, r0, lsr #31
 *   @0x17351c asr r1, r0, #1
 *   @0x173520 rsb r1, r1, #0
 *   @0x173524 vmov s14, r1
 *   @0x173528 vcvt.f32.s32 s15, s14
 *   @0x17352c bne 0x1734b4 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x17c>
 *   @0x173530 ldr r0, [r11]
 *   @0x173534 mov r1, r10
 *   @0x173538 bl 0xf8b04 <_ZN7CFontGM9TextWidthEPt>
 *   @0x17353c rsb r0, r0, #0
 *   @0x173540 vmov s14, r0
 *   @0x173544 vcvt.f32.s32 s15, s14
 *   @0x173548 b 0x1734b4 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x17c>
 *   @0x17354c mul r3, r1, r4
 *   @0x173550 add r3, r3, r3, lsr #31
 *   @0x173554 asr r3, r3, #1
 *   @0x173558 vmov s14, r3
 *   @0x17355c vcvt.f32.s32 s15, s14
 *   @0x173560 vsub.f32 s16, s16, s15
 *   @0x173564 b 0x1733c8 <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x90>
 *   @0x173568 ldr r3, [pc, #0x28]
 *   @0x17356c ldr r1, [pc, #0x28]
 *   @0x173570 ldr r11, [r9, r3]
 *   @0x173574 add r1, pc, r1
 *   @0x173578 ldr r0, [r11]
 *   @0x17357c bl 0xf93a4 <_ZN7CFontGM10TextHeightEPt>
 *   @0x173580 mov r4, r0
 *   @0x173584 b 0x17339c <_Z18GR_Text_Draw_ColorffPKciijjjjf+0x64>
 *   @0x173588 andeq r0, r0, r0
 *   @0x17358c .word 0x0027e8bc
 *   @0x173590 .word 0xffffe65c
 *   @0x173594 .word 0xffffe658
 *   @0x173598 .word 0xffffe654
 *   @0x17359c mulseq sp, r4, pc
 *
 * ══ §15/50 F_TilemapGetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)  0x1be838  size 616  154 条（0x1be838..0x1beaa0）
 * @func 0x1be838 0x1beaa0  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Error_Show(char const*, bool)×3 / YYGetFloat(RValue const*, int)×2 / F_TilemapGetAtPixel(RValue&, CInstance*, CInstance*, int, RValue*)+0x40×2 / 0xb6910×2 / CLayerManager::GetTargetRoomObj() / YYGetInt32(RValue const*, int) / CLayerManager::GetElementFromID(CRoom*, int, CLayer**) / Background_Data(int)
 * 字段偏移 top8: 0x4×3 / 0x38×3 / 0x28×3 / 0xc×2 / 0x1c4×2 / 0x34×2 / 0x1c×2 / 0x2c×2
 * VFP 指令 45 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1be838 cmp r3, #3
 *   @0x1be83c mov r3, #0
 *   @0x1be840 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1be844 vpush {d8, d9}
 *   @0x1be848 mov r4, r3
 *   @0x1be84c sub sp, sp, #12
 *   @0x1be850 movt r3, #0xbff0
 *   @0x1be854 mov r5, r0
 *   @0x1be858 str r4, [r0, #0xc]
 *   @0x1be85c str r3, [r0, #0x4]
 *   @0x1be860 str r4, [r0]
 *   @0x1be864 beq 0x1be884 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x4c>
 *   @0x1be868 ldr r0, [pc, #0x21c]
 *   @0x1be86c mov r1, r4
 *   @0x1be870 add r0, pc, r0
 *   @0x1be874 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1be878 add sp, sp, #12
 *   @0x1be87c vpop {d8, d9}
 *   @0x1be880 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1be884 bl 0x1ba730 <_ZN13CLayerManager16GetTargetRoomObjEv>
 *   @0x1be888 add r6, sp, #8
 *   @0x1be88c mov r1, r4
 *   @0x1be890 str r4, [r6, #-0x4]!
 *   @0x1be894 mov r7, r0
 *   @0x1be898 ldr r0, [sp, #0x38]
 *   @0x1be89c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1be8a0 mov r2, r6
 *   @0x1be8a4 mov r1, r0
 *   @0x1be8a8 mov r0, r7
 *   @0x1be8ac bl 0x1bc2a0 <_ZN13CLayerManager16GetElementFromIDEP5CRoomiPP6CLayer>
 *   @0x1be8b0 subs r4, r0, #0
 *   @0x1be8b4 beq 0x1be8c4 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1be8b8 ldr r3, [r4]
 *   @0x1be8bc cmp r3, #5
 *   @0x1be8c0 beq 0x1be8f0 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0xb8>
 *   @0x1be8c4 ldr r3, [pc, #0x1c4]
 *   @0x1be8c8 ldr r1, [pc, #0x1c4]
 *   @0x1be8cc ldr r3, [pc, r3]
 *   @0x1be8d0 add r1, pc, r1
 *   @0x1be8d4 ldr r0, [r3]
 *   @0x1be8d8 ldr r3, [r0]
 *   @0x1be8dc ldr r3, [r3, #0xc]
 *   @0x1be8e0 blx r3
 *   @0x1be8e4 add sp, sp, #12
 *   @0x1be8e8 vpop {d8, d9}
 *   @0x1be8ec pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1be8f0 ldr r3, [sp, #0x4]
 *   @0x1be8f4 cmp r3, #0
 *   @0x1be8f8 beq 0x1be8c4 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0x1be8fc ldr r1, [r4, #0x34]
 *   @0x1be900 cmp r1, #0
 *   @0x1be904 beq 0x1bea7c <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x244>
 *   @0x1be908 ldr r0, [r4, #0x1c]
 *   @0x1be90c bl 0xc3794 <_Z15Background_Datai>
 *   @0x1be910 subs r3, r0, #0
 *   @0x1be914 beq 0x1bea68 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x230>
 *   @0x1be918 mov r1, #1
 *   @0x1be91c ldr r0, [sp, #0x38]
 *   @0x1be920 ldr r2, [sp, #0x4]
 *   @0x1be924 vldr s16, [r4, #32]
 *   @0x1be928 vldr s15, [r2, #8]
 *   @0x1be92c vldr s18, [r2, #12]
 *   @0x1be930 vadd.f32 s16, s16, s15
 *   @0x1be934 ldr r6, [r3, #0x1c]
 *   @0x1be938 ldr r8, [r3, #0x20]
 *   @0x1be93c vldr s19, [r4, #36]
 *   @0x1be940 ldr r7, [r4, #0x28]
 *   @0x1be944 ldr r9, [r4, #0x2c]
 *   @0x1be948 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1be94c mov r1, #2
 *   @0x1be950 vmov s17, r0
 *   @0x1be954 ldr r0, [sp, #0x38]
 *   @0x1be958 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1be95c vsub.f32 s15, s17, s16
 *   @0x1be960 vcmpe.f32 s15, #0
 *   @0x1be964 vmrs APSR_nzcv, fpscr
 *   @0x1be968 vmov s13, r0
 *   @0x1be96c bmi 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be970 mul r7, r7, r6
 *   @0x1be974 vmov s12, r7
 *   @0x1be978 vcvt.f32.s32 s14, s12
 *   @0x1be97c vcmpe.f32 s14, s15
 *   @0x1be980 vmrs APSR_nzcv, fpscr
 *   @0x1be984 bls 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be988 vadd.f32 s18, s19, s18
 *   @0x1be98c vsub.f32 s18, s13, s18
 *   @0x1be990 vcmpe.f32 s18, #0
 *   @0x1be994 vmrs APSR_nzcv, fpscr
 *   @0x1be998 bmi 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be99c mul r9, r9, r8
 *   @0x1be9a0 vmov s13, r9
 *   @0x1be9a4 vcvt.f32.s32 s14, s13
 *   @0x1be9a8 vcmpe.f32 s14, s18
 *   @0x1be9ac vmrs APSR_nzcv, fpscr
 *   @0x1be9b0 bls 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1be9b4 vmov.f32 s16, #1.000000e+00
 *   @0x1be9b8 vmov s12, r6
 *   @0x1be9bc vcvt.f32.s32 s14, s12
 *   @0x1be9c0 vdiv.f32 s14, s16, s14
 *   @0x1be9c4 vmul.f32 s14, s15, s14
 *   @0x1be9c8 vmov r0, s14
 *   @0x1be9cc bl 0xb6910 <floorf@plt>
 *   @0x1be9d0 vmov s13, r8
 *   @0x1be9d4 vcvt.f32.s32 s15, s13
 *   @0x1be9d8 vdiv.f32 s16, s16, s15
 *   @0x1be9dc vmov s14, r0
 *   @0x1be9e0 vmul.f32 s16, s18, s16
 *   @0x1be9e4 vcvt.s32.f32 s14, s14
 *   @0x1be9e8 vmov r0, s16
 *   @0x1be9ec vmov r6, s14
 *   @0x1be9f0 bl 0xb6910 <floorf@plt>
 *   @0x1be9f4 ldr r3, [r4, #0x28]
 *   @0x1be9f8 cmp r6, r3
 *   @0x1be9fc lsrge r2, r3, #31
 *   @0x1bea00 lsrlt r2, r6, #31
 *   @0x1bea04 cmp r6, r3
 *   @0x1bea08 movge r6, r3
 *   @0x1bea0c vmov s15, r0
 *   @0x1bea10 cmp r2, #0
 *   @0x1bea14 ldr r2, [r4, #0x2c]
 *   @0x1bea18 vcvt.s32.f32 s15, s15
 *   @0x1bea1c movne r6, #0
 *   @0x1bea20 vmov r0, s15
 *   @0x1bea24 cmp r0, r2
 *   @0x1bea28 lsrge r1, r2, #31
 *   @0x1bea2c lsrlt r1, r0, #31
 *   @0x1bea30 cmp r1, #0
 *   @0x1bea34 movne r3, #0
 *   @0x1bea38 bne 0x1bea48 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0x1bea3c cmp r2, r0
 *   @0x1bea40 movge r2, r0
 *   @0x1bea44 mul r3, r2, r3
 *   @0x1bea48 ldr r2, [r4, #0x34]
 *   @0x1bea4c add r3, r6, r3
 *   @0x1bea50 ldr r2, [r2, r3, lsl #2]
 *   @0x1bea54 vmov s13, r2
 *   @0x1bea58 vcvt.f64.u32 d6, s13
 *   @0x1bea5c vmov r2, r3, d6
 *   @0x1bea60 stm r5, {r2, r3}
 *   @0x1bea64 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bea68 ldr r0, [pc, #0x28]
 *   @0x1bea6c mov r1, r3
 *   @0x1bea70 add r0, pc, r0
 *   @0x1bea74 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bea78 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bea7c ldr r0, [pc, #0x18]
 *   @0x1bea80 add r0, pc, r0
 *   @0x1bea84 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x1bea88 b 0x1be878 <_Z19F_TilemapGetAtPixelR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x1bea8c andseq r0, r9, r4, ror #7
 *   @0x1bea90 eoreq lr, r2, r8, asr #28
 *   @0x1bea94 andseq r0, r9, r12, lsr #8
 *   @0x1bea98 andseq r0, r9, r12, asr #4
 *   @0x1bea9c andseq r0, r9, r8, lsl #4
 *
 * ══ §16/50 Sprite_Delete(int)  0x1ef1ec  size 616  154 条（0x1ef1ec..0x1ef454）
 * @func 0x1ef1ec 0x1ef454  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1ef208→0x7530d8, 0x1ef21c→0x7530d0, 0x1ef268→0x7530dc, 0x1ef28c→0x7530e0
 * 调用序列: Sprite_Delete(int)+0x174 / CSprite::Clear() / unsigned int CHashMapCalculateHash<char const*>(char const*) / Sprite_Delete(int)+0x140 / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×12 / 0x4×10 / 0x2×6 / 0xc×3 / 0x240×1 / 0x234×1 / 0x224×1 / 0x1dc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1ef1ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1ef1f0 cmp r0, #0
 *   @0x1ef1f4 sub sp, sp, #20
 *   @0x1ef1f8 ldr r5, [pc, #0x240]
 *   @0x1ef1fc str r0, [sp]
 *   @0x1ef200 add r5, pc, r5
 *   @0x1ef204 blt 0x1ef360 <_Z13Sprite_Deletei+0x174>
 *   @0x1ef208 ldr r3, [pc, #0x234]
 *   @0x1ef20c ldr r3, [r5, r3]
 *   @0x1ef210 ldr r3, [r3]
 *   @0x1ef214 cmp r0, r3
 *   @0x1ef218 bge 0x1ef360 <_Z13Sprite_Deletei+0x174>
 *   @0x1ef21c ldr r3, [pc, #0x224]
 *   @0x1ef220 lsl r6, r0, #2
 *   @0x1ef224 ldr r4, [r5, r3]
 *   @0x1ef228 ldr r3, [r4, #0x4]
 *   @0x1ef22c ldr r0, [r3, r0, lsl #2]
 *   @0x1ef230 cmp r0, #0
 *   @0x1ef234 beq 0x1ef364 <_Z13Sprite_Deletei+0x178>
 *   @0x1ef238 bl 0x1e6b4c <_ZN7CSprite5ClearEv>
 *   @0x1ef23c ldr r3, [r4, #0x4]
 *   @0x1ef240 ldr r1, [sp]
 *   @0x1ef244 add r2, r3, r6
 *   @0x1ef248 ldr r0, [r3, r1, lsl #2]
 *   @0x1ef24c cmp r0, #0
 *   @0x1ef250 beq 0x1ef268 <_Z13Sprite_Deletei+0x7c>
 *   @0x1ef254 ldr r3, [r0]
 *   @0x1ef258 ldr r3, [r3, #0x4]
 *   @0x1ef25c blx r3
 *   @0x1ef260 ldr r2, [r4, #0x4]
 *   @0x1ef264 add r2, r2, r6
 *   @0x1ef268 ldr r3, [pc, #0x1dc]
 *   @0x1ef26c mov r4, #0
 *   @0x1ef270 str r4, [r2]
 *   @0x1ef274 ldr r2, [sp]
 *   @0x1ef278 ldr r3, [r5, r3]
 *   @0x1ef27c str r3, [sp, #0xc]
 *   @0x1ef280 ldr r3, [r3]
 *   @0x1ef284 ldr r0, [r3, r2, lsl #2]
 *   @0x1ef288 bl 0x1eeb88 <_Z21CHashMapCalculateHashIPKcEjT_>
 *   @0x1ef28c ldr r3, [pc, #0x1bc]
 *   @0x1ef290 ldr r3, [r5, r3]
 *   @0x1ef294 ldr r2, [r3, #0x8]
 *   @0x1ef298 ldr r12, [r3, #0x10]
 *   @0x1ef29c str r3, [sp, #0x8]
 *   @0x1ef2a0 bic r0, r0, #-2147483648
 *   @0x1ef2a4 and r3, r0, r2
 *   @0x1ef2a8 lsl r1, r3, #1
 *   @0x1ef2ac add lr, r1, r3
 *   @0x1ef2b0 add lr, r12, lr, lsl #2
 *   @0x1ef2b4 ldr lr, [lr, #0x8]
 *   @0x1ef2b8 cmp lr, r4
 *   @0x1ef2bc beq 0x1ef32c <_Z13Sprite_Deletei+0x140>
 *   @0x1ef2c0 cmp r0, lr
 *   @0x1ef2c4 beq 0x1ef374 <_Z13Sprite_Deletei+0x188>
 *   @0x1ef2c8 ldr r1, [sp, #0x8]
 *   @0x1ef2cc and lr, r2, lr
 *   @0x1ef2d0 ldr r7, [r1]
 *   @0x1ef2d4 add r1, r3, r7
 *   @0x1ef2d8 rsb lr, lr, r1
 *   @0x1ef2dc tst lr, r2
 *   @0x1ef2e0 bpl 0x1ef2f8 <_Z13Sprite_Deletei+0x10c>
 *   @0x1ef2e4 b 0x1ef32c <_Z13Sprite_Deletei+0x140>
 *   @0x1ef2e8 cmp r0, lr
 *   @0x1ef2ec beq 0x1ef36c <_Z13Sprite_Deletei+0x180>
 *   @0x1ef2f0 cmp r5, r4
 *   @0x1ef2f4 blt 0x1ef32c <_Z13Sprite_Deletei+0x140>
 *   @0x1ef2f8 add r3, r3, #1
 *   @0x1ef2fc add r4, r4, #1
 *   @0x1ef300 and r3, r3, r2
 *   @0x1ef304 add r6, r3, r7
 *   @0x1ef308 lsl r1, r3, #1
 *   @0x1ef30c add lr, r1, r3
 *   @0x1ef310 add lr, r12, lr, lsl #2
 *   @0x1ef314 ldr lr, [lr, #0x8]
 *   @0x1ef318 and r5, r2, lr
 *   @0x1ef31c cmp lr, #0
 *   @0x1ef320 rsb r5, r5, r6
 *   @0x1ef324 and r5, r5, r2
 *   @0x1ef328 bne 0x1ef2e8 <_Z13Sprite_Deletei+0xfc>
 *   @0x1ef32c ldr r1, [sp, #0xc]
 *   @0x1ef330 ldr r2, [sp]
 *   @0x1ef334 ldr r3, [r1]
 *   @0x1ef338 ldr r0, [r3, r2, lsl #2]
 *   @0x1ef33c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1ef340 ldr r7, [sp, #0xc]
 *   @0x1ef344 ldr r1, [sp]
 *   @0x1ef348 mov r2, #0
 *   @0x1ef34c mov r0, #1
 *   @0x1ef350 ldr r3, [r7]
 *   @0x1ef354 str r2, [r3, r1, lsl #2]
 *   @0x1ef358 add sp, sp, #20
 *   @0x1ef35c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ef360 mov r0, #0
 *   @0x1ef364 add sp, sp, #20
 *   @0x1ef368 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1ef36c cmn r3, #1
 *   @0x1ef370 beq 0x1ef32c <_Z13Sprite_Deletei+0x140>
 *   @0x1ef374 add r5, r3, #1
 *   @0x1ef378 and r5, r5, r2
 *   @0x1ef37c add r4, r5, r5, lsl #1
 *   @0x1ef380 add r4, r12, r4, lsl #2
 *   @0x1ef384 ldr lr, [r4, #0x8]
 *   @0x1ef388 cmp lr, #0
 *   @0x1ef38c beq 0x1ef438 <_Z13Sprite_Deletei+0x24c>
 *   @0x1ef390 ldr r7, [sp, #0x8]
 *   @0x1ef394 and r0, r2, lr
 *   @0x1ef398 ldr r7, [r7]
 *   @0x1ef39c add r6, r5, r7
 *   @0x1ef3a0 rsb r0, r0, r6
 *   @0x1ef3a4 str r7, [sp, #0x4]
 *   @0x1ef3a8 tst r0, r2
 *   @0x1ef3ac bne 0x1ef3c0 <_Z13Sprite_Deletei+0x1d4>
 *   @0x1ef3b0 b 0x1ef438 <_Z13Sprite_Deletei+0x24c>
 *   @0x1ef3b4 tst r8, r2
 *   @0x1ef3b8 beq 0x1ef410 <_Z13Sprite_Deletei+0x224>
 *   @0x1ef3bc mov r5, r0
 *   @0x1ef3c0 add r0, r5, #1
 *   @0x1ef3c4 add r7, r1, r3
 *   @0x1ef3c8 and r0, r0, r2
 *   @0x1ef3cc ldr r10, [r4]
 *   @0x1ef3d0 add r6, r12, r7, lsl #2
 *   @0x1ef3d4 ldr r1, [sp, #0x4]
 *   @0x1ef3d8 add r11, r0, r0, lsl #1
 *   @0x1ef3dc mov r3, r5
 *   @0x1ef3e0 str lr, [r6, #0x8]
 *   @0x1ef3e4 add r8, r0, r1
 *   @0x1ef3e8 ldr r9, [r4, #0x4]
 *   @0x1ef3ec add r4, r12, r11, lsl #2
 *   @0x1ef3f0 str r10, [r12, r7, lsl #2]
 *   @0x1ef3f4 lsl r1, r5, #1
 *   @0x1ef3f8 ldr lr, [r4, #0x8]
 *   @0x1ef3fc str r9, [r6, #0x4]
 *   @0x1ef400 cmp lr, #0
 *   @0x1ef404 and r6, r2, lr
 *   @0x1ef408 rsb r8, r6, r8
 *   @0x1ef40c bne 0x1ef3b4 <_Z13Sprite_Deletei+0x1c8>
 *   @0x1ef410 ldr r3, [sp, #0x8]
 *   @0x1ef414 add r5, r5, r5, lsl #1
 *   @0x1ef418 ldr r7, [sp, #0x8]
 *   @0x1ef41c add r12, r12, r5, lsl #2
 *   @0x1ef420 ldr r2, [r3, #0x4]
 *   @0x1ef424 mov r3, #0
 *   @0x1ef428 str r3, [r12, #0x8]
 *   @0x1ef42c sub r2, r2, #1
 *   @0x1ef430 str r2, [r7, #0x4]
 *   @0x1ef434 b 0x1ef32c <_Z13Sprite_Deletei+0x140>
 *   @0x1ef438 mov r5, r3
 *   @0x1ef43c b 0x1ef410 <_Z13Sprite_Deletei+0x224>
 *   @0x1ef440 eoreq r2, r0, r0, asr r10
 *   @0x1ef444 .word 0xfffff1c0
 *   @0x1ef448 .word 0xfffff1b8
 *   @0x1ef44c .word 0xfffff1bc
 *   @0x1ef450 .word 0xfffff1c4
 *
 * ══ §17/50 RVariable::RVariable(RValue const*)  0x1f5b60  size 616  154 条（0x1f5b60..0x1f5dc8）
 * @func 0x1f5b60 0x1f5dc8  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / HASH_RValue(RValue const*) / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / FREE_RValue__Pre(RValue*)
 * 字段偏移 top8: 0x8×13 / 0x4×9 / 0x14×3 / 0xc×3 / 0x10×2 / 0x28×1 / 0x18×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f5b60 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f5b64 mov r4, r0
 *   @0x1f5b68 mov r3, #0
 *   @0x1f5b6c mov r0, r1
 *   @0x1f5b70 str r3, [r4]
 *   @0x1f5b74 mov r5, r1
 *   @0x1f5b78 str r3, [r4, #0x4]
 *   @0x1f5b7c add r7, r4, #8
 *   @0x1f5b80 bl 0xcee94 <_Z11HASH_RValuePK6RValue>
 *   @0x1f5b84 ldr r2, [r4, #0x14]
 *   @0x1f5b88 bic r3, r2, #-16777216
 *   @0x1f5b8c cmp r3, #1
 *   @0x1f5b90 str r0, [r4, #0x28]
 *   @0x1f5b94 beq 0x1f5c58 <_ZN9RVariableC2EPK6RValue+0xf8>
 *   @0x1f5b98 cmp r3, #2
 *   @0x1f5b9c bne 0x1f5bc4 <_ZN9RVariableC2EPK6RValue+0x64>
 *   @0x1f5ba0 sub r2, r2, #1
 *   @0x1f5ba4 bic r2, r2, #-16777216
 *   @0x1f5ba8 bic r2, r2, #3
 *   @0x1f5bac cmp r2, #0
 *   @0x1f5bb0 beq 0x1f5d2c <_ZN9RVariableC2EPK6RValue+0x1cc>
 *   @0x1f5bb4 mov r2, #0
 *   @0x1f5bb8 mov r3, #5
 *   @0x1f5bbc str r2, [r4, #0x10]
 *   @0x1f5bc0 str r3, [r4, #0x14]
 *   @0x1f5bc4 ldr r3, [r5, #0xc]
 *   @0x1f5bc8 mov r1, #0
 *   @0x1f5bcc ldr r2, [r5, #0x8]
 *   @0x1f5bd0 str r1, [r4, #0x8]
 *   @0x1f5bd4 str r3, [r4, #0x14]
 *   @0x1f5bd8 ldr r3, [r5, #0xc]
 *   @0x1f5bdc str r2, [r4, #0x10]
 *   @0x1f5be0 bic r3, r3, #-16777216
 *   @0x1f5be4 cmp r3, #14
 *   @0x1f5be8 addls pc, pc, r3, lsl #2
 *   @0x1f5bec b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5bf0 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8>
 *   @0x1f5bf4 b 0x1f5cb0 <_ZN9RVariableC2EPK6RValue+0x150>
 *   @0x1f5bf8 b 0x1f5cc8 <_ZN9RVariableC2EPK6RValue+0x168>
 *   @0x1f5bfc b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc>
 *   @0x1f5c00 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c04 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c08 b 0x1f5c8c <_ZN9RVariableC2EPK6RValue+0x12c>
 *   @0x1f5c0c b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc>
 *   @0x1f5c10 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c14 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c18 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8>
 *   @0x1f5c1c b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c20 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c24 b 0x1f5c48 <_ZN9RVariableC2EPK6RValue+0xe8>
 *   @0x1f5c28 b 0x1f5c2c <_ZN9RVariableC2EPK6RValue+0xcc>
 *   @0x1f5c2c ldr r3, [r5]
 *   @0x1f5c30 str r3, [r4, #0x8]
 *   @0x1f5c34 mov r3, #0
 *   @0x1f5c38 mov r0, r4
 *   @0x1f5c3c str r3, [r4, #0x18]
 *   @0x1f5c40 str r3, [r4, #0x24]
 *   @0x1f5c44 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f5c48 ldm r5, {r2, r3}
 *   @0x1f5c4c str r2, [r4, #0x8]
 *   @0x1f5c50 str r3, [r4, #0xc]
 *   @0x1f5c54 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5c58 ldr r6, [r4, #0x8]
 *   @0x1f5c5c cmp r6, #0
 *   @0x1f5c60 beq 0x1f5c80 <_ZN9RVariableC2EPK6RValue+0x120>
 *   @0x1f5c64 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5c68 ldr r8, [r6, #0x4]
 *   @0x1f5c6c sub r8, r8, #1
 *   @0x1f5c70 str r8, [r6, #0x4]
 *   @0x1f5c74 cmp r8, #0
 *   @0x1f5c78 beq 0x1f5cf4 <_ZN9RVariableC2EPK6RValue+0x194>
 *   @0x1f5c7c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5c80 mov r3, #0
 *   @0x1f5c84 str r3, [r4, #0x8]
 *   @0x1f5c88 b 0x1f5bc4 <_ZN9RVariableC2EPK6RValue+0x64>
 *   @0x1f5c8c ldr r3, [r5]
 *   @0x1f5c90 str r3, [r4, #0x8]
 *   @0x1f5c94 ldr r3, [r5]
 *   @0x1f5c98 cmp r3, #0
 *   @0x1f5c9c beq 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5ca0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f5ca4 ldr r1, [r5]
 *   @0x1f5ca8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f5cac b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5cb0 ldr r3, [r5]
 *   @0x1f5cb4 cmp r3, #0
 *   @0x1f5cb8 ldrne r2, [r3, #0x4]
 *   @0x1f5cbc addne r2, r2, #1
 *   @0x1f5cc0 strne r2, [r3, #0x4]
 *   @0x1f5cc4 b 0x1f5c30 <_ZN9RVariableC2EPK6RValue+0xd0>
 *   @0x1f5cc8 ldr r3, [r5]
 *   @0x1f5ccc cmp r3, #0
 *   @0x1f5cd0 str r3, [r4, #0x8]
 *   @0x1f5cd4 beq 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5cd8 ldr r1, [r3, #0x8]
 *   @0x1f5cdc ldr r2, [r3]
 *   @0x1f5ce0 cmp r1, #0
 *   @0x1f5ce4 streq r7, [r3, #0x8]
 *   @0x1f5ce8 add r2, r2, #1
 *   @0x1f5cec str r2, [r3]
 *   @0x1f5cf0 b 0x1f5c34 <_ZN9RVariableC2EPK6RValue+0xd4>
 *   @0x1f5cf4 ldr r0, [r6]
 *   @0x1f5cf8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f5cfc str r8, [r6]
 *   @0x1f5d00 str r8, [r6, #0x8]
 *   @0x1f5d04 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5d08 ldr r8, [r6, #0x4]
 *   @0x1f5d0c sub r8, r8, #1
 *   @0x1f5d10 str r8, [r6, #0x4]
 *   @0x1f5d14 cmp r8, #0
 *   @0x1f5d18 beq 0x1f5d38 <_ZN9RVariableC2EPK6RValue+0x1d8>
 *   @0x1f5d1c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5d20 mov r0, r6
 *   @0x1f5d24 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f5d28 b 0x1f5c7c <_ZN9RVariableC2EPK6RValue+0x11c>
 *   @0x1f5d2c mov r0, r7
 *   @0x1f5d30 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f5d34 b 0x1f5bb4 <_ZN9RVariableC2EPK6RValue+0x54>
 *   @0x1f5d38 ldr r0, [r6]
 *   @0x1f5d3c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f5d40 str r8, [r6]
 *   @0x1f5d44 str r8, [r6, #0x8]
 *   @0x1f5d48 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5d4c ldr r8, [r6, #0x4]
 *   @0x1f5d50 sub r8, r8, #1
 *   @0x1f5d54 str r8, [r6, #0x4]
 *   @0x1f5d58 cmp r8, #0
 *   @0x1f5d5c beq 0x1f5d70 <_ZN9RVariableC2EPK6RValue+0x210>
 *   @0x1f5d60 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5d64 mov r0, r6
 *   @0x1f5d68 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f5d6c b 0x1f5d1c <_ZN9RVariableC2EPK6RValue+0x1bc>
 *   @0x1f5d70 ldr r0, [r6]
 *   @0x1f5d74 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f5d78 str r8, [r6]
 *   @0x1f5d7c str r8, [r6, #0x8]
 *   @0x1f5d80 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f5d84 ldr r8, [r6, #0x4]
 *   @0x1f5d88 sub r8, r8, #1
 *   @0x1f5d8c str r8, [r6, #0x4]
 *   @0x1f5d90 cmp r8, #0
 *   @0x1f5d94 bne 0x1f5db8 <_ZN9RVariableC2EPK6RValue+0x258>
 *   @0x1f5d98 ldr r0, [r6]
 *   @0x1f5d9c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f5da0 mov r0, r6
 *   @0x1f5da4 str r8, [r6]
 *   @0x1f5da8 str r8, [r6, #0x8]
 *   @0x1f5dac bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f5db0 mov r0, r6
 *   @0x1f5db4 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f5db8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f5dbc mov r0, r6
 *   @0x1f5dc0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f5dc4 b 0x1f5d60 <_ZN9RVariableC2EPK6RValue+0x200>
 *
 * ══ §18/50 JS_Function_prototype_bind(RValue&, CInstance*, CInstance*, int, RValue*)  0x254608  size 616  154 条（0x254608..0x254870）
 * @func 0x254608 0x254870  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: JS_SetupProperty(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), void (*)(RValue&, CInstance*, CInstance*, int, RValue*))×3 / YYObjectBase::Add(char const*, YYObjectBase*, int)×2 / Code_Variable_Find_Slot_From_Name(YYObjectBase*, char const*)×2 / YYObjectBase::InternalGetYYVar(int)×2 / JS_IsCallable_Object(YYObjectBase*) / YYSetScriptRef(RValue*) / YYObjectBase::AssignVars(YYObjectBase*) / JS_Function_prototype_bind(RValue&, CInstance*, CInstance*, int, RValue*)+0x208
 * 字段偏移 top8: 0xc×10 / 0x4×2 / 0x58×1 / 0x210×1 / 0x10×1 / 0x1ec×1 / 0x1d8×1 / 0x1a0×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x254608 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25460c sub sp, sp, #52
 *   @0x254610 mov r9, r0
 *   @0x254614 mov r0, r1
 *   @0x254618 mov r7, r1
 *   @0x25461c mov r11, r2
 *   @0x254620 mov r10, r3
 *   @0x254624 ldr r8, [sp, #0x58]
 *   @0x254628 bl 0x240758 <_Z20JS_IsCallable_ObjectP12YYObjectBase>
 *   @0x25462c cmp r0, #0
 *   @0x254630 beq 0x2547c4 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x254634 add r0, sp, #16
 *   @0x254638 ldr r4, [pc, #0x210]
 *   @0x25463c bl 0xdc3b0 <_Z14YYSetScriptRefP6RValue>
 *   @0x254640 ldr r6, [sp, #0x10]
 *   @0x254644 mov r1, r7
 *   @0x254648 mov r0, r6
 *   @0x25464c bl 0x1982d4 <_ZN12YYObjectBase10AssignVarsEPS_>
 *   @0x254650 ldr r4, [pc, r4]
 *   @0x254654 mov r1, r4
 *   @0x254658 mov r0, r4
 *   @0x25465c bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_>
 *   @0x254660 ldr r1, [pc, #0x1ec]
 *   @0x254664 mov r3, #0
 *   @0x254668 add r1, pc, r1
 *   @0x25466c mov r2, r0
 *   @0x254670 mov r0, r6
 *   @0x254674 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x254678 ldr r1, [pc, #0x1d8]
 *   @0x25467c mov r0, r6
 *   @0x254680 add r1, pc, r1
 *   @0x254684 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x254688 ldr r3, [r6, #0x4]
 *   @0x25468c cmp r3, #0
 *   @0x254690 beq 0x25483c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x254694 add r2, r3, r0, lsl #4
 *   @0x254698 mov r1, r4
 *   @0x25469c mov r0, r4
 *   @0x2546a0 str r2, [sp, #0xc]
 *   @0x2546a4 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_>
 *   @0x2546a8 ldr r2, [sp, #0xc]
 *   @0x2546ac mov r3, #0
 *   @0x2546b0 mov r1, #6
 *   @0x2546b4 ldr r5, [pc, #0x1a0]
 *   @0x2546b8 str r3, [r2, #0x8]
 *   @0x2546bc add r5, pc, r5
 *   @0x2546c0 str r1, [r2, #0xc]
 *   @0x2546c4 mov r1, r4
 *   @0x2546c8 str r0, [r2]
 *   @0x2546cc mov r0, r4
 *   @0x2546d0 str r3, [sp, #0xc]
 *   @0x2546d4 bl 0x241504 <_Z16JS_SetupPropertyPFvR6RValueP9CInstanceS2_iPS_ES5_>
 *   @0x2546d8 ldr r1, [pc, #0x180]
 *   @0x2546dc ldr r3, [sp, #0xc]
 *   @0x2546e0 add r1, pc, r1
 *   @0x2546e4 mov r2, r0
 *   @0x2546e8 mov r0, r6
 *   @0x2546ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2546f0 mov r1, r5
 *   @0x2546f4 mov r0, r6
 *   @0x2546f8 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc>
 *   @0x2546fc cmp r0, #0
 *   @0x254700 blt 0x254810 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x254704 ldr r3, [r6, #0x4]
 *   @0x254708 cmp r3, #0
 *   @0x25470c beq 0x254828 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x220>
 *   @0x254710 add r5, r3, r0, lsl #4
 *   @0x254714 cmp r5, #0
 *   @0x254718 beq 0x254748 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x25471c mov r0, r5
 *   @0x254720 rsb r4, r10, #1
 *   @0x254724 bl 0xd11b0 <_Z12INT32_RValuePK6RValue>
 *   @0x254728 mov r3, #0
 *   @0x25472c str r3, [r5, #0xc]
 *   @0x254730 add r0, r0, r4
 *   @0x254734 bic r4, r0, r0, asr #31
 *   @0x254738 vmov s15, r4
 *   @0x25473c vcvt.f64.s32 d7, s15
 *   @0x254740 vmov r2, r3, d7
 *   @0x254744 stm r5, {r2, r3}
 *   @0x254748 ldr r3, [r8, #0xc]
 *   @0x25474c ldr r4, [pc, #0x110]
 *   @0x254750 bic r3, r3, #-16777216
 *   @0x254754 cmp r3, #6
 *   @0x254758 ldr r4, [pc, r4]
 *   @0x25475c ldr r3, [r4]
 *   @0x254760 bne 0x2547d8 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x1d0>
 *   @0x254764 ldr r3, [r8]
 *   @0x254768 add r5, sp, #32
 *   @0x25476c str r3, [r6, #0x7c]
 *   @0x254770 mov r1, r7
 *   @0x254774 mov r2, r11
 *   @0x254778 sub r3, r10, #1
 *   @0x25477c mov r4, #6
 *   @0x254780 mov r0, r5
 *   @0x254784 str r4, [r6, #0x88]
 *   @0x254788 add r8, r8, #16
 *   @0x25478c str r8, [sp]
 *   @0x254790 mov r12, #5
 *   @0x254794 str r12, [sp, #0x2c]
 *   @0x254798 bl 0x253fc0 <_Z13F_JSArrayCallR6RValueP9CInstanceS2_iPS_>
 *   @0x25479c ldr r1, [pc, #0xc4]
 *   @0x2547a0 mov r0, r6
 *   @0x2547a4 mov r2, r5
 *   @0x2547a8 mov r3, #0
 *   @0x2547ac add r1, pc, r1
 *   @0x2547b0 bl 0x199b84 <_ZN12YYObjectBase3AddEPKcR6RValuei>
 *   @0x2547b4 str r4, [r9, #0xc]
 *   @0x2547b8 str r6, [r9]
 *   @0x2547bc add sp, sp, #52
 *   @0x2547c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2547c4 ldr r0, [pc, #0xa0]
 *   @0x2547c8 add r0, pc, r0
 *   @0x2547cc bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x2547d0 add sp, sp, #52
 *   @0x2547d4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2547d8 mov r0, r8
 *   @0x2547dc str r3, [sp, #0xc]
 *   @0x2547e0 bl 0x241dc0 <_Z16F_JS_IsPrimitiveR6RValue>
 *   @0x2547e4 add r5, sp, #32
 *   @0x2547e8 ldr r3, [sp, #0xc]
 *   @0x2547ec cmp r0, #0
 *   @0x2547f0 beq 0x25476c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x2547f4 mov r1, r8
 *   @0x2547f8 mov r0, r5
 *   @0x2547fc bl 0x247388 <_Z13F_JS_ToObjectR6RValuePS_>
 *   @0x254800 cmp r0, #0
 *   @0x254804 ldrne r3, [r4]
 *   @0x254808 ldreq r3, [sp, #0x20]
 *   @0x25480c b 0x25476c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x254810 mov r1, r5
 *   @0x254814 mov r0, r6
 *   @0x254818 bl 0x196b84 <_ZN12YYObjectBase9FindValueEPKc>
 *   @0x25481c subs r5, r0, #0
 *   @0x254820 bne 0x25471c <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x254824 b 0x254748 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x254828 mov r1, r0
 *   @0x25482c mov r0, r6
 *   @0x254830 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x254834 mov r5, r0
 *   @0x254838 b 0x254714 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x10c>
 *   @0x25483c mov r1, r0
 *   @0x254840 mov r0, r6
 *   @0x254844 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x254848 mov r2, r0
 *   @0x25484c b 0x254698 <_Z26JS_Function_prototype_bindR6RValueP9CInstanceS2_iPS_+0x90>
 *   @0x254850 andseq sp, r9, r4, lsl #3
 *   @0x254854 andseq r2, r0, r12, lsl r0
 *   @0x254858 muleq pc, r0, r0
 *   @0x25485c strheq r12, [sp], -r0
 *   @0x254860 andeq sp, pc, r0, lsr r0
 *   @0x254864 andseq r9, r9, r0, asr r5
 *   @0x254868 andeq r0, lr, r0, lsr #1
 *   @0x25486c andseq r1, r0, r4, lsl #29
 *
 * ══ §19/50 jpeg_calc_output_dimensions  0x2b63dc  size 616  154 条（0x2b63dc..0x2b6644）
 * @func 0x2b63dc 0x2b6644  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jdiv_round_up×8 / jpeg_calc_output_dimensions+0xe8×2 / jpeg_calc_output_dimensions+0x15c / jpeg_calc_output_dimensions+0x1d4 / jpeg_calc_output_dimensions+0xc4 / anon_2b60ec+0x214
 * 字段偏移 top8: 0x1c×5 / 0x20×5 / 0x118×5 / 0x5c×4 / 0x60×4 / 0x24×4 / 0x64×4 / 0x14×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b63dc ldr r3, [r0, #0x14]
 *   @0x2b63e0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b63e4 cmp r3, #202
 *   @0x2b63e8 mov r6, r0
 *   @0x2b63ec beq 0x2b640c <jpeg_calc_output_dimensions+0x30>
 *   @0x2b63f0 ldr r2, [r0]
 *   @0x2b63f4 mov r1, #20
 *   @0x2b63f8 str r3, [r2, #0x18]
 *   @0x2b63fc ldr r3, [r0]
 *   @0x2b6400 str r1, [r2, #0x14]
 *   @0x2b6404 ldr r3, [r3]
 *   @0x2b6408 blx r3
 *   @0x2b640c ldr r2, [r6, #0x30]
 *   @0x2b6410 ldr r3, [r6, #0x34]
 *   @0x2b6414 cmp r3, r2, lsl #3
 *   @0x2b6418 bhs 0x2b65b8 <jpeg_calc_output_dimensions+0x1dc>
 *   @0x2b641c cmp r3, r2, lsl #2
 *   @0x2b6420 bhs 0x2b65ec <jpeg_calc_output_dimensions+0x210>
 *   @0x2b6424 cmp r3, r2, lsl #1
 *   @0x2b6428 bhs 0x2b6618 <jpeg_calc_output_dimensions+0x23c>
 *   @0x2b642c ldr r2, [r6, #0x1c]
 *   @0x2b6430 mov r1, #8
 *   @0x2b6434 ldr r3, [r6, #0x20]
 *   @0x2b6438 str r1, [r6, #0x118]
 *   @0x2b643c str r2, [r6, #0x5c]
 *   @0x2b6440 str r3, [r6, #0x60]
 *   @0x2b6444 ldr r9, [r6, #0x24]
 *   @0x2b6448 ldr r7, [r6, #0xc4]
 *   @0x2b644c cmp r9, #0
 *   @0x2b6450 ble 0x2b6538 <jpeg_calc_output_dimensions+0x15c>
 *   @0x2b6454 ldr r0, [r6, #0x118]
 *   @0x2b6458 mov r8, r7
 *   @0x2b645c mov r10, #0
 *   @0x2b6460 cmp r0, #7
 *   @0x2b6464 bgt 0x2b65b0 <jpeg_calc_output_dimensions+0x1d4>
 *   @0x2b6468 ldr r12, [r8, #0x8]
 *   @0x2b646c ldr lr, [r6, #0x110]
 *   @0x2b6470 mul r3, r12, r0
 *   @0x2b6474 mul lr, lr, r0
 *   @0x2b6478 cmp lr, r3, lsl #1
 *   @0x2b647c blt 0x2b65b0 <jpeg_calc_output_dimensions+0x1d4>
 *   @0x2b6480 ldr r4, [r8, #0xc]
 *   @0x2b6484 ldr r5, [r6, #0x114]
 *   @0x2b6488 mul r3, r4, r0
 *   @0x2b648c mul r5, r5, r0
 *   @0x2b6490 cmp r5, r3, lsl #1
 *   @0x2b6494 mov r3, r0
 *   @0x2b6498 bge 0x2b64b4 <jpeg_calc_output_dimensions+0xd8>
 *   @0x2b649c b 0x2b64c4 <jpeg_calc_output_dimensions+0xe8>
 *   @0x2b64a0 cmp lr, r2, lsl #1
 *   @0x2b64a4 mul r1, r4, r3
 *   @0x2b64a8 blt 0x2b64c4 <jpeg_calc_output_dimensions+0xe8>
 *   @0x2b64ac cmp r5, r1, lsl #1
 *   @0x2b64b0 blt 0x2b64c4 <jpeg_calc_output_dimensions+0xe8>
 *   @0x2b64b4 lsl r3, r3, #1
 *   @0x2b64b8 cmp r3, #7
 *   @0x2b64bc mul r2, r12, r3
 *   @0x2b64c0 ble 0x2b64a0 <jpeg_calc_output_dimensions+0xc4>
 *   @0x2b64c4 add r10, r10, #1
 *   @0x2b64c8 str r3, [r8, #0x24]
 *   @0x2b64cc cmp r10, r9
 *   @0x2b64d0 add r8, r8, #84
 *   @0x2b64d4 bne 0x2b6460 <jpeg_calc_output_dimensions+0x84>
 *   @0x2b64d8 mov r4, #0
 *   @0x2b64dc ldr r2, [r7, #0x24]
 *   @0x2b64e0 add r4, r4, #1
 *   @0x2b64e4 ldr r3, [r7, #0x8]
 *   @0x2b64e8 add r7, r7, #84
 *   @0x2b64ec ldr r0, [r6, #0x1c]
 *   @0x2b64f0 ldr r1, [r6, #0x110]
 *   @0x2b64f4 mul r3, r2, r3
 *   @0x2b64f8 lsl r1, r1, #3
 *   @0x2b64fc mul r0, r0, r3
 *   @0x2b6500 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b6504 ldr r3, [r7, #-0x48]
 *   @0x2b6508 ldr r2, [r7, #-0x30]
 *   @0x2b650c mul r3, r2, r3
 *   @0x2b6510 str r0, [r7, #-0x2c]
 *   @0x2b6514 ldr r0, [r6, #0x20]
 *   @0x2b6518 ldr r1, [r6, #0x114]
 *   @0x2b651c mul r0, r0, r3
 *   @0x2b6520 lsl r1, r1, #3
 *   @0x2b6524 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b6528 str r0, [r7, #-0x28]
 *   @0x2b652c ldr r9, [r6, #0x24]
 *   @0x2b6530 cmp r9, r4
 *   @0x2b6534 bgt 0x2b64dc <jpeg_calc_output_dimensions+0x100>
 *   @0x2b6538 ldr r3, [r6, #0x2c]
 *   @0x2b653c sub r3, r3, #1
 *   @0x2b6540 cmp r3, #4
 *   @0x2b6544 addls pc, pc, r3, lsl #2
 *   @0x2b6548 b 0x2b65e4 <jpeg_calc_output_dimensions+0x208>
 *   @0x2b654c b 0x2b65a4 <jpeg_calc_output_dimensions+0x1c8>
 *   @0x2b6550 b 0x2b6598 <jpeg_calc_output_dimensions+0x1bc>
 *   @0x2b6554 b 0x2b6598 <jpeg_calc_output_dimensions+0x1bc>
 *   @0x2b6558 b 0x2b6560 <jpeg_calc_output_dimensions+0x184>
 *   @0x2b655c b 0x2b6560 <jpeg_calc_output_dimensions+0x184>
 *   @0x2b6560 mov r3, #4
 *   @0x2b6564 str r3, [r6, #0x64]
 *   @0x2b6568 ldrb r3, [r6, #0x4a]
 *   @0x2b656c mov r0, r6
 *   @0x2b6570 cmp r3, #0
 *   @0x2b6574 ldreq r3, [r6, #0x64]
 *   @0x2b6578 movne r3, #1
 *   @0x2b657c str r3, [r6, #0x68]
 *   @0x2b6580 bl 0x2b6300 <jpeg_set_marker_processor+0x25c>
 *   @0x2b6584 cmp r0, #0
 *   @0x2b6588 ldrne r3, [r6, #0x114]
 *   @0x2b658c moveq r3, #1
 *   @0x2b6590 str r3, [r6, #0x6c]
 *   @0x2b6594 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b6598 mov r3, #3
 *   @0x2b659c str r3, [r6, #0x64]
 *   @0x2b65a0 b 0x2b6568 <jpeg_calc_output_dimensions+0x18c>
 *   @0x2b65a4 mov r3, #1
 *   @0x2b65a8 str r3, [r6, #0x64]
 *   @0x2b65ac b 0x2b6568 <jpeg_calc_output_dimensions+0x18c>
 *   @0x2b65b0 mov r3, r0
 *   @0x2b65b4 b 0x2b64c4 <jpeg_calc_output_dimensions+0xe8>
 *   @0x2b65b8 mov r1, #8
 *   @0x2b65bc ldr r0, [r6, #0x1c]
 *   @0x2b65c0 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b65c4 mov r1, #8
 *   @0x2b65c8 str r0, [r6, #0x5c]
 *   @0x2b65cc ldr r0, [r6, #0x20]
 *   @0x2b65d0 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b65d4 mov r3, #1
 *   @0x2b65d8 str r3, [r6, #0x118]
 *   @0x2b65dc str r0, [r6, #0x60]
 *   @0x2b65e0 b 0x2b6444 <jpeg_calc_output_dimensions+0x68>
 *   @0x2b65e4 str r9, [r6, #0x64]
 *   @0x2b65e8 b 0x2b6568 <jpeg_calc_output_dimensions+0x18c>
 *   @0x2b65ec mov r1, #4
 *   @0x2b65f0 ldr r0, [r6, #0x1c]
 *   @0x2b65f4 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b65f8 mov r1, #4
 *   @0x2b65fc str r0, [r6, #0x5c]
 *   @0x2b6600 ldr r0, [r6, #0x20]
 *   @0x2b6604 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b6608 mov r3, #2
 *   @0x2b660c str r3, [r6, #0x118]
 *   @0x2b6610 str r0, [r6, #0x60]
 *   @0x2b6614 b 0x2b6444 <jpeg_calc_output_dimensions+0x68>
 *   @0x2b6618 mov r1, #2
 *   @0x2b661c ldr r0, [r6, #0x1c]
 *   @0x2b6620 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b6624 mov r1, #2
 *   @0x2b6628 str r0, [r6, #0x5c]
 *   @0x2b662c ldr r0, [r6, #0x20]
 *   @0x2b6630 bl 0x2bc7ec <jdiv_round_up>
 *   @0x2b6634 mov r3, #4
 *   @0x2b6638 str r3, [r6, #0x118]
 *   @0x2b663c str r0, [r6, #0x60]
 *   @0x2b6640 b 0x2b6444 <jpeg_calc_output_dimensions+0x68>
 *
 * ══ §20/50 CSkeletonSprite::GetSkinList(CDS_List*)  0xc1974  size 612  153 条（0xc1974..0xc1bd8）
 * @func 0xc1974 0xc1be8  size 628  157 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×4 / LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / CSkeletonSprite::GetSkinList(CDS_List*)+0xc8×2 / YYFree(void const*)×2 / operator delete(void*)×2 / YYSetString(RValue*, char const*) / CDS_List::Add(RValue*)
 * 字段偏移 top8: 0x4×15 / 0x8×9 / 0x10×7 / 0xc×6 / 0x20×2 / 0x24×1 / 0x2×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1974 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc1978 subs r8, r1, #0
 *   @0xc197c sub sp, sp, #36
 *   @0xc1980 mov r7, r0
 *   @0xc1984 beq 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8>
 *   @0xc1988 ldr r3, [r0, #0x4]
 *   @0xc198c ldr r2, [r3, #0x20]
 *   @0xc1990 cmp r2, #0
 *   @0xc1994 ble 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8>
 *   @0xc1998 mov r11, #0
 *   @0xc199c add r5, sp, #16
 *   @0xc19a0 mov r4, r11
 *   @0xc19a4 mov r6, #5
 *   @0xc19a8 b 0xc19c0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x4c>
 *   @0xc19ac ldr r3, [r7, #0x4]
 *   @0xc19b0 add r11, r11, #1
 *   @0xc19b4 ldr r1, [r3, #0x20]
 *   @0xc19b8 cmp r1, r11
 *   @0xc19bc ble 0xc1a3c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc8>
 *   @0xc19c0 ldr r3, [r3, #0x24]
 *   @0xc19c4 mov r0, r5
 *   @0xc19c8 ldr r3, [r3, r11, lsl #2]
 *   @0xc19cc ldr r1, [r3]
 *   @0xc19d0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc19d4 mov r1, r5
 *   @0xc19d8 mov r0, r8
 *   @0xc19dc bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0xc19e0 ldr r1, [sp, #0x1c]
 *   @0xc19e4 sub r3, r1, #1
 *   @0xc19e8 bic r3, r3, #-16777216
 *   @0xc19ec bics r9, r3, #3
 *   @0xc19f0 bne 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc19f4 bic r1, r1, #-16777216
 *   @0xc19f8 cmp r1, #2
 *   @0xc19fc beq 0xc1a6c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xf8>
 *   @0xc1a00 cmp r1, #3
 *   @0xc1a04 beq 0xc1a44 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xd0>
 *   @0xc1a08 cmp r1, #1
 *   @0xc1a0c bne 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a10 ldr r9, [sp, #0x10]
 *   @0xc1a14 cmp r9, #0
 *   @0xc1a18 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1a20 ldr r10, [r9, #0x4]
 *   @0xc1a24 sub r10, r10, #1
 *   @0xc1a28 str r10, [r9, #0x4]
 *   @0xc1a2c cmp r10, #0
 *   @0xc1a30 beq 0xc1b20 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1ac>
 *   @0xc1a34 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1a38 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a3c add sp, sp, #36
 *   @0xc1a40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc1a44 ldr r3, [sp, #0x18]
 *   @0xc1a48 tst r3, #8
 *   @0xc1a4c beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a50 ldr r0, [sp, #0x10]
 *   @0xc1a54 cmp r0, #0
 *   @0xc1a58 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a5c ldr r3, [r0]
 *   @0xc1a60 ldr r3, [r3, #0x4]
 *   @0xc1a64 blx r3
 *   @0xc1a68 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a6c ldr r10, [sp, #0x10]
 *   @0xc1a70 cmp r10, #0
 *   @0xc1a74 beq 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1a78 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1a7c ldr r3, [r10]
 *   @0xc1a80 ldr r1, [r10, #0x8]
 *   @0xc1a84 sub r3, r3, #1
 *   @0xc1a88 str r3, [r10]
 *   @0xc1a8c cmp r1, r5
 *   @0xc1a90 streq r9, [r10, #0x8]
 *   @0xc1a94 cmp r3, #0
 *   @0xc1a98 bgt 0xc1a34 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0xc0>
 *   @0xc1a9c ldr r3, [r10, #0x10]
 *   @0xc1aa0 cmp r3, #0
 *   @0xc1aa4 movgt r2, #0
 *   @0xc1aa8 strgt r2, [sp, #0x8]
 *   @0xc1aac ble 0xc1bb0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x23c>
 *   @0xc1ab0 ldr r2, [sp, #0x8]
 *   @0xc1ab4 ldr r3, [r10, #0x4]
 *   @0xc1ab8 add r2, r3, r2, lsl #3
 *   @0xc1abc str r2, [sp, #0xc]
 *   @0xc1ac0 ldr r2, [sp, #0x8]
 *   @0xc1ac4 ldr r12, [r3, r2, lsl #3]
 *   @0xc1ac8 ldr r3, [sp, #0xc]
 *   @0xc1acc ldr r9, [r3, #0x4]
 *   @0xc1ad0 add r12, r9, r12, lsl #4
 *   @0xc1ad4 cmp r9, r12
 *   @0xc1ad8 blo 0xc1af4 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x180>
 *   @0xc1adc b 0xc1bd0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x25c>
 *   @0xc1ae0 str r4, [r9, #0x8]
 *   @0xc1ae4 str r6, [r9, #0xc]
 *   @0xc1ae8 str r4, [r9], #16
 *   @0xc1aec cmp r12, r9
 *   @0xc1af0 bls 0xc1b80 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x20c>
 *   @0xc1af4 ldr r1, [r9, #0xc]
 *   @0xc1af8 sub r1, r1, #1
 *   @0xc1afc bic r1, r1, #-16777216
 *   @0xc1b00 bic r1, r1, #3
 *   @0xc1b04 cmp r1, #0
 *   @0xc1b08 bne 0xc1ae0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x16c>
 *   @0xc1b0c mov r0, r9
 *   @0xc1b10 str r12, [sp, #0x4]
 *   @0xc1b14 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1b18 ldr r12, [sp, #0x4]
 *   @0xc1b1c b 0xc1ae0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x16c>
 *   @0xc1b20 ldr r0, [r9]
 *   @0xc1b24 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xc1b28 str r10, [r9]
 *   @0xc1b2c str r10, [r9, #0x8]
 *   @0xc1b30 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1b34 ldr r10, [r9, #0x4]
 *   @0xc1b38 sub r10, r10, #1
 *   @0xc1b3c str r10, [r9, #0x4]
 *   @0xc1b40 cmp r10, #0
 *   @0xc1b44 beq 0xc1b5c <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1e8>
 *   @0xc1b48 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1b4c mov r0, r9
 *   @0xc1b50 bl 0x27d1d0 <_ZdlPv>
 *   @0xc1b54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1b58 b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1b5c ldr r0, [r9]
 *   @0xc1b60 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xc1b64 mov r0, r9
 *   @0xc1b68 str r10, [r9]
 *   @0xc1b6c str r10, [r9, #0x8]
 *   @0xc1b70 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xc1b74 mov r0, r9
 *   @0xc1b78 bl 0x27d1d0 <_ZdlPv>
 *   @0xc1b7c b 0xc1b48 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x1d4>
 *   @0xc1b80 ldr r2, [sp, #0xc]
 *   @0xc1b84 ldr r0, [r2, #0x4]
 *   @0xc1b88 ldr r3, [sp, #0x8]
 *   @0xc1b8c add r3, r3, #1
 *   @0xc1b90 str r3, [sp, #0x8]
 *   @0xc1b94 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1b98 ldr r2, [sp, #0xc]
 *   @0xc1b9c ldr r3, [r10, #0x10]
 *   @0xc1ba0 str r4, [r2, #0x4]
 *   @0xc1ba4 ldr r2, [sp, #0x8]
 *   @0xc1ba8 cmp r2, r3
 *   @0xc1bac blt 0xc1ab0 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x13c>
 *   @0xc1bb0 ldr r0, [r10, #0x4]
 *   @0xc1bb4 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1bb8 str r4, [r10, #0x4]
 *   @0xc1bbc mov r0, r10
 *   @0xc1bc0 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1bc4 str r4, [sp, #0x10]
 *   @0xc1bc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1bcc b 0xc19ac <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x38>
 *   @0xc1bd0 mov r0, r9
 *   @0xc1bd4 b 0xc1b88 <_ZN15CSkeletonSprite11GetSkinListEP8CDS_List+0x214>
 *
 * ══ §21/50 CSkeletonSprite::GetAnimationList(CDS_List*)  0xc1bd8  size 612  153 条（0xc1bd8..0xc1e3c）
 * @func 0xc1bd8 0xc1e3c  size 612  153 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / YYStrFree(char const*)×3 / CSkeletonSprite::GetAnimationList(CDS_List*)+0x100×2 / YYFree(void const*)×2 / UNLOCK_RVALUE_MUTEX()×2 / operator delete(void*)×2 / YYSetString(RValue*, char const*) / CDS_List::Add(RValue*)
 * 字段偏移 top8: 0x4×15 / 0x8×9 / 0x10×7 / 0xc×6 / 0x34×2 / 0x38×1 / 0x2×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc1bd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc1bdc subs r8, r1, #0
 *   @0xc1be0 sub sp, sp, #36
 *   @0xc1be4 mov r7, r0
 *   @0xc1be8 beq 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100>
 *   @0xc1bec ldr r3, [r0, #0x4]
 *   @0xc1bf0 cmp r3, #0
 *   @0xc1bf4 beq 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100>
 *   @0xc1bf8 ldr r2, [r3, #0x34]
 *   @0xc1bfc cmp r2, #0
 *   @0xc1c00 ble 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100>
 *   @0xc1c04 mov r11, #0
 *   @0xc1c08 add r5, sp, #16
 *   @0xc1c0c mov r4, r11
 *   @0xc1c10 mov r6, #5
 *   @0xc1c14 b 0xc1c2c <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x54>
 *   @0xc1c18 ldr r3, [r7, #0x4]
 *   @0xc1c1c add r11, r11, #1
 *   @0xc1c20 ldr r1, [r3, #0x34]
 *   @0xc1c24 cmp r1, r11
 *   @0xc1c28 ble 0xc1cd8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x100>
 *   @0xc1c2c ldr r3, [r3, #0x38]
 *   @0xc1c30 mov r0, r5
 *   @0xc1c34 ldr r3, [r3, r11, lsl #2]
 *   @0xc1c38 ldr r1, [r3]
 *   @0xc1c3c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0xc1c40 mov r1, r5
 *   @0xc1c44 mov r0, r8
 *   @0xc1c48 bl 0x205d18 <_ZN8CDS_List3AddEP6RValue>
 *   @0xc1c4c ldr r1, [sp, #0x1c]
 *   @0xc1c50 sub r3, r1, #1
 *   @0xc1c54 bic r3, r3, #-16777216
 *   @0xc1c58 bics r9, r3, #3
 *   @0xc1c5c bne 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1c60 bic r1, r1, #-16777216
 *   @0xc1c64 cmp r1, #2
 *   @0xc1c68 beq 0xc1d08 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x130>
 *   @0xc1c6c cmp r1, #3
 *   @0xc1c70 beq 0xc1ce0 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x108>
 *   @0xc1c74 cmp r1, #1
 *   @0xc1c78 bne 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1c7c ldr r9, [sp, #0x10]
 *   @0xc1c80 cmp r9, #0
 *   @0xc1c84 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1c88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1c8c ldr r10, [r9, #0x4]
 *   @0xc1c90 sub r10, r10, #1
 *   @0xc1c94 str r10, [r9, #0x4]
 *   @0xc1c98 cmp r10, #0
 *   @0xc1c9c bne 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160>
 *   @0xc1ca0 ldr r0, [r9]
 *   @0xc1ca4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xc1ca8 str r10, [r9]
 *   @0xc1cac str r10, [r9, #0x8]
 *   @0xc1cb0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1cb4 ldr r10, [r9, #0x4]
 *   @0xc1cb8 sub r10, r10, #1
 *   @0xc1cbc str r10, [r9, #0x4]
 *   @0xc1cc0 cmp r10, #0
 *   @0xc1cc4 beq 0xc1e18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x240>
 *   @0xc1cc8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1ccc mov r0, r9
 *   @0xc1cd0 bl 0x27d1d0 <_ZdlPv>
 *   @0xc1cd4 b 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160>
 *   @0xc1cd8 add sp, sp, #36
 *   @0xc1cdc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc1ce0 ldr r3, [sp, #0x18]
 *   @0xc1ce4 tst r3, #8
 *   @0xc1ce8 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1cec ldr r0, [sp, #0x10]
 *   @0xc1cf0 cmp r0, #0
 *   @0xc1cf4 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1cf8 ldr r3, [r0]
 *   @0xc1cfc ldr r3, [r3, #0x4]
 *   @0xc1d00 blx r3
 *   @0xc1d04 b 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1d08 ldr r10, [sp, #0x10]
 *   @0xc1d0c cmp r10, #0
 *   @0xc1d10 beq 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1d14 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xc1d18 ldr r3, [r10]
 *   @0xc1d1c ldr r1, [r10, #0x8]
 *   @0xc1d20 sub r3, r3, #1
 *   @0xc1d24 str r3, [r10]
 *   @0xc1d28 cmp r1, r5
 *   @0xc1d2c streq r9, [r10, #0x8]
 *   @0xc1d30 cmp r3, #0
 *   @0xc1d34 ble 0xc1d40 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x168>
 *   @0xc1d38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xc1d3c b 0xc1c18 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x40>
 *   @0xc1d40 ldr r3, [r10, #0x10]
 *   @0xc1d44 cmp r3, #0
 *   @0xc1d48 movgt r2, #0
 *   @0xc1d4c strgt r2, [sp, #0x8]
 *   @0xc1d50 ble 0xc1df4 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x21c>
 *   @0xc1d54 ldr r2, [sp, #0x8]
 *   @0xc1d58 ldr r3, [r10, #0x4]
 *   @0xc1d5c add r2, r3, r2, lsl #3
 *   @0xc1d60 str r2, [sp, #0xc]
 *   @0xc1d64 ldr r2, [sp, #0x8]
 *   @0xc1d68 ldr r12, [r3, r2, lsl #3]
 *   @0xc1d6c ldr r3, [sp, #0xc]
 *   @0xc1d70 ldr r9, [r3, #0x4]
 *   @0xc1d74 add r12, r9, r12, lsl #4
 *   @0xc1d78 cmp r9, r12
 *   @0xc1d7c blo 0xc1d98 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1c0>
 *   @0xc1d80 b 0xc1e10 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x238>
 *   @0xc1d84 str r4, [r9, #0x8]
 *   @0xc1d88 str r6, [r9, #0xc]
 *   @0xc1d8c str r4, [r9], #16
 *   @0xc1d90 cmp r12, r9
 *   @0xc1d94 bls 0xc1dc4 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ec>
 *   @0xc1d98 ldr r1, [r9, #0xc]
 *   @0xc1d9c sub r1, r1, #1
 *   @0xc1da0 bic r1, r1, #-16777216
 *   @0xc1da4 bic r1, r1, #3
 *   @0xc1da8 cmp r1, #0
 *   @0xc1dac bne 0xc1d84 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ac>
 *   @0xc1db0 mov r0, r9
 *   @0xc1db4 str r12, [sp, #0x4]
 *   @0xc1db8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0xc1dbc ldr r12, [sp, #0x4]
 *   @0xc1dc0 b 0xc1d84 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1ac>
 *   @0xc1dc4 ldr r2, [sp, #0xc]
 *   @0xc1dc8 ldr r0, [r2, #0x4]
 *   @0xc1dcc ldr r3, [sp, #0x8]
 *   @0xc1dd0 add r3, r3, #1
 *   @0xc1dd4 str r3, [sp, #0x8]
 *   @0xc1dd8 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1ddc ldr r2, [sp, #0xc]
 *   @0xc1de0 ldr r3, [r10, #0x10]
 *   @0xc1de4 str r4, [r2, #0x4]
 *   @0xc1de8 ldr r2, [sp, #0x8]
 *   @0xc1dec cmp r2, r3
 *   @0xc1df0 blt 0xc1d54 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x17c>
 *   @0xc1df4 ldr r0, [r10, #0x4]
 *   @0xc1df8 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1dfc str r4, [r10, #0x4]
 *   @0xc1e00 mov r0, r10
 *   @0xc1e04 bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0xc1e08 str r4, [sp, #0x10]
 *   @0xc1e0c b 0xc1d38 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x160>
 *   @0xc1e10 mov r0, r9
 *   @0xc1e14 b 0xc1dcc <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0x1f4>
 *   @0xc1e18 ldr r0, [r9]
 *   @0xc1e1c bl 0xcef90 <_Z6YYFreePKv>
 *   @0xc1e20 mov r0, r9
 *   @0xc1e24 str r10, [r9]
 *   @0xc1e28 str r10, [r9, #0x8]
 *   @0xc1e2c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xc1e30 mov r0, r9
 *   @0xc1e34 bl 0x27d1d0 <_ZdlPv>
 *   @0xc1e38 b 0xc1cc8 <_ZN15CSkeletonSprite16GetAnimationListEP8CDS_List+0xf0>
 *
 * ══ §22/50 F_JsonDecode(RValue&, CInstance*, CInstance*, int, RValue*)  0x13d348  size 612  153 条（0x13d348..0x13d5ac）
 * @func 0x13d348 0x13d5ac  size 612  153 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / 0xb6550×3 / 0xb6538×3 / findfirstnonspace(char const*, int, int)×2 / json_tokener_parse×2 / YYFree(void const*)×2 / YYGetReal(RValue const*, int) / json_parse(json_object*)
 * 字段偏移 top8: 0xc×2 / 0x18×1 / 0x218×1 / 0x1f0×1 / 0x160×1 / 0x148×1 / 0xd8×1 / 0xc4×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13d348 push {r4, r5, r6, r7, r8, lr}
 *   @0x13d34c mov r7, r0
 *   @0x13d350 ldr r4, [sp, #0x18]
 *   @0x13d354 ldr r3, [r4, #0xc]
 *   @0x13d358 bic r3, r3, #-16777216
 *   @0x13d35c cmp r3, #1
 *   @0x13d360 beq 0x13d3c8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x80>
 *   @0x13d364 ldr r1, [pc, #0x218]
 *   @0x13d368 movw r2, #0xb87
 *   @0x13d36c mov r3, #1
 *   @0x13d370 mov r0, #54
 *   @0x13d374 add r1, pc, r1
 *   @0x13d378 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13d37c mov r1, #0
 *   @0x13d380 mov r6, r0
 *   @0x13d384 mov r0, r4
 *   @0x13d388 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x13d38c mov r3, r1
 *   @0x13d390 ldr r1, [pc, #0x1f0]
 *   @0x13d394 mov r2, r0
 *   @0x13d398 mov r0, r6
 *   @0x13d39c add r1, pc, r1
 *   @0x13d3a0 bl 0xb6550 <sprintf@plt>
 *   @0x13d3a4 cmp r6, #0
 *   @0x13d3a8 bne 0x13d57c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0x13d3ac mov r3, #0
 *   @0x13d3b0 movt r3, #0xbff0
 *   @0x13d3b4 mov r2, #0
 *   @0x13d3b8 mov r1, #0
 *   @0x13d3bc stm r7, {r2, r3}
 *   @0x13d3c0 str r1, [r7, #0xc]
 *   @0x13d3c4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x13d3c8 ldr r3, [r4]
 *   @0x13d3cc cmp r3, #0
 *   @0x13d3d0 beq 0x13d364 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x13d3d4 ldr r6, [r3]
 *   @0x13d3d8 cmp r6, #0
 *   @0x13d3dc movne r8, #0
 *   @0x13d3e0 beq 0x13d364 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1c>
 *   @0x13d3e4 mov r0, r6
 *   @0x13d3e8 bl 0xb6538 <strlen@plt>
 *   @0x13d3ec mov r1, #1
 *   @0x13d3f0 mov r4, r0
 *   @0x13d3f4 mov r0, r6
 *   @0x13d3f8 mov r2, r4
 *   @0x13d3fc bl 0x13c350 <_Z17findfirstnonspacePKcii>
 *   @0x13d400 mov r2, r4
 *   @0x13d404 mvn r1, #0
 *   @0x13d408 mov r5, r0
 *   @0x13d40c sub r0, r4, #1
 *   @0x13d410 add r0, r6, r0
 *   @0x13d414 bl 0x13c350 <_Z17findfirstnonspacePKcii>
 *   @0x13d418 ldrb r3, [r5]
 *   @0x13d41c cmp r3, #123
 *   @0x13d420 beq 0x13d500 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1b8>
 *   @0x13d424 ldr r4, [pc, #0x160]
 *   @0x13d428 cmp r3, #91
 *   @0x13d42c mov r5, #20
 *   @0x13d430 add r4, pc, r4
 *   @0x13d434 beq 0x13d528 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0x13d438 mov r0, r6
 *   @0x13d43c bl 0xb6538 <strlen@plt>
 *   @0x13d440 ldr r1, [pc, #0x148]
 *   @0x13d444 movw r2, #0xb9d
 *   @0x13d448 mov r3, #1
 *   @0x13d44c add r1, pc, r1
 *   @0x13d450 add r0, r0, r5
 *   @0x13d454 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13d458 mov r1, r4
 *   @0x13d45c mov r2, r6
 *   @0x13d460 mov r5, r0
 *   @0x13d464 bl 0xb6550 <sprintf@plt>
 *   @0x13d468 cmp r8, #0
 *   @0x13d46c moveq r8, #1
 *   @0x13d470 bne 0x13d51c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1d4>
 *   @0x13d474 mov r0, r5
 *   @0x13d478 bl 0x28075c <json_tokener_parse>
 *   @0x13d47c cmn r0, #4000
 *   @0x13d480 mov r4, r0
 *   @0x13d484 bhi 0x13d4ac <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x164>
 *   @0x13d488 mov r0, r4
 *   @0x13d48c bl 0x13d0dc <_Z10json_parseP11json_object>
 *   @0x13d490 mov r5, r0
 *   @0x13d494 mov r0, r4
 *   @0x13d498 bl 0x27e7c8 <json_object_put>
 *   @0x13d49c vmov s15, r5
 *   @0x13d4a0 vcvt.f64.s32 d7, s15
 *   @0x13d4a4 vmov r2, r3, d7
 *   @0x13d4a8 b 0x13d3b8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x70>
 *   @0x13d4ac mov r0, r5
 *   @0x13d4b0 bl 0xb6538 <strlen@plt>
 *   @0x13d4b4 ldr r1, [pc, #0xd8]
 *   @0x13d4b8 movw r2, #0xbaa
 *   @0x13d4bc mov r3, #1
 *   @0x13d4c0 add r1, pc, r1
 *   @0x13d4c4 add r0, r0, #20
 *   @0x13d4c8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x13d4cc ldr r1, [pc, #0xc4]
 *   @0x13d4d0 mov r2, r5
 *   @0x13d4d4 add r1, pc, r1
 *   @0x13d4d8 mov r4, r0
 *   @0x13d4dc bl 0xb6550 <sprintf@plt>
 *   @0x13d4e0 cmp r8, #0
 *   @0x13d4e4 bne 0x13d544 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x13d4e8 mov r0, r4
 *   @0x13d4ec bl 0x28075c <json_tokener_parse>
 *   @0x13d4f0 cmn r0, #4000
 *   @0x13d4f4 mov r4, r0
 *   @0x13d4f8 bhi 0x13d3ac <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x64>
 *   @0x13d4fc b 0x13d488 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x140>
 *   @0x13d500 ldrb r3, [r0]
 *   @0x13d504 cmp r3, #125
 *   @0x13d508 beq 0x13d550 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x208>
 *   @0x13d50c ldr r4, [pc, #0x88]
 *   @0x13d510 mov r5, #20
 *   @0x13d514 add r4, pc, r4
 *   @0x13d518 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x13d51c mov r0, r6
 *   @0x13d520 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13d524 b 0x13d474 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x13d528 ldrb r3, [r0]
 *   @0x13d52c cmp r3, #93
 *   @0x13d530 beq 0x13d56c <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x13d534 ldr r4, [pc, #0x64]
 *   @0x13d538 mov r5, #20
 *   @0x13d53c add r4, pc, r4
 *   @0x13d540 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x13d544 mov r0, r5
 *   @0x13d548 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x13d54c b 0x13d4e8 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0x13d550 cmp r5, r0
 *   @0x13d554 movls r5, r6
 *   @0x13d558 bls 0x13d474 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x13d55c ldr r4, [pc, #0x40]
 *   @0x13d560 mov r5, #20
 *   @0x13d564 add r4, pc, r4
 *   @0x13d568 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x13d56c ldr r4, [pc, #0x34]
 *   @0x13d570 mov r5, #18
 *   @0x13d574 add r4, pc, r4
 *   @0x13d578 b 0x13d438 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0xf0>
 *   @0x13d57c mov r8, #1
 *   @0x13d580 b 0x13d3e4 <_Z12F_JsonDecodeR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x13d584 .word 0x00202cdc
 *   @0x13d588 eoreq r3, r0, r8, lsr r5
 *   @0x13d58c eoreq r3, r0, r12, lsl #9
 *   @0x13d590 eoreq r2, r0, r4, lsl #24
 *   @0x13d594 mlaeq r0, r0, r11, r2
 *   @0x13d598 eoreq r3, r0, r8, ror #7
 *   @0x13d59c eoreq r3, r0, r8, lsr #7
 *   @0x13d5a0 eoreq r3, r0, r0, lsl #7
 *   @0x13d5a4 eoreq r3, r0, r8, asr r3
 *   @0x13d5a8 eoreq r3, r0, r4, lsr r3
 *
 * ══ §23/50 FacebookSendInviteM(char*, char*, char*, char*, int)  0x15ece4  size 612  153 条（0x15ece4..0x15ef48）
 * @func 0x15ece4 0x15ef48  size 612  153 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: getJNIEnv×17 / FacebookSendInviteM(char*, char*, char*, char*, int)+0x210 / F_DsMapClear(RValue&, CInstance*, CInstance*, int, RValue*) / _JNIEnv::CallStaticVoidMethod(_jclass*, _jmethodID*, ...)
 * 字段偏移 top8: 0x29c×8 / 0x2b8×6 / 0x40×2 / 0x38×1 / 0x218×1 / 0x18×1 / 0x200×1 / 0x2b0×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15ece4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x15ece8 sub sp, sp, #28
 *   @0x15ecec mov r6, r2
 *   @0x15ecf0 mov r7, r1
 *   @0x15ecf4 mov r8, r0
 *   @0x15ecf8 ldr r5, [sp, #0x38]
 *   @0x15ecfc bl 0x290274 <getJNIEnv>
 *   @0x15ed00 mov r4, r0
 *   @0x15ed04 bl 0x290274 <getJNIEnv>
 *   @0x15ed08 ldr r1, [pc, #0x218]
 *   @0x15ed0c add r1, pc, r1
 *   @0x15ed10 ldr r3, [r0]
 *   @0x15ed14 ldr r3, [r3, #0x18]
 *   @0x15ed18 blx r3
 *   @0x15ed1c mov r9, r0
 *   @0x15ed20 bl 0x290274 <getJNIEnv>
 *   @0x15ed24 ldr r1, [pc, #0x200]
 *   @0x15ed28 add r1, pc, r1
 *   @0x15ed2c ldr r3, [r0]
 *   @0x15ed30 ldr r3, [r3, #0x29c]
 *   @0x15ed34 blx r3
 *   @0x15ed38 ldr r12, [r4]
 *   @0x15ed3c mov r2, r9
 *   @0x15ed40 mov r1, #6
 *   @0x15ed44 ldr r12, [r12, #0x2b0]
 *   @0x15ed48 mov r3, r0
 *   @0x15ed4c mov r0, r4
 *   @0x15ed50 blx r12
 *   @0x15ed54 mov r4, r0
 *   @0x15ed58 bl 0x290274 <getJNIEnv>
 *   @0x15ed5c ldr r1, [pc, #0x1cc]
 *   @0x15ed60 add r1, pc, r1
 *   @0x15ed64 ldr r3, [r0]
 *   @0x15ed68 ldr r3, [r3, #0x29c]
 *   @0x15ed6c blx r3
 *   @0x15ed70 mov r9, r0
 *   @0x15ed74 bl 0x290274 <getJNIEnv>
 *   @0x15ed78 mov r2, #0
 *   @0x15ed7c mov r3, r9
 *   @0x15ed80 mov r1, r4
 *   @0x15ed84 ldr r12, [r0]
 *   @0x15ed88 ldr r12, [r12, #0x2b8]
 *   @0x15ed8c blx r12
 *   @0x15ed90 bl 0x290274 <getJNIEnv>
 *   @0x15ed94 mov r1, r8
 *   @0x15ed98 ldr r3, [r0]
 *   @0x15ed9c ldr r3, [r3, #0x29c]
 *   @0x15eda0 blx r3
 *   @0x15eda4 mov r8, r0
 *   @0x15eda8 bl 0x290274 <getJNIEnv>
 *   @0x15edac mov r2, #1
 *   @0x15edb0 mov r3, r8
 *   @0x15edb4 mov r1, r4
 *   @0x15edb8 ldr r12, [r0]
 *   @0x15edbc ldr r12, [r12, #0x2b8]
 *   @0x15edc0 blx r12
 *   @0x15edc4 bl 0x290274 <getJNIEnv>
 *   @0x15edc8 ldr r1, [pc, #0x164]
 *   @0x15edcc add r1, pc, r1
 *   @0x15edd0 ldr r3, [r0]
 *   @0x15edd4 ldr r3, [r3, #0x29c]
 *   @0x15edd8 blx r3
 *   @0x15eddc mov r8, r0
 *   @0x15ede0 bl 0x290274 <getJNIEnv>
 *   @0x15ede4 mov r2, #2
 *   @0x15ede8 mov r3, r8
 *   @0x15edec mov r1, r4
 *   @0x15edf0 ldr r12, [r0]
 *   @0x15edf4 ldr r12, [r12, #0x2b8]
 *   @0x15edf8 blx r12
 *   @0x15edfc bl 0x290274 <getJNIEnv>
 *   @0x15ee00 mov r1, r7
 *   @0x15ee04 ldr r3, [r0]
 *   @0x15ee08 ldr r3, [r3, #0x29c]
 *   @0x15ee0c blx r3
 *   @0x15ee10 mov r7, r0
 *   @0x15ee14 bl 0x290274 <getJNIEnv>
 *   @0x15ee18 mov r2, #3
 *   @0x15ee1c mov r3, r7
 *   @0x15ee20 mov r1, r4
 *   @0x15ee24 ldr r12, [r0]
 *   @0x15ee28 ldr r12, [r12, #0x2b8]
 *   @0x15ee2c blx r12
 *   @0x15ee30 bl 0x290274 <getJNIEnv>
 *   @0x15ee34 ldr r1, [pc, #0xfc]
 *   @0x15ee38 add r1, pc, r1
 *   @0x15ee3c ldr r3, [r0]
 *   @0x15ee40 ldr r3, [r3, #0x29c]
 *   @0x15ee44 blx r3
 *   @0x15ee48 mov r7, r0
 *   @0x15ee4c bl 0x290274 <getJNIEnv>
 *   @0x15ee50 mov r2, #4
 *   @0x15ee54 mov r3, r7
 *   @0x15ee58 mov r1, r4
 *   @0x15ee5c ldr r12, [r0]
 *   @0x15ee60 ldr r12, [r12, #0x2b8]
 *   @0x15ee64 blx r12
 *   @0x15ee68 bl 0x290274 <getJNIEnv>
 *   @0x15ee6c mov r1, r6
 *   @0x15ee70 ldr r3, [r0]
 *   @0x15ee74 ldr r3, [r3, #0x29c]
 *   @0x15ee78 blx r3
 *   @0x15ee7c mov r6, r0
 *   @0x15ee80 bl 0x290274 <getJNIEnv>
 *   @0x15ee84 mov r3, r6
 *   @0x15ee88 mov r1, r4
 *   @0x15ee8c mov r2, #5
 *   @0x15ee90 ldr r12, [r0]
 *   @0x15ee94 ldr r12, [r12, #0x2b8]
 *   @0x15ee98 blx r12
 *   @0x15ee9c bl 0x290274 <getJNIEnv>
 *   @0x15eea0 ldr r1, [pc, #0x94]
 *   @0x15eea4 add r1, pc, r1
 *   @0x15eea8 ldr r3, [r0]
 *   @0x15eeac ldr r3, [r3, #0x29c]
 *   @0x15eeb0 blx r3
 *   @0x15eeb4 cmp r5, #0
 *   @0x15eeb8 mov r6, r0
 *   @0x15eebc blt 0x15eef4 <_Z19FacebookSendInviteMPcS_S_S_i+0x210>
 *   @0x15eec0 vmov s13, r5
 *   @0x15eec4 add r12, sp, #24
 *   @0x15eec8 mov r0, #0
 *   @0x15eecc mov r3, #1
 *   @0x15eed0 vcvt.f64.s32 d7, s13
 *   @0x15eed4 mov r1, r0
 *   @0x15eed8 mov r2, r0
 *   @0x15eedc str r0, [sp, #0x14]
 *   @0x15eee0 vmov r8, r9, d7
 *   @0x15eee4 strd r8, r9, [r12, #-16]!
 *   @0x15eee8 mov r0, r12
 *   @0x15eeec str r12, [sp]
 *   @0x15eef0 bl 0xfed40 <_Z12F_DsMapClearR6RValueP9CInstanceS2_iPS_>
 *   @0x15eef4 bl 0x290274 <getJNIEnv>
 *   @0x15eef8 ldr r1, [pc, #0x40]
 *   @0x15eefc ldr r2, [pc, #0x40]
 *   @0x15ef00 mov r3, r6
 *   @0x15ef04 ldr r1, [pc, r1]
 *   @0x15ef08 ldr r2, [pc, r2]
 *   @0x15ef0c ldr r1, [r1]
 *   @0x15ef10 ldr r2, [r2]
 *   @0x15ef14 stm sp, {r4, r5}
 *   @0x15ef18 bl 0xc4ad4 <_ZN7_JNIEnv20CallStaticVoidMethodEP7_jclassP10_jmethodIDz>
 *   @0x15ef1c mov r0, #1
 *   @0x15ef20 add sp, sp, #28
 *   @0x15ef24 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x15ef28 andseq r10, lr, r4, asr r10
 *   @0x15ef2c andseq pc, r12, lr, lsl #28
 *   @0x15ef30 andseq r10, lr, r12, ror #20
 *   @0x15ef34 ldrheq r10, [lr], -r8
 *   @0x15ef38 andseq r10, lr, r4, asr r9
 *   @0x15ef3c andseq r10, lr, r0, lsr r9
 *   @0x15ef40 eoreq lr, r8, r0, lsr #21
 *   @0x15ef44 .word 0x00290fb0
 *
 * ══ §24/50 ContactsStack::Push(b2Contact*)  0x23bec4  size 612  153 条（0x23bec4..0x23c128）
 * @func 0x23bec4 0x23c128  size 612  153 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65bc×2 / b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float) / ContactsStack::Push(b2Contact*)+0xfc / ContactsStack::Push(b2Contact*)+0x190 / MemoryManager::Alloc(unsigned int, char const*, int, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x8×9 / 0x4×6 / 0xc×3 / 0x24×3 / 0x-c×3 / 0x-8×3 / 0x-4×3 / 0x30×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23bec4 ldr r3, [r1, #0x30]
 *   @0x23bec8 ldr r12, [r1, #0x34]
 *   @0x23becc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x23bed0 sub sp, sp, #752
 *   @0x23bed4 ldr r2, [r3, #0x8]
 *   @0x23bed8 add r9, sp, #12
 *   @0x23bedc ldr r3, [r3, #0xc]
 *   @0x23bee0 add r8, r1, #64
 *   @0x23bee4 ldr lr, [r12, #0x8]
 *   @0x23bee8 mov r6, r1
 *   @0x23beec mov r7, r0
 *   @0x23bef0 mov r1, r8
 *   @0x23bef4 ldr r3, [r3, #0x8]
 *   @0x23bef8 add lr, lr, #12
 *   @0x23befc str lr, [sp]
 *   @0x23bf00 mov r0, r9
 *   @0x23bf04 ldr r12, [r12, #0xc]
 *   @0x23bf08 add r2, r2, #12
 *   @0x23bf0c ldr r12, [r12, #0x8]
 *   @0x23bf10 str r12, [sp, #0x4]
 *   @0x23bf14 bl 0x2c32c8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f>
 *   @0x23bf18 ldr r4, [r7, #0x4]
 *   @0x23bf1c ldr r5, [r6, #0x30]
 *   @0x23bf20 cmp r4, #0
 *   @0x23bf24 ldrle r6, [r6, #0x34]
 *   @0x23bf28 ble 0x23bfc0 <_ZN13ContactsStack4PushEP9b2Contact+0xfc>
 *   @0x23bf2c mov r3, #0
 *   @0x23bf30 ldr r6, [r6, #0x34]
 *   @0x23bf34 ldr r12, [r7]
 *   @0x23bf38 b 0x23bf50 <_ZN13ContactsStack4PushEP9b2Contact+0x8c>
 *   @0x23bf3c cmp r2, r6
 *   @0x23bf40 beq 0x23bfa8 <_ZN13ContactsStack4PushEP9b2Contact+0xe4>
 *   @0x23bf44 cmp r3, r4
 *   @0x23bf48 add r12, r12, #716
 *   @0x23bf4c beq 0x23bfc0 <_ZN13ContactsStack4PushEP9b2Contact+0xfc>
 *   @0x23bf50 cmp r12, #0
 *   @0x23bf54 add r3, r3, #1
 *   @0x23bf58 beq 0x23bf44 <_ZN13ContactsStack4PushEP9b2Contact+0x80>
 *   @0x23bf5c ldr r2, [r12, #0x4]
 *   @0x23bf60 cmp r2, r5
 *   @0x23bf64 bne 0x23bf3c <_ZN13ContactsStack4PushEP9b2Contact+0x78>
 *   @0x23bf68 ldr r1, [r12, #0x8]
 *   @0x23bf6c cmp r1, r6
 *   @0x23bf70 bne 0x23bf3c <_ZN13ContactsStack4PushEP9b2Contact+0x78>
 *   @0x23bf74 ldr r3, [r12]
 *   @0x23bf78 cmp r3, #7
 *   @0x23bf7c ble 0x23c054 <_ZN13ContactsStack4PushEP9b2Contact+0x190>
 *   @0x23bf80 ldr r3, [pc, #0x194]
 *   @0x23bf84 ldr r1, [pc, #0x194]
 *   @0x23bf88 ldr r3, [pc, r3]
 *   @0x23bf8c add r1, pc, r1
 *   @0x23bf90 ldr r0, [r3]
 *   @0x23bf94 ldr r3, [r0]
 *   @0x23bf98 ldr r3, [r3, #0xc]
 *   @0x23bf9c blx r3
 *   @0x23bfa0 add sp, sp, #752
 *   @0x23bfa4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x23bfa8 ldr r2, [r12, #0x8]
 *   @0x23bfac cmp r2, r5
 *   @0x23bfb0 beq 0x23bf74 <_ZN13ContactsStack4PushEP9b2Contact+0xb0>
 *   @0x23bfb4 cmp r3, r4
 *   @0x23bfb8 add r12, r12, #716
 *   @0x23bfbc bne 0x23bf50 <_ZN13ContactsStack4PushEP9b2Contact+0x8c>
 *   @0x23bfc0 add lr, sp, #48
 *   @0x23bfc4 add r10, r8, #64
 *   @0x23bfc8 mov r3, #0
 *   @0x23bfcc str r5, [sp, #0x28]
 *   @0x23bfd0 str r6, [sp, #0x2c]
 *   @0x23bfd4 str r3, [sp, #0x24]
 *   @0x23bfd8 ldr r0, [r8]
 *   @0x23bfdc add r8, r8, #16
 *   @0x23bfe0 ldr r1, [r8, #-0xc]
 *   @0x23bfe4 mov r12, lr
 *   @0x23bfe8 ldr r2, [r8, #-0x8]
 *   @0x23bfec add lr, lr, #16
 *   @0x23bff0 ldr r3, [r8, #-0x4]
 *   @0x23bff4 cmp r8, r10
 *   @0x23bff8 stm r12!, {r0, r1, r2, r3}
 *   @0x23bffc bne 0x23bfd8 <_ZN13ContactsStack4PushEP9b2Contact+0x114>
 *   @0x23c000 ldm r9!, {r0, r1, r2, r3}
 *   @0x23c004 add r12, sp, #560
 *   @0x23c008 ldr r5, [r7, #0x8]
 *   @0x23c00c ldr lr, [sp, #0x24]
 *   @0x23c010 cmp r4, r5
 *   @0x23c014 stm r12!, {r0, r1, r2, r3}
 *   @0x23c018 add lr, lr, #1
 *   @0x23c01c ldm r9, {r0, r1}
 *   @0x23c020 str lr, [sp, #0x24]
 *   @0x23c024 stm r12, {r0, r1}
 *   @0x23c028 beq 0x23c0cc <_ZN13ContactsStack4PushEP9b2Contact+0x208>
 *   @0x23c02c ldr r0, [r7]
 *   @0x23c030 mov r2, #716
 *   @0x23c034 add r1, sp, #36
 *   @0x23c038 mla r0, r2, r4, r0
 *   @0x23c03c bl 0xb65bc <memcpy@plt>
 *   @0x23c040 ldr r3, [r7, #0x4]
 *   @0x23c044 add r3, r3, #1
 *   @0x23c048 str r3, [r7, #0x4]
 *   @0x23c04c add sp, sp, #752
 *   @0x23c050 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x23c054 add r3, r12, r3, lsl #6
 *   @0x23c058 add r2, r8, #64
 *   @0x23c05c add r3, r3, #12
 *   @0x23c060 ldr r5, [r8]
 *   @0x23c064 add r8, r8, #16
 *   @0x23c068 ldr r4, [r8, #-0xc]
 *   @0x23c06c add r3, r3, #16
 *   @0x23c070 ldr r0, [r8, #-0x8]
 *   @0x23c074 ldr r1, [r8, #-0x4]
 *   @0x23c078 cmp r8, r2
 *   @0x23c07c str r5, [r3, #-0x10]
 *   @0x23c080 str r4, [r3, #-0xc]
 *   @0x23c084 str r0, [r3, #-0x8]
 *   @0x23c088 str r1, [r3, #-0x4]
 *   @0x23c08c bne 0x23c060 <_ZN13ContactsStack4PushEP9b2Contact+0x19c>
 *   @0x23c090 ldr r4, [r12]
 *   @0x23c094 ldm r9!, {r0, r1, r2, r3}
 *   @0x23c098 add r4, r4, r4, lsl #1
 *   @0x23c09c add r5, r12, r4, lsl #3
 *   @0x23c0a0 str r0, [r5, #0x20c]
 *   @0x23c0a4 str r1, [r5, #0x210]
 *   @0x23c0a8 str r2, [r5, #0x214]
 *   @0x23c0ac str r3, [r5, #0x218]
 *   @0x23c0b0 ldm r9!, {r0, r1}
 *   @0x23c0b4 str r0, [r5, #0x21c]
 *   @0x23c0b8 str r1, [r5, #0x220]
 *   @0x23c0bc ldr r3, [r12]
 *   @0x23c0c0 add r3, r3, #1
 *   @0x23c0c4 str r3, [r12]
 *   @0x23c0c8 b 0x23bfa0 <_ZN13ContactsStack4PushEP9b2Contact+0xdc>
 *   @0x23c0cc add r5, r4, #10
 *   @0x23c0d0 ldr r1, [pc, #0x4c]
 *   @0x23c0d4 mov r4, #716
 *   @0x23c0d8 mov r3, #1
 *   @0x23c0dc add r1, pc, r1
 *   @0x23c0e0 mov r2, #40
 *   @0x23c0e4 mul r0, r4, r5
 *   @0x23c0e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x23c0ec ldr r2, [r7, #0x8]
 *   @0x23c0f0 ldr r1, [r7]
 *   @0x23c0f4 mul r2, r4, r2
 *   @0x23c0f8 mov r6, r0
 *   @0x23c0fc bl 0xb65bc <memcpy@plt>
 *   @0x23c100 ldr r0, [r7]
 *   @0x23c104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x23c108 ldr r4, [r7, #0x4]
 *   @0x23c10c mov r0, r6
 *   @0x23c110 str r5, [r7, #0x8]
 *   @0x23c114 str r6, [r7]
 *   @0x23c118 b 0x23c030 <_ZN13ContactsStack4PushEP9b2Contact+0x16c>
 *   @0x23c11c andseq r1, r11, r12, lsl #15
 *   @0x23c120 mulseq r1, r12, r3
 *   @0x23c124 andseq r9, r1, r8, lsr #2
 *
 * ══ §25/50 _spDeformTimeline_apply  0x2821c8  size 612  153 条（0x2821c8..0x28242c）
 * @func 0x2821c8 0x28242c  size 612  153 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _spDeformTimeline_apply+0x5c×3 / _spDeformTimeline_apply+0x12c / _spDeformTimeline_apply+0x13c / _free / _malloc / spCurveTimeline_getCurvePercent
 * 字段偏移 top8: 0x24×5 / 0x20×4 / 0x1c×3 / 0x18×3 / 0x14×2 / 0x2×2 / 0x10×2 / 0x4×1
 * VFP 指令 49 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2821c8 push {r4, r5, r6, r7, r8, lr}
 *   @0x2821cc vpush {d8, d9}
 *   @0x2821d0 mov r4, r0
 *   @0x2821d4 vldr s16, [sp, #48]
 *   @0x2821d8 ldr r1, [r1, #0x14]
 *   @0x2821dc vmov s17, r3
 *   @0x2821e0 ldr r0, [r0, #0x1c]
 *   @0x2821e4 ldr r2, [r4, #0x20]
 *   @0x2821e8 ldr r5, [r1, r0, lsl #2]
 *   @0x2821ec ldr r3, [r5, #0x18]
 *   @0x2821f0 cmp r3, r2
 *   @0x2821f4 beq 0x28222c <_spDeformTimeline_apply+0x64>
 *   @0x2821f8 cmp r3, #0
 *   @0x2821fc beq 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282200 ldr r1, [r3, #0x4]
 *   @0x282204 cmp r1, #2
 *   @0x282208 bne 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x28220c ldr r1, [r3, #0x80]
 *   @0x282210 cmp r1, #0
 *   @0x282214 beq 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282218 ldr r3, [r3, #0x7c]
 *   @0x28221c cmp r2, r3
 *   @0x282220 beq 0x28222c <_spDeformTimeline_apply+0x64>
 *   @0x282224 vpop {d8, d9}
 *   @0x282228 pop {r4, r5, r6, r7, r8, pc}
 *   @0x28222c ldr r2, [r4, #0x10]
 *   @0x282230 vldr s15, [r2]
 *   @0x282234 vcmpe.f32 s15, s17
 *   @0x282238 vmrs APSR_nzcv, fpscr
 *   @0x28223c bgt 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282240 ldr r6, [r4, #0x14]
 *   @0x282244 ldr r3, [r5, #0x20]
 *   @0x282248 cmp r6, r3
 *   @0x28224c ble 0x2822f4 <_spDeformTimeline_apply+0x12c>
 *   @0x282250 ldr r3, [r5, #0x1c]
 *   @0x282254 cmp r6, r3
 *   @0x282258 vmovle.f32 s16, #1.000000e+00
 *   @0x28225c bgt 0x2822c8 <_spDeformTimeline_apply+0x100>
 *   @0x282260 ldr r3, [r4, #0xc]
 *   @0x282264 str r6, [r5, #0x20]
 *   @0x282268 sub r1, r3, #-1073741823
 *   @0x28226c add r0, r2, r1, lsl #2
 *   @0x282270 vldr s15, [r0]
 *   @0x282274 vcmpe.f32 s17, s15
 *   @0x282278 vmrs APSR_nzcv, fpscr
 *   @0x28227c blt 0x282304 <_spDeformTimeline_apply+0x13c>
 *   @0x282280 vmov.f32 s15, #1.000000e+00
 *   @0x282284 ldr r3, [r4, #0x18]
 *   @0x282288 ldr r1, [r3, r1, lsl #2]
 *   @0x28228c vcmpe.f32 s16, s15
 *   @0x282290 vmrs APSR_nzcv, fpscr
 *   @0x282294 bpl 0x2823d8 <_spDeformTimeline_apply+0x210>
 *   @0x282298 cmp r6, #0
 *   @0x28229c ble 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x2822a0 ldr r3, [r5, #0x24]
 *   @0x2822a4 add r6, r1, r6, lsl #2
 *   @0x2822a8 vldmia r1!, {s14}
 *   @0x2822ac vldr s15, [r3]
 *   @0x2822b0 vsub.f32 s14, s14, s15
 *   @0x2822b4 cmp r1, r6
 *   @0x2822b8 vmla.f32 s15, s14, s16
 *   @0x2822bc vstmia r3!, {s15}
 *   @0x2822c0 bne 0x2822a8 <_spDeformTimeline_apply+0xe0>
 *   @0x2822c4 b 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x2822c8 ldr r0, [r5, #0x24]
 *   @0x2822cc bl 0x285c80 <_free>
 *   @0x2822d0 ldr r1, [pc, #0x150]
 *   @0x2822d4 movw r2, #0x2d6
 *   @0x2822d8 lsl r0, r6, #2
 *   @0x2822dc add r1, pc, r1
 *   @0x2822e0 bl 0x285c10 <_malloc>
 *   @0x2822e4 ldr r3, [r5, #0x20]
 *   @0x2822e8 ldr r2, [r4, #0x10]
 *   @0x2822ec str r6, [r5, #0x1c]
 *   @0x2822f0 str r0, [r5, #0x24]
 *   @0x2822f4 vmov.f32 s15, #1.000000e+00
 *   @0x2822f8 cmp r6, r3
 *   @0x2822fc vmovne.f32 s16, s15
 *   @0x282300 b 0x282260 <_spDeformTimeline_apply+0x98>
 *   @0x282304 subs r3, r3, #2
 *   @0x282308 bne 0x282394 <_spDeformTimeline_apply+0x1cc>
 *   @0x28230c mov r8, r3
 *   @0x282310 mov r7, #4
 *   @0x282314 mov r1, r3
 *   @0x282318 add r3, r2, r7
 *   @0x28231c add r2, r2, r8
 *   @0x282320 vldr s15, [r3]
 *   @0x282324 vldr s14, [r2]
 *   @0x282328 vsub.f32 s17, s17, s15
 *   @0x28232c mov r0, r4
 *   @0x282330 vsub.f32 s15, s14, s15
 *   @0x282334 vdiv.f32 s15, s17, s15
 *   @0x282338 vmov.f32 s18, #1.000000e+00
 *   @0x28233c vsub.f32 s15, s18, s15
 *   @0x282340 vmov r2, s15
 *   @0x282344 bl 0x2818e0 <spCurveTimeline_getCurvePercent>
 *   @0x282348 vcmpe.f32 s16, s18
 *   @0x28234c ldr r2, [r4, #0x18]
 *   @0x282350 vmrs APSR_nzcv, fpscr
 *   @0x282354 ldr r3, [r2, r8]
 *   @0x282358 ldr r2, [r2, r7]
 *   @0x28235c vmov s13, r0
 *   @0x282360 bmi 0x2823ec <_spDeformTimeline_apply+0x224>
 *   @0x282364 cmp r6, #0
 *   @0x282368 addgt r6, r3, r6, lsl #2
 *   @0x28236c ldrgt r1, [r5, #0x24]
 *   @0x282370 ble 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282374 vldmia r3!, {s15}
 *   @0x282378 vldmia r2!, {s14}
 *   @0x28237c vsub.f32 s14, s14, s15
 *   @0x282380 cmp r3, r6
 *   @0x282384 vmla.f32 s15, s14, s13
 *   @0x282388 vstmia r1!, {s15}
 *   @0x28238c bne 0x282374 <_spDeformTimeline_apply+0x1ac>
 *   @0x282390 b 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282394 asr r0, r3, #1
 *   @0x282398 mov r1, #0
 *   @0x28239c add r12, r0, #1
 *   @0x2823a0 add lr, r2, r12, lsl #2
 *   @0x2823a4 vldr s15, [lr]
 *   @0x2823a8 vcmpe.f32 s17, s15
 *   @0x2823ac vmrs APSR_nzcv, fpscr
 *   @0x2823b0 movge r1, r12
 *   @0x2823b4 movlt r3, r0
 *   @0x2823b8 add r0, r1, r3
 *   @0x2823bc cmp r1, r3
 *   @0x2823c0 asr r0, r0, #1
 *   @0x2823c4 bne 0x28239c <_spDeformTimeline_apply+0x1d4>
 *   @0x2823c8 add r7, r1, #1
 *   @0x2823cc lsl r7, r7, #2
 *   @0x2823d0 sub r8, r7, #4
 *   @0x2823d4 b 0x282318 <_spDeformTimeline_apply+0x150>
 *   @0x2823d8 vpop {d8, d9}
 *   @0x2823dc lsl r2, r6, #2
 *   @0x2823e0 ldr r0, [r5, #0x24]
 *   @0x2823e4 pop {r4, r5, r6, r7, r8, lr}
 *   @0x2823e8 b 0xb65bc <memcpy@plt>
 *   @0x2823ec cmp r6, #0
 *   @0x2823f0 ble 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x2823f4 ldr r1, [r5, #0x24]
 *   @0x2823f8 add r6, r3, r6, lsl #2
 *   @0x2823fc vldmia r3!, {s14}
 *   @0x282400 vldmia r2!, {s12}
 *   @0x282404 vsub.f32 s12, s12, s14
 *   @0x282408 vldr s15, [r1]
 *   @0x28240c cmp r3, r6
 *   @0x282410 vmla.f32 s14, s12, s13
 *   @0x282414 vsub.f32 s14, s14, s15
 *   @0x282418 vmla.f32 s15, s14, s16
 *   @0x28241c vstmia r1!, {s15}
 *   @0x282420 bne 0x2823fc <_spDeformTimeline_apply+0x234>
 *   @0x282424 b 0x282224 <_spDeformTimeline_apply+0x5c>
 *   @0x282428 andeq r5, sp, r4, ror r1
 *
 * ══ §26/50 F_Vertex_Submit_release(RValue&, CInstance*, CInstance*, int, RValue*)  0xca24c  size 608  152 条（0xca24c..0xca4ac）
 * @func 0xca24c 0xca4ac  size 608  152 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×2 / GetVertexFormat(int)×2 / Graphics::AllocVerts(ePrimType, void*, int, int)×2 / YYGetPtrOrInt(RValue const*, int) / GR_Texture_Exists(int) / Graphics::GetMaxDynamicVertexCount() / Graphics::GetMaxDynamicVertexSpace() / F_Vertex_Submit_release(RValue&, CInstance*, CInstance*, int, RValue*)+0xd0
 * 字段偏移 top8: 0x28×5 / 0x30×4 / 0x2×4 / 0x14×4 / 0x4×3 / 0x20×3 / 0x1c×3 / 0xc×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xca24c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xca250 sub sp, sp, #12
 *   @0xca254 ldr r2, [pc, #0x23c]
 *   @0xca258 mov r1, #0
 *   @0xca25c ldr r5, [sp, #0x30]
 *   @0xca260 mov r3, r1
 *   @0xca264 add r2, pc, r2
 *   @0xca268 movt r3, #0xbff0
 *   @0xca26c str r1, [r0, #0xc]
 *   @0xca270 stm r0, {r1, r3}
 *   @0xca274 mov r0, r5
 *   @0xca278 ldr r4, [r2]
 *   @0xca27c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca280 mov r1, #1
 *   @0xca284 ldr r4, [r4, r0, lsl #2]
 *   @0xca288 mov r0, r5
 *   @0xca28c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xca290 mov r1, #2
 *   @0xca294 mov r8, r0
 *   @0xca298 mov r0, r5
 *   @0xca29c bl 0xce6c0 <_Z13YYGetPtrOrIntPK6RValuei>
 *   @0xca2a0 mov r5, r0
 *   @0xca2a4 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0xca2a8 cmp r0, #0
 *   @0xca2ac bne 0xca3c8 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0xca2b0 cmn r5, #1
 *   @0xca2b4 moveq r10, r0
 *   @0xca2b8 beq 0xca2d4 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x88>
 *   @0xca2bc ldr r3, [pc, #0x1d8]
 *   @0xca2c0 ldrsh r2, [r5, #20]
 *   @0xca2c4 ldr r3, [pc, r3]
 *   @0xca2c8 ldr r3, [r3, #0x4]
 *   @0xca2cc ldr r3, [r3, r2, lsl #2]
 *   @0xca2d0 ldr r10, [r3]
 *   @0xca2d4 ldrb r3, [r4, #0x20]
 *   @0xca2d8 cmp r3, #0
 *   @0xca2dc bne 0xca3e8 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x19c>
 *   @0xca2e0 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0xca2e4 mov r6, r0
 *   @0xca2e8 bl 0x185624 <_ZN8Graphics24GetMaxDynamicVertexSpaceEv>
 *   @0xca2ec mov r5, r0
 *   @0xca2f0 ldr r0, [r4, #0x28]
 *   @0xca2f4 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xca2f8 cmp r0, #0
 *   @0xca2fc beq 0xca480 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0xca300 ldr r2, [r0, #0x14]
 *   @0xca304 ldr r3, [r4, #0x1c]
 *   @0xca308 mul r2, r2, r3
 *   @0xca30c cmp r5, r2
 *   @0xca310 ble 0xca31c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0xd0>
 *   @0xca314 cmp r6, r3
 *   @0xca318 bgt 0xca45c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x210>
 *   @0xca31c sub r3, r8, #1
 *   @0xca320 cmp r3, #3
 *   @0xca324 bhi 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0xca328 ldr r2, [pc, #0x170]
 *   @0xca32c add r2, pc, r2
 *   @0xca330 ldr r11, [r2, r3, lsl #2]
 *   @0xca334 cmn r11, #1
 *   @0xca338 beq 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0xca33c ldr r0, [r4, #0x28]
 *   @0xca340 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0xca344 subs r9, r0, #0
 *   @0xca348 beq 0xca480 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x234>
 *   @0xca34c ldr r1, [r9, #0x14]
 *   @0xca350 mov r0, r5
 *   @0xca354 bl 0x318c48 <__udivsi3>
 *   @0xca358 mov r1, r11
 *   @0xca35c cmp r0, r6
 *   @0xca360 movge r0, r6
 *   @0xca364 bl 0x318d10 <__divsi3>
 *   @0xca368 ldr r6, [r4, #0x1c]
 *   @0xca36c ldr r7, [r4]
 *   @0xca370 cmp r6, #0
 *   @0xca374 mul r11, r11, r0
 *   @0xca378 ble 0xca3c0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0xca37c cmp r6, r11
 *   @0xca380 movlt r5, r6
 *   @0xca384 movge r5, r11
 *   @0xca388 mov r1, r10
 *   @0xca38c ldr r2, [r4, #0x28]
 *   @0xca390 mov r0, r8
 *   @0xca394 mov r3, r5
 *   @0xca398 rsb r6, r5, r6
 *   @0xca39c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xca3a0 ldr r2, [r9, #0x14]
 *   @0xca3a4 mov r1, r7
 *   @0xca3a8 mul r2, r2, r5
 *   @0xca3ac bl 0xb65bc <memcpy@plt>
 *   @0xca3b0 ldr r3, [r9, #0x14]
 *   @0xca3b4 cmp r6, #0
 *   @0xca3b8 mla r7, r3, r5, r7
 *   @0xca3bc bgt 0xca37c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x130>
 *   @0xca3c0 add sp, sp, #12
 *   @0xca3c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xca3c8 ldr r3, [pc, #0xd4]
 *   @0xca3cc ldr r3, [pc, r3]
 *   @0xca3d0 ldr r3, [r3, #0x4]
 *   @0xca3d4 ldr r3, [r3, r5, lsl #2]
 *   @0xca3d8 ldr r10, [r3]
 *   @0xca3dc ldrb r3, [r4, #0x20]
 *   @0xca3e0 cmp r3, #0
 *   @0xca3e4 beq 0xca2e0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xca3e8 mov r0, r8
 *   @0xca3ec bl 0x185638 <_ZN8Graphics25IsSupportedNativePrimtypeE9ePrimType>
 *   @0xca3f0 cmp r0, #0
 *   @0xca3f4 beq 0xca2e0 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0xca3f8 ldr r0, [r4, #0x30]
 *   @0xca3fc cmp r0, #0
 *   @0xca400 beq 0xca42c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0xca404 bl 0x183958 <_ZN12VertexBuffer7IsValidEv>
 *   @0xca408 cmp r0, #0
 *   @0xca40c bne 0xca434 <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e8>
 *   @0xca410 ldr r5, [r4, #0x30]
 *   @0xca414 cmp r5, #0
 *   @0xca418 beq 0xca42c <_Z23F_Vertex_Submit_releaseR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0xca41c mov r0, r5
 *   @0xca420 bl 0x18373c <_ZN12VertexBufferD2Ev>
 *   @0xca424 mov r0, r5
 *   @0xca428 bl 0x27d1d0 <_ZdlPv>
 *   @0xca42c mov r0, r4
 *   @0xca430 bl 0xca1a0 <_Z13_FreezeBufferP13Buffer_Vertex>
 *   @0xca434 ldr r1, [r4, #0x1c]
 *   @0xca438 mov r0, r8
 *   @0xca43c ldr r3, [r4, #0x28]
 *   @0xca440 mov r2, #0
 *   @0xca444 str r10, [sp]
 *   @0xca448 ldr r12, [r4, #0x30]
 *   @0xca44c str r12, [sp, #0x4]
 *   @0xca450 bl 0x185730 <_ZN8Graphics15DrawArrayFromVBE9ePrimTypeiiiPvP12VertexBuffer>
 *   @0xca454 add sp, sp, #12
 *   @0xca458 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xca45c mov r1, r10
 *   @0xca460 ldr r2, [r4, #0x28]
 *   @0xca464 mov r0, r8
 *   @0xca468 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0xca46c ldr r1, [r4]
 *   @0xca470 ldr r2, [r4, #0xc]
 *   @0xca474 add sp, sp, #12
 *   @0xca478 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xca47c b 0xb65bc <memcpy@plt>
 *   @0xca480 ldr r0, [pc, #0x20]
 *   @0xca484 mov r1, #1
 *   @0xca488 add r0, pc, r0
 *   @0xca48c add sp, sp, #12
 *   @0xca490 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xca494 b 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xca498 ldrsbteq pc, [r10], -r0
 *   @0xca49c eorseq r3, r2, r8, asr r6
 *   @0xca4a0 eoreq r2, r9, r12, lsl #9
 *   @0xca4a4 eorseq r3, r2, r0, asr r5
 *   @0xca4a8 eoreq r7, r6, r8, ror r9
 *
 * ══ §27/50 Color_RGBtoHSV(TRGB)  0x20fa48  size 608  152 条（0x20fa48..0x20fca8）
 * @func 0x20fa48 0x20fca8  size 608  152 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Color_RGBtoHSV(TRGB)+0x140×2 / Color_RGBtoHSV(TRGB)+0x114 / Color_RGBtoHSV(TRGB)+0x70
 * 字段偏移 top8: 无
 * VFP 指令 101 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20fa48 ubfx r3, r0, #0x10, #0x8
 *   @0x20fa4c vldr s13, [pc, #576]
 *   @0x20fa50 sub sp, sp, #16
 *   @0x20fa54 vmov s14, r3
 *   @0x20fa58 ubfx r3, r0, #0x8, #0x8
 *   @0x20fa5c uxtb r0, r0
 *   @0x20fa60 vmov s15, r3
 *   @0x20fa64 vcvt.f32.s32 s14, s14
 *   @0x20fa68 vmov s11, r0
 *   @0x20fa6c vcvt.f32.s32 s15, s15
 *   @0x20fa70 vdiv.f32 s14, s14, s13
 *   @0x20fa74 vdiv.f32 s15, s15, s13
 *   @0x20fa78 vcvt.f32.s32 s12, s11
 *   @0x20fa7c vcmpe.f32 s14, s15
 *   @0x20fa80 vdiv.f32 s12, s12, s13
 *   @0x20fa84 vmrs APSR_nzcv, fpscr
 *   @0x20fa88 bpl 0x20fb38 <_Z14Color_RGBtoHSV4TRGB+0xf0>
 *   @0x20fa8c vcmpe.f32 s14, s12
 *   @0x20fa90 vmrs APSR_nzcv, fpscr
 *   @0x20fa94 bpl 0x20fb80 <_Z14Color_RGBtoHSV4TRGB+0x138>
 *   @0x20fa98 vmov.f32 s11, s14
 *   @0x20fa9c vcmpe.f32 s14, s15
 *   @0x20faa0 vmrs APSR_nzcv, fpscr
 *   @0x20faa4 ble 0x20fb5c <_Z14Color_RGBtoHSV4TRGB+0x114>
 *   @0x20faa8 vcmpe.f32 s14, s12
 *   @0x20faac vmrs APSR_nzcv, fpscr
 *   @0x20fab0 ble 0x20fb88 <_Z14Color_RGBtoHSV4TRGB+0x140>
 *   @0x20fab4 vmov.f32 s13, s14
 *   @0x20fab8 vcmp.f32 s13, #0
 *   @0x20fabc vmrs APSR_nzcv, fpscr
 *   @0x20fac0 beq 0x20fb98 <_Z14Color_RGBtoHSV4TRGB+0x150>
 *   @0x20fac4 vsub.f32 s11, s13, s11
 *   @0x20fac8 vdiv.f32 s10, s11, s13
 *   @0x20facc vcmp.f32 s10, #0
 *   @0x20fad0 vmrs APSR_nzcv, fpscr
 *   @0x20fad4 beq 0x20fc7c <_Z14Color_RGBtoHSV4TRGB+0x234>
 *   @0x20fad8 vcmp.f32 s13, s14
 *   @0x20fadc vmrs APSR_nzcv, fpscr
 *   @0x20fae0 bne 0x20fbfc <_Z14Color_RGBtoHSV4TRGB+0x1b4>
 *   @0x20fae4 vsub.f32 s15, s15, s12
 *   @0x20fae8 vldr s9, [pc, #424]
 *   @0x20faec vmul.f32 s15, s15, s9
 *   @0x20faf0 vdiv.f32 s11, s15, s11
 *   @0x20faf4 vcmpe.f32 s11, #0
 *   @0x20faf8 vmrs APSR_nzcv, fpscr
 *   @0x20fafc bpl 0x20fc2c <_Z14Color_RGBtoHSV4TRGB+0x1e4>
 *   @0x20fb00 vldr s9, [pc, #404]
 *   @0x20fb04 vadd.f32 s11, s11, s9
 *   @0x20fb08 vldr s14, [pc, #388]
 *   @0x20fb0c vmul.f32 s15, s11, s14
 *   @0x20fb10 vdiv.f32 s9, s15, s9
 *   @0x20fb14 vmov.f32 s15, #5.000000e-01
 *   @0x20fb18 vmov.f32 s11, s15
 *   @0x20fb1c vmla.f32 s11, s10, s14
 *   @0x20fb20 vadd.f32 s15, s9, s15
 *   @0x20fb24 vcvt.s32.f32 s14, s11
 *   @0x20fb28 vcvt.s32.f32 s15, s15
 *   @0x20fb2c vmov r2, s14
 *   @0x20fb30 vmov r3, s15
 *   @0x20fb34 b 0x20fba0 <_Z14Color_RGBtoHSV4TRGB+0x158>
 *   @0x20fb38 vcmpe.f32 s15, s12
 *   @0x20fb3c vmrs APSR_nzcv, fpscr
 *   @0x20fb40 bpl 0x20fb80 <_Z14Color_RGBtoHSV4TRGB+0x138>
 *   @0x20fb44 vcmpe.f32 s14, s15
 *   @0x20fb48 vmrs APSR_nzcv, fpscr
 *   @0x20fb4c vmovpl.f32 s11, s15
 *   @0x20fb50 bpl 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54>
 *   @0x20fb54 vmov.f32 s11, s14
 *   @0x20fb58 b 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54>
 *   @0x20fb5c vcmpe.f32 s15, s12
 *   @0x20fb60 vmrs APSR_nzcv, fpscr
 *   @0x20fb64 ble 0x20fb88 <_Z14Color_RGBtoHSV4TRGB+0x140>
 *   @0x20fb68 vcmpe.f32 s14, s15
 *   @0x20fb6c vmrs APSR_nzcv, fpscr
 *   @0x20fb70 vmovle.f32 s13, s15
 *   @0x20fb74 ble 0x20fab8 <_Z14Color_RGBtoHSV4TRGB+0x70>
 *   @0x20fb78 vmov.f32 s13, s14
 *   @0x20fb7c b 0x20fab8 <_Z14Color_RGBtoHSV4TRGB+0x70>
 *   @0x20fb80 vmov.f32 s11, s12
 *   @0x20fb84 b 0x20fa9c <_Z14Color_RGBtoHSV4TRGB+0x54>
 *   @0x20fb88 vmov.f32 s13, s12
 *   @0x20fb8c vcmp.f32 s13, #0
 *   @0x20fb90 vmrs APSR_nzcv, fpscr
 *   @0x20fb94 bne 0x20fac4 <_Z14Color_RGBtoHSV4TRGB+0x7c>
 *   @0x20fb98 mov r2, #0
 *   @0x20fb9c mov r3, #0
 *   @0x20fba0 vmov.f32 s15, #5.000000e-01
 *   @0x20fba4 vldr s14, [pc, #232]
 *   @0x20fba8 mov r0, #0
 *   @0x20fbac vmla.f32 s15, s13, s14
 *   @0x20fbb0 vcvt.s32.f32 s15, s15
 *   @0x20fbb4 vmov r1, s15
 *   @0x20fbb8 cmp r1, #254
 *   @0x20fbbc bicle r1, r1, r1, asr #31
 *   @0x20fbc0 movgt r1, #255
 *   @0x20fbc4 uxtble r1, r1
 *   @0x20fbc8 cmp r2, #254
 *   @0x20fbcc bicle r2, r2, r2, asr #31
 *   @0x20fbd0 movgt r2, #255
 *   @0x20fbd4 uxtble r2, r2
 *   @0x20fbd8 cmp r3, #254
 *   @0x20fbdc bicle r3, r3, r3, asr #31
 *   @0x20fbe0 movgt r3, #255
 *   @0x20fbe4 uxtble r3, r3
 *   @0x20fbe8 bfi r0, r3, #0, #8
 *   @0x20fbec bfi r0, r2, #8, #8
 *   @0x20fbf0 bfi r0, r1, #16, #8
 *   @0x20fbf4 add sp, sp, #16
 *   @0x20fbf8 bx lr
 *   @0x20fbfc vcmp.f32 s13, s15
 *   @0x20fc00 vmrs APSR_nzcv, fpscr
 *   @0x20fc04 bne 0x20fc60 <_Z14Color_RGBtoHSV4TRGB+0x218>
 *   @0x20fc08 vsub.f32 s14, s12, s14
 *   @0x20fc0c vldr s8, [pc, #132]
 *   @0x20fc10 vldr s9, [pc, #136]
 *   @0x20fc14 vmul.f32 s14, s14, s8
 *   @0x20fc18 vdiv.f32 s11, s14, s11
 *   @0x20fc1c vadd.f32 s11, s11, s9
 *   @0x20fc20 vcmpe.f32 s11, #0
 *   @0x20fc24 vmrs APSR_nzcv, fpscr
 *   @0x20fc28 bmi 0x20fb00 <_Z14Color_RGBtoHSV4TRGB+0xb8>
 *   @0x20fc2c vldr s14, [pc, #96]
 *   @0x20fc30 vmul.f32 s11, s11, s14
 *   @0x20fc34 vldr s15, [pc, #96]
 *   @0x20fc38 vdiv.f32 s11, s11, s15
 *   @0x20fc3c vmov.f32 s15, #5.000000e-01
 *   @0x20fc40 vmov.f32 s12, s15
 *   @0x20fc44 vmla.f32 s12, s10, s14
 *   @0x20fc48 vadd.f32 s15, s11, s15
 *   @0x20fc4c vcvt.s32.f32 s14, s12
 *   @0x20fc50 vcvt.s32.f32 s15, s15
 *   @0x20fc54 vmov r2, s14
 *   @0x20fc58 vmov r3, s15
 *   @0x20fc5c b 0x20fba0 <_Z14Color_RGBtoHSV4TRGB+0x158>
 *   @0x20fc60 vsub.f32 s15, s14, s15
 *   @0x20fc64 vldr s9, [pc, #44]
 *   @0x20fc68 vldr s12, [pc, #52]
 *   @0x20fc6c vmul.f32 s15, s15, s9
 *   @0x20fc70 vdiv.f32 s11, s15, s11
 *   @0x20fc74 vadd.f32 s11, s11, s12
 *   @0x20fc78 b 0x20faf4 <_Z14Color_RGBtoHSV4TRGB+0xac>
 *   @0x20fc7c vmov.f32 s15, #5.000000e-01
 *   @0x20fc80 vldr s14, [pc, #12]
 *   @0x20fc84 vmla.f32 s15, s10, s14
 *   @0x20fc88 vcvt.s32.f32 s15, s15
 *   @0x20fc8c vmov r2, s15
 *   @0x20fc90 b 0x20fb9c <_Z14Color_RGBtoHSV4TRGB+0x154>
 *   @0x20fc94 cmnmi pc, #0
 *   @0x20fc98 rsbsmi r0, r0, #0
 *   @0x20fc9c .word 0x43b40000
 *   @0x20fca0 rscsmi r0, r0, #0
 *   @0x20fca4 cmnmi r0, #0
 *
 * ══ §28/50 ASYNC_SAVE_LOAD_REQ_CONTEXT::Process(HTTP_REQ_CONTEXT*)  0xc4e54  size 604  151 条（0xc4e54..0xc50b0）
 * @func 0xc4e54 0xc50b0  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65a4×4 / 0xb6538×4 / LoadSave::ReadBundleFile(char const*, int*)×2 / 0xb6628×2 / LoadSave::SaveFileExists(char const*)×2 / IBuffer::CopyMemoryToBuffer(IBuffer*, unsigned char*, int, int, int, int, bool, bool, bool) / MemoryManager::Free(void const*) / LoadSave::ReadSaveFile(char const*, int*)
 * 字段偏移 top8: 0xc×5 / 0x8×4 / 0x1c×3 / 0x10×3 / 0xc2c×2 / 0x48×2 / 0x44×2 / 0x18×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc4e54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xc4e58 sub sp, sp, #3120
 *   @0xc4e5c ldr r10, [pc, #0x240]
 *   @0xc4e60 sub sp, sp, #4
 *   @0xc4e64 ldr r3, [r0, #0xc]
 *   @0xc4e68 mov r9, r0
 *   @0xc4e6c ldr r10, [pc, r10]
 *   @0xc4e70 cmp r3, #7
 *   @0xc4e74 ldr r3, [r10]
 *   @0xc4e78 str r3, [sp, #0xc2c]
 *   @0xc4e7c beq 0xc4fb8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x164>
 *   @0xc4e80 ldrb r7, [r0, #0x4c]
 *   @0xc4e84 cmp r7, #0
 *   @0xc4e88 bne 0xc4fd4 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x180>
 *   @0xc4e8c add r6, sp, #44
 *   @0xc4e90 ldr r1, [r0, #0x48]
 *   @0xc4e94 mov r0, r6
 *   @0xc4e98 bl 0xb65a4 <strcpy@plt>
 *   @0xc4e9c mov r0, r6
 *   @0xc4ea0 bl 0xb6538 <strlen@plt>
 *   @0xc4ea4 ldr r4, [r9, #0x44]
 *   @0xc4ea8 cmp r4, #0
 *   @0xc4eac beq 0xc4fb0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x15c>
 *   @0xc4eb0 ldr r2, [pc, #0x1f0]
 *   @0xc4eb4 add r5, sp, #1072
 *   @0xc4eb8 add r12, sp, #40
 *   @0xc4ebc sub r5, r5, #4
 *   @0xc4ec0 add r2, pc, r2
 *   @0xc4ec4 add r3, r0, #1
 *   @0xc4ec8 add r3, r5, r3
 *   @0xc4ecc str r9, [sp, #0x1c]
 *   @0xc4ed0 str r2, [sp, #0x20]
 *   @0xc4ed4 add r8, r5, r0
 *   @0xc4ed8 str r3, [sp, #0x18]
 *   @0xc4edc mov r9, r12
 *   @0xc4ee0 str r10, [sp, #0x24]
 *   @0xc4ee4 mov r11, r2
 *   @0xc4ee8 b 0xc4f40 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xec>
 *   @0xc4eec bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xc4ef0 subs r10, r0, #0
 *   @0xc4ef4 beq 0xc5070 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x21c>
 *   @0xc4ef8 ldr lr, [r4, #0x10]
 *   @0xc4efc mov r12, #1
 *   @0xc4f00 ldr r0, [r4, #0x4]
 *   @0xc4f04 mov r1, r10
 *   @0xc4f08 mov r3, #0
 *   @0xc4f0c ldr r2, [sp, #0x28]
 *   @0xc4f10 str lr, [sp]
 *   @0xc4f14 ldr lr, [r4, #0x14]
 *   @0xc4f18 str r12, [sp, #0x8]
 *   @0xc4f1c str r7, [sp, #0xc]
 *   @0xc4f20 str lr, [sp, #0x4]
 *   @0xc4f24 str r7, [sp, #0x10]
 *   @0xc4f28 bl 0xccabc <_ZN7IBuffer18CopyMemoryToBufferEPS_Phiiiibbb>
 *   @0xc4f2c mov r0, r10
 *   @0xc4f30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc4f34 ldr r4, [r4]
 *   @0xc4f38 cmp r4, #0
 *   @0xc4f3c beq 0xc4fa8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x154>
 *   @0xc4f40 mov r1, r6
 *   @0xc4f44 mov r0, r5
 *   @0xc4f48 bl 0xb65a4 <strcpy@plt>
 *   @0xc4f4c mov r0, r8
 *   @0xc4f50 bl 0xb6538 <strlen@plt>
 *   @0xc4f54 ldrh r3, [r11]
 *   @0xc4f58 strh r3, [r8, r0]
 *   @0xc4f5c ldr r0, [sp, #0x18]
 *   @0xc4f60 ldr r1, [r4, #0x8]
 *   @0xc4f64 bl 0xb6628 <strcat@plt>
 *   @0xc4f68 mov r0, r5
 *   @0xc4f6c str r7, [sp, #0x28]
 *   @0xc4f70 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc4f74 mov r1, r9
 *   @0xc4f78 cmp r0, #0
 *   @0xc4f7c mov r0, r5
 *   @0xc4f80 beq 0xc4eec <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x98>
 *   @0xc4f84 bl 0x18fb08 <_ZN8LoadSave12ReadSaveFileEPKcPi>
 *   @0xc4f88 mov r10, r0
 *   @0xc4f8c cmp r10, #0
 *   @0xc4f90 bne 0xc4ef8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xa4>
 *   @0xc4f94 ldr r4, [r4]
 *   @0xc4f98 ldr r12, [sp, #0x1c]
 *   @0xc4f9c cmp r4, #0
 *   @0xc4fa0 str r10, [r12, #0x50]
 *   @0xc4fa4 bne 0xc4f40 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0xec>
 *   @0xc4fa8 ldr r9, [sp, #0x1c]
 *   @0xc4fac ldr r10, [sp, #0x24]
 *   @0xc4fb0 mov r3, #7
 *   @0xc4fb4 str r3, [r9, #0xc]
 *   @0xc4fb8 ldr r2, [sp, #0xc2c]
 *   @0xc4fbc ldr r3, [r10]
 *   @0xc4fc0 cmp r2, r3
 *   @0xc4fc4 bne 0xc50a0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x24c>
 *   @0xc4fc8 add sp, sp, #3120
 *   @0xc4fcc add sp, sp, #4
 *   @0xc4fd0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xc4fd4 add r6, sp, #44
 *   @0xc4fd8 ldr r2, [r0, #0x48]
 *   @0xc4fdc mov r1, #1024
 *   @0xc4fe0 mov r0, r6
 *   @0xc4fe4 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0xc4fe8 mov r0, r6
 *   @0xc4fec bl 0xb6538 <strlen@plt>
 *   @0xc4ff0 ldr r4, [r9, #0x44]
 *   @0xc4ff4 cmp r4, #0
 *   @0xc4ff8 beq 0xc4fb0 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x15c>
 *   @0xc4ffc add r5, sp, #1072
 *   @0xc5000 ldr r11, [pc, #0xa4]
 *   @0xc5004 sub r5, r5, #4
 *   @0xc5008 add r8, r0, #1
 *   @0xc500c add r11, pc, r11
 *   @0xc5010 add r7, r5, r0
 *   @0xc5014 add r8, r5, r8
 *   @0xc5018 mov r1, r6
 *   @0xc501c mov r0, r5
 *   @0xc5020 bl 0xb65a4 <strcpy@plt>
 *   @0xc5024 mov r0, r7
 *   @0xc5028 bl 0xb6538 <strlen@plt>
 *   @0xc502c ldrh r3, [r11]
 *   @0xc5030 strh r3, [r7, r0]
 *   @0xc5034 mov r0, r8
 *   @0xc5038 ldr r1, [r4, #0x8]
 *   @0xc503c bl 0xb6628 <strcat@plt>
 *   @0xc5040 ldr r1, [r4, #0xc]
 *   @0xc5044 ldr r2, [r4, #0x10]
 *   @0xc5048 mov r0, r5
 *   @0xc504c bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i>
 *   @0xc5050 ldr r4, [r4]
 *   @0xc5054 cmp r0, #0
 *   @0xc5058 streq r0, [r9, #0x50]
 *   @0xc505c cmp r4, #0
 *   @0xc5060 bne 0xc5018 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x1c4>
 *   @0xc5064 mov r3, #7
 *   @0xc5068 str r3, [r9, #0xc]
 *   @0xc506c b 0xc4fb8 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x164>
 *   @0xc5070 ldr r1, [r4, #0x8]
 *   @0xc5074 mov r0, r5
 *   @0xc5078 bl 0xb65a4 <strcpy@plt>
 *   @0xc507c mov r0, r5
 *   @0xc5080 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0xc5084 mov r1, r9
 *   @0xc5088 cmp r0, #0
 *   @0xc508c mov r0, r5
 *   @0xc5090 bne 0xc4f84 <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x130>
 *   @0xc5094 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0xc5098 mov r10, r0
 *   @0xc509c b 0xc4f8c <_ZN27ASYNC_SAVE_LOAD_REQ_CONTEXT7ProcessEP16HTTP_REQ_CONTEXT+0x138>
 *   @0xc50a0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xc50a4 eorseq r8, r2, r4, ror #21
 *   @0xc50a8 eoreq r11, r6, r12, asr #25
 *   @0xc50ac eoreq r11, r6, r0, lsl #23
 *
 * ══ §29/50 F_BUFFER_Async_Group_Option(RValue&, CInstance*, CInstance*, int, RValue*)  0xc5ef8  size 604  151 条（0xc5ef8..0xc6154）
 * @func 0xc5ef8 0xc6154  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xc5f5c→0x47a128, 0xc5f9c→0x47a12c, 0xc601c→0x3eb70c, 0xc604c→0x3f2010, 0xc6088→0x47a124, 0xc60b4→0x5356b8, 0xc60e4→0x3f200c, 0xc6100→0x3f2008
 * 调用序列: 0xb6574×7 / YYGetString(RValue const*, int)×3 / YYGetInt32(RValue const*, int)×3 / YYFree(void const*) / YYStrDup(char const*) / YYGetBool(RValue const*, int) / operator new(unsigned int) / 0xb6640
 * 字段偏移 top8: 0x4×3 / 0xc×2 / 0x18×1 / 0x1e8×1 / 0x1dc×1 / 0x1cc×1 / 0x1b8×1 / 0x17c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc5ef8 push {r3, r4, r5, r6, r7, lr}
 *   @0xc5efc mov r3, #0
 *   @0xc5f00 ldr r6, [sp, #0x18]
 *   @0xc5f04 mov r4, r0
 *   @0xc5f08 str r3, [r0]
 *   @0xc5f0c mov r1, r3
 *   @0xc5f10 str r3, [r0, #0x4]
 *   @0xc5f14 str r3, [r0, #0xc]
 *   @0xc5f18 mov r0, r6
 *   @0xc5f1c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5f20 ldr r5, [pc, #0x1e8]
 *   @0xc5f24 add r5, pc, r5
 *   @0xc5f28 subs r7, r0, #0
 *   @0xc5f2c popeq {r3, r4, r5, r6, r7, pc}
 *   @0xc5f30 ldr r1, [pc, #0x1dc]
 *   @0xc5f34 add r1, pc, r1
 *   @0xc5f38 bl 0xb6574 <strcmp@plt>
 *   @0xc5f3c cmp r0, #0
 *   @0xc5f40 beq 0xc5f9c <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0xa4>
 *   @0xc5f44 ldr r1, [pc, #0x1cc]
 *   @0xc5f48 mov r0, r7
 *   @0xc5f4c add r1, pc, r1
 *   @0xc5f50 bl 0xb6574 <strcmp@plt>
 *   @0xc5f54 cmp r0, #0
 *   @0xc5f58 bne 0xc5fa4 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0xac>
 *   @0xc5f5c ldr r2, [pc, #0x1b8]
 *   @0xc5f60 str r0, [r4]
 *   @0xc5f64 mov r3, #0
 *   @0xc5f68 movt r3, #0x3ff0
 *   @0xc5f6c str r3, [r4, #0x4]
 *   @0xc5f70 ldr r4, [r5, r2]
 *   @0xc5f74 ldr r0, [r4]
 *   @0xc5f78 cmp r0, #0
 *   @0xc5f7c beq 0xc5f84 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x8c>
 *   @0xc5f80 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xc5f84 mov r1, #1
 *   @0xc5f88 mov r0, r6
 *   @0xc5f8c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc5f90 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0xc5f94 str r0, [r4]
 *   @0xc5f98 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc5f9c ldr r2, [pc, #0x17c]
 *   @0xc5fa0 b 0xc5f60 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x68>
 *   @0xc5fa4 ldr r1, [pc, #0x178]
 *   @0xc5fa8 mov r0, r7
 *   @0xc5fac add r1, pc, r1
 *   @0xc5fb0 bl 0xb6574 <strcmp@plt>
 *   @0xc5fb4 subs r1, r0, #0
 *   @0xc5fb8 beq 0xc6044 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x14c>
 *   @0xc5fbc ldr r1, [pc, #0x164]
 *   @0xc5fc0 mov r0, r7
 *   @0xc5fc4 add r1, pc, r1
 *   @0xc5fc8 bl 0xb6574 <strcmp@plt>
 *   @0xc5fcc cmp r0, #0
 *   @0xc5fd0 beq 0xc6098 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1a0>
 *   @0xc5fd4 ldr r1, [pc, #0x150]
 *   @0xc5fd8 mov r0, r7
 *   @0xc5fdc add r1, pc, r1
 *   @0xc5fe0 bl 0xb6574 <strcmp@plt>
 *   @0xc5fe4 cmp r0, #0
 *   @0xc5fe8 beq 0xc60d8 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1e0>
 *   @0xc5fec ldr r1, [pc, #0x13c]
 *   @0xc5ff0 mov r0, r7
 *   @0xc5ff4 add r1, pc, r1
 *   @0xc5ff8 bl 0xb6574 <strcmp@plt>
 *   @0xc5ffc cmp r0, #0
 *   @0xc6000 beq 0xc60f4 <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0xc6004 ldr r1, [pc, #0x128]
 *   @0xc6008 mov r0, r7
 *   @0xc600c add r1, pc, r1
 *   @0xc6010 bl 0xb6574 <strcmp@plt>
 *   @0xc6014 cmp r0, #0
 *   @0xc6018 beq 0xc607c <_Z27F_BUFFER_Async_Group_OptionR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0xc601c ldr r3, [pc, #0x114]
 *   @0xc6020 mov r2, r7
 *   @0xc6024 ldr r1, [pc, #0x110]
 *   @0xc6028 ldr r3, [r5, r3]
 *   @0xc602c add r1, pc, r1
 *   @0xc6030 ldr r0, [r3]
 *   @0xc6034 ldr r3, [r0]
 *   @0xc6038 ldr r3, [r3, #0xc]
 *   @0xc603c blx r3
 *   @0xc6040 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc6044 add r0, r6, #16
 *   @0xc6048 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0xc604c ldr r3, [pc, #0xec]
 *   @0xc6050 cmp r0, #0
 *   @0xc6054 ldrne r3, [r5, r3]
 *   @0xc6058 movne r2, #1
 *   @0xc605c ldreq r3, [r5, r3]
 *   @0xc6060 strbne r2, [r3]
 *   @0xc6064 strbeq r0, [r3]
 *   @0xc6068 mov r3, #0
 *   @0xc606c mov r2, r3
 *   @0xc6070 movt r3, #0x3ff0
 *   @0xc6074 stm r4, {r2, r3}
 *   @0xc6078 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc607c mov r0, r6
 *   @0xc6080 mov r1, #1
 *   @0xc6084 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6088 ldr r3, [pc, #0xb4]
 *   @0xc608c ldr r3, [r5, r3]
 *   @0xc6090 str r0, [r3]
 *   @0xc6094 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc6098 mov r0, #12
 *   @0xc609c bl 0x27c524 <_Znwj>
 *   @0xc60a0 mov r1, #1
 *   @0xc60a4 mov r4, r0
 *   @0xc60a8 mov r0, r6
 *   @0xc60ac bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0xc60b0 bl 0xb6640 <strdup@plt>
 *   @0xc60b4 ldr r3, [pc, #0x8c]
 *   @0xc60b8 mov r2, #1
 *   @0xc60bc strb r2, [r4, #0x8]
 *   @0xc60c0 str r0, [r4, #0x4]
 *   @0xc60c4 ldr r3, [r5, r3]
 *   @0xc60c8 ldr r2, [r3]
 *   @0xc60cc str r2, [r4]
 *   @0xc60d0 str r4, [r3]
 *   @0xc60d4 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc60d8 mov r0, r6
 *   @0xc60dc mov r1, #1
 *   @0xc60e0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc60e4 ldr r3, [pc, #0x60]
 *   @0xc60e8 ldr r3, [r5, r3]
 *   @0xc60ec str r0, [r3]
 *   @0xc60f0 pop {r3, r4, r5, r6, r7, pc}
 *   @0xc60f4 mov r0, r6
 *   @0xc60f8 mov r1, #1
 *   @0xc60fc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0xc6100 ldr r3, [pc, #0x48]
 *   @0xc6104 ldr r3, [r5, r3]
 *   @0xc6108 str r0, [r3]
 *   @0xc610c pop {r3, r4, r5, r6, r7, pc}
 *   @0xc6110 eorseq r11, r2, r12, lsr #26
 *   @0xc6114 eoreq r10, r6, r0, lsl #27
 *   @0xc6118 eoreq r10, r6, r4, ror sp
 *   @0xc611c .word 0xffffbd6c
 *   @0xc6120 .word 0xffffbd70
 *   @0xc6124 eoreq r10, r6, r0, lsr #26
 *   @0xc6128 eoreq r10, r6, r4, lsl sp
 *   @0xc612c eoreq r10, r6, r8, lsl #26
 *   @0xc6130 eoreq r10, r6, r0, lsl #26
 *   @0xc6134 .word 0x0026acf8
 *   @0xc6138 .word 0xffffbac4
 *   @0xc613c eoreq r10, r6, r12, ror #25
 *   @0xc6140 .word 0xffffbd74
 *   @0xc6144 .word 0xffffbd78
 *   @0xc6148 .word 0xffffbd7c
 *   @0xc614c .word 0xffffbd80
 *   @0xc6150 .word 0xffffbd84
 *
 * ══ §30/50 F_GPUSetState(RValue&, CInstance*, CInstance*, int, RValue*)  0x1462d4  size 604  151 条（0x1462d4..0x146530）
 * @func 0x1462d4 0x146530  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×3 / Error_Show_Action(char const*, bool)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / YYGetFloat(RValue const*, int)×2 / DS_AutoMutex::DS_AutoMutex() / GetDsMap(int) / CDS_Map::FindFirst() / 0xb6574
 * 字段偏移 top8: 0x4×7 / 0xc×5 / 0x8×5 / 0x10×3 / 0x2c×2 / 0x3c×2 / 0x234×1 / 0x210×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1462d4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1462d8 cmp r3, #1
 *   @0x1462dc ldr r8, [pc, #0x234]
 *   @0x1462e0 mov r3, #0
 *   @0x1462e4 mov r4, r3
 *   @0x1462e8 sub sp, sp, #68
 *   @0x1462ec movt r3, #0xbff0
 *   @0x1462f0 str r4, [r0, #0xc]
 *   @0x1462f4 str r3, [r0, #0x4]
 *   @0x1462f8 add r8, pc, r8
 *   @0x1462fc str r4, [r0]
 *   @0x146300 beq 0x14631c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x146304 ldr r0, [pc, #0x210]
 *   @0x146308 mov r1, r4
 *   @0x14630c add r0, pc, r0
 *   @0x146310 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x146314 add sp, sp, #68
 *   @0x146318 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14631c add r1, sp, #28
 *   @0x146320 str r1, [sp, #0x14]
 *   @0x146324 mov r0, r1
 *   @0x146328 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x14632c mov r1, r4
 *   @0x146330 ldr r0, [sp, #0x68]
 *   @0x146334 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146338 bl 0x2052d4 <_Z8GetDsMapi>
 *   @0x14633c subs r2, r0, #0
 *   @0x146340 str r2, [sp, #0x10]
 *   @0x146344 beq 0x1464fc <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x228>
 *   @0x146348 bl 0x203c8c <_ZN7CDS_Map9FindFirstEv>
 *   @0x14634c subs r3, r0, #0
 *   @0x146350 beq 0x146440 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x146354 ldr r2, [pc, #0x1c4]
 *   @0x146358 add r1, sp, #48
 *   @0x14635c str r1, [sp, #0x8]
 *   @0x146360 add r7, sp, #32
 *   @0x146364 ldr r2, [r8, r2]
 *   @0x146368 add r5, r2, #216
 *   @0x14636c str r2, [sp, #0xc]
 *   @0x146370 ldr r0, [r3]
 *   @0x146374 mov r4, r3
 *   @0x146378 ldr r1, [r3, #0x4]
 *   @0x14637c mov lr, r7
 *   @0x146380 ldr r2, [r3, #0x8]
 *   @0x146384 add r12, sp, #48
 *   @0x146388 ldr r3, [r3, #0xc]
 *   @0x14638c stm lr!, {r0, r1, r2, r3}
 *   @0x146390 ldr r0, [r4, #0x10]!
 *   @0x146394 ldr lr, [sp, #0x2c]
 *   @0x146398 ldr r3, [r4, #0xc]
 *   @0x14639c bic lr, lr, #-16777216
 *   @0x1463a0 ldr r1, [r4, #0x4]
 *   @0x1463a4 cmp lr, #1
 *   @0x1463a8 ldr r2, [r4, #0x8]
 *   @0x1463ac str lr, [sp, #0x2c]
 *   @0x1463b0 movne r6, #0
 *   @0x1463b4 stm r12!, {r0, r1, r2, r3}
 *   @0x1463b8 ldr r3, [sp, #0x3c]
 *   @0x1463bc bic r3, r3, #-16777216
 *   @0x1463c0 str r3, [sp, #0x3c]
 *   @0x1463c4 beq 0x146480 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1ac>
 *   @0x1463c8 ldr r4, [sp, #0xc]
 *   @0x1463cc mov r0, r6
 *   @0x1463d0 ldr r1, [r4]
 *   @0x1463d4 bl 0xb6574 <strcmp@plt>
 *   @0x1463d8 cmp r0, #0
 *   @0x1463dc beq 0x146450 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x17c>
 *   @0x1463e0 add r4, r4, #12
 *   @0x1463e4 cmp r4, r5
 *   @0x1463e8 bne 0x1463cc <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x1463ec ldr r3, [pc, #0x130]
 *   @0x1463f0 ldr r10, [r8, r3]
 *   @0x1463f4 add r4, r10, #120
 *   @0x1463f8 ldr r9, [r10]
 *   @0x1463fc mov r0, r9
 *   @0x146400 bl 0xb6538 <strlen@plt>
 *   @0x146404 mov r1, r9
 *   @0x146408 mov r11, r0
 *   @0x14640c mov r0, r6
 *   @0x146410 mov r2, r11
 *   @0x146414 bl 0xb65e0 <strncmp@plt>
 *   @0x146418 cmp r0, #0
 *   @0x14641c beq 0x1464a0 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1cc>
 *   @0x146420 add r10, r10, #12
 *   @0x146424 cmp r10, r4
 *   @0x146428 bne 0x1463f8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x124>
 *   @0x14642c ldr r0, [sp, #0x10]
 *   @0x146430 mov r1, r7
 *   @0x146434 bl 0x203b94 <_ZN7CDS_Map8FindNextEP6RValue>
 *   @0x146438 subs r3, r0, #0
 *   @0x14643c bne 0x146370 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x9c>
 *   @0x146440 add r0, sp, #28
 *   @0x146444 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x146448 add sp, sp, #68
 *   @0x14644c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x146450 ldrb r1, [r4, #0x8]
 *   @0x146454 cmp r1, #0
 *   @0x146458 beq 0x146490 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1bc>
 *   @0x14645c mov r1, r0
 *   @0x146460 add r0, sp, #48
 *   @0x146464 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x146468 mov r2, r0
 *   @0x14646c ldr r3, [pc, #0xb4]
 *   @0x146470 ldr r1, [r4, #0x4]
 *   @0x146474 ldr r0, [r8, r3]
 *   @0x146478 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x14647c b 0x14642c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x146480 ldr r6, [sp, #0x20]
 *   @0x146484 cmp r6, #0
 *   @0x146488 ldrne r6, [r6]
 *   @0x14648c b 0x1463c8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x146490 add r0, sp, #48
 *   @0x146494 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x146498 mov r2, r0
 *   @0x14649c b 0x14646c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x1464a0 mov r2, r0
 *   @0x1464a4 add r0, r6, r11
 *   @0x1464a8 str r2, [sp, #0x4]
 *   @0x1464ac bl 0xb66b8 <atoi@plt>
 *   @0x1464b0 ldrb r1, [r10, #0x8]
 *   @0x1464b4 ldr r2, [sp, #0x4]
 *   @0x1464b8 cmp r1, #0
 *   @0x1464bc mov r4, r0
 *   @0x1464c0 bne 0x1464e8 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x1464c4 add r0, sp, #48
 *   @0x1464c8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1464cc mov r3, r0
 *   @0x1464d0 ldr lr, [pc, #0x50]
 *   @0x1464d4 mov r1, r4
 *   @0x1464d8 ldr r2, [r10, #0x4]
 *   @0x1464dc ldr r0, [r8, lr]
 *   @0x1464e0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej>
 *   @0x1464e4 b 0x14642c <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x1464e8 mov r1, r2
 *   @0x1464ec add r0, sp, #48
 *   @0x1464f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1464f4 mov r3, r0
 *   @0x1464f8 b 0x1464d0 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x1fc>
 *   @0x1464fc ldr r0, [pc, #0x28]
 *   @0x146500 mov r1, r2
 *   @0x146504 add r0, pc, r0
 *   @0x146508 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14650c add r0, sp, #28
 *   @0x146510 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x146514 b 0x146314 <_Z13F_GPUSetStateR6RValueP9CInstanceS2_iPS_+0x40>
 *   @0x146518 eoreq r11, r10, r8, asr r9
 *   @0x14651c ldrsheq r11, [pc], -r0
 *   @0x146520 .word 0xffffd9c4
 *   @0x146524 .word 0xffffd9c8
 *   @0x146528 .word 0xffffc0a8
 *   @0x14652c andseq r11, pc, r12, lsr r1
 *
 * ══ §31/50 _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool)  0x16af3c  size 604  151 条（0x16af3c..0x16b198）
 * @func 0x16af3c 0x16b198  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16af70→0x4859c0, 0x16afa0→0x4899a8, 0x16afd4→0x4859ac, 0x16afdc→0x4898a4, 0x16afe0→0x4897a0, 0x16b044→0x4899a8, 0x16b078→0x4898a4, 0x16b080→0x4897a0
 * 调用序列: Graphics::AllocVerts(ePrimType, void*, int, int)×2 / _Draw_Ellipse(float, float, float, float, unsigned int, unsigned int, bool)+0xfc×2
 * 字段偏移 top8: 0x30×4 / 0x1ac×2 / 0x4×2 / 0x8×2 / 0xc×2 / 0x224×1 / 0x50×1 / 0x4c×1
 * VFP 指令 48 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16af3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x16af40 vpush {d8, d9}
 *   @0x16af44 vmov s14, r3
 *   @0x16af48 vmov s16, r0
 *   @0x16af4c sub sp, sp, #20
 *   @0x16af50 vmov s13, r2
 *   @0x16af54 ldr r9, [pc, #0x224]
 *   @0x16af58 vmov s17, r1
 *   @0x16af5c ldrb r10, [sp, #0x50]
 *   @0x16af60 vmov.f32 s15, #5.000000e-01
 *   @0x16af64 add r9, pc, r9
 *   @0x16af68 cmp r10, #0
 *   @0x16af6c ldr r4, [sp, #0x4c]
 *   @0x16af70 ldr r3, [pc, #0x20c]
 *   @0x16af74 vsub.f32 s18, s16, s13
 *   @0x16af78 vsub.f32 s19, s17, s14
 *   @0x16af7c vmul.f32 s18, s18, s15
 *   @0x16af80 vmul.f32 s19, s19, s15
 *   @0x16af84 vadd.f32 s16, s16, s13
 *   @0x16af88 vadd.f32 s17, s17, s14
 *   @0x16af8c vabs.f32 s18, s18
 *   @0x16af90 vmul.f32 s16, s16, s15
 *   @0x16af94 vabs.f32 s19, s19
 *   @0x16af98 vmul.f32 s17, s17, s15
 *   @0x16af9c beq 0x16b044 <_Z13_Draw_Ellipseffffjjb+0x108>
 *   @0x16afa0 ldr r1, [pc, #0x1e0]
 *   @0x16afa4 mov r0, #3
 *   @0x16afa8 ldr r3, [r9, r3]
 *   @0x16afac mov r2, #16
 *   @0x16afb0 ldr r5, [r9, r1]
 *   @0x16afb4 ldr r1, [r3]
 *   @0x16afb8 ldr r3, [r5]
 *   @0x16afbc ldr r1, [r1]
 *   @0x16afc0 add r3, r3, #1
 *   @0x16afc4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16afc8 ldr r12, [r5]
 *   @0x16afcc cmp r12, #0
 *   @0x16afd0 blt 0x16b038 <_Z13_Draw_Ellipseffffjjb+0xfc>
 *   @0x16afd4 ldr r5, [pc, #0x1b0]
 *   @0x16afd8 add r3, r0, #8
 *   @0x16afdc ldr r1, [pc, #0x1ac]
 *   @0x16afe0 ldr r2, [pc, #0x1ac]
 *   @0x16afe4 ldr r5, [r9, r5]
 *   @0x16afe8 ldr r1, [r9, r1]
 *   @0x16afec ldr r0, [r9, r2]
 *   @0x16aff0 ldr r5, [r5]
 *   @0x16aff4 add r2, r1, #4
 *   @0x16aff8 add r12, r2, r12, lsl #2
 *   @0x16affc vmov.f32 s13, s16
 *   @0x16b000 vldr s15, [r1]
 *   @0x16b004 cmp r2, r12
 *   @0x16b008 mov r1, r2
 *   @0x16b00c add r3, r3, #16
 *   @0x16b010 add r2, r2, #4
 *   @0x16b014 vmla.f32 s13, s15, s18
 *   @0x16b018 vmov.f32 s14, s17
 *   @0x16b01c vstr s13, [r3, #-24]
 *   @0x16b020 vldmia r0!, {s15}
 *   @0x16b024 str r5, [r3, #-0x10]
 *   @0x16b028 str r4, [r3, #-0xc]
 *   @0x16b02c vmla.f32 s14, s15, s19
 *   @0x16b030 vstr s14, [r3, #-20]
 *   @0x16b034 bne 0x16affc <_Z13_Draw_Ellipseffffjjb+0xc0>
 *   @0x16b038 add sp, sp, #20
 *   @0x16b03c vpop {d8, d9}
 *   @0x16b040 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x16b044 ldr r1, [pc, #0x13c]
 *   @0x16b048 mov r0, #4
 *   @0x16b04c ldr r3, [r9, r3]
 *   @0x16b050 mov r2, #16
 *   @0x16b054 ldr r5, [r9, r1]
 *   @0x16b058 ldr r1, [r3]
 *   @0x16b05c ldr r3, [r5]
 *   @0x16b060 ldr r1, [r1]
 *   @0x16b064 add r3, r3, r3, lsl #1
 *   @0x16b068 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x16b06c ldr r3, [r5]
 *   @0x16b070 cmp r3, #0
 *   @0x16b074 ble 0x16b038 <_Z13_Draw_Ellipseffffjjb+0xfc>
 *   @0x16b078 ldr r12, [pc, #0x110]
 *   @0x16b07c add r1, r3, r3, lsl #1
 *   @0x16b080 ldr r3, [pc, #0x10c]
 *   @0x16b084 add r11, r0, #16
 *   @0x16b088 add r1, r0, r1, lsl #4
 *   @0x16b08c ldr r2, [pc, #0xf8]
 *   @0x16b090 ldr r12, [r9, r12]
 *   @0x16b094 add r1, r1, #48
 *   @0x16b098 str r1, [sp, #0x4]
 *   @0x16b09c add r8, r0, #32
 *   @0x16b0a0 add r7, r0, #36
 *   @0x16b0a4 add r6, r0, #40
 *   @0x16b0a8 str r12, [sp, #0x8]
 *   @0x16b0ac add r5, r0, #44
 *   @0x16b0b0 ldr r3, [r9, r3]
 *   @0x16b0b4 mov r1, r10
 *   @0x16b0b8 mov r12, r11
 *   @0x16b0bc str r3, [sp, #0xc]
 *   @0x16b0c0 add r3, r0, #48
 *   @0x16b0c4 ldr r2, [r9, r2]
 *   @0x16b0c8 vldr s15, [r2]
 *   @0x16b0cc str r0, [sp]
 *   @0x16b0d0 vmov.f32 s13, s16
 *   @0x16b0d4 ldr r0, [sp, #0x48]
 *   @0x16b0d8 ldr r2, [sp, #0x8]
 *   @0x16b0dc vstr s16, [r3, #-48]
 *   @0x16b0e0 vstr s17, [r3, #-44]
 *   @0x16b0e4 vstr s15, [r3, #-40]
 *   @0x16b0e8 str r0, [r3, #-0x24]
 *   @0x16b0ec add r10, r2, r1
 *   @0x16b0f0 vldr s14, [r10]
 *   @0x16b0f4 vmla.f32 s13, s18, s14
 *   @0x16b0f8 ldr r0, [sp]
 *   @0x16b0fc add r3, r3, #48
 *   @0x16b100 rsb r2, r0, r12
 *   @0x16b104 ldr r0, [sp, #0xc]
 *   @0x16b108 add r2, r2, r11
 *   @0x16b10c add r12, r12, #48
 *   @0x16b110 add r9, r0, r1
 *   @0x16b114 ldr r0, [sp, #0x4]
 *   @0x16b118 add r1, r1, #4
 *   @0x16b11c cmp r3, r0
 *   @0x16b120 vstr s13, [r2, #-16]
 *   @0x16b124 vmov.f32 s13, s17
 *   @0x16b128 vldr s14, [r9]
 *   @0x16b12c vstr s15, [r2, #-8]
 *   @0x16b130 str r4, [r2, #-0x4]
 *   @0x16b134 vmla.f32 s13, s19, s14
 *   @0x16b138 vstr s13, [r2, #-12]
 *   @0x16b13c vmov.f32 s13, s16
 *   @0x16b140 vldr s14, [r10, #4]
 *   @0x16b144 vmov r2, s15
 *   @0x16b148 vmla.f32 s13, s18, s14
 *   @0x16b14c vmov r0, s13
 *   @0x16b150 vmov.f32 s13, s17
 *   @0x16b154 str r0, [r8], #48
 *   @0x16b158 vldr s14, [r9, #4]
 *   @0x16b15c vmla.f32 s13, s19, s14
 *   @0x16b160 vmov r0, s13
 *   @0x16b164 str r0, [r7], #48
 *   @0x16b168 str r2, [r6], #48
 *   @0x16b16c str r4, [r5], #48
 *   @0x16b170 bne 0x16b0d0 <_Z13_Draw_Ellipseffffjjb+0x194>
 *   @0x16b174 add sp, sp, #20
 *   @0x16b178 vpop {d8, d9}
 *   @0x16b17c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x16b180 eoreq r6, r8, r12, ror #25
 *   @0x16b184 .word 0xffffe4e0
 *   @0x16b188 .word 0xffffe528
 *   @0x16b18c .word 0xffffbcd0
 *   @0x16b190 .word 0xffffe52c
 *   @0x16b194 .word 0xffffe530
 *
 * ══ §32/50 res2_inverse  0x22e814  size 604  151 条（0x22e814..0x22ea70）
 * @func 0x22e814 0x22ea70  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / res2_inverse+0xd0×2 / _vorbis_block_alloc / res2_inverse+0xdc / res2_inverse+0x204 / res2_inverse+0x1f4 / vorbis_book_decodevv_add / vorbis_book_decode
 * 字段偏移 top8: 0x60×5 / 0x30×5 / 0x18×5 / 0x14×4 / 0x1c×4 / 0x2×4 / 0x24×3 / 0x4×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22e814 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22e818 sub sp, sp, #60
 *   @0x22e81c mov r4, r0
 *   @0x22e820 mov r6, r3
 *   @0x22e824 ldr r0, [r0, #0x24]
 *   @0x22e828 mov r11, r1
 *   @0x22e82c ldr r3, [sp, #0x60]
 *   @0x22e830 ldr r10, [r1]
 *   @0x22e834 str r2, [sp, #0x24]
 *   @0x22e838 mul r0, r0, r3
 *   @0x22e83c ldr r2, [r1, #0x14]
 *   @0x22e840 ldr r3, [r10]
 *   @0x22e844 ldr r1, [r10, #0x4]
 *   @0x22e848 ldr r2, [r2]
 *   @0x22e84c ldr r5, [r10, #0x8]
 *   @0x22e850 asr r0, r0, #1
 *   @0x22e854 cmp r0, r1
 *   @0x22e858 rsble r0, r3, r0
 *   @0x22e85c rsbgt r0, r3, r1
 *   @0x22e860 str r2, [sp, #0x1c]
 *   @0x22e864 cmp r0, #0
 *   @0x22e868 ble 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22e86c mov r1, r5
 *   @0x22e870 bl 0x318d10 <__divsi3>
 *   @0x22e874 ldr lr, [sp, #0x1c]
 *   @0x22e878 mov r1, lr
 *   @0x22e87c mov r8, r0
 *   @0x22e880 add r0, r0, lr
 *   @0x22e884 sub r0, r0, #1
 *   @0x22e888 bl 0x318d10 <__divsi3>
 *   @0x22e88c lsl r1, r0, #2
 *   @0x22e890 mov r0, r4
 *   @0x22e894 bl 0x2270e4 <_vorbis_block_alloc>
 *   @0x22e898 ldr r1, [sp, #0x60]
 *   @0x22e89c mov r9, r0
 *   @0x22e8a0 ldr r0, [r10]
 *   @0x22e8a4 bl 0x318d10 <__divsi3>
 *   @0x22e8a8 str r0, [sp, #0x34]
 *   @0x22e8ac ldr r0, [sp, #0x60]
 *   @0x22e8b0 cmp r0, #0
 *   @0x22e8b4 ble 0x22e8f0 <res2_inverse+0xdc>
 *   @0x22e8b8 ldr r2, [r6]
 *   @0x22e8bc cmp r2, #0
 *   @0x22e8c0 bne 0x22e8f4 <res2_inverse+0xe0>
 *   @0x22e8c4 mov r3, r6
 *   @0x22e8c8 b 0x22e8d8 <res2_inverse+0xc4>
 *   @0x22e8cc ldr r1, [r3, #0x4]!
 *   @0x22e8d0 cmp r1, #0
 *   @0x22e8d4 bne 0x22e8f4 <res2_inverse+0xe0>
 *   @0x22e8d8 add r2, r2, #1
 *   @0x22e8dc cmp r2, r0
 *   @0x22e8e0 bne 0x22e8cc <res2_inverse+0xb8>
 *   @0x22e8e4 mov r0, #0
 *   @0x22e8e8 add sp, sp, #60
 *   @0x22e8ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22e8f0 beq 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22e8f4 mov r0, r5
 *   @0x22e8f8 ldr r1, [sp, #0x60]
 *   @0x22e8fc bl 0x318d10 <__divsi3>
 *   @0x22e900 ldr r3, [r11, #0xc]
 *   @0x22e904 cmp r3, #0
 *   @0x22e908 mov r7, r0
 *   @0x22e90c ble 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22e910 mov r12, r10
 *   @0x22e914 mov r10, r8
 *   @0x22e918 add r4, r4, #4
 *   @0x22e91c mov r2, #0
 *   @0x22e920 str r4, [sp, #0x2c]
 *   @0x22e924 str r2, [sp, #0x30]
 *   @0x22e928 cmp r10, #0
 *   @0x22e92c ble 0x22ea18 <res2_inverse+0x204>
 *   @0x22e930 ldr r3, [sp, #0x30]
 *   @0x22e934 mov r8, #0
 *   @0x22e938 mov r2, #1
 *   @0x22e93c mov r5, r8
 *   @0x22e940 lsl r2, r2, r3
 *   @0x22e944 str r2, [sp, #0x20]
 *   @0x22e948 lsl r0, r3, #2
 *   @0x22e94c str r0, [sp, #0x28]
 *   @0x22e950 ldr r3, [sp, #0x30]
 *   @0x22e954 cmp r3, #0
 *   @0x22e958 beq 0x22ea30 <res2_inverse+0x21c>
 *   @0x22e95c ldr r0, [sp, #0x1c]
 *   @0x22e960 cmp r10, r5
 *   @0x22e964 cmpgt r0, #0
 *   @0x22e968 ble 0x22ea08 <res2_inverse+0x1f4>
 *   @0x22e96c ldr r2, [sp, #0x34]
 *   @0x22e970 mov r4, #0
 *   @0x22e974 str r10, [sp, #0x14]
 *   @0x22e978 mla r6, r5, r7, r2
 *   @0x22e97c ldr r3, [r9, r8]
 *   @0x22e980 add r5, r5, #1
 *   @0x22e984 ldr r10, [sp, #0x20]
 *   @0x22e988 ldr r0, [r3, r4, lsl #2]
 *   @0x22e98c add r4, r4, #1
 *   @0x22e990 add r3, r0, #6
 *   @0x22e994 ldr r3, [r12, r3, lsl #2]
 *   @0x22e998 tst r10, r3
 *   @0x22e99c beq 0x22e9ec <res2_inverse+0x1d8>
 *   @0x22e9a0 ldr r10, [r11, #0x18]
 *   @0x22e9a4 mov r2, r6
 *   @0x22e9a8 ldr r1, [sp, #0x24]
 *   @0x22e9ac ldr r3, [sp, #0x60]
 *   @0x22e9b0 ldr r0, [r10, r0, lsl #2]
 *   @0x22e9b4 ldr r10, [sp, #0x28]
 *   @0x22e9b8 ldr r0, [r0, r10]
 *   @0x22e9bc cmp r0, #0
 *   @0x22e9c0 beq 0x22e9ec <res2_inverse+0x1d8>
 *   @0x22e9c4 ldr r10, [sp, #0x2c]
 *   @0x22e9c8 mvn lr, #7
 *   @0x22e9cc str r7, [sp, #0x4]
 *   @0x22e9d0 str lr, [sp, #0x8]
 *   @0x22e9d4 str r10, [sp]
 *   @0x22e9d8 str r12, [sp, #0x18]
 *   @0x22e9dc bl 0x228f20 <vorbis_book_decodevv_add>
 *   @0x22e9e0 ldr r12, [sp, #0x18]
 *   @0x22e9e4 cmn r0, #1
 *   @0x22e9e8 beq 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22e9ec ldr r10, [sp, #0x1c]
 *   @0x22e9f0 add r6, r6, r7
 *   @0x22e9f4 ldr r0, [sp, #0x14]
 *   @0x22e9f8 cmp r10, r4
 *   @0x22e9fc cmpgt r0, r5
 *   @0x22ea00 bgt 0x22e97c <res2_inverse+0x168>
 *   @0x22ea04 mov r10, r0
 *   @0x22ea08 cmp r10, r5
 *   @0x22ea0c add r8, r8, #4
 *   @0x22ea10 bgt 0x22e950 <res2_inverse+0x13c>
 *   @0x22ea14 ldr r3, [r11, #0xc]
 *   @0x22ea18 ldr r0, [sp, #0x30]
 *   @0x22ea1c add r0, r0, #1
 *   @0x22ea20 str r0, [sp, #0x30]
 *   @0x22ea24 cmp r3, r0
 *   @0x22ea28 bgt 0x22e928 <res2_inverse+0x114>
 *   @0x22ea2c b 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22ea30 ldr r0, [r11, #0x14]
 *   @0x22ea34 ldr r1, [sp, #0x2c]
 *   @0x22ea38 str r12, [sp, #0x18]
 *   @0x22ea3c bl 0x2280d0 <vorbis_book_decode>
 *   @0x22ea40 ldr r12, [sp, #0x18]
 *   @0x22ea44 cmn r0, #1
 *   @0x22ea48 beq 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22ea4c ldr r3, [r12, #0x10]
 *   @0x22ea50 cmp r0, r3
 *   @0x22ea54 bge 0x22e8e4 <res2_inverse+0xd0>
 *   @0x22ea58 ldr r3, [r11, #0x20]
 *   @0x22ea5c ldr r3, [r3, r0, lsl #2]
 *   @0x22ea60 cmp r3, #0
 *   @0x22ea64 str r3, [r9, r8]
 *   @0x22ea68 bne 0x22e95c <res2_inverse+0x148>
 *   @0x22ea6c b 0x22e8e4 <res2_inverse+0xd0>
 *
 * ══ §33/50 yySocket::Create()  0x294f68  size 604  151 条（0x294f68..0x2951c4）
 * @func 0x294f68 0x2951c4  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x294fcc→0x3eb70c, 0x295104→0x3eb70c, 0x295184→0x3eb70c
 * 调用序列: 0xb6d9c×4 / yySocket::Create()+0x17c×3 / 0xb6da8 / 0xb6db4 / yySocket::SetTimeout(int, int) / 0xb6dc0 / 0xb65d4
 * 字段偏移 top8: 0x8×3 / 0x2c×3 / 0xc×3 / 0x10×3 / 0xc4×2 / 0x1e0×2 / 0xa8×2 / 0x28×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x294f68 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x294f6c sub sp, sp, #52
 *   @0x294f70 ldr r6, [pc, #0x230]
 *   @0x294f74 mov r4, r0
 *   @0x294f78 ldr r2, [pc, #0x22c]
 *   @0x294f7c add r6, pc, r6
 *   @0x294f80 ldr r3, [r0, #0x8]
 *   @0x294f84 ldr r7, [r6, r2]
 *   @0x294f88 cmp r3, #0
 *   @0x294f8c ldr r2, [r7]
 *   @0x294f90 str r2, [sp, #0x2c]
 *   @0x294f94 beq 0x294fec <_ZN8yySocket6CreateEv+0x84>
 *   @0x294f98 cmp r3, #1
 *   @0x294f9c bne 0x295128 <_ZN8yySocket6CreateEv+0x1c0>
 *   @0x294fa0 ldr r5, [r4]
 *   @0x294fa4 mov r2, #17
 *   @0x294fa8 mov r1, #2
 *   @0x294fac cmn r5, #1
 *   @0x294fb0 bne 0x295000 <_ZN8yySocket6CreateEv+0x98>
 *   @0x294fb4 ldrb r0, [r4, #0xc4]
 *   @0x294fb8 cmp r0, #0
 *   @0x294fbc moveq r0, #2
 *   @0x294fc0 movne r0, #10
 *   @0x294fc4 bl 0xb6da8 <socket@plt>
 *   @0x294fc8 ldr r1, [pc, #0x1e0]
 *   @0x294fcc ldr r3, [pc, #0x1e0]
 *   @0x294fd0 add r1, pc, r1
 *   @0x294fd4 cmn r0, #1
 *   @0x294fd8 mov r5, r0
 *   @0x294fdc str r0, [r4]
 *   @0x294fe0 beq 0x29518c <_ZN8yySocket6CreateEv+0x224>
 *   @0x294fe4 ldr r3, [r4, #0x8]
 *   @0x294fe8 b 0x295000 <_ZN8yySocket6CreateEv+0x98>
 *   @0x294fec ldr r5, [r4]
 *   @0x294ff0 mov r2, r3
 *   @0x294ff4 mov r1, #1
 *   @0x294ff8 cmn r5, #1
 *   @0x294ffc beq 0x294fb4 <_ZN8yySocket6CreateEv+0x4c>
 *   @0x295000 cmp r3, #1
 *   @0x295004 mov r8, #1
 *   @0x295008 addeq r9, sp, #16
 *   @0x29500c str r8, [sp, #0xc]
 *   @0x295010 beq 0x295070 <_ZN8yySocket6CreateEv+0x108>
 *   @0x295014 mov r3, #4
 *   @0x295018 mov r0, r5
 *   @0x29501c str r3, [sp]
 *   @0x295020 mov r1, #6
 *   @0x295024 mov r2, r8
 *   @0x295028 add r3, sp, #12
 *   @0x29502c bl 0xb6d9c <setsockopt@plt>
 *   @0x295030 cmp r0, #0
 *   @0x295034 blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c>
 *   @0x295038 ldrb r12, [r4, #0x2c]
 *   @0x29503c add r9, sp, #16
 *   @0x295040 ldr r0, [r4]
 *   @0x295044 mov r2, #8
 *   @0x295048 mov r1, r8
 *   @0x29504c str r2, [sp]
 *   @0x295050 mov r3, r9
 *   @0x295054 mov r2, #13
 *   @0x295058 str r12, [sp, #0x10]
 *   @0x29505c mov r12, #0
 *   @0x295060 str r12, [sp, #0x14]
 *   @0x295064 bl 0xb6d9c <setsockopt@plt>
 *   @0x295068 cmp r0, #0
 *   @0x29506c blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c>
 *   @0x295070 ldrb r3, [r4, #0xc4]
 *   @0x295074 cmp r3, #0
 *   @0x295078 beq 0x2950b4 <_ZN8yySocket6CreateEv+0x14c>
 *   @0x29507c ldr r0, [r4]
 *   @0x295080 mov r3, #4
 *   @0x295084 mov r1, #41
 *   @0x295088 str r3, [sp]
 *   @0x29508c mov r2, #26
 *   @0x295090 mov r3, r9
 *   @0x295094 mov r8, #0
 *   @0x295098 str r8, [sp, #0x10]
 *   @0x29509c bl 0xb6d9c <setsockopt@plt>
 *   @0x2950a0 cmp r0, #0
 *   @0x2950a4 blt 0x2950e4 <_ZN8yySocket6CreateEv+0x17c>
 *   @0x2950a8 ldr r3, [r4, #0x8]
 *   @0x2950ac cmp r3, #1
 *   @0x2950b0 beq 0x295130 <_ZN8yySocket6CreateEv+0x1c8>
 *   @0x2950b4 mov r2, r9
 *   @0x2950b8 ldr r0, [r4]
 *   @0x2950bc movw r1, #0x5452
 *   @0x2950c0 mov r3, #1
 *   @0x2950c4 str r3, [sp, #0x10]
 *   @0x2950c8 bl 0xb6db4 <ioctl@plt>
 *   @0x2950cc cmp r0, #0
 *   @0x2950d0 bne 0x295104 <_ZN8yySocket6CreateEv+0x19c>
 *   @0x2950d4 mov r0, r4
 *   @0x2950d8 ldr r1, [r4, #0xb4]
 *   @0x2950dc ldr r2, [r4, #0xb8]
 *   @0x2950e0 bl 0x294ed4 <_ZN8yySocket10SetTimeoutEii>
 *   @0x2950e4 mov r5, r0
 *   @0x2950e8 ldr r2, [sp, #0x2c]
 *   @0x2950ec mov r0, r5
 *   @0x2950f0 ldr r3, [r7]
 *   @0x2950f4 cmp r2, r3
 *   @0x2950f8 bne 0x2951a4 <_ZN8yySocket6CreateEv+0x23c>
 *   @0x2950fc add sp, sp, #52
 *   @0x295100 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x295104 ldr r3, [pc, #0xa8]
 *   @0x295108 ldr r1, [pc, #0xa8]
 *   @0x29510c ldr r3, [r6, r3]
 *   @0x295110 add r1, pc, r1
 *   @0x295114 ldr r0, [r3]
 *   @0x295118 ldr r3, [r0]
 *   @0x29511c ldr r3, [r3, #0xc]
 *   @0x295120 blx r3
 *   @0x295124 b 0x2950d4 <_ZN8yySocket6CreateEv+0x16c>
 *   @0x295128 mvn r5, #0
 *   @0x29512c b 0x2950e8 <_ZN8yySocket6CreateEv+0x180>
 *   @0x295130 add r5, sp, #24
 *   @0x295134 ldr r1, [pc, #0x80]
 *   @0x295138 mov r0, #10
 *   @0x29513c str r8, [sp, #0x18]
 *   @0x295140 add r1, pc, r1
 *   @0x295144 mov r2, r5
 *   @0x295148 str r8, [sp, #0x1c]
 *   @0x29514c str r8, [sp, #0x20]
 *   @0x295150 str r8, [sp, #0x24]
 *   @0x295154 str r8, [sp, #0x28]
 *   @0x295158 bl 0xb6dc0 <inet_pton@plt>
 *   @0x29515c ldr r0, [r4]
 *   @0x295160 mov r2, #20
 *   @0x295164 mov r3, r5
 *   @0x295168 str r2, [sp]
 *   @0x29516c mov r1, #41
 *   @0x295170 bl 0xb6d9c <setsockopt@plt>
 *   @0x295174 cmp r0, #0
 *   @0x295178 bge 0x2950b4 <_ZN8yySocket6CreateEv+0x14c>
 *   @0x29517c ldr r1, [pc, #0x3c]
 *   @0x295180 mov r5, r0
 *   @0x295184 ldr r3, [pc, #0x28]
 *   @0x295188 add r1, pc, r1
 *   @0x29518c ldr r3, [r6, r3]
 *   @0x295190 ldr r0, [r3]
 *   @0x295194 ldr r3, [r0]
 *   @0x295198 ldr r3, [r3, #0xc]
 *   @0x29519c blx r3
 *   @0x2951a0 b 0x2950e8 <_ZN8yySocket6CreateEv+0x180>
 *   @0x2951a4 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2951a8 ldrsbeq r12, [r5], -r4
 *   @0x2951ac .word 0xffffbd00
 *   @0x2951b0 ldrdeq r4, r5, [r12], -r12
 *   @0x2951b4 .word 0xffffbac4
 *   @0x2951b8 andeq r4, r12, r8, ror #1
 *   @0x2951bc andeq r4, r12, r8, lsl #1
 *   @0x2951c0 andeq r4, r12, r8, asr #32
 *
 * ══ §34/50 b2FrictionJoint::InitVelocityConstraints(b2SolverData const&)  0x2cd73c  size 604  151 条（0x2cd73c..0x2cd998）
 * @func 0x2cd73c 0x2cd998  size 604  151 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2
 * 字段偏移 top8: 0x8×4 / 0x30×1 / 0x34×1 / 0x18×1 / 0x68×1 / 0x1c×1 / 0x6c×1 / 0x14×1
 * VFP 指令 105 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2cd73c ldr r2, [r0, #0x30]
 *   @0x2cd740 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2cd744 vpush {d8, d9, d10, d11}
 *   @0x2cd748 mov r7, r1
 *   @0x2cd74c vldr s19, [r2, #136]
 *   @0x2cd750 ldr r3, [r0, #0x34]
 *   @0x2cd754 add r1, r2, #44
 *   @0x2cd758 ldr r6, [r2, #0x8]
 *   @0x2cd75c mov r4, r0
 *   @0x2cd760 vldr s18, [r3, #136]
 *   @0x2cd764 ldr r8, [r7, #0x18]
 *   @0x2cd768 ldr r12, [r3, #0x8]
 *   @0x2cd76c add lr, r0, #136
 *   @0x2cd770 add r10, r0, #128
 *   @0x2cd774 ldm r1, {r0, r1}
 *   @0x2cd778 str r6, [r4, #0x68]
 *   @0x2cd77c add r6, r6, r6, lsl #1
 *   @0x2cd780 vldr s16, [r2, #144]
 *   @0x2cd784 add r9, r3, #44
 *   @0x2cd788 lsl r6, r6, #2
 *   @0x2cd78c ldr r5, [r7, #0x1c]
 *   @0x2cd790 add r2, r8, r6
 *   @0x2cd794 str r12, [r4, #0x6c]
 *   @0x2cd798 stm r10, {r0, r1}
 *   @0x2cd79c add r12, r12, r12, lsl #1
 *   @0x2cd7a0 ldm r9, {r0, r1}
 *   @0x2cd7a4 vldr s17, [r3, #144]
 *   @0x2cd7a8 ldr r9, [r2, #0x8]
 *   @0x2cd7ac lsl r12, r12, #2
 *   @0x2cd7b0 add r8, r8, r12
 *   @0x2cd7b4 add r6, r5, r6
 *   @0x2cd7b8 stm lr, {r0, r1}
 *   @0x2cd7bc vstr s19, [r4, #144]
 *   @0x2cd7c0 mov r0, r9
 *   @0x2cd7c4 vstr s18, [r4, #148]
 *   @0x2cd7c8 vstr s16, [r4, #152]
 *   @0x2cd7cc vstr s17, [r4, #156]
 *   @0x2cd7d0 add r5, r5, r12
 *   @0x2cd7d4 bl 0xb6580 <sinf@plt>
 *   @0x2cd7d8 ldr r8, [r8, #0x8]
 *   @0x2cd7dc vmov s22, r0
 *   @0x2cd7e0 mov r0, r9
 *   @0x2cd7e4 bl 0xb658c <cosf@plt>
 *   @0x2cd7e8 vmov s21, r0
 *   @0x2cd7ec mov r0, r8
 *   @0x2cd7f0 bl 0xb6580 <sinf@plt>
 *   @0x2cd7f4 vmov s20, r0
 *   @0x2cd7f8 mov r0, r8
 *   @0x2cd7fc bl 0xb658c <cosf@plt>
 *   @0x2cd800 vldr s11, [r4, #72]
 *   @0x2cd804 vldr s14, [r4, #132]
 *   @0x2cd808 vsub.f32 s14, s11, s14
 *   @0x2cd80c vldr s15, [r4, #140]
 *   @0x2cd810 vldr s13, [r4, #80]
 *   @0x2cd814 vldr s12, [r4, #76]
 *   @0x2cd818 vldr s8, [r4, #68]
 *   @0x2cd81c vldr s10, [r4, #128]
 *   @0x2cd820 vldr s1, [r6]
 *   @0x2cd824 vldr s2, [r6, #4]
 *   @0x2cd828 vldr s3, [r6, #8]
 *   @0x2cd82c vldr s4, [r5]
 *   @0x2cd830 vldr s5, [r5, #4]
 *   @0x2cd834 vldr s6, [r5, #8]
 *   @0x2cd838 vsub.f32 s13, s13, s15
 *   @0x2cd83c vldr s15, [r4, #136]
 *   @0x2cd840 vsub.f32 s15, s12, s15
 *   @0x2cd844 vmul.f32 s12, s14, s21
 *   @0x2cd848 vmov s9, r0
 *   @0x2cd84c vmul.f32 s11, s13, s20
 *   @0x2cd850 vsub.f32 s10, s8, s10
 *   @0x2cd854 vmul.f32 s14, s14, s22
 *   @0x2cd858 vmla.f32 s12, s10, s22
 *   @0x2cd85c vnmls.f32 s11, s15, s9
 *   @0x2cd860 vstr s12, [r4, #116]
 *   @0x2cd864 ldrb r3, [r7, #0x14]
 *   @0x2cd868 vmul.f32 s13, s13, s9
 *   @0x2cd86c vstr s11, [r4, #120]
 *   @0x2cd870 vnmls.f32 s14, s10, s21
 *   @0x2cd874 vmla.f32 s13, s15, s20
 *   @0x2cd878 vstr s14, [r4, #112]
 *   @0x2cd87c vadd.f32 s8, s19, s18
 *   @0x2cd880 vstr s13, [r4, #124]
 *   @0x2cd884 vmul.f32 s9, s16, s12
 *   @0x2cd888 vmul.f32 s15, s17, s11
 *   @0x2cd88c vmul.f32 s7, s16, s14
 *   @0x2cd890 vmov.f32 s20, s8
 *   @0x2cd894 vmla.f32 s20, s9, s12
 *   @0x2cd898 vmul.f32 s10, s15, s13
 *   @0x2cd89c vnmul.f32 s0, s16, s14
 *   @0x2cd8a0 vmla.f32 s8, s7, s14
 *   @0x2cd8a4 vnmls.f32 s10, s0, s12
 *   @0x2cd8a8 vmul.f32 s7, s17, s13
 *   @0x2cd8ac vmov.f32 s9, s20
 *   @0x2cd8b0 vmla.f32 s8, s15, s11
 *   @0x2cd8b4 vmla.f32 s9, s7, s13
 *   @0x2cd8b8 vmul.f32 s15, s10, s10
 *   @0x2cd8bc vnmls.f32 s15, s9, s8
 *   @0x2cd8c0 vcmp.f32 s15, #0
 *   @0x2cd8c4 vmrs APSR_nzcv, fpscr
 *   @0x2cd8c8 vmovne.f32 s7, #1.000000e+00
 *   @0x2cd8cc vdivne.f32 s15, s7, s15
 *   @0x2cd8d0 vadd.f32 s7, s16, s17
 *   @0x2cd8d4 vnmul.f32 s10, s15, s10
 *   @0x2cd8d8 vmul.f32 s8, s8, s15
 *   @0x2cd8dc vstr s10, [r4, #164]
 *   @0x2cd8e0 vstr s10, [r4, #168]
 *   @0x2cd8e4 vmul.f32 s15, s9, s15
 *   @0x2cd8e8 vstr s8, [r4, #160]
 *   @0x2cd8ec vcmpe.f32 s7, #0
 *   @0x2cd8f0 vstr s15, [r4, #172]
 *   @0x2cd8f4 vmrs APSR_nzcv, fpscr
 *   @0x2cd8f8 vmovgt.f32 s15, #1.000000e+00
 *   @0x2cd8fc vdivgt.f32 s7, s15, s7
 *   @0x2cd900 cmp r3, #0
 *   @0x2cd904 vstr s7, [r4, #176]
 *   @0x2cd908 bne 0x2cd93c <_ZN15b2FrictionJoint23InitVelocityConstraintsERK12b2SolverData+0x200>
 *   @0x2cd90c mov r3, #0
 *   @0x2cd910 str r3, [r4, #0x54]
 *   @0x2cd914 str r3, [r4, #0x58]
 *   @0x2cd918 str r3, [r4, #0x5c]
 *   @0x2cd91c vpop {d8, d9, d10, d11}
 *   @0x2cd920 vstr s1, [r6]
 *   @0x2cd924 vstr s2, [r6, #4]
 *   @0x2cd928 vstr s3, [r6, #8]
 *   @0x2cd92c vstr s4, [r5]
 *   @0x2cd930 vstr s5, [r5, #4]
 *   @0x2cd934 vstr s6, [r5, #8]
 *   @0x2cd938 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2cd93c vldr s9, [r7, #8]
 *   @0x2cd940 vldr s10, [r4, #84]
 *   @0x2cd944 vmul.f32 s10, s9, s10
 *   @0x2cd948 vldr s15, [r4, #88]
 *   @0x2cd94c vldr s8, [r4, #92]
 *   @0x2cd950 vmul.f32 s15, s9, s15
 *   @0x2cd954 vstr s10, [r4, #84]
 *   @0x2cd958 vmul.f32 s12, s12, s10
 *   @0x2cd95c vstr s15, [r4, #88]
 *   @0x2cd960 vmul.f32 s13, s13, s10
 *   @0x2cd964 vnmls.f32 s12, s14, s15
 *   @0x2cd968 vnmls.f32 s13, s11, s15
 *   @0x2cd96c vmul.f32 s14, s9, s8
 *   @0x2cd970 vadd.f32 s12, s14, s12
 *   @0x2cd974 vstr s14, [r4, #92]
 *   @0x2cd978 vadd.f32 s13, s14, s13
 *   @0x2cd97c vmls.f32 s1, s19, s10
 *   @0x2cd980 vmla.f32 s4, s18, s10
 *   @0x2cd984 vmls.f32 s2, s19, s15
 *   @0x2cd988 vmla.f32 s5, s18, s15
 *   @0x2cd98c vmls.f32 s3, s16, s12
 *   @0x2cd990 vmla.f32 s6, s17, s13
 *   @0x2cd994 b 0x2cd91c <_ZN15b2FrictionJoint23InitVelocityConstraintsERK12b2SolverData+0x1e0>
 *
 * ══ §35/50 ft_lzwstate_io  0x316fb4  size 602  151 条（0x316fb4..0x31720e）
 * @func 0x316fb4 0x317210  size 604  151 条
 * 部分覆盖: 本节 151/274 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_316cdc+0xe0×2 / FT_Stream_Seek / FT_Stream_TryRead / ft_lzwstate_io+0xba / 0x41692c / ft_mem_realloc / 0x357278
 * 字段偏移 top8: 0x38×4 / 0x5c×4 / 0x4c×3 / 0x60×2 / 0x28×1 / 0x30×1 / 0x2c×1 / 0xc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x316fb4 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x316fb8 mov r4, r0
 *   @0x316fbc mov r11, r1
 *   @0x316fc0 mov r10, r2
 *   @0x316fc4 ldr.w r8, [r0, #0x48]
 *   @0x316fc8 cmp r2, #0x0
 *   @0x316fcc stmdavs r3, {r0, r4, r8, pc}
 *   @0x316fd0 cmp r3, #0x1
 *   @0x316fd4 movwle r8, #0x40c6
 *   @0x316fd8 cmp r3, #0x2
 *   @0x316fdc strhs r8, [r0, #-0x10b]
 *   @0x316fe0 b 0x3170c2 <ft_lzwstate_io+0x10e>
 *   @0x316fe4 smlatbhs r2, r4, r0, r0
 *   @0x316fe8 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x316fec cmp r0, #0x0
 *   @0x316ff0 ldr.w r0, [r4, #0xa4]
 *   @0x316ff4 add r1, sp, #0x14
 *   @0x316ff8 bl 0x2e69a0 <FT_Stream_TryRead>
 *   @0x316ffc cmp r0, #0x1
 *   @0x317000 ldrb.w r2, [sp, #0x14]
 *   @0x317004 and r3, r2, #0x1f
 *   @0x317008 bic r2, r2, #0x7f
 *   @0x31700c cmp r3, #0x10
 *   @0x317010 sbcslt pc, r2, #3
 *   @0x317014 sub.w r1, r0, #0x100
 *   @0x317018 str r3, [r4, #0x28]
 *   @0x31701c str r1, [r4, #0x30]
 *   @0x317020 adds r2, #0x0
 *   @0x317024 .word 0x63610109
 *   @0x317028 it ne
 *   @0x31702c cmp r3, r1
 *   @0x317030 subls r0, #0xff
 *   @0x317034 it hi
 *   @0x317038 mvnvs r7, #128
 *   @0x31703c mov r0, r4
 *   @0x317040 ldmhs pc!, {r0, r2, r3, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x317044 bhi 0x317066 <ft_lzwstate_io+0xb2>
 *   @0x317048 andle r0, r1, r0, lsl #30
 *   @0x31704c strb.w r0, [r11]
 *   @0x317050 cmp.w r10, #0x1
 *   @0x317054 mov.w r5, #0x1
 *   @0x317058 bls 0x31706e <ft_lzwstate_io+0xba>
 *   @0x31705c mov r7, r0
 *   @0x317060 mov.w r9, #0x0
 *   @0x317064 b 0x317166 <ft_lzwstate_io+0x1b2>
 *   @0x317068 strhs r0, [r0, #-0x800]
 *   @0x31706c b 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x317070 mov r6, r0
 *   @0x317074 sbc r0, r2, r0, lsl #16
 *   @0x317078 ldr r3, [r4, #0x2c]
 *   @0x31707c beq 0x31716a <ft_lzwstate_io+0x1b6>
 *   @0x317080 movs r3, #0x1
 *   @0x317084 str r2, [r4, #0x38]
 *   @0x317088 strtmi r3, [r0], -r0, lsr #32
 *   @0x31708c str r2, [sp, #0xc]
 *   @0x317090 bls 0x41692c <g_RomDisk+0x1f10c>
 *   @0x317094 cmp r0, #0x0
 *   @0x317098 .word 0xf5b080af
 *   @0x31709c strmi r7, [r0], r0, lsl #31
 *   @0x3170a0 beq 0x317078 <ft_lzwstate_io+0xc4>
 *   @0x3170a4 it ls
 *   @0x3170a8 bhi 0x31716a <ft_lzwstate_io+0x1b6>
 *   @0x3170ac ldr r3, [r4, #0x60]
 *   @0x3170b0 bhs.w 0x3171e2 <ft_lzwstate_io+0x22e>
 *   @0x3170b4 ldr r3, [r4, #0x5c]
 *   @0x3170b8 adds r1, r3, #0x1
 *   @0x3170bc strb r6, [r2, r3]
 *   @0x3170c0 str r3, [r4]
 *   @0x3170c4 cbz r3, 0x3170e0 <ft_lzwstate_io+0x12c>
 *   @0x3170c8 str r3, [r4, #0x5c]
 *   @0x3170cc andle r0, r3, r0, lsl #30
 *   @0x3170d0 ldr r2, [r4, #0x58]
 *   @0x3170d4 strb.w r3, [r11, r5]
 *   @0x3170d8 adds r5, #0x1
 *   @0x3170dc bne 0x3170c2 <ft_lzwstate_io+0x10e>
 *   @0x3170e0 ldr r3, [r4, #0x38]
 *   @0x3170e4 cmp r3, r2
 *   @0x3170e8 ldr.w r9, [r4, #0x54]
 *   @0x3170ec cmp r3, r9
 *   @0x3170f0 ldr r2, [r4, #0x38]
 *   @0x3170f4 strh.w r7, [r3, r2, lsl #1]
 *   @0x3170f8 ldr r3, [r4, #0x38]
 *   @0x3170fc strb r6, [r2, r3]
 *   @0x317100 adds r3, #0x1
 *   @0x317104 b 0x317158 <ft_lzwstate_io+0x1a4>
 *   @0x317108 .word 0xf1b900a8
 *   @0x31710c andle r0, r2, r0, lsl #30
 *   @0x317110 add.w r12, r9, r9, lsr #2
 *   @0x317114 b 0x31711a <ft_lzwstate_io+0x166>
 *   @0x317118 stclvs p12, c7, [r3], #0
 *   @0x31711c movs r1, #0x3
 *   @0x317120 str.w r12, [sp, #0xc]
 *   @0x317124 str r3, [sp]
 *   @0x317128 str r3, [sp, #0x4]
 *   @0x31712c bl 0x2e808e <ft_mem_realloc>
 *   @0x317130 ldr r3, [sp, #0x14]
 *   @0x317134 strmi r12, [r1], -r12
 *   @0x317138 str r0, [r4, #0x4c]
 *   @0x31713c bne 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x317140 bl 0x357278
 *   @0x317144 strvs r0, [r0, #-0x149]!
 *   @0x317148 mov r2, r9
 *   @0x31714c .word 0xf8ddeaa4
 *   @0x317150 .word 0xf8c4c00c
 *   @0x317154 .word 0xe7cbc054
 *   @0x317158 movs r3, #0x1
 *   @0x31715c str r3, [r4]
 *   @0x317160 b 0x317166 <ft_lzwstate_io+0x1b2>
 *   @0x317164 movs r5, #0x0
 *   @0x317168 b 0x31708a <ft_lzwstate_io+0xd6>
 *   @0x31716c sub.w r2, r0, #0x100
 *   @0x317170 cmp r2, r3
 *   @0x317174 bhi 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x317178 ldr r3, [r4, #0x60]
 *   @0x31717c bhs 0x31718c <ft_lzwstate_io+0x1d8>
 *   @0x317180 mov r9, r7
 *   @0x317184 adds r1, r3, #0x1
 *   @0x317188 strb r6, [r2, r3]
 *   @0x31718c mov r0, r4
 *   @0x317190 stmdahs r0, {r0, r2, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x317194 bge 0x31717e <ft_lzwstate_io+0x1ca>
 *   @0x317198 mov r9, r0
 *   @0x31719c ldr r3, [r4, #0x4c]
 *   @0x3171a0 ldr r2, [r4, #0x5c]
 *   @0x3171a4 cmp r2, r3
 *   @0x3171a8 ldr r3, [r4, #0x5c]
 *   @0x3171ac adds r1, r3, #0x1
 *   @0x3171b0 ldr r1, [r4, #0x50]
 *   @0x3171b4 add.w r9, r9, #0x80000000
 *   @0x3171b8 sub.w r1, r1, #0x100
 *   @0x3171bc sub.w r9, r9, #0x100
 *   @0x3171c0 ldrb r1, [r1]
 *   @0x3171c4 ldr r3, [r4, #0x4c]
 *   @0x3171c8 .word 0xf1b99019
 *   @0x3171cc stmle r5!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} ^
 *   @0x3171d0 b 0x3171de <ft_lzwstate_io+0x22a>
 *   @0x3171d4 bl 0x316dbc <FT_Gzip_Uncompress+0x164>
 *   @0x3171d8 cmp r0, #0x0
 *   @0x3171dc b 0x3171fa <ft_lzwstate_io+0x246>
 *   @0x3171e0 b 0x3170aa <ft_lzwstate_io+0xf6>
 *   @0x3171e4 bl 0x316dbc <FT_Gzip_Uncompress+0x164>
 *   @0x3171e8 cmp r0, #0x0
 *   @0x3171ec and r10, r4, r3, ror #30
 *   @0x3171f0 mov r5, r2
 *   @0x3171f4 movs r5, #0x0
 *   @0x3171f8 mov r8, r9
 *   @0x3171fc str r3, [r4]
 *   @0x317200 str r7, [r4, #0x40]
 *   @0x317204 str.w r8, [r4, #0x48]
 *   @0x317208 add sp, #0x1c
 *   @0x31720c push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §36/50 VM::GetDSMap(Buffer_Standard*, int, int)  0xdb4b4  size 600  150 条（0xdb4b4..0xdb70c）
 * @func 0xdb4b4 0xdb70c  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: VM::WriteRValueToBuffer(RValue*, Buffer_Standard*)×2 / DS_AutoMutex::~DS_AutoMutex()×2 / DS_AutoMutex::DS_AutoMutex() / VM::GetDSMap(Buffer_Standard*, int, int)+0x200 / CDS_Map::Size() / VM::WriteDSSizeCount(Buffer_Standard*, int, int&) / VM::GetDSMap(Buffer_Standard*, int, int)+0x1bc / VM::GetDSMap(Buffer_Standard*, int, int)+0x18c
 * 字段偏移 top8: 0x4×6 / 0xc×5 / 0x14×3 / 0x8×3 / 0x10×2 / 0x2c×2 / 0x218×1 / 0x208×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdb4b4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xdb4b8 sub sp, sp, #36
 *   @0xdb4bc add r10, sp, #28
 *   @0xdb4c0 mov r7, r0
 *   @0xdb4c4 mov r4, r1
 *   @0xdb4c8 str r2, [sp, #0x14]
 *   @0xdb4cc mov r0, r10
 *   @0xdb4d0 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0xdb4d4 cmp r4, #0
 *   @0xdb4d8 blt 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200>
 *   @0xdb4dc ldr r3, [pc, #0x218]
 *   @0xdb4e0 ldr r3, [pc, r3]
 *   @0xdb4e4 ldr r3, [r3]
 *   @0xdb4e8 cmp r4, r3
 *   @0xdb4ec bge 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200>
 *   @0xdb4f0 ldr r3, [pc, #0x208]
 *   @0xdb4f4 ldr r3, [pc, r3]
 *   @0xdb4f8 ldr r3, [r3, #0x4]
 *   @0xdb4fc ldr r4, [r3, r4, lsl #2]
 *   @0xdb500 cmp r4, #0
 *   @0xdb504 beq 0xdb6b4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x200>
 *   @0xdb508 mov r0, r4
 *   @0xdb50c bl 0x2052c0 <_ZN7CDS_Map4SizeEv>
 *   @0xdb510 add r2, sp, #20
 *   @0xdb514 str r0, [sp, #0xc]
 *   @0xdb518 mov r0, r7
 *   @0xdb51c ldr r1, [sp, #0xc]
 *   @0xdb520 bl 0xdb080 <_ZN2VM16WriteDSSizeCountEP15Buffer_StandardiRi>
 *   @0xdb524 subs r9, r0, #0
 *   @0xdb528 ble 0xdb670 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1bc>
 *   @0xdb52c ldr r8, [r4]
 *   @0xdb530 mov r5, #0
 *   @0xdb534 ldr r12, [r8]
 *   @0xdb538 b 0xdb54c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x98>
 *   @0xdb53c ldr r3, [r8, #0x4]
 *   @0xdb540 add r5, r5, #1
 *   @0xdb544 cmp r5, r3
 *   @0xdb548 bgt 0xdb6ac <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1f8>
 *   @0xdb54c ldr r4, [r12, r5, lsl #3]
 *   @0xdb550 cmp r4, #0
 *   @0xdb554 beq 0xdb53c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x88>
 *   @0xdb558 ldr lr, [sp, #0x14]
 *   @0xdb55c cmp lr, #0
 *   @0xdb560 movgt r1, #0
 *   @0xdb564 bgt 0xdb578 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xc4>
 *   @0xdb568 b 0xdb5d0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x11c>
 *   @0xdb56c add r1, r1, #1
 *   @0xdb570 cmp r1, lr
 *   @0xdb574 beq 0xdb5d0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x11c>
 *   @0xdb578 cmp r4, #0
 *   @0xdb57c beq 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8>
 *   @0xdb580 ldr r4, [r4, #0x4]
 *   @0xdb584 cmp r4, #0
 *   @0xdb588 bne 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8>
 *   @0xdb58c ldr r0, [r8, #0x4]
 *   @0xdb590 add r2, r5, #1
 *   @0xdb594 cmp r2, r0
 *   @0xdb598 bgt 0xdb5c0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x10c>
 *   @0xdb59c add r3, r12, r5, lsl #3
 *   @0xdb5a0 ldr r4, [r3, #0x8]
 *   @0xdb5a4 mov r5, r2
 *   @0xdb5a8 add r3, r3, #8
 *   @0xdb5ac add r2, r2, #1
 *   @0xdb5b0 cmp r4, #0
 *   @0xdb5b4 bne 0xdb56c <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xb8>
 *   @0xdb5b8 cmp r0, r2
 *   @0xdb5bc bge 0xdb5a0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xec>
 *   @0xdb5c0 add r1, r1, #1
 *   @0xdb5c4 mvn r5, #0
 *   @0xdb5c8 cmp r1, lr
 *   @0xdb5cc bne 0xdb578 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xc4>
 *   @0xdb5d0 ldr r3, [pc, #0x12c]
 *   @0xdb5d4 mov r6, #0
 *   @0xdb5d8 add r3, pc, r3
 *   @0xdb5dc str r3, [sp, #0x10]
 *   @0xdb5e0 b 0xdb5f0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x13c>
 *   @0xdb5e4 add r6, r6, #1
 *   @0xdb5e8 cmp r6, r9
 *   @0xdb5ec beq 0xdb670 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1bc>
 *   @0xdb5f0 cmp r4, #0
 *   @0xdb5f4 beq 0xdb680 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1cc>
 *   @0xdb5f8 ldr r11, [r4, #0xc]
 *   @0xdb5fc cmp r11, #0
 *   @0xdb600 beq 0xdb680 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1cc>
 *   @0xdb604 mov r0, r11
 *   @0xdb608 mov r1, r7
 *   @0xdb60c bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb610 add r0, r11, #16
 *   @0xdb614 mov r1, r7
 *   @0xdb618 bl 0xd8a88 <_ZN2VM19WriteRValueToBufferEP6RValueP15Buffer_Standard>
 *   @0xdb61c ldr r4, [r4, #0x4]
 *   @0xdb620 cmp r4, #0
 *   @0xdb624 bne 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130>
 *   @0xdb628 ldr r1, [r8, #0x4]
 *   @0xdb62c add r2, r5, #1
 *   @0xdb630 cmp r2, r1
 *   @0xdb634 bgt 0xdb660 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x1ac>
 *   @0xdb638 ldr r3, [r8]
 *   @0xdb63c add r3, r3, r5, lsl #3
 *   @0xdb640 ldr r4, [r3, #0x8]
 *   @0xdb644 mov r5, r2
 *   @0xdb648 add r3, r3, #8
 *   @0xdb64c add r2, r2, #1
 *   @0xdb650 cmp r4, #0
 *   @0xdb654 bne 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130>
 *   @0xdb658 cmp r2, r1
 *   @0xdb65c ble 0xdb640 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x18c>
 *   @0xdb660 add r6, r6, #1
 *   @0xdb664 mvn r5, #0
 *   @0xdb668 cmp r6, r9
 *   @0xdb66c bne 0xdb5f0 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x13c>
 *   @0xdb670 mov r0, r10
 *   @0xdb674 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xdb678 add sp, sp, #36
 *   @0xdb67c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdb680 ldr r0, [pc, #0x80]
 *   @0xdb684 ldr r1, [sp, #0x10]
 *   @0xdb688 ldr r0, [pc, r0]
 *   @0xdb68c ldr r3, [sp, #0x14]
 *   @0xdb690 ldr r2, [sp, #0xc]
 *   @0xdb694 ldr r0, [r0]
 *   @0xdb698 ldr r12, [r0]
 *   @0xdb69c str r9, [sp]
 *   @0xdb6a0 ldr r12, [r12, #0xc]
 *   @0xdb6a4 blx r12
 *   @0xdb6a8 b 0xdb5e4 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0x130>
 *   @0xdb6ac mvn r5, #0
 *   @0xdb6b0 b 0xdb558 <_ZN2VM8GetDSMapEP15Buffer_Standardii+0xa4>
 *   @0xdb6b4 mov r2, r7
 *   @0xdb6b8 mov r1, #0
 *   @0xdb6bc ldr r0, [r2], #44
 *   @0xdb6c0 movt r1, #0xffe0
 *   @0xdb6c4 movw r3, #0xffff
 *   @0xdb6c8 str r1, [r7, #0x2c]
 *   @0xdb6cc movt r3, #0x41ef
 *   @0xdb6d0 mov r1, #0
 *   @0xdb6d4 str r3, [r7, #0x30]
 *   @0xdb6d8 ldr r3, [r0, #0x8]
 *   @0xdb6dc mov r0, r7
 *   @0xdb6e0 str r1, [r7, #0x38]
 *   @0xdb6e4 mov r1, #5
 *   @0xdb6e8 blx r3
 *   @0xdb6ec mov r0, r10
 *   @0xdb6f0 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0xdb6f4 add sp, sp, #36
 *   @0xdb6f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xdb6fc mlaseq r1, r8, r7, r2
 *   @0xdb700 eorseq r2, r1, r8, asr #8
 *   @0xdb704 eoreq r7, r5, r4, ror #12
 *   @0xdb708 eorseq r2, r1, r12, lsl #1
 *
 * ══ §37/50 F_PhysicsCreateDistanceJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x14ed04  size 600  150 条（0x14ed04..0x14ef5c）
 * @func 0x14ed04 0x14ef6c  size 616  154 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x14eda4→0x54298c, 0x14ee6c→0x54298c
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetBool(RValue const*, int) / CPhysicsWorld::CreateDistanceJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x11c×2 / 0x84×2 / 0xb4×2 / 0x10×2 / 0x14×2 / 0x22c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x14ed04 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x14ed08 sub sp, sp, #292
 *   @0x14ed0c ldr r6, [pc, #0x22c]
 *   @0x14ed10 mov r8, r2
 *   @0x14ed14 ldr r12, [pc, #0x228]
 *   @0x14ed18 mov r3, #0
 *   @0x14ed1c add r6, pc, r6
 *   @0x14ed20 ldr r4, [sp, #0x148]
 *   @0x14ed24 mov r5, r0
 *   @0x14ed28 mov r9, r1
 *   @0x14ed2c ldr r7, [r6, r12]
 *   @0x14ed30 mov r0, r3
 *   @0x14ed34 mov r1, r3
 *   @0x14ed38 movt r0, #0xbff0
 *   @0x14ed3c str r3, [r5, #0xc]
 *   @0x14ed40 ldr r2, [r7]
 *   @0x14ed44 str r0, [r5, #0x4]
 *   @0x14ed48 mov r0, r4
 *   @0x14ed4c str r3, [r5]
 *   @0x14ed50 str r2, [sp, #0x11c]
 *   @0x14ed54 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ed58 mov r1, r9
 *   @0x14ed5c mov r2, r8
 *   @0x14ed60 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14ed64 subs r10, r0, #0
 *   @0x14ed68 beq 0x14eeac <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x14ed6c mov r1, #1
 *   @0x14ed70 mov r0, r4
 *   @0x14ed74 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ed78 mov r1, r9
 *   @0x14ed7c mov r2, r8
 *   @0x14ed80 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x14ed84 subs r9, r0, #0
 *   @0x14ed88 beq 0x14eef4 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x14ed8c ldr r8, [r10, #0x84]
 *   @0x14ed90 cmp r8, #0
 *   @0x14ed94 beq 0x14ee6c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x14ed98 ldr r9, [r9, #0x84]
 *   @0x14ed9c cmp r9, #0
 *   @0x14eda0 beq 0x14ee6c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x14eda4 ldr r3, [pc, #0x19c]
 *   @0x14eda8 ldr r3, [r6, r3]
 *   @0x14edac ldr r3, [r3]
 *   @0x14edb0 ldr r6, [r3, #0xb4]
 *   @0x14edb4 cmp r6, #0
 *   @0x14edb8 beq 0x14ee98 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x14edbc mov r1, #2
 *   @0x14edc0 mov r0, r4
 *   @0x14edc4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14edc8 mov r1, #3
 *   @0x14edcc mov r10, r0
 *   @0x14edd0 mov r0, r4
 *   @0x14edd4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14edd8 mov r1, #4
 *   @0x14eddc mov r2, r0
 *   @0x14ede0 mov r0, r4
 *   @0x14ede4 str r2, [sp, #0x10]
 *   @0x14ede8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14edec mov r1, #5
 *   @0x14edf0 mov r3, r0
 *   @0x14edf4 mov r0, r4
 *   @0x14edf8 str r3, [sp, #0x14]
 *   @0x14edfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x14ee00 mov r1, #6
 *   @0x14ee04 mov r11, r0
 *   @0x14ee08 mov r0, r4
 *   @0x14ee0c bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x14ee10 ldr r2, [sp, #0x10]
 *   @0x14ee14 ldr r3, [sp, #0x14]
 *   @0x14ee18 mov r1, r8
 *   @0x14ee1c str r11, [sp, #0x8]
 *   @0x14ee20 str r2, [sp]
 *   @0x14ee24 mov r2, r9
 *   @0x14ee28 str r3, [sp, #0x4]
 *   @0x14ee2c mov r3, r10
 *   @0x14ee30 str r0, [sp, #0xc]
 *   @0x14ee34 mov r0, r6
 *   @0x14ee38 bl 0x238e70 <_ZN13CPhysicsWorld19CreateDistanceJointEP14CPhysicsObjectS1_ffffb>
 *   @0x14ee3c vmov s15, r0
 *   @0x14ee40 vcvt.f64.s32 d7, s15
 *   @0x14ee44 vmov r0, r1, d7
 *   @0x14ee48 vmov r2, s14
 *   @0x14ee4c mov r3, r1
 *   @0x14ee50 stm r5, {r2, r3}
 *   @0x14ee54 ldr r2, [sp, #0x11c]
 *   @0x14ee58 ldr r3, [r7]
 *   @0x14ee5c cmp r2, r3
 *   @0x14ee60 bne 0x14ef3c <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x14ee64 add sp, sp, #292
 *   @0x14ee68 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x14ee6c ldr r3, [pc, #0xd4]
 *   @0x14ee70 ldr r3, [r6, r3]
 *   @0x14ee74 ldr r3, [r3]
 *   @0x14ee78 ldr r3, [r3, #0xb4]
 *   @0x14ee7c cmp r3, #0
 *   @0x14ee80 beq 0x14ee98 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x14ee84 ldr r0, [pc, #0xc0]
 *   @0x14ee88 mov r1, #0
 *   @0x14ee8c add r0, pc, r0
 *   @0x14ee90 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ee94 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x14ee98 ldr r0, [pc, #0xb0]
 *   @0x14ee9c mov r1, #0
 *   @0x14eea0 add r0, pc, r0
 *   @0x14eea4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14eea8 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x14eeac add r5, sp, #28
 *   @0x14eeb0 mov r1, r10
 *   @0x14eeb4 mov r2, #256
 *   @0x14eeb8 mov r0, r5
 *   @0x14eebc bl 0xb65b0 <memset@plt>
 *   @0x14eec0 mov r1, r10
 *   @0x14eec4 mov r0, r4
 *   @0x14eec8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14eecc ldr r2, [pc, #0x80]
 *   @0x14eed0 mov r1, #256
 *   @0x14eed4 add r2, pc, r2
 *   @0x14eed8 mov r3, r0
 *   @0x14eedc mov r0, r5
 *   @0x14eee0 bl 0xb65c8 <snprintf@plt>
 *   @0x14eee4 mov r0, r5
 *   @0x14eee8 mov r1, r10
 *   @0x14eeec bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14eef0 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x14eef4 add r5, sp, #28
 *   @0x14eef8 mov r1, r9
 *   @0x14eefc mov r2, #256
 *   @0x14ef00 mov r0, r5
 *   @0x14ef04 bl 0xb65b0 <memset@plt>
 *   @0x14ef08 mov r0, r4
 *   @0x14ef0c mov r1, #1
 *   @0x14ef10 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x14ef14 ldr r2, [pc, #0x3c]
 *   @0x14ef18 mov r1, #256
 *   @0x14ef1c add r2, pc, r2
 *   @0x14ef20 mov r3, r0
 *   @0x14ef24 mov r0, r5
 *   @0x14ef28 bl 0xb65c8 <snprintf@plt>
 *   @0x14ef2c mov r0, r5
 *   @0x14ef30 mov r1, r9
 *   @0x14ef34 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x14ef38 b 0x14ee54 <_Z28F_PhysicsCreateDistanceJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x14ef3c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x14ef40 eoreq r2, r10, r4, lsr pc
 *   @0x14ef44 .word 0xffffbd00
 *   @0x14ef48 .word 0xffffbcd8
 *   @0x14ef4c andseq r5, pc, r0, lsr pc
 *   @0x14ef50 andseq r4, pc, r4, lsl #31
 *   @0x14ef54 andseq r5, pc, r12, asr #29
 *   @0x14ef58 andseq r5, pc, r4, lsl #29
 *
 * ══ §38/50 F_PhysicsCreateFrictionJoint(RValue&, CInstance*, CInstance*, int, RValue*)  0x1501dc  size 600  150 条（0x1501dc..0x150434）
 * @func 0x1501dc 0x150434  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x15027c→0x54298c, 0x150344→0x54298c
 * 调用序列: YYGetInt32(RValue const*, int)×4 / YYGetFloat(RValue const*, int)×4 / Error_Show_Action(char const*, bool)×4 / Object_GetInstance(int, CInstance*, CInstance*)×2 / 0xb65b0×2 / 0xb65c8×2 / YYGetBool(RValue const*, int) / CPhysicsWorld::CreateFrictionJoint(CPhysicsObject*, CPhysicsObject*, float, float, float, float, bool)
 * 字段偏移 top8: 0xc×2 / 0x4×2 / 0x11c×2 / 0x84×2 / 0xb4×2 / 0x10×2 / 0x14×2 / 0x22c×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1501dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1501e0 sub sp, sp, #292
 *   @0x1501e4 ldr r6, [pc, #0x22c]
 *   @0x1501e8 mov r8, r2
 *   @0x1501ec ldr r12, [pc, #0x228]
 *   @0x1501f0 mov r3, #0
 *   @0x1501f4 add r6, pc, r6
 *   @0x1501f8 ldr r4, [sp, #0x148]
 *   @0x1501fc mov r5, r0
 *   @0x150200 mov r9, r1
 *   @0x150204 ldr r7, [r6, r12]
 *   @0x150208 mov r0, r3
 *   @0x15020c mov r1, r3
 *   @0x150210 movt r0, #0xbff0
 *   @0x150214 str r3, [r5, #0xc]
 *   @0x150218 ldr r2, [r7]
 *   @0x15021c str r0, [r5, #0x4]
 *   @0x150220 mov r0, r4
 *   @0x150224 str r3, [r5]
 *   @0x150228 str r2, [sp, #0x11c]
 *   @0x15022c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x150230 mov r1, r9
 *   @0x150234 mov r2, r8
 *   @0x150238 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x15023c subs r10, r0, #0
 *   @0x150240 beq 0x150384 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x150244 mov r1, #1
 *   @0x150248 mov r0, r4
 *   @0x15024c bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x150250 mov r1, r9
 *   @0x150254 mov r2, r8
 *   @0x150258 bl 0x14ec2c <_Z18Object_GetInstanceiP9CInstanceS0_>
 *   @0x15025c subs r9, r0, #0
 *   @0x150260 beq 0x1503cc <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x150264 ldr r8, [r10, #0x84]
 *   @0x150268 cmp r8, #0
 *   @0x15026c beq 0x150344 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x150270 ldr r9, [r9, #0x84]
 *   @0x150274 cmp r9, #0
 *   @0x150278 beq 0x150344 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x168>
 *   @0x15027c ldr r3, [pc, #0x19c]
 *   @0x150280 ldr r3, [r6, r3]
 *   @0x150284 ldr r3, [r3]
 *   @0x150288 ldr r6, [r3, #0xb4]
 *   @0x15028c cmp r6, #0
 *   @0x150290 beq 0x150370 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x150294 mov r1, #2
 *   @0x150298 mov r0, r4
 *   @0x15029c bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1502a0 mov r1, #3
 *   @0x1502a4 mov r10, r0
 *   @0x1502a8 mov r0, r4
 *   @0x1502ac bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1502b0 mov r1, #4
 *   @0x1502b4 mov r2, r0
 *   @0x1502b8 mov r0, r4
 *   @0x1502bc str r2, [sp, #0x10]
 *   @0x1502c0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1502c4 mov r1, #5
 *   @0x1502c8 mov r3, r0
 *   @0x1502cc mov r0, r4
 *   @0x1502d0 str r3, [sp, #0x14]
 *   @0x1502d4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei>
 *   @0x1502d8 mov r1, #6
 *   @0x1502dc mov r11, r0
 *   @0x1502e0 mov r0, r4
 *   @0x1502e4 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1502e8 ldr r2, [sp, #0x10]
 *   @0x1502ec ldr r3, [sp, #0x14]
 *   @0x1502f0 mov r1, r8
 *   @0x1502f4 str r11, [sp, #0x8]
 *   @0x1502f8 str r2, [sp]
 *   @0x1502fc mov r2, r9
 *   @0x150300 str r3, [sp, #0x4]
 *   @0x150304 mov r3, r10
 *   @0x150308 str r0, [sp, #0xc]
 *   @0x15030c mov r0, r6
 *   @0x150310 bl 0x239674 <_ZN13CPhysicsWorld19CreateFrictionJointEP14CPhysicsObjectS1_ffffb>
 *   @0x150314 vmov s15, r0
 *   @0x150318 vcvt.f64.s32 d7, s15
 *   @0x15031c vmov r0, r1, d7
 *   @0x150320 vmov r2, s14
 *   @0x150324 mov r3, r1
 *   @0x150328 stm r5, {r2, r3}
 *   @0x15032c ldr r2, [sp, #0x11c]
 *   @0x150330 ldr r3, [r7]
 *   @0x150334 cmp r2, r3
 *   @0x150338 bne 0x150414 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x15033c add sp, sp, #292
 *   @0x150340 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x150344 ldr r3, [pc, #0xd4]
 *   @0x150348 ldr r3, [r6, r3]
 *   @0x15034c ldr r3, [r3]
 *   @0x150350 ldr r3, [r3, #0xb4]
 *   @0x150354 cmp r3, #0
 *   @0x150358 beq 0x150370 <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x194>
 *   @0x15035c ldr r0, [pc, #0xc0]
 *   @0x150360 mov r1, #0
 *   @0x150364 add r0, pc, r0
 *   @0x150368 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x15036c b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x150370 ldr r0, [pc, #0xb0]
 *   @0x150374 mov r1, #0
 *   @0x150378 add r0, pc, r0
 *   @0x15037c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x150380 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x150384 add r5, sp, #28
 *   @0x150388 mov r1, r10
 *   @0x15038c mov r2, #256
 *   @0x150390 mov r0, r5
 *   @0x150394 bl 0xb65b0 <memset@plt>
 *   @0x150398 mov r1, r10
 *   @0x15039c mov r0, r4
 *   @0x1503a0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1503a4 ldr r2, [pc, #0x80]
 *   @0x1503a8 mov r1, #256
 *   @0x1503ac add r2, pc, r2
 *   @0x1503b0 mov r3, r0
 *   @0x1503b4 mov r0, r5
 *   @0x1503b8 bl 0xb65c8 <snprintf@plt>
 *   @0x1503bc mov r0, r5
 *   @0x1503c0 mov r1, r10
 *   @0x1503c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x1503c8 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x1503cc add r5, sp, #28
 *   @0x1503d0 mov r1, r9
 *   @0x1503d4 mov r2, #256
 *   @0x1503d8 mov r0, r5
 *   @0x1503dc bl 0xb65b0 <memset@plt>
 *   @0x1503e0 mov r0, r4
 *   @0x1503e4 mov r1, #1
 *   @0x1503e8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1503ec ldr r2, [pc, #0x3c]
 *   @0x1503f0 mov r1, #256
 *   @0x1503f4 add r2, pc, r2
 *   @0x1503f8 mov r3, r0
 *   @0x1503fc mov r0, r5
 *   @0x150400 bl 0xb65c8 <snprintf@plt>
 *   @0x150404 mov r0, r5
 *   @0x150408 mov r1, r9
 *   @0x15040c bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x150410 b 0x15032c <_Z28F_PhysicsCreateFrictionJointR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x150414 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x150418 eoreq r1, r10, r12, asr r10
 *   @0x15041c .word 0xffffbd00
 *   @0x150420 .word 0xffffbcd8
 *   @0x150424 ldrsbeq r4, [pc], -r8
 *   @0x150428 andseq r3, pc, r12, lsr #21
 *   @0x15042c ldrsheq r4, [pc], -r4
 *   @0x150430 andseq r4, pc, r12, lsr #19
 *
 * ══ §39/50 GR_Texture_Draw_Part_Color(int, float, float, float, float, float, float, float, float, float, unsigned int, unsigned int, unsigned int, unsigned int, float)  0x175834  size 600  150 条（0x175834..0x175a8c）
 * @func 0x175834 0x175a8c  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6580 / 0xb658c
 * 字段偏移 top8: 0x68×2 / 0x6c×2 / 0x208×1 / 0x4×1 / 0x2×1 / 0x110×1 / 0x60×1 / 0x64×1
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x175834 push {r4, r5, r6, r7, r8, lr}
 *   @0x175838 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x17583c mov r4, r0
 *   @0x175840 vldr s18, [sp, #72]
 *   @0x175844 vmov s20, r1
 *   @0x175848 vldr s21, [sp, #76]
 *   @0x17584c vmov s17, r2
 *   @0x175850 vldr s22, [sp, #80]
 *   @0x175854 vmov s19, r3
 *   @0x175858 vldr s23, [sp, #92]
 *   @0x17585c bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x175860 subs r6, r0, #0
 *   @0x175864 beq 0x175a28 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x1f4>
 *   @0x175868 vldr s14, [sp, #112]
 *   @0x17586c vldr s15, [pc, #516]
 *   @0x175870 vmul.f32 s15, s14, s15
 *   @0x175874 ldr r1, [pc, #0x208]
 *   @0x175878 mov r0, #4
 *   @0x17587c mov r2, #24
 *   @0x175880 ldr r1, [pc, r1]
 *   @0x175884 mov r3, #6
 *   @0x175888 vldr s16, [pc, #492]
 *   @0x17588c ldr r1, [r1, #0x4]
 *   @0x175890 ldr r5, [r1, r4, lsl #2]
 *   @0x175894 ldr r1, [r5]
 *   @0x175898 vcvt.s32.f32 s15, s15
 *   @0x17589c vmov r7, s15
 *   @0x1758a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1758a4 vabs.f32 s14, s23
 *   @0x1758a8 vldr s15, [pc, #464]
 *   @0x1758ac vmov.f32 s25, s16
 *   @0x1758b0 vcmpe.f32 s14, s15
 *   @0x1758b4 vldr s15, [sp, #84]
 *   @0x1758b8 vldr s14, [sp, #88]
 *   @0x1758bc vmov.f32 s24, s16
 *   @0x1758c0 vmrs APSR_nzcv, fpscr
 *   @0x1758c4 vmla.f32 s25, s15, s19
 *   @0x1758c8 usat r7, #0x8, r7
 *   @0x1758cc mov r4, r0
 *   @0x1758d0 vmla.f32 s24, s14, s18
 *   @0x1758d4 bmi 0x175a34 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x200>
 *   @0x1758d8 vmov r0, s23
 *   @0x1758dc bl 0xb6580 <sinf@plt>
 *   @0x1758e0 vmov s26, r0
 *   @0x1758e4 vmov r0, s23
 *   @0x1758e8 bl 0xb658c <cosf@plt>
 *   @0x1758ec vmov.f32 s12, s22
 *   @0x1758f0 vmov.f32 s13, s21
 *   @0x1758f4 vmul.f32 s15, s26, s16
 *   @0x1758f8 vmls.f32 s12, s25, s26
 *   @0x1758fc vmov s14, r0
 *   @0x175900 vmul.f32 s16, s14, s16
 *   @0x175904 vmla.f32 s13, s25, s14
 *   @0x175908 vmul.f32 s26, s24, s26
 *   @0x17590c vmul.f32 s14, s24, s14
 *   @0x175910 vsub.f32 s22, s22, s15
 *   @0x175914 vadd.f32 s21, s21, s16
 *   @0x175918 vadd.f32 s11, s16, s22
 *   @0x17591c vadd.f32 s22, s14, s22
 *   @0x175920 vstr s11, [r4, #4]
 *   @0x175924 vstr s11, [r4, #124]
 *   @0x175928 vadd.f32 s14, s14, s12
 *   @0x17592c vstr s22, [r4, #100]
 *   @0x175930 vadd.f32 s16, s16, s12
 *   @0x175934 vstr s14, [r4, #52]
 *   @0x175938 vstr s14, [r4, #76]
 *   @0x17593c vadd.f32 s12, s15, s21
 *   @0x175940 vstr s16, [r4, #28]
 *   @0x175944 vadd.f32 s21, s26, s21
 *   @0x175948 vstr s12, [r4]
 *   @0x17594c vstr s12, [r4, #120]
 *   @0x175950 vadd.f32 s26, s26, s13
 *   @0x175954 vstr s21, [r4, #96]
 *   @0x175958 vadd.f32 s15, s15, s13
 *   @0x17595c vstr s26, [r4, #48]
 *   @0x175960 vstr s26, [r4, #72]
 *   @0x175964 vstr s15, [r4, #24]
 *   @0x175968 vldr s14, [r5, #8]
 *   @0x17596c vmul.f32 s12, s14, s20
 *   @0x175970 ldr r3, [pc, #0x110]
 *   @0x175974 lsl r2, r7, #24
 *   @0x175978 ldr r0, [sp, #0x60]
 *   @0x17597c ldr r8, [sp, #0x64]
 *   @0x175980 ldr r3, [pc, r3]
 *   @0x175984 bic r1, r0, #-16777216
 *   @0x175988 ldr r0, [sp, #0x68]
 *   @0x17598c ldr r3, [r3]
 *   @0x175990 bic r7, r8, #-16777216
 *   @0x175994 ldr r8, [sp, #0x6c]
 *   @0x175998 bic r12, r0, #-16777216
 *   @0x17599c orr r1, r2, r1
 *   @0x1759a0 str r1, [r4, #0x84]
 *   @0x1759a4 bic r0, r8, #-16777216
 *   @0x1759a8 str r3, [r4, #0x80]
 *   @0x1759ac str r3, [r4, #0x68]
 *   @0x1759b0 str r3, [r4, #0x50]
 *   @0x1759b4 str r3, [r4, #0x38]
 *   @0x1759b8 vadd.f32 s13, s20, s19
 *   @0x1759bc vstr s12, [r4, #136]
 *   @0x1759c0 vstr s12, [r4, #112]
 *   @0x1759c4 vstr s12, [r4, #16]
 *   @0x1759c8 vldr s12, [r5, #12]
 *   @0x1759cc str r3, [r4, #0x20]
 *   @0x1759d0 str r3, [r4, #0x8]
 *   @0x1759d4 orr r3, r2, r12
 *   @0x1759d8 str r1, [r4, #0xc]
 *   @0x1759dc orr r1, r2, r7
 *   @0x1759e0 str r3, [r4, #0x54]
 *   @0x1759e4 orr r2, r2, r0
 *   @0x1759e8 str r1, [r4, #0x24]
 *   @0x1759ec str r3, [r4, #0x3c]
 *   @0x1759f0 str r2, [r4, #0x6c]
 *   @0x1759f4 vadd.f32 s15, s17, s18
 *   @0x1759f8 vmul.f32 s13, s14, s13
 *   @0x1759fc vmul.f32 s15, s12, s15
 *   @0x175a00 vstr s13, [r4, #88]
 *   @0x175a04 vstr s13, [r4, #64]
 *   @0x175a08 vstr s13, [r4, #40]
 *   @0x175a0c vmul.f32 s14, s12, s17
 *   @0x175a10 vstr s15, [r4, #116]
 *   @0x175a14 vstr s15, [r4, #92]
 *   @0x175a18 vstr s15, [r4, #68]
 *   @0x175a1c vstr s14, [r4, #140]
 *   @0x175a20 vstr s14, [r4, #44]
 *   @0x175a24 vstr s14, [r4, #20]
 *   @0x175a28 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x175a2c mov r0, r6
 *   @0x175a30 pop {r4, r5, r6, r7, r8, pc}
 *   @0x175a34 vadd.f32 s25, s21, s25
 *   @0x175a38 vadd.f32 s21, s21, s16
 *   @0x175a3c vstr s25, [r0, #48]
 *   @0x175a40 vstr s25, [r0, #72]
 *   @0x175a44 vstr s25, [r0, #24]
 *   @0x175a48 vadd.f32 s16, s22, s16
 *   @0x175a4c vstr s21, [r0]
 *   @0x175a50 vstr s21, [r0, #120]
 *   @0x175a54 vstr s21, [r0, #96]
 *   @0x175a58 vadd.f32 s22, s22, s24
 *   @0x175a5c vstr s16, [r0, #28]
 *   @0x175a60 vstr s16, [r0, #4]
 *   @0x175a64 vstr s16, [r0, #124]
 *   @0x175a68 vstr s22, [r0, #100]
 *   @0x175a6c vstr s22, [r0, #52]
 *   @0x175a70 vstr s22, [r0, #76]
 *   @0x175a74 b 0x175968 <_Z26GR_Texture_Draw_Part_Colorifffffffffjjjjf+0x134>
 *   @0x175a78 cmnmi pc, #0
 *   @0x175a7c andeq r0, r0, r0
 *   @0x175a80 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x175a84 mlaeq r7, r12, r0, r8
 *   @0x175a88 eoreq r7, r7, r0, lsr #31
 *
 * ══ §40/50 res0_look  0x22e1d8  size 600  150 条（0x22e1d8..0x22e430）
 * @func 0x22e1d8 0x22e430  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c34×3 / __divsi3×3 / 0xb6544×2 / res0_look+0x158 / res0_look+0x10c / res0_look+0x18c / res0_look+0x24c / res0_look+0x234
 * 字段偏移 top8: 0x4×8 / 0x10×8 / 0x18×8 / 0x1c×7 / 0xc×5 / 0x2×5 / 0x14×4 / 0x8×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22e1d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22e1dc mov r6, r0
 *   @0x22e1e0 sub sp, sp, #36
 *   @0x22e1e4 mov r5, r1
 *   @0x22e1e8 mov r0, #1
 *   @0x22e1ec mov r1, #36
 *   @0x22e1f0 mov r11, r2
 *   @0x22e1f4 bl 0xb6c34 <calloc@plt>
 *   @0x22e1f8 ldr r3, [r6, #0x4]
 *   @0x22e1fc mov r4, #52
 *   @0x22e200 ldr r12, [r11, #0x14]
 *   @0x22e204 mov r1, #4
 *   @0x22e208 ldr lr, [r5, #0xc]
 *   @0x22e20c ldr r3, [r3, #0x1c]
 *   @0x22e210 mul r12, r4, r12
 *   @0x22e214 ldr r10, [r11, #0xc]
 *   @0x22e218 ldr r2, [r3, #0xc20]
 *   @0x22e21c str r10, [sp, #0x1c]
 *   @0x22e220 mov r8, r0
 *   @0x22e224 mov r0, r10
 *   @0x22e228 str lr, [r8, #0x4]
 *   @0x22e22c add lr, r2, r12
 *   @0x22e230 ldr r12, [r2, r12]
 *   @0x22e234 str r2, [r8, #0x10]
 *   @0x22e238 str r3, [sp, #0x4]
 *   @0x22e23c str r11, [r8]
 *   @0x22e240 str lr, [r8, #0x14]
 *   @0x22e244 str r12, [sp, #0x18]
 *   @0x22e248 str r10, [r8, #0x8]
 *   @0x22e24c bl 0xb6c34 <calloc@plt>
 *   @0x22e250 cmp r10, #0
 *   @0x22e254 mov r2, #0
 *   @0x22e258 ldr r3, [sp, #0x4]
 *   @0x22e25c str r2, [sp, #0x10]
 *   @0x22e260 str r0, [r8, #0x18]
 *   @0x22e264 ble 0x22e330 <res0_look+0x158>
 *   @0x22e268 add r12, r11, #20
 *   @0x22e26c mov r6, #0
 *   @0x22e270 str r10, [sp, #0x14]
 *   @0x22e274 mov r2, r4
 *   @0x22e278 mov r10, r3
 *   @0x22e27c mov r9, r6
 *   @0x22e280 mov r3, r12
 *   @0x22e284 ldr r7, [r3, #0x4]!
 *   @0x22e288 cmp r7, #0
 *   @0x22e28c mov r4, r7
 *   @0x22e290 beq 0x22e31c <res0_look+0x144>
 *   @0x22e294 mov r5, #0
 *   @0x22e298 lsrs r4, r4, #1
 *   @0x22e29c add r5, r5, #1
 *   @0x22e2a0 bne 0x22e298 <res0_look+0xc0>
 *   @0x22e2a4 ldr r12, [r8, #0x18]
 *   @0x22e2a8 mov r1, #4
 *   @0x22e2ac mov r0, r5
 *   @0x22e2b0 str r2, [sp, #0x8]
 *   @0x22e2b4 str r3, [sp, #0x4]
 *   @0x22e2b8 str r12, [sp, #0xc]
 *   @0x22e2bc bl 0xb6c34 <calloc@plt>
 *   @0x22e2c0 ldr r1, [sp, #0x10]
 *   @0x22e2c4 ldr r12, [sp, #0xc]
 *   @0x22e2c8 ldr r3, [sp, #0x4]
 *   @0x22e2cc cmp r1, r5
 *   @0x22e2d0 movlt r1, r5
 *   @0x22e2d4 ldr r2, [sp, #0x8]
 *   @0x22e2d8 str r1, [sp, #0x10]
 *   @0x22e2dc lsl r1, r9, #2
 *   @0x22e2e0 str r0, [r12, r9, lsl #2]
 *   @0x22e2e4 asr r0, r7, r4
 *   @0x22e2e8 add r12, r6, #70
 *   @0x22e2ec tst r0, #1
 *   @0x22e2f0 beq 0x22e310 <res0_look+0x138>
 *   @0x22e2f4 ldr lr, [r11, r12, lsl #2]
 *   @0x22e2f8 add r6, r6, #1
 *   @0x22e2fc ldr r12, [r10, #0xc20]
 *   @0x22e300 ldr r0, [r8, #0x18]
 *   @0x22e304 mla r12, r2, lr, r12
 *   @0x22e308 ldr r0, [r0, r1]
 *   @0x22e30c str r12, [r0, r4, lsl #2]
 *   @0x22e310 add r4, r4, #1
 *   @0x22e314 cmp r4, r5
 *   @0x22e318 blt 0x22e2e4 <res0_look+0x10c>
 *   @0x22e31c ldr r1, [sp, #0x14]
 *   @0x22e320 add r9, r9, #1
 *   @0x22e324 cmp r9, r1
 *   @0x22e328 bne 0x22e284 <res0_look+0xac>
 *   @0x22e32c mov r10, r1
 *   @0x22e330 ldr r3, [sp, #0x18]
 *   @0x22e334 mov r4, r10
 *   @0x22e338 str r10, [r8, #0x1c]
 *   @0x22e33c cmp r3, #1
 *   @0x22e340 ble 0x22e364 <res0_look+0x18c>
 *   @0x22e344 ldr r2, [sp, #0x18]
 *   @0x22e348 mov r3, #1
 *   @0x22e34c add r3, r3, #1
 *   @0x22e350 cmp r3, r2
 *   @0x22e354 mul r4, r10, r4
 *   @0x22e358 bne 0x22e34c <res0_look+0x174>
 *   @0x22e35c str r4, [r8, #0x1c]
 *   @0x22e360 str r4, [sp, #0x1c]
 *   @0x22e364 ldr r2, [sp, #0x1c]
 *   @0x22e368 ldr r3, [sp, #0x10]
 *   @0x22e36c lsl r0, r2, #2
 *   @0x22e370 str r3, [r8, #0xc]
 *   @0x22e374 bl 0xb6544 <malloc@plt>
 *   @0x22e378 cmp r4, #0
 *   @0x22e37c str r0, [r8, #0x20]
 *   @0x22e380 ble 0x22e424 <res0_look+0x24c>
 *   @0x22e384 ldr r2, [sp, #0x18]
 *   @0x22e388 mov r5, r0
 *   @0x22e38c mov r7, #0
 *   @0x22e390 mov r0, r4
 *   @0x22e394 lsl r2, r2, #2
 *   @0x22e398 str r2, [sp, #0x10]
 *   @0x22e39c mov r1, r10
 *   @0x22e3a0 bl 0x318d10 <__divsi3>
 *   @0x22e3a4 mov r4, r0
 *   @0x22e3a8 ldr r0, [sp, #0x10]
 *   @0x22e3ac bl 0xb6544 <malloc@plt>
 *   @0x22e3b0 ldr r3, [sp, #0x18]
 *   @0x22e3b4 cmp r3, #0
 *   @0x22e3b8 str r0, [r5, r7, lsl #2]
 *   @0x22e3bc ble 0x22e40c <res0_look+0x234>
 *   @0x22e3c0 ldr r3, [r8, #0x20]
 *   @0x22e3c4 mov r5, r7
 *   @0x22e3c8 ldr r2, [sp, #0x10]
 *   @0x22e3cc ldr r11, [r3, r7, lsl #2]
 *   @0x22e3d0 add r6, r11, r2
 *   @0x22e3d4 b 0x22e3dc <res0_look+0x204>
 *   @0x22e3d8 ldr r10, [r8, #0x8]
 *   @0x22e3dc mov r1, r4
 *   @0x22e3e0 mov r0, r5
 *   @0x22e3e4 bl 0x318d10 <__divsi3>
 *   @0x22e3e8 mov r1, r10
 *   @0x22e3ec mov r9, r0
 *   @0x22e3f0 mov r0, r4
 *   @0x22e3f4 bl 0x318d10 <__divsi3>
 *   @0x22e3f8 str r9, [r11], #4
 *   @0x22e3fc cmp r11, r6
 *   @0x22e400 mls r5, r4, r9, r5
 *   @0x22e404 mov r4, r0
 *   @0x22e408 bne 0x22e3d8 <res0_look+0x200>
 *   @0x22e40c ldr r0, [r8, #0x1c]
 *   @0x22e410 add r7, r7, #1
 *   @0x22e414 cmp r0, r7
 *   @0x22e418 ldrgt r10, [r8, #0x8]
 *   @0x22e41c ldrgt r5, [r8, #0x20]
 *   @0x22e420 bgt 0x22e39c <res0_look+0x1c4>
 *   @0x22e424 mov r0, r8
 *   @0x22e428 add sp, sp, #36
 *   @0x22e42c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §41/50 JS_Array_prototype_map(RValue&, CInstance*, CInstance*, int, RValue*)  0x2518a8  size 600  150 条（0x2518a8..0x251b00）
 * @func 0x2518a8 0x251b00  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYObjectBase::InternalGetYYVar(int)×4 / JSThrowTypeError(char const*)×2 / _itoa(int, char*, int)×2 / JS_Array_Put(YYObjectBase*, RValue*, char const*)×2 / JS_Array_prototype_map(RValue&, CInstance*, CInstance*, int, RValue*)+0x78 / JS_IsCallable(RValue&) / F_JSNewArray_NoArguments(RValue&, CInstance*, CInstance*, int, RValue*) / Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 * 字段偏移 top8: 0xc×6 / 0x1c×4 / 0x4×4 / 0x10×4 / 0x14×3 / 0xe4×2 / 0x244×1 / 0x110×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2518a8 ldr r12, [pc, #0x244]
 *   @0x2518ac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2518b0 sub sp, sp, #236
 *   @0x2518b4 mov r4, r1
 *   @0x2518b8 mov r5, r3
 *   @0x2518bc str r12, [sp, #0x1c]
 *   @0x2518c0 mov r6, r2
 *   @0x2518c4 ldr r12, [r1, #0x4]
 *   @0x2518c8 mov r2, #5
 *   @0x2518cc ldr r1, [sp, #0x1c]
 *   @0x2518d0 cmp r12, #0
 *   @0x2518d4 str r0, [sp, #0xc]
 *   @0x2518d8 ldr r1, [pc, r1]
 *   @0x2518dc str r1, [sp, #0x1c]
 *   @0x2518e0 str r2, [r0, #0xc]
 *   @0x2518e4 ldr r3, [r1]
 *   @0x2518e8 ldr r1, [sp, #0x110]
 *   @0x2518ec str r3, [sp, #0xe4]
 *   @0x2518f0 str r1, [sp, #0x10]
 *   @0x2518f4 beq 0x251ae0 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x238>
 *   @0x2518f8 add r0, r12, #16
 *   @0x2518fc ldr r7, [r0]
 *   @0x251900 cmp r5, #0
 *   @0x251904 ldr r12, [r7, #0x24]
 *   @0x251908 str r12, [sp, #0x14]
 *   @0x25190c ble 0x251920 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x78>
 *   @0x251910 ldr r0, [sp, #0x10]
 *   @0x251914 bl 0x24076c <_Z13JS_IsCallableR6RValue>
 *   @0x251918 cmp r0, #0
 *   @0x25191c bne 0x251948 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0xa0>
 *   @0x251920 ldr r0, [pc, #0x1d0]
 *   @0x251924 add r0, pc, r0
 *   @0x251928 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x25192c ldr r12, [sp, #0x1c]
 *   @0x251930 ldr r2, [sp, #0xe4]
 *   @0x251934 ldr r3, [r12]
 *   @0x251938 cmp r2, r3
 *   @0x25193c bne 0x251af0 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x248>
 *   @0x251940 add sp, sp, #236
 *   @0x251944 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x251948 cmp r5, #1
 *   @0x25194c moveq r12, #0
 *   @0x251950 streq r12, [sp, #0x18]
 *   @0x251954 ldrne r12, [sp, #0x10]
 *   @0x251958 ldrne r12, [r12, #0x10]
 *   @0x25195c strne r12, [sp, #0x18]
 *   @0x251960 ldr r12, [sp, #0x10]
 *   @0x251964 mov r1, r4
 *   @0x251968 mov r2, r6
 *   @0x25196c ldr r0, [sp, #0xc]
 *   @0x251970 mov r3, #0
 *   @0x251974 str r12, [sp]
 *   @0x251978 bl 0x242c84 <_Z24F_JSNewArray_NoArgumentsR6RValueP9CInstanceS2_iPS_>
 *   @0x25197c ldr r12, [sp, #0x14]
 *   @0x251980 cmp r12, #0
 *   @0x251984 beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251988 mov r6, #0
 *   @0x25198c add r9, sp, #100
 *   @0x251990 add r5, sp, #52
 *   @0x251994 mov r4, r6
 *   @0x251998 b 0x251a40 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x25199c ldr r0, [r7, #0x4]
 *   @0x2519a0 cmp r0, #0
 *   @0x2519a4 beq 0x251aac <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x204>
 *   @0x2519a8 add r0, r0, r6
 *   @0x2519ac vmov s15, r4
 *   @0x2519b0 add r8, sp, #36
 *   @0x2519b4 ldm r0, {r0, r1, r2, r3}
 *   @0x2519b8 vcvt.f64.u32 d7, s15
 *   @0x2519bc str r5, [sp]
 *   @0x2519c0 mov r12, #0
 *   @0x2519c4 str r12, [sp, #0x50]
 *   @0x2519c8 mov r12, #6
 *   @0x2519cc str r12, [sp, #0x60]
 *   @0x2519d0 stm r5, {r0, r1, r2, r3}
 *   @0x2519d4 mov r1, r8
 *   @0x2519d8 ldr r0, [sp, #0x18]
 *   @0x2519dc mov r3, #3
 *   @0x2519e0 vmov r10, r11, d7
 *   @0x2519e4 vstr s14, [sp, #68]
 *   @0x2519e8 ldr r2, [sp, #0x10]
 *   @0x2519ec str r7, [sp, #0x54]
 *   @0x2519f0 str r11, [sp, #0x48]
 *   @0x2519f4 bl 0x249860 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_>
 *   @0x2519f8 cmp r0, #2
 *   @0x2519fc beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251a00 cmp r0, #1
 *   @0x251a04 beq 0x251abc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x214>
 *   @0x251a08 mov r1, r9
 *   @0x251a0c mov r2, #10
 *   @0x251a10 mov r0, r4
 *   @0x251a14 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x251a18 ldr r12, [sp, #0xc]
 *   @0x251a1c mov r1, r8
 *   @0x251a20 mov r2, r9
 *   @0x251a24 ldr r0, [r12]
 *   @0x251a28 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x251a2c ldr r12, [sp, #0x14]
 *   @0x251a30 add r4, r4, #1
 *   @0x251a34 add r6, r6, #16
 *   @0x251a38 cmp r4, r12
 *   @0x251a3c beq 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251a40 ldr r0, [r7, #0x4]
 *   @0x251a44 cmp r0, #0
 *   @0x251a48 beq 0x251a9c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1f4>
 *   @0x251a4c add r0, r0, r6
 *   @0x251a50 ldr r3, [r0, #0xc]
 *   @0x251a54 mvn r1, #-16777216
 *   @0x251a58 bic r3, r3, #-16777216
 *   @0x251a5c cmp r3, r1
 *   @0x251a60 bne 0x25199c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0xf4>
 *   @0x251a64 mov r1, r9
 *   @0x251a68 mov r0, r4
 *   @0x251a6c mov r2, #10
 *   @0x251a70 bl 0xc4964 <_Z5_itoaiPci>
 *   @0x251a74 ldr r1, [r7, #0x4]
 *   @0x251a78 ldr r12, [sp, #0xc]
 *   @0x251a7c cmp r1, #0
 *   @0x251a80 ldr r8, [r12]
 *   @0x251a84 beq 0x251acc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x251a88 add r1, r1, r6
 *   @0x251a8c mov r0, r8
 *   @0x251a90 mov r2, r9
 *   @0x251a94 bl 0x24861c <_Z12JS_Array_PutP12YYObjectBaseP6RValuePKc>
 *   @0x251a98 b 0x251a2c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x184>
 *   @0x251a9c mov r0, r7
 *   @0x251aa0 mov r1, r4
 *   @0x251aa4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251aa8 b 0x251a50 <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1a8>
 *   @0x251aac mov r0, r7
 *   @0x251ab0 mov r1, r4
 *   @0x251ab4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251ab8 b 0x2519ac <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x251abc ldr r0, [pc, #0x38]
 *   @0x251ac0 add r0, pc, r0
 *   @0x251ac4 bl 0x24e58c <_Z16JSThrowTypeErrorPKc>
 *   @0x251ac8 b 0x25192c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x84>
 *   @0x251acc mov r1, r4
 *   @0x251ad0 mov r0, r7
 *   @0x251ad4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251ad8 mov r1, r0
 *   @0x251adc b 0x251a8c <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x1e4>
 *   @0x251ae0 mov r0, r4
 *   @0x251ae4 mov r1, #1
 *   @0x251ae8 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x251aec b 0x2518fc <_Z22JS_Array_prototype_mapR6RValueP9CInstanceS2_iPS_+0x54>
 *   @0x251af0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x251af4 andseq r12, r9, r8, ror r0
 *   @0x251af8 andseq r4, r0, r4, ror r10
 *   @0x251afc mulseq r0, r8, r8
 *
 * ══ §42/50 anon_298fd0  0x298fd0  size 600  150 条（0x298fd0..0x299228）
 * @func 0x298fd0 0x299228  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x298fec→0x7578e9, 0x29905c→0x3f5230, 0x2990b8→0x75790c
 * 调用序列: Error_Show_Action(char const*, bool)×4 / YYGetInt32(RValue const*, int)×3 / anon_298fd0+0x1f8 / AllocSocket() / anon_298fd0+0x220 / operator new(unsigned int) / yyServer::yyServer(bool) / yyServer::Init(eSocketType, int, int, bool)
 * 字段偏移 top8: 0x8×6 / 0xc×4 / 0x4×2 / 0x114×2 / 0x228×1 / 0x224×1 / 0x21c×1 / 0x1b0×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x298fd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x298fd4 mov r9, r2
 *   @0x298fd8 ldr r11, [pc, #0x228]
 *   @0x298fdc sub sp, sp, #284
 *   @0x298fe0 ldr r6, [pc, #0x224]
 *   @0x298fe4 mov r4, r0
 *   @0x298fe8 add r11, pc, r11
 *   @0x298fec ldr lr, [pc, #0x21c]
 *   @0x298ff0 mov r3, #0
 *   @0x298ff4 mov r0, #0
 *   @0x298ff8 ldr r6, [r11, r6]
 *   @0x298ffc movt r0, #0xbff0
 *   @0x299000 str r3, [r4, #0xc]
 *   @0x299004 mov r5, r1
 *   @0x299008 str r0, [r4, #0x4]
 *   @0x29900c ldr r2, [r6]
 *   @0x299010 str r6, [sp, #0x8]
 *   @0x299014 str r3, [r4]
 *   @0x299018 str r2, [sp, #0x114]
 *   @0x29901c ldr r7, [r11, lr]
 *   @0x299020 ldrb r3, [r7]
 *   @0x299024 cmp r3, #0
 *   @0x299028 beq 0x299174 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2e0>
 *   @0x29902c mov r0, r5
 *   @0x299030 mov r1, #2
 *   @0x299034 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x299038 movw r2, #0x3f6
 *   @0x29903c cmp r0, r2
 *   @0x299040 mov r6, r0
 *   @0x299044 bgt 0x299184 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2f0>
 *   @0x299048 cmp r0, #0
 *   @0x29904c ble 0x2991c8 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x334>
 *   @0x299050 mov r0, r5
 *   @0x299054 mov r1, #0
 *   @0x299058 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x29905c ldr r2, [pc, #0x1b0]
 *   @0x299060 ldr r10, [r11, r2]
 *   @0x299064 ldr r2, [r10]
 *   @0x299068 sub r2, r2, #2
 *   @0x29906c cmp r2, #2
 *   @0x299070 mov r8, r0
 *   @0x299074 bhi 0x299168 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2d4>
 *   @0x299078 cmp r0, #2
 *   @0x29907c beq 0x2991dc <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x348>
 *   @0x299080 bl 0x298e28 <_Z11AllocSocketv>
 *   @0x299084 subs r7, r0, #0
 *   @0x299088 blt 0x2991f0 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x35c>
 *   @0x29908c ldr r2, [r10]
 *   @0x299090 mov r0, #44
 *   @0x299094 lsl r3, r7, #1
 *   @0x299098 str r3, [sp, #0xc]
 *   @0x29909c sub r2, r2, #2
 *   @0x2990a0 cmp r2, #2
 *   @0x2990a4 movhi r6, #1
 *   @0x2990a8 bl 0x27c524 <_Znwj>
 *   @0x2990ac mov r1, r9
 *   @0x2990b0 mov r10, r0
 *   @0x2990b4 bl 0x2970f8 <_ZN8yyServerC2Eb>
 *   @0x2990b8 ldr r2, [pc, #0x158]
 *   @0x2990bc mov r0, r5
 *   @0x2990c0 ldr r1, [sp, #0xc]
 *   @0x2990c4 ldr r5, [r11, r2]
 *   @0x2990c8 add r9, r1, r7
 *   @0x2990cc mov r1, #1
 *   @0x2990d0 add r9, r5, r9, lsl #2
 *   @0x2990d4 str r10, [r9, #0x8]
 *   @0x2990d8 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x2990dc mov r12, #0
 *   @0x2990e0 mov r3, r6
 *   @0x2990e4 mov r1, r8
 *   @0x2990e8 str r12, [sp]
 *   @0x2990ec mov r2, r0
 *   @0x2990f0 mov r0, r10
 *   @0x2990f4 bl 0x2971e0 <_ZN8yyServer4InitE11eSocketTypeiib>
 *   @0x2990f8 cmp r0, #0
 *   @0x2990fc bge 0x2991a8 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x314>
 *   @0x299100 ldr r8, [r9, #0x8]
 *   @0x299104 cmp r8, #0
 *   @0x299108 beq 0x29911c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x288>
 *   @0x29910c mov r0, r8
 *   @0x299110 bl 0x297184 <_ZN8yyServerD2Ev>
 *   @0x299114 mov r0, r8
 *   @0x299118 bl 0x27d1d0 <_ZdlPv>
 *   @0x29911c ldr r3, [sp, #0xc]
 *   @0x299120 add r7, r3, r7
 *   @0x299124 mov r3, #0
 *   @0x299128 mov r1, r3
 *   @0x29912c movt r1, #0xbff0
 *   @0x299130 lsl r7, r7, #2
 *   @0x299134 add r0, r5, r7
 *   @0x299138 str r3, [r0, #0x8]
 *   @0x29913c strb r3, [r5, r7]
 *   @0x299140 strb r3, [r0, #0x1]
 *   @0x299144 str r3, [r4]
 *   @0x299148 str r1, [r4, #0x4]
 *   @0x29914c ldr r1, [sp, #0x8]
 *   @0x299150 ldr r2, [sp, #0x114]
 *   @0x299154 ldr r3, [r1]
 *   @0x299158 cmp r2, r3
 *   @0x29915c bne 0x299204 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x370>
 *   @0x299160 add sp, sp, #284
 *   @0x299164 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x299168 cmp r0, #0
 *   @0x29916c beq 0x299080 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x299170 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x299174 bl 0x294d18 <_ZN8yySocket7StartupEv>
 *   @0x299178 mov r3, #1
 *   @0x29917c strb r3, [r7]
 *   @0x299180 b 0x29902c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x299184 add r4, sp, #20
 *   @0x299188 ldr r1, [pc, #0x8c]
 *   @0x29918c mov r0, r4
 *   @0x299190 add r1, pc, r1
 *   @0x299194 bl 0xb6550 <sprintf@plt>
 *   @0x299198 mov r0, r4
 *   @0x29919c mov r1, #0
 *   @0x2991a0 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2991a4 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x2991a8 ldr r0, [r9, #0x8]
 *   @0x2991ac mov r1, r7
 *   @0x2991b0 bl 0x297558 <_ZN8yyServer11SetSocketIDEi>
 *   @0x2991b4 vmov s15, r7
 *   @0x2991b8 vcvt.f64.s32 d7, s15
 *   @0x2991bc vmov r2, r3, d7
 *   @0x2991c0 stm r4, {r2, r3}
 *   @0x2991c4 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x2991c8 ldr r0, [pc, #0x50]
 *   @0x2991cc mov r1, #0
 *   @0x2991d0 add r0, pc, r0
 *   @0x2991d4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2991d8 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x2991dc ldr r0, [pc, #0x40]
 *   @0x2991e0 mov r1, #0
 *   @0x2991e4 add r0, pc, r0
 *   @0x2991e8 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x2991ec b 0x299080 <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x1ec>
 *   @0x2991f0 ldr r0, [pc, #0x30]
 *   @0x2991f4 mov r1, #0
 *   @0x2991f8 add r0, pc, r0
 *   @0x2991fc bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0x299200 b 0x29914c <_Z23F_NETWORK_Create_SocketR6RValueP9CInstanceS2_iPS_+0x2b8>
 *   @0x299204 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x299208 andseq r8, r5, r8, ror #24
 *   @0x29920c .word 0xffffbd00
 *   @0x299210 .word 0xfffffd4c
 *   @0x299214 .word 0xffffe6d0
 *   @0x299218 .word 0xfffffd54
 *   @0x29921c andeq r0, r12, r0, lsl #11
 *   @0x299220 andeq r0, r12, r12, lsl #11
 *   @0x299224 andeq r0, r12, r0, ror #9
 *
 * ══ §43/50 anon_2e7b5e  0x2e7b5e  size 600  150 条（0x2e7b5e..0x2e7db6）
 * @func 0x2e7b5e 0x2e7db6  size 600  150 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x538602 / 0xff525ba8 / 0x46667e / 0x466656 / anon_2f929c+0x182 / 0x6f9cb2 / 0x62fe1a / 0xc9477a
 * 字段偏移 top8: 0xa×1 / 0x6×1
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e7b5e stmdavs r3, {r2, r9, r10, lr}
 *   @0x2e7b62 stmvs r3, {r0, r2, r3, r4, r6, r9, r10, r11, sp, lr} ^
 *   @0x2e7b66 swplt r6, r11, [r3]
 *   @0x2e7b6a qadd8mi r4, r8, r8
 *   @0x2e7b6e pop {r0, r5, r9, r10, lr}
 *   @0x2e7b72 .word 0xf7ff4038
 *   @0x2e7b76 ldrblt r11, [r8, #0xbdf]!
 *   @0x2e7b7a strmi r4, [r4], -pc, lsl #12
 *   @0x2e7b7e strhs r11, [r0, #-0x1a8]
 *   @0x2e7b82 bvs 0x1bb9442 <b2_toiTime+0x145ff9e>
 *   @0x2e7b86 ble 0x538602 <obj_numb_event+0x1692>
 *   @0x2e7b8a .word 0xf8536aa3
 *   @0x2e7b8e .word 0xf7ff0025
 *   @0x2e7b92 bvs 0xfebe7b2a <b2_toiTime+0xfffffffffe48e686>
 *   @0x2e7b96 eorvs pc, r5, r3, asr #16
 *   @0x2e7b9a ldrb r3, [r2, r1, lsl #10]!
 *   @0x2e7b9e bvs 0xfeb39486 <b2_toiTime+0xfffffffffe3dffe2>
 *   @0x2e7ba2 blx 0xff525ba8 <b2_toiTime+0xfffffffffedcc704>
 *   @0x2e7ba6 adcvs r2, r3, #0, #6
 *   @0x2e7baa ldcllt p2, c6, [r8, #396]!
 *   @0x2e7bae .word 0xe92d0000
 *   @0x2e7bb2 strdlt r4, r5, [r7], r0
 *   @0x2e7bb6 .word 0xf10d68c7
 *   @0x2e7bba stmvs r5, {r2, r4, r9, r11}
 *   @0x2e7bbe andls r4, r3, #6291456
 *   @0x2e7bc2 ldrbmi r4, [r2], -r8, lsl #13
 *   @0x2e7bc6 qsub16mi r6, r8, r9
 *   @0x2e7bca .word 0xf8dd469b
 *   @0x2e7bce .word 0xf7ff9044
 *   @0x2e7bd2 bls 0x46667e <g_RomDisk+0x6ee5e>
 *   @0x2e7bd6 bhs 0x2f93ee <ps_hints_apply+0x7fee>
 *   @0x2e7bda strvs sp, [r6], -r12, asr #2
 *   @0x2e7bde .word 0xf8d86645
 *   @0x2e7be2 strvs r2, [r2], r0
 *   @0x2e7be6 tstlt r10, r3, lsl #20
 *   @0x2e7bea vst2.32 {d22, d23}, [r2], r2
 *   @0x2e7bee addvs r6, r2, r0, lsl #5
 *   @0x2e7bf2 .word 0x21444628
 *   @0x2e7bf6 .word 0xf7ff4652
 *   @0x2e7bfa blls 0x466656 <g_RomDisk+0x6ee36>
 *   @0x2e7bfe blhs 0x2f941e <ps_hints_apply+0x801e>
 *   @0x2e7c02 .word 0xf8c4d139
 *   @0x2e7c06 movtvs r0, #0x3080
 *   @0x2e7c0a bls 0x6f9cb2 <g_SWFvertbuff+0x26bea>
 *   @0x2e7c0e .word 0xf8d44293
 *   @0x2e7c12 ble 0x62fe1a <g_SWFaavertbuff+0x5cd52>
 *   @0x2e7c16 ldmdblt r9, {r0, r4, r6, r8, r9, r11, sp, lr} ^
 *   @0x2e7c1a eorsne pc, r3, r9, asr r8
 *   @0x2e7c1e vstmiaeq r3, {s29, s30, s31}
 *   @0x2e7c22 smlabble r3, r1, r2, r4
 *   @0x2e7c26 .word 0x010ceb09
 *   @0x2e7c2a cmpvs r1, #4784128
 *   @0x2e7c2e strb r3, [r12, r1, lsl #6]!
 *   @0x2e7c32 .word 0x33fff04f
 *   @0x2e7c36 .word 0xf8d763d3
 *   @0x2e7c3a .word 0xf1bcc030
 *   @0x2e7c3e andle r0, r8, r0, lsl #30
 *   @0x2e7c42 andls pc, r0, sp, asr #17
 *   @0x2e7c46 .word 0xf8d84621
 *   @0x2e7c4a ldrbmi r0, [r10], -r0
 *   @0x2e7c4e .word 0x47e09b10
 *   @0x2e7c52 cdpvs p0, #0xa, c9, c3, c5, #0x0
 *   @0x2e7c56 andlo pc, r0, r8, asr #17
 *   @0x2e7c5a stmdblt r3!, {r0, r2, r8, r9, r11, r12, pc} ^
 *   @0x2e7c5e .word 0xf7fc4620
 *   @0x2e7c62 smlawtlt r0, r12, lr, pc
 *   @0x2e7c66 blhs 0xc9477a <b2_toiTime+0x53b2d6>
 *   @0x2e7c6a andls sp, r5, r1
 *   @0x2e7c6e blls 0x79fc82 <b2_toiTime+0x467de>
 *   @0x2e7c72 and r6, r0, r12, lsl r0
 *   @0x2e7c76 blls 0x43147e <g_RomDisk+0x39c5e>
 *   @0x2e7c7a qadd8mi r11, r0, r3
 *   @0x2e7c7e .word 0xf7ff4629
 *   @0x2e7c82 blvs 0x21e7a72 <b2_toiTime+0x1a8e5ce>
 *   @0x2e7c86 strtmi r11, [r0], -r11, lsl #2
 *   @0x2e7c8a qadd8mi r4, r8, r8
 *   @0x2e7c8e .word 0xf7ff4631
 *   @0x2e7c92 qsaxmi pc, r8, r1
 *   @0x2e7c96 .word 0xf7ff4621
 *   @0x2e7c9a bls 0x7a69d6 <b2_toiTime+0x4d532>
 *   @0x2e7c9e andsvs r2, r3, r0, lsl #6
 *   @0x2e7ca2 andlt r9, r7, r5, lsl #16
 *   @0x2e7ca6 svchi #0xf0e8bd
 *   @0x2e7caa cmnvs r2, #0, #30
 *   @0x2e7cae ldrlt r6, [r0, #-0x96e]
 *   @0x2e7cb2 stmdavs r1!, {r2, r9, r10, lr}
 *   @0x2e7cb6 .word 0xf7ff69c0
 *   @0x2e7cba movwhs pc, #0xb3d
 *   @0x2e7cbe rsbvs r6, r3, r3, lsr #32
 *   @0x2e7cc2 ldclt p1, c6, [r0, #-652]
 *   @0x2e7cc6 ldrblt r0, [r8, #0x0]!
 *   @0x2e7cca stmdavs r6, {r0, r4, r9, r10, lr}
 *   @0x2e7cce bmi 0x5f94ea <g_SWFaavertbuff+0x26422>
 *   @0x2e7cd2 shadd16mi r4, r0, pc
 *   @0x2e7cd6 .word 0xf7ff447a
 *   @0x2e7cda strmi pc, [r4], -r6, asr #20
 *   @0x2e7cde qsub16mi r11, r8, r0
 *   @0x2e7ce2 bls 0x47956e <g_RomDisk+0x81d4e>
 *   @0x2e7ce6 blx 0xff565cec <b2_toiTime+0xfffffffffee0c848>
 *   @0x2e7cea stmdblt r8, {r0, r2, r9, r10, lr}
 *   @0x2e7cee and r6, r3, r12, lsr r0
 *   @0x2e7cf2 qasxmi r4, r1, r0
 *   @0x2e7cf6 blx 0xaa5cfc <b2_toiTime+0x34c858>
 *   @0x2e7cfa ldcllt p6, c4, [r8, #160]!
 *   @0x2e7cfe ldcllt p0, c2, [r8, #256]!
 *   @0x2e7d02 bvs 0xfe81790a <b2_toiTime+0xfffffffffe0be466>
 *   @0x2e7d06 ldrblt r0, [r8, #0xa]!
 *   @0x2e7d0a stmdavs r6, {r0, r4, r9, r10, lr}
 *   @0x2e7d0e bmi 0x5f952a <g_SWFaavertbuff+0x26462>
 *   @0x2e7d12 shadd16mi r4, r0, pc
 *   @0x2e7d16 .word 0xf7ff447a
 *   @0x2e7d1a strmi pc, [r4], -r6, lsr #20
 *   @0x2e7d1e qsub16mi r11, r8, r0
 *   @0x2e7d22 bls 0x4795ae <g_RomDisk+0x81d8e>
 *   @0x2e7d26 blx 0xfed65d2c <b2_toiTime+0xfffffffffe60c888>
 *   @0x2e7d2a stmdblt r8, {r0, r2, r9, r10, lr}
 *   @0x2e7d2e and r6, r3, r12, lsr r0
 *   @0x2e7d32 qasxmi r4, r1, r0
 *   @0x2e7d36 blx 0x2a5d3a <png_free_data+0x17a>
 *   @0x2e7d3a ldcllt p6, c4, [r8, #160]!
 *   @0x2e7d3e ldcllt p0, c2, [r8, #256]!
 *   @0x2e7d42 bvs 0x1b9794a <b2_toiTime+0x143e4a6>
 *   @0x2e7d46 ldrblt r0, [r8, #0xa]!
 *   @0x2e7d4a stmdavs r6, {r0, r4, r9, r10, lr}
 *   @0x2e7d4e bmi 0x5f956a <g_SWFaavertbuff+0x264a2>
 *   @0x2e7d52 shadd16mi r4, r0, pc
 *   @0x2e7d56 .word 0xf7ff447a
 *   @0x2e7d5a strmi pc, [r4], -r6, lsl #20
 *   @0x2e7d5e qsub16mi r11, r8, r0
 *   @0x2e7d62 bls 0x4795ee <g_RomDisk+0x81dce>
 *   @0x2e7d66 blx 0xfe565d6c <b2_toiTime+0xfffffffffde0c8c8>
 *   @0x2e7d6a stmdblt r8, {r0, r2, r9, r10, lr}
 *   @0x2e7d6e and r6, r3, r12, lsr r0
 *   @0x2e7d72 qasxmi r4, r1, r0
 *   @0x2e7d76 blx 0xffaa5d7a <b2_toiTime+0xffffffffff34c8d6>
 *   @0x2e7d7a ldcllt p6, c4, [r8, #160]!
 *   @0x2e7d7e ldcllt p0, c2, [r8, #256]!
 *   @0x2e7d82 bvs 0xc1798a <b2_toiTime+0x4be4e6>
 *   @0x2e7d86 ldrblt r0, [r0, #-0xa]!
 *   @0x2e7d8a stmvs r11, {r0, r2, r9, r10, lr}
 *   @0x2e7d8e ldrmi r4, [r6], -r12, lsl #12
 *   @0x2e7d92 strmi r11, [r8], -r11, lsl #2
 *   @0x2e7d96 ldmvs r3!, {r3, r4, r7, r8, r9, r10, lr} ^
 *   @0x2e7d9a ldrdlt r6, r7, [r11, -r11]
 *   @0x2e7d9e ldrmi r4, [r8, r0, lsr #12]
 *   @0x2e7da2 bvs 0xfeb3964a <b2_toiTime+0xfffffffffe3e01a6>
 *   @0x2e7da6 blx 0xff4a5daa <b2_toiTime+0xfffffffffed4c906>
 *   @0x2e7daa strtmi r2, [r8], -r0, lsl #6
 *   @0x2e7dae strtmi r6, [r1], -r3, lsr #5
 *   @0x2e7db2 ldrhtmi lr, [r0], #-141
 *
 * ══ §44/50 CDS_Grid::Assign(CDS_Grid*)  0x20b478  size 596  149 条（0x20b478..0x20b6cc）
 * @func 0x20b478 0x20b6cc  size 596  149 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×3 / UNLOCK_RVALUE_MUTEX()×3 / YYFree(void const*)×3 / operator delete(void*)×3 / CDS_Grid::SetSize(int, int) / CDS_Grid::Assign(CDS_Grid*)+0xf4 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x4×12 / 0x-10×11 / 0x-4×4 / 0x8×4 / 0x-8×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b478 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20b47c mov r4, r0
 *   @0x20b480 mov r5, r1
 *   @0x20b484 sub sp, sp, #12
 *   @0x20b488 ldmib r1, {r1, r2}
 *   @0x20b48c bl 0x20affc <_ZN8CDS_Grid7SetSizeEii>
 *   @0x20b490 ldmib r4, {r3, r6}
 *   @0x20b494 ldr r5, [r5]
 *   @0x20b498 ldr r4, [r4]
 *   @0x20b49c mul r6, r6, r3
 *   @0x20b4a0 cmp r6, #0
 *   @0x20b4a4 ble 0x20b56c <_ZN8CDS_Grid6AssignEPS_+0xf4>
 *   @0x20b4a8 add r4, r4, #16
 *   @0x20b4ac add r5, r5, #16
 *   @0x20b4b0 mov r9, #0
 *   @0x20b4b4 mov r10, #5
 *   @0x20b4b8 ldr r2, [r4, #-0x4]
 *   @0x20b4bc sub r8, r5, #16
 *   @0x20b4c0 sub r7, r4, #16
 *   @0x20b4c4 bic r3, r2, #-16777216
 *   @0x20b4c8 cmp r3, #1
 *   @0x20b4cc beq 0x20b5e8 <_ZN8CDS_Grid6AssignEPS_+0x170>
 *   @0x20b4d0 cmp r3, #2
 *   @0x20b4d4 bne 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78>
 *   @0x20b4d8 sub r2, r2, #1
 *   @0x20b4dc bic r2, r2, #-16777216
 *   @0x20b4e0 bic r2, r2, #3
 *   @0x20b4e4 cmp r2, #0
 *   @0x20b4e8 beq 0x20b654 <_ZN8CDS_Grid6AssignEPS_+0x1dc>
 *   @0x20b4ec stmdb r4, {r9, r10}
 *   @0x20b4f0 str r9, [r4, #-0x10]
 *   @0x20b4f4 ldr r3, [r5, #-0x4]
 *   @0x20b4f8 str r3, [r4, #-0x4]
 *   @0x20b4fc ldr r3, [r5, #-0x8]
 *   @0x20b500 str r3, [r4, #-0x8]
 *   @0x20b504 ldr r3, [r5, #-0x4]
 *   @0x20b508 bic r3, r3, #-16777216
 *   @0x20b50c cmp r3, #14
 *   @0x20b510 addls pc, pc, r3, lsl #2
 *   @0x20b514 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b518 b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc>
 *   @0x20b51c b 0x20b5d0 <_ZN8CDS_Grid6AssignEPS_+0x158>
 *   @0x20b520 b 0x20b5a4 <_ZN8CDS_Grid6AssignEPS_+0x12c>
 *   @0x20b524 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc>
 *   @0x20b528 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b52c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b530 b 0x20b580 <_ZN8CDS_Grid6AssignEPS_+0x108>
 *   @0x20b534 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc>
 *   @0x20b538 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b53c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b540 b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc>
 *   @0x20b544 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b548 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b54c b 0x20b574 <_ZN8CDS_Grid6AssignEPS_+0xfc>
 *   @0x20b550 b 0x20b554 <_ZN8CDS_Grid6AssignEPS_+0xdc>
 *   @0x20b554 ldr r3, [r5, #-0x10]
 *   @0x20b558 str r3, [r4, #-0x10]
 *   @0x20b55c subs r6, r6, #1
 *   @0x20b560 add r4, r4, #16
 *   @0x20b564 add r5, r5, #16
 *   @0x20b568 bne 0x20b4b8 <_ZN8CDS_Grid6AssignEPS_+0x40>
 *   @0x20b56c add sp, sp, #12
 *   @0x20b570 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20b574 ldm r8, {r2, r3}
 *   @0x20b578 stm r7, {r2, r3}
 *   @0x20b57c b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b580 ldr r3, [r5, #-0x10]
 *   @0x20b584 str r3, [r4, #-0x10]
 *   @0x20b588 ldr r3, [r5, #-0x10]
 *   @0x20b58c cmp r3, #0
 *   @0x20b590 beq 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b594 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20b598 ldr r1, [r5, #-0x10]
 *   @0x20b59c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20b5a0 b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b5a4 ldr r3, [r5, #-0x10]
 *   @0x20b5a8 cmp r3, #0
 *   @0x20b5ac str r3, [r4, #-0x10]
 *   @0x20b5b0 beq 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b5b4 ldr r1, [r3, #0x8]
 *   @0x20b5b8 ldr r2, [r3]
 *   @0x20b5bc cmp r1, #0
 *   @0x20b5c0 streq r7, [r3, #0x8]
 *   @0x20b5c4 add r2, r2, #1
 *   @0x20b5c8 str r2, [r3]
 *   @0x20b5cc b 0x20b55c <_ZN8CDS_Grid6AssignEPS_+0xe4>
 *   @0x20b5d0 ldr r3, [r5, #-0x10]
 *   @0x20b5d4 cmp r3, #0
 *   @0x20b5d8 ldrne r2, [r3, #0x4]
 *   @0x20b5dc addne r2, r2, #1
 *   @0x20b5e0 strne r2, [r3, #0x4]
 *   @0x20b5e4 b 0x20b558 <_ZN8CDS_Grid6AssignEPS_+0xe0>
 *   @0x20b5e8 ldr r11, [r4, #-0x10]
 *   @0x20b5ec cmp r11, #0
 *   @0x20b5f0 beq 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78>
 *   @0x20b5f4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20b5f8 ldr r3, [r11, #0x4]
 *   @0x20b5fc sub r3, r3, #1
 *   @0x20b600 str r3, [r11, #0x4]
 *   @0x20b604 cmp r3, #0
 *   @0x20b608 beq 0x20b614 <_ZN8CDS_Grid6AssignEPS_+0x19c>
 *   @0x20b60c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20b610 b 0x20b4f0 <_ZN8CDS_Grid6AssignEPS_+0x78>
 *   @0x20b614 ldr r0, [r11]
 *   @0x20b618 str r3, [sp, #0x4]
 *   @0x20b61c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20b620 ldr r3, [sp, #0x4]
 *   @0x20b624 str r3, [r11]
 *   @0x20b628 str r3, [r11, #0x8]
 *   @0x20b62c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20b630 ldr r3, [r11, #0x4]
 *   @0x20b634 sub r3, r3, #1
 *   @0x20b638 str r3, [r11, #0x4]
 *   @0x20b63c cmp r3, #0
 *   @0x20b640 beq 0x20b660 <_ZN8CDS_Grid6AssignEPS_+0x1e8>
 *   @0x20b644 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20b648 mov r0, r11
 *   @0x20b64c bl 0x27d1d0 <_ZdlPv>
 *   @0x20b650 b 0x20b60c <_ZN8CDS_Grid6AssignEPS_+0x194>
 *   @0x20b654 mov r0, r7
 *   @0x20b658 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20b65c b 0x20b4ec <_ZN8CDS_Grid6AssignEPS_+0x74>
 *   @0x20b660 ldr r0, [r11]
 *   @0x20b664 str r3, [sp, #0x4]
 *   @0x20b668 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20b66c ldr r3, [sp, #0x4]
 *   @0x20b670 str r3, [r11]
 *   @0x20b674 str r3, [r11, #0x8]
 *   @0x20b678 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20b67c ldr r3, [r11, #0x4]
 *   @0x20b680 sub r3, r3, #1
 *   @0x20b684 str r3, [r11, #0x4]
 *   @0x20b688 cmp r3, #0
 *   @0x20b68c beq 0x20b6a0 <_ZN8CDS_Grid6AssignEPS_+0x228>
 *   @0x20b690 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20b694 mov r0, r11
 *   @0x20b698 bl 0x27d1d0 <_ZdlPv>
 *   @0x20b69c b 0x20b644 <_ZN8CDS_Grid6AssignEPS_+0x1cc>
 *   @0x20b6a0 ldr r0, [r11]
 *   @0x20b6a4 str r3, [sp, #0x4]
 *   @0x20b6a8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20b6ac ldr r3, [sp, #0x4]
 *   @0x20b6b0 mov r0, r11
 *   @0x20b6b4 str r3, [r11]
 *   @0x20b6b8 str r3, [r11, #0x8]
 *   @0x20b6bc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20b6c0 mov r0, r11
 *   @0x20b6c4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20b6c8 b 0x20b690 <_ZN8CDS_Grid6AssignEPS_+0x218>
 *
 * ══ §45/50 JS_FunctionSetup()  0x24163c  size 596  149 条（0x24163c..0x241890）
 * @func 0x24163c 0x241890  size 596  149 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x241678→0x756454, 0x2417dc→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×6 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×5 / YYObjectBase::InternalGetYYVar(int)×3 / JS_StandardScriptRefConstructor(RValue&, CInstance*, CInstance*, int, RValue*) / YYObjectBase::Add(char const*, int, int) / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0xc×2 / 0x28×2 / 0x120×2 / 0x1e8×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24163c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x241640 sub sp, sp, #28
 *   @0x241644 mov r4, #0
 *   @0x241648 add r0, sp, #8
 *   @0x24164c mov r1, r4
 *   @0x241650 mov r2, r4
 *   @0x241654 mov r3, r4
 *   @0x241658 str r4, [sp]
 *   @0x24165c ldr r6, [pc, #0x1e8]
 *   @0x241660 str r4, [sp, #0x8]
 *   @0x241664 str r4, [sp, #0xc]
 *   @0x241668 add r6, pc, r6
 *   @0x24166c str r4, [sp, #0x10]
 *   @0x241670 str r4, [sp, #0x14]
 *   @0x241674 bl 0x240d20 <_Z31JS_StandardScriptRefConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x241678 ldr r3, [pc, #0x1d0]
 *   @0x24167c mov r1, r4
 *   @0x241680 ldr r5, [sp, #0x8]
 *   @0x241684 mov r2, r4
 *   @0x241688 ldr r12, [pc, #0x1c4]
 *   @0x24168c ldr r8, [r6, r3]
 *   @0x241690 ldr r3, [pc, #0x1c0]
 *   @0x241694 add r12, pc, r12
 *   @0x241698 ldr r0, [r5, #0x28]
 *   @0x24169c str r12, [r5, #0x40]
 *   @0x2416a0 str r5, [r8]
 *   @0x2416a4 orr r0, r0, #1
 *   @0x2416a8 str r0, [r5, #0x28]
 *   @0x2416ac ldr r0, [r6, r3]
 *   @0x2416b0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2416b4 ldr r1, [pc, #0x1a0]
 *   @0x2416b8 mov r3, #6
 *   @0x2416bc add r1, pc, r1
 *   @0x2416c0 mov r2, r0
 *   @0x2416c4 mov r0, r5
 *   @0x2416c8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2416cc ldr r3, [pc, #0x18c]
 *   @0x2416d0 mov r2, r4
 *   @0x2416d4 mov r1, #1
 *   @0x2416d8 ldr r0, [r6, r3]
 *   @0x2416dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2416e0 ldr r1, [pc, #0x17c]
 *   @0x2416e4 mov r3, #6
 *   @0x2416e8 add r1, pc, r1
 *   @0x2416ec mov r2, r0
 *   @0x2416f0 mov r0, r5
 *   @0x2416f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2416f8 ldr r3, [pc, #0x168]
 *   @0x2416fc mov r2, r4
 *   @0x241700 mov r1, #1
 *   @0x241704 ldr r0, [r6, r3]
 *   @0x241708 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24170c ldr r1, [pc, #0x158]
 *   @0x241710 mov r3, #6
 *   @0x241714 add r1, pc, r1
 *   @0x241718 mov r2, r0
 *   @0x24171c mov r0, r5
 *   @0x241720 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241724 ldr r3, [pc, #0x144]
 *   @0x241728 mov r2, r4
 *   @0x24172c mov r1, #1
 *   @0x241730 ldr r0, [r6, r3]
 *   @0x241734 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x241738 ldr r1, [pc, #0x134]
 *   @0x24173c mov r3, #6
 *   @0x241740 add r1, pc, r1
 *   @0x241744 mov r2, r0
 *   @0x241748 mov r0, r5
 *   @0x24174c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241750 ldr r12, [pc, #0x120]
 *   @0x241754 ldr r1, [pc, #0x120]
 *   @0x241758 mov r0, r5
 *   @0x24175c mov r2, r4
 *   @0x241760 mov r3, r4
 *   @0x241764 ldr r12, [r6, r12]
 *   @0x241768 add r1, pc, r1
 *   @0x24176c str r12, [r5, #0x68]
 *   @0x241770 bl 0x199960 <_ZN12YYObjectBase3AddEPKcii>
 *   @0x241774 ldr r3, [pc, #0x104]
 *   @0x241778 mov r1, r4
 *   @0x24177c mov r2, r4
 *   @0x241780 ldr r9, [r6, r3]
 *   @0x241784 mov r0, r9
 *   @0x241788 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x24178c ldr r1, [pc, #0xf0]
 *   @0x241790 mov r3, r4
 *   @0x241794 add r1, pc, r1
 *   @0x241798 mov r7, r0
 *   @0x24179c str r9, [r0, #0x94]
 *   @0x2417a0 mov r2, r7
 *   @0x2417a4 mov r0, r5
 *   @0x2417a8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2417ac ldr r3, [r7, #0x4]
 *   @0x2417b0 cmp r3, r4
 *   @0x2417b4 beq 0x24180c <_Z16JS_FunctionSetupv+0x1d0>
 *   @0x2417b8 ldr r1, [r8]
 *   @0x2417bc mov r0, r7
 *   @0x2417c0 str r1, [r3]
 *   @0x2417c4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2417c8 ldr r1, [r7, #0x4]
 *   @0x2417cc cmp r1, #0
 *   @0x2417d0 movne r3, #6
 *   @0x2417d4 strne r3, [r1, #0xc]
 *   @0x2417d8 beq 0x241820 <_Z16JS_FunctionSetupv+0x1e4>
 *   @0x2417dc ldr r0, [pc, #0xa4]
 *   @0x2417e0 mov r3, #6
 *   @0x2417e4 str r3, [r1, #0x8]
 *   @0x2417e8 mov r2, r7
 *   @0x2417ec ldr r1, [pc, #0x98]
 *   @0x2417f0 mov r3, #0
 *   @0x2417f4 ldr r0, [r6, r0]
 *   @0x2417f8 add r1, pc, r1
 *   @0x2417fc ldr r0, [r0]
 *   @0x241800 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x241804 add sp, sp, #28
 *   @0x241808 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x24180c mov r1, r3
 *   @0x241810 mov r0, r7
 *   @0x241814 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241818 mov r3, r0
 *   @0x24181c b 0x2417b8 <_Z16JS_FunctionSetupv+0x17c>
 *   @0x241820 mov r0, r7
 *   @0x241824 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241828 ldr r1, [r7, #0x4]
 *   @0x24182c mov r3, #6
 *   @0x241830 cmp r1, #0
 *   @0x241834 str r3, [r0, #0xc]
 *   @0x241838 bne 0x2417dc <_Z16JS_FunctionSetupv+0x1a0>
 *   @0x24183c mov r0, r7
 *   @0x241840 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x241844 mov r1, r0
 *   @0x241848 b 0x2417dc <_Z16JS_FunctionSetupv+0x1a0>
 *   @0x24184c andseq r0, r11, r8, ror #11
 *   @0x241850 .word 0xffffc054
 *   @0x241854 andseq r3, r1, r0, asr pc
 *   @0x241858 .word 0xfffff8f4
 *   @0x24185c andeq r0, pc, r4, asr lr
 *   @0x241860 .word 0xfffff8f8
 *   @0x241864 andseq r3, r1, r12, lsl #30
 *   @0x241868 .word 0xfffff8fc
 *   @0x24186c andseq r3, r1, r8, ror #29
 *   @0x241870 .word 0xfffff900
 *   @0x241874 andseq r3, r1, r4, asr #29
 *   @0x241878 .word 0xfffff904
 *   @0x24187c andeq pc, lr, r4, lsl #2
 *   @0x241880 .word 0xfffff908
 *   @0x241884 mulseq r1, r0, sp
 *   @0x241888 .word 0xffffbf64
 *   @0x24188c andseq r3, r1, r12, asr sp
 *
 * ══ §46/50 _pcre_find_bracket  0x25e0fc  size 596  149 条（0x25e0fc..0x25e350）
 * @func 0x25e0fc 0x25e350  size 596  149 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _pcre_find_bracket+0x1fc / _pcre_find_bracket+0xc / _pcre_find_bracket+0x1cc
 * 字段偏移 top8: 0x1×3 / 0x3×2 / 0x23c×1 / 0xcc×1 / 0x-1×1 / 0xa0×1 / 0x4×1 / 0x34×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25e0fc push {r4, r5}
 *   @0x25e100 ldr r5, [pc, #0x23c]
 *   @0x25e104 add r5, pc, r5
 *   @0x25e108 ldrb r3, [r0]
 *   @0x25e10c cmp r3, #0
 *   @0x25e110 beq 0x25e2c4 <_pcre_find_bracket+0x1c8>
 *   @0x25e114 cmp r3, #112
 *   @0x25e118 beq 0x25e320 <_pcre_find_bracket+0x224>
 *   @0x25e11c cmp r3, #124
 *   @0x25e120 beq 0x25e334 <_pcre_find_bracket+0x238>
 *   @0x25e124 add r4, r3, #123
 *   @0x25e128 add r12, r3, #118
 *   @0x25e12c uxtb r4, r4
 *   @0x25e130 uxtb r12, r12
 *   @0x25e134 cmp r12, #1
 *   @0x25e138 cmphi r4, #1
 *   @0x25e13c bls 0x25e2f8 <_pcre_find_bracket+0x1fc>
 *   @0x25e140 sub r12, r3, #85
 *   @0x25e144 cmp r12, #70
 *   @0x25e148 addls pc, pc, r12, lsl #2
 *   @0x25e14c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e150 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e154 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e158 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e15c b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e160 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e164 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e168 b 0x25e2e4 <_pcre_find_bracket+0x1e8>
 *   @0x25e16c b 0x25e2e4 <_pcre_find_bracket+0x1e8>
 *   @0x25e170 b 0x25e2e4 <_pcre_find_bracket+0x1e8>
 *   @0x25e174 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e178 b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e17c b 0x25e2d0 <_pcre_find_bracket+0x1d4>
 *   @0x25e180 b 0x25e2e4 <_pcre_find_bracket+0x1e8>
 *   @0x25e184 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e188 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e18c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e190 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e194 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e198 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e19c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1a0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1a4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1a8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1ac b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1b0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1b4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1b8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1bc b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1c0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1c4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1c8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1cc b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1d0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1d4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1d8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1dc b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1e0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1e4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1e8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1ec b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1f0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1f4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1f8 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e1fc b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e200 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e204 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e208 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e20c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e210 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e214 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e218 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e21c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e220 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e224 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e228 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e22c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e230 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e234 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e238 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e23c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e240 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e244 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e248 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e24c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e250 b 0x25e26c <_pcre_find_bracket+0x170>
 *   @0x25e254 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e258 b 0x25e26c <_pcre_find_bracket+0x170>
 *   @0x25e25c b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e260 b 0x25e26c <_pcre_find_bracket+0x170>
 *   @0x25e264 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e268 b 0x25e26c <_pcre_find_bracket+0x170>
 *   @0x25e26c ldrb r12, [r0, #0x1]
 *   @0x25e270 add r0, r0, r12
 *   @0x25e274 ldr r12, [pc, #0xcc]
 *   @0x25e278 cmp r1, #0
 *   @0x25e27c ldr r12, [r5, r12]
 *   @0x25e280 ldrb r12, [r12, r3]
 *   @0x25e284 add r0, r0, r12
 *   @0x25e288 beq 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e28c sub r3, r3, #29
 *   @0x25e290 cmp r3, #55
 *   @0x25e294 bhi 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e298 ldrb r3, [r0, #-0x1]
 *   @0x25e29c cmp r3, #191
 *   @0x25e2a0 bls 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e2a4 ldr r12, [pc, #0xa0]
 *   @0x25e2a8 and r3, r3, #63
 *   @0x25e2ac ldr r12, [r5, r12]
 *   @0x25e2b0 ldrb r3, [r12, r3]
 *   @0x25e2b4 add r0, r0, r3
 *   @0x25e2b8 ldrb r3, [r0]
 *   @0x25e2bc cmp r3, #0
 *   @0x25e2c0 bne 0x25e114 <_pcre_find_bracket+0x18>
 *   @0x25e2c4 mov r0, r3
 *   @0x25e2c8 pop {r4, r5}
 *   @0x25e2cc bx lr
 *   @0x25e2d0 ldrb r12, [r0, #0x1]
 *   @0x25e2d4 sub r12, r12, #15
 *   @0x25e2d8 cmp r12, #1
 *   @0x25e2dc addls r0, r0, #2
 *   @0x25e2e0 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e2e4 ldrb r12, [r0, #0x3]
 *   @0x25e2e8 sub r12, r12, #15
 *   @0x25e2ec cmp r12, #1
 *   @0x25e2f0 addls r0, r0, #2
 *   @0x25e2f4 b 0x25e274 <_pcre_find_bracket+0x178>
 *   @0x25e2f8 ldrb r4, [r0, #0x3]
 *   @0x25e2fc ldrb r12, [r0, #0x4]
 *   @0x25e300 orr r12, r12, r4, lsl #8
 *   @0x25e304 cmp r12, r2
 *   @0x25e308 beq 0x25e2c8 <_pcre_find_bracket+0x1cc>
 *   @0x25e30c ldr r12, [pc, #0x34]
 *   @0x25e310 ldr r12, [r5, r12]
 *   @0x25e314 ldrb r3, [r12, r3]
 *   @0x25e318 add r0, r0, r3
 *   @0x25e31c b 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e320 ldrb r12, [r0, #0x1]
 *   @0x25e324 ldrb r3, [r0, #0x2]
 *   @0x25e328 orr r3, r3, r12, lsl #8
 *   @0x25e32c add r0, r0, r3
 *   @0x25e330 b 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e334 cmp r2, #0
 *   @0x25e338 blt 0x25e2c8 <_pcre_find_bracket+0x1cc>
 *   @0x25e33c add r0, r0, #3
 *   @0x25e340 b 0x25e108 <_pcre_find_bracket+0xc>
 *   @0x25e344 andseq r3, r9, r12, asr #22
 *   @0x25e348 .word 0xfffffb8c
 *   @0x25e34c .word 0xfffffb90
 *
 * ══ §47/50 Java_com_yoyogames_runner_RunnerJNILib_HttpResult  0x292d08  size 596  149 条（0x292d08..0x292f5c）
 * @func 0x292d08 0x292f5c  size 596  149 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: MemoryManager::Free(void const*)×2 / setJNIEnv / HTTP_REQ_CONTEXT::SetResponseHeaders(char*) / Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1c4 / YYStrDup(char const*) / MemoryManager::Alloc(unsigned int, char const*, int, bool)
 * 字段偏移 top8: 0xc×6 / 0x44×4 / 0x48×3 / 0x10×3 / 0x34×3 / 0x20×3 / 0x14×2 / 0x21c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x292d08 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x292d0c sub sp, sp, #28
 *   @0x292d10 mov r7, r2
 *   @0x292d14 mov r11, r0
 *   @0x292d18 str r3, [sp, #0x14]
 *   @0x292d1c ldr r5, [sp, #0x40]
 *   @0x292d20 bl 0x290614 <setJNIEnv>
 *   @0x292d24 ldr r2, [pc, #0x21c]
 *   @0x292d28 ldr r1, [pc, #0x21c]
 *   @0x292d2c ldr r2, [pc, r2]
 *   @0x292d30 add r1, pc, r1
 *   @0x292d34 ldr r6, [r2]
 *   @0x292d38 ldr r2, [r6]
 *   @0x292d3c mov r0, r6
 *   @0x292d40 ldr r2, [r2, #0xc]
 *   @0x292d44 blx r2
 *   @0x292d48 cmp r7, #0
 *   @0x292d4c moveq r9, r7
 *   @0x292d50 beq 0x292d6c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x64>
 *   @0x292d54 ldr r2, [r11]
 *   @0x292d58 mov r0, r11
 *   @0x292d5c mov r1, r7
 *   @0x292d60 ldr r2, [r2, #0x2ac]
 *   @0x292d64 blx r2
 *   @0x292d68 mov r9, r0
 *   @0x292d6c ldr r3, [sp, #0x44]
 *   @0x292d70 cmp r3, #0
 *   @0x292d74 beq 0x292f04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1fc>
 *   @0x292d78 ldr lr, [r11]
 *   @0x292d7c mov r0, r11
 *   @0x292d80 mov r1, r3
 *   @0x292d84 mov r2, #0
 *   @0x292d88 ldr r4, [lr, #0x2a4]
 *   @0x292d8c blx r4
 *   @0x292d90 mov r8, r0
 *   @0x292d94 ldr r3, [sp, #0x48]
 *   @0x292d98 cmp r3, #0
 *   @0x292d9c beq 0x292ef4 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1ec>
 *   @0x292da0 ldr lr, [r11]
 *   @0x292da4 mov r1, r3
 *   @0x292da8 mov r0, r11
 *   @0x292dac mov r2, #0
 *   @0x292db0 ldr r4, [lr, #0x2a4]
 *   @0x292db4 blx r4
 *   @0x292db8 adds r3, r0, #0
 *   @0x292dbc mov r10, r0
 *   @0x292dc0 movne r3, #1
 *   @0x292dc4 str r3, [sp, #0x10]
 *   @0x292dc8 ldr r2, [pc, #0x180]
 *   @0x292dcc ldr r2, [pc, r2]
 *   @0x292dd0 ldr r4, [r2]
 *   @0x292dd4 cmp r4, #0
 *   @0x292dd8 beq 0x292e04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xfc>
 *   @0x292ddc ldr r2, [r4, #0x24]
 *   @0x292de0 cmp r2, r5
 *   @0x292de4 bne 0x292df8 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xf0>
 *   @0x292de8 b 0x292e58 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x150>
 *   @0x292dec ldr r3, [r4, #0x24]
 *   @0x292df0 cmp r3, r5
 *   @0x292df4 beq 0x292e58 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x150>
 *   @0x292df8 ldr r4, [r4, #0x4]
 *   @0x292dfc cmp r4, #0
 *   @0x292e00 bne 0x292dec <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xe4>
 *   @0x292e04 ldr r3, [sp, #0x44]
 *   @0x292e08 cmp r8, #0
 *   @0x292e0c cmpne r3, #0
 *   @0x292e10 beq 0x292e2c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x124>
 *   @0x292e14 ldr r3, [r11]
 *   @0x292e18 mov r2, r8
 *   @0x292e1c ldr r1, [sp, #0x44]
 *   @0x292e20 mov r0, r11
 *   @0x292e24 ldr r3, [r3, #0x2a8]
 *   @0x292e28 blx r3
 *   @0x292e2c ldr r3, [sp, #0x10]
 *   @0x292e30 cmp r3, #0
 *   @0x292e34 beq 0x292e50 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x148>
 *   @0x292e38 ldr r3, [r11]
 *   @0x292e3c mov r2, r10
 *   @0x292e40 ldr r1, [sp, #0x48]
 *   @0x292e44 mov r0, r11
 *   @0x292e48 ldr r3, [r3, #0x2a8]
 *   @0x292e4c blx r3
 *   @0x292e50 add sp, sp, #28
 *   @0x292e54 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x292e58 ldr r3, [r4, #0x38]
 *   @0x292e5c cmp r9, r3
 *   @0x292e60 bgt 0x292f0c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x204>
 *   @0x292e64 mov r0, r4
 *   @0x292e68 mov r1, r10
 *   @0x292e6c bl 0x18e2d4 <_ZN16HTTP_REQ_CONTEXT18SetResponseHeadersEPc>
 *   @0x292e70 ldr r3, [sp, #0x14]
 *   @0x292e74 cmp r9, #0
 *   @0x292e78 str r3, [r4, #0x28]
 *   @0x292e7c mov r3, #7
 *   @0x292e80 str r3, [r4, #0xc]
 *   @0x292e84 ble 0x292ecc <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x1c4>
 *   @0x292e88 ldr lr, [r11]
 *   @0x292e8c mov r1, r7
 *   @0x292e90 ldr r12, [r4, #0x34]
 *   @0x292e94 mov r0, r11
 *   @0x292e98 mov r2, #0
 *   @0x292e9c mov r3, r9
 *   @0x292ea0 str r12, [sp]
 *   @0x292ea4 ldr r7, [lr, #0x320]
 *   @0x292ea8 blx r7
 *   @0x292eac ldr r3, [r6]
 *   @0x292eb0 ldr r1, [pc, #0x9c]
 *   @0x292eb4 mov r0, r6
 *   @0x292eb8 mov r2, r9
 *   @0x292ebc add r1, pc, r1
 *   @0x292ec0 ldr r3, [r3, #0xc]
 *   @0x292ec4 blx r3
 *   @0x292ec8 str r9, [r4, #0x3c]
 *   @0x292ecc cmp r8, #0
 *   @0x292ed0 beq 0x292e2c <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x124>
 *   @0x292ed4 ldr r0, [r4, #0x20]
 *   @0x292ed8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x292edc mov r3, #0
 *   @0x292ee0 mov r0, r8
 *   @0x292ee4 str r3, [r4, #0x20]
 *   @0x292ee8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x292eec str r0, [r4, #0x20]
 *   @0x292ef0 b 0x292e04 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xfc>
 *   @0x292ef4 ldr r3, [sp, #0x48]
 *   @0x292ef8 str r3, [sp, #0x10]
 *   @0x292efc mov r10, r3
 *   @0x292f00 b 0x292dc8 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0xc0>
 *   @0x292f04 ldr r8, [sp, #0x44]
 *   @0x292f08 b 0x292d94 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x8c>
 *   @0x292f0c ldr r0, [r4, #0x34]
 *   @0x292f10 add r3, r9, #1
 *   @0x292f14 str r3, [sp, #0xc]
 *   @0x292f18 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x292f1c ldr r3, [sp, #0xc]
 *   @0x292f20 mov r2, #70
 *   @0x292f24 ldr r1, [pc, #0x2c]
 *   @0x292f28 mov r0, r3
 *   @0x292f2c add r1, pc, r1
 *   @0x292f30 mov r3, #1
 *   @0x292f34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x292f38 ldr r12, [sp, #0xc]
 *   @0x292f3c str r12, [r4, #0x38]
 *   @0x292f40 str r0, [r4, #0x34]
 *   @0x292f44 b 0x292e64 <Java_com_yoyogames_runner_RunnerJNILib_HttpResult+0x15c>
 *   @0x292f48 andseq r10, r5, r4, lsl r12
 *   @0x292f4c andeq r6, r12, r0, asr r3
 *   @0x292f50 andseq r11, r5, r12, lsr #32
 *   @0x292f54 ldrdeq r6, r7, [r12], -r0
 *   @0x292f58 andeq lr, r9, r4, lsl #2
 *
 * ══ §48/50 F_FileCopy(RValue&, CInstance*, CInstance*, int, RValue*)  0x13b468  size 592  148 条（0x13b468..0x13b6b8）
 * @func 0x13b468 0x13b6b8  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x13b574→0x3eb70c, 0x13b640→0x3eb70c
 * 调用序列: 0xb6844×3 / YYGetString(RValue const*, int)×2 / LoadSave::_GetSaveFileName(char*, int, char const*)×2 / 0xb68bc×2 / 0xb6850×2 / LoadSave::SaveFileExists(char const*) / EnsureDirectoryIsCreated(char const*) / 0xb68c8
 * 字段偏移 top8: 0x4×4 / 0x-7f4×2 / 0xc×2 / 0x220×1 / 0x21c×1 / 0x-7c8×1 / 0x174×1 / 0x150×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x13b468 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x13b46c sub sp, sp, #6144
 *   @0x13b470 ldr r8, [pc, #0x220]
 *   @0x13b474 sub sp, sp, #20
 *   @0x13b478 ldr r3, [pc, #0x21c]
 *   @0x13b47c add r2, sp, #8192
 *   @0x13b480 add r8, pc, r8
 *   @0x13b484 mov r5, r0
 *   @0x13b488 ldr r6, [r2, #-0x7c8]
 *   @0x13b48c mov r1, #0
 *   @0x13b490 ldr r3, [r8, r3]
 *   @0x13b494 mov r0, r6
 *   @0x13b498 str r3, [sp, #0x4]
 *   @0x13b49c ldr r3, [r3]
 *   @0x13b4a0 str r3, [r2, #-0x7f4]
 *   @0x13b4a4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b4a8 mov r1, #1
 *   @0x13b4ac mov r4, r0
 *   @0x13b4b0 mov r0, r6
 *   @0x13b4b4 bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x13b4b8 mov r2, #0
 *   @0x13b4bc mov r3, r2
 *   @0x13b4c0 movt r2, #0xbff0
 *   @0x13b4c4 str r3, [r5, #0xc]
 *   @0x13b4c8 str r2, [r5, #0x4]
 *   @0x13b4cc str r3, [r5]
 *   @0x13b4d0 mov r10, r0
 *   @0x13b4d4 mov r0, r4
 *   @0x13b4d8 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc>
 *   @0x13b4dc cmp r0, #0
 *   @0x13b4e0 beq 0x13b600 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x198>
 *   @0x13b4e4 add r11, sp, #16
 *   @0x13b4e8 mov r1, #1024
 *   @0x13b4ec sub r7, r11, #4
 *   @0x13b4f0 mov r2, r4
 *   @0x13b4f4 mov r0, r7
 *   @0x13b4f8 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b4fc add r6, sp, #1040
 *   @0x13b500 mov r2, r10
 *   @0x13b504 sub r6, r6, #4
 *   @0x13b508 mov r1, #1024
 *   @0x13b50c movw r9, #0xe7f8
 *   @0x13b510 movt r9, #0xffff
 *   @0x13b514 mov r0, r6
 *   @0x13b518 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x13b51c mov r0, r6
 *   @0x13b520 bl 0x13ad20 <_Z24EnsureDirectoryIsCreatedPKc>
 *   @0x13b524 ldr r1, [pc, #0x174]
 *   @0x13b528 mov r0, r7
 *   @0x13b52c add r1, pc, r1
 *   @0x13b530 bl 0xb6844 <fopen@plt>
 *   @0x13b534 add r3, sp, #6144
 *   @0x13b538 add r3, r3, #16
 *   @0x13b53c mov r2, #0
 *   @0x13b540 str r2, [r3, r9]
 *   @0x13b544 subs r7, r0, #0
 *   @0x13b548 beq 0x13b630 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x1c8>
 *   @0x13b54c ldr r1, [pc, #0x150]
 *   @0x13b550 mov r0, r6
 *   @0x13b554 add r1, pc, r1
 *   @0x13b558 bl 0xb6844 <fopen@plt>
 *   @0x13b55c subs r6, r0, #0
 *   @0x13b560 addne r4, sp, #2048
 *   @0x13b564 addne r4, r4, #12
 *   @0x13b568 bne 0x13b5a4 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x13b56c ldr r1, [pc, #0x134]
 *   @0x13b570 mov r2, r10
 *   @0x13b574 ldr r3, [pc, #0x130]
 *   @0x13b578 add r1, pc, r1
 *   @0x13b57c ldr r3, [r8, r3]
 *   @0x13b580 ldr r0, [r3]
 *   @0x13b584 ldr r3, [r0]
 *   @0x13b588 ldr r3, [r3, #0xc]
 *   @0x13b58c blx r3
 *   @0x13b590 b 0x13b5dc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x174>
 *   @0x13b594 mov r0, r4
 *   @0x13b598 mov r1, #1
 *   @0x13b59c mov r3, r6
 *   @0x13b5a0 bl 0xb68bc <fwrite@plt>
 *   @0x13b5a4 mov r2, #4096
 *   @0x13b5a8 mov r0, r4
 *   @0x13b5ac mov r1, #1
 *   @0x13b5b0 mov r3, r7
 *   @0x13b5b4 bl 0xb68c8 <fread@plt>
 *   @0x13b5b8 subs r2, r0, #0
 *   @0x13b5bc bne 0x13b594 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x12c>
 *   @0x13b5c0 mov r0, r7
 *   @0x13b5c4 bl 0xb6850 <fclose@plt>
 *   @0x13b5c8 mov r0, r6
 *   @0x13b5cc bl 0xb6850 <fclose@plt>
 *   @0x13b5d0 mov r3, #0
 *   @0x13b5d4 str r3, [r5]
 *   @0x13b5d8 str r3, [r5, #0x4]
 *   @0x13b5dc ldr r1, [sp, #0x4]
 *   @0x13b5e0 add r3, sp, #8192
 *   @0x13b5e4 ldr r2, [r3, #-0x7f4]
 *   @0x13b5e8 ldr r3, [r1]
 *   @0x13b5ec cmp r2, r3
 *   @0x13b5f0 bne 0x13b694 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x22c>
 *   @0x13b5f4 add sp, sp, #6144
 *   @0x13b5f8 add sp, sp, #20
 *   @0x13b5fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x13b600 mov r0, r4
 *   @0x13b604 add r11, sp, #16
 *   @0x13b608 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc>
 *   @0x13b60c cmp r0, #0
 *   @0x13b610 addeq r7, sp, #12
 *   @0x13b614 beq 0x13b4fc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13b618 add r7, sp, #12
 *   @0x13b61c mov r1, #1024
 *   @0x13b620 mov r2, r4
 *   @0x13b624 mov r0, r7
 *   @0x13b628 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc>
 *   @0x13b62c b 0x13b4fc <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x94>
 *   @0x13b630 sub r1, r11, #8
 *   @0x13b634 mov r0, r4
 *   @0x13b638 bl 0x18f848 <_ZN8LoadSave14ReadBundleFileEPKcPi>
 *   @0x13b63c ldr r1, [pc, #0x6c]
 *   @0x13b640 ldr r3, [pc, #0x64]
 *   @0x13b644 mov r2, r4
 *   @0x13b648 add r1, pc, r1
 *   @0x13b64c subs r7, r0, #0
 *   @0x13b650 beq 0x13b57c <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x114>
 *   @0x13b654 ldr r1, [pc, #0x58]
 *   @0x13b658 mov r0, r6
 *   @0x13b65c add r1, pc, r1
 *   @0x13b660 bl 0xb6844 <fopen@plt>
 *   @0x13b664 subs r6, r0, #0
 *   @0x13b668 beq 0x13b56c <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x104>
 *   @0x13b66c add r1, sp, #6144
 *   @0x13b670 mov r0, r7
 *   @0x13b674 add r1, r1, #16
 *   @0x13b678 mov r3, r6
 *   @0x13b67c ldr r2, [r1, r9]
 *   @0x13b680 mov r1, #1
 *   @0x13b684 bl 0xb68bc <fwrite@plt>
 *   @0x13b688 mov r0, r7
 *   @0x13b68c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x13b690 b 0x13b5c8 <_Z10F_FileCopyR6RValueP9CInstanceS2_iPS_+0x160>
 *   @0x13b694 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x13b698 .word 0x002b67d0
 *   @0x13b69c .word 0xffffbd00
 *   @0x13b6a0 andseq r12, pc, r12, asr #13
 *   @0x13b6a4 .word 0x00204df0
 *   @0x13b6a8 eoreq r4, r0, r8, lsl lr
 *   @0x13b6ac .word 0xffffbac4
 *   @0x13b6b0 eoreq r4, r0, r8, lsr #26
 *   @0x13b6b4 eoreq r4, r0, r8, ror #25
 *
 * ══ §49/50 SHA1ProcessMessageBlock(SHA1Context*)  0x2142e8  size 592  148 条（0x2142e8..0x214538）
 * @func 0x2142e8 0x214538  size 592  148 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x4×10 / 0x8×4 / 0xc×4 / 0x10×2 / 0x1d×1 / 0x18×1 / 0x1b×1 / 0x1a×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2142e8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2142ec sub sp, sp, #336
 *   @0x2142f0 add r1, sp, #12
 *   @0x2142f4 add r7, sp, #16
 *   @0x2142f8 add r8, sp, #76
 *   @0x2142fc mov r3, r0
 *   @0x214300 mov r2, r1
 *   @0x214304 ldrb r12, [r3, #0x1d]
 *   @0x214308 add r3, r3, #4
 *   @0x21430c ldrb r6, [r3, #0x18]
 *   @0x214310 ldrb r5, [r3, #0x1b]
 *   @0x214314 ldrb r4, [r3, #0x1a]
 *   @0x214318 lsl r12, r12, #16
 *   @0x21431c orr r12, r12, r6, lsl #24
 *   @0x214320 orr r12, r12, r5
 *   @0x214324 orr r12, r12, r4, lsl #8
 *   @0x214328 str r12, [r2, #0x4]!
 *   @0x21432c cmp r2, r8
 *   @0x214330 bne 0x214304 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1c>
 *   @0x214334 mov r3, r7
 *   @0x214338 mov r2, #0
 *   @0x21433c ldr r4, [r3, #0x34]
 *   @0x214340 add r3, r3, #4
 *   @0x214344 ldr r12, [r3, #0x1c]
 *   @0x214348 ldr r5, [r7, r2]
 *   @0x21434c add r2, r2, #4
 *   @0x214350 eor r12, r4, r12
 *   @0x214354 ldr r4, [r3, #0x4]
 *   @0x214358 eor r12, r12, r5
 *   @0x21435c cmp r2, #256
 *   @0x214360 eor r12, r12, r4
 *   @0x214364 ror r12, r12, #31
 *   @0x214368 str r12, [r3, #0x3c]
 *   @0x21436c bne 0x21433c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x54>
 *   @0x214370 ldr r3, [r0, #0x4]
 *   @0x214374 add r11, r7, #76
 *   @0x214378 ldr r8, [r0]
 *   @0x21437c str r3, [sp]
 *   @0x214380 ldr r3, [r0, #0x8]
 *   @0x214384 mov r5, r8
 *   @0x214388 str r3, [sp, #0x4]
 *   @0x21438c ldr r3, [r0, #0xc]
 *   @0x214390 str r3, [sp, #0x8]
 *   @0x214394 ldr r3, [r0, #0x10]
 *   @0x214398 ldm sp, {r2, r4, r6}
 *   @0x21439c str r3, [sp, #0xc]
 *   @0x2143a0 mov r9, r3
 *   @0x2143a4 b 0x2143b4 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0xcc>
 *   @0x2143a8 mov r6, r4
 *   @0x2143ac mov r5, r12
 *   @0x2143b0 mov r4, r10
 *   @0x2143b4 ldr r10, [r1, #0x4]!
 *   @0x2143b8 movw r3, #0x7999
 *   @0x2143bc movt r3, #0x5a82
 *   @0x2143c0 bic r12, r6, r2
 *   @0x2143c4 add r3, r10, r3
 *   @0x2143c8 and r10, r4, r2
 *   @0x2143cc orr r12, r12, r10
 *   @0x2143d0 add r3, r3, r5, ror #27
 *   @0x2143d4 cmp r1, r11
 *   @0x2143d8 add r12, r3, r12
 *   @0x2143dc ror r10, r2, #2
 *   @0x2143e0 add r12, r12, r9
 *   @0x2143e4 mov r2, r5
 *   @0x2143e8 mov r9, r6
 *   @0x2143ec bne 0x2143a8 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0xc0>
 *   @0x2143f0 mov r3, r10
 *   @0x2143f4 add r9, sp, #92
 *   @0x2143f8 add r10, r7, #156
 *   @0x2143fc b 0x21440c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x124>
 *   @0x214400 mov r4, r3
 *   @0x214404 mov r12, r1
 *   @0x214408 mov r3, r2
 *   @0x21440c ldr r11, [r9, #0x4]!
 *   @0x214410 movw r2, #0xeba1
 *   @0x214414 movt r2, #0x6ed9
 *   @0x214418 eor r1, r3, r5
 *   @0x21441c add r2, r11, r2
 *   @0x214420 eor r1, r1, r4
 *   @0x214424 add r2, r2, r12, ror #27
 *   @0x214428 cmp r9, r10
 *   @0x21442c add r1, r2, r1
 *   @0x214430 ror r2, r5, #2
 *   @0x214434 add r1, r1, r6
 *   @0x214438 mov r5, r12
 *   @0x21443c mov r6, r4
 *   @0x214440 bne 0x214400 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x118>
 *   @0x214444 add r6, sp, #172
 *   @0x214448 add r11, r7, #236
 *   @0x21444c b 0x21445c <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x174>
 *   @0x214450 mov r3, r2
 *   @0x214454 mov r1, r5
 *   @0x214458 mov r2, r9
 *   @0x21445c ldr r10, [r6, #0x4]!
 *   @0x214460 movw r5, #0xbcdc
 *   @0x214464 orr r9, r3, r2
 *   @0x214468 movt r5, #0x8f1b
 *   @0x21446c add r5, r10, r5
 *   @0x214470 and r9, r9, r12
 *   @0x214474 and r10, r3, r2
 *   @0x214478 add r5, r5, r1, ror #27
 *   @0x21447c orr r9, r9, r10
 *   @0x214480 cmp r6, r11
 *   @0x214484 add r5, r5, r9
 *   @0x214488 ror r9, r12, #2
 *   @0x21448c add r5, r5, r4
 *   @0x214490 mov r12, r1
 *   @0x214494 mov r4, r3
 *   @0x214498 bne 0x214450 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x168>
 *   @0x21449c add r7, r7, #316
 *   @0x2144a0 add r4, sp, #252
 *   @0x2144a4 b 0x2144b4 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1cc>
 *   @0x2144a8 mov r2, r9
 *   @0x2144ac mov r5, r12
 *   @0x2144b0 mov r9, r10
 *   @0x2144b4 ldr r10, [r4, #0x4]!
 *   @0x2144b8 movw r12, #0xc1d6
 *   @0x2144bc movt r12, #0xca62
 *   @0x2144c0 eor r6, r9, r1
 *   @0x2144c4 add r12, r10, r12
 *   @0x2144c8 eor r6, r6, r2
 *   @0x2144cc add r12, r12, r5, ror #27
 *   @0x2144d0 cmp r4, r7
 *   @0x2144d4 add r12, r12, r6
 *   @0x2144d8 ror r10, r1, #2
 *   @0x2144dc add r12, r12, r3
 *   @0x2144e0 mov r1, r5
 *   @0x2144e4 mov r3, r2
 *   @0x2144e8 bne 0x2144a8 <_Z23SHA1ProcessMessageBlockP11SHA1Context+0x1c0>
 *   @0x2144ec ldr r3, [sp]
 *   @0x2144f0 add r12, r12, r8
 *   @0x2144f4 str r12, [r0]
 *   @0x2144f8 add r5, r5, r3
 *   @0x2144fc ldr r3, [sp, #0x4]
 *   @0x214500 str r5, [r0, #0x4]
 *   @0x214504 add r10, r10, r3
 *   @0x214508 ldr r3, [sp, #0x8]
 *   @0x21450c str r10, [r0, #0x8]
 *   @0x214510 add r9, r9, r3
 *   @0x214514 ldr r3, [sp, #0xc]
 *   @0x214518 str r9, [r0, #0xc]
 *   @0x21451c add r2, r2, r3
 *   @0x214520 mov r3, #0
 *   @0x214524 str r2, [r0, #0x10]
 *   @0x214528 str r3, [r0, #0x5c]
 *   @0x21452c add sp, sp, #336
 *   @0x214530 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x214534 bx lr
 *
 * ══ §50/50 CBackground::LoadFromJPEGData(void*, int, bool, bool, bool, bool)  0xc271c  size 128  32 条（0xc271c..0xc279c）
 * @func 0xc271c 0xc279c  size 128  32 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ReadJPEGFile(void*, int, int*, int*, bool) / CBackground::LoadFromData(void*, int, int, bool, bool, bool, bool) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 0x40×1 / 0x38×1 / 0x3c×1 / 0xc×1 / 0x10×1 / 0x14×1 / 0x4×1 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc271c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xc2720 sub sp, sp, #28
 *   @0xc2724 mov r12, #0
 *   @0xc2728 mov r9, r0
 *   @0xc272c mov r8, r3
 *   @0xc2730 mov r0, r1
 *   @0xc2734 str r12, [sp]
 *   @0xc2738 mov r1, r2
 *   @0xc273c add r3, sp, #20
 *   @0xc2740 add r2, sp, #16
 *   @0xc2744 ldrb r5, [sp, #0x40]
 *   @0xc2748 ldrb r7, [sp, #0x38]
 *   @0xc274c ldrb r6, [sp, #0x3c]
 *   @0xc2750 bl 0x18a728 <_Z12ReadJPEGFilePviPiS0_b>
 *   @0xc2754 subs r4, r0, #0
 *   @0xc2758 moveq r5, r4
 *   @0xc275c beq 0xc2790 <_ZN11CBackground16LoadFromJPEGDataEPvibbbb+0x74>
 *   @0xc2760 str r5, [sp, #0xc]
 *   @0xc2764 mov r0, r9
 *   @0xc2768 ldr r2, [sp, #0x10]
 *   @0xc276c mov r1, r4
 *   @0xc2770 ldr r3, [sp, #0x14]
 *   @0xc2774 str r8, [sp]
 *   @0xc2778 str r7, [sp, #0x4]
 *   @0xc277c str r6, [sp, #0x8]
 *   @0xc2780 bl 0xc2618 <_ZN11CBackground12LoadFromDataEPviibbbb>
 *   @0xc2784 mov r5, r0
 *   @0xc2788 mov r0, r4
 *   @0xc278c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xc2790 mov r0, r5
 *   @0xc2794 add sp, sp, #28
 *   @0xc2798 pop {r4, r5, r6, r7, r8, r9, pc}
 */
