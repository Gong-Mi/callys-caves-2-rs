/* cally 逆向卡：Reach_05 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 31 个函数｜锚点 7440 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/31 IO_UpdateM  0x18f094  size 1080  270 条（0x18f094..0x18f4cc）
 * @func 0x18f094 0x18f4cc  size 1080  270 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x18f0a4→0x534ca0, 0x18f0b8→0x534ba0, 0x18f0d0→0x534af0, 0x18f0e8→0x534b10, 0x18f100→0x534b30, 0x18f138→0x534da0, 0x18f13c→0x535730, 0x18f38c→0x535700
 * 调用序列: 0xb65b0×5 / 0xb65bc
 * 字段偏移 top8: 0x8×3 / 0x4×3 / 0x378×2 / 0x130×2 / 0x1×2 / 0x28×2 / 0x3f8×1 / 0x3f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x18f094 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x18f098 mov r1, #0
 *   @0x18f09c ldr r4, [pc, #0x3f8]
 *   @0x18f0a0 mov r2, #256
 *   @0x18f0a4 ldr r3, [pc, #0x3f4]
 *   @0x18f0a8 add r4, pc, r4
 *   @0x18f0ac ldr r9, [r4, r3]
 *   @0x18f0b0 mov r0, r9
 *   @0x18f0b4 bl 0xb65b0 <memset@plt>
 *   @0x18f0b8 ldr r3, [pc, #0x3e4]
 *   @0x18f0bc mov r1, #0
 *   @0x18f0c0 mov r2, #256
 *   @0x18f0c4 ldr r5, [r4, r3]
 *   @0x18f0c8 mov r0, r5
 *   @0x18f0cc bl 0xb65b0 <memset@plt>
 *   @0x18f0d0 ldr r3, [pc, #0x3d0]
 *   @0x18f0d4 mov r1, #0
 *   @0x18f0d8 mov r2, #30
 *   @0x18f0dc ldr r6, [r4, r3]
 *   @0x18f0e0 mov r0, r6
 *   @0x18f0e4 bl 0xb65b0 <memset@plt>
 *   @0x18f0e8 ldr r3, [pc, #0x3bc]
 *   @0x18f0ec mov r1, #0
 *   @0x18f0f0 mov r2, #30
 *   @0x18f0f4 ldr r8, [r4, r3]
 *   @0x18f0f8 mov r0, r8
 *   @0x18f0fc bl 0xb65b0 <memset@plt>
 *   @0x18f100 ldr r3, [pc, #0x3a8]
 *   @0x18f104 mov r1, #0
 *   @0x18f108 mov r2, #30
 *   @0x18f10c ldr r7, [r4, r3]
 *   @0x18f110 mov r0, r7
 *   @0x18f114 bl 0xb65b0 <memset@plt>
 *   @0x18f118 ldr r2, [pc, #0x394]
 *   @0x18f11c mov r1, #0
 *   @0x18f120 add r2, pc, r2
 *   @0x18f124 ldr r3, [r2, #0x8]
 *   @0x18f128 str r1, [r2, #0x4]
 *   @0x18f12c cmp r3, r1
 *   @0x18f130 str r1, [r2, #0x8]
 *   @0x18f134 beq 0x18f488 <_Z10IO_UpdateMv+0x3f4>
 *   @0x18f138 ldr r0, [pc, #0x378]
 *   @0x18f13c ldr r1, [pc, #0x378]
 *   @0x18f140 ldr r10, [r2]
 *   @0x18f144 ldr r0, [r4, r0]
 *   @0x18f148 ldr r1, [r4, r1]
 *   @0x18f14c ldr r2, [r3, #0x8]
 *   @0x18f150 ldr lr, [r3]
 *   @0x18f154 sub r12, r2, #4
 *   @0x18f158 cmp r12, #105
 *   @0x18f15c addls pc, pc, r12, lsl #2
 *   @0x18f160 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f164 b 0x18f474 <_Z10IO_UpdateMv+0x3e0>
 *   @0x18f168 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f16c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f170 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f174 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f178 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f17c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f180 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f184 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f188 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f18c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f190 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f194 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f198 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f19c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1a0 b 0x18f47c <_Z10IO_UpdateMv+0x3e8>
 *   @0x18f1a4 b 0x18f46c <_Z10IO_UpdateMv+0x3d8>
 *   @0x18f1a8 b 0x18f464 <_Z10IO_UpdateMv+0x3d0>
 *   @0x18f1ac b 0x18f45c <_Z10IO_UpdateMv+0x3c8>
 *   @0x18f1b0 b 0x18f454 <_Z10IO_UpdateMv+0x3c0>
 *   @0x18f1b4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1b8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1bc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1c0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1c4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1c8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1cc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1d0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1d4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1d8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1dc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1e0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1e4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1e8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1ec b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1f0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1f4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1f8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f1fc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f200 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f204 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f208 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f20c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f210 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f214 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f218 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f21c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f220 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f224 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f228 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f22c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f230 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f234 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f238 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f23c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f240 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f244 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f248 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f24c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f250 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f254 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f258 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f25c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f260 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f264 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f268 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f26c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f270 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f274 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f278 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f27c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f280 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f284 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f288 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f28c b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f290 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f294 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f298 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f29c b 0x18f44c <_Z10IO_UpdateMv+0x3b8>
 *   @0x18f2a0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2a4 b 0x18f444 <_Z10IO_UpdateMv+0x3b0>
 *   @0x18f2a8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2ac b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2b0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2b4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2b8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2bc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2c0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2c4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2c8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2cc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2d0 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2d4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2d8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2dc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2e0 b 0x18f43c <_Z10IO_UpdateMv+0x3a8>
 *   @0x18f2e4 b 0x18f434 <_Z10IO_UpdateMv+0x3a0>
 *   @0x18f2e8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2ec b 0x18f42c <_Z10IO_UpdateMv+0x398>
 *   @0x18f2f0 b 0x18f424 <_Z10IO_UpdateMv+0x390>
 *   @0x18f2f4 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2f8 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f2fc b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f300 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f304 b 0x18f344 <_Z10IO_UpdateMv+0x2b0>
 *   @0x18f308 b 0x18f30c <_Z10IO_UpdateMv+0x278>
 *   @0x18f30c mov r2, #13
 *   @0x18f310 ldr r12, [r3, #0x4]
 *   @0x18f314 cmp r12, #0
 *   @0x18f318 beq 0x18f354 <_Z10IO_UpdateMv+0x2c0>
 *   @0x18f31c cmp r12, #1
 *   @0x18f320 strbeq r12, [r9, r2]
 *   @0x18f324 moveq r12, #0
 *   @0x18f328 strbeq r12, [r1, r2]
 *   @0x18f32c cmp lr, #0
 *   @0x18f330 str r10, [r3]
 *   @0x18f334 beq 0x18f378 <_Z10IO_UpdateMv+0x2e4>
 *   @0x18f338 mov r10, r3
 *   @0x18f33c mov r3, lr
 *   @0x18f340 b 0x18f14c <_Z10IO_UpdateMv+0xb8>
 *   @0x18f344 ldr r12, [r3, #0x4]
 *   @0x18f348 mov r2, #161
 *   @0x18f34c cmp r12, #0
 *   @0x18f350 bne 0x18f31c <_Z10IO_UpdateMv+0x288>
 *   @0x18f354 ldrb r12, [r0, r2]
 *   @0x18f358 cmp r12, #0
 *   @0x18f35c moveq r12, #1
 *   @0x18f360 strbeq r12, [r5, r2]
 *   @0x18f364 cmp lr, #0
 *   @0x18f368 mov r12, #1
 *   @0x18f36c strb r12, [r1, r2]
 *   @0x18f370 str r10, [r3]
 *   @0x18f374 bne 0x18f338 <_Z10IO_UpdateMv+0x2a4>
 *   @0x18f378 ldr r2, [pc, #0x140]
 *   @0x18f37c add r2, pc, r2
 *   @0x18f380 str r3, [r2]
 *   @0x18f384 mov r2, #256
 *   @0x18f388 bl 0xb65bc <memcpy@plt>
 *   @0x18f38c ldr r2, [pc, #0x130]
 *   @0x18f390 ldr r3, [pc, #0x130]
 *   @0x18f394 mov r1, r7
 *   @0x18f398 mov r12, #1
 *   @0x18f39c ldr r7, [r4, r2]
 *   @0x18f3a0 mov r2, #0
 *   @0x18f3a4 ldr r4, [r4, r3]
 *   @0x18f3a8 b 0x18f3ec <_Z10IO_UpdateMv+0x358>
 *   @0x18f3ac eor r0, r3, r0
 *   @0x18f3b0 strb r12, [r1]
 *   @0x18f3b4 tst r0, #1
 *   @0x18f3b8 strbne r12, [r6]
 *   @0x18f3bc ands r5, r3, #2
 *   @0x18f3c0 beq 0x18f414 <_Z10IO_UpdateMv+0x380>
 *   @0x18f3c4 tst r0, #2
 *   @0x18f3c8 strb r12, [r1, #0x1]
 *   @0x18f3cc strbne r12, [r6, #0x1]
 *   @0x18f3d0 str r3, [r4, r2]
 *   @0x18f3d4 add r2, r2, #4
 *   @0x18f3d8 cmp r2, #40
 *   @0x18f3dc add r6, r6, #3
 *   @0x18f3e0 add r8, r8, #3
 *   @0x18f3e4 add r1, r1, #3
 *   @0x18f3e8 beq 0x18f484 <_Z10IO_UpdateMv+0x3f0>
 *   @0x18f3ec ldr r3, [r7, r2]
 *   @0x18f3f0 ldr r0, [r4, r2]
 *   @0x18f3f4 ands r5, r3, #1
 *   @0x18f3f8 bne 0x18f3ac <_Z10IO_UpdateMv+0x318>
 *   @0x18f3fc eor r0, r3, r0
 *   @0x18f400 strb r5, [r1]
 *   @0x18f404 tst r0, #1
 *   @0x18f408 strbne r12, [r8]
 *   @0x18f40c ands r5, r3, #2
 *   @0x18f410 bne 0x18f3c4 <_Z10IO_UpdateMv+0x330>
 *   @0x18f414 tst r0, #2
 *   @0x18f418 strb r5, [r1, #0x1]
 *   @0x18f41c strbne r12, [r8, #0x1]
 *   @0x18f420 b 0x18f3d0 <_Z10IO_UpdateMv+0x33c>
 *   @0x18f424 mov r2, #82
 *   @0x18f428 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f42c mov r2, #76
 *   @0x18f430 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f434 mov r2, #84
 *   @0x18f438 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f43c mov r2, #83
 *   @0x18f440 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f444 mov r2, #17
 *   @0x18f448 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f44c mov r2, #77
 *   @0x18f450 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f454 mov r2, #32
 *   @0x18f458 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f45c mov r2, #39
 *   @0x18f460 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f464 mov r2, #37
 *   @0x18f468 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f46c mov r2, #40
 *   @0x18f470 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f474 mov r2, #8
 *   @0x18f478 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f47c mov r2, #38
 *   @0x18f480 b 0x18f310 <_Z10IO_UpdateMv+0x27c>
 *   @0x18f484 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x18f488 ldr r2, [pc, #0x28]
 *   @0x18f48c ldr r3, [pc, #0x28]
 *   @0x18f490 ldr r0, [r4, r2]
 *   @0x18f494 ldr r1, [r4, r3]
 *   @0x18f498 b 0x18f384 <_Z10IO_UpdateMv+0x2f0>
 *   @0x18f49c eoreq r2, r6, r8, lsr #23
 *   @0x18f4a0 .word 0xffffe994
 *   @0x18f4a4 .word 0xffffe998
 *   @0x18f4a8 .word 0xffffe9ac
 *   @0x18f4ac .word 0xffffe9a8
 *   @0x18f4b0 .word 0xffffe9a4
 *   @0x18f4b4 eorseq r6, r10, r0, lsr #11
 *   @0x18f4b8 .word 0xffffe990
 *   @0x18f4bc .word 0xffffea00
 *   @0x18f4c0 eorseq r6, r10, r4, asr #6
 *   @0x18f4c4 .word 0xffffe9dc
 *   @0x18f4c8 .word 0xffffea04
 *
 * ══ §2/31 b2ContactSolver::InitializeVelocityConstraints  0x2e2398  size 1080  270 条（0x2e2398..0x2e27d0）
 * @func 0x2e2398 0x2e27d0  size 1080  270 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6580×2 / 0xb658c×2 / b2ContactSolver::InitializeVelocityConstraints()+0x340 / b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float) / b2ContactSolver::InitializeVelocityConstraints()+0x328
 * 字段偏移 top8: 0x1c×3 / 0x30×2 / 0x18×2 / 0x8×2 / 0xc×2 / 0x10×2 / 0x14×2 / 0x38×1
 * VFP 指令 174 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e2398 ldr r3, [r0, #0x30]
 *   @0x2e239c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2e23a0 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e23a4 cmp r3, #0
 *   @0x2e23a8 sub sp, sp, #124
 *   @0x2e23ac mov r6, r0
 *   @0x2e23b0 ble 0x2e26d8 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x340>
 *   @0x2e23b4 vmov.f32 s18, #1.000000e+00
 *   @0x2e23b8 mov r7, #0
 *   @0x2e23bc mov r9, r7
 *   @0x2e23c0 mov r8, r7
 *   @0x2e23c4 mov r5, #0
 *   @0x2e23c8 add r12, sp, #96
 *   @0x2e23cc str r12, [sp, #0x1c]
 *   @0x2e23d0 add r12, sp, #64
 *   @0x2e23d4 str r12, [sp, #0x38]
 *   @0x2e23d8 add r12, sp, #80
 *   @0x2e23dc str r12, [sp, #0x3c]
 *   @0x2e23e0 vmov.f32 s29, #-1.000000e+00
 *   @0x2e23e4 ldr r4, [r6, #0x28]
 *   @0x2e23e8 ldr r1, [r6, #0x2c]
 *   @0x2e23ec add r4, r4, r9
 *   @0x2e23f0 ldr lr, [r6, #0x18]
 *   @0x2e23f4 vldr s3, [r4, #120]
 *   @0x2e23f8 vldr s4, [r4, #124]
 *   @0x2e23fc ldr r10, [r4, #0x70]
 *   @0x2e2400 vstr s3, [sp, #48]
 *   @0x2e2404 ldr r3, [r4, #0x98]
 *   @0x2e2408 vstr s4, [sp, #52]
 *   @0x2e240c ldr r2, [r4, #0x74]
 *   @0x2e2410 vldr s17, [r4, #128]
 *   @0x2e2414 add r10, r10, r10, lsl #1
 *   @0x2e2418 vldr s16, [r4, #132]
 *   @0x2e241c ldr r1, [r1, r3, lsl #2]
 *   @0x2e2420 lsl r10, r10, #2
 *   @0x2e2424 add r2, r2, r2, lsl #1
 *   @0x2e2428 add r3, lr, r10
 *   @0x2e242c vldr s20, [r3]
 *   @0x2e2430 vldr s19, [r3, #4]
 *   @0x2e2434 lsl r2, r2, #2
 *   @0x2e2438 ldr r11, [r3, #0x8]
 *   @0x2e243c add lr, lr, r2
 *   @0x2e2440 ldr r3, [r6, #0x1c]
 *   @0x2e2444 vldr s22, [lr]
 *   @0x2e2448 vldr s21, [lr, #4]
 *   @0x2e244c add r1, r1, #64
 *   @0x2e2450 add r2, r3, r2
 *   @0x2e2454 vldr s26, [r2]
 *   @0x2e2458 vldr s25, [r2, #4]
 *   @0x2e245c vldr s24, [r2, #8]
 *   @0x2e2460 ldr r2, [r6, #0x24]
 *   @0x2e2464 add r10, r3, r10
 *   @0x2e2468 mov r0, r11
 *   @0x2e246c vldr s28, [r10]
 *   @0x2e2470 add r12, r2, r7
 *   @0x2e2474 vldr s27, [r10, #4]
 *   @0x2e2478 vldr s3, [r12, #48]
 *   @0x2e247c vldr s4, [r12, #52]
 *   @0x2e2480 ldr r3, [r12, #0x4c]
 *   @0x2e2484 vldr s8, [r12, #56]
 *   @0x2e2488 ldr r2, [r12, #0x50]
 *   @0x2e248c vstr s3, [sp, #44]
 *   @0x2e2490 vstr s4, [sp, #40]
 *   @0x2e2494 vldr s23, [r10, #8]
 *   @0x2e2498 ldr r10, [lr, #0x8]
 *   @0x2e249c vstr s8, [sp, #36]
 *   @0x2e24a0 vldr s10, [r12, #60]
 *   @0x2e24a4 str r1, [sp, #0xc]
 *   @0x2e24a8 vstr s10, [sp, #32]
 *   @0x2e24ac str r2, [sp, #0x10]
 *   @0x2e24b0 str r3, [sp, #0x14]
 *   @0x2e24b4 bl 0xb6580 <sinf@plt>
 *   @0x2e24b8 vmov s30, r0
 *   @0x2e24bc mov r0, r11
 *   @0x2e24c0 vstr s30, [sp, #72]
 *   @0x2e24c4 bl 0xb658c <cosf@plt>
 *   @0x2e24c8 vmov s31, r0
 *   @0x2e24cc mov r0, r10
 *   @0x2e24d0 vstr s31, [sp, #76]
 *   @0x2e24d4 bl 0xb6580 <sinf@plt>
 *   @0x2e24d8 str r0, [sp, #0x18]
 *   @0x2e24dc mov r0, r10
 *   @0x2e24e0 vldr s11, [sp, #24]
 *   @0x2e24e4 vstr s11, [sp, #88]
 *   @0x2e24e8 bl 0xb658c <cosf@plt>
 *   @0x2e24ec vldr s14, [sp, #40]
 *   @0x2e24f0 vldr s3, [sp, #32]
 *   @0x2e24f4 vldr s4, [sp, #24]
 *   @0x2e24f8 vmul.f32 s12, s14, s30
 *   @0x2e24fc vldr s8, [sp, #44]
 *   @0x2e2500 vldr s10, [sp, #36]
 *   @0x2e2504 ldr r2, [sp, #0x10]
 *   @0x2e2508 ldr r1, [sp, #0xc]
 *   @0x2e250c ldr r3, [sp, #0x14]
 *   @0x2e2510 str r2, [sp, #0x4]
 *   @0x2e2514 add r2, sp, #80
 *   @0x2e2518 str r2, [sp]
 *   @0x2e251c add r2, sp, #64
 *   @0x2e2520 vmul.f32 s13, s14, s31
 *   @0x2e2524 vmul.f32 s14, s3, s4
 *   @0x2e2528 vmov s11, r0
 *   @0x2e252c add r0, sp, #96
 *   @0x2e2530 vstr s11, [sp, #92]
 *   @0x2e2534 vmul.f32 s15, s3, s11
 *   @0x2e2538 vnmls.f32 s12, s8, s31
 *   @0x2e253c vmla.f32 s13, s8, s30
 *   @0x2e2540 vnmls.f32 s14, s10, s11
 *   @0x2e2544 vmla.f32 s15, s10, s4
 *   @0x2e2548 vsub.f32 s12, s20, s12
 *   @0x2e254c vsub.f32 s13, s19, s13
 *   @0x2e2550 vstr s12, [sp, #64]
 *   @0x2e2554 vsub.f32 s14, s22, s14
 *   @0x2e2558 vstr s13, [sp, #68]
 *   @0x2e255c vsub.f32 s15, s21, s15
 *   @0x2e2560 vstr s14, [sp, #80]
 *   @0x2e2564 vstr s15, [sp, #84]
 *   @0x2e2568 bl 0x2c32c8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f>
 *   @0x2e256c ldr r2, [sp, #0x1c]
 *   @0x2e2570 add r3, r4, #72
 *   @0x2e2574 ldr r12, [r4, #0x94]
 *   @0x2e2578 ldm r2, {r0, r1}
 *   @0x2e257c cmp r12, #0
 *   @0x2e2580 stm r3, {r0, r1}
 *   @0x2e2584 ble 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328>
 *   @0x2e2588 vldr s3, [sp, #48]
 *   @0x2e258c vldr s4, [sp, #52]
 *   @0x2e2590 vadd.f32 s7, s3, s4
 *   @0x2e2594 add r2, sp, #104
 *   @0x2e2598 add r1, r4, #4
 *   @0x2e259c add r3, r4, #32
 *   @0x2e25a0 mov r0, #0
 *   @0x2e25a4 vneg.f32 s5, s24
 *   @0x2e25a8 vneg.f32 s6, s23
 *   @0x2e25ac vldr s12, [r2]
 *   @0x2e25b0 vldr s13, [r2, #4]
 *   @0x2e25b4 add r0, r0, #1
 *   @0x2e25b8 add r2, r2, #8
 *   @0x2e25bc vsub.f32 s12, s12, s20
 *   @0x2e25c0 add r1, r1, #36
 *   @0x2e25c4 add r3, r3, #36
 *   @0x2e25c8 vsub.f32 s13, s13, s19
 *   @0x2e25cc vstr s12, [r3, #-68]
 *   @0x2e25d0 vstr s13, [r1, #-36]
 *   @0x2e25d4 vldr s10, [r2, #-8]
 *   @0x2e25d8 vldr s11, [r2, #-4]
 *   @0x2e25dc vsub.f32 s10, s10, s22
 *   @0x2e25e0 vsub.f32 s11, s11, s21
 *   @0x2e25e4 vstr s10, [r1, #-32]
 *   @0x2e25e8 vstr s11, [r1, #-28]
 *   @0x2e25ec vldr s14, [r4, #72]
 *   @0x2e25f0 vmul.f32 s8, s13, s14
 *   @0x2e25f4 vldr s15, [r4, #76]
 *   @0x2e25f8 str r5, [r3, #-0x24]
 *   @0x2e25fc vnmls.f32 s8, s12, s15
 *   @0x2e2600 vmul.f32 s9, s11, s14
 *   @0x2e2604 vmul.f32 s4, s17, s8
 *   @0x2e2608 vnmls.f32 s9, s10, s15
 *   @0x2e260c vmov.f32 s3, s7
 *   @0x2e2610 vmla.f32 s3, s4, s8
 *   @0x2e2614 vmul.f32 s4, s16, s9
 *   @0x2e2618 vmov.f32 s8, s3
 *   @0x2e261c vmla.f32 s8, s4, s9
 *   @0x2e2620 vcmpe.f32 s8, #0
 *   @0x2e2624 vmrs APSR_nzcv, fpscr
 *   @0x2e2628 vdivgt.f32 s8, s18, s8
 *   @0x2e262c vldrle s8, [pc, #408]
 *   @0x2e2630 vstr s8, [r3, #-44]
 *   @0x2e2634 vmul.f32 s8, s13, s15
 *   @0x2e2638 vneg.f32 s4, s14
 *   @0x2e263c vnmls.f32 s8, s12, s4
 *   @0x2e2640 vmul.f32 s9, s11, s15
 *   @0x2e2644 vmul.f32 s3, s17, s8
 *   @0x2e2648 vnmls.f32 s9, s10, s4
 *   @0x2e264c vmov.f32 s4, s7
 *   @0x2e2650 vmla.f32 s4, s3, s8
 *   @0x2e2654 vmov.f32 s8, s4
 *   @0x2e2658 vmul.f32 s4, s16, s9
 *   @0x2e265c vmla.f32 s8, s4, s9
 *   @0x2e2660 vmov.f32 s9, s25
 *   @0x2e2664 vmla.f32 s9, s24, s10
 *   @0x2e2668 vmov.f32 s10, s26
 *   @0x2e266c vmla.f32 s10, s11, s5
 *   @0x2e2670 vsub.f32 s11, s9, s27
 *   @0x2e2674 vmls.f32 s11, s23, s12
 *   @0x2e2678 vsub.f32 s12, s10, s28
 *   @0x2e267c vmls.f32 s12, s13, s6
 *   @0x2e2680 vcmpe.f32 s8, #0
 *   @0x2e2684 vmul.f32 s15, s15, s11
 *   @0x2e2688 vmrs APSR_nzcv, fpscr
 *   @0x2e268c vldrle s8, [pc, #312]
 *   @0x2e2690 vdivgt.f32 s8, s18, s8
 *   @0x2e2694 vmla.f32 s15, s14, s12
 *   @0x2e2698 vstr s8, [r3, #-40]
 *   @0x2e269c vcmpe.f32 s15, s29
 *   @0x2e26a0 vmrs APSR_nzcv, fpscr
 *   @0x2e26a4 vldrmi s14, [r4, #140]
 *   @0x2e26a8 vnmulmi.f32 s15, s14, s15
 *   @0x2e26ac vstrmi s15, [r3, #-36]
 *   @0x2e26b0 cmp r0, r12
 *   @0x2e26b4 bne 0x2e25ac <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x214>
 *   @0x2e26b8 cmp r0, #2
 *   @0x2e26bc beq 0x2e26e4 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x34c>
 *   @0x2e26c0 ldr r3, [r6, #0x30]
 *   @0x2e26c4 add r8, r8, #1
 *   @0x2e26c8 add r9, r9, #156
 *   @0x2e26cc add r7, r7, #88
 *   @0x2e26d0 cmp r3, r8
 *   @0x2e26d4 bgt 0x2e23e4 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x4c>
 *   @0x2e26d8 add sp, sp, #124
 *   @0x2e26dc vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2e26e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e26e4 vldr s14, [r4, #72]
 *   @0x2e26e8 vldr s11, [r4, #4]
 *   @0x2e26ec vmul.f32 s11, s14, s11
 *   @0x2e26f0 vldr s13, [r4, #40]
 *   @0x2e26f4 vldr s15, [r4, #76]
 *   @0x2e26f8 vldr s5, [r4]
 *   @0x2e26fc vldr s6, [r4, #36]
 *   @0x2e2700 vldr s12, [r4, #12]
 *   @0x2e2704 vldr s9, [r4, #48]
 *   @0x2e2708 vldr s8, [r4, #8]
 *   @0x2e270c vldr s10, [r4, #44]
 *   @0x2e2710 mov r2, #0
 *   @0x2e2714 movt r2, #0x447a
 *   @0x2e2718 vmov s3, r2
 *   @0x2e271c vmul.f32 s13, s14, s13
 *   @0x2e2720 vnmls.f32 s11, s15, s5
 *   @0x2e2724 vnmls.f32 s13, s15, s6
 *   @0x2e2728 vmul.f32 s12, s14, s12
 *   @0x2e272c vmul.f32 s14, s14, s9
 *   @0x2e2730 vnmls.f32 s12, s15, s8
 *   @0x2e2734 vmul.f32 s9, s17, s11
 *   @0x2e2738 vnmls.f32 s14, s15, s10
 *   @0x2e273c vmul.f32 s17, s17, s13
 *   @0x2e2740 vmov.f32 s15, s7
 *   @0x2e2744 vmla.f32 s15, s9, s13
 *   @0x2e2748 vmov.f32 s8, s7
 *   @0x2e274c vmla.f32 s8, s17, s13
 *   @0x2e2750 vmul.f32 s10, s16, s12
 *   @0x2e2754 vmla.f32 s7, s9, s11
 *   @0x2e2758 vmul.f32 s16, s16, s14
 *   @0x2e275c vmla.f32 s15, s10, s14
 *   @0x2e2760 vmov.f32 s13, s8
 *   @0x2e2764 vmla.f32 s7, s10, s12
 *   @0x2e2768 vmla.f32 s13, s16, s14
 *   @0x2e276c vmul.f32 s14, s15, s15
 *   @0x2e2770 vnmls.f32 s14, s7, s13
 *   @0x2e2774 vmul.f32 s11, s7, s7
 *   @0x2e2778 vmul.f32 s12, s14, s3
 *   @0x2e277c vcmpe.f32 s11, s12
 *   @0x2e2780 vmrs APSR_nzcv, fpscr
 *   @0x2e2784 movpl r2, #1
 *   @0x2e2788 strpl r2, [r4, #0x94]
 *   @0x2e278c bpl 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328>
 *   @0x2e2790 vcmp.f32 s14, #0
 *   @0x2e2794 vstr s15, [r4, #100]
 *   @0x2e2798 vstr s15, [r4, #104]
 *   @0x2e279c vstr s13, [r4, #108]
 *   @0x2e27a0 vstr s7, [r4, #96]
 *   @0x2e27a4 vmrs APSR_nzcv, fpscr
 *   @0x2e27a8 vdivne.f32 s14, s18, s14
 *   @0x2e27ac vnmul.f32 s15, s14, s15
 *   @0x2e27b0 vmul.f32 s13, s13, s14
 *   @0x2e27b4 vstr s15, [r4, #84]
 *   @0x2e27b8 vstr s15, [r4, #88]
 *   @0x2e27bc vmul.f32 s14, s7, s14
 *   @0x2e27c0 vstr s13, [r4, #80]
 *   @0x2e27c4 vstr s14, [r4, #92]
 *   @0x2e27c8 b 0x2e26c0 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x328>
 *   @0x2e27cc andeq r0, r0, r0
 *
 * ══ §3/31 spBone_updateWorldTransformWith  0x284f18  size 1072  268 条（0x284f18..0x285348）
 * @func 0x284f18 0x285348  size 1072  268 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb67e4×4 / 0xb67d8×4
 * 字段偏移 top8: 0x8×3 / 0x2c×2 / 0x30×2 / 0x4×2 / 0x50×2 / 0x54×2 / 0x180×1 / 0x-14×1
 * VFP 指令 203 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x284f18 push {r3, r4, r5, lr}
 *   @0x284f1c vpush {d8, d9, d10, d11, d12, d13, d14}
 *   @0x284f20 vmov s21, r3
 *   @0x284f24 vldr s18, [sp, #80]
 *   @0x284f28 vldr s27, [pc, #896]
 *   @0x284f2c vldr s16, [pc, #896]
 *   @0x284f30 vadd.f32 s18, s21, s18
 *   @0x284f34 mov r5, r0
 *   @0x284f38 vmov s29, r1
 *   @0x284f3c vldr s17, [sp, #84]
 *   @0x284f40 vmov s28, r2
 *   @0x284f44 vldr s26, [sp, #72]
 *   @0x284f48 vldr s25, [sp, #76]
 *   @0x284f4c vmul.f32 s18, s18, s27
 *   @0x284f50 vcvt.f64.f32 d9, s18
 *   @0x284f54 vadd.f32 s16, s21, s16
 *   @0x284f58 vmov r0, r1, d9
 *   @0x284f5c bl 0xb67e4 <cos@plt>
 *   @0x284f60 vadd.f32 s16, s16, s17
 *   @0x284f64 vmul.f32 s16, s16, s27
 *   @0x284f68 vcvt.f64.f32 d8, s16
 *   @0x284f6c vmov d6, r0, r1
 *   @0x284f70 vmov r0, r1, d8
 *   @0x284f74 vcvt.f32.f64 s20, d6
 *   @0x284f78 bl 0xb67e4 <cos@plt>
 *   @0x284f7c vmul.f32 s20, s20, s26
 *   @0x284f80 vmov d7, r0, r1
 *   @0x284f84 vmov r0, r1, d9
 *   @0x284f88 vcvt.f32.f64 s22, d7
 *   @0x284f8c bl 0xb67d8 <sin@plt>
 *   @0x284f90 vmul.f32 s22, s22, s25
 *   @0x284f94 vmov d6, r0, r1
 *   @0x284f98 vmov r0, r1, d8
 *   @0x284f9c vcvt.f32.f64 s24, d6
 *   @0x284fa0 bl 0xb67d8 <sin@plt>
 *   @0x284fa4 ldr r4, [r5, #0x8]
 *   @0x284fa8 vstr s21, [r5, #48]
 *   @0x284fac cmp r4, #0
 *   @0x284fb0 vmul.f32 s24, s24, s26
 *   @0x284fb4 vmov d7, r0, r1
 *   @0x284fb8 vcvt.f32.f64 s23, d7
 *   @0x284fbc vmul.f32 s23, s23, s25
 *   @0x284fc0 beq 0x2852c4 <spBone_updateWorldTransformWith+0x3ac>
 *   @0x284fc4 vldr s10, [r4, #56]
 *   @0x284fc8 vldr s11, [r4, #68]
 *   @0x284fcc vldr s12, [r4, #52]
 *   @0x284fd0 vldr s13, [r4, #64]
 *   @0x284fd4 vldr s9, [r4, #60]
 *   @0x284fd8 ldr r3, [r5]
 *   @0x284fdc ldr r2, [r3, #0x2c]
 *   @0x284fe0 ldr r3, [r3, #0x30]
 *   @0x284fe4 vmul.f32 s14, s10, s28
 *   @0x284fe8 vmul.f32 s15, s11, s28
 *   @0x284fec vmla.f32 s14, s12, s29
 *   @0x284ff0 vmla.f32 s15, s13, s29
 *   @0x284ff4 vadd.f32 s14, s14, s9
 *   @0x284ff8 vmov.f32 s19, #1.000000e+00
 *   @0x284ffc vstr s14, [r5, #60]
 *   @0x285000 vldr s9, [r4, #72]
 *   @0x285004 vmov.f32 s14, #-1.000000e+00
 *   @0x285008 vadd.f32 s15, s15, s9
 *   @0x28500c vcmpe.f32 s26, #0
 *   @0x285010 vstr s15, [r5, #72]
 *   @0x285014 vldr s9, [r4, #76]
 *   @0x285018 vmrs APSR_nzcv, fpscr
 *   @0x28501c vmovle.f32 s15, s14
 *   @0x285020 vmovgt.f32 s15, s19
 *   @0x285024 vmul.f32 s15, s9, s15
 *   @0x285028 vcmpe.f32 s25, #0
 *   @0x28502c vstr s15, [r5, #76]
 *   @0x285030 vldr s15, [r4, #80]
 *   @0x285034 vmrs APSR_nzcv, fpscr
 *   @0x285038 vmovgt.f32 s14, s19
 *   @0x28503c cmp r2, #0
 *   @0x285040 vmul.f32 s14, s15, s14
 *   @0x285044 vstr s14, [r5, #80]
 *   @0x285048 beq 0x28516c <spBone_updateWorldTransformWith+0x254>
 *   @0x28504c cmp r3, #0
 *   @0x285050 bne 0x285278 <spBone_updateWorldTransformWith+0x360>
 *   @0x285054 vldr s25, [pc, #604]
 *   @0x285058 vmov.f32 s26, s19
 *   @0x28505c vmov.f32 s21, s25
 *   @0x285060 b 0x285070 <spBone_updateWorldTransformWith+0x158>
 *   @0x285064 ldr r4, [r4, #0x8]
 *   @0x285068 cmp r4, #0
 *   @0x28506c beq 0x2850dc <spBone_updateWorldTransformWith+0x1c4>
 *   @0x285070 vldr s16, [r4, #48]
 *   @0x285074 vmul.f32 s16, s16, s27
 *   @0x285078 vcvt.f64.f32 d8, s16
 *   @0x28507c vmov r0, r1, d8
 *   @0x285080 bl 0xb67e4 <cos@plt>
 *   @0x285084 vmov d6, r0, r1
 *   @0x285088 vmov r0, r1, d8
 *   @0x28508c vcvt.f32.f64 s18, d6
 *   @0x285090 bl 0xb67d8 <sin@plt>
 *   @0x285094 ldr r3, [r4]
 *   @0x285098 ldr r3, [r3, #0x2c]
 *   @0x28509c cmp r3, #0
 *   @0x2850a0 vmov d6, r0, r1
 *   @0x2850a4 vcvt.f32.f64 s15, d6
 *   @0x2850a8 vmul.f32 s13, s21, s15
 *   @0x2850ac vmul.f32 s12, s26, s15
 *   @0x2850b0 vmul.f32 s14, s19, s15
 *   @0x2850b4 vmul.f32 s15, s25, s15
 *   @0x2850b8 vmla.f32 s13, s26, s18
 *   @0x2850bc vnmls.f32 s12, s21, s18
 *   @0x2850c0 vmla.f32 s14, s25, s18
 *   @0x2850c4 vnmls.f32 s15, s19, s18
 *   @0x2850c8 vmov.f32 s26, s13
 *   @0x2850cc vmov.f32 s21, s12
 *   @0x2850d0 vmov.f32 s25, s14
 *   @0x2850d4 vmov.f32 s19, s15
 *   @0x2850d8 bne 0x285064 <spBone_updateWorldTransformWith+0x14c>
 *   @0x2850dc vmul.f32 s15, s24, s21
 *   @0x2850e0 vmul.f32 s24, s24, s19
 *   @0x2850e4 vmul.f32 s21, s23, s21
 *   @0x2850e8 vmul.f32 s19, s23, s19
 *   @0x2850ec vmla.f32 s15, s20, s13
 *   @0x2850f0 vmla.f32 s21, s22, s13
 *   @0x2850f4 vstr s15, [r5, #52]
 *   @0x2850f8 vmla.f32 s24, s20, s14
 *   @0x2850fc vstr s21, [r5, #56]
 *   @0x285100 vmla.f32 s19, s22, s14
 *   @0x285104 vstr s24, [r5, #64]
 *   @0x285108 vstr s19, [r5, #68]
 *   @0x28510c ldr r3, [r5, #0x4]
 *   @0x285110 ldr r2, [r3, #0x50]
 *   @0x285114 cmp r2, #0
 *   @0x285118 beq 0x285134 <spBone_updateWorldTransformWith+0x21c>
 *   @0x28511c vldr s14, [r5, #52]
 *   @0x285120 vldr s15, [r5, #56]
 *   @0x285124 vneg.f32 s14, s14
 *   @0x285128 vneg.f32 s15, s15
 *   @0x28512c vstr s14, [r5, #52]
 *   @0x285130 vstr s15, [r5, #56]
 *   @0x285134 ldr r1, [pc, #0x180]
 *   @0x285138 ldr r2, [r3, #0x54]
 *   @0x28513c add r1, pc, r1
 *   @0x285140 ldr r3, [r1]
 *   @0x285144 cmp r2, r3
 *   @0x285148 beq 0x285164 <spBone_updateWorldTransformWith+0x24c>
 *   @0x28514c vldr s14, [r5, #64]
 *   @0x285150 vldr s15, [r5, #68]
 *   @0x285154 vneg.f32 s14, s14
 *   @0x285158 vneg.f32 s15, s15
 *   @0x28515c vstr s14, [r5, #64]
 *   @0x285160 vstr s15, [r5, #68]
 *   @0x285164 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x285168 pop {r3, r4, r5, pc}
 *   @0x28516c cmp r3, #0
 *   @0x285170 beq 0x285264 <spBone_updateWorldTransformWith+0x34c>
 *   @0x285174 vldr s21, [pc, #316]
 *   @0x285178 vmov.f32 s25, s19
 *   @0x28517c vmov.f32 s26, s21
 *   @0x285180 b 0x285190 <spBone_updateWorldTransformWith+0x278>
 *   @0x285184 ldr r4, [r4, #0x8]
 *   @0x285188 cmp r4, #0
 *   @0x28518c beq 0x285230 <spBone_updateWorldTransformWith+0x318>
 *   @0x285190 vldr s16, [r4, #48]
 *   @0x285194 vmul.f32 s16, s16, s27
 *   @0x285198 vldr s28, [r4, #32]
 *   @0x28519c vldr s29, [r4, #36]
 *   @0x2851a0 vcvt.f64.f32 d8, s16
 *   @0x2851a4 vmov r0, r1, d8
 *   @0x2851a8 bl 0xb67e4 <cos@plt>
 *   @0x2851ac vmov d7, r0, r1
 *   @0x2851b0 vmov r0, r1, d8
 *   @0x2851b4 vcvt.f32.f64 s18, d7
 *   @0x2851b8 bl 0xb67d8 <sin@plt>
 *   @0x2851bc ldr r3, [r4]
 *   @0x2851c0 ldr r3, [r3, #0x30]
 *   @0x2851c4 vmul.f32 s9, s18, s29
 *   @0x2851c8 vmul.f32 s10, s18, s28
 *   @0x2851cc vcmpe.f32 s28, #0
 *   @0x2851d0 vmov d6, r0, r1
 *   @0x2851d4 vcvt.f32.f64 s15, d6
 *   @0x2851d8 vmrs APSR_nzcv, fpscr
 *   @0x2851dc vmul.f32 s14, s15, s29
 *   @0x2851e0 vmul.f32 s13, s15, s28
 *   @0x2851e4 vmul.f32 s12, s25, s14
 *   @0x2851e8 vmul.f32 s11, s26, s13
 *   @0x2851ec vmul.f32 s14, s21, s14
 *   @0x2851f0 vmul.f32 s13, s19, s13
 *   @0x2851f4 vnmls.f32 s12, s26, s9
 *   @0x2851f8 vnmls.f32 s14, s19, s9
 *   @0x2851fc vmla.f32 s11, s25, s10
 *   @0x285200 vmla.f32 s13, s21, s10
 *   @0x285204 vnegge.f32 s15, s15
 *   @0x285208 cmp r3, #0
 *   @0x28520c vmul.f32 s25, s12, s15
 *   @0x285210 vmul.f32 s26, s15, s11
 *   @0x285214 vmul.f32 s21, s14, s15
 *   @0x285218 vmul.f32 s19, s15, s13
 *   @0x28521c vmla.f32 s25, s18, s11
 *   @0x285220 vnmls.f32 s26, s12, s18
 *   @0x285224 vmla.f32 s21, s18, s13
 *   @0x285228 vnmls.f32 s19, s14, s18
 *   @0x28522c bne 0x285184 <spBone_updateWorldTransformWith+0x26c>
 *   @0x285230 vmul.f32 s15, s24, s26
 *   @0x285234 vmul.f32 s24, s24, s19
 *   @0x285238 vmul.f32 s26, s23, s26
 *   @0x28523c vmul.f32 s19, s23, s19
 *   @0x285240 vmla.f32 s15, s20, s25
 *   @0x285244 vmla.f32 s26, s22, s25
 *   @0x285248 vstr s15, [r5, #52]
 *   @0x28524c vmla.f32 s24, s20, s21
 *   @0x285250 vstr s26, [r5, #56]
 *   @0x285254 vmla.f32 s19, s22, s21
 *   @0x285258 vstr s24, [r5, #64]
 *   @0x28525c vstr s19, [r5, #68]
 *   @0x285260 b 0x28510c <spBone_updateWorldTransformWith+0x1f4>
 *   @0x285264 vstr s20, [r5, #52]
 *   @0x285268 vstr s22, [r5, #56]
 *   @0x28526c vstr s24, [r5, #64]
 *   @0x285270 vstr s23, [r5, #68]
 *   @0x285274 b 0x28510c <spBone_updateWorldTransformWith+0x1f4>
 *   @0x285278 vmul.f32 s15, s10, s24
 *   @0x28527c vmul.f32 s24, s11, s24
 *   @0x285280 vmul.f32 s10, s10, s23
 *   @0x285284 vmul.f32 s11, s11, s23
 *   @0x285288 vmla.f32 s24, s13, s20
 *   @0x28528c vmla.f32 s15, s12, s20
 *   @0x285290 vstr s24, [r5, #64]
 *   @0x285294 vmla.f32 s10, s12, s22
 *   @0x285298 vstr s15, [r5, #52]
 *   @0x28529c vmla.f32 s11, s13, s22
 *   @0x2852a0 vstr s10, [r5, #56]
 *   @0x2852a4 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x2852a8 vstr s11, [r5, #68]
 *   @0x2852ac pop {r3, r4, r5, pc}
 *   @0x2852b0 vstmialo lr, {s30, s31}
 *   @0x2852b4 adcsmi r0, r4, #0
 *   @0x2852b8 andeq r0, r0, r0
 *   @0x2852bc subeq r1, sp, r12, ror r10
 *   @0x2852c0 subeq r1, sp, r4, ror #17
 *   @0x2852c4 ldr r3, [r5, #0x4]
 *   @0x2852c8 vmov.f32 s14, #1.000000e+00
 *   @0x2852cc ldr r1, [pc, #-0x14]
 *   @0x2852d0 ldr r2, [r3, #0x50]
 *   @0x2852d4 add r1, pc, r1
 *   @0x2852d8 cmp r2, #0
 *   @0x2852dc ldr r2, [r3, #0x54]
 *   @0x2852e0 ldr r3, [r1]
 *   @0x2852e4 vnegne.f32 s29, s29
 *   @0x2852e8 vnegne.f32 s20, s20
 *   @0x2852ec vstr s29, [r5, #60]
 *   @0x2852f0 vnegne.f32 s22, s22
 *   @0x2852f4 cmp r2, r3
 *   @0x2852f8 vstr s20, [r5, #52]
 *   @0x2852fc vmov.f32 s15, #-1.000000e+00
 *   @0x285300 vstr s22, [r5, #56]
 *   @0x285304 vnegne.f32 s28, s28
 *   @0x285308 vnegne.f32 s24, s24
 *   @0x28530c vstr s28, [r5, #72]
 *   @0x285310 vnegne.f32 s23, s23
 *   @0x285314 vstr s24, [r5, #64]
 *   @0x285318 vcmpe.f32 s26, #0
 *   @0x28531c vstr s23, [r5, #68]
 *   @0x285320 vmrs APSR_nzcv, fpscr
 *   @0x285324 vcmpe.f32 s25, #0
 *   @0x285328 vpop {d8, d9, d10, d11, d12, d13, d14}
 *   @0x28532c vmovle.f32 s13, s15
 *   @0x285330 vmovgt.f32 s13, s14
 *   @0x285334 vmrs APSR_nzcv, fpscr
 *   @0x285338 vstr s13, [r5, #76]
 *   @0x28533c vmovgt.f32 s15, s14
 *   @0x285340 vstr s15, [r5, #80]
 *   @0x285344 pop {r3, r4, r5, pc}
 *
 * ══ §4/31 GlobalState_DeSerialise  0x1d039c  size 1068  267 条（0x1d039c..0x1d07c8）
 * @func 0x1d039c 0x1d07c8  size 1068  267 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: YYGetInt32(RValue const*, int)×9 / YYGetBool(RValue const*, int)×5 / IBuffer::ReadString()×3 / operator new(unsigned int)×3 / 0xb6538×3 / YYStrDup(char const*)×3
 * 字段偏移 top8: 0xc×15 / 0x8×3 / 0x4×3 / 0x3c0×1 / 0x3a8×1 / 0x364×1 / 0x338×1 / 0x30c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d039c push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x1d03a0 add r7, r0, #44
 *   @0x1d03a4 ldr r3, [r0]
 *   @0x1d03a8 mov r1, #6
 *   @0x1d03ac mov r2, r7
 *   @0x1d03b0 mov r6, r0
 *   @0x1d03b4 ldr r8, [pc, #0x3c0]
 *   @0x1d03b8 ldr r3, [r3, #0xc]
 *   @0x1d03bc blx r3
 *   @0x1d03c0 mov r0, r7
 *   @0x1d03c4 mov r1, #0
 *   @0x1d03c8 add r8, pc, r8
 *   @0x1d03cc bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d03d0 ldr r3, [pc, #0x3a8]
 *   @0x1d03d4 movw r2, #0x353
 *   @0x1d03d8 add r3, pc, r3
 *   @0x1d03dc cmp r0, r2
 *   @0x1d03e0 str r0, [r3]
 *   @0x1d03e4 movne r3, #0
 *   @0x1d03e8 beq 0x1d03f4 <_Z23GlobalState_DeSerialiseP7IBuffer+0x58>
 *   @0x1d03ec mov r0, r3
 *   @0x1d03f0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1d03f4 ldr r3, [r6]
 *   @0x1d03f8 mov r2, r7
 *   @0x1d03fc mov r1, #6
 *   @0x1d0400 mov r0, r6
 *   @0x1d0404 ldr r3, [r3, #0xc]
 *   @0x1d0408 blx r3
 *   @0x1d040c mov r1, #0
 *   @0x1d0410 mov r0, r7
 *   @0x1d0414 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d0418 ldr r12, [pc, #0x364]
 *   @0x1d041c ldr r3, [r6]
 *   @0x1d0420 mov r2, r7
 *   @0x1d0424 mov r1, #6
 *   @0x1d0428 ldr r12, [r8, r12]
 *   @0x1d042c ldr r3, [r3, #0xc]
 *   @0x1d0430 str r0, [r12]
 *   @0x1d0434 mov r0, r6
 *   @0x1d0438 blx r3
 *   @0x1d043c mov r1, #0
 *   @0x1d0440 mov r0, r7
 *   @0x1d0444 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d0448 ldr r12, [pc, #0x338]
 *   @0x1d044c ldr r3, [r6]
 *   @0x1d0450 mov r2, r7
 *   @0x1d0454 mov r1, #6
 *   @0x1d0458 ldr r12, [r8, r12]
 *   @0x1d045c ldr r3, [r3, #0xc]
 *   @0x1d0460 str r0, [r12]
 *   @0x1d0464 mov r0, r6
 *   @0x1d0468 blx r3
 *   @0x1d046c mov r1, #0
 *   @0x1d0470 mov r0, r7
 *   @0x1d0474 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d0478 ldr r12, [pc, #0x30c]
 *   @0x1d047c ldr r3, [r6]
 *   @0x1d0480 mov r2, r7
 *   @0x1d0484 mov r1, #6
 *   @0x1d0488 ldr r12, [r8, r12]
 *   @0x1d048c ldr r3, [r3, #0xc]
 *   @0x1d0490 str r0, [r12]
 *   @0x1d0494 mov r0, r6
 *   @0x1d0498 blx r3
 *   @0x1d049c mov r1, #0
 *   @0x1d04a0 mov r0, r7
 *   @0x1d04a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d04a8 ldr r12, [pc, #0x2e0]
 *   @0x1d04ac ldr r3, [r6]
 *   @0x1d04b0 mov r2, r7
 *   @0x1d04b4 mov r1, #6
 *   @0x1d04b8 ldr r12, [r8, r12]
 *   @0x1d04bc ldr r3, [r3, #0xc]
 *   @0x1d04c0 str r0, [r12]
 *   @0x1d04c4 mov r0, r6
 *   @0x1d04c8 blx r3
 *   @0x1d04cc mov r1, #0
 *   @0x1d04d0 mov r0, r7
 *   @0x1d04d4 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d04d8 ldr r12, [pc, #0x2b4]
 *   @0x1d04dc ldr r3, [r6]
 *   @0x1d04e0 mov r2, r7
 *   @0x1d04e4 mov r1, #6
 *   @0x1d04e8 ldr r12, [r8, r12]
 *   @0x1d04ec ldr r3, [r3, #0xc]
 *   @0x1d04f0 str r0, [r12]
 *   @0x1d04f4 mov r0, r6
 *   @0x1d04f8 blx r3
 *   @0x1d04fc mov r1, #0
 *   @0x1d0500 mov r0, r7
 *   @0x1d0504 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d0508 ldr r12, [pc, #0x288]
 *   @0x1d050c ldr r3, [r6]
 *   @0x1d0510 mov r2, r7
 *   @0x1d0514 mov r1, #6
 *   @0x1d0518 ldr r12, [r8, r12]
 *   @0x1d051c ldr r3, [r3, #0xc]
 *   @0x1d0520 strb r0, [r12]
 *   @0x1d0524 mov r0, r6
 *   @0x1d0528 blx r3
 *   @0x1d052c mov r1, #0
 *   @0x1d0530 mov r0, r7
 *   @0x1d0534 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d0538 ldr r3, [pc, #0x25c]
 *   @0x1d053c ldr r3, [r8, r3]
 *   @0x1d0540 strb r0, [r3]
 *   @0x1d0544 mov r0, r6
 *   @0x1d0548 bl 0xcde74 <_ZN7IBuffer10ReadStringEv>
 *   @0x1d054c mov r5, r0
 *   @0x1d0550 mov r0, #12
 *   @0x1d0554 bl 0x27c524 <_Znwj>
 *   @0x1d0558 mov r4, r0
 *   @0x1d055c subs r0, r5, #0
 *   @0x1d0560 beq 0x1d0568 <_Z23GlobalState_DeSerialiseP7IBuffer+0x1cc>
 *   @0x1d0564 bl 0xb6538 <strlen@plt>
 *   @0x1d0568 str r0, [r4, #0x8]
 *   @0x1d056c mov r0, r5
 *   @0x1d0570 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1d0574 ldr r12, [pc, #0x224]
 *   @0x1d0578 ldr r3, [r6]
 *   @0x1d057c mov r2, #1
 *   @0x1d0580 str r2, [r4, #0x4]
 *   @0x1d0584 mov r5, #0
 *   @0x1d0588 mov r2, r7
 *   @0x1d058c mov r1, #6
 *   @0x1d0590 str r0, [r4]
 *   @0x1d0594 mov r0, r6
 *   @0x1d0598 ldr r12, [r8, r12]
 *   @0x1d059c ldr r3, [r3, #0xc]
 *   @0x1d05a0 str r4, [r12]
 *   @0x1d05a4 blx r3
 *   @0x1d05a8 mov r1, r5
 *   @0x1d05ac mov r0, r7
 *   @0x1d05b0 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d05b4 ldr r12, [pc, #0x1e8]
 *   @0x1d05b8 ldr r3, [r6]
 *   @0x1d05bc mov r2, r7
 *   @0x1d05c0 mov r1, #6
 *   @0x1d05c4 ldr r12, [r8, r12]
 *   @0x1d05c8 ldr r3, [r3, #0xc]
 *   @0x1d05cc str r0, [r12]
 *   @0x1d05d0 mov r0, r6
 *   @0x1d05d4 blx r3
 *   @0x1d05d8 mov r1, r5
 *   @0x1d05dc mov r0, r7
 *   @0x1d05e0 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d05e4 ldr r3, [pc, #0x1bc]
 *   @0x1d05e8 ldr r3, [r8, r3]
 *   @0x1d05ec strb r0, [r3]
 *   @0x1d05f0 mov r0, r6
 *   @0x1d05f4 bl 0xcde74 <_ZN7IBuffer10ReadStringEv>
 *   @0x1d05f8 mov r5, r0
 *   @0x1d05fc mov r0, #12
 *   @0x1d0600 bl 0x27c524 <_Znwj>
 *   @0x1d0604 mov r4, r0
 *   @0x1d0608 subs r0, r5, #0
 *   @0x1d060c beq 0x1d0614 <_Z23GlobalState_DeSerialiseP7IBuffer+0x278>
 *   @0x1d0610 bl 0xb6538 <strlen@plt>
 *   @0x1d0614 str r0, [r4, #0x8]
 *   @0x1d0618 mov r0, r5
 *   @0x1d061c bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1d0620 ldr r12, [pc, #0x184]
 *   @0x1d0624 ldr r3, [r6]
 *   @0x1d0628 mov r2, #1
 *   @0x1d062c str r2, [r4, #0x4]
 *   @0x1d0630 mov r1, #9
 *   @0x1d0634 mov r2, r7
 *   @0x1d0638 str r0, [r4]
 *   @0x1d063c mov r0, r6
 *   @0x1d0640 ldr r12, [r8, r12]
 *   @0x1d0644 ldr r3, [r3, #0xc]
 *   @0x1d0648 str r4, [r12]
 *   @0x1d064c blx r3
 *   @0x1d0650 ldr r12, [pc, #0x158]
 *   @0x1d0654 ldr r4, [r6, #0x2c]
 *   @0x1d0658 mov r2, r7
 *   @0x1d065c ldr r3, [r6]
 *   @0x1d0660 mov r1, #6
 *   @0x1d0664 ldr r12, [r8, r12]
 *   @0x1d0668 mov r0, r6
 *   @0x1d066c ldr r5, [r6, #0x30]
 *   @0x1d0670 ldr r3, [r3, #0xc]
 *   @0x1d0674 strd r4, r5, [r12]
 *   @0x1d0678 blx r3
 *   @0x1d067c mov r1, #0
 *   @0x1d0680 mov r0, r7
 *   @0x1d0684 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d0688 ldr r3, [pc, #0x124]
 *   @0x1d068c ldr r3, [r8, r3]
 *   @0x1d0690 strb r0, [r3]
 *   @0x1d0694 mov r0, r6
 *   @0x1d0698 bl 0xcde74 <_ZN7IBuffer10ReadStringEv>
 *   @0x1d069c mov r5, r0
 *   @0x1d06a0 mov r0, #12
 *   @0x1d06a4 bl 0x27c524 <_Znwj>
 *   @0x1d06a8 mov r4, r0
 *   @0x1d06ac subs r0, r5, #0
 *   @0x1d06b0 beq 0x1d06b8 <_Z23GlobalState_DeSerialiseP7IBuffer+0x31c>
 *   @0x1d06b4 bl 0xb6538 <strlen@plt>
 *   @0x1d06b8 str r0, [r4, #0x8]
 *   @0x1d06bc mov r0, r5
 *   @0x1d06c0 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1d06c4 ldr r12, [pc, #0xec]
 *   @0x1d06c8 ldr r3, [r6]
 *   @0x1d06cc mov r9, #1
 *   @0x1d06d0 str r9, [r4, #0x4]
 *   @0x1d06d4 mov r5, #0
 *   @0x1d06d8 mov r2, r7
 *   @0x1d06dc mov r1, #6
 *   @0x1d06e0 str r0, [r4]
 *   @0x1d06e4 mov r0, r6
 *   @0x1d06e8 ldr r12, [r8, r12]
 *   @0x1d06ec ldr r3, [r3, #0xc]
 *   @0x1d06f0 str r4, [r12]
 *   @0x1d06f4 blx r3
 *   @0x1d06f8 mov r1, r5
 *   @0x1d06fc mov r0, r7
 *   @0x1d0700 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d0704 ldr r12, [pc, #0xb0]
 *   @0x1d0708 ldr r3, [r6]
 *   @0x1d070c mov r2, r7
 *   @0x1d0710 mov r1, #6
 *   @0x1d0714 ldr r12, [r8, r12]
 *   @0x1d0718 ldr r3, [r3, #0xc]
 *   @0x1d071c str r0, [r12]
 *   @0x1d0720 mov r0, r6
 *   @0x1d0724 blx r3
 *   @0x1d0728 mov r1, r5
 *   @0x1d072c mov r0, r7
 *   @0x1d0730 bl 0xce870 <_Z10YYGetInt32PK6RValuei>
 *   @0x1d0734 ldr r12, [pc, #0x84]
 *   @0x1d0738 ldr r3, [r6]
 *   @0x1d073c mov r2, r7
 *   @0x1d0740 mov r1, #6
 *   @0x1d0744 ldr r12, [r8, r12]
 *   @0x1d0748 ldr r3, [r3, #0xc]
 *   @0x1d074c str r0, [r12]
 *   @0x1d0750 mov r0, r6
 *   @0x1d0754 blx r3
 *   @0x1d0758 mov r0, r7
 *   @0x1d075c mov r1, r5
 *   @0x1d0760 bl 0xce768 <_Z9YYGetBoolPK6RValuei>
 *   @0x1d0764 ldr r2, [pc, #0x58]
 *   @0x1d0768 mov r3, r9
 *   @0x1d076c ldr r2, [r8, r2]
 *   @0x1d0770 strb r0, [r2]
 *   @0x1d0774 mov r0, r3
 *   @0x1d0778 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x1d077c eoreq r1, r2, r8, lsl #17
 *   @0x1d0780 eoreq r4, r2, r8, lsr sp
 *   @0x1d0784 .word 0xffffeec4
 *   @0x1d0788 .word 0xffffd784
 *   @0x1d078c .word 0xffffc154
 *   @0x1d0790 .word 0xffffc458
 *   @0x1d0794 .word 0xffffce34
 *   @0x1d0798 .word 0xffffd99c
 *   @0x1d079c .word 0xffffd998
 *   @0x1d07a0 .word 0xffffd9a0
 *   @0x1d07a4 .word 0xffffd780
 *   @0x1d07a8 .word 0xffffd9a4
 *   @0x1d07ac .word 0xffffd9a8
 *   @0x1d07b0 .word 0xffffd788
 *   @0x1d07b4 .word 0xffffd9ac
 *   @0x1d07b8 .word 0xffffd9b0
 *   @0x1d07bc .word 0xffffd798
 *   @0x1d07c0 .word 0xffffebf0
 *   @0x1d07c4 .word 0xffffc974
 *
 * ══ §5/31 CCamera::ApplyMatrices  0x16d3bc  size 1032  258 条（0x16d3bc..0x16d7c4）
 * @func 0x16d3bc 0x16d7c4  size 1032  258 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x16d3e0→0x3f23a0, 0x16d3e8→0x3f239c, 0x16d3ec→0x54298c, 0x16d41c→0x3f2398, 0x16d42c→0x3f2394, 0x16d434→0x3f2390, 0x16d45c→0x3f23b4, 0x16d658→0x3f2398
 * 调用序列: 0xb6700×3 / SetViewExtents(float, float, float, float, float)×2 / CCamera::IsOrthoProj() / yyMatrix::Multiply(yyMatrix*, yyMatrix*, yyMatrix*) / Graphics::SetMatrices(float*, float*, float*) / CCamera::GetCamPos() / CCamera::ApplyMatrices()+0x298 / CCamera::ApplyMatrices()+0x38c
 * 字段偏移 top8: 0x3bc×2 / 0x54×2 / 0xf8×2 / 0x3cc×1 / 0x3c0×1 / 0x390×1 / 0x384×1 / 0x380×1
 * VFP 指令 133 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16d3bc push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x16d3c0 vpush {d8, d9}
 *   @0x16d3c4 sub sp, sp, #140
 *   @0x16d3c8 mov r5, r0
 *   @0x16d3cc bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv>
 *   @0x16d3d0 ldr r4, [pc, #0x3cc]
 *   @0x16d3d4 add r4, pc, r4
 *   @0x16d3d8 cmp r0, #0
 *   @0x16d3dc bne 0x16d520 <_ZN7CCamera13ApplyMatricesEv+0x164>
 *   @0x16d3e0 ldr r0, [pc, #0x3c0]
 *   @0x16d3e4 mov r3, #0
 *   @0x16d3e8 ldr r1, [pc, #0x3bc]
 *   @0x16d3ec ldr r2, [pc, #0x3bc]
 *   @0x16d3f0 ldr r0, [r4, r0]
 *   @0x16d3f4 str r3, [r0]
 *   @0x16d3f8 ldr r1, [r4, r1]
 *   @0x16d3fc str r3, [r1]
 *   @0x16d400 ldr r3, [r4, r2]
 *   @0x16d404 ldr r3, [r3]
 *   @0x16d408 cmp r3, #0
 *   @0x16d40c beq 0x16d754 <_ZN7CCamera13ApplyMatricesEv+0x398>
 *   @0x16d410 vldr s14, [r3, #16]
 *   @0x16d414 vldr s15, [r3, #20]
 *   @0x16d418 vcvt.f32.s32 s14, s14
 *   @0x16d41c ldr r3, [pc, #0x390]
 *   @0x16d420 ldr r3, [r4, r3]
 *   @0x16d424 vcvt.f32.s32 s15, s15
 *   @0x16d428 vstr s14, [r3]
 *   @0x16d42c ldr r3, [pc, #0x384]
 *   @0x16d430 mov r1, #0
 *   @0x16d434 ldr r12, [pc, #0x380]
 *   @0x16d438 mov r0, r1
 *   @0x16d43c vmov r2, s14
 *   @0x16d440 ldr r3, [r4, r3]
 *   @0x16d444 vstr s15, [r3]
 *   @0x16d448 ldr r12, [r4, r12]
 *   @0x16d44c vmov r3, s15
 *   @0x16d450 str r1, [sp]
 *   @0x16d454 str r1, [r12]
 *   @0x16d458 bl 0x1692e4 <_Z14SetViewExtentsfffff>
 *   @0x16d45c ldr r3, [pc, #0x35c]
 *   @0x16d460 ldr r3, [r4, r3]
 *   @0x16d464 ldr r3, [r3]
 *   @0x16d468 cmn r3, #1
 *   @0x16d46c beq 0x16d4f0 <_ZN7CCamera13ApplyMatricesEv+0x134>
 *   @0x16d470 add r4, sp, #8
 *   @0x16d474 add r1, r5, #4
 *   @0x16d478 add r2, sp, #72
 *   @0x16d47c mov r3, #0
 *   @0x16d480 mov r0, r4
 *   @0x16d484 mov r12, #1065353216
 *   @0x16d488 mov lr, #0
 *   @0x16d48c str r3, [sp, #0x80]
 *   @0x16d490 movt lr, #0xbf80
 *   @0x16d494 str r3, [sp, #0x7c]
 *   @0x16d498 str r3, [sp, #0x78]
 *   @0x16d49c str r3, [sp, #0x74]
 *   @0x16d4a0 str r3, [sp, #0x6c]
 *   @0x16d4a4 str r3, [sp, #0x68]
 *   @0x16d4a8 str r3, [sp, #0x64]
 *   @0x16d4ac str r12, [sp, #0x84]
 *   @0x16d4b0 str r12, [sp, #0x70]
 *   @0x16d4b4 str r12, [sp, #0x48]
 *   @0x16d4b8 str r3, [sp, #0x60]
 *   @0x16d4bc str r3, [sp, #0x58]
 *   @0x16d4c0 str r3, [sp, #0x54]
 *   @0x16d4c4 str r3, [sp, #0x50]
 *   @0x16d4c8 str r3, [sp, #0x4c]
 *   @0x16d4cc str lr, [sp, #0x5c]
 *   @0x16d4d0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_>
 *   @0x16d4d4 add r1, r5, #68
 *   @0x16d4d8 mov r2, r4
 *   @0x16d4dc mov r0, #0
 *   @0x16d4e0 bl 0x17ec90 <_ZN8Graphics11SetMatricesEPfS0_S0_>
 *   @0x16d4e4 add sp, sp, #140
 *   @0x16d4e8 vpop {d8, d9}
 *   @0x16d4ec pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x16d4f0 add lr, r5, #4
 *   @0x16d4f4 add r4, sp, #8
 *   @0x16d4f8 ldm lr!, {r0, r1, r2, r3}
 *   @0x16d4fc mov r12, r4
 *   @0x16d500 stm r12!, {r0, r1, r2, r3}
 *   @0x16d504 ldm lr!, {r0, r1, r2, r3}
 *   @0x16d508 stm r12!, {r0, r1, r2, r3}
 *   @0x16d50c ldm lr!, {r0, r1, r2, r3}
 *   @0x16d510 stm r12!, {r0, r1, r2, r3}
 *   @0x16d514 ldm lr, {r0, r1, r2, r3}
 *   @0x16d518 stm r12, {r0, r1, r2, r3}
 *   @0x16d51c b 0x16d4d4 <_ZN7CCamera13ApplyMatricesEv+0x118>
 *   @0x16d520 add r0, sp, #72
 *   @0x16d524 mov r1, r5
 *   @0x16d528 bl 0x16d3a0 <_ZN7CCamera9GetCamPosEv>
 *   @0x16d52c vldr s15, [pc, #612]
 *   @0x16d530 vldr s6, [r5, #344]
 *   @0x16d534 vmul.f32 s1, s6, s15
 *   @0x16d538 vldr s9, [r5, #360]
 *   @0x16d53c vldr s2, [r5, #328]
 *   @0x16d540 vldr s5, [r5, #340]
 *   @0x16d544 vldr s8, [r5, #356]
 *   @0x16d548 vldr s3, [r5, #324]
 *   @0x16d54c vldr s12, [r5, #376]
 *   @0x16d550 vldr s7, [r5, #348]
 *   @0x16d554 vldr s10, [r5, #364]
 *   @0x16d558 vldr s11, [r5, #372]
 *   @0x16d55c vldr s4, [r5, #332]
 *   @0x16d560 vldr s13, [r5, #380]
 *   @0x16d564 vmul.f32 s9, s9, s15
 *   @0x16d568 vadd.f32 s18, s2, s1
 *   @0x16d56c vsub.f32 s14, s1, s2
 *   @0x16d570 vmul.f32 s1, s5, s15
 *   @0x16d574 vmul.f32 s8, s8, s15
 *   @0x16d578 vadd.f32 s18, s9, s18
 *   @0x16d57c vadd.f32 s14, s14, s9
 *   @0x16d580 vadd.f32 s17, s3, s1
 *   @0x16d584 vsub.f32 s0, s1, s3
 *   @0x16d588 vadd.f32 s18, s12, s18
 *   @0x16d58c vadd.f32 s14, s14, s12
 *   @0x16d590 vmul.f32 s16, s7, s15
 *   @0x16d594 vadd.f32 s17, s8, s17
 *   @0x16d598 vadd.f32 s0, s0, s8
 *   @0x16d59c vsub.f32 s14, s18, s14
 *   @0x16d5a0 vmul.f32 s10, s10, s15
 *   @0x16d5a4 vadd.f32 s17, s11, s17
 *   @0x16d5a8 vadd.f32 s0, s0, s11
 *   @0x16d5ac vadd.f32 s1, s4, s16
 *   @0x16d5b0 vsub.f32 s16, s16, s4
 *   @0x16d5b4 vmul.f32 s14, s14, s14
 *   @0x16d5b8 vsub.f32 s0, s17, s0
 *   @0x16d5bc vadd.f32 s1, s10, s1
 *   @0x16d5c0 vadd.f32 s16, s16, s10
 *   @0x16d5c4 vmla.f32 s14, s0, s0
 *   @0x16d5c8 vadd.f32 s1, s13, s1
 *   @0x16d5cc vadd.f32 s16, s16, s13
 *   @0x16d5d0 vmul.f32 s2, s2, s15
 *   @0x16d5d4 vmul.f32 s3, s3, s15
 *   @0x16d5d8 vmul.f32 s4, s4, s15
 *   @0x16d5dc vsub.f32 s1, s1, s16
 *   @0x16d5e0 vadd.f32 s17, s5, s3
 *   @0x16d5e4 vadd.f32 s18, s6, s2
 *   @0x16d5e8 vadd.f32 s19, s7, s4
 *   @0x16d5ec vsub.f32 s3, s3, s5
 *   @0x16d5f0 vsub.f32 s2, s2, s6
 *   @0x16d5f4 vsub.f32 s4, s4, s7
 *   @0x16d5f8 vmla.f32 s14, s1, s1
 *   @0x16d5fc vadd.f32 s17, s8, s17
 *   @0x16d600 vadd.f32 s18, s9, s18
 *   @0x16d604 vadd.f32 s19, s10, s19
 *   @0x16d608 vadd.f32 s8, s8, s3
 *   @0x16d60c vadd.f32 s9, s9, s2
 *   @0x16d610 vadd.f32 s10, s10, s4
 *   @0x16d614 vadd.f32 s17, s11, s17
 *   @0x16d618 vadd.f32 s18, s12, s18
 *   @0x16d61c vadd.f32 s19, s13, s19
 *   @0x16d620 vadd.f32 s11, s11, s8
 *   @0x16d624 vadd.f32 s12, s12, s9
 *   @0x16d628 vadd.f32 s13, s13, s10
 *   @0x16d62c vcmpe.f32 s14, s15
 *   @0x16d630 vsub.f32 s17, s17, s11
 *   @0x16d634 vmrs APSR_nzcv, fpscr
 *   @0x16d638 vsub.f32 s18, s18, s12
 *   @0x16d63c vsub.f32 s19, s19, s13
 *   @0x16d640 ble 0x16d654 <_ZN7CCamera13ApplyMatricesEv+0x298>
 *   @0x16d644 vsqrt.f32 s15, s14
 *   @0x16d648 vcmp.f32 s15, s15
 *   @0x16d64c vmrs APSR_nzcv, fpscr
 *   @0x16d650 bne 0x16d76c <_ZN7CCamera13ApplyMatricesEv+0x3b0>
 *   @0x16d654 vmul.f32 s16, s18, s18
 *   @0x16d658 ldr r3, [pc, #0x154]
 *   @0x16d65c ldr r6, [r4, r3]
 *   @0x16d660 vstr s15, [r6]
 *   @0x16d664 vmla.f32 s16, s17, s17
 *   @0x16d668 vmla.f32 s16, s19, s19
 *   @0x16d66c vcmpe.f32 s16, #0
 *   @0x16d670 vsqrt.f32 s19, s16
 *   @0x16d674 vmrs APSR_nzcv, fpscr
 *   @0x16d678 ble 0x16d748 <_ZN7CCamera13ApplyMatricesEv+0x38c>
 *   @0x16d67c vmov r0, s19
 *   @0x16d680 vcmp.f32 s19, s19
 *   @0x16d684 vmrs APSR_nzcv, fpscr
 *   @0x16d688 bne 0x16d78c <_ZN7CCamera13ApplyMatricesEv+0x3d0>
 *   @0x16d68c vmov.f32 s11, #5.000000e-01
 *   @0x16d690 vldr s15, [r6]
 *   @0x16d694 vmov s12, r0
 *   @0x16d698 vmul.f32 s11, s12, s11
 *   @0x16d69c ldr r1, [pc, #0x114]
 *   @0x16d6a0 vldr s13, [sp, #72]
 *   @0x16d6a4 vldr s10, [sp, #76]
 *   @0x16d6a8 ldr r2, [pc, #0xf8]
 *   @0x16d6ac ldr r3, [pc, #0xf8]
 *   @0x16d6b0 ldr r7, [r4, r1]
 *   @0x16d6b4 vstr s12, [r7]
 *   @0x16d6b8 ldr r9, [r4, r2]
 *   @0x16d6bc vmov.f32 s12, #5.000000e-01
 *   @0x16d6c0 vmls.f32 s13, s15, s12
 *   @0x16d6c4 vsub.f32 s11, s10, s11
 *   @0x16d6c8 vstr s13, [r9]
 *   @0x16d6cc ldr r8, [r4, r3]
 *   @0x16d6d0 vcmp.f32 s19, s19
 *   @0x16d6d4 vstr s11, [r8]
 *   @0x16d6d8 vmov.f32 s14, s19
 *   @0x16d6dc vmrs APSR_nzcv, fpscr
 *   @0x16d6e0 bne 0x16d77c <_ZN7CCamera13ApplyMatricesEv+0x3c0>
 *   @0x16d6e4 vmov.f32 s16, #1.000000e+00
 *   @0x16d6e8 vdiv.f32 s16, s16, s14
 *   @0x16d6ec vmul.f32 s18, s18, s16
 *   @0x16d6f0 vmov r0, s18
 *   @0x16d6f4 bl 0xb6760 <acosf@plt>
 *   @0x16d6f8 vmul.f32 s17, s17, s16
 *   @0x16d6fc vldr s14, [pc, #152]
 *   @0x16d700 ldr r12, [pc, #0xb4]
 *   @0x16d704 ldr r1, [r8]
 *   @0x16d708 ldr r2, [r6]
 *   @0x16d70c ldr r12, [r4, r12]
 *   @0x16d710 ldr r3, [r7]
 *   @0x16d714 vcmpe.f32 s17, #0
 *   @0x16d718 vmrs APSR_nzcv, fpscr
 *   @0x16d71c vldrmi s15, [pc, #124]
 *   @0x16d720 vmov s13, r0
 *   @0x16d724 ldr r0, [r9]
 *   @0x16d728 vsubmi.f32 s13, s15, s13
 *   @0x16d72c vldr s15, [pc, #108]
 *   @0x16d730 vdiv.f32 s15, s13, s15
 *   @0x16d734 vmul.f32 s15, s15, s14
 *   @0x16d738 vstr s15, [sp]
 *   @0x16d73c vstr s15, [r12]
 *   @0x16d740 bl 0x1692e4 <_Z14SetViewExtentsfffff>
 *   @0x16d744 b 0x16d45c <_ZN7CCamera13ApplyMatricesEv+0xa0>
 *   @0x16d748 vldr s11, [pc, #72]
 *   @0x16d74c vmov.f32 s12, s11
 *   @0x16d750 b 0x16d69c <_ZN7CCamera13ApplyMatricesEv+0x2e0>
 *   @0x16d754 vmov.f32 s15, #1.000000e+00
 *   @0x16d758 ldr r3, [pc, #0x54]
 *   @0x16d75c ldr r3, [r4, r3]
 *   @0x16d760 vmov.f32 s14, s15
 *   @0x16d764 vstr s15, [r3]
 *   @0x16d768 b 0x16d42c <_ZN7CCamera13ApplyMatricesEv+0x70>
 *   @0x16d76c vmov r0, s14
 *   @0x16d770 bl 0xb6700 <sqrtf@plt>
 *   @0x16d774 vmov s15, r0
 *   @0x16d778 b 0x16d654 <_ZN7CCamera13ApplyMatricesEv+0x298>
 *   @0x16d77c vmov r0, s16
 *   @0x16d780 bl 0xb6700 <sqrtf@plt>
 *   @0x16d784 vmov s14, r0
 *   @0x16d788 b 0x16d6e4 <_ZN7CCamera13ApplyMatricesEv+0x328>
 *   @0x16d78c vmov r0, s16
 *   @0x16d790 bl 0xb6700 <sqrtf@plt>
 *   @0x16d794 b 0x16d68c <_ZN7CCamera13ApplyMatricesEv+0x2d0>
 *   @0x16d798 andeq r0, r0, r0
 *   @0x16d79c .word 0x43b40000
 *   @0x16d7a0 ldrdmi r0, r1, [r9], #251
 *   @0x16d7a4 eoreq r4, r8, r12, ror r8
 *   @0x16d7a8 .word 0xffffe504
 *   @0x16d7ac .word 0xffffe508
 *   @0x16d7b0 .word 0xffffbcd8
 *   @0x16d7b4 .word 0xffffe50c
 *   @0x16d7b8 .word 0xffffe510
 *   @0x16d7bc .word 0xffffe514
 *   @0x16d7c0 .word 0xffffe48c
 *
 * ══ §6/31 MouseToStr  0xf38f0  size 1028  257 条（0xf38f0..0xf3cf4）
 * @func 0xf38f0 0xf3cf4  size 1028  257 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x238×1 / 0x230×1 / 0x228×1 / 0x220×1 / 0x218×1 / 0x210×1 / 0x208×1 / 0x200×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf38f0 cmp r0, #61
 *   @0xf38f4 addls pc, pc, r0, lsl #2
 *   @0xf38f8 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf38fc b 0xf39f4 <_Z10MouseToStri+0x104>
 *   @0xf3900 b 0xf3c1c <_Z10MouseToStri+0x32c>
 *   @0xf3904 b 0xf3c10 <_Z10MouseToStri+0x320>
 *   @0xf3908 b 0xf3c04 <_Z10MouseToStri+0x314>
 *   @0xf390c b 0xf3bf8 <_Z10MouseToStri+0x308>
 *   @0xf3910 b 0xf3bec <_Z10MouseToStri+0x2fc>
 *   @0xf3914 b 0xf3be0 <_Z10MouseToStri+0x2f0>
 *   @0xf3918 b 0xf3bd4 <_Z10MouseToStri+0x2e4>
 *   @0xf391c b 0xf3bc8 <_Z10MouseToStri+0x2d8>
 *   @0xf3920 b 0xf3bbc <_Z10MouseToStri+0x2cc>
 *   @0xf3924 b 0xf3bb0 <_Z10MouseToStri+0x2c0>
 *   @0xf3928 b 0xf3ba4 <_Z10MouseToStri+0x2b4>
 *   @0xf392c b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3930 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3934 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3938 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf393c b 0xf3b98 <_Z10MouseToStri+0x2a8>
 *   @0xf3940 b 0xf3b8c <_Z10MouseToStri+0x29c>
 *   @0xf3944 b 0xf3b80 <_Z10MouseToStri+0x290>
 *   @0xf3948 b 0xf3b74 <_Z10MouseToStri+0x284>
 *   @0xf394c b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3950 b 0xf3b68 <_Z10MouseToStri+0x278>
 *   @0xf3954 b 0xf3b5c <_Z10MouseToStri+0x26c>
 *   @0xf3958 b 0xf3b50 <_Z10MouseToStri+0x260>
 *   @0xf395c b 0xf3b44 <_Z10MouseToStri+0x254>
 *   @0xf3960 b 0xf3b38 <_Z10MouseToStri+0x248>
 *   @0xf3964 b 0xf3b2c <_Z10MouseToStri+0x23c>
 *   @0xf3968 b 0xf3b20 <_Z10MouseToStri+0x230>
 *   @0xf396c b 0xf3b14 <_Z10MouseToStri+0x224>
 *   @0xf3970 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3974 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf3978 b 0xf3b08 <_Z10MouseToStri+0x218>
 *   @0xf397c b 0xf3afc <_Z10MouseToStri+0x20c>
 *   @0xf3980 b 0xf3af0 <_Z10MouseToStri+0x200>
 *   @0xf3984 b 0xf3ae4 <_Z10MouseToStri+0x1f4>
 *   @0xf3988 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf398c b 0xf3ad8 <_Z10MouseToStri+0x1e8>
 *   @0xf3990 b 0xf3acc <_Z10MouseToStri+0x1dc>
 *   @0xf3994 b 0xf3ac0 <_Z10MouseToStri+0x1d0>
 *   @0xf3998 b 0xf3ab4 <_Z10MouseToStri+0x1c4>
 *   @0xf399c b 0xf3aa8 <_Z10MouseToStri+0x1b8>
 *   @0xf39a0 b 0xf3a9c <_Z10MouseToStri+0x1ac>
 *   @0xf39a4 b 0xf3a90 <_Z10MouseToStri+0x1a0>
 *   @0xf39a8 b 0xf3a84 <_Z10MouseToStri+0x194>
 *   @0xf39ac b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39b0 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39b4 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39b8 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39bc b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39c0 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39c4 b 0xf3a78 <_Z10MouseToStri+0x188>
 *   @0xf39c8 b 0xf3a6c <_Z10MouseToStri+0x17c>
 *   @0xf39cc b 0xf3a60 <_Z10MouseToStri+0x170>
 *   @0xf39d0 b 0xf3a54 <_Z10MouseToStri+0x164>
 *   @0xf39d4 b 0xf3a48 <_Z10MouseToStri+0x158>
 *   @0xf39d8 b 0xf3a3c <_Z10MouseToStri+0x14c>
 *   @0xf39dc b 0xf3a30 <_Z10MouseToStri+0x140>
 *   @0xf39e0 b 0xf3a24 <_Z10MouseToStri+0x134>
 *   @0xf39e4 b 0xf3a18 <_Z10MouseToStri+0x128>
 *   @0xf39e8 b 0xf3c28 <_Z10MouseToStri+0x338>
 *   @0xf39ec b 0xf3a0c <_Z10MouseToStri+0x11c>
 *   @0xf39f0 b 0xf3a00 <_Z10MouseToStri+0x110>
 *   @0xf39f4 ldr r0, [pc, #0x238]
 *   @0xf39f8 add r0, pc, r0
 *   @0xf39fc bx lr
 *   @0xf3a00 ldr r0, [pc, #0x230]
 *   @0xf3a04 add r0, pc, r0
 *   @0xf3a08 bx lr
 *   @0xf3a0c ldr r0, [pc, #0x228]
 *   @0xf3a10 add r0, pc, r0
 *   @0xf3a14 bx lr
 *   @0xf3a18 ldr r0, [pc, #0x220]
 *   @0xf3a1c add r0, pc, r0
 *   @0xf3a20 bx lr
 *   @0xf3a24 ldr r0, [pc, #0x218]
 *   @0xf3a28 add r0, pc, r0
 *   @0xf3a2c bx lr
 *   @0xf3a30 ldr r0, [pc, #0x210]
 *   @0xf3a34 add r0, pc, r0
 *   @0xf3a38 bx lr
 *   @0xf3a3c ldr r0, [pc, #0x208]
 *   @0xf3a40 add r0, pc, r0
 *   @0xf3a44 bx lr
 *   @0xf3a48 ldr r0, [pc, #0x200]
 *   @0xf3a4c add r0, pc, r0
 *   @0xf3a50 bx lr
 *   @0xf3a54 ldr r0, [pc, #0x1f8]
 *   @0xf3a58 add r0, pc, r0
 *   @0xf3a5c bx lr
 *   @0xf3a60 ldr r0, [pc, #0x1f0]
 *   @0xf3a64 add r0, pc, r0
 *   @0xf3a68 bx lr
 *   @0xf3a6c ldr r0, [pc, #0x1e8]
 *   @0xf3a70 add r0, pc, r0
 *   @0xf3a74 bx lr
 *   @0xf3a78 ldr r0, [pc, #0x1e0]
 *   @0xf3a7c add r0, pc, r0
 *   @0xf3a80 bx lr
 *   @0xf3a84 ldr r0, [pc, #0x1d8]
 *   @0xf3a88 add r0, pc, r0
 *   @0xf3a8c bx lr
 *   @0xf3a90 ldr r0, [pc, #0x1d0]
 *   @0xf3a94 add r0, pc, r0
 *   @0xf3a98 bx lr
 *   @0xf3a9c ldr r0, [pc, #0x1c8]
 *   @0xf3aa0 add r0, pc, r0
 *   @0xf3aa4 bx lr
 *   @0xf3aa8 ldr r0, [pc, #0x1c0]
 *   @0xf3aac add r0, pc, r0
 *   @0xf3ab0 bx lr
 *   @0xf3ab4 ldr r0, [pc, #0x1b8]
 *   @0xf3ab8 add r0, pc, r0
 *   @0xf3abc bx lr
 *   @0xf3ac0 ldr r0, [pc, #0x1b0]
 *   @0xf3ac4 add r0, pc, r0
 *   @0xf3ac8 bx lr
 *   @0xf3acc ldr r0, [pc, #0x1a8]
 *   @0xf3ad0 add r0, pc, r0
 *   @0xf3ad4 bx lr
 *   @0xf3ad8 ldr r0, [pc, #0x1a0]
 *   @0xf3adc add r0, pc, r0
 *   @0xf3ae0 bx lr
 *   @0xf3ae4 ldr r0, [pc, #0x198]
 *   @0xf3ae8 add r0, pc, r0
 *   @0xf3aec bx lr
 *   @0xf3af0 ldr r0, [pc, #0x190]
 *   @0xf3af4 add r0, pc, r0
 *   @0xf3af8 bx lr
 *   @0xf3afc ldr r0, [pc, #0x188]
 *   @0xf3b00 add r0, pc, r0
 *   @0xf3b04 bx lr
 *   @0xf3b08 ldr r0, [pc, #0x180]
 *   @0xf3b0c add r0, pc, r0
 *   @0xf3b10 bx lr
 *   @0xf3b14 ldr r0, [pc, #0x178]
 *   @0xf3b18 add r0, pc, r0
 *   @0xf3b1c bx lr
 *   @0xf3b20 ldr r0, [pc, #0x170]
 *   @0xf3b24 add r0, pc, r0
 *   @0xf3b28 bx lr
 *   @0xf3b2c ldr r0, [pc, #0x168]
 *   @0xf3b30 add r0, pc, r0
 *   @0xf3b34 bx lr
 *   @0xf3b38 ldr r0, [pc, #0x160]
 *   @0xf3b3c add r0, pc, r0
 *   @0xf3b40 bx lr
 *   @0xf3b44 ldr r0, [pc, #0x158]
 *   @0xf3b48 add r0, pc, r0
 *   @0xf3b4c bx lr
 *   @0xf3b50 ldr r0, [pc, #0x150]
 *   @0xf3b54 add r0, pc, r0
 *   @0xf3b58 bx lr
 *   @0xf3b5c ldr r0, [pc, #0x148]
 *   @0xf3b60 add r0, pc, r0
 *   @0xf3b64 bx lr
 *   @0xf3b68 ldr r0, [pc, #0x140]
 *   @0xf3b6c add r0, pc, r0
 *   @0xf3b70 bx lr
 *   @0xf3b74 ldr r0, [pc, #0x138]
 *   @0xf3b78 add r0, pc, r0
 *   @0xf3b7c bx lr
 *   @0xf3b80 ldr r0, [pc, #0x130]
 *   @0xf3b84 add r0, pc, r0
 *   @0xf3b88 bx lr
 *   @0xf3b8c ldr r0, [pc, #0x128]
 *   @0xf3b90 add r0, pc, r0
 *   @0xf3b94 bx lr
 *   @0xf3b98 ldr r0, [pc, #0x120]
 *   @0xf3b9c add r0, pc, r0
 *   @0xf3ba0 bx lr
 *   @0xf3ba4 ldr r0, [pc, #0x118]
 *   @0xf3ba8 add r0, pc, r0
 *   @0xf3bac bx lr
 *   @0xf3bb0 ldr r0, [pc, #0x110]
 *   @0xf3bb4 add r0, pc, r0
 *   @0xf3bb8 bx lr
 *   @0xf3bbc ldr r0, [pc, #0x108]
 *   @0xf3bc0 add r0, pc, r0
 *   @0xf3bc4 bx lr
 *   @0xf3bc8 ldr r0, [pc, #0x100]
 *   @0xf3bcc add r0, pc, r0
 *   @0xf3bd0 bx lr
 *   @0xf3bd4 ldr r0, [pc, #0xf8]
 *   @0xf3bd8 add r0, pc, r0
 *   @0xf3bdc bx lr
 *   @0xf3be0 ldr r0, [pc, #0xf0]
 *   @0xf3be4 add r0, pc, r0
 *   @0xf3be8 bx lr
 *   @0xf3bec ldr r0, [pc, #0xe8]
 *   @0xf3bf0 add r0, pc, r0
 *   @0xf3bf4 bx lr
 *   @0xf3bf8 ldr r0, [pc, #0xe0]
 *   @0xf3bfc add r0, pc, r0
 *   @0xf3c00 bx lr
 *   @0xf3c04 ldr r0, [pc, #0xd8]
 *   @0xf3c08 add r0, pc, r0
 *   @0xf3c0c bx lr
 *   @0xf3c10 ldr r0, [pc, #0xd0]
 *   @0xf3c14 add r0, pc, r0
 *   @0xf3c18 bx lr
 *   @0xf3c1c ldr r0, [pc, #0xc8]
 *   @0xf3c20 add r0, pc, r0
 *   @0xf3c24 bx lr
 *   @0xf3c28 ldr r0, [pc, #0xc0]
 *   @0xf3c2c add r0, pc, r0
 *   @0xf3c30 bx lr
 *   @0xf3c34 eoreq r3, r4, r12, lsl r7
 *   @0xf3c38 eoreq r3, r4, r0, asr r10
 *   @0xf3c3c eoreq r3, r4, r4, lsr r10
 *   @0xf3c40 eoreq r3, r4, r0, lsl r10
 *   @0xf3c44 .word 0x002439f0
 *   @0xf3c48 .word 0x002439d0
 *   @0xf3c4c .word 0x002439b0
 *   @0xf3c50 mlaeq r4, r0, r9, r3
 *   @0xf3c54 eoreq r3, r4, r0, ror r9
 *   @0xf3c58 eoreq r3, r4, r0, asr r9
 *   @0xf3c5c eoreq r3, r4, r0, lsr r9
 *   @0xf3c60 eoreq r3, r4, r0, lsl r9
 *   @0xf3c64 .word 0x002438f0
 *   @0xf3c68 .word 0x002438d0
 *   @0xf3c6c .word 0x002438b0
 *   @0xf3c70 mlaeq r4, r0, r8, r3
 *   @0xf3c74 eoreq r3, r4, r0, ror r8
 *   @0xf3c78 eoreq r3, r4, r0, asr r8
 *   @0xf3c7c eoreq r3, r4, r0, lsr r8
 *   @0xf3c80 eoreq r3, r4, r0, lsl r8
 *   @0xf3c84 .word 0x002437f4
 *   @0xf3c88 .word 0x002437d8
 *   @0xf3c8c .word 0x002437b8
 *   @0xf3c90 mlaeq r4, r12, r7, r3
 *   @0xf3c94 eoreq r3, r4, r12, ror r7
 *   @0xf3c98 eoreq r3, r4, r12, asr r7
 *   @0xf3c9c eoreq r3, r4, r12, lsr r7
 *   @0xf3ca0 eoreq r3, r4, r12, lsl r7
 *   @0xf3ca4 .word 0x002436fc
 *   @0xf3ca8 .word 0x002436dc
 *   @0xf3cac .word 0x002436bc
 *   @0xf3cb0 mlaeq r4, r12, r6, r3
 *   @0xf3cb4 eoreq r3, r4, r0, lsl #13
 *   @0xf3cb8 eoreq r3, r4, r4, ror #12
 *   @0xf3cbc eoreq r3, r4, r4, asr #12
 *   @0xf3cc0 eoreq r3, r4, r8, lsr #12
 *   @0xf3cc4 eoreq r3, r4, r0, lsl r6
 *   @0xf3cc8 .word 0x002435f8
 *   @0xf3ccc .word 0x002435dc
 *   @0xf3cd0 eoreq r3, r4, r0, asr #11
 *   @0xf3cd4 eoreq r3, r4, r4, lsr #11
 *   @0xf3cd8 eoreq r3, r4, r8, lsl #11
 *   @0xf3cdc eoreq r3, r4, r12, ror #10
 *   @0xf3ce0 eoreq r3, r4, r0, asr r5
 *   @0xf3ce4 eoreq r3, r4, r8, lsr r5
 *   @0xf3ce8 eoreq r3, r4, r12, lsl r5
 *   @0xf3cec eoreq r3, r4, r0, lsl #10
 *   @0xf3cf0 eoreq r3, r4, r8, asr #7
 *
 * ══ §7/31 CalcGUITransformMat  0x1b2e14  size 1008  252 条（0x1b2e14..0x1b3204）
 * @func 0x1b2e14 0x1b3204  size 1008  252 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1b2e28→0x3f50d0, 0x1b2ed4→0x3f50cc, 0x1b2ed8→0x3f26c0, 0x1b2f10→0x3f26bc, 0x1b2f2c→0x5425a5, 0x1b2f88→0x3f50c8, 0x1b2f90→0x3f50c0, 0x1b2fa0→0x3f50c4
 * 调用序列: 0xb6910×4 / Get_FullScreenOffset(int&, int&, int&, int&)
 * 字段偏移 top8: 0x14×5 / 0x10×4 / 0xc×4 / 0x4×4 / 0x24×3 / 0x20×3 / 0x1c×3 / 0x18×3
 * VFP 指令 125 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b2e14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1b2e18 vpush {d8, d9}
 *   @0x1b2e1c sub sp, sp, #44
 *   @0x1b2e20 ldr r6, [pc, #0x3b4]
 *   @0x1b2e24 mov r4, r1
 *   @0x1b2e28 ldr lr, [pc, #0x3b0]
 *   @0x1b2e2c mov r1, #0
 *   @0x1b2e30 add r6, pc, r6
 *   @0x1b2e34 str r1, [r0, #0x38]
 *   @0x1b2e38 str r1, [r0, #0x34]
 *   @0x1b2e3c mov r12, #1065353216
 *   @0x1b2e40 str r1, [r0, #0x30]
 *   @0x1b2e44 mov r7, r2
 *   @0x1b2e48 str r1, [r0, #0x2c]
 *   @0x1b2e4c mov r10, r3
 *   @0x1b2e50 str r1, [r0, #0x24]
 *   @0x1b2e54 mov r5, r0
 *   @0x1b2e58 str r1, [r0, #0x20]
 *   @0x1b2e5c str r1, [r0, #0x1c]
 *   @0x1b2e60 str r1, [r0, #0x18]
 *   @0x1b2e64 str r1, [r0, #0x10]
 *   @0x1b2e68 str r1, [r0, #0xc]
 *   @0x1b2e6c str r1, [r0, #0x8]
 *   @0x1b2e70 str r1, [r0, #0x4]
 *   @0x1b2e74 str r12, [r0, #0x3c]
 *   @0x1b2e78 str r12, [r0, #0x28]
 *   @0x1b2e7c str r12, [r0, #0x14]
 *   @0x1b2e80 str r12, [r0]
 *   @0x1b2e84 add r0, sp, #24
 *   @0x1b2e88 str r12, [r4, #0x3c]
 *   @0x1b2e8c str r12, [r4, #0x28]
 *   @0x1b2e90 str r12, [r4, #0x14]
 *   @0x1b2e94 str r12, [r4]
 *   @0x1b2e98 str r1, [r4, #0x38]
 *   @0x1b2e9c str r1, [r4, #0x34]
 *   @0x1b2ea0 str r1, [r4, #0x30]
 *   @0x1b2ea4 str r1, [r4, #0x2c]
 *   @0x1b2ea8 str r1, [r4, #0x24]
 *   @0x1b2eac str r1, [r4, #0x20]
 *   @0x1b2eb0 str r1, [r4, #0x1c]
 *   @0x1b2eb4 str r1, [r4, #0x18]
 *   @0x1b2eb8 str r1, [r4, #0x10]
 *   @0x1b2ebc ldr r8, [sp, #0x60]
 *   @0x1b2ec0 ldr r9, [sp, #0x64]
 *   @0x1b2ec4 str r1, [r4, #0xc]
 *   @0x1b2ec8 str r1, [r4, #0x8]
 *   @0x1b2ecc str r1, [r4, #0x4]
 *   @0x1b2ed0 ldr lr, [r6, lr]
 *   @0x1b2ed4 ldr r2, [pc, #0x308]
 *   @0x1b2ed8 ldr r3, [pc, #0x308]
 *   @0x1b2edc ldr r1, [lr]
 *   @0x1b2ee0 str lr, [sp, #0xc]
 *   @0x1b2ee4 cmp r1, #0
 *   @0x1b2ee8 str r1, [sp, #0x8]
 *   @0x1b2eec add r1, sp, #28
 *   @0x1b2ef0 ldr r2, [r6, r2]
 *   @0x1b2ef4 str r2, [sp, #0x10]
 *   @0x1b2ef8 ldr r11, [r6, r3]
 *   @0x1b2efc ldr r12, [r2]
 *   @0x1b2f00 add r2, sp, #32
 *   @0x1b2f04 ldrlt r3, [r11]
 *   @0x1b2f08 strlt r3, [sp, #0x8]
 *   @0x1b2f0c cmp r12, #0
 *   @0x1b2f10 ldr r3, [pc, #0x2d4]
 *   @0x1b2f14 ldr r3, [r6, r3]
 *   @0x1b2f18 ldrlt r12, [r3]
 *   @0x1b2f1c str r3, [sp, #0x14]
 *   @0x1b2f20 add r3, sp, #36
 *   @0x1b2f24 str r12, [sp, #0x4]
 *   @0x1b2f28 bl 0x179a00 <_Z20Get_FullScreenOffsetRiS_S_S_>
 *   @0x1b2f2c ldr r3, [pc, #0x2bc]
 *   @0x1b2f30 ldr lr, [sp, #0x20]
 *   @0x1b2f34 ldr r0, [sp, #0x18]
 *   @0x1b2f38 ldr r3, [r6, r3]
 *   @0x1b2f3c ldr r1, [sp, #0x24]
 *   @0x1b2f40 ldr r2, [sp, #0x1c]
 *   @0x1b2f44 ldrb r3, [r3]
 *   @0x1b2f48 ldr r12, [sp, #0x4]
 *   @0x1b2f4c cmp r3, #0
 *   @0x1b2f50 beq 0x1b3120 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_+0x30c>
 *   @0x1b2f54 vmov.f32 s18, #5.000000e-01
 *   @0x1b2f58 vldr s16, [r11]
 *   @0x1b2f5c vcvt.f32.s32 s16, s16
 *   @0x1b2f60 vmul.f32 s16, s16, s18
 *   @0x1b2f64 vmov r0, s16
 *   @0x1b2f68 bl 0xb6910 <floorf@plt>
 *   @0x1b2f6c ldr r1, [sp, #0x14]
 *   @0x1b2f70 vldr s17, [r1]
 *   @0x1b2f74 vcvt.f32.s32 s17, s17
 *   @0x1b2f78 vmul.f32 s17, s17, s18
 *   @0x1b2f7c vmov s19, r0
 *   @0x1b2f80 vmov r0, s17
 *   @0x1b2f84 bl 0xb6910 <floorf@plt>
 *   @0x1b2f88 ldr r3, [pc, #0x264]
 *   @0x1b2f8c vldr s15, [pc, #580]
 *   @0x1b2f90 ldr r2, [pc, #0x260]
 *   @0x1b2f94 ldr r3, [r6, r3]
 *   @0x1b2f98 vldr s14, [r3]
 *   @0x1b2f9c vcmp.f32 s14, s15
 *   @0x1b2fa0 ldr r3, [pc, #0x254]
 *   @0x1b2fa4 ldr r3, [r6, r3]
 *   @0x1b2fa8 vldr s15, [r3]
 *   @0x1b2fac vmrs APSR_nzcv, fpscr
 *   @0x1b2fb0 vsubne.f32 s19, s14, s19
 *   @0x1b2fb4 vldr s14, [pc, #540]
 *   @0x1b2fb8 ldr r3, [pc, #0x240]
 *   @0x1b2fbc vcmp.f32 s15, s14
 *   @0x1b2fc0 vnegeq.f32 s19, s19
 *   @0x1b2fc4 vmrs APSR_nzcv, fpscr
 *   @0x1b2fc8 vstr s19, [r8]
 *   @0x1b2fcc vmov s13, r0
 *   @0x1b2fd0 vsubne.f32 s15, s15, s13
 *   @0x1b2fd4 vnegeq.f32 s15, s13
 *   @0x1b2fd8 vstr s15, [r9]
 *   @0x1b2fdc ldr r2, [r6, r2]
 *   @0x1b2fe0 ldr r2, [r2]
 *   @0x1b2fe4 str r2, [r7]
 *   @0x1b2fe8 ldr r3, [r6, r3]
 *   @0x1b2fec vldr s15, [r3]
 *   @0x1b2ff0 vstr s15, [r10]
 *   @0x1b2ff4 vldr s14, [r7]
 *   @0x1b2ff8 vldr s9, [r5, #32]
 *   @0x1b2ffc vldr s8, [r5]
 *   @0x1b3000 vldr s10, [r5, #16]
 *   @0x1b3004 vmul.f32 s8, s8, s14
 *   @0x1b3008 vldr s12, [r5, #36]
 *   @0x1b300c vldr s11, [r5, #4]
 *   @0x1b3010 vldr s13, [r5, #20]
 *   @0x1b3014 vldr s4, [r5, #52]
 *   @0x1b3018 vldr s5, [r5, #48]
 *   @0x1b301c vldr s6, [r5, #56]
 *   @0x1b3020 vmul.f32 s10, s10, s14
 *   @0x1b3024 vstr s8, [r5]
 *   @0x1b3028 vldr s7, [r4]
 *   @0x1b302c vmul.f32 s14, s9, s14
 *   @0x1b3030 vstr s10, [r5, #16]
 *   @0x1b3034 vldr s10, [r4, #16]
 *   @0x1b3038 vmul.f32 s11, s11, s15
 *   @0x1b303c vstr s14, [r5, #32]
 *   @0x1b3040 vldr s9, [r4, #32]
 *   @0x1b3044 vmul.f32 s14, s12, s15
 *   @0x1b3048 vstr s11, [r5, #4]
 *   @0x1b304c vldr s8, [r4, #4]
 *   @0x1b3050 vmul.f32 s13, s13, s15
 *   @0x1b3054 vmov.f32 s15, #1.000000e+00
 *   @0x1b3058 vstr s13, [r5, #20]
 *   @0x1b305c vldr s12, [r4, #20]
 *   @0x1b3060 vstr s14, [r5, #36]
 *   @0x1b3064 vldr s14, [r9]
 *   @0x1b3068 vldr s13, [r8]
 *   @0x1b306c vldr s11, [r4, #36]
 *   @0x1b3070 vadd.f32 s14, s4, s14
 *   @0x1b3074 vadd.f32 s13, s5, s13
 *   @0x1b3078 vstr s14, [r5, #52]
 *   @0x1b307c vadd.f32 s14, s6, s15
 *   @0x1b3080 vstr s13, [r5, #48]
 *   @0x1b3084 vstr s14, [r5, #56]
 *   @0x1b3088 vldr s13, [r7]
 *   @0x1b308c vldr s14, [r10]
 *   @0x1b3090 vdiv.f32 s13, s15, s13
 *   @0x1b3094 vdiv.f32 s14, s15, s14
 *   @0x1b3098 vmul.f32 s7, s7, s13
 *   @0x1b309c vmul.f32 s8, s8, s14
 *   @0x1b30a0 vstr s7, [r4]
 *   @0x1b30a4 vmul.f32 s10, s10, s13
 *   @0x1b30a8 vstr s8, [r4, #4]
 *   @0x1b30ac vmul.f32 s13, s9, s13
 *   @0x1b30b0 vstr s10, [r4, #16]
 *   @0x1b30b4 vmul.f32 s12, s12, s14
 *   @0x1b30b8 vstr s13, [r4, #32]
 *   @0x1b30bc vmul.f32 s14, s11, s14
 *   @0x1b30c0 vstr s12, [r4, #20]
 *   @0x1b30c4 vldr s12, [r4, #56]
 *   @0x1b30c8 vldr s13, [r4, #48]
 *   @0x1b30cc vstr s14, [r4, #36]
 *   @0x1b30d0 vldr s14, [r9]
 *   @0x1b30d4 vldr s9, [r8]
 *   @0x1b30d8 vadd.f32 s17, s17, s14
 *   @0x1b30dc vldr s10, [r10]
 *   @0x1b30e0 vldr s11, [r7]
 *   @0x1b30e4 vldr s14, [r4, #52]
 *   @0x1b30e8 vadd.f32 s16, s16, s9
 *   @0x1b30ec vneg.f32 s17, s17
 *   @0x1b30f0 vneg.f32 s16, s16
 *   @0x1b30f4 vdiv.f32 s17, s17, s10
 *   @0x1b30f8 vdiv.f32 s16, s16, s11
 *   @0x1b30fc vsub.f32 s15, s12, s15
 *   @0x1b3100 vadd.f32 s16, s13, s16
 *   @0x1b3104 vstr s15, [r4, #56]
 *   @0x1b3108 vadd.f32 s17, s14, s17
 *   @0x1b310c vstr s16, [r4, #48]
 *   @0x1b3110 vstr s17, [r4, #52]
 *   @0x1b3114 add sp, sp, #44
 *   @0x1b3118 vpop {d8, d9}
 *   @0x1b311c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1b3120 rsb r0, r0, lr
 *   @0x1b3124 rsb r2, r2, r1
 *   @0x1b3128 vldr s12, [sp, #8]
 *   @0x1b312c vcvt.f32.s32 s13, s12
 *   @0x1b3130 vmov s12, r0
 *   @0x1b3134 ldr r1, [sp, #0xc]
 *   @0x1b3138 vmov s14, r2
 *   @0x1b313c ldr r3, [r1]
 *   @0x1b3140 ldr r1, [sp, #0x10]
 *   @0x1b3144 cmp r3, #0
 *   @0x1b3148 vcvt.f32.s32 s15, s12
 *   @0x1b314c vmov s12, r12
 *   @0x1b3150 ldr r3, [r1]
 *   @0x1b3154 movlt r2, #1065353216
 *   @0x1b3158 vcvt.f32.s32 s16, s14
 *   @0x1b315c vcvt.f32.s32 s14, s12
 *   @0x1b3160 vdiv.f32 s13, s15, s13
 *   @0x1b3164 vdiv.f32 s14, s16, s14
 *   @0x1b3168 vstr s13, [r7]
 *   @0x1b316c vmov.f32 s18, #5.000000e-01
 *   @0x1b3170 vstr s14, [r10]
 *   @0x1b3174 ldrge r2, [r7]
 *   @0x1b3178 cmp r3, #0
 *   @0x1b317c movlt r3, #1065353216
 *   @0x1b3180 str r2, [r7]
 *   @0x1b3184 ldrge r3, [r10]
 *   @0x1b3188 str r3, [r10]
 *   @0x1b318c vmul.f32 s15, s15, s18
 *   @0x1b3190 vmov r0, s15
 *   @0x1b3194 bl 0xb6910 <floorf@plt>
 *   @0x1b3198 vmul.f32 s16, s16, s18
 *   @0x1b319c eor r3, r0, #-2147483648
 *   @0x1b31a0 vmov r0, s16
 *   @0x1b31a4 str r3, [r8]
 *   @0x1b31a8 bl 0xb6910 <floorf@plt>
 *   @0x1b31ac vldr s16, [r11]
 *   @0x1b31b0 ldr r3, [sp, #0x14]
 *   @0x1b31b4 vcvt.f32.s32 s16, s16
 *   @0x1b31b8 vldr s17, [r3]
 *   @0x1b31bc vcvt.f32.s32 s17, s17
 *   @0x1b31c0 vmul.f32 s16, s16, s18
 *   @0x1b31c4 vmul.f32 s17, s17, s18
 *   @0x1b31c8 eor r0, r0, #-2147483648
 *   @0x1b31cc str r0, [r9]
 *   @0x1b31d0 vldr s15, [r10]
 *   @0x1b31d4 b 0x1b2ff4 <_Z19CalcGUITransformMatR8yyMatrixS0_RfS1_S1_S1_+0x1e0>
 *   @0x1b31d8 svcmi #0x0
 *   @0x1b31dc eoreq lr, r3, r0, lsr #28
 *   @0x1b31e0 .word 0xffffdf18
 *   @0x1b31e4 .word 0xffffdf24
 *   @0x1b31e8 .word 0xffffe24c
 *   @0x1b31ec .word 0xffffe250
 *   @0x1b31f0 .word 0xffffdf14
 *   @0x1b31f4 .word 0xffffdf1c
 *   @0x1b31f8 .word 0xffffdf28
 *   @0x1b31fc .word 0xffffdf20
 *   @0x1b3200 .word 0xffffdf2c
 *
 * ══ §8/31 b2PolygonShape::Set  0x2c6028  size 1004  251 条（0x2c6028..0x2c6414）
 * @func 0x2c6028 0x2c6414  size 1004  251 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2PolygonShape::Set(b2Vec2 const*, int)+0x39c / b2PolygonShape::Set(b2Vec2 const*, int)+0x60 / b2PolygonShape::Set(b2Vec2 const*, int)+0x110 / b2PolygonShape::Set(b2Vec2 const*, int)+0x1ac / b2PolygonShape::Set(b2Vec2 const*, int)+0x1f4 / b2PolygonShape::Set(b2Vec2 const*, int)+0x2e8 / 0xb6700
 * 字段偏移 top8: 0x4×3 / 0x3c4×1 / 0x3bc×1 / 0x94×1 / 0x1fc×1 / 0x138×1 / 0x84×1
 * VFP 指令 101 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c6028 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c602c vpush {d8, d9, d10}
 *   @0x2c6030 sub r3, r2, #3
 *   @0x2c6034 ldr r8, [pc, #0x3c4]
 *   @0x2c6038 cmp r3, #5
 *   @0x2c603c mov r4, r1
 *   @0x2c6040 ldr r1, [pc, #0x3bc]
 *   @0x2c6044 ldr r8, [pc, r8]
 *   @0x2c6048 mov r6, r0
 *   @0x2c604c sub sp, sp, #108
 *   @0x2c6050 movhi r0, #0
 *   @0x2c6054 movls r0, #1
 *   @0x2c6058 add r1, pc, r1
 *   @0x2c605c ldr r3, [r8]
 *   @0x2c6060 mov r9, r2
 *   @0x2c6064 blx r3
 *   @0x2c6068 cmp r9, #2
 *   @0x2c606c ble 0x2c63c4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x39c>
 *   @0x2c6070 cmp r9, #7
 *   @0x2c6074 mov r3, #0
 *   @0x2c6078 add r5, sp, #40
 *   @0x2c607c mov r12, r3
 *   @0x2c6080 movle r7, r9
 *   @0x2c6084 movgt r7, #8
 *   @0x2c6088 add r1, r4, r3
 *   @0x2c608c add r12, r12, #1
 *   @0x2c6090 add r2, r5, r3
 *   @0x2c6094 cmp r12, r7
 *   @0x2c6098 ldm r1, {r0, r1}
 *   @0x2c609c add r3, r3, #8
 *   @0x2c60a0 stm r2, {r0, r1}
 *   @0x2c60a4 blt 0x2c6088 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x60>
 *   @0x2c60a8 add r10, sp, #48
 *   @0x2c60ac mov r3, #1
 *   @0x2c60b0 mov r4, #0
 *   @0x2c60b4 vldr s14, [sp, #40]
 *   @0x2c60b8 mov r2, r10
 *   @0x2c60bc vldr s15, [r2]
 *   @0x2c60c0 vcmpe.f32 s15, s14
 *   @0x2c60c4 vmrs APSR_nzcv, fpscr
 *   @0x2c60c8 vmovgt.f32 s14, s15
 *   @0x2c60cc movgt r4, r3
 *   @0x2c60d0 bgt 0x2c6100 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xd8>
 *   @0x2c60d4 add r0, sp, #104
 *   @0x2c60d8 vcmp.f32 s15, s14
 *   @0x2c60dc add r1, r0, r4, lsl #3
 *   @0x2c60e0 vmrs APSR_nzcv, fpscr
 *   @0x2c60e4 bne 0x2c6100 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xd8>
 *   @0x2c60e8 vldr s12, [r2, #4]
 *   @0x2c60ec vldr s13, [r1, #-60]
 *   @0x2c60f0 vcmp.f32 s12, s13
 *   @0x2c60f4 vmrs APSR_nzcv, fpscr
 *   @0x2c60f8 vmovmi.f32 s14, s15
 *   @0x2c60fc movmi r4, r3
 *   @0x2c6100 add r3, r3, #1
 *   @0x2c6104 add r2, r2, #8
 *   @0x2c6108 cmp r3, r9
 *   @0x2c610c bne 0x2c60bc <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x94>
 *   @0x2c6110 add r1, sp, #4
 *   @0x2c6114 mov r11, r4
 *   @0x2c6118 mov r9, #0
 *   @0x2c611c str r1, [sp, #0x4]
 *   @0x2c6120 mov r0, r1
 *   @0x2c6124 add lr, r5, r4, lsl #3
 *   @0x2c6128 mov r1, r10
 *   @0x2c612c mov r2, #1
 *   @0x2c6130 mov r3, #0
 *   @0x2c6134 str r4, [r0, #0x4]!
 *   @0x2c6138 cmp r3, r4
 *   @0x2c613c add r12, r5, r3, lsl #3
 *   @0x2c6140 moveq r3, r2
 *   @0x2c6144 beq 0x2c61a4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x17c>
 *   @0x2c6148 vldr s13, [lr]
 *   @0x2c614c vldr s14, [lr, #4]
 *   @0x2c6150 vldr s12, [r1]
 *   @0x2c6154 vldr s11, [r12, #4]
 *   @0x2c6158 vsub.f32 s12, s12, s13
 *   @0x2c615c vldr s9, [r12]
 *   @0x2c6160 vldr s10, [r1, #4]
 *   @0x2c6164 vsub.f32 s11, s11, s14
 *   @0x2c6168 vmul.f32 s15, s11, s12
 *   @0x2c616c vsub.f32 s13, s9, s13
 *   @0x2c6170 vsub.f32 s14, s10, s14
 *   @0x2c6174 vnmls.f32 s15, s13, s14
 *   @0x2c6178 vcmp.f32 s15, #0
 *   @0x2c617c vmrs APSR_nzcv, fpscr
 *   @0x2c6180 movmi r3, r2
 *   @0x2c6184 bne 0x2c61a4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x17c>
 *   @0x2c6188 vmul.f32 s14, s14, s14
 *   @0x2c618c vmul.f32 s11, s11, s11
 *   @0x2c6190 vmla.f32 s14, s12, s12
 *   @0x2c6194 vmla.f32 s11, s13, s13
 *   @0x2c6198 vcmp.f32 s14, s11
 *   @0x2c619c vmrs APSR_nzcv, fpscr
 *   @0x2c61a0 movgt r3, r2
 *   @0x2c61a4 add r2, r2, #1
 *   @0x2c61a8 add r1, r1, #8
 *   @0x2c61ac cmp r2, r7
 *   @0x2c61b0 blt 0x2c6138 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x110>
 *   @0x2c61b4 cmp r11, r3
 *   @0x2c61b8 add r9, r9, #1
 *   @0x2c61bc movne r4, r3
 *   @0x2c61c0 bne 0x2c6124 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0xfc>
 *   @0x2c61c4 add lr, sp, #4
 *   @0x2c61c8 mov r2, r6
 *   @0x2c61cc mov r3, #0
 *   @0x2c61d0 str r9, [r6, #0x94]
 *   @0x2c61d4 ldr r1, [lr, #0x4]!
 *   @0x2c61d8 add r0, sp, #104
 *   @0x2c61dc add r3, r3, #1
 *   @0x2c61e0 add r12, r2, #20
 *   @0x2c61e4 cmp r3, r9
 *   @0x2c61e8 add r2, r2, #8
 *   @0x2c61ec add r1, r0, r1, lsl #3
 *   @0x2c61f0 sub r1, r1, #64
 *   @0x2c61f4 ldm r1, {r0, r1}
 *   @0x2c61f8 stm r12, {r0, r1}
 *   @0x2c61fc blt 0x2c61d4 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x1ac>
 *   @0x2c6200 vmov.f32 s21, #1.000000e+00
 *   @0x2c6204 ldr r7, [pc, #0x1fc]
 *   @0x2c6208 add r4, r6, #84
 *   @0x2c620c mov r5, #0
 *   @0x2c6210 add r7, pc, r7
 *   @0x2c6214 vldr s20, [pc, #468]
 *   @0x2c6218 vldr s19, [pc, #468]
 *   @0x2c621c add r5, r5, #1
 *   @0x2c6220 vldr s14, [r4, #-60]
 *   @0x2c6224 cmp r5, r9
 *   @0x2c6228 vldr s15, [r4, #-64]
 *   @0x2c622c ldr r2, [r8]
 *   @0x2c6230 mov r1, r7
 *   @0x2c6234 movlt r3, r5
 *   @0x2c6238 movge r3, #0
 *   @0x2c623c add r3, r3, #2
 *   @0x2c6240 add r3, r6, r3, lsl #3
 *   @0x2c6244 vldr s16, [r3, #8]
 *   @0x2c6248 vsub.f32 s16, s16, s14
 *   @0x2c624c vldr s17, [r3, #4]
 *   @0x2c6250 vmul.f32 s18, s16, s16
 *   @0x2c6254 vsub.f32 s17, s17, s15
 *   @0x2c6258 vmov.f32 s15, s18
 *   @0x2c625c vmla.f32 s15, s17, s17
 *   @0x2c6260 vcmpe.f32 s15, s20
 *   @0x2c6264 vneg.f32 s17, s17
 *   @0x2c6268 vmrs APSR_nzcv, fpscr
 *   @0x2c626c movle r0, #0
 *   @0x2c6270 movgt r0, #1
 *   @0x2c6274 blx r2
 *   @0x2c6278 vstr s16, [r4]
 *   @0x2c627c vmla.f32 s18, s17, s17
 *   @0x2c6280 vstr s17, [r4, #4]
 *   @0x2c6284 vsqrt.f32 s15, s18
 *   @0x2c6288 vcmp.f32 s15, s15
 *   @0x2c628c vmrs APSR_nzcv, fpscr
 *   @0x2c6290 bne 0x2c63e0 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x3b8>
 *   @0x2c6294 vcmpe.f32 s15, s19
 *   @0x2c6298 vmrs APSR_nzcv, fpscr
 *   @0x2c629c bmi 0x2c62bc <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x294>
 *   @0x2c62a0 vdiv.f32 s15, s21, s15
 *   @0x2c62a4 vldr s14, [r4]
 *   @0x2c62a8 vldr s13, [r4, #4]
 *   @0x2c62ac vmul.f32 s14, s14, s15
 *   @0x2c62b0 vmul.f32 s15, s13, s15
 *   @0x2c62b4 vstr s14, [r4]
 *   @0x2c62b8 vstr s15, [r4, #4]
 *   @0x2c62bc cmp r5, r9
 *   @0x2c62c0 add r4, r4, #8
 *   @0x2c62c4 blt 0x2c621c <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x1f4>
 *   @0x2c62c8 cmp r9, #2
 *   @0x2c62cc ldr r1, [pc, #0x138]
 *   @0x2c62d0 ldr r3, [r8]
 *   @0x2c62d4 add r4, r6, #20
 *   @0x2c62d8 movle r0, #0
 *   @0x2c62dc movgt r0, #1
 *   @0x2c62e0 add r1, pc, r1
 *   @0x2c62e4 blx r3
 *   @0x2c62e8 vldr s10, [pc, #264]
 *   @0x2c62ec vmov.f32 s5, #5.000000e-01
 *   @0x2c62f0 add r0, r6, #24
 *   @0x2c62f4 add r3, r6, #28
 *   @0x2c62f8 mov r2, #0
 *   @0x2c62fc vldr s6, [pc, #248]
 *   @0x2c6300 vmov.f32 s8, s10
 *   @0x2c6304 vmov.f32 s16, s10
 *   @0x2c6308 vmov.f32 s9, s10
 *   @0x2c630c b 0x2c6314 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x2ec>
 *   @0x2c6310 vmov.f32 s10, s18
 *   @0x2c6314 add r2, r2, #1
 *   @0x2c6318 mov r1, r0
 *   @0x2c631c cmp r2, r9
 *   @0x2c6320 vldr s14, [r1]
 *   @0x2c6324 vldr s11, [r3, #-8]
 *   @0x2c6328 vadd.f32 s7, s11, s9
 *   @0x2c632c movge r1, r4
 *   @0x2c6330 movlt r1, r3
 *   @0x2c6334 vldr s12, [r1]
 *   @0x2c6338 vldr s13, [r1, #4]
 *   @0x2c633c add r0, r0, #8
 *   @0x2c6340 add r3, r3, #8
 *   @0x2c6344 vmul.f32 s15, s14, s12
 *   @0x2c6348 vnmls.f32 s15, s11, s13
 *   @0x2c634c vmul.f32 s15, s15, s5
 *   @0x2c6350 vadd.f32 s11, s14, s9
 *   @0x2c6354 vmul.f32 s14, s15, s6
 *   @0x2c6358 vadd.f32 s12, s12, s7
 *   @0x2c635c vmov.f32 s17, s8
 *   @0x2c6360 vmla.f32 s17, s14, s12
 *   @0x2c6364 vadd.f32 s13, s13, s11
 *   @0x2c6368 vmov.f32 s18, s10
 *   @0x2c636c vadd.f32 s16, s16, s15
 *   @0x2c6370 vmov.f32 s8, s17
 *   @0x2c6374 vmla.f32 s18, s14, s13
 *   @0x2c6378 blt 0x2c6310 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x2e8>
 *   @0x2c637c vldr s15, [pc, #112]
 *   @0x2c6380 vcmpe.f32 s16, s15
 *   @0x2c6384 ldr r1, [pc, #0x84]
 *   @0x2c6388 ldr r3, [r8]
 *   @0x2c638c add r1, pc, r1
 *   @0x2c6390 vmrs APSR_nzcv, fpscr
 *   @0x2c6394 movle r0, #0
 *   @0x2c6398 movgt r0, #1
 *   @0x2c639c blx r3
 *   @0x2c63a0 vmov.f32 s15, #1.000000e+00
 *   @0x2c63a4 vdiv.f32 s16, s15, s16
 *   @0x2c63a8 vmul.f32 s17, s17, s16
 *   @0x2c63ac vmul.f32 s16, s18, s16
 *   @0x2c63b0 vstr s17, [r6, #12]
 *   @0x2c63b4 vstr s16, [r6, #16]
 *   @0x2c63b8 add sp, sp, #108
 *   @0x2c63bc vpop {d8, d9, d10}
 *   @0x2c63c0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2c63c4 mov r1, #1065353216
 *   @0x2c63c8 mov r0, r6
 *   @0x2c63cc mov r2, r1
 *   @0x2c63d0 add sp, sp, #108
 *   @0x2c63d4 vpop {d8, d9, d10}
 *   @0x2c63d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2c63dc b 0x2c5e9c <_ZN14b2PolygonShape8SetAsBoxEff>
 *   @0x2c63e0 vmov r0, s18
 *   @0x2c63e4 bl 0xb6700 <sqrtf@plt>
 *   @0x2c63e8 vmov s15, r0
 *   @0x2c63ec b 0x2c6294 <_ZN14b2PolygonShape3SetEPK6b2Vec2i+0x26c>
 *   @0x2c63f0 .word 0x28800000
 *   @0x2c63f4 strlo r0, [r0], #-0
 *   @0x2c63f8 andeq r0, r0, r0
 *   @0x2c63fc .word 0x3eaaaaab
 *   @0x2c6400 andseq r11, r2, r4, lsl #9
 *   @0x2c6404 andeq r7, r9, r0, ror #1
 *   @0x2c6408 ldrdeq r6, r7, [r9], -r12
 *   @0x2c640c andeq r6, r9, r8, asr #31
 *   @0x2c6410 andeq r6, r9, r4, ror #26
 *
 * ══ §9/31 VMBuffer::convertBuffer  0xec750  size 996  249 条（0xec750..0xecb34）
 * @func 0xec750 0xecb34  size 996  249 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xec844→0x3f2018, 0xec8fc→0x3f20b4, 0xec940→0x3f2018, 0xec9f0→0x3f20b4, 0xeca54→0x3f20b4, 0xecaa8→0x3f20b4
 * 调用序列: MemoryManager::Alloc(unsigned int, char const*, int, bool)×4 / unsigned int CHashMapCalculateHash<unsigned char*>(unsigned char*) / VMBuffer::convertBuffer()+0xcc / VMBuffer::convertBuffer()+0x370 / VMBuffer::convertBuffer()+0x20
 * 字段偏移 top8: 0x14×13 / 0x10×4 / 0x8×4 / 0x4×4 / 0x18×3 / 0x2×3 / 0xc×2 / 0x3a4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xec750 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xec754 mov r4, r0
 *   @0xec758 ldr r7, [r0, #0x14]
 *   @0xec75c sub sp, sp, #20
 *   @0xec760 ldr r5, [pc, #0x3a4]
 *   @0xec764 cmp r7, #0
 *   @0xec768 add r5, pc, r5
 *   @0xec76c beq 0xec778 <_ZN8VMBuffer13convertBufferEv+0x28>
 *   @0xec770 add sp, sp, #20
 *   @0xec774 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xec778 ldr r0, [r0, #0x10]
 *   @0xec77c bl 0xec748 <_Z21CHashMapCalculateHashIPhEjT_>
 *   @0xec780 ldr r2, [pc, #0x388]
 *   @0xec784 add r2, pc, r2
 *   @0xec788 ldr r1, [r2, #0x8]
 *   @0xec78c ldr r9, [r2, #0x10]
 *   @0xec790 bic r0, r0, #-2147483648
 *   @0xec794 and r3, r0, r1
 *   @0xec798 lsl r6, r3, #1
 *   @0xec79c add r12, r6, r3
 *   @0xec7a0 add r12, r9, r12, lsl #2
 *   @0xec7a4 ldr r12, [r12, #0x8]
 *   @0xec7a8 cmp r12, #0
 *   @0xec7ac beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc>
 *   @0xec7b0 cmp r0, r12
 *   @0xec7b4 beq 0xec9b4 <_ZN8VMBuffer13convertBufferEv+0x264>
 *   @0xec7b8 ldr r10, [r2]
 *   @0xec7bc and r12, r1, r12
 *   @0xec7c0 add r2, r3, r10
 *   @0xec7c4 rsb r12, r12, r2
 *   @0xec7c8 tst r12, r1
 *   @0xec7cc bmi 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc>
 *   @0xec7d0 mov r12, r7
 *   @0xec7d4 b 0xec7e8 <_ZN8VMBuffer13convertBufferEv+0x98>
 *   @0xec7d8 cmp r0, r2
 *   @0xec7dc beq 0xec9ac <_ZN8VMBuffer13convertBufferEv+0x25c>
 *   @0xec7e0 cmp r7, r12
 *   @0xec7e4 blt 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc>
 *   @0xec7e8 add r3, r3, #1
 *   @0xec7ec add r12, r12, #1
 *   @0xec7f0 and r3, r3, r1
 *   @0xec7f4 add r8, r3, r10
 *   @0xec7f8 lsl r6, r3, #1
 *   @0xec7fc add r2, r6, r3
 *   @0xec800 add r2, r9, r2, lsl #2
 *   @0xec804 ldr r2, [r2, #0x8]
 *   @0xec808 and r7, r1, r2
 *   @0xec80c cmp r2, #0
 *   @0xec810 rsb r7, r7, r8
 *   @0xec814 and r7, r7, r1
 *   @0xec818 bne 0xec7d8 <_ZN8VMBuffer13convertBufferEv+0x88>
 *   @0xec81c ldr r7, [r4, #0x4]
 *   @0xec820 cmp r7, #0
 *   @0xec824 ble 0xecac0 <_ZN8VMBuffer13convertBufferEv+0x370>
 *   @0xec828 mov r0, #0
 *   @0xec82c ldr r6, [r4, #0x10]
 *   @0xec830 mov r3, r0
 *   @0xec834 b 0xec83c <_ZN8VMBuffer13convertBufferEv+0xec>
 *   @0xec838 mov r0, r2
 *   @0xec83c ldr r2, [r6, r3]
 *   @0xec840 mov r1, #4
 *   @0xec844 ldr lr, [pc, #0x2c8]
 *   @0xec848 tst r2, #1073741824
 *   @0xec84c ubfx r12, r2, #0x10, #0x4
 *   @0xec850 ldrne r2, [r5, lr]
 *   @0xec854 ldrne r1, [r2, r12, lsl #2]
 *   @0xec858 add r2, r0, #1
 *   @0xec85c addne r1, r1, #4
 *   @0xec860 add r3, r3, r1
 *   @0xec864 cmp r7, r3
 *   @0xec868 bgt 0xec838 <_ZN8VMBuffer13convertBufferEv+0xe8>
 *   @0xec86c ldr r6, [pc, #0x2a4]
 *   @0xec870 add r0, r0, #2
 *   @0xec874 mov r2, #126
 *   @0xec878 mov r3, #1
 *   @0xec87c add r6, pc, r6
 *   @0xec880 lsl r0, r0, #2
 *   @0xec884 movw r8, #0x869f
 *   @0xec888 movt r8, #0x1
 *   @0xec88c mov r1, r6
 *   @0xec890 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xec894 cmp r7, #0
 *   @0xec898 add r12, r7, #3
 *   @0xec89c mov r1, r6
 *   @0xec8a0 movge r12, r7
 *   @0xec8a4 bic r12, r12, #3
 *   @0xec8a8 mov r2, #127
 *   @0xec8ac mov r3, #1
 *   @0xec8b0 str r0, [r4, #0x14]
 *   @0xec8b4 add r0, r12, #4
 *   @0xec8b8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xec8bc mov r12, #0
 *   @0xec8c0 mov r1, #6784
 *   @0xec8c4 movw r2, #0xa11f
 *   @0xec8c8 movt r1, #0x6
 *   @0xec8cc movt r2, #0x7
 *   @0xec8d0 mov r6, r12
 *   @0xec8d4 mov r3, r12
 *   @0xec8d8 str r1, [sp, #0x4]
 *   @0xec8dc str r2, [sp, #0x8]
 *   @0xec8e0 str r8, [sp, #0xc]
 *   @0xec8e4 str r0, [r4, #0x18]
 *   @0xec8e8 b 0xec928 <_ZN8VMBuffer13convertBufferEv+0x1d8>
 *   @0xec8ec cmp r1, #25
 *   @0xec8f0 beq 0xeca08 <_ZN8VMBuffer13convertBufferEv+0x2b8>
 *   @0xec8f4 cmp r1, #5
 *   @0xec8f8 beq 0xec9d0 <_ZN8VMBuffer13convertBufferEv+0x280>
 *   @0xec8fc ldr r0, [pc, #0x218]
 *   @0xec900 ldr r2, [r4, #0x14]
 *   @0xec904 ldr r0, [r5, r0]
 *   @0xec908 ldr r1, [r0, r1, lsl #2]
 *   @0xec90c str r1, [r2, r12]
 *   @0xec910 add r3, r3, r9
 *   @0xec914 add r6, r6, #1
 *   @0xec918 cmp r7, r3
 *   @0xec91c add r12, r12, #4
 *   @0xec920 ble 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20>
 *   @0xec924 ldr r0, [r4, #0x18]
 *   @0xec928 ldr r2, [r4, #0x10]
 *   @0xec92c add r10, r2, r3
 *   @0xec930 ldr r2, [r2, r3]
 *   @0xec934 ands r11, r2, #1073741824
 *   @0xec938 moveq r9, #4
 *   @0xec93c beq 0xec954 <_ZN8VMBuffer13convertBufferEv+0x204>
 *   @0xec940 ldr r1, [pc, #0x1cc]
 *   @0xec944 ubfx r8, r2, #0x10, #0x4
 *   @0xec948 ldr r1, [r5, r1]
 *   @0xec94c ldr r9, [r1, r8, lsl #2]
 *   @0xec950 add r9, r9, #4
 *   @0xec954 cmp r3, #0
 *   @0xec958 add r8, r3, #3
 *   @0xec95c ubfx r1, r2, #0x18, #0x5
 *   @0xec960 movge r8, r3
 *   @0xec964 cmp r1, #7
 *   @0xec968 asr r8, r8, #2
 *   @0xec96c str r6, [r0, r8, lsl #2]
 *   @0xec970 bne 0xec8ec <_ZN8VMBuffer13convertBufferEv+0x19c>
 *   @0xec974 tst r2, #3840
 *   @0xec978 ubfx r2, r2, #0x10, #0x8
 *   @0xec97c movne r1, #0
 *   @0xec980 moveq r1, #1
 *   @0xec984 cmp r2, #82
 *   @0xec988 movne r2, #0
 *   @0xec98c andeq r2, r1, #1
 *   @0xec990 cmp r2, #0
 *   @0xec994 beq 0xeca54 <_ZN8VMBuffer13convertBufferEv+0x304>
 *   @0xec998 ldr r1, [pc, #0x180]
 *   @0xec99c ldr r2, [r4, #0x14]
 *   @0xec9a0 ldr r1, [r5, r1]
 *   @0xec9a4 str r1, [r2, r12]
 *   @0xec9a8 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xec9ac cmn r3, #1
 *   @0xec9b0 beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc>
 *   @0xec9b4 add r3, r6, r3
 *   @0xec9b8 add r9, r9, r3, lsl #2
 *   @0xec9bc cmn r9, #4
 *   @0xec9c0 beq 0xec81c <_ZN8VMBuffer13convertBufferEv+0xcc>
 *   @0xec9c4 ldr r3, [r9, #0x4]
 *   @0xec9c8 str r3, [r4, #0x14]
 *   @0xec9cc b 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20>
 *   @0xec9d0 ubfx r0, r2, #0x10, #0x4
 *   @0xec9d4 ubfx r1, r2, #0x14, #0x4
 *   @0xec9d8 cmp r0, #5
 *   @0xec9dc cmpeq r1, #5
 *   @0xec9e0 bne 0xec9f0 <_ZN8VMBuffer13convertBufferEv+0x2a0>
 *   @0xec9e4 sxth r2, r2
 *   @0xec9e8 cmn r2, #7
 *   @0xec9ec beq 0xeca6c <_ZN8VMBuffer13convertBufferEv+0x31c>
 *   @0xec9f0 ldr r1, [pc, #0x124]
 *   @0xec9f4 ldr r2, [r4, #0x14]
 *   @0xec9f8 ldr r1, [r5, r1]
 *   @0xec9fc ldr r1, [r1, #0x14]
 *   @0xeca00 str r1, [r2, r12]
 *   @0xeca04 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xeca08 ubfx r2, r2, #0x10, #0x4
 *   @0xeca0c cmp r2, #2
 *   @0xeca10 bne 0xec8fc <_ZN8VMBuffer13convertBufferEv+0x1ac>
 *   @0xeca14 ldr r2, [r10, #0x4]
 *   @0xeca18 ldmib sp, {r0, r8}
 *   @0xeca1c sub r1, r2, #99328
 *   @0xeca20 sub r1, r1, #672
 *   @0xeca24 cmp r1, r0
 *   @0xeca28 movhi r1, #0
 *   @0xeca2c movls r1, #1
 *   @0xeca30 cmp r2, r8
 *   @0xeca34 moveq r1, #0
 *   @0xeca38 cmp r1, #0
 *   @0xeca3c beq 0xeca88 <_ZN8VMBuffer13convertBufferEv+0x338>
 *   @0xeca40 ldr r1, [pc, #0xdc]
 *   @0xeca44 ldr r2, [r4, #0x14]
 *   @0xeca48 ldr r1, [r5, r1]
 *   @0xeca4c str r1, [r2, r12]
 *   @0xeca50 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xeca54 ldr r1, [pc, #0xc0]
 *   @0xeca58 ldr r2, [r4, #0x14]
 *   @0xeca5c ldr r1, [r5, r1]
 *   @0xeca60 ldr r1, [r1, #0x1c]
 *   @0xeca64 str r1, [r2, r12]
 *   @0xeca68 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xeca6c cmp r11, #0
 *   @0xeca70 beq 0xec9f0 <_ZN8VMBuffer13convertBufferEv+0x2a0>
 *   @0xeca74 ldr r1, [pc, #0xac]
 *   @0xeca78 ldr r2, [r4, #0x14]
 *   @0xeca7c ldr r1, [r5, r1]
 *   @0xeca80 str r1, [r2, r12]
 *   @0xeca84 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xeca88 ldr r0, [sp, #0xc]
 *   @0xeca8c cmp r2, r0
 *   @0xeca90 bgt 0xecaa8 <_ZN8VMBuffer13convertBufferEv+0x358>
 *   @0xeca94 ldr r1, [pc, #0x90]
 *   @0xeca98 ldr r2, [r4, #0x14]
 *   @0xeca9c ldr r1, [r5, r1]
 *   @0xecaa0 str r1, [r2, r12]
 *   @0xecaa4 b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xecaa8 ldr r1, [pc, #0x6c]
 *   @0xecaac ldr r2, [r4, #0x14]
 *   @0xecab0 ldr r1, [r5, r1]
 *   @0xecab4 ldr r1, [r1, #0x64]
 *   @0xecab8 str r1, [r2, r12]
 *   @0xecabc b 0xec910 <_ZN8VMBuffer13convertBufferEv+0x1c0>
 *   @0xecac0 ldr r5, [pc, #0x68]
 *   @0xecac4 mov r2, #126
 *   @0xecac8 mov r3, #1
 *   @0xecacc mov r0, #4
 *   @0xecad0 add r5, pc, r5
 *   @0xecad4 mov r1, r5
 *   @0xecad8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xecadc add r3, r7, #3
 *   @0xecae0 cmp r7, #0
 *   @0xecae4 mov r1, r5
 *   @0xecae8 mov r2, #127
 *   @0xecaec movlt r7, r3
 *   @0xecaf0 bic r12, r7, #3
 *   @0xecaf4 mov r3, #1
 *   @0xecaf8 str r0, [r4, #0x14]
 *   @0xecafc add r0, r12, #4
 *   @0xecb00 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0xecb04 str r0, [r4, #0x18]
 *   @0xecb08 b 0xec770 <_ZN8VMBuffer13convertBufferEv+0x20>
 *   @0xecb0c eorseq r5, r0, r8, ror #9
 *   @0xecb10 eorseq r2, r9, r4, lsl r12
 *   @0xecb14 .word 0xffffc09c
 *   @0xecb18 .word 0x002482d4
 *   @0xecb1c .word 0xffffc0a0
 *   @0xecb20 .word 0xffffc124
 *   @0xecb24 .word 0xffffc128
 *   @0xecb28 .word 0xffffc12c
 *   @0xecb2c .word 0xffffc130
 *   @0xecb30 eoreq r8, r4, r0, lsl #1
 *
 * ══ §10/31 GR_Texture_Draw_Part  0x175450  size 996  249 条（0x175450..0x175834）
 * @func 0x175450 0x175834  size 996  249 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float)+0x37c×2 / GR_Texture_Exists(int) / 0xb6580 / 0xb658c / GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float)+0x128 / GR_Texture_Draw_Part(YYTPageEntry*, float, float, float, float, float, float, float, float, float, unsigned int, float)+0x180 / Graphics::AllocVerts(ePrimType, void*, int, int) / 0xfe23a1e8
 * 字段偏移 top8: 0x368×1 / 0x60×1 / 0x348×1 / 0x4×1 / 0x2×1 / 0x148×1 / 0xc×1 / 0x84×1
 * VFP 指令 167 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x175450 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x175454 vpush {d8, d9, d10, d11, d12}
 *   @0x175458 subs r4, r0, #0
 *   @0x17545c vldr s17, [sp, #72]
 *   @0x175460 vmov s22, r1
 *   @0x175464 vldr s19, [sp, #76]
 *   @0x175468 vmov s21, r2
 *   @0x17546c vldr s18, [sp, #80]
 *   @0x175470 vmov s16, r3
 *   @0x175474 vldr s20, [sp, #92]
 *   @0x175478 beq 0x1757c8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x378>
 *   @0x17547c ldrsh r0, [r4, #20]
 *   @0x175480 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x175484 subs r6, r0, #0
 *   @0x175488 beq 0x1757c8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x378>
 *   @0x17548c vldr s15, [pc, #904]
 *   @0x175490 vldr s10, [sp, #100]
 *   @0x175494 vmul.f32 s15, s10, s15
 *   @0x175498 vcvt.s32.f32 s15, s15
 *   @0x17549c vmov r5, s15
 *   @0x1754a0 cmp r5, #255
 *   @0x1754a4 movgt r5, #-16777216
 *   @0x1754a8 bgt 0x1754b8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x68>
 *   @0x1754ac cmp r5, #0
 *   @0x1754b0 lslge r5, r5, #24
 *   @0x1754b4 movlt r5, #0
 *   @0x1754b8 ldr r3, [pc, #0x368]
 *   @0x1754bc ldr r1, [sp, #0x60]
 *   @0x1754c0 ldr r3, [pc, r3]
 *   @0x1754c4 vmov r0, s20
 *   @0x1754c8 bic r2, r1, #-16777216
 *   @0x1754cc ldrb r3, [r3]
 *   @0x1754d0 orr r5, r5, r2
 *   @0x1754d4 ldrsh r2, [r4, #20]
 *   @0x1754d8 cmp r3, #0
 *   @0x1754dc ldr r3, [pc, #0x348]
 *   @0x1754e0 bicne r5, r5, #65536
 *   @0x1754e4 ldr r3, [pc, r3]
 *   @0x1754e8 bicne r5, r5, #1
 *   @0x1754ec orrne r7, r5, #65536
 *   @0x1754f0 orrne r9, r5, #1
 *   @0x1754f4 ldr r3, [r3, #0x4]
 *   @0x1754f8 orrne r8, r7, #1
 *   @0x1754fc moveq r8, r5
 *   @0x175500 moveq r7, r5
 *   @0x175504 moveq r9, r5
 *   @0x175508 ldr r10, [r3, r2, lsl #2]
 *   @0x17550c bl 0xb6580 <sinf@plt>
 *   @0x175510 vmov s23, r0
 *   @0x175514 vmov r0, s20
 *   @0x175518 bl 0xb658c <cosf@plt>
 *   @0x17551c ldrsh r3, [r4, #8]
 *   @0x175520 vmov s15, r3
 *   @0x175524 vcvt.f32.s32 s15, s15
 *   @0x175528 vcmpe.f32 s15, s22
 *   @0x17552c vmrs APSR_nzcv, fpscr
 *   @0x175530 vsuble.f32 s22, s22, s15
 *   @0x175534 vmov s24, r0
 *   @0x175538 ble 0x175578 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x128>
 *   @0x17553c vsub.f32 s15, s15, s22
 *   @0x175540 vldr s10, [sp, #84]
 *   @0x175544 vldr s11, [sp, #88]
 *   @0x175548 vldr s22, [pc, #720]
 *   @0x17554c vmul.f32 s13, s24, s15
 *   @0x175550 vmul.f32 s14, s23, s15
 *   @0x175554 vmul.f32 s13, s13, s10
 *   @0x175558 vmul.f32 s14, s14, s11
 *   @0x17555c vcvt.s32.f32 s13, s13
 *   @0x175560 vcvt.s32.f32 s14, s14
 *   @0x175564 vcvt.f32.s32 s13, s13
 *   @0x175568 vcvt.f32.s32 s14, s14
 *   @0x17556c vsub.f32 s16, s16, s15
 *   @0x175570 vadd.f32 s19, s19, s13
 *   @0x175574 vsub.f32 s18, s18, s14
 *   @0x175578 ldrsh r1, [r4, #10]
 *   @0x17557c vmov s15, r1
 *   @0x175580 vcvt.f32.s32 s15, s15
 *   @0x175584 vcmpe.f32 s15, s21
 *   @0x175588 vmrs APSR_nzcv, fpscr
 *   @0x17558c vsuble.f32 s21, s21, s15
 *   @0x175590 ble 0x1755d0 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x180>
 *   @0x175594 vldr s10, [sp, #84]
 *   @0x175598 vldr s11, [sp, #88]
 *   @0x17559c vsub.f32 s15, s15, s21
 *   @0x1755a0 vldr s21, [pc, #632]
 *   @0x1755a4 vmul.f32 s13, s23, s15
 *   @0x1755a8 vmul.f32 s14, s24, s15
 *   @0x1755ac vmul.f32 s13, s13, s10
 *   @0x1755b0 vmul.f32 s14, s14, s11
 *   @0x1755b4 vcvt.s32.f32 s13, s13
 *   @0x1755b8 vcvt.s32.f32 s14, s14
 *   @0x1755bc vcvt.f32.s32 s13, s13
 *   @0x1755c0 vcvt.f32.s32 s14, s14
 *   @0x1755c4 vsub.f32 s17, s17, s15
 *   @0x1755c8 vadd.f32 s19, s19, s13
 *   @0x1755cc vadd.f32 s18, s18, s14
 *   @0x1755d0 ldrsh r1, [r4, #12]
 *   @0x1755d4 vldr s25, [pc, #580]
 *   @0x1755d8 ldrsh r3, [r4, #14]
 *   @0x1755dc vmov s15, r1
 *   @0x1755e0 vadd.f32 s14, s22, s16
 *   @0x1755e4 vcvt.f32.s32 s15, s15
 *   @0x1755e8 vcmpe.f32 s14, s15
 *   @0x1755ec vadd.f32 s14, s21, s17
 *   @0x1755f0 vmrs APSR_nzcv, fpscr
 *   @0x1755f4 vsubgt.f32 s16, s15, s22
 *   @0x1755f8 vmov s15, r3
 *   @0x1755fc vcvt.f32.s32 s15, s15
 *   @0x175600 vcmpe.f32 s14, s15
 *   @0x175604 vmrs APSR_nzcv, fpscr
 *   @0x175608 vcmpe.f32 s16, s25
 *   @0x17560c vsubgt.f32 s17, s15, s21
 *   @0x175610 vmrs APSR_nzcv, fpscr
 *   @0x175614 bls 0x1757cc <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x37c>
 *   @0x175618 vcmpe.f32 s17, s25
 *   @0x17561c vmrs APSR_nzcv, fpscr
 *   @0x175620 bls 0x1757cc <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x37c>
 *   @0x175624 vabs.f32 s20, s20
 *   @0x175628 mov r0, #4
 *   @0x17562c ldr r1, [r10]
 *   @0x175630 mov r2, #24
 *   @0x175634 mov r3, #6
 *   @0x175638 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii>
 *   @0x17563c vldr s15, [pc, #480]
 *   @0x175640 vcmpe.f32 s20, s15
 *   @0x175644 vldr s10, [sp, #84]
 *   @0x175648 vldr s11, [sp, #88]
 *   @0x17564c vmul.f32 s14, s10, s16
 *   @0x175650 vmrs APSR_nzcv, fpscr
 *   @0x175654 vmul.f32 s15, s11, s17
 *   @0x175658 bmi 0x1757d8 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x388>
 *   @0x17565c vmov.f32 s12, s19
 *   @0x175660 vmov.f32 s10, s18
 *   @0x175664 vmul.f32 s13, s24, s25
 *   @0x175668 vmul.f32 s25, s23, s25
 *   @0x17566c vmla.f32 s12, s14, s24
 *   @0x175670 vmls.f32 s10, s14, s23
 *   @0x175674 vmul.f32 s24, s15, s24
 *   @0x175678 vmul.f32 s23, s15, s23
 *   @0x17567c vadd.f32 s19, s19, s13
 *   @0x175680 vsub.f32 s18, s18, s25
 *   @0x175684 vadd.f32 s15, s25, s19
 *   @0x175688 vadd.f32 s11, s13, s18
 *   @0x17568c vstr s15, [r0]
 *   @0x175690 vadd.f32 s19, s23, s19
 *   @0x175694 vstr s11, [r0, #4]
 *   @0x175698 vadd.f32 s18, s24, s18
 *   @0x17569c vstr s19, [r0, #120]
 *   @0x1756a0 vstr s19, [r0, #48]
 *   @0x1756a4 vadd.f32 s25, s25, s12
 *   @0x1756a8 vstr s18, [r0, #124]
 *   @0x1756ac vstr s18, [r0, #52]
 *   @0x1756b0 vadd.f32 s13, s13, s10
 *   @0x1756b4 vstr s25, [r0, #24]
 *   @0x1756b8 vstr s25, [r0, #72]
 *   @0x1756bc vadd.f32 s23, s23, s12
 *   @0x1756c0 vstr s13, [r0, #28]
 *   @0x1756c4 vstr s13, [r0, #76]
 *   @0x1756c8 vadd.f32 s24, s24, s10
 *   @0x1756cc vstr s23, [r0, #96]
 *   @0x1756d0 vstr s24, [r0, #100]
 *   @0x1756d4 ldrsh r1, [r4, #4]
 *   @0x1756d8 vldr s11, [r10, #8]
 *   @0x1756dc ldrsh r3, [r4, #12]
 *   @0x1756e0 ldr r2, [pc, #0x148]
 *   @0x1756e4 vmov s9, r1
 *   @0x1756e8 ldrsh r1, [r4]
 *   @0x1756ec vmov s12, r3
 *   @0x1756f0 ldrsh r3, [r4, #6]
 *   @0x1756f4 vcvt.f32.s32 s9, s9
 *   @0x1756f8 ldr r2, [pc, r2]
 *   @0x1756fc vmov s14, r1
 *   @0x175700 ldrsh r1, [r4, #14]
 *   @0x175704 vmov s10, r3
 *   @0x175708 ldr r2, [r2]
 *   @0x17570c str r5, [r0, #0xc]
 *   @0x175710 vmov s15, r1
 *   @0x175714 str r5, [r0, #0x84]
 *   @0x175718 str r9, [r0, #0x24]
 *   @0x17571c str r7, [r0, #0x3c]
 *   @0x175720 vcvt.f32.s32 s12, s12
 *   @0x175724 str r2, [r0, #0x80]
 *   @0x175728 str r7, [r0, #0x54]
 *   @0x17572c str r8, [r0, #0x6c]
 *   @0x175730 str r2, [r0, #0x68]
 *   @0x175734 str r2, [r0, #0x50]
 *   @0x175738 str r2, [r0, #0x38]
 *   @0x17573c str r2, [r0, #0x20]
 *   @0x175740 vdiv.f32 s12, s9, s12
 *   @0x175744 str r2, [r0, #0x8]
 *   @0x175748 vcvt.f32.s32 s14, s14
 *   @0x17574c vmla.f32 s14, s22, s12
 *   @0x175750 vcvt.f32.s32 s10, s10
 *   @0x175754 vcvt.f32.s32 s15, s15
 *   @0x175758 vdiv.f32 s13, s10, s15
 *   @0x17575c vmul.f32 s15, s14, s11
 *   @0x175760 vstr s15, [r0, #136]
 *   @0x175764 vstr s15, [r0, #64]
 *   @0x175768 vstr s15, [r0, #16]
 *   @0x17576c ldrsh r4, [r4, #2]
 *   @0x175770 vmla.f32 s14, s16, s12
 *   @0x175774 vldr s12, [r10, #12]
 *   @0x175778 vmov s15, r4
 *   @0x17577c vcvt.f32.s32 s15, s15
 *   @0x175780 vmla.f32 s15, s21, s13
 *   @0x175784 vmov.f32 s10, s15
 *   @0x175788 vmla.f32 s10, s17, s13
 *   @0x17578c vmul.f32 s14, s11, s14
 *   @0x175790 vmul.f32 s13, s12, s10
 *   @0x175794 vstr s14, [r0, #112]
 *   @0x175798 vstr s14, [r0, #40]
 *   @0x17579c vstr s14, [r0, #88]
 *   @0x1757a0 vmul.f32 s15, s15, s12
 *   @0x1757a4 vstr s13, [r0, #140]
 *   @0x1757a8 vstr s13, [r0, #68]
 *   @0x1757ac vstr s15, [r0, #44]
 *   @0x1757b0 vstr s15, [r0, #92]
 *   @0x1757b4 vstr s15, [r0, #20]
 *   @0x1757b8 vstr s13, [r0, #116]
 *   @0x1757bc vpop {d8, d9, d10, d11, d12}
 *   @0x1757c0 mov r0, r6
 *   @0x1757c4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1757c8 mov r6, #0
 *   @0x1757cc vpop {d8, d9, d10, d11, d12}
 *   @0x1757d0 mov r0, r6
 *   @0x1757d4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1757d8 vadd.f32 s14, s19, s14
 *   @0x1757dc vadd.f32 s19, s19, s25
 *   @0x1757e0 vstr s14, [r0, #96]
 *   @0x1757e4 vstr s14, [r0, #24]
 *   @0x1757e8 vstr s14, [r0, #72]
 *   @0x1757ec vadd.f32 s25, s18, s25
 *   @0x1757f0 vstr s19, [r0]
 *   @0x1757f4 vstr s19, [r0, #120]
 *   @0x1757f8 vstr s19, [r0, #48]
 *   @0x1757fc vadd.f32 s18, s18, s15
 *   @0x175800 vstr s25, [r0, #28]
 *   @0x175804 vstr s25, [r0, #76]
 *   @0x175808 vstr s25, [r0, #4]
 *   @0x17580c vstr s18, [r0, #124]
 *   @0x175810 vstr s18, [r0, #52]
 *   @0x175814 vstr s18, [r0, #100]
 *   @0x175818 b 0x1756d4 <_Z20GR_Texture_Draw_PartP12YYTPageEntryfffffffffjf+0x284>
 *   @0x17581c cmnmi pc, #0
 *   @0x175820 andeq r0, r0, r0
 *   @0x175824 blo 0xfe23a1e8 <b2_toiTime+0xfffffffffdae0d44>
 *   @0x175828 eoreq r8, r7, r12, lsl #19
 *   @0x17582c eoreq r8, r7, r8, lsr r4
 *   @0x175830 eoreq r8, r7, r8, lsr #4
 *
 * ══ §11/31 VM::ExecDebug  0xe47c8  size 992  248 条（0xe47c8..0xe4ba8）
 * @func 0xe47c8 0xe4ba8  size 992  248 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xe47d8→0x47a1d4, 0xe47e8→0x47b234, 0xe482c→0x757e4c, 0xe4850→0x3f2094, 0xe4864→0x47f298, 0xe486c→0x47f297, 0xe4890→0x3f20b4, 0xe48b0→0x756470
 * 调用序列: VM::ExecDebug(VMExec&, RValue*, bool)+0xa4×2 / VM::ExecDebug(VMExec&, RValue*, bool)+0x178 / MemoryManager::Free(void const*) / VM::ExecDebug(VMExec&, RValue*, bool)+0x1b8 / YYObjectBase::Free(YYObjectBase*) / VM::DebugInfo(VMBuffer*, int) / VM::DebugLineNumber(VMDebugInfo*, char const*, char**) / PerformReturn(unsigned char*, VMExec*)
 * 字段偏移 top8: 0xc×8 / 0x8×8 / 0x4×7 / 0x44×4 / 0x10×4 / 0x28×2 / 0x2×2 / 0x4c×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xe47c8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0xe47cc sub sp, sp, #20
 *   @0xe47d0 ldr r5, [pc, #0x38c]
 *   @0xe47d4 mov r10, r1
 *   @0xe47d8 ldr r3, [pc, #0x388]
 *   @0xe47dc mov r4, r0
 *   @0xe47e0 add r5, pc, r5
 *   @0xe47e4 str r2, [sp, #0xc]
 *   @0xe47e8 ldr r1, [pc, #0x37c]
 *   @0xe47ec mov r9, #0
 *   @0xe47f0 ldr r3, [r5, r3]
 *   @0xe47f4 ldr r8, [r0, #0x28]
 *   @0xe47f8 ldr r2, [r3]
 *   @0xe47fc add r2, r2, #1
 *   @0xe4800 str r2, [r3]
 *   @0xe4804 ldr r1, [r5, r1]
 *   @0xe4808 ldr r2, [r1]
 *   @0xe480c str r1, [sp, #0x4]
 *   @0xe4810 str r2, [sp, #0x8]
 *   @0xe4814 ldr r1, [r4, #0x44]
 *   @0xe4818 ldr r3, [r4, #0x50]
 *   @0xe481c cmp r1, r3
 *   @0xe4820 bge 0xe48e0 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x118>
 *   @0xe4824 ldr r3, [r4, #0x24]
 *   @0xe4828 add r2, r1, #4
 *   @0xe482c ldr r0, [pc, #0x33c]
 *   @0xe4830 str r1, [r4, #0x54]
 *   @0xe4834 ldr r6, [r3, r1]
 *   @0xe4838 add r3, r3, r2
 *   @0xe483c str r2, [r4, #0x44]
 *   @0xe4840 ldr r2, [r5, r0]
 *   @0xe4844 ldr r2, [r2]
 *   @0xe4848 cmp r2, #0
 *   @0xe484c beq 0xe4a80 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2b8>
 *   @0xe4850 ldr r2, [pc, #0x31c]
 *   @0xe4854 ldr r11, [r5, r2]
 *   @0xe4858 ldr r2, [r11]
 *   @0xe485c cmp r2, #0
 *   @0xe4860 bge 0xe4988 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1c0>
 *   @0xe4864 ldr r2, [pc, #0x30c]
 *   @0xe4868 ldr r7, [r5, r2]
 *   @0xe486c ldr r2, [pc, #0x308]
 *   @0xe4870 ldr r2, [r5, r2]
 *   @0xe4874 ldrb r1, [r2]
 *   @0xe4878 cmp r1, #0
 *   @0xe487c bne 0xe4a24 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x25c>
 *   @0xe4880 tst r6, #1073741824
 *   @0xe4884 str r4, [r7]
 *   @0xe4888 ubfxeq lr, r6, #0x18, #0x5
 *   @0xe488c bne 0xe4a98 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2d0>
 *   @0xe4890 ldr r12, [pc, #0x2e8]
 *   @0xe4894 mov r1, r8
 *   @0xe4898 mov r2, r3
 *   @0xe489c mov r0, r6
 *   @0xe48a0 mov r3, r4
 *   @0xe48a4 ldr r12, [r5, r12]
 *   @0xe48a8 ldr r12, [r12, lr, lsl #2]
 *   @0xe48ac blx r12
 *   @0xe48b0 ldr r3, [pc, #0x2cc]
 *   @0xe48b4 str r4, [r7]
 *   @0xe48b8 ldr r12, [r5, r3]
 *   @0xe48bc ldrb r3, [r12]
 *   @0xe48c0 cmp r3, #0
 *   @0xe48c4 mov r8, r0
 *   @0xe48c8 beq 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c>
 *   @0xe48cc ldr r3, [pc, #0x2b4]
 *   @0xe48d0 ldr r3, [r5, r3]
 *   @0xe48d4 ldr r3, [r3]
 *   @0xe48d8 cmp r4, r3
 *   @0xe48dc beq 0xe4b0c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x344>
 *   @0xe48e0 ldr r3, [r4, #0x4c]
 *   @0xe48e4 cmp r3, #0
 *   @0xe48e8 bgt 0xe4a60 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x298>
 *   @0xe48ec ldr r2, [sp, #0x8]
 *   @0xe48f0 cmp r10, #0
 *   @0xe48f4 ldr r3, [sp, #0x4]
 *   @0xe48f8 str r2, [r3]
 *   @0xe48fc beq 0xe490c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x144>
 *   @0xe4900 ldr r3, [r4, #0x28]
 *   @0xe4904 cmp r3, r8
 *   @0xe4908 bhi 0xe4b40 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x378>
 *   @0xe490c ldr r3, [pc, #0x278]
 *   @0xe4910 ldr r0, [r4, #0x8]
 *   @0xe4914 ldr r12, [r5, r3]
 *   @0xe4918 ldr r3, [r12, #0x4]
 *   @0xe491c cmp r3, #0
 *   @0xe4920 beq 0xe494c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x184>
 *   @0xe4924 add r1, r3, #8
 *   @0xe4928 add r2, r3, #1048576
 *   @0xe492c cmp r0, r1
 *   @0xe4930 add r2, r2, #8
 *   @0xe4934 blo 0xe4940 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x178>
 *   @0xe4938 cmp r2, r0
 *   @0xe493c bhi 0xe4adc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x314>
 *   @0xe4940 ldr r3, [r3]
 *   @0xe4944 cmp r3, #0
 *   @0xe4948 bne 0xe4924 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x15c>
 *   @0xe494c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0xe4950 ldr r3, [sp, #0xc]
 *   @0xe4954 cmp r3, #0
 *   @0xe4958 beq 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8>
 *   @0xe495c ldr r3, [r4, #0xc]
 *   @0xe4960 cmp r3, #0
 *   @0xe4964 ble 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8>
 *   @0xe4968 ldr r0, [r4, #0x10]
 *   @0xe496c cmp r0, #0
 *   @0xe4970 beq 0xe4980 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1b8>
 *   @0xe4974 bl 0x198f88 <_ZN12YYObjectBase4FreeEPS_>
 *   @0xe4978 mov r3, #0
 *   @0xe497c str r3, [r4, #0x10]
 *   @0xe4980 add sp, sp, #20
 *   @0xe4984 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0xe4988 ldr r0, [r4, #0x38]
 *   @0xe498c str r3, [sp]
 *   @0xe4990 bl 0xec144 <_ZN2VM9DebugInfoEP8VMBufferi>
 *   @0xe4994 mov r2, #0
 *   @0xe4998 ldr r1, [r4, #0x3c]
 *   @0xe499c bl 0xec2b8 <_ZN2VM15DebugLineNumberEP11VMDebugInfoPKcPPc>
 *   @0xe49a0 ldr r2, [pc, #0x1d0]
 *   @0xe49a4 ldr r3, [sp]
 *   @0xe49a8 ldr r7, [r5, r2]
 *   @0xe49ac ldr r12, [r7]
 *   @0xe49b0 cmp r12, #0
 *   @0xe49b4 beq 0xe4b04 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x33c>
 *   @0xe49b8 mov r2, #0
 *   @0xe49bc ldr r1, [r12, #0x4c]
 *   @0xe49c0 add r2, r2, #1
 *   @0xe49c4 ldr r12, [r12, #0x4]
 *   @0xe49c8 add r2, r2, r1
 *   @0xe49cc cmp r12, #0
 *   @0xe49d0 bne 0xe49bc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x1f4>
 *   @0xe49d4 ldr r1, [r4, #0x3c]
 *   @0xe49d8 cmp r1, #0
 *   @0xe49dc beq 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4>
 *   @0xe49e0 ldr r12, [pc, #0x1a8]
 *   @0xe49e4 ldr r12, [r5, r12]
 *   @0xe49e8 ldr r12, [r12]
 *   @0xe49ec cmp r1, r12
 *   @0xe49f0 beq 0xe4aa4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2dc>
 *   @0xe49f4 ldr r0, [r11]
 *   @0xe49f8 cmp r0, #0
 *   @0xe49fc beq 0xe4a1c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x254>
 *   @0xe4a00 cmp r0, #2
 *   @0xe4a04 beq 0xe4abc <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x2f4>
 *   @0xe4a08 ldr r1, [pc, #0x184]
 *   @0xe4a0c ldr r1, [r5, r1]
 *   @0xe4a10 ldr r1, [r1]
 *   @0xe4a14 cmp r1, r2
 *   @0xe4a18 blt 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4>
 *   @0xe4a1c ldr r2, [pc, #0x158]
 *   @0xe4a20 ldr r2, [r5, r2]
 *   @0xe4a24 mov r6, #0
 *   @0xe4a28 movt r6, #0xff0f
 *   @0xe4a2c mov lr, #31
 *   @0xe4a30 mov r0, #15
 *   @0xe4a34 strb r9, [r2]
 *   @0xe4a38 mvn r2, #0
 *   @0xe4a3c str r4, [r7]
 *   @0xe4a40 str r2, [r11]
 *   @0xe4a44 ldr r2, [pc, #0x14c]
 *   @0xe4a48 ldr r1, [r4, #0x44]
 *   @0xe4a4c ldr r2, [r5, r2]
 *   @0xe4a50 ldr r2, [r2, r0, lsl #2]
 *   @0xe4a54 add r2, r1, r2
 *   @0xe4a58 str r2, [r4, #0x44]
 *   @0xe4a5c b 0xe4890 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xc8>
 *   @0xe4a60 mov r0, r8
 *   @0xe4a64 mov r1, r4
 *   @0xe4a68 bl 0xe42d8 <_Z13PerformReturnPhP6VMExec>
 *   @0xe4a6c str r9, [r0, #-0x4]
 *   @0xe4a70 sub r8, r0, #16
 *   @0xe4a74 str r9, [r0, #-0x10]
 *   @0xe4a78 str r9, [r0, #-0xc]
 *   @0xe4a7c b 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c>
 *   @0xe4a80 ldr r2, [pc, #0xf0]
 *   @0xe4a84 tst r6, #1073741824
 *   @0xe4a88 ubfxeq lr, r6, #0x18, #0x5
 *   @0xe4a8c ldr r7, [r5, r2]
 *   @0xe4a90 str r4, [r7]
 *   @0xe4a94 beq 0xe4890 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xc8>
 *   @0xe4a98 ubfx r0, r6, #0x10, #0x4
 *   @0xe4a9c ubfx lr, r6, #0x18, #0x5
 *   @0xe4aa0 b 0xe4a44 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x27c>
 *   @0xe4aa4 ldr lr, [pc, #0xf0]
 *   @0xe4aa8 ldr lr, [r5, lr]
 *   @0xe4aac ldr lr, [lr]
 *   @0xe4ab0 cmp r0, lr
 *   @0xe4ab4 bne 0xe49f4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x22c>
 *   @0xe4ab8 b 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4>
 *   @0xe4abc ldr r0, [pc, #0xd0]
 *   @0xe4ac0 ldr r0, [r5, r0]
 *   @0xe4ac4 ldr r0, [r0]
 *   @0xe4ac8 cmp r0, r2
 *   @0xe4acc blt 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4>
 *   @0xe4ad0 cmp r1, r12
 *   @0xe4ad4 bne 0xe4a1c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x254>
 *   @0xe4ad8 b 0xe486c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0xa4>
 *   @0xe4adc ldr r1, [r12, #0x8]
 *   @0xe4ae0 ldr r2, [r12, #0x10]
 *   @0xe4ae4 ldr r3, [r12, #0xc]
 *   @0xe4ae8 add r2, r2, #1
 *   @0xe4aec str r1, [r0]
 *   @0xe4af0 sub r3, r3, #1
 *   @0xe4af4 str r0, [r12, #0x8]
 *   @0xe4af8 str r2, [r12, #0x10]
 *   @0xe4afc str r3, [r12, #0xc]
 *   @0xe4b00 b 0xe4950 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x188>
 *   @0xe4b04 mov r2, r12
 *   @0xe4b08 b 0xe49d4 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x20c>
 *   @0xe4b0c ldr r2, [pc, #0x8c]
 *   @0xe4b10 ldr r3, [pc, #0x8c]
 *   @0xe4b14 ldr r6, [r5, r2]
 *   @0xe4b18 ldr r7, [r5, r3]
 *   @0xe4b1c ldm r6!, {r0, r1, r2, r3}
 *   @0xe4b20 ldr r6, [r7]
 *   @0xe4b24 sub r8, r6, #16
 *   @0xe4b28 str r0, [r6, #-0x10]
 *   @0xe4b2c str r1, [r8, #0x4]
 *   @0xe4b30 str r2, [r8, #0x8]
 *   @0xe4b34 str r3, [r8, #0xc]
 *   @0xe4b38 strb r9, [r12]
 *   @0xe4b3c b 0xe4814 <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x4c>
 *   @0xe4b40 ldr r0, [r8]
 *   @0xe4b44 ldr r1, [r8, #0x4]
 *   @0xe4b48 ldr r2, [r8, #0x8]
 *   @0xe4b4c ldr r3, [r8, #0xc]
 *   @0xe4b50 str r0, [r10]
 *   @0xe4b54 str r1, [r10, #0x4]
 *   @0xe4b58 str r2, [r10, #0x8]
 *   @0xe4b5c str r3, [r10, #0xc]
 *   @0xe4b60 b 0xe490c <_ZN2VM9ExecDebugER6VMExecP6RValueb+0x144>
 *   @0xe4b64 eorseq sp, r0, r0, ror r4
 *   @0xe4b68 .word 0xffffc0d4
 *   @0xe4b6c .word 0xffffc0bc
 *   @0xe4b70 .word 0xffffc0a4
 *   @0xe4b74 .word 0xffffc0e8
 *   @0xe4b78 .word 0xffffbf58
 *   @0xe4b7c .word 0xffffc0ec
 *   @0xe4b80 .word 0xffffc0a0
 *   @0xe4b84 .word 0xffffc0cc
 *   @0xe4b88 .word 0xffffc0dc
 *   @0xe4b8c .word 0xffffc0e4
 *   @0xe4b90 .word 0xffffc0f0
 *   @0xe4b94 .word 0xffffc0f4
 *   @0xe4b98 .word 0xffffc09c
 *   @0xe4b9c .word 0xffffc0f8
 *   @0xe4ba0 .word 0xffffc0d8
 *   @0xe4ba4 .word 0xffffc0e0
 *
 * ══ §12/31 yyMatrix::Invert  0x16c65c  size 976  244 条（0x16c65c..0x16ca2c）
 * @func 0x16c65c 0x16ca2c  size 976  244 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 无
 * VFP 指令 233 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x16c65c vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x16c660 vldr s9, [r0, #44]
 *   @0x16c664 vldr s7, [r0, #20]
 *   @0x16c668 vldr s22, [r0, #16]
 *   @0x16c66c vmul.f32 s15, s7, s9
 *   @0x16c670 vldr s14, [r0, #56]
 *   @0x16c674 vldr s12, [r0, #40]
 *   @0x16c678 vldr s13, [r0, #60]
 *   @0x16c67c vldr s11, [r0, #36]
 *   @0x16c680 vldr s10, [r0, #52]
 *   @0x16c684 vldr s8, [r0, #24]
 *   @0x16c688 vldr s0, [r0, #32]
 *   @0x16c68c vldr s17, [r0, #48]
 *   @0x16c690 vldr s6, [r0, #28]
 *   @0x16c694 vldr s16, [r0, #32]
 *   @0x16c698 sub sp, sp, #96
 *   @0x16c69c vldr s20, [r0, #4]
 *   @0x16c6a0 vldr s25, [r0]
 *   @0x16c6a4 vmul.f32 s3, s9, s22
 *   @0x16c6a8 vneg.f32 s4, s22
 *   @0x16c6ac vmul.f32 s5, s14, s3
 *   @0x16c6b0 vmul.f32 s1, s12, s4
 *   @0x16c6b4 vmul.f32 s15, s15, s14
 *   @0x16c6b8 vmul.f32 s2, s7, s12
 *   @0x16c6bc vmla.f32 s5, s13, s1
 *   @0x16c6c0 vnmls.f32 s15, s2, s13
 *   @0x16c6c4 vmul.f32 s2, s12, s22
 *   @0x16c6c8 vmul.f32 s23, s8, s0
 *   @0x16c6cc vmul.f32 s21, s10, s3
 *   @0x16c6d0 vmul.f32 s0, s11, s8
 *   @0x16c6d4 vmul.f32 s3, s11, s22
 *   @0x16c6d8 vmul.f32 s31, s10, s2
 *   @0x16c6dc vmul.f32 s4, s11, s4
 *   @0x16c6e0 vmla.f32 s5, s13, s23
 *   @0x16c6e4 vmls.f32 s15, s13, s0
 *   @0x16c6e8 vnmls.f32 s21, s13, s3
 *   @0x16c6ec vmul.f32 s17, s8, s17
 *   @0x16c6f0 vmul.f32 s1, s6, s16
 *   @0x16c6f4 vstr s17, [sp, #28]
 *   @0x16c6f8 vldr s27, [sp, #28]
 *   @0x16c6fc vmul.f32 s0, s7, s16
 *   @0x16c700 vmul.f32 s3, s11, s6
 *   @0x16c704 vmla.f32 s31, s14, s4
 *   @0x16c708 vmul.f32 s17, s6, s20
 *   @0x16c70c vmul.f32 s18, s9, s20
 *   @0x16c710 vmul.f32 s26, s12, s25
 *   @0x16c714 vmls.f32 s5, s14, s1
 *   @0x16c718 vstr s26, [sp, #4]
 *   @0x16c71c vldr s26, [r0]
 *   @0x16c720 vmla.f32 s15, s14, s3
 *   @0x16c724 vmls.f32 s21, s13, s0
 *   @0x16c728 vmul.f32 s4, s6, s25
 *   @0x16c72c vmul.f32 s24, s8, s25
 *   @0x16c730 vmul.f32 s19, s9, s25
 *   @0x16c734 vneg.f32 s25, s25
 *   @0x16c738 vmul.f32 s16, s8, s10
 *   @0x16c73c vmul.f32 s29, s14, s18
 *   @0x16c740 vmul.f32 s28, s14, s17
 *   @0x16c744 vmul.f32 s18, s11, s25
 *   @0x16c748 vmla.f32 s31, s14, s0
 *   @0x16c74c vstr s18, [sp, #8]
 *   @0x16c750 vmul.f32 s0, s8, s25
 *   @0x16c754 vmul.f32 s30, s12, s17
 *   @0x16c758 vstr s0, [sp, #20]
 *   @0x16c75c vmul.f32 s17, s8, s20
 *   @0x16c760 vmul.f32 s26, s11, s26
 *   @0x16c764 vstr s17, [sp, #16]
 *   @0x16c768 vneg.f32 s3, s20
 *   @0x16c76c vstr s26, [sp, #12]
 *   @0x16c770 vmls.f32 s5, s9, s27
 *   @0x16c774 vldr s27, [sp, #4]
 *   @0x16c778 vmul.f32 s2, s12, s3
 *   @0x16c77c vmul.f32 s17, s10, s19
 *   @0x16c780 vmla.f32 s15, s9, s16
 *   @0x16c784 vmla.f32 s21, s10, s1
 *   @0x16c788 vldr s1, [r0]
 *   @0x16c78c vmul.f32 s16, s10, s27
 *   @0x16c790 vldr s27, [sp, #16]
 *   @0x16c794 vmul.f32 s26, s7, s1
 *   @0x16c798 vmul.f32 s18, s14, s4
 *   @0x16c79c vmul.f32 s0, s10, s4
 *   @0x16c7a0 vmul.f32 s3, s8, s3
 *   @0x16c7a4 vmul.f32 s19, s14, s19
 *   @0x16c7a8 vmul.f32 s1, s11, s24
 *   @0x16c7ac vmul.f32 s25, s7, s25
 *   @0x16c7b0 vmla.f32 s29, s13, s2
 *   @0x16c7b4 vmla.f32 s30, s9, s3
 *   @0x16c7b8 vmul.f32 s2, s10, s24
 *   @0x16c7bc vnmls.f32 s28, s13, s27
 *   @0x16c7c0 vldr s27, [sp, #8]
 *   @0x16c7c4 vnmls.f32 s0, s13, s26
 *   @0x16c7c8 vmla.f32 s17, s13, s27
 *   @0x16c7cc vldr s27, [sp, #4]
 *   @0x16c7d0 vmul.f32 s3, s11, s4
 *   @0x16c7d4 vnmls.f32 s19, s13, s27
 *   @0x16c7d8 vldr s27, [sp, #12]
 *   @0x16c7dc vnmls.f32 s1, s12, s26
 *   @0x16c7e0 vldr s26, [r0, #48]
 *   @0x16c7e4 vnmls.f32 s16, s14, s27
 *   @0x16c7e8 vldr s27, [sp, #20]
 *   @0x16c7ec vmul.f32 s26, s6, s26
 *   @0x16c7f0 vmla.f32 s18, s13, s27
 *   @0x16c7f4 vldr s27, [r0, #48]
 *   @0x16c7f8 vstr s26, [sp, #8]
 *   @0x16c7fc vmul.f32 s27, s7, s27
 *   @0x16c800 vmul.f32 s4, s12, s4
 *   @0x16c804 vstr s27, [sp, #12]
 *   @0x16c808 vldr s27, [r0, #32]
 *   @0x16c80c vmla.f32 s2, s14, s25
 *   @0x16c810 vmla.f32 s3, s9, s25
 *   @0x16c814 vldr s25, [r0, #8]
 *   @0x16c818 vnmls.f32 s4, s9, s24
 *   @0x16c81c vmla.f32 s5, s12, s26
 *   @0x16c820 vldr s26, [r0, #8]
 *   @0x16c824 vmul.f32 s24, s6, s10
 *   @0x16c828 vstr s5, [sp, #48]
 *   @0x16c82c vmul.f32 s25, s11, s25
 *   @0x16c830 vmul.f32 s26, s7, s26
 *   @0x16c834 vstr s25, [sp, #16]
 *   @0x16c838 vldr s25, [r0, #8]
 *   @0x16c83c vmls.f32 s31, s10, s23
 *   @0x16c840 vstr s26, [sp, #20]
 *   @0x16c844 vldr s23, [sp, #12]
 *   @0x16c848 vmls.f32 s15, s12, s24
 *   @0x16c84c vmul.f32 s24, s27, s25
 *   @0x16c850 vstr s15, [sp, #32]
 *   @0x16c854 vmul.f32 s25, s27, s20
 *   @0x16c858 vldr s27, [r0, #8]
 *   @0x16c85c vmul.f32 s26, s22, s27
 *   @0x16c860 vmul.f32 s27, s22, s20
 *   @0x16c864 vmla.f32 s21, s9, s23
 *   @0x16c868 vldr s23, [sp, #16]
 *   @0x16c86c vmla.f32 s18, s13, s26
 *   @0x16c870 vmla.f32 s29, s13, s23
 *   @0x16c874 vldr s23, [sp, #20]
 *   @0x16c878 vmls.f32 s0, s13, s27
 *   @0x16c87c vmla.f32 s30, s9, s23
 *   @0x16c880 vmls.f32 s28, s13, s23
 *   @0x16c884 vmla.f32 s2, s14, s27
 *   @0x16c888 vmla.f32 s3, s9, s27
 *   @0x16c88c vmls.f32 s4, s9, s26
 *   @0x16c890 vmls.f32 s19, s13, s24
 *   @0x16c894 vmla.f32 s17, s13, s25
 *   @0x16c898 vldr s13, [r0, #12]
 *   @0x16c89c vmls.f32 s16, s14, s25
 *   @0x16c8a0 vmls.f32 s1, s12, s27
 *   @0x16c8a4 vldr s27, [r0, #32]
 *   @0x16c8a8 vmul.f32 s5, s5, s20
 *   @0x16c8ac vmul.f32 s23, s27, s13
 *   @0x16c8b0 vldr s27, [sp, #12]
 *   @0x16c8b4 vmls.f32 s31, s12, s27
 *   @0x16c8b8 vldr s27, [r0, #12]
 *   @0x16c8bc vmul.f32 s27, s11, s27
 *   @0x16c8c0 vmul.f32 s22, s22, s13
 *   @0x16c8c4 vstr s27, [sp, #12]
 *   @0x16c8c8 vldr s27, [sp, #8]
 *   @0x16c8cc vmul.f32 s13, s7, s13
 *   @0x16c8d0 vmls.f32 s21, s11, s27
 *   @0x16c8d4 vldr s27, [r0]
 *   @0x16c8d8 vmla.f32 s5, s15, s27
 *   @0x16c8dc vldr s27, [sp, #16]
 *   @0x16c8e0 vstr s21, [sp, #64]
 *   @0x16c8e4 vmla.f32 s28, s14, s13
 *   @0x16c8e8 vmls.f32 s18, s14, s22
 *   @0x16c8ec vmla.f32 s0, s10, s22
 *   @0x16c8f0 vmls.f32 s2, s10, s26
 *   @0x16c8f4 vmls.f32 s30, s12, s13
 *   @0x16c8f8 vldr s13, [sp, #12]
 *   @0x16c8fc vmla.f32 s19, s14, s23
 *   @0x16c900 vmls.f32 s29, s14, s13
 *   @0x16c904 vldr s14, [r0, #48]
 *   @0x16c908 vmls.f32 s17, s10, s23
 *   @0x16c90c vmla.f32 s16, s10, s24
 *   @0x16c910 vmla.f32 s1, s11, s26
 *   @0x16c914 vldr s26, [sp, #28]
 *   @0x16c918 vmls.f32 s3, s11, s22
 *   @0x16c91c vmla.f32 s4, s12, s22
 *   @0x16c920 vldr s22, [r0, #8]
 *   @0x16c924 vmul.f32 s20, s14, s20
 *   @0x16c928 vmul.f32 s13, s10, s22
 *   @0x16c92c vmul.f32 s14, s14, s22
 *   @0x16c930 vmla.f32 s31, s11, s26
 *   @0x16c934 vmla.f32 s5, s21, s22
 *   @0x16c938 vldr s21, [sp, #12]
 *   @0x16c93c vstr s31, [sp, #80]
 *   @0x16c940 vmls.f32 s29, s9, s13
 *   @0x16c944 vmla.f32 s28, s6, s13
 *   @0x16c948 vmls.f32 s30, s6, s27
 *   @0x16c94c vmla.f32 s19, s9, s14
 *   @0x16c950 vmls.f32 s18, s6, s14
 *   @0x16c954 vmls.f32 s17, s9, s20
 *   @0x16c958 vldr s9, [r0, #48]
 *   @0x16c95c vmla.f32 s0, s6, s20
 *   @0x16c960 vmls.f32 s3, s6, s25
 *   @0x16c964 vmla.f32 s4, s6, s24
 *   @0x16c968 vldr s6, [r0, #12]
 *   @0x16c96c vmla.f32 s16, s12, s20
 *   @0x16c970 vmla.f32 s1, s8, s25
 *   @0x16c974 vmls.f32 s2, s8, s20
 *   @0x16c978 vmul.f32 s13, s9, s6
 *   @0x16c97c vmul.f32 s10, s10, s6
 *   @0x16c980 vmla.f32 s5, s31, s6
 *   @0x16c984 vmla.f32 s30, s8, s21
 *   @0x16c988 vmla.f32 s29, s12, s10
 *   @0x16c98c vstr s30, [sp, #44]
 *   @0x16c990 vmls.f32 s28, s8, s10
 *   @0x16c994 vstr s29, [sp, #36]
 *   @0x16c998 vmls.f32 s19, s12, s13
 *   @0x16c99c vstr s28, [sp, #40]
 *   @0x16c9a0 vmla.f32 s18, s8, s13
 *   @0x16c9a4 vstr s19, [sp, #52]
 *   @0x16c9a8 vmla.f32 s17, s11, s13
 *   @0x16c9ac vstr s18, [sp, #56]
 *   @0x16c9b0 vmls.f32 s16, s11, s14
 *   @0x16c9b4 vstr s17, [sp, #68]
 *   @0x16c9b8 vmls.f32 s0, s7, s13
 *   @0x16c9bc vstr s16, [sp, #84]
 *   @0x16c9c0 vmls.f32 s1, s7, s24
 *   @0x16c9c4 vstr s0, [sp, #72]
 *   @0x16c9c8 vmla.f32 s2, s7, s14
 *   @0x16c9cc vstr s1, [sp, #92]
 *   @0x16c9d0 vmla.f32 s3, s7, s23
 *   @0x16c9d4 vstr s2, [sp, #88]
 *   @0x16c9d8 vmls.f32 s4, s8, s23
 *   @0x16c9dc vstr s3, [sp, #76]
 *   @0x16c9e0 vcmp.f32 s5, #0
 *   @0x16c9e4 vstr s4, [sp, #60]
 *   @0x16c9e8 vmrs APSR_nzcv, fpscr
 *   @0x16c9ec moveq r0, #0
 *   @0x16c9f0 beq 0x16ca20 <_ZN8yyMatrix6InvertEv+0x3c4>
 *   @0x16c9f4 vmov.f32 s14, #1.000000e+00
 *   @0x16c9f8 add r3, sp, #36
 *   @0x16c9fc add r2, sp, #96
 *   @0x16ca00 vdiv.f32 s5, s14, s5
 *   @0x16ca04 b 0x16ca0c <_ZN8yyMatrix6InvertEv+0x3b0>
 *   @0x16ca08 vldmia r3!, {s15}
 *   @0x16ca0c vmul.f32 s15, s5, s15
 *   @0x16ca10 cmp r3, r2
 *   @0x16ca14 vstmia r0!, {s15}
 *   @0x16ca18 bne 0x16ca08 <_ZN8yyMatrix6InvertEv+0x3ac>
 *   @0x16ca1c mov r0, #1
 *   @0x16ca20 add sp, sp, #96
 *   @0x16ca24 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x16ca28 bx lr
 *
 * ══ §13/31 OtherToStr  0xf3cf4  size 968  242 条（0xf3cf4..0xf40bc）
 * @func 0xf3cf4 0xf40bc  size 968  242 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x214×1 / 0x20c×1 / 0x204×1 / 0x1fc×1 / 0x1f4×1 / 0x1ec×1 / 0x1e4×1 / 0x1dc×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xf3cf4 cmp r0, #58
 *   @0xf3cf8 addls pc, pc, r0, lsl #2
 *   @0xf3cfc b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d00 b 0xf3dec <_Z10OtherToStri+0xf8>
 *   @0xf3d04 b 0xf3ff0 <_Z10OtherToStri+0x2fc>
 *   @0xf3d08 b 0xf3fe4 <_Z10OtherToStri+0x2f0>
 *   @0xf3d0c b 0xf3fd8 <_Z10OtherToStri+0x2e4>
 *   @0xf3d10 b 0xf3fcc <_Z10OtherToStri+0x2d8>
 *   @0xf3d14 b 0xf3fc0 <_Z10OtherToStri+0x2cc>
 *   @0xf3d18 b 0xf3fb4 <_Z10OtherToStri+0x2c0>
 *   @0xf3d1c b 0xf3fa8 <_Z10OtherToStri+0x2b4>
 *   @0xf3d20 b 0xf3f9c <_Z10OtherToStri+0x2a8>
 *   @0xf3d24 b 0xf3f90 <_Z10OtherToStri+0x29c>
 *   @0xf3d28 b 0xf3f84 <_Z10OtherToStri+0x290>
 *   @0xf3d2c b 0xf3f78 <_Z10OtherToStri+0x284>
 *   @0xf3d30 b 0xf3f6c <_Z10OtherToStri+0x278>
 *   @0xf3d34 b 0xf3f60 <_Z10OtherToStri+0x26c>
 *   @0xf3d38 b 0xf3f54 <_Z10OtherToStri+0x260>
 *   @0xf3d3c b 0xf3f48 <_Z10OtherToStri+0x254>
 *   @0xf3d40 b 0xf3f3c <_Z10OtherToStri+0x248>
 *   @0xf3d44 b 0xf3f30 <_Z10OtherToStri+0x23c>
 *   @0xf3d48 b 0xf3f24 <_Z10OtherToStri+0x230>
 *   @0xf3d4c b 0xf3f18 <_Z10OtherToStri+0x224>
 *   @0xf3d50 b 0xf3f0c <_Z10OtherToStri+0x218>
 *   @0xf3d54 b 0xf3f00 <_Z10OtherToStri+0x20c>
 *   @0xf3d58 b 0xf3ef4 <_Z10OtherToStri+0x200>
 *   @0xf3d5c b 0xf3ee8 <_Z10OtherToStri+0x1f4>
 *   @0xf3d60 b 0xf3edc <_Z10OtherToStri+0x1e8>
 *   @0xf3d64 b 0xf3ed0 <_Z10OtherToStri+0x1dc>
 *   @0xf3d68 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d6c b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d70 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d74 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d78 b 0xf3ec4 <_Z10OtherToStri+0x1d0>
 *   @0xf3d7c b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d80 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d84 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d88 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d8c b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d90 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d94 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d98 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3d9c b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3da0 b 0xf3eb8 <_Z10OtherToStri+0x1c4>
 *   @0xf3da4 b 0xf3eac <_Z10OtherToStri+0x1b8>
 *   @0xf3da8 b 0xf3ea0 <_Z10OtherToStri+0x1ac>
 *   @0xf3dac b 0xf3e94 <_Z10OtherToStri+0x1a0>
 *   @0xf3db0 b 0xf3e88 <_Z10OtherToStri+0x194>
 *   @0xf3db4 b 0xf3e7c <_Z10OtherToStri+0x188>
 *   @0xf3db8 b 0xf3e70 <_Z10OtherToStri+0x17c>
 *   @0xf3dbc b 0xf3e64 <_Z10OtherToStri+0x170>
 *   @0xf3dc0 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3dc4 b 0xf3ffc <_Z10OtherToStri+0x308>
 *   @0xf3dc8 b 0xf3e58 <_Z10OtherToStri+0x164>
 *   @0xf3dcc b 0xf3e4c <_Z10OtherToStri+0x158>
 *   @0xf3dd0 b 0xf3e40 <_Z10OtherToStri+0x14c>
 *   @0xf3dd4 b 0xf3e34 <_Z10OtherToStri+0x140>
 *   @0xf3dd8 b 0xf3e28 <_Z10OtherToStri+0x134>
 *   @0xf3ddc b 0xf3e1c <_Z10OtherToStri+0x128>
 *   @0xf3de0 b 0xf3e10 <_Z10OtherToStri+0x11c>
 *   @0xf3de4 b 0xf3e04 <_Z10OtherToStri+0x110>
 *   @0xf3de8 b 0xf3df8 <_Z10OtherToStri+0x104>
 *   @0xf3dec ldr r0, [pc, #0x214]
 *   @0xf3df0 add r0, pc, r0
 *   @0xf3df4 bx lr
 *   @0xf3df8 ldr r0, [pc, #0x20c]
 *   @0xf3dfc add r0, pc, r0
 *   @0xf3e00 bx lr
 *   @0xf3e04 ldr r0, [pc, #0x204]
 *   @0xf3e08 add r0, pc, r0
 *   @0xf3e0c bx lr
 *   @0xf3e10 ldr r0, [pc, #0x1fc]
 *   @0xf3e14 add r0, pc, r0
 *   @0xf3e18 bx lr
 *   @0xf3e1c ldr r0, [pc, #0x1f4]
 *   @0xf3e20 add r0, pc, r0
 *   @0xf3e24 bx lr
 *   @0xf3e28 ldr r0, [pc, #0x1ec]
 *   @0xf3e2c add r0, pc, r0
 *   @0xf3e30 bx lr
 *   @0xf3e34 ldr r0, [pc, #0x1e4]
 *   @0xf3e38 add r0, pc, r0
 *   @0xf3e3c bx lr
 *   @0xf3e40 ldr r0, [pc, #0x1dc]
 *   @0xf3e44 add r0, pc, r0
 *   @0xf3e48 bx lr
 *   @0xf3e4c ldr r0, [pc, #0x1d4]
 *   @0xf3e50 add r0, pc, r0
 *   @0xf3e54 bx lr
 *   @0xf3e58 ldr r0, [pc, #0x1cc]
 *   @0xf3e5c add r0, pc, r0
 *   @0xf3e60 bx lr
 *   @0xf3e64 ldr r0, [pc, #0x1c4]
 *   @0xf3e68 add r0, pc, r0
 *   @0xf3e6c bx lr
 *   @0xf3e70 ldr r0, [pc, #0x1bc]
 *   @0xf3e74 add r0, pc, r0
 *   @0xf3e78 bx lr
 *   @0xf3e7c ldr r0, [pc, #0x1b4]
 *   @0xf3e80 add r0, pc, r0
 *   @0xf3e84 bx lr
 *   @0xf3e88 ldr r0, [pc, #0x1ac]
 *   @0xf3e8c add r0, pc, r0
 *   @0xf3e90 bx lr
 *   @0xf3e94 ldr r0, [pc, #0x1a4]
 *   @0xf3e98 add r0, pc, r0
 *   @0xf3e9c bx lr
 *   @0xf3ea0 ldr r0, [pc, #0x19c]
 *   @0xf3ea4 add r0, pc, r0
 *   @0xf3ea8 bx lr
 *   @0xf3eac ldr r0, [pc, #0x194]
 *   @0xf3eb0 add r0, pc, r0
 *   @0xf3eb4 bx lr
 *   @0xf3eb8 ldr r0, [pc, #0x18c]
 *   @0xf3ebc add r0, pc, r0
 *   @0xf3ec0 bx lr
 *   @0xf3ec4 ldr r0, [pc, #0x184]
 *   @0xf3ec8 add r0, pc, r0
 *   @0xf3ecc bx lr
 *   @0xf3ed0 ldr r0, [pc, #0x17c]
 *   @0xf3ed4 add r0, pc, r0
 *   @0xf3ed8 bx lr
 *   @0xf3edc ldr r0, [pc, #0x174]
 *   @0xf3ee0 add r0, pc, r0
 *   @0xf3ee4 bx lr
 *   @0xf3ee8 ldr r0, [pc, #0x16c]
 *   @0xf3eec add r0, pc, r0
 *   @0xf3ef0 bx lr
 *   @0xf3ef4 ldr r0, [pc, #0x164]
 *   @0xf3ef8 add r0, pc, r0
 *   @0xf3efc bx lr
 *   @0xf3f00 ldr r0, [pc, #0x15c]
 *   @0xf3f04 add r0, pc, r0
 *   @0xf3f08 bx lr
 *   @0xf3f0c ldr r0, [pc, #0x154]
 *   @0xf3f10 add r0, pc, r0
 *   @0xf3f14 bx lr
 *   @0xf3f18 ldr r0, [pc, #0x14c]
 *   @0xf3f1c add r0, pc, r0
 *   @0xf3f20 bx lr
 *   @0xf3f24 ldr r0, [pc, #0x144]
 *   @0xf3f28 add r0, pc, r0
 *   @0xf3f2c bx lr
 *   @0xf3f30 ldr r0, [pc, #0x13c]
 *   @0xf3f34 add r0, pc, r0
 *   @0xf3f38 bx lr
 *   @0xf3f3c ldr r0, [pc, #0x134]
 *   @0xf3f40 add r0, pc, r0
 *   @0xf3f44 bx lr
 *   @0xf3f48 ldr r0, [pc, #0x12c]
 *   @0xf3f4c add r0, pc, r0
 *   @0xf3f50 bx lr
 *   @0xf3f54 ldr r0, [pc, #0x124]
 *   @0xf3f58 add r0, pc, r0
 *   @0xf3f5c bx lr
 *   @0xf3f60 ldr r0, [pc, #0x11c]
 *   @0xf3f64 add r0, pc, r0
 *   @0xf3f68 bx lr
 *   @0xf3f6c ldr r0, [pc, #0x114]
 *   @0xf3f70 add r0, pc, r0
 *   @0xf3f74 bx lr
 *   @0xf3f78 ldr r0, [pc, #0x10c]
 *   @0xf3f7c add r0, pc, r0
 *   @0xf3f80 bx lr
 *   @0xf3f84 ldr r0, [pc, #0x104]
 *   @0xf3f88 add r0, pc, r0
 *   @0xf3f8c bx lr
 *   @0xf3f90 ldr r0, [pc, #0xfc]
 *   @0xf3f94 add r0, pc, r0
 *   @0xf3f98 bx lr
 *   @0xf3f9c ldr r0, [pc, #0xf4]
 *   @0xf3fa0 add r0, pc, r0
 *   @0xf3fa4 bx lr
 *   @0xf3fa8 ldr r0, [pc, #0xec]
 *   @0xf3fac add r0, pc, r0
 *   @0xf3fb0 bx lr
 *   @0xf3fb4 ldr r0, [pc, #0xe4]
 *   @0xf3fb8 add r0, pc, r0
 *   @0xf3fbc bx lr
 *   @0xf3fc0 ldr r0, [pc, #0xdc]
 *   @0xf3fc4 add r0, pc, r0
 *   @0xf3fc8 bx lr
 *   @0xf3fcc ldr r0, [pc, #0xd4]
 *   @0xf3fd0 add r0, pc, r0
 *   @0xf3fd4 bx lr
 *   @0xf3fd8 ldr r0, [pc, #0xcc]
 *   @0xf3fdc add r0, pc, r0
 *   @0xf3fe0 bx lr
 *   @0xf3fe4 ldr r0, [pc, #0xc4]
 *   @0xf3fe8 add r0, pc, r0
 *   @0xf3fec bx lr
 *   @0xf3ff0 ldr r0, [pc, #0xbc]
 *   @0xf3ff4 add r0, pc, r0
 *   @0xf3ff8 bx lr
 *   @0xf3ffc ldr r0, [pc, #0xb4]
 *   @0xf4000 add r0, pc, r0
 *   @0xf4004 bx lr
 *   @0xf4008 eoreq r3, r4, r8, ror r6
 *   @0xf400c eoreq r3, r4, r12, lsl #18
 *   @0xf4010 .word 0x002438f0
 *   @0xf4014 .word 0x002438d4
 *   @0xf4018 .word 0x002438b8
 *   @0xf401c mlaeq r4, r12, r8, r3
 *   @0xf4020 eoreq r3, r4, r0, lsl #17
 *   @0xf4024 eoreq r3, r4, r4, ror #16
 *   @0xf4028 eoreq r3, r4, r8, asr #16
 *   @0xf402c eoreq r3, r4, r12, lsr #16
 *   @0xf4030 eoreq r3, r4, r0, lsl r8
 *   @0xf4034 .word 0x002437f4
 *   @0xf4038 .word 0x002437d8
 *   @0xf403c .word 0x002437bc
 *   @0xf4040 eoreq r3, r4, r0, lsr #15
 *   @0xf4044 eoreq r3, r4, r4, lsl #15
 *   @0xf4048 eoreq r3, r4, r8, ror #14
 *   @0xf404c eoreq r3, r4, r12, asr #14
 *   @0xf4050 eoreq r3, r4, r0, lsr r7
 *   @0xf4054 eoreq r3, r4, r4, lsl r7
 *   @0xf4058 .word 0x002436f8
 *   @0xf405c .word 0x002436dc
 *   @0xf4060 eoreq r3, r4, r0, asr #13
 *   @0xf4064 eoreq r3, r4, r4, lsr #13
 *   @0xf4068 eoreq r3, r4, r8, lsl #13
 *   @0xf406c eoreq r3, r4, r12, ror #12
 *   @0xf4070 eoreq r3, r4, r0, asr r6
 *   @0xf4074 eoreq r3, r4, r4, lsr r6
 *   @0xf4078 eoreq r3, r4, r8, lsl r6
 *   @0xf407c .word 0x002435fc
 *   @0xf4080 eoreq r3, r4, r0, ror #11
 *   @0xf4084 eoreq r3, r4, r4, asr #11
 *   @0xf4088 eoreq r3, r4, r8, lsr #11
 *   @0xf408c eoreq r3, r4, r12, lsl #11
 *   @0xf4090 eoreq r3, r4, r0, ror r5
 *   @0xf4094 eoreq r3, r4, r4, asr r5
 *   @0xf4098 eoreq r3, r4, r12, lsr r5
 *   @0xf409c eoreq r3, r4, r0, lsr #10
 *   @0xf40a0 eoreq r3, r4, r4, lsl #10
 *   @0xf40a4 eoreq r3, r4, r12, ror #9
 *   @0xf40a8 .word 0x002434d4
 *   @0xf40ac .word 0x002434bc
 *   @0xf40b0 eoreq r3, r4, r4, lsr #9
 *   @0xf40b4 eoreq r3, r4, r4, lsl #9
 *   @0xf40b8 .word 0x00242ff4
 *
 * ══ §14/31 Ext_Call  0x214a18  size 964  241 条（0x214a18..0x214ddc）
 * @func 0x214a18 0x214ddc  size 964  241 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x214a28→0x483664, 0x214b60→0x3eb708, 0x214bf0→0x756d44, 0x214bf4→0x756d1c
 * 调用序列: getJNIEnv×16 / CExtensionFunction::GetArgCount()×3 / CExtensionPackage::GetClassName() / CExtensionFunction::GetExternalName() / Ext_Call(int, int, RValue*, RValue*)+0x1d4 / YYGetReal(RValue const*, int) / _JNIEnv::CallStaticObjectMethod(_jclass*, _jmethodID*, ...) / CExtensionFunction::GetReturnType()
 * 字段偏移 top8: 0x1c×7 / 0x5c×6 / 0x28×5 / 0x18×5 / 0xc×5 / 0x14×4 / 0x24×4 / 0x29c×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x214a18 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x214a1c mov r6, r1
 *   @0x214a20 ldr r9, [pc, #0x394]
 *   @0x214a24 sub sp, sp, #60
 *   @0x214a28 ldr r1, [pc, #0x390]
 *   @0x214a2c mov r7, r2
 *   @0x214a30 add r9, pc, r9
 *   @0x214a34 str r3, [sp, #0x28]
 *   @0x214a38 ldr r3, [r9, r1]
 *   @0x214a3c ldr r3, [r3]
 *   @0x214a40 ldr r3, [r3, r0, lsl #2]
 *   @0x214a44 str r3, [sp, #0x1c]
 *   @0x214a48 bl 0x290274 <getJNIEnv>
 *   @0x214a4c ldr r11, [sp, #0x1c]
 *   @0x214a50 mov r4, r0
 *   @0x214a54 ldr r0, [r11, #0x60]
 *   @0x214a58 bl 0xf55c8 <_ZN17CExtensionPackage12GetClassNameEv>
 *   @0x214a5c ldr r3, [r4]
 *   @0x214a60 ldr r3, [r3, #0x29c]
 *   @0x214a64 mov r1, r0
 *   @0x214a68 mov r0, r4
 *   @0x214a6c blx r3
 *   @0x214a70 str r0, [sp, #0x14]
 *   @0x214a74 bl 0x290274 <getJNIEnv>
 *   @0x214a78 mov r4, r0
 *   @0x214a7c ldr r0, [sp, #0x1c]
 *   @0x214a80 bl 0xf4be4 <_ZN18CExtensionFunction15GetExternalNameEv>
 *   @0x214a84 ldr r3, [r4]
 *   @0x214a88 ldr r3, [r3, #0x29c]
 *   @0x214a8c mov r1, r0
 *   @0x214a90 mov r0, r4
 *   @0x214a94 blx r3
 *   @0x214a98 str r0, [sp, #0x18]
 *   @0x214a9c bl 0x290274 <getJNIEnv>
 *   @0x214aa0 mov r4, r0
 *   @0x214aa4 ldr r0, [sp, #0x1c]
 *   @0x214aa8 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0x214aac ldr r3, [r4]
 *   @0x214ab0 ldr r3, [r3, #0x2d8]
 *   @0x214ab4 mov r1, r0
 *   @0x214ab8 mov r0, r4
 *   @0x214abc blx r3
 *   @0x214ac0 mov r8, r0
 *   @0x214ac4 bl 0x290274 <getJNIEnv>
 *   @0x214ac8 ldr r1, [pc, #0x2f4]
 *   @0x214acc add r1, pc, r1
 *   @0x214ad0 ldr r3, [r0]
 *   @0x214ad4 ldr r3, [r3, #0x18]
 *   @0x214ad8 blx r3
 *   @0x214adc mov r5, r0
 *   @0x214ae0 bl 0x290274 <getJNIEnv>
 *   @0x214ae4 mov r4, r0
 *   @0x214ae8 ldr r0, [sp, #0x1c]
 *   @0x214aec bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0x214af0 ldr r12, [r4]
 *   @0x214af4 mov r2, r5
 *   @0x214af8 mov r3, #0
 *   @0x214afc ldr r12, [r12, #0x2b0]
 *   @0x214b00 mov r1, r0
 *   @0x214b04 mov r0, r4
 *   @0x214b08 blx r12
 *   @0x214b0c cmp r6, #0
 *   @0x214b10 str r0, [sp, #0x24]
 *   @0x214b14 ble 0x214bec <_Z8Ext_CalliiP6RValueS0_+0x1d4>
 *   @0x214b18 ldr r12, [pc, #0x2a8]
 *   @0x214b1c add r10, sp, #48
 *   @0x214b20 ldr r11, [pc, #0x2a4]
 *   @0x214b24 mov r5, r7
 *   @0x214b28 add r12, pc, r12
 *   @0x214b2c mov r4, #0
 *   @0x214b30 add r11, pc, r11
 *   @0x214b34 str r12, [sp, #0x20]
 *   @0x214b38 str r11, [sp, #0x2c]
 *   @0x214b3c b 0x214b9c <_Z8Ext_CalliiP6RValueS0_+0x184>
 *   @0x214b40 cmp r12, #7
 *   @0x214b44 beq 0x214bac <_Z8Ext_CalliiP6RValueS0_+0x194>
 *   @0x214b48 cmp r12, #13
 *   @0x214b4c beq 0x214bac <_Z8Ext_CalliiP6RValueS0_+0x194>
 *   @0x214b50 cmp r12, #1
 *   @0x214b54 beq 0x214d64 <_Z8Ext_CalliiP6RValueS0_+0x34c>
 *   @0x214b58 cmp r12, #3
 *   @0x214b5c beq 0x214cec <_Z8Ext_CalliiP6RValueS0_+0x2d4>
 *   @0x214b60 ldr r0, [pc, #0x268]
 *   @0x214b64 mov r2, r4
 *   @0x214b68 ldr r11, [sp, #0x18]
 *   @0x214b6c ldr r1, [sp, #0x20]
 *   @0x214b70 ldr r0, [r9, r0]
 *   @0x214b74 ldr r3, [sp, #0x14]
 *   @0x214b78 ldr r0, [r0]
 *   @0x214b7c ldr lr, [r0]
 *   @0x214b80 stm sp, {r11, r12}
 *   @0x214b84 ldr r12, [lr, #0xc]
 *   @0x214b88 blx r12
 *   @0x214b8c add r4, r4, #1
 *   @0x214b90 add r5, r5, #16
 *   @0x214b94 cmp r4, r6
 *   @0x214b98 beq 0x214bec <_Z8Ext_CalliiP6RValueS0_+0x1d4>
 *   @0x214b9c ldr r12, [r5, #0xc]
 *   @0x214ba0 cmp r12, #10
 *   @0x214ba4 cmpne r12, #0
 *   @0x214ba8 bne 0x214b40 <_Z8Ext_CalliiP6RValueS0_+0x128>
 *   @0x214bac mov r1, r4
 *   @0x214bb0 mov r0, r7
 *   @0x214bb4 bl 0xceb24 <_Z9YYGetRealPK6RValuei>
 *   @0x214bb8 add r5, r5, #16
 *   @0x214bbc strd r0, r1, [sp, #48]
 *   @0x214bc0 bl 0x290274 <getJNIEnv>
 *   @0x214bc4 mov r2, r4
 *   @0x214bc8 mov r1, r8
 *   @0x214bcc mov r3, #1
 *   @0x214bd0 add r4, r4, #1
 *   @0x214bd4 ldr r12, [r0]
 *   @0x214bd8 str r10, [sp]
 *   @0x214bdc ldr r12, [r12, #0x358]
 *   @0x214be0 blx r12
 *   @0x214be4 cmp r4, r6
 *   @0x214be8 bne 0x214b9c <_Z8Ext_CalliiP6RValueS0_+0x184>
 *   @0x214bec bl 0x290274 <getJNIEnv>
 *   @0x214bf0 ldr r2, [pc, #0x1dc]
 *   @0x214bf4 ldr r3, [pc, #0x1dc]
 *   @0x214bf8 ldr r2, [r9, r2]
 *   @0x214bfc ldr r3, [r9, r3]
 *   @0x214c00 ldr r6, [r2]
 *   @0x214c04 ldr r5, [r3]
 *   @0x214c08 mov r4, r0
 *   @0x214c0c ldr r0, [sp, #0x1c]
 *   @0x214c10 bl 0xf4c38 <_ZN18CExtensionFunction11GetArgCountEv>
 *   @0x214c14 ldr r12, [sp, #0x18]
 *   @0x214c18 ldr r11, [sp, #0x24]
 *   @0x214c1c mov r2, r5
 *   @0x214c20 ldr r3, [sp, #0x14]
 *   @0x214c24 mov r1, r6
 *   @0x214c28 str r12, [sp]
 *   @0x214c2c str r8, [sp, #0x8]
 *   @0x214c30 str r11, [sp, #0xc]
 *   @0x214c34 str r0, [sp, #0x4]
 *   @0x214c38 mov r0, r4
 *   @0x214c3c bl 0xf2840 <_ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz>
 *   @0x214c40 mov r4, r0
 *   @0x214c44 bl 0x290274 <getJNIEnv>
 *   @0x214c48 ldr r1, [sp, #0x14]
 *   @0x214c4c ldr r3, [r0]
 *   @0x214c50 ldr r3, [r3, #0x5c]
 *   @0x214c54 blx r3
 *   @0x214c58 bl 0x290274 <getJNIEnv>
 *   @0x214c5c ldr r1, [sp, #0x18]
 *   @0x214c60 ldr r3, [r0]
 *   @0x214c64 ldr r3, [r3, #0x5c]
 *   @0x214c68 blx r3
 *   @0x214c6c bl 0x290274 <getJNIEnv>
 *   @0x214c70 mov r1, r8
 *   @0x214c74 ldr r3, [r0]
 *   @0x214c78 ldr r3, [r3, #0x5c]
 *   @0x214c7c blx r3
 *   @0x214c80 bl 0x290274 <getJNIEnv>
 *   @0x214c84 ldr r1, [sp, #0x24]
 *   @0x214c88 ldr r3, [r0]
 *   @0x214c8c ldr r3, [r3, #0x5c]
 *   @0x214c90 blx r3
 *   @0x214c94 cmp r4, #0
 *   @0x214c98 beq 0x214dac <_Z8Ext_CalliiP6RValueS0_+0x394>
 *   @0x214c9c ldr r0, [sp, #0x1c]
 *   @0x214ca0 bl 0xf4c48 <_ZN18CExtensionFunction13GetReturnTypeEv>
 *   @0x214ca4 cmp r0, #1
 *   @0x214ca8 beq 0x214d94 <_Z8Ext_CalliiP6RValueS0_+0x37c>
 *   @0x214cac cmp r0, #2
 *   @0x214cb0 bne 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8>
 *   @0x214cb4 ldr r12, [sp, #0x28]
 *   @0x214cb8 mov r3, #0
 *   @0x214cbc mov r0, r4
 *   @0x214cc0 str r3, [r12, #0xc]
 *   @0x214cc4 bl 0x214968 <_Z18GetJObjectToDoubleP8_jobject>
 *   @0x214cc8 ldr r11, [sp, #0x28]
 *   @0x214ccc stm r11, {r0, r1}
 *   @0x214cd0 bl 0x290274 <getJNIEnv>
 *   @0x214cd4 mov r1, r4
 *   @0x214cd8 ldr r3, [r0]
 *   @0x214cdc ldr r3, [r3, #0x5c]
 *   @0x214ce0 blx r3
 *   @0x214ce4 add sp, sp, #60
 *   @0x214ce8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x214cec mov r1, r4
 *   @0x214cf0 mov r0, r7
 *   @0x214cf4 bl 0xcec18 <_Z8YYGetPtrPK6RValuei>
 *   @0x214cf8 mov r11, r0
 *   @0x214cfc bl 0xc6754 <_Z10GetIBufferPv>
 *   @0x214d00 subs r3, r0, #0
 *   @0x214d04 beq 0x214b8c <_Z8Ext_CalliiP6RValueS0_+0x174>
 *   @0x214d08 str r3, [sp, #0x10]
 *   @0x214d0c bl 0x290274 <getJNIEnv>
 *   @0x214d10 ldr r3, [sp, #0x10]
 *   @0x214d14 mov r1, r11
 *   @0x214d18 ldr r2, [r3, #0x10]
 *   @0x214d1c asr r3, r2, #31
 *   @0x214d20 ldr r12, [r0]
 *   @0x214d24 ldr r12, [r12, #0x394]
 *   @0x214d28 blx r12
 *   @0x214d2c mov r11, r0
 *   @0x214d30 bl 0x290274 <getJNIEnv>
 *   @0x214d34 mov r3, r11
 *   @0x214d38 ldr r1, [sp, #0x24]
 *   @0x214d3c mov r2, r4
 *   @0x214d40 ldr r12, [r0]
 *   @0x214d44 ldr r12, [r12, #0x2b8]
 *   @0x214d48 blx r12
 *   @0x214d4c bl 0x290274 <getJNIEnv>
 *   @0x214d50 mov r1, r11
 *   @0x214d54 ldr r3, [r0]
 *   @0x214d58 ldr r3, [r3, #0x5c]
 *   @0x214d5c blx r3
 *   @0x214d60 b 0x214b8c <_Z8Ext_CalliiP6RValueS0_+0x174>
 *   @0x214d64 mov r1, r4
 *   @0x214d68 mov r0, r7
 *   @0x214d6c bl 0xd04d0 <_Z11YYGetStringPK6RValuei>
 *   @0x214d70 ldr r12, [sp, #0x2c]
 *   @0x214d74 subs r11, r0, #0
 *   @0x214d78 moveq r11, r12
 *   @0x214d7c bl 0x290274 <getJNIEnv>
 *   @0x214d80 mov r1, r11
 *   @0x214d84 ldr r3, [r0]
 *   @0x214d88 ldr r3, [r3, #0x29c]
 *   @0x214d8c blx r3
 *   @0x214d90 b 0x214d2c <_Z8Ext_CalliiP6RValueS0_+0x314>
 *   @0x214d94 mov r0, r4
 *   @0x214d98 bl 0x214908 <_Z18GetJObjectToStringP8_jobject>
 *   @0x214d9c mov r1, r0
 *   @0x214da0 ldr r0, [sp, #0x28]
 *   @0x214da4 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x214da8 b 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8>
 *   @0x214dac ldr r12, [sp, #0x28]
 *   @0x214db0 mov r3, #5
 *   @0x214db4 str r3, [r12, #0xc]
 *   @0x214db8 b 0x214cd0 <_Z8Ext_CalliiP6RValueS0_+0x2b8>
 *   @0x214dbc andseq sp, sp, r0, lsr #4
 *   @0x214dc0 .word 0xffffc1f0
 *   @0x214dc4 andseq lr, r3, r12, lsl pc
 *   @0x214dc8 ldrsbeq lr, [r3], -r4
 *   @0x214dcc andseq r10, r1, r6
 *   @0x214dd0 .word 0xffffbcf0
 *   @0x214dd4 .word 0xffffbd54
 *   @0x214dd8 .word 0xfffff76c
 *
 * ══ §15/31 CDS_Map::Add  0x20b884  size 960  240 条（0x20b884..0x20bc44）
 * @func 0x20b884 0x20bc44  size 960  240 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65b0×2 / FREE_RValue__Pre(RValue*)×2 / CalcCRC(char const*, int)×2 / GetContextStackTop()×2 / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*)×2 / CalcCRC_string(char const*) / CDS_Map::Add(RValue*, RValue*)+0x21c / operator new(unsigned int)
 * 字段偏移 top8: 0xc×9 / 0x8×9 / 0x10×5 / 0x1c×3 / 0x18×2 / 0x14×1 / 0x64×1 / 0x3×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x20b884 ldr r3, [r1, #0xc]
 *   @0x20b888 push {r4, r5, r6, r7, r8, r9, lr}
 *   @0x20b88c bic r3, r3, #-16777216
 *   @0x20b890 cmp r3, #6
 *   @0x20b894 sub sp, sp, #12
 *   @0x20b898 mov r6, r1
 *   @0x20b89c mov r8, r0
 *   @0x20b8a0 mov r7, r2
 *   @0x20b8a4 beq 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258>
 *   @0x20b8a8 bgt 0x20b8dc <_ZN7CDS_Map3AddEP6RValueS1_+0x58>
 *   @0x20b8ac cmp r3, #4
 *   @0x20b8b0 bgt 0x20b8f4 <_ZN7CDS_Map3AddEP6RValueS1_+0x70>
 *   @0x20b8b4 cmp r3, #2
 *   @0x20b8b8 bge 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258>
 *   @0x20b8bc cmp r3, #1
 *   @0x20b8c0 bne 0x20baac <_ZN7CDS_Map3AddEP6RValueS1_+0x228>
 *   @0x20b8c4 ldr r0, [r1]
 *   @0x20b8c8 cmp r0, #0
 *   @0x20b8cc ldrne r0, [r0]
 *   @0x20b8d0 bl 0x27dfa8 <_Z14CalcCRC_stringPKc>
 *   @0x20b8d4 mov r9, r0
 *   @0x20b8d8 b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74>
 *   @0x20b8dc cmp r3, #11
 *   @0x20b8e0 beq 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258>
 *   @0x20b8e4 ble 0x20baa0 <_ZN7CDS_Map3AddEP6RValueS1_+0x21c>
 *   @0x20b8e8 mvn r2, #-16777216
 *   @0x20b8ec cmp r3, r2
 *   @0x20b8f0 bne 0x20baac <_ZN7CDS_Map3AddEP6RValueS1_+0x228>
 *   @0x20b8f4 mov r9, #0
 *   @0x20b8f8 mov r0, #32
 *   @0x20b8fc bl 0x27c524 <_Znwj>
 *   @0x20b900 mov r1, #0
 *   @0x20b904 mov r2, #16
 *   @0x20b908 add r5, r0, #16
 *   @0x20b90c mov r4, r0
 *   @0x20b910 bl 0xb65b0 <memset@plt>
 *   @0x20b914 mov r1, #0
 *   @0x20b918 mov r0, r5
 *   @0x20b91c mov r2, #16
 *   @0x20b920 bl 0xb65b0 <memset@plt>
 *   @0x20b924 ldr r3, [r4, #0xc]
 *   @0x20b928 sub r3, r3, #1
 *   @0x20b92c bic r3, r3, #-16777216
 *   @0x20b930 bic r3, r3, #3
 *   @0x20b934 cmp r3, #0
 *   @0x20b938 beq 0x20ba94 <_ZN7CDS_Map3AddEP6RValueS1_+0x210>
 *   @0x20b93c mov r3, #5
 *   @0x20b940 str r3, [r4, #0xc]
 *   @0x20b944 ldr r3, [r6, #0xc]
 *   @0x20b948 mov r2, #0
 *   @0x20b94c str r2, [r4, #0x8]
 *   @0x20b950 ldr r1, [r6, #0x8]
 *   @0x20b954 str r3, [r4, #0xc]
 *   @0x20b958 ldr r3, [r6, #0xc]
 *   @0x20b95c str r2, [r4]
 *   @0x20b960 bic r3, r3, #-16777216
 *   @0x20b964 str r1, [r4, #0x8]
 *   @0x20b968 cmp r3, #14
 *   @0x20b96c addls pc, pc, r3, lsl #2
 *   @0x20b970 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b974 b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8>
 *   @0x20b978 b 0x20bb14 <_ZN7CDS_Map3AddEP6RValueS1_+0x290>
 *   @0x20b97c b 0x20bb94 <_ZN7CDS_Map3AddEP6RValueS1_+0x310>
 *   @0x20b980 b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c>
 *   @0x20b984 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b988 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b98c b 0x20bb70 <_ZN7CDS_Map3AddEP6RValueS1_+0x2ec>
 *   @0x20b990 b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c>
 *   @0x20b994 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b998 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b99c b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8>
 *   @0x20b9a0 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b9a4 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20b9a8 b 0x20ba7c <_ZN7CDS_Map3AddEP6RValueS1_+0x1f8>
 *   @0x20b9ac b 0x20b9b0 <_ZN7CDS_Map3AddEP6RValueS1_+0x12c>
 *   @0x20b9b0 ldr r3, [r6]
 *   @0x20b9b4 str r3, [r4]
 *   @0x20b9b8 ldr r3, [r4, #0x1c]
 *   @0x20b9bc sub r3, r3, #1
 *   @0x20b9c0 bic r3, r3, #-16777216
 *   @0x20b9c4 bic r3, r3, #3
 *   @0x20b9c8 cmp r3, #0
 *   @0x20b9cc beq 0x20ba88 <_ZN7CDS_Map3AddEP6RValueS1_+0x204>
 *   @0x20b9d0 mov r3, #5
 *   @0x20b9d4 str r3, [r4, #0x1c]
 *   @0x20b9d8 ldr r3, [r7, #0xc]
 *   @0x20b9dc mov r2, #0
 *   @0x20b9e0 str r2, [r4, #0x18]
 *   @0x20b9e4 ldr r1, [r7, #0x8]
 *   @0x20b9e8 str r3, [r4, #0x1c]
 *   @0x20b9ec ldr r3, [r7, #0xc]
 *   @0x20b9f0 str r2, [r4, #0x10]
 *   @0x20b9f4 bic r3, r3, #-16777216
 *   @0x20b9f8 str r1, [r4, #0x18]
 *   @0x20b9fc cmp r3, #14
 *   @0x20ba00 addls pc, pc, r3, lsl #2
 *   @0x20ba04 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba08 b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8>
 *   @0x20ba0c b 0x20bb58 <_ZN7CDS_Map3AddEP6RValueS1_+0x2d4>
 *   @0x20ba10 b 0x20bb2c <_ZN7CDS_Map3AddEP6RValueS1_+0x2a8>
 *   @0x20ba14 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0>
 *   @0x20ba18 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba1c b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba20 b 0x20baf0 <_ZN7CDS_Map3AddEP6RValueS1_+0x26c>
 *   @0x20ba24 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0>
 *   @0x20ba28 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba2c b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba30 b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8>
 *   @0x20ba34 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba38 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba3c b 0x20ba6c <_ZN7CDS_Map3AddEP6RValueS1_+0x1e8>
 *   @0x20ba40 b 0x20ba44 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c0>
 *   @0x20ba44 ldr r3, [r7]
 *   @0x20ba48 str r3, [r4, #0x10]
 *   @0x20ba4c mov r1, r6
 *   @0x20ba50 mov r0, r8
 *   @0x20ba54 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x20ba58 subs r5, r0, #0
 *   @0x20ba5c movne r0, #0
 *   @0x20ba60 beq 0x20bbcc <_ZN7CDS_Map3AddEP6RValueS1_+0x348>
 *   @0x20ba64 add sp, sp, #12
 *   @0x20ba68 pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20ba6c ldm r7, {r2, r3}
 *   @0x20ba70 str r2, [r4, #0x10]
 *   @0x20ba74 str r3, [r4, #0x14]
 *   @0x20ba78 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20ba7c ldm r6, {r2, r3}
 *   @0x20ba80 stm r4, {r2, r3}
 *   @0x20ba84 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20ba88 mov r0, r5
 *   @0x20ba8c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ba90 b 0x20b9d0 <_ZN7CDS_Map3AddEP6RValueS1_+0x14c>
 *   @0x20ba94 mov r0, r4
 *   @0x20ba98 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x20ba9c b 0x20b93c <_ZN7CDS_Map3AddEP6RValueS1_+0xb8>
 *   @0x20baa0 sub r2, r3, #8
 *   @0x20baa4 cmp r2, #1
 *   @0x20baa8 bls 0x20badc <_ZN7CDS_Map3AddEP6RValueS1_+0x258>
 *   @0x20baac cmp r3, #0
 *   @0x20bab0 bne 0x20bbc0 <_ZN7CDS_Map3AddEP6RValueS1_+0x33c>
 *   @0x20bab4 ldm r6, {r0, r1}
 *   @0x20bab8 mov r4, r0
 *   @0x20babc add r0, sp, #8
 *   @0x20bac0 mov r5, r1
 *   @0x20bac4 mov r1, #8
 *   @0x20bac8 strd r4, r5, [r0, #-8]!
 *   @0x20bacc mov r0, sp
 *   @0x20bad0 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20bad4 mov r9, r0
 *   @0x20bad8 b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74>
 *   @0x20badc mov r0, r6
 *   @0x20bae0 mov r1, #8
 *   @0x20bae4 bl 0x27dfa0 <_Z7CalcCRCPKci>
 *   @0x20bae8 mov r9, r0
 *   @0x20baec b 0x20b8f8 <_ZN7CDS_Map3AddEP6RValueS1_+0x74>
 *   @0x20baf0 ldr r3, [r7]
 *   @0x20baf4 str r3, [r4, #0x10]
 *   @0x20baf8 ldr r3, [r7]
 *   @0x20bafc cmp r3, #0
 *   @0x20bb00 beq 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20bb04 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20bb08 ldr r1, [r7]
 *   @0x20bb0c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20bb10 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20bb14 ldr r3, [r6]
 *   @0x20bb18 cmp r3, #0
 *   @0x20bb1c ldrne r2, [r3, #0x4]
 *   @0x20bb20 addne r2, r2, #1
 *   @0x20bb24 strne r2, [r3, #0x4]
 *   @0x20bb28 b 0x20b9b4 <_ZN7CDS_Map3AddEP6RValueS1_+0x130>
 *   @0x20bb2c ldr r3, [r7]
 *   @0x20bb30 cmp r3, #0
 *   @0x20bb34 str r3, [r4, #0x10]
 *   @0x20bb38 beq 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20bb3c ldr r1, [r3, #0x8]
 *   @0x20bb40 ldr r2, [r3]
 *   @0x20bb44 cmp r1, #0
 *   @0x20bb48 streq r5, [r3, #0x8]
 *   @0x20bb4c add r2, r2, #1
 *   @0x20bb50 str r2, [r3]
 *   @0x20bb54 b 0x20ba4c <_ZN7CDS_Map3AddEP6RValueS1_+0x1c8>
 *   @0x20bb58 ldr r3, [r7]
 *   @0x20bb5c cmp r3, #0
 *   @0x20bb60 ldrne r2, [r3, #0x4]
 *   @0x20bb64 addne r2, r2, #1
 *   @0x20bb68 strne r2, [r3, #0x4]
 *   @0x20bb6c b 0x20ba48 <_ZN7CDS_Map3AddEP6RValueS1_+0x1c4>
 *   @0x20bb70 ldr r3, [r6]
 *   @0x20bb74 str r3, [r4]
 *   @0x20bb78 ldr r3, [r6]
 *   @0x20bb7c cmp r3, #0
 *   @0x20bb80 beq 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20bb84 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x20bb88 ldr r1, [r6]
 *   @0x20bb8c bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x20bb90 b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20bb94 ldr r3, [r6]
 *   @0x20bb98 cmp r3, #0
 *   @0x20bb9c str r3, [r4]
 *   @0x20bba0 beq 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20bba4 ldr r1, [r3, #0x8]
 *   @0x20bba8 ldr r2, [r3]
 *   @0x20bbac cmp r1, #0
 *   @0x20bbb0 streq r4, [r3, #0x8]
 *   @0x20bbb4 add r2, r2, #1
 *   @0x20bbb8 str r2, [r3]
 *   @0x20bbbc b 0x20b9b8 <_ZN7CDS_Map3AddEP6RValueS1_+0x134>
 *   @0x20bbc0 mov r0, r6
 *   @0x20bbc4 bl 0xd0e94 <_Z14REAL_RValue_ExPK6RValue>
 *   @0x20bbc8 b 0x20bab8 <_ZN7CDS_Map3AddEP6RValueS1_+0x234>
 *   @0x20bbcc ldr r6, [r8]
 *   @0x20bbd0 movw r2, #0x132
 *   @0x20bbd4 ldr r1, [pc, #0x64]
 *   @0x20bbd8 mov r3, #1
 *   @0x20bbdc mov r0, #16
 *   @0x20bbe0 add r1, pc, r1
 *   @0x20bbe4 ldm r6, {r7, r8}
 *   @0x20bbe8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib>
 *   @0x20bbec and r8, r9, r8
 *   @0x20bbf0 ldr r2, [r7, r8, lsl #3]
 *   @0x20bbf4 add r3, r7, r8, lsl #3
 *   @0x20bbf8 cmp r2, #0
 *   @0x20bbfc ldrne r2, [r3, #0x4]
 *   @0x20bc00 str r9, [r0, #0x8]
 *   @0x20bc04 str r4, [r0, #0xc]
 *   @0x20bc08 strne r2, [r0]
 *   @0x20bc0c streq r0, [r3, #0x4]
 *   @0x20bc10 strne r0, [r2, #0x4]
 *   @0x20bc14 strne r0, [r3, #0x4]
 *   @0x20bc18 ldr r3, [r6, #0x8]
 *   @0x20bc1c streq r0, [r7, r8, lsl #3]
 *   @0x20bc20 strne r5, [r0, #0x4]
 *   @0x20bc24 streq r2, [r0, #0x4]
 *   @0x20bc28 streq r2, [r0]
 *   @0x20bc2c mov r0, #1
 *   @0x20bc30 add r3, r3, r0
 *   @0x20bc34 str r3, [r6, #0x8]
 *   @0x20bc38 add sp, sp, #12
 *   @0x20bc3c pop {r4, r5, r6, r7, r8, r9, pc}
 *   @0x20bc40 andseq r1, r4, r12, asr #1
 *
 * ══ §16/31 ogg_stream_pagein  0x234eac  size 956  239 条（0x234eac..0x235268）
 * @func 0x234eac 0x235268  size 956  239 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6694×3 / ogg_page_version / ogg_page_continued / ogg_page_bos / ogg_page_eos / ogg_page_granulepos / ogg_page_serialno / ogg_page_pageno
 * 字段偏移 top8: 0x1c×14 / 0x8×10 / 0x10×10 / 0x14×8 / 0xc×5 / 0x20×5 / 0x18×3 / 0x2×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234eac push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x234eb0 mov r4, r0
 *   @0x234eb4 sub sp, sp, #44
 *   @0x234eb8 mov r0, r1
 *   @0x234ebc mov r7, r1
 *   @0x234ec0 ldr r9, [r1]
 *   @0x234ec4 ldr r10, [r1, #0x8]
 *   @0x234ec8 ldr r8, [r1, #0xc]
 *   @0x234ecc bl 0x233f74 <ogg_page_version>
 *   @0x234ed0 str r0, [sp, #0x14]
 *   @0x234ed4 mov r0, r7
 *   @0x234ed8 bl 0x233f80 <ogg_page_continued>
 *   @0x234edc mov r11, r0
 *   @0x234ee0 mov r0, r7
 *   @0x234ee4 bl 0x233f90 <ogg_page_bos>
 *   @0x234ee8 mov r5, r0
 *   @0x234eec mov r0, r7
 *   @0x234ef0 bl 0x233fa0 <ogg_page_eos>
 *   @0x234ef4 str r0, [sp, #0x1c]
 *   @0x234ef8 mov r0, r7
 *   @0x234efc bl 0x233fb0 <ogg_page_granulepos>
 *   @0x234f00 strd r0, r1, [sp, #32]
 *   @0x234f04 mov r0, r7
 *   @0x234f08 bl 0x23409c <ogg_page_serialno>
 *   @0x234f0c mov r6, r0
 *   @0x234f10 mov r0, r7
 *   @0x234f14 bl 0x2340c4 <ogg_page_pageno>
 *   @0x234f18 ldrb r7, [r9, #0x1a]
 *   @0x234f1c str r0, [sp, #0x18]
 *   @0x234f20 mov r0, r4
 *   @0x234f24 bl 0x23412c <ogg_stream_check>
 *   @0x234f28 cmp r0, #0
 *   @0x234f2c bne 0x235220 <ogg_stream_pagein+0x374>
 *   @0x234f30 ldr r1, [r4, #0xc]
 *   @0x234f34 ldr r3, [r4, #0x24]
 *   @0x234f38 cmp r1, #0
 *   @0x234f3c beq 0x234f5c <ogg_stream_pagein+0xb0>
 *   @0x234f40 ldr r2, [r4, #0x8]
 *   @0x234f44 rsb r2, r1, r2
 *   @0x234f48 str r2, [r4, #0x8]
 *   @0x234f4c cmp r2, #0
 *   @0x234f50 bne 0x235234 <ogg_stream_pagein+0x388>
 *   @0x234f54 mov r2, #0
 *   @0x234f58 str r2, [r4, #0xc]
 *   @0x234f5c cmp r3, #0
 *   @0x234f60 bne 0x2350a8 <ogg_stream_pagein+0x1fc>
 *   @0x234f64 ldr r3, [r4, #0x150]
 *   @0x234f68 cmp r3, r6
 *   @0x234f6c bne 0x235220 <ogg_stream_pagein+0x374>
 *   @0x234f70 ldr r3, [sp, #0x14]
 *   @0x234f74 cmp r3, #0
 *   @0x234f78 bgt 0x235220 <ogg_stream_pagein+0x374>
 *   @0x234f7c mov r0, r4
 *   @0x234f80 add r1, r7, #1
 *   @0x234f84 bl 0x2342a0 <ogg_stream_init+0xfc>
 *   @0x234f88 cmp r0, #0
 *   @0x234f8c str r0, [sp, #0x14]
 *   @0x234f90 bne 0x235220 <ogg_stream_pagein+0x374>
 *   @0x234f94 ldr r6, [r4, #0x154]
 *   @0x234f98 ldr r3, [sp, #0x18]
 *   @0x234f9c cmp r6, r3
 *   @0x234fa0 beq 0x235000 <ogg_stream_pagein+0x154>
 *   @0x234fa4 ldr r12, [r4, #0x20]
 *   @0x234fa8 ldr r0, [r4, #0x1c]
 *   @0x234fac cmp r12, r0
 *   @0x234fb0 bge 0x234fdc <ogg_stream_pagein+0x130>
 *   @0x234fb4 ldr r3, [r4, #0x10]
 *   @0x234fb8 ldr r2, [r4, #0x8]
 *   @0x234fbc add r0, r3, r0, lsl #2
 *   @0x234fc0 add r3, r3, r12, lsl #2
 *   @0x234fc4 ldr r1, [r3], #4
 *   @0x234fc8 cmp r3, r0
 *   @0x234fcc uxtb r1, r1
 *   @0x234fd0 rsb r2, r1, r2
 *   @0x234fd4 bne 0x234fc4 <ogg_stream_pagein+0x118>
 *   @0x234fd8 str r2, [r4, #0x8]
 *   @0x234fdc cmn r6, #1
 *   @0x234fe0 str r12, [r4, #0x1c]
 *   @0x234fe4 beq 0x235000 <ogg_stream_pagein+0x154>
 *   @0x234fe8 ldr r2, [r4, #0x10]
 *   @0x234fec add r3, r12, #1
 *   @0x234ff0 mov r1, #1024
 *   @0x234ff4 str r3, [r4, #0x1c]
 *   @0x234ff8 str r1, [r2, r12, lsl #2]
 *   @0x234ffc str r3, [r4, #0x20]
 *   @0x235000 cmp r11, #0
 *   @0x235004 bne 0x235110 <ogg_stream_pagein+0x264>
 *   @0x235008 mov r6, #0
 *   @0x23500c cmp r8, #0
 *   @0x235010 bne 0x235184 <ogg_stream_pagein+0x2d8>
 *   @0x235014 cmp r6, r7
 *   @0x235018 bge 0x2351d8 <ogg_stream_pagein+0x32c>
 *   @0x23501c ldr r10, [r4, #0x14]
 *   @0x235020 mvn r11, #0
 *   @0x235024 ldr r8, [r4, #0x10]
 *   @0x235028 add r12, r9, r6
 *   @0x23502c add r1, r6, #1
 *   @0x235030 stmib sp, {r7, r10, r11}
 *   @0x235034 b 0x23505c <ogg_stream_pagein+0x1b0>
 *   @0x235038 str r5, [r4, #0x1c]
 *   @0x23503c str r3, [sp, #0xc]
 *   @0x235040 str r5, [r4, #0x20]
 *   @0x235044 ldr r10, [sp, #0x4]
 *   @0x235048 mov r5, #0
 *   @0x23504c add r12, r12, #1
 *   @0x235050 add r1, r1, #1
 *   @0x235054 cmp r10, r0
 *   @0x235058 ble 0x2351c0 <ogg_stream_pagein+0x314>
 *   @0x23505c ldr r3, [r4, #0x1c]
 *   @0x235060 cmp r5, #0
 *   @0x235064 ldrb r2, [r12, #0x1b]
 *   @0x235068 mvn r10, #0
 *   @0x23506c ldr r7, [sp, #0x8]
 *   @0x235070 mvn r11, #0
 *   @0x235074 lsl r6, r3, #3
 *   @0x235078 orr r9, r2, #256
 *   @0x23507c str r2, [r8, r3, lsl #2]
 *   @0x235080 mov r0, r1
 *   @0x235084 strd r10, r11, [r7, r6]
 *   @0x235088 add r5, r3, #1
 *   @0x23508c strne r9, [r8, r3, lsl #2]
 *   @0x235090 cmp r2, #255
 *   @0x235094 bne 0x235038 <ogg_stream_pagein+0x18c>
 *   @0x235098 add r3, r3, #1
 *   @0x23509c mov r0, r1
 *   @0x2350a0 str r3, [r4, #0x1c]
 *   @0x2350a4 b 0x235044 <ogg_stream_pagein+0x198>
 *   @0x2350a8 ldr r2, [r4, #0x1c]
 *   @0x2350ac cmp r2, r3
 *   @0x2350b0 beq 0x2350f0 <ogg_stream_pagein+0x244>
 *   @0x2350b4 ldr r0, [r4, #0x10]
 *   @0x2350b8 rsb r2, r3, r2
 *   @0x2350bc str r3, [sp, #0x10]
 *   @0x2350c0 add r1, r0, r3, lsl #2
 *   @0x2350c4 lsl r2, r2, #2
 *   @0x2350c8 bl 0xb6694 <memmove@plt>
 *   @0x2350cc ldr r3, [sp, #0x10]
 *   @0x2350d0 ldr r2, [r4, #0x1c]
 *   @0x2350d4 ldr r0, [r4, #0x14]
 *   @0x2350d8 rsb r2, r3, r2
 *   @0x2350dc add r1, r0, r3, lsl #3
 *   @0x2350e0 lsl r2, r2, #3
 *   @0x2350e4 bl 0xb6694 <memmove@plt>
 *   @0x2350e8 ldr r2, [r4, #0x1c]
 *   @0x2350ec ldr r3, [sp, #0x10]
 *   @0x2350f0 ldr r1, [r4, #0x20]
 *   @0x2350f4 rsb r2, r3, r2
 *   @0x2350f8 str r2, [r4, #0x1c]
 *   @0x2350fc mov r2, #0
 *   @0x235100 rsb r3, r3, r1
 *   @0x235104 str r2, [r4, #0x24]
 *   @0x235108 str r3, [r4, #0x20]
 *   @0x23510c b 0x234f64 <ogg_stream_pagein+0xb8>
 *   @0x235110 ldr r3, [r4, #0x1c]
 *   @0x235114 cmp r3, #0
 *   @0x235118 ble 0x235130 <ogg_stream_pagein+0x284>
 *   @0x23511c ldr r2, [r4, #0x10]
 *   @0x235120 sub r3, r3, #-1073741823
 *   @0x235124 ldr r3, [r2, r3, lsl #2]
 *   @0x235128 cmp r3, #1024
 *   @0x23512c bne 0x235008 <ogg_stream_pagein+0x15c>
 *   @0x235130 cmp r7, #0
 *   @0x235134 beq 0x235254 <ogg_stream_pagein+0x3a8>
 *   @0x235138 ldrb r3, [r9, #0x1b]
 *   @0x23513c cmp r3, #255
 *   @0x235140 add r10, r10, r3
 *   @0x235144 rsb r8, r3, r8
 *   @0x235148 addeq r2, r9, #27
 *   @0x23514c moveq r6, #0
 *   @0x235150 beq 0x23516c <ogg_stream_pagein+0x2c0>
 *   @0x235154 b 0x235260 <ogg_stream_pagein+0x3b4>
 *   @0x235158 ldrb r3, [r2, #0x1]!
 *   @0x23515c cmp r3, #255
 *   @0x235160 add r10, r10, r3
 *   @0x235164 rsb r8, r3, r8
 *   @0x235168 bne 0x23524c <ogg_stream_pagein+0x3a0>
 *   @0x23516c add r6, r6, #1
 *   @0x235170 cmp r7, r6
 *   @0x235174 bgt 0x235158 <ogg_stream_pagein+0x2ac>
 *   @0x235178 cmp r8, #0
 *   @0x23517c mov r5, #0
 *   @0x235180 beq 0x235014 <ogg_stream_pagein+0x168>
 *   @0x235184 mov r0, r4
 *   @0x235188 mov r1, r8
 *   @0x23518c bl 0x234238 <ogg_stream_init+0x94>
 *   @0x235190 cmp r0, #0
 *   @0x235194 bne 0x235220 <ogg_stream_pagein+0x374>
 *   @0x235198 ldr r3, [r4, #0x8]
 *   @0x23519c mov r2, r8
 *   @0x2351a0 ldr r0, [r4]
 *   @0x2351a4 mov r1, r10
 *   @0x2351a8 add r0, r0, r3
 *   @0x2351ac bl 0xb65bc <memcpy@plt>
 *   @0x2351b0 ldr r3, [r4, #0x8]
 *   @0x2351b4 add r8, r3, r8
 *   @0x2351b8 str r8, [r4, #0x8]
 *   @0x2351bc b 0x235014 <ogg_stream_pagein+0x168>
 *   @0x2351c0 ldr r11, [sp, #0xc]
 *   @0x2351c4 ldr r10, [sp, #0x8]
 *   @0x2351c8 cmn r11, #1
 *   @0x2351cc lslne r11, r11, #3
 *   @0x2351d0 ldrdne r2, r3, [sp, #32]
 *   @0x2351d4 strdne r2, r3, [r10, r11]
 *   @0x2351d8 ldr r3, [sp, #0x1c]
 *   @0x2351dc cmp r3, #0
 *   @0x2351e0 beq 0x235208 <ogg_stream_pagein+0x35c>
 *   @0x2351e4 ldr r3, [r4, #0x1c]
 *   @0x2351e8 mov r2, #1
 *   @0x2351ec str r2, [r4, #0x148]
 *   @0x2351f0 cmp r3, #0
 *   @0x2351f4 subgt r3, r3, #-1073741823
 *   @0x2351f8 ldrgt r2, [r4, #0x10]
 *   @0x2351fc ldrgt r1, [r2, r3, lsl #2]
 *   @0x235200 orrgt r1, r1, #512
 *   @0x235204 strgt r1, [r2, r3, lsl #2]
 *   @0x235208 ldr r7, [sp, #0x18]
 *   @0x23520c ldr r0, [sp, #0x14]
 *   @0x235210 add r3, r7, #1
 *   @0x235214 str r3, [r4, #0x154]
 *   @0x235218 add sp, sp, #44
 *   @0x23521c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x235220 mvn r3, #0
 *   @0x235224 str r3, [sp, #0x14]
 *   @0x235228 ldr r0, [sp, #0x14]
 *   @0x23522c add sp, sp, #44
 *   @0x235230 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x235234 ldr r0, [r4]
 *   @0x235238 str r3, [sp, #0x10]
 *   @0x23523c add r1, r0, r1
 *   @0x235240 bl 0xb6694 <memmove@plt>
 *   @0x235244 ldr r3, [sp, #0x10]
 *   @0x235248 b 0x234f54 <ogg_stream_pagein+0xa8>
 *   @0x23524c add r6, r6, #1
 *   @0x235250 b 0x235178 <ogg_stream_pagein+0x2cc>
 *   @0x235254 mov r5, r7
 *   @0x235258 mov r6, r7
 *   @0x23525c b 0x23500c <ogg_stream_pagein+0x160>
 *   @0x235260 mov r6, #1
 *   @0x235264 b 0x235178 <ogg_stream_pagein+0x2cc>
 *
 * ══ §17/31 _SetCurrentTextureSettings  0x180b28  size 940  235 条（0x180b28..0x180ed4）
 * @func 0x180b28 0x180ed4  size 940  235 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x180b38→0x4a2f20, 0x180b40→0x4a2f28, 0x180b44→0x3f280c, 0x180b50→0x3f27ec, 0x180b8c→0x3f286c, 0x180b94→0x479bc0, 0x180bcc→0x3f284c, 0x180c44→0x3f282c
 * 调用序列: _SetCurrentTextureSettings()+0x2c8×2 / _SetCurrentTextureSettings()+0x2e8
 * 字段偏移 top8: 0x2×9 / 0x344×2 / 0x340×2 / 0x4×2 / 0x110×2 / 0x338×1 / 0x10×1 / 0x300×1
 * VFP 指令 34 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x180b28 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x180b2c vpush {d8}
 *   @0x180b30 sub sp, sp, #52
 *   @0x180b34 ldr r4, [pc, #0x344]
 *   @0x180b38 ldr r2, [pc, #0x344]
 *   @0x180b3c add r4, pc, r4
 *   @0x180b40 ldr r3, [pc, #0x340]
 *   @0x180b44 ldr r0, [pc, #0x340]
 *   @0x180b48 ldr r6, [r4, r2]
 *   @0x180b4c ldr r2, [r4, r3]
 *   @0x180b50 ldr r1, [pc, #0x338]
 *   @0x180b54 ldr r3, [r6]
 *   @0x180b58 ldr r0, [r4, r0]
 *   @0x180b5c ldr r1, [r4, r1]
 *   @0x180b60 ldr r2, [r2, r3, lsl #2]
 *   @0x180b64 ldr r8, [r0, r3, lsl #2]
 *   @0x180b68 cmp r2, #0
 *   @0x180b6c ldr r7, [r1, r3, lsl #2]
 *   @0x180b70 moveq r9, r2
 *   @0x180b74 beq 0x180b8c <_Z26_SetCurrentTextureSettingsv+0x64>
 *   @0x180b78 ldr r2, [r2, #0x10]
 *   @0x180b7c tst r2, #4
 *   @0x180b80 ubfx r9, r2, #0x5, #0x1
 *   @0x180b84 movne r7, #1
 *   @0x180b88 movne r8, r7
 *   @0x180b8c ldr r2, [pc, #0x300]
 *   @0x180b90 vldr s17, [pc, #728]
 *   @0x180b94 ldr r12, [pc, #0x2fc]
 *   @0x180b98 vldr s16, [pc, #724]
 *   @0x180b9c movw r0, #0xde1
 *   @0x180ba0 mov r1, #10240
 *   @0x180ba4 ldr r2, [r4, r2]
 *   @0x180ba8 ldr r5, [r4, r12]
 *   @0x180bac ldr r2, [r2, r3, lsl #2]
 *   @0x180bb0 ldr r3, [r5]
 *   @0x180bb4 cmp r2, #1
 *   @0x180bb8 vmoveq r2, s16
 *   @0x180bbc vmovne r2, s17
 *   @0x180bc0 blx r3
 *   @0x180bc4 cmp r9, #0
 *   @0x180bc8 bne 0x180c44 <_Z26_SetCurrentTextureSettingsv+0x11c>
 *   @0x180bcc ldr r2, [pc, #0x2c8]
 *   @0x180bd0 movw r0, #0xde1
 *   @0x180bd4 ldr r12, [r6]
 *   @0x180bd8 movw r1, #0x2801
 *   @0x180bdc ldr r3, [r5]
 *   @0x180be0 ldr r2, [r4, r2]
 *   @0x180be4 ldr r2, [r2, r12, lsl #2]
 *   @0x180be8 cmp r2, #1
 *   @0x180bec vmoveq r2, s16
 *   @0x180bf0 vmovne r2, s17
 *   @0x180bf4 blx r3
 *   @0x180bf8 cmp r8, #1
 *   @0x180bfc vldr s17, [pc, #628]
 *   @0x180c00 vldr s16, [pc, #628]
 *   @0x180c04 ldr r3, [r5]
 *   @0x180c08 vmoveq r2, s16
 *   @0x180c0c vmovne r2, s17
 *   @0x180c10 movw r0, #0xde1
 *   @0x180c14 movw r1, #0x2802
 *   @0x180c18 blx r3
 *   @0x180c1c cmp r7, #1
 *   @0x180c20 ldr r3, [r5]
 *   @0x180c24 movw r0, #0xde1
 *   @0x180c28 vmoveq r2, s16
 *   @0x180c2c vmovne r2, s17
 *   @0x180c30 movw r1, #0x2803
 *   @0x180c34 blx r3
 *   @0x180c38 add sp, sp, #52
 *   @0x180c3c vpop {d8}
 *   @0x180c40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x180c44 ldr r10, [pc, #0x254]
 *   @0x180c48 add r12, sp, #12
 *   @0x180c4c ldr lr, [pc, #0x250]
 *   @0x180c50 ldr r9, [pc, #0x244]
 *   @0x180c54 ldr r10, [r4, r10]
 *   @0x180c58 add lr, pc, lr
 *   @0x180c5c ldm lr!, {r0, r1, r2, r3}
 *   @0x180c60 str r10, [sp]
 *   @0x180c64 ldr r9, [r4, r9]
 *   @0x180c68 ldr r10, [r6]
 *   @0x180c6c ldr r11, [sp]
 *   @0x180c70 str r9, [sp, #0x4]
 *   @0x180c74 stm r12!, {r0, r1, r2, r3}
 *   @0x180c78 ldr r9, [r11, r10, lsl #2]
 *   @0x180c7c ldr r11, [sp, #0x4]
 *   @0x180c80 ldm lr!, {r0, r1, r2, r3}
 *   @0x180c84 add r9, r9, r9, lsl #1
 *   @0x180c88 ldr r10, [r11, r10, lsl #2]
 *   @0x180c8c add r9, r9, r10
 *   @0x180c90 ldr r10, [r5]
 *   @0x180c94 stm r12!, {r0, r1, r2, r3}
 *   @0x180c98 add r1, sp, #48
 *   @0x180c9c ldr lr, [lr]
 *   @0x180ca0 add r9, r1, r9, lsl #2
 *   @0x180ca4 movw r0, #0xde1
 *   @0x180ca8 movw r1, #0x2801
 *   @0x180cac str lr, [r12]
 *   @0x180cb0 ldr r2, [r9, #-0x24]
 *   @0x180cb4 vmov s15, r2
 *   @0x180cb8 vcvt.f32.s32 s15, s15
 *   @0x180cbc vmov r2, s15
 *   @0x180cc0 blx r10
 *   @0x180cc4 ldr r3, [pc, #0x1dc]
 *   @0x180cc8 ldr r3, [r4, r3]
 *   @0x180ccc ldrb r3, [r3]
 *   @0x180cd0 cmp r3, #0
 *   @0x180cd4 bne 0x180db0 <_Z26_SetCurrentTextureSettingsv+0x288>
 *   @0x180cd8 ldr r3, [pc, #0x1cc]
 *   @0x180cdc ldr r3, [r4, r3]
 *   @0x180ce0 ldrb r3, [r3]
 *   @0x180ce4 cmp r3, #0
 *   @0x180ce8 bne 0x180e48 <_Z26_SetCurrentTextureSettingsv+0x320>
 *   @0x180cec ldr r3, [pc, #0x1bc]
 *   @0x180cf0 ldr r3, [r4, r3]
 *   @0x180cf4 ldrb r3, [r3]
 *   @0x180cf8 cmp r3, #0
 *   @0x180cfc beq 0x180d50 <_Z26_SetCurrentTextureSettingsv+0x228>
 *   @0x180d00 ldr r3, [r6]
 *   @0x180d04 ldr r11, [sp]
 *   @0x180d08 ldr r2, [r11, r3, lsl #2]
 *   @0x180d0c cmp r2, #2
 *   @0x180d10 bne 0x180e30 <_Z26_SetCurrentTextureSettingsv+0x308>
 *   @0x180d14 ldr r2, [pc, #0x198]
 *   @0x180d18 movw r0, #0xde1
 *   @0x180d1c ldr lr, [pc, #0x194]
 *   @0x180d20 movw r1, #0x84fe
 *   @0x180d24 ldr r12, [r5]
 *   @0x180d28 ldr r2, [r4, r2]
 *   @0x180d2c ldr lr, [r4, lr]
 *   @0x180d30 ldr r2, [r2, r3, lsl #2]
 *   @0x180d34 ldr r3, [lr]
 *   @0x180d38 cmp r2, r3
 *   @0x180d3c movge r2, r3
 *   @0x180d40 vmov s15, r2
 *   @0x180d44 vcvt.f32.s32 s15, s15
 *   @0x180d48 vmov r2, s15
 *   @0x180d4c blx r12
 *   @0x180d50 ldr r3, [pc, #0x164]
 *   @0x180d54 ldr r3, [r4, r3]
 *   @0x180d58 ldrb r3, [r3]
 *   @0x180d5c cmp r3, #0
 *   @0x180d60 beq 0x180bf8 <_Z26_SetCurrentTextureSettingsv+0xd0>
 *   @0x180d64 ldr r2, [pc, #0x154]
 *   @0x180d68 movw r0, #0xde1
 *   @0x180d6c ldr r12, [r6]
 *   @0x180d70 movw r1, #0x813a
 *   @0x180d74 ldr r3, [r5]
 *   @0x180d78 ldr r2, [r4, r2]
 *   @0x180d7c add r2, r2, r12, lsl #2
 *   @0x180d80 ldr r2, [r2]
 *   @0x180d84 blx r3
 *   @0x180d88 ldr r2, [pc, #0x134]
 *   @0x180d8c ldr r12, [r6]
 *   @0x180d90 movw r0, #0xde1
 *   @0x180d94 ldr r3, [r5]
 *   @0x180d98 movw r1, #0x813b
 *   @0x180d9c ldr r2, [r4, r2]
 *   @0x180da0 add r2, r2, r12, lsl #2
 *   @0x180da4 ldr r2, [r2]
 *   @0x180da8 blx r3
 *   @0x180dac b 0x180bf8 <_Z26_SetCurrentTextureSettingsv+0xd0>
 *   @0x180db0 ldr r1, [pc, #0x110]
 *   @0x180db4 ldr r3, [pc, #0x110]
 *   @0x180db8 ldr r2, [r6]
 *   @0x180dbc ldr r1, [r4, r1]
 *   @0x180dc0 vldr s15, [r1]
 *   @0x180dc4 vneg.f32 s14, s15
 *   @0x180dc8 ldr r3, [r4, r3]
 *   @0x180dcc add r3, r3, r2, lsl #2
 *   @0x180dd0 vldr s13, [r3]
 *   @0x180dd4 vcmpe.f32 s13, s14
 *   @0x180dd8 vmrs APSR_nzcv, fpscr
 *   @0x180ddc ble 0x180e10 <_Z26_SetCurrentTextureSettingsv+0x2e8>
 *   @0x180de0 vcmpe.f32 s13, s15
 *   @0x180de4 vmrs APSR_nzcv, fpscr
 *   @0x180de8 bpl 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8>
 *   @0x180dec vmov.f32 s15, s13
 *   @0x180df0 ldr r3, [pc, #0xd8]
 *   @0x180df4 mov r0, #34048
 *   @0x180df8 movw r1, #0x8501
 *   @0x180dfc vmov r2, s15
 *   @0x180e00 ldr r3, [r4, r3]
 *   @0x180e04 ldr r3, [r3]
 *   @0x180e08 blx r3
 *   @0x180e0c b 0x180cec <_Z26_SetCurrentTextureSettingsv+0x1c4>
 *   @0x180e10 vcmpe.f32 s15, s14
 *   @0x180e14 vmrs APSR_nzcv, fpscr
 *   @0x180e18 ble 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8>
 *   @0x180e1c vcmpe.f32 s13, s14
 *   @0x180e20 vmrs APSR_nzcv, fpscr
 *   @0x180e24 vmovle.f32 s15, s14
 *   @0x180e28 ble 0x180df0 <_Z26_SetCurrentTextureSettingsv+0x2c8>
 *   @0x180e2c b 0x180dec <_Z26_SetCurrentTextureSettingsv+0x2c4>
 *   @0x180e30 ldr r3, [r5]
 *   @0x180e34 movw r0, #0xde1
 *   @0x180e38 movw r1, #0x84fe
 *   @0x180e3c mov r2, #1065353216
 *   @0x180e40 blx r3
 *   @0x180e44 b 0x180d50 <_Z26_SetCurrentTextureSettingsv+0x228>
 *   @0x180e48 ldr r2, [pc, #0x7c]
 *   @0x180e4c movw r0, #0xde1
 *   @0x180e50 ldr r12, [r6]
 *   @0x180e54 movw r1, #0x8501
 *   @0x180e58 ldr r3, [r5]
 *   @0x180e5c ldr r2, [r4, r2]
 *   @0x180e60 add r2, r2, r12, lsl #2
 *   @0x180e64 ldr r2, [r2]
 *   @0x180e68 blx r3
 *   @0x180e6c b 0x180cec <_Z26_SetCurrentTextureSettingsv+0x1c4>
 *   @0x180e70 ldrmi r0, [r8], -r0
 *   @0x180e74 ldrmi r0, [r8], -r0, lsl #8
 *   @0x180e78 strtmi r0, [r4], -r0, lsl #8
 *   @0x180e7c strmi r2, [r1, -r0, lsl #30]
 *   @0x180e80 eoreq r1, r7, r4, lsl r1
 *   @0x180e84 .word 0xffffe808
 *   @0x180e88 .word 0xffffe8e8
 *   @0x180e8c .word 0xffffe8c8
 *   @0x180e90 .word 0xffffe8cc
 *   @0x180e94 .word 0xffffe8bc
 *   @0x180e98 .word 0xffffbb1c
 *   @0x180e9c .word 0xffffe8c4
 *   @0x180ea0 .word 0xffffe8d0
 *   @0x180ea4 andseq r12, sp, r0, ror #30
 *   @0x180ea8 .word 0xffffe7e8
 *   @0x180eac .word 0xffffe8ec
 *   @0x180eb0 .word 0xffffe7d0
 *   @0x180eb4 .word 0xffffe8c0
 *   @0x180eb8 .word 0xffffe7d4
 *   @0x180ebc .word 0xffffe8f0
 *   @0x180ec0 .word 0xffffe8d4
 *   @0x180ec4 .word 0xffffe8d8
 *   @0x180ec8 .word 0xffffe7e4
 *   @0x180ecc .word 0xffffe8dc
 *   @0x180ed0 .word 0xffffbca4
 *
 * ══ §18/31 _pcre_valid_utf  0x2668f4  size 936  234 条（0x2668f4..0x266c9c）
 * @func 0x2668f4 0x266c9c  size 936  234 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _pcre_valid_utf+0x23c×2 / _pcre_valid_utf+0x254 / _pcre_valid_utf+0x2d4 / _pcre_valid_utf+0x228
 * 字段偏移 top8: 0x2×4 / 0x3×3 / 0x4×2 / 0x350×1 / 0x1×1 / 0x5×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2668f4 cmp r1, #0
 *   @0x2668f8 push {r4, r5, r6, r7}
 *   @0x2668fc blt 0x266b48 <_pcre_valid_utf+0x254>
 *   @0x266900 sub r12, r1, #1
 *   @0x266904 cmp r1, #0
 *   @0x266908 ble 0x266b30 <_pcre_valid_utf+0x23c>
 *   @0x26690c mov r3, r0
 *   @0x266910 b 0x266924 <_pcre_valid_utf+0x30>
 *   @0x266914 cmp r12, #0
 *   @0x266918 add r3, r3, #1
 *   @0x26691c sub r12, r12, #1
 *   @0x266920 ble 0x266b30 <_pcre_valid_utf+0x23c>
 *   @0x266924 ldrb r1, [r3]
 *   @0x266928 tst r1, #128
 *   @0x26692c beq 0x266914 <_pcre_valid_utf+0x20>
 *   @0x266930 cmp r1, #191
 *   @0x266934 bls 0x266bc8 <_pcre_valid_utf+0x2d4>
 *   @0x266938 cmp r1, #253
 *   @0x26693c bhi 0x266bd8 <_pcre_valid_utf+0x2e4>
 *   @0x266940 ldr r4, [pc, #0x350]
 *   @0x266944 and r5, r1, #63
 *   @0x266948 ldr r4, [pc, r4]
 *   @0x26694c ldrb r4, [r4, r5]
 *   @0x266950 cmp r4, r12
 *   @0x266954 bgt 0x266be8 <_pcre_valid_utf+0x2f4>
 *   @0x266958 ldrb r6, [r3, #0x1]
 *   @0x26695c rsb r12, r4, r12
 *   @0x266960 add r7, r3, #1
 *   @0x266964 and r5, r6, #192
 *   @0x266968 cmp r5, #128
 *   @0x26696c bne 0x266bf8 <_pcre_valid_utf+0x304>
 *   @0x266970 sub r5, r4, #1
 *   @0x266974 cmp r5, #4
 *   @0x266978 addls pc, pc, r5, lsl #2
 *   @0x26697c b 0x266b3c <_pcre_valid_utf+0x248>
 *   @0x266980 b 0x266b14 <_pcre_valid_utf+0x220>
 *   @0x266984 b 0x266ac8 <_pcre_valid_utf+0x1d4>
 *   @0x266988 b 0x266a64 <_pcre_valid_utf+0x170>
 *   @0x26698c b 0x266a0c <_pcre_valid_utf+0x118>
 *   @0x266990 b 0x266994 <_pcre_valid_utf+0xa0>
 *   @0x266994 ldrb r12, [r3, #0x2]
 *   @0x266998 and r12, r12, #192
 *   @0x26699c cmp r12, #128
 *   @0x2669a0 bne 0x266c0c <_pcre_valid_utf+0x318>
 *   @0x2669a4 ldrb r12, [r3, #0x3]
 *   @0x2669a8 and r12, r12, #192
 *   @0x2669ac cmp r12, #128
 *   @0x2669b0 bne 0x266c1c <_pcre_valid_utf+0x328>
 *   @0x2669b4 ldrb r12, [r3, #0x4]
 *   @0x2669b8 and r12, r12, #192
 *   @0x2669bc cmp r12, #128
 *   @0x2669c0 rsbne r3, r0, r3
 *   @0x2669c4 strne r3, [r2]
 *   @0x2669c8 movne r0, #9
 *   @0x2669cc bne 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x2669d0 ldrb r12, [r3, #0x5]
 *   @0x2669d4 add r7, r3, #5
 *   @0x2669d8 and r3, r12, #192
 *   @0x2669dc cmp r3, #128
 *   @0x2669e0 bne 0x266c5c <_pcre_valid_utf+0x368>
 *   @0x2669e4 cmp r1, #252
 *   @0x2669e8 beq 0x266b90 <_pcre_valid_utf+0x29c>
 *   @0x2669ec cmp r4, #4
 *   @0x2669f0 rsb r7, r0, r7
 *   @0x2669f4 rsb r4, r4, r7
 *   @0x2669f8 str r4, [r2]
 *   @0x2669fc movne r0, #12
 *   @0x266a00 moveq r0, #11
 *   @0x266a04 pop {r4, r5, r6, r7}
 *   @0x266a08 bx lr
 *   @0x266a0c ldrb r12, [r3, #0x2]
 *   @0x266a10 and r12, r12, #192
 *   @0x266a14 cmp r12, #128
 *   @0x266a18 bne 0x266c0c <_pcre_valid_utf+0x318>
 *   @0x266a1c ldrb r12, [r3, #0x3]
 *   @0x266a20 and r12, r12, #192
 *   @0x266a24 cmp r12, #128
 *   @0x266a28 bne 0x266c1c <_pcre_valid_utf+0x328>
 *   @0x266a2c ldrb r12, [r3, #0x4]
 *   @0x266a30 add r7, r3, #4
 *   @0x266a34 and r3, r12, #192
 *   @0x266a38 cmp r3, #128
 *   @0x266a3c bne 0x266c84 <_pcre_valid_utf+0x390>
 *   @0x266a40 cmp r1, #248
 *   @0x266a44 bne 0x2669ec <_pcre_valid_utf+0xf8>
 *   @0x266a48 tst r6, #56
 *   @0x266a4c bne 0x2669ec <_pcre_valid_utf+0xf8>
 *   @0x266a50 rsb r3, r0, r7
 *   @0x266a54 mov r0, #18
 *   @0x266a58 sub r3, r3, #4
 *   @0x266a5c str r3, [r2]
 *   @0x266a60 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266a64 ldrb r4, [r3, #0x2]
 *   @0x266a68 and r4, r4, #192
 *   @0x266a6c cmp r4, #128
 *   @0x266a70 bne 0x266c0c <_pcre_valid_utf+0x318>
 *   @0x266a74 ldrb r4, [r3, #0x3]
 *   @0x266a78 add r3, r3, #3
 *   @0x266a7c and r4, r4, #192
 *   @0x266a80 cmp r4, #128
 *   @0x266a84 bne 0x266c34 <_pcre_valid_utf+0x340>
 *   @0x266a88 cmp r1, #240
 *   @0x266a8c beq 0x266b74 <_pcre_valid_utf+0x280>
 *   @0x266a90 cmp r1, #244
 *   @0x266a94 bhi 0x266ab4 <_pcre_valid_utf+0x1c0>
 *   @0x266a98 cmp r6, #143
 *   @0x266a9c movls r6, #0
 *   @0x266aa0 movhi r6, #1
 *   @0x266aa4 cmp r1, #244
 *   @0x266aa8 movne r6, #0
 *   @0x266aac cmp r6, #0
 *   @0x266ab0 beq 0x266914 <_pcre_valid_utf+0x20>
 *   @0x266ab4 rsb r3, r0, r3
 *   @0x266ab8 mov r0, #13
 *   @0x266abc sub r3, r3, #3
 *   @0x266ac0 str r3, [r2]
 *   @0x266ac4 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266ac8 ldrb r4, [r3, #0x2]
 *   @0x266acc add r3, r3, #2
 *   @0x266ad0 and r4, r4, #192
 *   @0x266ad4 cmp r4, #128
 *   @0x266ad8 bne 0x266c48 <_pcre_valid_utf+0x354>
 *   @0x266adc cmp r1, #224
 *   @0x266ae0 beq 0x266bac <_pcre_valid_utf+0x2b8>
 *   @0x266ae4 cmp r6, #159
 *   @0x266ae8 movls r6, #0
 *   @0x266aec movhi r6, #1
 *   @0x266af0 cmp r1, #237
 *   @0x266af4 movne r6, #0
 *   @0x266af8 cmp r6, #0
 *   @0x266afc beq 0x266914 <_pcre_valid_utf+0x20>
 *   @0x266b00 rsb r3, r0, r3
 *   @0x266b04 mov r0, #14
 *   @0x266b08 sub r3, r3, #2
 *   @0x266b0c str r3, [r2]
 *   @0x266b10 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266b14 tst r1, #62
 *   @0x266b18 beq 0x266c70 <_pcre_valid_utf+0x37c>
 *   @0x266b1c cmp r12, #0
 *   @0x266b20 mov r3, r7
 *   @0x266b24 sub r12, r12, #1
 *   @0x266b28 add r3, r3, #1
 *   @0x266b2c bgt 0x266924 <_pcre_valid_utf+0x30>
 *   @0x266b30 mov r0, #0
 *   @0x266b34 pop {r4, r5, r6, r7}
 *   @0x266b38 bx lr
 *   @0x266b3c cmp r4, #3
 *   @0x266b40 bls 0x266b1c <_pcre_valid_utf+0x228>
 *   @0x266b44 b 0x2669ec <_pcre_valid_utf+0xf8>
 *   @0x266b48 ldrb r1, [r0]
 *   @0x266b4c cmp r1, #0
 *   @0x266b50 beq 0x266c2c <_pcre_valid_utf+0x338>
 *   @0x266b54 add r3, r0, #1
 *   @0x266b58 mov r1, r3
 *   @0x266b5c add r3, r3, #1
 *   @0x266b60 ldrb r12, [r1]
 *   @0x266b64 cmp r12, #0
 *   @0x266b68 bne 0x266b58 <_pcre_valid_utf+0x264>
 *   @0x266b6c rsb r1, r0, r1
 *   @0x266b70 b 0x266900 <_pcre_valid_utf+0xc>
 *   @0x266b74 tst r6, #48
 *   @0x266b78 bne 0x266914 <_pcre_valid_utf+0x20>
 *   @0x266b7c rsb r3, r0, r3
 *   @0x266b80 mov r0, #17
 *   @0x266b84 sub r3, r3, #3
 *   @0x266b88 str r3, [r2]
 *   @0x266b8c b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266b90 tst r6, #60
 *   @0x266b94 bne 0x2669ec <_pcre_valid_utf+0xf8>
 *   @0x266b98 rsb r3, r0, r7
 *   @0x266b9c mov r0, #19
 *   @0x266ba0 sub r3, r3, #5
 *   @0x266ba4 str r3, [r2]
 *   @0x266ba8 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266bac tst r6, #32
 *   @0x266bb0 bne 0x266914 <_pcre_valid_utf+0x20>
 *   @0x266bb4 rsb r3, r0, r3
 *   @0x266bb8 mov r0, #16
 *   @0x266bbc sub r3, r3, #2
 *   @0x266bc0 str r3, [r2]
 *   @0x266bc4 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266bc8 rsb r3, r0, r3
 *   @0x266bcc mov r0, #20
 *   @0x266bd0 str r3, [r2]
 *   @0x266bd4 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266bd8 rsb r3, r0, r3
 *   @0x266bdc mov r0, #21
 *   @0x266be0 str r3, [r2]
 *   @0x266be4 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266be8 rsb r3, r0, r3
 *   @0x266bec rsb r0, r12, r4
 *   @0x266bf0 str r3, [r2]
 *   @0x266bf4 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266bf8 rsb r3, r0, r7
 *   @0x266bfc mov r0, #6
 *   @0x266c00 sub r3, r3, #1
 *   @0x266c04 str r3, [r2]
 *   @0x266c08 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c0c rsb r3, r0, r3
 *   @0x266c10 mov r0, #7
 *   @0x266c14 str r3, [r2]
 *   @0x266c18 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c1c rsb r3, r0, r3
 *   @0x266c20 mov r0, #8
 *   @0x266c24 str r3, [r2]
 *   @0x266c28 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c2c mvn r12, #0
 *   @0x266c30 b 0x266904 <_pcre_valid_utf+0x10>
 *   @0x266c34 rsb r3, r0, r3
 *   @0x266c38 mov r0, #8
 *   @0x266c3c sub r3, r3, #3
 *   @0x266c40 str r3, [r2]
 *   @0x266c44 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c48 rsb r3, r0, r3
 *   @0x266c4c mov r0, #7
 *   @0x266c50 sub r3, r3, #2
 *   @0x266c54 str r3, [r2]
 *   @0x266c58 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c5c rsb r3, r0, r7
 *   @0x266c60 mov r0, #10
 *   @0x266c64 sub r3, r3, #5
 *   @0x266c68 str r3, [r2]
 *   @0x266c6c b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c70 rsb r3, r0, r7
 *   @0x266c74 mov r0, #15
 *   @0x266c78 sub r3, r3, #1
 *   @0x266c7c str r3, [r2]
 *   @0x266c80 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c84 rsb r3, r0, r7
 *   @0x266c88 mov r0, #9
 *   @0x266c8c sub r3, r3, #4
 *   @0x266c90 str r3, [r2]
 *   @0x266c94 b 0x266a04 <_pcre_valid_utf+0x110>
 *   @0x266c98 mulseq r8, r8, lr
 *
 * ══ §19/31 anon_27e408  0x27e408  size 936  234 条（0x27e408..0x27e7b0）
 * @func 0x27e408 0x27e7b0  size 936  234 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: printbuf_memappend×10 / sprintbuf×4 / printbuf_free×4 / anon_27e408+0xe0 / anon_27e408+0x124 / anon_27e408+0x180 / anon_27e408+0x50 / lh_table_free
 * 字段偏移 top8: 0x18×6 / 0x4×6 / 0x10×6 / 0xc×3 / 0x8×3 / 0x1f0×1 / 0x1ec×1 / 0x1e4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27e408 ldr r2, [r0, #0x18]
 *   @0x27e40c mov r0, r1
 *   @0x27e410 ldr r1, [pc, #0x4]
 *   @0x27e414 add r1, pc, r1
 *   @0x27e418 b 0x280dbc <sprintbuf>
 *   @0x27e41c strdeq r4, r5, [r11], -r8
 *   @0x27e420 ldrd r2, r3, [r0, #24]
 *   @0x27e424 mov r0, r1
 *   @0x27e428 ldr r1, [pc, #0x4]
 *   @0x27e42c add r1, pc, r1
 *   @0x27e430 b 0x280dbc <sprintbuf>
 *   @0x27e434 andeq r1, r12, r8, ror #27
 *   @0x27e438 mov r0, r1
 *   @0x27e43c ldr r1, [pc, #0x10]
 *   @0x27e440 push {r3, lr}
 *   @0x27e444 add r1, pc, r1
 *   @0x27e448 bl 0x280dbc <sprintbuf>
 *   @0x27e44c mov r0, #0
 *   @0x27e450 pop {r3, pc}
 *   @0x27e454 andeq r3, r11, r0, ror #28
 *   @0x27e458 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27e45c sub sp, sp, #20
 *   @0x27e460 ldr r3, [pc, #0x1f0]
 *   @0x27e464 mov r5, #0
 *   @0x27e468 ldr r10, [pc, #0x1ec]
 *   @0x27e46c mov r7, r1
 *   @0x27e470 add r3, pc, r3
 *   @0x27e474 ldr r9, [pc, #0x1e4]
 *   @0x27e478 str r3, [sp, #0xc]
 *   @0x27e47c add r10, pc, r10
 *   @0x27e480 ldr r3, [pc, #0x1dc]
 *   @0x27e484 add r9, pc, r9
 *   @0x27e488 ldr r8, [pc, #0x1d8]
 *   @0x27e48c sub r11, r1, #1
 *   @0x27e490 add r3, pc, r3
 *   @0x27e494 str r3, [sp, #0x8]
 *   @0x27e498 add r8, pc, r8
 *   @0x27e49c ldr r3, [pc, #0x1c8]
 *   @0x27e4a0 mov r6, r0
 *   @0x27e4a4 mov r1, r5
 *   @0x27e4a8 add r3, pc, r3
 *   @0x27e4ac str r3, [sp, #0x4]
 *   @0x27e4b0 ldrb r4, [r11, #0x1]!
 *   @0x27e4b4 mov r2, r5
 *   @0x27e4b8 add r5, r5, #1
 *   @0x27e4bc cmp r4, #13
 *   @0x27e4c0 beq 0x27e570 <mc_info+0x1a8>
 *   @0x27e4c4 bhi 0x27e4f4 <mc_info+0x12c>
 *   @0x27e4c8 cmp r4, #0
 *   @0x27e4cc bne 0x27e564 <mc_info+0x19c>
 *   @0x27e4d0 rsb r2, r1, r2
 *   @0x27e4d4 cmp r2, #0
 *   @0x27e4d8 ble 0x27e4e8 <mc_info+0x120>
 *   @0x27e4dc mov r0, r6
 *   @0x27e4e0 add r1, r7, r1
 *   @0x27e4e4 bl 0x280d20 <printbuf_memappend>
 *   @0x27e4e8 mov r0, #0
 *   @0x27e4ec add sp, sp, #20
 *   @0x27e4f0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27e4f4 cmp r4, #47
 *   @0x27e4f8 beq 0x27e570 <mc_info+0x1a8>
 *   @0x27e4fc cmp r4, #92
 *   @0x27e500 beq 0x27e570 <mc_info+0x1a8>
 *   @0x27e504 cmp r4, #34
 *   @0x27e508 beq 0x27e570 <mc_info+0x1a8>
 *   @0x27e50c cmp r4, #31
 *   @0x27e510 bhi 0x27e4b0 <mc_info+0xe8>
 *   @0x27e514 rsb r2, r1, r2
 *   @0x27e518 cmp r2, #0
 *   @0x27e51c ble 0x27e52c <mc_info+0x164>
 *   @0x27e520 add r1, r7, r1
 *   @0x27e524 mov r0, r6
 *   @0x27e528 bl 0x280d20 <printbuf_memappend>
 *   @0x27e52c ldr r3, [pc, #0x13c]
 *   @0x27e530 and r12, r4, #15
 *   @0x27e534 ldr r1, [pc, #0x138]
 *   @0x27e538 mov r0, r6
 *   @0x27e53c ldr r3, [pc, r3]
 *   @0x27e540 add r1, pc, r1
 *   @0x27e544 ldr r3, [r3]
 *   @0x27e548 ldrb r2, [r3, r4, lsr #4]
 *   @0x27e54c ldrb r3, [r3, r12]
 *   @0x27e550 bl 0x280dbc <sprintbuf>
 *   @0x27e554 cmp r4, #0
 *   @0x27e558 mov r1, r5
 *   @0x27e55c bne 0x27e4b0 <mc_info+0xe8>
 *   @0x27e560 b 0x27e4e8 <mc_info+0x120>
 *   @0x27e564 sub r3, r4, #8
 *   @0x27e568 cmp r3, #2
 *   @0x27e56c bhi 0x27e50c <mc_info+0x144>
 *   @0x27e570 rsb r2, r1, r2
 *   @0x27e574 cmp r2, #0
 *   @0x27e578 ble 0x27e588 <mc_info+0x1c0>
 *   @0x27e57c add r1, r7, r1
 *   @0x27e580 mov r0, r6
 *   @0x27e584 bl 0x280d20 <printbuf_memappend>
 *   @0x27e588 cmp r4, #8
 *   @0x27e58c beq 0x27e5c8 <mc_info+0x200>
 *   @0x27e590 cmp r4, #10
 *   @0x27e594 beq 0x27e5e0 <mc_info+0x218>
 *   @0x27e598 cmp r4, #13
 *   @0x27e59c beq 0x27e5f4 <mc_info+0x22c>
 *   @0x27e5a0 cmp r4, #9
 *   @0x27e5a4 beq 0x27e608 <mc_info+0x240>
 *   @0x27e5a8 cmp r4, #34
 *   @0x27e5ac beq 0x27e61c <mc_info+0x254>
 *   @0x27e5b0 cmp r4, #92
 *   @0x27e5b4 beq 0x27e630 <mc_info+0x268>
 *   @0x27e5b8 cmp r4, #47
 *   @0x27e5bc beq 0x27e644 <mc_info+0x27c>
 *   @0x27e5c0 mov r1, r5
 *   @0x27e5c4 b 0x27e4b0 <mc_info+0xe8>
 *   @0x27e5c8 ldr r1, [pc, #0xa8]
 *   @0x27e5cc mov r0, r6
 *   @0x27e5d0 mov r2, #2
 *   @0x27e5d4 add r1, pc, r1
 *   @0x27e5d8 bl 0x280d20 <printbuf_memappend>
 *   @0x27e5dc b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e5e0 mov r0, r6
 *   @0x27e5e4 mov r1, r8
 *   @0x27e5e8 mov r2, #2
 *   @0x27e5ec bl 0x280d20 <printbuf_memappend>
 *   @0x27e5f0 b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e5f4 mov r0, r6
 *   @0x27e5f8 mov r1, r9
 *   @0x27e5fc mov r2, #2
 *   @0x27e600 bl 0x280d20 <printbuf_memappend>
 *   @0x27e604 b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e608 mov r0, r6
 *   @0x27e60c mov r1, r10
 *   @0x27e610 mov r2, #2
 *   @0x27e614 bl 0x280d20 <printbuf_memappend>
 *   @0x27e618 b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e61c mov r0, r6
 *   @0x27e620 ldr r1, [sp, #0x4]
 *   @0x27e624 mov r2, #2
 *   @0x27e628 bl 0x280d20 <printbuf_memappend>
 *   @0x27e62c b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e630 mov r0, r6
 *   @0x27e634 ldr r1, [sp, #0x8]
 *   @0x27e638 mov r2, #2
 *   @0x27e63c bl 0x280d20 <printbuf_memappend>
 *   @0x27e640 b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e644 mov r0, r6
 *   @0x27e648 ldr r1, [sp, #0xc]
 *   @0x27e64c mov r2, #2
 *   @0x27e650 bl 0x280d20 <printbuf_memappend>
 *   @0x27e654 b 0x27e5c0 <mc_info+0x1f8>
 *   @0x27e658 andeq r8, sp, r4, lsr #28
 *   @0x27e65c andeq r8, sp, r12, lsl #28
 *   @0x27e660 andeq r8, sp, r0, lsl #28
 *   @0x27e664 andeq r8, sp, r0, lsl #28
 *   @0x27e668 andeq r8, sp, r8, ror #27
 *   @0x27e66c andeq r8, sp, r4, ror #27
 *   @0x27e670 andseq r3, r7, r12, asr #6
 *   @0x27e674 andeq r8, sp, r8, asr sp
 *   @0x27e678 andeq r8, sp, r8, lsr #25
 *   @0x27e67c push {r4, r5, r6, lr}
 *   @0x27e680 mov r4, r1
 *   @0x27e684 ldr r5, [pc, #0x30]
 *   @0x27e688 mov r6, r0
 *   @0x27e68c mov r0, r1
 *   @0x27e690 add r5, pc, r5
 *   @0x27e694 mov r1, r5
 *   @0x27e698 bl 0x280dbc <sprintbuf>
 *   @0x27e69c ldr r1, [r6, #0x18]
 *   @0x27e6a0 mov r0, r4
 *   @0x27e6a4 bl 0x27e458 <mc_info+0x90>
 *   @0x27e6a8 mov r0, r4
 *   @0x27e6ac mov r1, r5
 *   @0x27e6b0 bl 0x280dbc <sprintbuf>
 *   @0x27e6b4 mov r0, #0
 *   @0x27e6b8 pop {r4, r5, r6, pc}
 *   @0x27e6bc andeq r8, sp, r4, lsl r12
 *   @0x27e6c0 push {r4, lr}
 *   @0x27e6c4 mov r4, r0
 *   @0x27e6c8 ldr r0, [r0, #0x10]
 *   @0x27e6cc bl 0x280eb0 <printbuf_free>
 *   @0x27e6d0 mov r0, r4
 *   @0x27e6d4 pop {r4, lr}
 *   @0x27e6d8 b 0xb655c <free@plt>
 *   @0x27e6dc push {r4, lr}
 *   @0x27e6e0 mov r4, r0
 *   @0x27e6e4 ldr r0, [r0, #0x18]
 *   @0x27e6e8 bl 0x28094c <lh_table_free>
 *   @0x27e6ec ldr r0, [r4, #0x10]
 *   @0x27e6f0 bl 0x280eb0 <printbuf_free>
 *   @0x27e6f4 mov r0, r4
 *   @0x27e6f8 pop {r4, lr}
 *   @0x27e6fc b 0xb655c <free@plt>
 *   @0x27e700 push {r4, lr}
 *   @0x27e704 mov r4, r0
 *   @0x27e708 ldr r0, [r0, #0x18]
 *   @0x27e70c bl 0xb655c <free@plt>
 *   @0x27e710 ldr r0, [r4, #0x10]
 *   @0x27e714 bl 0x280eb0 <printbuf_free>
 *   @0x27e718 mov r0, r4
 *   @0x27e71c pop {r4, lr}
 *   @0x27e720 b 0xb655c <free@plt>
 *   @0x27e724 push {r4, lr}
 *   @0x27e728 mov r1, #1
 *   @0x27e72c mov r4, r0
 *   @0x27e730 mov r0, #32
 *   @0x27e734 bl 0xb6c34 <calloc@plt>
 *   @0x27e738 cmp r0, #0
 *   @0x27e73c popeq {r4, pc}
 *   @0x27e740 ldr r3, [pc, #0x14]
 *   @0x27e744 mov r2, #1
 *   @0x27e748 str r4, [r0]
 *   @0x27e74c add r3, pc, r3
 *   @0x27e750 str r2, [r0, #0xc]
 *   @0x27e754 str r3, [r0, #0x4]
 *   @0x27e758 pop {r4, pc}
 *   @0x27e75c .word 0xffffff6c
 *   @0x27e760 push {r4, lr}
 *   @0x27e764 mov r4, r0
 *   @0x27e768 ldr r0, [r0, #0x18]
 *   @0x27e76c bl 0x27e1b0 <array_list_free>
 *   @0x27e770 ldr r0, [r4, #0x10]
 *   @0x27e774 bl 0x280eb0 <printbuf_free>
 *   @0x27e778 mov r0, r4
 *   @0x27e77c pop {r4, lr}
 *   @0x27e780 b 0xb655c <free@plt>
 *   @0x27e784 ldr r3, [r0, #0x18]
 *   @0x27e788 mov r0, r1
 *   @0x27e78c cmp r3, #0
 *   @0x27e790 bne 0x27e7a0 <mc_info+0x3d8>
 *   @0x27e794 ldr r1, [pc, #0x10]
 *   @0x27e798 add r1, pc, r1
 *   @0x27e79c b 0x280dbc <sprintbuf>
 *   @0x27e7a0 ldr r1, [pc, #0x8]
 *   @0x27e7a4 add r1, pc, r1
 *   @0x27e7a8 b 0x280dbc <sprintbuf>
 *   @0x27e7ac muleq r11, r0, r2
 *
 * ══ §20/31 spSkeleton_create  0x289b40  size 932  233 条（0x289b40..0x289ee4）
 * @func 0x289b40 0x289ee4  size 932  233 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _malloc×8 / spSkeleton_create+0x384×3 / _calloc×2 / spBone_create×2 / spSkeleton_create+0xdc / spSkeleton_create+0x1e8 / spSlot_create / 0xb65bc
 * 字段偏移 top8: 0x2×18 / 0x8×11 / 0x10×7 / 0x4×5 / 0x14×5 / 0x3c×4 / 0x44×4 / 0xc×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x289b40 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x289b44 mov r1, #108
 *   @0x289b48 ldr r5, [pc, #0x37c]
 *   @0x289b4c mov r7, r0
 *   @0x289b50 mov r3, #59
 *   @0x289b54 mov r0, #1
 *   @0x289b58 add r5, pc, r5
 *   @0x289b5c mov r2, r5
 *   @0x289b60 bl 0x285c4c <_calloc>
 *   @0x289b64 mov r1, r5
 *   @0x289b68 mov r2, #64
 *   @0x289b6c mov r4, r0
 *   @0x289b70 ldr r0, [r7, #0x10]
 *   @0x289b74 str r7, [r4]
 *   @0x289b78 str r0, [r4, #0x4]
 *   @0x289b7c lsl r0, r0, #2
 *   @0x289b80 bl 0x285c10 <_malloc>
 *   @0x289b84 mov r3, #65
 *   @0x289b88 mov r2, r5
 *   @0x289b8c mov r1, #4
 *   @0x289b90 str r0, [r4, #0x8]
 *   @0x289b94 ldr r0, [r4, #0x4]
 *   @0x289b98 bl 0x285c4c <_calloc>
 *   @0x289b9c ldr r3, [r4, #0x4]
 *   @0x289ba0 cmp r3, #0
 *   @0x289ba4 mov r6, r0
 *   @0x289ba8 ble 0x289ec4 <spSkeleton_create+0x384>
 *   @0x289bac mov r5, #0
 *   @0x289bb0 b 0x289bf0 <spSkeleton_create+0xb0>
 *   @0x289bb4 ldr r3, [r4, #0x8]
 *   @0x289bb8 ldr r2, [r2]
 *   @0x289bbc ldr r2, [r3, r2, lsl #2]
 *   @0x289bc0 bl 0x2853c8 <spBone_create>
 *   @0x289bc4 ldr r3, [r8, #0x8]
 *   @0x289bc8 ldr r3, [r3]
 *   @0x289bcc ldr r2, [r6, r3, lsl #2]
 *   @0x289bd0 add r2, r2, #1
 *   @0x289bd4 str r2, [r6, r3, lsl #2]
 *   @0x289bd8 ldr r3, [r4, #0x4]
 *   @0x289bdc add r5, r5, #1
 *   @0x289be0 ldr r2, [r4, #0x8]
 *   @0x289be4 cmp r3, r5
 *   @0x289be8 str r0, [r2, r9]
 *   @0x289bec ble 0x289c1c <spSkeleton_create+0xdc>
 *   @0x289bf0 ldr r3, [r4]
 *   @0x289bf4 mov r1, r4
 *   @0x289bf8 lsl r9, r5, #2
 *   @0x289bfc ldr r3, [r3, #0x14]
 *   @0x289c00 ldr r8, [r3, r5, lsl #2]
 *   @0x289c04 ldr r2, [r8, #0x8]
 *   @0x289c08 mov r0, r8
 *   @0x289c0c cmp r2, #0
 *   @0x289c10 bne 0x289bb4 <spSkeleton_create+0x74>
 *   @0x289c14 bl 0x2853c8 <spBone_create>
 *   @0x289c18 b 0x289bd8 <spSkeleton_create+0x98>
 *   @0x289c1c cmp r3, #0
 *   @0x289c20 ble 0x289ec4 <spSkeleton_create+0x384>
 *   @0x289c24 ldr r9, [pc, #0x2a4]
 *   @0x289c28 mov r5, #0
 *   @0x289c2c add r9, pc, r9
 *   @0x289c30 ldr r3, [r4]
 *   @0x289c34 mov r1, r9
 *   @0x289c38 ldr r0, [r4, #0x8]
 *   @0x289c3c mov r2, #82
 *   @0x289c40 ldr r3, [r3, #0x14]
 *   @0x289c44 ldr r8, [r0, r5, lsl #2]
 *   @0x289c48 ldr r3, [r3, r5, lsl #2]
 *   @0x289c4c add r5, r5, #1
 *   @0x289c50 ldr r3, [r3]
 *   @0x289c54 ldr r0, [r6, r3, lsl #2]
 *   @0x289c58 lsl r0, r0, #2
 *   @0x289c5c bl 0x285c10 <_malloc>
 *   @0x289c60 ldr r12, [r4, #0x4]
 *   @0x289c64 cmp r12, r5
 *   @0x289c68 str r0, [r8, #0x10]
 *   @0x289c6c bgt 0x289c30 <spSkeleton_create+0xf0>
 *   @0x289c70 cmp r12, #0
 *   @0x289c74 ble 0x289ec4 <spSkeleton_create+0x384>
 *   @0x289c78 ldr r0, [r4, #0x8]
 *   @0x289c7c mov r2, #0
 *   @0x289c80 ldr r1, [r0, r2, lsl #2]
 *   @0x289c84 add r2, r2, #1
 *   @0x289c88 ldr r3, [r1, #0x8]
 *   @0x289c8c cmp r3, #0
 *   @0x289c90 beq 0x289cac <spSkeleton_create+0x16c>
 *   @0x289c94 ldr r0, [r3, #0xc]
 *   @0x289c98 ldr lr, [r3, #0x10]
 *   @0x289c9c add r5, r0, #1
 *   @0x289ca0 str r5, [r3, #0xc]
 *   @0x289ca4 str r1, [lr, r0, lsl #2]
 *   @0x289ca8 ldr r0, [r4, #0x8]
 *   @0x289cac cmp r2, r12
 *   @0x289cb0 bne 0x289c80 <spSkeleton_create+0x140>
 *   @0x289cb4 ldr r3, [r0]
 *   @0x289cb8 ldr r0, [r7, #0x18]
 *   @0x289cbc mov r2, #93
 *   @0x289cc0 ldr r1, [pc, #0x20c]
 *   @0x289cc4 str r3, [r4, #0xc]
 *   @0x289cc8 str r0, [r4, #0x10]
 *   @0x289ccc add r1, pc, r1
 *   @0x289cd0 lsl r0, r0, #2
 *   @0x289cd4 bl 0x285c10 <_malloc>
 *   @0x289cd8 ldr r3, [r4, #0x10]
 *   @0x289cdc cmp r3, #0
 *   @0x289ce0 str r0, [r4, #0x14]
 *   @0x289ce4 ble 0x289d28 <spSkeleton_create+0x1e8>
 *   @0x289ce8 mov r8, r0
 *   @0x289cec mov r5, #0
 *   @0x289cf0 b 0x289cf8 <spSkeleton_create+0x1b8>
 *   @0x289cf4 ldr r8, [r4, #0x14]
 *   @0x289cf8 ldr r2, [r7, #0x1c]
 *   @0x289cfc ldr r3, [r4, #0x8]
 *   @0x289d00 ldr r0, [r2, r5, lsl #2]
 *   @0x289d04 ldr r2, [r0, #0x8]
 *   @0x289d08 ldr r2, [r2]
 *   @0x289d0c ldr r1, [r3, r2, lsl #2]
 *   @0x289d10 bl 0x28eeec <spSlot_create>
 *   @0x289d14 ldr r3, [r4, #0x10]
 *   @0x289d18 str r0, [r8, r5, lsl #2]
 *   @0x289d1c add r5, r5, #1
 *   @0x289d20 cmp r3, r5
 *   @0x289d24 bgt 0x289cf4 <spSkeleton_create+0x1b4>
 *   @0x289d28 ldr r5, [pc, #0x1a8]
 *   @0x289d2c lsl r0, r3, #2
 *   @0x289d30 mov r2, #100
 *   @0x289d34 add r5, pc, r5
 *   @0x289d38 mov r1, r5
 *   @0x289d3c bl 0x285c10 <_malloc>
 *   @0x289d40 ldr r2, [r4, #0x10]
 *   @0x289d44 ldr r1, [r4, #0x14]
 *   @0x289d48 lsl r2, r2, #2
 *   @0x289d4c str r0, [r4, #0x18]
 *   @0x289d50 bl 0xb65bc <memcpy@plt>
 *   @0x289d54 ldr r0, [r7, #0x3c]
 *   @0x289d58 mov r1, r5
 *   @0x289d5c mov r2, #104
 *   @0x289d60 str r0, [r4, #0x1c]
 *   @0x289d64 lsl r0, r0, #2
 *   @0x289d68 bl 0x285c10 <_malloc>
 *   @0x289d6c ldr r3, [r4, #0x1c]
 *   @0x289d70 mov r1, r5
 *   @0x289d74 mov r2, #105
 *   @0x289d78 str r0, [r4, #0x20]
 *   @0x289d7c lsl r0, r3, #2
 *   @0x289d80 bl 0x285c10 <_malloc>
 *   @0x289d84 ldr r3, [r4]
 *   @0x289d88 ldr r2, [r3, #0x3c]
 *   @0x289d8c cmp r2, #0
 *   @0x289d90 movgt r5, #0
 *   @0x289d94 str r0, [r4, #0x24]
 *   @0x289d98 ble 0x289dc8 <spSkeleton_create+0x288>
 *   @0x289d9c ldr r3, [r3, #0x40]
 *   @0x289da0 mov r1, r4
 *   @0x289da4 ldr r8, [r4, #0x20]
 *   @0x289da8 ldr r0, [r3, r5, lsl #2]
 *   @0x289dac bl 0x285d64 <spIkConstraint_create>
 *   @0x289db0 str r0, [r8, r5, lsl #2]
 *   @0x289db4 add r5, r5, #1
 *   @0x289db8 ldr r3, [r4]
 *   @0x289dbc ldr r2, [r3, #0x3c]
 *   @0x289dc0 cmp r2, r5
 *   @0x289dc4 bgt 0x289d9c <spSkeleton_create+0x25c>
 *   @0x289dc8 ldr r0, [r7, #0x44]
 *   @0x289dcc mov r2, #110
 *   @0x289dd0 ldr r1, [pc, #0x104]
 *   @0x289dd4 str r0, [r4, #0x28]
 *   @0x289dd8 add r1, pc, r1
 *   @0x289ddc lsl r0, r0, #2
 *   @0x289de0 bl 0x285c10 <_malloc>
 *   @0x289de4 ldr r3, [r4]
 *   @0x289de8 ldr r2, [r3, #0x44]
 *   @0x289dec cmp r2, #0
 *   @0x289df0 movgt r5, #0
 *   @0x289df4 str r0, [r4, #0x2c]
 *   @0x289df8 movgt r8, r0
 *   @0x289dfc bgt 0x289e08 <spSkeleton_create+0x2c8>
 *   @0x289e00 b 0x289e30 <spSkeleton_create+0x2f0>
 *   @0x289e04 ldr r8, [r4, #0x2c]
 *   @0x289e08 ldr r3, [r3, #0x48]
 *   @0x289e0c mov r1, r4
 *   @0x289e10 ldr r0, [r3, r5, lsl #2]
 *   @0x289e14 bl 0x28f01c <spTransformConstraint_create>
 *   @0x289e18 str r0, [r8, r5, lsl #2]
 *   @0x289e1c add r5, r5, #1
 *   @0x289e20 ldr r3, [r4]
 *   @0x289e24 ldr r2, [r3, #0x44]
 *   @0x289e28 cmp r2, r5
 *   @0x289e2c bgt 0x289e04 <spSkeleton_create+0x2c4>
 *   @0x289e30 ldr r0, [r7, #0x4c]
 *   @0x289e34 mov r2, #115
 *   @0x289e38 ldr r1, [pc, #0xa0]
 *   @0x289e3c str r0, [r4, #0x30]
 *   @0x289e40 add r1, pc, r1
 *   @0x289e44 lsl r0, r0, #2
 *   @0x289e48 bl 0x285c10 <_malloc>
 *   @0x289e4c ldr r3, [r4]
 *   @0x289e50 ldr r2, [r3, #0x4c]
 *   @0x289e54 cmp r2, #0
 *   @0x289e58 movgt r5, #0
 *   @0x289e5c str r0, [r4, #0x34]
 *   @0x289e60 movgt r7, r0
 *   @0x289e64 bgt 0x289e70 <spSkeleton_create+0x330>
 *   @0x289e68 b 0x289e98 <spSkeleton_create+0x358>
 *   @0x289e6c ldr r7, [r4, #0x34]
 *   @0x289e70 ldr r3, [r3, #0x50]
 *   @0x289e74 mov r1, r4
 *   @0x289e78 ldr r0, [r3, r5, lsl #2]
 *   @0x289e7c bl 0x28796c <spPathConstraint_create>
 *   @0x289e80 str r0, [r7, r5, lsl #2]
 *   @0x289e84 add r5, r5, #1
 *   @0x289e88 ldr r3, [r4]
 *   @0x289e8c ldr r2, [r3, #0x4c]
 *   @0x289e90 cmp r2, r5
 *   @0x289e94 bgt 0x289e6c <spSkeleton_create+0x32c>
 *   @0x289e98 mov r3, #1065353216
 *   @0x289e9c mov r0, r4
 *   @0x289ea0 str r3, [r4, #0x3c]
 *   @0x289ea4 str r3, [r4, #0x40]
 *   @0x289ea8 str r3, [r4, #0x44]
 *   @0x289eac str r3, [r4, #0x48]
 *   @0x289eb0 bl 0x2895fc <spSkeleton_updateCache>
 *   @0x289eb4 mov r0, r6
 *   @0x289eb8 bl 0x285c80 <_free>
 *   @0x289ebc mov r0, r4
 *   @0x289ec0 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x289ec4 mov r3, #0
 *   @0x289ec8 b 0x289cb8 <spSkeleton_create+0x178>
 *   @0x289ecc ldrdeq sp, lr, [r12], -r12
 *   @0x289ed0 andeq sp, r12, r8, lsl #28
 *   @0x289ed4 andeq sp, r12, r8, ror #26
 *   @0x289ed8 andeq sp, r12, r0, lsl #26
 *   @0x289edc andeq sp, r12, r12, asr r12
 *   @0x289ee0 strdeq sp, lr, [r12], -r4
 *
 * ══ §21/31 vorbis_staticbook_unpack  0x227d30  size 928  232 条（0x227d30..0x2280d0）
 * @func 0x227d30 0x2280d0  size 928  232 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: oggpack_read×16 / vorbis_staticbook_unpack+0x158×4 / _ilog×3 / 0xb6544×3 / vorbis_staticbook_unpack+0x308×2 / oggpack_bytes×2 / 0xb6c34 / vorbis_staticbook_unpack+0x148
 * 字段偏移 top8: 0x4×11 / 0x8×5 / 0x10×3 / 0x18×3 / 0x20×3 / 0xc×2 / 0x2×2 / 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x227d30 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x227d34 mov r1, #36
 *   @0x227d38 mov r6, r0
 *   @0x227d3c mov r0, #1
 *   @0x227d40 bl 0xb6c34 <calloc@plt>
 *   @0x227d44 mov r1, #24
 *   @0x227d48 mov r5, r0
 *   @0x227d4c mov r0, r6
 *   @0x227d50 bl 0x233b28 <oggpack_read>
 *   @0x227d54 movw r3, #0x4342
 *   @0x227d58 movt r3, #0x56
 *   @0x227d5c cmp r0, r3
 *   @0x227d60 bne 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227d64 mov r1, #16
 *   @0x227d68 mov r0, r6
 *   @0x227d6c bl 0x233b28 <oggpack_read>
 *   @0x227d70 mov r1, #24
 *   @0x227d74 str r0, [r5]
 *   @0x227d78 mov r0, r6
 *   @0x227d7c bl 0x233b28 <oggpack_read>
 *   @0x227d80 cmn r0, #1
 *   @0x227d84 str r0, [r5, #0x4]
 *   @0x227d88 beq 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227d8c ldr r0, [r5]
 *   @0x227d90 bl 0x22eaf0 <_ilog>
 *   @0x227d94 mov r4, r0
 *   @0x227d98 ldr r0, [r5, #0x4]
 *   @0x227d9c bl 0x22eaf0 <_ilog>
 *   @0x227da0 add r0, r4, r0
 *   @0x227da4 cmp r0, #24
 *   @0x227da8 bgt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227dac mov r0, r6
 *   @0x227db0 mov r1, #1
 *   @0x227db4 bl 0x233b28 <oggpack_read>
 *   @0x227db8 subs r4, r0, #0
 *   @0x227dbc beq 0x227fa0 <vorbis_staticbook_unpack+0x270>
 *   @0x227dc0 cmp r4, #1
 *   @0x227dc4 bne 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227dc8 mov r0, r6
 *   @0x227dcc mov r1, #5
 *   @0x227dd0 bl 0x233b28 <oggpack_read>
 *   @0x227dd4 adds r4, r0, #1
 *   @0x227dd8 mov r9, r0
 *   @0x227ddc beq 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227de0 ldr r8, [r5, #0x4]
 *   @0x227de4 lsl r0, r8, #2
 *   @0x227de8 bl 0xb6544 <malloc@plt>
 *   @0x227dec cmp r8, #0
 *   @0x227df0 str r0, [r5, #0x8]
 *   @0x227df4 ble 0x227e88 <vorbis_staticbook_unpack+0x158>
 *   @0x227df8 add r9, r9, #2
 *   @0x227dfc mov r7, #0
 *   @0x227e00 rsb r0, r7, r8
 *   @0x227e04 bl 0x22eaf0 <_ilog>
 *   @0x227e08 mov r1, r0
 *   @0x227e0c mov r0, r6
 *   @0x227e10 bl 0x233b28 <oggpack_read>
 *   @0x227e14 cmn r0, #1
 *   @0x227e18 beq 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227e1c cmp r4, #32
 *   @0x227e20 bgt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227e24 ldr r8, [r5, #0x4]
 *   @0x227e28 rsb r3, r7, r8
 *   @0x227e2c cmp r0, r3
 *   @0x227e30 bgt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227e34 cmp r0, #0
 *   @0x227e38 ble 0x227e78 <vorbis_staticbook_unpack+0x148>
 *   @0x227e3c sub r1, r0, #1
 *   @0x227e40 asr r2, r4, #1
 *   @0x227e44 asr r3, r9, #1
 *   @0x227e48 asr r2, r1, r2
 *   @0x227e4c asrs r3, r2, r3
 *   @0x227e50 bne 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227e54 ldr r2, [r5, #0x8]
 *   @0x227e58 add r0, r7, r0
 *   @0x227e5c add r3, r2, r7, lsl #2
 *   @0x227e60 add r2, r2, r0, lsl #2
 *   @0x227e64 str r4, [r3], #4
 *   @0x227e68 cmp r3, r2
 *   @0x227e6c bne 0x227e64 <vorbis_staticbook_unpack+0x134>
 *   @0x227e70 ldr r8, [r5, #0x4]
 *   @0x227e74 mov r7, r0
 *   @0x227e78 cmp r8, r7
 *   @0x227e7c add r9, r9, #1
 *   @0x227e80 add r4, r4, #1
 *   @0x227e84 bgt 0x227e00 <vorbis_staticbook_unpack+0xd0>
 *   @0x227e88 mov r0, r6
 *   @0x227e8c mov r1, #4
 *   @0x227e90 bl 0x233b28 <oggpack_read>
 *   @0x227e94 cmp r0, #0
 *   @0x227e98 str r0, [r5, #0xc]
 *   @0x227e9c beq 0x227f98 <vorbis_staticbook_unpack+0x268>
 *   @0x227ea0 blt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227ea4 cmp r0, #2
 *   @0x227ea8 bgt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227eac mov r1, #32
 *   @0x227eb0 mov r0, r6
 *   @0x227eb4 bl 0x233b28 <oggpack_read>
 *   @0x227eb8 mov r1, #32
 *   @0x227ebc str r0, [r5, #0x10]
 *   @0x227ec0 mov r0, r6
 *   @0x227ec4 bl 0x233b28 <oggpack_read>
 *   @0x227ec8 mov r1, #4
 *   @0x227ecc str r0, [r5, #0x14]
 *   @0x227ed0 mov r0, r6
 *   @0x227ed4 bl 0x233b28 <oggpack_read>
 *   @0x227ed8 mov r1, #1
 *   @0x227edc add r3, r0, r1
 *   @0x227ee0 mov r0, r6
 *   @0x227ee4 str r3, [r5, #0x18]
 *   @0x227ee8 bl 0x233b28 <oggpack_read>
 *   @0x227eec cmn r0, #1
 *   @0x227ef0 str r0, [r5, #0x1c]
 *   @0x227ef4 beq 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227ef8 ldr r3, [r5, #0xc]
 *   @0x227efc cmp r3, #1
 *   @0x227f00 beq 0x2280ac <vorbis_staticbook_unpack+0x37c>
 *   @0x227f04 cmp r3, #2
 *   @0x227f08 bne 0x2280a4 <vorbis_staticbook_unpack+0x374>
 *   @0x227f0c ldr r3, [r5, #0x4]
 *   @0x227f10 ldr r8, [r5]
 *   @0x227f14 mul r8, r8, r3
 *   @0x227f18 mov r0, r6
 *   @0x227f1c ldr r4, [r5, #0x18]
 *   @0x227f20 ldr r7, [r6, #0x10]
 *   @0x227f24 bl 0x233e28 <oggpack_bytes>
 *   @0x227f28 mul r4, r4, r8
 *   @0x227f2c add r4, r4, #7
 *   @0x227f30 asr r4, r4, #3
 *   @0x227f34 rsb r0, r0, r7
 *   @0x227f38 cmp r4, r0
 *   @0x227f3c bgt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227f40 lsl r9, r8, #2
 *   @0x227f44 mov r0, r9
 *   @0x227f48 bl 0xb6544 <malloc@plt>
 *   @0x227f4c cmp r8, #0
 *   @0x227f50 str r0, [r5, #0x20]
 *   @0x227f54 ble 0x2280c8 <vorbis_staticbook_unpack+0x398>
 *   @0x227f58 mov r7, r0
 *   @0x227f5c mov r4, #0
 *   @0x227f60 b 0x227f68 <vorbis_staticbook_unpack+0x238>
 *   @0x227f64 ldr r7, [r5, #0x20]
 *   @0x227f68 mov r0, r6
 *   @0x227f6c ldr r1, [r5, #0x18]
 *   @0x227f70 bl 0x233b28 <oggpack_read>
 *   @0x227f74 str r0, [r7, r4, lsl #2]
 *   @0x227f78 add r4, r4, #1
 *   @0x227f7c cmp r4, r8
 *   @0x227f80 bne 0x227f64 <vorbis_staticbook_unpack+0x234>
 *   @0x227f84 ldr r0, [r5, #0x20]
 *   @0x227f88 add r0, r0, r9
 *   @0x227f8c ldr r3, [r0, #-0x4]
 *   @0x227f90 cmn r3, #1
 *   @0x227f94 beq 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227f98 mov r0, r5
 *   @0x227f9c pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x227fa0 mov r1, #1
 *   @0x227fa4 mov r0, r6
 *   @0x227fa8 bl 0x233b28 <oggpack_read>
 *   @0x227fac ldr r9, [r5, #0x4]
 *   @0x227fb0 ldr r8, [r6, #0x10]
 *   @0x227fb4 mov r7, r0
 *   @0x227fb8 mov r0, r6
 *   @0x227fbc bl 0x233e28 <oggpack_bytes>
 *   @0x227fc0 cmp r7, #0
 *   @0x227fc4 moveq r3, #5
 *   @0x227fc8 movne r3, #1
 *   @0x227fcc mul r3, r3, r9
 *   @0x227fd0 rsb r0, r0, r8
 *   @0x227fd4 add r3, r3, #7
 *   @0x227fd8 cmp r0, r3, asr #3
 *   @0x227fdc blt 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x227fe0 ldr r8, [r5, #0x4]
 *   @0x227fe4 lsl r0, r8, #2
 *   @0x227fe8 bl 0xb6544 <malloc@plt>
 *   @0x227fec cmp r7, #0
 *   @0x227ff0 str r0, [r5, #0x8]
 *   @0x227ff4 bne 0x228048 <vorbis_staticbook_unpack+0x318>
 *   @0x227ff8 cmp r8, #0
 *   @0x227ffc movgt r4, r7
 *   @0x228000 bgt 0x228020 <vorbis_staticbook_unpack+0x2f0>
 *   @0x228004 b 0x227e88 <vorbis_staticbook_unpack+0x158>
 *   @0x228008 ldr r2, [r5, #0x8]
 *   @0x22800c str r3, [r2, r4, lsl #2]
 *   @0x228010 add r4, r4, #1
 *   @0x228014 ldr r3, [r5, #0x4]
 *   @0x228018 cmp r3, r4
 *   @0x22801c ble 0x227e88 <vorbis_staticbook_unpack+0x158>
 *   @0x228020 mov r0, r6
 *   @0x228024 mov r1, #5
 *   @0x228028 bl 0x233b28 <oggpack_read>
 *   @0x22802c cmn r0, #1
 *   @0x228030 add r3, r0, #1
 *   @0x228034 bne 0x228008 <vorbis_staticbook_unpack+0x2d8>
 *   @0x228038 mov r0, r5
 *   @0x22803c bl 0x22f554 <vorbis_staticbook_destroy>
 *   @0x228040 mov r0, #0
 *   @0x228044 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x228048 cmp r8, #0
 *   @0x22804c ble 0x227e88 <vorbis_staticbook_unpack+0x158>
 *   @0x228050 mov r7, r4
 *   @0x228054 b 0x228074 <vorbis_staticbook_unpack+0x344>
 *   @0x228058 ldr r3, [r5, #0x8]
 *   @0x22805c add r7, r7, #1
 *   @0x228060 str r0, [r3, r4]
 *   @0x228064 add r4, r4, #4
 *   @0x228068 ldr r3, [r5, #0x4]
 *   @0x22806c cmp r3, r7
 *   @0x228070 ble 0x227e88 <vorbis_staticbook_unpack+0x158>
 *   @0x228074 mov r0, r6
 *   @0x228078 mov r1, #1
 *   @0x22807c bl 0x233b28 <oggpack_read>
 *   @0x228080 cmp r0, #0
 *   @0x228084 beq 0x228058 <vorbis_staticbook_unpack+0x328>
 *   @0x228088 mov r0, r6
 *   @0x22808c mov r1, #5
 *   @0x228090 bl 0x233b28 <oggpack_read>
 *   @0x228094 cmn r0, #1
 *   @0x228098 add r0, r0, #1
 *   @0x22809c bne 0x228058 <vorbis_staticbook_unpack+0x328>
 *   @0x2280a0 b 0x228038 <vorbis_staticbook_unpack+0x308>
 *   @0x2280a4 mov r8, #0
 *   @0x2280a8 b 0x227f18 <vorbis_staticbook_unpack+0x1e8>
 *   @0x2280ac ldr r8, [r5]
 *   @0x2280b0 cmp r8, #0
 *   @0x2280b4 beq 0x227f18 <vorbis_staticbook_unpack+0x1e8>
 *   @0x2280b8 mov r0, r5
 *   @0x2280bc bl 0x22ed88 <_book_maptype1_quantvals>
 *   @0x2280c0 mov r8, r0
 *   @0x2280c4 b 0x227f18 <vorbis_staticbook_unpack+0x1e8>
 *   @0x2280c8 beq 0x227f98 <vorbis_staticbook_unpack+0x268>
 *   @0x2280cc b 0x227f88 <vorbis_staticbook_unpack+0x258>
 *
 * ══ §22/31 YYCompareVal  0x2026c4  size 924  231 条（0x2026c4..0x202a60）
 * @func 0x2026c4 0x202a60  size 924  231 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: __fixdfdi×2 / YYCompareVal(RValue const&, RValue const&, double)+0x188×2 / YYCompareVal(RValue const&, RValue const&, double)+0x84 / YYCompareVal(RValue const&, RValue const&, double)+0x26c / YYCompareVal(RValue const&, RValue const&, double)+0x1b8 / YYCompareVal(RValue const&, RValue const&, double)+0x248 / YYCompareVal(RValue const&, RValue const&, double)+0x1f0 / YYCompareVal(RValue const&, RValue const&, double)+0x16c
 * 字段偏移 top8: 0x4×12 / 0xc×2
 * VFP 指令 35 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2026c4 push {r4, r5, r6, lr}
 *   @0x2026c8 mov r6, r1
 *   @0x2026cc ldr r1, [r0, #0xc]
 *   @0x2026d0 vmov d7, r2, r3
 *   @0x2026d4 ldr r3, [r6, #0xc]
 *   @0x2026d8 bic r2, r1, #-16777216
 *   @0x2026dc bic r3, r3, #-16777216
 *   @0x2026e0 add r3, r3, r2, lsl #4
 *   @0x2026e4 cmp r3, #119
 *   @0x2026e8 beq 0x202a10 <_Z12YYCompareValRK6RValueS1_d+0x34c>
 *   @0x2026ec ble 0x202748 <_Z12YYCompareValRK6RValueS1_d+0x84>
 *   @0x2026f0 cmp r3, #170
 *   @0x2026f4 beq 0x2029ec <_Z12YYCompareValRK6RValueS1_d+0x328>
 *   @0x2026f8 bgt 0x2027b4 <_Z12YYCompareValRK6RValueS1_d+0xf0>
 *   @0x2026fc cmp r3, #125
 *   @0x202700 beq 0x202854 <_Z12YYCompareValRK6RValueS1_d+0x190>
 *   @0x202704 ble 0x202930 <_Z12YYCompareValRK6RValueS1_d+0x26c>
 *   @0x202708 cmp r3, #160
 *   @0x20270c beq 0x2027c8 <_Z12YYCompareValRK6RValueS1_d+0x104>
 *   @0x202710 cmp r3, #167
 *   @0x202714 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202718 ldr r1, [r6]
 *   @0x20271c ldr r2, [r0]
 *   @0x202720 ldr r3, [r0, #0x4]
 *   @0x202724 subs r2, r2, r1
 *   @0x202728 sbc r3, r3, r1, asr #31
 *   @0x20272c orrs r1, r2, r3
 *   @0x202730 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x202734 cmp r2, #0
 *   @0x202738 sbcs r1, r3, #0
 *   @0x20273c mvnlt r0, #0
 *   @0x202740 movge r0, #1
 *   @0x202744 pop {r4, r5, r6, pc}
 *   @0x202748 cmp r3, #17
 *   @0x20274c beq 0x20298c <_Z12YYCompareValRK6RValueS1_d+0x2c8>
 *   @0x202750 ble 0x20287c <_Z12YYCompareValRK6RValueS1_d+0x1b8>
 *   @0x202754 cmp r3, #51
 *   @0x202758 beq 0x202838 <_Z12YYCompareValRK6RValueS1_d+0x174>
 *   @0x20275c ble 0x20290c <_Z12YYCompareValRK6RValueS1_d+0x248>
 *   @0x202760 cmp r3, #85
 *   @0x202764 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x202768 cmp r3, #112
 *   @0x20276c bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202770 ldr r2, [r6]
 *   @0x202774 vldr s11, [r0]
 *   @0x202778 ldr r3, [r6, #0x4]
 *   @0x20277c vcvt.f32.s32 s11, s11
 *   @0x202780 vmov d4, r2, r3
 *   @0x202784 vcvt.f32.f64 s13, d4
 *   @0x202788 vsub.f32 s11, s11, s13
 *   @0x20278c vabs.f32 s12, s11
 *   @0x202790 vcvt.f64.f32 d6, s12
 *   @0x202794 vcmpe.f64 d6, d7
 *   @0x202798 vmrs APSR_nzcv, fpscr
 *   @0x20279c bls 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x2027a0 vcmpe.f32 s11, #0
 *   @0x2027a4 vmrs APSR_nzcv, fpscr
 *   @0x2027a8 mvnmi r0, #0
 *   @0x2027ac movpl r0, #1
 *   @0x2027b0 pop {r4, r5, r6, pc}
 *   @0x2027b4 cmp r3, #215
 *   @0x2027b8 beq 0x202808 <_Z12YYCompareValRK6RValueS1_d+0x144>
 *   @0x2027bc bgt 0x2028bc <_Z12YYCompareValRK6RValueS1_d+0x1f8>
 *   @0x2027c0 cmp r3, #173
 *   @0x2027c4 bne 0x2029d4 <_Z12YYCompareValRK6RValueS1_d+0x310>
 *   @0x2027c8 ldr r3, [r6, #0x4]
 *   @0x2027cc ldr r2, [r6]
 *   @0x2027d0 ldr r4, [r0]
 *   @0x2027d4 ldr r5, [r0, #0x4]
 *   @0x2027d8 mov r1, r3
 *   @0x2027dc mov r0, r2
 *   @0x2027e0 bl 0x3194a0 <__fixdfdi>
 *   @0x2027e4 subs r0, r4, r0
 *   @0x2027e8 sbc r1, r5, r1
 *   @0x2027ec orrs r3, r0, r1
 *   @0x2027f0 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x2027f4 cmp r0, #0
 *   @0x2027f8 sbcs r3, r1, #0
 *   @0x2027fc mvnlt r0, #0
 *   @0x202800 movge r0, #1
 *   @0x202804 pop {r4, r5, r6, pc}
 *   @0x202808 ldr r2, [r0]
 *   @0x20280c ldr r3, [r0, #0x4]
 *   @0x202810 ldr r1, [r6]
 *   @0x202814 vmov d4, r2, r3
 *   @0x202818 vcvt.s32.f64 s9, d4
 *   @0x20281c vmov r0, s9
 *   @0x202820 rsb r0, r1, r0
 *   @0x202824 cmp r0, #0
 *   @0x202828 popeq {r4, r5, r6, pc}
 *   @0x20282c blt 0x20284c <_Z12YYCompareValRK6RValueS1_d+0x188>
 *   @0x202830 mov r0, #1
 *   @0x202834 pop {r4, r5, r6, pc}
 *   @0x202838 ldr r2, [r0]
 *   @0x20283c ldr r3, [r6]
 *   @0x202840 cmp r2, r3
 *   @0x202844 beq 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x202848 blo 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c>
 *   @0x20284c mvn r0, #0
 *   @0x202850 pop {r4, r5, r6, pc}
 *   @0x202854 ldr r2, [r6]
 *   @0x202858 ldr r3, [r6, #0x4]
 *   @0x20285c ldr r1, [r0]
 *   @0x202860 vmov d5, r2, r3
 *   @0x202864 vcvt.s32.f64 s11, d5
 *   @0x202868 vmov r0, s11
 *   @0x20286c rsb r0, r0, r1
 *   @0x202870 cmp r0, #0
 *   @0x202874 bne 0x20282c <_Z12YYCompareValRK6RValueS1_d+0x168>
 *   @0x202878 pop {r4, r5, r6, pc}
 *   @0x20287c cmp r3, #7
 *   @0x202880 beq 0x202958 <_Z12YYCompareValRK6RValueS1_d+0x294>
 *   @0x202884 ble 0x202a28 <_Z12YYCompareValRK6RValueS1_d+0x364>
 *   @0x202888 cmp r3, #10
 *   @0x20288c bne 0x202a34 <_Z12YYCompareValRK6RValueS1_d+0x370>
 *   @0x202890 ldm r0, {r2, r3}
 *   @0x202894 mov r0, r2
 *   @0x202898 mov r1, r3
 *   @0x20289c bl 0x3194a0 <__fixdfdi>
 *   @0x2028a0 ldm r6, {r2, r3}
 *   @0x2028a4 subs r0, r0, r2
 *   @0x2028a8 sbc r1, r1, r3
 *   @0x2028ac orrs r3, r0, r1
 *   @0x2028b0 bne 0x2027f4 <_Z12YYCompareValRK6RValueS1_d+0x130>
 *   @0x2028b4 mov r0, #0
 *   @0x2028b8 pop {r4, r5, r6, pc}
 *   @0x2028bc cmp r3, #218
 *   @0x2028c0 beq 0x202890 <_Z12YYCompareValRK6RValueS1_d+0x1cc>
 *   @0x2028c4 cmp r3, #221
 *   @0x2028c8 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x2028cc ldr r4, [r0]
 *   @0x2028d0 ldr r2, [r6]
 *   @0x2028d4 ldr r5, [r0, #0x4]
 *   @0x2028d8 ldr r3, [r6, #0x4]
 *   @0x2028dc vmov d4, r4, r5
 *   @0x2028e0 vmov d5, r2, r3
 *   @0x2028e4 vsub.f64 d6, d4, d5
 *   @0x2028e8 vabs.f64 d5, d6
 *   @0x2028ec vcmpe.f64 d7, d5
 *   @0x2028f0 vmrs APSR_nzcv, fpscr
 *   @0x2028f4 bge 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x2028f8 vcmpe.f64 d6, #0
 *   @0x2028fc vmrs APSR_nzcv, fpscr
 *   @0x202900 mvnmi r0, #0
 *   @0x202904 movpl r0, #1
 *   @0x202908 pop {r4, r5, r6, pc}
 *   @0x20290c cmp r3, #34
 *   @0x202910 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202914 ldr r3, [r0]
 *   @0x202918 cmp r3, #0
 *   @0x20291c beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c>
 *   @0x202920 ldr r0, [r6]
 *   @0x202924 subs r0, r3, r0
 *   @0x202928 movne r0, #1
 *   @0x20292c pop {r4, r5, r6, pc}
 *   @0x202930 cmp r3, #122
 *   @0x202934 bne 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202938 ldr r1, [r0]
 *   @0x20293c ldr r2, [r6]
 *   @0x202940 ldr r3, [r6, #0x4]
 *   @0x202944 rsbs r2, r2, r1
 *   @0x202948 rsc r3, r3, r1, asr #31
 *   @0x20294c orrs r1, r2, r3
 *   @0x202950 bne 0x202734 <_Z12YYCompareValRK6RValueS1_d+0x70>
 *   @0x202954 b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x202958 ldr r2, [r0]
 *   @0x20295c vldr s13, [r6]
 *   @0x202960 ldr r3, [r0, #0x4]
 *   @0x202964 vcvt.f32.s32 s13, s13
 *   @0x202968 vmov d4, r2, r3
 *   @0x20296c vcvt.f32.f64 s11, d4
 *   @0x202970 vsub.f32 s11, s11, s13
 *   @0x202974 vabs.f32 s12, s11
 *   @0x202978 vcvt.f64.f32 d6, s12
 *   @0x20297c vcmpe.f64 d7, d6
 *   @0x202980 vmrs APSR_nzcv, fpscr
 *   @0x202984 blt 0x2027a0 <_Z12YYCompareValRK6RValueS1_d+0xdc>
 *   @0x202988 b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x20298c ldr r3, [r0]
 *   @0x202990 cmp r3, #0
 *   @0x202994 beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c>
 *   @0x202998 ldr r2, [r6]
 *   @0x20299c cmp r2, #0
 *   @0x2029a0 beq 0x202830 <_Z12YYCompareValRK6RValueS1_d+0x16c>
 *   @0x2029a4 ldr r0, [r3]
 *   @0x2029a8 cmp r0, #0
 *   @0x2029ac beq 0x202a50 <_Z12YYCompareValRK6RValueS1_d+0x38c>
 *   @0x2029b0 ldr r1, [r2]
 *   @0x2029b4 cmp r1, #0
 *   @0x2029b8 beq 0x202a40 <_Z12YYCompareValRK6RValueS1_d+0x37c>
 *   @0x2029bc bl 0xb6574 <strcmp@plt>
 *   @0x2029c0 cmp r0, #0
 *   @0x2029c4 blt 0x20284c <_Z12YYCompareValRK6RValueS1_d+0x188>
 *   @0x2029c8 moveq r0, #0
 *   @0x2029cc movne r0, #1
 *   @0x2029d0 pop {r4, r5, r6, pc}
 *   @0x2029d4 cmp r3, #208
 *   @0x2029d8 beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208>
 *   @0x2029dc cmp r2, #0
 *   @0x2029e0 mvneq r0, #0
 *   @0x2029e4 movne r0, #1
 *   @0x2029e8 pop {r4, r5, r6, pc}
 *   @0x2029ec ldr r4, [r0]
 *   @0x2029f0 ldr r2, [r6]
 *   @0x2029f4 ldr r5, [r0, #0x4]
 *   @0x2029f8 ldr r3, [r6, #0x4]
 *   @0x2029fc subs r2, r4, r2
 *   @0x202a00 sbc r3, r5, r3
 *   @0x202a04 orrs r1, r2, r3
 *   @0x202a08 bne 0x202734 <_Z12YYCompareValRK6RValueS1_d+0x70>
 *   @0x202a0c b 0x2028b4 <_Z12YYCompareValRK6RValueS1_d+0x1f0>
 *   @0x202a10 ldr r0, [r0]
 *   @0x202a14 ldr r3, [r6]
 *   @0x202a18 rsb r0, r3, r0
 *   @0x202a1c cmp r0, #0
 *   @0x202a20 bne 0x20282c <_Z12YYCompareValRK6RValueS1_d+0x168>
 *   @0x202a24 pop {r4, r5, r6, pc}
 *   @0x202a28 cmp r3, #0
 *   @0x202a2c beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208>
 *   @0x202a30 b 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202a34 cmp r3, #13
 *   @0x202a38 beq 0x2028cc <_Z12YYCompareValRK6RValueS1_d+0x208>
 *   @0x202a3c b 0x2029dc <_Z12YYCompareValRK6RValueS1_d+0x318>
 *   @0x202a40 ldrb r0, [r0]
 *   @0x202a44 adds r0, r0, #0
 *   @0x202a48 movne r0, #1
 *   @0x202a4c pop {r4, r5, r6, pc}
 *   @0x202a50 ldr r0, [r2]
 *   @0x202a54 cmp r0, #0
 *   @0x202a58 bne 0x202a40 <_Z12YYCompareValRK6RValueS1_d+0x37c>
 *   @0x202a5c pop {r4, r5, r6, pc}
 *
 * ══ §23/31 b2WorldManifold::Initialize  0x2c32c8  size 924  231 条（0x2c32c8..0x2c3664）
 * @func 0x2c32c8 0x2c3664  size 924  231 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float)+0x40 / b2WorldManifold::Initialize(b2Manifold const*, b2Transform const&, float, b2Transform const&, float)+0x308 / 0xb6700
 * 字段偏移 top8: 0x3c×1 / 0x20×1 / 0x38×1
 * VFP 指令 187 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2c32c8 push {r4, lr}
 *   @0x2c32cc vpush {d8, d9, d10}
 *   @0x2c32d0 mov r4, r0
 *   @0x2c32d4 vldr s17, [sp, #36]
 *   @0x2c32d8 ldr r0, [r1, #0x3c]
 *   @0x2c32dc vmov s16, r3
 *   @0x2c32e0 ldr r12, [sp, #0x20]
 *   @0x2c32e4 cmp r0, #0
 *   @0x2c32e8 beq 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40>
 *   @0x2c32ec ldr r3, [r1, #0x38]
 *   @0x2c32f0 cmp r3, #1
 *   @0x2c32f4 beq 0x2c3310 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x48>
 *   @0x2c32f8 cmp r3, #2
 *   @0x2c32fc beq 0x2c34dc <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x214>
 *   @0x2c3300 cmp r3, #0
 *   @0x2c3304 beq 0x2c3410 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x148>
 *   @0x2c3308 vpop {d8, d9, d10}
 *   @0x2c330c pop {r4, pc}
 *   @0x2c3310 vldr s14, [r2, #12]
 *   @0x2c3314 vldr s15, [r2, #8]
 *   @0x2c3318 vldr s12, [r1, #44]
 *   @0x2c331c vmul.f32 s11, s14, s12
 *   @0x2c3320 vldr s13, [r1, #40]
 *   @0x2c3324 vldr s6, [r2]
 *   @0x2c3328 vldr s9, [r2, #4]
 *   @0x2c332c cmp r0, #0
 *   @0x2c3330 vmul.f32 s12, s15, s12
 *   @0x2c3334 vmla.f32 s11, s13, s15
 *   @0x2c3338 vnmls.f32 s12, s14, s13
 *   @0x2c333c vstr s11, [r4, #4]
 *   @0x2c3340 vstr s12, [r4]
 *   @0x2c3344 vldr s5, [r1, #52]
 *   @0x2c3348 vmul.f32 s13, s15, s5
 *   @0x2c334c vldr s10, [r1, #48]
 *   @0x2c3350 vmul.f32 s5, s14, s5
 *   @0x2c3354 vnmls.f32 s13, s14, s10
 *   @0x2c3358 vmla.f32 s5, s15, s10
 *   @0x2c335c vadd.f32 s6, s13, s6
 *   @0x2c3360 vadd.f32 s5, s5, s9
 *   @0x2c3364 ble 0x2c3308 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x40>
 *   @0x2c3368 add r3, r4, #8
 *   @0x2c336c mov r2, #0
 *   @0x2c3370 vldr s8, [r12, #12]
 *   @0x2c3374 vldr s9, [r12, #8]
 *   @0x2c3378 vldr s3, [r12]
 *   @0x2c337c vldr s4, [r12, #4]
 *   @0x2c3380 vmov.f32 s10, #5.000000e-01
 *   @0x2c3384 b 0x2c3390 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc8>
 *   @0x2c3388 vldr s12, [r4]
 *   @0x2c338c vldr s11, [r4, #4]
 *   @0x2c3390 vldr s14, [r1, #4]
 *   @0x2c3394 vmul.f32 s15, s14, s8
 *   @0x2c3398 vldr s13, [r1]
 *   @0x2c339c add r2, r2, #1
 *   @0x2c33a0 cmp r2, r0
 *   @0x2c33a4 add r1, r1, #20
 *   @0x2c33a8 add r3, r3, #8
 *   @0x2c33ac vmla.f32 s15, s13, s9
 *   @0x2c33b0 vmul.f32 s14, s14, s9
 *   @0x2c33b4 vnmls.f32 s14, s13, s8
 *   @0x2c33b8 vadd.f32 s15, s15, s4
 *   @0x2c33bc vsub.f32 s13, s15, s5
 *   @0x2c33c0 vadd.f32 s14, s14, s3
 *   @0x2c33c4 vmul.f32 s13, s13, s11
 *   @0x2c33c8 vsub.f32 s7, s14, s6
 *   @0x2c33cc vmla.f32 s13, s7, s12
 *   @0x2c33d0 vsub.f32 s13, s16, s13
 *   @0x2c33d4 vmov.f32 s7, s14
 *   @0x2c33d8 vmla.f32 s14, s13, s12
 *   @0x2c33dc vmls.f32 s7, s17, s12
 *   @0x2c33e0 vmov.f32 s12, s15
 *   @0x2c33e4 vmls.f32 s15, s17, s11
 *   @0x2c33e8 vmla.f32 s12, s13, s11
 *   @0x2c33ec vadd.f32 s14, s14, s7
 *   @0x2c33f0 vadd.f32 s15, s12, s15
 *   @0x2c33f4 vmul.f32 s14, s14, s10
 *   @0x2c33f8 vmul.f32 s15, s15, s10
 *   @0x2c33fc vstr s14, [r3, #-8]
 *   @0x2c3400 vstr s15, [r3, #-4]
 *   @0x2c3404 bne 0x2c3388 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0xc0>
 *   @0x2c3408 vpop {d8, d9, d10}
 *   @0x2c340c pop {r4, pc}
 *   @0x2c3410 vldr s8, [r2, #12]
 *   @0x2c3414 vldr s10, [r12, #12]
 *   @0x2c3418 vldr s4, [pc, #568]
 *   @0x2c341c vstr s4, [r4, #4]
 *   @0x2c3420 vldr s13, [r1, #52]
 *   @0x2c3424 vldr s7, [r1, #4]
 *   @0x2c3428 vmul.f32 s12, s8, s13
 *   @0x2c342c vldr s6, [r2, #8]
 *   @0x2c3430 vldr s14, [r12, #8]
 *   @0x2c3434 vldr s19, [r2, #4]
 *   @0x2c3438 vldr s18, [r12, #4]
 *   @0x2c343c vldr s3, [pc, #536]
 *   @0x2c3440 vmul.f32 s15, s10, s7
 *   @0x2c3444 vmov.f32 s5, #1.000000e+00
 *   @0x2c3448 vmul.f32 s13, s6, s13
 *   @0x2c344c vstr s5, [r4]
 *   @0x2c3450 vldr s9, [r1, #48]
 *   @0x2c3454 vldr s11, [r1]
 *   @0x2c3458 vldr s21, [r2]
 *   @0x2c345c vldr s20, [r12]
 *   @0x2c3460 vmla.f32 s15, s11, s14
 *   @0x2c3464 vmla.f32 s12, s9, s6
 *   @0x2c3468 vmul.f32 s14, s14, s7
 *   @0x2c346c vnmls.f32 s13, s8, s9
 *   @0x2c3470 vnmls.f32 s14, s10, s11
 *   @0x2c3474 vadd.f32 s19, s12, s19
 *   @0x2c3478 vadd.f32 s18, s15, s18
 *   @0x2c347c vsub.f32 s15, s19, s18
 *   @0x2c3480 vadd.f32 s21, s13, s21
 *   @0x2c3484 vadd.f32 s20, s14, s20
 *   @0x2c3488 vmul.f32 s15, s15, s15
 *   @0x2c348c vsub.f32 s14, s21, s20
 *   @0x2c3490 vmla.f32 s15, s14, s14
 *   @0x2c3494 vcmpe.f32 s15, s3
 *   @0x2c3498 vmrs APSR_nzcv, fpscr
 *   @0x2c349c vmovle.f32 s15, s4
 *   @0x2c34a0 vmovle.f32 s14, s5
 *   @0x2c34a4 bgt 0x2c35e8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x320>
 *   @0x2c34a8 vmla.f32 s21, s16, s14
 *   @0x2c34ac vmls.f32 s20, s17, s14
 *   @0x2c34b0 vmla.f32 s19, s16, s15
 *   @0x2c34b4 vmls.f32 s18, s17, s15
 *   @0x2c34b8 vadd.f32 s20, s21, s20
 *   @0x2c34bc vmov.f32 s11, #5.000000e-01
 *   @0x2c34c0 vadd.f32 s18, s19, s18
 *   @0x2c34c4 vmul.f32 s20, s20, s11
 *   @0x2c34c8 vmul.f32 s11, s18, s11
 *   @0x2c34cc vstr s20, [r4, #8]
 *   @0x2c34d0 vpop {d8, d9, d10}
 *   @0x2c34d4 vstr s11, [r4, #12]
 *   @0x2c34d8 pop {r4, pc}
 *   @0x2c34dc vldr s14, [r12, #12]
 *   @0x2c34e0 vldr s15, [r12, #8]
 *   @0x2c34e4 vldr s12, [r1, #44]
 *   @0x2c34e8 vmul.f32 s11, s14, s12
 *   @0x2c34ec vldr s13, [r1, #40]
 *   @0x2c34f0 vldr s6, [r12]
 *   @0x2c34f4 vldr s9, [r12, #4]
 *   @0x2c34f8 cmp r0, #0
 *   @0x2c34fc vmul.f32 s12, s15, s12
 *   @0x2c3500 vmla.f32 s11, s13, s15
 *   @0x2c3504 vnmls.f32 s12, s14, s13
 *   @0x2c3508 vstr s11, [r4, #4]
 *   @0x2c350c vstr s12, [r4]
 *   @0x2c3510 vldr s5, [r1, #52]
 *   @0x2c3514 vmul.f32 s13, s15, s5
 *   @0x2c3518 vldr s10, [r1, #48]
 *   @0x2c351c vmul.f32 s5, s14, s5
 *   @0x2c3520 vnmls.f32 s13, s14, s10
 *   @0x2c3524 vmla.f32 s5, s15, s10
 *   @0x2c3528 vadd.f32 s6, s13, s6
 *   @0x2c352c vadd.f32 s5, s5, s9
 *   @0x2c3530 ble 0x2c35d0 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x308>
 *   @0x2c3534 add r3, r4, #8
 *   @0x2c3538 mov r12, #0
 *   @0x2c353c vldr s8, [r2, #12]
 *   @0x2c3540 vldr s9, [r2, #8]
 *   @0x2c3544 vldr s3, [r2]
 *   @0x2c3548 vldr s4, [r2, #4]
 *   @0x2c354c vmov.f32 s10, #5.000000e-01
 *   @0x2c3550 vldr s14, [r1, #4]
 *   @0x2c3554 vldr s13, [r1]
 *   @0x2c3558 add r12, r12, #1
 *   @0x2c355c add r1, r1, #20
 *   @0x2c3560 cmp r12, r0
 *   @0x2c3564 add r3, r3, #8
 *   @0x2c3568 vmul.f32 s15, s14, s8
 *   @0x2c356c vmul.f32 s14, s14, s9
 *   @0x2c3570 vmla.f32 s15, s13, s9
 *   @0x2c3574 vnmls.f32 s14, s13, s8
 *   @0x2c3578 vadd.f32 s15, s15, s4
 *   @0x2c357c vsub.f32 s13, s15, s5
 *   @0x2c3580 vadd.f32 s14, s14, s3
 *   @0x2c3584 vmul.f32 s13, s13, s11
 *   @0x2c3588 vsub.f32 s7, s14, s6
 *   @0x2c358c vmla.f32 s13, s7, s12
 *   @0x2c3590 vsub.f32 s13, s17, s13
 *   @0x2c3594 vmov.f32 s7, s14
 *   @0x2c3598 vmla.f32 s14, s13, s12
 *   @0x2c359c vmls.f32 s7, s16, s12
 *   @0x2c35a0 vmov.f32 s12, s15
 *   @0x2c35a4 vmls.f32 s15, s16, s11
 *   @0x2c35a8 vmla.f32 s12, s13, s11
 *   @0x2c35ac vadd.f32 s14, s14, s7
 *   @0x2c35b0 vadd.f32 s15, s12, s15
 *   @0x2c35b4 vmul.f32 s14, s14, s10
 *   @0x2c35b8 vmul.f32 s15, s15, s10
 *   @0x2c35bc vstr s14, [r3, #-8]
 *   @0x2c35c0 vstr s15, [r3, #-4]
 *   @0x2c35c4 vldr s12, [r4]
 *   @0x2c35c8 vldr s11, [r4, #4]
 *   @0x2c35cc bne 0x2c3550 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x288>
 *   @0x2c35d0 vpop {d8, d9, d10}
 *   @0x2c35d4 vneg.f32 s12, s12
 *   @0x2c35d8 vneg.f32 s11, s11
 *   @0x2c35dc vstr s12, [r4]
 *   @0x2c35e0 vstr s11, [r4, #4]
 *   @0x2c35e4 pop {r4, pc}
 *   @0x2c35e8 vsub.f32 s14, s18, s19
 *   @0x2c35ec vmul.f32 s15, s14, s14
 *   @0x2c35f0 vstr s14, [r4, #4]
 *   @0x2c35f4 vsub.f32 s14, s20, s21
 *   @0x2c35f8 vmla.f32 s15, s14, s14
 *   @0x2c35fc vstr s14, [r4]
 *   @0x2c3600 vsqrt.f32 s13, s15
 *   @0x2c3604 vcmp.f32 s13, s13
 *   @0x2c3608 vmrs APSR_nzcv, fpscr
 *   @0x2c360c bne 0x2c3648 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x380>
 *   @0x2c3610 vldr s15, [pc, #72]
 *   @0x2c3614 vcmpe.f32 s13, s15
 *   @0x2c3618 vmrs APSR_nzcv, fpscr
 *   @0x2c361c vmovpl.f32 s12, #1.000000e+00
 *   @0x2c3620 vldrpl s14, [r4]
 *   @0x2c3624 vldrpl s15, [r4, #4]
 *   @0x2c3628 vldrmi s14, [r4]
 *   @0x2c362c vldrmi s15, [r4, #4]
 *   @0x2c3630 vdivpl.f32 s13, s12, s13
 *   @0x2c3634 vmulpl.f32 s14, s13, s14
 *   @0x2c3638 vmulpl.f32 s15, s13, s15
 *   @0x2c363c vstrpl s14, [r4]
 *   @0x2c3640 vstrpl s15, [r4, #4]
 *   @0x2c3644 b 0x2c34a8 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x1e0>
 *   @0x2c3648 vmov r0, s15
 *   @0x2c364c bl 0xb6700 <sqrtf@plt>
 *   @0x2c3650 vmov s13, r0
 *   @0x2c3654 b 0x2c3610 <_ZN15b2WorldManifold10InitializeEPK10b2ManifoldRK11b2TransformfS5_f+0x348>
 *   @0x2c3658 andeq r0, r0, r0
 *   @0x2c365c .word 0x28800000
 *   @0x2c3660 strlo r0, [r0], #-0
 *
 * ══ §24/31 CCamera::CameraUpdate  0x170b30  size 920  230 条（0x170b30..0x170ec8）
 * @func 0x170b30 0x170ec8  size 920  230 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb6910×2 / CCamera::CameraUpdate()+0x228×2 / CCamera::CameraUpdate()+0x274×2 / CCamera::IsOrthoProj()×2 / CCamera::CameraUpdate()+0x320 / CCamera::CameraUpdate()+0x180 / CCamera::IsViewDirty() / CInstance::Compute_BoundingBox(bool)
 * 字段偏移 top8: 0x4×4 / 0x8×4 / 0x3×2 / 0xc×2 / 0x68×2 / 0x69×2 / 0x1b4×1 / 0x1a8×1
 * VFP 指令 113 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x170b30 ldr r1, [r0, #0x1b4]
 *   @0x170b34 push {r3, r4, r5, lr}
 *   @0x170b38 vpush {d8, d9, d10, d11}
 *   @0x170b3c cmn r1, #1
 *   @0x170b40 mov r5, r0
 *   @0x170b44 bne 0x170ddc <_ZN7CCamera12CameraUpdateEv+0x2ac>
 *   @0x170b48 ldr r2, [r0, #0x1a8]
 *   @0x170b4c cmp r2, #0
 *   @0x170b50 blt 0x170e50 <_ZN7CCamera12CameraUpdateEv+0x320>
 *   @0x170b54 movw r3, #0x869f
 *   @0x170b58 movt r3, #0x1
 *   @0x170b5c cmp r2, r3
 *   @0x170b60 bgt 0x170de8 <_ZN7CCamera12CameraUpdateEv+0x2b8>
 *   @0x170b64 ldr r3, [pc, #0x350]
 *   @0x170b68 ldr r3, [pc, r3]
 *   @0x170b6c ldr r3, [r3]
 *   @0x170b70 ldr r1, [r3, #0x4]
 *   @0x170b74 ldr r3, [r3]
 *   @0x170b78 and r1, r2, r1
 *   @0x170b7c ldr r3, [r3, r1, lsl #3]
 *   @0x170b80 cmp r3, #0
 *   @0x170b84 bne 0x170b98 <_ZN7CCamera12CameraUpdateEv+0x68>
 *   @0x170b88 b 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170b8c ldr r3, [r3, #0x4]
 *   @0x170b90 cmp r3, #0
 *   @0x170b94 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170b98 ldr r1, [r3, #0x8]
 *   @0x170b9c cmp r2, r1
 *   @0x170ba0 bne 0x170b8c <_ZN7CCamera12CameraUpdateEv+0x5c>
 *   @0x170ba4 ldr r3, [r3, #0xc]
 *   @0x170ba8 cmp r3, #0
 *   @0x170bac ldrne r3, [r3, #0xd0]
 *   @0x170bb0 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170bb4 cmp r3, #0
 *   @0x170bb8 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170bbc ldr r2, [r3, #0x8]
 *   @0x170bc0 cmp r2, #0
 *   @0x170bc4 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170bc8 ldr r4, [r3, #0x8]
 *   @0x170bcc ldr r3, [r3]
 *   @0x170bd0 ldrb r2, [r4, #0x68]
 *   @0x170bd4 cmp r2, #0
 *   @0x170bd8 bne 0x170bb4 <_ZN7CCamera12CameraUpdateEv+0x84>
 *   @0x170bdc ldrb r2, [r4, #0x69]
 *   @0x170be0 cmp r2, #0
 *   @0x170be4 bne 0x170bb4 <_ZN7CCamera12CameraUpdateEv+0x84>
 *   @0x170be8 vmov.f32 s15, #5.000000e-01
 *   @0x170bec ldrb r3, [r4, #0x64]
 *   @0x170bf0 vldr s19, [r5, #396]
 *   @0x170bf4 vldr s18, [r5, #400]
 *   @0x170bf8 cmp r3, #0
 *   @0x170bfc vldr s16, [r5, #388]
 *   @0x170c00 vldr s23, [r5, #392]
 *   @0x170c04 vmul.f32 s21, s19, s15
 *   @0x170c08 vmul.f32 s20, s18, s15
 *   @0x170c0c bne 0x170ea0 <_ZN7CCamera12CameraUpdateEv+0x370>
 *   @0x170c10 ldr r0, [r4, #0xb4]
 *   @0x170c14 bl 0xb6910 <floorf@plt>
 *   @0x170c18 vmov s22, r0
 *   @0x170c1c ldr r0, [r4, #0xb8]
 *   @0x170c20 bl 0xb6910 <floorf@plt>
 *   @0x170c24 vldr s14, [r5, #412]
 *   @0x170c28 vadd.f32 s15, s14, s14
 *   @0x170c2c vcmpe.f32 s15, s19
 *   @0x170c30 vmrs APSR_nzcv, fpscr
 *   @0x170c34 vsubge.f32 s17, s22, s21
 *   @0x170c38 vmov s13, r0
 *   @0x170c3c bge 0x170c6c <_ZN7CCamera12CameraUpdateEv+0x13c>
 *   @0x170c40 vsub.f32 s17, s22, s14
 *   @0x170c44 vldr s15, [r5, #388]
 *   @0x170c48 vcmpe.f32 s17, s15
 *   @0x170c4c vmrs APSR_nzcv, fpscr
 *   @0x170c50 bmi 0x170c6c <_ZN7CCamera12CameraUpdateEv+0x13c>
 *   @0x170c54 vadd.f32 s14, s22, s14
 *   @0x170c58 vadd.f32 s15, s15, s19
 *   @0x170c5c vcmpe.f32 s14, s15
 *   @0x170c60 vmrs APSR_nzcv, fpscr
 *   @0x170c64 vsubgt.f32 s17, s14, s19
 *   @0x170c68 vmovle.f32 s17, s16
 *   @0x170c6c vldr s15, [r5, #416]
 *   @0x170c70 vadd.f32 s14, s15, s15
 *   @0x170c74 vcmpe.f32 s18, s14
 *   @0x170c78 vmrs APSR_nzcv, fpscr
 *   @0x170c7c vsubls.f32 s16, s13, s20
 *   @0x170c80 bls 0x170cb0 <_ZN7CCamera12CameraUpdateEv+0x180>
 *   @0x170c84 vldr s14, [r5, #392]
 *   @0x170c88 vsub.f32 s16, s13, s15
 *   @0x170c8c vcmpe.f32 s16, s14
 *   @0x170c90 vmrs APSR_nzcv, fpscr
 *   @0x170c94 bmi 0x170cb0 <_ZN7CCamera12CameraUpdateEv+0x180>
 *   @0x170c98 vadd.f32 s15, s13, s15
 *   @0x170c9c vadd.f32 s14, s18, s14
 *   @0x170ca0 vcmpe.f32 s15, s14
 *   @0x170ca4 vmrs APSR_nzcv, fpscr
 *   @0x170ca8 vsubgt.f32 s16, s15, s18
 *   @0x170cac vmovle.f32 s16, s23
 *   @0x170cb0 vldr s15, [pc, #512]
 *   @0x170cb4 ldr r3, [pc, #0x204]
 *   @0x170cb8 vcmp.f32 s17, #0
 *   @0x170cbc ldr r3, [pc, r3]
 *   @0x170cc0 ldr r3, [r3]
 *   @0x170cc4 vldr s13, [r3, #16]
 *   @0x170cc8 vmrs APSR_nzcv, fpscr
 *   @0x170ccc vmovmi.f32 s17, s15
 *   @0x170cd0 vadd.f32 s15, s17, s19
 *   @0x170cd4 vcvt.f32.s32 s14, s13
 *   @0x170cd8 vcmpe.f32 s15, s14
 *   @0x170cdc vldr s15, [pc, #468]
 *   @0x170ce0 vmrs APSR_nzcv, fpscr
 *   @0x170ce4 vcmp.f32 s16, s15
 *   @0x170ce8 vsubgt.f32 s17, s14, s19
 *   @0x170cec vmrs APSR_nzcv, fpscr
 *   @0x170cf0 vldr s14, [r3, #20]
 *   @0x170cf4 vmovmi.f32 s16, s15
 *   @0x170cf8 vadd.f32 s15, s16, s18
 *   @0x170cfc vcvt.f32.s32 s14, s14
 *   @0x170d00 vcmpe.f32 s15, s14
 *   @0x170d04 vmrs APSR_nzcv, fpscr
 *   @0x170d08 vsubgt.f32 s16, s14, s18
 *   @0x170d0c vldr s14, [r5, #404]
 *   @0x170d10 vcmpe.f32 s14, #0
 *   @0x170d14 vmrs APSR_nzcv, fpscr
 *   @0x170d18 blt 0x170d58 <_ZN7CCamera12CameraUpdateEv+0x228>
 *   @0x170d1c vldr s15, [r5, #388]
 *   @0x170d20 vcmpe.f32 s17, s15
 *   @0x170d24 vmrs APSR_nzcv, fpscr
 *   @0x170d28 bpl 0x170d3c <_ZN7CCamera12CameraUpdateEv+0x20c>
 *   @0x170d2c vsub.f32 s13, s15, s17
 *   @0x170d30 vcmpe.f32 s14, s13
 *   @0x170d34 vmrs APSR_nzcv, fpscr
 *   @0x170d38 vsubmi.f32 s17, s15, s14
 *   @0x170d3c vcmpe.f32 s17, s15
 *   @0x170d40 vmrs APSR_nzcv, fpscr
 *   @0x170d44 ble 0x170d58 <_ZN7CCamera12CameraUpdateEv+0x228>
 *   @0x170d48 vsub.f32 s13, s17, s15
 *   @0x170d4c vcmpe.f32 s14, s13
 *   @0x170d50 vmrs APSR_nzcv, fpscr
 *   @0x170d54 vaddmi.f32 s17, s14, s15
 *   @0x170d58 vldr s14, [r5, #408]
 *   @0x170d5c vcmpe.f32 s14, #0
 *   @0x170d60 vmrs APSR_nzcv, fpscr
 *   @0x170d64 blt 0x170da4 <_ZN7CCamera12CameraUpdateEv+0x274>
 *   @0x170d68 vldr s15, [r5, #392]
 *   @0x170d6c vcmpe.f32 s16, s15
 *   @0x170d70 vmrs APSR_nzcv, fpscr
 *   @0x170d74 bpl 0x170d88 <_ZN7CCamera12CameraUpdateEv+0x258>
 *   @0x170d78 vsub.f32 s13, s15, s16
 *   @0x170d7c vcmpe.f32 s14, s13
 *   @0x170d80 vmrs APSR_nzcv, fpscr
 *   @0x170d84 vsubmi.f32 s16, s15, s14
 *   @0x170d88 vcmpe.f32 s16, s15
 *   @0x170d8c vmrs APSR_nzcv, fpscr
 *   @0x170d90 ble 0x170da4 <_ZN7CCamera12CameraUpdateEv+0x274>
 *   @0x170d94 vsub.f32 s13, s16, s15
 *   @0x170d98 vcmpe.f32 s14, s13
 *   @0x170d9c vmrs APSR_nzcv, fpscr
 *   @0x170da0 vaddmi.f32 s16, s14, s15
 *   @0x170da4 vstr s17, [r5, #388]
 *   @0x170da8 vstr s16, [r5, #392]
 *   @0x170dac mov r0, r5
 *   @0x170db0 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv>
 *   @0x170db4 vadd.f32 s21, s17, s21
 *   @0x170db8 vadd.f32 s20, s16, s20
 *   @0x170dbc vmov r1, s21
 *   @0x170dc0 vmov r2, s20
 *   @0x170dc4 cmp r0, #0
 *   @0x170dc8 mov r0, r5
 *   @0x170dcc beq 0x170e94 <_ZN7CCamera12CameraUpdateEv+0x364>
 *   @0x170dd0 vpop {d8, d9, d10, d11}
 *   @0x170dd4 pop {r3, r4, r5, lr}
 *   @0x170dd8 b 0x16db44 <_ZN7CCamera11Build2DViewEff>
 *   @0x170ddc vpop {d8, d9, d10, d11}
 *   @0x170de0 pop {r3, r4, r5, lr}
 *   @0x170de4 b 0x170888 <_ZN7CCamera13ExecuteScriptEi>
 *   @0x170de8 ldr r3, [pc, #0xd4]
 *   @0x170dec ldr r3, [pc, r3]
 *   @0x170df0 ldr r1, [r3, #0x4]
 *   @0x170df4 ldr r3, [r3]
 *   @0x170df8 and r1, r2, r1
 *   @0x170dfc ldr r3, [r3, r1, lsl #3]
 *   @0x170e00 cmp r3, #0
 *   @0x170e04 bne 0x170e18 <_ZN7CCamera12CameraUpdateEv+0x2e8>
 *   @0x170e08 b 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170e0c ldr r3, [r3, #0x4]
 *   @0x170e10 cmp r3, #0
 *   @0x170e14 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170e18 ldr r1, [r3, #0x8]
 *   @0x170e1c cmp r2, r1
 *   @0x170e20 bne 0x170e0c <_ZN7CCamera12CameraUpdateEv+0x2dc>
 *   @0x170e24 ldr r4, [r3, #0xc]
 *   @0x170e28 cmp r4, #0
 *   @0x170e2c beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170e30 ldrb r3, [r4, #0x68]
 *   @0x170e34 cmp r3, #0
 *   @0x170e38 bne 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170e3c ldrb r3, [r4, #0x69]
 *   @0x170e40 cmp r3, #0
 *   @0x170e44 beq 0x170be8 <_ZN7CCamera12CameraUpdateEv+0xb8>
 *   @0x170e48 vpop {d8, d9, d10, d11}
 *   @0x170e4c pop {r3, r4, r5, pc}
 *   @0x170e50 bl 0x16d378 <_ZN7CCamera11IsViewDirtyEv>
 *   @0x170e54 cmp r0, #0
 *   @0x170e58 beq 0x170e48 <_ZN7CCamera12CameraUpdateEv+0x318>
 *   @0x170e5c mov r0, r5
 *   @0x170e60 bl 0x16d380 <_ZN7CCamera11IsOrthoProjEv>
 *   @0x170e64 vmov.f32 s15, #5.000000e-01
 *   @0x170e68 vldr s11, [r5, #396]
 *   @0x170e6c vldr s12, [r5, #388]
 *   @0x170e70 vldr s13, [r5, #400]
 *   @0x170e74 vldr s14, [r5, #392]
 *   @0x170e78 vmla.f32 s12, s11, s15
 *   @0x170e7c vmla.f32 s14, s13, s15
 *   @0x170e80 cmp r0, #0
 *   @0x170e84 vmov r1, s12
 *   @0x170e88 mov r0, r5
 *   @0x170e8c vmov r2, s14
 *   @0x170e90 bne 0x170dd0 <_ZN7CCamera12CameraUpdateEv+0x2a0>
 *   @0x170e94 vpop {d8, d9, d10, d11}
 *   @0x170e98 pop {r3, r4, r5, lr}
 *   @0x170e9c b 0x16dc0c <_ZN7CCamera11Build3DViewEff>
 *   @0x170ea0 mov r0, r4
 *   @0x170ea4 mov r1, #1
 *   @0x170ea8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb>
 *   @0x170eac vldr s19, [r5, #396]
 *   @0x170eb0 vldr s18, [r5, #400]
 *   @0x170eb4 b 0x170c10 <_ZN7CCamera12CameraUpdateEv+0xe0>
 *   @0x170eb8 andeq r0, r0, r0
 *   @0x170ebc .word 0x0027d0d4
 *   @0x170ec0 eoreq r12, r7, r12, ror #24
 *   @0x170ec4 eoreq r12, r7, r8, asr lr
 *
 * ══ §25/31 yySocket::ProcessGMSHandshake  0x296320  size 908  227 条（0x296320..0x2966ac）
 * @func 0x296320 0x2966ac  size 908  227 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x296388→0x3eb70c, 0x2963cc→0x3f7810, 0x296408→0x3eb70c, 0x2964d4→0x3f7810, 0x296510→0x3eb70c
 * 调用序列: Timing_Time×5 / yySocket::Peek()×2 / yySocket::Read(void*, unsigned int, unsigned int)×2 / yySocket::Close()×2 / yySocket::ProcessGMSHandshake()+0x40 / yySocket::ProcessGMSHandshake()+0x28c / 0xb6574 / yySocket::Write(void*, unsigned int)
 * 字段偏移 top8: 0xc×8 / 0x34×3 / 0x3c×2 / 0x34c×1 / 0x348×1 / 0x2f4×1 / 0x2e8×1 / 0x2b8×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x296320 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x296324 sub sp, sp, #64
 *   @0x296328 ldr r6, [pc, #0x34c]
 *   @0x29632c mov r8, r0
 *   @0x296330 ldr r3, [pc, #0x348]
 *   @0x296334 add r6, pc, r6
 *   @0x296338 ldr r9, [r0, #0x34]
 *   @0x29633c ldr r7, [r6, r3]
 *   @0x296340 cmp r9, #1
 *   @0x296344 ldr r3, [r7]
 *   @0x296348 str r3, [sp, #0x3c]
 *   @0x29634c beq 0x2964d0 <_ZN8yySocket19ProcessGMSHandshakeEv+0x1b0>
 *   @0x296350 cmp r9, #3
 *   @0x296354 beq 0x2963c8 <_ZN8yySocket19ProcessGMSHandshakeEv+0xa8>
 *   @0x296358 cmp r9, #0
 *   @0x29635c beq 0x296380 <_ZN8yySocket19ProcessGMSHandshakeEv+0x60>
 *   @0x296360 mov r9, #1
 *   @0x296364 ldr r2, [sp, #0x3c]
 *   @0x296368 mov r0, r9
 *   @0x29636c ldr r3, [r7]
 *   @0x296370 cmp r2, r3
 *   @0x296374 bne 0x296678 <_ZN8yySocket19ProcessGMSHandshakeEv+0x358>
 *   @0x296378 add sp, sp, #64
 *   @0x29637c pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x296380 bl 0x215148 <Timing_Time>
 *   @0x296384 mov r4, r0
 *   @0x296388 ldr r0, [pc, #0x2f4]
 *   @0x29638c mov r5, r1
 *   @0x296390 strd r4, r5, [r8, #56]
 *   @0x296394 mov r3, r1
 *   @0x296398 ldr r1, [pc, #0x2e8]
 *   @0x29639c ldr r0, [r6, r0]
 *   @0x2963a0 mov r2, r4
 *   @0x2963a4 add r1, pc, r1
 *   @0x2963a8 ldr r0, [r0]
 *   @0x2963ac ldr r12, [r0]
 *   @0x2963b0 ldr r12, [r12, #0xc]
 *   @0x2963b4 blx r12
 *   @0x2963b8 mov r3, #1
 *   @0x2963bc mov r9, r3
 *   @0x2963c0 str r3, [r8, #0x34]
 *   @0x2963c4 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x2963c8 bl 0x215148 <Timing_Time>
 *   @0x2963cc ldr r12, [pc, #0x2b8]
 *   @0x2963d0 mov r4, #1000
 *   @0x2963d4 ldrd r2, r3, [r8, #56]
 *   @0x2963d8 ldr r12, [r6, r12]
 *   @0x2963dc ldr r12, [r12]
 *   @0x2963e0 mul r4, r4, r12
 *   @0x2963e4 asr r5, r4, #31
 *   @0x2963e8 subs r2, r0, r2
 *   @0x2963ec sbc r3, r1, r3
 *   @0x2963f0 mov r0, r8
 *   @0x2963f4 cmp r4, r2
 *   @0x2963f8 sbcs r1, r5, r3
 *   @0x2963fc movge r9, #0
 *   @0x296400 movlt r9, #1
 *   @0x296404 bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x296408 ldr r3, [pc, #0x274]
 *   @0x29640c ldr r1, [pc, #0x27c]
 *   @0x296410 ldr r3, [r6, r3]
 *   @0x296414 add r1, pc, r1
 *   @0x296418 ldr r5, [r3]
 *   @0x29641c ldr r3, [r5]
 *   @0x296420 ldr r3, [r3, #0xc]
 *   @0x296424 mov r4, r0
 *   @0x296428 mov r2, r0
 *   @0x29642c mov r0, r5
 *   @0x296430 blx r3
 *   @0x296434 cmp r4, #0
 *   @0x296438 movne r3, #0
 *   @0x29643c andeq r3, r9, #1
 *   @0x296440 cmp r3, #0
 *   @0x296444 bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x296448 cmp r9, #0
 *   @0x29644c bne 0x296458 <_ZN8yySocket19ProcessGMSHandshakeEv+0x138>
 *   @0x296450 cmp r4, #12
 *   @0x296454 blo 0x296360 <_ZN8yySocket19ProcessGMSHandshakeEv+0x40>
 *   @0x296458 cmp r4, #12
 *   @0x29645c bne 0x296360 <_ZN8yySocket19ProcessGMSHandshakeEv+0x40>
 *   @0x296460 mov r2, r4
 *   @0x296464 mov r0, r8
 *   @0x296468 add r1, sp, #28
 *   @0x29646c mov r3, #0
 *   @0x296470 bl 0x2952dc <_ZN8yySocket4ReadEPvjj>
 *   @0x296474 cmp r0, #11
 *   @0x296478 bls 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x29647c ldr r2, [sp, #0x1c]
 *   @0x296480 movw r3, #0xbead
 *   @0x296484 movt r3, #0xdeaf
 *   @0x296488 cmp r2, r3
 *   @0x29648c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x296490 ldr r2, [sp, #0x20]
 *   @0x296494 movw r3, #0xbeeb
 *   @0x296498 movt r3, #0xf00d
 *   @0x29649c cmp r2, r3
 *   @0x2964a0 bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x2964a4 ldr r3, [sp, #0x24]
 *   @0x2964a8 cmp r3, #12
 *   @0x2964ac bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x2964b0 ldr r3, [r5]
 *   @0x2964b4 mov r0, r5
 *   @0x2964b8 ldr r1, [pc, #0x1d4]
 *   @0x2964bc mov r9, #2
 *   @0x2964c0 add r1, pc, r1
 *   @0x2964c4 ldr r3, [r3, #0xc]
 *   @0x2964c8 blx r3
 *   @0x2964cc b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x2964d0 bl 0x215148 <Timing_Time>
 *   @0x2964d4 ldr r12, [pc, #0x1b0]
 *   @0x2964d8 mov r4, #1000
 *   @0x2964dc ldrd r2, r3, [r8, #56]
 *   @0x2964e0 ldr r12, [r6, r12]
 *   @0x2964e4 ldr r12, [r12]
 *   @0x2964e8 mul r4, r4, r12
 *   @0x2964ec asr r5, r4, #31
 *   @0x2964f0 subs r2, r0, r2
 *   @0x2964f4 sbc r3, r1, r3
 *   @0x2964f8 mov r0, r8
 *   @0x2964fc cmp r4, r2
 *   @0x296500 sbcs r1, r5, r3
 *   @0x296504 movge r5, #0
 *   @0x296508 movlt r5, #1
 *   @0x29650c bl 0x295438 <_ZN8yySocket4PeekEv>
 *   @0x296510 ldr r3, [pc, #0x16c]
 *   @0x296514 ldr r1, [pc, #0x17c]
 *   @0x296518 ldr r3, [r6, r3]
 *   @0x29651c add r1, pc, r1
 *   @0x296520 ldr r6, [r3]
 *   @0x296524 ldr r3, [r6]
 *   @0x296528 ldr r3, [r3, #0xc]
 *   @0x29652c mov r4, r0
 *   @0x296530 mov r2, r0
 *   @0x296534 mov r0, r6
 *   @0x296538 blx r3
 *   @0x29653c cmp r4, #0
 *   @0x296540 movne r3, #0
 *   @0x296544 andeq r3, r5, #1
 *   @0x296548 cmp r3, #0
 *   @0x29654c bne 0x2965bc <_ZN8yySocket19ProcessGMSHandshakeEv+0x29c>
 *   @0x296550 eor r5, r5, #1
 *   @0x296554 cmp r4, #17
 *   @0x296558 movgt r3, #0
 *   @0x29655c andle r3, r5, #1
 *   @0x296560 cmp r3, #0
 *   @0x296564 bne 0x296654 <_ZN8yySocket19ProcessGMSHandshakeEv+0x334>
 *   @0x296568 cmp r4, #18
 *   @0x29656c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x296570 add r5, sp, #28
 *   @0x296574 mov r2, r4
 *   @0x296578 mov r0, r8
 *   @0x29657c mov r1, r5
 *   @0x296580 bl 0x2952dc <_ZN8yySocket4ReadEPvjj>
 *   @0x296584 ldr r3, [r6]
 *   @0x296588 ldr r1, [pc, #0x10c]
 *   @0x29658c ldr r3, [r3, #0xc]
 *   @0x296590 add r1, pc, r1
 *   @0x296594 mov r4, r0
 *   @0x296598 mov r2, r0
 *   @0x29659c mov r0, r6
 *   @0x2965a0 blx r3
 *   @0x2965a4 cmp r4, #17
 *   @0x2965a8 bgt 0x2965f8 <_ZN8yySocket19ProcessGMSHandshakeEv+0x2d8>
 *   @0x2965ac mov r0, r8
 *   @0x2965b0 mov r9, #0
 *   @0x2965b4 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x2965b8 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x2965bc ldr r3, [r6]
 *   @0x2965c0 mov r9, #0
 *   @0x2965c4 ldrd r4, r5, [r8, #56]
 *   @0x2965c8 ldr r10, [r3, #0xc]
 *   @0x2965cc bl 0x215148 <Timing_Time>
 *   @0x2965d0 mov r2, r4
 *   @0x2965d4 mov r3, r5
 *   @0x2965d8 strd r0, r1, [sp]
 *   @0x2965dc mov r0, r6
 *   @0x2965e0 ldr r1, [pc, #0xb8]
 *   @0x2965e4 add r1, pc, r1
 *   @0x2965e8 blx r10
 *   @0x2965ec mov r0, r8
 *   @0x2965f0 bl 0x295474 <_ZN8yySocket5CloseEv>
 *   @0x2965f4 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x2965f8 ldr r0, [pc, #0xa4]
 *   @0x2965fc mov r1, r5
 *   @0x296600 add r0, pc, r0
 *   @0x296604 bl 0xb6574 <strcmp@plt>
 *   @0x296608 cmp r0, #0
 *   @0x29660c bne 0x2965ac <_ZN8yySocket19ProcessGMSHandshakeEv+0x28c>
 *   @0x296610 mov r3, #16
 *   @0x296614 add r1, sp, #12
 *   @0x296618 mov r2, r3
 *   @0x29661c mov r0, r8
 *   @0x296620 str r3, [sp, #0x14]
 *   @0x296624 movw lr, #0xbabe
 *   @0x296628 movw r12, #0xb00b
 *   @0x29662c movt lr, #0xcafe
 *   @0x296630 movt r12, #0xdead
 *   @0x296634 str lr, [sp, #0xc]
 *   @0x296638 str r12, [sp, #0x10]
 *   @0x29663c bl 0x295464 <_ZN8yySocket5WriteEPvj>
 *   @0x296640 bl 0x215148 <Timing_Time>
 *   @0x296644 mov r3, #3
 *   @0x296648 str r3, [r8, #0x34]
 *   @0x29664c strd r0, r1, [r8, #56]
 *   @0x296650 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x296654 ldr r12, [r6]
 *   @0x296658 mov r2, r4
 *   @0x29665c ldr r1, [pc, #0x44]
 *   @0x296660 mov r0, r6
 *   @0x296664 mov r3, #18
 *   @0x296668 add r1, pc, r1
 *   @0x29666c ldr r12, [r12, #0xc]
 *   @0x296670 blx r12
 *   @0x296674 b 0x296364 <_ZN8yySocket19ProcessGMSHandshakeEv+0x44>
 *   @0x296678 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x29667c andseq r11, r5, r12, lsl r9
 *   @0x296680 .word 0xffffbd00
 *   @0x296684 .word 0xffffbac4
 *   @0x296688 andeq r3, r12, r4, ror r0
 *   @0x29668c .word 0xfffffd3c
 *   @0x296690 andeq r3, r12, r12, lsr #1
 *   @0x296694 andeq r3, r12, r12, lsl r0
 *   @0x296698 andeq r2, r12, r4, lsl pc
 *   @0x29669c andeq r2, r12, r0, lsl #30
 *   @0x2966a0 andeq r2, r12, r8, ror #28
 *   @0x2966a4 andeq r2, r12, r12, lsr #29
 *   @0x2966a8 andeq r2, r12, r12, lsl #28
 *
 * ══ §26/31 Script_Perform  0x1e0774  size 892  223 条（0x1e0774..0x1e0af0）
 * @func 0x1e0774 0x1e0af0  size 892  223 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1e0794→0x47b234, 0x1e07a0→0x47a170, 0x1e07dc→0x544c68, 0x1e07f0→0x544c70, 0x1e0980→0x47f3c0
 * 调用序列: operator delete(void*)×3 / LOCK_RVALUE_MUTEX()×2 / UNLOCK_RVALUE_MUTEX()×2 / YYFree(void const*)×2 / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*)+0xd4 / CScript::GetCode() / Code_Execute_Special(CInstance*, CInstance*, CCode*, RValue*, int) / Script_Perform(int, CInstance*, CInstance*, int, RValue*, DynamicArrayOfRValue*)+0x1d0
 * 字段偏移 top8: 0x4×9 / 0x-434×4 / 0x-44c×4 / 0x8×4 / 0xc×3 / 0x-430×2 / 0x-28×2 / 0x-438×2
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1e0774 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x1e0778 add r11, sp, #32
 *   @0x1e077c ldr r4, [pc, #0x34c]
 *   @0x1e0780 sub sp, sp, #1072
 *   @0x1e0784 sub sp, sp, #4
 *   @0x1e0788 ldr r12, [pc, #0x344]
 *   @0x1e078c add r4, pc, r4
 *   @0x1e0790 subs r7, r0, #0
 *   @0x1e0794 ldr r0, [pc, #0x33c]
 *   @0x1e0798 ldr r12, [r4, r12]
 *   @0x1e079c mov r8, r1
 *   @0x1e07a0 ldr r1, [pc, #0x334]
 *   @0x1e07a4 mov r6, r3
 *   @0x1e07a8 ldmib r11, {r3, r9}
 *   @0x1e07ac str r12, [r11, #-0x430]
 *   @0x1e07b0 ldr r12, [r12]
 *   @0x1e07b4 str r12, [r11, #-0x28]
 *   @0x1e07b8 ldr r0, [r4, r0]
 *   @0x1e07bc ldr r5, [r4, r1]
 *   @0x1e07c0 str r0, [r11, #-0x434]
 *   @0x1e07c4 ldr r1, [r11, #-0x434]
 *   @0x1e07c8 ldr r0, [r5]
 *   @0x1e07cc ldr r1, [r1]
 *   @0x1e07d0 str r0, [r11, #-0x438]
 *   @0x1e07d4 str r1, [r11, #-0x43c]
 *   @0x1e07d8 blt 0x1e0848 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd4>
 *   @0x1e07dc ldr r1, [pc, #0x2fc]
 *   @0x1e07e0 ldr r1, [r4, r1]
 *   @0x1e07e4 ldr r1, [r1]
 *   @0x1e07e8 cmp r7, r1
 *   @0x1e07ec bge 0x1e0848 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd4>
 *   @0x1e07f0 ldr r1, [pc, #0x2ec]
 *   @0x1e07f4 ldr r1, [r4, r1]
 *   @0x1e07f8 ldr r1, [r1, #0x4]
 *   @0x1e07fc ldr r1, [r1, r7, lsl #2]
 *   @0x1e0800 cmp r1, #0
 *   @0x1e0804 moveq r9, r1
 *   @0x1e0808 beq 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8>
 *   @0x1e080c mov r0, r1
 *   @0x1e0810 str r1, [r11, #-0x44c]
 *   @0x1e0814 str r2, [r11, #-0x444]
 *   @0x1e0818 str r3, [r11, #-0x448]
 *   @0x1e081c bl 0x1dfba8 <_ZN7CScript7GetCodeEv>
 *   @0x1e0820 ldr r1, [r11, #-0x44c]
 *   @0x1e0824 ldr r2, [r11, #-0x444]
 *   @0x1e0828 ldr r3, [r11, #-0x448]
 *   @0x1e082c subs r12, r0, #0
 *   @0x1e0830 beq 0x1e0884 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x110>
 *   @0x1e0834 ldr r0, [r12, #0x64]
 *   @0x1e0838 cmp r0, #0
 *   @0x1e083c beq 0x1e086c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xf8>
 *   @0x1e0840 mov r9, #1
 *   @0x1e0844 b 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8>
 *   @0x1e0848 mov r9, #0
 *   @0x1e084c ldr r5, [r11, #-0x430]
 *   @0x1e0850 mov r0, r9
 *   @0x1e0854 ldr r2, [r11, #-0x28]
 *   @0x1e0858 ldr r3, [r5]
 *   @0x1e085c cmp r2, r3
 *   @0x1e0860 bne 0x1e0acc <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x358>
 *   @0x1e0864 sub sp, r11, #32
 *   @0x1e0868 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x1e086c ldr r0, [r12, #0x50]
 *   @0x1e0870 cmp r0, #0
 *   @0x1e0874 beq 0x1e0884 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x110>
 *   @0x1e0878 ldr r0, [r0, #0x4]
 *   @0x1e087c cmp r0, #0
 *   @0x1e0880 beq 0x1e0840 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xcc>
 *   @0x1e0884 cmp r9, #0
 *   @0x1e0888 beq 0x1e0a64 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2f0>
 *   @0x1e088c ldr r0, [r9, #0x4]
 *   @0x1e0890 str r0, [r5]
 *   @0x1e0894 ldr r0, [r11, #-0x434]
 *   @0x1e0898 cmp r12, #0
 *   @0x1e089c str r6, [r0]
 *   @0x1e08a0 beq 0x1e0a6c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2f8>
 *   @0x1e08a4 mov r1, r2
 *   @0x1e08a8 mov r2, r12
 *   @0x1e08ac adds r12, r8, #0
 *   @0x1e08b0 mov r0, r8
 *   @0x1e08b4 movne r12, #1
 *   @0x1e08b8 str r12, [sp]
 *   @0x1e08bc bl 0xd05d4 <_Z20Code_Execute_SpecialP9CInstanceS0_P5CCodeP6RValuei>
 *   @0x1e08c0 subs r9, r0, #0
 *   @0x1e08c4 beq 0x1e095c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1e8>
 *   @0x1e08c8 cmp r6, #0
 *   @0x1e08cc ble 0x1e0944 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1d0>
 *   @0x1e08d0 mov r7, #0
 *   @0x1e08d4 str r9, [r11, #-0x440]
 *   @0x1e08d8 mov r1, #5
 *   @0x1e08dc mov r9, r5
 *   @0x1e08e0 mov r10, r7
 *   @0x1e08e4 mov r5, r6
 *   @0x1e08e8 b 0x1e0904 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x190>
 *   @0x1e08ec add r7, r7, #1
 *   @0x1e08f0 str r10, [r4, #0x8]
 *   @0x1e08f4 cmp r7, r5
 *   @0x1e08f8 str r1, [r4, #0xc]
 *   @0x1e08fc str r10, [r6, r8]
 *   @0x1e0900 beq 0x1e093c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x1c8>
 *   @0x1e0904 ldr r6, [r9]
 *   @0x1e0908 lsl r8, r7, #4
 *   @0x1e090c add r4, r6, r8
 *   @0x1e0910 ldr r3, [r4, #0xc]
 *   @0x1e0914 sub r3, r3, #1
 *   @0x1e0918 bic r3, r3, #-16777216
 *   @0x1e091c bic r3, r3, #3
 *   @0x1e0920 cmp r3, #0
 *   @0x1e0924 bne 0x1e08ec <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x178>
 *   @0x1e0928 mov r0, r4
 *   @0x1e092c str r1, [r11, #-0x44c]
 *   @0x1e0930 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1e0934 ldr r1, [r11, #-0x44c]
 *   @0x1e0938 b 0x1e08ec <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x178>
 *   @0x1e093c mov r5, r9
 *   @0x1e0940 ldr r9, [r11, #-0x440]
 *   @0x1e0944 ldr r1, [r11, #-0x438]
 *   @0x1e0948 ldr r0, [r11, #-0x434]
 *   @0x1e094c str r1, [r5]
 *   @0x1e0950 ldr r5, [r11, #-0x43c]
 *   @0x1e0954 str r5, [r0]
 *   @0x1e0958 b 0x1e084c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0xd8>
 *   @0x1e095c sub r8, r11, #1056
 *   @0x1e0960 mov r1, r9
 *   @0x1e0964 sub r8, r8, #4
 *   @0x1e0968 mov r2, #1024
 *   @0x1e096c sub r8, r8, #4
 *   @0x1e0970 mov r0, r8
 *   @0x1e0974 bl 0xb65b0 <memset@plt>
 *   @0x1e0978 mov r0, r7
 *   @0x1e097c bl 0x1e058c <_Z11Script_Namei>
 *   @0x1e0980 ldr r12, [pc, #0x160]
 *   @0x1e0984 ldr r2, [pc, #0x160]
 *   @0x1e0988 mov r1, #1024
 *   @0x1e098c ldr r4, [r4, r12]
 *   @0x1e0990 add r2, pc, r2
 *   @0x1e0994 ldr r12, [r4]
 *   @0x1e0998 ldr r12, [r12]
 *   @0x1e099c str r12, [sp]
 *   @0x1e09a0 mov r3, r0
 *   @0x1e09a4 mov r0, r8
 *   @0x1e09a8 bl 0xb65c8 <snprintf@plt>
 *   @0x1e09ac ldr r7, [r4]
 *   @0x1e09b0 cmp r7, #0
 *   @0x1e09b4 beq 0x1e09dc <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x268>
 *   @0x1e09b8 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1e09bc ldr r3, [r7, #0x4]
 *   @0x1e09c0 sub r3, r3, #1
 *   @0x1e09c4 str r3, [r7, #0x4]
 *   @0x1e09c8 cmp r3, #0
 *   @0x1e09cc beq 0x1e0a0c <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x298>
 *   @0x1e09d0 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1e09d4 mov r0, r7
 *   @0x1e09d8 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e09dc mov r0, #12
 *   @0x1e09e0 bl 0x27c524 <_Znwj>
 *   @0x1e09e4 mov r7, r0
 *   @0x1e09e8 mov r0, r8
 *   @0x1e09ec bl 0xb6538 <strlen@plt>
 *   @0x1e09f0 str r0, [r7, #0x8]
 *   @0x1e09f4 mov r0, r8
 *   @0x1e09f8 bl 0xdb8c8 <_Z8YYStrDupPKc>
 *   @0x1e09fc mov r3, #1
 *   @0x1e0a00 stm r7, {r0, r3}
 *   @0x1e0a04 str r7, [r4]
 *   @0x1e0a08 b 0x1e08c8 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x154>
 *   @0x1e0a0c ldr r0, [r7]
 *   @0x1e0a10 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1e0a14 str r9, [r7]
 *   @0x1e0a18 str r9, [r7, #0x8]
 *   @0x1e0a1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x1e0a20 ldr r3, [r7, #0x4]
 *   @0x1e0a24 sub r3, r3, #1
 *   @0x1e0a28 str r3, [r7, #0x4]
 *   @0x1e0a2c cmp r3, #0
 *   @0x1e0a30 bne 0x1e0a54 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x2e0>
 *   @0x1e0a34 ldr r0, [r7]
 *   @0x1e0a38 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x1e0a3c mov r0, r7
 *   @0x1e0a40 str r9, [r7]
 *   @0x1e0a44 str r9, [r7, #0x8]
 *   @0x1e0a48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x1e0a4c mov r0, r7
 *   @0x1e0a50 bl 0x27d1d0 <_ZdlPv>
 *   @0x1e0a54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x1e0a58 mov r0, r7
 *   @0x1e0a5c bl 0x27d1d0 <_ZdlPv>
 *   @0x1e0a60 b 0x1e09d0 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x25c>
 *   @0x1e0a64 str r9, [r5]
 *   @0x1e0a68 b 0x1e0894 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x120>
 *   @0x1e0a6c lsl r4, r6, #2
 *   @0x1e0a70 cmp r6, #0
 *   @0x1e0a74 add r12, r4, #14
 *   @0x1e0a78 ldr r0, [r5]
 *   @0x1e0a7c bic r12, r12, #7
 *   @0x1e0a80 sub sp, sp, r12
 *   @0x1e0a84 add lr, sp, #8
 *   @0x1e0a88 addgt r4, lr, r4
 *   @0x1e0a8c movgt r12, lr
 *   @0x1e0a90 ble 0x1e0aa4 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x330>
 *   @0x1e0a94 str r0, [r12], #4
 *   @0x1e0a98 cmp r12, r4
 *   @0x1e0a9c add r0, r0, #16
 *   @0x1e0aa0 bne 0x1e0a94 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x320>
 *   @0x1e0aa4 ldr r12, [r1, #0xc]
 *   @0x1e0aa8 mov r0, r8
 *   @0x1e0aac str lr, [sp]
 *   @0x1e0ab0 mov r1, r2
 *   @0x1e0ab4 mov r2, r3
 *   @0x1e0ab8 mov r3, r6
 *   @0x1e0abc ldr r12, [r12, #0x4]
 *   @0x1e0ac0 mov r9, #1
 *   @0x1e0ac4 blx r12
 *   @0x1e0ac8 b 0x1e08c8 <_Z14Script_PerformiP9CInstanceS0_iP6RValueP20DynamicArrayOfRValue+0x154>
 *   @0x1e0acc bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x1e0ad0 eoreq r1, r1, r4, asr #9
 *   @0x1e0ad4 .word 0xffffbd00
 *   @0x1e0ad8 .word 0xffffc0bc
 *   @0x1e0adc .word 0xffffc0c0
 *   @0x1e0ae0 .word 0xfffff0dc
 *   @0x1e0ae4 .word 0xfffff0d8
 *   @0x1e0ae8 .word 0xffffbf20
 *   @0x1e0aec andseq r1, r7, r12, lsr #7
 *
 * ══ §27/31 F_JS_ToString  0x24dd3c  size 888  222 条（0x24dd3c..0x24e0b4）
 * @func 0x24dd3c 0x24e0b4  size 888  222 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: FREE_RValue__Pre(RValue*)×2 / YYCreateString(RValue*, char const*) / F_JS_ToPrimitive(RValue&, RValue&, int) / yyisinf(RValue&) / F_JS_ToString(RValue&, RValue*)+0x334 / GetContextStackTop() / DeterminePotentialRoot(YYObjectBase*, YYObjectBase*) / F_JS_ToString(RValue&, RValue*)
 * 字段偏移 top8: 0x4×6 / 0xc×5 / 0x8×4 / 0x18×4 / 0x11c×2 / 0x340×1 / 0x2cc×1 / 0x10×1
 * VFP 指令 13 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x24dd3c push {r4, r5, r6, r7, lr}
 *   @0x24dd40 mvn r3, #-16777216
 *   @0x24dd44 ldr r7, [pc, #0x340]
 *   @0x24dd48 mov r6, r0
 *   @0x24dd4c str r3, [r0, #0xc]
 *   @0x24dd50 sub sp, sp, #292
 *   @0x24dd54 ldr r7, [pc, r7]
 *   @0x24dd58 ldr r0, [r1, #0xc]
 *   @0x24dd5c mov r3, #0
 *   @0x24dd60 str r3, [r6, #0x4]
 *   @0x24dd64 ldr r12, [r7]
 *   @0x24dd68 bic r2, r0, #-16777216
 *   @0x24dd6c str r3, [r6]
 *   @0x24dd70 str r3, [r6, #0x8]
 *   @0x24dd74 str r12, [sp, #0x11c]
 *   @0x24dd78 cmp r2, #13
 *   @0x24dd7c addls pc, pc, r2, lsl #2
 *   @0x24dd80 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24dd84 b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130>
 *   @0x24dd88 b 0x24debc <_Z13F_JS_ToStringR6RValuePS_+0x180>
 *   @0x24dd8c b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24dd90 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24dd94 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24dd98 b 0x24ddbc <_Z13F_JS_ToStringR6RValuePS_+0x80>
 *   @0x24dd9c b 0x24dde8 <_Z13F_JS_ToStringR6RValuePS_+0xac>
 *   @0x24dda0 b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130>
 *   @0x24dda4 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24dda8 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24ddac b 0x24de6c <_Z13F_JS_ToStringR6RValuePS_+0x130>
 *   @0x24ddb0 b 0x24df20 <_Z13F_JS_ToStringR6RValuePS_+0x1e4>
 *   @0x24ddb4 b 0x24de40 <_Z13F_JS_ToStringR6RValuePS_+0x104>
 *   @0x24ddb8 b 0x24de4c <_Z13F_JS_ToStringR6RValuePS_+0x110>
 *   @0x24ddbc ldr r1, [pc, #0x2cc]
 *   @0x24ddc0 add r1, pc, r1
 *   @0x24ddc4 mov r0, r6
 *   @0x24ddc8 bl 0xe5258 <_Z14YYCreateStringP6RValuePKc>
 *   @0x24ddcc mov r0, #0
 *   @0x24ddd0 ldr r2, [sp, #0x11c]
 *   @0x24ddd4 ldr r3, [r7]
 *   @0x24ddd8 cmp r2, r3
 *   @0x24dddc bne 0x24e088 <_Z13F_JS_ToStringR6RValuePS_+0x34c>
 *   @0x24dde0 add sp, sp, #292
 *   @0x24dde4 pop {r4, r5, r6, r7, pc}
 *   @0x24dde8 add r5, sp, #12
 *   @0x24ddec mov r2, #1
 *   @0x24ddf0 mov r4, #0
 *   @0x24ddf4 mvn r3, #-16777216
 *   @0x24ddf8 mov r0, r5
 *   @0x24ddfc str r4, [sp, #0xc]
 *   @0x24de00 str r4, [sp, #0x10]
 *   @0x24de04 str r4, [sp, #0x14]
 *   @0x24de08 str r3, [sp, #0x18]
 *   @0x24de0c bl 0x24cd64 <_Z16F_JS_ToPrimitiveR6RValueS0_i>
 *   @0x24de10 cmp r0, #2
 *   @0x24de14 beq 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24de18 cmp r0, #1
 *   @0x24de1c bne 0x24df68 <_Z13F_JS_ToStringR6RValuePS_+0x22c>
 *   @0x24de20 ldr r3, [sp, #0x18]
 *   @0x24de24 sub r3, r3, #1
 *   @0x24de28 bic r3, r3, #-16777216
 *   @0x24de2c bic r3, r3, #3
 *   @0x24de30 cmp r3, r4
 *   @0x24de34 beq 0x24e04c <_Z13F_JS_ToStringR6RValuePS_+0x310>
 *   @0x24de38 mov r0, #1
 *   @0x24de3c b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24de40 ldr r1, [pc, #0x24c]
 *   @0x24de44 add r1, pc, r1
 *   @0x24de48 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24de4c ldm r1, {r2, r3}
 *   @0x24de50 vmov d6, r2, r3
 *   @0x24de54 vcmp.f64 d6, #0
 *   @0x24de58 vmrs APSR_nzcv, fpscr
 *   @0x24de5c bne 0x24df5c <_Z13F_JS_ToStringR6RValuePS_+0x220>
 *   @0x24de60 ldr r1, [pc, #0x230]
 *   @0x24de64 add r1, pc, r1
 *   @0x24de68 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24de6c ldm r1, {r2, r3}
 *   @0x24de70 vmov d7, r2, r3
 *   @0x24de74 vmov d6, r2, r3
 *   @0x24de78 vcmp.f64 d7, d6
 *   @0x24de7c vmrs APSR_nzcv, fpscr
 *   @0x24de80 bvs 0x24e07c <_Z13F_JS_ToStringR6RValuePS_+0x340>
 *   @0x24de84 mov r0, r1
 *   @0x24de88 str r1, [sp, #0x4]
 *   @0x24de8c bl 0x240970 <_Z7yyisinfR6RValue>
 *   @0x24de90 ldr r1, [sp, #0x4]
 *   @0x24de94 subs r2, r0, #0
 *   @0x24de98 beq 0x24dfa0 <_Z13F_JS_ToStringR6RValuePS_+0x264>
 *   @0x24de9c ldm r1, {r2, r3}
 *   @0x24dea0 vmov d7, r2, r3
 *   @0x24dea4 vcmpe.f64 d7, #0
 *   @0x24dea8 vmrs APSR_nzcv, fpscr
 *   @0x24deac ble 0x24e070 <_Z13F_JS_ToStringR6RValuePS_+0x334>
 *   @0x24deb0 ldr r1, [pc, #0x1e4]
 *   @0x24deb4 add r1, pc, r1
 *   @0x24deb8 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24debc str r0, [r6, #0xc]
 *   @0x24dec0 mov r0, #0
 *   @0x24dec4 ldr r3, [r1, #0xc]
 *   @0x24dec8 ldr r2, [r1, #0x8]
 *   @0x24decc bic r3, r3, #-16777216
 *   @0x24ded0 str r0, [r6]
 *   @0x24ded4 str r2, [r6, #0x8]
 *   @0x24ded8 cmp r3, #14
 *   @0x24dedc addls pc, pc, r3, lsl #2
 *   @0x24dee0 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24dee4 b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294>
 *   @0x24dee8 b 0x24e014 <_Z13F_JS_ToStringR6RValuePS_+0x2d8>
 *   @0x24deec b 0x24dfe4 <_Z13F_JS_ToStringR6RValuePS_+0x2a8>
 *   @0x24def0 b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284>
 *   @0x24def4 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24def8 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24defc b 0x24df2c <_Z13F_JS_ToStringR6RValuePS_+0x1f0>
 *   @0x24df00 b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284>
 *   @0x24df04 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df08 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df0c b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294>
 *   @0x24df10 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df14 b 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df18 b 0x24dfd0 <_Z13F_JS_ToStringR6RValuePS_+0x294>
 *   @0x24df1c b 0x24dfc0 <_Z13F_JS_ToStringR6RValuePS_+0x284>
 *   @0x24df20 ldr r1, [pc, #0x178]
 *   @0x24df24 add r1, pc, r1
 *   @0x24df28 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24df2c ldr r3, [r1]
 *   @0x24df30 str r3, [r6]
 *   @0x24df34 ldr r3, [r1]
 *   @0x24df38 cmp r3, #0
 *   @0x24df3c beq 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df40 str r1, [sp, #0x4]
 *   @0x24df44 bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x24df48 ldr r1, [sp, #0x4]
 *   @0x24df4c ldr r1, [r1]
 *   @0x24df50 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x24df54 mov r0, #0
 *   @0x24df58 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24df5c ldr r1, [pc, #0x140]
 *   @0x24df60 add r1, pc, r1
 *   @0x24df64 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24df68 mov r0, r6
 *   @0x24df6c mov r1, r5
 *   @0x24df70 bl 0x24dd3c <_Z13F_JS_ToStringR6RValuePS_>
 *   @0x24df74 cmp r0, #1
 *   @0x24df78 beq 0x24e034 <_Z13F_JS_ToStringR6RValuePS_+0x2f8>
 *   @0x24df7c ldr r0, [sp, #0x18]
 *   @0x24df80 sub r0, r0, #1
 *   @0x24df84 bic r0, r0, #-16777216
 *   @0x24df88 bics r6, r0, #3
 *   @0x24df8c bne 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24df90 mov r0, r5
 *   @0x24df94 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24df98 mov r0, r6
 *   @0x24df9c b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24dfa0 ldm r1, {r4, r5}
 *   @0x24dfa4 vmov d6, r4, r5
 *   @0x24dfa8 vcmp.f64 d6, #0
 *   @0x24dfac vmrs APSR_nzcv, fpscr
 *   @0x24dfb0 bne 0x24e058 <_Z13F_JS_ToStringR6RValuePS_+0x31c>
 *   @0x24dfb4 ldr r1, [pc, #0xec]
 *   @0x24dfb8 add r1, pc, r1
 *   @0x24dfbc b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24dfc0 ldr r3, [r1]
 *   @0x24dfc4 mov r0, #0
 *   @0x24dfc8 str r3, [r6]
 *   @0x24dfcc b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24dfd0 ldr r2, [r1]
 *   @0x24dfd4 mov r0, #0
 *   @0x24dfd8 ldr r3, [r1, #0x4]
 *   @0x24dfdc stm r6, {r2, r3}
 *   @0x24dfe0 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24dfe4 ldr r3, [r1]
 *   @0x24dfe8 cmp r3, #0
 *   @0x24dfec str r3, [r6]
 *   @0x24dff0 beq 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24dff4 ldr r0, [r3, #0x8]
 *   @0x24dff8 ldr r2, [r3]
 *   @0x24dffc cmp r0, #0
 *   @0x24e000 streq r6, [r3, #0x8]
 *   @0x24e004 add r2, r2, #1
 *   @0x24e008 str r2, [r3]
 *   @0x24e00c bne 0x24df54 <_Z13F_JS_ToStringR6RValuePS_+0x218>
 *   @0x24e010 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24e014 ldr r3, [r1]
 *   @0x24e018 mov r0, #0
 *   @0x24e01c cmp r3, #0
 *   @0x24e020 ldrne r2, [r3, #0x4]
 *   @0x24e024 addne r2, r2, #1
 *   @0x24e028 strne r2, [r3, #0x4]
 *   @0x24e02c str r3, [r6]
 *   @0x24e030 b 0x24ddd0 <_Z13F_JS_ToStringR6RValuePS_+0x94>
 *   @0x24e034 ldr r3, [sp, #0x18]
 *   @0x24e038 sub r3, r3, #1
 *   @0x24e03c bic r3, r3, #-16777216
 *   @0x24e040 bic r3, r3, #3
 *   @0x24e044 cmp r3, #0
 *   @0x24e048 bne 0x24de38 <_Z13F_JS_ToStringR6RValuePS_+0xfc>
 *   @0x24e04c mov r0, r5
 *   @0x24e050 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x24e054 b 0x24de38 <_Z13F_JS_ToStringR6RValuePS_+0xfc>
 *   @0x24e058 add r4, sp, #28
 *   @0x24e05c mov r3, #256
 *   @0x24e060 mov r0, r4
 *   @0x24e064 bl 0x23f6c4 <_Z6g_dfmtPcPdij>
 *   @0x24e068 mov r1, r4
 *   @0x24e06c b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24e070 ldr r1, [pc, #0x34]
 *   @0x24e074 add r1, pc, r1
 *   @0x24e078 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24e07c ldr r1, [pc, #0x2c]
 *   @0x24e080 add r1, pc, r1
 *   @0x24e084 b 0x24ddc4 <_Z13F_JS_ToStringR6RValuePS_+0x88>
 *   @0x24e088 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x24e08c ldrsheq pc, [r9], -r12
 *   @0x24e090 andeq r4, lr, r0, lsr #9
 *   @0x24e094 andeq r4, lr, r0, ror #8
 *   @0x24e098 andeq r6, lr, r4, asr #23
 *   @0x24e09c andseq r7, r0, r8, lsr r5
 *   @0x24e0a0 mulseq r0, r0, r4
 *   @0x24e0a4 andeq r6, lr, r0, asr #21
 *   @0x24e0a8 andeq r4, lr, r4, lsr r5
 *   @0x24e0ac andseq r7, r0, r8, asr #28
 *   @0x24e0b0 andeq r4, lr, r4, ror r4
 *
 * ══ §28/31 b2ParticleSystem::SolvePressure  0x2d90a4  size 888  222 条（0x2d90a4..0x2d941c）
 * @func 0x2d90a4 0x2d941c  size 888  222 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolvePressure(b2TimeStep const&)+0x34 / b2ParticleSystem::SolvePressure(b2TimeStep const&)+0x7c / b2ParticleSystem::SolvePressure(b2TimeStep const&)+0xd4 / b2ParticleSystem::SolvePressure(b2TimeStep const&)+0x118 / b2ParticleSystem::GetCriticalPressure(b2TimeStep const&) const / b2ParticleSystem::SolvePressure(b2TimeStep const&)+0x19c / b2ParticleSystem::SolvePressure(b2TimeStep const&)+0x2c4 / b2ParticleSystem::GetParticleInvMass() const
 * 字段偏移 top8: 0x48×6 / 0x4×4 / 0x80×3 / 0x-8×3 / 0x24×2 / 0x88×2 / 0x74×2 / 0x7c×2
 * VFP 指令 95 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d90a4 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2d90a8 vpush {d8, d9, d10}
 *   @0x2d90ac mov r4, r0
 *   @0x2d90b0 ldr lr, [r0, #0x24]
 *   @0x2d90b4 mov r5, r1
 *   @0x2d90b8 cmp lr, #0
 *   @0x2d90bc ble 0x2d90d8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x34>
 *   @0x2d90c0 ldr r3, [r0, #0x48]
 *   @0x2d90c4 mov r1, #0
 *   @0x2d90c8 add r2, r3, lr, lsl #2
 *   @0x2d90cc str r1, [r3], #4
 *   @0x2d90d0 cmp r3, r2
 *   @0x2d90d4 bne 0x2d90cc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x28>
 *   @0x2d90d8 ldr r1, [r4, #0x80]
 *   @0x2d90dc cmp r1, #0
 *   @0x2d90e0 ble 0x2d9120 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x7c>
 *   @0x2d90e4 ldr r3, [r4, #0x88]
 *   @0x2d90e8 add r1, r1, r1, lsl #1
 *   @0x2d90ec ldr r0, [r4, #0x48]
 *   @0x2d90f0 add r3, r3, #8
 *   @0x2d90f4 add r1, r3, r1, lsl #3
 *   @0x2d90f8 ldr r2, [r3, #-0x8]
 *   @0x2d90fc mov r12, r3
 *   @0x2d9100 vldr s15, [r12]
 *   @0x2d9104 add r3, r3, #24
 *   @0x2d9108 cmp r3, r1
 *   @0x2d910c add r2, r0, r2, lsl #2
 *   @0x2d9110 vldr s14, [r2]
 *   @0x2d9114 vadd.f32 s15, s14, s15
 *   @0x2d9118 vstr s15, [r2]
 *   @0x2d911c bne 0x2d90f8 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x54>
 *   @0x2d9120 ldr r1, [r4, #0x74]
 *   @0x2d9124 cmp r1, #0
 *   @0x2d9128 ble 0x2d9178 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0xd4>
 *   @0x2d912c ldr r3, [r4, #0x7c]
 *   @0x2d9130 add r1, r1, r1, lsl #1
 *   @0x2d9134 ldr r12, [r4, #0x48]
 *   @0x2d9138 add r3, r3, #12
 *   @0x2d913c add r1, r3, r1, lsl #3
 *   @0x2d9140 ldr r0, [r3, #-0xc]
 *   @0x2d9144 vldr s15, [r3]
 *   @0x2d9148 ldr r2, [r3, #-0x8]
 *   @0x2d914c add r3, r3, #24
 *   @0x2d9150 cmp r3, r1
 *   @0x2d9154 add r0, r12, r0, lsl #2
 *   @0x2d9158 vldr s14, [r0]
 *   @0x2d915c vadd.f32 s14, s14, s15
 *   @0x2d9160 add r2, r12, r2, lsl #2
 *   @0x2d9164 vstr s14, [r0]
 *   @0x2d9168 vldr s14, [r2]
 *   @0x2d916c vadd.f32 s15, s14, s15
 *   @0x2d9170 vstr s15, [r2]
 *   @0x2d9174 bne 0x2d9140 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x9c>
 *   @0x2d9178 ldr r3, [r4, #0x4]
 *   @0x2d917c tst r3, #64
 *   @0x2d9180 beq 0x2d91bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x118>
 *   @0x2d9184 cmp lr, #0
 *   @0x2d9188 ble 0x2d91bc <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x118>
 *   @0x2d918c ldr r1, [r4, #0x30]
 *   @0x2d9190 lsl lr, lr, #2
 *   @0x2d9194 mov r3, #0
 *   @0x2d9198 mov r0, #0
 *   @0x2d919c ldr r2, [r1, r3]
 *   @0x2d91a0 tst r2, #64
 *   @0x2d91a4 ldrne r2, [r4, #0x48]
 *   @0x2d91a8 addne r2, r2, r3
 *   @0x2d91ac add r3, r3, #4
 *   @0x2d91b0 strne r0, [r2]
 *   @0x2d91b4 cmp r3, lr
 *   @0x2d91b8 bne 0x2d919c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0xf8>
 *   @0x2d91bc mov r0, r4
 *   @0x2d91c0 mov r1, r5
 *   @0x2d91c4 vldr s19, [r4, #172]
 *   @0x2d91c8 bl 0x2d8584 <_ZNK16b2ParticleSystem19GetCriticalPressureERK10b2TimeStep>
 *   @0x2d91cc ldr r2, [r4, #0x24]
 *   @0x2d91d0 cmp r2, #0
 *   @0x2d91d4 vmov s15, r0
 *   @0x2d91d8 vmul.f32 s19, s19, s15
 *   @0x2d91dc ble 0x2d9240 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x19c>
 *   @0x2d91e0 ldr r3, [r4, #0x48]
 *   @0x2d91e4 add r2, r3, r2, lsl #2
 *   @0x2d91e8 vmov.f32 s13, #5.000000e+00
 *   @0x2d91ec vmov.f32 s12, #1.000000e+00
 *   @0x2d91f0 b 0x2d9218 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x174>
 *   @0x2d91f4 vsub.f32 s15, s15, s12
 *   @0x2d91f8 vldr s14, [pc, #536]
 *   @0x2d91fc vcmpe.f32 s15, s14
 *   @0x2d9200 vmrs APSR_nzcv, fpscr
 *   @0x2d9204 bpl 0x2d922c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x188>
 *   @0x2d9208 vmul.f32 s14, s19, s14
 *   @0x2d920c cmp r3, r2
 *   @0x2d9210 vstr s14, [r3, #-4]
 *   @0x2d9214 beq 0x2d9240 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x19c>
 *   @0x2d9218 vldmia r3!, {s15}
 *   @0x2d921c vcmpe.f32 s15, s13
 *   @0x2d9220 vmrs APSR_nzcv, fpscr
 *   @0x2d9224 bmi 0x2d91f4 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x150>
 *   @0x2d9228 vmov.f32 s15, #4.000000e+00
 *   @0x2d922c cmp r3, r2
 *   @0x2d9230 vmov.f32 s14, s15
 *   @0x2d9234 vmul.f32 s14, s19, s14
 *   @0x2d9238 vstr s14, [r3, #-4]
 *   @0x2d923c bne 0x2d9218 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x174>
 *   @0x2d9240 vldr s15, [r4, #24]
 *   @0x2d9244 vldr s18, [r4, #12]
 *   @0x2d9248 vmul.f32 s18, s18, s15
 *   @0x2d924c ldr r3, [r4, #0x80]
 *   @0x2d9250 vldr s15, [r5]
 *   @0x2d9254 cmp r3, #0
 *   @0x2d9258 movgt r7, #0
 *   @0x2d925c movgt r9, #0
 *   @0x2d9260 movgt r8, r7
 *   @0x2d9264 vdiv.f32 s18, s15, s18
 *   @0x2d9268 ble 0x2d9368 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2c4>
 *   @0x2d926c ldr r2, [r4, #0x88]
 *   @0x2d9270 mov r0, r4
 *   @0x2d9274 ldr r12, [r4, #0x48]
 *   @0x2d9278 add r3, r2, r7
 *   @0x2d927c vldr s14, [r3, #8]
 *   @0x2d9280 ldr r5, [r2, r7]
 *   @0x2d9284 vldr s13, [r3, #20]
 *   @0x2d9288 ldr r1, [r4, #0x38]
 *   @0x2d928c vldr s16, [r3, #12]
 *   @0x2d9290 vldr s17, [r3, #16]
 *   @0x2d9294 ldr r6, [r3, #0x4]
 *   @0x2d9298 add r2, r12, r5, lsl #2
 *   @0x2d929c vldr s15, [r2]
 *   @0x2d92a0 ldr r2, [r4, #0x40]
 *   @0x2d92a4 lsl r5, r5, #3
 *   @0x2d92a8 add r3, r1, r5
 *   @0x2d92ac vldr s20, [r3]
 *   @0x2d92b0 add r5, r2, r5
 *   @0x2d92b4 vldr s21, [r3, #4]
 *   @0x2d92b8 vmul.f32 s12, s18, s14
 *   @0x2d92bc vmla.f32 s15, s19, s14
 *   @0x2d92c0 vmul.f32 s14, s12, s13
 *   @0x2d92c4 vmul.f32 s15, s14, s15
 *   @0x2d92c8 vmul.f32 s16, s15, s16
 *   @0x2d92cc vmul.f32 s17, s15, s17
 *   @0x2d92d0 bl 0x2d8a20 <_ZNK16b2ParticleSystem18GetParticleInvMassEv>
 *   @0x2d92d4 vldr s14, [r5]
 *   @0x2d92d8 vldr s15, [r5, #4]
 *   @0x2d92dc ldr r3, [r6]
 *   @0x2d92e0 cmp r3, #2
 *   @0x2d92e4 vmov s13, r0
 *   @0x2d92e8 vmls.f32 s14, s13, s16
 *   @0x2d92ec vmls.f32 s15, s13, s17
 *   @0x2d92f0 vstr s14, [r5]
 *   @0x2d92f4 vstr s15, [r5, #4]
 *   @0x2d92f8 bne 0x2d9354 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2b0>
 *   @0x2d92fc vldr s15, [r6, #64]
 *   @0x2d9300 vsub.f32 s21, s21, s15
 *   @0x2d9304 vldr s10, [r6, #60]
 *   @0x2d9308 vldr s14, [r6, #88]
 *   @0x2d930c vldr s12, [r6, #136]
 *   @0x2d9310 vldr s13, [r6, #80]
 *   @0x2d9314 vldr s15, [r6, #84]
 *   @0x2d9318 vldr s11, [r6, #144]
 *   @0x2d931c ldrh r3, [r6, #4]
 *   @0x2d9320 tst r3, #2
 *   @0x2d9324 orr r3, r3, #2
 *   @0x2d9328 streq r9, [r6, #0xa0]
 *   @0x2d932c strheq r3, [r6, #4]
 *   @0x2d9330 vmul.f32 s21, s16, s21
 *   @0x2d9334 vsub.f32 s20, s20, s10
 *   @0x2d9338 vnmls.f32 s21, s17, s20
 *   @0x2d933c vmla.f32 s13, s16, s12
 *   @0x2d9340 vmla.f32 s14, s21, s11
 *   @0x2d9344 vstr s13, [r6, #80]
 *   @0x2d9348 vmla.f32 s15, s17, s12
 *   @0x2d934c vstr s14, [r6, #88]
 *   @0x2d9350 vstr s15, [r6, #84]
 *   @0x2d9354 ldr r3, [r4, #0x80]
 *   @0x2d9358 add r8, r8, #1
 *   @0x2d935c add r7, r7, #24
 *   @0x2d9360 cmp r3, r8
 *   @0x2d9364 bgt 0x2d926c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x1c8>
 *   @0x2d9368 ldr r6, [r4, #0x74]
 *   @0x2d936c cmp r6, #0
 *   @0x2d9370 ble 0x2d9410 <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x36c>
 *   @0x2d9374 ldr r3, [r4, #0x7c]
 *   @0x2d9378 add r6, r6, r6, lsl #1
 *   @0x2d937c ldr r5, [r4, #0x48]
 *   @0x2d9380 ldr r12, [r4, #0x40]
 *   @0x2d9384 add r6, r3, r6, lsl #3
 *   @0x2d9388 add r0, r3, #12
 *   @0x2d938c ldr r1, [r0, #-0xc]
 *   @0x2d9390 mov r4, r0
 *   @0x2d9394 ldr r2, [r0, #-0x8]
 *   @0x2d9398 vldr s10, [r4]
 *   @0x2d939c vmul.f32 s10, s18, s10
 *   @0x2d93a0 vldr s14, [r3, #16]
 *   @0x2d93a4 add r4, r5, r1, lsl #2
 *   @0x2d93a8 vldr s15, [r4]
 *   @0x2d93ac add r4, r5, r2, lsl #2
 *   @0x2d93b0 vldr s9, [r4]
 *   @0x2d93b4 vldr s11, [r3, #20]
 *   @0x2d93b8 add r1, r12, r1, lsl #3
 *   @0x2d93bc vldr s13, [r1]
 *   @0x2d93c0 vldr s12, [r1, #4]
 *   @0x2d93c4 add r2, r12, r2, lsl #3
 *   @0x2d93c8 add r3, r3, #24
 *   @0x2d93cc cmp r3, r6
 *   @0x2d93d0 add r0, r0, #24
 *   @0x2d93d4 vadd.f32 s15, s15, s9
 *   @0x2d93d8 vmul.f32 s15, s10, s15
 *   @0x2d93dc vmul.f32 s14, s15, s14
 *   @0x2d93e0 vmul.f32 s15, s15, s11
 *   @0x2d93e4 vsub.f32 s13, s13, s14
 *   @0x2d93e8 vsub.f32 s12, s12, s15
 *   @0x2d93ec vstr s13, [r1]
 *   @0x2d93f0 vldr s13, [r2]
 *   @0x2d93f4 vstr s12, [r1, #4]
 *   @0x2d93f8 vadd.f32 s14, s13, s14
 *   @0x2d93fc vldr s13, [r2, #4]
 *   @0x2d9400 vadd.f32 s15, s13, s15
 *   @0x2d9404 vstr s14, [r2]
 *   @0x2d9408 vstr s15, [r2, #4]
 *   @0x2d940c bne 0x2d938c <_ZN16b2ParticleSystem13SolvePressureERK10b2TimeStep+0x2e8>
 *   @0x2d9410 vpop {d8, d9, d10}
 *   @0x2d9414 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2d9418 andeq r0, r0, r0
 *
 * ══ §29/31 SetArrayEntry  0x247904  size 868  217 条（0x247904..0x247c68）
 * @func 0x247904 0x247c68  size 868  217 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: LOCK_RVALUE_MUTEX()×4 / UNLOCK_RVALUE_MUTEX()×4 / YYFree(void const*)×4 / operator delete(void*)×4 / SetArrayEntry(YYObjectBase*, unsigned int, RValue*)+0x84×2 / PushContextStack(YYObjectBase*) / SetArrayEntry(YYObjectBase*, unsigned int, RValue*)+0x160 / SetArrayEntry(YYObjectBase*, unsigned int, RValue*)+0x7c
 * 字段偏移 top8: 0x4×13 / 0x8×9 / 0xc×7 / 0x2c×4 / 0x24×3 / 0x1f4×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x247904 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x247908 mov r4, r0
 *   @0x24790c sub sp, sp, #8
 *   @0x247910 mov r6, r1
 *   @0x247914 mov r7, r2
 *   @0x247918 bl 0xd3968 <_Z16PushContextStackP12YYObjectBase>
 *   @0x24791c ldr r5, [r4, #0x2c]
 *   @0x247920 cmp r5, r6
 *   @0x247924 bls 0x247a64 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x160>
 *   @0x247928 ldr r0, [r4, #0x4]
 *   @0x24792c cmp r0, #0
 *   @0x247930 beq 0x247a54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x150>
 *   @0x247934 ldr r3, [r4, #0x24]
 *   @0x247938 cmp r6, r3
 *   @0x24793c blo 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84>
 *   @0x247940 ldr r2, [r4, #0x2c]
 *   @0x247944 cmp r6, r2
 *   @0x247948 bhs 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84>
 *   @0x24794c rsb r12, r3, r6
 *   @0x247950 add r3, r0, r3, lsl #4
 *   @0x247954 cmp r12, #1
 *   @0x247958 mvnhi r1, #-16777216
 *   @0x24795c movhi lr, #5
 *   @0x247960 bls 0x247980 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x7c>
 *   @0x247964 ldr r2, [r3, #0xc]
 *   @0x247968 sub r12, r12, #1
 *   @0x24796c add r3, r3, #16
 *   @0x247970 cmp r2, r1
 *   @0x247974 streq lr, [r3, #-0x4]
 *   @0x247978 cmp r12, #1
 *   @0x24797c bne 0x247964 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x60>
 *   @0x247980 add r3, r6, #1
 *   @0x247984 str r3, [r4, #0x24]
 *   @0x247988 lsl r8, r6, #4
 *   @0x24798c add r5, r0, r8
 *   @0x247990 ldr r2, [r5, #0xc]
 *   @0x247994 bic r3, r2, #-16777216
 *   @0x247998 cmp r3, #1
 *   @0x24799c beq 0x247ad8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1d4>
 *   @0x2479a0 cmp r3, #2
 *   @0x2479a4 bne 0x2479cc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xc8>
 *   @0x2479a8 sub r3, r2, #1
 *   @0x2479ac bic r3, r3, #-16777216
 *   @0x2479b0 bic r3, r3, #3
 *   @0x2479b4 cmp r3, #0
 *   @0x2479b8 beq 0x247bb8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2b4>
 *   @0x2479bc mov r2, #0
 *   @0x2479c0 mov r3, #5
 *   @0x2479c4 str r2, [r5, #0x8]
 *   @0x2479c8 str r3, [r5, #0xc]
 *   @0x2479cc ldr r3, [r7, #0xc]
 *   @0x2479d0 mov r1, #0
 *   @0x2479d4 ldr r2, [r7, #0x8]
 *   @0x2479d8 str r1, [r5]
 *   @0x2479dc str r3, [r5, #0xc]
 *   @0x2479e0 ldr r3, [r7, #0xc]
 *   @0x2479e4 str r2, [r5, #0x8]
 *   @0x2479e8 bic r3, r3, #-16777216
 *   @0x2479ec cmp r3, #14
 *   @0x2479f0 addls pc, pc, r3, lsl #2
 *   @0x2479f4 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x2479f8 b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208>
 *   @0x2479fc b 0x247b68 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x264>
 *   @0x247a00 b 0x247b3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x238>
 *   @0x247a04 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130>
 *   @0x247a08 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a0c b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a10 b 0x247b18 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x214>
 *   @0x247a14 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130>
 *   @0x247a18 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a1c b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a20 b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208>
 *   @0x247a24 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a28 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247a2c b 0x247b0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x208>
 *   @0x247a30 b 0x247a34 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x130>
 *   @0x247a34 ldr r3, [r7]
 *   @0x247a38 str r3, [r5]
 *   @0x247a3c ldr r3, [r4, #0x4]
 *   @0x247a40 cmp r3, #0
 *   @0x247a44 beq 0x247bc4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2c0>
 *   @0x247a48 add r0, r3, r8
 *   @0x247a4c mov r2, #6
 *   @0x247a50 str r2, [r0, #0x8]
 *   @0x247a54 bl 0xd3a34 <_Z15PopContextStackv>
 *   @0x247a58 mov r0, #1
 *   @0x247a5c add sp, sp, #8
 *   @0x247a60 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x247a64 add r5, r5, r5, lsl #1
 *   @0x247a68 ldr r2, [pc, #0x1f4]
 *   @0x247a6c ldr r0, [r4, #0x4]
 *   @0x247a70 mov r3, #0
 *   @0x247a74 lsr r5, r5, #1
 *   @0x247a78 str r3, [sp]
 *   @0x247a7c cmp r6, r5
 *   @0x247a80 add r2, pc, r2
 *   @0x247a84 addhs r5, r6, #1
 *   @0x247a88 mov r3, #74
 *   @0x247a8c lsl r1, r5, #4
 *   @0x247a90 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib>
 *   @0x247a94 cmp r0, #0
 *   @0x247a98 str r0, [r4, #0x4]
 *   @0x247a9c beq 0x247a54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x150>
 *   @0x247aa0 ldr r12, [r4, #0x2c]
 *   @0x247aa4 subs r3, r5, r12
 *   @0x247aa8 add r12, r0, r12, lsl #4
 *   @0x247aac mvnne r2, #-16777216
 *   @0x247ab0 beq 0x247ac4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1c0>
 *   @0x247ab4 subs r3, r3, #1
 *   @0x247ab8 str r2, [r12, #0xc]
 *   @0x247abc add r12, r12, #16
 *   @0x247ac0 bne 0x247ab4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1b0>
 *   @0x247ac4 ldr r3, [r4, #0x24]
 *   @0x247ac8 str r5, [r4, #0x2c]
 *   @0x247acc cmp r6, r3
 *   @0x247ad0 blo 0x247988 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x84>
 *   @0x247ad4 b 0x247940 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x3c>
 *   @0x247ad8 ldr r9, [r0, r6, lsl #4]
 *   @0x247adc cmp r9, #0
 *   @0x247ae0 beq 0x247b00 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1fc>
 *   @0x247ae4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x247ae8 ldr r10, [r9, #0x4]
 *   @0x247aec sub r10, r10, #1
 *   @0x247af0 str r10, [r9, #0x4]
 *   @0x247af4 cmp r10, #0
 *   @0x247af8 beq 0x247b80 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x27c>
 *   @0x247afc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247b00 mov r3, #0
 *   @0x247b04 str r3, [r5]
 *   @0x247b08 b 0x2479cc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xc8>
 *   @0x247b0c ldm r7, {r2, r3}
 *   @0x247b10 stm r5, {r2, r3}
 *   @0x247b14 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247b18 ldr r3, [r7]
 *   @0x247b1c str r3, [r5]
 *   @0x247b20 ldr r3, [r7]
 *   @0x247b24 cmp r3, #0
 *   @0x247b28 beq 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247b2c bl 0xd3a54 <_Z18GetContextStackTopv>
 *   @0x247b30 ldr r1, [r7]
 *   @0x247b34 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_>
 *   @0x247b38 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247b3c ldr r3, [r7]
 *   @0x247b40 cmp r3, #0
 *   @0x247b44 str r3, [r5]
 *   @0x247b48 beq 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247b4c ldr r1, [r3, #0x8]
 *   @0x247b50 ldr r2, [r3]
 *   @0x247b54 cmp r1, #0
 *   @0x247b58 streq r5, [r3, #0x8]
 *   @0x247b5c add r2, r2, #1
 *   @0x247b60 str r2, [r3]
 *   @0x247b64 b 0x247a3c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x138>
 *   @0x247b68 ldr r3, [r7]
 *   @0x247b6c cmp r3, #0
 *   @0x247b70 ldrne r2, [r3, #0x4]
 *   @0x247b74 addne r2, r2, #1
 *   @0x247b78 strne r2, [r3, #0x4]
 *   @0x247b7c b 0x247a38 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x134>
 *   @0x247b80 ldr r0, [r9]
 *   @0x247b84 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x247b88 str r10, [r9]
 *   @0x247b8c str r10, [r9, #0x8]
 *   @0x247b90 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x247b94 ldr r10, [r9, #0x4]
 *   @0x247b98 sub r10, r10, #1
 *   @0x247b9c str r10, [r9, #0x4]
 *   @0x247ba0 cmp r10, #0
 *   @0x247ba4 beq 0x247bd4 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2d0>
 *   @0x247ba8 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247bac mov r0, r9
 *   @0x247bb0 bl 0x27d1d0 <_ZdlPv>
 *   @0x247bb4 b 0x247afc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x1f8>
 *   @0x247bb8 mov r0, r5
 *   @0x247bbc bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x247bc0 b 0x2479bc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0xb8>
 *   @0x247bc4 mov r0, r4
 *   @0x247bc8 mov r1, r6
 *   @0x247bcc bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi>
 *   @0x247bd0 b 0x247a4c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x148>
 *   @0x247bd4 ldr r0, [r9]
 *   @0x247bd8 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x247bdc str r10, [r9]
 *   @0x247be0 str r10, [r9, #0x8]
 *   @0x247be4 bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x247be8 ldr r10, [r9, #0x4]
 *   @0x247bec sub r10, r10, #1
 *   @0x247bf0 str r10, [r9, #0x4]
 *   @0x247bf4 cmp r10, #0
 *   @0x247bf8 beq 0x247c0c <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x308>
 *   @0x247bfc bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247c00 mov r0, r9
 *   @0x247c04 bl 0x27d1d0 <_ZdlPv>
 *   @0x247c08 b 0x247ba8 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2a4>
 *   @0x247c0c ldr r0, [r9]
 *   @0x247c10 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x247c14 str r10, [r9]
 *   @0x247c18 str r10, [r9, #0x8]
 *   @0x247c1c bl 0x190f2c <_Z17LOCK_RVALUE_MUTEXv>
 *   @0x247c20 ldr r10, [r9, #0x4]
 *   @0x247c24 sub r10, r10, #1
 *   @0x247c28 str r10, [r9, #0x4]
 *   @0x247c2c cmp r10, #0
 *   @0x247c30 bne 0x247c54 <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x350>
 *   @0x247c34 ldr r0, [r9]
 *   @0x247c38 bl 0xcef90 <_Z6YYFreePKv>
 *   @0x247c3c mov r0, r9
 *   @0x247c40 str r10, [r9]
 *   @0x247c44 str r10, [r9, #0x8]
 *   @0x247c48 bl 0xc09f8 <_ZN9_RefThingIPKcE3decEv>
 *   @0x247c4c mov r0, r9
 *   @0x247c50 bl 0x27d1d0 <_ZdlPv>
 *   @0x247c54 bl 0x190f30 <_Z19UNLOCK_RVALUE_MUTEXv>
 *   @0x247c58 mov r0, r9
 *   @0x247c5c bl 0x27d1d0 <_ZdlPv>
 *   @0x247c60 b 0x247bfc <_Z13SetArrayEntryP12YYObjectBasejP6RValue+0x2f8>
 *   @0x247c64 strheq r9, [lr], -r0
 *
 * ══ §30/31 CCode::CCode  0xcefc8  size 860  215 条（0xcefc8..0xcf324）
 * @func 0xcefc8 0xcf324  size 860  215 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0xcefd8→0x3eb8c0, 0xcefe4→0x544c48, 0xcf020→0x544c64, 0xcf094→0x47a168, 0xcf0ac→0x47a16c, 0xcf0dc→0x544c18, 0xcf11c→0x3eb8a8, 0xcf120→0x544c1c
 * 调用序列: 0xb65b0×2 / operator new(unsigned int)×2 / CCode::CCode(int, bool)+0x100 / CCode::CCode(int, bool)+0x128 / CCode::CCode(int, bool)+0x144
 * 字段偏移 top8: 0x10×10 / 0x4×6 / 0x8×5 / 0xc×4 / 0x6c×3 / 0x70×3 / 0x5c×3 / 0x2×3
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xcefc8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0xcefcc mov r4, r0
 *   @0xcefd0 ldr r5, [pc, #0x30c]
 *   @0xcefd4 mov r3, #0
 *   @0xcefd8 ldr r0, [pc, #0x308]
 *   @0xcefdc sub sp, sp, #8
 *   @0xcefe0 add r5, pc, r5
 *   @0xcefe4 ldr r12, [pc, #0x300]
 *   @0xcefe8 ldr r0, [r5, r0]
 *   @0xcefec str r1, [r4, #0x60]
 *   @0xceff0 add r0, r0, #8
 *   @0xceff4 strb r3, [r4, #0x68]
 *   @0xceff8 str r0, [r4]
 *   @0xceffc str r3, [r4, #0x50]
 *   @0xcf000 str r3, [r4, #0x54]
 *   @0xcf004 str r3, [r4, #0x64]
 *   @0xcf008 str r3, [r4, #0x6c]
 *   @0xcf00c str r3, [r4, #0x70]
 *   @0xcf010 ldr r3, [r5, r12]
 *   @0xcf014 ldrb r6, [r3]
 *   @0xcf018 cmp r6, #0
 *   @0xcf01c beq 0xcf0d4 <_ZN5CCodeC2Eib+0x10c>
 *   @0xcf020 ldr r3, [pc, #0x2c8]
 *   @0xcf024 ldr r0, [pc, #0x2c8]
 *   @0xcf028 ldr r12, [r5, r3]
 *   @0xcf02c add r0, pc, r0
 *   @0xcf030 mov r3, r0
 *   @0xcf034 ldr r12, [r12]
 *   @0xcf038 ldr r12, [r12, #0x1c]
 *   @0xcf03c add lr, r12, r1, lsl #3
 *   @0xcf040 ldr r1, [r12, r1, lsl #3]
 *   @0xcf044 str lr, [r4, #0x64]
 *   @0xcf048 str r0, [r4, #0x10]
 *   @0xcf04c str r1, [r4, #0x5c]
 *   @0xcf050 cmp r2, #0
 *   @0xcf054 str r3, [r4, #0x58]
 *   @0xcf058 mov r1, #0
 *   @0xcf05c mov r3, #1
 *   @0xcf060 mov r2, #44
 *   @0xcf064 strb r3, [r4, #0xc]
 *   @0xcf068 add r0, r4, #20
 *   @0xcf06c movne r3, #2
 *   @0xcf070 str r3, [r4, #0x8]
 *   @0xcf074 bl 0xb65b0 <memset@plt>
 *   @0xcf078 add r0, r4, #64
 *   @0xcf07c mov r1, #0
 *   @0xcf080 mov r2, #16
 *   @0xcf084 bl 0xb65b0 <memset@plt>
 *   @0xcf088 ldr r3, [r4, #0x60]
 *   @0xcf08c cmp r3, #0
 *   @0xcf090 blt 0xcf0c8 <_ZN5CCodeC2Eib+0x100>
 *   @0xcf094 ldr r3, [pc, #0x25c]
 *   @0xcf098 ldr r3, [r5, r3]
 *   @0xcf09c ldr r2, [r3]
 *   @0xcf0a0 cmp r2, #0
 *   @0xcf0a4 streq r4, [r3]
 *   @0xcf0a8 strne r4, [r3]
 *   @0xcf0ac ldr r3, [pc, #0x248]
 *   @0xcf0b0 streq r2, [r4, #0x4]
 *   @0xcf0b4 strne r2, [r4, #0x4]
 *   @0xcf0b8 ldr r3, [r5, r3]
 *   @0xcf0bc ldr r2, [r3]
 *   @0xcf0c0 add r2, r2, #1
 *   @0xcf0c4 str r2, [r3]
 *   @0xcf0c8 mov r0, r4
 *   @0xcf0cc add sp, sp, #8
 *   @0xcf0d0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0xcf0d4 cmp r1, #0
 *   @0xcf0d8 blt 0xcf0f0 <_ZN5CCodeC2Eib+0x128>
 *   @0xcf0dc ldr r3, [pc, #0x21c]
 *   @0xcf0e0 ldr r3, [r5, r3]
 *   @0xcf0e4 ldr r3, [r3]
 *   @0xcf0e8 cmp r1, r3
 *   @0xcf0ec blt 0xcf10c <_ZN5CCodeC2Eib+0x144>
 *   @0xcf0f0 ldr r1, [pc, #0x20c]
 *   @0xcf0f4 mov r3, #0
 *   @0xcf0f8 str r3, [r4, #0x5c]
 *   @0xcf0fc add r1, pc, r1
 *   @0xcf100 str r1, [r4, #0x10]
 *   @0xcf104 mov r3, r1
 *   @0xcf108 b 0xcf050 <_ZN5CCodeC2Eib+0x88>
 *   @0xcf10c mov r0, #28
 *   @0xcf110 str r1, [sp, #0x4]
 *   @0xcf114 str r2, [sp]
 *   @0xcf118 bl 0x27c524 <_Znwj>
 *   @0xcf11c ldr r12, [pc, #0x1e4]
 *   @0xcf120 ldr r3, [pc, #0x1e4]
 *   @0xcf124 ldr r1, [sp, #0x4]
 *   @0xcf128 ldr r7, [r5, r12]
 *   @0xcf12c ldr r2, [sp]
 *   @0xcf130 add r12, r7, #8
 *   @0xcf134 str r6, [r0, #0x10]
 *   @0xcf138 str r6, [r0, #0x14]
 *   @0xcf13c str r6, [r0, #0x18]
 *   @0xcf140 str r12, [r0]
 *   @0xcf144 str r0, [r4, #0x50]
 *   @0xcf148 ldr r3, [r5, r3]
 *   @0xcf14c ldr r3, [r3]
 *   @0xcf150 ldr r3, [r3, r1, lsl #2]
 *   @0xcf154 cmp r3, #0
 *   @0xcf158 ldrne r12, [pc, #0x1b0]
 *   @0xcf15c ldrne r12, [r5, r12]
 *   @0xcf160 ldrne r12, [r12]
 *   @0xcf164 addne r3, r12, r3
 *   @0xcf168 ldr r12, [r3]
 *   @0xcf16c cmp r12, #0
 *   @0xcf170 moveq r6, r12
 *   @0xcf174 ldrne lr, [pc, #0x194]
 *   @0xcf178 ldrne lr, [r5, lr]
 *   @0xcf17c ldrne r6, [lr]
 *   @0xcf180 addne r6, r6, r12
 *   @0xcf184 ldr r12, [pc, #0x188]
 *   @0xcf188 mov lr, #0
 *   @0xcf18c str r6, [r4, #0x5c]
 *   @0xcf190 str lr, [r4, #0x10]
 *   @0xcf194 ldr r12, [r5, r12]
 *   @0xcf198 ldr r12, [r12]
 *   @0xcf19c cmp r12, lr
 *   @0xcf1a0 beq 0xcf1cc <_ZN5CCodeC2Eib+0x204>
 *   @0xcf1a4 ldr r12, [r12, r1, lsl #2]
 *   @0xcf1a8 cmp r12, lr
 *   @0xcf1ac ldrne lr, [pc, #0x164]
 *   @0xcf1b0 ldrne lr, [r5, lr]
 *   @0xcf1b4 ldrne lr, [lr]
 *   @0xcf1b8 addne r12, lr, r12
 *   @0xcf1bc ldr r12, [r12]
 *   @0xcf1c0 cmp r12, #0
 *   @0xcf1c4 bne 0xcf2d0 <_ZN5CCodeC2Eib+0x308>
 *   @0xcf1c8 str r12, [r4, #0x10]
 *   @0xcf1cc ldr r12, [pc, #0x148]
 *   @0xcf1d0 ldr r10, [r3, #0x4]
 *   @0xcf1d4 ldr r12, [r5, r12]
 *   @0xcf1d8 ldrb r12, [r12]
 *   @0xcf1dc cmp r12, #0
 *   @0xcf1e0 beq 0xcf2a4 <_ZN5CCodeC2Eib+0x2dc>
 *   @0xcf1e4 ldrh lr, [r3, #10]
 *   @0xcf1e8 add r9, r3, #12
 *   @0xcf1ec ldrh r12, [r3, #8]
 *   @0xcf1f0 ldr r8, [r3, #0x10]
 *   @0xcf1f4 ubfx r6, lr, #0x0, #0xd
 *   @0xcf1f8 ldr r3, [r3, #0xc]
 *   @0xcf1fc str r10, [r0, #0x4]
 *   @0xcf200 str r12, [r0, #0x8]
 *   @0xcf204 add r3, r3, r9
 *   @0xcf208 str lr, [r0, #0xc]
 *   @0xcf20c str r3, [r0, #0x10]
 *   @0xcf210 str r12, [r4, #0x70]
 *   @0xcf214 str r8, [r4, #0x6c]
 *   @0xcf218 ldr r3, [pc, #0x100]
 *   @0xcf21c lsr lr, lr, #13
 *   @0xcf220 str r6, [r4, #0x74]
 *   @0xcf224 str lr, [r4, #0x78]
 *   @0xcf228 ldr r3, [r5, r3]
 *   @0xcf22c ldr r3, [r3]
 *   @0xcf230 cmp r3, #0
 *   @0xcf234 ldreq r3, [r4, #0x10]
 *   @0xcf238 beq 0xcf050 <_ZN5CCodeC2Eib+0x88>
 *   @0xcf23c ldr r3, [r3, r1, lsl #2]
 *   @0xcf240 cmp r3, #0
 *   @0xcf244 moveq r6, r3
 *   @0xcf248 moveq r8, #4
 *   @0xcf24c beq 0xcf264 <_ZN5CCodeC2Eib+0x29c>
 *   @0xcf250 ldr r1, [pc, #0xc0]
 *   @0xcf254 ldr r1, [r5, r1]
 *   @0xcf258 ldr r6, [r1]
 *   @0xcf25c add r6, r6, r3
 *   @0xcf260 add r8, r6, #4
 *   @0xcf264 mov r0, #28
 *   @0xcf268 str r2, [sp]
 *   @0xcf26c bl 0x27c524 <_Znwj>
 *   @0xcf270 ldr r1, [r6]
 *   @0xcf274 mov r3, #0
 *   @0xcf278 add r7, r7, #8
 *   @0xcf27c ldr r2, [sp]
 *   @0xcf280 lsl r1, r1, #2
 *   @0xcf284 str r3, [r0, #0x14]
 *   @0xcf288 str r3, [r0, #0x18]
 *   @0xcf28c str r7, [r0]
 *   @0xcf290 ldr r3, [r4, #0x10]
 *   @0xcf294 str r0, [r4, #0x54]
 *   @0xcf298 str r1, [r0, #0x4]
 *   @0xcf29c str r8, [r0, #0x10]
 *   @0xcf2a0 b 0xcf050 <_ZN5CCodeC2Eib+0x88>
 *   @0xcf2a4 ldrh r9, [r3, #8]
 *   @0xcf2a8 add r8, r3, #8
 *   @0xcf2ac ldrh lr, [r3, #10]
 *   @0xcf2b0 mov r6, r12
 *   @0xcf2b4 str r10, [r0, #0x4]
 *   @0xcf2b8 str r9, [r0, #0x8]
 *   @0xcf2bc str lr, [r0, #0xc]
 *   @0xcf2c0 str r8, [r0, #0x10]
 *   @0xcf2c4 str r12, [r4, #0x70]
 *   @0xcf2c8 str r12, [r4, #0x6c]
 *   @0xcf2cc b 0xcf218 <_ZN5CCodeC2Eib+0x250>
 *   @0xcf2d0 ldr lr, [pc, #0x40]
 *   @0xcf2d4 ldr lr, [r5, lr]
 *   @0xcf2d8 ldr lr, [lr]
 *   @0xcf2dc add r12, lr, r12
 *   @0xcf2e0 b 0xcf1c8 <_ZN5CCodeC2Eib+0x200>
 *   @0xcf2e4 eorseq r2, r2, r0, ror r12
 *   @0xcf2e8 .word 0xffffbed4
 *   @0xcf2ec .word 0xffffbecc
 *   @0xcf2f0 .word 0xffffbef0
 *   @0xcf2f4 eoreq pc, r5, r10, lsl #22
 *   @0xcf2f8 .word 0xffffbed0
 *   @0xcf2fc .word 0xffffbed8
 *   @0xcf300 .word 0xffffbef4
 *   @0xcf304 eoreq pc, r5, r10, lsr r10
 *   @0xcf308 .word 0xffffbedc
 *   @0xcf30c .word 0xffffbef8
 *   @0xcf310 .word 0xffffbcf4
 *   @0xcf314 .word 0xffffbefc
 *   @0xcf318 .word 0xffffbf00
 *   @0xcf31c .word 0xffffbf04
 *   @0xcf320 .word 0xffffbf08
 *
 * ══ §31/31 CalcLayerTilemapParams  0x1b19c4  size 836  209 条（0x1b19c4..0x1b1d08）
 * @func 0x1b19c4 0x1b1d08  size 836  209 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: GR_Texture_Exists(int)×2 / CBackground::GetWidth() / CBackground::GetHeight() / CBackground::GetTexture()
 * 字段偏移 top8: 0x34×5 / 0x30×5 / 0x24×4 / 0x20×3 / 0x38×3 / 0x12×3 / 0x4×2 / 0x2×2
 * VFP 指令 97 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1b19c4 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x1b19c8 subs r6, r1, #0
 *   @0x1b19cc mov r9, r2
 *   @0x1b19d0 mov r8, r3
 *   @0x1b19d4 mov r4, r0
 *   @0x1b19d8 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b19dc cmp r0, #0
 *   @0x1b19e0 streq r0, [r6]
 *   @0x1b19e4 popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b19e8 bl 0xc2d78 <_ZN11CBackground8GetWidthEv>
 *   @0x1b19ec mov r10, r0
 *   @0x1b19f0 mov r0, r4
 *   @0x1b19f4 bl 0xc2d80 <_ZN11CBackground9GetHeightEv>
 *   @0x1b19f8 mov r7, r0
 *   @0x1b19fc mov r0, r4
 *   @0x1b1a00 bl 0xc1e8c <_ZN11CBackground10GetTextureEv>
 *   @0x1b1a04 mov r5, r0
 *   @0x1b1a08 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1b1a0c cmp r0, #0
 *   @0x1b1a10 bne 0x1b1a3c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x78>
 *   @0x1b1a14 cmn r5, #1
 *   @0x1b1a18 beq 0x1b1a30 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x6c>
 *   @0x1b1a1c ldr r7, [pc, #0x2dc]
 *   @0x1b1a20 ldr r7, [pc, r7]
 *   @0x1b1a24 ldr r3, [r7]
 *   @0x1b1a28 cmp r5, r3
 *   @0x1b1a2c bhs 0x1b1af8 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x134>
 *   @0x1b1a30 mov r3, #0
 *   @0x1b1a34 str r3, [r6]
 *   @0x1b1a38 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b1a3c ldr r3, [pc, #0x2c0]
 *   @0x1b1a40 vmov s11, r7
 *   @0x1b1a44 vmov s9, r10
 *   @0x1b1a48 ldr r1, [sp, #0x20]
 *   @0x1b1a4c ldr r3, [pc, r3]
 *   @0x1b1a50 vcvt.f32.s32 s13, s11
 *   @0x1b1a54 mov r2, #1
 *   @0x1b1a58 ldr r3, [r3, #0x4]
 *   @0x1b1a5c ldr r3, [r3, r5, lsl #2]
 *   @0x1b1a60 vcvt.f32.s32 s12, s9
 *   @0x1b1a64 str r3, [r6]
 *   @0x1b1a68 vldr s15, [r4, #36]
 *   @0x1b1a6c vldr s10, [r4, #28]
 *   @0x1b1a70 vldr s11, [r4, #32]
 *   @0x1b1a74 ldr r3, [sp, #0x24]
 *   @0x1b1a78 vcvt.f32.s32 s14, s15
 *   @0x1b1a7c vldr s15, [r4, #40]
 *   @0x1b1a80 vcvt.f32.s32 s10, s10
 *   @0x1b1a84 vcvt.f32.s32 s11, s11
 *   @0x1b1a88 vdiv.f32 s14, s14, s12
 *   @0x1b1a8c vdiv.f32 s11, s11, s13
 *   @0x1b1a90 vdiv.f32 s12, s10, s12
 *   @0x1b1a94 vcvt.f32.s32 s15, s15
 *   @0x1b1a98 vstr s12, [r1]
 *   @0x1b1a9c vstr s11, [r3]
 *   @0x1b1aa0 vstr s14, [r9]
 *   @0x1b1aa4 mov r3, #1065353216
 *   @0x1b1aa8 vdiv.f32 s15, s15, s13
 *   @0x1b1aac vadd.f32 s14, s14, s14
 *   @0x1b1ab0 vstr s15, [r8]
 *   @0x1b1ab4 vldr s13, [r1]
 *   @0x1b1ab8 ldr r1, [sp, #0x28]
 *   @0x1b1abc vadd.f32 s14, s13, s14
 *   @0x1b1ac0 vadd.f32 s15, s15, s15
 *   @0x1b1ac4 vstr s14, [r1]
 *   @0x1b1ac8 ldr r1, [sp, #0x24]
 *   @0x1b1acc vldr s14, [r1]
 *   @0x1b1ad0 ldr r1, [sp, #0x2c]
 *   @0x1b1ad4 vadd.f32 s15, s14, s15
 *   @0x1b1ad8 vstr s15, [r1]
 *   @0x1b1adc ldr r1, [sp, #0x34]
 *   @0x1b1ae0 str r3, [r1]
 *   @0x1b1ae4 ldr r1, [sp, #0x30]
 *   @0x1b1ae8 str r3, [r1]
 *   @0x1b1aec ldr r3, [sp, #0x38]
 *   @0x1b1af0 strb r2, [r3]
 *   @0x1b1af4 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b1af8 ldrsh r10, [r5, #20]
 *   @0x1b1afc mov r0, r10
 *   @0x1b1b00 bl 0x173e2c <_Z17GR_Texture_Existsi>
 *   @0x1b1b04 cmp r0, #0
 *   @0x1b1b08 streq r0, [r6]
 *   @0x1b1b0c popeq {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b1b10 ldr r3, [r7, #0x4]
 *   @0x1b1b14 ldrsh r2, [r5, #8]
 *   @0x1b1b18 ldr r3, [r3, r10, lsl #2]
 *   @0x1b1b1c cmp r2, #0
 *   @0x1b1b20 str r3, [r6]
 *   @0x1b1b24 bne 0x1b1ba4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1e0>
 *   @0x1b1b28 ldrsh r2, [r5, #10]
 *   @0x1b1b2c cmp r2, #0
 *   @0x1b1b30 bne 0x1b1ba4 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1e0>
 *   @0x1b1b34 ldrh r1, [r5, #12]
 *   @0x1b1b38 ldrh r2, [r5, #16]
 *   @0x1b1b3c cmp r2, r1
 *   @0x1b1b40 sxth r0, r1
 *   @0x1b1b44 beq 0x1b1bb0 <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x1ec>
 *   @0x1b1b48 ldrh r3, [r5, #18]
 *   @0x1b1b4c ldrsh r1, [r5, #4]
 *   @0x1b1b50 sxth r2, r2
 *   @0x1b1b54 ldrsh r5, [r5, #6]
 *   @0x1b1b58 sxth r3, r3
 *   @0x1b1b5c vmov s12, r2
 *   @0x1b1b60 ldr r2, [sp, #0x30]
 *   @0x1b1b64 vmov s14, r1
 *   @0x1b1b68 ldr r1, [sp, #0x34]
 *   @0x1b1b6c vcvt.f32.s32 s12, s12
 *   @0x1b1b70 vmov s15, r3
 *   @0x1b1b74 mov r3, #0
 *   @0x1b1b78 vmov s13, r5
 *   @0x1b1b7c vcvt.f32.s32 s14, s14
 *   @0x1b1b80 vcvt.f32.s32 s13, s13
 *   @0x1b1b84 vcvt.f32.s32 s15, s15
 *   @0x1b1b88 vdiv.f32 s14, s14, s12
 *   @0x1b1b8c vdiv.f32 s15, s13, s15
 *   @0x1b1b90 vstr s14, [r2]
 *   @0x1b1b94 ldr r2, [sp, #0x38]
 *   @0x1b1b98 vstr s15, [r1]
 *   @0x1b1b9c strb r3, [r2]
 *   @0x1b1ba0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b1ba4 ldrh r2, [r5, #16]
 *   @0x1b1ba8 ldrh r3, [r5, #18]
 *   @0x1b1bac b 0x1b1b4c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x188>
 *   @0x1b1bb0 ldrh r2, [r5, #18]
 *   @0x1b1bb4 ldrsh r12, [r5, #14]
 *   @0x1b1bb8 sxth r6, r2
 *   @0x1b1bbc cmp r12, r6
 *   @0x1b1bc0 movne r3, r2
 *   @0x1b1bc4 movne r2, r1
 *   @0x1b1bc8 bne 0x1b1b4c <_Z22CalcLayerTilemapParamsP11CBackgroundPP8RTextureRfS4_S4_S4_S4_S4_S4_S4_Rb+0x188>
 *   @0x1b1bcc ldrsh r1, [r5, #4]
 *   @0x1b1bd0 vmov s9, r0
 *   @0x1b1bd4 vldr s7, [r4, #28]
 *   @0x1b1bd8 vcvt.f32.s32 s7, s7
 *   @0x1b1bdc vldr s13, [r4, #32]
 *   @0x1b1be0 vldr s8, [r4, #36]
 *   @0x1b1be4 vmov s6, r1
 *   @0x1b1be8 ldrsh r1, [r5, #6]
 *   @0x1b1bec vldr s11, [r4, #40]
 *   @0x1b1bf0 mov r2, #1
 *   @0x1b1bf4 vmov s5, r1
 *   @0x1b1bf8 ldrsh r1, [r5]
 *   @0x1b1bfc ldrsh r5, [r5, #2]
 *   @0x1b1c00 vcvt.f32.s32 s4, s9
 *   @0x1b1c04 vmov s9, r12
 *   @0x1b1c08 vmov s10, r1
 *   @0x1b1c0c ldr r1, [sp, #0x30]
 *   @0x1b1c10 vmov s12, r5
 *   @0x1b1c14 vcvt.f32.s32 s15, s9
 *   @0x1b1c18 vcvt.f32.s32 s6, s6
 *   @0x1b1c1c vcvt.f32.s32 s5, s5
 *   @0x1b1c20 vdiv.f32 s6, s6, s4
 *   @0x1b1c24 vdiv.f32 s15, s5, s15
 *   @0x1b1c28 vstr s6, [r1]
 *   @0x1b1c2c ldr r1, [sp, #0x34]
 *   @0x1b1c30 vstr s15, [r1]
 *   @0x1b1c34 vldr s9, [r3, #8]
 *   @0x1b1c38 vmul.f32 s9, s7, s9
 *   @0x1b1c3c ldr r1, [sp, #0x30]
 *   @0x1b1c40 vldr s15, [r1]
 *   @0x1b1c44 ldr r1, [sp, #0x20]
 *   @0x1b1c48 vmul.f32 s15, s9, s15
 *   @0x1b1c4c vcvt.f32.s32 s13, s13
 *   @0x1b1c50 vstr s15, [r1]
 *   @0x1b1c54 vldr s14, [r3, #12]
 *   @0x1b1c58 ldr r1, [sp, #0x34]
 *   @0x1b1c5c vldr s15, [r1]
 *   @0x1b1c60 ldr r1, [sp, #0x24]
 *   @0x1b1c64 vmul.f32 s14, s13, s14
 *   @0x1b1c68 vmul.f32 s15, s14, s15
 *   @0x1b1c6c vcvt.f32.s32 s8, s8
 *   @0x1b1c70 vstr s15, [r1]
 *   @0x1b1c74 vldr s13, [r3, #8]
 *   @0x1b1c78 ldr r1, [sp, #0x30]
 *   @0x1b1c7c vldr s14, [r1]
 *   @0x1b1c80 vldr s9, [r3, #12]
 *   @0x1b1c84 ldr r1, [sp, #0x34]
 *   @0x1b1c88 vldr s15, [r1]
 *   @0x1b1c8c ldr r1, [sp, #0x20]
 *   @0x1b1c90 vmul.f32 s8, s8, s13
 *   @0x1b1c94 vmul.f32 s14, s8, s14
 *   @0x1b1c98 vcvt.f32.s32 s11, s11
 *   @0x1b1c9c vcvt.f32.s32 s10, s10
 *   @0x1b1ca0 vmul.f32 s11, s11, s9
 *   @0x1b1ca4 vmov.f32 s9, s14
 *   @0x1b1ca8 vmla.f32 s9, s13, s10
 *   @0x1b1cac vmul.f32 s15, s11, s15
 *   @0x1b1cb0 vstr s9, [r9]
 *   @0x1b1cb4 vldr s13, [r3, #12]
 *   @0x1b1cb8 ldr r3, [sp, #0x28]
 *   @0x1b1cbc vcvt.f32.s32 s12, s12
 *   @0x1b1cc0 vmov.f32 s11, s15
 *   @0x1b1cc4 vmla.f32 s11, s12, s13
 *   @0x1b1cc8 vadd.f32 s14, s14, s14
 *   @0x1b1ccc vstr s11, [r8]
 *   @0x1b1cd0 vldr s13, [r1]
 *   @0x1b1cd4 vadd.f32 s15, s15, s15
 *   @0x1b1cd8 vadd.f32 s14, s13, s14
 *   @0x1b1cdc vstr s14, [r3]
 *   @0x1b1ce0 ldr r1, [sp, #0x24]
 *   @0x1b1ce4 vldr s14, [r1]
 *   @0x1b1ce8 vadd.f32 s15, s14, s15
 *   @0x1b1cec ldr r1, [sp, #0x38]
 *   @0x1b1cf0 ldr r3, [sp, #0x2c]
 *   @0x1b1cf4 vstr s15, [r3]
 *   @0x1b1cf8 strb r2, [r1]
 *   @0x1b1cfc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x1b1d00 .word 0x0023befc
 *   @0x1b1d04 .word 0x0023bed0
 */
