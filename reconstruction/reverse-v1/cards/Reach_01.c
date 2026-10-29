/* cally 逆向卡：Reach_01 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 7 个函数｜锚点 7000 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/7 json_tokener_parse_ex  0x27f048  size 5908  1477 条（0x27f048..0x28075c）
 * @func 0x27f048 0x28075c  size 5908  1477 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: utf8_get_charW×24 / printbuf_memappend×22 / utf8_char_sizeW×20 / 0xb65bc×10 / printbuf_reset×5 / 0xb6d18×3 / json_object_get×2 / anon_27ee08+0xbc×2
 * 字段偏移 top8: 0x4×106 / 0x24×89 / 0x8×62 / 0x28×22 / 0x18×21 / 0x14×19 / 0x30×16 / 0x10×9
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x27f048 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x27f04c sub sp, sp, #60
 *   @0x27f050 mov r3, #0
 *   @0x27f054 mov r4, r0
 *   @0x27f058 str r3, [r4, #0x14]
 *   @0x27f05c mov r0, r3
 *   @0x27f060 str r3, [r4, #0x18]
 *   @0x27f064 mov r6, r2
 *   @0x27f068 str r3, [sp, #0x4]
 *   @0x27f06c mov r3, #1
 *   @0x27f070 str r3, [sp, #0x24]
 *   @0x27f074 mov r5, r1
 *   @0x27f078 ldr r3, [pc, #0xfec]
 *   @0x27f07c ldr r2, [pc, #0xfec]
 *   @0x27f080 add r3, pc, r3
 *   @0x27f084 str r3, [sp, #0x10]
 *   @0x27f088 ldr r3, [pc, #0xfe4]
 *   @0x27f08c add r2, pc, r2
 *   @0x27f090 str r2, [sp, #0x8]
 *   @0x27f094 add r3, pc, r3
 *   @0x27f098 str r3, [sp, #0xc]
 *   @0x27f09c ldr r3, [pc, #0xfd4]
 *   @0x27f0a0 add r3, pc, r3
 *   @0x27f0a4 str r3, [sp, #0x18]
 *   @0x27f0a8 ldr r3, [pc, #0xfcc]
 *   @0x27f0ac add r3, pc, r3
 *   @0x27f0b0 str r3, [sp, #0x14]
 *   @0x27f0b4 ldr r3, [pc, #0xfc4]
 *   @0x27f0b8 add r3, pc, r3
 *   @0x27f0bc str r3, [sp, #0x1c]
 *   @0x27f0c0 cmp r6, r0
 *   @0x27f0c4 bne 0x27f1e0 <json_tokener_parse_ex+0x198>
 *   @0x27f0c8 ldr r3, [r4, #0x8]
 *   @0x27f0cc cmp r3, #0
 *   @0x27f0d0 bne 0x27f0ec <json_tokener_parse_ex+0xa4>
 *   @0x27f0d4 ldr r3, [r4, #0x24]
 *   @0x27f0d8 cmp r3, #0
 *   @0x27f0dc bne 0x27f0ec <json_tokener_parse_ex+0xa4>
 *   @0x27f0e0 ldr r2, [r4, #0x28]
 *   @0x27f0e4 cmp r2, #2
 *   @0x27f0e8 beq 0x27f0f0 <json_tokener_parse_ex+0xa8>
 *   @0x27f0ec mov r3, #1
 *   @0x27f0f0 str r3, [r4, #0x18]
 *   @0x27f0f4 ldr r8, [sp, #0x24]
 *   @0x27f0f8 cmp r8, #0
 *   @0x27f0fc beq 0x27f1a8 <json_tokener_parse_ex+0x160>
 *   @0x27f100 ldr r3, [r4, #0x18]
 *   @0x27f104 cmp r3, #0
 *   @0x27f108 movne r0, #0
 *   @0x27f10c bne 0x27f124 <json_tokener_parse_ex+0xdc>
 *   @0x27f110 ldr r3, [r4, #0x8]
 *   @0x27f114 add r3, r3, r3, lsl #2
 *   @0x27f118 add r4, r4, r3, lsl #2
 *   @0x27f11c ldr r0, [r4, #0x30]
 *   @0x27f120 bl 0x27e7b4 <json_object_get>
 *   @0x27f124 add sp, sp, #60
 *   @0x27f128 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27f12c ldr r8, [sp, #0x24]
 *   @0x27f130 cmp r8, #98
 *   @0x27f134 beq 0x2804a4 <json_tokener_parse_ex+0x145c>
 *   @0x27f138 ble 0x27fe88 <json_tokener_parse_ex+0xe40>
 *   @0x27f13c cmp r8, #114
 *   @0x27f140 beq 0x2804d8 <json_tokener_parse_ex+0x1490>
 *   @0x27f144 ble 0x280448 <json_tokener_parse_ex+0x1400>
 *   @0x27f148 cmp r8, #116
 *   @0x27f14c beq 0x2804fc <json_tokener_parse_ex+0x14b4>
 *   @0x27f150 cmp r8, #117
 *   @0x27f154 bne 0x27faec <json_tokener_parse_ex+0xaa4>
 *   @0x27f158 add r3, r1, r3
 *   @0x27f15c mov r2, #0
 *   @0x27f160 mov r0, #10
 *   @0x27f164 str r2, [r4, #0x1c]
 *   @0x27f168 add r3, r4, r3, lsl #2
 *   @0x27f16c str r2, [r4, #0x10]
 *   @0x27f170 str r0, [r3, #0x24]
 *   @0x27f174 mov r0, r5
 *   @0x27f178 bl 0x27eefc <utf8_get_charW>
 *   @0x27f17c bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f180 ldr r7, [r4, #0x14]
 *   @0x27f184 add r5, r5, r0
 *   @0x27f188 mov r0, r5
 *   @0x27f18c bl 0x27eefc <utf8_get_charW>
 *   @0x27f190 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f194 ldr r3, [sp, #0x24]
 *   @0x27f198 cmp r3, #0
 *   @0x27f19c add r0, r7, r0
 *   @0x27f1a0 str r0, [r4, #0x14]
 *   @0x27f1a4 bne 0x27f0c0 <json_tokener_parse_ex+0x78>
 *   @0x27f1a8 ldr r3, [r4, #0x8]
 *   @0x27f1ac add r3, r3, r3, lsl #2
 *   @0x27f1b0 add r3, r4, r3, lsl #2
 *   @0x27f1b4 ldr r2, [r3, #0x24]
 *   @0x27f1b8 cmp r2, #2
 *   @0x27f1bc beq 0x27f100 <json_tokener_parse_ex+0xb8>
 *   @0x27f1c0 ldr r3, [r3, #0x28]
 *   @0x27f1c4 cmp r3, #2
 *   @0x27f1c8 beq 0x27f100 <json_tokener_parse_ex+0xb8>
 *   @0x27f1cc mov r3, #3
 *   @0x27f1d0 mov r0, #0
 *   @0x27f1d4 str r3, [r4, #0x18]
 *   @0x27f1d8 add sp, sp, #60
 *   @0x27f1dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27f1e0 mov r0, r5
 *   @0x27f1e4 mov r9, #0
 *   @0x27f1e8 bl 0x27eefc <utf8_get_charW>
 *   @0x27f1ec ldr r3, [r4, #0x8]
 *   @0x27f1f0 lsl r1, r3, #2
 *   @0x27f1f4 add r2, r1, r3
 *   @0x27f1f8 add r2, r4, r2, lsl #2
 *   @0x27f1fc ldr r2, [r2, #0x24]
 *   @0x27f200 str r0, [sp, #0x24]
 *   @0x27f204 cmp r2, #21
 *   @0x27f208 addls pc, pc, r2, lsl #2
 *   @0x27f20c b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f210 b 0x27f298 <json_tokener_parse_ex+0x250>
 *   @0x27f214 b 0x27f33c <json_tokener_parse_ex+0x2f4>
 *   @0x27f218 b 0x27f5e4 <json_tokener_parse_ex+0x59c>
 *   @0x27f21c b 0x27f4b8 <json_tokener_parse_ex+0x470>
 *   @0x27f220 b 0x27f580 <json_tokener_parse_ex+0x538>
 *   @0x27f224 b 0x27f62c <json_tokener_parse_ex+0x5e4>
 *   @0x27f228 b 0x27f6e4 <json_tokener_parse_ex+0x69c>
 *   @0x27f22c b 0x27f754 <json_tokener_parse_ex+0x70c>
 *   @0x27f230 b 0x27f7b4 <json_tokener_parse_ex+0x76c>
 *   @0x27f234 b 0x27f12c <json_tokener_parse_ex+0xe4>
 *   @0x27f238 b 0x27fa44 <json_tokener_parse_ex+0x9fc>
 *   @0x27f23c b 0x27faf8 <json_tokener_parse_ex+0xab0>
 *   @0x27f240 b 0x27fba4 <json_tokener_parse_ex+0xb5c>
 *   @0x27f244 b 0x27f838 <json_tokener_parse_ex+0x7f0>
 *   @0x27f248 b 0x27f888 <json_tokener_parse_ex+0x840>
 *   @0x27f24c b 0x27f8c0 <json_tokener_parse_ex+0x878>
 *   @0x27f250 b 0x27f8f0 <json_tokener_parse_ex+0x8a8>
 *   @0x27f254 b 0x27f92c <json_tokener_parse_ex+0x8e4>
 *   @0x27f258 b 0x27f9b0 <json_tokener_parse_ex+0x968>
 *   @0x27f25c b 0x27f9d8 <json_tokener_parse_ex+0x990>
 *   @0x27f260 b 0x27f9f0 <json_tokener_parse_ex+0x9a8>
 *   @0x27f264 b 0x27f268 <json_tokener_parse_ex+0x220>
 *   @0x27f268 ldr r8, [sp, #0x24]
 *   @0x27f26c cmp r8, #125
 *   @0x27f270 beq 0x27fd3c <json_tokener_parse_ex+0xcf4>
 *   @0x27f274 cmp r8, #44
 *   @0x27f278 bne 0x280664 <json_tokener_parse_ex+0x161c>
 *   @0x27f27c add r3, r1, r3
 *   @0x27f280 mov r0, #16
 *   @0x27f284 mov r2, #0
 *   @0x27f288 add r3, r4, r3, lsl #2
 *   @0x27f28c str r0, [r3, #0x28]
 *   @0x27f290 str r2, [r3, #0x24]
 *   @0x27f294 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f298 ldr r0, [sp, #0x24]
 *   @0x27f29c cmp r0, #127
 *   @0x27f2a0 bgt 0x27f328 <json_tokener_parse_ex+0x2e0>
 *   @0x27f2a4 cmn r0, #1
 *   @0x27f2a8 beq 0x27f328 <json_tokener_parse_ex+0x2e0>
 *   @0x27f2ac ldr r8, [pc, #0xdd0]
 *   @0x27f2b0 ldr r8, [pc, r8]
 *   @0x27f2b4 ldr r3, [r8]
 *   @0x27f2b8 uxtab r3, r3, r0
 *   @0x27f2bc ldrb r3, [r3, #0x1]
 *   @0x27f2c0 tst r3, #8
 *   @0x27f2c4 beq 0x2806e8 <json_tokener_parse_ex+0x16a0>
 *   @0x27f2c8 mov r0, r5
 *   @0x27f2cc bl 0x27eefc <utf8_get_charW>
 *   @0x27f2d0 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f2d4 ldr r7, [r4, #0x14]
 *   @0x27f2d8 add r5, r5, r0
 *   @0x27f2dc mov r0, r5
 *   @0x27f2e0 bl 0x27eefc <utf8_get_charW>
 *   @0x27f2e4 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f2e8 ldr r3, [sp, #0x24]
 *   @0x27f2ec cmp r3, #0
 *   @0x27f2f0 add r3, r7, r0
 *   @0x27f2f4 mov r0, r5
 *   @0x27f2f8 str r3, [r4, #0x14]
 *   @0x27f2fc beq 0x27f1a8 <json_tokener_parse_ex+0x160>
 *   @0x27f300 cmp r6, r3
 *   @0x27f304 beq 0x27fe58 <json_tokener_parse_ex+0xe10>
 *   @0x27f308 bl 0x27eefc <utf8_get_charW>
 *   @0x27f30c cmp r0, #127
 *   @0x27f310 str r0, [sp, #0x24]
 *   @0x27f314 bgt 0x27f320 <json_tokener_parse_ex+0x2d8>
 *   @0x27f318 cmn r0, #1
 *   @0x27f31c bne 0x27f2b4 <json_tokener_parse_ex+0x26c>
 *   @0x27f320 ldr r3, [r4, #0x8]
 *   @0x27f324 lsl r1, r3, #2
 *   @0x27f328 add r0, r1, r3
 *   @0x27f32c add r0, r4, r0, lsl #2
 *   @0x27f330 ldr r2, [r0, #0x28]
 *   @0x27f334 str r2, [r0, #0x24]
 *   @0x27f338 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27f33c ldr r8, [sp, #0x24]
 *   @0x27f340 sub r2, r8, #34
 *   @0x27f344 cmp r2, #89
 *   @0x27f348 addls pc, pc, r2, lsl #2
 *   @0x27f34c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f350 b 0x280168 <json_tokener_parse_ex+0x1120>
 *   @0x27f354 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f358 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f35c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f360 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f364 b 0x280168 <json_tokener_parse_ex+0x1120>
 *   @0x27f368 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f36c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f370 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f374 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f378 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f37c b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f380 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f384 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f388 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f38c b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f390 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f394 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f398 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f39c b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f3a0 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f3a4 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f3a8 b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f3ac b 0x280134 <json_tokener_parse_ex+0x10ec>
 *   @0x27f3b0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3b4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3b8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3bc b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3c0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3c4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3c8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3cc b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3d0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3d4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3d8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3dc b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3e0 b 0x280128 <json_tokener_parse_ex+0x10e0>
 *   @0x27f3e4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3e8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3ec b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3f0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3f4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3f8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f3fc b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f400 b 0x2800f4 <json_tokener_parse_ex+0x10ac>
 *   @0x27f404 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f408 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f40c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f410 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f414 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f418 b 0x280128 <json_tokener_parse_ex+0x10e0>
 *   @0x27f41c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f420 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f424 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f428 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f42c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f430 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f434 b 0x2801b0 <json_tokener_parse_ex+0x1168>
 *   @0x27f438 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f43c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f440 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f444 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f448 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f44c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f450 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f454 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f458 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f45c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f460 b 0x280128 <json_tokener_parse_ex+0x10e0>
 *   @0x27f464 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f468 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f46c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f470 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f474 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f478 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f47c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f480 b 0x2800f4 <json_tokener_parse_ex+0x10ac>
 *   @0x27f484 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f488 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f48c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f490 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f494 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f498 b 0x280128 <json_tokener_parse_ex+0x10e0>
 *   @0x27f49c b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4a0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4a4 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4a8 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4ac b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4b0 b 0x280204 <json_tokener_parse_ex+0x11bc>
 *   @0x27f4b4 b 0x28018c <json_tokener_parse_ex+0x1144>
 *   @0x27f4b8 ldr r3, [r4, #0x4]
 *   @0x27f4bc ldr r0, [sp, #0x24]
 *   @0x27f4c0 ldmib r3, {r3, r7}
 *   @0x27f4c4 rsb r7, r3, r7
 *   @0x27f4c8 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f4cc cmp r7, r0
 *   @0x27f4d0 ble 0x27fd58 <json_tokener_parse_ex+0xd10>
 *   @0x27f4d4 ldr r3, [r4, #0x4]
 *   @0x27f4d8 add r7, sp, #56
 *   @0x27f4dc ldr r0, [r7, #-0x14]!
 *   @0x27f4e0 ldm r3, {r3, r8}
 *   @0x27f4e4 add r8, r8, r3
 *   @0x27f4e8 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f4ec mov r1, r7
 *   @0x27f4f0 mov r2, r0
 *   @0x27f4f4 mov r0, r8
 *   @0x27f4f8 bl 0xb65bc <memcpy@plt>
 *   @0x27f4fc ldr r7, [r4, #0x4]
 *   @0x27f500 ldr r0, [sp, #0x24]
 *   @0x27f504 ldr r8, [r7, #0x4]
 *   @0x27f508 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f50c ldr r3, [r4, #0x4]
 *   @0x27f510 ldr r2, [r3]
 *   @0x27f514 add r0, r8, r0
 *   @0x27f518 str r0, [r7, #0x4]
 *   @0x27f51c ldr r3, [r3, #0x4]
 *   @0x27f520 strb r9, [r2, r3]
 *   @0x27f524 ldr r8, [r4, #0x10]
 *   @0x27f528 ldr r3, [r4, #0x4]
 *   @0x27f52c add r7, r8, #1
 *   @0x27f530 ldr r0, [sp, #0xc]
 *   @0x27f534 cmp r7, #3
 *   @0x27f538 ldr r1, [r3]
 *   @0x27f53c movle r2, r7
 *   @0x27f540 movgt r2, #4
 *   @0x27f544 bl 0xb6d18 <strncasecmp@plt>
 *   @0x27f548 cmp r0, #0
 *   @0x27f54c bne 0x280600 <json_tokener_parse_ex+0x15b8>
 *   @0x27f550 cmp r8, #4
 *   @0x27f554 bne 0x2805a0 <json_tokener_parse_ex+0x1558>
 *   @0x27f558 ldr r3, [r4, #0x8]
 *   @0x27f55c mov r7, #2
 *   @0x27f560 mov r2, r0
 *   @0x27f564 lsl r1, r3, r7
 *   @0x27f568 add r12, r1, r3
 *   @0x27f56c add r12, r4, r12, lsl #2
 *   @0x27f570 str r0, [r12, #0x30]
 *   @0x27f574 str r0, [r12, #0x24]
 *   @0x27f578 str r7, [r12, #0x28]
 *   @0x27f57c b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27f580 ldr r8, [sp, #0x24]
 *   @0x27f584 cmp r8, #42
 *   @0x27f588 beq 0x27ffa4 <json_tokener_parse_ex+0xf5c>
 *   @0x27f58c cmp r8, #47
 *   @0x27f590 bne 0x280688 <json_tokener_parse_ex+0x1640>
 *   @0x27f594 add r3, r1, r3
 *   @0x27f598 mov r2, #6
 *   @0x27f59c add r3, r4, r3, lsl #2
 *   @0x27f5a0 str r2, [r3, #0x24]
 *   @0x27f5a4 ldr r0, [r4, #0x4]
 *   @0x27f5a8 ldr r3, [r0, #0x4]
 *   @0x27f5ac ldr r2, [r0, #0x8]
 *   @0x27f5b0 rsb r2, r3, r2
 *   @0x27f5b4 cmp r2, #1
 *   @0x27f5b8 ble 0x27ffd8 <json_tokener_parse_ex+0xf90>
 *   @0x27f5bc ldr r2, [r0]
 *   @0x27f5c0 mov r0, #0
 *   @0x27f5c4 ldrb r1, [sp, #0x24]
 *   @0x27f5c8 strb r1, [r2, r3]
 *   @0x27f5cc ldr r3, [r4, #0x4]
 *   @0x27f5d0 ldm r3, {r1, r2}
 *   @0x27f5d4 add r2, r2, #1
 *   @0x27f5d8 str r2, [r3, #0x4]
 *   @0x27f5dc strb r0, [r1, r2]
 *   @0x27f5e0 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f5e4 cmp r3, #0
 *   @0x27f5e8 beq 0x27f0f4 <json_tokener_parse_ex+0xac>
 *   @0x27f5ec add r3, r1, r3
 *   @0x27f5f0 add r3, r4, r3, lsl #2
 *   @0x27f5f4 ldr r0, [r3, #0x30]
 *   @0x27f5f8 bl 0x27e7b4 <json_object_get>
 *   @0x27f5fc ldr r1, [r4, #0x8]
 *   @0x27f600 str r0, [sp, #0x4]
 *   @0x27f604 mov r0, r4
 *   @0x27f608 bl 0x27eec4 <json_object_array_get_idx+0xc4>
 *   @0x27f60c ldr r3, [r4, #0x8]
 *   @0x27f610 sub r3, r3, #1
 *   @0x27f614 str r3, [r4, #0x8]
 *   @0x27f618 lsl r1, r3, #2
 *   @0x27f61c add r2, r1, r3
 *   @0x27f620 add r2, r4, r2, lsl #2
 *   @0x27f624 ldr r2, [r2, #0x24]
 *   @0x27f628 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27f62c ldr r3, [sp, #0x24]
 *   @0x27f630 mov r7, r5
 *   @0x27f634 cmp r3, #42
 *   @0x27f638 bne 0x27f658 <json_tokener_parse_ex+0x610>
 *   @0x27f63c b 0x27ff5c <json_tokener_parse_ex+0xf14>
 *   @0x27f640 cmp r6, r3
 *   @0x27f644 beq 0x27fd0c <json_tokener_parse_ex+0xcc4>
 *   @0x27f648 bl 0x27eefc <utf8_get_charW>
 *   @0x27f64c cmp r0, #42
 *   @0x27f650 str r0, [sp, #0x24]
 *   @0x27f654 beq 0x27ff5c <json_tokener_parse_ex+0xf14>
 *   @0x27f658 mov r0, r7
 *   @0x27f65c bl 0x27eefc <utf8_get_charW>
 *   @0x27f660 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f664 ldr r8, [r4, #0x14]
 *   @0x27f668 add r7, r7, r0
 *   @0x27f66c mov r0, r7
 *   @0x27f670 bl 0x27eefc <utf8_get_charW>
 *   @0x27f674 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f678 ldr r3, [sp, #0x24]
 *   @0x27f67c cmp r3, #0
 *   @0x27f680 add r3, r8, r0
 *   @0x27f684 mov r0, r7
 *   @0x27f688 str r3, [r4, #0x14]
 *   @0x27f68c bne 0x27f640 <json_tokener_parse_ex+0x5f8>
 *   @0x27f690 ldr r0, [r4, #0x4]
 *   @0x27f694 rsb r7, r5, r7
 *   @0x27f698 ldr r3, [r0, #0x4]
 *   @0x27f69c ldr r2, [r0, #0x8]
 *   @0x27f6a0 rsb r2, r3, r2
 *   @0x27f6a4 cmp r2, r7
 *   @0x27f6a8 ble 0x27fcf8 <json_tokener_parse_ex+0xcb0>
 *   @0x27f6ac ldr r0, [r0]
 *   @0x27f6b0 mov r2, r7
 *   @0x27f6b4 mov r1, r5
 *   @0x27f6b8 add r0, r0, r3
 *   @0x27f6bc bl 0xb65bc <memcpy@plt>
 *   @0x27f6c0 ldr r3, [r4, #0x4]
 *   @0x27f6c4 mov r1, #0
 *   @0x27f6c8 ldr r0, [r3, #0x4]
 *   @0x27f6cc ldr r2, [r3]
 *   @0x27f6d0 add r7, r7, r0
 *   @0x27f6d4 str r7, [r3, #0x4]
 *   @0x27f6d8 strb r1, [r2, r7]
 *   @0x27f6dc ldr r8, [sp, #0x24]
 *   @0x27f6e0 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x27f6e4 ldr r3, [sp, #0x24]
 *   @0x27f6e8 mov r9, r5
 *   @0x27f6ec cmp r3, #10
 *   @0x27f6f0 moveq r8, #0
 *   @0x27f6f4 beq 0x27fefc <json_tokener_parse_ex+0xeb4>
 *   @0x27f6f8 mov r7, r5
 *   @0x27f6fc b 0x27f718 <json_tokener_parse_ex+0x6d0>
 *   @0x27f700 cmp r6, r3
 *   @0x27f704 beq 0x27fd0c <json_tokener_parse_ex+0xcc4>
 *   @0x27f708 bl 0x27eefc <utf8_get_charW>
 *   @0x27f70c cmp r0, #10
 *   @0x27f710 str r0, [sp, #0x24]
 *   @0x27f714 beq 0x27fef4 <json_tokener_parse_ex+0xeac>
 *   @0x27f718 mov r0, r7
 *   @0x27f71c bl 0x27eefc <utf8_get_charW>
 *   @0x27f720 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f724 ldr r8, [r4, #0x14]
 *   @0x27f728 add r7, r7, r0
 *   @0x27f72c mov r0, r7
 *   @0x27f730 bl 0x27eefc <utf8_get_charW>
 *   @0x27f734 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f738 ldr r3, [sp, #0x24]
 *   @0x27f73c cmp r3, #0
 *   @0x27f740 add r3, r8, r0
 *   @0x27f744 mov r0, r7
 *   @0x27f748 str r3, [r4, #0x14]
 *   @0x27f74c bne 0x27f700 <json_tokener_parse_ex+0x6b8>
 *   @0x27f750 b 0x27f690 <json_tokener_parse_ex+0x648>
 *   @0x27f754 ldr r0, [r4, #0x4]
 *   @0x27f758 ldr r3, [r0, #0x4]
 *   @0x27f75c ldr r2, [r0, #0x8]
 *   @0x27f760 rsb r2, r3, r2
 *   @0x27f764 cmp r2, #1
 *   @0x27f768 ble 0x27ffc8 <json_tokener_parse_ex+0xf80>
 *   @0x27f76c ldr r2, [r0]
 *   @0x27f770 mov r0, #0
 *   @0x27f774 ldrb r1, [sp, #0x24]
 *   @0x27f778 strb r1, [r2, r3]
 *   @0x27f77c ldr r3, [r4, #0x4]
 *   @0x27f780 ldm r3, {r1, r2}
 *   @0x27f784 add r2, r2, #1
 *   @0x27f788 str r2, [r3, #0x4]
 *   @0x27f78c strb r0, [r1, r2]
 *   @0x27f790 ldr r3, [sp, #0x24]
 *   @0x27f794 cmp r3, #47
 *   @0x27f798 ldr r3, [r4, #0x8]
 *   @0x27f79c moveq r2, #0
 *   @0x27f7a0 movne r2, #5
 *   @0x27f7a4 add r3, r3, r3, lsl #2
 *   @0x27f7a8 add r3, r4, r3, lsl #2
 *   @0x27f7ac str r2, [r3, #0x24]
 *   @0x27f7b0 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f7b4 ldr r3, [sp, #0x24]
 *   @0x27f7b8 mov r9, r5
 *   @0x27f7bc ldrb r2, [r4, #0x20]
 *   @0x27f7c0 cmp r2, r3
 *   @0x27f7c4 beq 0x2805b8 <json_tokener_parse_ex+0x1570>
 *   @0x27f7c8 cmp r3, #92
 *   @0x27f7cc movne r7, r5
 *   @0x27f7d0 bne 0x27f7fc <json_tokener_parse_ex+0x7b4>
 *   @0x27f7d4 b 0x2805c0 <json_tokener_parse_ex+0x1578>
 *   @0x27f7d8 cmp r6, r3
 *   @0x27f7dc beq 0x27fd0c <json_tokener_parse_ex+0xcc4>
 *   @0x27f7e0 bl 0x27eefc <utf8_get_charW>
 *   @0x27f7e4 ldrb r3, [r4, #0x20]
 *   @0x27f7e8 cmp r3, r0
 *   @0x27f7ec str r0, [sp, #0x24]
 *   @0x27f7f0 beq 0x280210 <json_tokener_parse_ex+0x11c8>
 *   @0x27f7f4 cmp r0, #92
 *   @0x27f7f8 beq 0x280314 <json_tokener_parse_ex+0x12cc>
 *   @0x27f7fc mov r0, r7
 *   @0x27f800 bl 0x27eefc <utf8_get_charW>
 *   @0x27f804 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f808 ldr r8, [r4, #0x14]
 *   @0x27f80c add r7, r7, r0
 *   @0x27f810 mov r0, r7
 *   @0x27f814 bl 0x27eefc <utf8_get_charW>
 *   @0x27f818 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f81c ldr r3, [sp, #0x24]
 *   @0x27f820 cmp r3, #0
 *   @0x27f824 add r3, r8, r0
 *   @0x27f828 mov r0, r7
 *   @0x27f82c str r3, [r4, #0x14]
 *   @0x27f830 bne 0x27f7d8 <json_tokener_parse_ex+0x790>
 *   @0x27f834 b 0x27f690 <json_tokener_parse_ex+0x648>
 *   @0x27f838 ldr r8, [sp, #0x24]
 *   @0x27f83c cmp r8, #93
 *   @0x27f840 beq 0x27fd3c <json_tokener_parse_ex+0xcf4>
 *   @0x27f844 cmp r3, #30
 *   @0x27f848 bgt 0x2805f4 <json_tokener_parse_ex+0x15ac>
 *   @0x27f84c add r2, r1, r3
 *   @0x27f850 add r3, r3, #1
 *   @0x27f854 mov r12, #14
 *   @0x27f858 add r2, r4, r2, lsl #2
 *   @0x27f85c mov r1, r3
 *   @0x27f860 mov r0, r4
 *   @0x27f864 str r12, [r2, #0x24]
 *   @0x27f868 str r3, [r4, #0x8]
 *   @0x27f86c bl 0x27eec4 <json_object_array_get_idx+0xc4>
 *   @0x27f870 ldr r3, [r4, #0x8]
 *   @0x27f874 lsl r1, r3, #2
 *   @0x27f878 add r2, r1, r3
 *   @0x27f87c add r2, r4, r2, lsl #2
 *   @0x27f880 ldr r2, [r2, #0x24]
 *   @0x27f884 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27f888 add r3, r1, r3
 *   @0x27f88c ldr r1, [sp, #0x4]
 *   @0x27f890 add r3, r4, r3, lsl #2
 *   @0x27f894 ldr r0, [r3, #0x30]
 *   @0x27f898 bl 0x27edf0 <json_object_array_add>
 *   @0x27f89c ldr r3, [r4, #0x8]
 *   @0x27f8a0 mov r12, #15
 *   @0x27f8a4 mov r2, #0
 *   @0x27f8a8 lsl r1, r3, #2
 *   @0x27f8ac add r0, r1, r3
 *   @0x27f8b0 add r0, r4, r0, lsl #2
 *   @0x27f8b4 str r9, [r0, #0x24]
 *   @0x27f8b8 str r12, [r0, #0x28]
 *   @0x27f8bc b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27f8c0 ldr r8, [sp, #0x24]
 *   @0x27f8c4 cmp r8, #93
 *   @0x27f8c8 beq 0x27fd3c <json_tokener_parse_ex+0xcf4>
 *   @0x27f8cc cmp r8, #44
 *   @0x27f8d0 bne 0x2806a0 <json_tokener_parse_ex+0x1658>
 *   @0x27f8d4 add r3, r1, r3
 *   @0x27f8d8 mov r0, #13
 *   @0x27f8dc mov r2, #0
 *   @0x27f8e0 add r3, r4, r3, lsl #2
 *   @0x27f8e4 str r0, [r3, #0x28]
 *   @0x27f8e8 str r2, [r3, #0x24]
 *   @0x27f8ec b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f8f0 ldr r8, [sp, #0x24]
 *   @0x27f8f4 cmp r8, #125
 *   @0x27f8f8 beq 0x27fd3c <json_tokener_parse_ex+0xcf4>
 *   @0x27f8fc cmp r8, #34
 *   @0x27f900 cmpne r8, #39
 *   @0x27f904 bne 0x280694 <json_tokener_parse_ex+0x164c>
 *   @0x27f908 strb r8, [r4, #0x20]
 *   @0x27f90c ldr r0, [r4, #0x4]
 *   @0x27f910 bl 0x280e9c <printbuf_reset>
 *   @0x27f914 ldr r3, [r4, #0x8]
 *   @0x27f918 mov r2, #17
 *   @0x27f91c add r3, r3, r3, lsl #2
 *   @0x27f920 add r3, r4, r3, lsl #2
 *   @0x27f924 str r2, [r3, #0x24]
 *   @0x27f928 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f92c ldr r3, [sp, #0x24]
 *   @0x27f930 mov r9, r5
 *   @0x27f934 ldrb r2, [r4, #0x20]
 *   @0x27f938 cmp r2, r3
 *   @0x27f93c beq 0x2805d0 <json_tokener_parse_ex+0x1588>
 *   @0x27f940 cmp r3, #92
 *   @0x27f944 movne r7, r5
 *   @0x27f948 bne 0x27f974 <json_tokener_parse_ex+0x92c>
 *   @0x27f94c b 0x2805c8 <json_tokener_parse_ex+0x1580>
 *   @0x27f950 cmp r6, r3
 *   @0x27f954 beq 0x27fd0c <json_tokener_parse_ex+0xcc4>
 *   @0x27f958 bl 0x27eefc <utf8_get_charW>
 *   @0x27f95c ldrb r3, [r4, #0x20]
 *   @0x27f960 cmp r3, r0
 *   @0x27f964 str r0, [sp, #0x24]
 *   @0x27f968 beq 0x280298 <json_tokener_parse_ex+0x1250>
 *   @0x27f96c cmp r0, #92
 *   @0x27f970 beq 0x280384 <json_tokener_parse_ex+0x133c>
 *   @0x27f974 mov r0, r7
 *   @0x27f978 bl 0x27eefc <utf8_get_charW>
 *   @0x27f97c bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f980 ldr r8, [r4, #0x14]
 *   @0x27f984 add r7, r7, r0
 *   @0x27f988 mov r0, r7
 *   @0x27f98c bl 0x27eefc <utf8_get_charW>
 *   @0x27f990 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27f994 ldr r3, [sp, #0x24]
 *   @0x27f998 cmp r3, #0
 *   @0x27f99c add r3, r8, r0
 *   @0x27f9a0 mov r0, r7
 *   @0x27f9a4 str r3, [r4, #0x14]
 *   @0x27f9a8 bne 0x27f950 <json_tokener_parse_ex+0x908>
 *   @0x27f9ac b 0x27f690 <json_tokener_parse_ex+0x648>
 *   @0x27f9b0 ldr r8, [sp, #0x24]
 *   @0x27f9b4 cmp r8, #58
 *   @0x27f9b8 bne 0x2805e8 <json_tokener_parse_ex+0x15a0>
 *   @0x27f9bc add r3, r1, r3
 *   @0x27f9c0 mov r0, #19
 *   @0x27f9c4 mov r2, #0
 *   @0x27f9c8 add r3, r4, r3, lsl #2
 *   @0x27f9cc str r0, [r3, #0x28]
 *   @0x27f9d0 str r2, [r3, #0x24]
 *   @0x27f9d4 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27f9d8 cmp r3, #30
 *   @0x27f9dc bgt 0x2805d8 <json_tokener_parse_ex+0x1590>
 *   @0x27f9e0 add r2, r1, r3
 *   @0x27f9e4 mov r12, #20
 *   @0x27f9e8 add r3, r3, #1
 *   @0x27f9ec b 0x27f858 <json_tokener_parse_ex+0x810>
 *   @0x27f9f0 add r3, r1, r3
 *   @0x27f9f4 ldr r2, [sp, #0x4]
 *   @0x27f9f8 add r3, r4, r3, lsl #2
 *   @0x27f9fc ldr r1, [r3, #0x34]
 *   @0x27fa00 ldr r0, [r3, #0x30]
 *   @0x27fa04 bl 0x27ea00 <json_object_object_add>
 *   @0x27fa08 ldr r3, [r4, #0x8]
 *   @0x27fa0c add r3, r3, r3, lsl #2
 *   @0x27fa10 add r3, r4, r3, lsl #2
 *   @0x27fa14 ldr r0, [r3, #0x34]
 *   @0x27fa18 bl 0xb655c <free@plt>
 *   @0x27fa1c ldr r3, [r4, #0x8]
 *   @0x27fa20 mov r12, #21
 *   @0x27fa24 mov r2, #0
 *   @0x27fa28 lsl r1, r3, #2
 *   @0x27fa2c add r0, r1, r3
 *   @0x27fa30 add r0, r4, r0, lsl #2
 *   @0x27fa34 str r9, [r0, #0x34]
 *   @0x27fa38 str r9, [r0, #0x24]
 *   @0x27fa3c str r12, [r0, #0x28]
 *   @0x27fa40 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27fa44 ldr r7, [pc, #0x63c]
 *   @0x27fa48 ldr r8, [sp, #0x24]
 *   @0x27fa4c ldr r7, [pc, r7]
 *   @0x27fa50 b 0x27fad0 <json_tokener_parse_ex+0xa88>
 *   @0x27fa54 ldr r3, [r4, #0x10]
 *   @0x27fa58 cmp r8, #57
 *   @0x27fa5c ldr r1, [r4, #0x1c]
 *   @0x27fa60 suble r2, r8, #48
 *   @0x27fa64 rsb r12, r3, #3
 *   @0x27fa68 add r3, r3, #1
 *   @0x27fa6c cmp r3, #4
 *   @0x27fa70 str r3, [r4, #0x10]
 *   @0x27fa74 lsl r3, r12, #2
 *   @0x27fa78 mov r0, r5
 *   @0x27fa7c add r2, r1, r2, lsl r3
 *   @0x27fa80 str r2, [r4, #0x1c]
 *   @0x27fa84 beq 0x27ffe8 <json_tokener_parse_ex+0xfa0>
 *   @0x27fa88 bl 0x27eefc <utf8_get_charW>
 *   @0x27fa8c bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27fa90 ldr r8, [r4, #0x14]
 *   @0x27fa94 add r5, r5, r0
 *   @0x27fa98 mov r0, r5
 *   @0x27fa9c bl 0x27eefc <utf8_get_charW>
 *   @0x27faa0 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27faa4 ldr r3, [sp, #0x24]
 *   @0x27faa8 cmp r3, #0
 *   @0x27faac add r3, r8, r0
 *   @0x27fab0 mov r0, r5
 *   @0x27fab4 str r3, [r4, #0x14]
 *   @0x27fab8 beq 0x27f1a8 <json_tokener_parse_ex+0x160>
 *   @0x27fabc cmp r6, r3
 *   @0x27fac0 beq 0x27fe58 <json_tokener_parse_ex+0xe10>
 *   @0x27fac4 bl 0x27eefc <utf8_get_charW>
 *   @0x27fac8 mov r8, r0
 *   @0x27facc str r0, [sp, #0x24]
 *   @0x27fad0 ldr r0, [r7]
 *   @0x27fad4 mov r1, r8
 *   @0x27fad8 bl 0xb6634 <strchr@plt>
 *   @0x27fadc and r2, r8, #7
 *   @0x27fae0 add r2, r2, #9
 *   @0x27fae4 cmp r0, #0
 *   @0x27fae8 bne 0x27fa54 <json_tokener_parse_ex+0xa0c>
 *   @0x27faec mov r3, #12
 *   @0x27faf0 str r3, [r4, #0x18]
 *   @0x27faf4 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x27faf8 ldr r0, [r4, #0x4]
 *   @0x27fafc ldr r3, [r0, #0x4]
 *   @0x27fb00 ldr r2, [r0, #0x8]
 *   @0x27fb04 rsb r2, r3, r2
 *   @0x27fb08 cmp r2, #1
 *   @0x27fb0c ble 0x27ffb8 <json_tokener_parse_ex+0xf70>
 *   @0x27fb10 ldr r2, [r0]
 *   @0x27fb14 ldrb r1, [sp, #0x24]
 *   @0x27fb18 strb r1, [r2, r3]
 *   @0x27fb1c ldr r3, [r4, #0x4]
 *   @0x27fb20 ldm r3, {r1, r2}
 *   @0x27fb24 add r2, r2, #1
 *   @0x27fb28 str r2, [r3, #0x4]
 *   @0x27fb2c strb r9, [r1, r2]
 *   @0x27fb30 ldr r3, [r4, #0x4]
 *   @0x27fb34 ldr r8, [r4, #0x10]
 *   @0x27fb38 ldr r0, [sp, #0x8]
 *   @0x27fb3c ldr r10, [r3]
 *   @0x27fb40 add r7, r8, #1
 *   @0x27fb44 cmp r7, #3
 *   @0x27fb48 mov r1, r10
 *   @0x27fb4c movle r2, r7
 *   @0x27fb50 movgt r2, #4
 *   @0x27fb54 bl 0xb6d18 <strncasecmp@plt>
 *   @0x27fb58 subs r11, r0, #0
 *   @0x27fb5c bne 0x27fd7c <json_tokener_parse_ex+0xd34>
 *   @0x27fb60 cmp r8, #4
 *   @0x27fb64 bne 0x2805a0 <json_tokener_parse_ex+0x1558>
 *   @0x27fb68 mov r0, #1
 *   @0x27fb6c ldr r7, [r4, #0x8]
 *   @0x27fb70 bl 0x27ea48 <json_object_new_boolean>
 *   @0x27fb74 ldr r3, [r4, #0x8]
 *   @0x27fb78 mov r8, #2
 *   @0x27fb7c mov r2, r11
 *   @0x27fb80 add r7, r7, r7, lsl #2
 *   @0x27fb84 lsl r1, r3, r8
 *   @0x27fb88 add r12, r1, r3
 *   @0x27fb8c add r7, r4, r7, lsl #2
 *   @0x27fb90 add r12, r4, r12, lsl #2
 *   @0x27fb94 str r0, [r7, #0x30]
 *   @0x27fb98 str r11, [r12, #0x24]
 *   @0x27fb9c str r8, [r12, #0x28]
 *   @0x27fba0 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27fba4 ldr r11, [sp, #0x24]
 *   @0x27fba8 cmp r11, #0
 *   @0x27fbac beq 0x27fc94 <json_tokener_parse_ex+0xc4c>
 *   @0x27fbb0 ldr r10, [pc, #0x4d4]
 *   @0x27fbb4 mov r7, r5
 *   @0x27fbb8 mov r8, #0
 *   @0x27fbbc ldr r10, [pc, r10]
 *   @0x27fbc0 b 0x27fc28 <json_tokener_parse_ex+0xbe0>
 *   @0x27fbc4 cmp r11, #46
 *   @0x27fbc8 cmpne r11, #101
 *   @0x27fbcc add r8, r8, #1
 *   @0x27fbd0 moveq r2, #1
 *   @0x27fbd4 streq r2, [r4, #0xc]
 *   @0x27fbd8 bl 0x27eefc <utf8_get_charW>
 *   @0x27fbdc bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27fbe0 ldr r11, [r4, #0x14]
 *   @0x27fbe4 add r7, r7, r0
 *   @0x27fbe8 mov r0, r7
 *   @0x27fbec bl 0x27eefc <utf8_get_charW>
 *   @0x27fbf0 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27fbf4 ldr r3, [sp, #0x24]
 *   @0x27fbf8 cmp r3, #0
 *   @0x27fbfc add r3, r11, r0
 *   @0x27fc00 mov r0, r7
 *   @0x27fc04 str r3, [r4, #0x14]
 *   @0x27fc08 beq 0x27fe08 <json_tokener_parse_ex+0xdc0>
 *   @0x27fc0c cmp r6, r3
 *   @0x27fc10 beq 0x27fddc <json_tokener_parse_ex+0xd94>
 *   @0x27fc14 bl 0x27eefc <utf8_get_charW>
 *   @0x27fc18 cmp r0, #0
 *   @0x27fc1c mov r11, r0
 *   @0x27fc20 str r0, [sp, #0x24]
 *   @0x27fc24 beq 0x27fc4c <json_tokener_parse_ex+0xc04>
 *   @0x27fc28 ldr r0, [r10]
 *   @0x27fc2c mov r1, r11
 *   @0x27fc30 bl 0xb6634 <strchr@plt>
 *   @0x27fc34 cmp r0, #0
 *   @0x27fc38 mov r0, r7
 *   @0x27fc3c bne 0x27fbc4 <json_tokener_parse_ex+0xb7c>
 *   @0x27fc40 cmp r8, #0
 *   @0x27fc44 moveq r5, r7
 *   @0x27fc48 beq 0x27fc94 <json_tokener_parse_ex+0xc4c>
 *   @0x27fc4c ldr r0, [r4, #0x4]
 *   @0x27fc50 ldr r3, [r0, #0x4]
 *   @0x27fc54 ldr r2, [r0, #0x8]
 *   @0x27fc58 rsb r2, r3, r2
 *   @0x27fc5c cmp r2, r8
 *   @0x27fc60 ble 0x28009c <json_tokener_parse_ex+0x1054>
 *   @0x27fc64 ldr r0, [r0]
 *   @0x27fc68 mov r1, r5
 *   @0x27fc6c mov r2, r8
 *   @0x27fc70 mov r5, r7
 *   @0x27fc74 add r0, r0, r3
 *   @0x27fc78 bl 0xb65bc <memcpy@plt>
 *   @0x27fc7c ldr r3, [r4, #0x4]
 *   @0x27fc80 ldr r1, [r3, #0x4]
 *   @0x27fc84 ldr r2, [r3]
 *   @0x27fc88 add r8, r8, r1
 *   @0x27fc8c str r8, [r3, #0x4]
 *   @0x27fc90 strb r9, [r2, r8]
 *   @0x27fc94 ldr r3, [r4, #0xc]
 *   @0x27fc98 cmp r3, #0
 *   @0x27fc9c beq 0x2803e0 <json_tokener_parse_ex+0x1398>
 *   @0x27fca0 ldr r3, [r4, #0x4]
 *   @0x27fca4 add r2, sp, #48
 *   @0x27fca8 ldr r1, [sp, #0x14]
 *   @0x27fcac ldr r0, [r3]
 *   @0x27fcb0 bl 0xb68f8 <sscanf@plt>
 *   @0x27fcb4 cmp r0, #1
 *   @0x27fcb8 bne 0x280408 <json_tokener_parse_ex+0x13c0>
 *   @0x27fcbc ldrd r0, r1, [sp, #48]
 *   @0x27fcc0 ldr r7, [r4, #0x8]
 *   @0x27fcc4 bl 0x27ebb8 <json_object_new_double>
 *   @0x27fcc8 add r7, r7, r7, lsl #2
 *   @0x27fccc add r7, r4, r7, lsl #2
 *   @0x27fcd0 str r0, [r7, #0x30]
 *   @0x27fcd4 ldr r3, [r4, #0x8]
 *   @0x27fcd8 mov r12, #2
 *   @0x27fcdc mov r2, #0
 *   @0x27fce0 lsl r1, r3, r12
 *   @0x27fce4 add r0, r1, r3
 *   @0x27fce8 add r0, r4, r0, lsl #2
 *   @0x27fcec str r9, [r0, #0x24]
 *   @0x27fcf0 str r12, [r0, #0x28]
 *   @0x27fcf4 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27fcf8 mov r1, r5
 *   @0x27fcfc mov r2, r7
 *   @0x27fd00 bl 0x280d20 <printbuf_memappend>
 *   @0x27fd04 ldr r8, [sp, #0x24]
 *   @0x27fd08 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x27fd0c ldr r3, [r4, #0x8]
 *   @0x27fd10 cmp r3, #0
 *   @0x27fd14 bne 0x27fd30 <json_tokener_parse_ex+0xce8>
 *   @0x27fd18 ldr r3, [r4, #0x24]
 *   @0x27fd1c cmp r3, #0
 *   @0x27fd20 bne 0x27fd30 <json_tokener_parse_ex+0xce8>
 *   @0x27fd24 ldr r2, [r4, #0x28]
 *   @0x27fd28 cmp r2, #2
 *   @0x27fd2c beq 0x27fd34 <json_tokener_parse_ex+0xcec>
 *   @0x27fd30 mov r3, #1
 *   @0x27fd34 str r3, [r4, #0x18]
 *   @0x27fd38 b 0x27f690 <json_tokener_parse_ex+0x648>
 *   @0x27fd3c add r3, r1, r3
 *   @0x27fd40 mov r0, #2
 *   @0x27fd44 mov r2, #0
 *   @0x27fd48 add r3, r4, r3, lsl #2
 *   @0x27fd4c str r0, [r3, #0x28]
 *   @0x27fd50 str r2, [r3, #0x24]
 *   @0x27fd54 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27fd58 add r7, sp, #56
 *   @0x27fd5c ldr r8, [r4, #0x4]
 *   @0x27fd60 ldr r0, [r7, #-0x14]!
 *   @0x27fd64 bl 0x27ef80 <utf8_char_sizeW>
 *   @0x27fd68 mov r1, r7
 *   @0x27fd6c mov r2, r0
 *   @0x27fd70 mov r0, r8
 *   @0x27fd74 bl 0x280d20 <printbuf_memappend>
 *   @0x27fd78 b 0x27f524 <json_tokener_parse_ex+0x4dc>
 *   @0x27fd7c cmp r7, #4
 *   @0x27fd80 mov r1, r10
 *   @0x27fd84 ldr r0, [sp, #0x10]
 *   @0x27fd88 movle r2, r7
 *   @0x27fd8c movgt r2, #5
 *   @0x27fd90 bl 0xb6d18 <strncasecmp@plt>
 *   @0x27fd94 subs r10, r0, #0
 *   @0x27fd98 bne 0x2806c4 <json_tokener_parse_ex+0x167c>
 *   @0x27fd9c cmp r8, #5
 *   @0x27fda0 bne 0x2805a0 <json_tokener_parse_ex+0x1558>
 *   @0x27fda4 ldr r7, [r4, #0x8]
 *   @0x27fda8 bl 0x27ea48 <json_object_new_boolean>
 *   @0x27fdac ldr r3, [r4, #0x8]
 *   @0x27fdb0 mov r8, #2
 *   @0x27fdb4 mov r2, r10
 *   @0x27fdb8 add r7, r7, r7, lsl #2
 *   @0x27fdbc lsl r1, r3, r8
 *   @0x27fdc0 add r12, r1, r3
 *   @0x27fdc4 add r7, r4, r7, lsl #2
 *   @0x27fdc8 add r12, r4, r12, lsl #2
 *   @0x27fdcc str r0, [r7, #0x30]
 *   @0x27fdd0 str r10, [r12, #0x24]
 *   @0x27fdd4 str r8, [r12, #0x28]
 *   @0x27fdd8 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x27fddc ldr r3, [r4, #0x8]
 *   @0x27fde0 cmp r3, #0
 *   @0x27fde4 bne 0x27fe00 <json_tokener_parse_ex+0xdb8>
 *   @0x27fde8 ldr r3, [r4, #0x24]
 *   @0x27fdec cmp r3, #0
 *   @0x27fdf0 bne 0x27fe00 <json_tokener_parse_ex+0xdb8>
 *   @0x27fdf4 ldr r2, [r4, #0x28]
 *   @0x27fdf8 cmp r2, #2
 *   @0x27fdfc beq 0x27fe04 <json_tokener_parse_ex+0xdbc>
 *   @0x27fe00 mov r3, #1
 *   @0x27fe04 str r3, [r4, #0x18]
 *   @0x27fe08 ldr r0, [r4, #0x4]
 *   @0x27fe0c ldr r3, [r0, #0x4]
 *   @0x27fe10 ldr r2, [r0, #0x8]
 *   @0x27fe14 rsb r2, r3, r2
 *   @0x27fe18 cmp r2, r8
 *   @0x27fe1c ble 0x280058 <json_tokener_parse_ex+0x1010>
 *   @0x27fe20 ldr r0, [r0]
 *   @0x27fe24 mov r2, r8
 *   @0x27fe28 mov r1, r5
 *   @0x27fe2c add r0, r0, r3
 *   @0x27fe30 bl 0xb65bc <memcpy@plt>
 *   @0x27fe34 ldr r3, [r4, #0x4]
 *   @0x27fe38 mov r1, #0
 *   @0x27fe3c ldr r0, [r3, #0x4]
 *   @0x27fe40 ldr r2, [r3]
 *   @0x27fe44 add r8, r8, r0
 *   @0x27fe48 str r8, [r3, #0x4]
 *   @0x27fe4c strb r1, [r2, r8]
 *   @0x27fe50 ldr r8, [sp, #0x24]
 *   @0x27fe54 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x27fe58 ldr r3, [r4, #0x8]
 *   @0x27fe5c cmp r3, #0
 *   @0x27fe60 bne 0x27fe7c <json_tokener_parse_ex+0xe34>
 *   @0x27fe64 ldr r3, [r4, #0x24]
 *   @0x27fe68 cmp r3, #0
 *   @0x27fe6c bne 0x27fe7c <json_tokener_parse_ex+0xe34>
 *   @0x27fe70 ldr r2, [r4, #0x28]
 *   @0x27fe74 cmp r2, #2
 *   @0x27fe78 beq 0x27fe80 <json_tokener_parse_ex+0xe38>
 *   @0x27fe7c mov r3, #1
 *   @0x27fe80 str r3, [r4, #0x18]
 *   @0x27fe84 b 0x27f100 <json_tokener_parse_ex+0xb8>
 *   @0x27fe88 cmp r8, #47
 *   @0x27fe8c beq 0x27fea0 <json_tokener_parse_ex+0xe58>
 *   @0x27fe90 cmp r8, #92
 *   @0x27fe94 beq 0x27fea0 <json_tokener_parse_ex+0xe58>
 *   @0x27fe98 cmp r8, #34
 *   @0x27fe9c bne 0x27faec <json_tokener_parse_ex+0xaa4>
 *   @0x27fea0 ldr r0, [r4, #0x4]
 *   @0x27fea4 ldr r3, [r0, #0x4]
 *   @0x27fea8 ldr r2, [r0, #0x8]
 *   @0x27feac rsb r2, r3, r2
 *   @0x27feb0 cmp r2, #1
 *   @0x27feb4 ble 0x2804c8 <json_tokener_parse_ex+0x1480>
 *   @0x27feb8 ldr r2, [r0]
 *   @0x27febc mov r0, #0
 *   @0x27fec0 ldrb r1, [sp, #0x24]
 *   @0x27fec4 strb r1, [r2, r3]
 *   @0x27fec8 ldr r3, [r4, #0x4]
 *   @0x27fecc ldm r3, {r1, r2}
 *   @0x27fed0 add r2, r2, #1
 *   @0x27fed4 str r2, [r3, #0x4]
 *   @0x27fed8 strb r0, [r1, r2]
 *   @0x27fedc ldr r3, [r4, #0x8]
 *   @0x27fee0 add r3, r3, r3, lsl #2
 *   @0x27fee4 add r3, r4, r3, lsl #2
 *   @0x27fee8 ldr r2, [r3, #0x28]
 *   @0x27feec str r2, [r3, #0x24]
 *   @0x27fef0 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27fef4 rsb r8, r5, r7
 *   @0x27fef8 mov r5, r7
 *   @0x27fefc ldr r0, [r4, #0x4]
 *   @0x27ff00 ldr r3, [r0, #0x4]
 *   @0x27ff04 ldr r2, [r0, #0x8]
 *   @0x27ff08 rsb r2, r3, r2
 *   @0x27ff0c cmp r8, r2
 *   @0x27ff10 bge 0x2800e4 <json_tokener_parse_ex+0x109c>
 *   @0x27ff14 ldr r0, [r0]
 *   @0x27ff18 mov r2, r8
 *   @0x27ff1c mov r1, r9
 *   @0x27ff20 add r0, r0, r3
 *   @0x27ff24 bl 0xb65bc <memcpy@plt>
 *   @0x27ff28 ldr r3, [r4, #0x4]
 *   @0x27ff2c mov r1, #0
 *   @0x27ff30 ldr r0, [r3, #0x4]
 *   @0x27ff34 ldr r2, [r3]
 *   @0x27ff38 add r8, r8, r0
 *   @0x27ff3c str r8, [r3, #0x4]
 *   @0x27ff40 strb r1, [r2, r8]
 *   @0x27ff44 ldr r3, [r4, #0x8]
 *   @0x27ff48 mov r2, #0
 *   @0x27ff4c add r3, r3, r3, lsl #2
 *   @0x27ff50 add r3, r4, r3, lsl #2
 *   @0x27ff54 str r2, [r3, #0x24]
 *   @0x27ff58 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27ff5c ldr r0, [r4, #0x4]
 *   @0x27ff60 add r8, r7, #1
 *   @0x27ff64 rsb r8, r5, r8
 *   @0x27ff68 ldr r3, [r0, #0x4]
 *   @0x27ff6c ldr r2, [r0, #0x8]
 *   @0x27ff70 rsb r2, r3, r2
 *   @0x27ff74 cmp r2, r8
 *   @0x27ff78 bgt 0x2800b0 <json_tokener_parse_ex+0x1068>
 *   @0x27ff7c mov r1, r5
 *   @0x27ff80 mov r2, r8
 *   @0x27ff84 bl 0x280d20 <printbuf_memappend>
 *   @0x27ff88 ldr r3, [r4, #0x8]
 *   @0x27ff8c mov r2, #7
 *   @0x27ff90 mov r5, r7
 *   @0x27ff94 add r3, r3, r3, lsl #2
 *   @0x27ff98 add r3, r4, r3, lsl #2
 *   @0x27ff9c str r2, [r3, #0x24]
 *   @0x27ffa0 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27ffa4 add r3, r1, r3
 *   @0x27ffa8 mov r2, #5
 *   @0x27ffac add r3, r4, r3, lsl #2
 *   @0x27ffb0 str r2, [r3, #0x24]
 *   @0x27ffb4 b 0x27f5a4 <json_tokener_parse_ex+0x55c>
 *   @0x27ffb8 add r1, sp, #36
 *   @0x27ffbc mov r2, #1
 *   @0x27ffc0 bl 0x280d20 <printbuf_memappend>
 *   @0x27ffc4 b 0x27fb30 <json_tokener_parse_ex+0xae8>
 *   @0x27ffc8 add r1, sp, #36
 *   @0x27ffcc mov r2, #1
 *   @0x27ffd0 bl 0x280d20 <printbuf_memappend>
 *   @0x27ffd4 b 0x27f790 <json_tokener_parse_ex+0x748>
 *   @0x27ffd8 add r1, sp, #36
 *   @0x27ffdc mov r2, #1
 *   @0x27ffe0 bl 0x280d20 <printbuf_memappend>
 *   @0x27ffe4 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x27ffe8 cmp r2, #127
 *   @0x27ffec bls 0x2801d4 <json_tokener_parse_ex+0x118c>
 *   @0x27fff0 cmp r2, #2048
 *   @0x27fff4 bhs 0x280520 <json_tokener_parse_ex+0x14d8>
 *   @0x27fff8 lsr r1, r2, #6
 *   @0x27fffc and r3, r2, #63
 *   @0x280000 ldr r0, [r4, #0x4]
 *   @0x280004 mvn r1, r1, lsl #26
 *   @0x280008 mvn r3, r3, lsl #25
 *   @0x28000c mvn r3, r3, lsr #25
 *   @0x280010 mvn r1, r1, lsr #26
 *   @0x280014 strb r3, [sp, #0x31]
 *   @0x280018 strb r1, [sp, #0x30]
 *   @0x28001c ldr r3, [r0, #0x4]
 *   @0x280020 ldr r2, [r0, #0x8]
 *   @0x280024 rsb r2, r3, r2
 *   @0x280028 cmp r2, #2
 *   @0x28002c ble 0x2805a8 <json_tokener_parse_ex+0x1560>
 *   @0x280030 ldr r2, [r0]
 *   @0x280034 mov r0, #0
 *   @0x280038 ldrh r1, [sp, #48]
 *   @0x28003c strh r1, [r2, r3]
 *   @0x280040 ldr r3, [r4, #0x4]
 *   @0x280044 ldm r3, {r1, r2}
 *   @0x280048 add r2, r2, #2
 *   @0x28004c str r2, [r3, #0x4]
 *   @0x280050 strb r0, [r1, r2]
 *   @0x280054 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x280058 mov r2, r8
 *   @0x28005c mov r1, r5
 *   @0x280060 bl 0x280d20 <printbuf_memappend>
 *   @0x280064 ldr r8, [sp, #0x24]
 *   @0x280068 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x28006c andeq r5, r11, r8, lsr #19
 *   @0x280070 muleq r11, r4, r9
 *   @0x280074 andeq r3, r11, r0, lsl r2
 *   @0x280078 andeq r3, r11, r8, asr r4
 *   @0x28007c andeq r1, r12, r8, ror #2
 *   @0x280080 andeq r8, sp, r12, lsl r2
 *   @0x280084 ldrsbeq lr, [r6], -r0
 *   @0x280088 andseq r1, r7, r12, lsr lr
 *   @0x28008c ldrsbeq r1, [r7], -r0
 *   @0x280090 andeq r2, r11, r0, lsr #12
 *   @0x280094 andeq r6, sp, r4, lsr #24
 *   @0x280098 andeq r6, sp, r0, lsl #24
 *   @0x28009c mov r1, r5
 *   @0x2800a0 mov r2, r8
 *   @0x2800a4 mov r5, r7
 *   @0x2800a8 bl 0x280d20 <printbuf_memappend>
 *   @0x2800ac b 0x27fc94 <json_tokener_parse_ex+0xc4c>
 *   @0x2800b0 ldr r0, [r0]
 *   @0x2800b4 mov r2, r8
 *   @0x2800b8 mov r1, r5
 *   @0x2800bc add r0, r0, r3
 *   @0x2800c0 bl 0xb65bc <memcpy@plt>
 *   @0x2800c4 ldr r3, [r4, #0x4]
 *   @0x2800c8 mov r1, #0
 *   @0x2800cc ldr r0, [r3, #0x4]
 *   @0x2800d0 ldr r2, [r3]
 *   @0x2800d4 add r8, r8, r0
 *   @0x2800d8 str r8, [r3, #0x4]
 *   @0x2800dc strb r1, [r2, r8]
 *   @0x2800e0 b 0x27ff88 <json_tokener_parse_ex+0xf40>
 *   @0x2800e4 mov r1, r9
 *   @0x2800e8 mov r2, r8
 *   @0x2800ec bl 0x280d20 <printbuf_memappend>
 *   @0x2800f0 b 0x27ff44 <json_tokener_parse_ex+0xefc>
 *   @0x2800f4 add r3, r1, r3
 *   @0x2800f8 mov r2, #3
 *   @0x2800fc add r3, r4, r3, lsl #2
 *   @0x280100 ldr r0, [r4, #0x4]
 *   @0x280104 str r2, [r3, #0x24]
 *   @0x280108 bl 0x280e9c <printbuf_reset>
 *   @0x28010c ldr r3, [r4, #0x8]
 *   @0x280110 str r9, [r4, #0x10]
 *   @0x280114 lsl r1, r3, #2
 *   @0x280118 add r2, r1, r3
 *   @0x28011c add r2, r4, r2, lsl #2
 *   @0x280120 ldr r2, [r2, #0x24]
 *   @0x280124 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x280128 add r3, r1, r3
 *   @0x28012c mov r2, #11
 *   @0x280130 b 0x2800fc <json_tokener_parse_ex+0x10b4>
 *   @0x280134 add r3, r1, r3
 *   @0x280138 mov r2, #12
 *   @0x28013c ldr r0, [r4, #0x4]
 *   @0x280140 add r3, r4, r3, lsl #2
 *   @0x280144 str r2, [r3, #0x24]
 *   @0x280148 bl 0x280e9c <printbuf_reset>
 *   @0x28014c ldr r3, [r4, #0x8]
 *   @0x280150 str r9, [r4, #0xc]
 *   @0x280154 lsl r1, r3, #2
 *   @0x280158 add r2, r1, r3
 *   @0x28015c add r2, r4, r2, lsl #2
 *   @0x280160 ldr r2, [r2, #0x24]
 *   @0x280164 b 0x27f204 <json_tokener_parse_ex+0x1bc>
 *   @0x280168 add r3, r1, r3
 *   @0x28016c mov r2, #8
 *   @0x280170 ldr r0, [r4, #0x4]
 *   @0x280174 add r3, r4, r3, lsl #2
 *   @0x280178 str r2, [r3, #0x24]
 *   @0x28017c bl 0x280e9c <printbuf_reset>
 *   @0x280180 ldr r3, [sp, #0x24]
 *   @0x280184 strb r3, [r4, #0x20]
 *   @0x280188 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x28018c add r3, r1, r3
 *   @0x280190 mov r0, #0
 *   @0x280194 mov r2, #16
 *   @0x280198 add r7, r4, r3, lsl #2
 *   @0x28019c str r0, [r7, #0x24]
 *   @0x2801a0 str r2, [r7, #0x28]
 *   @0x2801a4 bl 0x27e89c <json_object_new_object>
 *   @0x2801a8 str r0, [r7, #0x30]
 *   @0x2801ac b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x2801b0 add r3, r1, r3
 *   @0x2801b4 mov r0, #0
 *   @0x2801b8 mov r2, #13
 *   @0x2801bc add r7, r4, r3, lsl #2
 *   @0x2801c0 str r0, [r7, #0x24]
 *   @0x2801c4 str r2, [r7, #0x28]
 *   @0x2801c8 bl 0x27ed80 <json_object_new_array>
 *   @0x2801cc str r0, [r7, #0x30]
 *   @0x2801d0 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x2801d4 ldr r0, [r4, #0x4]
 *   @0x2801d8 uxtb r2, r2
 *   @0x2801dc strb r2, [sp, #0x30]
 *   @0x2801e0 ldr r3, [r0, #0x4]
 *   @0x2801e4 ldr r1, [r0, #0x8]
 *   @0x2801e8 rsb r1, r3, r1
 *   @0x2801ec cmp r1, #1
 *   @0x2801f0 ble 0x280654 <json_tokener_parse_ex+0x160c>
 *   @0x2801f4 ldr r1, [r0]
 *   @0x2801f8 mov r0, #0
 *   @0x2801fc strb r2, [r1, r3]
 *   @0x280200 b 0x27fec8 <json_tokener_parse_ex+0xe80>
 *   @0x280204 mov r3, #4
 *   @0x280208 str r3, [r4, #0x18]
 *   @0x28020c b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280210 rsb r8, r5, r7
 *   @0x280214 mov r5, r7
 *   @0x280218 ldr r0, [r4, #0x4]
 *   @0x28021c ldr r3, [r0, #0x4]
 *   @0x280220 ldr r2, [r0, #0x8]
 *   @0x280224 rsb r2, r3, r2
 *   @0x280228 cmp r2, r8
 *   @0x28022c ble 0x280428 <json_tokener_parse_ex+0x13e0>
 *   @0x280230 ldr r0, [r0]
 *   @0x280234 mov r2, r8
 *   @0x280238 mov r1, r9
 *   @0x28023c add r0, r0, r3
 *   @0x280240 bl 0xb65bc <memcpy@plt>
 *   @0x280244 ldr r3, [r4, #0x4]
 *   @0x280248 mov r1, #0
 *   @0x28024c ldr r0, [r3, #0x4]
 *   @0x280250 ldr r2, [r3]
 *   @0x280254 add r8, r8, r0
 *   @0x280258 str r8, [r3, #0x4]
 *   @0x28025c strb r1, [r2, r8]
 *   @0x280260 ldmib r4, {r3, r7}
 *   @0x280264 add r7, r7, r7, lsl #2
 *   @0x280268 ldr r0, [r3]
 *   @0x28026c bl 0x27ecc0 <json_object_new_string>
 *   @0x280270 ldr r3, [r4, #0x8]
 *   @0x280274 add r12, r4, r7, lsl #2
 *   @0x280278 mov r1, #2
 *   @0x28027c mov r2, #0
 *   @0x280280 add r3, r3, r3, lsl #2
 *   @0x280284 add r3, r4, r3, lsl #2
 *   @0x280288 str r0, [r12, #0x30]
 *   @0x28028c str r1, [r3, #0x28]
 *   @0x280290 str r2, [r3, #0x24]
 *   @0x280294 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x280298 rsb r8, r5, r7
 *   @0x28029c mov r5, r7
 *   @0x2802a0 ldr r0, [r4, #0x4]
 *   @0x2802a4 ldr r3, [r0, #0x4]
 *   @0x2802a8 ldr r2, [r0, #0x8]
 *   @0x2802ac rsb r2, r3, r2
 *   @0x2802b0 cmp r2, r8
 *   @0x2802b4 ble 0x280418 <json_tokener_parse_ex+0x13d0>
 *   @0x2802b8 ldr r0, [r0]
 *   @0x2802bc mov r2, r8
 *   @0x2802c0 mov r1, r9
 *   @0x2802c4 add r0, r0, r3
 *   @0x2802c8 bl 0xb65bc <memcpy@plt>
 *   @0x2802cc ldr r3, [r4, #0x4]
 *   @0x2802d0 mov r1, #0
 *   @0x2802d4 ldr r0, [r3, #0x4]
 *   @0x2802d8 ldr r2, [r3]
 *   @0x2802dc add r8, r8, r0
 *   @0x2802e0 str r8, [r3, #0x4]
 *   @0x2802e4 strb r1, [r2, r8]
 *   @0x2802e8 ldmib r4, {r3, r7}
 *   @0x2802ec add r7, r7, r7, lsl #2
 *   @0x2802f0 ldr r0, [r3]
 *   @0x2802f4 bl 0xb6640 <strdup@plt>
 *   @0x2802f8 add r3, r4, r7, lsl #2
 *   @0x2802fc mov r1, #18
 *   @0x280300 mov r2, #0
 *   @0x280304 str r1, [r3, #0x28]
 *   @0x280308 str r2, [r3, #0x24]
 *   @0x28030c str r0, [r3, #0x34]
 *   @0x280310 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x280314 rsb r8, r5, r7
 *   @0x280318 mov r5, r7
 *   @0x28031c ldr r0, [r4, #0x4]
 *   @0x280320 ldr r3, [r0, #0x4]
 *   @0x280324 ldr r2, [r0, #0x8]
 *   @0x280328 rsb r2, r3, r2
 *   @0x28032c cmp r2, r8
 *   @0x280330 ble 0x280438 <json_tokener_parse_ex+0x13f0>
 *   @0x280334 ldr r0, [r0]
 *   @0x280338 mov r2, r8
 *   @0x28033c mov r1, r9
 *   @0x280340 add r0, r0, r3
 *   @0x280344 bl 0xb65bc <memcpy@plt>
 *   @0x280348 ldr r3, [r4, #0x4]
 *   @0x28034c mov r1, #0
 *   @0x280350 ldr r0, [r3, #0x4]
 *   @0x280354 ldr r2, [r3]
 *   @0x280358 add r8, r8, r0
 *   @0x28035c str r8, [r3, #0x4]
 *   @0x280360 strb r1, [r2, r8]
 *   @0x280364 ldr r3, [r4, #0x8]
 *   @0x280368 mov r1, #8
 *   @0x28036c add r3, r3, r3, lsl #2
 *   @0x280370 mov r2, #9
 *   @0x280374 add r3, r4, r3, lsl #2
 *   @0x280378 str r1, [r3, #0x28]
 *   @0x28037c str r2, [r3, #0x24]
 *   @0x280380 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x280384 rsb r8, r5, r7
 *   @0x280388 mov r5, r7
 *   @0x28038c ldr r0, [r4, #0x4]
 *   @0x280390 ldr r3, [r0, #0x4]
 *   @0x280394 ldr r2, [r0, #0x8]
 *   @0x280398 rsb r2, r3, r2
 *   @0x28039c cmp r2, r8
 *   @0x2803a0 ble 0x280494 <json_tokener_parse_ex+0x144c>
 *   @0x2803a4 ldr r0, [r0]
 *   @0x2803a8 mov r2, r8
 *   @0x2803ac mov r1, r9
 *   @0x2803b0 add r0, r0, r3
 *   @0x2803b4 bl 0xb65bc <memcpy@plt>
 *   @0x2803b8 ldr r3, [r4, #0x4]
 *   @0x2803bc mov r1, #0
 *   @0x2803c0 ldr r0, [r3, #0x4]
 *   @0x2803c4 ldr r2, [r3]
 *   @0x2803c8 add r8, r8, r0
 *   @0x2803cc str r8, [r3, #0x4]
 *   @0x2803d0 strb r1, [r2, r8]
 *   @0x2803d4 ldr r3, [r4, #0x8]
 *   @0x2803d8 mov r1, #17
 *   @0x2803dc b 0x28036c <json_tokener_parse_ex+0x1324>
 *   @0x2803e0 ldr r3, [r4, #0x4]
 *   @0x2803e4 add r2, sp, #40
 *   @0x2803e8 ldr r1, [sp, #0x18]
 *   @0x2803ec ldr r0, [r3]
 *   @0x2803f0 bl 0xb68f8 <sscanf@plt>
 *   @0x2803f4 cmp r0, #1
 *   @0x2803f8 beq 0x280610 <json_tokener_parse_ex+0x15c8>
 *   @0x2803fc ldr r3, [r4, #0xc]
 *   @0x280400 cmp r3, #0
 *   @0x280404 bne 0x27fca0 <json_tokener_parse_ex+0xc58>
 *   @0x280408 mov r3, #7
 *   @0x28040c ldr r8, [sp, #0x24]
 *   @0x280410 str r3, [r4, #0x18]
 *   @0x280414 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280418 mov r1, r9
 *   @0x28041c mov r2, r8
 *   @0x280420 bl 0x280d20 <printbuf_memappend>
 *   @0x280424 b 0x2802e8 <json_tokener_parse_ex+0x12a0>
 *   @0x280428 mov r1, r9
 *   @0x28042c mov r2, r8
 *   @0x280430 bl 0x280d20 <printbuf_memappend>
 *   @0x280434 b 0x280260 <json_tokener_parse_ex+0x1218>
 *   @0x280438 mov r1, r9
 *   @0x28043c mov r2, r8
 *   @0x280440 bl 0x280d20 <printbuf_memappend>
 *   @0x280444 b 0x280364 <json_tokener_parse_ex+0x131c>
 *   @0x280448 cmp r8, #110
 *   @0x28044c bne 0x27faec <json_tokener_parse_ex+0xaa4>
 *   @0x280450 ldr r0, [r4, #0x4]
 *   @0x280454 ldr r3, [r0, #0x4]
 *   @0x280458 ldr r2, [r0, #0x8]
 *   @0x28045c rsb r2, r3, r2
 *   @0x280460 cmp r2, #1
 *   @0x280464 ble 0x280670 <json_tokener_parse_ex+0x1628>
 *   @0x280468 ldr r2, [r0]
 *   @0x28046c mov r1, #10
 *   @0x280470 strb r1, [r2, r3]
 *   @0x280474 mov r0, #0
 *   @0x280478 ldr r3, [r4, #0x4]
 *   @0x28047c ldm r3, {r1, r2}
 *   @0x280480 add r2, r2, #1
 *   @0x280484 str r2, [r3, #0x4]
 *   @0x280488 strb r0, [r1, r2]
 *   @0x28048c ldr r3, [r4, #0x8]
 *   @0x280490 b 0x27fee0 <json_tokener_parse_ex+0xe98>
 *   @0x280494 mov r1, r9
 *   @0x280498 mov r2, r8
 *   @0x28049c bl 0x280d20 <printbuf_memappend>
 *   @0x2804a0 b 0x2803d4 <json_tokener_parse_ex+0x138c>
 *   @0x2804a4 ldr r0, [r4, #0x4]
 *   @0x2804a8 ldr r3, [r0, #0x4]
 *   @0x2804ac ldr r2, [r0, #0x8]
 *   @0x2804b0 rsb r2, r3, r2
 *   @0x2804b4 cmp r2, #1
 *   @0x2804b8 ble 0x280630 <json_tokener_parse_ex+0x15e8>
 *   @0x2804bc ldr r2, [r0]
 *   @0x2804c0 mov r1, #8
 *   @0x2804c4 b 0x280470 <json_tokener_parse_ex+0x1428>
 *   @0x2804c8 add r1, sp, #36
 *   @0x2804cc mov r2, #1
 *   @0x2804d0 bl 0x280d20 <printbuf_memappend>
 *   @0x2804d4 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x2804d8 ldr r0, [r4, #0x4]
 *   @0x2804dc ldr r3, [r0, #0x4]
 *   @0x2804e0 ldr r2, [r0, #0x8]
 *   @0x2804e4 rsb r2, r3, r2
 *   @0x2804e8 cmp r2, #1
 *   @0x2804ec ble 0x2806ac <json_tokener_parse_ex+0x1664>
 *   @0x2804f0 ldr r2, [r0]
 *   @0x2804f4 mov r1, #13
 *   @0x2804f8 b 0x280470 <json_tokener_parse_ex+0x1428>
 *   @0x2804fc ldr r0, [r4, #0x4]
 *   @0x280500 ldr r3, [r0, #0x4]
 *   @0x280504 ldr r2, [r0, #0x8]
 *   @0x280508 rsb r2, r3, r2
 *   @0x28050c cmp r2, #1
 *   @0x280510 ble 0x2806d4 <json_tokener_parse_ex+0x168c>
 *   @0x280514 ldr r2, [r0]
 *   @0x280518 mov r1, #9
 *   @0x28051c b 0x280470 <json_tokener_parse_ex+0x1428>
 *   @0x280520 lsr r12, r2, #12
 *   @0x280524 ubfx r1, r2, #0x6, #0x6
 *   @0x280528 and r3, r2, #63
 *   @0x28052c ldr r0, [r4, #0x4]
 *   @0x280530 mvn r12, r12, lsl #27
 *   @0x280534 mvn r1, r1, lsl #25
 *   @0x280538 mvn r3, r3, lsl #25
 *   @0x28053c mvn r12, r12, lsr #27
 *   @0x280540 mvn r3, r3, lsr #25
 *   @0x280544 strb r12, [sp, #0x30]
 *   @0x280548 strb r3, [sp, #0x32]
 *   @0x28054c mvn r1, r1, lsr #25
 *   @0x280550 strb r1, [sp, #0x31]
 *   @0x280554 ldr r3, [r0, #0x4]
 *   @0x280558 ldr r2, [r0, #0x8]
 *   @0x28055c rsb r2, r3, r2
 *   @0x280560 cmp r2, #3
 *   @0x280564 ble 0x280644 <json_tokener_parse_ex+0x15fc>
 *   @0x280568 add r2, sp, #56
 *   @0x28056c ldr r1, [r0]
 *   @0x280570 mov r0, #0
 *   @0x280574 ldrh lr, [r2, #-8]!
 *   @0x280578 add r12, r1, r3
 *   @0x28057c ldrb r2, [r2, #0x2]
 *   @0x280580 strh lr, [r1, r3]
 *   @0x280584 strb r2, [r12, #0x2]
 *   @0x280588 ldr r3, [r4, #0x4]
 *   @0x28058c ldm r3, {r1, r2}
 *   @0x280590 add r2, r2, #3
 *   @0x280594 str r2, [r3, #0x4]
 *   @0x280598 strb r0, [r1, r2]
 *   @0x28059c b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x2805a0 str r7, [r4, #0x10]
 *   @0x2805a4 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x2805a8 add r1, sp, #48
 *   @0x2805ac mov r2, #2
 *   @0x2805b0 bl 0x280d20 <printbuf_memappend>
 *   @0x2805b4 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x2805b8 mov r8, #0
 *   @0x2805bc b 0x280218 <json_tokener_parse_ex+0x11d0>
 *   @0x2805c0 mov r8, #0
 *   @0x2805c4 b 0x28031c <json_tokener_parse_ex+0x12d4>
 *   @0x2805c8 mov r8, #0
 *   @0x2805cc b 0x28038c <json_tokener_parse_ex+0x1344>
 *   @0x2805d0 mov r8, #0
 *   @0x2805d4 b 0x2802a0 <json_tokener_parse_ex+0x1258>
 *   @0x2805d8 mov r3, #2
 *   @0x2805dc ldr r8, [sp, #0x24]
 *   @0x2805e0 str r3, [r4, #0x18]
 *   @0x2805e4 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x2805e8 mov r3, #10
 *   @0x2805ec str r3, [r4, #0x18]
 *   @0x2805f0 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x2805f4 mov r3, #2
 *   @0x2805f8 str r3, [r4, #0x18]
 *   @0x2805fc b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280600 mov r3, #5
 *   @0x280604 ldr r8, [sp, #0x24]
 *   @0x280608 str r3, [r4, #0x18]
 *   @0x28060c b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280610 ldrd r0, r1, [sp, #40]
 *   @0x280614 bl 0x319164 <__floatdidf>
 *   @0x280618 ldr r7, [r4, #0x8]
 *   @0x28061c bl 0x27ebb8 <json_object_new_double>
 *   @0x280620 add r7, r7, r7, lsl #2
 *   @0x280624 add r3, r4, r7, lsl #2
 *   @0x280628 str r0, [r3, #0x30]
 *   @0x28062c b 0x27fcd4 <json_tokener_parse_ex+0xc8c>
 *   @0x280630 ldr r1, [sp, #0x1c]
 *   @0x280634 mov r2, #1
 *   @0x280638 bl 0x280d20 <printbuf_memappend>
 *   @0x28063c ldr r3, [r4, #0x8]
 *   @0x280640 b 0x27fee0 <json_tokener_parse_ex+0xe98>
 *   @0x280644 add r1, sp, #48
 *   @0x280648 mov r2, #3
 *   @0x28064c bl 0x280d20 <printbuf_memappend>
 *   @0x280650 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x280654 add r1, sp, #48
 *   @0x280658 mov r2, #1
 *   @0x28065c bl 0x280d20 <printbuf_memappend>
 *   @0x280660 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x280664 mov r3, #11
 *   @0x280668 str r3, [r4, #0x18]
 *   @0x28066c b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280670 ldr r1, [pc, #-0x5e8]
 *   @0x280674 mov r2, #1
 *   @0x280678 add r1, pc, r1
 *   @0x28067c bl 0x280d20 <printbuf_memappend>
 *   @0x280680 ldr r3, [r4, #0x8]
 *   @0x280684 b 0x27fee0 <json_tokener_parse_ex+0xe98>
 *   @0x280688 mov r3, #13
 *   @0x28068c str r3, [r4, #0x18]
 *   @0x280690 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x280694 mov r3, #9
 *   @0x280698 str r3, [r4, #0x18]
 *   @0x28069c b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x2806a0 mov r3, #8
 *   @0x2806a4 str r3, [r4, #0x18]
 *   @0x2806a8 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x2806ac ldr r1, [pc, #-0x620]
 *   @0x2806b0 mov r2, #1
 *   @0x2806b4 add r1, pc, r1
 *   @0x2806b8 bl 0x280d20 <printbuf_memappend>
 *   @0x2806bc ldr r3, [r4, #0x8]
 *   @0x2806c0 b 0x27fee0 <json_tokener_parse_ex+0xe98>
 *   @0x2806c4 mov r3, #6
 *   @0x2806c8 ldr r8, [sp, #0x24]
 *   @0x2806cc str r3, [r4, #0x18]
 *   @0x2806d0 b 0x27f0f8 <json_tokener_parse_ex+0xb0>
 *   @0x2806d4 ldr r1, [pc, #-0x644]
 *   @0x2806d8 mov r2, #1
 *   @0x2806dc add r1, pc, r1
 *   @0x2806e0 bl 0x280d20 <printbuf_memappend>
 *   @0x2806e4 b 0x27fedc <json_tokener_parse_ex+0xe94>
 *   @0x2806e8 cmp r0, #47
 *   @0x2806ec bne 0x27f320 <json_tokener_parse_ex+0x2d8>
 *   @0x2806f0 ldr r0, [r4, #0x4]
 *   @0x2806f4 bl 0x280e9c <printbuf_reset>
 *   @0x2806f8 ldr r0, [r4, #0x4]
 *   @0x2806fc ldr r3, [r0, #0x4]
 *   @0x280700 ldr r2, [r0, #0x8]
 *   @0x280704 rsb r2, r3, r2
 *   @0x280708 cmp r2, #1
 *   @0x28070c ble 0x28074c <json_tokener_parse_ex+0x1704>
 *   @0x280710 ldr r2, [r0]
 *   @0x280714 mov r0, #0
 *   @0x280718 ldrb r1, [sp, #0x24]
 *   @0x28071c strb r1, [r2, r3]
 *   @0x280720 ldr r3, [r4, #0x4]
 *   @0x280724 ldm r3, {r1, r2}
 *   @0x280728 add r2, r2, #1
 *   @0x28072c str r2, [r3, #0x4]
 *   @0x280730 strb r0, [r1, r2]
 *   @0x280734 ldr r3, [r4, #0x8]
 *   @0x280738 mov r2, #4
 *   @0x28073c add r3, r3, r3, lsl #2
 *   @0x280740 add r3, r4, r3, lsl #2
 *   @0x280744 str r2, [r3, #0x24]
 *   @0x280748 b 0x27f174 <json_tokener_parse_ex+0x12c>
 *   @0x28074c add r1, sp, #36
 *   @0x280750 mov r2, #1
 *   @0x280754 bl 0x280d20 <printbuf_memappend>
 *   @0x280758 b 0x280734 <json_tokener_parse_ex+0x16ec>
 *
 * ══ §2/7 gdtoa  0x23dfd0  size 5016  1254 条（0x23dfd0..0x23f368）
 * @func 0x23dfd0 0x23f368  size 5016  1254 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x23dfe0→0x756478
 * 调用序列: multadd_D2A×10 / Bfree_D2A×7 / cmp_D2A×7 / lshift_D2A×6 / gdtoa(FPI*, int, unsigned int*, int*, int, int, int*, char**)+0x650×4 / pow5mult_D2A×4 / nrv_alloc_D2A×3 / quorem_D2A×3
 * 字段偏移 top8: 0x4c×32 / 0x10×31 / 0x4×28 / 0x20×19 / 0x14×14 / 0x78×13 / 0x2c×13 / 0x34×11
 * VFP 指令 138 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x23dfd0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x23dfd4 mov r8, r0
 *   @0x23dfd8 ldr r7, [pc, #0x598]
 *   @0x23dfdc sub sp, sp, #84
 *   @0x23dfe0 ldr r0, [pc, #0x594]
 *   @0x23dfe4 mov r10, r1
 *   @0x23dfe8 add r7, pc, r7
 *   @0x23dfec str r2, [sp, #0xc]
 *   @0x23dff0 mov r4, r3
 *   @0x23dff4 ldr r5, [r7, r0]
 *   @0x23dff8 ldr r0, [r5]
 *   @0x23dffc cmp r0, #0
 *   @0x23e000 beq 0x23e010 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x40>
 *   @0x23e004 bl 0x23dd68 <_Z8freedtoaPc>
 *   @0x23e008 mov r3, #0
 *   @0x23e00c str r3, [r5]
 *   @0x23e010 ldr r9, [r4]
 *   @0x23e014 and r3, r9, #7
 *   @0x23e018 bic r2, r9, #48
 *   @0x23e01c str r2, [r4]
 *   @0x23e020 cmp r3, #4
 *   @0x23e024 addls pc, pc, r3, lsl #2
 *   @0x23e028 b 0x23f360 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1390>
 *   @0x23e02c b 0x23e104 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x134>
 *   @0x23e030 b 0x23e040 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x70>
 *   @0x23e034 b 0x23e040 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x70>
 *   @0x23e038 b 0x23e154 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x184>
 *   @0x23e03c b 0x23e128 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x158>
 *   @0x23e040 ldr r11, [r8]
 *   @0x23e044 mov r0, #0
 *   @0x23e048 cmp r11, #32
 *   @0x23e04c ble 0x23e064 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x94>
 *   @0x23e050 mov r3, #32
 *   @0x23e054 lsl r3, r3, #1
 *   @0x23e058 add r0, r0, #1
 *   @0x23e05c cmp r11, r3
 *   @0x23e060 bgt 0x23e054 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x84>
 *   @0x23e064 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23e068 ldr r3, [sp, #0xc]
 *   @0x23e06c mov r5, r0
 *   @0x23e070 sub r0, r11, #1
 *   @0x23e074 add r2, r5, #20
 *   @0x23e078 asr r0, r0, #5
 *   @0x23e07c mov r6, r2
 *   @0x23e080 add r0, r3, r0, lsl #2
 *   @0x23e084 ldr r1, [r3], #4
 *   @0x23e088 cmp r0, r3
 *   @0x23e08c str r1, [r6], #4
 *   @0x23e090 bhs 0x23e084 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb4>
 *   @0x23e094 rsb r6, r2, r6
 *   @0x23e098 asr r6, r6, #2
 *   @0x23e09c add r2, r2, r6, lsl #2
 *   @0x23e0a0 b 0x23e0b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe0>
 *   @0x23e0a4 cmp r3, #0
 *   @0x23e0a8 mov r6, r3
 *   @0x23e0ac beq 0x23e2d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x304>
 *   @0x23e0b0 ldr r1, [r2, #-0x4]!
 *   @0x23e0b4 sub r3, r6, #1
 *   @0x23e0b8 cmp r1, #0
 *   @0x23e0bc beq 0x23e0a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd4>
 *   @0x23e0c0 add r3, r5, r6, lsl #2
 *   @0x23e0c4 str r6, [r5, #0x10]
 *   @0x23e0c8 ldr r0, [r3, #0x10]
 *   @0x23e0cc bl 0x23d41c <hi0bits_D2A>
 *   @0x23e0d0 rsb r6, r0, r6, lsl #5
 *   @0x23e0d4 str r6, [sp, #0x24]
 *   @0x23e0d8 mov r0, r5
 *   @0x23e0dc bl 0x23dc44 <trailz_D2A>
 *   @0x23e0e0 cmp r0, #0
 *   @0x23e0e4 str r0, [sp, #0x4c]
 *   @0x23e0e8 moveq r6, r10
 *   @0x23e0ec bne 0x23e2e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x310>
 *   @0x23e0f0 ldr r3, [r5, #0x10]
 *   @0x23e0f4 mov r0, r5
 *   @0x23e0f8 cmp r3, #0
 *   @0x23e0fc bne 0x23e180 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1b0>
 *   @0x23e100 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e104 ldr r3, [sp, #0x80]
 *   @0x23e108 mov r2, #1
 *   @0x23e10c ldr r0, [pc, #0x46c]
 *   @0x23e110 ldr r1, [sp, #0x84]
 *   @0x23e114 add r0, pc, r0
 *   @0x23e118 str r2, [r3]
 *   @0x23e11c bl 0x23dd14 <nrv_alloc_D2A>
 *   @0x23e120 add sp, sp, #84
 *   @0x23e124 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23e128 ldr lr, [sp, #0x80]
 *   @0x23e12c mov r2, #3
 *   @0x23e130 ldr r0, [pc, #0x44c]
 *   @0x23e134 mov r3, #32768
 *   @0x23e138 ldr r1, [sp, #0x84]
 *   @0x23e13c movt r3, #0xffff
 *   @0x23e140 add r0, pc, r0
 *   @0x23e144 str r3, [lr]
 *   @0x23e148 bl 0x23dd14 <nrv_alloc_D2A>
 *   @0x23e14c add sp, sp, #84
 *   @0x23e150 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23e154 ldr r2, [sp, #0x80]
 *   @0x23e158 mov r3, #32768
 *   @0x23e15c ldr r0, [pc, #0x424]
 *   @0x23e160 movt r3, #0xffff
 *   @0x23e164 ldr r1, [sp, #0x84]
 *   @0x23e168 str r3, [r2]
 *   @0x23e16c add r0, pc, r0
 *   @0x23e170 mov r2, #8
 *   @0x23e174 bl 0x23dd14 <nrv_alloc_D2A>
 *   @0x23e178 add sp, sp, #84
 *   @0x23e17c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23e180 add r1, sp, #76
 *   @0x23e184 bl 0x23d968 <b2d_D2A>
 *   @0x23e188 vmov.f64 d4, #1.500000e+00
 *   @0x23e18c vldr d5, [pc, #964]
 *   @0x23e190 vldr d7, [pc, #968]
 *   @0x23e194 vldr d6, [pc, #972]
 *   @0x23e198 strd r0, r1, [sp, #24]
 *   @0x23e19c ldr lr, [sp, #0x1c]
 *   @0x23e1a0 ldr r0, [sp, #0x24]
 *   @0x23e1a4 ubfx r2, lr, #0x0, #0x14
 *   @0x23e1a8 orr r2, r2, #1069547520
 *   @0x23e1ac add r3, r6, r0
 *   @0x23e1b0 orr r2, r2, #3145728
 *   @0x23e1b4 str r2, [sp, #0x1c]
 *   @0x23e1b8 vldr d2, [sp, #24]
 *   @0x23e1bc vsub.f64 d4, d2, d4
 *   @0x23e1c0 sub r3, r3, #1
 *   @0x23e1c4 eor r1, r3, r3, asr #31
 *   @0x23e1c8 sub r1, r1, r3, asr #31
 *   @0x23e1cc vmov s5, r3
 *   @0x23e1d0 sub r1, r1, #1072
 *   @0x23e1d4 sub r1, r1, #5
 *   @0x23e1d8 cmp r1, #0
 *   @0x23e1dc vmovgt s6, r1
 *   @0x23e1e0 vmla.f64 d7, d4, d5
 *   @0x23e1e4 vcvt.f64.s32 d5, s5
 *   @0x23e1e8 vmla.f64 d7, d5, d6
 *   @0x23e1ec vldrgt d6, [pc, #892]
 *   @0x23e1f0 vcvtgt.f64.s32 d5, s6
 *   @0x23e1f4 vmlagt.f64 d7, d5, d6
 *   @0x23e1f8 vcvt.s32.f64 s7, d7
 *   @0x23e1fc vcmpe.f64 d7, #0
 *   @0x23e200 vstr s7, [sp, #16]
 *   @0x23e204 vmrs APSR_nzcv, fpscr
 *   @0x23e208 bmi 0x23e938 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x968>
 *   @0x23e20c ldr r1, [sp, #0x10]
 *   @0x23e210 add r2, r2, r3, lsl #20
 *   @0x23e214 str r2, [sp, #0x1c]
 *   @0x23e218 cmp r1, #22
 *   @0x23e21c movhi r2, #1
 *   @0x23e220 strhi r2, [sp, #0x40]
 *   @0x23e224 bhi 0x23e254 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x284>
 *   @0x23e228 ldr r2, [pc, #0x35c]
 *   @0x23e22c vldr d2, [sp, #24]
 *   @0x23e230 ldr r2, [r7, r2]
 *   @0x23e234 add r2, r2, r1, lsl #3
 *   @0x23e238 vldr d7, [r2]
 *   @0x23e23c vcmpe.f64 d7, d2
 *   @0x23e240 mov r2, #0
 *   @0x23e244 str r2, [sp, #0x40]
 *   @0x23e248 vmrs APSR_nzcv, fpscr
 *   @0x23e24c subgt r1, r1, #1
 *   @0x23e250 strgt r1, [sp, #0x10]
 *   @0x23e254 ldr r2, [sp, #0x24]
 *   @0x23e258 ldr lr, [sp, #0x10]
 *   @0x23e25c rsb r12, r3, r2
 *   @0x23e260 subs r12, r12, #1
 *   @0x23e264 rsbmi r12, r12, #0
 *   @0x23e268 strmi r12, [sp, #0x28]
 *   @0x23e26c movpl r2, #0
 *   @0x23e270 movmi r12, #0
 *   @0x23e274 strpl r2, [sp, #0x28]
 *   @0x23e278 cmp lr, #0
 *   @0x23e27c blt 0x23e914 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x944>
 *   @0x23e280 add r12, r12, lr
 *   @0x23e284 mov r2, #0
 *   @0x23e288 str lr, [sp, #0x38]
 *   @0x23e28c str r2, [sp, #0x30]
 *   @0x23e290 ldr lr, [sp, #0x78]
 *   @0x23e294 cmp lr, #9
 *   @0x23e298 bhi 0x23e304 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x334>
 *   @0x23e29c cmp lr, #5
 *   @0x23e2a0 ble 0x23e30c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x33c>
 *   @0x23e2a4 mov r3, #0
 *   @0x23e2a8 sub lr, lr, #4
 *   @0x23e2ac str lr, [sp, #0x78]
 *   @0x23e2b0 ldr r1, [sp, #0x78]
 *   @0x23e2b4 sub r2, r1, #2
 *   @0x23e2b8 cmp r2, #3
 *   @0x23e2bc addls pc, pc, r2, lsl #2
 *   @0x23e2c0 b 0x23e5dc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x60c>
 *   @0x23e2c4 b 0x23e590 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5c0>
 *   @0x23e2c8 b 0x23e328 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x358>
 *   @0x23e2cc b 0x23e5d0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x600>
 *   @0x23e2d0 b 0x23ebd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc08>
 *   @0x23e2d4 str r3, [r5, #0x10]
 *   @0x23e2d8 str r3, [sp, #0x24]
 *   @0x23e2dc b 0x23e0d8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108>
 *   @0x23e2e0 mov r1, r0
 *   @0x23e2e4 mov r0, r5
 *   @0x23e2e8 bl 0x23db50 <rshift_D2A>
 *   @0x23e2ec ldr r3, [sp, #0x4c]
 *   @0x23e2f0 ldr r2, [sp, #0x24]
 *   @0x23e2f4 add r6, r10, r3
 *   @0x23e2f8 rsb r2, r3, r2
 *   @0x23e2fc str r2, [sp, #0x24]
 *   @0x23e300 b 0x23e0f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x120>
 *   @0x23e304 mov r0, #0
 *   @0x23e308 str r0, [sp, #0x78]
 *   @0x23e30c add r3, r3, #1020
 *   @0x23e310 movw r2, #0x7f7
 *   @0x23e314 add r3, r3, #2
 *   @0x23e318 cmp r3, r2
 *   @0x23e31c movhi r3, #0
 *   @0x23e320 movls r3, #1
 *   @0x23e324 b 0x23e2b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x2e0>
 *   @0x23e328 mov r0, #0
 *   @0x23e32c str r0, [sp, #0x34]
 *   @0x23e330 ldr r2, [sp, #0x7c]
 *   @0x23e334 ldr r1, [sp, #0x10]
 *   @0x23e338 add r1, r2, r1
 *   @0x23e33c str r1, [sp, #0x44]
 *   @0x23e340 add lr, r1, #1
 *   @0x23e344 str lr, [sp, #0x20]
 *   @0x23e348 cmp lr, #0
 *   @0x23e34c ble 0x23ee4c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe7c>
 *   @0x23e350 mov r0, lr
 *   @0x23e354 cmp lr, #14
 *   @0x23e358 movhi r3, #0
 *   @0x23e35c andls r3, r3, #1
 *   @0x23e360 str lr, [sp, #0x4c]
 *   @0x23e364 str r3, [sp, #0x3c]
 *   @0x23e368 str r12, [sp, #0x4]
 *   @0x23e36c bl 0x23dcc4 <rv_alloc_D2A>
 *   @0x23e370 ldr r3, [r8, #0xc]
 *   @0x23e374 ldr r12, [sp, #0x4]
 *   @0x23e378 sub r3, r3, #1
 *   @0x23e37c str r3, [sp, #0x14]
 *   @0x23e380 cmp r3, #0
 *   @0x23e384 str r0, [sp, #0x2c]
 *   @0x23e388 beq 0x23e3a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x3d4>
 *   @0x23e38c movlt r3, #2
 *   @0x23e390 strlt r3, [sp, #0x14]
 *   @0x23e394 tst r9, #8
 *   @0x23e398 ldrne r3, [sp, #0x14]
 *   @0x23e39c rsbne r3, r3, #3
 *   @0x23e3a0 strne r3, [sp, #0x14]
 *   @0x23e3a4 ldr r1, [sp, #0x3c]
 *   @0x23e3a8 cmp r1, #0
 *   @0x23e3ac beq 0x23e624 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x654>
 *   @0x23e3b0 ldr r2, [sp, #0x14]
 *   @0x23e3b4 ldr lr, [sp, #0x10]
 *   @0x23e3b8 orrs r3, r2, lr
 *   @0x23e3bc bne 0x23e624 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x654>
 *   @0x23e3c0 ldr r2, [sp, #0x40]
 *   @0x23e3c4 vldr d3, [sp, #24]
 *   @0x23e3c8 str r3, [sp, #0x4c]
 *   @0x23e3cc cmp r2, #0
 *   @0x23e3d0 beq 0x23e3e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x414>
 *   @0x23e3d4 vmov.f64 d7, #1.000000e+00
 *   @0x23e3d8 vcmpe.f64 d3, d7
 *   @0x23e3dc vmrs APSR_nzcv, fpscr
 *   @0x23e3e0 bmi 0x23f138 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1168>
 *   @0x23e3e4 vadd.f64 d6, d3, d3
 *   @0x23e3e8 ldr r3, [sp, #0x20]
 *   @0x23e3ec cmp r3, #0
 *   @0x23e3f0 vmov.f64 d7, #7.000000e+00
 *   @0x23e3f4 vadd.f64 d2, d6, d7
 *   @0x23e3f8 vstr d2, [sp, #24]
 *   @0x23e3fc ldr r0, [sp, #0x1c]
 *   @0x23e400 sub r0, r0, #54525952
 *   @0x23e404 str r0, [sp, #0x1c]
 *   @0x23e408 beq 0x23eb04 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb34>
 *   @0x23e40c vmov.f64 d7, d3
 *   @0x23e410 ldr r1, [sp, #0x20]
 *   @0x23e414 mov r0, #0
 *   @0x23e418 ldr r3, [sp, #0x34]
 *   @0x23e41c cmp r3, #0
 *   @0x23e420 beq 0x23ef40 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf70>
 *   @0x23e424 vmov.f64 d5, #5.000000e-01
 *   @0x23e428 ldr r3, [pc, #0x15c]
 *   @0x23e42c ldr lr, [sp, #0x2c]
 *   @0x23e430 vldr d2, [sp, #24]
 *   @0x23e434 ldr r3, [r7, r3]
 *   @0x23e438 add r2, lr, #1
 *   @0x23e43c add r3, r3, r1, lsl #3
 *   @0x23e440 vldr d6, [r3, #-8]
 *   @0x23e444 mov r3, #0
 *   @0x23e448 str r3, [sp, #0x4c]
 *   @0x23e44c mov r9, r2
 *   @0x23e450 vdiv.f64 d6, d5, d6
 *   @0x23e454 vcvt.s32.f64 s9, d7
 *   @0x23e458 vmov lr, s9
 *   @0x23e45c vcvt.f64.s32 d5, s9
 *   @0x23e460 vsub.f64 d6, d6, d2
 *   @0x23e464 vsub.f64 d7, d7, d5
 *   @0x23e468 add r3, lr, #48
 *   @0x23e46c ldr lr, [sp, #0x2c]
 *   @0x23e470 uxtb r3, r3
 *   @0x23e474 strb r3, [lr]
 *   @0x23e478 vcmpe.f64 d6, d7
 *   @0x23e47c vmrs APSR_nzcv, fpscr
 *   @0x23e480 bgt 0x23e508 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x538>
 *   @0x23e484 vmov.f64 d2, #1.000000e+00
 *   @0x23e488 vsub.f64 d5, d2, d7
 *   @0x23e48c vcmpe.f64 d5, d6
 *   @0x23e490 vmrs APSR_nzcv, fpscr
 *   @0x23e494 bmi 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0>
 *   @0x23e498 ldr r3, [sp, #0x4c]
 *   @0x23e49c add r3, r3, #1
 *   @0x23e4a0 str r3, [sp, #0x4c]
 *   @0x23e4a4 cmp r1, r3
 *   @0x23e4a8 ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650>
 *   @0x23e4ac vmov.f64 d5, #1.000000e+01
 *   @0x23e4b0 b 0x23e4d8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x508>
 *   @0x23e4b4 vsub.f64 d4, d2, d7
 *   @0x23e4b8 vcmpe.f64 d4, d6
 *   @0x23e4bc vmrs APSR_nzcv, fpscr
 *   @0x23e4c0 bmi 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0>
 *   @0x23e4c4 ldr r3, [sp, #0x4c]
 *   @0x23e4c8 add r3, r3, #1
 *   @0x23e4cc str r3, [sp, #0x4c]
 *   @0x23e4d0 cmp r1, r3
 *   @0x23e4d4 ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650>
 *   @0x23e4d8 vmul.f64 d7, d7, d5
 *   @0x23e4dc vcvt.s32.f64 s8, d7
 *   @0x23e4e0 vmov lr, s8
 *   @0x23e4e4 vmul.f64 d6, d6, d5
 *   @0x23e4e8 vcvt.f64.s32 d4, s8
 *   @0x23e4ec add r3, lr, #48
 *   @0x23e4f0 uxtb r3, r3
 *   @0x23e4f4 strb r3, [r9], #1
 *   @0x23e4f8 vsub.f64 d7, d7, d4
 *   @0x23e4fc vcmpe.f64 d7, d6
 *   @0x23e500 vmrs APSR_nzcv, fpscr
 *   @0x23e504 bpl 0x23e4b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x4e4>
 *   @0x23e508 vcmp.f64 d7, #0
 *   @0x23e50c add r11, r0, #1
 *   @0x23e510 vmrs APSR_nzcv, fpscr
 *   @0x23e514 beq 0x23ed24 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd54>
 *   @0x23e518 mov r10, #16
 *   @0x23e51c mov r0, r5
 *   @0x23e520 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e524 ldr r1, [sp, #0x80]
 *   @0x23e528 ldr r0, [sp, #0x84]
 *   @0x23e52c mov r3, #0
 *   @0x23e530 strb r3, [r9]
 *   @0x23e534 str r11, [r1]
 *   @0x23e538 cmp r0, #0
 *   @0x23e53c ldr r3, [r4]
 *   @0x23e540 strne r9, [r0]
 *   @0x23e544 orr r10, r3, r10
 *   @0x23e548 ldr r0, [sp, #0x2c]
 *   @0x23e54c str r10, [r4]
 *   @0x23e550 add sp, sp, #84
 *   @0x23e554 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x23e558 .word 0x636f4361
 *   @0x23e55c svclo #0xd287a7
 *   @0x23e560 blhi 0x1a70834 <b2_toiTime+0x1317390>
 *   @0x23e564 svclo #0xc68a28
 *   @0x23e568 ldrshpl r7, [pc], r11
 *   @0x23e56c svclo #0xd34413
 *   @0x23e570 vldmdbls sp!, {s31}
 *   @0x23e574 ldclo p13, c2, [r4], {22}
 *   @0x23e578 andseq r3, r11, r8, ror #24
 *   @0x23e57c .word 0xfffff8b8
 *   @0x23e580 ldrdeq r4, r5, [pc], -r8
 *   @0x23e584 strheq r4, [pc], -r4
 *   @0x23e588 andseq r7, r1, r0, lsl #5
 *   @0x23e58c .word 0xfffff8bc
 *   @0x23e590 mov r0, #0
 *   @0x23e594 str r0, [sp, #0x34]
 *   @0x23e598 ldr r1, [sp, #0x7c]
 *   @0x23e59c cmp r1, #0
 *   @0x23e5a0 ble 0x23ee40 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe70>
 *   @0x23e5a4 cmp r1, #14
 *   @0x23e5a8 movhi r2, #0
 *   @0x23e5ac movls r2, #1
 *   @0x23e5b0 ldr lr, [sp, #0x7c]
 *   @0x23e5b4 and r2, r2, r3
 *   @0x23e5b8 str r2, [sp, #0x3c]
 *   @0x23e5bc str lr, [sp, #0x4c]
 *   @0x23e5c0 mov r0, lr
 *   @0x23e5c4 str lr, [sp, #0x44]
 *   @0x23e5c8 str lr, [sp, #0x20]
 *   @0x23e5cc b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398>
 *   @0x23e5d0 mov r2, #1
 *   @0x23e5d4 str r2, [sp, #0x34]
 *   @0x23e5d8 b 0x23e598 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5c8>
 *   @0x23e5dc vmov s4, r11
 *   @0x23e5e0 vldr d7, [pc, #960]
 *   @0x23e5e4 mvn r3, #0
 *   @0x23e5e8 mov r1, #0
 *   @0x23e5ec vcvt.f64.s32 d6, s4
 *   @0x23e5f0 str r3, [sp, #0x44]
 *   @0x23e5f4 str r3, [sp, #0x20]
 *   @0x23e5f8 mov r3, #1
 *   @0x23e5fc str r1, [sp, #0x3c]
 *   @0x23e600 str r1, [sp, #0x7c]
 *   @0x23e604 str r3, [sp, #0x34]
 *   @0x23e608 vmul.f64 d7, d6, d7
 *   @0x23e60c vcvt.s32.f64 s4, d7
 *   @0x23e610 vmov r0, s4
 *   @0x23e614 add r0, r0, #3
 *   @0x23e618 str r0, [sp, #0x4c]
 *   @0x23e61c b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398>
 *   @0x23e620 vstr d3, [sp, #24]
 *   @0x23e624 cmp r6, #0
 *   @0x23e628 blt 0x23e6e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x710>
 *   @0x23e62c ldr r3, [r8, #0x14]
 *   @0x23e630 ldr r2, [sp, #0x10]
 *   @0x23e634 cmp r2, r3
 *   @0x23e638 bgt 0x23e6e0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x710>
 *   @0x23e63c ldr lr, [sp, #0x7c]
 *   @0x23e640 ldr r3, [pc, #0x368]
 *   @0x23e644 ldr r0, [sp, #0x20]
 *   @0x23e648 lsr r10, lr, #31
 *   @0x23e64c cmp r0, #0
 *   @0x23e650 movgt r10, #0
 *   @0x23e654 andle r10, r10, #1
 *   @0x23e658 ldr r3, [r7, r3]
 *   @0x23e65c cmp r10, #0
 *   @0x23e660 add r3, r3, r2, lsl #3
 *   @0x23e664 vldr d6, [r3]
 *   @0x23e668 beq 0x23ec74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xca4>
 *   @0x23e66c cmp r0, #0
 *   @0x23e670 bne 0x23eb2c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb5c>
 *   @0x23e674 vmov.f64 d7, #5.000000e+00
 *   @0x23e678 vldr d2, [sp, #24]
 *   @0x23e67c vmul.f64 d6, d6, d7
 *   @0x23e680 vcmpe.f64 d6, d2
 *   @0x23e684 vmrs APSR_nzcv, fpscr
 *   @0x23e688 bge 0x23f078 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10a8>
 *   @0x23e68c add r11, r2, #2
 *   @0x23e690 mov r7, r0
 *   @0x23e694 mov r6, r0
 *   @0x23e698 ldr r0, [sp, #0x2c]
 *   @0x23e69c mov r2, #0
 *   @0x23e6a0 mov r10, #32
 *   @0x23e6a4 mov r3, #49
 *   @0x23e6a8 add r9, r0, #1
 *   @0x23e6ac strb r3, [r0]
 *   @0x23e6b0 mov r0, r7
 *   @0x23e6b4 str r2, [sp, #0x4]
 *   @0x23e6b8 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e6bc cmp r6, #0
 *   @0x23e6c0 ldr r2, [sp, #0x4]
 *   @0x23e6c4 beq 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23e6c8 cmp r2, r6
 *   @0x23e6cc cmpne r2, #0
 *   @0x23e6d0 bne 0x23ebcc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xbfc>
 *   @0x23e6d4 mov r0, r6
 *   @0x23e6d8 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e6dc b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23e6e0 ldr r3, [sp, #0x34]
 *   @0x23e6e4 cmp r3, #0
 *   @0x23e6e8 beq 0x23e954 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x984>
 *   @0x23e6ec ldr r2, [sp, #0x24]
 *   @0x23e6f0 ldr r3, [r8, #0x4]
 *   @0x23e6f4 rsb r11, r2, r11
 *   @0x23e6f8 rsb r2, r11, r6
 *   @0x23e6fc add r11, r11, #1
 *   @0x23e700 cmp r2, r3
 *   @0x23e704 str r11, [sp, #0x4c]
 *   @0x23e708 bge 0x23eb64 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb94>
 *   @0x23e70c ldr lr, [sp, #0x78]
 *   @0x23e710 cmp lr, #3
 *   @0x23e714 cmpne lr, #5
 *   @0x23e718 beq 0x23eb64 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb94>
 *   @0x23e71c ldr r2, [sp, #0x78]
 *   @0x23e720 rsb r3, r3, r6
 *   @0x23e724 ldr lr, [sp, #0x20]
 *   @0x23e728 add r11, r3, #1
 *   @0x23e72c str r11, [sp, #0x4c]
 *   @0x23e730 cmp r2, #1
 *   @0x23e734 cmpgt lr, #0
 *   @0x23e738 ble 0x23e748 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x778>
 *   @0x23e73c ldr r3, [sp, #0x20]
 *   @0x23e740 cmp r3, r11
 *   @0x23e744 blt 0x23eb70 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xba0>
 *   @0x23e748 ldr r7, [sp, #0x30]
 *   @0x23e74c ldr r9, [sp, #0x28]
 *   @0x23e750 ldr r2, [sp, #0x28]
 *   @0x23e754 mov r0, #1
 *   @0x23e758 add r12, r12, r11
 *   @0x23e75c str r12, [sp, #0x4]
 *   @0x23e760 add r2, r2, r11
 *   @0x23e764 str r2, [sp, #0x28]
 *   @0x23e768 bl 0x23d478 <i2b_D2A>
 *   @0x23e76c ldr r12, [sp, #0x4]
 *   @0x23e770 mov r6, r0
 *   @0x23e774 cmp r12, #0
 *   @0x23e778 cmpgt r9, #0
 *   @0x23e77c ble 0x23e7a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x7d4>
 *   @0x23e780 cmp r12, r9
 *   @0x23e784 movlt r3, r12
 *   @0x23e788 movge r3, r9
 *   @0x23e78c ldr r2, [sp, #0x28]
 *   @0x23e790 rsb r9, r3, r9
 *   @0x23e794 rsb r12, r3, r12
 *   @0x23e798 rsb r2, r3, r2
 *   @0x23e79c str r3, [sp, #0x4c]
 *   @0x23e7a0 str r2, [sp, #0x28]
 *   @0x23e7a4 ldr r3, [sp, #0x30]
 *   @0x23e7a8 cmp r3, #0
 *   @0x23e7ac ble 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830>
 *   @0x23e7b0 ldr r3, [sp, #0x34]
 *   @0x23e7b4 cmp r3, #0
 *   @0x23e7b8 beq 0x23ee24 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe54>
 *   @0x23e7bc cmp r7, #0
 *   @0x23e7c0 ble 0x23e7f4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x824>
 *   @0x23e7c4 mov r0, r6
 *   @0x23e7c8 mov r1, r7
 *   @0x23e7cc str r12, [sp, #0x4]
 *   @0x23e7d0 bl 0x23d5ec <pow5mult_D2A>
 *   @0x23e7d4 mov r1, r5
 *   @0x23e7d8 mov r6, r0
 *   @0x23e7dc bl 0x23d498 <mult_D2A>
 *   @0x23e7e0 mov r3, r0
 *   @0x23e7e4 mov r0, r5
 *   @0x23e7e8 mov r5, r3
 *   @0x23e7ec bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e7f0 ldr r12, [sp, #0x4]
 *   @0x23e7f4 ldr r2, [sp, #0x30]
 *   @0x23e7f8 subs r1, r2, r7
 *   @0x23e7fc bne 0x23eee0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf10>
 *   @0x23e800 mov r0, #1
 *   @0x23e804 str r12, [sp, #0x4]
 *   @0x23e808 bl 0x23d478 <i2b_D2A>
 *   @0x23e80c ldr r3, [sp, #0x38]
 *   @0x23e810 ldr r12, [sp, #0x4]
 *   @0x23e814 cmp r3, #0
 *   @0x23e818 mov r7, r0
 *   @0x23e81c ble 0x23e830 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x860>
 *   @0x23e820 mov r1, r3
 *   @0x23e824 bl 0x23d5ec <pow5mult_D2A>
 *   @0x23e828 ldr r12, [sp, #0x4]
 *   @0x23e82c mov r7, r0
 *   @0x23e830 ldr lr, [sp, #0x78]
 *   @0x23e834 cmp lr, #1
 *   @0x23e838 ble 0x23ed2c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd5c>
 *   @0x23e83c mov r8, #0
 *   @0x23e840 ldr r2, [sp, #0x38]
 *   @0x23e844 cmp r2, #0
 *   @0x23e848 moveq r0, #31
 *   @0x23e84c bne 0x23ebe4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc14>
 *   @0x23e850 rsb r10, r12, r0
 *   @0x23e854 ldr r3, [sp, #0x28]
 *   @0x23e858 sub r10, r10, #4
 *   @0x23e85c and r10, r10, #31
 *   @0x23e860 str r10, [sp, #0x4c]
 *   @0x23e864 add r1, r3, r10
 *   @0x23e868 cmp r1, #0
 *   @0x23e86c movle r1, r10
 *   @0x23e870 ble 0x23e88c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8bc>
 *   @0x23e874 mov r0, r5
 *   @0x23e878 str r12, [sp, #0x4]
 *   @0x23e87c bl 0x23d6cc <lshift_D2A>
 *   @0x23e880 ldr r1, [sp, #0x4c]
 *   @0x23e884 ldr r12, [sp, #0x4]
 *   @0x23e888 mov r5, r0
 *   @0x23e88c add r1, r12, r1
 *   @0x23e890 cmp r1, #0
 *   @0x23e894 ble 0x23e8a4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8d4>
 *   @0x23e898 mov r0, r7
 *   @0x23e89c bl 0x23d6cc <lshift_D2A>
 *   @0x23e8a0 mov r7, r0
 *   @0x23e8a4 ldr r2, [sp, #0x40]
 *   @0x23e8a8 cmp r2, #0
 *   @0x23e8ac bne 0x23ec00 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc30>
 *   @0x23e8b0 ldr r1, [sp, #0x20]
 *   @0x23e8b4 ldr r2, [sp, #0x78]
 *   @0x23e8b8 cmp r1, #0
 *   @0x23e8bc movgt r3, #0
 *   @0x23e8c0 movle r3, #1
 *   @0x23e8c4 cmp r2, #2
 *   @0x23e8c8 movle r3, #0
 *   @0x23e8cc cmp r3, #0
 *   @0x23e8d0 beq 0x23e964 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x994>
 *   @0x23e8d4 ldr r3, [sp, #0x20]
 *   @0x23e8d8 cmp r3, #0
 *   @0x23e8dc bne 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64>
 *   @0x23e8e0 mov r0, r7
 *   @0x23e8e4 mov r2, r3
 *   @0x23e8e8 mov r1, #5
 *   @0x23e8ec bl 0x23d368 <multadd_D2A>
 *   @0x23e8f0 mov r7, r0
 *   @0x23e8f4 mov r0, r5
 *   @0x23e8f8 mov r1, r7
 *   @0x23e8fc bl 0x23d7c8 <cmp_D2A>
 *   @0x23e900 cmp r0, #0
 *   @0x23e904 ble 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64>
 *   @0x23e908 ldr r3, [sp, #0x10]
 *   @0x23e90c add r11, r3, #2
 *   @0x23e910 b 0x23e698 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6c8>
 *   @0x23e914 ldr r2, [sp, #0x28]
 *   @0x23e918 ldr lr, [sp, #0x10]
 *   @0x23e91c rsb r2, lr, r2
 *   @0x23e920 str r2, [sp, #0x28]
 *   @0x23e924 rsb r2, lr, #0
 *   @0x23e928 str r2, [sp, #0x30]
 *   @0x23e92c mov r2, #0
 *   @0x23e930 str r2, [sp, #0x38]
 *   @0x23e934 b 0x23e290 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x2c0>
 *   @0x23e938 vcvt.f64.s32 d6, s7
 *   @0x23e93c vcmp.f64 d6, d7
 *   @0x23e940 vmrs APSR_nzcv, fpscr
 *   @0x23e944 vmovne r0, s7
 *   @0x23e948 subne r0, r0, #1
 *   @0x23e94c strne r0, [sp, #0x10]
 *   @0x23e950 b 0x23e20c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x23c>
 *   @0x23e954 ldr r7, [sp, #0x30]
 *   @0x23e958 ldr r9, [sp, #0x28]
 *   @0x23e95c ldr r6, [sp, #0x34]
 *   @0x23e960 b 0x23e774 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x7a4>
 *   @0x23e964 ldr r3, [sp, #0x34]
 *   @0x23e968 cmp r3, #0
 *   @0x23e96c beq 0x23ed60 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd90>
 *   @0x23e970 add r1, r9, r10
 *   @0x23e974 cmp r1, #0
 *   @0x23e978 ble 0x23e988 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9b8>
 *   @0x23e97c mov r0, r6
 *   @0x23e980 bl 0x23d6cc <lshift_D2A>
 *   @0x23e984 mov r6, r0
 *   @0x23e988 cmp r8, #0
 *   @0x23e98c moveq r8, r6
 *   @0x23e990 bne 0x23f100 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1130>
 *   @0x23e994 mov r3, #1
 *   @0x23e998 ldr r9, [sp, #0x2c]
 *   @0x23e99c str r3, [sp, #0x4c]
 *   @0x23e9a0 str r4, [sp, #0x18]
 *   @0x23e9a4 b 0x23ea84 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xab4>
 *   @0x23e9a8 strbpl r5, [r7, #-0xa32]
 *   @0x23e9ac svclo #0xd34413
 *   @0x23e9b0 .word 0xfffff8bc
 *   @0x23e9b4 mov r0, r3
 *   @0x23e9b8 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23e9bc ldr r0, [sp, #0x78]
 *   @0x23e9c0 orrs r0, r4, r0
 *   @0x23e9c4 bne 0x23e9e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa14>
 *   @0x23e9c8 ldr r1, [sp, #0xc]
 *   @0x23e9cc ldr r3, [r1]
 *   @0x23e9d0 tst r3, #1
 *   @0x23e9d4 bne 0x23e9e4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa14>
 *   @0x23e9d8 ldr r3, [sp, #0x14]
 *   @0x23e9dc cmp r3, #0
 *   @0x23e9e0 beq 0x23f2b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12e0>
 *   @0x23e9e4 cmp r10, #0
 *   @0x23e9e8 blt 0x23efc4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xff4>
 *   @0x23e9ec ldr lr, [sp, #0x78]
 *   @0x23e9f0 orrs lr, r10, lr
 *   @0x23e9f4 bne 0x23ea08 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xa38>
 *   @0x23e9f8 ldr r0, [sp, #0xc]
 *   @0x23e9fc ldr r3, [r0]
 *   @0x23ea00 tst r3, #1
 *   @0x23ea04 beq 0x23efc4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xff4>
 *   @0x23ea08 ldr r3, [sp, #0x14]
 *   @0x23ea0c cmp r3, #2
 *   @0x23ea10 cmpne r4, #0
 *   @0x23ea14 movle r4, #0
 *   @0x23ea18 movgt r4, #1
 *   @0x23ea1c bgt 0x23f194 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11c4>
 *   @0x23ea20 strb r11, [r9], #1
 *   @0x23ea24 ldr r3, [sp, #0x4c]
 *   @0x23ea28 ldr lr, [sp, #0x20]
 *   @0x23ea2c cmp r3, lr
 *   @0x23ea30 beq 0x23f184 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11b4>
 *   @0x23ea34 mov r0, r5
 *   @0x23ea38 mov r1, #10
 *   @0x23ea3c mov r2, r4
 *   @0x23ea40 bl 0x23d368 <multadd_D2A>
 *   @0x23ea44 cmp r6, r8
 *   @0x23ea48 mov r5, r0
 *   @0x23ea4c mov r0, r6
 *   @0x23ea50 beq 0x23eb4c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb7c>
 *   @0x23ea54 mov r1, #10
 *   @0x23ea58 mov r2, r4
 *   @0x23ea5c bl 0x23d368 <multadd_D2A>
 *   @0x23ea60 mov r2, r4
 *   @0x23ea64 mov r1, #10
 *   @0x23ea68 mov r6, r0
 *   @0x23ea6c mov r0, r8
 *   @0x23ea70 bl 0x23d368 <multadd_D2A>
 *   @0x23ea74 mov r8, r0
 *   @0x23ea78 ldr r3, [sp, #0x4c]
 *   @0x23ea7c add r3, r3, #1
 *   @0x23ea80 str r3, [sp, #0x4c]
 *   @0x23ea84 mov r1, r7
 *   @0x23ea88 mov r0, r5
 *   @0x23ea8c bl 0x23ddac <quorem_D2A>
 *   @0x23ea90 mov r1, r6
 *   @0x23ea94 str r0, [sp, #0x8]
 *   @0x23ea98 mov r0, r5
 *   @0x23ea9c bl 0x23d7c8 <cmp_D2A>
 *   @0x23eaa0 mov r1, r8
 *   @0x23eaa4 mov r10, r0
 *   @0x23eaa8 mov r0, r7
 *   @0x23eaac bl 0x23d828 <diff_D2A>
 *   @0x23eab0 ldr lr, [sp, #0x8]
 *   @0x23eab4 add r11, lr, #48
 *   @0x23eab8 ldr r2, [r0, #0xc]
 *   @0x23eabc mov r3, r0
 *   @0x23eac0 cmp r2, #0
 *   @0x23eac4 movne r4, #1
 *   @0x23eac8 bne 0x23e9b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9e4>
 *   @0x23eacc mov r1, r3
 *   @0x23ead0 mov r0, r5
 *   @0x23ead4 str r3, [sp, #0x4]
 *   @0x23ead8 bl 0x23d7c8 <cmp_D2A>
 *   @0x23eadc ldr r3, [sp, #0x4]
 *   @0x23eae0 mov r4, r0
 *   @0x23eae4 b 0x23e9b4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9e4>
 *   @0x23eae8 vadd.f64 d6, d3, d3
 *   @0x23eaec vmov.f64 d7, #7.000000e+00
 *   @0x23eaf0 vadd.f64 d2, d6, d7
 *   @0x23eaf4 vstr d2, [sp, #24]
 *   @0x23eaf8 ldr r0, [sp, #0x1c]
 *   @0x23eafc sub r0, r0, #54525952
 *   @0x23eb00 str r0, [sp, #0x1c]
 *   @0x23eb04 vmov.f64 d7, #5.000000e+00
 *   @0x23eb08 vldr d6, [sp, #24]
 *   @0x23eb0c vsub.f64 d7, d3, d7
 *   @0x23eb10 vcmpe.f64 d7, d6
 *   @0x23eb14 vmrs APSR_nzcv, fpscr
 *   @0x23eb18 bgt 0x23ef30 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf60>
 *   @0x23eb1c vneg.f64 d6, d6
 *   @0x23eb20 vcmpe.f64 d7, d6
 *   @0x23eb24 vmrs APSR_nzcv, fpscr
 *   @0x23eb28 bpl 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650>
 *   @0x23eb2c mov r7, #0
 *   @0x23eb30 mov r6, r7
 *   @0x23eb34 ldr lr, [sp, #0x7c]
 *   @0x23eb38 mov r2, #0
 *   @0x23eb3c ldr r9, [sp, #0x2c]
 *   @0x23eb40 mov r10, #16
 *   @0x23eb44 rsb r11, lr, #0
 *   @0x23eb48 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23eb4c mov r2, r4
 *   @0x23eb50 mov r1, #10
 *   @0x23eb54 bl 0x23d368 <multadd_D2A>
 *   @0x23eb58 mov r6, r0
 *   @0x23eb5c mov r8, r0
 *   @0x23eb60 b 0x23ea78 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xaa8>
 *   @0x23eb64 ldr r1, [sp, #0x78]
 *   @0x23eb68 cmp r1, #1
 *   @0x23eb6c ble 0x23e748 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x778>
 *   @0x23eb70 ldr r3, [sp, #0x20]
 *   @0x23eb74 ldr r2, [sp, #0x30]
 *   @0x23eb78 sub r7, r3, #1
 *   @0x23eb7c cmp r2, r7
 *   @0x23eb80 rsbge r7, r7, r2
 *   @0x23eb84 ldrlt r2, [sp, #0x30]
 *   @0x23eb88 strlt r7, [sp, #0x30]
 *   @0x23eb8c rsblt r3, r2, r7
 *   @0x23eb90 ldrlt r2, [sp, #0x38]
 *   @0x23eb94 movlt r7, #0
 *   @0x23eb98 addlt r2, r2, r3
 *   @0x23eb9c ldr r3, [sp, #0x20]
 *   @0x23eba0 strlt r2, [sp, #0x38]
 *   @0x23eba4 cmp r3, #0
 *   @0x23eba8 strge r3, [sp, #0x4c]
 *   @0x23ebac ldrlt r2, [sp, #0x28]
 *   @0x23ebb0 movlt r11, #0
 *   @0x23ebb4 ldrlt r3, [sp, #0x20]
 *   @0x23ebb8 movge r11, r3
 *   @0x23ebbc ldrge r9, [sp, #0x28]
 *   @0x23ebc0 rsblt r9, r3, r2
 *   @0x23ebc4 strlt r11, [sp, #0x4c]
 *   @0x23ebc8 b 0x23e750 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x780>
 *   @0x23ebcc mov r0, r2
 *   @0x23ebd0 bl 0x23d2a0 <Bfree_D2A>
 *   @0x23ebd4 b 0x23e6d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x704>
 *   @0x23ebd8 mov lr, #1
 *   @0x23ebdc str lr, [sp, #0x34]
 *   @0x23ebe0 b 0x23e330 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x360>
 *   @0x23ebe4 ldr r3, [r7, #0x10]
 *   @0x23ebe8 add r3, r7, r3, lsl #2
 *   @0x23ebec ldr r0, [r3, #0x10]
 *   @0x23ebf0 str r12, [sp, #0x4]
 *   @0x23ebf4 bl 0x23d41c <hi0bits_D2A>
 *   @0x23ebf8 ldr r12, [sp, #0x4]
 *   @0x23ebfc b 0x23e850 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x880>
 *   @0x23ec00 mov r0, r5
 *   @0x23ec04 mov r1, r7
 *   @0x23ec08 bl 0x23d7c8 <cmp_D2A>
 *   @0x23ec0c cmp r0, #0
 *   @0x23ec10 bge 0x23e8b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x8e0>
 *   @0x23ec14 ldr r3, [sp, #0x10]
 *   @0x23ec18 mov r0, r5
 *   @0x23ec1c mov r1, #10
 *   @0x23ec20 mov r2, #0
 *   @0x23ec24 sub r3, r3, #1
 *   @0x23ec28 str r3, [sp, #0x10]
 *   @0x23ec2c bl 0x23d368 <multadd_D2A>
 *   @0x23ec30 ldr r3, [sp, #0x34]
 *   @0x23ec34 cmp r3, #0
 *   @0x23ec38 mov r5, r0
 *   @0x23ec3c bne 0x23f300 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1330>
 *   @0x23ec40 ldr r0, [sp, #0x44]
 *   @0x23ec44 ldr r1, [sp, #0x78]
 *   @0x23ec48 cmp r0, #0
 *   @0x23ec4c movgt r3, #0
 *   @0x23ec50 movle r3, #1
 *   @0x23ec54 cmp r1, #2
 *   @0x23ec58 movle r3, #0
 *   @0x23ec5c cmp r3, #0
 *   @0x23ec60 streq r0, [sp, #0x20]
 *   @0x23ec64 beq 0x23ed60 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd90>
 *   @0x23ec68 ldr r3, [sp, #0x44]
 *   @0x23ec6c str r3, [sp, #0x20]
 *   @0x23ec70 b 0x23e8d4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x904>
 *   @0x23ec74 vldr d7, [sp, #24]
 *   @0x23ec78 vdiv.f64 d5, d7, d6
 *   @0x23ec7c ldr r0, [sp, #0x2c]
 *   @0x23ec80 ldr r3, [sp, #0x2c]
 *   @0x23ec84 add r9, r3, #1
 *   @0x23ec88 mov r3, #1
 *   @0x23ec8c str r3, [sp, #0x4c]
 *   @0x23ec90 mov r2, r9
 *   @0x23ec94 vcvt.s32.f64 s7, d5
 *   @0x23ec98 vcvt.f64.s32 d4, s7
 *   @0x23ec9c vmov lr, s7
 *   @0x23eca0 vmls.f64 d7, d4, d6
 *   @0x23eca4 add r3, lr, #48
 *   @0x23eca8 strb r3, [r0]
 *   @0x23ecac vcmp.f64 d7, #0
 *   @0x23ecb0 vmrs APSR_nzcv, fpscr
 *   @0x23ecb4 ldreq r3, [sp, #0x10]
 *   @0x23ecb8 addeq r11, r3, #1
 *   @0x23ecbc beq 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23ecc0 ldr r3, [sp, #0x4c]
 *   @0x23ecc4 ldr lr, [sp, #0x20]
 *   @0x23ecc8 cmp lr, r3
 *   @0x23eccc vmovne.f64 d4, #1.000000e+01
 *   @0x23ecd0 ldrne r1, [sp, #0x20]
 *   @0x23ecd4 bne 0x23ece8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd18>
 *   @0x23ecd8 b 0x23eef8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf28>
 *   @0x23ecdc ldr r3, [sp, #0x4c]
 *   @0x23ece0 cmp r1, r3
 *   @0x23ece4 beq 0x23eef8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf28>
 *   @0x23ece8 vmul.f64 d7, d7, d4
 *   @0x23ecec add r3, r3, #1
 *   @0x23ecf0 str r3, [sp, #0x4c]
 *   @0x23ecf4 vdiv.f64 d5, d7, d6
 *   @0x23ecf8 vcvt.s32.f64 s7, d5
 *   @0x23ecfc vcvt.f64.s32 d5, s7
 *   @0x23ed00 vmov r0, s7
 *   @0x23ed04 vmls.f64 d7, d5, d6
 *   @0x23ed08 add r3, r0, #48
 *   @0x23ed0c strb r3, [r9], #1
 *   @0x23ed10 vcmp.f64 d7, #0
 *   @0x23ed14 vmrs APSR_nzcv, fpscr
 *   @0x23ed18 bne 0x23ecdc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xd0c>
 *   @0x23ed1c ldr r3, [sp, #0x10]
 *   @0x23ed20 add r11, r3, #1
 *   @0x23ed24 mov r10, #0
 *   @0x23ed28 b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23ed2c ldr r2, [sp, #0x24]
 *   @0x23ed30 cmp r2, #1
 *   @0x23ed34 bne 0x23e83c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x86c>
 *   @0x23ed38 ldr r3, [r8, #0x4]
 *   @0x23ed3c add r3, r3, #1
 *   @0x23ed40 cmp r10, r3
 *   @0x23ed44 ble 0x23e83c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x86c>
 *   @0x23ed48 ldr r3, [sp, #0x28]
 *   @0x23ed4c add r12, r12, #1
 *   @0x23ed50 mov r8, r2
 *   @0x23ed54 add r3, r3, #1
 *   @0x23ed58 str r3, [sp, #0x28]
 *   @0x23ed5c b 0x23e840 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x870>
 *   @0x23ed60 mov r3, #1
 *   @0x23ed64 ldr r9, [sp, #0x2c]
 *   @0x23ed68 str r3, [sp, #0x4c]
 *   @0x23ed6c ldr r8, [sp, #0x20]
 *   @0x23ed70 b 0x23ed88 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xdb8>
 *   @0x23ed74 bl 0x23d368 <multadd_D2A>
 *   @0x23ed78 ldr r3, [sp, #0x4c]
 *   @0x23ed7c add r3, r3, #1
 *   @0x23ed80 str r3, [sp, #0x4c]
 *   @0x23ed84 mov r5, r0
 *   @0x23ed88 mov r1, r7
 *   @0x23ed8c mov r0, r5
 *   @0x23ed90 bl 0x23ddac <quorem_D2A>
 *   @0x23ed94 mov r1, #10
 *   @0x23ed98 mov r2, #0
 *   @0x23ed9c add r11, r0, #48
 *   @0x23eda0 strb r11, [r9], #1
 *   @0x23eda4 ldr r3, [sp, #0x4c]
 *   @0x23eda8 mov r0, r5
 *   @0x23edac cmp r8, r3
 *   @0x23edb0 bgt 0x23ed74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xda4>
 *   @0x23edb4 mov r2, #0
 *   @0x23edb8 ldr r3, [sp, #0x14]
 *   @0x23edbc cmp r3, #0
 *   @0x23edc0 beq 0x23f084 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10b4>
 *   @0x23edc4 cmp r3, #2
 *   @0x23edc8 beq 0x23f0b8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10e8>
 *   @0x23edcc ldr r3, [r5, #0x10]
 *   @0x23edd0 cmp r3, #1
 *   @0x23edd4 ble 0x23f258 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1288>
 *   @0x23edd8 ldrb r1, [r9, #-0x1]
 *   @0x23eddc ldr lr, [sp, #0x2c]
 *   @0x23ede0 mov r3, r9
 *   @0x23ede4 add r12, lr, #1
 *   @0x23ede8 b 0x23edfc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe2c>
 *   @0x23edec cmp r9, r12
 *   @0x23edf0 beq 0x23ef18 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf48>
 *   @0x23edf4 ldrb r1, [r3, #-0x2]
 *   @0x23edf8 mov r3, r0
 *   @0x23edfc cmp r1, #57
 *   @0x23ee00 mov r9, r3
 *   @0x23ee04 sub r0, r3, #1
 *   @0x23ee08 beq 0x23edec <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe1c>
 *   @0x23ee0c ldr r3, [sp, #0x10]
 *   @0x23ee10 add r1, r1, #1
 *   @0x23ee14 mov r10, #32
 *   @0x23ee18 strb r1, [r0]
 *   @0x23ee1c add r11, r3, #1
 *   @0x23ee20 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23ee24 mov r0, r5
 *   @0x23ee28 ldr r1, [sp, #0x30]
 *   @0x23ee2c str r12, [sp, #0x4]
 *   @0x23ee30 bl 0x23d5ec <pow5mult_D2A>
 *   @0x23ee34 ldr r12, [sp, #0x4]
 *   @0x23ee38 mov r5, r0
 *   @0x23ee3c b 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830>
 *   @0x23ee40 mov r2, #1
 *   @0x23ee44 str r2, [sp, #0x7c]
 *   @0x23ee48 b 0x23e5b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x5e0>
 *   @0x23ee4c ldr r0, [sp, #0x20]
 *   @0x23ee50 cmp r0, #14
 *   @0x23ee54 movhi r3, #0
 *   @0x23ee58 andls r3, r3, #1
 *   @0x23ee5c str r3, [sp, #0x3c]
 *   @0x23ee60 mov r3, #1
 *   @0x23ee64 str r3, [sp, #0x4c]
 *   @0x23ee68 mov r0, r3
 *   @0x23ee6c b 0x23e368 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x398>
 *   @0x23ee70 vadd.f64 d7, d7, d7
 *   @0x23ee74 vcmpe.f64 d6, d7
 *   @0x23ee78 vmrs APSR_nzcv, fpscr
 *   @0x23ee7c bmi 0x23f234 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1264>
 *   @0x23ee80 vcmp.f64 d6, d7
 *   @0x23ee84 vmrs APSR_nzcv, fpscr
 *   @0x23ee88 bne 0x23f2a0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12d0>
 *   @0x23ee8c vmov lr, s7
 *   @0x23ee90 tst lr, #1
 *   @0x23ee94 beq 0x23f2a0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12d0>
 *   @0x23ee98 ldrb r3, [r9, #-0x1]
 *   @0x23ee9c ldr r0, [sp, #0x10]
 *   @0x23eea0 mov r1, r9
 *   @0x23eea4 b 0x23eeb8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xee8>
 *   @0x23eea8 cmp r9, r2
 *   @0x23eeac beq 0x23f0ec <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x111c>
 *   @0x23eeb0 ldrb r3, [r1, #-0x2]
 *   @0x23eeb4 mov r1, r12
 *   @0x23eeb8 cmp r3, #57
 *   @0x23eebc mov r9, r1
 *   @0x23eec0 sub r12, r1, #1
 *   @0x23eec4 beq 0x23eea8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed8>
 *   @0x23eec8 add r3, r3, #1
 *   @0x23eecc uxtb r3, r3
 *   @0x23eed0 strb r3, [r12]
 *   @0x23eed4 add r11, r0, #1
 *   @0x23eed8 mov r10, #32
 *   @0x23eedc b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23eee0 mov r0, r5
 *   @0x23eee4 str r12, [sp, #0x4]
 *   @0x23eee8 bl 0x23d5ec <pow5mult_D2A>
 *   @0x23eeec ldr r12, [sp, #0x4]
 *   @0x23eef0 mov r5, r0
 *   @0x23eef4 b 0x23e800 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x830>
 *   @0x23eef8 ldr r3, [sp, #0x14]
 *   @0x23eefc cmp r3, #0
 *   @0x23ef00 beq 0x23ee70 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xea0>
 *   @0x23ef04 cmp r3, #1
 *   @0x23ef08 beq 0x23f234 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1264>
 *   @0x23ef0c ldr r3, [sp, #0x10]
 *   @0x23ef10 add r11, r3, #1
 *   @0x23ef14 b 0x23e518 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x548>
 *   @0x23ef18 ldr r3, [sp, #0x10]
 *   @0x23ef1c mov r10, #32
 *   @0x23ef20 add r11, r3, #2
 *   @0x23ef24 mov r3, #49
 *   @0x23ef28 strb r3, [r0]
 *   @0x23ef2c b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23ef30 mov r7, #0
 *   @0x23ef34 mov r11, #2
 *   @0x23ef38 mov r6, r7
 *   @0x23ef3c b 0x23e698 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6c8>
 *   @0x23ef40 ldr r3, [pc, #-0x598]
 *   @0x23ef44 mov r2, #1
 *   @0x23ef48 vldr d2, [sp, #24]
 *   @0x23ef4c vmov.f64 d6, #1.000000e+01
 *   @0x23ef50 ldr r9, [sp, #0x2c]
 *   @0x23ef54 ldr r3, [r7, r3]
 *   @0x23ef58 str r2, [sp, #0x4c]
 *   @0x23ef5c add r3, r3, r1, lsl #3
 *   @0x23ef60 vldr d4, [r3, #-8]
 *   @0x23ef64 vmul.f64 d4, d4, d2
 *   @0x23ef68 b 0x23ef74 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xfa4>
 *   @0x23ef6c vmul.f64 d7, d7, d6
 *   @0x23ef70 str r2, [sp, #0x4c]
 *   @0x23ef74 vcvt.s32.f64 s5, d7
 *   @0x23ef78 vmov r2, s5
 *   @0x23ef7c cmp r2, #0
 *   @0x23ef80 add r3, r2, #48
 *   @0x23ef84 vcvtne.f64.s32 d5, s5
 *   @0x23ef88 uxtb r3, r3
 *   @0x23ef8c strb r3, [r9], #1
 *   @0x23ef90 ldr r2, [sp, #0x4c]
 *   @0x23ef94 vsubne.f64 d7, d7, d5
 *   @0x23ef98 cmp r2, r1
 *   @0x23ef9c add r2, r2, #1
 *   @0x23efa0 bne 0x23ef6c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf9c>
 *   @0x23efa4 vmov.f64 d6, #5.000000e-01
 *   @0x23efa8 vadd.f64 d5, d4, d6
 *   @0x23efac vcmpe.f64 d5, d7
 *   @0x23efb0 vmrs APSR_nzcv, fpscr
 *   @0x23efb4 bpl 0x23f1f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1220>
 *   @0x23efb8 ldr r1, [sp, #0x2c]
 *   @0x23efbc add r2, r1, #1
 *   @0x23efc0 b 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0>
 *   @0x23efc4 ldr r3, [sp, #0x14]
 *   @0x23efc8 mov r2, r4
 *   @0x23efcc ldr r4, [sp, #0x18]
 *   @0x23efd0 cmp r3, #0
 *   @0x23efd4 beq 0x23f1d0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1200>
 *   @0x23efd8 ldr r1, [r5, #0x10]
 *   @0x23efdc cmp r1, #1
 *   @0x23efe0 ble 0x23f1c4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x11f4>
 *   @0x23efe4 ldr r3, [sp, #0x14]
 *   @0x23efe8 cmp r3, #2
 *   @0x23efec bne 0x23f02c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x105c>
 *   @0x23eff0 b 0x23f1e8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1218>
 *   @0x23eff4 strb r11, [r9], #1
 *   @0x23eff8 bl 0x23d368 <multadd_D2A>
 *   @0x23effc cmp r6, r8
 *   @0x23f000 mov r1, #10
 *   @0x23f004 mov r2, #0
 *   @0x23f008 mov r10, r0
 *   @0x23f00c mov r0, r5
 *   @0x23f010 moveq r6, r10
 *   @0x23f014 bl 0x23d368 <multadd_D2A>
 *   @0x23f018 mov r1, r7
 *   @0x23f01c mov r8, r10
 *   @0x23f020 mov r5, r0
 *   @0x23f024 bl 0x23ddac <quorem_D2A>
 *   @0x23f028 add r11, r0, #48
 *   @0x23f02c mov r1, r8
 *   @0x23f030 mov r0, r7
 *   @0x23f034 bl 0x23d7c8 <cmp_D2A>
 *   @0x23f038 mov r2, #0
 *   @0x23f03c mov r1, #10
 *   @0x23f040 cmp r0, r2
 *   @0x23f044 mov r0, r8
 *   @0x23f048 bgt 0x23eff4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1024>
 *   @0x23f04c cmp r11, #57
 *   @0x23f050 beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270>
 *   @0x23f054 add r11, r11, #1
 *   @0x23f058 mov r10, #32
 *   @0x23f05c strb r11, [r9]
 *   @0x23f060 mov r2, r6
 *   @0x23f064 ldr r3, [sp, #0x10]
 *   @0x23f068 add r9, r9, #1
 *   @0x23f06c mov r6, r8
 *   @0x23f070 add r11, r3, #1
 *   @0x23f074 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23f078 ldr r7, [sp, #0x20]
 *   @0x23f07c mov r6, r7
 *   @0x23f080 b 0x23eb34 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb64>
 *   @0x23f084 mov r0, r5
 *   @0x23f088 mov r1, #1
 *   @0x23f08c str r2, [sp, #0x4]
 *   @0x23f090 bl 0x23d6cc <lshift_D2A>
 *   @0x23f094 mov r1, r7
 *   @0x23f098 mov r5, r0
 *   @0x23f09c bl 0x23d7c8 <cmp_D2A>
 *   @0x23f0a0 ldr r2, [sp, #0x4]
 *   @0x23f0a4 cmp r0, #0
 *   @0x23f0a8 bgt 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08>
 *   @0x23f0ac bne 0x23f0b8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10e8>
 *   @0x23f0b0 tst r11, #1
 *   @0x23f0b4 bne 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08>
 *   @0x23f0b8 ldr r3, [r5, #0x10]
 *   @0x23f0bc cmp r3, #1
 *   @0x23f0c0 ble 0x23f350 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1380>
 *   @0x23f0c4 mov r10, #16
 *   @0x23f0c8 mov r3, r9
 *   @0x23f0cc mov r9, r3
 *   @0x23f0d0 sub r3, r3, #1
 *   @0x23f0d4 ldrb r1, [r9, #-0x1]
 *   @0x23f0d8 cmp r1, #48
 *   @0x23f0dc beq 0x23f0cc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10fc>
 *   @0x23f0e0 ldr r3, [sp, #0x10]
 *   @0x23f0e4 add r11, r3, #1
 *   @0x23f0e8 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23f0ec mov r2, #48
 *   @0x23f0f0 add r0, r0, #1
 *   @0x23f0f4 mov r3, #49
 *   @0x23f0f8 strb r2, [r12]
 *   @0x23f0fc b 0x23eed0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xf00>
 *   @0x23f100 ldr r0, [r6, #0x4]
 *   @0x23f104 bl 0x23d1f8 <Balloc_D2A>
 *   @0x23f108 ldr r2, [r6, #0x10]
 *   @0x23f10c add r1, r6, #12
 *   @0x23f110 lsl r2, r2, #2
 *   @0x23f114 add r2, r2, #8
 *   @0x23f118 mov r8, r0
 *   @0x23f11c add r0, r0, #12
 *   @0x23f120 bl 0xb65bc <memcpy@plt>
 *   @0x23f124 mov r0, r8
 *   @0x23f128 mov r1, #1
 *   @0x23f12c bl 0x23d6cc <lshift_D2A>
 *   @0x23f130 mov r8, r0
 *   @0x23f134 b 0x23e994 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9c4>
 *   @0x23f138 ldr r3, [sp, #0x20]
 *   @0x23f13c cmp r3, #0
 *   @0x23f140 beq 0x23eae8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xb18>
 *   @0x23f144 ldr r3, [sp, #0x44]
 *   @0x23f148 cmp r3, #0
 *   @0x23f14c ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650>
 *   @0x23f150 vmov.f64 d7, #1.000000e+01
 *   @0x23f154 mov r1, r3
 *   @0x23f158 mvn r0, #0
 *   @0x23f15c vmul.f64 d7, d3, d7
 *   @0x23f160 vmov.f64 d6, #7.000000e+00
 *   @0x23f164 vmov.f64 d5, #3.000000e+00
 *   @0x23f168 vmov.f64 d2, d6
 *   @0x23f16c vmla.f64 d2, d7, d5
 *   @0x23f170 vstr d2, [sp, #24]
 *   @0x23f174 ldr r2, [sp, #0x1c]
 *   @0x23f178 sub r2, r2, #54525952
 *   @0x23f17c str r2, [sp, #0x1c]
 *   @0x23f180 b 0x23e418 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x448>
 *   @0x23f184 mov r2, r6
 *   @0x23f188 ldr r4, [sp, #0x18]
 *   @0x23f18c mov r6, r8
 *   @0x23f190 b 0x23edb8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xde8>
 *   @0x23f194 cmp r11, #57
 *   @0x23f198 ldr r4, [sp, #0x18]
 *   @0x23f19c beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270>
 *   @0x23f1a0 add r3, r11, #1
 *   @0x23f1a4 strb r3, [r9]
 *   @0x23f1a8 ldr r3, [sp, #0x10]
 *   @0x23f1ac mov r2, r6
 *   @0x23f1b0 add r9, r9, #1
 *   @0x23f1b4 mov r6, r8
 *   @0x23f1b8 add r11, r3, #1
 *   @0x23f1bc mov r10, #32
 *   @0x23f1c0 b 0x23e6b0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x6e0>
 *   @0x23f1c4 ldr r1, [r5, #0x14]
 *   @0x23f1c8 cmp r1, #0
 *   @0x23f1cc bne 0x23efe4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1014>
 *   @0x23f1d0 cmp r2, #0
 *   @0x23f1d4 bgt 0x23f268 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1298>
 *   @0x23f1d8 mov r10, #0
 *   @0x23f1dc ldr r2, [r5, #0x10]
 *   @0x23f1e0 cmp r2, #1
 *   @0x23f1e4 ble 0x23f2f0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1320>
 *   @0x23f1e8 mov r10, #16
 *   @0x23f1ec b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c>
 *   @0x23f1f0 vsub.f64 d6, d6, d4
 *   @0x23f1f4 vcmpe.f64 d6, d7
 *   @0x23f1f8 vmrs APSR_nzcv, fpscr
 *   @0x23f1fc ble 0x23e620 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x650>
 *   @0x23f200 vcmp.f64 d7, #0
 *   @0x23f204 vmrs APSR_nzcv, fpscr
 *   @0x23f208 movne r10, #16
 *   @0x23f20c moveq r10, #0
 *   @0x23f210 mov r2, r9
 *   @0x23f214 b 0x23f220 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1250>
 *   @0x23f218 ldrb r3, [r2, #-0x2]
 *   @0x23f21c sub r2, r2, #1
 *   @0x23f220 cmp r3, #48
 *   @0x23f224 mov r9, r2
 *   @0x23f228 beq 0x23f218 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1248>
 *   @0x23f22c add r11, r0, #1
 *   @0x23f230 b 0x23e51c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x54c>
 *   @0x23f234 ldr r0, [sp, #0x10]
 *   @0x23f238 ldrb r3, [r9, #-0x1]
 *   @0x23f23c b 0x23eea0 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xed0>
 *   @0x23f240 mov r1, #57
 *   @0x23f244 mov r2, r6
 *   @0x23f248 strb r1, [r9]
 *   @0x23f24c mov r6, r8
 *   @0x23f250 add r9, r9, #1
 *   @0x23f254 b 0x23eddc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe0c>
 *   @0x23f258 ldr r10, [r5, #0x14]
 *   @0x23f25c cmp r10, #0
 *   @0x23f260 beq 0x23f0c8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f8>
 *   @0x23f264 b 0x23edd8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xe08>
 *   @0x23f268 mov r0, r5
 *   @0x23f26c mov r1, #1
 *   @0x23f270 bl 0x23d6cc <lshift_D2A>
 *   @0x23f274 mov r1, r7
 *   @0x23f278 mov r5, r0
 *   @0x23f27c bl 0x23d7c8 <cmp_D2A>
 *   @0x23f280 cmp r0, #0
 *   @0x23f284 ble 0x23f340 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1370>
 *   @0x23f288 cmp r11, #57
 *   @0x23f28c beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270>
 *   @0x23f290 ldr r2, [sp, #0x8]
 *   @0x23f294 add r11, r2, #49
 *   @0x23f298 mov r10, #32
 *   @0x23f29c b 0x23f1dc <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x120c>
 *   @0x23f2a0 ldr r0, [sp, #0x10]
 *   @0x23f2a4 mov r10, #16
 *   @0x23f2a8 ldrb r3, [r9, #-0x1]
 *   @0x23f2ac b 0x23f210 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1240>
 *   @0x23f2b0 cmp r11, #57
 *   @0x23f2b4 ldr r4, [sp, #0x18]
 *   @0x23f2b8 beq 0x23f240 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1270>
 *   @0x23f2bc cmp r10, #0
 *   @0x23f2c0 ldrgt r2, [sp, #0x8]
 *   @0x23f2c4 movgt r10, #32
 *   @0x23f2c8 addgt r11, r2, #49
 *   @0x23f2cc bgt 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c>
 *   @0x23f2d0 ldr r2, [r5, #0x10]
 *   @0x23f2d4 cmp r2, #1
 *   @0x23f2d8 bgt 0x23f1e8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x1218>
 *   @0x23f2dc ldr r10, [r5, #0x14]
 *   @0x23f2e0 cmp r10, #0
 *   @0x23f2e4 movne r10, #16
 *   @0x23f2e8 moveq r10, #0
 *   @0x23f2ec b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c>
 *   @0x23f2f0 ldr r2, [r5, #0x14]
 *   @0x23f2f4 cmp r2, #0
 *   @0x23f2f8 movne r10, #16
 *   @0x23f2fc b 0x23f05c <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x108c>
 *   @0x23f300 mov r0, r6
 *   @0x23f304 mov r1, #10
 *   @0x23f308 mov r2, #0
 *   @0x23f30c bl 0x23d368 <multadd_D2A>
 *   @0x23f310 ldr lr, [sp, #0x44]
 *   @0x23f314 cmp lr, #0
 *   @0x23f318 movgt r3, #0
 *   @0x23f31c movle r3, #1
 *   @0x23f320 mov r6, r0
 *   @0x23f324 ldr r0, [sp, #0x78]
 *   @0x23f328 cmp r0, #2
 *   @0x23f32c movle r3, #0
 *   @0x23f330 cmp r3, #0
 *   @0x23f334 streq lr, [sp, #0x20]
 *   @0x23f338 beq 0x23e970 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x9a0>
 *   @0x23f33c b 0x23ec68 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0xc98>
 *   @0x23f340 bne 0x23f298 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12c8>
 *   @0x23f344 tst r11, #1
 *   @0x23f348 beq 0x23f298 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12c8>
 *   @0x23f34c b 0x23f288 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x12b8>
 *   @0x23f350 ldr r10, [r5, #0x14]
 *   @0x23f354 cmp r10, #0
 *   @0x23f358 bne 0x23f0c4 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f4>
 *   @0x23f35c b 0x23f0c8 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x10f8>
 *   @0x23f360 mov r0, #0
 *   @0x23f364 b 0x23e120 <_Z5gdtoaP3FPIiPjPiiiS2_PPc+0x150>
 *
 * ══ §3/7 pcre_exec  0x279390  size 4408  1102 条（0x279390..0x27a4c8）
 * @func 0x279390 0x27a4c8  size 4408  1102 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: pcre_exec+0x734×3 / _pcre_is_newline×3 / anon_26f1e8×2 / _pcre_was_newline×2 / pcre_exec+0xf74 / pcre_exec+0xf7c / _pcre_valid_utf / pcre_exec+0x390
 * 字段偏移 top8: 0x98×11 / 0x16c×10 / 0x20×10 / 0x1×10 / 0x168×8 / 0x9c×8 / 0x68×8 / 0x5c×8
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x279390 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x279394 mov r7, r1
 *   @0x279398 rsbs r1, r0, #1
 *   @0x27939c sub sp, sp, #316
 *   @0x2793a0 ldr r11, [pc, #0xf94]
 *   @0x2793a4 mov r4, r0
 *   @0x2793a8 movlo r1, #0
 *   @0x2793ac cmp r7, #0
 *   @0x2793b0 cmpeq r0, #0
 *   @0x2793b4 add r11, pc, r11
 *   @0x2793b8 mov r6, r2
 *   @0x2793bc str r11, [sp, #0x14]
 *   @0x2793c0 ldr r5, [sp, #0x164]
 *   @0x2793c4 bne 0x2793dc <pcre_exec+0x4c>
 *   @0x2793c8 movw r2, #0xfc19
 *   @0x2793cc movt r2, #0xffff
 *   @0x2793d0 cmp r6, #0
 *   @0x2793d4 cmpeq r3, r2
 *   @0x2793d8 beq 0x27947c <pcre_exec+0xec>
 *   @0x2793dc movw r2, #0x5a6f
 *   @0x2793e0 movt r2, #0xe20f
 *   @0x2793e4 and r2, r5, r2
 *   @0x2793e8 cmp r2, #0
 *   @0x2793ec bne 0x27a058 <pcre_exec+0xcc8>
 *   @0x2793f0 cmp r6, #0
 *   @0x2793f4 orreq r1, r1, #1
 *   @0x2793f8 cmp r1, #0
 *   @0x2793fc bne 0x27970c <pcre_exec+0x37c>
 *   @0x279400 ldr r11, [sp, #0x168]
 *   @0x279404 ldr r12, [sp, #0x16c]
 *   @0x279408 rsbs r2, r11, #1
 *   @0x27940c movlo r2, #0
 *   @0x279410 cmp r12, #0
 *   @0x279414 movle r2, #0
 *   @0x279418 cmp r2, #0
 *   @0x27941c bne 0x27970c <pcre_exec+0x37c>
 *   @0x279420 cmp r12, #0
 *   @0x279424 blt 0x27a304 <pcre_exec+0xf74>
 *   @0x279428 cmp r3, #0
 *   @0x27942c blt 0x27a30c <pcre_exec+0xf7c>
 *   @0x279430 ldr r11, [sp, #0x160]
 *   @0x279434 lsr r2, r11, #31
 *   @0x279438 cmp r11, r3
 *   @0x27943c orrgt r2, r2, #1
 *   @0x279440 str r2, [sp, #0x18]
 *   @0x279444 cmp r2, #0
 *   @0x279448 bne 0x27a0c0 <pcre_exec+0xd30>
 *   @0x27944c ldr r1, [r4]
 *   @0x279450 movw r2, #0x5245
 *   @0x279454 movt r2, #0x5043
 *   @0x279458 cmp r1, r2
 *   @0x27945c beq 0x2794b4 <pcre_exec+0x124>
 *   @0x279460 movw r3, #0x4350
 *   @0x279464 movt r3, #0x4552
 *   @0x279468 cmp r1, r3
 *   @0x27946c mvnne r0, #3
 *   @0x279470 mvneq r0, #28
 *   @0x279474 add sp, sp, #316
 *   @0x279478 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x27947c ldr r12, [sp, #0x160]
 *   @0x279480 cmp r12, r2
 *   @0x279484 bne 0x2793dc <pcre_exec+0x4c>
 *   @0x279488 add r0, sp, #312
 *   @0x27948c mov r3, #0
 *   @0x279490 mov r12, #1
 *   @0x279494 str r3, [sp]
 *   @0x279498 str r3, [sp, #0x4]
 *   @0x27949c mov r1, r3
 *   @0x2794a0 str r3, [r0, #-0xb8]!
 *   @0x2794a4 mov r2, r3
 *   @0x2794a8 str r12, [sp, #0x8]
 *   @0x2794ac bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x2794b0 b 0x279474 <pcre_exec+0xe4>
 *   @0x2794b4 ldr r2, [r4, #0xc]
 *   @0x2794b8 tst r2, #1
 *   @0x2794bc beq 0x27a334 <pcre_exec+0xfa4>
 *   @0x2794c0 ldr r8, [r4, #0x8]
 *   @0x2794c4 tst r5, #134217728
 *   @0x2794c8 ubfxeq r1, r5, #0xf, #0x1
 *   @0x2794cc ubfx r12, r8, #0xb, #0x1
 *   @0x2794d0 str r12, [sp, #0x1c]
 *   @0x2794d4 ldr r11, [sp, #0x1c]
 *   @0x2794d8 movne r1, #2
 *   @0x2794dc str r12, [sp, #0xcc]
 *   @0x2794e0 cmp r11, #0
 *   @0x2794e4 ldr r12, [sp, #0x160]
 *   @0x2794e8 str r1, [sp, #0x108]
 *   @0x2794ec add r12, r6, r12
 *   @0x2794f0 str r12, [sp, #0x24]
 *   @0x2794f4 bne 0x279664 <pcre_exec+0x2d4>
 *   @0x2794f8 str r2, [sp, #0x20]
 *   @0x2794fc ldrh r9, [r4, #38]
 *   @0x279500 cmp r7, #0
 *   @0x279504 ldrh r10, [r4, #36]
 *   @0x279508 movw r1, #0x9680
 *   @0x27950c ldrh r12, [r4, #34]
 *   @0x279510 movt r1, #0x98
 *   @0x279514 str r9, [sp, #0xa0]
 *   @0x279518 add r0, r4, r12
 *   @0x27951c str r1, [sp, #0x84]
 *   @0x279520 str r0, [sp, #0xb0]
 *   @0x279524 mov r0, #0
 *   @0x279528 str r1, [sp, #0x88]
 *   @0x27952c str r0, [sp, #0x128]
 *   @0x279530 str r10, [sp, #0xa4]
 *   @0x279534 ldr r0, [r4, #0x30]
 *   @0x279538 streq r7, [sp, #0x34]
 *   @0x27953c beq 0x27957c <pcre_exec+0x1ec>
 *   @0x279540 ldr r1, [r7]
 *   @0x279544 ands r11, r1, #1
 *   @0x279548 ldrne r11, [r7, #0x4]
 *   @0x27954c tst r1, #2
 *   @0x279550 str r11, [sp, #0x34]
 *   @0x279554 ldrne r11, [r7, #0x8]
 *   @0x279558 strne r11, [sp, #0x84]
 *   @0x27955c tst r1, #16
 *   @0x279560 ldrne r11, [r7, #0x14]
 *   @0x279564 strne r11, [sp, #0x88]
 *   @0x279568 tst r1, #4
 *   @0x27956c ldrne r11, [r7, #0xc]
 *   @0x279570 strne r11, [sp, #0x128]
 *   @0x279574 tst r1, #8
 *   @0x279578 ldrne r0, [r7, #0x10]
 *   @0x27957c tst r2, #8192
 *   @0x279580 beq 0x279594 <pcre_exec+0x204>
 *   @0x279584 ldr r1, [r4, #0x10]
 *   @0x279588 ldr r11, [sp, #0x84]
 *   @0x27958c cmp r1, r11
 *   @0x279590 strlo r1, [sp, #0x84]
 *   @0x279594 tst r2, #16384
 *   @0x279598 beq 0x2795ac <pcre_exec+0x21c>
 *   @0x27959c ldr r1, [r4, #0x14]
 *   @0x2795a0 ldr r11, [sp, #0x88]
 *   @0x2795a4 cmp r1, r11
 *   @0x2795a8 strlo r1, [sp, #0x88]
 *   @0x2795ac cmp r0, #0
 *   @0x2795b0 beq 0x27a120 <pcre_exec+0xd90>
 *   @0x2795b4 mla r12, r10, r9, r12
 *   @0x2795b8 and r1, r5, #25165824
 *   @0x2795bc cmp r1, #8388608
 *   @0x2795c0 add r11, r6, r3
 *   @0x2795c4 ubfx r9, r8, #0x1d, #0x1
 *   @0x2795c8 ubfx r3, r8, #0x5, #0x1
 *   @0x2795cc add r12, r4, r12
 *   @0x2795d0 str r12, [sp, #0xf0]
 *   @0x2795d4 ldr r12, [sp, #0x160]
 *   @0x2795d8 str r0, [sp, #0xb8]
 *   @0x2795dc str r3, [sp, #0xd8]
 *   @0x2795e0 mov r3, #0
 *   @0x2795e4 str r12, [sp, #0x114]
 *   @0x2795e8 ubfx r12, r8, #0x19, #0x1
 *   @0x2795ec str r9, [sp, #0xd4]
 *   @0x2795f0 ubfx r9, r5, #0x7, #0x1
 *   @0x2795f4 str r12, [sp, #0xd0]
 *   @0x2795f8 ubfx r12, r5, #0x8, #0x1
 *   @0x2795fc str r9, [sp, #0xc4]
 *   @0x279600 ubfx r9, r5, #0xa, #0x1
 *   @0x279604 str r12, [sp, #0xc8]
 *   @0x279608 ubfx r12, r5, #0x1c, #0x1
 *   @0x27960c str r9, [sp, #0xdc]
 *   @0x279610 ubfx r9, r2, #0xc, #0x1
 *   @0x279614 str r12, [sp, #0xe0]
 *   @0x279618 add r12, r0, #256
 *   @0x27961c str r6, [sp, #0xf4]
 *   @0x279620 add r0, r0, #832
 *   @0x279624 str r11, [sp, #0xf8]
 *   @0x279628 str r3, [sp, #0xac]
 *   @0x27962c str r3, [sp, #0xe4]
 *   @0x279630 str r3, [sp, #0x130]
 *   @0x279634 str r3, [sp, #0x12c]
 *   @0x279638 str r3, [sp, #0x124]
 *   @0x27963c str r9, [sp, #0xec]
 *   @0x279640 str r12, [sp, #0xbc]
 *   @0x279644 str r0, [sp, #0xc0]
 *   @0x279648 beq 0x279714 <pcre_exec+0x384>
 *   @0x27964c cmp r1, #16777216
 *   @0x279650 beq 0x2796d4 <pcre_exec+0x344>
 *   @0x279654 cmp r1, r3
 *   @0x279658 beq 0x2796c4 <pcre_exec+0x334>
 *   @0x27965c mvn r0, #22
 *   @0x279660 b 0x279474 <pcre_exec+0xe4>
 *   @0x279664 tst r5, #8192
 *   @0x279668 bne 0x2794f8 <pcre_exec+0x168>
 *   @0x27966c mov r1, r3
 *   @0x279670 mov r0, r6
 *   @0x279674 add r2, sp, #124
 *   @0x279678 str r3, [sp, #0x10]
 *   @0x27967c bl 0x2668f4 <_pcre_valid_utf>
 *   @0x279680 ldr r3, [sp, #0x10]
 *   @0x279684 cmp r0, #0
 *   @0x279688 beq 0x27a280 <pcre_exec+0xef0>
 *   @0x27968c ldr r11, [sp, #0x16c]
 *   @0x279690 cmp r11, #1
 *   @0x279694 ldrgt r12, [sp, #0x168]
 *   @0x279698 ldrgt r3, [sp, #0x7c]
 *   @0x27969c strgt r0, [r12, #0x4]
 *   @0x2796a0 strgt r3, [r12]
 *   @0x2796a4 cmp r0, #5
 *   @0x2796a8 mvngt r0, #9
 *   @0x2796ac bgt 0x279474 <pcre_exec+0xe4>
 *   @0x2796b0 ldr r3, [sp, #0x108]
 *   @0x2796b4 cmp r3, #1
 *   @0x2796b8 mvngt r0, #24
 *   @0x2796bc mvnle r0, #9
 *   @0x2796c0 b 0x279474 <pcre_exec+0xe4>
 *   @0x2796c4 ands r3, r8, #25165824
 *   @0x2796c8 ubfxne r3, r8, #0x17, #0x1
 *   @0x2796cc strne r3, [sp, #0xe8]
 *   @0x2796d0 bne 0x2796d8 <pcre_exec+0x348>
 *   @0x2796d4 str r3, [sp, #0xe8]
 *   @0x2796d8 ands r3, r5, #7340032
 *   @0x2796dc andeq r3, r8, #7340032
 *   @0x2796e0 cmp r3, #2097152
 *   @0x2796e4 beq 0x279be0 <pcre_exec+0x850>
 *   @0x2796e8 bls 0x279720 <pcre_exec+0x390>
 *   @0x2796ec cmp r3, #4194304
 *   @0x2796f0 beq 0x27a130 <pcre_exec+0xda0>
 *   @0x2796f4 cmp r3, #5242880
 *   @0x2796f8 beq 0x279bd4 <pcre_exec+0x844>
 *   @0x2796fc cmp r3, #3145728
 *   @0x279700 bne 0x27965c <pcre_exec+0x2cc>
 *   @0x279704 movw r3, #0xd0a
 *   @0x279708 b 0x279734 <pcre_exec+0x3a4>
 *   @0x27970c mvn r0, #1
 *   @0x279710 b 0x279474 <pcre_exec+0xe4>
 *   @0x279714 mov r3, #1
 *   @0x279718 str r3, [sp, #0xe8]
 *   @0x27971c b 0x2796d8 <pcre_exec+0x348>
 *   @0x279720 cmp r3, #0
 *   @0x279724 beq 0x279be0 <pcre_exec+0x850>
 *   @0x279728 cmp r3, #1048576
 *   @0x27972c moveq r3, #13
 *   @0x279730 bne 0x27965c <pcre_exec+0x2cc>
 *   @0x279734 cmp r3, #255
 *   @0x279738 mov r1, #0
 *   @0x27973c str r1, [sp, #0x98]
 *   @0x279740 ble 0x279bec <pcre_exec+0x85c>
 *   @0x279744 strb r3, [sp, #0xb5]
 *   @0x279748 asr r3, r3, #8
 *   @0x27974c strb r3, [sp, #0xb4]
 *   @0x279750 mov r3, #2
 *   @0x279754 str r3, [sp, #0x9c]
 *   @0x279758 ldr r3, [sp, #0x108]
 *   @0x27975c cmp r3, #0
 *   @0x279760 beq 0x27976c <pcre_exec+0x3dc>
 *   @0x279764 tst r2, #512
 *   @0x279768 bne 0x27a44c <pcre_exec+0x10bc>
 *   @0x27976c ldr r12, [sp, #0x16c]
 *   @0x279770 movw r10, #0x5556
 *   @0x279774 movt r10, #0x5555
 *   @0x279778 ldrh r1, [r4, #32]
 *   @0x27977c smull r12, r9, r10, r12
 *   @0x279780 ldr r12, [sp, #0x16c]
 *   @0x279784 cmp r1, #0
 *   @0x279788 sub r9, r9, r12, asr #31
 *   @0x27978c add r9, r9, r9, lsl #1
 *   @0x279790 lsl r3, r9, #1
 *   @0x279794 smull r12, r0, r10, r3
 *   @0x279798 sub r0, r0, r3, asr #31
 *   @0x27979c str r0, [sp, #0x4c]
 *   @0x2797a0 beq 0x2797b4 <pcre_exec+0x424>
 *   @0x2797a4 smull r0, r3, r10, r9
 *   @0x2797a8 sub r3, r3, r9, asr #31
 *   @0x2797ac cmp r1, r3
 *   @0x2797b0 bge 0x27a200 <pcre_exec+0xe70>
 *   @0x2797b4 ldr r12, [sp, #0x168]
 *   @0x2797b8 mov r3, #0
 *   @0x2797bc str r9, [sp, #0x90]
 *   @0x2797c0 cmp r12, #0
 *   @0x2797c4 str r3, [sp, #0x110]
 *   @0x2797c8 str r12, [sp, #0x8c]
 *   @0x2797cc ldr r12, [sp, #0x4c]
 *   @0x2797d0 str r12, [sp, #0x94]
 *   @0x2797d4 beq 0x27a1f4 <pcre_exec+0xe64>
 *   @0x2797d8 ldr r2, [sp, #0x168]
 *   @0x2797dc lsl r1, r9, #2
 *   @0x2797e0 str r3, [sp, #0x70]
 *   @0x2797e4 ldrh r0, [r4, #30]
 *   @0x2797e8 add r1, r2, r1
 *   @0x2797ec sub r3, r1, #4
 *   @0x2797f0 add r12, r2, #8
 *   @0x2797f4 sub r1, r1, r0, lsl #2
 *   @0x2797f8 cmp r1, r12
 *   @0x2797fc movlo r1, r12
 *   @0x279800 cmp r3, r1
 *   @0x279804 mvnhs r0, #0
 *   @0x279808 blo 0x279818 <pcre_exec+0x488>
 *   @0x27980c str r0, [r3], #-4
 *   @0x279810 cmp r3, r1
 *   @0x279814 bhs 0x27980c <pcre_exec+0x47c>
 *   @0x279818 ldr r12, [sp, #0x16c]
 *   @0x27981c cmp r12, #0
 *   @0x279820 beq 0x279838 <pcre_exec+0x4a8>
 *   @0x279824 ldr r12, [sp, #0x16c]
 *   @0x279828 mvn r3, #0
 *   @0x27982c str r3, [r2]
 *   @0x279830 cmp r12, #1
 *   @0x279834 strne r3, [r2, #0x4]
 *   @0x279838 ldr r2, [r4, #0xc]
 *   @0x27983c orr r3, r8, r5
 *   @0x279840 ldr r12, [sp, #0x20]
 *   @0x279844 ubfx r3, r3, #0x4, #0x1
 *   @0x279848 str r3, [sp, #0x20]
 *   @0x27984c cmp r3, #0
 *   @0x279850 ubfx r12, r12, #0x8, #0x1
 *   @0x279854 str r12, [sp, #0x6c]
 *   @0x279858 beq 0x279fc0 <pcre_exec+0xc30>
 *   @0x27985c mov r12, #0
 *   @0x279860 str r12, [sp, #0x40]
 *   @0x279864 str r12, [sp, #0x64]
 *   @0x279868 str r12, [sp, #0x54]
 *   @0x27986c ands r3, r2, #64
 *   @0x279870 beq 0x279fb0 <pcre_exec+0xc20>
 *   @0x279874 ldrb r0, [r4, #0x1a]
 *   @0x279878 tst r2, #128
 *   @0x27987c str r0, [sp, #0x68]
 *   @0x279880 beq 0x27a0c8 <pcre_exec+0xd38>
 *   @0x279884 ldr r3, [sp, #0xbc]
 *   @0x279888 mov r1, #1
 *   @0x27988c str r1, [sp, #0x74]
 *   @0x279890 ldrb r3, [r3, r0]
 *   @0x279894 str r3, [sp, #0x60]
 *   @0x279898 ldr r9, [sp, #0x24]
 *   @0x27989c movw r2, #0xfc1d
 *   @0x2798a0 str r6, [sp, #0x48]
 *   @0x2798a4 movt r2, #0xffff
 *   @0x2798a8 ldr r6, [sp, #0x64]
 *   @0x2798ac mov r0, #0
 *   @0x2798b0 str r2, [sp, #0x58]
 *   @0x2798b4 mov r2, #0
 *   @0x2798b8 ldr r3, [sp, #0x24]
 *   @0x2798bc mov r10, r2
 *   @0x2798c0 str r7, [sp, #0x44]
 *   @0x2798c4 mov r7, r9
 *   @0x2798c8 mov r9, r5
 *   @0x2798cc mov r5, r12
 *   @0x2798d0 ubfx r8, r8, #0x12, #0x1
 *   @0x2798d4 str r0, [sp, #0x38]
 *   @0x2798d8 movw r1, #0xfc1e
 *   @0x2798dc sub r3, r3, #1
 *   @0x2798e0 movt r1, #0xffff
 *   @0x2798e4 add r0, sp, #156
 *   @0x2798e8 str r1, [sp, #0x2c]
 *   @0x2798ec add r1, sp, #128
 *   @0x2798f0 str r8, [sp, #0x28]
 *   @0x2798f4 str r3, [sp, #0x5c]
 *   @0x2798f8 str r0, [sp, #0x30]
 *   @0x2798fc str r1, [sp, #0x3c]
 *   @0x279900 str r2, [sp, #0x50]
 *   @0x279904 ldr r12, [sp, #0x28]
 *   @0x279908 cmp r12, #0
 *   @0x27990c moveq r8, r11
 *   @0x279910 beq 0x27998c <pcre_exec+0x5fc>
 *   @0x279914 ldr r12, [sp, #0x1c]
 *   @0x279918 mov r8, r7
 *   @0x27991c ldr r2, [sp, #0xf8]
 *   @0x279920 cmp r12, #0
 *   @0x279924 bne 0x279b5c <pcre_exec+0x7cc>
 *   @0x279928 cmp r7, r2
 *   @0x27992c blo 0x279948 <pcre_exec+0x5b8>
 *   @0x279930 b 0x27998c <pcre_exec+0x5fc>
 *   @0x279934 cmp r8, r2
 *   @0x279938 blo 0x279d2c <pcre_exec+0x99c>
 *   @0x27993c add r8, r8, #1
 *   @0x279940 cmp r2, r8
 *   @0x279944 bls 0x27998c <pcre_exec+0x5fc>
 *   @0x279948 ldr r1, [sp, #0x98]
 *   @0x27994c cmp r1, #0
 *   @0x279950 bne 0x279934 <pcre_exec+0x5a4>
 *   @0x279954 ldr r3, [sp, #0x9c]
 *   @0x279958 rsb r1, r3, r2
 *   @0x27995c cmp r8, r1
 *   @0x279960 bhi 0x27993c <pcre_exec+0x5ac>
 *   @0x279964 ldrb r0, [r8]
 *   @0x279968 ldrb r1, [sp, #0xb4]
 *   @0x27996c cmp r0, r1
 *   @0x279970 bne 0x27993c <pcre_exec+0x5ac>
 *   @0x279974 cmp r3, #1
 *   @0x279978 beq 0x27998c <pcre_exec+0x5fc>
 *   @0x27997c ldrb r1, [r8, #0x1]
 *   @0x279980 ldrb r3, [sp, #0xb5]
 *   @0x279984 cmp r1, r3
 *   @0x279988 bne 0x27993c <pcre_exec+0x5ac>
 *   @0x27998c ldr r3, [r4, #0x8]
 *   @0x279990 orr r3, r9, r3
 *   @0x279994 ands r3, r3, #67108864
 *   @0x279998 bne 0x279c3c <pcre_exec+0x8ac>
 *   @0x27999c ldr r12, [sp, #0x54]
 *   @0x2799a0 cmp r12, #0
 *   @0x2799a4 beq 0x279ef0 <pcre_exec+0xb60>
 *   @0x2799a8 cmp r5, r6
 *   @0x2799ac beq 0x27a1b0 <pcre_exec+0xe20>
 *   @0x2799b0 cmp r7, r8
 *   @0x2799b4 bhs 0x2799f4 <pcre_exec+0x664>
 *   @0x2799b8 ldrb r3, [r7]
 *   @0x2799bc cmp r3, r5
 *   @0x2799c0 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x2799c4 cmp r3, r6
 *   @0x2799c8 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x2799cc add r3, r7, #1
 *   @0x2799d0 b 0x2799e8 <pcre_exec+0x658>
 *   @0x2799d4 ldrb r2, [r3], #1
 *   @0x2799d8 cmp r2, r5
 *   @0x2799dc beq 0x2799f4 <pcre_exec+0x664>
 *   @0x2799e0 cmp r2, r6
 *   @0x2799e4 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x2799e8 cmp r3, r8
 *   @0x2799ec mov r7, r3
 *   @0x2799f0 bne 0x2799d4 <pcre_exec+0x644>
 *   @0x2799f4 ldr r3, [sp, #0x108]
 *   @0x2799f8 cmp r3, #0
 *   @0x2799fc bne 0x279c3c <pcre_exec+0x8ac>
 *   @0x279a00 ldr r12, [sp, #0x34]
 *   @0x279a04 cmp r12, #0
 *   @0x279a08 beq 0x279a28 <pcre_exec+0x698>
 *   @0x279a0c ldr r3, [r12, #0x4]
 *   @0x279a10 tst r3, #2
 *   @0x279a14 beq 0x279a28 <pcre_exec+0x698>
 *   @0x279a18 ldr r3, [r12, #0x28]
 *   @0x279a1c rsb r2, r7, r11
 *   @0x279a20 cmp r2, r3
 *   @0x279a24 blo 0x279ac4 <pcre_exec+0x734>
 *   @0x279a28 ldr r12, [sp, #0x74]
 *   @0x279a2c cmp r12, #0
 *   @0x279a30 beq 0x279c3c <pcre_exec+0x8ac>
 *   @0x279a34 rsb r3, r7, r11
 *   @0x279a38 cmp r3, #1000
 *   @0x279a3c bge 0x279c3c <pcre_exec+0x8ac>
 *   @0x279a40 ldr r12, [sp, #0x54]
 *   @0x279a44 add r3, r7, r12
 *   @0x279a48 ldr r12, [sp, #0x5c]
 *   @0x279a4c cmp r12, r3
 *   @0x279a50 bhs 0x279c3c <pcre_exec+0x8ac>
 *   @0x279a54 ldr r12, [sp, #0x68]
 *   @0x279a58 ldr r0, [sp, #0x60]
 *   @0x279a5c cmp r12, r0
 *   @0x279a60 beq 0x27a454 <pcre_exec+0x10c4>
 *   @0x279a64 cmp r11, r3
 *   @0x279a68 bls 0x279ac4 <pcre_exec+0x734>
 *   @0x279a6c add r12, r3, #1
 *   @0x279a70 ldrb r2, [r3]
 *   @0x279a74 str r12, [sp, #0x5c]
 *   @0x279a78 ldr r12, [sp, #0x68]
 *   @0x279a7c cmp r12, r2
 *   @0x279a80 beq 0x27a4a0 <pcre_exec+0x1110>
 *   @0x279a84 ldr r12, [sp, #0x60]
 *   @0x279a88 cmp r12, r2
 *   @0x279a8c beq 0x27a4a0 <pcre_exec+0x1110>
 *   @0x279a90 ldr r2, [sp, #0x5c]
 *   @0x279a94 ldr r0, [sp, #0x68]
 *   @0x279a98 ldr r12, [sp, #0x60]
 *   @0x279a9c b 0x279ab8 <pcre_exec+0x728>
 *   @0x279aa0 ldrb r1, [r3], #1
 *   @0x279aa4 cmp r0, r1
 *   @0x279aa8 beq 0x279c38 <pcre_exec+0x8a8>
 *   @0x279aac cmp r12, r1
 *   @0x279ab0 beq 0x279c38 <pcre_exec+0x8a8>
 *   @0x279ab4 mov r2, r3
 *   @0x279ab8 cmp r2, r11
 *   @0x279abc mov r3, r2
 *   @0x279ac0 bne 0x279aa0 <pcre_exec+0x710>
 *   @0x279ac4 ldr r7, [sp, #0x44]
 *   @0x279ac8 mov r8, #0
 *   @0x279acc ldr r6, [sp, #0x48]
 *   @0x279ad0 ldr r12, [sp, #0x70]
 *   @0x279ad4 cmp r12, #0
 *   @0x279ad8 bne 0x27a264 <pcre_exec+0xed4>
 *   @0x279adc ldr r12, [sp, #0x18]
 *   @0x279ae0 cmp r12, #0
 *   @0x279ae4 movne r0, r8
 *   @0x279ae8 bne 0x279474 <pcre_exec+0xe4>
 *   @0x279aec ldr r12, [sp, #0x38]
 *   @0x279af0 cmp r12, #0
 *   @0x279af4 mvneq r0, #0
 *   @0x279af8 beq 0x279b38 <pcre_exec+0x7a8>
 *   @0x279afc ldr r12, [sp, #0x16c]
 *   @0x279b00 cmp r12, #1
 *   @0x279b04 ble 0x27a1ec <pcre_exec+0xe5c>
 *   @0x279b08 ldr r12, [sp, #0x16c]
 *   @0x279b0c rsb r11, r6, r11
 *   @0x279b10 cmp r12, #2
 *   @0x279b14 ldr r12, [sp, #0x50]
 *   @0x279b18 rsb r3, r6, r12
 *   @0x279b1c ldr r12, [sp, #0x168]
 *   @0x279b20 stm r12, {r3, r11}
 *   @0x279b24 beq 0x27a1ec <pcre_exec+0xe5c>
 *   @0x279b28 ldr r11, [sp, #0x38]
 *   @0x279b2c mvn r0, #11
 *   @0x279b30 rsb r6, r6, r11
 *   @0x279b34 str r6, [r12, #0x8]
 *   @0x279b38 cmp r7, #0
 *   @0x279b3c beq 0x279474 <pcre_exec+0xe4>
 *   @0x279b40 ldr r3, [r7]
 *   @0x279b44 tst r3, #32
 *   @0x279b48 ldrne r3, [r7, #0x18]
 *   @0x279b4c ldrne r2, [sp, #0x130]
 *   @0x279b50 strne r2, [r3]
 *   @0x279b54 b 0x279474 <pcre_exec+0xe4>
 *   @0x279b58 mov r8, r3
 *   @0x279b5c cmp r8, r2
 *   @0x279b60 bhs 0x27998c <pcre_exec+0x5fc>
 *   @0x279b64 ldr r1, [sp, #0x98]
 *   @0x279b68 cmp r1, #0
 *   @0x279b6c beq 0x279bfc <pcre_exec+0x86c>
 *   @0x279b70 mov r0, #1
 *   @0x279b74 add r3, sp, #156
 *   @0x279b78 str r0, [sp]
 *   @0x279b7c mov r0, r8
 *   @0x279b80 bl 0x25f9fc <_pcre_is_newline>
 *   @0x279b84 cmp r0, #0
 *   @0x279b88 bne 0x27998c <pcre_exec+0x5fc>
 *   @0x279b8c ldr r2, [sp, #0xf8]
 *   @0x279b90 add r3, r8, #1
 *   @0x279b94 cmp r11, r3
 *   @0x279b98 bls 0x279b58 <pcre_exec+0x7c8>
 *   @0x279b9c ldrb r1, [r8, #0x1]
 *   @0x279ba0 and r1, r1, #192
 *   @0x279ba4 cmp r1, #128
 *   @0x279ba8 bne 0x279b58 <pcre_exec+0x7c8>
 *   @0x279bac add r3, r8, #2
 *   @0x279bb0 cmp r3, r11
 *   @0x279bb4 mov r8, r3
 *   @0x279bb8 add r3, r3, #1
 *   @0x279bbc beq 0x279b5c <pcre_exec+0x7cc>
 *   @0x279bc0 ldrb r1, [r8]
 *   @0x279bc4 and r1, r1, #192
 *   @0x279bc8 cmp r1, #128
 *   @0x279bcc beq 0x279bb0 <pcre_exec+0x820>
 *   @0x279bd0 b 0x279b5c <pcre_exec+0x7cc>
 *   @0x279bd4 mov r3, #2
 *   @0x279bd8 str r3, [sp, #0x98]
 *   @0x279bdc b 0x279758 <pcre_exec+0x3c8>
 *   @0x279be0 mov r3, #0
 *   @0x279be4 str r3, [sp, #0x98]
 *   @0x279be8 mov r3, #10
 *   @0x279bec strb r3, [sp, #0xb4]
 *   @0x279bf0 mov r3, #1
 *   @0x279bf4 str r3, [sp, #0x9c]
 *   @0x279bf8 b 0x279758 <pcre_exec+0x3c8>
 *   @0x279bfc ldr r3, [sp, #0x9c]
 *   @0x279c00 rsb r1, r3, r2
 *   @0x279c04 cmp r8, r1
 *   @0x279c08 bhi 0x279b90 <pcre_exec+0x800>
 *   @0x279c0c ldrb r0, [r8]
 *   @0x279c10 ldrb r1, [sp, #0xb4]
 *   @0x279c14 cmp r0, r1
 *   @0x279c18 bne 0x279b90 <pcre_exec+0x800>
 *   @0x279c1c cmp r3, #1
 *   @0x279c20 beq 0x27998c <pcre_exec+0x5fc>
 *   @0x279c24 ldrb r1, [r8, #0x1]
 *   @0x279c28 ldrb r3, [sp, #0xb5]
 *   @0x279c2c cmp r1, r3
 *   @0x279c30 bne 0x279b90 <pcre_exec+0x800>
 *   @0x279c34 b 0x27998c <pcre_exec+0x5fc>
 *   @0x279c38 str r2, [sp, #0x5c]
 *   @0x279c3c add r2, sp, #128
 *   @0x279c40 mov r3, #2
 *   @0x279c44 str r2, [sp]
 *   @0x279c48 mov r0, r7
 *   @0x279c4c ldr r1, [sp, #0xf0]
 *   @0x279c50 mov r2, r7
 *   @0x279c54 str r10, [sp, #0x4]
 *   @0x279c58 str r10, [sp, #0x8]
 *   @0x279c5c str r7, [sp, #0xfc]
 *   @0x279c60 str r7, [sp, #0x104]
 *   @0x279c64 str r10, [sp, #0x80]
 *   @0x279c68 str r10, [sp, #0x118]
 *   @0x279c6c str r10, [sp, #0x10c]
 *   @0x279c70 str r10, [sp, #0xa8]
 *   @0x279c74 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x279c78 ldr r3, [sp, #0xe4]
 *   @0x279c7c cmp r3, #0
 *   @0x279c80 beq 0x279c98 <pcre_exec+0x908>
 *   @0x279c84 ldr r12, [sp, #0x50]
 *   @0x279c88 cmp r12, #0
 *   @0x279c8c streq r7, [sp, #0x38]
 *   @0x279c90 ldreq r12, [sp, #0x104]
 *   @0x279c94 streq r12, [sp, #0x50]
 *   @0x279c98 ldr r12, [sp, #0x2c]
 *   @0x279c9c cmp r0, r12
 *   @0x279ca0 beq 0x279e8c <pcre_exec+0xafc>
 *   @0x279ca4 ble 0x279d4c <pcre_exec+0x9bc>
 *   @0x279ca8 cmn r0, #992
 *   @0x279cac beq 0x279e98 <pcre_exec+0xb08>
 *   @0x279cb0 bge 0x279ff4 <pcre_exec+0xc64>
 *   @0x279cb4 ldr r3, [sp, #0xa8]
 *   @0x279cb8 mov r8, r7
 *   @0x279cbc str r3, [sp, #0xac]
 *   @0x279cc0 ldr r12, [sp, #0x28]
 *   @0x279cc4 cmp r12, #0
 *   @0x279cc8 beq 0x279cf4 <pcre_exec+0x964>
 *   @0x279ccc ldr r1, [sp, #0x98]
 *   @0x279cd0 cmp r1, #0
 *   @0x279cd4 beq 0x27a010 <pcre_exec+0xc80>
 *   @0x279cd8 ldr r2, [sp, #0xf8]
 *   @0x279cdc cmp r2, r7
 *   @0x279ce0 movls r0, #0
 *   @0x279ce4 bhi 0x27a2e4 <pcre_exec+0xf54>
 *   @0x279ce8 mov r1, r0
 *   @0x279cec cmp r1, #0
 *   @0x279cf0 bne 0x279ac4 <pcre_exec+0x734>
 *   @0x279cf4 ldr r3, [sp, #0x20]
 *   @0x279cf8 cmp r8, r11
 *   @0x279cfc orrhi r3, r3, #1
 *   @0x279d00 cmp r3, #0
 *   @0x279d04 bne 0x279ac4 <pcre_exec+0x734>
 *   @0x279d08 ldr r12, [sp, #0x24]
 *   @0x279d0c cmp r8, r12
 *   @0x279d10 bls 0x279d20 <pcre_exec+0x990>
 *   @0x279d14 ldrb r3, [r8, #-0x1]
 *   @0x279d18 cmp r3, #13
 *   @0x279d1c beq 0x27a13c <pcre_exec+0xdac>
 *   @0x279d20 str r10, [sp, #0x12c]
 *   @0x279d24 mov r7, r8
 *   @0x279d28 b 0x279904 <pcre_exec+0x574>
 *   @0x279d2c str r10, [sp]
 *   @0x279d30 mov r0, r8
 *   @0x279d34 add r3, sp, #156
 *   @0x279d38 bl 0x25f9fc <_pcre_is_newline>
 *   @0x279d3c cmp r0, #0
 *   @0x279d40 bne 0x27998c <pcre_exec+0x5fc>
 *   @0x279d44 ldr r2, [sp, #0xf8]
 *   @0x279d48 b 0x27993c <pcre_exec+0x5ac>
 *   @0x279d4c cmn r0, #996
 *   @0x279d50 beq 0x279ac4 <pcre_exec+0x734>
 *   @0x279d54 ldr r12, [sp, #0x58]
 *   @0x279d58 cmp r0, r12
 *   @0x279d5c beq 0x279e98 <pcre_exec+0xb08>
 *   @0x279d60 movw r3, #0xfc19
 *   @0x279d64 movt r3, #0xffff
 *   @0x279d68 cmp r0, #1
 *   @0x279d6c cmpne r0, r3
 *   @0x279d70 mov r8, r0
 *   @0x279d74 ldr r7, [sp, #0x44]
 *   @0x279d78 ldr r6, [sp, #0x48]
 *   @0x279d7c bne 0x27a4a8 <pcre_exec+0x1118>
 *   @0x279d80 ldr r11, [sp, #0x70]
 *   @0x279d84 cmp r11, #0
 *   @0x279d88 beq 0x279dcc <pcre_exec+0xa3c>
 *   @0x279d8c ldr r12, [sp, #0x4c]
 *   @0x279d90 ldr r5, [sp, #0x8c]
 *   @0x279d94 cmp r12, #3
 *   @0x279d98 bgt 0x27a314 <pcre_exec+0xf84>
 *   @0x279d9c ldr r3, [sp, #0x10c]
 *   @0x279da0 mov r0, r5
 *   @0x279da4 ldr r11, [sp, #0x4c]
 *   @0x279da8 ldr r12, [sp, #0x14]
 *   @0x279dac cmp r11, r3
 *   @0x279db0 ldrlt r3, [sp, #0x110]
 *   @0x279db4 orrlt r3, r3, #65536
 *   @0x279db8 strlt r3, [sp, #0x110]
 *   @0x279dbc ldr r3, [pc, #0x57c]
 *   @0x279dc0 ldr r3, [r12, r3]
 *   @0x279dc4 ldr r3, [r3]
 *   @0x279dc8 blx r3
 *   @0x279dcc ldr r3, [sp, #0x110]
 *   @0x279dd0 tst r3, #65536
 *   @0x279dd4 ldr r3, [sp, #0x10c]
 *   @0x279dd8 beq 0x27a000 <pcre_exec+0xc70>
 *   @0x279ddc ldr r11, [sp, #0x4c]
 *   @0x279de0 cmp r11, r3
 *   @0x279de4 bgt 0x27a000 <pcre_exec+0xc70>
 *   @0x279de8 add r1, r3, r3, lsr #31
 *   @0x279dec mov r0, #0
 *   @0x279df0 asr r1, r1, #1
 *   @0x279df4 ldrh r2, [r4, #30]
 *   @0x279df8 cmp r1, r2
 *   @0x279dfc bgt 0x279e40 <pcre_exec+0xab0>
 *   @0x279e00 ldr r11, [sp, #0x168]
 *   @0x279e04 cmp r11, #0
 *   @0x279e08 beq 0x279e40 <pcre_exec+0xab0>
 *   @0x279e0c add r2, r2, #1
 *   @0x279e10 ldr r12, [sp, #0x16c]
 *   @0x279e14 add r3, r11, r3, lsl #2
 *   @0x279e18 lsl r2, r2, #1
 *   @0x279e1c cmp r2, r12
 *   @0x279e20 movge r2, r12
 *   @0x279e24 add r2, r11, r2, lsl #2
 *   @0x279e28 cmp r3, r2
 *   @0x279e2c bhs 0x279e40 <pcre_exec+0xab0>
 *   @0x279e30 mvn r1, #0
 *   @0x279e34 str r1, [r3], #4
 *   @0x279e38 cmp r2, r3
 *   @0x279e3c bhi 0x279e34 <pcre_exec+0xaa4>
 *   @0x279e40 ldr r12, [sp, #0x16c]
 *   @0x279e44 cmp r12, #1
 *   @0x279e48 ble 0x27a2dc <pcre_exec+0xf4c>
 *   @0x279e4c ldr r11, [sp, #0x168]
 *   @0x279e50 ldr r3, [sp, #0xf4]
 *   @0x279e54 ldr r1, [sp, #0xfc]
 *   @0x279e58 ldr r2, [sp, #0x100]
 *   @0x279e5c rsb r1, r3, r1
 *   @0x279e60 str r1, [r11]
 *   @0x279e64 rsb r3, r3, r2
 *   @0x279e68 str r3, [r11, #0x4]
 *   @0x279e6c cmp r7, #0
 *   @0x279e70 beq 0x279474 <pcre_exec+0xe4>
 *   @0x279e74 ldr r3, [r7]
 *   @0x279e78 tst r3, #32
 *   @0x279e7c ldrne r3, [r7, #0x18]
 *   @0x279e80 ldrne r2, [sp, #0x12c]
 *   @0x279e84 strne r2, [r3]
 *   @0x279e88 b 0x279474 <pcre_exec+0xe4>
 *   @0x279e8c ldr r8, [sp, #0xfc]
 *   @0x279e90 cmp r8, r7
 *   @0x279e94 bhi 0x279cc0 <pcre_exec+0x930>
 *   @0x279e98 ldr r12, [sp, #0x1c]
 *   @0x279e9c add r8, r7, #1
 *   @0x279ea0 str r10, [sp, #0xac]
 *   @0x279ea4 cmp r12, #0
 *   @0x279ea8 beq 0x279cc0 <pcre_exec+0x930>
 *   @0x279eac cmp r11, r8
 *   @0x279eb0 bls 0x279cc0 <pcre_exec+0x930>
 *   @0x279eb4 ldrb r3, [r7, #0x1]
 *   @0x279eb8 and r3, r3, #192
 *   @0x279ebc cmp r3, #128
 *   @0x279ec0 bne 0x279cc0 <pcre_exec+0x930>
 *   @0x279ec4 add r3, r7, #2
 *   @0x279ec8 b 0x279edc <pcre_exec+0xb4c>
 *   @0x279ecc ldrb r2, [r8]
 *   @0x279ed0 and r2, r2, #192
 *   @0x279ed4 cmp r2, #128
 *   @0x279ed8 bne 0x279cc0 <pcre_exec+0x930>
 *   @0x279edc cmp r3, r11
 *   @0x279ee0 mov r8, r3
 *   @0x279ee4 add r3, r3, #1
 *   @0x279ee8 bne 0x279ecc <pcre_exec+0xb3c>
 *   @0x279eec b 0x279cc0 <pcre_exec+0x930>
 *   @0x279ef0 ldr r12, [sp, #0x6c]
 *   @0x279ef4 cmp r12, #0
 *   @0x279ef8 beq 0x27a060 <pcre_exec+0xcd0>
 *   @0x279efc ldr r2, [sp, #0xf4]
 *   @0x279f00 ldr r12, [sp, #0x160]
 *   @0x279f04 add r1, r2, r12
 *   @0x279f08 cmp r7, r1
 *   @0x279f0c bls 0x2799f4 <pcre_exec+0x664>
 *   @0x279f10 ldr r12, [sp, #0x1c]
 *   @0x279f14 cmp r12, #0
 *   @0x279f18 bne 0x27a34c <pcre_exec+0xfbc>
 *   @0x279f1c cmp r7, r8
 *   @0x279f20 blo 0x279f40 <pcre_exec+0xbb0>
 *   @0x279f24 b 0x279f98 <pcre_exec+0xc08>
 *   @0x279f28 cmp r7, r2
 *   @0x279f2c bhi 0x27a194 <pcre_exec+0xe04>
 *   @0x279f30 add r7, r7, #1
 *   @0x279f34 cmp r7, r8
 *   @0x279f38 beq 0x279f8c <pcre_exec+0xbfc>
 *   @0x279f3c ldr r2, [sp, #0xf4]
 *   @0x279f40 ldr r1, [sp, #0x98]
 *   @0x279f44 cmp r1, #0
 *   @0x279f48 bne 0x279f28 <pcre_exec+0xb98>
 *   @0x279f4c ldr r3, [sp, #0x9c]
 *   @0x279f50 add r2, r2, r3
 *   @0x279f54 rsb r1, r3, r7
 *   @0x279f58 cmp r7, r2
 *   @0x279f5c blo 0x279f30 <pcre_exec+0xba0>
 *   @0x279f60 ldrb r1, [r1]
 *   @0x279f64 ldrb r2, [sp, #0xb4]
 *   @0x279f68 cmp r1, r2
 *   @0x279f6c bne 0x279f30 <pcre_exec+0xba0>
 *   @0x279f70 cmp r3, #1
 *   @0x279f74 rsb r2, r3, #1
 *   @0x279f78 beq 0x279f8c <pcre_exec+0xbfc>
 *   @0x279f7c ldrb r2, [r7, r2]
 *   @0x279f80 ldrb r3, [sp, #0xb5]
 *   @0x279f84 cmp r2, r3
 *   @0x279f88 bne 0x279f30 <pcre_exec+0xba0>
 *   @0x279f8c ldr r3, [r4, #0x8]
 *   @0x279f90 orr r3, r9, r3
 *   @0x279f94 and r3, r3, #67108864
 *   @0x279f98 ldrb r2, [r7, #-0x1]
 *   @0x279f9c cmp r2, #13
 *   @0x279fa0 beq 0x27a424 <pcre_exec+0x1094>
 *   @0x279fa4 cmp r3, #0
 *   @0x279fa8 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x279fac b 0x279c3c <pcre_exec+0x8ac>
 *   @0x279fb0 str r3, [sp, #0x60]
 *   @0x279fb4 str r3, [sp, #0x68]
 *   @0x279fb8 str r3, [sp, #0x74]
 *   @0x279fbc b 0x279898 <pcre_exec+0x508>
 *   @0x279fc0 tst r2, #16
 *   @0x279fc4 beq 0x27a0dc <pcre_exec+0xd4c>
 *   @0x279fc8 tst r2, #32
 *   @0x279fcc ldrb r12, [r4, #0x18]
 *   @0x279fd0 beq 0x27a2c4 <pcre_exec+0xf34>
 *   @0x279fd4 ldr r3, [sp, #0xbc]
 *   @0x279fd8 mov r1, #1
 *   @0x279fdc ldr r0, [sp, #0x20]
 *   @0x279fe0 str r1, [sp, #0x54]
 *   @0x279fe4 ldrb r3, [r3, r12]
 *   @0x279fe8 str r0, [sp, #0x40]
 *   @0x279fec str r3, [sp, #0x64]
 *   @0x279ff0 b 0x27986c <pcre_exec+0x4dc>
 *   @0x279ff4 cmp r0, #0
 *   @0x279ff8 bne 0x279d60 <pcre_exec+0x9d0>
 *   @0x279ffc b 0x279e98 <pcre_exec+0xb08>
 *   @0x27a000 add r0, r3, r3, lsr #31
 *   @0x27a004 asr r0, r0, #1
 *   @0x27a008 mov r1, r0
 *   @0x27a00c b 0x279df4 <pcre_exec+0xa64>
 *   @0x27a010 ldr r3, [sp, #0x9c]
 *   @0x27a014 ldr r2, [sp, #0xf8]
 *   @0x27a018 rsb r2, r3, r2
 *   @0x27a01c cmp r7, r2
 *   @0x27a020 bhi 0x279cec <pcre_exec+0x95c>
 *   @0x27a024 ldrb r0, [r7]
 *   @0x27a028 ldrb r2, [sp, #0xb4]
 *   @0x27a02c cmp r0, r2
 *   @0x27a030 bne 0x279cec <pcre_exec+0x95c>
 *   @0x27a034 cmp r3, #1
 *   @0x27a038 moveq r1, r3
 *   @0x27a03c beq 0x279cec <pcre_exec+0x95c>
 *   @0x27a040 ldrb r1, [r7, #0x1]
 *   @0x27a044 ldrb r3, [sp, #0xb5]
 *   @0x27a048 subs r3, r1, r3
 *   @0x27a04c rsbs r1, r3, #0
 *   @0x27a050 adcs r1, r1, r3
 *   @0x27a054 b 0x279cec <pcre_exec+0x95c>
 *   @0x27a058 mvn r0, #2
 *   @0x27a05c b 0x279474 <pcre_exec+0xe4>
 *   @0x27a060 ldr r12, [sp, #0x40]
 *   @0x27a064 cmp r12, #0
 *   @0x27a068 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x27a06c cmp r7, r8
 *   @0x27a070 bhs 0x2799f4 <pcre_exec+0x664>
 *   @0x27a074 ldrb r3, [r7]
 *   @0x27a078 and r2, r3, #7
 *   @0x27a07c ldrb r3, [r12, r3, lsr #3]
 *   @0x27a080 asr r3, r3, r2
 *   @0x27a084 tst r3, #1
 *   @0x27a088 bne 0x2799f4 <pcre_exec+0x664>
 *   @0x27a08c add r3, r7, #1
 *   @0x27a090 mov r0, r12
 *   @0x27a094 b 0x27a0b0 <pcre_exec+0xd20>
 *   @0x27a098 ldrb r2, [r3], #1
 *   @0x27a09c and r1, r2, #7
 *   @0x27a0a0 ldrb r2, [r0, r2, lsr #3]
 *   @0x27a0a4 asr r2, r2, r1
 *   @0x27a0a8 tst r2, #1
 *   @0x27a0ac bne 0x2799f4 <pcre_exec+0x664>
 *   @0x27a0b0 cmp r3, r8
 *   @0x27a0b4 mov r7, r3
 *   @0x27a0b8 bne 0x27a098 <pcre_exec+0xd08>
 *   @0x27a0bc b 0x2799f4 <pcre_exec+0x664>
 *   @0x27a0c0 mvn r0, #23
 *   @0x27a0c4 b 0x279474 <pcre_exec+0xe4>
 *   @0x27a0c8 ldr r2, [sp, #0x68]
 *   @0x27a0cc mov r3, #1
 *   @0x27a0d0 str r3, [sp, #0x74]
 *   @0x27a0d4 str r2, [sp, #0x60]
 *   @0x27a0d8 b 0x279898 <pcre_exec+0x508>
 *   @0x27a0dc ldr r12, [sp, #0x6c]
 *   @0x27a0e0 eor r3, r12, #1
 *   @0x27a0e4 ldr r12, [sp, #0x34]
 *   @0x27a0e8 cmp r12, #0
 *   @0x27a0ec moveq r3, #0
 *   @0x27a0f0 andne r3, r3, #1
 *   @0x27a0f4 cmp r3, #0
 *   @0x27a0f8 beq 0x27a180 <pcre_exec+0xdf0>
 *   @0x27a0fc ldr r3, [r12, #0x4]
 *   @0x27a100 tst r3, #1
 *   @0x27a104 beq 0x27a180 <pcre_exec+0xdf0>
 *   @0x27a108 add r12, r12, #8
 *   @0x27a10c str r12, [sp, #0x40]
 *   @0x27a110 ldr r12, [sp, #0x20]
 *   @0x27a114 str r12, [sp, #0x64]
 *   @0x27a118 str r12, [sp, #0x54]
 *   @0x27a11c b 0x27986c <pcre_exec+0x4dc>
 *   @0x27a120 ldr r1, [pc, #0x21c]
 *   @0x27a124 ldr r11, [sp, #0x14]
 *   @0x27a128 ldr r0, [r11, r1]
 *   @0x27a12c b 0x2795b4 <pcre_exec+0x224>
 *   @0x27a130 mov r3, #1
 *   @0x27a134 str r3, [sp, #0x98]
 *   @0x27a138 b 0x279758 <pcre_exec+0x3c8>
 *   @0x27a13c cmp r8, r11
 *   @0x27a140 bhs 0x279d20 <pcre_exec+0x990>
 *   @0x27a144 ldrb r3, [r8]
 *   @0x27a148 cmp r3, #10
 *   @0x27a14c bne 0x279d20 <pcre_exec+0x990>
 *   @0x27a150 ldr r3, [r4, #0xc]
 *   @0x27a154 tst r3, #2048
 *   @0x27a158 bne 0x279d20 <pcre_exec+0x990>
 *   @0x27a15c ldr r3, [sp, #0x98]
 *   @0x27a160 sub r3, r3, #1
 *   @0x27a164 cmp r3, #1
 *   @0x27a168 bls 0x27a178 <pcre_exec+0xde8>
 *   @0x27a16c ldr r3, [sp, #0x9c]
 *   @0x27a170 cmp r3, #2
 *   @0x27a174 bne 0x279d20 <pcre_exec+0x990>
 *   @0x27a178 add r8, r8, #1
 *   @0x27a17c b 0x279d20 <pcre_exec+0x990>
 *   @0x27a180 ldr r12, [sp, #0x20]
 *   @0x27a184 str r12, [sp, #0x40]
 *   @0x27a188 str r12, [sp, #0x64]
 *   @0x27a18c str r12, [sp, #0x54]
 *   @0x27a190 b 0x27986c <pcre_exec+0x4dc>
 *   @0x27a194 str r10, [sp]
 *   @0x27a198 mov r0, r7
 *   @0x27a19c add r3, sp, #156
 *   @0x27a1a0 bl 0x25fbc0 <_pcre_was_newline>
 *   @0x27a1a4 cmp r0, #0
 *   @0x27a1a8 beq 0x279f30 <pcre_exec+0xba0>
 *   @0x27a1ac b 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a1b0 cmp r7, r8
 *   @0x27a1b4 bhs 0x2799f4 <pcre_exec+0x664>
 *   @0x27a1b8 ldrb r3, [r7]
 *   @0x27a1bc cmp r3, r5
 *   @0x27a1c0 addne r3, r7, #1
 *   @0x27a1c4 bne 0x27a1d8 <pcre_exec+0xe48>
 *   @0x27a1c8 b 0x2799f4 <pcre_exec+0x664>
 *   @0x27a1cc ldrb r2, [r7]
 *   @0x27a1d0 cmp r2, r5
 *   @0x27a1d4 beq 0x2799f4 <pcre_exec+0x664>
 *   @0x27a1d8 cmp r3, r8
 *   @0x27a1dc mov r7, r3
 *   @0x27a1e0 add r3, r3, #1
 *   @0x27a1e4 bne 0x27a1cc <pcre_exec+0xe3c>
 *   @0x27a1e8 b 0x2799f4 <pcre_exec+0x664>
 *   @0x27a1ec mvn r0, #11
 *   @0x27a1f0 b 0x279b38 <pcre_exec+0x7a8>
 *   @0x27a1f4 ldr r12, [sp, #0x168]
 *   @0x27a1f8 str r12, [sp, #0x70]
 *   @0x27a1fc b 0x27983c <pcre_exec+0x4ac>
 *   @0x27a200 add r9, r1, #1
 *   @0x27a204 ldr r12, [sp, #0x14]
 *   @0x27a208 ldr r3, [pc, #0x138]
 *   @0x27a20c add r9, r9, r9, lsl #1
 *   @0x27a210 ldr r3, [r12, r3]
 *   @0x27a214 lsl r1, r9, #2
 *   @0x27a218 mov r0, r1
 *   @0x27a21c ldr r3, [r3]
 *   @0x27a220 str r1, [sp, #0x10]
 *   @0x27a224 blx r3
 *   @0x27a228 ldr r1, [sp, #0x10]
 *   @0x27a22c cmp r0, #0
 *   @0x27a230 str r0, [sp, #0x8c]
 *   @0x27a234 beq 0x27a4c0 <pcre_exec+0x1130>
 *   @0x27a238 lsl r3, r9, #1
 *   @0x27a23c mov r2, r0
 *   @0x27a240 str r9, [sp, #0x90]
 *   @0x27a244 mov r0, #0
 *   @0x27a248 smull r12, r10, r10, r3
 *   @0x27a24c str r0, [sp, #0x110]
 *   @0x27a250 mov r12, #1
 *   @0x27a254 str r12, [sp, #0x70]
 *   @0x27a258 sub r3, r10, r3, asr #31
 *   @0x27a25c str r3, [sp, #0x94]
 *   @0x27a260 b 0x2797e4 <pcre_exec+0x454>
 *   @0x27a264 ldr r12, [sp, #0x14]
 *   @0x27a268 ldr r3, [pc, #0xd0]
 *   @0x27a26c ldr r0, [sp, #0x8c]
 *   @0x27a270 ldr r3, [r12, r3]
 *   @0x27a274 ldr r3, [r3]
 *   @0x27a278 blx r3
 *   @0x27a27c b 0x279adc <pcre_exec+0x74c>
 *   @0x27a280 ldr r11, [sp, #0x160]
 *   @0x27a284 cmp r11, r3
 *   @0x27a288 movge r2, #0
 *   @0x27a28c movlt r2, #1
 *   @0x27a290 cmp r11, #0
 *   @0x27a294 movle r2, #0
 *   @0x27a298 cmp r2, #0
 *   @0x27a29c beq 0x27a2b4 <pcre_exec+0xf24>
 *   @0x27a2a0 ldrb r2, [r6, r11]
 *   @0x27a2a4 and r2, r2, #192
 *   @0x27a2a8 cmp r2, #128
 *   @0x27a2ac mvneq r0, #10
 *   @0x27a2b0 beq 0x279474 <pcre_exec+0xe4>
 *   @0x27a2b4 ldr r2, [r4, #0xc]
 *   @0x27a2b8 ldr r8, [r4, #0x8]
 *   @0x27a2bc str r2, [sp, #0x20]
 *   @0x27a2c0 b 0x2794fc <pcre_exec+0x16c>
 *   @0x27a2c4 ldr r0, [sp, #0x20]
 *   @0x27a2c8 mov r1, #1
 *   @0x27a2cc str r12, [sp, #0x64]
 *   @0x27a2d0 str r1, [sp, #0x54]
 *   @0x27a2d4 str r0, [sp, #0x40]
 *   @0x27a2d8 b 0x27986c <pcre_exec+0x4dc>
 *   @0x27a2dc mov r0, #0
 *   @0x27a2e0 b 0x279e6c <pcre_exec+0xadc>
 *   @0x27a2e4 ldr r12, [sp, #0x1c]
 *   @0x27a2e8 mov r0, r7
 *   @0x27a2ec add r3, sp, #156
 *   @0x27a2f0 str r12, [sp]
 *   @0x27a2f4 bl 0x25f9fc <_pcre_is_newline>
 *   @0x27a2f8 adds r0, r0, #0
 *   @0x27a2fc movne r0, #1
 *   @0x27a300 b 0x279ce8 <pcre_exec+0x958>
 *   @0x27a304 mvn r0, #14
 *   @0x27a308 b 0x279474 <pcre_exec+0xe4>
 *   @0x27a30c mvn r0, #31
 *   @0x27a310 b 0x279474 <pcre_exec+0xe4>
 *   @0x27a314 ldr r11, [sp, #0x4c]
 *   @0x27a318 add r1, r5, #8
 *   @0x27a31c ldr r12, [sp, #0x168]
 *   @0x27a320 sub r2, r11, #2
 *   @0x27a324 add r0, r12, #8
 *   @0x27a328 lsl r2, r2, #2
 *   @0x27a32c bl 0xb65bc <memcpy@plt>
 *   @0x27a330 b 0x279d9c <pcre_exec+0xa0c>
 *   @0x27a334 mvn r0, #27
 *   @0x27a338 b 0x279474 <pcre_exec+0xe4>
 *   @0x27a33c mulseq r7, r12, r8
 *   @0x27a340 .word 0xffffea38
 *   @0x27a344 .word 0xfffffb98
 *   @0x27a348 .word 0xfffffb94
 *   @0x27a34c cmp r7, r8
 *   @0x27a350 bhs 0x279f98 <pcre_exec+0xc08>
 *   @0x27a354 ldr r1, [sp, #0x98]
 *   @0x27a358 cmp r1, #0
 *   @0x27a35c beq 0x27a3b0 <pcre_exec+0x1020>
 *   @0x27a360 cmp r7, r2
 *   @0x27a364 bhi 0x27a3f4 <pcre_exec+0x1064>
 *   @0x27a368 add r3, r7, #1
 *   @0x27a36c cmp r8, r3
 *   @0x27a370 bls 0x27a414 <pcre_exec+0x1084>
 *   @0x27a374 ldrb r2, [r7, #0x1]
 *   @0x27a378 and r2, r2, #192
 *   @0x27a37c cmp r2, #128
 *   @0x27a380 bne 0x27a41c <pcre_exec+0x108c>
 *   @0x27a384 add r3, r7, #2
 *   @0x27a388 cmp r3, r8
 *   @0x27a38c mov r7, r3
 *   @0x27a390 add r3, r3, #1
 *   @0x27a394 beq 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a398 ldrb r2, [r7]
 *   @0x27a39c and r2, r2, #192
 *   @0x27a3a0 cmp r2, #128
 *   @0x27a3a4 beq 0x27a388 <pcre_exec+0xff8>
 *   @0x27a3a8 ldr r2, [sp, #0xf4]
 *   @0x27a3ac b 0x27a354 <pcre_exec+0xfc4>
 *   @0x27a3b0 ldr r3, [sp, #0x9c]
 *   @0x27a3b4 add r2, r2, r3
 *   @0x27a3b8 cmp r7, r2
 *   @0x27a3bc blo 0x27a368 <pcre_exec+0xfd8>
 *   @0x27a3c0 rsb r1, r3, r7
 *   @0x27a3c4 ldrb r2, [sp, #0xb4]
 *   @0x27a3c8 ldrb r1, [r1]
 *   @0x27a3cc cmp r1, r2
 *   @0x27a3d0 bne 0x27a368 <pcre_exec+0xfd8>
 *   @0x27a3d4 cmp r3, #1
 *   @0x27a3d8 beq 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a3dc rsb r3, r3, #1
 *   @0x27a3e0 ldrb r2, [sp, #0xb5]
 *   @0x27a3e4 ldrb r3, [r7, r3]
 *   @0x27a3e8 cmp r3, r2
 *   @0x27a3ec bne 0x27a368 <pcre_exec+0xfd8>
 *   @0x27a3f0 b 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a3f4 mov r0, #1
 *   @0x27a3f8 add r3, sp, #156
 *   @0x27a3fc str r0, [sp]
 *   @0x27a400 mov r0, r7
 *   @0x27a404 bl 0x25fbc0 <_pcre_was_newline>
 *   @0x27a408 cmp r0, #0
 *   @0x27a40c beq 0x27a368 <pcre_exec+0xfd8>
 *   @0x27a410 b 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a414 mov r7, r3
 *   @0x27a418 b 0x279f8c <pcre_exec+0xbfc>
 *   @0x27a41c mov r7, r3
 *   @0x27a420 b 0x27a3a8 <pcre_exec+0x1018>
 *   @0x27a424 ldr r2, [sp, #0x98]
 *   @0x27a428 sub r2, r2, #1
 *   @0x27a42c cmp r2, #1
 *   @0x27a430 bhi 0x279fa4 <pcre_exec+0xc14>
 *   @0x27a434 cmp r7, r8
 *   @0x27a438 bhs 0x279fa4 <pcre_exec+0xc14>
 *   @0x27a43c ldrb r2, [r7]
 *   @0x27a440 cmp r2, #10
 *   @0x27a444 addeq r7, r7, #1
 *   @0x27a448 b 0x279fa4 <pcre_exec+0xc14>
 *   @0x27a44c mvn r0, #12
 *   @0x27a450 b 0x279474 <pcre_exec+0xe4>
 *   @0x27a454 cmp r11, r3
 *   @0x27a458 bls 0x279ac4 <pcre_exec+0x734>
 *   @0x27a45c add r12, r3, #1
 *   @0x27a460 ldrb r2, [r3]
 *   @0x27a464 str r12, [sp, #0x5c]
 *   @0x27a468 ldr r12, [sp, #0x68]
 *   @0x27a46c cmp r2, r12
 *   @0x27a470 beq 0x27a4a0 <pcre_exec+0x1110>
 *   @0x27a474 ldr r2, [sp, #0x5c]
 *   @0x27a478 ldr r0, [sp, #0x68]
 *   @0x27a47c b 0x27a490 <pcre_exec+0x1100>
 *   @0x27a480 ldrb r1, [r3], #1
 *   @0x27a484 cmp r1, r0
 *   @0x27a488 beq 0x279c38 <pcre_exec+0x8a8>
 *   @0x27a48c mov r2, r3
 *   @0x27a490 cmp r2, r11
 *   @0x27a494 mov r3, r2
 *   @0x27a498 bne 0x27a480 <pcre_exec+0x10f0>
 *   @0x27a49c b 0x279ac4 <pcre_exec+0x734>
 *   @0x27a4a0 str r3, [sp, #0x5c]
 *   @0x27a4a4 b 0x279c3c <pcre_exec+0x8ac>
 *   @0x27a4a8 cmp r0, #0
 *   @0x27a4ac cmnne r0, #12
 *   @0x27a4b0 moveq r12, #0
 *   @0x27a4b4 movne r12, #1
 *   @0x27a4b8 str r12, [sp, #0x18]
 *   @0x27a4bc b 0x279ad0 <pcre_exec+0x740>
 *   @0x27a4c0 mvn r0, #5
 *   @0x27a4c4 b 0x279474 <pcre_exec+0xe4>
 *
 * ══ §4/7 b2ParticleSystem::SolveZombie  0x2d660c  size 3828  957 条（0x2d660c..0x2d7500）
 * @func 0x2d660c 0x2d7500  size 3828  957 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: b2ParticleSystem::SolveZombie()+0xa88×21 / b2ParticleSystem::SolveZombie()+0x448×15 / b2ParticleSystem::SolveZombie()+0x834×15 / b2ParticleSystem::SolveZombie()+0x254×5 / b2ParticleSystem::SolveZombie()+0x61c×5 / b2ParticleSystem::SolveZombie()+0xc48×3 / b2ParticleSystem::SolveZombie()+0xb04×3 / b2ParticleSystem::SolveZombie()+0xc50×2
 * 字段偏移 top8: 0x4×37 / 0x8×14 / 0x2×11 / 0x10×7 / 0xc×7 / 0x14×6 / 0x18×6 / 0x24×4
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2d660c ldr r1, [r0, #0x24]
 *   @0x2d6610 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2d6614 mov r5, r0
 *   @0x2d6618 ldr r0, [r0, #0xd4]
 *   @0x2d661c sub sp, sp, #28
 *   @0x2d6620 lsl r1, r1, #2
 *   @0x2d6624 add r0, r0, #68
 *   @0x2d6628 bl 0x2e0f44 <_ZN16b2StackAllocator8AllocateEi>
 *   @0x2d662c ldr r3, [r5, #0x24]
 *   @0x2d6630 cmp r3, #0
 *   @0x2d6634 mov r4, r0
 *   @0x2d6638 ble 0x2d74cc <_ZN16b2ParticleSystem11SolveZombieEv+0xec0>
 *   @0x2d663c mov r6, #0
 *   @0x2d6640 movw r8, #0x9244
 *   @0x2d6644 mov r7, r6
 *   @0x2d6648 movt r8, #0x1
 *   @0x2d664c str r6, [sp, #0x14]
 *   @0x2d6650 mvn r9, #0
 *   @0x2d6654 mov r10, r6
 *   @0x2d6658 str r8, [sp]
 *   @0x2d665c b 0x2d66a4 <_ZN16b2ParticleSystem11SolveZombieEv+0x98>
 *   @0x2d6660 ldr r3, [r5, #0xd4]
 *   @0x2d6664 tst r2, #512
 *   @0x2d6668 ldr r2, [sp]
 *   @0x2d666c ldr r0, [r3, r2]
 *   @0x2d6670 beq 0x2d668c <_ZN16b2ParticleSystem11SolveZombieEv+0x80>
 *   @0x2d6674 cmp r0, #0
 *   @0x2d6678 beq 0x2d668c <_ZN16b2ParticleSystem11SolveZombieEv+0x80>
 *   @0x2d667c ldr r3, [r0]
 *   @0x2d6680 mov r1, r7
 *   @0x2d6684 ldr r3, [r3, #0x14]
 *   @0x2d6688 blx r3
 *   @0x2d668c str r9, [r4, r6]
 *   @0x2d6690 ldr r3, [r5, #0x24]
 *   @0x2d6694 add r7, r7, #1
 *   @0x2d6698 add r6, r6, #4
 *   @0x2d669c cmp r3, r7
 *   @0x2d66a0 ble 0x2d674c <_ZN16b2ParticleSystem11SolveZombieEv+0x140>
 *   @0x2d66a4 ldr r3, [r5, #0x30]
 *   @0x2d66a8 add r0, r3, r6
 *   @0x2d66ac ldr r2, [r3, r6]
 *   @0x2d66b0 tst r2, #2
 *   @0x2d66b4 bne 0x2d6660 <_ZN16b2ParticleSystem11SolveZombieEv+0x54>
 *   @0x2d66b8 cmp r7, r10
 *   @0x2d66bc str r10, [r4, r6]
 *   @0x2d66c0 beq 0x2d6744 <_ZN16b2ParticleSystem11SolveZombieEv+0x138>
 *   @0x2d66c4 ldr r11, [r5, #0x38]
 *   @0x2d66c8 lsl lr, r7, #3
 *   @0x2d66cc ldr r0, [r0]
 *   @0x2d66d0 lsl r12, r10, #3
 *   @0x2d66d4 ldr r2, [r5, #0x40]
 *   @0x2d66d8 add r1, r11, lr
 *   @0x2d66dc add r11, r11, r12
 *   @0x2d66e0 str r0, [r3, r10, lsl #2]
 *   @0x2d66e4 add lr, r2, lr
 *   @0x2d66e8 ldm r1, {r0, r1}
 *   @0x2d66ec add r12, r2, r12
 *   @0x2d66f0 ldr r2, [r5, #0x5c]
 *   @0x2d66f4 lsl r3, r10, #2
 *   @0x2d66f8 stm r11, {r0, r1}
 *   @0x2d66fc ldr r11, [r2, r6]
 *   @0x2d6700 ldm lr, {r0, r1}
 *   @0x2d6704 stm r12, {r0, r1}
 *   @0x2d6708 str r11, [r2, r10, lsl #2]
 *   @0x2d670c ldr r2, [r5, #0x50]
 *   @0x2d6710 cmp r2, #0
 *   @0x2d6714 addne r1, r2, r6
 *   @0x2d6718 addne r2, r2, r3
 *   @0x2d671c ldrne r1, [r1]
 *   @0x2d6720 strne r1, [r2]
 *   @0x2d6724 ldr r2, [r5, #0x54]
 *   @0x2d6728 cmp r2, #0
 *   @0x2d672c ldrne r1, [r2, r6]
 *   @0x2d6730 strne r1, [r2, r3]
 *   @0x2d6734 ldr r2, [r5, #0x60]
 *   @0x2d6738 cmp r2, #0
 *   @0x2d673c ldrne r1, [r2, r6]
 *   @0x2d6740 strne r1, [r2, r3]
 *   @0x2d6744 add r10, r10, #1
 *   @0x2d6748 b 0x2d6690 <_ZN16b2ParticleSystem11SolveZombieEv+0x84>
 *   @0x2d674c str r10, [sp, #0x14]
 *   @0x2d6750 ldr r10, [r5, #0x68]
 *   @0x2d6754 cmp r10, #0
 *   @0x2d6758 lslle r10, r10, #3
 *   @0x2d675c ldrle r2, [r5, #0x70]
 *   @0x2d6760 ble 0x2d6788 <_ZN16b2ParticleSystem11SolveZombieEv+0x17c>
 *   @0x2d6764 ldr r2, [r5, #0x70]
 *   @0x2d6768 lsl r10, r10, #3
 *   @0x2d676c mov r3, #0
 *   @0x2d6770 ldr r1, [r2, r3]
 *   @0x2d6774 ldr r1, [r4, r1, lsl #2]
 *   @0x2d6778 str r1, [r2, r3]
 *   @0x2d677c add r3, r3, #8
 *   @0x2d6780 cmp r3, r10
 *   @0x2d6784 bne 0x2d6770 <_ZN16b2ParticleSystem11SolveZombieEv+0x164>
 *   @0x2d6788 add r10, r2, r10
 *   @0x2d678c rsb r11, r2, r10
 *   @0x2d6790 asr r0, r11, #5
 *   @0x2d6794 asr r11, r11, #3
 *   @0x2d6798 cmp r0, #0
 *   @0x2d679c ble 0x2d74f4 <_ZN16b2ParticleSystem11SolveZombieEv+0xee8>
 *   @0x2d67a0 ldr r3, [r2]
 *   @0x2d67a4 cmp r3, #0
 *   @0x2d67a8 blt 0x2d74ec <_ZN16b2ParticleSystem11SolveZombieEv+0xee0>
 *   @0x2d67ac ldr r3, [r2, #0x8]
 *   @0x2d67b0 cmp r3, #0
 *   @0x2d67b4 addlt r3, r2, #8
 *   @0x2d67b8 blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d67bc ldr r3, [r2, #0x10]
 *   @0x2d67c0 cmp r3, #0
 *   @0x2d67c4 addlt r3, r2, #16
 *   @0x2d67c8 blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d67cc ldr r3, [r2, #0x18]
 *   @0x2d67d0 cmp r3, #0
 *   @0x2d67d4 blt 0x2d685c <_ZN16b2ParticleSystem11SolveZombieEv+0x250>
 *   @0x2d67d8 mov r1, r2
 *   @0x2d67dc add r9, r2, #56
 *   @0x2d67e0 b 0x2d6818 <_ZN16b2ParticleSystem11SolveZombieEv+0x20c>
 *   @0x2d67e4 ldr r6, [r1, #0x20]
 *   @0x2d67e8 cmp r6, #0
 *   @0x2d67ec blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d67f0 ldr r6, [r12, r7]
 *   @0x2d67f4 cmp r6, #0
 *   @0x2d67f8 blt 0x2d749c <_ZN16b2ParticleSystem11SolveZombieEv+0xe90>
 *   @0x2d67fc ldr r12, [r12, r8]
 *   @0x2d6800 cmp r12, #0
 *   @0x2d6804 blt 0x2d74a4 <_ZN16b2ParticleSystem11SolveZombieEv+0xe98>
 *   @0x2d6808 ldr r12, [lr, #-0x20]
 *   @0x2d680c cmp r12, #0
 *   @0x2d6810 blt 0x2d74c4 <_ZN16b2ParticleSystem11SolveZombieEv+0xeb8>
 *   @0x2d6814 mov r1, r3
 *   @0x2d6818 add r3, r1, #32
 *   @0x2d681c subs r0, r0, #1
 *   @0x2d6820 rsb lr, r2, r3
 *   @0x2d6824 add r7, r2, #40
 *   @0x2d6828 add r8, r2, #48
 *   @0x2d682c rsb r12, r2, r1
 *   @0x2d6830 add lr, lr, r9
 *   @0x2d6834 bne 0x2d67e4 <_ZN16b2ParticleSystem11SolveZombieEv+0x1d8>
 *   @0x2d6838 rsb r1, r3, r10
 *   @0x2d683c asr r1, r1, #3
 *   @0x2d6840 cmp r1, #2
 *   @0x2d6844 beq 0x2d7404 <_ZN16b2ParticleSystem11SolveZombieEv+0xdf8>
 *   @0x2d6848 cmp r1, #3
 *   @0x2d684c beq 0x2d73f4 <_ZN16b2ParticleSystem11SolveZombieEv+0xde8>
 *   @0x2d6850 cmp r1, #1
 *   @0x2d6854 bne 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4>
 *   @0x2d6858 b 0x2d7414 <_ZN16b2ParticleSystem11SolveZombieEv+0xe08>
 *   @0x2d685c add r3, r2, #24
 *   @0x2d6860 cmp r10, r3
 *   @0x2d6864 beq 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4>
 *   @0x2d6868 add r1, r3, #8
 *   @0x2d686c cmp r10, r1
 *   @0x2d6870 beq 0x2d68a8 <_ZN16b2ParticleSystem11SolveZombieEv+0x29c>
 *   @0x2d6874 add r12, r3, #16
 *   @0x2d6878 add lr, r3, #24
 *   @0x2d687c rsb r1, r12, r10
 *   @0x2d6880 bic r1, r1, #7
 *   @0x2d6884 add lr, lr, r1
 *   @0x2d6888 ldr r1, [r12, #-0x8]
 *   @0x2d688c cmp r1, #0
 *   @0x2d6890 ldmdbge r12, {r0, r1}
 *   @0x2d6894 add r12, r12, #8
 *   @0x2d6898 stmge r3, {r0, r1}
 *   @0x2d689c addge r3, r3, #8
 *   @0x2d68a0 cmp r12, lr
 *   @0x2d68a4 bne 0x2d6888 <_ZN16b2ParticleSystem11SolveZombieEv+0x27c>
 *   @0x2d68a8 rsb r3, r2, r3
 *   @0x2d68ac asr r11, r3, #3
 *   @0x2d68b0 ldr r12, [r5, #0x74]
 *   @0x2d68b4 str r11, [r5, #0x68]
 *   @0x2d68b8 cmp r12, #0
 *   @0x2d68bc lslle r6, r12, #1
 *   @0x2d68c0 ldrle lr, [r5, #0x7c]
 *   @0x2d68c4 ble 0x2d6904 <_ZN16b2ParticleSystem11SolveZombieEv+0x2f8>
 *   @0x2d68c8 lsl r6, r12, #1
 *   @0x2d68cc ldr lr, [r5, #0x7c]
 *   @0x2d68d0 add r0, r6, r12
 *   @0x2d68d4 mov r2, #0
 *   @0x2d68d8 lsl r0, r0, #3
 *   @0x2d68dc ldr r1, [lr, r2]
 *   @0x2d68e0 mov r3, lr
 *   @0x2d68e4 ldr r1, [r4, r1, lsl #2]
 *   @0x2d68e8 str r1, [r3, r2]!
 *   @0x2d68ec add r2, r2, #24
 *   @0x2d68f0 ldr r1, [r3, #0x4]
 *   @0x2d68f4 cmp r2, r0
 *   @0x2d68f8 ldr r1, [r4, r1, lsl #2]
 *   @0x2d68fc str r1, [r3, #0x4]
 *   @0x2d6900 bne 0x2d68dc <_ZN16b2ParticleSystem11SolveZombieEv+0x2d0>
 *   @0x2d6904 add r12, r6, r12
 *   @0x2d6908 sbfx r3, r12, #0x0, #0x1d
 *   @0x2d690c add r12, lr, r12, lsl #3
 *   @0x2d6910 str r12, [sp, #0x10]
 *   @0x2d6914 add r2, r3, r3, lsl #2
 *   @0x2d6918 add r2, r2, r2, lsl #4
 *   @0x2d691c add r2, r2, r2, lsl #8
 *   @0x2d6920 add r2, r2, r2, lsl #16
 *   @0x2d6924 add r2, r3, r2, lsl #1
 *   @0x2d6928 str r2, [sp, #0xc]
 *   @0x2d692c asr r1, r2, #2
 *   @0x2d6930 str r1, [sp]
 *   @0x2d6934 cmp r1, #0
 *   @0x2d6938 movle r3, r2
 *   @0x2d693c movle r12, lr
 *   @0x2d6940 ble 0x2d72c4 <_ZN16b2ParticleSystem11SolveZombieEv+0xcb8>
 *   @0x2d6944 ldr r3, [lr]
 *   @0x2d6948 cmp r3, #0
 *   @0x2d694c blt 0x2d725c <_ZN16b2ParticleSystem11SolveZombieEv+0xc50>
 *   @0x2d6950 ldr r3, [lr, #0x4]
 *   @0x2d6954 cmp r3, #0
 *   @0x2d6958 blt 0x2d725c <_ZN16b2ParticleSystem11SolveZombieEv+0xc50>
 *   @0x2d695c ldr r3, [lr, #0x18]
 *   @0x2d6960 add r12, lr, #24
 *   @0x2d6964 cmp r3, #0
 *   @0x2d6968 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d696c ldr r3, [lr, #0x1c]
 *   @0x2d6970 cmp r3, #0
 *   @0x2d6974 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6978 ldr r3, [lr, #0x30]
 *   @0x2d697c add r1, lr, #48
 *   @0x2d6980 str r1, [sp, #0x4]
 *   @0x2d6984 cmp r3, #0
 *   @0x2d6988 mov r12, r1
 *   @0x2d698c blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6990 add r9, lr, #72
 *   @0x2d6994 add r6, lr, #96
 *   @0x2d6998 add r10, lr, #120
 *   @0x2d699c add r2, lr, #144
 *   @0x2d69a0 str r2, [sp, #0x8]
 *   @0x2d69a4 mov r2, lr
 *   @0x2d69a8 ldr r8, [sp, #0x4]
 *   @0x2d69ac rsb r3, lr, r2
 *   @0x2d69b0 add r1, r3, r9
 *   @0x2d69b4 add r7, r3, r6
 *   @0x2d69b8 add r0, r3, r8
 *   @0x2d69bc ldr r0, [r0, #0x4]
 *   @0x2d69c0 cmp r0, #0
 *   @0x2d69c4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d69c8 ldr r0, [r3, r9]
 *   @0x2d69cc add r12, r2, #72
 *   @0x2d69d0 cmp r0, #0
 *   @0x2d69d4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d69d8 ldr r1, [r1, #0x4]
 *   @0x2d69dc add r8, r3, r10
 *   @0x2d69e0 cmp r1, #0
 *   @0x2d69e4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d69e8 ldr r1, [sp]
 *   @0x2d69ec add r12, r2, #96
 *   @0x2d69f0 rsb r11, lr, r12
 *   @0x2d69f4 subs r1, r1, #1
 *   @0x2d69f8 str r1, [sp]
 *   @0x2d69fc ldr r1, [sp, #0x8]
 *   @0x2d6a00 mov r0, r12
 *   @0x2d6a04 add r11, r11, r1
 *   @0x2d6a08 beq 0x2d72a4 <_ZN16b2ParticleSystem11SolveZombieEv+0xc98>
 *   @0x2d6a0c ldr r1, [r3, r6]
 *   @0x2d6a10 cmp r1, #0
 *   @0x2d6a14 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6a18 ldr r1, [r7, #0x4]
 *   @0x2d6a1c cmp r1, #0
 *   @0x2d6a20 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6a24 ldr r3, [r3, r10]
 *   @0x2d6a28 add r12, r2, #120
 *   @0x2d6a2c cmp r3, #0
 *   @0x2d6a30 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6a34 ldr r3, [r8, #0x4]
 *   @0x2d6a38 cmp r3, #0
 *   @0x2d6a3c blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d6a40 ldr r3, [r11, #-0x60]
 *   @0x2d6a44 add r12, r2, #144
 *   @0x2d6a48 mov r2, r0
 *   @0x2d6a4c cmp r3, #0
 *   @0x2d6a50 bge 0x2d69a8 <_ZN16b2ParticleSystem11SolveZombieEv+0x39c>
 *   @0x2d6a54 ldr r2, [sp, #0x10]
 *   @0x2d6a58 cmp r2, r12
 *   @0x2d6a5c beq 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4>
 *   @0x2d6a60 add r3, r12, #24
 *   @0x2d6a64 cmp r2, r3
 *   @0x2d6a68 beq 0x2d6ac0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4b4>
 *   @0x2d6a6c add r8, r12, #48
 *   @0x2d6a70 add r9, r12, #72
 *   @0x2d6a74 rsb r3, r8, r2
 *   @0x2d6a78 bic r3, r3, #7
 *   @0x2d6a7c add r9, r9, r3
 *   @0x2d6a80 ldr r3, [r8, #-0x18]
 *   @0x2d6a84 sub r7, r8, #24
 *   @0x2d6a88 mov r6, r12
 *   @0x2d6a8c cmp r3, #0
 *   @0x2d6a90 blt 0x2d6ab4 <_ZN16b2ParticleSystem11SolveZombieEv+0x4a8>
 *   @0x2d6a94 ldr r3, [r8, #-0x14]
 *   @0x2d6a98 cmp r3, #0
 *   @0x2d6a9c blt 0x2d6ab4 <_ZN16b2ParticleSystem11SolveZombieEv+0x4a8>
 *   @0x2d6aa0 ldm r7!, {r0, r1, r2, r3}
 *   @0x2d6aa4 add r12, r12, #24
 *   @0x2d6aa8 stm r6!, {r0, r1, r2, r3}
 *   @0x2d6aac ldm r7, {r0, r1}
 *   @0x2d6ab0 stm r6, {r0, r1}
 *   @0x2d6ab4 add r8, r8, #24
 *   @0x2d6ab8 cmp r8, r9
 *   @0x2d6abc bne 0x2d6a80 <_ZN16b2ParticleSystem11SolveZombieEv+0x474>
 *   @0x2d6ac0 rsb r3, lr, r12
 *   @0x2d6ac4 asr r3, r3, #3
 *   @0x2d6ac8 add r2, r3, r3, lsl #2
 *   @0x2d6acc add r2, r2, r2, lsl #4
 *   @0x2d6ad0 add r2, r2, r2, lsl #8
 *   @0x2d6ad4 add r2, r2, r2, lsl #16
 *   @0x2d6ad8 add r2, r3, r2, lsl #1
 *   @0x2d6adc str r2, [sp, #0xc]
 *   @0x2d6ae0 ldr r0, [r5, #0x80]
 *   @0x2d6ae4 ldr r3, [sp, #0xc]
 *   @0x2d6ae8 cmp r0, #0
 *   @0x2d6aec lslle r12, r0, #1
 *   @0x2d6af0 str r3, [r5, #0x74]
 *   @0x2d6af4 ldrle lr, [r5, #0x88]
 *   @0x2d6af8 ble 0x2d6b28 <_ZN16b2ParticleSystem11SolveZombieEv+0x51c>
 *   @0x2d6afc lsl r12, r0, #1
 *   @0x2d6b00 ldr lr, [r5, #0x88]
 *   @0x2d6b04 add r1, r12, r0
 *   @0x2d6b08 mov r3, #0
 *   @0x2d6b0c lsl r1, r1, #3
 *   @0x2d6b10 ldr r2, [lr, r3]
 *   @0x2d6b14 ldr r2, [r4, r2, lsl #2]
 *   @0x2d6b18 str r2, [lr, r3]
 *   @0x2d6b1c add r3, r3, #24
 *   @0x2d6b20 cmp r3, r1
 *   @0x2d6b24 bne 0x2d6b10 <_ZN16b2ParticleSystem11SolveZombieEv+0x504>
 *   @0x2d6b28 add r0, r12, r0
 *   @0x2d6b2c sbfx r3, r0, #0x0, #0x1d
 *   @0x2d6b30 add r11, lr, r0, lsl #3
 *   @0x2d6b34 add r10, r3, r3, lsl #2
 *   @0x2d6b38 add r10, r10, r10, lsl #4
 *   @0x2d6b3c add r10, r10, r10, lsl #8
 *   @0x2d6b40 add r10, r10, r10, lsl #16
 *   @0x2d6b44 add r10, r3, r10, lsl #1
 *   @0x2d6b48 asr r2, r10, #2
 *   @0x2d6b4c cmp r2, #0
 *   @0x2d6b50 ble 0x2d74e0 <_ZN16b2ParticleSystem11SolveZombieEv+0xed4>
 *   @0x2d6b54 ldr r3, [lr]
 *   @0x2d6b58 cmp r3, #0
 *   @0x2d6b5c blt 0x2d74d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xecc>
 *   @0x2d6b60 ldr r3, [lr, #0x18]
 *   @0x2d6b64 cmp r3, #0
 *   @0x2d6b68 addlt r12, lr, #24
 *   @0x2d6b6c blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d6b70 ldr r3, [lr, #0x30]
 *   @0x2d6b74 cmp r3, #0
 *   @0x2d6b78 addlt r12, lr, #48
 *   @0x2d6b7c blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d6b80 ldr r3, [lr, #0x48]
 *   @0x2d6b84 cmp r3, #0
 *   @0x2d6b88 blt 0x2d6c24 <_ZN16b2ParticleSystem11SolveZombieEv+0x618>
 *   @0x2d6b8c mov r3, lr
 *   @0x2d6b90 add r9, lr, #168
 *   @0x2d6b94 b 0x2d6bcc <_ZN16b2ParticleSystem11SolveZombieEv+0x5c0>
 *   @0x2d6b98 ldr r6, [r3, #0x60]
 *   @0x2d6b9c cmp r6, #0
 *   @0x2d6ba0 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d6ba4 ldr r6, [r1, r7]
 *   @0x2d6ba8 cmp r6, #0
 *   @0x2d6bac blt 0x2d74ac <_ZN16b2ParticleSystem11SolveZombieEv+0xea0>
 *   @0x2d6bb0 ldr r1, [r1, r8]
 *   @0x2d6bb4 cmp r1, #0
 *   @0x2d6bb8 blt 0x2d74b4 <_ZN16b2ParticleSystem11SolveZombieEv+0xea8>
 *   @0x2d6bbc ldr r1, [r0, #-0x60]
 *   @0x2d6bc0 cmp r1, #0
 *   @0x2d6bc4 blt 0x2d74bc <_ZN16b2ParticleSystem11SolveZombieEv+0xeb0>
 *   @0x2d6bc8 mov r3, r12
 *   @0x2d6bcc add r12, r3, #96
 *   @0x2d6bd0 subs r2, r2, #1
 *   @0x2d6bd4 rsb r0, lr, r12
 *   @0x2d6bd8 add r7, lr, #120
 *   @0x2d6bdc add r8, lr, #144
 *   @0x2d6be0 rsb r1, lr, r3
 *   @0x2d6be4 add r0, r0, r9
 *   @0x2d6be8 bne 0x2d6b98 <_ZN16b2ParticleSystem11SolveZombieEv+0x58c>
 *   @0x2d6bec rsb r2, r12, r11
 *   @0x2d6bf0 asr r2, r2, #3
 *   @0x2d6bf4 add r3, r2, r2, lsl #2
 *   @0x2d6bf8 add r3, r3, r3, lsl #4
 *   @0x2d6bfc add r3, r3, r3, lsl #8
 *   @0x2d6c00 add r3, r3, r3, lsl #16
 *   @0x2d6c04 add r3, r2, r3, lsl #1
 *   @0x2d6c08 cmp r3, #2
 *   @0x2d6c0c beq 0x2d732c <_ZN16b2ParticleSystem11SolveZombieEv+0xd20>
 *   @0x2d6c10 cmp r3, #3
 *   @0x2d6c14 beq 0x2d731c <_ZN16b2ParticleSystem11SolveZombieEv+0xd10>
 *   @0x2d6c18 cmp r3, #1
 *   @0x2d6c1c bne 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690>
 *   @0x2d6c20 b 0x2d733c <_ZN16b2ParticleSystem11SolveZombieEv+0xd30>
 *   @0x2d6c24 add r12, lr, #72
 *   @0x2d6c28 cmp r11, r12
 *   @0x2d6c2c beq 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690>
 *   @0x2d6c30 add r3, r12, #24
 *   @0x2d6c34 cmp r11, r3
 *   @0x2d6c38 beq 0x2d6c80 <_ZN16b2ParticleSystem11SolveZombieEv+0x674>
 *   @0x2d6c3c add r6, r12, #48
 *   @0x2d6c40 add r9, r12, #72
 *   @0x2d6c44 rsb r3, r6, r11
 *   @0x2d6c48 bic r3, r3, #7
 *   @0x2d6c4c add r9, r9, r3
 *   @0x2d6c50 ldr r3, [r6, #-0x18]
 *   @0x2d6c54 sub r8, r6, #24
 *   @0x2d6c58 mov r7, r12
 *   @0x2d6c5c add r6, r6, #24
 *   @0x2d6c60 cmp r3, #0
 *   @0x2d6c64 addge r12, r12, #24
 *   @0x2d6c68 ldmge r8!, {r0, r1, r2, r3}
 *   @0x2d6c6c stmge r7!, {r0, r1, r2, r3}
 *   @0x2d6c70 ldmge r8, {r0, r1}
 *   @0x2d6c74 stmge r7, {r0, r1}
 *   @0x2d6c78 cmp r6, r9
 *   @0x2d6c7c bne 0x2d6c50 <_ZN16b2ParticleSystem11SolveZombieEv+0x644>
 *   @0x2d6c80 rsb r3, lr, r12
 *   @0x2d6c84 asr r3, r3, #3
 *   @0x2d6c88 add r10, r3, r3, lsl #2
 *   @0x2d6c8c add r10, r10, r10, lsl #4
 *   @0x2d6c90 add r10, r10, r10, lsl #8
 *   @0x2d6c94 add r10, r10, r10, lsl #16
 *   @0x2d6c98 add r10, r3, r10, lsl #1
 *   @0x2d6c9c ldr r12, [r5, #0x8c]
 *   @0x2d6ca0 str r10, [r5, #0x80]
 *   @0x2d6ca4 cmp r12, #0
 *   @0x2d6ca8 lslle r6, r12, #2
 *   @0x2d6cac ldrle lr, [r5, #0x94]
 *   @0x2d6cb0 ble 0x2d6cf0 <_ZN16b2ParticleSystem11SolveZombieEv+0x6e4>
 *   @0x2d6cb4 lsl r6, r12, #2
 *   @0x2d6cb8 ldr lr, [r5, #0x94]
 *   @0x2d6cbc add r0, r6, r12
 *   @0x2d6cc0 mov r2, #0
 *   @0x2d6cc4 lsl r0, r0, #2
 *   @0x2d6cc8 ldr r1, [lr, r2]
 *   @0x2d6ccc mov r3, lr
 *   @0x2d6cd0 ldr r1, [r4, r1, lsl #2]
 *   @0x2d6cd4 str r1, [r3, r2]!
 *   @0x2d6cd8 add r2, r2, #20
 *   @0x2d6cdc ldr r1, [r3, #0x4]
 *   @0x2d6ce0 cmp r2, r0
 *   @0x2d6ce4 ldr r1, [r4, r1, lsl #2]
 *   @0x2d6ce8 str r1, [r3, #0x4]
 *   @0x2d6cec bne 0x2d6cc8 <_ZN16b2ParticleSystem11SolveZombieEv+0x6bc>
 *   @0x2d6cf0 add r12, r6, r12
 *   @0x2d6cf4 sbfx r3, r12, #0x0, #0x1e
 *   @0x2d6cf8 add r12, lr, r12, lsl #2
 *   @0x2d6cfc str r12, [sp, #0x10]
 *   @0x2d6d00 add r2, r3, r3, lsl #1
 *   @0x2d6d04 add r2, r2, r2, lsl #4
 *   @0x2d6d08 add r2, r2, r2, lsl #8
 *   @0x2d6d0c add r2, r2, r2, lsl #16
 *   @0x2d6d10 add r2, r3, r2, lsl #2
 *   @0x2d6d14 str r2, [sp, #0xc]
 *   @0x2d6d18 asr r8, r2, #2
 *   @0x2d6d1c str r8, [sp]
 *   @0x2d6d20 cmp r8, #0
 *   @0x2d6d24 movle r3, r2
 *   @0x2d6d28 movle r12, lr
 *   @0x2d6d2c ble 0x2d7300 <_ZN16b2ParticleSystem11SolveZombieEv+0xcf4>
 *   @0x2d6d30 ldr r3, [lr]
 *   @0x2d6d34 cmp r3, #0
 *   @0x2d6d38 blt 0x2d7264 <_ZN16b2ParticleSystem11SolveZombieEv+0xc58>
 *   @0x2d6d3c ldr r3, [lr, #0x4]
 *   @0x2d6d40 cmp r3, #0
 *   @0x2d6d44 blt 0x2d7264 <_ZN16b2ParticleSystem11SolveZombieEv+0xc58>
 *   @0x2d6d48 ldr r3, [lr, #0x14]
 *   @0x2d6d4c add r12, lr, #20
 *   @0x2d6d50 cmp r3, #0
 *   @0x2d6d54 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6d58 ldr r3, [lr, #0x18]
 *   @0x2d6d5c cmp r3, #0
 *   @0x2d6d60 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6d64 ldr r3, [lr, #0x28]
 *   @0x2d6d68 add r1, lr, #40
 *   @0x2d6d6c str r1, [sp, #0x4]
 *   @0x2d6d70 cmp r3, #0
 *   @0x2d6d74 mov r12, r1
 *   @0x2d6d78 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6d7c add r9, lr, #60
 *   @0x2d6d80 add r6, lr, #80
 *   @0x2d6d84 add r10, lr, #100
 *   @0x2d6d88 mov r2, lr
 *   @0x2d6d8c add r1, lr, #120
 *   @0x2d6d90 str r1, [sp, #0x8]
 *   @0x2d6d94 ldr r8, [sp, #0x4]
 *   @0x2d6d98 rsb r3, lr, r2
 *   @0x2d6d9c add r1, r3, r9
 *   @0x2d6da0 add r7, r3, r6
 *   @0x2d6da4 add r0, r3, r8
 *   @0x2d6da8 ldr r0, [r0, #0x4]
 *   @0x2d6dac cmp r0, #0
 *   @0x2d6db0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6db4 ldr r0, [r3, r9]
 *   @0x2d6db8 add r12, r2, #60
 *   @0x2d6dbc cmp r0, #0
 *   @0x2d6dc0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6dc4 ldr r1, [r1, #0x4]
 *   @0x2d6dc8 add r8, r3, r10
 *   @0x2d6dcc cmp r1, #0
 *   @0x2d6dd0 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6dd4 ldr r1, [sp]
 *   @0x2d6dd8 add r12, r2, #80
 *   @0x2d6ddc rsb r11, lr, r12
 *   @0x2d6de0 subs r1, r1, #1
 *   @0x2d6de4 str r1, [sp]
 *   @0x2d6de8 ldr r1, [sp, #0x8]
 *   @0x2d6dec mov r0, r12
 *   @0x2d6df0 add r11, r11, r1
 *   @0x2d6df4 beq 0x2d72e0 <_ZN16b2ParticleSystem11SolveZombieEv+0xcd4>
 *   @0x2d6df8 ldr r1, [r3, r6]
 *   @0x2d6dfc cmp r1, #0
 *   @0x2d6e00 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6e04 ldr r1, [r7, #0x4]
 *   @0x2d6e08 cmp r1, #0
 *   @0x2d6e0c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6e10 ldr r3, [r3, r10]
 *   @0x2d6e14 add r12, r2, #100
 *   @0x2d6e18 cmp r3, #0
 *   @0x2d6e1c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6e20 ldr r3, [r8, #0x4]
 *   @0x2d6e24 cmp r3, #0
 *   @0x2d6e28 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d6e2c ldr r3, [r11, #-0x50]
 *   @0x2d6e30 add r12, r2, #120
 *   @0x2d6e34 mov r2, r0
 *   @0x2d6e38 cmp r3, #0
 *   @0x2d6e3c bge 0x2d6d94 <_ZN16b2ParticleSystem11SolveZombieEv+0x788>
 *   @0x2d6e40 ldr r2, [sp, #0x10]
 *   @0x2d6e44 cmp r2, r12
 *   @0x2d6e48 beq 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0>
 *   @0x2d6e4c add r3, r12, #20
 *   @0x2d6e50 cmp r2, r3
 *   @0x2d6e54 beq 0x2d6eac <_ZN16b2ParticleSystem11SolveZombieEv+0x8a0>
 *   @0x2d6e58 add r6, r12, #40
 *   @0x2d6e5c add r9, r12, #60
 *   @0x2d6e60 rsb r3, r6, r2
 *   @0x2d6e64 bic r3, r3, #3
 *   @0x2d6e68 add r9, r9, r3
 *   @0x2d6e6c ldr r3, [r6, #-0x14]
 *   @0x2d6e70 sub r8, r6, #20
 *   @0x2d6e74 mov r7, r12
 *   @0x2d6e78 cmp r3, #0
 *   @0x2d6e7c blt 0x2d6ea0 <_ZN16b2ParticleSystem11SolveZombieEv+0x894>
 *   @0x2d6e80 ldr r3, [r6, #-0x10]
 *   @0x2d6e84 cmp r3, #0
 *   @0x2d6e88 blt 0x2d6ea0 <_ZN16b2ParticleSystem11SolveZombieEv+0x894>
 *   @0x2d6e8c ldm r8!, {r0, r1, r2, r3}
 *   @0x2d6e90 add r12, r12, #20
 *   @0x2d6e94 stm r7!, {r0, r1, r2, r3}
 *   @0x2d6e98 ldr r3, [r8]
 *   @0x2d6e9c str r3, [r7]
 *   @0x2d6ea0 add r6, r6, #20
 *   @0x2d6ea4 cmp r6, r9
 *   @0x2d6ea8 bne 0x2d6e6c <_ZN16b2ParticleSystem11SolveZombieEv+0x860>
 *   @0x2d6eac rsb r3, lr, r12
 *   @0x2d6eb0 asr r3, r3, #2
 *   @0x2d6eb4 add r2, r3, r3, lsl #1
 *   @0x2d6eb8 add r2, r2, r2, lsl #4
 *   @0x2d6ebc add r2, r2, r2, lsl #8
 *   @0x2d6ec0 add r2, r2, r2, lsl #16
 *   @0x2d6ec4 add r2, r3, r2, lsl #2
 *   @0x2d6ec8 str r2, [sp, #0xc]
 *   @0x2d6ecc ldr lr, [r5, #0x98]
 *   @0x2d6ed0 ldr r3, [sp, #0xc]
 *   @0x2d6ed4 cmp lr, #0
 *   @0x2d6ed8 lslle r7, lr, #4
 *   @0x2d6edc str r3, [r5, #0x8c]
 *   @0x2d6ee0 ldrle r6, [r5, #0xa0]
 *   @0x2d6ee4 ble 0x2d6f30 <_ZN16b2ParticleSystem11SolveZombieEv+0x924>
 *   @0x2d6ee8 lsl r7, lr, #4
 *   @0x2d6eec ldr r6, [r5, #0xa0]
 *   @0x2d6ef0 rsb r12, lr, r7
 *   @0x2d6ef4 add r3, r6, #8
 *   @0x2d6ef8 add r12, r6, r12, lsl #2
 *   @0x2d6efc mov r2, r6
 *   @0x2d6f00 ldmdb r3, {r0, r1}
 *   @0x2d6f04 add r2, r2, #60
 *   @0x2d6f08 add r3, r3, #60
 *   @0x2d6f0c ldr r0, [r4, r0, lsl #2]
 *   @0x2d6f10 str r0, [r3, #-0x44]
 *   @0x2d6f14 ldr r1, [r4, r1, lsl #2]
 *   @0x2d6f18 str r1, [r3, #-0x40]
 *   @0x2d6f1c ldr r1, [r2, #-0x34]
 *   @0x2d6f20 ldr r1, [r4, r1, lsl #2]
 *   @0x2d6f24 str r1, [r2, #-0x34]
 *   @0x2d6f28 cmp r2, r12
 *   @0x2d6f2c bne 0x2d6f00 <_ZN16b2ParticleSystem11SolveZombieEv+0x8f4>
 *   @0x2d6f30 rsb lr, lr, r7
 *   @0x2d6f34 sbfx r3, lr, #0x0, #0x1e
 *   @0x2d6f38 add lr, r6, lr, lsl #2
 *   @0x2d6f3c str lr, [sp, #0x8]
 *   @0x2d6f40 add r3, r3, r3, lsl #4
 *   @0x2d6f44 add r3, r3, r3, lsl #8
 *   @0x2d6f48 add r3, r3, r3, lsl #16
 *   @0x2d6f4c rsb r3, r3, #0
 *   @0x2d6f50 str r3, [sp, #0x4]
 *   @0x2d6f54 asr r11, r3, #2
 *   @0x2d6f58 cmp r11, #0
 *   @0x2d6f5c movle r12, r6
 *   @0x2d6f60 ble 0x2d7288 <_ZN16b2ParticleSystem11SolveZombieEv+0xc7c>
 *   @0x2d6f64 ldr r3, [r6]
 *   @0x2d6f68 cmp r3, #0
 *   @0x2d6f6c blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48>
 *   @0x2d6f70 ldr r3, [r6, #0x4]
 *   @0x2d6f74 cmp r3, #0
 *   @0x2d6f78 blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48>
 *   @0x2d6f7c ldr r3, [r6, #0x8]
 *   @0x2d6f80 cmp r3, #0
 *   @0x2d6f84 blt 0x2d7254 <_ZN16b2ParticleSystem11SolveZombieEv+0xc48>
 *   @0x2d6f88 ldr r3, [r6, #0x3c]
 *   @0x2d6f8c add r9, r6, #60
 *   @0x2d6f90 cmp r3, #0
 *   @0x2d6f94 mov r12, r9
 *   @0x2d6f98 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d6f9c ldr r3, [r6, #0x40]
 *   @0x2d6fa0 cmp r3, #0
 *   @0x2d6fa4 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d6fa8 add r8, r6, #240
 *   @0x2d6fac add r3, r6, #248
 *   @0x2d6fb0 str r8, [sp]
 *   @0x2d6fb4 mov r1, r6
 *   @0x2d6fb8 add lr, r6, #120
 *   @0x2d6fbc add r7, r6, #180
 *   @0x2d6fc0 add r8, r6, #300
 *   @0x2d6fc4 b 0x2d7008 <_ZN16b2ParticleSystem11SolveZombieEv+0x9fc>
 *   @0x2d6fc8 ldr r0, [r3, #-0x4]
 *   @0x2d6fcc cmp r0, #0
 *   @0x2d6fd0 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d6fd4 ldr r0, [r3]
 *   @0x2d6fd8 cmp r0, #0
 *   @0x2d6fdc blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d6fe0 ldr r0, [r2, r8]
 *   @0x2d6fe4 add r12, r1, #300
 *   @0x2d6fe8 cmp r0, #0
 *   @0x2d6fec blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d6ff0 add r2, r2, r8
 *   @0x2d6ff4 add r3, r3, #240
 *   @0x2d6ff8 ldr r2, [r2, #0x4]
 *   @0x2d6ffc cmp r2, #0
 *   @0x2d7000 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7004 mov r1, r10
 *   @0x2d7008 ldr r2, [sp]
 *   @0x2d700c rsb r0, r2, r3
 *   @0x2d7010 ldr r2, [r0, r9]
 *   @0x2d7014 cmp r2, #0
 *   @0x2d7018 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d701c rsb r2, r6, r1
 *   @0x2d7020 add r12, r1, #120
 *   @0x2d7024 ldr r10, [r2, lr]
 *   @0x2d7028 cmp r10, #0
 *   @0x2d702c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7030 add r10, r2, lr
 *   @0x2d7034 ldr r10, [r10, #0x4]
 *   @0x2d7038 cmp r10, #0
 *   @0x2d703c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7040 ldr r10, [r0, lr]
 *   @0x2d7044 cmp r10, #0
 *   @0x2d7048 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d704c ldr r10, [r2, r7]
 *   @0x2d7050 add r12, r1, #180
 *   @0x2d7054 cmp r10, #0
 *   @0x2d7058 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d705c add r10, r2, r7
 *   @0x2d7060 ldr r10, [r10, #0x4]
 *   @0x2d7064 cmp r10, #0
 *   @0x2d7068 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d706c ldr r0, [r0, r7]
 *   @0x2d7070 cmp r0, #0
 *   @0x2d7074 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7078 add r12, r1, #240
 *   @0x2d707c subs r11, r11, #1
 *   @0x2d7080 mov r10, r12
 *   @0x2d7084 beq 0x2d726c <_ZN16b2ParticleSystem11SolveZombieEv+0xc60>
 *   @0x2d7088 ldr r0, [r3, #-0x8]
 *   @0x2d708c cmp r0, #0
 *   @0x2d7090 bge 0x2d6fc8 <_ZN16b2ParticleSystem11SolveZombieEv+0x9bc>
 *   @0x2d7094 ldr r1, [sp, #0x8]
 *   @0x2d7098 cmp r1, r12
 *   @0x2d709c beq 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c>
 *   @0x2d70a0 add r3, r12, #60
 *   @0x2d70a4 cmp r1, r3
 *   @0x2d70a8 beq 0x2d711c <_ZN16b2ParticleSystem11SolveZombieEv+0xb10>
 *   @0x2d70ac add r8, r12, #120
 *   @0x2d70b0 add r9, r12, #180
 *   @0x2d70b4 rsb r3, r8, r1
 *   @0x2d70b8 bic r3, r3, #3
 *   @0x2d70bc add r9, r9, r3
 *   @0x2d70c0 ldr r3, [r8, #-0x3c]
 *   @0x2d70c4 sub r7, r8, #60
 *   @0x2d70c8 mov lr, r12
 *   @0x2d70cc cmp r3, #0
 *   @0x2d70d0 blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04>
 *   @0x2d70d4 ldr r3, [r8, #-0x38]
 *   @0x2d70d8 cmp r3, #0
 *   @0x2d70dc blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04>
 *   @0x2d70e0 ldr r3, [r8, #-0x34]
 *   @0x2d70e4 cmp r3, #0
 *   @0x2d70e8 blt 0x2d7110 <_ZN16b2ParticleSystem11SolveZombieEv+0xb04>
 *   @0x2d70ec ldm r7!, {r0, r1, r2, r3}
 *   @0x2d70f0 add r12, r12, #60
 *   @0x2d70f4 stm lr!, {r0, r1, r2, r3}
 *   @0x2d70f8 ldm r7!, {r0, r1, r2, r3}
 *   @0x2d70fc stm lr!, {r0, r1, r2, r3}
 *   @0x2d7100 ldm r7!, {r0, r1, r2, r3}
 *   @0x2d7104 stm lr!, {r0, r1, r2, r3}
 *   @0x2d7108 ldm r7, {r0, r1, r2}
 *   @0x2d710c stm lr, {r0, r1, r2}
 *   @0x2d7110 add r8, r8, #60
 *   @0x2d7114 cmp r8, r9
 *   @0x2d7118 bne 0x2d70c0 <_ZN16b2ParticleSystem11SolveZombieEv+0xab4>
 *   @0x2d711c rsb r3, r6, r12
 *   @0x2d7120 asr r3, r3, #2
 *   @0x2d7124 add r3, r3, r3, lsl #4
 *   @0x2d7128 add r3, r3, r3, lsl #8
 *   @0x2d712c add r3, r3, r3, lsl #16
 *   @0x2d7130 rsb r3, r3, #0
 *   @0x2d7134 str r3, [sp, #0x4]
 *   @0x2d7138 ldr r6, [r5, #0xa8]
 *   @0x2d713c ldr r2, [sp, #0x4]
 *   @0x2d7140 cmp r6, #0
 *   @0x2d7144 str r2, [r5, #0x98]
 *   @0x2d7148 movne r8, #0
 *   @0x2d714c ldrne r9, [sp, #0x14]
 *   @0x2d7150 beq 0x2d71d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xbcc>
 *   @0x2d7154 ldmib r6, {r2, lr}
 *   @0x2d7158 cmp r2, lr
 *   @0x2d715c bge 0x2d7238 <_ZN16b2ParticleSystem11SolveZombieEv+0xc2c>
 *   @0x2d7160 mov r7, #0
 *   @0x2d7164 add r2, r4, r2, lsl #2
 *   @0x2d7168 add lr, r4, lr, lsl #2
 *   @0x2d716c mov r12, r9
 *   @0x2d7170 mov r0, r7
 *   @0x2d7174 ldr r3, [r2], #4
 *   @0x2d7178 cmp r3, #0
 *   @0x2d717c add r1, r3, #1
 *   @0x2d7180 movlt r7, #1
 *   @0x2d7184 blt 0x2d7198 <_ZN16b2ParticleSystem11SolveZombieEv+0xb8c>
 *   @0x2d7188 cmp r12, r3
 *   @0x2d718c movge r12, r3
 *   @0x2d7190 cmp r0, r1
 *   @0x2d7194 movlt r0, r1
 *   @0x2d7198 cmp r2, lr
 *   @0x2d719c bne 0x2d7174 <_ZN16b2ParticleSystem11SolveZombieEv+0xb68>
 *   @0x2d71a0 cmp r12, r0
 *   @0x2d71a4 bge 0x2d7238 <_ZN16b2ParticleSystem11SolveZombieEv+0xc2c>
 *   @0x2d71a8 cmp r7, #0
 *   @0x2d71ac str r12, [r6, #0x4]
 *   @0x2d71b0 str r0, [r6, #0x8]
 *   @0x2d71b4 beq 0x2d71cc <_ZN16b2ParticleSystem11SolveZombieEv+0xbc0>
 *   @0x2d71b8 ldr r3, [r6, #0xc]
 *   @0x2d71bc tst r3, #2
 *   @0x2d71c0 ldrbne r3, [r6, #0x4c]
 *   @0x2d71c4 orrne r3, r3, #4
 *   @0x2d71c8 strbne r3, [r6, #0x4c]
 *   @0x2d71cc ldr r6, [r6, #0x18]
 *   @0x2d71d0 cmp r6, #0
 *   @0x2d71d4 bne 0x2d7154 <_ZN16b2ParticleSystem11SolveZombieEv+0xb48>
 *   @0x2d71d8 ldr r8, [sp, #0x14]
 *   @0x2d71dc mov r1, r4
 *   @0x2d71e0 ldr r0, [r5, #0xd4]
 *   @0x2d71e4 str r8, [r5, #0x24]
 *   @0x2d71e8 add r0, r0, #68
 *   @0x2d71ec bl 0x2e0ffc <_ZN16b2StackAllocator4FreeEPv>
 *   @0x2d71f0 ldr r1, [r5, #0xa8]
 *   @0x2d71f4 cmp r1, #0
 *   @0x2d71f8 bne 0x2d720c <_ZN16b2ParticleSystem11SolveZombieEv+0xc00>
 *   @0x2d71fc b 0x2d7230 <_ZN16b2ParticleSystem11SolveZombieEv+0xc24>
 *   @0x2d7200 cmp r4, #0
 *   @0x2d7204 mov r1, r4
 *   @0x2d7208 beq 0x2d7230 <_ZN16b2ParticleSystem11SolveZombieEv+0xc24>
 *   @0x2d720c ldrb r3, [r1, #0x4c]
 *   @0x2d7210 ldr r4, [r1, #0x18]
 *   @0x2d7214 tst r3, #2
 *   @0x2d7218 beq 0x2d7200 <_ZN16b2ParticleSystem11SolveZombieEv+0xbf4>
 *   @0x2d721c mov r0, r5
 *   @0x2d7220 bl 0x2d5874 <_ZN16b2ParticleSystem20DestroyParticleGroupEP15b2ParticleGroup>
 *   @0x2d7224 cmp r4, #0
 *   @0x2d7228 mov r1, r4
 *   @0x2d722c bne 0x2d720c <_ZN16b2ParticleSystem11SolveZombieEv+0xc00>
 *   @0x2d7230 add sp, sp, #28
 *   @0x2d7234 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2d7238 ldrb r3, [r6, #0x4c]
 *   @0x2d723c str r8, [r6, #0x4]
 *   @0x2d7240 tst r3, #1
 *   @0x2d7244 str r8, [r6, #0x8]
 *   @0x2d7248 orrne r3, r3, #2
 *   @0x2d724c strbne r3, [r6, #0x4c]
 *   @0x2d7250 b 0x2d71cc <_ZN16b2ParticleSystem11SolveZombieEv+0xbc0>
 *   @0x2d7254 mov r12, r6
 *   @0x2d7258 b 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d725c mov r12, lr
 *   @0x2d7260 b 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d7264 mov r12, lr
 *   @0x2d7268 b 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d726c ldr r8, [sp, #0x8]
 *   @0x2d7270 rsb r3, r12, r8
 *   @0x2d7274 asr r3, r3, #2
 *   @0x2d7278 add r3, r3, r3, lsl #4
 *   @0x2d727c add r3, r3, r3, lsl #8
 *   @0x2d7280 add r3, r3, r3, lsl #16
 *   @0x2d7284 rsb r3, r3, #0
 *   @0x2d7288 cmp r3, #2
 *   @0x2d728c beq 0x2d744c <_ZN16b2ParticleSystem11SolveZombieEv+0xe40>
 *   @0x2d7290 cmp r3, #3
 *   @0x2d7294 beq 0x2d7424 <_ZN16b2ParticleSystem11SolveZombieEv+0xe18>
 *   @0x2d7298 cmp r3, #1
 *   @0x2d729c bne 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c>
 *   @0x2d72a0 b 0x2d7474 <_ZN16b2ParticleSystem11SolveZombieEv+0xe68>
 *   @0x2d72a4 ldr r3, [sp, #0x10]
 *   @0x2d72a8 rsb r2, r12, r3
 *   @0x2d72ac asr r2, r2, #3
 *   @0x2d72b0 add r3, r2, r2, lsl #2
 *   @0x2d72b4 add r3, r3, r3, lsl #4
 *   @0x2d72b8 add r3, r3, r3, lsl #8
 *   @0x2d72bc add r3, r3, r3, lsl #16
 *   @0x2d72c0 add r3, r2, r3, lsl #1
 *   @0x2d72c4 cmp r3, #2
 *   @0x2d72c8 beq 0x2d73bc <_ZN16b2ParticleSystem11SolveZombieEv+0xdb0>
 *   @0x2d72cc cmp r3, #3
 *   @0x2d72d0 beq 0x2d73a0 <_ZN16b2ParticleSystem11SolveZombieEv+0xd94>
 *   @0x2d72d4 cmp r3, #1
 *   @0x2d72d8 bne 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4>
 *   @0x2d72dc b 0x2d73d8 <_ZN16b2ParticleSystem11SolveZombieEv+0xdcc>
 *   @0x2d72e0 ldr r3, [sp, #0x10]
 *   @0x2d72e4 rsb r2, r12, r3
 *   @0x2d72e8 asr r2, r2, #2
 *   @0x2d72ec add r3, r2, r2, lsl #1
 *   @0x2d72f0 add r3, r3, r3, lsl #4
 *   @0x2d72f4 add r3, r3, r3, lsl #8
 *   @0x2d72f8 add r3, r3, r3, lsl #16
 *   @0x2d72fc add r3, r2, r3, lsl #2
 *   @0x2d7300 cmp r3, #2
 *   @0x2d7304 beq 0x2d7368 <_ZN16b2ParticleSystem11SolveZombieEv+0xd5c>
 *   @0x2d7308 cmp r3, #3
 *   @0x2d730c beq 0x2d734c <_ZN16b2ParticleSystem11SolveZombieEv+0xd40>
 *   @0x2d7310 cmp r3, #1
 *   @0x2d7314 bne 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0>
 *   @0x2d7318 b 0x2d7384 <_ZN16b2ParticleSystem11SolveZombieEv+0xd78>
 *   @0x2d731c ldr r3, [r12]
 *   @0x2d7320 cmp r3, #0
 *   @0x2d7324 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d7328 add r12, r12, #24
 *   @0x2d732c ldr r3, [r12]
 *   @0x2d7330 cmp r3, #0
 *   @0x2d7334 blt 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d7338 add r12, r12, #24
 *   @0x2d733c ldr r3, [r12]
 *   @0x2d7340 cmp r3, #0
 *   @0x2d7344 bge 0x2d6c9c <_ZN16b2ParticleSystem11SolveZombieEv+0x690>
 *   @0x2d7348 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d734c ldr r3, [r12]
 *   @0x2d7350 cmp r3, #0
 *   @0x2d7354 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d7358 ldr r3, [r12, #0x4]
 *   @0x2d735c cmp r3, #0
 *   @0x2d7360 addge r12, r12, #20
 *   @0x2d7364 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d7368 ldr r3, [r12]
 *   @0x2d736c cmp r3, #0
 *   @0x2d7370 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d7374 ldr r3, [r12, #0x4]
 *   @0x2d7378 cmp r3, #0
 *   @0x2d737c addge r12, r12, #20
 *   @0x2d7380 blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d7384 ldr r3, [r12]
 *   @0x2d7388 cmp r3, #0
 *   @0x2d738c blt 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d7390 ldr r3, [r12, #0x4]
 *   @0x2d7394 cmp r3, #0
 *   @0x2d7398 bge 0x2d6ecc <_ZN16b2ParticleSystem11SolveZombieEv+0x8c0>
 *   @0x2d739c b 0x2d6e40 <_ZN16b2ParticleSystem11SolveZombieEv+0x834>
 *   @0x2d73a0 ldr r3, [r12]
 *   @0x2d73a4 cmp r3, #0
 *   @0x2d73a8 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73ac ldr r3, [r12, #0x4]
 *   @0x2d73b0 cmp r3, #0
 *   @0x2d73b4 addge r12, r12, #24
 *   @0x2d73b8 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73bc ldr r3, [r12]
 *   @0x2d73c0 cmp r3, #0
 *   @0x2d73c4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73c8 ldr r3, [r12, #0x4]
 *   @0x2d73cc cmp r3, #0
 *   @0x2d73d0 addge r12, r12, #24
 *   @0x2d73d4 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73d8 ldr r3, [r12]
 *   @0x2d73dc cmp r3, #0
 *   @0x2d73e0 blt 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73e4 ldr r3, [r12, #0x4]
 *   @0x2d73e8 cmp r3, #0
 *   @0x2d73ec bge 0x2d6ae0 <_ZN16b2ParticleSystem11SolveZombieEv+0x4d4>
 *   @0x2d73f0 b 0x2d6a54 <_ZN16b2ParticleSystem11SolveZombieEv+0x448>
 *   @0x2d73f4 ldr r1, [r3]
 *   @0x2d73f8 cmp r1, #0
 *   @0x2d73fc blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d7400 add r3, r3, #8
 *   @0x2d7404 ldr r1, [r3]
 *   @0x2d7408 cmp r1, #0
 *   @0x2d740c blt 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d7410 add r3, r3, #8
 *   @0x2d7414 ldr r1, [r3]
 *   @0x2d7418 cmp r1, #0
 *   @0x2d741c bge 0x2d68b0 <_ZN16b2ParticleSystem11SolveZombieEv+0x2a4>
 *   @0x2d7420 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d7424 ldr r3, [r12]
 *   @0x2d7428 cmp r3, #0
 *   @0x2d742c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7430 ldr r3, [r12, #0x4]
 *   @0x2d7434 cmp r3, #0
 *   @0x2d7438 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d743c ldr r3, [r12, #0x8]
 *   @0x2d7440 cmp r3, #0
 *   @0x2d7444 addge r12, r12, #60
 *   @0x2d7448 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d744c ldr r3, [r12]
 *   @0x2d7450 cmp r3, #0
 *   @0x2d7454 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7458 ldr r3, [r12, #0x4]
 *   @0x2d745c cmp r3, #0
 *   @0x2d7460 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7464 ldr r3, [r12, #0x8]
 *   @0x2d7468 cmp r3, #0
 *   @0x2d746c addge r12, r12, #60
 *   @0x2d7470 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7474 ldr r3, [r12]
 *   @0x2d7478 cmp r3, #0
 *   @0x2d747c blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d7480 ldr r3, [r12, #0x4]
 *   @0x2d7484 cmp r3, #0
 *   @0x2d7488 blt 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d748c ldr r3, [r12, #0x8]
 *   @0x2d7490 cmp r3, #0
 *   @0x2d7494 bge 0x2d7138 <_ZN16b2ParticleSystem11SolveZombieEv+0xb2c>
 *   @0x2d7498 b 0x2d7094 <_ZN16b2ParticleSystem11SolveZombieEv+0xa88>
 *   @0x2d749c add r3, r1, #40
 *   @0x2d74a0 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d74a4 add r3, r1, #48
 *   @0x2d74a8 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d74ac add r12, r3, #120
 *   @0x2d74b0 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d74b4 add r12, r3, #144
 *   @0x2d74b8 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d74bc add r12, r3, #168
 *   @0x2d74c0 b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d74c4 add r3, r1, #56
 *   @0x2d74c8 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d74cc mov r8, #0
 *   @0x2d74d0 str r8, [sp, #0x14]
 *   @0x2d74d4 b 0x2d6750 <_ZN16b2ParticleSystem11SolveZombieEv+0x144>
 *   @0x2d74d8 mov r12, lr
 *   @0x2d74dc b 0x2d6c28 <_ZN16b2ParticleSystem11SolveZombieEv+0x61c>
 *   @0x2d74e0 mov r3, r10
 *   @0x2d74e4 mov r12, lr
 *   @0x2d74e8 b 0x2d6c08 <_ZN16b2ParticleSystem11SolveZombieEv+0x5fc>
 *   @0x2d74ec mov r3, r2
 *   @0x2d74f0 b 0x2d6860 <_ZN16b2ParticleSystem11SolveZombieEv+0x254>
 *   @0x2d74f4 mov r1, r11
 *   @0x2d74f8 mov r3, r2
 *   @0x2d74fc b 0x2d6840 <_ZN16b2ParticleSystem11SolveZombieEv+0x234>
 *
 * ══ §5/7 YYIAPEventsDispatch  0x153be8  size 3720  928 条（0x153be8..0x154a70）
 * @func 0x153be8 0x154a70  size 3720  928 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x153ce0→0x4836b0, 0x153cfc→0x3f524c, 0x153d04→0x536f20, 0x153d08→0x536f70, 0x153ec0→0x3f2358, 0x153f50→0x3eb708, 0x153fd8→0x53ab70, 0x153fe4→0x542374
 * 调用序列: MemoryManager::Free(void const*)×15 / YYSetString(RValue*, char const*)×8 / CDS_Map::Add(char const*, double, char const*)×8 / FREE_RValue__Pre(RValue*)×8 / CDS_Map::Find(RValue*)×6 / 0xb66d0×5 / DsQueueSize(int)×4 / 0xb66e8×3
 * 字段偏移 top8: 0x4×21 / 0x-94×15 / 0x-58×13 / 0x-90×11 / 0x-4c×11 / 0x10×9 / 0x14×8 / 0x-50×8
 * VFP 指令 27 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x153be8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x153bec vpush {d8, d9}
 *   @0x153bf0 add r11, sp, #48
 *   @0x153bf4 ldr r12, [pc, #0x43c]
 *   @0x153bf8 sub sp, sp, #196
 *   @0x153bfc ldr r3, [pc, #0x438]
 *   @0x153c00 add r12, pc, r12
 *   @0x153c04 str r12, [r11, #-0x94]
 *   @0x153c08 sub r12, r11, #140
 *   @0x153c0c str r12, [r11, #-0xd8]
 *   @0x153c10 ldr r4, [pc, #0x428]
 *   @0x153c14 mov r0, r12
 *   @0x153c18 ldr r12, [r11, #-0x94]
 *   @0x153c1c add r4, pc, r4
 *   @0x153c20 ldr r3, [r12, r3]
 *   @0x153c24 str r3, [r11, #-0xdc]
 *   @0x153c28 ldr r3, [r3]
 *   @0x153c2c str r3, [r11, #-0x38]
 *   @0x153c30 bl 0xfec18 <_ZN12DS_AutoMutexC2Ev>
 *   @0x153c34 ldr r3, [pc, #0x408]
 *   @0x153c38 ldr r0, [pc, r3]
 *   @0x153c3c bl 0x27e084 <_ZN5Mutex4LockEv>
 *   @0x153c40 ldr r0, [r4]
 *   @0x153c44 cmp r0, #0
 *   @0x153c48 blt 0x153e0c <_Z19YYIAPEventsDispatchv+0x224>
 *   @0x153c4c bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x153c50 cmp r0, #0
 *   @0x153c54 ble 0x153e0c <_Z19YYIAPEventsDispatchv+0x224>
 *   @0x153c58 ldr r0, [r4]
 *   @0x153c5c sub r7, r11, #52
 *   @0x153c60 bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x153c64 mov r3, #0
 *   @0x153c68 str r3, [r7, #-0x24]!
 *   @0x153c6c mov r8, #0
 *   @0x153c70 str r3, [r11, #-0xac]
 *   @0x153c74 lsl r0, r0, #2
 *   @0x153c78 add r3, r0, #14
 *   @0x153c7c bic r3, r3, #7
 *   @0x153c80 sub sp, sp, r3
 *   @0x153c84 add r6, sp, #8
 *   @0x153c88 sub r5, r6, #4
 *   @0x153c8c b 0x153ca8 <_Z19YYIAPEventsDispatchv+0xc0>
 *   @0x153c90 ldr r0, [r4]
 *   @0x153c94 mov r1, r7
 *   @0x153c98 bl 0x20557c <_Z14DsQueueDequeueiR6RValue>
 *   @0x153c9c ldr r3, [r11, #-0x58]
 *   @0x153ca0 add r8, r8, #1
 *   @0x153ca4 str r3, [r5, #0x4]!
 *   @0x153ca8 ldr r0, [r4]
 *   @0x153cac bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x153cb0 cmp r0, #0
 *   @0x153cb4 bgt 0x153c90 <_Z19YYIAPEventsDispatchv+0xa8>
 *   @0x153cb8 ldr r0, [r4]
 *   @0x153cbc str r8, [r11, #-0xac]
 *   @0x153cc0 bl 0x205620 <_Z12DsQueueCleari>
 *   @0x153cc4 ldr r3, [pc, #0x37c]
 *   @0x153cc8 ldr r0, [pc, r3]
 *   @0x153ccc bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x153cd0 ldr r8, [r11, #-0xac]
 *   @0x153cd4 cmp r8, #0
 *   @0x153cd8 beq 0x153e18 <_Z19YYIAPEventsDispatchv+0x230>
 *   @0x153cdc sub r12, r11, #136
 *   @0x153ce0 ldr r0, [pc, #0x364]
 *   @0x153ce4 str r12, [r11, #-0xa4]
 *   @0x153ce8 mov r12, #0
 *   @0x153cec str r12, [r11, #-0x9c]
 *   @0x153cf0 vldr d8, [pc, #824]
 *   @0x153cf4 ldr r12, [r11, #-0x94]
 *   @0x153cf8 str r6, [r11, #-0xa0]
 *   @0x153cfc ldr r1, [pc, #0x34c]
 *   @0x153d00 ldr r0, [r12, r0]
 *   @0x153d04 ldr r2, [pc, #0x348]
 *   @0x153d08 ldr r3, [pc, #0x348]
 *   @0x153d0c str r0, [r11, #-0xb8]
 *   @0x153d10 ldr r1, [r12, r1]
 *   @0x153d14 str r1, [r11, #-0xb4]
 *   @0x153d18 ldr r2, [r12, r2]
 *   @0x153d1c str r2, [r11, #-0xa8]
 *   @0x153d20 ldr r8, [r12, r3]
 *   @0x153d24 ldr r12, [pc, #0x330]
 *   @0x153d28 add r12, pc, r12
 *   @0x153d2c str r12, [r11, #-0xbc]
 *   @0x153d30 ldr r12, [pc, #0x328]
 *   @0x153d34 mov r10, r8
 *   @0x153d38 add r12, pc, r12
 *   @0x153d3c str r12, [r11, #-0xcc]
 *   @0x153d40 ldr r12, [pc, #0x31c]
 *   @0x153d44 add r12, pc, r12
 *   @0x153d48 str r12, [r11, #-0xe4]
 *   @0x153d4c ldr r12, [pc, #0x314]
 *   @0x153d50 add r12, pc, r12
 *   @0x153d54 str r12, [r11, #-0xd0]
 *   @0x153d58 ldr r12, [pc, #0x30c]
 *   @0x153d5c add r12, pc, r12
 *   @0x153d60 str r12, [r11, #-0xe8]
 *   @0x153d64 bl 0x100014 <_Z18FindFreeDsMapIndexv>
 *   @0x153d68 ldr r12, [r11, #-0xa0]
 *   @0x153d6c ldr r1, [r11, #-0xbc]
 *   @0x153d70 ldr r2, [r12]
 *   @0x153d74 ldr r12, [r11, #-0xb8]
 *   @0x153d78 ldr r3, [r12, #0x4]
 *   @0x153d7c str r0, [r11, #-0x98]
 *   @0x153d80 sub r0, r11, #136
 *   @0x153d84 ldr r12, [r11, #-0x98]
 *   @0x153d88 str r2, [r3, r12, lsl #2]
 *   @0x153d8c ldr r12, [r11, #-0xa0]
 *   @0x153d90 ldr r9, [r12], #4
 *   @0x153d94 str r12, [r11, #-0xa0]
 *   @0x153d98 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x153d9c mov r0, r9
 *   @0x153da0 sub r1, r11, #136
 *   @0x153da4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x153da8 ldr r3, [r11, #-0x7c]
 *   @0x153dac sub r3, r3, #1
 *   @0x153db0 bic r3, r3, #-16777216
 *   @0x153db4 bic r3, r3, #3
 *   @0x153db8 cmp r3, #0
 *   @0x153dbc mov r4, r0
 *   @0x153dc0 beq 0x154750 <_Z19YYIAPEventsDispatchv+0xb68>
 *   @0x153dc4 cmp r4, #0
 *   @0x153dc8 mov r3, #0
 *   @0x153dcc mov r2, #5
 *   @0x153dd0 str r3, [r11, #-0x80]
 *   @0x153dd4 str r3, [r11, #-0x88]
 *   @0x153dd8 str r2, [r11, #-0x7c]
 *   @0x153ddc beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x153de0 ldr r0, [r4, #0x10]
 *   @0x153de4 ldr r1, [r4, #0x14]
 *   @0x153de8 bl 0xb66e8 <lrint@plt>
 *   @0x153dec cmp r0, #4
 *   @0x153df0 addls pc, pc, r0, lsl #2
 *   @0x153df4 b 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x153df8 b 0x1542ac <_Z19YYIAPEventsDispatchv+0x6c4>
 *   @0x153dfc b 0x15455c <_Z19YYIAPEventsDispatchv+0x974>
 *   @0x153e00 b 0x15432c <_Z19YYIAPEventsDispatchv+0x744>
 *   @0x153e04 b 0x15419c <_Z19YYIAPEventsDispatchv+0x5b4>
 *   @0x153e08 b 0x153ec0 <_Z19YYIAPEventsDispatchv+0x2d8>
 *   @0x153e0c ldr r3, [pc, #0x25c]
 *   @0x153e10 ldr r0, [pc, r3]
 *   @0x153e14 bl 0x27e09c <_ZN5Mutex6UnlockEv>
 *   @0x153e18 sub r0, r11, #140
 *   @0x153e1c bl 0xfec6c <_ZN12DS_AutoMutexD2Ev>
 *   @0x153e20 ldr r12, [r11, #-0xdc]
 *   @0x153e24 ldr r2, [r11, #-0x38]
 *   @0x153e28 ldr r3, [r12]
 *   @0x153e2c cmp r2, r3
 *   @0x153e30 bne 0x154a6c <_Z19YYIAPEventsDispatchv+0xe84>
 *   @0x153e34 sub sp, r11, #48
 *   @0x153e38 vpop {d8, d9}
 *   @0x153e3c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x153e40 ldr r3, [r11, #-0xc0]
 *   @0x153e44 ldr r12, [r11, #-0xb0]
 *   @0x153e48 ldr r9, [r11, #-0xd4]
 *   @0x153e4c cmp r12, #0
 *   @0x153e50 moveq r3, #0
 *   @0x153e54 andne r3, r3, #1
 *   @0x153e58 cmp r3, #0
 *   @0x153e5c bne 0x15479c <_Z19YYIAPEventsDispatchv+0xbb4>
 *   @0x153e60 ldr r3, [r11, #-0xb0]
 *   @0x153e64 mov r2, #0
 *   @0x153e68 ldr r1, [pc, #0x204]
 *   @0x153e6c mov r0, r9
 *   @0x153e70 str r3, [sp]
 *   @0x153e74 add r1, pc, r1
 *   @0x153e78 mov r3, #0
 *   @0x153e7c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x153e80 vmov.f64 d7, #1.000000e+00
 *   @0x153e84 ldr r12, [r11, #-0xc0]
 *   @0x153e88 cmp r12, #0
 *   @0x153e8c vmovne r2, r3, d7
 *   @0x153e90 vmoveq r2, r3, d8
 *   @0x153e94 mov r1, #0
 *   @0x153e98 str r1, [sp]
 *   @0x153e9c ldr r1, [pc, #0x1d4]
 *   @0x153ea0 mov r0, r9
 *   @0x153ea4 add r1, pc, r1
 *   @0x153ea8 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x153eac mov r0, r9
 *   @0x153eb0 ldr r1, [r11, #-0x90]
 *   @0x153eb4 bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue>
 *   @0x153eb8 vmov r0, s18
 *   @0x153ebc bl 0x27e7c8 <json_object_put>
 *   @0x153ec0 ldr r3, [pc, #0x1e8]
 *   @0x153ec4 ldr r12, [r11, #-0x94]
 *   @0x153ec8 mov r2, #1
 *   @0x153ecc ldr r3, [r12, r3]
 *   @0x153ed0 str r2, [r3]
 *   @0x153ed4 ldr r12, [r11, #-0xcc]
 *   @0x153ed8 ldr r0, [r12, #0x4]
 *   @0x153edc bl 0x2055c8 <_Z11DsQueueSizei>
 *   @0x153ee0 cmp r0, #0
 *   @0x153ee4 beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x153ee8 ldr r12, [r11, #-0xcc]
 *   @0x153eec sub r5, r11, #52
 *   @0x153ef0 mov r3, #0
 *   @0x153ef4 str r3, [r11, #-0x4c]
 *   @0x153ef8 str r3, [r5, #-0x24]!
 *   @0x153efc mov r1, r5
 *   @0x153f00 ldr r0, [r12, #0x4]
 *   @0x153f04 bl 0x20557c <_Z14DsQueueDequeueiR6RValue>
 *   @0x153f08 ldr r4, [r11, #-0x58]
 *   @0x153f0c mov r0, r5
 *   @0x153f10 ldr r1, [r11, #-0xe4]
 *   @0x153f14 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x153f18 mov r1, r5
 *   @0x153f1c mov r0, r4
 *   @0x153f20 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x153f24 ldr r3, [r11, #-0x4c]
 *   @0x153f28 sub r3, r3, #1
 *   @0x153f2c bic r3, r3, #-16777216
 *   @0x153f30 bic r3, r3, #3
 *   @0x153f34 cmp r3, #0
 *   @0x153f38 mov r6, r0
 *   @0x153f3c bne 0x153f48 <_Z19YYIAPEventsDispatchv+0x360>
 *   @0x153f40 mov r0, r5
 *   @0x153f44 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x153f48 ldr r12, [r11, #-0x94]
 *   @0x153f4c mov r3, #0
 *   @0x153f50 ldr r1, [pc, #0x15c]
 *   @0x153f54 mov r2, #5
 *   @0x153f58 str r3, [r11, #-0x58]
 *   @0x153f5c str r3, [r11, #-0x50]
 *   @0x153f60 str r2, [r11, #-0x4c]
 *   @0x153f64 ldr r1, [r12, r1]
 *   @0x153f68 ldr r2, [r6, #0x10]
 *   @0x153f6c ldr r3, [r6, #0x14]
 *   @0x153f70 ldr r5, [r1]
 *   @0x153f74 mov r0, r2
 *   @0x153f78 mov r1, r3
 *   @0x153f7c ldr r12, [r5]
 *   @0x153f80 ldr r6, [r12, #0xc]
 *   @0x153f84 bl 0xb66e8 <lrint@plt>
 *   @0x153f88 ldr r1, [r11, #-0xd0]
 *   @0x153f8c mov r2, r0
 *   @0x153f90 mov r0, r5
 *   @0x153f94 blx r6
 *   @0x153f98 mov r0, r4
 *   @0x153f9c bl 0x153710 <_Z16InitIAPFunctionsv+0x23c>
 *   @0x153fa0 ldr lr, [r11, #-0xa8]
 *   @0x153fa4 movw r12, #0x1d08
 *   @0x153fa8 ldr r0, [r11, #-0x98]
 *   @0x153fac ldr r1, [r10, r12]
 *   @0x153fb0 ldrd r4, r5, [lr]
 *   @0x153fb4 ldr lr, [r11, #-0xb4]
 *   @0x153fb8 adds r2, r4, #1
 *   @0x153fbc adc r3, r5, #0
 *   @0x153fc0 cmp r1, #0
 *   @0x153fc4 str r0, [lr]
 *   @0x153fc8 ldr r0, [r11, #-0xa8]
 *   @0x153fcc strd r2, r3, [r0]
 *   @0x153fd0 ble 0x154174 <_Z19YYIAPEventsDispatchv+0x58c>
 *   @0x153fd4 mov r8, r12
 *   @0x153fd8 ldr r3, [pc, #0x9c]
 *   @0x153fdc ldr r12, [r11, #-0x94]
 *   @0x153fe0 mov r7, #0
 *   @0x153fe4 ldr r2, [pc, #0x94]
 *   @0x153fe8 ldr r3, [r12, r3]
 *   @0x153fec ldr r9, [r12, r2]
 *   @0x153ff0 str r3, [r11, #-0x90]
 *   @0x153ff4 mov r3, r10
 *   @0x153ff8 mov r10, r9
 *   @0x153ffc mov r9, r3
 *   @0x154000 ldr r12, [r11, #-0x90]
 *   @0x154004 movw lr, #0x3a14
 *   @0x154008 ldr r3, [r10]
 *   @0x15400c ldr r1, [r12, lr]
 *   @0x154010 ldr r2, [r3, #0x4]
 *   @0x154014 ldr r3, [r3]
 *   @0x154018 ldr r1, [r1, r7, lsl #2]
 *   @0x15401c and r2, r1, r2
 *   @0x154020 ldr r3, [r3, r2, lsl #3]
 *   @0x154024 cmp r3, #0
 *   @0x154028 bne 0x1540e8 <_Z19YYIAPEventsDispatchv+0x500>
 *   @0x15402c b 0x154160 <_Z19YYIAPEventsDispatchv+0x578>
 *   @0x154038 eoreq lr, r9, r0, asr r0
 *   @0x15403c .word 0xffffbd00
 *   @0x154040 eoreq lr, r9, r12, lsr #14
 *   @0x154044 eorseq r0, r3, r8, lsl #28
 *   @0x154048 eorseq r0, r3, r8, ror sp
 *   @0x15404c .word 0xffffbcec
 *   @0x154050 .word 0xffffdeb0
 *   @0x154054 .word 0xffffdeb4
 *   @0x154058 .word 0xffffdeb8
 *   @0x15405c andseq r2, pc, r0, lsl #8
 *   @0x154060 eoreq lr, r9, r0, lsl r6
 *   @0x154064 andseq r2, pc, r4, ror #7
 *   @0x154068 andseq r2, pc, r8, lsl r5
 *   @0x15406c andseq r2, pc, r4, lsr #9
 *   @0x154070 eorseq r0, r3, r0, lsr r12
 *   @0x154074 ldrheq r2, [pc], -r12
 *   @0x154078 andseq r2, pc, r0, lsl #7
 *   @0x15407c .word 0xffffdebc
 *   @0x154080 .word 0xffffbfec
 *   @0x154084 andseq r2, pc, r8
 *   @0x154088 andseq r2, pc, r12
 *   @0x15408c ldrsheq r1, [pc], -r0
 *   @0x154090 ldrsheq r0, [lr], -r0
 *   @0x154094 mulseq sp, r12, r7
 *   @0x154098 andseq r1, pc, r8, asr #29
 *   @0x15409c andseq r1, pc, r4, lsl #27
 *   @0x1540a0 andseq r1, pc, r8, ror #26
 *   @0x1540a4 mulseq pc, r8, r12
 *   @0x1540a8 andseq r1, pc, r12, lsr #21
 *   @0x1540ac andseq r1, pc, r4, ror #22
 *   @0x1540b0 .word 0xffffde74
 *   @0x1540b4 .word 0xffffbcf0
 *   @0x1540b8 andseq r1, pc, r12, lsl #21
 *   @0x1540bc .word 0xffffde7c
 *   @0x1540c0 .word 0xffffde78
 *   @0x1540c4 andseq r1, pc, r8, lsl #21
 *   @0x1540c8 ldrsheq r1, [pc], -r8
 *   @0x1540cc andseq r1, pc, r4, lsr #15
 *   @0x1540d0 .word 0xffffde80
 *   @0x1540d4 .word 0xffffde84
 *   @0x1540d8 ldrheq r1, [pc], -r0
 *   @0x1540dc ldr r3, [r3, #0x4]
 *   @0x1540e0 cmp r3, #0
 *   @0x1540e4 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578>
 *   @0x1540e8 ldr r2, [r3, #0x8]
 *   @0x1540ec cmp r1, r2
 *   @0x1540f0 bne 0x1540dc <_Z19YYIAPEventsDispatchv+0x4f4>
 *   @0x1540f4 ldr r3, [r3, #0xc]
 *   @0x1540f8 cmp r3, #0
 *   @0x1540fc ldrne r6, [r3, #0xc4]
 *   @0x154100 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578>
 *   @0x154104 cmp r6, #0
 *   @0x154108 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578>
 *   @0x15410c ldr r3, [r6, #0x8]
 *   @0x154110 cmp r3, #0
 *   @0x154114 beq 0x154160 <_Z19YYIAPEventsDispatchv+0x578>
 *   @0x154118 ldr r0, [r6, #0x8]
 *   @0x15411c ldr r6, [r6]
 *   @0x154120 ldrb r3, [r0, #0x68]
 *   @0x154124 cmp r3, #0
 *   @0x154128 bne 0x154104 <_Z19YYIAPEventsDispatchv+0x51c>
 *   @0x15412c ldrb r3, [r0, #0x69]
 *   @0x154130 cmp r3, #0
 *   @0x154134 bne 0x154104 <_Z19YYIAPEventsDispatchv+0x51c>
 *   @0x154138 ldrd r2, r3, [r0, #112]
 *   @0x15413c cmp r4, r2
 *   @0x154140 sbcs lr, r5, r3
 *   @0x154144 blt 0x154104 <_Z19YYIAPEventsDispatchv+0x51c>
 *   @0x154148 mov r2, #7
 *   @0x15414c mov r1, r0
 *   @0x154150 mov r3, #66
 *   @0x154154 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii>
 *   @0x154158 cmp r6, #0
 *   @0x15415c bne 0x15410c <_Z19YYIAPEventsDispatchv+0x524>
 *   @0x154160 ldr r3, [r9, r8]
 *   @0x154164 add r7, r7, #1
 *   @0x154168 cmp r3, r7
 *   @0x15416c bgt 0x154000 <_Z19YYIAPEventsDispatchv+0x418>
 *   @0x154170 mov r10, r9
 *   @0x154174 ldr r12, [r11, #-0x9c]
 *   @0x154178 ldr r0, [r11, #-0x98]
 *   @0x15417c add r12, r12, #1
 *   @0x154180 str r12, [r11, #-0x9c]
 *   @0x154184 bl 0x205334 <_Z12DestroyDsMapi>
 *   @0x154188 ldr r12, [r11, #-0x9c]
 *   @0x15418c ldr lr, [r11, #-0xac]
 *   @0x154190 cmp r12, lr
 *   @0x154194 bne 0x153d64 <_Z19YYIAPEventsDispatchv+0x17c>
 *   @0x154198 b 0x153e18 <_Z19YYIAPEventsDispatchv+0x230>
 *   @0x15419c sub r12, r11, #88
 *   @0x1541a0 ldr r1, [r11, #-0xe8]
 *   @0x1541a4 str r12, [r11, #-0x90]
 *   @0x1541a8 mov r0, r12
 *   @0x1541ac bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1541b0 mov r0, r9
 *   @0x1541b4 ldr r1, [r11, #-0x90]
 *   @0x1541b8 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x1541bc ldr r3, [r11, #-0x4c]
 *   @0x1541c0 sub r3, r3, #1
 *   @0x1541c4 bic r3, r3, #-16777216
 *   @0x1541c8 bic r3, r3, #3
 *   @0x1541cc cmp r3, #0
 *   @0x1541d0 mov r4, r0
 *   @0x1541d4 beq 0x154790 <_Z19YYIAPEventsDispatchv+0xba8>
 *   @0x1541d8 mov r5, #0
 *   @0x1541dc mov r3, #5
 *   @0x1541e0 str r5, [r11, #-0x50]
 *   @0x1541e4 str r5, [r11, #-0x58]
 *   @0x1541e8 str r3, [r11, #-0x4c]
 *   @0x1541ec ldr r2, [r4, #0x10]
 *   @0x1541f0 ldr r3, [r4, #0x14]
 *   @0x1541f4 vmov d7, r2, r3
 *   @0x1541f8 vcvt.s32.f64 s18, d7
 *   @0x1541fc vmov r0, s18
 *   @0x154200 bl 0x27e8f4 <json_object_get_object>
 *   @0x154204 ldr r4, [r0, #0x20]
 *   @0x154208 cmp r4, r5
 *   @0x15420c beq 0x154978 <_Z19YYIAPEventsDispatchv+0xd90>
 *   @0x154210 ldr r3, [pc, #-0x194]
 *   @0x154214 ldr r7, [pc, #-0x194]
 *   @0x154218 ldr r8, [pc, #-0x194]
 *   @0x15421c add r3, pc, r3
 *   @0x154220 ldr r2, [pc, #-0x198]
 *   @0x154224 add r7, pc, r7
 *   @0x154228 str r9, [r11, #-0xd4]
 *   @0x15422c add r8, pc, r8
 *   @0x154230 add r2, pc, r2
 *   @0x154234 str r5, [r11, #-0xc4]
 *   @0x154238 str r5, [r11, #-0xc0]
 *   @0x15423c mov r9, r3
 *   @0x154240 str r5, [r11, #-0xb0]
 *   @0x154244 str r2, [r11, #-0xc8]
 *   @0x154248 b 0x154280 <_Z19YYIAPEventsDispatchv+0x698>
 *   @0x15424c mov r0, r5
 *   @0x154250 mov r1, r8
 *   @0x154254 bl 0xb66d0 <strcasecmp@plt>
 *   @0x154258 cmp r0, #0
 *   @0x15425c beq 0x15475c <_Z19YYIAPEventsDispatchv+0xb74>
 *   @0x154260 mov r0, r5
 *   @0x154264 mov r1, r9
 *   @0x154268 bl 0xb66d0 <strcasecmp@plt>
 *   @0x15426c cmp r0, #0
 *   @0x154270 beq 0x15476c <_Z19YYIAPEventsDispatchv+0xb84>
 *   @0x154274 ldr r4, [r4, #0x8]
 *   @0x154278 cmp r4, #0
 *   @0x15427c beq 0x153e40 <_Z19YYIAPEventsDispatchv+0x258>
 *   @0x154280 ldr r5, [r4]
 *   @0x154284 mov r1, r7
 *   @0x154288 ldr r6, [r4, #0x4]
 *   @0x15428c mov r0, r5
 *   @0x154290 bl 0xb66d0 <strcasecmp@plt>
 *   @0x154294 cmp r0, #0
 *   @0x154298 bne 0x15424c <_Z19YYIAPEventsDispatchv+0x664>
 *   @0x15429c mov r0, r6
 *   @0x1542a0 bl 0x27ed58 <json_object_get_string>
 *   @0x1542a4 str r0, [r11, #-0xb0]
 *   @0x1542a8 b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c>
 *   @0x1542ac ldr r1, [pc, #-0x220]
 *   @0x1542b0 sub r0, r11, #136
 *   @0x1542b4 add r1, pc, r1
 *   @0x1542b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x1542bc mov r0, r9
 *   @0x1542c0 sub r1, r11, #136
 *   @0x1542c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x1542c8 ldr r3, [r11, #-0x7c]
 *   @0x1542cc sub r3, r3, #1
 *   @0x1542d0 bic r3, r3, #-16777216
 *   @0x1542d4 bic r3, r3, #3
 *   @0x1542d8 cmp r3, #0
 *   @0x1542dc mov r4, r0
 *   @0x1542e0 beq 0x154960 <_Z19YYIAPEventsDispatchv+0xd78>
 *   @0x1542e4 ldr r3, [r4, #0x14]
 *   @0x1542e8 mov r1, #0
 *   @0x1542ec ldr r2, [r4, #0x10]
 *   @0x1542f0 str r1, [r11, #-0x80]
 *   @0x1542f4 str r1, [r11, #-0x88]
 *   @0x1542f8 mov r1, #5
 *   @0x1542fc mov r0, r2
 *   @0x154300 str r1, [r11, #-0x7c]
 *   @0x154304 mov r1, r3
 *   @0x154308 bl 0xb66e8 <lrint@plt>
 *   @0x15430c ldr r3, [pc, #-0x264]
 *   @0x154310 cmp r0, #0
 *   @0x154314 beq 0x153ec4 <_Z19YYIAPEventsDispatchv+0x2dc>
 *   @0x154318 ldr r12, [r11, #-0x94]
 *   @0x15431c mvn r2, #0
 *   @0x154320 ldr r3, [r12, r3]
 *   @0x154324 str r2, [r3]
 *   @0x154328 b 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x15432c sub r8, r11, #120
 *   @0x154330 ldr r1, [pc, #-0x2a0]
 *   @0x154334 mov r0, r8
 *   @0x154338 add r1, pc, r1
 *   @0x15433c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x154340 mov r0, r9
 *   @0x154344 mov r1, r8
 *   @0x154348 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x15434c ldr r3, [r11, #-0x6c]
 *   @0x154350 sub r3, r3, #1
 *   @0x154354 bic r3, r3, #-16777216
 *   @0x154358 bic r3, r3, #3
 *   @0x15435c cmp r3, #0
 *   @0x154360 mov r4, r0
 *   @0x154364 beq 0x15496c <_Z19YYIAPEventsDispatchv+0xd84>
 *   @0x154368 mov r12, #0
 *   @0x15436c mov r3, #5
 *   @0x154370 str r12, [r11, #-0x70]
 *   @0x154374 sub lr, r11, #88
 *   @0x154378 str r12, [r11, #-0x78]
 *   @0x15437c str r3, [r11, #-0x6c]
 *   @0x154380 ldr r2, [r4, #0x10]
 *   @0x154384 ldr r3, [r4, #0x14]
 *   @0x154388 str lr, [r11, #-0x90]
 *   @0x15438c mvn lr, #1
 *   @0x154390 ldr r0, [r11, #-0x90]
 *   @0x154394 vmov d7, r2, r3
 *   @0x154398 str r12, [r11, #-0x58]
 *   @0x15439c str r12, [r11, #-0x54]
 *   @0x1543a0 vcvt.s32.f64 s15, d7
 *   @0x1543a4 str r12, [r11, #-0x50]
 *   @0x1543a8 str r12, [r11, #-0x4c]
 *   @0x1543ac str r12, [r11, #-0x48]
 *   @0x1543b0 str r12, [r11, #-0x40]
 *   @0x1543b4 str r12, [r11, #-0x44]
 *   @0x1543b8 str lr, [r11, #-0x3c]
 *   @0x1543bc vmov r1, s15
 *   @0x1543c0 vmov r7, s15
 *   @0x1543c4 bl 0x18ab40 <_ZN12CIAPPurchase11SetFromJSONEP11json_object>
 *   @0x1543c8 mov r5, r0
 *   @0x1543cc ldr r0, [r11, #-0x54]
 *   @0x1543d0 cmp r0, #0
 *   @0x1543d4 beq 0x154470 <_Z19YYIAPEventsDispatchv+0x888>
 *   @0x1543d8 ldr r3, [pc, #-0x324]
 *   @0x1543dc cmp r5, #0
 *   @0x1543e0 ldr r12, [r11, #-0x94]
 *   @0x1543e4 ldr r6, [r12, r3]
 *   @0x1543e8 blt 0x15440c <_Z19YYIAPEventsDispatchv+0x824>
 *   @0x1543ec ldr r3, [r6, #0x4]
 *   @0x1543f0 ldr r4, [r3, r5, lsl #2]
 *   @0x1543f4 ldr r1, [r4, #0x4]
 *   @0x1543f8 cmp r1, #0
 *   @0x1543fc beq 0x15440c <_Z19YYIAPEventsDispatchv+0x824>
 *   @0x154400 bl 0xb66d0 <strcasecmp@plt>
 *   @0x154404 cmp r0, #0
 *   @0x154408 beq 0x154464 <_Z19YYIAPEventsDispatchv+0x87c>
 *   @0x15440c sub r4, r11, #104
 *   @0x154410 ldr r1, [r11, #-0x58]
 *   @0x154414 mov r0, r4
 *   @0x154418 bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x15441c mov r0, r4
 *   @0x154420 bl 0x1533a0 <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x16c>
 *   @0x154424 ldr r3, [r11, #-0x5c]
 *   @0x154428 sub r3, r3, #1
 *   @0x15442c bic r3, r3, #-16777216
 *   @0x154430 bic r3, r3, #3
 *   @0x154434 cmp r3, #0
 *   @0x154438 mov r5, r0
 *   @0x15443c beq 0x154a60 <_Z19YYIAPEventsDispatchv+0xe78>
 *   @0x154440 cmp r5, #0
 *   @0x154444 mov r3, #0
 *   @0x154448 mov r2, #5
 *   @0x15444c str r3, [r11, #-0x60]
 *   @0x154450 str r3, [r11, #-0x68]
 *   @0x154454 str r2, [r11, #-0x5c]
 *   @0x154458 blt 0x154a44 <_Z19YYIAPEventsDispatchv+0xe5c>
 *   @0x15445c ldr r3, [r6, #0x4]
 *   @0x154460 ldr r4, [r3, r5, lsl #2]
 *   @0x154464 mov r0, r4
 *   @0x154468 ldr r1, [r11, #-0x90]
 *   @0x15446c bl 0x18aa6c <_ZN12CIAPPurchase15SetFromPurchaseERKS_>
 *   @0x154470 vmov s15, r5
 *   @0x154474 ldr r1, [pc, #-0x3e0]
 *   @0x154478 mov r4, #0
 *   @0x15447c mov r0, r9
 *   @0x154480 vcvt.f64.s32 d7, s15
 *   @0x154484 add r1, pc, r1
 *   @0x154488 str r4, [sp]
 *   @0x15448c vmov r2, r3, d7
 *   @0x154490 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x154494 vldr s15, [r11, #-68]
 *   @0x154498 vcvt.f64.s32 d7, s15
 *   @0x15449c ldr r1, [pc, #-0x404]
 *   @0x1544a0 str r4, [sp]
 *   @0x1544a4 mov r0, r9
 *   @0x1544a8 add r1, pc, r1
 *   @0x1544ac vmov r2, r3, d7
 *   @0x1544b0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x1544b4 mov r0, r9
 *   @0x1544b8 mov r1, r8
 *   @0x1544bc bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue>
 *   @0x1544c0 mov r0, r7
 *   @0x1544c4 bl 0x27e7c8 <json_object_put>
 *   @0x1544c8 ldr r0, [r11, #-0x58]
 *   @0x1544cc cmp r0, r4
 *   @0x1544d0 beq 0x1544dc <_Z19YYIAPEventsDispatchv+0x8f4>
 *   @0x1544d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1544d8 str r4, [r11, #-0x58]
 *   @0x1544dc ldr r0, [r11, #-0x54]
 *   @0x1544e0 cmp r0, #0
 *   @0x1544e4 beq 0x1544f4 <_Z19YYIAPEventsDispatchv+0x90c>
 *   @0x1544e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1544ec mov r3, #0
 *   @0x1544f0 str r3, [r11, #-0x54]
 *   @0x1544f4 ldr r0, [r11, #-0x50]
 *   @0x1544f8 cmp r0, #0
 *   @0x1544fc beq 0x15450c <_Z19YYIAPEventsDispatchv+0x924>
 *   @0x154500 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154504 mov r3, #0
 *   @0x154508 str r3, [r11, #-0x50]
 *   @0x15450c ldr r0, [r11, #-0x4c]
 *   @0x154510 cmp r0, #0
 *   @0x154514 beq 0x154524 <_Z19YYIAPEventsDispatchv+0x93c>
 *   @0x154518 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x15451c mov r3, #0
 *   @0x154520 str r3, [r11, #-0x4c]
 *   @0x154524 ldr r0, [r11, #-0x48]
 *   @0x154528 cmp r0, #0
 *   @0x15452c beq 0x154534 <_Z19YYIAPEventsDispatchv+0x94c>
 *   @0x154530 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154534 ldr r3, [pc, #-0x48c]
 *   @0x154538 ldr r12, [r11, #-0x94]
 *   @0x15453c ldr r3, [r12, r3]
 *   @0x154540 ldr r2, [r3]
 *   @0x154544 cmp r2, #3
 *   @0x154548 cmpne r2, #0
 *   @0x15454c beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x154550 mov r2, #1
 *   @0x154554 str r2, [r3]
 *   @0x154558 b 0x153ed4 <_Z19YYIAPEventsDispatchv+0x2ec>
 *   @0x15455c sub r8, r11, #120
 *   @0x154560 ldr r1, [pc, #-0x4c4]
 *   @0x154564 mov r0, r8
 *   @0x154568 add r1, pc, r1
 *   @0x15456c bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x154570 mov r0, r9
 *   @0x154574 mov r1, r8
 *   @0x154578 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue>
 *   @0x15457c ldr r3, [r11, #-0x6c]
 *   @0x154580 sub r3, r3, #1
 *   @0x154584 bic r3, r3, #-16777216
 *   @0x154588 bic r3, r3, #3
 *   @0x15458c cmp r3, #0
 *   @0x154590 mov r4, r0
 *   @0x154594 beq 0x154954 <_Z19YYIAPEventsDispatchv+0xd6c>
 *   @0x154598 mov r12, #0
 *   @0x15459c mov r3, #5
 *   @0x1545a0 str r12, [r11, #-0x70]
 *   @0x1545a4 sub lr, r11, #88
 *   @0x1545a8 str r12, [r11, #-0x78]
 *   @0x1545ac str r3, [r11, #-0x6c]
 *   @0x1545b0 mov r0, lr
 *   @0x1545b4 ldr r2, [r4, #0x10]
 *   @0x1545b8 ldr r3, [r4, #0x14]
 *   @0x1545bc str lr, [r11, #-0x90]
 *   @0x1545c0 str r12, [r11, #-0x58]
 *   @0x1545c4 vmov d7, r2, r3
 *   @0x1545c8 str r12, [r11, #-0x54]
 *   @0x1545cc str r12, [r11, #-0x50]
 *   @0x1545d0 vcvt.s32.f64 s18, d7
 *   @0x1545d4 str r12, [r11, #-0x4c]
 *   @0x1545d8 str r12, [r11, #-0x48]
 *   @0x1545dc strb r12, [r11, #-0x44]
 *   @0x1545e0 vmov r1, s18
 *   @0x1545e4 bl 0x18b168 <_ZN11CIAPProduct11SetFromJSONEP11json_object>
 *   @0x1545e8 ldr r1, [r11, #-0x58]
 *   @0x1545ec cmp r1, #0
 *   @0x1545f0 beq 0x1549ac <_Z19YYIAPEventsDispatchv+0xdc4>
 *   @0x1545f4 sub r4, r11, #104
 *   @0x1545f8 mov r0, r4
 *   @0x1545fc bl 0xdc308 <_Z11YYSetStringP6RValuePKc>
 *   @0x154600 mov r0, r4
 *   @0x154604 bl 0x15327c <_Z22F_IAP_ProductPurchasedR6RValueP9CInstanceS2_iPS_+0x48>
 *   @0x154608 ldr r3, [r11, #-0x5c]
 *   @0x15460c sub r3, r3, #1
 *   @0x154610 bic r3, r3, #-16777216
 *   @0x154614 bic r3, r3, #3
 *   @0x154618 cmp r3, #0
 *   @0x15461c mov r7, r0
 *   @0x154620 beq 0x1549a0 <_Z19YYIAPEventsDispatchv+0xdb8>
 *   @0x154624 cmp r7, #0
 *   @0x154628 mov r4, #0
 *   @0x15462c mov r3, #5
 *   @0x154630 str r4, [r11, #-0x60]
 *   @0x154634 str r4, [r11, #-0x68]
 *   @0x154638 str r3, [r11, #-0x5c]
 *   @0x15463c blt 0x1549b8 <_Z19YYIAPEventsDispatchv+0xdd0>
 *   @0x154640 ldr r3, [pc, #-0x574]
 *   @0x154644 lsl r6, r7, #2
 *   @0x154648 ldr r12, [r11, #-0x94]
 *   @0x15464c ldr r5, [r12, r3]
 *   @0x154650 ldr r3, [r5, #0x4]
 *   @0x154654 ldr r1, [r11, #-0x90]
 *   @0x154658 ldr r0, [r3, r6]
 *   @0x15465c bl 0x18b04c <_ZN11CIAPProduct14SetFromProductERKS_>
 *   @0x154660 ldr r3, [r5, #0x4]
 *   @0x154664 mov r2, #1
 *   @0x154668 ldr r3, [r3, r6]
 *   @0x15466c strb r2, [r3, #0x14]
 *   @0x154670 ldr r3, [r11, #-0x58]
 *   @0x154674 ldr r1, [pc, #-0x5d4]
 *   @0x154678 mov r2, #0
 *   @0x15467c str r3, [sp]
 *   @0x154680 mov r0, r9
 *   @0x154684 add r1, pc, r1
 *   @0x154688 mov r3, #0
 *   @0x15468c bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x154690 vmov s15, r7
 *   @0x154694 ldr r1, [pc, #-0x5f0]
 *   @0x154698 mov r4, #0
 *   @0x15469c vcvt.f64.s32 d7, s15
 *   @0x1546a0 str r4, [sp]
 *   @0x1546a4 add r1, pc, r1
 *   @0x1546a8 mov r0, r9
 *   @0x1546ac vmov r2, r3, d7
 *   @0x1546b0 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x1546b4 mov r0, r9
 *   @0x1546b8 mov r1, r8
 *   @0x1546bc bl 0x20b6cc <_ZN7CDS_Map6DeleteEP6RValue>
 *   @0x1546c0 vmov r0, s18
 *   @0x1546c4 bl 0x27e7c8 <json_object_put>
 *   @0x1546c8 ldr r0, [r11, #-0x58]
 *   @0x1546cc cmp r0, r4
 *   @0x1546d0 beq 0x1546dc <_Z19YYIAPEventsDispatchv+0xaf4>
 *   @0x1546d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1546d8 str r4, [r11, #-0x58]
 *   @0x1546dc ldr r0, [r11, #-0x54]
 *   @0x1546e0 cmp r0, #0
 *   @0x1546e4 beq 0x1546f4 <_Z19YYIAPEventsDispatchv+0xb0c>
 *   @0x1546e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1546ec mov r3, #0
 *   @0x1546f0 str r3, [r11, #-0x54]
 *   @0x1546f4 ldr r0, [r11, #-0x50]
 *   @0x1546f8 cmp r0, #0
 *   @0x1546fc beq 0x15470c <_Z19YYIAPEventsDispatchv+0xb24>
 *   @0x154700 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154704 mov r3, #0
 *   @0x154708 str r3, [r11, #-0x50]
 *   @0x15470c ldr r0, [r11, #-0x4c]
 *   @0x154710 cmp r0, #0
 *   @0x154714 beq 0x154724 <_Z19YYIAPEventsDispatchv+0xb3c>
 *   @0x154718 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x15471c mov r3, #0
 *   @0x154720 str r3, [r11, #-0x4c]
 *   @0x154724 ldr r0, [r11, #-0x48]
 *   @0x154728 cmp r0, #0
 *   @0x15472c beq 0x154734 <_Z19YYIAPEventsDispatchv+0xb4c>
 *   @0x154730 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x154734 ldr r3, [pc, #-0x68c]
 *   @0x154738 ldr r12, [r11, #-0x94]
 *   @0x15473c ldr r3, [r12, r3]
 *   @0x154740 ldr r2, [r3]
 *   @0x154744 cmp r2, #0
 *   @0x154748 beq 0x153fa0 <_Z19YYIAPEventsDispatchv+0x3b8>
 *   @0x15474c b 0x154550 <_Z19YYIAPEventsDispatchv+0x968>
 *   @0x154750 sub r0, r11, #136
 *   @0x154754 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154758 b 0x153dc4 <_Z19YYIAPEventsDispatchv+0x1dc>
 *   @0x15475c mov r0, r6
 *   @0x154760 bl 0x27ed58 <json_object_get_string>
 *   @0x154764 str r0, [r11, #-0xc4]
 *   @0x154768 b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c>
 *   @0x15476c mov r0, r6
 *   @0x154770 bl 0x27ed58 <json_object_get_string>
 *   @0x154774 mov r1, r0
 *   @0x154778 ldr r0, [r11, #-0xc8]
 *   @0x15477c bl 0xb66d0 <strcasecmp@plt>
 *   @0x154780 rsbs r0, r0, #1
 *   @0x154784 movlo r0, #0
 *   @0x154788 str r0, [r11, #-0xc0]
 *   @0x15478c b 0x154274 <_Z19YYIAPEventsDispatchv+0x68c>
 *   @0x154790 ldr r0, [r11, #-0x90]
 *   @0x154794 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154798 b 0x1541d8 <_Z19YYIAPEventsDispatchv+0x5f0>
 *   @0x15479c ldr r12, [r11, #-0x94]
 *   @0x1547a0 ldr r3, [pc, #-0x6f4]
 *   @0x1547a4 ldr r1, [pc, #-0x6f4]
 *   @0x1547a8 ldr r2, [r11, #-0xb0]
 *   @0x1547ac ldr r3, [r12, r3]
 *   @0x1547b0 add r1, pc, r1
 *   @0x1547b4 ldr r3, [r3]
 *   @0x1547b8 str r3, [r11, #-0xc0]
 *   @0x1547bc ldr r3, [r3]
 *   @0x1547c0 ldr r0, [r11, #-0xc0]
 *   @0x1547c4 ldr r3, [r3, #0xc]
 *   @0x1547c8 blx r3
 *   @0x1547cc ldr r3, [pc, #-0x718]
 *   @0x1547d0 ldr r12, [r11, #-0x94]
 *   @0x1547d4 ldr r6, [r12, r3]
 *   @0x1547d8 ldr r3, [r6]
 *   @0x1547dc cmp r3, #0
 *   @0x1547e0 ble 0x154924 <_Z19YYIAPEventsDispatchv+0xd3c>
 *   @0x1547e4 ldr r3, [pc, #-0x72c]
 *   @0x1547e8 ldr r3, [r12, r3]
 *   @0x1547ec str r3, [r11, #-0xc8]
 *   @0x1547f0 ldr r3, [r3]
 *   @0x1547f4 cmp r3, #0
 *   @0x1547f8 ble 0x154924 <_Z19YYIAPEventsDispatchv+0xd3c>
 *   @0x1547fc ldr r3, [pc, #-0x740]
 *   @0x154800 mov r7, r4
 *   @0x154804 mov r8, r4
 *   @0x154808 add r3, pc, r3
 *   @0x15480c str r3, [r11, #-0xe0]
 *   @0x154810 ldr r3, [r6, #0x4]
 *   @0x154814 lsl r4, r7, #2
 *   @0x154818 ldr r3, [r3, r7, lsl #2]
 *   @0x15481c cmp r3, #0
 *   @0x154820 beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28>
 *   @0x154824 ldr r0, [r3, #0x4]
 *   @0x154828 cmp r0, #0
 *   @0x15482c beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28>
 *   @0x154830 ldr r5, [r3, #0xc]
 *   @0x154834 cmp r5, #0
 *   @0x154838 beq 0x154910 <_Z19YYIAPEventsDispatchv+0xd28>
 *   @0x15483c ldr r1, [r11, #-0xb0]
 *   @0x154840 bl 0xb6574 <strcmp@plt>
 *   @0x154844 cmp r0, #0
 *   @0x154848 bne 0x154910 <_Z19YYIAPEventsDispatchv+0xd28>
 *   @0x15484c mov r0, r5
 *   @0x154850 ldr r1, [r11, #-0xc4]
 *   @0x154854 bl 0xb6574 <strcmp@plt>
 *   @0x154858 cmp r0, #0
 *   @0x15485c str r0, [r11, #-0xd4]
 *   @0x154860 bne 0x154910 <_Z19YYIAPEventsDispatchv+0xd28>
 *   @0x154864 ldr r12, [r11, #-0xc0]
 *   @0x154868 mov r2, r7
 *   @0x15486c ldr r1, [r11, #-0xe0]
 *   @0x154870 ldr r3, [r12]
 *   @0x154874 mov r0, r12
 *   @0x154878 ldr r3, [r3, #0xc]
 *   @0x15487c blx r3
 *   @0x154880 ldr r3, [r6, #0x4]
 *   @0x154884 add r2, r3, r4
 *   @0x154888 ldr r5, [r3, r4]
 *   @0x15488c cmp r5, #0
 *   @0x154890 beq 0x15490c <_Z19YYIAPEventsDispatchv+0xd24>
 *   @0x154894 ldr r0, [r5]
 *   @0x154898 cmp r0, #0
 *   @0x15489c beq 0x1548ac <_Z19YYIAPEventsDispatchv+0xcc4>
 *   @0x1548a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1548a4 ldr r12, [r11, #-0xd4]
 *   @0x1548a8 str r12, [r5]
 *   @0x1548ac ldr r0, [r5, #0x4]
 *   @0x1548b0 cmp r0, #0
 *   @0x1548b4 beq 0x1548c0 <_Z19YYIAPEventsDispatchv+0xcd8>
 *   @0x1548b8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1548bc str r8, [r5, #0x4]
 *   @0x1548c0 ldr r0, [r5, #0x8]
 *   @0x1548c4 cmp r0, #0
 *   @0x1548c8 beq 0x1548d4 <_Z19YYIAPEventsDispatchv+0xcec>
 *   @0x1548cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1548d0 str r8, [r5, #0x8]
 *   @0x1548d4 ldr r0, [r5, #0xc]
 *   @0x1548d8 cmp r0, #0
 *   @0x1548dc beq 0x1548e8 <_Z19YYIAPEventsDispatchv+0xd00>
 *   @0x1548e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1548e4 str r8, [r5, #0xc]
 *   @0x1548e8 ldr r0, [r5, #0x10]
 *   @0x1548ec cmp r0, #0
 *   @0x1548f0 beq 0x1548fc <_Z19YYIAPEventsDispatchv+0xd14>
 *   @0x1548f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv>
 *   @0x1548f8 str r8, [r5, #0x10]
 *   @0x1548fc mov r0, r5
 *   @0x154900 bl 0x27d1d0 <_ZdlPv>
 *   @0x154904 ldr r2, [r6, #0x4]
 *   @0x154908 add r2, r2, r4
 *   @0x15490c str r8, [r2]
 *   @0x154910 ldr r12, [r11, #-0xc8]
 *   @0x154914 add r7, r7, #1
 *   @0x154918 ldr r3, [r12]
 *   @0x15491c cmp r7, r3
 *   @0x154920 blt 0x154810 <_Z19YYIAPEventsDispatchv+0xc28>
 *   @0x154924 ldr r3, [r11, #-0xb0]
 *   @0x154928 mov r2, #0
 *   @0x15492c ldr r1, [pc, #-0x86c]
 *   @0x154930 mov r0, r9
 *   @0x154934 str r3, [sp]
 *   @0x154938 add r1, pc, r1
 *   @0x15493c mov r3, #0
 *   @0x154940 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x154944 mov r3, #0
 *   @0x154948 mov r2, #0
 *   @0x15494c movt r3, #0x3ff0
 *   @0x154950 b 0x153e94 <_Z19YYIAPEventsDispatchv+0x2ac>
 *   @0x154954 mov r0, r8
 *   @0x154958 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x15495c b 0x154598 <_Z19YYIAPEventsDispatchv+0x9b0>
 *   @0x154960 sub r0, r11, #136
 *   @0x154964 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154968 b 0x1542e4 <_Z19YYIAPEventsDispatchv+0x6fc>
 *   @0x15496c mov r0, r8
 *   @0x154970 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154974 b 0x154368 <_Z19YYIAPEventsDispatchv+0x780>
 *   @0x154978 ldr r1, [pc, #-0x8b4]
 *   @0x15497c mov r2, #0
 *   @0x154980 mov r3, #0
 *   @0x154984 str r4, [sp]
 *   @0x154988 mov r0, r9
 *   @0x15498c add r1, pc, r1
 *   @0x154990 bl 0x20d760 <_ZN7CDS_Map3AddEPKcdS1_>
 *   @0x154994 mov r2, #0
 *   @0x154998 mov r3, #0
 *   @0x15499c b 0x153e94 <_Z19YYIAPEventsDispatchv+0x2ac>
 *   @0x1549a0 mov r0, r4
 *   @0x1549a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x1549a8 b 0x154624 <_Z19YYIAPEventsDispatchv+0xa3c>
 *   @0x1549ac mov r3, r1
 *   @0x1549b0 mvn r7, #0
 *   @0x1549b4 b 0x154674 <_Z19YYIAPEventsDispatchv+0xa8c>
 *   @0x1549b8 ldr r12, [r11, #-0x94]
 *   @0x1549bc ldr r3, [pc, #-0x8f4]
 *   @0x1549c0 ldr r2, [pc, #-0x8f4]
 *   @0x1549c4 ldr lr, [r11, #-0x94]
 *   @0x1549c8 ldr r3, [r12, r3]
 *   @0x1549cc ldr r7, [r3]
 *   @0x1549d0 add r12, r7, #1
 *   @0x1549d4 str r12, [r3]
 *   @0x1549d8 ldr r5, [lr, r2]
 *   @0x1549dc ldr r3, [r5]
 *   @0x1549e0 cmp r7, r3
 *   @0x1549e4 lsllt r6, r7, #2
 *   @0x1549e8 blt 0x154650 <_Z19YYIAPEventsDispatchv+0xa68>
 *   @0x1549ec lsl r6, r12, #2
 *   @0x1549f0 ldr r2, [pc, #-0x920]
 *   @0x1549f4 add r0, r5, #4
 *   @0x1549f8 movw r3, #0x219
 *   @0x1549fc add r2, pc, r2
 *   @0x154a00 mov r1, r6
 *   @0x154a04 str r12, [r11, #-0xec]
 *   @0x154a08 bl 0x27d068 <_ZN13MemoryManager9SetLengthEPPvjPKci>
 *   @0x154a0c ldr r12, [r11, #-0xec]
 *   @0x154a10 mov r0, #24
 *   @0x154a14 sub r6, r6, #4
 *   @0x154a18 str r12, [r5]
 *   @0x154a1c bl 0x27c524 <_Znwj>
 *   @0x154a20 ldr r2, [r5, #0x4]
 *   @0x154a24 str r4, [r0, #0x8]
 *   @0x154a28 str r4, [r0]
 *   @0x154a2c str r4, [r0, #0x4]
 *   @0x154a30 str r4, [r0, #0xc]
 *   @0x154a34 str r4, [r0, #0x10]
 *   @0x154a38 strb r4, [r0, #0x14]
 *   @0x154a3c str r0, [r2, r6]
 *   @0x154a40 b 0x154650 <_Z19YYIAPEventsDispatchv+0xa68>
 *   @0x154a44 ldr r0, [r11, #-0x54]
 *   @0x154a48 bl 0x15314c <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x158>
 *   @0x154a4c subs r5, r0, #0
 *   @0x154a50 bge 0x15445c <_Z19YYIAPEventsDispatchv+0x874>
 *   @0x154a54 bl 0x153020 <_Z16F_IAP_StoreStateR6RValueP9CInstanceS2_iPS_+0x2c>
 *   @0x154a58 mov r5, r0
 *   @0x154a5c b 0x15445c <_Z19YYIAPEventsDispatchv+0x874>
 *   @0x154a60 mov r0, r4
 *   @0x154a64 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue>
 *   @0x154a68 b 0x154440 <_Z19YYIAPEventsDispatchv+0x858>
 *   @0x154a6c bl 0xb65d4 <__stack_chk_fail@plt>
 *
 * ══ §6/7 spPathConstraint_computeWorldPositions  0x287ad4  size 3252  813 条（0x287ad4..0x288788）
 * @func 0x287ad4 0x28879c  size 3272  818 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: spPathAttachment_computeWorldVertices1×8 / 0xb66f4×8 / _free×5 / _malloc×5 / spPathConstraint_computeWorldPositions+0x9b8×2 / anon_28775c×2 / 0xb66ac×2 / anon_28775c+0xf8×2
 * 字段偏移 top8: 0x18×18 / 0x8×18 / 0x4×10 / 0x10×9 / 0x1c×9 / 0x34×9 / 0xc×8 / 0x2c×8
 * VFP 指令 322 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x287ad4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x287ad8 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x287adc sub sp, sp, #52
 *   @0x287ae0 add r4, r2, r2, lsl #1
 *   @0x287ae4 mov r6, r0
 *   @0x287ae8 str r2, [sp, #0xc]
 *   @0x287aec add r4, r4, #2
 *   @0x287af0 ldr r2, [r0, #0x28]
 *   @0x287af4 mov r9, r1
 *   @0x287af8 ldr r0, [r0, #0xc]
 *   @0x287afc vldr s16, [r6, #16]
 *   @0x287b00 cmp r2, r4
 *   @0x287b04 str r3, [sp, #0x28]
 *   @0x287b08 ldr r11, [r6, #0x24]
 *   @0x287b0c str r0, [sp, #0x10]
 *   @0x287b10 beq 0x2885c8 <spPathConstraint_computeWorldPositions+0xaf4>
 *   @0x287b14 ldr r0, [r6, #0x2c]
 *   @0x287b18 cmp r0, #0
 *   @0x287b1c beq 0x287b24 <spPathConstraint_computeWorldPositions+0x50>
 *   @0x287b20 bl 0x285c80 <_free>
 *   @0x287b24 ldr r1, [pc, #0x2b4]
 *   @0x287b28 lsl r0, r4, #2
 *   @0x287b2c mov r2, #219
 *   @0x287b30 add r1, pc, r1
 *   @0x287b34 bl 0x285c10 <_malloc>
 *   @0x287b38 str r4, [r6, #0x28]
 *   @0x287b3c str r0, [sp, #0x1c]
 *   @0x287b40 str r0, [r6, #0x2c]
 *   @0x287b44 ldr r2, [r9, #0x20]
 *   @0x287b48 movw r4, #0xaaab
 *   @0x287b4c movt r4, #0x2aaa
 *   @0x287b50 ldr r3, [r9, #0x30]
 *   @0x287b54 ldr r0, [r9, #0x2c]
 *   @0x287b58 str r2, [sp, #0x14]
 *   @0x287b5c cmp r3, #0
 *   @0x287b60 smull r2, r4, r4, r2
 *   @0x287b64 ldr r1, [sp, #0x14]
 *   @0x287b68 str r0, [sp, #0x24]
 *   @0x287b6c sub r4, r4, r1, asr #31
 *   @0x287b70 bne 0x287dfc <spPathConstraint_computeWorldPositions+0x328>
 *   @0x287b74 cmp r0, #0
 *   @0x287b78 ldr r2, [sp, #0x98]
 *   @0x287b7c ldr r10, [r9, #0x28]
 *   @0x287b80 moveq r3, #2
 *   @0x287b84 movne r3, #1
 *   @0x287b88 rsb r3, r3, r4
 *   @0x287b8c cmp r2, #0
 *   @0x287b90 str r3, [sp, #0x20]
 *   @0x287b94 add r3, r10, r3, lsl #2
 *   @0x287b98 vldr s18, [r3]
 *   @0x287b9c ldr r3, [sp, #0x9c]
 *   @0x287ba0 vmulne.f32 s16, s16, s18
 *   @0x287ba4 cmp r3, #0
 *   @0x287ba8 beq 0x287bd4 <spPathConstraint_computeWorldPositions+0x100>
 *   @0x287bac ldr r0, [sp, #0xc]
 *   @0x287bb0 cmp r0, #0
 *   @0x287bb4 ble 0x287bd4 <spPathConstraint_computeWorldPositions+0x100>
 *   @0x287bb8 add r2, r11, r0, lsl #2
 *   @0x287bbc mov r3, r11
 *   @0x287bc0 vldr s15, [r3]
 *   @0x287bc4 vmul.f32 s15, s15, s18
 *   @0x287bc8 vstmia r3!, {s15}
 *   @0x287bcc cmp r3, r2
 *   @0x287bd0 bne 0x287bc0 <spPathConstraint_computeWorldPositions+0xec>
 *   @0x287bd4 ldr r3, [r6, #0x30]
 *   @0x287bd8 cmp r3, #8
 *   @0x287bdc beq 0x2885d4 <spPathConstraint_computeWorldPositions+0xb00>
 *   @0x287be0 ldr r0, [r6, #0x34]
 *   @0x287be4 cmp r0, #0
 *   @0x287be8 beq 0x287bf0 <spPathConstraint_computeWorldPositions+0x11c>
 *   @0x287bec bl 0x285c80 <_free>
 *   @0x287bf0 ldr r1, [pc, #0x1ec]
 *   @0x287bf4 mov r0, #32
 *   @0x287bf8 mov r2, #237
 *   @0x287bfc add r1, pc, r1
 *   @0x287c00 bl 0x285c10 <_malloc>
 *   @0x287c04 mov r3, #8
 *   @0x287c08 str r3, [r6, #0x30]
 *   @0x287c0c mov r4, r0
 *   @0x287c10 str r0, [r6, #0x34]
 *   @0x287c14 ldr r1, [sp, #0xc]
 *   @0x287c18 cmp r1, #0
 *   @0x287c1c ble 0x28848c <spPathConstraint_computeWorldPositions+0x9b8>
 *   @0x287c20 ldr r2, [sp, #0x14]
 *   @0x287c24 mov r6, #0
 *   @0x287c28 mov r7, r11
 *   @0x287c2c mov r5, r6
 *   @0x287c30 sub r2, r2, #6
 *   @0x287c34 mvn r8, #0
 *   @0x287c38 str r2, [sp, #0x2c]
 *   @0x287c3c ldr r11, [sp, #0x24]
 *   @0x287c40 str r9, [sp, #0x18]
 *   @0x287c44 b 0x287d94 <spPathConstraint_computeWorldPositions+0x2c0>
 *   @0x287c48 vcmpe.f32 s16, #0
 *   @0x287c4c vmrs APSR_nzcv, fpscr
 *   @0x287c50 bmi 0x288588 <spPathConstraint_computeWorldPositions+0xab4>
 *   @0x287c54 vcmpe.f32 s18, s16
 *   @0x287c58 vmrs APSR_nzcv, fpscr
 *   @0x287c5c bmi 0x288518 <spPathConstraint_computeWorldPositions+0xa44>
 *   @0x287c60 vmov.f32 s0, s16
 *   @0x287c64 lsl r2, r6, #2
 *   @0x287c68 mov r3, r6
 *   @0x287c6c add r2, r10, r2
 *   @0x287c70 vldr s15, [r2]
 *   @0x287c74 vcmpe.f32 s0, s15
 *   @0x287c78 vmrs APSR_nzcv, fpscr
 *   @0x287c7c ble 0x288508 <spPathConstraint_computeWorldPositions+0xa34>
 *   @0x287c80 add r3, r6, #1
 *   @0x287c84 add r2, r10, r3, lsl #2
 *   @0x287c88 vldmia r2!, {s15}
 *   @0x287c8c vcmpe.f32 s0, s15
 *   @0x287c90 mov r6, r3
 *   @0x287c94 mov r1, r3
 *   @0x287c98 add r3, r3, #1
 *   @0x287c9c vmrs APSR_nzcv, fpscr
 *   @0x287ca0 bgt 0x287c88 <spPathConstraint_computeWorldPositions+0x1b4>
 *   @0x287ca4 add r1, r10, r1, lsl #2
 *   @0x287ca8 vldr s14, [r1, #-4]
 *   @0x287cac vsub.f32 s0, s0, s14
 *   @0x287cb0 vsub.f32 s15, s15, s14
 *   @0x287cb4 cmp r6, r8
 *   @0x287cb8 vdiv.f32 s19, s0, s15
 *   @0x287cbc beq 0x287d28 <spPathConstraint_computeWorldPositions+0x254>
 *   @0x287cc0 ldr r0, [sp, #0x20]
 *   @0x287cc4 subs r2, r6, r0
 *   @0x287cc8 rsbs r3, r2, #0
 *   @0x287ccc adcs r3, r3, r2
 *   @0x287cd0 cmp r11, #0
 *   @0x287cd4 moveq r3, #0
 *   @0x287cd8 cmp r3, #0
 *   @0x287cdc beq 0x28855c <spPathConstraint_computeWorldPositions+0xa88>
 *   @0x287ce0 ldr r3, [sp, #0x14]
 *   @0x287ce4 mov r1, #0
 *   @0x287ce8 ldr r0, [sp, #0x18]
 *   @0x287cec mov r8, r6
 *   @0x287cf0 sub r2, r3, #4
 *   @0x287cf4 str r1, [sp, #0x4]
 *   @0x287cf8 mov r3, #4
 *   @0x287cfc ldr r1, [sp, #0x10]
 *   @0x287d00 str r4, [sp]
 *   @0x287d04 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x287d08 mov r0, #4
 *   @0x287d0c str r4, [sp]
 *   @0x287d10 mov r2, #0
 *   @0x287d14 str r0, [sp, #0x4]
 *   @0x287d18 mov r3, #4
 *   @0x287d1c ldr r0, [sp, #0x18]
 *   @0x287d20 ldr r1, [sp, #0x10]
 *   @0x287d24 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x287d28 ldr r1, [sp, #0x28]
 *   @0x287d2c vldr s1, [r4]
 *   @0x287d30 vldr s2, [r4, #4]
 *   @0x287d34 vldr s3, [r4, #8]
 *   @0x287d38 cmp r1, #0
 *   @0x287d3c vldr s4, [r4, #12]
 *   @0x287d40 vldr s5, [r4, #16]
 *   @0x287d44 vldr s6, [r4, #20]
 *   @0x287d48 vldr s7, [r4, #24]
 *   @0x287d4c vldr s8, [r4, #28]
 *   @0x287d50 movne r2, #1
 *   @0x287d54 bne 0x287d74 <spPathConstraint_computeWorldPositions+0x2a0>
 *   @0x287d58 vcmp.f32 s17, #0
 *   @0x287d5c vmrs APSR_nzcv, fpscr
 *   @0x287d60 movne r2, #0
 *   @0x287d64 moveq r2, #1
 *   @0x287d68 cmp r5, #0
 *   @0x287d6c movle r2, #0
 *   @0x287d70 andgt r2, r2, #1
 *   @0x287d74 vmov.f32 s0, s19
 *   @0x287d78 mov r1, r9
 *   @0x287d7c ldr r0, [sp, #0x1c]
 *   @0x287d80 bl 0x28775c <spPathAttachment_computeWorldVertices1+0x1c>
 *   @0x287d84 ldr r2, [sp, #0xc]
 *   @0x287d88 add r5, r5, #1
 *   @0x287d8c cmp r5, r2
 *   @0x287d90 beq 0x28848c <spPathConstraint_computeWorldPositions+0x9b8>
 *   @0x287d94 cmp r11, #0
 *   @0x287d98 vldmia r7!, {s17}
 *   @0x287d9c add r9, r5, r5, lsl #1
 *   @0x287da0 vadd.f32 s16, s16, s17
 *   @0x287da4 beq 0x287c48 <spPathConstraint_computeWorldPositions+0x174>
 *   @0x287da8 vcvt.f64.f32 d6, s16
 *   @0x287dac vcvt.f64.f32 d7, s18
 *   @0x287db0 vmov r0, r1, d6
 *   @0x287db4 vmov r2, r3, d7
 *   @0x287db8 bl 0xb66ac <fmod@plt>
 *   @0x287dbc mov r3, #0
 *   @0x287dc0 mov r2, r3
 *   @0x287dc4 mov r6, r3
 *   @0x287dc8 vmov d6, r0, r1
 *   @0x287dcc vcvt.f32.f64 s0, d6
 *   @0x287dd0 vcmpe.f32 s0, #0
 *   @0x287dd4 vmrs APSR_nzcv, fpscr
 *   @0x287dd8 vaddmi.f32 s0, s0, s18
 *   @0x287ddc b 0x287c6c <spPathConstraint_computeWorldPositions+0x198>
 *   @0x287de0 andeq pc, r12, r8, asr #28
 *   @0x287de4 andeq pc, r12, r12, ror sp
 *   @0x287de8 andeq pc, r12, r0, asr #22
 *   @0x287dec muleq r12, r8, r10
 *   @0x287df0 andeq pc, r12, r12, lsr #9
 *   @0x287df4 stcllo p0, c0, [r0]
 *   @0x287df8 andeq r0, r0, r0
 *   @0x287dfc ldr r3, [sp, #0x24]
 *   @0x287e00 cmp r3, #0
 *   @0x287e04 ldr r3, [r6, #0x30]
 *   @0x287e08 beq 0x28849c <spPathConstraint_computeWorldPositions+0x9c8>
 *   @0x287e0c ldr r0, [sp, #0x14]
 *   @0x287e10 add r10, r0, #2
 *   @0x287e14 cmp r3, r10
 *   @0x287e18 beq 0x2885dc <spPathConstraint_computeWorldPositions+0xb08>
 *   @0x287e1c ldr r0, [r6, #0x34]
 *   @0x287e20 cmp r0, #0
 *   @0x287e24 beq 0x287e2c <spPathConstraint_computeWorldPositions+0x358>
 *   @0x287e28 bl 0x285c80 <_free>
 *   @0x287e2c ldr r1, [pc, #-0x4c]
 *   @0x287e30 lsl r0, r10, #2
 *   @0x287e34 movw r2, #0x129
 *   @0x287e38 add r1, pc, r1
 *   @0x287e3c bl 0x285c10 <_malloc>
 *   @0x287e40 str r10, [r6, #0x30]
 *   @0x287e44 str r0, [sp, #0x18]
 *   @0x287e48 str r0, [r6, #0x34]
 *   @0x287e4c ldr r2, [sp, #0x14]
 *   @0x287e50 mov r5, #0
 *   @0x287e54 ldr r3, [sp, #0x18]
 *   @0x287e58 mov r0, r9
 *   @0x287e5c sub r7, r2, #2
 *   @0x287e60 ldr r1, [sp, #0x10]
 *   @0x287e64 mov r2, #2
 *   @0x287e68 str r5, [sp, #0x4]
 *   @0x287e6c str r3, [sp]
 *   @0x287e70 mov r3, r7
 *   @0x287e74 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x287e78 ldr r0, [sp, #0x18]
 *   @0x287e7c mov r2, r5
 *   @0x287e80 ldr r1, [sp, #0x10]
 *   @0x287e84 mov r3, #2
 *   @0x287e88 str r7, [sp, #0x4]
 *   @0x287e8c str r0, [sp]
 *   @0x287e90 mov r0, r9
 *   @0x287e94 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x287e98 ldr r1, [sp, #0x18]
 *   @0x287e9c sub r3, r10, #-1073741822
 *   @0x287ea0 ldr r2, [r1]
 *   @0x287ea4 add r3, r1, r3, lsl #2
 *   @0x287ea8 str r2, [r3]
 *   @0x287eac ldr r2, [r1, #0x4]
 *   @0x287eb0 str r2, [r3, #0x4]
 *   @0x287eb4 ldr r3, [r6, #0x38]
 *   @0x287eb8 cmp r3, r4
 *   @0x287ebc ldreq r12, [r6, #0x3c]
 *   @0x287ec0 beq 0x287ef4 <spPathConstraint_computeWorldPositions+0x420>
 *   @0x287ec4 ldr r0, [r6, #0x3c]
 *   @0x287ec8 cmp r0, #0
 *   @0x287ecc beq 0x287ed4 <spPathConstraint_computeWorldPositions+0x400>
 *   @0x287ed0 bl 0x285c80 <_free>
 *   @0x287ed4 ldr r1, [pc, #-0xf0]
 *   @0x287ed8 lsl r0, r4, #2
 *   @0x287edc mov r2, #320
 *   @0x287ee0 add r1, pc, r1
 *   @0x287ee4 bl 0x285c10 <_malloc>
 *   @0x287ee8 str r4, [r6, #0x38]
 *   @0x287eec mov r12, r0
 *   @0x287ef0 str r0, [r6, #0x3c]
 *   @0x287ef4 cmp r4, #0
 *   @0x287ef8 ldr r1, [sp, #0x18]
 *   @0x287efc vldr s15, [r1]
 *   @0x287f00 vldr s13, [r1, #4]
 *   @0x287f04 ble 0x288698 <spPathConstraint_computeWorldPositions+0xbc4>
 *   @0x287f08 vmov.f32 s31, #1.875000e-01
 *   @0x287f0c add r5, r1, #28
 *   @0x287f10 mov r8, r12
 *   @0x287f14 mov r7, #0
 *   @0x287f18 vldr s27, [pc, #-296]
 *   @0x287f1c vldr s30, [pc, #-304]
 *   @0x287f20 vldr s18, [r5, #-16]
 *   @0x287f24 vldr s17, [r5, #-20]
 *   @0x287f28 vldr s26, [r5, #-8]
 *   @0x287f2c mov r2, #0
 *   @0x287f30 movt r2, #0x4040
 *   @0x287f34 vldr s25, [r5, #-12]
 *   @0x287f38 mov r1, #1061158912
 *   @0x287f3c vldr s22, [r5]
 *   @0x287f40 vmov s12, r2
 *   @0x287f44 vldr s21, [r5, #-4]
 *   @0x287f48 add r7, r7, #1
 *   @0x287f4c add r5, r5, #24
 *   @0x287f50 vadd.f32 s28, s18, s18
 *   @0x287f54 vsub.f32 s28, s13, s28
 *   @0x287f58 vadd.f32 s29, s17, s17
 *   @0x287f5c vsub.f32 s14, s18, s26
 *   @0x287f60 vmov.f32 s23, s13
 *   @0x287f64 vadd.f32 s28, s28, s26
 *   @0x287f68 vsub.f32 s29, s15, s29
 *   @0x287f6c vnmls.f32 s23, s14, s12
 *   @0x287f70 vsub.f32 s14, s17, s25
 *   @0x287f74 vmul.f32 s28, s28, s31
 *   @0x287f78 vmov.f32 s24, s15
 *   @0x287f7c vadd.f32 s29, s29, s25
 *   @0x287f80 vnmls.f32 s24, s14, s12
 *   @0x287f84 vmov s12, r1
 *   @0x287f88 movw r1, #0xaaab
 *   @0x287f8c movt r1, #0x3e2a
 *   @0x287f90 vsub.f32 s13, s18, s13
 *   @0x287f94 vmov.f32 s20, s28
 *   @0x287f98 vmul.f32 s29, s29, s31
 *   @0x287f9c vadd.f32 s23, s23, s22
 *   @0x287fa0 vmla.f32 s20, s13, s12
 *   @0x287fa4 vsub.f32 s15, s17, s15
 *   @0x287fa8 vmov.f32 s19, s29
 *   @0x287fac vmul.f32 s23, s23, s30
 *   @0x287fb0 vadd.f32 s24, s24, s21
 *   @0x287fb4 vmla.f32 s19, s15, s12
 *   @0x287fb8 vmov s12, r1
 *   @0x287fbc vmul.f32 s24, s24, s30
 *   @0x287fc0 vmla.f32 s20, s23, s12
 *   @0x287fc4 vmla.f32 s19, s24, s12
 *   @0x287fc8 vmul.f32 s14, s20, s20
 *   @0x287fcc vmla.f32 s14, s19, s19
 *   @0x287fd0 vcvt.f64.f32 d7, s14
 *   @0x287fd4 vsqrt.f64 d6, d7
 *   @0x287fd8 vadd.f32 s28, s28, s28
 *   @0x287fdc vadd.f32 s29, s29, s29
 *   @0x287fe0 vcmp.f64 d6, d6
 *   @0x287fe4 vadd.f32 s28, s28, s23
 *   @0x287fe8 vmrs APSR_nzcv, fpscr
 *   @0x287fec vadd.f32 s29, s29, s24
 *   @0x287ff0 bne 0x28876c <spPathConstraint_computeWorldPositions+0xc98>
 *   @0x287ff4 vadd.f32 s20, s20, s28
 *   @0x287ff8 vmul.f32 s10, s20, s20
 *   @0x287ffc vadd.f32 s19, s19, s29
 *   @0x288000 vmla.f32 s10, s19, s19
 *   @0x288004 vcvt.f64.f32 d5, s10
 *   @0x288008 vsqrt.f64 d7, d5
 *   @0x28800c vcvt.f32.f64 s12, d6
 *   @0x288010 vcmp.f64 d7, d7
 *   @0x288014 vadd.f32 s27, s12, s27
 *   @0x288018 vmrs APSR_nzcv, fpscr
 *   @0x28801c vadd.f32 s29, s29, s24
 *   @0x288020 vadd.f32 s28, s28, s23
 *   @0x288024 bne 0x288754 <spPathConstraint_computeWorldPositions+0xc80>
 *   @0x288028 vadd.f32 s20, s20, s28
 *   @0x28802c vmul.f32 s10, s20, s20
 *   @0x288030 vadd.f32 s19, s19, s29
 *   @0x288034 vmla.f32 s10, s19, s19
 *   @0x288038 vcvt.f64.f32 d5, s10
 *   @0x28803c vsqrt.f64 d6, d5
 *   @0x288040 vcvt.f32.f64 s14, d7
 *   @0x288044 vcmp.f64 d6, d6
 *   @0x288048 vadd.f32 s27, s14, s27
 *   @0x28804c vmrs APSR_nzcv, fpscr
 *   @0x288050 bne 0x28873c <spPathConstraint_computeWorldPositions+0xc68>
 *   @0x288054 vadd.f32 s28, s28, s23
 *   @0x288058 vadd.f32 s28, s28, s20
 *   @0x28805c vadd.f32 s29, s29, s24
 *   @0x288060 vmul.f32 s28, s28, s28
 *   @0x288064 vadd.f32 s19, s29, s19
 *   @0x288068 vmla.f32 s28, s19, s19
 *   @0x28806c vcvt.f64.f32 d14, s28
 *   @0x288070 vsqrt.f64 d7, d14
 *   @0x288074 vcvt.f32.f64 s12, d6
 *   @0x288078 vcmp.f64 d7, d7
 *   @0x28807c vadd.f32 s27, s12, s27
 *   @0x288080 vmrs APSR_nzcv, fpscr
 *   @0x288084 bne 0x288724 <spPathConstraint_computeWorldPositions+0xc50>
 *   @0x288088 cmp r7, r4
 *   @0x28808c vcvt.f32.f64 s14, d7
 *   @0x288090 vadd.f32 s27, s14, s27
 *   @0x288094 vmov.f32 s13, s22
 *   @0x288098 vstmia r8!, {s27}
 *   @0x28809c vmov.f32 s15, s21
 *   @0x2880a0 bne 0x287f20 <spPathConstraint_computeWorldPositions+0x44c>
 *   @0x2880a4 vstr s22, [sp, #16]
 *   @0x2880a8 vstr s21, [sp, #20]
 *   @0x2880ac ldr r0, [sp, #0x98]
 *   @0x2880b0 ldr r1, [sp, #0x9c]
 *   @0x2880b4 cmp r0, #0
 *   @0x2880b8 vmulne.f32 s16, s16, s27
 *   @0x2880bc cmp r1, #0
 *   @0x2880c0 beq 0x288684 <spPathConstraint_computeWorldPositions+0xbb0>
 *   @0x2880c4 ldr r2, [sp, #0xc]
 *   @0x2880c8 cmp r2, #0
 *   @0x2880cc ble 0x28848c <spPathConstraint_computeWorldPositions+0x9b8>
 *   @0x2880d0 add r2, r11, r2, lsl #2
 *   @0x2880d4 mov r3, r11
 *   @0x2880d8 vldr s15, [r3]
 *   @0x2880dc vmul.f32 s15, s15, s27
 *   @0x2880e0 vstmia r3!, {s15}
 *   @0x2880e4 cmp r3, r2
 *   @0x2880e8 bne 0x2880d8 <spPathConstraint_computeWorldPositions+0x604>
 *   @0x2880ec add r9, r6, #72
 *   @0x2880f0 mov r8, #0
 *   @0x2880f4 sub r10, r10, #4
 *   @0x2880f8 mov r7, r11
 *   @0x2880fc str r10, [sp, #0x2c]
 *   @0x288100 mov r5, r8
 *   @0x288104 mov r4, r8
 *   @0x288108 mvn r10, #0
 *   @0x28810c mov r11, r12
 *   @0x288110 vldr s23, [pc, #-800]
 *   @0x288114 ldr r0, [sp, #0x24]
 *   @0x288118 vldmia r7!, {s31}
 *   @0x28811c add r12, r4, r4, lsl #1
 *   @0x288120 vadd.f32 s16, s16, s31
 *   @0x288124 cmp r0, #0
 *   @0x288128 bne 0x288610 <spPathConstraint_computeWorldPositions+0xb3c>
 *   @0x28812c vcmpe.f32 s16, #0
 *   @0x288130 vmrs APSR_nzcv, fpscr
 *   @0x288134 bmi 0x28866c <spPathConstraint_computeWorldPositions+0xb98>
 *   @0x288138 vcmpe.f32 s16, s27
 *   @0x28813c vmrs APSR_nzcv, fpscr
 *   @0x288140 bgt 0x288650 <spPathConstraint_computeWorldPositions+0xb7c>
 *   @0x288144 vmov.f32 s14, s16
 *   @0x288148 lsl r3, r5, #2
 *   @0x28814c mov r1, r5
 *   @0x288150 add r3, r11, r3
 *   @0x288154 vldr s15, [r3]
 *   @0x288158 vcmpe.f32 s14, s15
 *   @0x28815c vmrs APSR_nzcv, fpscr
 *   @0x288160 ble 0x2885f4 <spPathConstraint_computeWorldPositions+0xb20>
 *   @0x288164 add r3, r5, #1
 *   @0x288168 add r2, r11, r3, lsl #2
 *   @0x28816c vldmia r2!, {s15}
 *   @0x288170 vcmpe.f32 s15, s14
 *   @0x288174 mov r5, r3
 *   @0x288178 mov r1, r3
 *   @0x28817c add r3, r3, #1
 *   @0x288180 vmrs APSR_nzcv, fpscr
 *   @0x288184 bmi 0x28816c <spPathConstraint_computeWorldPositions+0x698>
 *   @0x288188 add r1, r11, r1, lsl #2
 *   @0x28818c vldr s13, [r1, #-4]
 *   @0x288190 vsub.f32 s14, s14, s13
 *   @0x288194 vsub.f32 s15, s15, s13
 *   @0x288198 cmp r5, r10
 *   @0x28819c lsleq r3, r8, #2
 *   @0x2881a0 moveq r1, r8
 *   @0x2881a4 vdiv.f32 s15, s14, s15
 *   @0x2881a8 vstr s15, [sp, #32]
 *   @0x2881ac beq 0x2883b0 <spPathConstraint_computeWorldPositions+0x8dc>
 *   @0x2881b0 add r2, r5, r5, lsl #1
 *   @0x2881b4 ldr r0, [sp, #0x18]
 *   @0x2881b8 vmov.f32 s15, #3.000000e+00
 *   @0x2881bc add r3, r0, r2, lsl #3
 *   @0x2881c0 vldr s18, [r3, #12]
 *   @0x2881c4 vldr s22, [r3, #4]
 *   @0x2881c8 vldr s17, [r3, #8]
 *   @0x2881cc vldr s26, [r3, #20]
 *   @0x2881d0 movw r0, #0xc28f
 *   @0x2881d4 movt r0, #0x3cf5
 *   @0x2881d8 vldr s21, [r3]
 *   @0x2881dc vldr s12, [r3, #28]
 *   @0x2881e0 vstr s12, [sp, #16]
 *   @0x2881e4 vmov s12, r0
 *   @0x2881e8 vldr s25, [r3, #16]
 *   @0x2881ec vldr s13, [r3, #24]
 *   @0x2881f0 vstr s13, [sp, #20]
 *   @0x2881f4 movw r0, #0x999a
 *   @0x2881f8 movt r0, #0x3e99
 *   @0x2881fc mov r2, r3
 *   @0x288200 vadd.f32 s28, s18, s18
 *   @0x288204 vsub.f32 s28, s22, s28
 *   @0x288208 vsub.f32 s14, s18, s26
 *   @0x28820c vadd.f32 s24, s17, s17
 *   @0x288210 vadd.f32 s28, s28, s26
 *   @0x288214 vmov.f32 s30, s22
 *   @0x288218 vsub.f32 s24, s21, s24
 *   @0x28821c vnmls.f32 s30, s14, s15
 *   @0x288220 vmul.f32 s28, s28, s12
 *   @0x288224 vmov s12, r0
 *   @0x288228 movw r0, #0xc28f
 *   @0x28822c movt r0, #0x3cf5
 *   @0x288230 vsub.f32 s13, s17, s25
 *   @0x288234 vsub.f32 s14, s18, s22
 *   @0x288238 vmov.f32 s29, s21
 *   @0x28823c vadd.f32 s24, s24, s25
 *   @0x288240 vnmls.f32 s29, s13, s15
 *   @0x288244 vldr s13, [sp, #16]
 *   @0x288248 vmov.f32 s20, s28
 *   @0x28824c vmla.f32 s20, s14, s12
 *   @0x288250 vmov s12, r0
 *   @0x288254 movw r0, #0x9ba6
 *   @0x288258 movt r0, #0x3bc4
 *   @0x28825c vmul.f32 s24, s24, s12
 *   @0x288260 vmov s12, r0
 *   @0x288264 movw r0, #0x999a
 *   @0x288268 movt r0, #0x3e99
 *   @0x28826c vadd.f32 s30, s30, s13
 *   @0x288270 vldr s13, [sp, #20]
 *   @0x288274 vsub.f32 s15, s17, s21
 *   @0x288278 vmul.f32 s30, s30, s12
 *   @0x28827c vmov s12, r0
 *   @0x288280 movw r0, #0xaaab
 *   @0x288284 movt r0, #0x3e2a
 *   @0x288288 vmov.f32 s19, s24
 *   @0x28828c vadd.f32 s29, s29, s13
 *   @0x288290 vmla.f32 s19, s15, s12
 *   @0x288294 vmov s12, r0
 *   @0x288298 movw r0, #0x9ba6
 *   @0x28829c movt r0, #0x3bc4
 *   @0x2882a0 vmla.f32 s20, s30, s12
 *   @0x2882a4 vmov s12, r0
 *   @0x2882a8 movw r0, #0xaaab
 *   @0x2882ac movt r0, #0x3e2a
 *   @0x2882b0 vmul.f32 s29, s29, s12
 *   @0x2882b4 vmov s12, r0
 *   @0x2882b8 vmla.f32 s19, s29, s12
 *   @0x2882bc vmul.f32 s12, s20, s20
 *   @0x2882c0 vmla.f32 s12, s19, s19
 *   @0x2882c4 vcvt.f64.f32 d6, s12
 *   @0x2882c8 vsqrt.f64 d7, d6
 *   @0x2882cc vadd.f32 s28, s28, s28
 *   @0x2882d0 vadd.f32 s24, s24, s24
 *   @0x2882d4 vcmp.f64 d7, d7
 *   @0x2882d8 vadd.f32 s28, s28, s30
 *   @0x2882dc vmrs APSR_nzcv, fpscr
 *   @0x2882e0 vadd.f32 s24, s24, s29
 *   @0x2882e4 bne 0x2886dc <spPathConstraint_computeWorldPositions+0xc08>
 *   @0x2882e8 add r10, r9, #4
 *   @0x2882ec mov r8, #1
 *   @0x2882f0 vcvt.f32.f64 s23, d7
 *   @0x2882f4 vstr s23, [r6, #72]
 *   @0x2882f8 vadd.f32 s20, s20, s28
 *   @0x2882fc add r8, r8, #1
 *   @0x288300 vmul.f32 s12, s20, s20
 *   @0x288304 vadd.f32 s19, s19, s24
 *   @0x288308 vmla.f32 s12, s19, s19
 *   @0x28830c vcvt.f64.f32 d6, s12
 *   @0x288310 vsqrt.f64 d7, d6
 *   @0x288314 vcmp.f64 d7, d7
 *   @0x288318 vadd.f32 s24, s24, s29
 *   @0x28831c vmrs APSR_nzcv, fpscr
 *   @0x288320 vadd.f32 s28, s28, s30
 *   @0x288324 bne 0x2886c4 <spPathConstraint_computeWorldPositions+0xbf0>
 *   @0x288328 cmp r8, #8
 *   @0x28832c vcvt.f32.f64 s14, d7
 *   @0x288330 vadd.f32 s23, s23, s14
 *   @0x288334 vstmia r10!, {s23}
 *   @0x288338 bne 0x2882f8 <spPathConstraint_computeWorldPositions+0x824>
 *   @0x28833c vadd.f32 s20, s20, s28
 *   @0x288340 vmul.f32 s14, s20, s20
 *   @0x288344 vadd.f32 s19, s19, s24
 *   @0x288348 vmla.f32 s14, s19, s19
 *   @0x28834c vcvt.f64.f32 d7, s14
 *   @0x288350 vsqrt.f64 d6, d7
 *   @0x288354 vcmp.f64 d6, d6
 *   @0x288358 vmrs APSR_nzcv, fpscr
 *   @0x28835c bne 0x28870c <spPathConstraint_computeWorldPositions+0xc38>
 *   @0x288360 vadd.f32 s10, s30, s28
 *   @0x288364 vadd.f32 s10, s10, s20
 *   @0x288368 vadd.f32 s24, s29, s24
 *   @0x28836c vmul.f32 s10, s10, s10
 *   @0x288370 vadd.f32 s19, s24, s19
 *   @0x288374 vmla.f32 s10, s19, s19
 *   @0x288378 vcvt.f64.f32 d5, s10
 *   @0x28837c vsqrt.f64 d7, d5
 *   @0x288380 vcvt.f32.f64 s12, d6
 *   @0x288384 vadd.f32 s23, s23, s12
 *   @0x288388 vcmp.f64 d7, d7
 *   @0x28838c vstr s23, [r6, #104]
 *   @0x288390 vmrs APSR_nzcv, fpscr
 *   @0x288394 bne 0x2886f4 <spPathConstraint_computeWorldPositions+0xc20>
 *   @0x288398 vcvt.f32.f64 s14, d7
 *   @0x28839c mov r3, #0
 *   @0x2883a0 mov r1, r3
 *   @0x2883a4 mov r8, r3
 *   @0x2883a8 vadd.f32 s23, s14, s23
 *   @0x2883ac vstr s23, [r6, #108]
 *   @0x2883b0 vldr s13, [sp, #32]
 *   @0x2883b4 vmul.f32 s14, s13, s23
 *   @0x2883b8 add r3, r9, r3
 *   @0x2883bc vldr s15, [r3]
 *   @0x2883c0 vcmpe.f32 s14, s15
 *   @0x2883c4 vmrs APSR_nzcv, fpscr
 *   @0x2883c8 ble 0x288600 <spPathConstraint_computeWorldPositions+0xb2c>
 *   @0x2883cc add r3, r8, #1
 *   @0x2883d0 add r2, r9, r3, lsl #2
 *   @0x2883d4 vldmia r2!, {s15}
 *   @0x2883d8 vcmpe.f32 s14, s15
 *   @0x2883dc mov r8, r3
 *   @0x2883e0 mov r1, r3
 *   @0x2883e4 add r3, r3, #1
 *   @0x2883e8 vmrs APSR_nzcv, fpscr
 *   @0x2883ec bgt 0x2883d4 <spPathConstraint_computeWorldPositions+0x900>
 *   @0x2883f0 add r1, r9, r1, lsl #2
 *   @0x2883f4 vldr s13, [r1, #-4]
 *   @0x2883f8 vsub.f32 s14, s14, s13
 *   @0x2883fc vsub.f32 s15, s15, s13
 *   @0x288400 vdiv.f32 s15, s14, s15
 *   @0x288404 vmov s14, r8
 *   @0x288408 vcvt.f32.s32 s0, s14
 *   @0x28840c vadd.f32 s0, s0, s15
 *   @0x288410 ldr r0, [sp, #0x28]
 *   @0x288414 movw r1, #0xcccd
 *   @0x288418 movt r1, #0x3dcc
 *   @0x28841c cmp r0, #0
 *   @0x288420 vmov s12, r1
 *   @0x288424 movne r2, #1
 *   @0x288428 vmul.f32 s0, s0, s12
 *   @0x28842c bne 0x28844c <spPathConstraint_computeWorldPositions+0x978>
 *   @0x288430 vcmp.f32 s31, #0
 *   @0x288434 vmrs APSR_nzcv, fpscr
 *   @0x288438 movne r2, #0
 *   @0x28843c moveq r2, #1
 *   @0x288440 cmp r4, #0
 *   @0x288444 movle r2, #0
 *   @0x288448 andgt r2, r2, #1
 *   @0x28844c mov r1, r12
 *   @0x288450 vmov.f32 s1, s21
 *   @0x288454 ldr r0, [sp, #0x1c]
 *   @0x288458 vldr s7, [sp, #20]
 *   @0x28845c vldr s8, [sp, #16]
 *   @0x288460 mov r10, r5
 *   @0x288464 vmov.f32 s2, s22
 *   @0x288468 vmov.f32 s3, s17
 *   @0x28846c vmov.f32 s4, s18
 *   @0x288470 vmov.f32 s5, s25
 *   @0x288474 vmov.f32 s6, s26
 *   @0x288478 bl 0x28775c <spPathAttachment_computeWorldVertices1+0x1c>
 *   @0x28847c ldr r0, [sp, #0xc]
 *   @0x288480 add r4, r4, #1
 *   @0x288484 cmp r0, r4
 *   @0x288488 bgt 0x288114 <spPathConstraint_computeWorldPositions+0x640>
 *   @0x28848c ldr r0, [sp, #0x1c]
 *   @0x288490 add sp, sp, #52
 *   @0x288494 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x288498 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x28849c ldr r2, [sp, #0x14]
 *   @0x2884a0 sub r4, r4, #1
 *   @0x2884a4 sub r10, r2, #4
 *   @0x2884a8 cmp r3, r10
 *   @0x2884ac beq 0x2885e8 <spPathConstraint_computeWorldPositions+0xb14>
 *   @0x2884b0 ldr r0, [r6, #0x34]
 *   @0x2884b4 cmp r0, #0
 *   @0x2884b8 beq 0x2884c0 <spPathConstraint_computeWorldPositions+0x9ec>
 *   @0x2884bc bl 0x285c80 <_free>
 *   @0x2884c0 ldr r1, [pc, #-0x6d8]
 *   @0x2884c4 lsl r0, r10, #2
 *   @0x2884c8 movw r2, #0x136
 *   @0x2884cc add r1, pc, r1
 *   @0x2884d0 bl 0x285c10 <_malloc>
 *   @0x2884d4 str r10, [r6, #0x30]
 *   @0x2884d8 str r0, [sp, #0x18]
 *   @0x2884dc str r0, [r6, #0x34]
 *   @0x2884e0 ldr r0, [sp, #0x18]
 *   @0x2884e4 mov r3, #0
 *   @0x2884e8 ldr r1, [sp, #0x10]
 *   @0x2884ec mov r2, #2
 *   @0x2884f0 str r3, [sp, #0x4]
 *   @0x2884f4 mov r3, r10
 *   @0x2884f8 str r0, [sp]
 *   @0x2884fc mov r0, r9
 *   @0x288500 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x288504 b 0x287eb4 <spPathConstraint_computeWorldPositions+0x3e0>
 *   @0x288508 cmp r6, #0
 *   @0x28850c beq 0x287cb4 <spPathConstraint_computeWorldPositions+0x1e0>
 *   @0x288510 mov r1, r3
 *   @0x288514 b 0x287ca4 <spPathConstraint_computeWorldPositions+0x1d0>
 *   @0x288518 cmn r8, #3
 *   @0x28851c beq 0x28853c <spPathConstraint_computeWorldPositions+0xa68>
 *   @0x288520 str r4, [sp]
 *   @0x288524 mov r3, #4
 *   @0x288528 ldr r0, [sp, #0x18]
 *   @0x28852c str r11, [sp, #0x4]
 *   @0x288530 ldr r1, [sp, #0x10]
 *   @0x288534 ldr r2, [sp, #0x2c]
 *   @0x288538 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x28853c mov r3, r9
 *   @0x288540 vsub.f32 s0, s16, s18
 *   @0x288544 mov r0, r4
 *   @0x288548 mov r1, #0
 *   @0x28854c ldr r2, [sp, #0x1c]
 *   @0x288550 mvn r8, #2
 *   @0x288554 bl 0x287854 <spPathAttachment_computeWorldVertices1+0x114>
 *   @0x288558 b 0x287d84 <spPathConstraint_computeWorldPositions+0x2b0>
 *   @0x28855c add r2, r6, r6, lsl #1
 *   @0x288560 str r3, [sp, #0x4]
 *   @0x288564 str r4, [sp]
 *   @0x288568 mov r3, #8
 *   @0x28856c lsl r2, r2, #1
 *   @0x288570 ldr r0, [sp, #0x18]
 *   @0x288574 ldr r1, [sp, #0x10]
 *   @0x288578 add r2, r2, #2
 *   @0x28857c bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x288580 mov r8, r6
 *   @0x288584 b 0x287d28 <spPathConstraint_computeWorldPositions+0x254>
 *   @0x288588 cmn r8, #2
 *   @0x28858c beq 0x2885ac <spPathConstraint_computeWorldPositions+0xad8>
 *   @0x288590 str r4, [sp]
 *   @0x288594 mov r2, #2
 *   @0x288598 ldr r0, [sp, #0x18]
 *   @0x28859c mov r3, #4
 *   @0x2885a0 str r11, [sp, #0x4]
 *   @0x2885a4 ldr r1, [sp, #0x10]
 *   @0x2885a8 bl 0x287740 <spPathAttachment_computeWorldVertices1>
 *   @0x2885ac mov r2, r9
 *   @0x2885b0 vmov.f32 s0, s16
 *   @0x2885b4 mov r0, r4
 *   @0x2885b8 ldr r1, [sp, #0x1c]
 *   @0x2885bc bl 0x2878e4 <spPathAttachment_computeWorldVertices1+0x1a4>
 *   @0x2885c0 mvn r8, #1
 *   @0x2885c4 b 0x287d84 <spPathConstraint_computeWorldPositions+0x2b0>
 *   @0x2885c8 ldr r1, [r6, #0x2c]
 *   @0x2885cc str r1, [sp, #0x1c]
 *   @0x2885d0 b 0x287b44 <spPathConstraint_computeWorldPositions+0x70>
 *   @0x2885d4 ldr r4, [r6, #0x34]
 *   @0x2885d8 b 0x287c14 <spPathConstraint_computeWorldPositions+0x140>
 *   @0x2885dc ldr r1, [r6, #0x34]
 *   @0x2885e0 str r1, [sp, #0x18]
 *   @0x2885e4 b 0x287e4c <spPathConstraint_computeWorldPositions+0x378>
 *   @0x2885e8 ldr r3, [r6, #0x34]
 *   @0x2885ec str r3, [sp, #0x18]
 *   @0x2885f0 b 0x2884e0 <spPathConstraint_computeWorldPositions+0xa0c>
 *   @0x2885f4 cmp r5, #0
 *   @0x2885f8 beq 0x288198 <spPathConstraint_computeWorldPositions+0x6c4>
 *   @0x2885fc b 0x288188 <spPathConstraint_computeWorldPositions+0x6b4>
 *   @0x288600 cmp r8, #0
 *   @0x288604 bne 0x2883f0 <spPathConstraint_computeWorldPositions+0x91c>
 *   @0x288608 vdiv.f32 s0, s14, s15
 *   @0x28860c b 0x288410 <spPathConstraint_computeWorldPositions+0x93c>
 *   @0x288610 vcvt.f64.f32 d6, s16
 *   @0x288614 str r12, [sp, #0x8]
 *   @0x288618 vcvt.f64.f32 d7, s27
 *   @0x28861c vmov r0, r1, d6
 *   @0x288620 vmov r2, r3, d7
 *   @0x288624 bl 0xb66ac <fmod@plt>
 *   @0x288628 mov r3, #0
 *   @0x28862c ldr r12, [sp, #0x8]
 *   @0x288630 mov r5, r3
 *   @0x288634 vmov d6, r0, r1
 *   @0x288638 mov r1, r3
 *   @0x28863c vcvt.f32.f64 s14, d6
 *   @0x288640 vcmpe.f32 s14, #0
 *   @0x288644 vmrs APSR_nzcv, fpscr
 *   @0x288648 vaddmi.f32 s14, s14, s27
 *   @0x28864c b 0x288150 <spPathConstraint_computeWorldPositions+0x67c>
 *   @0x288650 mov r3, r12
 *   @0x288654 vsub.f32 s0, s16, s27
 *   @0x288658 ldr r0, [sp, #0x18]
 *   @0x28865c ldr r1, [sp, #0x2c]
 *   @0x288660 ldr r2, [sp, #0x1c]
 *   @0x288664 bl 0x287854 <spPathAttachment_computeWorldVertices1+0x114>
 *   @0x288668 b 0x28847c <spPathConstraint_computeWorldPositions+0x9a8>
 *   @0x28866c mov r2, r12
 *   @0x288670 vmov.f32 s0, s16
 *   @0x288674 ldr r0, [sp, #0x18]
 *   @0x288678 ldr r1, [sp, #0x1c]
 *   @0x28867c bl 0x2878e4 <spPathAttachment_computeWorldVertices1+0x1a4>
 *   @0x288680 b 0x28847c <spPathConstraint_computeWorldPositions+0x9a8>
 *   @0x288684 ldr r3, [sp, #0xc]
 *   @0x288688 add r9, r6, #72
 *   @0x28868c cmp r3, #0
 *   @0x288690 bgt 0x2880f0 <spPathConstraint_computeWorldPositions+0x61c>
 *   @0x288694 b 0x28848c <spPathConstraint_computeWorldPositions+0x9b8>
 *   @0x288698 vldr s12, [pc, #228]
 *   @0x28869c vmov.f32 s22, s13
 *   @0x2886a0 vstr s12, [sp, #16]
 *   @0x2886a4 vstr s12, [sp, #20]
 *   @0x2886a8 vmov.f32 s21, s15
 *   @0x2886ac vmov.f32 s26, s12
 *   @0x2886b0 vmov.f32 s25, s12
 *   @0x2886b4 vmov.f32 s18, s12
 *   @0x2886b8 vmov.f32 s17, s12
 *   @0x2886bc vmov.f32 s27, s12
 *   @0x2886c0 b 0x2880ac <spPathConstraint_computeWorldPositions+0x5d8>
 *   @0x2886c4 vmov r0, r1, d6
 *   @0x2886c8 str r12, [sp, #0x8]
 *   @0x2886cc bl 0xb66f4 <sqrt@plt>
 *   @0x2886d0 ldr r12, [sp, #0x8]
 *   @0x2886d4 vmov d7, r0, r1
 *   @0x2886d8 b 0x288328 <spPathConstraint_computeWorldPositions+0x854>
 *   @0x2886dc vmov r0, r1, d6
 *   @0x2886e0 str r12, [sp, #0x8]
 *   @0x2886e4 bl 0xb66f4 <sqrt@plt>
 *   @0x2886e8 ldr r12, [sp, #0x8]
 *   @0x2886ec vmov d7, r0, r1
 *   @0x2886f0 b 0x2882e8 <spPathConstraint_computeWorldPositions+0x814>
 *   @0x2886f4 vmov r0, r1, d5
 *   @0x2886f8 str r12, [sp, #0x8]
 *   @0x2886fc bl 0xb66f4 <sqrt@plt>
 *   @0x288700 ldr r12, [sp, #0x8]
 *   @0x288704 vmov d7, r0, r1
 *   @0x288708 b 0x288398 <spPathConstraint_computeWorldPositions+0x8c4>
 *   @0x28870c vmov r0, r1, d7
 *   @0x288710 str r12, [sp, #0x8]
 *   @0x288714 bl 0xb66f4 <sqrt@plt>
 *   @0x288718 ldr r12, [sp, #0x8]
 *   @0x28871c vmov d6, r0, r1
 *   @0x288720 b 0x288360 <spPathConstraint_computeWorldPositions+0x88c>
 *   @0x288724 vmov r0, r1, d14
 *   @0x288728 str r12, [sp, #0x8]
 *   @0x28872c bl 0xb66f4 <sqrt@plt>
 *   @0x288730 ldr r12, [sp, #0x8]
 *   @0x288734 vmov d7, r0, r1
 *   @0x288738 b 0x288088 <spPathConstraint_computeWorldPositions+0x5b4>
 *   @0x28873c vmov r0, r1, d5
 *   @0x288740 str r12, [sp, #0x8]
 *   @0x288744 bl 0xb66f4 <sqrt@plt>
 *   @0x288748 ldr r12, [sp, #0x8]
 *   @0x28874c vmov d6, r0, r1
 *   @0x288750 b 0x288054 <spPathConstraint_computeWorldPositions+0x580>
 *   @0x288754 vmov r0, r1, d5
 *   @0x288758 str r12, [sp, #0x8]
 *   @0x28875c bl 0xb66f4 <sqrt@plt>
 *   @0x288760 ldr r12, [sp, #0x8]
 *   @0x288764 vmov d7, r0, r1
 *   @0x288768 b 0x288028 <spPathConstraint_computeWorldPositions+0x554>
 *   @0x28876c vmov r0, r1, d7
 *   @0x288770 str r12, [sp, #0x8]
 *   @0x288774 bl 0xb66f4 <sqrt@plt>
 *   @0x288778 ldr r12, [sp, #0x8]
 *   @0x28877c vmov d6, r0, r1
 *   @0x288780 b 0x287ff4 <spPathConstraint_computeWorldPositions+0x520>
 *   @0x288784 andeq r0, r0, r0
 *
 * ══ §7/7 spPathConstraint_apply  0x288788  size 1876  469 条（0x288788..0x288edc）
 * @func 0x288788 0x288edc  size 1876  469 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb66f4×5 / _free×2 / _malloc×2 / 0xb6c70×2 / 0xb67e4×2 / 0xb67d8×2 / spPathConstraint_apply+0x140×2 / spPathConstraint_apply+0x138
 * 字段偏移 top8: 0x8×17 / 0xc×10 / 0x4×10 / 0x10×9 / 0x18×8 / 0x28×7 / 0x20×6 / 0x2c×6
 * VFP 指令 199 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x288788 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x28878c vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x288790 vldr s22, [r0, #28]
 *   @0x288794 vcmpe.f32 s22, #0
 *   @0x288798 ldr r5, [r0]
 *   @0x28879c vldr s25, [r0, #24]
 *   @0x2887a0 ldr r2, [r0, #0xc]
 *   @0x2887a4 sub sp, sp, #52
 *   @0x2887a8 ldr r8, [r0, #0x4]
 *   @0x2887ac mov r4, r0
 *   @0x2887b0 vmrs APSR_nzcv, fpscr
 *   @0x2887b4 vcmpe.f32 s25, #0
 *   @0x2887b8 ldr r9, [r5, #0x18]
 *   @0x2887bc movle r3, #0
 *   @0x2887c0 movgt r3, #1
 *   @0x2887c4 ldr r6, [r2, #0x18]
 *   @0x2887c8 ldr r2, [r0, #0x8]
 *   @0x2887cc vmrs APSR_nzcv, fpscr
 *   @0x2887d0 movle r10, #0
 *   @0x2887d4 movgt r10, #1
 *   @0x2887d8 rsbs r1, r9, #1
 *   @0x2887dc ldr r12, [r5, #0x14]
 *   @0x2887e0 str r2, [sp, #0x20]
 *   @0x2887e4 movlo r1, #0
 *   @0x2887e8 cmp r1, #0
 *   @0x2887ec addeq r7, r8, #1
 *   @0x2887f0 str r1, [sp, #0x14]
 *   @0x2887f4 movne r7, r8
 *   @0x2887f8 orrs r3, r10, r3
 *   @0x2887fc beq 0x288814 <spPathConstraint_apply+0x8c>
 *   @0x288800 cmp r6, #0
 *   @0x288804 beq 0x288814 <spPathConstraint_apply+0x8c>
 *   @0x288808 ldr r3, [r6, #0x4]
 *   @0x28880c cmp r3, #4
 *   @0x288810 beq 0x288820 <spPathConstraint_apply+0x98>
 *   @0x288814 add sp, sp, #52
 *   @0x288818 vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x28881c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x288820 ldr r3, [r0, #0x20]
 *   @0x288824 cmp r7, r3
 *   @0x288828 beq 0x288b38 <spPathConstraint_apply+0x3b0>
 *   @0x28882c ldr r0, [r0, #0x24]
 *   @0x288830 cmp r0, #0
 *   @0x288834 beq 0x288844 <spPathConstraint_apply+0xbc>
 *   @0x288838 str r12, [sp, #0x8]
 *   @0x28883c bl 0x285c80 <_free>
 *   @0x288840 ldr r12, [sp, #0x8]
 *   @0x288844 ldr r1, [pc, #0x41c]
 *   @0x288848 lsl r0, r7, #2
 *   @0x28884c mov r2, #100
 *   @0x288850 str r12, [sp, #0x8]
 *   @0x288854 add r1, pc, r1
 *   @0x288858 bl 0x285c10 <_malloc>
 *   @0x28885c ldr r12, [sp, #0x8]
 *   @0x288860 str r7, [r4, #0x20]
 *   @0x288864 str r0, [sp, #0x28]
 *   @0x288868 str r0, [r4, #0x24]
 *   @0x28886c subs lr, r9, #2
 *   @0x288870 vldr s17, [pc, #1004]
 *   @0x288874 rsbs r9, lr, #0
 *   @0x288878 ldr r2, [sp, #0x28]
 *   @0x28887c adcs r9, r9, lr
 *   @0x288880 str r9, [sp, #0x18]
 *   @0x288884 ldr r1, [sp, #0x18]
 *   @0x288888 rsbs r9, r12, #1
 *   @0x28888c vstr s17, [r2]
 *   @0x288890 vldr s16, [r4, #20]
 *   @0x288894 movlo r9, #0
 *   @0x288898 orrs r1, r1, r9
 *   @0x28889c bne 0x288bdc <spPathConstraint_apply+0x454>
 *   @0x2888a0 cmp r7, #1
 *   @0x2888a4 ble 0x2888c0 <spPathConstraint_apply+0x138>
 *   @0x2888a8 ldr r2, [sp, #0x28]
 *   @0x2888ac add r3, r2, #4
 *   @0x2888b0 add r2, r2, r7, lsl #2
 *   @0x2888b4 vstmia r3!, {s16}
 *   @0x2888b8 cmp r3, r2
 *   @0x2888bc bne 0x2888b4 <spPathConstraint_apply+0x12c>
 *   @0x2888c0 mov r3, #0
 *   @0x2888c4 str r3, [sp, #0x2c]
 *   @0x2888c8 ldr r3, [r5, #0x10]
 *   @0x2888cc subs r2, r12, #2
 *   @0x2888d0 rsbs r12, r2, #0
 *   @0x2888d4 mov r1, r6
 *   @0x2888d8 adcs r12, r12, r2
 *   @0x2888dc subs r0, r3, #1
 *   @0x2888e0 rsbs r3, r0, #0
 *   @0x2888e4 str r12, [sp, #0x4]
 *   @0x2888e8 adcs r3, r3, r0
 *   @0x2888ec mov r2, r7
 *   @0x2888f0 str r3, [sp]
 *   @0x2888f4 mov r0, r4
 *   @0x2888f8 ldr r3, [sp, #0x14]
 *   @0x2888fc bl 0x287ad4 <spPathConstraint_computeWorldPositions>
 *   @0x288900 ldr r3, [r4]
 *   @0x288904 vldr s10, [r3, #28]
 *   @0x288908 ldr r3, [r4, #0xc]
 *   @0x28890c vcmp.f32 s10, #0
 *   @0x288910 ldr r1, [sp, #0x18]
 *   @0x288914 vstr s10, [sp, #28]
 *   @0x288918 ldr r3, [r3, #0x4]
 *   @0x28891c vmrs APSR_nzcv, fpscr
 *   @0x288920 movne r1, #0
 *   @0x288924 andeq r1, r1, #1
 *   @0x288928 cmp r8, #0
 *   @0x28892c ldr r3, [r3, #0x4]
 *   @0x288930 str r1, [sp, #0x24]
 *   @0x288934 vldr s28, [r3, #88]
 *   @0x288938 vldr s29, [r3, #92]
 *   @0x28893c vldr s17, [r0]
 *   @0x288940 vldr s30, [r0, #4]
 *   @0x288944 ble 0x288814 <spPathConstraint_apply+0x8c>
 *   @0x288948 ldr r3, [sp, #0x28]
 *   @0x28894c mov r11, #0
 *   @0x288950 ldr r2, [sp, #0x20]
 *   @0x288954 add r5, r0, #20
 *   @0x288958 add r7, r3, #4
 *   @0x28895c mov r3, r11
 *   @0x288960 sub r9, r2, #4
 *   @0x288964 mov r11, r8
 *   @0x288968 ldr r6, [sp, #0x2c]
 *   @0x28896c mov r8, r3
 *   @0x288970 b 0x288aa4 <spPathConstraint_apply+0x31c>
 *   @0x288974 vldr s16, [r5, #-12]
 *   @0x288978 vcvt.f64.f32 d5, s24
 *   @0x28897c vcvt.f64.f32 d6, s23
 *   @0x288980 vmov r0, r1, d5
 *   @0x288984 vmov r2, r3, d6
 *   @0x288988 bl 0xb6c70 <atan2@plt>
 *   @0x28898c ldr r2, [sp, #0x24]
 *   @0x288990 cmp r2, #0
 *   @0x288994 vmov d5, r0, r1
 *   @0x288998 movw r1, #0xfa35
 *   @0x28899c movt r1, #0x3c8e
 *   @0x2889a0 vcvt.f32.f64 s15, d5
 *   @0x2889a4 vldr s10, [sp, #28]
 *   @0x2889a8 vmov s11, r1
 *   @0x2889ac vmls.f32 s15, s10, s11
 *   @0x2889b0 vsub.f32 s16, s16, s15
 *   @0x2889b4 beq 0x288a04 <spPathConstraint_apply+0x27c>
 *   @0x2889b8 vcvt.f64.f32 d9, s16
 *   @0x2889bc vmov r0, r1, d9
 *   @0x2889c0 bl 0xb67e4 <cos@plt>
 *   @0x2889c4 vmov d6, r0, r1
 *   @0x2889c8 vmov r0, r1, d9
 *   @0x2889cc vcvt.f32.f64 s31, d6
 *   @0x2889d0 bl 0xb67d8 <sin@plt>
 *   @0x2889d4 ldr r3, [r4]
 *   @0x2889d8 vldr s13, [r3, #12]
 *   @0x2889dc vmul.f32 s14, s31, s24
 *   @0x2889e0 vmov d5, r0, r1
 *   @0x2889e4 vcvt.f32.f64 s12, d5
 *   @0x2889e8 vmul.f32 s15, s12, s24
 *   @0x2889ec vmla.f32 s14, s12, s23
 *   @0x2889f0 vnmls.f32 s15, s31, s23
 *   @0x2889f4 vnmls.f32 s30, s14, s13
 *   @0x2889f8 vnmls.f32 s17, s15, s13
 *   @0x2889fc vmla.f32 s21, s30, s25
 *   @0x288a00 vmla.f32 s20, s17, s25
 *   @0x288a04 movw r1, #0xfdb
 *   @0x288a08 movt r1, #0x4049
 *   @0x288a0c vmov s10, r1
 *   @0x288a10 movw r1, #0xfdb
 *   @0x288a14 vcmpe.f32 s16, s10
 *   @0x288a18 vmrs APSR_nzcv, fpscr
 *   @0x288a1c ble 0x288b44 <spPathConstraint_apply+0x3bc>
 *   @0x288a20 movt r1, #0x40c9
 *   @0x288a24 vmov s10, r1
 *   @0x288a28 vsub.f32 s16, s16, s10
 *   @0x288a2c vmul.f32 s16, s16, s25
 *   @0x288a30 vcvt.f64.f32 d8, s16
 *   @0x288a34 vmov r0, r1, d8
 *   @0x288a38 bl 0xb67e4 <cos@plt>
 *   @0x288a3c vmov d6, r0, r1
 *   @0x288a40 vmov r0, r1, d8
 *   @0x288a44 vcvt.f32.f64 s18, d6
 *   @0x288a48 bl 0xb67d8 <sin@plt>
 *   @0x288a4c vmul.f32 s13, s18, s24
 *   @0x288a50 vmul.f32 s14, s18, s27
 *   @0x288a54 vmov d5, r0, r1
 *   @0x288a58 vcvt.f32.f64 s15, d5
 *   @0x288a5c vmul.f32 s24, s15, s24
 *   @0x288a60 vmul.f32 s27, s15, s27
 *   @0x288a64 vmla.f32 s13, s15, s23
 *   @0x288a68 vnmls.f32 s24, s18, s23
 *   @0x288a6c vstr s13, [r4, #64]
 *   @0x288a70 vnmls.f32 s27, s18, s26
 *   @0x288a74 vstr s24, [r4, #52]
 *   @0x288a78 vmla.f32 s14, s15, s26
 *   @0x288a7c vstr s27, [r4, #56]
 *   @0x288a80 vstr s14, [r4, #68]
 *   @0x288a84 add r8, r8, #1
 *   @0x288a88 add r5, r5, #12
 *   @0x288a8c cmp r8, r11
 *   @0x288a90 add r7, r7, #4
 *   @0x288a94 add r6, r6, #4
 *   @0x288a98 beq 0x288814 <spPathConstraint_apply+0x8c>
 *   @0x288a9c vmov.f32 s30, s21
 *   @0x288aa0 vmov.f32 s17, s20
 *   @0x288aa4 ldr r4, [r9, #0x4]!
 *   @0x288aa8 vldr s14, [r4, #60]
 *   @0x288aac vldr s15, [r4, #72]
 *   @0x288ab0 ldr r1, [sp, #0x18]
 *   @0x288ab4 vsub.f32 s12, s17, s28
 *   @0x288ab8 cmp r1, #0
 *   @0x288abc vsub.f32 s13, s30, s29
 *   @0x288ac0 vsub.f32 s12, s12, s14
 *   @0x288ac4 vsub.f32 s13, s13, s15
 *   @0x288ac8 vmla.f32 s14, s12, s22
 *   @0x288acc vmla.f32 s15, s13, s22
 *   @0x288ad0 vstr s14, [r4, #60]
 *   @0x288ad4 vstr s15, [r4, #72]
 *   @0x288ad8 vldr s20, [r5, #-8]
 *   @0x288adc vldr s21, [r5, #-4]
 *   @0x288ae0 vsub.f32 s17, s20, s17
 *   @0x288ae4 vsub.f32 s30, s21, s30
 *   @0x288ae8 beq 0x288afc <spPathConstraint_apply+0x374>
 *   @0x288aec vldr s16, [r6]
 *   @0x288af0 vcmp.f32 s16, #0
 *   @0x288af4 vmrs APSR_nzcv, fpscr
 *   @0x288af8 bne 0x288b68 <spPathConstraint_apply+0x3e0>
 *   @0x288afc cmp r10, #0
 *   @0x288b00 beq 0x288a84 <spPathConstraint_apply+0x2fc>
 *   @0x288b04 ldr r2, [sp, #0x14]
 *   @0x288b08 vldr s23, [r4, #52]
 *   @0x288b0c vldr s26, [r4, #56]
 *   @0x288b10 vldr s24, [r4, #64]
 *   @0x288b14 cmp r2, #0
 *   @0x288b18 vldr s27, [r4, #68]
 *   @0x288b1c bne 0x288974 <spPathConstraint_apply+0x1ec>
 *   @0x288b20 vldr s15, [r7]
 *   @0x288b24 vcmp.f32 s15, #0
 *   @0x288b28 vmrs APSR_nzcv, fpscr
 *   @0x288b2c bne 0x288bbc <spPathConstraint_apply+0x434>
 *   @0x288b30 vldr s16, [r5]
 *   @0x288b34 b 0x288978 <spPathConstraint_apply+0x1f0>
 *   @0x288b38 ldr r3, [r0, #0x24]
 *   @0x288b3c str r3, [sp, #0x28]
 *   @0x288b40 b 0x28886c <spPathConstraint_apply+0xe4>
 *   @0x288b44 movt r1, #0xc049
 *   @0x288b48 vmov s10, r1
 *   @0x288b4c vcmpe.f32 s16, s10
 *   @0x288b50 vmrs APSR_nzcv, fpscr
 *   @0x288b54 movwmi r1, #0xfdb
 *   @0x288b58 movtmi r1, #0x40c9
 *   @0x288b5c vmovmi s10, r1
 *   @0x288b60 vaddmi.f32 s16, s16, s10
 *   @0x288b64 b 0x288a2c <spPathConstraint_apply+0x2a4>
 *   @0x288b68 vmul.f32 s12, s30, s30
 *   @0x288b6c vmla.f32 s12, s17, s17
 *   @0x288b70 vcvt.f64.f32 d6, s12
 *   @0x288b74 vsqrt.f64 d7, d6
 *   @0x288b78 vcmp.f64 d7, d7
 *   @0x288b7c vmrs APSR_nzcv, fpscr
 *   @0x288b80 bne 0x288e30 <spPathConstraint_apply+0x6a8>
 *   @0x288b84 vcvt.f32.f64 s14, d7
 *   @0x288b88 mov r2, #1065353216
 *   @0x288b8c vmov s10, r2
 *   @0x288b90 vldr s12, [r4, #52]
 *   @0x288b94 vmov s15, r2
 *   @0x288b98 vldr s13, [r4, #64]
 *   @0x288b9c vdiv.f32 s16, s14, s16
 *   @0x288ba0 vsub.f32 s16, s16, s10
 *   @0x288ba4 vmla.f32 s15, s16, s25
 *   @0x288ba8 vmul.f32 s14, s12, s15
 *   @0x288bac vmul.f32 s15, s13, s15
 *   @0x288bb0 vstr s14, [r4, #52]
 *   @0x288bb4 vstr s15, [r4, #64]
 *   @0x288bb8 b 0x288afc <spPathConstraint_apply+0x374>
 *   @0x288bbc vcvt.f64.f32 d5, s30
 *   @0x288bc0 vcvt.f64.f32 d6, s17
 *   @0x288bc4 vmov r0, r1, d5
 *   @0x288bc8 vmov r2, r3, d6
 *   @0x288bcc bl 0xb6c70 <atan2@plt>
 *   @0x288bd0 vmov d7, r0, r1
 *   @0x288bd4 vcvt.f32.f64 s16, d7
 *   @0x288bd8 b 0x288978 <spPathConstraint_apply+0x1f0>
 *   @0x288bdc ldr r1, [sp, #0x18]
 *   @0x288be0 cmp r1, #0
 *   @0x288be4 bne 0x288c74 <spPathConstraint_apply+0x4ec>
 *   @0x288be8 cmp r7, #1
 *   @0x288bec ldrle r1, [sp, #0x18]
 *   @0x288bf0 strle r1, [sp, #0x2c]
 *   @0x288bf4 ble 0x2888c8 <spPathConstraint_apply+0x140>
 *   @0x288bf8 ldr r2, [sp, #0x28]
 *   @0x288bfc cmp r9, #0
 *   @0x288c00 ldr r1, [sp, #0x20]
 *   @0x288c04 add r11, r2, #4
 *   @0x288c08 ldr r9, [sp, #0x18]
 *   @0x288c0c sub r3, r1, #4
 *   @0x288c10 sub r2, r7, #1
 *   @0x288c14 bne 0x288d54 <spPathConstraint_apply+0x5cc>
 *   @0x288c18 ldr r1, [r3, #0x4]!
 *   @0x288c1c vldr s14, [r1, #52]
 *   @0x288c20 vldr s12, [r1, #64]
 *   @0x288c24 add r9, r9, #1
 *   @0x288c28 ldr r1, [r1]
 *   @0x288c2c vldr s15, [r1, #12]
 *   @0x288c30 vmul.f32 s12, s15, s12
 *   @0x288c34 vmul.f32 s15, s15, s14
 *   @0x288c38 vmul.f32 s12, s12, s12
 *   @0x288c3c vmla.f32 s12, s15, s15
 *   @0x288c40 vcvt.f64.f32 d6, s12
 *   @0x288c44 vsqrt.f64 d7, d6
 *   @0x288c48 vcmp.f64 d7, d7
 *   @0x288c4c vmrs APSR_nzcv, fpscr
 *   @0x288c50 bne 0x288e68 <spPathConstraint_apply+0x6e0>
 *   @0x288c54 cmp r9, r2
 *   @0x288c58 vstmia r11!, {s16}
 *   @0x288c5c bne 0x288c18 <spPathConstraint_apply+0x490>
 *   @0x288c60 b 0x2888c0 <spPathConstraint_apply+0x138>
 *   @0x288c64 andeq r0, r0, r0
 *   @0x288c68 andeq pc, r12, r4, lsr #2
 *   @0x288c6c ldrdeq lr, pc, [r12], -r0
 *   @0x288c70 andeq r0, r0, r0
 *   @0x288c74 ldr r3, [r4, #0x40]
 *   @0x288c78 cmp r3, r8
 *   @0x288c7c beq 0x288d48 <spPathConstraint_apply+0x5c0>
 *   @0x288c80 ldr r0, [r4, #0x44]
 *   @0x288c84 cmp r0, #0
 *   @0x288c88 beq 0x288c98 <spPathConstraint_apply+0x510>
 *   @0x288c8c str r12, [sp, #0x8]
 *   @0x288c90 bl 0x285c80 <_free>
 *   @0x288c94 ldr r12, [sp, #0x8]
 *   @0x288c98 ldr r1, [pc, #-0x34]
 *   @0x288c9c lsl r0, r8, #2
 *   @0x288ca0 mov r2, #111
 *   @0x288ca4 str r12, [sp, #0x8]
 *   @0x288ca8 add r1, pc, r1
 *   @0x288cac bl 0x285c10 <_malloc>
 *   @0x288cb0 ldr r12, [sp, #0x8]
 *   @0x288cb4 str r8, [r4, #0x40]
 *   @0x288cb8 str r0, [sp, #0x2c]
 *   @0x288cbc str r0, [r4, #0x44]
 *   @0x288cc0 cmp r7, #1
 *   @0x288cc4 ble 0x2888c8 <spPathConstraint_apply+0x140>
 *   @0x288cc8 ldr r3, [sp, #0x20]
 *   @0x288ccc cmp r9, #0
 *   @0x288cd0 ldr r1, [sp, #0x28]
 *   @0x288cd4 sub r2, r3, #4
 *   @0x288cd8 ldr r11, [sp, #0x2c]
 *   @0x288cdc add r3, r1, #4
 *   @0x288ce0 sub r1, r7, #1
 *   @0x288ce4 bne 0x288dbc <spPathConstraint_apply+0x634>
 *   @0x288ce8 str r12, [sp, #0x1c]
 *   @0x288cec mov r12, r1
 *   @0x288cf0 ldr r1, [r2, #0x4]!
 *   @0x288cf4 vldr s14, [r1, #52]
 *   @0x288cf8 vldr s12, [r1, #64]
 *   @0x288cfc add r9, r9, #1
 *   @0x288d00 ldr r1, [r1]
 *   @0x288d04 vldr s15, [r1, #12]
 *   @0x288d08 vmul.f32 s12, s15, s12
 *   @0x288d0c vmul.f32 s15, s15, s14
 *   @0x288d10 vmul.f32 s12, s12, s12
 *   @0x288d14 vmla.f32 s12, s15, s15
 *   @0x288d18 vcvt.f64.f32 d6, s12
 *   @0x288d1c vsqrt.f64 d7, d6
 *   @0x288d20 vcmp.f64 d7, d7
 *   @0x288d24 vmrs APSR_nzcv, fpscr
 *   @0x288d28 bne 0x288e8c <spPathConstraint_apply+0x704>
 *   @0x288d2c vcvt.f32.f64 s14, d7
 *   @0x288d30 cmp r9, r12
 *   @0x288d34 vstmia r11!, {s14}
 *   @0x288d38 vstmia r3!, {s16}
 *   @0x288d3c bne 0x288cf0 <spPathConstraint_apply+0x568>
 *   @0x288d40 ldr r12, [sp, #0x1c]
 *   @0x288d44 b 0x2888c8 <spPathConstraint_apply+0x140>
 *   @0x288d48 ldr r2, [r4, #0x44]
 *   @0x288d4c str r2, [sp, #0x2c]
 *   @0x288d50 b 0x288cc0 <spPathConstraint_apply+0x538>
 *   @0x288d54 ldr r1, [r3, #0x4]!
 *   @0x288d58 vldr s14, [r1, #52]
 *   @0x288d5c vldr s12, [r1, #64]
 *   @0x288d60 add r9, r9, #1
 *   @0x288d64 ldr r1, [r1]
 *   @0x288d68 vldr s15, [r1, #12]
 *   @0x288d6c vmul.f32 s12, s15, s12
 *   @0x288d70 vmul.f32 s15, s15, s14
 *   @0x288d74 vmul.f32 s12, s12, s12
 *   @0x288d78 vmla.f32 s12, s15, s15
 *   @0x288d7c vcvt.f64.f32 d6, s12
 *   @0x288d80 vsqrt.f64 d7, d6
 *   @0x288d84 vcmp.f64 d7, d7
 *   @0x288d88 vmrs APSR_nzcv, fpscr
 *   @0x288d8c bne 0x288e40 <spPathConstraint_apply+0x6b8>
 *   @0x288d90 vcvt.f32.f64 s14, d7
 *   @0x288d94 vadd.f32 s14, s14, s16
 *   @0x288d98 vcmpe.f32 s14, #0
 *   @0x288d9c vmrs APSR_nzcv, fpscr
 *   @0x288da0 vmovmi.f32 s14, s17
 *   @0x288da4 cmp r9, r2
 *   @0x288da8 vstmia r11!, {s14}
 *   @0x288dac bne 0x288d54 <spPathConstraint_apply+0x5cc>
 *   @0x288db0 mov r1, #0
 *   @0x288db4 str r1, [sp, #0x2c]
 *   @0x288db8 b 0x2888c8 <spPathConstraint_apply+0x140>
 *   @0x288dbc str r12, [sp, #0x1c]
 *   @0x288dc0 mov r9, #0
 *   @0x288dc4 mov r12, r1
 *   @0x288dc8 vldr s17, [pc, #-352]
 *   @0x288dcc ldr r1, [r2, #0x4]!
 *   @0x288dd0 vldr s14, [r1, #52]
 *   @0x288dd4 vldr s12, [r1, #64]
 *   @0x288dd8 add r9, r9, #1
 *   @0x288ddc ldr r1, [r1]
 *   @0x288de0 vldr s15, [r1, #12]
 *   @0x288de4 vmul.f32 s12, s15, s12
 *   @0x288de8 vmul.f32 s15, s15, s14
 *   @0x288dec vmul.f32 s12, s12, s12
 *   @0x288df0 vmla.f32 s12, s15, s15
 *   @0x288df4 vcvt.f64.f32 d6, s12
 *   @0x288df8 vsqrt.f64 d7, d6
 *   @0x288dfc vcmp.f64 d7, d7
 *   @0x288e00 vmrs APSR_nzcv, fpscr
 *   @0x288e04 bne 0x288eb4 <spPathConstraint_apply+0x72c>
 *   @0x288e08 vcvt.f32.f64 s14, d7
 *   @0x288e0c vadd.f32 s15, s14, s16
 *   @0x288e10 vstmia r11!, {s14}
 *   @0x288e14 vcmpe.f32 s15, #0
 *   @0x288e18 vmrs APSR_nzcv, fpscr
 *   @0x288e1c vmovmi.f32 s15, s17
 *   @0x288e20 cmp r9, r12
 *   @0x288e24 vstmia r3!, {s15}
 *   @0x288e28 bne 0x288dcc <spPathConstraint_apply+0x644>
 *   @0x288e2c b 0x288d40 <spPathConstraint_apply+0x5b8>
 *   @0x288e30 vmov r0, r1, d6
 *   @0x288e34 bl 0xb66f4 <sqrt@plt>
 *   @0x288e38 vmov d7, r0, r1
 *   @0x288e3c b 0x288b84 <spPathConstraint_apply+0x3fc>
 *   @0x288e40 vmov r0, r1, d6
 *   @0x288e44 str r2, [sp, #0x10]
 *   @0x288e48 str r3, [sp, #0xc]
 *   @0x288e4c str r12, [sp, #0x8]
 *   @0x288e50 bl 0xb66f4 <sqrt@plt>
 *   @0x288e54 ldr r12, [sp, #0x8]
 *   @0x288e58 ldr r3, [sp, #0xc]
 *   @0x288e5c ldr r2, [sp, #0x10]
 *   @0x288e60 vmov d7, r0, r1
 *   @0x288e64 b 0x288d90 <spPathConstraint_apply+0x608>
 *   @0x288e68 vmov r0, r1, d6
 *   @0x288e6c str r2, [sp, #0x10]
 *   @0x288e70 str r3, [sp, #0xc]
 *   @0x288e74 str r12, [sp, #0x8]
 *   @0x288e78 bl 0xb66f4 <sqrt@plt>
 *   @0x288e7c ldr r12, [sp, #0x8]
 *   @0x288e80 ldr r3, [sp, #0xc]
 *   @0x288e84 ldr r2, [sp, #0x10]
 *   @0x288e88 b 0x288c54 <spPathConstraint_apply+0x4cc>
 *   @0x288e8c vmov r0, r1, d6
 *   @0x288e90 str r2, [sp, #0x10]
 *   @0x288e94 str r3, [sp, #0xc]
 *   @0x288e98 str r12, [sp, #0x8]
 *   @0x288e9c bl 0xb66f4 <sqrt@plt>
 *   @0x288ea0 ldr r12, [sp, #0x8]
 *   @0x288ea4 ldr r3, [sp, #0xc]
 *   @0x288ea8 ldr r2, [sp, #0x10]
 *   @0x288eac vmov d7, r0, r1
 *   @0x288eb0 b 0x288d2c <spPathConstraint_apply+0x5a4>
 *   @0x288eb4 vmov r0, r1, d6
 *   @0x288eb8 str r2, [sp, #0x10]
 *   @0x288ebc str r3, [sp, #0xc]
 *   @0x288ec0 str r12, [sp, #0x8]
 *   @0x288ec4 bl 0xb66f4 <sqrt@plt>
 *   @0x288ec8 ldr r12, [sp, #0x8]
 *   @0x288ecc ldr r3, [sp, #0xc]
 *   @0x288ed0 ldr r2, [sp, #0x10]
 *   @0x288ed4 vmov d7, r0, r1
 *   @0x288ed8 b 0x288e08 <spPathConstraint_apply+0x680>
 */
