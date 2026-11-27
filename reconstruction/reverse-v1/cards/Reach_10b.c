/* cally 逆向卡：Reach_10b —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 56 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/56 anon_25b524  0x25b524  size 10856  585 条（0x25b524..0x25df8c）｜其中 2129 条已由别的卡落锚，本节不再重复
 * @func 0x25b524 0x25db38  size 9748  585 条
 * 部分覆盖: 本节 585/2437 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_25b524×6 / anon_25b524+0x10b8×4 / anon_25b524+0x1264×3 / anon_25b524+0xa0×2 / anon_25b524+0x3a8×2 / anon_25b524+0x68c×2 / anon_25b524+0xc / anon_25b524+0x668
 * 字段偏移 top8: 0x1×89 / 0x2×49 / 0x3×27 / 0x4×20 / 0x98×12 / 0xc×11 / 0x10×11 / 0x20×7
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25b524 ldrb r3, [r0]
 *   @0x25b528 cmp r3, #128
 *   @0x25b52c bhi 0x25b56c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x444>
 *   @0x25b530 cmp r3, #126
 *   @0x25b534 bhs 0x25b57c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x454>
 *   @0x25b538 cmp r3, #4
 *   @0x25b53c bxlo lr
 *   @0x25b540 cmp r3, #5
 *   @0x25b544 bhi 0x25b5b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x488>
 *   @0x25b548 cmp r1, #0
 *   @0x25b54c bxeq lr
 *   @0x25b550 ldr r2, [pc, #0x64]
 *   @0x25b554 ldr r2, [pc, r2]
 *   @0x25b558 ldrb r3, [r2, r3]
 *   @0x25b55c add r0, r0, r3
 *   @0x25b560 ldrb r3, [r0]
 *   @0x25b564 cmp r3, #128
 *   @0x25b568 bls 0x25b530 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x408>
 *   @0x25b56c sub r2, r3, #141
 *   @0x25b570 cmp r2, #4
 *   @0x25b574 bxhi lr
 *   @0x25b578 b 0x25b550 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x428>
 *   @0x25b57c cmp r1, #0
 *   @0x25b580 bxeq lr
 *   @0x25b584 ldrb r2, [r0, #0x1]
 *   @0x25b588 ldrb r3, [r0, #0x2]
 *   @0x25b58c orr r3, r3, r2, lsl #8
 *   @0x25b590 ldrb r3, [r0, r3]!
 *   @0x25b594 cmp r3, #119
 *   @0x25b598 beq 0x25b584 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x45c>
 *   @0x25b59c ldr r2, [pc, #0x1c]
 *   @0x25b5a0 ldr r2, [pc, r2]
 *   @0x25b5a4 ldrb r3, [r2, r3]
 *   @0x25b5a8 add r0, r0, r3
 *   @0x25b5ac b 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc>
 *   @0x25b5b0 cmp r3, #118
 *   @0x25b5b4 beq 0x25b550 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x428>
 *   @0x25b5b8 bx lr
 *   @0x25b5bc andseq r6, r9, r8, lsl #5
 *   @0x25b5c0 andseq r6, r9, r12, lsr r2
 *   @0x25bba8 .word 0xfffffb8c
 *   @0x25bbac .word 0xfffffb90
 *   @0x25c26c ldrb r3, [r0, #0x2]
 *   @0x25c270 add r2, r0, #2
 *   @0x25c274 ldrb r12, [r0, #0x1]
 *   @0x25c278 cmp r3, #0
 *   @0x25c27c bne 0x25c2b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1188>
 *   @0x25c280 b 0x25c2dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11b4>
 *   @0x25c284 cmp r3, #91
 *   @0x25c288 beq 0x25c2d0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11a8>
 *   @0x25c28c cmp r3, #93
 *   @0x25c290 beq 0x25c2dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11b4>
 *   @0x25c294 ldrb r0, [r2, #0x1]
 *   @0x25c298 cmp r12, r3
 *   @0x25c29c beq 0x25c2e4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11bc>
 *   @0x25c2a0 cmp r0, #0
 *   @0x25c2a4 add r2, r2, #1
 *   @0x25c2a8 bxeq lr
 *   @0x25c2ac mov r3, r0
 *   @0x25c2b0 cmp r3, #92
 *   @0x25c2b4 bne 0x25c284 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x115c>
 *   @0x25c2b8 ldrb r0, [r2, #0x1]
 *   @0x25c2bc sub r3, r0, #92
 *   @0x25c2c0 cmp r3, #1
 *   @0x25c2c4 ldrbls r0, [r2, #0x2]
 *   @0x25c2c8 addls r2, r2, #1
 *   @0x25c2cc b 0x25c2a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1178>
 *   @0x25c2d0 ldrb r0, [r2, #0x1]
 *   @0x25c2d4 cmp r0, r12
 *   @0x25c2d8 bne 0x25c298 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1170>
 *   @0x25c2dc mov r0, #0
 *   @0x25c2e0 bx lr
 *   @0x25c2e4 cmp r0, #93
 *   @0x25c2e8 bne 0x25c2a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1178>
 *   @0x25c2ec str r2, [r1]
 *   @0x25c2f0 mov r0, #1
 *   @0x25c2f4 bx lr
 *   @0x25c5dc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x25c5e0 mov r4, r0
 *   @0x25c5e4 ldr r5, [pc, #0x198]
 *   @0x25c5e8 mov r8, r3
 *   @0x25c5ec ldrb r0, [r0]
 *   @0x25c5f0 add r10, r3, #1
 *   @0x25c5f4 ldr r5, [pc, r5]
 *   @0x25c5f8 mov r6, r1
 *   @0x25c5fc mov r7, r2
 *   @0x25c600 mov r9, #1
 *   @0x25c604 b 0x25c6a0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1578>
 *   @0x25c608 add r2, r12, #118
 *   @0x25c60c sub r1, r12, #133
 *   @0x25c610 uxtb r2, r2
 *   @0x25c614 cmp r2, #1
 *   @0x25c618 cmphi r1, #1
 *   @0x25c61c bls 0x25c6e8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x15c0>
 *   @0x25c620 cmp r12, #125
 *   @0x25c624 cmpne r12, #135
 *   @0x25c628 movne r1, #0
 *   @0x25c62c moveq r1, #1
 *   @0x25c630 beq 0x25c734 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x160c>
 *   @0x25c634 sub r2, r12, #129
 *   @0x25c638 cmp r2, #1
 *   @0x25c63c bls 0x25c758 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1630>
 *   @0x25c640 sub r2, r12, #85
 *   @0x25c644 cmp r12, #94
 *   @0x25c648 cmpne r2, #1
 *   @0x25c64c movhi r2, #0
 *   @0x25c650 movls r2, #1
 *   @0x25c654 bhi 0x25c71c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x15f4>
 *   @0x25c658 ldrb r3, [r0, #0x1]
 *   @0x25c65c cmp r3, #13
 *   @0x25c660 bne 0x25c774 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x164c>
 *   @0x25c664 ldr r3, [r7, #0x50]
 *   @0x25c668 ands r3, r6, r3
 *   @0x25c66c bne 0x25c774 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x164c>
 *   @0x25c670 cmp r8, #0
 *   @0x25c674 bgt 0x25c77c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1654>
 *   @0x25c678 ldr r2, [r7, #0x70]
 *   @0x25c67c cmp r2, #0
 *   @0x25c680 bne 0x25c77c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1654>
 *   @0x25c684 ldrb r2, [r4, #0x1]
 *   @0x25c688 ldrb r3, [r4, #0x2]
 *   @0x25c68c orr r3, r3, r2, lsl #8
 *   @0x25c690 ldrb r3, [r4, r3]!
 *   @0x25c694 cmp r3, #119
 *   @0x25c698 bne 0x25c750 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1628>
 *   @0x25c69c mov r0, r3
 *   @0x25c6a0 ldrb r0, [r5, r0]
 *   @0x25c6a4 mov r1, #0
 *   @0x25c6a8 add r0, r4, r0
 *   @0x25c6ac bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc>
 *   @0x25c6b0 ldrb r12, [r0]
 *   @0x25c6b4 add r2, r12, #120
 *   @0x25c6b8 sub r1, r12, #131
 *   @0x25c6bc uxtb r2, r2
 *   @0x25c6c0 cmp r2, #1
 *   @0x25c6c4 cmphi r1, #1
 *   @0x25c6c8 bhi 0x25c608 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14e0>
 *   @0x25c6cc mov r1, r6
 *   @0x25c6d0 mov r2, r7
 *   @0x25c6d4 mov r3, r8
 *   @0x25c6d8 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4>
 *   @0x25c6dc cmp r0, #0
 *   @0x25c6e0 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c>
 *   @0x25c6e4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c6e8 ldrb r1, [r0, #0x3]
 *   @0x25c6ec mov r3, r8
 *   @0x25c6f0 ldrb r2, [r0, #0x4]
 *   @0x25c6f4 orr r2, r2, r1, lsl #8
 *   @0x25c6f8 cmp r2, #31
 *   @0x25c6fc lslle r1, r9, r2
 *   @0x25c700 mov r2, r7
 *   @0x25c704 movgt r1, #1
 *   @0x25c708 orr r1, r1, r6
 *   @0x25c70c bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4>
 *   @0x25c710 cmp r0, #0
 *   @0x25c714 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c>
 *   @0x25c718 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c71c sub r3, r12, #1
 *   @0x25c720 cmp r12, #27
 *   @0x25c724 cmpne r3, #1
 *   @0x25c728 bls 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c>
 *   @0x25c72c mov r0, r2
 *   @0x25c730 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c734 mov r1, r6
 *   @0x25c738 mov r2, r7
 *   @0x25c73c mov r3, r8
 *   @0x25c740 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4>
 *   @0x25c744 cmp r0, #0
 *   @0x25c748 bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c>
 *   @0x25c74c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c750 mov r0, #1
 *   @0x25c754 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c758 mov r1, r6
 *   @0x25c75c mov r2, r7
 *   @0x25c760 mov r3, r10
 *   @0x25c764 bl 0x25c5dc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x14b4>
 *   @0x25c768 cmp r0, #0
 *   @0x25c76c bne 0x25c684 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x155c>
 *   @0x25c770 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c774 mov r0, r1
 *   @0x25c778 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c77c mov r0, r3
 *   @0x25c780 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x25c784 andseq r5, r9, r8, ror #3
 *   @0x25c988 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x25c98c mvn r5, #0
 *   @0x25c990 sub sp, sp, #12
 *   @0x25c994 str r5, [r1]
 *   @0x25c998 ldrb r3, [r0]
 *   @0x25c99c add r9, sp, #4
 *   @0x25c9a0 mov r8, r1
 *   @0x25c9a4 mov r4, r0
 *   @0x25c9a8 mov r7, r2
 *   @0x25c9ac mov r6, #0
 *   @0x25c9b0 add r2, r3, #118
 *   @0x25c9b4 add r3, r3, #123
 *   @0x25c9b8 mov r1, #1
 *   @0x25c9bc uxtb r2, r2
 *   @0x25c9c0 uxtb r3, r3
 *   @0x25c9c4 cmp r3, r1
 *   @0x25c9c8 cmphi r2, r1
 *   @0x25c9cc movhi r0, #3
 *   @0x25c9d0 movls r0, #5
 *   @0x25c9d4 add r0, r4, r0
 *   @0x25c9d8 bl 0x25b524 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x3fc>
 *   @0x25c9dc ldrb r2, [r0]
 *   @0x25c9e0 sub r3, r2, #29
 *   @0x25c9e4 cmp r3, #110
 *   @0x25c9e8 addls pc, pc, r3, lsl #2
 *   @0x25c9ec b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25c9f0 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc>
 *   @0x25c9f4 b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88>
 *   @0x25c9f8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25c9fc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca00 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca04 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca08 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc>
 *   @0x25ca0c b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc>
 *   @0x25ca10 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca14 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca18 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca1c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca20 b 0x25cbf0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ac8>
 *   @0x25ca24 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca28 b 0x25cbf4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1acc>
 *   @0x25ca2c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca30 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca34 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca38 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca3c b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88>
 *   @0x25ca40 b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88>
 *   @0x25ca44 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca48 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca4c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca50 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca54 b 0x25cbac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a84>
 *   @0x25ca58 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca5c b 0x25cbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a88>
 *   @0x25ca60 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca64 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca68 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca6c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca70 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca74 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca78 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca7c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca80 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca84 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca88 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca8c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca90 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca94 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca98 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25ca9c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caa0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caa4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caa8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caac b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cab0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cab4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cab8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cabc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cac0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cac4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cac8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cacc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cad0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cad4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cad8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cadc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cae0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cae4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cae8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caec b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caf0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caf4 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25caf8 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cafc b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb00 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb04 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb08 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb0c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb10 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb14 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb18 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb1c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb20 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb24 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb28 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb2c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb30 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb34 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb38 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb3c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb40 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb44 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb48 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb4c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb50 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb54 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb58 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb5c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb60 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb64 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb68 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb6c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb70 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb74 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb78 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb7c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb80 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb84 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb88 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb8c b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb90 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb94 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cb98 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cb9c b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cba0 b 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cba4 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cba8 b 0x25cc10 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1ae8>
 *   @0x25cbac add r0, r0, #2
 *   @0x25cbb0 cmp r7, #0
 *   @0x25cbb4 beq 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cbb8 cmn r5, #1
 *   @0x25cbbc beq 0x25cc54 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b2c>
 *   @0x25cbc0 ldrb r3, [r0, #0x1]
 *   @0x25cbc4 cmp r3, r6
 *   @0x25cbc8 bne 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cbcc ldrb r2, [r4, #0x1]
 *   @0x25cbd0 ldrb r3, [r4, #0x2]
 *   @0x25cbd4 orr r3, r3, r2, lsl #8
 *   @0x25cbd8 ldrb r3, [r4, r3]!
 *   @0x25cbdc cmp r3, #119
 *   @0x25cbe0 beq 0x25c9b0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1888>
 *   @0x25cbe4 mov r0, r6
 *   @0x25cbe8 str r5, [r8]
 *   @0x25cbec b 0x25cc4c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b24>
 *   @0x25cbf0 add r0, r0, #2
 *   @0x25cbf4 cmp r7, #0
 *   @0x25cbf8 beq 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cbfc cmn r5, #1
 *   @0x25cc00 bne 0x25cbc0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1a98>
 *   @0x25cc04 ldrb r6, [r0, #0x1]
 *   @0x25cc08 mov r5, #0
 *   @0x25cc0c b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4>
 *   @0x25cc10 subs r3, r2, #125
 *   @0x25cc14 mov r1, r9
 *   @0x25cc18 rsbs r2, r3, #0
 *   @0x25cc1c adcs r2, r2, r3
 *   @0x25cc20 bl 0x25c988 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1860>
 *   @0x25cc24 ldr r3, [sp, #0x4]
 *   @0x25cc28 cmp r3, #0
 *   @0x25cc2c blt 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cc30 cmn r5, #1
 *   @0x25cc34 beq 0x25cc60 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b38>
 *   @0x25cc38 cmp r6, r0
 *   @0x25cc3c bne 0x25cc48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b20>
 *   @0x25cc40 cmp r5, r3
 *   @0x25cc44 beq 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4>
 *   @0x25cc48 mov r0, #0
 *   @0x25cc4c add sp, sp, #12
 *   @0x25cc50 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x25cc54 ldrb r6, [r0, #0x1]
 *   @0x25cc58 mov r5, #1
 *   @0x25cc5c b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4>
 *   @0x25cc60 mov r5, r3
 *   @0x25cc64 mov r6, r0
 *   @0x25cc68 b 0x25cbcc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1aa4>
 *   @0x25cc6c ldr r12, [r3, #0xc]
 *   @0x25cc70 cmp r2, #0
 *   @0x25cc74 push {r4, r5, r6, r7}
 *   @0x25cc78 ldr r5, [r3, #0x74]
 *   @0x25cc7c ldr r6, [r12, r0, lsl #2]
 *   @0x25cc80 add r12, r5, r6
 *   @0x25cc84 blt 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c>
 *   @0x25cc88 ldr r0, [sp, #0x10]
 *   @0x25cc8c cmp r0, #0
 *   @0x25cc90 addeq r0, r1, r2
 *   @0x25cc94 moveq r2, r1
 *   @0x25cc98 beq 0x25cd30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c08>
 *   @0x25cc9c cmp r2, #0
 *   @0x25cca0 beq 0x25cd5c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c34>
 *   @0x25cca4 ldr r7, [r3, #0x78]
 *   @0x25cca8 cmp r1, r7
 *   @0x25ccac bhs 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28>
 *   @0x25ccb0 ldr r4, [r3, #0x38]
 *   @0x25ccb4 ldrb r0, [r5, r6]
 *   @0x25ccb8 ldrb r3, [r1]
 *   @0x25ccbc ldrb r0, [r4, r0]
 *   @0x25ccc0 ldrb r3, [r4, r3]
 *   @0x25ccc4 cmp r0, r3
 *   @0x25ccc8 bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c>
 *   @0x25cccc add r2, r1, r2
 *   @0x25ccd0 add r3, r1, #1
 *   @0x25ccd4 b 0x25ccfc <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bd4>
 *   @0x25ccd8 cmp r3, r7
 *   @0x25ccdc add r3, r3, #1
 *   @0x25cce0 beq 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28>
 *   @0x25cce4 ldrb r5, [r5]
 *   @0x25cce8 ldrb r0, [r12, #0x1]!
 *   @0x25ccec ldrb r5, [r4, r5]
 *   @0x25ccf0 ldrb r6, [r4, r0]
 *   @0x25ccf4 cmp r6, r5
 *   @0x25ccf8 bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c>
 *   @0x25ccfc cmp r3, r2
 *   @0x25cd00 mov r5, r3
 *   @0x25cd04 bne 0x25ccd8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bb0>
 *   @0x25cd08 rsb r0, r1, r3
 *   @0x25cd0c pop {r4, r5, r6, r7}
 *   @0x25cd10 bx lr
 *   @0x25cd14 ldr r4, [r3, #0x78]
 *   @0x25cd18 cmp r2, r4
 *   @0x25cd1c bhs 0x25cd50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c28>
 *   @0x25cd20 ldrb r5, [r12], #1
 *   @0x25cd24 ldrb r4, [r2], #1
 *   @0x25cd28 cmp r5, r4
 *   @0x25cd2c bne 0x25cd44 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c1c>
 *   @0x25cd30 cmp r2, r0
 *   @0x25cd34 bne 0x25cd14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1bec>
 *   @0x25cd38 rsb r0, r1, r2
 *   @0x25cd3c pop {r4, r5, r6, r7}
 *   @0x25cd40 bx lr
 *   @0x25cd44 mvn r0, #0
 *   @0x25cd48 pop {r4, r5, r6, r7}
 *   @0x25cd4c bx lr
 *   @0x25cd50 mvn r0, #1
 *   @0x25cd54 pop {r4, r5, r6, r7}
 *   @0x25cd58 bx lr
 *   @0x25cd5c mov r0, r2
 *   @0x25cd60 b 0x25cd48 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c20>
 *   @0x25cd64 ldr r3, [r0, #0x3c]
 *   @0x25cd68 push {r4, r5, r6, lr}
 *   @0x25cd6c cmp r3, #409600
 *   @0x25cd70 mov r4, r0
 *   @0x25cd74 blt 0x25cd80 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c58>
 *   @0x25cd78 mov r0, #72
 *   @0x25cd7c pop {r4, r5, r6, pc}
 *   @0x25cd80 lsl r5, r3, #1
 *   @0x25cd84 cmp r5, #409600
 *   @0x25cd88 movge r5, #409600
 *   @0x25cd8c rsb r3, r3, r5
 *   @0x25cd90 cmp r3, #99
 *   @0x25cd94 ble 0x25cd78 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c50>
 *   @0x25cd98 ldr r3, [pc, #0x6c]
 *   @0x25cd9c mov r0, r5
 *   @0x25cda0 ldr r3, [pc, r3]
 *   @0x25cda4 ldr r3, [r3]
 *   @0x25cda8 blx r3
 *   @0x25cdac subs r6, r0, #0
 *   @0x25cdb0 beq 0x25cdf0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cc8>
 *   @0x25cdb4 ldr r2, [r4, #0x3c]
 *   @0x25cdb8 ldr r1, [r4, #0x10]
 *   @0x25cdbc bl 0xb65bc <memcpy@plt>
 *   @0x25cdc0 ldr r2, [r4, #0x3c]
 *   @0x25cdc4 ldr r3, [r4, #0x20]
 *   @0x25cdc8 ldr r0, [r4, #0x10]
 *   @0x25cdcc cmp r2, #4096
 *   @0x25cdd0 rsb r3, r0, r3
 *   @0x25cdd4 add r3, r6, r3
 *   @0x25cdd8 str r3, [r4, #0x20]
 *   @0x25cddc bgt 0x25cdf8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cd0>
 *   @0x25cde0 str r6, [r4, #0x10]
 *   @0x25cde4 mov r0, #0
 *   @0x25cde8 str r5, [r4, #0x3c]
 *   @0x25cdec pop {r4, r5, r6, pc}
 *   @0x25cdf0 mov r0, #21
 *   @0x25cdf4 pop {r4, r5, r6, pc}
 *   @0x25cdf8 ldr r3, [pc, #0x10]
 *   @0x25cdfc ldr r3, [pc, r3]
 *   @0x25ce00 ldr r3, [r3]
 *   @0x25ce04 blx r3
 *   @0x25ce08 b 0x25cde0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cb8>
 *   @0x25ce0c andseq r4, r9, r4, asr #20
 *   @0x25ce10 andseq r3, r9, r12, lsl #17
 *   @0x25ce14 ldrb r3, [r0, #0x1]
 *   @0x25ce18 add r1, r0, #1
 *   @0x25ce1c sub r2, r3, #48
 *   @0x25ce20 cmp r2, #9
 *   @0x25ce24 bhi 0x25ce40 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d18>
 *   @0x25ce28 add r0, r0, #2
 *   @0x25ce2c mov r1, r0
 *   @0x25ce30 ldrb r3, [r0], #1
 *   @0x25ce34 sub r2, r3, #48
 *   @0x25ce38 cmp r2, #9
 *   @0x25ce3c bls 0x25ce2c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d04>
 *   @0x25ce40 cmp r3, #125
 *   @0x25ce44 beq 0x25cea4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d7c>
 *   @0x25ce48 cmp r3, #44
 *   @0x25ce4c beq 0x25ce58 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d30>
 *   @0x25ce50 mov r0, #0
 *   @0x25ce54 bx lr
 *   @0x25ce58 ldrb r3, [r1, #0x1]
 *   @0x25ce5c cmp r3, #125
 *   @0x25ce60 beq 0x25cea4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d7c>
 *   @0x25ce64 sub r3, r3, #48
 *   @0x25ce68 cmp r3, #9
 *   @0x25ce6c bhi 0x25ce50 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d28>
 *   @0x25ce70 ldrb r3, [r1, #0x2]
 *   @0x25ce74 add r1, r1, #2
 *   @0x25ce78 sub r2, r3, #48
 *   @0x25ce7c cmp r2, #9
 *   @0x25ce80 bhi 0x25ce94 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d6c>
 *   @0x25ce84 ldrb r3, [r1, #0x1]!
 *   @0x25ce88 sub r2, r3, #48
 *   @0x25ce8c cmp r2, #9
 *   @0x25ce90 bls 0x25ce84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d5c>
 *   @0x25ce94 subs r3, r3, #125
 *   @0x25ce98 rsbs r0, r3, #0
 *   @0x25ce9c adcs r0, r0, r3
 *   @0x25cea0 bx lr
 *   @0x25cea4 mov r0, #1
 *   @0x25cea8 bx lr
 *   @0x25da18 push {r4, r5, r6, r7}
 *   @0x25da1c mov r4, #1
 *   @0x25da20 ldrb r12, [r1]
 *   @0x25da24 ldr r5, [sp, #0x14]
 *   @0x25da28 and r6, r12, #7
 *   @0x25da2c cmp r5, #0
 *   @0x25da30 cmpne r12, #127
 *   @0x25da34 ldrb r5, [r0, r12, lsr #3]
 *   @0x25da38 orr r5, r5, r4, lsl r6
 *   @0x25da3c strb r5, [r0, r12, lsr #3]
 *   @0x25da40 bls 0x25da8c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2964>
 *   @0x25da44 ldrb r3, [r1]
 *   @0x25da48 cmp r3, #191
 *   @0x25da4c addls r0, r1, r4
 *   @0x25da50 bls 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c>
 *   @0x25da54 tst r3, #32
 *   @0x25da58 addeq r0, r1, #2
 *   @0x25da5c beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c>
 *   @0x25da60 tst r3, #16
 *   @0x25da64 addeq r0, r1, #3
 *   @0x25da68 beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c>
 *   @0x25da6c tst r3, #8
 *   @0x25da70 addeq r0, r1, #4
 *   @0x25da74 beq 0x25da84 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x295c>
 *   @0x25da78 tst r3, #4
 *   @0x25da7c addeq r0, r1, #5
 *   @0x25da80 addne r0, r1, #6
 *   @0x25da84 pop {r4, r5, r6, r7}
 *   @0x25da88 bx lr
 *   @0x25da8c cmp r2, #0
 *   @0x25da90 beq 0x25dac4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x299c>
 *   @0x25da94 ldr r5, [sp, #0x10]
 *   @0x25da98 ldr r2, [r5]
 *   @0x25da9c ldrb r2, [r2, r12]
 *   @0x25daa0 tst r2, #2
 *   @0x25daa4 beq 0x25dac4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x299c>
 *   @0x25daa8 ldr r3, [r3]
 *   @0x25daac ldrb r3, [r3, r12]
 *   @0x25dab0 and r12, r3, #7
 *   @0x25dab4 lsr r3, r3, #3
 *   @0x25dab8 ldrb r2, [r0, r3]
 *   @0x25dabc orr r4, r2, r4, lsl r12
 *   @0x25dac0 strb r4, [r0, r3]
 *   @0x25dac4 add r0, r1, #1
 *   @0x25dac8 pop {r4, r5, r6, r7}
 *   @0x25dacc bx lr
 *   @0x25dad0 cmp r2, #0
 *   @0x25dad4 push {r4, r5, r6}
 *   @0x25dad8 beq 0x25db18 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29f0>
 *   @0x25dadc sub r1, r1, #1
 *   @0x25dae0 add r6, r0, r2
 *   @0x25dae4 rsb r1, r0, r1
 *   @0x25dae8 mov r12, r0
 *   @0x25daec ldrb r5, [r12], #1
 *   @0x25daf0 ldr r4, [r3]
 *   @0x25daf4 cmp r12, r6
 *   @0x25daf8 add r4, r4, r12
 *   @0x25dafc ldrb r4, [r4, r1]
 *   @0x25db00 mvn r4, r4
 *   @0x25db04 orr r4, r4, r5
 *   @0x25db08 strb r4, [r12, #-0x1]
 *   @0x25db0c bne 0x25daec <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29c4>
 *   @0x25db10 cmp r2, #32
 *   @0x25db14 beq 0x25db30 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x2a08>
 *   @0x25db18 mov r3, #24
 *   @0x25db1c mvn r2, #0
 *   @0x25db20 strb r2, [r0, r3]
 *   @0x25db24 add r3, r3, #1
 *   @0x25db28 cmp r3, #32
 *   @0x25db2c bne 0x25db20 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x29f8>
 *   @0x25db30 pop {r4, r5, r6}
 *   @0x25db34 bx lr
 *
 * ══ §2/56 anon_22fd0c  0x22fd0c  size 4532  249 条（0x22fd0c..0x230ec0）｜其中 884 条已由别的卡落锚，本节不再重复
 * @func 0x22fd0c 0x230ec0  size 4532  249 条
 * 部分覆盖: 本节 249/1133 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: ogg_page_serialno×10 / anon_22fd0c×7 / ogg_stream_pagein×5 / 0xb655c×5 / 0xb6544×5 / ogg_page_bos×4 / ogg_stream_packetout×4 / vorbis_synthesis_pcmout×4
 * 字段偏移 top8: 0x4×22 / 0x58×19 / 0x44×10 / 0x48×9 / 0x38×8 / 0x1c8×6 / 0x2c×6 / 0x60×6
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22fd0c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x22fd10 mov r4, r2
 *   @0x22fd14 mov r5, r3
 *   @0x22fd18 cmp r4, #1
 *   @0x22fd1c sbcs r3, r5, #0
 *   @0x22fd20 mov r6, r0
 *   @0x22fd24 mov r8, r1
 *   @0x22fd28 blt 0x22fd38 <vorbis_packet_blocksize+0xbc>
 *   @0x22fd2c ldrd r2, r3, [r0, #8]
 *   @0x22fd30 adds r4, r4, r2
 *   @0x22fd34 adc r5, r5, r3
 *   @0x22fd38 cmp r4, #1
 *   @0x22fd3c sbcs r1, r5, #0
 *   @0x22fd40 add r7, r6, #24
 *   @0x22fd44 blt 0x22fdf0 <vorbis_packet_blocksize+0x174>
 *   @0x22fd48 ldrd r2, r3, [r6, #8]
 *   @0x22fd4c cmp r2, r4
 *   @0x22fd50 sbcs r1, r3, r5
 *   @0x22fd54 bge 0x22fe7c <vorbis_packet_blocksize+0x200>
 *   @0x22fd58 mov r0, r7
 *   @0x22fd5c mov r1, r8
 *   @0x22fd60 bl 0x234c90 <ogg_sync_pageseek>
 *   @0x22fd64 subs r9, r0, #0
 *   @0x22fd68 blt 0x22fe88 <vorbis_packet_blocksize+0x20c>
 *   @0x22fd6c bne 0x22feb8 <vorbis_packet_blocksize+0x23c>
 *   @0x22fd70 orrs r3, r4, r5
 *   @0x22fd74 beq 0x22fe7c <vorbis_packet_blocksize+0x200>
 *   @0x22fd78 bl 0xb6bf8 <__errno@plt>
 *   @0x22fd7c ldr r3, [r6, #0x288]
 *   @0x22fd80 cmp r3, #0
 *   @0x22fd84 str r9, [r0]
 *   @0x22fd88 beq 0x22fea0 <vorbis_packet_blocksize+0x224>
 *   @0x22fd8c ldr r3, [r6]
 *   @0x22fd90 cmp r3, #0
 *   @0x22fd94 beq 0x22fdd4 <vorbis_packet_blocksize+0x158>
 *   @0x22fd98 mov r1, #32768
 *   @0x22fd9c mov r0, r7
 *   @0x22fda0 bl 0x234b8c <ogg_sync_buffer>
 *   @0x22fda4 mov r1, #1
 *   @0x22fda8 ldr r12, [r6, #0x288]
 *   @0x22fdac mov r2, #32768
 *   @0x22fdb0 ldr r3, [r6]
 *   @0x22fdb4 blx r12
 *   @0x22fdb8 subs r1, r0, #0
 *   @0x22fdbc bgt 0x22fe64 <vorbis_packet_blocksize+0x1e8>
 *   @0x22fdc0 bne 0x22fe9c <vorbis_packet_blocksize+0x220>
 *   @0x22fdc4 bl 0xb6bf8 <__errno@plt>
 *   @0x22fdc8 ldr r3, [r0]
 *   @0x22fdcc cmp r3, #0
 *   @0x22fdd0 bne 0x22fea0 <vorbis_packet_blocksize+0x224>
 *   @0x22fdd4 mvn r0, #1
 *   @0x22fdd8 mvn r1, #0
 *   @0x22fddc pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x22fde0 ldrd r2, r3, [r6, #8]
 *   @0x22fde4 subs r2, r2, r9
 *   @0x22fde8 sbc r3, r3, r9, asr #31
 *   @0x22fdec strd r2, r3, [r6, #8]
 *   @0x22fdf0 mov r0, r7
 *   @0x22fdf4 mov r1, r8
 *   @0x22fdf8 bl 0x234c90 <ogg_sync_pageseek>
 *   @0x22fdfc subs r9, r0, #0
 *   @0x22fe00 blt 0x22fde0 <vorbis_packet_blocksize+0x164>
 *   @0x22fe04 bne 0x22feb8 <vorbis_packet_blocksize+0x23c>
 *   @0x22fe08 orrs r3, r4, r5
 *   @0x22fe0c beq 0x22fe7c <vorbis_packet_blocksize+0x200>
 *   @0x22fe10 bl 0xb6bf8 <__errno@plt>
 *   @0x22fe14 ldr r3, [r6, #0x288]
 *   @0x22fe18 cmp r3, #0
 *   @0x22fe1c str r9, [r0]
 *   @0x22fe20 beq 0x22fea0 <vorbis_packet_blocksize+0x224>
 *   @0x22fe24 ldr r3, [r6]
 *   @0x22fe28 cmp r3, #0
 *   @0x22fe2c beq 0x22fdd4 <vorbis_packet_blocksize+0x158>
 *   @0x22fe30 mov r1, #32768
 *   @0x22fe34 mov r0, r7
 *   @0x22fe38 bl 0x234b8c <ogg_sync_buffer>
 *   @0x22fe3c mov r1, #1
 *   @0x22fe40 ldr r12, [r6, #0x288]
 *   @0x22fe44 mov r2, #32768
 *   @0x22fe48 ldr r3, [r6]
 *   @0x22fe4c blx r12
 *   @0x22fe50 subs r1, r0, #0
 *   @0x22fe54 ble 0x22feac <vorbis_packet_blocksize+0x230>
 *   @0x22fe58 mov r0, r7
 *   @0x22fe5c bl 0x234c54 <ogg_sync_wrote>
 *   @0x22fe60 b 0x22fdf0 <vorbis_packet_blocksize+0x174>
 *   @0x22fe64 mov r0, r7
 *   @0x22fe68 bl 0x234c54 <ogg_sync_wrote>
 *   @0x22fe6c ldrd r2, r3, [r6, #8]
 *   @0x22fe70 cmp r2, r4
 *   @0x22fe74 sbcs r1, r3, r5
 *   @0x22fe78 blt 0x22fd58 <vorbis_packet_blocksize+0xdc>
 *   @0x22fe7c mvn r0, #0
 *   @0x22fe80 mov r1, r0
 *   @0x22fe84 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x22fe88 ldrd r2, r3, [r6, #8]
 *   @0x22fe8c subs r2, r2, r9
 *   @0x22fe90 sbc r3, r3, r9, asr #31
 *   @0x22fe94 strd r2, r3, [r6, #8]
 *   @0x22fe98 b 0x22fd48 <vorbis_packet_blocksize+0xcc>
 *   @0x22fe9c bge 0x22fd48 <vorbis_packet_blocksize+0xcc>
 *   @0x22fea0 mvn r0, #127
 *   @0x22fea4 mvn r1, #0
 *   @0x22fea8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x22feac beq 0x22fdc4 <vorbis_packet_blocksize+0x148>
 *   @0x22feb0 bge 0x22fdf0 <vorbis_packet_blocksize+0x174>
 *   @0x22feb4 b 0x22fea0 <vorbis_packet_blocksize+0x224>
 *   @0x22feb8 ldrd r2, r3, [r6, #8]
 *   @0x22febc adds r0, r2, r9
 *   @0x22fec0 adc r1, r3, r9, asr #31
 *   @0x22fec4 strd r0, r1, [r6, #8]
 *   @0x22fec8 mov r0, r2
 *   @0x22fecc mov r1, r3
 *   @0x22fed0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x22fed4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x22fed8 sub sp, sp, #60
 *   @0x22fedc ldr r8, [r0, #0x1c8]
 *   @0x22fee0 add r5, r0, #120
 *   @0x22fee4 add r4, sp, #8
 *   @0x22fee8 add r6, sp, #24
 *   @0x22feec mov r7, r0
 *   @0x22fef0 mov r10, #0
 *   @0x22fef4 mov r11, #0
 *   @0x22fef8 mvn r9, #0
 *   @0x22fefc str r1, [sp, #0x4]
 *   @0x22ff00 mvn r2, #0
 *   @0x22ff04 mov r0, r7
 *   @0x22ff08 mov r1, r4
 *   @0x22ff0c mvn r3, #0
 *   @0x22ff10 bl 0x22fd0c <vorbis_packet_blocksize+0x90>
 *   @0x22ff14 cmp r0, #0
 *   @0x22ff18 sbcs r2, r1, #0
 *   @0x22ff1c blt 0x22ff94 <vorbis_packet_blocksize+0x318>
 *   @0x22ff20 mov r0, r4
 *   @0x22ff24 bl 0x233f90 <ogg_page_bos>
 *   @0x22ff28 cmp r0, #0
 *   @0x22ff2c bne 0x22ff94 <vorbis_packet_blocksize+0x318>
 *   @0x22ff30 mov r0, r4
 *   @0x22ff34 bl 0x23409c <ogg_page_serialno>
 *   @0x22ff38 cmp r0, r8
 *   @0x22ff3c bne 0x22ff00 <vorbis_packet_blocksize+0x284>
 *   @0x22ff40 mov r0, r5
 *   @0x22ff44 mov r1, r4
 *   @0x22ff48 bl 0x234eac <ogg_stream_pagein>
 *   @0x22ff4c b 0x22ff54 <vorbis_packet_blocksize+0x2d8>
 *   @0x22ff50 bgt 0x22ffb4 <vorbis_packet_blocksize+0x338>
 *   @0x22ff54 mov r0, r5
 *   @0x22ff58 mov r1, r6
 *   @0x22ff5c bl 0x235328 <ogg_stream_packetout>
 *   @0x22ff60 cmp r0, #0
 *   @0x22ff64 bne 0x22ff50 <vorbis_packet_blocksize+0x2d4>
 *   @0x22ff68 mov r0, r4
 *   @0x22ff6c bl 0x233fb0 <ogg_page_granulepos>
 *   @0x22ff70 mvn r2, #0
 *   @0x22ff74 mvn r3, #0
 *   @0x22ff78 cmp r1, r3
 *   @0x22ff7c cmpeq r0, r2
 *   @0x22ff80 beq 0x22ff00 <vorbis_packet_blocksize+0x284>
 *   @0x22ff84 mov r0, r4
 *   @0x22ff88 bl 0x233fb0 <ogg_page_granulepos>
 *   @0x22ff8c subs r10, r0, r10
 *   @0x22ff90 sbc r11, r1, r11
 *   @0x22ff94 mov r0, r10
 *   @0x22ff98 mov r1, r11
 *   @0x22ff9c cmp r0, #0
 *   @0x22ffa0 sbcs r3, r1, #0
 *   @0x22ffa4 movlt r0, #0
 *   @0x22ffa8 movlt r1, #0
 *   @0x22ffac add sp, sp, #60
 *   @0x22ffb0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x22ffb4 ldr r0, [sp, #0x4]
 *   @0x22ffb8 mov r1, r6
 *   @0x22ffbc bl 0x22fc7c <vorbis_packet_blocksize>
 *   @0x22ffc0 cmn r9, #1
 *   @0x22ffc4 add r3, r9, r0
 *   @0x22ffc8 mov r9, r0
 *   @0x22ffcc asr r3, r3, #2
 *   @0x22ffd0 beq 0x22ff54 <vorbis_packet_blocksize+0x2d8>
 *   @0x22ffd4 adds r10, r10, r3
 *   @0x22ffd8 adc r11, r11, r3, asr #31
 *   @0x22ffdc b 0x22ff54 <vorbis_packet_blocksize+0x2d8>
 *   @0x22ffe0 push {r4, r5, r6, r7, lr}
 *   @0x22ffe4 mov r6, r0
 *   @0x22ffe8 ldr r0, [r0]
 *   @0x22ffec sub sp, sp, #12
 *   @0x22fff0 mov r4, r2
 *   @0x22fff4 mov r5, r3
 *   @0x22fff8 cmp r0, #0
 *   @0x22fffc beq 0x230040 <vorbis_packet_blocksize+0x3c4>
 *   @0x230000 ldr r1, [r6, #0x28c]
 *   @0x230004 cmp r1, #0
 *   @0x230008 beq 0x230038 <vorbis_packet_blocksize+0x3bc>
 *   @0x23000c mov r7, #0
 *   @0x230010 str r7, [sp]
 *   @0x230014 blx r1
 *   @0x230018 cmn r0, #1
 *   @0x23001c beq 0x230038 <vorbis_packet_blocksize+0x3bc>
 *   @0x230020 strd r4, r5, [r6, #8]
 *   @0x230024 add r0, r6, #24
 *   @0x230028 bl 0x235268 <ogg_sync_reset>
 *   @0x23002c mov r0, r7
 *   @0x230030 add sp, sp, #12
 *   @0x230034 pop {r4, r5, r6, r7, pc}
 *   @0x230038 mvn r0, #127
 *   @0x23003c b 0x230030 <vorbis_packet_blocksize+0x3b4>
 *   @0x230040 mvn r0, #128
 *   @0x230044 b 0x230030 <vorbis_packet_blocksize+0x3b4>
 *   @0x230294 push {r3, r4, r5, lr}
 *   @0x230298 mov r4, r0
 *   @0x23029c ldr r3, [r0, #0x58]
 *   @0x2302a0 cmp r3, #3
 *   @0x2302a4 bgt 0x230324 <vorbis_packet_blocksize+0x6a8>
 *   @0x2302a8 bne 0x23032c <vorbis_packet_blocksize+0x6b0>
 *   @0x2302ac ldr r3, [r0, #0x4]
 *   @0x2302b0 cmp r3, #0
 *   @0x2302b4 bne 0x2302fc <vorbis_packet_blocksize+0x680>
 *   @0x2302b8 add r5, r0, #480
 *   @0x2302bc ldr r1, [r0, #0x48]
 *   @0x2302c0 mov r0, r5
 *   @0x2302c4 bl 0x2273d0 <vorbis_synthesis_init>
 *   @0x2302c8 cmp r0, #0
 *   @0x2302cc bne 0x23031c <vorbis_packet_blocksize+0x6a0>
 *   @0x2302d0 add r1, r4, #560
 *   @0x2302d4 mov r0, r5
 *   @0x2302d8 bl 0x2270bc <vorbis_block_init>
 *   @0x2302dc mov r2, #0
 *   @0x2302e0 mov r3, #0
 *   @0x2302e4 mov r1, #4
 *   @0x2302e8 strd r2, r3, [r4, #104]
 *   @0x2302ec mov r0, #0
 *   @0x2302f0 str r1, [r4, #0x58]
 *   @0x2302f4 strd r2, r3, [r4, #112]
 *   @0x2302f8 pop {r3, r4, r5, pc}
 *   @0x2302fc ldr r1, [r0, #0x60]
 *   @0x230300 add r5, r0, #480
 *   @0x230304 ldr r3, [r0, #0x48]
 *   @0x230308 mov r0, r5
 *   @0x23030c add r1, r3, r1, lsl #5
 *   @0x230310 bl 0x2273d0 <vorbis_synthesis_init>
 *   @0x230314 cmp r0, #0
 *   @0x230318 beq 0x2302d0 <vorbis_packet_blocksize+0x654>
 *   @0x23031c mvn r0, #136
 *   @0x230320 pop {r3, r4, r5, pc}
 *   @0x230324 mov r0, #0
 *   @0x230328 pop {r3, r4, r5, pc}
 *   @0x23032c mvn r0, #128
 *   @0x230330 pop {r3, r4, r5, pc}
 *   @0x230eb8 beq 0x230b88 <vorbis_packet_blocksize+0xf0c>
 *   @0x230ebc mov r3, #0
 *
 * ══ §3/56 CheckLicense  0x1d23a0  size 2816  697 条（0x1d23a0..0x1d2ea0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1d23a0 0x1d2ea0  size 2816  697 条
 * 部分覆盖: 本节 697/704 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d23bc→0x544c5c, 0x1d23e4→0x544ba0, 0x1d23f8→0x544ba8, 0x1d2424→0x544b98, 0x1d2448→0x544b98, 0x1d255c→0x544bb4, 0x1d25dc→0x3f5238, 0x1d25f8→0x544bcc
 * 调用序列: YYStrBuilderYY::AddFormat(char const*, ...)×18 / 0xb6544×8 / 0xb655c×8 / 0xb65bc×5 / 0xb6538×4 / MD5Update(MD5_CTX*, unsigned char*, unsigned int)×4 / 0xb6550×3 / MD5Init(MD5_CTX*)×2
 * 字段偏移 top8: 0x-180×14 / 0x-178×12 / 0x-160×12 / 0x-168×12 / 0x-194×8 / 0x-17c×6 / 0x-164×6 / 0x-174×4
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d23a0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d23a4 vpush {d8}
 *   @0x1d23a8 add r11, sp, #40
 *   @0x1d23ac ldr r6, [pc, #0xa50]
 *   @0x1d23b0 sub sp, sp, #372
 *   @0x1d23b4 ldr r2, [pc, #0xa4c]
 *   @0x1d23b8 add r6, pc, r6
 *   @0x1d23bc ldr r3, [pc, #0xa48]
 *   @0x1d23c0 ldr r2, [r6, r2]
 *   @0x1d23c4 str r2, [r11, #-0x18c]
 *   @0x1d23c8 ldr r2, [r2]
 *   @0x1d23cc str r2, [r11, #-0x30]
 *   @0x1d23d0 ldr r5, [r6, r3]
 *   @0x1d23d4 ldr r3, [r5]
 *   @0x1d23d8 ldr r3, [r3, #0x4]
 *   @0x1d23dc cmp r3, #0
 *   @0x1d23e0 bne 0x1d247c <CheckLicense+0xdc>
 *   @0x1d23e4 ldr r3, [pc, #0xa24]
 *   @0x1d23e8 ldr r3, [r6, r3]
 *   @0x1d23ec ldrd r2, r3, [r3]
 *   @0x1d23f0 orrs r1, r2, r3
 *   @0x1d23f4 beq 0x1d2448 <CheckLicense+0xa8>
 *   @0x1d23f8 ldr r1, [pc, #0xa14]
 *   @0x1d23fc adds r4, r2, #1000
 *   @0x1d2400 adc r5, r3, #0
 *   @0x1d2404 ldr r1, [r6, r1]
 *   @0x1d2408 ldrd r0, r1, [r1]
 *   @0x1d240c cmp r1, r5
 *   @0x1d2410 cmpeq r0, r4
 *   @0x1d2414 beq 0x1d2448 <CheckLicense+0xa8>
 *   @0x1d2418 cmp r3, r1
 *   @0x1d241c cmpeq r2, r0
 *   @0x1d2420 beq 0x1d2cbc <CheckLicense+0x91c>
 *   @0x1d2424 ldr r3, [pc, #0x9ec]
 *   @0x1d2428 mov r2, #1
 *   @0x1d242c ldr r3, [r6, r3]
 *   @0x1d2430 str r2, [r3]
 *   @0x1d2434 mov r0, #0
 *   @0x1d2438 bl 0xb6688 <exit@plt>
 *   @0x1d243c cmp r0, r2
 *   @0x1d2440 sbcs r12, r1, r3
 *   @0x1d2444 blt 0x1d2de4 <CheckLicense+0xa44>
 *   @0x1d2448 ldr r3, [pc, #0x9c8]
 *   @0x1d244c ldr r3, [r6, r3]
 *   @0x1d2450 ldr r3, [r3]
 *   @0x1d2454 cmp r3, #0
 *   @0x1d2458 bne 0x1d2434 <CheckLicense+0x94>
 *   @0x1d245c ldr r12, [r11, #-0x18c]
 *   @0x1d2460 ldr r2, [r11, #-0x30]
 *   @0x1d2464 ldr r3, [r12]
 *   @0x1d2468 cmp r2, r3
 *   @0x1d246c bne 0x1d2e00 <CheckLicense+0xa60>
 *   @0x1d2470 sub sp, r11, #40
 *   @0x1d2474 vpop {d8}
 *   @0x1d2478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d247c mov r0, #3
 *   @0x1d2480 mov r3, #0
 *   @0x1d2484 str r3, [r11, #-0x178]
 *   @0x1d2488 bl 0xb6544 <malloc@plt>
 *   @0x1d248c ldr r4, [r11, #-0x178]
 *   @0x1d2490 mov r3, #3
 *   @0x1d2494 str r3, [r11, #-0x17c]
 *   @0x1d2498 mov r2, #123
 *   @0x1d249c add r4, r4, #1
 *   @0x1d24a0 str r4, [r11, #-0x178]
 *   @0x1d24a4 mvn r3, r4
 *   @0x1d24a8 add r3, r3, #3
 *   @0x1d24ac cmp r3, #0
 *   @0x1d24b0 strh r2, [r0]
 *   @0x1d24b4 movgt r2, r0
 *   @0x1d24b8 str r0, [r11, #-0x180]
 *   @0x1d24bc ble 0x1d2b78 <CheckLicense+0x7d8>
 *   @0x1d24c0 sub r0, r11, #44
 *   @0x1d24c4 sub r8, r11, #256
 *   @0x1d24c8 mov r3, #0
 *   @0x1d24cc strb r3, [r2, r4]
 *   @0x1d24d0 str r3, [r0, #-0x158]!
 *   @0x1d24d4 sub r7, r11, #169
 *   @0x1d24d8 bl 0x15f574 <_Z6YYUDIDPPc>
 *   @0x1d24dc mov r0, r8
 *   @0x1d24e0 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0x1d24e4 ldr r1, [r11, #-0x184]
 *   @0x1d24e8 sub r3, r11, #292
 *   @0x1d24ec str r3, [r11, #-0x188]
 *   @0x1d24f0 ldr r9, [pc, #0x924]
 *   @0x1d24f4 sub r4, r11, #260
 *   @0x1d24f8 mov r0, r1
 *   @0x1d24fc mov r10, r3
 *   @0x1d2500 str r1, [r11, #-0x194]
 *   @0x1d2504 bl 0xb6538 <strlen@plt>
 *   @0x1d2508 ldr r1, [r11, #-0x194]
 *   @0x1d250c add r9, pc, r9
 *   @0x1d2510 mov r2, r0
 *   @0x1d2514 mov r0, r8
 *   @0x1d2518 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x1d251c mov r0, r8
 *   @0x1d2520 bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0x1d2524 mov r0, r10
 *   @0x1d2528 mov r1, r9
 *   @0x1d252c add r10, r10, #2
 *   @0x1d2530 ldrb r2, [r7, #0x1]!
 *   @0x1d2534 bl 0xb6550 <sprintf@plt>
 *   @0x1d2538 cmp r10, r4
 *   @0x1d253c bne 0x1d2524 <CheckLicense+0x184>
 *   @0x1d2540 sub r7, r11, #384
 *   @0x1d2544 ldr r1, [pc, #0x8d4]
 *   @0x1d2548 sub r2, r11, #292
 *   @0x1d254c add r1, pc, r1
 *   @0x1d2550 mov r0, r7
 *   @0x1d2554 mov r10, r2
 *   @0x1d2558 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d255c ldr r3, [pc, #0x8c0]
 *   @0x1d2560 ldr r3, [r6, r3]
 *   @0x1d2564 sub r8, r3, #1
 *   @0x1d2568 mov r0, r10
 *   @0x1d256c mov r1, r9
 *   @0x1d2570 add r10, r10, #2
 *   @0x1d2574 ldrb r2, [r8, #0x1]!
 *   @0x1d2578 bl 0xb6550 <sprintf@plt>
 *   @0x1d257c cmp r10, r4
 *   @0x1d2580 bne 0x1d2568 <CheckLicense+0x1c8>
 *   @0x1d2584 ldr r1, [pc, #0x89c]
 *   @0x1d2588 mov r0, r7
 *   @0x1d258c sub r2, r11, #292
 *   @0x1d2590 sub r10, r11, #292
 *   @0x1d2594 add r1, pc, r1
 *   @0x1d2598 mov r4, #0
 *   @0x1d259c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d25a0 ldr r3, [r5]
 *   @0x1d25a4 mov r0, r10
 *   @0x1d25a8 mov r1, r9
 *   @0x1d25ac add r10, r10, #2
 *   @0x1d25b0 add r3, r3, r4
 *   @0x1d25b4 add r4, r4, #1
 *   @0x1d25b8 ldrb r2, [r3, #0x8]
 *   @0x1d25bc bl 0xb6550 <sprintf@plt>
 *   @0x1d25c0 cmp r4, #16
 *   @0x1d25c4 bne 0x1d25a0 <CheckLicense+0x200>
 *   @0x1d25c8 ldr r1, [pc, #0x85c]
 *   @0x1d25cc sub r2, r11, #292
 *   @0x1d25d0 mov r0, r7
 *   @0x1d25d4 add r1, pc, r1
 *   @0x1d25d8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d25dc ldr r3, [pc, #0x84c]
 *   @0x1d25e0 ldr r1, [pc, #0x84c]
 *   @0x1d25e4 mov r0, r7
 *   @0x1d25e8 ldr r3, [r6, r3]
 *   @0x1d25ec add r1, pc, r1
 *   @0x1d25f0 ldr r2, [r3]
 *   @0x1d25f4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d25f8 ldr r3, [pc, #0x838]
 *   @0x1d25fc ldr r1, [pc, #0x838]
 *   @0x1d2600 mov r0, r7
 *   @0x1d2604 ldr r3, [r6, r3]
 *   @0x1d2608 add r1, pc, r1
 *   @0x1d260c ldr r12, [r3]
 *   @0x1d2610 ldr lr, [r12, #0x38]
 *   @0x1d2614 ldr r3, [r12, #0x30]
 *   @0x1d2618 ldr r2, [r12, #0x2c]
 *   @0x1d261c str lr, [sp]
 *   @0x1d2620 ldr r12, [r12, #0x34]
 *   @0x1d2624 str r12, [sp, #0x4]
 *   @0x1d2628 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d262c bl 0x159cf4 <_Z23YoYo_GetPlatform_DoWorkv>
 *   @0x1d2630 vmov d7, r0, r1
 *   @0x1d2634 ldr r1, [pc, #0x804]
 *   @0x1d2638 mov r0, r7
 *   @0x1d263c vcvt.u32.f64 s15, d7
 *   @0x1d2640 add r1, pc, r1
 *   @0x1d2644 vmov r2, s15
 *   @0x1d2648 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d264c bl 0x15e5f8 <_Z11GetVersionMv>
 *   @0x1d2650 vmov d8, r0, r1
 *   @0x1d2654 bl 0xb6598 <floor@plt>
 *   @0x1d2658 vmov d7, r0, r1
 *   @0x1d265c mov r0, r7
 *   @0x1d2660 vcmp.f64 d7, d8
 *   @0x1d2664 vmrs APSR_nzcv, fpscr
 *   @0x1d2668 beq 0x1d2b60 <CheckLicense+0x7c0>
 *   @0x1d266c ldr r1, [pc, #0x7d0]
 *   @0x1d2670 vmov r2, r3, d8
 *   @0x1d2674 add r1, pc, r1
 *   @0x1d2678 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d267c bl 0x15f21c <_Z17GetLanguageStringv>
 *   @0x1d2680 ldr r1, [pc, #0x7c0]
 *   @0x1d2684 add r1, pc, r1
 *   @0x1d2688 mov r2, r0
 *   @0x1d268c mov r0, r7
 *   @0x1d2690 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2694 bl 0x15f230 <_Z15GetRegionStringv>
 *   @0x1d2698 ldr r1, [pc, #0x7ac]
 *   @0x1d269c add r1, pc, r1
 *   @0x1d26a0 mov r2, r0
 *   @0x1d26a4 mov r0, r7
 *   @0x1d26a8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d26ac bl 0x160240 <_Z17GetOSSpecificJSONv>
 *   @0x1d26b0 subs r4, r0, #0
 *   @0x1d26b4 beq 0x1d2700 <CheckLicense+0x360>
 *   @0x1d26b8 bl 0xb6538 <strlen@plt>
 *   @0x1d26bc ldr r8, [r11, #-0x178]
 *   @0x1d26c0 ldr r2, [r11, #-0x17c]
 *   @0x1d26c4 mvn r3, r8
 *   @0x1d26c8 add r3, r2, r3
 *   @0x1d26cc add r5, r0, #1
 *   @0x1d26d0 cmp r5, r3
 *   @0x1d26d4 bgt 0x1d2d74 <CheckLicense+0x9d4>
 *   @0x1d26d8 ldr r0, [r11, #-0x180]
 *   @0x1d26dc add r0, r0, r8
 *   @0x1d26e0 mov r1, r4
 *   @0x1d26e4 bl 0xb65a4 <strcpy@plt>
 *   @0x1d26e8 ldr r3, [r11, #-0x178]
 *   @0x1d26ec mov r0, r4
 *   @0x1d26f0 sub r3, r3, #1
 *   @0x1d26f4 add r5, r3, r5
 *   @0x1d26f8 str r5, [r11, #-0x178]
 *   @0x1d26fc bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1d2700 bl 0x15e60c <_Z16GetBrowserWidthMv>
 *   @0x1d2704 vmov d8, r0, r1
 *   @0x1d2708 bl 0x15e62c <_Z17GetBrowserHeightMv>
 *   @0x1d270c vcvt.s32.f64 s13, d8
 *   @0x1d2710 vmov r2, s13
 *   @0x1d2714 vmov d7, r0, r1
 *   @0x1d2718 ldr r1, [pc, #0x730]
 *   @0x1d271c mov r0, r7
 *   @0x1d2720 vcvt.s32.f64 s15, d7
 *   @0x1d2724 add r1, pc, r1
 *   @0x1d2728 vmov r3, s15
 *   @0x1d272c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2730 bl 0x15f244 <_Z7GetDPIXv>
 *   @0x1d2734 vmov s16, r0
 *   @0x1d2738 bl 0x15f258 <_Z7GetDPIYv>
 *   @0x1d273c ldr r1, [pc, #0x710]
 *   @0x1d2740 vcvt.f64.f32 d7, s16
 *   @0x1d2744 add r1, pc, r1
 *   @0x1d2748 vmov r2, r3, d7
 *   @0x1d274c vmov s13, r0
 *   @0x1d2750 mov r0, r7
 *   @0x1d2754 vcvt.f64.f32 d7, s13
 *   @0x1d2774 beq 0x1d2d68 <CheckLicense+0x9c8>
 *   @0x1d2778 ldr r1, [pc, #0x6dc]
 *   @0x1d277c mov r0, r7
 *   @0x1d2780 add r1, pc, r1
 *   @0x1d2784 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2788 ldrb r3, [r4]
 *   @0x1d278c cmp r3, #0
 *   @0x1d2790 bne 0x1d2bd0 <CheckLicense+0x830>
 *   @0x1d2794 bl 0x21dac0 <_Z19Audio_GetDeviceNamev>
 *   @0x1d2798 ldr r1, [pc, #0x6c0]
 *   @0x1d279c add r1, pc, r1
 *   @0x1d27a0 mov r2, r0
 *   @0x1d27a4 mov r0, r7
 *   @0x1d27a8 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d27ac ldr r3, [pc, #0x6b0]
 *   @0x1d27b0 mov r0, #1
 *   @0x1d27b4 mov r4, #0
 *   @0x1d27b8 ldr r3, [r6, r3]
 *   @0x1d27bc str r4, [r11, #-0x16c]
 *   @0x1d27c0 ldr r8, [r3]
 *   @0x1d27c4 bl 0xb6544 <malloc@plt>
 *   @0x1d27c8 mov r3, #1
 *   @0x1d27cc str r3, [r11, #-0x170]
 *   @0x1d27d0 cmp r8, r4
 *   @0x1d27d4 str r0, [r11, #-0x174]
 *   @0x1d27d8 strb r4, [r0]
 *   @0x1d27dc ble 0x1d2df8 <CheckLicense+0xa58>
 *   @0x1d27e0 ldr r3, [pc, #0x680]
 *   @0x1d27e4 mov r5, r4
 *   @0x1d27e8 ldr r12, [pc, #0x67c]
 *   @0x1d27ec add r12, pc, r12
 *   @0x1d27f0 str r12, [r11, #-0x190]
 *   @0x1d27f4 sub r12, r11, #372
 *   @0x1d27f8 str r12, [r11, #-0x188]
 *   @0x1d27fc ldr r10, [r6, r3]
 *   @0x1d2800 ldr r3, [r10]
 *   @0x1d2804 ldr r3, [r3, r4, lsl #2]
 *   @0x1d2808 ldrb r2, [r3]
 *   @0x1d280c cmp r2, #0
 *   @0x1d2810 beq 0x1d2848 <CheckLicense+0x4a8>
 *   @0x1d2814 mov r0, r3
 *   @0x1d2818 str r3, [r11, #-0x194]
 *   @0x1d281c bl 0x18ead0 <_ZNK9GMGamePad11ButtonCountEv>
 *   @0x1d2820 ldr r3, [r11, #-0x194]
 *   @0x1d2824 orr r5, r5, #1
 *   @0x1d2828 mov r9, r0
 *   @0x1d282c mov r0, r3
 *   @0x1d2830 bl 0x18ed88 <_ZNK9GMGamePad9AxisCountEv>
 *   @0x1d2834 ldr r1, [r11, #-0x190]
 *   @0x1d2838 mov r2, r9
 *   @0x1d283c mov r3, r0
 *   @0x1d2840 sub r0, r11, #372
 *   @0x1d2844 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2848 add r4, r4, #1
 *   @0x1d284c lsl r5, r5, #1
 *   @0x1d2850 cmp r4, r8
 *   @0x1d2854 bne 0x1d2800 <CheckLicense+0x460>
 *   @0x1d2858 ldr lr, [r11, #-0x174]
 *   @0x1d285c mov r2, r8
 *   @0x1d2860 ldr r1, [pc, #0x608]
 *   @0x1d2864 mov r3, r5
 *   @0x1d2868 mov r0, r7
 *   @0x1d286c mov r12, #0
 *   @0x1d2870 add r1, pc, r1
 *   @0x1d2874 str lr, [sp]
 *   @0x1d2878 str r12, [r11, #-0x16c]
 *   @0x1d287c bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2880 ldr r8, [r11, #-0x178]
 *   @0x1d2884 ldr r4, [r11, #-0x17c]
 *   @0x1d2888 mvn r3, r8
 *   @0x1d288c add r3, r4, r3
 *   @0x1d2890 cmp r3, #1
 *   @0x1d2894 ble 0x1d2c54 <CheckLicense+0x8b4>
 *   @0x1d2898 ldr r12, [r11, #-0x180]
 *   @0x1d289c ldr lr, [pc, #0x5d0]
 *   @0x1d28a0 sub r7, r11, #348
 *   @0x1d28a4 ldr r2, [pc, #0x5cc]
 *   @0x1d28a8 mov r3, #56
 *   @0x1d28ac add lr, pc, lr
 *   @0x1d28b0 mov r1, #9
 *   @0x1d28b4 add r2, pc, r2
 *   @0x1d28b8 mov r0, r7
 *   @0x1d28bc ldrh lr, [lr]
 *   @0x1d28c0 mov r5, #0
 *   @0x1d28c4 sub r4, r11, #152
 *   @0x1d28c8 strh lr, [r12, r8]
 *   @0x1d28cc ldr lr, [r11, #-0x178]
 *   @0x1d28d0 ldr r8, [r11, #-0x180]
 *   @0x1d28d4 add r12, lr, #2
 *   @0x1d28d8 add lr, lr, #1
 *   @0x1d28dc str lr, [r11, #-0x158]
 *   @0x1d28e0 lsl r12, r12, #1
 *   @0x1d28e4 str r12, [r11, #-0x14c]
 *   @0x1d28e8 add lr, r12, #14
 *   @0x1d28ec str r5, [r11, #-0x13c]
 *   @0x1d28f0 bic r12, lr, #7
 *   @0x1d28f4 str r8, [r11, #-0x15c]
 *   @0x1d28f8 sub sp, sp, r12
 *   @0x1d28fc str r5, [r11, #-0x138]
 *   @0x1d2900 add r8, sp, #8
 *   @0x1d2904 str r5, [r11, #-0x134]
 *   @0x1d2908 str r5, [r11, #-0x178]
 *   @0x1d290c str r8, [r11, #-0x150]
 *   @0x1d2910 bl 0xb69a0 <deflateInit_@plt>
 *   @0x1d2914 mov r1, #4
 *   @0x1d2918 mov r0, r7
 *   @0x1d291c bl 0xb69ac <deflate@plt>
 *   @0x1d2920 mov r0, r7
 *   @0x1d2924 bl 0xb69b8 <deflateEnd@plt>
 *   @0x1d2928 ldr r1, [r11, #-0x148]
 *   @0x1d292c movw r3, #0xaaab
 *   @0x1d2930 movt r3, #0xaaaa
 *   @0x1d2934 mov r0, r8
 *   @0x1d2938 lsl r2, r1, #2
 *   @0x1d293c add r2, r2, #2
 *   @0x1d2940 umull r12, r3, r3, r2
 *   @0x1d2944 bic r3, r3, #1
 *   @0x1d2948 add r3, r3, #14
 *   @0x1d294c bic r3, r3, #7
 *   @0x1d2950 sub sp, sp, r3
 *   @0x1d2954 add r7, sp, #8
 *   @0x1d2958 mov r2, r7
 *   @0x1d295c bl 0x1d1e60 <_Z13base64_encodePKcjPc>
 *   @0x1d2960 mov r0, r4
 *   @0x1d2964 bl 0x2140d8 <_Z7MD5InitP7MD5_CTX>
 *   @0x1d2968 ldr r1, [pc, #0x50c]
 *   @0x1d296c mov r2, #5
 *   @0x1d2970 mov r0, r4
 *   @0x1d2974 add r1, pc, r1
 *   @0x1d2978 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x1d297c mov r0, r7
 *   @0x1d2980 bl 0xb6538 <strlen@plt>
 *   @0x1d2984 mov r1, r7
 *   @0x1d2988 mov r2, r0
 *   @0x1d298c mov r0, r4
 *   @0x1d2990 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x1d2994 ldr r1, [pc, #0x4e4]
 *   @0x1d2998 mov r2, #5
 *   @0x1d299c mov r0, r4
 *   @0x1d29a0 add r1, pc, r1
 *   @0x1d29a4 bl 0x214118 <_Z9MD5UpdateP7MD5_CTXPhj>
 *   @0x1d29a8 mov r0, r4
 *   @0x1d29ac bl 0x2141d0 <_Z8MD5FinalP7MD5_CTX>
 *   @0x1d29b0 mov r0, #63
 *   @0x1d29b4 str r5, [r11, #-0x160]
 *   @0x1d29b8 bl 0xb6544 <malloc@plt>
 *   @0x1d29bc ldr lr, [pc, #0x4c0]
 *   @0x1d29c0 mov r3, #63
 *   @0x1d29c4 str r3, [r11, #-0x164]
 *   @0x1d29c8 add lr, pc, lr
 *   @0x1d29cc ldr r5, [r11, #-0x160]
 *   @0x1d29d0 add r5, r5, #41
 *   @0x1d29d4 str r5, [r11, #-0x160]
 *   @0x1d29d8 str r0, [r11, #-0x168]
 *   @0x1d29dc mov r12, r0
 *   @0x1d29e0 ldm lr!, {r0, r1, r2, r3}
 *   @0x1d29e4 stm r12!, {r0, r1, r2, r3}
 *   @0x1d29e8 ldm lr!, {r0, r1, r2, r3}
 *   @0x1d29ec stm r12!, {r0, r1, r2, r3}
 *   @0x1d29f0 ldm lr, {r0, r1, r2}
 *   @0x1d29f4 stm r12!, {r0, r1}
 *   @0x1d29f8 mov r0, r7
 *   @0x1d29fc strh r2, [r12]
 *   @0x1d2a00 bl 0x1d22c4 <_Z9urlEncodePKc>
 *   @0x1d2a04 subs r9, r0, #0
 *   @0x1d2a08 ldreq r5, [r11, #-0x160]
 *   @0x1d2a0c beq 0x1d2a50 <CheckLicense+0x6b0>
 *   @0x1d2a10 bl 0xb6538 <strlen@plt>
 *   @0x1d2a14 ldr r5, [r11, #-0x160]
 *   @0x1d2a18 ldr r2, [r11, #-0x164]
 *   @0x1d2a1c mvn r3, r5
 *   @0x1d2a20 add r3, r2, r3
 *   @0x1d2a24 add r7, r0, #1
 *   @0x1d2a28 cmp r7, r3
 *   @0x1d2a2c bgt 0x1d2cf8 <CheckLicense+0x958>
 *   @0x1d2a30 ldr r0, [r11, #-0x168]
 *   @0x1d2a34 add r0, r0, r5
 *   @0x1d2a38 mov r1, r9
 *   @0x1d2a3c bl 0xb65a4 <strcpy@plt>
 *   @0x1d2a40 ldr r5, [r11, #-0x160]
 *   @0x1d2a44 sub r5, r5, #1
 *   @0x1d2a48 add r5, r5, r7
 *   @0x1d2a4c str r5, [r11, #-0x160]
 *   @0x1d2a50 ldr r7, [r11, #-0x164]
 *   @0x1d2a54 mvn r3, r5
 *   @0x1d2a58 add r3, r7, r3
 *   @0x1d2a5c cmp r3, #10
 *   @0x1d2a60 ble 0x1d2bec <CheckLicense+0x84c>
 *   @0x1d2a64 ldr r12, [r11, #-0x168]
 *   @0x1d2a68 ldr r3, [pc, #0x418]
 *   @0x1d2a6c add r2, r12, r5
 *   @0x1d2a70 ldr r8, [pc, #0x414]
 *   @0x1d2a74 sub r7, r11, #360
 *   @0x1d2a78 add r3, pc, r3
 *   @0x1d2a7c add r8, pc, r8
 *   @0x1d2a80 ldm r3!, {r0, r1}
 *   @0x1d2a84 ldrh lr, [r3]
 *   @0x1d2a88 ldrb r3, [r3, #0x2]
 *   @0x1d2a8c str r0, [r12, r5]
 *   @0x1d2a90 mov r0, #12
 *   @0x1d2a94 str r1, [r2, #0x4]
 *   @0x1d2a98 strh lr, [r2, #8]
 *   @0x1d2a9c strb r3, [r2, #0xa]
 *   @0x1d2aa0 ldr r3, [r11, #-0x160]
 *   @0x1d2aa4 add r3, r3, #10
 *   @0x1d2aa8 str r3, [r11, #-0x160]
 *   @0x1d2aac bl 0xc4600 <_Z8YYRandomi>
 *   @0x1d2ab0 cmp r0, #15
 *   @0x1d2ab4 mov r5, r0
 *   @0x1d2ab8 mov r10, r0
 *   @0x1d2abc bgt 0x1d2ae8 <CheckLicense+0x748>
 *   @0x1d2ac0 add r3, r4, r10
 *   @0x1d2ac4 mov r0, r7
 *   @0x1d2ac8 add r10, r10, #1
 *   @0x1d2acc mov r1, r8
 *   @0x1d2ad0 ldrb r2, [r3, #0x58]
 *   @0x1d2ad4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2ad8 rsb r3, r5, r10
 *   @0x1d2adc cmp r3, #1
 *   @0x1d2ae0 cmple r10, #15
 *   @0x1d2ae4 ble 0x1d2ac0 <CheckLicense+0x720>
 *   @0x1d2ae8 mov r4, #0
 *   @0x1d2aec ldr r0, [r11, #-0x168]
 *   @0x1d2af0 mov r2, r4
 *   @0x1d2af4 mov r3, r4
 *   @0x1d2af8 mvn r1, #0
 *   @0x1d2afc str r4, [sp]
 *   @0x1d2b00 str r4, [r11, #-0x160]
 *   @0x1d2b04 bl 0x18fc68 <_ZN8LoadSave8HTTP_GetEPKciPFiP16HTTP_REQ_CONTEXTPvPiEPFvS3_ES4_>
 *   @0x1d2b08 mov r0, r9
 *   @0x1d2b0c bl 0xdc414 <_Z9YYStrFreePKc>
 *   @0x1d2b10 ldr r0, [r11, #-0x168]
 *   @0x1d2b14 cmp r0, r4
 *   @0x1d2b18 beq 0x1d2b2c <CheckLicense+0x78c>
 *   @0x1d2b1c bl 0xb655c <free@plt>
 *   @0x1d2b20 str r4, [r11, #-0x168]
 *   @0x1d2b24 str r4, [r11, #-0x164]
 *   @0x1d2b28 str r4, [r11, #-0x160]
 *   @0x1d2b2c ldr r0, [r11, #-0x174]
 *   @0x1d2b30 cmp r0, #0
 *   @0x1d2b34 beq 0x1d2b4c <CheckLicense+0x7ac>
 *   @0x1d2b38 bl 0xb655c <free@plt>
 *   @0x1d2b3c mov r3, #0
 *   @0x1d2b40 str r3, [r11, #-0x174]
 *   @0x1d2b44 str r3, [r11, #-0x170]
 *   @0x1d2b48 str r3, [r11, #-0x16c]
 *   @0x1d2b4c ldr r0, [r11, #-0x180]
 *   @0x1d2b50 cmp r0, #0
 *   @0x1d2b54 beq 0x1d23e4 <CheckLicense+0x44>
 *   @0x1d2b58 bl 0xb655c <free@plt>
 *   @0x1d2b5c b 0x1d23e4 <CheckLicense+0x44>
 *   @0x1d2b60 vcvt.u32.f64 s15, d8
 *   @0x1d2b64 ldr r1, [pc, #0x324]
 *   @0x1d2b68 add r1, pc, r1
 *   @0x1d2b6c vmov r2, s15
 *   @0x1d2b70 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2b74 b 0x1d267c <CheckLicense+0x2dc>
 *   @0x1d2b78 add r3, r4, #1
 *   @0x1d2b7c mov r7, #4
 *   @0x1d2b80 cmp r7, r3
 *   @0x1d2b84 ldr r8, [r11, #-0x180]
 *   @0x1d2b88 addlt r3, r3, r3, lsl #1
 *   @0x1d2b8c addlt r3, r3, r3, lsr #31
 *   @0x1d2b90 asrlt r7, r3, #1
 *   @0x1d2b94 mov r0, r7
 *   @0x1d2b98 bl 0xb6544 <malloc@plt>
 *   @0x1d2b9c mov r2, #3
 *   @0x1d2ba0 mov r1, r8
 *   @0x1d2ba4 str r0, [r11, #-0x180]
 *   @0x1d2ba8 bl 0xb65bc <memcpy@plt>
 *   @0x1d2bac cmp r8, #0
 *   @0x1d2bb0 str r7, [r11, #-0x17c]
 *   @0x1d2bb4 moveq r2, r0
 *   @0x1d2bb8 beq 0x1d24c0 <CheckLicense+0x120>
 *   @0x1d2bbc mov r0, r8
 *   @0x1d2bc0 bl 0xb655c <free@plt>
 *   @0x1d2bc4 ldr r2, [r11, #-0x180]
 *   @0x1d2bc8 ldr r4, [r11, #-0x178]
 *   @0x1d2bcc b 0x1d24c0 <CheckLicense+0x120>
 *   @0x1d2bd0 ldr r1, [pc, #0x2bc]
 *   @0x1d2bd4 mov r0, r7
 *   @0x1d2bd8 ldr r2, [pc, #0x2b8]
 *   @0x1d2bdc add r1, pc, r1
 *   @0x1d2be0 add r2, pc, r2
 *   @0x1d2be4 bl 0x15e0e8 <_ZN14YYStrBuilderYY9AddFormatEPKcz>
 *   @0x1d2be8 b 0x1d27ac <CheckLicense+0x40c>
 *   @0x1d2bec cmp r7, #0
 *   @0x1d2bf0 add r3, r5, #11
 *   @0x1d2bf4 addne r10, r7, r7, lsl #1
 *   @0x1d2bf8 ldr r8, [r11, #-0x168]
 *   @0x1d2bfc moveq r10, #16
 *   @0x1d2c00 addne r10, r10, r10, lsr #31
 *   @0x1d2c04 asrne r10, r10, #1
 *   @0x1d2c08 cmp r10, r3
 *   @0x1d2c0c addlt r3, r3, r3, lsl #1
 *   @0x1d2c10 addlt r3, r3, r3, lsr #31
 *   @0x1d2c14 asrlt r10, r3, #1
 *   @0x1d2c18 mov r0, r10
 *   @0x1d2c1c bl 0xb6544 <malloc@plt>
 *   @0x1d2c20 mov r2, r7
 *   @0x1d2c24 mov r1, r8
 *   @0x1d2c28 str r0, [r11, #-0x168]
 *   @0x1d2c2c bl 0xb65bc <memcpy@plt>
 *   @0x1d2c30 cmp r8, #0
 *   @0x1d2c34 str r10, [r11, #-0x164]
 *   @0x1d2c38 mov r12, r0
 *   @0x1d2c3c beq 0x1d2a68 <CheckLicense+0x6c8>
 *   @0x1d2c40 mov r0, r8
 *   @0x1d2c44 bl 0xb655c <free@plt>
 *   @0x1d2c48 ldr r12, [r11, #-0x168]
 *   @0x1d2c4c ldr r5, [r11, #-0x160]
 *   @0x1d2c50 b 0x1d2a68 <CheckLicense+0x6c8>
 *   @0x1d2c54 cmp r4, #0
 *   @0x1d2c58 add r3, r8, #2
 *   @0x1d2c5c addne r5, r4, r4, lsl #1
 *   @0x1d2c60 ldr r7, [r11, #-0x180]
 *   @0x1d2c64 moveq r5, #3
 *   @0x1d2c68 addne r5, r5, r5, lsr #31
 *   @0x1d2c6c asrne r5, r5, #1
 *   @0x1d2c70 cmp r5, r3
 *   @0x1d2c74 addlt r3, r3, r3, lsl #1
 *   @0x1d2c78 addlt r3, r3, r3, lsr #31
 *   @0x1d2c7c asrlt r5, r3, #1
 *   @0x1d2c80 mov r0, r5
 *   @0x1d2c84 bl 0xb6544 <malloc@plt>
 *   @0x1d2c88 mov r2, r4
 *   @0x1d2c8c mov r1, r7
 *   @0x1d2c90 str r0, [r11, #-0x180]
 *   @0x1d2c94 bl 0xb65bc <memcpy@plt>
 *   @0x1d2c98 cmp r7, #0
 *   @0x1d2c9c str r5, [r11, #-0x17c]
 *   @0x1d2ca0 mov r12, r0
 *   @0x1d2ca4 beq 0x1d289c <CheckLicense+0x4fc>
 *   @0x1d2ca8 mov r0, r7
 *   @0x1d2cac bl 0xb655c <free@plt>
 *   @0x1d2cb0 ldr r12, [r11, #-0x180]
 *   @0x1d2cb4 ldr r8, [r11, #-0x178]
 *   @0x1d2cb8 b 0x1d289c <CheckLicense+0x4fc>
 *   @0x1d2cbc ldr r1, [pc, #0x1d8]
 *   @0x1d2cc0 ldr r1, [r6, r1]
 *   @0x1d2cc4 ldrd r0, r1, [r1]
 *   @0x1d2cc8 mov r4, r0
 *   @0x1d2ccc mov r5, r1
 *   @0x1d2cd0 subs r4, r4, r2
 *   @0x1d2cd4 sbc r5, r5, r3
 *   @0x1d2cd8 cmp r4, #900
 *   @0x1d2cdc sbcs r12, r5, #0
 *   @0x1d2ce0 blt 0x1d243c <CheckLicense+0x9c>
 *   @0x1d2ce4 ldr r3, [pc, #0x12c]
 *   @0x1d2ce8 mov r2, #2
 *   @0x1d2cec ldr r3, [r6, r3]
 *   @0x1d2cf0 str r2, [r3]
 *   @0x1d2cf4 b 0x1d2434 <CheckLicense+0x94>
 *   @0x1d2cf8 cmp r2, #0
 *   @0x1d2cfc add r3, r7, r5
 *   @0x1d2d00 ldr r8, [r11, #-0x168]
 *   @0x1d2d04 movne r10, r2
 *   @0x1d2d08 moveq r10, r7
 *   @0x1d2d0c add r10, r10, r10, lsl #1
 *   @0x1d2d10 str r2, [r11, #-0x194]
 *   @0x1d2d14 add r10, r10, r10, lsr #31
 *   @0x1d2d18 asr r10, r10, #1
 *   @0x1d2d1c cmp r10, r3
 *   @0x1d2d20 addlt r3, r3, r3, lsl #1
 *   @0x1d2d24 addlt r3, r3, r3, lsr #31
 *   @0x1d2d28 asrlt r10, r3, #1
 *   @0x1d2d2c mov r0, r10
 *   @0x1d2d30 bl 0xb6544 <malloc@plt>
 *   @0x1d2d34 ldr r2, [r11, #-0x194]
 *   @0x1d2d38 mov r1, r8
 *   @0x1d2d3c str r0, [r11, #-0x168]
 *   @0x1d2d40 bl 0xb65bc <memcpy@plt>
 *   @0x1d2d44 cmp r8, #0
 *   @0x1d2d48 str r10, [r11, #-0x164]
 *   @0x1d2d4c moveq r0, r0
 *   @0x1d2d50 beq 0x1d2a34 <CheckLicense+0x694>
 *   @0x1d2d54 mov r0, r8
 *   @0x1d2d58 bl 0xb655c <free@plt>
 *   @0x1d2d5c ldr r0, [r11, #-0x168]
 *   @0x1d2d60 ldr r5, [r11, #-0x160]
 *   @0x1d2d64 b 0x1d2a34 <CheckLicense+0x694>
 *   @0x1d2d68 bl 0x21c5b8 <_Z22Audio_GetRecorderCountv>
 *   @0x1d2d6c mov r2, r0
 *   @0x1d2d70 b 0x1d2778 <CheckLicense+0x3d8>
 *   @0x1d2d74 cmp r2, #0
 *   @0x1d2d78 add r3, r5, r8
 *   @0x1d2d7c ldr r9, [r11, #-0x180]
 *   @0x1d2d80 movne r10, r2
 *   @0x1d2d84 moveq r10, r5
 *   @0x1d2d88 add r10, r10, r10, lsl #1
 *   @0x1d2d8c str r2, [r11, #-0x194]
 *   @0x1d2d90 add r10, r10, r10, lsr #31
 *   @0x1d2d94 asr r10, r10, #1
 *   @0x1d2d98 cmp r10, r3
 *   @0x1d2d9c addlt r3, r3, r3, lsl #1
 *   @0x1d2da0 addlt r3, r3, r3, lsr #31
 *   @0x1d2da4 asrlt r10, r3, #1
 *   @0x1d2da8 mov r0, r10
 *   @0x1d2dac bl 0xb6544 <malloc@plt>
 *   @0x1d2db0 ldr r2, [r11, #-0x194]
 *   @0x1d2db4 mov r1, r9
 *   @0x1d2db8 str r0, [r11, #-0x180]
 *   @0x1d2dbc bl 0xb65bc <memcpy@plt>
 *   @0x1d2dc0 cmp r9, #0
 *   @0x1d2dc4 str r10, [r11, #-0x17c]
 *   @0x1d2dc8 moveq r0, r0
 *   @0x1d2dcc beq 0x1d26dc <CheckLicense+0x33c>
 *   @0x1d2dd0 mov r0, r9
 *   @0x1d2dd4 bl 0xb655c <free@plt>
 *   @0x1d2dd8 ldr r0, [r11, #-0x180]
 *   @0x1d2ddc ldr r8, [r11, #-0x178]
 *   @0x1d2de0 b 0x1d26dc <CheckLicense+0x33c>
 *   @0x1d2de4 ldr r3, [pc, #0x2c]
 *   @0x1d2de8 mov r2, #3
 *   @0x1d2dec ldr r3, [r6, r3]
 *   @0x1d2df0 str r2, [r3]
 *   @0x1d2df4 b 0x1d2434 <CheckLicense+0x94>
 *   @0x1d2df8 mov r5, r4
 *   @0x1d2dfc b 0x1d2858 <CheckLicense+0x4b8>
 *   @0x1d2e00 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1d2e04 mlaeq r1, r8, r8, pc
 *   @0x1d2e08 .word 0xffffbd00
 *   @0x1d2e0c .word 0xffffef04
 *   @0x1d2e10 .word 0xffffef08
 *   @0x1d2e14 .word 0xffffef0c
 *   @0x1d2e18 .word 0xffffef10
 *   @0x1d2e1c mulseq r5, r8, r12
 *   @0x1d2e20 ldrheq lr, [r7], -r12
 *   @0x1d2e24 .word 0xffffef14
 *   @0x1d2e28 andseq lr, r7, r4, lsl #19
 *   @0x1d2e2c andseq lr, r7, r4, asr r9
 *   @0x1d2e30 .word 0xffffef18
 *   @0x1d2e34 andseq lr, r7, r12, asr #18
 *   @0x1d2e38 .word 0xffffe79c
 *   @0x1d2e3c andseq lr, r7, r0, asr #18
 *   @0x1d2e40 andseq lr, r7, r0, lsr #18
 *   @0x1d2e44 andseq lr, r7, r0, lsl r9
 *   @0x1d2e48 andseq lr, r7, r0, lsl r9
 *   @0x1d2e4c andseq lr, r7, r8, lsl #18
 *   @0x1d2e50 mulseq r7, r0, r8
 *   @0x1d2e54 andseq lr, r7, r4, lsl #17
 *   @0x1d2e58 .word 0xffffd3fc
 *   @0x1d2e5c andseq lr, r7, r0, ror #16
 *   @0x1d2e60 andseq lr, r7, r4, asr r8
 *   @0x1d2e64 .word 0xffffde10
 *   @0x1d2e68 .word 0xffffde14
 *   @0x1d2e6c andseq lr, r7, r4, lsl #17
 *   @0x1d2e70 mulseq r7, r0, r7
 *   @0x1d2e74 andseq lr, r7, r0, ror r7
 *   @0x1d2e78 andseq lr, r7, r12, ror #14
 *   @0x1d2e7c ldrheq lr, [r7], -r4
 *   @0x1d2e80 mulseq r7, r0, r6
 *   @0x1d2e84 andseq lr, r7, r0, ror r6
 *   @0x1d2e88 andseq lr, r7, r12, ror #11
 *   @0x1d2e8c andseq pc, r5, r8, lsr #14
 *   @0x1d2e90 andseq lr, r7, r8, lsl #8
 *   @0x1d2e94 andseq lr, r7, r4, lsl r4
 *   @0x1d2e98 andseq pc, r5, r0, ror #12
 *   @0x1d2e9c .word 0xffffef1c
 *
 * ══ §4/56 _DrawArray  0x184868  size 2336  577 条（0x184868..0x185188）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x184868 0x185188  size 2336  577 条
 * 部分覆盖: 本节 577/584 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1848bc→0x4859b0, 0x1848c0→0x5428e8, 0x1848c4→0x3f26dc, 0x184910→0x479c7c, 0x184998→0x479c70, 0x1849b0→0x479b9c, 0x1849f0→0x479c78, 0x184a24→0x479c70
 * 调用序列: GetVertexFormat(int)×2 / _DrawArray(ePrimType, int, void*, int, void*)+0x474×2 / _DrawArray(ePrimType, int, void*, int, void*)+0x188 / StartShaderBlock(int) / _DrawArray(ePrimType, int, void*, int, void*)+0x824 / _DrawArray(ePrimType, int, void*, int, void*)+0x464
 * 字段偏移 top8: 0x4×20 / 0x14×13 / 0x8×11 / 0xc×7 / 0x1c×7 / 0x18×6 / 0x10×4 / 0x2×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x184868 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18486c sub sp, sp, #36
 *   @0x184870 ldr r4, [pc, #0x8dc]
 *   @0x184874 sub r0, r0, #1
 *   @0x184878 ldr r7, [sp, #0x48]
 *   @0x18487c mov r8, r2
 *   @0x184880 add r4, pc, r4
 *   @0x184884 str r1, [sp, #0x10]
 *   @0x184888 mov r9, r3
 *   @0x18488c str r7, [sp, #0x14]
 *   @0x184890 cmp r0, #5
 *   @0x184894 addls pc, pc, r0, lsl #2
 *   @0x184898 b 0x184d04 <_Z10_DrawArray9ePrimTypeiPviS0_+0x49c>
 *   @0x18489c b 0x184adc <_Z10_DrawArray9ePrimTypeiPviS0_+0x274>
 *   @0x1848a0 b 0x184ae8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x280>
 *   @0x1848a4 b 0x1848b4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4c>
 *   @0x1848a8 b 0x184aa0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x238>
 *   @0x1848ac b 0x184ac4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x25c>
 *   @0x1848b0 b 0x184ad0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x268>
 *   @0x1848b4 mov r7, #3
 *   @0x1848d4 ldrb r6, [r2]
 *   @0x1848d8 ldrb r3, [r3]
 *   @0x1848dc cmp r6, #0
 *   @0x1848e0 ldr r5, [r1]
 *   @0x1848e4 str r1, [sp, #0xc]
 *   @0x1848e8 movne r6, #3
 *   @0x1848ec moveq r6, #2
 *   @0x1848f0 cmp r3, #0
 *   @0x1848f4 movne r6, #3
 *   @0x1848f8 cmp r5, #0
 *   @0x1848fc bne 0x184a14 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1ac>
 *   @0x184900 tst r9, #16777216
 *   @0x184904 beq 0x184af4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x28c>
 *   @0x184908 mov r0, r9
 *   @0x18490c bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x184910 ldr r3, [pc, #0x84c]
 *   @0x184914 ldr r6, [r4, r3]
 *   @0x184918 ldr r3, [r6]
 *   @0x18491c mov r7, r0
 *   @0x184920 movw r0, #0x8074
 *   @0x184924 ldr r10, [r7, #0xc]
 *   @0x184928 blx r3
 *   @0x18492c ldr r3, [r6]
 *   @0x184930 movw r0, #0x8076
 *   @0x184934 blx r3
 *   @0x184938 ldr r3, [r6]
 *   @0x18493c movw r0, #0x8078
 *   @0x184940 blx r3
 *   @0x184944 ldr r3, [r6]
 *   @0x184948 movw r0, #0x8075
 *   @0x18494c blx r3
 *   @0x184950 ldr r12, [r7, #0x4]
 *   @0x184954 cmp r12, #0
 *   @0x184958 ble 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188>
 *   @0x18495c mov r6, r5
 *   @0x184960 str r9, [sp, #0x1c]
 *   @0x184964 ldr r9, [r7, #0x8]
 *   @0x184968 add r11, r9, r5
 *   @0x18496c ldr r3, [r11, #0x8]
 *   @0x184970 sub r3, r3, #1
 *   @0x184974 cmp r3, #3
 *   @0x184978 addls pc, pc, r3, lsl #2
 *   @0x18497c b 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174>
 *   @0x184980 b 0x184a80 <_Z10_DrawArray9ePrimTypeiPviS0_+0x218>
 *   @0x184984 b 0x184a24 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1bc>
 *   @0x184988 b 0x184a44 <_Z10_DrawArray9ePrimTypeiPviS0_+0x1dc>
 *   @0x18498c b 0x184990 <_Z10_DrawArray9ePrimTypeiPviS0_+0x128>
 *   @0x184990 ldr r1, [sp, #0x14]
 *   @0x184994 movw r0, #0x8078
 *   @0x184998 ldr r3, [pc, #0x7c8]
 *   @0x18499c cmp r1, #0
 *   @0x1849a0 beq 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174>
 *   @0x1849a4 ldr r3, [r4, r3]
 *   @0x1849a8 ldr r3, [r3]
 *   @0x1849ac blx r3
 *   @0x1849b0 ldr r0, [pc, #0x7b4]
 *   @0x1849b4 ldr r3, [r11]
 *   @0x1849b8 ldr r12, [r4, r0]
 *   @0x1849bc add r2, r10, r5
 *   @0x1849c0 ldr r1, [r10, r5]
 *   @0x1849c4 add r3, r8, r3
 *   @0x1849c8 ldr r0, [r2, #0x4]
 *   @0x1849cc ldr r12, [r12]
 *   @0x1849d0 ldr r2, [r7, #0x14]
 *   @0x1849d4 blx r12
 *   @0x1849d8 ldr r12, [r7, #0x4]
 *   @0x1849dc add r6, r6, #1
 *   @0x1849e0 add r5, r5, #16
 *   @0x1849e4 cmp r12, r6
 *   @0x1849e8 bgt 0x184964 <_Z10_DrawArray9ePrimTypeiPviS0_+0xfc>
 *   @0x1849ec ldr r9, [sp, #0x1c]
 *   @0x1849f0 ldr r3, [pc, #0x778]
 *   @0x1849f4 mov r1, #0
 *   @0x1849f8 ldr r0, [sp, #0x18]
 *   @0x1849fc ldr r2, [sp, #0x10]
 *   @0x184a00 ldr r3, [r4, r3]
 *   @0x184a04 ldr r3, [r3]
 *   @0x184a08 blx r3
 *   @0x184a0c ldr r7, [sp, #0xc]
 *   @0x184a10 ldr r5, [r7]
 *   @0x184a14 cmp r5, #1
 *   @0x184a18 beq 0x184bc8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x360>
 *   @0x184a1c add sp, sp, #36
 *   @0x184a20 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x184a24 ldr r3, [pc, #0x73c]
 *   @0x184a28 movw r0, #0x8076
 *   @0x184a2c ldr r3, [r4, r3]
 *   @0x184a30 ldr r3, [r3]
 *   @0x184a34 blx r3
 *   @0x184a38 ldr r0, [pc, #0x734]
 *   @0x184a3c ldr r3, [r9, r5]
 *   @0x184a40 b 0x1849b8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x150>
 *   @0x184a44 ldr r3, [pc, #0x71c]
 *   @0x184a48 movw r0, #0x8075
 *   @0x184a4c ldr r3, [r4, r3]
 *   @0x184a50 ldr r3, [r3]
 *   @0x184a54 blx r3
 *   @0x184a58 ldr r3, [pc, #0x718]
 *   @0x184a5c ldr r2, [r9, r5]
 *   @0x184a60 ldr r0, [r10, r5]
 *   @0x184a64 ldr r3, [r4, r3]
 *   @0x184a68 add r2, r8, r2
 *   @0x184a6c ldr r1, [r7, #0x14]
 *   @0x184a70 ldr r3, [r3]
 *   @0x184a74 blx r3
 *   @0x184a78 ldr r12, [r7, #0x4]
 *   @0x184a7c b 0x1849dc <_Z10_DrawArray9ePrimTypeiPviS0_+0x174>
 *   @0x184a80 ldr r3, [pc, #0x6e0]
 *   @0x184a84 movw r0, #0x8074
 *   @0x184a88 ldr r3, [r4, r3]
 *   @0x184a8c ldr r3, [r3]
 *   @0x184a90 blx r3
 *   @0x184a94 ldr r0, [pc, #0x6e0]
 *   @0x184a98 ldr r3, [r9, r5]
 *   @0x184a9c b 0x1849b8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x150>
 *   @0x184aa0 ldr r3, [pc, #0x6d8]
 *   @0x184aa4 mov r7, #4
 *   @0x184aa8 str r7, [sp, #0x18]
 *   @0x184aac ldr r3, [r4, r3]
 *   @0x184ab0 ldr r7, [sp, #0x10]
 *   @0x184ab4 ldr r2, [r3]
 *   @0x184ab8 add r2, r2, r7
 *   @0x184abc str r2, [r3]
 *   @0x184ac0 b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54>
 *   @0x184ac4 ldr r3, [pc, #0x6b4]
 *   @0x184ac8 mov r7, #5
 *   @0x184acc b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240>
 *   @0x184ad0 ldr r3, [pc, #0x6a8]
 *   @0x184ad4 mov r7, #6
 *   @0x184ad8 b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240>
 *   @0x184adc ldr r3, [pc, #0x69c]
 *   @0x184ae0 mov r7, #0
 *   @0x184ae4 b 0x184aa8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x240>
 *   @0x184ae8 mov r7, #1
 *   @0x184aec str r7, [sp, #0x18]
 *   @0x184af0 b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54>
 *   @0x184af4 cmp r9, #16
 *   @0x184af8 beq 0x184f10 <_Z10_DrawArray9ePrimTypeiPviS0_+0x6a8>
 *   @0x184afc cmp r9, #24
 *   @0x184b00 ldr r3, [pc, #0x660]
 *   @0x184b04 beq 0x184df4 <_Z10_DrawArray9ePrimTypeiPviS0_+0x58c>
 *   @0x184b08 ldr r5, [r4, r3]
 *   @0x184b0c movw r0, #0x8074
 *   @0x184b10 ldr r3, [r5]
 *   @0x184b14 blx r3
 *   @0x184b18 ldr r12, [pc, #0x65c]
 *   @0x184b1c movw r1, #0x1406
 *   @0x184b20 mov r2, #36
 *   @0x184b24 mov r0, r6
 *   @0x184b28 mov r3, r8
 *   @0x184b2c ldr r12, [r4, r12]
 *   @0x184b30 ldr r12, [r12]
 *   @0x184b34 blx r12
 *   @0x184b38 ldr r3, [r5]
 *   @0x184b3c movw r0, #0x8076
 *   @0x184b40 blx r3
 *   @0x184b44 ldr r12, [pc, #0x628]
 *   @0x184b48 mov r0, #4
 *   @0x184b4c movw r1, #0x1401
 *   @0x184b50 mov r2, #36
 *   @0x184b54 add r3, r8, #24
 *   @0x184b58 ldr r12, [r4, r12]
 *   @0x184b5c ldr r12, [r12]
 *   @0x184b60 blx r12
 *   @0x184b64 ldr r7, [sp, #0x14]
 *   @0x184b68 cmp r7, #0
 *   @0x184b6c beq 0x184ffc <_Z10_DrawArray9ePrimTypeiPviS0_+0x794>
 *   @0x184b70 ldr r3, [r5]
 *   @0x184b74 movw r0, #0x8078
 *   @0x184b78 blx r3
 *   @0x184b7c ldr r12, [pc, #0x5e8]
 *   @0x184b80 mov r0, #2
 *   @0x184b84 movw r1, #0x1406
 *   @0x184b88 mov r2, #36
 *   @0x184b8c add r3, r8, #28
 *   @0x184b90 ldr r12, [r4, r12]
 *   @0x184b94 ldr r12, [r12]
 *   @0x184b98 blx r12
 *   @0x184b9c ldr r3, [r5]
 *   @0x184ba0 movw r0, #0x8075
 *   @0x184ba4 blx r3
 *   @0x184ba8 ldr r3, [pc, #0x5c8]
 *   @0x184bac movw r0, #0x1406
 *   @0x184bb0 mov r1, #36
 *   @0x184bb4 add r2, r8, #12
 *   @0x184bb8 ldr r3, [r4, r3]
 *   @0x184bbc ldr r3, [r3]
 *   @0x184bc0 blx r3
 *   @0x184bc4 b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188>
 *   @0x184bc8 mov r0, r9
 *   @0x184bcc bl 0x18426c <_Z16StartShaderBlocki>
 *   @0x184bd0 subs r5, r0, #0
 *   @0x184bd4 beq 0x184a1c <_Z10_DrawArray9ePrimTypeiPviS0_+0x1b4>
 *   @0x184bd8 ands r3, r9, #16777216
 *   @0x184bdc beq 0x184d10 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4a8>
 *   @0x184be0 mov r0, r9
 *   @0x184be4 bl 0x1e2cd0 <_Z15GetVertexFormati>
 *   @0x184be8 ldr r10, [r5, #0x30]
 *   @0x184bec cmp r10, #0
 *   @0x184bf0 mov r11, r0
 *   @0x184bf4 ldr r7, [r0, #0xc]
 *   @0x184bf8 ble 0x18508c <_Z10_DrawArray9ePrimTypeiPviS0_+0x824>
 *   @0x184bfc ldr r6, [r5, #0x34]
 *   @0x184c00 cmp r6, #0
 *   @0x184c04 beq 0x184ea0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x638>
 *   @0x184c08 ldr r1, [r11, #0x8]
 *   @0x184c0c mov r6, #0
 *   @0x184c10 str r4, [sp, #0x14]
 *   @0x184c14 mov r4, r7
 *   @0x184c18 str r8, [sp, #0x1c]
 *   @0x184c1c str r1, [sp, #0xc]
 *   @0x184c20 ldr r3, [r5, #0x2c]
 *   @0x184c24 ldr r0, [r3, r6, lsl #2]
 *   @0x184c28 cmn r0, #1
 *   @0x184c2c beq 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464>
 *   @0x184c30 ldr lr, [r11, #0x4]
 *   @0x184c34 ldr r2, [r5, #0x34]
 *   @0x184c38 ldr r3, [r5, #0x38]
 *   @0x184c3c cmp lr, #0
 *   @0x184c40 ldr r8, [r2, r6, lsl #2]
 *   @0x184c44 ldr r9, [r3, r6, lsl #2]
 *   @0x184c48 ble 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464>
 *   @0x184c4c ldr r2, [sp, #0xc]
 *   @0x184c50 mov r12, r4
 *   @0x184c54 mov r3, #0
 *   @0x184c58 b 0x184c68 <_Z10_DrawArray9ePrimTypeiPviS0_+0x400>
 *   @0x184c5c cmp r3, lr
 *   @0x184c60 add r12, r12, #16
 *   @0x184c64 beq 0x184ccc <_Z10_DrawArray9ePrimTypeiPviS0_+0x464>
 *   @0x184c68 ldr r1, [r2, #0x8]
 *   @0x184c6c lsl r7, r3, #4
 *   @0x184c70 add r2, r2, #16
 *   @0x184c74 add r3, r3, #1
 *   @0x184c78 cmp r1, r8
 *   @0x184c7c bne 0x184c5c <_Z10_DrawArray9ePrimTypeiPviS0_+0x3f4>
 *   @0x184c80 ldr r1, [r12, #0xc]
 *   @0x184c84 cmp r1, r9
 *   @0x184c88 bne 0x184c5c <_Z10_DrawArray9ePrimTypeiPviS0_+0x3f4>
 *   @0x184c8c ldr lr, [r11, #0x14]
 *   @0x184c90 ldr r2, [sp, #0x14]
 *   @0x184c94 ldr r3, [pc, #0x4e8]
 *   @0x184c98 ldr r1, [r12, #0x4]
 *   @0x184c9c ldr r8, [r2, r3]
 *   @0x184ca0 ldr r2, [r12]
 *   @0x184ca4 ldrb r3, [r12, #0x8]
 *   @0x184ca8 str lr, [sp]
 *   @0x184cac ldr lr, [r11, #0x8]
 *   @0x184cb0 ldr r12, [r8]
 *   @0x184cb4 ldr lr, [lr, r7]
 *   @0x184cb8 ldr r7, [sp, #0x1c]
 *   @0x184cbc add lr, r7, lr
 *   @0x184cc0 str lr, [sp, #0x4]
 *   @0x184cc4 blx r12
 *   @0x184cc8 ldr r10, [r5, #0x30]
 *   @0x184ccc add r6, r6, #1
 *   @0x184cd0 cmp r10, r6
 *   @0x184cd4 bgt 0x184c20 <_Z10_DrawArray9ePrimTypeiPviS0_+0x3b8>
 *   @0x184cd8 ldr r4, [sp, #0x14]
 *   @0x184cdc ldr r3, [pc, #0x48c]
 *   @0x184ce0 mov r1, #0
 *   @0x184ce4 ldr r0, [sp, #0x18]
 *   @0x184ce8 ldr r2, [sp, #0x10]
 *   @0x184cec ldr r3, [r4, r3]
 *   @0x184cf0 ldr r3, [r3]
 *   @0x184cf4 blx r3
 *   @0x184cf8 add sp, sp, #36
 *   @0x184cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x184d00 b 0x1847f8 <_Z14EndShaderBlockv>
 *   @0x184d04 mov r7, #4
 *   @0x184d08 str r7, [sp, #0x18]
 *   @0x184d0c b 0x1848bc <_Z10_DrawArray9ePrimTypeiPviS0_+0x54>
 *   @0x184d10 cmp r9, #16
 *   @0x184d14 beq 0x184f94 <_Z10_DrawArray9ePrimTypeiPviS0_+0x72c>
 *   @0x184d18 cmp r9, #24
 *   @0x184d1c ldr r0, [r5, #0x1c]
 *   @0x184d20 beq 0x185014 <_Z10_DrawArray9ePrimTypeiPviS0_+0x7ac>
 *   @0x184d24 cmn r0, #1
 *   @0x184d28 beq 0x184d50 <_Z10_DrawArray9ePrimTypeiPviS0_+0x4e8>
 *   @0x184d2c ldr r12, [pc, #0x450]
 *   @0x184d30 mov lr, #36
 *   @0x184d34 mov r1, #3
 *   @0x184d38 movw r2, #0x1406
 *   @0x184d3c ldr r12, [r4, r12]
 *   @0x184d40 str r8, [sp, #0x4]
 *   @0x184d44 str lr, [sp]
 *   @0x184d48 ldr r12, [r12]
 *   @0x184d4c blx r12
 *   @0x184d50 ldr r0, [r5, #0x20]
 *   @0x184d54 cmn r0, #1
 *   @0x184d58 beq 0x184d84 <_Z10_DrawArray9ePrimTypeiPviS0_+0x51c>
 *   @0x184d5c ldr r3, [pc, #0x420]
 *   @0x184d60 mov r6, #36
 *   @0x184d64 add lr, r8, #12
 *   @0x184d68 mov r1, #3
 *   @0x184d6c movw r2, #0x1406
 *   @0x184d70 ldr r12, [r4, r3]
 *   @0x184d74 mov r3, #0
 *   @0x184d78 stm sp, {r6, lr}
 *   @0x184d7c ldr r12, [r12]
 *   @0x184d80 blx r12
 *   @0x184d84 ldr r0, [r5, #0x28]
 *   @0x184d88 cmn r0, #1
 *   @0x184d8c beq 0x184db8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x550>
 *   @0x184d90 ldr r3, [pc, #0x3ec]
 *   @0x184d94 mov r6, #36
 *   @0x184d98 add lr, r8, #24
 *   @0x184d9c mov r1, #4
 *   @0x184da0 movw r2, #0x1401
 *   @0x184da4 ldr r12, [r4, r3]
 *   @0x184da8 mov r3, #1
 *   @0x184dac stm sp, {r6, lr}
 *   @0x184db0 ldr r12, [r12]
 *   @0x184db4 blx r12
 *   @0x184db8 ldr r0, [r5, #0x24]
 *   @0x184dbc cmn r0, #1
 *   @0x184dc0 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184dc4 ldr r3, [pc, #0x3b8]
 *   @0x184dc8 add r8, r8, #28
 *   @0x184dcc mov lr, #36
 *   @0x184dd0 ldr r12, [r4, r3]
 *   @0x184dd4 mov r1, #2
 *   @0x184dd8 str r8, [sp, #0x4]
 *   @0x184ddc movw r2, #0x1406
 *   @0x184de0 str lr, [sp]
 *   @0x184de4 mov r3, #0
 *   @0x184de8 ldr r12, [r12]
 *   @0x184dec blx r12
 *   @0x184df0 b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184df4 ldr r5, [r4, r3]
 *   @0x184df8 movw r0, #0x8076
 *   @0x184dfc ldr r3, [r5]
 *   @0x184e00 blx r3
 *   @0x184e04 ldr r12, [pc, #0x368]
 *   @0x184e08 movw r1, #0x1401
 *   @0x184e0c mov r2, r9
 *   @0x184e10 mov r0, #4
 *   @0x184e14 add r3, r8, #12
 *   @0x184e18 ldr r12, [r4, r12]
 *   @0x184e1c ldr r12, [r12]
 *   @0x184e20 blx r12
 *   @0x184e24 ldr r3, [r5]
 *   @0x184e28 movw r0, #0x8074
 *   @0x184e2c blx r3
 *   @0x184e30 ldr r12, [pc, #0x344]
 *   @0x184e34 mov r0, r6
 *   @0x184e38 movw r1, #0x1406
 *   @0x184e3c mov r2, r9
 *   @0x184e40 mov r3, r8
 *   @0x184e44 ldr r12, [r4, r12]
 *   @0x184e48 ldr r12, [r12]
 *   @0x184e4c blx r12
 *   @0x184e50 ldr r7, [sp, #0x14]
 *   @0x184e54 cmp r7, #0
 *   @0x184e58 beq 0x185138 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8d0>
 *   @0x184e5c ldr r3, [r5]
 *   @0x184e60 movw r0, #0x8078
 *   @0x184e64 blx r3
 *   @0x184e68 ldr r12, [pc, #0x2fc]
 *   @0x184e6c add r3, r8, #16
 *   @0x184e70 mov r0, #2
 *   @0x184e74 movw r1, #0x1406
 *   @0x184e78 mov r2, r9
 *   @0x184e7c ldr r12, [r4, r12]
 *   @0x184e80 ldr r12, [r12]
 *   @0x184e84 blx r12
 *   @0x184e88 ldr r3, [pc, #0x2d4]
 *   @0x184e8c ldr r5, [r4, r3]
 *   @0x184e90 ldr r3, [r5]
 *   @0x184e94 movw r0, #0x8075
 *   @0x184e98 blx r3
 *   @0x184e9c b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188>
 *   @0x184ea0 ldr r3, [r11, #0x4]
 *   @0x184ea4 cmp r3, r10
 *   @0x184ea8 movlt r9, r3
 *   @0x184eac movge r9, r10
 *   @0x184eb0 cmp r9, #0
 *   @0x184eb4 ble 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184eb8 ldr r3, [r5, #0x2c]
 *   @0x184ebc ldr r2, [pc, #0x2c0]
 *   @0x184ec0 ldr r12, [r11, #0x8]
 *   @0x184ec4 ldr r0, [r3, r6, lsl #2]
 *   @0x184ec8 cmn r0, #1
 *   @0x184ecc beq 0x184efc <_Z10_DrawArray9ePrimTypeiPviS0_+0x694>
 *   @0x184ed0 ldr lr, [r11, #0x14]
 *   @0x184ed4 ldr r10, [r4, r2]
 *   @0x184ed8 ldr r1, [r7, #0x4]
 *   @0x184edc ldr r2, [r7]
 *   @0x184ee0 ldrb r3, [r7, #0x8]
 *   @0x184ee4 str lr, [sp]
 *   @0x184ee8 ldr lr, [r12, r6, lsl #4]
 *   @0x184eec ldr r12, [r10]
 *   @0x184ef0 add lr, r8, lr
 *   @0x184ef4 str lr, [sp, #0x4]
 *   @0x184ef8 blx r12
 *   @0x184efc add r6, r6, #1
 *   @0x184f00 add r7, r7, #16
 *   @0x184f04 cmp r6, r9
 *   @0x184f08 bne 0x184eb8 <_Z10_DrawArray9ePrimTypeiPviS0_+0x650>
 *   @0x184f0c b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184f10 ldr r3, [pc, #0x250]
 *   @0x184f14 movw r0, #0x8074
 *   @0x184f18 ldr r5, [r4, r3]
 *   @0x184f1c ldr r3, [r5]
 *   @0x184f20 blx r3
 *   @0x184f24 ldr r12, [pc, #0x250]
 *   @0x184f28 movw r1, #0x1406
 *   @0x184f2c mov r2, r9
 *   @0x184f30 mov r0, r6
 *   @0x184f34 mov r3, r8
 *   @0x184f38 ldr r12, [r4, r12]
 *   @0x184f3c ldr r12, [r12]
 *   @0x184f40 blx r12
 *   @0x184f44 ldr r3, [r5]
 *   @0x184f48 movw r0, #0x8076
 *   @0x184f4c blx r3
 *   @0x184f50 ldr r12, [pc, #0x21c]
 *   @0x184f54 mov r0, #4
 *   @0x184f58 add r3, r8, #12
 *   @0x184f5c movw r1, #0x1401
 *   @0x184f60 mov r2, r9
 *   @0x184f64 ldr r12, [r4, r12]
 *   @0x184f68 ldr r12, [r12]
 *   @0x184f6c blx r12
 *   @0x184f70 ldr r7, [sp, #0x14]
 *   @0x184f74 ldr r3, [pc, #0x1e8]
 *   @0x184f78 movw r0, #0x8078
 *   @0x184f7c cmp r7, #0
 *   @0x184f80 beq 0x185144 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8dc>
 *   @0x184f84 ldr r5, [r4, r3]
 *   @0x184f88 ldr r3, [r5]
 *   @0x184f8c blx r3
 *   @0x184f90 b 0x184e90 <_Z10_DrawArray9ePrimTypeiPviS0_+0x628>
 *   @0x184f94 ldr r0, [r5, #0x1c]
 *   @0x184f98 cmn r0, #1
 *   @0x184f9c beq 0x184fc0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x758>
 *   @0x184fa0 ldr r12, [pc, #0x1dc]
 *   @0x184fa4 mov r1, #3
 *   @0x184fa8 movw r2, #0x1406
 *   @0x184fac ldr r12, [r4, r12]
 *   @0x184fb0 str r9, [sp]
 *   @0x184fb4 str r8, [sp, #0x4]
 *   @0x184fb8 ldr r12, [r12]
 *   @0x184fbc blx r12
 *   @0x184fc0 ldr r0, [r5, #0x28]
 *   @0x184fc4 cmn r0, #1
 *   @0x184fc8 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184fcc ldr r3, [pc, #0x1b0]
 *   @0x184fd0 add r8, r8, #12
 *   @0x184fd4 mov lr, #16
 *   @0x184fd8 mov r1, #4
 *   @0x184fdc movw r2, #0x1401
 *   @0x184fe0 ldr r12, [r4, r3]
 *   @0x184fe4 mov r3, #1
 *   @0x184fe8 str r8, [sp, #0x4]
 *   @0x184fec str lr, [sp]
 *   @0x184ff0 ldr r12, [r12]
 *   @0x184ff4 blx r12
 *   @0x184ff8 b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x184ffc ldr r3, [pc, #0x160]
 *   @0x185000 movw r0, #0x8078
 *   @0x185004 ldr r3, [r4, r3]
 *   @0x185008 ldr r3, [r3]
 *   @0x18500c blx r3
 *   @0x185010 b 0x184b9c <_Z10_DrawArray9ePrimTypeiPviS0_+0x334>
 *   @0x185014 cmn r0, #1
 *   @0x185018 beq 0x18503c <_Z10_DrawArray9ePrimTypeiPviS0_+0x7d4>
 *   @0x18501c ldr r12, [pc, #0x160]
 *   @0x185020 mov r1, #3
 *   @0x185024 movw r2, #0x1406
 *   @0x185028 ldr r12, [r4, r12]
 *   @0x18502c str r9, [sp]
 *   @0x185030 str r8, [sp, #0x4]
 *   @0x185034 ldr r12, [r12]
 *   @0x185038 blx r12
 *   @0x18503c ldr r0, [r5, #0x28]
 *   @0x185040 cmn r0, #1
 *   @0x185044 beq 0x185070 <_Z10_DrawArray9ePrimTypeiPviS0_+0x808>
 *   @0x185048 ldr r3, [pc, #0x134]
 *   @0x18504c mov r6, #24
 *   @0x185050 add lr, r8, #12
 *   @0x185054 mov r1, #4
 *   @0x185058 movw r2, #0x1401
 *   @0x18505c ldr r12, [r4, r3]
 *   @0x185060 mov r3, #1
 *   @0x185064 stm sp, {r6, lr}
 *   @0x185068 ldr r12, [r12]
 *   @0x18506c blx r12
 *   @0x185070 ldr r0, [r5, #0x24]
 *   @0x185074 cmn r0, #1
 *   @0x185078 beq 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x18507c ldr r3, [pc, #0x100]
 *   @0x185080 add r8, r8, #16
 *   @0x185084 mov lr, #24
 *   @0x185088 b 0x184dd0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x568>
 *   @0x18508c ldr r2, [r0, #0x4]
 *   @0x185090 cmp r2, #0
 *   @0x185094 ble 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x185098 mov r6, #0
 *   @0x18509c ldr lr, [r11, #0x8]
 *   @0x1850a0 lsl r12, r6, #4
 *   @0x1850a4 add r3, lr, r12
 *   @0x1850a8 ldr r3, [r3, #0x8]
 *   @0x1850ac sub r3, r3, #1
 *   @0x1850b0 cmp r3, #3
 *   @0x1850b4 addls pc, pc, r3, lsl #2
 *   @0x1850b8 b 0x18510c <_Z10_DrawArray9ePrimTypeiPviS0_+0x8a4>
 *   @0x1850bc b 0x185120 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8b8>
 *   @0x1850c0 b 0x185130 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8c8>
 *   @0x1850c4 b 0x185128 <_Z10_DrawArray9ePrimTypeiPviS0_+0x8c0>
 *   @0x1850c8 b 0x1850cc <_Z10_DrawArray9ePrimTypeiPviS0_+0x864>
 *   @0x1850cc ldr r0, [r5, #0x24]
 *   @0x1850d0 cmn r0, #1
 *   @0x1850d4 ldr r3, [pc, #0xa8]
 *   @0x1850d8 beq 0x18510c <_Z10_DrawArray9ePrimTypeiPviS0_+0x8a4>
 *   @0x1850dc ldr r10, [r11, #0x14]
 *   @0x1850e0 ldr r9, [r4, r3]
 *   @0x1850e4 ldr r2, [r7]
 *   @0x1850e8 ldr r1, [r7, #0x4]
 *   @0x1850ec ldrb r3, [r7, #0x8]
 *   @0x1850f0 str r10, [sp]
 *   @0x1850f4 ldr lr, [lr, r12]
 *   @0x1850f8 ldr r12, [r9]
 *   @0x1850fc add lr, r8, lr
 *   @0x185100 str lr, [sp, #0x4]
 *   @0x185104 blx r12
 *   @0x185108 ldr r2, [r11, #0x4]
 *   @0x18510c add r6, r6, #1
 *   @0x185110 add r7, r7, #16
 *   @0x185114 cmp r2, r6
 *   @0x185118 bgt 0x18509c <_Z10_DrawArray9ePrimTypeiPviS0_+0x834>
 *   @0x18511c b 0x184cdc <_Z10_DrawArray9ePrimTypeiPviS0_+0x474>
 *   @0x185120 ldr r0, [r5, #0x1c]
 *   @0x185124 b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868>
 *   @0x185128 ldr r0, [r5, #0x20]
 *   @0x18512c b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868>
 *   @0x185130 ldr r0, [r5, #0x28]
 *   @0x185134 b 0x1850d0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x868>
 *   @0x185138 ldr r3, [pc, #0x24]
 *   @0x18513c movw r0, #0x8078
 *   @0x185140 b 0x184f84 <_Z10_DrawArray9ePrimTypeiPviS0_+0x71c>
 *   @0x185144 ldr r3, [r4, r3]
 *   @0x185148 ldr r3, [r3]
 *   @0x18514c blx r3
 *   @0x185150 b 0x1849f0 <_Z10_DrawArray9ePrimTypeiPviS0_+0x188>
 *   @0x185154 .word 0x0026d3d0
 *   @0x185158 .word 0xffffc0b4
 *   @0x18515c .word 0xffffbcd4
 *   @0x185160 .word 0xffffe7b8
 *   @0x185164 .word 0xffffbc2c
 *   @0x185168 .word 0xffffbc30
 *   @0x18516c .word 0xffffbca8
 *   @0x185170 .word 0xffffbad4
 *   @0x185174 .word 0xffffbc28
 *   @0x185178 .word 0xffffbc50
 *   @0x18517c .word 0xffffbc6c
 *   @0x185180 .word 0xffffe944
 *   @0x185184 .word 0xffffbb90
 *
 * ══ §5/56 Graphics::SetRenderState  0x17fd24  size 1924  477 条（0x17fd24..0x1804a8）｜其中 4 条已由别的卡落锚，本节不再重复
 * @func 0x17fd24 0x1804a8  size 1924  477 条
 * 部分覆盖: 本节 477/481 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17fdd4→0x479c80, 0x17fde8→0x3f288c, 0x17fdf0→0x479bc4, 0x17fe18→0x3f2790, 0x17fe1c→0x3f26dc, 0x17fe38→0x479bcc, 0x17fe50→0x4a2394, 0x17fe54→0x3f26dc
 * 调用序列: ConvertStencilOp(eStencilOp)×7 / ConvertComparison(eCmpFunc)×5 / ConvertBlend(eBlend, int*)×2 / ConvertFogMode(eFog) / ConvertCull(eCull) / Graphics::SetRenderState(eRenderState, unsigned int)+0x76c / 0xfe1a0434
 * 字段偏移 top8: 0x13c×3 / 0x-134×3 / 0x-180×3 / 0x41c×2 / 0x310×2 / 0x338×2 / 0x26c×2 / 0x20c×2
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17fd24 push {r3, r4, r5, r6, r7, lr}
 *   @0x17fd2c ldr r4, [pc, #0x4fc]
 *   @0x17fd30 mov r5, r1
 *   @0x17fd34 add r4, pc, r4
 *   @0x17fd38 cmp r0, #31
 *   @0x17fd40 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd44 b 0x1802c4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x5a0>
 *   @0x17fd48 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd4c b 0x1801f4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x4d0>
 *   @0x17fd50 b 0x1801d4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x4b0>
 *   @0x17fd54 b 0x1801a4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x480>
 *   @0x17fd58 b 0x180168 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x444>
 *   @0x17fd5c b 0x180128 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x404>
 *   @0x17fd60 b 0x1800e0 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x3bc>
 *   @0x17fd64 b 0x1800c4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x3a0>
 *   @0x17fd68 b 0x180078 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x354>
 *   @0x17fd6c b 0x18002c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x308>
 *   @0x17fd70 b 0x180024 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x300>
 *   @0x17fd74 b 0x17ffc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x2a0>
 *   @0x17fd78 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd7c b 0x17fec0 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x19c>
 *   @0x17fd80 b 0x17fe88 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x164>
 *   @0x17fd84 b 0x17fe50 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x12c>
 *   @0x17fd88 b 0x17fe18 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xf4>
 *   @0x17fd8c b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd90 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd94 b 0x17ff3c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x218>
 *   @0x17fd98 b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fd9c b 0x17fdc4 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa0>
 *   @0x17fda0 b 0x17fde8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xc4>
 *   @0x17fda4 b 0x17fdc8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa4>
 *   @0x17fda8 b 0x180394 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x670>
 *   @0x17fdac b 0x180338 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x614>
 *   @0x17fdb0 b 0x1803c8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x6a4>
 *   @0x17fdb4 b 0x1802f8 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x5d4>
 *   @0x17fdb8 b 0x180424 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x700>
 *   @0x17fdbc b 0x17ff6c <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x248>
 *   @0x17fdc0 b 0x17ffac <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x288>
 *   @0x17fdc4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fdcc cmp r5, #0
 *   @0x17fdd0 bne 0x180464 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x740>
 *   @0x17fdd4 ldr r3, [pc, #0x4e4]
 *   @0x17fdd8 ldr r3, [r4, r3]
 *   @0x17fddc ldr r3, [r3]
 *   @0x17fde0 blx r3
 *   @0x17fde4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fde8 ldr lr, [pc, #0x444]
 *   @0x17fdec and r0, r1, #1
 *   @0x17fdf0 ldr r12, [pc, #0x440]
 *   @0x17fdf4 ubfx r1, r1, #0x1, #0x1
 *   @0x17fdf8 ubfx r2, r5, #0x2, #0x1
 *   @0x17fdfc ubfx r3, r5, #0x3, #0x1
 *   @0x17fe00 ldr lr, [r4, lr]
 *   @0x17fe04 str r5, [lr]
 *   @0x17fe08 ldr r12, [r4, r12]
 *   @0x17fe0c ldr r12, [r12]
 *   @0x17fe10 blx r12
 *   @0x17fe14 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fe18 ldr r2, [pc, #0x41c]
 *   @0x17fe1c ldr r3, [pc, #0x41c]
 *   @0x17fe20 ldr r2, [r4, r2]
 *   @0x17fe24 str r1, [r2]
 *   @0x17fe28 ldr r3, [r4, r3]
 *   @0x17fe2c ldr r3, [r3]
 *   @0x17fe30 cmp r3, #0
 *   @0x17fe34 popne {r3, r4, r5, r6, r7, pc}
 *   @0x17fe38 ldr r3, [pc, #0x404]
 *   @0x17fe3c movw r0, #0xb64
 *   @0x17fe40 ldr r3, [r4, r3]
 *   @0x17fe44 ldr r3, [r3]
 *   @0x17fe48 blx r3
 *   @0x17fe4c pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fe50 ldr r2, [pc, #0x3f0]
 *   @0x17fe54 ldr r3, [pc, #0x3e4]
 *   @0x17fe58 ldr r2, [r4, r2]
 *   @0x17fe5c str r1, [r2]
 *   @0x17fe60 ldr r3, [r4, r3]
 *   @0x17fe64 ldr r3, [r3]
 *   @0x17fe68 cmp r3, #0
 *   @0x17fe6c popne {r3, r4, r5, r6, r7, pc}
 *   @0x17fe70 ldr r3, [pc, #0x3cc]
 *   @0x17fe74 movw r0, #0xb63
 *   @0x17fe78 ldr r3, [r4, r3]
 *   @0x17fe7c ldr r3, [r3]
 *   @0x17fe80 blx r3
 *   @0x17fe84 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fe88 ldr r3, [pc, #0x3b0]
 *   @0x17fe8c ldr r3, [r4, r3]
 *   @0x17fe90 ldr r3, [r3]
 *   @0x17fe94 cmp r3, #0
 *   @0x17fe98 popne {r3, r4, r5, r6, r7, pc}
 *   @0x17fe9c ldr r3, [pc, #0x3a0]
 *   @0x17fea0 mov r0, r1
 *   @0x17fea4 ldr r3, [r4, r3]
 *   @0x17fea8 ldr r4, [r3]
 *   @0x17feac bl 0x17fcc8 <_Z14ConvertFogMode4eFog>
 *   @0x17feb0 mov r1, r0
 *   @0x17feb4 movw r0, #0xb65
 *   @0x17feb8 blx r4
 *   @0x17febc pop {r3, r4, r5, r6, r7, pc}
 *   @0x17fec0 uxtb r3, r1
 *   @0x17fec4 ubfx r5, r1, #0x10, #0x8
 *   @0x17fec8 vldr s15, [pc, #856]
 *   @0x17fecc ldr r2, [pc, #0x378]
 *   @0x17fed0 vmov s12, r3
 *   @0x17fed4 ubfx r3, r1, #0x8, #0x8
 *   @0x17fed8 vmov s11, r5
 *   @0x17fedc vmov s14, r3
 *   @0x17fee0 ldr r1, [r4, r2]
 *   @0x17fee4 vcvt.f32.s32 s12, s12
 *   @0x17fee8 ldr r3, [pc, #0x350]
 *   @0x17feec mov r2, #1065353216
 *   @0x17fef0 str r2, [r1, #0xc]
 *   @0x17fef4 vcvt.f32.s32 s14, s14
 *   @0x17fef8 vcvt.f32.s32 s13, s11
 *   @0x17fefc vmul.f32 s12, s12, s15
 *   @0x17ff00 vmul.f32 s14, s14, s15
 *   @0x17ff04 vstr s12, [r1]
 *   @0x17ff08 vmul.f32 s15, s13, s15
 *   @0x17ff0c vstr s14, [r1, #4]
 *   @0x17ff10 vstr s15, [r1, #8]
 *   @0x17ff14 ldr r3, [r4, r3]
 *   @0x17ff18 ldr r3, [r3]
 *   @0x17ff1c cmp r3, #0
 *   @0x17ff20 popne {r3, r4, r5, r6, r7, pc}
 *   @0x17ff24 ldr r3, [pc, #0x324]
 *   @0x17ff28 movw r0, #0xb66
 *   @0x17ff2c ldr r3, [r4, r3]
 *   @0x17ff30 ldr r3, [r3]
 *   @0x17ff34 blx r3
 *   @0x17ff38 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17ff3c ldr r2, [pc, #0x310]
 *   @0x17ff40 adds r1, r1, #0
 *   @0x17ff44 ldr r3, [pc, #0x2f4]
 *   @0x17ff48 movne r1, #1
 *   @0x17ff4c ldr r2, [r4, r2]
 *   @0x17ff50 strb r1, [r2]
 *   @0x17ff54 ldr r3, [r4, r3]
 *   @0x17ff58 ldr r3, [r3]
 *   @0x17ff5c cmp r3, #0
 *   @0x17ff60 popne {r3, r4, r5, r6, r7, pc}
 *   @0x17ff64 mov r0, #2896
 *   @0x17ff68 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8>
 *   @0x17ff6c ldr r1, [pc, #0x344]
 *   @0x17ff70 ldr r2, [pc, #0x338]
 *   @0x17ff74 ldr r3, [pc, #0x338]
 *   @0x17ff78 ldr r6, [r4, r1]
 *   @0x17ff7c str r5, [r6]
 *   @0x17ff80 ldr r2, [r4, r2]
 *   @0x17ff84 ldr r3, [r4, r3]
 *   @0x17ff88 ldr r0, [r2]
 *   @0x17ff8c ldr r5, [r3]
 *   @0x17ff90 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc>
 *   @0x17ff94 ldr r3, [pc, #0x310]
 *   @0x17ff98 ldr r2, [r6]
 *   @0x17ff9c ldr r3, [r4, r3]
 *   @0x17ffa0 ldr r1, [r3]
 *   @0x17ffa4 blx r5
 *   @0x17ffa8 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17ffac ldr r3, [pc, #0x2a4]
 *   @0x17ffb0 mov r0, r1
 *   @0x17ffb4 ldr r3, [r4, r3]
 *   @0x17ffb8 ldr r3, [r3]
 *   @0x17ffbc blx r3
 *   @0x17ffc0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x17ffc4 ldr r2, [pc, #0x290]
 *   @0x17ffc8 adds r1, r1, #0
 *   @0x17ffcc ldr r3, [pc, #0x26c]
 *   @0x17ffd0 movne r1, #1
 *   @0x17ffd4 ldr r2, [r4, r2]
 *   @0x17ffd8 strb r1, [r2]
 *   @0x17ffdc ldr r3, [r4, r3]
 *   @0x17ffe0 ldr r3, [r3]
 *   @0x17ffe4 cmp r3, #0
 *   @0x17ffe8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x17ffec ldr r3, [pc, #0x26c]
 *   @0x17fff0 movw r0, #0xc54
 *   @0x17fff4 mov r1, #4352
 *   @0x17fff8 ldr r3, [r4, r3]
 *   @0x17fffc ldr r3, [r3]
 *   @0x180000 blx r3
 *   @0x180004 ldr r3, [pc, #0x238]
 *   @0x180008 movw r0, #0xb62
 *   @0x18000c mov r1, #1065353216
 *   @0x180010 ldr r3, [r4, r3]
 *   @0x180014 ldr r3, [r3]
 *   @0x180018 blx r3
 *   @0x18001c mov r0, #2912
 *   @0x180020 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8>
 *   @0x180028 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8>
 *   @0x18002c ldr r3, [pc, #0x20c]
 *   @0x180030 ldr r3, [r4, r3]
 *   @0x180034 ldr r3, [r3]
 *   @0x180038 cmp r3, #0
 *   @0x18003c popne {r3, r4, r5, r6, r7, pc}
 *   @0x180040 ldr r3, [pc, #0x21c]
 *   @0x180044 mov r0, r1
 *   @0x180048 ldr r3, [r4, r3]
 *   @0x18004c ldr r5, [r3]
 *   @0x180050 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc>
 *   @0x180054 ldr r3, [pc, #0x20c]
 *   @0x180058 vldr s15, [pc, #460]
 *   @0x18005c ldr r3, [r4, r3]
 *   @0x180060 vldr s14, [r3]
 *   @0x180064 vcvt.f32.s32 s14, s14
 *   @0x180068 vdiv.f32 s15, s14, s15
 *   @0x18006c vmov r1, s15
 *   @0x180070 blx r5
 *   @0x180074 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180078 ldr r2, [pc, #0x1e8]
 *   @0x18007c ldr r3, [pc, #0x1bc]
 *   @0x180080 ldr r2, [r4, r2]
 *   @0x180084 str r1, [r2]
 *   @0x180088 ldr r3, [r4, r3]
 *   @0x18008c ldr r3, [r3]
 *   @0x180090 cmp r3, #0
 *   @0x180094 popne {r3, r4, r5, r6, r7, pc}
 *   @0x180098 vmov s11, r1
 *   @0x18009c vldr s15, [pc, #392]
 *   @0x1800a0 ldr r3, [pc, #0x1bc]
 *   @0x1800a4 mov r0, #516
 *   @0x1800a8 vcvt.f32.u32 s14, s11
 *   @0x1800ac ldr r3, [r4, r3]
 *   @0x1800b0 ldr r3, [r3]
 *   @0x1800b4 vdiv.f32 s15, s14, s15
 *   @0x1800b8 vmov r1, s15
 *   @0x1800bc blx r3
 *   @0x1800c0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1800c4 ldr r3, [pc, #0x1a0]
 *   @0x1800c8 mov r0, r1
 *   @0x1800cc ldr r3, [r4, r3]
 *   @0x1800d0 ldr r4, [r3]
 *   @0x1800d4 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc>
 *   @0x1800d8 blx r4
 *   @0x1800dc pop {r3, r4, r5, r6, r7, pc}
 *   @0x1800e0 ldr r3, [pc, #0x188]
 *   @0x1800e4 mov r0, r1
 *   @0x1800e8 ldr r3, [r4, r3]
 *   @0x1800ec str r1, [r3]
 *   @0x1800f0 bl 0x17fc68 <_Z11ConvertCull5eCull>
 *   @0x1800f4 subs r5, r0, #0
 *   @0x1800f8 blt 0x180490 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x76c>
 *   @0x1800fc ldr r3, [pc, #0x1b8]
 *   @0x180100 movw r0, #0xb44
 *   @0x180104 ldr r3, [r4, r3]
 *   @0x180108 ldr r3, [r3]
 *   @0x18010c blx r3
 *   @0x180110 ldr r3, [pc, #0x15c]
 *   @0x180114 mov r0, r5
 *   @0x180118 ldr r3, [r4, r3]
 *   @0x18011c ldr r3, [r3]
 *   @0x180120 blx r3
 *   @0x180124 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180128 ldr r3, [pc, #0x148]
 *   @0x18012c mov r0, r1
 *   @0x180130 ldr r1, [r4, r3]
 *   @0x180134 bl 0x17fc0c <_Z12ConvertBlend6eBlendPi>
 *   @0x180138 ldr r12, [pc, #0x13c]
 *   @0x18013c ldr r3, [pc, #0x13c]
 *   @0x180140 ldr r2, [pc, #0x13c]
 *   @0x180144 ldr r12, [r4, r12]
 *   @0x180148 str r0, [r12]
 *   @0x18014c mov r1, r0
 *   @0x180150 ldr r3, [r4, r3]
 *   @0x180154 ldr r2, [r4, r2]
 *   @0x180158 ldr r3, [r3]
 *   @0x18015c ldr r0, [r2]
 *   @0x180160 blx r3
 *   @0x180164 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180168 ldr r3, [pc, #0x118]
 *   @0x18016c mov r0, r1
 *   @0x180170 ldr r1, [r4, r3]
 *   @0x180174 bl 0x17fc0c <_Z12ConvertBlend6eBlendPi>
 *   @0x180178 ldr r1, [pc, #0x104]
 *   @0x18017c ldr r3, [pc, #0xfc]
 *   @0x180180 ldr r2, [pc, #0xf4]
 *   @0x180184 ldr r1, [r4, r1]
 *   @0x180188 str r0, [r1]
 *   @0x18018c ldr r3, [r4, r3]
 *   @0x180190 ldr r2, [r4, r2]
 *   @0x180194 ldr r3, [r3]
 *   @0x180198 ldr r1, [r2]
 *   @0x18019c blx r3
 *   @0x1801a0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1801a4 ldr r2, [pc, #0xe0]
 *   @0x1801a8 adds r1, r1, #0
 *   @0x1801ac ldr r3, [pc, #0x8c]
 *   @0x1801b0 movne r1, #1
 *   @0x1801b4 ldr r2, [r4, r2]
 *   @0x1801b8 strb r1, [r2]
 *   @0x1801bc ldr r3, [r4, r3]
 *   @0x1801c0 ldr r3, [r3]
 *   @0x1801c4 cmp r3, #0
 *   @0x1801c8 popne {r3, r4, r5, r6, r7, pc}
 *   @0x1801cc mov r0, #3008
 *   @0x1801d0 b 0x17fdcc <_ZN8Graphics14SetRenderStateE12eRenderStatej+0xa8>
 *   @0x1801d4 ldr r3, [pc, #0xb4]
 *   @0x1801d8 cmp r1, #0
 *   @0x1801dc movne r0, #1
 *   @0x1801e0 moveq r0, r1
 *   @0x1801e4 ldr r3, [r4, r3]
 *   @0x1801e8 ldr r3, [r3]
 *   @0x1801ec blx r3
 *   @0x1801f0 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1801f4 ldr r3, [pc, #0x44]
 *   @0x1801f8 ldr r3, [r4, r3]
 *   @0x1801fc ldr r3, [r3]
 *   @0x180200 cmp r3, #0
 *   @0x180204 popne {r3, r4, r5, r6, r7, pc}
 *   @0x180208 ldr r3, [pc, #0x84]
 *   @0x18020c cmp r1, #1
 *   @0x180210 moveq r0, #7424
 *   @0x180214 movwne r0, #0x1d01
 *   @0x180218 ldr r3, [r4, r3]
 *   @0x18021c ldr r3, [r3]
 *   @0x180220 blx r3
 *   @0x180224 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180228 bllo 0xfe1a0434 <b2_toiTime+0xfffffffffda46f90>
 *   @0x18022c cmnmi pc, #0
 *   @0x180230 eoreq r1, r7, r12, lsl pc
 *   @0x180234 .word 0xffffe870
 *   @0x180238 .word 0xffffbb18
 *   @0x18023c .word 0xffffe874
 *   @0x180240 .word 0xffffe7b8
 *   @0x180244 .word 0xffffbc98
 *   @0x180248 .word 0xffffe878
 *   @0x18024c .word 0xffffe87c
 *   @0x180250 .word 0xffffbc9c
 *   @0x180254 .word 0xffffe880
 *   @0x180258 .word 0xffffbb58
 *   @0x18025c .word 0xffffe884
 *   @0x180260 .word 0xffffbb14
 *   @0x180264 .word 0xffffbc1c
 *   @0x180268 .word 0xffffe888
 *   @0x18026c .word 0xffffbaec
 *   @0x180270 .word 0xffffe82c
 *   @0x180274 .word 0xffffbb10
 *   @0x180278 .word 0xffffe88c
 *   @0x18027c .word 0xffffe890
 *   @0x180280 .word 0xffffbac8
 *   @0x180284 .word 0xffffe894
 *   @0x180288 .word 0xffffe898
 *   @0x18028c .word 0xffffe89c
 *   @0x180290 .word 0xffffbb0c
 *   @0x180294 .word 0xffffbc64
 *   @0x180298 .word 0xffffe8a0
 *   @0x18029c .word 0xffffe8a4
 *   @0x1802a0 .word 0xffffe8a8
 *   @0x1802a4 .word 0xffffbb5c
 *   @0x1802a8 .word 0xffffe8ac
 *   @0x1802ac .word 0xffffe8b0
 *   @0x1802b0 .word 0xffffe8b4
 *   @0x1802b4 .word 0xffffbb54
 *   @0x1802b8 .word 0xffffe8b8
 *   @0x1802bc .word 0xffffbad8
 *   @0x1802c0 .word 0xffffbad0
 *   @0x1802c4 ldr r3, [pc, #-0x34]
 *   @0x1802c8 adds r5, r1, #0
 *   @0x1802cc movne r5, #1
 *   @0x1802d0 cmp r5, #0
 *   @0x1802d4 ldr r3, [r4, r3]
 *   @0x1802d8 strb r5, [r3]
 *   @0x1802dc beq 0x180478 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x754>
 *   @0x1802e0 ldr r3, [pc, #-0x2c]
 *   @0x1802e4 movw r0, #0xb71
 *   @0x1802e8 ldr r3, [r4, r3]
 *   @0x1802ec ldr r3, [r3]
 *   @0x1802f0 blx r3
 *   @0x1802f4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x1802f8 ldr r2, [pc, #-0x50]
 *   @0x1802fc mov r0, r1
 *   @0x180300 ldr r3, [pc, #-0x54]
 *   @0x180304 ldr r2, [r4, r2]
 *   @0x180308 str r1, [r2]
 *   @0x18030c ldr r3, [r4, r3]
 *   @0x180310 ldr r5, [r3]
 *   @0x180314 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc>
 *   @0x180318 ldr r2, [pc, #-0x74]
 *   @0x18031c ldr r3, [pc, #-0x6c]
 *   @0x180320 ldr r2, [r4, r2]
 *   @0x180324 ldr r3, [r4, r3]
 *   @0x180328 ldr r1, [r2]
 *   @0x18032c ldr r2, [r3]
 *   @0x180330 blx r5
 *   @0x180334 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180338 ldr r1, [pc, #-0x98]
 *   @0x18033c ldr r2, [pc, #-0xa4]
 *   @0x180340 ldr r3, [pc, #-0xa4]
 *   @0x180344 ldr r6, [r4, r1]
 *   @0x180348 str r5, [r6]
 *   @0x18034c ldr r2, [r4, r2]
 *   @0x180350 ldr r3, [r4, r3]
 *   @0x180354 ldr r0, [r2]
 *   @0x180358 ldr r5, [r3]
 *   @0x18035c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x180360 mov r7, r0
 *   @0x180364 ldr r0, [r6]
 *   @0x180368 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x18036c ldr r3, [pc, #-0xd8]
 *   @0x180370 ldr r3, [r4, r3]
 *   @0x180374 mov r6, r0
 *   @0x180378 ldr r0, [r3]
 *   @0x18037c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x180380 mov r1, r6
 *   @0x180384 mov r2, r0
 *   @0x180388 mov r0, r7
 *   @0x18038c blx r5
 *   @0x180390 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180394 ldr r2, [pc, #-0xfc]
 *   @0x180398 mov r0, r1
 *   @0x18039c ldr r3, [pc, #-0x100]
 *   @0x1803a0 ldr r2, [r4, r2]
 *   @0x1803a4 str r1, [r2]
 *   @0x1803a8 ldr r3, [r4, r3]
 *   @0x1803ac ldr r5, [r3]
 *   @0x1803b0 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x1803b4 ldr r3, [pc, #-0x114]
 *   @0x1803b8 ldr r3, [r4, r3]
 *   @0x1803bc mov r7, r0
 *   @0x1803c0 ldr r0, [r3]
 *   @0x1803c4 b 0x180368 <_ZN8Graphics14SetRenderStateE12eRenderStatej+0x644>
 *   @0x1803c8 ldr r1, [pc, #-0x134]
 *   @0x1803cc ldr r2, [pc, #-0x134]
 *   @0x1803d0 ldr r3, [pc, #-0x134]
 *   @0x1803d4 ldr r6, [r4, r1]
 *   @0x1803d8 str r5, [r6]
 *   @0x1803dc ldr r2, [r4, r2]
 *   @0x1803e0 ldr r3, [r4, r3]
 *   @0x1803e4 ldr r0, [r2]
 *   @0x1803e8 ldr r5, [r3]
 *   @0x1803ec bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x1803f0 ldr r3, [pc, #-0x150]
 *   @0x1803f4 ldr r3, [r4, r3]
 *   @0x1803f8 mov r7, r0
 *   @0x1803fc ldr r0, [r3]
 *   @0x180400 bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x180404 mov r4, r0
 *   @0x180408 ldr r0, [r6]
 *   @0x18040c bl 0x17fcf8 <_Z16ConvertStencilOp10eStencilOp>
 *   @0x180410 mov r1, r4
 *   @0x180414 mov r2, r0
 *   @0x180418 mov r0, r7
 *   @0x18041c blx r5
 *   @0x180420 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180424 ldr r1, [pc, #-0x180]
 *   @0x180428 ldr r2, [pc, #-0x180]
 *   @0x18042c ldr r3, [pc, #-0x180]
 *   @0x180430 ldr r6, [r4, r1]
 *   @0x180434 str r5, [r6]
 *   @0x180438 ldr r2, [r4, r2]
 *   @0x18043c ldr r3, [r4, r3]
 *   @0x180440 ldr r0, [r2]
 *   @0x180444 ldr r5, [r3]
 *   @0x180448 bl 0x17fc3c <_Z17ConvertComparison8eCmpFunc>
 *   @0x18044c ldr r3, [pc, #-0x19c]
 *   @0x180450 ldr r1, [r6]
 *   @0x180454 ldr r3, [r4, r3]
 *   @0x180458 ldr r2, [r3]
 *   @0x18045c blx r5
 *   @0x180460 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180464 ldr r3, [pc, #-0x1b0]
 *   @0x180468 ldr r3, [r4, r3]
 *   @0x18046c ldr r3, [r3]
 *   @0x180470 blx r3
 *   @0x180474 pop {r3, r4, r5, r6, r7, pc}
 *   @0x180478 ldr r3, [pc, #-0x1c0]
 *   @0x18047c movw r0, #0xb71
 *   @0x180480 ldr r3, [r4, r3]
 *   @0x180484 ldr r3, [r3]
 *   @0x180488 blx r3
 *   @0x18048c pop {r3, r4, r5, r6, r7, pc}
 *   @0x180490 ldr r3, [pc, #-0x1d8]
 *   @0x180494 movw r0, #0xb44
 *   @0x180498 ldr r3, [r4, r3]
 *   @0x18049c ldr r3, [r3]
 *   @0x1804a0 blx r3
 *   @0x1804a4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ §6/56 UpdateViews  0x1b0164  size 1340  328 条（0x1b0164..0x1b06a0）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1b0164 0x1b06a0  size 1340  328 条
 * 部分覆盖: 本节 328/335 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b0174→0x54298c, 0x1b01b8→0x5428e8, 0x1b01d8→0x48f78c, 0x1b02fc→0x3f510c, 0x1b0304→0x3f50d8, 0x1b030c→0x3f5108, 0x1b0324→0x3f50d4, 0x1b0380→0x542374
 * 调用序列: GR_Window_View_UnDefine(int)×2 / 0xb6910×2 / UpdateViews()+0x3c4×2 / UpdateViews()+0x41c×2 / CCameraManager::GetCamera(int) / CCamera::CameraUpdate() / GR_Window_View_Define(int, float, float, float, float, float, float, float, float, float, int, int) / UpdateViews()+0x48c
 * 字段偏移 top8: 0x4×6 / 0x8×6 / 0xc×4 / 0x24×3 / 0x418×2 / 0x2×2 / 0x40×2 / 0x14×2
 * VFP 指令 125 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b0164 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b0168 vpush {d8, d9, d10}
 *   @0x1b016c sub sp, sp, #44
 *   @0x1b0170 ldr r6, [pc, #0x418]
 *   @0x1b0174 ldr r3, [pc, #0x418]
 *   @0x1b0178 add r6, pc, r6
 *   @0x1b017c ldr r7, [r6, r3]
 *   @0x1b0180 ldr r2, [r7]
 *   @0x1b0184 ldrb r4, [r2, #0x44]
 *   @0x1b0188 cmp r4, #0
 *   @0x1b018c beq 0x1b035c <_Z11UpdateViewsv+0x1f8>
 *   @0x1b0190 vmov.f32 s18, #5.000000e-01
 *   @0x1b0194 movw r8, #0x869f
 *   @0x1b0198 movt r8, #0x1
 *   @0x1b019c mov r9, #0
 *   @0x1b01a0 vldr s16, [pc, #996]
 *   @0x1b01a4 add r3, r9, #18
 *   @0x1b01a8 ldr r4, [r2, r3, lsl #2]
 *   @0x1b01ac ldrb r3, [r4]
 *   @0x1b01cc ldr r1, [r4, #0x40]
 *   @0x1b01d0 cmn r1, #1
 *   @0x1b01d4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b01d8 ldr r3, [pc, #0x3bc]
 *   @0x1b01dc ldr r0, [r6, r3]
 *   @0x1b01e0 bl 0x16f45c <_ZN14CCameraManager9GetCameraEi>
 *   @0x1b01e4 cmp r0, #0
 *   @0x1b01e8 beq 0x1b01f0 <_Z11UpdateViewsv+0x8c>
 *   @0x1b01ec bl 0x170b30 <_ZN7CCamera12CameraUpdateEv>
 *   @0x1b01f0 ldr r2, [r7]
 *   @0x1b01f4 add r9, r9, #1
 *   @0x1b01f8 cmp r9, #8
 *   @0x1b01fc bne 0x1b01a4 <_Z11UpdateViewsv+0x40>
 *   @0x1b0200 movw r9, #0xbdc1
 *   @0x1b0204 movw r8, #0x423f
 *   @0x1b0208 movt r9, #0xfff0
 *   @0x1b020c movt r8, #0xf
 *   @0x1b0210 mov r5, #0
 *   @0x1b0214 mov r11, r9
 *   @0x1b0218 mov r10, r8
 *   @0x1b021c b 0x1b0224 <_Z11UpdateViewsv+0xc0>
 *   @0x1b0220 ldr r2, [r7]
 *   @0x1b0224 add r3, r5, #18
 *   @0x1b0228 mov r0, r5
 *   @0x1b022c ldr r4, [r2, r3, lsl #2]
 *   @0x1b0230 bl 0x179cac <_Z23GR_Window_View_UnDefinei>
 *   @0x1b0234 mov r0, r5
 *   @0x1b0238 add r5, r5, #1
 *   @0x1b023c ldrb r3, [r4]
 *   @0x1b0240 cmp r3, #0
 *   @0x1b0244 beq 0x1b02f0 <_Z11UpdateViewsv+0x18c>
 *   @0x1b0248 vldr s9, [r4, #32]
 *   @0x1b024c vcvt.f32.s32 s15, s9
 *   @0x1b0250 ldr r1, [r4, #0x14]
 *   @0x1b0254 ldr r3, [r4, #0x1c]
 *   @0x1b0258 ldr r2, [r4, #0x18]
 *   @0x1b025c cmp r10, r1
 *   @0x1b0260 movge r10, r1
 *   @0x1b0264 add r12, r1, r3
 *   @0x1b0268 vmov s10, r1
 *   @0x1b026c cmp r11, r12
 *   @0x1b0270 movlt r11, r12
 *   @0x1b0274 str r3, [sp, #0x20]
 *   @0x1b0278 vmov r3, s9
 *   @0x1b027c vldr s14, [sp, #32]
 *   @0x1b0280 vstr s15, [sp]
 *   @0x1b0284 ldr r12, [r4, #0x4]
 *   @0x1b0288 vmov s9, r2
 *   @0x1b028c cmp r8, r2
 *   @0x1b0290 movge r8, r2
 *   @0x1b0294 vcvt.f32.s32 s10, s10
 *   @0x1b0298 str r12, [sp, #0x4]
 *   @0x1b029c ldr r12, [r4, #0x8]
 *   @0x1b02a0 str r12, [sp, #0x8]
 *   @0x1b02a4 ldr r12, [r4, #0xc]
 *   @0x1b02a8 vcvt.f32.s32 s9, s9
 *   @0x1b02ac vmov r1, s10
 *   @0x1b02b0 str r12, [sp, #0xc]
 *   @0x1b02b4 ldr r12, [r4, #0x10]
 *   @0x1b02b8 str r12, [sp, #0x10]
 *   @0x1b02bc ldr r12, [r4, #0x24]
 *   @0x1b02c0 vcvt.f32.s32 s14, s14
 *   @0x1b02c4 str r12, [sp, #0x14]
 *   @0x1b02c8 add lr, r2, r3
 *   @0x1b02cc ldr r12, [r4, #0x3c]
 *   @0x1b02d0 cmp r9, lr
 *   @0x1b02d4 movlt r9, lr
 *   @0x1b02d8 vmov r2, s9
 *   @0x1b02dc str r12, [sp, #0x18]
 *   @0x1b02e0 ldr r12, [r4, #0x40]
 *   @0x1b02e4 vmov r3, s14
 *   @0x1b02e8 str r12, [sp, #0x1c]
 *   @0x1b02ec bl 0x179bfc <_Z21GR_Window_View_Defineifffffffffii>
 *   @0x1b02f0 cmp r5, #8
 *   @0x1b02f4 bne 0x1b0220 <_Z11UpdateViewsv+0xbc>
 *   @0x1b02f8 rsb r10, r10, r11
 *   @0x1b02fc ldr r1, [pc, #0x29c]
 *   @0x1b0300 rsb r8, r8, r9
 *   @0x1b0304 ldr r3, [pc, #0x298]
 *   @0x1b0308 vmov s15, r10
 *   @0x1b030c ldr r2, [pc, #0x294]
 *   @0x1b0310 ldr r0, [r6, r1]
 *   @0x1b0314 vldr s13, [r0]
 *   @0x1b0318 vcvt.f32.s32 s12, s15
 *   @0x1b031c ldr r1, [r6, r3]
 *   @0x1b0320 vmov s9, r8
 *   @0x1b0324 ldr r3, [pc, #0x280]
 *   @0x1b0328 vcvt.f32.s32 s13, s13
 *   @0x1b032c vdiv.f32 s13, s13, s12
 *   @0x1b0330 vcvt.f32.s32 s14, s9
 *   @0x1b0334 vstr s13, [r1]
 *   @0x1b0338 ldr r2, [r6, r2]
 *   @0x1b033c vldr s15, [r2]
 *   @0x1b0340 ldr r3, [r6, r3]
 *   @0x1b0344 vcvt.f32.s32 s15, s15
 *   @0x1b0348 vdiv.f32 s15, s15, s14
 *   @0x1b034c vstr s15, [r3]
 *   @0x1b0350 add sp, sp, #44
 *   @0x1b0354 vpop {d8, d9, d10}
 *   @0x1b0358 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b035c mov r0, r4
 *   @0x1b0360 add r4, r4, #1
 *   @0x1b0364 bl 0x179cac <_Z23GR_Window_View_UnDefinei>
 *   @0x1b0368 cmp r4, #8
 *   @0x1b036c bne 0x1b035c <_Z11UpdateViewsv+0x1f8>
 *   @0x1b0370 b 0x1b0350 <_Z11UpdateViewsv+0x1ec>
 *   @0x1b0374 ldr r0, [r4, #0x38]
 *   @0x1b0378 cmp r0, r8
 *   @0x1b037c bgt 0x1b0628 <_Z11UpdateViewsv+0x4c4>
 *   @0x1b0380 ldr r3, [pc, #0x228]
 *   @0x1b0384 ldr r3, [r6, r3]
 *   @0x1b0388 ldr r3, [r3]
 *   @0x1b038c ldr r1, [r3, #0x4]
 *   @0x1b0390 ldr r3, [r3]
 *   @0x1b0394 and r1, r0, r1
 *   @0x1b0398 ldr r3, [r3, r1, lsl #3]
 *   @0x1b039c cmp r3, #0
 *   @0x1b03a0 bne 0x1b03b4 <_Z11UpdateViewsv+0x250>
 *   @0x1b03a4 b 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b03a8 ldr r3, [r3, #0x4]
 *   @0x1b03ac cmp r3, #0
 *   @0x1b03b0 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b03b4 ldr r1, [r3, #0x8]
 *   @0x1b03b8 cmp r0, r1
 *   @0x1b03bc bne 0x1b03a8 <_Z11UpdateViewsv+0x244>
 *   @0x1b03c0 ldr r3, [r3, #0xc]
 *   @0x1b03c4 cmp r3, #0
 *   @0x1b03c8 ldrne r3, [r3, #0xd0]
 *   @0x1b03cc beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b03d0 cmp r3, #0
 *   @0x1b03d4 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b03d8 ldr r1, [r3, #0x8]
 *   @0x1b03dc cmp r1, #0
 *   @0x1b03e0 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b03e4 ldr r5, [r3, #0x8]
 *   @0x1b03e8 ldr r3, [r3]
 *   @0x1b03ec ldrb r1, [r5, #0x68]
 *   @0x1b03f0 cmp r1, #0
 *   @0x1b03f4 bne 0x1b03d0 <_Z11UpdateViewsv+0x26c>
 *   @0x1b03f8 ldrb r1, [r5, #0x69]
 *   @0x1b03fc cmp r1, #0
 *   @0x1b0400 bne 0x1b03d0 <_Z11UpdateViewsv+0x26c>
 *   @0x1b0404 ldrb r3, [r5, #0x64]
 *   @0x1b0408 vldr s20, [r4, #4]
 *   @0x1b040c vldr s19, [r4, #8]
 *   @0x1b0410 cmp r3, #0
 *   @0x1b0414 bne 0x1b068c <_Z11UpdateViewsv+0x528>
 *   @0x1b0418 ldr r0, [r5, #0xb4]
 *   @0x1b041c str r2, [sp, #0x24]
 *   @0x1b0420 bl 0xb6910 <floorf@plt>
 *   @0x1b0424 vmov s17, r0
 *   @0x1b0428 ldr r0, [r5, #0xb8]
 *   @0x1b042c bl 0xb6910 <floorf@plt>
 *   @0x1b0430 ldr r3, [r4, #0x28]
 *   @0x1b0434 vldr s12, [r4, #12]
 *   @0x1b0438 ldr r2, [sp, #0x24]
 *   @0x1b043c lsl r1, r3, #1
 *   @0x1b0440 vmov s15, r1
 *   @0x1b0444 vcvt.f32.s32 s15, s15
 *   @0x1b0448 vcmpe.f32 s15, s12
 *   @0x1b044c vmrs APSR_nzcv, fpscr
 *   @0x1b0450 vmov s11, r0
 *   @0x1b0454 blt 0x1b05f0 <_Z11UpdateViewsv+0x48c>
 *   @0x1b0458 vmov.f32 s14, s17
 *   @0x1b045c vmls.f32 s14, s12, s18
 *   @0x1b0460 ldr r3, [r4, #0x2c]
 *   @0x1b0464 vldr s13, [r4, #16]
 *   @0x1b0468 lsl r1, r3, #1
 *   @0x1b046c vmov s15, r1
 *   @0x1b0470 vcvt.f32.s32 s15, s15
 *   @0x1b0474 vcmpe.f32 s15, s13
 *   @0x1b0478 vmrs APSR_nzcv, fpscr
 *   @0x1b047c blt 0x1b05b8 <_Z11UpdateViewsv+0x454>
 *   @0x1b0480 vmov.f32 s15, s11
 *   @0x1b0484 vmls.f32 s15, s13, s18
 *   @0x1b0488 vldr s9, [r2, #16]
 *   @0x1b048c ldr r3, [r4, #0x30]
 *   @0x1b0490 vcmp.f32 s14, #0
 *   @0x1b0494 vmrs APSR_nzcv, fpscr
 *   @0x1b0498 vmovmi.f32 s14, s16
 *   @0x1b049c vadd.f32 s10, s14, s12
 *   @0x1b04a0 vcvt.f32.s32 s11, s9
 *   @0x1b04a4 vcmpe.f32 s10, s11
 *   @0x1b04a8 vldr s10, [r2, #20]
 *   @0x1b04ac vmrs APSR_nzcv, fpscr
 *   @0x1b04b0 vcmp.f32 s15, #0
 *   @0x1b04b4 vsubgt.f32 s14, s11, s12
 *   @0x1b04b8 vmrs APSR_nzcv, fpscr
 *   @0x1b04bc vmovmi.f32 s15, s16
 *   @0x1b04c0 vadd.f32 s11, s15, s13
 *   @0x1b04c4 vcvt.f32.s32 s12, s10
 *   @0x1b04c8 vcmpe.f32 s11, s12
 *   @0x1b04cc vmrs APSR_nzcv, fpscr
 *   @0x1b04d0 vsubgt.f32 s15, s12, s13
 *   @0x1b04d4 cmp r3, #0
 *   @0x1b04d8 blt 0x1b0528 <_Z11UpdateViewsv+0x3c4>
 *   @0x1b04dc vldr s13, [r4, #4]
 *   @0x1b04e0 vcmpe.f32 s14, s13
 *   @0x1b04e4 vmrs APSR_nzcv, fpscr
 *   @0x1b04e8 bpl 0x1b0504 <_Z11UpdateViewsv+0x3a0>
 *   @0x1b04ec vsub.f32 s11, s13, s14
 *   @0x1b04f0 vmov s9, r3
 *   @0x1b04f4 vcvt.f32.s32 s12, s9
 *   @0x1b04f8 vcmpe.f32 s11, s12
 *   @0x1b04fc vmrs APSR_nzcv, fpscr
 *   @0x1b0500 vsubgt.f32 s14, s13, s12
 *   @0x1b0504 vcmpe.f32 s14, s13
 *   @0x1b0508 vmrs APSR_nzcv, fpscr
 *   @0x1b050c ble 0x1b0528 <_Z11UpdateViewsv+0x3c4>
 *   @0x1b0510 vsub.f32 s11, s14, s13
 *   @0x1b0514 vmov s10, r3
 *   @0x1b0518 vcvt.f32.s32 s12, s10
 *   @0x1b051c vcmpe.f32 s11, s12
 *   @0x1b0520 vmrs APSR_nzcv, fpscr
 *   @0x1b0524 vaddgt.f32 s14, s13, s12
 *   @0x1b0528 ldr r3, [r4, #0x34]
 *   @0x1b052c cmp r3, #0
 *   @0x1b0530 blt 0x1b0580 <_Z11UpdateViewsv+0x41c>
 *   @0x1b0534 vldr s13, [r4, #8]
 *   @0x1b0538 vcmpe.f32 s15, s13
 *   @0x1b053c vmrs APSR_nzcv, fpscr
 *   @0x1b0540 bpl 0x1b055c <_Z11UpdateViewsv+0x3f8>
 *   @0x1b0544 vsub.f32 s11, s13, s15
 *   @0x1b0548 vmov s9, r3
 *   @0x1b054c vcvt.f32.s32 s12, s9
 *   @0x1b0550 vcmpe.f32 s11, s12
 *   @0x1b0554 vmrs APSR_nzcv, fpscr
 *   @0x1b0558 vsubgt.f32 s15, s13, s12
 *   @0x1b055c vcmpe.f32 s15, s13
 *   @0x1b0560 vmrs APSR_nzcv, fpscr
 *   @0x1b0564 ble 0x1b0580 <_Z11UpdateViewsv+0x41c>
 *   @0x1b0568 vsub.f32 s11, s15, s13
 *   @0x1b056c vmov s10, r3
 *   @0x1b0570 vcvt.f32.s32 s12, s10
 *   @0x1b0574 vcmpe.f32 s11, s12
 *   @0x1b0578 vmrs APSR_nzcv, fpscr
 *   @0x1b057c vaddgt.f32 s15, s13, s12
 *   @0x1b0580 vstr s14, [r4, #4]
 *   @0x1b0584 vstr s15, [r4, #8]
 *   @0x1b0588 b 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b058c andeq r0, r0, r0
 *   @0x1b0590 .word 0x00241ad8
 *   @0x1b0594 .word 0xffffbcd8
 *   @0x1b0598 .word 0xffffbcd4
 *   @0x1b059c .word 0xffffc024
 *   @0x1b05a0 .word 0xffffdf38
 *   @0x1b05a4 .word 0xffffe6bc
 *   @0x1b05a8 .word 0xffffdf40
 *   @0x1b05ac .word 0xffffe6c4
 *   @0x1b05b0 .word 0xffffbfec
 *   @0x1b05b4 .word 0xffffbff4
 *   @0x1b05b8 vmov s10, r3
 *   @0x1b05bc vcvt.f32.s32 s9, s10
 *   @0x1b05c0 vldr s10, [r4, #8]
 *   @0x1b05c4 vsub.f32 s15, s11, s9
 *   @0x1b05c8 vcmpe.f32 s15, s10
 *   @0x1b05cc vmrs APSR_nzcv, fpscr
 *   @0x1b05d0 bmi 0x1b0488 <_Z11UpdateViewsv+0x324>
 *   @0x1b05d4 vadd.f32 s11, s9, s11
 *   @0x1b05d8 vadd.f32 s10, s13, s10
 *   @0x1b05dc vcmpe.f32 s11, s10
 *   @0x1b05e0 vmrs APSR_nzcv, fpscr
 *   @0x1b05e4 vsubgt.f32 s15, s11, s13
 *   @0x1b05e8 vmovle.f32 s15, s19
 *   @0x1b05ec b 0x1b0488 <_Z11UpdateViewsv+0x324>
 *   @0x1b05f0 vmov s9, r3
 *   @0x1b05f4 vldr s15, [r4, #4]
 *   @0x1b05f8 vcvt.f32.s32 s13, s9
 *   @0x1b05fc vsub.f32 s14, s17, s13
 *   @0x1b0600 vcmpe.f32 s14, s15
 *   @0x1b0604 vmrs APSR_nzcv, fpscr
 *   @0x1b0608 bmi 0x1b0460 <_Z11UpdateViewsv+0x2fc>
 *   @0x1b060c vadd.f32 s13, s13, s17
 *   @0x1b0610 vadd.f32 s15, s12, s15
 *   @0x1b0614 vcmpe.f32 s13, s15
 *   @0x1b0618 vmrs APSR_nzcv, fpscr
 *   @0x1b061c vsubgt.f32 s14, s13, s12
 *   @0x1b0620 vmovle.f32 s14, s20
 *   @0x1b0624 b 0x1b0460 <_Z11UpdateViewsv+0x2fc>
 *   @0x1b0628 ldr r3, [pc, #-0x7c]
 *   @0x1b062c ldr r3, [r6, r3]
 *   @0x1b0630 ldr r1, [r3, #0x4]
 *   @0x1b0634 ldr r3, [r3]
 *   @0x1b0638 and r1, r0, r1
 *   @0x1b063c ldr r3, [r3, r1, lsl #3]
 *   @0x1b0640 cmp r3, #0
 *   @0x1b0644 bne 0x1b0658 <_Z11UpdateViewsv+0x4f4>
 *   @0x1b0648 b 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b064c ldr r3, [r3, #0x4]
 *   @0x1b0650 cmp r3, #0
 *   @0x1b0654 beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b0658 ldr r1, [r3, #0x8]
 *   @0x1b065c cmp r0, r1
 *   @0x1b0660 bne 0x1b064c <_Z11UpdateViewsv+0x4e8>
 *   @0x1b0664 ldr r5, [r3, #0xc]
 *   @0x1b0668 cmp r5, #0
 *   @0x1b066c beq 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b0670 ldrb r3, [r5, #0x68]
 *   @0x1b0674 cmp r3, #0
 *   @0x1b0678 bne 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b067c ldrb r3, [r5, #0x69]
 *   @0x1b0680 cmp r3, #0
 *   @0x1b0684 bne 0x1b01f4 <_Z11UpdateViewsv+0x90>
 *   @0x1b0688 b 0x1b0404 <_Z11UpdateViewsv+0x2a0>
 *   @0x1b068c mov r0, r5
 *   @0x1b0690 mov r1, #1
 *   @0x1b0694 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x1b0698 ldr r2, [r7]
 *   @0x1b069c b 0x1b0418 <_Z11UpdateViewsv+0x2b4>
 *
 * ══ §7/56 GR_Texture_Draw_Tiled  0x1762b0  size 1308  320 条（0x1762b0..0x1767cc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1762b0 0x1767cc  size 1308  320 条
 * 部分覆盖: 本节 320/327 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x176334→0x5428e8, 0x176368→0x5425c0, 0x1763e0→0x483678, 0x176434→0x48ffec, 0x176530→0x4859ac, 0x1766b8→0x48f78c
 * 调用序列: CCameraManager::GetActiveCamera()×2 / 0xb6790×2 / GR_Texture_Exists(int) / Graphics::GetMaxDynamicVertexCount() / GR_Texture_Draw_Tiled(YYTPageEntry*, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x60 / GR_Texture_Draw_Tiled(YYTPageEntry*, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)+0x3b8 / Graphics::AllocVerts(ePrimType, void*, int, int) / CCamera::Is2D()
 * 字段偏移 top8: 0x34×6 / 0x38×4 / 0xc×3 / 0x24×3 / 0x3c×3 / 0x30×3 / 0x8×2 / 0xbc×2
 * VFP 指令 132 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1762b0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1762b4 vpush {d8, d9, d10, d11, d12, d13}
 *   @0x1762b8 subs r9, r0, #0
 *   @0x1762bc sub sp, sp, #68
 *   @0x1762c0 ldr r12, [pc, #0x3d4]
 *   @0x1762c4 mov r6, r1
 *   @0x1762c8 mov r7, r2
 *   @0x1762cc add r12, pc, r12
 *   @0x1762d0 vmov s26, r3
 *   @0x1762d4 str r12, [sp, #0x34]
 *   @0x1762d8 vldr s23, [sp, #156]
 *   @0x1762dc vldr s25, [sp, #160]
 *   @0x1762e0 ldrb r5, [sp, #0xa4]
 *   @0x1762e4 ldrb r4, [sp, #0xa8]
 *   @0x1762e8 beq 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58>
 *   @0x1762ec vldr s15, [pc, #928]
 *   @0x1762f0 vcmpe.f32 s23, s15
 *   @0x1762f4 vmrs APSR_nzcv, fpscr
 *   @0x1762f8 bmi 0x176308 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x58>
 *   @0x1762fc vcmpe.f32 s25, s15
 *   @0x176300 vmrs APSR_nzcv, fpscr
 *   @0x176304 bpl 0x176320 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x70>
 *   @0x176308 mov r12, #0
 *   @0x17630c str r12, [sp, #0x38]
 *   @0x176310 ldr r0, [sp, #0x38]
 *   @0x176314 add sp, sp, #68
 *   @0x176318 vpop {d8, d9, d10, d11, d12, d13}
 *   @0x17631c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x176320 ldrsh r0, [r9, #20]
 *   @0x176324 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x176328 cmp r0, #0
 *   @0x176348 bne 0x1766b8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x408>
 *   @0x17634c eor r2, r5, #1
 *   @0x176350 eor r3, r4, #1
 *   @0x176354 tst r2, r3
 *   @0x176358 bne 0x1766e4 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x434>
 *   @0x17635c ldrsh r1, [r9, #16]
 *   @0x176360 cmp r5, #0
 *   @0x176364 ldrsh r2, [r9, #18]
 *   @0x176368 ldr r3, [pc, #0x334]
 *   @0x17636c vmov s17, r1
 *   @0x176370 ldr r12, [sp, #0x34]
 *   @0x176374 vmov s16, r2
 *   @0x176378 vcvt.f32.s32 s17, s17
 *   @0x17637c ldr r3, [r12, r3]
 *   @0x176380 ldm r3, {r2, r5}
 *   @0x176384 ldr r1, [r3, #0x8]
 *   @0x176388 ldr r6, [r3, #0xc]
 *   @0x17638c vmul.f32 s17, s17, s23
 *   @0x176390 vcvt.f32.s32 s16, s16
 *   @0x176394 vmoveq.f32 s19, s17
 *   @0x176398 vmul.f32 s16, s16, s25
 *   @0x17639c bne 0x176724 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x474>
 *   @0x1763a0 cmp r4, #0
 *   @0x1763a4 vmoveq.f32 s18, s16
 *   @0x1763a8 bne 0x176774 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x4c4>
 *   @0x1763ac vldr s15, [pc, #740]
 *   @0x1763b0 vldr s12, [sp, #192]
 *   @0x1763b4 vmul.f32 s15, s12, s15
 *   @0x1763b8 vcvt.s32.f32 s15, s15
 *   @0x1763bc vmov r6, s15
 *   @0x1763c0 cmp r6, #255
 *   @0x1763c4 movgt r6, #-16777216
 *   @0x1763c8 bgt 0x1763d8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x128>
 *   @0x1763cc cmp r6, #0
 *   @0x1763d0 lslge r6, r6, #24
 *   @0x1763d4 movlt r6, #0
 *   @0x1763d8 vdiv.f32 s16, s18, s16
 *   @0x1763dc ldr r12, [sp, #0x34]
 *   @0x1763e0 ldr r3, [pc, #0x2c0]
 *   @0x1763e4 ldr r1, [sp, #0xbc]
 *   @0x1763e8 ldrsh r0, [r9, #6]
 *   @0x1763ec ldr r3, [r12, r3]
 *   @0x1763f0 bic r2, r1, #-16777216
 *   @0x1763f4 orr r6, r6, r2
 *   @0x1763f8 ldrsh r1, [r9, #4]
 *   @0x1763fc ldrsh r2, [r9]
 *   @0x176400 ldrb r3, [r3]
 *   @0x176404 add r1, r2, r1
 *   @0x176408 cmp r3, #0
 *   @0x17640c ldrsh r3, [r9, #2]
 *   @0x176410 bicne r6, r6, #65536
 *   @0x176414 vmov s20, r1
 *   @0x176418 bicne r6, r6, #1
 *   @0x17641c ldrsh r1, [r9, #14]
 *   @0x176420 orrne r12, r6, #1
 *   @0x176424 strne r12, [sp, #0x20]
 *   @0x176428 ldrsh r12, [r9, #12]
 *   @0x17642c add r0, r3, r0
 *   @0x176430 vmov s27, r1
 *   @0x176434 ldr r1, [pc, #0x270]
 *   @0x176438 vmov s12, r2
 *   @0x17643c streq r6, [sp, #0x20]
 *   @0x176440 vmov s24, r12
 *   @0x176444 ldr r12, [sp, #0x34]
 *   @0x176448 vmov s22, r0
 *   @0x17644c ldrsh r0, [r9, #20]
 *   @0x176450 orrne r7, r6, #65536
 *   @0x176454 moveq r11, r6
 *   @0x176458 ldr r1, [r12, r1]
 *   @0x17645c orrne r11, r7, #1
 *   @0x176460 moveq r7, r6
 *   @0x176464 ldr r1, [r1, #0x4]
 *   @0x176468 ldr r1, [r1, r0, lsl #2]
 *   @0x17646c vldr s15, [r1, #12]
 *   @0x176470 vldr s14, [r1, #8]
 *   @0x176474 str r1, [sp, #0x24]
 *   @0x176478 vdiv.f32 s17, s19, s17
 *   @0x17647c vcvt.f32.s32 s13, s12
 *   @0x176480 vmov s12, r3
 *   @0x176484 vcvt.f32.s32 s20, s20
 *   @0x176488 vcvt.f32.s32 s21, s12
 *   @0x17648c vcvt.f32.s32 s22, s22
 *   @0x176490 vcvt.s32.f32 s16, s16
 *   @0x176494 vmul.f32 s21, s21, s15
 *   @0x176498 vstr s16, [sp, #60]
 *   @0x17649c vmul.f32 s22, s15, s22
 *   @0x1764a0 vmul.f32 s19, s13, s14
 *   @0x1764a4 vmul.f32 s20, s14, s20
 *   @0x1764a8 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv>
 *   @0x1764ac ldrsh r1, [r9, #10]
 *   @0x1764b0 ldr r12, [sp, #0x3c]
 *   @0x1764b4 vmov s15, r1
 *   @0x1764b8 cmp r12, #0
 *   @0x1764bc vcvt.s32.f32 s17, s17
 *   @0x1764c0 vmov r10, s17
 *   @0x1764c4 vldr s17, [sp, #152]
 *   @0x1764c8 vcvt.f32.s32 s27, s27
 *   @0x1764cc vcvt.f32.s32 s24, s24
 *   @0x1764d0 str r0, [sp, #0x2c]
 *   @0x1764d4 vcvt.f32.s32 s15, s15
 *   @0x1764d8 add r8, r10, r10, lsl #1
 *   @0x1764dc lsl r8, r8, #1
 *   @0x1764e0 vmul.f32 s27, s27, s25
 *   @0x1764e4 mul r8, r12, r8
 *   @0x1764e8 vmul.f32 s24, s24, s23
 *   @0x1764ec vmla.f32 s17, s15, s25
 *   @0x1764f0 ble 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60>
 *   @0x1764f4 mov r3, #0
 *   @0x1764f8 mov r12, #0
 *   @0x1764fc mov r4, r3
 *   @0x176500 str r12, [sp, #0x30]
 *   @0x176504 movw r12, #0xaaab
 *   @0x176508 movt r12, #0x2aaa
 *   @0x17650c str r12, [sp, #0x28]
 *   @0x176510 mov r12, r11
 *   @0x176514 ldrsh r1, [r9, #8]
 *   @0x176518 cmp r10, #0
 *   @0x17651c vmov s15, r1
 *   @0x176520 vcvt.f32.s32 s15, s15
 *   @0x176524 vmov.f32 s16, s26
 *   @0x176528 vmla.f32 s16, s15, s23
 *   @0x17652c ble 0x176668 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x3b8>
 *   @0x176530 ldr r2, [pc, #0x178]
 *   @0x176534 mov r5, #0
 *   @0x176538 ldr r1, [sp, #0x34]
 *   @0x17653c ldr r11, [r1, r2]
 *   @0x176540 mov r2, r11
 *   @0x176544 mov r11, r12
 *   @0x176548 mov r12, r2
 *   @0x17654c vadd.f32 s18, s17, s27
 *   @0x176550 cmp r4, #0
 *   @0x176554 add r5, r5, #1
 *   @0x176558 mov r0, #4
 *   @0x17655c mov r2, #24
 *   @0x176560 bne 0x1765a8 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x2f8>
 *   @0x176564 ldr r4, [sp, #0x2c]
 *   @0x176568 ldr r1, [sp, #0x28]
 *   @0x17656c cmp r4, r8
 *   @0x176570 movge r4, r8
 *   @0x176574 cmp r4, #6
 *   @0x176578 smull r1, r3, r1, r4
 *   @0x17657c subgt r4, r3, r4, asr #31
 *   @0x176580 ldr r3, [sp, #0x24]
 *   @0x176584 addgt r4, r4, r4, lsl #1
 *   @0x176588 ldr r1, [r3]
 *   @0x17658c lslgt r4, r4, #1
 *   @0x176590 str r12, [sp, #0x1c]
 *   @0x176594 rsb r8, r4, r8
 *   @0x176598 mov r3, r4
 *   @0x17659c bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x1765a0 ldr r12, [sp, #0x1c]
 *   @0x1765a4 mov r3, r0
 *   @0x1765a8 vadd.f32 s15, s16, s24
 *   @0x1765ac ldr r2, [r12]
 *   @0x1765b0 ldr r1, [sp, #0x20]
 *   @0x1765b4 vstr s16, [r3, #24]
 *   @0x1765b8 vstr s16, [r3]
 *   @0x1765bc str r6, [r3, #0x84]
 *   @0x1765c0 str r2, [r3, #0x80]
 *   @0x1765c4 vstr s18, [r3, #4]
 *   @0x1765c8 str r2, [r3, #0x68]
 *   @0x1765cc vstr s19, [r3, #16]
 *   @0x1765d0 str r2, [r3, #0x50]
 *   @0x1765d4 vstr s22, [r3, #20]
 *   @0x1765d8 str r2, [r3, #0x38]
 *   @0x1765dc vstr s17, [r3, #28]
 *   @0x1765e0 str r2, [r3, #0x20]
 *   @0x1765e4 vstr s19, [r3, #40]
 *   @0x1765e8 str r6, [r3, #0xc]
 *   @0x1765ec vstr s21, [r3, #44]
 *   @0x1765f0 str r1, [r3, #0x24]
 *   @0x1765f4 vstr s17, [r3, #52]
 *   @0x1765f8 vstr s15, [r3, #48]
 *   @0x1765fc vstr s15, [r3, #72]
 *   @0x176600 vstr s15, [r3, #96]
 *   @0x176604 str r7, [r3, #0x54]
 *   @0x176608 str r7, [r3, #0x3c]
 *   @0x17660c vstr s20, [r3, #64]
 *   @0x176610 str r11, [r3, #0x6c]
 *   @0x176614 vstr s21, [r3, #68]
 *   @0x176618 vstr s17, [r3, #76]
 *   @0x17661c vstr s20, [r3, #88]
 *   @0x176620 vstr s21, [r3, #92]
 *   @0x176624 vstr s18, [r3, #100]
 *   @0x176628 vstr s20, [r3, #112]
 *   @0x17662c vstr s22, [r3, #116]
 *   @0x176630 str r2, [r3, #0x8]
 *   @0x176634 vstr s19, [r3, #136]
 *   @0x176638 vstr s22, [r3, #140]
 *   @0x17663c ldrsh r2, [r9, #16]
 *   @0x176640 cmp r5, r10
 *   @0x176644 vstr s16, [r3, #120]
 *   @0x176648 vstr s18, [r3, #124]
 *   @0x17664c sub r4, r4, #6
 *   @0x176650 vmov s15, r2
 *   @0x176654 add r3, r3, #144
 *   @0x176658 vcvt.f32.s32 s15, s15
 *   @0x17665c vmla.f32 s16, s15, s23
 *   @0x176660 bne 0x176550 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x2a0>
 *   @0x176664 mov r12, r11
 *   @0x176668 ldrsh r1, [r9, #18]
 *   @0x17666c ldr r2, [sp, #0x30]
 *   @0x176670 vmov s15, r1
 *   @0x176674 ldr r1, [sp, #0x3c]
 *   @0x176678 add r2, r2, #1
 *   @0x17667c str r2, [sp, #0x30]
 *   @0x176680 vcvt.f32.s32 s15, s15
 *   @0x176684 cmp r2, r1
 *   @0x176688 vmla.f32 s17, s15, s25
 *   @0x17668c bne 0x176514 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x264>
 *   @0x176690 b 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60>
 *   @0x176694 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^
 *   @0x176698 cmnmi pc, #0
 *   @0x17669c eoreq r11, r7, r4, lsl #19
 *   @0x1766a0 .word 0xffffbcd4
 *   @0x1766a4 .word 0xffffe4fc
 *   @0x1766a8 .word 0xffffc1fc
 *   @0x1766ac .word 0xffffbccc
 *   @0x1766b0 .word 0xffffbcd0
 *   @0x1766b4 .word 0xffffc024
 *   @0x1766b8 ldr r3, [pc, #-0xc]
 *   @0x1766bc ldr r8, [r12, r3]
 *   @0x1766c0 mov r0, r8
 *   @0x1766c4 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x1766c8 cmp r0, #0
 *   @0x1766cc beq 0x17634c <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x9c>
 *   @0x1766d0 mov r0, r8
 *   @0x1766d4 bl 0x16ec3c <_ZN14CCameraManager15GetActiveCameraEv>
 *   @0x1766d8 bl 0x16d398 <_ZN7CCamera4Is2DEv>
 *   @0x1766dc cmp r0, #0
 *   @0x1766e0 bne 0x17634c <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x9c>
 *   @0x1766e4 ldr r1, [sp, #0xbc]
 *   @0x1766e8 vldr s12, [sp, #152]
 *   @0x1766ec mov r3, #0
 *   @0x1766f0 vstr s12, [sp]
 *   @0x1766f4 str r3, [sp, #0xc]
 *   @0x1766f8 vldr s12, [sp, #192]
 *   @0x1766fc str r1, [sp, #0x10]
 *   @0x176700 vstr s23, [sp, #4]
 *   @0x176704 vstr s25, [sp, #8]
 *   @0x176708 vstr s12, [sp, #20]
 *   @0x17670c mov r0, r9
 *   @0x176710 mov r1, r6
 *   @0x176714 mov r2, r7
 *   @0x176718 vmov r3, s26
 *   @0x17671c bl 0x174ee0 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf>
 *   @0x176720 b 0x176310 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0x60>
 *   @0x176724 vmov.f32 s14, #1.000000e+00
 *   @0x176728 rsb r1, r2, r1
 *   @0x17672c vmov s12, r2
 *   @0x176730 vmov s15, r1
 *   @0x176734 vmov r1, s17
 *   @0x176738 vsub.f32 s14, s17, s14
 *   @0x17673c vcvt.f32.s32 s15, s15
 *   @0x176740 vadd.f32 s19, s14, s15
 *   @0x176744 vdiv.f32 s19, s19, s17
 *   @0x176748 vcvt.f32.s32 s18, s12
 *   @0x17674c vsub.f32 s26, s26, s18
 *   @0x176750 vmov.f32 s15, #2.000000e+00
 *   @0x176754 vmov r0, s26
 *   @0x176758 vadd.f32 s19, s19, s15
 *   @0x17675c bl 0xb6790 <fmodf@plt>
 *   @0x176760 vmul.f32 s19, s19, s17
 *   @0x176764 vmov s13, r0
 *   @0x176768 vadd.f32 s18, s13, s18
 *   @0x17676c vsub.f32 s26, s18, s17
 *   @0x176770 b 0x1763a0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0xf0>
 *   @0x176774 vmov.f32 s14, #1.000000e+00
 *   @0x176778 rsb r6, r5, r6
 *   @0x17677c vmov s13, r5
 *   @0x176780 vmov s12, r6
 *   @0x176784 vmov r1, s16
 *   @0x176788 vsub.f32 s14, s16, s14
 *   @0x17678c vcvt.f32.s32 s15, s12
 *   @0x176790 vadd.f32 s18, s14, s15
 *   @0x176794 vldr s14, [sp, #152]
 *   @0x176798 vdiv.f32 s18, s18, s16
 *   @0x17679c vcvt.f32.s32 s20, s13
 *   @0x1767a0 vsub.f32 s14, s14, s20
 *   @0x1767a4 vmov.f32 s15, #2.000000e+00
 *   @0x1767a8 vmov r0, s14
 *   @0x1767ac vadd.f32 s18, s18, s15
 *   @0x1767b0 bl 0xb6790 <fmodf@plt>
 *   @0x1767b4 vmul.f32 s18, s18, s16
 *   @0x1767b8 vmov s15, r0
 *   @0x1767bc vadd.f32 s20, s15, s20
 *   @0x1767c0 vsub.f32 s20, s20, s16
 *   @0x1767c4 vstr s20, [sp, #152]
 *   @0x1767c8 b 0x1763ac <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf+0xfc>
 *
 * ══ §8/56 Graphics::Clear  0x17eec4  size 1180  293 条（0x17eec4..0x17f360）｜其中 2 条已由别的卡落锚，本节不再重复
 * @func 0x17eec4 0x17f360  size 1180  293 条
 * 部分覆盖: 本节 293/295 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17eed4→0x4a22b1, 0x17ef0c→0x7590bd, 0x17ef20→0x4859c8, 0x17efac→0x4a2150, 0x17efc0→0x4a214c, 0x17efd4→0x4a2148, 0x17efd8→0x3f289c, 0x17eff4→0x4a2144
 * 调用序列: RenderStateManager::SetRenderState(eRenderState, unsigned int)×12 / Graphics::GetMatrix(eMatrix, float*)×3 / Graphics::Flush()×2 / RenderStateManager::SaveStates()×2 / Shader_Set(Shader*)×2 / FlushShader()×2 / Graphics::SetMatrices(float*, float*, float*)×2 / RenderStateManager::RestoreStates()×2
 * 字段偏移 top8: 0x4×3 / 0x350×2 / 0xf4×2 / 0xe0×2 / 0x30×2 / 0x43c×1 / 0x438×1 / 0x404×1
 * VFP 指令 17 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17eec4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17eec8 mov r5, r3
 *   @0x17eecc ldr r4, [pc, #0x43c]
 *   @0x17eed0 sub sp, sp, #268
 *   @0x17eed4 ldr r6, [pc, #0x438]
 *   @0x17eed8 mov r7, r0
 *   @0x17eedc add r4, pc, r4
 *   @0x17eee0 mov r11, r1
 *   @0x17eee4 mov r8, r2
 *   @0x17eee8 ldr r3, [r4, r6]
 *   @0x17eeec ldrb r3, [r3]
 *   @0x17eef0 cmp r3, #0
 *   @0x17eef4 beq 0x17ef00 <_ZN8Graphics5ClearEjfi11eClearFlags+0x3c>
 *   @0x17eef8 cmp r5, #0
 *   @0x17eefc bne 0x17ef08 <_ZN8Graphics5ClearEjfi11eClearFlags+0x44>
 *   @0x17ef00 add sp, sp, #268
 *   @0x17ef04 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17ef08 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17ef0c ldr r3, [pc, #0x404]
 *   @0x17ef10 ldr r3, [r4, r3]
 *   @0x17ef14 ldrb r9, [r3]
 *   @0x17ef18 cmp r9, #0
 *   @0x17ef1c bne 0x17f064 <_ZN8Graphics5ClearEjfi11eClearFlags+0x1a0>
 *   @0x17ef20 ldr r3, [pc, #0x3f4]
 *   @0x17ef24 ldr r6, [r4, r3]
 *   @0x17ef28 mov r0, r6
 *   @0x17ef2c bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x17ef30 mov r0, r6
 *   @0x17ef34 mov r1, #24
 *   @0x17ef38 mov r2, #15
 *   @0x17ef3c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17ef40 mov r2, r9
 *   @0x17ef44 mov r0, r6
 *   @0x17ef48 mov r1, #12
 *   @0x17ef4c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17ef50 mov r0, r6
 *   @0x17ef54 mov r1, #32
 *   @0x17ef58 mvn r2, #0
 *   @0x17ef5c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17ef60 mov r0, r6
 *   @0x17ef64 mov r1, #4
 *   @0x17ef68 mov r2, #1
 *   @0x17ef6c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17ef70 mov r0, r6
 *   @0x17ef74 mov r1, #25
 *   @0x17ef78 mov r2, #1
 *   @0x17ef7c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17ef80 ands r9, r5, #1
 *   @0x17ef84 bne 0x17f284 <_ZN8Graphics5ClearEjfi11eClearFlags+0x3c0>
 *   @0x17ef88 tst r5, #2
 *   @0x17ef8c bne 0x17f254 <_ZN8Graphics5ClearEjfi11eClearFlags+0x390>
 *   @0x17ef90 mov r0, r6
 *   @0x17ef94 bl 0x168134 <_ZN18RenderStateManager5FlushEv>
 *   @0x17ef98 ldr r1, [pc, #0x380]
 *   @0x17ef9c movw r0, #0x8080
 *   @0x17efa0 movt r0, #0xff80
 *   @0x17efa4 add r1, pc, r1
 *   @0x17efa8 bl 0x17b8f0 <_ZN12GraphicsPerf4PushEjPKc>
 *   @0x17efac ldr r3, [pc, #0x370]
 *   @0x17efb0 ldr r3, [r4, r3]
 *   @0x17efb4 ldr r3, [r3]
 *   @0x17efb8 cmp r3, #0
 *   @0x17efbc bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c>
 *   @0x17efc0 ldr r3, [pc, #0x360]
 *   @0x17efc4 ldr r3, [r4, r3]
 *   @0x17efc8 ldr r3, [r3]
 *   @0x17efcc cmp r3, #0
 *   @0x17efd0 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c>
 *   @0x17efd4 ldr r2, [pc, #0x350]
 *   @0x17efd8 ldr r3, [pc, #0x350]
 *   @0x17efdc ldr r2, [r4, r2]
 *   @0x17efe0 ldr r3, [r4, r3]
 *   @0x17efe4 ldr r2, [r2]
 *   @0x17efe8 ldr r3, [r3]
 *   @0x17efec cmp r2, r3
 *   @0x17eff0 beq 0x17f2fc <_ZN8Graphics5ClearEjfi11eClearFlags+0x438>
 *   @0x17eff4 ldr r1, [pc, #0x338]
 *   @0x17eff8 ldr r1, [r4, r1]
 *   @0x17effc ldr r1, [r1]
 *   @0x17f000 cmp r3, r1
 *   @0x17f004 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c>
 *   @0x17f008 ldr r1, [pc, #0x328]
 *   @0x17f00c ldr r1, [r4, r1]
 *   @0x17f010 ldr r1, [r1]
 *   @0x17f014 cmp r1, r3
 *   @0x17f018 beq 0x17f024 <_ZN8Graphics5ClearEjfi11eClearFlags+0x160>
 *   @0x17f01c cmp r2, r1
 *   @0x17f020 bne 0x17f230 <_ZN8Graphics5ClearEjfi11eClearFlags+0x36c>
 *   @0x17f024 ldr r3, [pc, #0x310]
 *   @0x17f028 movw r0, #0xc11
 *   @0x17f02c ldr r3, [r4, r3]
 *   @0x17f030 ldr r3, [r3]
 *   @0x17f034 blx r3
 *   @0x17f038 ldr r3, [pc, #0x300]
 *   @0x17f03c mov r0, r9
 *   @0x17f040 ldr r3, [r4, r3]
 *   @0x17f044 ldr r3, [r3]
 *   @0x17f048 blx r3
 *   @0x17f04c ldr r3, [pc, #0x2f0]
 *   @0x17f050 movw r0, #0xc11
 *   @0x17f054 ldr r3, [r4, r3]
 *   @0x17f058 ldr r3, [r3]
 *   @0x17f05c blx r3
 *   @0x17f060 b 0x17f244 <_ZN8Graphics5ClearEjfi11eClearFlags+0x380>
 *   @0x17f064 add r10, sp, #8
 *   @0x17f068 add r9, sp, #72
 *   @0x17f06c mov r0, #2
 *   @0x17f070 add r8, sp, #136
 *   @0x17f074 mov r1, r10
 *   @0x17f078 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17f07c mov r1, r9
 *   @0x17f080 mov r0, #0
 *   @0x17f084 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17f088 mov r1, r8
 *   @0x17f08c mov r0, #1
 *   @0x17f090 bl 0x17ead0 <_ZN8Graphics9GetMatrixE7eMatrixPf>
 *   @0x17f094 ldr r3, [pc, #0x280]
 *   @0x17f098 ldr r6, [r4, r3]
 *   @0x17f09c mov r0, r6
 *   @0x17f0a0 bl 0x167fcc <_ZN18RenderStateManager10SaveStatesEv>
 *   @0x17f0a4 ldr r3, [pc, #0x29c]
 *   @0x17f0a8 mov r0, #0
 *   @0x17f0ac ldr r3, [r4, r3]
 *   @0x17f0b0 ldr r3, [r3]
 *   @0x17f0b4 str r3, [sp, #0x4]
 *   @0x17f0b8 bl 0x1e2024 <_Z10Shader_SetP6Shader>
 *   @0x17f0bc bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x17f0c0 mov r0, r6
 *   @0x17f0c4 mov r1, #1
 *   @0x17f0c8 mov r2, #0
 *   @0x17f0cc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f0d0 mov r0, r6
 *   @0x17f0d4 mov r1, #12
 *   @0x17f0d8 mov r2, #0
 *   @0x17f0dc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f0e0 mov r0, r6
 *   @0x17f0e4 mov r1, #5
 *   @0x17f0e8 mov r2, #0
 *   @0x17f0ec bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f0f0 mov r0, r6
 *   @0x17f0f4 mov r1, #21
 *   @0x17f0f8 mov r2, #0
 *   @0x17f0fc bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f100 mov r0, r6
 *   @0x17f104 mov r1, #8
 *   @0x17f108 mov r2, #0
 *   @0x17f10c bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f110 ands r2, r5, #1
 *   @0x17f114 mov r0, r6
 *   @0x17f118 mov r1, #24
 *   @0x17f11c movne r2, #15
 *   @0x17f120 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f124 ands r2, r5, #2
 *   @0x17f128 mov r0, r6
 *   @0x17f12c mov r1, #4
 *   @0x17f130 movne r2, #1
 *   @0x17f134 mov r5, #1065353216
 *   @0x17f138 bl 0x167e64 <_ZN18RenderStateManager14SetRenderStateE12eRenderStatej>
 *   @0x17f13c add r0, sp, #200
 *   @0x17f140 mov r3, #0
 *   @0x17f144 str r5, [sp, #0x104]
 *   @0x17f148 mov r1, r0
 *   @0x17f14c mov r2, r0
 *   @0x17f150 str r3, [sp, #0x100]
 *   @0x17f154 str r3, [sp, #0xfc]
 *   @0x17f158 str r3, [sp, #0xf8]
 *   @0x17f15c str r3, [sp, #0xf4]
 *   @0x17f160 str r3, [sp, #0xec]
 *   @0x17f164 str r3, [sp, #0xe8]
 *   @0x17f168 str r3, [sp, #0xe4]
 *   @0x17f16c str r3, [sp, #0xe0]
 *   @0x17f170 str r3, [sp, #0xd8]
 *   @0x17f174 str r3, [sp, #0xd4]
 *   @0x17f178 str r3, [sp, #0xd0]
 *   @0x17f17c str r3, [sp, #0xcc]
 *   @0x17f180 str r5, [sp, #0xf0]
 *   @0x17f184 str r5, [sp, #0xdc]
 *   @0x17f188 str r5, [sp, #0xc8]
 *   @0x17f18c bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x17f190 mov r1, #0
 *   @0x17f194 mov r2, #16
 *   @0x17f198 mov r3, #4
 *   @0x17f19c mov r0, #5
 *   @0x17f1a0 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17f1a4 mov r3, #0
 *   @0x17f1a8 movt r3, #0xbf80
 *   @0x17f1ac str r5, [r0, #0x14]
 *   @0x17f1b0 str r3, [r0]
 *   @0x17f1b4 str r3, [r0, #0x4]
 *   @0x17f1b8 str r3, [r0, #0x10]
 *   @0x17f1bc str r3, [r0, #0x24]
 *   @0x17f1c0 str r5, [r0, #0x20]
 *   @0x17f1c4 str r5, [r0, #0x30]
 *   @0x17f1c8 str r5, [r0, #0x34]
 *   @0x17f1cc str r11, [r0, #0x38]
 *   @0x17f1d0 str r11, [r0, #0x28]
 *   @0x17f1d4 str r11, [r0, #0x18]
 *   @0x17f1d8 str r11, [r0, #0x8]
 *   @0x17f1dc str r7, [r0, #0x3c]
 *   @0x17f1e0 str r7, [r0, #0x2c]
 *   @0x17f1e4 str r7, [r0, #0x1c]
 *   @0x17f1e8 str r7, [r0, #0xc]
 *   @0x17f1ec bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17f1f0 mov r0, r6
 *   @0x17f1f4 bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x17f1f8 mov r0, r10
 *   @0x17f1fc mov r1, r9
 *   @0x17f200 mov r2, r8
 *   @0x17f204 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x17f208 ldr r0, [sp, #0x4]
 *   @0x17f20c bl 0x1e2024 <_Z10Shader_SetP6Shader>
 *   @0x17f210 bl 0x1e1520 <_Z11FlushShaderv>
 *   @0x17f214 ldr r3, [pc, #0x130]
 *   @0x17f218 ldr r3, [r4, r3]
 *   @0x17f21c ldr r2, [r3]
 *   @0x17f220 add r2, r2, #1
 *   @0x17f224 str r2, [r3]
 *   @0x17f228 add sp, sp, #268
 *   @0x17f22c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17f230 ldr r3, [pc, #0x108]
 *   @0x17f234 mov r0, r9
 *   @0x17f238 ldr r3, [r4, r3]
 *   @0x17f23c ldr r3, [r3]
 *   @0x17f240 blx r3
 *   @0x17f244 bl 0x17bb10 <_ZN12GraphicsPerf3PopEv>
 *   @0x17f248 mov r0, r6
 *   @0x17f24c bl 0x168050 <_ZN18RenderStateManager13RestoreStatesEv>
 *   @0x17f250 b 0x17f214 <_ZN8Graphics5ClearEjfi11eClearFlags+0x350>
 *   @0x17f254 ldr r3, [pc, #0xf4]
 *   @0x17f258 mov r0, #1065353216
 *   @0x17f260 ldr r3, [r4, r3]
 *   @0x17f264 ldr r3, [r3]
 *   @0x17f268 blx r3
 *   @0x17f26c ldr r3, [pc, #0xe0]
 *   @0x17f270 mov r0, r8
 *   @0x17f274 ldr r3, [r4, r3]
 *   @0x17f278 ldr r3, [r3]
 *   @0x17f27c blx r3
 *   @0x17f280 b 0x17ef90 <_ZN8Graphics5ClearEjfi11eClearFlags+0xcc>
 *   @0x17f284 uxtb r2, r7
 *   @0x17f288 vldr s15, [pc, #124]
 *   @0x17f28c ldr r3, [pc, #0xc4]
 *   @0x17f294 vmov s11, r2
 *   @0x17f298 ubfx r2, r7, #0x8, #0x8
 *   @0x17f29c vmov s12, r2
 *   @0x17f2a0 ubfx r2, r7, #0x10, #0x8
 *   @0x17f2a4 vcvt.f32.s32 s11, s11
 *   @0x17f2a8 vmov s13, r2
 *   @0x17f2ac lsr r2, r7, #24
 *   @0x17f2b0 vmov s14, r2
 *   @0x17f2b4 ldr r2, [r4, r3]
 *   @0x17f2b8 ldr r3, [pc, #0x9c]
 *   @0x17f2bc str r7, [r2]
 *   @0x17f2c0 vcvt.f32.s32 s12, s12
 *   @0x17f2c4 ldr r3, [r4, r3]
 *   @0x17f2c8 ldr r12, [r3]
 *   @0x17f2cc vcvt.f32.s32 s13, s13
 *   @0x17f2d0 vcvt.f32.u32 s14, s14
 *   @0x17f2d4 vdiv.f32 s11, s11, s15
 *   @0x17f2d8 vdiv.f32 s12, s12, s15
 *   @0x17f2dc vmov r0, s11
 *   @0x17f2e0 vdiv.f32 s13, s13, s15
 *   @0x17f2e4 vmov r1, s12
 *   @0x17f2e8 vdiv.f32 s14, s14, s15
 *   @0x17f2ec vmov r2, s13
 *   @0x17f2f0 vmov r3, s14
 *   @0x17f2f4 blx r12
 *   @0x17f2f8 b 0x17ef88 <_ZN8Graphics5ClearEjfi11eClearFlags+0xc4>
 *   @0x17f2fc ldr r3, [pc, #0x30]
 *   @0x17f300 ldr r3, [r4, r3]
 *   @0x17f304 ldr r3, [r3]
 *   @0x17f308 b 0x17f008 <_ZN8Graphics5ClearEjfi11eClearFlags+0x144>
 *   @0x17f30c cmnmi pc, #0
 *   @0x17f310 eoreq r2, r7, r4, ror sp
 *   @0x17f314 .word 0xffffe4d0
 *   @0x17f318 .word 0xffffe830
 *   @0x17f31c .word 0xffffc0a8
 *   @0x17f320 ldrsheq r12, [r12], -r8
 *   @0x17f324 .word 0xffffe80c
 *   @0x17f328 .word 0xffffe810
 *   @0x17f32c .word 0xffffe814
 *   @0x17f330 .word 0xffffe834
 *   @0x17f334 .word 0xffffe818
 *   @0x17f338 .word 0xffffe838
 *   @0x17f33c .word 0xffffbad0
 *   @0x17f340 .word 0xffffbacc
 *   @0x17f344 .word 0xffffbad8
 *   @0x17f348 .word 0xffffe828
 *   @0x17f34c .word 0xffffe83c
 *   @0x17f350 .word 0xffffbb04
 *   @0x17f354 .word 0xffffbb08
 *   @0x17f358 .word 0xffffe840
 *   @0x17f35c .word 0xffffbb00
 *
 * ══ §9/56 EndRoom  0x1d1724  size 1044  254 条（0x1d1724..0x1d1b38）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1d1724 0x1d1b38  size 1044  254 条
 * 部分覆盖: 本节 254/261 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d1734→0x5428e8, 0x1d174c→0x54298c, 0x1d1768→0x542954, 0x1d17a8→0x542a14, 0x1d17ac→0x542a0c, 0x1d18b4→0x536d7c, 0x1d1948→0x536f28, 0x1d19d8→0x542a4c
 * 调用序列: CRoom::RemoveMarked()×4 / Perform_Event_All(int, int)×2 / MemoryManager::ReAlloc(void*, unsigned int, char const*, int, bool)×2 / MemoryManager::Free(void const*)×2 / CLayerManager::CleanRoomLayerRuntimeData(CRoom*)×2 / ParticleSystem_RemoveAllFromLayers() / DeleteAllVirtualKeys() / operator new(unsigned int)
 * 字段偏移 top8: 0x4×14 / 0x18×10 / 0x80×4 / 0x8×4 / 0x68×3 / 0x2×3 / 0x360×2 / 0x1c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1724 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d1728 mov r5, r0
 *   @0x1d1748 bne 0x1d1aac <_Z7EndRoomb+0x388>
 *   @0x1d174c ldr r3, [pc, #0x3b4]
 *   @0x1d1750 ldr r3, [r7, r3]
 *   @0x1d1754 ldr r0, [r3]
 *   @0x1d1758 str r3, [sp, #0x18]
 *   @0x1d175c cmp r0, #0
 *   @0x1d1760 beq 0x1d19e8 <_Z7EndRoomb+0x2c4>
 *   @0x1d1764 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv>
 *   @0x1d1768 ldr r2, [pc, #0x39c]
 *   @0x1d176c mov r0, #7
 *   @0x1d1770 mov r1, #5
 *   @0x1d1774 mvn r3, #0
 *   @0x1d1778 ldr r4, [r7, r2]
 *   @0x1d177c ldr r6, [r4]
 *   @0x1d1780 str r3, [r4]
 *   @0x1d1784 bl 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x1d1788 ldr r2, [sp, #0x18]
 *   @0x1d178c ldr r0, [r2]
 *   @0x1d1790 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv>
 *   @0x1d1794 cmp r5, #0
 *   @0x1d1798 bne 0x1d1abc <_Z7EndRoomb+0x398>
 *   @0x1d179c str r6, [r4]
 *   @0x1d17a0 bl 0x1a5cd8 <_Z34ParticleSystem_RemoveAllFromLayersv>
 *   @0x1d17a4 bl 0x18c64c <_Z20DeleteAllVirtualKeysv>
 *   @0x1d17a8 ldr r3, [pc, #0x360]
 *   @0x1d17ac ldr r0, [pc, #0x360]
 *   @0x1d17b0 mov r9, #0
 *   @0x1d17b4 ldr r2, [pc, #0x35c]
 *   @0x1d17b8 mov r1, #40
 *   @0x1d17bc ldr r11, [r7, r3]
 *   @0x1d17c0 mov r3, #76
 *   @0x1d17c4 add r2, pc, r2
 *   @0x1d17c8 str r9, [r11]
 *   @0x1d17cc ldr r6, [r7, r0]
 *   @0x1d17d0 str r9, [sp]
 *   @0x1d17d4 ldr r0, [r6, #0x4]
 *   @0x1d17d8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1d17dc ldr r2, [sp, #0x18]
 *   @0x1d17e0 ldr r3, [r2]
 *   @0x1d17e4 mov r2, #10
 *   @0x1d17e8 str r2, [r6]
 *   @0x1d17ec ldr r4, [r3, #0x80]
 *   @0x1d17f0 cmp r4, r9
 *   @0x1d17f4 str r0, [r6, #0x4]
 *   @0x1d17f8 beq 0x1d1af8 <_Z7EndRoomb+0x3d4>
 *   @0x1d17fc ldr r3, [pc, #0x318]
 *   @0x1d1800 add r3, pc, r3
 *   @0x1d1804 str r3, [sp, #0x1c]
 *   @0x1d1808 b 0x1d1810 <_Z7EndRoomb+0xec>
 *   @0x1d180c mov r4, r5
 *   @0x1d1810 ldrb r3, [r4, #0x68]
 *   @0x1d1814 ldr r5, [r4, #0x178]
 *   @0x1d1818 cmp r3, #0
 *   @0x1d181c bne 0x1d18d0 <_Z7EndRoomb+0x1ac>
 *   @0x1d1820 ldrb r3, [r4, #0x69]
 *   @0x1d1824 cmp r3, #0
 *   @0x1d1828 bne 0x1d18d0 <_Z7EndRoomb+0x1ac>
 *   @0x1d182c ldrb r2, [r4, #0x67]
 *   @0x1d1830 cmp r2, #0
 *   @0x1d1834 beq 0x1d18d0 <_Z7EndRoomb+0x1ac>
 *   @0x1d1838 ldr r8, [r11]
 *   @0x1d183c ldr r2, [r6]
 *   @0x1d1840 add r1, r8, #1
 *   @0x1d1844 str r1, [r11]
 *   @0x1d1848 cmp r1, r2
 *   @0x1d184c bgt 0x1d19f0 <_Z7EndRoomb+0x2cc>
 *   @0x1d1850 ldr r3, [r4, #0x78]
 *   @0x1d1854 mov r0, #432
 *   @0x1d1858 ldr r2, [r4, #0x7c]
 *   @0x1d185c ldr r1, [r4, #0xb4]
 *   @0x1d1860 ldr r10, [r4, #0xb8]
 *   @0x1d1864 str r2, [sp, #0xc]
 *   @0x1d1868 str r1, [sp, #0x14]
 *   @0x1d186c str r3, [sp, #0x10]
 *   @0x1d1870 bl 0x27c524 <_Znwj>
 *   @0x1d1874 ldr r2, [sp, #0xc]
 *   @0x1d1878 ldr r3, [sp, #0x10]
 *   @0x1d187c ldr r1, [sp, #0x14]
 *   @0x1d1880 str r2, [sp]
 *   @0x1d1884 mov r2, r10
 *   @0x1d1888 str r9, [sp, #0x4]
 *   @0x1d188c mov r8, r0
 *   @0x1d1890 bl 0x1994dc <_ZN9CInstanceC2Effiib>
 *   @0x1d1894 ldr r12, [r11]
 *   @0x1d1898 mov r2, #0
 *   @0x1d189c ldr r3, [r6, #0x4]
 *   @0x1d18a0 mov r0, r8
 *   @0x1d18a4 sub r12, r12, #1
 *   @0x1d18a8 mov r1, r4
 *   @0x1d18ac str r8, [r3, r12, lsl #2]
 *   @0x1d18b0 bl 0x1986ec <_ZN9CInstance6AssignEPS_b>
 *   @0x1d18b4 ldr r3, [pc, #0x264]
 *   @0x1d18b8 mov r2, #1
 *   @0x1d18bc strb r2, [r4, #0x68]
 *   @0x1d18c0 ldr r3, [r7, r3]
 *   @0x1d18c4 ldr r2, [r3]
 *   @0x1d18c8 add r2, r2, #1
 *   @0x1d18cc str r2, [r3]
 *   @0x1d18d0 cmp r5, #0
 *   @0x1d18d4 bne 0x1d180c <_Z7EndRoomb+0xe8>
 *   @0x1d18d8 ldr r3, [sp, #0x18]
 *   @0x1d18dc ldr r0, [r3]
 *   @0x1d18e0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv>
 *   @0x1d18e4 ldr r2, [sp, #0x18]
 *   @0x1d18e8 ldr r0, [r2]
 *   @0x1d18ec ldrb r3, [r0, #0x18]
 *   @0x1d18f0 cmp r3, #0
 *   @0x1d18f4 beq 0x1d1a54 <_Z7EndRoomb+0x330>
 *   @0x1d18f8 ldr r4, [r0, #0x80]
 *   @0x1d18fc cmp r4, #0
 *   @0x1d1900 beq 0x1d19d4 <_Z7EndRoomb+0x2b0>
 *   @0x1d1904 ldrb r3, [r4, #0x68]
 *   @0x1d1908 ldr r5, [r4, #0x178]
 *   @0x1d190c cmp r3, #0
 *   @0x1d1910 bne 0x1d19c0 <_Z7EndRoomb+0x29c>
 *   @0x1d1914 ldrb r3, [r4, #0x69]
 *   @0x1d1918 cmp r3, #0
 *   @0x1d191c bne 0x1d19c0 <_Z7EndRoomb+0x29c>
 *   @0x1d1920 ldrb r3, [r4, #0x67]
 *   @0x1d1924 cmp r3, #0
 *   @0x1d1928 bne 0x1d19c0 <_Z7EndRoomb+0x29c>
 *   @0x1d192c ldr r0, [r4, #0x80]
 *   @0x1d1930 mov r1, r4
 *   @0x1d1934 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance>
 *   @0x1d1938 ldr r2, [sp, #0x18]
 *   @0x1d193c mov r1, r4
 *   @0x1d1940 ldr r0, [r2]
 *   @0x1d1944 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance>
 *   @0x1d1948 ldr r3, [pc, #0x1d4]
 *   @0x1d194c ldr r2, [r4, #0x78]
 *   @0x1d1950 ldr r4, [r7, r3]
 *   @0x1d1954 ldr r1, [r4, #0x4]
 *   @0x1d1958 ldr r12, [r4]
 *   @0x1d195c and r1, r2, r1
 *   @0x1d1960 ldr r0, [r12, r1, lsl #3]
 *   @0x1d1964 add lr, r12, r1, lsl #3
 *   @0x1d1968 cmp r0, #0
 *   @0x1d196c bne 0x1d1980 <_Z7EndRoomb+0x25c>
 *   @0x1d1970 b 0x1d19c0 <_Z7EndRoomb+0x29c>
 *   @0x1d1974 ldr r0, [r0, #0x4]
 *   @0x1d1978 cmp r0, #0
 *   @0x1d197c beq 0x1d19c0 <_Z7EndRoomb+0x29c>
 *   @0x1d1980 ldr r3, [r0, #0x8]
 *   @0x1d1984 cmp r2, r3
 *   @0x1d1988 bne 0x1d1974 <_Z7EndRoomb+0x250>
 *   @0x1d198c ldr r3, [r0]
 *   @0x1d1990 ldr r2, [r0, #0x4]
 *   @0x1d1994 cmp r3, #0
 *   @0x1d1998 strne r2, [r3, #0x4]
 *   @0x1d199c ldrne r2, [r0, #0x4]
 *   @0x1d19a0 streq r2, [r12, r1, lsl #3]
 *   @0x1d19a4 cmp r2, #0
 *   @0x1d19a8 streq r3, [lr, #0x4]
 *   @0x1d19ac strne r3, [r2]
 *   @0x1d19b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d19b4 ldr r3, [r4, #0x8]
 *   @0x1d19b8 sub r3, r3, #1
 *   @0x1d19bc str r3, [r4, #0x8]
 *   @0x1d19c0 cmp r5, #0
 *   @0x1d19c4 movne r4, r5
 *   @0x1d19c8 bne 0x1d1904 <_Z7EndRoomb+0x1e0>
 *   @0x1d19cc ldr r3, [sp, #0x18]
 *   @0x1d19d0 ldr r0, [r3]
 *   @0x1d19d4 bl 0x1b8f68 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom>
 *   @0x1d19d8 ldr r3, [pc, #0x148]
 *   @0x1d19dc mov r2, #0
 *   @0x1d19e0 ldr r3, [r7, r3]
 *   @0x1d19e4 str r2, [r3, #0x8]
 *   @0x1d19e8 add sp, sp, #36
 *   @0x1d19ec pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d19f0 adds r8, r8, #6
 *   @0x1d19f4 ldr r0, [r6, #0x4]
 *   @0x1d19f8 bne 0x1d1a30 <_Z7EndRoomb+0x30c>
 *   @0x1d19fc cmp r0, #0
 *   @0x1d1a00 beq 0x1d1a24 <_Z7EndRoomb+0x300>
 *   @0x1d1a04 cmp r2, #0
 *   @0x1d1a08 ble 0x1d1a24 <_Z7EndRoomb+0x300>
 *   @0x1d1a0c mov r3, r8
 *   @0x1d1a10 str r9, [r0, r3, lsl #2]
 *   @0x1d1a14 add r3, r3, #1
 *   @0x1d1a18 cmp r3, r2
 *   @0x1d1a1c ldr r0, [r6, #0x4]
 *   @0x1d1a20 bne 0x1d1a10 <_Z7EndRoomb+0x2ec>
 *   @0x1d1a24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d1a28 str r9, [r6, #0x4]
 *   @0x1d1a2c b 0x1d1a4c <_Z7EndRoomb+0x328>
 *   @0x1d1a30 lsls r1, r8, #2
 *   @0x1d1a34 beq 0x1d1a24 <_Z7EndRoomb+0x300>
 *   @0x1d1a38 str r3, [sp]
 *   @0x1d1a3c mov r3, #76
 *   @0x1d1a40 ldr r2, [sp, #0x1c]
 *   @0x1d1a44 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1d1a48 str r0, [r6, #0x4]
 *   @0x1d1a4c str r8, [r6]
 *   @0x1d1a50 b 0x1d1850 <_Z7EndRoomb+0x12c>
 *   @0x1d1a54 bl 0x1b8f68 <_ZN13CLayerManager25CleanRoomLayerRuntimeDataEP5CRoom>
 *   @0x1d1a58 ldr r2, [pc, #0xcc]
 *   @0x1d1a5c ldr r3, [pc, #0xcc]
 *   @0x1d1a60 ldr r5, [r7, r2]
 *   @0x1d1a64 ldr r4, [r7, r3]
 *   @0x1d1a68 ldr r3, [r5]
 *   @0x1d1a6c ldr r2, [r4]
 *   @0x1d1a70 cmp r3, r2
 *   @0x1d1a74 bge 0x1d1ae4 <_Z7EndRoomb+0x3c0>
 *   @0x1d1a78 ldr r1, [r4, #0x4]
 *   @0x1d1a7c add r2, r1, r3, lsl #2
 *   @0x1d1a80 ldr r6, [r1, r3, lsl #2]
 *   @0x1d1a84 cmp r6, #0
 *   @0x1d1a88 beq 0x1d1aec <_Z7EndRoomb+0x3c8>
 *   @0x1d1a8c mov r0, r6
 *   @0x1d1a90 bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d1a94 mov r0, r6
 *   @0x1d1a98 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d1a9c ldr r2, [r5]
 *   @0x1d1aa0 ldr r3, [r4, #0x4]
 *   @0x1d1aa4 add r2, r3, r2, lsl #2
 *   @0x1d1aa8 b 0x1d1aec <_Z7EndRoomb+0x3c8>
 *   @0x1d1aac ldr r3, [pc, #0x80]
 *   @0x1d1ab0 ldr r0, [r7, r3]
 *   @0x1d1ab4 bl 0x16ecf0 <_ZN14CCameraManager7EndRoomEv>
 *   @0x1d1ab8 b 0x1d174c <_Z7EndRoomb+0x28>
 *   @0x1d1abc ldr r3, [sp, #0x18]
 *   @0x1d1ac0 ldr r0, [r3]
 *   @0x1d1ac4 bl 0x1abad4 <_ZN5CRoom15CleanPersistentEv>
 *   @0x1d1ac8 mov r0, #7
 *   @0x1d1acc mov r1, #3
 *   @0x1d1ad0 bl 0xf33b0 <_Z17Perform_Event_Allii>
 *   @0x1d1ad4 ldr r2, [sp, #0x18]
 *   @0x1d1ad8 ldr r0, [r2]
 *   @0x1d1adc bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv>
 *   @0x1d1ae0 b 0x1d179c <_Z7EndRoomb+0x78>
 *   @0x1d1ae4 ldr r2, [r4, #0x4]
 *   @0x1d1ae8 add r2, r2, r3, lsl #2
 *   @0x1d1aec mov r3, #0
 *   @0x1d1af0 str r3, [r2]
 *   @0x1d1af4 b 0x1d19d8 <_Z7EndRoomb+0x2b4>
 *   @0x1d1af8 mov r0, r3
 *   @0x1d1afc b 0x1d18e0 <_Z7EndRoomb+0x1bc>
 *   @0x1d1b00 eoreq r0, r2, r8, lsl r5
 *   @0x1d1b04 .word 0xffffbcd4
 *   @0x1d1b08 .word 0xffffbcd8
 *   @0x1d1b0c .word 0xffffc154
 *   @0x1d1b10 .word 0xffffeef4
 *   @0x1d1b14 .word 0xffffeef8
 *   @0x1d1b18 ldrsheq pc, [r7], -r4
 *   @0x1d1b1c ldrheq pc, [r7], -r8
 *   @0x1d1b20 .word 0xffffc464
 *   @0x1d1b24 .word 0xffffbff4
 *   @0x1d1b28 .word 0xffffbff8
 *   @0x1d1b2c .word 0xffffd784
 *   @0x1d1b30 .word 0xffffeed8
 *   @0x1d1b34 .word 0xffffc024
 *
 * ══ §10/56 GR_Texture_Draw  0x174ee0  size 808  199 条（0x174ee0..0x175208）｜其中 3 条已由别的卡落锚，本节不再重复
 * @func 0x174ee0 0x175208  size 808  199 条
 * 部分覆盖: 本节 199/202 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int) / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xb6580 / 0xb658c / 0xfe239bbc
 * 字段偏移 top8: 0x50×2 / 0xc×2 / 0x4c×2 / 0x2bc×1 / 0x278×1 / 0x4×1 / 0x2×1 / 0xe×1
 * VFP 指令 114 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x174ee0 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x174ee4 vpush {d8, d9, d10}
 *   @0x174ee8 subs r5, r0, #0
 *   @0x174eec vmov s20, r1
 *   @0x174ef0 vmov s19, r2
 *   @0x174ef4 vmov s16, r3
 *   @0x174ef8 beq 0x17514c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x26c>
 *   @0x174f00 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x174f04 subs r7, r0, #0
 *   @0x174f08 beq 0x17514c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x26c>
 *   @0x174f0c vldr s15, [pc, #736]
 *   @0x174f10 vldr s13, [sp, #84]
 *   @0x174f14 vmul.f32 s15, s13, s15
 *   @0x174f18 vcvt.s32.f32 s15, s15
 *   @0x174f1c vmov r6, s15
 *   @0x174f20 cmp r6, #255
 *   @0x174f24 movgt r6, #-16777216
 *   @0x174f28 bgt 0x174f38 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x58>
 *   @0x174f2c cmp r6, #0
 *   @0x174f30 lslge r6, r6, #24
 *   @0x174f34 movlt r6, #0
 *   @0x174f38 ldr r3, [pc, #0x2bc]
 *   @0x174f3c vldr s14, [sp, #72]
 *   @0x174f40 ldr r1, [sp, #0x50]
 *   @0x174f44 vldr s13, [sp, #68]
 *   @0x174f48 ldr r3, [pc, r3]
 *   @0x174f4c mov r0, #4
 *   @0x174f50 bic r2, r1, #-16777216
 *   @0x174f54 ldrsh r1, [r5, #10]
 *   @0x174f58 ldrb r3, [r3]
 *   @0x174f5c orr r6, r6, r2
 *   @0x174f60 ldrh r2, [r5, #12]
 *   @0x174f64 cmp r3, #0
 *   @0x174f68 ldrsh r3, [r5, #8]
 *   @0x174f6c vmov s17, r1
 *   @0x174f70 bicne r6, r6, #65536
 *   @0x174f74 bicne r6, r6, #1
 *   @0x174f78 ldrsh r1, [r5, #20]
 *   @0x174f7c vmov s18, r3
 *   @0x174f80 ldr r3, [pc, #0x278]
 *   @0x174f84 vcvt.f32.s32 s17, s17
 *   @0x174f88 orrne r9, r6, #65536
 *   @0x174f8c ldr r3, [pc, r3]
 *   @0x174f90 orrne r11, r6, #1
 *   @0x174f94 orrne r10, r9, #1
 *   @0x174f98 moveq r10, r6
 *   @0x174f9c ldr r3, [r3, #0x4]
 *   @0x174fa0 moveq r9, r6
 *   @0x174fa4 moveq r11, r6
 *   @0x174fa8 cmp r2, #0
 *   @0x174fac sxthne r2, r2
 *   @0x174fb0 ldr r8, [r3, r1, lsl #2]
 *   @0x174fb4 moveq r3, #1
 *   @0x174fb8 vcvt.f32.s32 s18, s18
 *   @0x174fbc strheq r3, [r5, #12]
 *   @0x174fc0 vmovne s15, r2
 *   @0x174fc4 ldrh r3, [r5, #14]
 *   @0x174fc8 ldr r1, [r8]
 *   @0x174fcc mov r2, #24
 *   @0x174fd0 vsub.f32 s18, s20, s18
 *   @0x174fd4 vsub.f32 s17, s19, s17
 *   @0x174fd8 vnmul.f32 s18, s13, s18
 *   @0x174fdc vnmul.f32 s17, s14, s17
 *   @0x174fe0 vcvtne.f32.s32 s14, s15
 *   @0x174fe4 vmoveq.f32 s14, #1.000000e+00
 *   @0x174fe8 cmp r3, #0
 *   @0x174fec sxthne r3, r3
 *   @0x174ff0 moveq r3, #1
 *   @0x174ff4 strheq r3, [r5, #14]
 *   @0x174ff8 vmovne s13, r3
 *   @0x174ffc mov r3, #6
 *   @0x175000 vmoveq.f32 s15, #1.000000e+00
 *   @0x175004 vcvtne.f32.s32 s15, s13
 *   @0x175008 vldr s13, [sp, #68]
 *   @0x17500c vmov.f32 s21, s18
 *   @0x175010 vmov.f32 s20, s17
 *   @0x175014 vmla.f32 s21, s13, s14
 *   @0x175018 vldr s14, [sp, #72]
 *   @0x17501c vmla.f32 s20, s14, s15
 *   @0x175020 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x175024 vldr s13, [sp, #76]
 *   @0x175028 vldr s15, [pc, #456]
 *   @0x17502c vabs.f32 s14, s13
 *   @0x175030 vcmpe.f32 s14, s15
 *   @0x175034 vmrs APSR_nzcv, fpscr
 *   @0x175038 mov r4, r0
 *   @0x17503c bpl 0x17515c <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x27c>
 *   @0x175040 vadd.f32 s18, s16, s18
 *   @0x175044 vldr s14, [sp, #64]
 *   @0x175048 vadd.f32 s16, s16, s21
 *   @0x17504c vstr s18, [r0]
 *   @0x175050 vstr s18, [r0, #120]
 *   @0x175054 vstr s18, [r0, #96]
 *   @0x175058 vadd.f32 s17, s14, s17
 *   @0x17505c vstr s16, [r0, #48]
 *   @0x175060 vstr s16, [r0, #72]
 *   @0x175064 vstr s16, [r0, #24]
 *   @0x175068 vadd.f32 s20, s14, s20
 *   @0x17506c vstr s17, [r0, #28]
 *   @0x175070 vstr s17, [r0, #4]
 *   @0x175074 vstr s17, [r0, #124]
 *   @0x175078 vstr s20, [r0, #100]
 *   @0x17507c vstr s20, [r0, #52]
 *   @0x175080 vstr s20, [r0, #76]
 *   @0x175084 ldrsh r2, [r5]
 *   @0x175088 vldr s11, [r8, #8]
 *   @0x17508c ldr r3, [pc, #0x170]
 *   @0x175090 mov r0, r7
 *   @0x175094 str r6, [r4, #0xc]
 *   @0x175098 vmov s13, r2
 *   @0x17509c ldr r3, [pc, r3]
 *   @0x1750a0 str r6, [r4, #0x84]
 *   @0x1750a4 vcvt.f32.s32 s15, s13
 *   @0x1750a8 ldr r3, [r3]
 *   @0x1750ac str r11, [r4, #0x24]
 *   @0x1750b0 str r9, [r4, #0x3c]
 *   @0x1750b8 str r3, [r4, #0x38]
 *   @0x1750bc str r3, [r4, #0x50]
 *   @0x1750c0 str r3, [r4, #0x20]
 *   @0x1750c4 vmul.f32 s15, s15, s11
 *   @0x1750c8 str r3, [r4, #0x8]
 *   @0x1750cc str r3, [r4, #0x80]
 *   @0x1750d0 str r9, [r4, #0x54]
 *   @0x1750d4 str r10, [r4, #0x6c]
 *   @0x1750d8 vstr s15, [r4, #112]
 *   @0x1750dc vstr s15, [r4, #16]
 *   @0x1750e0 vstr s15, [r4, #136]
 *   @0x1750e4 ldrsh r3, [r5, #2]
 *   @0x1750e8 vldr s12, [r8, #12]
 *   @0x1750ec vmov s14, r3
 *   @0x1750f0 vcvt.f32.s32 s13, s14
 *   @0x1750f4 vmul.f32 s13, s13, s12
 *   @0x1750f8 vstr s13, [r4, #44]
 *   @0x1750fc vstr s13, [r4, #20]
 *   @0x175100 vstr s13, [r4, #140]
 *   @0x175104 ldrsh r1, [r5, #4]
 *   @0x175108 add r1, r2, r1
 *   @0x17510c vmov s14, r1
 *   @0x175110 vcvt.f32.s32 s14, s14
 *   @0x175114 vmul.f32 s14, s11, s14
 *   @0x175118 vstr s14, [r4, #64]
 *   @0x17511c vstr s14, [r4, #88]
 *   @0x175120 vstr s14, [r4, #40]
 *   @0x175124 ldrsh r2, [r5, #6]
 *   @0x175128 add r2, r3, r2
 *   @0x17512c vmov s15, r2
 *   @0x175130 vcvt.f32.s32 s15, s15
 *   @0x175134 vmul.f32 s15, s12, s15
 *   @0x175138 vstr s15, [r4, #116]
 *   @0x17513c vstr s15, [r4, #68]
 *   @0x175140 vstr s15, [r4, #92]
 *   @0x175144 vpop {d8, d9, d10}
 *   @0x175148 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17514c vpop {d8, d9, d10}
 *   @0x175150 mov r7, #0
 *   @0x175154 mov r0, r7
 *   @0x175158 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x175160 bl 0xb6580 <sinf@plt>
 *   @0x175164 vmov s19, r0
 *   @0x175168 ldr r0, [sp, #0x4c]
 *   @0x17516c bl 0xb658c <cosf@plt>
 *   @0x175170 vldr s12, [sp, #64]
 *   @0x175174 vldr s13, [sp, #64]
 *   @0x175178 vmls.f32 s12, s18, s19
 *   @0x17517c vmls.f32 s13, s21, s19
 *   @0x175180 vmov s15, r0
 *   @0x175184 vmov.f32 s14, s16
 *   @0x175188 vmul.f32 s10, s17, s15
 *   @0x17518c vmla.f32 s14, s18, s15
 *   @0x175190 vmla.f32 s16, s21, s15
 *   @0x175194 vmul.f32 s15, s20, s15
 *   @0x175198 vmul.f32 s17, s17, s19
 *   @0x17519c vmul.f32 s19, s20, s19
 *   @0x1751a0 vadd.f32 s11, s12, s10
 *   @0x1751a4 vadd.f32 s10, s13, s10
 *   @0x1751a8 vstr s11, [r4, #4]
 *   @0x1751ac vstr s11, [r4, #124]
 *   @0x1751b0 vadd.f32 s13, s15, s13
 *   @0x1751b4 vstr s10, [r4, #28]
 *   @0x1751b8 vadd.f32 s15, s15, s12
 *   @0x1751bc vstr s13, [r4, #52]
 *   @0x1751c0 vstr s13, [r4, #76]
 *   @0x1751c4 vadd.f32 s13, s14, s17
 *   @0x1751c8 vstr s15, [r4, #100]
 *   @0x1751cc vadd.f32 s17, s16, s17
 *   @0x1751d0 vstr s13, [r4]
 *   @0x1751d4 vstr s13, [r4, #120]
 *   @0x1751d8 vadd.f32 s16, s19, s16
 *   @0x1751dc vstr s17, [r4, #24]
 *   @0x1751e0 vadd.f32 s19, s19, s14
 *   @0x1751e4 vstr s16, [r4, #48]
 *   @0x1751e8 vstr s16, [r4, #72]
 *   @0x1751ec vstr s19, [r4, #96]
 *   @0x1751f0 b 0x175084 <_Z15GR_Texture_DrawP12YYTPageEntryfffffffjf+0x1a4>
 *   @0x1751f4 cmnmi pc, #0
 *   @0x1751f8 blo 0xfe239bbc <b2_toiTime+0xfffffffffdae0718>
 *   @0x1751fc eoreq r8, r7, r4, lsl #30
 *   @0x175200 mlaeq r7, r0, r9, r8
 *   @0x175204 eoreq r8, r7, r4, lsl #17
 *
 * ══ §11/56 Graphics::SetTexture  0x182a28  size 808  200 条（0x182a28..0x182d50）｜其中 2 条已由别的卡落锚，本节不再重复
 * @func 0x182a28 0x182d50  size 808  200 条
 * 部分覆盖: 本节 200/202 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x182a38→0x3f26dc, 0x182a50→0x4a2f28, 0x182a64→0x4a22b1, 0x182a90→0x4859c8, 0x182ab4→0x479c74, 0x182ac8→0x4a2f24, 0x182adc→0x4a2100, 0x182ae8→0x479bbc
 * 调用序列: _CreateTextureIfInvalid(Texture*, bool, eMipEnable)×3 / isTextureBoundAsRenderTarget(Texture*)×2 / RenderStateManager::GetSamplerState(int, eSamplerState)×2 / _SetCurrentTextureSettings()
 * 字段偏移 top8: 0x14×6 / 0x2×2 / 0x150×2 / 0x120×2 / 0x2d4×1 / 0x2d0×1 / 0x2bc×1 / 0x2ac×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x182a28 push {r4, r5, r6, r7, r8, lr}
 *   @0x182a2c mov r7, r0
 *   @0x182a30 ldr r4, [pc, #0x2d4]
 *   @0x182a34 mov r5, r1
 *   @0x182a38 ldr r3, [pc, #0x2d0]
 *   @0x182a3c add r4, pc, r4
 *   @0x182a40 ldr r6, [r4, r3]
 *   @0x182a44 ldr r3, [r6]
 *   @0x182a48 cmp r3, #0
 *   @0x182a4c bne 0x182b18 <_ZN8Graphics10SetTextureEiPv+0xf0>
 *   @0x182a50 ldr r3, [pc, #0x2bc]
 *   @0x182a54 ldr r8, [r4, r3]
 *   @0x182a58 ldr r3, [r8]
 *   @0x182a5c cmp r3, r1
 *   @0x182a60 beq 0x182c38 <_ZN8Graphics10SetTextureEiPv+0x210>
 *   @0x182a64 ldr r3, [pc, #0x2ac]
 *   @0x182a68 ldr r3, [r4, r3]
 *   @0x182a6c ldrb r3, [r3]
 *   @0x182a70 cmp r3, #0
 *   @0x182a74 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x182a78 cmp r1, #0
 *   @0x182a7c beq 0x182c74 <_ZN8Graphics10SetTextureEiPv+0x24c>
 *   @0x182a80 mov r0, r5
 *   @0x182a84 bl 0x180884 <_Z28isTextureBoundAsRenderTargetP7Texture>
 *   @0x182a88 cmp r0, #0
 *   @0x182a8c bne 0x182c14 <_ZN8Graphics10SetTextureEiPv+0x1ec>
 *   @0x182a90 ldr r3, [pc, #0x284]
 *   @0x182a94 mov r1, r7
 *   @0x182a98 mov r2, #9
 *   @0x182a9c ldr r0, [r4, r3]
 *   @0x182aa0 bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x182aa4 mov r1, #1
 *   @0x182aa8 mov r2, r0
 *   @0x182aac mov r0, r5
 *   @0x182ab0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x182ab4 ldr r3, [pc, #0x264]
 *   @0x182ab8 movw r0, #0xde1
 *   @0x182abc ldr r3, [r4, r3]
 *   @0x182ac0 ldr r3, [r3]
 *   @0x182ac4 blx r3
 *   @0x182ac8 ldr r3, [pc, #0x254]
 *   @0x182acc ldr r3, [r4, r3]
 *   @0x182ad0 ldr r2, [r3]
 *   @0x182ad4 cmp r5, r2
 *   @0x182ad8 beq 0x182b14 <_ZN8Graphics10SetTextureEiPv+0xec>
 *   @0x182adc ldr r1, [pc, #0x244]
 *   @0x182ae0 movw r0, #0xde1
 *   @0x182ae4 str r5, [r3]
 *   @0x182ae8 ldr r2, [pc, #0x23c]
 *   @0x182aec ldr r3, [r4, r1]
 *   @0x182af0 ldr r1, [r5, #0x14]
 *   @0x182af4 ldr r12, [r3]
 *   @0x182af8 add r12, r12, #1
 *   @0x182afc str r12, [r3]
 *   @0x182b00 ldr r3, [r4, r2]
 *   @0x182b04 ldr r3, [r3]
 *   @0x182b08 blx r3
 *   @0x182b0c str r5, [r8]
 *   @0x182b10 bl 0x180b28 <_Z26_SetCurrentTextureSettingsv>
 *   @0x182b14 ldr r3, [r6]
 *   @0x182b18 cmp r3, #1
 *   @0x182b1c popne {r4, r5, r6, r7, r8, pc}
 *   @0x182b20 cmp r7, #7
 *   @0x182b24 pophi {r4, r5, r6, r7, r8, pc}
 *   @0x182b28 ldr r3, [pc, #0x200]
 *   @0x182b2c ldr r3, [r4, r3]
 *   @0x182b30 ldrb r3, [r3]
 *   @0x182b34 cmp r3, #0
 *   @0x182b38 bne 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128>
 *   @0x182b3c ldr r3, [pc, #0x1d0]
 *   @0x182b40 ldr r3, [r4, r3]
 *   @0x182b44 ldr r3, [r3, r7, lsl #2]
 *   @0x182b48 cmp r3, r5
 *   @0x182b4c beq 0x182cd0 <_ZN8Graphics10SetTextureEiPv+0x2a8>
 *   @0x182b50 ldr r3, [pc, #0x1c0]
 *   @0x182b54 ldr r3, [r4, r3]
 *   @0x182b58 ldrb r3, [r3]
 *   @0x182b5c cmp r3, #0
 *   @0x182b60 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x182b64 ldr r3, [pc, #0x1c8]
 *   @0x182b68 ldr r6, [r4, r3]
 *   @0x182b6c ldr r3, [r6]
 *   @0x182b70 cmp r3, r7
 *   @0x182b74 beq 0x182b94 <_ZN8Graphics10SetTextureEiPv+0x16c>
 *   @0x182b78 ldr r3, [pc, #0x1b8]
 *   @0x182b80 str r7, [r6]
 *   @0x182b88 ldr r3, [r4, r3]
 *   @0x182b8c ldr r3, [r3]
 *   @0x182b90 blx r3
 *   @0x182b94 cmp r5, #0
 *   @0x182b98 beq 0x182c94 <_ZN8Graphics10SetTextureEiPv+0x26c>
 *   @0x182b9c mov r0, r5
 *   @0x182ba0 bl 0x180884 <_Z28isTextureBoundAsRenderTargetP7Texture>
 *   @0x182ba4 cmp r0, #0
 *   @0x182ba8 bne 0x182c64 <_ZN8Graphics10SetTextureEiPv+0x23c>
 *   @0x182bac ldr r3, [pc, #0x168]
 *   @0x182bb0 mov r1, r7
 *   @0x182bb4 mov r2, #9
 *   @0x182bb8 ldr r0, [r4, r3]
 *   @0x182bbc bl 0x167fa0 <_ZN18RenderStateManager15GetSamplerStateEi13eSamplerState>
 *   @0x182bc0 mov r1, #1
 *   @0x182bc4 mov r2, r0
 *   @0x182bc8 mov r0, r5
 *   @0x182bcc bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x182bd0 ldr r3, [pc, #0x150]
 *   @0x182bd4 ldr r2, [pc, #0x150]
 *   @0x182bd8 movw r0, #0xde1
 *   @0x182bdc ldr r1, [r5, #0x14]
 *   @0x182be0 ldr r3, [r4, r3]
 *   @0x182be4 ldr r12, [r3]
 *   @0x182be8 add r12, r12, #1
 *   @0x182bec str r12, [r3]
 *   @0x182bf0 ldr r3, [r4, r2]
 *   @0x182bf4 ldr r3, [r3]
 *   @0x182bf8 blx r3
 *   @0x182bfc ldr r3, [pc, #0x110]
 *   @0x182c00 ldr r2, [r6]
 *   @0x182c04 ldr r3, [r4, r3]
 *   @0x182c08 str r5, [r3, r2, lsl #2]
 *   @0x182c0c pop {r4, r5, r6, r7, r8, lr}
 *   @0x182c10 b 0x180b28 <_Z26_SetCurrentTextureSettingsv>
 *   @0x182c14 ldr r1, [pc, #0x120]
 *   @0x182c18 ldr r3, [pc, #0x120]
 *   @0x182c1c add r1, pc, r1
 *   @0x182c20 ldr r3, [r4, r3]
 *   @0x182c24 ldr r0, [r3]
 *   @0x182c28 ldr r3, [r0]
 *   @0x182c2c ldr r3, [r3, #0xc]
 *   @0x182c30 blx r3
 *   @0x182c34 pop {r4, r5, r6, r7, r8, pc}
 *   @0x182c38 cmp r1, #0
 *   @0x182c3c popeq {r4, r5, r6, r7, r8, pc}
 *   @0x182c40 ldr r3, [r1, #0x14]
 *   @0x182c44 cmn r3, #1
 *   @0x182c48 popne {r4, r5, r6, r7, r8, pc}
 *   @0x182c4c ldr r3, [pc, #0xc4]
 *   @0x182c50 ldr r3, [r4, r3]
 *   @0x182c54 ldrb r3, [r3]
 *   @0x182c58 cmp r3, #0
 *   @0x182c5c bne 0x182a80 <_ZN8Graphics10SetTextureEiPv+0x58>
 *   @0x182c60 pop {r4, r5, r6, r7, r8, pc}
 *   @0x182c64 ldr r1, [pc, #0xd8]
 *   @0x182c68 ldr r3, [pc, #0xd0]
 *   @0x182c6c add r1, pc, r1
 *   @0x182c70 b 0x182c20 <_ZN8Graphics10SetTextureEiPv+0x1f8>
 *   @0x182c74 ldr r3, [pc, #0xcc]
 *   @0x182c78 movw r0, #0xde1
 *   @0x182c7c ldr r3, [r4, r3]
 *   @0x182c80 ldr r3, [r3]
 *   @0x182c84 blx r3
 *   @0x182c88 str r5, [r8]
 *   @0x182c8c ldr r3, [r6]
 *   @0x182c90 b 0x182b18 <_ZN8Graphics10SetTextureEiPv+0xf0>
 *   @0x182c94 ldr r3, [pc, #0xb0]
 *   @0x182c98 ldr r7, [r4, r3]
 *   @0x182c9c ldr r0, [r7]
 *   @0x182ca0 cmp r0, #0
 *   @0x182ca4 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x182ca8 mov r1, r5
 *   @0x182cac mvn r2, #0
 *   @0x182cb0 bl 0x182500 <_Z23_CreateTextureIfInvalidP7Textureb10eMipEnable>
 *   @0x182cb4 ldr r3, [pc, #0x6c]
 *   @0x182cb8 ldr r1, [r7]
 *   @0x182cbc movw r0, #0xde1
 *   @0x182cc0 ldr r2, [pc, #0x64]
 *   @0x182cc4 ldr r3, [r4, r3]
 *   @0x182cc8 ldr r1, [r1, #0x14]
 *   @0x182ccc b 0x182be4 <_ZN8Graphics10SetTextureEiPv+0x1bc>
 *   @0x182cd0 cmp r5, #0
 *   @0x182cd4 beq 0x182ce8 <_ZN8Graphics10SetTextureEiPv+0x2c0>
 *   @0x182cd8 ldr r3, [r5, #0x14]
 *   @0x182cdc cmn r3, #1
 *   @0x182ce0 popne {r4, r5, r6, r7, r8, pc}
 *   @0x182ce4 b 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128>
 *   @0x182ce8 ldr r3, [pc, #0x5c]
 *   @0x182cec ldr r3, [r4, r3]
 *   @0x182cf0 ldr r3, [r3]
 *   @0x182cf4 cmp r3, #0
 *   @0x182cf8 beq 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128>
 *   @0x182cfc ldr r3, [r3, #0x14]
 *   @0x182d00 cmn r3, #1
 *   @0x182d04 popne {r4, r5, r6, r7, r8, pc}
 *   @0x182d08 b 0x182b50 <_ZN8Graphics10SetTextureEiPv+0x128>
 *   @0x182d0c eoreq pc, r6, r4, lsl r2
 *   @0x182d10 .word 0xffffe7b8
 *   @0x182d14 .word 0xffffe8e8
 *   @0x182d18 .word 0xffffe4d0
 *   @0x182d1c .word 0xffffc0a8
 *   @0x182d20 .word 0xffffbad8
 *   @0x182d24 .word 0xffffe8f4
 *   @0x182d28 .word 0xffffe740
 *   @0x182d2c .word 0xffffbb20
 *   @0x182d30 .word 0xffffe904
 *   @0x182d34 .word 0xffffe808
 *   @0x182d38 .word 0xffffbbf0
 *   @0x182d3c andseq r8, r12, r12, lsl #30
 *   @0x182d40 .word 0xffffbac4
 *   @0x182d44 ldrheq r8, [r12], -r12
 *   @0x182d48 .word 0xffffbad0
 *   @0x182d4c .word 0xffffe8fc
 *
 * ══ §12/56 CProfiler::Init  0x2a00b0  size 692  166 条（0x2a00b0..0x2a0364）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x2a00b0 0x2a0364  size 692  166 条
 * 部分覆盖: 本节 166/173 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2a00d4→0x5428e8, 0x2a017c→0x47a148, 0x2a0180→0x47a16c, 0x2a01c8→0x757e7c
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×3 / operator new(unsigned int)×2 / YYStrDup(char const*)×2 / ExtractFilePath(char const*) / LoadSave::_GetSaveFileName(char*, int, char const*) / 0xb65d4
 * 字段偏移 top8: 0x18×4 / 0x8×4 / 0x15×3 / 0x14×3 / 0x11×3 / 0x10×2 / 0x12×2 / 0x13×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a00b0 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2a00b4 mov r9, r1
 *   @0x2a00b8 ldr r10, [pc, #0x280]
 *   @0x2a00bc adds r1, r1, #0
 *   @0x2a00c0 ldr r3, [pc, #0x27c]
 *   @0x2a00c4 mov r7, r0
 *   @0x2a00c8 add r10, pc, r10
 *   @0x2a00e8 sub sp, sp, #8
 *   @0x2a00ec mov r3, #0
 *   @0x2a00f0 ldr r1, [r8]
 *   @0x2a00f4 mov r6, #0
 *   @0x2a00f8 strb r12, [r7, #0x14]
 *   @0x2a00fc mov r4, #0
 *   @0x2a0100 strb lr, [r7, #0x10]
 *   @0x2a0104 mov r5, #0
 *   @0x2a0108 strb r3, [r7, #0x11]
 *   @0x2a010c strb r3, [r7, #0x12]
 *   @0x2a0110 strb r3, [r7, #0x13]
 *   @0x2a0114 str r1, [sp, #0x404]
 *   @0x2a0118 ldr r1, [r10, r0]
 *   @0x2a011c mov r0, #12
 *   @0x2a0120 str r2, [r7, #0x2c]
 *   @0x2a0124 strd r4, r5, [r7, #32]
 *   @0x2a0128 ldrb r1, [r1]
 *   @0x2a012c strd r4, r5, [r7, #72]
 *   @0x2a0130 cmp r1, r3
 *   @0x2a0134 strd r4, r5, [r7, #64]
 *   @0x2a0138 strbne r3, [r7, #0x14]
 *   @0x2a013c strd r4, r5, [r7, #88]
 *   @0x2a0140 strd r4, r5, [r7, #96]
 *   @0x2a0144 str r6, [r7, #0x28]
 *   @0x2a0148 str r6, [r7, #0x18]
 *   @0x2a014c str r6, [r7, #0x30]
 *   @0x2a0150 bl 0x27c524 <_Znwj>
 *   @0x2a0154 ldr r1, [pc, #0x1f0]
 *   @0x2a0158 mov r3, #10
 *   @0x2a015c mov r2, #55
 *   @0x2a0160 add r1, pc, r1
 *   @0x2a0164 mov r4, r0
 *   @0x2a0168 str r6, [r0, #0x4]
 *   @0x2a016c str r3, [r4, #0x8]
 *   @0x2a0170 mov r0, #240
 *   @0x2a0174 mov r3, #1
 *   @0x2a0178 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a017c ldr r2, [pc, #0x1cc]
 *   @0x2a0180 ldr r3, [pc, #0x1cc]
 *   @0x2a0184 str r0, [r4]
 *   @0x2a0188 mov r0, #12
 *   @0x2a018c str r4, [r7, #0x8]
 *   @0x2a0190 ldr r2, [r10, r2]
 *   @0x2a0194 ldr r2, [r2]
 *   @0x2a0198 str r2, [r7, #0x34]
 *   @0x2a019c ldr r3, [r10, r3]
 *   @0x2a01a0 ldr r3, [r3]
 *   @0x2a01a4 str r3, [r7, #0x38]
 *   @0x2a01a8 bl 0x27c524 <_Znwj>
 *   @0x2a01ac ldr r1, [pc, #0x1a4]
 *   @0x2a01b0 mov r2, #80
 *   @0x2a01b4 mov r3, #1
 *   @0x2a01b8 add r1, pc, r1
 *   @0x2a01bc mov r4, r0
 *   @0x2a01c0 mov r0, #5120
 *   @0x2a01c4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a01c8 ldr r1, [pc, #0x18c]
 *   @0x2a01cc mov r3, #128
 *   @0x2a01d0 str r3, [r4]
 *   @0x2a01d4 mvn r3, #0
 *   @0x2a01d8 mov r12, r0
 *   @0x2a01dc str r0, [r4, #0x8]
 *   @0x2a01e0 ldrb r2, [r12, #0x3]
 *   @0x2a01e4 mov r0, #1
 *   @0x2a01e8 str r4, [r7, #0xc]
 *   @0x2a01ec ldr r1, [r10, r1]
 *   @0x2a01f0 and r2, r2, #240
 *   @0x2a01f4 str r0, [r4, #0x4]
 *   @0x2a01f8 bfi r2, r6, #4, #4
 *   @0x2a01fc strb r6, [r12, #0x1]
 *   @0x2a0200 strb r6, [r1]
 *   @0x2a0204 strb r2, [r12, #0x3]
 *   @0x2a0208 strb r6, [r12, #0x2]
 *   @0x2a020c strb r6, [r12]
 *   @0x2a0210 strb r6, [r12, #0x8]
 *   @0x2a0214 strb r6, [r12, #0x9]
 *   @0x2a0218 strb r6, [r12, #0xa]
 *   @0x2a021c strb r6, [r12, #0xb]
 *   @0x2a0220 strb r6, [r12, #0xc]
 *   @0x2a0224 strb r6, [r12, #0xd]
 *   @0x2a0228 strb r6, [r12, #0xe]
 *   @0x2a022c strb r6, [r12, #0xf]
 *   @0x2a0230 strb r6, [r12, #0x10]
 *   @0x2a0234 strb r6, [r12, #0x11]
 *   @0x2a0238 strb r6, [r12, #0x12]
 *   @0x2a023c strb r6, [r12, #0x13]
 *   @0x2a0240 strb r6, [r12, #0x14]
 *   @0x2a0244 strb r6, [r12, #0x15]
 *   @0x2a0248 strb r6, [r12, #0x16]
 *   @0x2a024c strb r6, [r12, #0x17]
 *   @0x2a0250 strb r3, [r12, #0x18]
 *   @0x2a0254 strb r3, [r12, #0x19]
 *   @0x2a0258 strb r3, [r12, #0x1a]
 *   @0x2a025c strb r3, [r12, #0x1b]
 *   @0x2a0260 strb r3, [r12, #0x1c]
 *   @0x2a0264 strb r3, [r12, #0x1d]
 *   @0x2a0268 strb r3, [r12, #0x1e]
 *   @0x2a026c ldrb r2, [r7, #0x14]
 *   @0x2a0270 strb r3, [r12, #0x1f]
 *   @0x2a0274 cmp r2, r6
 *   @0x2a0278 strb r6, [r12, #0x20]
 *   @0x2a027c strb r6, [r12, #0x21]
 *   @0x2a0280 strb r6, [r12, #0x22]
 *   @0x2a0284 strb r6, [r12, #0x23]
 *   @0x2a0288 str r6, [r7, #0x70]
 *   @0x2a028c streq r2, [r7, #0x74]
 *   @0x2a0290 streq r2, [r7, #0x78]
 *   @0x2a0294 bne 0x2a02ec <_ZN9CProfiler4InitEPKci+0x23c>
 *   @0x2a0298 ldrb r3, [r7, #0x15]
 *   @0x2a029c cmp r3, #0
 *   @0x2a02a0 bne 0x2a02c0 <_ZN9CProfiler4InitEPKci+0x210>
 *   @0x2a02a4 ldr r2, [sp, #0x404]
 *   @0x2a02a8 ldr r3, [r8]
 *   @0x2a02ac cmp r2, r3
 *   @0x2a02b0 bne 0x2a033c <_ZN9CProfiler4InitEPKci+0x28c>
 *   @0x2a02b4 add sp, sp, #1024
 *   @0x2a02b8 add sp, sp, #8
 *   @0x2a02bc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2a02c0 mov r3, #1
 *   @0x2a02c4 mov r0, r9
 *   @0x2a02c8 strb r3, [r7, #0x11]
 *   @0x2a02cc bl 0x214f5c <_Z15ExtractFilePathPKc>
 *   @0x2a02d0 ldrb r3, [r0]
 *   @0x2a02d4 cmp r3, #0
 *   @0x2a02d8 beq 0x2a0318 <_ZN9CProfiler4InitEPKci+0x268>
 *   @0x2a02dc mov r0, r9
 *   @0x2a02e0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a02e4 str r0, [r7, #0x18]
 *   @0x2a02e8 b 0x2a02a4 <_ZN9CProfiler4InitEPKci+0x1f4>
 *   @0x2a02ec ldr r1, [pc, #0x6c]
 *   @0x2a02f0 mov r2, #32768
 *   @0x2a02f4 str r6, [r7, #0x7c]
 *   @0x2a02f8 mov r3, r6
 *   @0x2a02fc str r2, [r7, #0x78]
 *   @0x2a0300 mov r0, #131072
 *   @0x2a0304 mov r2, #76
 *   @0x2a0308 add r1, pc, r1
 *   @0x2a030c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x2a0310 str r0, [r7, #0x74]
 *   @0x2a0314 b 0x2a0298 <_ZN9CProfiler4InitEPKci+0x1e8>
 *   @0x2a0318 add r4, sp, #4
 *   @0x2a031c mov r2, r9
 *   @0x2a0320 mov r1, #1024
 *   @0x2a0324 mov r0, r4
 *   @0x2a0328 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc>
 *   @0x2a032c mov r0, r4
 *   @0x2a0330 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x2a0334 str r0, [r7, #0x18]
 *   @0x2a0338 b 0x2a02a4 <_ZN9CProfiler4InitEPKci+0x1f4>
 *   @0x2a033c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2a0340 andseq r1, r5, r8, lsl #23
 *   @0x2a0344 .word 0xffffbd00
 *   @0x2a0348 .word 0xffffbcd4
 *   @0x2a034c andeq r5, r11, r4, lsr #1
 *   @0x2a0350 .word 0xffffbec4
 *   @0x2a0354 .word 0xffffbed8
 *   @0x2a0358 strheq r9, [r11], -r12
 *   @0x2a035c .word 0xffffbf18
 *   @0x2a0360 muleq r11, r12, r9
 *
 * ══ §13/56 YYGML_surface_set_target_ext  0x171574  size 660  158 条（0x171574..0x171808）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x171574 0x17181c  size 680  163 条
 * 部分覆盖: 本节 163/170 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 162/169 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 161/168 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 160/167 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 159/166 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x171594→0x4a22b1, 0x1715dc→0x48ffac, 0x1715fc→0x3f23b0, 0x171604→0x48f7ac, 0x17160c→0x3f23ac, 0x171634→0x3f23a8, 0x171648→0x3f23a4, 0x17165c→0x3f23a0
 * 调用序列: Graphics::Flush() / GR_Surface_Get(int) / GR_Texture_Get_Surface(int) / Graphics::SaveRenderTarget() / Graphics::SetRenderTarget(int, void*) / GR_D3D_Set_View_Port(int, int, int, int) / UpdateDefaultCamera(float, float, float, float, float) / DirtyRoomExtents()
 * 字段偏移 top8: 0x2×11 / 0xc×5 / 0x4×3 / 0x8×2 / 0x240×1 / 0x22c×1 / 0x1e8×1 / 0x1cc×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171574 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x171578 cmp r0, #3
 *   @0x17157c ldr r4, [pc, #0x240]
 *   @0x171580 sub sp, sp, #20
 *   @0x171584 mov r8, r0
 *   @0x171588 mov r5, r1
 *   @0x17158c add r4, pc, r4
 *   @0x171590 bhi 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34>
 *   @0x171594 ldr r3, [pc, #0x22c]
 *   @0x171598 ldr r3, [r4, r3]
 *   @0x17159c ldrb r3, [r3]
 *   @0x1715a0 cmp r3, #0
 *   @0x1715a4 bne 0x1715b8 <_Z28YYGML_surface_set_target_extii+0x44>
 *   @0x1715a8 mov r9, #0
 *   @0x1715ac mov r0, r9
 *   @0x1715b0 add sp, sp, #20
 *   @0x1715b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1715b8 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x1715bc mov r0, r5
 *   @0x1715c0 bl 0x170f48 <_Z14GR_Surface_Geti>
 *   @0x1715c4 subs r6, r0, #0
 *   @0x1715c8 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34>
 *   @0x1715cc ldr r0, [r6, #0x4]
 *   @0x1715d0 bl 0x17435c <_Z22GR_Texture_Get_Surfacei>
 *   @0x1715d4 subs r7, r0, #0
 *   @0x1715d8 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34>
 *   @0x1715dc ldr r3, [pc, #0x1e8]
 *   @0x1715e0 ldr r3, [r4, r3]
 *   @0x1715e4 str r3, [sp, #0xc]
 *   @0x1715e8 ldr r3, [r3]
 *   @0x1715ec cmp r3, #496
 *   @0x1715f0 bgt 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34>
 *   @0x1715f4 cmp r8, #0
 *   @0x1715f8 bne 0x17179c <_Z28YYGML_surface_set_target_extii+0x228>
 *   @0x1715fc ldr r8, [pc, #0x1cc]
 *   @0x171600 add r0, r3, #1
 *   @0x171604 ldr r2, [pc, #0x1c8]
 *   @0x171608 add lr, r3, #2
 *   @0x17160c ldr r1, [pc, #0x1c4]
 *   @0x171610 add r12, r3, #3
 *   @0x171614 ldr r8, [r4, r8]
 *   @0x171618 add r9, r3, #4
 *   @0x17161c ldr r2, [r4, r2]
 *   @0x171620 add r11, r3, #5
 *   @0x171624 add r10, r3, #6
 *   @0x171628 ldr r8, [r8]
 *   @0x17162c str r8, [r2, r3, lsl #2]
 *   @0x171630 ldr r8, [r4, r1]
 *   @0x171634 ldr r1, [pc, #0x1a0]
 *   @0x171638 ldr r8, [r8]
 *   @0x17163c str r8, [r2, r0, lsl #2]
 *   @0x171640 add r8, r3, #7
 *   @0x171644 ldr r0, [r4, r1]
 *   @0x171648 ldr r1, [pc, #0x190]
 *   @0x17164c ldr r0, [r0]
 *   @0x171650 str r0, [r2, lr, lsl #2]
 *   @0x171654 add r0, r3, #8
 *   @0x171658 ldr lr, [r4, r1]
 *   @0x17165c ldr r1, [pc, #0x180]
 *   @0x171660 ldr lr, [lr]
 *   @0x171664 str lr, [r2, r12, lsl #2]
 *   @0x171668 add lr, r3, #10
 *   @0x17166c ldr r1, [r4, r1]
 *   @0x171670 ldr r12, [pc, #0x170]
 *   @0x171674 ldr r1, [r1]
 *   @0x171678 str r1, [r2, r9, lsl #2]
 *   @0x17167c add r1, r3, #9
 *   @0x171680 ldr r12, [r4, r12]
 *   @0x171684 ldr r9, [pc, #0x160]
 *   @0x171688 ldr r12, [r12]
 *   @0x17168c str r12, [r2, r11, lsl #2]
 *   @0x171690 add r12, r2, r1, lsl #2
 *   @0x171694 ldr r11, [r4, r9]
 *   @0x171698 ldr r9, [pc, #0x150]
 *   @0x17169c ldr r11, [r11]
 *   @0x1716a0 str r11, [r2, r10, lsl #2]
 *   @0x1716a4 ldr r9, [r4, r9]
 *   @0x1716a8 ldr r10, [pc, #0x144]
 *   @0x1716ac ldr r11, [r9]
 *   @0x1716b0 ldr r9, [pc, #0x140]
 *   @0x1716b4 str r11, [r2, r8, lsl #2]
 *   @0x1716b8 ldr r8, [r4, r10]
 *   @0x1716bc ldr r10, [sp, #0xc]
 *   @0x1716c0 ldr r8, [r8]
 *   @0x1716c4 str lr, [r10]
 *   @0x1716c8 ldr lr, [pc, #0x12c]
 *   @0x1716cc str r8, [r2, r0, lsl #2]
 *   @0x1716d0 ldr r0, [r4, r9]
 *   @0x1716d4 ldrb r0, [r0]
 *   @0x1716d8 str r0, [r2, r1, lsl #2]
 *   @0x1716dc ldr r8, [r4, lr]
 *   @0x1716e0 sub r2, r8, #4
 *   @0x1716e4 add r0, r8, #12
 *   @0x1716e8 ldr r1, [r2, #0x4]!
 *   @0x1716ec cmp r2, r0
 *   @0x1716f0 str r1, [r12, #0x4]!
 *   @0x1716f4 bne 0x1716e8 <_Z28YYGML_surface_set_target_extii+0x174>
 *   @0x1716f8 ldr r2, [sp, #0xc]
 *   @0x1716fc add r3, r3, #14
 *   @0x171700 str r3, [r2]
 *   @0x171704 bl 0x1833cc <_ZN8Graphics16SaveRenderTargetEv>
 *   @0x171708 subs r9, r0, #0
 *   @0x17170c beq 0x171788 <_Z28YYGML_surface_set_target_extii+0x214>
 *   @0x171710 mov r1, r7
 *   @0x171714 mov r0, #0
 *   @0x171718 bl 0x183590 <_ZN8Graphics15SetRenderTargetEiPv>
 *   @0x17171c subs r9, r0, #0
 *   @0x171720 beq 0x1715a8 <_Z28YYGML_surface_set_target_extii+0x34>
 *   @0x171724 mov r0, #0
 *   @0x171728 ldr r2, [r6, #0x8]
 *   @0x17172c mov r1, r0
 *   @0x171730 ldr r3, [r6, #0xc]
 *   @0x171750 vcvt.f32.s32 s15, s15
 *   @0x171754 ldrb r3, [r3]
 *   @0x171758 cmp r3, #0
 *   @0x17175c ldr r3, [r6, #0xc]
 *   @0x171760 str r1, [sp]
 *   @0x171764 vmov r2, s15
 *   @0x171768 vmov s15, r3
 *   @0x17176c vcvt.f32.s32 s15, s15
 *   @0x171770 vmov r3, s15
 *   @0x171774 beq 0x1717bc <_Z28YYGML_surface_set_target_extii+0x248>
 *   @0x171778 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff>
 *   @0x17177c str r5, [r8]
 *   @0x171780 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x171784 b 0x1715ac <_Z28YYGML_surface_set_target_extii+0x38>
 *   @0x171788 ldr r0, [pc, #0x74]
 *   @0x17178c mov r1, r9
 *   @0x171790 add r0, pc, r0
 *   @0x171794 bl 0xecd7c <_Z10Error_ShowPKcb>
 *   @0x171798 b 0x1715ac <_Z28YYGML_surface_set_target_extii+0x38>
 *   @0x17179c ldr r3, [pc, #0x58]
 *   @0x1717a0 mov r1, r7
 *   @0x1717a4 mov r0, r8
 *   @0x1717a8 ldr r3, [r4, r3]
 *   @0x1717ac str r5, [r3, r8, lsl #2]
 *   @0x1717b0 add sp, sp, #20
 *   @0x1717b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1717b8 b 0x183590 <_ZN8Graphics15SetRenderTargetEiPv>
 *   @0x1717bc bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff>
 *   @0x1717c0 b 0x17177c <_Z28YYGML_surface_set_target_extii+0x208>
 *   @0x1717c4 eoreq r0, r8, r4, asr #13
 *   @0x1717c8 .word 0xffffe4d0
 *   @0x1717cc .word 0xffffe614
 *   @0x1717d0 .word 0xffffe4ec
 *   @0x1717d4 .word 0xffffe618
 *   @0x1717d8 .word 0xffffe4f0
 *   @0x1717dc .word 0xffffe4f4
 *   @0x1717e0 .word 0xffffe4f8
 *   @0x1717e4 .word 0xffffe504
 *   @0x1717e8 .word 0xffffe508
 *   @0x1717ec .word 0xffffe50c
 *   @0x1717f0 .word 0xffffe510
 *   @0x1717f4 .word 0xffffe514
 *   @0x1717f8 .word 0xffffe490
 *   @0x1717fc .word 0xffffe51c
 *   @0x171800 .word 0xffffbcd4
 *   @0x171804 andseq r9, sp, r8, asr #24
 *
 * ══ §14/56 YYGML_surface_reset_target  0x171808  size 648  155 条（0x171808..0x171a90）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x171808 0x171a90  size 648  155 条
 * 部分覆盖: 本节 155/162 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x171818→0x4a22b1, 0x171858→0x48ffac, 0x17186c→0x3f23dc, 0x171870→0x48f7ac, 0x171898→0x7530c9, 0x1718a4→0x3f23ec, 0x1718b8→0x3f23f0, 0x1718c4→0x3f23f4
 * 调用序列: Graphics::Flush() / Graphics::RestoreRenderTarget() / GR_D3D_Get_Region(int&, int&) / GR_D3D_Set_View_Port(int, int, int, int) / UpdateDefaultCamera(float, float, float, float, float) / DirtyRoomExtents() / GR_D3D_Set_View_Area(float, float, float, float, float) / SetGuiView()
 * 字段偏移 top8: 0x2×5 / 0xc×5 / 0x10×4 / 0x14×3 / 0x1e4×2 / 0x-4×2 / 0x234×1 / 0x230×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x171808 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17180c sub sp, sp, #36
 *   @0x171810 ldr r4, [pc, #0x234]
 *   @0x171814 mov r3, #0
 *   @0x171818 ldr r2, [pc, #0x230]
 *   @0x17181c add r4, pc, r4
 *   @0x171820 str r3, [sp, #0x18]
 *   @0x171824 str r3, [sp, #0x1c]
 *   @0x171828 ldr r3, [r4, r2]
 *   @0x17182c ldrb r3, [r3]
 *   @0x171830 cmp r3, #0
 *   @0x171834 bne 0x171848 <_Z26YYGML_surface_reset_targetv+0x40>
 *   @0x171838 mov r8, #0
 *   @0x17183c mov r0, r8
 *   @0x171840 add sp, sp, #36
 *   @0x171844 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x171848 bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17184c bl 0x183404 <_ZN8Graphics19RestoreRenderTargetEv>
 *   @0x171850 subs r8, r0, #0
 *   @0x171854 beq 0x171838 <_Z26YYGML_surface_reset_targetv+0x30>
 *   @0x171858 ldr r3, [pc, #0x1f4]
 *   @0x17185c ldr r12, [r4, r3]
 *   @0x171860 ldr r3, [r12]
 *   @0x171864 cmp r3, #0
 *   @0x171868 beq 0x171a04 <_Z26YYGML_surface_reset_targetv+0x1fc>
 *   @0x17186c ldr r1, [pc, #0x1e4]
 *   @0x171870 ldr r2, [pc, #0x1e4]
 *   @0x171874 ldr r5, [r4, r1]
 *   @0x171878 ldr r2, [r4, r2]
 *   @0x17187c add r1, r5, #12
 *   @0x171880 sub r5, r5, #4
 *   @0x171884 add r0, r2, r3, lsl #2
 *   @0x171888 ldr lr, [r0, #-0x4]!
 *   @0x17188c str lr, [r1], #-4
 *   @0x171890 cmp r1, r5
 *   @0x171894 bne 0x171888 <_Z26YYGML_surface_reset_targetv+0x80>
 *   @0x171898 ldr r5, [pc, #0x1c0]
 *   @0x17189c sub r1, r3, #5
 *   @0x1718a0 add r11, r2, r3, lsl #2
 *   @0x1718a4 ldr r9, [pc, #0x1b8]
 *   @0x1718a8 ldr r10, [r2, r1, lsl #2]
 *   @0x1718ac vldr s15, [r11, #-32]
 *   @0x1718b0 ldr r5, [r4, r5]
 *   @0x1718b4 add r0, r2, r3, lsl #2
 *   @0x1718b8 ldr r7, [pc, #0x1a8]
 *   @0x1718bc adds r10, r10, #0
 *   @0x1718c0 vldr s13, [r0, #-24]
 *   @0x1718c4 ldr r6, [pc, #0x1a0]
 *   @0x1718c8 str r5, [sp, #0xc]
 *   @0x1718cc movne r10, #1
 *   @0x1718d0 ldr r11, [sp, #0xc]
 *   @0x1718d4 vldr s14, [r0, #-28]
 *   @0x1718d8 ldr r5, [pc, #0x190]
 *   @0x1718dc sub lr, r3, #11
 *   @0x1718e0 ldr r0, [pc, #0x18c]
 *   @0x1718e4 strb r10, [r11]
 *   @0x1718e8 add r10, r2, r3, lsl #2
 *   @0x1718ec ldr r9, [r4, r9]
 *   @0x1718f0 vstr s13, [r9]
 *   @0x1718f4 ldr r7, [r4, r7]
 *   @0x1718f8 vstr s14, [r7]
 *   @0x1718fc ldr r11, [r10, #-0x24]
 *   @0x171900 ldr r1, [pc, #0x170]
 *   @0x171904 str r7, [sp, #0x14]
 *   @0x171908 ldr r6, [r4, r6]
 *   @0x17190c vstr s15, [r6]
 *   @0x171910 ldr lr, [r2, lr, lsl #2]
 *   @0x171914 str r6, [sp, #0xc]
 *   @0x171918 ldr r5, [r4, r5]
 *   @0x17191c str r5, [sp, #0x10]
 *   @0x171920 ldr r6, [sp, #0x10]
 *   @0x171924 ldr r5, [r10, #-0x28]
 *   @0x171928 str r11, [r6]
 *   @0x17192c ldr r11, [r4, r0]
 *   @0x171930 sub r0, r3, #12
 *   @0x171934 ldr r6, [pc, #0x140]
 *   @0x171938 ldr r0, [r2, r0, lsl #2]
 *   @0x17193c str r5, [r11]
 *   @0x171940 ldr r5, [r4, r1]
 *   @0x171944 ldr r1, [pc, #0x134]
 *   @0x171948 str lr, [r5]
 *   @0x17194c sub lr, r3, #13
 *   @0x171950 ldr r6, [r4, r6]
 *   @0x171954 sub r3, r3, #14
 *   @0x171958 ldr lr, [r2, lr, lsl #2]
 *   @0x17195c ldr r2, [r2, r3, lsl #2]
 *   @0x171960 str r0, [r6]
 *   @0x171964 ldr r7, [r4, r1]
 *   @0x171968 ldr r1, [pc, #0x114]
 *   @0x17196c str r3, [r12]
 *   @0x171970 ldr r0, [pc, #0x110]
 *   @0x171974 str lr, [r7]
 *   @0x171978 ldr r10, [r4, r1]
 *   @0x17197c str r2, [r10]
 *   @0x171980 ldr r2, [r4, r0]
 *   @0x171984 ldrb r2, [r2]
 *   @0x171988 cmp r2, #0
 *   @0x17198c beq 0x171998 <_Z26YYGML_surface_reset_targetv+0x190>
 *   @0x171990 cmp r3, #0
 *   @0x171994 beq 0x171a44 <_Z26YYGML_surface_reset_targetv+0x23c>
 *   @0x171998 add r0, sp, #24
 *   @0x17199c add r1, sp, #28
 *   @0x1719a0 bl 0x168cac <_Z17GR_D3D_Get_RegionRiS_>
 *   @0x1719a4 ldr r0, [r10]
 *   @0x1719a8 ldr r3, [r5]
 *   @0x1719ac ldr r1, [r7]
 *   @0x1719cc beq 0x171a1c <_Z26YYGML_surface_reset_targetv+0x214>
 *   @0x1719d0 ldr r7, [sp, #0x10]
 *   @0x1719d4 ldr r11, [sp, #0xc]
 *   @0x1719d8 ldr r12, [sp, #0x14]
 *   @0x1719dc ldr lr, [r9]
 *   @0x1719e0 ldr r1, [r7]
 *   @0x1719e4 ldr r2, [r11]
 *   @0x1719e8 ldr r3, [r12]
 *   @0x1719ec str lr, [sp]
 *   @0x1719f0 bl 0x1aff1c <_Z19UpdateDefaultCamerafffff>
 *   @0x1719f4 bl 0x168d7c <_Z16DirtyRoomExtentsv>
 *   @0x1719f8 mov r0, r8
 *   @0x1719fc add sp, sp, #36
 *   @0x171a00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x171a04 ldr r1, [pc, #0x4c]
 *   @0x171a08 mov r8, r3
 *   @0x171a0c mvn r2, #0
 *   @0x171a10 ldr r3, [r4, r1]
 *   @0x171a14 str r2, [r3]
 *   @0x171a18 b 0x17183c <_Z26YYGML_surface_reset_targetv+0x34>
 *   @0x171a1c ldr r6, [sp, #0x10]
 *   @0x171a20 ldr r7, [sp, #0xc]
 *   @0x171a24 ldr r11, [sp, #0x14]
 *   @0x171a28 ldr lr, [r9]
 *   @0x171a2c ldr r1, [r6]
 *   @0x171a30 ldr r2, [r7]
 *   @0x171a34 ldr r3, [r11]
 *   @0x171a38 str lr, [sp]
 *   @0x171a3c bl 0x169408 <_Z20GR_D3D_Set_View_Areafffff>
 *   @0x171a40 b 0x1719f4 <_Z26YYGML_surface_reset_targetv+0x1ec>
 *   @0x171a44 bl 0x1b3330 <_Z10SetGuiViewv>
 *   @0x171a48 b 0x1719f4 <_Z26YYGML_surface_reset_targetv+0x1ec>
 *   @0x171a4c eoreq r0, r8, r4, lsr r4
 *   @0x171a50 .word 0xffffe4d0
 *   @0x171a54 .word 0xffffe614
 *   @0x171a58 .word 0xffffe51c
 *   @0x171a5c .word 0xffffe618
 *   @0x171a60 .word 0xffffe490
 *   @0x171a64 .word 0xffffe61c
 *   @0x171a68 .word 0xffffe620
 *   @0x171a6c .word 0xffffe624
 *   @0x171a70 .word 0xffffe628
 *   @0x171a74 .word 0xffffe62c
 *   @0x171a78 .word 0xffffe630
 *   @0x171a7c .word 0xffffe634
 *   @0x171a80 .word 0xffffe638
 *   @0x171a84 .word 0xffffe63c
 *   @0x171a88 .word 0xffffdf30
 *   @0x171a8c .word 0xffffbcd4
 *
 * ══ §15/56 StartGame  0x1d44fc  size 636  152 条（0x1d44fc..0x1d4778）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1d44fc 0x1d4778  size 636  152 条
 * 部分覆盖: 本节 152/159 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d4508→0x5428e8, 0x1d4520→0x3f5068, 0x1d4524→0x3f23d0, 0x1d453c→0x54294c, 0x1d4540→0x542940, 0x1d4548→0x542918, 0x1d4554→0x542914, 0x1d4558→0x542950
 * 调用序列: Room_Number()×2 / Create_Object_Lists() / Extension_Initialize() / GR_Window_Set_Cursor(int) / GR_D3D_Set_Texture_Interpolation(bool) / StartGame()+0x168 / CRoom::~CRoom() / operator delete(void*)
 * 字段偏移 top8: 0x4×8 / 0x22c×2 / 0x218×2 / 0x204×2 / 0x1f8×2 / 0x2×2 / 0x200×1 / 0x1c8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d44fc push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1d451c beq 0x1d4538 <_Z9StartGamev+0x3c>
 *   @0x1d4520 ldr r2, [pc, #0x218]
 *   @0x1d4524 ldr r3, [pc, #0x218]
 *   @0x1d4528 ldr r2, [r6, r2]
 *   @0x1d452c ldr r3, [r6, r3]
 *   @0x1d4530 ldr r2, [r2]
 *   @0x1d4534 str r2, [r3]
 *   @0x1d4538 bl 0x19e7dc <_Z19Create_Object_Listsv>
 *   @0x1d453c ldr r3, [pc, #0x204]
 *   @0x1d4540 ldr r0, [pc, #0x204]
 *   @0x1d4544 mov r4, #0
 *   @0x1d4548 ldr r1, [pc, #0x200]
 *   @0x1d454c mvn r5, #0
 *   @0x1d4550 ldr r12, [r6, r3]
 *   @0x1d4554 ldr r2, [pc, #0x1f8]
 *   @0x1d4558 ldr r3, [pc, #0x1f8]
 *   @0x1d455c str r4, [r12]
 *   @0x1d4560 ldr r0, [r6, r0]
 *   @0x1d4564 str r5, [r0]
 *   @0x1d4568 ldr r1, [r6, r1]
 *   @0x1d456c str r5, [r1]
 *   @0x1d4570 ldr r2, [r6, r2]
 *   @0x1d4574 str r4, [r2]
 *   @0x1d4578 ldr r3, [r6, r3]
 *   @0x1d457c str r4, [r3]
 *   @0x1d4580 bl 0xf63f0 <_Z20Extension_Initializev>
 *   @0x1d4584 cmp r0, r4
 *   @0x1d4588 beq 0x1d46d0 <_Z9StartGamev+0x1d4>
 *   @0x1d458c ldr r3, [pc, #0x1c8]
 *   @0x1d4590 ldr r3, [r6, r3]
 *   @0x1d4594 ldrb r3, [r3]
 *   @0x1d4598 cmp r3, r4
 *   @0x1d459c moveq r0, r5
 *   @0x1d45a0 movne r0, r4
 *   @0x1d45a4 bl 0x17af8c <_Z20GR_Window_Set_Cursori>
 *   @0x1d45a8 ldr r3, [pc, #0x1b0]
 *   @0x1d45ac ldr r3, [r6, r3]
 *   @0x1d45b0 ldrb r0, [r3]
 *   @0x1d45b4 bl 0x168710 <_Z32GR_D3D_Set_Texture_Interpolationb>
 *   @0x1d45b8 bl 0x1b523c <_Z11Room_Numberv>
 *   @0x1d45bc ldr r3, [pc, #0x1a0]
 *   @0x1d45c0 ldr r5, [r6, r3]
 *   @0x1d45c4 ldr r2, [r5]
 *   @0x1d45c8 cmp r0, r2
 *   @0x1d45cc mov r9, r0
 *   @0x1d45d0 beq 0x1d4678 <_Z9StartGamev+0x17c>
 *   @0x1d45d4 cmp r0, #0
 *   @0x1d45d8 bne 0x1d46d8 <_Z9StartGamev+0x1dc>
 *   @0x1d45dc ldr r3, [r5, #0x4]
 *   @0x1d45e0 cmp r3, #0
 *   @0x1d45e4 beq 0x1d4664 <_Z9StartGamev+0x168>
 *   @0x1d45e8 cmp r2, #0
 *   @0x1d45ec ble 0x1d4664 <_Z9StartGamev+0x168>
 *   @0x1d45f0 mov r4, r0
 *   @0x1d45f4 mov r10, r0
 *   @0x1d45f8 ldr r0, [r3]
 *   @0x1d45fc movw r2, #0xfeee
 *   @0x1d4600 movt r2, #0xfeee
 *   @0x1d4604 movw r1, #0xfeee
 *   @0x1d4608 cmp r0, r2
 *   @0x1d460c movt r1, #0xfeee
 *   @0x1d4610 lsl r8, r4, #2
 *   @0x1d4614 beq 0x1d4654 <_Z9StartGamev+0x158>
 *   @0x1d4618 ldr r7, [r3, r4, lsl #2]
 *   @0x1d461c add r2, r3, r8
 *   @0x1d4620 cmp r7, #0
 *   @0x1d4624 mov r0, r7
 *   @0x1d4628 beq 0x1d4654 <_Z9StartGamev+0x158>
 *   @0x1d462c ldr r3, [r7]
 *   @0x1d4630 cmp r3, r1
 *   @0x1d4634 beq 0x1d464c <_Z9StartGamev+0x150>
 *   @0x1d4638 bl 0x1afa00 <_ZN5CRoomD2Ev>
 *   @0x1d463c mov r0, r7
 *   @0x1d4640 bl 0x27d1d0 <_ZdlPv>
 *   @0x1d4644 ldr r2, [r5, #0x4]
 *   @0x1d4648 add r2, r2, r8
 *   @0x1d464c str r10, [r2]
 *   @0x1d4650 ldr r3, [r5, #0x4]
 *   @0x1d4654 ldr r2, [r5]
 *   @0x1d4658 add r4, r4, #1
 *   @0x1d465c cmp r4, r2
 *   @0x1d4660 blt 0x1d45f8 <_Z9StartGamev+0xfc>
 *   @0x1d4664 mov r0, r3
 *   @0x1d4668 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1d466c mov r3, #0
 *   @0x1d4670 str r3, [r5, #0x4]
 *   @0x1d4674 str r9, [r5]
 *   @0x1d4678 mov r4, #0
 *   @0x1d467c mov r7, r4
 *   @0x1d4680 b 0x1d4690 <_Z9StartGamev+0x194>
 *   @0x1d4684 ldr r3, [r5, #0x4]
 *   @0x1d4688 str r7, [r3, r4, lsl #2]
 *   @0x1d468c add r4, r4, #1
 *   @0x1d4690 bl 0x1b523c <_Z11Room_Numberv>
 *   @0x1d4694 cmp r4, r0
 *   @0x1d4698 blt 0x1d4684 <_Z9StartGamev+0x188>
 *   @0x1d469c ldr r2, [pc, #0xc4]
 *   @0x1d46a0 mov r1, #0
 *   @0x1d46a4 ldr r3, [pc, #0xc0]
 *   @0x1d46a8 ldr r2, [r6, r2]
 *   @0x1d46ac str r1, [r2]
 *   @0x1d46b0 ldr r3, [r6, r3]
 *   @0x1d46b4 ldrb r3, [r3]
 *   @0x1d46b8 cmp r3, r1
 *   @0x1d46bc beq 0x1d4704 <_Z9StartGamev+0x208>
 *   @0x1d46c0 mov r0, #0
 *   @0x1d46c4 add sp, sp, #8
 *   @0x1d46c8 pop {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1d46cc b 0x27c28c <_ZN13MemoryManager10DumpMemoryEP7__sFILE>
 *   @0x1d46d0 add sp, sp, #8
 *   @0x1d46d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1d46d8 lsls r1, r0, #2
 *   @0x1d46dc beq 0x1d4730 <_Z9StartGamev+0x234>
 *   @0x1d46e0 ldr r2, [pc, #0x88]
 *   @0x1d46e4 mov r3, #0
 *   @0x1d46e8 ldr r0, [r5, #0x4]
 *   @0x1d46ec add r2, pc, r2
 *   @0x1d46f0 str r3, [sp]
 *   @0x1d46f4 mov r3, #135
 *   @0x1d46f8 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x1d46fc str r0, [r5, #0x4]
 *   @0x1d4700 b 0x1d4674 <_Z9StartGamev+0x178>
 *   @0x1d4704 bl 0x1b5d08 <_Z10Room_Firstv>
 *   @0x1d4708 ldr r3, [pc, #0x64]
 *   @0x1d470c mov r1, #1
 *   @0x1d4710 ldr r4, [r6, r3]
 *   @0x1d4714 str r0, [r4]
 *   @0x1d4718 bl 0x1d38e0 <_Z9StartRoomib>
 *   @0x1d471c ldr r0, [r4]
 *   @0x1d4720 cmp r0, #0
 *   @0x1d4724 blt 0x1d46c0 <_Z9StartGamev+0x1c4>
 *   @0x1d4728 bl 0x1d4450 <_Z10SwitchRoomi>
 *   @0x1d472c b 0x1d46c0 <_Z9StartGamev+0x1c4>
 *   @0x1d4730 ldr r3, [r5, #0x4]
 *   @0x1d4734 b 0x1d4664 <_Z9StartGamev+0x168>
 *   @0x1d4738 eoreq sp, r1, r4, asr #14
 *   @0x1d473c .word 0xffffbcd4
 *   @0x1d4740 .word 0xffffeb14
 *   @0x1d4744 .word 0xffffc0ac
 *   @0x1d4748 .word 0xffffce34
 *   @0x1d474c .word 0xffffd780
 *   @0x1d4750 .word 0xffffd798
 *   @0x1d4754 .word 0xffffebf0
 *   @0x1d4758 .word 0xffffc458
 *   @0x1d475c .word 0xffffd79c
 *   @0x1d4760 .word 0xffffe4d8
 *   @0x1d4764 .word 0xffffeed8
 *   @0x1d4768 .word 0xffffeef4
 *   @0x1d476c .word 0xffffdf9c
 *   @0x1d4770 andseq r8, r7, r4, lsl #24
 *   @0x1d4774 .word 0xffffc154
 *
 * ══ §16/56 HandleMouse  0x1db7bc  size 596  142 条（0x1db7bc..0x1dba10）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1db7bc 0x1dba10  size 596  142 条
 * 部分覆盖: 本节 142/149 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1db7c4→0x757e7c, 0x1db7dc→0x3f5098, 0x1db7fc→0x757e80, 0x1db838→0x5428e8, 0x1db95c→0x757e80
 * 调用序列: HandleMouseGlobal(int)×8 / HandleButton(int)×6 / IO_Button_Pressed(int, int)×3 / IO_Button_Down(int, int)×2 / HandleGestures() / GR_Window_Views_Mouse_Get_X(int) / GR_Window_Views_Mouse_Get_Y(int) / IO_Button_Released(int, int)
 * 字段偏移 top8: 0x230×2 / 0x21c×1 / 0x200×1 / 0x1f4×1 / 0xc×1 / 0x8×1 / 0x1cc×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1db7bc push {r4, r5, r6, r7, r8, lr}
 *   @0x1db7c0 ldr r4, [pc, #0x230]
 *   @0x1db7c4 ldr r3, [pc, #0x230]
 *   @0x1db7c8 add r4, pc, r4
 *   @0x1db7cc ldr r6, [r4, r3]
 *   @0x1db7d0 ldrb r3, [r6]
 *   @0x1db7d4 cmp r3, #0
 *   @0x1db7d8 bne 0x1db95c <_Z11HandleMousev+0x1a0>
 *   @0x1db7dc ldr r3, [pc, #0x21c]
 *   @0x1db7e0 ldr r3, [r4, r3]
 *   @0x1db7e4 ldrb r3, [r3]
 *   @0x1db7e8 cmp r3, #0
 *   @0x1db7ec bne 0x1db80c <_Z11HandleMousev+0x50>
 *   @0x1db7f0 ldrb r3, [r6]
 *   @0x1db7f4 cmp r3, #0
 *   @0x1db7f8 popeq {r4, r5, r6, r7, r8, pc}
 *   @0x1db7fc ldr r3, [pc, #0x200]
 *   @0x1db800 ldr r0, [r4, r3]
 *   @0x1db804 pop {r4, r5, r6, r7, r8, lr}
 *   @0x1db808 b 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1db80c ldr r5, [pc, #0x1f4]
 *   @0x1db810 bl 0x1db590 <_Z14HandleGesturesv>
 *   @0x1db814 mov r0, #0
 *   @0x1db818 add r5, pc, r5
 *   @0x1db81c ldm r5, {r2, r3}
 *   @0x1db820 str r3, [r5, #0xc]
 *   @0x1db824 str r2, [r5, #0x8]
 *   @0x1db828 bl 0x17ad8c <_Z27GR_Window_Views_Mouse_Get_Xi>
 *   @0x1db82c str r0, [r5]
 *   @0x1db84c bne 0x1db894 <_Z11HandleMousev+0xd8>
 *   @0x1db850 mov r8, #1
 *   @0x1db854 mov r5, r8
 *   @0x1db858 mov r1, #0
 *   @0x1db85c mov r0, r5
 *   @0x1db860 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1db864 subs r1, r0, #0
 *   @0x1db868 beq 0x1db9ac <_Z11HandleMousev+0x1f0>
 *   @0x1db86c sub r0, r5, #1
 *   @0x1db870 mov r8, #0
 *   @0x1db874 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db878 add r0, r5, #49
 *   @0x1db87c bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db880 add r5, r5, #1
 *   @0x1db884 cmp r5, #4
 *   @0x1db888 bne 0x1db858 <_Z11HandleMousev+0x9c>
 *   @0x1db88c cmp r8, #0
 *   @0x1db890 bne 0x1db9e0 <_Z11HandleMousev+0x224>
 *   @0x1db894 mov r5, #1
 *   @0x1db898 mov r0, r5
 *   @0x1db89c mov r1, #0
 *   @0x1db8a0 bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x1db8a4 cmp r0, #0
 *   @0x1db8a8 bne 0x1db990 <_Z11HandleMousev+0x1d4>
 *   @0x1db8ac add r5, r5, #1
 *   @0x1db8b0 cmp r5, #4
 *   @0x1db8b4 bne 0x1db898 <_Z11HandleMousev+0xdc>
 *   @0x1db8b8 ldrb r3, [r7]
 *   @0x1db8bc cmp r3, #0
 *   @0x1db8c0 beq 0x1db908 <_Z11HandleMousev+0x14c>
 *   @0x1db8c4 mov r7, #1
 *   @0x1db8c8 mov r5, r7
 *   @0x1db8cc mov r1, #0
 *   @0x1db8d0 mov r0, r5
 *   @0x1db8d4 bl 0x18c0b4 <_Z14IO_Button_Downii>
 *   @0x1db8d8 subs r1, r0, #0
 *   @0x1db8dc beq 0x1db9c0 <_Z11HandleMousev+0x204>
 *   @0x1db8e0 sub r0, r5, #1
 *   @0x1db8e4 mov r7, #0
 *   @0x1db8e8 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db8ec add r0, r5, #49
 *   @0x1db8f0 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db8f4 add r5, r5, #1
 *   @0x1db8f8 cmp r5, #4
 *   @0x1db8fc bne 0x1db8cc <_Z11HandleMousev+0x110>
 *   @0x1db900 cmp r7, #0
 *   @0x1db904 bne 0x1db9ec <_Z11HandleMousev+0x230>
 *   @0x1db908 mov r5, #1
 *   @0x1db90c mov r0, r5
 *   @0x1db910 mov r1, #0
 *   @0x1db914 bl 0x18c12c <_Z18IO_Button_Releasedii>
 *   @0x1db918 cmp r0, #0
 *   @0x1db91c bne 0x1db974 <_Z11HandleMousev+0x1b8>
 *   @0x1db920 add r5, r5, #1
 *   @0x1db924 cmp r5, #4
 *   @0x1db928 bne 0x1db90c <_Z11HandleMousev+0x150>
 *   @0x1db92c bl 0x1d5fe8 <_Z11HandleEnterv>
 *   @0x1db930 mov r0, #0
 *   @0x1db934 bl 0x18c168 <_Z11IO_Wheel_Upi>
 *   @0x1db938 cmp r0, #0
 *   @0x1db93c bne 0x1db9d4 <_Z11HandleMousev+0x218>
 *   @0x1db940 mov r0, #0
 *   @0x1db944 bl 0x18c18c <_Z13IO_Wheel_Downi>
 *   @0x1db948 cmp r0, #0
 *   @0x1db94c beq 0x1db7f0 <_Z11HandleMousev+0x34>
 *   @0x1db950 mov r0, #61
 *   @0x1db954 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db958 b 0x1db7f0 <_Z11HandleMousev+0x34>
 *   @0x1db95c ldr r3, [pc, #0xa0]
 *   @0x1db960 mov r1, #6
 *   @0x1db964 mov r2, #9
 *   @0x1db968 ldr r0, [r4, r3]
 *   @0x1db96c bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1db970 b 0x1db7dc <_Z11HandleMousev+0x20>
 *   @0x1db974 add r0, r5, #6
 *   @0x1db978 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db97c mov r0, #13
 *   @0x1db980 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db984 add r0, r5, #55
 *   @0x1db988 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db98c b 0x1db920 <_Z11HandleMousev+0x164>
 *   @0x1db990 add r0, r5, #3
 *   @0x1db994 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db998 mov r0, #12
 *   @0x1db99c bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db9a0 add r0, r5, #52
 *   @0x1db9a4 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db9a8 b 0x1db8ac <_Z11HandleMousev+0xf0>
 *   @0x1db9ac mov r0, r5
 *   @0x1db9b0 bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x1db9b4 cmp r0, #0
 *   @0x1db9b8 bne 0x1db86c <_Z11HandleMousev+0xb0>
 *   @0x1db9bc b 0x1db880 <_Z11HandleMousev+0xc4>
 *   @0x1db9c0 mov r0, r5
 *   @0x1db9c4 bl 0x18c0f0 <_Z17IO_Button_Pressedii>
 *   @0x1db9c8 cmp r0, #0
 *   @0x1db9cc bne 0x1db8e0 <_Z11HandleMousev+0x124>
 *   @0x1db9d0 b 0x1db8f4 <_Z11HandleMousev+0x138>
 *   @0x1db9d4 mov r0, #60
 *   @0x1db9d8 bl 0x1d5d00 <_Z17HandleMouseGlobali>
 *   @0x1db9dc b 0x1db940 <_Z11HandleMousev+0x184>
 *   @0x1db9e0 mov r0, #3
 *   @0x1db9e4 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db9e8 b 0x1db894 <_Z11HandleMousev+0xd8>
 *   @0x1db9ec mov r0, #3
 *   @0x1db9f0 bl 0x1d5e70 <_Z12HandleButtoni>
 *   @0x1db9f4 b 0x1db908 <_Z11HandleMousev+0x14c>
 *   @0x1db9f8 eoreq r6, r1, r8, lsl #9
 *   @0x1db9fc .word 0xffffbf18
 *   @0x1dba00 .word 0xffffc96c
 *   @0x1dba04 .word 0xffffbf1c
 *   @0x1dba08 eorseq r9, r6, r8, asr r2
 *   @0x1dba0c .word 0xffffbcd4
 *
 * ══ §17/56 TickDebugger  0x29d770  size 568  135 条（0x29d770..0x29d9a8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x29d770 0x29d9a8  size 568  135 条
 * 部分覆盖: 本节 135/142 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x29d778→0x757e4c, 0x29d794→0x757e58, 0x29d7b0→0x757e72, 0x29d7c4→0x542979, 0x29d7ec→0x5428e8, 0x29d82c→0x4a20f8, 0x29d858→0x757e49, 0x29d86c→0x3eb708
 * 调用序列: Timing_Time / VM::ClearBreakpointsFromMemory() / DbgServer::Process() / VM::WriteBreakpointsToMemory() / TickDebugger()+0xdc / DebuggerIsConnected() / DbgServer::~DbgServer() / operator delete(void*)
 * 字段偏移 top8: 0x22c×5 / 0x230×3 / 0x1ec×2 / 0x234×2 / 0x120×2 / 0x1d4×1 / 0x1bc×1 / 0x1ac×1
 * VFP 指令 4 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x29d770 push {r3, r4, r5, r6, r7, lr}
 *   @0x29d774 ldr r4, [pc, #0x1ec]
 *   @0x29d778 ldr r3, [pc, #0x1ec]
 *   @0x29d77c add r4, pc, r4
 *   @0x29d780 ldr r5, [r4, r3]
 *   @0x29d784 ldr r3, [r5]
 *   @0x29d788 cmp r3, #0
 *   @0x29d78c popeq {r3, r4, r5, r6, r7, pc}
 *   @0x29d790 bl 0x215148 <Timing_Time>
 *   @0x29d794 ldr r3, [pc, #0x1d4]
 *   @0x29d798 ldr r3, [r4, r3]
 *   @0x29d79c strd r0, r1, [r3]
 *   @0x29d7a0 bl 0xd8404 <_ZN2VM26ClearBreakpointsFromMemoryEv>
 *   @0x29d7a4 ldr r0, [r5]
 *   @0x29d7a8 bl 0x29d62c <_ZN9DbgServer7ProcessEv>
 *   @0x29d7ac bl 0xd83cc <_ZN2VM24WriteBreakpointsToMemoryEv>
 *   @0x29d7b0 ldr r3, [pc, #0x1bc]
 *   @0x29d7b4 ldr r3, [r4, r3]
 *   @0x29d7b8 ldrb r2, [r3]
 *   @0x29d7bc cmp r2, #0
 *   @0x29d7c0 bne 0x29d8b8 <_Z12TickDebuggerv+0x148>
 *   @0x29d7c4 ldr r3, [pc, #0x1ac]
 *   @0x29d7c8 ldr r6, [r4, r3]
 *   @0x29d7cc ldr r3, [pc, #0x1a8]
 *   @0x29d7d0 add r3, pc, r3
 *   @0x29d7d4 ldrb r3, [r3, #0x218]
 *   @0x29d7d8 cmp r3, #0
 *   @0x29d7dc bne 0x29d8f0 <_Z12TickDebuggerv+0x180>
 *   @0x29d7e0 ldrb r3, [r6]
 *   @0x29d800 ldr r6, [pc, #0x17c]
 *   @0x29d804 add r6, pc, r6
 *   @0x29d808 ldr r7, [r6, #0x230]
 *   @0x29d80c cmp r7, #0
 *   @0x29d810 beq 0x29d938 <_Z12TickDebuggerv+0x1c8>
 *   @0x29d814 ldr r3, [r6, #0x22c]
 *   @0x29d818 ldr r2, [pc, #0x168]
 *   @0x29d81c add r2, pc, r2
 *   @0x29d820 ldr r1, [r2, #0x234]
 *   @0x29d824 cmp r1, r3
 *   @0x29d828 ble 0x29d84c <_Z12TickDebuggerv+0xdc>
 *   @0x29d82c ldr r1, [pc, #0x158]
 *   @0x29d830 add r12, r3, #1
 *   @0x29d834 ldr r0, [r2, #0x230]
 *   @0x29d838 str r12, [r2, #0x22c]
 *   @0x29d83c ldr r2, [r4, r1]
 *   @0x29d840 add r3, r0, r3, lsl #2
 *   @0x29d844 ldr r2, [r2]
 *   @0x29d848 str r2, [r3]
 *   @0x29d84c bl 0x29cb74 <_Z19DebuggerIsConnectedv>
 *   @0x29d850 subs r6, r0, #0
 *   @0x29d854 popne {r3, r4, r5, r6, r7, pc}
 *   @0x29d858 ldr r3, [pc, #0x130]
 *   @0x29d85c ldr r7, [r4, r3]
 *   @0x29d860 ldrb r3, [r7]
 *   @0x29d864 cmp r3, #0
 *   @0x29d868 popeq {r3, r4, r5, r6, r7, pc}
 *   @0x29d86c ldr r3, [pc, #0x120]
 *   @0x29d870 ldr r1, [pc, #0x120]
 *   @0x29d874 ldr r3, [r4, r3]
 *   @0x29d878 add r1, pc, r1
 *   @0x29d87c ldr r0, [r3]
 *   @0x29d880 ldr r3, [r0]
 *   @0x29d884 ldr r3, [r3, #0xc]
 *   @0x29d888 blx r3
 *   @0x29d88c ldr r4, [r5]
 *   @0x29d890 strb r6, [r7]
 *   @0x29d894 cmp r4, #0
 *   @0x29d898 beq 0x29d8ac <_Z12TickDebuggerv+0x13c>
 *   @0x29d89c mov r0, r4
 *   @0x29d8a0 bl 0x29d038 <_ZN9DbgServerD2Ev>
 *   @0x29d8a4 mov r0, r4
 *   @0x29d8a8 bl 0x27d1d0 <_ZdlPv>
 *   @0x29d8ac mov r3, #0
 *   @0x29d8b0 str r3, [r5]
 *   @0x29d8b4 pop {r3, r4, r5, r6, r7, pc}
 *   @0x29d8b8 ldr r2, [pc, #0xb8]
 *   @0x29d8bc ldr r6, [r4, r2]
 *   @0x29d8c0 ldrb r2, [r6]
 *   @0x29d8c4 cmp r2, #0
 *   @0x29d8c8 bne 0x29d7cc <_Z12TickDebuggerv+0x5c>
 *   @0x29d8cc ldr r1, [pc, #0xc8]
 *   @0x29d8d0 strb r2, [r3]
 *   @0x29d8d4 ldr r3, [r4, r1]
 *   @0x29d8d8 ldrb r3, [r3]
 *   @0x29d8dc cmp r3, #0
 *   @0x29d8e0 beq 0x29d928 <_Z12TickDebuggerv+0x1b8>
 *   @0x29d8e4 mov r3, #0
 *   @0x29d8e8 strb r3, [r6]
 *   @0x29d8ec b 0x29d7cc <_Z12TickDebuggerv+0x5c>
 *   @0x29d8f0 bl 0x29cdec <_Z14DebuggerPingIPv>
 *   @0x29d8f4 b 0x29d7e0 <_Z12TickDebuggerv+0x70>
 *   @0x29d8f8 ldr r2, [pc, #0x8c]
 *   @0x29d8fc ldr r3, [pc, #0x9c]
 *   @0x29d900 ldr r2, [r4, r2]
 *   @0x29d904 add r3, pc, r3
 *   @0x29d908 vldr s15, [r2]
 *   @0x29d90c vldr s14, [r3, #552]
 *   @0x29d910 vadd.f32 s15, s14, s15
 *   @0x29d914 ldr r2, [r3, #0x22c]
 *   @0x29d918 add r2, r2, #1
 *   @0x29d91c str r2, [r3, #0x22c]
 *   @0x29d920 vstr s15, [r3, #552]
 *   @0x29d924 b 0x29d84c <_Z12TickDebuggerv+0xdc>
 *   @0x29d928 bl 0x1b5d08 <_Z10Room_Firstv>
 *   @0x29d92c mov r1, #1
 *   @0x29d930 bl 0x1d38e0 <_Z9StartRoomib>
 *   @0x29d934 b 0x29d8e4 <_Z12TickDebuggerv+0x174>
 *   @0x29d938 ldr r1, [pc, #0x64]
 *   @0x29d93c mov r3, #1
 *   @0x29d940 mov r0, #512
 *   @0x29d944 movw r2, #0x6c2
 *   @0x29d948 add r1, pc, r1
 *   @0x29d94c mov r12, #128
 *   @0x29d950 str r12, [r6, #0x234]
 *   @0x29d954 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x29d958 mov r3, r7
 *   @0x29d95c str r7, [r6, #0x22c]
 *   @0x29d960 str r0, [r6, #0x230]
 *   @0x29d964 b 0x29d818 <_Z12TickDebuggerv+0xa8>
 *   @0x29d968 ldrsbeq r4, [r5], -r4
 *   @0x29d96c .word 0xffffc0a4
 *   @0x29d970 .word 0xfffffdc4
 *   @0x29d974 .word 0xffffdf9c
 *   @0x29d978 .word 0xffffdfa0
 *   @0x29d97c subeq r10, r11, r8, lsr r4
 *   @0x29d980 .word 0xffffbcd4
 *   @0x29d984 subeq r10, r11, r4, lsl #8
 *   @0x29d988 subeq r10, r11, r12, ror #7
 *   @0x29d98c .word 0xffffe7a8
 *   @0x29d990 .word 0xfffffdc0
 *   @0x29d994 .word 0xffffbcf0
 *   @0x29d998 ldrdeq r12, sp, [r11], -r12
 *   @0x29d99c .word 0xffffbf68
 *   @0x29d9a0 subeq r10, r11, r4, lsl #6
 *   @0x29d9a4 andeq r12, r11, r12, ror r0
 *
 * ══ §18/56 Graphics::SetMatrices  0x17ec90  size 564  139 条（0x17ec90..0x17eec4）｜其中 2 条已由别的卡落锚，本节不再重复
 * @func 0x17ec90 0x17eed8  size 584  144 条
 * 部分覆盖: 本节 144/146 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 143/145 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 142/144 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 141/143 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 140/142 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x17eca0→0x4a22b1, 0x17ecc0→0x4a2170, 0x17eda4→0x3f26dc, 0x17edb8→0x479c54, 0x17edcc→0x479bf8, 0x17ede8→0x479c54, 0x17edfc→0x479bf8, 0x17ee20→0x4a23f0
 * 调用序列: yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*)×3 / Graphics::Flush() / Graphics::SetRenderState(eRenderState, unsigned int) / GR_3D_Light_Process()
 * 字段偏移 top8: 0x-c×3 / 0x-8×3 / 0x-4×3 / 0x204×1 / 0x200×1 / 0x1e4×1 / 0x104×1 / 0xf4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x17ec90 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17ec94 mov r9, r0
 *   @0x17ec98 ldr r4, [pc, #0x204]
 *   @0x17ec9c mov r7, r1
 *   @0x17eca0 ldr r3, [pc, #0x200]
 *   @0x17eca4 mov r5, r2
 *   @0x17eca8 add r4, pc, r4
 *   @0x17ecac ldr r3, [r4, r3]
 *   @0x17ecb0 ldrb r6, [r3]
 *   @0x17ecb4 cmp r6, #0
 *   @0x17ecb8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17ecbc bl 0x1852ec <_ZN8Graphics5FlushEv>
 *   @0x17ecc0 ldr r3, [pc, #0x1e4]
 *   @0x17ecc4 cmp r7, #0
 *   @0x17ecc8 ldreq r8, [r4, r3]
 *   @0x17eccc beq 0x17ed08 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x78>
 *   @0x17ecd0 ldr r8, [r4, r3]
 *   @0x17ecd4 add r11, r7, #64
 *   @0x17ecd8 mov lr, r7
 *   @0x17ecdc mov r10, r8
 *   @0x17ece0 ldr r0, [lr]
 *   @0x17ece4 add lr, lr, #16
 *   @0x17ece8 ldr r1, [lr, #-0xc]
 *   @0x17ecec mov r12, r10
 *   @0x17ecf0 ldr r2, [lr, #-0x8]
 *   @0x17ecf4 add r10, r10, #16
 *   @0x17ecf8 ldr r3, [lr, #-0x4]
 *   @0x17ecfc cmp lr, r11
 *   @0x17ed00 stm r12!, {r0, r1, r2, r3}
 *   @0x17ed04 bne 0x17ece0 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x50>
 *   @0x17ed08 cmp r5, #0
 *   @0x17ed0c beq 0x17ed44 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xb4>
 *   @0x17ed10 add r10, r8, #64
 *   @0x17ed14 add r11, r5, #64
 *   @0x17ed18 mov lr, r5
 *   @0x17ed1c ldr r0, [lr]
 *   @0x17ed20 add lr, lr, #16
 *   @0x17ed24 ldr r1, [lr, #-0xc]
 *   @0x17ed28 mov r12, r10
 *   @0x17ed2c ldr r2, [lr, #-0x8]
 *   @0x17ed30 add r10, r10, #16
 *   @0x17ed34 ldr r3, [lr, #-0x4]
 *   @0x17ed38 cmp lr, r11
 *   @0x17ed3c stm r12!, {r0, r1, r2, r3}
 *   @0x17ed40 bne 0x17ed1c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x8c>
 *   @0x17ed44 cmp r9, #0
 *   @0x17ed48 beq 0x17ee68 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x1d8>
 *   @0x17ed4c mov r12, r9
 *   @0x17ed50 add r7, r8, #128
 *   @0x17ed54 add r9, r9, #64
 *   @0x17ed58 ldr r0, [r12]
 *   @0x17ed5c add r12, r12, #16
 *   @0x17ed60 ldr r1, [r12, #-0xc]
 *   @0x17ed64 mov lr, r7
 *   @0x17ed68 ldr r2, [r12, #-0x8]
 *   @0x17ed6c add r7, r7, #16
 *   @0x17ed70 ldr r3, [r12, #-0x4]
 *   @0x17ed74 cmp r12, r9
 *   @0x17ed78 stm lr!, {r0, r1, r2, r3}
 *   @0x17ed7c bne 0x17ed58 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xc8>
 *   @0x17ed80 add r7, r8, #192
 *   @0x17ed84 add r1, r8, #128
 *   @0x17ed88 mov r2, r8
 *   @0x17ed8c mov r0, r7
 *   @0x17ed94 mov r1, r7
 *   @0x17ed98 add r0, r8, #256
 *   @0x17ed9c add r2, r8, #64
 *   @0x17eda0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x17eda4 ldr r3, [pc, #0x104]
 *   @0x17eda8 ldr r9, [r4, r3]
 *   @0x17edac ldr r3, [r9]
 *   @0x17edb0 cmp r3, #0
 *   @0x17edb4 bne 0x17ee9c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x20c>
 *   @0x17edb8 ldr r3, [pc, #0xf4]
 *   @0x17edbc mov r0, #5888
 *   @0x17edc0 ldr r3, [r4, r3]
 *   @0x17edc4 ldr r3, [r3]
 *   @0x17edc8 blx r3
 *   @0x17edcc ldr r3, [pc, #0xe4]
 *   @0x17edd0 mov r0, r7
 *   @0x17edd4 ldr r3, [r4, r3]
 *   @0x17edd8 ldr r3, [r3]
 *   @0x17eddc blx r3
 *   @0x17ede0 cmp r5, #0
 *   @0x17ede4 beq 0x17ee10 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x180>
 *   @0x17ede8 ldr r3, [pc, #0xc4]
 *   @0x17edf0 ldr r3, [r4, r3]
 *   @0x17edf4 ldr r3, [r3]
 *   @0x17edf8 blx r3
 *   @0x17edfc ldr r3, [pc, #0xb4]
 *   @0x17ee00 add r0, r8, #64
 *   @0x17ee04 ldr r3, [r4, r3]
 *   @0x17ee08 ldr r3, [r3]
 *   @0x17ee0c blx r3
 *   @0x17ee10 cmp r6, #0
 *   @0x17ee14 bne 0x17ee9c <_ZN8Graphics11SetMatricesEPfS0_S0_+0x20c>
 *   @0x17ee18 cmp r5, #0
 *   @0x17ee1c beq 0x17ee34 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x1a4>
 *   @0x17ee20 ldr r3, [pc, #0x94]
 *   @0x17ee24 mov r0, #8
 *   @0x17ee28 ldr r3, [r4, r3]
 *   @0x17ee2c ldr r1, [r3]
 *   @0x17ee30 bl 0x17fd24 <_ZN8Graphics14SetRenderStateE12eRenderStatej>
 *   @0x17ee34 ldr r3, [r9]
 *   @0x17ee38 cmp r3, #1
 *   @0x17ee3c popne {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17ee40 ldr r3, [pc, #0x78]
 *   @0x17ee44 ldr r3, [r4, r3]
 *   @0x17ee48 ldr r3, [r3]
 *   @0x17ee4c cmp r3, #0
 *   @0x17ee50 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x17ee54 ldr r0, [r3, #0x6c]
 *   @0x17ee58 mov r2, r8
 *   @0x17ee5c mov r1, #5
 *   @0x17ee60 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x17ee64 b 0x1889fc <_Z27Shader_Set_Uniform_Matrix_NiiPf>
 *   @0x17ee68 cmp r7, #0
 *   @0x17ee6c bne 0x17ed80 <_ZN8Graphics11SetMatricesEPfS0_S0_+0xf0>
 *   @0x17ee70 add r0, r8, #256
 *   @0x17ee74 add r1, r8, #192
 *   @0x17ee78 add r2, r8, #64
 *   @0x17ee7c bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x17ee80 ldr r3, [pc, #0x28]
 *   @0x17ee84 ldr r9, [r4, r3]
 *   @0x17ee88 ldr r3, [r9]
 *   @0x17ee8c cmp r3, #0
 *   @0x17ee90 bne 0x17ee18 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x188>
 *   @0x17ee94 mov r6, r7
 *   @0x17ee98 b 0x17ede0 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x150>
 *   @0x17ee9c bl 0x17fa9c <_Z19GR_3D_Light_Processv>
 *   @0x17eea0 b 0x17ee18 <_ZN8Graphics11SetMatricesEPfS0_S0_+0x188>
 *   @0x17eea4 eoreq r2, r7, r8, lsr #31
 *   @0x17eea8 .word 0xffffe4d0
 *   @0x17eeac .word 0xffffe824
 *   @0x17eeb0 .word 0xffffe7b8
 *   @0x17eeb4 .word 0xffffbc48
 *   @0x17eeb8 .word 0xffffbc88
 *   @0x17eebc .word 0xffffe82c
 *   @0x17eec0 .word 0xffffe828
 *
 * ══ §19/56 HandleInstanceMovement  0x1d1cec  size 372  86 条（0x1d1cec..0x1d1e60）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1d1cec 0x1d1e60  size 372  86 条
 * 部分覆盖: 本节 86/93 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d1cf8→0x757e7c, 0x1d1d10→0x54298c, 0x1d1d28→0x5428e8, 0x1d1d5c→0x757e80, 0x1d1d70→0x757e80, 0x1d1d88→0x5428c0, 0x1d1da4→0x536f20
 * 调用序列: CPhysicsWorld::Update(int, bool) / CProfiler::Pop() / CProfiler::Push(int, int) / CTimingSource::GetFPS() / CInstance::Adapt_Speed() / CInstance::Adapt_Path() / HandleInstanceMovement(bool)+0x11c / Perform_Event(CInstance*, CInstance*, int, int)
 * 字段偏移 top8: 0x148×2 / 0x134×1 / 0xb4×1 / 0x120×1 / 0xf0×1 / 0xdc×1 / 0xc8×1 / 0xb0×1
 * VFP 指令 11 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d1cec push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1d1cf0 mov r5, r0
 *   @0x1d1cf4 ldr r8, [pc, #0x148]
 *   @0x1d1cf8 ldr r3, [pc, #0x148]
 *   @0x1d1cfc add r8, pc, r8
 *   @0x1d1d00 ldr r9, [r8, r3]
 *   @0x1d1d04 ldrb r3, [r9]
 *   @0x1d1d08 cmp r3, #0
 *   @0x1d1d0c bne 0x1d1d70 <_Z22HandleInstanceMovementb+0x84>
 *   @0x1d1d10 ldr r3, [pc, #0x134]
 *   @0x1d1d14 ldr r3, [r8, r3]
 *   @0x1d1d18 ldr r3, [r3]
 *   @0x1d1d1c ldr r4, [r3, #0xb4]
 *   @0x1d1d3c bne 0x1d1d88 <_Z22HandleInstanceMovementb+0x9c>
 *   @0x1d1d40 mov r0, r4
 *   @0x1d1d44 mov r2, r5
 *   @0x1d1d48 mov r4, #1
 *   @0x1d1d4c bl 0x2382b0 <_ZN13CPhysicsWorld6UpdateEib>
 *   @0x1d1d50 ldrb r3, [r9]
 *   @0x1d1d54 cmp r3, #0
 *   @0x1d1d58 beq 0x1d1d68 <_Z22HandleInstanceMovementb+0x7c>
 *   @0x1d1d5c ldr r3, [pc, #0xf0]
 *   @0x1d1d60 ldr r0, [r8, r3]
 *   @0x1d1d64 bl 0x2a08ac <_ZN9CProfiler3PopEv>
 *   @0x1d1d68 mov r0, r4
 *   @0x1d1d6c pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1d1d70 ldr r3, [pc, #0xdc]
 *   @0x1d1d74 mov r1, #6
 *   @0x1d1d78 mov r2, #5
 *   @0x1d1d7c ldr r0, [r8, r3]
 *   @0x1d1d80 bl 0x2a0738 <_ZN9CProfiler4PushEii>
 *   @0x1d1d84 b 0x1d1d10 <_Z22HandleInstanceMovementb+0x24>
 *   @0x1d1d88 ldr r3, [pc, #0xc8]
 *   @0x1d1d8c ldr r0, [r8, r3]
 *   @0x1d1d90 bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0x1d1d94 vmov d7, r0, r1
 *   @0x1d1d98 vcvt.s32.f64 s15, d7
 *   @0x1d1d9c vmov r1, s15
 *   @0x1d1da0 b 0x1d1d40 <_Z22HandleInstanceMovementb+0x54>
 *   @0x1d1da4 ldr r2, [pc, #0xb0]
 *   @0x1d1da8 ldr r10, [r3, #0x80]
 *   @0x1d1dac ldr r1, [r8, r2]
 *   @0x1d1db0 ldrd r6, r7, [r1]
 *   @0x1d1db4 adds r2, r6, #1
 *   @0x1d1db8 adc r3, r7, #0
 *   @0x1d1dbc cmp r10, #0
 *   @0x1d1dc0 strd r2, r3, [r1]
 *   @0x1d1dc4 beq 0x1d1e3c <_Z22HandleInstanceMovementb+0x150>
 *   @0x1d1dc8 mov r0, r10
 *   @0x1d1dcc ldr r11, [r10, #0x178]
 *   @0x1d1dd0 bl 0x193f2c <_ZN9CInstance11Adapt_SpeedEv>
 *   @0x1d1dd4 mov r0, r10
 *   @0x1d1dd8 bl 0x19411c <_ZN9CInstance10Adapt_PathEv>
 *   @0x1d1ddc cmp r0, #0
 *   @0x1d1de0 beq 0x1d1e08 <_Z22HandleInstanceMovementb+0x11c>
 *   @0x1d1de4 ldrd r4, r5, [r10, #112]
 *   @0x1d1de8 mov r0, r10
 *   @0x1d1dec mov r1, r10
 *   @0x1d1df0 mov r2, #7
 *   @0x1d1df4 cmp r6, r4
 *   @0x1d1df8 sbcs r12, r7, r5
 *   @0x1d1dfc mov r3, #8
 *   @0x1d1e00 blt 0x1d1e08 <_Z22HandleInstanceMovementb+0x11c>
 *   @0x1d1e04 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x1d1e08 vldr s13, [r10, #180]
 *   @0x1d1e0c vldr s15, [r10, #224]
 *   @0x1d1e10 vadd.f32 s15, s13, s15
 *   @0x1d1e14 vldr s14, [r10, #184]
 *   @0x1d1e18 mov r0, r10
 *   @0x1d1e1c vmov r1, s15
 *   @0x1d1e20 vldr s15, [r10, #228]
 *   @0x1d1e24 vadd.f32 s15, s14, s15
 *   @0x1d1e28 mov r10, r11
 *   @0x1d1e2c vmov r2, s15
 *   @0x1d1e30 bl 0x193e7c <_ZN9CInstance11SetPositionEff>
 *   @0x1d1e34 cmp r11, #0
 *   @0x1d1e38 bne 0x1d1dc8 <_Z22HandleInstanceMovementb+0xdc>
 *   @0x1d1e3c mov r4, #0
 *   @0x1d1e40 b 0x1d1d50 <_Z22HandleInstanceMovementb+0x64>
 *   @0x1d1e44 eoreq pc, r1, r4, asr pc
 *   @0x1d1e48 .word 0xffffbf18
 *   @0x1d1e4c .word 0xffffbcd8
 *   @0x1d1e50 .word 0xffffbcd4
 *   @0x1d1e54 .word 0xffffbf1c
 *   @0x1d1e58 .word 0xffffbcdc
 *   @0x1d1e5c .word 0xffffdeb4
 *
 * ══ §20/56 ParticleSystem_AddAllToLayers  0x1a5b9c  size 316  72 条（0x1a5b9c..0x1a5cd8）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x1a5b9c 0x1a5cd8  size 316  72 条
 * 部分覆盖: 本节 72/79 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1a5ba8→0x5428e8, 0x1a5bc0→0x542460, 0x1a5c18→0x54298c, 0x1a5c80→0x54298c
 * 调用序列: ParticleSystem_AddAllToLayers()+0x10c×2 / CLayerManager::GetNewParticleElement() / CLayerManager::GetLayerFromID(CRoom*, int) / CLayerManager::AddNewElement(CRoom*, CLayer*, CLayerElementBase*, bool) / CLayerManager::AddNewElementAtDepth(CRoom*, int, CLayerElementBase*, bool, bool)
 * 字段偏移 top8: 0x4×5 / 0x2c×5 / 0x11c×2 / 0x108×1 / 0x2×1 / 0xb4×1 / 0x30×1 / 0x1c×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1a5b9c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1a5bbc beq 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c>
 *   @0x1a5bc0 ldr r3, [pc, #0x108]
 *   @0x1a5bc4 ldr r5, [r8, r3]
 *   @0x1a5bc8 ldr r3, [r5]
 *   @0x1a5bcc cmp r3, #0
 *   @0x1a5bd0 ble 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c>
 *   @0x1a5bd4 mov r4, #0
 *   @0x1a5bd8 mov r7, #1
 *   @0x1a5bdc b 0x1a5bf0 <_Z29ParticleSystem_AddAllToLayersv+0x54>
 *   @0x1a5be0 ldr r3, [r5]
 *   @0x1a5be4 add r4, r4, #1
 *   @0x1a5be8 cmp r3, r4
 *   @0x1a5bec ble 0x1a5ca8 <_Z29ParticleSystem_AddAllToLayersv+0x10c>
 *   @0x1a5bf0 ldr r3, [r5, #0x4]
 *   @0x1a5bf4 lsl r6, r4, #2
 *   @0x1a5bf8 ldr r3, [r3, r4, lsl #2]
 *   @0x1a5bfc cmp r3, #0
 *   @0x1a5c00 beq 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44>
 *   @0x1a5c04 ldr r3, [r3, #0x2c]
 *   @0x1a5c08 cmn r3, #1
 *   @0x1a5c0c bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44>
 *   @0x1a5c10 bl 0x1c115c <_ZN13CLayerManager21GetNewParticleElementEv>
 *   @0x1a5c14 ldr r3, [r5, #0x4]
 *   @0x1a5c18 ldr r2, [pc, #0xb4]
 *   @0x1a5c1c ldr r9, [r3, r6]
 *   @0x1a5c20 ldr r1, [r9, #0x30]
 *   @0x1a5c24 cmn r1, #1
 *   @0x1a5c28 mov r10, r0
 *   @0x1a5c2c str r4, [r0, #0x1c]
 *   @0x1a5c30 beq 0x1a5c6c <_Z29ParticleSystem_AddAllToLayersv+0xd0>
 *   @0x1a5c34 ldr r9, [r8, r2]
 *   @0x1a5c38 ldr r0, [r9]
 *   @0x1a5c3c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi>
 *   @0x1a5c40 mov r2, r10
 *   @0x1a5c44 mov r3, #1
 *   @0x1a5c48 subs r1, r0, #0
 *   @0x1a5c4c beq 0x1a5cb0 <_Z29ParticleSystem_AddAllToLayersv+0x114>
 *   @0x1a5c50 ldr r12, [r5, #0x4]
 *   @0x1a5c54 ldr r0, [r9]
 *   @0x1a5c58 ldr r11, [r12, r6]
 *   @0x1a5c5c bl 0x1c5ff0 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb>
 *   @0x1a5c60 ldr r3, [r5, #0x4]
 *   @0x1a5c64 ldr r9, [r3, r6]
 *   @0x1a5c68 str r0, [r11, #0x2c]
 *   @0x1a5c6c ldr r3, [r9, #0x2c]
 *   @0x1a5c70 cmn r3, #1
 *   @0x1a5c74 bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44>
 *   @0x1a5c78 vldr s15, [r9, #28]
 *   @0x1a5c7c vcvt.s32.f32 s15, s15
 *   @0x1a5c80 ldr r0, [pc, #0x4c]
 *   @0x1a5c84 mov r2, r10
 *   @0x1a5c88 mov r3, #1
 *   @0x1a5c8c ldr r0, [r8, r0]
 *   @0x1a5c90 str r7, [sp]
 *   @0x1a5c94 vmov r1, s15
 *   @0x1a5c98 ldr r0, [r0]
 *   @0x1a5c9c bl 0x1c6c78 <_ZN13CLayerManager20AddNewElementAtDepthEP5CRoomiP17CLayerElementBasebb>
 *   @0x1a5ca0 str r0, [r9, #0x2c]
 *   @0x1a5ca4 b 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44>
 *   @0x1a5ca8 add sp, sp, #12
 *   @0x1a5cac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1a5cb0 ldr r3, [r5, #0x4]
 *   @0x1a5cb4 ldr r9, [r3, r6]
 *   @0x1a5cb8 ldr r3, [r9, #0x2c]
 *   @0x1a5cbc cmn r3, #1
 *   @0x1a5cc0 bne 0x1a5be0 <_Z29ParticleSystem_AddAllToLayersv+0x44>
 *   @0x1a5cc4 b 0x1a5c78 <_Z29ParticleSystem_AddAllToLayersv+0xdc>
 *   @0x1a5cc8 eoreq r12, r4, r4, lsr #1
 *   @0x1a5ccc .word 0xffffbcd4
 *   @0x1a5cd0 .word 0xffffeb68
 *   @0x1a5cd4 .word 0xffffbcd8
 *
 * ══ §21/56 Audio_Init  0x2166bc  size 288  65 条（0x2166bc..0x2167dc）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x2166bc 0x2167dc  size 288  65 条
 * 部分覆盖: 本节 65/72 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x2166c8→0x755310, 0x2166d0→0x755363, 0x2166e8→0x755314, 0x216714→0x755320, 0x216728→0x3f52c4
 * 调用序列: Audio_CreateSources(int) / 0xb6aa8 / Audio_SetListenerPosition(int, double, double, double) / Audio_SetListenerOrientation(int, double, double, double, double, double, double) / operator new(unsigned int) / CListener::CListener()
 * 字段偏移 top8: 0xf4×2 / 0xf0×1 / 0xdc×1 / 0xb4×1 / 0xa4×1 / 0x3c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2166bc push {r4, r5, r6, r7, lr}
 *   @0x2166c0 sub sp, sp, #44
 *   @0x2166c4 ldr r6, [pc, #0xf4]
 *   @0x2166e4 cmp r3, #0
 *   @0x2166e8 ldr r3, [pc, #0xdc]
 *   @0x2166ec beq 0x216704 <_Z10Audio_InitP13SoundHardware+0x48>
 *   @0x2166f0 ldr r3, [r6, r3]
 *   @0x2166f4 mov r2, #0
 *   @0x2166f8 strb r2, [r3]
 *   @0x2166fc add sp, sp, #44
 *   @0x216700 pop {r4, r5, r6, r7, pc}
 *   @0x216704 ldr r3, [r6, r3]
 *   @0x216708 ldrb r3, [r3]
 *   @0x21670c cmp r3, #0
 *   @0x216710 beq 0x2166fc <_Z10Audio_InitP13SoundHardware+0x40>
 *   @0x216714 ldr r3, [pc, #0xb4]
 *   @0x216718 ldr r4, [r6, r3]
 *   @0x21671c ldr r3, [r4]
 *   @0x216720 cmp r3, #0
 *   @0x216724 beq 0x2167a8 <_Z10Audio_InitP13SoundHardware+0xec>
 *   @0x216728 ldr r3, [pc, #0xa4]
 *   @0x21672c mov r4, #0
 *   @0x216730 mov r5, #0
 *   @0x216734 mov r7, #0
 *   @0x216738 movt r7, #0x3ff0
 *   @0x21673c ldr r3, [r6, r3]
 *   @0x216740 mov r6, #0
 *   @0x216744 ldr r0, [r3]
 *   @0x216748 add r0, r0, #1
 *   @0x21674c bl 0x21625c <_Z19Audio_CreateSourcesi>
 *   @0x216750 movw r0, #0xd001
 *   @0x216754 bl 0xb6aa8 <alDistanceModel@plt>
 *   @0x216758 mov r2, r4
 *   @0x21675c mov r3, r5
 *   @0x216760 strd r4, r5, [sp]
 *   @0x216764 strd r4, r5, [sp, #8]
 *   @0x216768 mov r0, #0
 *   @0x21676c bl 0x2165c0 <_Z25Audio_SetListenerPositioniddd>
 *   @0x216770 strd r4, r5, [sp]
 *   @0x216774 strd r4, r5, [sp, #16]
 *   @0x216778 mov r2, r4
 *   @0x21677c strd r4, r5, [sp, #32]
 *   @0x216780 mov r3, r5
 *   @0x216784 mov r0, #0
 *   @0x216788 strd r6, r7, [sp, #8]
 *   @0x21678c strd r6, r7, [sp, #24]
 *   @0x216790 bl 0x216650 <_Z28Audio_SetListenerOrientationidddddd>
 *   @0x216794 ldr r0, [pc, #0x3c]
 *   @0x216798 add r0, pc, r0
 *   @0x21679c add sp, sp, #44
 *   @0x2167a0 pop {r4, r5, r6, r7, lr}
 *   @0x2167a4 b 0x215fd0 <_Z7checkALPKc>
 *   @0x2167a8 mov r0, #52
 *   @0x2167ac bl 0x27c524 <_Znwj>
 *   @0x2167b0 mov r5, r0
 *   @0x2167b4 bl 0x215ae8 <_ZN9CListenerC2Ev>
 *   @0x2167b8 str r5, [r4]
 *   @0x2167bc b 0x216728 <_Z10Audio_InitP13SoundHardware+0x6c>
 *   @0x2167c0 andseq r11, sp, r4, lsl #11
 *   @0x2167c4 .word 0xfffff790
 *   @0x2167c8 .word 0xffffd3fc
 *   @0x2167cc .word 0xffffd0e0
 *   @0x2167d0 .word 0xfffff78c
 *   @0x2167d4 .word 0xfffff784
 *   @0x2167d8 andseq sp, r3, r4, lsr #8
 *
 * ══ §22/56 SoundHardware::Init  0x22021c  size 264  59 条（0x22021c..0x220324）｜其中 7 条已由别的卡落锚，本节不再重复
 * @func 0x22021c 0x220324  size 264  59 条
 * 部分覆盖: 本节 59/66 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x220228→0x755361, 0x220240→0x755363, 0x220268→0x75536c, 0x220274→0x755362, 0x220294→0x755360, 0x2202cc→0x3eb70c
 * 调用序列: OpenAL_Init() / alutInit / CheckALError()
 * 字段偏移 top8: 0x44×3 / 0xcc×2 / 0x98×2 / 0xb8×1 / 0x90×1 / 0x74×1 / 0x64×1 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x22021c push {r4, r5, lr}
 *   @0x220220 sub sp, sp, #12
 *   @0x220224 ldr r4, [pc, #0xcc]
 *   @0x220228 ldr r3, [pc, #0xcc]
 *   @0x22022c add r4, pc, r4
 *   @0x220230 ldr r3, [r4, r3]
 *   @0x220234 ldrb r3, [r3]
 *   @0x220254 mov r0, #0
 *   @0x220258 add sp, sp, #12
 *   @0x22025c pop {r4, r5, pc}
 *   @0x220260 bl 0x2232e0 <_Z11OpenAL_Initv>
 *   @0x220264 ldr r1, [pc, #0x98]
 *   @0x220268 ldr r2, [pc, #0x98]
 *   @0x22026c mov r0, #1
 *   @0x220270 add r1, pc, r1
 *   @0x220274 ldr r3, [pc, #0x90]
 *   @0x220278 strb r0, [r1]
 *   @0x22027c ldr r2, [r4, r2]
 *   @0x220280 strb r5, [r2]
 *   @0x220284 ldr r3, [r4, r3]
 *   @0x220288 ldrb r3, [r3]
 *   @0x22028c cmp r3, #0
 *   @0x220290 bne 0x220254 <_ZN13SoundHardware4InitEv+0x38>
 *   @0x220294 ldr r3, [pc, #0x74]
 *   @0x220298 ldr r3, [r4, r3]
 *   @0x22029c ldrb r3, [r3]
 *   @0x2202a0 cmp r3, #0
 *   @0x2202a4 bne 0x220254 <_ZN13SoundHardware4InitEv+0x38>
 *   @0x2202a8 ldr r2, [pc, #0x64]
 *   @0x2202ac add r1, sp, #4
 *   @0x2202b0 mov r0, sp
 *   @0x2202b4 str r3, [sp]
 *   @0x2202b8 add r2, pc, r2
 *   @0x2202bc str r2, [sp, #0x4]
 *   @0x2202c0 bl 0x221a34 <alutInit>
 *   @0x2202c4 bl 0x220198 <_Z12CheckALErrorv>
 *   @0x2202c8 b 0x220254 <_ZN13SoundHardware4InitEv+0x38>
 *   @0x2202cc ldr r3, [pc, #0x44]
 *   @0x2202d0 ldr r1, [pc, #0x44]
 *   @0x2202d4 ldr r2, [pc, #0x44]
 *   @0x2202d8 ldr r3, [r4, r3]
 *   @0x2202dc add r1, pc, r1
 *   @0x2202e0 add r2, pc, r2
 *   @0x2202e4 ldr r0, [r3]
 *   @0x2202e8 ldr r3, [r0]
 *   @0x2202ec ldr r3, [r3, #0xc]
 *   @0x2202f0 blx r3
 *   @0x2202f4 b 0x220240 <_ZN13SoundHardware4InitEv+0x24>
 *   @0x2202f8 andseq r1, sp, r4, lsr #20
 *   @0x2202fc .word 0xfffff7d8
 *   @0x220300 .word 0xffffd3fc
 *   @0x220304 ldrsbeq r5, [r3], #-12
 *   @0x220308 .word 0xfffff7dc
 *   @0x22030c .word 0xfffff7e0
 *   @0x220310 .word 0xfffff7e4
 *   @0x220314 andseq lr, r0, lr, ror r8
 *   @0x220318 .word 0xffffbac4
 *   @0x22031c andseq r4, r3, r0, ror #10
 *   @0x220320 andseq sp, r3, r8, ror #25
 *
 * ══ §23/56 GR_Texture_Create_Empty  0x173a24  size 252  63 条（0x173a24..0x173b20）
 * @func 0x173a24 0x173b20  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: AllocTexture() / Graphics::CreateTexture(int, int, int, eTextureFlags, eTextureFormat)
 * 字段偏移 top8: 0x4×2 / 0x28×1 / 0xbc×1 / 0x74×1 / 0x2×1 / 0x6×1 / 0x10×1 / 0x8×1
 * VFP 指令 9 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x173a24 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x173a28 sub sp, sp, #12
 *   @0x173a2c mov r8, r2
 *   @0x173a30 mov r9, r3
 *   @0x173a34 mov r5, r0
 *   @0x173a38 mov r4, r1
 *   @0x173a3c ldr r7, [sp, #0x28]
 *   @0x173a40 bl 0x173944 <_Z12AllocTexturev>
 *   @0x173a44 cmp r8, #0
 *   @0x173a48 moveq r3, r8
 *   @0x173a4c mov r6, r0
 *   @0x173a50 beq 0x173a74 <_Z23GR_Texture_Create_Emptyiibbi+0x50>
 *   @0x173a54 ldr r2, [pc, #0xbc]
 *   @0x173a58 cmp r9, #0
 *   @0x173a5c ldr r2, [pc, r2]
 *   @0x173a60 movne r3, #10
 *   @0x173a64 moveq r3, #2
 *   @0x173a68 ldrb r2, [r2]
 *   @0x173a6c cmp r2, #0
 *   @0x173a70 orrne r3, r3, #4
 *   @0x173a74 cmp r7, #1
 *   @0x173a78 moveq r7, #12
 *   @0x173a7c beq 0x173a8c <_Z23GR_Texture_Create_Emptyiibbi+0x68>
 *   @0x173a80 cmp r7, #2
 *   @0x173a84 moveq r7, #13
 *   @0x173a88 movne r7, #6
 *   @0x173a8c mov r2, #1
 *   @0x173a90 str r7, [sp]
 *   @0x173a94 mov r0, r5
 *   @0x173a98 mov r1, r4
 *   @0x173a9c bl 0x18269c <_ZN8Graphics13CreateTextureEiii13eTextureFlags14eTextureFormat>
 *   @0x173aa0 ldr r3, [pc, #0x74]
 *   @0x173aa4 mov r2, #1
 *   @0x173aa8 ldr r3, [pc, r3]
 *   @0x173aac ldr r3, [r3, #0x4]
 *   @0x173ab0 ldr r3, [r3, r6, lsl #2]
 *   @0x173ab4 strh r5, [r3, #4]
 *   @0x173ab8 strh r4, [r3, #6]
 *   @0x173abc strb r2, [r3, #0x10]
 *   @0x173ac0 cmp r0, #0
 *   @0x173ac4 beq 0x173afc <_Z23GR_Texture_Create_Emptyiibbi+0xd8>
 *   @0x173ac8 vmov.f32 s15, #1.000000e+00
 *   @0x173acc vldr s12, [r0, #4]
 *   @0x173ad0 vcvt.f32.s32 s14, s12
 *   @0x173ad4 vldr s12, [r0, #8]
 *   @0x173ad8 str r0, [r3]
 *   @0x173adc mov r0, r6
 *   @0x173ae0 vcvt.f32.s32 s13, s12
 *   @0x173ae4 vdiv.f32 s14, s15, s14
 *   @0x173ae8 vdiv.f32 s15, s15, s13
 *   @0x173aec vstr s14, [r3, #8]
 *   @0x173af0 vstr s15, [r3, #12]
 *   @0x173af4 add sp, sp, #12
 *   @0x173af8 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x173afc mov r1, #1065353216
 *   @0x173b00 str r0, [r3]
 *   @0x173b04 str r1, [r3, #0x8]
 *   @0x173b08 mov r0, r6
 *   @0x173b0c str r1, [r3, #0xc]
 *   @0x173b10 add sp, sp, #12
 *   @0x173b14 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x173b18 eoreq r10, r7, r4, ror #22
 *   @0x173b1c eoreq r9, r7, r4, ror lr
 *
 * ══ §24/56 RTree<CInstance*, int, float, 6, 2>::RemoveRect  0x1cd87c  size 252  63 条（0x1cd87c..0x1cd978）
 * @func 0x1cd87c 0x1cd978  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: RTree<CInstance*, int, float, 6, 2>::RemoveRectRec(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node*, RTree<CInstance*, int, float, 6, 2>::ListNode**) / RTree<CInstance*, int, float, 6, 2>::RemoveRect(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node**)+0x80 / RTree<CInstance*, int, float, 6, 2>::InsertRect(RTree<CInstance*, int, float, 6, 2>::Branch const&, RTree<CInstance*, int, float, 6, 2>::Node**, int) / operator delete(void*) / RTree<CInstance*, int, float, 6, 2>::RemoveRect(RTree<CInstance*, int, float, 6, 2>::Rect*, CInstance* const&, RTree<CInstance*, int, float, 6, 2>::Node**)+0xc0
 * 字段偏移 top8: 0x4×6 / 0xc×4 / 0x10×4 / 0x-4×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1cd87c push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x1cd880 sub sp, sp, #20
 *   @0x1cd884 add r12, sp, #16
 *   @0x1cd888 mov lr, #0
 *   @0x1cd88c mov r8, r3
 *   @0x1cd890 ldr r3, [r3]
 *   @0x1cd894 str lr, [r12, #-0x4]!
 *   @0x1cd898 mov r7, r0
 *   @0x1cd89c str r12, [sp]
 *   @0x1cd8a0 bl 0x1ccb94 <_ZN5RTreeIP9CInstanceifLi6ELi2EE13RemoveRectRecEPNS2_4RectERKS1_PNS2_4NodeEPPNS2_8ListNodeE>
 *   @0x1cd8a4 subs r9, r0, #0
 *   @0x1cd8a8 bne 0x1cd93c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xc0>
 *   @0x1cd8ac ldr r3, [sp, #0xc]
 *   @0x1cd8b0 cmp r3, #0
 *   @0x1cd8b4 beq 0x1cd92c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xb0>
 *   @0x1cd8b8 ldr r6, [r3, #0x4]
 *   @0x1cd8bc ldr r2, [r6]
 *   @0x1cd8c0 cmp r2, #0
 *   @0x1cd8c4 addgt r5, r6, #8
 *   @0x1cd8c8 movgt r4, #0
 *   @0x1cd8cc ble 0x1cd8fc <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x80>
 *   @0x1cd8d0 mov r1, r5
 *   @0x1cd8d4 mov r0, r7
 *   @0x1cd8d8 mov r2, r8
 *   @0x1cd8dc ldr r3, [r6, #0x4]
 *   @0x1cd8e0 bl 0x1cd700 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10InsertRectERKNS2_6BranchEPPNS2_4NodeEi>
 *   @0x1cd8e4 ldr r1, [r6]
 *   @0x1cd8e8 add r4, r4, #1
 *   @0x1cd8ec add r5, r5, #24
 *   @0x1cd8f0 cmp r1, r4
 *   @0x1cd8f4 bgt 0x1cd8d0 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x54>
 *   @0x1cd8f8 ldr r3, [sp, #0xc]
 *   @0x1cd8fc ldr r2, [r7, #0x4]
 *   @0x1cd900 mov r0, r3
 *   @0x1cd904 ldr r12, [r3]
 *   @0x1cd908 ldr r3, [r3, #0x4]
 *   @0x1cd90c ldr r1, [r2, #0x10]
 *   @0x1cd910 str r12, [sp, #0xc]
 *   @0x1cd914 str r3, [r2, #0x10]
 *   @0x1cd918 str r1, [r3]
 *   @0x1cd91c bl 0x27d1d0 <_ZdlPv>
 *   @0x1cd920 ldr r3, [sp, #0xc]
 *   @0x1cd924 cmp r3, #0
 *   @0x1cd928 bne 0x1cd8b8 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0x3c>
 *   @0x1cd92c ldr r3, [r8]
 *   @0x1cd930 ldr r2, [r3]
 *   @0x1cd934 cmp r2, #1
 *   @0x1cd938 beq 0x1cd948 <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xcc>
 *   @0x1cd93c mov r0, r9
 *   @0x1cd940 add sp, sp, #20
 *   @0x1cd944 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x1cd948 ldr r2, [r3, #0x4]
 *   @0x1cd94c cmp r2, #0
 *   @0x1cd950 ble 0x1cd93c <_ZN5RTreeIP9CInstanceifLi6ELi2EE10RemoveRectEPNS2_4RectERKS1_PPNS2_4NodeE+0xc0>
 *   @0x1cd954 ldr r2, [r7, #0x4]
 *   @0x1cd958 ldr r1, [r3, #0x18]
 *   @0x1cd95c ldr r0, [r2, #0x10]
 *   @0x1cd960 str r3, [r2, #0x10]
 *   @0x1cd964 str r0, [r3]
 *   @0x1cd968 mov r0, r9
 *   @0x1cd96c str r1, [r8]
 *   @0x1cd970 add sp, sp, #20
 *   @0x1cd974 pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ §25/56 lshift_D2A  0x23d6cc  size 252  63 条（0x23d6cc..0x23d7c8）
 * @func 0x23d6cc 0x23d7c8  size 252  63 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: lshift_D2A+0x3c / Balloc_D2A / lshift_D2A+0x70 / lshift_D2A+0x90 / Bfree_D2A / lshift_D2A+0xc0
 * 字段偏移 top8: 0x4×9 / 0x10×3 / 0x8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23d6cc push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x23d6d0 asr r5, r1, #5
 *   @0x23d6d4 ldr r7, [r0, #0x10]
 *   @0x23d6d8 mov r6, r0
 *   @0x23d6dc ldr r3, [r0, #0x8]
 *   @0x23d6e0 mov r9, r1
 *   @0x23d6e4 add r7, r5, r7
 *   @0x23d6e8 ldr r0, [r0, #0x4]
 *   @0x23d6ec add r4, r7, #1
 *   @0x23d6f0 cmp r4, r3
 *   @0x23d6f4 ble 0x23d708 <lshift_D2A+0x3c>
 *   @0x23d6f8 lsl r3, r3, #1
 *   @0x23d6fc add r0, r0, #1
 *   @0x23d700 cmp r4, r3
 *   @0x23d704 bgt 0x23d6f8 <lshift_D2A+0x2c>
 *   @0x23d708 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23d70c cmp r5, #0
 *   @0x23d710 mov r8, r0
 *   @0x23d714 add r2, r0, #20
 *   @0x23d718 ble 0x23d73c <lshift_D2A+0x70>
 *   @0x23d71c mov r3, #0
 *   @0x23d720 mov r12, r2
 *   @0x23d724 mov r0, r3
 *   @0x23d728 add r3, r3, #1
 *   @0x23d72c str r0, [r12], #4
 *   @0x23d730 cmp r3, r5
 *   @0x23d734 bne 0x23d728 <lshift_D2A+0x5c>
 *   @0x23d738 add r2, r2, r3, lsl #2
 *   @0x23d73c ldr r0, [r6, #0x10]
 *   @0x23d740 ands r1, r9, #31
 *   @0x23d744 add r3, r6, #20
 *   @0x23d748 add r0, r3, r0, lsl #2
 *   @0x23d74c beq 0x23d7a4 <lshift_D2A+0xd8>
 *   @0x23d750 rsb r5, r1, #32
 *   @0x23d754 mov lr, #0
 *   @0x23d758 b 0x23d760 <lshift_D2A+0x94>
 *   @0x23d75c mov r2, r12
 *   @0x23d760 ldr r9, [r3]
 *   @0x23d764 mov r12, r2
 *   @0x23d768 orr lr, lr, r9, lsl r1
 *   @0x23d76c str lr, [r12], #4
 *   @0x23d770 ldr lr, [r3], #4
 *   @0x23d774 cmp r3, r0
 *   @0x23d778 lsr lr, lr, r5
 *   @0x23d77c blo 0x23d75c <lshift_D2A+0x90>
 *   @0x23d780 cmp lr, #0
 *   @0x23d784 str lr, [r2, #0x4]
 *   @0x23d788 addne r4, r7, #2
 *   @0x23d78c mov r0, r6
 *   @0x23d790 sub r4, r4, #1
 *   @0x23d794 str r4, [r8, #0x10]
 *   @0x23d798 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23d79c mov r0, r8
 *   @0x23d7a0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x23d7a4 ldr r1, [r3], #4
 *   @0x23d7a8 cmp r0, r3
 *   @0x23d7ac str r1, [r2], #4
 *   @0x23d7b0 bls 0x23d78c <lshift_D2A+0xc0>
 *   @0x23d7b4 ldr r1, [r3], #4
 *   @0x23d7b8 cmp r0, r3
 *   @0x23d7bc str r1, [r2], #4
 *   @0x23d7c0 bhi 0x23d7a4 <lshift_D2A+0xd8>
 *   @0x23d7c4 b 0x23d78c <lshift_D2A+0xc0>
 *
 * ══ §26/56 _RefThing<char const*>::remove  0xdc42c  size 248  62 条（0xdc42c..0xdc524）
 * @func 0xdc42c 0xdc524  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / _RefThing<char const*>::dec()
 * 字段偏移 top8: 0x4×8 / 0x8×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xdc42c push {r3, r4, r5, lr}
 *   @0xdc430 subs r4, r0, #0
 *   @0xdc434 beq 0xdc454 <_ZN9_RefThingIPKcE6removeEPS2_+0x28>
 *   @0xdc438 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xdc43c ldr r5, [r4, #0x4]
 *   @0xdc440 sub r5, r5, #1
 *   @0xdc444 str r5, [r4, #0x4]
 *   @0xdc448 cmp r5, #0
 *   @0xdc44c beq 0xdc45c <_ZN9_RefThingIPKcE6removeEPS2_+0x30>
 *   @0xdc450 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xdc454 mov r0, #0
 *   @0xdc458 pop {r3, r4, r5, pc}
 *   @0xdc45c ldr r0, [r4]
 *   @0xdc460 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc464 str r5, [r4]
 *   @0xdc468 str r5, [r4, #0x8]
 *   @0xdc46c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xdc470 ldr r5, [r4, #0x4]
 *   @0xdc474 sub r5, r5, #1
 *   @0xdc478 str r5, [r4, #0x4]
 *   @0xdc47c cmp r5, #0
 *   @0xdc480 beq 0xdc494 <_ZN9_RefThingIPKcE6removeEPS2_+0x68>
 *   @0xdc484 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xdc488 mov r0, r4
 *   @0xdc48c bl 0x27d1d0 <_ZdlPv>
 *   @0xdc490 b 0xdc450 <_ZN9_RefThingIPKcE6removeEPS2_+0x24>
 *   @0xdc494 ldr r0, [r4]
 *   @0xdc498 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc49c str r5, [r4]
 *   @0xdc4a0 str r5, [r4, #0x8]
 *   @0xdc4a4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xdc4a8 ldr r5, [r4, #0x4]
 *   @0xdc4ac sub r5, r5, #1
 *   @0xdc4b0 str r5, [r4, #0x4]
 *   @0xdc4b4 cmp r5, #0
 *   @0xdc4b8 beq 0xdc4cc <_ZN9_RefThingIPKcE6removeEPS2_+0xa0>
 *   @0xdc4bc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xdc4c0 mov r0, r4
 *   @0xdc4c4 bl 0x27d1d0 <_ZdlPv>
 *   @0xdc4c8 b 0xdc484 <_ZN9_RefThingIPKcE6removeEPS2_+0x58>
 *   @0xdc4cc ldr r0, [r4]
 *   @0xdc4d0 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc4d4 str r5, [r4]
 *   @0xdc4d8 str r5, [r4, #0x8]
 *   @0xdc4dc bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0xdc4e0 ldr r5, [r4, #0x4]
 *   @0xdc4e4 sub r5, r5, #1
 *   @0xdc4e8 str r5, [r4, #0x4]
 *   @0xdc4ec cmp r5, #0
 *   @0xdc4f0 bne 0xdc514 <_ZN9_RefThingIPKcE6removeEPS2_+0xe8>
 *   @0xdc4f4 ldr r0, [r4]
 *   @0xdc4f8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xdc4fc mov r0, r4
 *   @0xdc500 str r5, [r4]
 *   @0xdc504 str r5, [r4, #0x8]
 *   @0xdc508 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0xdc50c mov r0, r4
 *   @0xdc510 bl 0x27d1d0 <_ZdlPv>
 *   @0xdc514 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0xdc518 mov r0, r4
 *   @0xdc51c bl 0x27d1d0 <_ZdlPv>
 *   @0xdc520 b 0xdc4bc <_ZN9_RefThingIPKcE6removeEPS2_+0x90>
 *
 * ══ §27/56 ov_clear  0x230ec4  size 248  62 条（0x230ec4..0x230fbc）
 * @func 0x230ec4 0x230fbc  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb655c×6 / vorbis_block_clear / vorbis_dsp_clear / ogg_stream_clear / ogg_sync_clear / 0xb65b0 / ov_clear+0xe8 / vorbis_info_clear
 * 字段偏移 top8: 0x48×2 / 0x34×2 / 0x4c×2 / 0x3c×1 / 0x44×1 / 0x40×1 / 0x38×1 / 0x290×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x230ec4 push {r3, r4, r5, lr}
 *   @0x230ec8 subs r4, r0, #0
 *   @0x230ecc beq 0x230f74 <ov_clear+0xb0>
 *   @0x230ed0 add r0, r4, #560
 *   @0x230ed4 bl 0x227208 <vorbis_block_clear>
 *   @0x230ed8 add r0, r4, #480
 *   @0x230edc bl 0x2272ac <vorbis_dsp_clear>
 *   @0x230ee0 add r0, r4, #120
 *   @0x230ee4 bl 0x234150 <ogg_stream_clear>
 *   @0x230ee8 ldr r0, [r4, #0x48]
 *   @0x230eec cmp r0, #0
 *   @0x230ef0 beq 0x230f00 <ov_clear+0x3c>
 *   @0x230ef4 ldr r3, [r4, #0x34]
 *   @0x230ef8 cmp r3, #0
 *   @0x230efc bne 0x230f7c <ov_clear+0xb8>
 *   @0x230f00 ldr r0, [r4, #0x3c]
 *   @0x230f04 cmp r0, #0
 *   @0x230f08 beq 0x230f10 <ov_clear+0x4c>
 *   @0x230f0c bl 0xb655c <free@plt>
 *   @0x230f10 ldr r0, [r4, #0x44]
 *   @0x230f14 cmp r0, #0
 *   @0x230f18 beq 0x230f20 <ov_clear+0x5c>
 *   @0x230f1c bl 0xb655c <free@plt>
 *   @0x230f20 ldr r0, [r4, #0x40]
 *   @0x230f24 cmp r0, #0
 *   @0x230f28 beq 0x230f30 <ov_clear+0x6c>
 *   @0x230f2c bl 0xb655c <free@plt>
 *   @0x230f30 ldr r0, [r4, #0x38]
 *   @0x230f34 cmp r0, #0
 *   @0x230f38 beq 0x230f40 <ov_clear+0x7c>
 *   @0x230f3c bl 0xb655c <free@plt>
 *   @0x230f40 add r0, r4, #24
 *   @0x230f44 bl 0x234b2c <ogg_sync_clear>
 *   @0x230f48 ldr r0, [r4]
 *   @0x230f4c cmp r0, #0
 *   @0x230f50 beq 0x230f64 <ov_clear+0xa0>
 *   @0x230f54 ldr r3, [r4, #0x290]
 *   @0x230f58 cmp r3, #0
 *   @0x230f5c beq 0x230f64 <ov_clear+0xa0>
 *   @0x230f60 blx r3
 *   @0x230f64 mov r0, r4
 *   @0x230f68 mov r1, #0
 *   @0x230f6c mov r2, #664
 *   @0x230f70 bl 0xb65b0 <memset@plt>
 *   @0x230f74 mov r0, #0
 *   @0x230f78 pop {r3, r4, r5, pc}
 *   @0x230f7c ble 0x230fac <ov_clear+0xe8>
 *   @0x230f80 mov r5, #0
 *   @0x230f84 add r0, r0, r5, lsl #5
 *   @0x230f88 bl 0x22ad10 <vorbis_info_clear>
 *   @0x230f8c ldr r0, [r4, #0x4c]
 *   @0x230f90 add r0, r0, r5, lsl #4
 *   @0x230f94 add r5, r5, #1
 *   @0x230f98 bl 0x22ac4c <vorbis_comment_clear>
 *   @0x230f9c ldr r3, [r4, #0x34]
 *   @0x230fa0 ldr r0, [r4, #0x48]
 *   @0x230fa4 cmp r3, r5
 *   @0x230fa8 bgt 0x230f84 <ov_clear+0xc0>
 *   @0x230fac bl 0xb655c <free@plt>
 *   @0x230fb0 ldr r0, [r4, #0x4c]
 *   @0x230fb4 bl 0xb655c <free@plt>
 *   @0x230fb8 b 0x230f00 <ov_clear+0x3c>
 *
 * ══ §28/56 anon_234238  0x234238  size 248  62 条（0x234238..0x234330）
 * @func 0x234238 0x234330  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6c28×3 / ogg_stream_clear×2 / anon_234238+0x24 / anon_234238+0x90
 * 字段偏移 top8: 0x18×4 / 0x4×2 / 0x10×2 / 0x14×2 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234238 push {r3, r4, r5, lr}
 *   @0x23423c mov r5, r1
 *   @0x234240 ldmib r0, {r1, r3}
 *   @0x234244 mov r4, r0
 *   @0x234248 add r3, r5, r3
 *   @0x23424c cmp r1, r3
 *   @0x234250 ble 0x23425c <ogg_stream_init+0xb8>
 *   @0x234254 mov r0, #0
 *   @0x234258 pop {r3, r4, r5, pc}
 *   @0x23425c add r1, r1, r5
 *   @0x234260 ldr r0, [r0]
 *   @0x234264 add r1, r1, #1024
 *   @0x234268 bl 0xb6c28 <realloc@plt>
 *   @0x23426c cmp r0, #0
 *   @0x234270 beq 0x234290 <ogg_stream_init+0xec>
 *   @0x234274 ldr r3, [r4, #0x4]
 *   @0x234278 add r5, r5, #1024
 *   @0x23427c str r0, [r4]
 *   @0x234280 mov r0, #0
 *   @0x234284 add r5, r3, r5
 *   @0x234288 str r5, [r4, #0x4]
 *   @0x23428c pop {r3, r4, r5, pc}
 *   @0x234290 mov r0, r4
 *   @0x234294 bl 0x234150 <ogg_stream_clear>
 *   @0x234298 mvn r0, #0
 *   @0x23429c pop {r3, r4, r5, pc}
 *   @0x2342a0 ldr r2, [r0, #0x1c]
 *   @0x2342a4 push {r3, r4, r5, lr}
 *   @0x2342a8 add r2, r1, r2
 *   @0x2342ac ldr r3, [r0, #0x18]
 *   @0x2342b0 mov r4, r0
 *   @0x2342b4 mov r5, r1
 *   @0x2342b8 cmp r3, r2
 *   @0x2342bc ble 0x2342c8 <ogg_stream_init+0x124>
 *   @0x2342c0 mov r0, #0
 *   @0x2342c4 pop {r3, r4, r5, pc}
 *   @0x2342c8 add r3, r3, r1
 *   @0x2342cc ldr r0, [r0, #0x10]
 *   @0x2342d0 add r1, r3, #32
 *   @0x2342d4 lsl r1, r1, #2
 *   @0x2342d8 bl 0xb6c28 <realloc@plt>
 *   @0x2342dc cmp r0, #0
 *   @0x2342e0 beq 0x234324 <ogg_stream_init+0x180>
 *   @0x2342e4 ldr r1, [r4, #0x18]
 *   @0x2342e8 str r0, [r4, #0x10]
 *   @0x2342ec add r1, r5, r1
 *   @0x2342f0 ldr r0, [r4, #0x14]
 *   @0x2342f4 add r1, r1, #32
 *   @0x2342f8 lsl r1, r1, #3
 *   @0x2342fc bl 0xb6c28 <realloc@plt>
 *   @0x234300 cmp r0, #0
 *   @0x234304 beq 0x234324 <ogg_stream_init+0x180>
 *   @0x234308 ldr r3, [r4, #0x18]
 *   @0x23430c add r5, r5, #32
 *   @0x234310 str r0, [r4, #0x14]
 *   @0x234314 mov r0, #0
 *   @0x234318 add r5, r3, r5
 *   @0x23431c str r5, [r4, #0x18]
 *   @0x234320 pop {r3, r4, r5, pc}
 *   @0x234324 mov r0, r4
 *   @0x234328 bl 0x234150 <ogg_stream_clear>
 *   @0x23432c mvn r0, #0
 *
 * ══ §29/56 b2ParticleSystem::~b2ParticleSystem  0x2d50c8  size 248  62 条（0x2d50c8..0x2d51c0）
 * @func 0x2d50c8 0x2d51c0  size 248  62 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)×11
 * 字段偏移 top8: 0xd4×11 / 0x28×9 / 0x30×1 / 0x38×1 / 0x40×1 / 0x54×1 / 0x60×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d50c8 push {r4, lr}
 *   @0x2d50cc mov r4, r0
 *   @0x2d50d0 ldr r0, [r0, #0xd4]
 *   @0x2d50d4 cmp r0, #0
 *   @0x2d50d8 beq 0x2d51b8 <_ZN16b2ParticleSystemD2Ev+0xf0>
 *   @0x2d50dc ldr r2, [r4, #0x28]
 *   @0x2d50e0 ldr r1, [r4, #0x30]
 *   @0x2d50e4 lsl r2, r2, #2
 *   @0x2d50e8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d50ec ldr r2, [r4, #0x28]
 *   @0x2d50f0 ldr r0, [r4, #0xd4]
 *   @0x2d50f4 ldr r1, [r4, #0x38]
 *   @0x2d50f8 lsl r2, r2, #3
 *   @0x2d50fc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5100 ldr r2, [r4, #0x28]
 *   @0x2d5104 ldr r0, [r4, #0xd4]
 *   @0x2d5108 ldr r1, [r4, #0x40]
 *   @0x2d510c lsl r2, r2, #3
 *   @0x2d5110 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5114 ldr r2, [r4, #0x28]
 *   @0x2d5118 ldr r0, [r4, #0xd4]
 *   @0x2d511c ldr r1, [r4, #0x54]
 *   @0x2d5120 lsl r2, r2, #2
 *   @0x2d5124 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5128 ldr r2, [r4, #0x28]
 *   @0x2d512c ldr r0, [r4, #0xd4]
 *   @0x2d5130 ldr r1, [r4, #0x60]
 *   @0x2d5134 lsl r2, r2, #2
 *   @0x2d5138 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d513c ldr r2, [r4, #0x28]
 *   @0x2d5140 ldr r0, [r4, #0xd4]
 *   @0x2d5144 ldr r1, [r4, #0x50]
 *   @0x2d5148 lsl r2, r2, #2
 *   @0x2d514c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5150 ldr r2, [r4, #0x28]
 *   @0x2d5154 ldr r0, [r4, #0xd4]
 *   @0x2d5158 ldr r1, [r4, #0x5c]
 *   @0x2d515c lsl r2, r2, #2
 *   @0x2d5160 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5164 ldr r2, [r4, #0x28]
 *   @0x2d5168 ldr r0, [r4, #0xd4]
 *   @0x2d516c ldr r1, [r4, #0x48]
 *   @0x2d5170 lsl r2, r2, #2
 *   @0x2d5174 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d5178 ldr r2, [r4, #0x28]
 *   @0x2d517c ldr r0, [r4, #0xd4]
 *   @0x2d5180 ldr r1, [r4, #0x4c]
 *   @0x2d5184 lsl r2, r2, #3
 *   @0x2d5188 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d518c ldr r2, [r4, #0x78]
 *   @0x2d5190 ldr r0, [r4, #0xd4]
 *   @0x2d5194 ldr r1, [r4, #0x7c]
 *   @0x2d5198 add r2, r2, r2, lsl #1
 *   @0x2d519c lsl r2, r2, #3
 *   @0x2d51a0 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d51a4 ldr r2, [r4, #0x6c]
 *   @0x2d51a8 ldr r0, [r4, #0xd4]
 *   @0x2d51ac ldr r1, [r4, #0x70]
 *   @0x2d51b0 lsl r2, r2, #3
 *   @0x2d51b4 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2d51b8 mov r0, r4
 *   @0x2d51bc pop {r4, pc}
 *
 * ══ §30/56 YYGetInt64  0xcea30  size 244  61 条（0xcea30..0xceb24）
 * @func 0xcea30 0xceb38  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: F_JS_ToNumber(RValue&, RValue&) / YYGetInt64(RValue const*, int) / __fixdfdi / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×5 / 0xc×1 / 0x34×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcea30 add r2, r0, r1, lsl #4
 *   @0xcea34 push {r4, r6, lr}
 *   @0xcea38 mov r6, r1
 *   @0xcea3c ldr r3, [r2, #0xc]
 *   @0xcea40 sub sp, sp, #20
 *   @0xcea44 bic r3, r3, #-16777216
 *   @0xcea48 cmp r3, #13
 *   @0xcea4c addls pc, pc, r3, lsl #2
 *   @0xcea50 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea54 b 0xceacc <_Z10YYGetInt64PK6RValuei+0x9c>
 *   @0xcea58 b 0xceaac <_Z10YYGetInt64PK6RValuei+0x7c>
 *   @0xcea5c b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea60 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea64 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea68 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea6c b 0xceaac <_Z10YYGetInt64PK6RValuei+0x7c>
 *   @0xcea70 b 0xcea9c <_Z10YYGetInt64PK6RValuei+0x6c>
 *   @0xcea74 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea78 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea7c b 0xcea8c <_Z10YYGetInt64PK6RValuei+0x5c>
 *   @0xcea80 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea84 b 0xceae0 <_Z10YYGetInt64PK6RValuei+0xb0>
 *   @0xcea88 b 0xceacc <_Z10YYGetInt64PK6RValuei+0x9c>
 *   @0xcea8c ldr r0, [r0, r1, lsl #4]
 *   @0xcea90 ldr r1, [r2, #0x4]
 *   @0xcea94 add sp, sp, #20
 *   @0xcea98 pop {r4, r6, pc}
 *   @0xcea9c ldr r0, [r0, r1, lsl #4]
 *   @0xceaa0 asr r1, r0, #31
 *   @0xceaa4 add sp, sp, #20
 *   @0xceaa8 pop {r4, r6, pc}
 *   @0xceaac mov r1, r2
 *   @0xceab0 mov r0, sp
 *   @0xceab4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0xceab8 mov r0, sp
 *   @0xceabc mov r1, #0
 *   @0xceac0 bl 0xcea30 <_Z10YYGetInt64PK6RValuei>
 *   @0xceac4 add sp, sp, #20
 *   @0xceac8 pop {r4, r6, pc}
 *   @0xceacc ldr r0, [r0, r1, lsl #4]
 *   @0xcead0 ldr r1, [r2, #0x4]
 *   @0xcead4 bl 0x3194a0 <__fixdfdi>
 *   @0xcead8 add sp, sp, #20
 *   @0xceadc pop {r4, r6, pc}
 *   @0xceae0 ldr r3, [pc, #0x34]
 *   @0xceae4 mov r0, r2
 *   @0xceae8 ldr r3, [pc, r3]
 *   @0xceaec ldr r4, [r3]
 *   @0xceaf0 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xceaf4 add r2, r6, #1
 *   @0xceaf8 mov r1, r4
 *   @0xceafc mov r3, r0
 *   @0xceb00 ldr r0, [pc, #0x18]
 *   @0xceb04 add r0, pc, r0
 *   @0xceb08 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xceb0c mov r0, #0
 *   @0xceb10 mov r1, #0
 *   @0xceb14 add sp, sp, #20
 *   @0xceb18 pop {r4, r6, pc}
 *   @0xceb1c eorseq pc, r1, r8, asr #32
 *   @0xceb20 .word 0x002638b8
 *
 * ══ §31/56 YYGetReal  0xceb24  size 244  61 条（0xceb24..0xcec18）
 * @func 0xceb24 0xcec18  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __floatdidf / F_JS_ToNumber(RValue&, RValue&) / KindName(RValue const*) / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×5 / 0xc×1 / 0x34×1 / 0x18×1
 * VFP 指令 3 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xceb24 add r2, r0, r1, lsl #4
 *   @0xceb28 push {r4, r5, lr}
 *   @0xceb2c mov r4, r1
 *   @0xceb30 ldr r3, [r2, #0xc]
 *   @0xceb34 sub sp, sp, #20
 *   @0xceb38 bic r3, r3, #-16777216
 *   @0xceb3c cmp r3, #13
 *   @0xceb40 addls pc, pc, r3, lsl #2
 *   @0xceb44 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb48 b 0xcebc4 <_Z9YYGetRealPK6RValuei+0xa0>
 *   @0xceb4c b 0xcebac <_Z9YYGetRealPK6RValuei+0x88>
 *   @0xceb50 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb54 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb58 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb5c b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb60 b 0xcebac <_Z9YYGetRealPK6RValuei+0x88>
 *   @0xceb64 b 0xceb94 <_Z9YYGetRealPK6RValuei+0x70>
 *   @0xceb68 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb6c b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb70 b 0xceb80 <_Z9YYGetRealPK6RValuei+0x5c>
 *   @0xceb74 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb78 b 0xcebd4 <_Z9YYGetRealPK6RValuei+0xb0>
 *   @0xceb7c b 0xcebc4 <_Z9YYGetRealPK6RValuei+0xa0>
 *   @0xceb80 ldr r0, [r0, r1, lsl #4]
 *   @0xceb84 ldr r1, [r2, #0x4]
 *   @0xceb88 bl 0x319164 <__floatdidf>
 *   @0xceb8c add sp, sp, #20
 *   @0xceb90 pop {r4, r5, pc}
 *   @0xceb94 ldr r0, [r0, r1, lsl #4]
 *   @0xceb98 vmov s15, r0
 *   @0xceb9c vcvt.f64.s32 d7, s15
 *   @0xceba0 vmov r0, r1, d7
 *   @0xceba4 add sp, sp, #20
 *   @0xceba8 pop {r4, r5, pc}
 *   @0xcebac mov r1, r2
 *   @0xcebb0 mov r0, sp
 *   @0xcebb4 bl 0x24cfac <_Z13F_JS_ToNumberR6RValueS0_>
 *   @0xcebb8 ldrd r0, r1, [sp]
 *   @0xcebbc add sp, sp, #20
 *   @0xcebc0 pop {r4, r5, pc}
 *   @0xcebc4 ldr r0, [r0, r1, lsl #4]
 *   @0xcebc8 ldr r1, [r2, #0x4]
 *   @0xcebcc add sp, sp, #20
 *   @0xcebd0 pop {r4, r5, pc}
 *   @0xcebd4 ldr r3, [pc, #0x34]
 *   @0xcebd8 mov r0, r2
 *   @0xcebdc ldr r3, [pc, r3]
 *   @0xcebe0 ldr r5, [r3]
 *   @0xcebe4 bl 0xce54c <_Z8KindNamePK6RValue>
 *   @0xcebe8 add r2, r4, #1
 *   @0xcebec mov r1, r5
 *   @0xcebf0 mov r3, r0
 *   @0xcebf4 ldr r0, [pc, #0x18]
 *   @0xcebf8 add r0, pc, r0
 *   @0xcebfc bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xcec00 mov r0, #0
 *   @0xcec04 mov r1, #0
 *   @0xcec08 add sp, sp, #20
 *   @0xcec0c pop {r4, r5, pc}
 *   @0xcec10 eorseq lr, r1, r4, asr pc
 *   @0xcec14 .word 0x002637fc
 *
 * ══ §32/56 YYStrBuilder::operator<<  0xd58c4  size 244  61 条（0xd58c4..0xd59b8）
 * @func 0xd58c4 0xd59b8  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: yyitoa(int, char*, int) / 0xb6538 / YYStrBuilder::operator<<(int)+0xb4 / YYAlloc(int) / 0xb65bc / YYFree(void const*) / 0xb65a4 / 0xb65d4
 * 字段偏移 top8: 0x8×4 / 0x4×3 / 0x104×2 / 0xe0×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd58c4 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0xd58c8 sub sp, sp, #268
 *   @0xd58cc ldr r5, [pc, #0xe0]
 *   @0xd58d0 add r6, sp, #4
 *   @0xd58d4 mov r4, r0
 *   @0xd58d8 mov r2, #10
 *   @0xd58dc ldr r5, [pc, r5]
 *   @0xd58e0 mov r0, r1
 *   @0xd58e4 mov r1, r6
 *   @0xd58e8 ldr r3, [r5]
 *   @0xd58ec str r3, [sp, #0x104]
 *   @0xd58f0 bl 0xd58c0 <_Z6yyitoaiPci>
 *   @0xd58f4 mov r0, r6
 *   @0xd58f8 bl 0xb6538 <strlen@plt>
 *   @0xd58fc ldr r2, [r4, #0x8]
 *   @0xd5900 ldr r3, [r4, #0x4]
 *   @0xd5904 add r1, r0, #1
 *   @0xd5908 mov r7, r0
 *   @0xd590c mvn r0, r2
 *   @0xd5910 add r0, r3, r0
 *   @0xd5914 cmp r1, r0
 *   @0xd5918 ble 0xd5978 <_ZN12YYStrBuilderlsEi+0xb4>
 *   @0xd591c cmp r3, #0
 *   @0xd5920 add r2, r1, r2
 *   @0xd5924 ldr r9, [r4]
 *   @0xd5928 moveq r3, r1
 *   @0xd592c add r3, r3, r3, lsl #1
 *   @0xd5930 add r3, r3, r3, lsr #31
 *   @0xd5934 asr r8, r3, #1
 *   @0xd5938 cmp r8, r2
 *   @0xd593c addlt r2, r2, r2, lsl #1
 *   @0xd5940 addlt r2, r2, r2, lsr #31
 *   @0xd5944 asrlt r8, r2, #1
 *   @0xd5948 mov r0, r8
 *   @0xd594c bl 0xcef4c <_Z7YYAlloci>
 *   @0xd5950 ldr r2, [r4, #0x4]
 *   @0xd5954 mov r1, r9
 *   @0xd5958 str r0, [r4]
 *   @0xd595c bl 0xb65bc <memcpy@plt>
 *   @0xd5960 cmp r9, #0
 *   @0xd5964 str r8, [r4, #0x4]
 *   @0xd5968 beq 0xd5974 <_ZN12YYStrBuilderlsEi+0xb0>
 *   @0xd596c mov r0, r9
 *   @0xd5970 bl 0xcef90 <_Z6YYFreePKv>
 *   @0xd5974 ldr r2, [r4, #0x8]
 *   @0xd5978 ldr r0, [r4]
 *   @0xd597c mov r1, r6
 *   @0xd5980 add r0, r0, r2
 *   @0xd5984 bl 0xb65a4 <strcpy@plt>
 *   @0xd5988 ldr r1, [sp, #0x104]
 *   @0xd598c ldr r2, [r5]
 *   @0xd5990 mov r0, r4
 *   @0xd5994 ldr r3, [r4, #0x8]
 *   @0xd5998 cmp r1, r2
 *   @0xd599c add r7, r3, r7
 *   @0xd59a0 str r7, [r4, #0x8]
 *   @0xd59a4 bne 0xd59b0 <_ZN12YYStrBuilderlsEi+0xec>
 *   @0xd59a8 add sp, sp, #268
 *   @0xd59ac pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0xd59b0 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xd59b4 eorseq r8, r1, r4, ror r0
 *
 * ══ §33/56 Shader_Set_Uniform_FA  0x188a9c  size 244  61 条（0x188a9c..0x188b90）
 * @func 0x188a9c 0x188b90  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __divsi3×2 / Shader_Set_Uniform_FA(int, int, float*)+0x24 / Shader_Get(int) / Shader_Set_Uniform_FA(int, int, float*)+0xbc / Shader_Set_Uniform_Matrix(int, int, int, float*) / Shader_Set_Uniform_F(int, int, int, float*)
 * 字段偏移 top8: 0x4×2 / 0xe4×1 / 0xb4×1 / 0x64×1 / 0x7c×1 / 0x78×1 / 0x10×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x188a9c ldr r12, [pc, #0xe4]
 *   @0x188aa0 push {r4, r5, r6, r7, r8, lr}
 *   @0x188aa4 ldr r12, [pc, r12]
 *   @0x188aa8 mov r5, r0
 *   @0x188aac mov r6, r1
 *   @0x188ab0 ldr r4, [r12]
 *   @0x188ab4 mov r7, r2
 *   @0x188ab8 cmp r4, #1
 *   @0x188abc beq 0x188ac8 <_Z21Shader_Set_Uniform_FAiiPf+0x2c>
 *   @0x188ac0 mov r0, #0
 *   @0x188ac4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x188ac8 cmp r0, #0
 *   @0x188acc blt 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24>
 *   @0x188ad0 ldr r12, [pc, #0xb4]
 *   @0x188ad4 ldr r12, [pc, r12]
 *   @0x188ad8 ldr r3, [r12]
 *   @0x188adc cmp r3, #0
 *   @0x188ae0 beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24>
 *   @0x188ae4 ldr r0, [r3, #0x64]
 *   @0x188ae8 bl 0x187e70 <_Z10Shader_Geti>
 *   @0x188aec cmp r0, #0
 *   @0x188af0 beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24>
 *   @0x188af4 ldr r3, [r0, #0x7c]
 *   @0x188af8 cmp r5, r3
 *   @0x188afc bge 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24>
 *   @0x188b00 ldr r3, [r0, #0x78]
 *   @0x188b04 rsb r5, r5, r5, lsl #3
 *   @0x188b08 adds r5, r3, r5, lsl #2
 *   @0x188b0c beq 0x188ac0 <_Z21Shader_Set_Uniform_FAiiPf+0x24>
 *   @0x188b10 ldr r8, [r5, #0x10]
 *   @0x188b14 cmp r8, #1
 *   @0x188b18 ble 0x188b58 <_Z21Shader_Set_Uniform_FAiiPf+0xbc>
 *   @0x188b1c ldr r1, [r5, #0x14]
 *   @0x188b20 cmp r1, #0
 *   @0x188b24 beq 0x188b38 <_Z21Shader_Set_Uniform_FAiiPf+0x9c>
 *   @0x188b28 mov r0, r6
 *   @0x188b2c bl 0x318d10 <__divsi3>
 *   @0x188b30 subs r2, r0, #0
 *   @0x188b34 bne 0x188b40 <_Z21Shader_Set_Uniform_FAiiPf+0xa4>
 *   @0x188b38 mov r0, r4
 *   @0x188b3c pop {r4, r5, r6, r7, r8, pc}
 *   @0x188b40 ldr r0, [r5, #0x4]
 *   @0x188b44 mov r1, r8
 *   @0x188b48 mov r3, r7
 *   @0x188b4c bl 0x18829c <_Z25Shader_Set_Uniform_MatrixiiiPf>
 *   @0x188b50 mov r0, r4
 *   @0x188b54 pop {r4, r5, r6, r7, r8, pc}
 *   @0x188b58 ldr r8, [r5, #0xc]
 *   @0x188b5c mov r0, r6
 *   @0x188b60 ldr r5, [r5, #0x4]
 *   @0x188b64 mov r1, r8
 *   @0x188b68 bl 0x318d10 <__divsi3>
 *   @0x188b6c mov r1, r8
 *   @0x188b70 mov r3, r7
 *   @0x188b74 mov r2, r0
 *   @0x188b78 mov r0, r5
 *   @0x188b7c bl 0x188164 <_Z20Shader_Set_Uniform_FiiiPf>
 *   @0x188b80 mov r0, r4
 *   @0x188b84 pop {r4, r5, r6, r7, r8, pc}
 *   @0x188b88 eoreq r7, r6, r4, ror #18
 *   @0x188b8c eoreq r7, r6, r4, lsr #19
 *
 * ══ §34/56 IO_Update  0x18d288  size 244  61 条（0x18d288..0x18d37c）
 * @func 0x18d288 0x18d37c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Timing_Time / IO_UpdateM() / GamepadUpdateM() / IO_Update()+0x38
 * 字段偏移 top8: 0xd8×1 / 0xc8×1 / 0xc4×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18d288 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18d28c ldr r3, [pc, #0xd8]
 *   @0x18d290 ldr r3, [pc, r3]
 *   @0x18d294 ldrb r3, [r3]
 *   @0x18d298 cmp r3, #0
 *   @0x18d29c beq 0x18d328 <_Z9IO_Updatev+0xa0>
 *   @0x18d2a0 ldr r9, [pc, #0xc8]
 *   @0x18d2a4 mov r5, #0
 *   @0x18d2a8 ldr r6, [pc, #0xc4]
 *   @0x18d2ac mov r4, r5
 *   @0x18d2b0 add r9, pc, r9
 *   @0x18d2b4 ldr r6, [pc, r6]
 *   @0x18d2b8 add r7, r9, #3072
 *   @0x18d2bc b 0x18d2d0 <_Z9IO_Updatev+0x48>
 *   @0x18d2c0 add r4, r4, #4
 *   @0x18d2c4 add r5, r5, #8
 *   @0x18d2c8 cmp r4, #40
 *   @0x18d2cc beq 0x18d328 <_Z9IO_Updatev+0xa0>
 *   @0x18d2d0 ldr r3, [r6, r4]
 *   @0x18d2d4 add r2, r7, #4
 *   @0x18d2d8 add r8, r6, r4
 *   @0x18d2dc ldr r1, [r4, r2]
 *   @0x18d2e0 tst r3, #1
 *   @0x18d2e4 str r3, [r4, r2]
 *   @0x18d2e8 eor r3, r1, r3
 *   @0x18d2ec beq 0x18d2c0 <_Z9IO_Updatev+0x38>
 *   @0x18d2f0 tst r3, #1
 *   @0x18d2f4 beq 0x18d2c0 <_Z9IO_Updatev+0x38>
 *   @0x18d2f8 bl 0x215148 <Timing_Time>
 *   @0x18d2fc add r12, r9, #3120
 *   @0x18d300 ldr lr, [pc, #0x70]
 *   @0x18d304 ldrd r2, r3, [r5, r12]
 *   @0x18d308 cmp r0, r2
 *   @0x18d30c sbcs r10, r1, r3
 *   @0x18d310 bge 0x18d338 <_Z9IO_Updatev+0xb0>
 *   @0x18d314 strd r0, r1, [r5, r12]
 *   @0x18d318 add r4, r4, #4
 *   @0x18d31c add r5, r5, #8
 *   @0x18d320 cmp r4, #40
 *   @0x18d324 bne 0x18d2d0 <_Z9IO_Updatev+0x48>
 *   @0x18d328 bl 0x18f094 <_Z10IO_UpdateMv>
 *   @0x18d32c bl 0x190ac0 <_Z14GamepadUpdateMv>
 *   @0x18d330 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x18d334 b 0x18cfa4 <_Z18ProcessVirtualKeysv>
 *   @0x18d338 ldr lr, [pc, lr]
 *   @0x18d33c mov r10, r0
 *   @0x18d340 mov r11, r1
 *   @0x18d344 subs r10, r10, r2
 *   @0x18d348 sbc r11, r11, r3
 *   @0x18d34c ldrd r2, r3, [lr]
 *   @0x18d350 cmp r10, r2
 *   @0x18d354 sbcs lr, r11, r3
 *   @0x18d358 movlt r3, #-2147483646
 *   @0x18d35c strlt r3, [r8]
 *   @0x18d360 blt 0x18d2c0 <_Z9IO_Updatev+0x38>
 *   @0x18d364 strd r0, r1, [r5, r12]
 *   @0x18d368 b 0x18d318 <_Z9IO_Updatev+0x90>
 *   @0x18d36c eoreq r1, r6, r12, asr #15
 *   @0x18d370 eorseq r5, r10, r8, lsl sp
 *   @0x18d374 eoreq r3, r6, r8, ror r3
 *   @0x18d378 .word 0x002632f8
 *
 * ══ §35/56 Draw_Room_SetSize  0x1b29bc  size 244  61 条（0x1b29bc..0x1b2ab0）
 * @func 0x1b29bc 0x1b2ab0  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Graphics_DisplayWidth()×3 / Graphics_DisplayHeight()×3 / GR_Window_Get_Region_Width()×2 / Draw_Room_SetSize()+0x7c / Draw_Room_SetSize()+0x88 / GR_Window_Get_Region_Height()
 * 字段偏移 top8: 0x14×2 / 0xe4×1 / 0x44×1 / 0x48×1 / 0x1c×1 / 0x20×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b29bc push {r3, r4, r5, lr}
 *   @0x1b29c0 ldr r3, [pc, #0xe4]
 *   @0x1b29c4 ldr r3, [pc, r3]
 *   @0x1b29c8 ldr r12, [r3]
 *   @0x1b29cc ldrb r3, [r12, #0x44]
 *   @0x1b29d0 cmp r3, #0
 *   @0x1b29d4 beq 0x1b2a60 <_Z17Draw_Room_SetSizev+0xa4>
 *   @0x1b29d8 mov r5, #8
 *   @0x1b29dc mov r2, #0
 *   @0x1b29e0 mov r4, r5
 *   @0x1b29e4 ldr r3, [r12, #0x48]
 *   @0x1b29e8 add r2, r2, #1
 *   @0x1b29ec add r12, r12, #4
 *   @0x1b29f0 ldrb lr, [r3]
 *   @0x1b29f4 cmp lr, #0
 *   @0x1b29f8 beq 0x1b2a24 <_Z17Draw_Room_SetSizev+0x68>
 *   @0x1b29fc ldr lr, [r3, #0x1c]
 *   @0x1b2a00 ldr r0, [r3, #0x14]
 *   @0x1b2a04 ldr r1, [r3, #0x20]
 *   @0x1b2a08 ldr r3, [r3, #0x18]
 *   @0x1b2a0c add r0, lr, r0
 *   @0x1b2a10 cmp r4, r0
 *   @0x1b2a14 movlt r4, r0
 *   @0x1b2a18 add r3, r1, r3
 *   @0x1b2a1c cmp r5, r3
 *   @0x1b2a20 movlt r5, r3
 *   @0x1b2a24 cmp r2, #8
 *   @0x1b2a28 bne 0x1b29e4 <_Z17Draw_Room_SetSizev+0x28>
 *   @0x1b2a2c bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x1b2a30 cmp r4, r0
 *   @0x1b2a34 bgt 0x1b2a74 <_Z17Draw_Room_SetSizev+0xb8>
 *   @0x1b2a38 bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x1b2a3c cmp r5, r0
 *   @0x1b2a40 bgt 0x1b2a88 <_Z17Draw_Room_SetSizev+0xcc>
 *   @0x1b2a44 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x1b2a48 cmp r0, r4
 *   @0x1b2a4c beq 0x1b2a9c <_Z17Draw_Room_SetSizev+0xe0>
 *   @0x1b2a50 mov r0, r4
 *   @0x1b2a54 mov r1, r5
 *   @0x1b2a58 pop {r3, r4, r5, lr}
 *   @0x1b2a5c b 0x1698ec <_Z17GR_D3D_Set_Regionii>
 *   @0x1b2a60 ldr r4, [r12, #0x10]
 *   @0x1b2a64 ldr r5, [r12, #0x14]
 *   @0x1b2a68 bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x1b2a6c cmp r4, r0
 *   @0x1b2a70 ble 0x1b2a38 <_Z17Draw_Room_SetSizev+0x7c>
 *   @0x1b2a74 bl 0x17db24 <_Z21Graphics_DisplayWidthv>
 *   @0x1b2a78 mov r4, r0
 *   @0x1b2a7c bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x1b2a80 cmp r5, r0
 *   @0x1b2a84 ble 0x1b2a44 <_Z17Draw_Room_SetSizev+0x88>
 *   @0x1b2a88 bl 0x17db38 <_Z22Graphics_DisplayHeightv>
 *   @0x1b2a8c mov r5, r0
 *   @0x1b2a90 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv>
 *   @0x1b2a94 cmp r0, r4
 *   @0x1b2a98 bne 0x1b2a50 <_Z17Draw_Room_SetSizev+0x94>
 *   @0x1b2a9c bl 0x17999c <_Z27GR_Window_Get_Region_Heightv>
 *   @0x1b2aa0 cmp r0, r5
 *   @0x1b2aa4 bne 0x1b2a50 <_Z17Draw_Room_SetSizev+0x94>
 *   @0x1b2aa8 pop {r3, r4, r5, pc}
 *   @0x1b2aac eoreq r10, r3, r4, ror #30
 *
 * ══ §36/56 _vorbis_window  0x233028  size 244  61 条（0x233028..0x23311c）
 * @func 0x233028 0x23311c  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _vorbis_window+0x40 / _vorbis_window+0x8c
 * 字段偏移 top8: 0x9c×1 / 0x78×1 / 0x68×1 / 0x5c×1 / 0x48×1 / 0x3c×1 / 0x30×1 / 0x24×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233028 cmp r0, #0
 *   @0x23302c bne 0x23308c <_vorbis_window+0x64>
 *   @0x233030 cmp r1, #256
 *   @0x233034 beq 0x2330ec <_vorbis_window+0xc4>
 *   @0x233038 ble 0x233068 <_vorbis_window+0x40>
 *   @0x23303c cmp r1, #1024
 *   @0x233040 beq 0x2330dc <_vorbis_window+0xb4>
 *   @0x233044 ble 0x2330b4 <_vorbis_window+0x8c>
 *   @0x233048 cmp r1, #2048
 *   @0x23304c beq 0x2330a4 <_vorbis_window+0x7c>
 *   @0x233050 cmp r1, #4096
 *   @0x233054 bne 0x23308c <_vorbis_window+0x64>
 *   @0x233058 ldr r0, [pc, #0x9c]
 *   @0x23305c add r0, pc, r0
 *   @0x233060 sub r0, r0, #112
 *   @0x233064 bx lr
 *   @0x233068 cmp r1, #64
 *   @0x23306c beq 0x2330cc <_vorbis_window+0xa4>
 *   @0x233070 cmp r1, #128
 *   @0x233074 beq 0x233094 <_vorbis_window+0x6c>
 *   @0x233078 cmp r1, #32
 *   @0x23307c bne 0x23308c <_vorbis_window+0x64>
 *   @0x233080 ldr r0, [pc, #0x78]
 *   @0x233084 add r0, pc, r0
 *   @0x233088 bx lr
 *   @0x23308c mov r0, #0
 *   @0x233090 bx lr
 *   @0x233094 ldr r0, [pc, #0x68]
 *   @0x233098 add r0, pc, r0
 *   @0x23309c add r0, r0, #384
 *   @0x2330a0 bx lr
 *   @0x2330a4 ldr r0, [pc, #0x5c]
 *   @0x2330a8 add r0, pc, r0
 *   @0x2330ac sub r0, r0, #120
 *   @0x2330b0 bx lr
 *   @0x2330b4 cmp r1, #512
 *   @0x2330b8 bne 0x23308c <_vorbis_window+0x64>
 *   @0x2330bc ldr r0, [pc, #0x48]
 *   @0x2330c0 add r0, pc, r0
 *   @0x2330c4 add r0, r0, #1920
 *   @0x2330c8 bx lr
 *   @0x2330cc ldr r0, [pc, #0x3c]
 *   @0x2330d0 add r0, pc, r0
 *   @0x2330d4 add r0, r0, #128
 *   @0x2330d8 bx lr
 *   @0x2330dc ldr r0, [pc, #0x30]
 *   @0x2330e0 add r0, pc, r0
 *   @0x2330e4 add r0, r0, #3968
 *   @0x2330e8 bx lr
 *   @0x2330ec ldr r0, [pc, #0x24]
 *   @0x2330f0 add r0, pc, r0
 *   @0x2330f4 add r0, r0, #896
 *   @0x2330f8 bx lr
 *   @0x2330fc andseq r1, r3, r12, asr #20
 *   @0x233100 andseq sp, r2, r4, lsr r10
 *   @0x233104 andseq sp, r2, r0, lsr #20
 *   @0x233108 andseq pc, r2, r8, lsl #20
 *   @0x23310c ldrsheq sp, [r2], -r8
 *   @0x233110 andseq sp, r2, r8, ror #19
 *   @0x233114 ldrsbeq sp, [r2], -r8
 *   @0x233118 andseq sp, r2, r8, asr #19
 *
 * ══ §37/56 rshift_D2A  0x23db50  size 244  61 条（0x23db50..0x23dc44）
 * @func 0x23db50 0x23dc44  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: rshift_D2A+0xec / rshift_D2A+0x44 / rshift_D2A+0x9c
 * 字段偏移 top8: 0x4×4 / 0x10×3 / 0x2×1 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23db50 ldr r2, [r0, #0x10]
 *   @0x23db54 asr r3, r1, #5
 *   @0x23db58 push {r4, r5, r6, r7, r8}
 *   @0x23db5c cmp r3, r2
 *   @0x23db60 add r8, r0, #20
 *   @0x23db64 bge 0x23dbec <rshift_D2A+0x9c>
 *   @0x23db68 ands r6, r1, #31
 *   @0x23db6c add r2, r8, r2, lsl #2
 *   @0x23db70 add r7, r8, r3, lsl #2
 *   @0x23db74 beq 0x23dc04 <rshift_D2A+0xb4>
 *   @0x23db78 ldr r12, [r8, r3, lsl #2]
 *   @0x23db7c add r3, r7, #4
 *   @0x23db80 cmp r2, r3
 *   @0x23db84 rsb r1, r6, #32
 *   @0x23db88 lsr r12, r12, r6
 *   @0x23db8c bls 0x23dc3c <rshift_D2A+0xec>
 *   @0x23db90 mov r4, r8
 *   @0x23db94 ldr r5, [r3]
 *   @0x23db98 orr r12, r12, r5, lsl r1
 *   @0x23db9c str r12, [r4], #4
 *   @0x23dba0 ldr r12, [r3], #4
 *   @0x23dba4 cmp r3, r2
 *   @0x23dba8 lsr r12, r12, r6
 *   @0x23dbac blo 0x23db94 <rshift_D2A+0x44>
 *   @0x23dbb0 rsb r3, r7, r2
 *   @0x23dbb4 sub r3, r3, #5
 *   @0x23dbb8 bic r3, r3, #3
 *   @0x23dbbc add r3, r3, #4
 *   @0x23dbc0 add r3, r8, r3
 *   @0x23dbc4 cmp r12, #0
 *   @0x23dbc8 str r12, [r3]
 *   @0x23dbcc addne r3, r3, #4
 *   @0x23dbd0 rsb r8, r8, r3
 *   @0x23dbd4 asr r8, r8, #2
 *   @0x23dbd8 cmp r8, #0
 *   @0x23dbdc str r8, [r0, #0x10]
 *   @0x23dbe0 beq 0x23dbf4 <rshift_D2A+0xa4>
 *   @0x23dbe4 pop {r4, r5, r6, r7, r8}
 *   @0x23dbe8 bx lr
 *   @0x23dbec mov r3, #0
 *   @0x23dbf0 str r3, [r0, #0x10]
 *   @0x23dbf4 mov r3, #0
 *   @0x23dbf8 str r3, [r0, #0x14]
 *   @0x23dbfc pop {r4, r5, r6, r7, r8}
 *   @0x23dc00 bx lr
 *   @0x23dc04 cmp r2, r7
 *   @0x23dc08 movhi r1, r8
 *   @0x23dc0c movhi r3, r7
 *   @0x23dc10 bls 0x23dbec <rshift_D2A+0x9c>
 *   @0x23dc14 ldr r12, [r3], #4
 *   @0x23dc18 cmp r2, r3
 *   @0x23dc1c str r12, [r1], #4
 *   @0x23dc20 bhi 0x23dc14 <rshift_D2A+0xc4>
 *   @0x23dc24 mvn r8, r7
 *   @0x23dc28 add r8, r8, r2
 *   @0x23dc2c bic r8, r8, #3
 *   @0x23dc30 add r8, r8, #4
 *   @0x23dc34 asr r8, r8, #2
 *   @0x23dc38 b 0x23dbd8 <rshift_D2A+0x88>
 *   @0x23dc3c mov r3, r8
 *   @0x23dc40 b 0x23dbc4 <rshift_D2A+0x74>
 *
 * ══ §38/56 yyMatrix::PerspectiveLH  0x27b180  size 244  61 条（0x27b180..0x27b274）
 * @func 0x27b180 0x27b288  size 264  66 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x4×2 / 0x1c×2 / 0x18×2 / 0x10×2 / 0x24×2 / 0x20×2
 * VFP 指令 21 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b180 vmov s12, r1
 *   @0x27b184 vldr s14, [sp]
 *   @0x27b188 vmov s13, r2
 *   @0x27b18c vcmp.f32 s12, #0
 *   @0x27b190 vmov s15, r3
 *   @0x27b194 vmrs APSR_nzcv, fpscr
 *   @0x27b198 vcmp.f32 s13, #0
 *   @0x27b19c movne r3, #0
 *   @0x27b1a0 moveq r3, #1
 *   @0x27b1a4 vmrs APSR_nzcv, fpscr
 *   @0x27b1a8 orreq r3, r3, #1
 *   @0x27b1ac cmp r3, #0
 *   @0x27b1b0 bne 0x27b228 <_ZN8yyMatrix13PerspectiveLHEPS_ffff+0xa8>
 *   @0x27b1b4 vcmp.f32 s15, s14
 *   @0x27b1b8 vmrs APSR_nzcv, fpscr
 *   @0x27b1bc beq 0x27b228 <_ZN8yyMatrix13PerspectiveLHEPS_ffff+0xa8>
 *   @0x27b1c0 vnmul.f32 s10, s15, s14
 *   @0x27b1c4 mov r3, #0
 *   @0x27b1c8 str r3, [r0, #0xc]
 *   @0x27b1cc str r3, [r0, #0x8]
 *   @0x27b1d0 str r3, [r0, #0x4]
 *   @0x27b1d4 str r3, [r0, #0x1c]
 *   @0x27b1d8 str r3, [r0, #0x18]
 *   @0x27b1dc str r3, [r0, #0x10]
 *   @0x27b1e0 str r3, [r0, #0x24]
 *   @0x27b1e4 str r3, [r0, #0x20]
 *   @0x27b1e8 str r3, [r0, #0x3c]
 *   @0x27b1ec str r3, [r0, #0x34]
 *   @0x27b1f0 str r3, [r0, #0x30]
 *   @0x27b1f4 mov r3, #1065353216
 *   @0x27b1f8 vsub.f32 s11, s14, s15
 *   @0x27b1fc str r3, [r0, #0x2c]
 *   @0x27b200 vadd.f32 s15, s15, s15
 *   @0x27b204 vdiv.f32 s10, s10, s11
 *   @0x27b208 vdiv.f32 s12, s15, s12
 *   @0x27b20c vstr s10, [r0, #56]
 *   @0x27b210 vdiv.f32 s14, s14, s11
 *   @0x27b214 vstr s12, [r0]
 *   @0x27b218 vdiv.f32 s15, s15, s13
 *   @0x27b21c vstr s14, [r0, #40]
 *   @0x27b220 vstr s15, [r0, #20]
 *   @0x27b224 bx lr
 *   @0x27b228 mov r3, #0
 *   @0x27b22c mov r2, #1065353216
 *   @0x27b230 str r3, [r0, #0x38]
 *   @0x27b234 str r3, [r0, #0x34]
 *   @0x27b238 str r3, [r0, #0x30]
 *   @0x27b23c str r3, [r0, #0x2c]
 *   @0x27b240 str r3, [r0, #0x24]
 *   @0x27b244 str r3, [r0, #0x20]
 *   @0x27b248 str r3, [r0, #0x1c]
 *   @0x27b24c str r3, [r0, #0x18]
 *   @0x27b250 str r3, [r0, #0x10]
 *   @0x27b254 str r3, [r0, #0xc]
 *   @0x27b258 str r3, [r0, #0x8]
 *   @0x27b25c str r3, [r0, #0x4]
 *   @0x27b260 str r2, [r0, #0x3c]
 *   @0x27b264 str r2, [r0, #0x28]
 *   @0x27b268 str r2, [r0, #0x14]
 *   @0x27b26c str r2, [r0]
 *   @0x27b270 bx lr
 *
 * ══ §39/56 yyMatrix::OrthoLH  0x27b274  size 244  61 条（0x27b274..0x27b368）
 * @func 0x27b274 0x27b368  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xc×2 / 0x8×2 / 0x4×2 / 0x1c×2 / 0x18×2 / 0x10×2 / 0x2c×2 / 0x24×2
 * VFP 指令 23 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27b274 vmov s13, r1
 *   @0x27b278 vldr s12, [sp]
 *   @0x27b27c vmov s14, r2
 *   @0x27b280 vcmp.f32 s13, #0
 *   @0x27b284 vmov s15, r3
 *   @0x27b288 vmrs APSR_nzcv, fpscr
 *   @0x27b28c vcmp.f32 s14, #0
 *   @0x27b290 movne r3, #0
 *   @0x27b294 moveq r3, #1
 *   @0x27b298 vmrs APSR_nzcv, fpscr
 *   @0x27b29c orreq r3, r3, #1
 *   @0x27b2a0 cmp r3, #0
 *   @0x27b2a4 bne 0x27b31c <_ZN8yyMatrix7OrthoLHEPS_ffff+0xa8>
 *   @0x27b2a8 vcmp.f32 s15, s12
 *   @0x27b2ac vmrs APSR_nzcv, fpscr
 *   @0x27b2b0 beq 0x27b31c <_ZN8yyMatrix7OrthoLHEPS_ffff+0xa8>
 *   @0x27b2b4 vsub.f32 s9, s12, s15
 *   @0x27b2b8 mov r3, #0
 *   @0x27b2bc str r3, [r0, #0xc]
 *   @0x27b2c0 str r3, [r0, #0x8]
 *   @0x27b2c4 str r3, [r0, #0x4]
 *   @0x27b2c8 str r3, [r0, #0x1c]
 *   @0x27b2cc str r3, [r0, #0x18]
 *   @0x27b2d0 str r3, [r0, #0x10]
 *   @0x27b2d4 str r3, [r0, #0x2c]
 *   @0x27b2d8 str r3, [r0, #0x24]
 *   @0x27b2dc str r3, [r0, #0x20]
 *   @0x27b2e0 vmov.f32 s10, #2.000000e+00
 *   @0x27b2e4 str r3, [r0, #0x34]
 *   @0x27b2e8 str r3, [r0, #0x30]
 *   @0x27b2ec vmov.f32 s11, #1.000000e+00
 *   @0x27b2f0 vsub.f32 s12, s15, s12
 *   @0x27b2f4 vstr s11, [r0, #60]
 *   @0x27b2f8 vdiv.f32 s13, s10, s13
 *   @0x27b2fc vdiv.f32 s14, s10, s14
 *   @0x27b300 vstr s13, [r0]
 *   @0x27b304 vdiv.f32 s15, s15, s12
 *   @0x27b308 vstr s14, [r0, #20]
 *   @0x27b30c vdiv.f32 s11, s11, s9
 *   @0x27b310 vstr s15, [r0, #56]
 *   @0x27b314 vstr s11, [r0, #40]
 *   @0x27b318 bx lr
 *   @0x27b31c mov r3, #0
 *   @0x27b320 mov r2, #1065353216
 *   @0x27b324 str r3, [r0, #0x38]
 *   @0x27b328 str r3, [r0, #0x34]
 *   @0x27b32c str r3, [r0, #0x30]
 *   @0x27b330 str r3, [r0, #0x2c]
 *   @0x27b334 str r3, [r0, #0x24]
 *   @0x27b338 str r3, [r0, #0x20]
 *   @0x27b33c str r3, [r0, #0x1c]
 *   @0x27b340 str r3, [r0, #0x18]
 *   @0x27b344 str r3, [r0, #0x10]
 *   @0x27b348 str r3, [r0, #0xc]
 *   @0x27b34c str r3, [r0, #0x8]
 *   @0x27b350 str r3, [r0, #0x4]
 *   @0x27b354 str r2, [r0, #0x3c]
 *   @0x27b358 str r2, [r0, #0x28]
 *   @0x27b35c str r2, [r0, #0x14]
 *   @0x27b360 str r2, [r0]
 *   @0x27b364 bx lr
 *
 * ══ §40/56 b2Fixture::Destroy  0x2c85f0  size 244  61 条（0x2c85f0..0x2c86e4）
 * @func 0x2c85f0 0x2c86e4  size 244  61 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2BlockAllocator::Free(void*, int)×5
 * 字段偏移 top8: 0xc×4 / 0x18×2 / 0x4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c85f0 push {r4, r5, r6, lr}
 *   @0x2c85f4 mov r4, r0
 *   @0x2c85f8 ldr r0, [r0, #0xc]
 *   @0x2c85fc mov r6, r1
 *   @0x2c8600 ldr r2, [r0]
 *   @0x2c8604 ldr r3, [r2, #0xc]
 *   @0x2c8608 blx r3
 *   @0x2c860c ldr r1, [r4, #0x18]
 *   @0x2c8610 rsb r2, r0, r0, lsl #3
 *   @0x2c8614 mov r0, r6
 *   @0x2c8618 lsl r2, r2, #2
 *   @0x2c861c bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c8620 ldr r5, [r4, #0xc]
 *   @0x2c8624 mov r3, #0
 *   @0x2c8628 str r3, [r4, #0x18]
 *   @0x2c862c ldr r3, [r5, #0x4]
 *   @0x2c8630 cmp r3, #3
 *   @0x2c8634 addls pc, pc, r3, lsl #2
 *   @0x2c8638 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c>
 *   @0x2c863c b 0x2c864c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x5c>
 *   @0x2c8640 b 0x2c86c0 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0xd0>
 *   @0x2c8644 b 0x2c869c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0xac>
 *   @0x2c8648 b 0x2c8678 <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x88>
 *   @0x2c864c ldr r3, [r5]
 *   @0x2c8650 mov r0, r5
 *   @0x2c8654 ldr r3, [r3]
 *   @0x2c8658 blx r3
 *   @0x2c865c mov r0, r6
 *   @0x2c8660 mov r1, r5
 *   @0x2c8664 mov r2, #20
 *   @0x2c8668 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c866c mov r3, #0
 *   @0x2c8670 str r3, [r4, #0xc]
 *   @0x2c8674 pop {r4, r5, r6, pc}
 *   @0x2c8678 ldr r3, [r5]
 *   @0x2c867c mov r0, r5
 *   @0x2c8680 ldr r3, [r3]
 *   @0x2c8684 blx r3
 *   @0x2c8688 mov r0, r6
 *   @0x2c868c mov r1, r5
 *   @0x2c8690 mov r2, #40
 *   @0x2c8694 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c8698 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c>
 *   @0x2c869c ldr r3, [r5]
 *   @0x2c86a0 mov r0, r5
 *   @0x2c86a4 ldr r3, [r3]
 *   @0x2c86a8 blx r3
 *   @0x2c86ac mov r0, r6
 *   @0x2c86b0 mov r1, r5
 *   @0x2c86b4 mov r2, #152
 *   @0x2c86b8 bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c86bc b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c>
 *   @0x2c86c0 ldr r3, [r5]
 *   @0x2c86c4 mov r0, r5
 *   @0x2c86c8 ldr r3, [r3]
 *   @0x2c86cc blx r3
 *   @0x2c86d0 mov r0, r6
 *   @0x2c86d4 mov r1, r5
 *   @0x2c86d8 mov r2, #48
 *   @0x2c86dc bl 0x2c6710 <_ZN16b2BlockAllocator4FreeEPvi>
 *   @0x2c86e0 b 0x2c866c <_ZN9b2Fixture7DestroyEP16b2BlockAllocator+0x7c>
 *
 * ══ §41/56 anon_27ee08  0x27ee08  size 240  60 条（0x27ee08..0x27eef8）
 * @func 0x27ee08 0x27eef8  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: sprintbuf×3 / json_object_array_length / json_object_array_get_idx / json_object_put / 0xb655c
 * 字段偏移 top8: 0x30×2 / 0x34×2 / 0x98×1 / 0x94×1 / 0x90×1 / 0x8c×1 / 0x8×1 / 0x18×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27ee08 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x27ee0c mov r5, r1
 *   @0x27ee10 ldr r1, [pc, #0x98]
 *   @0x27ee14 mov r6, r0
 *   @0x27ee18 ldr r7, [pc, #0x94]
 *   @0x27ee1c mov r0, r5
 *   @0x27ee20 ldr r8, [pc, #0x90]
 *   @0x27ee24 add r1, pc, r1
 *   @0x27ee28 ldr r9, [pc, #0x8c]
 *   @0x27ee2c bl 0x280dbc <sprintbuf>
 *   @0x27ee30 mov r4, #0
 *   @0x27ee34 add r7, pc, r7
 *   @0x27ee38 add r8, pc, r8
 *   @0x27ee3c add r9, pc, r9
 *   @0x27ee40 b 0x27ee50 <json_object_array_get_idx+0x50>
 *   @0x27ee44 ldr r3, [r3, #0x8]
 *   @0x27ee48 blx r3
 *   @0x27ee4c add r4, r4, #1
 *   @0x27ee50 mov r0, r6
 *   @0x27ee54 bl 0x27ede8 <json_object_array_length>
 *   @0x27ee58 mov r1, r7
 *   @0x27ee5c cmp r4, r0
 *   @0x27ee60 mov r0, r5
 *   @0x27ee64 bge 0x27eea0 <json_object_array_get_idx+0xa0>
 *   @0x27ee68 cmp r4, #0
 *   @0x27ee6c movne r1, r8
 *   @0x27ee70 movne r0, r5
 *   @0x27ee74 bl 0x280dbc <sprintbuf>
 *   @0x27ee78 mov r1, r4
 *   @0x27ee7c mov r0, r6
 *   @0x27ee80 bl 0x27ee00 <json_object_array_get_idx>
 *   @0x27ee84 mov r1, r5
 *   @0x27ee88 subs r3, r0, #0
 *   @0x27ee8c bne 0x27ee44 <json_object_array_get_idx+0x44>
 *   @0x27ee90 mov r0, r5
 *   @0x27ee94 mov r1, r9
 *   @0x27ee98 bl 0x280dbc <sprintbuf>
 *   @0x27ee9c b 0x27ee4c <json_object_array_get_idx+0x4c>
 *   @0x27eea0 ldr r1, [pc, #0x18]
 *   @0x27eea4 pop {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x27eea8 add r1, pc, r1
 *   @0x27eeac b 0x280dbc <sprintbuf>
 *   @0x27eeb0 muleq sp, r0, r4
 *   @0x27eeb4 andeq r8, sp, r8, lsl #9
 *   @0x27eeb8 andeq r8, sp, r0, lsl #9
 *   @0x27eebc andeq r3, r11, r8, ror #8
 *   @0x27eec0 andeq r8, sp, r8, lsl r4
 *   @0x27eec4 add r1, r1, r1, lsl #2
 *   @0x27eec8 push {r3, r4, r5, lr}
 *   @0x27eecc add r4, r0, r1, lsl #2
 *   @0x27eed0 mov r3, #1
 *   @0x27eed4 mov r5, #0
 *   @0x27eed8 str r3, [r4, #0x28]
 *   @0x27eedc ldr r0, [r4, #0x30]
 *   @0x27eee0 str r5, [r4, #0x24]
 *   @0x27eee4 bl 0x27e7c8 <json_object_put>
 *   @0x27eee8 str r5, [r4, #0x30]
 *   @0x27eeec ldr r0, [r4, #0x34]
 *   @0x27eef0 bl 0xb655c <free@plt>
 *   @0x27eef4 str r5, [r4, #0x34]
 *
 * ══ §42/56 b2DynamicTree::AllocateNode  0x2de9bc  size 240  60 条（0x2de9bc..0x2deaac）
 * @func 0x2de9bc 0x2deaac  size 240  60 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2Alloc(int) / 0xb65bc / b2Free(void*)
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x14×4 / 0x10×3 / 0x20×3 / 0xc×3 / 0x18×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de9bc push {r4, r5, r6, lr}
 *   @0x2de9c0 mov r4, r0
 *   @0x2de9c4 ldr r5, [r0, #0x10]
 *   @0x2de9c8 cmn r5, #1
 *   @0x2de9cc beq 0x2dea14 <_ZN13b2DynamicTree12AllocateNodeEv+0x58>
 *   @0x2de9d0 ldr r12, [r4, #0x4]
 *   @0x2de9d4 mov r0, r5
 *   @0x2de9d8 ldr r2, [r4, #0x8]
 *   @0x2de9dc add r3, r0, r0, lsl #3
 *   @0x2de9e0 add r5, r2, #1
 *   @0x2de9e4 mov r1, #0
 *   @0x2de9e8 mvn r2, #0
 *   @0x2de9ec add r3, r12, r3, lsl #2
 *   @0x2de9f0 ldr r12, [r3, #0x14]
 *   @0x2de9f4 str r12, [r4, #0x10]
 *   @0x2de9f8 str r2, [r3, #0x14]
 *   @0x2de9fc str r2, [r3, #0x18]
 *   @0x2dea00 str r2, [r3, #0x1c]
 *   @0x2dea04 str r1, [r3, #0x20]
 *   @0x2dea08 str r1, [r3, #0x10]
 *   @0x2dea0c str r5, [r4, #0x8]
 *   @0x2dea10 pop {r4, r5, r6, pc}
 *   @0x2dea14 ldr r2, [r0, #0xc]
 *   @0x2dea18 ldr r6, [r0, #0x4]
 *   @0x2dea1c lsl r3, r2, #1
 *   @0x2dea20 str r3, [r0, #0xc]
 *   @0x2dea24 add r0, r3, r2, lsl #4
 *   @0x2dea28 lsl r0, r0, #2
 *   @0x2dea2c bl 0x2c6a6c <_Z7b2Alloci>
 *   @0x2dea30 ldr r3, [r4, #0x8]
 *   @0x2dea34 mov r1, r6
 *   @0x2dea38 add r2, r3, r3, lsl #3
 *   @0x2dea3c lsl r2, r2, #2
 *   @0x2dea40 str r0, [r4, #0x4]
 *   @0x2dea44 bl 0xb65bc <memcpy@plt>
 *   @0x2dea48 mov r0, r6
 *   @0x2dea4c bl 0x2c6a70 <_Z6b2FreePv>
 *   @0x2dea50 ldr r6, [r4, #0xc]
 *   @0x2dea54 ldr r0, [r4, #0x8]
 *   @0x2dea58 sub r1, r6, #1
 *   @0x2dea5c ldr r12, [r4, #0x4]
 *   @0x2dea60 cmp r0, r1
 *   @0x2dea64 addlt r3, r0, r0, lsl #3
 *   @0x2dea68 movlt r2, r0
 *   @0x2dea6c addlt r3, r12, r3, lsl #2
 *   @0x2dea70 bge 0x2dea8c <_ZN13b2DynamicTree12AllocateNodeEv+0xd0>
 *   @0x2dea74 add r2, r2, #1
 *   @0x2dea78 str r5, [r3, #0x20]
 *   @0x2dea7c cmp r2, r1
 *   @0x2dea80 str r2, [r3, #0x14]
 *   @0x2dea84 add r3, r3, #36
 *   @0x2dea88 bne 0x2dea74 <_ZN13b2DynamicTree12AllocateNodeEv+0xb8>
 *   @0x2dea8c add r6, r6, r6, lsl #3
 *   @0x2dea90 mvn r3, #0
 *   @0x2dea94 mov r2, r0
 *   @0x2dea98 add r6, r12, r6, lsl #2
 *   @0x2dea9c sub r6, r6, #36
 *   @0x2deaa0 str r3, [r6, #0x14]
 *   @0x2deaa4 str r3, [r6, #0x20]
 *   @0x2deaa8 b 0x2de9dc <_ZN13b2DynamicTree12AllocateNodeEv+0x20>
 *
 * ══ §43/56 CSkeletonInstance::FrameCount  0xbe220  size 236  59 条（0xbe220..0xbe30c）
 * @func 0xbe220 0xbe30c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CSkeletonInstance::FrameCount(int)+0xc4 / CTimingSource::GetFPS()
 * 字段偏移 top8: 0xc×3 / 0x2×3 / 0x28×2 / 0x10×2 / 0xa0×1 / 0x90×1 / 0x4c×1
 * VFP 指令 10 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbe220 push {r3, r4, r5, lr}
 *   @0xbe224 subs r4, r1, #0
 *   @0xbe228 mov r5, r0
 *   @0xbe22c blt 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe230 ldr r3, [r0, #0x28]
 *   @0xbe234 cmp r3, #0
 *   @0xbe238 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe23c ldr r2, [r3, #0xc]
 *   @0xbe240 cmp r4, r2
 *   @0xbe244 bge 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe248 ldr r2, [r3, #0x10]
 *   @0xbe24c ldr r3, [r2, r4, lsl #2]
 *   @0xbe250 cmp r3, #0
 *   @0xbe254 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe258 ldr r3, [pc, #0xa0]
 *   @0xbe25c ldr r3, [pc, r3]
 *   @0xbe260 ldrb r3, [r3]
 *   @0xbe264 cmp r3, #0
 *   @0xbe268 bne 0xbe2b4 <_ZN17CSkeletonInstance10FrameCountEi+0x94>
 *   @0xbe26c ldr r3, [pc, #0x90]
 *   @0xbe270 ldr r3, [pc, r3]
 *   @0xbe274 ldr r3, [r3]
 *   @0xbe278 cmp r3, #0
 *   @0xbe27c moveq r3, #30
 *   @0xbe280 ldrne r3, [r3, #0xc]
 *   @0xbe284 ldr r2, [r2, r4, lsl #2]
 *   @0xbe288 ldr r2, [r2, #0xc]
 *   @0xbe28c cmp r2, #0
 *   @0xbe290 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe294 vmov.f32 s15, #5.000000e-01
 *   @0xbe298 vldr s13, [r2, #4]
 *   @0xbe29c vmov s12, r3
 *   @0xbe2a0 vcvt.f32.s32 s14, s12
 *   @0xbe2a4 vmla.f32 s15, s14, s13
 *   @0xbe2a8 vcvt.s32.f32 s15, s15
 *   @0xbe2ac vmov r0, s15
 *   @0xbe2b0 pop {r3, r4, r5, pc}
 *   @0xbe2b4 ldr r0, [pc, #0x4c]
 *   @0xbe2b8 ldr r0, [pc, r0]
 *   @0xbe2bc bl 0x214808 <_ZN13CTimingSource6GetFPSEv>
 *   @0xbe2c0 ldr r2, [r5, #0x28]
 *   @0xbe2c4 cmp r2, #0
 *   @0xbe2c8 vmov d7, r0, r1
 *   @0xbe2cc beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe2d0 vcvt.s32.f64 s12, d7
 *   @0xbe2d4 ldr r1, [r2, #0xc]
 *   @0xbe2d8 cmp r1, r4
 *   @0xbe2dc vmov r3, s12
 *   @0xbe2e0 bgt 0xbe2ec <_ZN17CSkeletonInstance10FrameCountEi+0xcc>
 *   @0xbe2e4 mov r0, #0
 *   @0xbe2e8 pop {r3, r4, r5, pc}
 *   @0xbe2ec ldr r2, [r2, #0x10]
 *   @0xbe2f0 ldr r2, [r2, r4, lsl #2]
 *   @0xbe2f4 cmp r2, #0
 *   @0xbe2f8 beq 0xbe2e4 <_ZN17CSkeletonInstance10FrameCountEi+0xc4>
 *   @0xbe2fc b 0xbe288 <_ZN17CSkeletonInstance10FrameCountEi+0x68>
 *   @0xbe300 eorseq pc, r2, r8, asr #13
 *   @0xbe304 ldrhteq pc, [r2], -r8
 *   @0xbe308 eorseq pc, r2, r4, ror r6
 *
 * ══ §44/56 Perform_Event_Object_ASync  0xf31f8  size 236  59 条（0xf31f8..0xf32e4）
 * @func 0xf31f8 0xf32e4  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: Find_Event(int, int, int, int&) / CEvent::Execute(CInstance*, CInstance*) / Error_Show_Action(char const*, bool)
 * 字段偏移 top8: 0x70×3 / 0x30×1 / 0x-4×1 / 0x90×1 / 0x4×1 / 0x38×1 / 0x20×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf31f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xf31fc sub sp, sp, #12
 *   @0xf3200 mov r8, r3
 *   @0xf3204 add r3, sp, #8
 *   @0xf3208 ldr r7, [sp, #0x30]
 *   @0xf320c mov r5, r0
 *   @0xf3210 mov r4, r1
 *   @0xf3214 mov r0, r2
 *   @0xf3218 mov r1, r8
 *   @0xf321c mov r2, #0
 *   @0xf3220 str r2, [r3, #-0x4]!
 *   @0xf3224 mov r2, r7
 *   @0xf3228 bl 0xf2e80 <_Z10Find_EventiiiRi>
 *   @0xf322c cmp r0, #0
 *   @0xf3230 beq 0xf32b0 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xb8>
 *   @0xf3234 ldr lr, [pc, #0x90]
 *   @0xf3238 add lr, pc, lr
 *   @0xf323c ldr r12, [lr]
 *   @0xf3240 add r12, r12, #1
 *   @0xf3244 str r12, [lr]
 *   @0xf3248 cmp r12, #32
 *   @0xf324c bgt 0xf32b8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xc0>
 *   @0xf3250 mov r1, r5
 *   @0xf3254 mov r2, r4
 *   @0xf3258 ldr r6, [pc, #0x70]
 *   @0xf325c ldr r5, [pc, #0x70]
 *   @0xf3260 ldr r4, [pc, #0x70]
 *   @0xf3264 ldr r6, [pc, r6]
 *   @0xf3268 ldr r5, [pc, r5]
 *   @0xf326c ldr r3, [sp, #0x4]
 *   @0xf3270 ldr r4, [pc, r4]
 *   @0xf3274 ldr r11, [r6]
 *   @0xf3278 ldr r10, [r5]
 *   @0xf327c ldr r9, [r4]
 *   @0xf3280 str r3, [r6]
 *   @0xf3284 str r8, [r5]
 *   @0xf3288 str r7, [r4]
 *   @0xf328c bl 0xf2e34 <_ZN6CEvent7ExecuteEP9CInstanceS1_>
 *   @0xf3290 str r11, [r6]
 *   @0xf3294 str r10, [r5]
 *   @0xf3298 str r9, [r4]
 *   @0xf329c ldr r3, [pc, #0x38]
 *   @0xf32a0 add r3, pc, r3
 *   @0xf32a4 ldr r2, [r3]
 *   @0xf32a8 sub r2, r2, #1
 *   @0xf32ac str r2, [r3]
 *   @0xf32b0 add sp, sp, #12
 *   @0xf32b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xf32b8 ldr r0, [pc, #0x20]
 *   @0xf32bc mov r1, #1
 *   @0xf32c0 add r0, pc, r0
 *   @0xf32c4 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xf32c8 b 0xf329c <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii+0xa4>
 *   @0xf32cc eorseq r0, r9, r12, asr #3
 *   @0xf32d0 eoreq r10, pc, r4, asr r11
 *   @0xf32d4 eoreq r10, pc, r8, asr #22
 *   @0xf32d8 eoreq r10, pc, r4, asr #22
 *   @0xf32dc eorseq r0, r9, r4, ror #2
 *   @0xf32e0 eoreq r3, r4, r8, asr #25
 *
 * ══ §45/56 ogg_page_granulepos  0x233fb0  size 236  59 条（0x233fb0..0x23409c）
 * @func 0x233fb0 0x23409c  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0xd×1 / 0xc×1 / 0xa×1 / 0xb×1 / 0x9×1 / 0x8×1 / 0x7×1 / 0x6×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x233fb0 ldr r12, [r0]
 *   @0x233fb4 mov r1, #0
 *   @0x233fb8 push {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x233fbc mov r9, #0
 *   @0x233fc0 ldrb r6, [r12, #0xd]
 *   @0x233fc4 sub sp, sp, #8
 *   @0x233fc8 ldrb r8, [r12, #0xc]
 *   @0x233fcc mov r11, #0
 *   @0x233fd0 ldrb r0, [r12, #0xa]
 *   @0x233fd4 lsr r3, r6, #24
 *   @0x233fd8 lsl r2, r6, #8
 *   @0x233fdc orr r9, r9, r3
 *   @0x233fe0 orr r8, r8, r2
 *   @0x233fe4 ldrb r10, [r12, #0xb]
 *   @0x233fe8 lsl r5, r9, #8
 *   @0x233fec lsl r4, r8, #8
 *   @0x233ff0 orr r5, r5, r8, lsr #24
 *   @0x233ff4 strd r0, r1, [sp]
 *   @0x233ff8 orr r5, r5, r11
 *   @0x233ffc orr r4, r4, r10
 *   @0x234000 ldrd r2, r3, [sp]
 *   @0x234004 mov r9, #0
 *   @0x234008 lsl r1, r5, #8
 *   @0x23400c lsl r0, r4, #8
 *   @0x234010 orr r1, r1, r4, lsr #24
 *   @0x234014 orr r0, r0, r2
 *   @0x234018 orr r1, r1, r3
 *   @0x23401c ldrb r8, [r12, #0x9]
 *   @0x234020 lsl r2, r0, #8
 *   @0x234024 ldrb r10, [r12, #0x8]
 *   @0x234028 lsl r3, r1, #8
 *   @0x23402c orr r2, r2, r8
 *   @0x234030 orr r3, r3, r0, lsr #24
 *   @0x234034 ldrb r0, [r12, #0x7]
 *   @0x234038 orr r3, r3, r9
 *   @0x23403c mov r11, #0
 *   @0x234040 lsl r6, r2, #8
 *   @0x234044 mov r1, #0
 *   @0x234048 lsl r7, r3, #8
 *   @0x23404c strd r0, r1, [sp]
 *   @0x234050 orr r7, r7, r2, lsr #24
 *   @0x234054 orr r6, r6, r10
 *   @0x234058 orr r7, r7, r11
 *   @0x23405c ldrd r2, r3, [sp]
 *   @0x234060 lsl r4, r6, #8
 *   @0x234064 ldrb r0, [r12, #0x6]
 *   @0x234068 lsl r5, r7, #8
 *   @0x23406c orr r4, r4, r2
 *   @0x234070 orr r5, r5, r6, lsr #24
 *   @0x234074 mov r1, #0
 *   @0x234078 orr r5, r5, r3
 *   @0x23407c lsl r2, r4, #8
 *   @0x234080 orr r0, r0, r2
 *   @0x234084 lsl r3, r5, #8
 *   @0x234088 orr r3, r3, r4, lsr #24
 *   @0x23408c orr r1, r1, r3
 *   @0x234090 add sp, sp, #8
 *   @0x234094 pop {r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x234098 bx lr
 *
 * ══ §46/56 spAnimation_apply  0x281500  size 236  59 条（0x281500..0x2815ec）
 * @func 0x281500 0x281600  size 256  64 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66ac×2 / spAnimation_apply+0x84 / spTimeline_apply / spAnimation_apply+0x44
 * 字段偏移 top8: 0x40×1 / 0x8×1 / 0x44×1 / 0x48×1 / 0xc×1 / 0x2×1 / 0x4×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x281500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x281504 vpush {d8}
 *   @0x281508 sub sp, sp, #20
 *   @0x28150c mov r11, r0
 *   @0x281510 mov r8, r1
 *   @0x281514 ldr r12, [sp, #0x40]
 *   @0x281518 mov r7, r2
 *   @0x28151c mov r6, r3
 *   @0x281520 ldr r5, [r0, #0x8]
 *   @0x281524 cmp r12, #0
 *   @0x281528 ldr r9, [sp, #0x44]
 *   @0x28152c ldr r10, [sp, #0x48]
 *   @0x281530 beq 0x281544 <spAnimation_apply+0x44>
 *   @0x281534 vldr s15, [r0, #4]
 *   @0x281538 vcmp.f32 s15, #0
 *   @0x28153c vmrs APSR_nzcv, fpscr
 *   @0x281540 bne 0x281590 <spAnimation_apply+0x90>
 *   @0x281544 cmp r5, #0
 *   @0x281548 ble 0x281584 <spAnimation_apply+0x84>
 *   @0x28154c vmov.f32 s16, #1.000000e+00
 *   @0x281550 mov r4, #0
 *   @0x281554 ldr r0, [r11, #0xc]
 *   @0x281558 mov r1, r8
 *   @0x28155c mov r2, r7
 *   @0x281560 mov r3, r6
 *   @0x281564 ldr r0, [r0, r4, lsl #2]
 *   @0x281568 vstr s16, [sp, #8]
 *   @0x28156c str r9, [sp]
 *   @0x281570 add r4, r4, #1
 *   @0x281574 str r10, [sp, #0x4]
 *   @0x281578 bl 0x2814cc <spTimeline_apply>
 *   @0x28157c cmp r4, r5
 *   @0x281580 bne 0x281554 <spAnimation_apply+0x54>
 *   @0x281584 add sp, sp, #20
 *   @0x281588 vpop {d8}
 *   @0x28158c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x281590 vmov s13, r3
 *   @0x281594 vcvt.f64.f32 d6, s13
 *   @0x281598 vmov r0, r1, d6
 *   @0x28159c vcvt.f64.f32 d6, s15
 *   @0x2815a0 vmov r2, r3, d6
 *   @0x2815a4 bl 0xb66ac <fmod@plt>
 *   @0x2815a8 vmov s13, r7
 *   @0x2815ac vcmpe.f32 s13, #0
 *   @0x2815b0 vmrs APSR_nzcv, fpscr
 *   @0x2815b4 vmov d7, r0, r1
 *   @0x2815b8 vcvt.f32.f64 s15, d7
 *   @0x2815bc vmov r6, s15
 *   @0x2815c0 ble 0x281544 <spAnimation_apply+0x44>
 *   @0x2815c4 vcvt.f64.f32 d6, s13
 *   @0x2815c8 vldr s15, [r11, #4]
 *   @0x2815cc vmov r0, r1, d6
 *   @0x2815d0 vcvt.f64.f32 d6, s15
 *   @0x2815d4 vmov r2, r3, d6
 *   @0x2815d8 bl 0xb66ac <fmod@plt>
 *   @0x2815dc vmov d7, r0, r1
 *   @0x2815e0 vcvt.f32.f64 s15, d7
 *   @0x2815e4 vmov r7, s15
 *   @0x2815e8 b 0x281544 <spAnimation_apply+0x44>
 *
 * ══ §47/56 spAnimation_mix  0x2815ec  size 236  59 条（0x2815ec..0x2816d8）
 * @func 0x2815ec 0x2816d8  size 236  59 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66ac×2 / spAnimation_mix+0x84 / spTimeline_apply / spAnimation_mix+0x48
 * 字段偏移 top8: 0x40×1 / 0x8×1 / 0x44×1 / 0x48×1 / 0xc×1 / 0x2×1 / 0x4×1
 * VFP 指令 26 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2815ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2815f0 vpush {d8}
 *   @0x2815f4 sub sp, sp, #20
 *   @0x2815f8 vldr s16, [sp, #76]
 *   @0x2815fc mov r11, r0
 *   @0x281600 mov r8, r1
 *   @0x281604 ldr r12, [sp, #0x40]
 *   @0x281608 mov r7, r2
 *   @0x28160c mov r6, r3
 *   @0x281610 ldr r5, [r0, #0x8]
 *   @0x281614 cmp r12, #0
 *   @0x281618 ldr r9, [sp, #0x44]
 *   @0x28161c ldr r10, [sp, #0x48]
 *   @0x281620 beq 0x281634 <spAnimation_mix+0x48>
 *   @0x281624 vldr s15, [r0, #4]
 *   @0x281628 vcmp.f32 s15, #0
 *   @0x28162c vmrs APSR_nzcv, fpscr
 *   @0x281630 bne 0x28167c <spAnimation_mix+0x90>
 *   @0x281634 cmp r5, #0
 *   @0x281638 ble 0x281670 <spAnimation_mix+0x84>
 *   @0x28163c mov r4, #0
 *   @0x281640 ldr r0, [r11, #0xc]
 *   @0x281644 mov r1, r8
 *   @0x281648 mov r2, r7
 *   @0x28164c mov r3, r6
 *   @0x281650 ldr r0, [r0, r4, lsl #2]
 *   @0x281654 vstr s16, [sp, #8]
 *   @0x281658 str r9, [sp]
 *   @0x28165c add r4, r4, #1
 *   @0x281660 str r10, [sp, #0x4]
 *   @0x281664 bl 0x2814cc <spTimeline_apply>
 *   @0x281668 cmp r4, r5
 *   @0x28166c bne 0x281640 <spAnimation_mix+0x54>
 *   @0x281670 add sp, sp, #20
 *   @0x281674 vpop {d8}
 *   @0x281678 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28167c vmov s13, r3
 *   @0x281680 vcvt.f64.f32 d6, s13
 *   @0x281684 vmov r0, r1, d6
 *   @0x281688 vcvt.f64.f32 d6, s15
 *   @0x28168c vmov r2, r3, d6
 *   @0x281690 bl 0xb66ac <fmod@plt>
 *   @0x281694 vmov s13, r7
 *   @0x281698 vcmpe.f32 s13, #0
 *   @0x28169c vmrs APSR_nzcv, fpscr
 *   @0x2816a0 vmov d7, r0, r1
 *   @0x2816a4 vcvt.f32.f64 s15, d7
 *   @0x2816a8 vmov r6, s15
 *   @0x2816ac ble 0x281634 <spAnimation_mix+0x48>
 *   @0x2816b0 vcvt.f64.f32 d6, s13
 *   @0x2816b4 vldr s15, [r11, #4]
 *   @0x2816b8 vmov r0, r1, d6
 *   @0x2816bc vcvt.f64.f32 d6, s15
 *   @0x2816c0 vmov r2, r3, d6
 *   @0x2816c4 bl 0xb66ac <fmod@plt>
 *   @0x2816c8 vmov d7, r0, r1
 *   @0x2816cc vcvt.f32.f64 s15, d7
 *   @0x2816d0 vmov r7, s15
 *   @0x2816d4 b 0x281634 <spAnimation_mix+0x48>
 *
 * ══ §48/56 CBackground::DrawTiled  0xc22d8  size 232  58 条（0xc22d8..0xc23c0）
 * @func 0xc22d8 0xc23c0  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Draw_Tiled(YYTPageEntry*, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float) / GR_Texture_Draw_Tiled(int, float, float, float, float, float, float, bool, bool, float, float, float, float, unsigned int, float)
 * 字段偏移 top8: 0xc×3 / 0x4×2 / 0x5c×2 / 0x24×2 / 0x10×2 / 0x14×1 / 0x44×1 / 0x48×1
 * VFP 指令 24 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc22d8 ldr r12, [r0, #0x14]
 *   @0xc22dc push {r4, r5, lr}
 *   @0xc22e0 cmp r12, #0
 *   @0xc22e4 sub sp, sp, #52
 *   @0xc22e8 mov lr, r1
 *   @0xc22ec ldrb r5, [sp, #0x44]
 *   @0xc22f0 ldrb r4, [sp, #0x48]
 *   @0xc22f4 beq 0xc235c <_ZN11CBackground9DrawTiledEffffbbffffjf+0x84>
 *   @0xc22f8 str r3, [sp, #0x4]
 *   @0xc22fc mov r1, #0
 *   @0xc2300 ldr r3, [sp, #0x5c]
 *   @0xc2304 vldr s15, [sp, #64]
 *   @0xc2308 str r2, [sp]
 *   @0xc230c vstr s15, [sp, #8]
 *   @0xc2310 str r5, [sp, #0xc]
 *   @0xc2314 vldr s15, [sp, #76]
 *   @0xc2318 str r3, [sp, #0x24]
 *   @0xc231c vstr s15, [sp, #20]
 *   @0xc2320 str r4, [sp, #0x10]
 *   @0xc2324 vldr s15, [sp, #80]
 *   @0xc2328 mov r0, r12
 *   @0xc232c vstr s15, [sp, #24]
 *   @0xc2330 mov r3, lr
 *   @0xc2334 vldr s15, [sp, #84]
 *   @0xc2338 mov r2, r1
 *   @0xc233c vstr s15, [sp, #28]
 *   @0xc2340 vldr s15, [sp, #88]
 *   @0xc2344 vstr s15, [sp, #32]
 *   @0xc2348 vldr s15, [sp, #96]
 *   @0xc234c vstr s15, [sp, #40]
 *   @0xc2350 bl 0x1762b0 <_Z21GR_Texture_Draw_TiledP12YYTPageEntryffffffbbffffjf>
 *   @0xc2354 add sp, sp, #52
 *   @0xc2358 pop {r4, r5, pc}
 *   @0xc235c ldr r0, [r0, #0xc]
 *   @0xc2360 mov r1, #0
 *   @0xc2364 str r3, [sp, #0x4]
 *   @0xc2368 vldr s15, [sp, #64]
 *   @0xc236c ldr r3, [sp, #0x5c]
 *   @0xc2370 vstr s15, [sp, #8]
 *   @0xc2374 str r2, [sp]
 *   @0xc2378 vldr s15, [sp, #76]
 *   @0xc237c str r5, [sp, #0xc]
 *   @0xc2380 vstr s15, [sp, #20]
 *   @0xc2384 str r3, [sp, #0x24]
 *   @0xc2388 vldr s15, [sp, #80]
 *   @0xc238c str r4, [sp, #0x10]
 *   @0xc2390 vstr s15, [sp, #24]
 *   @0xc2394 mov r3, lr
 *   @0xc2398 vldr s15, [sp, #84]
 *   @0xc239c mov r2, r1
 *   @0xc23a0 vstr s15, [sp, #28]
 *   @0xc23a4 vldr s15, [sp, #88]
 *   @0xc23a8 vstr s15, [sp, #32]
 *   @0xc23ac vldr s15, [sp, #96]
 *   @0xc23b0 vstr s15, [sp, #40]
 *   @0xc23b4 bl 0x175e90 <_Z21GR_Texture_Draw_Tilediffffffbbffffjf>
 *   @0xc23b8 add sp, sp, #52
 *   @0xc23bc pop {r4, r5, pc}
 *
 * ══ §49/56 CreateBuffer  0xc6ad0  size 232  58 条（0xc6ad0..0xc6bb8）
 * @func 0xc6ad0 0xc6bb8  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: operator new(unsigned int)×2 / IBuffer::IBuffer(int, eBuffer_Format, int)×2 / AllocBuffer() / YYError(char const*, ...)
 * 字段偏移 top8: 0x4×2 / 0x2×2 / 0x78×1 / 0x74×1 / 0x3c×1 / 0x38×1 / 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xc6ad0 push {r4, r5, r6, r7, r8, lr}
 *   @0xc6ad4 mov r7, r0
 *   @0xc6ad8 mov r4, r1
 *   @0xc6adc mov r6, r2
 *   @0xc6ae0 bl 0xc67b0 <_Z11AllocBufferv>
 *   @0xc6ae4 mov r5, r0
 *   @0xc6ae8 cmp r4, #4
 *   @0xc6aec addls pc, pc, r4, lsl #2
 *   @0xc6af0 b 0xc6b90 <_Z12CreateBufferi14eBuffer_Formati+0xc0>
 *   @0xc6af4 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c>
 *   @0xc6af8 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c>
 *   @0xc6afc b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c>
 *   @0xc6b00 b 0xc6b08 <_Z12CreateBufferi14eBuffer_Formati+0x38>
 *   @0xc6b04 b 0xc6b4c <_Z12CreateBufferi14eBuffer_Formati+0x7c>
 *   @0xc6b08 mov r0, #64
 *   @0xc6b0c bl 0x27c524 <_Znwj>
 *   @0xc6b10 mov r2, r4
 *   @0xc6b14 mov r3, r6
 *   @0xc6b18 mov r1, r7
 *   @0xc6b1c mov r8, r0
 *   @0xc6b20 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0xc6b24 ldr r2, [pc, #0x78]
 *   @0xc6b28 mov r0, r5
 *   @0xc6b2c ldr r3, [pc, #0x74]
 *   @0xc6b30 add r2, pc, r2
 *   @0xc6b34 ldr r3, [pc, r3]
 *   @0xc6b38 ldr r2, [r2, #0x4]
 *   @0xc6b3c add r3, r3, #8
 *   @0xc6b40 str r3, [r8]
 *   @0xc6b44 str r8, [r2, r5, lsl #2]
 *   @0xc6b48 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc6b4c mov r0, #64
 *   @0xc6b50 bl 0x27c524 <_Znwj>
 *   @0xc6b54 mov r2, r4
 *   @0xc6b58 mov r3, r6
 *   @0xc6b5c mov r1, r7
 *   @0xc6b60 mov r8, r0
 *   @0xc6b64 bl 0xcc994 <_ZN7IBufferC2Ei14eBuffer_Formati>
 *   @0xc6b68 ldr r2, [pc, #0x3c]
 *   @0xc6b6c mov r0, r5
 *   @0xc6b70 ldr r3, [pc, #0x38]
 *   @0xc6b74 add r2, pc, r2
 *   @0xc6b78 ldr r3, [pc, r3]
 *   @0xc6b7c ldr r2, [r2, #0x4]
 *   @0xc6b80 add r3, r3, #8
 *   @0xc6b84 str r3, [r8]
 *   @0xc6b88 str r8, [r2, r5, lsl #2]
 *   @0xc6b8c pop {r4, r5, r6, r7, r8, pc}
 *   @0xc6b90 ldr r0, [pc, #0x1c]
 *   @0xc6b94 add r0, pc, r0
 *   @0xc6b98 bl 0xd547c <_Z7YYErrorPKcz>
 *   @0xc6b9c mov r0, r5
 *   @0xc6ba0 pop {r4, r5, r6, r7, r8, pc}
 *   @0xc6ba4 eorseq r3, r11, r4, ror #11
 *   @0xc6ba8 eorseq r6, r2, r8, ror lr
 *   @0xc6bac eorseq r3, r11, r0, lsr #11
 *   @0xc6bb0 eorseq r6, r2, r8, lsr lr
 *   @0xc6bb4 eoreq r10, r6, r8, ror #9
 *
 * ══ §50/56 F_DsMapAdd_Internal  0x104d94  size 232  58 条（0x104d94..0x104e7c）
 * @func 0x104d94 0x104e7c  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / DS_AutoMutex::DS_AutoMutex() / YYSetString(RValue*, char const*) / CDS_Map::Add(RValue*, RValue*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x24×3 / 0x14×2 / 0xa8×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x104d94 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x104d98 sub sp, sp, #44
 *   @0x104d9c add r8, sp, #4
 *   @0x104da0 add r7, sp, #8
 *   @0x104da4 mov r6, r1
 *   @0x104da8 mov r9, r0
 *   @0x104dac mov r0, r8
 *   @0x104db0 mov r4, r2
 *   @0x104db4 mov r5, r3
 *   @0x104db8 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x104dbc mov r1, r6
 *   @0x104dc0 mov r0, r7
 *   @0x104dc4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x104dc8 ldr r3, [pc, #0xa8]
 *   @0x104dcc add r6, sp, #40
 *   @0x104dd0 mov r0, #0
 *   @0x104dd4 ldr r3, [pc, r3]
 *   @0x104dd8 str r0, [sp, #0x24]
 *   @0x104ddc strd r4, r5, [r6, #-16]!
 *   @0x104de0 mov r1, r7
 *   @0x104de4 ldr r3, [r3, #0x4]
 *   @0x104de8 mov r2, r6
 *   @0x104dec ldr r0, [r3, r9, lsl #2]
 *   @0x104df0 bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x104df4 ldr r3, [sp, #0x24]
 *   @0x104df8 sub r3, r3, #1
 *   @0x104dfc bic r3, r3, #-16777216
 *   @0x104e00 bic r3, r3, #3
 *   @0x104e04 cmp r3, #0
 *   @0x104e08 mov r4, r0
 *   @0x104e0c beq 0x104e6c <_Z19F_DsMapAdd_InternaliPcd+0xd8>
 *   @0x104e10 ldr r1, [sp, #0x14]
 *   @0x104e14 mov r3, #0
 *   @0x104e18 str r3, [sp, #0x20]
 *   @0x104e1c mov r2, #5
 *   @0x104e20 sub r1, r1, #1
 *   @0x104e24 str r3, [sp, #0x18]
 *   @0x104e28 bic r3, r1, #-16777216
 *   @0x104e2c str r2, [sp, #0x24]
 *   @0x104e30 bic r3, r3, #3
 *   @0x104e34 cmp r3, #0
 *   @0x104e38 bne 0x104e44 <_Z19F_DsMapAdd_InternaliPcd+0xb0>
 *   @0x104e3c mov r0, r7
 *   @0x104e40 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104e44 mov r0, r8
 *   @0x104e48 mov r3, #0
 *   @0x104e4c mov r2, #5
 *   @0x104e50 str r3, [sp, #0x10]
 *   @0x104e54 str r3, [sp, #0x8]
 *   @0x104e58 str r2, [sp, #0x14]
 *   @0x104e5c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x104e60 mov r0, r4
 *   @0x104e64 add sp, sp, #44
 *   @0x104e68 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x104e6c mov r0, r6
 *   @0x104e70 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x104e74 b 0x104e10 <_Z19F_DsMapAdd_InternaliPcd+0x7c>
 *   @0x104e78 eoreq r8, lr, r8, ror #22
 *
 * ══ §51/56 SetGuiView  0x1b3330  size 232  58 条（0x1b3330..0x1b3418）
 * @func 0x1b3330 0x1b3418  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_D3D_Set_View_Port(int, int, int, int) / yyMatrix::OrthoLH(yyMatrix*, float, float, float, float) / Graphics::SetMatrix(eMatrix, float*) / Calc_GUI_Scale()
 * 字段偏移 top8: 0xcc×1 / 0xc8×1 / 0xb0×1 / 0x44×1 / 0x40×1 / 0x3c×1 / 0x38×1 / 0x34×1
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b3330 push {r4, r5, lr}
 *   @0x1b3334 mov r0, #0
 *   @0x1b3338 ldr r4, [pc, #0xcc]
 *   @0x1b333c sub sp, sp, #76
 *   @0x1b3340 ldr r5, [pc, #0xc8]
 *   @0x1b3344 mov r1, r0
 *   @0x1b3348 ldr r4, [pc, r4]
 *   @0x1b334c ldr r5, [pc, r5]
 *   @0x1b3350 ldr r2, [r4]
 *   @0x1b3354 ldr r3, [r5]
 *   @0x1b3358 bl 0x168cd8 <_Z20GR_D3D_Set_View_Portiiii>
 *   @0x1b335c ldr r3, [pc, #0xb0]
 *   @0x1b3360 ldr r1, [r4]
 *   @0x1b3364 add r4, sp, #8
 *   @0x1b3368 ldr r3, [pc, r3]
 *   @0x1b336c ldr r2, [r5]
 *   @0x1b3370 mov lr, #1065353216
 *   @0x1b3374 mov r0, r4
 *   @0x1b3378 ldr r3, [r3]
 *   @0x1b337c vmov s15, r1
 *   @0x1b3380 rsb r2, r2, #0
 *   @0x1b3384 mov r12, #0
 *   @0x1b3388 vcvt.f32.s32 s15, s15
 *   @0x1b338c movt r12, #0x46fa
 *   @0x1b3390 mul r2, r3, r2
 *   @0x1b3394 str r12, [sp]
 *   @0x1b3398 mov r3, lr
 *   @0x1b339c mov r12, #0
 *   @0x1b33a0 str lr, [sp, #0x44]
 *   @0x1b33a4 str r12, [sp, #0x40]
 *   @0x1b33a8 str r12, [sp, #0x3c]
 *   @0x1b33ac vmov r1, s15
 *   @0x1b33b0 vmov s15, r2
 *   @0x1b33b4 str r12, [sp, #0x38]
 *   @0x1b33b8 str r12, [sp, #0x34]
 *   @0x1b33bc vcvt.f32.s32 s15, s15
 *   @0x1b33c0 str lr, [sp, #0x30]
 *   @0x1b33c4 str lr, [sp, #0x1c]
 *   @0x1b33c8 str lr, [sp, #0x8]
 *   @0x1b33cc str r12, [sp, #0x2c]
 *   @0x1b33d0 str r12, [sp, #0x28]
 *   @0x1b33d4 str r12, [sp, #0x24]
 *   @0x1b33d8 str r12, [sp, #0x20]
 *   @0x1b33dc vmov r2, s15
 *   @0x1b33e0 str r12, [sp, #0x18]
 *   @0x1b33e4 str r12, [sp, #0x14]
 *   @0x1b33e8 str r12, [sp, #0x10]
 *   @0x1b33ec str r12, [sp, #0xc]
 *   @0x1b33f0 bl 0x27b274 <_ZN8yyMatrix7OrthoLHEPS_ffff>
 *   @0x1b33f4 mov r1, r4
 *   @0x1b33f8 mov r0, #1
 *   @0x1b33fc bl 0x17eb1c <_ZN8Graphics9SetMatrixE7eMatrixPf>
 *   @0x1b3400 bl 0x1b3204 <_Z14Calc_GUI_Scalev>
 *   @0x1b3404 add sp, sp, #76
 *   @0x1b3408 pop {r4, r5, pc}
 *   @0x1b340c eoreq r12, r3, r4, asr r11
 *   @0x1b3410 eoreq r12, r3, r4, asr r11
 *   @0x1b3414 eoreq r12, r3, r4, ror sp
 *
 * ══ §52/56 MainLoop_Init  0x1d3658  size 232  58 条（0x1d3658..0x1d3740）
 * @func 0x1d3658 0x1d3740  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d3668→0x542a40, 0x1d3670→0x5428f4, 0x1d3674→0x542a1c, 0x1d367c→0x542a28, 0x1d36a8→0x3eb6b8, 0x1d3708→0x5429f8
 * 调用序列: Timing_Time×2 / ProcessMessages() / DisplayMemoryError(unsigned int, char const*)
 * 字段偏移 top8: 0xc×3 / 0xac×2 / 0xa8×2 / 0xa4×2 / 0x80×1 / 0x60×1 / 0x3c×1 / 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d3658 push {r4, r5, r6, lr}
 *   @0x1d365c bl 0x215148 <Timing_Time>
 *   @0x1d3660 mov r3, #0
 *   @0x1d3664 ldr r4, [pc, #0xac]
 *   @0x1d3668 ldr r2, [pc, #0xac]
 *   @0x1d366c add r4, pc, r4
 *   @0x1d3670 ldr lr, [pc, #0xa8]
 *   @0x1d3674 ldr r12, [pc, #0xa8]
 *   @0x1d3678 ldr r5, [r4, r2]
 *   @0x1d367c ldr r2, [pc, #0xa4]
 *   @0x1d3680 ldr r6, [pc, #0xa4]
 *   @0x1d3684 add r6, pc, r6
 *   @0x1d3688 strd r0, r1, [r5]
 *   @0x1d368c ldr lr, [r4, lr]
 *   @0x1d3690 str r3, [lr]
 *   @0x1d3694 ldr r12, [r4, r12]
 *   @0x1d3698 str r3, [r12]
 *   @0x1d369c ldr r3, [r4, r2]
 *   @0x1d36a0 strd r0, r1, [r3]
 *   @0x1d36a4 bl 0x28fe64 <_Z15ProcessMessagesv>
 *   @0x1d36a8 ldr r3, [pc, #0x80]
 *   @0x1d36ac mov r1, r6
 *   @0x1d36b0 ldr r3, [r4, r3]
 *   @0x1d36b4 ldr r5, [r3]
 *   @0x1d36b8 ldr r3, [r5]
 *   @0x1d36bc mov r0, r5
 *   @0x1d36c0 ldr r3, [r3, #0xc]
 *   @0x1d36c4 blx r3
 *   @0x1d36c8 ldr r3, [r5]
 *   @0x1d36cc ldr r1, [pc, #0x60]
 *   @0x1d36d0 mov r0, r5
 *   @0x1d36d4 add r1, pc, r1
 *   @0x1d36d8 ldr r3, [r3, #0xc]
 *   @0x1d36dc blx r3
 *   @0x1d36e0 ldr r3, [r5]
 *   @0x1d36e4 mov r1, r6
 *   @0x1d36e8 mov r0, r5
 *   @0x1d36ec ldr r3, [r3, #0xc]
 *   @0x1d36f0 blx r3
 *   @0x1d36f4 ldr r1, [pc, #0x3c]
 *   @0x1d36f8 mvn r0, #0
 *   @0x1d36fc add r1, pc, r1
 *   @0x1d3700 bl 0x27d234 <_Z18DisplayMemoryErrorjPKc>
 *   @0x1d3704 bl 0x215148 <Timing_Time>
 *   @0x1d3708 ldr r3, [pc, #0x2c]
 *   @0x1d370c ldr r3, [r4, r3]
 *   @0x1d3710 strd r0, r1, [r3]
 *   @0x1d3714 pop {r4, r5, r6, pc}
 *   @0x1d3718 eoreq lr, r1, r4, ror #11
 *   @0x1d371c .word 0xffffef28
 *   @0x1d3720 .word 0xffffeb1c
 *   @0x1d3724 .word 0xffffef2c
 *   @0x1d3728 .word 0xffffef30
 *   @0x1d372c andseq sp, r7, r4, lsr #20
 *   @0x1d3730 .word 0xffffdecc
 *   @0x1d3734 ldrsheq sp, [r7], -r12
 *   @0x1d3738 andseq sp, r7, r12, ror #19
 *   @0x1d373c .word 0xffffef20
 *
 * ══ §53/56 CPhysicsWorld::~CPhysicsWorld  0x239e68  size 232  58 条（0x239e68..0x239f50）
 * @func 0x239e68 0x239f50  size 232  58 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: CPhysicsWorld::~CPhysicsWorld()+0x4c / CPhysicsWorld::DeleteParticleGroup(int) / b2World::SetContactListener(b2ContactListener*) / b2World::~b2World() / operator delete(void*) / MemoryManager::Free(void const*) / CPhysicsWorld::DestroyBodies() / CPhysicsWorld::DestroyJoints()
 * 字段偏移 top8: 0x10×3 / 0x4c×2 / 0x4×2 / 0x54×1 / 0x70×1 / 0xb4×1 / 0x50×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x239e68 push {r3, r4, r5, lr}
 *   @0x239e6c mov r5, r0
 *   @0x239e70 ldr r0, [r0, #0x10]
 *   @0x239e74 movw r3, #0xfeee
 *   @0x239e78 movt r3, #0xfeee
 *   @0x239e7c cmp r0, r3
 *   @0x239e80 beq 0x239f10 <_ZN13CPhysicsWorldD2Ev+0xa8>
 *   @0x239e84 ldr r3, [r5, #0x4c]
 *   @0x239e88 cmp r3, #0
 *   @0x239e8c ble 0x239eb4 <_ZN13CPhysicsWorldD2Ev+0x4c>
 *   @0x239e90 mov r4, #0
 *   @0x239e94 mov r1, r4
 *   @0x239e98 mov r0, r5
 *   @0x239e9c bl 0x239e34 <_ZN13CPhysicsWorld19DeleteParticleGroupEi>
 *   @0x239ea0 ldr r3, [r5, #0x4c]
 *   @0x239ea4 add r4, r4, #1
 *   @0x239ea8 cmp r3, r4
 *   @0x239eac bgt 0x239e94 <_ZN13CPhysicsWorldD2Ev+0x2c>
 *   @0x239eb0 ldr r0, [r5, #0x10]
 *   @0x239eb4 mov r1, #0
 *   @0x239eb8 bl 0x2c901c <_ZN7b2World18SetContactListenerEP17b2ContactListener>
 *   @0x239ebc ldr r0, [r5, #0x54]
 *   @0x239ec0 cmp r0, #0
 *   @0x239ec4 beq 0x239ed4 <_ZN13CPhysicsWorldD2Ev+0x6c>
 *   @0x239ec8 ldr r3, [r0]
 *   @0x239ecc ldr r3, [r3, #0x4]
 *   @0x239ed0 blx r3
 *   @0x239ed4 ldr r3, [pc, #0x70]
 *   @0x239ed8 ldr r3, [pc, r3]
 *   @0x239edc ldr r3, [r3]
 *   @0x239ee0 cmp r3, #0
 *   @0x239ee4 beq 0x239ef4 <_ZN13CPhysicsWorldD2Ev+0x8c>
 *   @0x239ee8 ldr r3, [r3, #0xb4]
 *   @0x239eec cmp r5, r3
 *   @0x239ef0 beq 0x239f38 <_ZN13CPhysicsWorldD2Ev+0xd0>
 *   @0x239ef4 ldr r4, [r5, #0x10]
 *   @0x239ef8 cmp r4, #0
 *   @0x239efc beq 0x239f10 <_ZN13CPhysicsWorldD2Ev+0xa8>
 *   @0x239f00 mov r0, r4
 *   @0x239f04 bl 0x2c8f74 <_ZN7b2WorldD2Ev>
 *   @0x239f08 mov r0, r4
 *   @0x239f0c bl 0x27d1d0 <_ZdlPv>
 *   @0x239f10 ldr r0, [r5, #0x50]
 *   @0x239f14 cmp r0, #0
 *   @0x239f18 beq 0x239f28 <_ZN13CPhysicsWorldD2Ev+0xc0>
 *   @0x239f1c ldr r3, [r0]
 *   @0x239f20 ldr r3, [r3, #0x4]
 *   @0x239f24 blx r3
 *   @0x239f28 ldr r0, [r5]
 *   @0x239f2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x239f30 mov r0, r5
 *   @0x239f34 pop {r3, r4, r5, pc}
 *   @0x239f38 mov r0, r5
 *   @0x239f3c bl 0x237e94 <_ZN13CPhysicsWorld13DestroyBodiesEv>
 *   @0x239f40 mov r0, r5
 *   @0x239f44 bl 0x237f48 <_ZN13CPhysicsWorld13DestroyJointsEv>
 *   @0x239f48 b 0x239ef4 <_ZN13CPhysicsWorldD2Ev+0x8c>
 *   @0x239f4c andseq r3, r11, r0, asr r10
 *
 * ══ §54/56 YYError  0xd547c  size 228  57 条（0xd547c..0xd5560）
 * @func 0xd547c 0xd5560  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xd5498→0x47b238, 0xd54bc→0x47f3c4, 0xd5524→0x7590d2
 * 调用序列: 0xb667c / Error_Show_Action(char const*, bool) / YYGML_game_end() / 0xb65d4 / 0xb6688
 * 字段偏移 top8: 0x404×2 / 0xbc×1 / 0xb8×1 / 0xb4×1 / 0x420×1 / 0x94×1 / 0x30×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xd547c push {r0, r1, r2, r3}
 *   @0xd5480 push {r4, r5, r6, r7, lr}
 *   @0xd5484 sub sp, sp, #1024
 *   @0xd5488 ldr r4, [pc, #0xbc]
 *   @0xd548c sub sp, sp, #12
 *   @0xd5490 ldr r2, [pc, #0xb8]
 *   @0xd5494 add r4, pc, r4
 *   @0xd5498 ldr r3, [pc, #0xb4]
 *   @0xd549c ldr r1, [sp, #0x420]
 *   @0xd54a0 ldr r5, [r4, r2]
 *   @0xd54a4 ldr r2, [r5]
 *   @0xd54a8 str r2, [sp, #0x404]
 *   @0xd54ac ldr r6, [r4, r3]
 *   @0xd54b0 ldrb r3, [r6]
 *   @0xd54b4 cmp r3, #0
 *   @0xd54b8 beq 0xd54f0 <_Z7YYErrorPKcz+0x74>
 *   @0xd54bc ldr r3, [pc, #0x94]
 *   @0xd54c0 mov r2, #1
 *   @0xd54c4 ldr r3, [r4, r3]
 *   @0xd54c8 strb r2, [r3]
 *   @0xd54cc ldr r2, [sp, #0x404]
 *   @0xd54d0 ldr r3, [r5]
 *   @0xd54d4 cmp r2, r3
 *   @0xd54d8 bne 0xd5540 <_Z7YYErrorPKcz+0xc4>
 *   @0xd54dc add sp, sp, #1024
 *   @0xd54e0 add sp, sp, #12
 *   @0xd54e4 pop {r4, r5, r6, r7, lr}
 *   @0xd54e8 add sp, sp, #16
 *   @0xd54ec bx lr
 *   @0xd54f0 add r3, sp, #1056
 *   @0xd54f4 add r7, sp, #4
 *   @0xd54f8 add r3, r3, #4
 *   @0xd54fc str r3, [sp]
 *   @0xd5500 mov r0, r7
 *   @0xd5504 mov r2, r3
 *   @0xd5508 bl 0xb667c <vsprintf@plt>
 *   @0xd550c ldrb r3, [r6]
 *   @0xd5510 cmp r3, #0
 *   @0xd5514 bne 0xd54cc <_Z7YYErrorPKcz+0x50>
 *   @0xd5518 mov r0, r7
 *   @0xd551c mov r1, #1
 *   @0xd5520 bl 0xecf70 <_Z17Error_Show_ActionPKcb>
 *   @0xd5524 ldr r3, [pc, #0x30]
 *   @0xd5528 ldr r3, [r4, r3]
 *   @0xd552c ldrb r3, [r3]
 *   @0xd5530 cmp r3, #0
 *   @0xd5534 beq 0xd5544 <_Z7YYErrorPKcz+0xc8>
 *   @0xd5538 bl 0x10c320 <_Z14YYGML_game_endv>
 *   @0xd553c b 0xd54cc <_Z7YYErrorPKcz+0x50>
 *   @0xd5540 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0xd5544 mov r0, #1
 *   @0xd5548 bl 0xb6688 <exit@plt>
 *   @0xd554c ldrhteq r12, [r1], -r12
 *   @0xd5550 .word 0xffffbd00
 *   @0xd5554 .word 0xffffbfdc
 *   @0xd5558 .word 0xffffbf14
 *   @0xd555c .word 0xffffbfe0
 *
 * ══ §55/56 F_DsMapAdd_Internal  0x104f64  size 228  57 条（0x104f64..0x105048）
 * @func 0x104f64 0x105048  size 228  57 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYSetString(RValue*, char const*)×2 / FREE_RValue__Pre(RValue*)×2 / DS_AutoMutex::DS_AutoMutex() / CDS_Map::Add(RValue*, RValue*) / DS_AutoMutex::~DS_AutoMutex()
 * 字段偏移 top8: 0x24×2 / 0x14×2 / 0x98×1 / 0x4×1 / 0x2×1 / 0x20×1 / 0x18×1 / 0x10×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x104f64 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x104f68 sub sp, sp, #44
 *   @0x104f6c add r6, sp, #4
 *   @0x104f70 add r4, sp, #8
 *   @0x104f74 mov r7, r0
 *   @0x104f78 mov r9, r1
 *   @0x104f7c add r5, sp, #24
 *   @0x104f80 mov r0, r6
 *   @0x104f84 mov r8, r2
 *   @0x104f88 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x104f8c mov r1, r9
 *   @0x104f90 mov r0, r4
 *   @0x104f94 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x104f98 mov r1, r8
 *   @0x104f9c mov r0, r5
 *   @0x104fa0 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x104fa4 ldr r3, [pc, #0x98]
 *   @0x104fa8 mov r1, r4
 *   @0x104fac mov r2, r5
 *   @0x104fb0 ldr r3, [pc, r3]
 *   @0x104fb4 ldr r3, [r3, #0x4]
 *   @0x104fb8 ldr r0, [r3, r7, lsl #2]
 *   @0x104fbc bl 0x20b884 <_ZN7CDS_Map3AddEP6RValueS1_>
 *   @0x104fc0 ldr r3, [sp, #0x24]
 *   @0x104fc4 sub r3, r3, #1
 *   @0x104fc8 bic r3, r3, #-16777216
 *   @0x104fcc bic r3, r3, #3
 *   @0x104fd0 cmp r3, #0
 *   @0x104fd4 mov r7, r0
 *   @0x104fd8 beq 0x105038 <_Z19F_DsMapAdd_InternaliPcS_+0xd4>
 *   @0x104fdc ldr r1, [sp, #0x14]
 *   @0x104fe0 mov r3, #0
 *   @0x104fe4 str r3, [sp, #0x20]
 *   @0x104fe8 mov r2, #5
 *   @0x104fec sub r1, r1, #1
 *   @0x104ff0 str r3, [sp, #0x18]
 *   @0x104ff4 bic r3, r1, #-16777216
 *   @0x104ff8 str r2, [sp, #0x24]
 *   @0x104ffc bic r3, r3, #3
 *   @0x105000 cmp r3, #0
 *   @0x105004 bne 0x105010 <_Z19F_DsMapAdd_InternaliPcS_+0xac>
 *   @0x105008 mov r0, r4
 *   @0x10500c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105010 mov r0, r6
 *   @0x105014 mov r3, #0
 *   @0x105018 mov r2, #5
 *   @0x10501c str r3, [sp, #0x10]
 *   @0x105020 str r3, [sp, #0x8]
 *   @0x105024 str r2, [sp, #0x14]
 *   @0x105028 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x10502c mov r0, r7
 *   @0x105030 add sp, sp, #44
 *   @0x105034 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x105038 mov r0, r5
 *   @0x10503c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x105040 b 0x104fdc <_Z19F_DsMapAdd_InternaliPcS_+0x78>
 *   @0x105044 eoreq r8, lr, r12, lsl #19
 *
 * ══ §56/56 DeleteCachedAchievement  0x1598a8  size 28  7 条（0x1598a8..0x1598c4）
 * @func 0x1598a8 0x1598c4  size 28  7 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: UnLinkCacheAchievement(SAchivementCache*) / MemoryManager::Free(void const*)
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1598a8 push {r4, lr}
 *   @0x1598ac mov r4, r0
 *   @0x1598b0 bl 0x15978c <_Z22UnLinkCacheAchievementP16SAchivementCache>
 *   @0x1598b4 mov r0, r4
 *   @0x1598b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1598bc pop {r4, lr}
 *   @0x1598c0 b 0x159640 <_Z21FlushAchievementCachev>
 */
