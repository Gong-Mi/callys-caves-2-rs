/* cally 逆向卡：Anon_26f1e8 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 1 个函数｜锚点 9161 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/1 anon_26f1e8  0x26f1e8  size 41380  9161 条（0x26f1e8..0x27938c）｜其中 1184 条已由别的卡落锚，本节不再重复
 * @func 0x26ffac 0x27938c  size 37856  9161 条
 * 部分覆盖: 本节 9161/9464 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * ⚠ 这是一段**不闭合的状态机**，不是独立函数：段内 24 条分支跳出本段、落在 7 个不同目标上（pcre 8.x 的内部匹配器）。METHOD §4 允许给它出卡，但卡面必须声明这一点：本节只保证「每条指令都锚到二进制」，**不保证段内语义闭合**。
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x271470→0x756484, 0x274088→0x3f76dc, 0x2750a8→0x756484, 0x2755ec→0x3f76e0, 0x275804→0x3f76dc, 0x275838→0x3f76dc, 0x2758bc→0x3f76dc
 * 调用序列: anon_26f1e8×57 / anon_26f1e8+0x9dcc×12 / anon_26f1e8+0xa184×11 / anon_26f1e8+0x4e8×9 / _pcre_is_newline×9 / anon_26f1e8+0x3b70×9 / anon_26f1e8+0x4534×8 / anon_26f1e8+0x4c0×7
 * 字段偏移 top8: 0x1×329 / 0x2×174 / 0x4×141 / 0x78×129 / 0x3×112 / 0x18×95 / 0x1c×89 / 0x-2×85
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x26ffac beq 0x2740d4 <pcre_dfa_exec+0x5b6c>
 *   @0x26ffb0 ldr r2, [r6, #0x74]
 *   @0x26ffb4 sub r3, r10, #1
 *   @0x26ffb8 cmp r3, r2
 *   @0x26ffbc blo 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x26ffc0 ldrb r2, [r10, #-0x1]
 *   @0x26ffc4 and r2, r2, #192
 *   @0x26ffc8 cmp r2, #128
 *   @0x26ffcc bne 0x274620 <pcre_dfa_exec+0x60b8>
 *   @0x26ffd0 sub r3, r10, #2
 *   @0x26ffd4 mov r10, r3
 *   @0x26ffd8 sub r3, r3, #1
 *   @0x26ffdc ldrb r2, [r10]
 *   @0x26ffe0 and r2, r2, #192
 *   @0x26ffe4 cmp r2, #128
 *   @0x26ffe8 beq 0x26ffd4 <pcre_dfa_exec+0x1a6c>
 *   @0x26ffec sub r1, r1, #1
 *   @0x26fff0 b 0x26ffa8 <pcre_dfa_exec+0x1a40>
 *   @0x26fff4 ldr r2, [r6, #0x74]
 *   @0x26fff8 ldr r3, [r6, #0x94]
 *   @0x26fffc add r3, r2, r3
 *   @0x270000 cmp r3, r10
 *   @0x270004 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270008 mov r0, #0
 *   @0x27000c add sp, sp, #316
 *   @0x270010 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x270014 subs r3, r5, #159
 *   @0x270018 ldr r12, [sp, #0x1c]
 *   @0x27001c ldr r11, [sp, #0x18]
 *   @0x270020 movne r3, #1
 *   @0x270024 cmp r10, r12
 *   @0x270028 movne r3, #0
 *   @0x27002c cmp r3, #0
 *   @0x270030 beq 0x270040 <pcre_dfa_exec+0x1ad8>
 *   @0x270034 ldr r3, [r6, #0xa4]
 *   @0x270038 cmp r3, #0
 *   @0x27003c beq 0x2768f8 <pcre_dfa_exec+0x8390>
 *   @0x270040 cmp r5, #0
 *   @0x270044 ldr r5, [sp, #0x1c]
 *   @0x270048 str r10, [r6, #0x80]
 *   @0x27004c movwne r0, #0xfc19
 *   @0x270050 str r11, [r6, #0x8c]
 *   @0x270054 str r5, [r6, #0x7c]
 *   @0x270058 movtne r0, #0xffff
 *   @0x27005c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270060 mov r0, #1
 *   @0x270064 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270068 mov r0, #0
 *   @0x27006c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270070 mov r4, r11
 *   @0x270074 ldr r5, [sp, #0x164]
 *   @0x270078 ldr r11, [sp, #0x18]
 *   @0x27007c mov r0, r10
 *   @0x270080 ldr r12, [sp, #0x168]
 *   @0x270084 add r1, r4, #1
 *   @0x270088 str r6, [sp]
 *   @0x27008c mov r3, r11
 *   @0x270090 add r12, r12, #1
 *   @0x270094 str r5, [sp, #0x4]
 *   @0x270098 ldr r2, [sp, #0x1c]
 *   @0x27009c str r12, [sp, #0x8]
 *   @0x2700a0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2700a4 movw r3, #0xfc1c
 *   @0x2700a8 movt r3, #0xffff
 *   @0x2700ac cmp r0, #0
 *   @0x2700b0 moveq r0, r3
 *   @0x2700b4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2700b8 ldrb r2, [r11, #0x1]
 *   @0x2700bc ldrb r3, [r11, #0x2]
 *   @0x2700c0 ldr r1, [r6, #0x14]
 *   @0x2700c4 orr r2, r3, r2, lsl #8
 *   @0x2700c8 ldrh r3, [r6, #146]
 *   @0x2700cc lsl r0, r2, #1
 *   @0x2700d0 cmp r0, r1
 *   @0x2700d4 orr r3, r2, r3, lsl #16
 *   @0x2700d8 str r3, [r6, #0x90]
 *   @0x2700dc orrge r3, r3, #65536
 *   @0x2700e0 strge r3, [r6, #0x90]
 *   @0x2700e4 bge 0x26fd70 <pcre_dfa_exec+0x1808>
 *   @0x2700e8 ldr r1, [r6, #0x10]
 *   @0x2700ec ldr r3, [r6, #0xc]
 *   @0x2700f0 rsb r1, r2, r1
 *   @0x2700f4 ldr r7, [sp, #0x18]
 *   @0x2700f8 ldr r12, [r6, #0x74]
 *   @0x2700fc ldr r4, [r3, r1, lsl #2]
 *   @0x270100 cmp r7, r0
 *   @0x270104 add r1, r3, r2, lsl #3
 *   @0x270108 rsb r12, r12, r10
 *   @0x27010c str r4, [r3, r2, lsl #3]
 *   @0x270110 str r12, [r1, #0x4]
 *   @0x270114 bgt 0x26fd70 <pcre_dfa_exec+0x1808>
 *   @0x270118 add r3, r3, r7, lsl #2
 *   @0x27011c cmp r1, r3
 *   @0x270120 mvnhi r2, #0
 *   @0x270124 bls 0x270134 <pcre_dfa_exec+0x1bcc>
 *   @0x270128 str r2, [r3], #4
 *   @0x27012c cmp r1, r3
 *   @0x270130 bhi 0x270128 <pcre_dfa_exec+0x1bc0>
 *   @0x270134 add r0, r0, #2
 *   @0x270138 str r0, [sp, #0x18]
 *   @0x27013c b 0x26fd70 <pcre_dfa_exec+0x1808>
 *   @0x270140 ldrb r2, [r11, #0x1]
 *   @0x270144 add r8, r11, #3
 *   @0x270148 ldrb r3, [r11, #0x2]
 *   @0x27014c orr r3, r3, r2, lsl #8
 *   @0x270150 ldrb r1, [r11, r3]!
 *   @0x270154 sub r2, r1, #98
 *   @0x270158 uxtb r3, r2
 *   @0x27015c cmp r3, #11
 *   @0x270160 bhi 0x27660c <pcre_dfa_exec+0x80a4>
 *   @0x270164 mov r12, #1
 *   @0x270168 lsl r3, r12, r3
 *   @0x27016c ands r4, r3, #2240
 *   @0x270170 bne 0x274744 <pcre_dfa_exec+0x61dc>
 *   @0x270174 movw r1, #0x73f
 *   @0x270178 and r1, r3, r1
 *   @0x27017c cmp r1, #0
 *   @0x270180 beq 0x277494 <pcre_dfa_exec+0x8f2c>
 *   @0x270184 ldr r5, [sp, #0x44]
 *   @0x270188 cmp r2, #7
 *   @0x27018c strls r4, [sp, #0x2c]
 *   @0x270190 andls r4, r2, r12
 *   @0x270194 add r2, r5, r2
 *   @0x270198 movhi r3, #1
 *   @0x27019c strhi r3, [sp, #0x2c]
 *   @0x2701a0 add r11, r11, r12
 *   @0x2701a4 ldrb r7, [r2, #-0xc18]
 *   @0x2701a8 ldrb r5, [r2, #-0xc24]
 *   @0x2701ac cmp r7, #0
 *   @0x2701b0 mvneq r7, #-2147483648
 *   @0x2701b4 cmp r5, #0
 *   @0x2701b8 beq 0x274e6c <pcre_dfa_exec+0x6904>
 *   @0x2701bc ldr r3, [r6, #0x78]
 *   @0x2701c0 cmp r10, r3
 *   @0x2701c4 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2701c8 mov r9, #1
 *   @0x2701cc str r4, [sp, #0x30]
 *   @0x2701d0 str r11, [sp, #0x4c]
 *   @0x2701d4 mov r11, r7
 *   @0x2701d8 ldr r4, [sp, #0x24]
 *   @0x2701dc mov r7, r6
 *   @0x2701e0 mov r6, r9
 *   @0x2701e4 ldr r9, [sp, #0x28]
 *   @0x2701e8 b 0x27024c <pcre_dfa_exec+0x1ce4>
 *   @0x2701ec andseq r2, r8, r4, asr r10
 *   @0x2701f0 andseq r12, r1, r8, lsr #18
 *   @0x2701f4 andseq r12, r1, r4, lsr #18
 *   @0x2701f8 andseq r12, r1, r12, lsl r9
 *   @0x2701fc andseq r12, r1, r4, lsl #18
 *   @0x270200 andseq r12, r1, r0, lsl #18
 *   @0x270204 ldrsheq r12, [r1], -r8
 *   @0x270208 .word 0xfffffb8c
 *   @0x27020c ldrb r2, [r10, #0x1]
 *   @0x270210 and r0, r0, #31
 *   @0x270214 add r10, r10, #2
 *   @0x270218 and r2, r2, #63
 *   @0x27021c orr r0, r2, r0, lsl #6
 *   @0x270220 mov r1, r8
 *   @0x270224 mov r2, r9
 *   @0x270228 bl 0x266cac <_pcre_xclass>
 *   @0x27022c cmp r0, #0
 *   @0x270230 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270234 add r6, r6, #1
 *   @0x270238 cmp r5, r6
 *   @0x27023c blt 0x274e54 <pcre_dfa_exec+0x68ec>
 *   @0x270240 ldr r2, [r7, #0x78]
 *   @0x270244 cmp r10, r2
 *   @0x270248 bhs 0x272d54 <pcre_dfa_exec+0x47ec>
 *   @0x27024c ldrb r0, [r10]
 *   @0x270250 cmp r0, #191
 *   @0x270254 movls r2, #0
 *   @0x270258 andhi r2, r4, #1
 *   @0x27025c cmp r2, #0
 *   @0x270260 addeq r10, r10, #1
 *   @0x270264 beq 0x270220 <pcre_dfa_exec+0x1cb8>
 *   @0x270268 tst r0, #32
 *   @0x27026c beq 0x27020c <pcre_dfa_exec+0x1ca4>
 *   @0x270270 tst r0, #16
 *   @0x270274 bne 0x273538 <pcre_dfa_exec+0x4fd0>
 *   @0x270278 lsl r1, r0, #12
 *   @0x27027c ldrb r2, [r10, #0x2]
 *   @0x270280 ldrb r0, [r10, #0x1]
 *   @0x270284 add r10, r10, #3
 *   @0x270288 uxth r1, r1
 *   @0x27028c and r2, r2, #63
 *   @0x270290 and r0, r0, #63
 *   @0x270294 orr r2, r1, r2
 *   @0x270298 orr r0, r2, r0, lsl #6
 *   @0x27029c b 0x270220 <pcre_dfa_exec+0x1cb8>
 *   @0x2702a0 ldrb r2, [r11, #0x1]
 *   @0x2702a4 subs r4, r5, #114
 *   @0x2702a8 ldrb r3, [r11, #0x2]
 *   @0x2702ac rsbs r9, r4, #0
 *   @0x2702b0 ldr r5, [sp, #0x18]
 *   @0x2702b4 adcs r9, r9, r4
 *   @0x2702b8 orr r3, r3, r2, lsl #8
 *   @0x2702bc add r11, r11, #3
 *   @0x2702c0 lsl r7, r3, #1
 *   @0x2702c4 cmp r5, r7
 *   @0x2702c8 ble 0x2742d4 <pcre_dfa_exec+0x5d6c>
 *   @0x2702cc ldr r2, [r6, #0xc]
 *   @0x2702d0 lsl r1, r3, #3
 *   @0x2702d4 ldr r3, [r2, r3, lsl #3]
 *   @0x2702d8 cmp r3, #0
 *   @0x2702dc blt 0x2742d4 <pcre_dfa_exec+0x5d6c>
 *   @0x2702e0 add r2, r2, r1
 *   @0x2702e4 ldr r8, [r2, #0x4]
 *   @0x2702e8 rsb r8, r3, r8
 *   @0x2702ec ldrb r5, [r11]
 *   @0x2702f0 sub r3, r5, #98
 *   @0x2702f4 cmp r3, #7
 *   @0x2702f8 addls pc, pc, r3, lsl #2
 *   @0x2702fc b 0x2741e4 <pcre_dfa_exec+0x5c7c>
 *   @0x270300 b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x270304 b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x270308 b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x27030c b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x270310 b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x270314 b 0x2719e4 <pcre_dfa_exec+0x347c>
 *   @0x270318 b 0x271920 <pcre_dfa_exec+0x33b8>
 *   @0x27031c b 0x271920 <pcre_dfa_exec+0x33b8>
 *   @0x270320 ldr r9, [r6, #0x78]
 *   @0x270324 cmp r10, r9
 *   @0x270328 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x27032c ldrb r3, [r10]
 *   @0x270330 ldr r2, [sp, #0x24]
 *   @0x270334 cmp r3, #191
 *   @0x270338 movls r2, #0
 *   @0x27033c andhi r2, r2, #1
 *   @0x270340 cmp r2, #0
 *   @0x270344 addeq r10, r10, #1
 *   @0x270348 beq 0x270368 <pcre_dfa_exec+0x1e00>
 *   @0x27034c tst r3, #32
 *   @0x270350 bne 0x2752f8 <pcre_dfa_exec+0x6d90>
 *   @0x270354 ldrb r2, [r10, #0x1]
 *   @0x270358 and r3, r3, #31
 *   @0x27035c add r10, r10, #2
 *   @0x270360 and r2, r2, #63
 *   @0x270364 orr r3, r2, r3, lsl #6
 *   @0x270368 cmp r3, #133
 *   @0x27036c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270370 bhi 0x274dc0 <pcre_dfa_exec+0x6858>
 *   @0x270374 sub r3, r3, #10
 *   @0x270378 cmp r3, #3
 *   @0x27037c bls 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270380 mov r0, #0
 *   @0x270384 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270388 ldr r9, [r6, #0x78]
 *   @0x27038c cmp r10, r9
 *   @0x270390 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270394 ldrb r3, [r10]
 *   @0x270398 ldr r2, [sp, #0x24]
 *   @0x27039c cmp r3, #191
 *   @0x2703a0 movls r2, #0
 *   @0x2703a4 andhi r2, r2, #1
 *   @0x2703a8 cmp r2, #0
 *   @0x2703ac addeq r10, r10, #1
 *   @0x2703b0 beq 0x2703d0 <pcre_dfa_exec+0x1e68>
 *   @0x2703b4 tst r3, #32
 *   @0x2703b8 bne 0x275358 <pcre_dfa_exec+0x6df0>
 *   @0x2703bc ldrb r2, [r10, #0x1]
 *   @0x2703c0 and r3, r3, #31
 *   @0x2703c4 add r10, r10, #2
 *   @0x2703c8 and r2, r2, #63
 *   @0x2703cc orr r3, r2, r3, lsl #6
 *   @0x2703d0 cmp r3, #133
 *   @0x2703d4 beq 0x2703e8 <pcre_dfa_exec+0x1e80>
 *   @0x2703d8 bhi 0x2745bc <pcre_dfa_exec+0x6054>
 *   @0x2703dc sub r3, r3, #10
 *   @0x2703e0 cmp r3, #3
 *   @0x2703e4 bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2703e8 mov r0, #0
 *   @0x2703ec b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2703f0 mov r12, #0
 *   @0x2703f4 str r12, [sp, #0x30]
 *   @0x2703f8 b 0x26f86c <pcre_dfa_exec+0x1304>
 *   @0x2703fc cmp r5, #45
 *   @0x270400 ldr r7, [sp, #0x3c]
 *   @0x270404 add r4, r11, #1
 *   @0x270408 movhi r2, #46
 *   @0x27040c movls r2, #33
 *   @0x270410 rsb r2, r2, r5
 *   @0x270414 add r3, r7, r2
 *   @0x270418 and r2, r2, #1
 *   @0x27041c str r2, [sp, #0x4c]
 *   @0x270420 ldrb r12, [r3, #-0xc18]
 *   @0x270424 ldrb r7, [r3, #-0xc24]
 *   @0x270428 mov r3, #0
 *   @0x27042c cmp r12, #0
 *   @0x270430 str r3, [sp, #0x30]
 *   @0x270434 str r12, [sp, #0x2c]
 *   @0x270438 mvneq r12, #-2147483648
 *   @0x27043c streq r12, [sp, #0x2c]
 *   @0x270440 b 0x26f898 <pcre_dfa_exec+0x1330>
 *   @0x270444 ldr r5, [sp, #0x24]
 *   @0x270448 cmp r5, #0
 *   @0x27044c beq 0x274588 <pcre_dfa_exec+0x6020>
 *   @0x270450 ldrb r5, [r11, #0x1]
 *   @0x270454 add r2, r11, #1
 *   @0x270458 cmp r5, #191
 *   @0x27045c movls r3, #1
 *   @0x270460 bls 0x270494 <pcre_dfa_exec+0x1f2c>
 *   @0x270464 tst r5, #32
 *   @0x270468 moveq r3, #2
 *   @0x27046c beq 0x270494 <pcre_dfa_exec+0x1f2c>
 *   @0x270470 tst r5, #16
 *   @0x270474 moveq r3, #3
 *   @0x270478 beq 0x270494 <pcre_dfa_exec+0x1f2c>
 *   @0x27047c tst r5, #8
 *   @0x270480 moveq r3, #4
 *   @0x270484 beq 0x270494 <pcre_dfa_exec+0x1f2c>
 *   @0x270488 tst r5, #4
 *   @0x27048c moveq r3, #5
 *   @0x270490 movne r3, #6
 *   @0x270494 ldr r9, [r6, #0x78]
 *   @0x270498 rsb r1, r10, r9
 *   @0x27049c cmp r3, r1
 *   @0x2704a0 ble 0x2704b8 <pcre_dfa_exec+0x1f50>
 *   @0x2704a4 b 0x278b1c <pcre_dfa_exec+0xa5b4>
 *   @0x2704a8 ldrb r1, [r10], #1
 *   @0x2704ac cmp r1, r5
 *   @0x2704b0 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2704b4 ldrb r5, [r2, #0x1]!
 *   @0x2704b8 cmp r3, #0
 *   @0x2704bc mov r11, r2
 *   @0x2704c0 sub r3, r3, #1
 *   @0x2704c4 bgt 0x2704a8 <pcre_dfa_exec+0x1f40>
 *   @0x2704c8 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2704cc ldr r3, [r6, #0x44]
 *   @0x2704d0 ldr r2, [r6, #0x74]
 *   @0x2704d4 cmp r3, #0
 *   @0x2704d8 beq 0x27447c <pcre_dfa_exec+0x5f14>
 *   @0x2704dc cmp r2, r10
 *   @0x2704e0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2704e4 ldr r9, [r6, #0x78]
 *   @0x2704e8 cmp r9, r10
 *   @0x2704ec beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2704f0 ldr r1, [r6, #0x18]
 *   @0x2704f4 cmp r1, #0
 *   @0x2704f8 beq 0x2749ec <pcre_dfa_exec+0x6484>
 *   @0x2704fc cmp r10, r2
 *   @0x270500 bhi 0x275f34 <pcre_dfa_exec+0x79cc>
 *   @0x270504 mov r0, #0
 *   @0x270508 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27050c ldrb r7, [r11, #0x3]
 *   @0x270510 ldrb r2, [r11, #0x4]
 *   @0x270514 ldr r3, [r6, #0x14]
 *   @0x270518 orr r7, r2, r7, lsl #8
 *   @0x27051c cmp r3, r7, lsl #1
 *   @0x270520 ble 0x26f5a8 <pcre_dfa_exec+0x1040>
 *   @0x270524 ldr r2, [r6, #0x10]
 *   @0x270528 lsl r8, r7, #3
 *   @0x27052c ldr r3, [r6, #0xc]
 *   @0x270530 cmp r5, #135
 *   @0x270534 rsb r2, r7, r2
 *   @0x270538 add r8, r8, #4
 *   @0x27053c ldr r1, [r6, #0x74]
 *   @0x270540 mov r4, r11
 *   @0x270544 ldr r5, [r3, r2, lsl #2]
 *   @0x270548 ldr r12, [r3, r8]
 *   @0x27054c rsb r1, r1, r10
 *   @0x270550 ldr r11, [sp, #0x18]
 *   @0x270554 str r5, [sp, #0x38]
 *   @0x270558 ldr r5, [r3, r7, lsl #3]
 *   @0x27055c str r12, [sp, #0x34]
 *   @0x270560 ldr r12, [r6, #0x90]
 *   @0x270564 str r5, [sp, #0x28]
 *   @0x270568 ldr r5, [r6, #0xac]
 *   @0x27056c str r12, [sp, #0x18]
 *   @0x270570 str r1, [r3, r2, lsl #2]
 *   @0x270574 str r5, [sp, #0x24]
 *   @0x270578 ldr r3, [pc, #-0x378]
 *   @0x27057c bhi 0x27890c <pcre_dfa_exec+0xa3a4>
 *   @0x270580 ldr r12, [sp, #0x20]
 *   @0x270584 mvn r9, #996
 *   @0x270588 ldr r5, [r12, r3]
 *   @0x27058c b 0x2705c0 <pcre_dfa_exec+0x2058>
 *   @0x270590 cmp r0, #0
 *   @0x270594 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270598 ldr r12, [sp, #0x18]
 *   @0x27059c str r12, [r6, #0x90]
 *   @0x2705a0 ldrb r2, [r4, #0x1]
 *   @0x2705a4 ldrb r3, [r4, #0x2]
 *   @0x2705a8 ldr r12, [sp, #0x24]
 *   @0x2705ac orr r3, r3, r2, lsl #8
 *   @0x2705b0 str r12, [r6, #0xac]
 *   @0x2705b4 ldrb r3, [r4, r3]!
 *   @0x2705b8 cmp r3, #119
 *   @0x2705bc bne 0x2784e0 <pcre_dfa_exec+0x9f78>
 *   @0x2705c0 ldrb r1, [r4]
 *   @0x2705c4 mov r0, r10
 *   @0x2705c8 ldr lr, [sp, #0x164]
 *   @0x2705cc mov r3, r11
 *   @0x2705d0 ldr r12, [sp, #0x168]
 *   @0x2705d4 ldrb r1, [r5, r1]
 *   @0x2705d8 add r12, r12, #1
 *   @0x2705dc ldr r2, [sp, #0x1c]
 *   @0x2705e0 str r6, [sp]
 *   @0x2705e4 add r1, r4, r1
 *   @0x2705e8 str lr, [sp, #0x4]
 *   @0x2705ec str r12, [sp, #0x8]
 *   @0x2705f0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2705f4 cmp r0, r9
 *   @0x2705f8 beq 0x2784e4 <pcre_dfa_exec+0x9f7c>
 *   @0x2705fc cmn r0, #992
 *   @0x270600 bne 0x270590 <pcre_dfa_exec+0x2028>
 *   @0x270604 ldrb r1, [r4, #0x1]
 *   @0x270608 ldrb r3, [r4, #0x2]
 *   @0x27060c ldr r2, [r6, #0x7c]
 *   @0x270610 orr r3, r3, r1, lsl #8
 *   @0x270614 add r3, r4, r3
 *   @0x270618 cmp r3, r2
 *   @0x27061c bls 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x270620 ldrb r2, [r4]
 *   @0x270624 cmp r2, #119
 *   @0x270628 beq 0x270598 <pcre_dfa_exec+0x2030>
 *   @0x27062c ldrb r3, [r3]
 *   @0x270630 cmp r3, #119
 *   @0x270634 bne 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x270638 b 0x270598 <pcre_dfa_exec+0x2030>
 *   @0x27063c mov r12, #1
 *   @0x270640 mov r7, #0
 *   @0x270644 str r12, [sp, #0x2c]
 *   @0x270648 add r4, r11, r12
 *   @0x27064c str r7, [sp, #0x4c]
 *   @0x270650 str r12, [sp, #0x30]
 *   @0x270654 b 0x26f898 <pcre_dfa_exec+0x1330>
 *   @0x270658 mov r7, #1
 *   @0x27065c mvn r12, #-2147483648
 *   @0x270660 mov r3, #0
 *   @0x270664 add r4, r11, r7
 *   @0x270668 str r7, [sp, #0x30]
 *   @0x27066c str r12, [sp, #0x2c]
 *   @0x270670 str r3, [sp, #0x4c]
 *   @0x270674 b 0x26f898 <pcre_dfa_exec+0x1330>
 *   @0x270678 mov r7, #0
 *   @0x27067c mvn r12, #-2147483648
 *   @0x270680 mov r3, #1
 *   @0x270684 add r4, r11, #1
 *   @0x270688 str r7, [sp, #0x4c]
 *   @0x27068c str r12, [sp, #0x2c]
 *   @0x270690 str r3, [sp, #0x30]
 *   @0x270694 b 0x26f898 <pcre_dfa_exec+0x1330>
 *   @0x270698 ldrb r2, [r11, #0x1]
 *   @0x27069c mov r12, #0
 *   @0x2706a0 ldrb r3, [r11, #0x2]
 *   @0x2706a4 add r4, r11, #3
 *   @0x2706a8 str r12, [sp, #0x30]
 *   @0x2706ac orr r3, r3, r2, lsl #8
 *   @0x2706b0 str r12, [sp, #0x4c]
 *   @0x2706b4 str r3, [sp, #0x2c]
 *   @0x2706b8 mov r7, r3
 *   @0x2706bc b 0x26f898 <pcre_dfa_exec+0x1330>
 *   @0x2706c0 ldr r9, [r6, #0x78]
 *   @0x2706c4 cmp r10, r9
 *   @0x2706c8 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2706cc ldrb r3, [r10]
 *   @0x2706d0 ldr r2, [sp, #0x24]
 *   @0x2706d4 cmp r3, #191
 *   @0x2706d8 movls r2, #0
 *   @0x2706dc andhi r2, r2, #1
 *   @0x2706e0 cmp r2, #0
 *   @0x2706e4 addeq r10, r10, #1
 *   @0x2706e8 beq 0x270710 <pcre_dfa_exec+0x21a8>
 *   @0x2706ec tst r3, #32
 *   @0x2706f0 bne 0x2754a4 <pcre_dfa_exec+0x6f3c>
 *   @0x2706f4 ldrb r2, [r10, #0x1]
 *   @0x2706f8 and r3, r3, #31
 *   @0x2706fc add r10, r10, #2
 *   @0x270700 and r2, r2, #63
 *   @0x270704 orr r3, r2, r3, lsl #6
 *   @0x270708 cmp r3, #255
 *   @0x27070c bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270710 ldr r2, [r6, #0x40]
 *   @0x270714 ldrb r3, [r2, r3]
 *   @0x270718 tst r3, #16
 *   @0x27071c bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270720 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270724 ldr r9, [r6, #0x78]
 *   @0x270728 cmp r10, r9
 *   @0x27072c bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270730 ldrb r3, [r10]
 *   @0x270734 ldr r2, [sp, #0x24]
 *   @0x270738 cmp r3, #191
 *   @0x27073c movls r2, #0
 *   @0x270740 andhi r2, r2, #1
 *   @0x270744 cmp r2, #0
 *   @0x270748 addeq r10, r10, #1
 *   @0x27074c beq 0x27076c <pcre_dfa_exec+0x2204>
 *   @0x270750 tst r3, #32
 *   @0x270754 bne 0x275474 <pcre_dfa_exec+0x6f0c>
 *   @0x270758 ldrb r2, [r10, #0x1]
 *   @0x27075c and r3, r3, #31
 *   @0x270760 add r10, r10, #2
 *   @0x270764 and r2, r2, #63
 *   @0x270768 orr r3, r2, r3, lsl #6
 *   @0x27076c cmp r3, #13
 *   @0x270770 beq 0x2753cc <pcre_dfa_exec+0x6e64>
 *   @0x270774 bhi 0x275010 <pcre_dfa_exec+0x6aa8>
 *   @0x270778 cmp r3, #10
 *   @0x27077c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270780 blo 0x27502c <pcre_dfa_exec+0x6ac4>
 *   @0x270784 ldr r3, [r6, #0x68]
 *   @0x270788 cmp r3, #0
 *   @0x27078c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270790 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270794 ldr r9, [r6, #0x78]
 *   @0x270798 cmp r10, r9
 *   @0x27079c bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2707a0 ldrb r3, [r10]
 *   @0x2707a4 ldr r2, [sp, #0x24]
 *   @0x2707a8 cmp r3, #191
 *   @0x2707ac movls r2, #0
 *   @0x2707b0 andhi r2, r2, #1
 *   @0x2707b4 cmp r2, #0
 *   @0x2707b8 addeq r10, r10, #1
 *   @0x2707bc beq 0x2707e4 <pcre_dfa_exec+0x227c>
 *   @0x2707c0 tst r3, #32
 *   @0x2707c4 bne 0x275328 <pcre_dfa_exec+0x6dc0>
 *   @0x2707c8 ldrb r2, [r10, #0x1]
 *   @0x2707cc and r3, r3, #31
 *   @0x2707d0 add r10, r10, #2
 *   @0x2707d4 and r2, r2, #63
 *   @0x2707d8 orr r3, r2, r3, lsl #6
 *   @0x2707dc cmp r3, #255
 *   @0x2707e0 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2707e4 ldr r2, [r6, #0x40]
 *   @0x2707e8 ldrb r3, [r2, r3]
 *   @0x2707ec tst r3, #4
 *   @0x2707f0 bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2707f4 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2707f8 ldr r12, [sp, #0x24]
 *   @0x2707fc ldr r3, [r6, #0x74]
 *   @0x270800 cmp r12, #0
 *   @0x270804 beq 0x2744c0 <pcre_dfa_exec+0x5f58>
 *   @0x270808 cmp r3, r10
 *   @0x27080c beq 0x270878 <pcre_dfa_exec+0x2310>
 *   @0x270810 ldrb r3, [r10, #-0x1]
 *   @0x270814 sub r2, r10, #1
 *   @0x270818 and r3, r3, #192
 *   @0x27081c cmp r3, #128
 *   @0x270820 bne 0x270840 <pcre_dfa_exec+0x22d8>
 *   @0x270824 sub r3, r10, #2
 *   @0x270828 mov r2, r3
 *   @0x27082c sub r3, r3, #1
 *   @0x270830 ldrb r1, [r2]
 *   @0x270834 and r1, r1, #192
 *   @0x270838 cmp r1, #128
 *   @0x27083c beq 0x270828 <pcre_dfa_exec+0x22c0>
 *   @0x270840 ldr r3, [r6, #0x84]
 *   @0x270844 cmp r3, r2
 *   @0x270848 strhi r2, [r6, #0x84]
 *   @0x27084c ldrb r3, [r2]
 *   @0x270850 cmp r3, #191
 *   @0x270854 bls 0x27573c <pcre_dfa_exec+0x71d4>
 *   @0x270858 tst r3, #32
 *   @0x27085c bne 0x2765a8 <pcre_dfa_exec+0x8040>
 *   @0x270860 ldrb r2, [r2, #0x1]
 *   @0x270864 and r3, r3, #31
 *   @0x270868 and r2, r2, #63
 *   @0x27086c orr r3, r2, r3, lsl #6
 *   @0x270870 cmp r3, #255
 *   @0x270874 bls 0x27573c <pcre_dfa_exec+0x71d4>
 *   @0x270878 mov r0, #0
 *   @0x27087c ldr r9, [r6, #0x78]
 *   @0x270880 cmp r10, r9
 *   @0x270884 blo 0x275234 <pcre_dfa_exec+0x6ccc>
 *   @0x270888 ldr r2, [r6, #0x88]
 *   @0x27088c cmp r2, #0
 *   @0x270890 beq 0x2708b4 <pcre_dfa_exec+0x234c>
 *   @0x270894 ldr r3, [r6, #0x84]
 *   @0x270898 cmp r10, r3
 *   @0x27089c bls 0x2708b0 <pcre_dfa_exec+0x2348>
 *   @0x2708a0 cmp r2, #1
 *   @0x2708a4 mov r1, #1
 *   @0x2708a8 str r1, [r6, #0x64]
 *   @0x2708ac bgt 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x2708b0 mov r2, #0
 *   @0x2708b4 ldrb r1, [r11]
 *   @0x2708b8 add r3, r11, #1
 *   @0x2708bc cmp r1, #5
 *   @0x2708c0 eorne r2, r0, r2
 *   @0x2708c4 andne r2, r2, #1
 *   @0x2708c8 beq 0x2751ac <pcre_dfa_exec+0x6c44>
 *   @0x2708cc cmp r2, #0
 *   @0x2708d0 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2708d4 ldrb r5, [r11, #0x1]
 *   @0x2708d8 mov r11, r3
 *   @0x2708dc b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2708e0 ldrb r5, [r11, #0x1]
 *   @0x2708e4 add r11, r11, #1
 *   @0x2708e8 str r10, [sp, #0x1c]
 *   @0x2708ec b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2708f0 ldr r9, [r6, #0x78]
 *   @0x2708f4 cmp r10, r9
 *   @0x2708f8 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2708fc ldrb r3, [r10]
 *   @0x270900 ldr r2, [sp, #0x24]
 *   @0x270904 cmp r3, #191
 *   @0x270908 movls r2, #0
 *   @0x27090c andhi r2, r2, #1
 *   @0x270910 cmp r2, #0
 *   @0x270914 addeq r10, r10, #1
 *   @0x270918 beq 0x270938 <pcre_dfa_exec+0x23d0>
 *   @0x27091c tst r3, #32
 *   @0x270920 bne 0x275414 <pcre_dfa_exec+0x6eac>
 *   @0x270924 ldrb r2, [r10, #0x1]
 *   @0x270928 and r3, r3, #31
 *   @0x27092c add r10, r10, #2
 *   @0x270930 and r2, r2, #63
 *   @0x270934 orr r3, r2, r3, lsl #6
 *   @0x270938 movw r2, #0x180e
 *   @0x27093c cmp r3, r2
 *   @0x270940 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270944 bhi 0x2747dc <pcre_dfa_exec+0x6274>
 *   @0x270948 cmp r3, #32
 *   @0x27094c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270950 bls 0x2763f4 <pcre_dfa_exec+0x7e8c>
 *   @0x270954 cmp r3, #160
 *   @0x270958 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x27095c cmp r3, #5760
 *   @0x270960 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270964 mov r0, #0
 *   @0x270968 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27096c ldr r4, [r6, #0x98]
 *   @0x270970 mov r5, #0
 *   @0x270974 ldr r7, [r6, #0xac]
 *   @0x270978 cmp r4, #1
 *   @0x27097c movne r4, #0
 *   @0x270980 moveq r3, #0
 *   @0x270984 streq r3, [r6, #0x98]
 *   @0x270988 ldr r3, [sp, #0x168]
 *   @0x27098c mov r0, r10
 *   @0x270990 str r6, [sp]
 *   @0x270994 add r1, r11, #3
 *   @0x270998 add r3, r3, #1
 *   @0x27099c str r5, [sp, #0x4]
 *   @0x2709a0 str r3, [sp, #0x8]
 *   @0x2709a4 ldr r2, [sp, #0x1c]
 *   @0x2709a8 ldr r3, [sp, #0x18]
 *   @0x2709ac bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2709b0 str r7, [r6, #0xac]
 *   @0x2709b4 cmn r0, #992
 *   @0x2709b8 blt 0x2742b4 <pcre_dfa_exec+0x5d4c>
 *   @0x2709bc cmp r0, #0
 *   @0x2709c0 beq 0x274e34 <pcre_dfa_exec+0x68cc>
 *   @0x2709c4 cmp r0, #1
 *   @0x2709c8 beq 0x2742cc <pcre_dfa_exec+0x5d64>
 *   @0x2709cc cmn r0, #992
 *   @0x2709d0 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2709d4 ldrb r1, [r11, #0x1]
 *   @0x2709d8 ldrb r3, [r11, #0x2]
 *   @0x2709dc ldr r2, [r6, #0x7c]
 *   @0x2709e0 orr r3, r3, r1, lsl #8
 *   @0x2709e4 add r3, r11, r3
 *   @0x2709e8 cmp r3, r2
 *   @0x2709ec bls 0x270a0c <pcre_dfa_exec+0x24a4>
 *   @0x2709f0 ldrb r2, [r11]
 *   @0x2709f4 cmp r2, #119
 *   @0x2709f8 beq 0x276604 <pcre_dfa_exec+0x809c>
 *   @0x2709fc ldrb r2, [r3]
 *   @0x270a00 cmp r2, #119
 *   @0x270a04 moveq r11, r3
 *   @0x270a08 beq 0x270988 <pcre_dfa_exec+0x2420>
 *   @0x270a0c ldrb r2, [r11, #0x1]
 *   @0x270a10 ldrb r3, [r11, #0x2]
 *   @0x270a14 orr r3, r3, r2, lsl #8
 *   @0x270a18 ldrb r3, [r11, r3]!
 *   @0x270a1c cmp r3, #119
 *   @0x270a20 beq 0x270a0c <pcre_dfa_exec+0x24a4>
 *   @0x270a24 cmp r4, #0
 *   @0x270a28 beq 0x26fd70 <pcre_dfa_exec+0x1808>
 *   @0x270a2c b 0x270060 <pcre_dfa_exec+0x1af8>
 *   @0x270a30 ldr r9, [r6, #0x78]
 *   @0x270a34 cmp r10, r9
 *   @0x270a38 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270a3c ldrb r3, [r10]
 *   @0x270a40 ldr r2, [sp, #0x24]
 *   @0x270a44 cmp r3, #191
 *   @0x270a48 movls r2, #0
 *   @0x270a4c andhi r2, r2, #1
 *   @0x270a50 cmp r2, #0
 *   @0x270a54 addeq r10, r10, #1
 *   @0x270a58 beq 0x270a78 <pcre_dfa_exec+0x2510>
 *   @0x270a5c tst r3, #32
 *   @0x270a60 bne 0x2753e4 <pcre_dfa_exec+0x6e7c>
 *   @0x270a64 ldrb r2, [r10, #0x1]
 *   @0x270a68 and r3, r3, #31
 *   @0x270a6c add r10, r10, #2
 *   @0x270a70 and r2, r2, #63
 *   @0x270a74 orr r3, r2, r3, lsl #6
 *   @0x270a78 movw r2, #0x180e
 *   @0x270a7c cmp r3, r2
 *   @0x270a80 beq 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x270a84 bhi 0x274520 <pcre_dfa_exec+0x5fb8>
 *   @0x270a88 cmp r3, #32
 *   @0x270a8c beq 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x270a90 bhi 0x275278 <pcre_dfa_exec+0x6d10>
 *   @0x270a94 cmp r3, #9
 *   @0x270a98 bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270a9c mov r0, #0
 *   @0x270aa0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270aa4 ldr r9, [r6, #0x78]
 *   @0x270aa8 cmp r10, r9
 *   @0x270aac bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270ab0 ldr r12, [sp, #0x24]
 *   @0x270ab4 add r3, r10, #1
 *   @0x270ab8 cmp r12, #0
 *   @0x270abc beq 0x270b00 <pcre_dfa_exec+0x2598>
 *   @0x270ac0 cmp r9, r3
 *   @0x270ac4 bls 0x270b00 <pcre_dfa_exec+0x2598>
 *   @0x270ac8 ldrb r2, [r10, #0x1]
 *   @0x270acc and r2, r2, #192
 *   @0x270ad0 cmp r2, #128
 *   @0x270ad4 bne 0x270b00 <pcre_dfa_exec+0x2598>
 *   @0x270ad8 add r10, r10, #2
 *   @0x270adc b 0x270af0 <pcre_dfa_exec+0x2588>
 *   @0x270ae0 ldrb r2, [r3]
 *   @0x270ae4 and r2, r2, #192
 *   @0x270ae8 cmp r2, #128
 *   @0x270aec bne 0x270b00 <pcre_dfa_exec+0x2598>
 *   @0x270af0 cmp r10, r9
 *   @0x270af4 mov r3, r10
 *   @0x270af8 add r10, r10, #1
 *   @0x270afc bne 0x270ae0 <pcre_dfa_exec+0x2578>
 *   @0x270b00 mov r10, r3
 *   @0x270b04 b 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270b08 ldr r1, [r6, #0x18]
 *   @0x270b0c cmp r1, #0
 *   @0x270b10 beq 0x274540 <pcre_dfa_exec+0x5fd8>
 *   @0x270b14 ldr r2, [r6, #0x78]
 *   @0x270b18 cmp r10, r2
 *   @0x270b1c movhs r0, #0
 *   @0x270b20 blo 0x275c30 <pcre_dfa_exec+0x76c8>
 *   @0x270b24 mov r1, r0
 *   @0x270b28 cmp r1, #0
 *   @0x270b2c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270b30 ldr r2, [r6, #0x88]
 *   @0x270b34 ldr r9, [r6, #0x78]
 *   @0x270b38 cmp r2, #0
 *   @0x270b3c beq 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b40 add r3, r10, #1
 *   @0x270b44 cmp r9, r3
 *   @0x270b48 bhi 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b4c ldr r3, [r6, #0x18]
 *   @0x270b50 cmp r3, #0
 *   @0x270b54 bne 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b58 ldr r3, [r6, #0x1c]
 *   @0x270b5c cmp r3, #2
 *   @0x270b60 bne 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b64 ldrb r1, [r10]
 *   @0x270b68 ldrb r3, [r6, #0x34]
 *   @0x270b6c cmp r1, r3
 *   @0x270b70 bne 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b74 cmp r2, #1
 *   @0x270b78 mov r7, #1
 *   @0x270b7c str r7, [r6, #0x64]
 *   @0x270b80 ble 0x270aa8 <pcre_dfa_exec+0x2540>
 *   @0x270b84 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x270b88 ldr r9, [r6, #0x78]
 *   @0x270b8c cmp r10, r9
 *   @0x270b90 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270b94 ldrb r5, [r11, #0x1]
 *   @0x270b98 add r10, r10, #1
 *   @0x270b9c add r11, r11, #1
 *   @0x270ba0 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x270ba4 ldr r9, [r6, #0x78]
 *   @0x270ba8 cmp r10, r9
 *   @0x270bac bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270bb0 ldrb r3, [r10]
 *   @0x270bb4 ldr r2, [sp, #0x24]
 *   @0x270bb8 cmp r3, #191
 *   @0x270bbc movls r2, #0
 *   @0x270bc0 andhi r2, r2, #1
 *   @0x270bc4 cmp r2, #0
 *   @0x270bc8 addeq r10, r10, #1
 *   @0x270bcc beq 0x270bf4 <pcre_dfa_exec+0x268c>
 *   @0x270bd0 tst r3, #32
 *   @0x270bd4 bne 0x2754d4 <pcre_dfa_exec+0x6f6c>
 *   @0x270bd8 ldrb r2, [r10, #0x1]
 *   @0x270bdc and r3, r3, #31
 *   @0x270be0 add r10, r10, #2
 *   @0x270be4 and r2, r2, #63
 *   @0x270be8 orr r3, r2, r3, lsl #6
 *   @0x270bec cmp r3, #255
 *   @0x270bf0 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270bf4 ldr r2, [r6, #0x40]
 *   @0x270bf8 ldrb r3, [r2, r3]
 *   @0x270bfc tst r3, #1
 *   @0x270c00 bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270c04 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270c08 ldr r9, [r6, #0x78]
 *   @0x270c0c cmp r10, r9
 *   @0x270c10 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270c14 ldrb r3, [r10]
 *   @0x270c18 ldr r2, [sp, #0x24]
 *   @0x270c1c cmp r3, #191
 *   @0x270c20 movls r2, #0
 *   @0x270c24 andhi r2, r2, #1
 *   @0x270c28 cmp r2, #0
 *   @0x270c2c addeq r10, r10, #1
 *   @0x270c30 beq 0x270c58 <pcre_dfa_exec+0x26f0>
 *   @0x270c34 tst r3, #32
 *   @0x270c38 bne 0x275504 <pcre_dfa_exec+0x6f9c>
 *   @0x270c3c ldrb r2, [r10, #0x1]
 *   @0x270c40 and r3, r3, #31
 *   @0x270c44 add r10, r10, #2
 *   @0x270c48 and r2, r2, #63
 *   @0x270c4c orr r3, r2, r3, lsl #6
 *   @0x270c50 cmp r3, #255
 *   @0x270c54 bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270c58 ldr r2, [r6, #0x40]
 *   @0x270c5c ldrb r3, [r2, r3]
 *   @0x270c60 tst r3, #16
 *   @0x270c64 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270c68 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270c6c ldr r9, [r6, #0x78]
 *   @0x270c70 cmp r10, r9
 *   @0x270c74 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270c78 ldrb r3, [r10]
 *   @0x270c7c ldr r2, [sp, #0x24]
 *   @0x270c80 cmp r3, #191
 *   @0x270c84 movls r2, #0
 *   @0x270c88 andhi r2, r2, #1
 *   @0x270c8c cmp r2, #0
 *   @0x270c90 addeq r10, r10, #1
 *   @0x270c94 beq 0x270cbc <pcre_dfa_exec+0x2754>
 *   @0x270c98 tst r3, #32
 *   @0x270c9c bne 0x275534 <pcre_dfa_exec+0x6fcc>
 *   @0x270ca0 ldrb r2, [r10, #0x1]
 *   @0x270ca4 and r3, r3, #31
 *   @0x270ca8 add r10, r10, #2
 *   @0x270cac and r2, r2, #63
 *   @0x270cb0 orr r3, r2, r3, lsl #6
 *   @0x270cb4 cmp r3, #255
 *   @0x270cb8 bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270cbc ldr r2, [r6, #0x40]
 *   @0x270cc0 ldrb r3, [r2, r3]
 *   @0x270cc4 tst r3, #1
 *   @0x270cc8 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270ccc b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270cd0 ldr r9, [r6, #0x78]
 *   @0x270cd4 cmp r10, r9
 *   @0x270cd8 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270cdc ldrb r3, [r10]
 *   @0x270ce0 ldr r2, [sp, #0x24]
 *   @0x270ce4 cmp r3, #191
 *   @0x270ce8 movls r2, #0
 *   @0x270cec andhi r2, r2, #1
 *   @0x270cf0 cmp r2, #0
 *   @0x270cf4 addeq r10, r10, #1
 *   @0x270cf8 beq 0x270d20 <pcre_dfa_exec+0x27b8>
 *   @0x270cfc tst r3, #32
 *   @0x270d00 bne 0x275444 <pcre_dfa_exec+0x6edc>
 *   @0x270d04 ldrb r2, [r10, #0x1]
 *   @0x270d08 and r3, r3, #31
 *   @0x270d0c add r10, r10, #2
 *   @0x270d10 and r2, r2, #63
 *   @0x270d14 orr r3, r2, r3, lsl #6
 *   @0x270d18 cmp r3, #255
 *   @0x270d1c bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270d20 ldr r2, [r6, #0x40]
 *   @0x270d24 ldrb r3, [r2, r3]
 *   @0x270d28 tst r3, #4
 *   @0x270d2c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x270d30 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270d34 ldr r7, [sp, #0x34]
 *   @0x270d38 sub r5, r5, #85
 *   @0x270d3c add r3, r11, #1
 *   @0x270d40 add r2, r7, r5
 *   @0x270d44 and r5, r5, #1
 *   @0x270d48 str r5, [sp, #0x2c]
 *   @0x270d4c ldrb r7, [r2, #-0xc18]
 *   @0x270d50 ldrb r8, [r2, #-0xc24]
 *   @0x270d54 cmp r7, #0
 *   @0x270d58 mvneq r7, #-2147483648
 *   @0x270d5c cmp r8, #0
 *   @0x270d60 add r11, r3, #1
 *   @0x270d64 ldrb r5, [r3]
 *   @0x270d68 beq 0x2791e0 <pcre_dfa_exec+0xac78>
 *   @0x270d6c mov r12, #0
 *   @0x270d70 str r12, [sp, #0x30]
 *   @0x270d74 ldr r12, [sp, #0x24]
 *   @0x270d78 sub r3, r5, #6
 *   @0x270d7c cmp r12, #0
 *   @0x270d80 beq 0x272d68 <pcre_dfa_exec+0x4800>
 *   @0x270d84 cmp r3, #15
 *   @0x270d88 addls pc, pc, r3, lsl #2
 *   @0x270d8c b 0x272a74 <pcre_dfa_exec+0x450c>
 *   @0x270d90 b 0x272034 <pcre_dfa_exec+0x3acc>
 *   @0x270d94 b 0x2720c8 <pcre_dfa_exec+0x3b60>
 *   @0x270d98 b 0x271fb4 <pcre_dfa_exec+0x3a4c>
 *   @0x270d9c b 0x271f50 <pcre_dfa_exec+0x39e8>
 *   @0x270da0 b 0x271df4 <pcre_dfa_exec+0x388c>
 *   @0x270da4 b 0x271d80 <pcre_dfa_exec+0x3818>
 *   @0x270da8 b 0x271cb0 <pcre_dfa_exec+0x3748>
 *   @0x270dac b 0x271e8c <pcre_dfa_exec+0x3924>
 *   @0x270db0 b 0x271e74 <pcre_dfa_exec+0x390c>
 *   @0x270db4 b 0x272a74 <pcre_dfa_exec+0x450c>
 *   @0x270db8 b 0x272a74 <pcre_dfa_exec+0x450c>
 *   @0x270dbc b 0x271ef0 <pcre_dfa_exec+0x3988>
 *   @0x270dc0 b 0x271a80 <pcre_dfa_exec+0x3518>
 *   @0x270dc4 b 0x271b90 <pcre_dfa_exec+0x3628>
 *   @0x270dc8 b 0x271b14 <pcre_dfa_exec+0x35ac>
 *   @0x270dcc b 0x271c34 <pcre_dfa_exec+0x36cc>
 *   @0x270dd0 ldrb r1, [r11, #0x1]
 *   @0x270dd4 add r3, r11, #3
 *   @0x270dd8 ldrb r2, [r11, #0x2]
 *   @0x270ddc mov r8, #0
 *   @0x270de0 mov r12, #1
 *   @0x270de4 str r8, [sp, #0x30]
 *   @0x270de8 orr r1, r2, r1, lsl #8
 *   @0x270dec str r12, [sp, #0x2c]
 *   @0x270df0 ldrb r7, [r3]
 *   @0x270df4 ldr r2, [sp, #0x24]
 *   @0x270df8 cmp r7, #191
 *   @0x270dfc movls r2, #0
 *   @0x270e00 andhi r2, r2, #1
 *   @0x270e04 cmp r2, #0
 *   @0x270e08 addeq r11, r3, #1
 *   @0x270e0c beq 0x270e2c <pcre_dfa_exec+0x28c4>
 *   @0x270e10 tst r7, #32
 *   @0x270e14 bne 0x2734d0 <pcre_dfa_exec+0x4f68>
 *   @0x270e18 ldrb r2, [r3, #0x1]
 *   @0x270e1c and r7, r7, #31
 *   @0x270e20 add r11, r3, #2
 *   @0x270e24 and r3, r2, #63
 *   @0x270e28 orr r7, r3, r7, lsl #6
 *   @0x270e2c cmp r5, #71
 *   @0x270e30 bls 0x272c24 <pcre_dfa_exec+0x46bc>
 *   @0x270e34 ldr r3, [sp, #0x24]
 *   @0x270e38 cmp r7, #127
 *   @0x270e3c movls r3, #0
 *   @0x270e40 andhi r3, r3, #1
 *   @0x270e44 cmp r3, #0
 *   @0x270e48 bne 0x273330 <pcre_dfa_exec+0x4dc8>
 *   @0x270e4c ldr r5, [sp, #0x24]
 *   @0x270e50 ldr r3, [r6, #0x3c]
 *   @0x270e54 cmp r5, #0
 *   @0x270e58 ldrb r5, [r3, r7]
 *   @0x270e5c bne 0x273334 <pcre_dfa_exec+0x4dcc>
 *   @0x270e60 cmp r8, #0
 *   @0x270e64 beq 0x270ec4 <pcre_dfa_exec+0x295c>
 *   @0x270e68 ldr r9, [r6, #0x78]
 *   @0x270e6c cmp r10, r9
 *   @0x270e70 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270e74 ldrb r3, [r10]
 *   @0x270e78 cmp r3, r7
 *   @0x270e7c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270e80 cmp r5, r3
 *   @0x270e84 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270e88 add r3, r10, #1
 *   @0x270e8c mov r2, #1
 *   @0x270e90 b 0x270eb4 <pcre_dfa_exec+0x294c>
 *   @0x270e94 cmp r3, r9
 *   @0x270e98 add r3, r3, #1
 *   @0x270e9c beq 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x270ea0 ldrb r0, [r10]
 *   @0x270ea4 cmp r0, r7
 *   @0x270ea8 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270eac cmp r5, r0
 *   @0x270eb0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x270eb4 add r2, r2, #1
 *   @0x270eb8 mov r10, r3
 *   @0x270ebc cmp r8, r2
 *   @0x270ec0 bge 0x270e94 <pcre_dfa_exec+0x292c>
 *   @0x270ec4 cmp r8, r1
 *   @0x270ec8 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x270ecc ldr r12, [sp, #0x30]
 *   @0x270ed0 cmp r12, #0
 *   @0x270ed4 bne 0x278290 <pcre_dfa_exec+0x9d28>
 *   @0x270ed8 ldr r12, [sp, #0x24]
 *   @0x270edc cmp r12, #0
 *   @0x270ee0 bne 0x274b20 <pcre_dfa_exec+0x65b8>
 *   @0x270ee4 cmp r1, r8
 *   @0x270ee8 ble 0x277fc4 <pcre_dfa_exec+0x9a5c>
 *   @0x270eec ldr r9, [r6, #0x78]
 *   @0x270ef0 cmp r10, r9
 *   @0x270ef4 bhs 0x2765d4 <pcre_dfa_exec+0x806c>
 *   @0x270ef8 ldrb r3, [r10]
 *   @0x270efc cmp r3, r7
 *   @0x270f00 beq 0x277fc4 <pcre_dfa_exec+0x9a5c>
 *   @0x270f04 cmp r5, r3
 *   @0x270f08 beq 0x277fc4 <pcre_dfa_exec+0x9a5c>
 *   @0x270f0c rsb r1, r8, r1
 *   @0x270f10 add r3, r10, #1
 *   @0x270f14 add r1, r10, r1
 *   @0x270f18 b 0x270f3c <pcre_dfa_exec+0x29d4>
 *   @0x270f1c cmp r3, r9
 *   @0x270f20 add r3, r3, #1
 *   @0x270f24 beq 0x2765d8 <pcre_dfa_exec+0x8070>
 *   @0x270f28 ldrb r2, [r4]
 *   @0x270f2c cmp r2, r7
 *   @0x270f30 beq 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x270f34 cmp r5, r2
 *   @0x270f38 beq 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x270f3c cmp r3, r1
 *   @0x270f40 mov r4, r3
 *   @0x270f44 bne 0x270f1c <pcre_dfa_exec+0x29b4>
 *   @0x270f48 ldr r3, [sp, #0x2c]
 *   @0x270f4c cmp r3, #0
 *   @0x270f50 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x270f54 cmp r10, r4
 *   @0x270f58 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x270f5c ldr r5, [sp, #0x1c]
 *   @0x270f60 ldr r7, [sp, #0x18]
 *   @0x270f64 ldr r8, [sp, #0x164]
 *   @0x270f68 b 0x270f74 <pcre_dfa_exec+0x2a0c>
 *   @0x270f6c cmp r10, r4
 *   @0x270f70 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x270f74 ldr r12, [sp, #0x168]
 *   @0x270f78 mov r0, r4
 *   @0x270f7c str r6, [sp]
 *   @0x270f80 mov r1, r11
 *   @0x270f84 add r12, r12, #1
 *   @0x270f88 str r8, [sp, #0x4]
 *   @0x270f8c mov r2, r5
 *   @0x270f90 str r12, [sp, #0x8]
 *   @0x270f94 mov r3, r7
 *   @0x270f98 sub r4, r4, #1
 *   @0x270f9c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x270fa0 cmp r0, #0
 *   @0x270fa4 beq 0x270f6c <pcre_dfa_exec+0x2a04>
 *   @0x270fa8 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x270fac mov r1, #1
 *   @0x270fb0 mov r8, #0
 *   @0x270fb4 add r3, r11, r1
 *   @0x270fb8 str r8, [sp, #0x30]
 *   @0x270fbc str r1, [sp, #0x2c]
 *   @0x270fc0 b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x270fc4 mov r8, #1
 *   @0x270fc8 mov r7, #0
 *   @0x270fcc add r3, r11, r8
 *   @0x270fd0 str r8, [sp, #0x2c]
 *   @0x270fd4 mvn r1, #-2147483648
 *   @0x270fd8 str r7, [sp, #0x30]
 *   @0x270fdc b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x270fe0 mov r8, #0
 *   @0x270fe4 mov r2, #1
 *   @0x270fe8 add r3, r11, #1
 *   @0x270fec str r8, [sp, #0x30]
 *   @0x270ff0 mvn r1, #-2147483648
 *   @0x270ff4 str r2, [sp, #0x2c]
 *   @0x270ff8 b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x270ffc ldrb r1, [r11, #0x1]
 *   @0x271000 mov r12, #0
 *   @0x271004 ldrb r2, [r11, #0x2]
 *   @0x271008 add r3, r11, #3
 *   @0x27100c str r12, [sp, #0x2c]
 *   @0x271010 orr r1, r2, r1, lsl #8
 *   @0x271014 str r12, [sp, #0x30]
 *   @0x271018 mov r8, r1
 *   @0x27101c b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x271020 ldrb r1, [r11, #0x1]
 *   @0x271024 cmp r5, #66
 *   @0x271028 cmpne r5, #79
 *   @0x27102c ldrb r2, [r11, #0x2]
 *   @0x271030 mov r8, #0
 *   @0x271034 movne r0, #0
 *   @0x271038 moveq r0, #1
 *   @0x27103c add r3, r11, #3
 *   @0x271040 str r8, [sp, #0x2c]
 *   @0x271044 orr r1, r2, r1, lsl #8
 *   @0x271048 str r0, [sp, #0x30]
 *   @0x27104c b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x271050 cmp r5, #71
 *   @0x271054 ldr r7, [sp, #0x38]
 *   @0x271058 add r3, r11, #1
 *   @0x27105c movls r2, #59
 *   @0x271060 movhi r2, #72
 *   @0x271064 rsb r11, r2, r5
 *   @0x271068 add r2, r7, r11
 *   @0x27106c and r11, r11, #1
 *   @0x271070 str r11, [sp, #0x30]
 *   @0x271074 ldrb r1, [r2, #-0xc18]
 *   @0x271078 ldrb r8, [r2, #-0xc24]
 *   @0x27107c cmp r1, #0
 *   @0x271080 movne r12, #0
 *   @0x271084 moveq r0, #0
 *   @0x271088 strne r12, [sp, #0x2c]
 *   @0x27108c mvneq r1, #-2147483648
 *   @0x271090 streq r0, [sp, #0x2c]
 *   @0x271094 b 0x270df0 <pcre_dfa_exec+0x2888>
 *   @0x271098 mov r8, #1
 *   @0x27109c ldrb r5, [r11, #0x1]
 *   @0x2710a0 mov r12, #0
 *   @0x2710a4 str r8, [sp, #0x30]
 *   @0x2710a8 add r11, r11, #2
 *   @0x2710ac mvn r7, #-2147483648
 *   @0x2710b0 str r12, [sp, #0x2c]
 *   @0x2710b4 b 0x270d74 <pcre_dfa_exec+0x280c>
 *   @0x2710b8 add r3, r11, #1
 *   @0x2710bc mvn r7, #-2147483648
 *   @0x2710c0 mov r12, #1
 *   @0x2710c4 mov r5, #0
 *   @0x2710c8 str r12, [sp, #0x30]
 *   @0x2710cc str r5, [sp, #0x2c]
 *   @0x2710d0 ldrb r5, [r3]
 *   @0x2710d4 add r11, r3, #1
 *   @0x2710d8 mov r8, #0
 *   @0x2710dc cmp r8, r7
 *   @0x2710e0 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x2710e4 ldr r12, [sp, #0x2c]
 *   @0x2710e8 cmp r12, #0
 *   @0x2710ec bne 0x277018 <pcre_dfa_exec+0x8ab0>
 *   @0x2710f0 ldr r12, [sp, #0x24]
 *   @0x2710f4 sub r3, r5, #6
 *   @0x2710f8 cmp r12, #0
 *   @0x2710fc beq 0x273570 <pcre_dfa_exec+0x5008>
 *   @0x271100 cmp r3, #15
 *   @0x271104 addls pc, pc, r3, lsl #2
 *   @0x271108 b 0x272a7c <pcre_dfa_exec+0x4514>
 *   @0x27110c b 0x272900 <pcre_dfa_exec+0x4398>
 *   @0x271110 b 0x272778 <pcre_dfa_exec+0x4210>
 *   @0x271114 b 0x27297c <pcre_dfa_exec+0x4414>
 *   @0x271118 b 0x2726fc <pcre_dfa_exec+0x4194>
 *   @0x27111c b 0x2729f8 <pcre_dfa_exec+0x4490>
 *   @0x271120 b 0x272680 <pcre_dfa_exec+0x4118>
 *   @0x271124 b 0x2725a8 <pcre_dfa_exec+0x4040>
 *   @0x271128 b 0x272454 <pcre_dfa_exec+0x3eec>
 *   @0x27112c b 0x2728c0 <pcre_dfa_exec+0x4358>
 *   @0x271130 b 0x272a7c <pcre_dfa_exec+0x4514>
 *   @0x271134 b 0x272a7c <pcre_dfa_exec+0x4514>
 *   @0x271138 b 0x2727f4 <pcre_dfa_exec+0x428c>
 *   @0x27113c b 0x272374 <pcre_dfa_exec+0x3e0c>
 *   @0x271140 b 0x272374 <pcre_dfa_exec+0x3e0c>
 *   @0x271144 b 0x2722cc <pcre_dfa_exec+0x3d64>
 *   @0x271148 b 0x2722cc <pcre_dfa_exec+0x3d64>
 *   @0x27114c ldrb r1, [r11, #0x1]
 *   @0x271150 mov r5, #1
 *   @0x271154 ldrb r2, [r11, #0x2]
 *   @0x271158 add r3, r11, #3
 *   @0x27115c str r5, [sp, #0x2c]
 *   @0x271160 orr r7, r2, r1, lsl #8
 *   @0x271164 mov r8, r7
 *   @0x271168 b 0x270d5c <pcre_dfa_exec+0x27f4>
 *   @0x27116c ldrb r1, [r11, #0x1]
 *   @0x271170 subs r4, r5, #92
 *   @0x271174 ldrb r2, [r11, #0x2]
 *   @0x271178 rsbs r5, r4, #0
 *   @0x27117c mov r7, #0
 *   @0x271180 adcs r5, r5, r4
 *   @0x271184 str r7, [sp, #0x30]
 *   @0x271188 add r3, r11, #3
 *   @0x27118c str r5, [sp, #0x2c]
 *   @0x271190 orr r7, r2, r1, lsl #8
 *   @0x271194 b 0x2710d0 <pcre_dfa_exec+0x2b68>
 *   @0x271198 ldrb r1, [r11, #0x1]
 *   @0x27119c mov r7, #1
 *   @0x2711a0 ldrb r2, [r11, #0x2]
 *   @0x2711a4 mov r12, #0
 *   @0x2711a8 str r7, [sp, #0x30]
 *   @0x2711ac add r3, r11, #3
 *   @0x2711b0 str r12, [sp, #0x2c]
 *   @0x2711b4 orr r7, r2, r1, lsl #8
 *   @0x2711b8 b 0x2710d0 <pcre_dfa_exec+0x2b68>
 *   @0x2711bc mov r7, #1
 *   @0x2711c0 mov r5, #0
 *   @0x2711c4 add r3, r11, r7
 *   @0x2711c8 str r7, [sp, #0x30]
 *   @0x2711cc str r5, [sp, #0x2c]
 *   @0x2711d0 b 0x2710d0 <pcre_dfa_exec+0x2b68>
 *   @0x2711d4 ldrb r1, [r11, #0x21]
 *   @0x2711d8 add r8, r11, #1
 *   @0x2711dc add r0, r11, #33
 *   @0x2711e0 sub r2, r1, #98
 *   @0x2711e4 uxtb r3, r2
 *   @0x2711e8 cmp r3, #11
 *   @0x2711ec bhi 0x278fe4 <pcre_dfa_exec+0xaa7c>
 *   @0x2711f0 mov r7, #1
 *   @0x2711f4 lsl r3, r7, r3
 *   @0x2711f8 ands r12, r3, #2240
 *   @0x2711fc bne 0x274784 <pcre_dfa_exec+0x621c>
 *   @0x271200 movw r1, #0x73f
 *   @0x271204 and r1, r3, r1
 *   @0x271208 cmp r1, #0
 *   @0x27120c beq 0x278fe4 <pcre_dfa_exec+0xaa7c>
 *   @0x271210 cmp r2, #7
 *   @0x271214 strls r12, [sp, #0x30]
 *   @0x271218 andls r12, r2, r7
 *   @0x27121c ldr r7, [sp, #0x48]
 *   @0x271220 movhi r0, #1
 *   @0x271224 strhi r0, [sp, #0x30]
 *   @0x271228 add r2, r7, r2
 *   @0x27122c strls r12, [sp, #0x2c]
 *   @0x271230 strhi r12, [sp, #0x2c]
 *   @0x271234 add r11, r11, #34
 *   @0x271238 ldrb r0, [r2, #-0xc18]
 *   @0x27123c ldrb r12, [r2, #-0xc24]
 *   @0x271240 cmp r0, #0
 *   @0x271244 mvneq r0, #-2147483648
 *   @0x271248 ldr r7, [sp, #0x24]
 *   @0x27124c cmp r7, #0
 *   @0x271250 bne 0x274390 <pcre_dfa_exec+0x5e28>
 *   @0x271254 cmp r12, #0
 *   @0x271258 beq 0x2712c4 <pcre_dfa_exec+0x2d5c>
 *   @0x27125c ldr r9, [r6, #0x78]
 *   @0x271260 cmp r10, r9
 *   @0x271264 bhs 0x2740e4 <pcre_dfa_exec+0x5b7c>
 *   @0x271268 ldrb r3, [r10]
 *   @0x27126c add r2, r10, #1
 *   @0x271270 and r1, r3, #7
 *   @0x271274 ldrb r3, [r8, r3, lsr #3]
 *   @0x271278 asr r3, r3, r1
 *   @0x27127c tst r3, #1
 *   @0x271280 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271284 mov r3, #1
 *   @0x271288 b 0x2712ac <pcre_dfa_exec+0x2d44>
 *   @0x27128c cmp r2, r9
 *   @0x271290 beq 0x2740e8 <pcre_dfa_exec+0x5b80>
 *   @0x271294 ldrb r1, [r2], #1
 *   @0x271298 and r4, r1, #7
 *   @0x27129c ldrb r1, [r8, r1, lsr #3]
 *   @0x2712a0 asr r1, r1, r4
 *   @0x2712a4 tst r1, #1
 *   @0x2712a8 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2712ac add r3, r3, #1
 *   @0x2712b0 cmp r12, r3
 *   @0x2712b4 bge 0x27128c <pcre_dfa_exec+0x2d24>
 *   @0x2712b8 mov r10, r2
 *   @0x2712bc cmp r12, r0
 *   @0x2712c0 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x2712c4 ldr r2, [sp, #0x2c]
 *   @0x2712c8 cmp r2, #0
 *   @0x2712cc bne 0x27875c <pcre_dfa_exec+0xa1f4>
 *   @0x2712d0 ldr r7, [sp, #0x24]
 *   @0x2712d4 cmp r7, #0
 *   @0x2712d8 bne 0x2761c8 <pcre_dfa_exec+0x7c60>
 *   @0x2712dc cmp r0, r12
 *   @0x2712e0 ble 0x279388 <pcre_dfa_exec+0xae20>
 *   @0x2712e4 ldr r9, [r6, #0x78]
 *   @0x2712e8 cmp r10, r9
 *   @0x2712ec bhs 0x277634 <pcre_dfa_exec+0x90cc>
 *   @0x2712f0 ldrb r3, [r10]
 *   @0x2712f4 and r2, r3, #7
 *   @0x2712f8 ldrb r3, [r8, r3, lsr #3]
 *   @0x2712fc asr r3, r3, r2
 *   @0x271300 tst r3, #1
 *   @0x271304 beq 0x279388 <pcre_dfa_exec+0xae20>
 *   @0x271308 rsb r0, r12, r0
 *   @0x27130c add r3, r10, #1
 *   @0x271310 add r0, r10, r0
 *   @0x271314 b 0x271338 <pcre_dfa_exec+0x2dd0>
 *   @0x271318 cmp r3, r9
 *   @0x27131c beq 0x277638 <pcre_dfa_exec+0x90d0>
 *   @0x271320 ldrb r2, [r3], #1
 *   @0x271324 and r1, r2, #7
 *   @0x271328 ldrb r2, [r8, r2, lsr #3]
 *   @0x27132c asr r2, r2, r1
 *   @0x271330 tst r2, #1
 *   @0x271334 beq 0x271344 <pcre_dfa_exec+0x2ddc>
 *   @0x271338 cmp r3, r0
 *   @0x27133c mov r5, r3
 *   @0x271340 bne 0x271318 <pcre_dfa_exec+0x2db0>
 *   @0x271344 ldr r12, [sp, #0x30]
 *   @0x271348 cmp r12, #0
 *   @0x27134c bne 0x274cc4 <pcre_dfa_exec+0x675c>
 *   @0x271350 mov r4, r11
 *   @0x271354 ldr r11, [sp, #0x18]
 *   @0x271358 b 0x271394 <pcre_dfa_exec+0x2e2c>
 *   @0x27135c ldr r7, [sp, #0x164]
 *   @0x271360 mov r0, r5
 *   @0x271364 ldr r3, [sp, #0x168]
 *   @0x271368 mov r1, r4
 *   @0x27136c str r6, [sp]
 *   @0x271370 sub r5, r5, #1
 *   @0x271374 add r3, r3, #1
 *   @0x271378 str r7, [sp, #0x4]
 *   @0x27137c str r3, [sp, #0x8]
 *   @0x271380 mov r3, r11
 *   @0x271384 ldr r2, [sp, #0x1c]
 *   @0x271388 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x27138c cmp r0, #0
 *   @0x271390 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271394 cmp r5, r10
 *   @0x271398 bhs 0x27135c <pcre_dfa_exec+0x2df4>
 *   @0x27139c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2713a0 ldr r5, [sp, #0x164]
 *   @0x2713a4 add r4, r11, #1
 *   @0x2713a8 ldr r3, [sp, #0x168]
 *   @0x2713ac mov r0, r10
 *   @0x2713b0 str r6, [sp]
 *   @0x2713b4 mov r1, r4
 *   @0x2713b8 add r3, r3, #1
 *   @0x2713bc str r5, [sp, #0x4]
 *   @0x2713c0 str r3, [sp, #0x8]
 *   @0x2713c4 ldr r2, [sp, #0x1c]
 *   @0x2713c8 ldr r3, [sp, #0x18]
 *   @0x2713cc bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2713d0 cmp r0, #0
 *   @0x2713d4 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2713d8 ldrb r2, [r4, #0x1]
 *   @0x2713dc ldrb r3, [r4, #0x2]
 *   @0x2713e0 orr r3, r3, r2, lsl #8
 *   @0x2713e4 ldrb r3, [r4, r3]!
 *   @0x2713e8 cmp r3, #119
 *   @0x2713ec beq 0x2713d8 <pcre_dfa_exec+0x2e70>
 *   @0x2713f0 add r11, r4, #3
 *   @0x2713f4 ldrb r5, [r4, #0x3]
 *   @0x2713f8 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2713fc mov r4, r11
 *   @0x271400 ldr r7, [sp, #0x164]
 *   @0x271404 ldr r11, [sp, #0x18]
 *   @0x271408 mov r0, r10
 *   @0x27140c ldr r12, [sp, #0x168]
 *   @0x271410 add r1, r4, #1
 *   @0x271414 str r6, [sp]
 *   @0x271418 add r12, r12, #1
 *   @0x27141c str r7, [sp, #0x4]
 *   @0x271420 ldr r2, [sp, #0x1c]
 *   @0x271424 mov r3, r11
 *   @0x271428 str r12, [sp, #0x8]
 *   @0x27142c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x271430 cmp r0, #0
 *   @0x271434 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271438 movw r0, #0xfc1d
 *   @0x27143c movt r0, #0xffff
 *   @0x271440 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271444 ldrb r9, [r11, #0x1]
 *   @0x271448 add r3, r11, #1
 *   @0x27144c cmp r9, #134
 *   @0x271450 cmpne r9, #139
 *   @0x271454 mov r11, r3
 *   @0x271458 movne r12, #1
 *   @0x27145c strne r12, [sp, #0x4c]
 *   @0x271460 bne 0x26f7b0 <pcre_dfa_exec+0x1248>
 *   @0x271464 mov r7, #1
 *   @0x271468 str r7, [sp, #0x4c]
 *   @0x27146c b 0x26f95c <pcre_dfa_exec+0x13f4>
 *   @0x271470 ldr r3, [pc, #0xfd4]
 *   @0x271474 ldr r7, [sp, #0x20]
 *   @0x271478 ldr r3, [r7, r3]
 *   @0x27147c ldr r2, [r3]
 *   @0x271480 cmp r2, #0
 *   @0x271484 beq 0x27152c <pcre_dfa_exec+0x2fc4>
 *   @0x271488 ldr r3, [r6, #0x74]
 *   @0x27148c mov r1, #2
 *   @0x271490 ldr r7, [sp, #0x1c]
 *   @0x271494 str r1, [sp, #0x8c]
 *   @0x271498 ldrb r0, [r11, #0x1]
 *   @0x27149c rsb r1, r3, r7
 *   @0x2714a0 str r1, [sp, #0xa0]
 *   @0x2714a4 ldr r1, [r6, #0xc]
 *   @0x2714a8 str r0, [sp, #0x90]
 *   @0x2714ac ldr r0, [r6, #0x78]
 *   @0x2714b0 str r3, [sp, #0x98]
 *   @0x2714b4 str r1, [sp, #0x94]
 *   @0x2714b8 rsb r1, r3, r10
 *   @0x2714bc rsb r3, r3, r0
 *   @0x2714c0 str r1, [sp, #0xa4]
 *   @0x2714c4 str r3, [sp, #0x9c]
 *   @0x2714c8 ldrb r0, [r11, #0x2]
 *   @0x2714cc ldrb r1, [r11, #0x3]
 *   @0x2714d0 ldrh r3, [r6, #144]
 *   @0x2714d4 orr r1, r1, r0, lsl #8
 *   @0x2714d8 str r1, [sp, #0xb4]
 *   @0x2714dc ldrb r0, [r11, #0x4]
 *   @0x2714e0 cmp r3, #0
 *   @0x2714e4 ldrb r1, [r11, #0x5]
 *   @0x2714e8 ldr r5, [sp, #0x18]
 *   @0x2714ec mvneq r3, #0
 *   @0x2714f0 orr r1, r1, r0, lsl #8
 *   @0x2714f4 str r3, [sp, #0xac]
 *   @0x2714f8 str r1, [sp, #0xb8]
 *   @0x2714fc add r0, sp, #140
 *   @0x271500 ldr r1, [r6, #0xa8]
 *   @0x271504 add r12, r5, r5, lsr #31
 *   @0x271508 ldr r3, [r6, #0xb0]
 *   @0x27150c asr r12, r12, #1
 *   @0x271510 str r12, [sp, #0xa8]
 *   @0x271514 str r1, [sp, #0xb0]
 *   @0x271518 str r3, [sp, #0xbc]
 *   @0x27151c blx r2
 *   @0x271520 cmp r0, #0
 *   @0x271524 bgt 0x2786a4 <pcre_dfa_exec+0xa13c>
 *   @0x271528 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27152c ldrb r5, [r11, #0x6]
 *   @0x271530 add r11, r11, #6
 *   @0x271534 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x271538 ldr r12, [sp, #0x20]
 *   @0x27153c mov r4, r11
 *   @0x271540 ldr r3, [pc, #0xf08]
 *   @0x271544 add r5, r4, #2
 *   @0x271548 mov r2, #0
 *   @0x27154c str r5, [r6, #0xb0]
 *   @0x271550 str r2, [r6, #0xac]
 *   @0x271554 mov r0, r10
 *   @0x271558 ldr r7, [r12, r3]
 *   @0x27155c ldrb lr, [r4]
 *   @0x271560 ldrb r1, [r4, #0x1]
 *   @0x271564 ldr r11, [sp, #0x18]
 *   @0x271568 ldrb lr, [r7, lr]
 *   @0x27156c ldr r7, [sp, #0x164]
 *   @0x271570 ldr r12, [sp, #0x168]
 *   @0x271574 add r1, lr, r1
 *   @0x271578 mov r3, r11
 *   @0x27157c add r1, r4, r1
 *   @0x271580 add r12, r12, #1
 *   @0x271584 ldr r2, [sp, #0x1c]
 *   @0x271588 str r6, [sp]
 *   @0x27158c str r7, [sp, #0x4]
 *   @0x271590 str r12, [sp, #0x8]
 *   @0x271594 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x271598 movw r3, #0xfc19
 *   @0x27159c movt r3, #0xffff
 *   @0x2715a0 cmp r0, #1
 *   @0x2715a4 cmpne r0, r3
 *   @0x2715a8 mov r4, r0
 *   @0x2715ac bne 0x2715c4 <pcre_dfa_exec+0x305c>
 *   @0x2715b0 ldr r3, [r6, #0xac]
 *   @0x2715b4 cmp r3, #0
 *   @0x2715b8 streq r5, [r6, #0xac]
 *   @0x2715bc moveq r0, r0
 *   @0x2715c0 beq 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2715c4 mvn r3, #992
 *   @0x2715c8 cmp r4, r3
 *   @0x2715cc movne r0, r4
 *   @0x2715d0 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2715d4 mov r0, r5
 *   @0x2715d8 ldr r1, [r6, #0x7c]
 *   @0x2715dc bl 0xb6574 <strcmp@plt>
 *   @0x2715e0 cmp r0, #0
 *   @0x2715e4 movne r0, r4
 *   @0x2715e8 movweq r0, #0xfc1e
 *   @0x2715ec streq r10, [r6, #0x7c]
 *   @0x2715f0 movteq r0, #0xffff
 *   @0x2715f4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2715f8 ldrb r7, [r11, #0x1]
 *   @0x2715fc ldrb r3, [r11, #0x2]
 *   @0x271600 ldr r4, [r6, #0x70]
 *   @0x271604 orr r7, r3, r7, lsl #8
 *   @0x271608 ldr r12, [r6, #0xa4]
 *   @0x27160c add r9, r4, r7
 *   @0x271610 cmp r4, r9
 *   @0x271614 ldrbne r1, [r9, #0x3]
 *   @0x271618 moveq r1, #0
 *   @0x27161c ldrbne r3, [r9, #0x4]
 *   @0x271620 orrne r1, r3, r1, lsl #8
 *   @0x271624 cmp r12, #0
 *   @0x271628 beq 0x273f54 <pcre_dfa_exec+0x59ec>
 *   @0x27162c mov r3, r12
 *   @0x271630 b 0x271640 <pcre_dfa_exec+0x30d8>
 *   @0x271634 ldr r3, [r3]
 *   @0x271638 cmp r3, #0
 *   @0x27163c beq 0x273f54 <pcre_dfa_exec+0x59ec>
 *   @0x271640 ldr r2, [r3, #0x4]
 *   @0x271644 cmp r1, r2
 *   @0x271648 bne 0x271634 <pcre_dfa_exec+0x30cc>
 *   @0x27164c ldr r2, [r3, #0x14]
 *   @0x271650 cmp r2, r10
 *   @0x271654 bne 0x271634 <pcre_dfa_exec+0x30cc>
 *   @0x271658 mvn r0, #25
 *   @0x27165c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271660 ldrb r7, [r11, #0x3]
 *   @0x271664 subs r5, r5, #116
 *   @0x271668 ldrb r3, [r11, #0x4]
 *   @0x27166c rsbs r9, r5, #0
 *   @0x271670 ldrb r12, [r11, #0x1]
 *   @0x271674 adcs r9, r9, r5
 *   @0x271678 ldrb r1, [r11, #0x2]
 *   @0x27167c orr r7, r3, r7, lsl #8
 *   @0x271680 ldr r8, [r6, #0x50]
 *   @0x271684 sub r2, r7, #1
 *   @0x271688 ldr r0, [r6, #0x24]
 *   @0x27168c orr r1, r1, r12, lsl #8
 *   @0x271690 ldr r3, [r6, #0x30]
 *   @0x271694 cmp r8, #0
 *   @0x271698 movne r8, #0
 *   @0x27169c mvneq r8, #0
 *   @0x2716a0 cmp r7, #0
 *   @0x2716a4 add r11, r11, #5
 *   @0x2716a8 mla r3, r0, r1, r3
 *   @0x2716ac beq 0x2702ec <pcre_dfa_exec+0x1d84>
 *   @0x2716b0 ldr r4, [sp, #0x18]
 *   @0x2716b4 b 0x2716c0 <pcre_dfa_exec+0x3158>
 *   @0x2716b8 cmn r2, #1
 *   @0x2716bc beq 0x2702ec <pcre_dfa_exec+0x1d84>
 *   @0x2716c0 ldrb r7, [r3]
 *   @0x2716c4 sub r2, r2, #1
 *   @0x2716c8 ldrb r1, [r3, #0x1]
 *   @0x2716cc add r3, r3, r0
 *   @0x2716d0 orr r7, r1, r7, lsl #8
 *   @0x2716d4 lsl r7, r7, #1
 *   @0x2716d8 cmp r4, r7
 *   @0x2716dc ble 0x2716b8 <pcre_dfa_exec+0x3150>
 *   @0x2716e0 ldr r12, [r6, #0xc]
 *   @0x2716e4 ldr r1, [r12, r7, lsl #2]
 *   @0x2716e8 cmp r1, #0
 *   @0x2716ec blt 0x2716b8 <pcre_dfa_exec+0x3150>
 *   @0x2716f0 add r3, r7, #1
 *   @0x2716f4 ldr r8, [r12, r3, lsl #2]
 *   @0x2716f8 rsb r8, r1, r8
 *   @0x2716fc b 0x2702ec <pcre_dfa_exec+0x1d84>
 *   @0x271700 ldr r9, [r6, #0x78]
 *   @0x271704 cmp r10, r9
 *   @0x271708 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x27170c ldr r7, [sp, #0x24]
 *   @0x271710 cmp r7, #0
 *   @0x271714 beq 0x2745d0 <pcre_dfa_exec+0x6068>
 *   @0x271718 ldrb r3, [r11, #0x1]
 *   @0x27171c cmp r3, #191
 *   @0x271720 addls r11, r11, #2
 *   @0x271724 bls 0x271744 <pcre_dfa_exec+0x31dc>
 *   @0x271728 tst r3, #32
 *   @0x27172c bne 0x275f04 <pcre_dfa_exec+0x799c>
 *   @0x271730 ldrb r2, [r11, #0x2]
 *   @0x271734 and r3, r3, #31
 *   @0x271738 add r11, r11, #3
 *   @0x27173c and r2, r2, #63
 *   @0x271740 orr r3, r2, r3, lsl #6
 *   @0x271744 ldrb r2, [r10]
 *   @0x271748 cmp r2, #191
 *   @0x27174c addls r10, r10, #1
 *   @0x271750 bls 0x271770 <pcre_dfa_exec+0x3208>
 *   @0x271754 tst r2, #32
 *   @0x271758 bne 0x275ed4 <pcre_dfa_exec+0x796c>
 *   @0x27175c ldrb r1, [r10, #0x1]
 *   @0x271760 and r2, r2, #31
 *   @0x271764 add r10, r10, #2
 *   @0x271768 and r1, r1, #63
 *   @0x27176c orr r2, r1, r2, lsl #6
 *   @0x271770 cmp r5, #31
 *   @0x271774 beq 0x275db4 <pcre_dfa_exec+0x784c>
 *   @0x271778 cmp r3, #127
 *   @0x27177c ldrls r1, [r6, #0x3c]
 *   @0x271780 movhi r1, r3
 *   @0x271784 ldrbls r1, [r1, r3]
 *   @0x271788 cmp r3, r2
 *   @0x27178c cmpne r1, r2
 *   @0x271790 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271794 ldrb r5, [r11]
 *   @0x271798 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x27179c ldr r9, [r6, #0x78]
 *   @0x2717a0 cmp r10, r9
 *   @0x2717a4 bhs 0x274488 <pcre_dfa_exec+0x5f20>
 *   @0x2717a8 ldr r1, [r6, #0x18]
 *   @0x2717ac cmp r1, #0
 *   @0x2717b0 beq 0x27528c <pcre_dfa_exec+0x6d24>
 *   @0x2717b4 ldr r12, [sp, #0x28]
 *   @0x2717b8 mov r2, r9
 *   @0x2717bc mov r0, r10
 *   @0x2717c0 add r3, r6, #28
 *   @0x2717c4 str r12, [sp]
 *   @0x2717c8 bl 0x25f9fc <_pcre_is_newline>
 *   @0x2717cc rsbs r0, r0, #1
 *   @0x2717d0 movlo r0, #0
 *   @0x2717d4 cmp r0, #0
 *   @0x2717d8 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2717dc ldr r3, [r6, #0x88]
 *   @0x2717e0 cmp r3, #0
 *   @0x2717e4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2717e8 ldr r1, [r6, #0x78]
 *   @0x2717ec add r2, r10, #1
 *   @0x2717f0 cmp r1, r2
 *   @0x2717f4 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2717f8 ldr r2, [r6, #0x18]
 *   @0x2717fc cmp r2, #0
 *   @0x271800 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271804 ldr r2, [r6, #0x1c]
 *   @0x271808 cmp r2, #2
 *   @0x27180c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271810 ldrb r1, [r10]
 *   @0x271814 ldrb r2, [r6, #0x34]
 *   @0x271818 cmp r1, r2
 *   @0x27181c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271820 cmp r3, #1
 *   @0x271824 mov r3, #1
 *   @0x271828 str r3, [r6, #0x64]
 *   @0x27182c ble 0x270504 <pcre_dfa_exec+0x1f9c>
 *   @0x271830 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x271834 add r4, r11, #1
 *   @0x271838 mov r1, r4
 *   @0x27183c ldrb r2, [r1, #0x1]
 *   @0x271840 ldrb r3, [r1, #0x2]
 *   @0x271844 orr r3, r3, r2, lsl #8
 *   @0x271848 ldrb r3, [r1, r3]!
 *   @0x27184c cmp r3, #119
 *   @0x271850 beq 0x27183c <pcre_dfa_exec+0x32d4>
 *   @0x271854 ldr r7, [sp, #0x164]
 *   @0x271858 add r1, r1, #3
 *   @0x27185c ldr r3, [sp, #0x168]
 *   @0x271860 mov r0, r10
 *   @0x271864 str r6, [sp]
 *   @0x271868 add r3, r3, #1
 *   @0x27186c str r7, [sp, #0x4]
 *   @0x271870 str r3, [sp, #0x8]
 *   @0x271874 ldr r2, [sp, #0x1c]
 *   @0x271878 ldr r3, [sp, #0x18]
 *   @0x27187c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x271880 cmp r0, #0
 *   @0x271884 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271888 ldrb r5, [r11, #0x1]
 *   @0x27188c mov r11, r4
 *   @0x271890 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x271894 ldr r12, [sp, #0x20]
 *   @0x271898 mov r4, r11
 *   @0x27189c ldr r3, [pc, #0xbac]
 *   @0x2718a0 mov r2, #0
 *   @0x2718a4 add r5, r4, #2
 *   @0x2718a8 str r2, [r6, #0xac]
 *   @0x2718ac str r5, [r6, #0xb0]
 *   @0x2718b0 mov r0, r10
 *   @0x2718b4 ldr r7, [r12, r3]
 *   @0x2718b8 ldrb lr, [r4]
 *   @0x2718bc ldrb r1, [r4, #0x1]
 *   @0x2718c0 ldr r11, [sp, #0x18]
 *   @0x2718c4 ldrb lr, [r7, lr]
 *   @0x2718c8 ldr r7, [sp, #0x164]
 *   @0x2718cc ldr r12, [sp, #0x168]
 *   @0x2718d0 add r1, lr, r1
 *   @0x2718d4 mov r3, r11
 *   @0x2718d8 ldr r2, [sp, #0x1c]
 *   @0x2718dc add r12, r12, #1
 *   @0x2718e0 str r6, [sp]
 *   @0x2718e4 str r7, [sp, #0x4]
 *   @0x2718e8 add r1, r4, r1
 *   @0x2718ec str r12, [sp, #0x8]
 *   @0x2718f0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2718f4 movw r3, #0xfc19
 *   @0x2718f8 movt r3, #0xffff
 *   @0x2718fc cmp r0, #1
 *   @0x271900 cmpne r0, r3
 *   @0x271904 bne 0x271914 <pcre_dfa_exec+0x33ac>
 *   @0x271908 ldr r3, [r6, #0xac]
 *   @0x27190c cmp r3, #0
 *   @0x271910 streq r5, [r6, #0xac]
 *   @0x271914 cmp r0, #0
 *   @0x271918 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27191c b 0x271438 <pcre_dfa_exec+0x2ed0>
 *   @0x271920 subs r12, r5, #105
 *   @0x271924 ldrb r1, [r11, #0x3]
 *   @0x271928 rsbs r5, r12, #0
 *   @0x27192c ldrb r3, [r11, #0x4]
 *   @0x271930 adcs r5, r5, r12
 *   @0x271934 str r5, [sp, #0x30]
 *   @0x271938 ldrb r5, [r11, #0x1]
 *   @0x27193c add r11, r11, #5
 *   @0x271940 ldrb r2, [r11, #-0x3]
 *   @0x271944 orrs r3, r3, r1, lsl #8
 *   @0x271948 orr r5, r2, r5, lsl #8
 *   @0x27194c mvneq r3, #-2147483648
 *   @0x271950 str r3, [sp, #0x2c]
 *   @0x271954 cmp r8, #0
 *   @0x271958 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x27195c lsr r3, r8, #31
 *   @0x271960 cmp r5, #0
 *   @0x271964 movne r3, #0
 *   @0x271968 andeq r3, r3, #1
 *   @0x27196c cmp r3, #0
 *   @0x271970 bne 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x271974 cmp r5, #0
 *   @0x271978 beq 0x275adc <pcre_dfa_exec+0x7574>
 *   @0x27197c mov r4, #1
 *   @0x271980 b 0x271990 <pcre_dfa_exec+0x3428>
 *   @0x271984 cmp r5, r4
 *   @0x271988 add r10, r10, r0
 *   @0x27198c blt 0x275ad0 <pcre_dfa_exec+0x7568>
 *   @0x271990 str r9, [sp]
 *   @0x271994 mov r0, r7
 *   @0x271998 mov r1, r10
 *   @0x27199c mov r2, r8
 *   @0x2719a0 mov r3, r6
 *   @0x2719a4 add r4, r4, #1
 *   @0x2719a8 bl 0x25cc6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b44>
 *   @0x2719ac cmp r0, #0
 *   @0x2719b0 bge 0x271984 <pcre_dfa_exec+0x341c>
 *   @0x2719b4 cmn r0, #2
 *   @0x2719b8 ldr r3, [r6, #0x88]
 *   @0x2719bc ldreq r10, [r6, #0x78]
 *   @0x2719c0 cmp r3, #0
 *   @0x2719c4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2719c8 ldr r2, [r6, #0x78]
 *   @0x2719cc cmp r10, r2
 *   @0x2719d0 blo 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2719d4 ldr r2, [r6, #0x84]
 *   @0x2719d8 cmp r10, r2
 *   @0x2719dc bhi 0x271820 <pcre_dfa_exec+0x32b8>
 *   @0x2719e0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2719e4 ldr r12, [sp, #0x40]
 *   @0x2719e8 add r11, r11, #1
 *   @0x2719ec add r2, r12, r3
 *   @0x2719f0 and r3, r3, #1
 *   @0x2719f4 str r3, [sp, #0x30]
 *   @0x2719f8 ldrb r5, [r2, #-0xc18]
 *   @0x2719fc str r5, [sp, #0x2c]
 *   @0x271a00 ldr r12, [sp, #0x2c]
 *   @0x271a04 ldrb r5, [r2, #-0xc24]
 *   @0x271a08 cmp r12, #0
 *   @0x271a0c mvneq r12, #-2147483648
 *   @0x271a10 str r12, [sp, #0x2c]
 *   @0x271a14 b 0x271954 <pcre_dfa_exec+0x33ec>
 *   @0x271a18 mvn r0, #4
 *   @0x271a1c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271a20 ldr r3, [sp, #0x168]
 *   @0x271a24 mov lr, #1
 *   @0x271a28 mov r2, #0
 *   @0x271a2c str lr, [r6, #0x98]
 *   @0x271a30 add r3, r3, lr
 *   @0x271a34 str r2, [sp, #0x4]
 *   @0x271a38 str r3, [sp, #0x8]
 *   @0x271a3c mov r0, r10
 *   @0x271a40 str r6, [sp]
 *   @0x271a44 mov r1, r4
 *   @0x271a48 ldr r2, [sp, #0x1c]
 *   @0x271a4c ldr r3, [sp, #0x18]
 *   @0x271a50 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x271a54 cmp r0, #1
 *   @0x271a58 beq 0x277418 <pcre_dfa_exec+0x8eb0>
 *   @0x271a5c cmp r0, #0
 *   @0x271a60 cmnne r0, #992
 *   @0x271a64 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271a68 add r11, r4, r7
 *   @0x271a6c ldrb r3, [r11, #-0x3]
 *   @0x271a70 cmp r3, #119
 *   @0x271a74 beq 0x2721e4 <pcre_dfa_exec+0x3c7c>
 *   @0x271a78 ldrb r5, [r4, r7]
 *   @0x271a7c b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x271a80 ldr r9, [r6, #0x78]
 *   @0x271a84 mov r2, #1
 *   @0x271a88 movw r1, #0x180e
 *   @0x271a8c b 0x271ab0 <pcre_dfa_exec+0x3548>
 *   @0x271a90 cmp r3, #32
 *   @0x271a94 beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x271a98 bhi 0x2747c8 <pcre_dfa_exec+0x6260>
 *   @0x271a9c cmp r3, #9
 *   @0x271aa0 beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x271aa4 add r2, r2, #1
 *   @0x271aa8 cmp r2, r8
 *   @0x271aac bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271ab0 cmp r9, r10
 *   @0x271ab4 bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271ab8 ldrb r3, [r10]
 *   @0x271abc cmp r3, #191
 *   @0x271ac0 addls r10, r10, #1
 *   @0x271ac4 bls 0x271ae4 <pcre_dfa_exec+0x357c>
 *   @0x271ac8 tst r3, #32
 *   @0x271acc bne 0x274658 <pcre_dfa_exec+0x60f0>
 *   @0x271ad0 ldrb r0, [r10, #0x1]
 *   @0x271ad4 and r3, r3, #31
 *   @0x271ad8 add r10, r10, #2
 *   @0x271adc and r0, r0, #63
 *   @0x271ae0 orr r3, r0, r3, lsl #6
 *   @0x271ae4 cmp r3, r1
 *   @0x271ae8 beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x271aec bls 0x271a90 <pcre_dfa_exec+0x3528>
 *   @0x271af0 movw r12, #0x202f
 *   @0x271af4 cmp r3, r12
 *   @0x271af8 beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x271afc bhi 0x27472c <pcre_dfa_exec+0x61c4>
 *   @0x271b00 sub r3, r3, #8192
 *   @0x271b04 cmp r3, #10
 *   @0x271b08 bhi 0x271aa4 <pcre_dfa_exec+0x353c>
 *   @0x271b0c mov r0, #0
 *   @0x271b10 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271b14 ldr r9, [r6, #0x78]
 *   @0x271b18 mov r2, #1
 *   @0x271b1c b 0x271b38 <pcre_dfa_exec+0x35d0>
 *   @0x271b20 sub r3, r3, #10
 *   @0x271b24 cmp r3, #3
 *   @0x271b28 bls 0x271b88 <pcre_dfa_exec+0x3620>
 *   @0x271b2c add r2, r2, #1
 *   @0x271b30 cmp r2, r8
 *   @0x271b34 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271b38 cmp r9, r10
 *   @0x271b3c bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271b40 ldrb r3, [r10]
 *   @0x271b44 cmp r3, #191
 *   @0x271b48 addls r10, r10, #1
 *   @0x271b4c bls 0x271b6c <pcre_dfa_exec+0x3604>
 *   @0x271b50 tst r3, #32
 *   @0x271b54 bne 0x2746cc <pcre_dfa_exec+0x6164>
 *   @0x271b58 ldrb r1, [r10, #0x1]
 *   @0x271b5c and r3, r3, #31
 *   @0x271b60 add r10, r10, #2
 *   @0x271b64 and r1, r1, #63
 *   @0x271b68 orr r3, r1, r3, lsl #6
 *   @0x271b6c cmp r3, #133
 *   @0x271b70 beq 0x271b88 <pcre_dfa_exec+0x3620>
 *   @0x271b74 bls 0x271b20 <pcre_dfa_exec+0x35b8>
 *   @0x271b78 sub r3, r3, #8192
 *   @0x271b7c sub r3, r3, #40
 *   @0x271b80 cmp r3, #1
 *   @0x271b84 bhi 0x271b2c <pcre_dfa_exec+0x35c4>
 *   @0x271b88 mov r0, #0
 *   @0x271b8c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271b90 ldr r9, [r6, #0x78]
 *   @0x271b94 mov r2, #1
 *   @0x271b98 movw r1, #0x180e
 *   @0x271b9c b 0x271bc8 <pcre_dfa_exec+0x3660>
 *   @0x271ba0 cmp r3, #32
 *   @0x271ba4 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271ba8 bls 0x27575c <pcre_dfa_exec+0x71f4>
 *   @0x271bac cmp r3, #160
 *   @0x271bb0 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271bb4 cmp r3, #5760
 *   @0x271bb8 bne 0x271c2c <pcre_dfa_exec+0x36c4>
 *   @0x271bbc add r2, r2, #1
 *   @0x271bc0 cmp r2, r8
 *   @0x271bc4 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271bc8 cmp r9, r10
 *   @0x271bcc bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271bd0 ldrb r3, [r10]
 *   @0x271bd4 cmp r3, #191
 *   @0x271bd8 addls r10, r10, #1
 *   @0x271bdc bls 0x271bfc <pcre_dfa_exec+0x3694>
 *   @0x271be0 tst r3, #32
 *   @0x271be4 bne 0x2746fc <pcre_dfa_exec+0x6194>
 *   @0x271be8 ldrb r0, [r10, #0x1]
 *   @0x271bec and r3, r3, #31
 *   @0x271bf0 add r10, r10, #2
 *   @0x271bf4 and r0, r0, #63
 *   @0x271bf8 orr r3, r0, r3, lsl #6
 *   @0x271bfc cmp r3, r1
 *   @0x271c00 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271c04 bls 0x271ba0 <pcre_dfa_exec+0x3638>
 *   @0x271c08 movw r12, #0x202f
 *   @0x271c0c cmp r3, r12
 *   @0x271c10 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271c14 bls 0x27574c <pcre_dfa_exec+0x71e4>
 *   @0x271c18 movw r0, #0x205f
 *   @0x271c1c cmp r3, r0
 *   @0x271c20 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271c24 cmp r3, #12288
 *   @0x271c28 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x271c2c mov r0, #0
 *   @0x271c30 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271c34 ldr r9, [r6, #0x78]
 *   @0x271c38 mov r2, #1
 *   @0x271c3c b 0x271c58 <pcre_dfa_exec+0x36f0>
 *   @0x271c40 sub r3, r3, #10
 *   @0x271c44 cmp r3, #3
 *   @0x271c48 bhi 0x271ca8 <pcre_dfa_exec+0x3740>
 *   @0x271c4c add r2, r2, #1
 *   @0x271c50 cmp r2, r8
 *   @0x271c54 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271c58 cmp r10, r9
 *   @0x271c5c bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271c60 ldrb r3, [r10]
 *   @0x271c64 cmp r3, #191
 *   @0x271c68 addls r10, r10, #1
 *   @0x271c6c bls 0x271c8c <pcre_dfa_exec+0x3724>
 *   @0x271c70 tst r3, #32
 *   @0x271c74 bne 0x274628 <pcre_dfa_exec+0x60c0>
 *   @0x271c78 ldrb r1, [r10, #0x1]
 *   @0x271c7c and r3, r3, #31
 *   @0x271c80 add r10, r10, #2
 *   @0x271c84 and r1, r1, #63
 *   @0x271c88 orr r3, r1, r3, lsl #6
 *   @0x271c8c cmp r3, #133
 *   @0x271c90 beq 0x271c4c <pcre_dfa_exec+0x36e4>
 *   @0x271c94 bls 0x271c40 <pcre_dfa_exec+0x36d8>
 *   @0x271c98 sub r3, r3, #8192
 *   @0x271c9c sub r3, r3, #40
 *   @0x271ca0 cmp r3, #1
 *   @0x271ca4 bls 0x271c4c <pcre_dfa_exec+0x36e4>
 *   @0x271ca8 mov r0, #0
 *   @0x271cac b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x271cb0 ldr r9, [r6, #0x78]
 *   @0x271cb4 add r12, r6, #28
 *   @0x271cb8 mov r3, r5
 *   @0x271cbc mov r4, #1
 *   @0x271cc0 mov r5, r8
 *   @0x271cc4 mov r8, r3
 *   @0x271cc8 mov r2, r9
 *   @0x271ccc mov r9, r7
 *   @0x271cd0 mov r7, r12
 *   @0x271cd4 cmp r2, r10
 *   @0x271cd8 bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271cdc ldr r1, [r6, #0x18]
 *   @0x271ce0 cmp r1, #0
 *   @0x271ce4 beq 0x273cd4 <pcre_dfa_exec+0x576c>
 *   @0x271ce8 ldr r12, [sp, #0x28]
 *   @0x271cec mov r0, r10
 *   @0x271cf0 mov r3, r7
 *   @0x271cf4 str r12, [sp]
 *   @0x271cf8 bl 0x25f9fc <_pcre_is_newline>
 *   @0x271cfc adds r0, r0, #0
 *   @0x271d00 movne r0, #1
 *   @0x271d04 cmp r0, #0
 *   @0x271d08 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271d0c ldr r1, [r6, #0x88]
 *   @0x271d10 add r3, r10, #1
 *   @0x271d14 ldr r2, [r6, #0x78]
 *   @0x271d18 cmp r1, #0
 *   @0x271d1c bne 0x273cfc <pcre_dfa_exec+0x5794>
 *   @0x271d20 cmp r2, r3
 *   @0x271d24 bls 0x273d1c <pcre_dfa_exec+0x57b4>
 *   @0x271d28 ldrb r1, [r3]
 *   @0x271d2c and r1, r1, #192
 *   @0x271d30 cmp r1, #128
 *   @0x271d34 bne 0x273d1c <pcre_dfa_exec+0x57b4>
 *   @0x271d38 add r3, r3, #1
 *   @0x271d3c b 0x271d50 <pcre_dfa_exec+0x37e8>
 *   @0x271d40 ldrb r1, [r10]
 *   @0x271d44 and r1, r1, #192
 *   @0x271d48 cmp r1, #128
 *   @0x271d4c bne 0x271d60 <pcre_dfa_exec+0x37f8>
 *   @0x271d50 cmp r2, r3
 *   @0x271d54 mov r10, r3
 *   @0x271d58 add r3, r3, #1
 *   @0x271d5c bhi 0x271d40 <pcre_dfa_exec+0x37d8>
 *   @0x271d60 add r4, r4, #1
 *   @0x271d64 cmp r4, r5
 *   @0x271d68 ble 0x271cd4 <pcre_dfa_exec+0x376c>
 *   @0x271d6c mov r3, r8
 *   @0x271d70 mov r7, r9
 *   @0x271d74 mov r8, r5
 *   @0x271d78 mov r5, r3
 *   @0x271d7c b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271d80 ldr r9, [r6, #0x78]
 *   @0x271d84 mov r3, r10
 *   @0x271d88 mov r2, #1
 *   @0x271d8c b 0x271dbc <pcre_dfa_exec+0x3854>
 *   @0x271d90 ldrb r1, [r3]
 *   @0x271d94 add r3, r3, #1
 *   @0x271d98 cmp r1, #127
 *   @0x271d9c mov r10, r3
 *   @0x271da0 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271da4 ldr r0, [r6, #0x40]
 *   @0x271da8 ldrb r1, [r0, r1]
 *   @0x271dac tst r1, #16
 *   @0x271db0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271db4 cmp r2, r8
 *   @0x271db8 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271dbc cmp r9, r3
 *   @0x271dc0 add r2, r2, #1
 *   @0x271dc4 bhi 0x271d90 <pcre_dfa_exec+0x3828>
 *   @0x271dc8 ldr r2, [r6, #0x88]
 *   @0x271dcc cmp r2, #0
 *   @0x271dd0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271dd4 ldr r1, [r6, #0x84]
 *   @0x271dd8 cmp r1, r3
 *   @0x271ddc bhs 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271de0 cmp r2, #1
 *   @0x271de4 mov r3, #1
 *   @0x271de8 str r3, [r6, #0x64]
 *   @0x271dec ble 0x270504 <pcre_dfa_exec+0x1f9c>
 *   @0x271df0 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x271df4 ldr r9, [r6, #0x78]
 *   @0x271df8 mov r1, #1
 *   @0x271dfc cmp r9, r10
 *   @0x271e00 bls 0x2730a8 <pcre_dfa_exec+0x4b40>
 *   @0x271e04 ldrb r3, [r10]
 *   @0x271e08 cmp r3, #127
 *   @0x271e0c bhi 0x271e20 <pcre_dfa_exec+0x38b8>
 *   @0x271e10 ldr r2, [r6, #0x40]
 *   @0x271e14 ldrb r3, [r2, r3]
 *   @0x271e18 tst r3, #16
 *   @0x271e1c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271e20 add r3, r10, #1
 *   @0x271e24 cmp r9, r3
 *   @0x271e28 bls 0x275850 <pcre_dfa_exec+0x72e8>
 *   @0x271e2c ldrb r2, [r10, #0x1]
 *   @0x271e30 and r2, r2, #192
 *   @0x271e34 cmp r2, #128
 *   @0x271e38 bne 0x275850 <pcre_dfa_exec+0x72e8>
 *   @0x271e3c add r3, r10, #2
 *   @0x271e40 b 0x271e54 <pcre_dfa_exec+0x38ec>
 *   @0x271e44 ldrb r2, [r10]
 *   @0x271e48 and r2, r2, #192
 *   @0x271e4c cmp r2, #128
 *   @0x271e50 bne 0x271e64 <pcre_dfa_exec+0x38fc>
 *   @0x271e54 cmp r3, r9
 *   @0x271e58 mov r10, r3
 *   @0x271e5c add r3, r3, #1
 *   @0x271e60 bne 0x271e44 <pcre_dfa_exec+0x38dc>
 *   @0x271e64 add r1, r1, #1
 *   @0x271e68 cmp r1, r8
 *   @0x271e6c ble 0x271dfc <pcre_dfa_exec+0x3894>
 *   @0x271e70 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271e74 ldr r9, [r6, #0x78]
 *   @0x271e78 rsb r9, r8, r9
 *   @0x271e7c cmp r10, r9
 *   @0x271e80 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271e84 add r10, r10, r8
 *   @0x271e88 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271e8c ldr r9, [r6, #0x78]
 *   @0x271e90 mov r1, #1
 *   @0x271e94 cmp r9, r10
 *   @0x271e98 bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x271e9c add r3, r10, #1
 *   @0x271ea0 cmp r9, r3
 *   @0x271ea4 bls 0x275aa0 <pcre_dfa_exec+0x7538>
 *   @0x271ea8 ldrb r2, [r10, #0x1]
 *   @0x271eac and r2, r2, #192
 *   @0x271eb0 cmp r2, #128
 *   @0x271eb4 bne 0x275aa0 <pcre_dfa_exec+0x7538>
 *   @0x271eb8 add r3, r10, #2
 *   @0x271ebc b 0x271ed0 <pcre_dfa_exec+0x3968>
 *   @0x271ec0 ldrb r2, [r10]
 *   @0x271ec4 and r2, r2, #192
 *   @0x271ec8 cmp r2, #128
 *   @0x271ecc bne 0x271ee0 <pcre_dfa_exec+0x3978>
 *   @0x271ed0 cmp r3, r9
 *   @0x271ed4 mov r10, r3
 *   @0x271ed8 add r3, r3, #1
 *   @0x271edc bne 0x271ec0 <pcre_dfa_exec+0x3958>
 *   @0x271ee0 add r1, r1, #1
 *   @0x271ee4 cmp r1, r8
 *   @0x271ee8 ble 0x271e94 <pcre_dfa_exec+0x392c>
 *   @0x271eec b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271ef0 ldr r9, [r6, #0x78]
 *   @0x271ef4 mov r12, #1
 *   @0x271ef8 cmp r9, r10
 *   @0x271efc bls 0x2730a8 <pcre_dfa_exec+0x4b40>
 *   @0x271f00 ldrb r3, [r10]
 *   @0x271f04 cmp r3, #191
 *   @0x271f08 addls r10, r10, #1
 *   @0x271f0c bls 0x271f2c <pcre_dfa_exec+0x39c4>
 *   @0x271f10 tst r3, #32
 *   @0x271f14 bne 0x275df0 <pcre_dfa_exec+0x7888>
 *   @0x271f18 ldrb r2, [r10, #0x1]
 *   @0x271f1c and r3, r3, #31
 *   @0x271f20 add r10, r10, #2
 *   @0x271f24 and r2, r2, #63
 *   @0x271f28 orr r3, r2, r3, lsl #6
 *   @0x271f2c cmp r3, #13
 *   @0x271f30 beq 0x275d9c <pcre_dfa_exec+0x7834>
 *   @0x271f34 bhi 0x2759c0 <pcre_dfa_exec+0x7458>
 *   @0x271f38 cmp r3, #10
 *   @0x271f3c bne 0x275d40 <pcre_dfa_exec+0x77d8>
 *   @0x271f40 add r12, r12, #1
 *   @0x271f44 cmp r12, r8
 *   @0x271f48 ble 0x271ef8 <pcre_dfa_exec+0x3990>
 *   @0x271f4c b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271f50 ldr r9, [r6, #0x78]
 *   @0x271f54 mov r3, r10
 *   @0x271f58 mov r2, #1
 *   @0x271f5c b 0x271f8c <pcre_dfa_exec+0x3a24>
 *   @0x271f60 ldrb r1, [r3]
 *   @0x271f64 add r3, r3, #1
 *   @0x271f68 cmp r1, #127
 *   @0x271f6c mov r10, r3
 *   @0x271f70 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271f74 ldr r0, [r6, #0x40]
 *   @0x271f78 ldrb r1, [r0, r1]
 *   @0x271f7c tst r1, #1
 *   @0x271f80 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271f84 cmp r2, r8
 *   @0x271f88 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x271f8c cmp r9, r3
 *   @0x271f90 add r2, r2, #1
 *   @0x271f94 bhi 0x271f60 <pcre_dfa_exec+0x39f8>
 *   @0x271f98 ldr r2, [r6, #0x88]
 *   @0x271f9c cmp r2, #0
 *   @0x271fa0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271fa4 ldr r1, [r6, #0x84]
 *   @0x271fa8 cmp r3, r1
 *   @0x271fac bhi 0x271de0 <pcre_dfa_exec+0x3878>
 *   @0x271fb0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271fb4 ldr r9, [r6, #0x78]
 *   @0x271fb8 mov r1, #1
 *   @0x271fbc cmp r9, r10
 *   @0x271fc0 bls 0x2730a8 <pcre_dfa_exec+0x4b40>
 *   @0x271fc4 ldrb r3, [r10]
 *   @0x271fc8 cmp r3, #127
 *   @0x271fcc bhi 0x271fe0 <pcre_dfa_exec+0x3a78>
 *   @0x271fd0 ldr r2, [r6, #0x40]
 *   @0x271fd4 ldrb r3, [r2, r3]
 *   @0x271fd8 tst r3, #1
 *   @0x271fdc bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x271fe0 add r3, r10, #1
 *   @0x271fe4 cmp r9, r3
 *   @0x271fe8 bls 0x2758d4 <pcre_dfa_exec+0x736c>
 *   @0x271fec ldrb r2, [r10, #0x1]
 *   @0x271ff0 and r2, r2, #192
 *   @0x271ff4 cmp r2, #128
 *   @0x271ff8 bne 0x2758d4 <pcre_dfa_exec+0x736c>
 *   @0x271ffc add r3, r10, #2
 *   @0x272000 b 0x272014 <pcre_dfa_exec+0x3aac>
 *   @0x272004 ldrb r2, [r10]
 *   @0x272008 and r2, r2, #192
 *   @0x27200c cmp r2, #128
 *   @0x272010 bne 0x272024 <pcre_dfa_exec+0x3abc>
 *   @0x272014 cmp r3, r9
 *   @0x272018 mov r10, r3
 *   @0x27201c add r3, r3, #1
 *   @0x272020 bne 0x272004 <pcre_dfa_exec+0x3a9c>
 *   @0x272024 add r1, r1, #1
 *   @0x272028 cmp r1, r8
 *   @0x27202c ble 0x271fbc <pcre_dfa_exec+0x3a54>
 *   @0x272030 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272034 ldr r9, [r6, #0x78]
 *   @0x272038 mov r2, #1
 *   @0x27203c b 0x272078 <pcre_dfa_exec+0x3b10>
 *   @0x272040 ldrb r1, [r10, #0x1]
 *   @0x272044 and r3, r3, #31
 *   @0x272048 add r10, r10, #2
 *   @0x27204c and r1, r1, #63
 *   @0x272050 orr r3, r1, r3, lsl #6
 *   @0x272054 cmp r3, #127
 *   @0x272058 bhi 0x27206c <pcre_dfa_exec+0x3b04>
 *   @0x27205c ldr r1, [r6, #0x40]
 *   @0x272060 ldrb r3, [r1, r3]
 *   @0x272064 tst r3, #4
 *   @0x272068 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27206c add r2, r2, #1
 *   @0x272070 cmp r2, r8
 *   @0x272074 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272078 cmp r9, r10
 *   @0x27207c bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x272080 ldrb r3, [r10]
 *   @0x272084 cmp r3, #191
 *   @0x272088 addls r10, r10, #1
 *   @0x27208c bls 0x272054 <pcre_dfa_exec+0x3aec>
 *   @0x272090 tst r3, #32
 *   @0x272094 beq 0x272040 <pcre_dfa_exec+0x3ad8>
 *   @0x272098 tst r3, #16
 *   @0x27209c bne 0x275174 <pcre_dfa_exec+0x6c0c>
 *   @0x2720a0 lsl r0, r3, #12
 *   @0x2720a4 ldrb r1, [r10, #0x1]
 *   @0x2720a8 ldrb r3, [r10, #0x2]
 *   @0x2720ac add r10, r10, #3
 *   @0x2720b0 uxth r0, r0
 *   @0x2720b4 and r1, r1, #63
 *   @0x2720b8 and r3, r3, #63
 *   @0x2720bc orr r3, r0, r3
 *   @0x2720c0 orr r3, r3, r1, lsl #6
 *   @0x2720c4 b 0x272054 <pcre_dfa_exec+0x3aec>
 *   @0x2720c8 ldr r9, [r6, #0x78]
 *   @0x2720cc mov r3, r10
 *   @0x2720d0 mov r2, #1
 *   @0x2720d4 b 0x272104 <pcre_dfa_exec+0x3b9c>
 *   @0x2720d8 ldrb r1, [r3]
 *   @0x2720dc add r3, r3, #1
 *   @0x2720e0 cmp r1, #127
 *   @0x2720e4 mov r10, r3
 *   @0x2720e8 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2720ec ldr r0, [r6, #0x40]
 *   @0x2720f0 ldrb r1, [r0, r1]
 *   @0x2720f4 tst r1, #4
 *   @0x2720f8 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2720fc cmp r2, r8
 *   @0x272100 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272104 cmp r9, r3
 *   @0x272108 add r2, r2, #1
 *   @0x27210c bhi 0x2720d8 <pcre_dfa_exec+0x3b70>
 *   @0x272110 b 0x271f98 <pcre_dfa_exec+0x3a30>
 *   @0x272114 ldr r12, [r6, #0xa4]
 *   @0x272118 cmp r12, #0
 *   @0x27211c beq 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x272120 ldrb r1, [r4, #0x1]
 *   @0x272124 ldrb r3, [r4, #0x2]
 *   @0x272128 ldr r0, [r6, #0x24]
 *   @0x27212c orr r1, r3, r1, lsl #8
 *   @0x272130 ldrb r2, [r4, #0x3]
 *   @0x272134 ldrb r3, [r4, #0x4]
 *   @0x272138 mul r1, r0, r1
 *   @0x27213c orr r2, r3, r2, lsl #8
 *   @0x272140 ldr r9, [r6, #0x30]
 *   @0x272144 cmp r2, #0
 *   @0x272148 sub r2, r2, #1
 *   @0x27214c add r3, r9, r1
 *   @0x272150 beq 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x272154 ldrb r9, [r9, r1]
 *   @0x272158 ldrb r1, [r3, #0x1]
 *   @0x27215c ldr r12, [r12, #0x4]
 *   @0x272160 orr r1, r1, r9, lsl #8
 *   @0x272164 cmp r1, r12
 *   @0x272168 beq 0x2721d0 <pcre_dfa_exec+0x3c68>
 *   @0x27216c add r3, r3, r0
 *   @0x272170 b 0x272188 <pcre_dfa_exec+0x3c20>
 *   @0x272174 ldrb r9, [r1]
 *   @0x272178 ldrb r1, [r1, #0x1]
 *   @0x27217c orr r1, r1, r9, lsl #8
 *   @0x272180 cmp r1, r12
 *   @0x272184 beq 0x2721d0 <pcre_dfa_exec+0x3c68>
 *   @0x272188 sub r2, r2, #1
 *   @0x27218c mov r1, r3
 *   @0x272190 cmn r2, #1
 *   @0x272194 add r3, r3, r0
 *   @0x272198 bne 0x272174 <pcre_dfa_exec+0x3c0c>
 *   @0x27219c b 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x2721a0 ldr r3, [r6, #0xa4]
 *   @0x2721a4 cmp r3, #0
 *   @0x2721a8 beq 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x2721ac ldrb r0, [r4, #0x1]
 *   @0x2721b0 movw r1, #0xffff
 *   @0x2721b4 ldrb r2, [r4, #0x2]
 *   @0x2721b8 orr r2, r2, r0, lsl #8
 *   @0x2721bc cmp r2, r1
 *   @0x2721c0 beq 0x2721d0 <pcre_dfa_exec+0x3c68>
 *   @0x2721c4 ldr r3, [r3, #0x4]
 *   @0x2721c8 cmp r3, r2
 *   @0x2721cc bne 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x2721d0 ldr r3, [pc, #0x278]
 *   @0x2721d4 ldr r12, [sp, #0x20]
 *   @0x2721d8 ldr r7, [r12, r3]
 *   @0x2721dc ldrb r3, [r7, r8]
 *   @0x2721e0 add r11, r4, r3
 *   @0x2721e4 cmp r5, #140
 *   @0x2721e8 bne 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x2721ec mov r4, r11
 *   @0x2721f0 ldr r5, [sp, #0x164]
 *   @0x2721f4 ldr r11, [sp, #0x18]
 *   @0x2721f8 mov r12, #2
 *   @0x2721fc ldr lr, [sp, #0x168]
 *   @0x272200 mov r0, r10
 *   @0x272204 str r6, [sp]
 *   @0x272208 mov r1, r4
 *   @0x27220c str r5, [sp, #0x4]
 *   @0x272210 add lr, lr, #1
 *   @0x272214 ldr r2, [sp, #0x1c]
 *   @0x272218 mov r3, r11
 *   @0x27221c str lr, [sp, #0x8]
 *   @0x272220 str r12, [r6, #0x98]
 *   @0x272224 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x272228 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27222c ldrb r2, [r4, #0x3]
 *   @0x272230 ldrb r3, [r4, #0x4]
 *   @0x272234 ldrb r12, [r4, #0x1]
 *   @0x272238 ldrb r1, [r4, #0x2]
 *   @0x27223c orr r2, r3, r2, lsl #8
 *   @0x272240 ldr r0, [r6, #0x24]
 *   @0x272244 cmp r2, #0
 *   @0x272248 ldr r3, [r6, #0x30]
 *   @0x27224c orr r1, r1, r12, lsl #8
 *   @0x272250 sub r2, r2, #1
 *   @0x272254 mla r3, r0, r1, r3
 *   @0x272258 beq 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x27225c ldr r12, [sp, #0x18]
 *   @0x272260 ldrb r9, [r3]
 *   @0x272264 sub r2, r2, #1
 *   @0x272268 ldrb r1, [r3, #0x1]
 *   @0x27226c add r3, r3, r0
 *   @0x272270 orr r1, r1, r9, lsl #8
 *   @0x272274 lsl r1, r1, #1
 *   @0x272278 cmp r12, r1
 *   @0x27227c ble 0x272290 <pcre_dfa_exec+0x3d28>
 *   @0x272280 ldr r9, [r6, #0xc]
 *   @0x272284 ldr r1, [r9, r1, lsl #2]
 *   @0x272288 cmp r1, #0
 *   @0x27228c bge 0x2721d0 <pcre_dfa_exec+0x3c68>
 *   @0x272290 cmn r2, #1
 *   @0x272294 bne 0x272260 <pcre_dfa_exec+0x3cf8>
 *   @0x272298 b 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x27229c ldrb r2, [r4, #0x1]
 *   @0x2722a0 ldrb r3, [r4, #0x2]
 *   @0x2722a4 ldr r12, [sp, #0x18]
 *   @0x2722a8 orr r3, r3, r2, lsl #8
 *   @0x2722ac lsl r3, r3, #1
 *   @0x2722b0 cmp r12, r3
 *   @0x2722b4 ble 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x2722b8 ldr r2, [r6, #0xc]
 *   @0x2722bc ldr r3, [r2, r3, lsl #2]
 *   @0x2722c0 cmp r3, #0
 *   @0x2722c4 bge 0x2721d0 <pcre_dfa_exec+0x3c68>
 *   @0x2722c8 b 0x271a68 <pcre_dfa_exec+0x3500>
 *   @0x2722cc cmp r7, r8
 *   @0x2722d0 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x2722d4 ldr r9, [r6, #0x78]
 *   @0x2722d8 cmp r10, r9
 *   @0x2722dc bhs 0x27730c <pcre_dfa_exec+0x8da4>
 *   @0x2722e0 subs r4, r5, #20
 *   @0x2722e4 rsbs r12, r4, #0
 *   @0x2722e8 adcs r12, r12, r4
 *   @0x2722ec mov r4, r10
 *   @0x2722f0 b 0x272324 <pcre_dfa_exec+0x3dbc>
 *   @0x2722f4 sub r3, r3, #10
 *   @0x2722f8 cmp r3, #3
 *   @0x2722fc bls 0x27236c <pcre_dfa_exec+0x3e04>
 *   @0x272300 mov r3, #0
 *   @0x272304 cmp r3, r12
 *   @0x272308 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27230c add r8, r8, #1
 *   @0x272310 add r4, r4, r2
 *   @0x272314 cmp r8, r7
 *   @0x272318 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27231c cmp r9, r4
 *   @0x272320 bls 0x277310 <pcre_dfa_exec+0x8da8>
 *   @0x272324 ldrb r3, [r4]
 *   @0x272328 cmp r3, #191
 *   @0x27232c movls r2, #1
 *   @0x272330 bls 0x272350 <pcre_dfa_exec+0x3de8>
 *   @0x272334 tst r3, #32
 *   @0x272338 bne 0x2751bc <pcre_dfa_exec+0x6c54>
 *   @0x27233c ldrb r1, [r4, #0x1]
 *   @0x272340 and r3, r3, #31
 *   @0x272344 mov r2, #2
 *   @0x272348 and r1, r1, #63
 *   @0x27234c orr r3, r1, r3, lsl #6
 *   @0x272350 cmp r3, #133
 *   @0x272354 beq 0x27236c <pcre_dfa_exec+0x3e04>
 *   @0x272358 bls 0x2722f4 <pcre_dfa_exec+0x3d8c>
 *   @0x27235c sub r3, r3, #8192
 *   @0x272360 sub r3, r3, #40
 *   @0x272364 cmp r3, #1
 *   @0x272368 bhi 0x272300 <pcre_dfa_exec+0x3d98>
 *   @0x27236c mov r3, #1
 *   @0x272370 b 0x272304 <pcre_dfa_exec+0x3d9c>
 *   @0x272374 cmp r7, r8
 *   @0x272378 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x27237c ldr r9, [r6, #0x78]
 *   @0x272380 cmp r10, r9
 *   @0x272384 bhs 0x276780 <pcre_dfa_exec+0x8218>
 *   @0x272388 subs r3, r5, #18
 *   @0x27238c mov r4, r10
 *   @0x272390 rsbs r0, r3, #0
 *   @0x272394 adcs r0, r0, r3
 *   @0x272398 str r0, [sp, #0x54]
 *   @0x27239c movw r0, #0x180e
 *   @0x2723a0 b 0x2723e8 <pcre_dfa_exec+0x3e80>
 *   @0x2723a4 cmp r3, #32
 *   @0x2723a8 beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x2723ac bls 0x2757c8 <pcre_dfa_exec+0x7260>
 *   @0x2723b0 cmp r3, #160
 *   @0x2723b4 beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x2723b8 cmp r3, #5760
 *   @0x2723bc beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x2723c0 mov r3, #0
 *   @0x2723c4 ldr r12, [sp, #0x54]
 *   @0x2723c8 cmp r3, r12
 *   @0x2723cc beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2723d0 add r8, r8, #1
 *   @0x2723d4 add r4, r4, r2
 *   @0x2723d8 cmp r8, r7
 *   @0x2723dc beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2723e0 cmp r9, r4
 *   @0x2723e4 bls 0x276784 <pcre_dfa_exec+0x821c>
 *   @0x2723e8 ldrb r3, [r4]
 *   @0x2723ec cmp r3, #191
 *   @0x2723f0 movls r2, #1
 *   @0x2723f4 bls 0x272414 <pcre_dfa_exec+0x3eac>
 *   @0x2723f8 tst r3, #32
 *   @0x2723fc bne 0x2751ec <pcre_dfa_exec+0x6c84>
 *   @0x272400 ldrb r1, [r4, #0x1]
 *   @0x272404 and r3, r3, #31
 *   @0x272408 mov r2, #2
 *   @0x27240c and r1, r1, #63
 *   @0x272410 orr r3, r1, r3, lsl #6
 *   @0x272414 cmp r3, r0
 *   @0x272418 beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x27241c bls 0x2723a4 <pcre_dfa_exec+0x3e3c>
 *   @0x272420 movw r12, #0x202f
 *   @0x272424 cmp r3, r12
 *   @0x272428 beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x27242c bls 0x2757d4 <pcre_dfa_exec+0x726c>
 *   @0x272430 movw r1, #0x205f
 *   @0x272434 cmp r3, r1
 *   @0x272438 beq 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x27243c cmp r3, #12288
 *   @0x272440 bne 0x2723c0 <pcre_dfa_exec+0x3e58>
 *   @0x272444 mov r3, #1
 *   @0x272448 b 0x2723c4 <pcre_dfa_exec+0x3e5c>
 *   @0x27244c .word 0xfffffbb4
 *   @0x272450 .word 0xfffffb8c
 *   @0x272454 cmn r7, #-2147483647
 *   @0x272458 beq 0x277c64 <pcre_dfa_exec+0x96fc>
 *   @0x27245c cmp r7, r8
 *   @0x272460 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272464 ldr r9, [r6, #0x78]
 *   @0x272468 cmp r10, r9
 *   @0x27246c movlo r2, r10
 *   @0x272470 bhs 0x278ec4 <pcre_dfa_exec+0xa95c>
 *   @0x272474 add r4, r2, #1
 *   @0x272478 cmp r9, r4
 *   @0x27247c bls 0x278eb0 <pcre_dfa_exec+0xa948>
 *   @0x272480 ldrb r3, [r2, #0x1]
 *   @0x272484 and r3, r3, #192
 *   @0x272488 cmp r3, #128
 *   @0x27248c bne 0x279374 <pcre_dfa_exec+0xae0c>
 *   @0x272490 add r3, r2, #2
 *   @0x272494 b 0x2724a8 <pcre_dfa_exec+0x3f40>
 *   @0x272498 ldrb r1, [r2]
 *   @0x27249c and r1, r1, #192
 *   @0x2724a0 cmp r1, #128
 *   @0x2724a4 bne 0x2724b8 <pcre_dfa_exec+0x3f50>
 *   @0x2724a8 cmp r3, r9
 *   @0x2724ac mov r2, r3
 *   @0x2724b0 add r3, r3, #1
 *   @0x2724b4 bne 0x272498 <pcre_dfa_exec+0x3f30>
 *   @0x2724b8 add r8, r8, #1
 *   @0x2724bc cmp r8, r7
 *   @0x2724c0 beq 0x2776ac <pcre_dfa_exec+0x9144>
 *   @0x2724c4 cmp r9, r2
 *   @0x2724c8 bhi 0x272474 <pcre_dfa_exec+0x3f0c>
 *   @0x2724cc mov r4, r2
 *   @0x2724d0 ldr r2, [r6, #0x88]
 *   @0x2724d4 cmp r2, #0
 *   @0x2724d8 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2724dc ldr r3, [r6, #0x84]
 *   @0x2724e0 cmp r3, r4
 *   @0x2724e4 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2724e8 cmp r2, #1
 *   @0x2724ec mov r1, #1
 *   @0x2724f0 str r1, [r6, #0x64]
 *   @0x2724f4 bgt 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x2724f8 ldr r7, [sp, #0x30]
 *   @0x2724fc cmp r7, #0
 *   @0x272500 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x272504 cmp r4, r10
 *   @0x272508 bls 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x27250c ldr r7, [sp, #0x1c]
 *   @0x272510 ldr r8, [sp, #0x18]
 *   @0x272514 ldr r9, [sp, #0x164]
 *   @0x272518 ldr r3, [sp, #0x168]
 *   @0x27251c mov r0, r4
 *   @0x272520 str r6, [sp]
 *   @0x272524 mov r1, r11
 *   @0x272528 add r3, r3, #1
 *   @0x27252c str r9, [sp, #0x4]
 *   @0x272530 str r3, [sp, #0x8]
 *   @0x272534 mov r2, r7
 *   @0x272538 mov r3, r8
 *   @0x27253c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x272540 cmp r0, #0
 *   @0x272544 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272548 ldrb r3, [r4, #-0x1]
 *   @0x27254c sub r1, r4, #1
 *   @0x272550 and r2, r3, #192
 *   @0x272554 cmp r2, #128
 *   @0x272558 bne 0x274378 <pcre_dfa_exec+0x5e10>
 *   @0x27255c sub r12, r4, #2
 *   @0x272560 mov r4, r12
 *   @0x272564 ldrb r3, [r12], #-1
 *   @0x272568 and r2, r3, #192
 *   @0x27256c cmp r2, #128
 *   @0x272570 beq 0x272560 <pcre_dfa_exec+0x3ff8>
 *   @0x272574 subs r1, r5, #17
 *   @0x272578 rsbs r2, r1, #0
 *   @0x27257c adcs r2, r2, r1
 *   @0x272580 cmp r10, r4
 *   @0x272584 movhs r2, #0
 *   @0x272588 cmp r2, #0
 *   @0x27258c beq 0x272598 <pcre_dfa_exec+0x4030>
 *   @0x272590 cmp r3, #10
 *   @0x272594 beq 0x273de4 <pcre_dfa_exec+0x587c>
 *   @0x272598 cmp r4, r10
 *   @0x27259c bhi 0x272518 <pcre_dfa_exec+0x3fb0>
 *   @0x2725a0 mov r10, r4
 *   @0x2725a4 b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x2725a8 cmp r7, r8
 *   @0x2725ac ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x2725b0 ldr r9, [r6, #0x78]
 *   @0x2725b4 cmp r10, r9
 *   @0x2725b8 addlo r12, r6, #28
 *   @0x2725bc strlo r12, [sp, #0x2c]
 *   @0x2725c0 movlo r4, r10
 *   @0x2725c4 bhs 0x279230 <pcre_dfa_exec+0xacc8>
 *   @0x2725c8 ldr r1, [r6, #0x18]
 *   @0x2725cc cmp r1, #0
 *   @0x2725d0 beq 0x274104 <pcre_dfa_exec+0x5b9c>
 *   @0x2725d4 cmp r4, r9
 *   @0x2725d8 movhs r0, #0
 *   @0x2725dc blo 0x275718 <pcre_dfa_exec+0x71b0>
 *   @0x2725e0 mov r1, r0
 *   @0x2725e4 cmp r1, #0
 *   @0x2725e8 bne 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2725ec ldr r2, [r6, #0x88]
 *   @0x2725f0 add r1, r4, #1
 *   @0x2725f4 ldr r9, [r6, #0x78]
 *   @0x2725f8 cmp r2, #0
 *   @0x2725fc bne 0x274150 <pcre_dfa_exec+0x5be8>
 *   @0x272600 cmp r9, r1
 *   @0x272604 mov r4, r1
 *   @0x272608 bls 0x2791d8 <pcre_dfa_exec+0xac70>
 *   @0x27260c ldrb r3, [r1]
 *   @0x272610 and r3, r3, #192
 *   @0x272614 cmp r3, #128
 *   @0x272618 bne 0x273520 <pcre_dfa_exec+0x4fb8>
 *   @0x27261c add r1, r1, #1
 *   @0x272620 b 0x272634 <pcre_dfa_exec+0x40cc>
 *   @0x272624 ldrb r0, [r3]
 *   @0x272628 and r0, r0, #192
 *   @0x27262c cmp r0, #128
 *   @0x272630 bne 0x279170 <pcre_dfa_exec+0xac08>
 *   @0x272634 cmp r9, r1
 *   @0x272638 mov r3, r1
 *   @0x27263c add r1, r1, #1
 *   @0x272640 bhi 0x272624 <pcre_dfa_exec+0x40bc>
 *   @0x272644 add r8, r8, #1
 *   @0x272648 cmp r8, r7
 *   @0x27264c movne r4, r3
 *   @0x272650 beq 0x278754 <pcre_dfa_exec+0xa1ec>
 *   @0x272654 cmp r2, #0
 *   @0x272658 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27265c ldr r3, [r6, #0x84]
 *   @0x272660 cmp r3, r4
 *   @0x272664 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272668 cmp r2, #1
 *   @0x27266c mov r0, #1
 *   @0x272670 str r0, [r6, #0x64]
 *   @0x272674 ble 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272678 mvn r0, #11
 *   @0x27267c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272680 cmp r7, r8
 *   @0x272684 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272688 ldr r9, [r6, #0x78]
 *   @0x27268c cmp r10, r9
 *   @0x272690 movlo r4, r10
 *   @0x272694 blo 0x2726e8 <pcre_dfa_exec+0x4180>
 *   @0x272698 b 0x27730c <pcre_dfa_exec+0x8da4>
 *   @0x27269c tst r3, #32
 *   @0x2726a0 bne 0x274f90 <pcre_dfa_exec+0x6a28>
 *   @0x2726a4 ldrb r1, [r4, #0x1]
 *   @0x2726a8 and r3, r3, #31
 *   @0x2726ac mov r2, #2
 *   @0x2726b0 and r1, r1, #63
 *   @0x2726b4 orr r3, r1, r3, lsl #6
 *   @0x2726b8 cmp r3, #255
 *   @0x2726bc bhi 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2726c0 ldr r1, [r6, #0x40]
 *   @0x2726c4 ldrb r3, [r1, r3]
 *   @0x2726c8 tst r3, #16
 *   @0x2726cc beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2726d0 add r8, r8, #1
 *   @0x2726d4 add r4, r4, r2
 *   @0x2726d8 cmp r8, r7
 *   @0x2726dc beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2726e0 cmp r9, r4
 *   @0x2726e4 bls 0x277310 <pcre_dfa_exec+0x8da8>
 *   @0x2726e8 ldrb r3, [r4]
 *   @0x2726ec cmp r3, #191
 *   @0x2726f0 bhi 0x27269c <pcre_dfa_exec+0x4134>
 *   @0x2726f4 mov r2, #1
 *   @0x2726f8 b 0x2726c0 <pcre_dfa_exec+0x4158>
 *   @0x2726fc cmp r7, r8
 *   @0x272700 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272704 ldr r9, [r6, #0x78]
 *   @0x272708 cmp r10, r9
 *   @0x27270c movlo r4, r10
 *   @0x272710 blo 0x272764 <pcre_dfa_exec+0x41fc>
 *   @0x272714 b 0x276f48 <pcre_dfa_exec+0x89e0>
 *   @0x272718 tst r3, #32
 *   @0x27271c bne 0x274fc0 <pcre_dfa_exec+0x6a58>
 *   @0x272720 ldrb r1, [r4, #0x1]
 *   @0x272724 and r3, r3, #31
 *   @0x272728 mov r2, #2
 *   @0x27272c and r1, r1, #63
 *   @0x272730 orr r3, r1, r3, lsl #6
 *   @0x272734 cmp r3, #255
 *   @0x272738 bhi 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27273c ldr r1, [r6, #0x40]
 *   @0x272740 ldrb r3, [r1, r3]
 *   @0x272744 tst r3, #1
 *   @0x272748 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27274c add r8, r8, #1
 *   @0x272750 add r4, r4, r2
 *   @0x272754 cmp r8, r7
 *   @0x272758 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27275c cmp r4, r9
 *   @0x272760 bhs 0x276f4c <pcre_dfa_exec+0x89e4>
 *   @0x272764 ldrb r3, [r4]
 *   @0x272768 cmp r3, #191
 *   @0x27276c bhi 0x272718 <pcre_dfa_exec+0x41b0>
 *   @0x272770 mov r2, #1
 *   @0x272774 b 0x27273c <pcre_dfa_exec+0x41d4>
 *   @0x272778 cmp r7, r8
 *   @0x27277c ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272780 ldr r9, [r6, #0x78]
 *   @0x272784 cmp r10, r9
 *   @0x272788 movlo r4, r10
 *   @0x27278c blo 0x2727e0 <pcre_dfa_exec+0x4278>
 *   @0x272790 b 0x27800c <pcre_dfa_exec+0x9aa4>
 *   @0x272794 tst r3, #32
 *   @0x272798 bne 0x275078 <pcre_dfa_exec+0x6b10>
 *   @0x27279c ldrb r1, [r4, #0x1]
 *   @0x2727a0 and r3, r3, #31
 *   @0x2727a4 mov r2, #2
 *   @0x2727a8 and r1, r1, #63
 *   @0x2727ac orr r3, r1, r3, lsl #6
 *   @0x2727b0 cmp r3, #255
 *   @0x2727b4 bhi 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2727b8 ldr r1, [r6, #0x40]
 *   @0x2727bc ldrb r3, [r1, r3]
 *   @0x2727c0 tst r3, #4
 *   @0x2727c4 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2727c8 add r8, r8, #1
 *   @0x2727cc add r4, r4, r2
 *   @0x2727d0 cmp r8, r7
 *   @0x2727d4 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2727d8 cmp r4, r9
 *   @0x2727dc bhs 0x278010 <pcre_dfa_exec+0x9aa8>
 *   @0x2727e0 ldrb r3, [r4]
 *   @0x2727e4 cmp r3, #191
 *   @0x2727e8 bhi 0x272794 <pcre_dfa_exec+0x422c>
 *   @0x2727ec mov r2, #1
 *   @0x2727f0 b 0x2727b8 <pcre_dfa_exec+0x4250>
 *   @0x2727f4 cmp r7, r8
 *   @0x2727f8 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x2727fc ldr r9, [r6, #0x78]
 *   @0x272800 cmp r10, r9
 *   @0x272804 movlo r4, r10
 *   @0x272808 blo 0x27285c <pcre_dfa_exec+0x42f4>
 *   @0x27280c b 0x276f48 <pcre_dfa_exec+0x89e0>
 *   @0x272810 cmp r3, #10
 *   @0x272814 beq 0x272844 <pcre_dfa_exec+0x42dc>
 *   @0x272818 ldr r1, [r6, #0x68]
 *   @0x27281c cmp r1, #0
 *   @0x272820 bne 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272824 sub r1, r3, #11
 *   @0x272828 cmp r3, #133
 *   @0x27282c cmpne r1, #1
 *   @0x272830 bls 0x272844 <pcre_dfa_exec+0x42dc>
 *   @0x272834 sub r3, r3, #8192
 *   @0x272838 sub r3, r3, #40
 *   @0x27283c cmp r3, #1
 *   @0x272840 bhi 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272844 add r4, r4, r2
 *   @0x272848 add r8, r8, #1
 *   @0x27284c cmp r8, r7
 *   @0x272850 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272854 cmp r4, r9
 *   @0x272858 bhs 0x276f4c <pcre_dfa_exec+0x89e4>
 *   @0x27285c ldrb r3, [r4]
 *   @0x272860 cmp r3, #191
 *   @0x272864 movls r2, #1
 *   @0x272868 bls 0x272888 <pcre_dfa_exec+0x4320>
 *   @0x27286c tst r3, #32
 *   @0x272870 bne 0x2749bc <pcre_dfa_exec+0x6454>
 *   @0x272874 ldrb r1, [r4, #0x1]
 *   @0x272878 and r3, r3, #31
 *   @0x27287c mov r2, #2
 *   @0x272880 and r1, r1, #63
 *   @0x272884 orr r3, r1, r3, lsl #6
 *   @0x272888 cmp r3, #13
 *   @0x27288c bne 0x272810 <pcre_dfa_exec+0x42a8>
 *   @0x272890 add r3, r4, #1
 *   @0x272894 cmp r9, r3
 *   @0x272898 bls 0x278754 <pcre_dfa_exec+0xa1ec>
 *   @0x27289c ldrb r2, [r4, #0x1]
 *   @0x2728a0 cmp r2, #10
 *   @0x2728a4 addeq r4, r4, #2
 *   @0x2728a8 beq 0x272848 <pcre_dfa_exec+0x42e0>
 *   @0x2728ac add r8, r8, #1
 *   @0x2728b0 cmp r8, r7
 *   @0x2728b4 beq 0x278754 <pcre_dfa_exec+0xa1ec>
 *   @0x2728b8 mov r4, r3
 *   @0x2728bc b 0x27285c <pcre_dfa_exec+0x42f4>
 *   @0x2728c0 ldr r4, [r6, #0x78]
 *   @0x2728c4 rsb r8, r8, r7
 *   @0x2728c8 rsb r3, r10, r4
 *   @0x2728cc cmp r8, r3
 *   @0x2728d0 bls 0x27748c <pcre_dfa_exec+0x8f24>
 *   @0x2728d4 ldr r2, [r6, #0x88]
 *   @0x2728d8 cmp r2, #0
 *   @0x2728dc beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2728e0 ldr r3, [r6, #0x84]
 *   @0x2728e4 cmp r4, r3
 *   @0x2728e8 bls 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2728ec cmp r2, #1
 *   @0x2728f0 mov r3, #1
 *   @0x2728f4 str r3, [r6, #0x64]
 *   @0x2728f8 ble 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2728fc b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x272900 cmp r7, r8
 *   @0x272904 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272908 ldr r9, [r6, #0x78]
 *   @0x27290c cmp r10, r9
 *   @0x272910 movlo r4, r10
 *   @0x272914 blo 0x272958 <pcre_dfa_exec+0x43f0>
 *   @0x272918 b 0x278ec4 <pcre_dfa_exec+0xa95c>
 *   @0x27291c tst r3, #32
 *   @0x272920 bne 0x274d90 <pcre_dfa_exec+0x6828>
 *   @0x272924 ldrb r1, [r4, #0x1]
 *   @0x272928 and r3, r3, #31
 *   @0x27292c mov r2, #2
 *   @0x272930 and r1, r1, #63
 *   @0x272934 orr r3, r1, r3, lsl #6
 *   @0x272938 cmp r3, #255
 *   @0x27293c bls 0x272968 <pcre_dfa_exec+0x4400>
 *   @0x272940 add r8, r8, #1
 *   @0x272944 add r4, r4, r2
 *   @0x272948 cmp r8, r7
 *   @0x27294c beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272950 cmp r9, r4
 *   @0x272954 bls 0x2724d0 <pcre_dfa_exec+0x3f68>
 *   @0x272958 ldrb r3, [r4]
 *   @0x27295c cmp r3, #191
 *   @0x272960 bhi 0x27291c <pcre_dfa_exec+0x43b4>
 *   @0x272964 mov r2, #1
 *   @0x272968 ldr r1, [r6, #0x40]
 *   @0x27296c ldrb r3, [r1, r3]
 *   @0x272970 tst r3, #4
 *   @0x272974 beq 0x272940 <pcre_dfa_exec+0x43d8>
 *   @0x272978 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27297c cmp r7, r8
 *   @0x272980 ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272984 ldr r9, [r6, #0x78]
 *   @0x272988 cmp r10, r9
 *   @0x27298c movlo r4, r10
 *   @0x272990 blo 0x2729d4 <pcre_dfa_exec+0x446c>
 *   @0x272994 b 0x277538 <pcre_dfa_exec+0x8fd0>
 *   @0x272998 tst r3, #32
 *   @0x27299c bne 0x274e04 <pcre_dfa_exec+0x689c>
 *   @0x2729a0 ldrb r1, [r4, #0x1]
 *   @0x2729a4 and r3, r3, #31
 *   @0x2729a8 mov r2, #2
 *   @0x2729ac and r1, r1, #63
 *   @0x2729b0 orr r3, r1, r3, lsl #6
 *   @0x2729b4 cmp r3, #255
 *   @0x2729b8 bls 0x2729e4 <pcre_dfa_exec+0x447c>
 *   @0x2729bc add r8, r8, #1
 *   @0x2729c0 add r4, r4, r2
 *   @0x2729c4 cmp r8, r7
 *   @0x2729c8 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2729cc cmp r9, r4
 *   @0x2729d0 bls 0x27753c <pcre_dfa_exec+0x8fd4>
 *   @0x2729d4 ldrb r3, [r4]
 *   @0x2729d8 cmp r3, #191
 *   @0x2729dc bhi 0x272998 <pcre_dfa_exec+0x4430>
 *   @0x2729e0 mov r2, #1
 *   @0x2729e4 ldr r1, [r6, #0x40]
 *   @0x2729e8 ldrb r3, [r1, r3]
 *   @0x2729ec tst r3, #1
 *   @0x2729f0 beq 0x2729bc <pcre_dfa_exec+0x4454>
 *   @0x2729f4 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2729f8 cmp r7, r8
 *   @0x2729fc ble 0x27936c <pcre_dfa_exec+0xae04>
 *   @0x272a00 ldr r9, [r6, #0x78]
 *   @0x272a04 cmp r10, r9
 *   @0x272a08 movlo r4, r10
 *   @0x272a0c blo 0x272a50 <pcre_dfa_exec+0x44e8>
 *   @0x272a10 b 0x276780 <pcre_dfa_exec+0x8218>
 *   @0x272a14 tst r3, #32
 *   @0x272a18 bne 0x274dd4 <pcre_dfa_exec+0x686c>
 *   @0x272a1c ldrb r1, [r4, #0x1]
 *   @0x272a20 and r3, r3, #31
 *   @0x272a24 mov r2, #2
 *   @0x272a28 and r1, r1, #63
 *   @0x272a2c orr r3, r1, r3, lsl #6
 *   @0x272a30 cmp r3, #255
 *   @0x272a34 bls 0x272a60 <pcre_dfa_exec+0x44f8>
 *   @0x272a38 add r8, r8, #1
 *   @0x272a3c add r4, r4, r2
 *   @0x272a40 cmp r8, r7
 *   @0x272a44 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272a48 cmp r9, r4
 *   @0x272a4c bls 0x276784 <pcre_dfa_exec+0x821c>
 *   @0x272a50 ldrb r3, [r4]
 *   @0x272a54 cmp r3, #191
 *   @0x272a58 bhi 0x272a14 <pcre_dfa_exec+0x44ac>
 *   @0x272a5c mov r2, #1
 *   @0x272a60 ldr r1, [r6, #0x40]
 *   @0x272a64 ldrb r3, [r1, r3]
 *   @0x272a68 tst r3, #16
 *   @0x272a6c beq 0x272a38 <pcre_dfa_exec+0x44d0>
 *   @0x272a70 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x272a74 mvn r0, #13
 *   @0x272a78 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272a7c mvn r0, #13
 *   @0x272a80 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272a84 ldr r12, [r6, #0x8c]
 *   @0x272a88 ldr r11, [r6, #0x70]
 *   @0x272a8c ldr r3, [r6, #0x80]
 *   @0x272a90 str r12, [sp, #0x18]
 *   @0x272a94 ldr r12, [sp, #0x30]
 *   @0x272a98 cmp r3, r10
 *   @0x272a9c add r11, r11, r12
 *   @0x272aa0 ldr r12, [r6, #0x7c]
 *   @0x272aa4 str r12, [sp, #0x1c]
 *   @0x272aa8 beq 0x273dac <pcre_dfa_exec+0x5844>
 *   @0x272aac mov r12, #1
 *   @0x272ab0 mov r10, r3
 *   @0x272ab4 str r12, [sp, #0x2c]
 *   @0x272ab8 b 0x26f7ec <pcre_dfa_exec+0x1284>
 *   @0x272abc ldrb r1, [r11, #0x1]
 *   @0x272ac0 ldrb r3, [r11, #0x2]
 *   @0x272ac4 ldr r2, [r6, #0x7c]
 *   @0x272ac8 orr r3, r3, r1, lsl #8
 *   @0x272acc add r3, r11, r3
 *   @0x272ad0 cmp r3, r2
 *   @0x272ad4 bls 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x272ad8 ldrb r2, [r11]
 *   @0x272adc cmp r2, #119
 *   @0x272ae0 beq 0x2740b4 <pcre_dfa_exec+0x5b4c>
 *   @0x272ae4 ldrb r2, [r3]
 *   @0x272ae8 cmp r2, #119
 *   @0x272aec bne 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x272af0 mov r11, r3
 *   @0x272af4 b 0x26f85c <pcre_dfa_exec+0x12f4>
 *   @0x272af8 cmp r5, #45
 *   @0x272afc add r11, r4, #1
 *   @0x272b00 bhi 0x27317c <pcre_dfa_exec+0x4c14>
 *   @0x272b04 cmp r7, #0
 *   @0x272b08 beq 0x276c70 <pcre_dfa_exec+0x8708>
 *   @0x272b0c ldr r9, [r6, #0x78]
 *   @0x272b10 cmp r10, r9
 *   @0x272b14 bhs 0x273500 <pcre_dfa_exec+0x4f98>
 *   @0x272b18 ldrb r2, [r10]
 *   @0x272b1c add r8, r10, #1
 *   @0x272b20 cmp r2, r12
 *   @0x272b24 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272b28 mov r3, #1
 *   @0x272b2c b 0x272b44 <pcre_dfa_exec+0x45dc>
 *   @0x272b30 cmp r8, r9
 *   @0x272b34 beq 0x273504 <pcre_dfa_exec+0x4f9c>
 *   @0x272b38 ldrb r1, [r8], #1
 *   @0x272b3c cmp r1, r2
 *   @0x272b40 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272b44 add r3, r3, #1
 *   @0x272b48 cmp r7, r3
 *   @0x272b4c bge 0x272b30 <pcre_dfa_exec+0x45c8>
 *   @0x272b50 ldr r5, [sp, #0x2c]
 *   @0x272b54 cmp r7, r5
 *   @0x272b58 beq 0x274850 <pcre_dfa_exec+0x62e8>
 *   @0x272b5c ldr r3, [sp, #0x4c]
 *   @0x272b60 cmp r3, #0
 *   @0x272b64 bne 0x2786dc <pcre_dfa_exec+0xa174>
 *   @0x272b68 ldr r5, [sp, #0x2c]
 *   @0x272b6c cmp r5, r7
 *   @0x272b70 ble 0x277dfc <pcre_dfa_exec+0x9894>
 *   @0x272b74 ldr r9, [r6, #0x78]
 *   @0x272b78 cmp r9, r8
 *   @0x272b7c bls 0x27590c <pcre_dfa_exec+0x73a4>
 *   @0x272b80 ldrb r2, [r8]
 *   @0x272b84 cmp r2, r12
 *   @0x272b88 bne 0x277dfc <pcre_dfa_exec+0x9894>
 *   @0x272b8c rsb r0, r7, r5
 *   @0x272b90 add r3, r8, #1
 *   @0x272b94 add r0, r8, r0
 *   @0x272b98 b 0x272bb4 <pcre_dfa_exec+0x464c>
 *   @0x272b9c cmp r3, r9
 *   @0x272ba0 add r3, r3, #1
 *   @0x272ba4 beq 0x275910 <pcre_dfa_exec+0x73a8>
 *   @0x272ba8 ldrb r1, [r10]
 *   @0x272bac cmp r2, r1
 *   @0x272bb0 bne 0x272bc0 <pcre_dfa_exec+0x4658>
 *   @0x272bb4 cmp r3, r0
 *   @0x272bb8 mov r10, r3
 *   @0x272bbc bne 0x272b9c <pcre_dfa_exec+0x4634>
 *   @0x272bc0 ldr r12, [sp, #0x30]
 *   @0x272bc4 cmp r12, #0
 *   @0x272bc8 bne 0x274388 <pcre_dfa_exec+0x5e20>
 *   @0x272bcc cmp r8, r10
 *   @0x272bd0 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x272bd4 ldr r4, [sp, #0x1c]
 *   @0x272bd8 ldr r5, [sp, #0x18]
 *   @0x272bdc ldr r7, [sp, #0x164]
 *   @0x272be0 b 0x272bec <pcre_dfa_exec+0x4684>
 *   @0x272be4 cmp r10, r8
 *   @0x272be8 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x272bec ldr r12, [sp, #0x168]
 *   @0x272bf0 mov r0, r10
 *   @0x272bf4 str r6, [sp]
 *   @0x272bf8 mov r1, r11
 *   @0x272bfc add r12, r12, #1
 *   @0x272c00 str r7, [sp, #0x4]
 *   @0x272c04 mov r2, r4
 *   @0x272c08 str r12, [sp, #0x8]
 *   @0x272c0c mov r3, r5
 *   @0x272c10 sub r10, r10, #1
 *   @0x272c14 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x272c18 cmp r0, #0
 *   @0x272c1c beq 0x272be4 <pcre_dfa_exec+0x467c>
 *   @0x272c20 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272c24 ldr r5, [sp, #0x24]
 *   @0x272c28 cmp r5, #0
 *   @0x272c2c bne 0x273404 <pcre_dfa_exec+0x4e9c>
 *   @0x272c30 cmp r8, #0
 *   @0x272c34 beq 0x272c7c <pcre_dfa_exec+0x4714>
 *   @0x272c38 ldr r9, [r6, #0x78]
 *   @0x272c3c cmp r10, r9
 *   @0x272c40 bhs 0x2740e4 <pcre_dfa_exec+0x5b7c>
 *   @0x272c44 ldrb r3, [r10]
 *   @0x272c48 add r10, r10, #1
 *   @0x272c4c cmp r3, r7
 *   @0x272c50 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272c54 mov r3, #1
 *   @0x272c58 b 0x272c70 <pcre_dfa_exec+0x4708>
 *   @0x272c5c cmp r10, r9
 *   @0x272c60 beq 0x2740e4 <pcre_dfa_exec+0x5b7c>
 *   @0x272c64 ldrb r2, [r10], #1
 *   @0x272c68 cmp r2, r7
 *   @0x272c6c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272c70 add r3, r3, #1
 *   @0x272c74 cmp r8, r3
 *   @0x272c78 bge 0x272c5c <pcre_dfa_exec+0x46f4>
 *   @0x272c7c cmp r8, r1
 *   @0x272c80 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x272c84 ldr r12, [sp, #0x30]
 *   @0x272c88 cmp r12, #0
 *   @0x272c8c bne 0x2780d8 <pcre_dfa_exec+0x9b70>
 *   @0x272c90 ldr r12, [sp, #0x24]
 *   @0x272c94 cmp r12, #0
 *   @0x272c98 bne 0x27485c <pcre_dfa_exec+0x62f4>
 *   @0x272c9c cmp r1, r8
 *   @0x272ca0 ble 0x277fbc <pcre_dfa_exec+0x9a54>
 *   @0x272ca4 ldr r9, [r6, #0x78]
 *   @0x272ca8 cmp r10, r9
 *   @0x272cac bhs 0x275e20 <pcre_dfa_exec+0x78b8>
 *   @0x272cb0 ldrb r3, [r10]
 *   @0x272cb4 cmp r3, r7
 *   @0x272cb8 beq 0x277fbc <pcre_dfa_exec+0x9a54>
 *   @0x272cbc rsb r1, r8, r1
 *   @0x272cc0 add r3, r10, #1
 *   @0x272cc4 add r1, r10, r1
 *   @0x272cc8 b 0x272ce4 <pcre_dfa_exec+0x477c>
 *   @0x272ccc cmp r3, r9
 *   @0x272cd0 add r3, r3, #1
 *   @0x272cd4 beq 0x275e24 <pcre_dfa_exec+0x78bc>
 *   @0x272cd8 ldrb r2, [r4]
 *   @0x272cdc cmp r2, r7
 *   @0x272ce0 beq 0x272cf0 <pcre_dfa_exec+0x4788>
 *   @0x272ce4 cmp r3, r1
 *   @0x272ce8 mov r4, r3
 *   @0x272cec bne 0x272ccc <pcre_dfa_exec+0x4764>
 *   @0x272cf0 ldr r3, [sp, #0x2c]
 *   @0x272cf4 cmp r3, #0
 *   @0x272cf8 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x272cfc cmp r10, r4
 *   @0x272d00 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x272d04 ldr r5, [sp, #0x1c]
 *   @0x272d08 ldr r7, [sp, #0x18]
 *   @0x272d0c ldr r8, [sp, #0x164]
 *   @0x272d10 b 0x272d1c <pcre_dfa_exec+0x47b4>
 *   @0x272d14 cmp r10, r4
 *   @0x272d18 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x272d1c ldr r12, [sp, #0x168]
 *   @0x272d20 mov r0, r4
 *   @0x272d24 str r6, [sp]
 *   @0x272d28 mov r1, r11
 *   @0x272d2c add r12, r12, #1
 *   @0x272d30 str r8, [sp, #0x4]
 *   @0x272d34 mov r2, r5
 *   @0x272d38 str r12, [sp, #0x8]
 *   @0x272d3c mov r3, r7
 *   @0x272d40 sub r4, r4, #1
 *   @0x272d44 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x272d48 cmp r0, #0
 *   @0x272d4c beq 0x272d14 <pcre_dfa_exec+0x47ac>
 *   @0x272d50 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x272d54 mov r6, r7
 *   @0x272d58 ldr r3, [r6, #0x88]
 *   @0x272d5c cmp r3, #0
 *   @0x272d60 bne 0x26f944 <pcre_dfa_exec+0x13dc>
 *   @0x272d64 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272d68 cmp r3, #15
 *   @0x272d6c addls pc, pc, r3, lsl #2
 *   @0x272d70 b 0x273174 <pcre_dfa_exec+0x4c0c>
 *   @0x272d74 b 0x273028 <pcre_dfa_exec+0x4ac0>
 *   @0x272d78 b 0x272fe4 <pcre_dfa_exec+0x4a7c>
 *   @0x272d7c b 0x272fa0 <pcre_dfa_exec+0x4a38>
 *   @0x272d80 b 0x272f5c <pcre_dfa_exec+0x49f4>
 *   @0x272d84 b 0x272f18 <pcre_dfa_exec+0x49b0>
 *   @0x272d88 b 0x272ed4 <pcre_dfa_exec+0x496c>
 *   @0x272d8c b 0x272e08 <pcre_dfa_exec+0x48a0>
 *   @0x272d90 b 0x272db4 <pcre_dfa_exec+0x484c>
 *   @0x272d94 b 0x272db4 <pcre_dfa_exec+0x484c>
 *   @0x272d98 b 0x273174 <pcre_dfa_exec+0x4c0c>
 *   @0x272d9c b 0x273174 <pcre_dfa_exec+0x4c0c>
 *   @0x272da0 b 0x273130 <pcre_dfa_exec+0x4bc8>
 *   @0x272da4 b 0x2730f0 <pcre_dfa_exec+0x4b88>
 *   @0x272da8 b 0x2730b8 <pcre_dfa_exec+0x4b50>
 *   @0x272dac b 0x27306c <pcre_dfa_exec+0x4b04>
 *   @0x272db0 b 0x272dc8 <pcre_dfa_exec+0x4860>
 *   @0x272db4 ldr r9, [r6, #0x78]
 *   @0x272db8 rsb r9, r8, r9
 *   @0x272dbc cmp r10, r9
 *   @0x272dc0 bls 0x271e84 <pcre_dfa_exec+0x391c>
 *   @0x272dc4 b 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x272dc8 ldr r9, [r6, #0x78]
 *   @0x272dcc mov r2, #1
 *   @0x272dd0 b 0x272df8 <pcre_dfa_exec+0x4890>
 *   @0x272dd4 ldrb r3, [r10], #1
 *   @0x272dd8 cmp r3, #10
 *   @0x272ddc blo 0x277344 <pcre_dfa_exec+0x8ddc>
 *   @0x272de0 cmp r3, #13
 *   @0x272de4 bls 0x272df0 <pcre_dfa_exec+0x4888>
 *   @0x272de8 cmp r3, #133
 *   @0x272dec bne 0x277344 <pcre_dfa_exec+0x8ddc>
 *   @0x272df0 cmp r2, r8
 *   @0x272df4 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272df8 cmp r9, r10
 *   @0x272dfc add r2, r2, #1
 *   @0x272e00 bhi 0x272dd4 <pcre_dfa_exec+0x486c>
 *   @0x272e04 b 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x272e08 add r12, r6, #28
 *   @0x272e0c str r12, [sp, #0x4c]
 *   @0x272e10 mov r12, r10
 *   @0x272e14 mov r9, r7
 *   @0x272e18 add r4, r10, #1
 *   @0x272e1c mov r7, r5
 *   @0x272e20 mov r5, r12
 *   @0x272e24 b 0x272e94 <pcre_dfa_exec+0x492c>
 *   @0x272e28 mov lr, #0
 *   @0x272e2c mov r0, r10
 *   @0x272e30 str lr, [sp]
 *   @0x272e34 ldr r3, [sp, #0x4c]
 *   @0x272e38 bl 0x25f9fc <_pcre_is_newline>
 *   @0x272e3c adds r0, r0, #0
 *   @0x272e40 movne r0, #1
 *   @0x272e44 cmp r0, #0
 *   @0x272e48 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272e4c ldr r3, [r6, #0x88]
 *   @0x272e50 cmp r3, #0
 *   @0x272e54 beq 0x272e7c <pcre_dfa_exec+0x4914>
 *   @0x272e58 ldr r2, [r6, #0x78]
 *   @0x272e5c cmp r4, r2
 *   @0x272e60 blo 0x272e7c <pcre_dfa_exec+0x4914>
 *   @0x272e64 ldr r2, [r6, #0x18]
 *   @0x272e68 cmp r2, #0
 *   @0x272e6c bne 0x272e7c <pcre_dfa_exec+0x4914>
 *   @0x272e70 ldr r2, [r6, #0x1c]
 *   @0x272e74 cmp r2, #2
 *   @0x272e78 beq 0x2766f4 <pcre_dfa_exec+0x818c>
 *   @0x272e7c mov r2, r4
 *   @0x272e80 add r4, r4, #1
 *   @0x272e84 rsb r3, r5, r4
 *   @0x272e88 add r10, r10, #1
 *   @0x272e8c cmp r8, r3
 *   @0x272e90 blt 0x277334 <pcre_dfa_exec+0x8dcc>
 *   @0x272e94 ldr r2, [r6, #0x78]
 *   @0x272e98 cmp r2, r10
 *   @0x272e9c bls 0x277318 <pcre_dfa_exec+0x8db0>
 *   @0x272ea0 ldr r1, [r6, #0x18]
 *   @0x272ea4 cmp r1, #0
 *   @0x272ea8 bne 0x272e28 <pcre_dfa_exec+0x48c0>
 *   @0x272eac ldr r3, [r6, #0x1c]
 *   @0x272eb0 rsb r2, r3, r2
 *   @0x272eb4 cmp r10, r2
 *   @0x272eb8 bhi 0x272ecc <pcre_dfa_exec+0x4964>
 *   @0x272ebc ldrb r0, [r4, #-0x1]
 *   @0x272ec0 ldrb r2, [r6, #0x34]
 *   @0x272ec4 cmp r0, r2
 *   @0x272ec8 beq 0x275964 <pcre_dfa_exec+0x73fc>
 *   @0x272ecc mov r0, r1
 *   @0x272ed0 b 0x272e44 <pcre_dfa_exec+0x48dc>
 *   @0x272ed4 ldr r9, [r6, #0x78]
 *   @0x272ed8 mov r3, r10
 *   @0x272edc mov r2, #1
 *   @0x272ee0 b 0x272f08 <pcre_dfa_exec+0x49a0>
 *   @0x272ee4 ldrb r1, [r3]
 *   @0x272ee8 add r3, r3, #1
 *   @0x272eec ldr r0, [r6, #0x40]
 *   @0x272ef0 mov r10, r3
 *   @0x272ef4 ldrb r1, [r0, r1]
 *   @0x272ef8 tst r1, #16
 *   @0x272efc beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272f00 cmp r2, r8
 *   @0x272f04 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272f08 cmp r9, r3
 *   @0x272f0c add r2, r2, #1
 *   @0x272f10 bhi 0x272ee4 <pcre_dfa_exec+0x497c>
 *   @0x272f14 b 0x271dc8 <pcre_dfa_exec+0x3860>
 *   @0x272f18 ldr r9, [r6, #0x78]
 *   @0x272f1c mov r3, r10
 *   @0x272f20 mov r2, #1
 *   @0x272f24 b 0x272f4c <pcre_dfa_exec+0x49e4>
 *   @0x272f28 ldrb r1, [r3]
 *   @0x272f2c add r3, r3, #1
 *   @0x272f30 ldr r0, [r6, #0x40]
 *   @0x272f34 mov r10, r3
 *   @0x272f38 ldrb r1, [r0, r1]
 *   @0x272f3c tst r1, #16
 *   @0x272f40 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272f44 cmp r2, r8
 *   @0x272f48 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272f4c cmp r9, r3
 *   @0x272f50 add r2, r2, #1
 *   @0x272f54 bhi 0x272f28 <pcre_dfa_exec+0x49c0>
 *   @0x272f58 b 0x271dc8 <pcre_dfa_exec+0x3860>
 *   @0x272f5c ldr r9, [r6, #0x78]
 *   @0x272f60 mov r3, r10
 *   @0x272f64 mov r2, #1
 *   @0x272f68 b 0x272f90 <pcre_dfa_exec+0x4a28>
 *   @0x272f6c ldrb r1, [r3]
 *   @0x272f70 add r3, r3, #1
 *   @0x272f74 ldr r0, [r6, #0x40]
 *   @0x272f78 mov r10, r3
 *   @0x272f7c ldrb r1, [r0, r1]
 *   @0x272f80 tst r1, #1
 *   @0x272f84 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272f88 cmp r2, r8
 *   @0x272f8c bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272f90 cmp r9, r3
 *   @0x272f94 add r2, r2, #1
 *   @0x272f98 bhi 0x272f6c <pcre_dfa_exec+0x4a04>
 *   @0x272f9c b 0x271dc8 <pcre_dfa_exec+0x3860>
 *   @0x272fa0 ldr r9, [r6, #0x78]
 *   @0x272fa4 mov r3, r10
 *   @0x272fa8 mov r2, #1
 *   @0x272fac b 0x272fd4 <pcre_dfa_exec+0x4a6c>
 *   @0x272fb0 ldrb r1, [r3]
 *   @0x272fb4 add r3, r3, #1
 *   @0x272fb8 ldr r0, [r6, #0x40]
 *   @0x272fbc mov r10, r3
 *   @0x272fc0 ldrb r1, [r0, r1]
 *   @0x272fc4 tst r1, #1
 *   @0x272fc8 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x272fcc cmp r2, r8
 *   @0x272fd0 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x272fd4 cmp r9, r3
 *   @0x272fd8 add r2, r2, #1
 *   @0x272fdc bhi 0x272fb0 <pcre_dfa_exec+0x4a48>
 *   @0x272fe0 b 0x271f98 <pcre_dfa_exec+0x3a30>
 *   @0x272fe4 ldr r9, [r6, #0x78]
 *   @0x272fe8 mov r3, r10
 *   @0x272fec mov r2, #1
 *   @0x272ff0 b 0x273018 <pcre_dfa_exec+0x4ab0>
 *   @0x272ff4 ldrb r1, [r3]
 *   @0x272ff8 add r3, r3, #1
 *   @0x272ffc ldr r0, [r6, #0x40]
 *   @0x273000 mov r10, r3
 *   @0x273004 ldrb r1, [r0, r1]
 *   @0x273008 tst r1, #4
 *   @0x27300c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273010 cmp r2, r8
 *   @0x273014 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x273018 cmp r3, r9
 *   @0x27301c add r2, r2, #1
 *   @0x273020 blo 0x272ff4 <pcre_dfa_exec+0x4a8c>
 *   @0x273024 b 0x271dc8 <pcre_dfa_exec+0x3860>
 *   @0x273028 ldr r9, [r6, #0x78]
 *   @0x27302c mov r3, r10
 *   @0x273030 mov r2, #1
 *   @0x273034 b 0x27305c <pcre_dfa_exec+0x4af4>
 *   @0x273038 ldrb r1, [r3]
 *   @0x27303c add r3, r3, #1
 *   @0x273040 ldr r0, [r6, #0x40]
 *   @0x273044 mov r10, r3
 *   @0x273048 ldrb r1, [r0, r1]
 *   @0x27304c tst r1, #4
 *   @0x273050 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273054 cmp r2, r8
 *   @0x273058 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x27305c cmp r9, r3
 *   @0x273060 add r2, r2, #1
 *   @0x273064 bhi 0x273038 <pcre_dfa_exec+0x4ad0>
 *   @0x273068 b 0x271f98 <pcre_dfa_exec+0x3a30>
 *   @0x27306c ldr r9, [r6, #0x78]
 *   @0x273070 mov r3, #1
 *   @0x273074 b 0x27309c <pcre_dfa_exec+0x4b34>
 *   @0x273078 ldrb r2, [r10], #1
 *   @0x27307c cmp r2, #10
 *   @0x273080 blo 0x273094 <pcre_dfa_exec+0x4b2c>
 *   @0x273084 cmp r2, #13
 *   @0x273088 bls 0x276f78 <pcre_dfa_exec+0x8a10>
 *   @0x27308c cmp r2, #133
 *   @0x273090 beq 0x276f78 <pcre_dfa_exec+0x8a10>
 *   @0x273094 cmp r3, r8
 *   @0x273098 bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x27309c cmp r10, r9
 *   @0x2730a0 add r3, r3, #1
 *   @0x2730a4 blo 0x273078 <pcre_dfa_exec+0x4b10>
 *   @0x2730a8 ldr r3, [r6, #0x88]
 *   @0x2730ac cmp r3, #0
 *   @0x2730b0 bne 0x2719d4 <pcre_dfa_exec+0x346c>
 *   @0x2730b4 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2730b8 ldr r9, [r6, #0x78]
 *   @0x2730bc mov r3, #1
 *   @0x2730c0 cmp r9, r10
 *   @0x2730c4 add r3, r3, #1
 *   @0x2730c8 bls 0x2730a8 <pcre_dfa_exec+0x4b40>
 *   @0x2730cc ldrb r2, [r10], #1
 *   @0x2730d0 cmp r2, #32
 *   @0x2730d4 beq 0x273324 <pcre_dfa_exec+0x4dbc>
 *   @0x2730d8 cmp r2, #160
 *   @0x2730dc beq 0x273324 <pcre_dfa_exec+0x4dbc>
 *   @0x2730e0 cmp r2, #9
 *   @0x2730e4 beq 0x273324 <pcre_dfa_exec+0x4dbc>
 *   @0x2730e8 mov r0, #0
 *   @0x2730ec b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2730f0 ldr r9, [r6, #0x78]
 *   @0x2730f4 mov r2, #1
 *   @0x2730f8 b 0x273120 <pcre_dfa_exec+0x4bb8>
 *   @0x2730fc ldrb r3, [r10], #1
 *   @0x273100 cmp r3, #32
 *   @0x273104 beq 0x277010 <pcre_dfa_exec+0x8aa8>
 *   @0x273108 cmp r3, #160
 *   @0x27310c beq 0x277010 <pcre_dfa_exec+0x8aa8>
 *   @0x273110 cmp r3, #9
 *   @0x273114 beq 0x277010 <pcre_dfa_exec+0x8aa8>
 *   @0x273118 cmp r2, r8
 *   @0x27311c bgt 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x273120 cmp r9, r10
 *   @0x273124 add r2, r2, #1
 *   @0x273128 bhi 0x2730fc <pcre_dfa_exec+0x4b94>
 *   @0x27312c b 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273130 ldr r9, [r6, #0x78]
 *   @0x273134 mov r2, #1
 *   @0x273138 cmp r9, r10
 *   @0x27313c bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273140 ldrb r3, [r10]
 *   @0x273144 add r1, r10, #1
 *   @0x273148 cmp r3, #12
 *   @0x27314c bhi 0x274ff0 <pcre_dfa_exec+0x6a88>
 *   @0x273150 cmp r3, #11
 *   @0x273154 bhs 0x275000 <pcre_dfa_exec+0x6a98>
 *   @0x273158 cmp r3, #10
 *   @0x27315c bne 0x275e88 <pcre_dfa_exec+0x7920>
 *   @0x273160 add r2, r2, #1
 *   @0x273164 mov r10, r1
 *   @0x273168 cmp r2, r8
 *   @0x27316c ble 0x273138 <pcre_dfa_exec+0x4bd0>
 *   @0x273170 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x273174 mvn r0, #13
 *   @0x273178 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27317c ldr r3, [r6, #0x3c]
 *   @0x273180 cmp r7, #0
 *   @0x273184 ldrb r5, [r3, r12]
 *   @0x273188 beq 0x276b24 <pcre_dfa_exec+0x85bc>
 *   @0x27318c ldr r9, [r6, #0x78]
 *   @0x273190 cmp r10, r9
 *   @0x273194 bhs 0x273500 <pcre_dfa_exec+0x4f98>
 *   @0x273198 ldrb r3, [r10]
 *   @0x27319c cmp r5, r3
 *   @0x2731a0 cmpne r12, r3
 *   @0x2731a4 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2731a8 add r10, r10, #1
 *   @0x2731ac mov r3, #1
 *   @0x2731b0 b 0x2731d0 <pcre_dfa_exec+0x4c68>
 *   @0x2731b4 cmp r10, r9
 *   @0x2731b8 add r10, r10, #1
 *   @0x2731bc beq 0x273504 <pcre_dfa_exec+0x4f9c>
 *   @0x2731c0 ldrb r2, [r8]
 *   @0x2731c4 cmp r5, r2
 *   @0x2731c8 cmpne r12, r2
 *   @0x2731cc bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2731d0 add r3, r3, #1
 *   @0x2731d4 mov r8, r10
 *   @0x2731d8 cmp r7, r3
 *   @0x2731dc bge 0x2731b4 <pcre_dfa_exec+0x4c4c>
 *   @0x2731e0 ldr r0, [sp, #0x2c]
 *   @0x2731e4 cmp r7, r0
 *   @0x2731e8 beq 0x274850 <pcre_dfa_exec+0x62e8>
 *   @0x2731ec ldr r3, [sp, #0x4c]
 *   @0x2731f0 cmp r3, #0
 *   @0x2731f4 bne 0x2789d0 <pcre_dfa_exec+0xa468>
 *   @0x2731f8 ldr r0, [sp, #0x2c]
 *   @0x2731fc cmp r0, r7
 *   @0x273200 ble 0x277b88 <pcre_dfa_exec+0x9620>
 *   @0x273204 ldr r9, [r6, #0x78]
 *   @0x273208 cmp r9, r8
 *   @0x27320c bls 0x2758dc <pcre_dfa_exec+0x7374>
 *   @0x273210 ldrb r3, [r8]
 *   @0x273214 cmp r12, r3
 *   @0x273218 cmpne r5, r3
 *   @0x27321c bne 0x277b88 <pcre_dfa_exec+0x9620>
 *   @0x273220 rsb r1, r7, r0
 *   @0x273224 add r3, r8, #1
 *   @0x273228 add r1, r8, r1
 *   @0x27322c b 0x27324c <pcre_dfa_exec+0x4ce4>
 *   @0x273230 cmp r3, r9
 *   @0x273234 add r3, r3, #1
 *   @0x273238 beq 0x2758e0 <pcre_dfa_exec+0x7378>
 *   @0x27323c ldrb r2, [r10]
 *   @0x273240 cmp r5, r2
 *   @0x273244 cmpne r12, r2
 *   @0x273248 bne 0x273258 <pcre_dfa_exec+0x4cf0>
 *   @0x27324c cmp r3, r1
 *   @0x273250 mov r10, r3
 *   @0x273254 bne 0x273230 <pcre_dfa_exec+0x4cc8>
 *   @0x273258 ldr r7, [sp, #0x30]
 *   @0x27325c cmp r7, #0
 *   @0x273260 bne 0x274388 <pcre_dfa_exec+0x5e20>
 *   @0x273264 cmp r8, r10
 *   @0x273268 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x27326c ldr r4, [sp, #0x1c]
 *   @0x273270 ldr r5, [sp, #0x18]
 *   @0x273274 ldr r7, [sp, #0x164]
 *   @0x273278 b 0x273284 <pcre_dfa_exec+0x4d1c>
 *   @0x27327c cmp r10, r8
 *   @0x273280 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x273284 ldr r12, [sp, #0x168]
 *   @0x273288 mov r0, r10
 *   @0x27328c str r6, [sp]
 *   @0x273290 mov r1, r11
 *   @0x273294 add r12, r12, #1
 *   @0x273298 str r7, [sp, #0x4]
 *   @0x27329c mov r2, r4
 *   @0x2732a0 str r12, [sp, #0x8]
 *   @0x2732a4 mov r3, r5
 *   @0x2732a8 sub r10, r10, #1
 *   @0x2732ac bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2732b0 cmp r0, #0
 *   @0x2732b4 beq 0x27327c <pcre_dfa_exec+0x4d14>
 *   @0x2732b8 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2732bc mov r10, r4
 *   @0x2732c0 b 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x2732c4 mov r11, r3
 *   @0x2732c8 b 0x26f5ec <pcre_dfa_exec+0x1084>
 *   @0x2732cc ldrb r1, [r11, #0x1]
 *   @0x2732d0 ldrb r3, [r11, #0x2]
 *   @0x2732d4 ldr r2, [r6, #0x7c]
 *   @0x2732d8 orr r3, r3, r1, lsl #8
 *   @0x2732dc add r3, r11, r3
 *   @0x2732e0 cmp r3, r2
 *   @0x2732e4 bls 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x2732e8 ldrb r2, [r11]
 *   @0x2732ec cmp r2, #119
 *   @0x2732f0 beq 0x26fa00 <pcre_dfa_exec+0x1498>
 *   @0x2732f4 ldrb r3, [r3]
 *   @0x2732f8 cmp r3, #119
 *   @0x2732fc bne 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x273300 b 0x26fa00 <pcre_dfa_exec+0x1498>
 *   @0x273304 mov r12, #1
 *   @0x273308 mov r2, r3
 *   @0x27330c str r3, [sp]
 *   @0x273310 add r0, sp, #360
 *   @0x273314 str r3, [sp, #0x4]
 *   @0x273318 str r12, [sp, #0x8]
 *   @0x27331c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x273320 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x273324 cmp r3, r8
 *   @0x273328 ble 0x2730c0 <pcre_dfa_exec+0x4b58>
 *   @0x27332c b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x273330 mov r5, r7
 *   @0x273334 cmp r8, #0
 *   @0x273338 beq 0x270ec4 <pcre_dfa_exec+0x295c>
 *   @0x27333c ldr r9, [r6, #0x78]
 *   @0x273340 cmp r10, r9
 *   @0x273344 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273348 mov r2, #1
 *   @0x27334c b 0x273384 <pcre_dfa_exec+0x4e1c>
 *   @0x273350 ldrb r0, [r10, #0x1]
 *   @0x273354 and r3, r3, #31
 *   @0x273358 add r10, r10, #2
 *   @0x27335c and r0, r0, #63
 *   @0x273360 orr r3, r0, r3, lsl #6
 *   @0x273364 cmp r7, r3
 *   @0x273368 cmpne r5, r3
 *   @0x27336c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273370 add r2, r2, #1
 *   @0x273374 cmp r8, r2
 *   @0x273378 blt 0x270ec4 <pcre_dfa_exec+0x295c>
 *   @0x27337c cmp r10, r9
 *   @0x273380 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273384 ldrb r3, [r10]
 *   @0x273388 cmp r3, #191
 *   @0x27338c addls r10, r10, #1
 *   @0x273390 bls 0x273364 <pcre_dfa_exec+0x4dfc>
 *   @0x273394 tst r3, #32
 *   @0x273398 beq 0x273350 <pcre_dfa_exec+0x4de8>
 *   @0x27339c tst r3, #16
 *   @0x2733a0 bne 0x2733cc <pcre_dfa_exec+0x4e64>
 *   @0x2733a4 ldrb r12, [r10, #0x2]
 *   @0x2733a8 lsl r3, r3, #12
 *   @0x2733ac ldrb r0, [r10, #0x1]
 *   @0x2733b0 add r10, r10, #3
 *   @0x2733b4 uxth r3, r3
 *   @0x2733b8 and r12, r12, #63
 *   @0x2733bc and r0, r0, #63
 *   @0x2733c0 orr r3, r3, r12
 *   @0x2733c4 orr r3, r3, r0, lsl #6
 *   @0x2733c8 b 0x273364 <pcre_dfa_exec+0x4dfc>
 *   @0x2733cc tst r3, #8
 *   @0x2733d0 bne 0x273d68 <pcre_dfa_exec+0x5800>
 *   @0x2733d4 ldrb r4, [r10, #0x3]
 *   @0x2733d8 and r3, r3, #7
 *   @0x2733dc ldrb r12, [r10, #0x1]
 *   @0x2733e0 add r10, r10, #4
 *   @0x2733e4 ldrb r0, [r10, #-0x2]
 *   @0x2733e8 and r4, r4, #63
 *   @0x2733ec and r12, r12, #63
 *   @0x2733f0 orr r3, r4, r3, lsl #18
 *   @0x2733f4 and r0, r0, #63
 *   @0x2733f8 orr r3, r3, r12, lsl #12
 *   @0x2733fc orr r3, r3, r0, lsl #6
 *   @0x273400 b 0x273364 <pcre_dfa_exec+0x4dfc>
 *   @0x273404 cmp r8, #0
 *   @0x273408 beq 0x272c7c <pcre_dfa_exec+0x4714>
 *   @0x27340c ldr r9, [r6, #0x78]
 *   @0x273410 cmp r10, r9
 *   @0x273414 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273418 mov r2, #1
 *   @0x27341c b 0x273450 <pcre_dfa_exec+0x4ee8>
 *   @0x273420 ldrb r0, [r10, #0x1]
 *   @0x273424 and r3, r3, #31
 *   @0x273428 add r10, r10, #2
 *   @0x27342c and r0, r0, #63
 *   @0x273430 orr r3, r0, r3, lsl #6
 *   @0x273434 cmp r7, r3
 *   @0x273438 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27343c add r2, r2, #1
 *   @0x273440 cmp r8, r2
 *   @0x273444 blt 0x272c7c <pcre_dfa_exec+0x4714>
 *   @0x273448 cmp r10, r9
 *   @0x27344c bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x273450 ldrb r3, [r10]
 *   @0x273454 cmp r3, #191
 *   @0x273458 addls r10, r10, #1
 *   @0x27345c bls 0x273434 <pcre_dfa_exec+0x4ecc>
 *   @0x273460 tst r3, #32
 *   @0x273464 beq 0x273420 <pcre_dfa_exec+0x4eb8>
 *   @0x273468 tst r3, #16
 *   @0x27346c bne 0x273498 <pcre_dfa_exec+0x4f30>
 *   @0x273470 ldrb r12, [r10, #0x2]
 *   @0x273474 lsl r3, r3, #12
 *   @0x273478 ldrb r0, [r10, #0x1]
 *   @0x27347c add r10, r10, #3
 *   @0x273480 uxth r3, r3
 *   @0x273484 and r12, r12, #63
 *   @0x273488 and r0, r0, #63
 *   @0x27348c orr r3, r3, r12
 *   @0x273490 orr r3, r3, r0, lsl #6
 *   @0x273494 b 0x273434 <pcre_dfa_exec+0x4ecc>
 *   @0x273498 tst r3, #8
 *   @0x27349c bne 0x273d24 <pcre_dfa_exec+0x57bc>
 *   @0x2734a0 ldrb r4, [r10, #0x3]
 *   @0x2734a4 and r3, r3, #7
 *   @0x2734a8 ldrb r12, [r10, #0x1]
 *   @0x2734ac add r10, r10, #4
 *   @0x2734b0 ldrb r0, [r10, #-0x2]
 *   @0x2734b4 and r4, r4, #63
 *   @0x2734b8 and r12, r12, #63
 *   @0x2734bc orr r3, r4, r3, lsl #18
 *   @0x2734c0 and r0, r0, #63
 *   @0x2734c4 orr r3, r3, r12, lsl #12
 *   @0x2734c8 orr r3, r3, r0, lsl #6
 *   @0x2734cc b 0x273434 <pcre_dfa_exec+0x4ecc>
 *   @0x2734d0 tst r7, #16
 *   @0x2734d4 bne 0x273df4 <pcre_dfa_exec+0x588c>
 *   @0x2734d8 lsl r2, r7, #12
 *   @0x2734dc ldrb r0, [r3, #0x1]
 *   @0x2734e0 ldrb r12, [r3, #0x2]
 *   @0x2734e4 add r11, r3, #3
 *   @0x2734e8 uxth r2, r2
 *   @0x2734ec and r7, r0, #63
 *   @0x2734f0 and r3, r12, #63
 *   @0x2734f4 orr r3, r2, r3
 *   @0x2734f8 orr r7, r3, r7, lsl #6
 *   @0x2734fc b 0x270e2c <pcre_dfa_exec+0x28c4>
 *   @0x273500 mov r8, r10
 *   @0x273504 ldr r3, [r6, #0x88]
 *   @0x273508 cmp r3, #0
 *   @0x27350c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273510 ldr r2, [r6, #0x84]
 *   @0x273514 cmp r2, r8
 *   @0x273518 blo 0x271820 <pcre_dfa_exec+0x32b8>
 *   @0x27351c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273520 add r8, r8, #1
 *   @0x273524 cmp r8, r7
 *   @0x273528 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27352c cmp r9, r1
 *   @0x273530 bhi 0x2725c8 <pcre_dfa_exec+0x4060>
 *   @0x273534 b 0x272654 <pcre_dfa_exec+0x40ec>
 *   @0x273538 tst r0, #8
 *   @0x27353c bne 0x2741a0 <pcre_dfa_exec+0x5c38>
 *   @0x273540 ldrb r2, [r10, #0x3]
 *   @0x273544 and lr, r0, #7
 *   @0x273548 ldrb r1, [r10, #0x1]
 *   @0x27354c add r10, r10, #4
 *   @0x273550 ldrb r0, [r10, #-0x2]
 *   @0x273554 and r2, r2, #63
 *   @0x273558 and r1, r1, #63
 *   @0x27355c orr r2, r2, lr, lsl #18
 *   @0x273560 and r0, r0, #63
 *   @0x273564 orr r2, r2, r1, lsl #12
 *   @0x273568 orr r0, r2, r0, lsl #6
 *   @0x27356c b 0x270220 <pcre_dfa_exec+0x1cb8>
 *   @0x273570 cmp r3, #15
 *   @0x273574 addls pc, pc, r3, lsl #2
 *   @0x273578 b 0x273ccc <pcre_dfa_exec+0x5764>
 *   @0x27357c b 0x273938 <pcre_dfa_exec+0x53d0>
 *   @0x273580 b 0x2738ac <pcre_dfa_exec+0x5344>
 *   @0x273584 b 0x2739b4 <pcre_dfa_exec+0x544c>
 *   @0x273588 b 0x27367c <pcre_dfa_exec+0x5114>
 *   @0x27358c b 0x273c40 <pcre_dfa_exec+0x56d8>
 *   @0x273590 b 0x273b30 <pcre_dfa_exec+0x55c8>
 *   @0x273594 b 0x2737b8 <pcre_dfa_exec+0x5250>
 *   @0x273598 b 0x2736e0 <pcre_dfa_exec+0x5178>
 *   @0x27359c b 0x2736e0 <pcre_dfa_exec+0x5178>
 *   @0x2735a0 b 0x273ccc <pcre_dfa_exec+0x5764>
 *   @0x2735a4 b 0x273ccc <pcre_dfa_exec+0x5764>
 *   @0x2735a8 b 0x273a9c <pcre_dfa_exec+0x5534>
 *   @0x2735ac b 0x273a40 <pcre_dfa_exec+0x54d8>
 *   @0x2735b0 b 0x273bbc <pcre_dfa_exec+0x5654>
 *   @0x2735b4 b 0x27361c <pcre_dfa_exec+0x50b4>
 *   @0x2735b8 b 0x2735bc <pcre_dfa_exec+0x5054>
 *   @0x2735bc cmp r7, r8
 *   @0x2735c0 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2735c4 ldr r9, [r6, #0x78]
 *   @0x2735c8 cmp r10, r9
 *   @0x2735cc addlo r2, r7, r10
 *   @0x2735d0 movlo r3, r10
 *   @0x2735d4 rsblo r8, r8, r2
 *   @0x2735d8 blo 0x2735e8 <pcre_dfa_exec+0x5080>
 *   @0x2735dc b 0x278fac <pcre_dfa_exec+0xaa44>
 *   @0x2735e0 cmp r3, r9
 *   @0x2735e4 beq 0x273b90 <pcre_dfa_exec+0x5628>
 *   @0x2735e8 mov r4, r3
 *   @0x2735ec add r3, r3, #1
 *   @0x2735f0 ldrb r2, [r4]
 *   @0x2735f4 cmp r2, #10
 *   @0x2735f8 blo 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2735fc cmp r2, #13
 *   @0x273600 bls 0x27360c <pcre_dfa_exec+0x50a4>
 *   @0x273604 cmp r2, #133
 *   @0x273608 bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27360c cmp r3, r8
 *   @0x273610 mov r4, r3
 *   @0x273614 bne 0x2735e0 <pcre_dfa_exec+0x5078>
 *   @0x273618 b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27361c cmp r7, r8
 *   @0x273620 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273624 ldr r9, [r6, #0x78]
 *   @0x273628 cmp r10, r9
 *   @0x27362c addlo r2, r7, r10
 *   @0x273630 movlo r3, r10
 *   @0x273634 rsblo r8, r8, r2
 *   @0x273638 blo 0x273648 <pcre_dfa_exec+0x50e0>
 *   @0x27363c b 0x278f40 <pcre_dfa_exec+0xa9d8>
 *   @0x273640 cmp r3, r9
 *   @0x273644 beq 0x273ca0 <pcre_dfa_exec+0x5738>
 *   @0x273648 mov r4, r3
 *   @0x27364c add r3, r3, #1
 *   @0x273650 ldrb r2, [r4]
 *   @0x273654 cmp r2, #10
 *   @0x273658 blo 0x27366c <pcre_dfa_exec+0x5104>
 *   @0x27365c cmp r2, #13
 *   @0x273660 bls 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273664 cmp r2, #133
 *   @0x273668 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27366c cmp r3, r8
 *   @0x273670 mov r4, r3
 *   @0x273674 bne 0x273640 <pcre_dfa_exec+0x50d8>
 *   @0x273678 b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27367c cmp r7, r8
 *   @0x273680 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273684 ldr r9, [r6, #0x78]
 *   @0x273688 cmp r10, r9
 *   @0x27368c bhs 0x279130 <pcre_dfa_exec+0xabc8>
 *   @0x273690 ldr r1, [r6, #0x40]
 *   @0x273694 ldrb r3, [r10]
 *   @0x273698 ldrb r3, [r1, r3]
 *   @0x27369c tst r3, #1
 *   @0x2736a0 beq 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2736a4 add r2, r10, r7
 *   @0x2736a8 add r3, r10, #1
 *   @0x2736ac rsb r8, r8, r2
 *   @0x2736b0 b 0x2736d0 <pcre_dfa_exec+0x5168>
 *   @0x2736b4 cmp r3, r9
 *   @0x2736b8 add r3, r3, #1
 *   @0x2736bc beq 0x273c14 <pcre_dfa_exec+0x56ac>
 *   @0x2736c0 ldrb r2, [r4]
 *   @0x2736c4 ldrb r2, [r1, r2]
 *   @0x2736c8 tst r2, #1
 *   @0x2736cc beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2736d0 cmp r3, r8
 *   @0x2736d4 mov r4, r3
 *   @0x2736d8 bne 0x2736b4 <pcre_dfa_exec+0x514c>
 *   @0x2736dc b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2736e0 ldr r4, [r6, #0x78]
 *   @0x2736e4 rsb r8, r8, r7
 *   @0x2736e8 rsb r3, r10, r4
 *   @0x2736ec cmp r8, r3
 *   @0x2736f0 bls 0x2773c0 <pcre_dfa_exec+0x8e58>
 *   @0x2736f4 ldr r2, [r6, #0x88]
 *   @0x2736f8 cmp r2, #0
 *   @0x2736fc beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273700 ldr r3, [r6, #0x84]
 *   @0x273704 cmp r4, r3
 *   @0x273708 bls 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27370c cmp r2, #1
 *   @0x273710 mov r0, #1
 *   @0x273714 str r0, [r6, #0x64]
 *   @0x273718 bgt 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x27371c ldr r7, [sp, #0x30]
 *   @0x273720 cmp r7, #0
 *   @0x273724 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x273728 cmp r10, r4
 *   @0x27372c beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x273730 ldr r7, [sp, #0x1c]
 *   @0x273734 ldr r8, [sp, #0x18]
 *   @0x273738 ldr r9, [sp, #0x164]
 *   @0x27373c b 0x27374c <pcre_dfa_exec+0x51e4>
 *   @0x273740 cmp r10, r12
 *   @0x273744 mov r4, r12
 *   @0x273748 beq 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x27374c ldr r3, [sp, #0x168]
 *   @0x273750 mov r0, r4
 *   @0x273754 str r6, [sp]
 *   @0x273758 mov r1, r11
 *   @0x27375c add r3, r3, #1
 *   @0x273760 str r9, [sp, #0x4]
 *   @0x273764 str r3, [sp, #0x8]
 *   @0x273768 mov r2, r7
 *   @0x27376c mov r3, r8
 *   @0x273770 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x273774 sub r12, r4, #1
 *   @0x273778 cmp r0, #0
 *   @0x27377c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x273780 cmp r10, r12
 *   @0x273784 movhs r3, #0
 *   @0x273788 movlo r3, #1
 *   @0x27378c cmp r5, #17
 *   @0x273790 movne r3, #0
 *   @0x273794 cmp r3, #0
 *   @0x273798 beq 0x273740 <pcre_dfa_exec+0x51d8>
 *   @0x27379c ldrb r3, [r4, #-0x1]
 *   @0x2737a0 cmp r3, #10
 *   @0x2737a4 bne 0x273740 <pcre_dfa_exec+0x51d8>
 *   @0x2737a8 ldrb r3, [r4, #-0x2]
 *   @0x2737ac cmp r3, #13
 *   @0x2737b0 subeq r12, r4, #2
 *   @0x2737b4 b 0x273740 <pcre_dfa_exec+0x51d8>
 *   @0x2737b8 cmp r7, r8
 *   @0x2737bc ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2737c0 ldr r9, [r6, #0x78]
 *   @0x2737c4 cmp r10, r9
 *   @0x2737c8 bhs 0x279308 <pcre_dfa_exec+0xada0>
 *   @0x2737cc add r3, r10, r7
 *   @0x2737d0 add r0, r6, #28
 *   @0x2737d4 rsb r12, r8, r3
 *   @0x2737d8 mov r2, r9
 *   @0x2737dc add r7, r10, #1
 *   @0x2737e0 str r0, [sp, #0x2c]
 *   @0x2737e4 mov r8, r10
 *   @0x2737e8 mov r9, r12
 *   @0x2737ec b 0x273858 <pcre_dfa_exec+0x52f0>
 *   @0x2737f0 cmp r2, r8
 *   @0x2737f4 movls r0, #0
 *   @0x2737f8 bhi 0x2757a0 <pcre_dfa_exec+0x7238>
 *   @0x2737fc mov r1, r0
 *   @0x273800 cmp r1, #0
 *   @0x273804 bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273808 ldr r3, [r6, #0x88]
 *   @0x27380c cmp r3, #0
 *   @0x273810 beq 0x273838 <pcre_dfa_exec+0x52d0>
 *   @0x273814 ldr r2, [r6, #0x78]
 *   @0x273818 cmp r7, r2
 *   @0x27381c blo 0x273838 <pcre_dfa_exec+0x52d0>
 *   @0x273820 ldr r2, [r6, #0x18]
 *   @0x273824 cmp r2, #0
 *   @0x273828 bne 0x273838 <pcre_dfa_exec+0x52d0>
 *   @0x27382c ldr r2, [r6, #0x1c]
 *   @0x273830 cmp r2, #2
 *   @0x273834 beq 0x27739c <pcre_dfa_exec+0x8e34>
 *   @0x273838 cmp r7, r9
 *   @0x27383c mov r4, r7
 *   @0x273840 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273844 ldr r2, [r6, #0x78]
 *   @0x273848 add r7, r7, #1
 *   @0x27384c add r8, r8, #1
 *   @0x273850 cmp r4, r2
 *   @0x273854 bhs 0x277828 <pcre_dfa_exec+0x92c0>
 *   @0x273858 ldr r1, [r6, #0x18]
 *   @0x27385c mov r4, r8
 *   @0x273860 cmp r1, #0
 *   @0x273864 bne 0x2737f0 <pcre_dfa_exec+0x5288>
 *   @0x273868 ldr r3, [r6, #0x1c]
 *   @0x27386c rsb r2, r3, r2
 *   @0x273870 cmp r8, r2
 *   @0x273874 bhi 0x273800 <pcre_dfa_exec+0x5298>
 *   @0x273878 ldrb r0, [r7, #-0x1]
 *   @0x27387c ldrb r2, [r6, #0x34]
 *   @0x273880 cmp r0, r2
 *   @0x273884 bne 0x273800 <pcre_dfa_exec+0x5298>
 *   @0x273888 cmp r3, #1
 *   @0x27388c moveq r1, r3
 *   @0x273890 beq 0x273800 <pcre_dfa_exec+0x5298>
 *   @0x273894 ldrb r1, [r8, #0x1]
 *   @0x273898 ldrb r3, [r6, #0x35]
 *   @0x27389c subs r3, r1, r3
 *   @0x2738a0 rsbs r1, r3, #0
 *   @0x2738a4 adcs r1, r1, r3
 *   @0x2738a8 b 0x273800 <pcre_dfa_exec+0x5298>
 *   @0x2738ac cmp r7, r8
 *   @0x2738b0 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2738b4 ldr r9, [r6, #0x78]
 *   @0x2738b8 cmp r10, r9
 *   @0x2738bc bhs 0x278fdc <pcre_dfa_exec+0xaa74>
 *   @0x2738c0 ldr r1, [r6, #0x40]
 *   @0x2738c4 ldrb r3, [r10]
 *   @0x2738c8 ldrb r3, [r1, r3]
 *   @0x2738cc tst r3, #4
 *   @0x2738d0 beq 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2738d4 add r2, r10, r7
 *   @0x2738d8 add r3, r10, #1
 *   @0x2738dc rsb r8, r8, r2
 *   @0x2738e0 b 0x2738f4 <pcre_dfa_exec+0x538c>
 *   @0x2738e4 ldrb r2, [r4]
 *   @0x2738e8 ldrb r2, [r1, r2]
 *   @0x2738ec tst r2, #4
 *   @0x2738f0 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2738f4 cmp r3, r8
 *   @0x2738f8 mov r4, r3
 *   @0x2738fc beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273900 cmp r3, r9
 *   @0x273904 add r3, r3, #1
 *   @0x273908 bne 0x2738e4 <pcre_dfa_exec+0x537c>
 *   @0x27390c ldr r2, [r6, #0x88]
 *   @0x273910 cmp r2, #0
 *   @0x273914 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273918 ldr r3, [r6, #0x84]
 *   @0x27391c cmp r3, r4
 *   @0x273920 bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273924 cmp r2, #1
 *   @0x273928 mov r1, #1
 *   @0x27392c str r1, [r6, #0x64]
 *   @0x273930 ble 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273934 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x273938 cmp r7, r8
 *   @0x27393c ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273940 ldr r9, [r6, #0x78]
 *   @0x273944 cmp r10, r9
 *   @0x273948 bhs 0x278fcc <pcre_dfa_exec+0xaa64>
 *   @0x27394c ldr r1, [r6, #0x40]
 *   @0x273950 ldrb r3, [r10]
 *   @0x273954 ldrb r3, [r1, r3]
 *   @0x273958 tst r3, #4
 *   @0x27395c bne 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273960 add r2, r10, r7
 *   @0x273964 add r3, r10, #1
 *   @0x273968 rsb r8, r8, r2
 *   @0x27396c b 0x273980 <pcre_dfa_exec+0x5418>
 *   @0x273970 ldrb r2, [r4]
 *   @0x273974 ldrb r2, [r1, r2]
 *   @0x273978 tst r2, #4
 *   @0x27397c bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273980 cmp r3, r8
 *   @0x273984 mov r4, r3
 *   @0x273988 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x27398c cmp r3, r9
 *   @0x273990 add r3, r3, #1
 *   @0x273994 bne 0x273970 <pcre_dfa_exec+0x5408>
 *   @0x273998 ldr r2, [r6, #0x88]
 *   @0x27399c cmp r2, #0
 *   @0x2739a0 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2739a4 ldr r3, [r6, #0x84]
 *   @0x2739a8 cmp r3, r4
 *   @0x2739ac bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2739b0 b 0x27370c <pcre_dfa_exec+0x51a4>
 *   @0x2739b4 cmp r7, r8
 *   @0x2739b8 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2739bc ldr r9, [r6, #0x78]
 *   @0x2739c0 cmp r10, r9
 *   @0x2739c4 bhs 0x278fd4 <pcre_dfa_exec+0xaa6c>
 *   @0x2739c8 ldr r1, [r6, #0x40]
 *   @0x2739cc ldrb r3, [r10]
 *   @0x2739d0 ldrb r3, [r1, r3]
 *   @0x2739d4 tst r3, #1
 *   @0x2739d8 bne 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x2739dc add r2, r10, r7
 *   @0x2739e0 add r3, r10, #1
 *   @0x2739e4 rsb r8, r8, r2
 *   @0x2739e8 b 0x2739fc <pcre_dfa_exec+0x5494>
 *   @0x2739ec ldrb r2, [r4]
 *   @0x2739f0 ldrb r2, [r1, r2]
 *   @0x2739f4 tst r2, #1
 *   @0x2739f8 bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2739fc cmp r3, r8
 *   @0x273a00 mov r4, r3
 *   @0x273a04 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a08 cmp r3, r9
 *   @0x273a0c add r3, r3, #1
 *   @0x273a10 bne 0x2739ec <pcre_dfa_exec+0x5484>
 *   @0x273a14 ldr r2, [r6, #0x88]
 *   @0x273a18 cmp r2, #0
 *   @0x273a1c beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a20 ldr r3, [r6, #0x84]
 *   @0x273a24 cmp r3, r4
 *   @0x273a28 bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a2c cmp r2, #1
 *   @0x273a30 mov r2, #1
 *   @0x273a34 str r2, [r6, #0x64]
 *   @0x273a38 ble 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a3c b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x273a40 cmp r7, r8
 *   @0x273a44 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273a48 ldr r9, [r6, #0x78]
 *   @0x273a4c cmp r10, r9
 *   @0x273a50 addlo r2, r10, r7
 *   @0x273a54 movlo r3, r10
 *   @0x273a58 rsblo r8, r8, r2
 *   @0x273a5c bhs 0x278fd4 <pcre_dfa_exec+0xaa6c>
 *   @0x273a60 mov r4, r3
 *   @0x273a64 add r3, r3, #1
 *   @0x273a68 ldrb r2, [r4]
 *   @0x273a6c cmp r2, #32
 *   @0x273a70 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a74 cmp r2, #160
 *   @0x273a78 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a7c cmp r2, #9
 *   @0x273a80 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a84 cmp r3, r8
 *   @0x273a88 mov r4, r3
 *   @0x273a8c beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273a90 cmp r3, r9
 *   @0x273a94 bne 0x273a60 <pcre_dfa_exec+0x54f8>
 *   @0x273a98 b 0x273a14 <pcre_dfa_exec+0x54ac>
 *   @0x273a9c cmp r7, r8
 *   @0x273aa0 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273aa4 ldr r9, [r6, #0x78]
 *   @0x273aa8 cmp r10, r9
 *   @0x273aac movlo r4, r10
 *   @0x273ab0 blo 0x273af4 <pcre_dfa_exec+0x558c>
 *   @0x273ab4 b 0x278fdc <pcre_dfa_exec+0xaa74>
 *   @0x273ab8 cmp r3, #10
 *   @0x273abc beq 0x273adc <pcre_dfa_exec+0x5574>
 *   @0x273ac0 ldr r2, [r6, #0x68]
 *   @0x273ac4 cmp r2, #0
 *   @0x273ac8 bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273acc sub r2, r3, #11
 *   @0x273ad0 cmp r3, #133
 *   @0x273ad4 cmpne r2, #1
 *   @0x273ad8 bhi 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273adc add r4, r4, #1
 *   @0x273ae0 add r8, r8, #1
 *   @0x273ae4 cmp r8, r7
 *   @0x273ae8 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273aec cmp r4, r9
 *   @0x273af0 bhs 0x27390c <pcre_dfa_exec+0x53a4>
 *   @0x273af4 ldrb r3, [r4]
 *   @0x273af8 cmp r3, #13
 *   @0x273afc bne 0x273ab8 <pcre_dfa_exec+0x5550>
 *   @0x273b00 add r3, r4, #1
 *   @0x273b04 cmp r9, r3
 *   @0x273b08 bls 0x278b68 <pcre_dfa_exec+0xa600>
 *   @0x273b0c ldrb r2, [r4, #0x1]
 *   @0x273b10 cmp r2, #10
 *   @0x273b14 addeq r4, r4, #2
 *   @0x273b18 beq 0x273ae0 <pcre_dfa_exec+0x5578>
 *   @0x273b1c add r8, r8, #1
 *   @0x273b20 cmp r8, r7
 *   @0x273b24 beq 0x278b68 <pcre_dfa_exec+0xa600>
 *   @0x273b28 mov r4, r3
 *   @0x273b2c b 0x273af4 <pcre_dfa_exec+0x558c>
 *   @0x273b30 cmp r7, r8
 *   @0x273b34 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273b38 ldr r9, [r6, #0x78]
 *   @0x273b3c cmp r10, r9
 *   @0x273b40 bhs 0x278fac <pcre_dfa_exec+0xaa44>
 *   @0x273b44 ldr r1, [r6, #0x40]
 *   @0x273b48 ldrb r3, [r10]
 *   @0x273b4c ldrb r3, [r1, r3]
 *   @0x273b50 tst r3, #16
 *   @0x273b54 beq 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273b58 add r2, r10, r7
 *   @0x273b5c add r3, r10, #1
 *   @0x273b60 rsb r8, r8, r2
 *   @0x273b64 b 0x273b78 <pcre_dfa_exec+0x5610>
 *   @0x273b68 ldrb r2, [r4]
 *   @0x273b6c ldrb r2, [r1, r2]
 *   @0x273b70 tst r2, #16
 *   @0x273b74 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273b78 cmp r3, r8
 *   @0x273b7c mov r4, r3
 *   @0x273b80 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273b84 cmp r3, r9
 *   @0x273b88 add r3, r3, #1
 *   @0x273b8c bne 0x273b68 <pcre_dfa_exec+0x5600>
 *   @0x273b90 ldr r2, [r6, #0x88]
 *   @0x273b94 cmp r2, #0
 *   @0x273b98 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273b9c ldr r3, [r6, #0x84]
 *   @0x273ba0 cmp r3, r4
 *   @0x273ba4 bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273ba8 cmp r2, #1
 *   @0x273bac mov r12, #1
 *   @0x273bb0 str r12, [r6, #0x64]
 *   @0x273bb4 ble 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273bb8 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x273bbc cmp r7, r8
 *   @0x273bc0 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273bc4 ldr r9, [r6, #0x78]
 *   @0x273bc8 cmp r10, r9
 *   @0x273bcc addlo r2, r10, r7
 *   @0x273bd0 movlo r3, r10
 *   @0x273bd4 rsblo r8, r8, r2
 *   @0x273bd8 bhs 0x279130 <pcre_dfa_exec+0xabc8>
 *   @0x273bdc mov r4, r3
 *   @0x273be0 add r3, r3, #1
 *   @0x273be4 ldrb r2, [r4]
 *   @0x273be8 cmp r2, #32
 *   @0x273bec beq 0x273c00 <pcre_dfa_exec+0x5698>
 *   @0x273bf0 cmp r2, #160
 *   @0x273bf4 beq 0x273c00 <pcre_dfa_exec+0x5698>
 *   @0x273bf8 cmp r2, #9
 *   @0x273bfc bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c00 cmp r3, r8
 *   @0x273c04 mov r4, r3
 *   @0x273c08 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c0c cmp r3, r9
 *   @0x273c10 bne 0x273bdc <pcre_dfa_exec+0x5674>
 *   @0x273c14 ldr r2, [r6, #0x88]
 *   @0x273c18 cmp r2, #0
 *   @0x273c1c beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c20 ldr r3, [r6, #0x84]
 *   @0x273c24 cmp r3, r4
 *   @0x273c28 bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c2c cmp r2, #1
 *   @0x273c30 mov r3, #1
 *   @0x273c34 str r3, [r6, #0x64]
 *   @0x273c38 ble 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c3c b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x273c40 cmp r7, r8
 *   @0x273c44 ble 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273c48 ldr r9, [r6, #0x78]
 *   @0x273c4c cmp r10, r9
 *   @0x273c50 bhs 0x278f40 <pcre_dfa_exec+0xa9d8>
 *   @0x273c54 ldr r1, [r6, #0x40]
 *   @0x273c58 ldrb r3, [r10]
 *   @0x273c5c ldrb r3, [r1, r3]
 *   @0x273c60 tst r3, #16
 *   @0x273c64 bne 0x278fb4 <pcre_dfa_exec+0xaa4c>
 *   @0x273c68 add r2, r10, r7
 *   @0x273c6c add r3, r10, #1
 *   @0x273c70 rsb r8, r8, r2
 *   @0x273c74 b 0x273c88 <pcre_dfa_exec+0x5720>
 *   @0x273c78 ldrb r2, [r4]
 *   @0x273c7c ldrb r2, [r1, r2]
 *   @0x273c80 tst r2, #16
 *   @0x273c84 bne 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c88 cmp r3, r8
 *   @0x273c8c mov r4, r3
 *   @0x273c90 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273c94 cmp r3, r9
 *   @0x273c98 add r3, r3, #1
 *   @0x273c9c bne 0x273c78 <pcre_dfa_exec+0x5710>
 *   @0x273ca0 ldr r2, [r6, #0x88]
 *   @0x273ca4 cmp r2, #0
 *   @0x273ca8 beq 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273cac ldr r3, [r6, #0x84]
 *   @0x273cb0 cmp r3, r4
 *   @0x273cb4 bhs 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273cb8 cmp r2, #1
 *   @0x273cbc mov r7, #1
 *   @0x273cc0 str r7, [r6, #0x64]
 *   @0x273cc4 ble 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x273cc8 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x273ccc mvn r0, #13
 *   @0x273cd0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x273cd4 ldr r3, [r6, #0x1c]
 *   @0x273cd8 rsb r2, r3, r2
 *   @0x273cdc cmp r10, r2
 *   @0x273ce0 bhi 0x273cf4 <pcre_dfa_exec+0x578c>
 *   @0x273ce4 ldrb r0, [r10]
 *   @0x273ce8 ldrb r2, [r6, #0x34]
 *   @0x273cec cmp r0, r2
 *   @0x273cf0 beq 0x27593c <pcre_dfa_exec+0x73d4>
 *   @0x273cf4 mov r0, r1
 *   @0x273cf8 b 0x271d04 <pcre_dfa_exec+0x379c>
 *   @0x273cfc cmp r3, r2
 *   @0x273d00 blo 0x271d28 <pcre_dfa_exec+0x37c0>
 *   @0x273d04 ldr r0, [r6, #0x18]
 *   @0x273d08 cmp r0, #0
 *   @0x273d0c bne 0x273d1c <pcre_dfa_exec+0x57b4>
 *   @0x273d10 ldr r0, [r6, #0x1c]
 *   @0x273d14 cmp r0, #2
 *   @0x273d18 beq 0x27675c <pcre_dfa_exec+0x81f4>
 *   @0x273d1c mov r10, r3
 *   @0x273d20 b 0x271d60 <pcre_dfa_exec+0x37f8>
 *   @0x273d24 tst r3, #4
 *   @0x273d28 bne 0x2742e8 <pcre_dfa_exec+0x5d80>
 *   @0x273d2c ldrb r0, [r10, #0x4]
 *   @0x273d30 and r3, r3, #3
 *   @0x273d34 ldrb r4, [r10, #0x1]
 *   @0x273d38 add r10, r10, #5
 *   @0x273d3c and r0, r0, #63
 *   @0x273d40 ldrb r12, [r10, #-0x3]
 *   @0x273d44 orr r3, r0, r3, lsl #24
 *   @0x273d48 and r4, r4, #63
 *   @0x273d4c ldrb r0, [r10, #-0x2]
 *   @0x273d50 and r12, r12, #63
 *   @0x273d54 orr r3, r3, r4, lsl #18
 *   @0x273d58 and r0, r0, #63
 *   @0x273d5c orr r3, r3, r12, lsl #12
 *   @0x273d60 orr r3, r3, r0, lsl #6
 *   @0x273d64 b 0x273434 <pcre_dfa_exec+0x4ecc>
 *   @0x273d68 tst r3, #4
 *   @0x273d6c bne 0x274330 <pcre_dfa_exec+0x5dc8>
 *   @0x273d70 ldrb r0, [r10, #0x4]
 *   @0x273d74 and r3, r3, #3
 *   @0x273d78 ldrb r4, [r10, #0x1]
 *   @0x273d7c add r10, r10, #5
 *   @0x273d80 and r0, r0, #63
 *   @0x273d84 ldrb r12, [r10, #-0x3]
 *   @0x273d88 orr r3, r0, r3, lsl #24
 *   @0x273d8c and r4, r4, #63
 *   @0x273d90 ldrb r0, [r10, #-0x2]
 *   @0x273d94 and r12, r12, #63
 *   @0x273d98 orr r3, r3, r4, lsl #18
 *   @0x273d9c and r0, r0, #63
 *   @0x273da0 orr r3, r3, r12, lsl #12
 *   @0x273da4 orr r3, r3, r0, lsl #6
 *   @0x273da8 b 0x273364 <pcre_dfa_exec+0x4dfc>
 *   @0x273dac mov r3, r11
 *   @0x273db0 ldrb r1, [r3, #0x1]
 *   @0x273db4 ldrb r2, [r3, #0x2]
 *   @0x273db8 orr r2, r2, r1, lsl #8
 *   @0x273dbc ldrb r2, [r3, r2]!
 *   @0x273dc0 cmp r2, #119
 *   @0x273dc4 beq 0x273db0 <pcre_dfa_exec+0x5848>
 *   @0x273dc8 mov r5, #1
 *   @0x273dcc str r5, [sp, #0x2c]
 *   @0x273dd0 ldr r7, [sp, #0x2c]
 *   @0x273dd4 ldr r12, [sp, #0x4c]
 *   @0x273dd8 orrs r7, r7, r12
 *   @0x273ddc bne 0x26fc84 <pcre_dfa_exec+0x171c>
 *   @0x273de0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x273de4 ldrb r3, [r4, #-0x1]
 *   @0x273de8 cmp r3, #13
 *   @0x273dec subeq r4, r4, #1
 *   @0x273df0 b 0x272598 <pcre_dfa_exec+0x4030>
 *   @0x273df4 tst r7, #8
 *   @0x273df8 bne 0x274804 <pcre_dfa_exec+0x629c>
 *   @0x273dfc ldrb r2, [r3, #0x3]
 *   @0x273e00 and r7, r7, #7
 *   @0x273e04 ldrb r0, [r3, #0x1]
 *   @0x273e08 add r11, r3, #4
 *   @0x273e0c ldrb r12, [r3, #0x2]
 *   @0x273e10 and r2, r2, #63
 *   @0x273e14 and r0, r0, #63
 *   @0x273e18 orr r2, r2, r7, lsl #18
 *   @0x273e1c and r7, r12, #63
 *   @0x273e20 orr r3, r2, r0, lsl #12
 *   @0x273e24 orr r7, r3, r7, lsl #6
 *   @0x273e28 b 0x270e2c <pcre_dfa_exec+0x28c4>
 *   @0x273e2c ldr r5, [sp, #0x2c]
 *   @0x273e30 add r11, r4, r8
 *   @0x273e34 cmp r7, r5
 *   @0x273e38 ldrbeq r5, [r4, r8]
 *   @0x273e3c beq 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x273e40 ldr r12, [sp, #0x4c]
 *   @0x273e44 cmp r12, #0
 *   @0x273e48 bne 0x27861c <pcre_dfa_exec+0xa0b4>
 *   @0x273e4c ldr r5, [sp, #0x2c]
 *   @0x273e50 cmp r5, r7
 *   @0x273e54 movle r5, r10
 *   @0x273e58 ble 0x273ef0 <pcre_dfa_exec+0x5988>
 *   @0x273e5c ldr r9, [r6, #0x78]
 *   @0x273e60 mov r5, r10
 *   @0x273e64 rsb r3, r8, r9
 *   @0x273e68 cmp r3, r10
 *   @0x273e6c blo 0x273ec0 <pcre_dfa_exec+0x5958>
 *   @0x273e70 str r6, [sp, #0x4c]
 *   @0x273e74 mov r6, r7
 *   @0x273e78 ldr r7, [sp, #0x2c]
 *   @0x273e7c str r9, [sp, #0x2c]
 *   @0x273e80 mov r9, r3
 *   @0x273e84 b 0x273e9c <pcre_dfa_exec+0x5934>
 *   @0x273e88 cmp r6, r7
 *   @0x273e8c add r5, r5, r8
 *   @0x273e90 beq 0x2757e4 <pcre_dfa_exec+0x727c>
 *   @0x273e94 cmp r5, r9
 *   @0x273e98 bhi 0x273eb8 <pcre_dfa_exec+0x5950>
 *   @0x273e9c mov r0, r5
 *   @0x273ea0 mov r1, r4
 *   @0x273ea4 mov r2, r8
 *   @0x273ea8 add r6, r6, #1
 *   @0x273eac bl 0xb6c40 <memcmp@plt>
 *   @0x273eb0 cmp r0, #0
 *   @0x273eb4 beq 0x273e88 <pcre_dfa_exec+0x5920>
 *   @0x273eb8 ldr r6, [sp, #0x4c]
 *   @0x273ebc ldr r9, [sp, #0x2c]
 *   @0x273ec0 ldr r2, [r6, #0x88]
 *   @0x273ec4 cmp r2, #0
 *   @0x273ec8 beq 0x273ef0 <pcre_dfa_exec+0x5988>
 *   @0x273ecc cmp r9, r5
 *   @0x273ed0 bhi 0x273ef0 <pcre_dfa_exec+0x5988>
 *   @0x273ed4 ldr r1, [r6, #0x84]
 *   @0x273ed8 cmp r1, r5
 *   @0x273edc bhs 0x273ef0 <pcre_dfa_exec+0x5988>
 *   @0x273ee0 cmp r2, #1
 *   @0x273ee4 mov r7, #1
 *   @0x273ee8 str r7, [r6, #0x64]
 *   @0x273eec bgt 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x273ef0 ldr r12, [sp, #0x30]
 *   @0x273ef4 cmp r12, #0
 *   @0x273ef8 bne 0x274cc4 <pcre_dfa_exec+0x675c>
 *   @0x273efc cmp r5, r10
 *   @0x273f00 bls 0x273f4c <pcre_dfa_exec+0x59e4>
 *   @0x273f04 ldr r4, [sp, #0x1c]
 *   @0x273f08 ldr r7, [sp, #0x18]
 *   @0x273f0c ldr r9, [sp, #0x164]
 *   @0x273f10 ldr r3, [sp, #0x168]
 *   @0x273f14 mov r0, r5
 *   @0x273f18 str r6, [sp]
 *   @0x273f1c mov r1, r11
 *   @0x273f20 add r3, r3, #1
 *   @0x273f24 str r9, [sp, #0x4]
 *   @0x273f28 str r3, [sp, #0x8]
 *   @0x273f2c mov r2, r4
 *   @0x273f30 mov r3, r7
 *   @0x273f34 rsb r5, r8, r5
 *   @0x273f38 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x273f3c cmp r0, #0
 *   @0x273f40 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x273f44 cmp r10, r5
 *   @0x273f48 blo 0x273f10 <pcre_dfa_exec+0x59a8>
 *   @0x273f4c mov r10, r5
 *   @0x273f50 b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x273f54 ldr r2, [r6, #0x10]
 *   @0x273f58 add r5, sp, #312
 *   @0x273f5c ldr r3, [r6, #0x90]
 *   @0x273f60 cmp r2, #30
 *   @0x273f64 str r12, [r5, #-0xc4]!
 *   @0x273f68 str r1, [sp, #0x78]
 *   @0x273f6c str r10, [sp, #0x88]
 *   @0x273f70 str r2, [sp, #0x80]
 *   @0x273f74 str r5, [r6, #0xa4]
 *   @0x273f78 str r3, [sp, #0x84]
 *   @0x273f7c bgt 0x2755e4 <pcre_dfa_exec+0x707c>
 *   @0x273f80 add r12, sp, #192
 *   @0x273f84 str r12, [sp, #0x2c]
 *   @0x273f88 str r12, [sp, #0x7c]
 *   @0x273f8c mov r0, r12
 *   @0x273f90 lsl r2, r2, #2
 *   @0x273f94 ldr r1, [r6, #0xc]
 *   @0x273f98 bl 0xb65bc <memcpy@plt>
 *   @0x273f9c ldrb r3, [r4, r7]
 *   @0x273fa0 ldr r12, [sp, #0x20]
 *   @0x273fa4 movw r7, #0xfc19
 *   @0x273fa8 cmp r3, #135
 *   @0x273fac ldr r3, [pc, #0xfcc]
 *   @0x273fb0 movt r7, #0xffff
 *   @0x273fb4 ldr r4, [r12, r3]
 *   @0x273fb8 mov r3, r5
 *   @0x273fbc str r11, [sp, #0x30]
 *   @0x273fc0 ldr r11, [sp, #0x1c]
 *   @0x273fc4 mov r5, r4
 *   @0x273fc8 bhi 0x274a30 <pcre_dfa_exec+0x64c8>
 *   @0x273fcc mov r4, r6
 *   @0x273fd0 mov r6, r3
 *   @0x273fd4 b 0x274004 <pcre_dfa_exec+0x5a9c>
 *   @0x273fd8 cmp r0, #4
 *   @0x273fdc bls 0x275824 <pcre_dfa_exec+0x72bc>
 *   @0x273fe0 cmp r8, #0
 *   @0x273fe4 bne 0x2757ec <pcre_dfa_exec+0x7284>
 *   @0x273fe8 str r6, [r4, #0xa4]
 *   @0x273fec ldrb r1, [r9, #0x1]
 *   @0x273ff0 ldrb r3, [r9, #0x2]
 *   @0x273ff4 orr r3, r3, r1, lsl #8
 *   @0x273ff8 ldrb r3, [r9, r3]!
 *   @0x273ffc cmp r3, #119
 *   @0x274000 bne 0x2758a0 <pcre_dfa_exec+0x7338>
 *   @0x274004 ldrb r1, [r9]
 *   @0x274008 mov r2, r11
 *   @0x27400c ldr r12, [sp, #0x164]
 *   @0x274010 mov r0, r10
 *   @0x274014 ldr lr, [sp, #0x168]
 *   @0x274018 ldrb r1, [r5, r1]
 *   @0x27401c add lr, lr, #1
 *   @0x274020 ldr r3, [sp, #0x18]
 *   @0x274024 str r12, [sp, #0x4]
 *   @0x274028 add r1, r9, r1
 *   @0x27402c str lr, [sp, #0x8]
 *   @0x274030 str r4, [sp]
 *   @0x274034 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x274038 ldr r2, [sp, #0x80]
 *   @0x27403c ldr r1, [sp, #0x7c]
 *   @0x274040 lsl r2, r2, #2
 *   @0x274044 mov r8, r0
 *   @0x274048 ldr r0, [r4, #0xc]
 *   @0x27404c bl 0xb65bc <memcpy@plt>
 *   @0x274050 ldr r1, [sp, #0x84]
 *   @0x274054 ldr r2, [sp, #0x74]
 *   @0x274058 cmp r8, #1
 *   @0x27405c cmpne r8, r7
 *   @0x274060 add r0, r8, #996
 *   @0x274064 str r1, [r4, #0x90]
 *   @0x274068 str r2, [r4, #0xa4]
 *   @0x27406c bne 0x273fd8 <pcre_dfa_exec+0x5a70>
 *   @0x274070 ldr r11, [sp, #0x30]
 *   @0x274074 mov r6, r4
 *   @0x274078 ldr r0, [sp, #0x7c]
 *   @0x27407c ldr r5, [sp, #0x2c]
 *   @0x274080 cmp r0, r5
 *   @0x274084 beq 0x27409c <pcre_dfa_exec+0x5b34>
 *   @0x274088 ldr r3, [pc, #0xefc]
 *   @0x27408c ldr r7, [sp, #0x20]
 *   @0x274090 ldr r3, [r7, r3]
 *   @0x274094 ldr r3, [r3]
 *   @0x274098 blx r3
 *   @0x27409c ldr r12, [r6, #0x7c]
 *   @0x2740a0 add r11, r11, #3
 *   @0x2740a4 ldrb r5, [r11]
 *   @0x2740a8 ldr r10, [r6, #0x80]
 *   @0x2740ac str r12, [sp, #0x1c]
 *   @0x2740b0 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2740b4 mov r11, r3
 *   @0x2740b8 b 0x26f850 <pcre_dfa_exec+0x12e8>
 *   @0x2740bc ldrb r2, [r11, #0x2]
 *   @0x2740c0 ldr r3, [r6, #0x74]
 *   @0x2740c4 orr r2, r2, r1, lsl #8
 *   @0x2740c8 rsb r10, r2, r10
 *   @0x2740cc cmp r10, r3
 *   @0x2740d0 blo 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2740d4 ldr r3, [r6, #0x84]
 *   @0x2740d8 cmp r10, r3
 *   @0x2740dc strlo r10, [r6, #0x84]
 *   @0x2740e0 b 0x26fd70 <pcre_dfa_exec+0x1808>
 *   @0x2740e4 mov r2, r10
 *   @0x2740e8 ldr r3, [r6, #0x88]
 *   @0x2740ec cmp r3, #0
 *   @0x2740f0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2740f4 ldr r1, [r6, #0x84]
 *   @0x2740f8 cmp r1, r2
 *   @0x2740fc blo 0x271820 <pcre_dfa_exec+0x32b8>
 *   @0x274100 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274104 ldr r3, [r6, #0x1c]
 *   @0x274108 rsb r9, r3, r9
 *   @0x27410c cmp r4, r9
 *   @0x274110 bhi 0x2725e4 <pcre_dfa_exec+0x407c>
 *   @0x274114 ldrb r0, [r4]
 *   @0x274118 ldrb r2, [r6, #0x34]
 *   @0x27411c cmp r0, r2
 *   @0x274120 bne 0x2725e4 <pcre_dfa_exec+0x407c>
 *   @0x274124 cmp r3, #1
 *   @0x274128 ldreq r1, [sp, #0x24]
 *   @0x27412c beq 0x2725e4 <pcre_dfa_exec+0x407c>
 *   @0x274130 ldrb r1, [r4, #0x1]
 *   @0x274134 ldrb r3, [r6, #0x35]
 *   @0x274138 subs r12, r1, r3
 *   @0x27413c rsbs r1, r12, #0
 *   @0x274140 adcs r1, r1, r12
 *   @0x274144 b 0x2725e4 <pcre_dfa_exec+0x407c>
 *   @0x274148 mvn r0, #7
 *   @0x27414c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x274150 cmp r1, r9
 *   @0x274154 mov r3, r1
 *   @0x274158 blo 0x274cd0 <pcre_dfa_exec+0x6768>
 *   @0x27415c ldr r0, [r6, #0x18]
 *   @0x274160 cmp r0, #0
 *   @0x274164 bne 0x272644 <pcre_dfa_exec+0x40dc>
 *   @0x274168 ldr r0, [r6, #0x1c]
 *   @0x27416c cmp r0, #2
 *   @0x274170 bne 0x272644 <pcre_dfa_exec+0x40dc>
 *   @0x274174 ldrb r12, [r4]
 *   @0x274178 ldrb r0, [r6, #0x34]
 *   @0x27417c cmp r12, r0
 *   @0x274180 bne 0x272644 <pcre_dfa_exec+0x40dc>
 *   @0x274184 cmp r2, #1
 *   @0x274188 mov r0, #1
 *   @0x27418c str r0, [r6, #0x64]
 *   @0x274190 ble 0x272600 <pcre_dfa_exec+0x4098>
 *   @0x274194 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x274198 mvn r0, #20
 *   @0x27419c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2741a0 tst r0, #4
 *   @0x2741a4 bne 0x274d48 <pcre_dfa_exec+0x67e0>
 *   @0x2741a8 ldrb r2, [r10, #0x4]
 *   @0x2741ac and r0, r0, #3
 *   @0x2741b0 ldrb lr, [r10, #0x1]
 *   @0x2741b4 add r10, r10, #5
 *   @0x2741b8 ldrb r1, [r10, #-0x3]
 *   @0x2741bc and r2, r2, #63
 *   @0x2741c0 orr r2, r2, r0, lsl #24
 *   @0x2741c4 and lr, lr, #63
 *   @0x2741c8 ldrb r0, [r10, #-0x2]
 *   @0x2741cc and r1, r1, #63
 *   @0x2741d0 orr r2, r2, lr, lsl #18
 *   @0x2741d4 and r0, r0, #63
 *   @0x2741d8 orr r2, r2, r1, lsl #12
 *   @0x2741dc orr r0, r2, r0, lsl #6
 *   @0x2741e0 b 0x270220 <pcre_dfa_exec+0x1cb8>
 *   @0x2741e4 str r9, [sp]
 *   @0x2741e8 mov r0, r7
 *   @0x2741ec mov r2, r8
 *   @0x2741f0 mov r1, r10
 *   @0x2741f4 mov r3, r6
 *   @0x2741f8 bl 0x25cc6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b44>
 *   @0x2741fc cmp r0, #0
 *   @0x274200 blt 0x2719b4 <pcre_dfa_exec+0x344c>
 *   @0x274204 add r10, r10, r0
 *   @0x274208 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x27420c ldr r7, [r6, #0x7c]
 *   @0x274210 ldrb r3, [r11]
 *   @0x274214 str r7, [sp, #0x1c]
 *   @0x274218 cmp r3, #120
 *   @0x27421c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274220 cmp r8, #0
 *   @0x274224 bne 0x270060 <pcre_dfa_exec+0x1af8>
 *   @0x274228 ldrb r2, [r11, #0x1]
 *   @0x27422c ldrb r3, [r11, #0x2]
 *   @0x274230 orr r3, r3, r2, lsl #8
 *   @0x274234 ldrb r3, [r11, r3]!
 *   @0x274238 cmp r3, #119
 *   @0x27423c beq 0x274228 <pcre_dfa_exec+0x5cc0>
 *   @0x274240 ldr r12, [r6, #0x8c]
 *   @0x274244 mov r3, r11
 *   @0x274248 ldrb r5, [r11, #0x3]
 *   @0x27424c add r11, r11, #3
 *   @0x274250 str r12, [sp, #0x18]
 *   @0x274254 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x274258 ldr r12, [r6, #0x7c]
 *   @0x27425c ldrb r3, [r5]
 *   @0x274260 str r12, [sp, #0x1c]
 *   @0x274264 cmp r3, #119
 *   @0x274268 cmpne r3, #130
 *   @0x27426c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274270 ldrb r2, [r5, #0x1]
 *   @0x274274 ldrb r3, [r5, #0x2]
 *   @0x274278 orr r3, r3, r2, lsl #8
 *   @0x27427c ldrb r3, [r5, r3]!
 *   @0x274280 cmp r3, #119
 *   @0x274284 beq 0x274270 <pcre_dfa_exec+0x5d08>
 *   @0x274288 ldr r7, [r6, #0x8c]
 *   @0x27428c cmp r3, #120
 *   @0x274290 ldr r4, [r6, #0x80]
 *   @0x274294 str r7, [sp, #0x18]
 *   @0x274298 beq 0x2742a4 <pcre_dfa_exec+0x5d3c>
 *   @0x27429c cmp r10, r4
 *   @0x2742a0 bne 0x278a9c <pcre_dfa_exec+0xa534>
 *   @0x2742a4 add r11, r5, #3
 *   @0x2742a8 mov r10, r4
 *   @0x2742ac ldrb r5, [r5, #0x3]
 *   @0x2742b0 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2742b4 cmn r0, #996
 *   @0x2742b8 bge 0x270a0c <pcre_dfa_exec+0x24a4>
 *   @0x2742bc movw r3, #0xfc19
 *   @0x2742c0 movt r3, #0xffff
 *   @0x2742c4 cmp r0, r3
 *   @0x2742c8 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2742cc mov r0, #0
 *   @0x2742d0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2742d4 ldr r8, [r6, #0x50]
 *   @0x2742d8 cmp r8, #0
 *   @0x2742dc movne r8, #0
 *   @0x2742e0 mvneq r8, #0
 *   @0x2742e4 b 0x2702ec <pcre_dfa_exec+0x1d84>
 *   @0x2742e8 ldrb r12, [r10, #0x5]
 *   @0x2742ec and r3, r3, #1
 *   @0x2742f0 ldrb r0, [r10, #0x1]
 *   @0x2742f4 add r10, r10, #6
 *   @0x2742f8 and r12, r12, #63
 *   @0x2742fc ldrb r4, [r10, #-0x4]
 *   @0x274300 and r0, r0, #63
 *   @0x274304 orr r3, r12, r3, lsl #30
 *   @0x274308 ldrb r12, [r10, #-0x3]
 *   @0x27430c and r4, r4, #63
 *   @0x274310 orr r3, r3, r0, lsl #24
 *   @0x274314 ldrb r0, [r10, #-0x2]
 *   @0x274318 and r12, r12, #63
 *   @0x27431c orr r3, r3, r4, lsl #18
 *   @0x274320 and r0, r0, #63
 *   @0x274324 orr r3, r3, r12, lsl #12
 *   @0x274328 orr r3, r3, r0, lsl #6
 *   @0x27432c b 0x273434 <pcre_dfa_exec+0x4ecc>
 *   @0x274330 ldrb r12, [r10, #0x5]
 *   @0x274334 and r3, r3, #1
 *   @0x274338 ldrb r0, [r10, #0x1]
 *   @0x27433c add r10, r10, #6
 *   @0x274340 and r12, r12, #63
 *   @0x274344 ldrb r4, [r10, #-0x4]
 *   @0x274348 and r0, r0, #63
 *   @0x27434c orr r3, r12, r3, lsl #30
 *   @0x274350 ldrb r12, [r10, #-0x3]
 *   @0x274354 and r4, r4, #63
 *   @0x274358 orr r3, r3, r0, lsl #24
 *   @0x27435c ldrb r0, [r10, #-0x2]
 *   @0x274360 and r12, r12, #63
 *   @0x274364 orr r3, r3, r4, lsl #18
 *   @0x274368 and r0, r0, #63
 *   @0x27436c orr r3, r3, r12, lsl #12
 *   @0x274370 orr r3, r3, r0, lsl #6
 *   @0x274374 b 0x273364 <pcre_dfa_exec+0x4dfc>
 *   @0x274378 mov r4, r1
 *   @0x27437c b 0x272574 <pcre_dfa_exec+0x400c>
 *   @0x274380 mov r3, r11
 *   @0x274384 b 0x273dd0 <pcre_dfa_exec+0x5868>
 *   @0x274388 ldrb r5, [r4, #0x1]
 *   @0x27438c b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x274390 cmp r12, #0
 *   @0x274394 beq 0x2712c4 <pcre_dfa_exec+0x2d5c>
 *   @0x274398 ldr r9, [r6, #0x78]
 *   @0x27439c cmp r10, r9
 *   @0x2743a0 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2743a4 mov r2, #1
 *   @0x2743a8 b 0x2743ec <pcre_dfa_exec+0x5e84>
 *   @0x2743ac tst r3, #32
 *   @0x2743b0 bne 0x274414 <pcre_dfa_exec+0x5eac>
 *   @0x2743b4 ldrb r1, [r10, #0x1]
 *   @0x2743b8 and r3, r3, #31
 *   @0x2743bc add r10, r10, #2
 *   @0x2743c0 and r1, r1, #63
 *   @0x2743c4 orr r3, r1, r3, lsl #6
 *   @0x2743c8 cmp r3, #255
 *   @0x2743cc bls 0x2743fc <pcre_dfa_exec+0x5e94>
 *   @0x2743d0 cmp r5, #110
 *   @0x2743d4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2743d8 add r2, r2, #1
 *   @0x2743dc cmp r12, r2
 *   @0x2743e0 blt 0x2712bc <pcre_dfa_exec+0x2d54>
 *   @0x2743e4 cmp r9, r10
 *   @0x2743e8 bls 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2743ec ldrb r3, [r10]
 *   @0x2743f0 cmp r3, #191
 *   @0x2743f4 bhi 0x2743ac <pcre_dfa_exec+0x5e44>
 *   @0x2743f8 add r10, r10, #1
 *   @0x2743fc ldrb r1, [r8, r3, lsr #3]
 *   @0x274400 and r3, r3, #7
 *   @0x274404 asr r3, r1, r3
 *   @0x274408 tst r3, #1
 *   @0x27440c bne 0x2743d8 <pcre_dfa_exec+0x5e70>
 *   @0x274410 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274414 tst r3, #16
 *   @0x274418 bne 0x274444 <pcre_dfa_exec+0x5edc>
 *   @0x27441c lsl r4, r3, #12
 *   @0x274420 ldrb r1, [r10, #0x1]
 *   @0x274424 ldrb r3, [r10, #0x2]
 *   @0x274428 add r10, r10, #3
 *   @0x27442c uxth r4, r4
 *   @0x274430 and r1, r1, #63
 *   @0x274434 and r3, r3, #63
 *   @0x274438 orr r3, r4, r3
 *   @0x27443c orr r3, r3, r1, lsl #6
 *   @0x274440 b 0x2743c8 <pcre_dfa_exec+0x5e60>
 *   @0x274444 tst r3, #8
 *   @0x274448 bne 0x274688 <pcre_dfa_exec+0x6120>
 *   @0x27444c ldrb r7, [r10, #0x3]
 *   @0x274450 and r3, r3, #7
 *   @0x274454 ldrb r4, [r10, #0x1]
 *   @0x274458 add r10, r10, #4
 *   @0x27445c ldrb r1, [r10, #-0x2]
 *   @0x274460 and r7, r7, #63
 *   @0x274464 and r4, r4, #63
 *   @0x274468 orr r3, r7, r3, lsl #18
 *   @0x27446c and r1, r1, #63
 *   @0x274470 orr r3, r3, r4, lsl #12
 *   @0x274474 orr r3, r3, r1, lsl #6
 *   @0x274478 b 0x2743c8 <pcre_dfa_exec+0x5e60>
 *   @0x27447c cmp r2, r10
 *   @0x274480 bne 0x2704e4 <pcre_dfa_exec+0x1f7c>
 *   @0x274484 b 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x274488 ldr r3, [r6, #0x48]
 *   @0x27448c cmp r3, #0
 *   @0x274490 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274494 ldr r2, [r6, #0x88]
 *   @0x274498 cmp r2, #0
 *   @0x27449c beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2744a0 ldr r3, [r6, #0x84]
 *   @0x2744a4 cmp r10, r3
 *   @0x2744a8 bls 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2744ac cmp r2, #1
 *   @0x2744b0 mov r0, #1
 *   @0x2744b4 str r0, [r6, #0x64]
 *   @0x2744b8 ble 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2744bc b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x2744c0 cmp r3, r10
 *   @0x2744c4 beq 0x2767f4 <pcre_dfa_exec+0x828c>
 *   @0x2744c8 ldr r3, [r6, #0x84]
 *   @0x2744cc ldr r2, [r6, #0x40]
 *   @0x2744d0 cmp r10, r3
 *   @0x2744d4 subls r3, r10, #1
 *   @0x2744d8 strls r3, [r6, #0x84]
 *   @0x2744dc ldrb r3, [r10, #-0x1]
 *   @0x2744e0 ldrb r0, [r2, r3]
 *   @0x2744e4 ubfx r0, r0, #0x4, #0x1
 *   @0x2744e8 ldr r9, [r6, #0x78]
 *   @0x2744ec cmp r10, r9
 *   @0x2744f0 blo 0x275270 <pcre_dfa_exec+0x6d08>
 *   @0x2744f4 ldr r2, [r6, #0x88]
 *   @0x2744f8 cmp r2, #0
 *   @0x2744fc beq 0x2708b4 <pcre_dfa_exec+0x234c>
 *   @0x274500 ldr r3, [r6, #0x84]
 *   @0x274504 cmp r10, r3
 *   @0x274508 bls 0x2708b0 <pcre_dfa_exec+0x2348>
 *   @0x27450c cmp r2, #1
 *   @0x274510 mov r2, #1
 *   @0x274514 str r2, [r6, #0x64]
 *   @0x274518 ble 0x2708b0 <pcre_dfa_exec+0x2348>
 *   @0x27451c b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x274520 movw r2, #0x202f
 *   @0x274524 cmp r3, r2
 *   @0x274528 beq 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x27452c bhi 0x27521c <pcre_dfa_exec+0x6cb4>
 *   @0x274530 sub r3, r3, #8192
 *   @0x274534 cmp r3, #10
 *   @0x274538 bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x27453c b 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x274540 ldr r3, [r6, #0x1c]
 *   @0x274544 ldr r2, [r6, #0x78]
 *   @0x274548 rsb r2, r3, r2
 *   @0x27454c cmp r10, r2
 *   @0x274550 bhi 0x270b28 <pcre_dfa_exec+0x25c0>
 *   @0x274554 ldrb r0, [r10]
 *   @0x274558 ldrb r2, [r6, #0x34]
 *   @0x27455c cmp r0, r2
 *   @0x274560 bne 0x270b28 <pcre_dfa_exec+0x25c0>
 *   @0x274564 cmp r3, #1
 *   @0x274568 moveq r1, r3
 *   @0x27456c beq 0x270b28 <pcre_dfa_exec+0x25c0>
 *   @0x274570 ldrb r1, [r10, #0x1]
 *   @0x274574 ldrb r3, [r6, #0x35]
 *   @0x274578 subs r7, r1, r3
 *   @0x27457c rsbs r1, r7, #0
 *   @0x274580 adcs r1, r1, r7
 *   @0x274584 b 0x270b28 <pcre_dfa_exec+0x25c0>
 *   @0x274588 ldr r9, [r6, #0x78]
 *   @0x27458c rsb r9, r10, r9
 *   @0x274590 cmp r9, #0
 *   @0x274594 ble 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x274598 ldrb r2, [r11, #0x1]
 *   @0x27459c add r1, r10, #1
 *   @0x2745a0 ldrb r3, [r10]
 *   @0x2745a4 cmp r2, r3
 *   @0x2745a8 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2745ac ldrb r5, [r11, #0x2]
 *   @0x2745b0 mov r10, r1
 *   @0x2745b4 add r11, r11, #2
 *   @0x2745b8 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2745bc sub r3, r3, #8192
 *   @0x2745c0 sub r3, r3, #40
 *   @0x2745c4 cmp r3, #1
 *   @0x2745c8 bhi 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2745cc b 0x2703e8 <pcre_dfa_exec+0x1e80>
 *   @0x2745d0 ldrb r2, [r11, #0x1]
 *   @0x2745d4 add r1, r10, #1
 *   @0x2745d8 ldrb r3, [r10]
 *   @0x2745dc cmp r2, r3
 *   @0x2745e0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2745e4 cmp r5, #32
 *   @0x2745e8 bne 0x2745ac <pcre_dfa_exec+0x6044>
 *   @0x2745ec ldr r0, [r6, #0x3c]
 *   @0x2745f0 ldrb r2, [r0, r2]
 *   @0x2745f4 cmp r2, r3
 *   @0x2745f8 bne 0x2745ac <pcre_dfa_exec+0x6044>
 *   @0x2745fc b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274600 ldr r3, [r6, #0x38]
 *   @0x274604 ldrb r2, [r11, #0x1]
 *   @0x274608 ldrb r1, [r10]
 *   @0x27460c ldrb r2, [r3, r2]
 *   @0x274610 ldrb r3, [r3, r1]
 *   @0x274614 cmp r2, r3
 *   @0x274618 beq 0x26fb90 <pcre_dfa_exec+0x1628>
 *   @0x27461c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274620 mov r10, r3
 *   @0x274624 b 0x26ffec <pcre_dfa_exec+0x1a84>
 *   @0x274628 tst r3, #16
 *   @0x27462c bne 0x275698 <pcre_dfa_exec+0x7130>
 *   @0x274630 lsl r0, r3, #12
 *   @0x274634 ldrb r1, [r10, #0x1]
 *   @0x274638 ldrb r3, [r10, #0x2]
 *   @0x27463c add r10, r10, #3
 *   @0x274640 uxth r0, r0
 *   @0x274644 and r1, r1, #63
 *   @0x274648 and r3, r3, #63
 *   @0x27464c orr r3, r0, r3
 *   @0x274650 orr r3, r3, r1, lsl #6
 *   @0x274654 b 0x271c8c <pcre_dfa_exec+0x3724>
 *   @0x274658 tst r3, #16
 *   @0x27465c bne 0x275650 <pcre_dfa_exec+0x70e8>
 *   @0x274660 lsl r12, r3, #12
 *   @0x274664 ldrb r0, [r10, #0x1]
 *   @0x274668 ldrb r3, [r10, #0x2]
 *   @0x27466c add r10, r10, #3
 *   @0x274670 uxth r12, r12
 *   @0x274674 and r0, r0, #63
 *   @0x274678 and r3, r3, #63
 *   @0x27467c orr r3, r12, r3
 *   @0x274680 orr r3, r3, r0, lsl #6
 *   @0x274684 b 0x271ae4 <pcre_dfa_exec+0x357c>
 *   @0x274688 tst r3, #4
 *   @0x27468c bne 0x275564 <pcre_dfa_exec+0x6ffc>
 *   @0x274690 ldrb r1, [r10, #0x4]
 *   @0x274694 and r3, r3, #3
 *   @0x274698 ldrb r7, [r10, #0x1]
 *   @0x27469c add r10, r10, #5
 *   @0x2746a0 and r1, r1, #63
 *   @0x2746a4 ldrb r4, [r10, #-0x3]
 *   @0x2746a8 orr r3, r1, r3, lsl #24
 *   @0x2746ac and r7, r7, #63
 *   @0x2746b0 ldrb r1, [r10, #-0x2]
 *   @0x2746b4 and r4, r4, #63
 *   @0x2746b8 orr r3, r3, r7, lsl #18
 *   @0x2746bc and r1, r1, #63
 *   @0x2746c0 orr r3, r3, r4, lsl #12
 *   @0x2746c4 orr r3, r3, r1, lsl #6
 *   @0x2746c8 b 0x2743c8 <pcre_dfa_exec+0x5e60>
 *   @0x2746cc tst r3, #16
 *   @0x2746d0 bne 0x2755ac <pcre_dfa_exec+0x7044>
 *   @0x2746d4 lsl r0, r3, #12
 *   @0x2746d8 ldrb r1, [r10, #0x1]
 *   @0x2746dc ldrb r3, [r10, #0x2]
 *   @0x2746e0 add r10, r10, #3
 *   @0x2746e4 uxth r0, r0
 *   @0x2746e8 and r1, r1, #63
 *   @0x2746ec and r3, r3, #63
 *   @0x2746f0 orr r3, r0, r3
 *   @0x2746f4 orr r3, r3, r1, lsl #6
 *   @0x2746f8 b 0x271b6c <pcre_dfa_exec+0x3604>
 *   @0x2746fc tst r3, #16
 *   @0x274700 bne 0x275618 <pcre_dfa_exec+0x70b0>
 *   @0x274704 lsl r12, r3, #12
 *   @0x274708 ldrb r0, [r10, #0x1]
 *   @0x27470c ldrb r3, [r10, #0x2]
 *   @0x274710 add r10, r10, #3
 *   @0x274714 uxth r12, r12
 *   @0x274718 and r0, r0, #63
 *   @0x27471c and r3, r3, #63
 *   @0x274720 orr r3, r12, r3
 *   @0x274724 orr r3, r3, r0, lsl #6
 *   @0x274728 b 0x271bfc <pcre_dfa_exec+0x3694>
 *   @0x27472c movw r0, #0x205f
 *   @0x274730 cmp r3, r0
 *   @0x274734 beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x274738 cmp r3, #12288
 *   @0x27473c bne 0x271aa4 <pcre_dfa_exec+0x353c>
 *   @0x274740 b 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x274744 subs r5, r1, #105
 *   @0x274748 ldrb r7, [r11, #0x3]
 *   @0x27474c rsbs r4, r5, #0
 *   @0x274750 ldrb r3, [r11, #0x4]
 *   @0x274754 adcs r4, r4, r5
 *   @0x274758 subs r9, r1, #109
 *   @0x27475c rsbs r1, r9, #0
 *   @0x274760 ldrb r5, [r11, #0x1]
 *   @0x274764 adcs r1, r1, r9
 *   @0x274768 ldrb r2, [r11, #0x2]
 *   @0x27476c orrs r7, r3, r7, lsl #8
 *   @0x274770 str r1, [sp, #0x2c]
 *   @0x274774 add r11, r11, #5
 *   @0x274778 orr r5, r2, r5, lsl #8
 *   @0x27477c mvneq r7, #-2147483648
 *   @0x274780 b 0x2701b4 <pcre_dfa_exec+0x1c4c>
 *   @0x274784 subs r3, r1, #105
 *   @0x274788 ldrb r0, [r11, #0x24]
 *   @0x27478c rsbs r12, r3, #0
 *   @0x274790 add r11, r11, #38
 *   @0x274794 adcs r12, r12, r3
 *   @0x274798 ldrb r3, [r11, #-0x1]
 *   @0x27479c subs r2, r1, #109
 *   @0x2747a0 str r12, [sp, #0x2c]
 *   @0x2747a4 rsbs r1, r2, #0
 *   @0x2747a8 ldrb r12, [r11, #-0x4]
 *   @0x2747ac adcs r1, r1, r2
 *   @0x2747b0 ldrb r2, [r11, #-0x3]
 *   @0x2747b4 orrs r0, r3, r0, lsl #8
 *   @0x2747b8 str r1, [sp, #0x30]
 *   @0x2747bc orr r12, r2, r12, lsl #8
 *   @0x2747c0 mvneq r0, #-2147483648
 *   @0x2747c4 b 0x271248 <pcre_dfa_exec+0x2ce0>
 *   @0x2747c8 cmp r3, #160
 *   @0x2747cc beq 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x2747d0 cmp r3, #5760
 *   @0x2747d4 bne 0x271aa4 <pcre_dfa_exec+0x353c>
 *   @0x2747d8 b 0x271b0c <pcre_dfa_exec+0x35a4>
 *   @0x2747dc movw r2, #0x202f
 *   @0x2747e0 cmp r3, r2
 *   @0x2747e4 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2747e8 bls 0x276444 <pcre_dfa_exec+0x7edc>
 *   @0x2747ec movw r2, #0x205f
 *   @0x2747f0 cmp r3, r2
 *   @0x2747f4 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2747f8 cmp r3, #12288
 *   @0x2747fc beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x274800 b 0x270964 <pcre_dfa_exec+0x23fc>
 *   @0x274804 tst r7, #4
 *   @0x274808 bne 0x2756d0 <pcre_dfa_exec+0x7168>
 *   @0x27480c ldrb r2, [r3, #0x4]
 *   @0x274810 and r7, r7, #3
 *   @0x274814 ldrb r12, [r3, #0x1]
 *   @0x274818 add r11, r3, #5
 *   @0x27481c ldrb r0, [r3, #0x2]
 *   @0x274820 and r2, r2, #63
 *   @0x274824 orr r2, r2, r7, lsl #24
 *   @0x274828 and r12, r12, #63
 *   @0x27482c ldrb r7, [r3, #0x3]
 *   @0x274830 and r0, r0, #63
 *   @0x274834 orr r2, r2, r12, lsl #18
 *   @0x274838 and r7, r7, #63
 *   @0x27483c orr r3, r2, r0, lsl #12
 *   @0x274840 orr r7, r3, r7, lsl #6
 *   @0x274844 b 0x270e2c <pcre_dfa_exec+0x28c4>
 *   @0x274848 mov r11, r3
 *   @0x27484c b 0x26fbe0 <pcre_dfa_exec+0x1678>
 *   @0x274850 ldrb r5, [r4, #0x1]
 *   @0x274854 mov r10, r8
 *   @0x274858 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x27485c cmp r1, r8
 *   @0x274860 ble 0x27492c <pcre_dfa_exec+0x63c4>
 *   @0x274864 ldr r9, [r6, #0x78]
 *   @0x274868 cmp r10, r9
 *   @0x27486c movlo r4, r10
 *   @0x274870 blo 0x2748ac <pcre_dfa_exec+0x6344>
 *   @0x274874 b 0x275dc0 <pcre_dfa_exec+0x7858>
 *   @0x274878 ldrb r0, [r4, #0x1]
 *   @0x27487c and r3, r3, #31
 *   @0x274880 mov r2, #2
 *   @0x274884 and r0, r0, #63
 *   @0x274888 orr r3, r0, r3, lsl #6
 *   @0x27488c cmp r7, r3
 *   @0x274890 beq 0x274930 <pcre_dfa_exec+0x63c8>
 *   @0x274894 add r8, r8, #1
 *   @0x274898 add r4, r4, r2
 *   @0x27489c cmp r8, r1
 *   @0x2748a0 beq 0x274930 <pcre_dfa_exec+0x63c8>
 *   @0x2748a4 cmp r9, r4
 *   @0x2748a8 bls 0x275dc4 <pcre_dfa_exec+0x785c>
 *   @0x2748ac ldrb r3, [r4]
 *   @0x2748b0 cmp r3, #191
 *   @0x2748b4 movls r2, #1
 *   @0x2748b8 bls 0x27488c <pcre_dfa_exec+0x6324>
 *   @0x2748bc tst r3, #32
 *   @0x2748c0 beq 0x274878 <pcre_dfa_exec+0x6310>
 *   @0x2748c4 tst r3, #16
 *   @0x2748c8 bne 0x2748f4 <pcre_dfa_exec+0x638c>
 *   @0x2748cc lsl r2, r3, #12
 *   @0x2748d0 ldrb r0, [r4, #0x1]
 *   @0x2748d4 ldrb r3, [r4, #0x2]
 *   @0x2748d8 uxth r2, r2
 *   @0x2748dc and r0, r0, #63
 *   @0x2748e0 and r3, r3, #63
 *   @0x2748e4 orr r3, r2, r3
 *   @0x2748e8 mov r2, #3
 *   @0x2748ec orr r3, r3, r0, lsl #6
 *   @0x2748f0 b 0x27488c <pcre_dfa_exec+0x6324>
 *   @0x2748f4 tst r3, #8
 *   @0x2748f8 bne 0x275034 <pcre_dfa_exec+0x6acc>
 *   @0x2748fc ldrb r12, [r4, #0x3]
 *   @0x274900 and r3, r3, #7
 *   @0x274904 ldrb r2, [r4, #0x1]
 *   @0x274908 ldrb r0, [r4, #0x2]
 *   @0x27490c and r12, r12, #63
 *   @0x274910 and r2, r2, #63
 *   @0x274914 orr r3, r12, r3, lsl #18
 *   @0x274918 and r0, r0, #63
 *   @0x27491c orr r3, r3, r2, lsl #12
 *   @0x274920 mov r2, #4
 *   @0x274924 orr r3, r3, r0, lsl #6
 *   @0x274928 b 0x27488c <pcre_dfa_exec+0x6324>
 *   @0x27492c mov r4, r10
 *   @0x274930 ldr r1, [sp, #0x2c]
 *   @0x274934 cmp r1, #0
 *   @0x274938 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x27493c cmp r4, r10
 *   @0x274940 bls 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x274944 ldr r5, [sp, #0x1c]
 *   @0x274948 ldr r7, [sp, #0x18]
 *   @0x27494c ldr r8, [sp, #0x164]
 *   @0x274950 ldr r3, [sp, #0x168]
 *   @0x274954 mov r0, r4
 *   @0x274958 str r6, [sp]
 *   @0x27495c mov r1, r11
 *   @0x274960 add r3, r3, #1
 *   @0x274964 str r8, [sp, #0x4]
 *   @0x274968 str r3, [sp, #0x8]
 *   @0x27496c mov r2, r5
 *   @0x274970 mov r3, r7
 *   @0x274974 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x274978 cmp r0, #0
 *   @0x27497c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x274980 ldrb r3, [r4, #-0x1]
 *   @0x274984 sub r2, r4, #1
 *   @0x274988 and r3, r3, #192
 *   @0x27498c cmp r3, #128
 *   @0x274990 bne 0x2757c0 <pcre_dfa_exec+0x7258>
 *   @0x274994 sub r12, r4, #2
 *   @0x274998 mov r4, r12
 *   @0x27499c sub r12, r12, #1
 *   @0x2749a0 ldrb r3, [r4]
 *   @0x2749a4 and r3, r3, #192
 *   @0x2749a8 cmp r3, #128
 *   @0x2749ac beq 0x274998 <pcre_dfa_exec+0x6430>
 *   @0x2749b0 cmp r4, r10
 *   @0x2749b4 bhi 0x274950 <pcre_dfa_exec+0x63e8>
 *   @0x2749b8 b 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x2749bc tst r3, #16
 *   @0x2749c0 bne 0x275768 <pcre_dfa_exec+0x7200>
 *   @0x2749c4 lsl r2, r3, #12
 *   @0x2749c8 ldrb r1, [r4, #0x1]
 *   @0x2749cc ldrb r3, [r4, #0x2]
 *   @0x2749d0 uxth r2, r2
 *   @0x2749d4 and r1, r1, #63
 *   @0x2749d8 and r3, r3, #63
 *   @0x2749dc orr r3, r2, r3
 *   @0x2749e0 mov r2, #3
 *   @0x2749e4 orr r3, r3, r1, lsl #6
 *   @0x2749e8 b 0x272888 <pcre_dfa_exec+0x4320>
 *   @0x2749ec ldr r3, [r6, #0x1c]
 *   @0x2749f0 add r2, r2, r3
 *   @0x2749f4 cmp r10, r2
 *   @0x2749f8 blo 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2749fc rsb r1, r3, r10
 *   @0x274a00 ldrb r2, [r6, #0x34]
 *   @0x274a04 ldrb r1, [r1]
 *   @0x274a08 cmp r1, r2
 *   @0x274a0c bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274a10 cmp r3, #1
 *   @0x274a14 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x274a18 rsb r3, r3, #1
 *   @0x274a1c ldrb r2, [r6, #0x35]
 *   @0x274a20 ldrb r3, [r10, r3]
 *   @0x274a24 cmp r3, r2
 *   @0x274a28 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274a2c b 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x274a30 mov r4, r9
 *   @0x274a34 mov r9, r3
 *   @0x274a38 b 0x274a68 <pcre_dfa_exec+0x6500>
 *   @0x274a3c cmp r0, #4
 *   @0x274a40 bls 0x275824 <pcre_dfa_exec+0x72bc>
 *   @0x274a44 cmp r8, #0
 *   @0x274a48 bne 0x2757ec <pcre_dfa_exec+0x7284>
 *   @0x274a4c str r9, [r6, #0xa4]
 *   @0x274a50 ldrb r1, [r4, #0x1]
 *   @0x274a54 ldrb r3, [r4, #0x2]
 *   @0x274a58 orr r3, r3, r1, lsl #8
 *   @0x274a5c ldrb r3, [r4, r3]!
 *   @0x274a60 cmp r3, #119
 *   @0x274a64 bne 0x2758a4 <pcre_dfa_exec+0x733c>
 *   @0x274a68 mov lr, #2
 *   @0x274a6c str lr, [r6, #0x98]
 *   @0x274a70 ldrb r1, [r4]
 *   @0x274a74 mov r2, r11
 *   @0x274a78 ldr r12, [sp, #0x164]
 *   @0x274a7c mov r0, r10
 *   @0x274a80 ldr lr, [sp, #0x168]
 *   @0x274a84 ldrb r1, [r5, r1]
 *   @0x274a88 add lr, lr, #1
 *   @0x274a8c ldr r3, [sp, #0x18]
 *   @0x274a90 str r12, [sp, #0x4]
 *   @0x274a94 add r1, r4, r1
 *   @0x274a98 str lr, [sp, #0x8]
 *   @0x274a9c str r6, [sp]
 *   @0x274aa0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x274aa4 ldr r2, [sp, #0x80]
 *   @0x274aa8 ldr r1, [sp, #0x7c]
 *   @0x274aac lsl r2, r2, #2
 *   @0x274ab0 mov r8, r0
 *   @0x274ab4 ldr r0, [r6, #0xc]
 *   @0x274ab8 bl 0xb65bc <memcpy@plt>
 *   @0x274abc ldr r1, [sp, #0x84]
 *   @0x274ac0 ldr r2, [sp, #0x74]
 *   @0x274ac4 cmp r8, #1
 *   @0x274ac8 cmpne r8, r7
 *   @0x274acc add r0, r8, #996
 *   @0x274ad0 str r1, [r6, #0x90]
 *   @0x274ad4 str r2, [r6, #0xa4]
 *   @0x274ad8 bne 0x274a3c <pcre_dfa_exec+0x64d4>
 *   @0x274adc ldr r11, [sp, #0x30]
 *   @0x274ae0 b 0x274078 <pcre_dfa_exec+0x5b10>
 *   @0x274ae4 ldr r3, [r6, #0x1c]
 *   @0x274ae8 rsb r2, r3, r9
 *   @0x274aec cmp r10, r2
 *   @0x274af0 bhi 0x2717dc <pcre_dfa_exec+0x3274>
 *   @0x274af4 ldrb r1, [r10]
 *   @0x274af8 ldrb r2, [r6, #0x34]
 *   @0x274afc cmp r1, r2
 *   @0x274b00 bne 0x2717dc <pcre_dfa_exec+0x3274>
 *   @0x274b04 cmp r3, #1
 *   @0x274b08 beq 0x26f770 <pcre_dfa_exec+0x1208>
 *   @0x274b0c ldrb r1, [r10, #0x1]
 *   @0x274b10 ldrb r2, [r6, #0x35]
 *   @0x274b14 cmp r1, r2
 *   @0x274b18 bne 0x2717dc <pcre_dfa_exec+0x3274>
 *   @0x274b1c b 0x26f770 <pcre_dfa_exec+0x1208>
 *   @0x274b20 cmp r1, r8
 *   @0x274b24 ble 0x274bf4 <pcre_dfa_exec+0x668c>
 *   @0x274b28 ldr r9, [r6, #0x78]
 *   @0x274b2c cmp r10, r9
 *   @0x274b30 movlo r4, r10
 *   @0x274b34 blo 0x274b74 <pcre_dfa_exec+0x660c>
 *   @0x274b38 b 0x276128 <pcre_dfa_exec+0x7bc0>
 *   @0x274b3c ldrb r0, [r4, #0x1]
 *   @0x274b40 and r3, r3, #31
 *   @0x274b44 mov r2, #2
 *   @0x274b48 and r0, r0, #63
 *   @0x274b4c orr r3, r0, r3, lsl #6
 *   @0x274b50 cmp r7, r3
 *   @0x274b54 cmpne r5, r3
 *   @0x274b58 beq 0x274bf8 <pcre_dfa_exec+0x6690>
 *   @0x274b5c add r8, r8, #1
 *   @0x274b60 add r4, r4, r2
 *   @0x274b64 cmp r8, r1
 *   @0x274b68 beq 0x274bf8 <pcre_dfa_exec+0x6690>
 *   @0x274b6c cmp r4, r9
 *   @0x274b70 bhs 0x27612c <pcre_dfa_exec+0x7bc4>
 *   @0x274b74 ldrb r3, [r4]
 *   @0x274b78 cmp r3, #191
 *   @0x274b7c movls r2, #1
 *   @0x274b80 bls 0x274b50 <pcre_dfa_exec+0x65e8>
 *   @0x274b84 tst r3, #32
 *   @0x274b88 beq 0x274b3c <pcre_dfa_exec+0x65d4>
 *   @0x274b8c tst r3, #16
 *   @0x274b90 bne 0x274bbc <pcre_dfa_exec+0x6654>
 *   @0x274b94 lsl r2, r3, #12
 *   @0x274b98 ldrb r0, [r4, #0x1]
 *   @0x274b9c ldrb r3, [r4, #0x2]
 *   @0x274ba0 uxth r2, r2
 *   @0x274ba4 and r0, r0, #63
 *   @0x274ba8 and r3, r3, #63
 *   @0x274bac orr r3, r2, r3
 *   @0x274bb0 mov r2, #3
 *   @0x274bb4 orr r3, r3, r0, lsl #6
 *   @0x274bb8 b 0x274b50 <pcre_dfa_exec+0x65e8>
 *   @0x274bbc tst r3, #8
 *   @0x274bc0 bne 0x2752b4 <pcre_dfa_exec+0x6d4c>
 *   @0x274bc4 ldrb r12, [r4, #0x3]
 *   @0x274bc8 and r3, r3, #7
 *   @0x274bcc ldrb r2, [r4, #0x1]
 *   @0x274bd0 ldrb r0, [r4, #0x2]
 *   @0x274bd4 and r12, r12, #63
 *   @0x274bd8 and r2, r2, #63
 *   @0x274bdc orr r3, r12, r3, lsl #18
 *   @0x274be0 and r0, r0, #63
 *   @0x274be4 orr r3, r3, r2, lsl #12
 *   @0x274be8 mov r2, #4
 *   @0x274bec orr r3, r3, r0, lsl #6
 *   @0x274bf0 b 0x274b50 <pcre_dfa_exec+0x65e8>
 *   @0x274bf4 mov r4, r10
 *   @0x274bf8 ldr r1, [sp, #0x2c]
 *   @0x274bfc cmp r1, #0
 *   @0x274c00 bne 0x2732bc <pcre_dfa_exec+0x4d54>
 *   @0x274c04 cmp r4, r10
 *   @0x274c08 bls 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x274c0c ldr r5, [sp, #0x1c]
 *   @0x274c10 ldr r7, [sp, #0x18]
 *   @0x274c14 ldr r8, [sp, #0x164]
 *   @0x274c18 ldr r3, [sp, #0x168]
 *   @0x274c1c mov r0, r4
 *   @0x274c20 str r6, [sp]
 *   @0x274c24 mov r1, r11
 *   @0x274c28 add r3, r3, #1
 *   @0x274c2c str r8, [sp, #0x4]
 *   @0x274c30 str r3, [sp, #0x8]
 *   @0x274c34 mov r2, r5
 *   @0x274c38 mov r3, r7
 *   @0x274c3c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x274c40 cmp r0, #0
 *   @0x274c44 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x274c48 ldrb r3, [r4, #-0x1]
 *   @0x274c4c sub r2, r4, #1
 *   @0x274c50 and r3, r3, #192
 *   @0x274c54 cmp r3, #128
 *   @0x274c58 bne 0x27595c <pcre_dfa_exec+0x73f4>
 *   @0x274c5c sub r12, r4, #2
 *   @0x274c60 mov r4, r12
 *   @0x274c64 sub r12, r12, #1
 *   @0x274c68 ldrb r3, [r4]
 *   @0x274c6c and r3, r3, #192
 *   @0x274c70 cmp r3, #128
 *   @0x274c74 beq 0x274c60 <pcre_dfa_exec+0x66f8>
 *   @0x274c78 cmp r4, r10
 *   @0x274c7c bhi 0x274c18 <pcre_dfa_exec+0x66b0>
 *   @0x274c80 b 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x274c84 mov r3, r11
 *   @0x274c88 str r4, [sp, #0x1c]
 *   @0x274c8c str r5, [sp, #0x18]
 *   @0x274c90 ldrb r1, [r3, #0x1]
 *   @0x274c94 ldrb r2, [r3, #0x2]
 *   @0x274c98 orr r2, r2, r1, lsl #8
 *   @0x274c9c ldrb r2, [r3, r2]!
 *   @0x274ca0 cmp r2, #119
 *   @0x274ca4 beq 0x274c90 <pcre_dfa_exec+0x6728>
 *   @0x274ca8 mov r12, #1
 *   @0x274cac str r12, [sp, #0x50]
 *   @0x274cb0 ldr r7, [sp, #0x50]
 *   @0x274cb4 ldr r12, [sp, #0x4c]
 *   @0x274cb8 orrs r7, r7, r12
 *   @0x274cbc bne 0x26fc84 <pcre_dfa_exec+0x171c>
 *   @0x274cc0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x274cc4 mov r10, r5
 *   @0x274cc8 ldrb r5, [r11]
 *   @0x274ccc b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x274cd0 mov r4, r1
 *   @0x274cd4 b 0x27260c <pcre_dfa_exec+0x40a4>
 *   @0x274cd8 ldr r12, [sp, #0x18]
 *   @0x274cdc ldr r5, [r6, #0xc]
 *   @0x274ce0 cmp r12, r1
 *   @0x274ce4 addge r0, r5, r1, lsl #2
 *   @0x274ce8 bge 0x274d10 <pcre_dfa_exec+0x67a8>
 *   @0x274cec ldr r7, [sp, #0x18]
 *   @0x274cf0 add r0, r5, r1, lsl #2
 *   @0x274cf4 add r3, r5, r7, lsl #2
 *   @0x274cf8 cmp r3, r0
 *   @0x274cfc bhs 0x274d10 <pcre_dfa_exec+0x67a8>
 *   @0x274d00 mvn r12, #0
 *   @0x274d04 str r12, [r3], #4
 *   @0x274d08 cmp r0, r3
 *   @0x274d0c bhi 0x274d04 <pcre_dfa_exec+0x679c>
 *   @0x274d10 ldr r3, [r6, #0x10]
 *   @0x274d14 ldr r12, [sp, #0x18]
 *   @0x274d18 rsb r2, r2, r3
 *   @0x274d1c add r3, r1, #1
 *   @0x274d20 cmp r12, r1
 *   @0x274d24 ldr r12, [r6, #0x74]
 *   @0x274d28 ldr r2, [r5, r2, lsl #2]
 *   @0x274d2c addle r1, r1, #2
 *   @0x274d30 rsb r12, r12, r10
 *   @0x274d34 strle r1, [sp, #0x18]
 *   @0x274d38 str r2, [r0]
 *   @0x274d3c str r12, [r5, r3, lsl #2]
 *   @0x274d40 ldrb r5, [r11]
 *   @0x274d44 b 0x26fd4c <pcre_dfa_exec+0x17e4>
 *   @0x274d48 and r1, r0, #1
 *   @0x274d4c ldrb r2, [r10, #0x5]
 *   @0x274d50 ldrb r0, [r10, #0x1]
 *   @0x274d54 add r10, r10, #6
 *   @0x274d58 ldrb lr, [r10, #-0x4]
 *   @0x274d5c and r2, r2, #63
 *   @0x274d60 and r0, r0, #63
 *   @0x274d64 orr r2, r2, r1, lsl #30
 *   @0x274d68 ldrb r1, [r10, #-0x3]
 *   @0x274d6c and lr, lr, #63
 *   @0x274d70 orr r2, r2, r0, lsl #24
 *   @0x274d74 ldrb r0, [r10, #-0x2]
 *   @0x274d78 and r1, r1, #63
 *   @0x274d7c orr r2, r2, lr, lsl #18
 *   @0x274d80 and r0, r0, #63
 *   @0x274d84 orr r2, r2, r1, lsl #12
 *   @0x274d88 orr r0, r2, r0, lsl #6
 *   @0x274d8c b 0x270220 <pcre_dfa_exec+0x1cb8>
 *   @0x274d90 tst r3, #16
 *   @0x274d94 bne 0x275a68 <pcre_dfa_exec+0x7500>
 *   @0x274d98 lsl r2, r3, #12
 *   @0x274d9c ldrb r1, [r4, #0x1]
 *   @0x274da0 ldrb r3, [r4, #0x2]
 *   @0x274da4 uxth r2, r2
 *   @0x274da8 and r1, r1, #63
 *   @0x274dac and r3, r3, #63
 *   @0x274db0 orr r3, r2, r3
 *   @0x274db4 mov r2, #3
 *   @0x274db8 orr r3, r3, r1, lsl #6
 *   @0x274dbc b 0x272938 <pcre_dfa_exec+0x43d0>
 *   @0x274dc0 sub r3, r3, #8192
 *   @0x274dc4 sub r3, r3, #40
 *   @0x274dc8 cmp r3, #1
 *   @0x274dcc bls 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x274dd0 b 0x270380 <pcre_dfa_exec+0x1e18>
 *   @0x274dd4 tst r3, #16
 *   @0x274dd8 bne 0x2759ec <pcre_dfa_exec+0x7484>
 *   @0x274ddc lsl r2, r3, #12
 *   @0x274de0 ldrb r1, [r4, #0x1]
 *   @0x274de4 ldrb r3, [r4, #0x2]
 *   @0x274de8 uxth r2, r2
 *   @0x274dec and r1, r1, #63
 *   @0x274df0 and r3, r3, #63
 *   @0x274df4 orr r3, r2, r3
 *   @0x274df8 mov r2, #3
 *   @0x274dfc orr r3, r3, r1, lsl #6
 *   @0x274e00 b 0x272a30 <pcre_dfa_exec+0x44c8>
 *   @0x274e04 tst r3, #16
 *   @0x274e08 bne 0x275988 <pcre_dfa_exec+0x7420>
 *   @0x274e0c lsl r2, r3, #12
 *   @0x274e10 ldrb r1, [r4, #0x1]
 *   @0x274e14 ldrb r3, [r4, #0x2]
 *   @0x274e18 uxth r2, r2
 *   @0x274e1c and r1, r1, #63
 *   @0x274e20 and r3, r3, #63
 *   @0x274e24 orr r3, r2, r3
 *   @0x274e28 mov r2, #3
 *   @0x274e2c orr r3, r3, r1, lsl #6
 *   @0x274e30 b 0x2729b4 <pcre_dfa_exec+0x444c>
 *   @0x274e34 ldrb r2, [r11, #0x1]
 *   @0x274e38 ldrb r3, [r11, #0x2]
 *   @0x274e3c orr r3, r3, r2, lsl #8
 *   @0x274e40 add r11, r11, r3
 *   @0x274e44 ldrb r3, [r11]
 *   @0x274e48 cmp r3, #119
 *   @0x274e4c beq 0x270988 <pcre_dfa_exec+0x2420>
 *   @0x274e50 b 0x270a24 <pcre_dfa_exec+0x24bc>
 *   @0x274e54 mov r6, r7
 *   @0x274e58 mov r7, r11
 *   @0x274e5c cmp r5, r7
 *   @0x274e60 ldr r4, [sp, #0x30]
 *   @0x274e64 ldr r11, [sp, #0x4c]
 *   @0x274e68 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x274e6c cmp r4, #0
 *   @0x274e70 bne 0x278bc4 <pcre_dfa_exec+0xa65c>
 *   @0x274e74 cmp r7, r5
 *   @0x274e78 ble 0x278bbc <pcre_dfa_exec+0xa654>
 *   @0x274e7c ldr r9, [r6, #0x78]
 *   @0x274e80 cmp r10, r9
 *   @0x274e84 bhs 0x278a94 <pcre_dfa_exec+0xa52c>
 *   @0x274e88 mov r9, r10
 *   @0x274e8c str r10, [sp, #0x30]
 *   @0x274e90 str r11, [sp, #0x4c]
 *   @0x274e94 mov r10, r5
 *   @0x274e98 mov r11, r9
 *   @0x274e9c ldr r5, [sp, #0x28]
 *   @0x274ea0 mov r9, r6
 *   @0x274ea4 mov r6, r7
 *   @0x274ea8 ldr r7, [sp, #0x24]
 *   @0x274eac b 0x274ef4 <pcre_dfa_exec+0x698c>
 *   @0x274eb0 ldrb r2, [r11, #0x1]
 *   @0x274eb4 and r0, r0, #31
 *   @0x274eb8 mov r4, #2
 *   @0x274ebc and r2, r2, #63
 *   @0x274ec0 orr r0, r2, r0, lsl #6
 *   @0x274ec4 mov r1, r8
 *   @0x274ec8 mov r2, r5
 *   @0x274ecc bl 0x266cac <_pcre_xclass>
 *   @0x274ed0 cmp r0, #0
 *   @0x274ed4 beq 0x275aa8 <pcre_dfa_exec+0x7540>
 *   @0x274ed8 add r10, r10, #1
 *   @0x274edc add r11, r11, r4
 *   @0x274ee0 cmp r10, r6
 *   @0x274ee4 beq 0x275aa8 <pcre_dfa_exec+0x7540>
 *   @0x274ee8 ldr r2, [r9, #0x78]
 *   @0x274eec cmp r2, r11
 *   @0x274ef0 bls 0x2767fc <pcre_dfa_exec+0x8294>
 *   @0x274ef4 ldrb r0, [r11]
 *   @0x274ef8 cmp r0, #191
 *   @0x274efc movls r2, #0
 *   @0x274f00 andhi r2, r7, #1
 *   @0x274f04 cmp r2, #0
 *   @0x274f08 moveq r4, #1
 *   @0x274f0c beq 0x274ec4 <pcre_dfa_exec+0x695c>
 *   @0x274f10 tst r0, #32
 *   @0x274f14 beq 0x274eb0 <pcre_dfa_exec+0x6948>
 *   @0x274f18 tst r0, #16
 *   @0x274f1c bne 0x274f48 <pcre_dfa_exec+0x69e0>
 *   @0x274f20 lsl r1, r0, #12
 *   @0x274f24 ldrb r2, [r11, #0x2]
 *   @0x274f28 ldrb r0, [r11, #0x1]
 *   @0x274f2c mov r4, #3
 *   @0x274f30 uxth r1, r1
 *   @0x274f34 and r2, r2, #63
 *   @0x274f38 and r0, r0, #63
 *   @0x274f3c orr r2, r1, r2
 *   @0x274f40 orr r0, r2, r0, lsl #6
 *   @0x274f44 b 0x274ec4 <pcre_dfa_exec+0x695c>
 *   @0x274f48 tst r0, #8
 *   @0x274f4c bne 0x275a24 <pcre_dfa_exec+0x74bc>
 *   @0x274f50 ldrb r2, [r11, #0x3]
 *   @0x274f54 and lr, r0, #7
 *   @0x274f58 ldrb r1, [r11, #0x1]
 *   @0x274f5c mov r4, #4
 *   @0x274f60 ldrb r0, [r11, #0x2]
 *   @0x274f64 and r2, r2, #63
 *   @0x274f68 and r1, r1, #63
 *   @0x274f6c orr r2, r2, lr, lsl #18
 *   @0x274f70 and r0, r0, #63
 *   @0x274f74 orr r2, r2, r1, lsl #12
 *   @0x274f78 orr r0, r2, r0, lsl #6
 *   @0x274f7c b 0x274ec4 <pcre_dfa_exec+0x695c>
 *   @0x274f80 .word 0xfffffb8c
 *   @0x274f84 .word 0xfffffbb4
 *   @0x274f88 .word 0xfffffb94
 *   @0x274f8c .word 0xffffea38
 *   @0x274f90 tst r3, #16
 *   @0x274f94 bne 0x275d08 <pcre_dfa_exec+0x77a0>
 *   @0x274f98 lsl r2, r3, #12
 *   @0x274f9c ldrb r1, [r4, #0x1]
 *   @0x274fa0 ldrb r3, [r4, #0x2]
 *   @0x274fa4 uxth r2, r2
 *   @0x274fa8 and r1, r1, #63
 *   @0x274fac and r3, r3, #63
 *   @0x274fb0 orr r3, r2, r3
 *   @0x274fb4 mov r2, #3
 *   @0x274fb8 orr r3, r3, r1, lsl #6
 *   @0x274fbc b 0x2726b8 <pcre_dfa_exec+0x4150>
 *   @0x274fc0 tst r3, #16
 *   @0x274fc4 bne 0x275d4c <pcre_dfa_exec+0x77e4>
 *   @0x274fc8 lsl r2, r3, #12
 *   @0x274fcc ldrb r1, [r4, #0x1]
 *   @0x274fd0 ldrb r3, [r4, #0x2]
 *   @0x274fd4 uxth r2, r2
 *   @0x274fd8 and r1, r1, #63
 *   @0x274fdc and r3, r3, #63
 *   @0x274fe0 orr r3, r2, r3
 *   @0x274fe4 mov r2, #3
 *   @0x274fe8 orr r3, r3, r1, lsl #6
 *   @0x274fec b 0x272734 <pcre_dfa_exec+0x41cc>
 *   @0x274ff0 cmp r3, #13
 *   @0x274ff4 beq 0x275d84 <pcre_dfa_exec+0x781c>
 *   @0x274ff8 cmp r3, #133
 *   @0x274ffc bne 0x275e88 <pcre_dfa_exec+0x7920>
 *   @0x275000 ldr r3, [r6, #0x68]
 *   @0x275004 cmp r3, #0
 *   @0x275008 beq 0x273160 <pcre_dfa_exec+0x4bf8>
 *   @0x27500c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275010 cmp r3, #133
 *   @0x275014 beq 0x270784 <pcre_dfa_exec+0x221c>
 *   @0x275018 blo 0x27502c <pcre_dfa_exec+0x6ac4>
 *   @0x27501c sub r3, r3, #8192
 *   @0x275020 sub r3, r3, #40
 *   @0x275024 cmp r3, #1
 *   @0x275028 bls 0x270784 <pcre_dfa_exec+0x221c>
 *   @0x27502c mov r0, #0
 *   @0x275030 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275034 tst r3, #4
 *   @0x275038 bne 0x275c50 <pcre_dfa_exec+0x76e8>
 *   @0x27503c ldrb r0, [r4, #0x4]
 *   @0x275040 and r3, r3, #3
 *   @0x275044 ldrb r12, [r4, #0x1]
 *   @0x275048 and r0, r0, #63
 *   @0x27504c ldrb r2, [r4, #0x2]
 *   @0x275050 orr r3, r0, r3, lsl #24
 *   @0x275054 and r12, r12, #63
 *   @0x275058 ldrb r0, [r4, #0x3]
 *   @0x27505c and r2, r2, #63
 *   @0x275060 orr r3, r3, r12, lsl #18
 *   @0x275064 and r0, r0, #63
 *   @0x275068 orr r3, r3, r2, lsl #12
 *   @0x27506c mov r2, #5
 *   @0x275070 orr r3, r3, r0, lsl #6
 *   @0x275074 b 0x27488c <pcre_dfa_exec+0x6324>
 *   @0x275078 tst r3, #16
 *   @0x27507c bne 0x275c98 <pcre_dfa_exec+0x7730>
 *   @0x275080 lsl r2, r3, #12
 *   @0x275084 ldrb r1, [r4, #0x1]
 *   @0x275088 ldrb r3, [r4, #0x2]
 *   @0x27508c uxth r2, r2
 *   @0x275090 and r1, r1, #63
 *   @0x275094 and r3, r3, #63
 *   @0x275098 orr r3, r2, r3
 *   @0x27509c mov r2, #3
 *   @0x2750a0 orr r3, r3, r1, lsl #6
 *   @0x2750a4 b 0x2727b0 <pcre_dfa_exec+0x4248>
 *   @0x2750a8 ldr r3, [pc, #-0x12c]
 *   @0x2750ac ldr r12, [sp, #0x20]
 *   @0x2750b0 ldr r3, [r12, r3]
 *   @0x2750b4 ldr r2, [r3]
 *   @0x2750b8 cmp r2, #0
 *   @0x2750bc beq 0x275164 <pcre_dfa_exec+0x6bfc>
 *   @0x2750c0 ldr lr, [sp, #0x18]
 *   @0x2750c4 mov r1, #2
 *   @0x2750c8 ldr r3, [r6, #0x74]
 *   @0x2750cc str r1, [sp, #0x8c]
 *   @0x2750d0 add r12, lr, lr, lsr #31
 *   @0x2750d4 ldrb r0, [r11, #0x4]
 *   @0x2750d8 ldr lr, [sp, #0x1c]
 *   @0x2750dc str r3, [sp, #0x98]
 *   @0x2750e0 asr r12, r12, #1
 *   @0x2750e4 rsb r1, r3, lr
 *   @0x2750e8 str r1, [sp, #0xa0]
 *   @0x2750ec ldr r1, [r6, #0xc]
 *   @0x2750f0 str r0, [sp, #0x90]
 *   @0x2750f4 ldr r0, [r6, #0x78]
 *   @0x2750f8 str r1, [sp, #0x94]
 *   @0x2750fc rsb r1, r3, r10
 *   @0x275100 rsb r3, r3, r0
 *   @0x275104 str r1, [sp, #0xa4]
 *   @0x275108 str r3, [sp, #0x9c]
 *   @0x27510c ldrb r0, [r11, #0x5]
 *   @0x275110 ldrb r1, [r11, #0x6]
 *   @0x275114 ldrh r3, [r6, #144]
 *   @0x275118 orr r1, r1, r0, lsl #8
 *   @0x27511c str r1, [sp, #0xb4]
 *   @0x275120 ldrb r0, [r11, #0x7]
 *   @0x275124 cmp r3, #0
 *   @0x275128 ldrb r1, [r11, #0x8]
 *   @0x27512c mvneq r3, #0
 *   @0x275130 str r3, [sp, #0xac]
 *   @0x275134 orr r1, r1, r0, lsl #8
 *   @0x275138 ldr r3, [r6, #0xb0]
 *   @0x27513c str r1, [sp, #0xb8]
 *   @0x275140 add r0, sp, #140
 *   @0x275144 ldr r1, [r6, #0xa8]
 *   @0x275148 str r12, [sp, #0xa8]
 *   @0x27514c str r3, [sp, #0xbc]
 *   @0x275150 str r1, [sp, #0xb0]
 *   @0x275154 blx r2
 *   @0x275158 cmp r0, #0
 *   @0x27515c bgt 0x278ba0 <pcre_dfa_exec+0xa638>
 *   @0x275160 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275164 ldrb r8, [r11, #0x9]
 *   @0x275168 sub r7, r7, #6
 *   @0x27516c add r4, r11, #9
 *   @0x275170 b 0x26fad8 <pcre_dfa_exec+0x1570>
 *   @0x275174 tst r3, #8
 *   @0x275178 bne 0x275e90 <pcre_dfa_exec+0x7928>
 *   @0x27517c ldrb r12, [r10, #0x3]
 *   @0x275180 and r3, r3, #7
 *   @0x275184 ldrb r0, [r10, #0x1]
 *   @0x275188 add r10, r10, #4
 *   @0x27518c ldrb r1, [r10, #-0x2]
 *   @0x275190 and r12, r12, #63
 *   @0x275194 and r0, r0, #63
 *   @0x275198 orr r3, r12, r3, lsl #18
 *   @0x27519c and r1, r1, #63
 *   @0x2751a0 orr r3, r3, r0, lsl #12
 *   @0x2751a4 orr r3, r3, r1, lsl #6
 *   @0x2751a8 b 0x272054 <pcre_dfa_exec+0x3aec>
 *   @0x2751ac subs r8, r2, r0
 *   @0x2751b0 rsbs r2, r8, #0
 *   @0x2751b4 adcs r2, r2, r8
 *   @0x2751b8 b 0x2708cc <pcre_dfa_exec+0x2364>
 *   @0x2751bc tst r3, #16
 *   @0x2751c0 bne 0x275e50 <pcre_dfa_exec+0x78e8>
 *   @0x2751c4 lsl r2, r3, #12
 *   @0x2751c8 ldrb r1, [r4, #0x1]
 *   @0x2751cc ldrb r3, [r4, #0x2]
 *   @0x2751d0 uxth r2, r2
 *   @0x2751d4 and r1, r1, #63
 *   @0x2751d8 and r3, r3, #63
 *   @0x2751dc orr r3, r2, r3
 *   @0x2751e0 mov r2, #3
 *   @0x2751e4 orr r3, r3, r1, lsl #6
 *   @0x2751e8 b 0x272350 <pcre_dfa_exec+0x3de8>
 *   @0x2751ec tst r3, #16
 *   @0x2751f0 bne 0x275cd0 <pcre_dfa_exec+0x7768>
 *   @0x2751f4 lsl r2, r3, #12
 *   @0x2751f8 ldrb r1, [r4, #0x1]
 *   @0x2751fc ldrb r3, [r4, #0x2]
 *   @0x275200 uxth r2, r2
 *   @0x275204 and r1, r1, #63
 *   @0x275208 and r3, r3, #63
 *   @0x27520c orr r3, r2, r3
 *   @0x275210 mov r2, #3
 *   @0x275214 orr r3, r3, r1, lsl #6
 *   @0x275218 b 0x272414 <pcre_dfa_exec+0x3eac>
 *   @0x27521c movw r2, #0x205f
 *   @0x275220 cmp r3, r2
 *   @0x275224 beq 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x275228 cmp r3, #12288
 *   @0x27522c bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x275230 b 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x275234 ldrb r3, [r10]
 *   @0x275238 cmp r3, #191
 *   @0x27523c bls 0x275260 <pcre_dfa_exec+0x6cf8>
 *   @0x275240 tst r3, #32
 *   @0x275244 bne 0x2769a4 <pcre_dfa_exec+0x843c>
 *   @0x275248 ldrb r2, [r10, #0x1]
 *   @0x27524c and r3, r3, #31
 *   @0x275250 and r2, r2, #63
 *   @0x275254 orr r3, r2, r3, lsl #6
 *   @0x275258 cmp r3, #255
 *   @0x27525c bhi 0x2708b0 <pcre_dfa_exec+0x2348>
 *   @0x275260 ldr r2, [r6, #0x40]
 *   @0x275264 ldrb r2, [r2, r3]
 *   @0x275268 ubfx r2, r2, #0x4, #0x1
 *   @0x27526c b 0x2708b4 <pcre_dfa_exec+0x234c>
 *   @0x275270 ldrb r3, [r10]
 *   @0x275274 b 0x275260 <pcre_dfa_exec+0x6cf8>
 *   @0x275278 cmp r3, #160
 *   @0x27527c beq 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x275280 cmp r3, #5760
 *   @0x275284 bne 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x275288 b 0x270a9c <pcre_dfa_exec+0x2534>
 *   @0x27528c ldr r3, [r6, #0x1c]
 *   @0x275290 rsb r9, r3, r9
 *   @0x275294 cmp r10, r9
 *   @0x275298 bhi 0x2752ac <pcre_dfa_exec+0x6d44>
 *   @0x27529c ldrb r0, [r10]
 *   @0x2752a0 ldrb r2, [r6, #0x34]
 *   @0x2752a4 cmp r0, r2
 *   @0x2752a8 beq 0x277730 <pcre_dfa_exec+0x91c8>
 *   @0x2752ac mov r0, #1
 *   @0x2752b0 b 0x2717d4 <pcre_dfa_exec+0x326c>
 *   @0x2752b4 tst r3, #4
 *   @0x2752b8 bne 0x276304 <pcre_dfa_exec+0x7d9c>
 *   @0x2752bc ldrb r0, [r4, #0x4]
 *   @0x2752c0 and r3, r3, #3
 *   @0x2752c4 ldrb r12, [r4, #0x1]
 *   @0x2752c8 and r0, r0, #63
 *   @0x2752cc ldrb r2, [r4, #0x2]
 *   @0x2752d0 orr r3, r0, r3, lsl #24
 *   @0x2752d4 and r12, r12, #63
 *   @0x2752d8 ldrb r0, [r4, #0x3]
 *   @0x2752dc and r2, r2, #63
 *   @0x2752e0 orr r3, r3, r12, lsl #18
 *   @0x2752e4 and r0, r0, #63
 *   @0x2752e8 orr r3, r3, r2, lsl #12
 *   @0x2752ec mov r2, #5
 *   @0x2752f0 orr r3, r3, r0, lsl #6
 *   @0x2752f4 b 0x274b50 <pcre_dfa_exec+0x65e8>
 *   @0x2752f8 tst r3, #16
 *   @0x2752fc bne 0x276080 <pcre_dfa_exec+0x7b18>
 *   @0x275300 lsl r1, r3, #12
 *   @0x275304 ldrb r2, [r10, #0x1]
 *   @0x275308 ldrb r3, [r10, #0x2]
 *   @0x27530c add r10, r10, #3
 *   @0x275310 uxth r1, r1
 *   @0x275314 and r2, r2, #63
 *   @0x275318 and r3, r3, #63
 *   @0x27531c orr r3, r1, r3
 *   @0x275320 orr r3, r3, r2, lsl #6
 *   @0x275324 b 0x270368 <pcre_dfa_exec+0x1e00>
 *   @0x275328 tst r3, #16
 *   @0x27532c bne 0x2763bc <pcre_dfa_exec+0x7e54>
 *   @0x275330 lsl r1, r3, #12
 *   @0x275334 ldrb r2, [r10, #0x1]
 *   @0x275338 ldrb r3, [r10, #0x2]
 *   @0x27533c add r10, r10, #3
 *   @0x275340 uxth r1, r1
 *   @0x275344 and r2, r2, #63
 *   @0x275348 and r3, r3, #63
 *   @0x27534c orr r3, r1, r3
 *   @0x275350 orr r3, r3, r2, lsl #6
 *   @0x275354 b 0x2707dc <pcre_dfa_exec+0x2274>
 *   @0x275358 tst r3, #16
 *   @0x27535c bne 0x2760f0 <pcre_dfa_exec+0x7b88>
 *   @0x275360 lsl r1, r3, #12
 *   @0x275364 ldrb r2, [r10, #0x1]
 *   @0x275368 ldrb r3, [r10, #0x2]
 *   @0x27536c add r10, r10, #3
 *   @0x275370 uxth r1, r1
 *   @0x275374 and r2, r2, #63
 *   @0x275378 and r3, r3, #63
 *   @0x27537c orr r3, r1, r3
 *   @0x275380 orr r3, r3, r2, lsl #6
 *   @0x275384 b 0x2703d0 <pcre_dfa_exec+0x1e68>
 *   @0x275388 ldrb r2, [r10]
 *   @0x27538c cmp r2, #191
 *   @0x275390 addls r10, r10, #1
 *   @0x275394 bls 0x2753b4 <pcre_dfa_exec+0x6e4c>
 *   @0x275398 tst r2, #32
 *   @0x27539c bne 0x276a28 <pcre_dfa_exec+0x84c0>
 *   @0x2753a0 ldrb r0, [r10, #0x1]
 *   @0x2753a4 and r2, r2, #31
 *   @0x2753a8 add r10, r10, #2
 *   @0x2753ac and r0, r0, #63
 *   @0x2753b0 orr r2, r0, r2, lsl #6
 *   @0x2753b4 cmp r3, r2
 *   @0x2753b8 add r3, r11, #1
 *   @0x2753bc add r11, r3, r1
 *   @0x2753c0 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2753c4 ldrb r5, [r3, r1]
 *   @0x2753c8 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x2753cc cmp r10, r9
 *   @0x2753d0 bhs 0x274494 <pcre_dfa_exec+0x5f2c>
 *   @0x2753d4 ldrb r3, [r10]
 *   @0x2753d8 cmp r3, #10
 *   @0x2753dc addeq r10, r10, #1
 *   @0x2753e0 b 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2753e4 tst r3, #16
 *   @0x2753e8 bne 0x276158 <pcre_dfa_exec+0x7bf0>
 *   @0x2753ec lsl r1, r3, #12
 *   @0x2753f0 ldrb r2, [r10, #0x1]
 *   @0x2753f4 ldrb r3, [r10, #0x2]
 *   @0x2753f8 add r10, r10, #3
 *   @0x2753fc uxth r1, r1
 *   @0x275400 and r2, r2, #63
 *   @0x275404 and r3, r3, #63
 *   @0x275408 orr r3, r1, r3
 *   @0x27540c orr r3, r3, r2, lsl #6
 *   @0x275410 b 0x270a78 <pcre_dfa_exec+0x2510>
 *   @0x275414 tst r3, #16
 *   @0x275418 bne 0x276190 <pcre_dfa_exec+0x7c28>
 *   @0x27541c lsl r1, r3, #12
 *   @0x275420 ldrb r2, [r10, #0x1]
 *   @0x275424 ldrb r3, [r10, #0x2]
 *   @0x275428 add r10, r10, #3
 *   @0x27542c uxth r1, r1
 *   @0x275430 and r2, r2, #63
 *   @0x275434 and r3, r3, #63
 *   @0x275438 orr r3, r1, r3
 *   @0x27543c orr r3, r3, r2, lsl #6
 *   @0x275440 b 0x270938 <pcre_dfa_exec+0x23d0>
 *   @0x275444 tst r3, #16
 *   @0x275448 bne 0x276048 <pcre_dfa_exec+0x7ae0>
 *   @0x27544c lsl r1, r3, #12
 *   @0x275450 ldrb r2, [r10, #0x1]
 *   @0x275454 ldrb r3, [r10, #0x2]
 *   @0x275458 add r10, r10, #3
 *   @0x27545c uxth r1, r1
 *   @0x275460 and r2, r2, #63
 *   @0x275464 and r3, r3, #63
 *   @0x275468 orr r3, r1, r3
 *   @0x27546c orr r3, r3, r2, lsl #6
 *   @0x275470 b 0x270d18 <pcre_dfa_exec+0x27b0>
 *   @0x275474 tst r3, #16
 *   @0x275478 bne 0x276010 <pcre_dfa_exec+0x7aa8>
 *   @0x27547c lsl r1, r3, #12
 *   @0x275480 ldrb r2, [r10, #0x1]
 *   @0x275484 ldrb r3, [r10, #0x2]
 *   @0x275488 add r10, r10, #3
 *   @0x27548c uxth r1, r1
 *   @0x275490 and r2, r2, #63
 *   @0x275494 and r3, r3, #63
 *   @0x275498 orr r3, r1, r3
 *   @0x27549c orr r3, r3, r2, lsl #6
 *   @0x2754a0 b 0x27076c <pcre_dfa_exec+0x2204>
 *   @0x2754a4 tst r3, #16
 *   @0x2754a8 bne 0x2762cc <pcre_dfa_exec+0x7d64>
 *   @0x2754ac lsl r1, r3, #12
 *   @0x2754b0 ldrb r2, [r10, #0x1]
 *   @0x2754b4 ldrb r3, [r10, #0x2]
 *   @0x2754b8 add r10, r10, #3
 *   @0x2754bc uxth r1, r1
 *   @0x2754c0 and r2, r2, #63
 *   @0x2754c4 and r3, r3, #63
 *   @0x2754c8 orr r3, r1, r3
 *   @0x2754cc orr r3, r3, r2, lsl #6
 *   @0x2754d0 b 0x270708 <pcre_dfa_exec+0x21a0>
 *   @0x2754d4 tst r3, #16
 *   @0x2754d8 bne 0x27634c <pcre_dfa_exec+0x7de4>
 *   @0x2754dc lsl r1, r3, #12
 *   @0x2754e0 ldrb r2, [r10, #0x1]
 *   @0x2754e4 ldrb r3, [r10, #0x2]
 *   @0x2754e8 add r10, r10, #3
 *   @0x2754ec uxth r1, r1
 *   @0x2754f0 and r2, r2, #63
 *   @0x2754f4 and r3, r3, #63
 *   @0x2754f8 orr r3, r1, r3
 *   @0x2754fc orr r3, r3, r2, lsl #6
 *   @0x275500 b 0x270bec <pcre_dfa_exec+0x2684>
 *   @0x275504 tst r3, #16
 *   @0x275508 bne 0x276384 <pcre_dfa_exec+0x7e1c>
 *   @0x27550c lsl r1, r3, #12
 *   @0x275510 ldrb r2, [r10, #0x1]
 *   @0x275514 ldrb r3, [r10, #0x2]
 *   @0x275518 add r10, r10, #3
 *   @0x27551c uxth r1, r1
 *   @0x275520 and r2, r2, #63
 *   @0x275524 and r3, r3, #63
 *   @0x275528 orr r3, r1, r3
 *   @0x27552c orr r3, r3, r2, lsl #6
 *   @0x275530 b 0x270c50 <pcre_dfa_exec+0x26e8>
 *   @0x275534 tst r3, #16
 *   @0x275538 bne 0x2760b8 <pcre_dfa_exec+0x7b50>
 *   @0x27553c lsl r1, r3, #12
 *   @0x275540 ldrb r2, [r10, #0x1]
 *   @0x275544 ldrb r3, [r10, #0x2]
 *   @0x275548 add r10, r10, #3
 *   @0x27554c uxth r1, r1
 *   @0x275550 and r2, r2, #63
 *   @0x275554 and r3, r3, #63
 *   @0x275558 orr r3, r1, r3
 *   @0x27555c orr r3, r3, r2, lsl #6
 *   @0x275560 b 0x270cb4 <pcre_dfa_exec+0x274c>
 *   @0x275564 ldrb r4, [r10, #0x5]
 *   @0x275568 and r3, r3, #1
 *   @0x27556c ldrb r1, [r10, #0x1]
 *   @0x275570 add r10, r10, #6
 *   @0x275574 and r4, r4, #63
 *   @0x275578 ldrb r7, [r10, #-0x4]
 *   @0x27557c and r1, r1, #63
 *   @0x275580 orr r3, r4, r3, lsl #30
 *   @0x275584 ldrb r4, [r10, #-0x3]
 *   @0x275588 and r7, r7, #63
 *   @0x27558c orr r3, r3, r1, lsl #24
 *   @0x275590 ldrb r1, [r10, #-0x2]
 *   @0x275594 and r4, r4, #63
 *   @0x275598 orr r3, r3, r7, lsl #18
 *   @0x27559c and r1, r1, #63
 *   @0x2755a0 orr r3, r3, r4, lsl #12
 *   @0x2755a4 orr r3, r3, r1, lsl #6
 *   @0x2755a8 b 0x2743c8 <pcre_dfa_exec+0x5e60>
 *   @0x2755ac tst r3, #8
 *   @0x2755b0 bne 0x2764dc <pcre_dfa_exec+0x7f74>
 *   @0x2755b4 ldrb r12, [r10, #0x3]
 *   @0x2755b8 and r3, r3, #7
 *   @0x2755bc ldrb r0, [r10, #0x1]
 *   @0x2755c0 add r10, r10, #4
 *   @0x2755c4 ldrb r1, [r10, #-0x2]
 *   @0x2755c8 and r12, r12, #63
 *   @0x2755cc and r0, r0, #63
 *   @0x2755d0 orr r3, r12, r3, lsl #18
 *   @0x2755d4 and r1, r1, #63
 *   @0x2755d8 orr r3, r3, r0, lsl #12
 *   @0x2755dc orr r3, r3, r1, lsl #6
 *   @0x2755e0 b 0x271b6c <pcre_dfa_exec+0x3604>
 *   @0x2755e4 ldr r12, [sp, #0x20]
 *   @0x2755e8 lsl r0, r2, #2
 *   @0x2755ec ldr r3, [pc, #-0x66c]
 *   @0x2755f0 ldr r3, [r12, r3]
 *   @0x2755f4 ldr r3, [r3]
 *   @0x2755f8 blx r3
 *   @0x2755fc cmp r0, #0
 *   @0x275600 str r0, [sp, #0x7c]
 *   @0x275604 beq 0x278ccc <pcre_dfa_exec+0xa764>
 *   @0x275608 add r12, sp, #192
 *   @0x27560c ldr r2, [sp, #0x80]
 *   @0x275610 str r12, [sp, #0x2c]
 *   @0x275614 b 0x273f90 <pcre_dfa_exec+0x5a28>
 *   @0x275618 tst r3, #8
 *   @0x27561c bne 0x276454 <pcre_dfa_exec+0x7eec>
 *   @0x275620 ldrb r4, [r10, #0x3]
 *   @0x275624 and r3, r3, #7
 *   @0x275628 ldrb r12, [r10, #0x1]
 *   @0x27562c add r10, r10, #4
 *   @0x275630 ldrb r0, [r10, #-0x2]
 *   @0x275634 and r4, r4, #63
 *   @0x275638 and r12, r12, #63
 *   @0x27563c orr r3, r4, r3, lsl #18
 *   @0x275640 and r0, r0, #63
 *   @0x275644 orr r3, r3, r12, lsl #12
 *   @0x275648 orr r3, r3, r0, lsl #6
 *   @0x27564c b 0x271bfc <pcre_dfa_exec+0x3694>
 *   @0x275650 tst r3, #8
 *   @0x275654 bne 0x276400 <pcre_dfa_exec+0x7e98>
 *   @0x275658 ldrb r4, [r10, #0x3]
 *   @0x27565c and r3, r3, #7
 *   @0x275660 ldrb r12, [r10, #0x1]
 *   @0x275664 add r10, r10, #4
 *   @0x275668 ldrb r0, [r10, #-0x2]
 *   @0x27566c and r4, r4, #63
 *   @0x275670 and r12, r12, #63
 *   @0x275674 orr r3, r4, r3, lsl #18
 *   @0x275678 and r0, r0, #63
 *   @0x27567c orr r3, r3, r12, lsl #12
 *   @0x275680 orr r3, r3, r0, lsl #6
 *   @0x275684 b 0x271ae4 <pcre_dfa_exec+0x357c>
 *   @0x275688 ldrb r3, [r11]
 *   @0x27568c ldrb r3, [r7, r3]
 *   @0x275690 add r11, r11, r3
 *   @0x275694 b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x275698 tst r3, #8
 *   @0x27569c bne 0x276498 <pcre_dfa_exec+0x7f30>
 *   @0x2756a0 ldrb r12, [r10, #0x3]
 *   @0x2756a4 and r3, r3, #7
 *   @0x2756a8 ldrb r0, [r10, #0x1]
 *   @0x2756ac add r10, r10, #4
 *   @0x2756b0 ldrb r1, [r10, #-0x2]
 *   @0x2756b4 and r12, r12, #63
 *   @0x2756b8 and r0, r0, #63
 *   @0x2756bc orr r3, r12, r3, lsl #18
 *   @0x2756c0 and r1, r1, #63
 *   @0x2756c4 orr r3, r3, r0, lsl #12
 *   @0x2756c8 orr r3, r3, r1, lsl #6
 *   @0x2756cc b 0x271c8c <pcre_dfa_exec+0x3724>
 *   @0x2756d0 ldrb r2, [r3, #0x5]
 *   @0x2756d4 and r7, r7, #1
 *   @0x2756d8 ldrb r4, [r3, #0x1]
 *   @0x2756dc add r11, r3, #6
 *   @0x2756e0 ldrb r12, [r3, #0x2]
 *   @0x2756e4 and r2, r2, #63
 *   @0x2756e8 ldrb r0, [r3, #0x3]
 *   @0x2756ec and r4, r4, #63
 *   @0x2756f0 orr r2, r2, r7, lsl #30
 *   @0x2756f4 and r12, r12, #63
 *   @0x2756f8 ldrb r7, [r3, #0x4]
 *   @0x2756fc orr r2, r2, r4, lsl #24
 *   @0x275700 and r0, r0, #63
 *   @0x275704 orr r2, r2, r12, lsl #18
 *   @0x275708 and r7, r7, #63
 *   @0x27570c orr r3, r2, r0, lsl #12
 *   @0x275710 orr r7, r3, r7, lsl #6
 *   @0x275714 b 0x270e2c <pcre_dfa_exec+0x28c4>
 *   @0x275718 ldr r12, [sp, #0x28]
 *   @0x27571c mov r2, r9
 *   @0x275720 mov r0, r4
 *   @0x275724 ldr r3, [sp, #0x2c]
 *   @0x275728 str r12, [sp]
 *   @0x27572c bl 0x25f9fc <_pcre_is_newline>
 *   @0x275730 adds r0, r0, #0
 *   @0x275734 movne r0, #1
 *   @0x275738 b 0x2725e0 <pcre_dfa_exec+0x4078>
 *   @0x27573c ldr r2, [r6, #0x40]
 *   @0x275740 ldrb r0, [r2, r3]
 *   @0x275744 ubfx r0, r0, #0x4, #0x1
 *   @0x275748 b 0x27087c <pcre_dfa_exec+0x2314>
 *   @0x27574c sub r3, r3, #8192
 *   @0x275750 cmp r3, #10
 *   @0x275754 bls 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x275758 b 0x271c2c <pcre_dfa_exec+0x36c4>
 *   @0x27575c cmp r3, #9
 *   @0x275760 beq 0x271bbc <pcre_dfa_exec+0x3654>
 *   @0x275764 b 0x271c2c <pcre_dfa_exec+0x36c4>
 *   @0x275768 tst r3, #8
 *   @0x27576c bne 0x276564 <pcre_dfa_exec+0x7ffc>
 *   @0x275770 ldrb r0, [r4, #0x3]
 *   @0x275774 and r3, r3, #7
 *   @0x275778 ldrb r2, [r4, #0x1]
 *   @0x27577c ldrb r1, [r4, #0x2]
 *   @0x275780 and r0, r0, #63
 *   @0x275784 and r2, r2, #63
 *   @0x275788 orr r3, r0, r3, lsl #18
 *   @0x27578c and r1, r1, #63
 *   @0x275790 orr r3, r3, r2, lsl #12
 *   @0x275794 mov r2, #4
 *   @0x275798 orr r3, r3, r1, lsl #6
 *   @0x27579c b 0x272888 <pcre_dfa_exec+0x4320>
 *   @0x2757a0 mov r3, #0
 *   @0x2757a4 mov r0, r8
 *   @0x2757a8 str r3, [sp]
 *   @0x2757ac ldr r3, [sp, #0x2c]
 *   @0x2757b0 bl 0x25f9fc <_pcre_is_newline>
 *   @0x2757b4 adds r0, r0, #0
 *   @0x2757b8 movne r0, #1
 *   @0x2757bc b 0x2737fc <pcre_dfa_exec+0x5294>
 *   @0x2757c0 mov r4, r2
 *   @0x2757c4 b 0x2749b0 <pcre_dfa_exec+0x6448>
 *   @0x2757c8 cmp r3, #9
 *   @0x2757cc bne 0x2723c0 <pcre_dfa_exec+0x3e58>
 *   @0x2757d0 b 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x2757d4 sub r3, r3, #8192
 *   @0x2757d8 cmp r3, #10
 *   @0x2757dc bhi 0x2723c0 <pcre_dfa_exec+0x3e58>
 *   @0x2757e0 b 0x272444 <pcre_dfa_exec+0x3edc>
 *   @0x2757e4 ldr r6, [sp, #0x4c]
 *   @0x2757e8 b 0x273ef0 <pcre_dfa_exec+0x5988>
 *   @0x2757ec ldr r0, [sp, #0x7c]
 *   @0x2757f0 ldr r12, [sp, #0x2c]
 *   @0x2757f4 cmp r0, r12
 *   @0x2757f8 moveq r0, r8
 *   @0x2757fc beq 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275800 ldr r5, [sp, #0x20]
 *   @0x275804 ldr r2, [pc, #-0x880]
 *   @0x275808 ldr r2, [r5, r2]
 *   @0x27580c ldr r2, [r2]
 *   @0x275810 str r8, [sp, #0x14]
 *   @0x275814 blx r2
 *   @0x275818 ldr r3, [sp, #0x14]
 *   @0x27581c mov r0, r3
 *   @0x275820 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275824 ldr r0, [sp, #0x7c]
 *   @0x275828 ldr r5, [sp, #0x2c]
 *   @0x27582c cmp r0, r5
 *   @0x275830 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275834 ldr r7, [sp, #0x20]
 *   @0x275838 ldr r3, [pc, #-0x8b4]
 *   @0x27583c ldr r3, [r7, r3]
 *   @0x275840 ldr r3, [r3]
 *   @0x275844 blx r3
 *   @0x275848 mov r0, #0
 *   @0x27584c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275850 mov r10, r3
 *   @0x275854 b 0x271e64 <pcre_dfa_exec+0x38fc>
 *   @0x275858 ldr r7, [sp, #0x50]
 *   @0x27585c str r5, [sp, #0x18]
 *   @0x275860 cmp r7, #0
 *   @0x275864 str r4, [sp, #0x1c]
 *   @0x275868 ldr r5, [sp, #0x30]
 *   @0x27586c bne 0x278fbc <pcre_dfa_exec+0xaa54>
 *   @0x275870 ldr r2, [r6, #0xc]
 *   @0x275874 mov r3, r11
 *   @0x275878 ldr r12, [sp, #0x5c]
 *   @0x27587c ldr r7, [sp, #0x58]
 *   @0x275880 str r12, [r2, r5, lsl #3]
 *   @0x275884 ldr r12, [sp, #0x60]
 *   @0x275888 str r12, [r2, r7]
 *   @0x27588c ldr r1, [r6, #0x10]
 *   @0x275890 ldr r7, [sp, #0x64]
 *   @0x275894 rsb r5, r5, r1
 *   @0x275898 str r7, [r2, r5, lsl #2]
 *   @0x27589c b 0x274cb0 <pcre_dfa_exec+0x6748>
 *   @0x2758a0 mov r6, r4
 *   @0x2758a4 ldr r0, [sp, #0x7c]
 *   @0x2758a8 ldr r7, [sp, #0x2c]
 *   @0x2758ac str r2, [r6, #0xa4]
 *   @0x2758b0 cmp r0, r7
 *   @0x2758b4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2758b8 ldr r12, [sp, #0x20]
 *   @0x2758bc ldr r3, [pc, #-0x938]
 *   @0x2758c0 ldr r3, [r12, r3]
 *   @0x2758c4 ldr r3, [r3]
 *   @0x2758c8 blx r3
 *   @0x2758cc mov r0, #0
 *   @0x2758d0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2758d4 mov r10, r3
 *   @0x2758d8 b 0x272024 <pcre_dfa_exec+0x3abc>
 *   @0x2758dc mov r10, r8
 *   @0x2758e0 ldr r2, [r6, #0x88]
 *   @0x2758e4 cmp r2, #0
 *   @0x2758e8 beq 0x273258 <pcre_dfa_exec+0x4cf0>
 *   @0x2758ec ldr r3, [r6, #0x84]
 *   @0x2758f0 cmp r3, r10
 *   @0x2758f4 bhs 0x273258 <pcre_dfa_exec+0x4cf0>
 *   @0x2758f8 cmp r2, #1
 *   @0x2758fc mov r5, #1
 *   @0x275900 str r5, [r6, #0x64]
 *   @0x275904 ble 0x273258 <pcre_dfa_exec+0x4cf0>
 *   @0x275908 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x27590c mov r10, r8
 *   @0x275910 ldr r2, [r6, #0x88]
 *   @0x275914 cmp r2, #0
 *   @0x275918 beq 0x272bc0 <pcre_dfa_exec+0x4658>
 *   @0x27591c ldr r3, [r6, #0x84]
 *   @0x275920 cmp r3, r10
 *   @0x275924 bhs 0x272bc0 <pcre_dfa_exec+0x4658>
 *   @0x275928 cmp r2, #1
 *   @0x27592c mov r7, #1
 *   @0x275930 str r7, [r6, #0x64]
 *   @0x275934 ble 0x272bc0 <pcre_dfa_exec+0x4658>
 *   @0x275938 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x27593c cmp r3, #1
 *   @0x275940 beq 0x2773c8 <pcre_dfa_exec+0x8e60>
 *   @0x275944 ldrb r1, [r10, #0x1]
 *   @0x275948 ldrb r3, [r6, #0x35]
 *   @0x27594c subs r12, r1, r3
 *   @0x275950 rsbs r1, r12, #0
 *   @0x275954 adcs r1, r1, r12
 *   @0x275958 b 0x273cf4 <pcre_dfa_exec+0x578c>
 *   @0x27595c mov r4, r2
 *   @0x275960 b 0x274c78 <pcre_dfa_exec+0x6710>
 *   @0x275964 cmp r3, #1
 *   @0x275968 moveq r1, r3
 *   @0x27596c beq 0x272ecc <pcre_dfa_exec+0x4964>
 *   @0x275970 ldrb r1, [r10, #0x1]
 *   @0x275974 ldrb r3, [r6, #0x35]
 *   @0x275978 subs r0, r1, r3
 *   @0x27597c rsbs r1, r0, #0
 *   @0x275980 adcs r1, r1, r0
 *   @0x275984 b 0x272ecc <pcre_dfa_exec+0x4964>
 *   @0x275988 tst r3, #8
 *   @0x27598c bne 0x276718 <pcre_dfa_exec+0x81b0>
 *   @0x275990 ldrb r0, [r4, #0x3]
 *   @0x275994 and r3, r3, #7
 *   @0x275998 ldrb r2, [r4, #0x1]
 *   @0x27599c ldrb r1, [r4, #0x2]
 *   @0x2759a0 and r0, r0, #63
 *   @0x2759a4 and r2, r2, #63
 *   @0x2759a8 orr r3, r0, r3, lsl #18
 *   @0x2759ac and r1, r1, #63
 *   @0x2759b0 orr r3, r3, r2, lsl #12
 *   @0x2759b4 mov r2, #4
 *   @0x2759b8 orr r3, r3, r1, lsl #6
 *   @0x2759bc b 0x2729b4 <pcre_dfa_exec+0x444c>
 *   @0x2759c0 cmp r3, #133
 *   @0x2759c4 beq 0x2759dc <pcre_dfa_exec+0x7474>
 *   @0x2759c8 blo 0x275d44 <pcre_dfa_exec+0x77dc>
 *   @0x2759cc sub r3, r3, #8192
 *   @0x2759d0 sub r3, r3, #40
 *   @0x2759d4 cmp r3, #1
 *   @0x2759d8 bhi 0x275d44 <pcre_dfa_exec+0x77dc>
 *   @0x2759dc ldr r3, [r6, #0x68]
 *   @0x2759e0 cmp r3, #0
 *   @0x2759e4 beq 0x271f40 <pcre_dfa_exec+0x39d8>
 *   @0x2759e8 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2759ec tst r3, #8
 *   @0x2759f0 bne 0x27666c <pcre_dfa_exec+0x8104>
 *   @0x2759f4 ldrb r2, [r4, #0x3]
 *   @0x2759f8 and r0, r3, #7
 *   @0x2759fc ldrb r1, [r4, #0x1]
 *   @0x275a00 ldrb r3, [r4, #0x2]
 *   @0x275a04 and r2, r2, #63
 *   @0x275a08 and r1, r1, #63
 *   @0x275a0c orr r2, r2, r0, lsl #18
 *   @0x275a10 and r3, r3, #63
 *   @0x275a14 orr r1, r2, r1, lsl #12
 *   @0x275a18 mov r2, #4
 *   @0x275a1c orr r3, r1, r3, lsl #6
 *   @0x275a20 b 0x272a30 <pcre_dfa_exec+0x44c8>
 *   @0x275a24 tst r0, #4
 *   @0x275a28 bne 0x276624 <pcre_dfa_exec+0x80bc>
 *   @0x275a2c ldrb r2, [r11, #0x4]
 *   @0x275a30 and r0, r0, #3
 *   @0x275a34 ldrb lr, [r11, #0x1]
 *   @0x275a38 mov r4, #5
 *   @0x275a3c and r2, r2, #63
 *   @0x275a40 ldrb r1, [r11, #0x2]
 *   @0x275a44 orr r2, r2, r0, lsl #24
 *   @0x275a48 and lr, lr, #63
 *   @0x275a4c ldrb r0, [r11, #0x3]
 *   @0x275a50 and r1, r1, #63
 *   @0x275a54 orr r2, r2, lr, lsl #18
 *   @0x275a58 and r0, r0, #63
 *   @0x275a5c orr r2, r2, r1, lsl #12
 *   @0x275a60 orr r0, r2, r0, lsl #6
 *   @0x275a64 b 0x274ec4 <pcre_dfa_exec+0x695c>
 *   @0x275a68 tst r3, #8
 *   @0x275a6c bne 0x2766b0 <pcre_dfa_exec+0x8148>
 *   @0x275a70 ldrb r0, [r4, #0x3]
 *   @0x275a74 and r3, r3, #7
 *   @0x275a78 ldrb r2, [r4, #0x1]
 *   @0x275a7c ldrb r1, [r4, #0x2]
 *   @0x275a80 and r0, r0, #63
 *   @0x275a84 and r2, r2, #63
 *   @0x275a88 orr r3, r0, r3, lsl #18
 *   @0x275a8c and r1, r1, #63
 *   @0x275a90 orr r3, r3, r2, lsl #12
 *   @0x275a94 mov r2, #4
 *   @0x275a98 orr r3, r3, r1, lsl #6
 *   @0x275a9c b 0x272938 <pcre_dfa_exec+0x43d0>
 *   @0x275aa0 mov r10, r3
 *   @0x275aa4 b 0x271ee0 <pcre_dfa_exec+0x3978>
 *   @0x275aa8 mov r6, r9
 *   @0x275aac ldr r10, [sp, #0x30]
 *   @0x275ab0 mov r9, r11
 *   @0x275ab4 ldr r11, [sp, #0x4c]
 *   @0x275ab8 ldr r3, [sp, #0x2c]
 *   @0x275abc cmp r3, #0
 *   @0x275ac0 beq 0x275f54 <pcre_dfa_exec+0x79ec>
 *   @0x275ac4 mov r10, r9
 *   @0x275ac8 ldrb r5, [r11]
 *   @0x275acc b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x275ad0 ldr r12, [sp, #0x2c]
 *   @0x275ad4 cmp r5, r12
 *   @0x275ad8 beq 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x275adc ldr r12, [sp, #0x30]
 *   @0x275ae0 mov r4, r11
 *   @0x275ae4 str r9, [sp, #0x20]
 *   @0x275ae8 cmp r12, #0
 *   @0x275aec ldr r11, [sp, #0x18]
 *   @0x275af0 bne 0x275ba0 <pcre_dfa_exec+0x7638>
 *   @0x275af4 ldr r12, [sp, #0x2c]
 *   @0x275af8 mov r9, r10
 *   @0x275afc cmp r5, r12
 *   @0x275b00 blt 0x275b18 <pcre_dfa_exec+0x75b0>
 *   @0x275b04 b 0x275bec <pcre_dfa_exec+0x7684>
 *   @0x275b08 ldr r12, [sp, #0x2c]
 *   @0x275b0c add r9, r9, r0
 *   @0x275b10 cmp r5, r12
 *   @0x275b14 beq 0x275c24 <pcre_dfa_exec+0x76bc>
 *   @0x275b18 ldr r12, [sp, #0x20]
 *   @0x275b1c mov r0, r7
 *   @0x275b20 mov r1, r9
 *   @0x275b24 mov r2, r8
 *   @0x275b28 mov r3, r6
 *   @0x275b2c add r5, r5, #1
 *   @0x275b30 str r12, [sp]
 *   @0x275b34 bl 0x25cc6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b44>
 *   @0x275b38 cmp r0, #0
 *   @0x275b3c bge 0x275b08 <pcre_dfa_exec+0x75a0>
 *   @0x275b40 cmn r0, #2
 *   @0x275b44 bne 0x275c24 <pcre_dfa_exec+0x76bc>
 *   @0x275b48 ldr r3, [r6, #0x88]
 *   @0x275b4c cmp r3, #0
 *   @0x275b50 beq 0x275c24 <pcre_dfa_exec+0x76bc>
 *   @0x275b54 ldr r1, [r6, #0x78]
 *   @0x275b58 ldr r2, [r6, #0x84]
 *   @0x275b5c cmp r1, r2
 *   @0x275b60 bls 0x275c24 <pcre_dfa_exec+0x76bc>
 *   @0x275b64 cmp r3, #1
 *   @0x275b68 mov r3, #1
 *   @0x275b6c str r3, [r6, #0x64]
 *   @0x275b70 ble 0x275c24 <pcre_dfa_exec+0x76bc>
 *   @0x275b74 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x275b78 ldr r12, [sp, #0x2c]
 *   @0x275b7c cmp r5, r12
 *   @0x275b80 add r5, r5, #1
 *   @0x275b84 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275b88 ldr r12, [sp, #0x20]
 *   @0x275b8c str r12, [sp]
 *   @0x275b90 bl 0x25cc6c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1b44>
 *   @0x275b94 cmp r0, #0
 *   @0x275b98 blt 0x2719b4 <pcre_dfa_exec+0x344c>
 *   @0x275b9c add r10, r10, r0
 *   @0x275ba0 ldr r12, [sp, #0x164]
 *   @0x275ba4 mov r1, r4
 *   @0x275ba8 ldr r3, [sp, #0x168]
 *   @0x275bac mov r0, r10
 *   @0x275bb0 ldr r2, [sp, #0x1c]
 *   @0x275bb4 str r12, [sp, #0x4]
 *   @0x275bb8 add r3, r3, #1
 *   @0x275bbc str r6, [sp]
 *   @0x275bc0 str r3, [sp, #0x8]
 *   @0x275bc4 mov r3, r11
 *   @0x275bc8 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x275bcc mov r1, r10
 *   @0x275bd0 mov r2, r8
 *   @0x275bd4 mov r3, r6
 *   @0x275bd8 subs r12, r0, #0
 *   @0x275bdc mov r0, r7
 *   @0x275be0 beq 0x275b78 <pcre_dfa_exec+0x7610>
 *   @0x275be4 mov r0, r12
 *   @0x275be8 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275bec ldr r5, [sp, #0x164]
 *   @0x275bf0 mov r0, r9
 *   @0x275bf4 ldr r3, [sp, #0x168]
 *   @0x275bf8 mov r1, r4
 *   @0x275bfc str r6, [sp]
 *   @0x275c00 rsb r9, r8, r9
 *   @0x275c04 add r3, r3, #1
 *   @0x275c08 str r5, [sp, #0x4]
 *   @0x275c0c str r3, [sp, #0x8]
 *   @0x275c10 mov r3, r11
 *   @0x275c14 ldr r2, [sp, #0x1c]
 *   @0x275c18 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x275c1c cmp r0, #0
 *   @0x275c20 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275c24 cmp r10, r9
 *   @0x275c28 bls 0x275bec <pcre_dfa_exec+0x7684>
 *   @0x275c2c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275c30 ldr r5, [sp, #0x28]
 *   @0x275c34 mov r0, r10
 *   @0x275c38 add r3, r6, #28
 *   @0x275c3c str r5, [sp]
 *   @0x275c40 bl 0x25f9fc <_pcre_is_newline>
 *   @0x275c44 adds r0, r0, #0
 *   @0x275c48 movne r0, #1
 *   @0x275c4c b 0x270b24 <pcre_dfa_exec+0x25bc>
 *   @0x275c50 ldrb r2, [r4, #0x5]
 *   @0x275c54 and r3, r3, #1
 *   @0x275c58 ldrb r0, [r4, #0x1]
 *   @0x275c5c and r2, r2, #63
 *   @0x275c60 ldrb r12, [r4, #0x2]
 *   @0x275c64 and r0, r0, #63
 *   @0x275c68 orr r3, r2, r3, lsl #30
 *   @0x275c6c ldrb r2, [r4, #0x3]
 *   @0x275c70 and r12, r12, #63
 *   @0x275c74 orr r3, r3, r0, lsl #24
 *   @0x275c78 ldrb r0, [r4, #0x4]
 *   @0x275c7c and r2, r2, #63
 *   @0x275c80 orr r3, r3, r12, lsl #18
 *   @0x275c84 and r0, r0, #63
 *   @0x275c88 orr r3, r3, r2, lsl #12
 *   @0x275c8c mov r2, #6
 *   @0x275c90 orr r3, r3, r0, lsl r2
 *   @0x275c94 b 0x27488c <pcre_dfa_exec+0x6324>
 *   @0x275c98 tst r3, #8
 *   @0x275c9c bne 0x2768b4 <pcre_dfa_exec+0x834c>
 *   @0x275ca0 ldrb r2, [r4, #0x3]
 *   @0x275ca4 and r0, r3, #7
 *   @0x275ca8 ldrb r1, [r4, #0x1]
 *   @0x275cac ldrb r3, [r4, #0x2]
 *   @0x275cb0 and r2, r2, #63
 *   @0x275cb4 and r1, r1, #63
 *   @0x275cb8 orr r2, r2, r0, lsl #18
 *   @0x275cbc and r3, r3, #63
 *   @0x275cc0 orr r1, r2, r1, lsl #12
 *   @0x275cc4 mov r2, #4
 *   @0x275cc8 orr r3, r1, r3, lsl #6
 *   @0x275ccc b 0x2727b0 <pcre_dfa_exec+0x4248>
 *   @0x275cd0 tst r3, #8
 *   @0x275cd4 bne 0x2769d0 <pcre_dfa_exec+0x8468>
 *   @0x275cd8 ldrb r2, [r4, #0x3]
 *   @0x275cdc and r12, r3, #7
 *   @0x275ce0 ldrb r1, [r4, #0x1]
 *   @0x275ce4 ldrb r3, [r4, #0x2]
 *   @0x275ce8 and r2, r2, #63
 *   @0x275cec and r1, r1, #63
 *   @0x275cf0 orr r2, r2, r12, lsl #18
 *   @0x275cf4 and r12, r3, #63
 *   @0x275cf8 orr r3, r2, r1, lsl #12
 *   @0x275cfc mov r2, #4
 *   @0x275d00 orr r3, r3, r12, lsl #6
 *   @0x275d04 b 0x272414 <pcre_dfa_exec+0x3eac>
 *   @0x275d08 tst r3, #8
 *   @0x275d0c bne 0x276870 <pcre_dfa_exec+0x8308>
 *   @0x275d10 ldrb r2, [r4, #0x3]
 *   @0x275d14 and r0, r3, #7
 *   @0x275d18 ldrb r1, [r4, #0x1]
 *   @0x275d1c ldrb r3, [r4, #0x2]
 *   @0x275d20 and r2, r2, #63
 *   @0x275d24 and r1, r1, #63
 *   @0x275d28 orr r2, r2, r0, lsl #18
 *   @0x275d2c and r3, r3, #63
 *   @0x275d30 orr r1, r2, r1, lsl #12
 *   @0x275d34 mov r2, #4
 *   @0x275d38 orr r3, r1, r3, lsl #6
 *   @0x275d3c b 0x2726b8 <pcre_dfa_exec+0x4150>
 *   @0x275d40 bhs 0x2759dc <pcre_dfa_exec+0x7474>
 *   @0x275d44 mov r0, #0
 *   @0x275d48 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275d4c tst r3, #8
 *   @0x275d50 bne 0x2767b0 <pcre_dfa_exec+0x8248>
 *   @0x275d54 ldrb r2, [r4, #0x3]
 *   @0x275d58 and r0, r3, #7
 *   @0x275d5c ldrb r1, [r4, #0x1]
 *   @0x275d60 ldrb r3, [r4, #0x2]
 *   @0x275d64 and r2, r2, #63
 *   @0x275d68 and r1, r1, #63
 *   @0x275d6c orr r2, r2, r0, lsl #18
 *   @0x275d70 and r3, r3, #63
 *   @0x275d74 orr r1, r2, r1, lsl #12
 *   @0x275d78 mov r2, #4
 *   @0x275d7c orr r3, r1, r3, lsl #6
 *   @0x275d80 b 0x272734 <pcre_dfa_exec+0x41cc>
 *   @0x275d84 cmp r9, r1
 *   @0x275d88 bls 0x273160 <pcre_dfa_exec+0x4bf8>
 *   @0x275d8c ldrb r3, [r10, #0x1]
 *   @0x275d90 cmp r3, #10
 *   @0x275d94 addeq r1, r10, #2
 *   @0x275d98 b 0x273160 <pcre_dfa_exec+0x4bf8>
 *   @0x275d9c cmp r10, r9
 *   @0x275da0 bhs 0x271f40 <pcre_dfa_exec+0x39d8>
 *   @0x275da4 ldrb r3, [r10]
 *   @0x275da8 cmp r3, #10
 *   @0x275dac addeq r10, r10, #1
 *   @0x275db0 b 0x271f40 <pcre_dfa_exec+0x39d8>
 *   @0x275db4 cmp r3, r2
 *   @0x275db8 bne 0x271794 <pcre_dfa_exec+0x322c>
 *   @0x275dbc b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275dc0 mov r4, r10
 *   @0x275dc4 ldr r2, [r6, #0x88]
 *   @0x275dc8 cmp r2, #0
 *   @0x275dcc beq 0x274930 <pcre_dfa_exec+0x63c8>
 *   @0x275dd0 ldr r3, [r6, #0x84]
 *   @0x275dd4 cmp r3, r4
 *   @0x275dd8 bhs 0x274930 <pcre_dfa_exec+0x63c8>
 *   @0x275ddc cmp r2, #1
 *   @0x275de0 mov r0, #1
 *   @0x275de4 str r0, [r6, #0x64]
 *   @0x275de8 ble 0x274930 <pcre_dfa_exec+0x63c8>
 *   @0x275dec b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x275df0 tst r3, #16
 *   @0x275df4 bne 0x276838 <pcre_dfa_exec+0x82d0>
 *   @0x275df8 lsl r1, r3, #12
 *   @0x275dfc ldrb r2, [r10, #0x2]
 *   @0x275e00 ldrb r3, [r10, #0x1]
 *   @0x275e04 add r10, r10, #3
 *   @0x275e08 uxth r1, r1
 *   @0x275e0c and r2, r2, #63
 *   @0x275e10 and r3, r3, #63
 *   @0x275e14 orr r2, r1, r2
 *   @0x275e18 orr r3, r2, r3, lsl #6
 *   @0x275e1c b 0x271f2c <pcre_dfa_exec+0x39c4>
 *   @0x275e20 mov r4, r10
 *   @0x275e24 ldr r2, [r6, #0x88]
 *   @0x275e28 cmp r2, #0
 *   @0x275e2c beq 0x272cf0 <pcre_dfa_exec+0x4788>
 *   @0x275e30 ldr r3, [r6, #0x84]
 *   @0x275e34 cmp r3, r4
 *   @0x275e38 bhs 0x272cf0 <pcre_dfa_exec+0x4788>
 *   @0x275e3c cmp r2, #1
 *   @0x275e40 mov r2, #1
 *   @0x275e44 str r2, [r6, #0x64]
 *   @0x275e48 ble 0x272cf0 <pcre_dfa_exec+0x4788>
 *   @0x275e4c b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x275e50 tst r3, #8
 *   @0x275e54 bne 0x276ae0 <pcre_dfa_exec+0x8578>
 *   @0x275e58 ldrb r2, [r4, #0x3]
 *   @0x275e5c and r0, r3, #7
 *   @0x275e60 ldrb r1, [r4, #0x1]
 *   @0x275e64 ldrb r3, [r4, #0x2]
 *   @0x275e68 and r2, r2, #63
 *   @0x275e6c and r1, r1, #63
 *   @0x275e70 orr r2, r2, r0, lsl #18
 *   @0x275e74 and r3, r3, #63
 *   @0x275e78 orr r1, r2, r1, lsl #12
 *   @0x275e7c mov r2, #4
 *   @0x275e80 orr r3, r1, r3, lsl #6
 *   @0x275e84 b 0x272350 <pcre_dfa_exec+0x3de8>
 *   @0x275e88 mov r0, #0
 *   @0x275e8c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275e90 tst r3, #4
 *   @0x275e94 bne 0x276e3c <pcre_dfa_exec+0x88d4>
 *   @0x275e98 ldrb r1, [r10, #0x4]
 *   @0x275e9c and r3, r3, #3
 *   @0x275ea0 ldrb r12, [r10, #0x1]
 *   @0x275ea4 add r10, r10, #5
 *   @0x275ea8 and r1, r1, #63
 *   @0x275eac ldrb r0, [r10, #-0x3]
 *   @0x275eb0 orr r3, r1, r3, lsl #24
 *   @0x275eb4 and r12, r12, #63
 *   @0x275eb8 ldrb r1, [r10, #-0x2]
 *   @0x275ebc and r0, r0, #63
 *   @0x275ec0 orr r3, r3, r12, lsl #18
 *   @0x275ec4 and r1, r1, #63
 *   @0x275ec8 orr r3, r3, r0, lsl #12
 *   @0x275ecc orr r3, r3, r1, lsl #6
 *   @0x275ed0 b 0x272054 <pcre_dfa_exec+0x3aec>
 *   @0x275ed4 tst r2, #16
 *   @0x275ed8 bne 0x276cbc <pcre_dfa_exec+0x8754>
 *   @0x275edc lsl r0, r2, #12
 *   @0x275ee0 ldrb r1, [r10, #0x1]
 *   @0x275ee4 ldrb r2, [r10, #0x2]
 *   @0x275ee8 add r10, r10, #3
 *   @0x275eec uxth r0, r0
 *   @0x275ef0 and r1, r1, #63
 *   @0x275ef4 and r2, r2, #63
 *   @0x275ef8 orr r2, r0, r2
 *   @0x275efc orr r2, r2, r1, lsl #6
 *   @0x275f00 b 0x271770 <pcre_dfa_exec+0x3208>
 *   @0x275f04 tst r3, #16
 *   @0x275f08 bne 0x27696c <pcre_dfa_exec+0x8404>
 *   @0x275f0c lsl r1, r3, #12
 *   @0x275f10 ldrb r2, [r11, #0x2]
 *   @0x275f14 ldrb r3, [r11, #0x3]
 *   @0x275f18 add r11, r11, #4
 *   @0x275f1c uxth r1, r1
 *   @0x275f20 and r2, r2, #63
 *   @0x275f24 and r3, r3, #63
 *   @0x275f28 orr r3, r1, r3
 *   @0x275f2c orr r3, r3, r2, lsl #6
 *   @0x275f30 b 0x271744 <pcre_dfa_exec+0x31dc>
 *   @0x275f34 ldr r7, [sp, #0x28]
 *   @0x275f38 mov r0, r10
 *   @0x275f3c add r3, r6, #28
 *   @0x275f40 str r7, [sp]
 *   @0x275f44 bl 0x25fbc0 <_pcre_was_newline>
 *   @0x275f48 cmp r0, #0
 *   @0x275f4c beq 0x270504 <pcre_dfa_exec+0x1f9c>
 *   @0x275f50 b 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x275f54 mov r4, r11
 *   @0x275f58 ldr r8, [sp, #0x28]
 *   @0x275f5c ldr r5, [sp, #0x1c]
 *   @0x275f60 ldr r11, [sp, #0x18]
 *   @0x275f64 ldr r7, [sp, #0x164]
 *   @0x275f68 ldr r3, [sp, #0x168]
 *   @0x275f6c mov r0, r9
 *   @0x275f70 str r6, [sp]
 *   @0x275f74 mov r1, r4
 *   @0x275f78 add r3, r3, #1
 *   @0x275f7c str r7, [sp, #0x4]
 *   @0x275f80 str r3, [sp, #0x8]
 *   @0x275f84 mov r2, r5
 *   @0x275f88 mov r3, r11
 *   @0x275f8c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x275f90 cmp r0, #0
 *   @0x275f94 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x275f98 cmp r9, r10
 *   @0x275f9c sub r3, r9, #1
 *   @0x275fa0 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x275fa4 cmp r8, #0
 *   @0x275fa8 beq 0x275fd8 <pcre_dfa_exec+0x7a70>
 *   @0x275fac ldrb r2, [r9, #-0x1]
 *   @0x275fb0 and r2, r2, #192
 *   @0x275fb4 cmp r2, #128
 *   @0x275fb8 bne 0x275fd8 <pcre_dfa_exec+0x7a70>
 *   @0x275fbc sub r0, r9, #2
 *   @0x275fc0 mov r3, r0
 *   @0x275fc4 sub r0, r0, #1
 *   @0x275fc8 ldrb r2, [r3]
 *   @0x275fcc and r2, r2, #192
 *   @0x275fd0 cmp r2, #128
 *   @0x275fd4 beq 0x275fc0 <pcre_dfa_exec+0x7a58>
 *   @0x275fd8 mov r9, r3
 *   @0x275fdc b 0x275f68 <pcre_dfa_exec+0x7a00>
 *   @0x275fe0 tst r3, #16
 *   @0x275fe4 bne 0x276cf4 <pcre_dfa_exec+0x878c>
 *   @0x275fe8 lsl r1, r3, #12
 *   @0x275fec ldrb r2, [r11, #0x2]
 *   @0x275ff0 ldrb r3, [r11, #0x3]
 *   @0x275ff4 uxth r1, r1
 *   @0x275ff8 and r2, r2, #63
 *   @0x275ffc and r3, r3, #63
 *   @0x276000 orr r3, r1, r3
 *   @0x276004 mov r1, #3
 *   @0x276008 orr r3, r3, r2, lsl #6
 *   @0x27600c b 0x26fb70 <pcre_dfa_exec+0x1608>
 *   @0x276010 tst r3, #8
 *   @0x276014 bne 0x276928 <pcre_dfa_exec+0x83c0>
 *   @0x276018 ldrb r0, [r10, #0x3]
 *   @0x27601c and r3, r3, #7
 *   @0x276020 ldrb r1, [r10, #0x1]
 *   @0x276024 add r10, r10, #4
 *   @0x276028 ldrb r2, [r10, #-0x2]
 *   @0x27602c and r0, r0, #63
 *   @0x276030 and r1, r1, #63
 *   @0x276034 orr r3, r0, r3, lsl #18
 *   @0x276038 and r2, r2, #63
 *   @0x27603c orr r3, r3, r1, lsl #12
 *   @0x276040 orr r3, r3, r2, lsl #6
 *   @0x276044 b 0x27076c <pcre_dfa_exec+0x2204>
 *   @0x276048 tst r3, #8
 *   @0x27604c bne 0x276bb4 <pcre_dfa_exec+0x864c>
 *   @0x276050 ldrb r0, [r10, #0x3]
 *   @0x276054 and r3, r3, #7
 *   @0x276058 ldrb r1, [r10, #0x1]
 *   @0x27605c add r10, r10, #4
 *   @0x276060 ldrb r2, [r10, #-0x2]
 *   @0x276064 and r0, r0, #63
 *   @0x276068 and r1, r1, #63
 *   @0x27606c orr r3, r0, r3, lsl #18
 *   @0x276070 and r2, r2, #63
 *   @0x276074 orr r3, r3, r1, lsl #12
 *   @0x276078 orr r3, r3, r2, lsl #6
 *   @0x27607c b 0x270d18 <pcre_dfa_exec+0x27b0>
 *   @0x276080 tst r3, #8
 *   @0x276084 bne 0x276b2c <pcre_dfa_exec+0x85c4>
 *   @0x276088 ldrb r0, [r10, #0x3]
 *   @0x27608c and r3, r3, #7
 *   @0x276090 ldrb r1, [r10, #0x1]
 *   @0x276094 add r10, r10, #4
 *   @0x276098 ldrb r2, [r10, #-0x2]
 *   @0x27609c and r0, r0, #63
 *   @0x2760a0 and r1, r1, #63
 *   @0x2760a4 orr r3, r0, r3, lsl #18
 *   @0x2760a8 and r2, r2, #63
 *   @0x2760ac orr r3, r3, r1, lsl #12
 *   @0x2760b0 orr r3, r3, r2, lsl #6
 *   @0x2760b4 b 0x270368 <pcre_dfa_exec+0x1e00>
 *   @0x2760b8 tst r3, #8
 *   @0x2760bc bne 0x276b70 <pcre_dfa_exec+0x8608>
 *   @0x2760c0 ldrb r0, [r10, #0x3]
 *   @0x2760c4 and r3, r3, #7
 *   @0x2760c8 ldrb r1, [r10, #0x1]
 *   @0x2760cc add r10, r10, #4
 *   @0x2760d0 ldrb r2, [r10, #-0x2]
 *   @0x2760d4 and r0, r0, #63
 *   @0x2760d8 and r1, r1, #63
 *   @0x2760dc orr r3, r0, r3, lsl #18
 *   @0x2760e0 and r2, r2, #63
 *   @0x2760e4 orr r3, r3, r1, lsl #12
 *   @0x2760e8 orr r3, r3, r2, lsl #6
 *   @0x2760ec b 0x270cb4 <pcre_dfa_exec+0x274c>
 *   @0x2760f0 tst r3, #8
 *   @0x2760f4 bne 0x276a58 <pcre_dfa_exec+0x84f0>
 *   @0x2760f8 ldrb r0, [r10, #0x3]
 *   @0x2760fc and r3, r3, #7
 *   @0x276100 ldrb r1, [r10, #0x1]
 *   @0x276104 add r10, r10, #4
 *   @0x276108 ldrb r2, [r10, #-0x2]
 *   @0x27610c and r0, r0, #63
 *   @0x276110 and r1, r1, #63
 *   @0x276114 orr r3, r0, r3, lsl #18
 *   @0x276118 and r2, r2, #63
 *   @0x27611c orr r3, r3, r1, lsl #12
 *   @0x276120 orr r3, r3, r2, lsl #6
 *   @0x276124 b 0x2703d0 <pcre_dfa_exec+0x1e68>
 *   @0x276128 mov r4, r10
 *   @0x27612c ldr r2, [r6, #0x88]
 *   @0x276130 cmp r2, #0
 *   @0x276134 beq 0x274bf8 <pcre_dfa_exec+0x6690>
 *   @0x276138 ldr r3, [r6, #0x84]
 *   @0x27613c cmp r3, r4
 *   @0x276140 bhs 0x274bf8 <pcre_dfa_exec+0x6690>
 *   @0x276144 cmp r2, #1
 *   @0x276148 mov r0, #1
 *   @0x27614c str r0, [r6, #0x64]
 *   @0x276150 ble 0x274bf8 <pcre_dfa_exec+0x6690>
 *   @0x276154 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x276158 tst r3, #8
 *   @0x27615c bne 0x276d2c <pcre_dfa_exec+0x87c4>
 *   @0x276160 ldrb r0, [r10, #0x3]
 *   @0x276164 and r3, r3, #7
 *   @0x276168 ldrb r1, [r10, #0x1]
 *   @0x27616c add r10, r10, #4
 *   @0x276170 ldrb r2, [r10, #-0x2]
 *   @0x276174 and r0, r0, #63
 *   @0x276178 and r1, r1, #63
 *   @0x27617c orr r3, r0, r3, lsl #18
 *   @0x276180 and r2, r2, #63
 *   @0x276184 orr r3, r3, r1, lsl #12
 *   @0x276188 orr r3, r3, r2, lsl #6
 *   @0x27618c b 0x270a78 <pcre_dfa_exec+0x2510>
 *   @0x276190 tst r3, #8
 *   @0x276194 bne 0x276a9c <pcre_dfa_exec+0x8534>
 *   @0x276198 ldrb r0, [r10, #0x3]
 *   @0x27619c and r3, r3, #7
 *   @0x2761a0 ldrb r1, [r10, #0x1]
 *   @0x2761a4 add r10, r10, #4
 *   @0x2761a8 ldrb r2, [r10, #-0x2]
 *   @0x2761ac and r0, r0, #63
 *   @0x2761b0 and r1, r1, #63
 *   @0x2761b4 orr r3, r0, r3, lsl #18
 *   @0x2761b8 and r2, r2, #63
 *   @0x2761bc orr r3, r3, r1, lsl #12
 *   @0x2761c0 orr r3, r3, r2, lsl #6
 *   @0x2761c4 b 0x270938 <pcre_dfa_exec+0x23d0>
 *   @0x2761c8 cmp r0, r12
 *   @0x2761cc ble 0x278e4c <pcre_dfa_exec+0xa8e4>
 *   @0x2761d0 ldr r9, [r6, #0x78]
 *   @0x2761d4 cmp r10, r9
 *   @0x2761d8 movlo r7, r10
 *   @0x2761dc blo 0x276228 <pcre_dfa_exec+0x7cc0>
 *   @0x2761e0 b 0x27758c <pcre_dfa_exec+0x9024>
 *   @0x2761e4 tst r3, #32
 *   @0x2761e8 bne 0x276264 <pcre_dfa_exec+0x7cfc>
 *   @0x2761ec ldrb r1, [r7, #0x1]
 *   @0x2761f0 and r3, r3, #31
 *   @0x2761f4 mov r2, #2
 *   @0x2761f8 and r1, r1, #63
 *   @0x2761fc orr r3, r1, r3, lsl #6
 *   @0x276200 cmp r3, #255
 *   @0x276204 bls 0x276238 <pcre_dfa_exec+0x7cd0>
 *   @0x276208 cmp r5, #110
 *   @0x27620c beq 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x276210 add r12, r12, #1
 *   @0x276214 add r7, r7, r2
 *   @0x276218 cmp r12, r0
 *   @0x27621c beq 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x276220 cmp r7, r9
 *   @0x276224 bhs 0x277590 <pcre_dfa_exec+0x9028>
 *   @0x276228 ldrb r3, [r7]
 *   @0x27622c cmp r3, #191
 *   @0x276230 bhi 0x2761e4 <pcre_dfa_exec+0x7c7c>
 *   @0x276234 mov r2, #1
 *   @0x276238 ldrb r1, [r8, r3, lsr #3]
 *   @0x27623c and r3, r3, #7
 *   @0x276240 asr r3, r1, r3
 *   @0x276244 tst r3, #1
 *   @0x276248 bne 0x276210 <pcre_dfa_exec+0x7ca8>
 *   @0x27624c ldr r0, [sp, #0x30]
 *   @0x276250 cmp r0, #0
 *   @0x276254 beq 0x276bf8 <pcre_dfa_exec+0x8690>
 *   @0x276258 mov r10, r7
 *   @0x27625c ldrb r5, [r11]
 *   @0x276260 b 0x26f2b0 <pcre_dfa_exec+0xd48>
 *   @0x276264 tst r3, #16
 *   @0x276268 bne 0x276294 <pcre_dfa_exec+0x7d2c>
 *   @0x27626c lsl r2, r3, #12
 *   @0x276270 ldrb r1, [r7, #0x1]
 *   @0x276274 ldrb r3, [r7, #0x2]
 *   @0x276278 uxth r2, r2
 *   @0x27627c and r1, r1, #63
 *   @0x276280 and r3, r3, #63
 *   @0x276284 orr r3, r2, r3
 *   @0x276288 mov r2, #3
 *   @0x27628c orr r3, r3, r1, lsl #6
 *   @0x276290 b 0x276200 <pcre_dfa_exec+0x7c98>
 *   @0x276294 tst r3, #8
 *   @0x276298 bne 0x276520 <pcre_dfa_exec+0x7fb8>
 *   @0x27629c ldrb r4, [r7, #0x3]
 *   @0x2762a0 and r3, r3, #7
 *   @0x2762a4 ldrb r2, [r7, #0x1]
 *   @0x2762a8 ldrb r1, [r7, #0x2]
 *   @0x2762ac and r4, r4, #63
 *   @0x2762b0 and r2, r2, #63
 *   @0x2762b4 orr r3, r4, r3, lsl #18
 *   @0x2762b8 and r1, r1, #63
 *   @0x2762bc orr r3, r3, r2, lsl #12
 *   @0x2762c0 mov r2, #4
 *   @0x2762c4 orr r3, r3, r1, lsl #6
 *   @0x2762c8 b 0x276200 <pcre_dfa_exec+0x7c98>
 *   @0x2762cc tst r3, #8
 *   @0x2762d0 bne 0x276d70 <pcre_dfa_exec+0x8808>
 *   @0x2762d4 ldrb r0, [r10, #0x3]
 *   @0x2762d8 and r3, r3, #7
 *   @0x2762dc ldrb r1, [r10, #0x1]
 *   @0x2762e0 add r10, r10, #4
 *   @0x2762e4 ldrb r2, [r10, #-0x2]
 *   @0x2762e8 and r0, r0, #63
 *   @0x2762ec and r1, r1, #63
 *   @0x2762f0 orr r3, r0, r3, lsl #18
 *   @0x2762f4 and r2, r2, #63
 *   @0x2762f8 orr r3, r3, r1, lsl #12
 *   @0x2762fc orr r3, r3, r2, lsl #6
 *   @0x276300 b 0x270708 <pcre_dfa_exec+0x21a0>
 *   @0x276304 ldrb r2, [r4, #0x5]
 *   @0x276308 and r3, r3, #1
 *   @0x27630c ldrb r0, [r4, #0x1]
 *   @0x276310 and r2, r2, #63
 *   @0x276314 ldrb r12, [r4, #0x2]
 *   @0x276318 and r0, r0, #63
 *   @0x27631c orr r3, r2, r3, lsl #30
 *   @0x276320 ldrb r2, [r4, #0x3]
 *   @0x276324 and r12, r12, #63
 *   @0x276328 orr r3, r3, r0, lsl #24
 *   @0x27632c ldrb r0, [r4, #0x4]
 *   @0x276330 and r2, r2, #63
 *   @0x276334 orr r3, r3, r12, lsl #18
 *   @0x276338 and r0, r0, #63
 *   @0x27633c orr r3, r3, r2, lsl #12
 *   @0x276340 mov r2, #6
 *   @0x276344 orr r3, r3, r0, lsl r2
 *   @0x276348 b 0x274b50 <pcre_dfa_exec+0x65e8>
 *   @0x27634c tst r3, #8
 *   @0x276350 bne 0x276db4 <pcre_dfa_exec+0x884c>
 *   @0x276354 ldrb r0, [r10, #0x3]
 *   @0x276358 and r3, r3, #7
 *   @0x27635c ldrb r1, [r10, #0x1]
 *   @0x276360 add r10, r10, #4
 *   @0x276364 ldrb r2, [r10, #-0x2]
 *   @0x276368 and r0, r0, #63
 *   @0x27636c and r1, r1, #63
 *   @0x276370 orr r3, r0, r3, lsl #18
 *   @0x276374 and r2, r2, #63
 *   @0x276378 orr r3, r3, r1, lsl #12
 *   @0x27637c orr r3, r3, r2, lsl #6
 *   @0x276380 b 0x270bec <pcre_dfa_exec+0x2684>
 *   @0x276384 tst r3, #8
 *   @0x276388 bne 0x276df8 <pcre_dfa_exec+0x8890>
 *   @0x27638c ldrb r0, [r10, #0x3]
 *   @0x276390 and r3, r3, #7
 *   @0x276394 ldrb r1, [r10, #0x1]
 *   @0x276398 add r10, r10, #4
 *   @0x27639c ldrb r2, [r10, #-0x2]
 *   @0x2763a0 and r0, r0, #63
 *   @0x2763a4 and r1, r1, #63
 *   @0x2763a8 orr r3, r0, r3, lsl #18
 *   @0x2763ac and r2, r2, #63
 *   @0x2763b0 orr r3, r3, r1, lsl #12
 *   @0x2763b4 orr r3, r3, r2, lsl #6
 *   @0x2763b8 b 0x270c50 <pcre_dfa_exec+0x26e8>
 *   @0x2763bc tst r3, #8
 *   @0x2763c0 bne 0x276c78 <pcre_dfa_exec+0x8710>
 *   @0x2763c4 ldrb r0, [r10, #0x3]
 *   @0x2763c8 and r3, r3, #7
 *   @0x2763cc ldrb r1, [r10, #0x1]
 *   @0x2763d0 add r10, r10, #4
 *   @0x2763d4 ldrb r2, [r10, #-0x2]
 *   @0x2763d8 and r0, r0, #63
 *   @0x2763dc and r1, r1, #63
 *   @0x2763e0 orr r3, r0, r3, lsl #18
 *   @0x2763e4 and r2, r2, #63
 *   @0x2763e8 orr r3, r3, r1, lsl #12
 *   @0x2763ec orr r3, r3, r2, lsl #6
 *   @0x2763f0 b 0x2707dc <pcre_dfa_exec+0x2274>
 *   @0x2763f4 cmp r3, #9
 *   @0x2763f8 beq 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x2763fc b 0x270964 <pcre_dfa_exec+0x23fc>
 *   @0x276400 tst r3, #4
 *   @0x276404 bne 0x276e84 <pcre_dfa_exec+0x891c>
 *   @0x276408 ldrb r0, [r10, #0x4]
 *   @0x27640c and r3, r3, #3
 *   @0x276410 ldrb r4, [r10, #0x1]
 *   @0x276414 add r10, r10, #5
 *   @0x276418 and r0, r0, #63
 *   @0x27641c ldrb r12, [r10, #-0x3]
 *   @0x276420 orr r3, r0, r3, lsl #24
 *   @0x276424 and r4, r4, #63
 *   @0x276428 ldrb r0, [r10, #-0x2]
 *   @0x27642c and r12, r12, #63
 *   @0x276430 orr r3, r3, r4, lsl #18
 *   @0x276434 and r0, r0, #63
 *   @0x276438 orr r3, r3, r12, lsl #12
 *   @0x27643c orr r3, r3, r0, lsl #6
 *   @0x276440 b 0x271ae4 <pcre_dfa_exec+0x357c>
 *   @0x276444 sub r3, r3, #8192
 *   @0x276448 cmp r3, #10
 *   @0x27644c bls 0x26f6d0 <pcre_dfa_exec+0x1168>
 *   @0x276450 b 0x270964 <pcre_dfa_exec+0x23fc>
 *   @0x276454 tst r3, #4
 *   @0x276458 bne 0x276fc8 <pcre_dfa_exec+0x8a60>
 *   @0x27645c ldrb r0, [r10, #0x4]
 *   @0x276460 and r3, r3, #3
 *   @0x276464 ldrb r4, [r10, #0x1]
 *   @0x276468 add r10, r10, #5
 *   @0x27646c and r0, r0, #63
 *   @0x276470 ldrb r12, [r10, #-0x3]
 *   @0x276474 orr r3, r0, r3, lsl #24
 *   @0x276478 and r4, r4, #63
 *   @0x27647c ldrb r0, [r10, #-0x2]
 *   @0x276480 and r12, r12, #63
 *   @0x276484 orr r3, r3, r4, lsl #18
 *   @0x276488 and r0, r0, #63
 *   @0x27648c orr r3, r3, r12, lsl #12
 *   @0x276490 orr r3, r3, r0, lsl #6
 *   @0x276494 b 0x271bfc <pcre_dfa_exec+0x3694>
 *   @0x276498 tst r3, #4
 *   @0x27649c bne 0x276ecc <pcre_dfa_exec+0x8964>
 *   @0x2764a0 ldrb r1, [r10, #0x4]
 *   @0x2764a4 and r3, r3, #3
 *   @0x2764a8 ldrb r12, [r10, #0x1]
 *   @0x2764ac add r10, r10, #5
 *   @0x2764b0 and r1, r1, #63
 *   @0x2764b4 ldrb r0, [r10, #-0x3]
 *   @0x2764b8 orr r3, r1, r3, lsl #24
 *   @0x2764bc and r12, r12, #63
 *   @0x2764c0 ldrb r1, [r10, #-0x2]
 *   @0x2764c4 and r0, r0, #63
 *   @0x2764c8 orr r3, r3, r12, lsl #18
 *   @0x2764cc and r1, r1, #63
 *   @0x2764d0 orr r3, r3, r0, lsl #12
 *   @0x2764d4 orr r3, r3, r1, lsl #6
 *   @0x2764d8 b 0x271c8c <pcre_dfa_exec+0x3724>
 *   @0x2764dc tst r3, #4
 *   @0x2764e0 bne 0x27734c <pcre_dfa_exec+0x8de4>
 *   @0x2764e4 ldrb r1, [r10, #0x4]
 *   @0x2764e8 and r3, r3, #3
 *   @0x2764ec ldrb r12, [r10, #0x1]
 *   @0x2764f0 add r10, r10, #5
 *   @0x2764f4 and r1, r1, #63
 *   @0x2764f8 ldrb r0, [r10, #-0x3]
 *   @0x2764fc orr r3, r1, r3, lsl #24
 *   @0x276500 and r12, r12, #63
 *   @0x276504 ldrb r1, [r10, #-0x2]
 *   @0x276508 and r0, r0, #63
 *   @0x27650c orr r3, r3, r12, lsl #18
 *   @0x276510 and r1, r1, #63
 *   @0x276514 orr r3, r3, r0, lsl #12
 *   @0x276518 orr r3, r3, r1, lsl #6
 *   @0x27651c b 0x271b6c <pcre_dfa_exec+0x3604>
 *   @0x276520 tst r3, #4
 *   @0x276524 bne 0x276f80 <pcre_dfa_exec+0x8a18>
 *   @0x276528 ldrb r1, [r7, #0x4]
 *   @0x27652c and r3, r3, #3
 *   @0x276530 ldrb r4, [r7, #0x1]
 *   @0x276534 and r1, r1, #63
 *   @0x276538 ldrb r2, [r7, #0x2]
 *   @0x27653c orr r3, r1, r3, lsl #24
 *   @0x276540 and r4, r4, #63
 *   @0x276544 ldrb r1, [r7, #0x3]
 *   @0x276548 and r2, r2, #63
 *   @0x27654c orr r3, r3, r4, lsl #18
 *   @0x276550 and r1, r1, #63
 *   @0x276554 orr r3, r3, r2, lsl #12
 *   @0x276558 mov r2, #5
 *   @0x27655c orr r3, r3, r1, lsl #6
 *   @0x276560 b 0x276200 <pcre_dfa_exec+0x7c98>
 *   @0x276564 tst r3, #4
 *   @0x276568 bne 0x2773d0 <pcre_dfa_exec+0x8e68>
 *   @0x27656c ldrb r1, [r4, #0x4]
 *   @0x276570 and r3, r3, #3
 *   @0x276574 ldrb r0, [r4, #0x1]
 *   @0x276578 and r1, r1, #63
 *   @0x27657c ldrb r2, [r4, #0x2]
 *   @0x276580 orr r3, r1, r3, lsl #24
 *   @0x276584 and r0, r0, #63
 *   @0x276588 ldrb r1, [r4, #0x3]
 *   @0x27658c and r2, r2, #63
 *   @0x276590 orr r3, r3, r0, lsl #18
 *   @0x276594 and r1, r1, #63
 *   @0x276598 orr r3, r3, r2, lsl #12
 *   @0x27659c mov r2, #5
 *   @0x2765a0 orr r3, r3, r1, lsl #6
 *   @0x2765a4 b 0x272888 <pcre_dfa_exec+0x4320>
 *   @0x2765a8 tst r3, #16
 *   @0x2765ac bne 0x276f14 <pcre_dfa_exec+0x89ac>
 *   @0x2765b0 lsl r1, r3, #12
 *   @0x2765b4 ldrb r3, [r2, #0x2]
 *   @0x2765b8 ldrb r2, [r2, #0x1]
 *   @0x2765bc uxth r1, r1
 *   @0x2765c0 and r3, r3, #63
 *   @0x2765c4 and r2, r2, #63
 *   @0x2765c8 orr r3, r1, r3
 *   @0x2765cc orr r3, r3, r2, lsl #6
 *   @0x2765d0 b 0x270870 <pcre_dfa_exec+0x2308>
 *   @0x2765d4 mov r4, r10
 *   @0x2765d8 ldr r2, [r6, #0x88]
 *   @0x2765dc cmp r2, #0
 *   @0x2765e0 beq 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x2765e4 ldr r3, [r6, #0x84]
 *   @0x2765e8 cmp r3, r4
 *   @0x2765ec bhs 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x2765f0 cmp r2, #1
 *   @0x2765f4 mov r2, #1
 *   @0x2765f8 str r2, [r6, #0x64]
 *   @0x2765fc ble 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x276600 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x276604 mov r11, r3
 *   @0x276608 b 0x274e44 <pcre_dfa_exec+0x68dc>
 *   @0x27660c mov r5, #1
 *   @0x276610 mov r7, #0
 *   @0x276614 mov r4, #0
 *   @0x276618 str r7, [sp, #0x2c]
 *   @0x27661c mov r7, r5
 *   @0x276620 b 0x2701bc <pcre_dfa_exec+0x1c54>
 *   @0x276624 ldrb r2, [r11, #0x5]
 *   @0x276628 and r0, r0, #1
 *   @0x27662c ldrb r4, [r11, #0x1]
 *   @0x276630 ldrb lr, [r11, #0x2]
 *   @0x276634 and r2, r2, #63
 *   @0x276638 and r4, r4, #63
 *   @0x27663c ldrb r1, [r11, #0x3]
 *   @0x276640 orr r2, r2, r0, lsl #30
 *   @0x276644 and lr, lr, #63
 *   @0x276648 ldrb r0, [r11, #0x4]
 *   @0x27664c orr r2, r2, r4, lsl #24
 *   @0x276650 and r1, r1, #63
 *   @0x276654 orr r2, r2, lr, lsl #18
 *   @0x276658 and r0, r0, #63
 *   @0x27665c mov r4, #6
 *   @0x276660 orr r2, r2, r1, lsl #12
 *   @0x276664 orr r0, r2, r0, lsl r4
 *   @0x276668 b 0x274ec4 <pcre_dfa_exec+0x695c>
 *   @0x27666c tst r3, #4
 *   @0x276670 bne 0x2774a8 <pcre_dfa_exec+0x8f40>
 *   @0x276674 ldrb r2, [r4, #0x4]
 *   @0x276678 and r3, r3, #3
 *   @0x27667c ldrb r0, [r4, #0x1]
 *   @0x276680 and r2, r2, #63
 *   @0x276684 ldrb r1, [r4, #0x2]
 *   @0x276688 orr r2, r2, r3, lsl #24
 *   @0x27668c and r0, r0, #63
 *   @0x276690 ldrb r3, [r4, #0x3]
 *   @0x276694 and r1, r1, #63
 *   @0x276698 orr r2, r2, r0, lsl #18
 *   @0x27669c and r3, r3, #63
 *   @0x2766a0 orr r1, r2, r1, lsl #12
 *   @0x2766a4 mov r2, #5
 *   @0x2766a8 orr r3, r1, r3, lsl #6
 *   @0x2766ac b 0x272a30 <pcre_dfa_exec+0x44c8>
 *   @0x2766b0 tst r3, #4
 *   @0x2766b4 bne 0x2775bc <pcre_dfa_exec+0x9054>
 *   @0x2766b8 ldrb r1, [r4, #0x4]
 *   @0x2766bc and r3, r3, #3
 *   @0x2766c0 ldrb r0, [r4, #0x1]
 *   @0x2766c4 and r1, r1, #63
 *   @0x2766c8 ldrb r2, [r4, #0x2]
 *   @0x2766cc orr r3, r1, r3, lsl #24
 *   @0x2766d0 and r0, r0, #63
 *   @0x2766d4 ldrb r1, [r4, #0x3]
 *   @0x2766d8 and r2, r2, #63
 *   @0x2766dc orr r3, r3, r0, lsl #18
 *   @0x2766e0 and r1, r1, #63
 *   @0x2766e4 orr r3, r3, r2, lsl #12
 *   @0x2766e8 mov r2, #5
 *   @0x2766ec orr r3, r3, r1, lsl #6
 *   @0x2766f0 b 0x272938 <pcre_dfa_exec+0x43d0>
 *   @0x2766f4 ldrb r1, [r4, #-0x1]
 *   @0x2766f8 ldrb r2, [r6, #0x34]
 *   @0x2766fc cmp r1, r2
 *   @0x276700 bne 0x272e7c <pcre_dfa_exec+0x4914>
 *   @0x276704 cmp r3, #1
 *   @0x276708 mov r0, #1
 *   @0x27670c str r0, [r6, #0x64]
 *   @0x276710 ble 0x272e7c <pcre_dfa_exec+0x4914>
 *   @0x276714 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x276718 tst r3, #4
 *   @0x27671c bne 0x2774f0 <pcre_dfa_exec+0x8f88>
 *   @0x276720 ldrb r1, [r4, #0x4]
 *   @0x276724 and r3, r3, #3
 *   @0x276728 ldrb r0, [r4, #0x1]
 *   @0x27672c and r1, r1, #63
 *   @0x276730 ldrb r2, [r4, #0x2]
 *   @0x276734 orr r3, r1, r3, lsl #24
 *   @0x276738 and r0, r0, #63
 *   @0x27673c ldrb r1, [r4, #0x3]
 *   @0x276740 and r2, r2, #63
 *   @0x276744 orr r3, r3, r0, lsl #18
 *   @0x276748 and r1, r1, #63
 *   @0x27674c orr r3, r3, r2, lsl #12
 *   @0x276750 mov r2, #5
 *   @0x276754 orr r3, r3, r1, lsl #6
 *   @0x276758 b 0x2729b4 <pcre_dfa_exec+0x444c>
 *   @0x27675c ldrb r10, [r10]
 *   @0x276760 ldrb r0, [r6, #0x34]
 *   @0x276764 cmp r10, r0
 *   @0x276768 bne 0x273d1c <pcre_dfa_exec+0x57b4>
 *   @0x27676c cmp r1, #1
 *   @0x276770 mov r0, #1
 *   @0x276774 str r0, [r6, #0x64]
 *   @0x276778 ble 0x271d20 <pcre_dfa_exec+0x37b8>
 *   @0x27677c b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x276780 mov r4, r10
 *   @0x276784 ldr r2, [r6, #0x88]
 *   @0x276788 cmp r2, #0
 *   @0x27678c beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x276790 ldr r3, [r6, #0x84]
 *   @0x276794 cmp r3, r4
 *   @0x276798 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27679c cmp r2, #1
 *   @0x2767a0 mov r12, #1
 *   @0x2767a4 str r12, [r6, #0x64]
 *   @0x2767a8 ble 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2767ac b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x2767b0 tst r3, #4
 *   @0x2767b4 bne 0x277bd8 <pcre_dfa_exec+0x9670>
 *   @0x2767b8 ldrb r2, [r4, #0x4]
 *   @0x2767bc and r3, r3, #3
 *   @0x2767c0 ldrb r0, [r4, #0x1]
 *   @0x2767c4 and r2, r2, #63
 *   @0x2767c8 ldrb r1, [r4, #0x2]
 *   @0x2767cc orr r2, r2, r3, lsl #24
 *   @0x2767d0 and r0, r0, #63
 *   @0x2767d4 ldrb r3, [r4, #0x3]
 *   @0x2767d8 and r1, r1, #63
 *   @0x2767dc orr r2, r2, r0, lsl #18
 *   @0x2767e0 and r3, r3, #63
 *   @0x2767e4 orr r1, r2, r1, lsl #12
 *   @0x2767e8 mov r2, #5
 *   @0x2767ec orr r3, r1, r3, lsl #6
 *   @0x2767f0 b 0x272734 <pcre_dfa_exec+0x41cc>
 *   @0x2767f4 ldr r0, [sp, #0x24]
 *   @0x2767f8 b 0x2744e8 <pcre_dfa_exec+0x5f80>
 *   @0x2767fc mov r6, r9
 *   @0x276800 ldr r10, [sp, #0x30]
 *   @0x276804 mov r9, r11
 *   @0x276808 ldr r11, [sp, #0x4c]
 *   @0x27680c ldr r2, [r6, #0x88]
 *   @0x276810 cmp r2, #0
 *   @0x276814 beq 0x275ab8 <pcre_dfa_exec+0x7550>
 *   @0x276818 ldr r3, [r6, #0x84]
 *   @0x27681c cmp r3, r9
 *   @0x276820 bhs 0x275ab8 <pcre_dfa_exec+0x7550>
 *   @0x276824 cmp r2, #1
 *   @0x276828 mov r0, #1
 *   @0x27682c str r0, [r6, #0x64]
 *   @0x276830 ble 0x275ab8 <pcre_dfa_exec+0x7550>
 *   @0x276834 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x276838 tst r3, #8
 *   @0x27683c bne 0x277ed8 <pcre_dfa_exec+0x9970>
 *   @0x276840 ldrb r0, [r10, #0x3]
 *   @0x276844 and r3, r3, #7
 *   @0x276848 ldrb r2, [r10, #0x1]
 *   @0x27684c add r10, r10, #4
 *   @0x276850 ldrb r1, [r10, #-0x2]
 *   @0x276854 and r0, r0, #63
 *   @0x276858 and r2, r2, #63
 *   @0x27685c orr r0, r0, r3, lsl #18
 *   @0x276860 and r1, r1, #63
 *   @0x276864 orr r3, r0, r2, lsl #12
 *   @0x276868 orr r3, r3, r1, lsl #6
 *   @0x27686c b 0x271f2c <pcre_dfa_exec+0x39c4>
 *   @0x276870 tst r3, #4
 *   @0x276874 bne 0x277d6c <pcre_dfa_exec+0x9804>
 *   @0x276878 ldrb r2, [r4, #0x4]
 *   @0x27687c and r3, r3, #3
 *   @0x276880 ldrb r0, [r4, #0x1]
 *   @0x276884 and r2, r2, #63
 *   @0x276888 ldrb r1, [r4, #0x2]
 *   @0x27688c orr r2, r2, r3, lsl #24
 *   @0x276890 and r0, r0, #63
 *   @0x276894 ldrb r3, [r4, #0x3]
 *   @0x276898 and r1, r1, #63
 *   @0x27689c orr r2, r2, r0, lsl #18
 *   @0x2768a0 and r3, r3, #63
 *   @0x2768a4 orr r1, r2, r1, lsl #12
 *   @0x2768a8 mov r2, #5
 *   @0x2768ac orr r3, r1, r3, lsl #6
 *   @0x2768b0 b 0x2726b8 <pcre_dfa_exec+0x4150>
 *   @0x2768b4 tst r3, #4
 *   @0x2768b8 bne 0x2776e8 <pcre_dfa_exec+0x9180>
 *   @0x2768bc ldrb r2, [r4, #0x4]
 *   @0x2768c0 and r3, r3, #3
 *   @0x2768c4 ldrb r0, [r4, #0x1]
 *   @0x2768c8 and r2, r2, #63
 *   @0x2768cc ldrb r1, [r4, #0x2]
 *   @0x2768d0 orr r2, r2, r3, lsl #24
 *   @0x2768d4 and r0, r0, #63
 *   @0x2768d8 ldrb r3, [r4, #0x3]
 *   @0x2768dc and r1, r1, #63
 *   @0x2768e0 orr r2, r2, r0, lsl #18
 *   @0x2768e4 and r3, r3, #63
 *   @0x2768e8 orr r1, r2, r1, lsl #12
 *   @0x2768ec mov r2, #5
 *   @0x2768f0 orr r3, r1, r3, lsl #6
 *   @0x2768f4 b 0x2727b0 <pcre_dfa_exec+0x4248>
 *   @0x2768f8 ldr r3, [r6, #0x5c]
 *   @0x2768fc cmp r3, #0
 *   @0x276900 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x276904 ldr r3, [r6, #0x60]
 *   @0x276908 cmp r3, #0
 *   @0x27690c beq 0x270040 <pcre_dfa_exec+0x1ad8>
 *   @0x276910 ldr r2, [r6, #0x74]
 *   @0x276914 ldr r3, [r6, #0x94]
 *   @0x276918 add r3, r2, r3
 *   @0x27691c cmp r12, r3
 *   @0x276920 bne 0x270040 <pcre_dfa_exec+0x1ad8>
 *   @0x276924 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x276928 tst r3, #4
 *   @0x27692c bne 0x277b90 <pcre_dfa_exec+0x9628>
 *   @0x276930 ldrb r2, [r10, #0x4]
 *   @0x276934 and r3, r3, #3
 *   @0x276938 ldrb r0, [r10, #0x1]
 *   @0x27693c add r10, r10, #5
 *   @0x276940 and r2, r2, #63
 *   @0x276944 ldrb r1, [r10, #-0x3]
 *   @0x276948 orr r3, r2, r3, lsl #24
 *   @0x27694c and r0, r0, #63
 *   @0x276950 ldrb r2, [r10, #-0x2]
 *   @0x276954 and r1, r1, #63
 *   @0x276958 orr r3, r3, r0, lsl #18
 *   @0x27695c and r2, r2, #63
 *   @0x276960 orr r3, r3, r1, lsl #12
 *   @0x276964 orr r3, r3, r2, lsl #6
 *   @0x276968 b 0x27076c <pcre_dfa_exec+0x2204>
 *   @0x27696c tst r3, #8
 *   @0x276970 bne 0x277c20 <pcre_dfa_exec+0x96b8>
 *   @0x276974 ldrb r0, [r11, #0x4]
 *   @0x276978 and r3, r3, #7
 *   @0x27697c ldrb r1, [r11, #0x2]
 *   @0x276980 add r11, r11, #5
 *   @0x276984 ldrb r2, [r11, #-0x2]
 *   @0x276988 and r0, r0, #63
 *   @0x27698c and r1, r1, #63
 *   @0x276990 orr r3, r0, r3, lsl #18
 *   @0x276994 and r2, r2, #63
 *   @0x276998 orr r3, r3, r1, lsl #12
 *   @0x27699c orr r3, r3, r2, lsl #6
 *   @0x2769a0 b 0x271744 <pcre_dfa_exec+0x31dc>
 *   @0x2769a4 tst r3, #16
 *   @0x2769a8 bne 0x2776b4 <pcre_dfa_exec+0x914c>
 *   @0x2769ac lsl r1, r3, #12
 *   @0x2769b0 ldrb r2, [r10, #0x1]
 *   @0x2769b4 ldrb r3, [r10, #0x2]
 *   @0x2769b8 uxth r1, r1
 *   @0x2769bc and r2, r2, #63
 *   @0x2769c0 and r3, r3, #63
 *   @0x2769c4 orr r3, r1, r3
 *   @0x2769c8 orr r3, r3, r2, lsl #6
 *   @0x2769cc b 0x275258 <pcre_dfa_exec+0x6cf0>
 *   @0x2769d0 tst r3, #4
 *   @0x2769d4 bne 0x277788 <pcre_dfa_exec+0x9220>
 *   @0x2769d8 ldrb r1, [r4, #0x1]
 *   @0x2769dc and r12, r3, #3
 *   @0x2769e0 ldrb r2, [r4, #0x4]
 *   @0x2769e4 str r1, [sp, #0x2c]
 *   @0x2769e8 and r2, r2, #63
 *   @0x2769ec ldr r3, [sp, #0x2c]
 *   @0x2769f0 orr r2, r2, r12, lsl #24
 *   @0x2769f4 ldrb r1, [r4, #0x2]
 *   @0x2769f8 and r3, r3, #63
 *   @0x2769fc str r3, [sp, #0x2c]
 *   @0x276a00 and r12, r1, #63
 *   @0x276a04 ldr r1, [sp, #0x2c]
 *   @0x276a08 ldrb r3, [r4, #0x3]
 *   @0x276a0c orr r2, r2, r1, lsl #18
 *   @0x276a10 and r3, r3, #63
 *   @0x276a14 orr r12, r2, r12, lsl #12
 *   @0x276a18 str r3, [sp, #0x2c]
 *   @0x276a1c mov r2, #5
 *   @0x276a20 orr r3, r12, r3, lsl #6
 *   @0x276a24 b 0x272414 <pcre_dfa_exec+0x3eac>
 *   @0x276a28 tst r2, #16
 *   @0x276a2c bne 0x277750 <pcre_dfa_exec+0x91e8>
 *   @0x276a30 lsl r12, r2, #12
 *   @0x276a34 ldrb r0, [r10, #0x1]
 *   @0x276a38 ldrb r2, [r10, #0x2]
 *   @0x276a3c add r10, r10, #3
 *   @0x276a40 uxth r12, r12
 *   @0x276a44 and r0, r0, #63
 *   @0x276a48 and r2, r2, #63
 *   @0x276a4c orr r2, r12, r2
 *   @0x276a50 orr r2, r2, r0, lsl #6
 *   @0x276a54 b 0x2753b4 <pcre_dfa_exec+0x6e4c>
 *   @0x276a58 tst r3, #4
 *   @0x276a5c bne 0x2778bc <pcre_dfa_exec+0x9354>
 *   @0x276a60 ldrb r2, [r10, #0x4]
 *   @0x276a64 and r3, r3, #3
 *   @0x276a68 ldrb r0, [r10, #0x1]
 *   @0x276a6c add r10, r10, #5
 *   @0x276a70 and r2, r2, #63
 *   @0x276a74 ldrb r1, [r10, #-0x3]
 *   @0x276a78 orr r3, r2, r3, lsl #24
 *   @0x276a7c and r0, r0, #63
 *   @0x276a80 ldrb r2, [r10, #-0x2]
 *   @0x276a84 and r1, r1, #63
 *   @0x276a88 orr r3, r3, r0, lsl #18
 *   @0x276a8c and r2, r2, #63
 *   @0x276a90 orr r3, r3, r1, lsl #12
 *   @0x276a94 orr r3, r3, r2, lsl #6
 *   @0x276a98 b 0x2703d0 <pcre_dfa_exec+0x1e68>
 *   @0x276a9c tst r3, #4
 *   @0x276aa0 bne 0x277c94 <pcre_dfa_exec+0x972c>
 *   @0x276aa4 ldrb r2, [r10, #0x4]
 *   @0x276aa8 and r3, r3, #3
 *   @0x276aac ldrb r0, [r10, #0x1]
 *   @0x276ab0 add r10, r10, #5
 *   @0x276ab4 and r2, r2, #63
 *   @0x276ab8 ldrb r1, [r10, #-0x3]
 *   @0x276abc orr r3, r2, r3, lsl #24
 *   @0x276ac0 and r0, r0, #63
 *   @0x276ac4 ldrb r2, [r10, #-0x2]
 *   @0x276ac8 and r1, r1, #63
 *   @0x276acc orr r3, r3, r0, lsl #18
 *   @0x276ad0 and r2, r2, #63
 *   @0x276ad4 orr r3, r3, r1, lsl #12
 *   @0x276ad8 orr r3, r3, r2, lsl #6
 *   @0x276adc b 0x270938 <pcre_dfa_exec+0x23d0>
 *   @0x276ae0 tst r3, #4
 *   @0x276ae4 bne 0x277e04 <pcre_dfa_exec+0x989c>
 *   @0x276ae8 ldrb r2, [r4, #0x4]
 *   @0x276aec and r3, r3, #3
 *   @0x276af0 ldrb r0, [r4, #0x1]
 *   @0x276af4 and r2, r2, #63
 *   @0x276af8 ldrb r1, [r4, #0x2]
 *   @0x276afc orr r2, r2, r3, lsl #24
 *   @0x276b00 and r0, r0, #63
 *   @0x276b04 ldrb r3, [r4, #0x3]
 *   @0x276b08 and r1, r1, #63
 *   @0x276b0c orr r2, r2, r0, lsl #18
 *   @0x276b10 and r3, r3, #63
 *   @0x276b14 orr r1, r2, r1, lsl #12
 *   @0x276b18 mov r2, #5
 *   @0x276b1c orr r3, r1, r3, lsl #6
 *   @0x276b20 b 0x272350 <pcre_dfa_exec+0x3de8>
 *   @0x276b24 mov r8, r10
 *   @0x276b28 b 0x2731e0 <pcre_dfa_exec+0x4c78>
 *   @0x276b2c tst r3, #4
 *   @0x276b30 bne 0x277664 <pcre_dfa_exec+0x90fc>
 *   @0x276b34 ldrb r2, [r10, #0x4]
 *   @0x276b38 and r3, r3, #3
 *   @0x276b3c ldrb r0, [r10, #0x1]
 *   @0x276b40 add r10, r10, #5
 *   @0x276b44 and r2, r2, #63
 *   @0x276b48 ldrb r1, [r10, #-0x3]
 *   @0x276b4c orr r3, r2, r3, lsl #24
 *   @0x276b50 and r0, r0, #63
 *   @0x276b54 ldrb r2, [r10, #-0x2]
 *   @0x276b58 and r1, r1, #63
 *   @0x276b5c orr r3, r3, r0, lsl #18
 *   @0x276b60 and r2, r2, #63
 *   @0x276b64 orr r3, r3, r1, lsl #12
 *   @0x276b68 orr r3, r3, r2, lsl #6
 *   @0x276b6c b 0x270368 <pcre_dfa_exec+0x1e00>
 *   @0x276b70 tst r3, #4
 *   @0x276b74 bne 0x277f1c <pcre_dfa_exec+0x99b4>
 *   @0x276b78 ldrb r2, [r10, #0x4]
 *   @0x276b7c and r3, r3, #3
 *   @0x276b80 ldrb r0, [r10, #0x1]
 *   @0x276b84 add r10, r10, #5
 *   @0x276b88 and r2, r2, #63
 *   @0x276b8c ldrb r1, [r10, #-0x3]
 *   @0x276b90 orr r3, r2, r3, lsl #24
 *   @0x276b94 and r0, r0, #63
 *   @0x276b98 ldrb r2, [r10, #-0x2]
 *   @0x276b9c and r1, r1, #63
 *   @0x276ba0 orr r3, r3, r0, lsl #18
 *   @0x276ba4 and r2, r2, #63
 *   @0x276ba8 orr r3, r3, r1, lsl #12
 *   @0x276bac orr r3, r3, r2, lsl #6
 *   @0x276bb0 b 0x270cb4 <pcre_dfa_exec+0x274c>
 *   @0x276bb4 tst r3, #4
 *   @0x276bb8 bne 0x277d24 <pcre_dfa_exec+0x97bc>
 *   @0x276bbc ldrb r2, [r10, #0x4]
 *   @0x276bc0 and r3, r3, #3
 *   @0x276bc4 ldrb r0, [r10, #0x1]
 *   @0x276bc8 add r10, r10, #5
 *   @0x276bcc and r2, r2, #63
 *   @0x276bd0 ldrb r1, [r10, #-0x3]
 *   @0x276bd4 orr r3, r2, r3, lsl #24
 *   @0x276bd8 and r0, r0, #63
 *   @0x276bdc ldrb r2, [r10, #-0x2]
 *   @0x276be0 and r1, r1, #63
 *   @0x276be4 orr r3, r3, r0, lsl #18
 *   @0x276be8 and r2, r2, #63
 *   @0x276bec orr r3, r3, r1, lsl #12
 *   @0x276bf0 orr r3, r3, r2, lsl #6
 *   @0x276bf4 b 0x270d18 <pcre_dfa_exec+0x27b0>
 *   @0x276bf8 mov r4, r11
 *   @0x276bfc ldr r11, [sp, #0x18]
 *   @0x276c00 ldr r5, [sp, #0x164]
 *   @0x276c04 mov r0, r7
 *   @0x276c08 ldr r3, [sp, #0x168]
 *   @0x276c0c mov r1, r4
 *   @0x276c10 str r6, [sp]
 *   @0x276c14 add r3, r3, #1
 *   @0x276c18 str r5, [sp, #0x4]
 *   @0x276c1c str r3, [sp, #0x8]
 *   @0x276c20 mov r3, r11
 *   @0x276c24 ldr r2, [sp, #0x1c]
 *   @0x276c28 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x276c2c cmp r0, #0
 *   @0x276c30 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x276c34 cmp r10, r7
 *   @0x276c38 sub r2, r7, #1
 *   @0x276c3c beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x276c40 ldrb r3, [r7, #-0x1]
 *   @0x276c44 and r3, r3, #192
 *   @0x276c48 cmp r3, #128
 *   @0x276c4c bne 0x277394 <pcre_dfa_exec+0x8e2c>
 *   @0x276c50 sub r3, r7, #2
 *   @0x276c54 mov r7, r3
 *   @0x276c58 sub r3, r3, #1
 *   @0x276c5c ldrb r2, [r7]
 *   @0x276c60 and r2, r2, #192
 *   @0x276c64 cmp r2, #128
 *   @0x276c68 beq 0x276c54 <pcre_dfa_exec+0x86ec>
 *   @0x276c6c b 0x276c00 <pcre_dfa_exec+0x8698>
 *   @0x276c70 mov r8, r10
 *   @0x276c74 b 0x272b50 <pcre_dfa_exec+0x45e8>
 *   @0x276c78 tst r3, #4
 *   @0x276c7c bne 0x277cdc <pcre_dfa_exec+0x9774>
 *   @0x276c80 ldrb r2, [r10, #0x4]
 *   @0x276c84 and r3, r3, #3
 *   @0x276c88 ldrb r0, [r10, #0x1]
 *   @0x276c8c add r10, r10, #5
 *   @0x276c90 and r2, r2, #63
 *   @0x276c94 ldrb r1, [r10, #-0x3]
 *   @0x276c98 orr r3, r2, r3, lsl #24
 *   @0x276c9c and r0, r0, #63
 *   @0x276ca0 ldrb r2, [r10, #-0x2]
 *   @0x276ca4 and r1, r1, #63
 *   @0x276ca8 orr r3, r3, r0, lsl #18
 *   @0x276cac and r2, r2, #63
 *   @0x276cb0 orr r3, r3, r1, lsl #12
 *   @0x276cb4 orr r3, r3, r2, lsl #6
 *   @0x276cb8 b 0x2707dc <pcre_dfa_exec+0x2274>
 *   @0x276cbc tst r2, #8
 *   @0x276cc0 bne 0x277830 <pcre_dfa_exec+0x92c8>
 *   @0x276cc4 ldrb r12, [r10, #0x3]
 *   @0x276cc8 and r2, r2, #7
 *   @0x276ccc ldrb r0, [r10, #0x1]
 *   @0x276cd0 add r10, r10, #4
 *   @0x276cd4 ldrb r1, [r10, #-0x2]
 *   @0x276cd8 and r12, r12, #63
 *   @0x276cdc and r0, r0, #63
 *   @0x276ce0 orr r2, r12, r2, lsl #18
 *   @0x276ce4 and r1, r1, #63
 *   @0x276ce8 orr r2, r2, r0, lsl #12
 *   @0x276cec orr r2, r2, r1, lsl #6
 *   @0x276cf0 b 0x271770 <pcre_dfa_exec+0x3208>
 *   @0x276cf4 tst r3, #8
 *   @0x276cf8 bne 0x277e4c <pcre_dfa_exec+0x98e4>
 *   @0x276cfc ldrb r0, [r11, #0x4]
 *   @0x276d00 and r3, r3, #7
 *   @0x276d04 ldrb r1, [r11, #0x2]
 *   @0x276d08 ldrb r2, [r11, #0x3]
 *   @0x276d0c and r0, r0, #63
 *   @0x276d10 and r1, r1, #63
 *   @0x276d14 orr r3, r0, r3, lsl #18
 *   @0x276d18 and r2, r2, #63
 *   @0x276d1c orr r3, r3, r1, lsl #12
 *   @0x276d20 mov r1, #4
 *   @0x276d24 orr r3, r3, r2, lsl #6
 *   @0x276d28 b 0x26fb70 <pcre_dfa_exec+0x1608>
 *   @0x276d2c tst r3, #4
 *   @0x276d30 bne 0x277874 <pcre_dfa_exec+0x930c>
 *   @0x276d34 ldrb r2, [r10, #0x4]
 *   @0x276d38 and r3, r3, #3
 *   @0x276d3c ldrb r0, [r10, #0x1]
 *   @0x276d40 add r10, r10, #5
 *   @0x276d44 and r2, r2, #63
 *   @0x276d48 ldrb r1, [r10, #-0x3]
 *   @0x276d4c orr r3, r2, r3, lsl #24
 *   @0x276d50 and r0, r0, #63
 *   @0x276d54 ldrb r2, [r10, #-0x2]
 *   @0x276d58 and r1, r1, #63
 *   @0x276d5c orr r3, r3, r0, lsl #18
 *   @0x276d60 and r2, r2, #63
 *   @0x276d64 orr r3, r3, r1, lsl #12
 *   @0x276d68 orr r3, r3, r2, lsl #6
 *   @0x276d6c b 0x270a78 <pcre_dfa_exec+0x2510>
 *   @0x276d70 tst r3, #4
 *   @0x276d74 bne 0x277e90 <pcre_dfa_exec+0x9928>
 *   @0x276d78 ldrb r2, [r10, #0x4]
 *   @0x276d7c and r3, r3, #3
 *   @0x276d80 ldrb r0, [r10, #0x1]
 *   @0x276d84 add r10, r10, #5
 *   @0x276d88 and r2, r2, #63
 *   @0x276d8c ldrb r1, [r10, #-0x3]
 *   @0x276d90 orr r3, r2, r3, lsl #24
 *   @0x276d94 and r0, r0, #63
 *   @0x276d98 ldrb r2, [r10, #-0x2]
 *   @0x276d9c and r1, r1, #63
 *   @0x276da0 orr r3, r3, r0, lsl #18
 *   @0x276da4 and r2, r2, #63
 *   @0x276da8 orr r3, r3, r1, lsl #12
 *   @0x276dac orr r3, r3, r2, lsl #6
 *   @0x276db0 b 0x270708 <pcre_dfa_exec+0x21a0>
 *   @0x276db4 tst r3, #4
 *   @0x276db8 bne 0x277db4 <pcre_dfa_exec+0x984c>
 *   @0x276dbc ldrb r2, [r10, #0x4]
 *   @0x276dc0 and r3, r3, #3
 *   @0x276dc4 ldrb r0, [r10, #0x1]
 *   @0x276dc8 add r10, r10, #5
 *   @0x276dcc and r2, r2, #63
 *   @0x276dd0 ldrb r1, [r10, #-0x3]
 *   @0x276dd4 orr r3, r2, r3, lsl #24
 *   @0x276dd8 and r0, r0, #63
 *   @0x276ddc ldrb r2, [r10, #-0x2]
 *   @0x276de0 and r1, r1, #63
 *   @0x276de4 orr r3, r3, r0, lsl #18
 *   @0x276de8 and r2, r2, #63
 *   @0x276dec orr r3, r3, r1, lsl #12
 *   @0x276df0 orr r3, r3, r2, lsl #6
 *   @0x276df4 b 0x270bec <pcre_dfa_exec+0x2684>
 *   @0x276df8 tst r3, #4
 *   @0x276dfc bne 0x2777e0 <pcre_dfa_exec+0x9278>
 *   @0x276e00 ldrb r2, [r10, #0x4]
 *   @0x276e04 and r3, r3, #3
 *   @0x276e08 ldrb r0, [r10, #0x1]
 *   @0x276e0c add r10, r10, #5
 *   @0x276e10 and r2, r2, #63
 *   @0x276e14 ldrb r1, [r10, #-0x3]
 *   @0x276e18 orr r3, r2, r3, lsl #24
 *   @0x276e1c and r0, r0, #63
 *   @0x276e20 ldrb r2, [r10, #-0x2]
 *   @0x276e24 and r1, r1, #63
 *   @0x276e28 orr r3, r3, r0, lsl #18
 *   @0x276e2c and r2, r2, #63
 *   @0x276e30 orr r3, r3, r1, lsl #12
 *   @0x276e34 orr r3, r3, r2, lsl #6
 *   @0x276e38 b 0x270c50 <pcre_dfa_exec+0x26e8>
 *   @0x276e3c ldrb r0, [r10, #0x5]
 *   @0x276e40 and r3, r3, #1
 *   @0x276e44 ldrb r1, [r10, #0x1]
 *   @0x276e48 add r10, r10, #6
 *   @0x276e4c and r0, r0, #63
 *   @0x276e50 ldrb r12, [r10, #-0x4]
 *   @0x276e54 and r1, r1, #63
 *   @0x276e58 orr r3, r0, r3, lsl #30
 *   @0x276e5c ldrb r0, [r10, #-0x3]
 *   @0x276e60 and r12, r12, #63
 *   @0x276e64 orr r3, r3, r1, lsl #24
 *   @0x277324 ldr r2, [r6, #0x84]
 *   @0x277328 cmp r10, r2
 *   @0x27732c bhi 0x271820 <pcre_dfa_exec+0x32b8>
 *   @0x277330 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277334 mov r5, r7
 *   @0x277338 mov r10, r2
 *   @0x27733c mov r7, r9
 *   @0x277340 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x277344 mov r0, #0
 *   @0x277348 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27734c ldrb r0, [r10, #0x5]
 *   @0x277350 and r3, r3, #1
 *   @0x277354 ldrb r1, [r10, #0x1]
 *   @0x277358 add r10, r10, #6
 *   @0x27735c and r0, r0, #63
 *   @0x277360 ldrb r12, [r10, #-0x4]
 *   @0x277364 and r1, r1, #63
 *   @0x277368 orr r3, r0, r3, lsl #30
 *   @0x27736c ldrb r0, [r10, #-0x3]
 *   @0x277370 and r12, r12, #63
 *   @0x277374 orr r3, r3, r1, lsl #24
 *   @0x277378 ldrb r1, [r10, #-0x2]
 *   @0x27737c and r0, r0, #63
 *   @0x277380 orr r3, r3, r12, lsl #18
 *   @0x277384 and r1, r1, #63
 *   @0x277388 orr r3, r3, r0, lsl #12
 *   @0x27738c orr r3, r3, r1, lsl #6
 *   @0x277390 b 0x271b6c <pcre_dfa_exec+0x3604>
 *   @0x277394 mov r7, r2
 *   @0x277398 b 0x276c00 <pcre_dfa_exec+0x8698>
 *   @0x27739c ldrb r1, [r7, #-0x1]
 *   @0x2773a0 ldrb r2, [r6, #0x34]
 *   @0x2773a4 cmp r1, r2
 *   @0x2773a8 bne 0x273838 <pcre_dfa_exec+0x52d0>
 *   @0x2773ac cmp r3, #1
 *   @0x2773b0 mov r12, #1
 *   @0x2773b4 str r12, [r6, #0x64]
 *   @0x2773b8 ble 0x273838 <pcre_dfa_exec+0x52d0>
 *   @0x2773bc b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x2773c0 add r4, r10, r8
 *   @0x2773c4 b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x2773c8 ldr r1, [sp, #0x24]
 *   @0x2773cc b 0x273cf4 <pcre_dfa_exec+0x578c>
 *   @0x2773d0 ldrb r2, [r4, #0x5]
 *   @0x2773d4 and r3, r3, #1
 *   @0x2773d8 ldrb r1, [r4, #0x1]
 *   @0x2773dc and r2, r2, #63
 *   @0x2773e0 ldrb r0, [r4, #0x2]
 *   @0x2773e4 and r1, r1, #63
 *   @0x2773e8 orr r3, r2, r3, lsl #30
 *   @0x2773ec ldrb r2, [r4, #0x3]
 *   @0x2773f0 and r0, r0, #63
 *   @0x2773f4 orr r3, r3, r1, lsl #24
 *   @0x2773f8 ldrb r1, [r4, #0x4]
 *   @0x2773fc and r2, r2, #63
 *   @0x277400 orr r3, r3, r0, lsl #18
 *   @0x277404 and r1, r1, #63
 *   @0x277408 orr r3, r3, r2, lsl #12
 *   @0x27740c mov r2, #6
 *   @0x277410 orr r3, r3, r1, lsl r2
 *   @0x277414 b 0x272888 <pcre_dfa_exec+0x4320>
 *   @0x277418 ldrb r3, [r4]
 *   @0x27741c ldr r2, [r6, #0x8c]
 *   @0x277420 ldr r7, [sp, #0x18]
 *   @0x277424 cmp r7, r2
 *   @0x277428 movlt r7, r2
 *   @0x27742c cmp r3, #146
 *   @0x277430 addeq r4, r4, #1
 *   @0x277434 str r7, [sp, #0x18]
 *   @0x277438 ldrb r2, [r4, #0x1]
 *   @0x27743c ldrb r3, [r4, #0x2]
 *   @0x277440 orr r2, r3, r2, lsl #8
 *   @0x277444 add r3, r4, r2
 *   @0x277448 ldrb r2, [r4, r2]
 *   @0x27744c cmp r2, #119
 *   @0x277450 bne 0x27746c <pcre_dfa_exec+0x8f04>
 *   @0x277454 ldrb r1, [r3, #0x1]
 *   @0x277458 ldrb r2, [r3, #0x2]
 *   @0x27745c orr r2, r2, r1, lsl #8
 *   @0x277460 ldrb r2, [r3, r2]!
 *   @0x277464 cmp r2, #119
 *   @0x277468 beq 0x277454 <pcre_dfa_exec+0x8eec>
 *   @0x27746c ldr r2, [pc, #0xfc0]
 *   @0x277470 ldr r12, [sp, #0x20]
 *   @0x277474 ldr r7, [r12, r2]
 *   @0x277478 ldrb r2, [r7, r8]
 *   @0x27747c rsb r4, r2, #3
 *   @0x277480 add r4, r3, r4
 *   @0x277484 mov r3, r2
 *   @0x277488 b 0x2721e0 <pcre_dfa_exec+0x3c78>
 *   @0x27748c add r4, r10, r8
 *   @0x277490 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277494 mov r5, #1
 *   @0x277498 str r1, [sp, #0x2c]
 *   @0x27749c mov r4, r1
 *   @0x2774a0 mov r7, r5
 *   @0x2774a4 b 0x2701bc <pcre_dfa_exec+0x1c54>
 *   @0x2774a8 ldrb r1, [r4, #0x5]
 *   @0x2774ac and r3, r3, #1
 *   @0x2774b0 ldrb r2, [r4, #0x1]
 *   @0x2774b4 and r1, r1, #63
 *   @0x2774b8 ldrb r0, [r4, #0x2]
 *   @0x2774bc and r2, r2, #63
 *   @0x2774c0 orr r3, r1, r3, lsl #30
 *   @0x2774c4 ldrb r1, [r4, #0x3]
 *   @0x2774c8 and r0, r0, #63
 *   @0x2774cc orr r2, r3, r2, lsl #24
 *   @0x2774d0 ldrb r3, [r4, #0x4]
 *   @0x2774d4 and r1, r1, #63
 *   @0x2774d8 orr r2, r2, r0, lsl #18
 *   @0x2774dc and r3, r3, #63
 *   @0x2774e0 orr r1, r2, r1, lsl #12
 *   @0x2774e4 mov r2, #6
 *   @0x2774e8 orr r3, r1, r3, lsl r2
 *   @0x2774ec b 0x272a30 <pcre_dfa_exec+0x44c8>
 *   @0x2774f0 ldrb r2, [r4, #0x5]
 *   @0x2774f4 and r3, r3, #1
 *   @0x2774f8 ldrb r1, [r4, #0x1]
 *   @0x2774fc and r2, r2, #63
 *   @0x277500 ldrb r0, [r4, #0x2]
 *   @0x277504 and r1, r1, #63
 *   @0x277508 orr r3, r2, r3, lsl #30
 *   @0x27750c ldrb r2, [r4, #0x3]
 *   @0x277510 and r0, r0, #63
 *   @0x277514 orr r3, r3, r1, lsl #24
 *   @0x277518 ldrb r1, [r4, #0x4]
 *   @0x27751c and r2, r2, #63
 *   @0x277520 orr r3, r3, r0, lsl #18
 *   @0x277524 and r1, r1, #63
 *   @0x277528 orr r3, r3, r2, lsl #12
 *   @0x27752c mov r2, #6
 *   @0x277530 orr r3, r3, r1, lsl r2
 *   @0x277534 b 0x2729b4 <pcre_dfa_exec+0x444c>
 *   @0x277538 mov r4, r10
 *   @0x27753c ldr r2, [r6, #0x88]
 *   @0x277540 cmp r2, #0
 *   @0x277544 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277548 ldr r3, [r6, #0x84]
 *   @0x27754c cmp r3, r4
 *   @0x277550 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277554 b 0x2728ec <pcre_dfa_exec+0x4384>
 *   @0x277558 ldr r1, [r6, #0x18]
 *   @0x27755c cmp r1, #0
 *   @0x277560 beq 0x277f64 <pcre_dfa_exec+0x99fc>
 *   @0x277564 ldr r12, [sp, #0x28]
 *   @0x277568 mov r0, r10
 *   @0x27756c ldr r3, [sp, #0x18]
 *   @0x277570 str r12, [sp]
 *   @0x277574 bl 0x25f9fc <_pcre_is_newline>
 *   @0x277578 adds r0, r0, #0
 *   @0x27757c movne r0, #1
 *   @0x277580 cmp r0, #0
 *   @0x277584 beq 0x2770a4 <pcre_dfa_exec+0x8b3c>
 *   @0x277588 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27758c mov r7, r10
 *   @0x277590 ldr r2, [r6, #0x88]
 *   @0x277594 cmp r2, #0
 *   @0x277598 beq 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x27759c ldr r3, [r6, #0x84]
 *   @0x2775a0 cmp r3, r7
 *   @0x2775a4 bhs 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x2775a8 cmp r2, #1
 *   @0x2775ac mov r12, #1
 *   @0x2775b0 str r12, [r6, #0x64]
 *   @0x2775b4 ble 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x2775b8 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x2775bc ldrb r2, [r4, #0x5]
 *   @0x2775c0 and r3, r3, #1
 *   @0x2775c4 ldrb r1, [r4, #0x1]
 *   @0x2775c8 and r2, r2, #63
 *   @0x2775cc ldrb r0, [r4, #0x2]
 *   @0x2775d0 and r1, r1, #63
 *   @0x2775d4 orr r3, r2, r3, lsl #30
 *   @0x2775d8 ldrb r2, [r4, #0x3]
 *   @0x2775dc and r0, r0, #63
 *   @0x2775e0 orr r3, r3, r1, lsl #24
 *   @0x2775e4 ldrb r1, [r4, #0x4]
 *   @0x2775e8 and r2, r2, #63
 *   @0x2775ec orr r3, r3, r0, lsl #18
 *   @0x2775f0 and r1, r1, #63
 *   @0x2775f4 orr r3, r3, r2, lsl #12
 *   @0x2775f8 mov r2, #6
 *   @0x2775fc orr r3, r3, r1, lsl r2
 *   @0x277600 b 0x272938 <pcre_dfa_exec+0x43d0>
 *   @0x277604 tst r3, #16
 *   @0x277608 bne 0x27859c <pcre_dfa_exec+0xa034>
 *   @0x27760c lsl r1, r3, #12
 *   @0x277610 ldrb r2, [r10, #0x1]
 *   @0x277614 ldrb r3, [r10, #0x2]
 *   @0x277618 add r10, r10, #3
 *   @0x27761c uxth r1, r1
 *   @0x277620 and r2, r2, #63
 *   @0x277624 and r3, r3, #63
 *   @0x277628 orr r3, r1, r3
 *   @0x27762c orr r3, r3, r2, lsl #6
 *   @0x277630 b 0x2770cc <pcre_dfa_exec+0x8b64>
 *   @0x277634 mov r5, r10
 *   @0x277638 ldr r2, [r6, #0x88]
 *   @0x27763c cmp r2, #0
 *   @0x277640 beq 0x271344 <pcre_dfa_exec+0x2ddc>
 *   @0x277644 ldr r3, [r6, #0x84]
 *   @0x277648 cmp r3, r5
 *   @0x27764c bhs 0x271344 <pcre_dfa_exec+0x2ddc>
 *   @0x277650 cmp r2, #1
 *   @0x277654 mov r7, #1
 *   @0x277658 str r7, [r6, #0x64]
 *   @0x27765c ble 0x271344 <pcre_dfa_exec+0x2ddc>
 *   @0x277660 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x277664 ldrb r1, [r10, #0x5]
 *   @0x277668 and r3, r3, #1
 *   @0x27766c ldrb r2, [r10, #0x1]
 *   @0x277670 add r10, r10, #6
 *   @0x277674 and r1, r1, #63
 *   @0x277678 ldrb r0, [r10, #-0x4]
 *   @0x27767c and r2, r2, #63
 *   @0x277680 orr r3, r1, r3, lsl #30
 *   @0x277684 ldrb r1, [r10, #-0x3]
 *   @0x277688 and r0, r0, #63
 *   @0x27768c orr r3, r3, r2, lsl #24
 *   @0x277690 ldrb r2, [r10, #-0x2]
 *   @0x277694 and r1, r1, #63
 *   @0x277698 orr r3, r3, r0, lsl #18
 *   @0x27769c and r2, r2, #63
 *   @0x2776a0 orr r3, r3, r1, lsl #12
 *   @0x2776a4 orr r3, r3, r2, lsl #6
 *   @0x2776a8 b 0x270368 <pcre_dfa_exec+0x1e00>
 *   @0x2776ac mov r4, r2
 *   @0x2776b0 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x2776b4 tst r3, #8
 *   @0x2776b8 bne 0x27820c <pcre_dfa_exec+0x9ca4>
 *   @0x2776bc ldrb r12, [r10, #0x3]
 *   @0x2776c0 and r3, r3, #7
 *   @0x2776c4 ldrb r1, [r10, #0x1]
 *   @0x2776c8 ldrb r2, [r10, #0x2]
 *   @0x2776cc and r12, r12, #63
 *   @0x2776d0 and r1, r1, #63
 *   @0x2776d4 orr r3, r12, r3, lsl #18
 *   @0x2776d8 and r2, r2, #63
 *   @0x2776dc orr r3, r3, r1, lsl #12
 *   @0x2776e0 orr r3, r3, r2, lsl #6
 *   @0x2776e4 b 0x275258 <pcre_dfa_exec+0x6cf0>
 *   @0x2776e8 ldrb r1, [r4, #0x5]
 *   @0x2776ec and r3, r3, #1
 *   @0x2776f0 ldrb r2, [r4, #0x1]
 *   @0x2776f4 and r1, r1, #63
 *   @0x2776f8 ldrb r0, [r4, #0x2]
 *   @0x2776fc and r2, r2, #63
 *   @0x277700 orr r3, r1, r3, lsl #30
 *   @0x277704 ldrb r1, [r4, #0x3]
 *   @0x277708 and r0, r0, #63
 *   @0x27770c orr r2, r3, r2, lsl #24
 *   @0x277710 ldrb r3, [r4, #0x4]
 *   @0x277714 and r1, r1, #63
 *   @0x277718 orr r2, r2, r0, lsl #18
 *   @0x27771c and r3, r3, #63
 *   @0x277720 orr r1, r2, r1, lsl #12
 *   @0x277724 mov r2, #6
 *   @0x277728 orr r3, r1, r3, lsl r2
 *   @0x27772c b 0x2727b0 <pcre_dfa_exec+0x4248>
 *   @0x277730 cmp r3, #1
 *   @0x277734 moveq r0, r1
 *   @0x277738 beq 0x2717d4 <pcre_dfa_exec+0x326c>
 *   @0x27773c ldrb r0, [r10, #0x1]
 *   @0x277740 ldrb r3, [r6, #0x35]
 *   @0x277744 subs r0, r0, r3
 *   @0x277748 movne r0, #1
 *   @0x27774c b 0x2717d4 <pcre_dfa_exec+0x326c>
 *   @0x277750 tst r2, #8
 *   @0x277754 bne 0x27824c <pcre_dfa_exec+0x9ce4>
 *   @0x277758 ldrb r4, [r10, #0x3]
 *   @0x27775c and r2, r2, #7
 *   @0x277760 ldrb r12, [r10, #0x1]
 *   @0x277764 add r10, r10, #4
 *   @0x277768 ldrb r0, [r10, #-0x2]
 *   @0x27776c and r4, r4, #63
 *   @0x277770 and r12, r12, #63
 *   @0x277774 orr r2, r4, r2, lsl #18
 *   @0x277778 and r0, r0, #63
 *   @0x27777c orr r2, r2, r12, lsl #12
 *   @0x277780 orr r2, r2, r0, lsl #6
 *   @0x277784 b 0x2753b4 <pcre_dfa_exec+0x6e4c>
 *   @0x277788 ldrb r1, [r4, #0x5]
 *   @0x27778c and r12, r3, #1
 *   @0x277790 ldrb r2, [r4, #0x1]
 *   @0x277794 ldrb r3, [r4, #0x2]
 *   @0x277798 and r1, r1, #63
 *   @0x27779c and r2, r2, #63
 *   @0x2777a0 str r2, [sp, #0x50]
 *   @0x2777a4 orr r2, r1, r12, lsl #30
 *   @0x2777a8 and r12, r3, #63
 *   @0x2777ac ldr r3, [sp, #0x50]
 *   @0x2777b0 str r12, [sp, #0x2c]
 *   @0x2777b4 ldrb r1, [r4, #0x3]
 *   @0x2777b8 orr r2, r2, r3, lsl #24
 *   @0x2777bc ldr r3, [sp, #0x2c]
 *   @0x2777c0 ldrb r12, [r4, #0x4]
 *   @0x2777c4 and r1, r1, #63
 *   @0x2777c8 orr r2, r2, r3, lsl #18
 *   @0x2777cc and r12, r12, #63
 *   @0x2777d0 orr r3, r2, r1, lsl #12
 *   @0x2777d4 mov r2, #6
 *   @0x2777d8 orr r3, r3, r12, lsl r2
 *   @0x2777dc b 0x272414 <pcre_dfa_exec+0x3eac>
 *   @0x2777e0 ldrb r1, [r10, #0x5]
 *   @0x2777e4 and r3, r3, #1
 *   @0x2777e8 ldrb r2, [r10, #0x1]
 *   @0x2777ec add r10, r10, #6
 *   @0x2777f0 and r1, r1, #63
 *   @0x2777f4 ldrb r0, [r10, #-0x4]
 *   @0x2777f8 and r2, r2, #63
 *   @0x2777fc orr r3, r1, r3, lsl #30
 *   @0x277800 ldrb r1, [r10, #-0x3]
 *   @0x277804 and r0, r0, #63
 *   @0x277808 orr r3, r3, r2, lsl #24
 *   @0x27780c ldrb r2, [r10, #-0x2]
 *   @0x277810 and r1, r1, #63
 *   @0x277814 orr r3, r3, r0, lsl #18
 *   @0x277818 and r2, r2, #63
 *   @0x27781c orr r3, r3, r1, lsl #12
 *   @0x277820 orr r3, r3, r2, lsl #6
 *   @0x277824 b 0x270c50 <pcre_dfa_exec+0x26e8>
 *   @0x277828 mov r2, r3
 *   @0x27782c b 0x273b94 <pcre_dfa_exec+0x562c>
 *   @0x277830 tst r2, #4
 *   @0x277834 bne 0x27850c <pcre_dfa_exec+0x9fa4>
 *   @0x277838 ldrb r1, [r10, #0x4]
 *   @0x27783c and r2, r2, #3
 *   @0x277840 ldrb r12, [r10, #0x1]
 *   @0x277844 add r10, r10, #5
 *   @0x277848 and r1, r1, #63
 *   @0x27784c ldrb r0, [r10, #-0x3]
 *   @0x277850 orr r2, r1, r2, lsl #24
 *   @0x277854 and r12, r12, #63
 *   @0x277858 ldrb r1, [r10, #-0x2]
 *   @0x27785c and r0, r0, #63
 *   @0x277860 orr r2, r2, r12, lsl #18
 *   @0x277864 and r1, r1, #63
 *   @0x277868 orr r2, r2, r0, lsl #12
 *   @0x27786c orr r2, r2, r1, lsl #6
 *   @0x277870 b 0x271770 <pcre_dfa_exec+0x3208>
 *   @0x277874 ldrb r1, [r10, #0x5]
 *   @0x277878 and r3, r3, #1
 *   @0x27787c ldrb r2, [r10, #0x1]
 *   @0x277880 add r10, r10, #6
 *   @0x277884 and r1, r1, #63
 *   @0x277888 ldrb r0, [r10, #-0x4]
 *   @0x27788c and r2, r2, #63
 *   @0x277890 orr r3, r1, r3, lsl #30
 *   @0x277894 ldrb r1, [r10, #-0x3]
 *   @0x277898 and r0, r0, #63
 *   @0x27789c orr r3, r3, r2, lsl #24
 *   @0x2778a0 ldrb r2, [r10, #-0x2]
 *   @0x2778a4 and r1, r1, #63
 *   @0x2778a8 orr r3, r3, r0, lsl #18
 *   @0x2778ac and r2, r2, #63
 *   @0x2778b0 orr r3, r3, r1, lsl #12
 *   @0x2778b4 orr r3, r3, r2, lsl #6
 *   @0x2778b8 b 0x270a78 <pcre_dfa_exec+0x2510>
 *   @0x2778bc ldrb r1, [r10, #0x5]
 *   @0x2778c0 and r3, r3, #1
 *   @0x2778c4 ldrb r2, [r10, #0x1]
 *   @0x2778c8 add r10, r10, #6
 *   @0x2778cc and r1, r1, #63
 *   @0x2778d0 ldrb r0, [r10, #-0x4]
 *   @0x2778d4 and r2, r2, #63
 *   @0x2778d8 orr r3, r1, r3, lsl #30
 *   @0x2778dc ldrb r1, [r10, #-0x3]
 *   @0x2778e0 and r0, r0, #63
 *   @0x2778e4 orr r3, r3, r2, lsl #24
 *   @0x2778e8 ldrb r2, [r10, #-0x2]
 *   @0x2778ec and r1, r1, #63
 *   @0x2778f0 orr r3, r3, r0, lsl #18
 *   @0x2778f4 and r2, r2, #63
 *   @0x2778f8 orr r3, r3, r1, lsl #12
 *   @0x2778fc orr r3, r3, r2, lsl #6
 *   @0x277900 b 0x2703d0 <pcre_dfa_exec+0x1e68>
 *   @0x277904 ldr r12, [sp, #0x20]
 *   @0x277908 add r9, r6, #28
 *   @0x27790c mov r8, #1
 *   @0x277910 sub r5, r12, #6
 *   @0x277914 ldr r12, [sp, #0x164]
 *   @0x277918 mov r0, r10
 *   @0x27791c ldr r3, [sp, #0x168]
 *   @0x277920 mov r1, r4
 *   @0x277924 str r6, [sp]
 *   @0x277928 add r3, r3, #1
 *   @0x27792c str r12, [sp, #0x4]
 *   @0x277930 str r3, [sp, #0x8]
 *   @0x277934 mov r3, r11
 *   @0x277938 ldr r2, [sp, #0x1c]
 *   @0x27793c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x277940 cmp r0, #0
 *   @0x277944 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277948 ldr r12, [sp, #0x24]
 *   @0x27794c cmp r7, r12
 *   @0x277950 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277954 ldr r2, [r6, #0x78]
 *   @0x277958 cmp r10, r2
 *   @0x27795c bhs 0x279320 <pcre_dfa_exec+0xadb8>
 *   @0x277960 ldr r12, [sp, #0x20]
 *   @0x277964 cmp r12, #12
 *   @0x277968 beq 0x277b58 <pcre_dfa_exec+0x95f0>
 *   @0x27796c add r2, r10, #1
 *   @0x277970 ldrb r3, [r10]
 *   @0x277974 cmp r5, #15
 *   @0x277978 addls pc, pc, r5, lsl #2
 *   @0x27797c b 0x277ab0 <pcre_dfa_exec+0x9548>
 *   @0x277980 b 0x277a9c <pcre_dfa_exec+0x9534>
 *   @0x277984 b 0x277a88 <pcre_dfa_exec+0x9520>
 *   @0x277988 b 0x277a74 <pcre_dfa_exec+0x950c>
 *   @0x27798c b 0x277a60 <pcre_dfa_exec+0x94f8>
 *   @0x277990 b 0x277a4c <pcre_dfa_exec+0x94e4>
 *   @0x277994 b 0x277a38 <pcre_dfa_exec+0x94d0>
 *   @0x277998 b 0x2779ec <pcre_dfa_exec+0x9484>
 *   @0x27799c b 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x2779a0 b 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x2779a4 b 0x277ab0 <pcre_dfa_exec+0x9548>
 *   @0x2779a8 b 0x277ab0 <pcre_dfa_exec+0x9548>
 *   @0x2779ac b 0x277b38 <pcre_dfa_exec+0x95d0>
 *   @0x2779b0 b 0x277b18 <pcre_dfa_exec+0x95b0>
 *   @0x2779b4 b 0x277af8 <pcre_dfa_exec+0x9590>
 *   @0x2779b8 b 0x277ad8 <pcre_dfa_exec+0x9570>
 *   @0x2779bc b 0x277ab8 <pcre_dfa_exec+0x9550>
 *   @0x2779c0 cmp r3, #13
 *   @0x2779c4 bne 0x278d94 <pcre_dfa_exec+0xa82c>
 *   @0x2779c8 ldr r3, [r6, #0x78]
 *   @0x2779cc cmp r2, r3
 *   @0x2779d0 bhs 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x2779d4 ldrb r3, [r10, #0x1]
 *   @0x2779d8 cmp r3, #10
 *   @0x2779dc addeq r2, r10, #2
 *   @0x2779e0 add r7, r7, #1
 *   @0x2779e4 mov r10, r2
 *   @0x2779e8 b 0x277914 <pcre_dfa_exec+0x93ac>
 *   @0x2779ec ldr r1, [r6, #0x88]
 *   @0x2779f0 cmp r1, #0
 *   @0x2779f4 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x2779f8 ldr r0, [r6, #0x78]
 *   @0x2779fc cmp r2, r0
 *   @0x277a00 blo 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a04 ldr r0, [r6, #0x18]
 *   @0x277a08 cmp r0, #0
 *   @0x277a0c bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a10 ldr r0, [r6, #0x1c]
 *   @0x277a14 cmp r0, #2
 *   @0x277a18 bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a1c ldrb r0, [r6, #0x34]
 *   @0x277a20 cmp r0, r3
 *   @0x277a24 bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a28 cmp r1, #1
 *   @0x277a2c str r8, [r6, #0x64]
 *   @0x277a30 ble 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a34 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x277a38 ldr r1, [r6, #0x40]
 *   @0x277a3c ldrb r3, [r1, r3]
 *   @0x277a40 tst r3, #16
 *   @0x277a44 bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a48 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277a4c ldr r1, [r6, #0x40]
 *   @0x277a50 ldrb r3, [r1, r3]
 *   @0x277a54 tst r3, #16
 *   @0x277a58 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a5c b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277a60 ldr r1, [r6, #0x40]
 *   @0x277a64 ldrb r3, [r1, r3]
 *   @0x277a68 tst r3, #1
 *   @0x277a6c bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a70 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277a74 ldr r1, [r6, #0x40]
 *   @0x277a78 ldrb r3, [r1, r3]
 *   @0x277a7c tst r3, #1
 *   @0x277a80 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a84 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277a88 ldr r1, [r6, #0x40]
 *   @0x277a8c ldrb r3, [r1, r3]
 *   @0x277a90 tst r3, #4
 *   @0x277a94 bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277a98 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277a9c ldr r1, [r6, #0x40]
 *   @0x277aa0 ldrb r3, [r1, r3]
 *   @0x277aa4 tst r3, #4
 *   @0x277aa8 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277aac b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277ab0 mvn r0, #13
 *   @0x277ab4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277ab8 cmp r3, #10
 *   @0x277abc blo 0x277ad0 <pcre_dfa_exec+0x9568>
 *   @0x277ac0 cmp r3, #13
 *   @0x277ac4 bls 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277ac8 cmp r3, #133
 *   @0x277acc beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277ad0 mov r0, #0
 *   @0x277ad4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277ad8 cmp r3, #10
 *   @0x277adc blo 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277ae0 cmp r3, #13
 *   @0x277ae4 bls 0x277af0 <pcre_dfa_exec+0x9588>
 *   @0x277ae8 cmp r3, #133
 *   @0x277aec bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277af0 mov r0, #0
 *   @0x277af4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277af8 cmp r3, #32
 *   @0x277afc beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277b00 cmp r3, #160
 *   @0x277b04 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277b08 cmp r3, #9
 *   @0x277b0c beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277b10 mov r0, #0
 *   @0x277b14 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277b18 cmp r3, #32
 *   @0x277b1c beq 0x277b30 <pcre_dfa_exec+0x95c8>
 *   @0x277b20 cmp r3, #160
 *   @0x277b24 beq 0x277b30 <pcre_dfa_exec+0x95c8>
 *   @0x277b28 cmp r3, #9
 *   @0x277b2c bne 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277b30 mov r0, #0
 *   @0x277b34 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277b38 cmp r3, #12
 *   @0x277b3c bhi 0x2779c0 <pcre_dfa_exec+0x9458>
 *   @0x277b40 cmp r3, #11
 *   @0x277b44 bhs 0x278d9c <pcre_dfa_exec+0xa834>
 *   @0x277b48 cmp r3, #10
 *   @0x277b4c beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x277b50 mov r0, #0
 *   @0x277b54 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277b58 ldr r1, [r6, #0x18]
 *   @0x277b5c cmp r1, #0
 *   @0x277b60 beq 0x277f90 <pcre_dfa_exec+0x9a28>
 *   @0x277b64 str r0, [sp]
 *   @0x277b68 mov r3, r9
 *   @0x277b6c mov r0, r10
 *   @0x277b70 bl 0x25f9fc <_pcre_is_newline>
 *   @0x277b74 adds r0, r0, #0
 *   @0x277b78 movne r0, #1
 *   @0x277b7c cmp r0, #0
 *   @0x277b80 beq 0x27796c <pcre_dfa_exec+0x9404>
 *   @0x277b84 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277b88 mov r10, r8
 *   @0x277b8c b 0x273258 <pcre_dfa_exec+0x4cf0>
 *   @0x277b90 ldrb r1, [r10, #0x5]
 *   @0x277b94 and r3, r3, #1
 *   @0x277b98 ldrb r2, [r10, #0x1]
 *   @0x277b9c add r10, r10, #6
 *   @0x277ba0 and r1, r1, #63
 *   @0x277ba4 ldrb r0, [r10, #-0x4]
 *   @0x277ba8 and r2, r2, #63
 *   @0x277bac orr r3, r1, r3, lsl #30
 *   @0x277bb0 ldrb r1, [r10, #-0x3]
 *   @0x277bb4 and r0, r0, #63
 *   @0x277bb8 orr r3, r3, r2, lsl #24
 *   @0x277bbc ldrb r2, [r10, #-0x2]
 *   @0x277bc0 and r1, r1, #63
 *   @0x277bc4 orr r3, r3, r0, lsl #18
 *   @0x277bc8 and r2, r2, #63
 *   @0x277bcc orr r3, r3, r1, lsl #12
 *   @0x277bd0 orr r3, r3, r2, lsl #6
 *   @0x277bd4 b 0x27076c <pcre_dfa_exec+0x2204>
 *   @0x277bd8 ldrb r1, [r4, #0x5]
 *   @0x277bdc and r3, r3, #1
 *   @0x277be0 ldrb r2, [r4, #0x1]
 *   @0x277be4 and r1, r1, #63
 *   @0x277be8 ldrb r0, [r4, #0x2]
 *   @0x277bec and r2, r2, #63
 *   @0x277bf0 orr r3, r1, r3, lsl #30
 *   @0x277bf4 ldrb r1, [r4, #0x3]
 *   @0x277bf8 and r0, r0, #63
 *   @0x277bfc orr r2, r3, r2, lsl #24
 *   @0x277c00 ldrb r3, [r4, #0x4]
 *   @0x277c04 and r1, r1, #63
 *   @0x277c08 orr r2, r2, r0, lsl #18
 *   @0x277c0c and r3, r3, #63
 *   @0x277c10 orr r1, r2, r1, lsl #12
 *   @0x277c14 mov r2, #6
 *   @0x277c18 orr r3, r1, r3, lsl r2
 *   @0x277c1c b 0x272734 <pcre_dfa_exec+0x41cc>
 *   @0x277c20 tst r3, #4
 *   @0x277c24 bne 0x2783ec <pcre_dfa_exec+0x9e84>
 *   @0x277c28 ldrb r2, [r11, #0x5]
 *   @0x277c2c and r3, r3, #3
 *   @0x277c30 ldrb r0, [r11, #0x2]
 *   @0x277c34 add r11, r11, #6
 *   @0x277c38 and r2, r2, #63
 *   @0x277c3c ldrb r1, [r11, #-0x3]
 *   @0x277c40 orr r3, r2, r3, lsl #24
 *   @0x277c44 and r0, r0, #63
 *   @0x277c48 ldrb r2, [r11, #-0x2]
 *   @0x277c4c and r1, r1, #63
 *   @0x277c50 orr r3, r3, r0, lsl #18
 *   @0x277c54 and r2, r2, #63
 *   @0x277c58 orr r3, r3, r1, lsl #12
 *   @0x277c5c orr r3, r3, r2, lsl #6
 *   @0x277c60 b 0x271744 <pcre_dfa_exec+0x31dc>
 *   @0x277c64 ldr r2, [r6, #0x88]
 *   @0x277c68 ldr r4, [r6, #0x78]
 *   @0x277c6c cmp r2, #0
 *   @0x277c70 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277c74 ldr r3, [r6, #0x84]
 *   @0x277c78 cmp r4, r3
 *   @0x277c7c bls 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277c80 cmp r2, #1
 *   @0x277c84 mov r2, #1
 *   @0x277c88 str r2, [r6, #0x64]
 *   @0x277c8c ble 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x277c90 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x277c94 ldrb r1, [r10, #0x5]
 *   @0x277c98 and r3, r3, #1
 *   @0x277c9c ldrb r2, [r10, #0x1]
 *   @0x277ca0 add r10, r10, #6
 *   @0x277ca4 and r1, r1, #63
 *   @0x277ca8 ldrb r0, [r10, #-0x4]
 *   @0x277cac and r2, r2, #63
 *   @0x277cb0 orr r3, r1, r3, lsl #30
 *   @0x277cb4 ldrb r1, [r10, #-0x3]
 *   @0x277cb8 and r0, r0, #63
 *   @0x277cbc orr r3, r3, r2, lsl #24
 *   @0x277cc0 ldrb r2, [r10, #-0x2]
 *   @0x277cc4 and r1, r1, #63
 *   @0x277cc8 orr r3, r3, r0, lsl #18
 *   @0x277ccc and r2, r2, #63
 *   @0x277cd0 orr r3, r3, r1, lsl #12
 *   @0x277cd4 orr r3, r3, r2, lsl #6
 *   @0x277cd8 b 0x270938 <pcre_dfa_exec+0x23d0>
 *   @0x277cdc ldrb r1, [r10, #0x5]
 *   @0x277ce0 and r3, r3, #1
 *   @0x277ce4 ldrb r2, [r10, #0x1]
 *   @0x277ce8 add r10, r10, #6
 *   @0x277cec and r1, r1, #63
 *   @0x277cf0 ldrb r0, [r10, #-0x4]
 *   @0x277cf4 and r2, r2, #63
 *   @0x277cf8 orr r3, r1, r3, lsl #30
 *   @0x277cfc ldrb r1, [r10, #-0x3]
 *   @0x277d00 and r0, r0, #63
 *   @0x277d04 orr r3, r3, r2, lsl #24
 *   @0x277d08 ldrb r2, [r10, #-0x2]
 *   @0x277d0c and r1, r1, #63
 *   @0x277d10 orr r3, r3, r0, lsl #18
 *   @0x277d14 and r2, r2, #63
 *   @0x277d18 orr r3, r3, r1, lsl #12
 *   @0x277d1c orr r3, r3, r2, lsl #6
 *   @0x277d20 b 0x2707dc <pcre_dfa_exec+0x2274>
 *   @0x277d24 ldrb r1, [r10, #0x5]
 *   @0x277d28 and r3, r3, #1
 *   @0x277d2c ldrb r2, [r10, #0x1]
 *   @0x277d30 add r10, r10, #6
 *   @0x277d34 and r1, r1, #63
 *   @0x277d38 ldrb r0, [r10, #-0x4]
 *   @0x277d3c and r2, r2, #63
 *   @0x277d40 orr r3, r1, r3, lsl #30
 *   @0x277d44 ldrb r1, [r10, #-0x3]
 *   @0x277d48 and r0, r0, #63
 *   @0x277d4c orr r3, r3, r2, lsl #24
 *   @0x277d50 ldrb r2, [r10, #-0x2]
 *   @0x277d54 and r1, r1, #63
 *   @0x277d58 orr r3, r3, r0, lsl #18
 *   @0x277d5c and r2, r2, #63
 *   @0x277d60 orr r3, r3, r1, lsl #12
 *   @0x277d64 orr r3, r3, r2, lsl #6
 *   @0x277d68 b 0x270d18 <pcre_dfa_exec+0x27b0>
 *   @0x277d6c ldrb r1, [r4, #0x5]
 *   @0x277d70 and r3, r3, #1
 *   @0x277d74 ldrb r2, [r4, #0x1]
 *   @0x277d78 and r1, r1, #63
 *   @0x277d7c ldrb r0, [r4, #0x2]
 *   @0x277d80 and r2, r2, #63
 *   @0x277d84 orr r3, r1, r3, lsl #30
 *   @0x277d88 ldrb r1, [r4, #0x3]
 *   @0x277d8c and r0, r0, #63
 *   @0x277d90 orr r2, r3, r2, lsl #24
 *   @0x277d94 ldrb r3, [r4, #0x4]
 *   @0x277d98 and r1, r1, #63
 *   @0x277d9c orr r2, r2, r0, lsl #18
 *   @0x277da0 and r3, r3, #63
 *   @0x277da4 orr r1, r2, r1, lsl #12
 *   @0x277da8 mov r2, #6
 *   @0x277dac orr r3, r1, r3, lsl r2
 *   @0x277db0 b 0x2726b8 <pcre_dfa_exec+0x4150>
 *   @0x277db4 ldrb r1, [r10, #0x5]
 *   @0x277db8 and r3, r3, #1
 *   @0x277dbc ldrb r2, [r10, #0x1]
 *   @0x277dc0 add r10, r10, #6
 *   @0x277dc4 and r1, r1, #63
 *   @0x277dc8 ldrb r0, [r10, #-0x4]
 *   @0x277dcc and r2, r2, #63
 *   @0x277dd0 orr r3, r1, r3, lsl #30
 *   @0x277dd4 ldrb r1, [r10, #-0x3]
 *   @0x277dd8 and r0, r0, #63
 *   @0x277ddc orr r3, r3, r2, lsl #24
 *   @0x277de0 ldrb r2, [r10, #-0x2]
 *   @0x277de4 and r1, r1, #63
 *   @0x277de8 orr r3, r3, r0, lsl #18
 *   @0x277dec and r2, r2, #63
 *   @0x277df0 orr r3, r3, r1, lsl #12
 *   @0x277df4 orr r3, r3, r2, lsl #6
 *   @0x277df8 b 0x270bec <pcre_dfa_exec+0x2684>
 *   @0x277dfc mov r10, r8
 *   @0x277e00 b 0x272bc0 <pcre_dfa_exec+0x4658>
 *   @0x277e04 ldrb r1, [r4, #0x5]
 *   @0x277e08 and r3, r3, #1
 *   @0x277e0c ldrb r2, [r4, #0x1]
 *   @0x277e10 and r1, r1, #63
 *   @0x277e14 ldrb r0, [r4, #0x2]
 *   @0x277e18 and r2, r2, #63
 *   @0x277e1c orr r3, r1, r3, lsl #30
 *   @0x277e20 ldrb r1, [r4, #0x3]
 *   @0x277e24 and r0, r0, #63
 *   @0x277e28 orr r2, r3, r2, lsl #24
 *   @0x277e2c ldrb r3, [r4, #0x4]
 *   @0x277e30 and r1, r1, #63
 *   @0x277e34 orr r2, r2, r0, lsl #18
 *   @0x277e38 and r3, r3, #63
 *   @0x277e3c orr r1, r2, r1, lsl #12
 *   @0x277e40 mov r2, #6
 *   @0x277e44 orr r3, r1, r3, lsl r2
 *   @0x277e48 b 0x272350 <pcre_dfa_exec+0x3de8>
 *   @0x277e4c tst r3, #4
 *   @0x277e50 bne 0x278554 <pcre_dfa_exec+0x9fec>
 *   @0x277e54 ldrb r2, [r11, #0x5]
 *   @0x277e58 and r3, r3, #3
 *   @0x277e5c ldrb r0, [r11, #0x2]
 *   @0x277e60 and r2, r2, #63
 *   @0x277e64 ldrb r1, [r11, #0x3]
 *   @0x277e68 orr r3, r2, r3, lsl #24
 *   @0x277e6c and r0, r0, #63
 *   @0x277e70 ldrb r2, [r11, #0x4]
 *   @0x277e74 and r1, r1, #63
 *   @0x277e78 orr r3, r3, r0, lsl #18
 *   @0x277e7c and r2, r2, #63
 *   @0x277e80 orr r3, r3, r1, lsl #12
 *   @0x277e84 mov r1, #5
 *   @0x277e88 orr r3, r3, r2, lsl #6
 *   @0x277e8c b 0x26fb70 <pcre_dfa_exec+0x1608>
 *   @0x277e90 ldrb r1, [r10, #0x5]
 *   @0x277e94 and r3, r3, #1
 *   @0x277e98 ldrb r2, [r10, #0x1]
 *   @0x277e9c add r10, r10, #6
 *   @0x277ea0 and r1, r1, #63
 *   @0x277ea4 ldrb r0, [r10, #-0x4]
 *   @0x277ea8 and r2, r2, #63
 *   @0x277eac orr r3, r1, r3, lsl #30
 *   @0x277eb0 ldrb r1, [r10, #-0x3]
 *   @0x277eb4 and r0, r0, #63
 *   @0x277eb8 orr r3, r3, r2, lsl #24
 *   @0x277ebc ldrb r2, [r10, #-0x2]
 *   @0x277ec0 and r1, r1, #63
 *   @0x277ec4 orr r3, r3, r0, lsl #18
 *   @0x277ec8 and r2, r2, #63
 *   @0x277ecc orr r3, r3, r1, lsl #12
 *   @0x277ed0 orr r3, r3, r2, lsl #6
 *   @0x277ed4 b 0x270708 <pcre_dfa_exec+0x21a0>
 *   @0x277ed8 tst r3, #4
 *   @0x277edc bne 0x2785d4 <pcre_dfa_exec+0xa06c>
 *   @0x277ee0 ldrb r1, [r10, #0x4]
 *   @0x277ee4 and r3, r3, #3
 *   @0x277ee8 ldrb r0, [r10, #0x1]
 *   @0x277eec add r10, r10, #5
 *   @0x277ef0 ldrb r2, [r10, #-0x3]
 *   @0x277ef4 and r1, r1, #63
 *   @0x277ef8 orr r1, r1, r3, lsl #24
 *   @0x277efc and r0, r0, #63
 *   @0x277f00 ldrb r3, [r10, #-0x2]
 *   @0x277f04 and r2, r2, #63
 *   @0x277f08 orr r1, r1, r0, lsl #18
 *   @0x277f0c and r3, r3, #63
 *   @0x277f10 orr r2, r1, r2, lsl #12
 *   @0x277f14 orr r3, r2, r3, lsl #6
 *   @0x277f18 b 0x271f2c <pcre_dfa_exec+0x39c4>
 *   @0x277f1c ldrb r1, [r10, #0x5]
 *   @0x277f20 and r3, r3, #1
 *   @0x277f24 ldrb r2, [r10, #0x1]
 *   @0x277f28 add r10, r10, #6
 *   @0x277f2c and r1, r1, #63
 *   @0x277f30 ldrb r0, [r10, #-0x4]
 *   @0x277f34 and r2, r2, #63
 *   @0x277f38 orr r3, r1, r3, lsl #30
 *   @0x277f3c ldrb r1, [r10, #-0x3]
 *   @0x277f40 and r0, r0, #63
 *   @0x277f44 orr r3, r3, r2, lsl #24
 *   @0x277f48 ldrb r2, [r10, #-0x2]
 *   @0x277f4c and r1, r1, #63
 *   @0x277f50 orr r3, r3, r0, lsl #18
 *   @0x277f54 and r2, r2, #63
 *   @0x277f58 orr r3, r3, r1, lsl #12
 *   @0x277f5c orr r3, r3, r2, lsl #6
 *   @0x277f60 b 0x270cb4 <pcre_dfa_exec+0x274c>
 *   @0x277f64 ldr r3, [r6, #0x1c]
 *   @0x277f68 rsb r2, r3, r2
 *   @0x277f6c cmp r10, r2
 *   @0x277f70 bhi 0x277f84 <pcre_dfa_exec+0x9a1c>
 *   @0x277f74 ldrb r0, [r10]
 *   @0x277f78 ldrb r2, [r6, #0x34]
 *   @0x277f7c cmp r0, r2
 *   @0x277f80 beq 0x278f48 <pcre_dfa_exec+0xa9e0>
 *   @0x277f84 mov r3, r1
 *   @0x277f88 and r0, r3, #1
 *   @0x277f8c b 0x277580 <pcre_dfa_exec+0x9018>
 *   @0x277f90 ldr r3, [r6, #0x1c]
 *   @0x277f94 rsb r2, r3, r2
 *   @0x277f98 cmp r10, r2
 *   @0x277f9c bhi 0x277fb0 <pcre_dfa_exec+0x9a48>
 *   @0x277fa0 ldrb r0, [r10]
 *   @0x277fa4 ldrb r2, [r6, #0x34]
 *   @0x277fa8 cmp r0, r2
 *   @0x277fac beq 0x27934c <pcre_dfa_exec+0xade4>
 *   @0x277fb0 mov r3, r1
 *   @0x277fb4 and r0, r3, #1
 *   @0x277fb8 b 0x277b7c <pcre_dfa_exec+0x9614>
 *   @0x277fbc mov r4, r10
 *   @0x277fc0 b 0x272cf0 <pcre_dfa_exec+0x4788>
 *   @0x277fc4 mov r4, r10
 *   @0x277fc8 b 0x270f48 <pcre_dfa_exec+0x29e0>
 *   @0x277fcc tst r3, #4
 *   @0x277fd0 bne 0x2786ac <pcre_dfa_exec+0xa144>
 *   @0x277fd4 ldrb r12, [r2, #0x4]
 *   @0x277fd8 and r3, r3, #3
 *   @0x277fdc ldrb r0, [r2, #0x1]
 *   @0x277fe0 and r12, r12, #63
 *   @0x277fe4 ldrb r1, [r2, #0x2]
 *   @0x277fe8 ldrb r2, [r2, #0x3]
 *   @0x277fec and r0, r0, #63
 *   @0x277ff0 orr r3, r12, r3, lsl #24
 *   @0x277ff4 and r1, r1, #63
 *   @0x277ff8 orr r3, r3, r0, lsl #18
 *   @0x277ffc and r2, r2, #63
 *   @0x278000 orr r3, r3, r1, lsl #12
 *   @0x278004 orr r3, r3, r2, lsl #6
 *   @0x278008 b 0x270870 <pcre_dfa_exec+0x2308>
 *   @0x27800c mov r4, r10
 *   @0x278010 ldr r2, [r6, #0x88]
 *   @0x278014 cmp r2, #0
 *   @0x278018 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27801c ldr r3, [r6, #0x84]
 *   @0x278020 cmp r3, r4
 *   @0x278024 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x278028 b 0x277c80 <pcre_dfa_exec+0x9718>
 *   @0x27802c ldr r11, [sp, #0x18]
 *   @0x278030 movw r0, #0xfc1a
 *   @0x278034 ldr r5, [sp, #0x1c]
 *   @0x278038 movt r0, #0xffff
 *   @0x27803c str r10, [r6, #0x80]
 *   @0x278040 str r11, [r6, #0x8c]
 *   @0x278044 str r5, [r6, #0x7c]
 *   @0x278048 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27804c cmp r5, #122
 *   @0x278050 ldr r3, [sp, #0x168]
 *   @0x278054 beq 0x278e64 <pcre_dfa_exec+0xa8fc>
 *   @0x278058 ldr r12, [sp, #0x164]
 *   @0x27805c add r3, r3, #1
 *   @0x278060 mov r0, r10
 *   @0x278064 str r3, [sp, #0x8]
 *   @0x278068 str r6, [sp]
 *   @0x27806c mov r1, r8
 *   @0x278070 ldr r3, [sp, #0x18]
 *   @0x278074 str r12, [sp, #0x4]
 *   @0x278078 ldr r2, [sp, #0x1c]
 *   @0x27807c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278080 mvn r3, #996
 *   @0x278084 cmp r0, r3
 *   @0x278088 beq 0x278e54 <pcre_dfa_exec+0xa8ec>
 *   @0x27808c cmp r0, #0
 *   @0x278090 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278094 ldrb r3, [r8]
 *   @0x278098 cmp r3, #129
 *   @0x27809c beq 0x278f68 <pcre_dfa_exec+0xaa00>
 *   @0x2780a0 add r11, r11, #3
 *   @0x2780a4 b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x2780a8 ldr r11, [sp, #0x18]
 *   @0x2780ac mov r0, #1
 *   @0x2780b0 ldr r5, [sp, #0x1c]
 *   @0x2780b4 str r10, [r6, #0x80]
 *   @0x2780b8 str r11, [r6, #0x8c]
 *   @0x2780bc str r5, [r6, #0x7c]
 *   @0x2780c0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2780c4 ldr r7, [sp, #0x1c]
 *   @0x2780c8 mov r0, #1
 *   @0x2780cc str r10, [r6, #0x80]
 *   @0x2780d0 str r7, [r6, #0x7c]
 *   @0x2780d4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2780d8 ldr r5, [sp, #0x28]
 *   @0x2780dc mov r4, r11
 *   @0x2780e0 str r1, [sp, #0x20]
 *   @0x2780e4 cmp r5, #0
 *   @0x2780e8 ldr r11, [sp, #0x18]
 *   @0x2780ec bne 0x278178 <pcre_dfa_exec+0x9c10>
 *   @0x2780f0 rsb r8, r10, r8
 *   @0x2780f4 b 0x278104 <pcre_dfa_exec+0x9b9c>
 *   @0x2780f8 ldrb r3, [r10], #1
 *   @0x2780fc cmp r7, r3
 *   @0x278100 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278104 ldr r12, [sp, #0x164]
 *   @0x278108 mov r0, r10
 *   @0x27810c ldr r3, [sp, #0x168]
 *   @0x278110 mov r1, r4
 *   @0x278114 str r6, [sp]
 *   @0x278118 add r3, r3, #1
 *   @0x27811c str r12, [sp, #0x4]
 *   @0x278120 str r3, [sp, #0x8]
 *   @0x278124 mov r3, r11
 *   @0x278128 ldr r2, [sp, #0x1c]
 *   @0x27812c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278130 add r3, r10, r8
 *   @0x278134 cmp r0, #0
 *   @0x278138 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27813c ldr r5, [sp, #0x20]
 *   @0x278140 cmp r3, r5
 *   @0x278144 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278148 ldr r3, [r6, #0x78]
 *   @0x27814c cmp r10, r3
 *   @0x278150 blo 0x2780f8 <pcre_dfa_exec+0x9b90>
 *   @0x278154 b 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x278158 ldrb r3, [r10, #0x1]
 *   @0x27815c and r0, r0, #31
 *   @0x278160 add r10, r10, #2
 *   @0x278164 and r3, r3, #63
 *   @0x278168 orr r0, r3, r0, lsl #6
 *   @0x27816c cmp r7, r0
 *   @0x278170 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278174 add r8, r8, #1
 *   @0x278178 ldr r12, [sp, #0x164]
 *   @0x27817c mov r0, r10
 *   @0x278180 ldr r3, [sp, #0x168]
 *   @0x278184 mov r1, r4
 *   @0x278188 str r6, [sp]
 *   @0x27818c add r3, r3, #1
 *   @0x278190 str r12, [sp, #0x4]
 *   @0x278194 str r3, [sp, #0x8]
 *   @0x278198 mov r3, r11
 *   @0x27819c ldr r2, [sp, #0x1c]
 *   @0x2781a0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2781a4 cmp r0, #0
 *   @0x2781a8 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2781ac ldr r5, [sp, #0x20]
 *   @0x2781b0 cmp r8, r5
 *   @0x2781b4 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2781b8 ldr r3, [r6, #0x78]
 *   @0x2781bc cmp r10, r3
 *   @0x2781c0 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2781c4 ldrb r0, [r10]
 *   @0x2781c8 cmp r0, #191
 *   @0x2781cc addls r10, r10, #1
 *   @0x2781d0 bls 0x27816c <pcre_dfa_exec+0x9c04>
 *   @0x2781d4 tst r0, #32
 *   @0x2781d8 beq 0x278158 <pcre_dfa_exec+0x9bf0>
 *   @0x2781dc tst r0, #16
 *   @0x2781e0 bne 0x278ae4 <pcre_dfa_exec+0xa57c>
 *   @0x2781e4 lsl r2, r0, #12
 *   @0x2781e8 ldrb r3, [r10, #0x2]
 *   @0x2781ec ldrb r1, [r10, #0x1]
 *   @0x2781f0 add r10, r10, #3
 *   @0x2781f4 uxth r2, r2
 *   @0x2781f8 and r3, r3, #63
 *   @0x2781fc and r0, r1, #63
 *   @0x278200 orr r3, r2, r3
 *   @0x278204 orr r0, r3, r0, lsl #6
 *   @0x278208 b 0x27816c <pcre_dfa_exec+0x9c04>
 *   @0x27820c tst r3, #4
 *   @0x278210 bne 0x2788c8 <pcre_dfa_exec+0xa360>
 *   @0x278214 ldrb r2, [r10, #0x4]
 *   @0x278218 and r3, r3, #3
 *   @0x27821c ldrb r12, [r10, #0x1]
 *   @0x278220 and r2, r2, #63
 *   @0x278224 ldrb r1, [r10, #0x2]
 *   @0x278228 orr r3, r2, r3, lsl #24
 *   @0x27822c and r12, r12, #63
 *   @0x278230 ldrb r2, [r10, #0x3]
 *   @0x278234 and r1, r1, #63
 *   @0x278238 orr r3, r3, r12, lsl #18
 *   @0x27823c and r2, r2, #63
 *   @0x278240 orr r3, r3, r1, lsl #12
 *   @0x278244 orr r3, r3, r2, lsl #6
 *   @0x278248 b 0x275258 <pcre_dfa_exec+0x6cf0>
 *   @0x27824c tst r2, #4
 *   @0x278250 bne 0x278a4c <pcre_dfa_exec+0xa4e4>
 *   @0x278254 ldrb r0, [r10, #0x4]
 *   @0x278258 and r2, r2, #3
 *   @0x27825c ldrb r4, [r10, #0x1]
 *   @0x278260 add r10, r10, #5
 *   @0x278264 and r0, r0, #63
 *   @0x278268 ldrb r12, [r10, #-0x3]
 *   @0x27826c orr r2, r0, r2, lsl #24
 *   @0x278270 and r4, r4, #63
 *   @0x278274 ldrb r0, [r10, #-0x2]
 *   @0x278278 and r12, r12, #63
 *   @0x27827c orr r2, r2, r4, lsl #18
 *   @0x278280 and r0, r0, #63
 *   @0x278284 orr r2, r2, r12, lsl #12
 *   @0x278288 orr r2, r2, r0, lsl #6
 *   @0x27828c b 0x2753b4 <pcre_dfa_exec+0x6e4c>
 *   @0x278290 ldr r12, [sp, #0x28]
 *   @0x278294 mov r4, r11
 *   @0x278298 str r1, [sp, #0x20]
 *   @0x27829c cmp r12, #0
 *   @0x2782a0 ldr r11, [sp, #0x18]
 *   @0x2782a4 bne 0x278358 <pcre_dfa_exec+0x9df0>
 *   @0x2782a8 mov r9, r10
 *   @0x2782ac b 0x2782c8 <pcre_dfa_exec+0x9d60>
 *   @0x2782b0 ldrb r3, [r9]
 *   @0x2782b4 add r9, r9, #1
 *   @0x2782b8 cmp r7, r3
 *   @0x2782bc beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2782c0 cmp r3, r5
 *   @0x2782c4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2782c8 ldr r12, [sp, #0x164]
 *   @0x2782cc mov r0, r9
 *   @0x2782d0 ldr r3, [sp, #0x168]
 *   @0x2782d4 mov r1, r4
 *   @0x2782d8 str r6, [sp]
 *   @0x2782dc add r3, r3, #1
 *   @0x2782e0 str r12, [sp, #0x4]
 *   @0x2782e4 str r3, [sp, #0x8]
 *   @0x2782e8 mov r3, r11
 *   @0x2782ec ldr r2, [sp, #0x1c]
 *   @0x2782f0 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2782f4 cmp r0, #0
 *   @0x2782f8 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2782fc ldr r12, [sp, #0x20]
 *   @0x278300 cmp r8, r12
 *   @0x278304 add r8, r8, #1
 *   @0x278308 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27830c ldr r3, [r6, #0x78]
 *   @0x278310 cmp r9, r3
 *   @0x278314 blo 0x2782b0 <pcre_dfa_exec+0x9d48>
 *   @0x278318 ldr r3, [r6, #0x88]
 *   @0x27831c cmp r3, #0
 *   @0x278320 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278324 ldr r2, [r6, #0x84]
 *   @0x278328 cmp r2, r9
 *   @0x27832c blo 0x271820 <pcre_dfa_exec+0x32b8>
 *   @0x278330 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278334 ldrb r2, [r10, #0x1]
 *   @0x278338 and r3, r3, #31
 *   @0x27833c add r10, r10, #2
 *   @0x278340 and r2, r2, #63
 *   @0x278344 orr r3, r2, r3, lsl #6
 *   @0x278348 cmp r7, r3
 *   @0x27834c cmpne r3, r5
 *   @0x278350 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278354 add r8, r8, #1
 *   @0x278358 ldr r12, [sp, #0x164]
 *   @0x27835c mov r0, r10
 *   @0x278360 ldr r3, [sp, #0x168]
 *   @0x278364 mov r1, r4
 *   @0x278368 str r6, [sp]
 *   @0x27836c add r3, r3, #1
 *   @0x278370 str r12, [sp, #0x4]
 *   @0x278374 str r3, [sp, #0x8]
 *   @0x278378 mov r3, r11
 *   @0x27837c ldr r2, [sp, #0x1c]
 *   @0x278380 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278384 cmp r0, #0
 *   @0x278388 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27838c ldr r12, [sp, #0x20]
 *   @0x278390 cmp r8, r12
 *   @0x278394 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278398 ldr r3, [r6, #0x78]
 *   @0x27839c cmp r10, r3
 *   @0x2783a0 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2783a4 ldrb r3, [r10]
 *   @0x2783a8 cmp r3, #191
 *   @0x2783ac addls r10, r10, #1
 *   @0x2783b0 bls 0x278348 <pcre_dfa_exec+0x9de0>
 *   @0x2783b4 tst r3, #32
 *   @0x2783b8 beq 0x278334 <pcre_dfa_exec+0x9dcc>
 *   @0x2783bc tst r3, #16
 *   @0x2783c0 bne 0x278c94 <pcre_dfa_exec+0xa72c>
 *   @0x2783c4 lsl r1, r3, #12
 *   @0x2783c8 ldrb r2, [r10, #0x1]
 *   @0x2783cc ldrb r3, [r10, #0x2]
 *   @0x2783d0 add r10, r10, #3
 *   @0x2783d4 uxth r1, r1
 *   @0x2783d8 and r2, r2, #63
 *   @0x2783dc and r3, r3, #63
 *   @0x2783e0 orr r3, r1, r3
 *   @0x2783e4 orr r3, r3, r2, lsl #6
 *   @0x2783e8 b 0x278348 <pcre_dfa_exec+0x9de0>
 *   @0x2783ec ldrb r1, [r11, #0x6]
 *   @0x2783f0 and r3, r3, #1
 *   @0x2783f4 ldrb r2, [r11, #0x2]
 *   @0x2783f8 add r11, r11, #7
 *   @0x2783fc and r1, r1, #63
 *   @0x278400 ldrb r0, [r11, #-0x4]
 *   @0x278404 and r2, r2, #63
 *   @0x278408 orr r3, r1, r3, lsl #30
 *   @0x27840c ldrb r1, [r11, #-0x3]
 *   @0x278410 and r0, r0, #63
 *   @0x278414 orr r3, r3, r2, lsl #24
 *   @0x278418 ldrb r2, [r11, #-0x2]
 *   @0x27841c and r1, r1, #63
 *   @0x278420 orr r3, r3, r0, lsl #18
 *   @0x278424 and r2, r2, #63
 *   @0x278428 orr r3, r3, r1, lsl #12
 *   @0x27842c orr r3, r3, r2, lsl #6
 *   @0x278430 b 0x271744 <pcre_dfa_exec+0x31dc>
 *   @0x278434 .word 0xfffffb8c
 *   @0x278438 ldr r12, [pc, #-0xc]
 *   @0x27843c mov r4, r11
 *   @0x278440 ldr r7, [sp, #0x20]
 *   @0x278444 mov r0, r10
 *   @0x278448 ldrb lr, [r4]
 *   @0x27844c ldrb r1, [r4, #0x1]
 *   @0x278450 ldr r5, [r7, r12]
 *   @0x278454 ldr r11, [sp, #0x18]
 *   @0x278458 ldr r12, [sp, #0x168]
 *   @0x27845c ldrb lr, [r5, lr]
 *   @0x278460 ldr r5, [sp, #0x164]
 *   @0x278464 mov r3, r11
 *   @0x278468 add r1, lr, r1
 *   @0x27846c add r12, r12, #1
 *   @0x278470 ldr r2, [sp, #0x1c]
 *   @0x278474 add r1, r4, r1
 *   @0x278478 str r6, [sp]
 *   @0x27847c str r5, [sp, #0x4]
 *   @0x278480 str r12, [sp, #0x8]
 *   @0x278484 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278488 cmp r0, #0
 *   @0x27848c addeq r3, r4, #2
 *   @0x278490 streq r3, [r6, #0x7c]
 *   @0x278494 mvneq r0, #992
 *   @0x278498 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27849c mov r4, r11
 *   @0x2784a0 ldr r7, [sp, #0x164]
 *   @0x2784a4 ldr r11, [sp, #0x18]
 *   @0x2784a8 mov r0, r10
 *   @0x2784ac ldr r12, [sp, #0x168]
 *   @0x2784b0 add r1, r4, #3
 *   @0x2784b4 str r6, [sp]
 *   @0x2784b8 add r12, r12, #1
 *   @0x2784bc str r7, [sp, #0x4]
 *   @0x2784c0 ldr r2, [sp, #0x1c]
 *   @0x2784c4 mov r3, r11
 *   @0x2784c8 str r12, [sp, #0x8]
 *   @0x2784cc bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2784d0 cmp r0, #0
 *   @0x2784d4 streq r8, [r6, #0xb4]
 *   @0x2784d8 mvneq r0, #996
 *   @0x2784dc b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2784e0 mov r0, #0
 *   @0x2784e4 ldr r3, [r6, #0xc]
 *   @0x2784e8 ldr r5, [sp, #0x28]
 *   @0x2784ec ldr r12, [sp, #0x34]
 *   @0x2784f0 str r5, [r3, r7, lsl #3]
 *   @0x2784f4 str r12, [r3, r8]
 *   @0x2784f8 ldr r2, [r6, #0x10]
 *   @0x2784fc ldr r5, [sp, #0x38]
 *   @0x278500 rsb r4, r7, r2
 *   @0x278504 str r5, [r3, r4, lsl #2]
 *   @0x278508 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27850c ldrb r0, [r10, #0x5]
 *   @0x278510 and r2, r2, #1
 *   @0x278514 ldrb r1, [r10, #0x1]
 *   @0x278518 add r10, r10, #6
 *   @0x27851c and r0, r0, #63
 *   @0x278520 ldrb r12, [r10, #-0x4]
 *   @0x278524 and r1, r1, #63
 *   @0x278528 orr r2, r0, r2, lsl #30
 *   @0x27852c ldrb r0, [r10, #-0x3]
 *   @0x278530 and r12, r12, #63
 *   @0x278534 orr r2, r2, r1, lsl #24
 *   @0x278538 ldrb r1, [r10, #-0x2]
 *   @0x27853c and r0, r0, #63
 *   @0x278540 orr r2, r2, r12, lsl #18
 *   @0x278544 and r1, r1, #63
 *   @0x278548 orr r2, r2, r0, lsl #12
 *   @0x27854c orr r2, r2, r1, lsl #6
 *   @0x278550 b 0x271770 <pcre_dfa_exec+0x3208>
 *   @0x278554 ldrb r1, [r11, #0x6]
 *   @0x278558 and r3, r3, #1
 *   @0x27855c ldrb r2, [r11, #0x2]
 *   @0x278560 and r1, r1, #63
 *   @0x278564 ldrb r0, [r11, #0x3]
 *   @0x278568 and r2, r2, #63
 *   @0x27856c orr r3, r1, r3, lsl #30
 *   @0x278570 ldrb r1, [r11, #0x4]
 *   @0x278574 and r0, r0, #63
 *   @0x278578 orr r3, r3, r2, lsl #24
 *   @0x27857c ldrb r2, [r11, #0x5]
 *   @0x278580 and r1, r1, #63
 *   @0x278584 orr r3, r3, r0, lsl #18
 *   @0x278588 and r2, r2, #63
 *   @0x27858c orr r3, r3, r1, lsl #12
 *   @0x278590 mov r1, #6
 *   @0x278594 orr r3, r3, r2, lsl r1
 *   @0x278598 b 0x26fb70 <pcre_dfa_exec+0x1608>
 *   @0x27859c tst r3, #8
 *   @0x2785a0 bne 0x278d0c <pcre_dfa_exec+0xa7a4>
 *   @0x2785a4 ldrb r0, [r10, #0x3]
 *   @0x2785a8 and r3, r3, #7
 *   @0x2785ac ldrb r1, [r10, #0x1]
 *   @0x2785b0 add r10, r10, #4
 *   @0x2785b4 ldrb r2, [r10, #-0x2]
 *   @0x2785b8 and r0, r0, #63
 *   @0x2785bc and r1, r1, #63
 *   @0x2785c0 orr r3, r0, r3, lsl #18
 *   @0x2785c4 and r2, r2, #63
 *   @0x2785c8 orr r3, r3, r1, lsl #12
 *   @0x2785cc orr r3, r3, r2, lsl #6
 *   @0x2785d0 b 0x2770cc <pcre_dfa_exec+0x8b64>
 *   @0x2785d4 ldrb r2, [r10, #0x5]
 *   @0x2785d8 and r3, r3, #1
 *   @0x2785dc ldrb r1, [r10, #0x1]
 *   @0x2785e0 add r10, r10, #6
 *   @0x2785e4 and r2, r2, #63
 *   @0x2785e8 ldrb r0, [r10, #-0x4]
 *   @0x2785ec and r1, r1, #63
 *   @0x2785f0 orr r3, r2, r3, lsl #30
 *   @0x2785f4 ldrb r2, [r10, #-0x3]
 *   @0x2785f8 and r0, r0, #63
 *   @0x2785fc orr r1, r3, r1, lsl #24
 *   @0x278600 ldrb r3, [r10, #-0x2]
 *   @0x278604 and r2, r2, #63
 *   @0x278608 orr r1, r1, r0, lsl #18
 *   @0x27860c and r3, r3, #63
 *   @0x278610 orr r2, r1, r2, lsl #12
 *   @0x278614 orr r3, r2, r3, lsl #6
 *   @0x278618 b 0x271f2c <pcre_dfa_exec+0x39c4>
 *   @0x27861c mov r9, r4
 *   @0x278620 mov r4, r11
 *   @0x278624 ldr r11, [sp, #0x18]
 *   @0x278628 b 0x27865c <pcre_dfa_exec+0xa0f4>
 *   @0x27862c ldr r5, [sp, #0x2c]
 *   @0x278630 cmp r7, r5
 *   @0x278634 add r7, r7, #1
 *   @0x278638 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27863c ldr r5, [r6, #0x78]
 *   @0x278640 rsb r3, r8, r5
 *   @0x278644 cmp r10, r3
 *   @0x278648 bhi 0x2790ac <pcre_dfa_exec+0xab44>
 *   @0x27864c bl 0xb6c40 <memcmp@plt>
 *   @0x278650 cmp r0, #0
 *   @0x278654 bne 0x2790ac <pcre_dfa_exec+0xab44>
 *   @0x278658 add r10, r10, r8
 *   @0x27865c ldr r12, [sp, #0x164]
 *   @0x278660 mov r1, r4
 *   @0x278664 ldr r3, [sp, #0x168]
 *   @0x278668 mov r0, r10
 *   @0x27866c ldr r2, [sp, #0x1c]
 *   @0x278670 add r3, r3, #1
 *   @0x278674 str r6, [sp]
 *   @0x278678 str r3, [sp, #0x8]
 *   @0x27867c mov r3, r11
 *   @0x278680 str r12, [sp, #0x4]
 *   @0x278684 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278688 mov r1, r9
 *   @0x27868c mov r2, r8
 *   @0x278690 subs r3, r0, #0
 *   @0x278694 mov r0, r10
 *   @0x278698 beq 0x27862c <pcre_dfa_exec+0xa0c4>
 *   @0x27869c mov r0, r3
 *   @0x2786a0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2786a4 mov r0, #0
 *   @0x2786a8 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2786ac ldrb r1, [r2, #0x5]
 *   @0x2786b0 and r3, r3, #1
 *   @0x2786b4 ldrb r12, [r2, #0x1]
 *   @0x2786b8 and r1, r1, #63
 *   @0x2786bc ldrb r0, [r2, #0x2]
 *   @0x2786c0 and r12, r12, #63
 *   @0x2786c4 orr r3, r1, r3, lsl #30
 *   @0x2786c8 and r0, r0, #63
 *   @0x2786cc ldrb r1, [r2, #0x3]
 *   @0x2786d0 orr r3, r3, r12, lsl #24
 *   @0x2786d4 ldrb r2, [r2, #0x4]
 *   @0x2786d8 b 0x277ff4 <pcre_dfa_exec+0x9a8c>
 *   @0x2786dc mov r4, r11
 *   @0x2786e0 rsb r7, r8, r7
 *   @0x2786e4 ldr r11, [sp, #0x18]
 *   @0x2786e8 b 0x2786f8 <pcre_dfa_exec+0xa190>
 *   @0x2786ec ldrb r3, [r8], #1
 *   @0x2786f0 cmp r12, r3
 *   @0x2786f4 bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2786f8 ldr r5, [sp, #0x164]
 *   @0x2786fc mov r0, r8
 *   @0x278700 ldr r3, [sp, #0x168]
 *   @0x278704 mov r1, r4
 *   @0x278708 str r6, [sp]
 *   @0x27870c add r3, r3, #1
 *   @0x278710 str r5, [sp, #0x4]
 *   @0x278714 str r3, [sp, #0x8]
 *   @0x278718 mov r3, r11
 *   @0x27871c ldr r2, [sp, #0x1c]
 *   @0x278720 str r12, [sp, #0x14]
 *   @0x278724 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278728 add r3, r8, r7
 *   @0x27872c ldr r12, [sp, #0x14]
 *   @0x278730 cmp r0, #0
 *   @0x278734 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278738 ldr r5, [sp, #0x2c]
 *   @0x27873c cmp r3, r5
 *   @0x278740 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278744 ldr r3, [r6, #0x78]
 *   @0x278748 cmp r8, r3
 *   @0x27874c blo 0x2786ec <pcre_dfa_exec+0xa184>
 *   @0x278750 b 0x273504 <pcre_dfa_exec+0x4f9c>
 *   @0x278754 mov r4, r3
 *   @0x278758 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x27875c ldr r7, [sp, #0x28]
 *   @0x278760 mov r4, r11
 *   @0x278764 str r0, [sp, #0x20]
 *   @0x278768 cmp r7, #0
 *   @0x27876c ldr r11, [sp, #0x18]
 *   @0x278770 bne 0x27881c <pcre_dfa_exec+0xa2b4>
 *   @0x278774 rsb r9, r10, r12
 *   @0x278778 b 0x278794 <pcre_dfa_exec+0xa22c>
 *   @0x27877c ldrb r3, [r10], #1
 *   @0x278780 and r2, r3, #7
 *   @0x278784 ldrb r3, [r8, r3, lsr #3]
 *   @0x278788 asr r3, r3, r2
 *   @0x27878c tst r3, #1
 *   @0x278790 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278794 ldr r12, [sp, #0x164]
 *   @0x278798 mov r0, r10
 *   @0x27879c ldr r3, [sp, #0x168]
 *   @0x2787a0 mov r1, r4
 *   @0x2787a4 str r6, [sp]
 *   @0x2787a8 add r3, r3, #1
 *   @0x2787ac str r12, [sp, #0x4]
 *   @0x2787b0 str r3, [sp, #0x8]
 *   @0x2787b4 mov r3, r11
 *   @0x2787b8 ldr r2, [sp, #0x1c]
 *   @0x2787bc bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2787c0 add r3, r10, r9
 *   @0x2787c4 cmp r0, #0
 *   @0x2787c8 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2787cc ldr r5, [sp, #0x20]
 *   @0x2787d0 cmp r3, r5
 *   @0x2787d4 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2787d8 ldr r3, [r6, #0x78]
 *   @0x2787dc cmp r10, r3
 *   @0x2787e0 blo 0x27877c <pcre_dfa_exec+0xa214>
 *   @0x2787e4 b 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x2787e8 tst r1, #32
 *   @0x2787ec bne 0x278898 <pcre_dfa_exec+0xa330>
 *   @0x2787f0 ldrb r3, [r10, #0x1]
 *   @0x2787f4 and r1, r1, #31
 *   @0x2787f8 add r7, r10, #2
 *   @0x2787fc and r3, r3, #63
 *   @0x278800 orr r1, r3, r1, lsl #6
 *   @0x278804 cmp r1, #255
 *   @0x278808 bls 0x278880 <pcre_dfa_exec+0xa318>
 *   @0x27880c cmp r5, #110
 *   @0x278810 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278814 add r12, r12, #1
 *   @0x278818 mov r10, r7
 *   @0x27881c ldr r7, [sp, #0x164]
 *   @0x278820 mov r0, r10
 *   @0x278824 ldr r3, [sp, #0x168]
 *   @0x278828 mov r1, r4
 *   @0x27882c str r6, [sp]
 *   @0x278830 add r3, r3, #1
 *   @0x278834 str r7, [sp, #0x4]
 *   @0x278838 str r3, [sp, #0x8]
 *   @0x27883c mov r3, r11
 *   @0x278840 ldr r2, [sp, #0x1c]
 *   @0x278844 str r12, [sp, #0x14]
 *   @0x278848 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x27884c ldr r12, [sp, #0x14]
 *   @0x278850 cmp r0, #0
 *   @0x278854 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278858 ldr r7, [sp, #0x20]
 *   @0x27885c cmp r12, r7
 *   @0x278860 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278864 ldr r3, [r6, #0x78]
 *   @0x278868 cmp r10, r3
 *   @0x27886c bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x278870 ldrb r1, [r10]
 *   @0x278874 cmp r1, #191
 *   @0x278878 bhi 0x2787e8 <pcre_dfa_exec+0xa280>
 *   @0x27887c add r7, r10, #1
 *   @0x278880 ldrb r3, [r8, r1, lsr #3]
 *   @0x278884 and r1, r1, #7
 *   @0x278888 asr r3, r3, r1
 *   @0x27888c tst r3, #1
 *   @0x278890 bne 0x278814 <pcre_dfa_exec+0xa2ac>
 *   @0x278894 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278898 tst r1, #16
 *   @0x27889c bne 0x279138 <pcre_dfa_exec+0xabd0>
 *   @0x2788a0 lsl r2, r1, #12
 *   @0x2788a4 ldrb r3, [r10, #0x2]
 *   @0x2788a8 ldrb r1, [r10, #0x1]
 *   @0x2788ac add r7, r10, #3
 *   @0x2788b0 uxth r2, r2
 *   @0x2788b4 and r3, r3, #63
 *   @0x2788b8 and r1, r1, #63
 *   @0x2788bc orr r3, r2, r3
 *   @0x2788c0 orr r1, r3, r1, lsl #6
 *   @0x2788c4 b 0x278804 <pcre_dfa_exec+0xa29c>
 *   @0x2788c8 ldrb r1, [r10, #0x5]
 *   @0x2788cc and r3, r3, #1
 *   @0x2788d0 ldrb r2, [r10, #0x1]
 *   @0x2788d4 and r1, r1, #63
 *   @0x2788d8 ldrb r12, [r10, #0x2]
 *   @0x2788dc and r2, r2, #63
 *   @0x2788e0 orr r3, r1, r3, lsl #30
 *   @0x2788e4 ldrb r1, [r10, #0x3]
 *   @0x2788e8 and r12, r12, #63
 *   @0x2788ec orr r3, r3, r2, lsl #24
 *   @0x2788f0 ldrb r2, [r10, #0x4]
 *   @0x2788f4 and r1, r1, #63
 *   @0x2788f8 orr r3, r3, r12, lsl #18
 *   @0x2788fc and r2, r2, #63
 *   @0x278900 orr r3, r3, r1, lsl #12
 *   @0x278904 orr r3, r3, r2, lsl #6
 *   @0x278908 b 0x275258 <pcre_dfa_exec+0x6cf0>
 *   @0x27890c ldr r12, [sp, #0x20]
 *   @0x278910 mov r9, #2
 *   @0x278914 ldr r5, [r12, r3]
 *   @0x278918 b 0x27894c <pcre_dfa_exec+0xa3e4>
 *   @0x27891c cmp r0, #0
 *   @0x278920 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278924 ldr r12, [sp, #0x18]
 *   @0x278928 str r12, [r6, #0x90]
 *   @0x27892c ldrb r2, [r4, #0x1]
 *   @0x278930 ldrb r3, [r4, #0x2]
 *   @0x278934 ldr r12, [sp, #0x24]
 *   @0x278938 orr r3, r3, r2, lsl #8
 *   @0x27893c str r12, [r6, #0xac]
 *   @0x278940 ldrb r3, [r4, r3]!
 *   @0x278944 cmp r3, #119
 *   @0x278948 bne 0x2784e0 <pcre_dfa_exec+0x9f78>
 *   @0x27894c str r9, [r6, #0x98]
 *   @0x278950 mov r0, r10
 *   @0x278954 ldrb r1, [r4]
 *   @0x278958 mov r3, r11
 *   @0x27895c ldr lr, [sp, #0x164]
 *   @0x278960 ldr r12, [sp, #0x168]
 *   @0x278964 ldrb r1, [r5, r1]
 *   @0x278968 add r12, r12, #1
 *   @0x27896c ldr r2, [sp, #0x1c]
 *   @0x278970 add r1, r4, r1
 *   @0x278974 str r6, [sp]
 *   @0x278978 str lr, [sp, #0x4]
 *   @0x27897c str r12, [sp, #0x8]
 *   @0x278980 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278984 mvn r1, #996
 *   @0x278988 cmp r0, r1
 *   @0x27898c beq 0x2784e4 <pcre_dfa_exec+0x9f7c>
 *   @0x278990 cmn r0, #992
 *   @0x278994 bne 0x27891c <pcre_dfa_exec+0xa3b4>
 *   @0x278998 ldrb r1, [r4, #0x1]
 *   @0x27899c ldrb r3, [r4, #0x2]
 *   @0x2789a0 ldr r2, [r6, #0x7c]
 *   @0x2789a4 orr r3, r3, r1, lsl #8
 *   @0x2789a8 add r3, r4, r3
 *   @0x2789ac cmp r3, r2
 *   @0x2789b0 bls 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x2789b4 ldrb r2, [r4]
 *   @0x2789b8 cmp r2, #119
 *   @0x2789bc beq 0x278924 <pcre_dfa_exec+0xa3bc>
 *   @0x2789c0 ldrb r3, [r3]
 *   @0x2789c4 cmp r3, #119
 *   @0x2789c8 bne 0x26f6a8 <pcre_dfa_exec+0x1140>
 *   @0x2789cc b 0x278924 <pcre_dfa_exec+0xa3bc>
 *   @0x2789d0 mov r4, r11
 *   @0x2789d4 ldr r11, [sp, #0x18]
 *   @0x2789d8 b 0x2789f0 <pcre_dfa_exec+0xa488>
 *   @0x2789dc ldrb r3, [r8]
 *   @0x2789e0 add r8, r8, #1
 *   @0x2789e4 cmp r5, r3
 *   @0x2789e8 cmpne r12, r3
 *   @0x2789ec bne 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2789f0 ldr r2, [sp, #0x164]
 *   @0x2789f4 mov r0, r8
 *   @0x2789f8 ldr r3, [sp, #0x168]
 *   @0x2789fc mov r1, r4
 *   @0x278a00 str r6, [sp]
 *   @0x278a04 str r2, [sp, #0x4]
 *   @0x278a08 add r3, r3, #1
 *   @0x278a0c ldr r2, [sp, #0x1c]
 *   @0x278a10 str r3, [sp, #0x8]
 *   @0x278a14 mov r3, r11
 *   @0x278a18 str r12, [sp, #0x14]
 *   @0x278a1c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278a20 ldr r12, [sp, #0x14]
 *   @0x278a24 cmp r0, #0
 *   @0x278a28 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278a2c ldr r3, [sp, #0x2c]
 *   @0x278a30 cmp r7, r3
 *   @0x278a34 add r7, r7, #1
 *   @0x278a38 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278a3c ldr r3, [r6, #0x78]
 *   @0x278a40 cmp r8, r3
 *   @0x278a44 blo 0x2789dc <pcre_dfa_exec+0xa474>
 *   @0x278a48 b 0x273504 <pcre_dfa_exec+0x4f9c>
 *   @0x278a4c ldrb r12, [r10, #0x5]
 *   @0x278a50 and r2, r2, #1
 *   @0x278a54 ldrb r0, [r10, #0x1]
 *   @0x278a58 add r10, r10, #6
 *   @0x278a5c and r12, r12, #63
 *   @0x278a60 ldrb r4, [r10, #-0x4]
 *   @0x278a64 and r0, r0, #63
 *   @0x278a68 orr r2, r12, r2, lsl #30
 *   @0x278a6c ldrb r12, [r10, #-0x3]
 *   @0x278a70 and r4, r4, #63
 *   @0x278a74 orr r2, r2, r0, lsl #24
 *   @0x278a78 ldrb r0, [r10, #-0x2]
 *   @0x278a7c and r12, r12, #63
 *   @0x278a80 orr r2, r2, r4, lsl #18
 *   @0x278a84 and r0, r0, #63
 *   @0x278a88 orr r2, r2, r12, lsl #12
 *   @0x278a8c orr r2, r2, r0, lsl #6
 *   @0x278a90 b 0x2753b4 <pcre_dfa_exec+0x6e4c>
 *   @0x278a94 mov r9, r10
 *   @0x278a98 b 0x27680c <pcre_dfa_exec+0x82a4>
 *   @0x278a9c cmp r3, #122
 *   @0x278aa0 ldr r3, [sp, #0x168]
 *   @0x278aa4 beq 0x2792d4 <pcre_dfa_exec+0xad6c>
 *   @0x278aa8 ldr r7, [sp, #0x164]
 *   @0x278aac add r3, r3, #1
 *   @0x278ab0 mov r1, r11
 *   @0x278ab4 str r3, [sp, #0x8]
 *   @0x278ab8 str r6, [sp]
 *   @0x278abc mov r0, r4
 *   @0x278ac0 str r7, [sp, #0x4]
 *   @0x278ac4 ldr r2, [sp, #0x1c]
 *   @0x278ac8 ldr r3, [sp, #0x18]
 *   @0x278acc bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278ad0 cmp r0, #0
 *   @0x278ad4 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278ad8 add r11, r5, #3
 *   @0x278adc mov r10, r4
 *   @0x278ae0 b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x278ae4 tst r0, #8
 *   @0x278ae8 bne 0x278d50 <pcre_dfa_exec+0xa7e8>
 *   @0x278aec ldrb r3, [r10, #0x3]
 *   @0x278af0 and r0, r0, #7
 *   @0x278af4 ldrb r1, [r10, #0x1]
 *   @0x278af8 add r10, r10, #4
 *   @0x278afc ldrb r2, [r10, #-0x2]
 *   @0x278b00 and r3, r3, #63
 *   @0x278b04 and r1, r1, #63
 *   @0x278b08 orr r3, r3, r0, lsl #18
 *   @0x278b0c and r2, r2, #63
 *   @0x278b10 orr r3, r3, r1, lsl #12
 *   @0x278b14 orr r0, r3, r2, lsl #6
 *   @0x278b18 b 0x27816c <pcre_dfa_exec+0x9c04>
 *   @0x278b1c ldr r3, [r6, #0x88]
 *   @0x278b20 cmp r3, #0
 *   @0x278b24 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278b28 cmp r9, r10
 *   @0x278b2c bls 0x26f944 <pcre_dfa_exec+0x13dc>
 *   @0x278b30 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278b34 cmp r3, r5
 *   @0x278b38 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b3c bls 0x279184 <pcre_dfa_exec+0xac1c>
 *   @0x278b40 cmp r3, r8
 *   @0x278b44 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b48 cmp r3, #12288
 *   @0x278b4c beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b50 b 0x2772fc <pcre_dfa_exec+0x8d94>
 *   @0x278b54 sub r3, r3, #8192
 *   @0x278b58 sub r3, r3, #40
 *   @0x278b5c cmp r3, #1
 *   @0x278b60 bls 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b64 b 0x277254 <pcre_dfa_exec+0x8cec>
 *   @0x278b68 mov r4, r3
 *   @0x278b6c b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x278b70 cmp r3, #160
 *   @0x278b74 beq 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278b78 cmp r3, #5760
 *   @0x278b7c bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b80 b 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278b84 cmp r3, r5
 *   @0x278b88 beq 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278b8c bhi 0x278ba8 <pcre_dfa_exec+0xa640>
 *   @0x278b90 sub r3, r3, #8192
 *   @0x278b94 cmp r3, #10
 *   @0x278b98 bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278b9c b 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278ba0 mov r0, #0
 *   @0x278ba4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278ba8 cmp r3, r8
 *   @0x278bac beq 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278bb0 cmp r3, #12288
 *   @0x278bb4 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278bb8 b 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x278bbc mov r9, r10
 *   @0x278bc0 b 0x275ab8 <pcre_dfa_exec+0x7550>
 *   @0x278bc4 mov r4, r11
 *   @0x278bc8 ldr r11, [sp, #0x18]
 *   @0x278bcc b 0x278bfc <pcre_dfa_exec+0xa694>
 *   @0x278bd0 ldrb r3, [r10, #0x1]
 *   @0x278bd4 and r0, r0, #31
 *   @0x278bd8 add r10, r10, #2
 *   @0x278bdc and r3, r3, #63
 *   @0x278be0 orr r0, r3, r0, lsl #6
 *   @0x278be4 mov r1, r8
 *   @0x278be8 ldr r2, [sp, #0x28]
 *   @0x278bec bl 0x266cac <_pcre_xclass>
 *   @0x278bf0 cmp r0, #0
 *   @0x278bf4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278bf8 add r5, r5, #1
 *   @0x278bfc ldr r12, [sp, #0x164]
 *   @0x278c00 mov r0, r10
 *   @0x278c04 ldr r3, [sp, #0x168]
 *   @0x278c08 mov r1, r4
 *   @0x278c0c str r6, [sp]
 *   @0x278c10 add r3, r3, #1
 *   @0x278c14 str r12, [sp, #0x4]
 *   @0x278c18 str r3, [sp, #0x8]
 *   @0x278c1c mov r3, r11
 *   @0x278c20 ldr r2, [sp, #0x1c]
 *   @0x278c24 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278c28 cmp r0, #0
 *   @0x278c2c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278c30 cmp r5, r7
 *   @0x278c34 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278c38 ldr r3, [r6, #0x78]
 *   @0x278c3c cmp r10, r3
 *   @0x278c40 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x278c44 ldrb r0, [r10]
 *   @0x278c48 ldr r12, [sp, #0x28]
 *   @0x278c4c cmp r12, #0
 *   @0x278c50 cmpne r0, #191
 *   @0x278c54 addls r10, r10, #1
 *   @0x278c58 bls 0x278be4 <pcre_dfa_exec+0xa67c>
 *   @0x278c5c tst r0, #32
 *   @0x278c60 beq 0x278bd0 <pcre_dfa_exec+0xa668>
 *   @0x278c64 tst r0, #16
 *   @0x278c68 bne 0x278cd4 <pcre_dfa_exec+0xa76c>
 *   @0x278c6c lsl r2, r0, #12
 *   @0x278c70 ldrb r3, [r10, #0x2]
 *   @0x278c74 ldrb r1, [r10, #0x1]
 *   @0x278c78 add r10, r10, #3
 *   @0x278c7c uxth r2, r2
 *   @0x278c80 and r3, r3, #63
 *   @0x278c84 and r0, r1, #63
 *   @0x278c88 orr r3, r2, r3
 *   @0x278c8c orr r0, r3, r0, lsl #6
 *   @0x278c90 b 0x278be4 <pcre_dfa_exec+0xa67c>
 *   @0x278c94 tst r3, #8
 *   @0x278c98 bne 0x278dac <pcre_dfa_exec+0xa844>
 *   @0x278c9c ldrb r1, [r10, #0x3]
 *   @0x278ca0 and r3, r3, #7
 *   @0x278ca4 ldrb r0, [r10, #0x1]
 *   @0x278ca8 add r10, r10, #4
 *   @0x278cac ldrb r2, [r10, #-0x2]
 *   @0x278cb0 and r1, r1, #63
 *   @0x278cb4 and r0, r0, #63
 *   @0x278cb8 orr r3, r1, r3, lsl #18
 *   @0x278cbc and r2, r2, #63
 *   @0x278cc0 orr r3, r3, r0, lsl #12
 *   @0x278cc4 orr r3, r3, r2, lsl #6
 *   @0x278cc8 b 0x278348 <pcre_dfa_exec+0x9de0>
 *   @0x278ccc mvn r0, #5
 *   @0x278cd0 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278cd4 tst r0, #8
 *   @0x278cd8 bne 0x279008 <pcre_dfa_exec+0xaaa0>
 *   @0x278cdc ldrb r3, [r10, #0x3]
 *   @0x278ce0 and r0, r0, #7
 *   @0x278ce4 ldrb r2, [r10, #0x1]
 *   @0x278ce8 add r10, r10, #4
 *   @0x278cec ldrb r1, [r10, #-0x2]
 *   @0x278cf0 and r3, r3, #63
 *   @0x278cf4 and r2, r2, #63
 *   @0x278cf8 orr r3, r3, r0, lsl #18
 *   @0x278cfc and r0, r1, #63
 *   @0x278d00 orr r3, r3, r2, lsl #12
 *   @0x278d04 orr r0, r3, r0, lsl #6
 *   @0x278d08 b 0x278be4 <pcre_dfa_exec+0xa67c>
 *   @0x278d0c tst r3, #4
 *   @0x278d10 bne 0x278df0 <pcre_dfa_exec+0xa888>
 *   @0x278d14 ldrb r2, [r10, #0x4]
 *   @0x278d18 and r3, r3, #3
 *   @0x278d1c ldrb r0, [r10, #0x1]
 *   @0x278d20 add r10, r10, #5
 *   @0x278d24 and r2, r2, #63
 *   @0x278d28 ldrb r1, [r10, #-0x3]
 *   @0x278d2c orr r3, r2, r3, lsl #24
 *   @0x278d30 and r0, r0, #63
 *   @0x278d34 ldrb r2, [r10, #-0x2]
 *   @0x278d38 and r1, r1, #63
 *   @0x278d3c orr r3, r3, r0, lsl #18
 *   @0x278d40 and r2, r2, #63
 *   @0x278d44 orr r3, r3, r1, lsl #12
 *   @0x278d48 orr r3, r3, r2, lsl #6
 *   @0x278d4c b 0x2770cc <pcre_dfa_exec+0x8b64>
 *   @0x278d50 tst r0, #4
 *   @0x278d54 bne 0x2790e8 <pcre_dfa_exec+0xab80>
 *   @0x278d58 ldrb r3, [r10, #0x4]
 *   @0x278d5c and r12, r0, #3
 *   @0x278d60 ldrb r2, [r10, #0x1]
 *   @0x278d64 add r10, r10, #5
 *   @0x278d68 ldrb r1, [r10, #-0x3]
 *   @0x278d6c and r0, r3, #63
 *   @0x278d70 and r2, r2, #63
 *   @0x278d74 ldrb r3, [r10, #-0x2]
 *   @0x278d78 orr r0, r0, r12, lsl #24
 *   @0x278d7c and r1, r1, #63
 *   @0x278d80 orr r2, r0, r2, lsl #18
 *   @0x278d84 and r3, r3, #63
 *   @0x278d88 orr r2, r2, r1, lsl #12
 *   @0x278d8c orr r0, r2, r3, lsl #6
 *   @0x278d90 b 0x27816c <pcre_dfa_exec+0x9c04>
 *   @0x278d94 cmp r3, #133
 *   @0x278d98 bne 0x277b50 <pcre_dfa_exec+0x95e8>
 *   @0x278d9c ldr r3, [r6, #0x68]
 *   @0x278da0 cmp r3, #0
 *   @0x278da4 beq 0x2779e0 <pcre_dfa_exec+0x9478>
 *   @0x278da8 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x278dac tst r3, #4
 *   @0x278db0 bne 0x2791e8 <pcre_dfa_exec+0xac80>
 *   @0x278db4 ldrb r1, [r10, #0x4]
 *   @0x278db8 and r3, r3, #3
 *   @0x278dbc ldrb r0, [r10, #0x1]
 *   @0x278dc0 add r10, r10, #5
 *   @0x278dc4 ldrb r2, [r10, #-0x3]
 *   @0x278dc8 and r1, r1, #63
 *   @0x278dcc ldrb r12, [r10, #-0x2]
 *   @0x278dd0 and r0, r0, #63
 *   @0x278dd4 orr r1, r1, r3, lsl #24
 *   @0x278dd8 and r2, r2, #63
 *   @0x278ddc orr r3, r1, r0, lsl #18
 *   @0x278de0 and r12, r12, #63
 *   @0x278de4 orr r3, r3, r2, lsl #12
 *   @0x278de8 orr r3, r3, r12, lsl #6
 *   @0x278dec b 0x278348 <pcre_dfa_exec+0x9de0>
 *   @0x278df0 ldrb r1, [r10, #0x5]
 *   @0x278df4 and r3, r3, #1
 *   @0x278df8 ldrb r2, [r10, #0x1]
 *   @0x278dfc add r10, r10, #6
 *   @0x278e00 and r1, r1, #63
 *   @0x278e04 ldrb r0, [r10, #-0x4]
 *   @0x278e08 and r2, r2, #63
 *   @0x278e0c orr r3, r1, r3, lsl #30
 *   @0x278e10 ldrb r1, [r10, #-0x3]
 *   @0x278e14 and r0, r0, #63
 *   @0x278e18 orr r3, r3, r2, lsl #24
 *   @0x278e1c ldrb r2, [r10, #-0x2]
 *   @0x278e20 and r1, r1, #63
 *   @0x278e24 orr r3, r3, r0, lsl #18
 *   @0x278e28 and r2, r2, #63
 *   @0x278e2c orr r3, r3, r1, lsl #12
 *   @0x278e30 orr r3, r3, r2, lsl #6
 *   @0x278e34 b 0x2770cc <pcre_dfa_exec+0x8b64>
 *   @0x278e38 sub r3, r3, #8192
 *   @0x278e3c sub r3, r3, #40
 *   @0x278e40 cmp r3, #1
 *   @0x278e44 bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x278e48 b 0x277274 <pcre_dfa_exec+0x8d0c>
 *   @0x278e4c mov r7, r10
 *   @0x278e50 b 0x27624c <pcre_dfa_exec+0x7ce4>
 *   @0x278e54 ldr r3, [r6, #0xb4]
 *   @0x278e58 cmp r8, r3
 *   @0x278e5c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278e60 b 0x278094 <pcre_dfa_exec+0x9b2c>
 *   @0x278e64 ldr r12, [sp, #0x164]
 *   @0x278e68 add r3, r3, #1
 *   @0x278e6c add r1, r11, #3
 *   @0x278e70 str r3, [sp, #0x8]
 *   @0x278e74 str r6, [sp]
 *   @0x278e78 mov r0, r10
 *   @0x278e7c str r12, [sp, #0x4]
 *   @0x278e80 ldr r2, [sp, #0x1c]
 *   @0x278e84 ldr r3, [sp, #0x18]
 *   @0x278e88 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278e8c cmp r0, #0
 *   @0x278e90 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278e94 ldrb r3, [r8]
 *   @0x278e98 cmp r3, #129
 *   @0x278e9c beq 0x278f00 <pcre_dfa_exec+0xa998>
 *   @0x278ea0 cmp r3, #135
 *   @0x278ea4 bhi 0x278ecc <pcre_dfa_exec+0xa964>
 *   @0x278ea8 mov r11, r8
 *   @0x278eac b 0x26f260 <pcre_dfa_exec+0xcf8>
 *   @0x278eb0 add r8, r8, #1
 *   @0x278eb4 cmp r8, r7
 *   @0x278eb8 movne r2, r4
 *   @0x278ebc bne 0x2724cc <pcre_dfa_exec+0x3f64>
 *   @0x278ec0 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x278ec4 mov r4, r10
 *   @0x278ec8 b 0x2724d0 <pcre_dfa_exec+0x3f68>
 *   @0x278ecc ldr r11, [sp, #0x18]
 *   @0x278ed0 mov r0, r10
 *   @0x278ed4 ldr r7, [sp, #0x164]
 *   @0x278ed8 mov r1, r8
 *   @0x278edc ldr r12, [sp, #0x168]
 *   @0x278ee0 str r6, [sp]
 *   @0x278ee4 mov r3, r11
 *   @0x278ee8 add r12, r12, #1
 *   @0x278eec str r7, [sp, #0x4]
 *   @0x278ef0 ldr r2, [sp, #0x1c]
 *   @0x278ef4 str r12, [sp, #0x8]
 *   @0x278ef8 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278efc b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278f00 ldr r11, [sp, #0x18]
 *   @0x278f04 mov r0, r10
 *   @0x278f08 ldr r5, [sp, #0x164]
 *   @0x278f0c mov r1, r8
 *   @0x278f10 ldr r12, [sp, #0x168]
 *   @0x278f14 str r6, [sp]
 *   @0x278f18 mov r3, r11
 *   @0x278f1c add r12, r12, #1
 *   @0x278f20 ldr r2, [sp, #0x1c]
 *   @0x278f24 str r5, [sp, #0x4]
 *   @0x278f28 str r12, [sp, #0x8]
 *   @0x278f2c bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278f30 cmp r0, #0
 *   @0x278f34 streq r8, [r6, #0xb4]
 *   @0x278f38 mvneq r0, #996
 *   @0x278f3c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278f40 mov r4, r10
 *   @0x278f44 b 0x273ca0 <pcre_dfa_exec+0x5738>
 *   @0x278f48 cmp r3, #1
 *   @0x278f4c beq 0x277f88 <pcre_dfa_exec+0x9a20>
 *   @0x278f50 ldrb r3, [r6, #0x35]
 *   @0x278f54 ldrb r2, [r10, #0x1]
 *   @0x278f58 subs r1, r2, r3
 *   @0x278f5c rsbs r3, r1, #0
 *   @0x278f60 adcs r3, r3, r1
 *   @0x278f64 b 0x277f88 <pcre_dfa_exec+0x9a20>
 *   @0x278f68 mov r4, r11
 *   @0x278f6c ldr r5, [sp, #0x164]
 *   @0x278f70 ldr r11, [sp, #0x18]
 *   @0x278f74 mov r0, r10
 *   @0x278f78 ldr r12, [sp, #0x168]
 *   @0x278f7c add r1, r4, #3
 *   @0x278f80 str r6, [sp]
 *   @0x278f84 add r12, r12, #1
 *   @0x278f88 str r5, [sp, #0x4]
 *   @0x278f8c ldr r2, [sp, #0x1c]
 *   @0x278f90 mov r3, r11
 *   @0x278f94 str r12, [sp, #0x8]
 *   @0x278f98 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x278f9c cmp r0, #0
 *   @0x278fa0 streq r8, [r6, #0xb4]
 *   @0x278fa4 mvneq r0, #996
 *   @0x278fa8 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x278fac mov r4, r10
 *   @0x278fb0 b 0x273b90 <pcre_dfa_exec+0x5628>
 *   @0x278fb4 mov r4, r10
 *   @0x278fb8 b 0x27371c <pcre_dfa_exec+0x51b4>
 *   @0x278fbc mov r5, #1
 *   @0x278fc0 mov r3, r11
 *   @0x278fc4 str r5, [sp, #0x50]
 *   @0x278fc8 b 0x274cb0 <pcre_dfa_exec+0x6748>
 *   @0x278fcc mov r4, r10
 *   @0x278fd0 b 0x273998 <pcre_dfa_exec+0x5430>
 *   @0x278fd4 mov r4, r10
 *   @0x278fd8 b 0x273a14 <pcre_dfa_exec+0x54ac>
 *   @0x278fdc mov r4, r10
 *   @0x278fe0 b 0x27390c <pcre_dfa_exec+0x53a4>
 *   @0x278fe4 ldr r7, [sp, #0x24]
 *   @0x278fe8 mov r12, #1
 *   @0x278fec cmp r7, #0
 *   @0x278ff0 bne 0x27904c <pcre_dfa_exec+0xaae4>
 *   @0x278ff4 mov r11, r0
 *   @0x278ff8 str r7, [sp, #0x30]
 *   @0x278ffc mov r0, r12
 *   @0x279000 str r7, [sp, #0x2c]
 *   @0x279004 b 0x27125c <pcre_dfa_exec+0x2cf4>
 *   @0x279008 tst r0, #4
 *   @0x27900c bne 0x279064 <pcre_dfa_exec+0xaafc>
 *   @0x279010 ldrb r3, [r10, #0x4]
 *   @0x279014 and r0, r0, #3
 *   @0x279018 ldrb r1, [r10, #0x1]
 *   @0x27901c add r10, r10, #5
 *   @0x279020 ldrb r2, [r10, #-0x3]
 *   @0x279024 and r3, r3, #63
 *   @0x279028 orr r3, r3, r0, lsl #24
 *   @0x27902c and r1, r1, #63
 *   @0x279030 ldrb r0, [r10, #-0x2]
 *   @0x279034 and r2, r2, #63
 *   @0x279038 orr r3, r3, r1, lsl #18
 *   @0x27903c and r0, r0, #63
 *   @0x279040 orr r3, r3, r2, lsl #12
 *   @0x279044 orr r0, r3, r0, lsl #6
 *   @0x279048 b 0x278be4 <pcre_dfa_exec+0xa67c>
 *   @0x27904c mov r1, #0
 *   @0x279050 mov r11, r0
 *   @0x279054 str r1, [sp, #0x30]
 *   @0x279058 mov r0, r12
 *   @0x27905c str r1, [sp, #0x2c]
 *   @0x279060 b 0x274398 <pcre_dfa_exec+0x5e30>
 *   @0x279064 ldrb r3, [r10, #0x5]
 *   @0x279068 and r0, r0, #1
 *   @0x27906c ldrb r12, [r10, #0x1]
 *   @0x279070 add r10, r10, #6
 *   @0x279074 ldrb r1, [r10, #-0x4]
 *   @0x279078 and r3, r3, #63
 *   @0x27907c ldrb r2, [r10, #-0x3]
 *   @0x279080 and r12, r12, #63
 *   @0x279084 orr r3, r3, r0, lsl #30
 *   @0x279088 and r1, r1, #63
 *   @0x27908c ldrb r0, [r10, #-0x2]
 *   @0x279090 orr r3, r3, r12, lsl #24
 *   @0x279094 and r2, r2, #63
 *   @0x279098 orr r3, r3, r1, lsl #18
 *   @0x27909c and r0, r0, #63
 *   @0x2790a0 orr r3, r3, r2, lsl #12
 *   @0x2790a4 orr r0, r3, r0, lsl #6
 *   @0x2790a8 b 0x278be4 <pcre_dfa_exec+0xa67c>
 *   @0x2790ac ldr r3, [r6, #0x88]
 *   @0x2790b0 cmp r3, #0
 *   @0x2790b4 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2790b8 cmp r5, r10
 *   @0x2790bc bls 0x26f944 <pcre_dfa_exec+0x13dc>
 *   @0x2790c0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2790c4 cmp r3, #133
 *   @0x2790c8 beq 0x2772c0 <pcre_dfa_exec+0x8d58>
 *   @0x2790cc blo 0x2790e0 <pcre_dfa_exec+0xab78>
 *   @0x2790d0 sub r3, r3, #8192
 *   @0x2790d4 sub r3, r3, #40
 *   @0x2790d8 cmp r3, #1
 *   @0x2790dc bls 0x2772c0 <pcre_dfa_exec+0x8d58>
 *   @0x2790e0 mov r0, #0
 *   @0x2790e4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2790e8 ldrb r3, [r10, #0x5]
 *   @0x2790ec and r0, r0, #1
 *   @0x2790f0 ldrb r12, [r10, #0x1]
 *   @0x2790f4 add r10, r10, #6
 *   @0x2790f8 ldrb r2, [r10, #-0x4]
 *   @0x2790fc and r3, r3, #63
 *   @0x279100 ldrb r1, [r10, #-0x3]
 *   @0x279104 and r12, r12, #63
 *   @0x279108 orr r0, r3, r0, lsl #30
 *   @0x27910c and r2, r2, #63
 *   @0x279110 ldrb r3, [r10, #-0x2]
 *   @0x279114 orr r0, r0, r12, lsl #24
 *   @0x279118 and r1, r1, #63
 *   @0x27911c orr r2, r0, r2, lsl #18
 *   @0x279120 and r3, r3, #63
 *   @0x279124 orr r2, r2, r1, lsl #12
 *   @0x279128 orr r0, r2, r3, lsl #6
 *   @0x27912c b 0x27816c <pcre_dfa_exec+0x9c04>
 *   @0x279130 mov r4, r10
 *   @0x279134 b 0x273c14 <pcre_dfa_exec+0x56ac>
 *   @0x279138 tst r1, #8
 *   @0x27913c bne 0x279194 <pcre_dfa_exec+0xac2c>
 *   @0x279140 ldrb r3, [r10, #0x3]
 *   @0x279144 and r1, r1, #7
 *   @0x279148 ldrb r2, [r10, #0x1]
 *   @0x27914c add r7, r10, #4
 *   @0x279150 ldrb r0, [r10, #0x2]
 *   @0x279154 and r3, r3, #63
 *   @0x279158 and r2, r2, #63
 *   @0x27915c orr r3, r3, r1, lsl #18
 *   @0x279160 and r0, r0, #63
 *   @0x279164 orr r3, r3, r2, lsl #12
 *   @0x279168 orr r1, r3, r0, lsl #6
 *   @0x27916c b 0x278804 <pcre_dfa_exec+0xa29c>
 *   @0x279170 add r8, r8, #1
 *   @0x279174 cmp r8, r7
 *   @0x279178 beq 0x278754 <pcre_dfa_exec+0xa1ec>
 *   @0x27917c mov r4, r3
 *   @0x279180 b 0x2725c8 <pcre_dfa_exec+0x4060>
 *   @0x279184 sub r3, r3, #8192
 *   @0x279188 cmp r3, #10
 *   @0x27918c bls 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x279190 b 0x2772fc <pcre_dfa_exec+0x8d94>
 *   @0x279194 tst r1, #4
 *   @0x279198 bne 0x27923c <pcre_dfa_exec+0xacd4>
 *   @0x27919c ldrb r2, [r10, #0x4]
 *   @0x2791a0 and r9, r1, #3
 *   @0x2791a4 ldrb r3, [r10, #0x1]
 *   @0x2791a8 add r7, r10, #5
 *   @0x2791ac and r1, r2, #63
 *   @0x2791b0 ldrb r2, [r10, #0x2]
 *   @0x2791b4 and r3, r3, #63
 *   @0x2791b8 ldrb r0, [r10, #0x3]
 *   @0x2791bc orr r1, r1, r9, lsl #24
 *   @0x2791c0 and r2, r2, #63
 *   @0x2791c4 orr r3, r1, r3, lsl #18
 *   @0x2791c8 and r0, r0, #63
 *   @0x2791cc orr r3, r3, r2, lsl #12
 *   @0x2791d0 orr r1, r3, r0, lsl #6
 *   @0x2791d4 b 0x278804 <pcre_dfa_exec+0xa29c>
 *   @0x2791d8 mov r3, r1
 *   @0x2791dc b 0x272644 <pcre_dfa_exec+0x40dc>
 *   @0x2791e0 str r8, [sp, #0x30]
 *   @0x2791e4 b 0x2710dc <pcre_dfa_exec+0x2b74>
 *   @0x2791e8 ldrb r1, [r10, #0x5]
 *   @0x2791ec and r3, r3, #1
 *   @0x2791f0 ldrb r0, [r10, #0x1]
 *   @0x2791f4 add r10, r10, #6
 *   @0x2791f8 ldrb r2, [r10, #-0x4]
 *   @0x2791fc and r1, r1, #63
 *   @0x279200 ldrb r12, [r10, #-0x3]
 *   @0x279204 and r0, r0, #63
 *   @0x279208 orr r3, r1, r3, lsl #30
 *   @0x27920c and r2, r2, #63
 *   @0x279210 ldrb r1, [r10, #-0x2]
 *   @0x279214 orr r0, r3, r0, lsl #24
 *   @0x279218 and r12, r12, #63
 *   @0x27921c orr r3, r0, r2, lsl #18
 *   @0x279220 and r1, r1, #63
 *   @0x279224 orr r3, r3, r12, lsl #12
 *   @0x279228 orr r3, r3, r1, lsl #6
 *   @0x27922c b 0x278348 <pcre_dfa_exec+0x9de0>
 *   @0x279230 ldr r2, [r6, #0x88]
 *   @0x279234 mov r4, r10
 *   @0x279238 b 0x272654 <pcre_dfa_exec+0x40ec>
 *   @0x27923c ldrb r3, [r10, #0x2]
 *   @0x279240 and r1, r1, #1
 *   @0x279244 ldrb r2, [r10, #0x5]
 *   @0x279248 add r7, r10, #6
 *   @0x27924c ldrb r0, [r10, #0x1]
 *   @0x279250 and r9, r3, #63
 *   @0x279254 and r2, r2, #63
 *   @0x279258 ldrb r3, [r10, #0x3]
 *   @0x27925c and r0, r0, #63
 *   @0x279260 orr r2, r2, r1, lsl #30
 *   @0x279264 ldrb r1, [r10, #0x4]
 *   @0x279268 and r3, r3, #63
 *   @0x27926c orr r2, r2, r0, lsl #24
 *   @0x279270 orr r2, r2, r9, lsl #18
 *   @0x279274 and r1, r1, #63
 *   @0x279278 orr r3, r2, r3, lsl #12
 *   @0x27927c orr r1, r3, r1, lsl #6
 *   @0x279280 b 0x278804 <pcre_dfa_exec+0xa29c>
 *   @0x279284 mvn r3, #996
 *   @0x279288 cmp r0, r3
 *   @0x27928c mov r4, r11
 *   @0x279290 bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x279294 ldrb r3, [r11]
 *   @0x279298 cmp r3, #129
 *   @0x27929c bne 0x2792a8 <pcre_dfa_exec+0xad40>
 *   @0x2792a0 b 0x2792c0 <pcre_dfa_exec+0xad58>
 *   @0x2792a4 ldrb r3, [r4, r3]!
 *   @0x2792a8 ldrb r2, [r4, #0x1]
 *   @0x2792ac cmp r3, #119
 *   @0x2792b0 ldrb r3, [r4, #0x2]
 *   @0x2792b4 orr r3, r3, r2, lsl #8
 *   @0x2792b8 beq 0x2792a4 <pcre_dfa_exec+0xad3c>
 *   @0x2792bc rsb r4, r3, r4
 *   @0x2792c0 ldr r3, [r6, #0xb4]
 *   @0x2792c4 cmp r3, r4
 *   @0x2792c8 mvnne r0, #996
 *   @0x2792cc bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2792d0 b 0x270504 <pcre_dfa_exec+0x1f9c>
 *   @0x2792d4 ldr r12, [sp, #0x164]
 *   @0x2792d8 add r3, r3, #1
 *   @0x2792dc add r1, r5, #3
 *   @0x2792e0 str r3, [sp, #0x8]
 *   @0x2792e4 str r6, [sp]
 *   @0x2792e8 mov r0, r4
 *   @0x2792ec str r12, [sp, #0x4]
 *   @0x2792f0 ldr r2, [sp, #0x1c]
 *   @0x2792f4 ldr r3, [sp, #0x18]
 *   @0x2792f8 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2792fc cmp r0, #0
 *   @0x279300 beq 0x2725a0 <pcre_dfa_exec+0x4038>
 *   @0x279304 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x279308 ldr r2, [r6, #0x88]
 *   @0x27930c mov r4, r10
 *   @0x279310 b 0x273b94 <pcre_dfa_exec+0x562c>
 *   @0x279314 cmp r3, #9
 *   @0x279318 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x27931c b 0x2772fc <pcre_dfa_exec+0x8d94>
 *   @0x279320 ldr r3, [r6, #0x88]
 *   @0x279324 cmp r3, #0
 *   @0x279328 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27932c ldr r2, [r6, #0x84]
 *   @0x279330 cmp r2, r10
 *   @0x279334 bhs 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x279338 cmp r3, #1
 *   @0x27933c mov r3, #1
 *   @0x279340 str r3, [r6, #0x64]
 *   @0x279344 ble 0x270504 <pcre_dfa_exec+0x1f9c>
 *   @0x279348 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x27934c cmp r3, #1
 *   @0x279350 beq 0x277fb4 <pcre_dfa_exec+0x9a4c>
 *   @0x279354 ldrb r3, [r6, #0x35]
 *   @0x279358 ldrb r2, [r10, #0x1]
 *   @0x27935c subs r2, r2, r3
 *   @0x279360 rsbs r3, r2, #0
 *   @0x279364 adcs r3, r3, r2
 *   @0x279368 b 0x277fb4 <pcre_dfa_exec+0x9a4c>
 *   @0x27936c mov r4, r10
 *   @0x279370 b 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x279374 add r8, r8, #1
 *   @0x279378 cmp r8, r7
 *   @0x27937c beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x279380 mov r2, r4
 *   @0x279384 b 0x272474 <pcre_dfa_exec+0x3f0c>
 *   @0x279388 mov r5, r10
 */
