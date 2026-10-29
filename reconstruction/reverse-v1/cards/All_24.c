/* cally 逆向卡：All_24 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 12 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/12 CDS_Map::Set(RValue*, RValue*, RValue*)  0x208c3c  size 2860  715 条（0x208c3c..0x209768）
 * @func 0x208c3c 0x209768  size 2860  715 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×10 / UNLOCK_RVALUE_MUTEX()×10 / YYFree(void const*)×10 / operator delete(void*)×10 / GetContextStackTop()×6 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×6 / FREE_RValue__Pre(RValue*)×6 / _RefThing<char const*>::dec()×4
 * 字段偏移 top8: 0x8×32 / 0xc×24 / 0x4×20 / 0x10×19 / 0x1c×8 / 0x18×5 / 0x14×3 / 0x8e4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x208c3c push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x208c40 sub sp, sp, #8
 *   @0x208c44 mov r7, r2
 *   @0x208c48 mov r6, r3
 *   @0x208c4c mov r8, r0
 *   @0x208c50 mov r9, r1
 *   @0x208c54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x208c58 subs r4, r0, #0
 *   @0x208c5c beq 0x209204 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5c8>
 *   @0x208c60 cmp r6, #0
 *   @0x208c64 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208c68 ldr r2, [r6, #0xc]
 *   @0x208c6c bic r3, r2, #-16777216
 *   @0x208c70 cmp r3, #1
 *   @0x208c74 beq 0x208f7c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x340>
 *   @0x208c78 cmp r3, #2
 *   @0x208c7c bne 0x208ca4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x68>
 *   @0x208c80 sub r2, r2, #1
 *   @0x208c84 bic r2, r2, #-16777216
 *   @0x208c88 bic r2, r2, #3
 *   @0x208c8c cmp r2, #0
 *   @0x208c90 beq 0x2091e0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5a4>
 *   @0x208c94 mov r2, #0
 *   @0x208c98 mov r3, #5
 *   @0x208c9c str r2, [r6, #0x8]
 *   @0x208ca0 str r3, [r6, #0xc]
 *   @0x208ca4 ldr r3, [r4, #0x1c]
 *   @0x208ca8 mov r1, #0
 *   @0x208cac ldr r2, [r4, #0x18]
 *   @0x208cb0 str r1, [r6]
 *   @0x208cb4 str r3, [r6, #0xc]
 *   @0x208cb8 ldr r3, [r4, #0x1c]
 *   @0x208cbc str r2, [r6, #0x8]
 *   @0x208cc0 bic r3, r3, #-16777216
 *   @0x208cc4 cmp r3, #14
 *   @0x208cc8 addls pc, pc, r3, lsl #2
 *   @0x208ccc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208cd0 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374>
 *   @0x208cd4 b 0x209140 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x504>
 *   @0x208cd8 b 0x209158 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x51c>
 *   @0x208cdc b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0>
 *   @0x208ce0 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208ce4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208ce8 b 0x209184 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x548>
 *   @0x208cec b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0>
 *   @0x208cf0 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208cf4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208cf8 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374>
 *   @0x208cfc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208d00 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208d04 b 0x208fb0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x374>
 *   @0x208d08 b 0x208d0c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd0>
 *   @0x208d0c ldr r3, [r4, #0x10]
 *   @0x208d10 str r3, [r6]
 *   @0x208d14 ldr r2, [r4, #0xc]
 *   @0x208d18 bic r3, r2, #-16777216
 *   @0x208d1c cmp r3, #1
 *   @0x208d20 beq 0x208f14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2d8>
 *   @0x208d24 cmp r3, #2
 *   @0x208d28 bne 0x208d50 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x114>
 *   @0x208d2c sub r2, r2, #1
 *   @0x208d30 bic r2, r2, #-16777216
 *   @0x208d34 bic r2, r2, #3
 *   @0x208d38 cmp r2, #0
 *   @0x208d3c beq 0x2091ec <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5b0>
 *   @0x208d40 mov r2, #0
 *   @0x208d44 mov r3, #5
 *   @0x208d48 str r2, [r4, #0x8]
 *   @0x208d4c str r3, [r4, #0xc]
 *   @0x208d50 ldr r3, [r9, #0xc]
 *   @0x208d54 mov r1, #0
 *   @0x208d58 ldr r2, [r9, #0x8]
 *   @0x208d5c str r1, [r4]
 *   @0x208d60 str r3, [r4, #0xc]
 *   @0x208d64 ldr r3, [r9, #0xc]
 *   @0x208d68 str r2, [r4, #0x8]
 *   @0x208d6c bic r3, r3, #-16777216
 *   @0x208d70 cmp r3, #14
 *   @0x208d74 addls pc, pc, r3, lsl #2
 *   @0x208d78 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208d7c b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc>
 *   @0x208d80 b 0x208fc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x384>
 *   @0x208d84 b 0x209040 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x404>
 *   @0x208d88 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c>
 *   @0x208d8c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208d90 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208d94 b 0x20906c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x430>
 *   @0x208d98 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c>
 *   @0x208d9c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208da0 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208da4 b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc>
 *   @0x208da8 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208dac b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208db0 b 0x208f08 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2cc>
 *   @0x208db4 b 0x208db8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x17c>
 *   @0x208db8 ldr r3, [r9]
 *   @0x208dbc str r3, [r4]
 *   @0x208dc0 ldr r2, [r4, #0x1c]
 *   @0x208dc4 add r5, r4, #16
 *   @0x208dc8 bic r3, r2, #-16777216
 *   @0x208dcc cmp r3, #1
 *   @0x208dd0 beq 0x208f48 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x30c>
 *   @0x208dd4 cmp r3, #2
 *   @0x208dd8 bne 0x208e00 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1c4>
 *   @0x208ddc sub r2, r2, #1
 *   @0x208de0 bic r2, r2, #-16777216
 *   @0x208de4 bic r2, r2, #3
 *   @0x208de8 cmp r2, #0
 *   @0x208dec beq 0x2091f8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x5bc>
 *   @0x208df0 mov r2, #0
 *   @0x208df4 mov r3, #5
 *   @0x208df8 str r2, [r4, #0x18]
 *   @0x208dfc str r3, [r4, #0x1c]
 *   @0x208e00 ldr r3, [r7, #0xc]
 *   @0x208e04 mov r1, #0
 *   @0x208e08 ldr r2, [r7, #0x8]
 *   @0x208e0c str r1, [r4, #0x10]
 *   @0x208e10 str r3, [r4, #0x1c]
 *   @0x208e14 ldr r3, [r7, #0xc]
 *   @0x208e18 str r2, [r4, #0x18]
 *   @0x208e1c bic r3, r3, #-16777216
 *   @0x208e20 cmp r3, #14
 *   @0x208e24 addls pc, pc, r3, lsl #2
 *   @0x208e28 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e2c b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8>
 *   @0x208e30 b 0x208fd8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x39c>
 *   @0x208e34 b 0x208ff0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x3b4>
 *   @0x208e38 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8>
 *   @0x208e3c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e40 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e44 b 0x20901c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x3e0>
 *   @0x208e48 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8>
 *   @0x208e4c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e50 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e54 b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8>
 *   @0x208e58 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e5c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x208e60 b 0x208ef4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2b8>
 *   @0x208e64 b 0x208ee4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a8>
 *   @0x208e68 ldr r3, [r7]
 *   @0x208e6c str r3, [r4, #0x10]
 *   @0x208e70 ldr r5, [r8]
 *   @0x208e74 movw r2, #0x132
 *   @0x208e78 ldr r1, [pc, #0x8e4]
 *   @0x208e7c mov r3, #1
 *   @0x208e80 mov r0, #16
 *   @0x208e84 add r1, pc, r1
 *   @0x208e88 ldm r5, {r6, r7}
 *   @0x208e8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x208e90 and r7, r10, r7
 *   @0x208e94 ldr r2, [r6, r7, lsl #3]
 *   @0x208e98 add r3, r6, r7, lsl #3
 *   @0x208e9c cmp r2, #0
 *   @0x208ea0 ldrne r2, [r3, #0x4]
 *   @0x208ea4 movne r1, #0
 *   @0x208ea8 str r10, [r0, #0x8]
 *   @0x208eac str r4, [r0, #0xc]
 *   @0x208eb0 strne r2, [r0]
 *   @0x208eb4 streq r0, [r3, #0x4]
 *   @0x208eb8 strne r0, [r2, #0x4]
 *   @0x208ebc strne r0, [r3, #0x4]
 *   @0x208ec0 ldr r3, [r5, #0x8]
 *   @0x208ec4 streq r0, [r6, r7, lsl #3]
 *   @0x208ec8 strne r1, [r0, #0x4]
 *   @0x208ecc add r3, r3, #1
 *   @0x208ed0 streq r2, [r0, #0x4]
 *   @0x208ed4 streq r2, [r0]
 *   @0x208ed8 str r3, [r5, #0x8]
 *   @0x208edc add sp, sp, #8
 *   @0x208ee0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x208ee4 ldr r3, [r7]
 *   @0x208ee8 str r3, [r4, #0x10]
 *   @0x208eec add sp, sp, #8
 *   @0x208ef0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x208ef4 ldm r7, {r2, r3}
 *   @0x208ef8 str r2, [r4, #0x10]
 *   @0x208efc str r3, [r4, #0x14]
 *   @0x208f00 add sp, sp, #8
 *   @0x208f04 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x208f08 ldm r9, {r2, r3}
 *   @0x208f0c stm r4, {r2, r3}
 *   @0x208f10 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x208f14 ldr r5, [r4]
 *   @0x208f18 cmp r5, #0
 *   @0x208f1c beq 0x208f3c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x300>
 *   @0x208f20 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x208f24 ldr r6, [r5, #0x4]
 *   @0x208f28 sub r6, r6, #1
 *   @0x208f2c str r6, [r5, #0x4]
 *   @0x208f30 cmp r6, #0
 *   @0x208f34 beq 0x209090 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x454>
 *   @0x208f38 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x208f3c mov r3, #0
 *   @0x208f40 str r3, [r4]
 *   @0x208f44 b 0x208d50 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x114>
 *   @0x208f48 ldr r6, [r4, #0x10]
 *   @0x208f4c cmp r6, #0
 *   @0x208f50 beq 0x208f70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x334>
 *   @0x208f54 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x208f58 ldr r8, [r6, #0x4]
 *   @0x208f5c sub r8, r8, #1
 *   @0x208f60 str r8, [r6, #0x4]
 *   @0x208f64 cmp r8, #0
 *   @0x208f68 beq 0x2090e8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x4ac>
 *   @0x208f6c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x208f70 mov r3, #0
 *   @0x208f74 str r3, [r4, #0x10]
 *   @0x208f78 b 0x208e00 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1c4>
 *   @0x208f7c ldr r5, [r6]
 *   @0x208f80 cmp r5, #0
 *   @0x208f84 beq 0x208fa4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x368>
 *   @0x208f88 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x208f8c ldr r8, [r5, #0x4]
 *   @0x208f90 sub r8, r8, #1
 *   @0x208f94 str r8, [r5, #0x4]
 *   @0x208f98 cmp r8, #0
 *   @0x208f9c beq 0x2091a8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x56c>
 *   @0x208fa0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x208fa4 mov r3, #0
 *   @0x208fa8 str r3, [r6]
 *   @0x208fac b 0x208ca4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x68>
 *   @0x208fb0 ldr r2, [r4, #0x10]
 *   @0x208fb4 ldr r3, [r4, #0x14]
 *   @0x208fb8 stm r6, {r2, r3}
 *   @0x208fbc b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x208fc0 ldr r3, [r9]
 *   @0x208fc4 cmp r3, #0
 *   @0x208fc8 ldrne r2, [r3, #0x4]
 *   @0x208fcc addne r2, r2, #1
 *   @0x208fd0 strne r2, [r3, #0x4]
 *   @0x208fd4 b 0x208dbc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x180>
 *   @0x208fd8 ldr r3, [r7]
 *   @0x208fdc cmp r3, #0
 *   @0x208fe0 ldrne r2, [r3, #0x4]
 *   @0x208fe4 addne r2, r2, #1
 *   @0x208fe8 strne r2, [r3, #0x4]
 *   @0x208fec b 0x208ee8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2ac>
 *   @0x208ff0 ldr r3, [r7]
 *   @0x208ff4 cmp r3, #0
 *   @0x208ff8 str r3, [r4, #0x10]
 *   @0x208ffc beq 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x209000 ldr r1, [r3, #0x8]
 *   @0x209004 ldr r2, [r3]
 *   @0x209008 cmp r1, #0
 *   @0x20900c streq r5, [r3, #0x8]
 *   @0x209010 add r2, r2, #1
 *   @0x209014 str r2, [r3]
 *   @0x209018 b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x20901c ldr r3, [r7]
 *   @0x209020 str r3, [r4, #0x10]
 *   @0x209024 ldr r3, [r7]
 *   @0x209028 cmp r3, #0
 *   @0x20902c beq 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x209030 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x209034 ldr r1, [r7]
 *   @0x209038 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20903c b 0x208edc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2a0>
 *   @0x209040 ldr r3, [r9]
 *   @0x209044 cmp r3, #0
 *   @0x209048 str r3, [r4]
 *   @0x20904c beq 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x209050 ldr r1, [r3, #0x8]
 *   @0x209054 ldr r2, [r3]
 *   @0x209058 cmp r1, #0
 *   @0x20905c streq r4, [r3, #0x8]
 *   @0x209060 add r2, r2, #1
 *   @0x209064 str r2, [r3]
 *   @0x209068 b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x20906c ldr r3, [r9]
 *   @0x209070 str r3, [r4]
 *   @0x209074 ldr r3, [r9]
 *   @0x209078 cmp r3, #0
 *   @0x20907c beq 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x209080 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x209084 ldr r1, [r9]
 *   @0x209088 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20908c b 0x208dc0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x184>
 *   @0x209090 ldr r0, [r5]
 *   @0x209094 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209098 str r6, [r5]
 *   @0x20909c str r6, [r5, #0x8]
 *   @0x2090a0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2090a4 ldr r6, [r5, #0x4]
 *   @0x2090a8 sub r6, r6, #1
 *   @0x2090ac str r6, [r5, #0x4]
 *   @0x2090b0 cmp r6, #0
 *   @0x2090b4 bne 0x2090d8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x49c>
 *   @0x2090b8 ldr r0, [r5]
 *   @0x2090bc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2090c0 mov r0, r5
 *   @0x2090c4 str r6, [r5]
 *   @0x2090c8 str r6, [r5, #0x8]
 *   @0x2090cc bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x2090d0 mov r0, r5
 *   @0x2090d4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2090d8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2090dc mov r0, r5
 *   @0x2090e0 bl 0x27d1d0 <_ZdlPv>
 *   @0x2090e4 b 0x208f38 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x2fc>
 *   @0x2090e8 ldr r0, [r6]
 *   @0x2090ec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2090f0 str r8, [r6]
 *   @0x2090f4 str r8, [r6, #0x8]
 *   @0x2090f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2090fc ldr r8, [r6, #0x4]
 *   @0x209100 sub r8, r8, #1
 *   @0x209104 str r8, [r6, #0x4]
 *   @0x209108 cmp r8, #0
 *   @0x20910c bne 0x209130 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x4f4>
 *   @0x209110 ldr r0, [r6]
 *   @0x209114 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209118 mov r0, r6
 *   @0x20911c str r8, [r6]
 *   @0x209120 str r8, [r6, #0x8]
 *   @0x209124 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x209128 mov r0, r6
 *   @0x20912c bl 0x27d1d0 <_ZdlPv>
 *   @0x209130 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209134 mov r0, r6
 *   @0x209138 bl 0x27d1d0 <_ZdlPv>
 *   @0x20913c b 0x208f6c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x330>
 *   @0x209140 ldr r3, [r4, #0x10]
 *   @0x209144 cmp r3, #0
 *   @0x209148 ldrne r2, [r3, #0x4]
 *   @0x20914c addne r2, r2, #1
 *   @0x209150 strne r2, [r3, #0x4]
 *   @0x209154 b 0x208d10 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd4>
 *   @0x209158 ldr r3, [r4, #0x10]
 *   @0x20915c cmp r3, #0
 *   @0x209160 str r3, [r6]
 *   @0x209164 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x209168 ldr r1, [r3, #0x8]
 *   @0x20916c ldr r2, [r3]
 *   @0x209170 cmp r1, #0
 *   @0x209174 streq r6, [r3, #0x8]
 *   @0x209178 add r2, r2, #1
 *   @0x20917c str r2, [r3]
 *   @0x209180 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x209184 ldr r3, [r4, #0x10]
 *   @0x209188 str r3, [r6]
 *   @0x20918c ldr r3, [r4, #0x10]
 *   @0x209190 cmp r3, #0
 *   @0x209194 beq 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x209198 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20919c ldr r1, [r4, #0x10]
 *   @0x2091a0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2091a4 b 0x208d14 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xd8>
 *   @0x2091a8 ldr r0, [r5]
 *   @0x2091ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2091b0 str r8, [r5]
 *   @0x2091b4 str r8, [r5, #0x8]
 *   @0x2091b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2091bc ldr r8, [r5, #0x4]
 *   @0x2091c0 sub r8, r8, #1
 *   @0x2091c4 str r8, [r5, #0x4]
 *   @0x2091c8 cmp r8, #0
 *   @0x2091cc beq 0x2092f0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6b4>
 *   @0x2091d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2091d4 mov r0, r5
 *   @0x2091d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x2091dc b 0x208fa0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x364>
 *   @0x2091e0 mov r0, r6
 *   @0x2091e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2091e8 b 0x208c94 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x58>
 *   @0x2091ec mov r0, r4
 *   @0x2091f0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2091f4 b 0x208d40 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x104>
 *   @0x2091f8 mov r0, r5
 *   @0x2091fc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x209200 b 0x208df0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x1b4>
 *   @0x209204 ldr r3, [r9, #0xc]
 *   @0x209208 bic r3, r3, #-16777216
 *   @0x20920c cmp r3, #6
 *   @0x209210 beq 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04>
 *   @0x209214 bgt 0x209314 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6d8>
 *   @0x209218 cmp r3, #4
 *   @0x20921c bgt 0x20932c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f0>
 *   @0x209220 cmp r3, #2
 *   @0x209224 bge 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04>
 *   @0x209228 cmp r3, #1
 *   @0x20922c bne 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18>
 *   @0x209230 ldr r0, [r9]
 *   @0x209234 cmp r0, #0
 *   @0x209238 ldrne r0, [r0]
 *   @0x20923c bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x209240 mov r10, r0
 *   @0x209244 cmp r6, #0
 *   @0x209248 beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x20924c ldr r2, [r6, #0xc]
 *   @0x209250 bic r3, r2, #-16777216
 *   @0x209254 cmp r3, #1
 *   @0x209258 beq 0x209600 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9c4>
 *   @0x20925c cmp r3, #2
 *   @0x209260 bne 0x209288 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x64c>
 *   @0x209264 sub r3, r2, #1
 *   @0x209268 bic r3, r3, #-16777216
 *   @0x20926c bic r3, r3, #3
 *   @0x209270 cmp r3, #0
 *   @0x209274 beq 0x2096bc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa80>
 *   @0x209278 mov r2, #0
 *   @0x20927c mov r3, #5
 *   @0x209280 str r2, [r6, #0x8]
 *   @0x209284 str r3, [r6, #0xc]
 *   @0x209288 ldr r3, [r7, #0xc]
 *   @0x20928c mov r1, #0
 *   @0x209290 ldr r2, [r7, #0x8]
 *   @0x209294 str r1, [r6]
 *   @0x209298 str r3, [r6, #0xc]
 *   @0x20929c ldr r3, [r7, #0xc]
 *   @0x2092a0 str r2, [r6, #0x8]
 *   @0x2092a4 bic r3, r3, #-16777216
 *   @0x2092a8 cmp r3, #14
 *   @0x2092ac addls pc, pc, r3, lsl #2
 *   @0x2092b0 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092b4 b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868>
 *   @0x2092b8 b 0x2095d0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x994>
 *   @0x2092bc b 0x209580 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x944>
 *   @0x2092c0 b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8>
 *   @0x2092c4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092c8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092cc b 0x2095ac <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x970>
 *   @0x2092d0 b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8>
 *   @0x2092d4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092d8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092dc b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868>
 *   @0x2092e0 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092e4 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2092e8 b 0x2094a4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x868>
 *   @0x2092ec b 0x209334 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6f8>
 *   @0x2092f0 ldr r0, [r5]
 *   @0x2092f4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2092f8 mov r0, r5
 *   @0x2092fc str r8, [r5]
 *   @0x209300 str r8, [r5, #0x8]
 *   @0x209304 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x209308 mov r0, r5
 *   @0x20930c bl 0x27d1d0 <_ZdlPv>
 *   @0x209310 b 0x2091d0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x594>
 *   @0x209314 cmp r3, #11
 *   @0x209318 beq 0x209640 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa04>
 *   @0x20931c ble 0x209634 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9f8>
 *   @0x209320 mvn r2, #-16777216
 *   @0x209324 cmp r3, r2
 *   @0x209328 bne 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18>
 *   @0x20932c mov r10, #0
 *   @0x209330 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608>
 *   @0x209334 ldr r3, [r7]
 *   @0x209338 str r3, [r6]
 *   @0x20933c mov r0, #32
 *   @0x209340 bl 0x27c524 <_Znwj>
 *   @0x209344 mov r1, #0
 *   @0x209348 mov r2, #16
 *   @0x20934c add r5, r0, #16
 *   @0x209350 mov r4, r0
 *   @0x209354 bl 0xb65b0 <memset@plt>
 *   @0x209358 mov r1, #0
 *   @0x20935c mov r0, r5
 *   @0x209360 mov r2, #16
 *   @0x209364 bl 0xb65b0 <memset@plt>
 *   @0x209368 ldr r3, [r4, #0xc]
 *   @0x20936c sub r3, r3, #1
 *   @0x209370 bic r3, r3, #-16777216
 *   @0x209374 bic r3, r3, #3
 *   @0x209378 cmp r3, #0
 *   @0x20937c beq 0x2095e8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9ac>
 *   @0x209380 mov r3, #5
 *   @0x209384 str r3, [r4, #0xc]
 *   @0x209388 ldr r3, [r9, #0xc]
 *   @0x20938c mov r2, #0
 *   @0x209390 str r2, [r4, #0x8]
 *   @0x209394 ldr r1, [r9, #0x8]
 *   @0x209398 str r3, [r4, #0xc]
 *   @0x20939c ldr r3, [r9, #0xc]
 *   @0x2093a0 str r2, [r4]
 *   @0x2093a4 bic r3, r3, #-16777216
 *   @0x2093a8 str r1, [r4, #0x8]
 *   @0x2093ac cmp r3, #14
 *   @0x2093b0 addls pc, pc, r3, lsl #2
 *   @0x2093b4 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093b8 b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c>
 *   @0x2093bc b 0x209568 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x92c>
 *   @0x2093c0 b 0x20953c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x900>
 *   @0x2093c4 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8>
 *   @0x2093c8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093cc b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093d0 b 0x209518 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x8dc>
 *   @0x2093d4 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8>
 *   @0x2093d8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093dc b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093e0 b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c>
 *   @0x2093e4 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093e8 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x2093ec b 0x209488 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x84c>
 *   @0x2093f0 b 0x2093f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7b8>
 *   @0x2093f4 ldr r3, [r9]
 *   @0x2093f8 str r3, [r4]
 *   @0x2093fc ldr r3, [r4, #0x1c]
 *   @0x209400 sub r3, r3, #1
 *   @0x209404 bic r3, r3, #-16777216
 *   @0x209408 bic r3, r3, #3
 *   @0x20940c cmp r3, #0
 *   @0x209410 beq 0x2095f4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9b8>
 *   @0x209414 mov r3, #5
 *   @0x209418 str r3, [r4, #0x1c]
 *   @0x20941c ldr r3, [r7, #0xc]
 *   @0x209420 mov r2, #0
 *   @0x209424 str r2, [r4, #0x18]
 *   @0x209428 ldr r1, [r7, #0x8]
 *   @0x20942c str r3, [r4, #0x1c]
 *   @0x209430 ldr r3, [r7, #0xc]
 *   @0x209434 str r2, [r4, #0x10]
 *   @0x209438 bic r3, r3, #-16777216
 *   @0x20943c str r1, [r4, #0x18]
 *   @0x209440 cmp r3, #14
 *   @0x209444 addls pc, pc, r3, lsl #2
 *   @0x209448 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x20944c b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858>
 *   @0x209450 b 0x209500 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x8c4>
 *   @0x209454 b 0x2094d4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x898>
 *   @0x209458 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c>
 *   @0x20945c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209460 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209464 b 0x2094b0 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x874>
 *   @0x209468 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c>
 *   @0x20946c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209470 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209474 b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858>
 *   @0x209478 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x20947c b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209480 b 0x209494 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x858>
 *   @0x209484 b 0x208e68 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x22c>
 *   @0x209488 ldm r9, {r2, r3}
 *   @0x20948c stm r4, {r2, r3}
 *   @0x209490 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x209494 ldm r7, {r2, r3}
 *   @0x209498 str r2, [r4, #0x10]
 *   @0x20949c str r3, [r4, #0x14]
 *   @0x2094a0 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x2094a4 ldm r7, {r2, r3}
 *   @0x2094a8 stm r6, {r2, r3}
 *   @0x2094ac b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2094b0 ldr r3, [r7]
 *   @0x2094b4 str r3, [r4, #0x10]
 *   @0x2094b8 ldr r3, [r7]
 *   @0x2094bc cmp r3, #0
 *   @0x2094c0 beq 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x2094c4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2094c8 ldr r1, [r7]
 *   @0x2094cc bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2094d0 b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x2094d4 ldr r3, [r7]
 *   @0x2094d8 cmp r3, #0
 *   @0x2094dc str r3, [r4, #0x10]
 *   @0x2094e0 beq 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x2094e4 ldr r1, [r3, #0x8]
 *   @0x2094e8 ldr r2, [r3]
 *   @0x2094ec cmp r1, #0
 *   @0x2094f0 streq r5, [r3, #0x8]
 *   @0x2094f4 add r2, r2, #1
 *   @0x2094f8 str r2, [r3]
 *   @0x2094fc b 0x208e70 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x234>
 *   @0x209500 ldr r3, [r7]
 *   @0x209504 cmp r3, #0
 *   @0x209508 ldrne r2, [r3, #0x4]
 *   @0x20950c addne r2, r2, #1
 *   @0x209510 strne r2, [r3, #0x4]
 *   @0x209514 b 0x208e6c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x230>
 *   @0x209518 ldr r3, [r9]
 *   @0x20951c str r3, [r4]
 *   @0x209520 ldr r3, [r9]
 *   @0x209524 cmp r3, #0
 *   @0x209528 beq 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x20952c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x209530 ldr r1, [r9]
 *   @0x209534 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x209538 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x20953c ldr r3, [r9]
 *   @0x209540 cmp r3, #0
 *   @0x209544 str r3, [r4]
 *   @0x209548 beq 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x20954c ldr r1, [r3, #0x8]
 *   @0x209550 ldr r2, [r3]
 *   @0x209554 cmp r1, #0
 *   @0x209558 streq r4, [r3, #0x8]
 *   @0x20955c add r2, r2, #1
 *   @0x209560 str r2, [r3]
 *   @0x209564 b 0x2093fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7c0>
 *   @0x209568 ldr r3, [r9]
 *   @0x20956c cmp r3, #0
 *   @0x209570 ldrne r2, [r3, #0x4]
 *   @0x209574 addne r2, r2, #1
 *   @0x209578 strne r2, [r3, #0x4]
 *   @0x20957c b 0x2093f8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7bc>
 *   @0x209580 ldr r3, [r7]
 *   @0x209584 cmp r3, #0
 *   @0x209588 str r3, [r6]
 *   @0x20958c beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x209590 ldr r1, [r3, #0x8]
 *   @0x209594 ldr r2, [r3]
 *   @0x209598 cmp r1, #0
 *   @0x20959c streq r6, [r3, #0x8]
 *   @0x2095a0 add r2, r2, #1
 *   @0x2095a4 str r2, [r3]
 *   @0x2095a8 b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2095ac ldr r3, [r7]
 *   @0x2095b0 str r3, [r6]
 *   @0x2095b4 ldr r3, [r7]
 *   @0x2095b8 cmp r3, #0
 *   @0x2095bc beq 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2095c0 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x2095c4 ldr r1, [r7]
 *   @0x2095c8 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x2095cc b 0x20933c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x700>
 *   @0x2095d0 ldr r3, [r7]
 *   @0x2095d4 cmp r3, #0
 *   @0x2095d8 ldrne r2, [r3, #0x4]
 *   @0x2095dc addne r2, r2, #1
 *   @0x2095e0 strne r2, [r3, #0x4]
 *   @0x2095e4 b 0x209338 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x6fc>
 *   @0x2095e8 mov r0, r4
 *   @0x2095ec bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2095f0 b 0x209380 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x744>
 *   @0x2095f4 mov r0, r5
 *   @0x2095f8 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2095fc b 0x209414 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x7d8>
 *   @0x209600 ldr r4, [r6]
 *   @0x209604 cmp r4, #0
 *   @0x209608 beq 0x209628 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9ec>
 *   @0x20960c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209610 ldr r5, [r4, #0x4]
 *   @0x209614 sub r5, r5, #1
 *   @0x209618 str r5, [r4, #0x4]
 *   @0x20961c cmp r5, #0
 *   @0x209620 beq 0x209684 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa48>
 *   @0x209624 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209628 mov r3, #0
 *   @0x20962c str r3, [r6]
 *   @0x209630 b 0x209288 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x64c>
 *   @0x209634 sub r2, r3, #8
 *   @0x209638 cmp r2, #1
 *   @0x20963c bhi 0x209654 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa18>
 *   @0x209640 mov r0, r9
 *   @0x209644 mov r1, #8
 *   @0x209648 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20964c mov r10, r0
 *   @0x209650 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608>
 *   @0x209654 cmp r3, #0
 *   @0x209658 bne 0x2096c8 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa8c>
 *   @0x20965c ldm r9, {r0, r1}
 *   @0x209660 mov r4, r0
 *   @0x209664 add r0, sp, #8
 *   @0x209668 mov r5, r1
 *   @0x20966c mov r1, #8
 *   @0x209670 strd r4, r5, [r0, #-8]!
 *   @0x209674 mov r0, sp
 *   @0x209678 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20967c mov r10, r0
 *   @0x209680 b 0x209244 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x608>
 *   @0x209684 ldr r0, [r4]
 *   @0x209688 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20968c str r5, [r4]
 *   @0x209690 str r5, [r4, #0x8]
 *   @0x209694 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209698 ldr r5, [r4, #0x4]
 *   @0x20969c sub r5, r5, #1
 *   @0x2096a0 str r5, [r4, #0x4]
 *   @0x2096a4 cmp r5, #0
 *   @0x2096a8 beq 0x2096d4 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa98>
 *   @0x2096ac bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x2096b0 mov r0, r4
 *   @0x2096b4 bl 0x27d1d0 <_ZdlPv>
 *   @0x2096b8 b 0x209624 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x9e8>
 *   @0x2096bc mov r0, r6
 *   @0x2096c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x2096c4 b 0x209278 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0x63c>
 *   @0x2096c8 mov r0, r9
 *   @0x2096cc bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x2096d0 b 0x209660 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa24>
 *   @0x2096d4 ldr r0, [r4]
 *   @0x2096d8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x2096dc str r5, [r4]
 *   @0x2096e0 str r5, [r4, #0x8]
 *   @0x2096e4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x2096e8 ldr r5, [r4, #0x4]
 *   @0x2096ec sub r5, r5, #1
 *   @0x2096f0 str r5, [r4, #0x4]
 *   @0x2096f4 cmp r5, #0
 *   @0x2096f8 beq 0x20970c <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xad0>
 *   @0x2096fc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209700 mov r0, r4
 *   @0x209704 bl 0x27d1d0 <_ZdlPv>
 *   @0x209708 b 0x2096ac <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xa70>
 *   @0x20970c ldr r0, [r4]
 *   @0x209710 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x209714 str r5, [r4]
 *   @0x209718 str r5, [r4, #0x8]
 *   @0x20971c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x209720 ldr r5, [r4, #0x4]
 *   @0x209724 sub r5, r5, #1
 *   @0x209728 str r5, [r4, #0x4]
 *   @0x20972c cmp r5, #0
 *   @0x209730 bne 0x209754 <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xb18>
 *   @0x209734 ldr r0, [r4]
 *   @0x209738 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20973c mov r0, r4
 *   @0x209740 str r5, [r4]
 *   @0x209744 str r5, [r4, #0x8]
 *   @0x209748 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20974c mov r0, r4
 *   @0x209750 bl 0x27d1d0 <_ZdlPv>
 *   @0x209754 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x209758 mov r0, r4
 *   @0x20975c bl 0x27d1d0 <_ZdlPv>
 *   @0x209760 b 0x2096fc <_ZN7CDS_Map3SetEP6RValueS1_S1_+0xac0>
 *   @0x209764 andseq r3, r4, r8, lsr #28
 *
 * ══ §2/12 ProcessCommandLine(char*)  0x2a1cf0  size 2828  700 条（0x2a1cf0..0x2a27fc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x2a1cf0 0x2a27fc  size 2828  700 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a1d00→0x3f5114, 0x2a1d0c→0x75527c, 0x2a1d10→0x5346cd, 0x2a1d1c→0x5346cc, 0x2a1d20→0x3f2090, 0x2a1d30→0x755363, 0x2a1d34→0x757f10, 0x2a1d4c→0x4a2018
 * 调用序列: 0xb6574×30 / GetNextCmd(int, char*)×11 / 0xb6538×10 / MemoryManager::Alloc(unsigned int, char const*, int, bool)×6 / 0xb65a4×6 / MemoryManager::Free(void const*)×4 / 0xb65e0×2 / 0xb66b8×2
 * 字段偏移 top8: 0x30×10 / 0x4×10 / 0x34×6 / 0x20×3 / 0xc×3 / 0x920×3 / 0x990×2 / 0x988×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a1cf0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a1cf4 sub sp, sp, #60
 *   @0x2a1cf8 ldr r5, [pc, #0x99c]
 *   @0x2a1cfc mov r3, #0
 *   @0x2a1d00 ldr r12, [pc, #0x998]
 *   @0x2a1d04 mov r2, #1
 *   @0x2a1d08 add r5, pc, r5
 *   @0x2a1d0c ldr r1, [pc, #0x990]
 *   @0x2a1d10 ldr r8, [pc, #0x990]
 *   @0x2a1d14 subs r7, r0, #0
 *   @0x2a1d18 ldr r12, [r5, r12]
 *   @0x2a1d1c ldr r6, [pc, #0x988]
 *   @0x2a1d20 ldr r4, [pc, #0x988]
 *   @0x2a1d24 str r12, [sp, #0x10]
 *   @0x2a1d44 str r1, [sp, #0x20]
 *   @0x2a1d48 ldr r8, [sp, #0x20]
 *   @0x2a1d4c ldr r1, [pc, #0x968]
 *   @0x2a1d50 strb r3, [r8]
 *   @0x2a1d54 ldr r6, [r5, r6]
 *   @0x2a1d58 str r6, [sp, #0x24]
 *   @0x2a1d5c strb r3, [r6]
 *   @0x2a1d60 ldr r4, [r5, r4]
 *   @0x2a1d64 str r4, [sp, #0x14]
 *   @0x2a1d68 strb r2, [r4]
 *   @0x2a1d6c ldr r2, [r5, r12]
 *   @0x2a1d70 strb r3, [r2]
 *   @0x2a1d74 str r2, [sp, #0x18]
 *   @0x2a1d78 ldr r2, [r5, r0]
 *   @0x2a1d7c strb r3, [r2]
 *   @0x2a1d80 str r2, [sp, #0x1c]
 *   @0x2a1d84 ldr r2, [r5, r1]
 *   @0x2a1d88 str r2, [sp, #0xc]
 *   @0x2a1d8c str r3, [r2]
 *   @0x2a1d90 beq 0x2a1e54 <_Z18ProcessCommandLinePc+0x164>
 *   @0x2a1d94 ldr r2, [pc, #0x924]
 *   @0x2a1d98 mov r4, r3
 *   @0x2a1d9c ldr r9, [pc, #0x920]
 *   @0x2a1da0 ldr r8, [pc, #0x920]
 *   @0x2a1da4 ldr r6, [pc, #0x920]
 *   @0x2a1da8 add r9, pc, r9
 *   @0x2a1dac ldr r10, [pc, #0x91c]
 *   @0x2a1db0 add r8, pc, r8
 *   @0x2a1db4 ldr r11, [pc, #0x918]
 *   @0x2a1db8 add r6, pc, r6
 *   @0x2a1dbc ldr r2, [r5, r2]
 *   @0x2a1dc0 add r10, pc, r10
 *   @0x2a1dc4 str r6, [sp, #0x28]
 *   @0x2a1dc8 add r11, pc, r11
 *   @0x2a1dcc ldr r6, [pc, #0x904]
 *   @0x2a1dd0 str r3, [r2]
 *   @0x2a1dd4 add r6, pc, r6
 *   @0x2a1dd8 str r6, [sp, #0x2c]
 *   @0x2a1ddc ldrb r3, [r7, r4]
 *   @0x2a1de0 cmp r3, #0
 *   @0x2a1de4 beq 0x2a1e54 <_Z18ProcessCommandLinePc+0x164>
 *   @0x2a1de8 mov r0, r4
 *   @0x2a1dec mov r1, r7
 *   @0x2a1df0 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a1df4 ldr r3, [pc, #0x8e0]
 *   @0x2a1df8 ldr r1, [pc, #0x8e0]
 *   @0x2a1dfc ldr r6, [r5, r3]
 *   @0x2a1e00 add r1, pc, r1
 *   @0x2a1e04 mov r4, r0
 *   @0x2a1e08 mov r0, r6
 *   @0x2a1e0c bl 0xb6574 <strcmp@plt>
 *   @0x2a1e10 cmp r0, #0
 *   @0x2a1e14 bne 0x2a1e5c <_Z18ProcessCommandLinePc+0x16c>
 *   @0x2a1e18 ldr r3, [pc, #0x8c4]
 *   @0x2a1e1c ldr r3, [r5, r3]
 *   @0x2a1e20 ldr r3, [r3]
 *   @0x2a1e24 cmp r3, #0
 *   @0x2a1e28 bne 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1e2c ldr r6, [sp, #0x10]
 *   @0x2a1e30 mov r3, #1
 *   @0x2a1e34 strb r3, [r6]
 *   @0x2a1e38 mov r3, #2
 *   @0x2a1e3c ldr r6, [sp, #0xc]
 *   @0x2a1e40 str r3, [r6]
 *   @0x2a1e44 bl 0x237b88 <_ZN13CPhysicsWorld12SetDebugModeEv>
 *   @0x2a1e48 ldrb r3, [r7, r4]
 *   @0x2a1e4c cmp r3, #0
 *   @0x2a1e50 bne 0x2a1de8 <_Z18ProcessCommandLinePc+0xf8>
 *   @0x2a1e54 add sp, sp, #60
 *   @0x2a1e58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2a1e5c ldr r1, [pc, #0x884]
 *   @0x2a1e60 mov r0, r6
 *   @0x2a1e64 add r1, pc, r1
 *   @0x2a1e68 bl 0xb6574 <strcmp@plt>
 *   @0x2a1e6c cmp r0, #0
 *   @0x2a1e70 bne 0x2a1e88 <_Z18ProcessCommandLinePc+0x198>
 *   @0x2a1e74 ldr r3, [pc, #0x870]
 *   @0x2a1e78 mov r2, #1
 *   @0x2a1e7c ldr r3, [r5, r3]
 *   @0x2a1e80 strb r2, [r3]
 *   @0x2a1e84 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1e88 ldr r1, [pc, #0x860]
 *   @0x2a1e8c mov r0, r6
 *   @0x2a1e90 add r1, pc, r1
 *   @0x2a1e94 bl 0xb6574 <strcmp@plt>
 *   @0x2a1e98 cmp r0, #0
 *   @0x2a1e9c bne 0x2a1eb4 <_Z18ProcessCommandLinePc+0x1c4>
 *   @0x2a1ea0 ldr r3, [pc, #0x84c]
 *   @0x2a1ea4 mov r2, #1
 *   @0x2a1ea8 ldr r3, [r5, r3]
 *   @0x2a1eac strb r2, [r3]
 *   @0x2a1eb0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1eb4 ldr r1, [pc, #0x83c]
 *   @0x2a1eb8 mov r0, r6
 *   @0x2a1ebc add r1, pc, r1
 *   @0x2a1ec0 bl 0xb6574 <strcmp@plt>
 *   @0x2a1ec4 cmp r0, #0
 *   @0x2a1ec8 ldreq r6, [sp, #0x8]
 *   @0x2a1ecc moveq r3, #1
 *   @0x2a1ed0 strbeq r3, [r6]
 *   @0x2a1ed4 beq 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1ed8 ldr r1, [pc, #0x81c]
 *   @0x2a1edc mov r0, r6
 *   @0x2a1ee0 add r1, pc, r1
 *   @0x2a1ee4 bl 0xb6574 <strcmp@plt>
 *   @0x2a1ee8 cmp r0, #0
 *   @0x2a1eec ldreq r3, [pc, #0x80c]
 *   @0x2a1ef0 ldreq r3, [r5, r3]
 *   @0x2a1ef4 strbeq r0, [r3]
 *   @0x2a1ef8 beq 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1efc ldr r1, [pc, #0x800]
 *   @0x2a1f00 mov r0, r6
 *   @0x2a1f04 add r1, pc, r1
 *   @0x2a1f08 bl 0xb6574 <strcmp@plt>
 *   @0x2a1f0c cmp r0, #0
 *   @0x2a1f10 beq 0x2a1f3c <_Z18ProcessCommandLinePc+0x24c>
 *   @0x2a1f14 ldr r1, [pc, #0x7ec]
 *   @0x2a1f18 mov r0, r6
 *   @0x2a1f1c add r1, pc, r1
 *   @0x2a1f20 bl 0xb6574 <strcmp@plt>
 *   @0x2a1f24 cmp r0, #0
 *   @0x2a1f28 bne 0x2a1f48 <_Z18ProcessCommandLinePc+0x258>
 *   @0x2a1f2c ldr r6, [sp, #0x18]
 *   @0x2a1f30 mov r3, #1
 *   @0x2a1f34 strb r3, [r6]
 *   @0x2a1f38 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1f3c ldr r6, [sp, #0x14]
 *   @0x2a1f40 strb r0, [r6]
 *   @0x2a1f44 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1f48 ldr r1, [pc, #0x7bc]
 *   @0x2a1f4c mov r0, r6
 *   @0x2a1f50 add r1, pc, r1
 *   @0x2a1f54 bl 0xb6574 <strcmp@plt>
 *   @0x2a1f58 cmp r0, #0
 *   @0x2a1f5c beq 0x2a1ff4 <_Z18ProcessCommandLinePc+0x304>
 *   @0x2a1f60 ldr r1, [pc, #0x7a8]
 *   @0x2a1f64 mov r0, r6
 *   @0x2a1f68 add r1, pc, r1
 *   @0x2a1f6c bl 0xb6574 <strcmp@plt>
 *   @0x2a1f70 cmp r0, #0
 *   @0x2a1f74 beq 0x2a2004 <_Z18ProcessCommandLinePc+0x314>
 *   @0x2a1f78 ldr r1, [pc, #0x794]
 *   @0x2a1f7c mov r0, r6
 *   @0x2a1f80 add r1, pc, r1
 *   @0x2a1f84 bl 0xb6574 <strcmp@plt>
 *   @0x2a1f88 cmp r0, #0
 *   @0x2a1f8c str r0, [sp, #0x34]
 *   @0x2a1f90 beq 0x2a2070 <_Z18ProcessCommandLinePc+0x380>
 *   @0x2a1f94 ldr r1, [pc, #0x77c]
 *   @0x2a1f98 mov r0, r6
 *   @0x2a1f9c add r1, pc, r1
 *   @0x2a1fa0 bl 0xb6574 <strcmp@plt>
 *   @0x2a1fa4 cmp r0, #0
 *   @0x2a1fa8 str r0, [sp, #0x34]
 *   @0x2a1fac beq 0x2a20ec <_Z18ProcessCommandLinePc+0x3fc>
 *   @0x2a1fb0 ldr r1, [pc, #0x764]
 *   @0x2a1fb4 mov r0, r6
 *   @0x2a1fb8 add r1, pc, r1
 *   @0x2a1fbc bl 0xb6574 <strcmp@plt>
 *   @0x2a1fc0 cmp r0, #0
 *   @0x2a1fc4 beq 0x2a213c <_Z18ProcessCommandLinePc+0x44c>
 *   @0x2a1fc8 ldr r1, [pc, #0x750]
 *   @0x2a1fcc mov r0, r6
 *   @0x2a1fd0 add r1, pc, r1
 *   @0x2a1fd4 bl 0xb6574 <strcmp@plt>
 *   @0x2a1fd8 cmp r0, #0
 *   @0x2a1fdc bne 0x2a20c0 <_Z18ProcessCommandLinePc+0x3d0>
 *   @0x2a1fe0 ldr r3, [pc, #0x73c]
 *   @0x2a1fe4 mov r2, #1
 *   @0x2a1fe8 ldr r3, [r5, r3]
 *   @0x2a1fec strb r2, [r3]
 *   @0x2a1ff0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a1ff4 ldr r6, [sp, #0x1c]
 *   @0x2a1ff8 mov r3, #1
 *   @0x2a1ffc strb r3, [r6]
 *   @0x2a2000 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2004 mov r0, r4
 *   @0x2a2008 mov r1, r7
 *   @0x2a200c bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a2010 ldr r3, [pc, #0x6cc]
 *   @0x2a2014 ldr r3, [r5, r3]
 *   @0x2a2018 str r3, [sp, #0x30]
 *   @0x2a201c mov r4, r0
 *   @0x2a2020 ldr r0, [r3]
 *   @0x2a2024 cmp r0, #0
 *   @0x2a2028 beq 0x2a203c <_Z18ProcessCommandLinePc+0x34c>
 *   @0x2a202c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2030 ldr r0, [sp, #0x30]
 *   @0x2a2034 mov r3, #0
 *   @0x2a2038 str r3, [r0]
 *   @0x2a203c mov r0, r6
 *   @0x2a2040 bl 0xb6538 <strlen@plt>
 *   @0x2a2044 ldr r1, [pc, #0x6dc]
 *   @0x2a2048 movw r2, #0x26d
 *   @0x2a204c add r1, pc, r1
 *   @0x2a2050 mov r3, #1
 *   @0x2a2054 add r0, r0, r3
 *   @0x2a2058 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a205c mov r1, r6
 *   @0x2a2060 ldr r6, [sp, #0x30]
 *   @0x2a2064 str r0, [r6]
 *   @0x2a2068 bl 0xb65a4 <strcpy@plt>
 *   @0x2a206c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2070 mov r0, r4
 *   @0x2a2074 mov r1, r7
 *   @0x2a2078 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a207c ldr r3, [pc, #0x6a8]
 *   @0x2a2080 ldr r3, [r5, r3]
 *   @0x2a2084 str r3, [sp, #0x30]
 *   @0x2a2088 mov r4, r0
 *   @0x2a208c ldr r0, [r3]
 *   @0x2a2090 cmp r0, #0
 *   @0x2a2094 beq 0x2a20a8 <_Z18ProcessCommandLinePc+0x3b8>
 *   @0x2a2098 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a209c ldr r2, [sp, #0x34]
 *   @0x2a20a0 ldr r3, [sp, #0x30]
 *   @0x2a20a4 str r2, [r3]
 *   @0x2a20a8 mov r0, r6
 *   @0x2a20ac bl 0xb6538 <strlen@plt>
 *   @0x2a20b0 ldr r1, [pc, #0x678]
 *   @0x2a20b4 movw r2, #0x276
 *   @0x2a20b8 add r1, pc, r1
 *   @0x2a20bc b 0x2a2050 <_Z18ProcessCommandLinePc+0x360>
 *   @0x2a20c0 ldr r1, [pc, #0x66c]
 *   @0x2a20c4 mov r0, r6
 *   @0x2a20c8 add r1, pc, r1
 *   @0x2a20cc bl 0xb6574 <strcmp@plt>
 *   @0x2a20d0 cmp r0, #0
 *   @0x2a20d4 bne 0x2a2194 <_Z18ProcessCommandLinePc+0x4a4>
 *   @0x2a20d8 ldr r3, [pc, #0x658]
 *   @0x2a20dc mov r2, #1
 *   @0x2a20e0 ldr r3, [r5, r3]
 *   @0x2a20e4 strb r2, [r3]
 *   @0x2a20e8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a20ec mov r0, r4
 *   @0x2a20f0 mov r1, r7
 *   @0x2a20f4 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a20f8 ldr r3, [pc, #0x63c]
 *   @0x2a20fc ldr r3, [r5, r3]
 *   @0x2a2100 str r3, [sp, #0x30]
 *   @0x2a2104 mov r4, r0
 *   @0x2a2108 ldr r0, [r3]
 *   @0x2a210c cmp r0, #0
 *   @0x2a2110 beq 0x2a2124 <_Z18ProcessCommandLinePc+0x434>
 *   @0x2a2114 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a2118 ldr r2, [sp, #0x34]
 *   @0x2a211c ldr r3, [sp, #0x30]
 *   @0x2a2120 str r2, [r3]
 *   @0x2a2124 mov r0, r6
 *   @0x2a2128 bl 0xb6538 <strlen@plt>
 *   @0x2a212c ldr r1, [pc, #0x60c]
 *   @0x2a2130 movw r2, #0x27f
 *   @0x2a2134 add r1, pc, r1
 *   @0x2a2138 b 0x2a2050 <_Z18ProcessCommandLinePc+0x360>
 *   @0x2a213c mov r0, r4
 *   @0x2a2140 ldr r4, [sp, #0x20]
 *   @0x2a2144 mov r1, r7
 *   @0x2a2148 mov r3, #1
 *   @0x2a214c strb r3, [r4]
 *   @0x2a2150 str r3, [sp, #0x4]
 *   @0x2a2154 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a2158 mov r4, r0
 *   @0x2a215c mov r0, r6
 *   @0x2a2160 bl 0xb6538 <strlen@plt>
 *   @0x2a2164 ldr r1, [pc, #0x5d8]
 *   @0x2a2168 ldr r3, [sp, #0x4]
 *   @0x2a216c movw r2, #0x285
 *   @0x2a2170 add r1, pc, r1
 *   @0x2a2174 add r0, r0, #1
 *   @0x2a2178 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a217c ldr r3, [pc, #0x5c4]
 *   @0x2a2180 mov r1, r6
 *   @0x2a2184 ldr r3, [r5, r3]
 *   @0x2a2188 str r0, [r3]
 *   @0x2a218c bl 0xb65a4 <strcpy@plt>
 *   @0x2a2190 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2194 ldr r1, [pc, #0x5b0]
 *   @0x2a2198 mov r0, r6
 *   @0x2a219c add r1, pc, r1
 *   @0x2a21a0 bl 0xb6574 <strcmp@plt>
 *   @0x2a21a4 cmp r0, #0
 *   @0x2a21a8 bne 0x2a21cc <_Z18ProcessCommandLinePc+0x4dc>
 *   @0x2a21ac ldr r1, [pc, #0x59c]
 *   @0x2a21b0 mov r3, #1
 *   @0x2a21b4 ldr r2, [pc, #0x598]
 *   @0x2a21b8 ldr r1, [r5, r1]
 *   @0x2a21bc strb r3, [r1]
 *   @0x2a21c0 ldr r2, [r5, r2]
 *   @0x2a21c4 strb r3, [r2]
 *   @0x2a21c8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a21cc ldr r1, [pc, #0x584]
 *   @0x2a21d0 mov r0, r6
 *   @0x2a21d4 add r1, pc, r1
 *   @0x2a21d8 bl 0xb6574 <strcmp@plt>
 *   @0x2a21dc cmp r0, #0
 *   @0x2a21e0 bne 0x2a21f8 <_Z18ProcessCommandLinePc+0x508>
 *   @0x2a21e4 ldr r6, [sp, #0xc]
 *   @0x2a21e8 ldr r3, [r6]
 *   @0x2a21ec orr r3, r3, #16
 *   @0x2a21f0 str r3, [r6]
 *   @0x2a21f4 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a21f8 ldr r1, [pc, #0x55c]
 *   @0x2a21fc mov r0, r6
 *   @0x2a2200 add r1, pc, r1
 *   @0x2a2204 bl 0xb6574 <strcmp@plt>
 *   @0x2a2208 cmp r0, #0
 *   @0x2a220c bne 0x2a2224 <_Z18ProcessCommandLinePc+0x534>
 *   @0x2a2210 ldr r3, [pc, #0x548]
 *   @0x2a2214 mov r2, #1
 *   @0x2a2218 ldr r3, [r5, r3]
 *   @0x2a221c strb r2, [r3]
 *   @0x2a2220 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2224 mov r0, r6
 *   @0x2a2228 mov r1, r9
 *   @0x2a222c bl 0xb6574 <strcmp@plt>
 *   @0x2a2230 cmp r0, #0
 *   @0x2a2234 bne 0x2a224c <_Z18ProcessCommandLinePc+0x55c>
 *   @0x2a2238 ldr r3, [pc, #0x524]
 *   @0x2a223c mov r2, #1
 *   @0x2a2240 ldr r3, [r5, r3]
 *   @0x2a2244 strb r2, [r3]
 *   @0x2a2248 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a224c mov r0, r6
 *   @0x2a2250 mov r1, r8
 *   @0x2a2254 bl 0xb6574 <strcmp@plt>
 *   @0x2a2258 cmp r0, #0
 *   @0x2a225c beq 0x2a22e0 <_Z18ProcessCommandLinePc+0x5f0>
 *   @0x2a2260 mov r0, r6
 *   @0x2a2264 ldr r1, [sp, #0x28]
 *   @0x2a2268 bl 0xb6574 <strcmp@plt>
 *   @0x2a226c cmp r0, #0
 *   @0x2a2270 beq 0x2a25c4 <_Z18ProcessCommandLinePc+0x8d4>
 *   @0x2a2274 mov r0, r6
 *   @0x2a2278 ldr r1, [sp, #0x2c]
 *   @0x2a227c bl 0xb6574 <strcmp@plt>
 *   @0x2a2280 cmp r0, #0
 *   @0x2a2284 beq 0x2a2548 <_Z18ProcessCommandLinePc+0x858>
 *   @0x2a2288 mov r0, r6
 *   @0x2a228c mov r1, r10
 *   @0x2a2290 bl 0xb6574 <strcmp@plt>
 *   @0x2a2294 cmp r0, #0
 *   @0x2a2298 bne 0x2a231c <_Z18ProcessCommandLinePc+0x62c>
 *   @0x2a229c ldr r2, [pc, #0x4c4]
 *   @0x2a22a0 mov r3, #1
 *   @0x2a22a4 ldr r1, [pc, #0x4c0]
 *   @0x2a22a8 ldr r0, [r5, r2]
 *   @0x2a22ac ldr r2, [pc, #0x4bc]
 *   @0x2a22b0 strb r3, [r0]
 *   @0x2a22b4 ldr r0, [r5, r1]
 *   @0x2a22b8 ldr r1, [pc, #0x4b4]
 *   @0x2a22bc strb r3, [r0]
 *   @0x2a22c0 ldr r0, [r5, r2]
 *   @0x2a22c4 ldr r2, [pc, #0x4ac]
 *   @0x2a22c8 strb r3, [r0]
 *   @0x2a22cc ldr r1, [r5, r1]
 *   @0x2a22d0 strb r3, [r1]
 *   @0x2a22d4 ldr r2, [r5, r2]
 *   @0x2a22d8 strb r3, [r2]
 *   @0x2a22dc b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a22e0 mov r0, r4
 *   @0x2a22e4 ldr r4, [sp, #0x24]
 *   @0x2a22e8 mov r1, r7
 *   @0x2a22ec mov r3, #1
 *   @0x2a22f0 strb r3, [r4]
 *   @0x2a22f4 str r3, [sp, #0x4]
 *   @0x2a22f8 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a22fc mov r4, r0
 *   @0x2a2300 mov r0, r6
 *   @0x2a2304 bl 0xb6538 <strlen@plt>
 *   @0x2a2308 ldr r1, [pc, #0x46c]
 *   @0x2a230c ldr r3, [sp, #0x4]
 *   @0x2a2310 movw r2, #0x29f
 *   @0x2a2314 add r1, pc, r1
 *   @0x2a2318 b 0x2a2174 <_Z18ProcessCommandLinePc+0x484>
 *   @0x2a231c mov r0, r6
 *   @0x2a2320 mov r1, r11
 *   @0x2a2324 bl 0xb6574 <strcmp@plt>
 *   @0x2a2328 cmp r0, #0
 *   @0x2a232c beq 0x2a2440 <_Z18ProcessCommandLinePc+0x750>
 *   @0x2a2330 ldr r1, [pc, #0x448]
 *   @0x2a2334 mov r0, r6
 *   @0x2a2338 mov r2, #9
 *   @0x2a233c add r1, pc, r1
 *   @0x2a2340 bl 0xb65e0 <strncmp@plt>
 *   @0x2a2344 subs r3, r0, #0
 *   @0x2a2348 bne 0x2a23f0 <_Z18ProcessCommandLinePc+0x700>
 *   @0x2a234c ldr r2, [pc, #0x430]
 *   @0x2a2350 ldr r2, [r5, r2]
 *   @0x2a2354 ldr r0, [r2]
 *   @0x2a2358 str r2, [sp, #0x30]
 *   @0x2a235c cmp r0, #0
 *   @0x2a2360 beq 0x2a2378 <_Z18ProcessCommandLinePc+0x688>
 *   @0x2a2364 str r3, [sp, #0x4]
 *   @0x2a2368 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x2a236c ldr r3, [sp, #0x4]
 *   @0x2a2370 ldr r0, [sp, #0x30]
 *   @0x2a2374 str r3, [r0]
 *   @0x2a2378 ldr r1, [pc, #0x408]
 *   @0x2a237c mov r2, #11
 *   @0x2a2380 mov r0, r6
 *   @0x2a2384 add r1, pc, r1
 *   @0x2a2388 bl 0xb65e0 <strncmp@plt>
 *   @0x2a238c cmp r0, #0
 *   @0x2a2390 moveq r0, #11
 *   @0x2a2394 movne r0, #9
 *   @0x2a2398 str r0, [sp, #0x34]
 *   @0x2a239c mov r0, r6
 *   @0x2a23a0 bl 0xb6538 <strlen@plt>
 *   @0x2a23a4 sub r0, r0, #1
 *   @0x2a23a8 ldrb r3, [r6, r0]
 *   @0x2a23ac cmp r3, #47
 *   @0x2a23b0 moveq r3, #0
 *   @0x2a23b4 strbeq r3, [r6, r0]
 *   @0x2a23b8 mov r0, r6
 *   @0x2a23bc bl 0xb6538 <strlen@plt>
 *   @0x2a23c0 ldr r1, [pc, #0x3c4]
 *   @0x2a23c4 mov r3, #1
 *   @0x2a23c8 mov r2, #720
 *   @0x2a23cc add r1, pc, r1
 *   @0x2a23d0 add r0, r0, r3
 *   @0x2a23d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a23d8 ldr r2, [sp, #0x34]
 *   @0x2a23dc add r1, r6, r2
 *   @0x2a23e0 ldr r6, [sp, #0x30]
 *   @0x2a23e4 str r0, [r6]
 *   @0x2a23e8 bl 0xb65a4 <strcpy@plt>
 *   @0x2a23ec b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a23f0 ldr r1, [pc, #0x398]
 *   @0x2a23f4 mov r0, r6
 *   @0x2a23f8 add r1, pc, r1
 *   @0x2a23fc bl 0xb6574 <strcmp@plt>
 *   @0x2a2400 cmp r0, #0
 *   @0x2a2404 beq 0x2a24e4 <_Z18ProcessCommandLinePc+0x7f4>
 *   @0x2a2408 ldr r1, [pc, #0x384]
 *   @0x2a240c mov r0, r6
 *   @0x2a2410 add r1, pc, r1
 *   @0x2a2414 bl 0xb6574 <strcmp@plt>
 *   @0x2a2418 cmp r0, #0
 *   @0x2a241c bne 0x2a24ac <_Z18ProcessCommandLinePc+0x7bc>
 *   @0x2a2420 ldr r2, [pc, #0x370]
 *   @0x2a2424 mov r1, #1
 *   @0x2a2428 ldr r3, [pc, #0x36c]
 *   @0x2a242c ldr r2, [r5, r2]
 *   @0x2a2430 strb r1, [r2]
 *   @0x2a2434 ldr r3, [r5, r3]
 *   @0x2a2438 strb r0, [r3]
 *   @0x2a243c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2440 mov r1, r7
 *   @0x2a2444 mov r0, r4
 *   @0x2a2448 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a244c mov r4, r0
 *   @0x2a2450 mov r0, r6
 *   @0x2a2454 bl 0xb6538 <strlen@plt>
 *   @0x2a2458 ldr r1, [pc, #0x340]
 *   @0x2a245c movw r2, #0x2bb
 *   @0x2a2460 mov r3, #1
 *   @0x2a2464 add r1, pc, r1
 *   @0x2a2468 add r0, r0, r3
 *   @0x2a246c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a2470 ldr r3, [pc, #0x32c]
 *   @0x2a2474 mov r1, r6
 *   @0x2a2478 ldr r3, [r5, r3]
 *   @0x2a247c str r0, [r3]
 *   @0x2a2480 bl 0xb65a4 <strcpy@plt>
 *   @0x2a2484 mov r0, r4
 *   @0x2a2488 mov r1, r7
 *   @0x2a248c bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a2490 mov r4, r0
 *   @0x2a2494 mov r0, r6
 *   @0x2a2498 bl 0xb66b8 <atoi@plt>
 *   @0x2a249c ldr r3, [pc, #0x304]
 *   @0x2a24a0 ldr r3, [r5, r3]
 *   @0x2a24a4 str r0, [r3]
 *   @0x2a24a8 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a24ac ldr r1, [pc, #0x2f8]
 *   @0x2a24b0 mov r0, r6
 *   @0x2a24b4 add r1, pc, r1
 *   @0x2a24b8 bl 0xb6574 <strcmp@plt>
 *   @0x2a24bc cmp r0, #0
 *   @0x2a24c0 bne 0x2a251c <_Z18ProcessCommandLinePc+0x82c>
 *   @0x2a24c4 ldr r1, [pc, #0x2cc]
 *   @0x2a24c8 mov r3, #1
 *   @0x2a24cc ldr r2, [pc, #0x2dc]
 *   @0x2a24d0 ldr r1, [r5, r1]
 *   @0x2a24d4 strb r3, [r1]
 *   @0x2a24d8 ldr r2, [r5, r2]
 *   @0x2a24dc strb r3, [r2]
 *   @0x2a24e0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a24e4 mov r1, r7
 *   @0x2a24e8 mov r0, r4
 *   @0x2a24ec bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a24f0 mov r4, r0
 *   @0x2a24f4 mov r0, r6
 *   @0x2a24f8 bl 0xb66b8 <atoi@plt>
 *   @0x2a24fc ldr r1, [pc, #0x2b0]
 *   @0x2a2500 ldr r2, [pc, #0x2b0]
 *   @0x2a2504 mov r3, #1
 *   @0x2a2508 ldr r1, [r5, r1]
 *   @0x2a250c str r0, [r1]
 *   @0x2a2510 ldr r2, [r5, r2]
 *   @0x2a2514 strb r3, [r2]
 *   @0x2a2518 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a251c ldr r1, [pc, #0x298]
 *   @0x2a2520 mov r0, r6
 *   @0x2a2524 add r1, pc, r1
 *   @0x2a2528 bl 0xb6574 <strcmp@plt>
 *   @0x2a252c cmp r0, #0
 *   @0x2a2530 bne 0x2a2620 <_Z18ProcessCommandLinePc+0x930>
 *   @0x2a2534 ldr r3, [pc, #0x284]
 *   @0x2a2538 mov r2, #1
 *   @0x2a253c ldr r3, [r5, r3]
 *   @0x2a2540 strb r2, [r3]
 *   @0x2a2544 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2548 ldr lr, [pc, #0x274]
 *   @0x2a254c mov r1, r7
 *   @0x2a2550 ldr r12, [pc, #0x270]
 *   @0x2a2554 mov r0, r4
 *   @0x2a2558 ldr r2, [pc, #0x26c]
 *   @0x2a255c mov r3, #1
 *   @0x2a2560 ldr lr, [r5, lr]
 *   @0x2a2564 ldr r12, [r5, r12]
 *   @0x2a2568 ldr lr, [lr]
 *   @0x2a256c ldr r12, [r12]
 *   @0x2a2570 ldr lr, [lr]
 *   @0x2a2574 str lr, [r12]
 *   @0x2a2578 ldr r2, [r5, r2]
 *   @0x2a257c strb r3, [r2]
 *   @0x2a2580 str r3, [sp, #0x4]
 *   @0x2a2584 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a2588 mov r4, r0
 *   @0x2a258c mov r0, r6
 *   @0x2a2590 bl 0xb6538 <strlen@plt>
 *   @0x2a2594 ldr r1, [pc, #0x234]
 *   @0x2a2598 ldr r3, [sp, #0x4]
 *   @0x2a259c mov r2, #684
 *   @0x2a25a0 add r1, pc, r1
 *   @0x2a25a4 add r0, r0, #1
 *   @0x2a25a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a25ac ldr r3, [pc, #0x220]
 *   @0x2a25b0 mov r1, r6
 *   @0x2a25b4 ldr r3, [r5, r3]
 *   @0x2a25b8 str r0, [r3]
 *   @0x2a25bc bl 0xb65a4 <strcpy@plt>
 *   @0x2a25c0 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a25c4 ldr r2, [pc, #0x20c]
 *   @0x2a25c8 mov r1, r7
 *   @0x2a25cc mov r0, r4
 *   @0x2a25d0 mov r3, #1
 *   @0x2a25d4 ldr r2, [r5, r2]
 *   @0x2a25d8 strb r3, [r2]
 *   @0x2a25dc str r3, [sp, #0x4]
 *   @0x2a25e0 bl 0x2a1c0c <_Z10GetNextCmdiPc>
 *   @0x2a25e4 mov r4, r0
 *   @0x2a25e8 mov r0, r6
 *   @0x2a25ec bl 0xb6538 <strlen@plt>
 *   @0x2a25f0 ldr r1, [pc, #0x1e4]
 *   @0x2a25f4 ldr r3, [sp, #0x4]
 *   @0x2a25f8 movw r2, #0x2a5
 *   @0x2a25fc add r1, pc, r1
 *   @0x2a2600 add r0, r0, #1
 *   @0x2a2604 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a2608 ldr r3, [pc, #0x1d0]
 *   @0x2a260c mov r1, r6
 *   @0x2a2610 ldr r3, [r5, r3]
 *   @0x2a2614 str r0, [r3]
 *   @0x2a2618 bl 0xb65a4 <strcpy@plt>
 *   @0x2a261c b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2620 ldr r1, [pc, #0x1bc]
 *   @0x2a2624 mov r0, r6
 *   @0x2a2628 add r1, pc, r1
 *   @0x2a262c bl 0xb6574 <strcmp@plt>
 *   @0x2a2630 cmp r0, #0
 *   @0x2a2634 bne 0x2a264c <_Z18ProcessCommandLinePc+0x95c>
 *   @0x2a2638 ldr r3, [pc, #0x1a8]
 *   @0x2a263c mov r2, #1
 *   @0x2a2640 ldr r3, [r5, r3]
 *   @0x2a2644 strb r2, [r3]
 *   @0x2a2648 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a264c ldr r1, [pc, #0x198]
 *   @0x2a2650 mov r0, r6
 *   @0x2a2654 add r1, pc, r1
 *   @0x2a2658 bl 0xb6574 <strcmp@plt>
 *   @0x2a265c cmp r0, #0
 *   @0x2a2660 bne 0x2a2678 <_Z18ProcessCommandLinePc+0x988>
 *   @0x2a2664 ldr r3, [pc, #0x184]
 *   @0x2a2668 mov r2, #1
 *   @0x2a266c ldr r3, [r5, r3]
 *   @0x2a2670 strb r2, [r3]
 *   @0x2a2674 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a2678 ldr r1, [pc, #0x174]
 *   @0x2a267c mov r0, r6
 *   @0x2a2680 add r1, pc, r1
 *   @0x2a2684 bl 0xb6574 <strcmp@plt>
 *   @0x2a2688 cmp r0, #0
 *   @0x2a268c ldreq r3, [pc, #0x164]
 *   @0x2a2690 ldreq r3, [r5, r3]
 *   @0x2a2694 strbeq r0, [r3]
 *   @0x2a2698 b 0x2a1ddc <_Z18ProcessCommandLinePc+0xec>
 *   @0x2a269c andseq pc, r4, r8, asr #30
 *   @0x2a26a0 .word 0xffffef34
 *   @0x2a26a4 .word 0xfffff75c
 *   @0x2a26a8 .word 0xffffe9c8
 *   @0x2a26ac .word 0xffffe9cc
 *   @0x2a26b0 .word 0xffffe9f8
 *   @0x2a26b4 .word 0xffffd3fc
 *   @0x2a26b8 .word 0xffffeb04
 *   @0x2a26bc .word 0xffffc7dc
 *   @0x2a26c0 .word 0xffffd650
 *   @0x2a26c4 andeq r8, r11, r0, lsr r5
 *   @0x2a26c8 andeq r8, r11, r4, lsr r5
 *   @0x2a26cc andeq r8, r11, r8, lsr r5
 *   @0x2a26d0 andeq r8, r11, r8, asr #10
 *   @0x2a26d4 andeq r8, r11, r12, asr #10
 *   @0x2a26d8 andeq r8, r11, r4, lsr #10
 *   @0x2a26dc .word 0xfffffddc
 *   @0x2a26e0 andeq r8, r11, r4, lsl #8
 *   @0x2a26e4 .word 0xffffeed0
 *   @0x2a26e8 andeq r8, r11, r8, lsr #7
 *   @0x2a26ec .word 0xffffc100
 *   @0x2a26f0 andeq r8, r11, r4, lsl #7
 *   @0x2a26f4 .word 0xffffc7cc
 *   @0x2a26f8 andeq r8, r11, r4, ror #6
 *   @0x2a26fc andeq r8, r11, r8, asr #6
 *   @0x2a2700 .word 0xffffc158
 *   @0x2a2704 andeq r8, r11, r0, lsr r3
 *   @0x2a2708 andeq r8, r11, r4, lsr #6
 *   @0x2a270c strdeq r8, r9, [r11], -r12
 *   @0x2a2710 strdeq r8, r9, [r11], -r0
 *   @0x2a2714 andeq r8, r11, r8, lsl #6
 *   @0x2a2718 strdeq r8, r9, [r11], -r4
 *   @0x2a271c andeq r8, r11, r0, ror #5
 *   @0x2a2720 ldrdeq r8, r9, [r11], -r0
 *   @0x2a2724 .word 0xffffc180
 *   @0x2a2728 andeq r8, r11, r4, lsl r2
 *   @0x2a272c .word 0xfffffde0
 *   @0x2a2730 andeq r8, r11, r8, lsr #3
 *   @0x2a2734 andeq r8, r11, r0, ror #3
 *   @0x2a2738 .word 0xfffffde4
 *   @0x2a273c .word 0xfffffde8
 *   @0x2a2740 andeq r8, r11, r12, lsr #2
 *   @0x2a2744 strdeq r8, r9, [r11], -r0
 *   @0x2a2748 .word 0xffffe9d0
 *   @0x2a274c andeq r8, r11, r8, lsl r1
 *   @0x2a2750 .word 0xffffe830
 *   @0x2a2754 .word 0xfffffdec
 *   @0x2a2758 andeq r8, r11, r8, ror #1
 *   @0x2a275c andeq r8, r11, r8, asr #1
 *   @0x2a2760 .word 0xfffffd48
 *   @0x2a2764 .word 0xfffffdf0
 *   @0x2a2768 .word 0xfffff0cc
 *   @0x2a276c .word 0xffffef38
 *   @0x2a2770 .word 0xfffffdf4
 *   @0x2a2774 .word 0xffffc148
 *   @0x2a2778 .word 0xfffffdcc
 *   @0x2a277c andeq r7, r11, r12, asr #30
 *   @0x2a2780 andeq r7, r11, r8, ror #31
 *   @0x2a2784 .word 0xffffdf10
 *   @0x2a2788 andeq r7, r11, r12, lsr #31
 *   @0x2a278c muleq r11, r4, lr
 *   @0x2a2790 andeq r7, r11, r4, asr #30
 *   @0x2a2794 andeq r7, r11, r12, lsr pc
 *   @0x2a2798 .word 0xfffffdf8
 *   @0x2a279c .word 0xfffffdfc
 *   @0x2a27a0 strdeq r7, r8, [r11], -r12
 *   @0x2a27a4 .word 0xffffef64
 *   @0x2a27a8 .word 0xffffef68
 *   @0x2a27ac andeq r7, r11, r4, lsr #29
 *   @0x2a27b0 .word 0xfffffe00
 *   @0x2a27b4 .word 0xffffc964
 *   @0x2a27b8 .word 0xfffffe04
 *   @0x2a27bc andeq r7, r11, r12, lsr lr
 *   @0x2a27c0 .word 0xfffffe08
 *   @0x2a27c4 .word 0xffffbac4
 *   @0x2a27c8 .word 0xffffdecc
 *   @0x2a27cc .word 0xfffffe0c
 *   @0x2a27d0 andeq r7, r11, r0, asr #25
 *   @0x2a27d4 .word 0xfffffe10
 *   @0x2a27d8 .word 0xfffffe14
 *   @0x2a27dc andeq r7, r11, r4, ror #24
 *   @0x2a27e0 .word 0xfffffe18
 *   @0x2a27e4 andeq r7, r11, r12, asr #26
 *   @0x2a27e8 .word 0xfffffe1c
 *   @0x2a27ec andeq r7, r11, r0, lsr sp
 *   @0x2a27f0 .word 0xfffffe20
 *   @0x2a27f4 andeq r7, r11, r4, lsl sp
 *   @0x2a27f8 .word 0xfffffe24
 *
 * ══ §3/12 anon_2ba268  0x2ba268  size 2756  689 条（0x2ba268..0x2bad2c）
 * @func 0x2ba268 0x2bad2c  size 2756  689 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×4 / jzero_far×3 / anon_2ba268+0x8f0×2 / anon_2ba268+0x1b4 / anon_2ba268+0x10c / anon_2ba268+0x250 / anon_2ba268+0x25c / anon_2ba268+0x2e4
 * 字段偏移 top8: 0x4×35 / 0x18×23 / 0x14×22 / 0x8×16 / 0x10×15 / 0x64×14 / 0x1c×12 / 0xc×12
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2ba268 ldr r3, [r0, #0x4c]
 *   @0x2ba26c ldr r1, [r0, #0x1a8]
 *   @0x2ba270 cmp r3, #1
 *   @0x2ba274 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ba278 sub sp, sp, #36
 *   @0x2ba27c strbeq r3, [r1, #0x1c]
 *   @0x2ba280 movne r3, #0
 *   @0x2ba284 str r1, [sp, #0x4]
 *   @0x2ba288 mov r10, r0
 *   @0x2ba28c ldrne r1, [sp, #0x4]
 *   @0x2ba290 movweq r3, #0x1fe
 *   @0x2ba294 movweq r2, #0x2fe
 *   @0x2ba298 streq r3, [sp, #0xc]
 *   @0x2ba29c movne r2, #256
 *   @0x2ba2a0 strne r3, [sp, #0xc]
 *   @0x2ba2a4 strbne r3, [r1, #0x1c]
 *   @0x2ba2a8 mov r1, #1
 *   @0x2ba2ac ldr r12, [r0, #0x4]
 *   @0x2ba2b0 ldr r3, [r10, #0x64]
 *   @0x2ba2b4 ldr r12, [r12, #0x8]
 *   @0x2ba2b8 blx r12
 *   @0x2ba2bc ldr r2, [sp, #0x4]
 *   @0x2ba2c0 ldr r3, [r10, #0x64]
 *   @0x2ba2c4 cmp r3, #0
 *   @0x2ba2c8 ldr r3, [r2, #0x14]
 *   @0x2ba2cc str r3, [sp, #0x10]
 *   @0x2ba2d0 str r0, [r2, #0x18]
 *   @0x2ba2d4 ble 0x2ba41c <jinit_memory_mgr+0x368>
 *   @0x2ba2d8 ldr r3, [sp, #0x4]
 *   @0x2ba2dc mov r5, r0
 *   @0x2ba2e0 mov r2, #0
 *   @0x2ba2e4 str r10, [sp, #0x1c]
 *   @0x2ba2e8 str r2, [sp, #0x8]
 *   @0x2ba2ec str r2, [sp, #0x18]
 *   @0x2ba2f0 str r3, [sp, #0x14]
 *   @0x2ba2f4 ldr r2, [sp, #0x14]
 *   @0x2ba2f8 ldr r0, [sp, #0x10]
 *   @0x2ba2fc ldr r4, [r2, #0x20]
 *   @0x2ba300 mov r1, r4
 *   @0x2ba304 bl 0x318d10 <__divsi3>
 *   @0x2ba308 ldr r3, [sp, #0xc]
 *   @0x2ba30c cmp r3, #0
 *   @0x2ba310 str r0, [sp, #0x10]
 *   @0x2ba314 beq 0x2ba330 <jinit_memory_mgr+0x27c>
 *   @0x2ba318 ldr r2, [sp, #0x8]
 *   @0x2ba31c ldr r3, [r5, r2]
 *   @0x2ba320 add r3, r3, #255
 *   @0x2ba324 str r3, [r5, r2]
 *   @0x2ba328 ldr r3, [sp, #0x4]
 *   @0x2ba32c ldr r5, [r3, #0x18]
 *   @0x2ba330 ldr r2, [sp, #0x8]
 *   @0x2ba334 sub r8, r4, #1
 *   @0x2ba338 ldr r3, [sp, #0x10]
 *   @0x2ba33c add r0, r4, #254
 *   @0x2ba340 mov r4, #0
 *   @0x2ba344 ldr r6, [r5, r2]
 *   @0x2ba348 lsl r5, r8, #1
 *   @0x2ba34c mov r11, r4
 *   @0x2ba350 uxtb r7, r3
 *   @0x2ba354 mov r1, r5
 *   @0x2ba358 bl 0x318d10 <__divsi3>
 *   @0x2ba35c cmp r0, r4
 *   @0x2ba360 bge 0x2ba398 <jinit_memory_mgr+0x2e4>
 *   @0x2ba364 add r10, r11, #1
 *   @0x2ba368 rsb r9, r10, r10, lsl #8
 *   @0x2ba36c add r9, r8, r9, lsl #1
 *   @0x2ba370 add r9, r9, #255
 *   @0x2ba374 mov r0, r9
 *   @0x2ba378 mov r1, r5
 *   @0x2ba37c bl 0x318d10 <__divsi3>
 *   @0x2ba380 add r9, r9, #508
 *   @0x2ba384 mov r11, r10
 *   @0x2ba388 add r9, r9, #2
 *   @0x2ba38c add r10, r10, #1
 *   @0x2ba390 cmp r0, r4
 *   @0x2ba394 blt 0x2ba374 <jinit_memory_mgr+0x2c0>
 *   @0x2ba398 mul r3, r11, r7
 *   @0x2ba39c strb r3, [r6, r4]
 *   @0x2ba3a0 add r4, r4, #1
 *   @0x2ba3a4 cmp r4, #256
 *   @0x2ba3a8 bne 0x2ba35c <jinit_memory_mgr+0x2a8>
 *   @0x2ba3ac ldr r1, [sp, #0xc]
 *   @0x2ba3b0 cmp r1, #0
 *   @0x2ba3b4 beq 0x2ba3dc <jinit_memory_mgr+0x328>
 *   @0x2ba3b8 add r2, r6, #255
 *   @0x2ba3bc sub r0, r6, #255
 *   @0x2ba3c0 mov r3, r6
 *   @0x2ba3c4 ldrb r1, [r6]
 *   @0x2ba3c8 strb r1, [r3, #-0x1]!
 *   @0x2ba3cc cmp r3, r0
 *   @0x2ba3d0 ldrb r1, [r6, #0xff]
 *   @0x2ba3d4 strb r1, [r2, #0x1]!
 *   @0x2ba3d8 bne 0x2ba3c4 <jinit_memory_mgr+0x310>
 *   @0x2ba3dc ldr r2, [sp, #0x1c]
 *   @0x2ba3e0 ldr r3, [r2, #0x64]
 *   @0x2ba3e4 ldr r2, [sp, #0x18]
 *   @0x2ba3e8 add r2, r2, #1
 *   @0x2ba3ec str r2, [sp, #0x18]
 *   @0x2ba3f0 ldr r2, [sp, #0x8]
 *   @0x2ba3f4 add r2, r2, #4
 *   @0x2ba3f8 str r2, [sp, #0x8]
 *   @0x2ba3fc ldr r2, [sp, #0x14]
 *   @0x2ba400 add r2, r2, #4
 *   @0x2ba404 str r2, [sp, #0x14]
 *   @0x2ba408 ldr r2, [sp, #0x18]
 *   @0x2ba40c cmp r3, r2
 *   @0x2ba410 ldrgt r3, [sp, #0x4]
 *   @0x2ba414 ldrgt r5, [r3, #0x18]
 *   @0x2ba418 bgt 0x2ba2f4 <jinit_memory_mgr+0x240>
 *   @0x2ba41c add sp, sp, #36
 *   @0x2ba420 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ba424 ldr r12, [r0, #0x1a8]
 *   @0x2ba428 cmp r3, #0
 *   @0x2ba42c push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba430 sub sp, sp, #8
 *   @0x2ba434 ldr r11, [r0, #0x5c]
 *   @0x2ba438 str r1, [sp, #0x4]
 *   @0x2ba43c ldr r7, [r0, #0x64]
 *   @0x2ba440 ldr r9, [r12, #0x18]
 *   @0x2ba444 ble 0x2ba4b8 <jinit_memory_mgr+0x404>
 *   @0x2ba448 mov r10, #0
 *   @0x2ba44c lsl r3, r3, #2
 *   @0x2ba450 str r3, [sp]
 *   @0x2ba454 ldr r1, [sp, #0x4]
 *   @0x2ba458 cmp r11, #0
 *   @0x2ba45c ldr r6, [r2, r10]
 *   @0x2ba460 ldr r3, [r1, r10]
 *   @0x2ba464 beq 0x2ba4a8 <jinit_memory_mgr+0x3f4>
 *   @0x2ba468 add r8, r6, r11
 *   @0x2ba46c cmp r7, #0
 *   @0x2ba470 ble 0x2ba4c4 <jinit_memory_mgr+0x410>
 *   @0x2ba474 sub r0, r9, #4
 *   @0x2ba478 add r4, r3, r7
 *   @0x2ba47c mov r1, #0
 *   @0x2ba480 ldrb r12, [r3], #1
 *   @0x2ba484 ldr r5, [r0, #0x4]!
 *   @0x2ba488 cmp r3, r4
 *   @0x2ba48c ldrb r12, [r5, r12]
 *   @0x2ba490 add r1, r1, r12
 *   @0x2ba494 bne 0x2ba480 <jinit_memory_mgr+0x3cc>
 *   @0x2ba498 uxtb r1, r1
 *   @0x2ba49c strb r1, [r6], #1
 *   @0x2ba4a0 cmp r6, r8
 *   @0x2ba4a4 bne 0x2ba46c <jinit_memory_mgr+0x3b8>
 *   @0x2ba4a8 ldr r3, [sp]
 *   @0x2ba4ac add r10, r10, #4
 *   @0x2ba4b0 cmp r10, r3
 *   @0x2ba4b4 bne 0x2ba454 <jinit_memory_mgr+0x3a0>
 *   @0x2ba4b8 add sp, sp, #8
 *   @0x2ba4bc pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba4c0 bx lr
 *   @0x2ba4c4 mov r1, #0
 *   @0x2ba4c8 b 0x2ba49c <jinit_memory_mgr+0x3e8>
 *   @0x2ba4cc ldr r12, [r0, #0x1a8]
 *   @0x2ba4d0 cmp r3, #0
 *   @0x2ba4d4 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba4d8 sub sp, sp, #8
 *   @0x2ba4dc ldr r11, [r0, #0x5c]
 *   @0x2ba4e0 ldr r0, [r12, #0x18]
 *   @0x2ba4e4 ldm r0, {r7, r8, r9}
 *   @0x2ba4e8 ble 0x2ba54c <jinit_memory_mgr+0x498>
 *   @0x2ba4ec mov r10, #0
 *   @0x2ba4f0 lsl r3, r3, #2
 *   @0x2ba4f4 str r3, [sp, #0x4]
 *   @0x2ba4f8 cmp r11, #0
 *   @0x2ba4fc ldr r0, [r2, r10]
 *   @0x2ba500 ldr r3, [r1, r10]
 *   @0x2ba504 addne r6, r0, r11
 *   @0x2ba508 beq 0x2ba53c <jinit_memory_mgr+0x488>
 *   @0x2ba50c ldrb r12, [r3]
 *   @0x2ba510 add r3, r3, #3
 *   @0x2ba514 ldrb r5, [r3, #-0x2]
 *   @0x2ba518 ldrb r4, [r3, #-0x1]
 *   @0x2ba51c ldrb r12, [r7, r12]
 *   @0x2ba520 ldrb r5, [r8, r5]
 *   @0x2ba524 ldrb r4, [r9, r4]
 *   @0x2ba528 add r12, r5, r12
 *   @0x2ba52c add r12, r4, r12
 *   @0x2ba530 strb r12, [r0], #1
 *   @0x2ba534 cmp r0, r6
 *   @0x2ba538 bne 0x2ba50c <jinit_memory_mgr+0x458>
 *   @0x2ba53c ldr r3, [sp, #0x4]
 *   @0x2ba540 add r10, r10, #4
 *   @0x2ba544 cmp r10, r3
 *   @0x2ba548 bne 0x2ba4f8 <jinit_memory_mgr+0x444>
 *   @0x2ba54c add sp, sp, #8
 *   @0x2ba550 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba554 bx lr
 *   @0x2ba558 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba55c sub sp, sp, #40
 *   @0x2ba560 ldr r4, [r0, #0x1a8]
 *   @0x2ba564 cmp r3, #0
 *   @0x2ba568 ldr r0, [r0, #0x5c]
 *   @0x2ba56c str r2, [sp, #0x24]
 *   @0x2ba570 ldr r2, [r4, #0x18]
 *   @0x2ba574 str r0, [sp, #0x18]
 *   @0x2ba578 str r4, [sp, #0x10]
 *   @0x2ba57c ldr r12, [r2]
 *   @0x2ba580 ldr r0, [r2, #0x4]
 *   @0x2ba584 ldr r2, [r2, #0x8]
 *   @0x2ba588 str r1, [sp, #0x20]
 *   @0x2ba58c str r12, [sp]
 *   @0x2ba590 str r0, [sp, #0x4]
 *   @0x2ba594 str r2, [sp, #0x8]
 *   @0x2ba598 ble 0x2ba690 <jinit_memory_mgr+0x5dc>
 *   @0x2ba59c ldr r1, [r4, #0x30]
 *   @0x2ba5a0 lsl r3, r3, #2
 *   @0x2ba5a4 mov r2, #0
 *   @0x2ba5a8 str r3, [sp, #0x1c]
 *   @0x2ba5ac str r2, [sp, #0xc]
 *   @0x2ba5b0 str r1, [sp, #0x14]
 *   @0x2ba5b4 ldr r4, [sp, #0x10]
 *   @0x2ba5b8 ldr r3, [sp, #0x18]
 *   @0x2ba5bc ldr r12, [sp, #0x14]
 *   @0x2ba5c0 cmp r3, #0
 *   @0x2ba5c4 ldr r8, [r4, #0x34]
 *   @0x2ba5c8 ldr r3, [r4, #0x3c]
 *   @0x2ba5cc ldr r9, [r4, #0x38]
 *   @0x2ba5d0 lsl r10, r12, #6
 *   @0x2ba5d4 ldr r1, [sp, #0x20]
 *   @0x2ba5d8 add r8, r8, r10
 *   @0x2ba5dc ldr r0, [sp, #0xc]
 *   @0x2ba5e0 add r9, r9, r10
 *   @0x2ba5e4 add r10, r3, r10
 *   @0x2ba5e8 ldr r3, [sp, #0x24]
 *   @0x2ba5ec ldr r2, [r1, r0]
 *   @0x2ba5f0 ldr r1, [r3, r0]
 *   @0x2ba5f4 beq 0x2ba660 <jinit_memory_mgr+0x5ac>
 *   @0x2ba5f8 ldr r12, [sp, #0x18]
 *   @0x2ba5fc mov r3, #0
 *   @0x2ba600 add r11, r1, r12
 *   @0x2ba604 ldrb r4, [r2, #0x1]
 *   @0x2ba608 add r7, r3, #1
 *   @0x2ba60c ldr r12, [sp, #0x4]
 *   @0x2ba610 add r2, r2, #3
 *   @0x2ba614 ldrb r6, [r2, #-0x3]
 *   @0x2ba618 ldr r0, [sp]
 *   @0x2ba61c add r4, r12, r4
 *   @0x2ba620 ldr r5, [r8, r3, lsl #2]
 *   @0x2ba624 ldr r12, [r9, r3, lsl #2]
 *   @0x2ba628 add r6, r0, r6
 *   @0x2ba62c ldr r0, [r10, r3, lsl #2]
 *   @0x2ba630 and r3, r7, #15
 *   @0x2ba634 ldrb r5, [r6, r5]
 *   @0x2ba638 ldrb r12, [r4, r12]
 *   @0x2ba63c ldrb r6, [r2, #-0x1]
 *   @0x2ba640 ldr r4, [sp, #0x8]
 *   @0x2ba644 add r5, r12, r5
 *   @0x2ba648 add r6, r4, r6
 *   @0x2ba64c ldrb r12, [r6, r0]
 *   @0x2ba650 add r12, r12, r5
 *   @0x2ba654 strb r12, [r1], #1
 *   @0x2ba658 cmp r1, r11
 *   @0x2ba65c bne 0x2ba604 <jinit_memory_mgr+0x550>
 *   @0x2ba660 ldr r4, [sp, #0xc]
 *   @0x2ba664 ldr r0, [sp, #0x1c]
 *   @0x2ba668 add r4, r4, #4
 *   @0x2ba66c ldr r12, [sp, #0x14]
 *   @0x2ba670 str r4, [sp, #0xc]
 *   @0x2ba674 cmp r4, r0
 *   @0x2ba678 ldr r4, [sp, #0x10]
 *   @0x2ba67c add r3, r12, #1
 *   @0x2ba680 and r3, r3, #15
 *   @0x2ba684 str r3, [r4, #0x30]
 *   @0x2ba688 strne r3, [sp, #0x14]
 *   @0x2ba68c bne 0x2ba5b4 <jinit_memory_mgr+0x500>
 *   @0x2ba690 add sp, sp, #40
 *   @0x2ba694 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2ba698 bx lr
 *   @0x2ba69c push {r3, r4, r5, r6, r7, lr}
 *   @0x2ba6a0 mov r4, r0
 *   @0x2ba6a4 ldr r7, [r0, #0x5c]
 *   @0x2ba6a8 ldr r3, [r0, #0x64]
 *   @0x2ba6ac add r7, r7, #2
 *   @0x2ba6b0 ldr r6, [r0, #0x1a8]
 *   @0x2ba6b4 cmp r3, #0
 *   @0x2ba6b8 lsl r7, r7, #1
 *   @0x2ba6bc pople {r3, r4, r5, r6, r7, pc}
 *   @0x2ba6c0 mov r5, #0
 *   @0x2ba6c4 ldr r3, [r4, #0x4]
 *   @0x2ba6c8 mov r1, #1
 *   @0x2ba6cc mov r0, r4
 *   @0x2ba6d0 mov r2, r7
 *   @0x2ba6d4 add r5, r5, r1
 *   @0x2ba6d8 add r6, r6, #4
 *   @0x2ba6dc ldr r3, [r3, #0x4]
 *   @0x2ba6e0 blx r3
 *   @0x2ba6e4 str r0, [r6, #0x40]
 *   @0x2ba6e8 ldr r3, [r4, #0x64]
 *   @0x2ba6ec cmp r3, r5
 *   @0x2ba6f0 bgt 0x2ba6c4 <jinit_memory_mgr+0x610>
 *   @0x2ba6f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x2ba6f8 bx lr
 *   @0x2ba6fc push {r3, lr}
 *   @0x2ba700 mov r1, #46
 *   @0x2ba704 ldr r3, [r0]
 *   @0x2ba708 ldr r2, [r3]
 *   @0x2ba70c str r1, [r3, #0x14]
 *   @0x2ba710 blx r2
 *   @0x2ba714 pop {r3, pc}
 *   @0x2ba718 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ba71c sub sp, sp, #84
 *   @0x2ba720 cmp r3, #0
 *   @0x2ba724 ldr r4, [r0, #0x64]
 *   @0x2ba728 ldr r12, [r0, #0x5c]
 *   @0x2ba72c str r3, [sp, #0x4c]
 *   @0x2ba730 ldr r3, [r0, #0x1a8]
 *   @0x2ba734 ldr r0, [r0, #0x120]
 *   @0x2ba738 str r1, [sp, #0x34]
 *   @0x2ba73c str r3, [sp, #0x1c]
 *   @0x2ba740 str r4, [sp, #0x28]
 *   @0x2ba744 str r12, [sp, #0x24]
 *   @0x2ba748 str r0, [sp, #0x10]
 *   @0x2ba74c ble 0x2ba954 <jinit_memory_mgr+0x8a0>
 *   @0x2ba750 sub r3, r12, #1
 *   @0x2ba754 str r3, [sp, #0x38]
 *   @0x2ba758 str r2, [sp, #0x2c]
 *   @0x2ba75c add r3, r12, #1
 *   @0x2ba760 ldr r2, [sp, #0x28]
 *   @0x2ba764 rsb r4, r4, #0
 *   @0x2ba768 ldr r12, [sp, #0x38]
 *   @0x2ba76c lsl r3, r3, #1
 *   @0x2ba770 str r4, [sp, #0x44]
 *   @0x2ba774 str r3, [sp, #0x40]
 *   @0x2ba778 mov r3, #0
 *   @0x2ba77c mul r12, r12, r2
 *   @0x2ba780 str r3, [sp, #0x48]
 *   @0x2ba784 str r12, [sp, #0x3c]
 *   @0x2ba788 ldr r4, [sp, #0x2c]
 *   @0x2ba78c ldr r1, [sp, #0x24]
 *   @0x2ba790 ldr r0, [r4], #4
 *   @0x2ba794 str r4, [sp, #0x2c]
 *   @0x2ba798 bl 0x2bc868 <jzero_far>
 *   @0x2ba79c ldr r12, [sp, #0x28]
 *   @0x2ba7a0 cmp r12, #0
 *   @0x2ba7a4 ble 0x2ba928 <jinit_memory_mgr+0x874>
 *   @0x2ba7a8 ldr r0, [sp, #0x48]
 *   @0x2ba7ac mov r3, #0
 *   @0x2ba7b0 ldr r2, [sp, #0x1c]
 *   @0x2ba7b4 str r3, [sp, #0x14]
 *   @0x2ba7b8 lsl r0, r0, #2
 *   @0x2ba7bc str r0, [sp, #0x30]
 *   @0x2ba7c0 str r2, [sp, #0x20]
 *   @0x2ba7c4 ldr r4, [sp, #0x1c]
 *   @0x2ba7c8 ldr r12, [sp, #0x30]
 *   @0x2ba7cc ldr r0, [sp, #0x14]
 *   @0x2ba7d0 ldrb r3, [r4, #0x54]
 *   @0x2ba7d4 ldr r4, [sp, #0x34]
 *   @0x2ba7d8 cmp r3, #0
 *   @0x2ba7dc ldr r1, [r4, r12]
 *   @0x2ba7e0 ldr r12, [sp, #0x2c]
 *   @0x2ba7e4 add r11, r1, r0
 *   @0x2ba7e8 ldr r2, [r12, #-0x4]
 *   @0x2ba7ec beq 0x2ba95c <jinit_memory_mgr+0x8a8>
 *   @0x2ba7f0 ldr r1, [sp, #0x20]
 *   @0x2ba7f4 ldr r4, [sp, #0x3c]
 *   @0x2ba7f8 ldr r10, [sp, #0x44]
 *   @0x2ba7fc ldr r12, [sp, #0x38]
 *   @0x2ba800 add r11, r11, r4
 *   @0x2ba804 ldr r3, [r1, #0x44]
 *   @0x2ba808 ldr r4, [sp, #0x40]
 *   @0x2ba80c add r2, r2, r12
 *   @0x2ba810 mvn r12, #0
 *   @0x2ba814 str r12, [sp, #0x4]
 *   @0x2ba818 add r3, r3, r4
 *   @0x2ba81c str r3, [sp, #0x18]
 *   @0x2ba820 ldr r4, [sp, #0x1c]
 *   @0x2ba824 ldr r0, [sp, #0x14]
 *   @0x2ba828 ldr r12, [sp, #0x24]
 *   @0x2ba82c ldr r3, [r4, #0x18]
 *   @0x2ba830 ldr r1, [r4, #0x10]
 *   @0x2ba834 cmp r12, #0
 *   @0x2ba838 ldr r3, [r3, r0, lsl #2]
 *   @0x2ba83c ldr r1, [r1, r0, lsl #2]
 *   @0x2ba840 str r3, [sp, #0x8]
 *   @0x2ba844 str r1, [sp, #0xc]
 *   @0x2ba848 beq 0x2ba978 <jinit_memory_mgr+0x8c4>
 *   @0x2ba84c ldr r1, [sp, #0x4]
 *   @0x2ba850 mov r5, #0
 *   @0x2ba854 ldr r3, [sp, #0x18]
 *   @0x2ba858 mov r7, r5
 *   @0x2ba85c add r2, r2, r1
 *   @0x2ba860 rsb r8, r1, #0
 *   @0x2ba864 lsl r6, r1, #1
 *   @0x2ba868 mov r9, r12
 *   @0x2ba86c mov r1, r5
 *   @0x2ba870 ldrsh r12, [r3, r6]
 *   @0x2ba874 add r4, r3, r6
 *   @0x2ba878 str r4, [sp]
 *   @0x2ba87c subs r9, r9, #1
 *   @0x2ba880 add r1, r12, r1
 *   @0x2ba884 ldr r4, [sp, #0x10]
 *   @0x2ba888 add r1, r1, #8
 *   @0x2ba88c ldrb r0, [r11], r10
 *   @0x2ba890 ldrb r12, [r2, r8]
 *   @0x2ba894 add r1, r4, r1, asr #4
 *   @0x2ba898 ldr r4, [sp, #0x8]
 *   @0x2ba89c ldrb r1, [r1, r0]
 *   @0x2ba8a0 ldrb r0, [r4, r1]
 *   @0x2ba8a4 ldr r4, [sp, #0x4]
 *   @0x2ba8a8 add r12, r0, r12
 *   @0x2ba8ac strb r12, [r2, r8]
 *   @0x2ba8b0 ldr r12, [sp, #0xc]
 *   @0x2ba8b4 add r2, r2, r4
 *   @0x2ba8b8 ldrb r0, [r12, r0]
 *   @0x2ba8bc rsb r0, r0, r1
 *   @0x2ba8c0 lsl r1, r0, #1
 *   @0x2ba8c4 add r12, r0, r1
 *   @0x2ba8c8 add r5, r12, r5
 *   @0x2ba8cc add r12, r12, r1
 *   @0x2ba8d0 strh r5, [r3]
 *   @0x2ba8d4 add r1, r12, r1
 *   @0x2ba8d8 add r5, r7, r12
 *   @0x2ba8dc ldr r3, [sp]
 *   @0x2ba8e0 mov r7, r0
 *   @0x2ba8e4 bne 0x2ba870 <jinit_memory_mgr+0x7bc>
 *   @0x2ba8e8 ldr r0, [sp, #0x18]
 *   @0x2ba8ec uxth r5, r5
 *   @0x2ba8f0 ldr r12, [sp, #0x24]
 *   @0x2ba8f4 mla r0, r12, r6, r0
 *   @0x2ba8f8 str r0, [sp, #0x18]
 *   @0x2ba8fc ldr r1, [sp, #0x14]
 *   @0x2ba900 ldr r3, [sp, #0x28]
 *   @0x2ba904 add r1, r1, #1
 *   @0x2ba908 ldr r2, [sp, #0x18]
 *   @0x2ba90c ldr r4, [sp, #0x20]
 *   @0x2ba910 cmp r1, r3
 *   @0x2ba914 str r1, [sp, #0x14]
 *   @0x2ba918 add r4, r4, #4
 *   @0x2ba91c strh r5, [r2]
 *   @0x2ba920 str r4, [sp, #0x20]
 *   @0x2ba924 bne 0x2ba7c4 <jinit_memory_mgr+0x710>
 *   @0x2ba928 ldr r2, [sp, #0x1c]
 *   @0x2ba92c ldr r4, [sp, #0x48]
 *   @0x2ba930 ldr r12, [sp, #0x4c]
 *   @0x2ba934 ldrb r3, [r2, #0x54]
 *   @0x2ba938 add r4, r4, #1
 *   @0x2ba93c str r4, [sp, #0x48]
 *   @0x2ba940 rsbs r3, r3, #1
 *   @0x2ba944 movlo r3, #0
 *   @0x2ba948 cmp r4, r12
 *   @0x2ba94c strb r3, [r2, #0x54]
 *   @0x2ba950 bne 0x2ba788 <jinit_memory_mgr+0x6d4>
 *   @0x2ba954 add sp, sp, #84
 *   @0x2ba958 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ba95c ldr r0, [sp, #0x20]
 *   @0x2ba960 mov r1, #1
 *   @0x2ba964 ldr r10, [sp, #0x28]
 *   @0x2ba968 str r1, [sp, #0x4]
 *   @0x2ba96c ldr r0, [r0, #0x44]
 *   @0x2ba970 str r0, [sp, #0x18]
 *   @0x2ba974 b 0x2ba820 <jinit_memory_mgr+0x76c>
 *   @0x2ba978 ldr r5, [sp, #0x24]
 *   @0x2ba97c b 0x2ba8fc <jinit_memory_mgr+0x848>
 *   @0x2ba980 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2ba984 cmp r3, #0
 *   @0x2ba988 ldr r11, [r0, #0x1a8]
 *   @0x2ba98c sub sp, sp, #36
 *   @0x2ba990 ldr r10, [r0, #0x64]
 *   @0x2ba994 ldr r0, [r0, #0x5c]
 *   @0x2ba998 str r3, [sp, #0x1c]
 *   @0x2ba99c str r1, [sp, #0x10]
 *   @0x2ba9a0 str r0, [sp]
 *   @0x2ba9a4 ble 0x2baaa0 <jinit_memory_mgr+0x9ec>
 *   @0x2ba9a8 str r2, [sp, #0x4]
 *   @0x2ba9ac mov r2, #0
 *   @0x2ba9b0 str r2, [sp, #0x14]
 *   @0x2ba9b4 ldr r3, [sp, #0x4]
 *   @0x2ba9b8 ldr r1, [sp]
 *   @0x2ba9bc ldr r0, [r3], #4
 *   @0x2ba9c0 str r3, [sp, #0x4]
 *   @0x2ba9c4 bl 0x2bc868 <jzero_far>
 *   @0x2ba9c8 ldr r0, [r11, #0x30]
 *   @0x2ba9cc cmp r10, #0
 *   @0x2ba9d0 str r0, [sp, #0x18]
 *   @0x2ba9d4 ble 0x2baa78 <jinit_memory_mgr+0x9c4>
 *   @0x2ba9d8 ldr r2, [sp, #0x18]
 *   @0x2ba9dc mov r9, r11
 *   @0x2ba9e0 ldr r3, [sp, #0x14]
 *   @0x2ba9e4 mov r8, #0
 *   @0x2ba9e8 lsl r2, r2, #6
 *   @0x2ba9ec str r2, [sp, #0xc]
 *   @0x2ba9f0 lsl r3, r3, #2
 *   @0x2ba9f4 str r3, [sp, #0x8]
 *   @0x2ba9f8 ldr r2, [sp]
 *   @0x2ba9fc ldr r0, [sp, #0x8]
 *   @0x2baa00 cmp r2, #0
 *   @0x2baa04 ldr r2, [sp, #0x10]
 *   @0x2baa08 ldr r3, [r11, #0x18]
 *   @0x2baa0c ldr r6, [r9, #0x34]
 *   @0x2baa10 ldr r1, [r2, r0]
 *   @0x2baa14 ldr r2, [sp, #0x4]
 *   @0x2baa18 ldr r5, [r3, r8, lsl #2]
 *   @0x2baa1c add r1, r1, r8
 *   @0x2baa20 ldr r3, [sp, #0xc]
 *   @0x2baa24 add r6, r6, r3
 *   @0x2baa28 ldr r3, [r2, #-0x4]
 *   @0x2baa2c beq 0x2baa68 <jinit_memory_mgr+0x9b4>
 *   @0x2baa30 ldr r2, [sp]
 *   @0x2baa34 add r7, r3, r2
 *   @0x2baa38 mov r2, #0
 *   @0x2baa3c ldrb r4, [r1], r10
 *   @0x2baa40 add r12, r2, #1
 *   @0x2baa44 ldr r0, [r6, r2, lsl #2]
 *   @0x2baa48 and r2, r12, #15
 *   @0x2baa4c add r4, r5, r4
 *   @0x2baa50 ldrb r12, [r3]
 *   @0x2baa54 ldrb r0, [r4, r0]
 *   @0x2baa58 add r0, r12, r0
 *   @0x2baa5c strb r0, [r3], #1
 *   @0x2baa60 cmp r3, r7
 *   @0x2baa64 bne 0x2baa3c <jinit_memory_mgr+0x988>
 *   @0x2baa68 add r8, r8, #1
 *   @0x2baa6c add r9, r9, #4
 *   @0x2baa70 cmp r8, r10
 *   @0x2baa74 bne 0x2ba9f8 <jinit_memory_mgr+0x944>
 *   @0x2baa78 ldr r2, [sp, #0x14]
 *   @0x2baa7c ldr r1, [sp, #0x1c]
 *   @0x2baa80 add r2, r2, #1
 *   @0x2baa84 ldr r0, [sp, #0x18]
 *   @0x2baa88 cmp r2, r1
 *   @0x2baa8c str r2, [sp, #0x14]
 *   @0x2baa90 add r3, r0, #1
 *   @0x2baa94 and r3, r3, #15
 *   @0x2baa98 str r3, [r11, #0x30]
 *   @0x2baa9c bne 0x2ba9b4 <jinit_memory_mgr+0x900>
 *   @0x2baaa0 add sp, sp, #36
 *   @0x2baaa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2baaa8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2baaac mov r11, r0
 *   @0x2baab0 ldr r4, [r0, #0x1a8]
 *   @0x2baab4 sub sp, sp, #28
 *   @0x2baab8 ldr r2, [r0, #0x4c]
 *   @0x2baabc ldr r12, [r4, #0x10]
 *   @0x2baac0 cmp r2, #1
 *   @0x2baac4 ldr r1, [r4, #0x14]
 *   @0x2baac8 str r12, [r0, #0x74]
 *   @0x2baacc str r1, [r0, #0x70]
 *   @0x2baad0 beq 0x2bab80 <jinit_memory_mgr+0xacc>
 *   @0x2baad4 blo 0x2bab60 <jinit_memory_mgr+0xaac>
 *   @0x2baad8 cmp r2, #2
 *   @0x2baadc bne 0x2bab44 <jinit_memory_mgr+0xa90>
 *   @0x2baae0 ldr r12, [r4, #0x44]
 *   @0x2baae4 mov r1, #0
 *   @0x2baae8 ldr r2, [pc, #0x228]
 *   @0x2baaec cmp r12, r1
 *   @0x2baaf0 strb r1, [r4, #0x54]
 *   @0x2baaf4 add r2, pc, r2
 *   @0x2baaf8 str r2, [r4, #0x4]
 *   @0x2baafc beq 0x2bad10 <jinit_memory_mgr+0xc5c>
 *   @0x2bab00 ldr r6, [r11, #0x5c]
 *   @0x2bab04 ldr r2, [r11, #0x64]
 *   @0x2bab08 add r6, r6, #2
 *   @0x2bab0c cmp r2, #0
 *   @0x2bab10 lsl r6, r6, #1
 *   @0x2bab14 ble 0x2bab58 <jinit_memory_mgr+0xaa4>
 *   @0x2bab18 mov r5, #0
 *   @0x2bab1c ldr r0, [r4, #0x44]
 *   @0x2bab20 mov r1, r6
 *   @0x2bab24 bl 0x2bc868 <jzero_far>
 *   @0x2bab28 ldr r3, [r11, #0x64]
 *   @0x2bab2c add r5, r5, #1
 *   @0x2bab30 add r4, r4, #4
 *   @0x2bab34 cmp r3, r5
 *   @0x2bab38 bgt 0x2bab1c <jinit_memory_mgr+0xa68>
 *   @0x2bab3c add sp, sp, #28
 *   @0x2bab40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bab44 ldr r3, [r0]
 *   @0x2bab48 mov r1, #48
 *   @0x2bab4c ldr r2, [r3]
 *   @0x2bab50 str r1, [r3, #0x14]
 *   @0x2bab54 blx r2
 *   @0x2bab58 add sp, sp, #28
 *   @0x2bab5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bab60 ldr r3, [r0, #0x64]
 *   @0x2bab64 cmp r3, #3
 *   @0x2bab68 beq 0x2bacc8 <jinit_memory_mgr+0xc14>
 *   @0x2bab6c ldr r3, [pc, #0x1a8]
 *   @0x2bab70 add r3, pc, r3
 *   @0x2bab74 str r3, [r4, #0x4]
 *   @0x2bab78 add sp, sp, #28
 *   @0x2bab7c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2bab80 ldr r2, [r0, #0x64]
 *   @0x2bab84 cmp r2, #3
 *   @0x2bab88 beq 0x2bacd8 <jinit_memory_mgr+0xc24>
 *   @0x2bab8c ldr r2, [pc, #0x18c]
 *   @0x2bab90 add r2, pc, r2
 *   @0x2bab94 str r2, [r4, #0x4]
 *   @0x2bab98 ldrb r2, [r4, #0x1c]
 *   @0x2bab9c mov r1, #0
 *   @0x2baba0 str r1, [r4, #0x30]
 *   @0x2baba4 cmp r2, r1
 *   @0x2baba8 beq 0x2bace8 <jinit_memory_mgr+0xc34>
 *   @0x2babac ldr r6, [r4, #0x34]
 *   @0x2babb0 cmp r6, #0
 *   @0x2babb4 bne 0x2bab58 <jinit_memory_mgr+0xaa4>
 *   @0x2babb8 ldr r2, [r11, #0x64]
 *   @0x2babbc ldr r9, [r11, #0x1a8]
 *   @0x2babc0 cmp r2, #0
 *   @0x2babc4 ble 0x2bab58 <jinit_memory_mgr+0xaa4>
 *   @0x2babc8 ldr r3, [pc, #0x154]
 *   @0x2babcc mov r7, r9
 *   @0x2babd0 str r11, [sp, #0x8]
 *   @0x2babd4 add r3, pc, r3
 *   @0x2babd8 str r3, [sp, #0xc]
 *   @0x2babdc add r3, r3, #256
 *   @0x2babe0 str r3, [sp, #0x10]
 *   @0x2babe4 cmp r6, #0
 *   @0x2babe8 ldr r5, [r7, #0x20]
 *   @0x2babec beq 0x2bac24 <jinit_memory_mgr+0xb70>
 *   @0x2babf0 ldr r3, [r9, #0x20]
 *   @0x2babf4 cmp r5, r3
 *   @0x2babf8 movne r2, r9
 *   @0x2babfc movne r3, #0
 *   @0x2bac00 bne 0x2bac14 <jinit_memory_mgr+0xb60>
 *   @0x2bac04 b 0x2bacf4 <jinit_memory_mgr+0xc40>
 *   @0x2bac08 ldr r1, [r2, #0x20]
 *   @0x2bac0c cmp r5, r1
 *   @0x2bac10 beq 0x2bacf8 <jinit_memory_mgr+0xc44>
 *   @0x2bac14 add r3, r3, #1
 *   @0x2bac18 add r2, r2, #4
 *   @0x2bac1c cmp r3, r6
 *   @0x2bac20 bne 0x2bac08 <jinit_memory_mgr+0xb54>
 *   @0x2bac24 ldr r2, [sp, #0x8]
 *   @0x2bac28 mov r1, #1
 *   @0x2bac2c ldr r4, [sp, #0xc]
 *   @0x2bac30 sub r5, r5, #1
 *   @0x2bac34 ldr r3, [r2, #0x4]
 *   @0x2bac38 mov r0, r2
 *   @0x2bac3c mov r2, #1024
 *   @0x2bac40 lsl r5, r5, #9
 *   @0x2bac44 ldr r3, [r3]
 *   @0x2bac48 blx r3
 *   @0x2bac4c ldr r11, [sp, #0x10]
 *   @0x2bac50 str r6, [sp, #0x14]
 *   @0x2bac54 sub r8, r0, #4
 *   @0x2bac58 str r0, [sp, #0x4]
 *   @0x2bac5c mov r6, r8
 *   @0x2bac60 mov r10, #0
 *   @0x2bac64 ldrb r3, [r4, r10]
 *   @0x2bac68 mov r1, r5
 *   @0x2bac6c add r10, r10, #1
 *   @0x2bac70 sub r3, r3, r3, lsl #8
 *   @0x2bac74 lsl r0, r3, #1
 *   @0x2bac78 add r0, r0, #65024
 *   @0x2bac7c add r0, r0, #1
 *   @0x2bac80 bl 0x318d10 <__divsi3>
 *   @0x2bac84 cmp r10, #16
 *   @0x2bac88 str r0, [r6, #0x4]!
 *   @0x2bac8c bne 0x2bac64 <jinit_memory_mgr+0xbb0>
 *   @0x2bac90 add r4, r4, #16
 *   @0x2bac94 add r8, r8, #64
 *   @0x2bac98 cmp r4, r11
 *   @0x2bac9c bne 0x2bac5c <jinit_memory_mgr+0xba8>
 *   @0x2baca0 ldr r6, [sp, #0x14]
 *   @0x2baca4 ldr r3, [sp, #0x4]
 *   @0x2baca8 add r6, r6, #1
 *   @0x2bacac ldr r2, [sp, #0x8]
 *   @0x2bacb0 add r7, r7, #4
 *   @0x2bacb4 str r3, [r7, #0x30]
 *   @0x2bacb8 ldr r3, [r2, #0x64]
 *   @0x2bacbc cmp r6, r3
 *   @0x2bacc0 blt 0x2babe4 <jinit_memory_mgr+0xb30>
 *   @0x2bacc4 b 0x2bab58 <jinit_memory_mgr+0xaa4>
 *   @0x2bacc8 ldr r3, [pc, #0x58]
 *   @0x2baccc add r3, pc, r3
 *   @0x2bacd0 str r3, [r4, #0x4]
 *   @0x2bacd4 b 0x2bab58 <jinit_memory_mgr+0xaa4>
 *   @0x2bacd8 ldr r2, [pc, #0x4c]
 *   @0x2bacdc add r2, pc, r2
 *   @0x2bace0 str r2, [r4, #0x4]
 *   @0x2bace4 b 0x2bab98 <jinit_memory_mgr+0xae4>
 *   @0x2bace8 mov r0, r11
 *   @0x2bacec bl 0x2ba268 <jinit_memory_mgr+0x1b4>
 *   @0x2bacf0 b 0x2babac <jinit_memory_mgr+0xaf8>
 *   @0x2bacf4 mov r3, #0
 *   @0x2bacf8 add r3, r9, r3, lsl #2
 *   @0x2bacfc ldr r3, [r3, #0x34]
 *   @0x2bad00 cmp r3, #0
 *   @0x2bad04 str r3, [sp, #0x4]
 *   @0x2bad08 bne 0x2baca4 <jinit_memory_mgr+0xbf0>
 *   @0x2bad0c b 0x2bac24 <jinit_memory_mgr+0xb70>
 *   @0x2bad10 bl 0x2ba69c <jinit_memory_mgr+0x5e8>
 *   @0x2bad14 b 0x2bab00 <jinit_memory_mgr+0xa4c>
 *   @0x2bad18 .word 0xfffffc1c
 *   @0x2bad1c .word 0xfffff8ac
 *   @0x2bad20 .word 0xfffffde8
 *   @0x2bad24 strdeq r5, r6, [sp], -r12
 *   @0x2bad28 .word 0xfffff7f8
 *
 * ══ §4/12 CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)  0x1a6154  size 2660  665 条（0x1a6154..0x1a6bb8）
 * @func 0x1a6154 0x1a6bb8  size 2660  665 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPath::AddInternalPoint(float, float, float)×9 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x38×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x170×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x2a0×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x3dc×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x50c×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x640×2 / CPath::HandlePiece(int, float, float, float, float, float, float, float, float, float)+0x778×2
 * 字段偏移 top8: 0xac×4 / 0xa8×4 / 0x9c×1 / 0xa0×1 / 0xb0×1 / 0x98×1 / 0xa4×1 / 0xb4×1
 * VFP 指令 536 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a6154 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a6158 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a615c cmp r1, #0
 *   @0x1a6160 sub sp, sp, #196
 *   @0x1a6164 mov r5, r0
 *   @0x1a6168 vmov s15, r2
 *   @0x1a616c vldr s12, [sp, #296]
 *   @0x1a6170 str r1, [sp, #0xac]
 *   @0x1a6174 vmov s14, r3
 *   @0x1a6178 beq 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58>
 *   @0x1a617c vmov.f32 s28, #2.500000e-01
 *   @0x1a6180 vmov.f32 s30, #1.600000e+01
 *   @0x1a6184 vmov.f32 s31, #5.000000e-01
 *   @0x1a6188 b 0x1a6224 <_ZN5CPath11HandlePieceEifffffffff+0xd0>
 *   @0x1a618c mov r0, r5
 *   @0x1a6190 ldr r1, [sp, #0x9c]
 *   @0x1a6194 ldr r2, [sp, #0xa0]
 *   @0x1a6198 ldr r3, [sp, #0xb0]
 *   @0x1a619c bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a61a0 vldr s7, [sp, #304]
 *   @0x1a61a4 vldr s8, [sp, #316]
 *   @0x1a61a8 vsub.f32 s15, s7, s8
 *   @0x1a61ac vldr s9, [sp, #300]
 *   @0x1a61b0 vldr s10, [sp, #312]
 *   @0x1a61b4 vmul.f32 s15, s15, s15
 *   @0x1a61b8 vsub.f32 s14, s9, s10
 *   @0x1a61bc vmla.f32 s15, s14, s14
 *   @0x1a61c0 vcmpe.f32 s15, s30
 *   @0x1a61c4 vmrs APSR_nzcv, fpscr
 *   @0x1a61c8 ble 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58>
 *   @0x1a61cc vldr s8, [sp, #300]
 *   @0x1a61d0 vldr s9, [sp, #312]
 *   @0x1a61d4 vldr s5, [sp, #304]
 *   @0x1a61d8 vadd.f32 s13, s8, s9
 *   @0x1a61dc vldr s7, [sp, #316]
 *   @0x1a61e0 vldr s8, [sp, #308]
 *   @0x1a61e4 vldr s9, [sp, #320]
 *   @0x1a61e8 ldr r3, [sp, #0xac]
 *   @0x1a61ec subs r3, r3, #1
 *   @0x1a61f0 str r3, [sp, #0xac]
 *   @0x1a61f4 vadd.f32 s14, s5, s7
 *   @0x1a61f8 vadd.f32 s15, s8, s9
 *   @0x1a61fc vmul.f32 s13, s13, s31
 *   @0x1a6200 vmul.f32 s14, s14, s31
 *   @0x1a6204 vstr s13, [sp, #300]
 *   @0x1a6208 vmul.f32 s15, s15, s31
 *   @0x1a620c vstr s14, [sp, #304]
 *   @0x1a6210 vstr s15, [sp, #308]
 *   @0x1a6214 beq 0x1a6bac <_ZN5CPath11HandlePieceEifffffffff+0xa58>
 *   @0x1a6218 vldr s12, [sp, #176]
 *   @0x1a621c vldr s14, [sp, #160]
 *   @0x1a6220 vldr s15, [sp, #156]
 *   @0x1a6224 vldr s5, [sp, #304]
 *   @0x1a6228 vsub.f32 s13, s5, s14
 *   @0x1a622c vldr s7, [sp, #300]
 *   @0x1a6230 vmul.f32 s13, s13, s13
 *   @0x1a6234 vsub.f32 s8, s7, s15
 *   @0x1a6238 vadd.f32 s9, s15, s7
 *   @0x1a623c vadd.f32 s10, s14, s5
 *   @0x1a6240 vldr s5, [sp, #308]
 *   @0x1a6244 vadd.f32 s11, s12, s5
 *   @0x1a6248 vmla.f32 s13, s8, s8
 *   @0x1a624c vldr s8, [sp, #304]
 *   @0x1a6250 vadd.f32 s6, s9, s7
 *   @0x1a6254 vadd.f32 s7, s10, s8
 *   @0x1a6258 vadd.f32 s8, s11, s5
 *   @0x1a625c vldr s5, [sp, #312]
 *   @0x1a6260 vadd.f32 s6, s6, s5
 *   @0x1a6264 vldr s5, [sp, #316]
 *   @0x1a6268 vadd.f32 s7, s7, s5
 *   @0x1a626c vldr s5, [sp, #320]
 *   @0x1a6270 vadd.f32 s8, s8, s5
 *   @0x1a6274 vmul.f32 s6, s6, s28
 *   @0x1a6278 vmul.f32 s7, s7, s28
 *   @0x1a627c vstr s6, [sp, #156]
 *   @0x1a6280 vmul.f32 s8, s8, s28
 *   @0x1a6284 vstr s7, [sp, #160]
 *   @0x1a6288 vcmpe.f32 s13, s30
 *   @0x1a628c vstr s8, [sp, #176]
 *   @0x1a6290 vmrs APSR_nzcv, fpscr
 *   @0x1a6294 ble 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38>
 *   @0x1a6298 vmul.f32 s9, s9, s31
 *   @0x1a629c ldr r3, [sp, #0xac]
 *   @0x1a62a0 cmp r3, #1
 *   @0x1a62a4 vmul.f32 s10, s10, s31
 *   @0x1a62a8 vstr s9, [sp, #136]
 *   @0x1a62ac vmul.f32 s11, s11, s31
 *   @0x1a62b0 vstr s10, [sp, #140]
 *   @0x1a62b4 vstr s11, [sp, #184]
 *   @0x1a62b8 beq 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38>
 *   @0x1a62bc sub r11, r3, #2
 *   @0x1a62c0 b 0x1a6358 <_ZN5CPath11HandlePieceEifffffffff+0x204>
 *   @0x1a62c4 mov r0, r5
 *   @0x1a62c8 ldr r1, [sp, #0x98]
 *   @0x1a62cc ldr r2, [sp, #0xa4]
 *   @0x1a62d0 ldr r3, [sp, #0xb4]
 *   @0x1a62d4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a62d8 vldr s7, [sp, #140]
 *   @0x1a62dc vldr s8, [sp, #160]
 *   @0x1a62e0 vsub.f32 s15, s7, s8
 *   @0x1a62e4 vldr s9, [sp, #136]
 *   @0x1a62e8 vldr s10, [sp, #156]
 *   @0x1a62ec vmul.f32 s15, s15, s15
 *   @0x1a62f0 vsub.f32 s14, s9, s10
 *   @0x1a62f4 vmla.f32 s15, s14, s14
 *   @0x1a62f8 vcmpe.f32 s15, s30
 *   @0x1a62fc vmrs APSR_nzcv, fpscr
 *   @0x1a6300 ble 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38>
 *   @0x1a6304 vldr s15, [sp, #140]
 *   @0x1a6308 vldr s11, [sp, #136]
 *   @0x1a630c vldr s7, [sp, #184]
 *   @0x1a6310 vldr s10, [sp, #156]
 *   @0x1a6314 vldr s12, [sp, #160]
 *   @0x1a6318 vadd.f32 s13, s10, s11
 *   @0x1a631c vldr s5, [sp, #176]
 *   @0x1a6320 cmp r11, #0
 *   @0x1a6324 sub r11, r11, #1
 *   @0x1a6328 vadd.f32 s14, s12, s15
 *   @0x1a632c vadd.f32 s15, s5, s7
 *   @0x1a6330 vmul.f32 s13, s13, s31
 *   @0x1a6334 vmul.f32 s14, s14, s31
 *   @0x1a6338 vstr s13, [sp, #136]
 *   @0x1a633c vmul.f32 s15, s15, s31
 *   @0x1a6340 vstr s14, [sp, #140]
 *   @0x1a6344 vstr s15, [sp, #184]
 *   @0x1a6348 beq 0x1a618c <_ZN5CPath11HandlePieceEifffffffff+0x38>
 *   @0x1a634c vldr s12, [sp, #180]
 *   @0x1a6350 vldr s14, [sp, #164]
 *   @0x1a6354 vldr s15, [sp, #152]
 *   @0x1a6358 vldr s5, [sp, #140]
 *   @0x1a635c vsub.f32 s13, s5, s14
 *   @0x1a6360 vldr s7, [sp, #136]
 *   @0x1a6364 vmul.f32 s13, s13, s13
 *   @0x1a6368 vsub.f32 s8, s7, s15
 *   @0x1a636c vadd.f32 s9, s15, s7
 *   @0x1a6370 vadd.f32 s10, s14, s5
 *   @0x1a6374 vldr s5, [sp, #184]
 *   @0x1a6378 vadd.f32 s11, s12, s5
 *   @0x1a637c vmla.f32 s13, s8, s8
 *   @0x1a6380 vldr s8, [sp, #140]
 *   @0x1a6384 vadd.f32 s6, s7, s9
 *   @0x1a6388 vadd.f32 s7, s8, s10
 *   @0x1a638c vadd.f32 s8, s5, s11
 *   @0x1a6390 vldr s5, [sp, #156]
 *   @0x1a6394 vadd.f32 s6, s5, s6
 *   @0x1a6398 vldr s5, [sp, #160]
 *   @0x1a639c vadd.f32 s7, s5, s7
 *   @0x1a63a0 vldr s5, [sp, #176]
 *   @0x1a63a4 vadd.f32 s8, s5, s8
 *   @0x1a63a8 vmul.f32 s6, s6, s28
 *   @0x1a63ac vmul.f32 s7, s7, s28
 *   @0x1a63b0 vstr s6, [sp, #152]
 *   @0x1a63b4 vmul.f32 s8, s8, s28
 *   @0x1a63b8 vstr s7, [sp, #164]
 *   @0x1a63bc vcmpe.f32 s13, s30
 *   @0x1a63c0 vstr s8, [sp, #180]
 *   @0x1a63c4 vmrs APSR_nzcv, fpscr
 *   @0x1a63c8 ble 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170>
 *   @0x1a63cc vmul.f32 s9, s9, s31
 *   @0x1a63d0 cmp r11, #0
 *   @0x1a63d4 str r11, [sp, #0xa8]
 *   @0x1a63d8 vmul.f32 s10, s10, s31
 *   @0x1a63dc vstr s9, [sp, #144]
 *   @0x1a63e0 vmul.f32 s11, s11, s31
 *   @0x1a63e4 vstr s10, [sp, #148]
 *   @0x1a63e8 vstr s11, [sp, #188]
 *   @0x1a63ec bne 0x1a648c <_ZN5CPath11HandlePieceEifffffffff+0x338>
 *   @0x1a63f0 b 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170>
 *   @0x1a63f4 mov r0, r5
 *   @0x1a63f8 ldr r1, [sp, #0x80]
 *   @0x1a63fc ldr r2, [sp, #0x78]
 *   @0x1a6400 ldr r3, [sp, #0x84]
 *   @0x1a6404 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6408 vldr s7, [sp, #148]
 *   @0x1a640c vldr s8, [sp, #164]
 *   @0x1a6410 vsub.f32 s15, s7, s8
 *   @0x1a6414 vldr s9, [sp, #144]
 *   @0x1a6418 vldr s10, [sp, #152]
 *   @0x1a641c vmul.f32 s15, s15, s15
 *   @0x1a6420 vsub.f32 s14, s9, s10
 *   @0x1a6424 vmla.f32 s15, s14, s14
 *   @0x1a6428 vcmpe.f32 s15, s30
 *   @0x1a642c vmrs APSR_nzcv, fpscr
 *   @0x1a6430 ble 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170>
 *   @0x1a6434 vldr s15, [sp, #144]
 *   @0x1a6438 vldr s14, [sp, #152]
 *   @0x1a643c vldr s7, [sp, #148]
 *   @0x1a6440 vadd.f32 s13, s14, s15
 *   @0x1a6444 vldr s9, [sp, #188]
 *   @0x1a6448 vldr s5, [sp, #164]
 *   @0x1a644c vldr s8, [sp, #180]
 *   @0x1a6450 ldr r3, [sp, #0xa8]
 *   @0x1a6454 subs r3, r3, #1
 *   @0x1a6458 str r3, [sp, #0xa8]
 *   @0x1a645c vadd.f32 s14, s5, s7
 *   @0x1a6460 vadd.f32 s15, s8, s9
 *   @0x1a6464 vmul.f32 s13, s13, s31
 *   @0x1a6468 vmul.f32 s14, s14, s31
 *   @0x1a646c vstr s13, [sp, #144]
 *   @0x1a6470 vmul.f32 s15, s15, s31
 *   @0x1a6474 vstr s14, [sp, #148]
 *   @0x1a6478 vstr s15, [sp, #188]
 *   @0x1a647c beq 0x1a62c4 <_ZN5CPath11HandlePieceEifffffffff+0x170>
 *   @0x1a6480 vldr s12, [sp, #132]
 *   @0x1a6484 vldr s14, [sp, #120]
 *   @0x1a6488 vldr s15, [sp, #128]
 *   @0x1a648c vldr s11, [sp, #148]
 *   @0x1a6490 vsub.f32 s13, s11, s14
 *   @0x1a6494 vldr s5, [sp, #144]
 *   @0x1a6498 vldr s7, [sp, #188]
 *   @0x1a649c vmul.f32 s13, s13, s13
 *   @0x1a64a0 vsub.f32 s8, s5, s15
 *   @0x1a64a4 vadd.f32 s9, s15, s5
 *   @0x1a64a8 vadd.f32 s10, s14, s11
 *   @0x1a64ac vadd.f32 s11, s12, s7
 *   @0x1a64b0 vmla.f32 s13, s8, s8
 *   @0x1a64b4 vldr s8, [sp, #148]
 *   @0x1a64b8 vadd.f32 s6, s5, s9
 *   @0x1a64bc vldr s5, [sp, #188]
 *   @0x1a64c0 vadd.f32 s7, s8, s10
 *   @0x1a64c4 vadd.f32 s8, s5, s11
 *   @0x1a64c8 vldr s5, [sp, #152]
 *   @0x1a64cc vadd.f32 s6, s5, s6
 *   @0x1a64d0 vldr s5, [sp, #164]
 *   @0x1a64d4 vadd.f32 s7, s5, s7
 *   @0x1a64d8 vldr s5, [sp, #180]
 *   @0x1a64dc vadd.f32 s8, s5, s8
 *   @0x1a64e0 vmul.f32 s6, s6, s28
 *   @0x1a64e4 vmul.f32 s7, s7, s28
 *   @0x1a64e8 vstr s6, [sp, #128]
 *   @0x1a64ec vmul.f32 s8, s8, s28
 *   @0x1a64f0 vstr s7, [sp, #120]
 *   @0x1a64f4 vcmpe.f32 s13, s30
 *   @0x1a64f8 vstr s8, [sp, #132]
 *   @0x1a64fc vmrs APSR_nzcv, fpscr
 *   @0x1a6500 ble 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0>
 *   @0x1a6504 vmul.f32 s9, s9, s31
 *   @0x1a6508 ldr r3, [sp, #0xa8]
 *   @0x1a650c cmp r3, #1
 *   @0x1a6510 vmul.f32 s10, s10, s31
 *   @0x1a6514 vstr s9, [sp, #116]
 *   @0x1a6518 vmul.f32 s11, s11, s31
 *   @0x1a651c vstr s10, [sp, #112]
 *   @0x1a6520 vstr s11, [sp, #124]
 *   @0x1a6524 beq 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0>
 *   @0x1a6528 sub r10, r3, #2
 *   @0x1a652c b 0x1a65c4 <_ZN5CPath11HandlePieceEifffffffff+0x470>
 *   @0x1a6530 mov r0, r5
 *   @0x1a6534 ldr r1, [sp, #0x64]
 *   @0x1a6538 ldr r2, [sp, #0x68]
 *   @0x1a653c ldr r3, [sp, #0x6c]
 *   @0x1a6540 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6544 vldr s7, [sp, #112]
 *   @0x1a6548 vldr s8, [sp, #120]
 *   @0x1a654c vsub.f32 s15, s7, s8
 *   @0x1a6550 vldr s9, [sp, #116]
 *   @0x1a6554 vldr s10, [sp, #128]
 *   @0x1a6558 vmul.f32 s15, s15, s15
 *   @0x1a655c vsub.f32 s14, s9, s10
 *   @0x1a6560 vmla.f32 s15, s14, s14
 *   @0x1a6564 vcmpe.f32 s15, s30
 *   @0x1a6568 vmrs APSR_nzcv, fpscr
 *   @0x1a656c ble 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0>
 *   @0x1a6570 vldr s8, [sp, #116]
 *   @0x1a6574 vldr s10, [sp, #112]
 *   @0x1a6578 vldr s12, [sp, #124]
 *   @0x1a657c vldr s7, [sp, #128]
 *   @0x1a6580 vldr s9, [sp, #120]
 *   @0x1a6584 vadd.f32 s13, s7, s8
 *   @0x1a6588 vldr s11, [sp, #132]
 *   @0x1a658c cmp r10, #0
 *   @0x1a6590 sub r10, r10, #1
 *   @0x1a6594 vadd.f32 s14, s9, s10
 *   @0x1a6598 vadd.f32 s15, s11, s12
 *   @0x1a659c vmul.f32 s13, s13, s31
 *   @0x1a65a0 vmul.f32 s14, s14, s31
 *   @0x1a65a4 vstr s13, [sp, #116]
 *   @0x1a65a8 vmul.f32 s15, s15, s31
 *   @0x1a65ac vstr s14, [sp, #112]
 *   @0x1a65b0 vstr s15, [sp, #124]
 *   @0x1a65b4 beq 0x1a63f4 <_ZN5CPath11HandlePieceEifffffffff+0x2a0>
 *   @0x1a65b8 vldr s15, [sp, #100]
 *   @0x1a65bc vldr s14, [sp, #104]
 *   @0x1a65c0 vldr s12, [sp, #108]
 *   @0x1a65c4 vldr s5, [sp, #112]
 *   @0x1a65c8 vsub.f32 s13, s5, s14
 *   @0x1a65cc vldr s7, [sp, #116]
 *   @0x1a65d0 vmul.f32 s13, s13, s13
 *   @0x1a65d4 vsub.f32 s11, s7, s15
 *   @0x1a65d8 vadd.f32 s8, s15, s7
 *   @0x1a65dc vadd.f32 s9, s14, s5
 *   @0x1a65e0 vldr s5, [sp, #124]
 *   @0x1a65e4 vadd.f32 s10, s12, s5
 *   @0x1a65e8 vmla.f32 s13, s11, s11
 *   @0x1a65ec vldr s11, [sp, #112]
 *   @0x1a65f0 vadd.f32 s6, s7, s8
 *   @0x1a65f4 vadd.f32 s7, s11, s9
 *   @0x1a65f8 vadd.f32 s11, s5, s10
 *   @0x1a65fc vldr s5, [sp, #128]
 *   @0x1a6600 vadd.f32 s6, s5, s6
 *   @0x1a6604 vldr s5, [sp, #120]
 *   @0x1a6608 vadd.f32 s7, s5, s7
 *   @0x1a660c vldr s5, [sp, #132]
 *   @0x1a6610 vadd.f32 s11, s5, s11
 *   @0x1a6614 vmul.f32 s6, s6, s28
 *   @0x1a6618 vmul.f32 s7, s7, s28
 *   @0x1a661c vstr s6, [sp, #100]
 *   @0x1a6620 vmul.f32 s11, s11, s28
 *   @0x1a6624 vstr s7, [sp, #104]
 *   @0x1a6628 vcmpe.f32 s13, s30
 *   @0x1a662c vstr s11, [sp, #108]
 *   @0x1a6630 vmrs APSR_nzcv, fpscr
 *   @0x1a6634 ble 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc>
 *   @0x1a6638 vmul.f32 s8, s8, s31
 *   @0x1a663c cmp r10, #0
 *   @0x1a6640 mov r9, r10
 *   @0x1a6644 vmul.f32 s9, s9, s31
 *   @0x1a6648 vstr s8, [sp, #92]
 *   @0x1a664c vmul.f32 s10, s10, s31
 *   @0x1a6650 vstr s9, [sp, #88]
 *   @0x1a6654 vstr s10, [sp, #96]
 *   @0x1a6658 bne 0x1a66f0 <_ZN5CPath11HandlePieceEifffffffff+0x59c>
 *   @0x1a665c b 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc>
 *   @0x1a6660 mov r0, r5
 *   @0x1a6664 ldr r1, [sp, #0x4c]
 *   @0x1a6668 ldr r2, [sp, #0x50]
 *   @0x1a666c ldr r3, [sp, #0x54]
 *   @0x1a6670 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6674 vldr s7, [sp, #88]
 *   @0x1a6678 vldr s8, [sp, #104]
 *   @0x1a667c vsub.f32 s15, s7, s8
 *   @0x1a6680 vldr s9, [sp, #92]
 *   @0x1a6684 vldr s10, [sp, #100]
 *   @0x1a6688 vmul.f32 s15, s15, s15
 *   @0x1a668c vsub.f32 s14, s9, s10
 *   @0x1a6690 vmla.f32 s15, s14, s14
 *   @0x1a6694 vcmpe.f32 s15, s30
 *   @0x1a6698 vmrs APSR_nzcv, fpscr
 *   @0x1a669c ble 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc>
 *   @0x1a66a0 vldr s9, [sp, #92]
 *   @0x1a66a4 vldr s11, [sp, #88]
 *   @0x1a66a8 vldr s5, [sp, #96]
 *   @0x1a66ac vldr s8, [sp, #100]
 *   @0x1a66b0 vldr s10, [sp, #104]
 *   @0x1a66b4 vadd.f32 s13, s8, s9
 *   @0x1a66b8 vldr s12, [sp, #108]
 *   @0x1a66bc subs r9, r9, #1
 *   @0x1a66c0 vadd.f32 s14, s10, s11
 *   @0x1a66c4 vadd.f32 s15, s12, s5
 *   @0x1a66c8 vmul.f32 s13, s13, s31
 *   @0x1a66cc vmul.f32 s14, s14, s31
 *   @0x1a66d0 vstr s13, [sp, #92]
 *   @0x1a66d4 vmul.f32 s15, s15, s31
 *   @0x1a66d8 vstr s14, [sp, #88]
 *   @0x1a66dc vstr s15, [sp, #96]
 *   @0x1a66e0 beq 0x1a6530 <_ZN5CPath11HandlePieceEifffffffff+0x3dc>
 *   @0x1a66e4 vldr s15, [sp, #76]
 *   @0x1a66e8 vldr s14, [sp, #80]
 *   @0x1a66ec vldr s12, [sp, #84]
 *   @0x1a66f0 vldr s11, [sp, #88]
 *   @0x1a66f4 vsub.f32 s13, s11, s14
 *   @0x1a66f8 vldr s5, [sp, #92]
 *   @0x1a66fc vldr s7, [sp, #88]
 *   @0x1a6700 vmul.f32 s13, s13, s13
 *   @0x1a6704 vsub.f32 s11, s5, s15
 *   @0x1a6708 vadd.f32 s8, s15, s5
 *   @0x1a670c vldr s5, [sp, #96]
 *   @0x1a6710 vadd.f32 s9, s14, s7
 *   @0x1a6714 vldr s7, [sp, #92]
 *   @0x1a6718 vadd.f32 s10, s12, s5
 *   @0x1a671c vmla.f32 s13, s11, s11
 *   @0x1a6720 vldr s11, [sp, #88]
 *   @0x1a6724 vadd.f32 s6, s7, s8
 *   @0x1a6728 vadd.f32 s7, s11, s9
 *   @0x1a672c vadd.f32 s11, s5, s10
 *   @0x1a6730 vldr s5, [sp, #100]
 *   @0x1a6734 vadd.f32 s6, s5, s6
 *   @0x1a6738 vldr s5, [sp, #104]
 *   @0x1a673c vadd.f32 s7, s5, s7
 *   @0x1a6740 vldr s5, [sp, #108]
 *   @0x1a6744 vadd.f32 s11, s5, s11
 *   @0x1a6748 vmul.f32 s6, s6, s28
 *   @0x1a674c vmul.f32 s7, s7, s28
 *   @0x1a6750 vstr s6, [sp, #76]
 *   @0x1a6754 vmul.f32 s11, s11, s28
 *   @0x1a6758 vstr s7, [sp, #80]
 *   @0x1a675c vcmpe.f32 s13, s30
 *   @0x1a6760 vstr s11, [sp, #84]
 *   @0x1a6764 vmrs APSR_nzcv, fpscr
 *   @0x1a6768 ble 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c>
 *   @0x1a676c vmul.f32 s8, s8, s31
 *   @0x1a6770 cmp r9, #1
 *   @0x1a6774 vmul.f32 s9, s9, s31
 *   @0x1a6778 vstr s8, [sp, #64]
 *   @0x1a677c vmul.f32 s10, s10, s31
 *   @0x1a6780 vstr s9, [sp, #68]
 *   @0x1a6784 vstr s10, [sp, #72]
 *   @0x1a6788 beq 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c>
 *   @0x1a678c sub r8, r9, #2
 *   @0x1a6790 b 0x1a6828 <_ZN5CPath11HandlePieceEifffffffff+0x6d4>
 *   @0x1a6794 mov r0, r5
 *   @0x1a6798 ldr r1, [sp, #0x34]
 *   @0x1a679c ldr r2, [sp, #0x38]
 *   @0x1a67a0 ldr r3, [sp, #0x3c]
 *   @0x1a67a4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a67a8 vldr s7, [sp, #68]
 *   @0x1a67ac vldr s8, [sp, #80]
 *   @0x1a67b0 vsub.f32 s15, s7, s8
 *   @0x1a67b4 vldr s9, [sp, #64]
 *   @0x1a67b8 vldr s10, [sp, #76]
 *   @0x1a67bc vmul.f32 s15, s15, s15
 *   @0x1a67c0 vsub.f32 s14, s9, s10
 *   @0x1a67c4 vmla.f32 s15, s14, s14
 *   @0x1a67c8 vcmpe.f32 s15, s30
 *   @0x1a67cc vmrs APSR_nzcv, fpscr
 *   @0x1a67d0 ble 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c>
 *   @0x1a67d4 vldr s10, [sp, #64]
 *   @0x1a67d8 vldr s12, [sp, #68]
 *   @0x1a67dc vldr s7, [sp, #72]
 *   @0x1a67e0 vldr s9, [sp, #76]
 *   @0x1a67e4 vldr s11, [sp, #80]
 *   @0x1a67e8 vadd.f32 s13, s9, s10
 *   @0x1a67ec vldr s5, [sp, #84]
 *   @0x1a67f0 cmp r8, #0
 *   @0x1a67f4 sub r8, r8, #1
 *   @0x1a67f8 vadd.f32 s14, s11, s12
 *   @0x1a67fc vadd.f32 s15, s5, s7
 *   @0x1a6800 vmul.f32 s13, s13, s31
 *   @0x1a6804 vmul.f32 s14, s14, s31
 *   @0x1a6808 vstr s13, [sp, #64]
 *   @0x1a680c vmul.f32 s15, s15, s31
 *   @0x1a6810 vstr s14, [sp, #68]
 *   @0x1a6814 vstr s15, [sp, #72]
 *   @0x1a6818 beq 0x1a6660 <_ZN5CPath11HandlePieceEifffffffff+0x50c>
 *   @0x1a681c vldr s15, [sp, #52]
 *   @0x1a6820 vldr s12, [sp, #60]
 *   @0x1a6824 vldr s14, [sp, #56]
 *   @0x1a6828 vldr s11, [sp, #68]
 *   @0x1a682c vsub.f32 s13, s11, s14
 *   @0x1a6830 vldr s5, [sp, #64]
 *   @0x1a6834 vldr s7, [sp, #68]
 *   @0x1a6838 vmul.f32 s13, s13, s13
 *   @0x1a683c vsub.f32 s11, s5, s15
 *   @0x1a6840 vadd.f32 s8, s15, s5
 *   @0x1a6844 vldr s5, [sp, #72]
 *   @0x1a6848 vadd.f32 s9, s14, s7
 *   @0x1a684c vldr s7, [sp, #64]
 *   @0x1a6850 vadd.f32 s10, s12, s5
 *   @0x1a6854 vmla.f32 s13, s11, s11
 *   @0x1a6858 vldr s11, [sp, #68]
 *   @0x1a685c vadd.f32 s6, s7, s8
 *   @0x1a6860 vadd.f32 s7, s11, s9
 *   @0x1a6864 vadd.f32 s11, s5, s10
 *   @0x1a6868 vldr s5, [sp, #76]
 *   @0x1a686c vadd.f32 s6, s5, s6
 *   @0x1a6870 vldr s5, [sp, #80]
 *   @0x1a6874 vadd.f32 s7, s5, s7
 *   @0x1a6878 vldr s5, [sp, #84]
 *   @0x1a687c vadd.f32 s11, s5, s11
 *   @0x1a6880 vmul.f32 s6, s6, s28
 *   @0x1a6884 vmul.f32 s7, s7, s28
 *   @0x1a6888 vstr s6, [sp, #52]
 *   @0x1a688c vmul.f32 s11, s11, s28
 *   @0x1a6890 vstr s7, [sp, #56]
 *   @0x1a6894 vcmpe.f32 s13, s30
 *   @0x1a6898 vstr s11, [sp, #60]
 *   @0x1a689c vmrs APSR_nzcv, fpscr
 *   @0x1a68a0 ble 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640>
 *   @0x1a68a4 vmul.f32 s8, s8, s31
 *   @0x1a68a8 cmp r8, #0
 *   @0x1a68ac mov r7, r8
 *   @0x1a68b0 vmul.f32 s9, s9, s31
 *   @0x1a68b4 vstr s8, [sp, #40]
 *   @0x1a68b8 vmul.f32 s10, s10, s31
 *   @0x1a68bc vstr s9, [sp, #44]
 *   @0x1a68c0 vstr s10, [sp, #48]
 *   @0x1a68c4 bne 0x1a695c <_ZN5CPath11HandlePieceEifffffffff+0x808>
 *   @0x1a68c8 b 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640>
 *   @0x1a68cc mov r0, r5
 *   @0x1a68d0 ldr r1, [sp, #0x20]
 *   @0x1a68d4 vmov r2, s29
 *   @0x1a68d8 ldr r3, [sp, #0x24]
 *   @0x1a68dc bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a68e0 vldr s8, [sp, #44]
 *   @0x1a68e4 vldr s9, [sp, #56]
 *   @0x1a68e8 vsub.f32 s15, s8, s9
 *   @0x1a68ec vldr s10, [sp, #40]
 *   @0x1a68f0 vldr s11, [sp, #52]
 *   @0x1a68f4 vmul.f32 s15, s15, s15
 *   @0x1a68f8 vsub.f32 s14, s10, s11
 *   @0x1a68fc vmla.f32 s15, s14, s14
 *   @0x1a6900 vcmpe.f32 s15, s30
 *   @0x1a6904 vmrs APSR_nzcv, fpscr
 *   @0x1a6908 ble 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640>
 *   @0x1a690c vldr s12, [sp, #40]
 *   @0x1a6910 vldr s15, [sp, #56]
 *   @0x1a6914 vldr s5, [sp, #44]
 *   @0x1a6918 vldr s8, [sp, #48]
 *   @0x1a691c vadd.f32 s14, s15, s5
 *   @0x1a6920 vldr s11, [sp, #52]
 *   @0x1a6924 vldr s7, [sp, #60]
 *   @0x1a6928 subs r7, r7, #1
 *   @0x1a692c vadd.f32 s13, s11, s12
 *   @0x1a6930 vadd.f32 s15, s7, s8
 *   @0x1a6934 vmul.f32 s13, s13, s31
 *   @0x1a6938 vmul.f32 s14, s14, s31
 *   @0x1a693c vstr s13, [sp, #40]
 *   @0x1a6940 vmul.f32 s15, s15, s31
 *   @0x1a6944 vstr s14, [sp, #44]
 *   @0x1a6948 vstr s15, [sp, #48]
 *   @0x1a694c beq 0x1a6794 <_ZN5CPath11HandlePieceEifffffffff+0x640>
 *   @0x1a6950 vmov.f32 s14, s29
 *   @0x1a6954 vldr s12, [sp, #36]
 *   @0x1a6958 vldr s15, [sp, #32]
 *   @0x1a695c vldr s11, [sp, #44]
 *   @0x1a6960 vldr s5, [sp, #40]
 *   @0x1a6964 vsub.f32 s13, s11, s14
 *   @0x1a6968 vldr s8, [sp, #48]
 *   @0x1a696c vldr s7, [sp, #44]
 *   @0x1a6970 vldr s9, [sp, #52]
 *   @0x1a6974 vmul.f32 s13, s13, s13
 *   @0x1a6978 vsub.f32 s11, s5, s15
 *   @0x1a697c vadd.f32 s25, s15, s5
 *   @0x1a6980 vadd.f32 s27, s12, s8
 *   @0x1a6984 vadd.f32 s26, s14, s7
 *   @0x1a6988 vmla.f32 s13, s11, s11
 *   @0x1a698c vadd.f32 s10, s5, s25
 *   @0x1a6990 vldr s5, [sp, #56]
 *   @0x1a6994 vadd.f32 s11, s8, s27
 *   @0x1a6998 vadd.f32 s29, s7, s26
 *   @0x1a699c vldr s7, [sp, #60]
 *   @0x1a69a0 vadd.f32 s10, s9, s10
 *   @0x1a69a4 vadd.f32 s11, s7, s11
 *   @0x1a69a8 vmul.f32 s10, s10, s28
 *   @0x1a69ac vmul.f32 s11, s11, s28
 *   @0x1a69b0 vstr s10, [sp, #32]
 *   @0x1a69b4 vadd.f32 s29, s5, s29
 *   @0x1a69b8 vstr s11, [sp, #36]
 *   @0x1a69bc vcmpe.f32 s13, s30
 *   @0x1a69c0 vmul.f32 s29, s29, s28
 *   @0x1a69c4 vmrs APSR_nzcv, fpscr
 *   @0x1a69c8 ble 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778>
 *   @0x1a69cc cmp r7, #1
 *   @0x1a69d0 vmul.f32 s25, s25, s31
 *   @0x1a69d4 vmul.f32 s26, s26, s31
 *   @0x1a69d8 vmul.f32 s27, s27, s31
 *   @0x1a69dc beq 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778>
 *   @0x1a69e0 sub r6, r7, #2
 *   @0x1a69e4 b 0x1a6a54 <_ZN5CPath11HandlePieceEifffffffff+0x900>
 *   @0x1a69e8 mov r0, r5
 *   @0x1a69ec vmov r1, s19
 *   @0x1a69f0 vmov r2, s20
 *   @0x1a69f4 vmov r3, s24
 *   @0x1a69f8 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a69fc vsub.f32 s15, s26, s29
 *   @0x1a6a00 vldr s8, [sp, #32]
 *   @0x1a6a04 vmul.f32 s15, s15, s15
 *   @0x1a6a08 vsub.f32 s14, s25, s8
 *   @0x1a6a0c vmla.f32 s15, s14, s14
 *   @0x1a6a10 vcmpe.f32 s15, s30
 *   @0x1a6a14 vmrs APSR_nzcv, fpscr
 *   @0x1a6a18 ble 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778>
 *   @0x1a6a1c vldr s9, [sp, #32]
 *   @0x1a6a20 vadd.f32 s26, s29, s26
 *   @0x1a6a24 vldr s10, [sp, #36]
 *   @0x1a6a28 cmp r6, #0
 *   @0x1a6a2c sub r6, r6, #1
 *   @0x1a6a30 vadd.f32 s25, s9, s25
 *   @0x1a6a34 vadd.f32 s27, s10, s27
 *   @0x1a6a38 vmul.f32 s25, s25, s31
 *   @0x1a6a3c vmul.f32 s26, s26, s31
 *   @0x1a6a40 vmul.f32 s27, s27, s31
 *   @0x1a6a44 beq 0x1a68cc <_ZN5CPath11HandlePieceEifffffffff+0x778>
 *   @0x1a6a48 vmov.f32 s12, s24
 *   @0x1a6a4c vmov.f32 s14, s20
 *   @0x1a6a50 vmov.f32 s15, s19
 *   @0x1a6a54 vldr s5, [sp, #32]
 *   @0x1a6a58 vldr s7, [sp, #36]
 *   @0x1a6a5c vsub.f32 s13, s26, s14
 *   @0x1a6a60 vmul.f32 s13, s13, s13
 *   @0x1a6a64 vsub.f32 s11, s25, s15
 *   @0x1a6a68 vadd.f32 s17, s15, s25
 *   @0x1a6a6c vadd.f32 s16, s14, s26
 *   @0x1a6a70 vadd.f32 s18, s12, s27
 *   @0x1a6a74 vmla.f32 s13, s11, s11
 *   @0x1a6a78 vadd.f32 s19, s25, s17
 *   @0x1a6a7c vadd.f32 s20, s26, s16
 *   @0x1a6a80 vadd.f32 s24, s27, s18
 *   @0x1a6a84 vadd.f32 s19, s5, s19
 *   @0x1a6a88 vadd.f32 s20, s29, s20
 *   @0x1a6a8c vadd.f32 s24, s7, s24
 *   @0x1a6a90 vcmpe.f32 s13, s30
 *   @0x1a6a94 vmul.f32 s19, s19, s28
 *   @0x1a6a98 vmrs APSR_nzcv, fpscr
 *   @0x1a6a9c vmul.f32 s20, s20, s28
 *   @0x1a6aa0 vmul.f32 s24, s24, s28
 *   @0x1a6aa4 ble 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894>
 *   @0x1a6aa8 cmp r6, #0
 *   @0x1a6aac mov r4, r6
 *   @0x1a6ab0 vmul.f32 s17, s17, s31
 *   @0x1a6ab4 vmul.f32 s16, s16, s31
 *   @0x1a6ab8 vmul.f32 s18, s18, s31
 *   @0x1a6abc bne 0x1a6b20 <_ZN5CPath11HandlePieceEifffffffff+0x9cc>
 *   @0x1a6ac0 b 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894>
 *   @0x1a6ac4 mov r0, r5
 *   @0x1a6ac8 vmov r1, s21
 *   @0x1a6acc vmov r2, s22
 *   @0x1a6ad0 vmov r3, s23
 *   @0x1a6ad4 bl 0x1a6068 <_ZN5CPath16AddInternalPointEfff>
 *   @0x1a6ad8 vsub.f32 s13, s16, s20
 *   @0x1a6adc vmul.f32 s13, s13, s13
 *   @0x1a6ae0 vsub.f32 s11, s17, s19
 *   @0x1a6ae4 vmla.f32 s13, s11, s11
 *   @0x1a6ae8 vcmpe.f32 s13, s30
 *   @0x1a6aec vmov.f32 s12, s23
 *   @0x1a6af0 vmrs APSR_nzcv, fpscr
 *   @0x1a6af4 vmov.f32 s14, s22
 *   @0x1a6af8 vmov.f32 s15, s21
 *   @0x1a6afc ble 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894>
 *   @0x1a6b00 subs r4, r4, #1
 *   @0x1a6b04 vadd.f32 s17, s19, s17
 *   @0x1a6b08 vadd.f32 s16, s20, s16
 *   @0x1a6b0c vadd.f32 s18, s24, s18
 *   @0x1a6b10 vmul.f32 s17, s17, s31
 *   @0x1a6b14 vmul.f32 s16, s16, s31
 *   @0x1a6b18 vmul.f32 s18, s18, s31
 *   @0x1a6b1c beq 0x1a69e8 <_ZN5CPath11HandlePieceEifffffffff+0x894>
 *   @0x1a6b20 vsub.f32 s13, s16, s14
 *   @0x1a6b24 vmul.f32 s13, s13, s13
 *   @0x1a6b28 vsub.f32 s11, s17, s15
 *   @0x1a6b2c vadd.f32 s8, s15, s17
 *   @0x1a6b30 vadd.f32 s9, s14, s16
 *   @0x1a6b34 vadd.f32 s10, s12, s18
 *   @0x1a6b38 vmla.f32 s13, s11, s11
 *   @0x1a6b3c vadd.f32 s21, s17, s8
 *   @0x1a6b40 vadd.f32 s22, s16, s9
 *   @0x1a6b44 vadd.f32 s23, s18, s10
 *   @0x1a6b48 vadd.f32 s21, s19, s21
 *   @0x1a6b4c vadd.f32 s22, s20, s22
 *   @0x1a6b50 vadd.f32 s23, s24, s23
 *   @0x1a6b54 vcmpe.f32 s13, s30
 *   @0x1a6b58 vmul.f32 s21, s21, s28
 *   @0x1a6b5c vmrs APSR_nzcv, fpscr
 *   @0x1a6b60 vmul.f32 s22, s22, s28
 *   @0x1a6b64 vmul.f32 s23, s23, s28
 *   @0x1a6b68 ble 0x1a6ac4 <_ZN5CPath11HandlePieceEifffffffff+0x970>
 *   @0x1a6b6c vstr s12, [sp]
 *   @0x1a6b70 vstr s21, [sp, #16]
 *   @0x1a6b74 vstr s22, [sp, #20]
 *   @0x1a6b78 mov r0, r5
 *   @0x1a6b7c sub r1, r4, #1
 *   @0x1a6b80 vmov r2, s15
 *   @0x1a6b84 vmov r3, s14
 *   @0x1a6b88 vstr s23, [sp, #24]
 *   @0x1a6b8c vmul.f32 s8, s8, s31
 *   @0x1a6b90 vmul.f32 s9, s9, s31
 *   @0x1a6b94 vstr s8, [sp, #4]
 *   @0x1a6b98 vmul.f32 s10, s10, s31
 *   @0x1a6b9c vstr s9, [sp, #8]
 *   @0x1a6ba0 vstr s10, [sp, #12]
 *   @0x1a6ba4 bl 0x1a6154 <_ZN5CPath11HandlePieceEifffffffff>
 *   @0x1a6ba8 b 0x1a6ac4 <_ZN5CPath11HandlePieceEifffffffff+0x970>
 *   @0x1a6bac add sp, sp, #196
 *   @0x1a6bb0 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x1a6bb4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §5/12 png_do_background  0x2a9680  size 2646  662 条（0x2a9680..0x2aa0d6）
 * @func 0x2a9680 0x2aa0d6  size 2646  662 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x50d84c / 0x15e7e98 / 0x1468a9c / 0x509b8e / 0x4ebd7e / 0xa89ca4 / 0x5e8db8 / 0x56c766
 * 字段偏移 top8: 0x2×20 / 0x8×12 / 0x1×12 / 0x4×12 / 0x3×10 / 0x6×7 / 0x-1×5 / 0x-2×5
 * VFP 指令 2 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a9680 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2a9684 sub sp, #0x1c
 *   @0x2a9688 ldr r4, [sp, #0x44]
 *   @0x2a968c ldr.w r10, [sp, #0x54]
 *   @0x2a9690 ldr.w r9, [sp, #0x58]
 *   @0x2a9694 ldr.w r11, [sp, #0x5c]
 *   @0x2a9698 ldr r0, [r0]
 *   @0x2a969c beq.w 0x2aa0d0 <png_do_background+0xa50>
 *   @0x2a96a0 ldr r7, [sp, #0xc]
 *   @0x2a96a4 lsls r7, r5, #0x1d
 *   @0x2a96a8 cmp r2, #0x0
 *   @0x2a96ac stchs p5, c8, [r6, #-68]
 *   @0x2a96b0 bhi.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a96b4 tbh [pc, r5, lsl #1]
 *   @0x2a96b8 movs r7, r0
 *   @0x2a96bc lsls r6, r0, #0x5
 *   @0x2a96c0 lsls r1, r6, #0x8
 *   @0x2a96c4 lsls r3, r2, #0xc
 *   @0x2a96c8 ldrb r5, [r6, #0x9]
 *   @0x2a96cc cmp r5, #0xf
 *   @0x2a96d0 ldm pc, {r1, r2, r5, r6, r7, r10, pc} ^
 *   @0x2a96d4 andseq pc, r0, r5, lsl r0
 *   @0x2a96d8 movs r0, r6
 *   @0x2a96dc lsls r3, r1, #0x2
 *   @0x2a96e0 lsls r4, r4, #0x13
 *   @0x2a96e4 lsls r7, r3, #0x3
 *   @0x2a96e8 lsls r4, r4, #0x13
 *   @0x2a96ec lsls r4, r4, #0x13
 *   @0x2a96f0 lsls r4, r4, #0x13
 *   @0x2a96f4 lsls r2, r7, #0x3
 *   @0x2a96f8 movs r5, #0x0
 *   @0x2a96fc addmi r7, r5, #32512
 *   @0x2a9700 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9704 ldrb r7, [r1]
 *   @0x2a9708 asr.w r8, r7, r4
 *   @0x2a970c and r8, r8, #0x1
 *   @0x2a9710 cmp r8, r6
 *   @0x2a9714 rsb.w r6, r4, #0x7
 *   @0x2a9718 asr.w r6, r12, r6
 *   @0x2a971c ands r6, r7
 *   @0x2a9720 ldrh r7, [r3, #0x8]
 *   @0x2a9724 orrs r6, r7
 *   @0x2a9728 cbnz r4, 0x2a9730 <png_do_background+0xb0>
 *   @0x2a972c movs r4, #0x7
 *   @0x2a9730 subs r4, #0x1
 *   @0x2a9734 b 0x2a96fe <png_do_background+0x7e>
 *   @0x2a9738 cbnz r4, 0x2a9740 <png_do_background+0xc0>
 *   @0x2a973c sub r7, pc, pc, lsr r12
 *   @0x2a9740 movs r7, #0x0
 *   @0x2a9744 addmi r7, r7, #4128768
 *   @0x2a9748 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a974c ldrb.w r12, [r1]
 *   @0x2a9750 ldrh.w r9, [r2, #0x8]
 *   @0x2a9754 asr.w r6, r12, r5
 *   @0x2a9758 and r6, r6, #0x3
 *   @0x2a975c cmp r6, r9
 *   @0x2a9760 .word 0xd10c0906
 *   @0x2a9764 asr.w r9, r8, r9
 *   @0x2a9768 and.w r12, r12, r9
 *   @0x2a976c strb.w r12, [r1]
 *   @0x2a9770 ldrh.w r9, [r3, #0x8]
 *   @0x2a9774 lsl.w r9, r9, r5
 *   @0x2a9778 orr.w r12, r12, r9
 *   @0x2a977c b 0x2a97a2 <png_do_background+0x122>
 *   @0x2a9780 asr.w r9, r8, r9
 *   @0x2a9784 and.w r12, r12, r9
 *   @0x2a9788 lsl.w r10, r6, #0x4
 *   @0x2a978c orr.w r10, r10, r6, lsl #2
 *   @0x2a9790 orr.w r10, r10, r6
 *   @0x2a9794 orr.w r6, r10, r6, lsl #6
 *   @0x2a9798 ldrb r6, [r4, r6]
 *   @0x2a979c lsls r6, r5
 *   @0x2a97a0 .word 0xf8810c0c
 *   @0x2a97a4 ldmdblt r5, {lr, pc}
 *   @0x2a97a8 adds r1, #0x1
 *   @0x2a97ac b 0x2a97b0 <png_do_background+0x130>
 *   @0x2a97b0 adds r7, #0x1
 *   @0x2a97b4 ldrb r7, [r1]
 *   @0x2a97b8 asr.w r8, r7, r5
 *   @0x2a97bc and r8, r8, #0x3
 *   @0x2a97c0 cmp r8, r6
 *   @0x2a97c4 rsb.w r6, r5, #0x6
 *   @0x2a97c8 asr.w r6, r12, r6
 *   @0x2a97cc ands r6, r7
 *   @0x2a97d0 ldrh r7, [r3, #0x8]
 *   @0x2a97d4 orrs r6, r7
 *   @0x2a97d8 cbnz r5, 0x2a97e8 <png_do_background+0x168>
 *   @0x2a97dc movs r5, #0x6
 *   @0x2a97e0 cmp r4, r0
 *   @0x2a97e4 b.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a97e8 subs r5, #0x2
 *   @0x2a97ec movs r5, #0x4
 *   @0x2a97f0 movw r12, #0xf0f
 *   @0x2a97f4 b 0x2a9888 <png_do_background+0x208>
 *   @0x2a97f8 movw r8, #0xf0f
 *   @0x2a97fc cmp r6, r0
 *   @0x2a9800 stmdavc pc, {r1, r2, r3, r6, r10, pc}
 *   @0x2a9804 ldrh.w r9, [r2, #0x8]
 *   @0x2a9808 asr.w r12, r7, r5
 *   @0x2a980c and r12, r12, #0xf
 *   @0x2a9810 cmp r12, r9
 *   @0x2a9814 mrsle r0, apsr
 *   @0x2a9818 asr.w r9, r8, r9
 *   @0x2a981c and.w r7, r7, r9
 *   @0x2a9820 strb r7, [r1]
 *   @0x2a9824 blx 0x50d84c <SrcVerts+0x6a890>
 *   @0x2a9828 b 0x14a7c44 <b2_toiTime+0xd4e7a0>
 *   @0x2a982c and r0, sp, r9, lsl #14
 *   @0x2a9830 orr.w r12, r12, r12, lsl #4
 *   @0x2a9834 asr.w r9, r8, r9
 *   @0x2a9838 and.w r7, r7, r9
 *   @0x2a983c ldrb.w r12, [r4, r12]
 *   @0x2a9840 lsr.w r12, r12, #0x4
 *   @0x2a9844 lsl.w r12, r12, r5
 *   @0x2a9848 orr.w r7, r12, r7
 *   @0x2a984c strb r7, [r1]
 *   @0x2a9850 adds r1, #0x1
 *   @0x2a9854 b 0x2a9858 <png_do_background+0x1d8>
 *   @0x2a9858 adds r6, #0x1
 *   @0x2a985c ldrb r7, [r1]
 *   @0x2a9860 asr.w r8, r7, r5
 *   @0x2a9864 and r8, r8, #0xf
 *   @0x2a9868 cmp r8, r6
 *   @0x2a986c rsb.w r6, r5, #0x4
 *   @0x2a9870 asr.w r6, r12, r6
 *   @0x2a9874 ands r6, r7
 *   @0x2a9878 ldrh r7, [r3, #0x8]
 *   @0x2a987c orrs r6, r7
 *   @0x2a9880 cbnz r5, 0x2a9890 <png_do_background+0x210>
 *   @0x2a9884 movs r5, #0x4
 *   @0x2a9888 cmp r4, r0
 *   @0x2a988c b.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9890 subs r5, #0x4
 *   @0x2a9894 adds r5, r1, r0
 *   @0x2a9898 cmp r1, r5
 *   @0x2a989c .word 0xf8118400
 *   @0x2a98a0 ldmdbhi r7, {r0, r8, r9, r11, sp, lr}
 *   @0x2a98a4 cmp r7, r6
 *   @0x2a98a8 ldrheq r6, [r3, #0x8]
 *   @0x2a98ac strb r6, [r1, #-1]
 *   @0x2a98b0 b 0x2a9898 <png_do_background+0x218>
 *   @0x2a98b4 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a98b8 ldrb r4, [r1], #1
 *   @0x2a98bc ldrh r6, [r2, #0x8]
 *   @0x2a98c0 itt eq
 *   @0x2a98c4 strbeq r4, [r1, #-1]
 *   @0x2a98c8 b 0x2a98b2 <png_do_background+0x232>
 *   @0x2a98cc adds r1, #0x2
 *   @0x2a98d0 movs r4, #0x0
 *   @0x2a98d4 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a98d8 ldrb r5, [r1, #-2]
 *   @0x2a98dc ldrb r6, [r1, #-1]
 *   @0x2a98e0 ldrh.w r12, [r2, #0x8]
 *   @0x2a98e4 add.w r7, r6, r5, lsl #8
 *   @0x2a98e8 uxth r7, r7
 *   @0x2a98ec bne 0x2a98fa <png_do_background+0x27a>
 *   @0x2a98f0 lsrs r5, r5, #0x8
 *   @0x2a98f4 ldmdbhi sp, {r1, r10, r11, r12, lr}
 *   @0x2a98f8 b 0x2a990e <png_do_background+0x28e>
 *   @0x2a98fc asr.w r6, r6, r11
 *   @0x2a9900 ldr.w r6, [r7, r6, lsl #2]
 *   @0x2a9904 ldrh.w r5, [r6, r5, lsl #1]
 *   @0x2a9908 lsrs r6, r5, #0x8
 *   @0x2a990c .word 0xf8016c02
 *   @0x2a9910 strlo r5, [r1], #-3073
 *   @0x2a9914 adds r1, #0x2
 *   @0x2a9918 ldrb r6, [r1, #-2]
 *   @0x2a991c ldrb r5, [r1, #-1]
 *   @0x2a9920 add.w r5, r5, r6, lsl #8
 *   @0x2a9924 ldrh r6, [r2, #0x8]
 *   @0x2a9928 cmp r6, r5
 *   @0x2a992c ldrh r5, [r3, #0x8]
 *   @0x2a9930 strb r5, [r1, #-2]
 *   @0x2a9934 ldrh r5, [r3, #0x8]
 *   @0x2a9938 strlo r5, [r1], #-3073
 *   @0x2a993c adds r1, #0x2
 *   @0x2a9940 bne 0x2a9918 <png_do_background+0x298>
 *   @0x2a9944 ldr r6, [sp, #0xc]
 *   @0x2a9948 cmp r5, #0x8
 *   @0x2a994c movs r6, #0x3
 *   @0x2a9950 mla r6, r6, r0, r1
 *   @0x2a9954 b 0x2a99b6 <png_do_background+0x336>
 *   @0x2a9958 stclne p7, c1, [sp], {0}
 *   @0x2a995c cmp r1, r7
 *   @0x2a9960 .word 0xf815839e
 *   @0x2a9964 rfeia r2!
 *   @0x2a9968 ldrmi r12, [r4, #0x2]!
 *   @0x2a996c bne 0x2a9994 <png_do_background+0x314>
 *   @0x2a9970 rfeia r2!
 *   @0x2a9974 strbmi r12, [r0, #0x4]!
 *   @0x2a9978 bne 0x2a9994 <png_do_background+0x314>
 *   @0x2a997c rfeia r2!
 *   @0x2a9980 strbmi r12, [r0, #0x6]!
 *   @0x2a9984 bne 0x2a9994 <png_do_background+0x314>
 *   @0x2a9988 strb r6, [r5, #-3]
 *   @0x2a998c ldrh r6, [r3, #0x4]
 *   @0x2a9990 ldrh r6, [r3, #0x6]
 *   @0x2a9994 ldrb r6, [r4, r6]
 *   @0x2a9998 stmdavc lr, {r0, r1, r10, r11, sp, lr} ^
 *   @0x2a999c ldrb r6, [r4, r6]
 *   @0x2a99a0 ldrb r6, [r1, #0x2]
 *   @0x2a99a4 strb r6, [r1, #0x2]
 *   @0x2a99a8 adds r1, #0x3
 *   @0x2a99ac ldrb r5, [r1]
 *   @0x2a99b0 cmp r5, r4
 *   @0x2a99b4 adds r1, #0x3
 *   @0x2a99b8 bne 0x2a99ac <png_do_background+0x32c>
 *   @0x2a99bc ldrb r5, [r1, #0x1]
 *   @0x2a99c0 cmp r5, r4
 *   @0x2a99c4 ldrb r5, [r1, #0x2]
 *   @0x2a99c8 cmp r5, r4
 *   @0x2a99cc ldrh r4, [r3, #0x2]
 *   @0x2a99d0 ldrh r4, [r3, #0x4]
 *   @0x2a99d4 ldrh r4, [r3, #0x6]
 *   @0x2a99d8 b 0x2a99b4 <png_do_background+0x334>
 *   @0x2a99dc cbnz r7, 0x2a99e2 <png_do_background+0x362>
 *   @0x2a99e0 b 0x2a9ada <png_do_background+0x45a>
 *   @0x2a99e4 movs r5, #0x0
 *   @0x2a99e8 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a99ec ldrb r8, [r4, #-6]
 *   @0x2a99f0 ldrb.w r10, [r1, #0x2]
 *   @0x2a99f4 ldrb.w r9, [r1, #0x1]
 *   @0x2a99f8 ldrb r6, [r1, #0x4]
 *   @0x2a99fc .word 0xf8cd2708
 *   @0x2a9a00 rfeia r2!
 *   @0x2a9a04 adcslt r10, pc, #2
 *   @0x2a9a08 str r6, [sp, #0x10]
 *   @0x2a9a0c ldrb.w r12, [r1, #0x3]
 *   @0x2a9a10 ldrb r6, [r1, #0x5]
 *   @0x2a9a14 ldr r7, [sp, #0x8]
 *   @0x2a9a18 strls r2, [r1, -r7, lsl #14]
 *   @0x2a9a1c ldr.w r10, [sp, #0x4]
 *   @0x2a9a20 ldrh r7, [r2, #0x4]
 *   @0x2a9a24 ldrbmi pc, [r7, #-0xa8a]
 *   @0x2a9a28 bne 0x2a9a60 <png_do_background+0x3e0>
 *   @0x2a9a2c ldmhi r7, {r4, sp, pc} ^
 *   @0x2a9a30 add.w r10, r6, r10, lsl #8
 *   @0x2a9a34 str.w r10, [sp, #0x4]
 *   @0x2a9a38 uxth.w r10, r10
 *   @0x2a9a3c cmp r7, r10
 *   @0x2a9a40 ldrh r6, [r3, #0x2]
 *   @0x2a9a44 strb r6, [r4, #-6]
 *   @0x2a9a48 ldrh r6, [r3, #0x2]
 *   @0x2a9a4c ldrh r6, [r3, #0x4]
 *   @0x2a9a50 strb r6, [r1, #0x2]
 *   @0x2a9a54 strb r6, [r1, #0x3]
 *   @0x2a9a58 lsrs r6, r6, #0x8
 *   @0x2a9a5c ldrh r6, [r3, #0x6]
 *   @0x2a9a60 ldr r7, [sp, #0x50]
 *   @0x2a9a64 blx 0x15e7e98 <b2_toiTime+0xe8e9f4>
 *   @0x2a9a68 blx 0x1468a9c <b2_toiTime+0xd0f5f8>
 *   @0x2a9a6c .word 0xf857f60b
 *   @0x2a9a70 rfeda r9!
 *   @0x2a9a74 b 0x1689adc <b2_toiTime+0xf30638>
 *   @0x2a9a78 .word 0xf8042918
 *   @0x2a9a7c .word 0xf8819c06
 *   @0x2a9a80 .word 0xf8578001
 *   @0x2a9a84 .word 0xf8ddc02c
 *   @0x2a9a88 rfeda r12!
 *   @0x2a9a8c .word 0xf8dd7018
 *   @0x2a9a90 sbcvc r8, pc, r0, lsl r0
 *   @0x2a9a94 lsr.w r12, r7, #0x8
 *   @0x2a9a98 ldr r7, [sp, #0x50]
 *   @0x2a9a9c .word 0xf857c002
 *   @0x2a9aa0 rfeda r6!
 *   @0x2a9aa4 beq 0x1081b0c <b2_toiTime+0x928668>
 *   @0x2a9aa8 strb r7, [r1, #0x4]
 *   @0x2a9aac adds r5, #0x1
 *   @0x2a9ab0 adds r4, #0x6
 *   @0x2a9ab4 ldrb.w r9, [r1]
 *   @0x2a9ab8 ldrb.w r8, [r1, #0x1]
 *   @0x2a9abc ldrb.w r12, [r1, #0x2]
 *   @0x2a9ac0 add.w r8, r8, r9, lsl #8
 *   @0x2a9ac4 ldrh.w r9, [r2, #0x2]
 *   @0x2a9ac8 ldrb r7, [r1, #0x3]
 *   @0x2a9acc stmdbvc lr, {r3, r7, r11, r12, sp, lr, pc}
 *   @0x2a9ad0 cmp r9, r8
 *   @0x2a9ad4 beq 0x2a9ae0 <png_do_background+0x460>
 *   @0x2a9ad8 adds r1, #0x6
 *   @0x2a9adc bne 0x2a9ab4 <png_do_background+0x434>
 *   @0x2a9ae0 add.w r7, r7, r12, lsl #8
 *   @0x2a9ae4 ldrh.w r12, [r2, #0x4]
 *   @0x2a9ae8 uxth r7, r7
 *   @0x2a9aec bne 0x2a9ad6 <png_do_background+0x456>
 *   @0x2a9af0 ldmhi r6, {r1, r2, r8, r10, sp} ^
 *   @0x2a9af4 uxth r5, r5
 *   @0x2a9af8 bne 0x2a9ad6 <png_do_background+0x456>
 *   @0x2a9afc lsrs r5, r5, #0x8
 *   @0x2a9b00 ldrh r5, [r3, #0x2]
 *   @0x2a9b04 ldrh r5, [r3, #0x4]
 *   @0x2a9b08 strb r5, [r1, #0x2]
 *   @0x2a9b0c strb r5, [r1, #0x3]
 *   @0x2a9b10 lsrs r5, r5, #0x8
 *   @0x2a9b14 ldrh r5, [r3, #0x6]
 *   @0x2a9b18 b 0x2a9ad6 <png_do_background+0x456>
 *   @0x2a9b1c ldrb r2, [r5, #0x9]
 *   @0x2a9b20 bne 0x2a9bd4 <png_do_background+0x554>
 *   @0x2a9b24 cbz r6, 0x2a9b2a <png_do_background+0x4aa>
 *   @0x2a9b28 cbnz r2, 0x2a9b30 <png_do_background+0x4b0>
 *   @0x2a9b2c movs r2, #0x0
 *   @0x2a9b30 cmp r4, #0x0
 *   @0x2a9b34 movs r2, #0x0
 *   @0x2a9b38 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9b3c ldrb r12, [r7, #-1]
 *   @0x2a9b40 cmp.w r12, #0xff
 *   @0x2a9b44 bne 0x2a9b50 <png_do_background+0x4d0>
 *   @0x2a9b48 .word 0xf814cc02
 *   @0x2a9b4c ands r12, lr, r12
 *   @0x2a9b50 cmp.w r12, #0x0
 *   @0x2a9b54 bne 0x2a9b5c <png_do_background+0x4dc>
 *   @0x2a9b58 ands r12, r8, r8
 *   @0x2a9b5c ldr r5, [sp, #0x40]
 *   @0x2a9b60 rfeia r5!
 *   @0x2a9b64 blx 0x509b8e <SrcVerts+0x66bd2>
 *   @0x2a9b68 .word 0xf817f808
 *   @0x2a9b6c .word 0xf8169c02
 *   @0x2a9b70 .word 0xf1089009
 *   @0x2a9b74 blx 0x4ebd7e <SrcVerts+0x48dc2>
 *   @0x2a9b78 .word 0xf8dd8c0c
 *   @0x2a9b7c blx 0xa89ca4 <b2_toiTime+0x330800>
 *   @0x2a9b80 bl 0x5e8db8 <g_SWFaavertbuff+0x15cf0>
 *   @0x2a9b84 .word 0xf3cc2c1c
 *   @0x2a9b88 .word 0xf8182c07
 *   @0x2a9b8c .word 0xf801c00c
 *   @0x2a9b90 strlo r12, [r2, -r2]
 *   @0x2a9b94 adds r2, #0x1
 *   @0x2a9b98 ldrb r5, [r4, #-1]
 *   @0x2a9b9c cmp r5, #0xff
 *   @0x2a9ba0 ldrb r5, [r4, #-2]
 *   @0x2a9ba4 strb r5, [r1, r2]
 *   @0x2a9ba8 adds r2, #0x1
 *   @0x2a9bac bne 0x2a9b98 <png_do_background+0x518>
 *   @0x2a9bb0 cbnz r5, 0x2a9bb6 <png_do_background+0x536>
 *   @0x2a9bb4 b 0x2a9ba4 <png_do_background+0x524>
 *   @0x2a9bb8 .word 0xf1c56c02
 *   @0x2a9bbc .word 0x436e0cff
 *   @0x2a9bc0 ldr r5, [sp, #0x40]
 *   @0x2a9bc4 adds r6, #0x80
 *   @0x2a9bc8 adclt r6, sp, #29360128
 *   @0x2a9bcc add.w r5, r5, r5, lsr #8
 *   @0x2a9bd0 asrs r5, r5, #0x8
 *   @0x2a9bd4 ldr r6, [sp, #0x50]
 *   @0x2a9bd8 cmp.w r10, #0x0
 *   @0x2a9bdc bne 0x2a9be8 <png_do_background+0x568>
 *   @0x2a9be0 movs r5, #0x0
 *   @0x2a9be4 ldrsh r7, [r8], #-111
 *   @0x2a9be8 cmp.w r9, #0x0
 *   @0x2a9bec beq 0x2a9bde <png_do_background+0x55e>
 *   @0x2a9bf0 movs r5, #0x0
 *   @0x2a9bf4 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9bf8 ldrb r7, [r1, #0x2]
 *   @0x2a9bfc add.w r4, r4, r7, lsl #8
 *   @0x2a9c00 movw r7, #0xffff
 *   @0x2a9c04 uxth r4, r4
 *   @0x2a9c08 bne 0x2a9c1e <png_do_background+0x59e>
 *   @0x2a9c0c ldr r6, [sp, #0x50]
 *   @0x2a9c10 asr.w r4, r4, r11
 *   @0x2a9c14 ldr.w r4, [r6, r4, lsl #2]
 *   @0x2a9c18 ldrh.w r4, [r4, r7, lsl #1]
 *   @0x2a9c1c b 0x2a9c70 <png_do_background+0x5f0>
 *   @0x2a9c20 ldrh r4, [r3, #0x8]
 *   @0x2a9c24 strb r4, [r2, #-2]
 *   @0x2a9c28 ldrh r4, [r3, #0x8]
 *   @0x2a9c2c ldr r6, [sp, #0x40]
 *   @0x2a9c30 .word 0x37ff477f
 *   @0x2a9c34 ldrb.w r8, [r1]
 *   @0x2a9c38 ldrh.w r12, [r6, #0x8]
 *   @0x2a9c3c mul r7, r12, r7
 *   @0x2a9c40 ldrb.w r12, [r1, #0x1]
 *   @0x2a9c44 asr.w r12, r12, r11
 *   @0x2a9c48 add.w r7, r7, #0x8000
 *   @0x2a9c4c ldr.w r12, [r9, r12, lsl #2]
 *   @0x2a9c50 ldrh.w r12, [r12, r8, lsl #1]
 *   @0x2a9c54 mla r4, r4, r12, r7
 *   @0x2a9c58 add.w r4, r4, r4, lsr #16
 *   @0x2a9c5c lsrs r4, r4, #0x10
 *   @0x2a9c60 beq 0xbe7e78 <b2_toiTime+0x48e9d4>
 *   @0x2a9c64 asr.w r8, r8, r11
 *   @0x2a9c68 ldr.w r7, [r10, r8, lsl #2]
 *   @0x2a9c6c ldrh.w r4, [r7, r4, lsl #1]
 *   @0x2a9c70 lsrs r7, r4, #0x8
 *   @0x2a9c74 .word 0xf8027c02
 *   @0x2a9c78 strlo r4, [r1, #-0xc01]
 *   @0x2a9c7c adds r1, #0x4
 *   @0x2a9c80 b 0x2a9bf2 <png_do_background+0x572>
 *   @0x2a9c84 ldrb r4, [r1, #0x3]
 *   @0x2a9c88 adclt r2, r4, #117440512
 *   @0x2a9c8c cmp r4, r6
 *   @0x2a9c90 ldrh r4, [r1]
 *   @0x2a9c94 adds r5, #0x1
 *   @0x2a9c98 adds r2, #0x2
 *   @0x2a9c9c bne 0x2a9c82 <png_do_background+0x602>
 *   @0x2a9ca0 cbnz r4, 0x2a9cac <png_do_background+0x62c>
 *   @0x2a9ca4 lsrs r4, r4, #0x8
 *   @0x2a9ca8 ldrh r4, [r3, #0x8]
 *   @0x2a9cac ldrb.w r12, [r1]
 *   @0x2a9cb0 ldrb r7, [r1, #0x1]
 *   @0x2a9cb4 adcslt r2, pc, #12, #14
 *   @0x2a9cb8 muls r7, r4, r7
 *   @0x2a9cbc .word 0xf104447f
 *   @0x2a9cc0 .word 0x9c1008ff
 *   @0x2a9cc4 add.w r7, r7, #0x8000
 *   @0x2a9cc8 ldrh.w r12, [r4, #0x8]
 *   @0x2a9ccc mla r4, r12, r8, r7
 *   @0x2a9cd0 add.w r4, r4, r4, lsr #16
 *   @0x2a9cd4 lsrs r4, r4, #0x10
 *   @0x2a9cd8 strb r7, [r2]
 *   @0x2a9cdc b 0x2a9c94 <png_do_background+0x614>
 *   @0x2a9ce0 ldrb r2, [r5, #0x9]
 *   @0x2a9ce4 bne.w 0x2a9e5e <png_do_background+0x7de>
 *   @0x2a9ce8 add.w r12, r1, #0x3
 *   @0x2a9cec cbz r6, 0x2a9cf2 <png_do_background+0x672>
 *   @0x2a9cf0 cbnz r7, 0x2a9d00 <png_do_background+0x680>
 *   @0x2a9cf4 strbtmi r0, [r5], -r3, lsl #16
 *   @0x2a9cf8 mla r8, r8, r0, r1
 *   @0x2a9cfc mov r2, r1
 *   @0x2a9d00 cmp r4, #0x0
 *   @0x2a9d04 mov.w r9, #0x3
 *   @0x2a9d08 mov r2, r1
 *   @0x2a9d0c strbmi r1, [r10, #-0x900]
 *   @0x2a9d10 beq.w 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9d14 ldrb r7, [r1, #0x3]
 *   @0x2a9d18 bne 0x2a9d2e <png_do_background+0x6ae>
 *   @0x2a9d1c ldrb r7, [r4, r7]
 *   @0x2a9d20 stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^
 *   @0x2a9d24 ldrb r7, [r4, r7]
 *   @0x2a9d28 ldrb r7, [r1, #0x2]
 *   @0x2a9d2c b 0x2a9dd4 <png_do_background+0x754>
 *   @0x2a9d30 ldrh r7, [r3, #0x2]
 *   @0x2a9d34 ldmhi pc, {r0, r1, r10, r11, r12, sp, lr}
 *   @0x2a9d38 strb r7, [r2, #0x1]
 *   @0x2a9d3c b 0x2a9dd4 <png_do_background+0x754>
 *   @0x2a9d40 rsb.w r8, r7, #0xff
 *   @0x2a9d44 ldrb.w r11, [r1]
 *   @0x2a9d48 uxth.w r8, r8
 *   @0x2a9d4c ldrh.w r10, [r5, #0x2]
 *   @0x2a9d50 ldrb.w r11, [r6, r11]
 *   @0x2a9d54 ldr r5, [sp, #0x48]
 *   @0x2a9d58 .word 0xf10afa08
 *   @0x2a9d5c blx 0x56c766 <g_SWFlineaavertbuff+0x1969e>
 *   @0x2a9d60 blx 0xa94584 <b2_toiTime+0x33b0e0>
 *   @0x2a9d64 bl 0x568794 <g_SWFlineaavertbuff+0x156cc>
 *   @0x2a9d68 vshll.u8 q9, d10, #0x2
 *   @0x2a9d6c .word 0xf8152a07
 *   @0x2a9d70 ldcls p0, c10, [r0, #-40]
 *   @0x2a9d74 strb r10, [r12, #-3]
 *   @0x2a9d78 ldrh.w r10, [r5, #0x4]
 *   @0x2a9d7c ldrb.w r11, [r1, #0x1]
 *   @0x2a9d80 ldr r5, [sp, #0x48]
 *   @0x2a9d84 .word 0xf816fa08
 *   @0x2a9d88 .word 0xf10ab00b
 *   @0x2a9d8c blx 0x56c796 <g_SWFlineaavertbuff+0x196ce>
 *   @0x2a9d90 blx 0xa945b4 <b2_toiTime+0x33b110>
 *   @0x2a9d94 bl 0x5687c4 <g_SWFlineaavertbuff+0x156fc>
 *   @0x2a9d98 vshll.u8 q9, d10, #0x2
 *   @0x2a9d9c .word 0xf8152a07
 *   @0x2a9da0 ldcls p0, c10, [r0, #-40]
 *   @0x2a9da4 strb.w r10, [r2, #0x1]
 *   @0x2a9da8 ldrh.w r10, [r5, #0x6]
 *   @0x2a9dac mul r8, r10, r8
 *   @0x2a9db0 ldrb.w r10, [r1, #0x2]
 *   @0x2a9db4 ldrb.w r10, [r6, r10]
 *   @0x2a9db8 add.w r8, r8, #0x80
 *   @0x2a9dbc mla r8, r10, r7, r8
 *   @0x2a9dc0 ldr.w r10, [sp, #0x48]
 *   @0x2a9dc4 uxth.w r8, r8
 *   @0x2a9dc8 add.w r8, r8, r8, lsr #8
 *   @0x2a9dcc ubfx r8, r8, #0x8, #0x8
 *   @0x2a9dd0 ldrb.w r7, [r10, r8]
 *   @0x2a9dd4 strb r7, [r2, #0x2]
 *   @0x2a9dd8 adds r2, #0x3
 *   @0x2a9ddc ldr r0, [r6, r3, lsl #24]
 *   @0x2a9de0 ldrb r4, [r1, #0x3]
 *   @0x2a9de4 bne 0x2a9e00 <png_do_background+0x780>
 *   @0x2a9de8 strb r4, [r5, #-3]
 *   @0x2a9dec ldrb r4, [r1, #0x1]
 *   @0x2a9df0 ldrb r4, [r1, #0x2]
 *   @0x2a9df4 adds r1, #0x4
 *   @0x2a9df8 adds r5, #0x3
 *   @0x2a9dfc bne 0x2a9de0 <png_do_background+0x760>
 *   @0x2a9e00 ldrh.w r12, [r3, #0x2]
 *   @0x2a9e04 cbnz r4, 0x2a9e12 <png_do_background+0x792>
 *   @0x2a9e08 ldmhi r12, {r0, r1, r10, r11, lr, pc}
 *   @0x2a9e0c strb r4, [r2, #0x1]
 *   @0x2a9e10 b 0x2a9df2 <png_do_background+0x772>
 *   @0x2a9e14 rsb.w r6, r4, #0xff
 *   @0x2a9e18 uxth r6, r6
 *   @0x2a9e1c adds r7, #0x80
 *   @0x2a9e20 adcslt r7, pc, #12, #14
 *   @0x2a9e24 add.w r7, r7, r7, lsr #8
 *   @0x2a9e28 asrs r7, r7, #0x8
 *   @0x2a9e2c stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^
 *   @0x2a9e30 ldrh.w r12, [r3, #0x4]
 *   @0x2a9e34 muls r7, r4, r7
 *   @0x2a9e38 mla r7, r6, r12, r7
 *   @0x2a9e3c uxth r7, r7
 *   @0x2a9e40 eorsne r2, pc, #6029312
 *   @0x2a9e44 strb r7, [r2, #0x1]
 *   @0x2a9e48 muls r4, r7, r4
 *   @0x2a9e4c adds r4, #0x80
 *   @0x2a9e50 adcslt r4, r6, #7340032
 *   @0x2a9e54 add.w r6, r6, r6, lsr #8
 *   @0x2a9e58 asrs r6, r6, #0x8
 *   @0x2a9e5c b 0x2a9df4 <png_do_background+0x774>
 *   @0x2a9e60 cbz r2, 0x2a9e68 <png_do_background+0x7e8>
 *   @0x2a9e64 .word 0xd1040f00
 *   @0x2a9e68 mov r2, r1
 *   @0x2a9e6c movw r12, #0xffff
 *   @0x2a9e70 b 0x2a9fec <png_do_background+0x96c>
 *   @0x2a9e74 rscsle r0, r7, r0, lsl #30
 *   @0x2a9e78 add.w r8, r1, #0x6
 *   @0x2a9e7c mov r2, r1
 *   @0x2a9e80 str r4, [sp, #0x14]
 *   @0x2a9e84 cmp r4, r0
 *   @0x2a9e88 stmibvc sp, {r1, r3, r8, pc}
 *   @0x2a9e8c ldrb r4, [r1, #0x7]
 *   @0x2a9e90 .word 0xf64f2405
 *   @0x2a9e94 adclt r7, r4, #1069547520
 *   @0x2a9e98 cmp r4, r5
 *   @0x2a9e9c ldrb r4, [r1, #0x1]
 *   @0x2a9ea0 ldrb r5, [r1]
 *   @0x2a9ea4 .word 0xf856f40b
 *   @0x2a9ea8 rfeda r4!
 *   @0x2a9eac beq 0xbf9f08 <b2_toiTime+0x4a0a64>
 *   @0x2a9eb0 strb r5, [r8, #-6]
 *   @0x2a9eb4 strb r4, [r2, #0x1]
 *   @0x2a9eb8 ldrb r5, [r1, #0x2]
 *   @0x2a9ebc .word 0xf856f40b
 *   @0x2a9ec0 rfeda r4!
 *   @0x2a9ec4 sbcsvc r4, r4, r5, lsl r0
 *   @0x2a9ec8 lsrs r5, r4, #0x8
 *   @0x2a9ecc ldrb r4, [r1, #0x5]
 *   @0x2a9ed0 asr.w r4, r4, r11
 *   @0x2a9ed4 ldr.w r4, [r6, r4, lsl #2]
 *   @0x2a9ed8 ldrh.w r4, [r4, r5, lsl #1]
 *   @0x2a9edc b 0x2a9fb4 <png_do_background+0x934>
 *   @0x2a9ee0 ldrh r4, [r3, #0x2]
 *   @0x2a9ee4 strb r4, [r8, #-6]
 *   @0x2a9ee8 ldrh r4, [r3, #0x2]
 *   @0x2a9eec ldrh r4, [r3, #0x4]
 *   @0x2a9ef0 strb r4, [r2, #0x2]
 *   @0x2a9ef4 strb r4, [r2, #0x3]
 *   @0x2a9ef8 lsrs r4, r4, #0x8
 *   @0x2a9efc ldrh r4, [r3, #0x6]
 *   @0x2a9f00 ldr r7, [sp, #0x40]
 *   @0x2a9f04 ldrblo r4, [pc, #0x57f]!
 *   @0x2a9f08 ldrb.w r12, [r1]
 *   @0x2a9f0c ldrh r6, [r7, #0x2]
 *   @0x2a9f10 muls r6, r5, r6
 *   @0x2a9f14 .word 0xf859f70b
 *   @0x2a9f18 .word 0xf5067027
 *   @0x2a9f1c rfeda r7!
 *   @0x2a9f20 blx 0x3c5f9a <error_g0017+0x1ec3e>
 *   @0x2a9f24 bl 0x443748 <g_RomDisk+0x4bf28>
 *   @0x2a9f28 ldceq p6, c4, [r6], #-88
 *   @0x2a9f2c uxtb r7, r6
 *   @0x2a9f30 asr.w r7, r7, r11
 *   @0x2a9f34 ldr.w r7, [r10, r7, lsl #2]
 *   @0x2a9f38 ldrh.w r6, [r7, r6, lsl #1]
 *   @0x2a9f3c lsrs r7, r6, #0x8
 *   @0x2a9f40 svcls #0x107c06
 *   @0x2a9f44 strb r6, [r2, #0x1]
 *   @0x2a9f48 ldmhi lr!, {r1, lr, pc}
 *   @0x2a9f4c ldrb r7, [r1, #0x3]
 *   @0x2a9f50 asr.w r7, r7, r11
 *   @0x2a9f54 ldr.w r7, [r9, r7, lsl #2]
 *   @0x2a9f58 add.w r6, r6, #0x8000
 *   @0x2a9f5c ldrh.w r7, [r7, r12, lsl #1]
 *   @0x2a9f60 mla r6, r4, r7, r6
 *   @0x2a9f64 add.w r6, r6, r6, lsr #16
 *   @0x2a9f68 lsrs r6, r6, #0x10
 *   @0x2a9f6c lsrs r6, r6, #0x8
 *   @0x2a9f70 .word 0xf85af70b
 *   @0x2a9f74 rfeda r7!
 *   @0x2a9f78 beq 0x1081fd8 <b2_toiTime+0x928b34>
 *   @0x2a9f7c strb r7, [r2, #0x2]
 *   @0x2a9f80 strb r6, [r2, #0x3]
 *   @0x2a9f84 ldrb r7, [r1, #0x4]
 *   @0x2a9f88 ldrb r6, [r1, #0x5]
 *   @0x2a9f8c .word 0xf505f60b
 *   @0x2a9f90 .word 0xf8594500
 *   @0x2a9f94 rfeda r6!
 *   @0x2a9f98 blx 0x3c1ffe <error_g0017+0x1aca2>
 *   @0x2a9f9c bl 0x3befbc <error_g0017+0x17c60>
 *   @0x2a9fa0 stceq p4, c4, [r4], #-80
 *   @0x2a9fa4 uxtb r7, r4
 *   @0x2a9fa8 asr.w r7, r7, r11
 *   @0x2a9fac ldr.w r5, [r10, r7, lsl #2]
 *   @0x2a9fb0 ldrh.w r4, [r5, r4, lsl #1]
 *   @0x2a9fb4 lsrs r5, r4, #0x8
 *   @0x2a9fb8 ldr.w r12, [sp, #0x14]
 *   @0x2a9fbc adds r1, #0x8
 *   @0x2a9fc0 add.w r8, r8, #0x6
 *   @0x2a9fc4 add.w r12, r12, #0x1
 *   @0x2a9fc8 adds r2, #0x6
 *   @0x2a9fcc smmla r8, r4, r0, r12
 *   @0x2a9fd0 ldrb r6, [r1, #0x6]
 *   @0x2a9fd4 add.w r4, r4, r6, lsl #8
 *   @0x2a9fd8 uxth r4, r4
 *   @0x2a9fdc bne 0x2a9ff2 <png_do_background+0x972>
 *   @0x2a9fe0 str r4, [r2]
 *   @0x2a9fe4 strh r4, [r2, #0x4]
 *   @0x2a9fe8 adds r1, #0x8
 *   @0x2a9fec cmp r5, r0
 *   @0x2a9ff0 b 0x2aa09e <png_do_background+0xa1e>
 *   @0x2a9ff4 cbnz r4, 0x2aa014 <png_do_background+0x994>
 *   @0x2a9ff8 strb r7, [r2]
 *   @0x2a9ffc strb r4, [r2, #0x1]
 *   @0x2aa000 lsrs r4, r4, #0x8
 *   @0x2aa004 ldrh r4, [r3, #0x4]
 *   @0x2aa008 ldrh r4, [r3, #0x6]
 *   @0x2aa00c strb r4, [r2, #0x4]
 *   @0x2aa010 strb r4, [r2, #0x5]
 *   @0x2aa014 ldrb.w r11, [r1]
 *   @0x2aa018 ldrb.w r10, [r1, #0x1]
 *   @0x2aa01c ldrb.w r9, [r1, #0x2]
 *   @0x2aa020 add.w r10, r10, r11, lsl #8
 *   @0x2aa024 ldrb r6, [r1, #0x3]
 *   @0x2aa028 blx 0xa8a040 <b2_toiTime+0x330b9c>
 *   @0x2aa02c bl 0x468a5c <g_RomDisk+0x7123c>
 *   @0x2aa030 stmdbvc lr, {r0, r3, r8, r11, sp} ^
 *   @0x2aa034 mul r10, r10, r4
 *   @0x2aa038 add.w r8, r6, r8, lsl #8
 *   @0x2aa03c rsb.w r6, r4, #0xff00
 *   @0x2aa040 uxth.w r9, r9
 *   @0x2aa044 adds r6, #0xff
 *   @0x2aa048 .word 0xf50af888
 *   @0x2aa04c blx 0x3bc856 <error_g0017+0x154fa>
 *   @0x2aa050 blx 0x4a847e <SrcVerts+0x54c2>
 *   @0x2aa054 .word 0xf509a706
 *   @0x2aa058 blx 0x3bc462 <error_g0017+0x15106>
 *   @0x2aa05c bl 0x4a7084 <SrcVerts+0x40c8>
 *   @0x2aa060 .word 0xf5044717
 *   @0x2aa064 ldceq p4, c4, [pc], #-0
 *   @0x2aa068 strb r7, [r2, #0x1]
 *   @0x2aa06c .word 0xf8822a17
 *   @0x2aa070 ldmhi pc, {sp, pc}
 *   @0x2aa074 mla r7, r7, r6, r9
 *   @0x2aa078 add.w r7, r7, r7, lsr #16
 *   @0x2aa07c lsrs r7, r7, #0x10
 *   @0x2aa080 lsr.w r9, r7, #0x8
 *   @0x2aa084 strb.w r9, [r2, #0x2]
 *   @0x2aa088 ldrh.w r8, [r3, #0x6]
 *   @0x2aa08c mla r6, r8, r6, r4
 *   @0x2aa090 add.w r6, r6, r6, lsr #16
 *   @0x2aa094 lsrs r6, r6, #0x10
 *   @0x2aa098 lsrs r4, r6, #0x8
 *   @0x2aa09c b 0x2a9fe6 <png_do_background+0x966>
 *   @0x2aa0a0 ldrb r3, [r5, #0x8]
 *   @0x2aa0a4 bpl 0x2aa0d0 <png_do_background+0xa50>
 *   @0x2aa0a8 eorvc r0, r11, #4, #6
 *   @0x2aa0ac ldrb r3, [r5, #0xa]
 *   @0x2aa0b0 subs r3, #0x1
 *   @0x2aa0b4 strb r3, [r5, #0xa]
 *   @0x2aa0b8 uxtb r3, r3
 *   @0x2aa0bc cmp r3, #0x7
 *   @0x2aa0c0 lsrs r3, r3, #0x3
 *   @0x2aa0c4 b 0x2aa0cc <png_do_background+0xa4c>
 *   @0x2aa0c8 adds r0, #0x7
 *   @0x2aa0cc ldr r6, [sp, #0xc]
 *   @0x2aa0d0 add sp, #0x1c
 *   @0x2aa0d4 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ §6/12 Option_Load(unsigned char*, unsigned int, unsigned char*)  0x19f534  size 2616  654 条（0x19f534..0x19ff6c）
 * @func 0x19f534 0x19ff6c  size 2616  654 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x19f554→0x5423c0, 0x19f560→0x757f10, 0x19f588→0x5423bf, 0x19f590→0x755314, 0x19f5a0→0x5423be, 0x19f5b4→0x3f5080, 0x19f5cc→0x3f507c, 0x19f5e4→0x5423bd
 * 调用序列: 0xb6574×6 / MemoryManager::SetLength(void**, unsigned int, char const*, int)×4 / 0xb66b8×3 / GR_Window_Set_Color(unsigned int)×2 / YYStrDup(char const*)×2 / Option_Load(unsigned char*, unsigned int, unsigned char*)+0x61c / Option_Load(unsigned char*, unsigned int, unsigned char*)+0x934 / 0xb697c
 * 字段偏移 top8: 0x8×11 / 0xc×11 / 0x4×8 / 0x1c×5 / 0x2×5 / 0x10×4 / 0x14×4 / 0x18×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x19f534 ldr r3, [r0]
 *   @0x19f538 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x19f53c cmp r3, #0
 *   @0x19f540 ldr r10, [pc, #0x940]
 *   @0x19f544 sub sp, sp, #36
 *   @0x19f548 mov r4, r0
 *   @0x19f54c add r10, pc, r10
 *   @0x19f550 blt 0x19fb50 <_Z11Option_LoadPhjS_+0x61c>
 *   @0x19f554 ldr r3, [pc, #0x930]
 *   @0x19f558 moveq r1, #0
 *   @0x19f55c movne r1, #1
 *   @0x19f560 ldr r2, [pc, #0x928]
 *   @0x19f564 ldr r0, [r0, #0x4]
 *   @0x19f568 ldr r3, [r10, r3]
 *   @0x19f56c ldr lr, [r4, #0x8]
 *   @0x19f570 strb r1, [r3]
 *   @0x19f574 ldr r2, [r10, r2]
 *   @0x19f578 ldrb r2, [r2]
 *   @0x19f57c cmp r2, #0
 *   @0x19f580 movne r2, #0
 *   @0x19f584 strbne r2, [r3]
 *   @0x19f588 ldr r3, [pc, #0x904]
 *   @0x19f58c adds r0, r0, #0
 *   @0x19f590 ldr r2, [pc, #0x900]
 *   @0x19f594 movne r0, #1
 *   @0x19f598 adds lr, lr, #0
 *   @0x19f59c ldr r1, [r10, r3]
 *   @0x19f5a0 ldr r3, [pc, #0x8f4]
 *   @0x19f5a4 movne lr, #1
 *   @0x19f5a8 strb r0, [r1]
 *   @0x19f5ac ldr r1, [r10, r2]
 *   @0x19f5b0 ldr r0, [r4, #0xc]
 *   @0x19f5b4 ldr r2, [pc, #0x8e4]
 *   @0x19f5b8 strb lr, [r1]
 *   @0x19f5bc adds r0, r0, #0
 *   @0x19f5c0 ldr r1, [r10, r3]
 *   @0x19f5c4 ldr lr, [r4, #0x10]
 *   @0x19f5c8 movne r0, #1
 *   @0x19f5cc ldr r3, [pc, #0x8d0]
 *   @0x19f5d0 strb r0, [r1]
 *   @0x19f5d4 adds lr, lr, #0
 *   @0x19f5d8 ldr r1, [r10, r2]
 *   @0x19f5dc movne lr, #1
 *   @0x19f5e0 ldr r0, [r4, #0x14]
 *   @0x19f5e4 ldr r2, [pc, #0x8bc]
 *   @0x19f5e8 strb lr, [r1]
 *   @0x19f5ec ldr r1, [r10, r3]
 *   @0x19f5f0 ldr lr, [r4, #0x18]
 *   @0x19f5f4 ldr r3, [pc, #0x8b0]
 *   @0x19f5f8 str r0, [r1]
 *   @0x19f5fc adds lr, lr, #0
 *   @0x19f600 ldr r1, [r10, r2]
 *   @0x19f604 ldr r0, [r4, #0x1c]
 *   @0x19f608 movne lr, #1
 *   @0x19f60c ldr r2, [pc, #0x89c]
 *   @0x19f610 strb lr, [r1]
 *   @0x19f614 adds r0, r0, #0
 *   @0x19f618 ldr r1, [r10, r3]
 *   @0x19f61c ldr r3, [r4, #0x20]
 *   @0x19f620 movne r0, #1
 *   @0x19f624 strb r0, [r1]
 *   @0x19f628 ldr r2, [r10, r2]
 *   @0x19f62c mov r0, r3
 *   @0x19f630 str r3, [r2]
 *   @0x19f634 bl 0x17ae08 <_Z19GR_Window_Set_Colorj>
 *   @0x19f638 ldr r1, [pc, #0x874]
 *   @0x19f63c mov r3, #0
 *   @0x19f640 ldr lr, [r4, #0x24]
 *   @0x19f644 ldr r2, [pc, #0x86c]
 *   @0x19f648 ldr r0, [r10, r1]
 *   @0x19f64c subs lr, lr, r3
 *   @0x19f650 ldr r5, [r4, #0x28]
 *   @0x19f654 movne lr, #1
 *   @0x19f658 ldr r1, [pc, #0x85c]
 *   @0x19f65c strb lr, [r0]
 *   @0x19f660 ldr r0, [r10, r2]
 *   @0x19f664 ldr lr, [r4, #0x2c]
 *   @0x19f668 ldr r2, [pc, #0x850]
 *   @0x19f66c str r5, [r0]
 *   @0x19f670 ldr r0, [r10, r1]
 *   @0x19f674 ldr r5, [r4, #0x30]
 *   @0x19f678 ldr r1, [pc, #0x844]
 *   @0x19f67c str lr, [r0]
 *   @0x19f680 ldr r0, [r10, r2]
 *   @0x19f684 ldr lr, [r4, #0x34]
 *   @0x19f688 ldr r2, [pc, #0x838]
 *   @0x19f68c str r5, [r0]
 *   @0x19f690 subs lr, lr, r3
 *   @0x19f694 ldr r0, [r10, r1]
 *   @0x19f698 movne lr, #1
 *   @0x19f69c ldr r5, [r4, #0x38]
 *   @0x19f6a0 ldr r1, [pc, #0x824]
 *   @0x19f6a4 strb lr, [r0]
 *   @0x19f6a8 ldr r0, [r10, r2]
 *   @0x19f6ac ldr lr, [r4, #0x3c]
 *   @0x19f6b0 ldr r2, [pc, #0x818]
 *   @0x19f6b4 str r5, [r0]
 *   @0x19f6b8 subs lr, lr, r3
 *   @0x19f6bc ldr r0, [r10, r1]
 *   @0x19f6c0 ldr r5, [r4, #0x40]
 *   @0x19f6c4 movne lr, #1
 *   @0x19f6c8 ldr r1, [pc, #0x804]
 *   @0x19f6cc strb lr, [r0]
 *   @0x19f6d0 subs r5, r5, r3
 *   @0x19f6d4 ldr r0, [r10, r2]
 *   @0x19f6d8 ldr lr, [r4, #0x44]
 *   @0x19f6dc movne r5, #1
 *   @0x19f6e0 ldr r2, [pc, #0x7f0]
 *   @0x19f6e4 strb r5, [r0]
 *   @0x19f6e8 subs lr, lr, r3
 *   @0x19f6ec ldr r0, [r10, r1]
 *   @0x19f6f0 ldr r5, [r4, #0x48]
 *   @0x19f6f4 movne lr, #1
 *   @0x19f6f8 ldr r1, [pc, #0x7dc]
 *   @0x19f6fc strb lr, [r0]
 *   @0x19f700 subs r5, r5, r3
 *   @0x19f704 ldr r0, [r10, r2]
 *   @0x19f708 ldr lr, [r4, #0x4c]
 *   @0x19f70c movne r5, #1
 *   @0x19f710 ldr r2, [pc, #0x7c8]
 *   @0x19f714 strb r5, [r0]
 *   @0x19f718 subs lr, lr, r3
 *   @0x19f71c ldr r1, [r10, r1]
 *   @0x19f720 ldr r5, [r4, #0x50]
 *   @0x19f724 movne lr, #1
 *   @0x19f728 ldr r0, [pc, #0x7b4]
 *   @0x19f72c strb lr, [r1]
 *   @0x19f730 subs r5, r5, r3
 *   @0x19f734 ldr lr, [r10, r2]
 *   @0x19f738 movne r5, #1
 *   @0x19f73c ldr r1, [pc, #0x7a4]
 *   @0x19f740 ldr r6, [r4, #0x58]
 *   @0x19f744 strb r5, [lr]
 *   @0x19f748 ldr r5, [r4, #0x54]
 *   @0x19f74c subs r6, r6, r3
 *   @0x19f750 ldr lr, [r10, r0]
 *   @0x19f754 ldr r2, [pc, #0x790]
 *   @0x19f758 movne r6, #1
 *   @0x19f75c ldr r0, [pc, #0x78c]
 *   @0x19f760 str r5, [lr]
 *   @0x19f764 ldr r5, [r10, r1]
 *   @0x19f768 ldr r1, [pc, #0x784]
 *   @0x19f76c ldr lr, [pc, #0x784]
 *   @0x19f770 strb r6, [r5]
 *   @0x19f774 ldr r5, [r10, r2]
 *   @0x19f778 ldr r6, [r4, #0x5c]
 *   @0x19f77c ldr r2, [pc, #0x778]
 *   @0x19f780 strb r3, [r5]
 *   @0x19f784 subs r6, r6, r3
 *   @0x19f788 ldr r7, [r10, r0]
 *   @0x19f78c movne r6, #1
 *   @0x19f790 ldr r0, [pc, #0x768]
 *   @0x19f794 ldr r5, [r4, #0x68]
 *   @0x19f798 strb r3, [r7]
 *   @0x19f79c ldr r3, [r10, r1]
 *   @0x19f7a0 ldr r7, [r4, #0x6c]
 *   @0x19f7a4 ldr r1, [pc, #0x758]
 *   @0x19f7a8 strb r6, [r3]
 *   @0x19f7ac adds r7, r7, #0
 *   @0x19f7b0 ldr r6, [r10, lr]
 *   @0x19f7b4 ldr r3, [r10, r2]
 *   @0x19f7b8 movne r7, #1
 *   @0x19f7bc ldr lr, [r4, #0x70]
 *   @0x19f7c0 ldr r8, [r6]
 *   @0x19f7c4 ldr r2, [pc, #0x73c]
 *   @0x19f7c8 adds lr, lr, #0
 *   @0x19f7cc add r5, r8, r5
 *   @0x19f7d0 str r5, [r3]
 *   @0x19f7d4 ldr r0, [r10, r0]
 *   @0x19f7d8 movne lr, #1
 *   @0x19f7dc ldr r5, [r4, #0x74]
 *   @0x19f7e0 ldr r3, [pc, #0x724]
 *   @0x19f7e4 strb r7, [r0]
 *   @0x19f7e8 adds r5, r5, #0
 *   @0x19f7ec ldr r1, [r10, r1]
 *   @0x19f7f0 ldr r7, [r4, #0x7c]
 *   @0x19f7f4 movne r5, #1
 *   @0x19f7f8 ldr r0, [pc, #0x710]
 *   @0x19f7fc str lr, [r1]
 *   @0x19f800 adds r7, r7, #0
 *   @0x19f804 ldr r1, [r10, r2]
 *   @0x19f808 ldr lr, [r4, #0x80]
 *   @0x19f80c movne r7, #1
 *   @0x19f810 ldr r2, [pc, #0x6fc]
 *   @0x19f814 strb r5, [r1]
 *   @0x19f818 adds lr, lr, #0
 *   @0x19f81c ldr r5, [r10, r3]
 *   @0x19f820 ldr r1, [r4, #0x84]
 *   @0x19f824 movne lr, #1
 *   @0x19f828 ldr r3, [pc, #0x6e8]
 *   @0x19f82c strb r7, [r5]
 *   @0x19f830 adds r1, r1, #0
 *   @0x19f834 ldr r0, [r10, r0]
 *   @0x19f838 movne r1, #1
 *   @0x19f83c strb lr, [r0]
 *   @0x19f840 ldr r2, [r10, r2]
 *   @0x19f844 strb r1, [r2]
 *   @0x19f848 ldr r3, [r10, r3]
 *   @0x19f84c ldr r3, [r3]
 *   @0x19f850 cmp r3, #4
 *   @0x19f854 bgt 0x19fadc <_Z11Option_LoadPhjS_+0x5a8>
 *   @0x19f858 ldr r3, [pc, #0x6bc]
 *   @0x19f85c adds r11, r4, #144
 *   @0x19f860 ldr r9, [r4, #0x8c]
 *   @0x19f864 ldr r8, [r10, r3]
 *   @0x19f868 str r9, [r8]
 *   @0x19f86c beq 0x19fe28 <_Z11Option_LoadPhjS_+0x8f4>
 *   @0x19f870 cmp r9, #0
 *   @0x19f874 ble 0x19fe68 <_Z11Option_LoadPhjS_+0x934>
 *   @0x19f878 add r11, r11, #8
 *   @0x19f87c ldr r12, [pc, #0x69c]
 *   @0x19f880 str r11, [sp, #0xc]
 *   @0x19f884 mov r5, #0
 *   @0x19f888 ldr r11, [pc, #0x694]
 *   @0x19f88c add r12, pc, r12
 *   @0x19f890 ldr r4, [sp, #0xc]
 *   @0x19f894 add r11, pc, r11
 *   @0x19f898 str r12, [sp, #0x8]
 *   @0x19f89c str r11, [sp, #0x4]
 *   @0x19f8a0 b 0x19f8c8 <_Z11Option_LoadPhjS_+0x394>
 *   @0x19f8a4 ldr r1, [sp, #0x8]
 *   @0x19f8a8 mov r0, r11
 *   @0x19f8ac bl 0xb6574 <strcmp@plt>
 *   @0x19f8b0 subs r1, r0, #0
 *   @0x19f8b4 beq 0x19faa8 <_Z11Option_LoadPhjS_+0x574>
 *   @0x19f8b8 add r5, r5, #1
 *   @0x19f8bc add r4, r4, #8
 *   @0x19f8c0 cmp r5, r9
 *   @0x19f8c4 beq 0x19f930 <_Z11Option_LoadPhjS_+0x3fc>
 *   @0x19f8c8 ldr r0, [r4, #-0x8]
 *   @0x19f8cc ldr r7, [r4, #-0x4]
 *   @0x19f8d0 cmp r0, #0
 *   @0x19f8d4 ldr r1, [sp, #0x4]
 *   @0x19f8d8 ldrne r3, [r6]
 *   @0x19f8dc moveq r11, r0
 *   @0x19f8e0 addne r11, r3, r0
 *   @0x19f8e4 cmp r7, #0
 *   @0x19f8e8 ldrne r2, [r6]
 *   @0x19f8ec mov r0, r11
 *   @0x19f8f0 addne r7, r2, r7
 *   @0x19f8f4 bl 0xb6574 <strcmp@plt>
 *   @0x19f8f8 cmp r0, #0
 *   @0x19f8fc bne 0x19f8a4 <_Z11Option_LoadPhjS_+0x370>
 *   @0x19f900 mov r0, r7
 *   @0x19f904 add r5, r5, #1
 *   @0x19f908 bl 0xb66b8 <atoi@plt>
 *   @0x19f90c ldr r3, [pc, #0x614]
 *   @0x19f910 ldr r2, [r8]
 *   @0x19f914 cmp r5, r9
 *   @0x19f918 add r4, r4, #8
 *   @0x19f91c ldr r3, [r10, r3]
 *   @0x19f920 sub r2, r2, #1
 *   @0x19f924 str r2, [r8]
 *   @0x19f928 str r0, [r3]
 *   @0x19f92c bne 0x19f8c8 <_Z11Option_LoadPhjS_+0x394>
 *   @0x19f930 ldr r2, [pc, #0x5f4]
 *   @0x19f934 mov r3, #352
 *   @0x19f938 ldr r7, [pc, #0x5f0]
 *   @0x19f93c mov r5, #0
 *   @0x19f940 ldr r1, [r8]
 *   @0x19f944 mov r4, r5
 *   @0x19f948 ldr r2, [r10, r2]
 *   @0x19f94c add r7, pc, r7
 *   @0x19f950 ldr r12, [pc, #0x5dc]
 *   @0x19f954 lsl r1, r1, #2
 *   @0x19f958 ldr r11, [sp, #0xc]
 *   @0x19f95c str r2, [sp, #0x8]
 *   @0x19f960 mov r2, r7
 *   @0x19f964 ldr r0, [sp, #0x8]
 *   @0x19f968 add r12, pc, r12
 *   @0x19f96c str r12, [sp]
 *   @0x19f970 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19f974 ldr r0, [pc, #0x5bc]
 *   @0x19f978 movw r3, #0x161
 *   @0x19f97c ldr lr, [pc, #0x5b8]
 *   @0x19f980 mov r2, r7
 *   @0x19f984 ldr r1, [r8]
 *   @0x19f988 add lr, pc, lr
 *   @0x19f98c str lr, [sp, #0x4]
 *   @0x19f990 ldr r0, [r10, r0]
 *   @0x19f994 lsl r1, r1, #2
 *   @0x19f998 str r0, [sp, #0xc]
 *   @0x19f99c ldr r0, [pc, #0x59c]
 *   @0x19f9a0 add r0, pc, r0
 *   @0x19f9a4 str r0, [sp, #0x10]
 *   @0x19f9a8 ldr r0, [sp, #0xc]
 *   @0x19f9ac bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19f9b0 ldr r12, [sp]
 *   @0x19f9b4 ldr r3, [pc, #0x588]
 *   @0x19f9b8 str r10, [sp, #0x1c]
 *   @0x19f9bc add r3, pc, r3
 *   @0x19f9c0 mov r10, r12
 *   @0x19f9c4 str r3, [sp, #0x14]
 *   @0x19f9c8 b 0x19f9dc <_Z11Option_LoadPhjS_+0x4a8>
 *   @0x19f9cc add r4, r4, #1
 *   @0x19f9d0 add r11, r11, #8
 *   @0x19f9d4 cmp r4, r9
 *   @0x19f9d8 beq 0x19fa9c <_Z11Option_LoadPhjS_+0x568>
 *   @0x19f9dc ldr r7, [r11, #-0x8]
 *   @0x19f9e0 mov r1, r10
 *   @0x19f9e4 ldr r8, [r11, #-0x4]
 *   @0x19f9e8 cmp r7, #0
 *   @0x19f9ec ldrne r2, [r6]
 *   @0x19f9f0 addne r7, r2, r7
 *   @0x19f9f4 cmp r8, #0
 *   @0x19f9f8 ldrne r2, [r6]
 *   @0x19f9fc mov r0, r7
 *   @0x19fa00 addne r8, r2, r8
 *   @0x19fa04 bl 0xb6574 <strcmp@plt>
 *   @0x19fa08 cmp r0, #0
 *   @0x19fa0c beq 0x19f9cc <_Z11Option_LoadPhjS_+0x498>
 *   @0x19fa10 mov r0, r7
 *   @0x19fa14 ldr r1, [sp, #0x4]
 *   @0x19fa18 bl 0xb6574 <strcmp@plt>
 *   @0x19fa1c cmp r0, #0
 *   @0x19fa20 beq 0x19f9cc <_Z11Option_LoadPhjS_+0x498>
 *   @0x19fa24 ldr r12, [sp, #0x8]
 *   @0x19fa28 mov r0, r7
 *   @0x19fa2c ldr r7, [r12]
 *   @0x19fa30 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x19fa34 ldr r12, [sp, #0xc]
 *   @0x19fa38 lsl r3, r5, #2
 *   @0x19fa3c str r3, [sp, #0x18]
 *   @0x19fa40 str r0, [r7, r5, lsl #2]
 *   @0x19fa44 mov r0, r8
 *   @0x19fa48 ldr r8, [r12]
 *   @0x19fa4c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x19fa50 ldr r12, [sp, #0x8]
 *   @0x19fa54 ldr r1, [sp, #0x10]
 *   @0x19fa58 str r0, [r8, r5, lsl #2]
 *   @0x19fa5c ldr r2, [r12]
 *   @0x19fa60 ldr r8, [r2, r5, lsl #2]
 *   @0x19fa64 mov r0, r8
 *   @0x19fa68 bl 0xb6574 <strcmp@plt>
 *   @0x19fa6c cmp r0, #0
 *   @0x19fa70 beq 0x19fb20 <_Z11Option_LoadPhjS_+0x5ec>
 *   @0x19fa74 mov r0, r8
 *   @0x19fa78 ldr r1, [sp, #0x14]
 *   @0x19fa7c bl 0xb6574 <strcmp@plt>
 *   @0x19fa80 cmp r0, #0
 *   @0x19fa84 beq 0x19faf8 <_Z11Option_LoadPhjS_+0x5c4>
 *   @0x19fa88 add r4, r4, #1
 *   @0x19fa8c add r5, r5, #1
 *   @0x19fa90 cmp r4, r9
 *   @0x19fa94 add r11, r11, #8
 *   @0x19fa98 bne 0x19f9dc <_Z11Option_LoadPhjS_+0x4a8>
 *   @0x19fa9c mov r0, #1
 *   @0x19faa0 add sp, sp, #36
 *   @0x19faa4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x19faa8 mov r2, r1
 *   @0x19faac mov r0, r7
 *   @0x19fab0 bl 0xb697c <strtoul@plt>
 *   @0x19fab4 ldr r1, [pc, #0x48c]
 *   @0x19fab8 ldr r3, [pc, #0x48c]
 *   @0x19fabc ldr r2, [r8]
 *   @0x19fac0 ldr r1, [r10, r1]
 *   @0x19fac4 sub r2, r2, #1
 *   @0x19fac8 str r0, [r1]
 *   @0x19facc ldr r3, [r10, r3]
 *   @0x19fad0 str r2, [r8]
 *   @0x19fad4 str r0, [r3]
 *   @0x19fad8 b 0x19f8b8 <_Z11Option_LoadPhjS_+0x384>
 *   @0x19fadc ldr r3, [pc, #0x46c]
 *   @0x19fae0 ldr r2, [r4, #0x88]
 *   @0x19fae4 ldr r3, [r10, r3]
 *   @0x19fae8 adds r2, r2, #0
 *   @0x19faec movne r2, #1
 *   @0x19faf0 strb r2, [r3]
 *   @0x19faf4 b 0x19f858 <_Z11Option_LoadPhjS_+0x324>
 *   @0x19faf8 ldr r12, [sp, #0xc]
 *   @0x19fafc ldr r3, [sp, #0x18]
 *   @0x19fb00 ldr r2, [r12]
 *   @0x19fb04 ldr r0, [r2, r3]
 *   @0x19fb08 bl 0xb66b8 <atoi@plt>
 *   @0x19fb0c ldr r2, [pc, #0x440]
 *   @0x19fb10 ldr r12, [sp, #0x1c]
 *   @0x19fb14 ldr r2, [r12, r2]
 *   @0x19fb18 str r0, [r2]
 *   @0x19fb1c b 0x19fa88 <_Z11Option_LoadPhjS_+0x554>
 *   @0x19fb20 ldr r12, [sp, #0xc]
 *   @0x19fb24 ldr r2, [r12]
 *   @0x19fb28 ldr r0, [r2, r5, lsl #2]
 *   @0x19fb2c bl 0xb66b8 <atoi@plt>
 *   @0x19fb30 ldr r2, [pc, #0x420]
 *   @0x19fb34 ldr r12, [sp, #0x8]
 *   @0x19fb38 ldr r3, [sp, #0x1c]
 *   @0x19fb3c ldr r1, [r12]
 *   @0x19fb40 ldr r2, [r3, r2]
 *   @0x19fb44 ldr r8, [r1, r5, lsl #2]
 *   @0x19fb48 str r0, [r2]
 *   @0x19fb4c b 0x19fa74 <_Z11Option_LoadPhjS_+0x540>
 *   @0x19fb50 ldr r3, [r0, #0x4]
 *   @0x19fb54 cmp r3, #2
 *   @0x19fb58 movne r0, #0
 *   @0x19fb5c bne 0x19faa0 <_Z11Option_LoadPhjS_+0x56c>
 *   @0x19fb60 ldr r1, [pc, #0x324]
 *   @0x19fb64 ldr r0, [pc, #0x324]
 *   @0x19fb68 ldrd r2, r3, [r4, #8]
 *   @0x19fb6c ldr r1, [r10, r1]
 *   @0x19fb70 and lr, r2, #1
 *   @0x19fb74 ldr r5, [pc, #0x31c]
 *   @0x19fb78 ubfx r12, r2, #0x3, #0x1
 *   @0x19fb7c ubfx r7, r2, #0x2, #0x1
 *   @0x19fb80 strb lr, [r1]
 *   @0x19fb84 ubfx r9, r2, #0x4, #0x1
 *   @0x19fb88 ldr r0, [r10, r0]
 *   @0x19fb8c ubfx r6, r2, #0x5, #0x1
 *   @0x19fb90 ldr lr, [pc, #0x2fc]
 *   @0x19fb94 ldrb r0, [r0]
 *   @0x19fb98 cmp r0, #0
 *   @0x19fb9c movne r0, #0
 *   @0x19fba0 strbne r0, [r1]
 *   @0x19fba4 ldr lr, [r10, lr]
 *   @0x19fba8 lsrs r1, r3, #1
 *   @0x19fbac rrx r0, r2
 *   @0x19fbb0 ldr r1, [pc, #0x2e4]
 *   @0x19fbb4 and r8, r0, #1
 *   @0x19fbb8 ldr r3, [pc, #0x2e0]
 *   @0x19fbbc strb r8, [lr]
 *   @0x19fbc0 ubfx lr, r2, #0x6, #0x1
 *   @0x19fbc4 ldr r2, [r10, r5]
 *   @0x19fbc8 ldr r0, [pc, #0x2d4]
 *   @0x19fbcc ldr r8, [r4, #0x10]
 *   @0x19fbd0 strb r7, [r2]
 *   @0x19fbd4 ldr r7, [r10, r1]
 *   @0x19fbd8 ldr r5, [pc, #0x2c8]
 *   @0x19fbdc ldr r1, [pc, #0x2c8]
 *   @0x19fbe0 strb r12, [r7]
 *   @0x19fbe4 ldr r7, [r10, r3]
 *   @0x19fbe8 ldr r2, [pc, #0x2c0]
 *   @0x19fbec ldr r3, [r4, #0x14]
 *   @0x19fbf0 strb r9, [r7]
 *   @0x19fbf4 ldr r7, [r10, r0]
 *   @0x19fbf8 mov r0, r3
 *   @0x19fbfc str r8, [r7]
 *   @0x19fc00 ldr r5, [r10, r5]
 *   @0x19fc04 strb r6, [r5]
 *   @0x19fc08 ldr r1, [r10, r1]
 *   @0x19fc0c strb lr, [r1]
 *   @0x19fc10 ldr r2, [r10, r2]
 *   @0x19fc14 str r3, [r2]
 *   @0x19fc18 bl 0x17ae08 <_Z19GR_Window_Set_Colorj>
 *   @0x19fc1c ldr r1, [pc, #0x290]
 *   @0x19fc20 ldr r2, [pc, #0x290]
 *   @0x19fc24 ldr r3, [r4, #0x8]
 *   @0x19fc28 ldr r0, [r10, r1]
 *   @0x19fc2c ldr r12, [r4, #0x18]
 *   @0x19fc30 ubfx lr, r3, #0x7, #0x1
 *   @0x19fc34 ldr r1, [pc, #0x280]
 *   @0x19fc38 ubfx r8, r3, #0x8, #0x1
 *   @0x19fc3c strb lr, [r0]
 *   @0x19fc40 ubfx r7, r3, #0x9, #0x1
 *   @0x19fc44 ldr r0, [r10, r2]
 *   @0x19fc48 ubfx r6, r3, #0xa, #0x1
 *   @0x19fc4c ldr r9, [r4, #0x1c]
 *   @0x19fc50 ubfx r5, r3, #0xb, #0x1
 *   @0x19fc54 ldr r2, [pc, #0x264]
 *   @0x19fc58 ubfx lr, r3, #0xc, #0x1
 *   @0x19fc5c str r12, [r0]
 *   @0x19fc60 ubfx r0, r3, #0xd, #0x1
 *   @0x19fc64 ldr r12, [r10, r1]
 *   @0x19fc68 ubfx r1, r3, #0xe, #0x1
 *   @0x19fc6c ubfx r11, r3, #0xf, #0x1
 *   @0x19fc70 str r9, [r12]
 *   @0x19fc74 ubfx r9, r3, #0x18, #0x1
 *   @0x19fc78 str r9, [sp, #0x8]
 *   @0x19fc7c ldr r9, [r4, #0x20]
 *   @0x19fc80 ldr r12, [r10, r2]
 *   @0x19fc84 ldr r2, [pc, #0x238]
 *   @0x19fc88 str r9, [r12]
 *   @0x19fc8c ubfx r12, r3, #0x19, #0x1
 *   @0x19fc90 str r12, [sp, #0xc]
 *   @0x19fc94 ldr r12, [r10, r2]
 *   @0x19fc98 ldr r2, [pc, #0x228]
 *   @0x19fc9c strb r8, [r12]
 *   @0x19fca0 ldr r8, [r4, #0x24]
 *   @0x19fca4 ldr r12, [r10, r2]
 *   @0x19fca8 ldr r2, [pc, #0x21c]
 *   @0x19fcac str r8, [r12]
 *   @0x19fcb0 ubfx r8, r3, #0x1a, #0x1
 *   @0x19fcb4 ldr r12, [r10, r2]
 *   @0x19fcb8 ldr r2, [pc, #0x210]
 *   @0x19fcbc strb r7, [r12]
 *   @0x19fcc0 ubfx r7, r3, #0x1b, #0x1
 *   @0x19fcc4 ldr r12, [r10, r2]
 *   @0x19fcc8 ldr r2, [pc, #0x204]
 *   @0x19fccc strb r6, [r12]
 *   @0x19fcd0 ubfx r6, r3, #0x10, #0x1
 *   @0x19fcd4 ldr r12, [r10, r2]
 *   @0x19fcd8 ldr r2, [pc, #0x1f8]
 *   @0x19fcdc strb r5, [r12]
 *   @0x19fce0 ubfx r5, r3, #0x11, #0x1
 *   @0x19fce4 ldr r12, [r10, r2]
 *   @0x19fce8 ldr r2, [pc, #0x1ec]
 *   @0x19fcec strb lr, [r12]
 *   @0x19fcf0 ubfx lr, r3, #0x12, #0x1
 *   @0x19fcf4 ldr r12, [r10, r2]
 *   @0x19fcf8 ldr r2, [pc, #0x1e0]
 *   @0x19fcfc strb r0, [r12]
 *   @0x19fd00 ubfx r0, r3, #0x14, #0x1
 *   @0x19fd04 ldr r12, [r10, r2]
 *   @0x19fd08 ldr r2, [pc, #0x1d4]
 *   @0x19fd0c strb r1, [r12]
 *   @0x19fd10 ldr r12, [r4, #0x28]
 *   @0x19fd14 ldr r1, [r10, r2]
 *   @0x19fd18 ldr r2, [pc, #0x1c8]
 *   @0x19fd1c str r12, [r1]
 *   @0x19fd20 ubfx r1, r3, #0x15, #0x1
 *   @0x19fd24 ldr r2, [r10, r2]
 *   @0x19fd28 ldr r12, [pc, #0x1bc]
 *   @0x19fd2c ldr r9, [sp, #0x8]
 *   @0x19fd30 strb r11, [r2]
 *   @0x19fd34 ubfx r2, r3, #0x16, #0x1
 *   @0x19fd38 ldr r12, [r10, r12]
 *   @0x19fd3c str r12, [sp, #0x4]
 *   @0x19fd40 ldr r11, [sp, #0x4]
 *   @0x19fd44 ldr r12, [pc, #0x1a4]
 *   @0x19fd48 strb r9, [r11]
 *   @0x19fd4c ldr r9, [sp, #0xc]
 *   @0x19fd50 ldr r11, [r10, r12]
 *   @0x19fd54 ldr r12, [pc, #0x200]
 *   @0x19fd58 strb r9, [r11]
 *   @0x19fd5c ldr r9, [pc, #0x1fc]
 *   @0x19fd60 ldr r11, [r10, r12]
 *   @0x19fd64 ldr r12, [pc, #0x188]
 *   @0x19fd68 strb r8, [r11]
 *   @0x19fd6c ldr r11, [r10, r9]
 *   @0x19fd70 ldr r9, [pc, #0x180]
 *   @0x19fd74 ldr r8, [pc, #0x180]
 *   @0x19fd78 strb r7, [r11]
 *   @0x19fd7c ldr r11, [r10, r12]
 *   @0x19fd80 ldr r7, [pc, #0x178]
 *   @0x19fd84 ldr r12, [r4, #0x34]
 *   @0x19fd88 strb r6, [r11]
 *   @0x19fd8c ldr r6, [r10, r9]
 *   @0x19fd90 ldr r9, [r10, r8]
 *   @0x19fd94 ldr r8, [pc, #0x168]
 *   @0x19fd98 ldr r11, [r6]
 *   @0x19fd9c add r12, r11, r12
 *   @0x19fda0 str r12, [r9]
 *   @0x19fda4 ldr r9, [r10, r7]
 *   @0x19fda8 ldr r12, [r4, #0x38]
 *   @0x19fdac ldr r7, [pc, #0x154]
 *   @0x19fdb0 strb r5, [r9]
 *   @0x19fdb4 adds r12, r12, #0
 *   @0x19fdb8 ldr r5, [r10, r8]
 *   @0x19fdbc movne r12, #1
 *   @0x19fdc0 ldr r9, [pc, #0x144]
 *   @0x19fdc4 ldr r8, [pc, #0x144]
 *   @0x19fdc8 str r12, [r5]
 *   @0x19fdcc ldr r12, [r10, r7]
 *   @0x19fdd0 ldr r7, [pc, #0x13c]
 *   @0x19fdd4 ldr r5, [pc, #0x13c]
 *   @0x19fdd8 strb lr, [r12]
 *   @0x19fddc ldr lr, [r10, r9]
 *   @0x19fde0 strb r0, [lr]
 *   @0x19fde4 ldr r0, [r10, r8]
 *   @0x19fde8 strb r1, [r0]
 *   @0x19fdec ldr r1, [r10, r7]
 *   @0x19fdf0 strb r2, [r1]
 *   @0x19fdf4 ldr r2, [r10, r5]
 *   @0x19fdf8 ldr r2, [r2]
 *   @0x19fdfc cmp r2, #4
 *   @0x19fe00 ldrgt r2, [pc, #0x148]
 *   @0x19fe04 ubfxgt r3, r3, #0x17, #0x1
 *   @0x19fe08 ldrgt r2, [r10, r2]
 *   @0x19fe0c strbgt r3, [r2]
 *   @0x19fe10 ldr r3, [pc, #0x104]
 *   @0x19fe14 add r11, r4, #64
 *   @0x19fe18 ldr r9, [r4, #0x3c]
 *   @0x19fe1c ldr r8, [r10, r3]
 *   @0x19fe20 str r9, [r8]
 *   @0x19fe24 b 0x19f870 <_Z11Option_LoadPhjS_+0x33c>
 *   @0x19fe28 ldr r2, [pc, #0xfc]
 *   @0x19fe2c lsl r1, r9, #2
 *   @0x19fe30 ldr r4, [pc, #0x12c]
 *   @0x19fe34 mov r3, #352
 *   @0x19fe38 ldr r0, [r10, r2]
 *   @0x19fe3c add r4, pc, r4
 *   @0x19fe40 mov r2, r4
 *   @0x19fe44 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19fe48 ldr r1, [r8]
 *   @0x19fe4c ldr r0, [pc, #0xe4]
 *   @0x19fe50 mov r2, r4
 *   @0x19fe54 movw r3, #0x161
 *   @0x19fe58 lsl r1, r1, #2
 *   @0x19fe5c ldr r0, [r10, r0]
 *   @0x19fe60 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x19fe64 b 0x19fa9c <_Z11Option_LoadPhjS_+0x568>
 *   @0x19fe68 ldr r2, [pc, #0xbc]
 *   @0x19fe6c mov r3, #352
 *   @0x19fe70 ldr r1, [r8]
 *   @0x19fe74 ldr r4, [pc, #0xec]
 *   @0x19fe78 ldr r0, [r10, r2]
 *   @0x19fe7c add r4, pc, r4
 *   @0x19fe80 lsl r1, r1, #2
 *   @0x19fe84 b 0x19fe40 <_Z11Option_LoadPhjS_+0x90c>
 *   @0x19fe88 eoreq r2, r5, r4, lsl #14
 *   @0x19fe8c .word 0xffffea98
 *   @0x19fe90 .word 0xffffeb04
 *   @0x19fe94 .word 0xffffea9c
 *   @0x19fe98 .word 0xffffd0e0
 *   @0x19fe9c .word 0xffffeaa0
 *   @0x19fea0 .word 0xffffd79c
 *   @0x19fea4 .word 0xffffeaa4
 *   @0x19fea8 .word 0xffffeaa8
 *   @0x19feac .word 0xffffeaac
 *   @0x19feb0 .word 0xffffeab0
 *   @0x19feb4 .word 0xffffeab4
 *   @0x19feb8 .word 0xffffeab8
 *   @0x19febc .word 0xffffeabc
 *   @0x19fec0 .word 0xffffeac0
 *   @0x19fec4 .word 0xffffeac4
 *   @0x19fec8 .word 0xffffeacc
 *   @0x19fecc .word 0xffffead0
 *   @0x19fed0 .word 0xffffead4
 *   @0x19fed4 .word 0xffffead8
 *   @0x19fed8 .word 0xffffeadc
 *   @0x19fedc .word 0xffffeae0
 *   @0x19fee0 .word 0xffffeae4
 *   @0x19fee4 .word 0xffffeae8
 *   @0x19fee8 .word 0xffffeac8
 *   @0x19feec .word 0xffffeb08
 *   @0x19fef0 .word 0xffffeb0c
 *   @0x19fef4 .word 0xffffeaec
 *   @0x19fef8 .word 0xffffbcf4
 *   @0x19fefc .word 0xffffeb10
 *   @0x19ff00 .word 0xffffeaf0
 *   @0x19ff04 .word 0xffffeaf4
 *   @0x19ff08 .word 0xffffeaf8
 *   @0x19ff0c .word 0xffffeafc
 *   @0x19ff10 .word 0xffffc144
 *   @0x19ff14 .word 0xffffeb00
 *   @0x19ff18 .word 0xffffea88
 *   @0x19ff1c .word 0xffffc184
 *   @0x19ff20 andseq sp, r10, r12, lsl #13
 *   @0x19ff24 andseq sp, r10, r4, ror r6
 *   @0x19ff28 .word 0xffffc964
 *   @0x19ff2c .word 0xffffc188
 *   @0x19ff30 ldrsheq sp, [r10], -r12
 *   @0x19ff34 andseq sp, r10, r0, lsr #11
 *   @0x19ff38 .word 0xffffc18c
 *   @0x19ff3c mulseq r10, r0, r5
 *   @0x19ff40 andseq sp, r10, r8, lsl #11
 *   @0x19ff44 andseq sp, r10, r12, ror r5
 *   @0x19ff48 .word 0xffffc0ac
 *   @0x19ff4c .word 0xffffeb14
 *   @0x19ff50 .word 0xffffeb18
 *   @0x19ff54 .word 0xffffe7a4
 *   @0x19ff58 .word 0xffffe7a0
 *   @0x19ff5c .word 0xffffea30
 *   @0x19ff60 .word 0xffffea34
 *   @0x19ff64 andseq sp, r10, r12, lsl #2
 *   @0x19ff68 andseq sp, r10, r12, asr #1
 *
 * ══ §7/12 InitYoYoFunctionConstants()  0x15d0f8  size 2564  641 条（0x15d0f8..0x15dafc）
 * @func 0x15d0f8 0x15dafc  size 2564  641 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AddRealConstant(char const*, double)×92 / InitYoYoConstantsM()
 * 字段偏移 top8: 0x878×1 / 0x868×1 / 0x858×1 / 0x848×1 / 0x834×1 / 0x824×1 / 0x814×1 / 0x800×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x15d0f8 push {r4, lr}
 *   @0x15d0fc bl 0x15e2a4 <_Z18InitYoYoConstantsMv>
 *   @0x15d100 mov r2, #0
 *   @0x15d104 ldr r0, [pc, #0x878]
 *   @0x15d108 mov r3, #0
 *   @0x15d10c movt r3, #0xbff0
 *   @0x15d110 add r0, pc, r0
 *   @0x15d114 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d118 ldr r0, [pc, #0x868]
 *   @0x15d11c mov r2, #0
 *   @0x15d120 mov r3, #0
 *   @0x15d124 add r0, pc, r0
 *   @0x15d128 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d12c ldr r0, [pc, #0x858]
 *   @0x15d130 mov r2, #0
 *   @0x15d134 mov r3, #0
 *   @0x15d138 add r0, pc, r0
 *   @0x15d13c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d140 ldr r0, [pc, #0x848]
 *   @0x15d144 mov r2, #0
 *   @0x15d148 mov r3, #0
 *   @0x15d14c add r0, pc, r0
 *   @0x15d150 movt r3, #0x3ff0
 *   @0x15d154 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d158 ldr r3, [pc, #0x834]
 *   @0x15d15c ldr r3, [pc, r3]
 *   @0x15d160 ldrb r3, [r3]
 *   @0x15d164 cmp r3, #0
 *   @0x15d168 bne 0x15d180 <_Z25InitYoYoFunctionConstantsv+0x88>
 *   @0x15d16c ldr r0, [pc, #0x824]
 *   @0x15d170 mov r2, #0
 *   @0x15d174 mov r3, #1073741824
 *   @0x15d178 add r0, pc, r0
 *   @0x15d17c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d180 ldr r0, [pc, #0x814]
 *   @0x15d184 mov r2, #0
 *   @0x15d188 mov r3, #0
 *   @0x15d18c movt r3, #0x4008
 *   @0x15d190 add r0, pc, r0
 *   @0x15d194 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d198 ldr r0, [pc, #0x800]
 *   @0x15d19c mov r2, #0
 *   @0x15d1a0 mov r3, #0
 *   @0x15d1a4 add r0, pc, r0
 *   @0x15d1a8 movt r3, #0x4010
 *   @0x15d1ac bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d1b0 ldr r0, [pc, #0x7ec]
 *   @0x15d1b4 mov r2, #0
 *   @0x15d1b8 mov r3, #0
 *   @0x15d1bc add r0, pc, r0
 *   @0x15d1c0 movt r3, #0x4014
 *   @0x15d1c4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d1c8 ldr r0, [pc, #0x7d8]
 *   @0x15d1cc mov r2, #0
 *   @0x15d1d0 mov r3, #0
 *   @0x15d1d4 add r0, pc, r0
 *   @0x15d1d8 movt r3, #0x4018
 *   @0x15d1dc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d1e0 ldr r0, [pc, #0x7c4]
 *   @0x15d1e4 mov r2, #0
 *   @0x15d1e8 mov r3, #0
 *   @0x15d1ec add r0, pc, r0
 *   @0x15d1f0 movt r3, #0x401c
 *   @0x15d1f4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d1f8 ldr r0, [pc, #0x7b0]
 *   @0x15d1fc mov r2, #0
 *   @0x15d200 mov r3, #0
 *   @0x15d204 add r0, pc, r0
 *   @0x15d208 movt r3, #0x4020
 *   @0x15d20c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d210 ldr r0, [pc, #0x79c]
 *   @0x15d214 mov r2, #0
 *   @0x15d218 mov r3, #0
 *   @0x15d21c add r0, pc, r0
 *   @0x15d220 movt r3, #0x4022
 *   @0x15d224 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d228 ldr r0, [pc, #0x788]
 *   @0x15d22c mov r2, #0
 *   @0x15d230 mov r3, #0
 *   @0x15d234 add r0, pc, r0
 *   @0x15d238 movt r3, #0x4024
 *   @0x15d23c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d240 ldr r0, [pc, #0x774]
 *   @0x15d244 mov r2, #0
 *   @0x15d248 mov r3, #0
 *   @0x15d24c add r0, pc, r0
 *   @0x15d250 movt r3, #0x4026
 *   @0x15d254 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d258 ldr r0, [pc, #0x760]
 *   @0x15d25c mov r2, #0
 *   @0x15d260 mov r3, #0
 *   @0x15d264 add r0, pc, r0
 *   @0x15d268 movt r3, #0x4028
 *   @0x15d26c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d270 ldr r0, [pc, #0x74c]
 *   @0x15d274 mov r2, #0
 *   @0x15d278 mov r3, #0
 *   @0x15d27c add r0, pc, r0
 *   @0x15d280 movt r3, #0x402a
 *   @0x15d284 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d288 ldr r0, [pc, #0x738]
 *   @0x15d28c mov r2, #0
 *   @0x15d290 mov r3, #0
 *   @0x15d294 add r0, pc, r0
 *   @0x15d298 movt r3, #0x402c
 *   @0x15d29c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d2a0 ldr r0, [pc, #0x724]
 *   @0x15d2a4 mov r2, #0
 *   @0x15d2a8 mov r3, #0
 *   @0x15d2ac add r0, pc, r0
 *   @0x15d2b0 movt r3, #0x402e
 *   @0x15d2b4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d2b8 ldr r0, [pc, #0x710]
 *   @0x15d2bc mov r2, #0
 *   @0x15d2c0 mov r3, #0
 *   @0x15d2c4 add r0, pc, r0
 *   @0x15d2c8 movt r3, #0x4030
 *   @0x15d2cc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d2d0 ldr r0, [pc, #0x6fc]
 *   @0x15d2d4 mov r2, #0
 *   @0x15d2d8 mov r3, #0
 *   @0x15d2dc add r0, pc, r0
 *   @0x15d2e0 movt r3, #0x4031
 *   @0x15d2e4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d2e8 ldr r0, [pc, #0x6e8]
 *   @0x15d2ec mov r2, #0
 *   @0x15d2f0 mov r3, #0
 *   @0x15d2f4 add r0, pc, r0
 *   @0x15d2f8 movt r3, #0x4032
 *   @0x15d2fc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d300 ldr r0, [pc, #0x6d4]
 *   @0x15d304 mov r2, #0
 *   @0x15d308 mov r3, #0
 *   @0x15d30c add r0, pc, r0
 *   @0x15d310 movt r3, #0x4033
 *   @0x15d314 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d318 ldr r0, [pc, #0x6c0]
 *   @0x15d31c mov r2, #0
 *   @0x15d320 mov r3, #0
 *   @0x15d324 add r0, pc, r0
 *   @0x15d328 movt r3, #0x40f0
 *   @0x15d32c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d330 ldr r0, [pc, #0x6ac]
 *   @0x15d334 mov r2, #0
 *   @0x15d338 mov r3, #16
 *   @0x15d33c add r0, pc, r0
 *   @0x15d340 movt r3, #0x40f0
 *   @0x15d344 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d348 ldr r0, [pc, #0x698]
 *   @0x15d34c mov r2, #0
 *   @0x15d350 mov r3, #32
 *   @0x15d354 add r0, pc, r0
 *   @0x15d358 movt r3, #0x40f0
 *   @0x15d35c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d360 ldr r0, [pc, #0x684]
 *   @0x15d364 mov r2, #0
 *   @0x15d368 mov r3, #48
 *   @0x15d36c add r0, pc, r0
 *   @0x15d370 movt r3, #0x40f0
 *   @0x15d374 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d378 ldr r0, [pc, #0x670]
 *   @0x15d37c mov r2, #0
 *   @0x15d380 mov r3, #64
 *   @0x15d384 add r0, pc, r0
 *   @0x15d388 movt r3, #0x40f0
 *   @0x15d38c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d390 ldr r0, [pc, #0x65c]
 *   @0x15d394 mov r2, #0
 *   @0x15d398 mov r3, #80
 *   @0x15d39c add r0, pc, r0
 *   @0x15d3a0 movt r3, #0x40f0
 *   @0x15d3a4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d3a8 ldr r0, [pc, #0x648]
 *   @0x15d3ac mov r2, #0
 *   @0x15d3b0 mov r3, #96
 *   @0x15d3b4 add r0, pc, r0
 *   @0x15d3b8 movt r3, #0x40f0
 *   @0x15d3bc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d3c0 ldr r0, [pc, #0x634]
 *   @0x15d3c4 mov r2, #0
 *   @0x15d3c8 mov r3, #112
 *   @0x15d3cc add r0, pc, r0
 *   @0x15d3d0 movt r3, #0x40f0
 *   @0x15d3d4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d3d8 ldr r0, [pc, #0x620]
 *   @0x15d3dc mov r2, #0
 *   @0x15d3e0 mov r3, #0
 *   @0x15d3e4 add r0, pc, r0
 *   @0x15d3e8 movt r3, #0xbff0
 *   @0x15d3ec bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d3f0 ldr r0, [pc, #0x60c]
 *   @0x15d3f4 mov r2, #0
 *   @0x15d3f8 mov r3, #0
 *   @0x15d3fc add r0, pc, r0
 *   @0x15d400 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d404 ldr r0, [pc, #0x5fc]
 *   @0x15d408 mov r2, #0
 *   @0x15d40c mov r3, #0
 *   @0x15d410 add r0, pc, r0
 *   @0x15d414 movt r3, #0x3ff0
 *   @0x15d418 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d41c ldr r0, [pc, #0x5e8]
 *   @0x15d420 mov r2, #0
 *   @0x15d424 mov r3, #1073741824
 *   @0x15d428 add r0, pc, r0
 *   @0x15d42c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d430 ldr r0, [pc, #0x5d8]
 *   @0x15d434 mov r2, #0
 *   @0x15d438 mov r3, #0
 *   @0x15d43c add r0, pc, r0
 *   @0x15d440 movt r3, #0x4008
 *   @0x15d444 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d448 ldr r0, [pc, #0x5c4]
 *   @0x15d44c mov r2, #0
 *   @0x15d450 mov r3, #0
 *   @0x15d454 add r0, pc, r0
 *   @0x15d458 movt r3, #0x4010
 *   @0x15d45c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d460 ldr r0, [pc, #0x5b0]
 *   @0x15d464 mov r2, #0
 *   @0x15d468 mov r3, #0
 *   @0x15d46c add r0, pc, r0
 *   @0x15d470 movt r3, #0x4070
 *   @0x15d474 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d478 ldr r0, [pc, #0x59c]
 *   @0x15d47c mov r2, #0
 *   @0x15d480 mov r3, #1073741824
 *   @0x15d484 add r0, pc, r0
 *   @0x15d488 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d48c ldr r0, [pc, #0x58c]
 *   @0x15d490 mov r2, #0
 *   @0x15d494 mov r3, #0
 *   @0x15d498 add r0, pc, r0
 *   @0x15d49c movt r3, #0xbff0
 *   @0x15d4a0 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d4a4 ldr r0, [pc, #0x578]
 *   @0x15d4a8 mov r2, #0
 *   @0x15d4ac mov r3, #0
 *   @0x15d4b0 add r0, pc, r0
 *   @0x15d4b4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d4b8 ldr r0, [pc, #0x568]
 *   @0x15d4bc mov r2, #0
 *   @0x15d4c0 mov r3, #0
 *   @0x15d4c4 add r0, pc, r0
 *   @0x15d4c8 movt r3, #0x3ff0
 *   @0x15d4cc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d4d0 ldr r0, [pc, #0x554]
 *   @0x15d4d4 mov r2, #0
 *   @0x15d4d8 mov r3, #1073741824
 *   @0x15d4dc add r0, pc, r0
 *   @0x15d4e0 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d4e4 ldr r0, [pc, #0x544]
 *   @0x15d4e8 mov r2, #0
 *   @0x15d4ec mov r3, #0
 *   @0x15d4f0 add r0, pc, r0
 *   @0x15d4f4 movt r3, #0x4008
 *   @0x15d4f8 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d4fc ldr r0, [pc, #0x530]
 *   @0x15d500 mov r2, #0
 *   @0x15d504 mov r3, #0
 *   @0x15d508 add r0, pc, r0
 *   @0x15d50c movt r3, #0x4010
 *   @0x15d510 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d514 ldr r0, [pc, #0x51c]
 *   @0x15d518 mov r2, #0
 *   @0x15d51c mov r3, #0
 *   @0x15d520 add r0, pc, r0
 *   @0x15d524 movt r3, #0x4014
 *   @0x15d528 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d52c ldr r0, [pc, #0x508]
 *   @0x15d530 mov r2, #0
 *   @0x15d534 mov r3, #0
 *   @0x15d538 add r0, pc, r0
 *   @0x15d53c movt r3, #0x4018
 *   @0x15d540 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d544 ldr r0, [pc, #0x4f4]
 *   @0x15d548 mov r2, #0
 *   @0x15d54c mov r3, #0
 *   @0x15d550 add r0, pc, r0
 *   @0x15d554 movt r3, #0x401c
 *   @0x15d558 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d55c ldr r0, [pc, #0x4e0]
 *   @0x15d560 mov r2, #0
 *   @0x15d564 mov r3, #0
 *   @0x15d568 add r0, pc, r0
 *   @0x15d56c movt r3, #0x4020
 *   @0x15d570 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d574 ldr r0, [pc, #0x4cc]
 *   @0x15d578 mov r2, #0
 *   @0x15d57c mov r3, #0
 *   @0x15d580 add r0, pc, r0
 *   @0x15d584 movt r3, #0x4022
 *   @0x15d588 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d58c ldr r0, [pc, #0x4b8]
 *   @0x15d590 mov r2, #0
 *   @0x15d594 mov r3, #0
 *   @0x15d598 add r0, pc, r0
 *   @0x15d59c movt r3, #0x4024
 *   @0x15d5a0 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d5a4 ldr r0, [pc, #0x4a4]
 *   @0x15d5a8 mov r2, #0
 *   @0x15d5ac mov r3, #0
 *   @0x15d5b0 add r0, pc, r0
 *   @0x15d5b4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d5b8 ldr r0, [pc, #0x494]
 *   @0x15d5bc mov r2, #0
 *   @0x15d5c0 mov r3, #0
 *   @0x15d5c4 add r0, pc, r0
 *   @0x15d5c8 movt r3, #0x3ff0
 *   @0x15d5cc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d5d0 ldr r0, [pc, #0x480]
 *   @0x15d5d4 mov r2, #0
 *   @0x15d5d8 mov r3, #1073741824
 *   @0x15d5dc add r0, pc, r0
 *   @0x15d5e0 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d5e4 ldr r0, [pc, #0x470]
 *   @0x15d5e8 mov r2, #0
 *   @0x15d5ec mov r3, #0
 *   @0x15d5f0 add r0, pc, r0
 *   @0x15d5f4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d5f8 ldr r0, [pc, #0x460]
 *   @0x15d5fc mov r2, #0
 *   @0x15d600 mov r3, #0
 *   @0x15d604 add r0, pc, r0
 *   @0x15d608 movt r3, #0x3ff0
 *   @0x15d60c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d610 ldr r0, [pc, #0x44c]
 *   @0x15d614 mov r2, #0
 *   @0x15d618 mov r3, #20480
 *   @0x15d61c add r0, pc, r0
 *   @0x15d620 movt r3, #0x408f
 *   @0x15d624 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d628 ldr r0, [pc, #0x438]
 *   @0x15d62c mov r2, #0
 *   @0x15d630 mov r3, #22528
 *   @0x15d634 add r0, pc, r0
 *   @0x15d638 movt r3, #0x408f
 *   @0x15d63c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d640 ldr r0, [pc, #0x424]
 *   @0x15d644 mov r2, #0
 *   @0x15d648 mov r3, #24576
 *   @0x15d64c add r0, pc, r0
 *   @0x15d650 movt r3, #0x408f
 *   @0x15d654 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d658 ldr r0, [pc, #0x410]
 *   @0x15d65c mov r2, #0
 *   @0x15d660 mov r3, #26624
 *   @0x15d664 add r0, pc, r0
 *   @0x15d668 movt r3, #0x408f
 *   @0x15d66c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d670 ldr r0, [pc, #0x3fc]
 *   @0x15d674 mov r2, #0
 *   @0x15d678 mov r3, #28672
 *   @0x15d67c add r0, pc, r0
 *   @0x15d680 movt r3, #0x408f
 *   @0x15d684 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d688 ldr r0, [pc, #0x3e8]
 *   @0x15d68c mov r2, #0
 *   @0x15d690 mov r3, #30720
 *   @0x15d694 add r0, pc, r0
 *   @0x15d698 movt r3, #0x408f
 *   @0x15d69c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d6a0 ldr r0, [pc, #0x3d4]
 *   @0x15d6a4 mov r2, #0
 *   @0x15d6a8 mov r3, #32768
 *   @0x15d6ac add r0, pc, r0
 *   @0x15d6b0 movt r3, #0x408f
 *   @0x15d6b4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d6b8 ldr r0, [pc, #0x3c0]
 *   @0x15d6bc mov r2, #0
 *   @0x15d6c0 mov r3, #34816
 *   @0x15d6c4 add r0, pc, r0
 *   @0x15d6c8 movt r3, #0x408f
 *   @0x15d6cc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d6d0 ldr r0, [pc, #0x3ac]
 *   @0x15d6d4 mov r2, #0
 *   @0x15d6d8 mov r3, #36864
 *   @0x15d6dc add r0, pc, r0
 *   @0x15d6e0 movt r3, #0x408f
 *   @0x15d6e4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d6e8 ldr r0, [pc, #0x398]
 *   @0x15d6ec mov r2, #0
 *   @0x15d6f0 mov r3, #38912
 *   @0x15d6f4 add r0, pc, r0
 *   @0x15d6f8 movt r3, #0x408f
 *   @0x15d6fc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d700 ldr r0, [pc, #0x384]
 *   @0x15d704 mov r2, #0
 *   @0x15d708 mov r3, #0
 *   @0x15d70c add r0, pc, r0
 *   @0x15d710 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d714 ldr r0, [pc, #0x374]
 *   @0x15d718 mov r2, #0
 *   @0x15d71c mov r3, #0
 *   @0x15d720 add r0, pc, r0
 *   @0x15d724 movt r3, #0x3ff0
 *   @0x15d728 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d72c ldr r0, [pc, #0x360]
 *   @0x15d730 mov r2, #0
 *   @0x15d734 mov r3, #1073741824
 *   @0x15d738 add r0, pc, r0
 *   @0x15d73c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d740 ldr r0, [pc, #0x350]
 *   @0x15d744 mov r2, #0
 *   @0x15d748 mov r3, #0
 *   @0x15d74c add r0, pc, r0
 *   @0x15d750 movt r3, #0x4008
 *   @0x15d754 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d758 ldr r0, [pc, #0x33c]
 *   @0x15d75c mov r2, #0
 *   @0x15d760 mov r3, #0
 *   @0x15d764 add r0, pc, r0
 *   @0x15d768 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d76c ldr r0, [pc, #0x32c]
 *   @0x15d770 mov r2, #0
 *   @0x15d774 mov r3, #0
 *   @0x15d778 add r0, pc, r0
 *   @0x15d77c movt r3, #0x3ff0
 *   @0x15d780 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d784 ldr r0, [pc, #0x318]
 *   @0x15d788 mov r2, #0
 *   @0x15d78c mov r3, #0
 *   @0x15d790 add r0, pc, r0
 *   @0x15d794 movt r3, #0xbff0
 *   @0x15d798 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d79c ldr r0, [pc, #0x304]
 *   @0x15d7a0 mov r2, #0
 *   @0x15d7a4 mov r3, #0
 *   @0x15d7a8 add r0, pc, r0
 *   @0x15d7ac bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d7b0 ldr r0, [pc, #0x2f4]
 *   @0x15d7b4 mov r2, #0
 *   @0x15d7b8 mov r3, #0
 *   @0x15d7bc add r0, pc, r0
 *   @0x15d7c0 movt r3, #0x3ff0
 *   @0x15d7c4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d7c8 ldr r0, [pc, #0x2e0]
 *   @0x15d7cc mov r2, #0
 *   @0x15d7d0 mov r3, #1073741824
 *   @0x15d7d4 add r0, pc, r0
 *   @0x15d7d8 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d7dc ldr r0, [pc, #0x2d0]
 *   @0x15d7e0 mov r2, #0
 *   @0x15d7e4 mov r3, #0
 *   @0x15d7e8 add r0, pc, r0
 *   @0x15d7ec movt r3, #0x4008
 *   @0x15d7f0 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d7f4 ldr r0, [pc, #0x2bc]
 *   @0x15d7f8 mov r2, #0
 *   @0x15d7fc mov r3, #0
 *   @0x15d800 add r0, pc, r0
 *   @0x15d804 movt r3, #0x4010
 *   @0x15d808 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d80c ldr r0, [pc, #0x2a8]
 *   @0x15d810 mov r2, #0
 *   @0x15d814 mov r3, #0
 *   @0x15d818 add r0, pc, r0
 *   @0x15d81c movt r3, #0x4014
 *   @0x15d820 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d824 ldr r0, [pc, #0x294]
 *   @0x15d828 mov r2, #0
 *   @0x15d82c mov r3, #0
 *   @0x15d830 add r0, pc, r0
 *   @0x15d834 movt r3, #0x4018
 *   @0x15d838 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d83c ldr r0, [pc, #0x280]
 *   @0x15d840 mov r2, #0
 *   @0x15d844 mov r3, #0
 *   @0x15d848 add r0, pc, r0
 *   @0x15d84c movt r3, #0x401c
 *   @0x15d850 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d854 ldr r0, [pc, #0x26c]
 *   @0x15d858 mov r2, #0
 *   @0x15d85c mov r3, #0
 *   @0x15d860 add r0, pc, r0
 *   @0x15d864 movt r3, #0x4020
 *   @0x15d868 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d86c ldr r0, [pc, #0x258]
 *   @0x15d870 mov r2, #0
 *   @0x15d874 mov r3, #0
 *   @0x15d878 add r0, pc, r0
 *   @0x15d87c movt r3, #0x3ff0
 *   @0x15d880 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d884 ldr r0, [pc, #0x244]
 *   @0x15d888 mov r2, #0
 *   @0x15d88c mov r3, #1073741824
 *   @0x15d890 add r0, pc, r0
 *   @0x15d894 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d898 ldr r0, [pc, #0x234]
 *   @0x15d89c mov r2, #0
 *   @0x15d8a0 mov r3, #0
 *   @0x15d8a4 add r0, pc, r0
 *   @0x15d8a8 movt r3, #0x4008
 *   @0x15d8ac bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d8b0 ldr r0, [pc, #0x220]
 *   @0x15d8b4 mov r2, #0
 *   @0x15d8b8 mov r3, #0
 *   @0x15d8bc add r0, pc, r0
 *   @0x15d8c0 movt r3, #0x4010
 *   @0x15d8c4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d8c8 ldr r0, [pc, #0x20c]
 *   @0x15d8cc mov r2, #0
 *   @0x15d8d0 mov r3, #0
 *   @0x15d8d4 add r0, pc, r0
 *   @0x15d8d8 movt r3, #0x4014
 *   @0x15d8dc bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d8e0 ldr r0, [pc, #0x1f8]
 *   @0x15d8e4 mov r2, #0
 *   @0x15d8e8 mov r3, #0
 *   @0x15d8ec add r0, pc, r0
 *   @0x15d8f0 movt r3, #0x4018
 *   @0x15d8f4 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d8f8 ldr r0, [pc, #0x1e4]
 *   @0x15d8fc mov r2, #0
 *   @0x15d900 mov r3, #0
 *   @0x15d904 add r0, pc, r0
 *   @0x15d908 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d90c ldr r0, [pc, #0x1d4]
 *   @0x15d910 mov r2, #0
 *   @0x15d914 mov r3, #0
 *   @0x15d918 add r0, pc, r0
 *   @0x15d91c movt r3, #0x3ff0
 *   @0x15d920 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d924 ldr r0, [pc, #0x1c0]
 *   @0x15d928 mov r2, #0
 *   @0x15d92c mov r3, #1073741824
 *   @0x15d930 add r0, pc, r0
 *   @0x15d934 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d938 ldr r0, [pc, #0x1b0]
 *   @0x15d93c mov r2, #0
 *   @0x15d940 mov r3, #0
 *   @0x15d944 add r0, pc, r0
 *   @0x15d948 movt r3, #0x4008
 *   @0x15d94c bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d950 ldr r0, [pc, #0x19c]
 *   @0x15d954 mov r2, #0
 *   @0x15d958 mov r3, #0
 *   @0x15d95c add r0, pc, r0
 *   @0x15d960 movt r3, #0x4010
 *   @0x15d964 bl 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d968 ldr r0, [pc, #0x188]
 *   @0x15d96c mov r3, #0
 *   @0x15d970 mov r2, #0
 *   @0x15d974 add r0, pc, r0
 *   @0x15d978 movt r3, #0x4014
 *   @0x15d97c pop {r4, lr}
 *   @0x15d980 b 0xedff4 <_Z15AddRealConstantPKcd>
 *   @0x15d984 andseq r9, sp, r8, asr r3
 *   @0x15d988 andseq r9, sp, r0, asr r3
 *   @0x15d98c andseq r9, sp, r8, asr #6
 *   @0x15d990 andseq r9, sp, r0, asr #6
 *   @0x15d994 eoreq r0, r9, r8, asr #15
 *   @0x15d998 andseq r9, sp, r0, lsr #6
 *   @0x15d99c andseq r9, sp, r0, lsl r3
 *   @0x15d9a0 andseq r9, sp, r4, lsl #6
 *   @0x15d9a4 ldrsheq r9, [sp], -r8
 *   @0x15d9a8 andseq r9, sp, r12, ror #5
 *   @0x15d9ac andseq r9, sp, r0, ror #5
 *   @0x15d9b0 ldrsbeq r9, [sp], -r4
 *   @0x15d9b4 andseq r9, sp, r8, asr #5
 *   @0x15d9b8 andseq r9, sp, r0, asr #5
 *   @0x15d9bc ldrheq r9, [sp], -r0
 *   @0x15d9c0 andseq r9, sp, r0, lsr #5
 *   @0x15d9c4 mulseq sp, r4, r2
 *   @0x15d9c8 andseq r9, sp, r4, lsl #5
 *   @0x15d9cc andseq r9, sp, r4, ror r2
 *   @0x15d9d0 andseq r9, sp, r8, ror #4
 *   @0x15d9d4 andseq r9, sp, r8, asr r2
 *   @0x15d9d8 andseq r9, sp, r12, asr #4
 *   @0x15d9dc andseq r11, lr, r8, ror #27
 *   @0x15d9e0 ldrsbeq r11, [lr], -r12
 *   @0x15d9e4 ldrsbeq r11, [lr], -r4
 *   @0x15d9e8 andseq r11, lr, r12, asr #27
 *   @0x15d9ec andseq r11, lr, r0, asr #27
 *   @0x15d9f0 ldrheq r11, [lr], -r4
 *   @0x15d9f4 andseq r11, lr, r12, lsr #27
 *   @0x15d9f8 andseq r11, lr, r4, lsr #27
 *   @0x15d9fc mulseq lr, r12, sp
 *   @0x15da00 mulseq lr, r8, sp
 *   @0x15da04 mulseq lr, r4, sp
 *   @0x15da08 mulseq lr, r4, sp
 *   @0x15da0c mulseq lr, r8, sp
 *   @0x15da10 mulseq lr, r4, sp
 *   @0x15da14 mulseq lr, r4, sp
 *   @0x15da18 mulseq lr, r0, sp
 *   @0x15da1c andseq r11, lr, r8, lsl #27
 *   @0x15da20 andseq r11, lr, r4, lsl #27
 *   @0x15da24 andseq r11, lr, r4, lsl #27
 *   @0x15da28 andseq r11, lr, r0, lsl #27
 *   @0x15da2c andseq r11, lr, r4, ror sp
 *   @0x15da30 andseq r11, lr, r0, ror sp
 *   @0x15da34 andseq r11, lr, r8, ror #26
 *   @0x15da38 andseq r11, lr, r0, ror #26
 *   @0x15da3c andseq r11, lr, r0, ror #26
 *   @0x15da40 andseq r11, lr, r8, asr sp
 *   @0x15da44 andseq r11, lr, r8, asr sp
 *   @0x15da48 andseq r11, lr, r8, asr sp
 *   @0x15da4c andseq r11, lr, r0, asr sp
 *   @0x15da50 andseq r11, lr, r12, asr #26
 *   @0x15da54 andseq r11, lr, r12, asr #26
 *   @0x15da58 andseq r11, lr, r8, asr #26
 *   @0x15da5c andseq r11, lr, r8, asr #26
 *   @0x15da60 andseq r11, lr, r12, asr #26
 *   @0x15da64 andseq r11, lr, r4, asr sp
 *   @0x15da68 andseq r11, lr, r4, asr sp
 *   @0x15da6c andseq r11, lr, r8, asr sp
 *   @0x15da70 andseq r11, lr, r0, ror #26
 *   @0x15da74 andseq r11, lr, r8, ror #26
 *   @0x15da78 andseq r11, lr, r8, ror #26
 *   @0x15da7c andseq r11, lr, r0, ror sp
 *   @0x15da80 andseq r11, lr, r4, lsl #27
 *   @0x15da84 andseq r11, lr, r12, lsl #27
 *   @0x15da88 mulseq lr, r8, sp
 *   @0x15da8c andseq r11, lr, r0, lsr #27
 *   @0x15da90 andseq r11, lr, r12, lsr #27
 *   @0x15da94 ldrheq r11, [lr], -r4
 *   @0x15da98 andseq r11, lr, r4, asr #27
 *   @0x15da9c andseq r11, lr, r12, asr #27
 *   @0x15daa0 andseq r11, lr, r0, ror #27
 *   @0x15daa4 andseq r11, lr, r12, ror #27
 *   @0x15daa8 andseq r11, lr, r4, ror #27
 *   @0x15daac andseq r11, lr, r0, ror #27
 *   @0x15dab0 ldrsbeq r11, [lr], -r8
 *   @0x15dab4 ldrsbeq r11, [lr], -r0
 *   @0x15dab8 andseq r11, lr, r4, asr #27
 *   @0x15dabc andseq r11, lr, r0, asr #27
 *   @0x15dac0 ldrheq r11, [lr], -r4
 *   @0x15dac4 andseq r11, lr, r12, lsr #27
 *   @0x15dac8 andseq r11, lr, r0, lsr #27
 *   @0x15dacc mulseq lr, r8, sp
 *   @0x15dad0 andseq r11, lr, r12, lsl #27
 *   @0x15dad4 andseq r11, lr, r8, lsl #27
 *   @0x15dad8 andseq r11, lr, r0, lsl #27
 *   @0x15dadc andseq r11, lr, r8, ror sp
 *   @0x15dae0 andseq r11, lr, r0, ror sp
 *   @0x15dae4 andseq r11, lr, r12, ror #26
 *   @0x15dae8 andseq r11, lr, r12, ror #26
 *   @0x15daec andseq r11, lr, r4, ror sp
 *   @0x15daf0 andseq r11, lr, r0, lsl #27
 *   @0x15daf4 andseq r11, lr, r4, lsl #27
 *   @0x15daf8 andseq r11, lr, r8, lsl #27
 *
 * ══ §8/12 ps_hints_apply  0x2f1400  size 2534  634 条（0x2f1400..0x2f1de6）
 * @func 0x2f1400 0x2f1de6  size 2534  634 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2e9c78+0x6464×3 / anon_2f0d1c+0x172×2 / ps_hints_apply+0x45c×2 / FT_DivFix×2 / TT_RunIns+0x62c / 0x830cd8 / 0x830cbc / 0x4bc5ac
 * 字段偏移 top8: 0x20×16 / 0x4×12 / 0x1c×12 / 0x10×12 / 0x24×9 / 0x14×9 / 0xc×7 / 0x98×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f1400 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2f1404 sub sp, #0x114
 *   @0x2f1408 mov r5, r1
 *   @0x2f140c str r2, [sp, #0x24]
 *   @0x2f1410 cmp r4, #0x0
 *   @0x2f1414 rfeib r1!
 *   @0x2f1418 blhs 0x2fd420 <TT_RunIns+0x62c>
 *   @0x2f141c beq.w 0x2f1ddc <ps_hints_apply+0x9dc>
 *   @0x2f1420 add r7, sp, #0x90
 *   @0x2f1424 movs r2, #0x80
 *   @0x2f1428 mov r0, r7
 *   @0x2f142c svcls #0x9e8c2
 *   @0x2f1430 movs r2, #0x0
 *   @0x2f1434 sxth r3, r4
 *   @0x2f1438 str r2, [sp]
 *   @0x2f143c str r7, [sp, #0xa0]
 *   @0x2f1440 ldr r0, [sp, #0x20]
 *   @0x2f1444 str r7, [sp, #0x38]
 *   @0x2f1448 bls 0x830cd8 <b2_toiTime+0xd7834>
 *   @0x2f144c str r0, [sp, #0x98]
 *   @0x2f1450 bne.w 0x2f1702 <ps_hints_apply+0x302>
 *   @0x2f1454 ldrsh.w r3, [r5]
 *   @0x2f1458 add r0, sp, #0x50
 *   @0x2f145c movs r1, #0x8
 *   @0x2f1460 ldr r0, [sp, #0x20]
 *   @0x2f1464 bls 0x830cbc <b2_toiTime+0xd7818>
 *   @0x2f1468 str r0, [sp, #0x9c]
 *   @0x2f146c bne.w 0x2f1702 <ps_hints_apply+0x302>
 *   @0x2f1470 ldrsh.w r3, [r5, #0x2]
 *   @0x2f1474 adds r0, #0x8
 *   @0x2f1478 mov r1, r2
 *   @0x2f147c str r3, [sp, #0x90]
 *   @0x2f1480 .word 0x93253000
 *   @0x2f1484 ldr r3, [sp, #0x94]
 *   @0x2f1488 addsmi r0, r10, #8, #18
 *   @0x2f148c bhs 0x2f14f2 <ps_hints_apply+0xf2>
 *   @0x2f1490 ldrsh.w lr, [r3, r2, lsl #1]
 *   @0x2f1494 add.w lr, lr, #0x1
 *   @0x2f1498 rsb r4, r1, lr
 *   @0x2f149c muls r1, r7, r1
 *   @0x2f14a0 stmdb r0, {r3, r4}
 *   @0x2f14a4 cbz r4, 0x2f14ea <ps_hints_apply+0xea>
 *   @0x2f14a8 .word 0xf1036c0e
 *   @0x2f14ac ldrmi r0, [r8], r8, lsr #20
 *   @0x2f14b0 sub.w r12, r12, #0x28
 *   @0x2f14b4 str.w r12, [r6, r1]
 *   @0x2f14b8 mov r12, r4
 *   @0x2f14bc .word 0xf1bc9008
 *   @0x2f14c0 andle r0, lr, r1, lsl #30
 *   @0x2f14c4 add.w r1, r8, #0x28
 *   @0x2f14c8 add.w r12, r12, #0xffffffff
 *   @0x2f14cc rsb r11, r3, r1
 *   @0x2f14d0 add r11, r10
 *   @0x2f14d4 .word 0xf84b1c24
 *   @0x2f14d8 strmi r8, [r8], r8, lsr #24
 *   @0x2f14dc str.w r9, [r1, #0x8]
 *   @0x2f14e0 b 0x2f14be <ps_hints_apply+0xbe>
 *   @0x2f14e4 .word 0xf8443404
 *   @0x2f14e8 andlo r3, r1, #36, #24
 *   @0x2f14ec adds r0, #0x8
 *   @0x2f14f0 b 0x2f1484 <ps_hints_apply+0x84>
 *   @0x2f14f4 .word 0xf04f9098
 *   @0x2f14f8 stmdavs pc!, {r11} ^
 *   @0x2f14fc add.w r4, r9, #0x28
 *   @0x2f1500 mov r6, r7
 *   @0x2f1504 cmp r8, r3
 *   @0x2f1508 ldr r3, [r4, #-40]
 *   @0x2f150c ldr r2, [r4, #-36]
 *   @0x2f1510 rsb r3, r9, r3
 *   @0x2f1514 ldr r1, [pc, #0x274]
 *   @0x2f1518 stmvs r10!, {r1, r8, r9, r11}
 *   @0x2f151c asrs r3, r3, #0x3
 *   @0x2f1520 movtmi r0, #0xbbeb
 *   @0x2f1524 ldrb.w r2, [r2, r8]
 *   @0x2f1528 mul r11, r1, r11
 *   @0x2f152c lsls r2, r2, #0x1f
 *   @0x2f1530 movpl r2, #0x1
 *   @0x2f1534 bl 0x4bc5ac <SrcVerts+0x195f0>
 *   @0x2f1538 ldmdavs r1!, {r0, r1, r6, r7, r9}
 *   @0x2f153c ldr.w r3, [r7, r3, lsl #3]
 *   @0x2f1540 ldr r2, [r2, #0x4]
 *   @0x2f1544 ldmdavs r3!, {r0, r10, r11} ^
 *   @0x2f1548 str.w r12, [sp, #0x18]
 *   @0x2f154c subs r3, r3, r2
 *   @0x2f1550 str r3, [sp, #0x1c]
 *   @0x2f1554 bl 0x2f01f0 <FT_Done_Memory+0x657c>
 *   @0x2f1558 add.w r1, r7, r11, lsl #3
 *   @0x2f155c uxtb.w r10, r0
 *   @0x2f1560 strb r10, [r4, #-20]
 *   @0x2f1564 ldr.w r0, [r7, r11, lsl #3]
 *   @0x2f1568 ldr r2, [r6]
 *   @0x2f156c ldr r0, [r1, #0x4]
 *   @0x2f1570 str r2, [sp, #0x14]
 *   @0x2f1574 ldrmi r0, [r0], -r0, lsl #22
 *   @0x2f1578 mov r1, r11
 *   @0x2f157c .word 0xf854fe39
 *   @0x2f1580 .word 0xf0111c1c
 *   @0x2f1584 sbclt r0, r0, #1, #30
 *   @0x2f1588 strb r0, [r4, #-19]
 *   @0x2f158c ldr r2, [sp, #0x14]
 *   @0x2f1590 ldr.w r12, [sp, #0x18]
 *   @0x2f1594 beq 0x2f15a0 <ps_hints_apply+0x1a0>
 *   @0x2f1598 .word 0xf8440102
 *   @0x2f159c ands r1, r3, r12, lsl r12
 *   @0x2f15a0 cmp r0, r10
 *   @0x2f15a4 smlabble pc, r10, r1, pc
 *   @0x2f15a8 cmp r1, #0x4
 *   @0x2f15ac ldr r3, [r4, #-28]
 *   @0x2f15b0 orr r3, r3, #0x2
 *   @0x2f15b4 str r3, [r4, #-28]
 *   @0x2f15b8 b 0x2f15c8 <ps_hints_apply+0x1c8>
 *   @0x2f15bc mov r0, r12
 *   @0x2f15c0 bl 0x2e5248 <ft_corner_is_flat>
 *   @0x2f15c4 cmp r0, #0x0
 *   @0x2f15c8 add.w r8, r8, #0x1
 *   @0x2f15cc adds r4, #0x28
 *   @0x2f15d0 b 0x2f1502 <ps_hints_apply+0x102>
 *   @0x2f15d4 add r0, sp, #0x90
 *   @0x2f15d8 str r5, [sp, #0xa4]
 *   @0x2f15dc bl 0x2f022e <FT_Done_Memory+0x65ba>
 *   @0x2f15e0 movs r7, #0x0
 *   @0x2f15e4 cmp r7, r3
 *   @0x2f15e8 ldr r3, [sp, #0x9c]
 *   @0x2f15ec ldmdavs r2, {r0, r1, r2, r6, r7, r9} ^
 *   @0x2f15f0 cmp r2, #0x3
 *   @0x2f15f4 ldr.w r6, [r3, r7, lsl #3]
 *   @0x2f15f8 mov r4, r6
 *   @0x2f15fc cmp r4, r6
 *   @0x2f1600 ldr r2, [r4, #0x1c]
 *   @0x2f1604 ldr r0, [r4, #0x20]
 *   @0x2f1608 subs.w r12, r2, r3
 *   @0x2f160c rsb r11, r1, r0
 *   @0x2f1610 beq 0x2f1616 <ps_hints_apply+0x216>
 *   @0x2f1614 b 0x2f163c <ps_hints_apply+0x23c>
 *   @0x2f1618 rscle r0, lr, r0, lsl #30
 *   @0x2f161c b 0x2f1612 <ps_hints_apply+0x212>
 *   @0x2f1620 ldr.w r3, [r9, #0x1c]
 *   @0x2f1624 ldr r0, [r5, #0x20]
 *   @0x2f1628 bl 0xfef756b0 <b2_toiTime+0xfffffffffe81c20c>
 *   @0x2f162c bl 0xff333e40 <b2_toiTime+0xfffffffffebda99c>
 *   @0x2f1630 .word 0xd1080800
 *   @0x2f1634 cmp.w r8, #0x0
 *   @0x2f1638 bne 0x2f1646 <ps_hints_apply+0x246>
 *   @0x2f163c ldr.w r9, [r5]
 *   @0x2f1640 cmp r9, r6
 *   @0x2f1644 b 0x2f16d6 <ps_hints_apply+0x2d6>
 *   @0x2f1648 mov r1, r11
 *   @0x2f164c mov r3, r8
 *   @0x2f1650 .word 0xf7f3c018
 *   @0x2f1654 .word 0xf8ddfdb7
 *   @0x2f1658 andls r12, sp, r8, lsl r0
 *   @0x2f165c cmp r0, #0x0
 *   @0x2f1660 str r5, [sp, #0x3c]
 *   @0x2f1664 mov.w r12, #0x0
 *   @0x2f1668 ldr r4, [r4, #0x4]
 *   @0x2f166c ldr r3, [r6, #0x1c]
 *   @0x2f1670 cmp r4, r0
 *   @0x2f1674 moveq.w r12, #0x1
 *   @0x2f1678 ldr r1, [r6, #0x20]
 *   @0x2f167c subs.w r11, r2, r3
 *   @0x2f1680 rsb r9, r1, r0
 *   @0x2f1684 bne 0x2f1690 <ps_hints_apply+0x290>
 *   @0x2f1688 .word 0xd1010f00
 *   @0x2f168c mov r6, r4
 *   @0x2f1690 mov r0, r10
 *   @0x2f1694 mov r2, r11
 *   @0x2f1698 str.w r12, [sp, #0x18]
 *   @0x2f169c bl 0x2e51c4 <ft_corner_orientation>
 *   @0x2f16a0 ldr.w r12, [sp, #0x18]
 *   @0x2f16a4 cmp r0, #0x0
 *   @0x2f16a8 ldr r1, [sp, #0x34]
 *   @0x2f16ac strle r0, [r10, #-0xf01]
 *   @0x2f16b0 ldr r3, [r5, #0xc]
 *   @0x2f16b4 rscvs r0, r11, r4, lsl #6
 *   @0x2f16b8 ldr r5, [r5, #0x4]
 *   @0x2f16bc bne 0x2f16b0 <ps_hints_apply+0x2b0>
 *   @0x2f16c0 orr r3, r3, #0x4
 *   @0x2f16c4 str r3, [r6, #0xc]
 *   @0x2f16c8 .word 0xd1040f00
 *   @0x2f16cc str r0, [sp, #0x34]
 *   @0x2f16d0 mov r10, r11
 *   @0x2f16d4 b 0x2f1662 <ps_hints_apply+0x262>
 *   @0x2f16d8 b 0x2f15e2 <ps_hints_apply+0x1e2>
 *   @0x2f16dc add r0, sp, #0xac
 *   @0x2f16e0 add.w r1, r7, #0x10
 *   @0x2f16e4 add.w r2, r7, #0x1c
 *   @0x2f16e8 bl 0x2f0e8e <FT_Done_Memory+0x721a>
 *   @0x2f16ec str r0, [sp, #0x50]
 *   @0x2f16f0 add r0, sp, #0xd4
 *   @0x2f16f4 .word 0xf1070134
 *   @0x2f16f8 blls 0x4f2000 <SrcVerts+0x4f044>
 *   @0x2f16fc bl 0x2f0e8e <FT_Done_Memory+0x721a>
 *   @0x2f1700 str r0, [sp, #0x50]
 *   @0x2f1704 str r7, [sp, #0x2c]
 *   @0x2f1708 ldr r4, [sp, #0xa0]
 *   @0x2f170c mov r1, r4
 *   @0x2f1710 stmdage r11!, {r1, r3, r4, r6, r7, r11, r12, sp, lr, pc}
 *   @0x2f1714 mov r1, r4
 *   @0x2f1718 .word 0x4620f8d6
 *   @0x2f171c ldr r1, [sp, #0x98]
 *   @0x2f1720 strtmi pc, [r0], -r10, lsl #28
 *   @0x2f1724 ldr r1, [sp, #0x9c]
 *   @0x2f1728 str r3, [sp, #0x98]
 *   @0x2f172c cmp r6, #4, #28
 *   @0x2f1730 ldr r3, [sp, #0xa8]
 *   @0x2f1734 .word 0xf8d370c8
 *   @0x2f1738 .word 0x970d3194
 *   @0x2f173c ldr r7, [sp, #0x24]
 *   @0x2f1740 str r3, [sp, #0x3c]
 *   @0x2f1744 .word 0xf7fe01a0
 *   @0x2f1748 cps #0x9
 *   @0x2f174c strmi r0, [r4], -r0, lsr #10
 *   @0x2f1750 bics r5, r5, #0x3f
 *   @0x2f1754 beq 0x2f1790 <ps_hints_apply+0x390>
 *   @0x2f1758 beq 0x2f1790 <ps_hints_apply+0x390>
 *   @0x2f175c mov r1, r5
 *   @0x2f1760 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2f1764 cmp r5, r4
 *   @0x2f1768 bge 0x2f177a <ps_hints_apply+0x37a>
 *   @0x2f176c stmdals sp, {r0, r4, r5, r8}
 *   @0x2f1770 blx 0x318d10 <__divsi3>
 *   @0x2f1774 ldr r1, [sp, #0x34]
 *   @0x2f1778 b 0x2f177c <ps_hints_apply+0x37c>
 *   @0x2f177c movs r3, #0x0
 *   @0x2f1780 str r3, [sp]
 *   @0x2f1784 bl 0x2f0444 <FT_Done_Memory+0x67d0>
 *   @0x2f1788 movs r7, #0x1
 *   @0x2f178c ldm r4!, {r0, r2, r3, r6, r7}
 *   @0x2f1790 ldr r7, [sp, #0x2c]
 *   @0x2f1794 movs r3, #0x1
 *   @0x2f1798 strb.w r3, [sp, #0x108]
 *   @0x2f179c subs r2, r7, #0x2
 *   @0x2f17a0 addsmi r3, r10, #1073741826
 *   @0x2f17a4 ite hi
 *   @0x2f17a8 movls r2, #0x1
 *   @0x2f17ac strb.w r2, [sp, #0x10a]
 *   @0x2f17b0 beq 0x2f17b8 <ps_hints_apply+0x3b8>
 *   @0x2f17b4 rsbs r3, r0, #0
 *   @0x2f17b8 ldr r7, [sp, #0x28]
 *   @0x2f17bc .word 0xf88d0a00
 *   @0x2f17c0 .word 0xf117310b
 *   @0x2f17c4 svcge #0x2b33ff
 *   @0x2f17c8 str r7, [sp, #0x20]
 *   @0x2f17cc movne r3, #0x1
 *   @0x2f17d0 stmdage r4!, {r2, r3, r8, r12, sp}
 *   @0x2f17d4 mov r1, r10
 *   @0x2f17d8 stcls p13, c15, [r5, #-168]!
 *   @0x2f17dc ldr r4, [sp, #0x9c]
 *   @0x2f17e0 cmp r3, r5
 *   @0x2f17e4 add.w r2, r4, r3, lsl #3
 *   @0x2f17e8 ldr.w r6, [r4, r3, lsl #3]
 *   @0x2f17ec ldr r2, [r2, #0x4]
 *   @0x2f17f0 mov r0, r6
 *   @0x2f17f4 cmp r0, r6
 *   @0x2f17f8 ldr r1, [r0, #0x1c]
 *   @0x2f17fc cmp r1, r2
 *   @0x2f1800 ldr r7, [r0, #0x4]
 *   @0x2f1804 mov r1, r2
 *   @0x2f1808 cmp r1, r7
 *   @0x2f180c ldr.w lr, [r1, #0x1c]
 *   @0x2f1810 ldr r6, [r2, #0x1c]
 *   @0x2f1814 beq 0x2f1806 <ps_hints_apply+0x406>
 *   @0x2f1818 cmp r0, r6
 *   @0x2f181c cmp lr, r6
 *   @0x2f1820 b 0x2f1834 <ps_hints_apply+0x434>
 *   @0x2f1824 ble 0x2f1834 <ps_hints_apply+0x434>
 *   @0x2f1828 orr r0, r0, #0x40
 *   @0x2f182c str r0, [r2, #0x10]
 *   @0x2f1830 cmp r2, r1
 *   @0x2f1834 ldr r0, [r1]
 *   @0x2f1838 b 0x2f1804 <ps_hints_apply+0x404>
 *   @0x2f183c b 0x2f17e0 <ps_hints_apply+0x3e0>
 *   @0x2f1840 ldr r2, [sp, #0x90]
 *   @0x2f1844 bhs 0x2f18a0 <ps_hints_apply+0x4a0>
 *   @0x2f1848 movs r1, #0x28
 *   @0x2f184c ldmdbvs r4, {r0, r1, r9, sp}
 *   @0x2f1850 lsls r1, r4, #0x19
 *   @0x2f1854 mov r1, r2
 *   @0x2f1858 cmp r1, r2
 *   @0x2f185c adds r3, #0x1
 *   @0x2f1860 ldr r5, [r2, #0x20]
 *   @0x2f1864 cmp r0, r5
 *   @0x2f1868 mov r6, r2
 *   @0x2f186c cmp r6, r2
 *   @0x2f1870 ldr r0, [r6, #0x20]
 *   @0x2f1874 beq 0x2f186a <ps_hints_apply+0x46a>
 *   @0x2f1878 mov r6, r2
 *   @0x2f187c ldr r0, [r1, #0x20]
 *   @0x2f1880 cmp r0, r1
 *   @0x2f1884 ldr r0, [r6, #0x20]
 *   @0x2f1888 ble 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f188c and r0, r5, r0, lsl #9
 *   @0x2f1890 ble 0x2f185c <ps_hints_apply+0x45c>
 *   @0x2f1894 cmp r0, r1
 *   @0x2f1898 orr r4, r4, #0x100
 *   @0x2f189c str r4, [r2, #0x10]
 *   @0x2f18a0 ldr r7, [sp, #0x20]
 *   @0x2f18a4 ldr r6, [r7, #0x8]
 *   @0x2f18a8 cbz r4, 0x2f18bc <ps_hints_apply+0x4bc>
 *   @0x2f18ac mov r1, r5
 *   @0x2f18b0 add r3, sp, #0x90
 *   @0x2f18b4 .word 0x3c01fc46
 *   @0x2f18b8 adds r6, #0x1c
 *   @0x2f18bc ldr r7, [sp, #0x20]
 *   @0x2f18c0 movs r0, #0x20
 *   @0x2f18c4 svclt #0x140f00
 *   @0x2f18c8 movne.w r8, #0x2
 *   @0x2f18cc moveq.w r8, #0x1
 *   @0x2f18d0 ldr r3, [r7, #0x20]
 *   @0x2f18d4 ldr r5, [r3, #0x8]
 *   @0x2f18d8 mla r3, r2, r10, r3
 *   @0x2f18dc ldr.w r1, [r3, #0xc8]
 *   @0x2f18e0 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f18e4 cmp r0, #0x1e
 *   @0x2f18e8 movlt r7, r0
 *   @0x2f18ec cmp r4, #0x1
 *   @0x2f18f0 ldr r3, [sp, #0x90]
 *   @0x2f18f4 beq 0x2f1962 <ps_hints_apply+0x562>
 *   @0x2f18f8 adds r5, #0x10
 *   @0x2f18fc addsmi r0, r3, #40, #18
 *   @0x2f1900 it hs
 *   @0x2f1904 ldr r6, [r5, #0xc]
 *   @0x2f1908 cmp r6, r2
 *   @0x2f190c movhs r6, r2
 *   @0x2f1910 bls 0x2f1934 <ps_hints_apply+0x534>
 *   @0x2f1914 subs r2, r6, r3
 *   @0x2f1918 str r2, [sp, #0x14]
 *   @0x2f191c strtmi r1, [r9], -r3, lsl #22
 *   @0x2f1920 bl 0x2f0154 <FT_Done_Memory+0x64e0>
 *   @0x2f1924 str.w r8, [sp]
 *   @0x2f1928 ldr r0, [sp, #0x20]
 *   @0x2f192c ldr r2, [sp, #0x14]
 *   @0x2f1930 bl 0x2f0266 <FT_Done_Memory+0x65f2>
 *   @0x2f1934 subs r4, #0x1
 *   @0x2f1938 cmp r4, #0x1
 *   @0x2f193c ldr r0, [sp, #0x20]
 *   @0x2f1940 ldr r5, [sp, #0x98]
 *   @0x2f1944 ldr r1, [r3, #0x8]
 *   @0x2f1948 .word 0xf8cdfc05
 *   @0x2f194c stmdals r8, {pc}
 *   @0x2f1950 mov r1, r5
 *   @0x2f1954 mov r3, r7
 *   @0x2f1958 and pc, r2, r6, lsl #25
 *   @0x2f195c mov r3, r6
 *   @0x2f1960 beq 0x2f193c <ps_hints_apply+0x53c>
 *   @0x2f1964 ldr r4, [sp, #0x98]
 *   @0x2f1968 mov r3, r4
 *   @0x2f196c ldr r1, [r3, #0x18]
 *   @0x2f1970 ldr r1, [r3, #0x10]
 *   @0x2f1974 itt pl
 *   @0x2f1978 tstvs r9, r0, lsl r1
 *   @0x2f197c subs r2, #0x1
 *   @0x2f1980 b 0x2f196a <ps_hints_apply+0x56a>
 *   @0x2f1984 andle r0, r6, r1, lsl #30
 *   @0x2f1988 ldr r3, [sp, #0xa8]
 *   @0x2f198c mla r3, r2, r10, r3
 *   @0x2f1990 ldr.w r6, [r3, #0xc8]
 *   @0x2f1994 b 0x2f1a72 <ps_hints_apply+0x672>
 *   @0x2f1998 mov r2, r4
 *   @0x2f199c add.w lr, r7, #0x3a0
 *   @0x2f19a0 cmp r1, #0x0
 *   @0x2f19a4 ldrsb.w r3, [r2, #0x14]
 *   @0x2f19a8 cmp r3, #0x2
 *   @0x2f19ac adds r3, #0x2
 *   @0x2f19b0 ldrsb.w r3, [r2, #0x15]
 *   @0x2f19b4 cmp r3, #0x2
 *   @0x2f19b8 adds r3, #0x2
 *   @0x2f19bc ldr r3, [r2, #0x10]
 *   @0x2f19c0 bmi 0x2f1a64 <ps_hints_apply+0x664>
 *   @0x2f19c4 ldr r3, [r2, #0x1c]
 *   @0x2f19c8 .word 0xf8d076d0
 *   @0x2f19cc movwlt r7, #0x719c
 *   @0x2f19d0 ldr r0, [r6, #0xc]
 *   @0x2f19d4 stmdals r9, {r0, r1, r10, r11}
 *   @0x2f19d8 ldr.w r8, [r0, #0x9b8]
 *   @0x2f19dc rsb.w r0, r8, #0x0
 *   @0x2f19e0 cmp r12, r0
 *   @0x2f19e4 ldr r0, [r6, #0x8]
 *   @0x2f19e8 cmp r3, r0
 *   @0x2f19ec ldr r0, [sp, #0x24]
 *   @0x2f19f0 .word 0xf1b889bc
 *   @0x2f19f4 .word 0xd1030f00
 *   @0x2f19f8 ldr.w r0, [r0, #0x9b4]
 *   @0x2f19fc cmp r12, r0
 *   @0x2f1a00 ldr r0, [r6, #0x18]
 *   @0x2f1a04 ldr r0, [r2, #0x10]
 *   @0x2f1a08 tstvs r0, r0, lsr r0
 *   @0x2f1a0c subs r7, #0x1
 *   @0x2f1a10 b 0x2f19ce <ps_hints_apply+0x5ce>
 *   @0x2f1a14 ldr.w r7, [r0, #0x3a0]
 *   @0x2f1a18 add.w r6, lr, r7, lsl #5
 *   @0x2f1a1c subs r6, #0x1c
 *   @0x2f1a20 ldr r0, [r6, #0x8]
 *   @0x2f1a24 stmdals r9, {r10, r11}
 *   @0x2f1a28 ldr.w r8, [r0, #0x9b8]
 *   @0x2f1a2c rsb.w r0, r8, #0x0
 *   @0x2f1a30 cmp r12, r0
 *   @0x2f1a34 ldr r0, [r6, #0xc]
 *   @0x2f1a38 addmi r0, r3, #0
 *   @0x2f1a3c blt 0x2f1a5e <ps_hints_apply+0x65e>
 *   @0x2f1a40 ldrb.w r8, [r0, #0x9bc]
 *   @0x2f1a44 cmp.w r8, #0x0
 *   @0x2f1a48 bne 0x2f1a52 <ps_hints_apply+0x652>
 *   @0x2f1a4c strmi r0, [r4, #0x9b4]
 *   @0x2f1a50 bge 0x2f1a5e <ps_hints_apply+0x65e>
 *   @0x2f1a54 str r0, [r2, #0x24]
 *   @0x2f1a58 orr r0, r0, #0x30
 *   @0x2f1a5c str r0, [r2, #0x10]
 *   @0x2f1a60 subs r6, #0x20
 *   @0x2f1a64 subs r1, #0x1
 *   @0x2f1a68 b 0x2f19a0 <ps_hints_apply+0x5a0>
 *   @0x2f1a6c cbnz r3, 0x2f1a78 <ps_hints_apply+0x678>
 *   @0x2f1a70 adds r4, #0x28
 *   @0x2f1a74 bne 0x2f1a6a <ps_hints_apply+0x66a>
 *   @0x2f1a78 ldr r2, [r4, #0x10]
 *   @0x2f1a7c tst.w r2, #0x200
 *   @0x2f1a80 bne 0x2f1a8a <ps_hints_apply+0x68a>
 *   @0x2f1a84 bpl 0x2f1a8e <ps_hints_apply+0x68e>
 *   @0x2f1a88 add r7, r3
 *   @0x2f1a8c b 0x2f1ab6 <ps_hints_apply+0x6b6>
 *   @0x2f1a90 ldr r2, [r3]
 *   @0x2f1a94 cmp r0, #0x0
 *   @0x2f1a98 ldr r2, [r3, #0x4]
 *   @0x2f1a9c blt 0x2f1aac <ps_hints_apply+0x6ac>
 *   @0x2f1aa0 subs r0, r0, r2
 *   @0x2f1aa4 mov r1, r6
 *   @0x2f1aa8 and pc, r2, r9, lsl r11
 *   @0x2f1aac ldr r1, [r3, #0xc]
 *   @0x2f1ab0 ldrtmi pc, [r8], #-2373
 *   @0x2f1ab4 str r0, [r4, #0x24]
 *   @0x2f1ab8 orr r3, r3, #0x20
 *   @0x2f1abc str r3, [r4, #0x10]
 *   @0x2f1ac0 ldr r3, [sp, #0xa8]
 *   @0x2f1ac4 ldr r4, [sp, #0x98]
 *   @0x2f1ac8 ldr r7, [sp, #0xa0]
 *   @0x2f1acc strtmi r3, [r2], -r10, lsl #6
 *   @0x2f1ad0 str r7, [sp, #0x48]
 *   @0x2f1ad4 blls 0xc11dfc <b2_toiTime+0x4b8958>
 *   @0x2f1ad8 mla r6, r6, r3, r4
 *   @0x2f1adc mov r3, r5
 *   @0x2f1ae0 bhs 0x2f1aee <ps_hints_apply+0x6ee>
 *   @0x2f1ae4 adds r2, #0x28
 *   @0x2f1ae8 it mi
 *   @0x2f1aec b 0x2f1ade <ps_hints_apply+0x6de>
 *   @0x2f1af0 beq.w 0x2f1c54 <ps_hints_apply+0x854>
 *   @0x2f1af4 cmp r3, #0x10
 *   @0x2f1af8 movs r0, #0x0
 *   @0x2f1afc str r0, [sp]
 *   @0x2f1b00 str r1, [sp, #0x4]
 *   @0x2f1b04 ldr r0, [sp, #0x48]
 *   @0x2f1b08 blls 0x830618 <b2_toiTime+0xd7174>
 *   @0x2f1b0c mov r5, r0
 *   @0x2f1b10 bne.w 0x2f1c54 <ps_hints_apply+0x854>
 *   @0x2f1b14 b 0x2f1b18 <ps_hints_apply+0x718>
 *   @0x2f1b18 mov r3, r4
 *   @0x2f1b1c adcsmi r0, r3, #0, #18
 *   @0x2f1b20 bhs 0x2f1b4e <ps_hints_apply+0x74e>
 *   @0x2f1b24 lsls r7, r2, #0x1b
 *   @0x2f1b28 add.w r0, r5, r9, lsl #2
 *   @0x2f1b2c cmp r0, r5
 *   @0x2f1b30 ldr r2, [r0, #-4]
 *   @0x2f1b34 ldr r1, [r3, #0x1c]
 *   @0x2f1b38 cmp r7, r1
 *   @0x2f1b3c str r3, [r0]
 *   @0x2f1b40 and r0, r2, r1, lsl #18
 *   @0x2f1b44 str r2, [r0], #-4
 *   @0x2f1b48 b 0x2f1b2c <ps_hints_apply+0x72c>
 *   @0x2f1b4c b 0x2f1b1e <ps_hints_apply+0x71e>
 *   @0x2f1b50 .word 0xf10b4b80
 *   @0x2f1b54 b 0x16c0b58 <b2_toiTime+0xf676b4>
 *   @0x2f1b58 bl 0x43498c <g_RomDisk+0x3d16c>
 *   @0x2f1b5c .word 0xf10b030b
 *   @0x2f1b60 strtmi r0, [r11], #2820
 *   @0x2f1b64 str r3, [sp, #0x40]
 *   @0x2f1b68 bhs 0x2f1c46 <ps_hints_apply+0x846>
 *   @0x2f1b6c lsls r0, r2, #0x1b
 *   @0x2f1b70 ldr r3, [r4, #0xc]
 *   @0x2f1b74 bpl 0x2f1b94 <ps_hints_apply+0x794>
 *   @0x2f1b78 stmdbhs r4, {r2, r4, r12}
 *   @0x2f1b7c beq 0x2f1c42 <ps_hints_apply+0x842>
 *   @0x2f1b80 addmi r0, r8, #21
 *   @0x2f1b84 bne 0x2f1c42 <ps_hints_apply+0x842>
 *   @0x2f1b88 bmi 0x2f1b8e <ps_hints_apply+0x78e>
 *   @0x2f1b8c bpl 0x2f1c42 <ps_hints_apply+0x842>
 *   @0x2f1b90 rscvs r0, r3, r2, lsl #6
 *   @0x2f1b94 movs r3, #0x0
 *   @0x2f1b98 beq 0x2f1ba6 <ps_hints_apply+0x7a6>
 *   @0x2f1b9c ldmibvs r1, {r0, r1, r5, sp} ^
 *   @0x2f1ba0 ldr r2, [r4, #0x1c]
 *   @0x2f1ba4 ble 0x2f1bbc <ps_hints_apply+0x7bc>
 *   @0x2f1ba8 ldr r3, [r5]
 *   @0x2f1bac ldr r2, [r4, #0x1c]
 *   @0x2f1bb0 ldr r7, [r3, #0x24]
 *   @0x2f1bb4 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1bb8 add r0, r7
 *   @0x2f1bbc adds r3, #0x1
 *   @0x2f1bc0 add.w r3, r3, #0x40000000
 *   @0x2f1bc4 mov r1, r11
 *   @0x2f1bc8 ldr.w lr, [r5, r3, lsl #2]
 *   @0x2f1bcc mov r3, r9
 *   @0x2f1bd0 ldr r2, [r1, #-4]!
 *   @0x2f1bd4 ldr r0, [r2, #0x1c]
 *   @0x2f1bd8 cmp r0, r2
 *   @0x2f1bdc subs r3, #0x1
 *   @0x2f1be0 cmp r3, r9
 *   @0x2f1be4 bne 0x2f1bfe <ps_hints_apply+0x7fe>
 *   @0x2f1be8 mov r1, r8
 *   @0x2f1bec ldr r2, [r3, #0x24]
 *   @0x2f1bf0 subs r0, r0, r3
 *   @0x2f1bf4 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1bf8 ldr r2, [sp, #0x14]
 *   @0x2f1bfc b 0x2f1c38 <ps_hints_apply+0x838>
 *   @0x2f1c00 .word 0xf8de1023
 *   @0x2f1c04 addsmi r3, r8, #28
 *   @0x2f1c08 bne 0x2f1c12 <ps_hints_apply+0x812>
 *   @0x2f1c0c rsbvs r3, r3, #36
 *   @0x2f1c10 b 0x2f1c3a <ps_hints_apply+0x83a>
 *   @0x2f1c14 ldr r1, [r1, #0x24]
 *   @0x2f1c18 bne 0x2f1c1e <ps_hints_apply+0x81e>
 *   @0x2f1c1c b 0x2f1c3a <ps_hints_apply+0x83a>
 *   @0x2f1c20 bne 0xff321cb8 <b2_toiTime+0xfffffffffebc8814>
 *   @0x2f1c24 subs r2, r2, r3
 *   @0x2f1c28 .word 0xf8cd0101
 *   @0x2f1c2c .word 0xf7f3c018
 *   @0x2f1c30 .word 0xf8ddf885
 *   @0x2f1c34 strbtmi r12, [r0], #-24
 *   @0x2f1c38 str r0, [r4, #0x24]
 *   @0x2f1c3c orr r3, r3, #0x20
 *   @0x2f1c40 str r3, [r4, #0x10]
 *   @0x2f1c44 b 0x2f1b66 <ps_hints_apply+0x766>
 *   @0x2f1c48 cmp r5, r7
 *   @0x2f1c4c ldr r0, [sp, #0x48]
 *   @0x2f1c50 bl 0x2e7336 <ft_mem_free>
 *   @0x2f1c54 ldr r3, [sp, #0xa8]
 *   @0x2f1c58 mla r3, r2, r10, r3
 *   @0x2f1c5c ldr r2, [sp, #0x94]
 *   @0x2f1c60 str r2, [sp, #0x28]
 *   @0x2f1c64 .word 0xf8d380c4
 *   @0x2f1c68 tstls r2, #200
 *   @0x2f1c6c ldr r3, [sp, #0x9c]
 *   @0x2f1c70 svcls #0xa0908
 *   @0x2f1c74 cmp r7, #0x0
 *   @0x2f1c78 ldr r6, [r9, #-8]
 *   @0x2f1c7c movs r3, #0x28
 *   @0x2f1c80 andhs r4, r0, r4, lsl #24
 *   @0x2f1c84 mov r7, r0
 *   @0x2f1c88 mla r4, r3, r4, r6
 *   @0x2f1c8c cmp r2, r4
 *   @0x2f1c90 ldr r1, [r2, #0x10]
 *   @0x2f1c94 bpl 0x2f1c9e <ps_hints_apply+0x89e>
 *   @0x2f1c98 it eq
 *   @0x2f1c9c adds r0, #0x1
 *   @0x2f1ca0 b 0x2f1c8c <ps_hints_apply+0x88c>
 *   @0x2f1ca4 str r7, [sp, #0x4c]
 *   @0x2f1ca8 bne 0x2f1cce <ps_hints_apply+0x8ce>
 *   @0x2f1cac mov r1, r8
 *   @0x2f1cb0 bl 0x2f00dc <FT_Done_Memory+0x6468>
 *   @0x2f1cb4 subs r5, r5, r0
 *   @0x2f1cb8 b 0x2f1cce <ps_hints_apply+0x8ce>
 *   @0x2f1cbc beq 0x2f1ccc <ps_hints_apply+0x8cc>
 *   @0x2f1cc0 mov r1, r8
 *   @0x2f1cc4 bls 0x7b04f8 <b2_toiTime+0x57054>
 *   @0x2f1cc8 add r0, r2
 *   @0x2f1ccc adds r6, #0x28
 *   @0x2f1cd0 blo 0x2f1cba <ps_hints_apply+0x8ba>
 *   @0x2f1cd4 ldr r1, [r7, #0x10]
 *   @0x2f1cd8 bpl 0x2f1ce6 <ps_hints_apply+0x8e6>
 *   @0x2f1cdc ldr r3, [sp, #0x4c]
 *   @0x2f1ce0 cmp r7, r3
 *   @0x2f1ce4 b 0x2f1d64 <ps_hints_apply+0x964>
 *   @0x2f1ce8 ldr r1, [r7, #0x10]
 *   @0x2f1cec bpl 0x2f1ce6 <ps_hints_apply+0x8e6>
 *   @0x2f1cf0 ldr r1, [r7, #0x1c]
 *   @0x2f1cf4 cmp r5, r1
 *   @0x2f1cf8 bgt 0x2f1d04 <ps_hints_apply+0x904>
 *   @0x2f1cfc subs r6, r1, r5
 *   @0x2f1d00 and r0, r4, r3, lsl #22
 *   @0x2f1d04 rsb r11, r3, r0
 *   @0x2f1d08 subs r6, r5, r1
 *   @0x2f1d0c mov r5, r1
 *   @0x2f1d10 ble 0x2f1d22 <ps_hints_apply+0x922>
 *   @0x2f1d14 mov r1, r6
 *   @0x2f1d18 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2f1d1c ldr r2, [sp, #0x14]
 *   @0x2f1d20 b 0x2f1d28 <ps_hints_apply+0x928>
 *   @0x2f1d24 tstls r0, #128, #6
 *   @0x2f1d28 ldr r2, [r2, #0x4]
 *   @0x2f1d2c ldr r0, [r2, #0x1c]
 *   @0x2f1d30 cmp r0, #0x0
 *   @0x2f1d34 mov r1, r8
 *   @0x2f1d38 cmp r0, r6
 *   @0x2f1d3c subs r0, r0, r6
 *   @0x2f1d40 str r2, [sp, #0x14]
 *   @0x2f1d44 ldrbmi pc, [r8], #-2507
 *   @0x2f1d48 b 0x2f1d54 <ps_hints_apply+0x954>
 *   @0x2f1d4c str r2, [sp, #0x14]
 *   @0x2f1d50 strtmi pc, [r0], #-2501
 *   @0x2f1d54 ldr r2, [sp, #0x14]
 *   @0x2f1d58 ldr r2, [r2, #0x4]
 *   @0x2f1d5c bne 0x2f1d2c <ps_hints_apply+0x92c>
 *   @0x2f1d60 cmp r7, r2
 *   @0x2f1d64 ldr r3, [sp, #0x28]
 *   @0x2f1d68 bllo 0x334190
 *   @0x2f1d6c str r3, [sp, #0x28]
 *   @0x2f1d70 ldr r1, [sp, #0xa4]
 *   @0x2f1d74 ldr r2, [r1, #0x4]
 *   @0x2f1d78 ldr r1, [sp, #0x90]
 *   @0x2f1d7c bhs 0x2f1dae <ps_hints_apply+0x9ae>
 *   @0x2f1d80 lsls r4, r7, #0x3
 *   @0x2f1d84 .word 0xd1020f00
 *   @0x2f1d88 str.w r1, [r2, r7, lsl #3]
 *   @0x2f1d8c b 0x2f1d92 <ps_hints_apply+0x992>
 *   @0x2f1d90 str r1, [r4, #0x4]
 *   @0x2f1d94 lsls r1, r1, #0x1b
 *   @0x2f1d98 ldrb r1, [r0, r7]
 *   @0x2f1d9c svclt #0x140f00
 *   @0x2f1da0 movne r4, #0x40
 *   @0x2f1da4 orrs r1, r4
 *   @0x2f1da8 adds r3, #0x28
 *   @0x2f1dac b 0x2f1d78 <ps_hints_apply+0x978>
 *   @0x2f1db0 cbz r7, 0x2f1dc2 <ps_hints_apply+0x9c2>
 *   @0x2f1db4 ldr r1, [sp, #0x34]
 *   @0x2f1db8 movs r3, #0x0
 *   @0x2f1dbc ldr r2, [sp, #0x3c]
 *   @0x2f1dc0 .word 0xf10afb41
 *   @0x2f1dc4 svcls #0x80a01
 *   @0x2f1dc8 cmp.w r10, #0x2
 *   @0x2f1dcc add.w r7, r7, #0x28
 *   @0x2f1dd0 str r7, [sp, #0x20]
 *   @0x2f1dd4 ldrbt r10, [r12], #3225
 *   @0x2f1dd8 str r4, [sp, #0x2c]
 *   @0x2f1ddc str r3, [sp, #0x2c]
 *   @0x2f1de0 add sp, #0x114
 *   @0x2f1de4 svclt #0x8ff0
 *
 * ══ §9/12 CDS_Grid::Shuffle()  0x20cd98  size 2504  626 条（0x20cd98..0x20d760）
 * @func 0x20cd98 0x20d760  size 2504  626 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UNLOCK_RVALUE_MUTEX()×11 / operator delete(void*)×11 / LOCK_RVALUE_MUTEX()×10 / YYFree(void const*)×10 / FREE_RValue__Pre(RValue*)×6 / YYRandom(int)×4 / GetContextStackTop()×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×3
 * 字段偏移 top8: 0x4×98 / 0x8×80 / 0xc×30 / 0x10×16 / 0x20×15 / 0x2c×8 / 0x18×7 / 0x28×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20cd98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x20cd9c mov r4, r0
 *   @0x20cda0 ldmib r0, {r0, r2}
 *   @0x20cda4 mov r5, #0
 *   @0x20cda8 sub sp, sp, #52
 *   @0x20cdac lsl r3, r0, #3
 *   @0x20cdb0 str r5, [sp, #0x20]
 *   @0x20cdb4 str r5, [sp, #0x24]
 *   @0x20cdb8 mul r3, r2, r3
 *   @0x20cdbc str r5, [sp, #0x28]
 *   @0x20cdc0 str r5, [sp, #0x2c]
 *   @0x20cdc4 cmp r3, r5
 *   @0x20cdc8 ble 0x20d0f8 <_ZN8CDS_Grid7ShuffleEv+0x360>
 *   @0x20cdcc add r2, sp, #32
 *   @0x20cdd0 mov r3, #1
 *   @0x20cdd4 str r2, [sp, #0x1c]
 *   @0x20cdd8 str r3, [sp, #0x14]
 *   @0x20cddc bl 0xc4600 <_Z8YYRandomi>
 *   @0x20cde0 mov r10, r0
 *   @0x20cde4 ldr r0, [r4, #0x4]
 *   @0x20cde8 bl 0xc4600 <_Z8YYRandomi>
 *   @0x20cdec mov r6, r0
 *   @0x20cdf0 ldr r0, [r4, #0x8]
 *   @0x20cdf4 bl 0xc4600 <_Z8YYRandomi>
 *   @0x20cdf8 mov r8, r0
 *   @0x20cdfc ldr r0, [r4, #0x8]
 *   @0x20ce00 bl 0xc4600 <_Z8YYRandomi>
 *   @0x20ce04 cmp r10, r6
 *   @0x20ce08 cmpeq r8, r0
 *   @0x20ce0c mov r7, r0
 *   @0x20ce10 beq 0x20d0d0 <_ZN8CDS_Grid7ShuffleEv+0x338>
 *   @0x20ce14 ldr r2, [r4, #0x4]
 *   @0x20ce18 ldr r0, [sp, #0x2c]
 *   @0x20ce1c ldr r11, [r4]
 *   @0x20ce20 mla r2, r2, r8, r10
 *   @0x20ce24 bic r1, r0, #-16777216
 *   @0x20ce28 cmp r1, #1
 *   @0x20ce2c add r9, r11, r2, lsl #4
 *   @0x20ce30 beq 0x20d2ac <_ZN8CDS_Grid7ShuffleEv+0x514>
 *   @0x20ce34 cmp r1, #2
 *   @0x20ce38 bne 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4>
 *   @0x20ce3c sub r0, r0, #1
 *   @0x20ce40 bic r0, r0, #-16777216
 *   @0x20ce44 bic r0, r0, #3
 *   @0x20ce48 cmp r0, #0
 *   @0x20ce4c beq 0x20d4b8 <_ZN8CDS_Grid7ShuffleEv+0x720>
 *   @0x20ce50 mov r0, #5
 *   @0x20ce54 str r5, [sp, #0x28]
 *   @0x20ce58 str r0, [sp, #0x2c]
 *   @0x20ce5c ldr r1, [r9, #0xc]
 *   @0x20ce60 ldr r0, [r9, #0x8]
 *   @0x20ce64 str r5, [sp, #0x20]
 *   @0x20ce68 str r1, [sp, #0x2c]
 *   @0x20ce6c ldr r1, [r9, #0xc]
 *   @0x20ce70 str r0, [sp, #0x28]
 *   @0x20ce74 bic r1, r1, #-16777216
 *   @0x20ce78 cmp r1, #14
 *   @0x20ce7c addls pc, pc, r1, lsl #2
 *   @0x20ce80 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ce84 b 0x20d25c <_ZN8CDS_Grid7ShuffleEv+0x4c4>
 *   @0x20ce88 b 0x20d244 <_ZN8CDS_Grid7ShuffleEv+0x4ac>
 *   @0x20ce8c b 0x20d214 <_ZN8CDS_Grid7ShuffleEv+0x47c>
 *   @0x20ce90 b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128>
 *   @0x20ce94 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ce98 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ce9c b 0x20d280 <_ZN8CDS_Grid7ShuffleEv+0x4e8>
 *   @0x20cea0 b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128>
 *   @0x20cea4 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20cea8 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ceac b 0x20d26c <_ZN8CDS_Grid7ShuffleEv+0x4d4>
 *   @0x20ceb0 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ceb4 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20ceb8 b 0x20d25c <_ZN8CDS_Grid7ShuffleEv+0x4c4>
 *   @0x20cebc b 0x20cec0 <_ZN8CDS_Grid7ShuffleEv+0x128>
 *   @0x20cec0 ldr r2, [r11, r2, lsl #4]
 *   @0x20cec4 str r2, [sp, #0x20]
 *   @0x20cec8 ldr r2, [r4, #0x4]
 *   @0x20cecc ldr r9, [r4]
 *   @0x20ced0 mla r1, r2, r8, r10
 *   @0x20ced4 mla r2, r2, r7, r6
 *   @0x20ced8 add r11, r9, r1, lsl #4
 *   @0x20cedc ldr r0, [r11, #0xc]
 *   @0x20cee0 str r2, [sp, #0x18]
 *   @0x20cee4 add r2, r9, r2, lsl #4
 *   @0x20cee8 sub r0, r0, #1
 *   @0x20ceec bic r0, r0, #-16777216
 *   @0x20cef0 bic r0, r0, #3
 *   @0x20cef4 cmp r0, #0
 *   @0x20cef8 beq 0x20d378 <_ZN8CDS_Grid7ShuffleEv+0x5e0>
 *   @0x20cefc str r5, [r11, #0x8]
 *   @0x20cf00 mov r3, #5
 *   @0x20cf04 str r3, [r11, #0xc]
 *   @0x20cf08 str r5, [r9, r1, lsl #4]
 *   @0x20cf0c ldr r1, [r4, #0x4]
 *   @0x20cf10 ldr r11, [r4]
 *   @0x20cf14 mla r3, r1, r8, r10
 *   @0x20cf18 add r10, r11, r3, lsl #4
 *   @0x20cf1c ldr r0, [r10, #0xc]
 *   @0x20cf20 bic r1, r0, #-16777216
 *   @0x20cf24 cmp r1, #1
 *   @0x20cf28 beq 0x20d2f0 <_ZN8CDS_Grid7ShuffleEv+0x558>
 *   @0x20cf2c cmp r1, #2
 *   @0x20cf30 bne 0x20cf54 <_ZN8CDS_Grid7ShuffleEv+0x1bc>
 *   @0x20cf34 sub r0, r0, #1
 *   @0x20cf38 bic r0, r0, #-16777216
 *   @0x20cf3c bic r0, r0, #3
 *   @0x20cf40 cmp r0, #0
 *   @0x20cf44 beq 0x20d4d8 <_ZN8CDS_Grid7ShuffleEv+0x740>
 *   @0x20cf48 mov r0, #5
 *   @0x20cf4c str r5, [r10, #0x8]
 *   @0x20cf50 str r0, [r10, #0xc]
 *   @0x20cf54 ldr r1, [r2, #0xc]
 *   @0x20cf58 ldr r0, [r2, #0x8]
 *   @0x20cf5c str r5, [r11, r3, lsl #4]
 *   @0x20cf60 str r1, [r10, #0xc]
 *   @0x20cf64 ldr r1, [r2, #0xc]
 *   @0x20cf68 str r0, [r10, #0x8]
 *   @0x20cf6c bic r1, r1, #-16777216
 *   @0x20cf70 cmp r1, #14
 *   @0x20cf74 addls pc, pc, r1, lsl #2
 *   @0x20cf78 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cf7c b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368>
 *   @0x20cf80 b 0x20d1f8 <_ZN8CDS_Grid7ShuffleEv+0x460>
 *   @0x20cf84 b 0x20d1c8 <_ZN8CDS_Grid7ShuffleEv+0x430>
 *   @0x20cf88 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220>
 *   @0x20cf8c b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cf90 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cf94 b 0x20d19c <_ZN8CDS_Grid7ShuffleEv+0x404>
 *   @0x20cf98 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220>
 *   @0x20cf9c b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cfa0 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cfa4 b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368>
 *   @0x20cfa8 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cfac b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20cfb0 b 0x20d100 <_ZN8CDS_Grid7ShuffleEv+0x368>
 *   @0x20cfb4 b 0x20cfb8 <_ZN8CDS_Grid7ShuffleEv+0x220>
 *   @0x20cfb8 ldr r1, [sp, #0x18]
 *   @0x20cfbc ldr r2, [r9, r1, lsl #4]
 *   @0x20cfc0 str r2, [r11, r3, lsl #4]
 *   @0x20cfc4 ldm r4, {r10, r11}
 *   @0x20cfc8 mla r11, r11, r7, r6
 *   @0x20cfcc add r9, r10, r11, lsl #4
 *   @0x20cfd0 ldr r3, [r9, #0xc]
 *   @0x20cfd4 sub r3, r3, #1
 *   @0x20cfd8 bic r3, r3, #-16777216
 *   @0x20cfdc bic r3, r3, #3
 *   @0x20cfe0 cmp r3, #0
 *   @0x20cfe4 beq 0x20d3a0 <_ZN8CDS_Grid7ShuffleEv+0x608>
 *   @0x20cfe8 str r5, [r9, #0x8]
 *   @0x20cfec mov r2, #5
 *   @0x20cff0 str r2, [r9, #0xc]
 *   @0x20cff4 str r5, [r10, r11, lsl #4]
 *   @0x20cff8 ldr r3, [r4, #0x4]
 *   @0x20cffc ldr r10, [r4]
 *   @0x20d000 mla r6, r3, r7, r6
 *   @0x20d004 add r9, r10, r6, lsl #4
 *   @0x20d008 ldr r2, [r9, #0xc]
 *   @0x20d00c bic r3, r2, #-16777216
 *   @0x20d010 cmp r3, #1
 *   @0x20d014 beq 0x20d348 <_ZN8CDS_Grid7ShuffleEv+0x5b0>
 *   @0x20d018 cmp r3, #2
 *   @0x20d01c bne 0x20d040 <_ZN8CDS_Grid7ShuffleEv+0x2a8>
 *   @0x20d020 sub r2, r2, #1
 *   @0x20d024 bic r2, r2, #-16777216
 *   @0x20d028 bic r2, r2, #3
 *   @0x20d02c cmp r2, #0
 *   @0x20d030 beq 0x20d4cc <_ZN8CDS_Grid7ShuffleEv+0x734>
 *   @0x20d034 mov r3, #5
 *   @0x20d038 str r5, [r9, #0x8]
 *   @0x20d03c str r3, [r9, #0xc]
 *   @0x20d040 ldr r3, [sp, #0x2c]
 *   @0x20d044 ldr r2, [sp, #0x28]
 *   @0x20d048 str r5, [r10, r6, lsl #4]
 *   @0x20d04c str r3, [r9, #0xc]
 *   @0x20d050 ldr r3, [sp, #0x2c]
 *   @0x20d054 str r2, [r9, #0x8]
 *   @0x20d058 bic r2, r3, #-16777216
 *   @0x20d05c cmp r2, #14
 *   @0x20d060 addls pc, pc, r2, lsl #2
 *   @0x20d064 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d068 b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380>
 *   @0x20d06c b 0x20d158 <_ZN8CDS_Grid7ShuffleEv+0x3c0>
 *   @0x20d070 b 0x20d12c <_ZN8CDS_Grid7ShuffleEv+0x394>
 *   @0x20d074 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c>
 *   @0x20d078 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d07c b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d080 b 0x20d174 <_ZN8CDS_Grid7ShuffleEv+0x3dc>
 *   @0x20d084 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c>
 *   @0x20d088 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d08c b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d090 b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380>
 *   @0x20d094 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d098 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d09c b 0x20d118 <_ZN8CDS_Grid7ShuffleEv+0x380>
 *   @0x20d0a0 b 0x20d0a4 <_ZN8CDS_Grid7ShuffleEv+0x30c>
 *   @0x20d0a4 ldr r2, [sp, #0x20]
 *   @0x20d0a8 str r2, [r10, r6, lsl #4]
 *   @0x20d0ac sub r3, r3, #1
 *   @0x20d0b0 bic r3, r3, #-16777216
 *   @0x20d0b4 bic r3, r3, #3
 *   @0x20d0b8 cmp r3, #0
 *   @0x20d0bc beq 0x20d394 <_ZN8CDS_Grid7ShuffleEv+0x5fc>
 *   @0x20d0c0 mov r0, #5
 *   @0x20d0c4 str r5, [sp, #0x28]
 *   @0x20d0c8 str r0, [sp, #0x2c]
 *   @0x20d0cc str r5, [sp, #0x20]
 *   @0x20d0d0 ldr r2, [sp, #0x14]
 *   @0x20d0d4 ldr r0, [r4, #0x4]
 *   @0x20d0d8 add r2, r2, #1
 *   @0x20d0dc str r2, [sp, #0x14]
 *   @0x20d0e0 ldr r2, [r4, #0x8]
 *   @0x20d0e4 lsl r3, r0, #3
 *   @0x20d0e8 mul r3, r2, r3
 *   @0x20d0ec ldr r2, [sp, #0x14]
 *   @0x20d0f0 cmp r3, r2
 *   @0x20d0f4 bge 0x20cddc <_ZN8CDS_Grid7ShuffleEv+0x44>
 *   @0x20d0f8 add sp, sp, #52
 *   @0x20d0fc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x20d100 ldr r0, [sp, #0x18]
 *   @0x20d104 ldr r2, [r2, #0x4]
 *   @0x20d108 ldr r1, [r9, r0, lsl #4]
 *   @0x20d10c str r1, [r11, r3, lsl #4]
 *   @0x20d110 str r2, [r10, #0x4]
 *   @0x20d114 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20d118 ldr r1, [sp, #0x20]
 *   @0x20d11c ldr r2, [sp, #0x24]
 *   @0x20d120 str r1, [r10, r6, lsl #4]
 *   @0x20d124 str r2, [r9, #0x4]
 *   @0x20d128 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d12c ldr r2, [sp, #0x20]
 *   @0x20d130 cmp r2, #0
 *   @0x20d134 str r2, [r10, r6, lsl #4]
 *   @0x20d138 beq 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d13c ldr r0, [r2, #0x8]
 *   @0x20d140 ldr r1, [r2]
 *   @0x20d144 cmp r0, #0
 *   @0x20d148 streq r9, [r2, #0x8]
 *   @0x20d14c add r1, r1, #1
 *   @0x20d150 str r1, [r2]
 *   @0x20d154 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d158 ldr r2, [sp, #0x20]
 *   @0x20d15c cmp r2, #0
 *   @0x20d160 ldrne r3, [r2, #0x4]
 *   @0x20d164 addne r3, r3, #1
 *   @0x20d168 strne r3, [r2, #0x4]
 *   @0x20d16c ldrne r3, [sp, #0x2c]
 *   @0x20d170 b 0x20d0a8 <_ZN8CDS_Grid7ShuffleEv+0x310>
 *   @0x20d174 ldr r2, [sp, #0x20]
 *   @0x20d178 str r2, [r10, r6, lsl #4]
 *   @0x20d17c ldr r2, [sp, #0x20]
 *   @0x20d180 cmp r2, #0
 *   @0x20d184 beq 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d188 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20d18c ldr r1, [sp, #0x20]
 *   @0x20d190 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20d194 ldr r3, [sp, #0x2c]
 *   @0x20d198 b 0x20d0ac <_ZN8CDS_Grid7ShuffleEv+0x314>
 *   @0x20d19c ldr r1, [sp, #0x18]
 *   @0x20d1a0 ldr r2, [r9, r1, lsl #4]
 *   @0x20d1a4 str r2, [r11, r3, lsl #4]
 *   @0x20d1a8 ldr r3, [r9, r1, lsl #4]
 *   @0x20d1ac cmp r3, #0
 *   @0x20d1b0 beq 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20d1b4 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20d1b8 ldr r2, [sp, #0x18]
 *   @0x20d1bc ldr r1, [r9, r2, lsl #4]
 *   @0x20d1c0 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20d1c4 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20d1c8 ldr r1, [sp, #0x18]
 *   @0x20d1cc ldr r2, [r9, r1, lsl #4]
 *   @0x20d1d0 cmp r2, #0
 *   @0x20d1d4 str r2, [r11, r3, lsl #4]
 *   @0x20d1d8 beq 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20d1dc ldr r1, [r2, #0x8]
 *   @0x20d1e0 ldr r3, [r2]
 *   @0x20d1e4 cmp r1, #0
 *   @0x20d1e8 streq r10, [r2, #0x8]
 *   @0x20d1ec add r3, r3, #1
 *   @0x20d1f0 str r3, [r2]
 *   @0x20d1f4 b 0x20cfc4 <_ZN8CDS_Grid7ShuffleEv+0x22c>
 *   @0x20d1f8 ldr r1, [sp, #0x18]
 *   @0x20d1fc ldr r2, [r9, r1, lsl #4]
 *   @0x20d200 cmp r2, #0
 *   @0x20d204 ldrne r1, [r2, #0x4]
 *   @0x20d208 addne r1, r1, #1
 *   @0x20d20c strne r1, [r2, #0x4]
 *   @0x20d210 b 0x20cfc0 <_ZN8CDS_Grid7ShuffleEv+0x228>
 *   @0x20d214 ldr r2, [r11, r2, lsl #4]
 *   @0x20d218 cmp r2, #0
 *   @0x20d21c str r2, [sp, #0x20]
 *   @0x20d220 beq 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d224 ldr r0, [r2, #0x8]
 *   @0x20d228 ldr r1, [r2]
 *   @0x20d22c cmp r0, #0
 *   @0x20d230 add r1, r1, #1
 *   @0x20d234 str r1, [r2]
 *   @0x20d238 addeq r1, sp, #32
 *   @0x20d23c streq r1, [r2, #0x8]
 *   @0x20d240 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d244 ldr r2, [r11, r2, lsl #4]
 *   @0x20d248 cmp r2, #0
 *   @0x20d24c ldrne r1, [r2, #0x4]
 *   @0x20d250 addne r1, r1, #1
 *   @0x20d254 strne r1, [r2, #0x4]
 *   @0x20d258 b 0x20cec4 <_ZN8CDS_Grid7ShuffleEv+0x12c>
 *   @0x20d25c ldr r0, [r11, r2, lsl #4]
 *   @0x20d260 ldr r1, [r9, #0x4]
 *   @0x20d264 strd r0, r1, [sp, #32]
 *   @0x20d268 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d26c ldr r1, [r11, r2, lsl #4]
 *   @0x20d270 ldr r2, [r9, #0x4]
 *   @0x20d274 str r1, [sp, #0x20]
 *   @0x20d278 str r2, [sp, #0x24]
 *   @0x20d27c b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d280 ldr r1, [r11, r2, lsl #4]
 *   @0x20d284 str r1, [sp, #0x20]
 *   @0x20d288 ldr r1, [r11, r2, lsl #4]
 *   @0x20d28c cmp r1, #0
 *   @0x20d290 beq 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d294 str r2, [sp, #0x4]
 *   @0x20d298 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20d29c ldr r2, [sp, #0x4]
 *   @0x20d2a0 ldr r1, [r11, r2, lsl #4]
 *   @0x20d2a4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20d2a8 b 0x20cec8 <_ZN8CDS_Grid7ShuffleEv+0x130>
 *   @0x20d2ac ldr r1, [sp, #0x20]
 *   @0x20d2b0 cmp r1, #0
 *   @0x20d2b4 beq 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4>
 *   @0x20d2b8 str r1, [sp, #0x8]
 *   @0x20d2bc str r2, [sp, #0x4]
 *   @0x20d2c0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d2c4 ldr r1, [sp, #0x8]
 *   @0x20d2c8 ldr r2, [sp, #0x4]
 *   @0x20d2cc ldr r12, [r1, #0x4]
 *   @0x20d2d0 sub r12, r12, #1
 *   @0x20d2d4 str r12, [r1, #0x4]
 *   @0x20d2d8 cmp r12, #0
 *   @0x20d2dc beq 0x20d3ac <_ZN8CDS_Grid7ShuffleEv+0x614>
 *   @0x20d2e0 str r2, [sp, #0x4]
 *   @0x20d2e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d2e8 ldr r2, [sp, #0x4]
 *   @0x20d2ec b 0x20ce5c <_ZN8CDS_Grid7ShuffleEv+0xc4>
 *   @0x20d2f0 ldr r1, [r11, r3, lsl #4]
 *   @0x20d2f4 cmp r1, #0
 *   @0x20d2f8 beq 0x20d340 <_ZN8CDS_Grid7ShuffleEv+0x5a8>
 *   @0x20d2fc str r1, [sp, #0x8]
 *   @0x20d300 str r2, [sp, #0x4]
 *   @0x20d304 str r3, [sp, #0xc]
 *   @0x20d308 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d30c ldr r1, [sp, #0x8]
 *   @0x20d310 ldr r2, [sp, #0x4]
 *   @0x20d314 ldr r3, [sp, #0xc]
 *   @0x20d318 ldr r12, [r1, #0x4]
 *   @0x20d31c sub r12, r12, #1
 *   @0x20d320 str r12, [r1, #0x4]
 *   @0x20d324 cmp r12, #0
 *   @0x20d328 beq 0x20d410 <_ZN8CDS_Grid7ShuffleEv+0x678>
 *   @0x20d32c str r2, [sp, #0x4]
 *   @0x20d330 str r3, [sp, #0xc]
 *   @0x20d334 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d338 ldr r3, [sp, #0xc]
 *   @0x20d33c ldr r2, [sp, #0x4]
 *   @0x20d340 str r5, [r11, r3, lsl #4]
 *   @0x20d344 b 0x20cf54 <_ZN8CDS_Grid7ShuffleEv+0x1bc>
 *   @0x20d348 ldr r7, [r10, r6, lsl #4]
 *   @0x20d34c cmp r7, #0
 *   @0x20d350 beq 0x20d370 <_ZN8CDS_Grid7ShuffleEv+0x5d8>
 *   @0x20d354 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d358 ldr r11, [r7, #0x4]
 *   @0x20d35c sub r11, r11, #1
 *   @0x20d360 str r11, [r7, #0x4]
 *   @0x20d364 cmp r11, #0
 *   @0x20d368 beq 0x20d480 <_ZN8CDS_Grid7ShuffleEv+0x6e8>
 *   @0x20d36c bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d370 str r5, [r10, r6, lsl #4]
 *   @0x20d374 b 0x20d040 <_ZN8CDS_Grid7ShuffleEv+0x2a8>
 *   @0x20d378 mov r0, r11
 *   @0x20d37c str r1, [sp, #0x8]
 *   @0x20d380 str r2, [sp, #0x4]
 *   @0x20d384 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d388 ldr r2, [sp, #0x4]
 *   @0x20d38c ldr r1, [sp, #0x8]
 *   @0x20d390 b 0x20cefc <_ZN8CDS_Grid7ShuffleEv+0x164>
 *   @0x20d394 add r0, sp, #32
 *   @0x20d398 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d39c b 0x20d0c0 <_ZN8CDS_Grid7ShuffleEv+0x328>
 *   @0x20d3a0 mov r0, r9
 *   @0x20d3a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d3a8 b 0x20cfe8 <_ZN8CDS_Grid7ShuffleEv+0x250>
 *   @0x20d3ac ldr r0, [r1]
 *   @0x20d3b0 str r1, [sp, #0x8]
 *   @0x20d3b4 str r12, [sp, #0x10]
 *   @0x20d3b8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d3bc ldr r1, [sp, #0x8]
 *   @0x20d3c0 ldr r12, [sp, #0x10]
 *   @0x20d3c4 str r12, [r1]
 *   @0x20d3c8 str r12, [r1, #0x8]
 *   @0x20d3cc str r1, [sp, #0x8]
 *   @0x20d3d0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d3d4 ldr r1, [sp, #0x8]
 *   @0x20d3d8 ldr r2, [sp, #0x4]
 *   @0x20d3dc ldr r12, [r1, #0x4]
 *   @0x20d3e0 sub r12, r12, #1
 *   @0x20d3e4 str r12, [r1, #0x4]
 *   @0x20d3e8 cmp r12, #0
 *   @0x20d3ec beq 0x20d598 <_ZN8CDS_Grid7ShuffleEv+0x800>
 *   @0x20d3f0 str r2, [sp, #0x4]
 *   @0x20d3f4 str r1, [sp, #0x8]
 *   @0x20d3f8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d3fc ldr r1, [sp, #0x8]
 *   @0x20d400 mov r0, r1
 *   @0x20d404 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d408 ldr r2, [sp, #0x4]
 *   @0x20d40c b 0x20d2e0 <_ZN8CDS_Grid7ShuffleEv+0x548>
 *   @0x20d410 ldr r0, [r1]
 *   @0x20d414 str r1, [sp, #0x8]
 *   @0x20d418 str r12, [sp, #0x10]
 *   @0x20d41c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d420 ldr r1, [sp, #0x8]
 *   @0x20d424 ldr r12, [sp, #0x10]
 *   @0x20d428 str r12, [r1]
 *   @0x20d42c str r12, [r1, #0x8]
 *   @0x20d430 str r1, [sp, #0x8]
 *   @0x20d434 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d438 ldr r1, [sp, #0x8]
 *   @0x20d43c ldr r2, [sp, #0x4]
 *   @0x20d440 ldr r3, [sp, #0xc]
 *   @0x20d444 ldr r12, [r1, #0x4]
 *   @0x20d448 sub r12, r12, #1
 *   @0x20d44c str r12, [r1, #0x4]
 *   @0x20d450 cmp r12, #0
 *   @0x20d454 beq 0x20d524 <_ZN8CDS_Grid7ShuffleEv+0x78c>
 *   @0x20d458 str r2, [sp, #0x4]
 *   @0x20d45c str r3, [sp, #0xc]
 *   @0x20d460 str r1, [sp, #0x8]
 *   @0x20d464 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d468 ldr r1, [sp, #0x8]
 *   @0x20d46c mov r0, r1
 *   @0x20d470 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d474 ldr r3, [sp, #0xc]
 *   @0x20d478 ldr r2, [sp, #0x4]
 *   @0x20d47c b 0x20d32c <_ZN8CDS_Grid7ShuffleEv+0x594>
 *   @0x20d480 ldr r0, [r7]
 *   @0x20d484 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d488 str r11, [r7]
 *   @0x20d48c str r11, [r7, #0x8]
 *   @0x20d490 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d494 ldr r11, [r7, #0x4]
 *   @0x20d498 sub r11, r11, #1
 *   @0x20d49c str r11, [r7, #0x4]
 *   @0x20d4a0 cmp r11, #0
 *   @0x20d4a4 beq 0x20d4f4 <_ZN8CDS_Grid7ShuffleEv+0x75c>
 *   @0x20d4a8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d4ac mov r0, r7
 *   @0x20d4b0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d4b4 b 0x20d36c <_ZN8CDS_Grid7ShuffleEv+0x5d4>
 *   @0x20d4b8 add r0, sp, #32
 *   @0x20d4bc str r2, [sp, #0x4]
 *   @0x20d4c0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d4c4 ldr r2, [sp, #0x4]
 *   @0x20d4c8 b 0x20ce50 <_ZN8CDS_Grid7ShuffleEv+0xb8>
 *   @0x20d4cc mov r0, r9
 *   @0x20d4d0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d4d4 b 0x20d034 <_ZN8CDS_Grid7ShuffleEv+0x29c>
 *   @0x20d4d8 mov r0, r10
 *   @0x20d4dc str r2, [sp, #0x4]
 *   @0x20d4e0 str r3, [sp, #0xc]
 *   @0x20d4e4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20d4e8 ldr r3, [sp, #0xc]
 *   @0x20d4ec ldr r2, [sp, #0x4]
 *   @0x20d4f0 b 0x20cf48 <_ZN8CDS_Grid7ShuffleEv+0x1b0>
 *   @0x20d4f4 ldr r0, [r7]
 *   @0x20d4f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d4fc mov r0, r7
 *   @0x20d500 str r11, [r7]
 *   @0x20d504 str r11, [r7, #0x8]
 *   @0x20d508 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20d50c mov r0, r7
 *   @0x20d510 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d514 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d518 mov r0, r7
 *   @0x20d51c bl 0x27d1d0 <_ZdlPv>
 *   @0x20d520 b 0x20d36c <_ZN8CDS_Grid7ShuffleEv+0x5d4>
 *   @0x20d524 ldr r0, [r1]
 *   @0x20d528 str r1, [sp, #0x8]
 *   @0x20d52c str r12, [sp, #0x10]
 *   @0x20d530 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d534 ldr r1, [sp, #0x8]
 *   @0x20d538 ldr r12, [sp, #0x10]
 *   @0x20d53c str r12, [r1]
 *   @0x20d540 str r12, [r1, #0x8]
 *   @0x20d544 str r1, [sp, #0x8]
 *   @0x20d548 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d54c ldr r1, [sp, #0x8]
 *   @0x20d550 ldr r2, [sp, #0x4]
 *   @0x20d554 ldr r3, [sp, #0xc]
 *   @0x20d558 ldr r12, [r1, #0x4]
 *   @0x20d55c sub r12, r12, #1
 *   @0x20d560 str r12, [r1, #0x4]
 *   @0x20d564 cmp r12, #0
 *   @0x20d568 beq 0x20d600 <_ZN8CDS_Grid7ShuffleEv+0x868>
 *   @0x20d56c str r2, [sp, #0x4]
 *   @0x20d570 str r3, [sp, #0xc]
 *   @0x20d574 str r1, [sp, #0x8]
 *   @0x20d578 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d57c ldr r1, [sp, #0x8]
 *   @0x20d580 mov r0, r1
 *   @0x20d584 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d588 ldr r3, [sp, #0xc]
 *   @0x20d58c ldr r2, [sp, #0x4]
 *   @0x20d590 ldr r1, [sp, #0x8]
 *   @0x20d594 b 0x20d458 <_ZN8CDS_Grid7ShuffleEv+0x6c0>
 *   @0x20d598 ldr r0, [r1]
 *   @0x20d59c str r1, [sp, #0x8]
 *   @0x20d5a0 str r12, [sp, #0x10]
 *   @0x20d5a4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d5a8 ldr r1, [sp, #0x8]
 *   @0x20d5ac ldr r12, [sp, #0x10]
 *   @0x20d5b0 str r12, [r1]
 *   @0x20d5b4 str r12, [r1, #0x8]
 *   @0x20d5b8 str r1, [sp, #0x8]
 *   @0x20d5bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d5c0 ldr r1, [sp, #0x8]
 *   @0x20d5c4 ldr r2, [sp, #0x4]
 *   @0x20d5c8 ldr r12, [r1, #0x4]
 *   @0x20d5cc sub r12, r12, #1
 *   @0x20d5d0 str r12, [r1, #0x4]
 *   @0x20d5d4 cmp r12, #0
 *   @0x20d5d8 beq 0x20d6b8 <_ZN8CDS_Grid7ShuffleEv+0x920>
 *   @0x20d5dc str r2, [sp, #0x4]
 *   @0x20d5e0 str r1, [sp, #0x8]
 *   @0x20d5e4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d5e8 ldr r1, [sp, #0x8]
 *   @0x20d5ec mov r0, r1
 *   @0x20d5f0 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d5f4 ldr r2, [sp, #0x4]
 *   @0x20d5f8 ldr r1, [sp, #0x8]
 *   @0x20d5fc b 0x20d3f0 <_ZN8CDS_Grid7ShuffleEv+0x658>
 *   @0x20d600 ldr r0, [r1]
 *   @0x20d604 str r1, [sp, #0x8]
 *   @0x20d608 str r12, [sp, #0x10]
 *   @0x20d60c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d610 ldr r1, [sp, #0x8]
 *   @0x20d614 ldr r12, [sp, #0x10]
 *   @0x20d618 str r12, [r1]
 *   @0x20d61c str r12, [r1, #0x8]
 *   @0x20d620 str r1, [sp, #0x8]
 *   @0x20d624 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d628 ldr r1, [sp, #0x8]
 *   @0x20d62c ldr r2, [sp, #0x4]
 *   @0x20d630 ldr r3, [sp, #0xc]
 *   @0x20d634 ldr r12, [r1, #0x4]
 *   @0x20d638 sub r12, r12, #1
 *   @0x20d63c str r12, [r1, #0x4]
 *   @0x20d640 cmp r12, #0
 *   @0x20d644 bne 0x20d68c <_ZN8CDS_Grid7ShuffleEv+0x8f4>
 *   @0x20d648 ldr r0, [r1]
 *   @0x20d64c str r1, [sp, #0x8]
 *   @0x20d650 str r12, [sp, #0x10]
 *   @0x20d654 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d658 ldr r1, [sp, #0x8]
 *   @0x20d65c ldr r12, [sp, #0x10]
 *   @0x20d660 mov r0, r1
 *   @0x20d664 str r12, [r1]
 *   @0x20d668 str r12, [r1, #0x8]
 *   @0x20d66c str r1, [sp, #0x8]
 *   @0x20d670 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20d674 ldr r1, [sp, #0x8]
 *   @0x20d678 mov r0, r1
 *   @0x20d67c bl 0x27d1d0 <_ZdlPv>
 *   @0x20d680 ldr r3, [sp, #0xc]
 *   @0x20d684 ldr r2, [sp, #0x4]
 *   @0x20d688 ldr r1, [sp, #0x8]
 *   @0x20d68c str r2, [sp, #0x4]
 *   @0x20d690 str r3, [sp, #0xc]
 *   @0x20d694 str r1, [sp, #0x8]
 *   @0x20d698 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d69c ldr r1, [sp, #0x8]
 *   @0x20d6a0 mov r0, r1
 *   @0x20d6a4 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d6a8 ldr r3, [sp, #0xc]
 *   @0x20d6ac ldr r2, [sp, #0x4]
 *   @0x20d6b0 ldr r1, [sp, #0x8]
 *   @0x20d6b4 b 0x20d56c <_ZN8CDS_Grid7ShuffleEv+0x7d4>
 *   @0x20d6b8 ldr r0, [r1]
 *   @0x20d6bc str r1, [sp, #0x8]
 *   @0x20d6c0 str r12, [sp, #0x10]
 *   @0x20d6c4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d6c8 ldr r1, [sp, #0x8]
 *   @0x20d6cc ldr r12, [sp, #0x10]
 *   @0x20d6d0 str r12, [r1]
 *   @0x20d6d4 str r12, [r1, #0x8]
 *   @0x20d6d8 str r1, [sp, #0x8]
 *   @0x20d6dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x20d6e0 ldr r1, [sp, #0x8]
 *   @0x20d6e4 ldr r2, [sp, #0x4]
 *   @0x20d6e8 ldr r12, [r1, #0x4]
 *   @0x20d6ec sub r12, r12, #1
 *   @0x20d6f0 str r12, [r1, #0x4]
 *   @0x20d6f4 cmp r12, #0
 *   @0x20d6f8 bne 0x20d73c <_ZN8CDS_Grid7ShuffleEv+0x9a4>
 *   @0x20d6fc ldr r0, [r1]
 *   @0x20d700 str r1, [sp, #0x8]
 *   @0x20d704 str r12, [sp, #0x10]
 *   @0x20d708 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x20d70c ldr r1, [sp, #0x8]
 *   @0x20d710 ldr r12, [sp, #0x10]
 *   @0x20d714 mov r0, r1
 *   @0x20d718 str r12, [r1]
 *   @0x20d71c str r12, [r1, #0x8]
 *   @0x20d720 str r1, [sp, #0x8]
 *   @0x20d724 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x20d728 ldr r1, [sp, #0x8]
 *   @0x20d72c mov r0, r1
 *   @0x20d730 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d734 ldr r2, [sp, #0x4]
 *   @0x20d738 ldr r1, [sp, #0x8]
 *   @0x20d73c str r2, [sp, #0x4]
 *   @0x20d740 str r1, [sp, #0x8]
 *   @0x20d744 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x20d748 ldr r1, [sp, #0x8]
 *   @0x20d74c mov r0, r1
 *   @0x20d750 bl 0x27d1d0 <_ZdlPv>
 *   @0x20d754 ldr r2, [sp, #0x4]
 *   @0x20d758 ldr r1, [sp, #0x8]
 *   @0x20d75c b 0x20d5dc <_ZN8CDS_Grid7ShuffleEv+0x844>
 *
 * ══ §10/12 JS_DateObjectSetup()  0x246328  size 2456  614 条（0x246328..0x246cc0）
 * @func 0x246328 0x246cc0  size 2456  614 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x246338→0x756418, 0x246368→0x756420, 0x246378→0x756450, 0x246b5c→0x544be0
 * 调用序列: YYObjectBase::Add(char const*, YYObjectBase*, int)×48 / JS_SetupFunction(void (*)(RValue&, CInstance*, CInstance*, int, RValue*), int, bool)×47 / YYObjectBase::InternalGetYYVar(int)×3 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / JS_StandardBuiltInObjectConstructor(RValue&, CInstance*, CInstance*, int, RValue*)
 * 字段偏移 top8: 0x4×3 / 0x8×2 / 0x28×2 / 0x894×1 / 0x890×1 / 0x864×1 / 0x860×1 / 0x85c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x246328 push {r4, r5, r6, r7, r8, lr}
 *   @0x24632c sub sp, sp, #24
 *   @0x246330 ldr r7, [pc, #0x894]
 *   @0x246334 mov r6, #0
 *   @0x246338 ldr r12, [pc, #0x890]
 *   @0x24633c mov r1, r6
 *   @0x246340 add r7, pc, r7
 *   @0x246344 mov r2, r6
 *   @0x246348 mov r3, r6
 *   @0x24634c add r0, sp, #8
 *   @0x246350 ldr r12, [r7, r12]
 *   @0x246354 mvn r4, #0
 *   @0x246358 mvn r5, #-2147483648
 *   @0x24635c str r6, [sp]
 *   @0x246360 strd r4, r5, [r12]
 *   @0x246364 bl 0x23cabc <_Z35JS_StandardBuiltInObjectConstructorR6RValueP9CInstanceS2_iPS_>
 *   @0x246368 ldr r3, [pc, #0x864]
 *   @0x24636c ldr r4, [sp, #0x8]
 *   @0x246370 ldr r2, [pc, #0x860]
 *   @0x246374 ldr r8, [r7, r3]
 *   @0x246378 ldr r3, [pc, #0x85c]
 *   @0x24637c add r2, pc, r2
 *   @0x246380 str r2, [r4, #0x40]
 *   @0x246384 mov r0, r4
 *   @0x246388 str r4, [r8]
 *   @0x24638c ldr r3, [r7, r3]
 *   @0x246390 ldr r1, [r3]
 *   @0x246394 str r1, [r4, #0x18]
 *   @0x246398 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24639c ldr r3, [pc, #0x83c]
 *   @0x2463a0 ldr r0, [r4, #0x28]
 *   @0x2463a4 mov r1, r6
 *   @0x2463a8 mov r2, r6
 *   @0x2463ac orr r0, r0, #1
 *   @0x2463b0 str r0, [r4, #0x28]
 *   @0x2463b4 ldr r5, [r7, r3]
 *   @0x2463b8 mov r0, r5
 *   @0x2463bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2463c0 ldr r1, [pc, #0x81c]
 *   @0x2463c4 mov r3, #6
 *   @0x2463c8 add r1, pc, r1
 *   @0x2463cc mov r2, r0
 *   @0x2463d0 mov r0, r4
 *   @0x2463d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2463d8 mov r0, r5
 *   @0x2463dc mov r1, r6
 *   @0x2463e0 mov r2, r6
 *   @0x2463e4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2463e8 ldr r1, [pc, #0x7f8]
 *   @0x2463ec mov r3, #6
 *   @0x2463f0 add r1, pc, r1
 *   @0x2463f4 mov r2, r0
 *   @0x2463f8 mov r0, r4
 *   @0x2463fc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246400 mov r0, r5
 *   @0x246404 mov r1, r6
 *   @0x246408 mov r2, r6
 *   @0x24640c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246410 ldr r1, [pc, #0x7d4]
 *   @0x246414 mov r3, #6
 *   @0x246418 add r1, pc, r1
 *   @0x24641c mov r2, r0
 *   @0x246420 mov r0, r4
 *   @0x246424 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246428 mov r0, r5
 *   @0x24642c mov r1, r6
 *   @0x246430 mov r2, r6
 *   @0x246434 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246438 ldr r1, [pc, #0x7b0]
 *   @0x24643c mov r3, #6
 *   @0x246440 add r1, pc, r1
 *   @0x246444 mov r2, r0
 *   @0x246448 mov r0, r4
 *   @0x24644c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246450 mov r0, r5
 *   @0x246454 mov r1, r6
 *   @0x246458 mov r2, r6
 *   @0x24645c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246460 ldr r1, [pc, #0x78c]
 *   @0x246464 mov r3, #6
 *   @0x246468 add r1, pc, r1
 *   @0x24646c mov r2, r0
 *   @0x246470 mov r0, r4
 *   @0x246474 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246478 mov r0, r5
 *   @0x24647c mov r1, r6
 *   @0x246480 mov r2, r6
 *   @0x246484 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246488 ldr r1, [pc, #0x768]
 *   @0x24648c mov r3, #6
 *   @0x246490 add r1, pc, r1
 *   @0x246494 mov r2, r0
 *   @0x246498 mov r0, r4
 *   @0x24649c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2464a0 mov r0, r5
 *   @0x2464a4 mov r1, r6
 *   @0x2464a8 mov r2, r6
 *   @0x2464ac bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2464b0 ldr r1, [pc, #0x744]
 *   @0x2464b4 mov r3, #6
 *   @0x2464b8 add r1, pc, r1
 *   @0x2464bc mov r2, r0
 *   @0x2464c0 mov r0, r4
 *   @0x2464c4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2464c8 mov r0, r5
 *   @0x2464cc mov r1, r6
 *   @0x2464d0 mov r2, r6
 *   @0x2464d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2464d8 ldr r1, [pc, #0x720]
 *   @0x2464dc mov r3, #6
 *   @0x2464e0 add r1, pc, r1
 *   @0x2464e4 mov r2, r0
 *   @0x2464e8 mov r0, r4
 *   @0x2464ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2464f0 mov r0, r5
 *   @0x2464f4 mov r1, r6
 *   @0x2464f8 mov r2, r6
 *   @0x2464fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246500 ldr r1, [pc, #0x6fc]
 *   @0x246504 mov r3, #6
 *   @0x246508 add r1, pc, r1
 *   @0x24650c mov r2, r0
 *   @0x246510 mov r0, r4
 *   @0x246514 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246518 mov r0, r5
 *   @0x24651c mov r1, r6
 *   @0x246520 mov r2, r6
 *   @0x246524 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246528 ldr r1, [pc, #0x6d8]
 *   @0x24652c mov r3, #6
 *   @0x246530 add r1, pc, r1
 *   @0x246534 mov r2, r0
 *   @0x246538 mov r0, r4
 *   @0x24653c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246540 mov r0, r5
 *   @0x246544 mov r1, r6
 *   @0x246548 mov r2, r6
 *   @0x24654c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246550 ldr r1, [pc, #0x6b4]
 *   @0x246554 mov r3, #6
 *   @0x246558 add r1, pc, r1
 *   @0x24655c mov r2, r0
 *   @0x246560 mov r0, r4
 *   @0x246564 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246568 mov r0, r5
 *   @0x24656c mov r1, r6
 *   @0x246570 mov r2, r6
 *   @0x246574 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246578 ldr r1, [pc, #0x690]
 *   @0x24657c mov r3, #6
 *   @0x246580 add r1, pc, r1
 *   @0x246584 mov r2, r0
 *   @0x246588 mov r0, r4
 *   @0x24658c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246590 mov r0, r5
 *   @0x246594 mov r1, r6
 *   @0x246598 mov r2, r6
 *   @0x24659c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2465a0 ldr r1, [pc, #0x66c]
 *   @0x2465a4 mov r3, #6
 *   @0x2465a8 add r1, pc, r1
 *   @0x2465ac mov r2, r0
 *   @0x2465b0 mov r0, r4
 *   @0x2465b4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2465b8 mov r0, r5
 *   @0x2465bc mov r1, r6
 *   @0x2465c0 mov r2, r6
 *   @0x2465c4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2465c8 ldr r1, [pc, #0x648]
 *   @0x2465cc mov r3, #6
 *   @0x2465d0 add r1, pc, r1
 *   @0x2465d4 mov r2, r0
 *   @0x2465d8 mov r0, r4
 *   @0x2465dc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2465e0 mov r0, r5
 *   @0x2465e4 mov r1, r6
 *   @0x2465e8 mov r2, r6
 *   @0x2465ec bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2465f0 ldr r1, [pc, #0x624]
 *   @0x2465f4 mov r3, #6
 *   @0x2465f8 add r1, pc, r1
 *   @0x2465fc mov r2, r0
 *   @0x246600 mov r0, r4
 *   @0x246604 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246608 mov r0, r5
 *   @0x24660c mov r1, r6
 *   @0x246610 mov r2, r6
 *   @0x246614 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246618 ldr r1, [pc, #0x600]
 *   @0x24661c mov r3, #6
 *   @0x246620 add r1, pc, r1
 *   @0x246624 mov r2, r0
 *   @0x246628 mov r0, r4
 *   @0x24662c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246630 mov r0, r5
 *   @0x246634 mov r1, r6
 *   @0x246638 mov r2, r6
 *   @0x24663c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246640 ldr r1, [pc, #0x5dc]
 *   @0x246644 mov r3, #6
 *   @0x246648 add r1, pc, r1
 *   @0x24664c mov r2, r0
 *   @0x246650 mov r0, r4
 *   @0x246654 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246658 mov r0, r5
 *   @0x24665c mov r1, r6
 *   @0x246660 mov r2, r6
 *   @0x246664 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246668 ldr r1, [pc, #0x5b8]
 *   @0x24666c mov r3, #6
 *   @0x246670 add r1, pc, r1
 *   @0x246674 mov r2, r0
 *   @0x246678 mov r0, r4
 *   @0x24667c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246680 mov r0, r5
 *   @0x246684 mov r1, r6
 *   @0x246688 mov r2, r6
 *   @0x24668c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246690 ldr r1, [pc, #0x594]
 *   @0x246694 mov r3, #6
 *   @0x246698 add r1, pc, r1
 *   @0x24669c mov r2, r0
 *   @0x2466a0 mov r0, r4
 *   @0x2466a4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2466a8 mov r0, r5
 *   @0x2466ac mov r1, r6
 *   @0x2466b0 mov r2, r6
 *   @0x2466b4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2466b8 ldr r1, [pc, #0x570]
 *   @0x2466bc mov r3, #6
 *   @0x2466c0 add r1, pc, r1
 *   @0x2466c4 mov r2, r0
 *   @0x2466c8 mov r0, r4
 *   @0x2466cc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2466d0 mov r0, r5
 *   @0x2466d4 mov r1, r6
 *   @0x2466d8 mov r2, r6
 *   @0x2466dc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2466e0 ldr r1, [pc, #0x54c]
 *   @0x2466e4 mov r3, #6
 *   @0x2466e8 add r1, pc, r1
 *   @0x2466ec mov r2, r0
 *   @0x2466f0 mov r0, r4
 *   @0x2466f4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2466f8 mov r0, r5
 *   @0x2466fc mov r1, r6
 *   @0x246700 mov r2, r6
 *   @0x246704 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246708 ldr r1, [pc, #0x528]
 *   @0x24670c mov r3, #6
 *   @0x246710 add r1, pc, r1
 *   @0x246714 mov r2, r0
 *   @0x246718 mov r0, r4
 *   @0x24671c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246720 mov r0, r5
 *   @0x246724 mov r1, r6
 *   @0x246728 mov r2, r6
 *   @0x24672c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246730 ldr r1, [pc, #0x504]
 *   @0x246734 mov r3, #6
 *   @0x246738 add r1, pc, r1
 *   @0x24673c mov r2, r0
 *   @0x246740 mov r0, r4
 *   @0x246744 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246748 mov r0, r5
 *   @0x24674c mov r1, r6
 *   @0x246750 mov r2, r6
 *   @0x246754 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246758 ldr r1, [pc, #0x4e0]
 *   @0x24675c mov r3, #6
 *   @0x246760 add r1, pc, r1
 *   @0x246764 mov r2, r0
 *   @0x246768 mov r0, r4
 *   @0x24676c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246770 mov r0, r5
 *   @0x246774 mov r1, r6
 *   @0x246778 mov r2, r6
 *   @0x24677c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246780 ldr r1, [pc, #0x4bc]
 *   @0x246784 mov r3, #6
 *   @0x246788 add r1, pc, r1
 *   @0x24678c mov r2, r0
 *   @0x246790 mov r0, r4
 *   @0x246794 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246798 mov r0, r5
 *   @0x24679c mov r1, r6
 *   @0x2467a0 mov r2, r6
 *   @0x2467a4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2467a8 ldr r1, [pc, #0x498]
 *   @0x2467ac mov r3, #6
 *   @0x2467b0 add r1, pc, r1
 *   @0x2467b4 mov r2, r0
 *   @0x2467b8 mov r0, r4
 *   @0x2467bc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2467c0 mov r0, r5
 *   @0x2467c4 mov r1, r6
 *   @0x2467c8 mov r2, r6
 *   @0x2467cc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2467d0 ldr r1, [pc, #0x474]
 *   @0x2467d4 mov r3, #6
 *   @0x2467d8 add r1, pc, r1
 *   @0x2467dc mov r2, r0
 *   @0x2467e0 mov r0, r4
 *   @0x2467e4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2467e8 mov r0, r5
 *   @0x2467ec mov r1, r6
 *   @0x2467f0 mov r2, r6
 *   @0x2467f4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2467f8 ldr r1, [pc, #0x450]
 *   @0x2467fc mov r3, #6
 *   @0x246800 add r1, pc, r1
 *   @0x246804 mov r2, r0
 *   @0x246808 mov r0, r4
 *   @0x24680c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246810 mov r0, r5
 *   @0x246814 mov r1, r6
 *   @0x246818 mov r2, r6
 *   @0x24681c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246820 ldr r1, [pc, #0x42c]
 *   @0x246824 mov r3, #6
 *   @0x246828 add r1, pc, r1
 *   @0x24682c mov r2, r0
 *   @0x246830 mov r0, r4
 *   @0x246834 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246838 mov r0, r5
 *   @0x24683c mov r1, r6
 *   @0x246840 mov r2, r6
 *   @0x246844 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246848 ldr r1, [pc, #0x408]
 *   @0x24684c mov r3, #6
 *   @0x246850 add r1, pc, r1
 *   @0x246854 mov r2, r0
 *   @0x246858 mov r0, r4
 *   @0x24685c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246860 mov r0, r5
 *   @0x246864 mov r1, r6
 *   @0x246868 mov r2, r6
 *   @0x24686c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246870 ldr r1, [pc, #0x3e4]
 *   @0x246874 mov r3, #6
 *   @0x246878 add r1, pc, r1
 *   @0x24687c mov r2, r0
 *   @0x246880 mov r0, r4
 *   @0x246884 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246888 mov r0, r5
 *   @0x24688c mov r1, r6
 *   @0x246890 mov r2, r6
 *   @0x246894 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246898 ldr r1, [pc, #0x3c0]
 *   @0x24689c mov r3, #6
 *   @0x2468a0 add r1, pc, r1
 *   @0x2468a4 mov r2, r0
 *   @0x2468a8 mov r0, r4
 *   @0x2468ac bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2468b0 mov r0, r5
 *   @0x2468b4 mov r1, r6
 *   @0x2468b8 mov r2, r6
 *   @0x2468bc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2468c0 ldr r1, [pc, #0x39c]
 *   @0x2468c4 mov r3, #6
 *   @0x2468c8 add r1, pc, r1
 *   @0x2468cc mov r2, r0
 *   @0x2468d0 mov r0, r4
 *   @0x2468d4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2468d8 mov r0, r5
 *   @0x2468dc mov r1, r6
 *   @0x2468e0 mov r2, r6
 *   @0x2468e4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2468e8 ldr r1, [pc, #0x378]
 *   @0x2468ec mov r3, #6
 *   @0x2468f0 add r1, pc, r1
 *   @0x2468f4 mov r2, r0
 *   @0x2468f8 mov r0, r4
 *   @0x2468fc bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246900 mov r0, r5
 *   @0x246904 mov r1, r6
 *   @0x246908 mov r2, r6
 *   @0x24690c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246910 ldr r1, [pc, #0x354]
 *   @0x246914 mov r3, #6
 *   @0x246918 add r1, pc, r1
 *   @0x24691c mov r2, r0
 *   @0x246920 mov r0, r4
 *   @0x246924 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246928 mov r0, r5
 *   @0x24692c mov r1, r6
 *   @0x246930 mov r2, r6
 *   @0x246934 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246938 ldr r1, [pc, #0x330]
 *   @0x24693c mov r3, #6
 *   @0x246940 add r1, pc, r1
 *   @0x246944 mov r2, r0
 *   @0x246948 mov r0, r4
 *   @0x24694c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246950 mov r0, r5
 *   @0x246954 mov r1, r6
 *   @0x246958 mov r2, r6
 *   @0x24695c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246960 ldr r1, [pc, #0x30c]
 *   @0x246964 mov r3, #6
 *   @0x246968 add r1, pc, r1
 *   @0x24696c mov r2, r0
 *   @0x246970 mov r0, r4
 *   @0x246974 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246978 mov r0, r5
 *   @0x24697c mov r1, r6
 *   @0x246980 mov r2, r6
 *   @0x246984 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246988 ldr r1, [pc, #0x2e8]
 *   @0x24698c mov r3, #6
 *   @0x246990 add r1, pc, r1
 *   @0x246994 mov r2, r0
 *   @0x246998 mov r0, r4
 *   @0x24699c bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2469a0 mov r0, r5
 *   @0x2469a4 mov r1, r6
 *   @0x2469a8 mov r2, r6
 *   @0x2469ac bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2469b0 ldr r1, [pc, #0x2c4]
 *   @0x2469b4 mov r3, #6
 *   @0x2469b8 add r1, pc, r1
 *   @0x2469bc mov r2, r0
 *   @0x2469c0 mov r0, r4
 *   @0x2469c4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2469c8 mov r0, r5
 *   @0x2469cc mov r1, r6
 *   @0x2469d0 mov r2, r6
 *   @0x2469d4 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x2469d8 ldr r1, [pc, #0x2a0]
 *   @0x2469dc mov r3, #6
 *   @0x2469e0 add r1, pc, r1
 *   @0x2469e4 mov r2, r0
 *   @0x2469e8 mov r0, r4
 *   @0x2469ec bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x2469f0 mov r0, r5
 *   @0x2469f4 mov r1, r6
 *   @0x2469f8 mov r2, r6
 *   @0x2469fc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246a00 ldr r1, [pc, #0x27c]
 *   @0x246a04 mov r3, #6
 *   @0x246a08 add r1, pc, r1
 *   @0x246a0c mov r2, r0
 *   @0x246a10 mov r0, r4
 *   @0x246a14 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246a18 ldr r3, [pc, #0x268]
 *   @0x246a1c mov r1, r6
 *   @0x246a20 mov r2, r6
 *   @0x246a24 ldr r0, [r7, r3]
 *   @0x246a28 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246a2c ldr r1, [pc, #0x258]
 *   @0x246a30 mov r3, #6
 *   @0x246a34 add r1, pc, r1
 *   @0x246a38 mov r2, r0
 *   @0x246a3c mov r0, r4
 *   @0x246a40 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246a44 mov r0, r5
 *   @0x246a48 mov r1, r6
 *   @0x246a4c mov r2, r6
 *   @0x246a50 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246a54 ldr r1, [pc, #0x234]
 *   @0x246a58 mov r3, #6
 *   @0x246a5c add r1, pc, r1
 *   @0x246a60 mov r2, r0
 *   @0x246a64 mov r0, r4
 *   @0x246a68 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246a6c ldr r3, [pc, #0x220]
 *   @0x246a70 mov r2, r6
 *   @0x246a74 mov r1, #7
 *   @0x246a78 ldr r0, [r7, r3]
 *   @0x246a7c bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246a80 ldr r3, [pc, #0x210]
 *   @0x246a84 mov r1, r6
 *   @0x246a88 mov r2, r6
 *   @0x246a8c mov r5, r0
 *   @0x246a90 ldr r0, [pc, #0x204]
 *   @0x246a94 ldr r0, [r7, r0]
 *   @0x246a98 str r0, [r5, #0x94]
 *   @0x246a9c ldr r0, [r7, r3]
 *   @0x246aa0 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246aa4 ldr r1, [pc, #0x1f4]
 *   @0x246aa8 mov r3, r6
 *   @0x246aac add r1, pc, r1
 *   @0x246ab0 mov r2, r0
 *   @0x246ab4 mov r0, r5
 *   @0x246ab8 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246abc ldr r3, [pc, #0x1e0]
 *   @0x246ac0 mov r2, r6
 *   @0x246ac4 mov r1, #7
 *   @0x246ac8 ldr r0, [r7, r3]
 *   @0x246acc bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246ad0 ldr r1, [pc, #0x1d0]
 *   @0x246ad4 mov r3, r6
 *   @0x246ad8 add r1, pc, r1
 *   @0x246adc mov r2, r0
 *   @0x246ae0 mov r0, r5
 *   @0x246ae4 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246ae8 ldr r3, [pc, #0x1bc]
 *   @0x246aec mov r1, r6
 *   @0x246af0 mov r2, r6
 *   @0x246af4 ldr r0, [r7, r3]
 *   @0x246af8 bl 0x240f7c <_Z16JS_SetupFunctionPFvR6RValueP9CInstanceS2_iPS_Eib>
 *   @0x246afc ldr r1, [pc, #0x1ac]
 *   @0x246b00 mov r3, r6
 *   @0x246b04 add r1, pc, r1
 *   @0x246b08 mov r2, r0
 *   @0x246b0c mov r0, r5
 *   @0x246b10 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246b14 ldr r1, [pc, #0x198]
 *   @0x246b18 mov r3, r6
 *   @0x246b1c mov r0, r4
 *   @0x246b20 mov r2, r5
 *   @0x246b24 add r1, pc, r1
 *   @0x246b28 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246b2c ldr r3, [r5, #0x4]
 *   @0x246b30 cmp r3, r6
 *   @0x246b34 beq 0x246b8c <_Z18JS_DateObjectSetupv+0x864>
 *   @0x246b38 ldr r1, [r8]
 *   @0x246b3c mov r0, r5
 *   @0x246b40 str r1, [r3]
 *   @0x246b44 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x246b48 ldr r1, [r5, #0x4]
 *   @0x246b4c cmp r1, #0
 *   @0x246b50 movne r3, #6
 *   @0x246b54 strne r3, [r1, #0xc]
 *   @0x246b58 beq 0x246ba0 <_Z18JS_DateObjectSetupv+0x878>
 *   @0x246b5c ldr r0, [pc, #0x154]
 *   @0x246b60 mov r3, #6
 *   @0x246b64 str r3, [r1, #0x8]
 *   @0x246b68 mov r2, r5
 *   @0x246b6c ldr r1, [pc, #0x148]
 *   @0x246b70 mov r3, #0
 *   @0x246b74 ldr r0, [r7, r0]
 *   @0x246b78 add r1, pc, r1
 *   @0x246b7c ldr r0, [r0]
 *   @0x246b80 bl 0x19946c <_ZN12YYObjectBase3AddEPKcPS_i>
 *   @0x246b84 add sp, sp, #24
 *   @0x246b88 pop {r4, r5, r6, r7, r8, pc}
 *   @0x246b8c mov r1, r3
 *   @0x246b90 mov r0, r5
 *   @0x246b94 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x246b98 mov r3, r0
 *   @0x246b9c b 0x246b38 <_Z18JS_DateObjectSetupv+0x810>
 *   @0x246ba0 mov r0, r5
 *   @0x246ba4 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x246ba8 ldr r1, [r5, #0x4]
 *   @0x246bac mov r3, #6
 *   @0x246bb0 cmp r1, #0
 *   @0x246bb4 str r3, [r0, #0xc]
 *   @0x246bb8 bne 0x246b5c <_Z18JS_DateObjectSetupv+0x834>
 *   @0x246bbc mov r0, r5
 *   @0x246bc0 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x246bc4 mov r1, r0
 *   @0x246bc8 b 0x246b5c <_Z18JS_DateObjectSetupv+0x834>
 *   @0x246bcc andseq r11, r10, r0, lsl r9
 *   @0x246bd0 .word 0xfffffad8
 *   @0x246bd4 .word 0xfffffae0
 *   @0x246bd8 andseq pc, r0, r0, lsl #13
 *   @0x246bdc .word 0xffffc050
 *   @0x246be0 .word 0xfffff8ec
 *   @0x246be4 andeq r12, lr, r8, asr #2
 *   @0x246be8 andseq pc, r0, r4, lsl r6
 *   @0x246bec ldrsheq pc, [r0], -r12
 *   @0x246bf0 andseq pc, r0, r8, lsl #4
 *   @0x246bf4 ldrheq pc, [r0], -r12
 *   @0x246bf8 andseq pc, r0, r8, lsr #11
 *   @0x246bfc andseq pc, r0, r0, lsr #3
 *   @0x246c00 andseq pc, r0, r12, ror #10
 *   @0x246c04 andseq pc, r0, r12, asr #10
 *   @0x246c08 andseq pc, r0, r0, lsr r5
 *   @0x246c0c andseq pc, r0, r8, lsl r5
 *   @0x246c10 ldrsheq pc, [r0], -r12
 *   @0x246c14 andseq pc, r0, r0, ror #9
 *   @0x246c18 andseq pc, r0, r0, asr #9
 *   @0x246c1c andseq pc, r0, r4, lsr #9
 *   @0x246c20 andseq pc, r0, r4, lsl #9
 *   @0x246c24 andseq pc, r0, r8, ror #8
 *   @0x246c28 andseq pc, r0, r12, asr #8
 *   @0x246c2c andseq pc, r0, r0, lsr r4
 *   @0x246c30 andseq pc, r0, r4, lsl r4
 *   @0x246c34 ldrsheq pc, [r0], -r12
 *   @0x246c38 andseq pc, r0, r0, ror #7
 *   @0x246c3c andseq pc, r0, r8, asr #7
 *   @0x246c40 ldrheq pc, [r0], -r0
 *   @0x246c44 mulseq r0, r12, r3
 *   @0x246c48 andseq pc, r0, r8, lsl #7
 *   @0x246c4c andseq pc, r0, r8, ror #6
 *   @0x246c50 andseq pc, r0, r0, asr r3
 *   @0x246c54 andseq pc, r0, r12, lsr r3
 *   @0x246c58 andseq pc, r0, r0, lsr #6
 *   @0x246c5c andseq pc, r0, r8, lsl #6
 *   @0x246c60 andseq pc, r0, r12, ror #5
 *   @0x246c64 ldrsbeq pc, [r0], -r4
 *   @0x246c68 ldrheq pc, [r0], -r8
 *   @0x246c6c mulseq r0, r12, r2
 *   @0x246c70 andseq pc, r0, r12, ror r2
 *   @0x246c74 andseq pc, r0, r0, ror #4
 *   @0x246c78 andseq pc, r0, r4, asr #4
 *   @0x246c7c andseq pc, r0, r8, lsr #4
 *   @0x246c80 andseq pc, r0, r12, lsl #4
 *   @0x246c84 ldrsheq pc, [r0], -r4
 *   @0x246c88 .word 0xfffffae4
 *   @0x246c8c ldrsbeq pc, [r0], -r4
 *   @0x246c90 ldrheq pc, [r0], -r8
 *   @0x246c94 .word 0xfffffae8
 *   @0x246c98 .word 0xfffffaec
 *   @0x246c9c .word 0xfffffaf0
 *   @0x246ca0 andseq pc, r0, r0, ror r1
 *   @0x246ca4 .word 0xfffffaf4
 *   @0x246ca8 andseq pc, r0, r8, asr #2
 *   @0x246cac .word 0xfffffaf8
 *   @0x246cb0 andseq pc, r0, r0, lsr #2
 *   @0x246cb4 andseq lr, r0, r0, lsl #20
 *   @0x246cb8 .word 0xffffbf64
 *   @0x246cbc andseq lr, r0, r4, lsl #29
 *
 * ══ §11/12 JS_Date_parse(RValue&, CInstance*, CInstance*, int, RValue*)  0x2454f0  size 2436  609 条（0x2454f0..0x245e74）
 * @func 0x2454f0 0x245e74  size 2436  609 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_extract_char×29 / MakeTime(double, double, double, double)×2 / YYGetString(RValue const*, int) / MakeDay(double, double, double) / MakeDate(double, double)
 * 字段偏移 top8: 0x1×21 / 0x58×1 / 0x4cc×1 / 0x-4×1 / 0xc×1
 * VFP 指令 253 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2454f0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2454f4 vpush {d8, d9, d10, d11}
 *   @0x2454f8 sub sp, sp, #24
 *   @0x2454fc mov r1, #0
 *   @0x245500 mov r6, r0
 *   @0x245504 ldr r0, [sp, #0x58]
 *   @0x245508 add r4, sp, #24
 *   @0x24550c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x245510 ldr r5, [pc, #0x4cc]
 *   @0x245514 str r0, [r4, #-0x4]!
 *   @0x245518 mov r0, r4
 *   @0x24551c bl 0x10fb38 <utf8_extract_char>
 *   @0x245520 mov r8, r0
 *   @0x245524 mov r0, r4
 *   @0x245528 bl 0x10fb38 <utf8_extract_char>
 *   @0x24552c mov r9, r0
 *   @0x245530 mov r0, r4
 *   @0x245534 bl 0x10fb38 <utf8_extract_char>
 *   @0x245538 mov r10, r0
 *   @0x24553c mov r0, r4
 *   @0x245540 bl 0x10fb38 <utf8_extract_char>
 *   @0x245544 ldr r5, [pc, r5]
 *   @0x245548 ldr r3, [r5]
 *   @0x24554c uxtab r2, r3, r8
 *   @0x245550 ldrb r7, [r2, #0x1]
 *   @0x245554 and r7, r7, #4
 *   @0x245558 ands r7, r7, #255
 *   @0x24555c beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x245560 uxtab r2, r3, r9
 *   @0x245564 ldrb r7, [r2, #0x1]
 *   @0x245568 and r7, r7, #4
 *   @0x24556c ands r7, r7, #255
 *   @0x245570 beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x245574 uxtab r2, r3, r10
 *   @0x245578 ldrb r7, [r2, #0x1]
 *   @0x24557c and r7, r7, #4
 *   @0x245580 ands r7, r7, #255
 *   @0x245584 beq 0x245610 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x120>
 *   @0x245588 uxtab r3, r3, r0
 *   @0x24558c ldrb r7, [r3, #0x1]
 *   @0x245590 and r7, r7, #4
 *   @0x245594 ands r7, r7, #255
 *   @0x245598 beq 0x2456e0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x1f0>
 *   @0x24559c sub r9, r9, #48
 *   @0x2455a0 mov r2, #100
 *   @0x2455a4 sub r8, r8, #48
 *   @0x2455a8 mov r3, #1000
 *   @0x2455ac mul r9, r2, r9
 *   @0x2455b0 sub r10, r10, #48
 *   @0x2455b4 mla r8, r3, r8, r9
 *   @0x2455b8 add r10, r10, r10, lsl #2
 *   @0x2455bc sub r3, r0, #48
 *   @0x2455c0 mov r0, r4
 *   @0x2455c4 add r10, r8, r10, lsl #1
 *   @0x2455c8 add r3, r10, r3
 *   @0x2455cc vmov s22, r3
 *   @0x2455d0 bl 0x10fb38 <utf8_extract_char>
 *   @0x2455d4 cmp r0, #45
 *   @0x2455d8 beq 0x245714 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x224>
 *   @0x2455dc vcvt.f64.s32 d5, s22
 *   @0x2455e0 mov r7, #0
 *   @0x2455e4 vmov r0, r1, d5
 *   @0x2455e8 vmov s18, r7
 *   @0x2455ec mov r2, #0
 *   @0x2455f0 vmov s16, r7
 *   @0x2455f4 mov r3, #0
 *   @0x2455f8 vmov s17, r7
 *   @0x2455fc vldr s19, [pc, #996]
 *   @0x245600 vmov s20, r7
 *   @0x245604 vmov s21, r7
 *   @0x245608 vmov.f64 d4, #1.000000e+00
 *   @0x24560c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245610 vmov.f64 d4, #1.000000e+00
 *   @0x245614 mov r1, #51200
 *   @0x245618 vmov s18, r7
 *   @0x24561c movt r1, #0x409e
 *   @0x245620 vmov s16, r7
 *   @0x245624 mov r2, #0
 *   @0x245628 vmov s17, r7
 *   @0x24562c mov r3, #0
 *   @0x245630 vmov s20, r7
 *   @0x245634 mov r0, #0
 *   @0x245638 vmov s21, r7
 *   @0x24563c vldr s19, [pc, #932]
 *   @0x245640 vstr d4, [sp]
 *   @0x245644 bl 0x245370 <_Z7MakeDayddd>
 *   @0x245648 vcvt.f64.s32 d5, s17
 *   @0x24564c vcvt.f64.s32 d6, s16
 *   @0x245650 vstr d5, [sp]
 *   @0x245654 vstr d6, [sp, #8]
 *   @0x245658 vcvt.f64.s32 d5, s21
 *   @0x24565c vcvt.f64.s32 d6, s20
 *   @0x245660 vmov r2, r3, d6
 *   @0x245664 mov r4, r0
 *   @0x245668 mov r5, r1
 *   @0x24566c vmov r0, r1, d5
 *   @0x245670 bl 0x2451d8 <_Z8MakeTimedddd>
 *   @0x245674 mov r2, r0
 *   @0x245678 mov r3, r1
 *   @0x24567c mov r0, r4
 *   @0x245680 mov r1, r5
 *   @0x245684 bl 0x245480 <_Z8MakeDatedd>
 *   @0x245688 vmov s11, r7
 *   @0x24568c vcvt.f64.s32 d7, s18
 *   @0x245690 mov r4, #0
 *   @0x245694 mov r5, #0
 *   @0x245698 strd r4, r5, [sp]
 *   @0x24569c strd r4, r5, [sp, #8]
 *   @0x2456a0 vcvt.f64.s32 d5, s11
 *   @0x2456a4 vmov r2, r3, d5
 *   @0x2456a8 vmov d8, r0, r1
 *   @0x2456ac vmov r0, r1, d7
 *   @0x2456b0 bl 0x2451d8 <_Z8MakeTimedddd>
 *   @0x2456b4 mov r3, #0
 *   @0x2456b8 vcvt.f64.s32 d7, s19
 *   @0x2456bc str r3, [r6, #0xc]
 *   @0x2456c0 vmov.f64 d6, d8
 *   @0x2456c4 vmov d5, r0, r1
 *   @0x2456c8 vmla.f64 d6, d7, d5
 *   @0x2456cc vmov r2, r3, d6
 *   @0x2456d0 stm r6, {r2, r3}
 *   @0x2456d4 add sp, sp, #24
 *   @0x2456d8 vpop {d8, d9, d10, d11}
 *   @0x2456dc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2456e0 mov r1, #51200
 *   @0x2456e4 vmov.f64 d4, #1.000000e+00
 *   @0x2456e8 vmov s18, r7
 *   @0x2456ec vldr s19, [pc, #756]
 *   @0x2456f0 vmov s16, r7
 *   @0x2456f4 mov r2, #0
 *   @0x2456f8 vmov s17, r7
 *   @0x2456fc mov r3, #0
 *   @0x245700 vmov s20, r7
 *   @0x245704 mov r0, #0
 *   @0x245708 vmov s21, r7
 *   @0x24570c movt r1, #0x409e
 *   @0x245710 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245714 mov r0, r4
 *   @0x245718 bl 0x10fb38 <utf8_extract_char>
 *   @0x24571c mov r8, r0
 *   @0x245720 mov r0, r4
 *   @0x245724 bl 0x10fb38 <utf8_extract_char>
 *   @0x245728 ldr r3, [r5]
 *   @0x24572c uxtab r2, r3, r8
 *   @0x245730 ldrb r7, [r2, #0x1]
 *   @0x245734 and r7, r7, #4
 *   @0x245738 ands r7, r7, #255
 *   @0x24573c beq 0x2457bc <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2cc>
 *   @0x245740 uxtab r3, r3, r0
 *   @0x245744 ldrb r3, [r3, #0x1]
 *   @0x245748 and r3, r3, #4
 *   @0x24574c ands r7, r3, #255
 *   @0x245750 beq 0x2457b0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2c0>
 *   @0x245754 sub r8, r8, #48
 *   @0x245758 sub r3, r0, #48
 *   @0x24575c mov r0, r4
 *   @0x245760 add r8, r8, r8, lsl #2
 *   @0x245764 add r8, r3, r8, lsl #1
 *   @0x245768 bl 0x10fb38 <utf8_extract_char>
 *   @0x24576c cmp r0, #45
 *   @0x245770 beq 0x2457c8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x2d8>
 *   @0x245774 sub r2, r8, #1
 *   @0x245778 vcvt.f64.s32 d6, s22
 *   @0x24577c mov r7, #0
 *   @0x245780 vldr s19, [pc, #608]
 *   @0x245784 vmov s11, r2
 *   @0x245788 vmov s18, r7
 *   @0x24578c vmov s16, r7
 *   @0x245790 vmov s17, r7
 *   @0x245794 vmov s20, r7
 *   @0x245798 vcvt.f64.s32 d5, s11
 *   @0x24579c vmov s21, r7
 *   @0x2457a0 vmov r0, r1, d6
 *   @0x2457a4 vmov r2, r3, d5
 *   @0x2457a8 vmov.f64 d4, #1.000000e+00
 *   @0x2457ac b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x2457b0 vcvt.f64.s32 d7, s22
 *   @0x2457b4 vmov r0, r1, d7
 *   @0x2457b8 b 0x2455e8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x2457bc vcvt.f64.s32 d6, s22
 *   @0x2457c0 vmov r0, r1, d6
 *   @0x2457c4 b 0x2455e8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0xf8>
 *   @0x2457c8 mov r0, r4
 *   @0x2457cc bl 0x10fb38 <utf8_extract_char>
 *   @0x2457d0 mov r9, r0
 *   @0x2457d4 mov r0, r4
 *   @0x2457d8 bl 0x10fb38 <utf8_extract_char>
 *   @0x2457dc ldr r3, [r5]
 *   @0x2457e0 uxtab r2, r3, r9
 *   @0x2457e4 ldrb r2, [r2, #0x1]
 *   @0x2457e8 and r2, r2, #4
 *   @0x2457ec ands r7, r2, #255
 *   @0x2457f0 beq 0x2458a0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x3b0>
 *   @0x2457f4 uxtab r3, r3, r0
 *   @0x2457f8 ldrb r3, [r3, #0x1]
 *   @0x2457fc tst r3, #4
 *   @0x245800 beq 0x245864 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x374>
 *   @0x245804 sub r2, r9, #48
 *   @0x245808 sub r3, r0, #48
 *   @0x24580c mov r9, #10
 *   @0x245810 mov r0, r4
 *   @0x245814 mla r3, r9, r2, r3
 *   @0x245818 vmov s23, r3
 *   @0x24581c bl 0x10fb38 <utf8_extract_char>
 *   @0x245820 cmp r0, #84
 *   @0x245824 beq 0x2458d8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x3e8>
 *   @0x245828 sub r2, r8, #1
 *   @0x24582c vcvt.f64.s32 d6, s22
 *   @0x245830 mov r7, #0
 *   @0x245834 vldr s19, [pc, #428]
 *   @0x245838 vmov s11, r2
 *   @0x24583c vmov s18, r7
 *   @0x245840 vmov s16, r7
 *   @0x245844 vmov s17, r7
 *   @0x245848 vmov s20, r7
 *   @0x24584c vcvt.f64.s32 d5, s11
 *   @0x245850 vmov s21, r7
 *   @0x245854 vmov r0, r1, d6
 *   @0x245858 vmov r2, r3, d5
 *   @0x24585c vcvt.f64.s32 d4, s23
 *   @0x245860 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245864 sub r2, r8, #1
 *   @0x245868 vcvt.f64.s32 d7, s22
 *   @0x24586c mov r7, #0
 *   @0x245870 vldr s19, [pc, #368]
 *   @0x245874 vmov s13, r2
 *   @0x245878 vmov s18, r7
 *   @0x24587c vmov s16, r7
 *   @0x245880 vmov s17, r7
 *   @0x245884 vmov s20, r7
 *   @0x245888 vcvt.f64.s32 d6, s13
 *   @0x24588c vmov s21, r7
 *   @0x245890 vmov r0, r1, d7
 *   @0x245894 vmov r2, r3, d6
 *   @0x245898 vmov.f64 d4, #1.000000e+00
 *   @0x24589c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x2458a0 sub r2, r8, #1
 *   @0x2458a4 vcvt.f64.s32 d5, s22
 *   @0x2458a8 vmov s18, r7
 *   @0x2458ac vldr s19, [pc, #308]
 *   @0x2458b0 vmov s15, r2
 *   @0x2458b4 vmov s16, r7
 *   @0x2458b8 vmov s17, r7
 *   @0x2458bc vmov s20, r7
 *   @0x2458c0 vmov s21, r7
 *   @0x2458c4 vcvt.f64.s32 d7, s15
 *   @0x2458c8 vmov r0, r1, d5
 *   @0x2458cc vmov r2, r3, d7
 *   @0x2458d0 vmov.f64 d4, #1.000000e+00
 *   @0x2458d4 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x2458d8 mov r0, r4
 *   @0x2458dc bl 0x10fb38 <utf8_extract_char>
 *   @0x2458e0 mov r10, r0
 *   @0x2458e4 mov r0, r4
 *   @0x2458e8 bl 0x10fb38 <utf8_extract_char>
 *   @0x2458ec ldr r3, [r5]
 *   @0x2458f0 uxtab r2, r3, r10
 *   @0x2458f4 ldrb r2, [r2, #0x1]
 *   @0x2458f8 and r2, r2, #4
 *   @0x2458fc ands r7, r2, #255
 *   @0x245900 beq 0x245954 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x464>
 *   @0x245904 uxtab r3, r3, r0
 *   @0x245908 ldrb r3, [r3, #0x1]
 *   @0x24590c and r3, r3, #4
 *   @0x245910 ands r3, r3, #255
 *   @0x245914 bne 0x24598c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x245918 sub r2, r8, #1
 *   @0x24591c vcvt.f64.s32 d7, s22
 *   @0x245920 mov r7, r3
 *   @0x245924 vmov s18, r3
 *   @0x245928 vmov s13, r2
 *   @0x24592c vldr s19, [pc, #180]
 *   @0x245930 vmov s16, r3
 *   @0x245934 vmov s17, r7
 *   @0x245938 vmov s20, r7
 *   @0x24593c vmov s21, r7
 *   @0x245940 vcvt.f64.s32 d6, s13
 *   @0x245944 vmov r0, r1, d7
 *   @0x245948 vmov r2, r3, d6
 *   @0x24594c vcvt.f64.s32 d4, s23
 *   @0x245950 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245954 sub r2, r8, #1
 *   @0x245958 vcvt.f64.s32 d5, s22
 *   @0x24595c vmov s18, r7
 *   @0x245960 vldr s19, [pc, #128]
 *   @0x245964 vmov s15, r2
 *   @0x245968 vmov s16, r7
 *   @0x24596c vmov s17, r7
 *   @0x245970 vmov s20, r7
 *   @0x245974 vmov s21, r7
 *   @0x245978 vcvt.f64.s32 d7, s15
 *   @0x24597c vmov r0, r1, d5
 *   @0x245980 vmov r2, r3, d7
 *   @0x245984 vcvt.f64.s32 d4, s23
 *   @0x245988 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x24598c sub r3, r0, #48
 *   @0x245990 sub r10, r10, #48
 *   @0x245994 mov r0, r4
 *   @0x245998 mla r3, r9, r10, r3
 *   @0x24599c vmov s21, r3
 *   @0x2459a0 bl 0x10fb38 <utf8_extract_char>
 *   @0x2459a4 cmp r0, #58
 *   @0x2459a8 beq 0x2459ec <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x4fc>
 *   @0x2459ac sub r2, r8, #1
 *   @0x2459b0 vcvt.f64.s32 d6, s22
 *   @0x2459b4 mov r7, #0
 *   @0x2459b8 vldr s19, [pc, #40]
 *   @0x2459bc vmov s11, r2
 *   @0x2459c0 vmov s18, r7
 *   @0x2459c4 vmov s16, r7
 *   @0x2459c8 vmov s17, r7
 *   @0x2459cc vmov s20, r7
 *   @0x2459d0 vcvt.f64.s32 d5, s11
 *   @0x2459d4 vmov r0, r1, d6
 *   @0x2459d8 vmov r2, r3, d5
 *   @0x2459dc vcvt.f64.s32 d4, s23
 *   @0x2459e0 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x2459e4 andseq r8, r10, r12, lsr r4
 *   @0x2459e8 andeq r0, r0, r1
 *   @0x2459ec mov r0, r4
 *   @0x2459f0 bl 0x10fb38 <utf8_extract_char>
 *   @0x2459f4 mov r10, r0
 *   @0x2459f8 mov r0, r4
 *   @0x2459fc bl 0x10fb38 <utf8_extract_char>
 *   @0x245a00 ldr r3, [r5]
 *   @0x245a04 uxtab r2, r3, r10
 *   @0x245a08 ldrb r2, [r2, #0x1]
 *   @0x245a0c and r2, r2, #4
 *   @0x245a10 ands r7, r2, #255
 *   @0x245a14 beq 0x245a64 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x574>
 *   @0x245a18 uxtab r3, r3, r0
 *   @0x245a1c ldrb r3, [r3, #0x1]
 *   @0x245a20 and r3, r3, #4
 *   @0x245a24 ands r3, r3, #255
 *   @0x245a28 bne 0x245a98 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x5a8>
 *   @0x245a2c sub r2, r8, #1
 *   @0x245a30 vcvt.f64.s32 d7, s22
 *   @0x245a34 mov r7, r3
 *   @0x245a38 vmov s18, r3
 *   @0x245a3c vmov s13, r2
 *   @0x245a40 vldr s19, [pc, #-96]
 *   @0x245a44 vmov s16, r3
 *   @0x245a48 vmov s17, r7
 *   @0x245a4c vmov s20, r7
 *   @0x245a50 vcvt.f64.s32 d6, s13
 *   @0x245a54 vmov r0, r1, d7
 *   @0x245a58 vmov r2, r3, d6
 *   @0x245a5c vcvt.f64.s32 d4, s23
 *   @0x245a60 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245a64 sub r2, r8, #1
 *   @0x245a68 vcvt.f64.s32 d5, s22
 *   @0x245a6c vmov s18, r7
 *   @0x245a70 vldr s19, [pc, #-144]
 *   @0x245a74 vmov s15, r2
 *   @0x245a78 vmov s16, r7
 *   @0x245a7c vmov s17, r7
 *   @0x245a80 vmov s20, r7
 *   @0x245a84 vcvt.f64.s32 d7, s15
 *   @0x245a88 vmov r0, r1, d5
 *   @0x245a8c vmov r2, r3, d7
 *   @0x245a90 vcvt.f64.s32 d4, s23
 *   @0x245a94 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245a98 sub r3, r0, #48
 *   @0x245a9c sub r10, r10, #48
 *   @0x245aa0 mov r0, r4
 *   @0x245aa4 mla r3, r9, r10, r3
 *   @0x245aa8 vmov s20, r3
 *   @0x245aac bl 0x10fb38 <utf8_extract_char>
 *   @0x245ab0 cmp r0, #58
 *   @0x245ab4 beq 0x245aec <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x5fc>
 *   @0x245ab8 sub r2, r8, #1
 *   @0x245abc vcvt.f64.s32 d6, s22
 *   @0x245ac0 mov r7, #0
 *   @0x245ac4 vldr s19, [pc, #-228]
 *   @0x245ac8 vmov s11, r2
 *   @0x245acc vmov s18, r7
 *   @0x245ad0 vmov s16, r7
 *   @0x245ad4 vmov s17, r7
 *   @0x245ad8 vcvt.f64.s32 d5, s11
 *   @0x245adc vmov r0, r1, d6
 *   @0x245ae0 vmov r2, r3, d5
 *   @0x245ae4 vcvt.f64.s32 d4, s23
 *   @0x245ae8 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245aec mov r0, r4
 *   @0x245af0 bl 0x10fb38 <utf8_extract_char>
 *   @0x245af4 mov r10, r0
 *   @0x245af8 mov r0, r4
 *   @0x245afc bl 0x10fb38 <utf8_extract_char>
 *   @0x245b00 ldr r3, [r5]
 *   @0x245b04 uxtab r2, r3, r10
 *   @0x245b08 ldrb r2, [r2, #0x1]
 *   @0x245b0c and r2, r2, #4
 *   @0x245b10 ands r7, r2, #255
 *   @0x245b14 beq 0x245b60 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x670>
 *   @0x245b18 uxtab r3, r3, r0
 *   @0x245b1c ldrb r3, [r3, #0x1]
 *   @0x245b20 and r3, r3, #4
 *   @0x245b24 ands r3, r3, #255
 *   @0x245b28 bne 0x245b90 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6a0>
 *   @0x245b2c sub r2, r8, #1
 *   @0x245b30 vcvt.f64.s32 d7, s22
 *   @0x245b34 mov r7, r3
 *   @0x245b38 vmov s18, r3
 *   @0x245b3c vmov s13, r2
 *   @0x245b40 vldr s19, [pc, #-352]
 *   @0x245b44 vmov s16, r3
 *   @0x245b48 vmov s17, r7
 *   @0x245b4c vcvt.f64.s32 d6, s13
 *   @0x245b50 vmov r0, r1, d7
 *   @0x245b54 vmov r2, r3, d6
 *   @0x245b58 vcvt.f64.s32 d4, s23
 *   @0x245b5c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245b60 sub r2, r8, #1
 *   @0x245b64 vcvt.f64.s32 d5, s22
 *   @0x245b68 vmov s18, r7
 *   @0x245b6c vldr s19, [pc, #-396]
 *   @0x245b70 vmov s15, r2
 *   @0x245b74 vmov s16, r7
 *   @0x245b78 vmov s17, r7
 *   @0x245b7c vcvt.f64.s32 d7, s15
 *   @0x245b80 vmov r0, r1, d5
 *   @0x245b84 vmov r2, r3, d7
 *   @0x245b88 vcvt.f64.s32 d4, s23
 *   @0x245b8c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245b90 sub r3, r0, #48
 *   @0x245b94 sub r10, r10, #48
 *   @0x245b98 mov r0, r4
 *   @0x245b9c mla r3, r9, r10, r3
 *   @0x245ba0 vmov s17, r3
 *   @0x245ba4 bl 0x10fb38 <utf8_extract_char>
 *   @0x245ba8 cmp r0, #58
 *   @0x245bac beq 0x245be0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6f0>
 *   @0x245bb0 sub r2, r8, #1
 *   @0x245bb4 vcvt.f64.s32 d6, s22
 *   @0x245bb8 mov r7, #0
 *   @0x245bbc vldr s19, [pc, #-476]
 *   @0x245bc0 vmov s11, r2
 *   @0x245bc4 vmov s18, r7
 *   @0x245bc8 vmov s16, r7
 *   @0x245bcc vcvt.f64.s32 d5, s11
 *   @0x245bd0 vmov r0, r1, d6
 *   @0x245bd4 vmov r2, r3, d5
 *   @0x245bd8 vcvt.f64.s32 d4, s23
 *   @0x245bdc b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245be0 mov r0, r4
 *   @0x245be4 bl 0x10fb38 <utf8_extract_char>
 *   @0x245be8 mov r9, r0
 *   @0x245bec mov r0, r4
 *   @0x245bf0 bl 0x10fb38 <utf8_extract_char>
 *   @0x245bf4 mov r10, r0
 *   @0x245bf8 mov r0, r4
 *   @0x245bfc bl 0x10fb38 <utf8_extract_char>
 *   @0x245c00 ldr r3, [r5]
 *   @0x245c04 uxtab r2, r3, r9
 *   @0x245c08 ldrb r2, [r2, #0x1]
 *   @0x245c0c and r2, r2, #4
 *   @0x245c10 ands r7, r2, #255
 *   @0x245c14 beq 0x245d04 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x814>
 *   @0x245c18 uxtab r2, r3, r10
 *   @0x245c1c ldrb r2, [r2, #0x1]
 *   @0x245c20 and r2, r2, #4
 *   @0x245c24 ands r7, r2, #255
 *   @0x245c28 beq 0x245e30 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x940>
 *   @0x245c2c uxtab r3, r3, r0
 *   @0x245c30 ldrb r3, [r3, #0x1]
 *   @0x245c34 and r3, r3, #4
 *   @0x245c38 ands r3, r3, #255
 *   @0x245c3c beq 0x245bb0 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x6c0>
 *   @0x245c40 sub r1, r10, #48
 *   @0x245c44 sub r2, r9, #48
 *   @0x245c48 mov r9, #10
 *   @0x245c4c mov r12, #100
 *   @0x245c50 mul r1, r9, r1
 *   @0x245c54 sub r3, r0, #48
 *   @0x245c58 mla r2, r12, r2, r1
 *   @0x245c5c mov r0, r4
 *   @0x245c60 add r3, r2, r3
 *   @0x245c64 vmov s16, r3
 *   @0x245c68 bl 0x10fb38 <utf8_extract_char>
 *   @0x245c6c subs r2, r0, #45
 *   @0x245c70 rsbs r3, r2, #0
 *   @0x245c74 adcs r3, r3, r2
 *   @0x245c78 cmp r0, #45
 *   @0x245c7c cmpne r0, #43
 *   @0x245c80 movne r0, #0
 *   @0x245c84 moveq r0, #1
 *   @0x245c88 bne 0x245e04 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x914>
 *   @0x245c8c cmp r3, #0
 *   @0x245c90 mov r0, r4
 *   @0x245c94 moveq r3, #1
 *   @0x245c98 mvnne r3, #0
 *   @0x245c9c vmov s19, r3
 *   @0x245ca0 bl 0x10fb38 <utf8_extract_char>
 *   @0x245ca4 mov r10, r0
 *   @0x245ca8 mov r0, r4
 *   @0x245cac bl 0x10fb38 <utf8_extract_char>
 *   @0x245cb0 ldr r3, [r5]
 *   @0x245cb4 uxtab r2, r3, r10
 *   @0x245cb8 ldrb r2, [r2, #0x1]
 *   @0x245cbc and r2, r2, #4
 *   @0x245cc0 ands r7, r2, #255
 *   @0x245cc4 beq 0x245d74 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x884>
 *   @0x245cc8 uxtab r3, r3, r0
 *   @0x245ccc ldrb r3, [r3, #0x1]
 *   @0x245cd0 and r3, r3, #4
 *   @0x245cd4 ands r3, r3, #255
 *   @0x245cd8 bne 0x245d30 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x840>
 *   @0x245cdc sub r2, r8, #1
 *   @0x245ce0 vmov s18, r3
 *   @0x245ce4 mov r7, r3
 *   @0x245ce8 vmov s11, r2
 *   @0x245cec vcvt.f64.s32 d7, s22
 *   @0x245cf0 vcvt.f64.s32 d5, s11
 *   @0x245cf4 vmov r0, r1, d7
 *   @0x245cf8 vmov r2, r3, d5
 *   @0x245cfc vcvt.f64.s32 d4, s23
 *   @0x245d00 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245d04 sub r2, r8, #1
 *   @0x245d08 vcvt.f64.s32 d5, s22
 *   @0x245d0c vmov s18, r7
 *   @0x245d10 vldr s19, [pc, #-816]
 *   @0x245d14 vmov s15, r2
 *   @0x245d18 vmov s16, r7
 *   @0x245d1c vcvt.f64.s32 d7, s15
 *   @0x245d20 vmov r0, r1, d5
 *   @0x245d24 vmov r2, r3, d7
 *   @0x245d28 vcvt.f64.s32 d4, s23
 *   @0x245d2c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245d30 sub r3, r0, #48
 *   @0x245d34 sub r10, r10, #48
 *   @0x245d38 mov r0, r4
 *   @0x245d3c mla r3, r9, r10, r3
 *   @0x245d40 vmov s18, r3
 *   @0x245d44 bl 0x10fb38 <utf8_extract_char>
 *   @0x245d48 cmp r0, #58
 *   @0x245d4c beq 0x245d98 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x8a8>
 *   @0x245d50 sub r2, r8, #1
 *   @0x245d54 vcvt.f64.s32 d6, s22
 *   @0x245d58 mov r7, #0
 *   @0x245d5c vmov s15, r2
 *   @0x245d60 vcvt.f64.s32 d7, s15
 *   @0x245d64 vmov r0, r1, d6
 *   @0x245d68 vmov r2, r3, d7
 *   @0x245d6c vcvt.f64.s32 d4, s23
 *   @0x245d70 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245d74 sub r2, r8, #1
 *   @0x245d78 vmov s18, r7
 *   @0x245d7c vmov s13, r2
 *   @0x245d80 vcvt.f64.s32 d5, s22
 *   @0x245d84 vcvt.f64.s32 d6, s13
 *   @0x245d88 vmov r0, r1, d5
 *   @0x245d8c vmov r2, r3, d6
 *   @0x245d90 vcvt.f64.s32 d4, s23
 *   @0x245d94 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245d98 mov r0, r4
 *   @0x245d9c bl 0x10fb38 <utf8_extract_char>
 *   @0x245da0 mov r10, r0
 *   @0x245da4 mov r0, r4
 *   @0x245da8 bl 0x10fb38 <utf8_extract_char>
 *   @0x245dac ldr r3, [r5]
 *   @0x245db0 uxtab r2, r3, r10
 *   @0x245db4 ldrb r2, [r2, #0x1]
 *   @0x245db8 and r2, r2, #4
 *   @0x245dbc ands r7, r2, #255
 *   @0x245dc0 beq 0x245e68 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x978>
 *   @0x245dc4 uxtab r3, r3, r0
 *   @0x245dc8 ldrb r3, [r3, #0x1]
 *   @0x245dcc and r3, r3, #4
 *   @0x245dd0 ands r3, r3, #255
 *   @0x245dd4 beq 0x245e5c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x96c>
 *   @0x245dd8 sub r2, r8, #1
 *   @0x245ddc vcvt.f64.s32 d6, s22
 *   @0x245de0 sub r3, r0, #48
 *   @0x245de4 sub r7, r10, #48
 *   @0x245de8 vmov s15, r2
 *   @0x245dec mla r7, r9, r7, r3
 *   @0x245df0 vcvt.f64.s32 d7, s15
 *   @0x245df4 vmov r0, r1, d6
 *   @0x245df8 vmov r2, r3, d7
 *   @0x245dfc vcvt.f64.s32 d4, s23
 *   @0x245e00 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245e04 sub r2, r8, #1
 *   @0x245e08 vcvt.f64.s32 d7, s22
 *   @0x245e0c mov r7, r0
 *   @0x245e10 vmov s18, r0
 *   @0x245e14 vmov s11, r2
 *   @0x245e18 vldr s19, [pc, #80]
 *   @0x245e1c vcvt.f64.s32 d5, s11
 *   @0x245e20 vmov r0, r1, d7
 *   @0x245e24 vmov r2, r3, d5
 *   @0x245e28 vcvt.f64.s32 d4, s23
 *   @0x245e2c b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245e30 sub r2, r8, #1
 *   @0x245e34 vcvt.f64.s32 d7, s22
 *   @0x245e38 vmov s18, r7
 *   @0x245e3c vldr s19, [pc, #44]
 *   @0x245e40 vmov s13, r2
 *   @0x245e44 vmov s16, r7
 *   @0x245e48 vcvt.f64.s32 d6, s13
 *   @0x245e4c vmov r0, r1, d7
 *   @0x245e50 vmov r2, r3, d6
 *   @0x245e54 vcvt.f64.s32 d4, s23
 *   @0x245e58 b 0x245640 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x150>
 *   @0x245e5c sub r2, r8, #1
 *   @0x245e60 mov r7, r3
 *   @0x245e64 b 0x245ce8 <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x7f8>
 *   @0x245e68 sub r2, r8, #1
 *   @0x245e6c b 0x245d7c <_Z13JS_Date_parseR6RValueP9CInstanceS2_iPS_+0x88c>
 *   @0x245e70 andeq r0, r0, r1
 *
 * ══ §12/12 RVariable::RVariable(RVariable const*)  0x1f7404  size 1164  291 条（0x1f7404..0x1f7890）
 * @func 0x1f7404 0x1f7890  size 1164  291 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×8 / UNLOCK_RVALUE_MUTEX()×8 / YYFree(void const*)×8 / operator delete(void*)×8 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / FREE_RValue__Pre(RValue*)×2 / _RefThing<char const*>::dec()×2
 * 字段偏移 top8: 0x8×24 / 0x4×17 / 0x18×14 / 0x24×5 / 0x14×5 / 0x20×3 / 0x10×3 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1f7404 push {r4, r5, r6, r7, r8, lr}
 *   @0x1f7408 mov r5, r1
 *   @0x1f740c ldr r1, [r0, #0x24]
 *   @0x1f7410 mov r3, #0
 *   @0x1f7414 mov r4, r0
 *   @0x1f7418 add r7, r0, #24
 *   @0x1f741c bic r2, r1, #-16777216
 *   @0x1f7420 str r3, [r0]
 *   @0x1f7424 cmp r2, #1
 *   @0x1f7428 str r3, [r0, #0x4]
 *   @0x1f742c beq 0x1f75b0 <_ZN9RVariableC2EPKS_+0x1ac>
 *   @0x1f7430 cmp r2, #2
 *   @0x1f7434 bne 0x1f745c <_ZN9RVariableC2EPKS_+0x58>
 *   @0x1f7438 sub r1, r1, #1
 *   @0x1f743c bic r1, r1, #-16777216
 *   @0x1f7440 bic r1, r1, #3
 *   @0x1f7444 cmp r1, #0
 *   @0x1f7448 beq 0x1f7758 <_ZN9RVariableC2EPKS_+0x354>
 *   @0x1f744c mov r2, #0
 *   @0x1f7450 mov r3, #5
 *   @0x1f7454 str r2, [r4, #0x20]
 *   @0x1f7458 str r3, [r4, #0x24]
 *   @0x1f745c ldr r3, [r5, #0x24]
 *   @0x1f7460 mov r1, #0
 *   @0x1f7464 ldr r2, [r5, #0x20]
 *   @0x1f7468 str r1, [r4, #0x18]
 *   @0x1f746c str r3, [r4, #0x24]
 *   @0x1f7470 ldr r3, [r5, #0x24]
 *   @0x1f7474 str r2, [r4, #0x20]
 *   @0x1f7478 bic r3, r3, #-16777216
 *   @0x1f747c cmp r3, #14
 *   @0x1f7480 addls pc, pc, r3, lsl #2
 *   @0x1f7484 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f7488 b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180>
 *   @0x1f748c b 0x1f763c <_ZN9RVariableC2EPKS_+0x238>
 *   @0x1f7490 b 0x1f7654 <_ZN9RVariableC2EPKS_+0x250>
 *   @0x1f7494 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0>
 *   @0x1f7498 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f749c b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f74a0 b 0x1f7618 <_ZN9RVariableC2EPKS_+0x214>
 *   @0x1f74a4 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0>
 *   @0x1f74a8 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f74ac b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f74b0 b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180>
 *   @0x1f74b4 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f74b8 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f74bc b 0x1f7584 <_ZN9RVariableC2EPKS_+0x180>
 *   @0x1f74c0 b 0x1f74c4 <_ZN9RVariableC2EPKS_+0xc0>
 *   @0x1f74c4 ldr r3, [r5, #0x18]
 *   @0x1f74c8 str r3, [r4, #0x18]
 *   @0x1f74cc ldr r2, [r4, #0x14]
 *   @0x1f74d0 add r7, r4, #8
 *   @0x1f74d4 bic r3, r2, #-16777216
 *   @0x1f74d8 cmp r3, #1
 *   @0x1f74dc beq 0x1f75e4 <_ZN9RVariableC2EPKS_+0x1e0>
 *   @0x1f74e0 cmp r3, #2
 *   @0x1f74e4 bne 0x1f750c <_ZN9RVariableC2EPKS_+0x108>
 *   @0x1f74e8 sub r2, r2, #1
 *   @0x1f74ec bic r2, r2, #-16777216
 *   @0x1f74f0 bic r2, r2, #3
 *   @0x1f74f4 cmp r2, #0
 *   @0x1f74f8 beq 0x1f7764 <_ZN9RVariableC2EPKS_+0x360>
 *   @0x1f74fc mov r2, #0
 *   @0x1f7500 mov r3, #5
 *   @0x1f7504 str r2, [r4, #0x10]
 *   @0x1f7508 str r3, [r4, #0x14]
 *   @0x1f750c ldr r3, [r5, #0x14]
 *   @0x1f7510 mov r1, #0
 *   @0x1f7514 ldr r2, [r5, #0x10]
 *   @0x1f7518 str r1, [r4, #0x8]
 *   @0x1f751c str r3, [r4, #0x14]
 *   @0x1f7520 ldr r3, [r5, #0x14]
 *   @0x1f7524 str r2, [r4, #0x10]
 *   @0x1f7528 bic r3, r3, #-16777216
 *   @0x1f752c cmp r3, #14
 *   @0x1f7530 addls pc, pc, r3, lsl #2
 *   @0x1f7534 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f7538 b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194>
 *   @0x1f753c b 0x1f7680 <_ZN9RVariableC2EPKS_+0x27c>
 *   @0x1f7540 b 0x1f76bc <_ZN9RVariableC2EPKS_+0x2b8>
 *   @0x1f7544 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170>
 *   @0x1f7548 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f754c b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f7550 b 0x1f7698 <_ZN9RVariableC2EPKS_+0x294>
 *   @0x1f7554 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170>
 *   @0x1f7558 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f755c b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f7560 b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194>
 *   @0x1f7564 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f7568 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f756c b 0x1f7598 <_ZN9RVariableC2EPKS_+0x194>
 *   @0x1f7570 b 0x1f7574 <_ZN9RVariableC2EPKS_+0x170>
 *   @0x1f7574 ldr r3, [r5, #0x8]
 *   @0x1f7578 str r3, [r4, #0x8]
 *   @0x1f757c mov r0, r4
 *   @0x1f7580 pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f7584 ldr r2, [r5, #0x18]
 *   @0x1f7588 ldr r3, [r5, #0x1c]
 *   @0x1f758c str r2, [r4, #0x18]
 *   @0x1f7590 str r3, [r4, #0x1c]
 *   @0x1f7594 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f7598 ldr r2, [r5, #0x8]
 *   @0x1f759c mov r0, r4
 *   @0x1f75a0 ldr r3, [r5, #0xc]
 *   @0x1f75a4 str r2, [r4, #0x8]
 *   @0x1f75a8 str r3, [r4, #0xc]
 *   @0x1f75ac pop {r4, r5, r6, r7, r8, pc}
 *   @0x1f75b0 ldr r6, [r0, #0x18]
 *   @0x1f75b4 cmp r6, #0
 *   @0x1f75b8 beq 0x1f75d8 <_ZN9RVariableC2EPKS_+0x1d4>
 *   @0x1f75bc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f75c0 ldr r8, [r6, #0x4]
 *   @0x1f75c4 sub r8, r8, #1
 *   @0x1f75c8 str r8, [r6, #0x4]
 *   @0x1f75cc cmp r8, #0
 *   @0x1f75d0 beq 0x1f76e8 <_ZN9RVariableC2EPKS_+0x2e4>
 *   @0x1f75d4 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f75d8 mov r3, #0
 *   @0x1f75dc str r3, [r4, #0x18]
 *   @0x1f75e0 b 0x1f745c <_ZN9RVariableC2EPKS_+0x58>
 *   @0x1f75e4 ldr r6, [r4, #0x8]
 *   @0x1f75e8 cmp r6, #0
 *   @0x1f75ec beq 0x1f760c <_ZN9RVariableC2EPKS_+0x208>
 *   @0x1f75f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f75f4 ldr r8, [r6, #0x4]
 *   @0x1f75f8 sub r8, r8, #1
 *   @0x1f75fc str r8, [r6, #0x4]
 *   @0x1f7600 cmp r8, #0
 *   @0x1f7604 beq 0x1f7720 <_ZN9RVariableC2EPKS_+0x31c>
 *   @0x1f7608 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f760c mov r3, #0
 *   @0x1f7610 str r3, [r4, #0x8]
 *   @0x1f7614 b 0x1f750c <_ZN9RVariableC2EPKS_+0x108>
 *   @0x1f7618 ldr r3, [r5, #0x18]
 *   @0x1f761c str r3, [r4, #0x18]
 *   @0x1f7620 ldr r3, [r5, #0x18]
 *   @0x1f7624 cmp r3, #0
 *   @0x1f7628 beq 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f762c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f7630 ldr r1, [r5, #0x18]
 *   @0x1f7634 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f7638 b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f763c ldr r3, [r5, #0x18]
 *   @0x1f7640 cmp r3, #0
 *   @0x1f7644 ldrne r2, [r3, #0x4]
 *   @0x1f7648 addne r2, r2, #1
 *   @0x1f764c strne r2, [r3, #0x4]
 *   @0x1f7650 b 0x1f74c8 <_ZN9RVariableC2EPKS_+0xc4>
 *   @0x1f7654 ldr r3, [r5, #0x18]
 *   @0x1f7658 cmp r3, #0
 *   @0x1f765c str r3, [r4, #0x18]
 *   @0x1f7660 beq 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f7664 ldr r1, [r3, #0x8]
 *   @0x1f7668 ldr r2, [r3]
 *   @0x1f766c cmp r1, #0
 *   @0x1f7670 streq r7, [r3, #0x8]
 *   @0x1f7674 add r2, r2, #1
 *   @0x1f7678 str r2, [r3]
 *   @0x1f767c b 0x1f74cc <_ZN9RVariableC2EPKS_+0xc8>
 *   @0x1f7680 ldr r3, [r5, #0x8]
 *   @0x1f7684 cmp r3, #0
 *   @0x1f7688 ldrne r2, [r3, #0x4]
 *   @0x1f768c addne r2, r2, #1
 *   @0x1f7690 strne r2, [r3, #0x4]
 *   @0x1f7694 b 0x1f7578 <_ZN9RVariableC2EPKS_+0x174>
 *   @0x1f7698 ldr r3, [r5, #0x8]
 *   @0x1f769c str r3, [r4, #0x8]
 *   @0x1f76a0 ldr r3, [r5, #0x8]
 *   @0x1f76a4 cmp r3, #0
 *   @0x1f76a8 beq 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f76ac bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x1f76b0 ldr r1, [r5, #0x8]
 *   @0x1f76b4 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x1f76b8 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f76bc ldr r3, [r5, #0x8]
 *   @0x1f76c0 cmp r3, #0
 *   @0x1f76c4 str r3, [r4, #0x8]
 *   @0x1f76c8 beq 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f76cc ldr r1, [r3, #0x8]
 *   @0x1f76d0 ldr r2, [r3]
 *   @0x1f76d4 cmp r1, #0
 *   @0x1f76d8 streq r7, [r3, #0x8]
 *   @0x1f76dc add r2, r2, #1
 *   @0x1f76e0 str r2, [r3]
 *   @0x1f76e4 b 0x1f757c <_ZN9RVariableC2EPKS_+0x178>
 *   @0x1f76e8 ldr r0, [r6]
 *   @0x1f76ec bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f76f0 str r8, [r6]
 *   @0x1f76f4 str r8, [r6, #0x8]
 *   @0x1f76f8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f76fc ldr r8, [r6, #0x4]
 *   @0x1f7700 sub r8, r8, #1
 *   @0x1f7704 str r8, [r6, #0x4]
 *   @0x1f7708 cmp r8, #0
 *   @0x1f770c beq 0x1f7770 <_ZN9RVariableC2EPKS_+0x36c>
 *   @0x1f7710 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7714 mov r0, r6
 *   @0x1f7718 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f771c b 0x1f75d4 <_ZN9RVariableC2EPKS_+0x1d0>
 *   @0x1f7720 ldr r0, [r6]
 *   @0x1f7724 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7728 str r8, [r6]
 *   @0x1f772c str r8, [r6, #0x8]
 *   @0x1f7730 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7734 ldr r8, [r6, #0x4]
 *   @0x1f7738 sub r8, r8, #1
 *   @0x1f773c str r8, [r6, #0x4]
 *   @0x1f7740 cmp r8, #0
 *   @0x1f7744 beq 0x1f77a8 <_ZN9RVariableC2EPKS_+0x3a4>
 *   @0x1f7748 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f774c mov r0, r6
 *   @0x1f7750 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7754 b 0x1f7608 <_ZN9RVariableC2EPKS_+0x204>
 *   @0x1f7758 mov r0, r7
 *   @0x1f775c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f7760 b 0x1f744c <_ZN9RVariableC2EPKS_+0x48>
 *   @0x1f7764 mov r0, r7
 *   @0x1f7768 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1f776c b 0x1f74fc <_ZN9RVariableC2EPKS_+0xf8>
 *   @0x1f7770 ldr r0, [r6]
 *   @0x1f7774 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7778 str r8, [r6]
 *   @0x1f777c str r8, [r6, #0x8]
 *   @0x1f7780 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f7784 ldr r8, [r6, #0x4]
 *   @0x1f7788 sub r8, r8, #1
 *   @0x1f778c str r8, [r6, #0x4]
 *   @0x1f7790 cmp r8, #0
 *   @0x1f7794 beq 0x1f77e0 <_ZN9RVariableC2EPKS_+0x3dc>
 *   @0x1f7798 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f779c mov r0, r6
 *   @0x1f77a0 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f77a4 b 0x1f7710 <_ZN9RVariableC2EPKS_+0x30c>
 *   @0x1f77a8 ldr r0, [r6]
 *   @0x1f77ac bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f77b0 str r8, [r6]
 *   @0x1f77b4 str r8, [r6, #0x8]
 *   @0x1f77b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f77bc ldr r8, [r6, #0x4]
 *   @0x1f77c0 sub r8, r8, #1
 *   @0x1f77c4 str r8, [r6, #0x4]
 *   @0x1f77c8 cmp r8, #0
 *   @0x1f77cc beq 0x1f7838 <_ZN9RVariableC2EPKS_+0x434>
 *   @0x1f77d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f77d4 mov r0, r6
 *   @0x1f77d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f77dc b 0x1f7748 <_ZN9RVariableC2EPKS_+0x344>
 *   @0x1f77e0 ldr r0, [r6]
 *   @0x1f77e4 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f77e8 str r8, [r6]
 *   @0x1f77ec str r8, [r6, #0x8]
 *   @0x1f77f0 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f77f4 ldr r8, [r6, #0x4]
 *   @0x1f77f8 sub r8, r8, #1
 *   @0x1f77fc str r8, [r6, #0x4]
 *   @0x1f7800 cmp r8, #0
 *   @0x1f7804 bne 0x1f7828 <_ZN9RVariableC2EPKS_+0x424>
 *   @0x1f7808 ldr r0, [r6]
 *   @0x1f780c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7810 mov r0, r6
 *   @0x1f7814 str r8, [r6]
 *   @0x1f7818 str r8, [r6, #0x8]
 *   @0x1f781c bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f7820 mov r0, r6
 *   @0x1f7824 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7828 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f782c mov r0, r6
 *   @0x1f7830 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7834 b 0x1f7798 <_ZN9RVariableC2EPKS_+0x394>
 *   @0x1f7838 ldr r0, [r6]
 *   @0x1f783c bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7840 str r8, [r6]
 *   @0x1f7844 str r8, [r6, #0x8]
 *   @0x1f7848 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1f784c ldr r8, [r6, #0x4]
 *   @0x1f7850 sub r8, r8, #1
 *   @0x1f7854 str r8, [r6, #0x4]
 *   @0x1f7858 cmp r8, #0
 *   @0x1f785c bne 0x1f7880 <_ZN9RVariableC2EPKS_+0x47c>
 *   @0x1f7860 ldr r0, [r6]
 *   @0x1f7864 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1f7868 mov r0, r6
 *   @0x1f786c str r8, [r6]
 *   @0x1f7870 str r8, [r6, #0x8]
 *   @0x1f7874 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1f7878 mov r0, r6
 *   @0x1f787c bl 0x27d1d0 <_ZdlPv>
 *   @0x1f7880 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1f7884 mov r0, r6
 *   @0x1f7888 bl 0x27d1d0 <_ZdlPv>
 *   @0x1f788c b 0x1f77d0 <_ZN9RVariableC2EPKS_+0x3cc>
 */
