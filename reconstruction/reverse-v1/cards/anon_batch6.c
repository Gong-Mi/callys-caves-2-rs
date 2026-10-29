/* cally 逆向卡：匿名代码段骨架（asm/anon_splits.tsv 切分产物，原版 libyoyo.so，armv7）
 * 节: 8 段｜锚点 6932 条｜入选条件: size≥512 B、有入口证据、未被既有卡主张
 * 级别: 骨架 —— 只有地址、尺寸、ISA、入度/调用者与出调用；**没有任何语义主张**。
 *       这些段被 strip 掉了符号，METHOD §4 规定只能叫 anon_<addr>、不许编名字；
 *       段内语义要等从调用点反推或出正文卡时才升格，本卡不越过这条线。
 * 切分依据: asm/anon_splits.tsv（bl 直接目标 / ARM prologue / .data·.rodata 数据指针三信号）
 * 索引: asm/instructions.jsonl（census，Thumb 双遍解码）
 *
 * ══ §1/8 anon_234434  0x234434..0x234774  size 832  208 条｜ISA ARM｜入口证据 prologue｜父块 anon_234434
 * @func 0x234434 0x234774  size 832  208 条
 * 入度 4｜调用者: 0x234a0c(ogg_stream_flush+0x8), 0x234a18(ogg_stream_flush_fill+0x8), 0x234a68(ogg_stream_pageout+0x4c), 0x234ad0(ogg_stream_pageout_fill+0x50)
 * 出调用 4 处 → 0xb6694×2, ogg_stream_check×1, ogg_page_checksum_set×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x234434 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x234438 sub sp, sp, #20
 *   @0x23443c ldr r6, [r0, #0x1c]
 *   @0x234440 mov r4, r0
 *   @0x234444 str r3, [sp]
 *   @0x234448 mov r9, r1
 *   @0x23444c str r2, [sp, #0x8]
 *   @0x234450 bl 0x23412c <ogg_stream_check>
 *   @0x234454 ldr r3, [sp]
 *   @0x234458 cmp r0, #0
 *   @0x23445c movne r0, #0
 *   @0x234460 bne 0x2346b4 <ogg_page_checksum_set+0x360>
 *   @0x234464 cmp r6, #255
 *   @0x234468 movge r6, #255
 *   @0x23446c cmp r6, #0
 *   @0x234470 beq 0x2346b4 <ogg_page_checksum_set+0x360>
 *   @0x234474 ldr r2, [r4, #0x14c]
 *   @0x234478 cmp r2, #0
 *   @0x23447c str r2, [sp, #0xc]
 *   @0x234480 beq 0x2346bc <ogg_page_checksum_set+0x368>
 *   @0x234484 cmp r6, #0
 *   @0x234488 ble 0x23475c <ogg_page_checksum_set+0x408>
 *   @0x23448c ldr r2, [r4, #0x10]
 *   @0x234490 mvn r7, #0
 *   @0x234494 mov r8, r7
 *   @0x234498 mov r11, r0
 *   @0x23449c sub r10, r2, #4
 *   @0x2344a0 mov r12, r0
 *   @0x2344a4 str r2, [sp, #0x4]
 *   @0x2344a8 mov r2, r0
 *   @0x2344ac b 0x2344cc <ogg_page_checksum_set+0x178>
 *   @0x2344b0 cmp r5, #3
 *   @0x2344b4 movle r5, #0
 *   @0x2344b8 movgt r5, #1
 *   @0x2344bc cmp r3, r12
 *   @0x2344c0 movge r5, #0
 *   @0x2344c4 cmp r5, #0
 *   @0x2344c8 bne 0x234738 <ogg_page_checksum_set+0x3e4>
 *   @0x2344cc ldr r1, [r10, #0x4]!
 *   @0x2344d0 mov r5, #0
 *   @0x2344d4 uxtb r1, r1
 *   @0x2344d8 cmp r1, #255
 *   @0x2344dc add r12, r12, r1
 *   @0x2344e0 beq 0x2344fc <ogg_page_checksum_set+0x1a8>
 *   @0x2344e4 ldr r1, [r4, #0x14]
 *   @0x2344e8 add r11, r11, #1
 *   @0x2344ec add r8, r1, r2, lsl #3
 *   @0x2344f0 mov r5, r11
 *   @0x2344f4 ldr r7, [r1, r2, lsl #3]
 *   @0x2344f8 ldr r8, [r8, #0x4]
 *   @0x2344fc add r2, r2, #1
 *   @0x234500 cmp r2, r6
 *   @0x234504 bne 0x2344b0 <ogg_page_checksum_set+0x15c>
 *   @0x234508 cmp r2, #255
 *   @0x23450c bne 0x234708 <ogg_page_checksum_set+0x3b4>
 *   @0x234510 movw r5, #0x7f8
 *   @0x234514 mov r1, #1020
 *   @0x234518 movw r12, #0x11a
 *   @0x23451c mov r10, r2
 *   @0x234520 ldr r0, [pc, #0x24c]
 *   @0x234524 mov r3, #0
 *   @0x234528 strb r3, [r4, #0x2d]
 *   @0x23452c add r6, r4, #40
 *   @0x234530 add r0, pc, r0
 *   @0x234534 strb r3, [r4, #0x2c]
 *   @0x234538 ldr lr, [r4, #0x1c]
 *   @0x23453c ldr r0, [r0]
 *   @0x234540 str r0, [r4, #0x28]
 *   @0x234544 ldr r0, [sp, #0x4]
 *   @0x234548 ldr r3, [r0]
 *   @0x23454c tst r3, #256
 *   @0x234550 moveq r3, #1
 *   @0x234554 strbeq r3, [r4, #0x2d]
 *   @0x234558 ldr r3, [sp, #0xc]
 *   @0x23455c cmp r3, #0
 *   @0x234560 ldrbeq r3, [r4, #0x2d]
 *   @0x234564 orreq r3, r3, #2
 *   @0x234568 strbeq r3, [r4, #0x2d]
 *   @0x23456c ldr r3, [r4, #0x148]
 *   @0x234570 cmp r3, #0
 *   @0x234574 beq 0x234588 <ogg_page_checksum_set+0x234>
 *   @0x234578 cmp lr, r2
 *   @0x23457c ldrbeq r3, [r4, #0x2d]
 *   @0x234580 orreq r3, r3, #4
 *   @0x234584 strbeq r3, [r4, #0x2d]
 *   @0x234588 mov r0, r4
 *   @0x23458c mov r3, #6
 *   @0x234590 mov r11, #1
 *   @0x234594 str r11, [r4, #0x14c]
 *   @0x234598 add r3, r3, #1
 *   @0x23459c strb r7, [r0, #0x2e]
 *   @0x2345a0 cmp r3, #14
 *   @0x2345a4 lsr r7, r7, #8
 *   @0x2345a8 orr r7, r7, r8, lsl #24
 *   @0x2345ac add r0, r0, #1
 *   @0x2345b0 asr r8, r8, #8
 *   @0x2345b4 bne 0x234598 <ogg_page_checksum_set+0x244>
 *   @0x2345b8 ldr r3, [r4, #0x154]
 *   @0x2345bc ldr r0, [r4, #0x150]
 *   @0x2345c0 cmn r3, #1
 *   @0x2345c4 strb r10, [r4, #0x42]
 *   @0x2345c8 moveq r3, #0
 *   @0x2345cc asr r7, r0, #8
 *   @0x2345d0 strb r0, [r4, #0x36]
 *   @0x2345d4 strb r7, [r4, #0x37]
 *   @0x2345d8 asr r7, r0, #16
 *   @0x2345dc asr r0, r0, #24
 *   @0x2345e0 strb r0, [r4, #0x39]
 *   @0x2345e4 addne r0, r3, #1
 *   @0x2345e8 moveq r0, #1
 *   @0x2345ec cmp r2, #0
 *   @0x2345f0 strb r7, [r4, #0x38]
 *   @0x2345f4 str r0, [r4, #0x154]
 *   @0x2345f8 asr r7, r3, #8
 *   @0x2345fc asr r0, r3, #16
 *   @0x234600 strb r3, [r4, #0x3a]
 *   @0x234604 strb r7, [r4, #0x3b]
 *   @0x234608 asr r3, r3, #24
 *   @0x23460c mov r7, #0
 *   @0x234610 strb r0, [r4, #0x3c]
 *   @0x234614 strb r3, [r4, #0x3d]
 *   @0x234618 strb r7, [r4, #0x3e]
 *   @0x23461c strb r7, [r4, #0x3f]
 *   @0x234620 strb r7, [r4, #0x40]
 *   @0x234624 strb r7, [r4, #0x41]
 *   @0x234628 ble 0x234650 <ogg_page_checksum_set+0x2fc>
 *   @0x23462c ldr r0, [sp, #0x4]
 *   @0x234630 add r8, r4, #66
 *   @0x234634 sub r3, r0, #4
 *   @0x234638 add r10, r3, r2, lsl #2
 *   @0x23463c ldr r0, [r3, #0x4]!
 *   @0x234640 cmp r3, r10
 *   @0x234644 strb r0, [r8, #0x1]!
 *   @0x234648 uxtab r7, r7, r0
 *   @0x23464c bne 0x23463c <ogg_page_checksum_set+0x2e8>
 *   @0x234650 rsb lr, r2, lr
 *   @0x234654 ldr r3, [r4, #0xc]
 *   @0x234658 ldr r2, [r4]
 *   @0x23465c ldr r0, [sp, #0x4]
 *   @0x234660 add r3, r2, r3
 *   @0x234664 str r6, [r9]
 *   @0x234668 lsl r2, lr, #2
 *   @0x23466c str r12, [r4, #0x144]
 *   @0x234670 add r1, r0, r1
 *   @0x234674 str r12, [r9, #0x4]
 *   @0x234678 str r3, [r9, #0x8]
 *   @0x23467c str r7, [r9, #0xc]
 *   @0x234680 str lr, [r4, #0x1c]
 *   @0x234684 bl 0xb6694 <memmove@plt>
 *   @0x234688 ldr r2, [r4, #0x1c]
 *   @0x23468c ldr r0, [r4, #0x14]
 *   @0x234690 lsl r2, r2, #3
 *   @0x234694 add r1, r0, r5
 *   @0x234698 bl 0xb6694 <memmove@plt>
 *   @0x23469c ldr r3, [r4, #0xc]
 *   @0x2346a0 mov r0, r9
 *   @0x2346a4 add r7, r3, r7
 *   @0x2346a8 str r7, [r4, #0xc]
 *   @0x2346ac bl 0x234354 <ogg_page_checksum_set>
 *   @0x2346b0 mov r0, #1
 *   @0x2346b4 add sp, sp, #20
 *   @0x2346b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2346bc cmp r6, #0
 *   @0x2346c0 ble 0x23474c <ogg_page_checksum_set+0x3f8>
 *   @0x2346c4 ldr r3, [r4, #0x10]
 *   @0x2346c8 str r3, [sp, #0x4]
 *   @0x2346cc ldrb r3, [r3]
 *   @0x2346d0 cmp r3, #255
 *   @0x2346d4 bne 0x23476c <ogg_page_checksum_set+0x418>
 *   @0x2346d8 ldr r3, [sp, #0x4]
 *   @0x2346dc ldr r2, [sp, #0xc]
 *   @0x2346e0 b 0x2346f4 <ogg_page_checksum_set+0x3a0>
 *   @0x2346e4 ldr r1, [r3, #0x4]!
 *   @0x2346e8 uxtb r1, r1
 *   @0x2346ec cmp r1, #255
 *   @0x2346f0 bne 0x234730 <ogg_page_checksum_set+0x3dc>
 *   @0x2346f4 add r2, r2, #1
 *   @0x2346f8 cmp r2, r6
 *   @0x2346fc bne 0x2346e4 <ogg_page_checksum_set+0x390>
 *   @0x234700 mov r7, #0
 *   @0x234704 mov r8, r7
 *   @0x234708 ldr r3, [sp, #0x8]
 *   @0x23470c cmp r3, #0
 *   @0x234710 beq 0x2346b4 <ogg_page_checksum_set+0x360>
 *   @0x234714 ldr r3, [r4, #0x10]
 *   @0x234718 uxtb r10, r2
 *   @0x23471c add r12, r2, #27
 *   @0x234720 lsl r1, r2, #2
 *   @0x234724 lsl r5, r2, #3
 *   @0x234728 str r3, [sp, #0x4]
 *   @0x23472c b 0x234520 <ogg_page_checksum_set+0x1cc>
 *   @0x234730 add r2, r2, #1
 *   @0x234734 b 0x234700 <ogg_page_checksum_set+0x3ac>
 *   @0x234738 uxtb r10, r2
 *   @0x23473c add r12, r2, #27
 *   @0x234740 lsl r1, r2, #2
 *   @0x234744 lsl r5, r2, #3
 *   @0x234748 b 0x234520 <ogg_page_checksum_set+0x1cc>
 *   @0x23474c ldr r7, [sp, #0xc]
 *   @0x234750 mov r8, r7
 *   @0x234754 mov r2, r7
 *   @0x234758 b 0x234708 <ogg_page_checksum_set+0x3b4>
 *   @0x23475c mvn r7, #0
 *   @0x234760 mov r2, r0
 *   @0x234764 mov r8, r7
 *   @0x234768 b 0x234708 <ogg_page_checksum_set+0x3b4>
 *   @0x23476c mov r2, #1
 *   @0x234770 b 0x234700 <ogg_page_checksum_set+0x3ac>
 *
 * ══ §2/8 anon_26020c  0x26020c..0x262680  size 9332  2333 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_25fe2c
 * @func 0x26020c 0x262690  size 9348  2337 条
 * ⚠ 父块 anon_25fe2c 是 26,424 B 的未闭合大状态机（METHOD §4）：段长不一定等于函数长，本段可能只是其中的一段
 * 入度 88｜调用者: 0x2626c4(anon_25fe2c+0x2898), 0x2626f4(anon_25fe2c+0x28c8), 0x2627fc(anon_25fe2c+0x29d0), 0x262818(anon_25fe2c+0x29ec), 0x262860(anon_25fe2c+0x2a34), 0x26289c(anon_25fe2c+0x2a70), 0x262a7c(anon_25fe2c+0x2c50), 0x262ac4(anon_25fe2c+0x2c98)…
 * 出调用 28 处 → 0xb6694×5, 0xb65e0×4, _pcre_is_newline×3, anon_25b524+0xdd4×3, anon_25b524+0x1988×2, 0xb65bc×2
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x26020c ldr r12, [sp, #0x3c]
 *   @0x260210 movw r3, #0xffeb
 *   @0x260214 movt r3, #0x7fff
 *   @0x260218 ldr r1, [r12]
 *   @0x26021c ldr r12, [sp, #0x54]
 *   @0x260220 rsb r3, r1, r3
 *   @0x260224 cmp r6, r12
 *   @0x260228 movlo r6, r12
 *   @0x26022c rsb r2, r12, r6
 *   @0x260230 cmp r3, r2
 *   @0x260234 blt 0x261938 <_pcre_ord2utf+0x1ba0>
 *   @0x260238 ldr r12, [sp, #0x3c]
 *   @0x26023c cmp r8, #0
 *   @0x260240 add r2, r1, r2
 *   @0x260244 str r2, [r12]
 *   @0x260248 ldr r12, [sp, #0x60]
 *   @0x26024c beq 0x260e74 <_pcre_ord2utf+0x10dc>
 *   @0x260250 cmp r12, r8
 *   @0x260254 strhs r6, [sp, #0x54]
 *   @0x260258 blo 0x260d98 <_pcre_ord2utf+0x1000>
 *   @0x26025c cmp r4, #0
 *   @0x260260 beq 0x260278 <_pcre_ord2utf+0x4e0>
 *   @0x260264 cmp r4, #92
 *   @0x260268 beq 0x260d08 <_pcre_ord2utf+0xf70>
 *   @0x26026c ldr r12, [sp, #0x94]
 *   @0x260270 cmp r12, #0
 *   @0x260274 bne 0x260d24 <_pcre_ord2utf+0xf8c>
 *   @0x260278 ldr r12, [sp, #0x40]
 *   @0x26027c ands r7, r12, #8
 *   @0x260280 beq 0x2602d8 <_pcre_ord2utf+0x540>
 *   @0x260284 ldr r1, [r9, #0xc]
 *   @0x260288 ldr r5, [sp, #0x13c]
 *   @0x26028c ldrb r3, [r1, r4]
 *   @0x260290 tst r3, #1
 *   @0x260294 beq 0x261660 <_pcre_ord2utf+0x18c8>
 *   @0x260298 mov r3, r5
 *   @0x26029c b 0x2602a4 <_pcre_ord2utf+0x50c>
 *   @0x2602a0 mov r3, r2
 *   @0x2602a4 add r2, r3, #1
 *   @0x2602a8 str r2, [sp, #0x13c]
 *   @0x2602ac ldrb r4, [r3, #0x1]
 *   @0x2602b0 mov r11, r2
 *   @0x2602b4 ldrb r3, [r1, r4]
 *   @0x2602b8 tst r3, #1
 *   @0x2602bc bne 0x2602a0 <_pcre_ord2utf+0x508>
 *   @0x2602c0 cmp r4, #35
 *   @0x2602c4 beq 0x261344 <_pcre_ord2utf+0x15ac>
 *   @0x2602c8 cmp r5, r11
 *   @0x2602cc bhs 0x2602d8 <_pcre_ord2utf+0x540>
 *   @0x2602d0 ldr r7, [r9, #0x10]
 *   @0x2602d4 b 0x2601c0 <_pcre_ord2utf+0x428>
 *   @0x2602d8 cmp r4, #40
 *   @0x2602dc beq 0x260e0c <_pcre_ord2utf+0x1074>
 *   @0x2602e0 sub r3, r4, #42
 *   @0x2602e4 cmp r4, #63
 *   @0x2602e8 cmpne r3, #1
 *   @0x2602ec movhi r5, #0
 *   @0x2602f0 movls r5, #1
 *   @0x2602f4 movls r3, #1
 *   @0x2602f8 movls r5, #0
 *   @0x2602fc bls 0x260328 <_pcre_ord2utf+0x590>
 *   @0x260300 cmp r4, #123
 *   @0x260304 beq 0x2614a8 <_pcre_ord2utf+0x1710>
 *   @0x260308 ldr r12, [sp, #0x7c]
 *   @0x26030c cmp r12, #0
 *   @0x260310 beq 0x260320 <_pcre_ord2utf+0x588>
 *   @0x260314 ldr r12, [sp, #0x44]
 *   @0x260318 cmp r12, #0
 *   @0x26031c beq 0x261554 <_pcre_ord2utf+0x17bc>
 *   @0x260320 mov r5, #1
 *   @0x260324 mov r3, #0
 *   @0x260328 ldr r12, [sp, #0x40]
 *   @0x26032c tst r12, #16384
 *   @0x260330 beq 0x260390 <_pcre_ord2utf+0x5f8>
 *   @0x260334 ldr r12, [sp, #0x44]
 *   @0x260338 cmp r12, #0
 *   @0x26033c movne r5, #0
 *   @0x260340 andeq r5, r5, #1
 *   @0x260344 cmp r5, #0
 *   @0x260348 beq 0x260390 <_pcre_ord2utf+0x5f8>
 *   @0x26034c ldr r1, [sp, #0x13c]
 *   @0x260350 mov r2, #118
 *   @0x260354 strb r2, [r6]
 *   @0x260358 mvn r2, #0
 *   @0x26035c strb r2, [r6, #0x1]
 *   @0x260360 mov r2, #0
 *   @0x260364 ldr r0, [r9, #0x18]
 *   @0x260368 str r6, [sp, #0x7c]
 *   @0x26036c add r6, r6, #6
 *   @0x260370 rsb r0, r0, r1
 *   @0x260374 asr r0, r0, #8
 *   @0x260378 strb r0, [r6, #-0x4]
 *   @0x26037c ldr r0, [r9, #0x18]
 *   @0x260380 strb r2, [r6, #-0x2]
 *   @0x260384 rsb r1, r0, r1
 *   @0x260388 strb r2, [r6, #-0x1]
 *   @0x26038c strb r1, [r6, #-0x3]
 *   @0x260390 cmp r4, #124
 *   @0x260394 addls pc, pc, r4, lsl #2
 *   @0x260398 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26039c b 0x260b08 <_pcre_ord2utf+0xd70>
 *   @0x2603a0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603a4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603a8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603ac b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603b0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603b4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603b8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603bc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603c0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603c4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603c8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603cc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603d0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603d4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603d8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603dc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603e0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603e4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603e8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603ec b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603f0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603f4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603f8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2603fc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260400 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260404 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260408 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26040c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260410 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260414 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260418 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26041c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260420 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260424 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260428 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26042c b 0x260ae0 <_pcre_ord2utf+0xd48>
 *   @0x260430 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260434 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260438 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26043c b 0x260814 <_pcre_ord2utf+0xa7c>
 *   @0x260440 b 0x260b08 <_pcre_ord2utf+0xd70>
 *   @0x260444 b 0x2606fc <_pcre_ord2utf+0x964>
 *   @0x260448 b 0x2631b4 <_pcre_ord2utf+0x341c>
 *   @0x26044c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260450 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260454 b 0x260ba4 <_pcre_ord2utf+0xe0c>
 *   @0x260458 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26045c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260460 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260464 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260468 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26046c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260470 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260474 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260478 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26047c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260480 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260484 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260488 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26048c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260490 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260494 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260498 b 0x263174 <_pcre_ord2utf+0x33dc>
 *   @0x26049c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604a0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604a4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604a8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604ac b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604b0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604b4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604b8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604bc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604c0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604c4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604c8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604cc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604d0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604d4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604d8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604dc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604e0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604e4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604e8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604ec b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604f0 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604f4 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604f8 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x2604fc b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260500 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260504 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260508 b 0x2606a8 <_pcre_ord2utf+0x910>
 *   @0x26050c b 0x260a64 <_pcre_ord2utf+0xccc>
 *   @0x260510 b 0x2606e8 <_pcre_ord2utf+0x950>
 *   @0x260514 b 0x26066c <_pcre_ord2utf+0x8d4>
 *   @0x260518 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26051c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260520 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260524 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260528 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26052c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260530 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260534 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260538 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26053c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260540 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260544 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260548 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26054c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260550 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260554 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260558 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26055c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260560 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260564 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260568 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26056c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260570 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260574 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260578 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x26057c b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260580 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260584 b 0x260c0c <_pcre_ord2utf+0xe74>
 *   @0x260588 b 0x260590 <_pcre_ord2utf+0x7f8>
 *   @0x26058c b 0x260b08 <_pcre_ord2utf+0xd70>
 *   @0x260590 cmp r3, #0
 *   @0x260594 moveq r3, #123
 *   @0x260598 bne 0x261c7c <_pcre_ord2utf+0x1ee4>
 *   @0x26059c mov r12, #1
 *   @0x2605a0 ldr r1, [sp, #0x40]
 *   @0x2605a4 mov r8, r6
 *   @0x2605a8 mov r0, r12
 *   @0x2605ac and r1, r1, r12
 *   @0x2605b0 strb r3, [sp, #0x194]
 *   @0x2605b4 str r1, [sp, #0x58]
 *   @0x2605b8 ldr r2, [sp, #0x58]
 *   @0x2605bc add r6, r8, #1
 *   @0x2605c0 ldr r3, [r9, #0x10]
 *   @0x2605c4 cmp r2, #0
 *   @0x2605c8 ldr r2, [r9, #0x20]
 *   @0x2605cc moveq r1, #29
 *   @0x2605d0 movne r1, #30
 *   @0x2605d4 cmp r0, #0
 *   @0x2605d8 rsb r3, r3, r2
 *   @0x2605dc strb r1, [r8]
 *   @0x2605e0 str r3, [sp, #0x5c]
 *   @0x2605e4 beq 0x26060c <_pcre_ord2utf+0x874>
 *   @0x2605e8 add r2, sp, #400
 *   @0x2605ec add r4, r8, r0
 *   @0x2605f0 add r2, r2, #3
 *   @0x2605f4 mov r3, r8
 *   @0x2605f8 ldrb r1, [r2, #0x1]!
 *   @0x2605fc strb r1, [r3, #0x1]!
 *   @0x260600 cmp r3, r4
 *   @0x260604 bne 0x2605f8 <_pcre_ord2utf+0x860>
 *   @0x260608 add r6, r6, r0
 *   @0x26060c ldrb r3, [sp, #0x194]
 *   @0x260610 ldr r1, [sp, #0x4c]
 *   @0x260614 cmp r3, #13
 *   @0x260618 cmpne r3, #10
 *   @0x26061c ldreq r2, [r9, #0x64]
 *   @0x260620 orreq r2, r2, #2048
 *   @0x260624 streq r2, [r9, #0x64]
 *   @0x260628 cmn r1, #2
 *   @0x26062c beq 0x2612f8 <_pcre_ord2utf+0x1560>
 *   @0x260630 cmp r12, #0
 *   @0x260634 bne 0x2612b4 <_pcre_ord2utf+0x151c>
 *   @0x260638 ldr r12, [sp, #0x4c]
 *   @0x26063c ldr r11, [sp, #0x13c]
 *   @0x260640 ldr r7, [r9, #0x10]
 *   @0x260644 str r12, [sp, #0x58]
 *   @0x260648 ldr r12, [sp, #0x64]
 *   @0x26064c str r12, [sp, #0x78]
 *   @0x260650 ldr r12, [sp, #0x70]
 *   @0x260654 str r12, [sp, #0x80]
 *   @0x260658 ldr r12, [sp, #0x6c]
 *   @0x26065c str r12, [sp, #0x74]
 *   @0x260660 add r11, r11, #1
 *   @0x260664 str r11, [sp, #0x13c]
 *   @0x260668 b 0x2601c0 <_pcre_ord2utf+0x428>
 *   @0x26066c ldr r12, [sp, #0x40]
 *   @0x260670 ands r8, r12, #2
 *   @0x260674 beq 0x26185c <_pcre_ord2utf+0x1ac4>
 *   @0x260678 ldr r12, [sp, #0x4c]
 *   @0x26067c mov r3, #28
 *   @0x260680 strb r3, [r6]
 *   @0x260684 mov r8, #0
 *   @0x260688 cmn r12, #2
 *   @0x26068c ldr r11, [sp, #0x13c]
 *   @0x260690 add r6, r6, #1
 *   @0x260694 ldr r7, [r9, #0x10]
 *   @0x260698 mvneq r12, #0
 *   @0x26069c streq r12, [sp, #0x58]
 *   @0x2606a0 streq r12, [sp, #0x4c]
 *   @0x2606a4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2606a8 ldr r4, [sp, #0x13c]
 *   @0x2606ac mov r2, #6
 *   @0x2606b0 ldr r1, [pc, #0x7e0]
 *   @0x2606b4 add r5, r4, #1
 *   @0x2606b8 add r1, pc, r1
 *   @0x2606bc mov r0, r5
 *   @0x2606c0 bl 0xb65e0 <strncmp@plt>
 *   @0x2606c4 cmp r0, #0
 *   @0x2606c8 bne 0x261814 <_pcre_ord2utf+0x1a7c>
 *   @0x2606cc ldr r12, [sp, #0x100]
 *   @0x2606d0 add r4, r4, #7
 *   @0x2606d4 ldr r7, [r9, #0x10]
 *   @0x2606d8 str r4, [sp, #0x44]
 *   @0x2606dc str r12, [sp, #0x13c]
 *   @0x2606e0 mov r11, r12
 *   @0x2606e4 b 0x2601c0 <_pcre_ord2utf+0x428>
 *   @0x2606e8 ldr r3, [r9, #0x60]
 *   @0x2606ec tst r3, #33554432
 *   @0x2606f0 bne 0x264f84 <_pcre_ord2utf+0x51ec>
 *   @0x2606f4 mov r3, #93
 *   @0x2606f8 b 0x26059c <_pcre_ord2utf+0x804>
 *   @0x2606fc cmp r8, #0
 *   @0x260700 ldr r4, [sp, #0x13c]
 *   @0x260704 beq 0x262bf4 <_pcre_ord2utf+0x2e5c>
 *   @0x260708 ldr r12, [sp, #0x78]
 *   @0x26070c mov r5, #0
 *   @0x260710 mvn r11, #0
 *   @0x260714 str r12, [sp, #0x64]
 *   @0x260718 ldr r12, [sp, #0x58]
 *   @0x26071c str r12, [sp, #0x4c]
 *   @0x260720 ldr r12, [sp, #0x74]
 *   @0x260724 str r12, [sp, #0x6c]
 *   @0x260728 ldr r12, [sp, #0x80]
 *   @0x26072c str r12, [sp, #0x70]
 *   @0x260730 cmp r11, r5
 *   @0x260734 movne r12, #2
 *   @0x260738 moveq r12, #0
 *   @0x26073c str r12, [sp, #0x88]
 *   @0x260740 cmp r7, #0
 *   @0x260744 str r8, [sp, #0x138]
 *   @0x260748 beq 0x260ec4 <_pcre_ord2utf+0x112c>
 *   @0x26074c ldrb r3, [r4, #0x1]
 *   @0x260750 add r2, r4, #1
 *   @0x260754 ldr r0, [r9, #0xc]
 *   @0x260758 add r7, r9, #136
 *   @0x26075c mov r1, r3
 *   @0x260760 mov r3, r2
 *   @0x260764 mov r2, r1
 *   @0x260768 ldrb r1, [r0, r2]
 *   @0x26076c tst r1, #1
 *   @0x260770 bne 0x260808 <_pcre_ord2utf+0xa70>
 *   @0x260774 cmp r2, #35
 *   @0x260778 bne 0x260eb8 <_pcre_ord2utf+0x1120>
 *   @0x26077c ldrb r2, [r3, #0x1]
 *   @0x260780 add r4, r3, #1
 *   @0x260784 cmp r2, #0
 *   @0x260788 beq 0x2607f4 <_pcre_ord2utf+0xa5c>
 *   @0x26078c ldr r1, [r9, #0x84]
 *   @0x260790 cmp r1, #0
 *   @0x260794 beq 0x260c90 <_pcre_ord2utf+0xef8>
 *   @0x260798 ldr r2, [r9, #0x1c]
 *   @0x26079c cmp r2, r4
 *   @0x2607a0 movls r0, #0
 *   @0x2607a4 bhi 0x260cec <_pcre_ord2utf+0xf54>
 *   @0x2607a8 mov r1, r0
 *   @0x2607ac cmp r1, #0
 *   @0x2607b0 bne 0x260cd8 <_pcre_ord2utf+0xf40>
 *   @0x2607b4 cmp r10, #0
 *   @0x2607b8 ldrb r2, [r4, #0x1]
 *   @0x2607bc add r3, r4, #1
 *   @0x2607c0 beq 0x260c88 <_pcre_ord2utf+0xef0>
 *   @0x2607c4 and r1, r2, #192
 *   @0x2607c8 cmp r1, #128
 *   @0x2607cc bne 0x260c88 <_pcre_ord2utf+0xef0>
 *   @0x2607d0 add r3, r4, #2
 *   @0x2607d4 mov r4, r3
 *   @0x2607d8 add r3, r3, #1
 *   @0x2607dc ldrb r2, [r4]
 *   @0x2607e0 and r1, r2, #192
 *   @0x2607e4 cmp r1, #128
 *   @0x2607e8 beq 0x2607d4 <_pcre_ord2utf+0xa3c>
 *   @0x2607ec cmp r2, #0
 *   @0x2607f0 bne 0x26078c <_pcre_ord2utf+0x9f4>
 *   @0x2607f4 ldr r0, [r9, #0xc]
 *   @0x2607f8 mov r3, r4
 *   @0x2607fc ldrb r1, [r0, r2]
 *   @0x260800 tst r1, #1
 *   @0x260804 beq 0x260774 <_pcre_ord2utf+0x9dc>
 *   @0x260808 ldrb r2, [r3, #0x1]
 *   @0x26080c add r3, r3, #1
 *   @0x260810 b 0x260768 <_pcre_ord2utf+0x9d0>
 *   @0x260814 ldr r0, [sp, #0x13c]
 *   @0x260818 add r3, r0, #1
 *   @0x26081c str r3, [sp, #0x13c]
 *   @0x260820 ldrb r3, [r0, #0x1]
 *   @0x260824 cmp r3, #42
 *   @0x260828 beq 0x261b68 <_pcre_ord2utf+0x1dd0>
 *   @0x26082c cmp r3, #63
 *   @0x260830 ldr r7, [r9, #0x10]
 *   @0x260834 ldr r3, [r9, #0x20]
 *   @0x260838 rsb r12, r7, r3
 *   @0x26083c str r12, [sp, #0x5c]
 *   @0x260840 beq 0x261f94 <_pcre_ord2utf+0x21fc>
 *   @0x260844 ldr r12, [sp, #0x40]
 *   @0x260848 tst r12, #4096
 *   @0x26084c bne 0x261ba0 <_pcre_ord2utf+0x1e08>
 *   @0x260850 ldr r3, [r9, #0x40]
 *   @0x260854 add r3, r3, #1
 *   @0x260858 str r3, [r9, #0x40]
 *   @0x26085c lsr r3, r3, #8
 *   @0x260860 ldr r0, [sp, #0x40]
 *   @0x260864 mov r5, #2
 *   @0x260868 strb r3, [r6, #0x3]
 *   @0x26086c mov r4, #133
 *   @0x260870 ldr r2, [r9, #0x40]
 *   @0x260874 mov r3, #0
 *   @0x260878 strb r2, [r6, #0x4]
 *   @0x26087c ldr r2, [r9, #0x58]
 *   @0x260880 add r2, r2, #1
 *   @0x260884 str r2, [r9, #0x58]
 *   @0x260888 cmp r2, #250
 *   @0x26088c bgt 0x264f70 <_pcre_ord2utf+0x51d8>
 *   @0x260890 sub r11, r4, #125
 *   @0x260894 cmp r11, #3
 *   @0x260898 bhi 0x2608b0 <_pcre_ord2utf+0xb18>
 *   @0x26089c ldr r2, [r9, #0x80]
 *   @0x2608a0 cmp r2, #0
 *   @0x2608a4 movne r8, #0
 *   @0x2608a8 strne r8, [r9, #0x80]
 *   @0x2608ac bne 0x2608c4 <_pcre_ord2utf+0xb2c>
 *   @0x2608b0 ldr r1, [r9, #0x20]
 *   @0x2608b4 mov r8, r6
 *   @0x2608b8 ldr r2, [r9, #0x10]
 *   @0x2608bc rsb r2, r2, r1
 *   @0x2608c0 str r2, [sp, #0x5c]
 *   @0x2608c4 subs r2, r4, #135
 *   @0x2608c8 sub r1, r4, #127
 *   @0x2608cc rsbs r7, r2, #0
 *   @0x2608d0 ldr r12, [sp, #0x3c]
 *   @0x2608d4 adcs r7, r7, r2
 *   @0x2608d8 ldr lr, [sp, #0x1ec]
 *   @0x2608dc cmp r1, #1
 *   @0x2608e0 strb r4, [r6]
 *   @0x2608e4 mov r2, #0
 *   @0x2608e8 str r2, [sp, #0x134]
 *   @0x2608ec movhi r1, #0
 *   @0x2608f0 movls r1, #1
 *   @0x2608f4 cmp r12, #0
 *   @0x2608f8 add r12, lr, r7
 *   @0x2608fc ldr lr, [r9, #0x68]
 *   @0x260900 addne r2, sp, #308
 *   @0x260904 ldreq r2, [sp, #0x3c]
 *   @0x260908 str r6, [sp, #0x138]
 *   @0x26090c str lr, [sp, #0x50]
 *   @0x260910 ldr lr, [r9, #0x40]
 *   @0x260914 stm sp, {r1, r3, r5, r12}
 *   @0x260918 add r3, sp, #332
 *   @0x26091c str r2, [sp, #0x28]
 *   @0x260920 add r12, sp, #340
 *   @0x260924 str r3, [sp, #0x10]
 *   @0x260928 add r1, sp, #312
 *   @0x26092c add r3, sp, #344
 *   @0x260930 str r12, [sp, #0x1c]
 *   @0x260934 str r3, [sp, #0x14]
 *   @0x260938 add r12, sp, #364
 *   @0x26093c add r3, sp, #328
 *   @0x260940 str r9, [sp, #0x24]
 *   @0x260944 str r3, [sp, #0x18]
 *   @0x260948 add r2, sp, #316
 *   @0x26094c ldr r3, [sp, #0x48]
 *   @0x260950 str r12, [sp, #0x20]
 *   @0x260954 str lr, [sp, #0x68]
 *   @0x260958 bl 0x25ff54 <_pcre_ord2utf+0x1bc>
 *   @0x26095c cmp r0, #0
 *   @0x260960 beq 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x260964 ldr r3, [r9, #0x58]
 *   @0x260968 cmp r4, #129
 *   @0x26096c sub r3, r3, #1
 *   @0x260970 str r3, [r9, #0x58]
 *   @0x260974 beq 0x261d80 <_pcre_ord2utf+0x1fe8>
 *   @0x260978 cmp r11, #3
 *   @0x26097c ldr r12, [sp, #0x3c]
 *   @0x260980 ldrls r3, [r9, #0x5c]
 *   @0x260984 subls r3, r3, #1
 *   @0x260988 strls r3, [r9, #0x5c]
 *   @0x26098c cmp r12, #0
 *   @0x260990 movne r7, #0
 *   @0x260994 andeq r7, r7, #1
 *   @0x260998 cmp r7, #0
 *   @0x26099c beq 0x2609ec <_pcre_ord2utf+0xc54>
 *   @0x2609a0 mov r3, r6
 *   @0x2609a4 mov r2, #0
 *   @0x2609a8 ldrb r0, [r3, #0x1]
 *   @0x2609ac add r2, r2, #1
 *   @0x2609b0 ldrb r1, [r3, #0x2]
 *   @0x2609b4 orr r1, r1, r0, lsl #8
 *   @0x2609b8 ldrb r1, [r3, r1]!
 *   @0x2609bc cmp r1, #120
 *   @0x2609c0 bne 0x2609a8 <_pcre_ord2utf+0xc10>
 *   @0x2609c4 ldrb r4, [r6, #0x3]
 *   @0x2609c8 cmp r4, #145
 *   @0x2609cc beq 0x262ce4 <_pcre_ord2utf+0x2f4c>
 *   @0x2609d0 cmp r2, #2
 *   @0x2609d4 bgt 0x264f5c <_pcre_ord2utf+0x51c4>
 *   @0x2609d8 cmp r2, #1
 *   @0x2609dc mov r4, #135
 *   @0x2609e0 mvneq r3, #0
 *   @0x2609e4 streq r3, [sp, #0x154]
 *   @0x2609e8 streq r3, [sp, #0x158]
 *   @0x2609ec ldr r3, [sp, #0x13c]
 *   @0x2609f0 ldrb r2, [r3]
 *   @0x2609f4 cmp r2, #41
 *   @0x2609f8 bne 0x264f48 <_pcre_ord2utf+0x51b0>
 *   @0x2609fc ldr r12, [sp, #0x3c]
 *   @0x260a00 cmp r12, #0
 *   @0x260a04 beq 0x262c64 <_pcre_ord2utf+0x2ecc>
 *   @0x260a08 ldr r0, [r12]
 *   @0x260a0c movw r2, #0xffeb
 *   @0x260a10 ldr r1, [sp, #0x134]
 *   @0x260a14 movt r2, #0x7fff
 *   @0x260a18 rsb r2, r0, r2
 *   @0x260a1c sub r1, r1, #6
 *   @0x260a20 cmp r2, r1
 *   @0x260a24 blt 0x261848 <_pcre_ord2utf+0x1ab0>
 *   @0x260a28 ldr r12, [sp, #0x3c]
 *   @0x260a2c mov r2, #0
 *   @0x260a30 add r1, r0, r1
 *   @0x260a34 strb r2, [r6, #0x1]
 *   @0x260a38 mov r3, #3
 *   @0x260a3c mov r0, #120
 *   @0x260a40 strb r3, [r6, #0x2]
 *   @0x260a44 add r6, r6, #6
 *   @0x260a48 strb r0, [r6, #-0x3]
 *   @0x260a4c strb r2, [r6, #-0x2]
 *   @0x260a50 strb r3, [r6, #-0x1]
 *   @0x260a54 str r1, [r12]
 *   @0x260a58 ldr r11, [sp, #0x13c]
 *   @0x260a5c ldr r7, [r9, #0x10]
 *   @0x260a60 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x260a64 ldr lr, [sp, #0x40]
 *   @0x260a68 mov r2, #0
 *   @0x260a6c ldr r12, [sp, #0x13c]
 *   @0x260a70 add r0, sp, #316
 *   @0x260a74 ldr r3, [r9, #0x40]
 *   @0x260a78 add r1, sp, #336
 *   @0x260a7c str r2, [sp, #0x4]
 *   @0x260a80 str lr, [sp]
 *   @0x260a84 ldr r2, [sp, #0x48]
 *   @0x260a88 str r12, [sp, #0x140]
 *   @0x260a8c bl 0x25ceac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d84>
 *   @0x260a90 ldr r12, [sp, #0x48]
 *   @0x260a94 ldr r3, [r12]
 *   @0x260a98 cmp r3, #0
 *   @0x260a9c bne 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x260aa0 cmp r0, #0
 *   @0x260aa4 bne 0x26196c <_pcre_ord2utf+0x1bd4>
 *   @0x260aa8 ldr r0, [sp, #0x150]
 *   @0x260aac cmp r0, #127
 *   @0x260ab0 movls r3, #0
 *   @0x260ab4 andhi r3, r10, #1
 *   @0x260ab8 cmp r3, #0
 *   @0x260abc bne 0x261d54 <_pcre_ord2utf+0x1fbc>
 *   @0x260ac0 ldr r3, [sp, #0x40]
 *   @0x260ac4 mov r12, #1
 *   @0x260ac8 strb r0, [sp, #0x194]
 *   @0x260acc mov r8, r6
 *   @0x260ad0 and r3, r3, r12
 *   @0x260ad4 mov r0, r12
 *   @0x260ad8 str r3, [sp, #0x58]
 *   @0x260adc b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x260ae0 ldr r12, [sp, #0x40]
 *   @0x260ae4 mov r8, #0
 *   @0x260ae8 add r6, r6, #1
 *   @0x260aec tst r12, #2
 *   @0x260af0 moveq r3, #25
 *   @0x260af4 movne r3, #26
 *   @0x260af8 strb r3, [r6, #-0x1]
 *   @0x260afc ldr r11, [sp, #0x13c]
 *   @0x260b00 ldr r7, [r9, #0x10]
 *   @0x260b04 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x260b08 ldr r12, [sp, #0x3c]
 *   @0x260b0c mov r10, r6
 *   @0x260b10 ldr r4, [sp, #0x13c]
 *   @0x260b14 cmp r12, #0
 *   @0x260b18 beq 0x260b48 <_pcre_ord2utf+0xdb0>
 *   @0x260b1c ldr r1, [r12]
 *   @0x260b20 movw r3, #0xffeb
 *   @0x260b24 ldr r12, [sp, #0x54]
 *   @0x260b28 movt r3, #0x7fff
 *   @0x260b2c rsb r3, r1, r3
 *   @0x260b30 rsb r2, r12, r6
 *   @0x260b34 cmp r3, r2
 *   @0x260b38 blt 0x26184c <_pcre_ord2utf+0x1ab4>
 *   @0x260b3c ldr r12, [sp, #0x3c]
 *   @0x260b40 add r2, r1, r2
 *   @0x260b44 str r2, [r12]
 *   @0x260b48 ldr r12, [sp, #0xe0]
 *   @0x260b4c ldr r3, [r9, #0x40]
 *   @0x260b50 ldr r5, [sp, #0x64]
 *   @0x260b54 cmp r12, r3
 *   @0x260b58 movlo r12, r3
 *   @0x260b5c str r12, [sp, #0xe0]
 *   @0x260b60 ldr r12, [sp, #0xc8]
 *   @0x260b64 ldr r8, [sp, #0x6c]
 *   @0x260b68 cmp r12, #0
 *   @0x260b6c beq 0x261a3c <_pcre_ord2utf+0x1ca4>
 *   @0x260b70 ldrb r3, [r4]
 *   @0x260b74 cmp r3, #124
 *   @0x260b78 bne 0x264f40 <_pcre_ord2utf+0x51a8>
 *   @0x260b7c ldr r12, [sp, #0xd0]
 *   @0x260b80 ldr r2, [sp, #0x130]
 *   @0x260b84 ldr r3, [r12]
 *   @0x260b88 add r2, r2, #3
 *   @0x260b8c ldr r12, [sp, #0xe8]
 *   @0x260b90 str r2, [sp, #0x130]
 *   @0x260b94 add r3, r3, r12
 *   @0x260b98 str r3, [sp, #0x60]
 *   @0x260b9c add r4, r4, #1
 *   @0x260ba0 b 0x2600e0 <_pcre_ord2utf+0x348>
 *   @0x260ba4 ldr r12, [sp, #0x4c]
 *   @0x260ba8 mov r8, r6
 *   @0x260bac ldr r2, [r9, #0x20]
 *   @0x260bb0 add r6, r6, #1
 *   @0x260bb4 cmn r12, #2
 *   @0x260bb8 ldr r3, [r9, #0x10]
 *   @0x260bbc mvneq r12, #0
 *   @0x260bc0 str r12, [sp, #0x4c]
 *   @0x260bc4 ldr r12, [sp, #0x40]
 *   @0x260bc8 rsb r3, r3, r2
 *   @0x260bcc str r3, [sp, #0x5c]
 *   @0x260bd0 tst r12, #4
 *   @0x260bd4 ldr r12, [sp, #0x4c]
 *   @0x260bd8 moveq r3, #12
 *   @0x260bdc movne r3, #13
 *   @0x260be0 strb r3, [r6, #-0x1]
 *   @0x260be4 ldr r11, [sp, #0x13c]
 *   @0x260be8 ldr r7, [r9, #0x10]
 *   @0x260bec str r12, [sp, #0x58]
 *   @0x260bf0 ldr r12, [sp, #0x64]
 *   @0x260bf4 str r12, [sp, #0x78]
 *   @0x260bf8 ldr r12, [sp, #0x70]
 *   @0x260bfc str r12, [sp, #0x80]
 *   @0x260c00 ldr r12, [sp, #0x6c]
 *   @0x260c04 str r12, [sp, #0x74]
 *   @0x260c08 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x260c0c mov r8, r6
 *   @0x260c10 cmp r4, #191
 *   @0x260c14 movls r12, #0
 *   @0x260c18 andhi r12, r10, #1
 *   @0x260c1c strb r4, [sp, #0x194]
 *   @0x260c20 cmp r12, #0
 *   @0x260c24 beq 0x26132c <_pcre_ord2utf+0x1594>
 *   @0x260c28 ldr r3, [sp, #0x13c]
 *   @0x260c2c ldrb r2, [r3, #0x1]
 *   @0x260c30 and r2, r2, #192
 *   @0x260c34 cmp r2, #128
 *   @0x260c38 bne 0x261800 <_pcre_ord2utf+0x1a68>
 *   @0x260c3c add r3, r3, #2
 *   @0x260c40 add r2, sp, #404
 *   @0x260c44 mov r0, #1
 *   @0x260c48 sub r1, r3, #1
 *   @0x260c4c str r1, [sp, #0x13c]
 *   @0x260c50 ldrb r12, [r3, #-0x1]
 *   @0x260c54 add r0, r0, #1
 *   @0x260c58 add r3, r3, #1
 *   @0x260c5c strb r12, [r2, #0x1]!
 *   @0x260c60 ldrb r1, [r3, #-0x1]
 *   @0x260c64 and r1, r1, #192
 *   @0x260c68 cmp r1, #128
 *   @0x260c6c beq 0x260c48 <_pcre_ord2utf+0xeb0>
 *   @0x260c70 ldr r1, [sp, #0x98]
 *   @0x260c74 ldr r2, [sp, #0x40]
 *   @0x260c78 eor r12, r1, #1
 *   @0x260c7c and r2, r2, #1
 *   @0x260c80 str r2, [sp, #0x58]
 *   @0x260c84 b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x260c88 mov r4, r3
 *   @0x260c8c b 0x260784 <_pcre_ord2utf+0x9ec>
 *   @0x260c90 ldr r3, [r9, #0x88]
 *   @0x260c94 ldr r0, [r9, #0x1c]
 *   @0x260c98 rsb r0, r3, r0
 *   @0x260c9c cmp r4, r0
 *   @0x260ca0 bhi 0x2607ac <_pcre_ord2utf+0xa14>
 *   @0x260ca4 ldrb r0, [r9, #0x8c]
 *   @0x260ca8 cmp r0, r2
 *   @0x260cac bne 0x2607ac <_pcre_ord2utf+0xa14>
 *   @0x260cb0 cmp r3, #1
 *   @0x260cb4 moveq r1, r3
 *   @0x260cb8 beq 0x2607ac <_pcre_ord2utf+0xa14>
 *   @0x260cbc ldrb r1, [r4, #0x1]
 *   @0x260cc0 ldrb r3, [r9, #0x8d]
 *   @0x260cc4 subs r0, r1, r3
 *   @0x260cc8 rsbs r1, r0, #0
 *   @0x260ccc adcs r1, r1, r0
 *   @0x260cd0 cmp r1, #0
 *   @0x260cd4 beq 0x2607b4 <_pcre_ord2utf+0xa1c>
 *   @0x260cd8 ldr r2, [r9, #0x88]
 *   @0x260cdc ldr r0, [r9, #0xc]
 *   @0x260ce0 add r3, r4, r2
 *   @0x260ce4 ldrb r2, [r4, r2]
 *   @0x260ce8 b 0x260768 <_pcre_ord2utf+0x9d0>
 *   @0x260cec str r10, [sp]
 *   @0x260cf0 mov r0, r4
 *   @0x260cf4 mov r3, r7
 *   @0x260cf8 bl 0x25f9fc <_pcre_is_newline>
 *   @0x260cfc adds r0, r0, #0
 *   @0x260d00 movne r0, #1
 *   @0x260d04 b 0x2607a8 <_pcre_ord2utf+0xa10>
 *   @0x260d08 ldr r11, [sp, #0x13c]
 *   @0x260d0c ldrb r3, [r11, #0x1]
 *   @0x260d10 cmp r3, #69
 *   @0x260d14 beq 0x2615f0 <_pcre_ord2utf+0x1858>
 *   @0x260d18 ldr r12, [sp, #0x94]
 *   @0x260d1c cmp r12, #0
 *   @0x260d20 beq 0x2614d4 <_pcre_ord2utf+0x173c>
 *   @0x260d24 ldr r12, [sp, #0x7c]
 *   @0x260d28 cmp r12, #0
 *   @0x260d2c beq 0x260d3c <_pcre_ord2utf+0xfa4>
 *   @0x260d30 ldr r12, [sp, #0x3c]
 *   @0x260d34 cmp r12, #0
 *   @0x260d38 beq 0x2616d8 <_pcre_ord2utf+0x1940>
 *   @0x260d3c ldr r12, [sp, #0x40]
 *   @0x260d40 ands r3, r12, #16384
 *   @0x260d44 streq r3, [sp, #0x7c]
 *   @0x260d48 moveq r8, r6
 *   @0x260d4c beq 0x260c10 <_pcre_ord2utf+0xe78>
 *   @0x260d50 ldr r2, [sp, #0x13c]
 *   @0x260d54 mov r3, #118
 *   @0x260d58 strb r3, [r6]
 *   @0x260d5c mvn r3, #0
 *   @0x260d60 strb r3, [r6, #0x1]
 *   @0x260d64 add r8, r6, #6
 *   @0x260d68 ldr r1, [r9, #0x18]
 *   @0x260d6c mov r3, #0
 *   @0x260d70 str r6, [sp, #0x7c]
 *   @0x260d74 rsb r1, r1, r2
 *   @0x260d78 asr r1, r1, #8
 *   @0x260d7c strb r1, [r6, #0x2]
 *   @0x260d80 ldr r1, [r9, #0x18]
 *   @0x260d84 strb r3, [r6, #0x4]
 *   @0x260d88 rsb r2, r1, r2
 *   @0x260d8c strb r3, [r6, #0x5]
 *   @0x260d90 strb r2, [r6, #0x3]
 *   @0x260d94 b 0x260c10 <_pcre_ord2utf+0xe78>
 *   @0x260d98 rsb r2, r8, r6
 *   @0x260d9c mov r0, r12
 *   @0x260da0 mov r1, r8
 *   @0x260da4 bl 0xb6694 <memmove@plt>
 *   @0x260da8 ldr r12, [sp, #0x60]
 *   @0x260dac rsb r8, r8, r12
 *   @0x260db0 add r6, r6, r8
 *   @0x260db4 mov r8, r12
 *   @0x260db8 str r6, [sp, #0x54]
 *   @0x260dbc b 0x26025c <_pcre_ord2utf+0x4c4>
 *   @0x260dc0 ldr r2, [r9, #0x3c]
 *   @0x260dc4 ldr r3, [r9, #0x20]
 *   @0x260dc8 add r7, r7, r2
 *   @0x260dcc cmp r3, r7
 *   @0x260dd0 bls 0x26025c <_pcre_ord2utf+0x4c4>
 *   @0x260dd4 ldr r12, [sp, #0x48]
 *   @0x260dd8 mov r3, #52
 *   @0x260ddc ldr r4, [sp, #0x13c]
 *   @0x260de0 str r3, [r12]
 *   @0x260de4 ldr r12, [sp, #0xc4]
 *   @0x260de8 mov r0, #0
 *   @0x260dec str r4, [r12]
 *   @0x260df0 ldr r12, [sp, #0xf4]
 *   @0x260df4 ldr r2, [sp, #0x1b4]
 *   @0x260df8 ldr r3, [r12]
 *   @0x260dfc cmp r2, r3
 *   @0x260e00 bne 0x264f3c <_pcre_ord2utf+0x51a4>
 *   @0x260e04 add sp, sp, #444
 *   @0x260e08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x260e0c ldr r2, [sp, #0x13c]
 *   @0x260e10 ldrb r3, [r2, #0x1]
 *   @0x260e14 cmp r3, #63
 *   @0x260e18 bne 0x260308 <_pcre_ord2utf+0x570>
 *   @0x260e1c ldrb r3, [r2, #0x2]
 *   @0x260e20 cmp r3, #35
 *   @0x260e24 bne 0x260308 <_pcre_ord2utf+0x570>
 *   @0x260e28 add r3, r2, #3
 *   @0x260e2c str r3, [sp, #0x13c]
 *   @0x260e30 ldrb r3, [r2, #0x3]
 *   @0x260e34 cmp r3, #41
 *   @0x260e38 cmpne r3, #0
 *   @0x260e3c beq 0x260e58 <_pcre_ord2utf+0x10c0>
 *   @0x260e40 add r2, r2, #4
 *   @0x260e44 str r2, [sp, #0x13c]
 *   @0x260e48 ldrb r3, [r2], #1
 *   @0x260e4c cmp r3, #41
 *   @0x260e50 cmpne r3, #0
 *   @0x260e54 bne 0x260e44 <_pcre_ord2utf+0x10ac>
 *   @0x260e58 cmp r3, #0
 *   @0x260e5c bne 0x261d98 <_pcre_ord2utf+0x2000>
 *   @0x260e60 ldr r12, [sp, #0x48]
 *   @0x260e64 mov r3, #18
 *   @0x260e68 ldr r4, [sp, #0x13c]
 *   @0x260e6c str r3, [r12]
 *   @0x260e70 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x260e74 str r12, [sp, #0x54]
 *   @0x260e78 mov r6, r12
 *   @0x260e7c b 0x26025c <_pcre_ord2utf+0x4c4>
 *   @0x260e80 andseq r1, r9, r8, ror #25
 *   @0x260e84 .word 0xffffbd00
 *   @0x260e88 .word 0xfffffba4
 *   @0x260e8c andseq r9, r2, r4, lsl #22
 *   @0x260e90 andseq r9, r2, r4, ror #21
 *   @0x260e94 andeq r6, pc, r12, ror #29
 *   @0x260e98 andeq r6, pc, r12, lsr #17
 *   @0x260e9c andseq r8, r2, r4, lsr r12
 *   @0x260ea0 ldrheq r8, [r2], -r8
 *   @0x260ea4 .word 0xfffffb8c
 *   @0x260ea8 .word 0xfffffb90
 *   @0x260eac andeq r5, pc, r12, asr #14
 *   @0x260eb0 andeq r5, pc, r4, lsl #7
 *   @0x260eb4 andseq r7, r2, r12, lsr sp
 *   @0x260eb8 sub r2, r3, #1
 *   @0x260ebc str r2, [sp, #0x13c]
 *   @0x260ec0 mov r4, r2
 *   @0x260ec4 ldrb r3, [r4, #0x1]
 *   @0x260ec8 cmp r3, #40
 *   @0x260ecc beq 0x261604 <_pcre_ord2utf+0x186c>
 *   @0x260ed0 cmp r3, #43
 *   @0x260ed4 beq 0x261574 <_pcre_ord2utf+0x17dc>
 *   @0x260ed8 cmp r3, #63
 *   @0x260edc beq 0x261708 <_pcre_ord2utf+0x1970>
 *   @0x260ee0 ldr r12, [sp, #0xb0]
 *   @0x260ee4 str r12, [sp, #0x50]
 *   @0x260ee8 mov r12, #0
 *   @0x260eec str r12, [sp, #0x84]
 *   @0x260ef0 ldrb r4, [r8]
 *   @0x260ef4 cmp r4, #117
 *   @0x260ef8 beq 0x261598 <_pcre_ord2utf+0x1800>
 *   @0x260efc sub r3, r4, #29
 *   @0x260f00 cmp r3, #3
 *   @0x260f04 bhi 0x2614f0 <_pcre_ord2utf+0x1758>
 *   @0x260f08 sub r3, r4, #30
 *   @0x260f0c uxtb r3, r3
 *   @0x260f10 cmp r3, #2
 *   @0x260f14 movhi r3, #0
 *   @0x260f18 ldrls r2, [pc, #-0x84]
 *   @0x260f1c addls r2, pc, r2
 *   @0x260f20 addls r3, r2, r3, lsl #2
 *   @0x260f24 ldrls r3, [r3, #0x2d8]
 *   @0x260f28 cmp r10, #0
 *   @0x260f2c ldrb r7, [r6, #-0x1]
 *   @0x260f30 beq 0x260f40 <_pcre_ord2utf+0x11a8>
 *   @0x260f34 and r2, r7, #192
 *   @0x260f38 cmp r2, #128
 *   @0x260f3c beq 0x26215c <_pcre_ord2utf+0x23c4>
 *   @0x260f40 cmp r4, #30
 *   @0x260f44 bhi 0x260f64 <_pcre_ord2utf+0x11cc>
 *   @0x260f48 cmp r5, #1
 *   @0x260f4c ble 0x260f64 <_pcre_ord2utf+0x11cc>
 *   @0x260f50 ldr r2, [r9, #0x68]
 *   @0x260f54 ldr r12, [sp, #0x98]
 *   @0x260f58 str r7, [sp, #0x6c]
 *   @0x260f5c orr r2, r12, r2
 *   @0x260f60 str r2, [sp, #0x64]
 *   @0x260f64 sub r4, r4, #15
 *   @0x260f68 cmp r4, #1
 *   @0x260f6c ldrbls r12, [r8, #0x1]
 *   @0x260f70 mvnhi r12, #0
 *   @0x260f74 strhi r12, [sp, #0x8c]
 *   @0x260f78 strhi r12, [sp, #0x68]
 *   @0x260f7c strls r12, [sp, #0x68]
 *   @0x260f80 ldrbls r12, [r8, #0x2]
 *   @0x260f84 strls r12, [sp, #0x8c]
 *   @0x260f88 cmp r11, #0
 *   @0x260f8c beq 0x261504 <_pcre_ord2utf+0x176c>
 *   @0x260f90 ldr r0, [sp, #0x50]
 *   @0x260f94 cmp r5, #0
 *   @0x260f98 add r12, r0, r3
 *   @0x260f9c bne 0x261764 <_pcre_ord2utf+0x19cc>
 *   @0x260fa0 cmn r11, #1
 *   @0x260fa4 addeq r3, r12, #33
 *   @0x260fa8 strbeq r3, [r8]
 *   @0x260fac addeq r3, r8, #1
 *   @0x260fb0 beq 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x260fb4 cmp r11, #1
 *   @0x260fb8 strbne r11, [r8, #0x2]
 *   @0x260fbc addeq r3, r12, #37
 *   @0x260fc0 addne r3, r12, #39
 *   @0x260fc4 strbeq r3, [r8]
 *   @0x260fc8 addeq r3, r8, #1
 *   @0x260fcc strbne r3, [r8]
 *   @0x260fd0 addne r3, r8, #3
 *   @0x260fd4 asrne r6, r11, #8
 *   @0x260fd8 strbne r6, [r8, #0x1]
 *   @0x260fdc cmp r10, #0
 *   @0x260fe0 beq 0x260fec <_pcre_ord2utf+0x1254>
 *   @0x260fe4 tst r7, #268435456
 *   @0x260fe8 bne 0x261d3c <_pcre_ord2utf+0x1fa4>
 *   @0x260fec add r6, r3, #1
 *   @0x260ff0 strb r7, [r3]
 *   @0x260ff4 ldr r12, [sp, #0x84]
 *   @0x260ff8 cmp r12, #0
 *   @0x260ffc beq 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x261000 ldr r3, [sp, #0x138]
 *   @0x261004 ldrb r2, [r3]
 *   @0x261008 sub r1, r2, #29
 *   @0x26100c cmp r1, #83
 *   @0x261010 addls pc, pc, r1, lsl #2
 *   @0x261014 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261018 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x26101c b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x261020 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x261024 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x261028 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26102c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261030 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261034 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261038 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26103c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261040 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261044 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261048 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x26104c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261050 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261054 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261058 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26105c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261060 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261064 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261068 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26106c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261070 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261074 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261078 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26107c b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x261080 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261084 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261088 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26108c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261090 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261094 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261098 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26109c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610a0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610a4 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610a8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610ac b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610b0 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x2610b4 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610b8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610bc b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610c0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610c4 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610c8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610cc b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610d0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610d4 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610d8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610dc b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610e0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610e4 b 0x26126c <_pcre_ord2utf+0x14d4>
 *   @0x2610e8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610ec b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610f0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610f4 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610f8 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2610fc b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261100 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261104 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261108 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26110c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261110 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261114 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261118 b 0x261240 <_pcre_ord2utf+0x14a8>
 *   @0x26111c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261120 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261124 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261128 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26112c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261130 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261134 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261138 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26113c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261140 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261144 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261148 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26114c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261150 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261154 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261158 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26115c b 0x261260 <_pcre_ord2utf+0x14c8>
 *   @0x261160 b 0x261260 <_pcre_ord2utf+0x14c8>
 *   @0x261164 b 0x261168 <_pcre_ord2utf+0x13d0>
 *   @0x261168 ldrb r1, [r3, #0x1]
 *   @0x26116c ldrb r2, [r3, #0x2]
 *   @0x261170 orr r2, r2, r1, lsl #8
 *   @0x261174 add r3, r3, r2
 *   @0x261178 str r3, [sp, #0x138]
 *   @0x26117c rsb r4, r3, r6
 *   @0x261180 cmp r4, #0
 *   @0x261184 ble 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x261188 ldrb r2, [r3]
 *   @0x26118c cmp r2, #117
 *   @0x261190 bhi 0x2611b0 <_pcre_ord2utf+0x1418>
 *   @0x261194 ldr r1, [pc, #-0x2fc]
 *   @0x261198 add r1, pc, r1
 *   @0x26119c add r2, r1, r2
 *   @0x2611a0 ldrb r2, [r2, #0x2e4]
 *   @0x2611a4 cmp r2, #0
 *   @0x2611a8 strbne r2, [r3]
 *   @0x2611ac bne 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x2611b0 ldr r12, [sp, #0x5c]
 *   @0x2611b4 mov r3, #0
 *   @0x2611b8 strb r3, [r6]
 *   @0x2611bc mov r1, #3
 *   @0x2611c0 mov r3, r9
 *   @0x2611c4 ldr r0, [sp, #0x138]
 *   @0x2611c8 str r12, [sp]
 *   @0x2611cc mov r2, r10
 *   @0x2611d0 bl 0x25c2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11d0>
 *   @0x2611d4 ldr r1, [sp, #0x138]
 *   @0x2611d8 mov r2, r4
 *   @0x2611dc add r6, r6, #6
 *   @0x2611e0 add r0, r1, #3
 *   @0x2611e4 bl 0xb6694 <memmove@plt>
 *   @0x2611e8 ldr r2, [sp, #0x138]
 *   @0x2611ec mov r1, #120
 *   @0x2611f0 mvn r0, #126
 *   @0x2611f4 add r3, r4, #3
 *   @0x2611f8 strb r0, [r2]
 *   @0x2611fc ubfx r2, r3, #0x8, #0x8
 *   @0x261200 strb r1, [r6, #-0x3]
 *   @0x261204 uxtb r3, r3
 *   @0x261208 ldr r1, [sp, #0x138]
 *   @0x26120c strb r2, [r6, #-0x2]
 *   @0x261210 strb r3, [r6, #-0x1]
 *   @0x261214 strb r2, [r1, #0x1]
 *   @0x261218 ldr r2, [sp, #0x138]
 *   @0x26121c strb r3, [r2, #0x2]
 *   @0x261220 ldr r3, [r9, #0x68]
 *   @0x261224 mov r8, #0
 *   @0x261228 ldr r12, [sp, #0x88]
 *   @0x26122c ldr r11, [sp, #0x13c]
 *   @0x261230 orr r3, r3, r12
 *   @0x261234 ldr r7, [r9, #0x10]
 *   @0x261238 str r3, [r9, #0x68]
 *   @0x26123c b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261240 ldrb r2, [r3, #0x3]
 *   @0x261244 sub r2, r2, #15
 *   @0x261248 cmp r2, #1
 *   @0x26124c movhi r2, #4
 *   @0x261250 movls r2, #6
 *   @0x261254 add r3, r3, r2
 *   @0x261258 str r3, [sp, #0x138]
 *   @0x26125c b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261260 add r3, r3, #33
 *   @0x261264 str r3, [sp, #0x138]
 *   @0x261268 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26126c ldr r1, [pc, #-0x3d0]
 *   @0x261270 cmp r10, #0
 *   @0x261274 ldr r12, [sp, #0xa0]
 *   @0x261278 ldr r1, [r12, r1]
 *   @0x26127c ldrb r2, [r1, r2]
 *   @0x261280 add r3, r3, r2
 *   @0x261284 str r3, [sp, #0x138]
 *   @0x261288 beq 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x26128c ldrb r2, [r3, #-0x1]
 *   @0x261290 cmp r2, #191
 *   @0x261294 bls 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x261298 ldr r1, [pc, #-0x3f8]
 *   @0x26129c and r2, r2, #63
 *   @0x2612a0 ldr r1, [r12, r1]
 *   @0x2612a4 ldrb r2, [r1, r2]
 *   @0x2612a8 add r3, r3, r2
 *   @0x2612ac str r3, [sp, #0x138]
 *   @0x2612b0 b 0x26117c <_pcre_ord2utf+0x13e4>
 *   @0x2612b4 ldr r12, [sp, #0x64]
 *   @0x2612b8 ldr r3, [r9, #0x68]
 *   @0x2612bc ldr r11, [sp, #0x13c]
 *   @0x2612c0 str r12, [sp, #0x78]
 *   @0x2612c4 ldr r12, [sp, #0x6c]
 *   @0x2612c8 ldr r7, [r9, #0x10]
 *   @0x2612cc str r12, [sp, #0x74]
 *   @0x2612d0 ldr r12, [sp, #0x98]
 *   @0x2612d4 orr r3, r12, r3
 *   @0x2612d8 ldr r12, [sp, #0x4c]
 *   @0x2612dc str r3, [sp, #0x64]
 *   @0x2612e0 str r12, [sp, #0x58]
 *   @0x2612e4 ldr r12, [sp, #0x70]
 *   @0x2612e8 str r12, [sp, #0x80]
 *   @0x2612ec ldrb r12, [r6, #-0x1]
 *   @0x2612f0 str r12, [sp, #0x6c]
 *   @0x2612f4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2612f8 cmp r12, #0
 *   @0x2612fc bne 0x26150c <_pcre_ord2utf+0x1774>
 *   @0x261300 ldr r12, [sp, #0x64]
 *   @0x261304 ldr r11, [sp, #0x13c]
 *   @0x261308 ldr r7, [r9, #0x10]
 *   @0x26130c str r12, [sp, #0x78]
 *   @0x261310 mvn r12, #0
 *   @0x261314 str r12, [sp, #0x64]
 *   @0x261318 str r12, [sp, #0x58]
 *   @0x26131c str r12, [sp, #0x4c]
 *   @0x261320 ldr r12, [sp, #0x6c]
 *   @0x261324 str r12, [sp, #0x74]
 *   @0x261328 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x26132c ldr r3, [sp, #0x40]
 *   @0x261330 mov r12, #1
 *   @0x261334 mov r0, r12
 *   @0x261338 and r3, r3, r12
 *   @0x26133c str r3, [sp, #0x58]
 *   @0x261340 b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x261344 cmp r10, #0
 *   @0x261348 add r3, r11, #1
 *   @0x26134c str r3, [sp, #0x13c]
 *   @0x261350 ldrb r2, [r11, #0x1]
 *   @0x261354 addne r11, r9, #136
 *   @0x261358 bne 0x2613ec <_pcre_ord2utf+0x1654>
 *   @0x26135c add r12, r9, #136
 *   @0x261360 mov r11, r10
 *   @0x261364 str r12, [sp, #0x50]
 *   @0x261368 b 0x2613a4 <_pcre_ord2utf+0x160c>
 *   @0x26136c ldr r0, [r9, #0x88]
 *   @0x261370 ldr r12, [r9, #0x1c]
 *   @0x261374 rsb r12, r0, r12
 *   @0x261378 cmp r3, r12
 *   @0x26137c bhi 0x26138c <_pcre_ord2utf+0x15f4>
 *   @0x261380 ldrb r12, [r9, #0x8c]
 *   @0x261384 cmp r12, r2
 *   @0x261388 beq 0x261488 <_pcre_ord2utf+0x16f0>
 *   @0x26138c cmp r1, #0
 *   @0x261390 bne 0x2613d4 <_pcre_ord2utf+0x163c>
 *   @0x261394 add r1, r3, #1
 *   @0x261398 str r1, [sp, #0x13c]
 *   @0x26139c ldrb r2, [r3, #0x1]
 *   @0x2613a0 mov r3, r1
 *   @0x2613a4 cmp r2, #0
 *   @0x2613a8 beq 0x261460 <_pcre_ord2utf+0x16c8>
 *   @0x2613ac ldr r1, [r9, #0x84]
 *   @0x2613b0 cmp r1, #0
 *   @0x2613b4 beq 0x26136c <_pcre_ord2utf+0x15d4>
 *   @0x2613b8 ldr r2, [r9, #0x1c]
 *   @0x2613bc cmp r2, r3
 *   @0x2613c0 bhi 0x261468 <_pcre_ord2utf+0x16d0>
 *   @0x2613c4 mov r0, #0
 *   @0x2613c8 mov r1, r0
 *   @0x2613cc cmp r1, #0
 *   @0x2613d0 beq 0x261394 <_pcre_ord2utf+0x15fc>
 *   @0x2613d4 ldr r2, [r9, #0x88]
 *   @0x2613d8 add r3, r3, r2
 *   @0x2613dc str r3, [sp, #0x13c]
 *   @0x2613e0 mov r11, r3
 *   @0x2613e4 b 0x2602c8 <_pcre_ord2utf+0x530>
 *   @0x2613e8 mov r3, r1
 *   @0x2613ec cmp r2, #0
 *   @0x2613f0 beq 0x261460 <_pcre_ord2utf+0x16c8>
 *   @0x2613f4 ldr r1, [r9, #0x84]
 *   @0x2613f8 cmp r1, #0
 *   @0x2613fc beq 0x261724 <_pcre_ord2utf+0x198c>
 *   @0x261400 ldr r2, [r9, #0x1c]
 *   @0x261404 cmp r2, r3
 *   @0x261408 movls r0, #0
 *   @0x26140c bhi 0x261f70 <_pcre_ord2utf+0x21d8>
 *   @0x261410 mov r1, r0
 *   @0x261414 cmp r1, #0
 *   @0x261418 bne 0x2613d4 <_pcre_ord2utf+0x163c>
 *   @0x26141c add r1, r3, #1
 *   @0x261420 str r1, [sp, #0x13c]
 *   @0x261424 ldrb r2, [r3, #0x1]
 *   @0x261428 and r0, r2, #192
 *   @0x26142c cmp r0, #128
 *   @0x261430 bne 0x2613e8 <_pcre_ord2utf+0x1650>
 *   @0x261434 add r2, r3, #2
 *   @0x261438 str r2, [sp, #0x13c]
 *   @0x26143c mov r0, r2
 *   @0x261440 ldrb r3, [r2], #1
 *   @0x261444 and r1, r3, #192
 *   @0x261448 cmp r1, #128
 *   @0x26144c beq 0x261438 <_pcre_ord2utf+0x16a0>
 *   @0x261450 mov r2, r3
 *   @0x261454 cmp r2, #0
 *   @0x261458 mov r3, r0
 *   @0x26145c bne 0x2613f4 <_pcre_ord2utf+0x165c>
 *   @0x261460 mov r11, r3
 *   @0x261464 b 0x2602c8 <_pcre_ord2utf+0x530>
 *   @0x261468 mov r0, r3
 *   @0x26146c str r11, [sp]
 *   @0x261470 ldr r3, [sp, #0x50]
 *   @0x261474 bl 0x25f9fc <_pcre_is_newline>
 *   @0x261478 ldr r3, [sp, #0x13c]
 *   @0x26147c adds r0, r0, #0
 *   @0x261480 movne r0, #1
 *   @0x261484 b 0x2613c8 <_pcre_ord2utf+0x1630>
 *   @0x261488 cmp r0, #1
 *   @0x26148c beq 0x2613c8 <_pcre_ord2utf+0x1630>
 *   @0x261490 ldrb r1, [r9, #0x8d]
 *   @0x261494 ldrb r2, [r3, #0x1]
 *   @0x261498 subs r12, r1, r2
 *   @0x26149c rsbs r1, r12, #0
 *   @0x2614a0 adcs r1, r1, r12
 *   @0x2614a4 b 0x26138c <_pcre_ord2utf+0x15f4>
 *   @0x2614a8 ldr r0, [sp, #0x13c]
 *   @0x2614ac ldrb r3, [r0, #0x1]
 *   @0x2614b0 sub r3, r3, #48
 *   @0x2614b4 cmp r3, #9
 *   @0x2614b8 bhi 0x260308 <_pcre_ord2utf+0x570>
 *   @0x2614bc add r0, r0, #1
 *   @0x2614c0 bl 0x25ce14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cec>
 *   @0x2614c4 cmp r0, #0
 *   @0x2614c8 movne r3, #1
 *   @0x2614cc bne 0x260328 <_pcre_ord2utf+0x590>
 *   @0x2614d0 b 0x260308 <_pcre_ord2utf+0x570>
 *   @0x2614d4 cmp r3, #81
 *   @0x2614d8 bne 0x260278 <_pcre_ord2utf+0x4e0>
 *   @0x2614dc mov r12, #1
 *   @0x2614e0 add r11, r11, #1
 *   @0x2614e4 str r12, [sp, #0x94]
 *   @0x2614e8 ldr r7, [r9, #0x10]
 *   @0x2614ec b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2614f0 cmp r4, #22
 *   @0x2614f4 bhi 0x261668 <_pcre_ord2utf+0x18d0>
 *   @0x2614f8 mov r7, r4
 *   @0x2614fc mov r3, #52
 *   @0x261500 b 0x260f64 <_pcre_ord2utf+0x11cc>
 *   @0x261504 mov r6, r8
 *   @0x261508 b 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x26150c cmp r0, #1
 *   @0x261510 str r3, [sp, #0x70]
 *   @0x261514 beq 0x261aac <_pcre_ord2utf+0x1d14>
 *   @0x261518 ldr r12, [sp, #0x64]
 *   @0x26151c ldr r11, [sp, #0x13c]
 *   @0x261520 ldr r7, [r9, #0x10]
 *   @0x261524 str r12, [sp, #0x78]
 *   @0x261528 ldr r12, [sp, #0x6c]
 *   @0x26152c str r12, [sp, #0x74]
 *   @0x261530 ldr r12, [sp, #0x98]
 *   @0x261534 str r12, [sp, #0x4c]
 *   @0x261538 ldr r12, [r9, #0x68]
 *   @0x26153c str r12, [sp, #0x64]
 *   @0x261540 mvn r12, #0
 *   @0x261544 str r12, [sp, #0x58]
 *   @0x261548 ldrb r12, [r6, #-0x1]
 *   @0x26154c str r12, [sp, #0x6c]
 *   @0x261550 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261554 ldr r12, [sp, #0xbc]
 *   @0x261558 cmp r12, #0
 *   @0x26155c sub r3, r12, #1
 *   @0x261560 ble 0x261c5c <_pcre_ord2utf+0x1ec4>
 *   @0x261564 str r3, [sp, #0xbc]
 *   @0x261568 mov r5, #1
 *   @0x26156c ldr r3, [sp, #0x44]
 *   @0x261570 b 0x260328 <_pcre_ord2utf+0x590>
 *   @0x261574 add r4, r4, #1
 *   @0x261578 str r4, [sp, #0x13c]
 *   @0x26157c ldrb r4, [r8]
 *   @0x261580 mov r12, #1
 *   @0x261584 str r12, [sp, #0x84]
 *   @0x261588 mov r12, #0
 *   @0x26158c cmp r4, #117
 *   @0x261590 str r12, [sp, #0x50]
 *   @0x261594 bne 0x260efc <_pcre_ord2utf+0x1164>
 *   @0x261598 mov r1, r8
 *   @0x26159c mov r2, #3
 *   @0x2615a0 add r0, r8, #3
 *   @0x2615a4 add r6, r6, #6
 *   @0x2615a8 bl 0xb6694 <memmove@plt>
 *   @0x2615ac ldr r12, [sp, #0x3c]
 *   @0x2615b0 mov r2, #0
 *   @0x2615b4 mvn r3, #126
 *   @0x2615b8 cmp r12, #0
 *   @0x2615bc strb r3, [r8]
 *   @0x2615c0 strb r2, [r8, #0x1]
 *   @0x2615c4 mov r3, #6
 *   @0x2615c8 mov r1, #120
 *   @0x2615cc strb r2, [r8, #0x7]
 *   @0x2615d0 strb r3, [r8, #0x2]
 *   @0x2615d4 mov r2, #9
 *   @0x2615d8 strb r3, [r8, #0x8]
 *   @0x2615dc strb r1, [r8, #0x6]
 *   @0x2615e0 str r2, [sp, #0x134]
 *   @0x2615e4 beq 0x262a80 <_pcre_ord2utf+0x2ce8>
 *   @0x2615e8 ldrb r4, [r8]
 *   @0x2615ec b 0x260efc <_pcre_ord2utf+0x1164>
 *   @0x2615f0 mov r12, #0
 *   @0x2615f4 add r11, r11, #1
 *   @0x2615f8 str r12, [sp, #0x94]
 *   @0x2615fc ldr r7, [r9, #0x10]
 *   @0x261600 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261604 ldrb r3, [r4, #0x2]
 *   @0x261608 cmp r3, #63
 *   @0x26160c bne 0x260ee0 <_pcre_ord2utf+0x1148>
 *   @0x261610 ldrb r3, [r4, #0x3]
 *   @0x261614 cmp r3, #35
 *   @0x261618 bne 0x260ee0 <_pcre_ord2utf+0x1148>
 *   @0x26161c ldrb r3, [r4, #0x4]
 *   @0x261620 add r2, r4, #4
 *   @0x261624 str r2, [sp, #0x13c]
 *   @0x261628 cmp r3, #41
 *   @0x26162c cmpne r3, #0
 *   @0x261630 beq 0x26164c <_pcre_ord2utf+0x18b4>
 *   @0x261634 add r4, r4, #5
 *   @0x261638 str r4, [sp, #0x13c]
 *   @0x26163c ldrb r3, [r4], #1
 *   @0x261640 cmp r3, #41
 *   @0x261644 cmpne r3, #0
 *   @0x261648 bne 0x261638 <_pcre_ord2utf+0x18a0>
 *   @0x26164c cmp r3, #0
 *   @0x261650 beq 0x260e60 <_pcre_ord2utf+0x10c8>
 *   @0x261654 ldr r4, [sp, #0x13c]
 *   @0x261658 ldrb r3, [r4, #0x1]
 *   @0x26165c b 0x260ed0 <_pcre_ord2utf+0x1138>
 *   @0x261660 mov r11, r5
 *   @0x261664 b 0x2602c0 <_pcre_ord2utf+0x528>
 *   @0x261668 sub r3, r4, #110
 *   @0x26166c cmp r3, #6
 *   @0x261670 bhi 0x261ad8 <_pcre_ord2utf+0x1d40>
 *   @0x261674 cmp r11, #0
 *   @0x261678 beq 0x261504 <_pcre_ord2utf+0x176c>
 *   @0x26167c cmp r5, #0
 *   @0x261680 bne 0x262ac8 <_pcre_ord2utf+0x2d30>
 *   @0x261684 cmn r11, #1
 *   @0x261688 ldr r12, [sp, #0x50]
 *   @0x26168c addeq r3, r12, #98
 *   @0x261690 strbeq r3, [r6]
 *   @0x261694 addeq r6, r6, #1
 *   @0x261698 beq 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x26169c cmp r11, #1
 *   @0x2616a0 addeq r3, r12, #102
 *   @0x2616a4 strbeq r3, [r6]
 *   @0x2616a8 addeq r6, r6, #1
 *   @0x2616ac beq 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x2616b0 add r3, r12, #104
 *   @0x2616b4 strb r5, [r6, #0x1]
 *   @0x2616b8 strb r3, [r6]
 *   @0x2616bc strb r5, [r6, #0x2]
 *   @0x2616c0 ubfx r3, r11, #0x8, #0x8
 *   @0x2616c4 uxtb r2, r11
 *   @0x2616c8 strb r3, [r6, #0x3]
 *   @0x2616cc add r6, r6, #5
 *   @0x2616d0 strb r2, [r6, #-0x1]
 *   @0x2616d4 b 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x2616d8 ldr r12, [sp, #0x7c]
 *   @0x2616dc ldr r2, [r9, #0x18]
 *   @0x2616e0 ldr r1, [sp, #0x13c]
 *   @0x2616e4 ldrb r0, [r12, #0x2]
 *   @0x2616e8 ldrb r3, [r12, #0x3]
 *   @0x2616ec rsb r2, r2, r1
 *   @0x2616f0 orr r3, r3, r0, lsl #8
 *   @0x2616f4 rsb r3, r3, r2
 *   @0x2616f8 strb r3, [r12, #0x5]
 *   @0x2616fc asr r3, r3, #8
 *   @0x261700 strb r3, [r12, #0x4]
 *   @0x261704 b 0x260d3c <_pcre_ord2utf+0xfa4>
 *   @0x261708 ldr r12, [sp, #0xe4]
 *   @0x26170c add r4, r4, #1
 *   @0x261710 str r4, [sp, #0x13c]
 *   @0x261714 str r12, [sp, #0x50]
 *   @0x261718 mov r12, #0
 *   @0x26171c str r12, [sp, #0x84]
 *   @0x261720 b 0x260ef0 <_pcre_ord2utf+0x1158>
 *   @0x261724 ldr r0, [r9, #0x88]
 *   @0x261728 ldr r12, [r9, #0x1c]
 *   @0x26172c rsb r12, r0, r12
 *   @0x261730 cmp r3, r12
 *   @0x261734 bhi 0x261414 <_pcre_ord2utf+0x167c>
 *   @0x261738 ldrb r12, [r9, #0x8c]
 *   @0x26173c cmp r12, r2
 *   @0x261740 bne 0x261414 <_pcre_ord2utf+0x167c>
 *   @0x261744 cmp r0, #1
 *   @0x261748 beq 0x261410 <_pcre_ord2utf+0x1678>
 *   @0x26174c ldrb r1, [r3, #0x1]
 *   @0x261750 ldrb r2, [r9, #0x8d]
 *   @0x261754 subs r2, r1, r2
 *   @0x261758 rsbs r1, r2, #0
 *   @0x26175c adcs r1, r1, r2
 *   @0x261760 b 0x261414 <_pcre_ord2utf+0x167c>
 *   @0x261764 cmp r5, #1
 *   @0x261768 beq 0x262120 <_pcre_ord2utf+0x2388>
 *   @0x26176c cmp r11, #0
 *   @0x261770 add r3, r3, #41
 *   @0x261774 asr r2, r5, #8
 *   @0x261778 strb r3, [r8]
 *   @0x26177c strb r5, [r8, #0x2]
 *   @0x261780 add r3, r8, #3
 *   @0x261784 strb r2, [r8, #0x1]
 *   @0x261788 blt 0x262c20 <_pcre_ord2utf+0x2e88>
 *   @0x26178c cmp r11, r5
 *   @0x261790 beq 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x261794 cmp r10, #0
 *   @0x261798 beq 0x2617a4 <_pcre_ord2utf+0x1a0c>
 *   @0x26179c tst r7, #268435456
 *   @0x2617a0 bne 0x264e84 <_pcre_ord2utf+0x50ec>
 *   @0x2617a4 add r4, r8, #4
 *   @0x2617a8 strb r7, [r8, #0x3]
 *   @0x2617ac ldr r3, [sp, #0x68]
 *   @0x2617b0 cmn r3, #1
 *   @0x2617b4 beq 0x2617d0 <_pcre_ord2utf+0x1a38>
 *   @0x2617b8 ldr r0, [sp, #0x68]
 *   @0x2617bc mov r3, r4
 *   @0x2617c0 ldr r1, [sp, #0x8c]
 *   @0x2617c4 strb r0, [r3], #2
 *   @0x2617c8 strb r1, [r4, #0x1]
 *   @0x2617cc mov r4, r3
 *   @0x2617d0 rsb r5, r5, r11
 *   @0x2617d4 cmp r5, #1
 *   @0x2617d8 strbne r5, [r4, #0x2]
 *   @0x2617dc addeq r3, r12, #37
 *   @0x2617e0 addne r2, r12, #39
 *   @0x2617e4 strbeq r3, [r4]
 *   @0x2617e8 asrne r5, r5, #8
 *   @0x2617ec addeq r3, r4, #1
 *   @0x2617f0 addne r3, r4, #3
 *   @0x2617f4 strbne r2, [r4]
 *   @0x2617f8 strbne r5, [r4, #0x1]
 *   @0x2617fc b 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x261800 ldr r0, [sp, #0x40]
 *   @0x261804 and r0, r0, #1
 *   @0x261808 str r0, [sp, #0x58]
 *   @0x26180c mov r0, #1
 *   @0x261810 b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x261814 ldr r1, [pc, #-0x970]
 *   @0x261818 mov r0, r5
 *   @0x26181c mov r2, #6
 *   @0x261820 add r1, pc, r1
 *   @0x261824 bl 0xb65e0 <strncmp@plt>
 *   @0x261828 cmp r0, #0
 *   @0x26182c bne 0x261bb4 <_pcre_ord2utf+0x1e1c>
 *   @0x261830 ldr r12, [sp, #0xfc]
 *   @0x261834 add r4, r4, #7
 *   @0x261838 str r4, [sp, #0x44]
 *   @0x26183c str r12, [sp, #0x13c]
 *   @0x261840 mov r11, r12
 *   @0x261844 b 0x2602d0 <_pcre_ord2utf+0x538>
 *   @0x261848 mov r4, r3
 *   @0x26184c ldr r12, [sp, #0x48]
 *   @0x261850 mov r3, #20
 *   @0x261854 str r3, [r12]
 *   @0x261858 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x26185c mov r3, #27
 *   @0x261860 strb r3, [r6]
 *   @0x261864 ldr r11, [sp, #0x13c]
 *   @0x261868 add r6, r6, #1
 *   @0x26186c ldr r7, [r9, #0x10]
 *   @0x261870 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261874 ldrb r3, [r8, #0x3]
 *   @0x261878 cmp r3, #145
 *   @0x26187c beq 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x261880 cmp r5, #0
 *   @0x261884 bne 0x2621b0 <_pcre_ord2utf+0x2418>
 *   @0x261888 cmp r11, #1
 *   @0x26188c ble 0x261b0c <_pcre_ord2utf+0x1d74>
 *   @0x261890 ldr r12, [sp, #0x5c]
 *   @0x261894 add r4, r8, #4
 *   @0x261898 mov r0, r8
 *   @0x26189c mov r3, r9
 *   @0x2618a0 strb r5, [r6], #4
 *   @0x2618a4 mov r1, #4
 *   @0x2618a8 str r12, [sp]
 *   @0x2618ac mov r2, r10
 *   @0x2618b0 bl 0x25c2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11d0>
 *   @0x2618b4 mov r0, r4
 *   @0x2618b8 mov r1, r8
 *   @0x2618bc ldr r2, [sp, #0x68]
 *   @0x2618c0 str r4, [sp, #0x8c]
 *   @0x2618c4 bl 0xb6694 <memmove@plt>
 *   @0x2618c8 ldr r12, [sp, #0x50]
 *   @0x2618cc add r4, r8, #2
 *   @0x2618d0 strb r5, [r8, #0x2]
 *   @0x2618d4 mvn r3, #124
 *   @0x2618d8 strb r5, [r8, #0x3]
 *   @0x2618dc sub r2, r12, #110
 *   @0x2618e0 strb r3, [r8, #0x1]
 *   @0x2618e4 strb r2, [r8]
 *   @0x2618e8 mov r8, r5
 *   @0x2618ec sub r11, r11, #1
 *   @0x2618f0 mov r7, r8
 *   @0x2618f4 cmp r11, #0
 *   @0x2618f8 ldr r8, [sp, #0x8c]
 *   @0x2618fc ldr r12, [sp, #0x5c]
 *   @0x261900 blt 0x264680 <_pcre_ord2utf+0x48e8>
 *   @0x261904 ldr r2, [sp, #0x3c]
 *   @0x261908 cmp r2, #0
 *   @0x26190c beq 0x26471c <_pcre_ord2utf+0x4984>
 *   @0x261910 cmp r11, #0
 *   @0x261914 beq 0x262234 <_pcre_ord2utf+0x249c>
 *   @0x261918 ldr r1, [sp, #0x134]
 *   @0x26191c add r1, r1, #7
 *   @0x261920 smull r2, r3, r11, r1
 *   @0x261924 mul r1, r11, r1
 *   @0x261928 cmp r2, #-2147483648
 *   @0x26192c sbcs r12, r3, #0
 *   @0x261930 sub r1, r1, #6
 *   @0x261934 blt 0x262210 <_pcre_ord2utf+0x2478>
 *   @0x261938 ldr r12, [sp, #0x48]
 *   @0x26193c mov r3, #20
 *   @0x261940 ldr r4, [sp, #0x13c]
 *   @0x261944 str r3, [r12]
 *   @0x261948 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x26194c add r3, r7, r3
 *   @0x261950 ldr r12, [sp, #0x48]
 *   @0x261954 cmp r6, r3
 *   @0x261958 ldr r4, [sp, #0x13c]
 *   @0x26195c movlo r3, #87
 *   @0x261960 movhs r3, #52
 *   @0x261964 str r3, [r12]
 *   @0x261968 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x26196c cmp r0, #5
 *   @0x261970 ldr r12, [sp, #0x4c]
 *   @0x261974 movle r3, #0
 *   @0x261978 movgt r3, #1
 *   @0x26197c cmn r12, #2
 *   @0x261980 movne r3, #0
 *   @0x261984 cmp r3, #0
 *   @0x261988 beq 0x26199c <_pcre_ord2utf+0x1c04>
 *   @0x26198c cmp r0, #23
 *   @0x261990 mvnlt r12, #0
 *   @0x261994 mvnge r12, #1
 *   @0x261998 str r12, [sp, #0x4c]
 *   @0x26199c cmp r0, #27
 *   @0x2619a0 beq 0x262fdc <_pcre_ord2utf+0x3244>
 *   @0x2619a4 cmp r0, #28
 *   @0x2619a8 beq 0x262df8 <_pcre_ord2utf+0x3060>
 *   @0x2619ac cmp r0, #0
 *   @0x2619b0 blt 0x262d14 <_pcre_ord2utf+0x2f7c>
 *   @0x2619b4 sub r3, r0, #15
 *   @0x2619b8 cmp r0, #22
 *   @0x2619bc cmpne r3, #1
 *   @0x2619c0 bls 0x262d00 <_pcre_ord2utf+0x2f68>
 *   @0x2619c4 sub r3, r0, #4
 *   @0x2619c8 cmp r0, #1
 *   @0x2619cc cmpne r3, #1
 *   @0x2619d0 bhi 0x2619e4 <_pcre_ord2utf+0x1c4c>
 *   @0x2619d4 ldr r3, [r9, #0x48]
 *   @0x2619d8 cmp r3, #0
 *   @0x2619dc moveq r3, #1
 *   @0x2619e0 streq r3, [r9, #0x48]
 *   @0x2619e4 sub r8, r0, #6
 *   @0x2619e8 cmp r0, #14
 *   @0x2619ec moveq r3, r10
 *   @0x2619f0 orrne r3, r10, #1
 *   @0x2619f4 cmp r8, #16
 *   @0x2619f8 ldr r12, [sp, #0x4c]
 *   @0x2619fc ldr r1, [r9, #0x20]
 *   @0x261a00 movls r8, r6
 *   @0x261a04 movhi r8, #0
 *   @0x261a08 cmp r3, #0
 *   @0x261a0c ldr r2, [r9, #0x10]
 *   @0x261a10 add r3, r6, #1
 *   @0x261a14 uxtbne r0, r0
 *   @0x261a18 moveq r0, #13
 *   @0x261a1c strb r0, [r6]
 *   @0x261a20 rsb r2, r2, r1
 *   @0x261a24 str r12, [sp, #0x58]
 *   @0x261a28 str r2, [sp, #0x5c]
 *   @0x261a2c mov r6, r3
 *   @0x261a30 ldr r11, [sp, #0x13c]
 *   @0x261a34 ldr r7, [r9, #0x10]
 *   @0x261a38 b 0x260bf0 <_pcre_ord2utf+0xe58>
 *   @0x261a3c ldr r12, [sp, #0xb4]
 *   @0x261a40 ldrb r3, [r12]
 *   @0x261a44 cmp r3, #119
 *   @0x261a48 beq 0x262b5c <_pcre_ord2utf+0x2dc4>
 *   @0x261a4c ldr r12, [sp, #0x4c]
 *   @0x261a50 str r12, [sp, #0xb8]
 *   @0x261a54 ldr r12, [sp, #0x70]
 *   @0x261a58 str r12, [sp, #0xcc]
 *   @0x261a5c ldr r12, [sp, #0x1e0]
 *   @0x261a60 cmp r12, #0
 *   @0x261a64 bne 0x262b00 <_pcre_ord2utf+0x2d68>
 *   @0x261a68 ldrb r3, [r4]
 *   @0x261a6c cmp r3, #124
 *   @0x261a70 bne 0x264d68 <_pcre_ord2utf+0x4fd0>
 *   @0x261a74 ldr r12, [sp, #0xb4]
 *   @0x261a78 str r5, [sp, #0xac]
 *   @0x261a7c rsb r3, r12, r10
 *   @0x261a80 str r10, [sp, #0xb4]
 *   @0x261a84 strb r3, [r10, #0x2]
 *   @0x261a88 add r12, r10, #3
 *   @0x261a8c asr r3, r3, #8
 *   @0x261a90 str r8, [sp, #0xa4]
 *   @0x261a94 strb r3, [r10, #0x1]
 *   @0x261a98 mov r3, #119
 *   @0x261a9c str r12, [sp, #0x60]
 *   @0x261aa0 strb r3, [r10]
 *   @0x261aa4 str r10, [sp, #0x170]
 *   @0x261aa8 b 0x260b9c <_pcre_ord2utf+0xe04>
 *   @0x261aac ldr r12, [sp, #0x64]
 *   @0x261ab0 ldr r11, [sp, #0x13c]
 *   @0x261ab4 ldr r7, [r9, #0x10]
 *   @0x261ab8 str r12, [sp, #0x78]
 *   @0x261abc ldr r12, [sp, #0x6c]
 *   @0x261ac0 str r12, [sp, #0x74]
 *   @0x261ac4 ldr r12, [sp, #0x98]
 *   @0x261ac8 str r12, [sp, #0x4c]
 *   @0x261acc mvn r12, #0
 *   @0x261ad0 str r12, [sp, #0x58]
 *   @0x261ad4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261ad8 sub r3, r4, #125
 *   @0x261adc cmp r3, #10
 *   @0x261ae0 bhi 0x262194 <_pcre_ord2utf+0x23fc>
 *   @0x261ae4 cmp r4, #135
 *   @0x261ae8 rsb r12, r8, r6
 *   @0x261aec str r12, [sp, #0x68]
 *   @0x261af0 beq 0x261874 <_pcre_ord2utf+0x1adc>
 *   @0x261af4 cmp r4, #128
 *   @0x261af8 bhi 0x261880 <_pcre_ord2utf+0x1ae8>
 *   @0x261afc cmp r11, #1
 *   @0x261b00 movhs r11, #1
 *   @0x261b04 cmp r5, #0
 *   @0x261b08 bne 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x261b0c add r12, r8, #1
 *   @0x261b10 str r12, [sp, #0x8c]
 *   @0x261b14 ldr r12, [sp, #0x5c]
 *   @0x261b18 mov r3, r9
 *   @0x261b1c mov r4, #0
 *   @0x261b20 mov r0, r8
 *   @0x261b24 strb r4, [r6], #1
 *   @0x261b28 mov r1, #1
 *   @0x261b2c str r12, [sp]
 *   @0x261b30 mov r2, r10
 *   @0x261b34 bl 0x25c2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11d0>
 *   @0x261b38 ldr r0, [sp, #0x8c]
 *   @0x261b3c mov r1, r8
 *   @0x261b40 ldr r2, [sp, #0x68]
 *   @0x261b44 bl 0xb6694 <memmove@plt>
 *   @0x261b48 cmp r11, r4
 *   @0x261b4c mvneq r3, #94
 *   @0x261b50 strbeq r3, [r8]
 *   @0x261b54 beq 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x261b58 ldr r12, [sp, #0x50]
 *   @0x261b5c sub r3, r12, #110
 *   @0x261b60 strb r3, [r8]
 *   @0x261b64 b 0x2618ec <_pcre_ord2utf+0x1b54>
 *   @0x261b68 ldrb r3, [r0, #0x2]
 *   @0x261b6c ldr r2, [r9, #0xc]
 *   @0x261b70 cmp r3, #58
 *   @0x261b74 beq 0x261da4 <_pcre_ord2utf+0x200c>
 *   @0x261b78 ldrb r3, [r2, r3]
 *   @0x261b7c tst r3, #2
 *   @0x261b80 bne 0x261da4 <_pcre_ord2utf+0x200c>
 *   @0x261b84 ldr r12, [sp, #0x40]
 *   @0x261b88 ldr r2, [r9, #0x20]
 *   @0x261b8c ldr r3, [r9, #0x10]
 *   @0x261b90 tst r12, #4096
 *   @0x261b94 rsb r3, r3, r2
 *   @0x261b98 str r3, [sp, #0x5c]
 *   @0x261b9c beq 0x260850 <_pcre_ord2utf+0xab8>
 *   @0x261ba0 mov r5, #0
 *   @0x261ba4 ldr r0, [sp, #0x40]
 *   @0x261ba8 mov r3, r5
 *   @0x261bac mov r4, #131
 *   @0x261bb0 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x261bb4 ldrb r3, [r4, #0x1]
 *   @0x261bb8 ldr r1, [r9, #0x20]
 *   @0x261bbc ldr r2, [r9, #0x10]
 *   @0x261bc0 cmp r3, #46
 *   @0x261bc4 cmpne r3, #58
 *   @0x261bc8 rsb r2, r2, r1
 *   @0x261bcc str r2, [sp, #0x5c]
 *   @0x261bd0 beq 0x262c04 <_pcre_ord2utf+0x2e6c>
 *   @0x261bd4 cmp r3, #61
 *   @0x261bd8 beq 0x262c04 <_pcre_ord2utf+0x2e6c>
 *   @0x261bdc mov r5, r4
 *   @0x261be0 ldr r7, [pc, #-0xd38]
 *   @0x261be4 mov r12, #0
 *   @0x261be8 mov r8, r12
 *   @0x261bec str r12, [sp, #0x50]
 *   @0x261bf0 add r7, pc, r7
 *   @0x261bf4 add r2, r5, #1
 *   @0x261bf8 str r2, [sp, #0x13c]
 *   @0x261bfc ldrb r4, [r5, #0x1]
 *   @0x261c00 cmp r4, #92
 *   @0x261c04 beq 0x261c2c <_pcre_ord2utf+0x1e94>
 *   @0x261c08 eor r3, r8, #1
 *   @0x261c0c cmp r4, #94
 *   @0x261c10 movne r3, #0
 *   @0x261c14 andeq r3, r3, #1
 *   @0x261c18 cmp r3, #0
 *   @0x261c1c beq 0x261f14 <_pcre_ord2utf+0x217c>
 *   @0x261c20 mov r5, r2
 *   @0x261c24 mov r8, #1
 *   @0x261c28 b 0x261bf4 <_pcre_ord2utf+0x1e5c>
 *   @0x261c2c ldrb r3, [r5, #0x2]
 *   @0x261c30 cmp r3, #69
 *   @0x261c34 addeq r5, r5, #2
 *   @0x261c38 beq 0x261bf4 <_pcre_ord2utf+0x1e5c>
 *   @0x261c3c add r0, r5, #2
 *   @0x261c40 mov r1, r7
 *   @0x261c44 mov r2, #3
 *   @0x261c48 bl 0xb65e0 <strncmp@plt>
 *   @0x261c4c cmp r0, #0
 *   @0x261c50 bne 0x262308 <_pcre_ord2utf+0x2570>
 *   @0x261c54 add r5, r5, #4
 *   @0x261c58 b 0x261bf4 <_pcre_ord2utf+0x1e5c>
 *   @0x261c5c ldr r12, [sp, #0x3c]
 *   @0x261c60 cmp r12, #0
 *   @0x261c64 beq 0x264d28 <_pcre_ord2utf+0x4f90>
 *   @0x261c68 str r3, [sp, #0xbc]
 *   @0x261c6c mov r5, #1
 *   @0x261c70 ldr r3, [sp, #0x44]
 *   @0x261c74 str r3, [sp, #0x7c]
 *   @0x261c78 b 0x260328 <_pcre_ord2utf+0x590>
 *   @0x261c7c ldr r3, [sp, #0x13c]
 *   @0x261c80 mov r5, #0
 *   @0x261c84 add r3, r3, #1
 *   @0x261c88 b 0x261ca0 <_pcre_ord2utf+0x1f08>
 *   @0x261c8c add r5, r5, r5, lsl #2
 *   @0x261c90 mov r4, r3
 *   @0x261c94 add r5, r2, r5, lsl #1
 *   @0x261c98 cmp r5, #65536
 *   @0x261c9c bge 0x261d2c <_pcre_ord2utf+0x1f94>
 *   @0x261ca0 mov r4, r3
 *   @0x261ca4 add r3, r3, #1
 *   @0x261ca8 ldrb r1, [r4]
 *   @0x261cac sub r2, r1, #48
 *   @0x261cb0 uxtb r0, r2
 *   @0x261cb4 cmp r0, #9
 *   @0x261cb8 bls 0x261c8c <_pcre_ord2utf+0x1ef4>
 *   @0x261cbc cmp r1, #125
 *   @0x261cc0 mov r1, r4
 *   @0x261cc4 beq 0x262a18 <_pcre_ord2utf+0x2c80>
 *   @0x261cc8 ldrb r2, [r4, #0x1]
 *   @0x261ccc mov r4, r3
 *   @0x261cd0 cmp r2, #125
 *   @0x261cd4 mvneq r11, #0
 *   @0x261cd8 beq 0x262a1c <_pcre_ord2utf+0x2c84>
 *   @0x261cdc add r1, r1, #1
 *   @0x261ce0 mov r3, r2
 *   @0x261ce4 mov r11, #0
 *   @0x261ce8 b 0x261d04 <_pcre_ord2utf+0x1f6c>
 *   @0x261cec add r11, r11, r11, lsl #2
 *   @0x261cf0 add r4, r4, #1
 *   @0x261cf4 add r11, r3, r11, lsl #1
 *   @0x261cf8 cmp r11, #65536
 *   @0x261cfc bge 0x261d2c <_pcre_ord2utf+0x1f94>
 *   @0x261d00 ldrb r3, [r1, #0x1]!
 *   @0x261d04 sub r3, r3, #48
 *   @0x261d08 uxtb r2, r3
 *   @0x261d0c cmp r2, #9
 *   @0x261d10 bls 0x261cec <_pcre_ord2utf+0x1f54>
 *   @0x261d14 cmp r11, r5
 *   @0x261d18 bge 0x262a1c <_pcre_ord2utf+0x2c84>
 *   @0x261d1c ldr r12, [sp, #0x48]
 *   @0x261d20 mov r3, #4
 *   @0x261d24 str r3, [r12]
 *   @0x261d28 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x261d2c ldr r12, [sp, #0x48]
 *   @0x261d30 mov r3, #5
 *   @0x261d34 str r3, [r12]
 *   @0x261d38 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x261d3c and r2, r7, #7
 *   @0x261d40 mov r0, r3
 *   @0x261d44 add r1, sp, #348
 *   @0x261d48 add r6, r3, r2
 *   @0x261d4c bl 0xb65bc <memcpy@plt>
 *   @0x261d50 b 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x261d54 add r1, sp, #404
 *   @0x261d58 mov r8, r6
 *   @0x261d5c bl 0x25fd98 <_pcre_ord2utf>
 *   @0x261d60 ldr r1, [sp, #0x98]
 *   @0x261d64 ldr r2, [sp, #0x40]
 *   @0x261d68 eor r12, r1, #1
 *   @0x261d6c and r2, r2, #1
 *   @0x261d70 str r2, [sp, #0x58]
 *   @0x261d74 cmp r0, #1
 *   @0x261d78 orreq r12, r12, #1
 *   @0x261d7c b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x261d80 ldr r3, [r9, #0x40]
 *   @0x261d84 ldr r12, [sp, #0x68]
 *   @0x261d88 cmp r12, r3
 *   @0x261d8c mvnhs r3, #125
 *   @0x261d90 strbhs r3, [r6]
 *   @0x261d94 b 0x260978 <_pcre_ord2utf+0xbe0>
 *   @0x261d98 ldr r11, [sp, #0x13c]
 *   @0x261d9c ldr r7, [r9, #0x10]
 *   @0x261da0 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261da4 add r11, r0, #2
 *   @0x261da8 str r11, [sp, #0x13c]
 *   @0x261dac ldrb r3, [r0, #0x2]
 *   @0x261db0 ldrb r1, [r2, r3]
 *   @0x261db4 and r1, r1, #2
 *   @0x261db8 ands r1, r1, #255
 *   @0x261dbc beq 0x264bb8 <_pcre_ord2utf+0x4e20>
 *   @0x261dc0 add r0, r0, #3
 *   @0x261dc4 str r0, [sp, #0x13c]
 *   @0x261dc8 mov r1, r0
 *   @0x261dcc ldrb r3, [r0], #1
 *   @0x261dd0 ldrb r12, [r2, r3]
 *   @0x261dd4 tst r12, #2
 *   @0x261dd8 bne 0x261dc4 <_pcre_ord2utf+0x202c>
 *   @0x261ddc rsb r12, r11, r1
 *   @0x261de0 str r12, [sp, #0x68]
 *   @0x261de4 cmp r3, #58
 *   @0x261de8 movne r8, #0
 *   @0x261dec movne r7, r8
 *   @0x261df0 beq 0x2622b0 <_pcre_ord2utf+0x2518>
 *   @0x261df4 ldr r3, [sp, #0x13c]
 *   @0x261df8 str r3, [sp, #0x50]
 *   @0x261dfc ldrb r3, [r3]
 *   @0x261e00 cmp r3, #41
 *   @0x261e04 bne 0x261efc <_pcre_ord2utf+0x2164>
 *   @0x261e08 ldr r12, [pc, #-0xf5c]
 *   @0x261e0c mov r4, #0
 *   @0x261e10 str r10, [sp, #0x84]
 *   @0x261e14 add r12, pc, r12
 *   @0x261e18 str r7, [sp, #0x88]
 *   @0x261e1c add r3, r12, #516
 *   @0x261e20 mov r7, r12
 *   @0x261e24 mov r10, r3
 *   @0x261e28 mov r3, r9
 *   @0x261e2c mov r9, r8
 *   @0x261e30 mov r8, r6
 *   @0x261e34 mov r6, r4
 *   @0x261e38 b 0x261e54 <_pcre_ord2utf+0x20bc>
 *   @0x261e3c add r4, r4, #12
 *   @0x261e40 add r5, r5, #1
 *   @0x261e44 cmp r4, #108
 *   @0x261e48 add r10, r10, r5
 *   @0x261e4c add r6, r6, #1
 *   @0x261e50 beq 0x261efc <_pcre_ord2utf+0x2164>
 *   @0x261e54 add r2, r7, #860
 *   @0x261e58 ldr r12, [sp, #0x68]
 *   @0x261e5c ldr r5, [r4, r2]
 *   @0x261e60 cmp r5, r12
 *   @0x261e64 bne 0x261e3c <_pcre_ord2utf+0x20a4>
 *   @0x261e68 mov r0, r11
 *   @0x261e6c mov r1, r10
 *   @0x261e70 mov r2, r12
 *   @0x261e74 str r3, [sp, #0x38]
 *   @0x261e78 bl 0xb65e0 <strncmp@plt>
 *   @0x261e7c ldr r3, [sp, #0x38]
 *   @0x261e80 cmp r0, #0
 *   @0x261e84 bne 0x261e3c <_pcre_ord2utf+0x20a4>
 *   @0x261e88 mov r5, r6
 *   @0x261e8c mov r12, r7
 *   @0x261e90 add r5, r5, r5, lsl #1
 *   @0x261e94 mov r6, r8
 *   @0x261e98 ldr r10, [sp, #0x84]
 *   @0x261e9c mov r8, r9
 *   @0x261ea0 add r12, r12, r5, lsl #2
 *   @0x261ea4 mov r9, r3
 *   @0x261ea8 ldr r7, [sp, #0x88]
 *   @0x261eac ldr r4, [r12, #0x360]
 *   @0x261eb0 cmp r4, #158
 *   @0x261eb4 beq 0x264c4c <_pcre_ord2utf+0x4eb4>
 *   @0x261eb8 cmp r7, #0
 *   @0x261ebc bne 0x264c08 <_pcre_ord2utf+0x4e70>
 *   @0x261ec0 cmp r4, #0
 *   @0x261ec4 blt 0x264bf0 <_pcre_ord2utf+0x4e58>
 *   @0x261ec8 strb r4, [r6]
 *   @0x261ecc add r2, r6, #1
 *   @0x261ed0 uxtb r4, r4
 *   @0x261ed4 sub r4, r4, #150
 *   @0x261ed8 cmp r4, #5
 *   @0x261edc addls pc, pc, r4, lsl #2
 *   @0x261ee0 b 0x264bd0 <_pcre_ord2utf+0x4e38>
 *   @0x261ee4 b 0x264be4 <_pcre_ord2utf+0x4e4c>
 *   @0x261ee8 b 0x264be4 <_pcre_ord2utf+0x4e4c>
 *   @0x261eec b 0x264be4 <_pcre_ord2utf+0x4e4c>
 *   @0x261ef0 b 0x264be4 <_pcre_ord2utf+0x4e4c>
 *   @0x261ef4 b 0x264bc4 <_pcre_ord2utf+0x4e2c>
 *   @0x261ef8 b 0x264bc4 <_pcre_ord2utf+0x4e2c>
 *   @0x261efc ldr r12, [sp, #0x50]
 *   @0x261f00 mov r3, #60
 *   @0x261f04 mov r4, r12
 *   @0x261f08 ldr r12, [sp, #0x48]
 *   @0x261f0c str r3, [r12]
 *   @0x261f10 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x261f14 cmp r4, #93
 *   @0x261f18 str r8, [sp, #0x50]
 *   @0x261f1c bne 0x26281c <_pcre_ord2utf+0x2a84>
 *   @0x261f20 ldr r3, [r9, #0x60]
 *   @0x261f24 ands r3, r3, #33554432
 *   @0x261f28 beq 0x2626c8 <_pcre_ord2utf+0x2930>
 *   @0x261f2c cmp r8, #0
 *   @0x261f30 ldr r12, [sp, #0x4c]
 *   @0x261f34 moveq r3, #157
 *   @0x261f38 movne r3, #13
 *   @0x261f3c cmn r12, #2
 *   @0x261f40 strb r3, [r6]
 *   @0x261f44 add r3, r6, #1
 *   @0x261f48 beq 0x2657d4 <_pcre_ord2utf+0x5a3c>
 *   @0x261f4c ldr r12, [sp, #0x4c]
 *   @0x261f50 mov r8, r6
 *   @0x261f54 ldr r11, [sp, #0x13c]
 *   @0x261f58 mov r6, r3
 *   @0x261f5c ldr r7, [r9, #0x10]
 *   @0x261f60 str r12, [sp, #0x58]
 *   @0x261f64 ldr r12, [sp, #0x70]
 *   @0x261f68 str r12, [sp, #0x80]
 *   @0x261f6c b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x261f70 mov lr, #1
 *   @0x261f74 mov r0, r3
 *   @0x261f78 str lr, [sp]
 *   @0x261f7c mov r3, r11
 *   @0x261f80 bl 0x25f9fc <_pcre_is_newline>
 *   @0x261f84 ldr r3, [sp, #0x13c]
 *   @0x261f88 adds r0, r0, #0
 *   @0x261f8c movne r0, #1
 *   @0x261f90 b 0x261410 <_pcre_ord2utf+0x1678>
 *   @0x261f94 add r12, r0, #2
 *   @0x261f98 str r12, [sp, #0x13c]
 *   @0x261f9c ldrb r2, [r0, #0x2]
 *   @0x261fa0 sub r1, r2, #33
 *   @0x261fa4 cmp r1, #91
 *   @0x261fa8 addls pc, pc, r1, lsl #2
 *   @0x261fac b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fb0 b 0x265608 <_pcre_ord2utf+0x5870>
 *   @0x261fb4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fb8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fbc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fc0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fc4 b 0x2655f8 <_pcre_ord2utf+0x5860>
 *   @0x261fc8 b 0x26509c <_pcre_ord2utf+0x5304>
 *   @0x261fcc b 0x264fa8 <_pcre_ord2utf+0x5210>
 *   @0x261fd0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fd4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fd8 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261fdc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fe0 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261fe4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fe8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x261fec b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261ff0 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261ff4 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261ff8 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x261ffc b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x262000 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x262004 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x262008 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x26200c b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x262010 b 0x264fa0 <_pcre_ord2utf+0x5208>
 *   @0x262014 b 0x264f98 <_pcre_ord2utf+0x5200>
 *   @0x262018 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26201c b 0x2659e8 <_pcre_ord2utf+0x5c50>
 *   @0x262020 b 0x2659c0 <_pcre_ord2utf+0x5c28>
 *   @0x262024 b 0x265a24 <_pcre_ord2utf+0x5c8c>
 *   @0x262028 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26202c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262030 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262034 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262038 b 0x265920 <_pcre_ord2utf+0x5b88>
 *   @0x26203c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262040 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262044 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262048 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26204c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262050 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262054 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262058 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26205c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262060 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262064 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262068 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26206c b 0x263d14 <_pcre_ord2utf+0x3f7c>
 *   @0x262070 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262074 b 0x263cf8 <_pcre_ord2utf+0x3f60>
 *   @0x262078 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26207c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262080 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262084 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262088 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26208c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262090 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262094 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262098 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26209c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620a0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620a4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620a8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620ac b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620b0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620b4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620b8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620bc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620c0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620c4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620c8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620cc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620d0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620d4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620d8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620dc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620e0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620e4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620e8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620ec b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620f0 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620f4 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620f8 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2620fc b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262100 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262104 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262108 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26210c b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262110 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262114 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x262118 b 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x26211c b 0x263cd8 <_pcre_ord2utf+0x3f40>
 *   @0x262120 cmn r11, #1
 *   @0x262124 addeq r3, r12, #35
 *   @0x262128 strbeq r3, [r8]
 *   @0x26212c addeq r3, r8, #1
 *   @0x262130 beq 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x262134 cmp r11, #1
 *   @0x262138 beq 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x26213c sub r2, r11, #1
 *   @0x262140 add r1, r12, #39
 *   @0x262144 strb r2, [r6, #0x2]
 *   @0x262148 add r3, r6, #3
 *   @0x26214c asr r2, r2, #8
 *   @0x262150 strb r1, [r6]
 *   @0x262154 strb r2, [r6, #0x1]
 *   @0x262158 b 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x26215c sub r2, r6, #2
 *   @0x262160 mov r1, r2
 *   @0x262164 sub r2, r2, #1
 *   @0x262168 ldrb r0, [r1]
 *   @0x26216c and r0, r0, #192
 *   @0x262170 cmp r0, #128
 *   @0x262174 beq 0x262160 <_pcre_ord2utf+0x23c8>
 *   @0x262178 rsb r2, r1, r6
 *   @0x26217c add r0, sp, #348
 *   @0x262180 str r3, [sp, #0x38]
 *   @0x262184 orr r7, r2, #268435456
 *   @0x262188 bl 0xb65bc <memcpy@plt>
 *   @0x26218c ldr r3, [sp, #0x38]
 *   @0x262190 b 0x260f64 <_pcre_ord2utf+0x11cc>
 *   @0x262194 cmp r4, #157
 *   @0x262198 beq 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x26219c ldr r12, [sp, #0x48]
 *   @0x2621a0 mov r3, #11
 *   @0x2621a4 ldr r4, [sp, #0x13c]
 *   @0x2621a8 str r3, [r12]
 *   @0x2621ac b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x2621b0 cmp r5, #1
 *   @0x2621b4 beq 0x264664 <_pcre_ord2utf+0x48cc>
 *   @0x2621b8 ldr r12, [sp, #0x3c]
 *   @0x2621bc cmp r12, #0
 *   @0x2621c0 beq 0x264970 <_pcre_ord2utf+0x4bd8>
 *   @0x2621c4 ldr r0, [sp, #0x134]
 *   @0x2621c8 sub r1, r5, #1
 *   @0x2621cc smull r2, r3, r1, r0
 *   @0x2621d0 mul r1, r0, r1
 *   @0x2621d4 cmp r2, #-2147483648
 *   @0x2621d8 sbcs r0, r3, #0
 *   @0x2621dc bge 0x261938 <_pcre_ord2utf+0x1ba0>
 *   @0x2621e0 ldr r12, [sp, #0x3c]
 *   @0x2621e4 movw r3, #0xffeb
 *   @0x2621e8 movt r3, #0x7fff
 *   @0x2621ec ldr r2, [r12]
 *   @0x2621f0 rsb r3, r2, r3
 *   @0x2621f4 cmp r1, r3
 *   @0x2621f8 bgt 0x261938 <_pcre_ord2utf+0x1ba0>
 *   @0x2621fc ldr r0, [sp, #0x3c]
 *   @0x262200 add r2, r1, r2
 *   @0x262204 ldr r12, [sp, #0x5c]
 *   @0x262208 str r2, [r0]
 *   @0x26220c b 0x264668 <_pcre_ord2utf+0x48d0>
 *   @0x262210 ldr r12, [sp, #0x3c]
 *   @0x262214 movw r3, #0xffeb
 *   @0x262218 movt r3, #0x7fff
 *   @0x26221c ldr r2, [r12]
 *   @0x262220 rsb r3, r2, r3
 *   @0x262224 cmp r1, r3
 *   @0x262228 bgt 0x261938 <_pcre_ord2utf+0x1ba0>
 *   @0x26222c add r2, r1, r2
 *   @0x262230 str r2, [r12]
 *   @0x262234 cmp r4, #0
 *   @0x262238 movne r12, #120
 *   @0x26223c beq 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x262240 rsb r2, r4, r6
 *   @0x262244 add r2, r2, #1
 *   @0x262248 rsb r3, r2, r6
 *   @0x26224c ldrb r0, [r3, #0x1]
 *   @0x262250 ldrb r1, [r3, #0x2]
 *   @0x262254 orrs r1, r1, r0, lsl #8
 *   @0x262258 beq 0x262288 <_pcre_ord2utf+0x24f0>
 *   @0x26225c subs r4, r4, r1
 *   @0x262260 strb r12, [r6]
 *   @0x262264 ubfx r1, r2, #0x8, #0x8
 *   @0x262268 add r6, r6, #3
 *   @0x26226c strb r1, [r6, #-0x2]
 *   @0x262270 uxtb r2, r2
 *   @0x262274 strb r2, [r6, #-0x1]
 *   @0x262278 strb r1, [r3, #0x1]
 *   @0x26227c strb r2, [r3, #0x2]
 *   @0x262280 bne 0x262240 <_pcre_ord2utf+0x24a8>
 *   @0x262284 b 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x262288 mov r1, #120
 *   @0x26228c add r6, r6, #3
 *   @0x262290 strb r1, [r6, #-0x3]
 *   @0x262294 ubfx r1, r2, #0x8, #0x8
 *   @0x262298 uxtb r2, r2
 *   @0x26229c strb r1, [r6, #-0x2]
 *   @0x2622a0 strb r2, [r6, #-0x1]
 *   @0x2622a4 strb r1, [r3, #0x1]
 *   @0x2622a8 strb r2, [r3, #0x2]
 *   @0x2622ac b 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x2622b0 add r8, r1, #1
 *   @0x2622b4 str r8, [sp, #0x13c]
 *   @0x2622b8 ldrb r7, [r1, #0x1]
 *   @0x2622bc cmp r7, #41
 *   @0x2622c0 cmpne r7, #0
 *   @0x2622c4 moveq r7, #0
 *   @0x2622c8 movne r7, #1
 *   @0x2622cc beq 0x261df4 <_pcre_ord2utf+0x205c>
 *   @0x2622d0 add r3, r1, #2
 *   @0x2622d4 str r3, [sp, #0x13c]
 *   @0x2622d8 mov r4, r3
 *   @0x2622dc ldrb r2, [r3], #1
 *   @0x2622e0 cmp r2, #41
 *   @0x2622e4 cmpne r2, #0
 *   @0x2622e8 bne 0x2622d4 <_pcre_ord2utf+0x253c>
 *   @0x2622ec rsb r7, r8, r4
 *   @0x2622f0 cmp r7, #255
 *   @0x2622f4 bls 0x261df4 <_pcre_ord2utf+0x205c>
 *   @0x2622f8 ldr r12, [sp, #0x48]
 *   @0x2622fc mov r3, #75
 *   @0x262300 str r3, [r12]
 *   @0x262304 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262308 add r11, sp, #372
 *   @0x26230c mov r3, #0
 *   @0x262310 str r8, [sp, #0x50]
 *   @0x262314 add r8, r6, #4
 *   @0x262318 str r3, [sp, #0x174]
 *   @0x26231c str r8, [sp, #0x144]
 *   @0x262320 str r3, [sp, #0x178]
 *   @0x262324 str r3, [sp, #0x17c]
 *   @0x262328 str r3, [sp, #0x180]
 *   @0x26232c str r3, [sp, #0x184]
 *   @0x262330 str r3, [sp, #0x188]
 *   @0x262334 str r3, [sp, #0x18c]
 *   @0x262338 str r3, [sp, #0x190]
 *   @0x26233c ldr r12, [sp, #0x3c]
 *   @0x262340 mov r5, #0
 *   @0x262344 str r10, [sp, #0x84]
 *   @0x262348 mov r10, r8
 *   @0x26234c adds r12, r12, #0
 *   @0x262350 str r6, [sp, #0x104]
 *   @0x262354 ldr r6, [sp, #0x94]
 *   @0x262358 mov r7, r5
 *   @0x26235c movne r12, #1
 *   @0x262360 str r12, [sp, #0xf0]
 *   @0x262364 ldr r12, [pc, #0xff4]
 *   @0x262368 str r8, [sp, #0x94]
 *   @0x26236c add r12, pc, r12
 *   @0x262370 str r12, [sp, #0xf8]
 *   @0x262374 ldr r12, [pc, #0xfe8]
 *   @0x262378 ldr r8, [sp, #0x40]
 *   @0x26237c add r12, pc, r12
 *   @0x262380 str r12, [sp, #0xa8]
 *   @0x262384 ldr r12, [sp, #0x40]
 *   @0x262388 str r5, [sp, #0x74]
 *   @0x26238c and r12, r12, #1
 *   @0x262390 str r12, [sp, #0x58]
 *   @0x262394 ldr r12, [sp, #0x40]
 *   @0x262398 str r5, [sp, #0x68]
 *   @0x26239c and r12, r12, #64
 *   @0x2623a0 str r12, [sp, #0x110]
 *   @0x2623a4 add r12, sp, #324
 *   @0x2623a8 str r12, [sp, #0x78]
 *   @0x2623ac ldr r12, [sp, #0xf0]
 *   @0x2623b0 str r12, [sp, #0x124]
 *   @0x2623b4 ldr r3, [sp, #0x84]
 *   @0x2623b8 cmp r4, #191
 *   @0x2623bc movls r3, #0
 *   @0x2623c0 andhi r3, r3, #1
 *   @0x2623c4 cmp r3, #0
 *   @0x2623c8 beq 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x2623cc ldr r3, [sp, #0x13c]
 *   @0x2623d0 ldrb r4, [r3]
 *   @0x2623d4 cmp r4, #191
 *   @0x2623d8 bls 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x2623dc tst r4, #32
 *   @0x2623e0 bne 0x262614 <_pcre_ord2utf+0x287c>
 *   @0x2623e4 ldrb r2, [r3, #0x1]!
 *   @0x2623e8 and r4, r4, #31
 *   @0x2623ec and r2, r2, #63
 *   @0x2623f0 orr r4, r2, r4, lsl #6
 *   @0x2623f4 str r3, [sp, #0x13c]
 *   @0x2623f8 ldr r12, [sp, #0x94]
 *   @0x2623fc cmp r12, r10
 *   @0x262400 bhs 0x262440 <_pcre_ord2utf+0x26a8>
 *   @0x262404 ldr r12, [sp, #0x124]
 *   @0x262408 cmp r12, #0
 *   @0x26240c moveq r12, #1
 *   @0x262410 streq r12, [sp, #0x68]
 *   @0x262414 beq 0x262440 <_pcre_ord2utf+0x26a8>
 *   @0x262418 ldr r12, [sp, #0x3c]
 *   @0x26241c ldr r3, [r12]
 *   @0x262420 ldr r12, [sp, #0x94]
 *   @0x262424 rsb r10, r12, r10
 *   @0x262428 str r12, [sp, #0x144]
 *   @0x26242c mov r12, #1
 *   @0x262430 str r12, [sp, #0x68]
 *   @0x262434 add r3, r3, r10
 *   @0x262438 ldr r12, [sp, #0x3c]
 *   @0x26243c str r3, [r12]
 *   @0x262440 cmp r6, #0
 *   @0x262444 beq 0x262574 <_pcre_ord2utf+0x27dc>
 *   @0x262448 cmp r4, #92
 *   @0x26244c beq 0x262648 <_pcre_ord2utf+0x28b0>
 *   @0x262450 ldr r1, [sp, #0x13c]
 *   @0x262454 cmp r4, #13
 *   @0x262458 cmpne r4, #10
 *   @0x26245c movne r0, #0
 *   @0x262460 moveq r0, #1
 *   @0x262464 ldrb r2, [r1, #0x1]
 *   @0x262468 cmp r2, #92
 *   @0x26246c bne 0x2624ac <_pcre_ord2utf+0x2714>
 *   @0x262470 ldrb r3, [r1, #0x2]
 *   @0x262474 cmp r3, #69
 *   @0x262478 bne 0x2624ac <_pcre_ord2utf+0x2714>
 *   @0x26247c add r3, r1, #2
 *   @0x262480 b 0x262490 <_pcre_ord2utf+0x26f8>
 *   @0x262484 ldrb r2, [r3, #0x2]!
 *   @0x262488 cmp r2, #69
 *   @0x26248c bne 0x2625e4 <_pcre_ord2utf+0x284c>
 *   @0x262490 str r3, [sp, #0x13c]
 *   @0x262494 mov r1, r3
 *   @0x262498 ldrb r2, [r3, #0x1]
 *   @0x26249c cmp r2, #92
 *   @0x2624a0 beq 0x262484 <_pcre_ord2utf+0x26ec>
 *   @0x2624a4 mov r1, r3
 *   @0x2624a8 mov r6, #0
 *   @0x2624ac cmp r0, #0
 *   @0x2624b0 ldrne r3, [r9, #0x64]
 *   @0x2624b4 orrne r3, r3, #2048
 *   @0x2624b8 strne r3, [r9, #0x64]
 *   @0x2624bc cmp r6, #0
 *   @0x2624c0 bne 0x2625dc <_pcre_ord2utf+0x2844>
 *   @0x2624c4 ldrb r3, [r1, #0x1]
 *   @0x2624c8 cmp r3, #45
 *   @0x2624cc movne r3, #1
 *   @0x2624d0 beq 0x262668 <_pcre_ord2utf+0x28d0>
 *   @0x2624d4 cmp r5, #1
 *   @0x2624d8 addle r5, r5, #1
 *   @0x2624dc cmp r5, #1
 *   @0x2624e0 movne r12, #0
 *   @0x2624e4 andeq r12, r3, #1
 *   @0x2624e8 cmp r12, #0
 *   @0x2624ec beq 0x262500 <_pcre_ord2utf+0x2768>
 *   @0x2624f0 ldr r3, [sp, #0x13c]
 *   @0x2624f4 ldrb r2, [r3, #0x1]
 *   @0x2624f8 cmp r2, #93
 *   @0x2624fc beq 0x264344 <_pcre_ord2utf+0x45ac>
 *   @0x262500 add r3, r9, #4
 *   @0x262504 str r4, [sp]
 *   @0x262508 mov r0, r11
 *   @0x26250c str r4, [sp, #0x4]
 *   @0x262510 add r1, sp, #324
 *   @0x262514 mov r2, r8
 *   @0x262518 bl 0x25fe2c <_pcre_ord2utf+0x94>
 *   @0x26251c ldr r3, [sp, #0x13c]
 *   @0x262520 add r7, r7, r0
 *   @0x262524 add r2, r3, #1
 *   @0x262528 str r2, [sp, #0x13c]
 *   @0x26252c ldrb r4, [r3, #0x1]
 *   @0x262530 cmp r4, #0
 *   @0x262534 bne 0x262560 <_pcre_ord2utf+0x27c8>
 *   @0x262538 ldr r12, [sp, #0x44]
 *   @0x26253c cmp r12, #0
 *   @0x262540 beq 0x262850 <_pcre_ord2utf+0x2ab8>
 *   @0x262544 add r2, r12, #1
 *   @0x262548 str r2, [sp, #0x13c]
 *   @0x26254c ldrb r4, [r12, #0x1]
 *   @0x262550 cmp r4, #0
 *   @0x262554 beq 0x262850 <_pcre_ord2utf+0x2ab8>
 *   @0x262558 mov r12, #0
 *   @0x26255c str r12, [sp, #0x44]
 *   @0x262560 cmp r6, #0
 *   @0x262564 cmpeq r4, #93
 *   @0x262568 beq 0x263b1c <_pcre_ord2utf+0x3d84>
 *   @0x26256c ldr r10, [sp, #0x144]
 *   @0x262570 b 0x2623b4 <_pcre_ord2utf+0x261c>
 *   @0x262574 cmp r4, #91
 *   @0x262578 beq 0x2625ec <_pcre_ord2utf+0x2854>
 *   @0x26257c cmp r4, #92
 *   @0x262580 bne 0x262450 <_pcre_ord2utf+0x26b8>
 *   @0x262584 ldr r3, [r9, #0x40]
 *   @0x262588 mov lr, #1
 *   @0x26258c add r0, sp, #316
 *   @0x262590 str r8, [sp]
 *   @0x262594 add r1, sp, #336
 *   @0x262598 str lr, [sp, #0x4]
 *   @0x26259c ldr r2, [sp, #0x48]
 *   @0x2625a0 bl 0x25ceac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d84>
 *   @0x2625a4 ldr r12, [sp, #0x48]
 *   @0x2625a8 ldr r3, [r12]
 *   @0x2625ac cmp r3, #0
 *   @0x2625b0 bne 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x2625b4 cmp r0, #0
 *   @0x2625b8 bne 0x2633c4 <_pcre_ord2utf+0x362c>
 *   @0x2625bc ldr r4, [sp, #0x150]
 *   @0x2625c0 ldr r1, [sp, #0x13c]
 *   @0x2625c4 cmp r4, #13
 *   @0x2625c8 cmpne r4, #10
 *   @0x2625cc ldrb r2, [r1, #0x1]
 *   @0x2625d0 movne r0, #0
 *   @0x2625d4 moveq r0, #1
 *   @0x2625d8 b 0x262468 <_pcre_ord2utf+0x26d0>
 *   @0x2625dc mov r3, #0
 *   @0x2625e0 b 0x2624d4 <_pcre_ord2utf+0x273c>
 *   @0x2625e4 mov r6, #0
 *   @0x2625e8 b 0x2624ac <_pcre_ord2utf+0x2714>
 *   @0x2625ec ldr r0, [sp, #0x13c]
 *   @0x2625f0 ldrb r2, [r0, #0x1]
 *   @0x2625f4 cmp r2, #46
 *   @0x2625f8 cmpne r2, #58
 *   @0x2625fc beq 0x262800 <_pcre_ord2utf+0x2a68>
 *   @0x262600 cmp r2, #61
 *   @0x262604 movne r1, r0
 *   @0x262608 beq 0x262800 <_pcre_ord2utf+0x2a68>
 *   @0x26260c mov r0, #0
 *   @0x262610 b 0x262468 <_pcre_ord2utf+0x26d0>
 *   @0x262614 tst r4, #16
 *   @0x262618 bne 0x262864 <_pcre_ord2utf+0x2acc>
 *   @0x26261c ldrb r1, [r3, #0x2]
 *   @0x262620 lsl r4, r4, #12
 *   @0x262624 ldrb r2, [r3, #0x1]
 *   @0x262628 add r3, r3, #2
 *   @0x26262c uxth r0, r4
 *   @0x262630 and r1, r1, #63
 *   @0x262634 and r2, r2, #63
 *   @0x262638 orr r1, r0, r1
 *   @0x26263c str r3, [sp, #0x13c]
 *   @0x262640 orr r4, r1, r2, lsl #6
 *   @0x262644 b 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x262648 ldr r3, [sp, #0x13c]
 *   @0x26264c ldrb r2, [r3, #0x1]
 *   @0x262650 cmp r2, #69
 *   @0x262654 addeq r3, r3, #1
 *   @0x262658 moveq r6, #0
 *   @0x26265c beq 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x262660 mov r1, r3
 *   @0x262664 b 0x26260c <_pcre_ord2utf+0x2874>
 *   @0x262668 add r3, r1, #2
 *   @0x26266c str r3, [sp, #0x13c]
 *   @0x262670 ldrb r2, [r1, #0x2]
 *   @0x262674 cmp r2, #92
 *   @0x262678 bne 0x2626b4 <_pcre_ord2utf+0x291c>
 *   @0x26267c ldrb r2, [r1, #0x3]
 *
 * ══ §3/8 anon_262680  0x262680..0x2636d4  size 4180  1045 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_25fe2c
 * @func 0x262680 0x2636e4  size 4196  1049 条
 * ⚠ 父块 anon_25fe2c 是 26,424 B 的未闭合大状态机（METHOD §4）：段长不一定等于函数长，本段可能只是其中的一段
 * 入度 61｜调用者: 0x260448(anon_25fe2c+0x61c), 0x260498(anon_25fe2c+0x66c), 0x2636f8(anon_25fe2c+0x38cc), 0x263720(anon_25fe2c+0x38f4), 0x263750(anon_25fe2c+0x3924), 0x263780(anon_25fe2c+0x3954), 0x2637c8(anon_25fe2c+0x399c), 0x2637ec(anon_25fe2c+0x39c0)…
 * 出调用 21 处 → anon_25b524+0xd48×3, 0xb65e0×2, anon_25fe2c×1, anon_25fe2c+0x4438×1, anon_25fe2c+0x4414×1, anon_25fe2c+0x17bc×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x262680 cmp r2, #69
 *   @0x262684 bne 0x2626fc <_pcre_ord2utf+0x2964>
 *   @0x262688 add r3, r1, #4
 *   @0x26268c b 0x2626a0 <_pcre_ord2utf+0x2908>
 *   @0x262690 add r3, r3, #2
 *   @0x262694 ldrb r2, [r3, #-0x1]
 *   @0x262698 cmp r2, #69
 *   @0x26269c bne 0x2626f8 <_pcre_ord2utf+0x2960>
 *   @0x2626a0 str r3, [sp, #0x13c]
 *   @0x2626a4 mov r0, r3
 *   @0x2626a8 ldrb r2, [r3]
 *   @0x2626ac cmp r2, #92
 *   @0x2626b0 beq 0x262690 <_pcre_ord2utf+0x28f8>
 *   @0x2626b4 cmp r2, #0
 *   @0x2626b8 bne 0x26364c <_pcre_ord2utf+0x38b4>
 *   @0x2626bc mov r3, #1
 *   @0x2626c0 str r1, [sp, #0x13c]
 *   @0x2626c4 b 0x2624d4 <_pcre_ord2utf+0x273c>
 *   @0x2626c8 add r8, r6, #4
 *   @0x2626cc str r3, [sp, #0x174]
 *   @0x2626d0 str r3, [sp, #0x178]
 *   @0x2626d4 add r11, sp, #372
 *   @0x2626d8 str r3, [sp, #0x17c]
 *   @0x2626dc str r3, [sp, #0x180]
 *   @0x2626e0 str r3, [sp, #0x184]
 *   @0x2626e4 str r3, [sp, #0x188]
 *   @0x2626e8 str r3, [sp, #0x18c]
 *   @0x2626ec str r3, [sp, #0x190]
 *   @0x2626f0 str r8, [sp, #0x144]
 *   @0x2626f4 b 0x26233c <_pcre_ord2utf+0x25a4>
 *   @0x2626f8 mov r3, r0
 *   @0x2626fc cmp r2, #81
 *   @0x262700 ldrbne r2, [r3]
 *   @0x262704 bne 0x262730 <_pcre_ord2utf+0x2998>
 *   @0x262708 add r0, r3, #2
 *   @0x26270c str r0, [sp, #0x13c]
 *   @0x262710 ldrb r2, [r3, #0x2]
 *   @0x262714 cmp r2, #92
 *   @0x262718 bne 0x264500 <_pcre_ord2utf+0x4768>
 *   @0x26271c ldrb r12, [r3, #0x3]
 *   @0x262720 cmp r12, #69
 *   @0x262724 beq 0x2644ac <_pcre_ord2utf+0x4714>
 *   @0x262728 mov r3, r0
 *   @0x26272c mov r6, #1
 *   @0x262730 ldr r12, [sp, #0x84]
 *   @0x262734 cmp r12, #0
 *   @0x262738 streq r2, [sp, #0x158]
 *   @0x26273c beq 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x262740 cmp r2, #191
 *   @0x262744 str r2, [sp, #0x158]
 *   @0x262748 bls 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x26274c tst r2, #32
 *   @0x262750 bne 0x264474 <_pcre_ord2utf+0x46dc>
 *   @0x262754 ldrb r1, [r3, #0x1]!
 *   @0x262758 and r2, r2, #31
 *   @0x26275c and r1, r1, #63
 *   @0x262760 orr r2, r1, r2, lsl #6
 *   @0x262764 str r3, [sp, #0x13c]
 *   @0x262768 str r2, [sp, #0x158]
 *   @0x26276c cmp r6, #0
 *   @0x262770 bne 0x2627b4 <_pcre_ord2utf+0x2a1c>
 *   @0x262774 cmp r2, #92
 *   @0x262778 beq 0x26441c <_pcre_ord2utf+0x4684>
 *   @0x26277c cmp r2, #91
 *   @0x262780 bne 0x2627b4 <_pcre_ord2utf+0x2a1c>
 *   @0x262784 ldr r0, [sp, #0x13c]
 *   @0x262788 ldrb r3, [r0, #0x1]
 *   @0x26278c cmp r3, #46
 *   @0x262790 cmpne r3, #58
 *   @0x262794 beq 0x2627a0 <_pcre_ord2utf+0x2a08>
 *   @0x262798 cmp r3, #61
 *   @0x26279c bne 0x2627b4 <_pcre_ord2utf+0x2a1c>
 *   @0x2627a0 add r1, sp, #320
 *   @0x2627a4 bl 0x25c26c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1144>
 *   @0x2627a8 cmp r0, #0
 *   @0x2627ac bne 0x264464 <_pcre_ord2utf+0x46cc>
 *   @0x2627b0 ldr r2, [sp, #0x158]
 *   @0x2627b4 cmp r4, r2
 *   @0x2627b8 bhi 0x26422c <_pcre_ord2utf+0x4494>
 *   @0x2627bc beq 0x264220 <_pcre_ord2utf+0x4488>
 *   @0x2627c0 cmp r2, #13
 *   @0x2627c4 cmpne r2, #10
 *   @0x2627c8 mov r0, r11
 *   @0x2627cc add r1, sp, #324
 *   @0x2627d0 mov r5, #2
 *   @0x2627d4 ldreq r3, [r9, #0x64]
 *   @0x2627d8 orreq r3, r3, #2048
 *   @0x2627dc streq r3, [r9, #0x64]
 *   @0x2627e0 add r3, r9, #4
 *   @0x2627e4 str r2, [sp, #0x4]
 *   @0x2627e8 mov r2, r8
 *   @0x2627ec str r4, [sp]
 *   @0x2627f0 bl 0x25fe2c <_pcre_ord2utf+0x94>
 *   @0x2627f4 ldr r3, [sp, #0x13c]
 *   @0x2627f8 add r7, r7, r0
 *   @0x2627fc b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x262800 add r1, sp, #320
 *   @0x262804 bl 0x25c26c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1144>
 *   @0x262808 cmp r0, #0
 *   @0x26280c bne 0x2628a0 <_pcre_ord2utf+0x2b08>
 *   @0x262810 ldr r1, [sp, #0x13c]
 *   @0x262814 ldrb r2, [r1, #0x1]
 *   @0x262818 b 0x26260c <_pcre_ord2utf+0x2874>
 *   @0x26281c cmp r4, #0
 *   @0x262820 add r8, r6, #4
 *   @0x262824 str r3, [sp, #0x174]
 *   @0x262828 add r11, sp, #372
 *   @0x26282c str r3, [sp, #0x178]
 *   @0x262830 str r3, [sp, #0x17c]
 *   @0x262834 str r3, [sp, #0x180]
 *   @0x262838 str r3, [sp, #0x184]
 *   @0x26283c str r3, [sp, #0x188]
 *   @0x262840 str r3, [sp, #0x18c]
 *   @0x262844 str r3, [sp, #0x190]
 *   @0x262848 str r8, [sp, #0x144]
 *   @0x26284c bne 0x26233c <_pcre_ord2utf+0x25a4>
 *   @0x262850 ldr r12, [sp, #0x48]
 *   @0x262854 mov r3, #6
 *   @0x262858 mov r4, r2
 *   @0x26285c str r3, [r12]
 *   @0x262860 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262864 tst r4, #8
 *   @0x262868 bne 0x263604 <_pcre_ord2utf+0x386c>
 *   @0x26286c ldrb r0, [r3, #0x3]
 *   @0x262870 and r4, r4, #7
 *   @0x262874 ldrb r2, [r3, #0x1]
 *   @0x262878 add r3, r3, #3
 *   @0x26287c ldrb r1, [r3, #-0x1]
 *   @0x262880 and r0, r0, #63
 *   @0x262884 and r2, r2, #63
 *   @0x262888 orr r0, r0, r4, lsl #18
 *   @0x26288c and r1, r1, #63
 *   @0x262890 str r3, [sp, #0x13c]
 *   @0x262894 orr r2, r0, r2, lsl #12
 *   @0x262898 orr r4, r2, r1, lsl #6
 *   @0x26289c b 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x2628a0 ldr r3, [sp, #0x13c]
 *   @0x2628a4 ldr r12, [r9, #0x8]
 *   @0x2628a8 ldrb r2, [r3, #0x1]
 *   @0x2628ac str r12, [sp, #0x88]
 *   @0x2628b0 cmp r2, #58
 *   @0x2628b4 bne 0x264408 <_pcre_ord2utf+0x4670>
 *   @0x2628b8 add r7, r3, #2
 *   @0x2628bc str r7, [sp, #0x13c]
 *   @0x2628c0 ldrb r2, [r3, #0x2]
 *   @0x2628c4 cmp r2, #94
 *   @0x2628c8 movne r12, #0
 *   @0x2628cc strne r12, [sp, #0x8c]
 *   @0x2628d0 beq 0x264328 <_pcre_ord2utf+0x4590>
 *   @0x2628d4 ldr r12, [sp, #0x140]
 *   @0x2628d8 mov r4, #0
 *   @0x2628dc str r9, [sp, #0x12c]
 *   @0x2628e0 mov r5, #5
 *   @0x2628e4 mov r9, r6
 *   @0x2628e8 mov r6, r4
 *   @0x2628ec str r12, [sp, #0xc0]
 *   @0x2628f0 ldr r0, [sp, #0xc0]
 *   @0x2628f4 ldr r12, [sp, #0xf8]
 *   @0x2628f8 add r3, r12, #968
 *   @0x2628fc add r10, r12, #432
 *   @0x262900 rsb r12, r7, r0
 *   @0x262904 mov r4, r3
 *   @0x262908 mov r3, r11
 *   @0x26290c mov r11, r8
 *   @0x262910 mov r8, r7
 *   @0x262914 mov r7, r12
 *   @0x262918 b 0x262934 <_pcre_ord2utf+0x2b9c>
 *   @0x26291c add r2, r5, #1
 *   @0x262920 ldrb r5, [r4, #0x1]!
 *   @0x262924 add r10, r10, r2
 *   @0x262928 add r6, r6, #1
 *   @0x26292c cmp r5, #0
 *   @0x262930 beq 0x264310 <_pcre_ord2utf+0x4578>
 *   @0x262934 cmp r7, r5
 *   @0x262938 bne 0x26291c <_pcre_ord2utf+0x2b84>
 *   @0x26293c mov r0, r8
 *   @0x262940 mov r1, r10
 *   @0x262944 mov r2, r7
 *   @0x262948 str r3, [sp, #0x38]
 *   @0x26294c bl 0xb65e0 <strncmp@plt>
 *   @0x262950 ldr r3, [sp, #0x38]
 *   @0x262954 cmp r0, #0
 *   @0x262958 bne 0x26291c <_pcre_ord2utf+0x2b84>
 *   @0x26295c ldr r12, [sp, #0x58]
 *   @0x262960 mov r4, r6
 *   @0x262964 mov r8, r11
 *   @0x262968 mov r6, r9
 *   @0x26296c cmp r12, #0
 *   @0x262970 ldr r9, [sp, #0x12c]
 *   @0x262974 mov r11, r3
 *   @0x262978 bne 0x2642fc <_pcre_ord2utf+0x4564>
 *   @0x26297c add r0, r4, r4, lsl #1
 *   @0x262980 add r2, r0, #1
 *   @0x262984 add r3, r0, #2
 *   @0x262988 ldr r12, [sp, #0xa8]
 *   @0x26298c add r5, sp, #404
 *   @0x262990 add r0, r12, r0, lsl #2
 *   @0x262994 add r2, r12, r2, lsl #2
 *   @0x262998 add r3, r12, r3, lsl #2
 *   @0x26299c mov r12, r5
 *   @0x2629a0 ldr r4, [r0, #0x230]
 *   @0x2629a4 ldr r0, [sp, #0x88]
 *   @0x2629a8 ldr r10, [r2, #0x230]
 *   @0x2629ac add r4, r0, r4
 *   @0x2629b0 ldr r7, [r3, #0x230]
 *   @0x2629b4 cmp r10, #0
 *   @0x2629b8 ldr r0, [r4]
 *   @0x2629bc ldr r1, [r4, #0x4]
 *   @0x2629c0 ldr r2, [r4, #0x8]
 *   @0x2629c4 ldr r3, [r4, #0xc]
 *   @0x2629c8 stm r12!, {r0, r1, r2, r3}
 *   @0x2629cc ldr r0, [r4, #0x10]
 *   @0x2629d0 ldr r1, [r4, #0x14]
 *   @0x2629d4 ldr r2, [r4, #0x18]
 *   @0x2629d8 ldr r3, [r4, #0x1c]
 *   @0x2629dc stm r12!, {r0, r1, r2, r3}
 *   @0x2629e0 blt 0x264264 <_pcre_ord2utf+0x44cc>
 *   @0x2629e4 ldr r12, [sp, #0x88]
 *   @0x2629e8 cmp r7, #0
 *   @0x2629ec mov r3, #0
 *   @0x2629f0 add r10, r12, r10
 *   @0x2629f4 blt 0x264240 <_pcre_ord2utf+0x44a8>
 *   @0x2629f8 ldrb r1, [r10, r3]
 *   @0x2629fc ldrb r2, [r5, r3]
 *   @0x262a00 orr r2, r1, r2
 *   @0x262a04 strb r2, [r5, r3]
 *   @0x262a08 add r3, r3, #1
 *   @0x262a0c cmp r3, #32
 *   @0x262a10 bne 0x2629f8 <_pcre_ord2utf+0x2c60>
 *   @0x262a14 b 0x26426c <_pcre_ord2utf+0x44d4>
 *   @0x262a18 mov r11, r5
 *   @0x262a1c ldr r12, [sp, #0x48]
 *   @0x262a20 str r4, [sp, #0x13c]
 *   @0x262a24 ldr r3, [r12]
 *   @0x262a28 cmp r3, #0
 *   @0x262a2c bne 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262a30 cmp r8, #0
 *   @0x262a34 beq 0x262bf4 <_pcre_ord2utf+0x2e5c>
 *   @0x262a38 ldr r0, [sp, #0x64]
 *   @0x262a3c cmp r5, #0
 *   @0x262a40 ldr r12, [sp, #0x78]
 *   @0x262a44 movne r12, r0
 *   @0x262a48 ldr r0, [sp, #0x4c]
 *   @0x262a4c str r12, [sp, #0x64]
 *   @0x262a50 ldr r12, [sp, #0x58]
 *   @0x262a54 movne r12, r0
 *   @0x262a58 ldr r0, [sp, #0x6c]
 *   @0x262a5c str r12, [sp, #0x4c]
 *   @0x262a60 ldr r12, [sp, #0x74]
 *   @0x262a64 movne r12, r0
 *   @0x262a68 ldr r0, [sp, #0x70]
 *   @0x262a6c str r12, [sp, #0x6c]
 *   @0x262a70 ldr r12, [sp, #0x80]
 *   @0x262a74 movne r12, r0
 *   @0x262a78 str r12, [sp, #0x70]
 *   @0x262a7c b 0x260730 <_pcre_ord2utf+0x998>
 *   @0x262a80 ldr r7, [r9, #0x10]
 *   @0x262a84 ldr r3, [r9, #0x20]
 *   @0x262a88 add r7, r7, #2
 *   @0x262a8c cmp r3, r7
 *   @0x262a90 blo 0x2615e8 <_pcre_ord2utf+0x1850>
 *   @0x262a94 ldrb r0, [r3, #-0x2]
 *   @0x262a98 add r2, r8, #1
 *   @0x262a9c ldrb r1, [r3, #-0x1]
 *   @0x262aa0 ldr r12, [r9, #0x14]
 *   @0x262aa4 orr r1, r1, r0, lsl #8
 *   @0x262aa8 rsb r12, r12, r2
 *   @0x262aac cmp r1, r12
 *   @0x262ab0 addeq r2, r1, #3
 *   @0x262ab4 asreq r1, r2, #8
 *   @0x262ab8 strbeq r1, [r3, #-0x2]
 *   @0x262abc ldreq r3, [r9, #0x20]
 *   @0x262ac0 strbeq r2, [r3, #-0x1]
 *   @0x262ac4 b 0x2615e8 <_pcre_ord2utf+0x1850>
 *   @0x262ac8 cmp r5, #1
 *   @0x262acc bne 0x2641f4 <_pcre_ord2utf+0x445c>
 *   @0x262ad0 cmn r11, #1
 *   @0x262ad4 ldr r12, [sp, #0x50]
 *   @0x262ad8 addeq r3, r12, #100
 *   @0x262adc strbeq r3, [r6]
 *   @0x262ae0 addeq r6, r6, #1
 *   @0x262ae4 beq 0x260ff4 <_pcre_ord2utf+0x125c>
 *   @0x262ae8 add r3, r12, #104
 *   @0x262aec strb r5, [r6, #0x2]
 *   @0x262af0 strb r3, [r6]
 *   @0x262af4 mov r3, #0
 *   @0x262af8 strb r3, [r6, #0x1]
 *   @0x262afc b 0x2616c0 <_pcre_ord2utf+0x1928>
 *   @0x262b00 ldr r12, [sp, #0x40]
 *   @0x262b04 mov r3, #0
 *   @0x262b08 mov r2, r3
 *   @0x262b0c strb r3, [r10]
 *   @0x262b10 ldr r0, [sp, #0xb4]
 *   @0x262b14 ubfx r1, r12, #0xb, #0x1
 *   @0x262b18 str r3, [sp]
 *   @0x262b1c mov r3, r9
 *   @0x262b20 bl 0x25b5c4 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x49c>
 *   @0x262b24 cmn r0, #3
 *   @0x262b28 moveq r3, #1
 *   @0x262b2c streq r3, [r9, #0x74]
 *   @0x262b30 beq 0x261a68 <_pcre_ord2utf+0x1cd0>
 *   @0x262b34 cmp r0, #0
 *   @0x262b38 blt 0x2641c4 <_pcre_ord2utf+0x442c>
 *   @0x262b3c ldr r12, [sp, #0xd8]
 *   @0x262b40 ldr r3, [r9, #0x48]
 *   @0x262b44 cmp r0, r3
 *   @0x262b48 strgt r0, [r9, #0x48]
 *   @0x262b4c strb r0, [r12, #0x1]
 *   @0x262b50 asr r0, r0, #8
 *   @0x262b54 strb r0, [r12]
 *   @0x262b58 b 0x261a68 <_pcre_ord2utf+0x1cd0>
 *   @0x262b5c ldr r12, [sp, #0xb8]
 *   @0x262b60 cmp r12, #0
 *   @0x262b64 blt 0x262b88 <_pcre_ord2utf+0x2df0>
 *   @0x262b68 ldr r0, [sp, #0x4c]
 *   @0x262b6c cmp r12, r0
 *   @0x262b70 beq 0x2641b0 <_pcre_ord2utf+0x4418>
 *   @0x262b74 ldr r12, [sp, #0xac]
 *   @0x262b78 cmp r12, #0
 *   @0x262b7c blt 0x26419c <_pcre_ord2utf+0x4404>
 *   @0x262b80 mvn r12, #0
 *   @0x262b84 str r12, [sp, #0xb8]
 *   @0x262b88 ldr r12, [sp, #0x4c]
 *   @0x262b8c cmp r12, #0
 *   @0x262b90 blt 0x262bb4 <_pcre_ord2utf+0x2e1c>
 *   @0x262b94 ldr r12, [sp, #0x64]
 *   @0x262b98 ldr r8, [sp, #0x6c]
 *   @0x262b9c cmp r12, #0
 *   @0x262ba0 mov r5, r12
 *   @0x262ba4 ldr r12, [sp, #0x4c]
 *   @0x262ba8 movlt r5, r12
 *   @0x262bac ldr r12, [sp, #0x70]
 *   @0x262bb0 movlt r8, r12
 *   @0x262bb4 ldr r12, [sp, #0xac]
 *   @0x262bb8 eor r3, r5, r12
 *   @0x262bbc bics r0, r3, #2
 *   @0x262bc0 bne 0x262bd0 <_pcre_ord2utf+0x2e38>
 *   @0x262bc4 ldr r12, [sp, #0xa4]
 *   @0x262bc8 cmp r12, r8
 *   @0x262bcc beq 0x264190 <_pcre_ord2utf+0x43f8>
 *   @0x262bd0 ldr r8, [sp, #0xa4]
 *   @0x262bd4 mvn r5, #0
 *   @0x262bd8 b 0x261a5c <_pcre_ord2utf+0x1cc4>
 *   @0x262bdc ldr r12, [sp, #0x48]
 *   @0x262be0 mov r3, #85
 *   @0x262be4 mov r0, #0
 *   @0x262be8 str r3, [r12]
 *   @0x262bec b 0x260df0 <_pcre_ord2utf+0x1058>
 *   @0x262bf0 ldr r4, [sp, #0x13c]
 *   @0x262bf4 ldr r12, [sp, #0x48]
 *   @0x262bf8 mov r3, #9
 *   @0x262bfc str r3, [r12]
 *   @0x262c00 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262c04 mov r0, r4
 *   @0x262c08 add r1, sp, #320
 *   @0x262c0c bl 0x25c26c <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1144>
 *   @0x262c10 cmp r0, #0
 *   @0x262c14 bne 0x264170 <_pcre_ord2utf+0x43d8>
 *   @0x262c18 ldr r5, [sp, #0x13c]
 *   @0x262c1c b 0x261be0 <_pcre_ord2utf+0x1e48>
 *   @0x262c20 cmp r10, #0
 *   @0x262c24 beq 0x262c30 <_pcre_ord2utf+0x2e98>
 *   @0x262c28 tst r7, #268435456
 *   @0x262c2c bne 0x26414c <_pcre_ord2utf+0x43b4>
 *   @0x262c30 ldr r3, [sp, #0x68]
 *   @0x262c34 strb r7, [r8, #0x3]
 *   @0x262c38 cmn r3, #1
 *   @0x262c3c addeq r3, r8, #4
 *   @0x262c40 addne r3, r8, #6
 *   @0x262c44 ldrne r0, [sp, #0x68]
 *   @0x262c48 ldrne r1, [sp, #0x8c]
 *   @0x262c4c strbne r0, [r8, #0x4]
 *   @0x262c50 strbne r1, [r8, #0x5]
 *   @0x262c54 add r2, r12, #33
 *   @0x262c58 add r3, r3, #1
 *   @0x262c5c strb r2, [r3, #-0x1]
 *   @0x262c60 b 0x260fdc <_pcre_ord2utf+0x1244>
 *   @0x262c64 cmp r4, #145
 *   @0x262c68 ldr r6, [sp, #0x138]
 *   @0x262c6c beq 0x2640d8 <_pcre_ord2utf+0x4340>
 *   @0x262c70 cmp r4, #128
 *   @0x262c74 ble 0x263440 <_pcre_ord2utf+0x36a8>
 *   @0x262c78 ldr r12, [sp, #0x4c]
 *   @0x262c7c cmn r12, #2
 *   @0x262c80 beq 0x264080 <_pcre_ord2utf+0x42e8>
 *   @0x262c84 ldr r1, [sp, #0x158]
 *   @0x262c88 ldr r2, [sp, #0x154]
 *   @0x262c8c cmp r1, #0
 *   @0x262c90 blt 0x264134 <_pcre_ord2utf+0x439c>
 *   @0x262c94 cmp r2, #0
 *   @0x262c98 blt 0x264104 <_pcre_ord2utf+0x436c>
 *   @0x262c9c ldr r12, [sp, #0x4c]
 *   @0x262ca0 ldr r1, [sp, #0x70]
 *   @0x262ca4 str r12, [sp, #0x58]
 *   @0x262ca8 ldr r12, [sp, #0x3c]
 *   @0x262cac str r12, [sp, #0x9c]
 *   @0x262cb0 ldr r12, [sp, #0x64]
 *   @0x262cb4 mov r11, r3
 *   @0x262cb8 str r2, [sp, #0x64]
 *   @0x262cbc ldr r7, [r9, #0x10]
 *   @0x262cc0 str r12, [sp, #0x78]
 *   @0x262cc4 ldr r12, [sp, #0x70]
 *   @0x262cc8 str r1, [sp, #0x70]
 *   @0x262ccc str r12, [sp, #0x80]
 *   @0x262cd0 ldr r12, [sp, #0x6c]
 *   @0x262cd4 str r12, [sp, #0x74]
 *   @0x262cd8 ldr r12, [sp, #0x148]
 *   @0x262cdc str r12, [sp, #0x6c]
 *   @0x262ce0 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x262ce4 cmp r2, #1
 *   @0x262ce8 beq 0x2609ec <_pcre_ord2utf+0xc54>
 *   @0x262cec ldr r12, [sp, #0x48]
 *   @0x262cf0 mov r3, #54
 *   @0x262cf4 ldr r4, [sp, #0x13c]
 *   @0x262cf8 str r3, [r12]
 *   @0x262cfc b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262d00 ldr r12, [sp, #0x48]
 *   @0x262d04 mov r3, #45
 *   @0x262d08 ldr r4, [sp, #0x13c]
 *   @0x262d0c str r3, [r12]
 *   @0x262d10 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x262d14 ldr r12, [sp, #0x4c]
 *   @0x262d18 rsb r4, r0, #0
 *   @0x262d1c str r12, [sp, #0x58]
 *   @0x262d20 ldr r12, [sp, #0x64]
 *   @0x262d24 str r12, [sp, #0x78]
 *   @0x262d28 ldr r12, [sp, #0x70]
 *   @0x262d2c str r12, [sp, #0x80]
 *   @0x262d30 ldr r12, [sp, #0x6c]
 *   @0x262d34 str r12, [sp, #0x74]
 *   @0x262d38 ldr r12, [sp, #0x4c]
 *   @0x262d3c asr r2, r4, #8
 *   @0x262d40 ldr r1, [r9, #0x20]
 *   @0x262d44 cmn r12, #2
 *   @0x262d48 ldr r3, [r9, #0x10]
 *   @0x262d4c strb r2, [r6, #0x1]
 *   @0x262d50 mov r2, #1
 *   @0x262d54 mvneq r12, #0
 *   @0x262d58 str r12, [sp, #0x4c]
 *   @0x262d5c ldr r12, [sp, #0x40]
 *   @0x262d60 rsb r3, r3, r1
 *   @0x262d64 strb r4, [r6, #0x2]
 *   @0x262d68 tst r12, #1
 *   @0x262d6c str r3, [sp, #0x5c]
 *   @0x262d70 moveq r3, #113
 *   @0x262d74 movne r3, #114
 *   @0x262d78 cmp r4, #31
 *   @0x262d7c strb r3, [r6]
 *   @0x262d80 lslle r2, r2, r4
 *   @0x262d84 ldr r0, [r9, #0x50]
 *   @0x262d88 add r3, r6, #3
 *   @0x262d8c ldr r1, [r9, #0x4c]
 *   @0x262d90 orr r2, r2, r0
 *   @0x262d94 str r2, [r9, #0x50]
 *   @0x262d98 ldr r2, [r9, #0x24]
 *   @0x262d9c cmp r4, r1
 *   @0x262da0 strgt r4, [r9, #0x4c]
 *   @0x262da4 cmp r2, #0
 *   @0x262da8 bne 0x262dbc <_pcre_ord2utf+0x3024>
 *   @0x262dac b 0x262de4 <_pcre_ord2utf+0x304c>
 *   @0x262db0 ldr r2, [r2]
 *   @0x262db4 cmp r2, #0
 *   @0x262db8 beq 0x262de4 <_pcre_ord2utf+0x304c>
 *   @0x262dbc ldrh r1, [r2, #4]
 *   @0x262dc0 cmp r4, r1
 *   @0x262dc4 bne 0x262db0 <_pcre_ord2utf+0x3018>
 *   @0x262dc8 mov r8, r6
 *   @0x262dcc mov r1, #1
 *   @0x262dd0 mov r6, r3
 *   @0x262dd4 strh r1, [r2, #6]
 *   @0x262dd8 ldr r11, [sp, #0x13c]
 *   @0x262ddc ldr r7, [r9, #0x10]
 *   @0x262de0 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x262de4 mov r8, r6
 *   @0x262de8 ldr r11, [sp, #0x13c]
 *   @0x262dec mov r6, r3
 *   @0x262df0 ldr r7, [r9, #0x10]
 *   @0x262df4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x262df8 ldr r4, [sp, #0x13c]
 *   @0x262dfc ldrb r3, [r4, #0x1]
 *   @0x262e00 cmp r3, #60
 *   @0x262e04 cmpne r3, #39
 *   @0x262e08 beq 0x262e14 <_pcre_ord2utf+0x307c>
 *   @0x262e0c cmp r3, #123
 *   @0x262e10 bne 0x263ad4 <_pcre_ord2utf+0x3d3c>
 *   @0x262e14 add r3, r4, #1
 *   @0x262e18 str r3, [sp, #0x13c]
 *   @0x262e1c ldrb r5, [r4, #0x1]
 *   @0x262e20 cmp r5, #60
 *   @0x262e24 beq 0x263950 <_pcre_ord2utf+0x3bb8>
 *   @0x262e28 ldr r12, [sp, #0x4c]
 *   @0x262e2c cmp r5, #39
 *   @0x262e30 movne r5, #125
 *   @0x262e34 moveq r5, #39
 *   @0x262e38 str r12, [sp, #0x58]
 *   @0x262e3c ldr r12, [sp, #0x64]
 *   @0x262e40 str r12, [sp, #0x78]
 *   @0x262e44 ldr r12, [sp, #0x70]
 *   @0x262e48 str r12, [sp, #0x80]
 *   @0x262e4c ldr r12, [sp, #0x6c]
 *   @0x262e50 str r12, [sp, #0x74]
 *   @0x262e54 mov r12, #0
 *   @0x262e58 add r0, r3, #1
 *   @0x262e5c str r0, [sp, #0x13c]
 *   @0x262e60 ldrb r2, [r3, #0x1]
 *   @0x262e64 str r0, [sp, #0x5c]
 *   @0x262e68 sub r1, r2, #48
 *   @0x262e6c cmp r1, #9
 *   @0x262e70 bls 0x26397c <_pcre_ord2utf+0x3be4>
 *   @0x262e74 ldr r1, [r9, #0xc]
 *   @0x262e78 ldrb r2, [r1, r2]
 *   @0x262e7c tst r2, #16
 *   @0x262e80 addne r3, r3, #2
 *   @0x262e84 beq 0x26389c <_pcre_ord2utf+0x3b04>
 *   @0x262e88 str r3, [sp, #0x13c]
 *   @0x262e8c mov r4, r3
 *   @0x262e90 ldrb r2, [r3], #1
 *   @0x262e94 ldrb r0, [r1, r2]
 *   @0x262e98 tst r0, #16
 *   @0x262e9c bne 0x262e88 <_pcre_ord2utf+0x30f0>
 *   @0x262ea0 ldr r0, [sp, #0x3c]
 *   @0x262ea4 ldr r3, [sp, #0x5c]
 *   @0x262ea8 cmp r0, #0
 *   @0x262eac rsb r7, r3, r4
 *   @0x262eb0 beq 0x2638c0 <_pcre_ord2utf+0x3b28>
 *   @0x262eb4 cmp r7, #0
 *   @0x262eb8 beq 0x2638a8 <_pcre_ord2utf+0x3b10>
 *   @0x262ebc cmp r2, r5
 *   @0x262ec0 bne 0x263888 <_pcre_ord2utf+0x3af0>
 *   @0x262ec4 cmp r7, #32
 *   @0x262ec8 bgt 0x263874 <_pcre_ord2utf+0x3adc>
 *   @0x262ecc cmp r12, #0
 *   @0x262ed0 ldr r0, [sp, #0x3c]
 *   @0x262ed4 ldr r2, [r9, #0x7c]
 *   @0x262ed8 ldreq r3, [r9, #0x54]
 *   @0x262edc ldr r11, [r9, #0x30]
 *   @0x262ee0 addeq r3, r3, #1
 *   @0x262ee4 ldr r5, [r9, #0x28]
 *   @0x262ee8 streq r3, [r9, #0x54]
 *   @0x262eec cmp r2, #0
 *   @0x262ef0 ldr r3, [r0]
 *   @0x262ef4 add r2, r3, #14
 *   @0x262ef8 addne r3, r3, #26
 *   @0x262efc str r2, [r0]
 *   @0x262f00 strne r3, [r0]
 *   @0x262f04 cmp r11, #0
 *   @0x262f08 ble 0x26386c <_pcre_ord2utf+0x3ad4>
 *   @0x262f0c mov r3, r12
 *   @0x262f10 mov r4, #0
 *   @0x262f14 mov r12, r6
 *   @0x262f18 add r5, r5, #12
 *   @0x262f1c mov r8, r4
 *   @0x262f20 mov r6, r3
 *   @0x262f24 b 0x262f38 <_pcre_ord2utf+0x31a0>
 *   @0x262f28 add r8, r8, #1
 *   @0x262f2c add r5, r5, #12
 *   @0x262f30 cmp r8, r11
 *   @0x262f34 beq 0x262fb0 <_pcre_ord2utf+0x3218>
 *   @0x262f38 ldr r3, [r5, #-0x8]
 *   @0x262f3c cmp r3, r7
 *   @0x262f40 bne 0x262f28 <_pcre_ord2utf+0x3190>
 *   @0x262f44 ldr r1, [r5, #-0xc]
 *   @0x262f48 mov r2, r7
 *   @0x262f4c ldr r0, [sp, #0x5c]
 *   @0x262f50 str r12, [sp, #0x34]
 *   @0x262f54 bl 0xb65e0 <strncmp@plt>
 *   @0x262f58 ldr r12, [sp, #0x34]
 *   @0x262f5c cmp r0, #0
 *   @0x262f60 bne 0x262f28 <_pcre_ord2utf+0x3190>
 *   @0x262f64 cmp r6, #0
 *   @0x262f68 ldr r4, [r5, #-0x4]
 *   @0x262f6c bne 0x263864 <_pcre_ord2utf+0x3acc>
 *   @0x262f70 ldr r3, [r9, #0x24]
 *   @0x262f74 cmp r3, #0
 *   @0x262f78 bne 0x262f8c <_pcre_ord2utf+0x31f4>
 *   @0x262f7c b 0x262f28 <_pcre_ord2utf+0x3190>
 *   @0x262f80 ldr r3, [r3]
 *   @0x262f84 cmp r3, #0
 *   @0x262f88 beq 0x262f28 <_pcre_ord2utf+0x3190>
 *   @0x262f8c ldrh r2, [r3, #4]
 *   @0x262f90 cmp r4, r2
 *   @0x262f94 bne 0x262f80 <_pcre_ord2utf+0x31e8>
 *   @0x262f98 add r8, r8, #1
 *   @0x262f9c mov r1, #1
 *   @0x262fa0 cmp r8, r11
 *   @0x262fa4 strh r1, [r3, #6]
 *   @0x262fa8 add r5, r5, #12
 *   @0x262fac bne 0x262f38 <_pcre_ord2utf+0x31a0>
 *   @0x262fb0 mov r3, r6
 *   @0x262fb4 mov r6, r12
 *   @0x262fb8 mov r12, r3
 *   @0x262fbc cmp r12, #0
 *   @0x262fc0 beq 0x262d38 <_pcre_ord2utf+0x2fa0>
 *   @0x262fc4 ldr r2, [r9, #0x20]
 *   @0x262fc8 ldr r3, [r9, #0x10]
 *   @0x262fcc ldr r5, [r9, #0x14]
 *   @0x262fd0 rsb r3, r3, r2
 *   @0x262fd4 str r3, [sp, #0x5c]
 *   @0x262fd8 b 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x262fdc ldr r2, [sp, #0x13c]
 *   @0x262fe0 ldr r3, [r9, #0x20]
 *   @0x262fe4 add r11, r2, #1
 *   @0x262fe8 str r11, [sp, #0x13c]
 *   @0x262fec ldrb r5, [r2, #0x1]
 *   @0x262ff0 ldrb r1, [r2, #0x2]
 *   @0x262ff4 cmp r5, #60
 *   @0x262ff8 ldr r7, [r9, #0x10]
 *   @0x262ffc movne r5, #39
 *   @0x263000 moveq r5, #62
 *   @0x263004 cmp r1, #43
 *   @0x263008 cmpne r1, #45
 *   @0x26300c rsb r12, r7, r3
 *   @0x263010 str r12, [sp, #0x5c]
 *   @0x263014 beq 0x263024 <_pcre_ord2utf+0x328c>
 *   @0x263018 sub r1, r1, #48
 *   @0x26301c cmp r1, #9
 *   @0x263020 bhi 0x263838 <_pcre_ord2utf+0x3aa0>
 *   @0x263024 ldrb r1, [r2, #0x3]
 *   @0x263028 add r0, r2, #3
 *   @0x26302c sub r12, r1, #48
 *   @0x263030 cmp r12, #9
 *   @0x263034 bhi 0x263048 <_pcre_ord2utf+0x32b0>
 *   @0x263038 ldrb r1, [r0, #0x1]!
 *   @0x26303c sub r12, r1, #48
 *   @0x263040 cmp r12, #9
 *   @0x263044 bls 0x263038 <_pcre_ord2utf+0x32a0>
 *   @0x263048 cmp r1, r5
 *   @0x26304c bne 0x263810 <_pcre_ord2utf+0x3a78>
 *   @0x263050 ldr r0, [sp, #0x4c]
 *   @0x263054 add r12, r2, #2
 *   @0x263058 ldr r1, [sp, #0x64]
 *   @0x26305c str r12, [sp, #0x13c]
 *   @0x263060 str r0, [sp, #0x58]
 *   @0x263064 str r1, [sp, #0x78]
 *   @0x263068 ldr r0, [sp, #0x70]
 *   @0x26306c ldr r1, [sp, #0x6c]
 *   @0x263070 ldrb r2, [r2, #0x2]
 *   @0x263074 str r0, [sp, #0x80]
 *   @0x263078 str r1, [sp, #0x74]
 *   @0x26307c cmp r2, #43
 *   @0x263080 mov r8, r2
 *   @0x263084 beq 0x2637f0 <_pcre_ord2utf+0x3a58>
 *   @0x263088 cmp r2, #45
 *   @0x26308c beq 0x2637cc <_pcre_ord2utf+0x3a34>
 *   @0x263090 sub r1, r2, #48
 *   @0x263094 uxtb r1, r1
 *   @0x263098 cmp r1, #9
 *   @0x26309c movhi r1, r2
 *   @0x2630a0 movhi r4, #0
 *   @0x2630a4 bhi 0x2630e8 <_pcre_ord2utf+0x3350>
 *   @0x2630a8 add r2, r12, #1
 *   @0x2630ac mov r4, #0
 *   @0x2630b0 b 0x2630c0 <_pcre_ord2utf+0x3328>
 *   @0x2630b4 ldr r0, [sp, #0xd4]
 *   @0x2630b8 cmp r4, r0
 *   @0x2630bc bgt 0x263798 <_pcre_ord2utf+0x3a00>
 *   @0x2630c0 str r2, [sp, #0x13c]
 *   @0x2630c4 mov r12, r2
 *   @0x2630c8 ldrb r0, [r2, #-0x1]
 *   @0x2630cc add r4, r4, r4, lsl #2
 *   @0x2630d0 ldrb r1, [r2], #1
 *   @0x2630d4 add r4, r0, r4, lsl #1
 *   @0x2630d8 sub r0, r1, #48
 *   @0x2630dc sub r4, r4, #48
 *   @0x2630e0 cmp r0, #9
 *   @0x2630e4 bls 0x2630b4 <_pcre_ord2utf+0x331c>
 *   @0x2630e8 cmp r1, r5
 *   @0x2630ec bne 0x2633b0 <_pcre_ord2utf+0x3618>
 *   @0x2630f0 cmp r8, #45
 *   @0x2630f4 beq 0x263378 <_pcre_ord2utf+0x35e0>
 *   @0x2630f8 cmp r8, #43
 *   @0x2630fc beq 0x263204 <_pcre_ord2utf+0x346c>
 *   @0x263100 rsb r7, r7, r3
 *   @0x263104 str r7, [sp, #0x5c]
 *   @0x263108 ldr r12, [sp, #0x3c]
 *   @0x26310c ldr r5, [r9, #0x14]
 *   @0x263110 cmp r12, #0
 *   @0x263114 beq 0x26322c <_pcre_ord2utf+0x3494>
 *   @0x263118 mov r3, #117
 *   @0x26311c strb r3, [r6]
 *   @0x263120 ldr r3, [r9, #0x14]
 *   @0x263124 ldr r12, [sp, #0x4c]
 *   @0x263128 rsb r3, r3, r5
 *   @0x26312c cmn r12, #2
 *   @0x263130 add r12, r6, #3
 *   @0x263134 asr r3, r3, #8
 *   @0x263138 strb r3, [r6, #0x1]
 *   @0x26313c ldr r3, [r9, #0x14]
 *   @0x263140 moveq r0, #0
 *   @0x263144 mvneq r1, #0
 *   @0x263148 movne r2, #0
 *   @0x26314c rsb r5, r3, r5
 *   @0x263150 strb r5, [r6, #0x2]
 *   @0x263154 ldr r11, [sp, #0x13c]
 *   @0x263158 ldr r7, [r9, #0x10]
 *   @0x26315c streq r0, [sp, #0x9c]
 *   @0x263160 streq r1, [sp, #0x4c]
 *   @0x263164 strne r2, [sp, #0x9c]
 *   @0x263168 mov r8, r6
 *   @0x26316c mov r6, r12
 *   @0x263170 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x263174 cmp r8, #0
 *   @0x263178 beq 0x262bf0 <_pcre_ord2utf+0x2e58>
 *   @0x26317c ldr r12, [sp, #0x58]
 *   @0x263180 mov r5, #0
 *   @0x263184 ldr r4, [sp, #0x13c]
 *   @0x263188 mov r11, #1
 *   @0x26318c str r12, [sp, #0x4c]
 *   @0x263190 ldr r12, [sp, #0x74]
 *   @0x263194 str r12, [sp, #0x6c]
 *   @0x263198 ldr r12, [sp, #0x80]
 *   @0x26319c str r12, [sp, #0x70]
 *   @0x2631a0 ldr r12, [sp, #0x78]
 *   @0x2631a4 str r12, [sp, #0x64]
 *   @0x2631a8 mov r12, #2
 *   @0x2631ac str r12, [sp, #0x88]
 *   @0x2631b0 b 0x260740 <_pcre_ord2utf+0x9a8>
 *   @0x2631b4 cmp r8, #0
 *   @0x2631b8 beq 0x262bf0 <_pcre_ord2utf+0x2e58>
 *   @0x2631bc ldr r4, [sp, #0x13c]
 *   @0x2631c0 mov r5, #1
 *   @0x2631c4 mvn r11, #0
 *   @0x2631c8 b 0x260730 <_pcre_ord2utf+0x998>
 *   @0x2631cc ldr r12, [sp, #0x90]
 *   @0x2631d0 mov r3, #0
 *   @0x2631d4 ldr r0, [r7, #0x24]
 *   @0x2631d8 ldrb r1, [r12, #0x3]
 *   @0x2631dc ldrb r2, [r12, #0x4]
 *   @0x2631e0 str r0, [sp, #0x164]
 *   @0x2631e4 orr r2, r2, r1, lsl #8
 *   @0x2631e8 add r1, sp, #512
 *   @0x2631ec str r2, [sp, #0xdc]
 *   @0x2631f0 strh r3, [r1, #-150]
 *   @0x2631f4 add r3, sp, #356
 *   @0x2631f8 strh r2, [r1, #-152]
 *   @0x2631fc str r3, [r7, #0x24]
 *   @0x263200 b 0x260030 <_pcre_ord2utf+0x298>
 *   @0x263204 cmp r4, #0
 *   @0x263208 beq 0x2632c4 <_pcre_ord2utf+0x352c>
 *   @0x26320c ldr r12, [sp, #0x3c]
 *   @0x263210 rsb r7, r7, r3
 *   @0x263214 ldr r2, [r9, #0x40]
 *   @0x263218 cmp r12, #0
 *   @0x26321c str r7, [sp, #0x5c]
 *   @0x263220 add r4, r4, r2
 *   @0x263224 ldr r5, [r9, #0x14]
 *   @0x263228 bne 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x26322c cmp r4, #0
 *   @0x263230 mov r3, #0
 *   @0x263234 strb r3, [r6]
 *   @0x263238 beq 0x263250 <_pcre_ord2utf+0x34b8>
 *   @0x26323c ldr r0, [r9, #0x14]
 *   @0x263240 mov r1, r10
 *   @0x263244 mov r2, r4
 *   @0x263248 bl 0x25e0fc <_pcre_find_bracket>
 *   @0x26324c mov r5, r0
 *   @0x263250 cmp r5, #0
 *   @0x263254 beq 0x2632dc <_pcre_ord2utf+0x3544>
 *   @0x263258 ldrb r2, [r5, #0x1]
 *   @0x26325c ldrb r3, [r5, #0x2]
 *   @0x263260 orrs r3, r3, r2, lsl #8
 *   @0x263264 bne 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x263268 ldr r12, [sp, #0x1ec]
 *   @0x26326c cmp r12, #0
 *   @0x263270 addle r4, sp, #364
 *   @0x263274 movle r7, r3
 *   @0x263278 bgt 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x26327c ldr r0, [r4, #0x4]
 *   @0x263280 cmp r5, r0
 *   @0x263284 bhi 0x2632b0 <_pcre_ord2utf+0x3518>
 *   @0x263288 str r7, [sp]
 *   @0x26328c mov r1, r6
 *   @0x263290 mov r2, r10
 *   @0x263294 mov r3, r9
 *   @0x263298 bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88>
 *   @0x26329c cmp r0, #0
 *   @0x2632a0 beq 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x2632a4 ldr r4, [r4]
 *   @0x2632a8 cmp r4, #0
 *   @0x2632ac bne 0x26327c <_pcre_ord2utf+0x34e4>
 *   @0x2632b0 ldr r12, [sp, #0x48]
 *   @0x2632b4 mov r3, #40
 *   @0x2632b8 ldr r11, [sp, #0x13c]
 *   @0x2632bc str r3, [r12]
 *   @0x2632c0 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2632c4 ldr r12, [sp, #0x48]
 *   @0x2632c8 mov r3, #58
 *   @0x2632cc ldr r11, [sp, #0x13c]
 *   @0x2632d0 str r3, [r12]
 *   @0x2632d4 mov r4, r11
 *   @0x2632d8 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x2632dc ldr r3, [r9, #0x44]
 *   @0x2632e0 cmp r3, r4
 *   @0x2632e4 blt 0x263394 <_pcre_ord2utf+0x35fc>
 *   @0x2632e8 ldr r2, [r9, #0x3c]
 *   @0x2632ec ldr r1, [r9, #0x10]
 *   @0x2632f0 sub r2, r2, #100
 *   @0x2632f4 ldr r3, [r9, #0x20]
 *   @0x2632f8 add r1, r1, r2
 *   @0x2632fc ldr r2, [r9, #0x14]
 *   @0x263300 cmp r3, r1
 *   @0x263304 add r5, r2, r4
 *   @0x263308 bhs 0x26333c <_pcre_ord2utf+0x35a4>
 *   @0x26330c add r1, r6, #1
 *   @0x263310 rsb r2, r2, r1
 *   @0x263314 asr r2, r2, #8
 *   @0x263318 strb r2, [r3]
 *   @0x26331c ldr r3, [r9, #0x20]
 *   @0x263320 ldr r2, [r9, #0x14]
 *   @0x263324 rsb r1, r2, r1
 *   @0x263328 strb r1, [r3, #0x1]
 *   @0x26332c ldr r3, [r9, #0x20]
 *   @0x263330 add r3, r3, #2
 *   @0x263334 str r3, [r9, #0x20]
 *   @0x263338 b 0x263118 <_pcre_ord2utf+0x3380>
 *   @0x26333c mov r0, r9
 *   @0x263340 bl 0x25cd64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c3c>
 *   @0x263344 ldr r12, [sp, #0x48]
 *   @0x263348 cmp r0, #0
 *   @0x26334c str r0, [r12]
 *   @0x263350 bne 0x2633a8 <_pcre_ord2utf+0x3610>
 *   @0x263354 ldr r3, [r9, #0x20]
 *   @0x263358 ldr r2, [r9, #0x14]
 *   @0x26335c b 0x26330c <_pcre_ord2utf+0x3574>
 *   @0x263360 andseq r7, r2, r4, ror #15
 *   @0x263364 ldrsbeq r7, [r2], -r4
 *   @0x263368 .word 0xfffffba8
 *   @0x26336c .word 0xfffffbac
 *   @0x263370 .word 0xfffffb94
 *   @0x263374 .word 0xffffea38
 *   @0x263378 cmp r4, #0
 *   @0x26337c beq 0x2632c4 <_pcre_ord2utf+0x352c>
 *   @0x263380 ldr r2, [r9, #0x40]
 *   @0x263384 add r2, r2, #1
 *   @0x263388 rsb r4, r4, r2
 *   @0x26338c cmp r4, #0
 *   @0x263390 bgt 0x263100 <_pcre_ord2utf+0x3368>
 *   @0x263394 ldr r12, [sp, #0x48]
 *   @0x263398 mov r3, #15
 *   @0x26339c ldr r11, [sp, #0x13c]
 *   @0x2633a0 str r3, [r12]
 *   @0x2633a4 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2633a8 ldr r11, [sp, #0x13c]
 *   @0x2633ac b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2633b0 ldr r12, [sp, #0x48]
 *   @0x2633b4 mov r3, #29
 *   @0x2633b8 ldr r11, [sp, #0x13c]
 *   @0x2633bc str r3, [r12]
 *   @0x2633c0 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2633c4 cmp r0, #5
 *   @0x2633c8 beq 0x2635f0 <_pcre_ord2utf+0x3858>
 *   @0x2633cc cmp r0, #12
 *   @0x2633d0 beq 0x2635dc <_pcre_ord2utf+0x3844>
 *   @0x2633d4 cmp r0, #26
 *   @0x2633d8 beq 0x26350c <_pcre_ord2utf+0x3774>
 *   @0x2633dc cmp r0, #25
 *   @0x2633e0 beq 0x2634ac <_pcre_ord2utf+0x3714>
 *   @0x2633e4 sub r0, r0, #6
 *   @0x2633e8 ldr r1, [r9, #0x8]
 *   @0x2633ec add r3, r7, #1
 *   @0x2633f0 add r12, r5, #2
 *   @0x2633f4 cmp r0, #15
 *   @0x2633f8 addls pc, pc, r0, lsl #2
 *   @0x2633fc b 0x263598 <_pcre_ord2utf+0x3800>
 *   @0x263400 b 0x263558 <_pcre_ord2utf+0x37c0>
 *   @0x263404 b 0x263724 <_pcre_ord2utf+0x398c>
 *   @0x263408 b 0x2636fc <_pcre_ord2utf+0x3964>
 *   @0x26340c b 0x2636d0 <_pcre_ord2utf+0x3938>
 *   @0x263410 b 0x2636a4 <_pcre_ord2utf+0x390c>
 *   @0x263414 b 0x263754 <_pcre_ord2utf+0x39bc>
 *   @0x263418 b 0x263598 <_pcre_ord2utf+0x3800>
 *   @0x26341c b 0x263598 <_pcre_ord2utf+0x3800>
 *   @0x263420 b 0x263598 <_pcre_ord2utf+0x3800>
 *   @0x263424 b 0x262d00 <_pcre_ord2utf+0x2f68>
 *   @0x263428 b 0x262d00 <_pcre_ord2utf+0x2f68>
 *   @0x26342c b 0x263598 <_pcre_ord2utf+0x3800>
 *   @0x263430 b 0x26374c <_pcre_ord2utf+0x39b4>
 *   @0x263434 b 0x26377c <_pcre_ord2utf+0x39e4>
 *   @0x263438 b 0x263524 <_pcre_ord2utf+0x378c>
 *   @0x26343c b 0x26347c <_pcre_ord2utf+0x36e4>
 *   @0x263440 cmp r4, #125
 *   @0x263444 beq 0x2634b4 <_pcre_ord2utf+0x371c>
 *   @0x263448 ldr r12, [sp, #0x4c]
 *   @0x26344c mov r11, r3
 *   @0x263450 ldr r7, [r9, #0x10]
 *   @0x263454 str r12, [sp, #0x58]
 *   @0x263458 ldr r12, [sp, #0x64]
 *   @0x26345c str r12, [sp, #0x78]
 *   @0x263460 ldr r12, [sp, #0x70]
 *   @0x263464 str r12, [sp, #0x80]
 *   @0x263468 ldr r12, [sp, #0x6c]
 *   @0x26346c str r12, [sp, #0x74]
 *   @0x263470 ldr r12, [sp, #0x3c]
 *   @0x263474 str r12, [sp, #0x9c]
 *   @0x263478 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x26347c ldr lr, [pc, #-0x11c]
 *   @0x263480 mov r7, r3
 *   @0x263484 mov r3, lr
 *   @0x263488 ldr lr, [sp, #0xa0]
 *   @0x26348c mov r5, r12
 *   @0x263490 mov r0, r11
 *   @0x263494 add r1, sp, #324
 *   @0x263498 mov r2, r8
 *   @0x26349c ldr r12, [lr, r3]
 *   @0x2634a0 mov r3, r9
 *   @0x2634a4 str r12, [sp]
 *   @0x2634a8 bl 0xb7090 <.text+0xc0>
 *   @0x2634ac ldr r3, [sp, #0x13c]
 *   @0x2634b0 b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x2634b4 ldr r2, [sp, #0x154]
 *   @0x2634b8 cmp r2, #0
 *   @0x2634bc blt 0x263448 <_pcre_ord2utf+0x36b0>
 *   @0x2634c0 ldr r1, [sp, #0x158]
 *   @0x2634c4 cmp r1, #0
 *   @0x2634c8 blt 0x263448 <_pcre_ord2utf+0x36b0>
 *   @0x2634cc ldr r12, [sp, #0x64]
 *   @0x2634d0 mov r11, r3
 *   @0x2634d4 str r2, [sp, #0x64]
 *   @0x2634d8 ldr r7, [r9, #0x10]
 *   @0x2634dc str r12, [sp, #0x78]
 *   @0x2634e0 ldr r12, [sp, #0x6c]
 *   @0x2634e4 str r12, [sp, #0x74]
 *   @0x2634e8 ldr r12, [sp, #0x4c]
 *   @0x2634ec str r12, [sp, #0x58]
 *   @0x2634f0 ldr r12, [sp, #0x70]
 *   @0x2634f4 str r12, [sp, #0x80]
 *   @0x2634f8 ldr r12, [sp, #0x148]
 *   @0x2634fc str r12, [sp, #0x6c]
 *   @0x263500 ldr r12, [sp, #0x3c]
 *   @0x263504 str r12, [sp, #0x9c]
 *   @0x263508 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x26350c ldr r3, [sp, #0x13c]
 *   @0x263510 ldrb r2, [r3, #0x1]
 *   @0x263514 cmp r2, #92
 *   @0x263518 beq 0x263784 <_pcre_ord2utf+0x39ec>
 *   @0x26351c mov r6, #1
 *   @0x263520 b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x263524 ldr lr, [pc, #-0x1c4]
 *   @0x263528 mov r7, r3
 *   @0x26352c mov r3, lr
 *   @0x263530 ldr lr, [sp, #0xa0]
 *   @0x263534 mov r5, r12
 *   @0x263538 mov r0, r11
 *   @0x26353c add r1, sp, #324
 *   @0x263540 mov r2, r8
 *   @0x263544 ldr r12, [lr, r3]
 *   @0x263548 mov r3, r9
 *   @0x26354c str r12, [sp]
 *   @0x263550 bl 0xb6fd0 <.text>
 *   @0x263554 b 0x2634ac <_pcre_ord2utf+0x3714>
 *   @0x263558 add r5, r1, #63
 *   @0x26355c add r1, sp, #404
 *   @0x263560 mov r2, r11
 *   @0x263564 ldrb r0, [r5, #0x1]!
 *   @0x263568 ldrb r4, [r2]
 *   @0x26356c mvn r0, r0
 *   @0x263570 orr r0, r4, r0
 *   @0x263574 strb r0, [r2], #1
 *   @0x263578 cmp r2, r1
 *   @0x26357c bne 0x263564 <_pcre_ord2utf+0x37cc>
 *   @0x263580 mov r5, r12
 *   @0x263584 mov r7, r3
 *   @0x263588 mov r12, #1
 *   @0x26358c ldr r3, [sp, #0x13c]
 *   @0x263590 str r12, [sp, #0x74]
 *   @0x263594 b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x263598 ldr r12, [sp, #0x110]
 *   @0x26359c cmp r12, #0
 *   @0x2635a0 bne 0x2635c8 <_pcre_ord2utf+0x3830>
 *   @0x2635a4 ldr r3, [sp, #0x13c]
 *   @0x2635a8 ldrb r4, [r3]
 *   @0x2635ac mov r1, r3
 *   @0x2635b0 ldrb r2, [r3, #0x1]
 *   @0x2635b4 cmp r4, #13
 *   @0x2635b8 cmpne r4, #10
 *   @0x2635bc movne r0, #0
 *   @0x2635c0 moveq r0, #1
 *   @0x2635c4 b 0x262468 <_pcre_ord2utf+0x26d0>
 *   @0x2635c8 ldr r12, [sp, #0x48]
 *   @0x2635cc mov r3, #7
 *   @0x2635d0 ldr r4, [sp, #0x13c]
 *   @0x2635d4 str r3, [r12]
 *   @0x2635d8 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x2635dc ldr r12, [sp, #0x48]
 *   @0x2635e0 mov r3, #71
 *   @0x2635e4 ldr r4, [sp, #0x13c]
 *   @0x2635e8 str r3, [r12]
 *   @0x2635ec b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x2635f0 ldr r1, [sp, #0x13c]
 *   @0x2635f4 mov r0, r6
 *   @0x2635f8 mov r4, #8
 *   @0x2635fc ldrb r2, [r1, #0x1]
 *   @0x263600 b 0x262468 <_pcre_ord2utf+0x26d0>
 *   @0x263604 tst r4, #4
 *   @0x263608 bne 0x263658 <_pcre_ord2utf+0x38c0>
 *   @0x26360c ldrb r1, [r3, #0x4]
 *   @0x263610 and r0, r4, #3
 *   @0x263614 ldrb r12, [r3, #0x1]
 *   @0x263618 add r3, r3, #4
 *   @0x26361c ldrb r2, [r3, #-0x2]
 *   @0x263620 and r1, r1, #63
 *   @0x263624 orr r0, r1, r0, lsl #24
 *   @0x263628 and r12, r12, #63
 *   @0x26362c ldrb r1, [r3, #-0x1]
 *   @0x263630 and r2, r2, #63
 *   @0x263634 orr r0, r0, r12, lsl #18
 *   @0x263638 str r3, [sp, #0x13c]
 *   @0x26363c and r1, r1, #63
 *   @0x263640 orr r2, r0, r2, lsl #12
 *   @0x263644 orr r4, r2, r1, lsl #6
 *   @0x263648 b 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x26364c cmp r2, #93
 *   @0x263650 bne 0x262730 <_pcre_ord2utf+0x2998>
 *   @0x263654 b 0x2626bc <_pcre_ord2utf+0x2924>
 *   @0x263658 ldrb r2, [r3, #0x5]
 *   @0x26365c and r1, r4, #1
 *   @0x263660 ldrb r0, [r3, #0x1]
 *   @0x263664 add r3, r3, #5
 *   @0x263668 ldrb r12, [r3, #-0x3]
 *   @0x26366c and r2, r2, #63
 *   @0x263670 and r0, r0, #63
 *   @0x263674 orr r1, r2, r1, lsl #30
 *   @0x263678 ldrb r2, [r3, #-0x2]
 *   @0x26367c and r12, r12, #63
 *   @0x263680 orr r0, r1, r0, lsl #24
 *   @0x263684 ldrb r1, [r3, #-0x1]
 *   @0x263688 and r2, r2, #63
 *   @0x26368c orr r0, r0, r12, lsl #18
 *   @0x263690 and r1, r1, #63
 *   @0x263694 str r3, [sp, #0x13c]
 *   @0x263698 orr r2, r0, r2, lsl #12
 *   @0x26369c orr r4, r2, r1, lsl #6
 *   @0x2636a0 b 0x2623f8 <_pcre_ord2utf+0x2660>
 *   @0x2636a4 add r5, r1, #159
 *   @0x2636a8 add r1, sp, #404
 *   @0x2636ac mov r2, r11
 *   @0x2636b0 ldrb r0, [r5, #0x1]!
 *   @0x2636b4 ldrb r4, [r2]
 *   @0x2636b8 mvn r0, r0
 *   @0x2636bc orr r0, r4, r0
 *   @0x2636c0 strb r0, [r2], #1
 *   @0x2636c4 cmp r2, r1
 *   @0x2636c8 bne 0x2636b0 <_pcre_ord2utf+0x3918>
 *   @0x2636cc b 0x263580 <_pcre_ord2utf+0x37e8>
 *   @0x2636d0 mov r2, #0
 *
 * ══ §4/8 anon_2636d4  0x2636d4..0x264c00  size 5420  1355 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_25fe2c
 * @func 0x2636d4 0x264c10  size 5436  1359 条
 * ⚠ 父块 anon_25fe2c 是 26,424 B 的未闭合大状态机（METHOD §4）：段长不一定等于函数长，本段可能只是其中的一段
 * 入度 19｜调用者: 0x261ee0(anon_25fe2c+0x20b4), 0x261ee4(anon_25fe2c+0x20b8), 0x261ee8(anon_25fe2c+0x20bc), 0x261eec(anon_25fe2c+0x20c0), 0x261ef0(anon_25fe2c+0x20c4), 0x261ef4(anon_25fe2c+0x20c8), 0x261ef8(anon_25fe2c+0x20cc), 0x26206c(anon_25fe2c+0x2240)…
 * 出调用 22 处 → 0xb65bc×4, 0xb65e0×3, 0xb6694×2, _pcre_ord2utf×2, anon_25b524+0x1840×2, anon_25fe2c+0x3568×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2636d4 ldrb r4, [r1, r2]
 *   @0x2636d8 ldrb r0, [r2, r11]
 *   @0x2636dc orr r0, r4, r0
 *   @0x2636e0 strb r0, [r2, r11]
 *   @0x2636e4 add r2, r2, #1
 *   @0x2636e8 cmp r2, #32
 *   @0x2636ec bne 0x2636d4 <_pcre_ord2utf+0x393c>
 *   @0x2636f0 mov r5, r12
 *   @0x2636f4 mov r7, r3
 *   @0x2636f8 b 0x2634ac <_pcre_ord2utf+0x3714>
 *   @0x2636fc mov r2, #0
 *   @0x263700 ldrb r4, [r1, r2]
 *   @0x263704 ldrb r0, [r2, r11]
 *   @0x263708 mvn r4, r4
 *   @0x26370c orr r0, r4, r0
 *   @0x263710 strb r0, [r2, r11]
 *   @0x263714 add r2, r2, #1
 *   @0x263718 cmp r2, #32
 *   @0x26371c bne 0x263700 <_pcre_ord2utf+0x3968>
 *   @0x263720 b 0x263580 <_pcre_ord2utf+0x37e8>
 *   @0x263724 add r1, r1, #63
 *   @0x263728 add r0, sp, #404
 *   @0x26372c mov r2, r11
 *   @0x263730 ldrb r5, [r2]
 *   @0x263734 ldrb r4, [r1, #0x1]!
 *   @0x263738 orr r4, r5, r4
 *   @0x26373c strb r4, [r2], #1
 *   @0x263740 cmp r2, r0
 *   @0x263744 bne 0x263730 <_pcre_ord2utf+0x3998>
 *   @0x263748 b 0x2636f0 <_pcre_ord2utf+0x3958>
 *   @0x26374c ldr lr, [pc, #-0x3e8]
 *   @0x263750 b 0x263528 <_pcre_ord2utf+0x3790>
 *   @0x263754 add r1, r1, #159
 *   @0x263758 add r0, sp, #404
 *   @0x26375c mov r2, r11
 *   @0x263760 ldrb r5, [r2]
 *   @0x263764 ldrb r4, [r1, #0x1]!
 *   @0x263768 orr r4, r5, r4
 *   @0x26376c strb r4, [r2], #1
 *   @0x263770 cmp r2, r0
 *   @0x263774 bne 0x263760 <_pcre_ord2utf+0x39c8>
 *   @0x263778 b 0x2636f0 <_pcre_ord2utf+0x3958>
 *   @0x26377c ldr lr, [pc, #-0x418]
 *   @0x263780 b 0x263480 <_pcre_ord2utf+0x36e8>
 *   @0x263784 ldrb r2, [r3, #0x2]
 *   @0x263788 cmp r2, #69
 *   @0x26378c addeq r3, r3, #2
 *   @0x263790 bne 0x26351c <_pcre_ord2utf+0x3784>
 *   @0x263794 b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x263798 add r9, r12, #1
 *   @0x26379c str r9, [sp, #0x13c]
 *   @0x2637a0 mov r3, r9
 *   @0x2637a4 ldrb r2, [r9]
 *   @0x2637a8 add r9, r9, #1
 *   @0x2637ac sub r2, r2, #48
 *   @0x2637b0 cmp r2, #9
 *   @0x2637b4 bls 0x26379c <_pcre_ord2utf+0x3a04>
 *   @0x2637b8 ldr r12, [sp, #0x48]
 *   @0x2637bc mov r11, r3
 *   @0x2637c0 mov r3, #61
 *   @0x2637c4 str r3, [r12]
 *   @0x2637c8 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2637cc ldrb r2, [r12, #0x1]
 *   @0x2637d0 sub r2, r2, #48
 *   @0x2637d4 cmp r2, #9
 *   @0x2637d8 bhi 0x26563c <_pcre_ord2utf+0x58a4>
 *   @0x2637dc add r1, r12, #1
 *   @0x2637e0 str r1, [sp, #0x13c]
 *   @0x2637e4 ldrb r2, [r12, #0x1]
 *   @0x2637e8 mov r12, r1
 *   @0x2637ec b 0x263090 <_pcre_ord2utf+0x32f8>
 *   @0x2637f0 add r1, r12, #1
 *   @0x2637f4 str r1, [sp, #0x13c]
 *   @0x2637f8 ldrb r2, [r12, #0x1]
 *   @0x2637fc sub r2, r2, #48
 *   @0x263800 cmp r2, #9
 *   @0x263804 bhi 0x263824 <_pcre_ord2utf+0x3a8c>
 *   @0x263808 mov r12, r1
 *   @0x26380c b 0x2630a8 <_pcre_ord2utf+0x3310>
 *   @0x263810 ldr r12, [sp, #0x48]
 *   @0x263814 mov r3, #57
 *   @0x263818 mov r4, r11
 *   @0x26381c str r3, [r12]
 *   @0x263820 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x263824 ldr r12, [sp, #0x48]
 *   @0x263828 mov r3, #63
 *   @0x26382c mov r11, r1
 *   @0x263830 str r3, [r12]
 *   @0x263834 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x263838 ldr r12, [sp, #0x4c]
 *   @0x26383c mov r3, r11
 *   @0x263840 str r12, [sp, #0x58]
 *   @0x263844 ldr r12, [sp, #0x64]
 *   @0x263848 str r12, [sp, #0x78]
 *   @0x26384c ldr r12, [sp, #0x70]
 *   @0x263850 str r12, [sp, #0x80]
 *   @0x263854 ldr r12, [sp, #0x6c]
 *   @0x263858 str r12, [sp, #0x74]
 *   @0x26385c mov r12, #1
 *   @0x263860 b 0x262e58 <_pcre_ord2utf+0x30c0>
 *   @0x263864 mov r6, r12
 *   @0x263868 b 0x262fc4 <_pcre_ord2utf+0x322c>
 *   @0x26386c mov r4, #0
 *   @0x263870 b 0x262fbc <_pcre_ord2utf+0x3224>
 *   @0x263874 ldr r12, [sp, #0x48]
 *   @0x263878 mov r3, #48
 *   @0x26387c mov r11, r4
 *   @0x263880 str r3, [r12]
 *   @0x263884 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x263888 ldr r12, [sp, #0x48]
 *   @0x26388c mov r3, #42
 *   @0x263890 mov r11, r4
 *   @0x263894 str r3, [r12]
 *   @0x263898 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x26389c ldr r0, [sp, #0x3c]
 *   @0x2638a0 cmp r0, #0
 *   @0x2638a4 beq 0x2638bc <_pcre_ord2utf+0x3b24>
 *   @0x2638a8 ldr r12, [sp, #0x48]
 *   @0x2638ac mov r3, #62
 *   @0x2638b0 ldr r11, [sp, #0x13c]
 *   @0x2638b4 str r3, [r12]
 *   @0x2638b8 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2638bc mov r7, r0
 *   @0x2638c0 ldr r11, [r9, #0x30]
 *   @0x2638c4 ldr r5, [r9, #0x2c]
 *   @0x2638c8 cmp r11, #0
 *   @0x2638cc ble 0x263394 <_pcre_ord2utf+0x35fc>
 *   @0x2638d0 mov r8, #0
 *   @0x2638d4 mov r4, r12
 *   @0x2638d8 b 0x2638f0 <_pcre_ord2utf+0x3b58>
 *   @0x2638dc add r8, r8, #1
 *   @0x2638e0 ldr r3, [r9, #0x34]
 *   @0x2638e4 cmp r8, r11
 *   @0x2638e8 add r5, r5, r3
 *   @0x2638ec beq 0x263394 <_pcre_ord2utf+0x35fc>
 *   @0x2638f0 add r3, r5, #2
 *   @0x2638f4 ldr r0, [sp, #0x5c]
 *   @0x2638f8 mov r2, r7
 *   @0x2638fc str r3, [sp, #0x50]
 *   @0x263900 mov r1, r3
 *   @0x263904 bl 0xb65e0 <strncmp@plt>
 *   @0x263908 cmp r0, #0
 *   @0x26390c bne 0x2638dc <_pcre_ord2utf+0x3b44>
 *   @0x263910 add r3, r5, r7
 *   @0x263914 ldrb r3, [r3, #0x2]
 *   @0x263918 cmp r3, #0
 *   @0x26391c bne 0x2638dc <_pcre_ord2utf+0x3b44>
 *   @0x263920 mov r12, r4
 *   @0x263924 ldrb r4, [r5]
 *   @0x263928 ldrb r3, [r5, #0x1]
 *   @0x26392c cmp r12, #0
 *   @0x263930 orr r4, r3, r4, lsl #8
 *   @0x263934 beq 0x263990 <_pcre_ord2utf+0x3bf8>
 *   @0x263938 ldr r2, [r9, #0x20]
 *   @0x26393c ldr r3, [r9, #0x10]
 *   @0x263940 ldr r5, [r9, #0x14]
 *   @0x263944 rsb r3, r3, r2
 *   @0x263948 str r3, [sp, #0x5c]
 *   @0x26394c b 0x26322c <_pcre_ord2utf+0x3494>
 *   @0x263950 ldr r12, [sp, #0x4c]
 *   @0x263954 mov r5, #62
 *   @0x263958 str r12, [sp, #0x58]
 *   @0x26395c ldr r12, [sp, #0x64]
 *   @0x263960 str r12, [sp, #0x78]
 *   @0x263964 ldr r12, [sp, #0x70]
 *   @0x263968 str r12, [sp, #0x80]
 *   @0x26396c ldr r12, [sp, #0x6c]
 *   @0x263970 str r12, [sp, #0x74]
 *   @0x263974 mov r12, #0
 *   @0x263978 b 0x262e58 <_pcre_ord2utf+0x30c0>
 *   @0x26397c ldr r12, [sp, #0x48]
 *   @0x263980 mov r3, #84
 *   @0x263984 ldr r11, [sp, #0x5c]
 *   @0x263988 str r3, [r12]
 *   @0x26398c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x263990 ldr r3, [r9, #0x78]
 *   @0x263994 cmp r3, #0
 *   @0x263998 beq 0x262d38 <_pcre_ord2utf+0x2fa0>
 *   @0x26399c add r2, r8, #1
 *   @0x2639a0 ldr r3, [r9, #0x34]
 *   @0x2639a4 cmp r2, r11
 *   @0x2639a8 add r7, r5, r3
 *   @0x2639ac bge 0x262d38 <_pcre_ord2utf+0x2fa0>
 *   @0x2639b0 rsb r2, r8, r11
 *   @0x2639b4 mov r12, r4
 *   @0x2639b8 mov r11, #1
 *   @0x2639bc mov r4, r2
 *   @0x2639c0 mov r2, r9
 *   @0x2639c4 mov r9, r5
 *   @0x2639c8 mov r5, r3
 *   @0x2639cc ldr r0, [sp, #0x50]
 *   @0x2639d0 add r1, r7, #2
 *   @0x2639d4 str r2, [sp, #0x38]
 *   @0x2639d8 str r12, [sp, #0x34]
 *   @0x2639dc bl 0xb6574 <strcmp@plt>
 *   @0x2639e0 ldr r2, [sp, #0x38]
 *   @0x2639e4 ldr r12, [sp, #0x34]
 *   @0x2639e8 cmp r0, #0
 *   @0x2639ec bne 0x263ae4 <_pcre_ord2utf+0x3d4c>
 *   @0x2639f0 add r11, r11, #1
 *   @0x2639f4 add r7, r7, r5
 *   @0x2639f8 cmp r11, r4
 *   @0x2639fc bne 0x2639cc <_pcre_ord2utf+0x3c34>
 *   @0x263a00 mov r5, r9
 *   @0x263a04 mov r9, r2
 *   @0x263a08 ldr r12, [sp, #0x4c]
 *   @0x263a0c lsr r3, r8, #8
 *   @0x263a10 ldr r1, [r9, #0x20]
 *   @0x263a14 cmn r12, #2
 *   @0x263a18 ldr r2, [r9, #0x10]
 *   @0x263a1c strb r8, [r6, #0x2]
 *   @0x263a20 mvneq r12, #0
 *   @0x263a24 str r12, [sp, #0x4c]
 *   @0x263a28 ldr r12, [sp, #0x40]
 *   @0x263a2c rsb r2, r2, r1
 *   @0x263a30 str r2, [sp, #0x5c]
 *   @0x263a34 tst r12, #1
 *   @0x263a38 strb r3, [r6, #0x1]
 *   @0x263a3c add r12, r6, #5
 *   @0x263a40 strb r11, [r6, #0x4]
 *   @0x263a44 moveq r2, #115
 *   @0x263a48 movne r2, #116
 *   @0x263a4c cmp r5, r7
 *   @0x263a50 strb r2, [r6]
 *   @0x263a54 asr r2, r11, #8
 *   @0x263a58 strb r2, [r6, #0x3]
 *   @0x263a5c bhs 0x263b10 <_pcre_ord2utf+0x3d78>
 *   @0x263a60 ldr r4, [r9, #0x50]
 *   @0x263a64 mov r8, #1
 *   @0x263a68 ldr r0, [r9, #0x24]
 *   @0x263a6c ldr r11, [r9, #0x34]
 *   @0x263a70 ldrb r2, [r5]
 *   @0x263a74 ldrb r3, [r5, #0x1]
 *   @0x263a78 ldr r1, [r9, #0x4c]
 *   @0x263a7c orr r2, r3, r2, lsl #8
 *   @0x263a80 cmp r2, #31
 *   @0x263a84 lslle r3, r8, r2
 *   @0x263a88 movgt r3, #1
 *   @0x263a8c cmp r2, r1
 *   @0x263a90 strgt r2, [r9, #0x4c]
 *   @0x263a94 cmp r0, #0
 *   @0x263a98 orr r4, r4, r3
 *   @0x263a9c str r4, [r9, #0x50]
 *   @0x263aa0 beq 0x263b04 <_pcre_ord2utf+0x3d6c>
 *   @0x263aa4 ldrh r3, [r0, #4]
 *   @0x263aa8 cmp r2, r3
 *   @0x263aac movne r3, r0
 *   @0x263ab0 bne 0x263ac4 <_pcre_ord2utf+0x3d2c>
 *   @0x263ab4 b 0x263afc <_pcre_ord2utf+0x3d64>
 *   @0x263ab8 ldrh r1, [r3, #4]
 *   @0x263abc cmp r2, r1
 *   @0x263ac0 beq 0x263b00 <_pcre_ord2utf+0x3d68>
 *   @0x263ac4 ldr r3, [r3]
 *   @0x263ac8 cmp r3, #0
 *   @0x263acc bne 0x263ab8 <_pcre_ord2utf+0x3d20>
 *   @0x263ad0 b 0x263b04 <_pcre_ord2utf+0x3d6c>
 *   @0x263ad4 ldr r12, [sp, #0x48]
 *   @0x263ad8 mov r3, #69
 *   @0x263adc str r3, [r12]
 *   @0x263ae0 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x263ae4 cmp r11, #1
 *   @0x263ae8 mov r5, r9
 *   @0x263aec mov r4, r12
 *   @0x263af0 mov r9, r2
 *   @0x263af4 bne 0x263a08 <_pcre_ord2utf+0x3c70>
 *   @0x263af8 b 0x262d38 <_pcre_ord2utf+0x2fa0>
 *   @0x263afc mov r3, r0
 *   @0x263b00 strh r8, [r3, #6]
 *   @0x263b04 add r5, r5, r11
 *   @0x263b08 cmp r5, r7
 *   @0x263b0c blo 0x263a70 <_pcre_ord2utf+0x3cd8>
 *   @0x263b10 ldr r11, [sp, #0x13c]
 *   @0x263b14 ldr r7, [r9, #0x10]
 *   @0x263b18 b 0x263168 <_pcre_ord2utf+0x33d0>
 *   @0x263b1c ldr r8, [sp, #0x94]
 *   @0x263b20 ldr r3, [sp, #0x144]
 *   @0x263b24 ldr r12, [sp, #0x68]
 *   @0x263b28 cmp r3, r8
 *   @0x263b2c ldr r10, [sp, #0x84]
 *   @0x263b30 ldr r6, [sp, #0x104]
 *   @0x263b34 movhi r12, #1
 *   @0x263b38 str r12, [sp, #0x68]
 *   @0x263b3c ldr r12, [sp, #0x4c]
 *   @0x263b40 cmn r12, #2
 *   @0x263b44 mvneq r12, #0
 *   @0x263b48 str r12, [sp, #0x4c]
 *   @0x263b4c ldr r12, [sp, #0x68]
 *   @0x263b50 cmp r12, #0
 *   @0x263b54 beq 0x263c3c <_pcre_ord2utf+0x3ea4>
 *   @0x263b58 ldr r12, [sp, #0x74]
 *   @0x263b5c cmp r12, #0
 *   @0x263b60 beq 0x263b70 <_pcre_ord2utf+0x3dd8>
 *   @0x263b64 ldr r12, [sp, #0x40]
 *   @0x263b68 tst r12, #536870912
 *   @0x263b6c beq 0x263c3c <_pcre_ord2utf+0x3ea4>
 *   @0x263b70 ldr r4, [sp, #0x50]
 *   @0x263b74 cmp r7, #0
 *   @0x263b78 add r2, r3, #1
 *   @0x263b7c str r2, [sp, #0x144]
 *   @0x263b80 mov r2, #0
 *   @0x263b84 strb r2, [r3]
 *   @0x263b88 mov r3, #112
 *   @0x263b8c strb r4, [r6, #0x3]
 *   @0x263b90 strb r3, [r6]
 *   @0x263b94 ble 0x2644f0 <_pcre_ord2utf+0x4758>
 *   @0x263b98 orr r3, r4, #2
 *   @0x263b9c strb r3, [r6, #0x3]
 *   @0x263ba0 ldr r2, [sp, #0x144]
 *   @0x263ba4 add r0, r6, #36
 *   @0x263ba8 mov r1, r8
 *   @0x263bac rsb r2, r8, r2
 *   @0x263bb0 bl 0xb6694 <memmove@plt>
 *   @0x263bb4 cmp r4, #0
 *   @0x263bb8 bne 0x263cb8 <_pcre_ord2utf+0x3f20>
 *   @0x263bbc mov r4, r11
 *   @0x263bc0 ldr r12, [sp, #0x144]
 *   @0x263bc4 ldm r4!, {r0, r1, r2, r3}
 *   @0x263bc8 add r12, r12, #32
 *   @0x263bcc str r0, [r8]
 *   @0x263bd0 str r1, [r8, #0x4]
 *   @0x263bd4 str r2, [r8, #0x8]
 *   @0x263bd8 str r3, [r8, #0xc]
 *   @0x263bdc ldm r4!, {r0, r1, r2, r3}
 *   @0x263be0 str r0, [r8, #0x10]
 *   @0x263be4 str r1, [r8, #0x14]
 *   @0x263be8 str r2, [r8, #0x18]
 *   @0x263bec str r3, [r8, #0x1c]
 *   @0x263bf0 rsb r3, r6, r12
 *   @0x263bf4 mov r8, r6
 *   @0x263bf8 strb r3, [r6, #0x2]
 *   @0x263bfc asr r3, r3, #8
 *   @0x263c00 strb r3, [r6, #0x1]
 *   @0x263c04 mov r6, r12
 *   @0x263c08 ldr r12, [sp, #0x64]
 *   @0x263c0c ldr r0, [sp, #0x4c]
 *   @0x263c10 ldr r11, [sp, #0x13c]
 *   @0x263c14 str r12, [sp, #0x78]
 *   @0x263c18 ldr r12, [sp, #0x70]
 *   @0x263c1c str r0, [sp, #0x58]
 *   @0x263c20 ldr r7, [r9, #0x10]
 *   @0x263c24 str r12, [sp, #0x80]
 *   @0x263c28 ldr r12, [sp, #0x6c]
 *   @0x263c2c str r12, [sp, #0x74]
 *   @0x263c30 mov r12, #0
 *   @0x263c34 str r12, [sp, #0x94]
 *   @0x263c38 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x263c3c ldr r12, [sp, #0xf0]
 *   @0x263c40 ldr r0, [sp, #0x74]
 *   @0x263c44 cmp r12, #0
 *   @0x263c48 rsbne r3, r8, r3
 *   @0x263c4c ldrne r12, [sp, #0x3c]
 *   @0x263c50 ldrne r2, [r12]
 *   @0x263c54 addne r3, r2, r3
 *   @0x263c58 strne r3, [r12]
 *   @0x263c5c ldr r12, [sp, #0x50]
 *   @0x263c60 cmp r12, r0
 *   @0x263c64 ldr r12, [sp, #0x3c]
 *   @0x263c68 movne r3, #111
 *   @0x263c6c moveq r3, #110
 *   @0x263c70 cmp r12, #0
 *   @0x263c74 strb r3, [r6]
 *   @0x263c78 beq 0x264554 <_pcre_ord2utf+0x47bc>
 *   @0x263c7c ldr r12, [sp, #0x4c]
 *   @0x263c80 mov r8, r6
 *   @0x263c84 ldr r11, [sp, #0x13c]
 *   @0x263c88 add r6, r6, #33
 *   @0x263c8c ldr r7, [r9, #0x10]
 *   @0x263c90 str r12, [sp, #0x58]
 *   @0x263c94 ldr r12, [sp, #0x64]
 *   @0x263c98 str r12, [sp, #0x78]
 *   @0x263c9c ldr r12, [sp, #0x70]
 *   @0x263ca0 str r12, [sp, #0x80]
 *   @0x263ca4 ldr r12, [sp, #0x6c]
 *   @0x263ca8 str r12, [sp, #0x74]
 *   @0x263cac mov r12, #0
 *   @0x263cb0 str r12, [sp, #0x94]
 *   @0x263cb4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x263cb8 add r2, sp, #404
 *   @0x263cbc mov r3, r11
 *   @0x263cc0 ldrb r1, [r3]
 *   @0x263cc4 mvn r1, r1
 *   @0x263cc8 strb r1, [r3], #1
 *   @0x263ccc cmp r3, r2
 *   @0x263cd0 bne 0x263cc0 <_pcre_ord2utf+0x3f28>
 *   @0x263cd4 b 0x263bbc <_pcre_ord2utf+0x3e24>
 *   @0x263cd8 mov r3, #1
 *   @0x263cdc str r3, [r9, #0x7c]
 *   @0x263ce0 add r2, r0, #3
 *   @0x263ce4 mov r5, #0
 *   @0x263ce8 ldr r0, [sp, #0x40]
 *   @0x263cec mov r4, #131
 *   @0x263cf0 str r2, [sp, #0x13c]
 *   @0x263cf4 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x263cf8 add r3, r0, #3
 *   @0x263cfc str r3, [sp, #0x13c]
 *   @0x263d00 ldrb r2, [r0, #0x3]
 *   @0x263d04 cmp r2, #41
 *   @0x263d08 bne 0x263e94 <_pcre_ord2utf+0x40fc>
 *   @0x263d0c mov r4, #0
 *   @0x263d10 b 0x263108 <_pcre_ord2utf+0x3370>
 *   @0x263d14 add r3, r0, #3
 *   @0x263d18 str r3, [sp, #0x13c]
 *   @0x263d1c ldrb r1, [r0, #0x3]
 *   @0x263d20 sub r2, r1, #61
 *   @0x263d24 cmp r2, #1
 *   @0x263d28 bls 0x2659ac <_pcre_ord2utf+0x5c14>
 *   @0x263d2c cmp r1, #60
 *   @0x263d30 bne 0x265998 <_pcre_ord2utf+0x5c00>
 *   @0x263d34 mov r12, r3
 *   @0x263d38 mov r4, #62
 *   @0x263d3c add r3, r12, #1
 *   @0x263d40 str r3, [sp, #0x50]
 *   @0x263d44 str r3, [sp, #0x13c]
 *   @0x263d48 ldrb r3, [r12, #0x1]
 *   @0x263d4c sub r2, r3, #48
 *   @0x263d50 cmp r2, #9
 *   @0x263d54 bls 0x265500 <_pcre_ord2utf+0x5768>
 *   @0x263d58 ldr r1, [r9, #0xc]
 *   @0x263d5c ldrb r2, [r1, r3]
 *   @0x263d60 and r2, r2, #16
 *   @0x263d64 ands r2, r2, #255
 *   @0x263d68 moveq r7, r2
 *   @0x263d6c beq 0x263d94 <_pcre_ord2utf+0x3ffc>
 *   @0x263d70 add r2, r12, #2
 *   @0x263d74 str r2, [sp, #0x13c]
 *   @0x263d78 mov r7, r2
 *   @0x263d7c ldrb r3, [r2], #1
 *   @0x263d80 ldrb r0, [r1, r3]
 *   @0x263d84 tst r0, #16
 *   @0x263d88 bne 0x263d74 <_pcre_ord2utf+0x3fdc>
 *   @0x263d8c ldr r12, [sp, #0x50]
 *   @0x263d90 rsb r7, r12, r7
 *   @0x263d94 ldr r12, [sp, #0x3c]
 *   @0x263d98 cmp r12, #0
 *   @0x263d9c beq 0x264060 <_pcre_ord2utf+0x42c8>
 *   @0x263da0 cmp r3, r4
 *   @0x263da4 ldr r3, [r9, #0x40]
 *   @0x263da8 add r11, r3, #1
 *   @0x263dac str r3, [sp, #0x84]
 *   @0x263db0 bne 0x26404c <_pcre_ord2utf+0x42b4>
 *   @0x263db4 ldr r4, [r9, #0x30]
 *   @0x263db8 movw r2, #0x270f
 *   @0x263dbc cmp r4, r2
 *   @0x263dc0 bgt 0x263f5c <_pcre_ord2utf+0x41c4>
 *   @0x263dc4 ldr r2, [r9, #0x34]
 *   @0x263dc8 add r1, r7, #2
 *   @0x263dcc cmp r1, r2
 *   @0x263dd0 blt 0x263de4 <_pcre_ord2utf+0x404c>
 *   @0x263dd4 cmp r7, #32
 *   @0x263dd8 add r2, r7, #3
 *   @0x263ddc str r2, [r9, #0x34]
 *   @0x263de0 bgt 0x265ab8 <_pcre_ord2utf+0x5d20>
 *   @0x263de4 ldr r3, [r9, #0x28]
 *   @0x263de8 cmp r4, #0
 *   @0x263dec str r3, [sp, #0x68]
 *   @0x263df0 mov r5, r3
 *   @0x263df4 ble 0x263f10 <_pcre_ord2utf+0x4178>
 *   @0x263df8 ldr r12, [sp, #0x40]
 *   @0x263dfc ands r8, r12, #524288
 *   @0x263e00 add r12, r4, r4, lsl #1
 *   @0x263e04 beq 0x263ea8 <_pcre_ord2utf+0x4110>
 *   @0x263e08 add r5, r3, #12
 *   @0x263e0c str r4, [sp, #0x88]
 *   @0x263e10 add r12, r5, r12, lsl #2
 *   @0x263e14 mov r8, #0
 *   @0x263e18 mov r3, #1
 *   @0x263e1c mov r4, r12
 *   @0x263e20 b 0x263e40 <_pcre_ord2utf+0x40a8>
 *   @0x263e24 ldr r2, [r5, #-0x4]
 *   @0x263e28 cmp r11, r2
 *   @0x263e2c beq 0x26406c <_pcre_ord2utf+0x42d4>
 *   @0x263e30 add r5, r5, #12
 *   @0x263e34 add r8, r8, #1
 *   @0x263e38 cmp r5, r4
 *   @0x263e3c beq 0x263e8c <_pcre_ord2utf+0x40f4>
 *   @0x263e40 ldr r2, [r5, #-0x8]
 *   @0x263e44 cmp r2, r7
 *   @0x263e48 bne 0x263e24 <_pcre_ord2utf+0x408c>
 *   @0x263e4c ldr r1, [r5, #-0xc]
 *   @0x263e50 mov r2, r7
 *   @0x263e54 ldr r0, [sp, #0x50]
 *   @0x263e58 str r3, [sp, #0x38]
 *   @0x263e5c bl 0xb65e0 <strncmp@plt>
 *   @0x263e60 ldr r3, [sp, #0x38]
 *   @0x263e64 cmp r0, #0
 *   @0x263e68 bne 0x263e24 <_pcre_ord2utf+0x408c>
 *   @0x263e6c ldr r2, [r5, #-0x4]
 *   @0x263e70 cmp r11, r2
 *   @0x263e74 beq 0x263f04 <_pcre_ord2utf+0x416c>
 *   @0x263e78 add r5, r5, #12
 *   @0x263e7c str r3, [r9, #0x78]
 *   @0x263e80 cmp r5, r4
 *   @0x263e84 add r8, r8, #1
 *   @0x263e88 bne 0x263e40 <_pcre_ord2utf+0x40a8>
 *   @0x263e8c ldr r4, [sp, #0x88]
 *   @0x263e90 b 0x263f10 <_pcre_ord2utf+0x4178>
 *   @0x263e94 ldr r12, [sp, #0x48]
 *   @0x263e98 mov r11, r3
 *   @0x263e9c mov r3, #29
 *   @0x263ea0 str r3, [r12]
 *   @0x263ea4 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x263ea8 ldr r0, [sp, #0x68]
 *   @0x263eac str r9, [sp, #0x88]
 *   @0x263eb0 mov r9, r6
 *   @0x263eb4 add r12, r0, r12, lsl #2
 *   @0x263eb8 add r3, r0, #12
 *   @0x263ebc mov r6, r12
 *   @0x263ec0 mov r12, r4
 *   @0x263ec4 mov r4, r3
 *   @0x263ec8 ldr r2, [r4, #-0x8]
 *   @0x263ecc cmp r2, r7
 *   @0x263ed0 beq 0x264000 <_pcre_ord2utf+0x4268>
 *   @0x263ed4 ldr r2, [r5, #0x8]
 *   @0x263ed8 cmp r11, r2
 *   @0x263edc beq 0x26406c <_pcre_ord2utf+0x42d4>
 *   @0x263ee0 add r5, r5, #12
 *   @0x263ee4 add r8, r8, #1
 *   @0x263ee8 cmp r5, r6
 *   @0x263eec add r4, r4, #12
 *   @0x263ef0 bne 0x263ec8 <_pcre_ord2utf+0x4130>
 *   @0x263ef4 mov r6, r9
 *   @0x263ef8 mov r4, r12
 *   @0x263efc ldr r9, [sp, #0x88]
 *   @0x263f00 b 0x263f10 <_pcre_ord2utf+0x4178>
 *   @0x263f04 ldr r4, [sp, #0x88]
 *   @0x263f08 cmp r4, r8
 *   @0x263f0c bgt 0x263f54 <_pcre_ord2utf+0x41bc>
 *   @0x263f10 ldr r2, [r9, #0x38]
 *   @0x263f14 cmp r4, r2
 *   @0x263f18 bge 0x263f70 <_pcre_ord2utf+0x41d8>
 *   @0x263f1c ldr r2, [sp, #0x68]
 *   @0x263f20 ldr r12, [sp, #0x84]
 *   @0x263f24 add r0, r4, r4, lsl #1
 *   @0x263f28 add r4, r4, #1
 *   @0x263f2c add r3, r12, #1
 *   @0x263f30 ldr r12, [sp, #0x50]
 *   @0x263f34 add r1, r2, r0, lsl #2
 *   @0x263f38 str r12, [r2, r0, lsl #2]
 *   @0x263f3c stmib r1, {r7, r11}
 *   @0x263f40 str r4, [r9, #0x30]
 *   @0x263f44 ldr r2, [sp, #0x13c]
 *   @0x263f48 add r2, r2, #1
 *   @0x263f4c str r2, [sp, #0x13c]
 *   @0x263f50 b 0x260858 <_pcre_ord2utf+0xac0>
 *   @0x263f54 mov r3, r11
 *   @0x263f58 b 0x263f44 <_pcre_ord2utf+0x41ac>
 *   @0x263f5c ldr r12, [sp, #0x48]
 *   @0x263f60 mov r3, #49
 *   @0x263f64 ldr r11, [sp, #0x13c]
 *   @0x263f68 str r3, [r12]
 *   @0x263f6c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x263f70 ldr r12, [sp, #0xa0]
 *   @0x263f74 lsl r8, r2, #1
 *   @0x263f78 ldr r3, [pc, #-0xc10]
 *   @0x263f7c add r0, r8, r2, lsl #2
 *   @0x263f80 lsl r0, r0, #2
 *   @0x263f84 ldr r3, [r12, r3]
 *   @0x263f88 ldr r3, [r3]
 *   @0x263f8c blx r3
 *   @0x263f90 subs r5, r0, #0
 *   @0x263f94 beq 0x263fec <_pcre_ord2utf+0x4254>
 *   @0x263f98 ldr r3, [r9, #0x38]
 *   @0x263f9c ldr r1, [r9, #0x28]
 *   @0x263fa0 add r2, r3, r3, lsl #1
 *   @0x263fa4 lsl r2, r2, #2
 *   @0x263fa8 bl 0xb65bc <memcpy@plt>
 *   @0x263fac ldr r3, [r9, #0x38]
 *   @0x263fb0 cmp r3, #20
 *   @0x263fb4 ble 0x263fd0 <_pcre_ord2utf+0x4238>
 *   @0x263fb8 ldr r3, [pc, #-0xc4c]
 *   @0x263fbc ldr r12, [sp, #0xa0]
 *   @0x263fc0 ldr r0, [r9, #0x28]
 *   @0x263fc4 ldr r3, [r12, r3]
 *   @0x263fc8 ldr r3, [r3]
 *   @0x263fcc blx r3
 *   @0x263fd0 ldr r3, [r9, #0x40]
 *   @0x263fd4 mov r2, r5
 *   @0x263fd8 ldr r4, [r9, #0x30]
 *   @0x263fdc str r5, [r9, #0x28]
 *   @0x263fe0 str r3, [sp, #0x84]
 *   @0x263fe4 str r8, [r9, #0x38]
 *   @0x263fe8 b 0x263f20 <_pcre_ord2utf+0x4188>
 *   @0x263fec ldr r12, [sp, #0x48]
 *   @0x263ff0 mov r3, #21
 *   @0x263ff4 ldr r11, [sp, #0x13c]
 *   @0x263ff8 str r3, [r12]
 *   @0x263ffc b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x264000 ldr r1, [r4, #-0xc]
 *   @0x264004 mov r2, r7
 *   @0x264008 ldr r0, [sp, #0x50]
 *   @0x26400c str r12, [sp, #0x34]
 *   @0x264010 bl 0xb65e0 <strncmp@plt>
 *   @0x264014 ldr r12, [sp, #0x34]
 *   @0x264018 cmp r0, #0
 *   @0x26401c bne 0x263ed4 <_pcre_ord2utf+0x413c>
 *   @0x264020 ldr r2, [r5, #0x8]
 *   @0x264024 mov r6, r9
 *   @0x264028 mov r4, r12
 *   @0x26402c ldr r9, [sp, #0x88]
 *   @0x264030 cmp r11, r2
 *   @0x264034 beq 0x263f08 <_pcre_ord2utf+0x4170>
 *   @0x264038 ldr r12, [sp, #0x48]
 *   @0x26403c mov r3, #43
 *   @0x264040 ldr r11, [sp, #0x13c]
 *   @0x264044 str r3, [r12]
 *   @0x264048 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x26404c ldr r12, [sp, #0x48]
 *   @0x264050 mov r3, #42
 *   @0x264054 ldr r11, [sp, #0x13c]
 *   @0x264058 str r3, [r12]
 *   @0x26405c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x264060 ldr r3, [r9, #0x40]
 *   @0x264064 add r3, r3, #1
 *   @0x264068 b 0x263f44 <_pcre_ord2utf+0x41ac>
 *   @0x26406c ldr r12, [sp, #0x48]
 *   @0x264070 mov r3, #65
 *   @0x264074 ldr r11, [sp, #0x13c]
 *   @0x264078 str r3, [r12]
 *   @0x26407c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x264080 ldr r12, [sp, #0x158]
 *   @0x264084 cmp r12, #0
 *   @0x264088 str r12, [sp, #0x4c]
 *   @0x26408c blt 0x2640e4 <_pcre_ord2utf+0x434c>
 *   @0x264090 ldr r1, [sp, #0x14c]
 *   @0x264094 mov r12, #1
 *   @0x264098 ldr r2, [sp, #0x154]
 *   @0x26409c str r12, [sp, #0x9c]
 *   @0x2640a0 mvn r12, #0
 *   @0x2640a4 str r12, [sp, #0x58]
 *   @0x2640a8 cmp r2, #0
 *   @0x2640ac bge 0x262cb0 <_pcre_ord2utf+0x2f18>
 *   @0x2640b0 ldr r12, [sp, #0x70]
 *   @0x2640b4 mov r11, r3
 *   @0x2640b8 str r1, [sp, #0x70]
 *   @0x2640bc ldr r7, [r9, #0x10]
 *   @0x2640c0 str r12, [sp, #0x80]
 *   @0x2640c4 ldr r12, [sp, #0x64]
 *   @0x2640c8 str r12, [sp, #0x78]
 *   @0x2640cc ldr r12, [sp, #0x6c]
 *   @0x2640d0 str r12, [sp, #0x74]
 *   @0x2640d4 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2640d8 mov r11, r3
 *   @0x2640dc ldr r7, [r9, #0x10]
 *   @0x2640e0 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2640e4 mvn r12, #0
 *   @0x2640e8 str r12, [sp, #0x58]
 *   @0x2640ec str r12, [sp, #0x4c]
 *   @0x2640f0 ldr r12, [sp, #0x3c]
 *   @0x2640f4 ldr r2, [sp, #0x154]
 *   @0x2640f8 ldr r1, [sp, #0x70]
 *   @0x2640fc str r12, [sp, #0x9c]
 *   @0x264100 b 0x2640a8 <_pcre_ord2utf+0x4310>
 *   @0x264104 ldr r12, [sp, #0x50]
 *   @0x264108 ldr r0, [sp, #0x14c]
 *   @0x26410c orr r11, r1, r12
 *   @0x264110 ldr r12, [sp, #0x4c]
 *   @0x264114 ldr r1, [sp, #0x70]
 *   @0x264118 mov r2, r11
 *   @0x26411c str r11, [sp, #0x154]
 *   @0x264120 str r12, [sp, #0x58]
 *   @0x264124 ldr r12, [sp, #0x3c]
 *   @0x264128 str r0, [sp, #0x148]
 *   @0x26412c str r12, [sp, #0x9c]
 *   @0x264130 b 0x2640a8 <_pcre_ord2utf+0x4310>
 *   @0x264134 ldr r12, [sp, #0x4c]
 *   @0x264138 ldr r1, [sp, #0x70]
 *   @0x26413c str r12, [sp, #0x58]
 *   @0x264140 ldr r12, [sp, #0x3c]
 *   @0x264144 str r12, [sp, #0x9c]
 *   @0x264148 b 0x2640a8 <_pcre_ord2utf+0x4310>
 *   @0x26414c and r4, r7, #7
 *   @0x264150 mov r0, r3
 *   @0x264154 add r1, sp, #348
 *   @0x264158 str r12, [sp, #0x34]
 *   @0x26415c mov r2, r4
 *   @0x264160 bl 0xb65bc <memcpy@plt>
 *   @0x264164 ldr r12, [sp, #0x34]
 *   @0x264168 add r3, r0, r4
 *   @0x26416c b 0x262c54 <_pcre_ord2utf+0x2ebc>
 *   @0x264170 ldr r4, [sp, #0x13c]
 *   @0x264174 ldr r12, [sp, #0x48]
 *   @0x264178 ldrb r3, [r4, #0x1]
 *   @0x26417c cmp r3, #58
 *   @0x264180 movne r3, #31
 *   @0x264184 moveq r3, #13
 *   @0x264188 str r3, [r12]
 *   @0x26418c b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264190 ldr r12, [sp, #0xac]
 *   @0x264194 orr r5, r5, r12
 *   @0x264198 b 0x261a5c <_pcre_ord2utf+0x1cc4>
 *   @0x26419c ldr r12, [sp, #0xb8]
 *   @0x2641a0 str r12, [sp, #0xac]
 *   @0x2641a4 ldr r12, [sp, #0xcc]
 *   @0x2641a8 str r12, [sp, #0xa4]
 *   @0x2641ac b 0x262b80 <_pcre_ord2utf+0x2de8>
 *   @0x2641b0 ldr r12, [sp, #0xcc]
 *   @0x2641b4 ldr r0, [sp, #0x70]
 *   @0x2641b8 cmp r12, r0
 *   @0x2641bc bne 0x262b74 <_pcre_ord2utf+0x2ddc>
 *   @0x2641c0 b 0x262bb4 <_pcre_ord2utf+0x2e1c>
 *   @0x2641c4 cmn r0, #2
 *   @0x2641c8 moveq r0, #36
 *   @0x2641cc beq 0x2641dc <_pcre_ord2utf+0x4444>
 *   @0x2641d0 cmn r0, #4
 *   @0x2641d4 movne r0, #25
 *   @0x2641d8 moveq r0, #70
 *   @0x2641dc ldr r12, [sp, #0x48]
 *   @0x2641e0 str r0, [r12]
 *   @0x2641e4 mov r0, #0
 *   @0x2641e8 ldr r12, [sp, #0xc4]
 *   @0x2641ec str r4, [r12]
 *   @0x2641f0 b 0x260df0 <_pcre_ord2utf+0x1058>
 *   @0x2641f4 cmn r11, #1
 *   @0x2641f8 ldr r12, [sp, #0x50]
 *   @0x2641fc strb r5, [r6, #0x2]
 *   @0x264200 asr r5, r5, #8
 *   @0x264204 moveq r2, #0
 *   @0x264208 add r3, r12, #104
 *   @0x26420c strb r5, [r6, #0x1]
 *   @0x264210 strb r3, [r6]
 *   @0x264214 moveq r3, r2
 *   @0x264218 beq 0x2616c8 <_pcre_ord2utf+0x1930>
 *   @0x26421c b 0x2616c0 <_pcre_ord2utf+0x1928>
 *   @0x264220 eor r3, r6, #1
 *   @0x264224 and r3, r3, #1
 *   @0x264228 b 0x2624d4 <_pcre_ord2utf+0x273c>
 *   @0x26422c ldr r12, [sp, #0x48]
 *   @0x264230 mov r3, #8
 *   @0x264234 str r3, [r12]
 *   @0x264238 ldr r4, [sp, #0x13c]
 *   @0x26423c b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264240 ldrb r1, [r10, r3]
 *   @0x264244 ldrb r2, [r5, r3]
 *   @0x264248 bic r2, r2, r1
 *   @0x26424c strb r2, [r5, r3]
 *   @0x264250 add r3, r3, #1
 *   @0x264254 cmp r3, #32
 *   @0x264258 bne 0x264240 <_pcre_ord2utf+0x44a8>
 *   @0x26425c rsb r7, r7, #0
 *   @0x264260 b 0x26426c <_pcre_ord2utf+0x44d4>
 *   @0x264264 cmp r7, #0
 *   @0x264268 blt 0x26425c <_pcre_ord2utf+0x44c4>
 *   @0x26426c cmp r7, #1
 *   @0x264270 beq 0x2642ec <_pcre_ord2utf+0x4554>
 *   @0x264274 cmp r7, #2
 *   @0x264278 ldrbeq r3, [sp, #0x19f]
 *   @0x26427c andeq r3, r3, #127
 *   @0x264280 strbeq r3, [sp, #0x19f]
 *   @0x264284 ldr r12, [sp, #0x8c]
 *   @0x264288 cmp r12, #0
 *   @0x26428c beq 0x2642c8 <_pcre_ord2utf+0x4530>
 *   @0x264290 mov r3, #0
 *   @0x264294 ldrb r1, [r5, r3]
 *   @0x264298 ldrb r2, [r3, r11]
 *   @0x26429c mvn r1, r1
 *   @0x2642a0 orr r2, r1, r2
 *   @0x2642a4 strb r2, [r3, r11]
 *   @0x2642a8 add r3, r3, #1
 *   @0x2642ac cmp r3, #32
 *   @0x2642b0 bne 0x264294 <_pcre_ord2utf+0x44fc>
 *   @0x2642b4 ldr r12, [sp, #0xc0]
 *   @0x2642b8 mov r5, #2
 *   @0x2642bc mov r7, #1
 *   @0x2642c0 add r3, r12, #1
 *   @0x2642c4 b 0x262524 <_pcre_ord2utf+0x278c>
 *   @0x2642c8 ldr r3, [sp, #0x8c]
 *   @0x2642cc ldrb r2, [r3, r11]
 *   @0x2642d0 ldrb r1, [r5, r3]
 *   @0x2642d4 orr r2, r1, r2
 *   @0x2642d8 strb r2, [r3, r11]
 *   @0x2642dc add r3, r3, #1
 *   @0x2642e0 cmp r3, #32
 *   @0x2642e4 bne 0x2642cc <_pcre_ord2utf+0x4534>
 *   @0x2642e8 b 0x2642b4 <_pcre_ord2utf+0x451c>
 *   @0x2642ec ldrb r3, [sp, #0x195]
 *   @0x2642f0 bic r3, r3, #60
 *   @0x2642f4 strb r3, [sp, #0x195]
 *   @0x2642f8 b 0x264284 <_pcre_ord2utf+0x44ec>
 *   @0x2642fc cmp r4, #2
 *   @0x264300 movle r3, #2
 *   @0x264304 movle r2, #1
 *   @0x264308 ble 0x262988 <_pcre_ord2utf+0x2bf0>
 *   @0x26430c b 0x26297c <_pcre_ord2utf+0x2be4>
 *   @0x264310 ldr r0, [sp, #0x48]
 *   @0x264314 mov r12, r8
 *   @0x264318 mov r3, #30
 *   @0x26431c str r3, [r0]
 *   @0x264320 mov r4, r12
 *   @0x264324 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264328 add r3, r3, #3
 *   @0x26432c mov r12, #1
 *   @0x264330 str r3, [sp, #0x13c]
 *   @0x264334 str r12, [sp, #0x74]
 *   @0x264338 mov r7, r3
 *   @0x26433c str r12, [sp, #0x8c]
 *   @0x264340 b 0x2628d4 <_pcre_ord2utf+0x2b3c>
 *   @0x264344 ldr r0, [sp, #0x50]
 *   @0x264348 add r3, r3, #1
 *   @0x26434c ldr r10, [sp, #0x84]
 *   @0x264350 cmp r0, #0
 *   @0x264354 ldr r6, [sp, #0x104]
 *   @0x264358 str r3, [sp, #0x13c]
 *   @0x26435c beq 0x264ab8 <_pcre_ord2utf+0x4d20>
 *   @0x264360 ldr r12, [sp, #0x4c]
 *   @0x264364 add r5, r6, #1
 *   @0x264368 cmn r12, #2
 *   @0x26436c mvneq r12, #0
 *   @0x264370 str r12, [sp, #0x4c]
 *   @0x264374 ldr r12, [sp, #0x58]
 *   @0x264378 cmp r4, #127
 *   @0x26437c movls r3, #0
 *   @0x264380 andhi r3, r10, #1
 *   @0x264384 cmp r12, #0
 *   @0x264388 moveq r2, #31
 *   @0x26438c movne r2, #32
 *   @0x264390 cmp r3, #0
 *   @0x264394 strb r2, [r6]
 *   @0x264398 bne 0x2643c0 <_pcre_ord2utf+0x4628>
 *   @0x26439c ldr r12, [sp, #0x4c]
 *   @0x2643a0 mov r8, r6
 *   @0x2643a4 strb r4, [r6, #0x1]
 *   @0x2643a8 add r6, r6, #2
 *   @0x2643ac str r3, [sp, #0x94]
 *   @0x2643b0 ldr r11, [sp, #0x13c]
 *   @0x2643b4 ldr r7, [r9, #0x10]
 *   @0x2643b8 str r12, [sp, #0x58]
 *   @0x2643bc b 0x260bf0 <_pcre_ord2utf+0xe58>
 *   @0x2643c0 mov r0, r4
 *   @0x2643c4 mov r1, r5
 *   @0x2643c8 bl 0x25fd98 <_pcre_ord2utf>
 *   @0x2643cc ldr r12, [sp, #0x4c]
 *   @0x2643d0 mov r8, r6
 *   @0x2643d4 ldr r11, [sp, #0x13c]
 *   @0x2643d8 ldr r7, [r9, #0x10]
 *   @0x2643dc str r12, [sp, #0x58]
 *   @0x2643e0 ldr r12, [sp, #0x64]
 *   @0x2643e4 str r12, [sp, #0x78]
 *   @0x2643e8 ldr r12, [sp, #0x70]
 *   @0x2643ec str r12, [sp, #0x80]
 *   @0x2643f0 ldr r12, [sp, #0x6c]
 *   @0x2643f4 str r12, [sp, #0x74]
 *   @0x2643f8 mov r12, #0
 *   @0x2643fc str r12, [sp, #0x94]
 *   @0x264400 add r6, r5, r0
 *   @0x264404 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x264408 ldr r0, [sp, #0x48]
 *   @0x26440c mov r12, r3
 *   @0x264410 mov r3, #31
 *   @0x264414 str r3, [r0]
 *   @0x264418 b 0x264320 <_pcre_ord2utf+0x4588>
 *   @0x26441c ldr r3, [r9, #0x40]
 *   @0x264420 mov lr, #1
 *   @0x264424 add r0, sp, #316
 *   @0x264428 str r8, [sp]
 *   @0x26442c add r1, sp, #344
 *   @0x264430 str lr, [sp, #0x4]
 *   @0x264434 ldr r2, [sp, #0x48]
 *   @0x264438 bl 0x25ceac <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1d84>
 *   @0x26443c ldr r12, [sp, #0x48]
 *   @0x264440 ldr r3, [r12]
 *   @0x264444 cmp r3, #0
 *   @0x264448 bne 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x26444c cmp r0, #0
 *   @0x264450 beq 0x2627b0 <_pcre_ord2utf+0x2a18>
 *   @0x264454 cmp r0, #5
 *   @0x264458 moveq r2, #8
 *   @0x26445c streq r2, [sp, #0x158]
 *   @0x264460 beq 0x2627b4 <_pcre_ord2utf+0x2a1c>
 *   @0x264464 ldr r12, [sp, #0x48]
 *   @0x264468 mov r3, #83
 *   @0x26446c str r3, [r12]
 *   @0x264470 b 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x264474 tst r2, #16
 *   @0x264478 bne 0x264514 <_pcre_ord2utf+0x477c>
 *   @0x26447c ldrb r0, [r3, #0x2]
 *   @0x264480 lsl r2, r2, #12
 *   @0x264484 ldrb r1, [r3, #0x1]
 *   @0x264488 add r3, r3, #2
 *   @0x26448c uxth r2, r2
 *   @0x264490 and r0, r0, #63
 *   @0x264494 and r1, r1, #63
 *   @0x264498 orr r2, r0, r2
 *   @0x26449c str r3, [sp, #0x13c]
 *   @0x2644a0 orr r2, r2, r1, lsl #6
 *   @0x2644a4 str r2, [sp, #0x158]
 *   @0x2644a8 b 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x2644ac ldrb r12, [r3, #0x4]
 *   @0x2644b0 mov r0, r3
 *   @0x2644b4 add r3, r3, #4
 *   @0x2644b8 cmp r12, #92
 *   @0x2644bc bne 0x2645e8 <_pcre_ord2utf+0x4850>
 *   @0x2644c0 ldrb r10, [r0, #0x5]
 *   @0x2644c4 cmp r10, #81
 *   @0x2644c8 bne 0x264590 <_pcre_ord2utf+0x47f8>
 *   @0x2644cc ldrb r12, [r0, #0x6]
 *   @0x2644d0 add r0, r0, #6
 *   @0x2644d4 cmp r12, #92
 *   @0x2644d8 bne 0x2644f8 <_pcre_ord2utf+0x4760>
 *   @0x2644dc ldrb r12, [r3, #0x3]
 *   @0x2644e0 cmp r12, #69
 *   @0x2644e4 beq 0x2644ac <_pcre_ord2utf+0x4714>
 *   @0x2644e8 str r0, [sp, #0x13c]
 *   @0x2644ec b 0x262728 <_pcre_ord2utf+0x2990>
 *   @0x2644f0 ldr r12, [sp, #0x144]
 *   @0x2644f4 b 0x263bf0 <_pcre_ord2utf+0x3e58>
 *   @0x2644f8 mov r2, r12
 *   @0x2644fc str r0, [sp, #0x13c]
 *   @0x264500 cmp r2, #0
 *   @0x264504 bne 0x262728 <_pcre_ord2utf+0x2990>
 *   @0x264508 mov r3, r2
 *   @0x26450c mov r6, #1
 *   @0x264510 b 0x2626c0 <_pcre_ord2utf+0x2928>
 *   @0x264514 tst r2, #8
 *   @0x264518 bne 0x26459c <_pcre_ord2utf+0x4804>
 *   @0x26451c ldrb r12, [r3, #0x3]
 *   @0x264520 and r2, r2, #7
 *   @0x264524 ldrb r1, [r3, #0x1]
 *   @0x264528 add r3, r3, #3
 *   @0x26452c ldrb r0, [r3, #-0x1]
 *   @0x264530 and r12, r12, #63
 *   @0x264534 and r1, r1, #63
 *   @0x264538 orr r12, r12, r2, lsl #18
 *   @0x26453c and r0, r0, #63
 *   @0x264540 str r3, [sp, #0x13c]
 *   @0x264544 orr r2, r12, r1, lsl #12
 *   @0x264548 orr r2, r2, r0, lsl #6
 *   @0x26454c str r2, [sp, #0x158]
 *   @0x264550 b 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x264554 ldr r12, [sp, #0x50]
 *   @0x264558 cmp r12, #0
 *   @0x26455c bne 0x2645f4 <_pcre_ord2utf+0x485c>
 *   @0x264560 mov r12, r11
 *   @0x264564 ldm r12!, {r0, r1, r2, r3}
 *   @0x264568 str r0, [r6, #0x1]
 *   @0x26456c str r1, [r6, #0x5]
 *   @0x264570 str r2, [r6, #0x9]
 *   @0x264574 str r3, [r6, #0xd]
 *   @0x264578 ldm r12!, {r0, r1, r2, r3}
 *   @0x26457c str r0, [r6, #0x11]
 *   @0x264580 str r1, [r6, #0x15]
 *   @0x264584 str r2, [r6, #0x19]
 *   @0x264588 str r3, [r6, #0x1d]
 *   @0x26458c b 0x263c7c <_pcre_ord2utf+0x3ee4>
 *   @0x264590 str r3, [sp, #0x13c]
 *   @0x264594 mov r2, r12
 *   @0x264598 b 0x262730 <_pcre_ord2utf+0x2998>
 *   @0x26459c tst r2, #4
 *   @0x2645a0 bne 0x264614 <_pcre_ord2utf+0x487c>
 *   @0x2645a4 ldrb r1, [r3, #0x4]
 *   @0x2645a8 and r0, r2, #3
 *   @0x2645ac ldrb r12, [r3, #0x1]
 *   @0x2645b0 add r3, r3, #4
 *   @0x2645b4 ldrb r2, [r3, #-0x2]
 *   @0x2645b8 and r1, r1, #63
 *   @0x2645bc orr r0, r1, r0, lsl #24
 *   @0x2645c0 and r12, r12, #63
 *   @0x2645c4 ldrb r1, [r3, #-0x1]
 *   @0x2645c8 and r2, r2, #63
 *   @0x2645cc orr r0, r0, r12, lsl #18
 *   @0x2645d0 str r3, [sp, #0x13c]
 *   @0x2645d4 and r1, r1, #63
 *   @0x2645d8 orr r2, r0, r2, lsl #12
 *   @0x2645dc orr r2, r2, r1, lsl #6
 *   @0x2645e0 str r2, [sp, #0x158]
 *   @0x2645e4 b 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x2645e8 mov r2, r12
 *   @0x2645ec str r3, [sp, #0x13c]
 *   @0x2645f0 b 0x2626b4 <_pcre_ord2utf+0x291c>
 *   @0x2645f4 add r2, sp, #404
 *   @0x2645f8 mov r3, r11
 *   @0x2645fc ldrb r1, [r3]
 *   @0x264600 mvn r1, r1
 *   @0x264604 strb r1, [r3], #1
 *   @0x264608 cmp r3, r2
 *   @0x26460c bne 0x2645fc <_pcre_ord2utf+0x4864>
 *   @0x264610 b 0x264560 <_pcre_ord2utf+0x47c8>
 *   @0x264614 ldrb r1, [r3, #0x5]
 *   @0x264618 and r2, r2, #1
 *   @0x26461c ldrb r0, [r3, #0x1]
 *   @0x264620 add r3, r3, #5
 *   @0x264624 ldrb r12, [r3, #-0x3]
 *   @0x264628 and r1, r1, #63
 *   @0x26462c and r0, r0, #63
 *   @0x264630 orr r1, r1, r2, lsl #30
 *   @0x264634 ldrb r2, [r3, #-0x2]
 *   @0x264638 and r12, r12, #63
 *   @0x26463c orr r0, r1, r0, lsl #24
 *   @0x264640 ldrb r1, [r3, #-0x1]
 *   @0x264644 and r2, r2, #63
 *   @0x264648 orr r0, r0, r12, lsl #18
 *   @0x26464c and r1, r1, #63
 *   @0x264650 str r3, [sp, #0x13c]
 *   @0x264654 orr r2, r0, r2, lsl #12
 *   @0x264658 orr r2, r2, r1, lsl #6
 *   @0x26465c str r2, [sp, #0x158]
 *   @0x264660 b 0x26276c <_pcre_ord2utf+0x29d4>
 *   @0x264664 ldr r12, [sp, #0x5c]
 *   @0x264668 cmp r11, #0
 *   @0x26466c mov r7, #0
 *   @0x264670 rsbgt r11, r5, r11
 *   @0x264674 mov r4, r7
 *   @0x264678 cmp r11, #0
 *   @0x26467c bge 0x261904 <_pcre_ord2utf+0x1b6c>
 *   @0x264680 ldrb r2, [r6, #-0x2]
 *   @0x264684 sub r12, r6, #3
 *   @0x264688 ldrb r3, [r6, #-0x1]
 *   @0x26468c orr r3, r3, r2, lsl #8
 *   @0x264690 rsb r11, r3, r12
 *   @0x264694 ldrb r8, [r11]
 *   @0x264698 add r3, r8, #127
 *   @0x26469c uxtb r3, r3
 *   @0x2646a0 cmp r3, #1
 *   @0x2646a4 bls 0x264b10 <_pcre_ord2utf+0x4d78>
 *   @0x2646a8 ldr r0, [sp, #0x3c]
 *   @0x2646ac cmp r0, #0
 *   @0x2646b0 beq 0x264890 <_pcre_ord2utf+0x4af8>
 *   @0x2646b4 cmp r8, #135
 *   @0x2646b8 bne 0x2646d8 <_pcre_ord2utf+0x4940>
 *   @0x2646bc ldrb r2, [r11, #0x1]
 *   @0x2646c0 ldrb r3, [r11, #0x2]
 *   @0x2646c4 orr r3, r3, r2, lsl #8
 *   @0x2646c8 ldrb r3, [r11, r3]
 *   @0x2646cc cmp r3, #119
 *   @0x2646d0 mvnne r3, #115
 *   @0x2646d4 strbne r3, [r11]
 *   @0x2646d8 ldr r12, [sp, #0x84]
 *   @0x2646dc cmp r12, #0
 *   @0x2646e0 beq 0x264960 <_pcre_ord2utf+0x4bc8>
 *   @0x2646e4 ldrb r3, [r11]
 *   @0x2646e8 cmp r3, #135
 *   @0x2646ec cmpne r3, #140
 *   @0x2646f0 beq 0x2648e8 <_pcre_ord2utf+0x4b50>
 *   @0x2646f4 add r3, r3, #1
 *   @0x2646f8 strb r3, [r11]
 *   @0x2646fc mov r3, #123
 *   @0x264700 strb r3, [r6, #-0x3]
 *   @0x264704 cmp r7, #0
 *   @0x264708 mvnne r3, #107
 *   @0x26470c strbne r3, [r7]
 *   @0x264710 cmp r5, #1
 *   @0x264714 bgt 0x261000 <_pcre_ord2utf+0x1268>
 *   @0x264718 b 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x26471c subs r11, r11, #1
 *   @0x264720 blo 0x262234 <_pcre_ord2utf+0x249c>
 *   @0x264724 ldr lr, [sp, #0x50]
 *   @0x264728 mov r5, r4
 *   @0x26472c ldr r3, [r9, #0x20]
 *   @0x264730 mov r4, r12
 *   @0x264734 ldr r7, [r9, #0x10]
 *   @0x264738 sub r2, lr, #110
 *   @0x26473c ldr r0, [sp, #0x68]
 *   @0x264740 uxtb r2, r2
 *   @0x264744 str r2, [sp, #0x8c]
 *   @0x264748 add r0, r0, #4
 *   @0x26474c mov r1, r7
 *   @0x264750 str r0, [sp, #0xa8]
 *   @0x264754 mov r0, r3
 *   @0x264758 ldr r3, [sp, #0x8c]
 *   @0x26475c cmp r11, #0
 *   @0x264760 rsb r7, r1, r0
 *   @0x264764 strb r3, [r6]
 *   @0x264768 addeq r6, r6, #1
 *   @0x26476c streq r6, [sp, #0x50]
 *   @0x264770 beq 0x2647ac <_pcre_ord2utf+0x4a14>
 *   @0x264774 cmp r5, #0
 *   @0x264778 add r0, r6, #2
 *   @0x26477c rsbne r3, r5, r0
 *   @0x264780 mvn r12, #124
 *   @0x264784 moveq r2, r5
 *   @0x264788 mov r5, r0
 *   @0x26478c ubfxne r1, r3, #0x8, #0x8
 *   @0x264790 uxtbne r2, r3
 *   @0x264794 moveq r1, r2
 *   @0x264798 add r3, r6, #4
 *   @0x26479c strb r12, [r6, #0x1]
 *   @0x2647a0 str r3, [sp, #0x50]
 *   @0x2647a4 strb r1, [r6, #0x2]
 *   @0x2647a8 strb r2, [r6, #0x3]
 *   @0x2647ac ldr r0, [sp, #0x50]
 *   @0x2647b0 mov r1, r8
 *   @0x2647b4 ldr r2, [sp, #0x68]
 *   @0x2647b8 bl 0xb65bc <memcpy@plt>
 *   @0x2647bc b 0x2647d8 <_pcre_ord2utf+0x4a40>
 *   @0x2647c0 mov r0, r9
 *   @0x2647c4 bl 0x25cd64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c3c>
 *   @0x2647c8 ldr r12, [sp, #0x48]
 *   @0x2647cc cmp r0, #0
 *   @0x2647d0 str r0, [r12]
 *   @0x2647d4 bne 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x2647d8 ldr r3, [r9, #0x3c]
 *   @0x2647dc ldr r1, [r9, #0x10]
 *   @0x2647e0 sub r3, r3, #100
 *   @0x2647e4 ldr r2, [r9, #0x20]
 *   @0x2647e8 rsb r3, r7, r3
 *   @0x2647ec add r3, r3, r4
 *   @0x2647f0 add r3, r1, r3
 *   @0x2647f4 mov r0, r2
 *   @0x2647f8 cmp r2, r3
 *   @0x2647fc bhi 0x2647c0 <_pcre_ord2utf+0x4a28>
 *   @0x264800 add r12, r1, r4
 *   @0x264804 add r6, r1, r7
 *   @0x264808 cmp r12, r6
 *   @0x26480c bhs 0x264870 <_pcre_ord2utf+0x4ad8>
 *   @0x264810 cmp r11, #0
 *   @0x264814 beq 0x264b40 <_pcre_ord2utf+0x4da8>
 *   @0x264818 ldrb r1, [r12]
 *   @0x26481c add r12, r12, #2
 *   @0x264820 ldrb r3, [r12, #-0x1]
 *   @0x264824 ldr r0, [sp, #0x68]
 *   @0x264828 orr r3, r3, r1, lsl #8
 *   @0x26482c ldr r1, [sp, #0xa8]
 *   @0x264830 add r3, r0, r3
 *   @0x264834 add r3, r3, #4
 *   @0x264838 asr r3, r3, #8
 *   @0x26483c strb r3, [r2]
 *   @0x264840 ldr r3, [r9, #0x20]
 *   @0x264844 ldrb r2, [r12, #-0x1]
 *   @0x264848 add r2, r1, r2
 *   @0x26484c strb r2, [r3, #0x1]
 *   @0x264850 ldr r1, [r9, #0x10]
 *   @0x264854 ldr r0, [r9, #0x20]
 *   @0x264858 add r3, r1, r7
 *   @0x26485c add r2, r0, #2
 *   @0x264860 cmp r12, r3
 *   @0x264864 str r2, [r9, #0x20]
 *   @0x264868 mov r0, r2
 *   @0x26486c blo 0x264818 <_pcre_ord2utf+0x4a80>
 *   @0x264870 sub r11, r11, #1
 *   @0x264874 ldr r3, [sp, #0x50]
 *   @0x264878 ldr r12, [sp, #0x68]
 *   @0x26487c cmn r11, #1
 *   @0x264880 add r6, r3, r12
 *   @0x264884 beq 0x264bb0 <_pcre_ord2utf+0x4e18>
 *   @0x264888 mov r4, r7
 *   @0x26488c b 0x264758 <_pcre_ord2utf+0x49c0>
 *   @0x264890 str r8, [sp, #0x68]
 *   @0x264894 mov r4, r11
 *   @0x264898 mov r8, r5
 *   @0x26489c mov r5, r12
 *   @0x2648a0 mov r3, #0
 *   @0x2648a4 mov r0, r4
 *   @0x2648a8 str r3, [sp]
 *   @0x2648ac mov r1, r5
 *   @0x2648b0 mov r2, r10
 *   @0x2648b4 mov r3, r9
 *   @0x2648b8 bl 0x25bbb0 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0xa88>
 *   @0x2648bc cmp r0, #0
 *   @0x2648c0 bne 0x264b2c <_pcre_ord2utf+0x4d94>
 *   @0x2648c4 ldrb r2, [r4, #0x1]
 *   @0x2648c8 ldrb r3, [r4, #0x2]
 *   @0x2648cc orr r3, r3, r2, lsl #8
 *   @0x2648d0 ldrb r3, [r4, r3]!
 *   @0x2648d4 cmp r3, #119
 *   @0x2648d8 beq 0x2648a0 <_pcre_ord2utf+0x4b08>
 *   @0x2648dc mov r5, r8
 *   @0x2648e0 ldr r8, [sp, #0x68]
 *   @0x2648e4 b 0x2646b4 <_pcre_ord2utf+0x491c>
 *   @0x2648e8 ldr r12, [sp, #0x5c]
 *   @0x2648ec rsb r4, r11, r6
 *   @0x2648f0 mov r3, #0
 *   @0x2648f4 mov r0, r11
 *   @0x2648f8 strb r3, [r6]
 *   @0x2648fc mov r1, #3
 *   @0x264900 mov r3, r9
 *   @0x264904 str r12, [sp]
 *   @0x264908 mov r2, r10
 *   @0x26490c add r6, r6, #6
 *   @0x264910 bl 0x25c2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11d0>
 *   @0x264914 mov r2, r4
 *   @0x264918 mov r1, r11
 *   @0x26491c add r0, r11, #3
 *   @0x264920 bl 0xb6694 <memmove@plt>
 *   @0x264924 ldrb r1, [r11]
 *   @0x264928 add r3, r4, #3
 *   @0x26492c mov r0, #123
 *   @0x264930 cmp r1, #135
 *   @0x264934 ubfx r2, r3, #0x8, #0x8
 *   @0x264938 uxtb r3, r3
 *   @0x26493c movne r1, #137
 *   @0x264940 moveq r1, #132
 *   @0x264944 strb r1, [r11]
 *   @0x264948 strb r2, [r6, #-0x2]
 *   @0x26494c strb r3, [r6, #-0x1]
 *   @0x264950 strb r0, [r6, #-0x3]
 *   @0x264954 strb r2, [r11, #0x1]
 *   @0x264958 strb r3, [r11, #0x2]
 *   @0x26495c b 0x264704 <_pcre_ord2utf+0x496c>
 *   @0x264960 ldr r12, [sp, #0x50]
 *   @0x264964 add r3, r12, #121
 *   @0x264968 strb r3, [r6, #-0x3]
 *   @0x26496c b 0x261220 <_pcre_ord2utf+0x1488>
 *   @0x264970 ldr r12, [sp, #0x9c]
 *   @0x264974 ldr lr, [sp, #0x4c]
 *   @0x264978 adds r2, r12, #0
 *   @0x26497c ldr r12, [sp, #0x64]
 *   @0x264980 ldr r3, [r9, #0x20]
 *   @0x264984 movne r2, #1
 *   @0x264988 ldr r7, [r9, #0x10]
 *   @0x26498c and r2, r2, r12, lsr #31
 *   @0x264990 ldr r12, [sp, #0x68]
 *   @0x264994 cmp r2, #0
 *   @0x264998 ldr r4, [sp, #0x5c]
 *   @0x26499c str r10, [sp, #0xc0]
 *   @0x2649a0 uxtb r12, r12
 *   @0x2649a4 str r12, [sp, #0xa8]
 *   @0x2649a8 mov r12, #1
 *   @0x2649ac str r12, [sp, #0x8c]
 *   @0x2649b0 ldr r12, [sp, #0x64]
 *   @0x2649b4 movne r12, lr
 *   @0x2649b8 ldr lr, [sp, #0x70]
 *   @0x2649bc str r12, [sp, #0x64]
 *   @0x2649c0 ldr r12, [sp, #0x6c]
 *   @0x2649c4 movne r12, lr
 *   @0x2649c8 str r12, [sp, #0x6c]
 *   @0x2649cc mov r0, r6
 *   @0x2649d0 mov r1, r8
 *   @0x2649d4 ldr r2, [sp, #0x68]
 *   @0x2649d8 mov r10, r4
 *   @0x2649dc rsb r4, r7, r3
 *   @0x2649e0 bl 0xb65bc <memcpy@plt>
 *   @0x2649e4 b 0x264a00 <_pcre_ord2utf+0x4c68>
 *   @0x2649e8 mov r0, r9
 *   @0x2649ec bl 0x25cd64 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1c3c>
 *   @0x2649f0 ldr r12, [sp, #0x48]
 *   @0x2649f4 cmp r0, #0
 *   @0x2649f8 str r0, [r12]
 *   @0x2649fc bne 0x264238 <_pcre_ord2utf+0x44a0>
 *   @0x264a00 ldr r1, [r9, #0x3c]
 *   @0x264a04 ldr r7, [r9, #0x10]
 *   @0x264a08 sub r1, r1, #100
 *   @0x264a0c ldr r3, [r9, #0x20]
 *   @0x264a10 rsb r1, r4, r1
 *   @0x264a14 add r1, r1, r10
 *   @0x264a18 add r1, r7, r1
 *   @0x264a1c mov r2, r3
 *   @0x264a20 cmp r3, r1
 *   @0x264a24 bhi 0x2649e8 <_pcre_ord2utf+0x4c50>
 *   @0x264a28 add r12, r7, r10
 *   @0x264a2c add r1, r7, r4
 *   @0x264a30 cmp r12, r1
 *   @0x264a34 bhs 0x264a8c <_pcre_ord2utf+0x4cf4>
 *   @0x264a38 ldrb r1, [r12]
 *   @0x264a3c add r12, r12, #2
 *   @0x264a40 ldrb r3, [r12, #-0x1]
 *   @0x264a44 ldr r0, [sp, #0x68]
 *   @0x264a48 orr r3, r3, r1, lsl #8
 *   @0x264a4c ldr r1, [sp, #0xa8]
 *   @0x264a50 add r3, r0, r3
 *   @0x264a54 asr r3, r3, #8
 *   @0x264a58 strb r3, [r2]
 *   @0x264a5c ldr r3, [r9, #0x20]
 *   @0x264a60 ldrb r2, [r12, #-0x1]
 *   @0x264a64 add r2, r1, r2
 *   @0x264a68 strb r2, [r3, #0x1]
 *   @0x264a6c ldr r7, [r9, #0x10]
 *   @0x264a70 ldr r3, [r9, #0x20]
 *   @0x264a74 add r2, r7, r4
 *   @0x264a78 cmp r12, r2
 *   @0x264a7c add r2, r3, #2
 *   @0x264a80 str r2, [r9, #0x20]
 *   @0x264a84 mov r3, r2
 *   @0x264a88 blo 0x264a38 <_pcre_ord2utf+0x4ca0>
 *   @0x264a8c ldr r12, [sp, #0x8c]
 *   @0x264a90 add r12, r12, #1
 *   @0x264a94 str r12, [sp, #0x8c]
 *   @0x264a98 ldr r12, [sp, #0x68]
 *   @0x264a9c add r6, r6, r12
 *   @0x264aa0 ldr r12, [sp, #0x8c]
 *   @0x264aa4 cmp r12, r5
 *   @0x264aa8 blt 0x2649cc <_pcre_ord2utf+0x4c34>
 *   @0x264aac ldr r10, [sp, #0xc0]
 *   @0x264ab0 mov r12, r4
 *   @0x264ab4 b 0x264668 <_pcre_ord2utf+0x48d0>
 *   @0x264ab8 cmp r4, #127
 *   @0x264abc movls r3, #0
 *   @0x264ac0 andhi r3, r10, #1
 *   @0x264ac4 cmp r3, #0
 *   @0x264ac8 bne 0x264ae4 <_pcre_ord2utf+0x4d4c>
 *   @0x264acc ldr r3, [sp, #0x50]
 *   @0x264ad0 mov r8, r6
 *   @0x264ad4 strb r4, [sp, #0x194]
 *   @0x264ad8 mov r0, #1
 *   @0x264adc str r3, [sp, #0x94]
 *   @0x264ae0 b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x264ae4 add r1, sp, #404
 *   @0x264ae8 mov r0, r4
 *   @0x264aec bl 0x25fd98 <_pcre_ord2utf>
 *   @0x264af0 ldr r1, [sp, #0x98]
 *   @0x264af4 ldr r2, [sp, #0x50]
 *   @0x264af8 mov r8, r6
 *   @0x264afc eor r12, r1, #1
 *   @0x264b00 str r2, [sp, #0x94]
 *   @0x264b04 cmp r0, #1
 *   @0x264b08 orreq r12, r12, #1
 *   @0x264b0c b 0x2605b8 <_pcre_ord2utf+0x820>
 *   @0x264b10 ldr r2, [sp, #0x84]
 *   @0x264b14 cmp r2, #0
 *   @0x264b18 beq 0x264960 <_pcre_ord2utf+0x4bc8>
 *   @0x264b1c mvn r3, #124
 *   @0x264b20 mov r8, #131
 *   @0x264b24 strb r3, [r11]
 *   @0x264b28 b 0x2646a8 <_pcre_ord2utf+0x4910>
 *   @0x264b2c mov r5, r8
 *   @0x264b30 ldr r8, [sp, #0x68]
 *   @0x264b34 add r8, r8, #5
 *   @0x264b38 strb r8, [r11]
 *   @0x264b3c b 0x2646d8 <_pcre_ord2utf+0x4940>
 *   @0x264b40 ldr r1, [sp, #0x68]
 *   @0x264b44 mov r4, r5
 *   @0x264b48 mov r5, r7
 *   @0x264b4c add r0, r1, #1
 *   @0x264b50 ldrb r1, [r12]
 *   @0x264b54 add r12, r12, #2
 *   @0x264b58 ldrb r3, [r12, #-0x1]
 *   @0x264b5c orr r3, r3, r1, lsl #8
 *   @0x264b60 ldr r1, [sp, #0x68]
 *   @0x264b64 add r3, r1, r3
 *   @0x264b68 add r3, r3, #1
 *   @0x264b6c asr r3, r3, #8
 *   @0x264b70 strb r3, [r2]
 *   @0x264b74 ldr r3, [r9, #0x20]
 *   @0x264b78 ldrb r2, [r12, #-0x1]
 *   @0x264b7c add r2, r0, r2
 *   @0x264b80 strb r2, [r3, #0x1]
 *   @0x264b84 ldr r3, [r9, #0x10]
 *   @0x264b88 ldr r2, [r9, #0x20]
 *   @0x264b8c add r3, r3, r5
 *   @0x264b90 cmp r12, r3
 *   @0x264b94 add r2, r2, #2
 *   @0x264b98 str r2, [r9, #0x20]
 *   @0x264b9c blo 0x264b50 <_pcre_ord2utf+0x4db8>
 *   @0x264ba0 ldr r3, [sp, #0x50]
 *   @0x264ba4 ldr r12, [sp, #0x68]
 *   @0x264ba8 add r6, r3, r12
 *   @0x264bac b 0x262234 <_pcre_ord2utf+0x249c>
 *   @0x264bb0 mov r4, r5
 *   @0x264bb4 b 0x262234 <_pcre_ord2utf+0x249c>
 *   @0x264bb8 str r1, [sp, #0x68]
 *   @0x264bbc mov r1, r11
 *   @0x264bc0 b 0x261de4 <_pcre_ord2utf+0x204c>
 *   @0x264bc4 ldr r3, [r9, #0x64]
 *   @0x264bc8 orr r3, r3, #4096
 *   @0x264bcc str r3, [r9, #0x64]
 *   @0x264bd0 mov r6, r2
 *   @0x264bd4 ldr r11, [sp, #0x13c]
 *   @0x264bd8 mov r8, #0
 *   @0x264bdc ldr r7, [r9, #0x10]
 *   @0x264be0 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x264be4 mov r3, #1
 *   @0x264be8 str r3, [r9, #0x70]
 *   @0x264bec b 0x264bd0 <_pcre_ord2utf+0x4e38>
 *   @0x264bf0 ldr r12, [sp, #0x50]
 *   @0x264bf4 mov r3, #66
 *   @0x264bf8 mov r4, r12
 *   @0x264bfc ldr r12, [sp, #0x48]
 *
 * ══ §5/8 anon_264c00  0x264c00..0x265b58  size 3928  982 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_25fe2c
 * @func 0x264c00 0x265b58  size 3928  982 条
 * ⚠ 父块 anon_25fe2c 是 26,424 B 的未闭合大状态机（METHOD §4）：段长不一定等于函数长，本段可能只是其中的一段
 * 入度 90｜调用者: 0x261fac(anon_25fe2c+0x2180), 0x261fb0(anon_25fe2c+0x2184), 0x261fb4(anon_25fe2c+0x2188), 0x261fb8(anon_25fe2c+0x218c), 0x261fbc(anon_25fe2c+0x2190), 0x261fc0(anon_25fe2c+0x2194), 0x261fc4(anon_25fe2c+0x2198), 0x261fc8(anon_25fe2c+0x219c)…
 * 出调用 9 处 → 0xb65e0×3, 0xb65bc×2, anon_25b524+0xdd4×1, 0xb6694×1, 0xb65d4×1, anon_25b524+0x18f0×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x264c00 str r3, [r12]
 *   @0x264c04 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264c08 ldr r4, [r12, #0x364]
 *   @0x264c0c cmp r4, #0
 *   @0x264c10 blt 0x264ce0 <_pcre_ord2utf+0x4f48>
 *   @0x264c14 ldr r12, [sp, #0x3c]
 *   @0x264c18 strb r4, [r6]
 *   @0x264c1c uxtb r4, r4
 *   @0x264c20 cmp r12, #0
 *   @0x264c24 beq 0x264cc0 <_pcre_ord2utf+0x4f28>
 *   @0x264c28 ldr r2, [r12]
 *   @0x264c2c add r3, r6, #2
 *   @0x264c30 strb r0, [r6, #0x1]
 *   @0x264c34 add r7, r2, r7
 *   @0x264c38 str r7, [r12]
 *   @0x264c3c mov r1, #0
 *   @0x264c40 add r2, r3, #1
 *   @0x264c44 strb r1, [r3]
 *   @0x264c48 b 0x261ed4 <_pcre_ord2utf+0x213c>
 *   @0x264c4c cmp r7, #0
 *   @0x264c50 bne 0x264ce0 <_pcre_ord2utf+0x4f48>
 *   @0x264c54 ldr r3, [r3, #0x24]
 *   @0x264c58 mov r2, #1
 *   @0x264c5c str r2, [r9, #0x6c]
 *   @0x264c60 cmp r3, #0
 *   @0x264c64 beq 0x264c94 <_pcre_ord2utf+0x4efc>
 *   @0x264c68 ldr r12, [sp, #0x3c]
 *   @0x264c6c cmp r12, #0
 *   @0x264c70 beq 0x264cf8 <_pcre_ord2utf+0x4f60>
 *   @0x264c74 ldr r12, [sp, #0x3c]
 *   @0x264c78 ldr r2, [r12]
 *   @0x264c7c ldr r3, [r3]
 *   @0x264c80 add r2, r2, #3
 *   @0x264c84 cmp r3, #0
 *   @0x264c88 bne 0x264c7c <_pcre_ord2utf+0x4ee4>
 *   @0x264c8c ldr r12, [sp, #0x3c]
 *   @0x264c90 str r2, [r12]
 *   @0x264c94 ldr r3, [r9, #0x5c]
 *   @0x264c98 add r2, r6, #1
 *   @0x264c9c ldr r12, [sp, #0x4c]
 *   @0x264ca0 cmp r3, #0
 *   @0x264ca4 movgt r4, #159
 *   @0x264ca8 movle r4, #158
 *   @0x264cac cmn r12, #2
 *   @0x264cb0 strb r4, [r6]
 *   @0x264cb4 mvneq r12, #0
 *   @0x264cb8 str r12, [sp, #0x4c]
 *   @0x264cbc b 0x261ed4 <_pcre_ord2utf+0x213c>
 *   @0x264cc0 add r3, r6, #2
 *   @0x264cc4 strb r7, [r6, #0x1]
 *   @0x264cc8 mov r1, r8
 *   @0x264ccc mov r2, r7
 *   @0x264cd0 mov r0, r3
 *   @0x264cd4 bl 0xb65bc <memcpy@plt>
 *   @0x264cd8 add r3, r0, r7
 *   @0x264cdc b 0x264c3c <_pcre_ord2utf+0x4ea4>
 *   @0x264ce0 ldr r12, [sp, #0x50]
 *   @0x264ce4 mov r3, #59
 *   @0x264ce8 mov r4, r12
 *   @0x264cec ldr r12, [sp, #0x48]
 *   @0x264cf0 str r3, [r12]
 *   @0x264cf4 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264cf8 mvn r2, #95
 *   @0x264cfc strb r2, [r6]
 *   @0x264d00 add r6, r6, #3
 *   @0x264d04 ldrh r1, [r3, #4]
 *   @0x264d08 lsr r1, r1, #8
 *   @0x264d0c strb r1, [r6, #-0x2]
 *   @0x264d10 ldrh r1, [r3, #4]
 *   @0x264d14 strb r1, [r6, #-0x1]
 *   @0x264d18 ldr r3, [r3]
 *   @0x264d1c cmp r3, #0
 *   @0x264d20 bne 0x264cfc <_pcre_ord2utf+0x4f64>
 *   @0x264d24 b 0x264c94 <_pcre_ord2utf+0x4efc>
 *   @0x264d28 ldr r12, [sp, #0x7c]
 *   @0x264d2c mov r5, #1
 *   @0x264d30 str r3, [sp, #0xbc]
 *   @0x264d34 ldr r1, [sp, #0x13c]
 *   @0x264d38 ldrb r2, [r12, #0x2]
 *   @0x264d3c ldrb r3, [r12, #0x3]
 *   @0x264d40 orr r2, r3, r2, lsl #8
 *   @0x264d44 ldr r3, [r9, #0x18]
 *   @0x264d48 rsb r1, r3, r1
 *   @0x264d4c ldr r3, [sp, #0x3c]
 *   @0x264d50 rsb r2, r2, r1
 *   @0x264d54 strb r2, [r12, #0x5]
 *   @0x264d58 str r3, [sp, #0x7c]
 *   @0x264d5c asr r2, r2, #8
 *   @0x264d60 strb r2, [r12, #0x4]
 *   @0x264d64 b 0x260328 <_pcre_ord2utf+0x590>
 *   @0x264d68 ldr r12, [sp, #0xb4]
 *   @0x264d6c mov r7, r9
 *   @0x264d70 rsb r3, r12, r10
 *   @0x264d74 mov r2, r12
 *   @0x264d78 b 0x264d80 <_pcre_ord2utf+0x4fe8>
 *   @0x264d7c mov r3, r1
 *   @0x264d80 ldrb r0, [r2, #0x1]
 *   @0x264d84 asr r12, r3, #8
 *   @0x264d88 ldrb r1, [r2, #0x2]
 *   @0x264d8c strb r12, [r2, #0x1]
 *   @0x264d90 orr r1, r1, r0, lsl #8
 *   @0x264d94 strb r3, [r2, #0x2]
 *   @0x264d98 cmp r1, #0
 *   @0x264d9c rsb r2, r1, r2
 *   @0x264da0 bne 0x264d7c <_pcre_ord2utf+0x4fe4>
 *   @0x264da4 str r8, [sp, #0xa4]
 *   @0x264da8 str r5, [sp, #0xac]
 *   @0x264dac ldr r12, [sp, #0xdc]
 *   @0x264db0 mov r6, #120
 *   @0x264db4 add r5, r10, #3
 *   @0x264db8 strb r6, [r10]
 *   @0x264dbc cmp r12, #0
 *   @0x264dc0 ldr r12, [sp, #0x90]
 *   @0x264dc4 rsb r3, r12, r10
 *   @0x264dc8 strb r3, [r10, #0x2]
 *   @0x264dcc asr r3, r3, #8
 *   @0x264dd0 strb r3, [r10, #0x1]
 *   @0x264dd4 beq 0x264df0 <_pcre_ord2utf+0x5058>
 *   @0x264dd8 ldr r3, [r7, #0x24]
 *   @0x264ddc ldrh r2, [r3, #6]
 *   @0x264de0 cmp r2, #0
 *   @0x264de4 bne 0x264ea8 <_pcre_ord2utf+0x5110>
 *   @0x264de8 ldr r3, [r3]
 *   @0x264dec str r3, [r7, #0x24]
 *   @0x264df0 ldr r12, [sp, #0xc8]
 *   @0x264df4 ldr r0, [sp, #0x114]
 *   @0x264df8 cmp r12, #0
 *   @0x264dfc ldr r12, [sp, #0xe0]
 *   @0x264e00 str r12, [r7, #0x40]
 *   @0x264e04 ldr r12, [sp, #0xd0]
 *   @0x264e08 str r5, [r12]
 *   @0x264e0c ldr r12, [sp, #0xc4]
 *   @0x264e10 str r4, [r12]
 *   @0x264e14 ldr r12, [sp, #0xcc]
 *   @0x264e18 str r12, [r0]
 *   @0x264e1c ldr r12, [sp, #0xb8]
 *   @0x264e20 ldr r0, [sp, #0x118]
 *   @0x264e24 str r12, [r0]
 *   @0x264e28 ldr r12, [sp, #0xa4]
 *   @0x264e2c ldr r0, [sp, #0x11c]
 *   @0x264e30 str r12, [r0]
 *   @0x264e34 ldr r12, [sp, #0xac]
 *   @0x264e38 ldr r0, [sp, #0x120]
 *   @0x264e3c str r12, [r0]
 *   @0x264e40 beq 0x264f34 <_pcre_ord2utf+0x519c>
 *   @0x264e44 ldr r12, [sp, #0xc8]
 *   @0x264e48 movw r3, #0xffeb
 *   @0x264e4c ldr r2, [sp, #0x130]
 *   @0x264e50 movt r3, #0x7fff
 *   @0x264e54 ldr r1, [r12]
 *   @0x264e58 rsb r3, r1, r3
 *   @0x264e5c cmp r3, r2
 *   @0x264e60 addge r2, r1, r2
 *   @0x264e64 ldrlt r12, [sp, #0x48]
 *   @0x264e68 movlt r3, #20
 *   @0x264e6c ldrge r12, [sp, #0xc8]
 *   @0x264e70 movlt r0, #0
 *   @0x264e74 movge r0, #1
 *   @0x264e78 strlt r3, [r12]
 *   @0x264e7c strge r2, [r12]
 *   @0x264e80 b 0x260df0 <_pcre_ord2utf+0x1058>
 *   @0x264e84 and r4, r7, #7
 *   @0x264e88 mov r0, r3
 *   @0x264e8c add r1, sp, #348
 *   @0x264e90 str r12, [sp, #0x34]
 *   @0x264e94 mov r2, r4
 *   @0x264e98 bl 0xb65bc <memcpy@plt>
 *   @0x264e9c ldr r12, [sp, #0x34]
 *   @0x264ea0 add r4, r0, r4
 *   @0x264ea4 b 0x2617ac <_pcre_ord2utf+0x1a14>
 *   @0x264ea8 ldr r12, [sp, #0x108]
 *   @0x264eac mov r1, #0
 *   @0x264eb0 ldr lr, [sp, #0x10c]
 *   @0x264eb4 strb r1, [r10, #0x3]
 *   @0x264eb8 mov r1, #3
 *   @0x264ebc rsb r3, lr, r12
 *   @0x264ec0 ldr r12, [sp, #0x40]
 *   @0x264ec4 ldr r0, [sp, #0x90]
 *   @0x264ec8 ubfx r2, r12, #0xb, #0x1
 *   @0x264ecc str r3, [sp]
 *   @0x264ed0 mov r3, r7
 *   @0x264ed4 bl 0x25c2f8 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x11d0>
 *   @0x264ed8 ldr r12, [sp, #0x90]
 *   @0x264edc rsb r2, r12, r5
 *   @0x264ee0 add r0, r12, #3
 *   @0x264ee4 mov r1, r12
 *   @0x264ee8 add r5, r10, #9
 *   @0x264eec bl 0xb6694 <memmove@plt>
 *   @0x264ef0 ldr r12, [sp, #0x90]
 *   @0x264ef4 add r3, r10, #6
 *   @0x264ef8 mvn r1, #126
 *   @0x264efc rsb r3, r12, r3
 *   @0x264f00 ubfx r2, r3, #0x8, #0x8
 *   @0x264f04 strb r1, [r12]
 *   @0x264f08 strb r2, [r12, #0x1]
 *   @0x264f0c uxtb r3, r3
 *   @0x264f10 strb r3, [r12, #0x2]
 *   @0x264f14 strb r2, [r10, #0x7]
 *   @0x264f18 ldr r2, [sp, #0x130]
 *   @0x264f1c strb r3, [r10, #0x8]
 *   @0x264f20 strb r6, [r10, #0x6]
 *   @0x264f24 add r2, r2, #6
 *   @0x264f28 ldr r3, [r7, #0x24]
 *   @0x264f2c str r2, [sp, #0x130]
 *   @0x264f30 b 0x264de8 <_pcre_ord2utf+0x5050>
 *   @0x264f34 mov r0, #1
 *   @0x264f38 b 0x260df0 <_pcre_ord2utf+0x1058>
 *   @0x264f3c bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x264f40 mov r7, r9
 *   @0x264f44 b 0x264dac <_pcre_ord2utf+0x5014>
 *   @0x264f48 ldr r12, [sp, #0x48]
 *   @0x264f4c mov r4, r3
 *   @0x264f50 mov r3, #14
 *   @0x264f54 str r3, [r12]
 *   @0x264f58 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264f5c ldr r12, [sp, #0x48]
 *   @0x264f60 mov r3, #27
 *   @0x264f64 ldr r4, [sp, #0x13c]
 *   @0x264f68 str r3, [r12]
 *   @0x264f6c b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264f70 ldr r12, [sp, #0x48]
 *   @0x264f74 mov r3, #82
 *   @0x264f78 ldr r4, [sp, #0x13c]
 *   @0x264f7c str r3, [r12]
 *   @0x264f80 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264f84 ldr r12, [sp, #0x48]
 *   @0x264f88 mov r3, #64
 *   @0x264f8c ldr r4, [sp, #0x13c]
 *   @0x264f90 str r3, [r12]
 *   @0x264f94 b 0x260de4 <_pcre_ord2utf+0x104c>
 *   @0x264f98 mov r3, #0
 *   @0x264f9c b 0x263ce0 <_pcre_ord2utf+0x3f48>
 *   @0x264fa0 mov r5, #41
 *   @0x264fa4 b 0x26307c <_pcre_ord2utf+0x32e4>
 *   @0x264fa8 str r12, [sp, #0x140]
 *   @0x264fac ldrb r3, [r0, #0x3]
 *   @0x264fb0 cmp r3, #63
 *   @0x264fb4 beq 0x265548 <_pcre_ord2utf+0x57b0>
 *   @0x264fb8 mvn r3, #114
 *   @0x264fbc strb r3, [r6, #0x3]
 *   @0x264fc0 ldr r3, [sp, #0x13c]
 *   @0x264fc4 add r8, r3, #1
 *   @0x264fc8 str r8, [sp, #0x13c]
 *   @0x264fcc ldrb r4, [r3, #0x1]
 *   @0x264fd0 cmp r4, #82
 *   @0x264fd4 beq 0x265514 <_pcre_ord2utf+0x577c>
 *   @0x264fd8 cmp r4, #60
 *   @0x264fdc beq 0x2654e4 <_pcre_ord2utf+0x574c>
 *   @0x264fe0 cmp r4, #39
 *   @0x264fe4 beq 0x2654c0 <_pcre_ord2utf+0x5728>
 *   @0x264fe8 cmp r4, #45
 *   @0x264fec cmpne r4, #43
 *   @0x264ff0 bne 0x2650d8 <_pcre_ord2utf+0x5340>
 *   @0x264ff4 add r2, r3, #2
 *   @0x264ff8 str r2, [sp, #0x13c]
 *   @0x264ffc ldrb r1, [r3, #0x2]
 *   @0x265000 ldrb r12, [r3, #0x1]
 *   @0x265004 sub r3, r1, #48
 *   @0x265008 cmp r3, #9
 *   @0x26500c movhi r3, #0
 *   @0x265010 bhi 0x265058 <_pcre_ord2utf+0x52c0>
 *   @0x265014 add r2, r2, #1
 *   @0x265018 sub r1, r1, #48
 *   @0x26501c mov r3, #0
 *   @0x265020 b 0x265030 <_pcre_ord2utf+0x5298>
 *   @0x265024 ldr r0, [sp, #0xd4]
 *   @0x265028 cmp r3, r0
 *   @0x26502c bgt 0x2650a4 <_pcre_ord2utf+0x530c>
 *   @0x265030 add r3, r3, r3, lsl #2
 *   @0x265034 str r2, [sp, #0x13c]
 *   @0x265038 mov r4, r2
 *   @0x26503c ldrb r0, [r2], #1
 *   @0x265040 add r3, r1, r3, lsl #1
 *   @0x265044 sub r1, r0, #48
 *   @0x265048 uxtb r0, r1
 *   @0x26504c cmp r0, #9
 *   @0x265050 bls 0x265024 <_pcre_ord2utf+0x528c>
 *   @0x265054 mov r2, r4
 *   @0x265058 mov r4, #0
 *   @0x26505c mov r5, #3
 *   @0x265060 mov r8, r4
 *   @0x265064 mvn r7, #0
 *   @0x265068 add r0, r2, #1
 *   @0x26506c str r0, [sp, #0x13c]
 *   @0x265070 ldrb r2, [r2]
 *   @0x265074 str r0, [sp, #0x50]
 *   @0x265078 cmp r2, #41
 *   @0x26507c bne 0x26547c <_pcre_ord2utf+0x56e4>
 *   @0x265080 ldr r0, [sp, #0x3c]
 *   @0x265084 cmp r0, #0
 *   @0x265088 beq 0x265174 <_pcre_ord2utf+0x53dc>
 *   @0x26508c ldr r0, [sp, #0x40]
 *   @0x265090 mov r3, #0
 *   @0x265094 mov r4, #135
 *   @0x265098 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x26509c mov r4, #39
 *   @0x2650a0 b 0x263d3c <_pcre_ord2utf+0x3fa4>
 *   @0x2650a4 add r4, r4, #1
 *   @0x2650a8 str r4, [sp, #0x13c]
 *   @0x2650ac mov r3, r4
 *   @0x2650b0 ldrb r2, [r4]
 *   @0x2650b4 add r4, r4, #1
 *   @0x2650b8 sub r2, r2, #48
 *   @0x2650bc cmp r2, #9
 *   @0x2650c0 bls 0x2650a8 <_pcre_ord2utf+0x5310>
 *   @0x2650c4 ldr r12, [sp, #0x48]
 *   @0x2650c8 mov r11, r3
 *   @0x2650cc mov r3, #61
 *   @0x2650d0 str r3, [r12]
 *   @0x2650d4 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2650d8 sub r3, r4, #48
 *   @0x2650dc cmp r3, #9
 *   @0x2650e0 movhi r3, r4
 *   @0x2650e4 movhi r4, #0
 *   @0x2650e8 bls 0x2654a8 <_pcre_ord2utf+0x5710>
 *   @0x2650ec ldr r2, [r9, #0xc]
 *   @0x2650f0 ldrb r3, [r2, r3]
 *   @0x2650f4 tst r3, #16
 *   @0x2650f8 beq 0x265494 <_pcre_ord2utf+0x56fc>
 *   @0x2650fc add r1, r8, #1
 *   @0x265100 str r1, [sp, #0x13c]
 *   @0x265104 ldrb r3, [r8, #0x1]
 *   @0x265108 ldrb r3, [r2, r3]
 *   @0x26510c tst r3, #16
 *   @0x265110 beq 0x265134 <_pcre_ord2utf+0x539c>
 *   @0x265114 add r3, r8, #2
 *   @0x265118 str r3, [sp, #0x13c]
 *   @0x26511c mov r1, r3
 *   @0x265120 ldrb r0, [r3]
 *   @0x265124 add r3, r3, #1
 *   @0x265128 ldrb r0, [r2, r0]
 *   @0x26512c tst r0, #16
 *   @0x265130 bne 0x265118 <_pcre_ord2utf+0x5380>
 *   @0x265134 ldr r12, [sp, #0x3c]
 *   @0x265138 rsb r7, r8, r1
 *   @0x26513c cmp r12, #0
 *   @0x265140 movne r5, #5
 *   @0x265144 moveq r5, #3
 *   @0x265148 cmp r4, #0
 *   @0x26514c ble 0x2654b8 <_pcre_ord2utf+0x5720>
 *   @0x265150 add r2, r1, #1
 *   @0x265154 str r2, [sp, #0x13c]
 *   @0x265158 ldrb r1, [r1]
 *   @0x26515c uxtb r3, r4
 *   @0x265160 cmp r1, r3
 *   @0x265164 bne 0x265480 <_pcre_ord2utf+0x56e8>
 *   @0x265168 mvn r12, #0
 *   @0x26516c mov r3, #0
 *   @0x265170 b 0x265068 <_pcre_ord2utf+0x52d0>
 *   @0x265174 cmn r12, #1
 *   @0x265178 beq 0x2651f4 <_pcre_ord2utf+0x545c>
 *   @0x26517c cmp r3, #0
 *   @0x265180 beq 0x2651e0 <_pcre_ord2utf+0x5448>
 *   @0x265184 cmp r12, #0
 *   @0x265188 beq 0x2651a8 <_pcre_ord2utf+0x5410>
 *   @0x26518c ldr r2, [r9, #0x40]
 *   @0x265190 cmp r12, #45
 *   @0x265194 addeq r2, r2, #1
 *   @0x265198 addne r3, r3, r2
 *   @0x26519c rsbeq r3, r3, r2
 *   @0x2651a0 cmp r3, #0
 *   @0x2651a4 ble 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x2651a8 ldr r2, [r9, #0x44]
 *   @0x2651ac cmp r2, r3
 *   @0x2651b0 blt 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x2651b4 asr r2, r3, #8
 *   @0x2651b8 strb r3, [r6, #0x5]
 *   @0x2651bc strb r2, [r6, #0x4]
 *   @0x2651c0 ldr r2, [r9, #0x4c]
 *   @0x2651c4 cmp r2, r3
 *   @0x2651c8 bge 0x26508c <_pcre_ord2utf+0x52f4>
 *   @0x2651cc str r3, [r9, #0x4c]
 *   @0x2651d0 mov r4, #135
 *   @0x2651d4 ldr r0, [sp, #0x40]
 *   @0x2651d8 mov r3, #0
 *   @0x2651dc b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x2651e0 ldr r12, [sp, #0x48]
 *   @0x2651e4 mov r3, #35
 *   @0x2651e8 ldr r11, [sp, #0x50]
 *   @0x2651ec str r3, [r12]
 *   @0x2651f0 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2651f4 ldr r3, [r9, #0x30]
 *   @0x2651f8 ldr r12, [r9, #0x2c]
 *   @0x2651fc cmp r3, #0
 *   @0x265200 str r3, [sp, #0x68]
 *   @0x265204 ble 0x265260 <_pcre_ord2utf+0x54c8>
 *   @0x265208 ldr r11, [sp, #0x3c]
 *   @0x26520c str r5, [sp, #0x84]
 *   @0x265210 mov r5, r4
 *   @0x265214 mov r4, r12
 *   @0x265218 mov r0, r8
 *   @0x26521c add r1, r4, #2
 *   @0x265220 mov r2, r7
 *   @0x265224 bl 0xb65e0 <strncmp@plt>
 *   @0x265228 cmp r0, #0
 *   @0x26522c bne 0x265240 <_pcre_ord2utf+0x54a8>
 *   @0x265230 add r3, r4, r7
 *   @0x265234 ldrb r3, [r3, #0x2]
 *   @0x265238 cmp r3, #0
 *   @0x26523c beq 0x265328 <_pcre_ord2utf+0x5590>
 *   @0x265240 ldr r12, [sp, #0x68]
 *   @0x265244 add r11, r11, #1
 *   @0x265248 ldr r3, [r9, #0x34]
 *   @0x26524c cmp r11, r12
 *   @0x265250 add r4, r4, r3
 *   @0x265254 bne 0x265218 <_pcre_ord2utf+0x5480>
 *   @0x265258 mov r4, r5
 *   @0x26525c ldr r5, [sp, #0x84]
 *   @0x265260 cmp r4, #0
 *   @0x265264 bne 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x265268 ldrb r3, [r8]
 *   @0x26526c cmp r3, #82
 *   @0x265270 beq 0x2652b0 <_pcre_ord2utf+0x5518>
 *   @0x265274 cmp r7, #6
 *   @0x265278 bne 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x26527c mov r0, r8
 *   @0x265280 mov r2, r7
 *   @0x265284 ldr r1, [sp, #0x128]
 *   @0x265288 bl 0xb65e0 <strncmp@plt>
 *   @0x26528c cmp r0, #0
 *   @0x265290 bne 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x265294 mov r3, r4
 *   @0x265298 mvn r2, #110
 *   @0x26529c ldr r0, [sp, #0x40]
 *   @0x2652a0 mov r5, #1
 *   @0x2652a4 strb r2, [r6, #0x3]
 *   @0x2652a8 mov r4, #135
 *   @0x2652ac b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x2652b0 cmp r7, #1
 *   @0x2652b4 ble 0x265454 <_pcre_ord2utf+0x56bc>
 *   @0x2652b8 ldrb r3, [r8, #0x1]
 *   @0x2652bc sub r2, r3, #48
 *   @0x2652c0 cmp r2, #9
 *   @0x2652c4 bhi 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x2652c8 add r1, r8, r7
 *   @0x2652cc add r8, r8, #2
 *   @0x2652d0 add r4, r4, r4, lsl #2
 *   @0x2652d4 cmp r8, r1
 *   @0x2652d8 add r3, r3, r4, lsl #1
 *   @0x2652dc sub r4, r3, #48
 *   @0x2652e0 beq 0x265444 <_pcre_ord2utf+0x56ac>
 *   @0x2652e4 ldrb r3, [r8], #1
 *   @0x2652e8 sub r2, r3, #48
 *   @0x2652ec cmp r2, #9
 *   @0x2652f0 bhi 0x265314 <_pcre_ord2utf+0x557c>
 *   @0x2652f4 ldr r12, [sp, #0xd4]
 *   @0x2652f8 cmp r4, r12
 *   @0x2652fc ble 0x2652d0 <_pcre_ord2utf+0x5538>
 *   @0x265300 ldr r12, [sp, #0x48]
 *   @0x265304 mov r3, #61
 *   @0x265308 ldr r11, [sp, #0x50]
 *   @0x26530c str r3, [r12]
 *   @0x265310 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265314 ldr r12, [sp, #0x48]
 *   @0x265318 mov r3, #15
 *   @0x26531c ldr r11, [sp, #0x50]
 *   @0x265320 str r3, [r12]
 *   @0x265324 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265328 ldrb r1, [r4]
 *   @0x26532c add r2, r11, #1
 *   @0x265330 ldrb r3, [r4, #0x1]
 *   @0x265334 mov r12, r4
 *   @0x265338 ldr r0, [r9, #0x4c]
 *   @0x26533c orr r3, r3, r1, lsl #8
 *   @0x265340 ldr r5, [sp, #0x84]
 *   @0x265344 cmp r3, r0
 *   @0x265348 ldr r0, [sp, #0x68]
 *   @0x26534c strgt r3, [r9, #0x4c]
 *   @0x265350 cmp r0, r2
 *   @0x265354 ble 0x265428 <_pcre_ord2utf+0x5690>
 *   @0x265358 ldr r1, [r9, #0x34]
 *   @0x26535c rsb r2, r11, r0
 *   @0x265360 str r2, [sp, #0x84]
 *   @0x265364 mov r4, #1
 *   @0x265368 add r2, r1, #2
 *   @0x26536c str r5, [sp, #0x68]
 *   @0x265370 add r12, r12, r2
 *   @0x265374 mov r5, r4
 *   @0x265378 str r1, [sp, #0x50]
 *   @0x26537c mov r4, r12
 *   @0x265380 mov r12, r9
 *   @0x265384 mov r9, r3
 *   @0x265388 mov r0, r8
 *   @0x26538c mov r1, r4
 *   @0x265390 mov r2, r7
 *   @0x265394 str r12, [sp, #0x34]
 *   @0x265398 bl 0xb65e0 <strncmp@plt>
 *   @0x26539c ldr r12, [sp, #0x34]
 *   @0x2653a0 cmp r0, #0
 *   @0x2653a4 bne 0x265410 <_pcre_ord2utf+0x5678>
 *   @0x2653a8 ldrb r2, [r4, r7]
 *   @0x2653ac cmp r2, #0
 *   @0x2653b0 bne 0x265410 <_pcre_ord2utf+0x5678>
 *   @0x2653b4 ldr r3, [sp, #0x50]
 *   @0x2653b8 add r5, r5, #1
 *   @0x2653bc add r4, r4, r3
 *   @0x2653c0 ldr r3, [sp, #0x84]
 *   @0x2653c4 cmp r5, r3
 *   @0x2653c8 bne 0x265388 <_pcre_ord2utf+0x55f0>
 *   @0x2653cc mov r4, r5
 *   @0x2653d0 ldr r5, [sp, #0x68]
 *   @0x2653d4 mov r9, r12
 *   @0x2653d8 ldrb r3, [r6, #0x3]
 *   @0x2653dc add r5, r5, #2
 *   @0x2653e0 strb r11, [r6, #0x5]
 *   @0x2653e4 asr r11, r11, #8
 *   @0x2653e8 add r3, r3, #1
 *   @0x2653ec strb r4, [r6, #0x7]
 *   @0x2653f0 strb r3, [r6, #0x3]
 *   @0x2653f4 asr r4, r4, #8
 *   @0x2653f8 strb r11, [r6, #0x4]
 *   @0x2653fc mov r3, #0
 *   @0x265400 strb r4, [r6, #0x6]
 *   @0x265404 mov r4, #135
 *   @0x265408 ldr r0, [sp, #0x40]
 *   @0x26540c b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265410 mov r4, r5
 *   @0x265414 cmp r4, #1
 *   @0x265418 mov r3, r9
 *   @0x26541c ldr r5, [sp, #0x68]
 *   @0x265420 mov r9, r12
 *   @0x265424 bne 0x2653d8 <_pcre_ord2utf+0x5640>
 *   @0x265428 strb r3, [r6, #0x5]
 *   @0x26542c mov r4, #135
 *   @0x265430 asr r3, r3, #8
 *   @0x265434 ldr r0, [sp, #0x40]
 *   @0x265438 strb r3, [r6, #0x4]
 *   @0x26543c mov r3, #0
 *   @0x265440 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265444 cmp r4, #0
 *   @0x265448 ubfxne r3, r4, #0x8, #0x8
 *   @0x26544c uxtbne r4, r4
 *   @0x265450 bne 0x26545c <_pcre_ord2utf+0x56c4>
 *   @0x265454 mov r4, #255
 *   @0x265458 mov r3, r4
 *   @0x26545c strb r3, [r6, #0x4]
 *   @0x265460 mvn r3, #112
 *   @0x265464 strb r4, [r6, #0x5]
 *   @0x265468 mov r4, #135
 *   @0x26546c strb r3, [r6, #0x3]
 *   @0x265470 mov r3, #0
 *   @0x265474 ldr r0, [sp, #0x40]
 *   @0x265478 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x26547c mov r2, r0
 *   @0x265480 ldr r12, [sp, #0x48]
 *   @0x265484 mov r3, #26
 *   @0x265488 sub r11, r2, #1
 *   @0x26548c str r3, [r12]
 *   @0x265490 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265494 ldr r12, [sp, #0x48]
 *   @0x265498 mov r3, #28
 *   @0x26549c mov r11, r8
 *   @0x2654a0 str r3, [r12]
 *   @0x2654a4 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2654a8 mov r1, r4
 *   @0x2654ac mov r2, r8
 *   @0x2654b0 mov r12, #0
 *   @0x2654b4 b 0x265014 <_pcre_ord2utf+0x527c>
 *   @0x2654b8 mov r2, r1
 *   @0x2654bc b 0x265168 <_pcre_ord2utf+0x53d0>
 *   @0x2654c0 add r11, r3, #2
 *   @0x2654c4 str r11, [sp, #0x13c]
 *   @0x2654c8 ldrb r3, [r3, #0x2]
 *   @0x2654cc sub r2, r3, #48
 *   @0x2654d0 uxtb r2, r2
 *   @0x2654d4 cmp r2, #9
 *   @0x2654d8 bls 0x265504 <_pcre_ord2utf+0x576c>
 *   @0x2654dc mov r8, r11
 *   @0x2654e0 b 0x2650ec <_pcre_ord2utf+0x5354>
 *   @0x2654e4 add r11, r3, #2
 *   @0x2654e8 str r11, [sp, #0x13c]
 *   @0x2654ec ldrb r3, [r3, #0x2]
 *   @0x2654f0 mov r4, #62
 *   @0x2654f4 sub r2, r3, #48
 *   @0x2654f8 uxtb r2, r2
 *   @0x2654fc b 0x2654d4 <_pcre_ord2utf+0x573c>
 *   @0x265500 ldr r11, [sp, #0x50]
 *   @0x265504 ldr r12, [sp, #0x48]
 *   @0x265508 mov r3, #84
 *   @0x26550c str r3, [r12]
 *   @0x265510 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265514 ldrb r2, [r3, #0x2]
 *   @0x265518 cmp r2, #38
 *   @0x26551c bne 0x2650d8 <_pcre_ord2utf+0x5340>
 *   @0x265520 add r3, r3, #3
 *   @0x265524 mvn r2, #112
 *   @0x265528 str r3, [sp, #0x13c]
 *   @0x26552c mvn r4, #0
 *   @0x265530 strb r2, [r6, #0x3]
 *   @0x265534 ldr r11, [sp, #0x13c]
 *   @0x265538 ldrb r3, [r11]
 *   @0x26553c sub r2, r3, #48
 *   @0x265540 uxtb r2, r2
 *   @0x265544 b 0x2654d4 <_pcre_ord2utf+0x573c>
 *   @0x265548 ldrb r3, [r0, #0x4]
 *   @0x26554c cmp r3, #67
 *   @0x265550 movne r3, r12
 *   @0x265554 beq 0x26559c <_pcre_ord2utf+0x5804>
 *   @0x265558 ldrb r2, [r3, #0x2]
 *   @0x26555c cmp r2, #61
 *   @0x265560 cmpne r2, #33
 *   @0x265564 beq 0x265580 <_pcre_ord2utf+0x57e8>
 *   @0x265568 cmp r2, #60
 *   @0x26556c bne 0x264fb8 <_pcre_ord2utf+0x5220>
 *   @0x265570 ldrb r3, [r3, #0x3]
 *   @0x265574 cmp r3, #61
 *   @0x265578 cmpne r3, #33
 *   @0x26557c bne 0x264fb8 <_pcre_ord2utf+0x5220>
 *   @0x265580 mov r5, #0
 *   @0x265584 mov r2, #1
 *   @0x265588 mov r3, r5
 *   @0x26558c str r2, [r9, #0x80]
 *   @0x265590 ldr r0, [sp, #0x40]
 *   @0x265594 mov r4, #135
 *   @0x265598 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x26559c ldrb r3, [r0, #0x5]
 *   @0x2655a0 sub r2, r3, #48
 *   @0x2655a4 cmp r2, #9
 *   @0x2655a8 bhi 0x2657b8 <_pcre_ord2utf+0x5a20>
 *   @0x2655ac mov r2, #3
 *   @0x2655b0 add r2, r2, #1
 *   @0x2655b4 ldrb r3, [r12, r2]
 *   @0x2655b8 mov r1, r2
 *   @0x2655bc sub r0, r3, #48
 *   @0x2655c0 cmp r0, #9
 *   @0x2655c4 bls 0x2655b0 <_pcre_ord2utf+0x5818>
 *   @0x2655c8 cmp r3, #41
 *   @0x2655cc addeq r3, r1, #1
 *   @0x2655d0 addeq r3, r12, r3
 *   @0x2655d4 movne r3, r12
 *   @0x2655d8 streq r3, [sp, #0x140]
 *   @0x2655dc ldrb r2, [r3]
 *   @0x2655e0 cmp r2, #40
 *   @0x2655e4 bne 0x2657c0 <_pcre_ord2utf+0x5a28>
 *   @0x2655e8 ldrb r2, [r3, #0x1]
 *   @0x2655ec cmp r2, #63
 *   @0x2655f0 bne 0x264fb8 <_pcre_ord2utf+0x5220>
 *   @0x2655f4 b 0x265558 <_pcre_ord2utf+0x57c0>
 *   @0x2655f8 mov r3, r12
 *   @0x2655fc mov r5, #41
 *   @0x265600 mov r12, #1
 *   @0x265604 b 0x262e58 <_pcre_ord2utf+0x30c0>
 *   @0x265608 add r3, r0, #3
 *   @0x26560c str r3, [sp, #0x13c]
 *   @0x265610 ldrb r3, [r0, #0x3]
 *   @0x265614 cmp r3, #41
 *   @0x265618 beq 0x2657fc <_pcre_ord2utf+0x5a64>
 *   @0x26561c ldr r2, [r9, #0x5c]
 *   @0x265620 mov r5, #0
 *   @0x265624 mov r3, r5
 *   @0x265628 ldr r0, [sp, #0x40]
 *   @0x26562c add r2, r2, #1
 *   @0x265630 mov r4, #126
 *   @0x265634 str r2, [r9, #0x5c]
 *   @0x265638 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x26563c add r3, sp, #440
 *   @0x265640 mov r1, r12
 *   @0x265644 mov r2, #0
 *   @0x265648 str r2, [sp, #0x158]
 *   @0x26564c str r2, [r3, #-0x64]!
 *   @0x265650 mov r11, r1
 *   @0x265654 add r1, r1, #1
 *   @0x265658 ldrb r2, [r11]
 *   @0x26565c cmp r2, #58
 *   @0x265660 cmpne r2, #41
 *   @0x265664 moveq r5, #0
 *   @0x265668 movne r5, #1
 *   @0x26566c beq 0x2658f0 <_pcre_ord2utf+0x5b58>
 *   @0x265670 str r1, [sp, #0x13c]
 *   @0x265674 ldrb r2, [r1, #-0x1]
 *   @0x265678 sub r2, r2, #45
 *   @0x26567c cmp r2, #75
 *   @0x265680 addls pc, pc, r2, lsl #2
 *   @0x265684 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265688 b 0x2658d8 <_pcre_ord2utf+0x5b40>
 *   @0x26568c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265690 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265694 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265698 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26569c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656a0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656a4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656a8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656ac b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656b0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656b4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656b8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656bc b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656c0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656c4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656c8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656cc b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656d0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656d4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656d8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656dc b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656e0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656e4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656e8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656ec b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656f0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656f4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656f8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2656fc b 0x2658bc <_pcre_ord2utf+0x5b24>
 *   @0x265700 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265704 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265708 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26570c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265710 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265714 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265718 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26571c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265720 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265724 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265728 b 0x2658ac <_pcre_ord2utf+0x5b14>
 *   @0x26572c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265730 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265734 b 0x26589c <_pcre_ord2utf+0x5b04>
 *   @0x265738 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26573c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265740 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265744 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265748 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26574c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265750 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265754 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265758 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26575c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265760 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265764 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265768 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26576c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265770 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265774 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265778 b 0x26588c <_pcre_ord2utf+0x5af4>
 *   @0x26577c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265780 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265784 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265788 b 0x26587c <_pcre_ord2utf+0x5ae4>
 *   @0x26578c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265790 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265794 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x265798 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x26579c b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2657a0 b 0x265848 <_pcre_ord2utf+0x5ab0>
 *   @0x2657a4 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2657a8 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2657ac b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2657b0 b 0x2658e0 <_pcre_ord2utf+0x5b48>
 *   @0x2657b4 b 0x265838 <_pcre_ord2utf+0x5aa0>
 *   @0x2657b8 mov r1, #3
 *   @0x2657bc b 0x2655c8 <_pcre_ord2utf+0x5830>
 *   @0x2657c0 mov r11, r12
 *   @0x2657c4 ldr r12, [sp, #0x48]
 *   @0x2657c8 mov r3, #28
 *   @0x2657cc str r3, [r12]
 *   @0x2657d0 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2657d4 mvn r12, #0
 *   @0x2657d8 str r12, [sp, #0x4c]
 *   @0x2657dc str r12, [sp, #0x58]
 *   @0x2657e0 mov r8, r6
 *   @0x2657e4 ldr r12, [sp, #0x70]
 *   @0x2657e8 mov r6, r3
 *   @0x2657ec ldr r11, [sp, #0x13c]
 *   @0x2657f0 ldr r7, [r9, #0x10]
 *   @0x2657f4 str r12, [sp, #0x80]
 *   @0x2657f8 b 0x260660 <_pcre_ord2utf+0x8c8>
 *   @0x2657fc ldrb r3, [r0, #0x4]
 *   @0x265800 sub r2, r3, #42
 *   @0x265804 cmp r2, #1
 *   @0x265808 bls 0x26561c <_pcre_ord2utf+0x5884>
 *   @0x26580c cmp r3, #63
 *   @0x265810 beq 0x26561c <_pcre_ord2utf+0x5884>
 *   @0x265814 cmp r3, #123
 *   @0x265818 beq 0x265858 <_pcre_ord2utf+0x5ac0>
 *   @0x26581c mvn r3, #98
 *   @0x265820 strb r3, [r6]
 *   @0x265824 add r12, r6, #1
 *   @0x265828 ldr r11, [sp, #0x13c]
 *   @0x26582c ldr r7, [r9, #0x10]
 *   @0x265830 mov r6, #0
 *   @0x265834 b 0x263168 <_pcre_ord2utf+0x33d0>
 *   @0x265838 ldr r2, [r3]
 *   @0x26583c orr r2, r2, #8
 *   @0x265840 str r2, [r3]
 *   @0x265844 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x265848 ldr r2, [r3]
 *   @0x26584c orr r2, r2, #4
 *   @0x265850 str r2, [r3]
 *   @0x265854 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x265858 ldrb r3, [r0, #0x5]
 *   @0x26585c add r0, r0, #5
 *   @0x265860 sub r3, r3, #48
 *   @0x265864 cmp r3, #9
 *   @0x265868 bhi 0x26581c <_pcre_ord2utf+0x5a84>
 *   @0x26586c bl 0x25ce14 <_Z26JS_Array_prototype_unshiftR6RValueP9CInstanceS2_iPS_+0x1cec>
 *   @0x265870 cmp r0, #0
 *   @0x265874 bne 0x26561c <_pcre_ord2utf+0x5884>
 *   @0x265878 b 0x26581c <_pcre_ord2utf+0x5a84>
 *   @0x26587c ldr r2, [r3]
 *   @0x265880 orr r2, r2, #2
 *   @0x265884 str r2, [r3]
 *   @0x265888 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x26588c ldr r2, [r3]
 *   @0x265890 orr r2, r2, #1
 *   @0x265894 str r2, [r3]
 *   @0x265898 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x26589c ldr r2, [r3]
 *   @0x2658a0 orr r2, r2, #64
 *   @0x2658a4 str r2, [r3]
 *   @0x2658a8 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x2658ac ldr r2, [r3]
 *   @0x2658b0 orr r2, r2, #512
 *   @0x2658b4 str r2, [r3]
 *   @0x2658b8 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x2658bc ldr r0, [r3]
 *   @0x2658c0 ldr r2, [r9, #0x64]
 *   @0x2658c4 orr r0, r0, #524288
 *   @0x2658c8 str r0, [r3]
 *   @0x2658cc orr r2, r2, #1024
 *   @0x2658d0 str r2, [r9, #0x64]
 *   @0x2658d4 b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x2658d8 add r3, sp, #344
 *   @0x2658dc b 0x265650 <_pcre_ord2utf+0x58b8>
 *   @0x2658e0 ldr r12, [sp, #0x48]
 *   @0x2658e4 mov r3, #12
 *   @0x2658e8 str r3, [r12]
 *   @0x2658ec b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2658f0 ldr r0, [sp, #0x154]
 *   @0x2658f4 cmp r2, #41
 *   @0x2658f8 ldr r3, [sp, #0x158]
 *   @0x2658fc ldr r12, [sp, #0x40]
 *   @0x265900 orr r0, r0, r12
 *   @0x265904 bic r0, r0, r3
 *   @0x265908 beq 0x265a40 <_pcre_ord2utf+0x5ca8>
 *   @0x26590c add r11, r11, #1
 *   @0x265910 mov r3, r5
 *   @0x265914 str r11, [sp, #0x13c]
 *   @0x265918 mov r4, #131
 *   @0x26591c b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265920 mov r3, #118
 *   @0x265924 strb r3, [r6]
 *   @0x265928 ldr r2, [sp, #0x13c]
 *   @0x26592c add r3, r2, #1
 *   @0x265930 str r3, [sp, #0x13c]
 *   @0x265934 ldrb r1, [r2, #0x1]
 *   @0x265938 sub r0, r1, #48
 *   @0x26593c cmp r0, #9
 *   @0x265940 bhi 0x265acc <_pcre_ord2utf+0x5d34>
 *   @0x265944 add r2, r2, #2
 *   @0x265948 mov r3, #0
 *   @0x26594c str r2, [sp, #0x13c]
 *   @0x265950 mov r12, r2
 *   @0x265954 ldrb r0, [r2, #-0x1]
 *   @0x265958 add r3, r3, r3, lsl #2
 *   @0x26595c ldrb r1, [r2], #1
 *   @0x265960 add r3, r0, r3, lsl #1
 *   @0x265964 sub r0, r1, #48
 *   @0x265968 sub r3, r3, #48
 *   @0x26596c cmp r0, #9
 *   @0x265970 bls 0x26594c <_pcre_ord2utf+0x5bb4>
 *   @0x265974 cmp r1, #41
 *   @0x265978 bne 0x265b3c <_pcre_ord2utf+0x5da4>
 *   @0x26597c cmp r3, #255
 *   @0x265980 ble 0x265b34 <_pcre_ord2utf+0x5d9c>
 *   @0x265984 mov r11, r12
 *   @0x265988 ldr r12, [sp, #0x48]
 *   @0x26598c mov r3, #38
 *   @0x265990 str r3, [r12]
 *   @0x265994 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265998 ldr r12, [sp, #0x48]
 *   @0x26599c mov r11, r3
 *   @0x2659a0 mov r3, #41
 *   @0x2659a4 str r3, [r12]
 *   @0x2659a8 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x2659ac subs r1, r1, #62
 *   @0x2659b0 mov r5, #41
 *   @0x2659b4 rsbs r12, r1, #0
 *   @0x2659b8 adcs r12, r12, r1
 *   @0x2659bc b 0x262e58 <_pcre_ord2utf+0x30c0>
 *   @0x2659c0 ldr r2, [r9, #0x5c]
 *   @0x2659c4 mov r5, #0
 *   @0x2659c8 add r0, r0, #3
 *   @0x2659cc mov r3, r5
 *   @0x2659d0 str r0, [sp, #0x13c]
 *   @0x2659d4 add r2, r2, #1
 *   @0x2659d8 ldr r0, [sp, #0x40]
 *   @0x2659dc mov r4, #125
 *   @0x2659e0 str r2, [r9, #0x5c]
 *   @0x2659e4 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x2659e8 ldrb r3, [r0, #0x3]
 *   @0x2659ec cmp r3, #33
 *   @0x2659f0 beq 0x265a90 <_pcre_ord2utf+0x5cf8>
 *   @0x2659f4 cmp r3, #61
 *   @0x2659f8 bne 0x265a6c <_pcre_ord2utf+0x5cd4>
 *   @0x2659fc ldr r2, [r9, #0x5c]
 *   @0x265a00 mov r5, #0
 *   @0x265a04 add r0, r0, #4
 *   @0x265a08 mov r3, r5
 *   @0x265a0c str r0, [sp, #0x13c]
 *   @0x265a10 add r2, r2, #1
 *   @0x265a14 ldr r0, [sp, #0x40]
 *   @0x265a18 mov r4, #127
 *   @0x265a1c str r2, [r9, #0x5c]
 *   @0x265a20 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265a24 mov r5, #0
 *   @0x265a28 add r0, r0, #3
 *   @0x265a2c mov r3, r5
 *   @0x265a30 str r0, [sp, #0x13c]
 *   @0x265a34 mov r4, #129
 *   @0x265a38 ldr r0, [sp, #0x40]
 *   @0x265a3c b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265a40 ubfx r12, r0, #0x9, #0x1
 *   @0x265a44 str r12, [sp, #0xb0]
 *   @0x265a48 ldr r1, [sp, #0xb0]
 *   @0x265a4c mov r12, r6
 *   @0x265a50 and r2, r0, #1
 *   @0x265a54 mov r6, r5
 *   @0x265a58 eor r1, r1, #1
 *   @0x265a5c str r2, [sp, #0x98]
 *   @0x265a60 str r1, [sp, #0xe4]
 *   @0x265a64 str r0, [sp, #0x40]
 *   @0x265a68 b 0x263168 <_pcre_ord2utf+0x33d0>
 *   @0x265a6c ldr r2, [r9, #0xc]
 *   @0x265a70 ldrb r3, [r2, r3]
 *   @0x265a74 tst r3, #16
 *   @0x265a78 bne 0x263d38 <_pcre_ord2utf+0x3fa0>
 *   @0x265a7c ldr r12, [sp, #0x48]
 *   @0x265a80 mov r3, #24
 *   @0x265a84 add r11, r0, #3
 *   @0x265a88 str r3, [r12]
 *   @0x265a8c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265a90 ldr r2, [r9, #0x5c]
 *   @0x265a94 mov r5, #0
 *   @0x265a98 add r0, r0, #4
 *   @0x265a9c mov r3, r5
 *   @0x265aa0 str r0, [sp, #0x13c]
 *   @0x265aa4 add r2, r2, #1
 *   @0x265aa8 ldr r0, [sp, #0x40]
 *   @0x265aac mov r4, #128
 *   @0x265ab0 str r2, [r9, #0x5c]
 *   @0x265ab4 b 0x26087c <_pcre_ord2utf+0xae4>
 *   @0x265ab8 ldr r12, [sp, #0x48]
 *   @0x265abc mov r3, #48
 *   @0x265ac0 ldr r11, [sp, #0x13c]
 *   @0x265ac4 str r3, [r12]
 *   @0x265ac8 b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265acc cmp r1, #41
 *   @0x265ad0 bne 0x265b50 <_pcre_ord2utf+0x5db8>
 *   @0x265ad4 mov r3, #0
 *   @0x265ad8 strb r3, [r6, #0x1]
 *   @0x265adc mov r0, #1
 *   @0x265ae0 ldr r2, [r9, #0x18]
 *   @0x265ae4 mov r3, #0
 *   @0x265ae8 ldr r1, [sp, #0x13c]
 *   @0x265aec add r12, r6, #6
 *   @0x265af0 str r6, [sp, #0x7c]
 *   @0x265af4 rsb r2, r2, r1
 *   @0x265af8 str r0, [sp, #0xbc]
 *   @0x265afc add r2, r2, r0
 *   @0x265b00 asr r2, r2, #8
 *   @0x265b04 strb r2, [r6, #0x2]
 *   @0x265b08 ldr r1, [sp, #0x13c]
 *   @0x265b0c ldr r2, [r9, #0x18]
 *   @0x265b10 strb r3, [r6, #0x4]
 *   @0x265b14 rsb r2, r2, r1
 *   @0x265b18 strb r3, [r6, #0x5]
 *   @0x265b1c add r2, r2, r0
 *   @0x265b20 strb r2, [r6, #0x3]
 *   @0x265b24 ldr r11, [sp, #0x13c]
 *   @0x265b28 mov r6, r3
 *   @0x265b2c ldr r7, [r9, #0x10]
 *   @0x265b30 b 0x263168 <_pcre_ord2utf+0x33d0>
 *   @0x265b34 uxtb r3, r3
 *   @0x265b38 b 0x265ad8 <_pcre_ord2utf+0x5d40>
 *   @0x265b3c mov r11, r12
 *   @0x265b40 ldr r12, [sp, #0x48]
 *   @0x265b44 mov r3, #39
 *   @0x265b48 str r3, [r12]
 *   @0x265b4c b 0x2632d4 <_pcre_ord2utf+0x353c>
 *   @0x265b50 mov r11, r3
 *   @0x265b54 b 0x265b40 <_pcre_ord2utf+0x5da8>
 *
 * ══ §6/8 anon_276e68  0x276e68..0x277324  size 1212  303 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_26f1e8
 * @func 0x276e68 0x277324  size 1212  303 条
 * ⚠ 父块 anon_26f1e8 是 41,380 B 的未闭合大状态机（METHOD §4）：段长不一定等于函数长，本段可能只是其中的一段
 * 入度 15｜调用者: 0x272698(anon_26f1e8+0x34b0), 0x272714(anon_26f1e8+0x352c), 0x27280c(anon_26f1e8+0x3624), 0x277630(anon_26f1e8+0x8448), 0x2785d0(anon_26f1e8+0x93e8), 0x278b50(anon_26f1e8+0x9968), 0x278b64(anon_26f1e8+0x997c), 0x278b80(anon_26f1e8+0x9998)…
 * 出调用 4 处 → anon_26f1e8+0x3310×1, anon_26f1e8×1, anon_26f1e8+0x9ef8×1, anon_26f1e8+0xa12c×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x276e68 ldrb r1, [r10, #-0x2]
 *   @0x276e6c and r0, r0, #63
 *   @0x276e70 orr r3, r3, r12, lsl #18
 *   @0x276e74 and r1, r1, #63
 *   @0x276e78 orr r3, r3, r0, lsl #12
 *   @0x276e7c orr r3, r3, r1, lsl #6
 *   @0x276e80 b 0x272054 <pcre_dfa_exec+0x3aec>
 *   @0x276e84 ldrb r12, [r10, #0x5]
 *   @0x276e88 and r3, r3, #1
 *   @0x276e8c ldrb r0, [r10, #0x1]
 *   @0x276e90 add r10, r10, #6
 *   @0x276e94 and r12, r12, #63
 *   @0x276e98 ldrb r4, [r10, #-0x4]
 *   @0x276e9c and r0, r0, #63
 *   @0x276ea0 orr r3, r12, r3, lsl #30
 *   @0x276ea4 ldrb r12, [r10, #-0x3]
 *   @0x276ea8 and r4, r4, #63
 *   @0x276eac orr r3, r3, r0, lsl #24
 *   @0x276eb0 ldrb r0, [r10, #-0x2]
 *   @0x276eb4 and r12, r12, #63
 *   @0x276eb8 orr r3, r3, r4, lsl #18
 *   @0x276ebc and r0, r0, #63
 *   @0x276ec0 orr r3, r3, r12, lsl #12
 *   @0x276ec4 orr r3, r3, r0, lsl #6
 *   @0x276ec8 b 0x271ae4 <pcre_dfa_exec+0x357c>
 *   @0x276ecc ldrb r0, [r10, #0x5]
 *   @0x276ed0 and r3, r3, #1
 *   @0x276ed4 ldrb r1, [r10, #0x1]
 *   @0x276ed8 add r10, r10, #6
 *   @0x276edc and r0, r0, #63
 *   @0x276ee0 ldrb r12, [r10, #-0x4]
 *   @0x276ee4 and r1, r1, #63
 *   @0x276ee8 orr r3, r0, r3, lsl #30
 *   @0x276eec ldrb r0, [r10, #-0x3]
 *   @0x276ef0 and r12, r12, #63
 *   @0x276ef4 orr r3, r3, r1, lsl #24
 *   @0x276ef8 ldrb r1, [r10, #-0x2]
 *   @0x276efc and r0, r0, #63
 *   @0x276f00 orr r3, r3, r12, lsl #18
 *   @0x276f04 and r1, r1, #63
 *   @0x276f08 orr r3, r3, r0, lsl #12
 *   @0x276f0c orr r3, r3, r1, lsl #6
 *   @0x276f10 b 0x271c8c <pcre_dfa_exec+0x3724>
 *   @0x276f14 tst r3, #8
 *   @0x276f18 bne 0x277fcc <pcre_dfa_exec+0x9a64>
 *   @0x276f1c ldrb r0, [r2, #0x3]
 *   @0x276f20 and r3, r3, #7
 *   @0x276f24 ldrb r1, [r2, #0x1]
 *   @0x276f28 ldrb r2, [r2, #0x2]
 *   @0x276f2c and r0, r0, #63
 *   @0x276f30 and r1, r1, #63
 *   @0x276f34 orr r3, r0, r3, lsl #18
 *   @0x276f38 and r2, r2, #63
 *   @0x276f3c orr r3, r3, r1, lsl #12
 *   @0x276f40 orr r3, r3, r2, lsl #6
 *   @0x276f44 b 0x270870 <pcre_dfa_exec+0x2308>
 *   @0x276f48 mov r4, r10
 *   @0x276f4c ldr r2, [r6, #0x88]
 *   @0x276f50 cmp r2, #0
 *   @0x276f54 beq 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x276f58 ldr r3, [r6, #0x84]
 *   @0x276f5c cmp r3, r4
 *   @0x276f60 bhs 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x276f64 cmp r2, #1
 *   @0x276f68 mov r7, #1
 *   @0x276f6c str r7, [r6, #0x64]
 *   @0x276f70 ble 0x2724f8 <pcre_dfa_exec+0x3f90>
 *   @0x276f74 b 0x272678 <pcre_dfa_exec+0x4110>
 *   @0x276f78 mov r0, #0
 *   @0x276f7c b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x276f80 ldrb r2, [r7, #0x5]
 *   @0x276f84 and r3, r3, #1
 *   @0x276f88 ldrb r1, [r7, #0x1]
 *   @0x276f8c and r2, r2, #63
 *   @0x276f90 ldrb r4, [r7, #0x2]
 *   @0x276f94 and r1, r1, #63
 *   @0x276f98 orr r3, r2, r3, lsl #30
 *   @0x276f9c ldrb r2, [r7, #0x3]
 *   @0x276fa0 and r4, r4, #63
 *   @0x276fa4 orr r3, r3, r1, lsl #24
 *   @0x276fa8 ldrb r1, [r7, #0x4]
 *   @0x276fac and r2, r2, #63
 *   @0x276fb0 orr r3, r3, r4, lsl #18
 *   @0x276fb4 and r1, r1, #63
 *   @0x276fb8 orr r3, r3, r2, lsl #12
 *   @0x276fbc mov r2, #6
 *   @0x276fc0 orr r3, r3, r1, lsl r2
 *   @0x276fc4 b 0x276200 <pcre_dfa_exec+0x7c98>
 *   @0x276fc8 ldrb r12, [r10, #0x5]
 *   @0x276fcc and r3, r3, #1
 *   @0x276fd0 ldrb r0, [r10, #0x1]
 *   @0x276fd4 add r10, r10, #6
 *   @0x276fd8 and r12, r12, #63
 *   @0x276fdc ldrb r4, [r10, #-0x4]
 *   @0x276fe0 and r0, r0, #63
 *   @0x276fe4 orr r3, r12, r3, lsl #30
 *   @0x276fe8 ldrb r12, [r10, #-0x3]
 *   @0x276fec and r4, r4, #63
 *   @0x276ff0 orr r3, r3, r0, lsl #24
 *   @0x276ff4 ldrb r0, [r10, #-0x2]
 *   @0x276ff8 and r12, r12, #63
 *   @0x276ffc orr r3, r3, r4, lsl #18
 *   @0x277000 and r0, r0, #63
 *   @0x277004 orr r3, r3, r12, lsl #12
 *   @0x277008 orr r3, r3, r0, lsl #6
 *   @0x27700c b 0x271bfc <pcre_dfa_exec+0x3694>
 *   @0x277010 mov r0, #0
 *   @0x277014 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277018 str r5, [sp, #0x20]
 *   @0x27701c mov r4, r11
 *   @0x277020 ldr r5, [sp, #0x28]
 *   @0x277024 str r7, [sp, #0x24]
 *   @0x277028 mov r7, r8
 *   @0x27702c cmp r5, #0
 *   @0x277030 ldr r11, [sp, #0x18]
 *   @0x277034 beq 0x277904 <pcre_dfa_exec+0x939c>
 *   @0x277038 mov r9, #1
 *   @0x27703c movw r5, #0x202f
 *   @0x277040 movw r8, #0x205f
 *   @0x277044 add r12, r6, #28
 *   @0x277048 str r12, [sp, #0x18]
 *   @0x27704c ldr r12, [sp, #0x164]
 *   @0x277050 mov r0, r10
 *   @0x277054 ldr r3, [sp, #0x168]
 *   @0x277058 mov r1, r4
 *   @0x27705c str r6, [sp]
 *   @0x277060 add r3, r3, #1
 *   @0x277064 str r12, [sp, #0x4]
 *   @0x277068 str r3, [sp, #0x8]
 *   @0x27706c mov r3, r11
 *   @0x277070 ldr r2, [sp, #0x1c]
 *   @0x277074 bl 0x26f1e8 <pcre_dfa_exec+0xc80>
 *   @0x277078 cmp r0, #0
 *   @0x27707c bne 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277080 ldr r12, [sp, #0x24]
 *   @0x277084 cmp r7, r12
 *   @0x277088 bge 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x27708c ldr r2, [r6, #0x78]
 *   @0x277090 cmp r10, r2
 *   @0x277094 bhs 0x272d58 <pcre_dfa_exec+0x47f0>
 *   @0x277098 ldr r12, [sp, #0x20]
 *   @0x27709c cmp r12, #12
 *   @0x2770a0 beq 0x277558 <pcre_dfa_exec+0x8ff0>
 *   @0x2770a4 ldrb r3, [r10]
 *   @0x2770a8 cmp r3, #191
 *   @0x2770ac bls 0x277304 <pcre_dfa_exec+0x8d9c>
 *   @0x2770b0 tst r3, #32
 *   @0x2770b4 bne 0x277604 <pcre_dfa_exec+0x909c>
 *   @0x2770b8 ldrb r2, [r10, #0x1]
 *   @0x2770bc and r3, r3, #31
 *   @0x2770c0 add r10, r10, #2
 *   @0x2770c4 and r2, r2, #63
 *   @0x2770c8 orr r3, r2, r3, lsl #6
 *   @0x2770cc ldr r12, [sp, #0x20]
 *   @0x2770d0 sub r2, r12, #6
 *   @0x2770d4 cmp r2, #15
 *   @0x2770d8 addls pc, pc, r2, lsl #2
 *   @0x2770dc b 0x277234 <pcre_dfa_exec+0x8ccc>
 *   @0x2770e0 b 0x277218 <pcre_dfa_exec+0x8cb0>
 *   @0x2770e4 b 0x2771fc <pcre_dfa_exec+0x8c94>
 *   @0x2770e8 b 0x2771e0 <pcre_dfa_exec+0x8c78>
 *   @0x2770ec b 0x2771c4 <pcre_dfa_exec+0x8c5c>
 *   @0x2770f0 b 0x2771a8 <pcre_dfa_exec+0x8c40>
 *   @0x2770f4 b 0x27718c <pcre_dfa_exec+0x8c24>
 *   @0x2770f8 b 0x277140 <pcre_dfa_exec+0x8bd8>
 *   @0x2770fc b 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277100 b 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277104 b 0x277234 <pcre_dfa_exec+0x8ccc>
 *   @0x277108 b 0x277234 <pcre_dfa_exec+0x8ccc>
 *   @0x27710c b 0x2772a8 <pcre_dfa_exec+0x8d40>
 *   @0x277110 b 0x27727c <pcre_dfa_exec+0x8d14>
 *   @0x277114 b 0x2772d0 <pcre_dfa_exec+0x8d68>
 *   @0x277118 b 0x27725c <pcre_dfa_exec+0x8cf4>
 *   @0x27711c b 0x27723c <pcre_dfa_exec+0x8cd4>
 *   @0x277120 ldr r3, [r6, #0x78]
 *   @0x277124 cmp r10, r3
 *   @0x277128 bhs 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x27712c ldrb r3, [r10]
 *   @0x277130 cmp r3, #10
 *   @0x277134 addeq r10, r10, #1
 *   @0x277138 add r7, r7, #1
 *   @0x27713c b 0x27704c <pcre_dfa_exec+0x8ae4>
 *   @0x277140 ldr r2, [r6, #0x88]
 *   @0x277144 cmp r2, #0
 *   @0x277148 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x27714c ldr r1, [r6, #0x78]
 *   @0x277150 cmp r10, r1
 *   @0x277154 blo 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277158 ldr r1, [r6, #0x18]
 *   @0x27715c cmp r1, #0
 *   @0x277160 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277164 ldr r1, [r6, #0x1c]
 *   @0x277168 cmp r1, #2
 *   @0x27716c bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277170 ldrb r1, [r6, #0x34]
 *   @0x277174 cmp r1, r3
 *   @0x277178 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x27717c cmp r2, #1
 *   @0x277180 str r9, [r6, #0x64]
 *   @0x277184 ble 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277188 b 0x26f728 <pcre_dfa_exec+0x11c0>
 *   @0x27718c cmp r3, #255
 *   @0x277190 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277194 ldr r2, [r6, #0x40]
 *   @0x277198 ldrb r3, [r2, r3]
 *   @0x27719c tst r3, #16
 *   @0x2771a0 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771a4 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2771a8 cmp r3, #255
 *   @0x2771ac bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771b0 ldr r2, [r6, #0x40]
 *   @0x2771b4 ldrb r3, [r2, r3]
 *   @0x2771b8 tst r3, #16
 *   @0x2771bc beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771c0 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2771c4 cmp r3, #255
 *   @0x2771c8 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2771cc ldr r2, [r6, #0x40]
 *   @0x2771d0 ldrb r3, [r2, r3]
 *   @0x2771d4 tst r3, #1
 *   @0x2771d8 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771dc b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2771e0 cmp r3, #255
 *   @0x2771e4 bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771e8 ldr r2, [r6, #0x40]
 *   @0x2771ec ldrb r3, [r2, r3]
 *   @0x2771f0 tst r3, #1
 *   @0x2771f4 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2771f8 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2771fc cmp r3, #255
 *   @0x277200 bhi 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277204 ldr r2, [r6, #0x40]
 *   @0x277208 ldrb r3, [r2, r3]
 *   @0x27720c tst r3, #4
 *   @0x277210 bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277214 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277218 cmp r3, #255
 *   @0x27721c bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277220 ldr r2, [r6, #0x40]
 *   @0x277224 ldrb r3, [r2, r3]
 *   @0x277228 tst r3, #4
 *   @0x27722c beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277230 b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x277234 mvn r0, #13
 *   @0x277238 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27723c cmp r3, #133
 *   @0x277240 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277244 bhi 0x278b54 <pcre_dfa_exec+0xa5ec>
 *   @0x277248 sub r3, r3, #10
 *   @0x27724c cmp r3, #3
 *   @0x277250 bls 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277254 mov r0, #0
 *   @0x277258 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27725c cmp r3, #133
 *   @0x277260 beq 0x277274 <pcre_dfa_exec+0x8d0c>
 *   @0x277264 bhi 0x278e38 <pcre_dfa_exec+0xa8d0>
 *   @0x277268 sub r3, r3, #10
 *   @0x27726c cmp r3, #3
 *   @0x277270 bhi 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x277274 mov r0, #0
 *   @0x277278 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x27727c movw r0, #0x180e
 *   @0x277280 cmp r3, r0
 *   @0x277284 beq 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x277288 bhi 0x278b84 <pcre_dfa_exec+0xa61c>
 *   @0x27728c cmp r3, #32
 *   @0x277290 beq 0x2772a0 <pcre_dfa_exec+0x8d38>
 *   @0x277294 bhi 0x278b70 <pcre_dfa_exec+0xa608>
 *   @0x277298 cmp r3, #9
 *   @0x27729c bne 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772a0 mov r0, #0
 *   @0x2772a4 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x2772a8 cmp r3, #13
 *   @0x2772ac beq 0x277120 <pcre_dfa_exec+0x8bb8>
 *   @0x2772b0 bhi 0x2790c4 <pcre_dfa_exec+0xab5c>
 *   @0x2772b4 cmp r3, #10
 *   @0x2772b8 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772bc blo 0x2790e0 <pcre_dfa_exec+0xab78>
 *   @0x2772c0 ldr r3, [r6, #0x68]
 *   @0x2772c4 cmp r3, #0
 *   @0x2772c8 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772cc b 0x270008 <pcre_dfa_exec+0x1aa0>
 *   @0x2772d0 movw r1, #0x180e
 *   @0x2772d4 cmp r3, r1
 *   @0x2772d8 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772dc bhi 0x278b34 <pcre_dfa_exec+0xa5cc>
 *   @0x2772e0 cmp r3, #32
 *   @0x2772e4 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772e8 bls 0x279314 <pcre_dfa_exec+0xadac>
 *   @0x2772ec cmp r3, #160
 *   @0x2772f0 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772f4 cmp r3, #5760
 *   @0x2772f8 beq 0x277138 <pcre_dfa_exec+0x8bd0>
 *   @0x2772fc mov r0, #0
 *   @0x277300 b 0x26f5a0 <pcre_dfa_exec+0x1038>
 *   @0x277304 add r10, r10, #1
 *   @0x277308 b 0x2770cc <pcre_dfa_exec+0x8b64>
 *   @0x27730c mov r4, r10
 *   @0x277310 ldr r2, [r6, #0x88]
 *   @0x277314 b 0x272654 <pcre_dfa_exec+0x40ec>
 *   @0x277318 ldr r3, [r6, #0x88]
 *   @0x27731c cmp r3, #0
 *   @0x277320 beq 0x270008 <pcre_dfa_exec+0x1aa0>
 *
 * ══ §7/8 anon_2fc4e8  0x2fc4e8..0x2fcdf0  size 2312  578 条｜ISA ARM｜入口证据 bl｜父块 anon_2fc4e8
 * @func 0x2fc4e8 0x2fcdf0  size 2312  578 条
 * 入度 5｜调用者: 0x2fb404(anon_2fa330+0x10d4), 0x2fc0bc(anonT_2fb894+0x828), 0x2fc0e0(anonT_2fb894+0x84c), 0x2fc2a2(anonT_2fb894+0xa0e), 0x2feefe(anonT_2fec70+0x28e)
 * 出调用 27 处 → 0x14ba5ec×1, anon_30a7b2+0x375c×1, 0x20ba65a×1, 0x4cdfe0×1, 0x4dd1ec×1, 0x51d1e4×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2fc4e8 adclo pc, r8, #12910592
 *   @0x2fc4ec andslt r9, r3, r10, lsl #16
 *   @0x2fc4f0 svchi #0xf0e8bd
 *   @0x2fc4f4 .word 0xf7ff2301
 *   @0x2fc4f8 ldrblt r11, [r0, #-0xdbf]!
 *   @0x2fc4fc .word 0xf8d0460e
 *   @0x2fc500 .word 0x460412b8
 *   @0x2fc504 cmplt r1, r5, lsl r6
 *   @0x2fc508 adcshs pc, r8, #212, #16
 *   @0x2fc50c adcseq pc, r5, #148, #16
 *   @0x2fc510 addsmi r6, lr, #1245184
 *   @0x2fc514 shasxmi r11, r3, r8
 *   @0x2fc518 .word 0x4602b930
 *   @0x2fc51c .word 0xf7ffe00f
 *   @0x2fc520 stmdahs r0, {r0, r1, r3, r5, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2fc524 ldcllt p0, c13, [r0, #-960]!
 *   @0x2fc528 mulhs r0, r12, r0
 *   @0x2fc52c andle r4, r4, r0, lsr #5
 *   @0x2fc530 stmdapl r9, {r0, r4, r6, r11, sp, lr}
 *   @0x2fc534 andlo r5, r4, r9, lsr #32
 *   @0x2fc538 andhs lr, r0, #248, #14
 *   @0x2fc53c addsmi lr, r8, #5
 *   @0x2fc540 .word 0xf845d0fb
 *   @0x2fc544 andlo r2, r1, r0, lsr #32
 *   @0x2fc548 adcsmi lr, r3, #65273856
 *   @0x2fc54c .word 0xf845d203
 *   @0x2fc550 movwlo r2, #0x1023
 *   @0x2fc554 strdhs lr, pc, [r0], -r9
 *   @0x2fc558 ldrblt r11, [r0, #-0xd70]!
 *   @0x2fc55c .word 0xf8d0460e
 *   @0x2fc560 .word 0x460412b8
 *   @0x2fc564 cmplt r1, r5, lsl r6
 *   @0x2fc568 adcshs pc, r8, #212, #16
 *   @0x2fc56c adcseq pc, r5, #148, #16
 *   @0x2fc570 addsmi r6, lr, #1245184
 *   @0x2fc574 shasxmi r11, r3, r8
 *   @0x2fc578 .word 0x4602b930
 *   @0x2fc57c .word 0xf7ffe00f
 *   @0x2fc580 stmdahs r0, {r0, r1, r3, r4, r5, r6, r9, r11, r12, sp, lr, pc}
 *   @0x2fc584 ldcllt p0, c13, [r0, #-960]!
 *   @0x2fc588 mulhs r0, r12, r0
 *   @0x2fc58c andle r4, r4, r0, lsr #5
 *   @0x2fc590 stmdapl r9, {r0, r4, r7, r11, sp, lr}
 *   @0x2fc594 andlo r5, r4, r9, lsr #32
 *   @0x2fc598 andhs lr, r0, #248, #14
 *   @0x2fc59c addsmi lr, r8, #5
 *   @0x2fc5a0 .word 0xf845d0fb
 *   @0x2fc5a4 andlo r2, r1, r0, lsr #32
 *   @0x2fc5a8 adcsmi lr, r3, #65273856
 *   @0x2fc5ac .word 0xf845d203
 *   @0x2fc5b0 movwlo r2, #0x1023
 *   @0x2fc5b4 strdhs lr, pc, [r0], -r9
 *   @0x2fc5b8 push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2fc5bc .word 0x460f43f0
 *   @0x2fc5c0 .word 0xf8d0b085
 *   @0x2fc5c4 movwhs r1, #0x2b8
 *   @0x2fc5c8 ldrmi r4, [r1], r4, lsl #12
 *   @0x2fc5cc .word 0xf8d09303
 *   @0x2fc5d0 .word 0xb1498064
 *   @0x2fc5d4 adcspl pc, r8, #212, #16
 *   @0x2fc5d8 stmdavs r10!, {r1, r2, r3, r5, r6, r7, r11, sp, lr} ^
 *   @0x2fc5dc addsmi r6, pc, #3342336
 *   @0x2fc5e0 ldrmi r11, [pc], -r8, lsr #30
 *   @0x2fc5e4 mul r6, r2, r9
 *   @0x2fc5e8 blx 0x14ba5ec <b2_toiTime+0xd61148>
 *   @0x2fc5ec stmdahs r0, {r0, r1, r12, pc}
 *   @0x2fc5f0 strhs sp, [r0, #-0xf0]
 *   @0x2fc5f4 stmdbge r3, {r6, sp, lr, pc}
 *   @0x2fc5f8 .word 0x91019200
 *   @0x2fc5fc .word 0x21044640
 *   @0x2fc600 stc2l p7, c15, [r5, #-940]
 *   @0x2fc604 rsbvs r9, r8, r3, lsl #22
 *   @0x2fc608 mvnsle r2, r0, lsl #22
 *   @0x2fc60c stmdavs r8!, {r0, r1, r3, r4, r5, r7} ^
 *   @0x2fc610 ldrmi r4, [r10], -r9, asr #12
 *   @0x2fc614 .word 0xf5b9461d
 *   @0x2fc618 ldmvs r3!, {r1, r4, r6, r7, r8, r9, r10, r11, sp, lr, pc} ^
 *   @0x2fc61c strbmi r2, [sp], #-24
 *   @0x2fc620 blx 0x30df0e <af_shaper_get_elem+0x377c>
 *   @0x2fc624 ldmdavs r3!, {r0, r1, r2, r12, sp}
 *   @0x2fc628 andle r4, r5, #-1879048183
 *   @0x2fc62c smlabblo r1, r3, r8, r6
 *   @0x2fc630 .word 0xf8453018
 *   @0x2fc634 ldrb r3, [r6, r4, lsl #22]!
 *   @0x2fc638 stmdbge r3, {r9, sp}
 *   @0x2fc63c strbmi r9, [r0], -r0, lsl #4
 *   @0x2fc640 .word 0x21049101
 *   @0x2fc644 stc2 p7, c15, [r3, #-940]!
 *   @0x2fc648 strmi r9, [r5], -r3, lsl #22
 *   @0x2fc64c .word 0xf8d4b9a3
 *   @0x2fc650 mrcvc p2, #0x0, r3, c11, c8, #0x5
 *   @0x2fc654 qadd16mi r11, r0, r3
 *   @0x2fc658 blx 0x20ba65a <b2_toiTime+0x19611b6>
 *   @0x2fc65c adcseq pc, r8, #212, #16
 *   @0x2fc660 .word 0x464a4639
 *   @0x2fc664 .word 0xf7ff462b
 *   @0x2fc668 strtmi pc, [r0], -r8, lsl #19
 *   @0x2fc66c qasxmi r6, r10, r1
 *   @0x2fc670 .word 0xf7ff2300
 *   @0x2fc674 andls pc, r3, r1, lsl #26
 *   @0x2fc678 strtmi r4, [r9], -r0, asr #12
 *   @0x2fc67c cdp2 p7, #0x5, c15, c11, c10, #0x7
 *   @0x2fc680 andlt r9, r5, r3, lsl #16
 *   @0x2fc684 mvnshi lr, #12386304
 *   @0x2fc688 svcmi #0xf0e92d
 *   @0x2fc68c stclmi p6, c4, [r4, #608]
 *   @0x2fc690 strmi r11, [r12], -r7, lsr #1
 *   @0x2fc694 ldrbtmi r4, [sp], #-1665
 *   @0x2fc698 andls r6, r7, #2949120
 *   @0x2fc69c stmdavs r11!, {r4, r5, r9, r10, r11, r12, pc}
 *   @0x2fc6a0 cdpvs p3, #0x0, c9, c11, c5, #0x1
 *   @0x2fc6a4 ldmdavs r8, {r0, r1, r2, r3, r4, r5, r7, r8, r11, lr} ^
 *   @0x2fc6a8 .word 0xf7e94479
 *   @0x2fc6ac strls pc, [r12, #-0xc3d]
 *   @0x2fc6b0 stmdahs r0, {r3, r12, pc}
 *   @0x2fc6b4 sbcshi pc, r9, #0
 *   @0x2fc6b8 .word 0x21004648
 *   @0x2fc6bc .word 0xf8f3f7ea
 *   @0x2fc6c0 .word 0xf0402800
 *   @0x2fc6c4 stmdbls r8, {r3, r4, r6, r7, r9, pc}
 *   @0x2fc6c8 strls r4, [r0], -r8, asr #12
 *   @0x2fc6cc bls 0x4cdfe0 <SrcVerts+0x2b024>
 *   @0x2fc6d0 strtmi r6, [r1], -sp, asr #16
 *   @0x2fc6d4 cdpvs p7, #0xa, c4, c5, c8, #0x5
 *   @0x2fc6d8 .word 0xf0402800
 *   @0x2fc6dc .word 0xf8d482cc
 *   @0x2fc6e0 .word 0xf5b33094
 *   @0x2fc6e4 andle r3, r6, r0, lsl #31
 *   @0x2fc6e8 svclo #0xf5b3
 *   @0x2fc6ec bmi 0xfecf0700 <b2_toiTime+0xfffffffffe59725c>
 *   @0x2fc6f0 .word 0xf0404293
 *   @0x2fc6f4 bls 0x4dd1ec <SrcVerts+0x3a230>
 *   @0x2fc6f8 bhs 0x31698c <FT_Bitmap_Embolden+0x1b46>
 *   @0x2fc6fc movwvs pc, #0x443
 *   @0x2fc700 vaddl.s8 q11, d16, d19
 *   @0x2fc704 blls 0x51d1e4 <SrcVerts+0x7a228>
 *   @0x2fc708 strls r4, [r0], -r8, lsr #12
 *   @0x2fc70c ldmvs lr, {r0, r5, r9, r10, lr}
 *   @0x2fc710 ldrmi r4, [r0, r3, asr #12]!
 *   @0x2fc714 stmdahs r0, {r1, r7, r9, r10, lr}
 *   @0x2fc718 sbchi pc, r8, #64
 *   @0x2fc71c orrlt r6, pc, r7, ror #18
 *   @0x2fc720 addhi pc, r4, #14614528
 *   @0x2fc724 ldrbtmi r4, [r8], #1542
 *   @0x2fc728 ldmvc r4!, {r3, r8, r10, r12, sp, lr, pc}
 *   @0x2fc72c bl 0x50e014 <SrcVerts+0x6b058>
 *   @0x2fc730 .word 0xf5b90106
 *   @0x2fc734 stmdahs r0, {r3, r5, r6, r8, r9, r10, r11, sp, lr, pc}
 *   @0x2fc738 sbchi pc, r1, #64
 *   @0x2fc73c .word 0xf5b63614
 *   @0x2fc740 ldrhle r7, [r3, #244]!
 *   @0x2fc744 stmdaeq r0, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x2fc748 subhs r2, r12, #0, #2
 *   @0x2fc74c strbmi r2, [r0], -r0, lsl #12
 *   @0x2fc750 svc #0x2ef5b9
 *   @0x2fc754 .word 0x960b4b95
 *   @0x2fc758 .word 0x9609447b
 *   @0x2fc75c teqvc r4, #12582912
 *   @0x2fc760 movwls r9, #0xd60a
 *   @0x2fc764 ldrhlo pc, [r8], r4
 *   @0x2fc768 vqsub.s8 d20, d16, d19
 *   @0x2fc76c .word 0xf8d48082
 *   @0x2fc770 .word 0x0131309c
 *   @0x2fc774 smlabbls r5, r6, r10, r4
 *   @0x2fc778 addsmi r5, r3, #5963776
 *   @0x2fc77c bmi 0xfe4707c0 <b2_toiTime+0xfffffffffdd1731c>
 *   @0x2fc780 mulle r7, r3, r2
 *   @0x2fc784 addsmi r4, r3, #132, #20
 *   @0x2fc788 movwhs sp, #0x1170
 *   @0x2fc78c stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2fc790 and r9, r7, r10, lsl #6
 *   @0x2fc794 .word 0xf04f2101
 *   @0x2fc798 mrsls r0, apsr
 *   @0x2fc79c andhs lr, r1, #2
 *   @0x2fc7a0 ldrmi r9, [r1], r9, lsl #4
 *   @0x2fc7a4 strhs r9, [r0, -sp, lsl #22]
 *   @0x2fc7a8 bl 0x3ce29c <error_g0017+0x26f40>
 *   @0x2fc7ac .word 0xf10909c9
 *   @0x2fc7b0 .word 0xf8d40904
 *   @0x2fc7b4 bls 0x448a2c <g_RomDisk+0x5120c>
 *   @0x2fc7b8 ldmvs r1, {r1, r3, r4, r10, lr} ^
 *   @0x2fc7bc .word 0x2000f8d9
 *   @0x2fc7c0 swpble r4, r1, [lr]
 *   @0x2fc7c4 svceq #0xf1bb
 *   @0x2fc7c8 .word 0xf8d4d13d
 *   @0x2fc7cc .word 0xf1bcc204
 *   @0x2fc7d0 eorsle r0, r8, r0, lsl #30
 *   @0x2fc7d4 strtmi r9, [r0], -r5, lsl #20
 *   @0x2fc7d8 uadd8mi r5, r11, r9
 *   @0x2fc7dc strbmi r6, [r0, r2, lsr #29]!
 *   @0x2fc7e0 teqle r0, r0, lsl #16
 *   @0x2fc7e4 stmdbls r5, {r0, r1, r5, r7, r9, r10, r11, sp, lr}
 *   @0x2fc7e8 .word 0xf8d49306
 *   @0x2fc7ec stmdals r6, {r2, r3, r4, r7, r12, sp}
 *   @0x2fc7f0 ldmvs r11, {r0, r1, r3, r10, lr} ^
 *   @0x2fc7f4 movwls r4, #0x3619
 *   @0x2fc7f8 blx 0x7fa7ae <b2_toiTime+0xa130a>
 *   @0x2fc7fc bllt 0x723410 <g_SWFvertbuff+0x50348>
 *   @0x2fc800 bhs 0x3ce070 <error_g0017+0x26d14>
 *   @0x2fc804 stmdals r6, {r0, r3, r8, r11, r12, lr, pc}
 *   @0x2fc808 movwls r9, #0x3204
 *   @0x2fc80c .word 0xf925f7ea
 *   @0x2fc810 blls 0x3e3028 <error_g0017+0x3bccc>
 *   @0x2fc814 strmi r3, [r3], #2564
 *   @0x2fc818 .word 0xf003e7f3
 *   @0x2fc81c .word 0xf1c30303
 *   @0x2fc820 movwhs r0, #0x3203
 *   @0x2fc824 stmdals r6, {r0, r1, r4, r7, r9, lr}
 *   @0x2fc828 andls sp, r4, #11
 *   @0x2fc82c .word 0xf7ea9303
 *   @0x2fc830 blls 0x3fab90 <g_RomDisk+0x3370>
 *   @0x2fc834 sbcseq r9, r9, r4, lsl #20
 *   @0x2fc838 sbclt r3, r0, #1024
 *   @0x2fc83c strmi r4, [r3], #136
 *   @0x2fc840 .word 0xf7ebe7f0
 *   @0x2fc844 .word 0xf859fb39
 *   @0x2fc848 ldrbmi r3, [r11, #-0xc04]
 *   @0x2fc84c .word 0xf858d104
 *   @0x2fc850 movwlo r3, #0x1007
 *   @0x2fc854 andlo pc, r7, r8, asr #16
 *   @0x2fc858 andlo pc, r7, r8, asr r8
 *   @0x2fc85c .word 0xf0002b03
 *   @0x2fc860 strlo r8, [r4, -lr, lsr #4]
 *   @0x2fc864 ldmdbeq r8, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2fc868 .word 0xd1a22f4c
 *   @0x2fc86c adcslt r3, r6, #1048576
 *   @0x2fc870 bmi 0x16f6658 <b2_toiTime+0xf9d1b4>
 *   @0x2fc874 .word 0xf108ab0f
 *   @0x2fc878 ldrbtmi r0, [r10], #-2120
 *   @0x2fc87c eorsvc pc, r9, #8388608
 *   @0x2fc880 stmdblt r9!, {r1, r3, r8, r11, r12, pc}
 *   @0x2fc884 .word 0x1c10f852
 *   @0x2fc888 ldmdavs r9, {r0, r4, r8, r11, r12, sp, pc} ^
 *   @0x2fc88c subsvs r3, r9, r1, lsl #2
 *   @0x2fc890 stmdblt r9!, {r0, r3, r8, r11, r12, pc}
 *   @0x2fc894 .word 0x1c08f852
 *   @0x2fc898 ldmdavs r9, {r0, r4, r8, r11, r12, sp, pc} ^
 *   @0x2fc89c subsvs r3, r9, r1, lsl #2
 *   @0x2fc8a0 stmdblt r1!, {r0, r1, r3, r8, r11, r12, pc}
 *   @0x2fc8a4 ldmdblt r1, {r0, r4, r11, sp, lr}
 *   @0x2fc8a8 qaddlo r6, r9, r1
 *   @0x2fc8ac .word 0xf8536059
 *   @0x2fc8b0 stmdbhs r3, {r2, r8, r9, r10, r11, r12}
 *   @0x2fc8b4 andhi pc, r3, #0
 *   @0x2fc8b8 .word 0xf1024543
 *   @0x2fc8bc bicsle r0, pc, r8, lsl r2
 *   @0x2fc8c0 .word 0xf10d69ea
 *   @0x2fc8c4 .word 0xf8d40840
 *   @0x2fc8c8 strtmi r6, [r0], -r4, lsl #4
 *   @0x2fc8cc .word 0x46434933
 *   @0x2fc8d0 strtmi r9, [r10], -r5, lsl #4
 *   @0x2fc8d4 strhls r4, [pc], -r0
 *   @0x2fc8d8 cmnle r7, r0, lsl #16
 *   @0x2fc8dc stmdbhs r7, {r4, r8, r11, r12, pc}
 *   @0x2fc8e0 .word 0xf504d976
 *   @0x2fc8e4 qasxmi r7, r8, r7
 *   @0x2fc8e8 .word 0xf7eb464a
 *   @0x2fc8ec .word 0x900ffada
 *   @0x2fc8f0 .word 0xd1662800
 *   @0x2fc8f4 sbcsvs pc, r12, #212, #16
 *   @0x2fc8f8 .word 0xf8969b10
 *   @0x2fc8fc movwls r12, #0x6002
 *   @0x2fc900 ldmdbvc r7!, {r0, r1, r4, r5, r6, r7, r11, r12, sp, lr} ^
 *   @0x2fc904 blhs 0x637218 <g_SWFaavertbuff+0x64150>
 *   @0x2fc908 ldrteq r7, [pc], #-2355
 *   @0x2fc90c strvs lr, [r3, -r7, asr #20]
 *   @0x2fc910 tstmi pc, #3981312
 *   @0x2fc914 b 0x14dafe8 <b2_toiTime+0xd81b44>
 *   @0x2fc918 .word 0xf1172703
 *   @0x2fc91c svclt #0x881f01
 *   @0x2fc920 .word 0xf1bbb2bf
 *   @0x2fc924 stmdale r7, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x2fc928 svceq #0xf1bb
 *   @0x2fc92c svcne #0x3ad007
 *   @0x2fc930 .word 0x73fdf64f
 *   @0x2fc934 stmdble r2, {r1, r3, r4, r7, r9, lr}
 *   @0x2fc938 movwls r2, #0xf303
 *   @0x2fc93c andhs lr, r0, #58
 *   @0x2fc940 andls r10, r0, #15360
 *   @0x2fc944 movwls r2, #0x1101
 *   @0x2fc948 stmdals r5, {r0, r1, r3, r4, r6, r9, r10, lr}
 *   @0x2fc94c blx 0xfeafa902 <b2_toiTime+0xfffffffffe3a145e>
 *   @0x2fc950 .word 0xf8c49b0f
 *   @0x2fc954 bllt 0x1dbd50c <b2_toiTime+0x1664068>
 *   @0x2fc958 .word 0xf1069906
 *   @0x2fc95c rsbsmi r0, r8, #8, #4
 *   @0x2fc960 ldrbmi r4, [r11, #-0x40e]
 *   @0x2fc964 ldrtmi sp, [r10], #-514
 *   @0x2fc968 stmdble r7, {r1, r4, r5, r7, r9, lr}
 *   @0x2fc96c rsclo pc, r4, #196, #16
 *   @0x2fc970 .word 0xf8c49b10
 *   @0x2fc974 .word 0xf8c472e8
 *   @0x2fc978 eor r3, r2, r0, ror #5
 *   @0x2fc97c andls pc, r0, r2, lsl r8
 *   @0x2fc980 rscne pc, r12, #212, #16
 *   @0x2fc984 andls pc, r3, r1, lsl #16
 *   @0x2fc988 strb r3, [r10, r1, lsl #6]!
 *   @0x2fc98c ldrbtvc r7, [r2], #-1381
 *   @0x2fc990 ldrbtvs r6, [r0], -sp, ror #14
 *   @0x2fc994 rsbsvc r6, r2, r0, ror r5
 *   @0x2fc998 cmnvs r6, #32, #8
 *   @0x2fc99c stmdavs r4!, {r3, r4, r5, r6, r8, r10, r11, sp, lr} ^
 *   @0x2fc9a0 strheq r1, [pc], -lr
 *   @0x2fc9a4 andeq r2, r9, r7, lsl #10
 *   @0x2fc9a8 ldrdeq r3, r4, [r10], -lr
 *   @0x2fc9ac andeq r3, r10, r12, lsr #15
 *   @0x2fc9b0 andeq r3, r10, r10, lsl #13
 *   @0x2fc9b4 strbmi r4, [r9], -r8, lsr #12
 *   @0x2fc9b8 blx 0xcfa96c <b2_toiTime+0x5a14c8>
 *   @0x2fc9bc .word 0xf8c42300
 *   @0x2fc9c0 svcls #0xf32e0
 *   @0x2fc9c4 .word 0xf0402f00
 *   @0x2fc9c8 and r8, r2, r2, ror r1
 *   @0x2fc9cc and r2, r0, r0, lsl #14
 *   @0x2fc9d0 stmvs r3!, {r0, r1, r2, r9, r10, lr}
 *   @0x2fc9d4 .word 0xf14007da
 *   @0x2fc9d8 .word 0xf8d480fe
 *   @0x2fc9dc blvs 0x19c8be4 <b2_toiTime+0x126f740>
 *   @0x2fc9e0 qasxmi r11, r0, r11
 *   @0x2fc9e4 .word 0xf7fe4629
 *   @0x2fc9e8 stmdahs r0, {r0, r2, r5, r6, r8, r11, r12, sp, lr, pc}
 *   @0x2fc9ec addhi pc, r1, r0, asr #32
 *   @0x2fc9f0 .word 0xf504e083
 *   @0x2fc9f4 .word 0xf8d4732b
 *   @0x2fc9f8 strtmi r6, [r0], -r4, lsl #4
 *   @0x2fc9fc qadd8mi r4, r10, pc
 *   @0x2fca00 sbclt r4, r3, #176, #14
 *   @0x2fca04 smlabble r2, lr, r11, r2
 *   @0x2fca08 adcvc pc, r12, #196, #16
 *   @0x2fca0c stmdahs r0, {r0, r2, sp, lr, pc}
 *   @0x2fca10 .word 0xf8d4d164
 *   @0x2fca14 blvs 0x19c8c1c <b2_toiTime+0x126f778>
 *   @0x2fca18 .word 0xf8c4b113
 *   @0x2fca1c strh r7, [r4], -r0
 *   @0x2fca20 .word 0xf7e94628
 *   @0x2fca24 .word 0xf8c4ff8d
 *   @0x2fca28 .word 0xf8d402b0
 *   @0x2fca2c strtmi r6, [r0], -r4, lsl #4
 *   @0x2fca30 qadd8mi r4, r10, r3
 *   @0x2fca34 ldrmi r4, [r0, r3, asr #12]!
 *   @0x2fca38 mrsle r2, spsr
 *   @0x2fca3c ldrhlo pc, [r2], #148
 *   @0x2fca40 .word 0xb14b9a10
 *   @0x2fca44 addsmi r4, r10, #146432
 *   @0x2fca48 tstls r0, #136, #30
 *   @0x2fca4c ldmeq r11, {r4, r8, r9, r11, r12, pc}
 *   @0x2fca50 sbcslo pc, r4, #196, #16
 *   @0x2fca54 and r2, r8, r2, lsl #6
 *   @0x2fca58 addsmi r4, r10, #142336
 *   @0x2fca5c tstls r0, #136, #30
 *   @0x2fca60 ldmdaeq r11, {r4, r8, r9, r11, r12, pc} ^
 *   @0x2fca64 sbcslo pc, r4, #196, #16
 *   @0x2fca68 stmdbvs r2!, {r0, r8, r9, sp}
 *   @0x2fca6c sbcsne pc, r4, #212, #16
 *   @0x2fca70 adcsmi r1, r9, #22272
 *   @0x2fca74 addsmi sp, r1, #42
 *   @0x2fca78 rfeia r4!
 *   @0x2fca7c qadd8mi r9, r8, r8
 *   @0x2fca80 ldrsbvs pc, [r12], r4
 *   @0x2fca84 .word 0xf7e9409f
 *   @0x2fca88 qaddhs pc, r11, r0
 *   @0x2fca8c stmdbne r9, {r1, r2, r8, r9, r11, sp, lr, pc}
 *   @0x2fca90 movwmi pc, #0x6f
 *   @0x2fca94 andle r4, r9, #327155712
 *   @0x2fca98 bne 0x796d68 <b2_toiTime+0x3d8c4>
 *   @0x2fca9c vstrle s4, [r3, #-0]
 *   @0x2fcaa0 svclt #0xbc429a
 *   @0x2fcaa4 .word 0x21014613
 *   @0x2fcaa8 .word 0xe7f33610
 *   @0x2fcaac stmdavs r11!, {r0, r3, r8, r11, r12, sp, pc} ^
 *   @0x2fcab0 addsmi r1, pc, #110592
 *   @0x2fcab4 stmdbvs r3!, {r0, r2, r11, r12, lr, pc}
 *   @0x2fcab8 movwlo r9, #0x1710
 *   @0x2fcabc sbcslo pc, r4, #196, #16
 *   @0x2fcac0 .word 0xf8d4e004
 *   @0x2fcac4 ldrdlt r3, r4, [r3, -r4]
 *   @0x2fcac8 .word 0x61233b01
 *   @0x2fcacc ldmdbls r0, {r3, r5, r9, r10, lr}
 *   @0x2fcad0 eorsvc pc, r6, #4, #10
 *   @0x2fcad4 .word 0xf9e5f7eb
 *   @0x2fcad8 addshs lr, r0, r0
 *   @0x2fcadc adclo pc, r12, #212, #16
 *   @0x2fcae0 sbclt r11, r3, #-1073741818
 *   @0x2fcae4 .word 0xf0002b8e
 *   @0x2fcae8 stmdahs r0, {r1, r2, r6, r7, pc}
 *   @0x2fcaec sbchi pc, r3, r0, asr #32
 *   @0x2fcaf0 sbclt lr, r3, #31195136
 *   @0x2fcaf4 .word 0xf0402b8e
 *   @0x2fcaf8 .word 0xf8d480be
 *   @0x2fcafc strtmi r6, [r0], -r4, lsl #4
 *   @0x2fcb00 strtmi r4, [r10], -r2, ror #18
 *   @0x2fcb04 ldrmi r4, [r0, r3, asr #12]!
 *   @0x2fcb08 movwhs r11, #0x128
 *   @0x2fcb0c addlo pc, r8, #196, #16
 *   @0x2fcb10 addlo pc, r4, #196, #16
 *   @0x2fcb14 ldmdbls r0, {r2, r3, sp, lr, pc}
 *   @0x2fcb18 .word 0xf5044628
 *   @0x2fcb1c .word 0xf8c47222
 *   @0x2fcb20 .word 0xf7eb1284
 *   @0x2fcb24 ldrhlt pc, [r8, -lr]
 *   @0x2fcb28 blhs 0xfe6a963c <b2_toiTime+0xfffffffffdf50198>
 *   @0x2fcb2c adchi pc, r3, r0, asr #32
 *   @0x2fcb30 andvs pc, r4, #212, #16
 *   @0x2fcb34 ldmdbmi r6, {r5, r9, r10, lr} ^
 *   @0x2fcb38 strbmi r4, [r3], -r10, lsr #12
 *   @0x2fcb3c strhlt r4, [r8, -r0]!
 *   @0x2fcb40 .word 0xf8c42300
 *   @0x2fcb44 .word 0xf8c43290
 *   @0x2fcb48 and r3, sp, r12, lsl #5
 *   @0x2fcb4c qadd16mi r9, r8, r0
 *   @0x2fcb50 eorvc pc, r4, #4, #10
 *   @0x2fcb54 addne pc, r12, #196, #16
 *   @0x2fcb58 .word 0xf9a3f7eb
 *   @0x2fcb5c tstlt r8, r2, lsl #13
 *   @0x2fcb60 blhs 0xfe6a9674 <b2_toiTime+0xfffffffffdf501d0>
 *   @0x2fcb64 adchi pc, r2, r0, asr #32
 *   @0x2fcb68 .word 0x3080f8d4
 *   @0x2fcb6c vstrhs d6, [r0, #-372]
 *   @0x2fcb70 stmibvs r3!, {r0, r4, r5, r8, r12, lr, pc} ^
 *   @0x2fcb74 .word 0xf8d4b37b
 *   @0x2fcb78 .word 0xb36332d8
 *   @0x2fcb7c strtmi r4, [lr], -pc, lsr #12
 *   @0x2fcb80 sbcslo pc, r4, #212, #16
 *   @0x2fcb84 andle r4, r12, #-536870903
 *   @0x2fcb88 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2fcb8c .word 0xf7fd4642
 *   @0x2fcb90 blls 0x73abd8 <g_SWFvertbuff+0x67b10>
 *   @0x2fcb94 stchs p1, c11, [r1, #-108]
 *   @0x2fcb98 shadd16mi sp, r7, sp
 *   @0x2fcb9c strlo r2, [r1], -r1, lsl #10
 *   @0x2fcba0 stchs p7, c14, [r1, #-952]
 *   @0x2fcba4 orrslt sp, r7, r7, lsl r1
 *   @0x2fcba8 strtmi r10, [r0], -r3, lsr #26
 *   @0x2fcbac movwhs r4, #0x8639
 *   @0x2fcbb0 .word 0xf7e8462a
 *   @0x2fcbb4 ldmdblt r0!, {r0, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2fcbb8 umulllo pc, r12, sp, r8
 *   @0x2fcbbc .word 0xd10a2b2e
 *   @0x2fcbc0 qasxmi r4, r8, r4
 *   @0x2fcbc4 ldrbtmi r2, [r9], #-520
 *   @0x2fcbc8 stc p5, c15, [r10, #-740]
 *   @0x2fcbcc stmvs r3!, {r3, r4, r8, r11, r12, sp, pc}
 *   @0x2fcbd0 movweq pc, #0x1023
 *   @0x2fcbd4 stmvs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x2fcbd8 ldrle r0, [r1, #-0x5db]!
 *   @0x2fcbdc ldrne r9, [r6], #-2567
 *   @0x2fcbe0 strtmi sp, [r0], -lr, lsr #32
 *   @0x2fcbe4 .word 0xf7fe2100
 *   @0x2fcbe8 strmi pc, [r2], r7, asr #30
 *   @0x2fcbec cmple sp, r0, lsl #16
 *   @0x2fcbf0 adcslo pc, r8, #212, #16
 *   @0x2fcbf4 ldmdbvs sp, {r0, r1, r3, r4, r6, r7, r11, sp, lr}
 *   @0x2fcbf8 movwhs r11, #0xc315
 *   @0x2fcbfc cmpmi lr, #8, #18
 *   @0x2fcc00 svcvs #0x4b4620
 *   @0x2fcc04 cdplo p14, #0x0, c6, c12, c7, #0x3
 *   @0x2fcc08 ldmhi r1, {r1, r3, r5, r7, r8, r11, r12}
 *   @0x2fcc0c ldrmi r4, [r8, r2, asr #12]
 *   @0x2fcc10 stmdahs r0, {r1, r7, r9, r10, lr}
 *   @0x2fcc14 stmibvs r1!, {r1, r3, r6, r8, r12, lr, pc}
 *   @0x2fcc18 shadd16mi r11, r8, r1
 *   @0x2fcc1c blx 0xfe5fabce <b2_toiTime+0xfffffffffdea172a>
 *   @0x2fcc20 qadd16mi r9, r0, r0
 *   @0x2fcc24 .word 0xf8d461a3
 *   @0x2fcc28 stmibpl r10!, {r3, r4, r5, r7, r9, r12, sp}
 *   @0x2fcc2c ldmdavs r9, {r0, r1, r3, r4, r6, r7, r11, sp, lr}
 *   @0x2fcc30 stc2l p7, c15, [r3], {255}
 *   @0x2fcc34 stmdahs r0, {r1, r7, r9, r10, lr}
 *   @0x2fcc38 qasxmi sp, r0, r8
 *   @0x2fcc3c ldc2 p7, c15, [lr, #1016]!
 *   @0x2fcc40 ldrbtmi r4, [r11], #-2837
 *   @0x2fcc44 andlo pc, r8, #196, #16
 *   @0x2fcc48 ldrbtmi r4, [r11], #-2836
 *   @0x2fcc4c andslo pc, r0, #196, #16
 *   @0x2fcc50 ldrbtmi r4, [r11], #-2835
 *   @0x2fcc54 andslo pc, r4, #196, #16
 *   @0x2fcc58 ldrbtmi r4, [r11], #-2834
 *   @0x2fcc5c andslo pc, r8, #196, #16
 *   @0x2fcc60 ldrbtmi r4, [r11], #-2833
 *   @0x2fcc64 andlo pc, r12, #196, #16
 *   @0x2fcc68 strhs lr, [r11, -r0, lsr #32]
 *   @0x2fcc6c smladhs r2, pc, r0, lr
 *   @0x2fcc70 smladhs r0, sp, r0, lr
 *   @0x2fcc74 .word 0x4607e01b
 *   @0x2fcc78 svclt #0xe019
 *   @0x2fcc7c strbvs r7, [r12, -r6, ror #18]!
 *   @0x2fcc80 stclvs p3, c6, [pc], #-388
 *   @0x2fcc84 .word 0x0003ffff
 *   @0x2fcc88 .word 0x0001ffff
 *   @0x2fcc8c ldrbtvs r6, [r0], -sp, ror #14
 *   @0x2fcc90 rsbsvc r6, r2, r0, ror r5
 *   @0x2fcc94 andeq r2, r9, r11, lsr r0
 *   @0x2fcc98 .word 0xffffd96d
 *   @0x2fcc9c .word 0xffffc295
 *   @0x2fcca0 .word 0xffffda4b
 *   @0x2fcca4 .word 0xffffe42f
 *   @0x2fcca8 .word 0xffffd977
 *   @0x2fccac stmdbls r12, {r0, r1, r2, r4, r6, r9, r10, lr}
 *   @0x2fccb0 bls 0xc4e598 <b2_toiTime+0x4f50f4>
 *   @0x2fccb4 addsmi r6, r10, #720896
 *   @0x2fccb8 .word 0xf5b9d006
 *   @0x2fccbc stmvs r3!, {r2, r3, r7, r10, r11, sp, lr, pc}
 *   @0x2fccc0 movwpl pc, #0x443
 *   @0x2fccc4 ldrb r6, [r11, #0xa3]!
 *   @0x2fccc8 pop {r0, r1, r2, r5, r12, sp, pc}
 *   @0x2fcccc svclt #0x8ff0
 *   @0x2fccd0 .word 0x4606b5f8
 *   @0x2fccd4 adcspl pc, r8, #208, #16
 *   @0x2fccd8 ldrmi r4, [r7], -r12, lsl #12
 *   @0x2fccdc eorsle r2, r10, r0, lsl #26
 *   @0x2fcce0 .word 0xf895b17b
 *   @0x2fcce4 ldmdblt r11, {r2, r3, r5, r12, sp}
 *   @0x2fcce8 .word 0xf7fe2101
 *   @0x2fccec msrvs APSR_nzcvq, #13565952
 *   @0x2fccf0 adcslo pc, r8, #14024704
 *   @0x2fccf4 mlahs sp, r3, r8, pc
 *   @0x2fccf8 blvs 0x92b128 <b2_toiTime+0x1d1c84>
 *   @0x2fccfc blvs 0x196c4e4 <b2_toiTime+0x1213040>
 *   @0x2fcd00 .word 0xf895e00d
 *   @0x2fcd04 ldmdblt r1, {r5, r12}
 *   @0x2fcd08 .word 0xf8c0f7fe
 *   @0x2fcd0c .word 0xf8d66268
 *   @0x2fcd10 .word 0xf89332b8
 *   @0x2fcd14 stmdblt r10, {r0, r5, sp}
 *   @0x2fcd18 .word 0xbdf86a58
 *   @0x2fcd1c stmibvs r11, {r0, r3, r4, r7, r9, r11, sp, lr} ^
 *   @0x2fcd20 stmdbvs r10, {r0, r1, r4, r6, r8, r12, sp, pc} ^
 *   @0x2fcd24 svclt #0x284294
 *   @0x2fcd28 ldrbtlo pc, [pc], #258
 *   @0x2fcd2c .word 0xf852698a
 *   @0x2fcd30 .word 0xf8532024
 *   @0x2fcd34 and r4, r4, r4, lsr #32
 *   @0x2fcd38 ldmdavs r2, {r1, r3, r6, r11, sp, lr}
 *   @0x2fcd3c andle r4, r12, #148, #4
 *   @0x2fcd40 qadd16mi r4, r3, r10
 *   @0x2fcd44 eorvc pc, lr, r6, lsl #10
 *   @0x2fcd48 stc2l p7, c15, [sp], {254}
 *   @0x2fcd4c ldrmi r6, [r8], #-2107
 *   @0x2fcd50 andhs r6, r0, r8, lsr r0
 *   @0x2fcd54 qsub8mi r11, r8, r8
 *   @0x2fcd58 strdhs r11, r12, [r6], -r8
 *   @0x2fcd5c .word 0xf890bdf8
 *   @0x2fcd60 ldrhlt r3, [r3, -r5]
 *   @0x2fcd64 .word 0xf7ff2300
 *   @0x2fcd68 .word 0x4618bfb3
 *   @0x2fcd6c andeq r4, r0, r0, ror r7
 *   @0x2fcd70 .word 0x4604b538
 *   @0x2fcd74 strmi r4, [sp], -sp, lsl #16
 *   @0x2fcd78 .word 0xf7e84478
 *   @0x2fcd7c stmiblt r0!, {r1, r3, r5, r6, r7, r9, r11, r12, sp, lr, pc}
 *   @0x2fcd80 stmdavs r0!, {r2, r4, r7, r8, r12, sp, pc} ^
 *   @0x2fcd84 andhs r11, r0, r8, lsl #18
 *   @0x2fcd88 stmdbmi r9, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2fcd8c .word 0xf7e94479
 *   @0x2fcd90 stmdahs r0, {r0, r1, r2, r3, r5, r7, r11, r12, sp, lr, pc}
 *   @0x2fcd94 stmdavs r3, {r0, r1, r2, r4, r5, r6, r7, r12, lr, pc}
 *   @0x2fcd98 blhs 0x31730c <ft_lzwstate_io+0x358>
 *   @0x2fcd9c ldmdbvs r11, {r0, r1, r4, r5, r6, r7, r12, lr, pc}
 *   @0x2fcda0 strtmi r4, [r9], -r0, lsr #12
 *   @0x2fcda4 ldclt p7, c4, [r8, #-608]!
 *   @0x2fcda8 ldclt p6, c4, [r8, #-128]!
 *   @0x2fcdac muleq lr, r12, r3
 *   @0x2fcdb0 andeq r1, r9, r3, lsr #28
 *   @0x2fcdb4 .word 0x4605b570
 *   @0x2fcdb8 stmdbmi sp, {r3, r9, r10, lr}
 *   @0x2fcdbc sadd16mi r4, lr, r4
 *   @0x2fcdc0 .word 0xf5b94479
 *   @0x2fcdc4 .word 0x4601ebd8
 *   @0x2fcdc8 .word 0xb126b978
 *   @0x2fcdcc andhs r4, r10, #32, #12
 *   @0x2fcdd0 mcrr p5, #0xb, pc, lr, c9
 *   @0x2fcdd4 stmdavs r0!, {sp, lr, pc}
 *   @0x2fcdd8 andle r2, r1, r3, lsr #16
 *   @0x2fcddc .word 0xd1022828
 *   @0x2fcde0 andhs r6, r0, r8, lsr #8
 *   @0x2fcde4 andhs r11, r7, r0, ror sp
 *   @0x2fcde8 andhs r11, r12, r0, ror sp
 *   @0x2fcdec svclt #0xbd70
 *
 * ══ §8/8 anon_300004  0x300004..0x300204  size 512  128 条｜ISA ARM｜入口证据 data-ptr｜父块 anon_300004
 * @func 0x300004 0x300204  size 512  128 条
 * 入度 5｜调用者: 0x2ff730(anonT_2fec70+0xac0), 0x2ff8c4(anonT_2fec70+0xc54), 0x2ffac2(anonT_2fec70+0xe52), 0x2ffb02(anonT_2fec70+0xe92), 0x2ffde4(anonT_2fec70+0x1174)
 * 出调用 5 处 → 0xa7f528×1, anon_30a7b2+0x715a×1, 0x17a2bd8×1, 0x3e4400×1, 0x19ea660×1
 * 未主张: 函数边界（段长 ≠ 函数长）、参数/返回值、内部分支语义 —— 全部 open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x300004 strbmi r9, [r11, #-0xb07]
 *   @0x300008 rscshi pc, r0, r0, asr #4
 *   @0x30000c rfeib r5!
 *   @0x300010 stcne p0, c1, [r11, #-88]
 *   @0x300014 rfeib r5!
 *   @0x300018 subeq r3, r8, r10, lsr r0
 *   @0x30001c ldrmi r3, [r8], #-4
 *   @0x300020 addsmi r6, r8, #7012352
 *   @0x300024 strtmi sp, [r8], -r10, lsl #18
 *   @0x300028 .word 0xf7e83104
 *   @0x30002c strmi pc, [r6], -r12, ror #16
 *   @0x300030 svclt #0xe005
 *   @0x300034 .word 0x636f6d70
 *   @0x300038 andeq r0, r10, lr, lsr r7
 *   @0x30003c sadd16ls r4, sp, r6
 *   @0x300040 .word 0xf0402e00
 *   @0x300044 rfeib r5!
 *   @0x300048 stmibvs r11!, {r1, r2, r4, sp}
 *   @0x30004c biceq lr, r2, #3072
 *   @0x300050 subeq pc, r4, #4, #2
 *   @0x300054 muleq r3, r2, r8
 *   @0x300058 andeq lr, r3, r3, lsl #17
 *   @0x30005c ldrhlo pc, [r6], -r5
 *   @0x300060 movwlo r6, #0x19aa
 *   @0x300064 biceq lr, r3, #2048
 *   @0x300068 subeq pc, r12, #4, #2
 *   @0x30006c muleq r3, r2, r8
 *   @0x300070 andeq lr, r3, r3, lsl #17
 *   @0x300074 ldrhlo pc, [r6], -r5
 *   @0x300078 movwlo r6, #0x29aa
 *   @0x30007c biceq lr, r3, #2048
 *   @0x300080 adcseq pc, r4, #4, #2
 *   @0x300084 muleq r3, r2, r8
 *   @0x300088 andeq lr, r3, r3, lsl #17
 *   @0x30008c ldrhlo pc, [r6], -r5
 *   @0x300090 movwlo r6, #0x39aa
 *   @0x300094 biceq lr, r3, #2048
 *   @0x300098 adcseq pc, r12, #4, #2
 *   @0x30009c muleq r3, r2, r8
 *   @0x3000a0 andeq lr, r3, r3, lsl #17
 *   @0x3000a4 ldrhhs pc, [r6], -r5
 *   @0x3000a8 ldrpl r6, [lr], #2539
 *   @0x3000ac ldrhhs pc, [r6], -r5
 *   @0x3000b0 ldrmi r6, [r3], #-2539
 *   @0x3000b4 rfeib r5!
 *   @0x3000b8 stmibvs r11!, {r1, r2, r4, sp} ^
 *   @0x3000bc addsvc r4, lr, r3, lsl r4
 *   @0x3000c0 rfeib r5!
 *   @0x3000c4 ldrmi r3, [r3], #-22
 *   @0x3000c8 stmibvs r5!, {r1, r2, r3, r4, r6, r7, r12, sp, lr}
 *   @0x3000cc .word 0x10a4f8d4
 *   @0x3000d0 .word 0xf7e64628
 *   @0x3000d4 andsls pc, sp, r8, ror #23
 *   @0x3000d8 ldmdals sp, {r3, r8, r12, sp, pc}
 *   @0x3000dc qsub16mi lr, r8, r12
 *   @0x3000e0 .word 0xf7e6a91d
 *   @0x3000e4 blls 0xa7f528 <b2_toiTime+0x326084>
 *   @0x3000e8 blhs 0x31190c <af_shaper_get_elem+0x717a>
 *   @0x3000ec stmdavs r3!, {r0, r2, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x3000f0 ldrhlo pc, [lr, -r3]
 *   @0x3000f4 subsle r4, r5, #805306376
 *   @0x3000f8 addsmi r6, r8, #3719168
 *   @0x3000fc .word 0xf8d4dc55
 *   @0x300100 ldmdbge r4!, {r2, r3, r4, r7, r12, sp}
 *   @0x300104 .word 0x2188f8d3
 *   @0x300108 stclhs p8, c15, [r8, #-260]
 *   @0x30010c andls r2, r0, r1, lsl #4
 *   @0x300110 .word 0xf5036898
 *   @0x300114 .word 0xf7fa73c6
 *   @0x300118 .word 0xf8d4f916
 *   @0x30011c rfeia sp!
 *   @0x300120 andsls r2, sp, r8, lsl #1
 *   @0x300124 orrhs pc, r8, r3, asr #17
 *   @0x300128 cmple r5, r0, lsl #16
 *   @0x30012c ldrsblo pc, [r12], r4
 *   @0x300130 ldrtmi r4, [r10], -r8, lsr #12
 *   @0x300134 .word 0x118cf8d3
 *   @0x300138 stc2 p7, c15, [r9], #-920
 *   @0x30013c stmdahs r0, {r0, r2, r3, r4, r12, pc}
 *   @0x300140 .word 0xf8d4d14a
 *   @0x300144 stmvs r3!, {r2, r3, r4, r7, sp}
 *   @0x300148 .word 0xf8d2990d
 *   @0x30014c andlt r2, sp, #140, #2
 *   @0x300150 .word 0xf8c3990b
 *   @0x300154 stmvs r3!, {r3, r7, sp}
 *   @0x300158 addvc pc, r12, r3, asr #17
 *   @0x30015c bhi 0xff99a4f0 <b2_toiTime+0xffffffffff24104c>
 *   @0x300160 andeq lr, r2, #205824
 *   @0x300164 addhs pc, r0, r4, lsr #17
 *   @0x300168 blne 0x17a2bd8 <b2_toiTime+0x1049734>
 *   @0x30016c addhs pc, r2, r4, lsr #17
 *   @0x300170 bvs 0xfe96c9a0 <b2_toiTime+0xfffffffffe2134fc>
 *   @0x300174 ldrmi r0, [r1], #-210
 *   @0x300178 addne pc, r4, r4, asr #17
 *   @0x30017c ldrmi r6, [r1], #-2457
 *   @0x300180 addne pc, r8, r4, asr #17
 *   @0x300184 strmi r6, [r10], #-2777
 *   @0x300188 addhs pc, r12, r4, asr #17
 *   @0x30018c strbmi r6, [r10], #-2522
 *   @0x300190 addshs pc, r0, r4, asr #17
 *   @0x300194 .word 0xf8a46a1b
 *   @0x300198 bl 0x3e4400 <error_g0017+0x3d0a4>
 *   @0x30019c .word 0xf8c40545
 *   @0x3001a0 mul r4, r4, r0
 *   @0x3001a4 bicle r2, r1, r0, lsl #16
 *   @0x3001a8 andshs lr, r6, r5, lsl r0
 *   @0x3001ac rfeia r4!
 *   @0x3001b0 addsmi r3, r8, #128
 *   @0x3001b4 .word 0xf8d4d207
 *   @0x3001b8 .word 0x5c1a3090
 *   @0x3001bc andseq pc, r8, #34
 *   @0x3001c0 andlo r5, r1, r10, lsl r4
 *   @0x3001c4 movwlo lr, #0x47f3
 *   @0x3001c8 .word 0xf8a44620
 *   @0x3001cc smlabbhs r1, r0, r0, r3
 *   @0x3001d0 stc2l p7, c15, [lr, #-1016]
 *   @0x3001d4 ldrtmi lr, [r0], -r0
 *   @0x3001d8 and r9, r7, r7, lsl r0
 *   @0x3001dc tstls r7, #20, #6
 *   @0x3001e0 tstlt sp, r4, lsl #26
 *   @0x3001e4 andlo pc, r12, #14352384
 *   @0x3001e8 ldrmi r4, [r8, r0, lsr #12]
 *   @0x3001ec teqlt sp, r10, lsl #26
 *   @0x3001f0 .word 0x3080f8db
 *   @0x3001f4 blvs 0x19ea660 <b2_toiTime+0x12911bc>
 *   @0x3001f8 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^
 *   @0x3001fc .word 0x47906852
 *   @0x300200 eorslt r9, r5, r7, lsl r8
 */
