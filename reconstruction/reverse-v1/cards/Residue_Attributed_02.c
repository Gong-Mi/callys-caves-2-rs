/* cally 逆向卡：残段归属修正批 2 —— 按 census 的函数归属重新归组
 * ⚠ 更正：原来的 Residue_01-03 说这些地址「不属于任何函数跨度」是**错的**。
 *   真实原因：生成器用 range(start,end,4) 取指令，而这些函数是 **Thumb-2**，指令落在 2 字节栅格上，
 *   半字地址被漏掉，于是被误标成跨度外残段。census 的 f 字段给出了它们真正的函数归属。
 * 本卡：每节 = 一个真实函数（名字取自 asm/functions.tsv），只收它落在 4 字节栅格之外的那部分指令。
 * 级别: 骨架（地址 + 归属 + 入度；这些函数的其余部分在 All_*/Reach_* 卡里，语义仍 open）
 * 节: 374 个函数｜锚点 7143 条
 *
 * ══ png_do_read_interlace  0x2ade1c  size 812  本节 120 条（Thumb-2 半字段）｜入度 13
 * @func 0x2ade22 0x2ae14a  size 808  120 条
 * 部分覆盖: 本节 120/322 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ade22 ldr.w r10, [pc, #0x31c]
 *   @0x2ade26 mov r4, r0
 *   @0x2ade32 ldr.w r10, [r10]
 *   @0x2ade36 ldr.w r6, [r0, #0x1b0]
 *   @0x2ade3a add r12, pc
 *   @0x2ade4e adds r6, #0x1
 *   @0x2ade56 ldm.w r12!, {r0, r1, r2, r3}
 *   @0x2ade5a stm r5!, {r0, r1, r2, r3}
 *   @0x2ade72 ldr.w r2, [r4, #0x1c4]
 *   @0x2ade76 add.w r3, r1, r8, lsl #2
 *   @0x2ade7a ldrb.w r8, [r4, #0x1cf]
 *   @0x2ade7e subs r1, r2, #0x1
 *   @0x2ade8e add.w r0, r5, #0xffffffff
 *   @0x2ade92 beq 0x2adf68 <png_do_read_interlace+0x14c>
 *   @0x2adeba movs r2, #0x0
 *   @0x2adeca mov.w r12, #0x7
 *   @0x2adece b 0x2adee4 <png_do_read_interlace+0xc8>
 *   @0x2aded2 mvns r3, r3
 *   @0x2adee6 ldr.w r2, [r4, #0x1c4]
 *   @0x2adeea cmp r7, r2
 *   @0x2adeee ldrb.w r9, [r1]
 *   @0x2adef2 asr.w r9, r9, r6
 *   @0x2adef6 and r9, r9, #0x1
 *   @0x2adefa str.w r9, [sp, #0x4]
 *   @0x2adefe mov.w r9, #0x0
 *   @0x2adf02 ldr r2, [sp, #0x8]
 *   @0x2adf06 bge 0x2adf40 <png_do_read_interlace+0x124>
 *   @0x2adf2e strb.w r10, [r0]
 *   @0x2adf32 cmp r3, r2
 *   @0x2adf36 addeq.w r0, r0, #0xffffffff
 *   @0x2adf3a addne r3, r8
 *   @0x2adf3e b 0x2adf02 <png_do_read_interlace+0xe6>
 *   @0x2adf46 cmp r6, r10
 *   @0x2adf4a addeq.w r1, r1, #0xffffffff
 *   @0x2adf4e addne r6, r8
 *   @0x2adf52 b 0x2adee6 <png_do_read_interlace+0xca>
 *   @0x2adf5e bls.w 0x2ae122 <png_do_read_interlace+0x306>
 *   @0x2adf62 lsrs r3, r3, #0x3
 *   @0x2adf66 b 0x2ae128 <png_do_read_interlace+0x30c>
 *   @0x2adf76 add.w r2, r2, #0x3
 *   @0x2adf7a add.w r3, r5, #0x3
 *   @0x2adf7e beq 0x2adf9a <png_do_read_interlace+0x17e>
 *   @0x2adf92 lsls r3, r3, #0x1
 *   @0x2adf9a mvns r2, r2
 *   @0x2adf9e and r6, r2, #0x3
 *   @0x2adfa2 and r3, r3, #0x3
 *   @0x2adfa6 mov.w r9, #0x6
 *   @0x2adfaa lsls r6, r6, #0x1
 *   @0x2adfae movs r7, #0x0
 *   @0x2adfb6 bhs 0x2adf54 <png_do_read_interlace+0x138>
 *   @0x2adfba ldrb r2, [r1]
 *   @0x2adfbe and r2, r2, #0x3
 *   @0x2adfc2 str r2, [sp, #0x4]
 *   @0x2adfc6 ldr r1, [sp, #0x8]
 *   @0x2adfca bge 0x2ae006 <png_do_read_interlace+0x1ea>
 *   @0x2adfde add.w r2, r2, #0x1
 *   @0x2adfe2 and.w r1, r11, r10
 *   @0x2adfe6 ldr.w r11, [sp, #0x4]
 *   @0x2adfea lsl.w r10, r11, r3
 *   @0x2adfee it eq
 *   @0x2adff2 orr.w r10, r1, r10
 *   @0x2adff6 it ne
 *   @0x2adffa strb.w r10, [r0]
 *   @0x2adffe it eq
 *   @0x2ae006 cmp r6, r9
 *   @0x2ae00a ldr r2, [sp]
 *   @0x2ae00e subs r2, #0x1
 *   @0x2ae012 b 0x2ae016 <png_do_read_interlace+0x1fa>
 *   @0x2ae016 adds r7, #0x1
 *   @0x2ae01a ands r7, r7, #0x10000
 *   @0x2ae01e add.w r1, r6, r1, lsr #1
 *   @0x2ae022 add.w r0, r6, r0, lsr #1
 *   @0x2ae026 str r1, [sp]
 *   @0x2ae032 and r2, r2, #0x1
 *   @0x2ae036 and r3, r3, #0x1
 *   @0x2ae03a mov.w r9, #0x0
 *   @0x2ae03e lsls r6, r2, #0x2
 *   @0x2ae042 mvn r2, #0x3
 *   @0x2ae046 b 0x2ae064 <png_do_read_interlace+0x248>
 *   @0x2ae04e ite ne
 *   @0x2ae052 moveq r6, #0x4
 *   @0x2ae05a itete ne
 *   @0x2ae05e moveq r8, r3
 *   @0x2ae062 moveq r3, r2
 *   @0x2ae06e bhs.w 0x2adf54 <png_do_read_interlace+0x138>
 *   @0x2ae072 ldr r1, [sp]
 *   @0x2ae076 asrs r7, r6
 *   @0x2ae07e movs r7, #0x0
 *   @0x2ae082 cmp r7, r1
 *   @0x2ae086 rsb.w r11, r3, #0x4
 *   @0x2ae08a movw r10, #0xf0f
 *   @0x2ae08e asr.w r11, r10, r11
 *   @0x2ae092 ldrb.w r10, [r0]
 *   @0x2ae096 cmp r3, r9
 *   @0x2ae0aa moveq r3, r8
 *   @0x2ae0b2 addne r3, r3, r2
 *   @0x2ae0ba addeq.w r0, r0, #0xffffffff
 *   @0x2ae0be b 0x2ae080 <png_do_read_interlace+0x264>
 *   @0x2ae0c2 bne 0x2ae0ce <png_do_read_interlace+0x2b2>
 *   @0x2ae0c6 mov r6, r8
 *   @0x2ae0ca str r1, [sp]
 *   @0x2ae0ce add r6, r2
 *   @0x2ae0d6 lsr.w r8, r8, #0x3
 *   @0x2ae0da add.w r10, sp, #0x2c
 *   @0x2ae0de movs r7, #0x0
 *   @0x2ae0ee bhs.w 0x2adf54 <png_do_read_interlace+0x138>
 *   @0x2ae0f2 mov r0, r10
 *   @0x2ae0f6 mov r2, r8
 *   @0x2ae102 cmp r11, r3
 *   @0x2ae106 mov r0, r6
 *   @0x2ae10a mov r2, r8
 *   @0x2ae11a rsb r9, r8, r9
 *   @0x2ae11e adds r7, #0x1
 *   @0x2ae122 muls r5, r3, r5
 *   @0x2ae126 lsrs r5, r5, #0x3
 *   @0x2ae12e ldr r2, [sp, #0x34]
 *   @0x2ae132 cmp r2, r3
 *   @0x2ae136 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2ae13a add sp, #0x3c
 *   @0x2ae146 movs r6, r1
 *
 * ══ png_read_filter_row  0x2ae148  size 276  本节 58 条（Thumb-2 半字段）｜入度 11
 * @func 0x2ae14e 0x2ae25a  size 268  58 条
 * 部分覆盖: 本节 58/125 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae14e ldr r2, [sp, #0x28]
 *   @0x2ae152 bhi 0x2ae246 <png_read_filter_row+0xfe>
 *   @0x2ae15a movs r1, #0x15
 *   @0x2ae15e ldrb r3, [r1, #0xb]
 *   @0x2ae162 adds r3, #0x7
 *   @0x2ae166 adds r2, r4, r3
 *   @0x2ae16a add r2, r1
 *   @0x2ae16e cmp r3, r0
 *   @0x2ae172 ldrb r5, [r4, r3]
 *   @0x2ae176 add r1, r5
 *   @0x2ae17a adds r3, #0x1
 *   @0x2ae17e pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae182 ldr r1, [r1, #0x4]
 *   @0x2ae186 cmp r2, r1
 *   @0x2ae18a ldrb r5, [r3, r2]
 *   @0x2ae18e add r0, r5
 *   @0x2ae192 adds r2, #0x1
 *   @0x2ae196 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae19a ldrb r0, [r1, #0xb]
 *   @0x2ae19e ldr r5, [r1, #0x4]
 *   @0x2ae1a2 asrs r0, r0, #0x3
 *   @0x2ae1a6 cmp r2, r0
 *   @0x2ae1aa ldrb r6, [r3, r2]
 *   @0x2ae1ae add.w r1, r1, r6, lsr #1
 *   @0x2ae1b2 strb r1, [r4, r2]
 *   @0x2ae1b6 b 0x2ae1a6 <png_read_filter_row+0x5e>
 *   @0x2ae1ba add r2, r3
 *   @0x2ae1be cmp r1, r5
 *   @0x2ae1c2 ldrb r6, [r2, r1]
 *   @0x2ae1c6 add r3, r6
 *   @0x2ae1ca add.w r3, r6, r3, lsr #1
 *   @0x2ae1ce strb r3, [r0, r1]
 *   @0x2ae1d2 b 0x2ae1be <png_read_filter_row+0x76>
 *   @0x2ae1da ldr r2, [r1, #0x4]
 *   @0x2ae1de asrs r0, r0, #0x3
 *   @0x2ae1e6 cmp r2, r0
 *   @0x2ae1ea ldrb r5, [r3, r2]
 *   @0x2ae1ee add r1, r5
 *   @0x2ae1f2 adds r2, #0x1
 *   @0x2ae1f6 adds r5, r4, r2
 *   @0x2ae1fe cmp r2, r9
 *   @0x2ae202 ldrb r0, [r3, r2]
 *   @0x2ae206 ldrb.w r6, [r10, r2]
 *   @0x2ae20a subs r7, r1, r0
 *   @0x2ae222 cmp r7, #0x0
 *   @0x2ae226 rsblt r7, r7, #0
 *   @0x2ae22a bgt 0x2ae230 <png_read_filter_row+0xe8>
 *   @0x2ae22e ble 0x2ae238 <png_read_filter_row+0xf0>
 *   @0x2ae232 ite gt
 *   @0x2ae236 movle r1, r6
 *   @0x2ae23a add r1, r0
 *   @0x2ae23e adds r2, #0x1
 *   @0x2ae242 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae246 ldr r1, [pc, #0x10]
 *   @0x2ae24a bl 0x2a6474 <png_warning>
 *   @0x2ae24e movs r3, #0x0
 *   @0x2ae252 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ae256 nop
 *
 * ══ png_read_finish_row  0x2ae25c  size 568  本节 100 条（Thumb-2 半字段）｜入度 8
 * @func 0x2ae25e 0x2ae492  size 564  100 条
 * 部分覆盖: 本节 100/241 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae25e mov r4, r0
 *   @0x2ae262 sub sp, #0x84
 *   @0x2ae266 add r6, pc
 *   @0x2ae26e stm r5!, {r0, r1, r2, r3}
 *   @0x2ae27e ldm r7!, {r0, r1, r2, r3}
 *   @0x2ae282 ldm.w r7, {r0, r1, r2}
 *   @0x2ae286 add.w r7, r6, #0x40
 *   @0x2ae28a adds r6, #0x5c
 *   @0x2ae292 ldm r7!, {r0, r1, r2, r3}
 *   @0x2ae296 ldm.w r7, {r0, r1, r2}
 *   @0x2ae29a stm.w r5, {r0, r1, r2}
 *   @0x2ae29e add r5, sp, #0x64
 *   @0x2ae2a2 stm r5!, {r0, r1, r2, r3}
 *   @0x2ae2ae str.w r3, [r4, #0x1a8]
 *   @0x2ae2b2 stm.w r5, {r0, r1, r2}
 *   @0x2ae2b6 ldr.w r2, [r4, #0x194]
 *   @0x2ae2ba cmp r3, r2
 *   @0x2ae2c6 beq 0x2ae342 <png_read_finish_row+0xe6>
 *   @0x2ae2ce ldr.w r0, [r4, #0x1ac]
 *   @0x2ae2d2 str.w r1, [r4, #0x1a8]
 *   @0x2ae2d6 adds r2, #0x1
 *   @0x2ae2e2 uxtb r5, r5
 *   @0x2ae2e6 bls 0x2ae2ee <png_read_finish_row+0x92>
 *   @0x2ae2ee add r3, sp, #0x80
 *   @0x2ae2fe adds r0, r3, r1
 *   @0x2ae306 blx 0x318c48 <__udivsi3>
 *   @0x2ae30a ldr.w r3, [r4, #0x134]
 *   @0x2ae30e lsls r2, r3, #0x1e
 *   @0x2ae312 str.w r0, [r4, #0x1a4]
 *   @0x2ae316 bmi.w 0x2ae470 <png_read_finish_row+0x214>
 *   @0x2ae31a ldr.w r3, [r4, #0x190]
 *   @0x2ae31e ldr r1, [r6, #-28]
 *   @0x2ae322 subs r3, #0x1
 *   @0x2ae32a subs r0, r0, r2
 *   @0x2ae332 uxtb r3, r3
 *   @0x2ae33a bne.w 0x2ae470 <png_read_finish_row+0x214>
 *   @0x2ae33e mov r5, r3
 *   @0x2ae342 ldr.w r3, [r4, #0x130]
 *   @0x2ae346 lsls r3, r3, #0x1a
 *   @0x2ae34a ldr r3, [pc, #0x130]
 *   @0x2ae34e add r3, pc
 *   @0x2ae352 ldrb r3, [r3, #0x4]
 *   @0x2ae356 strb.w r3, [sp, #0xc]
 *   @0x2ae35a add.w r3, sp, #0x7
 *   @0x2ae35e str.w r3, [r4, #0x144]
 *   @0x2ae362 movs r3, #0x1
 *   @0x2ae36e ldr r7, [pc, #0x110]
 *   @0x2ae372 add.w r6, r4, #0x1e0
 *   @0x2ae376 ldr.w r3, [r4, #0x1d0]
 *   @0x2ae37a cbnz r3, 0x2ae3a6 <png_read_finish_row+0x14a>
 *   @0x2ae37e mov r0, r4
 *   @0x2ae386 bl 0x2adbc4 <png_read_chunk_header>
 *   @0x2ae38a mov r1, r5
 *   @0x2ae38e str.w r0, [r4, #0x1d0]
 *   @0x2ae392 mov r0, r6
 *   @0x2ae39a beq 0x2ae376 <png_read_finish_row+0x11a>
 *   @0x2ae39e mov r1, r7
 *   @0x2ae3a6 ldr.w r2, [r4, #0x174]
 *   @0x2ae3aa mov r0, r4
 *   @0x2ae3b2 str.w r2, [r4, #0x13c]
 *   @0x2ae3b6 str.w r1, [r4, #0x138]
 *   @0x2ae3ba it hi
 *   @0x2ae3d2 str.w r3, [r4, #0x1d0]
 *   @0x2ae3d6 add.w r0, r4, #0x138
 *   @0x2ae3da movs r1, #0x1
 *   @0x2ae3e2 bne 0x2ae3fe <png_read_finish_row+0x1a2>
 *   @0x2ae3ea ldr.w r3, [r4, #0x13c]
 *   @0x2ae3ee cbnz r3, 0x2ae3f6 <png_read_finish_row+0x19a>
 *   @0x2ae3f6 ldr r1, [pc, #0x8c]
 *   @0x2ae3fa add r1, pc
 *   @0x2ae3fe cbz r0, 0x2ae414 <png_read_finish_row+0x1b8>
 *   @0x2ae406 ldr r1, [pc, #0x80]
 *   @0x2ae40a b 0x2ae40e <png_read_finish_row+0x1b2>
 *   @0x2ae40e mov r0, r4
 *   @0x2ae41a bne 0x2ae368 <png_read_finish_row+0x10c>
 *   @0x2ae41e mov r0, r4
 *   @0x2ae422 bl 0x2a6474 <png_warning>
 *   @0x2ae426 ldr.w r3, [r4, #0x12c]
 *   @0x2ae42a orr r3, r3, #0x8
 *   @0x2ae42e str.w r3, [r4, #0x12c]
 *   @0x2ae432 ldr.w r3, [r4, #0x130]
 *   @0x2ae436 orr r3, r3, #0x20
 *   @0x2ae43a str.w r3, [r4, #0x130]
 *   @0x2ae43e movs r3, #0x0
 *   @0x2ae44a ldr.w r3, [r4, #0x13c]
 *   @0x2ae44e cbz r3, 0x2ae45a <png_read_finish_row+0x1fe>
 *   @0x2ae452 mov r0, r4
 *   @0x2ae456 bl 0x2a6474 <png_warning>
 *   @0x2ae45a add.w r0, r4, #0x138
 *   @0x2ae45e blx 0xb6f40 <inflateReset@plt>
 *   @0x2ae462 ldr.w r3, [r4, #0x12c]
 *   @0x2ae466 orr r3, r3, #0x8
 *   @0x2ae46a str.w r3, [r4, #0x12c]
 *   @0x2ae46e b 0x2ae474 <png_read_finish_row+0x218>
 *   @0x2ae476 pop {r4, r5, r6, r7, pc}
 *   @0x2ae47a movs r6, r1
 *   @0x2ae47e movs r6, r1
 *   @0x2ae482 movs r5, r1
 *   @0x2ae486 movs r5, r1
 *   @0x2ae48e movs r5, r1
 *
 * ══ png_read_start_row  0x2ae494  size 544  本节 107 条（Thumb-2 半字段）｜入度 13
 * @func 0x2ae496 0x2ae6b2  size 540  107 条
 * 部分覆盖: 本节 107/242 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae496 mov r4, r0
 *   @0x2ae49a sub sp, #0x3c
 *   @0x2ae49e mov r5, sp
 *   @0x2ae4a6 ldm r7!, {r0, r1, r2, r3}
 *   @0x2ae4aa ldm.w r7, {r0, r1, r2}
 *   @0x2ae4ae stm.w r5, {r0, r1, r2}
 *   @0x2ae4b2 add r5, sp, #0x1c
 *   @0x2ae4b6 stm r5!, {r0, r1, r2, r3}
 *   @0x2ae4ba ldm.w r6, {r0, r1, r2}
 *   @0x2ae4be str.w r3, [r4, #0x13c]
 *   @0x2ae4c2 stm.w r5, {r0, r1, r2}
 *   @0x2ae4c6 mov r0, r4
 *   @0x2ae4de lsls r2, r5, #0x1e
 *   @0x2ae4e2 it pl
 *   @0x2ae4e6 add.w r0, r6, #0xffffffff
 *   @0x2ae4ea it pl
 *   @0x2ae4ee str.w r3, [r4, #0x194]
 *   @0x2ae4f2 ldrb.w r3, [r4, #0x1e8]
 *   @0x2ae4f6 add.w r3, r2, r3, lsl #2
 *   @0x2ae4fa ldr r1, [r3, #-28]
 *   @0x2ae4fe ldr r3, [r3, #-56]
 *   @0x2ae502 add r0, r1
 *   @0x2ae506 blx 0x318c48 <__udivsi3>
 *   @0x2ae50a str.w r0, [r4, #0x1a4]
 *   @0x2ae50e b 0x2ae518 <png_read_start_row+0x84>
 *   @0x2ae51a ldrb.w r0, [r4, #0x1ed]
 *   @0x2ae51e bpl 0x2ae52a <png_read_start_row+0x96>
 *   @0x2ae526 it ls
 *   @0x2ae52a ands r7, r5, #0x1000
 *   @0x2ae52e beq 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae536 bne 0x2ae546 <png_read_start_row+0xb2>
 *   @0x2ae53e ite eq
 *   @0x2ae542 movne r0, #0x20
 *   @0x2ae546 cbnz r3, 0x2ae558 <png_read_start_row+0xc4>
 *   @0x2ae54e it lt
 *   @0x2ae552 cbz r3, 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae556 b 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae55a bne 0x2ae56a <png_read_start_row+0xd6>
 *   @0x2ae562 lsls r0, r0, #0x2
 *   @0x2ae566 blx 0x318d10 <__divsi3>
 *   @0x2ae56a ands r2, r5, #0x8000
 *   @0x2ae56e beq 0x2ae594 <png_read_start_row+0x100>
 *   @0x2ae576 beq 0x2ae592 <png_read_start_row+0xfe>
 *   @0x2ae57a cmp r0, #0x8
 *   @0x2ae57e movgt r0, #0x20
 *   @0x2ae582 b 0x2ae594 <png_read_start_row+0x100>
 *   @0x2ae586 bne 0x2ae594 <png_read_start_row+0x100>
 *   @0x2ae58a ite gt
 *   @0x2ae58e movle r0, #0x20
 *   @0x2ae592 movs r0, #0x20
 *   @0x2ae596 bpl 0x2ae5ca <png_read_start_row+0x136>
 *   @0x2ae59e cbnz r7, 0x2ae5aa <png_read_start_row+0x116>
 *   @0x2ae5a2 ldrb.w r3, [r4, #0x1ea]
 *   @0x2ae5a6 cmp r3, #0x4
 *   @0x2ae5aa cmp r0, #0x10
 *   @0x2ae5ae movgt r0, #0x40
 *   @0x2ae5b2 b 0x2ae5ca <png_read_start_row+0x136>
 *   @0x2ae5b6 bgt 0x2ae5c2 <png_read_start_row+0x12e>
 *   @0x2ae5ba ite ne
 *   @0x2ae5be moveq r0, #0x20
 *   @0x2ae5c2 cmp r3, #0x6
 *   @0x2ae5c6 movne r0, #0x30
 *   @0x2ae5ca lsls r3, r5, #0xb
 *   @0x2ae5ce ldrb.w r2, [r4, #0x128]
 *   @0x2ae5d2 ldrb.w r3, [r4, #0x129]
 *   @0x2ae5d6 smulbb r3, r2, r3
 *   @0x2ae5da cmp r0, r3
 *   @0x2ae5de movlt r0, r3
 *   @0x2ae5e2 cmp r0, #0x7
 *   @0x2ae5ea lsrgt r5, r0, #0x3
 *   @0x2ae5f2 mulle r5, r6, r0
 *   @0x2ae5f6 add.w r0, r0, #0x7
 *   @0x2ae5fa ite gt
 *   @0x2ae5fe lsrle r5, r5, #0x3
 *   @0x2ae602 add.w r5, r5, r0, asr #3
 *   @0x2ae606 adds r5, #0x30
 *   @0x2ae60a bls 0x2ae648 <png_read_start_row+0x1b4>
 *   @0x2ae60e ldr.w r1, [r4, #0x2f4]
 *   @0x2ae612 bl 0x2a6cfc <png_free>
 *   @0x2ae616 ldrb.w r3, [r4, #0x1e7]
 *   @0x2ae61a mov r0, r4
 *   @0x2ae61e cbz r3, 0x2ae626 <png_read_start_row+0x192>
 *   @0x2ae626 bl 0x2a6ca0 <png_malloc>
 *   @0x2ae62a str.w r0, [r4, #0x2f4]
 *   @0x2ae62e ldr.w r3, [r4, #0x2f4]
 *   @0x2ae632 str.w r5, [r4, #0x328]
 *   @0x2ae636 add.w r2, r3, #0xf
 *   @0x2ae63a and r2, r2, #0xf
 *   @0x2ae63e rsb.w r2, r2, #0x20
 *   @0x2ae642 add r3, r2
 *   @0x2ae64e bne 0x2ae65a <png_read_start_row+0x1c6>
 *   @0x2ae652 mov r0, r4
 *   @0x2ae656 bl 0x2a642c <png_error>
 *   @0x2ae65a ldr.w r3, [r4, #0x19c]
 *   @0x2ae65e adds r2, r3, #0x1
 *   @0x2ae666 bls 0x2ae68c <png_read_start_row+0x1f8>
 *   @0x2ae66a ldr.w r1, [r4, #0x1ac]
 *   @0x2ae66e bl 0x2a6cfc <png_free>
 *   @0x2ae672 ldr.w r1, [r4, #0x19c]
 *   @0x2ae676 mov r0, r4
 *   @0x2ae67a bl 0x2a6ca0 <png_malloc>
 *   @0x2ae67e ldr.w r3, [r4, #0x19c]
 *   @0x2ae682 adds r3, #0x1
 *   @0x2ae692 ldr.w r0, [r4, #0x1ac]
 *   @0x2ae696 adds r2, #0x1
 *   @0x2ae6aa pop {r4, r5, r6, r7, pc}
 *   @0x2ae6ae movs r6, r1
 *
 * ══ png_set_bKGD  0x2ae6b4  size 32  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2ae6b6 0x2ae6d8  size 34  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae6b6 cbz r1, 0x2ae6d2 <png_set_bKGD+0x1e>
 *   @0x2ae6ba str.w r3, [r1, #0x5a]
 *   @0x2ae6be ldr r3, [r2, #0x4]
 *   @0x2ae6c6 strh.w r3, [r1, #0x62]
 *   @0x2ae6ca ldr r3, [r1, #0x8]
 *   @0x2ae6d2 bx lr
 *
 * ══ anon_2ae6d4  0x2ae6d4  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2ae6d4 0x2ae6d8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae6d4 andeq r0, r0, r0
 *
 * ══ png_set_cHRM  0x2ae6d8  size 264  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2ae6fe 0x2ae7e2  size 228  7 条
 * 部分覆盖: 本节 7/64 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae6fe beq 0x2ae7d0 <png_set_cHRM+0xf8>
 *   @0x2ae702 beq 0x2ae7d0 <png_set_cHRM+0xf8>
 *   @0x2ae70e orr r3, r3, #0x4
 *   @0x2ae712 str r3, [r1, #0x8]
 *   @0x2ae7d6 nop
 *   @0x2ae7da movs r0, r0
 *   @0x2ae7de lsrs r0, r7
 *
 * ══ png_set_cHRM_fixed  0x2ae7e0  size 280  本节 61 条（Thumb-2 半字段）｜入度 3
 * @func 0x2ae7e6 0x2ae902  size 284  63 条
 * 部分覆盖: 本节 63/134 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 62/132 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 61/130 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae7e6 mov r4, r1
 *   @0x2ae7ea mov r10, r3
 *   @0x2ae7f2 ldr r6, [sp, #0x40]
 *   @0x2ae7f6 cmp r0, #0x0
 *   @0x2ae7fa cmp r1, #0x0
 *   @0x2ae7fe ldr r3, [sp, #0x48]
 *   @0x2ae802 str r7, [sp]
 *   @0x2ae806 str r6, [sp, #0x4]
 *   @0x2ae80a ldr r3, [sp, #0x4c]
 *   @0x2ae80e str r3, [sp, #0x10]
 *   @0x2ae812 bl 0x2a6068 <png_check_cHRM_fixed>
 *   @0x2ae816 cmp r0, #0x0
 *   @0x2ae81a vmov s11, r11
 *   @0x2ae81e vldr d7, [pc, #208]
 *   @0x2ae822 ldr r3, [sp, #0x48]
 *   @0x2ae83a str.w r9, [r4, #0x108]
 *   @0x2ae83e str.w r7, [r4, #0x10c]
 *   @0x2ae842 str.w r3, [r4, #0x11c]
 *   @0x2ae846 vdiv.f64 d6, d6, d7
 *   @0x2ae84a str.w r6, [r4, #0x110]
 *   @0x2ae84e str.w r5, [r4, #0x114]
 *   @0x2ae852 vcvt.f32.f64 s12, d6
 *   @0x2ae856 vstr s12, [r4, #128]
 *   @0x2ae85a vcvt.f64.s32 d6, s11
 *   @0x2ae85e vmov s11, r9
 *   @0x2ae862 vdiv.f64 d6, d6, d7
 *   @0x2ae866 vcvt.f32.f64 s12, d6
 *   @0x2ae86a vstr s12, [r4, #132]
 *   @0x2ae86e vcvt.f64.s32 d6, s11
 *   @0x2ae872 vmov s11, r7
 *   @0x2ae876 vdiv.f64 d6, d6, d7
 *   @0x2ae87a vcvt.f32.f64 s12, d6
 *   @0x2ae87e vstr s12, [r4, #136]
 *   @0x2ae882 vcvt.f64.s32 d6, s11
 *   @0x2ae886 vmov s11, r6
 *   @0x2ae88a vdiv.f64 d6, d6, d7
 *   @0x2ae88e vcvt.f32.f64 s12, d6
 *   @0x2ae892 vstr s12, [r4, #140]
 *   @0x2ae896 vcvt.f64.s32 d6, s11
 *   @0x2ae89a vmov s11, r5
 *   @0x2ae89e vdiv.f64 d6, d6, d7
 *   @0x2ae8a2 vcvt.f32.f64 s12, d6
 *   @0x2ae8a6 vstr s12, [r4, #144]
 *   @0x2ae8aa vcvt.f64.s32 d6, s11
 *   @0x2ae8ae vldr s11, [sp, #72]
 *   @0x2ae8b2 vdiv.f64 d6, d6, d7
 *   @0x2ae8b6 vcvt.f32.f64 s12, d6
 *   @0x2ae8ba vstr s12, [r4, #148]
 *   @0x2ae8be vcvt.f64.s32 d6, s11
 *   @0x2ae8c2 vmov s11, r3
 *   @0x2ae8c6 ldr r3, [r4, #0x8]
 *   @0x2ae8ce vdiv.f64 d6, d6, d7
 *   @0x2ae8d2 vcvt.f32.f64 s12, d6
 *   @0x2ae8d6 vstr s12, [r4, #152]
 *   @0x2ae8da vcvt.f64.s32 d6, s11
 *   @0x2ae8de vdiv.f64 d7, d6, d7
 *   @0x2ae8e2 vcvt.f32.f64 s14, d7
 *   @0x2ae8e6 vstr s14, [r4, #156]
 *   @0x2ae8ea add sp, #0x18
 *   @0x2ae8f2 movs r0, r0
 *   @0x2ae8f6 lsrs r0, r7
 *
 * ══ png_set_gAMA  0x2ae8f8  size 144  本节 18 条（Thumb-2 半字段）｜入度 0
 * @func 0x2ae8fa 0x2ae982  size 136  18 条
 * 部分覆盖: 本节 18/52 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae8fa vpush {d8}
 *   @0x2ae8fe mov r4, r1
 *   @0x2ae906 cbz r0, 0x2ae964 <png_set_gAMA+0x6c>
 *   @0x2ae90a vldr d8, [pc, #100]
 *   @0x2ae90e vcmpe.f64 d7, d8
 *   @0x2ae912 vmrs APSR_nzcv, fpscr
 *   @0x2ae916 ble 0x2ae924 <png_set_gAMA+0x2c>
 *   @0x2ae91a add r1, pc
 *   @0x2ae92a vcvt.f32.f64 s13, d7
 *   @0x2ae92e orr r3, r3, #0x1
 *   @0x2ae932 str r3, [r4, #0x8]
 *   @0x2ae952 vpop {d8}
 *   @0x2ae956 mov r0, r5
 *   @0x2ae95a add r1, pc
 *   @0x2ae96a nop
 *   @0x2ae972 subs r0, r7, #0x2
 *   @0x2ae97a movs r0, r0
 *   @0x2ae97e lsrs r0, r7
 *
 * ══ png_set_gAMA_fixed  0x2ae988  size 124  本节 19 条（Thumb-2 半字段）｜入度 1
 * @func 0x2ae98a 0x2aea08  size 126  20 条
 * 部分覆盖: 本节 20/50 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ae98a mov r5, r1
 *   @0x2ae98e mov r6, r0
 *   @0x2ae992 cbz r1, 0x2ae9e8 <png_set_gAMA_fixed+0x60>
 *   @0x2ae99a bne 0x2ae9a6 <png_set_gAMA_fixed+0x1e>
 *   @0x2ae99e add r1, pc
 *   @0x2ae9a6 cmp r2, #0x0
 *   @0x2ae9aa ldr r1, [pc, #0x50]
 *   @0x2ae9ae add r1, pc
 *   @0x2ae9ba str.w r4, [r5, #0xfc]
 *   @0x2ae9be vcvt.f64.s32 d6, s15
 *   @0x2ae9c2 vldr d7, [pc, #44]
 *   @0x2ae9c6 orr r3, r3, #0x1
 *   @0x2ae9ca str r3, [r5, #0x8]
 *   @0x2ae9da ldr r1, [pc, #0x24]
 *   @0x2ae9de pop.w {r4, r5, r6, lr}
 *   @0x2ae9e2 add r1, pc
 *   @0x2ae9ea nop
 *   @0x2ae9f2 movs r0, r0
 *   @0x2ae9f6 lsrs r0, r7
 *
 * ══ anon_2aea04  0x2aea04  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aea04 0x2aea08  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aea04 andhi pc, r0, pc, lsr #7
 *
 * ══ png_set_hIST  0x2aea08  size 124  本节 24 条（Thumb-2 半字段）｜入度 3
 * @func 0x2aea0a 0x2aea7e  size 116  24 条
 * 部分覆盖: 本节 24/53 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aea0a mov r4, r1
 *   @0x2aea0e mov r5, r0
 *   @0x2aea12 cbz r1, 0x2aea7a <png_set_hIST+0x72>
 *   @0x2aea16 subs r3, #0x1
 *   @0x2aea1a cmp r3, #0xff
 *   @0x2aea1e ldr r1, [pc, #0x5c]
 *   @0x2aea22 b 0x2aea46 <png_set_hIST+0x3e>
 *   @0x2aea26 movs r3, #0x0
 *   @0x2aea2e mov.w r1, #0x200
 *   @0x2aea32 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aea36 str.w r0, [r5, #0x2b8]
 *   @0x2aea3a cbz r0, 0x2aea40 <png_set_hIST+0x38>
 *   @0x2aea3e b 0x2aea4e <png_set_hIST+0x46>
 *   @0x2aea42 mov r0, r5
 *   @0x2aea46 pop.w {r4, r5, r6, lr}
 *   @0x2aea4a b.w 0x2a6474 <png_warning>
 *   @0x2aea4e ldrh r2, [r4, #0x14]
 *   @0x2aea56 bge 0x2aea64 <png_set_hIST+0x5c>
 *   @0x2aea62 b 0x2aea4e <png_set_hIST+0x46>
 *   @0x2aea66 str r1, [r4, #0x7c]
 *   @0x2aea6e ldr.w r3, [r4, #0xb8]
 *   @0x2aea72 orr r3, r3, #0x8
 *   @0x2aea76 str.w r3, [r4, #0xb8]
 *   @0x2aea7a pop {r4, r5, r6, pc}
 *
 * ══ png_set_IHDR  0x2aea84  size 134  本节 32 条（Thumb-2 半字段）｜入度 5
 * @func 0x2aea86 0x2aeb0a  size 132  32 条
 * 部分覆盖: 本节 32/65 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aea86 sub sp, #0x14
 *   @0x2aea8a mov r5, r2
 *   @0x2aea8e ldr.w r12, [sp, #0x2c]
 *   @0x2aea92 ldr r7, [sp, #0x30]
 *   @0x2aea96 ldr r2, [sp, #0x38]
 *   @0x2aea9a beq 0x2aeb06 <png_set_IHDR+0x82>
 *   @0x2aea9e beq 0x2aeb06 <png_set_IHDR+0x82>
 *   @0x2aeaa2 strb.w r12, [r4, #0x19]
 *   @0x2aeaa6 uxtb.w r12, r12
 *   @0x2aeaaa strb r1, [r4, #0x1a]
 *   @0x2aeaae strb r2, [r4, #0x1b]
 *   @0x2aeab2 strb r7, [r4, #0x1c]
 *   @0x2aeab6 str r1, [sp, #0x8]
 *   @0x2aeaba str r2, [sp, #0xc]
 *   @0x2aeabe str r5, [r4]
 *   @0x2aeac2 strb r6, [r4, #0x18]
 *   @0x2aeaca bl 0x2a61b0 <png_check_IHDR>
 *   @0x2aeace ldrb r3, [r4, #0x19]
 *   @0x2aead2 bne 0x2aead8 <png_set_IHDR+0x54>
 *   @0x2aead6 b 0x2aeade <png_set_IHDR+0x5a>
 *   @0x2aeada bpl 0x2aead4 <png_set_IHDR+0x50>
 *   @0x2aeade lsls r3, r3, #0x1d
 *   @0x2aeae2 bpl 0x2aeaea <png_set_IHDR+0x66>
 *   @0x2aeae6 adds r3, #0x1
 *   @0x2aeaea ldrb r2, [r4, #0x18]
 *   @0x2aeaee muls r3, r2, r3
 *   @0x2aeaf2 strb r3, [r4, #0x1e]
 *   @0x2aeaf6 bls 0x2aeafe <png_set_IHDR+0x7a>
 *   @0x2aeafa muls r5, r3, r5
 *   @0x2aeafe muls r5, r3, r5
 *   @0x2aeb02 lsrs r5, r5, #0x3
 *   @0x2aeb06 add sp, #0x14
 *
 * ══ png_set_oFFs  0x2aeb0a  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aeb0c 0x2aeb26  size 26  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aeb0c cbz r1, 0x2aeb20 <png_set_oFFs+0x16>
 *   @0x2aeb10 ldr r3, [sp]
 *   @0x2aeb14 strb.w r3, [r1, #0x6c]
 *   @0x2aeb18 ldr r3, [r1, #0x8]
 *   @0x2aeb20 bx lr
 *
 * ══ anon_2aeb22  0x2aeb22  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aeb22 0x2aeb26  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aeb22 .word 0xe92d0000
 *
 * ══ png_set_pCAL  0x2aeb24  size 292  本节 60 条（Thumb-2 半字段）｜入度 5
 * @func 0x2aeb2a 0x2aec36  size 268  60 条
 * 部分覆盖: 本节 60/127 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aeb2a ldr r3, [sp, #0x30]
 *   @0x2aeb2e ldr.w r9, [sp, #0x34]
 *   @0x2aeb32 mov r5, r0
 *   @0x2aeb36 str r3, [sp, #0x4]
 *   @0x2aeb3a ldr.w r8, [sp, #0x40]
 *   @0x2aeb3e cmp r0, #0x0
 *   @0x2aeb42 cmp r1, #0x0
 *   @0x2aeb46 mov r0, r2
 *   @0x2aeb4a blx 0xb6538 <strlen@plt>
 *   @0x2aeb4e add.w r10, r0, #0x1
 *   @0x2aeb52 mov r0, r5
 *   @0x2aeb56 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aeb5a ldr r2, [sp]
 *   @0x2aeb62 ldr r1, [pc, #0xd4]
 *   @0x2aeb66 add r1, pc
 *   @0x2aeb6a mov r1, r2
 *   @0x2aeb6e blx 0xb65bc <memcpy@plt>
 *   @0x2aeb72 ldr r3, [sp, #0x4]
 *   @0x2aeb7a str.w r11, [r4, #0xa4]
 *   @0x2aeb7e str.w r3, [r4, #0xa8]
 *   @0x2aeb82 strb.w r7, [r4, #0xb5]
 *   @0x2aeb86 blx 0xb6538 <strlen@plt>
 *   @0x2aeb8a add.w r9, r0, #0x1
 *   @0x2aeb8e mov r0, r5
 *   @0x2aeb92 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aeb96 str.w r0, [r4, #0xac]
 *   @0x2aeb9a cbnz r0, 0x2aeba4 <png_set_pCAL+0x80>
 *   @0x2aeb9e mov r0, r5
 *   @0x2aeba2 b 0x2aec14 <png_set_pCAL+0xf0>
 *   @0x2aeba6 adds r6, r7, #0x1
 *   @0x2aebaa lsls r6, r6, #0x2
 *   @0x2aebb2 mov r1, r6
 *   @0x2aebbe ldr r1, [pc, #0x80]
 *   @0x2aebc2 add r1, pc
 *   @0x2aebc6 mov r2, r6
 *   @0x2aebca blx 0xb65b0 <memset@plt>
 *   @0x2aebce sub.w r8, r8, #0x4
 *   @0x2aebd2 movs r6, #0x0
 *   @0x2aebd6 ldr r1, [r8, #4]!
 *   @0x2aebda mov r2, r9
 *   @0x2aebe2 cmp r6, r7
 *   @0x2aebe6 ldr.w r0, [r8, #0x4]
 *   @0x2aebea blx 0xb6538 <strlen@plt>
 *   @0x2aebee ldr.w r10, [r4, #0xb0]
 *   @0x2aebf2 add.w r9, r0, #0x1
 *   @0x2aebf6 mov r0, r5
 *   @0x2aebfa bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aebfe str.w r0, [r10, r6, lsl #2]
 *   @0x2aec02 ldr.w r3, [r4, #0xb0]
 *   @0x2aec06 ldr.w r0, [r3, r6, lsl #2]
 *   @0x2aec0a cmp r0, #0x0
 *   @0x2aec0e ldr r1, [pc, #0x34]
 *   @0x2aec12 add r1, pc
 *   @0x2aec16 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2aec1a b.w 0x2a6474 <png_warning>
 *   @0x2aec1e ldr r3, [r4, #0x8]
 *   @0x2aec26 ldr.w r3, [r4, #0xb8]
 *   @0x2aec2a orr r3, r3, #0x80
 *   @0x2aec2e str.w r3, [r4, #0xb8]
 *   @0x2aec32 add sp, #0xc
 *
 * ══ png_set_sCAL  0x2aec48  size 34  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aec4a 0x2aec6a  size 32  3 条
 * 部分覆盖: 本节 3/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aec4a cbz r1, 0x2aec68 <png_set_sCAL+0x20>
 *   @0x2aec62 orr r3, r3, #0x4000
 *   @0x2aec66 str r3, [r1, #0x8]
 *
 * ══ png_set_pHYs  0x2aec6a  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aec6c 0x2aec96  size 42  10 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aec6c cbz r1, 0x2aec80 <png_set_pHYs+0x16>
 *   @0x2aec70 ldr r3, [sp]
 *   @0x2aec74 strb.w r3, [r1, #0x78]
 *   @0x2aec78 ldr r3, [r1, #0x8]
 *   @0x2aec80 bx lr
 *
 * ══ anon_2aec82  0x2aec82  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aec82 0x2aec96  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aec82 ldrblt r0, [r8, #0x0]!
 *
 * ══ png_set_PLTE  0x2aec84  size 152  本节 27 条（Thumb-2 半字段）｜入度 6
 * @func 0x2aec86 0x2aed16  size 144  27 条
 * 部分覆盖: 本节 27/63 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aec86 mov r4, r1
 *   @0x2aec8a mov r6, r3
 *   @0x2aec8e cmp r0, #0x0
 *   @0x2aec92 cmp r1, #0x0
 *   @0x2aec96 ldrb r3, [r1, #0x19]
 *   @0x2aec9a ittet eq
 *   @0x2aec9e moveq r0, #0x1
 *   @0x2aeca6 cmp r6, #0x0
 *   @0x2aecaa cmp r6, r0
 *   @0x2aecae cmp r3, #0x3
 *   @0x2aecb2 bne 0x2aecbe <png_set_PLTE+0x3a>
 *   @0x2aecb6 add r1, pc
 *   @0x2aecbe ldr r1, [pc, #0x58]
 *   @0x2aecc6 b.w 0x2a6474 <png_warning>
 *   @0x2aecca movs r3, #0x0
 *   @0x2aecd2 mov r1, r4
 *   @0x2aecde bl 0x2a6cd8 <png_calloc>
 *   @0x2aece2 movs r2, #0x3
 *   @0x2aece6 mov r1, r7
 *   @0x2aecea str.w r0, [r5, #0x1d8]
 *   @0x2aecee blx 0xb65bc <memcpy@plt>
 *   @0x2aecf2 ldr.w r3, [r5, #0x1d8]
 *   @0x2aecf6 str r3, [r4, #0x10]
 *   @0x2aed02 orr r3, r3, #0x1000
 *   @0x2aed06 str.w r3, [r4, #0xb8]
 *   @0x2aed0a ldr r3, [r4, #0x8]
 *   @0x2aed12 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ png_set_sBIT  0x2aed1c  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aed1e 0x2aed46  size 40  9 条
 * 部分覆盖: 本节 5/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aed1e cbz r1, 0x2aed32 <png_set_sBIT+0x16>
 *   @0x2aed22 str r3, [r1, #0x44]
 *   @0x2aed26 strb.w r3, [r1, #0x48]
 *   @0x2aed2a ldr r3, [r1, #0x8]
 *   @0x2aed32 bx lr
 *
 * ══ png_set_sRGB  0x2aed34  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aed36 0x2aed46  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aed36 cbz r1, 0x2aed44 <png_set_sRGB+0x10>
 *   @0x2aed3a strb.w r2, [r1, #0x2c]
 *   @0x2aed3e orr r3, r3, #0x800
 *   @0x2aed42 str r3, [r1, #0x8]
 *
 * ══ png_set_sRGB_gAMA_and_cHRM  0x2aed48  size 256  本节 53 条（Thumb-2 半字段）｜入度 5
 * @func 0x2aed4a 0x2aee4a  size 256  53 条
 * 部分覆盖: 本节 53/117 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aed4a mov r4, r1
 *   @0x2aed4e mov r5, r0
 *   @0x2aed52 beq 0x2aedfa <png_set_sRGB_gAMA_and_cHRM+0xb2>
 *   @0x2aed56 beq 0x2aedfa <png_set_sRGB_gAMA_and_cHRM+0xb2>
 *   @0x2aed5e ldrd r2, r3, [r3]
 *   @0x2aed62 mov r0, r5
 *   @0x2aed66 bl 0x2ae8f8 <png_set_gAMA>
 *   @0x2aed6a mov r0, r5
 *   @0x2aed6e movw r2, #0xb18f
 *   @0x2aed72 bl 0x2ae988 <png_set_gAMA_fixed>
 *   @0x2aed76 mov.w r0, #0xfa00
 *   @0x2aed7a movw r1, #0x80e8
 *   @0x2aed7e movw r2, #0x7530
 *   @0x2aed82 movw r3, #0xea60
 *   @0x2aed86 stm.w sp, {r0, r1, r2, r3}
 *   @0x2aed8a movw r3, #0x3a98
 *   @0x2aed8e mov r0, r5
 *   @0x2aed92 mov r1, r4
 *   @0x2aed9e movw r3, #0x8084
 *   @0x2aeda2 bl 0x2ae7e0 <png_set_cHRM_fixed>
 *   @0x2aeda6 adr r3, #96 <png_set_sRGB_gAMA_and_cHRM+0x7a>
 *   @0x2aedae mov r1, r4
 *   @0x2aedb6 ldrd r2, r3, [r3]
 *   @0x2aedba strd r2, r3, [sp, #8]
 *   @0x2aedbe adr r3, #88 <png_set_sRGB_gAMA_and_cHRM+0x90>
 *   @0x2aedca ldrd r2, r3, [r3]
 *   @0x2aedce strd r2, r3, [sp, #24]
 *   @0x2aedd2 adr r3, #84 <png_set_sRGB_gAMA_and_cHRM+0xa3>
 *   @0x2aedde ldrd r2, r3, [r3]
 *   @0x2aede2 strd r2, r3, [sp, #40]
 *   @0x2aede6 adr r3, #80 <png_set_sRGB_gAMA_and_cHRM+0xb6>
 *   @0x2aedf2 ldrd r2, r3, [r3]
 *   @0x2aedf6 bl 0x2ae6d8 <png_set_cHRM>
 *   @0x2aedfa add sp, #0x3c
 *   @0x2aedfe nop
 *   @0x2aee02 b 0x2aee06 <png_set_sRGB_gAMA_and_cHRM+0xbe>
 *   @0x2aee06 subs r7, #0xdd
 *   @0x2aee0a movs r0, r0
 *   @0x2aee0e subs r7, #0xd5
 *   @0x2aee12 ands r0, r0
 *   @0x2aee16 subs r7, #0xe4
 *   @0x2aee1a str r0, [r0]
 *   @0x2aee1e subs r7, #0xd5
 *   @0x2aee22 ands r0, r0
 *   @0x2aee26 subs r7, #0xd3
 *   @0x2aee2a ands r0, r0
 *   @0x2aee2e subs r7, #0xe3
 *   @0x2aee32 ands r0, r0
 *   @0x2aee36 subs r7, #0xc3
 *   @0x2aee3a b 0x2aee3e <png_set_sRGB_gAMA_and_cHRM+0xf6>
 *   @0x2aee3e subs r7, #0xae
 *   @0x2aee42 b 0x2aee46 <png_set_sRGB_gAMA_and_cHRM+0xfe>
 *   @0x2aee46 subs r7, #0xd4
 *
 * ══ png_set_iCCP  0x2aee48  size 176  本节 32 条（Thumb-2 半字段）｜入度 0
 * @func 0x2aee4e 0x2aeeee  size 160  32 条
 * 部分覆盖: 本节 32/72 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aee4e mov r7, r2
 *   @0x2aee52 ldr.w r9, [sp, #0x28]
 *   @0x2aee56 mov r5, r0
 *   @0x2aee5a cmp r0, #0x0
 *   @0x2aee5e cmp r1, #0x0
 *   @0x2aee62 cmp r2, #0x0
 *   @0x2aee66 cmp.w r9, #0x0
 *   @0x2aee6a beq 0x2aeeec <png_set_iCCP+0xa4>
 *   @0x2aee6e blx 0xb6538 <strlen@plt>
 *   @0x2aee72 add.w r10, r0, #0x1
 *   @0x2aee76 mov r0, r5
 *   @0x2aee7a bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aee7e mov r8, r0
 *   @0x2aee82 ldr r1, [pc, #0x6c]
 *   @0x2aee86 add r1, pc
 *   @0x2aee8a mov r1, r7
 *   @0x2aee8e blx 0xb65bc <memcpy@plt>
 *   @0x2aee92 mov r0, r5
 *   @0x2aee96 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aee9a mov r7, r0
 *   @0x2aee9e mov r0, r5
 *   @0x2aeea2 bl 0x2a6cfc <png_free>
 *   @0x2aeea6 ldr r1, [pc, #0x4c]
 *   @0x2aeeaa add r1, pc
 *   @0x2aeeb6 mov r2, r6
 *   @0x2aeebe mov r0, r5
 *   @0x2aeec2 movs r2, #0x10
 *   @0x2aeeda str.w r8, [r4, #0xc4]
 *   @0x2aeede orr r3, r3, #0x1000
 *   @0x2aeee2 str.w r7, [r4, #0xc8]
 *   @0x2aeee6 strb.w r11, [r4, #0xd0]
 *   @0x2aeeea str r3, [r4, #0x8]
 *
 * ══ png_set_text_2  0x2aeef8  size 488  本节 102 条（Thumb-2 半字段）｜入度 13
 * @func 0x2aeefe 0x2af0de  size 480  102 条
 * 部分覆盖: 本节 102/222 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2aeefe mov r4, r1
 *   @0x2aef02 str r3, [sp, #0xc]
 *   @0x2aef06 cbnz r0, 0x2aef0c <png_set_text_2+0x14>
 *   @0x2aef0a b 0x2af0d4 <png_set_text_2+0x1dc>
 *   @0x2aef0e beq 0x2aef08 <png_set_text_2+0x10>
 *   @0x2aef12 cmp r3, #0x0
 *   @0x2aef16 ldr r5, [r1, #0x30]
 *   @0x2aef1a ldr r7, [r4, #0x34]
 *   @0x2aef1e cmp r1, r7
 *   @0x2aef22 ldr r6, [r4, #0x38]
 *   @0x2aef2a adds r1, #0x8
 *   @0x2aef2e mul r1, r8, r1
 *   @0x2aef32 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aef36 str r0, [r4, #0x38]
 *   @0x2aef3a str r7, [r4, #0x34]
 *   @0x2aef3e b 0x2af0d2 <png_set_text_2+0x1da>
 *   @0x2aef42 mul r2, r8, r7
 *   @0x2aef46 blx 0xb65bc <memcpy@plt>
 *   @0x2aef4a ldr r0, [sp, #0x10]
 *   @0x2aef4e bl 0x2a6cfc <png_free>
 *   @0x2aef52 movs r3, #0x0
 *   @0x2aef56 ldr r3, [pc, #0x184]
 *   @0x2aef5a add r3, pc
 *   @0x2aef5e b 0x2aef9c <png_set_text_2+0xa4>
 *   @0x2aef62 str r6, [r4, #0x30]
 *   @0x2aef6a mul r1, r8, r1
 *   @0x2aef6e bl 0x2a6d16 <png_malloc_warn>
 *   @0x2aef72 str r0, [r4, #0x38]
 *   @0x2aef76 str r5, [r4, #0x30]
 *   @0x2aef7a b 0x2af0d2 <png_set_text_2+0x1da>
 *   @0x2aef8a ldr r3, [r4, #0x38]
 *   @0x2aef8e ldr r6, [r4, #0x30]
 *   @0x2aef92 cbnz r0, 0x2aefa6 <png_set_text_2+0xae>
 *   @0x2aef96 adds r5, #0x1c
 *   @0x2aef9a str r3, [sp, #0x4]
 *   @0x2aef9e ldr r3, [sp, #0xc]
 *   @0x2aefa2 blt 0x2aef8a <png_set_text_2+0x92>
 *   @0x2aefa6 ldr r2, [r5]
 *   @0x2aefaa cmp r3, #0x3
 *   @0x2aefae bls 0x2aefba <png_set_text_2+0xc2>
 *   @0x2aefb2 ldr r1, [sp, #0x14]
 *   @0x2aefba blx 0xb6538 <strlen@plt>
 *   @0x2aefbe ldr r3, [sp, #0x8]
 *   @0x2aefc2 mov r9, r0
 *   @0x2aefc6 ldr r0, [r5, #0x14]
 *   @0x2aefca blx 0xb6538 <strlen@plt>
 *   @0x2aefce mov r8, r0
 *   @0x2aefd2 cbz r0, 0x2aefe0 <png_set_text_2+0xe8>
 *   @0x2aefda movs r7, #0x0
 *   @0x2aefde b 0x2aefe2 <png_set_text_2+0xea>
 *   @0x2aefe2 movs r3, #0x1c
 *   @0x2aefe6 mul r11, r3, r6
 *   @0x2aefea ldr r6, [sp]
 *   @0x2aefee cbz r0, 0x2aeff4 <png_set_text_2+0xfc>
 *   @0x2aeff2 cbnz r2, 0x2af00c <png_set_text_2+0x114>
 *   @0x2aeff6 mov.w r10, #0x0
 *   @0x2aeffa ldr r3, [sp]
 *   @0x2aeffe ite gt
 *   @0x2af002 movle.w r2, #0xffffffff
 *   @0x2af006 str.w r2, [r3, r11]
 *   @0x2af00a b 0x2af01a <png_set_text_2+0x122>
 *   @0x2af012 ldr r3, [sp]
 *   @0x2af01a add.w r1, r9, #0x4
 *   @0x2af01e ldr r0, [sp, #0x10]
 *   @0x2af022 add r1, r7
 *   @0x2af026 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af02a str r0, [r6, #0x4]
 *   @0x2af02e beq 0x2af0d2 <png_set_text_2+0x1da>
 *   @0x2af032 ldr r1, [r5, #0x4]
 *   @0x2af03a mov.w r3, #0x0
 *   @0x2af03e strb.w r3, [r2, r9]
 *   @0x2af042 add.w r9, r9, #0x1
 *   @0x2af046 ldr r2, [r5]
 *   @0x2af04a cmp r2, #0x0
 *   @0x2af04e mov r2, r8
 *   @0x2af052 str r0, [r6, #0x14]
 *   @0x2af056 blx 0xb65bc <memcpy@plt>
 *   @0x2af05a ldr r2, [r6, #0x14]
 *   @0x2af06a add.w r0, r2, r8
 *   @0x2af06e mov r2, r7
 *   @0x2af072 ldr r1, [r5, #0x18]
 *   @0x2af07a mov.w r3, #0x0
 *   @0x2af07e strb r3, [r2, r7]
 *   @0x2af082 ldr r2, [r6, #0x18]
 *   @0x2af086 str r2, [r6, #0x8]
 *   @0x2af08a movs r2, #0x0
 *   @0x2af08e str r2, [r6, #0x14]
 *   @0x2af092 str r0, [r6, #0x8]
 *   @0x2af09a ldr r0, [r6, #0x8]
 *   @0x2af09e ldr r1, [r5, #0x8]
 *   @0x2af0a6 mov.w r3, #0x0
 *   @0x2af0aa strb.w r3, [r2, r10]
 *   @0x2af0ae ldr r3, [sp]
 *   @0x2af0b6 ble 0x2af0c2 <png_set_text_2+0x1ca>
 *   @0x2af0ba str.w r10, [r6, #0x10]
 *   @0x2af0be str r2, [r6, #0xc]
 *   @0x2af0c2 movs r3, #0x0
 *   @0x2af0ca ldr r3, [r4, #0x30]
 *   @0x2af0ce str r3, [r4, #0x30]
 *   @0x2af0d2 movs r0, #0x1
 *   @0x2af0d6 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2af0da nop
 *
 * ══ png_set_text  0x2af0e0  size 32  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af0e2 0x2af0fe  size 28  5 条
 * 部分覆盖: 本节 5/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af0e2 mov r4, r0
 *   @0x2af0ea ldr r1, [pc, #0x10]
 *   @0x2af0ee pop.w {r4, lr}
 *   @0x2af0f2 add r1, pc
 *   @0x2af0fa nop
 *
 * ══ png_set_tIME  0x2af100  size 76  本节 16 条（Thumb-2 半字段）｜入度 6
 * @func 0x2af102 0x2af14a  size 72  16 条
 * 部分覆盖: 本节 16/34 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af102 cbz r1, 0x2af146 <png_set_tIME+0x46>
 *   @0x2af10a bmi 0x2af146 <png_set_tIME+0x46>
 *   @0x2af10e subs r3, #0x1
 *   @0x2af112 bhi 0x2af12e <png_set_tIME+0x2e>
 *   @0x2af116 subs r3, #0x1
 *   @0x2af11a bhi 0x2af12e <png_set_tIME+0x2e>
 *   @0x2af11e cmp r3, #0x17
 *   @0x2af122 ldrb r3, [r2, #0x5]
 *   @0x2af126 bhi 0x2af12e <png_set_tIME+0x2e>
 *   @0x2af12a cmp r3, #0x3c
 *   @0x2af12e ldr r1, [pc, #0x18]
 *   @0x2af132 b.w 0x2a6474 <png_warning>
 *   @0x2af136 ldr r3, [r2]
 *   @0x2af13a ldr r3, [r2, #0x4]
 *   @0x2af13e ldr r3, [r1, #0x8]
 *   @0x2af146 bx lr
 *
 * ══ png_set_tRNS  0x2af14c  size 192  本节 39 条（Thumb-2 半字段）｜入度 4
 * @func 0x2af152 0x2af206  size 180  39 条
 * 部分覆盖: 本节 39/84 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af152 mov r8, r2
 *   @0x2af156 ldr r6, [sp, #0x18]
 *   @0x2af15a cmp r0, #0x0
 *   @0x2af15e cmp r1, #0x0
 *   @0x2af162 cmp.w r3, #0x100
 *   @0x2af166 bls 0x2af174 <png_set_tRNS+0x28>
 *   @0x2af16a pop.w {r4, r5, r6, r7, r8, lr}
 *   @0x2af16e add r1, pc
 *   @0x2af176 movs r3, #0x0
 *   @0x2af182 mov.w r1, #0x100
 *   @0x2af186 bl 0x2a6ca0 <png_malloc>
 *   @0x2af18a subs r3, r5, #0x1
 *   @0x2af18e str r0, [r4, #0x4c]
 *   @0x2af196 ldr r0, [r4, #0x4c]
 *   @0x2af19a mov r2, r5
 *   @0x2af1a2 ldrb r3, [r4, #0x18]
 *   @0x2af1a6 lsl.w r3, r2, r3
 *   @0x2af1aa ldrb r2, [r4, #0x19]
 *   @0x2af1ae ldrh r2, [r6, #0x8]
 *   @0x2af1b2 cmp r2, #0x2
 *   @0x2af1b6 ldrh r2, [r6, #0x2]
 *   @0x2af1ba bgt 0x2af1c8 <png_set_tRNS+0x7c>
 *   @0x2af1be cmp r2, r3
 *   @0x2af1c2 ldrh r2, [r6, #0x6]
 *   @0x2af1c6 ble 0x2af1d2 <png_set_tRNS+0x86>
 *   @0x2af1ca mov r0, r7
 *   @0x2af1ce bl 0x2a6474 <png_warning>
 *   @0x2af1d2 ldr r3, [r6]
 *   @0x2af1d6 it eq
 *   @0x2af1da str r3, [r4, #0x50]
 *   @0x2af1de str r3, [r4, #0x54]
 *   @0x2af1e2 strh.w r3, [r4, #0x58]
 *   @0x2af1e6 strh r5, [r4, #0x16]
 *   @0x2af1ea ldr r3, [r4, #0x8]
 *   @0x2af1f2 ldr.w r3, [r4, #0xb8]
 *   @0x2af1f6 orr r3, r3, #0x2000
 *   @0x2af1fa str.w r3, [r4, #0xb8]
 *   @0x2af1fe pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2af202 nop
 *
 * ══ png_set_sPLT  0x2af20c  size 308  本节 56 条（Thumb-2 半字段）｜入度 4
 * @func 0x2af212 0x2af336  size 292  56 条
 * 部分覆盖: 本节 56/129 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af212 sub sp, #0x14
 *   @0x2af216 mov r9, r3
 *   @0x2af21a cmp r0, #0x0
 *   @0x2af222 beq.w 0x2af32c <png_set_sPLT+0x120>
 *   @0x2af226 ldr.w r1, [r1, #0xd8]
 *   @0x2af22a add r1, r3
 *   @0x2af22e bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af232 mov r6, r0
 *   @0x2af236 ldr r1, [pc, #0xfc]
 *   @0x2af23a add r1, pc
 *   @0x2af23e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af242 b.w 0x2a6474 <png_warning>
 *   @0x2af246 ldr.w r2, [r4, #0xd8]
 *   @0x2af24a mov r11, r8
 *   @0x2af252 lsls r2, r2, #0x4
 *   @0x2af25a ldr.w r1, [r4, #0xd4]
 *   @0x2af25e bl 0x2a6cfc <png_free>
 *   @0x2af262 ldr r3, [pc, #0xd4]
 *   @0x2af26a str r3, [sp, #0x8]
 *   @0x2af26e add r3, pc
 *   @0x2af272 cmp r7, r9
 *   @0x2af27a ldr.w r0, [r11]
 *   @0x2af27e add.w r8, r7, r2
 *   @0x2af282 blx 0xb6538 <strlen@plt>
 *   @0x2af286 lsl.w r8, r8, #0x4
 *   @0x2af28a add.w r10, r6, r8
 *   @0x2af28e adds r2, r0, #0x1
 *   @0x2af292 str r2, [sp, #0x4]
 *   @0x2af296 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af29a str.w r0, [r6, r8]
 *   @0x2af29e ldr r2, [sp, #0x4]
 *   @0x2af2a2 mov r0, r5
 *   @0x2af2a6 bl 0x2a6474 <png_warning>
 *   @0x2af2aa b 0x2af306 <png_set_sPLT+0xfa>
 *   @0x2af2ba mov r0, r5
 *   @0x2af2be bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af2c2 mov r2, r0
 *   @0x2af2ca mov r0, r5
 *   @0x2af2ce str r2, [sp, #0x4]
 *   @0x2af2d6 ldr.w r1, [r6, r8]
 *   @0x2af2da bl 0x2a6cfc <png_free>
 *   @0x2af2de ldr r2, [sp, #0x4]
 *   @0x2af2e6 ldr.w r2, [r11, #0xc]
 *   @0x2af2ea movs r3, #0xa
 *   @0x2af2f2 blx 0xb65bc <memcpy@plt>
 *   @0x2af2f6 ldr.w r2, [r11, #0xc]
 *   @0x2af2fa str.w r2, [r10, #0xc]
 *   @0x2af2fe ldrb.w r2, [r11, #0x4]
 *   @0x2af302 strb.w r2, [r10, #0x4]
 *   @0x2af306 adds r7, #0x1
 *   @0x2af30e ldr r3, [r4, #0x8]
 *   @0x2af312 str.w r6, [r4, #0xd4]
 *   @0x2af316 orr r3, r3, #0x2000
 *   @0x2af31a str r3, [r4, #0x8]
 *   @0x2af32e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2af332 nop
 *
 * ══ png_set_unknown_chunks  0x2af340  size 244  本节 45 条（Thumb-2 半字段）｜入度 4
 * @func 0x2af346 0x2af42a  size 228  45 条
 * 部分覆盖: 本节 45/102 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af346 mov r5, r2
 *   @0x2af34a mov r6, r0
 *   @0x2af34e beq 0x2af426 <png_set_unknown_chunks+0xe6>
 *   @0x2af352 beq 0x2af426 <png_set_unknown_chunks+0xe6>
 *   @0x2af356 beq 0x2af426 <png_set_unknown_chunks+0xe6>
 *   @0x2af362 mul r1, r9, r1
 *   @0x2af366 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af36a mov r8, r0
 *   @0x2af36e ldr r1, [pc, #0xbc]
 *   @0x2af372 add r1, pc
 *   @0x2af376 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af37a b.w 0x2a6474 <png_warning>
 *   @0x2af37e ldr.w r2, [r4, #0xc0]
 *   @0x2af382 ldr.w r1, [r4, #0xbc]
 *   @0x2af386 ldr.w r11, [pc, #0xa8]
 *   @0x2af38a mul r2, r9, r2
 *   @0x2af38e blx 0xb65bc <memcpy@plt>
 *   @0x2af392 mov r0, r6
 *   @0x2af39a bl 0x2a6cfc <png_free>
 *   @0x2af39e movs r3, #0x0
 *   @0x2af3a2 str.w r3, [r4, #0xbc]
 *   @0x2af3a6 cmp r10, r7
 *   @0x2af3ae add r3, r10
 *   @0x2af3b2 mul r2, r1, r3
 *   @0x2af3b6 ldr r1, [r5]
 *   @0x2af3ca str.w r2, [r9, #0xc]
 *   @0x2af3ce ldr.w r2, [r6, #0x12c]
 *   @0x2af3d2 strb.w r2, [r9, #0x10]
 *   @0x2af3d6 ldr r1, [r5, #0xc]
 *   @0x2af3da str.w r1, [r9, #0x8]
 *   @0x2af3de b 0x2af408 <png_set_unknown_chunks+0xc8>
 *   @0x2af3e2 bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af3e6 mov r2, r0
 *   @0x2af3ee mov r0, r6
 *   @0x2af3f2 str r2, [sp, #0x4]
 *   @0x2af3fa str.w r2, [r9, #0xc]
 *   @0x2af3fe b 0x2af408 <png_set_unknown_chunks+0xc8>
 *   @0x2af402 ldr r2, [r5, #0xc]
 *   @0x2af40e b 0x2af3a6 <png_set_unknown_chunks+0x66>
 *   @0x2af412 ldr.w r3, [r4, #0xb8]
 *   @0x2af416 str.w r8, [r4, #0xbc]
 *   @0x2af41a orr r3, r3, #0x200
 *   @0x2af41e str.w r7, [r4, #0xc0]
 *   @0x2af422 str.w r3, [r4, #0xb8]
 *   @0x2af426 add sp, #0xc
 *
 * ══ png_set_unknown_chunk_location  0x2af434  size 30  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af436 0x2af452  size 28  5 条
 * 部分覆盖: 本节 5/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af436 cbz r1, 0x2af450 <png_set_unknown_chunk_location+0x1c>
 *   @0x2af43a blt 0x2af450 <png_set_unknown_chunk_location+0x1c>
 *   @0x2af442 bge 0x2af450 <png_set_unknown_chunk_location+0x1c>
 *   @0x2af44a mla r2, r0, r2, r1
 *   @0x2af44e strb r3, [r2, #0x10]
 *
 * ══ png_permit_mng_features  0x2af452  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af454 0x2af460  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af454 and r1, r1, #0x5
 *   @0x2af458 str.w r1, [r0, #0x2dc]
 *   @0x2af45c mov r0, r1
 *
 * ══ png_set_keep_unknown_chunks  0x2af460  size 192  本节 27 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af466 0x2af50a  size 164  27 条
 * 部分覆盖: 本节 27/68 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af466 mov r11, r2
 *   @0x2af46a mov r4, r0
 *   @0x2af46e beq 0x2af51c <png_set_keep_unknown_chunks+0xbc>
 *   @0x2af472 subs r3, r1, #0x2
 *   @0x2af476 ldr.w r3, [r0, #0x130]
 *   @0x2af47a bhi 0x2af48c <png_set_keep_unknown_chunks+0x2c>
 *   @0x2af47e it eq
 *   @0x2af486 orr r3, r3, #0x8000
 *   @0x2af48a b 0x2af490 <png_set_keep_unknown_chunks+0x30>
 *   @0x2af4a6 ldr.w r8, [r0, #0x2cc]
 *   @0x2af4aa mov.w r9, #0x5
 *   @0x2af4ae add.w r10, r3, r8
 *   @0x2af4b2 mul r1, r9, r10
 *   @0x2af4b6 bl 0x2a6ca0 <png_malloc>
 *   @0x2af4ba ldr.w r1, [r4, #0x2d0]
 *   @0x2af4be mov r7, r0
 *   @0x2af4c2 mul r2, r9, r8
 *   @0x2af4c6 blx 0xb65bc <memcpy@plt>
 *   @0x2af4ca mov r0, r4
 *   @0x2af4d6 str.w r3, [r4, #0x2d0]
 *   @0x2af4da mov.w r9, #0x5
 *   @0x2af4de mov r1, r11
 *   @0x2af4f2 blx 0xb65bc <memcpy@plt>
 *   @0x2af4f6 movs r3, #0x0
 *   @0x2af4fa bge 0x2af508 <png_set_keep_unknown_chunks+0xa8>
 *   @0x2af502 strb.w r6, [r8, r2]
 *   @0x2af506 b 0x2af4f8 <png_set_keep_unknown_chunks+0x98>
 *
 * ══ png_set_read_user_chunk_fn  0x2af520  size 12  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af522 0x2af53e  size 28  7 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af522 str.w r2, [r0, #0x2c8]
 *   @0x2af526 str.w r1, [r0, #0x2c4]
 *   @0x2af52a bx lr
 *
 * ══ png_set_rows  0x2af52c  size 44  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af52e 0x2af562  size 52  10 条
 * 部分覆盖: 本节 8/19 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af52e mov r4, r1
 *   @0x2af532 cbz r0, 0x2af556 <png_set_rows+0x2a>
 *   @0x2af536 ldr.w r3, [r1, #0xf8]
 *   @0x2af53a cbz r3, 0x2af548 <png_set_rows+0x1c>
 *   @0x2af53e beq 0x2af548 <png_set_rows+0x1c>
 *   @0x2af542 movs r3, #0x0
 *   @0x2af54e ldr r3, [r4, #0x8]
 *   @0x2af556 pop {r3, r4, r5, pc}
 *
 * ══ png_set_compression_buffer_size  0x2af558  size 46  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af55a 0x2af572  size 24  3 条
 * 部分覆盖: 本节 3/9 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af55a mov r5, r1
 *   @0x2af55e cbz r0, 0x2af584 <png_set_compression_buffer_size+0x2c>
 *   @0x2af56e mov r1, r5
 *
 * ══ png_set_invalid  0x2af586  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af588 0x2af594  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af588 cbz r1, 0x2af592 <png_set_invalid+0xc>
 *   @0x2af58c bic.w r3, r3, r2
 *   @0x2af590 str r3, [r1, #0x8]
 *
 * ══ png_set_user_limits  0x2af594  size 12  本节 3 条（Thumb-2 半字段）｜入度 2
 * @func 0x2af596 0x2af5b2  size 28  7 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af596 str.w r1, [r0, #0x308]
 *   @0x2af59a str.w r2, [r0, #0x30c]
 *   @0x2af59e bx lr
 *
 * ══ png_set_chunk_cache_max  0x2af5a0  size 8  本节 2 条（Thumb-2 半字段）｜入度 1
 * @func 0x2af5a2 0x2af5ba  size 24  6 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af5a2 str.w r1, [r0, #0x310]
 *   @0x2af5a6 bx lr
 *
 * ══ png_set_chunk_malloc_max  0x2af5a8  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af5aa 0x2af5c2  size 24  6 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af5aa str.w r1, [r0, #0x1a0]
 *   @0x2af5ae bx lr
 *
 * ══ png_check_keyword  0x2af5b0  size 392  本节 87 条（Thumb-2 半字段）｜入度 11
 * @func 0x2af5b2 0x2af74a  size 408  91 条
 * 部分覆盖: 本节 91/193 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 90/191 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 89/189 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 88/187 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 87/185 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af5b2 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2af5b6 add r3, pc
 *   @0x2af5ba mov r6, r2
 *   @0x2af5be ldr r2, [r3]
 *   @0x2af5c2 mov r5, r0
 *   @0x2af5c6 mov r9, r1
 *   @0x2af5ca str r2, [sp, #0x34]
 *   @0x2af5ce mov r0, r1
 *   @0x2af5d6 cbnz r0, 0x2af5e6 <png_check_keyword+0x36>
 *   @0x2af5da mov r0, r5
 *   @0x2af5de bl 0x2a6474 <png_warning>
 *   @0x2af5e2 movs r0, #0x0
 *   @0x2af5e6 mov r0, r5
 *   @0x2af5ea bl 0x2a6d16 <png_malloc_warn>
 *   @0x2af5ee mov r8, r0
 *   @0x2af5f2 cbz r0, 0x2af604 <png_check_keyword+0x54>
 *   @0x2af602 b 0x2af630 <png_check_keyword+0x80>
 *   @0x2af606 mov r0, r5
 *   @0x2af60a b 0x2af5de <png_check_keyword+0x2e>
 *   @0x2af60e bhi 0x2af63e <png_check_keyword+0x8e>
 *   @0x2af612 mov r2, r11
 *   @0x2af616 str.w r12, [sp]
 *   @0x2af61a blx 0xb65c8 <snprintf@plt>
 *   @0x2af61e mov r0, r5
 *   @0x2af622 bl 0x2a6474 <png_warning>
 *   @0x2af626 ldr.w r12, [sp]
 *   @0x2af62a strb.w r12, [r8, r7]
 *   @0x2af62e adds r7, #0x1
 *   @0x2af63a bne 0x2af60c <png_check_keyword+0x5c>
 *   @0x2af63e sub.w r2, r3, #0x7f
 *   @0x2af642 cmp r2, #0x21
 *   @0x2af646 strb.w r3, [r8, r7]
 *   @0x2af64a b 0x2af62e <png_check_keyword+0x7e>
 *   @0x2af64e subs r1, r4, #0x1
 *   @0x2af652 adds r7, r0, r1
 *   @0x2af656 cmp r2, #0x20
 *   @0x2af65a ldr r1, [pc, #0xc8]
 *   @0x2af65e str r3, [sp]
 *   @0x2af662 bl 0x2a6474 <png_warning>
 *   @0x2af666 ldr r3, [sp]
 *   @0x2af66a ldrb r1, [r2, r4]
 *   @0x2af66e bne 0x2af676 <png_check_keyword+0xc6>
 *   @0x2af672 subs r4, #0x1
 *   @0x2af676 ldr r7, [r6]
 *   @0x2af67a cmp r3, #0x20
 *   @0x2af67e ldr r1, [pc, #0xa8]
 *   @0x2af682 add r1, pc
 *   @0x2af68a mov r3, r7
 *   @0x2af68e subs r4, r1, r3
 *   @0x2af692 adds r3, #0x1
 *   @0x2af696 beq 0x2af68c <png_check_keyword+0xdc>
 *   @0x2af69a subs r7, #0x1
 *   @0x2af69e movs r0, #0x0
 *   @0x2af6a6 cmp r2, #0x20
 *   @0x2af6aa cbnz r0, 0x2af6b4 <png_check_keyword+0x104>
 *   @0x2af6ae adds r3, #0x1
 *   @0x2af6b2 b 0x2af6a0 <png_check_keyword+0xf0>
 *   @0x2af6b6 movs r1, #0x1
 *   @0x2af6ba strb r2, [r3]
 *   @0x2af6be b 0x2af69e <png_check_keyword+0xee>
 *   @0x2af6c2 cbz r1, 0x2af6ce <png_check_keyword+0x11e>
 *   @0x2af6c6 mov r0, r5
 *   @0x2af6ca bl 0x2a6474 <png_warning>
 *   @0x2af6ce cbnz r4, 0x2af6e4 <png_check_keyword+0x134>
 *   @0x2af6d2 ldr r1, [r6]
 *   @0x2af6da mov r0, r5
 *   @0x2af6de bl 0x2a6474 <png_warning>
 *   @0x2af6e2 b 0x2af6fe <png_check_keyword+0x14e>
 *   @0x2af6e6 bls 0x2af6fe <png_check_keyword+0x14e>
 *   @0x2af6ea mov r0, r5
 *   @0x2af6ee bl 0x2a6474 <png_warning>
 *   @0x2af6f2 ldr r3, [r6]
 *   @0x2af6f6 movs r0, #0x4f
 *   @0x2af6fe mov r0, r4
 *   @0x2af702 ldr r2, [sp, #0x34]
 *   @0x2af706 cmp r2, r3
 *   @0x2af70a blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2af70e add sp, #0x3c
 *   @0x2af716 movs r3, r2
 *   @0x2af71a movs r5, r1
 *   @0x2af71e movs r5, r1
 *   @0x2af722 movs r5, r1
 *   @0x2af726 movs r5, r1
 *   @0x2af72a movs r5, r1
 *   @0x2af72e movs r5, r1
 *   @0x2af732 movs r5, r1
 *   @0x2af736 movs r5, r1
 *
 * ══ png_set_bgr  0x2af738  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af73a 0x2af75a  size 32  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af73a ldr.w r3, [r0, #0x134]
 *   @0x2af73e orr r3, r3, #0x1
 *   @0x2af742 str.w r3, [r0, #0x134]
 *   @0x2af746 bx lr
 *
 * ══ png_set_swap  0x2af748  size 24  本节 6 条（Thumb-2 半字段）｜入度 1
 * @func 0x2af74a 0x2af772  size 40  10 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af74a ldrb.w r3, [r0, #0x1eb]
 *   @0x2af74e cmp r3, #0x10
 *   @0x2af752 ldr.w r3, [r0, #0x134]
 *   @0x2af756 orr r3, r3, #0x10
 *   @0x2af75a str.w r3, [r0, #0x134]
 *   @0x2af75e bx lr
 *
 * ══ png_set_packing  0x2af760  size 30  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af762 0x2af77a  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af762 ldrb.w r3, [r0, #0x1eb]
 *   @0x2af766 cmp r3, #0x7
 *   @0x2af76a ldr.w r3, [r0, #0x134]
 *   @0x2af76e orr r3, r3, #0x4
 *   @0x2af772 str.w r3, [r0, #0x134]
 *   @0x2af776 movs r3, #0x8
 *
 * ══ png_set_packswap  0x2af77e  size 24  本节 6 条（Thumb-2 半字段）｜入度 1
 * @func 0x2af780 0x2af7a8  size 40  10 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af780 ldrb.w r3, [r0, #0x1eb]
 *   @0x2af784 cmp r3, #0x7
 *   @0x2af788 ldr.w r3, [r0, #0x134]
 *   @0x2af78c orr r3, r3, #0x10000
 *   @0x2af790 str.w r3, [r0, #0x134]
 *   @0x2af794 bx lr
 *
 * ══ png_set_shift  0x2af796  size 28  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af798 0x2af7bc  size 36  8 条
 * 部分覆盖: 本节 6/13 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af798 ldr.w r3, [r0, #0x134]
 *   @0x2af79c orr r3, r3, #0x8
 *   @0x2af7a0 str.w r3, [r0, #0x134]
 *   @0x2af7a4 ldr r3, [r1]
 *   @0x2af7ac strb.w r3, [r0, #0x249]
 *   @0x2af7b0 bx lr
 *
 * ══ png_set_interlace_handling  0x2af7b2  size 28  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af7b4 0x2af7d8  size 36  6 条
 * 部分覆盖: 本节 6/15 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 5/13 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 4/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af7b4 ldrb.w r3, [r0, #0x1e7]
 *   @0x2af7b8 cbz r3, 0x2af7ca <png_set_interlace_handling+0x18>
 *   @0x2af7c8 bx lr
 *   @0x2af7cc bx lr
 *
 * ══ png_set_filler  0x2af7ce  size 68  本节 12 条（Thumb-2 半字段）｜入度 3
 * @func 0x2af7d0 0x2af824  size 84  16 条
 * 部分覆盖: 本节 15/35 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/33 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/31 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af7d0 ldr.w r3, [r0, #0x134]
 *   @0x2af7d4 cmp r2, #0x1
 *   @0x2af7e8 orreq r3, r3, #0x80
 *   @0x2af7ec bicne r3, r3, #0x80
 *   @0x2af7f0 str.w r3, [r0, #0x130]
 *   @0x2af7f4 ldrb.w r3, [r0, #0x1ea]
 *   @0x2af7f8 cmp r3, #0x2
 *   @0x2af7fc movs r3, #0x4
 *   @0x2af800 cbnz r3, 0x2af810 <png_set_filler+0x42>
 *   @0x2af808 bls 0x2af810 <png_set_filler+0x42>
 *   @0x2af80c strb.w r3, [r0, #0x1ef]
 *   @0x2af810 bx lr
 *
 * ══ png_set_add_alpha  0x2af812  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af814 0x2af83c  size 40  10 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af814 mov r4, r0
 *   @0x2af818 bl 0x2af7ce <png_set_filler>
 *   @0x2af81c ldr.w r3, [r4, #0x134]
 *   @0x2af820 orr r3, r3, #0x1000000
 *   @0x2af824 str.w r3, [r4, #0x134]
 *   @0x2af828 pop {r4, pc}
 *
 * ══ png_set_swap_alpha  0x2af82a  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af82c 0x2af84c  size 32  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af82c ldr.w r3, [r0, #0x134]
 *   @0x2af830 orr r3, r3, #0x20000
 *   @0x2af834 str.w r3, [r0, #0x134]
 *   @0x2af838 bx lr
 *
 * ══ png_set_invert_alpha  0x2af83a  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af83c 0x2af85c  size 32  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af83c ldr.w r3, [r0, #0x134]
 *   @0x2af840 orr r3, r3, #0x80000
 *   @0x2af844 str.w r3, [r0, #0x134]
 *   @0x2af848 bx lr
 *
 * ══ png_set_invert_mono  0x2af84a  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af84c 0x2af86c  size 32  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af84c ldr.w r3, [r0, #0x134]
 *   @0x2af850 orr r3, r3, #0x20
 *   @0x2af854 str.w r3, [r0, #0x134]
 *   @0x2af858 bx lr
 *
 * ══ png_do_invert  0x2af85a  size 92  本节 21 条（Thumb-2 半字段）｜入度 4
 * @func 0x2af85c 0x2af8c8  size 108  25 条
 * 部分覆盖: 本节 25/52 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/50 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/44 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af85c ldrb r3, [r0, #0x8]
 *   @0x2af860 ldr r3, [r0, #0x4]
 *   @0x2af864 cmp r1, r3
 *   @0x2af868 ldrb r2, [r1]
 *   @0x2af86c strb r2, [r1], #1
 *   @0x2af870 b 0x2af864 <png_do_invert+0xa>
 *   @0x2af874 ldrh r3, [r0, #0x8]
 *   @0x2af87c bne 0x2af892 <png_do_invert+0x38>
 *   @0x2af880 movs r3, #0x0
 *   @0x2af884 bhs 0x2af890 <png_do_invert+0x36>
 *   @0x2af888 mvns r0, r0
 *   @0x2af88c adds r3, #0x2
 *   @0x2af890 pop {r4, pc}
 *   @0x2af898 bne 0x2af8b4 <png_do_invert+0x5a>
 *   @0x2af89c movs r3, #0x0
 *   @0x2af8a0 bhs 0x2af8b4 <png_do_invert+0x5a>
 *   @0x2af8a4 mvns r2, r2
 *   @0x2af8a8 adds r2, r1, r3
 *   @0x2af8ac ldrb r4, [r2, #0x1]
 *   @0x2af8b0 strb r4, [r2, #0x1]
 *   @0x2af8b4 pop {r4, pc}
 *
 * ══ png_do_swap  0x2af8b6  size 46  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2af8b8 0x2af8e4  size 44  10 条
 * 部分覆盖: 本节 10/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af8b8 ldrb r3, [r0, #0x9]
 *   @0x2af8bc bne 0x2af8e2 <png_do_swap+0x2c>
 *   @0x2af8c0 ldr r2, [r0]
 *   @0x2af8c4 movs r3, #0x0
 *   @0x2af8c8 add.w r1, r1, #0x2
 *   @0x2af8cc beq 0x2af8e2 <png_do_swap+0x2c>
 *   @0x2af8d4 ldrb r4, [r1, #-1]
 *   @0x2af8d8 strb r0, [r1, #-1]
 *   @0x2af8dc strb r4, [r1, #-2]
 *   @0x2af8e0 b 0x2af8c6 <png_do_swap+0x10>
 *
 * ══ png_do_packswap  0x2af8e4  size 76  本节 16 条（Thumb-2 半字段）｜入度 5
 * @func 0x2af8e6 0x2af93e  size 88  19 条
 * 部分覆盖: 本节 17/37 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 16/35 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af8e6 cmp r3, #0x7
 *   @0x2af8ea cmp r3, #0x1
 *   @0x2af8ee beq 0x2af902 <png_do_packswap+0x1e>
 *   @0x2af8f2 beq 0x2af908 <png_do_packswap+0x24>
 *   @0x2af8f6 bne 0x2af922 <png_do_packswap+0x3e>
 *   @0x2af8fa add r3, pc
 *   @0x2af902 ldr r3, [pc, #0x24]
 *   @0x2af906 b 0x2af910 <png_do_packswap+0x2c>
 *   @0x2af90a add r3, pc
 *   @0x2af912 cmp r1, r2
 *   @0x2af916 bhs 0x2af922 <png_do_packswap+0x3e>
 *   @0x2af91a ldrb r0, [r3, r0]
 *   @0x2af922 bx lr
 *   @0x2af926 movs r6, r1
 *   @0x2af92a movs r6, r1
 *   @0x2af92e movs r6, r1
 *
 * ══ png_do_strip_filler  0x2af930  size 440  本节 71 条（Thumb-2 半字段）｜入度 18
 * @func 0x2af932 0x2afafa  size 456  75 条
 * 部分覆盖: 本节 75/189 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 74/187 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 73/185 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 72/183 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 71/181 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2af932 ldrb r4, [r0, #0x8]
 *   @0x2af936 cmp r4, #0x2
 *   @0x2af93a cmp r4, #0x6
 *   @0x2af942 bpl.w 0x2afada <png_do_strip_filler+0x1aa>
 *   @0x2af946 ldrb r5, [r0, #0xa]
 *   @0x2af94a bne 0x2afa42 <png_do_strip_filler+0x112>
 *   @0x2af94e and r5, r2, #0x80
 *   @0x2af952 cmp r4, #0x8
 *   @0x2af956 cbnz r5, 0x2af962 <png_do_strip_filler+0x32>
 *   @0x2af95a mov r4, r1
 *   @0x2af962 adds r4, r1, #0x4
 *   @0x2af966 movs r5, #0x1
 *   @0x2af96a bhs 0x2af98a <png_do_strip_filler+0x5a>
 *   @0x2af96e adds r5, #0x1
 *   @0x2af972 adds r1, #0x3
 *   @0x2af98a movs r1, #0x18
 *   @0x2af98e movs r1, #0x3
 *   @0x2af992 cmp r4, r5
 *   @0x2af996 ldrb r6, [r1, #0x1]
 *   @0x2af99a adds r1, #0x4
 *   @0x2af9b2 cbnz r5, 0x2af9b8 <png_do_strip_filler+0x88>
 *   @0x2af9b6 b 0x2afa08 <png_do_strip_filler+0xd8>
 *   @0x2af9be movs r5, #0x1
 *   @0x2af9c2 bhs 0x2af9fa <png_do_strip_filler+0xca>
 *   @0x2af9c6 adds r5, #0x1
 *   @0x2af9ca adds r1, #0x6
 *   @0x2af9fa movs r1, #0x30
 *   @0x2af9fe movs r1, #0x6
 *   @0x2afa02 str r3, [r0, #0x4]
 *   @0x2afa06 b 0x2afad8 <png_do_strip_filler+0x1a8>
 *   @0x2afa0a beq 0x2af9fa <png_do_strip_filler+0xca>
 *   @0x2afa0e adds r5, #0x1
 *   @0x2afa12 adds r4, #0x6
 *   @0x2afa42 cbz r4, 0x2afa4c <png_do_strip_filler+0x11c>
 *   @0x2afa46 bne 0x2afada <png_do_strip_filler+0x1aa>
 *   @0x2afa4a bpl 0x2afada <png_do_strip_filler+0x1aa>
 *   @0x2afa4e cmp r4, #0x2
 *   @0x2afa52 ldrb r4, [r0, #0x9]
 *   @0x2afa56 and r4, r2, #0x80
 *   @0x2afa5a bne 0x2afa84 <png_do_strip_filler+0x154>
 *   @0x2afa5e movs r4, #0x0
 *   @0x2afa62 beq 0x2afa6e <png_do_strip_filler+0x13e>
 *   @0x2afa6a adds r4, #0x1
 *   @0x2afa6e movs r1, #0x8
 *   @0x2afa72 b 0x2afab6 <png_do_strip_filler+0x186>
 *   @0x2afa76 beq 0x2afa6e <png_do_strip_filler+0x13e>
 *   @0x2afa7e strb r5, [r1, r4]
 *   @0x2afa82 b 0x2afa74 <png_do_strip_filler+0x144>
 *   @0x2afa86 mov r5, r1
 *   @0x2afa8a adds r4, r1, #0x4
 *   @0x2afa8e movs r5, #0x1
 *   @0x2afa92 add.w r4, r4, #0x4
 *   @0x2afa96 add.w r1, r1, #0x2
 *   @0x2afa9a bhs 0x2afab0 <png_do_strip_filler+0x180>
 *   @0x2afaa2 strb r6, [r1, #-2]
 *   @0x2afaa6 ldrb r6, [r4, #-3]
 *   @0x2afaaa strb r6, [r1, #-1]
 *   @0x2afaae b 0x2afa90 <png_do_strip_filler+0x160>
 *   @0x2afab2 movs r1, #0x10
 *   @0x2afab6 str r3, [r0, #0x4]
 *   @0x2afaba b 0x2afad8 <png_do_strip_filler+0x1a8>
 *   @0x2afabe add.w r5, r5, #0x2
 *   @0x2afac2 beq 0x2afab0 <png_do_strip_filler+0x180>
 *   @0x2afac6 adds r4, #0x1
 *   @0x2afaca strb r6, [r5, #-2]
 *   @0x2aface ldrb r6, [r1, #-1]
 *   @0x2afad2 strb r6, [r5, #-1]
 *   @0x2afad6 b 0x2afabc <png_do_strip_filler+0x18c>
 *   @0x2afada lsls r3, r2, #0x9
 *   @0x2afade ldrb r3, [r0, #0x8]
 *   @0x2afae6 pop {r4, r5, r6, pc}
 *
 * ══ png_do_bgr  0x2afae8  size 182  本节 38 条（Thumb-2 半字段）｜入度 5
 * @func 0x2afaea 0x2afb9e  size 180  38 条
 * 部分覆盖: 本节 38/83 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afaea ldrb r3, [r0, #0x8]
 *   @0x2afaee bpl 0x2afb9c <png_do_bgr+0xb4>
 *   @0x2afaf2 ldrb r0, [r0, #0x9]
 *   @0x2afaf6 bne 0x2afb3e <png_do_bgr+0x56>
 *   @0x2afafa bne 0x2afb1a <png_do_bgr+0x32>
 *   @0x2afafe mla r2, r3, r2, r1
 *   @0x2afb02 cmp r1, r2
 *   @0x2afb06 ldrb r3, [r1]
 *   @0x2afb0a ldrb r0, [r1, #-1]
 *   @0x2afb0e strb r3, [r1, #-1]
 *   @0x2afb12 strb r0, [r1, #-3]
 *   @0x2afb16 b 0x2afb02 <png_do_bgr+0x1a>
 *   @0x2afb1a cmp r3, #0x6
 *   @0x2afb1e movs r3, #0x0
 *   @0x2afb22 add.w r1, r1, #0x4
 *   @0x2afb26 beq 0x2afb3c <png_do_bgr+0x54>
 *   @0x2afb2e ldrb r4, [r1, #-2]
 *   @0x2afb32 strb r0, [r1, #-2]
 *   @0x2afb36 strb r4, [r1, #-4]
 *   @0x2afb3a b 0x2afb20 <png_do_bgr+0x38>
 *   @0x2afb3e cmp r0, #0x10
 *   @0x2afb42 cmp r3, #0x2
 *   @0x2afb46 movs r3, #0x0
 *   @0x2afb4a beq 0x2afb6e <png_do_bgr+0x86>
 *   @0x2afb4e adds r3, #0x1
 *   @0x2afb52 adds r1, #0x6
 *   @0x2afb6e pop {r4, pc}
 *   @0x2afb72 bne 0x2afb9c <png_do_bgr+0xb4>
 *   @0x2afb76 cmp r3, r2
 *   @0x2afb7a ldrb r0, [r1]
 *   @0x2afb7e ldrb r4, [r1, #0x4]
 *   @0x2afb82 strb r0, [r1, #-4]
 *   @0x2afb86 strb r4, [r1, #-8]
 *   @0x2afb8a ldrb r0, [r1, #-7]
 *   @0x2afb8e ldrb r4, [r1, #-3]
 *   @0x2afb92 strb r0, [r1, #-3]
 *   @0x2afb96 strb r4, [r1, #-7]
 *   @0x2afb9a b 0x2afb76 <png_do_bgr+0x8e>
 *
 * ══ png_set_user_transform_info  0x2afb9e  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afba0 0x2afbbe  size 30  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afba0 str.w r1, [r0, #0x124]
 *   @0x2afba4 strb.w r2, [r0, #0x128]
 *   @0x2afba8 strb.w r3, [r0, #0x129]
 *   @0x2afbac bx lr
 *
 * ══ png_get_user_transform_ptr  0x2afbae  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afbb0 0x2afbca  size 26  7 条
 * 部分覆盖: 本节 3/5 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afbb0 ldr.w r0, [r0, #0x124]
 *   @0x2afbb4 bx lr
 *
 * ══ anon_2afbb6  0x2afbb6  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afbb6 0x2afbca  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afbb6 ldrlt r0, [r8, #-0x0]!
 *
 * ══ png_default_write_data  0x2afbb8  size 44  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2afbba 0x2afbf6  size 60  13 条
 * 部分覆盖: 本节 11/24 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afbba mov r5, r2
 *   @0x2afbbe cbz r0, 0x2afbde <png_default_write_data+0x26>
 *   @0x2afbc2 ldr.w r3, [r4, #0x118]
 *   @0x2afbc6 movs r1, #0x1
 *   @0x2afbce beq 0x2afbde <png_default_write_data+0x26>
 *   @0x2afbd2 mov r0, r4
 *   @0x2afbda b.w 0x2a642c <png_error>
 *   @0x2afbde pop {r3, r4, r5, pc}
 *   @0x2afbe2 movs r5, r1
 *
 * ══ png_default_flush  0x2afbe4  size 12  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afbe6 0x2afc02  size 28  7 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afbe6 ldr.w r0, [r0, #0x118]
 *   @0x2afbea b.w 0x31bb1c <__udivdi3+0x484>
 *   @0x2afbee bx lr
 *
 * ══ png_write_data  0x2afbf0  size 28  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afbf2 0x2afc1e  size 44  10 条
 * 部分覆盖: 本节 6/13 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afbf2 ldr.w r3, [r0, #0x110]
 *   @0x2afbf6 cbz r3, 0x2afbfc <png_write_data+0xc>
 *   @0x2afbfa pop {r3, pc}
 *   @0x2afbfe pop.w {r3, lr}
 *   @0x2afc02 add r1, pc
 *   @0x2afc0a movs r5, r1
 *
 * ══ png_flush  0x2afc0c  size 12  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afc0e 0x2afc2a  size 28  7 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afc0e ldr.w r3, [r0, #0x210]
 *   @0x2afc12 cbz r3, 0x2afc16 <png_flush+0xa>
 *   @0x2afc16 pop {r3, pc}
 *
 * ══ png_set_write_fn  0x2afc18  size 88  本节 21 条（Thumb-2 半字段）｜入度 0
 * @func 0x2afc1a 0x2afc72  size 88  21 条
 * 部分覆盖: 本节 21/43 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afc1a mov r4, r0
 *   @0x2afc1e str.w r1, [r0, #0x118]
 *   @0x2afc22 cbnz r2, 0x2afc2a <png_set_write_fn+0x12>
 *   @0x2afc26 add r2, pc
 *   @0x2afc2a str.w r2, [r4, #0x110]
 *   @0x2afc2e cbnz r3, 0x2afc36 <png_set_write_fn+0x1e>
 *   @0x2afc32 add r3, pc
 *   @0x2afc36 str.w r3, [r4, #0x210]
 *   @0x2afc3a ldr.w r3, [r4, #0x114]
 *   @0x2afc3e cbz r3, 0x2afc5e <png_set_write_fn+0x46>
 *   @0x2afc42 mov r0, r4
 *   @0x2afc46 str.w r3, [r4, #0x114]
 *   @0x2afc4a add r1, pc
 *   @0x2afc52 mov r0, r4
 *   @0x2afc56 pop.w {r4, lr}
 *   @0x2afc5a b.w 0x2a6474 <png_warning>
 *   @0x2afc5e pop {r4, pc}
 *   @0x2afc62 movs r4, r2
 *   @0x2afc66 movs r4, r2
 *   @0x2afc6a movs r5, r1
 *   @0x2afc6e movs r5, r1
 *
 * ══ png_write_info_before_PLTE  0x2afc70  size 420  本节 67 条（Thumb-2 半字段）｜入度 5
 * @func 0x2afc76 0x2afe16  size 416  67 条
 * 部分覆盖: 本节 67/171 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afc76 sub sp, #0x38
 *   @0x2afc7a cmp r0, #0x0
 *   @0x2afc82 beq.w 0x2afe04 <png_write_info_before_PLTE+0x194>
 *   @0x2afc86 ldr.w r3, [r0, #0x12c]
 *   @0x2afc8a ands r6, r3, #0x400
 *   @0x2afc8e bne.w 0x2afe04 <png_write_info_before_PLTE+0x194>
 *   @0x2afc92 bl 0x2b1140 <png_write_sig>
 *   @0x2afc96 ldr.w r3, [r5, #0x12c]
 *   @0x2afc9a lsls r2, r3, #0x13
 *   @0x2afc9e ldr.w r3, [r5, #0x2dc]
 *   @0x2afca2 cbz r3, 0x2afcb2 <png_write_info_before_PLTE+0x42>
 *   @0x2afca6 mov r0, r5
 *   @0x2afcaa bl 0x2a6474 <png_warning>
 *   @0x2afcae str.w r6, [r5, #0x2dc]
 *   @0x2afcb2 ldrb r2, [r4, #0x19]
 *   @0x2afcb6 ldrb r3, [r4, #0x18]
 *   @0x2afcba ldrb r2, [r4, #0x1a]
 *   @0x2afcbe ldrb r2, [r4, #0x1b]
 *   @0x2afcc2 ldrb r2, [r4, #0x1c]
 *   @0x2afcc6 ldm.w r4, {r1, r2}
 *   @0x2afcca bl 0x2b12e4 <png_write_IHDR>
 *   @0x2afcce ldr r3, [r4, #0x8]
 *   @0x2afcd2 bpl 0x2afce6 <png_write_info_before_PLTE+0x76>
 *   @0x2afcde vmov r2, r3, d6
 *   @0x2afce2 bl 0x2b17c0 <png_write_gAMA>
 *   @0x2afce6 ldr r3, [r4, #0x8]
 *   @0x2afcea bpl 0x2afcf6 <png_write_info_before_PLTE+0x86>
 *   @0x2afcee ldrb.w r1, [r4, #0x2c]
 *   @0x2afcf2 bl 0x2b184c <png_write_sRGB>
 *   @0x2afcf6 ldr r3, [r4, #0x8]
 *   @0x2afcfa bpl 0x2afd12 <png_write_info_before_PLTE+0xa2>
 *   @0x2afd02 ldr.w r1, [r4, #0xc4]
 *   @0x2afd06 movs r2, #0x0
 *   @0x2afd0a ldr.w r3, [r4, #0xc8]
 *   @0x2afd0e bl 0x2b1890 <png_write_iCCP>
 *   @0x2afd12 ldr r3, [r4, #0x8]
 *   @0x2afd16 bpl 0x2afd24 <png_write_info_before_PLTE+0xb4>
 *   @0x2afd1a add.w r1, r4, #0x44
 *   @0x2afd1e ldrb r2, [r4, #0x19]
 *   @0x2afd26 lsls r1, r3, #0x1d
 *   @0x2afd2a vldr s14, [r4, #132]
 *   @0x2afd2e vcvt.f64.f32 d7, s14
 *   @0x2afd32 vldr s13, [r4, #128]
 *   @0x2afd36 mov r0, r5
 *   @0x2afd96 ldr.w r3, [r5, #0x12c]
 *   @0x2afd9a orr r3, r3, #0x400
 *   @0x2afd9e str.w r3, [r5, #0x12c]
 *   @0x2afda2 b 0x2afe04 <png_write_info_before_PLTE+0x194>
 *   @0x2afdaa ldr.w r6, [r4, #0xbc]
 *   @0x2afdae add r8, pc
 *   @0x2afdbe bhs 0x2afd96 <png_write_info_before_PLTE+0x126>
 *   @0x2afdc2 mov r1, r6
 *   @0x2afdca beq 0x2afe00 <png_write_info_before_PLTE+0x190>
 *   @0x2afdce cbz r3, 0x2afe00 <png_write_info_before_PLTE+0x190>
 *   @0x2afdd6 ldrb r3, [r6, #0x3]
 *   @0x2afdda bmi 0x2afde8 <png_write_info_before_PLTE+0x178>
 *   @0x2afdde beq 0x2afde8 <png_write_info_before_PLTE+0x178>
 *   @0x2afde6 bpl 0x2afe00 <png_write_info_before_PLTE+0x190>
 *   @0x2afdea cbnz r3, 0x2afdf4 <png_write_info_before_PLTE+0x184>
 *   @0x2afdee mov r1, r8
 *   @0x2afdf6 mov r1, r6
 *   @0x2afdfa ldr r3, [r6, #0xc]
 *   @0x2afe02 b 0x2afdb0 <png_write_info_before_PLTE+0x140>
 *   @0x2afe06 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2afe0a nop
 *   @0x2afe0e movs r5, r1
 *   @0x2afe12 movs r5, r1
 *
 * ══ png_write_info  0x2afe14  size 536  本节 99 条（Thumb-2 半字段）｜入度 22
 * @func 0x2afe1a 0x2b002e  size 532  99 条
 * 部分覆盖: 本节 99/232 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2afe1a sub sp, #0x14
 *   @0x2afe1e cmp r0, #0x0
 *   @0x2afe26 beq.w 0x2b0022 <png_write_info+0x20e>
 *   @0x2afe2a bl 0x2afc70 <png_write_info_before_PLTE>
 *   @0x2afe2e ldr r3, [r6, #0x8]
 *   @0x2afe32 bpl 0x2afe40 <png_write_info+0x2c>
 *   @0x2afe36 ldr r1, [r6, #0x10]
 *   @0x2afe3a bl 0x2b15d0 <png_write_PLTE>
 *   @0x2afe3e b 0x2afe50 <png_write_info+0x3c>
 *   @0x2afe42 cmp r3, #0x3
 *   @0x2afe46 ldr r1, [pc, #0x1e0]
 *   @0x2afe4a add r1, pc
 *   @0x2afe52 lsls r3, r3, #0x1b
 *   @0x2afe56 ldr.w r3, [r7, #0x134]
 *   @0x2afe5a lsls r5, r3, #0xc
 *   @0x2afe5e ldrb r2, [r6, #0x19]
 *   @0x2afe62 ldrh r3, [r6, #0x16]
 *   @0x2afe66 str r2, [sp]
 *   @0x2afe72 ldrb r3, [r6, #0x19]
 *   @0x2afe76 bne 0x2afe5e <png_write_info+0x4a>
 *   @0x2afe7a ldrh r2, [r6, #0x16]
 *   @0x2afe7e bge 0x2afe5e <png_write_info+0x4a>
 *   @0x2afe82 ldrb r1, [r2, r3]
 *   @0x2afe86 strb r1, [r2, r3]
 *   @0x2afe8a b 0x2afe7a <png_write_info+0x66>
 *   @0x2afe8e lsls r4, r3, #0x1a
 *   @0x2afe92 mov r0, r7
 *   @0x2afe9a bl 0x2b1e54 <png_write_bKGD>
 *   @0x2afe9e ldr r3, [r6, #0x8]
 *   @0x2afea2 bpl 0x2afeae <png_write_info+0x9a>
 *   @0x2afea6 ldr r1, [r6, #0x7c]
 *   @0x2afeaa bl 0x2b1f28 <png_write_hIST>
 *   @0x2afeae ldr r3, [r6, #0x8]
 *   @0x2afeb2 bpl 0x2afec2 <png_write_info+0xae>
 *   @0x2afeb6 ldr r1, [r6, #0x64]
 *   @0x2afeba ldrb.w r3, [r6, #0x6c]
 *   @0x2afebe bl 0x2b21d8 <png_write_oFFs>
 *   @0x2afec2 ldr r3, [r6, #0x8]
 *   @0x2afec6 bpl 0x2afeec <png_write_info+0xd8>
 *   @0x2afed2 str r3, [sp]
 *   @0x2afeda ldr.w r3, [r6, #0xac]
 *   @0x2afede str r3, [sp, #0x8]
 *   @0x2afee6 ldm r1, {r1, r2, r3}
 *   @0x2afeee lsls r3, r3, #0x11
 *   @0x2afef2 ldrd r4, r5, [r6, #232]
 *   @0x2afef6 mov r0, r7
 *   @0x2aff0a lsls r5, r3, #0x18
 *   @0x2aff0e mov r0, r7
 *   @0x2aff12 ldr r2, [r6, #0x74]
 *   @0x2aff1e lsls r4, r3, #0x16
 *   @0x2aff22 mov r0, r7
 *   @0x2aff3a lsls r0, r3, #0x12
 *   @0x2aff3e movs r4, #0x0
 *   @0x2aff42 mov.w r8, #0x0
 *   @0x2aff46 mov.w r10, #0x1c
 *   @0x2aff4a mvn r9, #0x2
 *   @0x2aff4e mvn r11, #0x1
 *   @0x2aff52 b 0x2aff86 <png_write_info+0x172>
 *   @0x2aff5a bge 0x2aff42 <png_write_info+0x12e>
 *   @0x2aff62 add.w r1, r1, r4, lsl #4
 *   @0x2aff66 adds r4, #0x1
 *   @0x2aff6e bne 0x2affb0 <png_write_info+0x19c>
 *   @0x2aff72 mov r0, r7
 *   @0x2aff76 ldr r2, [r4, #0x8]
 *   @0x2aff7e str.w r11, [r3, r5]
 *   @0x2aff82 add.w r8, r8, #0x1
 *   @0x2aff86 ldr r3, [r6, #0x30]
 *   @0x2aff8a bge 0x2affc8 <png_write_info+0x1b4>
 *   @0x2aff92 adds r4, r3, r5
 *   @0x2aff96 cmp r3, #0x0
 *   @0x2aff9a ldr r2, [r4, #0x18]
 *   @0x2aff9e mov r0, r7
 *   @0x2affa2 ldr r2, [r4, #0x8]
 *   @0x2affa6 ldr r2, [r4, #0x4]
 *   @0x2affaa bl 0x2b20b8 <png_write_iTXt>
 *   @0x2affae b 0x2affc0 <png_write_info+0x1ac>
 *   @0x2affb2 bne 0x2aff82 <png_write_info+0x16e>
 *   @0x2affb6 ldr r1, [r4, #0x4]
 *   @0x2affba movs r3, #0x0
 *   @0x2affc2 str.w r9, [r3, r5]
 *   @0x2affc6 b 0x2aff82 <png_write_info+0x16e>
 *   @0x2affce ldr.w r4, [r6, #0xbc]
 *   @0x2affd2 movs r5, #0x14
 *   @0x2affe2 bhs 0x2b0022 <png_write_info+0x20e>
 *   @0x2affe6 mov r1, r4
 *   @0x2affee beq 0x2b001e <png_write_info+0x20a>
 *   @0x2afff2 cbz r3, 0x2b001e <png_write_info+0x20a>
 *   @0x2afffa bne 0x2b001e <png_write_info+0x20a>
 *   @0x2afffe bmi 0x2b001e <png_write_info+0x20a>
 *   @0x2b0002 lsls r2, r3, #0x1a
 *   @0x2b0006 cmp r0, #0x3
 *   @0x2b000a ldr.w r3, [r7, #0x130]
 *   @0x2b000e lsls r3, r3, #0xf
 *   @0x2b0012 mov r0, r7
 *   @0x2b0016 ldr r2, [r4, #0x8]
 *   @0x2b001a bl 0x2b12bc <png_write_chunk>
 *   @0x2b001e adds r4, #0x14
 *   @0x2b0022 add sp, #0x14
 *   @0x2b002a movs r5, r1
 *
 * ══ png_write_end  0x2b002c  size 284  本节 54 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b0032 0x2b015a  size 296  58 条
 * 部分覆盖: 本节 58/132 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 57/130 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 56/128 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 55/126 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 54/124 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0032 mov r4, r0
 *   @0x2b0036 beq.w 0x2b013c <png_write_end+0x110>
 *   @0x2b003a ldr.w r3, [r0, #0x12c]
 *   @0x2b003e lsls r7, r3, #0x1d
 *   @0x2b0042 ldr r1, [pc, #0x100]
 *   @0x2b0046 bl 0x2a642c <png_error>
 *   @0x2b004a cbnz r5, 0x2b0064 <png_write_end+0x38>
 *   @0x2b0052 orr r3, r3, #0x8
 *   @0x2b0056 str.w r3, [r4, #0x12c]
 *   @0x2b005a add sp, #0xc
 *   @0x2b0066 lsls r6, r3, #0x16
 *   @0x2b006a ldr.w r3, [r4, #0x12c]
 *   @0x2b006e lsls r0, r3, #0x16
 *   @0x2b0072 mov r0, r4
 *   @0x2b008e cmp r8, r3
 *   @0x2b0092 mul r7, r10, r8
 *   @0x2b0096 ldr r3, [r5, #0x38]
 *   @0x2b009a ldr r3, [r3, r7]
 *   @0x2b009e ble 0x2b00b6 <png_write_end+0x8a>
 *   @0x2b00a2 mov r1, r3
 *   @0x2b00a6 str r2, [sp]
 *   @0x2b00aa str r2, [sp, #0x4]
 *   @0x2b00ae ldr r3, [r6, #0x14]
 *   @0x2b00b6 bne 0x2b00cc <png_write_end+0xa0>
 *   @0x2b00ba mov r0, r4
 *   @0x2b00be ldr r2, [r6, #0x8]
 *   @0x2b00c6 str.w r11, [r3, r7]
 *   @0x2b00ca b 0x2b00e2 <png_write_end+0xb6>
 *   @0x2b00ce bne 0x2b00e2 <png_write_end+0xb6>
 *   @0x2b00d2 ldr r1, [r6, #0x4]
 *   @0x2b00d6 movs r3, #0x0
 *   @0x2b00de str.w r9, [r3, r7]
 *   @0x2b00e2 add.w r8, r8, #0x1
 *   @0x2b00e6 b 0x2b008c <png_write_end+0x60>
 *   @0x2b00ee beq 0x2b004c <png_write_end+0x20>
 *   @0x2b00f6 ldr.w r2, [r5, #0xc0]
 *   @0x2b00fa ldr.w r3, [r5, #0xbc]
 *   @0x2b00fe mla r3, r7, r2, r3
 *   @0x2b0102 cmp r6, r3
 *   @0x2b0106 mov r0, r4
 *   @0x2b010a bl 0x2a5fe4 <png_handle_as_unknown>
 *   @0x2b010e cmp r0, #0x1
 *   @0x2b0112 ldrb r3, [r6, #0x10]
 *   @0x2b0116 lsls r1, r3, #0x1c
 *   @0x2b011a ldrb r3, [r6, #0x3]
 *   @0x2b011e bmi 0x2b012c <png_write_end+0x100>
 *   @0x2b0122 beq 0x2b012c <png_write_end+0x100>
 *   @0x2b012a bpl 0x2b0138 <png_write_end+0x10c>
 *   @0x2b012e mov r1, r6
 *   @0x2b0132 ldr r3, [r6, #0xc]
 *   @0x2b013a b 0x2b00f6 <png_write_end+0xca>
 *   @0x2b013e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b0142 nop
 *   @0x2b0146 movs r5, r1
 *
 * ══ png_convert_from_struct_tm  0x2b0148  size 32  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b014a 0x2b017a  size 48  12 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b014a addw r3, r3, #0x76c
 *   @0x2b014e strh r3, [r0]
 *   @0x2b0152 adds r3, #0x1
 *   @0x2b0156 ldr r3, [r1, #0xc]
 *   @0x2b015a ldr r3, [r1, #0x8]
 *   @0x2b015e ldr r3, [r1, #0x4]
 *   @0x2b0162 ldr r3, [r1]
 *   @0x2b0166 bx lr
 *
 * ══ png_convert_from_time_t  0x2b0168  size 26  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b016a 0x2b0182  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b016a mov r4, r0
 *   @0x2b016e str r1, [r0, #-4]!
 *   @0x2b0172 blx 0xb6f4c <gmtime@plt>
 *   @0x2b0176 mov r1, r0
 *   @0x2b017a bl 0x2b0148 <png_convert_from_struct_tm>
 *   @0x2b017e add sp, #0x8
 *
 * ══ png_create_write_struct_2  0x2b0184  size 480  本节 102 条（Thumb-2 半字段）｜入度 13
 * @func 0x2b0186 0x2b0376  size 496  106 条
 * 部分覆盖: 本节 106/230 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 105/228 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 104/226 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 103/224 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 102/222 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0186 sub sp, #0x84
 *   @0x2b018a ldr r0, [sp, #0x98]
 *   @0x2b018e ldr r3, [sp, #0xa0]
 *   @0x2b0192 ldr r0, [pc, #0x1b4]
 *   @0x2b0196 str r3, [sp, #0x10]
 *   @0x2b019a ldr r2, [sp, #0x9c]
 *   @0x2b019e str r0, [sp, #0x4]
 *   @0x2b01a2 mov r1, r2
 *   @0x2b01a6 ldr r3, [r0, r3]
 *   @0x2b01aa ldr r2, [sp, #0x8]
 *   @0x2b01ae str r3, [sp, #0x7c]
 *   @0x2b01b2 str r3, [sp, #0x24]
 *   @0x2b01ba ldr r0, [sp, #0x28]
 *   @0x2b01be beq.w 0x2b032e <png_create_write_struct_2+0x1aa>
 *   @0x2b01c2 ldr r2, [sp, #0x28]
 *   @0x2b01c6 str.w r3, [r2, #0x308]
 *   @0x2b01ca ldr r2, [sp, #0x28]
 *   @0x2b01ce str.w r3, [r2, #0x30c]
 *   @0x2b01d2 ldr r2, [sp, #0x4]
 *   @0x2b01d6 ldr r1, [r2, r3]
 *   @0x2b01e6 cbz r0, 0x2b01ec <png_create_write_struct_2+0x68>
 *   @0x2b01ee ldr r0, [sp, #0x28]
 *   @0x2b01f2 bl 0x2a6d34 <png_set_mem_fn>
 *   @0x2b01f6 add r1, sp, #0x14
 *   @0x2b01fa ldm r1, {r1, r2, r3}
 *   @0x2b0202 cbnz r3, 0x2b0210 <png_create_write_struct_2+0x8c>
 *   @0x2b0206 ldr.w r3, [r3, #0x130]
 *   @0x2b020a lsls r3, r3, #0xe
 *   @0x2b020e b 0x2b02d2 <png_create_write_struct_2+0x14e>
 *   @0x2b0212 mov.w r3, #0xffffffff
 *   @0x2b0216 movs r6, #0x1
 *   @0x2b021a ldr r0, [sp]
 *   @0x2b021e ldrb r2, [r3, r5]
 *   @0x2b0222 ldrb r1, [r0, r3]
 *   @0x2b0226 beq 0x2b0236 <png_create_write_struct_2+0xb2>
 *   @0x2b022a ldr.w r0, [r1, #0x130]
 *   @0x2b022e orr r0, r0, #0x20000
 *   @0x2b0232 str.w r0, [r1, #0x130]
 *   @0x2b0236 ldr r0, [sp]
 *   @0x2b023a cmp r1, #0x2e
 *   @0x2b023e cmp r4, #0x0
 *   @0x2b0242 mov r4, r6
 *   @0x2b0246 cmp r1, #0x0
 *   @0x2b024a cmp r2, #0x0
 *   @0x2b024e b 0x2b0204 <png_create_write_struct_2+0x80>
 *   @0x2b0252 cbz r2, 0x2b02a6 <png_create_write_struct_2+0x122>
 *   @0x2b0256 ldrb r4, [r2]
 *   @0x2b025e cmp r3, r4
 *   @0x2b0262 ldr r0, [sp]
 *   @0x2b0266 cmp r3, #0x31
 *   @0x2b026a ldr r2, [sp]
 *   @0x2b026e cmp r3, #0x30
 *   @0x2b0272 b 0x2b0286 <png_create_write_struct_2+0x102>
 *   @0x2b0276 movs r0, #0x0
 *   @0x2b027a bl 0x2a5fcc <png_get_header_ver>
 *   @0x2b027e ldrb r3, [r0, #0x2]
 *   @0x2b0282 bne 0x2b028e <png_create_write_struct_2+0x10a>
 *   @0x2b0286 ldr r0, [sp]
 *   @0x2b028a cmp r3, #0x38
 *   @0x2b028e add r4, sp, #0x2c
 *   @0x2b0292 movs r1, #0x50
 *   @0x2b0296 mov r0, r4
 *   @0x2b029a blx 0xb65c8 <snprintf@plt>
 *   @0x2b029e ldr r0, [sp, #0x28]
 *   @0x2b02a2 bl 0x2a6474 <png_warning>
 *   @0x2b02a6 movs r0, #0x0
 *   @0x2b02aa bl 0x2a5fcc <png_get_header_ver>
 *   @0x2b02ae ldr r2, [pc, #0xac]
 *   @0x2b02b2 add r2, pc
 *   @0x2b02b6 mov r0, r4
 *   @0x2b02be mov r1, r4
 *   @0x2b02c6 ldr r0, [sp, #0x28]
 *   @0x2b02ca bl 0x2a6474 <png_warning>
 *   @0x2b02ce movs r3, #0x1
 *   @0x2b02d2 ldr r3, [sp, #0x28]
 *   @0x2b02de cbnz r3, 0x2b02fe <png_create_write_struct_2+0x17a>
 *   @0x2b02e2 ldr r0, [sp, #0x28]
 *   @0x2b02e6 ldr.w r1, [r3, #0x174]
 *   @0x2b02ea bl 0x2a6d16 <png_malloc_warn>
 *   @0x2b02ee ldr r3, [sp, #0x28]
 *   @0x2b02fa movs r3, #0x1
 *   @0x2b02fe ldr r1, [sp, #0x24]
 *   @0x2b0302 cbz r1, 0x2b0324 <png_create_write_struct_2+0x1a0>
 *   @0x2b0306 movs r4, #0x0
 *   @0x2b0312 ldr r1, [sp, #0x10]
 *   @0x2b0316 str.w r4, [r3, #0x170]
 *   @0x2b031a ldr r2, [sp, #0x8]
 *   @0x2b0322 b 0x2b032e <png_create_write_struct_2+0x1aa>
 *   @0x2b0326 mov r3, r1
 *   @0x2b032e ldr r2, [sp, #0x4]
 *   @0x2b0332 ldr r3, [r2, r3]
 *   @0x2b0336 ldr r3, [r3]
 *   @0x2b033a beq 0x2b0340 <png_create_write_struct_2+0x1bc>
 *   @0x2b0342 pop {r4, r5, r6, r7, pc}
 *   @0x2b0346 movs r7, r1
 *   @0x2b034a movs r4, r2
 *   @0x2b034e .word 0xffff e4ac
 *   @0x2b0352 vsra.u32 q14, q4, #0x1
 *   @0x2b0356 movs r5, r1
 *   @0x2b035a movs r5, r1
 *   @0x2b035e movs r5, r1
 *   @0x2b0362 movs r5, r1
 *
 * ══ png_create_write_struct  0x2b0364  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0366 0x2b0376  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0366 movs r4, #0x0
 *   @0x2b036a str r4, [sp, #0x4]
 *   @0x2b036e bl 0x2b0184 <png_create_write_struct_2>
 *   @0x2b0372 add sp, #0x10
 *
 * ══ png_write_row  0x2b0378  size 376  本节 67 条（Thumb-2 半字段）｜入度 13
 * @func 0x2b037a 0x2b0502  size 392  71 条
 * 部分覆盖: 本节 71/169 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 70/167 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 69/165 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 68/163 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 67/161 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b037a mov r5, r1
 *   @0x2b037e cmp r0, #0x0
 *   @0x2b038a ldrb.w r3, [r0, #0x1e8]
 *   @0x2b038e cbnz r3, 0x2b03a6 <png_write_row+0x2e>
 *   @0x2b0396 bmi 0x2b03a0 <png_write_row+0x28>
 *   @0x2b039a add r1, pc
 *   @0x2b03a2 bl 0x2b2510 <png_write_start_row>
 *   @0x2b03a6 ldrb.w r3, [r4, #0x1e7]
 *   @0x2b03aa cmp r3, #0x0
 *   @0x2b03ae ldr.w r3, [r4, #0x134]
 *   @0x2b03b2 lsls r3, r3, #0x1e
 *   @0x2b03b6 ldrb.w r3, [r4, #0x1e8]
 *   @0x2b03ba cmp r3, #0x6
 *   @0x2b03be tbb [pc, r3]
 *   @0x2b03c2 lsrs r4, r0, #0x14
 *   @0x2b03c6 cmp r2, #0x23
 *   @0x2b03ca ldr.w r3, [r4, #0x1a8]
 *   @0x2b03ce lsls r0, r3, #0x1d
 *   @0x2b03d2 mov r0, r4
 *   @0x2b03e2 bne 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b03ea b 0x2b0424 <png_write_row+0xac>
 *   @0x2b03f6 b 0x2b0412 <png_write_row+0x9a>
 *   @0x2b03fe bne 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b0406 b 0x2b0424 <png_write_row+0xac>
 *   @0x2b0412 beq 0x2b0430 <png_write_row+0xb8>
 *   @0x2b0416 ldr.w r3, [r4, #0x1a8]
 *   @0x2b041a lsls r3, r3, #0x1f
 *   @0x2b041e ldr.w r3, [r4, #0x18c]
 *   @0x2b0422 cmp r3, #0x1
 *   @0x2b0426 b 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b042e bpl 0x2b03d2 <png_write_row+0x5a>
 *   @0x2b0452 uxtb r3, r3
 *   @0x2b045a bls 0x2b0462 <png_write_row+0xea>
 *   @0x2b045e muls r2, r3, r2
 *   @0x2b0462 muls r2, r3, r2
 *   @0x2b0466 lsrs r2, r2, #0x3
 *   @0x2b046e str.w r2, [r4, #0x1c8]
 *   @0x2b0472 add.w r5, r4, #0x1c4
 *   @0x2b0476 adds r0, #0x1
 *   @0x2b0482 ldrb.w r2, [r4, #0x1e8]
 *   @0x2b0486 cmp r2, #0x5
 *   @0x2b048a ldr.w r3, [r4, #0x134]
 *   @0x2b048e lsls r1, r3, #0x1e
 *   @0x2b0492 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0496 mov r0, r5
 *   @0x2b049a bl 0x2b279c <png_do_write_interlace>
 *   @0x2b049e ldr.w r3, [r4, #0x1c4]
 *   @0x2b04a2 cmp r3, #0x0
 *   @0x2b04a6 ldr.w r3, [r4, #0x134]
 *   @0x2b04aa cbz r3, 0x2b04b2 <png_write_row+0x13a>
 *   @0x2b04ae bl 0x2b0dbc <png_do_write_transformations>
 *   @0x2b04b2 ldr.w r3, [r4, #0x2dc]
 *   @0x2b04b6 lsls r3, r3, #0x1d
 *   @0x2b04ba ldrb.w r3, [r4, #0x2e4]
 *   @0x2b04be cmp r3, #0x40
 *   @0x2b04c2 ldr.w r1, [r4, #0x1b0]
 *   @0x2b04c6 mov r0, r5
 *   @0x2b04ca bl 0x2b0eb6 <png_do_write_intrapixel>
 *   @0x2b04ce mov r0, r4
 *   @0x2b04d2 bl 0x2b29d8 <png_write_find_filter>
 *   @0x2b04d6 ldr.w r3, [r4, #0x260]
 *   @0x2b04da cbz r3, 0x2b04e8 <png_write_row+0x170>
 *   @0x2b04de ldr.w r1, [r4, #0x1a8]
 *   @0x2b04e2 ldrb.w r2, [r4, #0x1e8]
 *   @0x2b04e6 blx r3
 *   @0x2b04ea nop
 *   @0x2b04ee movs r5, r1
 *
 * ══ png_write_rows  0x2b04f0  size 32  本节 7 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b04f2 0x2b0512  size 32  7 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b04f2 mov r6, r1
 *   @0x2b04f6 mov r5, r0
 *   @0x2b04fa movs r4, #0x0
 *   @0x2b04fe beq 0x2b050e <png_write_rows+0x1e>
 *   @0x2b0506 bl 0x2b0378 <png_write_row>
 *   @0x2b050a adds r4, #0x1
 *   @0x2b050e pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ png_write_image  0x2b0510  size 54  本节 10 条（Thumb-2 半字段）｜入度 3
 * @func 0x2b0516 0x2b0546  size 48  10 条
 * 部分覆盖: 本节 10/22 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0516 mov r6, r0
 *   @0x2b051a bl 0x2af7b2 <png_set_interlace_handling>
 *   @0x2b051e movs r5, #0x0
 *   @0x2b0522 cmp r5, r8
 *   @0x2b0526 movs r4, #0x0
 *   @0x2b052e bhs 0x2b053e <png_write_image+0x2e>
 *   @0x2b0536 bl 0x2b0378 <png_write_row>
 *   @0x2b053a adds r4, #0x1
 *   @0x2b053e adds r5, #0x1
 *   @0x2b0542 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ png_set_flush  0x2b0546  size 12  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0548 0x2b055e  size 22  6 条
 * 部分覆盖: 本节 4/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0548 bic.w r1, r1, r1, asr #31
 *   @0x2b054c str.w r1, [r0, #0x214]
 *   @0x2b0550 bx lr
 *
 * ══ anon_2b0552  0x2b0552  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0552 0x2b055e  size 12  3 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0552 ldrblt r0, [r0, #-0x0]!
 *
 * ══ png_write_flush  0x2b0554  size 148  本节 25 条（Thumb-2 半字段）｜入度 3
 * @func 0x2b0556 0x2b05ea  size 148  25 条
 * 部分覆盖: 本节 25/62 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0556 mov r4, r0
 *   @0x2b055a beq 0x2b05e2 <png_write_flush+0x8e>
 *   @0x2b0566 bhs 0x2b05e2 <png_write_flush+0x8e>
 *   @0x2b056a add.w r5, r0, #0x138
 *   @0x2b056e add r6, pc
 *   @0x2b0572 movs r1, #0x2
 *   @0x2b057a ldr.w r1, [r4, #0x150]
 *   @0x2b057e mov r0, r4
 *   @0x2b0582 mov r1, r6
 *   @0x2b058e mov r0, r4
 *   @0x2b05ae ldr.w r2, [r4, #0x174]
 *   @0x2b05b2 cmp r2, r3
 *   @0x2b05b6 subs r2, r2, r3
 *   @0x2b05ba ldr.w r1, [r4, #0x170]
 *   @0x2b05be bl 0x2b16a0 <png_write_IDAT>
 *   @0x2b05c2 ldr.w r3, [r4, #0x170]
 *   @0x2b05c6 str.w r3, [r4, #0x144]
 *   @0x2b05ca ldr.w r3, [r4, #0x174]
 *   @0x2b05ce str.w r3, [r4, #0x148]
 *   @0x2b05d2 movs r3, #0x0
 *   @0x2b05d6 str.w r3, [r4, #0x218]
 *   @0x2b05da pop.w {r4, r5, r6, lr}
 *   @0x2b05de b.w 0x2afc0c <png_flush>
 *   @0x2b05e2 pop {r4, r5, r6, pc}
 *   @0x2b05e6 movs r5, r1
 *
 * ══ png_write_destroy  0x2b05e8  size 170  本节 28 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b05ee 0x2b0692  size 164  28 条
 * 部分覆盖: 本节 28/69 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b05ee sub sp, #0x100
 *   @0x2b05fa ldr.w r1, [r4, #0x170]
 *   @0x2b05fe mov.w r5, #0x100
 *   @0x2b0602 bl 0x2a6cfc <png_free>
 *   @0x2b0606 mov r0, r4
 *   @0x2b0612 ldr.w r1, [r4, #0x1ac]
 *   @0x2b0616 bl 0x2a6cfc <png_free>
 *   @0x2b061a mov r0, r4
 *   @0x2b0626 ldr.w r1, [r4, #0x1b8]
 *   @0x2b062a bl 0x2a6cfc <png_free>
 *   @0x2b062e mov r0, r4
 *   @0x2b063a ldr.w r1, [r4, #0x1c0]
 *   @0x2b063e bl 0x2a6cfc <png_free>
 *   @0x2b0642 mov r0, r4
 *   @0x2b064e mov r2, r5
 *   @0x2b0652 blx 0xb65bc <memcpy@plt>
 *   @0x2b0656 ldr.w r10, [r4, #0x104]
 *   @0x2b065a ldr.w r9, [r4, #0x108]
 *   @0x2b065e mov r0, r4
 *   @0x2b0666 ldr.w r7, [r4, #0x2f0]
 *   @0x2b066a mov.w r2, #0x338
 *   @0x2b066e blx 0xb65b0 <memset@plt>
 *   @0x2b0672 str.w r10, [r4, #0x104]
 *   @0x2b0676 str.w r9, [r4, #0x108]
 *   @0x2b067a mov r0, r4
 *   @0x2b0682 str.w r7, [r4, #0x2f0]
 *   @0x2b0686 mov r2, r5
 *   @0x2b068e pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ png_destroy_write_struct  0x2b0692  size 126  本节 24 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0698 0x2b0710  size 120  24 条
 * 部分覆盖: 本节 24/54 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0698 mov r5, r0
 *   @0x2b069c ldr r4, [r0]
 *   @0x2b06a8 mov r4, r0
 *   @0x2b06ac mov r7, r0
 *   @0x2b06b4 ldr.w r9, [r8]
 *   @0x2b06b8 cmp.w r9, #0x0
 *   @0x2b06bc beq 0x2b06f6 <png_destroy_write_struct+0x64>
 *   @0x2b06c0 mov.w r3, #0xffffffff
 *   @0x2b06c4 mov r0, r4
 *   @0x2b06c8 movw r2, #0x7fff
 *   @0x2b06cc bl 0x2a5bc0 <png_free_data>
 *   @0x2b06d0 ldr.w r3, [r4, #0x2cc]
 *   @0x2b06d4 cbz r3, 0x2b06e6 <png_destroy_write_struct+0x54>
 *   @0x2b06d8 ldr.w r1, [r4, #0x2d0]
 *   @0x2b06dc bl 0x2a6cfc <png_free>
 *   @0x2b06e0 movs r3, #0x0
 *   @0x2b06e8 mov r1, r7
 *   @0x2b06ec bl 0x2a6c5e <png_destroy_struct_2>
 *   @0x2b06f0 movs r3, #0x0
 *   @0x2b06f8 mov r0, r4
 *   @0x2b0700 mov r1, r7
 *   @0x2b0704 bl 0x2a6c5e <png_destroy_struct_2>
 *   @0x2b0708 movs r3, #0x0
 *   @0x2b070c pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ png_set_filter  0x2b0710  size 372  本节 73 条（Thumb-2 半字段）｜入度 10
 * @func 0x2b0712 0x2b0898  size 390  78 条
 * 部分覆盖: 本节 78/175 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 77/173 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 76/171 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 75/169 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 74/167 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0712 mov r4, r0
 *   @0x2b0716 beq.w 0x2b086c <png_set_filter+0x15c>
 *   @0x2b071a ldr.w r3, [r0, #0x2dc]
 *   @0x2b071e lsls r0, r3, #0x1d
 *   @0x2b0722 cmp r1, #0x40
 *   @0x2b0726 cmp r1, #0x0
 *   @0x2b072e cmp r3, #0x7
 *   @0x2b0732 tbb [pc, r3]
 *   @0x2b0736 lsrs r4, r0, #0x10
 *   @0x2b073a lsls r4, r2, #0x18
 *   @0x2b073e movs r3, #0x8
 *   @0x2b0742 ldr r1, [pc, #0x12c]
 *   @0x2b0746 add r1, pc
 *   @0x2b074e movs r3, #0x10
 *   @0x2b0756 movs r3, #0x20
 *   @0x2b075a movs r3, #0x40
 *   @0x2b075e movs r3, #0x80
 *   @0x2b0762 strb.w r2, [r4, #0x1e9]
 *   @0x2b0766 ldr.w r3, [r4, #0x1b0]
 *   @0x2b076a cmp r3, #0x0
 *   @0x2b076e ldrb.w r3, [r4, #0x1e9]
 *   @0x2b0772 lsls r1, r3, #0x1b
 *   @0x2b0776 ldr.w r3, [r4, #0x1b4]
 *   @0x2b077a cbnz r3, 0x2b0790 <png_set_filter+0x80>
 *   @0x2b0782 adds r1, #0x1
 *   @0x2b078a str.w r0, [r4, #0x1b4]
 *   @0x2b078e strb r3, [r0]
 *   @0x2b0796 bpl 0x2b07d0 <png_set_filter+0xc0>
 *   @0x2b079e ldr.w r3, [r4, #0x1ac]
 *   @0x2b07a2 cbnz r3, 0x2b07bc <png_set_filter+0xac>
 *   @0x2b07a6 mov r0, r4
 *   @0x2b07aa bl 0x2a6474 <png_warning>
 *   @0x2b07ae ldrb.w r3, [r4, #0x1e9]
 *   @0x2b07b2 bic r3, r3, #0x20
 *   @0x2b07b6 strb.w r3, [r4, #0x1e9]
 *   @0x2b07ba b 0x2b07d0 <png_set_filter+0xc0>
 *   @0x2b07c2 adds r1, #0x1
 *   @0x2b07ca str.w r0, [r4, #0x1b8]
 *   @0x2b07ce strb r3, [r0]
 *   @0x2b07d6 bpl 0x2b0810 <png_set_filter+0x100>
 *   @0x2b07de ldr.w r3, [r4, #0x1ac]
 *   @0x2b07e2 cbnz r3, 0x2b07fc <png_set_filter+0xec>
 *   @0x2b07e6 mov r0, r4
 *   @0x2b07ea bl 0x2a6474 <png_warning>
 *   @0x2b07ee ldrb.w r3, [r4, #0x1e9]
 *   @0x2b07f2 bic r3, r3, #0x40
 *   @0x2b07f6 strb.w r3, [r4, #0x1e9]
 *   @0x2b07fa b 0x2b0810 <png_set_filter+0x100>
 *   @0x2b0802 adds r1, #0x1
 *   @0x2b080a str.w r0, [r4, #0x1bc]
 *   @0x2b080e strb r3, [r0]
 *   @0x2b0816 bge 0x2b0850 <png_set_filter+0x140>
 *   @0x2b081e ldr.w r3, [r4, #0x1ac]
 *   @0x2b0822 cbnz r3, 0x2b083c <png_set_filter+0x12c>
 *   @0x2b0826 mov r0, r4
 *   @0x2b082a bl 0x2a6474 <png_warning>
 *   @0x2b082e ldrb.w r3, [r4, #0x1e9]
 *   @0x2b0832 and r3, r3, #0x7f
 *   @0x2b0836 strb.w r3, [r4, #0x1e9]
 *   @0x2b083a b 0x2b0850 <png_set_filter+0x140>
 *   @0x2b0842 adds r1, #0x1
 *   @0x2b084a str.w r0, [r4, #0x1c0]
 *   @0x2b084e strb r3, [r0]
 *   @0x2b0856 movs r3, #0x8
 *   @0x2b085e ldr r1, [pc, #0x20]
 *   @0x2b0862 pop.w {r4, lr}
 *   @0x2b0866 add r1, pc
 *   @0x2b086e nop
 *   @0x2b0872 movs r5, r1
 *   @0x2b0876 movs r5, r1
 *   @0x2b087a movs r5, r1
 *   @0x2b087e movs r5, r1
 *   @0x2b0882 movs r5, r1
 *
 * ══ png_set_filter_heuristics  0x2b0884  size 2  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0884 0x2b0898  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0884 bx lr
 *
 * ══ png_set_compression_level  0x2b0886  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0888 0x2b08ac  size 36  9 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0888 ldr.w r3, [r0, #0x130]
 *   @0x2b088c str.w r1, [r0, #0x178]
 *   @0x2b0890 orr r3, r3, #0x2
 *   @0x2b0894 str.w r3, [r0, #0x130]
 *   @0x2b0898 bx lr
 *
 * ══ png_set_compression_mem_level  0x2b089a  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b089c 0x2b08c0  size 36  9 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b089c ldr.w r3, [r0, #0x130]
 *   @0x2b08a0 str.w r1, [r0, #0x184]
 *   @0x2b08a4 orr r3, r3, #0x4
 *   @0x2b08a8 str.w r3, [r0, #0x130]
 *   @0x2b08ac bx lr
 *
 * ══ png_set_compression_strategy  0x2b08ae  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b08b0 0x2b08d6  size 38  10 条
 * 部分覆盖: 本节 9/17 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 8/15 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/13 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 6/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b08b0 ldr.w r3, [r0, #0x130]
 *   @0x2b08b4 str.w r1, [r0, #0x188]
 *   @0x2b08b8 orr r3, r3, #0x1
 *   @0x2b08bc str.w r3, [r0, #0x130]
 *   @0x2b08c0 bx lr
 *
 * ══ anon_2b08c2  0x2b08c2  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b08c2 0x2b08d6  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b08c2 ldrlt r0, [r8, #-0x0]!
 *
 * ══ png_set_compression_window_bits  0x2b08c4  size 76  本节 19 条（Thumb-2 半字段）｜入度 4
 * @func 0x2b08c6 0x2b0922  size 92  23 条
 * 部分覆盖: 本节 23/46 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 22/44 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/42 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 20/40 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 19/38 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b08c6 mov r4, r1
 *   @0x2b08ca cbz r0, 0x2b0902 <png_set_compression_window_bits+0x3e>
 *   @0x2b08ce ble 0x2b08d6 <png_set_compression_window_bits+0x12>
 *   @0x2b08d2 add r1, pc
 *   @0x2b08d6 cmp r1, #0x7
 *   @0x2b08da ldr r1, [pc, #0x2c]
 *   @0x2b08de bl 0x2a6474 <png_warning>
 *   @0x2b08e2 b 0x2b08f2 <png_set_compression_window_bits+0x2e>
 *   @0x2b08e6 bne 0x2b08f2 <png_set_compression_window_bits+0x2e>
 *   @0x2b08ea movs r4, #0x9
 *   @0x2b08ee bl 0x2a6474 <png_warning>
 *   @0x2b08f2 ldr.w r3, [r5, #0x130]
 *   @0x2b08f6 str.w r4, [r5, #0x180]
 *   @0x2b08fa orr r3, r3, #0x8
 *   @0x2b08fe str.w r3, [r5, #0x130]
 *   @0x2b0902 pop {r3, r4, r5, pc}
 *   @0x2b0906 movs r5, r1
 *   @0x2b090a movs r5, r1
 *   @0x2b090e movs r5, r1
 *
 * ══ png_set_compression_method  0x2b0910  size 44  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0912 0x2b094e  size 60  10 条
 * 部分覆盖: 本节 10/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/23 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 7/19 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 6/17 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0912 mov r5, r1
 *   @0x2b0916 cbz r0, 0x2b0934 <png_set_compression_method+0x24>
 *   @0x2b091a beq 0x2b0924 <png_set_compression_method+0x14>
 *   @0x2b091e add r1, pc
 *   @0x2b0936 nop
 *   @0x2b093a movs r5, r1
 *
 * ══ png_set_write_status_fn  0x2b093c  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b093e 0x2b0956  size 24  6 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b093e str.w r1, [r0, #0x260]
 *   @0x2b0942 bx lr
 *
 * ══ png_set_write_user_transform_fn  0x2b0944  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b0946 0x2b096a  size 36  9 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0946 ldr.w r3, [r0, #0x134]
 *   @0x2b094a str.w r1, [r0, #0x120]
 *   @0x2b094e orr r3, r3, #0x100000
 *   @0x2b0952 str.w r3, [r0, #0x134]
 *   @0x2b0956 bx lr
 *
 * ══ png_write_png  0x2b0958  size 166  本节 32 条（Thumb-2 半字段）｜入度 6
 * @func 0x2b095a 0x2b09f6  size 156  32 条
 * 部分覆盖: 本节 32/71 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b095a mov r6, r1
 *   @0x2b095e mov r4, r0
 *   @0x2b0962 beq 0x2b09fc <png_write_png+0xa4>
 *   @0x2b0966 beq 0x2b09fc <png_write_png+0xa4>
 *   @0x2b096e bpl 0x2b0976 <png_write_png+0x1e>
 *   @0x2b0972 bl 0x2af84a <png_set_invert_mono>
 *   @0x2b0976 lsls r2, r5, #0x19
 *   @0x2b097a ldr r3, [r6, #0x8]
 *   @0x2b097e bpl 0x2b098a <png_write_png+0x32>
 *   @0x2b0982 add.w r1, r6, #0x44
 *   @0x2b0986 bl 0x2af796 <png_set_shift>
 *   @0x2b098a lsls r0, r5, #0x1d
 *   @0x2b098e mov r0, r4
 *   @0x2b0996 bpl 0x2b099e <png_write_png+0x46>
 *   @0x2b099a bl 0x2af82a <png_set_swap_alpha>
 *   @0x2b099e ands r1, r5, #0x1000
 *   @0x2b09a2 beq 0x2b09ac <png_write_png+0x54>
 *   @0x2b09a6 movs r1, #0x0
 *   @0x2b09aa b 0x2b09b4 <png_write_png+0x5c>
 *   @0x2b09ae bpl 0x2b09b8 <png_write_png+0x60>
 *   @0x2b09b2 mov r2, r1
 *   @0x2b09ba bpl 0x2b09c2 <png_write_png+0x6a>
 *   @0x2b09be bl 0x2af738 <png_set_bgr>
 *   @0x2b09c2 lsls r0, r5, #0x16
 *   @0x2b09c6 mov r0, r4
 *   @0x2b09ce bpl 0x2b09d6 <png_write_png+0x7e>
 *   @0x2b09d2 bl 0x2af77e <png_set_packswap>
 *   @0x2b09d6 lsls r2, r5, #0x15
 *   @0x2b09da mov r0, r4
 *   @0x2b09e2 lsls r3, r3, #0x10
 *   @0x2b09e6 mov r0, r4
 *   @0x2b09f2 mov r1, r6
 *
 * ══ png_do_pack  0x2b09fe  size 214  本节 42 条（Thumb-2 半字段）｜入度 8
 * @func 0x2b0a00 0x2b0ad4  size 212  42 条
 * 部分覆盖: 本节 42/95 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0a00 push {r4, r5, r6, r7, lr}
 *   @0x2b0a10 cmp r2, #0x2
 *   @0x2b0a14 beq 0x2b0a4e <png_do_pack+0x50>
 *   @0x2b0a18 beq 0x2b0a80 <png_do_pack+0x82>
 *   @0x2b0a1c bne 0x2b0ab4 <png_do_pack+0xb6>
 *   @0x2b0a20 mov r7, r1
 *   @0x2b0a24 movs r3, #0x80
 *   @0x2b0a28 beq 0x2b0a4a <png_do_pack+0x4c>
 *   @0x2b0a34 orrs r4, r3
 *   @0x2b0a38 add.w r5, r5, #0x1
 *   @0x2b0a3c itett le
 *   @0x2b0a44 movle r4, #0x0
 *   @0x2b0a48 b 0x2b0a26 <png_do_pack+0x28>
 *   @0x2b0a4c b 0x2b0ab0 <png_do_pack+0xb2>
 *   @0x2b0a50 mov r7, r1
 *   @0x2b0a54 movs r3, #0x6
 *   @0x2b0a58 beq 0x2b0a7c <png_do_pack+0x7e>
 *   @0x2b0a6c strb r4, [r7], #1
 *   @0x2b0a70 mov r4, r3
 *   @0x2b0a74 b 0x2b0a78 <png_do_pack+0x7a>
 *   @0x2b0a78 adds r5, #0x1
 *   @0x2b0a7c cmp r3, #0x6
 *   @0x2b0a80 movs r5, #0x0
 *   @0x2b0a84 mov r4, r5
 *   @0x2b0a88 cmp r5, r6
 *   @0x2b0a8c ldrb.w r12, [r1, r5]
 *   @0x2b0a90 and r12, r12, #0xf
 *   @0x2b0a94 lsl.w r12, r12, r3
 *   @0x2b0a98 orr.w r4, r4, r12
 *   @0x2b0a9c cbnz r3, 0x2b0aa8 <png_do_pack+0xaa>
 *   @0x2b0aa4 movs r3, #0x4
 *   @0x2b0aa8 subs r3, #0x4
 *   @0x2b0aac b 0x2b0a88 <png_do_pack+0x8a>
 *   @0x2b0ab0 it ne
 *   @0x2b0ab4 ldrb r3, [r0, #0xa]
 *   @0x2b0ab8 muls r2, r3, r2
 *   @0x2b0abc uxtb r2, r2
 *   @0x2b0ac0 cmp r2, #0x7
 *   @0x2b0ac4 lsrs r2, r2, #0x3
 *   @0x2b0ac8 b 0x2b0ad0 <png_do_pack+0xd2>
 *   @0x2b0acc adds r2, #0x7
 *   @0x2b0ad0 str r2, [r0, #0x4]
 *
 * ══ png_do_shift  0x2b0ad4  size 388  本节 77 条（Thumb-2 半字段）｜入度 16
 * @func 0x2b0ada 0x2b0c56  size 380  77 条
 * 部分覆盖: 本节 77/172 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0ada ldrb r5, [r0, #0x8]
 *   @0x2b0ade beq.w 0x2b0c52 <png_do_shift+0x17e>
 *   @0x2b0ae2 tst.w r5, #0x2
 *   @0x2b0ae6 ldrb r3, [r0, #0x9]
 *   @0x2b0aea ldrb r4, [r2]
 *   @0x2b0aee str r6, [sp]
 *   @0x2b0af2 ldrb r4, [r2, #0x1]
 *   @0x2b0af6 str r6, [sp, #0x4]
 *   @0x2b0afa ldrb r4, [r2, #0x2]
 *   @0x2b0afe str r6, [sp, #0x8]
 *   @0x2b0b02 movs r4, #0x3
 *   @0x2b0b06 ldrb r4, [r2, #0x3]
 *   @0x2b0b0a str r6, [sp]
 *   @0x2b0b0e movs r4, #0x1
 *   @0x2b0b12 bpl 0x2b0b28 <png_do_shift+0x54>
 *   @0x2b0b16 add r7, sp, #0x20
 *   @0x2b0b1e subs r7, r3, r6
 *   @0x2b0b2a bhi 0x2b0b96 <png_do_shift+0xc2>
 *   @0x2b0b2e ldr r4, [r0, #0x4]
 *   @0x2b0b32 bne 0x2b0b3e <png_do_shift+0x6a>
 *   @0x2b0b36 ite eq
 *   @0x2b0b3a movne r3, #0xff
 *   @0x2b0b3e cmp r3, #0x4
 *   @0x2b0b42 cmp r2, #0x3
 *   @0x2b0b46 moveq r3, #0x11
 *   @0x2b0b4a b 0x2b0b4e <png_do_shift+0x7a>
 *   @0x2b0b4e ldr r5, [sp]
 *   @0x2b0b56 mov.w r9, #0x0
 *   @0x2b0b5a rsb.w r10, r5, #0x0
 *   @0x2b0b5e rsb.w r8, r0, #0x0
 *   @0x2b0b62 cmp r1, r12
 *   @0x2b0b66 mov r4, r10
 *   @0x2b0b6a ldrb r6, [r1]
 *   @0x2b0b72 ble 0x2b0b62 <png_do_shift+0x8e>
 *   @0x2b0b76 ldrb r7, [r1, #-1]
 *   @0x2b0b7a itet le
 *   @0x2b0b8a orr.w r7, r11, r7
 *   @0x2b0b8e add r4, r0
 *   @0x2b0b96 cmp r3, #0x8
 *   @0x2b0b9a mul r8, r3, r4
 *   @0x2b0b9e bne 0x2b0bf2 <png_do_shift+0x11e>
 *   @0x2b0ba2 mov r5, r1
 *   @0x2b0ba6 cmp r6, r8
 *   @0x2b0baa mov r0, r6
 *   @0x2b0bae blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b0bb2 add r3, sp, #0x20
 *   @0x2b0bb6 strb r9, [r5], #1
 *   @0x2b0bba add.w r1, r3, r1, lsl #2
 *   @0x2b0bbe ldr r3, [r1, #-32]
 *   @0x2b0bc2 ldr r1, [r1, #-16]
 *   @0x2b0bc6 rsbs r2, r3, #0
 *   @0x2b0bce ble 0x2b0bee <png_do_shift+0x11a>
 *   @0x2b0bd2 ldrb r7, [r5, #-1]
 *   @0x2b0bd6 ite gt
 *   @0x2b0be6 strb r7, [r5, #-1]
 *   @0x2b0bea add r2, r1
 *   @0x2b0bee adds r6, #0x1
 *   @0x2b0bf2 adds r5, r1, #0x2
 *   @0x2b0bf6 cmp r6, r8
 *   @0x2b0bfa mov r0, r6
 *   @0x2b0bfe blx 0x318cf0 <__aeabi_uidivmod>
 *   @0x2b0c02 ldrb r7, [r5, #-2]
 *   @0x2b0c06 ldrb r3, [r5, #-1]
 *   @0x2b0c0a add.w r7, r3, r7, lsl #8
 *   @0x2b0c0e add r3, sp, #0x20
 *   @0x2b0c12 add.w r1, r3, r1, lsl #2
 *   @0x2b0c16 movs r3, #0x0
 *   @0x2b0c26 cmp r2, r12
 *   @0x2b0c2a cmp r2, #0x0
 *   @0x2b0c2e lslgt.w r9, r7, r2
 *   @0x2b0c32 asrle.w r9, r7, r1
 *   @0x2b0c36 orr.w r3, r3, r9
 *   @0x2b0c3a subs r2, r2, r0
 *   @0x2b0c3e uxth r3, r3
 *   @0x2b0c42 lsrs r2, r3, #0x8
 *   @0x2b0c4e adds r5, #0x2
 *   @0x2b0c52 add sp, #0x24
 *
 * ══ png_do_write_swap_alpha  0x2b0c58  size 218  本节 33 条（Thumb-2 半字段）｜入度 4
 * @func 0x2b0c5a 0x2b0d32  size 216  33 条
 * 部分覆盖: 本节 33/87 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0c5a ldrb r3, [r0, #0x8]
 *   @0x2b0c5e bne 0x2b0cdc <png_do_write_swap_alpha+0x84>
 *   @0x2b0c62 ldr r2, [r0]
 *   @0x2b0c66 mov.w r3, #0x0
 *   @0x2b0c6a bne 0x2b0c94 <png_do_write_swap_alpha+0x3c>
 *   @0x2b0c6e beq 0x2b0c92 <png_do_write_swap_alpha+0x3a>
 *   @0x2b0c72 adds r3, #0x1
 *   @0x2b0c76 adds r1, #0x4
 *   @0x2b0c92 pop {r4, r5, pc}
 *   @0x2b0c96 beq 0x2b0cda <png_do_write_swap_alpha+0x82>
 *   @0x2b0c9a adds r3, #0x1
 *   @0x2b0c9e adds r1, #0x8
 *   @0x2b0cda pop {r4, r5, pc}
 *   @0x2b0cde bne 0x2b0d30 <png_do_write_swap_alpha+0xd8>
 *   @0x2b0ce2 ldr r2, [r0]
 *   @0x2b0ce6 mov.w r3, #0x0
 *   @0x2b0cea bne 0x2b0d0a <png_do_write_swap_alpha+0xb2>
 *   @0x2b0cee add.w r1, r1, #0x2
 *   @0x2b0cf2 beq 0x2b0d08 <png_do_write_swap_alpha+0xb0>
 *   @0x2b0cfa ldrb r4, [r1, #-1]
 *   @0x2b0cfe strb r0, [r1, #-1]
 *   @0x2b0d02 strb r4, [r1, #-2]
 *   @0x2b0d06 b 0x2b0cec <png_do_write_swap_alpha+0x94>
 *   @0x2b0d0a cmp r3, r2
 *   @0x2b0d0e ldrb r5, [r1, #0x2]
 *   @0x2b0d12 ldrb r4, [r1]
 *   @0x2b0d16 ldrb r0, [r1, #-3]
 *   @0x2b0d1a strb r5, [r1, #-4]
 *   @0x2b0d1e ldrb r5, [r1, #-1]
 *   @0x2b0d22 strb r4, [r1, #-2]
 *   @0x2b0d26 strb r0, [r1, #-1]
 *   @0x2b0d2a strb r5, [r1, #-3]
 *   @0x2b0d2e b 0x2b0d0a <png_do_write_swap_alpha+0xb2>
 *
 * ══ png_do_write_invert_alpha  0x2b0d32  size 138  本节 28 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b0d34 0x2b0dbc  size 136  28 条
 * 部分覆盖: 本节 28/62 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0d34 cmp r3, #0x6
 *   @0x2b0d38 ldrb r3, [r0, #0x9]
 *   @0x2b0d3c cmp r3, #0x8
 *   @0x2b0d44 cmp r3, r2
 *   @0x2b0d48 ldrb r0, [r1, #0x3]
 *   @0x2b0d4c adds r1, #0x4
 *   @0x2b0d50 strb r0, [r1, #-1]
 *   @0x2b0d54 b 0x2b0d44 <png_do_write_invert_alpha+0x12>
 *   @0x2b0d58 cmp r3, r2
 *   @0x2b0d5c ldrb r0, [r1, #0x6]
 *   @0x2b0d60 adds r1, #0x8
 *   @0x2b0d64 strb r0, [r1, #-2]
 *   @0x2b0d68 ldrb r0, [r1, #-1]
 *   @0x2b0d6c mvns r0, r0
 *   @0x2b0d74 bx lr
 *   @0x2b0d78 bne 0x2b0dba <png_do_write_invert_alpha+0x88>
 *   @0x2b0d7c ldr r2, [r0]
 *   @0x2b0d80 mov.w r3, #0x0
 *   @0x2b0d84 bne 0x2b0d9e <png_do_write_invert_alpha+0x6c>
 *   @0x2b0d88 add.w r1, r1, #0x2
 *   @0x2b0d8c beq 0x2b0d9c <png_do_write_invert_alpha+0x6a>
 *   @0x2b0d94 mvns r0, r0
 *   @0x2b0d9c bx lr
 *   @0x2b0da0 beq 0x2b0dba <png_do_write_invert_alpha+0x88>
 *   @0x2b0da4 adds r3, #0x1
 *   @0x2b0da8 mvns r0, r0
 *   @0x2b0db4 strb r0, [r1, #-1]
 *   @0x2b0db8 b 0x2b0d9e <png_do_write_invert_alpha+0x6c>
 *
 * ══ png_do_write_transformations  0x2b0dbc  size 250  本节 43 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b0dbe 0x2b0eb2  size 244  43 条
 * 部分覆盖: 本节 43/104 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0dbe mov r4, r0
 *   @0x2b0dc2 beq 0x2b0eb4 <png_do_write_transformations+0xf8>
 *   @0x2b0dca bpl 0x2b0dde <png_do_write_transformations+0x22>
 *   @0x2b0dd2 ldr.w r2, [r0, #0x1b0]
 *   @0x2b0dd6 add.w r1, r0, #0x1c4
 *   @0x2b0dda adds r2, #0x1
 *   @0x2b0dde ldr.w r3, [r4, #0x134]
 *   @0x2b0de2 lsls r3, r3, #0x10
 *   @0x2b0de6 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0dea add.w r0, r4, #0x1c4
 *   @0x2b0dee ldr.w r2, [r4, #0x130]
 *   @0x2b0df2 adds r1, #0x1
 *   @0x2b0dfe bpl 0x2b0e0e <png_do_write_transformations+0x52>
 *   @0x2b0e0a bl 0x2af8e4 <png_do_packswap>
 *   @0x2b0e0e ldr.w r3, [r4, #0x134]
 *   @0x2b0e12 lsls r1, r3, #0x1d
 *   @0x2b0e16 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e1a add.w r0, r4, #0x1c4
 *   @0x2b0e1e ldrb.w r2, [r4, #0x1eb]
 *   @0x2b0e22 adds r1, #0x1
 *   @0x2b0e2e bpl 0x2b0e3e <png_do_write_transformations+0x82>
 *   @0x2b0e3a bl 0x2af8b6 <png_do_swap>
 *   @0x2b0e3e ldr.w r3, [r4, #0x134]
 *   @0x2b0e42 lsls r3, r3, #0x1c
 *   @0x2b0e46 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e4a add.w r0, r4, #0x1c4
 *   @0x2b0e4e addw r2, r4, #0x245
 *   @0x2b0e52 adds r1, #0x1
 *   @0x2b0e5e bpl 0x2b0e6e <png_do_write_transformations+0xb2>
 *   @0x2b0e6a bl 0x2b0c58 <png_do_write_swap_alpha>
 *   @0x2b0e6e ldr.w r3, [r4, #0x134]
 *   @0x2b0e72 lsls r1, r3, #0xc
 *   @0x2b0e76 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0e7a add.w r0, r4, #0x1c4
 *   @0x2b0e7e adds r1, #0x1
 *   @0x2b0e8a bpl 0x2b0e9a <png_do_write_transformations+0xde>
 *   @0x2b0e96 bl 0x2afae8 <png_do_bgr>
 *   @0x2b0e9a ldr.w r3, [r4, #0x134]
 *   @0x2b0e9e lsls r3, r3, #0x1a
 *   @0x2b0ea2 ldr.w r1, [r4, #0x1b0]
 *   @0x2b0ea6 add.w r0, r4, #0x1c4
 *   @0x2b0eaa pop.w {r4, lr}
 *   @0x2b0eae adds r1, #0x1
 *
 * ══ png_do_write_intrapixel  0x2b0eb6  size 134  本节 33 条（Thumb-2 半字段）｜入度 4
 * @func 0x2b0eb8 0x2b0f3c  size 132  33 条
 * 部分覆盖: 本节 33/66 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b0eb8 ldrb r3, [r0, #0x8]
 *   @0x2b0ebc bpl 0x2b0f3a <png_do_write_intrapixel+0x84>
 *   @0x2b0ec0 ldrb r0, [r0, #0x9]
 *   @0x2b0ec4 bne 0x2b0ef0 <png_do_write_intrapixel+0x3a>
 *   @0x2b0ec8 beq 0x2b0ed2 <png_do_write_intrapixel+0x1c>
 *   @0x2b0ecc bne 0x2b0f3a <png_do_write_intrapixel+0x84>
 *   @0x2b0ed0 b 0x2b0ed4 <png_do_write_intrapixel+0x1e>
 *   @0x2b0ed4 movs r3, #0x0
 *   @0x2b0ed8 beq 0x2b0eee <png_do_write_intrapixel+0x38>
 *   @0x2b0edc adds r3, #0x1
 *   @0x2b0ee0 subs r5, r5, r4
 *   @0x2b0ee4 ldrb r5, [r1, #0x2]
 *   @0x2b0ee8 strb r4, [r1, #0x2]
 *   @0x2b0eec b 0x2b0ed6 <png_do_write_intrapixel+0x20>
 *   @0x2b0ef0 cmp r0, #0x10
 *   @0x2b0ef4 cmp r3, #0x2
 *   @0x2b0ef8 cmp r3, #0x6
 *   @0x2b0efc movs r0, #0x8
 *   @0x2b0f00 movs r0, #0x6
 *   @0x2b0f04 cmp r3, r2
 *   @0x2b0f08 ldrb r6, [r1, #0x2]
 *   @0x2b0f0c ldrb r4, [r1, #0x3]
 *   @0x2b0f10 orr.w r6, r4, r6, lsl #8
 *   @0x2b0f14 ldrb r4, [r1, #0x1]
 *   @0x2b0f18 orr.w r5, r4, r5, lsl #8
 *   @0x2b0f1c ldrb r4, [r1, #0x5]
 *   @0x2b0f20 orr.w r4, r4, r7, lsl #8
 *   @0x2b0f24 subs r4, r4, r6
 *   @0x2b0f28 strb r5, [r1, #0x1]
 *   @0x2b0f2c lsrs r6, r5, #0x8
 *   @0x2b0f30 strb r6, [r1]
 *   @0x2b0f34 strb r5, [r1, #0x4]
 *   @0x2b0f38 b 0x2b0f04 <png_do_write_intrapixel+0x4e>
 *
 * ══ anon_2b0f3e  0x2b0f3e  size 484  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1122 0x2b1136  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1122 cdpeq p0, #0x0, c0, c11, c13, #0x0
 *
 * ══ png_save_uint_32  0x2b1124  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1126 0x2b1136  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1126 strb r1, [r0, #0x3]
 *   @0x2b112a lsrs r3, r1, #0x10
 *   @0x2b112e lsrs r3, r1, #0x8
 *   @0x2b1132 bx lr
 *
 * ══ png_save_uint_16  0x2b1138  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b113a 0x2b1152  size 24  6 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b113a strb r1, [r0, #0x1]
 *   @0x2b113e bx lr
 *
 * ══ png_write_sig  0x2b1140  size 96  本节 16 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1142 0x2b119e  size 92  16 条
 * 部分覆盖: 本节 16/39 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1142 sub sp, #0x14
 *   @0x2b1146 mov r4, r0
 *   @0x2b114a add r5, pc
 *   @0x2b114e add r2, pc
 *   @0x2b1152 ldr r0, [r2]
 *   @0x2b1156 str r3, [sp, #0xc]
 *   @0x2b115a ldrb.w r2, [r4, #0x1f0]
 *   @0x2b115e stm r3!, {r0, r1}
 *   @0x2b1162 movs r3, #0x12
 *   @0x2b1166 str.w r3, [r4, #0x334]
 *   @0x2b116a mov r0, r4
 *   @0x2b117a bhi 0x2b1188 <png_write_sig+0x48>
 *   @0x2b118a ldr r3, [r5]
 *   @0x2b118e beq 0x2b1194 <png_write_sig+0x54>
 *   @0x2b1196 pop {r4, r5, pc}
 *   @0x2b119a movs r3, r2
 *
 * ══ png_write_chunk_start  0x2b11a0  size 100  本节 19 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b11a2 0x2b1216  size 116  23 条
 * 部分覆盖: 本节 21/48 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 20/46 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 19/44 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b11a2 push {r4, r5, r6, r7, lr}
 *   @0x2b11a6 ldr r3, [r3]
 *   @0x2b11aa sub sp, #0x14
 *   @0x2b11ae mov r4, r0
 *   @0x2b11b2 str r1, [sp, #0xc]
 *   @0x2b11b6 add r6, sp, #0x4
 *   @0x2b11ba mov r1, r2
 *   @0x2b11c2 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b11c6 ldr r0, [r5]
 *   @0x2b11ca movs r2, #0x8
 *   @0x2b11ce mov r0, r4
 *   @0x2b11d6 mov r0, r4
 *   @0x2b11e2 mov r1, r5
 *   @0x2b11e6 bl 0x2a5b08 <png_calculate_crc>
 *   @0x2b11ea movs r3, #0x42
 *   @0x2b11f2 ldr r3, [r7]
 *   @0x2b11f6 beq 0x2b11fc <png_write_chunk_start+0x5c>
 *   @0x2b11fe pop {r4, r5, r6, r7, pc}
 *   @0x2b1202 movs r3, r2
 *
 * ══ png_write_chunk_data  0x2b1204  size 34  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1206 0x2b121e  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1206 mov r5, r1
 *   @0x2b120a mov r6, r0
 *   @0x2b120e cbz r1, 0x2b1224 <png_write_chunk_data+0x20>
 *   @0x2b1212 bl 0x2afbf0 <png_write_data>
 *   @0x2b1216 mov r0, r6
 *   @0x2b121a mov r2, r4
 *
 * ══ anon_2b1228  0x2b1228  size 108  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1294 0x2b12a8  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1294 ldrlt r11, [r7, #-0xfb7]!
 *
 * ══ png_write_chunk_end  0x2b1296  size 38  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1298 0x2b12bc  size 36  7 条
 * 部分覆盖: 本节 7/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1298 mov r4, r0
 *   @0x2b129c add r5, sp, #0x4
 *   @0x2b12a0 str.w r3, [r0, #0x334]
 *   @0x2b12a4 mov r0, r5
 *   @0x2b12b0 mov r1, r5
 *   @0x2b12b4 bl 0x2afbf0 <png_write_data>
 *   @0x2b12b8 add sp, #0xc
 *
 * ══ png_write_chunk  0x2b12bc  size 38  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b12be 0x2b12da  size 28  6 条
 * 部分覆盖: 本节 6/13 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b12be mov r6, r2
 *   @0x2b12c2 mov r4, r0
 *   @0x2b12c6 mov r2, r3
 *   @0x2b12ce mov r1, r6
 *   @0x2b12d2 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b12d6 mov r0, r4
 *
 * ══ png_write_IHDR  0x2b12e4  size 748  本节 145 条（Thumb-2 半字段）｜入度 17
 * @func 0x2b12ea 0x2b15e2  size 760  149 条
 * 部分覆盖: 本节 149/339 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 148/337 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 147/335 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 146/333 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 145/331 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b12ea ldr r3, [pc, #0x29c]
 *   @0x2b12ee sub sp, #0x3c
 *   @0x2b12f2 add r3, pc
 *   @0x2b12f6 mov r6, r1
 *   @0x2b12fe ldr r7, [sp, #0x68]
 *   @0x2b1306 ldr r2, [pc, #0x284]
 *   @0x2b130a add r2, pc
 *   @0x2b1312 str r0, [sp, #0x1c]
 *   @0x2b131a cmp.w r8, #0x6
 *   @0x2b131e bhi 0x2b13a6 <png_write_IHDR+0xc2>
 *   @0x2b1326 subs r0, r2, r4
 *   @0x2b132a movs r4, r6
 *   @0x2b132e cmp r3, #0xf
 *   @0x2b1332 lsls r2, r3
 *   @0x2b133a cbnz r3, 0x2b136a <png_write_IHDR+0x86>
 *   @0x2b133e mov r0, r4
 *   @0x2b1342 b 0x2b13ac <png_write_IHDR+0xc8>
 *   @0x2b1346 beq 0x2b1356 <png_write_IHDR+0x72>
 *   @0x2b134a beq 0x2b1356 <png_write_IHDR+0x72>
 *   @0x2b134e mov r0, r4
 *   @0x2b1352 bl 0x2a642c <png_error>
 *   @0x2b1356 movs r3, #0x3
 *   @0x2b135a subs r3, r5, #0x1
 *   @0x2b135e bhi 0x2b136e <png_write_IHDR+0x8a>
 *   @0x2b136a movs r3, #0x1
 *   @0x2b136e ldr r1, [pc, #0x228]
 *   @0x2b1372 add r1, pc
 *   @0x2b1376 cmp r5, #0x8
 *   @0x2b137a cmp r5, #0x10
 *   @0x2b137e ldr r1, [pc, #0x21c]
 *   @0x2b1382 add r1, pc
 *   @0x2b138a b 0x2b13a0 <png_write_IHDR+0xbc>
 *   @0x2b138e beq 0x2b139e <png_write_IHDR+0xba>
 *   @0x2b1392 beq 0x2b139e <png_write_IHDR+0xba>
 *   @0x2b1396 mov r0, r4
 *   @0x2b139a bl 0x2a642c <png_error>
 *   @0x2b139e movs r3, #0x4
 *   @0x2b13a6 ldr r1, [pc, #0x1fc]
 *   @0x2b13aa add r1, pc
 *   @0x2b13b2 cbz r3, 0x2b13be <png_write_IHDR+0xda>
 *   @0x2b13b6 mov r0, r4
 *   @0x2b13ba bl 0x2a6474 <png_warning>
 *   @0x2b13be ldr.w r3, [r4, #0x2dc]
 *   @0x2b13c2 lsls r2, r3, #0x1d
 *   @0x2b13c6 ldr.w r3, [r4, #0x12c]
 *   @0x2b13ca lsls r3, r3, #0x13
 *   @0x2b13ce bic r3, r8, #0x4
 *   @0x2b13d2 cmp r3, #0x2
 *   @0x2b13d6 cmp r7, #0x40
 *   @0x2b13da cbz r7, 0x2b13e8 <png_write_IHDR+0x104>
 *   @0x2b13de mov r0, r4
 *   @0x2b13e2 add r1, pc
 *   @0x2b13ee ldr r1, [pc, #0x1c0]
 *   @0x2b13f2 mov.w r10, #0x1
 *   @0x2b13f6 add r1, pc
 *   @0x2b13fe strb.w r2, [r4, #0x304]
 *   @0x2b1402 ldrb.w r2, [r4, #0x1ee]
 *   @0x2b1406 uxtb.w r9, r5
 *   @0x2b140a uxtb.w r8, r8
 *   @0x2b140e uxtb.w r10, r10
 *   @0x2b1412 uxtb r7, r7
 *   @0x2b141a strb.w r8, [r4, #0x1ea]
 *   @0x2b141e strb.w r10, [r4, #0x1e7]
 *   @0x2b1422 strb.w r7, [r4, #0x2e4]
 *   @0x2b1426 str.w r6, [r4, #0x18c]
 *   @0x2b142a str.w r11, [r4, #0x190]
 *   @0x2b142e uxtb r5, r5
 *   @0x2b1436 bls 0x2b143e <png_write_IHDR+0x15a>
 *   @0x2b143a muls r5, r6, r5
 *   @0x2b143e muls r5, r6, r5
 *   @0x2b1442 lsrs r5, r5, #0x3
 *   @0x2b144a strb.w r2, [r4, #0x1ef]
 *   @0x2b144e mov r1, r6
 *   @0x2b1452 str.w r6, [r4, #0x198]
 *   @0x2b1456 strb.w r9, [r4, #0x1ec]
 *   @0x2b145a bl 0x2b1124 <png_save_uint_32>
 *   @0x2b145e adds r0, r5, #0x4
 *   @0x2b1462 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1466 movs r3, #0x0
 *   @0x2b146a strb.w r3, [sp, #0x2e]
 *   @0x2b146e add r1, sp, #0x1c
 *   @0x2b1472 mov r2, r5
 *   @0x2b148a str.w r4, [r4, #0x160]
 *   @0x2b148e add r3, pc
 *   @0x2b1492 str.w r3, [r4, #0x158]
 *   @0x2b1496 ldr r3, [pc, #0x120]
 *   @0x2b149a ldr r3, [r3]
 *   @0x2b14a6 ldrb.w r3, [r4, #0x1ea]
 *   @0x2b14aa cmp r3, #0x3
 *   @0x2b14ae ldrb.w r3, [r4, #0x1eb]
 *   @0x2b14b2 cmp r3, #0x7
 *   @0x2b14b6 movs r3, #0x8
 *   @0x2b14ba movs r3, #0xf8
 *   @0x2b14ca ldrb.w r1, [r4, #0x1e9]
 *   @0x2b14ce cmp r1, #0x8
 *   @0x2b14d2 movne r2, #0x1
 *   @0x2b14da itt pl
 *   @0x2b14e6 itt pl
 *   @0x2b14ea strpl.w r2, [r4, #0x184]
 *   @0x2b14ee lsls r0, r3, #0x1c
 *   @0x2b14f6 movpl r2, #0xf
 *   @0x2b14fe add.w r1, r4, #0x178
 *   @0x2b1502 itt pl
 *   @0x2b1506 strpl.w r3, [r4, #0x17c]
 *   @0x2b150a ldr.w r3, [r4, #0x184]
 *   @0x2b150e str r3, [sp]
 *   @0x2b1516 ldr r3, [pc, #0xa4]
 *   @0x2b151a str r3, [sp, #0x8]
 *   @0x2b151e str r3, [sp, #0xc]
 *   @0x2b1522 blx 0xb6eb0 <deflateInit2_@plt>
 *   @0x2b1526 cbz r0, 0x2b1558 <png_write_IHDR+0x274>
 *   @0x2b152a bne 0x2b1534 <png_write_IHDR+0x250>
 *   @0x2b152e mov r0, r4
 *   @0x2b1532 b 0x2b154a <png_write_IHDR+0x266>
 *   @0x2b1536 bne 0x2b1540 <png_write_IHDR+0x25c>
 *   @0x2b153a mov r0, r4
 *   @0x2b153e b 0x2b154a <png_write_IHDR+0x266>
 *   @0x2b1542 bne 0x2b154e <png_write_IHDR+0x26a>
 *   @0x2b1546 mov r0, r4
 *   @0x2b154a bl 0x2a642c <png_error>
 *   @0x2b154e ldr r1, [pc, #0x7c]
 *   @0x2b1552 add r1, pc
 *   @0x2b155e ldr r2, [sp, #0x34]
 *   @0x2b156e str.w r3, [r4, #0x164]
 *   @0x2b1572 movs r3, #0x1
 *   @0x2b157a cmp r2, r3
 *   @0x2b157e blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b1582 add sp, #0x3c
 *   @0x2b158a movs r3, r2
 *   @0x2b1592 movs r5, r1
 *   @0x2b1596 movs r5, r1
 *   @0x2b159a movs r5, r1
 *   @0x2b159e movs r5, r1
 *   @0x2b15a2 movs r5, r1
 *   @0x2b15a6 movs r5, r1
 *   @0x2b15aa movs r5, r1
 *   @0x2b15ae movs r5, r1
 *   @0x2b15b2 movs r5, r1
 *   @0x2b15b6 movs r4, r2
 *   @0x2b15ba movs r4, r2
 *   @0x2b15be movs r5, r1
 *   @0x2b15c2 movs r5, r1
 *   @0x2b15c6 movs r5, r1
 *   @0x2b15ca movs r5, r1
 *   @0x2b15ce movs r5, r1
 *
 * ══ png_write_PLTE  0x2b15d0  size 208  本节 35 条（Thumb-2 半字段）｜入度 4
 * @func 0x2b15d2 0x2b16a2  size 208  35 条
 * 部分覆盖: 本节 35/87 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b15d2 push {r4, r5, r6, r7, lr}
 *   @0x2b15d6 mov r4, r0
 *   @0x2b15da ldr r0, [r3, #13]!
 *   @0x2b15de mov r6, r2
 *   @0x2b15e2 ldrb r3, [r3, #0x4]
 *   @0x2b15e6 strb.w r3, [sp, #0xc]
 *   @0x2b15ea ldrb.w r3, [r4, #0x1ea]
 *   @0x2b15ee cmp r3, #0x3
 *   @0x2b15f2 ldrbeq.w r2, [r4, #0x1eb]
 *   @0x2b15f6 moveq r1, #0x1
 *   @0x2b1606 bmi 0x2b160a <png_write_PLTE+0x3a>
 *   @0x2b160a cmp r6, r2
 *   @0x2b160e cmp r3, #0x3
 *   @0x2b1612 bne 0x2b161e <png_write_PLTE+0x4e>
 *   @0x2b1616 add r1, pc
 *   @0x2b161e ldr r1, [pc, #0x78]
 *   @0x2b1622 b 0x2b1632 <png_write_PLTE+0x62>
 *   @0x2b162a bmi 0x2b1638 <png_write_PLTE+0x68>
 *   @0x2b162e mov r0, r4
 *   @0x2b1632 bl 0x2a6474 <png_warning>
 *   @0x2b1636 b 0x2b168c <png_write_PLTE+0xbc>
 *   @0x2b163a strh.w r6, [r4, #0x1dc]
 *   @0x2b163e muls r6, r3, r6
 *   @0x2b1642 add r1, sp, #0x8
 *   @0x2b1646 add r7, sp, #0x4
 *   @0x2b164a add r6, r5
 *   @0x2b1652 beq 0x2b167a <png_write_PLTE+0xaa>
 *   @0x2b165a mov r1, r7
 *   @0x2b165e adds r5, #0x3
 *   @0x2b167a mov r0, r4
 *   @0x2b168e pop {r4, r5, r6, r7, pc}
 *   @0x2b1692 movs r5, r1
 *   @0x2b1696 movs r5, r1
 *   @0x2b169a movs r5, r1
 *   @0x2b169e movs r5, r1
 *
 * ══ png_write_IDAT  0x2b16a0  size 236  本节 44 条（Thumb-2 半字段）｜入度 10
 * @func 0x2b16a6 0x2b179a  size 244  47 条
 * 部分覆盖: 本节 47/108 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 46/106 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 45/104 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 44/102 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b16a6 ldr r1, [pc, #0xdc]
 *   @0x2b16aa mov r8, r2
 *   @0x2b16ae ldr r0, [r1, #18]!
 *   @0x2b16b2 ldrb r3, [r1, #0x4]
 *   @0x2b16b6 strb.w r3, [sp, #0x4]
 *   @0x2b16ba ldr.w r3, [r4, #0x12c]
 *   @0x2b16be lsls r3, r3, #0x1d
 *   @0x2b16c2 ldrb.w r3, [r4, #0x304]
 *   @0x2b16c6 cmp r3, #0x0
 *   @0x2b16ca ldrb r6, [r5]
 *   @0x2b16d2 bne 0x2b175c <png_write_IDAT+0xbc>
 *   @0x2b16da bhi 0x2b175c <png_write_IDAT+0xbc>
 *   @0x2b16de bls 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b16ea bhi 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b16f2 bhi 0x2b1766 <png_write_IDAT+0xc6>
 *   @0x2b1702 ldrb.w r1, [r4, #0x1e7]
 *   @0x2b1706 adds r7, #0xf
 *   @0x2b170a muls r7, r3, r7
 *   @0x2b170e adds r3, #0x7
 *   @0x2b1712 ite hi
 *   @0x2b1716 movls r2, #0xc
 *   @0x2b171a mla r7, r3, r2, r7
 *   @0x2b171e lsrs r1, r6, #0x4
 *   @0x2b1722 adds r3, r1, #0x7
 *   @0x2b1726 cmp r7, r0
 *   @0x2b172a lsls r1, r1, #0x4
 *   @0x2b1732 cmp r6, r3
 *   @0x2b1736 strb r3, [r5]
 *   @0x2b173a ldrb r3, [r5, #0x1]
 *   @0x2b174e strb r1, [r5, #0x1]
 *   @0x2b1752 cmp r0, #0xff
 *   @0x2b1756 subs r1, #0x1
 *   @0x2b175a b 0x2b1726 <png_write_IDAT+0x86>
 *   @0x2b175e mov r0, r4
 *   @0x2b1762 bl 0x2a642c <png_error>
 *   @0x2b1766 mov r3, r8
 *   @0x2b176a mov r1, sp
 *   @0x2b176e bl 0x2b12bc <png_write_chunk>
 *   @0x2b1772 ldr.w r3, [r4, #0x12c]
 *   @0x2b1776 orr r3, r3, #0x4
 *   @0x2b177a str.w r3, [r4, #0x12c]
 *   @0x2b177e add sp, #0x8
 *   @0x2b1786 movs r5, r1
 *   @0x2b178a movs r5, r1
 *
 * ══ png_write_IEND  0x2b178c  size 52  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b178e 0x2b17c2  size 52  8 条
 * 部分覆盖: 本节 8/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b178e movs r2, #0x0
 *   @0x2b1792 add r3, pc
 *   @0x2b1796 mov r1, sp
 *   @0x2b179e str r0, [sp]
 *   @0x2b17a2 strb.w r3, [sp, #0x4]
 *   @0x2b17a6 mov r3, r2
 *   @0x2b17ba pop {r4, pc}
 *   @0x2b17be movs r5, r1
 *
 * ══ png_write_gAMA  0x2b17c0  size 84  本节 18 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b17ce 0x2b1818  size 74  19 条
 * 部分覆盖: 本节 19/36 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b17ce push {r4, r5, lr}
 *   @0x2b17d2 mov r5, r0
 *   @0x2b17d6 ldr r0, [r1, #28]!
 *   @0x2b17da add r4, sp, #0x4
 *   @0x2b17de str r0, [sp, #0x8]
 *   @0x2b17e2 vmla.f64 d7, d5, d6
 *   @0x2b17e6 strb.w r1, [sp, #0xc]
 *   @0x2b17ea vcvt.u32.f64 s11, d7
 *   @0x2b17ee vmov r1, s11
 *   @0x2b17f2 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b17f6 mov r0, r5
 *   @0x2b17fa mov r2, r4
 *   @0x2b17fe bl 0x2b12bc <png_write_chunk>
 *   @0x2b1802 add sp, #0x14
 *   @0x2b1806 nop
 *   @0x2b180a movs r0, r0
 *   @0x2b180e lsrs r0, r7
 *   @0x2b1812 movs r5, r1
 *
 * ══ anon_2b1814  0x2b1814  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1814 0x2b1818  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1814 andhi pc, r0, pc, lsr #7
 *
 * ══ png_write_gAMA_fixed  0x2b1818  size 52  本节 13 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b181a 0x2b185a  size 64  16 条
 * 部分覆盖: 本节 14/28 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 13/26 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b181a push {r4, r5, lr}
 *   @0x2b181e mov r5, r0
 *   @0x2b1822 ldr r0, [r3, #28]!
 *   @0x2b1826 add r4, sp, #0x4
 *   @0x2b182a str r0, [sp, #0x8]
 *   @0x2b182e strb.w r3, [sp, #0xc]
 *   @0x2b1832 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1836 mov r0, r5
 *   @0x2b183a mov r2, r4
 *   @0x2b183e bl 0x2b12bc <png_write_chunk>
 *   @0x2b1842 add sp, #0x14
 *   @0x2b1846 nop
 *   @0x2b184a movs r5, r1
 *
 * ══ png_write_sRGB  0x2b184c  size 68  本节 16 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b184e 0x2b1892  size 68  16 条
 * 部分覆盖: 本节 16/33 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b184e cmp r1, #0x3
 *   @0x2b1852 add r3, pc
 *   @0x2b1856 sub sp, #0x14
 *   @0x2b185e ldrb r3, [r3, #0x4]
 *   @0x2b1862 strb.w r3, [sp, #0xc]
 *   @0x2b1866 ble 0x2b1872 <png_write_sRGB+0x26>
 *   @0x2b186a mov r0, r4
 *   @0x2b186e bl 0x2a6474 <png_warning>
 *   @0x2b1872 mov r0, r4
 *   @0x2b1876 add r2, sp, #0x4
 *   @0x2b187a strb.w r5, [sp, #0x4]
 *   @0x2b187e bl 0x2b12bc <png_write_chunk>
 *   @0x2b1882 add sp, #0x14
 *   @0x2b1886 nop
 *   @0x2b188a movs r5, r1
 *   @0x2b188e movs r5, r1
 *
 * ══ png_write_iCCP  0x2b1890  size 252  本节 51 条（Thumb-2 半字段）｜入度 2
 * @func 0x2b1896 0x2b199e  size 264  55 条
 * 部分覆盖: 本节 55/121 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 54/119 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 52/115 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 51/113 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1896 ldr r3, [pc, #0xe0]
 *   @0x2b189a sub sp, #0x28
 *   @0x2b189e add r3, pc
 *   @0x2b18a2 ldr r5, [sp, #0x40]
 *   @0x2b18aa str r0, [sp, #0xc]
 *   @0x2b18ae strb.w r3, [sp, #0x10]
 *   @0x2b18b2 movs r3, #0x0
 *   @0x2b18b6 str r3, [sp, #0x20]
 *   @0x2b18ba str r3, [sp, #0x14]
 *   @0x2b18be bl 0x2af5b0 <png_check_keyword>
 *   @0x2b18c2 mov r7, r0
 *   @0x2b18c6 beq 0x2b1970 <png_write_iCCP+0xe0>
 *   @0x2b18ce ldr r1, [pc, #0xac]
 *   @0x2b18d2 add r1, pc
 *   @0x2b18da cmp r5, #0x3
 *   @0x2b18de ldrb.w r8, [r6, #0x1]
 *   @0x2b18e2 ldrb r3, [r6]
 *   @0x2b18ee orr.w r8, r8, r3
 *   @0x2b18f2 ldrb r3, [r6, #0x2]
 *   @0x2b18fa ldr r1, [pc, #0x84]
 *   @0x2b18fe add r1, pc
 *   @0x2b1902 mov r5, r6
 *   @0x2b190a bge 0x2b1918 <png_write_iCCP+0x88>
 *   @0x2b190e mov r0, r4
 *   @0x2b1912 bl 0x2a6474 <png_warning>
 *   @0x2b1916 b 0x2b1968 <png_write_iCCP+0xd8>
 *   @0x2b191a ldr r1, [pc, #0x6c]
 *   @0x2b191e mov r5, r8
 *   @0x2b1922 bl 0x2a6474 <png_warning>
 *   @0x2b1926 cbz r5, 0x2b193a <png_write_iCCP+0xaa>
 *   @0x2b192a mov r2, r5
 *   @0x2b192e mov r0, r4
 *   @0x2b1932 movs r3, #0x0
 *   @0x2b193a adds r6, r7, #0x2
 *   @0x2b193e add r1, sp, #0xc
 *   @0x2b1942 bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b1946 ldr r3, [sp, #0x8]
 *   @0x2b194a mov r2, r6
 *   @0x2b194e movs r3, #0x0
 *   @0x2b1952 ldr r1, [sp, #0x8]
 *   @0x2b195a mov r0, r4
 *   @0x2b195e bl 0x2b1226 <png_write_chunk_data+0x22>
 *   @0x2b1962 mov r0, r4
 *   @0x2b196a ldr r1, [sp, #0x8]
 *   @0x2b1972 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2b1976 nop
 *   @0x2b197a movs r5, r1
 *   @0x2b197e movs r5, r1
 *   @0x2b1982 movs r5, r1
 *   @0x2b1986 movs r5, r1
 *   @0x2b198a movs r5, r1
 *
 * ══ png_write_sPLT  0x2b198c  size 288  本节 53 条（Thumb-2 半字段）｜入度 3
 * @func 0x2b198e 0x2b1ab6  size 296  55 条
 * 部分覆盖: 本节 55/129 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 54/127 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 53/125 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b198e push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b1992 add r3, pc
 *   @0x2b1996 sub sp, #0x24
 *   @0x2b199a ldr r2, [r3]
 *   @0x2b199e ldrb.w r8, [r1, #0x4]
 *   @0x2b19a2 mov r9, r3
 *   @0x2b19a6 str r2, [sp, #0x1c]
 *   @0x2b19ae movne.w r8, #0xa
 *   @0x2b19b2 moveq.w r8, #0x6
 *   @0x2b19b6 ldr r2, [pc, #0xf0]
 *   @0x2b19ba add r2, pc
 *   @0x2b19c2 str r0, [sp, #0x8]
 *   @0x2b19c6 strb.w r2, [sp, #0xc]
 *   @0x2b19ca add r2, sp, #0x4
 *   @0x2b19d2 cmp r0, #0x0
 *   @0x2b19d6 adds r2, r0, #0x2
 *   @0x2b19da mov r0, r6
 *   @0x2b19ea mov r0, r6
 *   @0x2b19ee bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b19f2 mov r0, r6
 *   @0x2b19f6 movs r2, #0x1
 *   @0x2b19fe add r7, sp, #0x10
 *   @0x2b1a02 add.w r11, r7, #0x2
 *   @0x2b1a06 ldr r2, [r5, #0xc]
 *   @0x2b1a0e mla r3, r10, r2, r3
 *   @0x2b1a12 cmp r1, r3
 *   @0x2b1a16 ldrb r3, [r5, #0x4]
 *   @0x2b1a1a bne 0x2b1a40 <png_write_sPLT+0xb4>
 *   @0x2b1a22 strb.w r3, [sp, #0x10]
 *   @0x2b1a26 ldrh r3, [r4, #-8]
 *   @0x2b1a2a strb.w r3, [sp, #0x11]
 *   @0x2b1a2e ldrh r3, [r4, #-6]
 *   @0x2b1a32 strb.w r3, [sp, #0x12]
 *   @0x2b1a36 ldrh r3, [r4, #-4]
 *   @0x2b1a3a strb.w r3, [sp, #0x13]
 *   @0x2b1a3e b 0x2b1a6c <png_write_sPLT+0xe0>
 *   @0x2b1a42 ldrh r1, [r4, #-10]
 *   @0x2b1a46 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1a4a mov r0, r11
 *   @0x2b1a56 ldrh r1, [r4, #-6]
 *   @0x2b1a5a bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1a5e adds r0, r7, #0x6
 *   @0x2b1a72 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1a76 mov r0, r6
 *   @0x2b1a7a mov r2, r8
 *   @0x2b1a82 mov r0, r6
 *   @0x2b1a8a ldr r1, [sp, #0x4]
 *   @0x2b1a92 ldr.w r3, [r9]
 *   @0x2b1a96 cmp r2, r3
 *   @0x2b1a9a blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b1a9e add sp, #0x24
 *   @0x2b1aa6 movs r3, r2
 *   @0x2b1aaa movs r5, r1
 *
 * ══ png_write_sBIT  0x2b1aac  size 160  本节 32 条（Thumb-2 半字段）｜入度 12
 * @func 0x2b1aae 0x2b1b50  size 162  33 条
 * 部分覆盖: 本节 33/72 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1aae mov r4, r0
 *   @0x2b1ab2 add r3, pc
 *   @0x2b1aba str r0, [sp, #0x8]
 *   @0x2b1abe strb.w r3, [sp, #0xc]
 *   @0x2b1ac2 bpl 0x2b1b06 <png_write_sBIT+0x5a>
 *   @0x2b1ac6 ldrb r6, [r1]
 *   @0x2b1aca ldrbne.w r3, [r4, #0x1ec]
 *   @0x2b1ace moveq r3, #0x8
 *   @0x2b1ad2 ldr r1, [pc, #0x74]
 *   @0x2b1ad6 add r1, pc
 *   @0x2b1ade cmp r6, r3
 *   @0x2b1ae2 ldrb r5, [r1, #0x1]
 *   @0x2b1ae6 beq 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1aea bhi 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1aee cmp r0, #0x0
 *   @0x2b1af2 cmp r0, r3
 *   @0x2b1af6 strb.w r6, [sp, #0x4]
 *   @0x2b1afa movs r3, #0x3
 *   @0x2b1b06 ldrb r3, [r1, #0x3]
 *   @0x2b1b0a beq 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1b12 blo 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1b1a lsls r2, r2, #0x1d
 *   @0x2b1b1e ldrb r2, [r1, #0x4]
 *   @0x2b1b22 beq 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1b2a blo 0x2b1ad2 <png_write_sBIT+0x26>
 *   @0x2b1b2e add r1, r3
 *   @0x2b1b32 strb r2, [r1, #-12]
 *   @0x2b1b36 mov r0, r4
 *   @0x2b1b3a add r2, sp, #0x4
 *   @0x2b1b42 pop {r4, r5, r6, pc}
 *   @0x2b1b46 movs r5, r1
 *   @0x2b1b4a movs r5, r1
 *
 * ══ anon_2b1b4c  0x2b1b4c  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b1b4c 0x2b1b50  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1b4c andeq r0, r0, r0
 *
 * ══ png_write_cHRM  0x2b1b50  size 368  本节 55 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b1b66 0x2b1cc2  size 348  55 条
 * 部分覆盖: 本节 55/142 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1b66 ldr.w r8, [pc, #0x150]
 *   @0x2b1b6a mov r9, r0
 *   @0x2b1b6e ldr.w r8, [r8]
 *   @0x2b1b72 ldr.w r1, [r8]
 *   @0x2b1b76 mov r11, r8
 *   @0x2b1b7e ldr r1, [pc, #0x13c]
 *   @0x2b1b86 ldr r0, [r1, #53]!
 *   @0x2b1b8a ldrb r1, [r1, #0x4]
 *   @0x2b1b8e mov r0, r9
 *   @0x2b1bae vcvt.u32.f64 s9, d4
 *   @0x2b1bb2 vmov r5, s9
 *   @0x2b1bb6 vmov.f64 d4, d7
 *   @0x2b1bba vmla.f64 d4, d5, d6
 *   @0x2b1bbe vldr d5, [sp, #144]
 *   @0x2b1bc2 mov r2, r5
 *   @0x2b1bda vcvt.u32.f64 s9, d4
 *   @0x2b1bde vmov r7, s9
 *   @0x2b1be2 vmov.f64 d4, d7
 *   @0x2b1be6 vmla.f64 d4, d5, d6
 *   @0x2b1bea vldr d5, [sp, #160]
 *   @0x2b1bee vcvt.u32.f64 s9, d4
 *   @0x2b1bf2 vmov r10, s9
 *   @0x2b1bf6 vmov.f64 d4, d7
 *   @0x2b1bfa vmla.f64 d4, d5, d6
 *   @0x2b1bfe vldr d5, [sp, #168]
 *   @0x2b1c02 stm.w sp, {r7, r10}
 *   @0x2b1c06 vcvt.u32.f64 s18, d4
 *   @0x2b1c0a vmov.f64 d4, d7
 *   @0x2b1c0e vstr s18, [sp, #8]
 *   @0x2b1c12 vmla.f64 d4, d5, d6
 *   @0x2b1c16 vldr d5, [sp, #176]
 *   @0x2b1c1a vmla.f64 d7, d5, d6
 *   @0x2b1c1e vcvt.u32.f64 s17, d4
 *   @0x2b1c22 vcvt.u32.f64 s16, d7
 *   @0x2b1c26 vstr s17, [sp, #12]
 *   @0x2b1c2a vstr s16, [sp, #16]
 *   @0x2b1c2e bl 0x2a6068 <png_check_cHRM_fixed>
 *   @0x2b1c32 cbz r0, 0x2b1c98 <png_write_cHRM+0x148>
 *   @0x2b1c3a mov r0, r8
 *   @0x2b1c46 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c4a add.w r0, r8, #0x8
 *   @0x2b1c4e mov r1, r6
 *   @0x2b1c5a bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1c5e add.w r0, r8, #0x10
 *   @0x2b1c62 mov r1, r10
 *   @0x2b1c8e add r1, sp, #0x1c
 *   @0x2b1c92 movs r3, #0x20
 *   @0x2b1c9a ldr.w r3, [r11]
 *   @0x2b1c9e cmp r2, r3
 *   @0x2b1ca2 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b1ca6 add sp, #0x4c
 *   @0x2b1cb2 movs r0, r0
 *   @0x2b1cb6 lsrs r0, r7
 *   @0x2b1cba movs r3, r2
 *   @0x2b1cbe movs r5, r1
 *
 * ══ png_write_cHRM_fixed  0x2b1cc0  size 192  本节 34 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b1cc6 0x2b1d92  size 204  38 条
 * 部分覆盖: 本节 38/89 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 37/87 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 36/85 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 35/83 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 34/81 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1cc6 ldr r4, [pc, #0xb0]
 *   @0x2b1cca ldr.w lr, [pc, #0xb0]
 *   @0x2b1cce mov r8, r1
 *   @0x2b1cd2 ldr r4, [r4]
 *   @0x2b1cd6 add lr, pc
 *   @0x2b1cda ldr r0, [r4]
 *   @0x2b1cde mov r10, r3
 *   @0x2b1ce2 str r6, [sp, #0x8]
 *   @0x2b1ce6 ldr r0, [lr, #53]!
 *   @0x2b1cea str r0, [sp, #0x1c]
 *   @0x2b1cf6 stm.w sp, {r0, r7}
 *   @0x2b1cfa ldr r0, [sp, #0x7c]
 *   @0x2b1cfe ldr r0, [sp, #0x80]
 *   @0x2b1d02 mov r0, r5
 *   @0x2b1d0a add r4, sp, #0x24
 *   @0x2b1d0e mov r0, r4
 *   @0x2b1d16 mov r1, r11
 *   @0x2b1d22 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d26 add.w r0, r4, #0xc
 *   @0x2b1d2a ldr r1, [sp, #0x70]
 *   @0x2b1d36 bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d3a add.w r0, r4, #0x14
 *   @0x2b1d3e mov r1, r6
 *   @0x2b1d4a bl 0x2b1124 <png_save_uint_32>
 *   @0x2b1d4e add.w r0, r4, #0x1c
 *   @0x2b1d52 ldr r1, [sp, #0x80]
 *   @0x2b1d5a add r1, sp, #0x1c
 *   @0x2b1d5e movs r3, #0x20
 *   @0x2b1d66 ldr.w r3, [r9]
 *   @0x2b1d6a cmp r2, r3
 *   @0x2b1d6e blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b1d72 add sp, #0x4c
 *   @0x2b1d7a movs r3, r2
 *   @0x2b1d7e movs r5, r1
 *
 * ══ png_write_tRNS  0x2b1d80  size 212  本节 42 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b1d82 0x2b1e62  size 224  45 条
 * 部分覆盖: 本节 45/101 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 44/99 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 43/97 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 42/95 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1d82 mov r6, r2
 *   @0x2b1d86 sub sp, #0x14
 *   @0x2b1d8a mov r12, r1
 *   @0x2b1d8e ldr r5, [sp, #0x28]
 *   @0x2b1d96 ldrb r2, [r2, #0x4]
 *   @0x2b1d9a strb.w r2, [sp, #0x4]
 *   @0x2b1d9e bne 0x2b1dba <png_write_tRNS+0x3a>
 *   @0x2b1da2 mov r0, r4
 *   @0x2b1da6 ldrh.w r2, [r4, #0x1dc]
 *   @0x2b1daa cmp r3, r2
 *   @0x2b1dae ldr r1, [pc, #0x94]
 *   @0x2b1db2 b 0x2b1e38 <png_write_tRNS+0xb8>
 *   @0x2b1db6 mov r2, r12
 *   @0x2b1dba cbnz r5, 0x2b1de6 <png_write_tRNS+0x66>
 *   @0x2b1dc2 ldrh r1, [r6, #0x8]
 *   @0x2b1dca blt 0x2b1dd4 <png_write_tRNS+0x54>
 *   @0x2b1dce mov r0, r4
 *   @0x2b1dd2 b 0x2b1e38 <png_write_tRNS+0xb8>
 *   @0x2b1dd6 mov r0, r5
 *   @0x2b1dde mov r1, sp
 *   @0x2b1de2 movs r3, #0x2
 *   @0x2b1de6 cmp r5, #0x2
 *   @0x2b1dea add r5, sp, #0x8
 *   @0x2b1dee mov r0, r5
 *   @0x2b1df6 ldrh r1, [r6, #0x4]
 *   @0x2b1dfe ldrh r1, [r6, #0x6]
 *   @0x2b1e0a cmp r3, #0x8
 *   @0x2b1e0e ldrb.w r3, [sp, #0x8]
 *   @0x2b1e12 ldrb.w r2, [sp, #0xa]
 *   @0x2b1e16 orrs r2, r3
 *   @0x2b1e1e beq 0x2b1e26 <png_write_tRNS+0xa6>
 *   @0x2b1e22 add r1, pc
 *   @0x2b1e26 mov r1, sp
 *   @0x2b1e2a movs r3, #0x6
 *   @0x2b1e32 ldr r1, [pc, #0x1c]
 *   @0x2b1e36 add r1, pc
 *   @0x2b1e3e pop {r4, r5, r6, r7, pc}
 *   @0x2b1e42 movs r5, r1
 *   @0x2b1e46 movs r5, r1
 *   @0x2b1e4a movs r5, r1
 *   @0x2b1e4e movs r5, r1
 *   @0x2b1e52 movs r5, r1
 *
 * ══ png_write_bKGD  0x2b1e54  size 212  本节 44 条（Thumb-2 半字段）｜入度 8
 * @func 0x2b1e56 0x2b1f2a  size 212  44 条
 * 部分覆盖: 本节 44/97 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1e56 cmp r2, #0x3
 *   @0x2b1e5a add r3, pc
 *   @0x2b1e5e sub sp, #0x14
 *   @0x2b1e66 ldrb r3, [r3, #0x4]
 *   @0x2b1e6a strb.w r3, [sp, #0x4]
 *   @0x2b1e6e bne 0x2b1e9a <png_write_bKGD+0x46>
 *   @0x2b1e76 cbnz r2, 0x2b1e80 <png_write_bKGD+0x2c>
 *   @0x2b1e7e bmi 0x2b1e8c <png_write_bKGD+0x38>
 *   @0x2b1e82 blo 0x2b1e8c <png_write_bKGD+0x38>
 *   @0x2b1e86 mov r0, r4
 *   @0x2b1e8a b 0x2b1ef8 <png_write_bKGD+0xa4>
 *   @0x2b1e8e mov r0, r4
 *   @0x2b1e92 strb r3, [r2, #-8]!
 *   @0x2b1e96 movs r3, #0x1
 *   @0x2b1e9a lsls r3, r2, #0x1e
 *   @0x2b1e9e add r6, sp, #0x8
 *   @0x2b1ea2 mov r0, r6
 *   @0x2b1eaa ldrh r1, [r5, #0x4]
 *   @0x2b1eb2 ldrh r1, [r5, #0x6]
 *   @0x2b1ebe cmp r3, #0x8
 *   @0x2b1ec2 ldrb.w r3, [sp, #0x8]
 *   @0x2b1ec6 ldrb.w r2, [sp, #0xa]
 *   @0x2b1eca orrs r2, r3
 *   @0x2b1ed2 beq 0x2b1eda <png_write_bKGD+0x86>
 *   @0x2b1ed6 add r1, pc
 *   @0x2b1eda mov r1, sp
 *   @0x2b1ede movs r3, #0x6
 *   @0x2b1ee2 ldrb.w r3, [r4, #0x1eb]
 *   @0x2b1ee6 movs r2, #0x1
 *   @0x2b1eea lsl.w r3, r2, r3
 *   @0x2b1eee cmp r1, r3
 *   @0x2b1ef2 ldr r1, [pc, #0x30]
 *   @0x2b1ef6 add r1, pc
 *   @0x2b1efe add r5, sp, #0x8
 *   @0x2b1f02 bl 0x2b1138 <png_save_uint_16>
 *   @0x2b1f06 mov r0, r4
 *   @0x2b1f0a mov r2, r5
 *   @0x2b1f0e bl 0x2b12bc <png_write_chunk>
 *   @0x2b1f12 add sp, #0x14
 *   @0x2b1f16 nop
 *   @0x2b1f1a movs r5, r1
 *   @0x2b1f1e movs r5, r1
 *   @0x2b1f22 movs r5, r1
 *   @0x2b1f26 movs r5, r1
 *
 * ══ png_write_hIST  0x2b1f28  size 108  本节 21 条（Thumb-2 半字段）｜入度 3
 * @func 0x2b1f2e 0x2b1fa6  size 120  25 条
 * 部分覆盖: 本节 22/49 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/47 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1f2e ldr r3, [pc, #0x5c]
 *   @0x2b1f32 mov r6, r2
 *   @0x2b1f36 ldr r0, [r3, #68]!
 *   @0x2b1f3a ldrb r3, [r3, #0x4]
 *   @0x2b1f3e mov r0, r4
 *   @0x2b1f4a ble 0x2b1f56 <png_write_hIST+0x2e>
 *   @0x2b1f4e add r1, pc
 *   @0x2b1f56 add r1, sp, #0x8
 *   @0x2b1f5a bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b1f5e add r7, sp, #0x4
 *   @0x2b1f62 cmp r5, r6
 *   @0x2b1f66 ldrh.w r1, [r8, r5, lsl #1]
 *   @0x2b1f6a mov r0, r7
 *   @0x2b1f72 mov r1, r7
 *   @0x2b1f76 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b1f7a adds r5, #0x1
 *   @0x2b1f7e mov r0, r4
 *   @0x2b1f86 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2b1f8a nop
 *   @0x2b1f8e movs r5, r1
 *   @0x2b1f92 movs r5, r1
 *
 * ══ png_write_tEXt  0x2b1f94  size 112  本节 23 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b1f96 0x2b2012  size 124  26 条
 * 部分覆盖: 本节 25/55 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/51 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b1f96 push {r4, r5, r6, r7, lr}
 *   @0x2b1f9a mov r4, r0
 *   @0x2b1f9e ldr r0, [r3, #73]!
 *   @0x2b1fa2 mov r5, r2
 *   @0x2b1fa6 ldrb r3, [r3, #0x4]
 *   @0x2b1faa mov r0, r4
 *   @0x2b1fb6 cbz r0, 0x2b1ffa <png_write_tEXt+0x66>
 *   @0x2b1fba ldrb r6, [r5]
 *   @0x2b1fbe mov r0, r5
 *   @0x2b1fc6 b 0x2b1fca <png_write_tEXt+0x36>
 *   @0x2b1fca adds r7, #0x1
 *   @0x2b1fce add r1, sp, #0x8
 *   @0x2b1fd2 bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b1fd6 mov r0, r4
 *   @0x2b1fda mov r2, r7
 *   @0x2b1fe2 mov r0, r4
 *   @0x2b1fe6 mov r2, r6
 *   @0x2b1fee bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b1ff2 mov r0, r4
 *   @0x2b1ff6 bl 0x2a6cfc <png_free>
 *   @0x2b1ffa add sp, #0x14
 *   @0x2b1ffe nop
 *   @0x2b2002 movs r5, r1
 *
 * ══ png_write_zTXt  0x2b2004  size 180  本节 39 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b2006 0x2b20ba  size 180  39 条
 * 部分覆盖: 本节 39/84 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b2006 push.w {r4, r5, r6, r7, r8, lr}
 *   @0x2b200a add r3, pc
 *   @0x2b200e sub sp, #0x30
 *   @0x2b2016 movs r2, #0x0
 *   @0x2b201a str r2, [sp, #0x28]
 *   @0x2b201e str r0, [sp, #0x14]
 *   @0x2b2022 str r2, [sp, #0x2c]
 *   @0x2b2026 str r2, [sp, #0x20]
 *   @0x2b202a ldr r6, [sp, #0x48]
 *   @0x2b2036 cbz r0, 0x2b204e <png_write_zTXt+0x4a>
 *   @0x2b203a ldrb r3, [r5]
 *   @0x2b203e adds r3, r6, #0x1
 *   @0x2b2042 mov r0, r4
 *   @0x2b2046 mov r2, r5
 *   @0x2b204a bl 0x2b1f94 <png_write_tEXt>
 *   @0x2b204e mov r0, r4
 *   @0x2b2052 bl 0x2a6cfc <png_free>
 *   @0x2b2056 b 0x2b20ac <png_write_zTXt+0xa8>
 *   @0x2b205a add.w r8, sp, #0x1c
 *   @0x2b205e blx 0xb6538 <strlen@plt>
 *   @0x2b2062 mov r3, r6
 *   @0x2b2066 str.w r8, [sp]
 *   @0x2b206a mov r2, r0
 *   @0x2b206e bl 0x2b0f3c <png_do_write_intrapixel+0x86>
 *   @0x2b2072 adds r2, r7, #0x2
 *   @0x2b2076 add r2, r0
 *   @0x2b207a bl 0x2b11a0 <png_write_chunk_start>
 *   @0x2b207e adds r2, r7, #0x1
 *   @0x2b2082 ldr r1, [sp, #0x10]
 *   @0x2b208a ldr r1, [sp, #0x10]
 *   @0x2b2092 mov r0, r4
 *   @0x2b2096 strb r6, [r1, #-36]!
 *   @0x2b209a bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b209e mov r0, r4
 *   @0x2b20a2 bl 0x2b1226 <png_write_chunk_data+0x22>
 *   @0x2b20a6 mov r0, r4
 *   @0x2b20ae pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2b20b2 nop
 *   @0x2b20b6 movs r5, r1
 *
 * ══ png_write_iTXt  0x2b20b8  size 288  本节 59 条（Thumb-2 半字段）｜入度 3
 * @func 0x2b20be 0x2b21da  size 284  59 条
 * 部分覆盖: 本节 59/130 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b20be ldr r6, [pc, #0x110]
 *   @0x2b20c2 mov r8, r3
 *   @0x2b20c6 add r6, pc
 *   @0x2b20ca add r2, sp, #0x10
 *   @0x2b20ce ldr r0, [r6, #83]!
 *   @0x2b20d2 ldr r7, [sp, #0x5c]
 *   @0x2b20d6 movs r6, #0x0
 *   @0x2b20da mov r0, r4
 *   @0x2b20de strb.w r3, [sp, #0x18]
 *   @0x2b20e2 str r6, [sp, #0x24]
 *   @0x2b20e6 str r6, [sp, #0x2c]
 *   @0x2b20ea bl 0x2af5b0 <png_check_keyword>
 *   @0x2b20ee mov r10, r0
 *   @0x2b20f2 beq 0x2b21ca <png_write_iTXt+0x112>
 *   @0x2b20f6 mov r1, r8
 *   @0x2b20fa bl 0x2af5b0 <png_check_keyword>
 *   @0x2b20fe mov r6, r0
 *   @0x2b2102 ldr r1, [pc, #0xd0]
 *   @0x2b2106 add r1, pc
 *   @0x2b210e cbz r5, 0x2b211a <png_write_iTXt+0x62>
 *   @0x2b2112 blx 0xb6538 <strlen@plt>
 *   @0x2b2116 mov r8, r0
 *   @0x2b211a mov r8, r5
 *   @0x2b211e mov r0, r7
 *   @0x2b2126 b 0x2b212a <png_write_iTXt+0x72>
 *   @0x2b212a sub.w r3, r9, #0x2
 *   @0x2b212e mov r1, r7
 *   @0x2b2136 str.w r11, [sp]
 *   @0x2b213a bl 0x2b0f3c <png_do_write_intrapixel+0x86>
 *   @0x2b213e add.w r2, r10, #0x5
 *   @0x2b2142 add r2, r6
 *   @0x2b2146 add r2, r8
 *   @0x2b214a mov r0, r4
 *   @0x2b2152 ldr r1, [sp, #0x10]
 *   @0x2b2162 cmp.w r9, #0xffffffff
 *   @0x2b2166 bne 0x2b216c <png_write_iTXt+0xb4>
 *   @0x2b216a b 0x2b216e <png_write_iTXt+0xb6>
 *   @0x2b216e add r7, sp, #0x8
 *   @0x2b2172 movs r2, #0x2
 *   @0x2b217a mov.w r9, #0x0
 *   @0x2b217e strb.w r9, [sp, #0x9]
 *   @0x2b2182 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2186 ldr r1, [sp, #0xc]
 *   @0x2b218a adds r2, r6, #0x1
 *   @0x2b2192 it eq
 *   @0x2b2196 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b219a add.w r2, r8, #0x1
 *   @0x2b219e mov r0, r4
 *   @0x2b21a2 ite ne
 *   @0x2b21a6 moveq r1, r7
 *   @0x2b21ae mov r0, r4
 *   @0x2b21b6 bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b21ba mov r0, r4
 *   @0x2b21be bl 0x2a6cfc <png_free>
 *   @0x2b21c2 mov r0, r4
 *   @0x2b21c6 bl 0x2a6cfc <png_free>
 *   @0x2b21ca add sp, #0x34
 *   @0x2b21d2 movs r5, r1
 *   @0x2b21d6 movs r5, r1
 *
 * ══ png_write_oFFs  0x2b21d8  size 120  本节 23 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b21de 0x2b2252  size 116  23 条
 * 部分覆盖: 本节 23/52 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b21de ldr r4, [pc, #0x64]
 *   @0x2b21e2 ldr r5, [pc, #0x64]
 *   @0x2b21e6 add r4, pc
 *   @0x2b21ea cmp r7, #0x1
 *   @0x2b21ee mov r9, r1
 *   @0x2b21f2 mov r8, r2
 *   @0x2b21fa ldrb r3, [r5, #0x4]
 *   @0x2b21fe strb.w r3, [sp, #0x4]
 *   @0x2b2202 ble 0x2b220e <png_write_oFFs+0x36>
 *   @0x2b2206 mov r0, r6
 *   @0x2b220a bl 0x2a6474 <png_warning>
 *   @0x2b220e add r5, sp, #0x8
 *   @0x2b2212 mov r0, r5
 *   @0x2b221a mov r1, r8
 *   @0x2b2222 movs r3, #0x9
 *   @0x2b2226 mov r1, sp
 *   @0x2b2232 ldr r3, [r4]
 *   @0x2b2236 beq 0x2b223c <png_write_oFFs+0x64>
 *   @0x2b223e pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b2242 nop
 *   @0x2b2246 movs r3, r2
 *   @0x2b224a movs r5, r1
 *   @0x2b224e movs r5, r1
 *
 * ══ png_write_pCAL  0x2b2250  size 308  本节 58 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b2256 0x2b2386  size 304  58 条
 * 部分覆盖: 本节 58/134 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b2256 mov r4, r0
 *   @0x2b225a str r3, [sp, #0x10]
 *   @0x2b225e str r2, [sp, #0xc]
 *   @0x2b2262 ldr r3, [r3]
 *   @0x2b2266 ldr r5, [sp, #0x64]
 *   @0x2b226a cmp r1, #0x3
 *   @0x2b2272 str r2, [sp, #0x34]
 *   @0x2b2276 str r3, [sp, #0x14]
 *   @0x2b227a ldr r0, [r2, #93]!
 *   @0x2b227e ldrb r2, [r2, #0x4]
 *   @0x2b2282 strb.w r2, [sp, #0x24]
 *   @0x2b2286 ble 0x2b2292 <png_write_pCAL+0x42>
 *   @0x2b228a mov r0, r4
 *   @0x2b228e bl 0x2a6474 <png_warning>
 *   @0x2b2292 mov r1, r6
 *   @0x2b2296 mov r0, r4
 *   @0x2b22a2 blx 0xb6538 <strlen@plt>
 *   @0x2b22a6 lsls r1, r5, #0x2
 *   @0x2b22aa ite eq
 *   @0x2b22ae addne.w r8, r0, #0x1
 *   @0x2b22b2 mov r0, r4
 *   @0x2b22c2 movs r3, #0x0
 *   @0x2b22c6 cmp r3, r5
 *   @0x2b22ca ldr.w r0, [r7, r3, lsl #2]
 *   @0x2b22ce str r1, [sp, #0x4]
 *   @0x2b22d2 blx 0xb6538 <strlen@plt>
 *   @0x2b22d6 ldr r3, [sp, #0x8]
 *   @0x2b22da cmp r3, r1
 *   @0x2b22de addne r0, #0x1
 *   @0x2b22e6 adds r3, #0x1
 *   @0x2b22ea mov r0, r4
 *   @0x2b22ee mov r2, r11
 *   @0x2b22f6 add.w r10, sp, #0x28
 *   @0x2b22fa mov r0, r4
 *   @0x2b22fe bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2302 mov r0, r10
 *   @0x2b2306 bl 0x2b1134 <png_save_int_32>
 *   @0x2b230a add.w r0, r10, #0x4
 *   @0x2b230e ldr r1, [sp, #0x10]
 *   @0x2b2316 mov r0, r4
 *   @0x2b231a movs r2, #0xa
 *   @0x2b232a mov r0, r4
 *   @0x2b232e mov.w r8, #0x0
 *   @0x2b2332 bl 0x2b1204 <png_write_chunk_data>
 *   @0x2b2336 mov r0, r4
 *   @0x2b233a bl 0x2a6cfc <png_free>
 *   @0x2b233e cmp r8, r5
 *   @0x2b2342 bge 0x2b2356 <png_write_pCAL+0x106>
 *   @0x2b2356 mov r1, r6
 *   @0x2b235e bl 0x2b1296 <png_write_chunk_end>
 *   @0x2b2362 ldr r1, [sp, #0x14]
 *   @0x2b2366 ldr r3, [r1]
 *   @0x2b236a beq 0x2b2370 <png_write_pCAL+0x120>
 *   @0x2b2372 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b2376 nop
 *   @0x2b237a movs r3, r2
 *   @0x2b237e movs r5, r1
 *   @0x2b2382 movs r5, r1
 *
 * ══ png_write_sCAL  0x2b2384  size 148  本节 26 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b238a 0x2b241a  size 144  26 条
 * 部分覆盖: 本节 26/62 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b238a ldr r7, [pc, #0x80]
 *   @0x2b238e ldr r4, [pc, #0x80]
 *   @0x2b2392 add r7, pc
 *   @0x2b2396 ldr.w r11, [pc, #0x7c]
 *   @0x2b239a add r4, pc
 *   @0x2b23a2 add r11, pc
 *   @0x2b23aa mov r2, r11
 *   @0x2b23ae ldr r0, [r4, #98]!
 *   @0x2b23b2 str r0, [sp, #0xc]
 *   @0x2b23b6 adds r4, r6, #0x1
 *   @0x2b23be blx 0xb65c8 <snprintf@plt>
 *   @0x2b23c2 mov r0, r4
 *   @0x2b23ce strd r4, r5, [sp]
 *   @0x2b23d2 add.w r8, r0, #0x2
 *   @0x2b23d6 mov r1, r0
 *   @0x2b23e2 blx 0xb65c8 <snprintf@plt>
 *   @0x2b23e6 mov r0, r9
 *   @0x2b23ee add r1, sp, #0xc
 *   @0x2b23f6 bl 0x2b12bc <png_write_chunk>
 *   @0x2b23fa ldr r2, [sp, #0x54]
 *   @0x2b23fe cmp r2, r3
 *   @0x2b2402 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b2406 add sp, #0x5c
 *   @0x2b240e movs r3, r2
 *   @0x2b2412 movs r5, r1
 *   @0x2b2416 movs r5, r1
 *
 * ══ png_write_pHYs  0x2b2418  size 120  本节 23 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b241e 0x2b24a2  size 132  27 条
 * 部分覆盖: 本节 27/60 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 26/58 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/56 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/52 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b241e ldr r4, [pc, #0x64]
 *   @0x2b2422 ldr r5, [pc, #0x64]
 *   @0x2b2426 add r4, pc
 *   @0x2b242a cmp r7, #0x1
 *   @0x2b242e mov r9, r1
 *   @0x2b2432 mov r8, r2
 *   @0x2b243a ldrb r3, [r5, #0x4]
 *   @0x2b243e strb.w r3, [sp, #0x4]
 *   @0x2b2442 ble 0x2b244e <png_write_pHYs+0x36>
 *   @0x2b2446 mov r0, r6
 *   @0x2b244a bl 0x2a6474 <png_warning>
 *   @0x2b244e add r5, sp, #0x8
 *   @0x2b2452 mov r0, r5
 *   @0x2b245a mov r1, r8
 *   @0x2b2462 movs r3, #0x9
 *   @0x2b2466 mov r1, sp
 *   @0x2b2472 ldr r3, [r4]
 *   @0x2b2476 beq 0x2b247c <png_write_pHYs+0x64>
 *   @0x2b247e pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b2482 nop
 *   @0x2b2486 movs r3, r2
 *   @0x2b248a movs r5, r1
 *   @0x2b248e movs r5, r1
 *
 * ══ png_write_tIME  0x2b2490  size 128  本节 27 条（Thumb-2 半字段）｜入度 5
 * @func 0x2b2492 0x2b2516  size 132  28 条
 * 部分覆盖: 本节 28/61 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 27/59 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b2492 mov r6, r0
 *   @0x2b2496 mov r4, r1
 *   @0x2b249a ldr r0, [r3, #108]!
 *   @0x2b249e ldrb r3, [r3, #0x4]
 *   @0x2b24a2 strb.w r3, [sp, #0x4]
 *   @0x2b24a6 ldrb r3, [r1, #0x2]
 *   @0x2b24aa cmp r3, #0xb
 *   @0x2b24ae ldrb r3, [r1, #0x3]
 *   @0x2b24b2 cmp r3, #0x1e
 *   @0x2b24b6 ldrb r3, [r1, #0x4]
 *   @0x2b24ba bhi 0x2b24c2 <png_write_tIME+0x32>
 *   @0x2b24be cmp r3, #0x3c
 *   @0x2b24c2 ldr r1, [pc, #0x48]
 *   @0x2b24c6 add r1, pc
 *   @0x2b24ce add r5, sp, #0x8
 *   @0x2b24d2 mov r0, r5
 *   @0x2b24da mov r0, r6
 *   @0x2b24de mov r2, r5
 *   @0x2b24e6 strb.w r3, [sp, #0xb]
 *   @0x2b24ea ldrb r3, [r4, #0x4]
 *   @0x2b24f2 strb.w r3, [sp, #0xd]
 *   @0x2b24f6 ldrb r3, [r4, #0x6]
 *   @0x2b24fe bl 0x2b12bc <png_write_chunk>
 *   @0x2b2502 add sp, #0x10
 *   @0x2b2506 nop
 *   @0x2b250a movs r5, r1
 *   @0x2b250e movs r5, r1
 *
 * ══ png_write_start_row  0x2b2510  size 252  本节 47 条（Thumb-2 半字段）｜入度 8
 * @func 0x2b2512 0x2b261a  size 264  50 条
 * 部分覆盖: 本节 50/116 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 49/114 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 48/112 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 47/110 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b2512 mov r4, r0
 *   @0x2b2526 ble 0x2b252e <png_write_start_row+0x1e>
 *   @0x2b252a muls r5, r2, r5
 *   @0x2b252e mul r5, r2, r3
 *   @0x2b2532 adds r5, #0x7
 *   @0x2b2536 adds r5, #0x1
 *   @0x2b253a mov r1, r5
 *   @0x2b2542 str.w r0, [r4, #0x1b0]
 *   @0x2b2546 strb r3, [r0]
 *   @0x2b254e bpl 0x2b2564 <png_write_start_row+0x54>
 *   @0x2b2556 adds r1, #0x1
 *   @0x2b255e str.w r0, [r4, #0x1b4]
 *   @0x2b2562 strb r3, [r0]
 *   @0x2b256e mov r1, r5
 *   @0x2b2572 bl 0x2a6cd8 <png_calloc>
 *   @0x2b2576 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b257a lsls r5, r3, #0x1a
 *   @0x2b2582 ldr.w r1, [r4, #0x19c]
 *   @0x2b2586 mov r0, r4
 *   @0x2b258a bl 0x2a6ca0 <png_malloc>
 *   @0x2b258e movs r3, #0x2
 *   @0x2b2596 ldrb.w r3, [r4, #0x1e9]
 *   @0x2b259a lsls r0, r3, #0x19
 *   @0x2b259e ldr.w r1, [r4, #0x19c]
 *   @0x2b25a2 mov r0, r4
 *   @0x2b25a6 bl 0x2a6ca0 <png_malloc>
 *   @0x2b25aa movs r3, #0x3
 *   @0x2b25b2 ldrsb.w r3, [r4, #0x1e9]
 *   @0x2b25b6 cmp r3, #0x0
 *   @0x2b25ba ldr.w r1, [r4, #0x19c]
 *   @0x2b25be mov r0, r4
 *   @0x2b25c2 bl 0x2a6ca0 <png_malloc>
 *   @0x2b25c6 movs r3, #0x4
 *   @0x2b25ce ldrb.w r1, [r4, #0x1e7]
 *   @0x2b25d2 ldr.w r3, [r4, #0x18c]
 *   @0x2b25d6 ldr.w r2, [r4, #0x190]
 *   @0x2b25da cbz r1, 0x2b25f2 <png_write_start_row+0xe2>
 *   @0x2b25e2 bmi 0x2b25f2 <png_write_start_row+0xe2>
 *   @0x2b25e6 adds r3, #0x7
 *   @0x2b25ea lsrs r3, r3, #0x3
 *   @0x2b25f2 str.w r2, [r4, #0x194]
 *   @0x2b25f6 str.w r3, [r4, #0x198]
 *   @0x2b25fa ldr.w r3, [r4, #0x174]
 *   @0x2b25fe str.w r3, [r4, #0x148]
 *   @0x2b2602 ldr.w r3, [r4, #0x170]
 *   @0x2b2606 str.w r3, [r4, #0x144]
 *   @0x2b260a pop {r3, r4, r5, pc}
 *
 * ══ png_write_finish_row  0x2b260c  size 400  本节 72 条（Thumb-2 半字段）｜入度 8
 * @func 0x2b260e 0x2b279e  size 400  72 条
 * 部分覆盖: 本节 72/172 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b260e mov r4, r0
 *   @0x2b2612 sub sp, #0x74
 *   @0x2b2616 mov r5, sp
 *   @0x2b261e stm r5!, {r0, r1, r2, r3}
 *   @0x2b262e ldm r7!, {r0, r1, r2, r3}
 *   @0x2b2632 ldm.w r7, {r0, r1, r2}
 *   @0x2b2636 add.w r7, r6, #0xac
 *   @0x2b263a adds r6, #0xc8
 *   @0x2b2642 ldm r7!, {r0, r1, r2, r3}
 *   @0x2b2646 ldm.w r7, {r0, r1, r2}
 *   @0x2b264a stm.w r5, {r0, r1, r2}
 *   @0x2b264e add r5, sp, #0x54
 *   @0x2b2652 stm r5!, {r0, r1, r2, r3}
 *   @0x2b265e str.w r3, [r4, #0x1a8]
 *   @0x2b2662 stm.w r5, {r0, r1, r2}
 *   @0x2b2666 ldr.w r2, [r4, #0x194]
 *   @0x2b266a cmp r3, r2
 *   @0x2b2676 beq 0x2b271e <png_write_finish_row+0x112>
 *   @0x2b267a str.w r3, [r4, #0x1a8]
 *   @0x2b267e ldr.w r3, [r4, #0x134]
 *   @0x2b2682 ldrb.w r5, [r4, #0x1e8]
 *   @0x2b2686 tst.w r3, #0x2
 *   @0x2b268a beq 0x2b26ce <png_write_finish_row+0xc2>
 *   @0x2b268e b 0x2b26dc <png_write_finish_row+0xd0>
 *   @0x2b2692 add.w r6, r3, r5, lsl #2
 *   @0x2b2696 ldr.w r3, [r4, #0x18c]
 *   @0x2b269a ldr r1, [r6, #-84]
 *   @0x2b269e subs r3, #0x1
 *   @0x2b26a2 ldr r3, [r6, #-112]
 *   @0x2b26a6 subs r0, r0, r3
 *   @0x2b26b6 ldr r2, [r6, #-56]
 *   @0x2b26ba str.w r0, [r4, #0x198]
 *   @0x2b26be mov r7, r0
 *   @0x2b26c2 subs r0, r0, r2
 *   @0x2b26ce adds r5, #0x1
 *   @0x2b26d2 cmp r5, #0x6
 *   @0x2b26d6 b 0x2b26dc <png_write_finish_row+0xd0>
 *   @0x2b26da beq 0x2b26ce <png_write_finish_row+0xc2>
 *   @0x2b26e6 bhi 0x2b271e <png_write_finish_row+0x112>
 *   @0x2b26ee beq 0x2b2790 <png_write_finish_row+0x184>
 *   @0x2b2702 ble 0x2b270a <png_write_finish_row+0xfe>
 *   @0x2b2706 muls r2, r3, r2
 *   @0x2b270a muls r2, r3, r2
 *   @0x2b270e lsrs r2, r2, #0x3
 *   @0x2b2712 movs r1, #0x0
 *   @0x2b2716 pop.w {r4, r5, r6, r7, lr}
 *   @0x2b271a b.w 0x31bacc <__udivdi3+0x434>
 *   @0x2b271e ldr r6, [pc, #0x78]
 *   @0x2b2726 mov r0, r5
 *   @0x2b272a blx 0xb69ac <deflate@plt>
 *   @0x2b272e cbnz r0, 0x2b2758 <png_write_finish_row+0x14c>
 *   @0x2b2736 bne 0x2b2726 <png_write_finish_row+0x11a>
 *   @0x2b273a ldr.w r1, [r4, #0x170]
 *   @0x2b273e ldr.w r2, [r4, #0x174]
 *   @0x2b2742 bl 0x2b16a0 <png_write_IDAT>
 *   @0x2b2746 ldr.w r3, [r4, #0x170]
 *   @0x2b274a str.w r3, [r4, #0x144]
 *   @0x2b274e ldr.w r3, [r4, #0x174]
 *   @0x2b2752 str.w r3, [r4, #0x148]
 *   @0x2b2756 b 0x2b2726 <png_write_finish_row+0x11a>
 *   @0x2b275a beq 0x2b276c <png_write_finish_row+0x160>
 *   @0x2b2762 cbnz r1, 0x2b2766 <png_write_finish_row+0x15a>
 *   @0x2b2766 bl 0x2a642c <png_error>
 *   @0x2b276a b 0x2b2726 <png_write_finish_row+0x11a>
 *   @0x2b2776 bhs 0x2b2784 <png_write_finish_row+0x178>
 *   @0x2b277a ldr.w r1, [r4, #0x170]
 *   @0x2b277e subs r2, r2, r3
 *   @0x2b2786 blx 0xb6f58 <deflateReset@plt>
 *   @0x2b278a movs r3, #0x0
 *   @0x2b2792 pop {r4, r5, r6, r7, pc}
 *   @0x2b2796 movs r5, r1
 *   @0x2b279a movs r5, r1
 *
 * ══ png_do_write_interlace  0x2b279c  size 416  本节 80 条（Thumb-2 半字段）｜入度 15
 * @func 0x2b27a2 0x2b294e  size 428  84 条
 * 部分覆盖: 本节 84/191 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 83/189 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 82/187 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 81/185 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 80/183 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b27a2 ldr r5, [pc, #0x194]
 *   @0x2b27a6 mov r7, r1
 *   @0x2b27aa add r5, pc
 *   @0x2b27b6 add.w r5, r5, #0x90
 *   @0x2b27ba ldm r6!, {r0, r1, r2, r3}
 *   @0x2b27be ldm.w r6, {r0, r1, r2}
 *   @0x2b27c2 stm.w r4, {r0, r1, r2}
 *   @0x2b27c6 add r4, sp, #0x1c
 *   @0x2b27ca stm r4!, {r0, r1, r2, r3}
 *   @0x2b27e6 beq 0x2b2836 <png_do_write_interlace+0x9a>
 *   @0x2b27ea beq 0x2b287e <png_do_write_interlace+0xe2>
 *   @0x2b27ee bne 0x2b28ca <png_do_write_interlace+0x12e>
 *   @0x2b27f2 mov r6, r7
 *   @0x2b27f6 movs r2, #0x0
 *   @0x2b27fa ldr r1, [r0, #-56]
 *   @0x2b27fe mov lr, r0
 *   @0x2b2802 bhs 0x2b2832 <png_do_write_interlace+0x96>
 *   @0x2b2806 ldrb.w r12, [r7, r0]
 *   @0x2b280a mvns r0, r1
 *   @0x2b281a orrs r2, r0
 *   @0x2b281e strb r2, [r6]
 *   @0x2b2822 adds r6, #0x1
 *   @0x2b2826 b 0x2b282a <png_do_write_interlace+0x8e>
 *   @0x2b282a ldr r0, [lr, #-28]
 *   @0x2b282e add r1, r0
 *   @0x2b2832 cmp r3, #0x7
 *   @0x2b2836 add r0, sp, #0x38
 *   @0x2b283a add r0, r4
 *   @0x2b283e movs r3, #0x6
 *   @0x2b2846 cmp r1, r5
 *   @0x2b284a lsrs r0, r1, #0x2
 *   @0x2b2852 and r0, r0, #0x3
 *   @0x2b2856 lsls r0, r0, #0x1
 *   @0x2b2862 orrs r2, r0
 *   @0x2b2866 strb r2, [r6]
 *   @0x2b286a adds r6, #0x1
 *   @0x2b286e b 0x2b2872 <png_do_write_interlace+0xd6>
 *   @0x2b2872 ldr r0, [lr, #-28]
 *   @0x2b2876 add r1, r0
 *   @0x2b287a cmp r3, #0x6
 *   @0x2b287e add r0, sp, #0x38
 *   @0x2b2882 add r0, r4
 *   @0x2b2886 ldr r1, [r0, #-56]
 *   @0x2b288a mov lr, r0
 *   @0x2b288e bhs 0x2b28c2 <png_do_write_interlace+0x126>
 *   @0x2b2892 tst.w r1, #0x1
 *   @0x2b2896 ldrb.w r12, [r7, r0]
 *   @0x2b289a ite ne
 *   @0x2b289e moveq r0, #0x4
 *   @0x2b28aa orrs r2, r0
 *   @0x2b28ae strb r2, [r6]
 *   @0x2b28b2 adds r6, #0x1
 *   @0x2b28b6 b 0x2b28ba <png_do_write_interlace+0x11e>
 *   @0x2b28ba ldr r0, [lr, #-28]
 *   @0x2b28be add r1, r0
 *   @0x2b28c2 cmp r3, #0x4
 *   @0x2b28c6 strb r2, [r6]
 *   @0x2b28ca lsr.w r9, r3, #0x3
 *   @0x2b28ce add r3, sp, #0x38
 *   @0x2b28d2 mov r12, r7
 *   @0x2b28da cmp r6, r5
 *   @0x2b28de mla r1, r9, r6, r7
 *   @0x2b28e2 cmp r12, r1
 *   @0x2b28e6 mov r0, r12
 *   @0x2b28ea blx 0xb65bc <memcpy@plt>
 *   @0x2b28ee mov r12, r0
 *   @0x2b28f6 add r6, r2
 *   @0x2b28fa add r3, sp, #0x38
 *   @0x2b28fe ldr.w r3, [r8]
 *   @0x2b2902 ldr r1, [r4, #-28]
 *   @0x2b2906 subs r3, #0x1
 *   @0x2b290e subs r0, r0, r2
 *   @0x2b291a str.w r0, [r8]
 *   @0x2b291e bls 0x2b2926 <png_do_write_interlace+0x18a>
 *   @0x2b2922 muls r0, r3, r0
 *   @0x2b2926 muls r0, r3, r0
 *   @0x2b292a lsrs r0, r0, #0x3
 *   @0x2b2932 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b2936 nop
 *   @0x2b293a movs r5, r1
 *
 * ══ png_write_filtered_row  0x2b293c  size 156  本节 31 条（Thumb-2 半字段）｜入度 1
 * @func 0x2b293e 0x2b29da  size 156  31 条
 * 部分覆盖: 本节 31/70 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b293e add.w r5, r0, #0x138
 *   @0x2b2942 ldr r6, [pc, #0x90]
 *   @0x2b2946 ldr.w r3, [r0, #0x1c8]
 *   @0x2b294a add r6, pc
 *   @0x2b2952 str.w r3, [r0, #0x13c]
 *   @0x2b2956 mov r0, r5
 *   @0x2b295a blx 0xb69ac <deflate@plt>
 *   @0x2b295e cbz r0, 0x2b296e <png_write_filtered_row+0x32>
 *   @0x2b2966 cbnz r1, 0x2b296a <png_write_filtered_row+0x2e>
 *   @0x2b296a bl 0x2a642c <png_error>
 *   @0x2b296e ldr.w r3, [r4, #0x148]
 *   @0x2b2972 cbnz r3, 0x2b2992 <png_write_filtered_row+0x56>
 *   @0x2b2976 ldr.w r1, [r4, #0x170]
 *   @0x2b297a ldr.w r2, [r4, #0x174]
 *   @0x2b297e bl 0x2b16a0 <png_write_IDAT>
 *   @0x2b2982 ldr.w r3, [r4, #0x170]
 *   @0x2b2986 str.w r3, [r4, #0x144]
 *   @0x2b298a ldr.w r3, [r4, #0x174]
 *   @0x2b298e str.w r3, [r4, #0x148]
 *   @0x2b2992 ldr.w r3, [r4, #0x13c]
 *   @0x2b2996 cmp r3, #0x0
 *   @0x2b299a ldr.w r3, [r4, #0x1ac]
 *   @0x2b299e cbz r3, 0x2b29ac <png_write_filtered_row+0x70>
 *   @0x2b29ae bl 0x2b260c <png_write_finish_row>
 *   @0x2b29b2 ldr.w r2, [r4, #0x218]
 *   @0x2b29b6 ldr.w r3, [r4, #0x214]
 *   @0x2b29ba adds r2, #0x1
 *   @0x2b29c2 cmp r2, r3
 *   @0x2b29c6 mov r0, r4
 *   @0x2b29d2 nop
 *   @0x2b29d6 movs r5, r1
 *
 * ══ png_write_find_filter  0x2b29d8  size 1060  本节 199 条（Thumb-2 半字段）｜入度 29
 * @func 0x2b29de 0x2b2df6  size 1048  199 条
 * 部分覆盖: 本节 199/461 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b29de ldrb r3, [r1, #0xb]
 *   @0x2b29e2 ldrb.w r0, [r0, #0x1e9]
 *   @0x2b29e6 ldr r2, [r1, #0x4]
 *   @0x2b29ea ldr.w r4, [r11, #0x1ac]
 *   @0x2b29ee lsls r7, r0, #0x1c
 *   @0x2b29f6 str r4, [sp, #0x4]
 *   @0x2b29fe cmp r0, #0x8
 *   @0x2b2a02 ldr r6, [sp, #0xc]
 *   @0x2b2a06 movs r1, #0x0
 *   @0x2b2a0a cmp r4, r6
 *   @0x2b2a0e ldrb r5, [r4, #1]!
 *   @0x2b2a12 cmp r5, #0x7f
 *   @0x2b2a16 rsbgt.w r5, r5, #0x100
 *   @0x2b2a1a add r1, r5
 *   @0x2b2a1e mvn r1, #0x80000000
 *   @0x2b2a22 cmp r0, #0x10
 *   @0x2b2a26 ldr.w r5, [r11, #0x1b4]
 *   @0x2b2a2a adds r6, r2, #0x1
 *   @0x2b2a2e adds r7, r5, #0x1
 *   @0x2b2a32 beq 0x2b2a48 <png_write_find_filter+0x70>
 *   @0x2b2a42 strb.w r8, [r12, #0x1]
 *   @0x2b2a46 b 0x2b2a30 <png_write_find_filter+0x58>
 *   @0x2b2a4a subs r7, r2, r3
 *   @0x2b2a4e ldr r5, [sp, #0xc]
 *   @0x2b2a52 bhs 0x2b2a6c <png_write_find_filter+0x94>
 *   @0x2b2a6a b 0x2b2a4e <png_write_find_filter+0x76>
 *   @0x2b2a72 b 0x2b2b2e <png_write_find_filter+0x156>
 *   @0x2b2a7a bpl 0x2b2afc <png_write_find_filter+0x124>
 *   @0x2b2a82 add.w r8, r2, #0x1
 *   @0x2b2a86 mov r4, r5
 *   @0x2b2a8e beq 0x2b2aaa <png_write_find_filter+0xd2>
 *   @0x2b2a92 add.w r9, r7, r5
 *   @0x2b2a96 adds r5, #0x1
 *   @0x2b2a9a cmp r6, #0x7f
 *   @0x2b2aa2 rsbgt.w r6, r6, #0x100
 *   @0x2b2aa6 add r4, r6
 *   @0x2b2aaa add.w r9, r12, r3
 *   @0x2b2aae rsb.w r12, r3, #0x0
 *   @0x2b2ab2 add.w r7, r2, r12
 *   @0x2b2ab6 add r12, r9
 *   @0x2b2aba mov r10, r8
 *   @0x2b2abe cmp r5, r6
 *   @0x2b2ac2 add.w r8, r7, r5
 *   @0x2b2ac6 ldrb.w r9, [r10, r5]
 *   @0x2b2aca ldrb.w r8, [r8, #0x1]
 *   @0x2b2ace rsb r8, r8, r9
 *   @0x2b2ad2 uxtb.w r8, r8
 *   @0x2b2ad6 strb.w r8, [r12, r5]
 *   @0x2b2ada cmp.w r8, #0x7f
 *   @0x2b2ade it gt
 *   @0x2b2ae6 cmp r4, r1
 *   @0x2b2aea adds r5, #0x1
 *   @0x2b2aee cmp r4, r1
 *   @0x2b2af2 ldr.w r1, [r11, #0x1b4]
 *   @0x2b2af6 str r1, [sp, #0x8]
 *   @0x2b2afa b 0x2b2afe <png_write_find_filter+0x126>
 *   @0x2b2afe cmp r0, #0x20
 *   @0x2b2b02 ldr r4, [sp, #0xc]
 *   @0x2b2b0a movs r4, #0x0
 *   @0x2b2b0e cmp r4, r5
 *   @0x2b2b12 ldr.w r8, [sp, #0x4]
 *   @0x2b2b16 ldrb.w r12, [r2, r4]
 *   @0x2b2b1a ldrb.w r7, [r8, r4]
 *   @0x2b2b1e rsb r7, r7, r12
 *   @0x2b2b22 strb r7, [r6, r4]
 *   @0x2b2b26 ldr.w r4, [r11, #0x1b8]
 *   @0x2b2b2a str r4, [sp, #0x8]
 *   @0x2b2b2e lsls r5, r0, #0x1a
 *   @0x2b2b32 ldr r5, [sp, #0xc]
 *   @0x2b2b36 ldr.w r7, [r11, #0x1b8]
 *   @0x2b2b3a adds r6, r5, #0x1
 *   @0x2b2b3e cmp r4, r6
 *   @0x2b2b42 ldr.w r9, [sp, #0x4]
 *   @0x2b2b46 ldrb.w r8, [r2, r4]
 *   @0x2b2b4a ldrb.w r12, [r9, r4]
 *   @0x2b2b4e rsb r12, r12, r8
 *   @0x2b2b52 uxtb.w r12, r12
 *   @0x2b2b56 strb.w r12, [r7, r4]
 *   @0x2b2b5a cmp.w r12, #0x7f
 *   @0x2b2b5e add.w r4, r4, #0x1
 *   @0x2b2b62 it gt
 *   @0x2b2b6a cmp r5, r1
 *   @0x2b2b6e b 0x2b2b7c <png_write_find_filter+0x1a4>
 *   @0x2b2b72 bhs 0x2b2b7c <png_write_find_filter+0x1a4>
 *   @0x2b2b7a mov r1, r5
 *   @0x2b2b7e bne 0x2b2be2 <png_write_find_filter+0x20a>
 *   @0x2b2b86 ldr r4, [sp, #0x4]
 *   @0x2b2b92 movs r4, #0x0
 *   @0x2b2b96 cmp r4, r8
 *   @0x2b2b9a ldr.w r10, [sp, #0x4]
 *   @0x2b2b9e ldrb.w r9, [r10, r4]
 *   @0x2b2ba2 ldrb.w r10, [r2, r4]
 *   @0x2b2ba6 sub.w r9, r10, r9, lsr #1
 *   @0x2b2baa strb.w r9, [r5, r4]
 *   @0x2b2bae b 0x2b2b94 <png_write_find_filter+0x1bc>
 *   @0x2b2bb6 ldr r5, [sp, #0xc]
 *   @0x2b2bba bhs 0x2b2bda <png_write_find_filter+0x202>
 *   @0x2b2bca ldrb.w r9, [r7, r4]
 *   @0x2b2bce sub.w r8, r9, r8, lsr #1
 *   @0x2b2bd2 strb.w r8, [r12, r4]
 *   @0x2b2bd6 adds r4, #0x1
 *   @0x2b2bda ldr.w r6, [r11, #0x1bc]
 *   @0x2b2bde str r6, [sp, #0x8]
 *   @0x2b2be2 lsls r4, r0, #0x19
 *   @0x2b2be6 ldr.w r6, [r11, #0x1bc]
 *   @0x2b2bea add.w r10, r2, #0x1
 *   @0x2b2bee ldr r4, [sp, #0x4]
 *   @0x2b2bfa adds r4, #0x1
 *   @0x2b2bfe movs r4, #0x0
 *   @0x2b2c02 beq 0x2b2c28 <png_write_find_filter+0x250>
 *   @0x2b2c16 strb r7, [r6, r5]
 *   @0x2b2c1a add.w r5, r5, #0x1
 *   @0x2b2c1e it gt
 *   @0x2b2c26 b 0x2b2c00 <png_write_find_filter+0x228>
 *   @0x2b2c2a add r9, r3
 *   @0x2b2c36 mov r5, r3
 *   @0x2b2c3a cmp r5, r6
 *   @0x2b2c3e add.w r6, r12, r5
 *   @0x2b2c42 ldrb.w r7, [r8, r5]
 *   @0x2b2c46 ldrb r6, [r6, #0x1]
 *   @0x2b2c4a ldrb.w r7, [r10, r5]
 *   @0x2b2c4e sub.w r6, r7, r6, lsr #1
 *   @0x2b2c52 uxtb r6, r6
 *   @0x2b2c5a it gt
 *   @0x2b2c62 cmp r4, r1
 *   @0x2b2c66 adds r5, #0x1
 *   @0x2b2c6a cmp r4, r1
 *   @0x2b2c6e ldr.w r1, [r11, #0x1bc]
 *   @0x2b2c72 str r1, [sp, #0x8]
 *   @0x2b2c76 cmp r0, #0x80
 *   @0x2b2c7a ldr r5, [sp, #0x4]
 *   @0x2b2c7e ldr.w r0, [r11, #0x1c0]
 *   @0x2b2c82 movs r1, #0x0
 *   @0x2b2c8a add.w r10, r0, #0x1
 *   @0x2b2c8e adds r1, #0x1
 *   @0x2b2c92 beq 0x2b2ca4 <png_write_find_filter+0x2cc>
 *   @0x2b2c9a ldrb.w r6, [r8, r1]
 *   @0x2b2c9e subs r6, r7, r6
 *   @0x2b2ca2 b 0x2b2c8e <png_write_find_filter+0x2b6>
 *   @0x2b2caa adds r0, r4, r3
 *   @0x2b2cae add r12, r3
 *   @0x2b2cb2 add r12, r1
 *   @0x2b2cba adds r1, r0, r1
 *   @0x2b2cbe ldr r1, [sp, #0xc]
 *   @0x2b2cc2 bhs 0x2b2d10 <png_write_find_filter+0x338>
 *   @0x2b2cd2 ldrb r1, [r1, #0x1]
 *   @0x2b2cd6 subs r6, r1, r2
 *   @0x2b2cea cmp r6, #0x0
 *   @0x2b2cee rsblt r6, r6, #0
 *   @0x2b2cf2 bgt 0x2b2cf8 <png_write_find_filter+0x320>
 *   @0x2b2cf6 ble 0x2b2d00 <png_write_find_filter+0x328>
 *   @0x2b2cfa it le
 *   @0x2b2cfe b 0x2b2d02 <png_write_find_filter+0x32a>
 *   @0x2b2d02 ldr r0, [sp, #0x4]
 *   @0x2b2d06 subs r2, r1, r2
 *   @0x2b2d0e b 0x2b2cbe <png_write_find_filter+0x2e6>
 *   @0x2b2d16 b 0x2b2dee <png_write_find_filter+0x416>
 *   @0x2b2d1a bpl 0x2b2dee <png_write_find_filter+0x416>
 *   @0x2b2d26 movs r0, #0x0
 *   @0x2b2d2e add.w r8, r4, #0x1
 *   @0x2b2d32 movs r4, #0x1
 *   @0x2b2d36 ldr.w r12, [sp, #0x10]
 *   @0x2b2d3a cmp r4, r12
 *   @0x2b2d3e ldr r6, [sp, #0x4]
 *   @0x2b2d46 rsb r7, r7, r12
 *   @0x2b2d4a uxtb r7, r7
 *   @0x2b2d4e cmp r7, #0x7f
 *   @0x2b2d56 rsbgt.w r7, r7, #0x100
 *   @0x2b2d5a add r0, r7
 *   @0x2b2d5e rsbs r4, r3, #0
 *   @0x2b2d62 add r10, r3
 *   @0x2b2d66 add r9, r4
 *   @0x2b2d6a add r8, r3
 *   @0x2b2d6e add r8, r4
 *   @0x2b2d72 str.w r8, [sp, #0x10]
 *   @0x2b2d76 str r5, [sp, #0x4]
 *   @0x2b2d7a ldr r2, [sp, #0xc]
 *   @0x2b2d7e bhs 0x2b2de4 <png_write_find_filter+0x40c>
 *   @0x2b2d82 ldr r4, [sp, #0x14]
 *   @0x2b2d86 add r2, r3
 *   @0x2b2d8a ldrb r2, [r2, #0x1]
 *   @0x2b2d8e ldrb r4, [r4, #0x1]
 *   @0x2b2daa cmp.w r12, #0x0
 *   @0x2b2dae it lt
 *   @0x2b2db6 bgt 0x2b2dbc <png_write_find_filter+0x3e4>
 *   @0x2b2dba ble 0x2b2dc4 <png_write_find_filter+0x3ec>
 *   @0x2b2dbe it le
 *   @0x2b2dc2 b 0x2b2dc6 <png_write_find_filter+0x3ee>
 *   @0x2b2dc6 ldrb.w r4, [r9, r3]
 *   @0x2b2dca subs r2, r4, r2
 *   @0x2b2dce strb.w r2, [r10, r3]
 *   @0x2b2dd2 cmp r2, #0x7f
 *   @0x2b2dd6 rsbgt.w r2, r2, #0x100
 *   @0x2b2dda add r0, r2
 *   @0x2b2dde bhi 0x2b2dee <png_write_find_filter+0x416>
 *   @0x2b2de2 b 0x2b2d7a <png_write_find_filter+0x3a2>
 *   @0x2b2de6 itt lo
 *   @0x2b2dee mov r0, r11
 *   @0x2b2df2 add sp, #0x1c
 *
 * ══ anon_2b33a4  0x2b33a4  size 256  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b34a4 0x2b34a8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b34a4 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ anon_2b389c  0x2b389c  size 1600  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b3edc 0x2b3ee0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b3edc b 0x2b3e30 <jpeg_finish_output+0x640>
 *
 * ══ anon_2b3f58  0x2b3f58  size 7748  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b5d9c 0x2b5da0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b5d9c b 0x2b5d08 <jinit_input_controller+0x1e28>
 *
 * ══ anon_2b60ec  0x2b60ec  size 748  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b63d8 0x2b63dc  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b63d8 bx lr
 *
 * ══ anon_2b6a38  0x2b6a38  size 1376  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b6f98 0x2b6f9c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b6f98 b 0x2b6f48 <jinit_master_decompress+0x870>
 *
 * ══ anon_2b7148  0x2b7148  size 3728  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b7fd8 0x2b7fdc  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b7fd8 andeq r8, sp, r8, lsr r0
 *
 * ══ anon_2b8084  0x2b8084  size 900  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b8408 0x2b840c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b8408 b 0x2b8354 <jinit_phuff_decoder+0x378>
 *
 * ══ anon_2b84e8  0x2b84e8  size 1508  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b8acc 0x2b8ad0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b8acc pop {r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ anon_2b8dc0  0x2b8dc0  size 508  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2b8fbc 0x2b8fc0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2b8fbc bl 0xb6688 <exit@plt>
 *
 * ══ anon_2b9054  0x2b9054  size 4188  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2ba0b0 0x2ba0b4  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2ba0b0 b 0x2b9f1c <jpeg_std_error+0xf5c>
 *
 * ══ anon_2ba268  0x2ba268  size 2756  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bad2c 0x2bad30  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bad2c .word 0xfffff874
 *
 * ══ anon_2bb0f8  0x2bb0f8  size 5464  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bc650 0x2bc654  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bc650 b 0x2bc360 <jinit_1pass_quantizer+0x1630>
 *
 * ══ anon_2bc92c  0x2bc92c  size 4208  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bd99c 0x2bd9a0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bd99c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anon_2be194  0x2be194  size 740  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2be478 0x2be47c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2be478 .word 0xfffffe74
 *
 * ══ anon_2be8b0  0x2be8b0  size 376  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bea28 0x2bea2c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bea28 b 0x2be8d4 <jpeg_make_d_derived_tbl+0x3c4>
 *
 * ══ anon_2bec94  0x2bec94  size 1284  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bf198 0x2bf19c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bf198 andseq r2, r3, r12, asr r12
 *
 * ══ anon_2bf200  0x2bf200  size 1552  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2bf810 0x2bf814  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2bf810 .word 0xfffffb9c
 *
 * ══ anon_2c1274  0x2c1274  size 260  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2c1378 0x2c137c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2c1378 b 0x2c1328 <jpeg_idct_1x1+0xe8>
 *
 * ══ anon_2c143c  0x2c143c  size 1520  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2c1a2c 0x2c1a30  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2c1a2c b 0x2c1820 <jpeg_mem_term+0x3e8>
 *
 * ══ anon_2c7f2c  0x2c7f2c  size 176  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2c7fdc 0x2c7fe0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2c7fdc b 0x2c7fb4 <_ZNSt4priv25__unguarded_linear_insertIP6b2PairS1_PFbRKS1_S4_EEEvT_T0_T1_+0xe4>
 *
 * ══ anon_2c811c  0x2c811c  size 480  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2c82fc 0x2c8300  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2c82fc pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ anon_2d48c0  0x2d48c0  size 204  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2d498c 0x2d4990  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2d498c andseq sp, r1, r4, lsl #4
 *
 * ══ anon_2d51e4  0x2d51e4  size 84  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2d5238 0x2d523c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2d5238 pop {r3, r4, r5, pc}
 *
 * ══ anon_2d85e0  0x2d85e0  size 1084  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2d8a1c 0x2d8a20  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2d8a1c andeq r0, r0, r0
 *
 * ══ anon_2d941c  0x2d941c  size 1092  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2d9860 0x2d9864  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2d9860 strmi r0, [r0, #-0x0]
 *
 * ══ anon_2de0f4  0x2de0f4  size 876  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2de460 0x2de464  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2de460 .word 0xff7fffff
 *
 * ══ anon_2e490c  0x2e490c  size 1036  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4d18 0x2e4d1c  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4d18 andeq r9, r10, r9, lsl #20
 *
 * ══ FT_RoundFix  0x2e4d1c  size 14  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4d26 0x2e4d2a  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4d26 lsls r0, r0, #0x10
 *
 * ══ FT_CeilFix  0x2e4d2a  size 12  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4d30 0x2e4d3c  size 12  3 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4d30 lsrs r0, r0, #0x10
 *   @0x2e4d34 bx lr
 *
 * ══ FT_FloorFix  0x2e4d36  size 6  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4d38 0x2e4d3c  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4d38 lsls r0, r0, #0x10
 *
 * ══ FT_MulDiv  0x2e4d3c  size 118  本节 26 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4d3e 0x2e4db2  size 116  26 条
 * 部分覆盖: 本节 26/55 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4d3e cmp r0, #0x0
 *   @0x2e4d42 rsblt r0, r0, #0
 *   @0x2e4d46 ite lt
 *   @0x2e4d4e cmp r1, #0x0
 *   @0x2e4d52 rsblt r5, r5, #0
 *   @0x2e4d56 cmp r2, #0x0
 *   @0x2e4d5a rsblt r4, r2, #0
 *   @0x2e4d5e cbz r4, 0x2e4da4 <FT_MulDiv+0x68>
 *   @0x2e4d62 adds r2, r1, r0
 *   @0x2e4d6a add.w r3, r3, #0x166
 *   @0x2e4d6e cmp r3, r2
 *   @0x2e4d72 mla r0, r0, r1, r6
 *   @0x2e4d76 b 0x2e4d90 <FT_MulDiv+0x54>
 *   @0x2e4d7a bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8>
 *   @0x2e4d7e ldr r1, [sp]
 *   @0x2e4d82 adds r1, r6, r1
 *   @0x2e4d86 movlo r0, #0x0
 *   @0x2e4d8a adds r0, r0, r3
 *   @0x2e4d8e mov r0, r1
 *   @0x2e4d92 blx 0x318c48 <__udivsi3>
 *   @0x2e4d96 b 0x2e4da8 <FT_MulDiv+0x6c>
 *   @0x2e4d9a bhs 0x2e4da4 <FT_MulDiv+0x68>
 *   @0x2e4d9e bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a>
 *   @0x2e4da2 b 0x2e4da8 <FT_MulDiv+0x6c>
 *   @0x2e4daa it eq
 *   @0x2e4dae add sp, #0x8
 *
 * ══ anon_2e4db4  0x2e4db4  size 52  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4de8 0x2e4dec  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4de8 ldcllt p0, c2, [r8, #0]!
 *
 * ══ FT_MulDiv_No_Round  0x2e4dec  size 96  本节 22 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e4dee 0x2e4e4e  size 96  22 条
 * 部分覆盖: 本节 22/46 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4dee cmp r0, #0x0
 *   @0x2e4df2 rsblt r0, r0, #0
 *   @0x2e4df6 ite lt
 *   @0x2e4dfe cmp r1, #0x0
 *   @0x2e4e02 rsblt r5, r5, #0
 *   @0x2e4e06 cmp r2, #0x0
 *   @0x2e4e0a rsblt r4, r2, #0
 *   @0x2e4e0e cbz r4, 0x2e4e3e <FT_MulDiv_No_Round+0x52>
 *   @0x2e4e12 cmp.w r3, #0x20000
 *   @0x2e4e16 bhs 0x2e4e1c <FT_MulDiv_No_Round+0x30>
 *   @0x2e4e1a b 0x2e4e28 <FT_MulDiv_No_Round+0x3c>
 *   @0x2e4e1e bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8>
 *   @0x2e4e22 ldr r0, [sp, #0x4]
 *   @0x2e4e26 ldr r0, [sp]
 *   @0x2e4e2a blx 0x318c48 <__udivsi3>
 *   @0x2e4e2e b 0x2e4e42 <FT_MulDiv_No_Round+0x56>
 *   @0x2e4e32 ldr r1, [sp]
 *   @0x2e4e36 mov r2, r4
 *   @0x2e4e3e mvn r0, #0x80000000
 *   @0x2e4e42 adds r5, #0x1
 *   @0x2e4e46 rsbeq r0, r0, #0
 *   @0x2e4e4a pop {r4, r5, pc}
 *
 * ══ FT_MulFix  0x2e4e4c  size 28  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4e5a 0x2e4e6a  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4e5a adc r2, r2, #0x0
 *   @0x2e4e5e lsr.w r0, r3, #0x10
 *   @0x2e4e62 orr.w r0, r0, r2, lsl #16
 *   @0x2e4e66 bx lr
 *
 * ══ anon_2e4e68  0x2e4e68  size 76  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e4eb4 0x2e4ec8  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4eb4 mcrne p13, #0x0, r11, c3, c8, #0x1
 *
 * ══ FT_DivFix  0x2e4eb6  size 88  本节 20 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e4eb8 0x2e4f10  size 88  20 条
 * 部分覆盖: 本节 20/42 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4eb8 mov r2, r1
 *   @0x2e4ebc itte lt
 *   @0x2e4ec0 movlt.w r4, #0xffffffff
 *   @0x2e4ec4 movge r4, #0x1
 *   @0x2e4ec8 itt lt
 *   @0x2e4ecc rsblt r4, r4, #0
 *   @0x2e4ed0 lsrs r1, r2, #0x11
 *   @0x2e4ed4 rsb.w r1, r1, #0xff00
 *   @0x2e4ed8 adds r1, #0xff
 *   @0x2e4edc lsr.w r1, r2, #0x1
 *   @0x2e4ee0 blo 0x2e4eec <FT_DivFix+0x36>
 *   @0x2e4ee4 mov r1, r2
 *   @0x2e4eec adds r1, r1, r0
 *   @0x2e4ef0 movlo r0, #0x0
 *   @0x2e4ef4 add.w r0, r0, r3, lsr #16
 *   @0x2e4ef8 cmp r0, r2
 *   @0x2e4efc bl 0x2e4c3e <_ZNK11b2GearJoint8GetRatioEv+0x33a>
 *   @0x2e4f00 b 0x2e4f06 <FT_DivFix+0x50>
 *   @0x2e4f08 it eq
 *   @0x2e4f0c pop {r4, pc}
 *
 * ══ FT_Matrix_Multiply  0x2e4f0e  size 110  本节 22 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e4f14 0x2e4f7c  size 104  22 条
 * 部分覆盖: 本节 22/48 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4f14 mov r5, r0
 *   @0x2e4f18 beq 0x2e4f78 <FT_Matrix_Multiply+0x6a>
 *   @0x2e4f1c beq 0x2e4f78 <FT_Matrix_Multiply+0x6a>
 *   @0x2e4f20 ldr r0, [r0]
 *   @0x2e4f28 mov r8, r0
 *   @0x2e4f2c bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f30 ldr r1, [r4, #0x4]
 *   @0x2e4f34 ldr r0, [r5]
 *   @0x2e4f3c mov r7, r0
 *   @0x2e4f40 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f44 ldr r1, [r4]
 *   @0x2e4f48 ldr r0, [r5, #0x8]
 *   @0x2e4f50 mov r6, r0
 *   @0x2e4f54 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f58 ldr r1, [r4, #0x4]
 *   @0x2e4f5c ldr r0, [r5, #0x8]
 *   @0x2e4f64 mov r9, r0
 *   @0x2e4f68 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f6c str.w r8, [r4]
 *   @0x2e4f70 str r7, [r4, #0x4]
 *   @0x2e4f74 add r0, r9
 *   @0x2e4f78 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ FT_Matrix_Invert  0x2e4f7c  size 82  本节 16 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e4f7e 0x2e4fce  size 80  16 条
 * 部分覆盖: 本节 16/36 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4f7e mov r4, r0
 *   @0x2e4f82 movs r0, #0x6
 *   @0x2e4f86 ldr r1, [r4, #0xc]
 *   @0x2e4f8a bl 0x2e4e4c <FT_MulFix>
 *   @0x2e4f8e ldr r1, [r4, #0x8]
 *   @0x2e4f92 ldr r0, [r4, #0x4]
 *   @0x2e4f9a beq 0x2e4f82 <FT_Matrix_Invert+0x6>
 *   @0x2e4f9e ldr r0, [r4, #0x4]
 *   @0x2e4fa6 rsbs r0, r0, #0
 *   @0x2e4faa ldr r0, [r4, #0x8]
 *   @0x2e4fb2 ldr r6, [r4]
 *   @0x2e4fb6 str r0, [r4, #0x8]
 *   @0x2e4fba bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e4fbe mov r1, r5
 *   @0x2e4fc2 mov r0, r6
 *   @0x2e4fca movs r0, #0x0
 *
 * ══ FT_Matrix_Multiply_Scaled  0x2e4fce  size 130  本节 21 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e4fd4 0x2e5050  size 124  21 条
 * 部分覆盖: 本节 21/52 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e4fd4 mov r5, r0
 *   @0x2e4fd8 beq 0x2e504c <FT_Matrix_Multiply_Scaled+0x7e>
 *   @0x2e4fdc beq 0x2e504c <FT_Matrix_Multiply_Scaled+0x7e>
 *   @0x2e4fe0 ldr r1, [r1]
 *   @0x2e4fe4 mov r2, r6
 *   @0x2e4fec mov r2, r6
 *   @0x2e4ff0 ldr r0, [r5, #0x4]
 *   @0x2e4ff8 mov r2, r6
 *   @0x2e4ffc ldr r0, [r5]
 *   @0x2e5004 mov r2, r6
 *   @0x2e5008 ldr r0, [r5, #0x4]
 *   @0x2e5010 mov r2, r6
 *   @0x2e5014 ldr r0, [r5, #0x8]
 *   @0x2e501c mov r2, r6
 *   @0x2e5020 ldr r0, [r5, #0xc]
 *   @0x2e5028 mov r2, r6
 *   @0x2e502c ldr r0, [r5, #0x8]
 *   @0x2e5034 mov r2, r6
 *   @0x2e5038 ldr r0, [r5, #0xc]
 *   @0x2e5048 add r0, r10
 *   @0x2e504c pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ FT_Vector_Transform_Scaled  0x2e5050  size 70  本节 12 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5056 0x2e5096  size 64  12 条
 * 部分覆盖: 本节 12/28 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5056 mov r4, r0
 *   @0x2e505a cbz r1, 0x2e5092 <FT_Vector_Transform_Scaled+0x42>
 *   @0x2e505e ldr r1, [r1]
 *   @0x2e5062 mov r2, r6
 *   @0x2e506a mov r2, r6
 *   @0x2e506e ldr r0, [r4, #0x4]
 *   @0x2e5076 mov r2, r6
 *   @0x2e507a ldr r0, [r4]
 *   @0x2e5082 mov r2, r6
 *   @0x2e5086 ldr r0, [r4, #0x4]
 *   @0x2e508e add r0, r8
 *   @0x2e5092 pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ FT_Vector_NormLen  0x2e5096  size 300  本节 41 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e50a0 0x2e51d6  size 310  46 条
 * 部分覆盖: 本节 46/123 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 45/121 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 44/119 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 43/117 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 42/115 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e50a0 itte lt
 *   @0x2e50a4 movlt.w r8, #0xffffffff
 *   @0x2e50a8 movge.w r8, #0x1
 *   @0x2e50ac cmp r3, #0x0
 *   @0x2e50b0 rsblt r3, r3, #0
 *   @0x2e50bc cmp r3, #0x0
 *   @0x2e50c0 lsl.w r2, r12, #0x10
 *   @0x2e50c4 str r2, [r0, #0x4]
 *   @0x2e50c8 cbnz r3, 0x2e50d6 <FT_Vector_NormLen+0x40>
 *   @0x2e50d0 mov r0, r2
 *   @0x2e50d8 mov.w r1, #0xaaaaaaaa
 *   @0x2e50dc ite hi
 *   @0x2e50ec cmp r4, r1
 *   @0x2e50f0 movlo r1, #0xf
 *   @0x2e50f4 subs r1, r5, r1
 *   @0x2e50f8 ble 0x2e510c <FT_Vector_NormLen+0x76>
 *   @0x2e50fc lsls r3, r1
 *   @0x2e5100 ite hi
 *   @0x2e510c rsbs r6, r1, #0
 *   @0x2e5110 lsrs r3, r6
 *   @0x2e513c it lt
 *   @0x2e5148 rsb.w r10, r10, #0x0
 *   @0x2e514c mov r4, r10
 *   @0x2e5150 it mi
 *   @0x2e5158 it mi
 *   @0x2e5164 add r6, r7
 *   @0x2e5168 muls r2, r5, r2
 *   @0x2e5174 rsbeq r6, r5, #0
 *   @0x2e5178 cmp.w r12, #0xffffffff
 *   @0x2e517c str r6, [r0]
 *   @0x2e5180 rsbeq.w r6, r11, #0x0
 *   @0x2e5184 movne r6, r11
 *   @0x2e5188 it lt
 *   @0x2e5190 it lt
 *   @0x2e5194 cmp r1, #0x0
 *   @0x2e51a0 subs r2, r1, #0x1
 *   @0x2e51a4 lsl.w r2, r0, r2
 *   @0x2e51a8 add r3, r2
 *   @0x2e51b4 lsl.w r0, r3, r1
 *   @0x2e51b8 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e51bc mov r0, r3
 *
 * ══ anon_2e51c2  0x2e51c2  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e51c2 0x2e51d6  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e51c2 ldrblt r0, [pc, #-0x0]!
 *
 * ══ ft_corner_orientation  0x2e51c4  size 132  本节 29 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e51c6 0x2e5246  size 128  29 条
 * 部分覆盖: 本节 29/61 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e51c6 mov r5, r1
 *   @0x2e51ca eor.w r1, r0, r0, asr #31
 *   @0x2e51ce sub.w r1, r1, r0, asr #31
 *   @0x2e51d2 eor.w r2, r3, r3, asr #31
 *   @0x2e51d6 sub.w r2, r2, r3, asr #31
 *   @0x2e51da add r1, r2
 *   @0x2e51de cmp r1, r2
 *   @0x2e51e2 eor.w r6, r5, r5, asr #31
 *   @0x2e51e6 sub.w r6, r6, r5, asr #31
 *   @0x2e51ea eor.w r1, r4, r4, asr #31
 *   @0x2e51ee sub.w r1, r1, r4, asr #31
 *   @0x2e51f2 add r1, r6
 *   @0x2e51f6 bhi 0x2e520a <ft_corner_orientation+0x46>
 *   @0x2e51fa muls r4, r5, r4
 *   @0x2e51fe bgt 0x2e523e <ft_corner_orientation+0x7a>
 *   @0x2e5202 movge r0, #0x0
 *   @0x2e520a mov r1, r3
 *   @0x2e520e bl 0x2e490c <_ZNK11b2GearJoint8GetRatioEv+0x8>
 *   @0x2e5212 add r2, sp, #0x8
 *   @0x2e5216 mov r1, r4
 *   @0x2e521e ldr r2, [sp, #0x4]
 *   @0x2e5222 bhi 0x2e523e <ft_corner_orientation+0x7a>
 *   @0x2e5226 ldr r3, [sp, #0x8]
 *   @0x2e522a cmp r2, r3
 *   @0x2e522e ite hs
 *   @0x2e5232 mvnlo r0, #0x0
 *   @0x2e5236 b 0x2e5240 <ft_corner_orientation+0x7c>
 *   @0x2e523e movs r0, #0x1
 *   @0x2e5242 pop {r4, r5, r6, pc}
 *
 * ══ ft_corner_is_flat  0x2e5248  size 116  本节 25 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e524a 0x2e52c6  size 124  27 条
 * 部分覆盖: 本节 26/56 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/54 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e524a adds r6, r0, r2
 *   @0x2e524e cmp r0, #0x0
 *   @0x2e5252 rsblt r0, r0, #0
 *   @0x2e5256 it lt
 *   @0x2e525a movs r4, #0x3
 *   @0x2e525e ite gt
 *   @0x2e5262 mulle r0, r4, r0
 *   @0x2e526a addgt.w r1, r0, r1, asr #3
 *   @0x2e526e addle.w r1, r1, r0, asr #3
 *   @0x2e5272 cmp r2, #0x0
 *   @0x2e5276 rsblt r2, r2, #0
 *   @0x2e527a it lt
 *   @0x2e527e movs r0, #0x3
 *   @0x2e5282 itete gt
 *   @0x2e5286 mulle r2, r0, r2
 *   @0x2e5292 it lt
 *   @0x2e5296 cmp r5, #0x0
 *   @0x2e529a rsblt r5, r5, #0
 *   @0x2e529e cmp r6, r5
 *   @0x2e52a2 mulgt r4, r5, r4
 *   @0x2e52a6 addgt.w r4, r6, r4, asr #3
 *   @0x2e52aa addle.w r4, r5, r4, asr #3
 *   @0x2e52ae subs r3, r3, r4
 *   @0x2e52b6 movge r0, #0x0
 *   @0x2e52ba pop {r4, r5, r6, pc}
 *
 * ══ FT_GlyphLoader_Rewind  0x2e52bc  size 32  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e52be 0x2e52ea  size 44  10 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e52be add.w r5, r0, #0x14
 *   @0x2e52c2 movs r3, #0x0
 *   @0x2e52ca strh r3, [r0, #0x14]
 *   @0x2e52ce ldm r5!, {r0, r1, r2, r3}
 *   @0x2e52d2 ldm r5!, {r0, r1, r2, r3}
 *   @0x2e52d6 ldr r3, [r5]
 *   @0x2e52da pop {r4, r5, pc}
 *
 * ══ FT_GlyphLoader_Prepare  0x2e52dc  size 28  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e52de 0x2e530a  size 44  9 条
 * 部分覆盖: 本节 5/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e52de strh r3, [r0, #0x3a]
 *   @0x2e52e2 mov r4, r0
 *   @0x2e52e6 str r3, [r0, #0x54]
 *   @0x2e52ee ldr r3, [r4, #0x34]
 *   @0x2e52f6 pop {r4, pc}
 *
 * ══ FT_GlyphLoader_Add  0x2e52f8  size 62  本节 12 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e52fa 0x2e532e  size 52  12 条
 * 部分覆盖: 本节 12/25 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e52fa cbz r0, 0x2e5334 <FT_GlyphLoader_Add+0x3c>
 *   @0x2e52fe ldrh r1, [r0, #0x3a]
 *   @0x2e5302 add r1, r2
 *   @0x2e5306 ldrh r1, [r0, #0x14]
 *   @0x2e530a add r3, r1
 *   @0x2e530e strh r3, [r0, #0x14]
 *   @0x2e5312 add r3, r1
 *   @0x2e5316 movs r3, #0x0
 *   @0x2e531a bge 0x2e532c <FT_GlyphLoader_Add+0x34>
 *   @0x2e531e ldrh.w r5, [r1, r3, lsl #1]
 *   @0x2e5322 add r5, r2
 *   @0x2e532a b 0x2e5318 <FT_GlyphLoader_Add+0x20>
 *
 * ══ ft_hash_str_lookup  0x2e5336  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5338 0x2e5344  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5338 bl 0x2e49b8 <_ZNK11b2GearJoint8GetRatioEv+0xb4>
 *   @0x2e533c ldr r0, [r0]
 *   @0x2e5340 adds r0, #0x4
 *
 * ══ ft_hash_num_lookup  0x2e5344  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5346 0x2e5352  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5346 bl 0x2e49b8 <_ZNK11b2GearJoint8GetRatioEv+0xb4>
 *   @0x2e534a ldr r0, [r0]
 *   @0x2e534e adds r0, #0x4
 *
 * ══ ft_service_list_lookup  0x2e5352  size 38  本节 8 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e5354 0x2e5378  size 36  8 条
 * 部分覆盖: 本节 8/17 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5354 mov r5, r1
 *   @0x2e5358 cbz r0, 0x2e5372 <ft_service_list_lookup+0x20>
 *   @0x2e535c ldr r0, [r4]
 *   @0x2e5360 mov r1, r5
 *   @0x2e5368 ldr r0, [r4, #0x4]
 *   @0x2e536c adds r4, #0x8
 *   @0x2e5370 pop {r3, r4, r5, pc}
 *   @0x2e5374 mov r0, r1
 *
 * ══ ft_validator_init  0x2e5378  size 20  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5386 0x2e538e  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5386 str.w r3, [r0, #0x10c]
 *   @0x2e538a bx lr
 *
 * ══ ft_validator_error  0x2e5392  size 12  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5398 0x2e539c  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5398 push {r3, lr}
 *
 * ══ FT_Set_Transform  0x2e539e  size 114  本节 22 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e53a0 0x2e5410  size 112  22 条
 * 部分覆盖: 本节 22/50 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e53a0 mov r5, r1
 *   @0x2e53a4 cmp r0, #0x0
 *   @0x2e53a8 ldr.w r4, [r0, #0x80]
 *   @0x2e53ac movs r3, #0x0
 *   @0x2e53b0 cbnz r1, 0x2e53c2 <FT_Set_Transform+0x24>
 *   @0x2e53b8 stm.w r4, {r3, r5}
 *   @0x2e53bc mov r5, r4
 *   @0x2e53c0 b 0x2e53c8 <FT_Set_Transform+0x2a>
 *   @0x2e53c4 stm.w r4, {r0, r1, r2, r3}
 *   @0x2e53c8 ldr r2, [r5, #0x8]
 *   @0x2e53cc orrs r3, r2
 *   @0x2e53d0 ldr r3, [r5]
 *   @0x2e53d8 ldr r3, [r5, #0xc]
 *   @0x2e53e0 ldr r3, [r4, #0x18]
 *   @0x2e53e8 add.w r3, r4, #0x10
 *   @0x2e53ec cbnz r6, 0x2e53f6 <FT_Set_Transform+0x58>
 *   @0x2e53f0 str r6, [r4, #0x14]
 *   @0x2e53f4 b 0x2e53fe <FT_Set_Transform+0x60>
 *   @0x2e5400 ldr r3, [r6]
 *   @0x2e5404 beq 0x2e540e <FT_Set_Transform+0x70>
 *   @0x2e5408 orr r3, r3, #0x2
 *   @0x2e540c str r3, [r4, #0x18]
 *
 * ══ FT_Reference_Face  0x2e5410  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5412 0x2e5426  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5412 ldr.w r3, [r0, #0x80]
 *   @0x2e5416 movs r0, #0x0
 *   @0x2e541a adds r2, #0x1
 *   @0x2e541e bx lr
 *   @0x2e5422 bx lr
 *
 * ══ FT_Match_Size  0x2e5424  size 188  本节 40 条（Thumb-2 半字段）｜入度 10
 * @func 0x2e542a 0x2e54de  size 180  40 条
 * 部分覆盖: 本节 40/85 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e542a ldr r3, [r0, #0x8]
 *   @0x2e542e mov r4, r1
 *   @0x2e5432 lsls r3, r3, #0x1e
 *   @0x2e5436 ldr r3, [r1]
 *   @0x2e543a bne 0x2e54d4 <FT_Match_Size+0xb0>
 *   @0x2e543e ldr.w r9, [r1, #0x4]
 *   @0x2e5442 cbz r0, 0x2e5454 <FT_Match_Size+0x30>
 *   @0x2e544a adds r0, #0x24
 *   @0x2e5452 b 0x2e5456 <FT_Match_Size+0x32>
 *   @0x2e5456 ldr r0, [r4, #0x10]
 *   @0x2e545a cbz r0, 0x2e5468 <FT_Match_Size+0x44>
 *   @0x2e545e movs r1, #0x48
 *   @0x2e5462 blx 0x318d10 <__divsi3>
 *   @0x2e5466 b 0x2e546a <FT_Match_Size+0x46>
 *   @0x2e546a cmp.w r9, #0x0
 *   @0x2e546e beq 0x2e5478 <FT_Match_Size+0x54>
 *   @0x2e5472 it eq
 *   @0x2e5476 b 0x2e547e <FT_Match_Size+0x5a>
 *   @0x2e547a it ne
 *   @0x2e547e adds r5, #0x20
 *   @0x2e5486 add.w r1, r0, #0x20
 *   @0x2e548a bics r4, r1, #0x3f
 *   @0x2e548e beq 0x2e54da <FT_Match_Size+0xb6>
 *   @0x2e5492 movs r1, #0x0
 *   @0x2e5496 bge 0x2e54da <FT_Match_Size+0xb6>
 *   @0x2e549a add.w r3, r3, r1, lsl #4
 *   @0x2e549e ldr r2, [r3, #0xc]
 *   @0x2e54a2 bic r2, r2, #0x3f
 *   @0x2e54a6 cmp r4, r2
 *   @0x2e54aa ldr r3, [r3, #0x8]
 *   @0x2e54ae bic r3, r3, #0x3f
 *   @0x2e54b2 cmp r5, r3
 *   @0x2e54b6 cbz r7, 0x2e54c4 <FT_Match_Size+0xa0>
 *   @0x2e54ba b 0x2e54c4 <FT_Match_Size+0xa0>
 *   @0x2e54c2 b 0x2e54b6 <FT_Match_Size+0x92>
 *   @0x2e54c6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e54ca adds r1, #0x1
 *   @0x2e54ce movs r0, #0x23
 *   @0x2e54d6 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e54da movs r0, #0x17
 *
 * ══ ft_synthesize_vertical_metrics  0x2e54e0  size 68  本节 15 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e54e2 0x2e5536  size 84  19 条
 * 部分覆盖: 本节 19/40 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 15/32 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e54e2 mov r4, r0
 *   @0x2e54e6 ldr r5, [r0, #0x4]
 *   @0x2e54ea bge 0x2e54f4 <ft_synthesize_vertical_metrics+0x14>
 *   @0x2e54ee it lt
 *   @0x2e54f2 b 0x2e54fa <ft_synthesize_vertical_metrics+0x1a>
 *   @0x2e54f6 rsbne r5, r3, r5
 *   @0x2e54fa cbnz r1, 0x2e5508 <ft_synthesize_vertical_metrics+0x28>
 *   @0x2e54fe movs r1, #0xa
 *   @0x2e5502 blx 0x318d10 <__divsi3>
 *   @0x2e5506 mov r1, r0
 *   @0x2e550a subs r5, r1, r5
 *   @0x2e550e add.w r5, r5, r5, lsr #31
 *   @0x2e5512 str r1, [r4, #0x1c]
 *   @0x2e551a str r5, [r4, #0x18]
 *   @0x2e5522 pop {r3, r4, r5, pc}
 *
 * ══ FT_Select_Metrics  0x2e5524  size 100  本节 23 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e5526 0x2e558a  size 100  23 条
 * 部分覆盖: 本节 23/48 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5526 lsls r1, r1, #0x4
 *   @0x2e552a mov r6, r0
 *   @0x2e552e adds r5, r2, r1
 *   @0x2e5532 adds r3, #0x20
 *   @0x2e5536 strh r3, [r4, #0xc]
 *   @0x2e553a adds r3, #0x20
 *   @0x2e553e strh r3, [r4, #0xe]
 *   @0x2e5542 ands r3, r3, #0x1
 *   @0x2e5546 beq 0x2e556e <FT_Select_Metrics+0x4a>
 *   @0x2e554e bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e5552 str r0, [r4, #0x10]
 *   @0x2e555a bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e555e add.w r1, r4, #0xc
 *   @0x2e5562 str r0, [r4, #0x14]
 *   @0x2e5566 pop.w {r4, r5, r6, lr}
 *   @0x2e556a b.w 0x2e4e68 <FT_MulFix+0x1c>
 *   @0x2e556e mov.w r0, #0x10000
 *   @0x2e5572 str r0, [r4, #0x10]
 *   @0x2e5576 ldr r0, [r5, #0xc]
 *   @0x2e557a str r0, [r4, #0x18]
 *   @0x2e557e lsls r3, r3, #0x6
 *   @0x2e5582 ldr r3, [r5, #0x8]
 *   @0x2e5586 pop {r4, r5, r6, pc}
 *
 * ══ FT_Request_Metrics  0x2e5588  size 370  本节 71 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e558e 0x2e56fa  size 364  71 条
 * 部分覆盖: 本节 71/162 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e558e ldr r1, [r0, #0x8]
 *   @0x2e5592 ldr r4, [r0, #0x58]
 *   @0x2e55a6 bhi.w 0x2e56f2 <FT_Request_Metrics+0x16a>
 *   @0x2e55aa tbb [pc, r2]
 *   @0x2e55ae lsls r3, r0, #0x18
 *   @0x2e55b2 movs r0, r4
 *   @0x2e55ba ldrsh.w r9, [r5, #0x46]
 *   @0x2e55be ldrsh.w r2, [r5, #0x48]
 *   @0x2e55c2 rsb r9, r2, r9
 *   @0x2e55c6 mov r10, r9
 *   @0x2e55ca ldr r1, [r5, #0x3c]
 *   @0x2e55ce rsb r9, r2, r1
 *   @0x2e55d2 ldr r1, [r5, #0x40]
 *   @0x2e55d6 rsb r10, r2, r1
 *   @0x2e55da b 0x2e5604 <FT_Request_Metrics+0x7c>
 *   @0x2e55ee str r3, [r4, #0x10]
 *   @0x2e55f2 str r6, [r4, #0x14]
 *   @0x2e55f6 str r6, [r4, #0x10]
 *   @0x2e55fa b 0x2e569e <FT_Request_Metrics+0x116>
 *   @0x2e55fe bne 0x2e569c <FT_Request_Metrics+0x114>
 *   @0x2e5602 b 0x2e569e <FT_Request_Metrics+0x116>
 *   @0x2e560a rsblt.w r9, r9, #0x0
 *   @0x2e560e ldr r0, [r7, #0xc]
 *   @0x2e5616 rsblt.w r10, r10, #0x0
 *   @0x2e561a cbz r0, 0x2e562e <FT_Request_Metrics+0xa6>
 *   @0x2e561e movs r1, #0x48
 *   @0x2e5622 adds r0, #0x24
 *   @0x2e562a mov r8, r0
 *   @0x2e562e mov r8, r3
 *   @0x2e5632 ldr r6, [r7, #0x8]
 *   @0x2e5636 muls r0, r6, r0
 *   @0x2e563a str r3, [sp, #0x4]
 *   @0x2e563e blx 0x318d10 <__divsi3>
 *   @0x2e5642 ldr r3, [sp, #0x4]
 *   @0x2e5646 cbz r3, 0x2e5682 <FT_Request_Metrics+0xfa>
 *   @0x2e564a mov r1, r9
 *   @0x2e5652 ldr r3, [r7, #0x8]
 *   @0x2e5656 mov r0, r6
 *   @0x2e565a bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e565e str r0, [r4, #0x14]
 *   @0x2e5662 cmp r3, #0x3
 *   @0x2e5666 ldr r3, [r4, #0x10]
 *   @0x2e566a ite le
 *   @0x2e566e strgt r3, [r4, #0x14]
 *   @0x2e5672 str r0, [r4, #0x14]
 *   @0x2e5676 mov r0, r8
 *   @0x2e567a bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e567e mov r6, r0
 *   @0x2e5682 mov r1, r10
 *   @0x2e5686 bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e568a mov r1, r9
 *   @0x2e568e str r0, [r4, #0x14]
 *   @0x2e5692 mov r0, r6
 *   @0x2e569a b 0x2e56a0 <FT_Request_Metrics+0x118>
 *   @0x2e569e mov r8, r6
 *   @0x2e56a2 cbz r3, 0x2e56bc <FT_Request_Metrics+0x134>
 *   @0x2e56a6 ldrh.w r0, [r5, #0x44]
 *   @0x2e56aa bl 0x2e4e4c <FT_MulFix>
 *   @0x2e56ae ldr r1, [r4, #0x14]
 *   @0x2e56b2 ldrh.w r0, [r5, #0x44]
 *   @0x2e56b6 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e56ba mov r6, r0
 *   @0x2e56c2 mov r0, r5
 *   @0x2e56c6 asr.w r8, r8, #0x6
 *   @0x2e56ca asrs r6, r6, #0x6
 *   @0x2e56d2 add sp, #0xc
 *   @0x2e56de movs r2, #0x1c
 *   @0x2e56ea str r3, [r4, #0x14]
 *   @0x2e56ee pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e56f2 mov.w r9, #0x0
 *   @0x2e56f6 mov r10, r9
 *
 * ══ FT_Select_Size  0x2e56fa  size 50  本节 12 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e56fc 0x2e572c  size 48  12 条
 * 部分覆盖: 本节 12/24 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e56fc cbz r0, 0x2e5724 <FT_Select_Size+0x2a>
 *   @0x2e5700 lsls r4, r4, #0x1e
 *   @0x2e5704 cmp r1, #0x0
 *   @0x2e5708 ldr r4, [r0, #0x1c]
 *   @0x2e570c bge 0x2e5728 <FT_Select_Size+0x2e>
 *   @0x2e5710 ldr r2, [r2, #0xc]
 *   @0x2e5714 cbz r4, 0x2e571c <FT_Select_Size+0x22>
 *   @0x2e5718 blx r4
 *   @0x2e571c bl 0x2e5524 <FT_Select_Metrics>
 *   @0x2e5720 mov r0, r4
 *   @0x2e5724 movs r0, #0x23
 *   @0x2e5728 movs r0, #0x6
 *
 * ══ FT_Request_Size  0x2e572c  size 96  本节 23 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e572e 0x2e579e  size 112  27 条
 * 部分覆盖: 本节 27/55 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 26/53 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/51 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/49 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/47 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e572e mov r4, r0
 *   @0x2e5732 cbz r1, 0x2e5786 <FT_Request_Size+0x5a>
 *   @0x2e5736 cmp r2, #0x0
 *   @0x2e573a ldr r2, [r1, #0x8]
 *   @0x2e573e blt 0x2e5786 <FT_Request_Size+0x5a>
 *   @0x2e5742 cmp r3, #0x4
 *   @0x2e5746 ldr r3, [r0, #0x58]
 *   @0x2e574a ldr r3, [r3, #0x28]
 *   @0x2e574e ldr r3, [r0, #0x60]
 *   @0x2e5752 ldr r5, [r3, #0x58]
 *   @0x2e5756 ldr r0, [r0, #0x58]
 *   @0x2e575a b 0x2e5788 <FT_Request_Size+0x5c>
 *   @0x2e575e and r3, r3, #0x3
 *   @0x2e5762 cmp r3, #0x2
 *   @0x2e5766 mov r2, r5
 *   @0x2e576a bl 0x2e5424 <FT_Match_Size>
 *   @0x2e576e cbnz r0, 0x2e5788 <FT_Request_Size+0x5c>
 *   @0x2e5772 ldr r1, [sp, #0x4]
 *   @0x2e577a bl 0x2e5588 <FT_Request_Metrics>
 *   @0x2e577e mov r0, r5
 *   @0x2e5782 movs r0, #0x23
 *   @0x2e5786 movs r0, #0x6
 *   @0x2e578a pop {r4, r5, pc}
 *
 * ══ FT_Set_Char_Size  0x2e578c  size 70  本节 17 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e578e 0x2e57d2  size 68  17 条
 * 部分覆盖: 本节 17/34 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e578e sub sp, #0x1c
 *   @0x2e5792 cbz r1, 0x2e579c <FT_Set_Char_Size+0x10>
 *   @0x2e5796 it eq
 *   @0x2e579a b 0x2e579e <FT_Set_Char_Size+0x12>
 *   @0x2e579e cbz r3, 0x2e57a8 <FT_Set_Char_Size+0x1c>
 *   @0x2e57a2 it eq
 *   @0x2e57a6 b 0x2e57aa <FT_Set_Char_Size+0x1e>
 *   @0x2e57aa cmp r1, #0x40
 *   @0x2e57ae movlt r1, #0x40
 *   @0x2e57b2 it lt
 *   @0x2e57b6 cbnz r3, 0x2e57bc <FT_Set_Char_Size+0x30>
 *   @0x2e57ba mov r3, r4
 *   @0x2e57be add r1, sp, #0x4
 *   @0x2e57c2 str r2, [sp, #0xc]
 *   @0x2e57c6 str r3, [sp, #0x10]
 *   @0x2e57ca bl 0x2e572c <FT_Request_Size>
 *   @0x2e57ce add sp, #0x1c
 *
 * ══ FT_Set_Pixel_Sizes  0x2e57d2  size 74  本节 18 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e57d4 0x2e581c  size 72  18 条
 * 部分覆盖: 本节 18/36 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e57d4 movw r3, #0xfffe
 *   @0x2e57d8 sub sp, #0x18
 *   @0x2e57dc cmp r2, #0x0
 *   @0x2e57e0 moveq r2, r1
 *   @0x2e57e4 cbz r2, 0x2e57f4 <FT_Set_Pixel_Sizes+0x22>
 *   @0x2e57e8 movw r4, #0xffff
 *   @0x2e57ec cmp r1, r3
 *   @0x2e57f0 movhi r1, r4
 *   @0x2e57f4 movs r1, #0x1
 *   @0x2e57f8 movw r4, #0xffff
 *   @0x2e57fc cmp r2, r3
 *   @0x2e5800 movhi r2, r4
 *   @0x2e5804 str r1, [sp, #0x8]
 *   @0x2e5808 movs r3, #0x0
 *   @0x2e580c str r3, [sp, #0x4]
 *   @0x2e5810 str r3, [sp, #0x10]
 *   @0x2e5814 bl 0x2e572c <FT_Request_Size>
 *   @0x2e5818 add sp, #0x18
 *
 * ══ FT_Get_Kerning  0x2e581c  size 142  本节 33 条（Thumb-2 半字段）｜入度 6
 * @func 0x2e581e 0x2e58aa  size 140  33 条
 * 部分覆盖: 本节 33/68 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e581e mov r6, r3
 *   @0x2e5822 mov r5, r0
 *   @0x2e5826 beq 0x2e58a2 <FT_Get_Kerning+0x86>
 *   @0x2e582a beq 0x2e58a6 <FT_Get_Kerning+0x8a>
 *   @0x2e582e movs r3, #0x0
 *   @0x2e5832 str r3, [r4, #0x4]
 *   @0x2e5836 ldr r7, [r3, #0x4c]
 *   @0x2e583a beq 0x2e589e <FT_Get_Kerning+0x82>
 *   @0x2e583e blx r7
 *   @0x2e5842 bne 0x2e58a8 <FT_Get_Kerning+0x8c>
 *   @0x2e5846 beq 0x2e589e <FT_Get_Kerning+0x82>
 *   @0x2e584a ldr r0, [r4]
 *   @0x2e584e bl 0x2e4e4c <FT_MulFix>
 *   @0x2e5852 str r0, [r4]
 *   @0x2e5856 ldr r0, [r4, #0x4]
 *   @0x2e585a bl 0x2e4e4c <FT_MulFix>
 *   @0x2e585e cmp r6, #0x1
 *   @0x2e5862 str r0, [r4, #0x4]
 *   @0x2e5866 ldr r3, [r5, #0x58]
 *   @0x2e586a ldrh r1, [r3, #0xc]
 *   @0x2e586e bhi 0x2e5878 <FT_Get_Kerning+0x5c>
 *   @0x2e5872 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e5876 str r0, [r4]
 *   @0x2e587a ldrh r1, [r3, #0xe]
 *   @0x2e587e bhi 0x2e588a <FT_Get_Kerning+0x6e>
 *   @0x2e5882 movs r2, #0x19
 *   @0x2e588a ldr r3, [r4]
 *   @0x2e588e bic r3, r3, #0x3f
 *   @0x2e5892 str r3, [r4]
 *   @0x2e5896 adds r3, #0x20
 *   @0x2e589e movs r0, #0x0
 *   @0x2e58a2 movs r0, #0x23
 *   @0x2e58a6 movs r0, #0x6
 *
 * ══ FT_Get_Track_Kerning  0x2e58ac  size 72  本节 15 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e58b2 0x2e5906  size 84  19 条
 * 部分覆盖: 本节 19/40 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 15/32 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e58b2 mov r8, r2
 *   @0x2e58b6 mov r4, r0
 *   @0x2e58ba cbz r3, 0x2e58ea <FT_Get_Track_Kerning+0x3e>
 *   @0x2e58be ldr r3, [r0]
 *   @0x2e58c2 cbnz r3, 0x2e58ca <FT_Get_Track_Kerning+0x1e>
 *   @0x2e58c6 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e58ca ldr r1, [pc, #0x24]
 *   @0x2e58ce blx r3
 *   @0x2e58d2 beq 0x2e58c4 <FT_Get_Track_Kerning+0x18>
 *   @0x2e58d6 mov r1, r7
 *   @0x2e58da mov r2, r8
 *   @0x2e58de blx r6
 *   @0x2e58e6 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e58ea movs r0, #0x6
 *   @0x2e58f2 movs r2, r1
 *
 * ══ FT_Select_Charmap  0x2e58f4  size 68  本节 15 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e58f6 0x2e594a  size 84  19 条
 * 部分覆盖: 本节 19/40 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 15/32 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e58f6 mov r3, r0
 *   @0x2e58fa cbz r1, 0x2e592c <FT_Select_Charmap+0x38>
 *   @0x2e58fe cmp r1, r2
 *   @0x2e5902 pop.w {r4, r5, lr}
 *   @0x2e5906 b.w 0x2e49fc <_ZNK11b2GearJoint8GetRatioEv+0xf8>
 *   @0x2e590a ldr r2, [r0, #0x28]
 *   @0x2e590e ldr r0, [r0, #0x24]
 *   @0x2e5916 bhs 0x2e592c <FT_Select_Charmap+0x38>
 *   @0x2e591e cmp r4, r1
 *   @0x2e5922 str r0, [r3, #0x5c]
 *   @0x2e5926 pop {r4, r5, pc}
 *   @0x2e592a pop {r4, r5, pc}
 *   @0x2e592e pop {r4, r5, pc}
 *   @0x2e5932 pop {r4, r5, pc}
 *   @0x2e5936 strb r6, [r5, #0x15]
 *
 * ══ FT_Get_Charmap_Index  0x2e5938  size 40  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e593a 0x2e5972  size 56  14 条
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e593a cbz r0, 0x2e5956 <FT_Get_Charmap_Index+0x1e>
 *   @0x2e593e cbz r2, 0x2e5956 <FT_Get_Charmap_Index+0x1e>
 *   @0x2e5942 movs r3, #0x0
 *   @0x2e5946 bge 0x2e595c <FT_Get_Charmap_Index+0x24>
 *   @0x2e594a ldr.w r1, [r1, r3, lsl #2]
 *   @0x2e594e cmp r1, r0
 *   @0x2e5952 adds r3, #0x1
 *   @0x2e5956 mov.w r0, #0xffffffff
 *   @0x2e595a pop {r4, pc}
 *   @0x2e595e pop {r4, pc}
 *
 * ══ FT_Get_Char_Index  0x2e5960  size 30  本节 7 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5962 0x2e597e  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5962 mov r4, r0
 *   @0x2e5966 movs r0, #0x0
 *   @0x2e596a ldr r0, [r0, #0x5c]
 *   @0x2e596e beq 0x2e5966 <FT_Get_Char_Index+0x6>
 *   @0x2e5972 ldr r3, [r3, #0xc]
 *   @0x2e5976 ldr r3, [r4, #0x10]
 *   @0x2e597a bhs 0x2e5966 <FT_Get_Char_Index+0x6>
 *
 * ══ FT_Get_Next_Char  0x2e597e  size 62  本节 15 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5980 0x2e59bc  size 60  15 条
 * 部分覆盖: 本节 15/30 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5980 mov r7, r2
 *   @0x2e5984 cbz r0, 0x2e59ac <FT_Get_Next_Char+0x2e>
 *   @0x2e5988 cbz r5, 0x2e59b0 <FT_Get_Next_Char+0x32>
 *   @0x2e598c cbz r3, 0x2e59b2 <FT_Get_Next_Char+0x34>
 *   @0x2e5990 str r1, [r6, #-4]!
 *   @0x2e5994 ldr r3, [r5, #0xc]
 *   @0x2e5998 mov r1, r6
 *   @0x2e599c blx r3
 *   @0x2e59a0 cmp r0, r2
 *   @0x2e59a4 bhs 0x2e5994 <FT_Get_Next_Char+0x16>
 *   @0x2e59a8 ldr r0, [sp, #0x4]
 *   @0x2e59ac mov r3, r0
 *   @0x2e59b0 mov r3, r5
 *   @0x2e59b4 cbz r7, 0x2e59b8 <FT_Get_Next_Char+0x3a>
 *   @0x2e59b8 add sp, #0xc
 *
 * ══ FT_Get_First_Char  0x2e59bc  size 58  本节 12 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e59be 0x2e59f6  size 56  12 条
 * 部分覆盖: 本节 12/26 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e59be mov r5, r1
 *   @0x2e59c2 movs r1, #0x0
 *   @0x2e59c6 cbnz r0, 0x2e59cc <FT_Get_First_Char+0x10>
 *   @0x2e59ca b 0x2e59ec <FT_Get_First_Char+0x30>
 *   @0x2e59ce cmp r3, #0x0
 *   @0x2e59d2 ldr r3, [r0, #0x10]
 *   @0x2e59d6 beq 0x2e59c8 <FT_Get_First_Char+0xc>
 *   @0x2e59de str r0, [sp, #0x4]
 *   @0x2e59e2 bne 0x2e59c8 <FT_Get_First_Char+0xc>
 *   @0x2e59e6 add r2, sp, #0x4
 *   @0x2e59ee ldr r3, [sp, #0x4]
 *   @0x2e59f2 add sp, #0xc
 *
 * ══ FT_Face_Properties  0x2e59f8  size 168  本节 35 条（Thumb-2 半字段）｜入度 9
 * @func 0x2e59fe 0x2e5ab2  size 180  39 条
 * 部分覆盖: 本节 38/82 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 37/80 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 36/78 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 35/76 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e59fe adds r2, #0x8
 *   @0x2e5a06 mov.w r12, #0xffffffff
 *   @0x2e5a0a ldr r7, [pc, #0x8c]
 *   @0x2e5a0e mov.w r8, #0xff
 *   @0x2e5a12 mov.w r9, #0x1
 *   @0x2e5a16 b 0x2e5a4e <FT_Face_Properties+0x56>
 *   @0x2e5a1a bne 0x2e59fe <FT_Face_Properties+0x6>
 *   @0x2e5a1e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e5a22 ldr r3, [r2, #-8]
 *   @0x2e5a26 cmp r3, r11
 *   @0x2e5a2a ldr r10, [r2, #-4]
 *   @0x2e5a2e ldr.w r3, [r0, #0x80]
 *   @0x2e5a32 cmp.w r10, #0x0
 *   @0x2e5a36 beq 0x2e5a54 <FT_Face_Properties+0x5c>
 *   @0x2e5a42 movne r10, r9
 *   @0x2e5a46 strb.w r10, [r3, #0x38]
 *   @0x2e5a4a subs r1, #0x1
 *   @0x2e5a4e cmp r1, #0x0
 *   @0x2e5a52 b 0x2e5a86 <FT_Face_Properties+0x8e>
 *   @0x2e5a5a cmp r3, r6
 *   @0x2e5a5e cmp r3, r7
 *   @0x2e5a62 ldr r3, [r2, #-4]
 *   @0x2e5a66 ldr.w r10, [r0, #0x80]
 *   @0x2e5a6a cbz r3, 0x2e5a80 <FT_Face_Properties+0x88>
 *   @0x2e5a6e str.w r3, [r10, #0x3c]
 *   @0x2e5a72 ldr.w r3, [r0, #0x80]
 *   @0x2e5a76 ldr r5, [r3, #0x3c]
 *   @0x2e5a7a bge 0x2e5a4a <FT_Face_Properties+0x52>
 *   @0x2e5a7e b 0x2e5a4a <FT_Face_Properties+0x52>
 *   @0x2e5a86 mov r0, r1
 *   @0x2e5a8e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e5a92 nop
 *   @0x2e5a96 ldr r3, [r4, #0x44]
 *   @0x2e5a9a strb r5, [r4, #0xd]
 *   @0x2e5a9e str r1, [r4, #0x44]
 *
 * ══ FT_Get_Name_Index  0x2e5aa0  size 88  本节 21 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5aa2 0x2e5afa  size 88  21 条
 * 部分覆盖: 本节 21/43 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5aa2 mov r5, r1
 *   @0x2e5aa6 cbnz r0, 0x2e5aac <FT_Get_Name_Index+0xc>
 *   @0x2e5aaa pop {r3, r4, r5, pc}
 *   @0x2e5aae lsls r1, r3, #0x16
 *   @0x2e5ab2 cmp r5, #0x0
 *   @0x2e5ab6 ldr.w r3, [r0, #0x80]
 *   @0x2e5aba ldr r3, [r3, #0x28]
 *   @0x2e5abe beq 0x2e5aa8 <FT_Get_Name_Index+0x8>
 *   @0x2e5ac2 ldr r0, [r0, #0x60]
 *   @0x2e5ac6 ldr r2, [r2, #0x20]
 *   @0x2e5aca ldr r1, [pc, #0x28]
 *   @0x2e5ace blx r2
 *   @0x2e5ad2 ldr.w r2, [r4, #0x80]
 *   @0x2e5ad6 cmp r3, #0x0
 *   @0x2e5ada movne r1, r3
 *   @0x2e5ae2 beq 0x2e5aa8 <FT_Get_Name_Index+0x8>
 *   @0x2e5ae6 cmp r3, #0x0
 *   @0x2e5aea mov r0, r4
 *   @0x2e5aee blx r3
 *   @0x2e5af2 nop
 *   @0x2e5af6 movs r2, r1
 *
 * ══ FT_Get_Glyph_Name  0x2e5af8  size 128  本节 27 条（Thumb-2 半字段）｜入度 6
 * @func 0x2e5afe 0x2e5b8a  size 140  31 条
 * 部分覆盖: 本节 31/66 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 30/64 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 29/62 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 27/58 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5afe mov r5, r2
 *   @0x2e5b02 mov r4, r0
 *   @0x2e5b06 beq 0x2e5b66 <FT_Get_Glyph_Name+0x6e>
 *   @0x2e5b0a movs r0, #0x6
 *   @0x2e5b12 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12>
 *   @0x2e5b16 strb r3, [r2]
 *   @0x2e5b1a cmp r1, r3
 *   @0x2e5b1e ldr r3, [r0, #0x8]
 *   @0x2e5b22 bpl 0x2e5b0a <FT_Get_Glyph_Name+0x12>
 *   @0x2e5b2a adds r3, r0, #0x2
 *   @0x2e5b2e cbnz r0, 0x2e5b52 <FT_Get_Glyph_Name+0x5a>
 *   @0x2e5b32 ldr r3, [r2]
 *   @0x2e5b36 cbz r3, 0x2e5b40 <FT_Get_Glyph_Name+0x48>
 *   @0x2e5b3a mov r0, r2
 *   @0x2e5b3e blx r3
 *   @0x2e5b46 ite ne
 *   @0x2e5b4a mvneq r2, #0x1
 *   @0x2e5b4e str r2, [r3, #0x28]
 *   @0x2e5b52 ldr r6, [r0]
 *   @0x2e5b56 beq 0x2e5b0a <FT_Get_Glyph_Name+0x12>
 *   @0x2e5b5a mov r1, r7
 *   @0x2e5b5e mov r3, r8
 *   @0x2e5b62 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5b66 movs r0, #0x23
 *   @0x2e5b6e pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5b72 nop
 *   @0x2e5b76 movs r2, r1
 *
 * ══ FT_Get_Postscript_Name  0x2e5b78  size 72  本节 17 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e5b7a 0x2e5bd2  size 88  21 条
 * 部分覆盖: 本节 17/35 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5b7a mov r4, r0
 *   @0x2e5b7e movs r0, #0x0
 *   @0x2e5b82 ldr.w r3, [r0, #0x80]
 *   @0x2e5b86 ldr r3, [r3, #0x1c]
 *   @0x2e5b8a beq 0x2e5b7e <FT_Get_Postscript_Name+0x6>
 *   @0x2e5b8e ldr r0, [r0, #0x60]
 *   @0x2e5b92 ldr r2, [r2, #0x20]
 *   @0x2e5b96 ldr r1, [pc, #0x24]
 *   @0x2e5b9a blx r2
 *   @0x2e5b9e ldr.w r2, [r4, #0x80]
 *   @0x2e5ba2 cmp r3, #0x0
 *   @0x2e5ba6 movne r1, r3
 *   @0x2e5bae beq 0x2e5b7e <FT_Get_Postscript_Name+0x6>
 *   @0x2e5bb2 cmp r3, #0x0
 *   @0x2e5bb6 mov r0, r4
 *   @0x2e5bba pop {r4, pc}
 *   @0x2e5bbe movs r2, r1
 *
 * ══ FT_Get_Sfnt_Table  0x2e5bc0  size 52  本节 13 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5bc2 0x2e5bf6  size 52  13 条
 * 部分覆盖: 本节 13/26 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5bc2 mov r5, r1
 *   @0x2e5bc6 cbnz r0, 0x2e5bcc <FT_Get_Sfnt_Table+0xc>
 *   @0x2e5bca pop {r3, r4, r5, pc}
 *   @0x2e5bce lsls r3, r3, #0x1c
 *   @0x2e5bd2 ldr r0, [r0, #0x60]
 *   @0x2e5bd6 ldr r3, [r3, #0x20]
 *   @0x2e5bda beq 0x2e5bc8 <FT_Get_Sfnt_Table+0x8>
 *   @0x2e5bde add r1, pc
 *   @0x2e5be2 cmp r0, #0x0
 *   @0x2e5be6 ldr r3, [r0, #0x4]
 *   @0x2e5bea mov r0, r4
 *   @0x2e5bee pop {r3, r4, r5, pc}
 *   @0x2e5bf2 movs r2, r1
 *
 * ══ FT_Load_Sfnt_Table  0x2e5bf4  size 72  本节 16 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5bfa 0x2e5c3e  size 68  16 条
 * 部分覆盖: 本节 16/33 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5bfa mov r8, r2
 *   @0x2e5bfe mov r4, r0
 *   @0x2e5c02 ldr r0, [r0, #0x8]
 *   @0x2e5c06 bpl 0x2e5c30 <FT_Load_Sfnt_Table+0x3c>
 *   @0x2e5c0a ldr r5, [r0]
 *   @0x2e5c0e cbnz r5, 0x2e5c14 <FT_Load_Sfnt_Table+0x20>
 *   @0x2e5c12 b 0x2e5c32 <FT_Load_Sfnt_Table+0x3e>
 *   @0x2e5c16 add r1, pc
 *   @0x2e5c1a cmp r0, #0x0
 *   @0x2e5c1e ldr r5, [sp, #0x20]
 *   @0x2e5c22 mov r2, r8
 *   @0x2e5c26 str r5, [sp]
 *   @0x2e5c2a mov r0, r4
 *   @0x2e5c2e b 0x2e5c32 <FT_Load_Sfnt_Table+0x3e>
 *   @0x2e5c32 add sp, #0x8
 *   @0x2e5c3a movs r2, r1
 *
 * ══ FT_Sfnt_Table_Info  0x2e5c3c  size 72  本节 16 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5c42 0x2e5c96  size 84  20 条
 * 部分覆盖: 本节 16/33 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5c42 mov r7, r2
 *   @0x2e5c46 mov r4, r0
 *   @0x2e5c4a ldr r0, [r0, #0x8]
 *   @0x2e5c4e bpl 0x2e5c78 <FT_Sfnt_Table_Info+0x3c>
 *   @0x2e5c52 ldr r5, [r0]
 *   @0x2e5c56 cbnz r5, 0x2e5c5c <FT_Sfnt_Table_Info+0x20>
 *   @0x2e5c5a b 0x2e5c7a <FT_Sfnt_Table_Info+0x3e>
 *   @0x2e5c5e add r1, pc
 *   @0x2e5c62 cmp r0, #0x0
 *   @0x2e5c66 str.w r8, [sp]
 *   @0x2e5c6a mov r1, r6
 *   @0x2e5c6e mov r2, r7
 *   @0x2e5c72 add r3, sp, #0xc
 *   @0x2e5c76 b 0x2e5c7a <FT_Sfnt_Table_Info+0x3e>
 *   @0x2e5c7a add sp, #0x10
 *   @0x2e5c82 movs r2, r1
 *
 * ══ FT_Get_CMap_Language_ID  0x2e5c84  size 60  本节 15 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e5c86 0x2e5cd2  size 76  19 条
 * 部分覆盖: 本节 15/30 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5c86 mov r4, r0
 *   @0x2e5c8a movs r0, #0x0
 *   @0x2e5c8e ldr r3, [r0]
 *   @0x2e5c92 beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6>
 *   @0x2e5c96 ldr r3, [r0]
 *   @0x2e5c9a cmp r3, #0x0
 *   @0x2e5c9e ldr r1, [pc, #0x1c]
 *   @0x2e5ca2 blx r3
 *   @0x2e5ca6 beq 0x2e5c8a <FT_Get_CMap_Language_ID+0x6>
 *   @0x2e5caa mov r1, sp
 *   @0x2e5cae blx r3
 *   @0x2e5cb2 bne 0x2e5c8a <FT_Get_CMap_Language_ID+0x6>
 *   @0x2e5cb6 add sp, #0x8
 *   @0x2e5cba nop
 *   @0x2e5cbe movs r2, r1
 *
 * ══ FT_Get_CMap_Format  0x2e5cc0  size 60  本节 15 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e5cc2 0x2e5d0e  size 76  19 条
 * 部分覆盖: 本节 15/30 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5cc2 mov r4, r0
 *   @0x2e5cc6 mov.w r0, #0xffffffff
 *   @0x2e5cca b 0x2e5cf4 <FT_Get_CMap_Format+0x34>
 *   @0x2e5cce cmp r3, #0x0
 *   @0x2e5cd2 ldr r0, [r3, #0x60]
 *   @0x2e5cd6 ldr r3, [r3, #0x20]
 *   @0x2e5cda beq 0x2e5cc6 <FT_Get_CMap_Format+0x6>
 *   @0x2e5cde add r1, pc
 *   @0x2e5ce2 cmp r0, #0x0
 *   @0x2e5ce6 ldr r3, [r0]
 *   @0x2e5cea mov r0, r4
 *   @0x2e5cee cmp r0, #0x0
 *   @0x2e5cf2 ldr r0, [sp, #0x4]
 *   @0x2e5cf6 pop {r4, pc}
 *   @0x2e5cfa movs r2, r1
 *
 * ══ FT_Set_Charmap  0x2e5cfc  size 60  本节 14 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e5cfe 0x2e5d3a  size 60  14 条
 * 部分覆盖: 本节 14/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5cfe mov r5, r1
 *   @0x2e5d02 cbz r0, 0x2e5d2c <FT_Set_Charmap+0x30>
 *   @0x2e5d06 cbz r6, 0x2e5d30 <FT_Set_Charmap+0x34>
 *   @0x2e5d0a mov r0, r1
 *   @0x2e5d12 beq 0x2e5d34 <FT_Set_Charmap+0x38>
 *   @0x2e5d16 add.w r3, r6, r3, lsl #2
 *   @0x2e5d1a cmp r6, r3
 *   @0x2e5d1e ldr r2, [r6], #4
 *   @0x2e5d22 cmp r2, r5
 *   @0x2e5d26 str r5, [r4, #0x5c]
 *   @0x2e5d2a pop {r4, r5, r6, pc}
 *   @0x2e5d2e pop {r4, r5, r6, pc}
 *   @0x2e5d32 pop {r4, r5, r6, pc}
 *   @0x2e5d36 pop {r4, r5, r6, pc}
 *
 * ══ anon_2e5d38  0x2e5d38  size 44  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5d64 0x2e5d68  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5d64 andeq r11, r0, r0, ror sp
 *
 * ══ FT_Face_GetCharVariantIndex  0x2e5d68  size 56  本节 13 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e5d6a 0x2e5daa  size 64  15 条
 * 部分覆盖: 本节 13/27 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5d6a mov r7, r1
 *   @0x2e5d6e mov r4, r0
 *   @0x2e5d72 movs r0, #0x0
 *   @0x2e5d76 ldr r5, [r0, #0x5c]
 *   @0x2e5d7a beq 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa>
 *   @0x2e5d7e ldr r3, [pc, #0x1c]
 *   @0x2e5d82 bne 0x2e5d72 <FT_Face_GetCharVariantIndex+0xa>
 *   @0x2e5d8a cmp r0, #0x0
 *   @0x2e5d8e ldr r3, [r0, #0xc]
 *   @0x2e5d92 ldr r4, [r3, #0x14]
 *   @0x2e5d96 blx r4
 *   @0x2e5d9a nop
 *   @0x2e5d9e strb r6, [r5, #0x15]
 *
 * ══ FT_Face_GetCharVariantIsDefault  0x2e5da0  size 34  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5da2 0x2e5dc2  size 32  7 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5da2 mov r5, r1
 *   @0x2e5da6 cbnz r0, 0x2e5dae <FT_Face_GetCharVariantIsDefault+0xe>
 *   @0x2e5dae bl 0x2e5d38 <FT_Set_Charmap+0x3c>
 *   @0x2e5db2 cmp r0, #0x0
 *   @0x2e5db6 ldr r3, [r0, #0xc]
 *   @0x2e5dba mov r2, r4
 *   @0x2e5dbe blx r3
 *
 * ══ FT_Face_GetVariantSelectors  0x2e5dc2  size 28  本节 7 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e5dc4 0x2e5dec  size 40  10 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5dc4 mov r4, r0
 *   @0x2e5dc8 movs r0, #0x0
 *   @0x2e5dcc bl 0x2e5d38 <FT_Set_Charmap+0x3c>
 *   @0x2e5dd0 cmp r0, #0x0
 *   @0x2e5dd4 ldr r3, [r0, #0xc]
 *   @0x2e5dd8 ldr r3, [r3, #0x1c]
 *   @0x2e5ddc pop {r4, pc}
 *
 * ══ FT_Face_GetVariantsOfChar  0x2e5dde  size 32  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5de0 0x2e5e0c  size 44  10 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5de0 mov r4, r1
 *   @0x2e5de4 cbnz r0, 0x2e5dea <FT_Face_GetVariantsOfChar+0xc>
 *   @0x2e5de8 pop {r3, r4, r5, pc}
 *   @0x2e5df0 beq 0x2e5de6 <FT_Face_GetVariantsOfChar+0x8>
 *   @0x2e5df4 mov r2, r4
 *   @0x2e5df8 ldr r3, [r3, #0x20]
 *   @0x2e5dfc pop {r3, r4, r5, pc}
 *
 * ══ FT_Face_GetCharsOfVariant  0x2e5dfe  size 32  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5e00 0x2e5e30  size 48  11 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5e00 mov r4, r1
 *   @0x2e5e04 cbnz r0, 0x2e5e0a <FT_Face_GetCharsOfVariant+0xc>
 *   @0x2e5e08 pop {r3, r4, r5, pc}
 *   @0x2e5e10 beq 0x2e5e06 <FT_Face_GetCharsOfVariant+0x8>
 *   @0x2e5e14 mov r2, r4
 *   @0x2e5e18 ldr r3, [r3, #0x24]
 *   @0x2e5e1c pop {r3, r4, r5, pc}
 *
 * ══ FT_Activate_Size  0x2e5e1e  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5e20 0x2e5e40  size 32  8 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5e20 ldr r3, [r0]
 *   @0x2e5e24 ldr r2, [r3, #0x60]
 *   @0x2e5e28 str r0, [r3, #0x58]
 *   @0x2e5e2c bx lr
 *   @0x2e5e30 bx lr
 *   @0x2e5e34 bx lr
 *
 * ══ FT_Lookup_Renderer  0x2e5e36  size 50  本节 11 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5e38 0x2e5e68  size 48  11 条
 * 部分覆盖: 本节 11/23 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5e38 cbnz r0, 0x2e5e3e <FT_Lookup_Renderer+0x8>
 *   @0x2e5e3c pop {r4, pc}
 *   @0x2e5e44 ldr r0, [r2]
 *   @0x2e5e48 ldr r3, [r0, #0x4]
 *   @0x2e5e4c str r0, [r2]
 *   @0x2e5e50 ldr r0, [r3, #0x8]
 *   @0x2e5e54 cmp r4, r1
 *   @0x2e5e58 ldr r3, [r3, #0x4]
 *   @0x2e5e5c bne 0x2e5e50 <FT_Lookup_Renderer+0x1a>
 *   @0x2e5e60 cbz r2, 0x2e5e66 <FT_Lookup_Renderer+0x30>
 *   @0x2e5e64 pop {r4, pc}
 *
 * ══ FT_Get_Renderer  0x2e5e68  size 6  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5e6a 0x2e5e6e  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5e6a b.w 0x2e5e36 <FT_Lookup_Renderer>
 *
 * ══ FT_Render_Glyph_Internal  0x2e5e70  size 104  本节 22 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e5e76 0x2e5eea  size 116  26 条
 * 部分覆盖: 本节 25/53 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/51 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 22/47 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5e76 ldr r3, [pc, #0x58]
 *   @0x2e5e7a ldr r1, [r1, #0x48]
 *   @0x2e5e7e movs r4, #0x0
 *   @0x2e5e82 beq 0x2e5ec6 <FT_Render_Glyph_Internal+0x56>
 *   @0x2e5e86 str r4, [sp, #0x4]
 *   @0x2e5e8a bne 0x2e5e98 <FT_Render_Glyph_Internal+0x28>
 *   @0x2e5e96 b 0x2e5e9e <FT_Render_Glyph_Internal+0x2e>
 *   @0x2e5e9a bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e5e9e add.w r8, sp, #0x4
 *   @0x2e5ea2 movs r4, #0x7
 *   @0x2e5ea6 ldr r4, [r0, #0x3c]
 *   @0x2e5eaa mov r2, r7
 *   @0x2e5eae blx r4
 *   @0x2e5eb2 cbz r0, 0x2e5ec6 <FT_Render_Glyph_Internal+0x56>
 *   @0x2e5eb6 cmp r3, #0x13
 *   @0x2e5eba mov r0, r5
 *   @0x2e5ebe mov r2, r8
 *   @0x2e5ec6 mov r0, r4
 *   @0x2e5eca pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e5ece nop
 *   @0x2e5ed2 str r1, [r5, #0x24]
 *   @0x2e5ed6 ldr r5, [r6, #0x74]
 *
 * ══ FT_Render_Glyph  0x2e5ed8  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5eda 0x2e5f02  size 40  9 条
 * 部分覆盖: 本节 5/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5eda mov r3, r0
 *   @0x2e5ede ldr r0, [r0, #0x4]
 *   @0x2e5ee2 ldr r1, [r0, #0x60]
 *   @0x2e5ee6 mov r1, r3
 *   @0x2e5eee bx lr
 *
 * ══ FT_Get_Module  0x2e5ef0  size 56  本节 13 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e5ef2 0x2e5f36  size 68  16 条
 * 部分覆盖: 本节 13/27 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5ef2 mov r5, r1
 *   @0x2e5ef6 cbz r1, 0x2e5f22 <FT_Get_Module+0x32>
 *   @0x2e5efa add.w r6, r0, #0x14
 *   @0x2e5efe add.w r7, r6, r7, lsl #2
 *   @0x2e5f02 cmp r6, r7
 *   @0x2e5f06 ldr r4, [r6], #4
 *   @0x2e5f0a mov r1, r5
 *   @0x2e5f0e ldr r0, [r3, #0x8]
 *   @0x2e5f16 bne 0x2e5f02 <FT_Get_Module+0x12>
 *   @0x2e5f1a movs r4, #0x0
 *   @0x2e5f1e mov r4, r0
 *   @0x2e5f22 mov r4, r1
 *   @0x2e5f26 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ FT_Get_Module_Interface  0x2e5f28  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5f2a 0x2e5f36  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5f2a bl 0x2e5ef0 <FT_Get_Module>
 *   @0x2e5f2e cbz r0, 0x2e5f34 <FT_Get_Module_Interface+0xc>
 *   @0x2e5f32 ldr r0, [r3, #0x14]
 *
 * ══ ft_module_get_service  0x2e5f36  size 76  本节 18 条（Thumb-2 半字段）｜入度 7
 * @func 0x2e5f38 0x2e5f8c  size 84  20 条
 * 部分覆盖: 本节 19/39 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 18/37 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5f38 mov r6, r1
 *   @0x2e5f3c mov r4, r0
 *   @0x2e5f40 movs r0, #0x0
 *   @0x2e5f44 ldr r3, [r0]
 *   @0x2e5f48 cbz r3, 0x2e5f7a <ft_module_get_service+0x44>
 *   @0x2e5f4c cbz r5, 0x2e5f80 <ft_module_get_service+0x4a>
 *   @0x2e5f50 ldr r3, [r4, #0x4]
 *   @0x2e5f58 add.w r7, r5, r7, lsl #2
 *   @0x2e5f5c cmp r5, r7
 *   @0x2e5f60 ldr r0, [r5], #4
 *   @0x2e5f64 cmp r0, r4
 *   @0x2e5f68 ldr r3, [r0]
 *   @0x2e5f6c cmp r3, #0x0
 *   @0x2e5f70 mov r1, r6
 *   @0x2e5f74 cmp r0, #0x0
 *   @0x2e5f78 b 0x2e5f80 <ft_module_get_service+0x4a>
 *   @0x2e5f7c bne 0x2e5f50 <ft_module_get_service+0x1a>
 *   @0x2e5f80 pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ FT_Property_Set  0x2e5f82  size 20  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5f84 0x2e5fa0  size 28  5 条
 * 部分覆盖: 本节 4/10 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 3/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5f84 mov.w lr, #0x0
 *   @0x2e5f88 movs r4, #0x1
 *   @0x2e5f94 pop {r4, pc}
 *
 * ══ FT_Property_Get  0x2e5f96  size 16  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5f98 0x2e5fb0  size 24  5 条
 * 部分覆盖: 本节 3/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5f98 movs r4, #0x0
 *   @0x2e5f9c str r4, [sp, #0x4]
 *   @0x2e5fa4 pop {r4, pc}
 *
 * ══ ft_property_string_set  0x2e5fa6  size 16  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5fa8 0x2e5fc0  size 24  5 条
 * 部分覆盖: 本节 3/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5fa8 movs r4, #0x1
 *   @0x2e5fac str r4, [sp, #0x4]
 *   @0x2e5fb4 pop {r4, pc}
 *
 * ══ FT_Reference_Library  0x2e5fb6  size 20  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5fb8 0x2e5fdc  size 36  8 条
 * 部分覆盖: 本节 4/9 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5fb8 ldr.w r3, [r0, #0xbc]
 *   @0x2e5fbc adds r3, #0x1
 *   @0x2e5fc4 bx lr
 *   @0x2e5fc8 bx lr
 *
 * ══ FT_Library_Version  0x2e5fca  size 30  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5fcc 0x2e5fe8  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5fcc cbz r0, 0x2e5fd6 <FT_Library_Version+0xc>
 *   @0x2e5fd0 ldr r4, [r0, #0x8]
 *   @0x2e5fd4 b 0x2e5fda <FT_Library_Version+0x10>
 *   @0x2e5fd8 mov r5, r0
 *   @0x2e5fdc str r5, [r1]
 *   @0x2e5fe0 str r4, [r2]
 *   @0x2e5fe4 str r0, [r3]
 *
 * ══ FT_Set_Debug_Hook  0x2e5fe8  size 18  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5fea 0x2e5ff2  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5fea cbz r2, 0x2e5ff8 <FT_Set_Debug_Hook+0x10>
 *   @0x2e5fee itt ls
 *
 * ══ FT_Get_TrueType_Engine_Type  0x2e5ffc  size 48  本节 11 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e5ffe 0x2e603e  size 64  15 条
 * 部分覆盖: 本节 11/23 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e5ffe cbnz r0, 0x2e6004 <FT_Get_TrueType_Engine_Type+0x8>
 *   @0x2e6002 pop {r3, pc}
 *   @0x2e6006 add r1, pc
 *   @0x2e600e beq 0x2e6000 <FT_Get_TrueType_Engine_Type+0x4>
 *   @0x2e6012 movs r2, #0x0
 *   @0x2e6016 bl 0x2e5f36 <ft_module_get_service>
 *   @0x2e601a cmp r0, #0x0
 *   @0x2e601e ldr r0, [r0]
 *   @0x2e6022 nop
 *   @0x2e6026 movs r2, r1
 *   @0x2e602a movs r2, r1
 *
 * ══ FT_Get_SubGlyph_Info  0x2e602c  size 76  本节 17 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e602e 0x2e607a  size 76  17 条
 * 部分覆盖: 本节 17/36 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e602e ldr r4, [sp, #0x1c]
 *   @0x2e6032 ldr.w r5, [r0, #0x84]
 *   @0x2e6036 cbz r5, 0x2e606e <FT_Get_SubGlyph_Info+0x42>
 *   @0x2e603a ldr r7, [pc, #0x38]
 *   @0x2e603e bne 0x2e606e <FT_Get_SubGlyph_Info+0x42>
 *   @0x2e6046 bhs 0x2e606e <FT_Get_SubGlyph_Info+0x42>
 *   @0x2e604a adds r0, r5, r1
 *   @0x2e604e str r1, [r2]
 *   @0x2e6052 str r2, [r3]
 *   @0x2e6056 ldr r2, [r0, #0x8]
 *   @0x2e605a ldr r3, [sp, #0x18]
 *   @0x2e605e str r2, [r3]
 *   @0x2e6066 stm.w r4, {r0, r1, r2, r3}
 *   @0x2e606a movs r0, #0x0
 *   @0x2e606e movs r0, #0x6
 *   @0x2e6072 nop
 *   @0x2e6076 str r7, [r5, #0x34]
 *
 * ══ FT_Outline_Decompose  0x2e6078  size 678  本节 132 条（Thumb-2 半字段）｜入度 16
 * @func 0x2e607e 0x2e631e  size 672  132 条
 * 部分覆盖: 本节 132/300 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e607e mov r7, r1
 *   @0x2e6082 str r0, [sp, #0xc]
 *   @0x2e6086 beq.w 0x2e619a <FT_Outline_Decompose+0x122>
 *   @0x2e608a cmp r1, #0x0
 *   @0x2e6092 add.w r8, sp, #0x40
 *   @0x2e6096 ldr r5, [r1, #0x10]
 *   @0x2e609a str r3, [sp, #0x14]
 *   @0x2e60a2 ldr.w r8, [r0, #0x4]
 *   @0x2e60a6 add r0, sp, #0x28
 *   @0x2e60aa add.w r4, r8, r3, lsl #3
 *   @0x2e60ae add.w r11, r8, r2, lsl #3
 *   @0x2e60b2 ldr r2, [sp, #0x4]
 *   @0x2e60c2 rsb r12, r6, r12
 *   @0x2e60c6 ldr r1, [sp, #0x10]
 *   @0x2e60ce subs r2, r2, r6
 *   @0x2e60d2 ldr.w r0, [r8, r1, lsl #3]
 *   @0x2e60d6 add.w r8, sp, #0x20
 *   @0x2e60da ldr.w r1, [r11, #0x4]
 *   @0x2e60de str.w r8, [sp, #0x8]
 *   @0x2e60e2 ldr.w r8, [sp, #0x4]
 *   @0x2e60e6 lsls r0, r5
 *   @0x2e60ee ldm.w r8, {r0, r1}
 *   @0x2e60f2 ldr.w r8, [sp, #0x8]
 *   @0x2e60f6 stm.w r8, {r0, r1}
 *   @0x2e60fa ldr r0, [sp, #0xc]
 *   @0x2e60fe add.w r8, r1, r3
 *   @0x2e6102 ldrb r3, [r1, r3]
 *   @0x2e610a beq 0x2e619a <FT_Outline_Decompose+0x122>
 *   @0x2e610e beq 0x2e619e <FT_Outline_Decompose+0x126>
 *   @0x2e6112 add r0, sp, #0x28
 *   @0x2e6116 blx r3
 *   @0x2e611a bne.w 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e611e add r0, sp, #0x30
 *   @0x2e6122 cmp r4, r11
 *   @0x2e613a ldr r3, [r4, #0x8]
 *   @0x2e613e subs r3, r3, r6
 *   @0x2e6142 ldr r3, [r4, #0xc]
 *   @0x2e614a subs r3, r3, r6
 *   @0x2e614e mov r3, r10
 *   @0x2e6152 blo 0x2e6208 <FT_Outline_Decompose+0x190>
 *   @0x2e6156 add r0, sp, #0x20
 *   @0x2e615a mov r2, r9
 *   @0x2e615e cmp r0, #0x0
 *   @0x2e617a ldr.w r8, [sp, #0x14]
 *   @0x2e617e ldrsh.w r2, [r0]
 *   @0x2e6182 cmp r8, r2
 *   @0x2e618a ldr.w r8, [sp, #0x14]
 *   @0x2e618e ldr r2, [r0, #0xc]
 *   @0x2e6196 str r2, [sp, #0x10]
 *   @0x2e619a movs r0, #0x14
 *   @0x2e619e ldr.w lr, [sp, #0x10]
 *   @0x2e61a2 ldr r3, [sp, #0x18]
 *   @0x2e61aa rsb r3, r6, r10
 *   @0x2e61ae and r1, r1, #0x3
 *   @0x2e61b2 cmp r1, #0x1
 *   @0x2e61b6 str r0, [sp, #0x28]
 *   @0x2e61be b 0x2e61d6 <FT_Outline_Decompose+0x15e>
 *   @0x2e61c2 add r2, r3
 *   @0x2e61d2 str r1, [sp, #0x28]
 *   @0x2e61d6 subs r4, #0x8
 *   @0x2e61de cmp r3, #0x1
 *   @0x2e61e2 ldr r3, [r4, #0x8]
 *   @0x2e61e6 mov r1, r9
 *   @0x2e61ea subs r3, r3, r6
 *   @0x2e61ee ldr r3, [r4, #0xc]
 *   @0x2e61f2 subs r3, r3, r6
 *   @0x2e61f6 ldr r3, [r7, #0x4]
 *   @0x2e61fa blx r3
 *   @0x2e61fe cmp r0, #0x0
 *   @0x2e6206 b 0x2e6304 <FT_Outline_Decompose+0x28c>
 *   @0x2e620a mov r8, r4
 *   @0x2e6216 lsls r2, r5
 *   @0x2e621e str r2, [sp, #0x38]
 *   @0x2e6222 cmp r1, #0x1
 *   @0x2e6226 lsl.w r3, r3, r5
 *   @0x2e622a rsb r3, r6, r3
 *   @0x2e622e str r3, [sp, #0x3c]
 *   @0x2e6232 ldr r3, [r7, #0x8]
 *   @0x2e6236 add r1, sp, #0x38
 *   @0x2e623a blx r3
 *   @0x2e623e bne 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e6242 cmp r1, #0x0
 *   @0x2e6246 ldr r1, [sp, #0x20]
 *   @0x2e624a add r2, r1
 *   @0x2e624e add.w r2, r2, r2, lsr #31
 *   @0x2e6252 asrs r2, r2, #0x1
 *   @0x2e6256 ldr r2, [sp, #0x24]
 *   @0x2e625a mov r2, r9
 *   @0x2e6262 str r3, [sp, #0x44]
 *   @0x2e6266 str.w r12, [sp]
 *   @0x2e626a blx r3
 *   @0x2e6272 bne 0x2e6318 <FT_Outline_Decompose+0x2a0>
 *   @0x2e6276 ldr.w r8, [sp, #0x8]
 *   @0x2e627a ldm.w r3, {r0, r1}
 *   @0x2e627e mov r3, r12
 *   @0x2e6286 add.w r3, r4, #0x10
 *   @0x2e628a cmp r11, r3
 *   @0x2e628e ldrb.w r3, [r8, #0x2]
 *   @0x2e6292 and r3, r3, #0x3
 *   @0x2e6296 cmp r3, #0x2
 *   @0x2e629e add.w r10, r4, #0x18
 *   @0x2e62a2 cmp r10, r11
 *   @0x2e62a6 lsl.w r3, r3, r5
 *   @0x2e62aa rsb r3, r6, r3
 *   @0x2e62ae str r3, [sp, #0x30]
 *   @0x2e62b2 lsl.w r3, r3, r5
 *   @0x2e62b6 rsb r3, r6, r3
 *   @0x2e62ba str r3, [sp, #0x34]
 *   @0x2e62be lsl.w r3, r3, r5
 *   @0x2e62c2 rsb r3, r6, r3
 *   @0x2e62c6 str r3, [sp, #0x38]
 *   @0x2e62ca lsl.w r3, r3, r5
 *   @0x2e62ce rsb r3, r6, r3
 *   @0x2e62d2 str r3, [sp, #0x3c]
 *   @0x2e62d6 ldr r3, [r4, #0x18]
 *   @0x2e62da add r2, sp, #0x40
 *   @0x2e62de subs r3, r3, r6
 *   @0x2e62e2 ldr r3, [r4, #0x1c]
 *   @0x2e62e6 lsls r3, r5
 *   @0x2e62ea str r3, [sp, #0x44]
 *   @0x2e62ee blx r4
 *   @0x2e62f2 add.w r8, r8, #0x3
 *   @0x2e62f6 b 0x2e6304 <FT_Outline_Decompose+0x28c>
 *   @0x2e62fa add r0, sp, #0x30
 *   @0x2e62fe mov r3, r9
 *   @0x2e6302 b 0x2e615e <FT_Outline_Decompose+0xe6>
 *   @0x2e6306 b 0x2e6122 <FT_Outline_Decompose+0xaa>
 *   @0x2e630a add r0, sp, #0x28
 *   @0x2e630e blx r3
 *   @0x2e6312 movs r0, #0x0
 *   @0x2e6316 movs r0, #0x6
 *   @0x2e631a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ FT_Outline_Check  0x2e631e  size 78  本节 15 条（Thumb-2 半字段）｜入度 6
 * @func 0x2e6320 0x2e636c  size 76  15 条
 * 部分覆盖: 本节 15/34 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6320 cbz r0, 0x2e6368 <FT_Outline_Check+0x4a>
 *   @0x2e632c bne 0x2e6338 <FT_Outline_Check+0x1a>
 *   @0x2e6330 ite ne
 *   @0x2e6334 moveq r0, #0x0
 *   @0x2e6338 ble 0x2e6368 <FT_Outline_Check+0x4a>
 *   @0x2e633c ble 0x2e6368 <FT_Outline_Check+0x4a>
 *   @0x2e6340 movs r2, #0x0
 *   @0x2e634c ble 0x2e6368 <FT_Outline_Check+0x4a>
 *   @0x2e6350 bge 0x2e6368 <FT_Outline_Check+0x4a>
 *   @0x2e6354 cmp r2, r4
 *   @0x2e6358 mov r0, r3
 *   @0x2e635c subs r0, r1, #0x1
 *   @0x2e6360 ite ne
 *   @0x2e6364 moveq r0, #0x0
 *   @0x2e6368 movs r0, #0x6
 *
 * ══ FT_Outline_Copy  0x2e636c  size 96  本节 24 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e636e 0x2e63de  size 112  28 条
 * 部分覆盖: 本节 28/56 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 27/54 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 26/52 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 25/50 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/48 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e636e mov r5, r1
 *   @0x2e6372 cbz r0, 0x2e63c0 <FT_Outline_Copy+0x54>
 *   @0x2e6376 ldr r2, [r0]
 *   @0x2e637a cmp r2, r3
 *   @0x2e637e cmp r0, r1
 *   @0x2e6382 ldrh r2, [r0, #0x2]
 *   @0x2e6386 sxth r2, r2
 *   @0x2e638a ldr r1, [r4, #0x4]
 *   @0x2e638e blx 0xb65bc <memcpy@plt>
 *   @0x2e6392 ldr r0, [r5, #0x8]
 *   @0x2e6396 ldrsh.w r2, [r4, #0x2]
 *   @0x2e639a blx 0xb65bc <memcpy@plt>
 *   @0x2e639e ldrh r2, [r4]
 *   @0x2e63a2 sxth r2, r2
 *   @0x2e63a6 ldr r1, [r4, #0xc]
 *   @0x2e63aa blx 0xb65bc <memcpy@plt>
 *   @0x2e63ae ldr r2, [r4, #0x10]
 *   @0x2e63b2 bic r2, r2, #0x1
 *   @0x2e63b6 and r3, r3, #0x1
 *   @0x2e63ba orrs r3, r2
 *   @0x2e63be b 0x2e63c8 <FT_Outline_Copy+0x5c>
 *   @0x2e63c2 pop {r3, r4, r5, pc}
 *   @0x2e63c6 pop {r3, r4, r5, pc}
 *   @0x2e63ca pop {r3, r4, r5, pc}
 *
 * ══ FT_Outline_Get_CBox  0x2e63cc  size 88  本节 20 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e63ce 0x2e642e  size 96  22 条
 * 部分覆盖: 本节 20/42 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e63ce cbz r0, 0x2e6422 <FT_Outline_Get_CBox+0x56>
 *   @0x2e63d2 ldrh r3, [r0, #0x2]
 *   @0x2e63d6 ldr r4, [r0, #0x4]
 *   @0x2e63da add.w r5, r4, #0x8
 *   @0x2e63de add.w r7, r4, r3, lsl #3
 *   @0x2e63e2 ldm.w r4, {r0, r2}
 *   @0x2e63e6 mov r3, r2
 *   @0x2e63ea cmp r7, r5
 *   @0x2e63f2 ldr r5, [r6, #-8]
 *   @0x2e63f6 cmp r0, r5
 *   @0x2e63fa movge r0, r5
 *   @0x2e63fe it lt
 *   @0x2e6402 ldr r5, [r6, #-4]
 *   @0x2e6406 cmp r2, r5
 *   @0x2e640a movge r2, r5
 *   @0x2e640e it lt
 *   @0x2e6412 mov r5, r6
 *   @0x2e6416 mov r4, r3
 *   @0x2e641a mov r0, r3
 *   @0x2e6422 pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Outline_Translate  0x2e6424  size 46  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6426 0x2e6452  size 44  10 条
 * 部分覆盖: 本节 10/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6426 cbz r0, 0x2e6450 <FT_Outline_Translate+0x2c>
 *   @0x2e642a movs r4, #0x0
 *   @0x2e6432 cmp r4, r5
 *   @0x2e6436 ldr r5, [r3, #-8]
 *   @0x2e643a adds r4, #0x1
 *   @0x2e643e str r5, [r3, #-8]
 *   @0x2e6442 ldr r5, [r3, #-4]
 *   @0x2e6446 uxth r4, r4
 *   @0x2e644a str r5, [r3, #-4]
 *   @0x2e644e b 0x2e642c <FT_Outline_Translate+0x8>
 *
 * ══ FT_Outline_Reverse  0x2e6452  size 116  本节 21 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6458 0x2e64d6  size 126  25 条
 * 部分覆盖: 本节 22/50 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6458 cbz r0, 0x2e64c2 <FT_Outline_Reverse+0x70>
 *   @0x2e645c mov r5, r6
 *   @0x2e6464 bge 0x2e64ba <FT_Outline_Reverse+0x68>
 *   @0x2e6468 ldr r4, [r3, #0x4]
 *   @0x2e6478 sub.w r4, r4, #0x8
 *   @0x2e647c add.w r2, r2, #0x8
 *   @0x2e6480 bhs 0x2e649a <FT_Outline_Reverse+0x48>
 *   @0x2e648c stmdb r2, {r0, r1}
 *   @0x2e6490 str.w r8, [r4, #0x8]
 *   @0x2e6494 str.w r12, [r4, #0xc]
 *   @0x2e6498 b 0x2e6476 <FT_Outline_Reverse+0x24>
 *   @0x2e649c add r6, r2
 *   @0x2e64a0 cmp r6, r2
 *   @0x2e64a4 ldrb r1, [r6]
 *   @0x2e64a8 strb r0, [r6], #1
 *   @0x2e64ac strb r1, [r2], #-1
 *   @0x2e64b0 b 0x2e64a0 <FT_Outline_Reverse+0x4e>
 *   @0x2e64b4 adds r6, r7, #0x1
 *   @0x2e64b8 b 0x2e645e <FT_Outline_Reverse+0xc>
 *   @0x2e64bc eor r2, r2, #0x4
 *   @0x2e64c0 str r2, [r3, #0x10]
 *
 * ══ anon_2e64c6  0x2e64c6  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e64c6 0x2e64d6  size 16  4 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e64c6 ldrblt r0, [r7, #0x0]!
 *
 * ══ FT_Outline_Render  0x2e64c8  size 84  本节 18 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e64ca 0x2e652e  size 100  22 条
 * 部分覆盖: 本节 21/45 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 20/43 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 19/41 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 18/39 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e64ca mov r6, r2
 *   @0x2e64ce cbz r0, 0x2e6506 <FT_Outline_Render+0x3e>
 *   @0x2e64d2 cbz r2, 0x2e650e <FT_Outline_Render+0x46>
 *   @0x2e64da movs r4, #0x13
 *   @0x2e64e2 str r3, [r7, #-4]!
 *   @0x2e64e6 cbz r0, 0x2e6512 <FT_Outline_Render+0x4a>
 *   @0x2e64ea mov r1, r6
 *   @0x2e64ee blx r3
 *   @0x2e64f2 cbz r0, 0x2e6512 <FT_Outline_Render+0x4a>
 *   @0x2e64f6 cmp r3, #0x13
 *   @0x2e64fa mov r0, r5
 *   @0x2e64fe mov r2, r7
 *   @0x2e6506 movs r0, #0x21
 *   @0x2e650a movs r0, #0x14
 *   @0x2e650e movs r0, #0x6
 *   @0x2e6512 mov r0, r4
 *   @0x2e6516 pop {r4, r5, r6, r7, pc}
 *   @0x2e651a ldr r5, [r6, #0x74]
 *
 * ══ FT_Outline_Get_Bitmap  0x2e651c  size 44  本节 10 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e651e 0x2e6546  size 40  10 条
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e651e sub sp, #0x34
 *   @0x2e6522 movs r3, #0x0
 *   @0x2e6526 ldrb r3, [r2, #0x12]
 *   @0x2e652a cmp r3, #0x2
 *   @0x2e652e subs r3, #0x5
 *   @0x2e6532 bhi 0x2e6538 <FT_Outline_Get_Bitmap+0x1c>
 *   @0x2e6536 str r3, [sp, #0x8]
 *   @0x2e653a bl 0x2e64c8 <FT_Outline_Render>
 *   @0x2e653e b 0x2e6542 <FT_Outline_Get_Bitmap+0x26>
 *   @0x2e6542 add sp, #0x34
 *
 * ══ FT_Vector_Transform  0x2e6548  size 56  本节 12 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e654a 0x2e658a  size 64  14 条
 * 部分覆盖: 本节 12/26 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e654a mov r5, r1
 *   @0x2e654e cbz r0, 0x2e657e <FT_Vector_Transform+0x36>
 *   @0x2e6552 ldr r1, [r1]
 *   @0x2e6556 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e655a ldr r1, [r5, #0x4]
 *   @0x2e655e ldr r0, [r4, #0x4]
 *   @0x2e6566 add r6, r0
 *   @0x2e656a bl 0x2e4e4c <FT_MulFix>
 *   @0x2e656e ldr r1, [r5, #0xc]
 *   @0x2e6572 ldr r0, [r4, #0x4]
 *   @0x2e657a add r0, r7
 *   @0x2e657e pop {r3, r4, r5, r6, r7, pc}
 *
 * ══ FT_Outline_Transform  0x2e6580  size 36  本节 8 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6582 0x2e65a6  size 36  8 条
 * 部分覆盖: 本节 8/17 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6582 mov r5, r1
 *   @0x2e6586 cbz r1, 0x2e65a2 <FT_Outline_Transform+0x22>
 *   @0x2e658e add.w r6, r4, r6, lsl #3
 *   @0x2e6592 cmp r4, r6
 *   @0x2e6596 mov r0, r4
 *   @0x2e659a bl 0x2e6548 <FT_Vector_Transform>
 *   @0x2e659e adds r4, #0x8
 *   @0x2e65a2 pop {r4, r5, r6, pc}
 *
 * ══ FT_Outline_Get_Orientation  0x2e65a4  size 204  本节 39 条（Thumb-2 半字段）｜入度 6
 * @func 0x2e65aa 0x2e666e  size 196  39 条
 * 部分覆盖: 本节 39/88 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e65aa sub sp, #0x1c
 *   @0x2e65ae movs r0, #0x0
 *   @0x2e65b2 ldrsh.w r3, [r0, #0x2]
 *   @0x2e65b6 cmp r3, #0x0
 *   @0x2e65ba add r1, sp, #0x8
 *   @0x2e65c2 ldr r1, [sp, #0x10]
 *   @0x2e65c6 beq 0x2e6664 <FT_Outline_Get_Orientation+0xc0>
 *   @0x2e65ca ldr r2, [sp, #0x14]
 *   @0x2e65ce beq 0x2e6664 <FT_Outline_Get_Orientation+0xc0>
 *   @0x2e65da it lt
 *   @0x2e65de rsb r8, r3, r2
 *   @0x2e65e2 orr.w r12, r12, r1
 *   @0x2e65e6 clz r12, r12
 *   @0x2e65ea clz r8, r8
 *   @0x2e65ee rsb.w r12, r12, #0x11
 *   @0x2e65f2 rsb.w r8, r8, #0x11
 *   @0x2e65f6 ldrsh.w r0, [r4]
 *   @0x2e65fa movs r3, #0x0
 *   @0x2e65fe bic.w r12, r12, r12, asr #31
 *   @0x2e6602 bic.w r8, r8, r8, asr #31
 *   @0x2e6606 mov r2, r3
 *   @0x2e660a str r0, [sp, #0x4]
 *   @0x2e660e cmp r1, r0
 *   @0x2e6612 ldr r0, [r4, #0xc]
 *   @0x2e6626 asr.w r9, r5, r8
 *   @0x2e662a add.w r5, r6, r2, lsl #3
 *   @0x2e662e cmp r2, r0
 *   @0x2e6636 ldr r7, [r5, #-8]
 *   @0x2e663a adds r2, #0x1
 *   @0x2e6646 asr.w r7, r7, r8
 *   @0x2e664a rsb r9, r9, r7
 *   @0x2e664e mla r3, r10, r9, r3
 *   @0x2e6652 mov r9, r7
 *   @0x2e6656 b 0x2e662e <FT_Outline_Get_Orientation+0x8a>
 *   @0x2e665a adds r1, #0x1
 *   @0x2e665e cmp r3, #0x0
 *   @0x2e6662 bne 0x2e65ae <FT_Outline_Get_Orientation+0xa>
 *   @0x2e6666 b 0x2e666a <FT_Outline_Get_Orientation+0xc6>
 *   @0x2e666a add sp, #0x1c
 *
 * ══ FT_Outline_EmboldenXY  0x2e6670  size 512  本节 113 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e6676 0x2e6876  size 512  114 条
 * 部分覆盖: 本节 114/242 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 113/240 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6676 str r0, [sp, #0x4]
 *   @0x2e667a beq.w 0x2e6862 <FT_Outline_EmboldenXY+0x1f2>
 *   @0x2e667e add.w r1, r1, r1, lsr #31
 *   @0x2e6682 add.w r2, r2, r2, lsr #31
 *   @0x2e6686 asrs r1, r1, #0x1
 *   @0x2e668e str r2, [sp, #0x18]
 *   @0x2e6692 cbnz r2, 0x2e6698 <FT_Outline_EmboldenXY+0x28>
 *   @0x2e6696 b 0x2e6864 <FT_Outline_EmboldenXY+0x1f4>
 *   @0x2e669a bl 0x2e65a4 <FT_Outline_Get_Orientation>
 *   @0x2e669e ldr r3, [sp, #0x4]
 *   @0x2e66a2 str r0, [sp, #0x28]
 *   @0x2e66a6 ldrsh.w r0, [r3]
 *   @0x2e66aa cmp r0, #0x0
 *   @0x2e66ae movne r0, #0x6
 *   @0x2e66b2 b 0x2e6864 <FT_Outline_EmboldenXY+0x1f4>
 *   @0x2e66b6 movs r3, #0x0
 *   @0x2e66ba str r3, [sp, #0xc]
 *   @0x2e66be str r3, [sp, #0x34]
 *   @0x2e66c2 ldrsh.w r3, [r2]
 *   @0x2e66c6 ldr r2, [sp, #0xc]
 *   @0x2e66ca bge 0x2e6694 <FT_Outline_EmboldenXY+0x24>
 *   @0x2e66ce mov.w r9, #0x0
 *   @0x2e66d2 ldr r5, [sp, #0x8]
 *   @0x2e66d6 mov r11, r9
 *   @0x2e66da ldr r3, [r2, #0xc]
 *   @0x2e66de str.w r9, [sp, #0x30]
 *   @0x2e66e2 str.w r9, [sp, #0x2c]
 *   @0x2e66e6 ldrsh.w r3, [r3, r2, lsl #1]
 *   @0x2e66ea str r3, [sp, #0x1c]
 *   @0x2e66ee mov.w r3, #0xffffffff
 *   @0x2e66f2 str r3, [sp, #0x14]
 *   @0x2e66f6 beq.w 0x2e6854 <FT_Outline_EmboldenXY+0x1e4>
 *   @0x2e66fa ldr r3, [sp, #0x14]
 *   @0x2e66fe beq.w 0x2e6854 <FT_Outline_EmboldenXY+0x1e4>
 *   @0x2e6702 ldr r3, [sp, #0x14]
 *   @0x2e6706 beq 0x2e6734 <FT_Outline_EmboldenXY+0xc4>
 *   @0x2e671a ldr r2, [r0, #0x4]
 *   @0x2e671e add r0, sp, #0x38
 *   @0x2e6722 subs r3, r2, r3
 *   @0x2e6726 bl 0x2e5096 <FT_Vector_NormLen>
 *   @0x2e672a str r0, [sp, #0x10]
 *   @0x2e672e beq.w 0x2e6848 <FT_Outline_EmboldenXY+0x1d8>
 *   @0x2e6732 b 0x2e6740 <FT_Outline_EmboldenXY+0xd0>
 *   @0x2e6736 str.w r9, [sp, #0x3c]
 *   @0x2e673a str r3, [sp, #0x38]
 *   @0x2e673e str r3, [sp, #0x10]
 *   @0x2e6746 ldr r3, [sp, #0x14]
 *   @0x2e674a bge 0x2e6758 <FT_Outline_EmboldenXY+0xe8>
 *   @0x2e674e str.w r11, [sp, #0x30]
 *   @0x2e6752 str r4, [sp, #0x14]
 *   @0x2e675a mov r0, r11
 *   @0x2e6762 mov r10, r0
 *   @0x2e6766 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e676a ldr r2, [pc, #0x100]
 *   @0x2e676e cmp r0, r2
 *   @0x2e6772 add.w r10, r0, #0x10000
 *   @0x2e6776 ldr r0, [sp, #0x38]
 *   @0x2e677a add.w r2, r11, r0
 *   @0x2e677e str r2, [sp, #0x20]
 *   @0x2e6782 add r3, r7
 *   @0x2e6786 rsbs r3, r3, #0
 *   @0x2e678a ldr r2, [sp, #0x20]
 *   @0x2e678e str r2, [sp, #0x20]
 *   @0x2e6792 str r3, [sp]
 *   @0x2e679a mov r7, r0
 *   @0x2e679e bl 0x2e4e4c <FT_MulFix>
 *   @0x2e67a2 ldr r2, [sp, #0x28]
 *   @0x2e67a6 subs r7, r7, r0
 *   @0x2e67aa rsbs r7, r7, #0
 *   @0x2e67ae mov r1, r7
 *   @0x2e67b2 cmp r2, r8
 *   @0x2e67b6 movlt r8, r2
 *   @0x2e67ba bl 0x2e4e4c <FT_MulFix>
 *   @0x2e67be mov r1, r10
 *   @0x2e67c2 mov r0, r8
 *   @0x2e67ca cmp r11, r0
 *   @0x2e67ce itete le
 *   @0x2e67d2 movgt r1, r8
 *   @0x2e67d6 movgt r2, r7
 *   @0x2e67de mov r11, r0
 *   @0x2e67e2 bl 0x2e4e4c <FT_MulFix>
 *   @0x2e67e6 mov r1, r10
 *   @0x2e67ea mov r0, r8
 *   @0x2e67ee bl 0x2e4e4c <FT_MulFix>
 *   @0x2e67f2 ldr r3, [sp]
 *   @0x2e67f6 ldr r0, [sp, #0x20]
 *   @0x2e67fa ldr r1, [sp, #0x18]
 *   @0x2e67fe b 0x2e6812 <FT_Outline_EmboldenXY+0x1a2>
 *   @0x2e6802 mov r11, r0
 *   @0x2e6806 add r11, r3
 *   @0x2e680a add r0, r3
 *   @0x2e680e mov r1, r8
 *   @0x2e6812 bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e6816 b 0x2e6804 <FT_Outline_EmboldenXY+0x194>
 *   @0x2e6822 str.w r2, [r6, r4, lsl #3]
 *   @0x2e6826 ldr r2, [r3, #0x4]
 *   @0x2e682a str r2, [r3, #0x4]
 *   @0x2e682e cmp r4, r3
 *   @0x2e6832 addlt r4, #0x1
 *   @0x2e6836 cmp r4, r5
 *   @0x2e683a b 0x2e683e <FT_Outline_EmboldenXY+0x1ce>
 *   @0x2e683e ldr.w r11, [sp, #0x38]
 *   @0x2e6842 ldr r7, [sp, #0x3c]
 *   @0x2e684a cmp r5, r3
 *   @0x2e684e addlt r5, #0x1
 *   @0x2e6852 b 0x2e66f4 <FT_Outline_EmboldenXY+0x84>
 *   @0x2e6856 adds r3, #0x1
 *   @0x2e685a ldr r3, [sp, #0xc]
 *   @0x2e685e str r3, [sp, #0xc]
 *   @0x2e6862 movs r0, #0x14
 *   @0x2e6866 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e686a nop
 *   @0x2e686e .word 0xffff 460a
 *
 * ══ FT_Outline_Embolden  0x2e6870  size 6  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6872 0x2e6876  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6872 b.w 0x2e6670 <FT_Outline_EmboldenXY>
 *
 * ══ FT_Get_Sfnt_Name_Count  0x2e6876  size 20  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6878 0x2e689c  size 36  8 条
 * 部分覆盖: 本节 4/9 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6878 ldr r3, [r0, #0x8]
 *   @0x2e6880 ldrh.w r0, [r0, #0x154]
 *   @0x2e6884 bx lr
 *   @0x2e6888 bx lr
 *
 * ══ FT_Stream_OpenMemory  0x2e688a  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e688c 0x2e68ac  size 32  8 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e688c stm.w r0, {r1, r2}
 *   @0x2e6890 str r3, [r0, #0x8]
 *   @0x2e6894 str r3, [r0, #0x14]
 *   @0x2e6898 bx lr
 *
 * ══ FT_Stream_Close  0x2e689a  size 12  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e689c 0x2e68b8  size 28  7 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e689c cbz r0, 0x2e68a4 <FT_Stream_Close+0xa>
 *   @0x2e68a0 cbz r3, 0x2e68a4 <FT_Stream_Close+0xa>
 *   @0x2e68a4 pop {r3, pc}
 *
 * ══ FT_Stream_Seek  0x2e68a6  size 36  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e68a8 0x2e68ce  size 38  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e68a8 mov r4, r0
 *   @0x2e68ac mov r5, r1
 *   @0x2e68b0 movs r2, #0x0
 *   @0x2e68b4 blx r6
 *   @0x2e68b8 b 0x2e68c0 <FT_Stream_Seek+0x1a>
 *   @0x2e68bc cmp r1, r3
 *   @0x2e68c0 str r5, [r4, #0x8]
 *   @0x2e68c4 pop {r4, r5, r6, pc}
 *   @0x2e68c8 pop {r4, r5, r6, pc}
 *
 * ══ anon_2e68ca  0x2e68ca  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e68ca 0x2e68ce  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e68ca .word 0xe92d0000
 *
 * ══ FT_Raccess_Guess  0x2e68cc  size 100  本节 23 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e68d2 0x2e693a  size 104  25 条
 * 部分覆盖: 本节 25/51 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 24/49 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/47 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e68d2 ldr.w r11, [pc, #0x58]
 *   @0x2e68d6 sub sp, #0x14
 *   @0x2e68da mov r7, r1
 *   @0x2e68de mov r9, r2
 *   @0x2e68e2 mov r10, r4
 *   @0x2e68e6 str r10, [r6], #4
 *   @0x2e68ea cbz r7, 0x2e68fe <FT_Raccess_Guess+0x32>
 *   @0x2e68ee movs r1, #0x0
 *   @0x2e68f2 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e68f6 ldr r5, [sp, #0x3c]
 *   @0x2e68fa ldr r3, [sp, #0xc]
 *   @0x2e68fe ldr r5, [sp, #0x3c]
 *   @0x2e6902 ldr r5, [sp, #0x3c]
 *   @0x2e6906 cbnz r2, 0x2e691e <FT_Raccess_Guess+0x52>
 *   @0x2e690a mov r0, r8
 *   @0x2e6912 add r2, r4
 *   @0x2e6916 mov r2, r9
 *   @0x2e691a ldr r5, [sp, #0x3c]
 *   @0x2e691e adds r4, #0x4
 *   @0x2e6922 bne 0x2e68e4 <FT_Raccess_Guess+0x18>
 *   @0x2e6926 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e692a nop
 *   @0x2e692e movs r0, r2
 *
 * ══ FT_Stream_Skip  0x2e6930  size 16  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6932 0x2e6946  size 20  4 条
 * 部分覆盖: 本节 3/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6932 blt 0x2e693c <FT_Stream_Skip+0xc>
 *   @0x2e6936 add r1, r3
 *   @0x2e693e bx lr
 *
 * ══ FT_Stream_Pos  0x2e6940  size 4  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6942 0x2e6946  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6942 bx lr
 *
 * ══ FT_Stream_ReadAt  0x2e6944  size 74  本节 13 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e694a 0x2e698e  size 68  13 条
 * 部分覆盖: 本节 13/30 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e694a ldr r6, [r0, #0x4]
 *   @0x2e694e mov r7, r3
 *   @0x2e6952 bhs 0x2e6988 <FT_Stream_ReadAt+0x44>
 *   @0x2e695e blx r12
 *   @0x2e6962 b 0x2e6978 <FT_Stream_ReadAt+0x34>
 *   @0x2e6966 ldr r1, [r0]
 *   @0x2e696a it hs
 *   @0x2e696e mov r0, r2
 *   @0x2e6972 mov r2, r6
 *   @0x2e697a cmp r6, r7
 *   @0x2e697e movlo r0, #0x55
 *   @0x2e6982 str r5, [r4, #0x8]
 *   @0x2e698a pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ FT_Stream_Read  0x2e698e  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6990 0x2e69a0  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6990 mov r4, r1
 *   @0x2e6994 ldr r1, [r0, #0x8]
 *   @0x2e6998 pop.w {r4, lr}
 *   @0x2e699c b.w 0x2e6944 <FT_Stream_ReadAt>
 *
 * ══ FT_Stream_TryRead  0x2e69a0  size 62  本节 14 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e69a2 0x2e69de  size 60  14 条
 * 部分覆盖: 本节 14/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e69a2 mov r7, r1
 *   @0x2e69a6 mov r4, r0
 *   @0x2e69aa mov r3, r2
 *   @0x2e69ae bhs 0x2e69d8 <FT_Stream_TryRead+0x38>
 *   @0x2e69b2 cbz r6, 0x2e69bc <FT_Stream_TryRead+0x1c>
 *   @0x2e69b6 blx r6
 *   @0x2e69ba b 0x2e69d0 <FT_Stream_TryRead+0x30>
 *   @0x2e69be ldr r3, [r0]
 *   @0x2e69c2 it lo
 *   @0x2e69c6 mov r0, r7
 *   @0x2e69ca mov r2, r5
 *   @0x2e69d2 add r3, r5
 *   @0x2e69d6 b 0x2e69da <FT_Stream_TryRead+0x3a>
 *   @0x2e69da mov r0, r5
 *
 * ══ FT_Stream_GetChar  0x2e69de  size 20  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e69e0 0x2e6a04  size 36  9 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e69e0 ldr r2, [r0, #0x24]
 *   @0x2e69e4 ittte lo
 *   @0x2e69e8 strlo r2, [r0, #0x20]
 *   @0x2e69ec movhs r0, #0x0
 *   @0x2e69f0 bx lr
 *
 * ══ FT_Stream_GetUShort  0x2e69f2  size 32  本节 6 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e69f4 0x2e6a24  size 48  10 条
 * 部分覆盖: 本节 6/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e69f4 ldr r3, [r0, #0x20]
 *   @0x2e69f8 adds r0, r3, #0x1
 *   @0x2e69fc bls 0x2e6a0c <FT_Stream_GetUShort+0x1a>
 *   @0x2e6a00 adds r3, #0x2
 *   @0x2e6a0c movs r0, #0x0
 *   @0x2e6a10 bx lr
 *
 * ══ FT_Stream_GetUShortLE  0x2e6a12  size 32  本节 6 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6a14 0x2e6a44  size 48  10 条
 * 部分覆盖: 本节 6/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6a14 ldr r3, [r0, #0x20]
 *   @0x2e6a18 adds r0, r3, #0x1
 *   @0x2e6a1c bls 0x2e6a2c <FT_Stream_GetUShortLE+0x1a>
 *   @0x2e6a20 adds r3, #0x2
 *   @0x2e6a2c movs r0, #0x0
 *   @0x2e6a30 bx lr
 *
 * ══ FT_Stream_GetUOffset  0x2e6a32  size 40  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6a34 0x2e6a6c  size 56  13 条
 * 部分覆盖: 本节 9/19 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6a34 ldr r3, [r0, #0x20]
 *   @0x2e6a38 adds r0, r3, #0x2
 *   @0x2e6a3c bls 0x2e6a54 <FT_Stream_GetUOffset+0x22>
 *   @0x2e6a40 adds r3, #0x3
 *   @0x2e6a48 orr.w r0, r0, r1, lsl #16
 *   @0x2e6a4c ldrb r1, [r3, #-1]
 *   @0x2e6a50 orrs r0, r1
 *   @0x2e6a54 movs r0, #0x0
 *   @0x2e6a58 bx lr
 *
 * ══ FT_Stream_GetULong  0x2e6a5a  size 48  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6a5c 0x2e6a9c  size 64  13 条
 * 部分覆盖: 本节 13/29 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 12/27 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 11/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6a5c ldr r3, [r0, #0x20]
 *   @0x2e6a60 adds r0, r3, #0x3
 *   @0x2e6a64 bls 0x2e6a84 <FT_Stream_GetULong+0x2a>
 *   @0x2e6a68 adds r3, #0x4
 *   @0x2e6a70 orr.w r0, r0, r1, lsl #24
 *   @0x2e6a74 ldrb r1, [r3, #-1]
 *   @0x2e6a78 orrs r0, r1
 *   @0x2e6a84 movs r0, #0x0
 *   @0x2e6a88 bx lr
 *
 * ══ FT_Stream_GetULongLE  0x2e6a8a  size 48  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6a8c 0x2e6ac8  size 60  12 条
 * 部分覆盖: 本节 12/27 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 11/25 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 9/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6a8c ldr r3, [r0, #0x20]
 *   @0x2e6a90 adds r0, r3, #0x3
 *   @0x2e6a94 bls 0x2e6ab4 <FT_Stream_GetULongLE+0x2a>
 *   @0x2e6a98 adds r3, #0x4
 *   @0x2e6aa0 orr.w r0, r0, r1, lsl #24
 *   @0x2e6aa4 ldrb r1, [r3, #-4]
 *   @0x2e6aa8 orrs r0, r1
 *   @0x2e6ab4 movs r0, #0x0
 *   @0x2e6ab8 bx lr
 *
 * ══ FT_Stream_ReadChar  0x2e6aba  size 74  本节 15 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e6abc 0x2e6b04  size 72  15 条
 * 部分覆盖: 本节 15/33 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6abc movs r3, #0x0
 *   @0x2e6ac0 mov r4, r0
 *   @0x2e6ac4 mov r5, r1
 *   @0x2e6acc ldr r1, [r0, #0x8]
 *   @0x2e6ad4 blx r6
 *   @0x2e6ad8 bne 0x2e6af8 <FT_Stream_ReadChar+0x3e>
 *   @0x2e6adc ldr r3, [r0, #0x8]
 *   @0x2e6ae0 cmp r3, r2
 *   @0x2e6ae4 ldr r2, [r0]
 *   @0x2e6ae8 strb.w r3, [sp, #0x7]
 *   @0x2e6aec ldr r3, [r4, #0x8]
 *   @0x2e6af4 str r3, [r4, #0x8]
 *   @0x2e6af8 movs r0, #0x0
 *   @0x2e6afc str r3, [r5]
 *   @0x2e6b00 add sp, #0x8
 *
 * ══ FT_Stream_ReadUShort  0x2e6b04  size 76  本节 18 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6b06 0x2e6b52  size 76  18 条
 * 部分覆盖: 本节 18/37 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6b06 movs r3, #0x0
 *   @0x2e6b0a mov r5, r1
 *   @0x2e6b0e mov r4, r0
 *   @0x2e6b12 adds r1, r3, #0x1
 *   @0x2e6b16 bhs 0x2e6b46 <FT_Stream_ReadUShort+0x42>
 *   @0x2e6b1a cbz r7, 0x2e6b2e <FT_Stream_ReadUShort+0x2a>
 *   @0x2e6b1e mov r1, r3
 *   @0x2e6b22 mov r2, r6
 *   @0x2e6b26 cmp r0, #0x2
 *   @0x2e6b2a mov r3, r6
 *   @0x2e6b2e ldr r2, [r0]
 *   @0x2e6b32 beq 0x2e6b3c <FT_Stream_ReadUShort+0x38>
 *   @0x2e6b36 ldrb r3, [r3, #0x1]
 *   @0x2e6b3e mov r0, r3
 *   @0x2e6b42 str r2, [r4, #0x8]
 *   @0x2e6b46 movs r0, #0x0
 *   @0x2e6b4a str r3, [r5]
 *   @0x2e6b4e pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Raccess_Get_HeaderInfo  0x2e6b50  size 468  本节 90 条（Thumb-2 半字段）｜入度 16
 * @func 0x2e6b56 0x2e6d36  size 480  94 条
 * 部分覆盖: 本节 94/214 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 93/212 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 92/210 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 91/208 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 90/206 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6b56 ldr r6, [pc, #0x1c8]
 *   @0x2e6b5a str r3, [sp, #0x8]
 *   @0x2e6b5e add r6, pc
 *   @0x2e6b62 mov r1, r2
 *   @0x2e6b66 ldr r7, [sp, #0x60]
 *   @0x2e6b6a str r3, [sp, #0x34]
 *   @0x2e6b72 str r0, [sp, #0x10]
 *   @0x2e6b76 bne.w 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6b7a add r6, sp, #0x14
 *   @0x2e6b7e movs r2, #0x10
 *   @0x2e6b82 bl 0x2e698e <FT_Stream_Read>
 *   @0x2e6b86 str r0, [sp, #0x10]
 *   @0x2e6b8a bne.w 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6b8e ldrb.w r1, [sp, #0x14]
 *   @0x2e6b92 lsls r0, r1, #0x18
 *   @0x2e6b96 movs r0, #0x2
 *   @0x2e6b9a ldrb.w r12, [sp, #0x18]
 *   @0x2e6b9e tst.w r12, #0x80
 *   @0x2e6ba2 bne 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6baa bmi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6bb2 bmi 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6bc2 ldrb.w r10, [sp, #0x1f]
 *   @0x2e6bc6 orr.w r1, r3, r1, lsl #24
 *   @0x2e6bca ldrb.w r3, [sp, #0x16]
 *   @0x2e6bce orr.w r1, r1, r8
 *   @0x2e6bd2 ldrb.w r8, [sp, #0x1b]
 *   @0x2e6bd6 ldrb.w r9, [sp, #0x23]
 *   @0x2e6bda orr.w r3, r1, r3, lsl #8
 *   @0x2e6bde ldrb.w r1, [sp, #0x19]
 *   @0x2e6be2 str r3, [r7]
 *   @0x2e6be6 orr.w r1, r1, r12, lsl #24
 *   @0x2e6bea ldrb.w r12, [sp, #0x1a]
 *   @0x2e6bee orr.w r1, r1, r8
 *   @0x2e6bf2 ldrb.w r8, [sp, #0x1e]
 *   @0x2e6bf6 orrs.w r1, r1, r12, lsl #8
 *   @0x2e6bfa str.w r8, [sp]
 *   @0x2e6bfe ldrb.w r8, [sp, #0x21]
 *   @0x2e6c02 str.w r8, [sp, #0x4]
 *   @0x2e6c06 ldrb.w r8, [sp, #0x22]
 *   @0x2e6c0a beq 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c1a orr.w r11, r11, r10
 *   @0x2e6c1e orr.w r11, r11, r12, lsl #8
 *   @0x2e6c22 ldr.w r12, [sp, #0x4]
 *   @0x2e6c26 lsl.w r0, r12, #0x10
 *   @0x2e6c2a orr.w r2, r0, r2, lsl #24
 *   @0x2e6c2e orr.w r9, r2, r9
 *   @0x2e6c32 orr.w r8, r9, r8, lsl #8
 *   @0x2e6c36 bge 0x2e6c40 <FT_Raccess_Get_HeaderInfo+0xf0>
 *   @0x2e6c3e b 0x2e6c46 <FT_Raccess_Get_HeaderInfo+0xf6>
 *   @0x2e6c46 bgt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c52 blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c5e blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c6a cmp r2, r5
 *   @0x2e6c6e add.w r0, r1, r8
 *   @0x2e6c72 mvn r2, #0x80000000
 *   @0x2e6c76 subs r2, r2, r0
 *   @0x2e6c7a blt 0x2e6b96 <FT_Raccess_Get_HeaderInfo+0x46>
 *   @0x2e6c7e ldr r2, [r4, #0x4]
 *   @0x2e6c82 cmp r11, r2
 *   @0x2e6c86 add r5, r1
 *   @0x2e6c8a cmp r8, r2
 *   @0x2e6c8e str r3, [r7]
 *   @0x2e6c92 mov r1, r5
 *   @0x2e6c9a cmp r0, #0x0
 *   @0x2e6c9e add r7, sp, #0x24
 *   @0x2e6ca6 movs r2, #0x10
 *   @0x2e6caa adds r3, #0x1
 *   @0x2e6cb6 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6cba mov r2, r3
 *   @0x2e6cbe ldrb.w r12, [r6, r0]
 *   @0x2e6cc2 adds r0, #0x1
 *   @0x2e6cc6 it ne
 *   @0x2e6cca cmp r12, r1
 *   @0x2e6cce movne r3, #0x0
 *   @0x2e6cd2 bne 0x2e6cbc <FT_Raccess_Get_HeaderInfo+0x16c>
 *   @0x2e6cd6 cmp r3, #0x0
 *   @0x2e6cde mov r0, r4
 *   @0x2e6ce6 str r0, [r1, #-40]!
 *   @0x2e6cea mov r0, r4
 *   @0x2e6cf2 ldr r0, [sp, #0x10]
 *   @0x2e6cf6 cmp r1, #0x0
 *   @0x2e6cfe mov r0, r4
 *   @0x2e6d02 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e6d06 cbnz r0, 0x2e6d0c <FT_Raccess_Get_HeaderInfo+0x1bc>
 *   @0x2e6d0a str r5, [r3]
 *   @0x2e6d0e ldr r2, [sp, #0x34]
 *   @0x2e6d12 cmp r2, r3
 *   @0x2e6d16 blx 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2e6d1a add sp, #0x3c
 *   @0x2e6d22 movs r0, r2
 *
 * ══ FT_Stream_ReadUShortLE  0x2e6d24  size 76  本节 18 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6d26 0x2e6d82  size 92  22 条
 * 部分覆盖: 本节 19/39 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 18/37 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6d26 movs r3, #0x0
 *   @0x2e6d2a mov r5, r1
 *   @0x2e6d2e mov r4, r0
 *   @0x2e6d32 adds r1, r3, #0x1
 *   @0x2e6d36 bhs 0x2e6d66 <FT_Stream_ReadUShortLE+0x42>
 *   @0x2e6d3a cbz r7, 0x2e6d4e <FT_Stream_ReadUShortLE+0x2a>
 *   @0x2e6d3e mov r1, r3
 *   @0x2e6d42 mov r2, r6
 *   @0x2e6d46 cmp r0, #0x2
 *   @0x2e6d4a mov r3, r6
 *   @0x2e6d4e ldr r2, [r0]
 *   @0x2e6d52 beq 0x2e6d5c <FT_Stream_ReadUShortLE+0x38>
 *   @0x2e6d56 ldrb r3, [r3]
 *   @0x2e6d5e mov r0, r3
 *   @0x2e6d62 str r2, [r4, #0x8]
 *   @0x2e6d66 movs r0, #0x0
 *   @0x2e6d6a str r3, [r5]
 *   @0x2e6d6e pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Stream_ReadUOffset  0x2e6d70  size 84  本节 20 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6d72 0x2e6dd6  size 100  24 条
 * 部分覆盖: 本节 20/41 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6d72 movs r3, #0x0
 *   @0x2e6d76 mov r5, r1
 *   @0x2e6d7a mov r4, r0
 *   @0x2e6d7e adds r1, r3, #0x2
 *   @0x2e6d82 bhs 0x2e6dba <FT_Stream_ReadUOffset+0x4a>
 *   @0x2e6d86 cbz r7, 0x2e6d9a <FT_Stream_ReadUOffset+0x2a>
 *   @0x2e6d8a mov r1, r3
 *   @0x2e6d8e mov r2, r6
 *   @0x2e6d92 cmp r0, #0x3
 *   @0x2e6d96 mov r2, r6
 *   @0x2e6d9a ldr r2, [r0]
 *   @0x2e6d9e beq 0x2e6db0 <FT_Stream_ReadUOffset+0x40>
 *   @0x2e6da2 ldrb r3, [r2]
 *   @0x2e6da6 orr.w r0, r0, r3, lsl #16
 *   @0x2e6daa ldrb r3, [r2, #0x2]
 *   @0x2e6db2 mov r0, r2
 *   @0x2e6db6 str r3, [r4, #0x8]
 *   @0x2e6dba movs r0, #0x0
 *   @0x2e6dbe str r3, [r5]
 *   @0x2e6dc2 pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Stream_ReadULong  0x2e6dc4  size 88  本节 21 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6dc6 0x2e6e1e  size 88  21 条
 * 部分覆盖: 本节 21/43 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6dc6 movs r3, #0x0
 *   @0x2e6dca mov r5, r1
 *   @0x2e6dce mov r4, r0
 *   @0x2e6dd2 adds r1, r3, #0x3
 *   @0x2e6dd6 bhs 0x2e6e12 <FT_Stream_ReadULong+0x4e>
 *   @0x2e6dda cbz r7, 0x2e6dee <FT_Stream_ReadULong+0x2a>
 *   @0x2e6dde mov r1, r3
 *   @0x2e6de2 mov r2, r6
 *   @0x2e6de6 cmp r0, #0x4
 *   @0x2e6dea mov r2, r6
 *   @0x2e6dee ldr r2, [r0]
 *   @0x2e6df2 beq 0x2e6e08 <FT_Stream_ReadULong+0x44>
 *   @0x2e6df6 ldrb r3, [r2]
 *   @0x2e6dfa orr.w r0, r0, r3, lsl #24
 *   @0x2e6dfe ldrb r3, [r2, #0x3]
 *   @0x2e6e02 orrs r0, r3
 *   @0x2e6e0a mov r0, r2
 *   @0x2e6e0e str r3, [r4, #0x8]
 *   @0x2e6e12 movs r0, #0x0
 *   @0x2e6e16 str r3, [r5]
 *   @0x2e6e1a pop {r4, r5, r6, r7, pc}
 *
 * ══ anon_2e6e1c  0x2e6e1c  size 200  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6ee4 0x2e6ee8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6ee4 andeq r1, r5, r7, lsl #12
 *
 * ══ FT_Stream_ReadULongLE  0x2e6ee8  size 88  本节 21 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e6eea 0x2e6f4e  size 100  24 条
 * 部分覆盖: 本节 22/45 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/43 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6eea movs r3, #0x0
 *   @0x2e6eee mov r5, r1
 *   @0x2e6ef2 mov r4, r0
 *   @0x2e6ef6 adds r1, r3, #0x3
 *   @0x2e6efa bhs 0x2e6f36 <FT_Stream_ReadULongLE+0x4e>
 *   @0x2e6efe cbz r7, 0x2e6f12 <FT_Stream_ReadULongLE+0x2a>
 *   @0x2e6f02 mov r1, r3
 *   @0x2e6f06 mov r2, r6
 *   @0x2e6f0a cmp r0, #0x4
 *   @0x2e6f0e mov r2, r6
 *   @0x2e6f12 ldr r2, [r0]
 *   @0x2e6f16 beq 0x2e6f2c <FT_Stream_ReadULongLE+0x44>
 *   @0x2e6f1a ldrb r3, [r2, #0x3]
 *   @0x2e6f1e orr.w r0, r0, r3, lsl #24
 *   @0x2e6f22 ldrb r3, [r2]
 *   @0x2e6f26 orrs r0, r3
 *   @0x2e6f2e mov r0, r2
 *   @0x2e6f32 str r3, [r4, #0x8]
 *   @0x2e6f36 movs r0, #0x0
 *   @0x2e6f3a str r3, [r5]
 *   @0x2e6f3e pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Atan2  0x2e6f40  size 32  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6f42 0x2e6f72  size 48  11 条
 * 部分覆盖: 本节 7/15 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6f42 cbnz r0, 0x2e6f46 <FT_Atan2+0x6>
 *   @0x2e6f46 stm.w sp, {r0, r1}
 *   @0x2e6f4a mov r0, sp
 *   @0x2e6f52 bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234>
 *   @0x2e6f56 ldr r0, [sp, #0x4]
 *   @0x2e6f5a mov r0, r1
 *   @0x2e6f5e pop {r4, pc}
 *
 * ══ FT_Vector_Unit  0x2e6f60  size 40  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6f62 0x2e6f9a  size 56  14 条
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6f62 mov r4, r0
 *   @0x2e6f66 ldr r2, [pc, #0x1c]
 *   @0x2e6f6a stm.w r0, {r2, r3}
 *   @0x2e6f6e bl 0x2e4ac4 <_ZNK11b2GearJoint8GetRatioEv+0x1c0>
 *   @0x2e6f72 ldr r3, [r4]
 *   @0x2e6f76 asrs r3, r3, #0x8
 *   @0x2e6f7a ldr r3, [r4, #0x4]
 *   @0x2e6f7e asrs r3, r3, #0x8
 *   @0x2e6f82 pop {r4, pc}
 *   @0x2e6f86 lsls r3, r3, #0x3
 *
 * ══ FT_Cos  0x2e6f88  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6f8a 0x2e6f9a  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6f8a mov r1, r0
 *   @0x2e6f8e bl 0x2e6f60 <FT_Vector_Unit>
 *   @0x2e6f92 ldr r0, [sp]
 *   @0x2e6f96 ldr pc, [sp], #4
 *
 * ══ FT_Sin  0x2e6f9a  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6f9c 0x2e6fac  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6f9c mov r1, r0
 *   @0x2e6fa0 bl 0x2e6f60 <FT_Vector_Unit>
 *   @0x2e6fa4 ldr r0, [sp, #0x4]
 *   @0x2e6fa8 ldr pc, [sp], #4
 *
 * ══ FT_Tan  0x2e6fac  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e6fae 0x2e6fc2  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6fae mov r1, r0
 *   @0x2e6fb2 bl 0x2e6f60 <FT_Vector_Unit>
 *   @0x2e6fb6 ldr r0, [sp, #0x4]
 *   @0x2e6fba bl 0x2e4eb6 <FT_DivFix>
 *   @0x2e6fbe add sp, #0xc
 *
 * ══ FT_Vector_Rotate  0x2e6fc4  size 100  本节 21 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e6fc6 0x2e703a  size 116  25 条
 * 部分覆盖: 本节 24/52 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/50 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/46 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e6fc6 mov r7, r1
 *   @0x2e6fca cbz r0, 0x2e7024 <FT_Vector_Rotate+0x60>
 *   @0x2e6fce ldm r0, {r0, r1}
 *   @0x2e6fd6 cbz r1, 0x2e7024 <FT_Vector_Rotate+0x60>
 *   @0x2e6fda bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8>
 *   @0x2e6fde mov r1, r7
 *   @0x2e6fe2 mov r0, sp
 *   @0x2e6fea bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166>
 *   @0x2e6fee mov r6, r0
 *   @0x2e6ff2 bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166>
 *   @0x2e6ff6 cmp r5, #0x0
 *   @0x2e6ffa subs r3, r5, #0x1
 *   @0x2e6ffe lsl.w r3, r2, r3
 *   @0x2e7002 adds r2, r6, r3
 *   @0x2e7006 add.w r6, r2, r6, asr #31
 *   @0x2e700a add.w r0, r3, r0, asr #31
 *   @0x2e700e asrs r6, r5
 *   @0x2e7016 b 0x2e7022 <FT_Vector_Rotate+0x5e>
 *   @0x2e701a lsls r6, r5
 *   @0x2e7022 str r5, [r4, #0x4]
 *   @0x2e7026 pop {r4, r5, r6, r7, pc}
 *
 * ══ FT_Vector_Length  0x2e7028  size 82  本节 18 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e702a 0x2e707a  size 80  18 条
 * 部分覆盖: 本节 18/38 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e702a cbz r0, 0x2e7076 <FT_Vector_Length+0x4e>
 *   @0x2e702e stm.w sp, {r0, r1}
 *   @0x2e7032 mov r3, r0
 *   @0x2e7036 cbnz r3, 0x2e7040 <FT_Vector_Length+0x18>
 *   @0x2e703a it lt
 *   @0x2e703e b 0x2e7076 <FT_Vector_Length+0x4e>
 *   @0x2e7042 eor.w r0, r3, r3, asr #31
 *   @0x2e7046 sub.w r0, r0, r3, asr #31
 *   @0x2e704a b 0x2e7076 <FT_Vector_Length+0x4e>
 *   @0x2e704e bl 0x2e4bdc <_ZNK11b2GearJoint8GetRatioEv+0x2d8>
 *   @0x2e7052 mov r5, r0
 *   @0x2e7056 bl 0x2e4b38 <_ZNK11b2GearJoint8GetRatioEv+0x234>
 *   @0x2e705a ldr r0, [sp]
 *   @0x2e7062 ble 0x2e7072 <FT_Vector_Length+0x4a>
 *   @0x2e7066 movs r2, #0x1
 *   @0x2e706e asrs r0, r5
 *   @0x2e7072 rsbs r5, r5, #0
 *   @0x2e7076 add sp, #0xc
 *
 * ══ FT_Hypot  0x2e707a  size 18  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e707c 0x2e708c  size 16  3 条
 * 部分覆盖: 本节 3/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e707c stm.w sp, {r0, r1}
 *   @0x2e7080 mov r0, sp
 *   @0x2e7088 ldr pc, [sp], #4
 *
 * ══ FT_Vector_Polarize  0x2e708c  size 66  本节 14 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e708e 0x2e70ce  size 64  14 条
 * 部分覆盖: 本节 14/30 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e708e mov r6, r1
 *   @0x2e7092 cbz r0, 0x2e70ca <FT_Vector_Polarize+0x3e>
 *   @0x2e7096 cbz r2, 0x2e70ca <FT_Vector_Polarize+0x3e>
 *   @0x2e709a stm.w sp, {r0, r1}
 *   @0x2e709e cbnz r0, 0x2e70a2 <FT_Vector_Polarize+0x16>
 *   @0x2e70a2 mov r0, sp
 *   @0x2e70aa mov r0, sp
 *   @0x2e70b2 bl 0x2e4a6a <_ZNK11b2GearJoint8GetRatioEv+0x166>
 *   @0x2e70b6 ldr r3, [sp, #0x4]
 *   @0x2e70ba itet lt
 *   @0x2e70be asrge.w r5, r0, r5
 *   @0x2e70c2 lsllt.w r5, r0, r5
 *   @0x2e70c6 str r5, [r6]
 *   @0x2e70ca add sp, #0xc
 *
 * ══ FT_Vector_From_Polar  0x2e70ce  size 16  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e70d0 0x2e70ea  size 26  7 条
 * 部分覆盖: 本节 5/9 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e70d0 str r1, [r0]
 *   @0x2e70d4 str r1, [r0, #0x4]
 *   @0x2e70d8 b.w 0x2e6fc4 <FT_Vector_Rotate>
 *   @0x2e70dc bx lr
 *
 * ══ anon_2e70de  0x2e70de  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e70de 0x2e70ea  size 12  3 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e70de blmi 0x4670e6 <g_RomDisk+0x6f8c6>
 *
 * ══ FT_Angle_Diff  0x2e70e0  size 32  本节 6 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e70e2 0x2e7112  size 48  10 条
 * 部分覆盖: 本节 6/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e70e2 subs r0, r1, r0
 *   @0x2e70e6 bge 0x2e70ee <FT_Angle_Diff+0xe>
 *   @0x2e70ee cmp.w r0, #0xb40000
 *   @0x2e70f2 ble 0x2e70fa <FT_Angle_Diff+0x1a>
 *   @0x2e70fa bx lr
 *   @0x2e70fe vqrshl.u8 d27, d0, d12
 *
 * ══ ft_mem_qalloc  0x2e7100  size 38  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e7102 0x2e7126  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7102 mov r4, r2
 *   @0x2e7106 mov r3, r0
 *   @0x2e710a ldr r3, [r0, #0x4]
 *   @0x2e710e cmp r0, #0x0
 *   @0x2e7112 moveq r3, #0x40
 *   @0x2e7116 b 0x2e7122 <ft_mem_qalloc+0x22>
 *   @0x2e711a moveq r0, r2
 *   @0x2e711e moveq r3, r0
 *   @0x2e7122 str r3, [r4]
 *
 * ══ ft_mem_alloc  0x2e7126  size 38  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7128 0x2e714c  size 36  7 条
 * 部分覆盖: 本节 7/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7128 mov r5, r2
 *   @0x2e712c mov r4, r1
 *   @0x2e7134 mov r6, r0
 *   @0x2e7138 cmp r4, #0x0
 *   @0x2e713c mov r2, r4
 *   @0x2e7144 mov r0, r6
 *   @0x2e7148 add sp, #0x8
 *
 * ══ FT_GlyphLoader_New  0x2e714c  size 28  本节 7 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e714e 0x2e716a  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e714e mov r4, r1
 *   @0x2e7152 movs r1, #0x60
 *   @0x2e7156 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e715a ldr r3, [sp, #0x4]
 *   @0x2e715e str r5, [r0]
 *   @0x2e7162 ldr r0, [sp, #0x4]
 *   @0x2e7166 pop {r4, r5, pc}
 *
 * ══ anon_2e7168  0x2e7168  size 396  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e72f4 0x2e72f8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e72f4 muleq r10, r4, r4
 *
 * ══ FT_New_Library  0x2e72f8  size 62  本节 14 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e72fa 0x2e7336  size 60  14 条
 * 部分覆盖: 本节 14/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e72fa mov r4, r1
 *   @0x2e72fe cbz r0, 0x2e732c <FT_New_Library+0x34>
 *   @0x2e7302 movs r1, #0xc0
 *   @0x2e7306 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e730a ldr r3, [sp, #0x4]
 *   @0x2e730e movs r2, #0x2
 *   @0x2e7312 str r2, [r0, #0x4]
 *   @0x2e7316 str.w r3, [r0, #0xa8]
 *   @0x2e731a str r2, [r0, #0x8]
 *   @0x2e731e str.w r3, [r0, #0xa4]
 *   @0x2e7322 str r3, [r0, #0xc]
 *   @0x2e732a b 0x2e7330 <FT_New_Library+0x38>
 *   @0x2e732e b 0x2e7332 <FT_New_Library+0x3a>
 *   @0x2e7332 add sp, #0xc
 *
 * ══ ft_mem_free  0x2e7336  size 10  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7338 0x2e7340  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7338 cbz r1, 0x2e733e <ft_mem_free+0x8>
 *   @0x2e733c blx r3
 *
 * ══ FT_GlyphLoader_Reset  0x2e7340  size 76  本节 14 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7342 0x2e7386  size 68  14 条
 * 部分覆盖: 本节 14/31 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7342 mov r4, r0
 *   @0x2e7346 movs r5, #0x0
 *   @0x2e734a mov r0, r6
 *   @0x2e7352 ldr r1, [r4, #0x1c]
 *   @0x2e7356 bl 0x2e7336 <ft_mem_free>
 *   @0x2e735a mov r0, r6
 *   @0x2e735e str r5, [r4, #0x1c]
 *   @0x2e7366 ldr r1, [r4, #0x28]
 *   @0x2e736a bl 0x2e7336 <ft_mem_free>
 *   @0x2e736e mov r0, r6
 *   @0x2e7372 ldr r1, [r4, #0x34]
 *   @0x2e737a str r5, [r4, #0x2c]
 *   @0x2e737e str r5, [r4, #0x4]
 *   @0x2e7382 str r5, [r4, #0xc]
 *
 * ══ FT_GlyphLoader_Done  0x2e738c  size 26  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e738e 0x2e739e  size 16  3 条
 * 部分覆盖: 本节 3/7 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e738e mov r4, r0
 *   @0x2e7392 ldr r5, [r0]
 *   @0x2e739a mov r0, r5
 *
 * ══ ft_hash_str_free  0x2e73a6  size 54  本节 12 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e73ac 0x2e73dc  size 48  12 条
 * 部分覆盖: 本节 12/24 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e73ac mov r4, r0
 *   @0x2e73b0 ldr.w r8, [r0, #0x4]
 *   @0x2e73b4 movs r5, #0x0
 *   @0x2e73b8 mov r9, r5
 *   @0x2e73bc mov r0, r7
 *   @0x2e73c0 ldr r1, [r6]
 *   @0x2e73c4 bl 0x2e7336 <ft_mem_free>
 *   @0x2e73c8 str r9, [r6], #4
 *   @0x2e73cc b 0x2e73ba <ft_hash_str_free+0x14>
 *   @0x2e73d0 bl 0x2e7336 <ft_mem_free>
 *   @0x2e73d4 movs r3, #0x0
 *   @0x2e73d8 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ FT_Stream_New  0x2e73dc  size 130  本节 28 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e73de 0x2e745e  size 128  28 条
 * 部分覆盖: 本节 28/60 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e73de movs r3, #0x0
 *   @0x2e73e2 mov r7, r2
 *   @0x2e73e6 cmp r0, #0x0
 *   @0x2e73ea cmp r1, #0x0
 *   @0x2e73ee ldr r6, [r0]
 *   @0x2e73f2 add r2, sp, #0x4
 *   @0x2e73f6 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e73fa ldr r3, [sp, #0x4]
 *   @0x2e73fe cbnz r3, 0x2e7450 <FT_Stream_New+0x74>
 *   @0x2e7402 ldr r3, [r5]
 *   @0x2e7406 bpl 0x2e7412 <FT_Stream_New+0x36>
 *   @0x2e740a ldr r2, [r5, #0x8]
 *   @0x2e7412 lsls r2, r3, #0x1d
 *   @0x2e7416 ldr r1, [r5, #0xc]
 *   @0x2e741e str r3, [r4, #0x10]
 *   @0x2e7422 b 0x2e743c <FT_Stream_New+0x60>
 *   @0x2e7426 bpl 0x2e7438 <FT_Stream_New+0x5c>
 *   @0x2e742a cbz r3, 0x2e7438 <FT_Stream_New+0x5c>
 *   @0x2e742e mov r0, r6
 *   @0x2e7436 b 0x2e743c <FT_Stream_New+0x60>
 *   @0x2e743a str r3, [sp, #0x4]
 *   @0x2e743e cbz r3, 0x2e744c <FT_Stream_New+0x70>
 *   @0x2e7442 mov r0, r6
 *   @0x2e744a b 0x2e744e <FT_Stream_New+0x72>
 *   @0x2e744e str r4, [r7]
 *   @0x2e7452 b 0x2e745a <FT_Stream_New+0x7e>
 *   @0x2e7456 b 0x2e745a <FT_Stream_New+0x7e>
 *   @0x2e745a add sp, #0xc
 *
 * ══ FT_Stream_Free  0x2e745e  size 30  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7460 0x2e7474  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7460 mov r6, r1
 *   @0x2e7464 cbz r0, 0x2e747a <FT_Stream_Free+0x1c>
 *   @0x2e7468 bl 0x2e689a <FT_Stream_Close>
 *   @0x2e746c cbnz r6, 0x2e747a <FT_Stream_Free+0x1c>
 *   @0x2e7470 mov r1, r4
 *
 * ══ anon_2e747e  0x2e747e  size 60  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e74ba 0x2e74ce  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e74ba ldrblt r0, [r3, #-0x5]!
 *
 * ══ FT_Attach_Stream  0x2e74bc  size 70  本节 14 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e74be 0x2e7502  size 68  14 条
 * 部分覆盖: 本节 14/31 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e74be mov r6, r1
 *   @0x2e74c2 cbz r0, 0x2e74f8 <FT_Attach_Stream+0x3c>
 *   @0x2e74c6 cbz r5, 0x2e74fc <FT_Attach_Stream+0x40>
 *   @0x2e74ca add r2, sp, #0x4
 *   @0x2e74d2 ldr r3, [r5, #0xc]
 *   @0x2e74d6 cbz r3, 0x2e74e2 <FT_Attach_Stream+0x26>
 *   @0x2e74da ldr r1, [sp, #0x4]
 *   @0x2e74de mov r4, r0
 *   @0x2e74e2 movs r4, #0x7
 *   @0x2e74e6 ldr r0, [sp, #0x4]
 *   @0x2e74ea ldr r1, [r6]
 *   @0x2e74f6 b 0x2e74fe <FT_Attach_Stream+0x42>
 *   @0x2e74fa b 0x2e74fe <FT_Attach_Stream+0x42>
 *   @0x2e74fe add sp, #0x8
 *
 * ══ FT_Attach_File  0x2e7502  size 32  本节 7 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e7504 0x2e7520  size 28  7 条
 * 部分覆盖: 本节 7/14 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7504 sub sp, #0x24
 *   @0x2e7508 str r1, [sp, #0xc]
 *   @0x2e750c movs r3, #0x0
 *   @0x2e7510 movs r3, #0x4
 *   @0x2e7514 bl 0x2e74bc <FT_Attach_Stream>
 *   @0x2e7518 b 0x2e751c <FT_Attach_File+0x1a>
 *   @0x2e751c add sp, #0x24
 *
 * ══ ft_glyphslot_free_bitmap  0x2e7522  size 50  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7524 0x2e7554  size 48  10 条
 * 部分覆盖: 本节 10/22 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7524 mov r4, r0
 *   @0x2e752c ldr r3, [r3, #0x4]
 *   @0x2e7530 bpl 0x2e754e <ft_glyphslot_free_bitmap+0x2c>
 *   @0x2e7534 ldr r1, [r4, #0x58]
 *   @0x2e7538 bl 0x2e7336 <ft_mem_free>
 *   @0x2e753c movs r3, #0x0
 *   @0x2e7540 ldr.w r3, [r4, #0x9c]
 *   @0x2e7544 ldr r2, [r3, #0x4]
 *   @0x2e754c pop {r4, pc}
 *   @0x2e7550 str r3, [r4, #0x58]
 *
 * ══ ft_glyphslot_set_bitmap  0x2e7554  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7556 0x2e7562  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7556 mov r4, r0
 *   @0x2e755a bl 0x2e7522 <ft_glyphslot_free_bitmap>
 *   @0x2e755e str r5, [r4, #0x58]
 *
 * ══ FT_Load_Glyph  0x2e7564  size 808  本节 167 条（Thumb-2 半字段）｜入度 24
 * @func 0x2e756a 0x2e788e  size 804  167 条
 * 部分覆盖: 本节 167/368 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e756a sub sp, #0x14
 *   @0x2e756e mov r6, r0
 *   @0x2e7572 beq 0x2e7672 <FT_Load_Glyph+0x10e>
 *   @0x2e7576 cmp r3, #0x0
 *   @0x2e757a ldr r4, [r0, #0x54]
 *   @0x2e757e beq 0x2e7672 <FT_Load_Glyph+0x10e>
 *   @0x2e7582 add.w r8, r4, #0x6c
 *   @0x2e7586 bl 0x2e7522 <ft_glyphslot_free_bitmap>
 *   @0x2e758a movs r1, #0x0
 *   @0x2e758e add.w r0, r4, #0x18
 *   @0x2e7592 blx 0xb65b0 <memset@plt>
 *   @0x2e7596 movs r2, #0x14
 *   @0x2e759a movs r1, #0x0
 *   @0x2e75a2 str r7, [r4, #0x50]
 *   @0x2e75a6 str r7, [r4, #0x4c]
 *   @0x2e75aa orrmi r5, r5, #0x800
 *   @0x2e75ae str r7, [r4, #0x54]
 *   @0x2e75b2 orrmi r5, r5, #0x1
 *   @0x2e75b6 strb.w r7, [r4, #0x5e]
 *   @0x2e75ba str r7, [r4, #0x64]
 *   @0x2e75be str.w r7, [r4, #0x80]
 *   @0x2e75c2 str.w r7, [r4, #0x84]
 *   @0x2e75c6 str.w r7, [r4, #0x88]
 *   @0x2e75ca str.w r7, [r4, #0x8c]
 *   @0x2e75ce str.w r7, [r4, #0x98]
 *   @0x2e75d2 str r7, [r4, #0x48]
 *   @0x2e75d6 str r7, [r4, #0x3c]
 *   @0x2e75e2 ldr r3, [r7, #0x4]
 *   @0x2e75ea itt mi
 *   @0x2e75f6 it mi
 *   @0x2e7602 movw r3, #0x8002
 *   @0x2e7606 ands r3, r5
 *   @0x2e760a bne 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e760e ldr r3, [r2]
 *   @0x2e761a ldr r3, [r6, #0x8]
 *   @0x2e761e bmi 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7622 bmi 0x2e7634 <FT_Load_Glyph+0xd0>
 *   @0x2e762a ldr r1, [r1]
 *   @0x2e762e cbnz r1, 0x2e7634 <FT_Load_Glyph+0xd0>
 *   @0x2e7632 cbnz r1, 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7636 bmi.w 0x2e7824 <FT_Load_Glyph+0x2c0>
 *   @0x2e763a ldr r2, [r2]
 *   @0x2e763e bpl.w 0x2e7824 <FT_Load_Glyph+0x2c0>
 *   @0x2e7642 ubfx r1, r5, #0x10, #0x4
 *   @0x2e7646 cmp r1, #0x1
 *   @0x2e764a lsls r1, r2, #0x14
 *   @0x2e7652 bpl 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e765a ldrh.w r2, [r6, #0x11e]
 *   @0x2e765e cbnz r2, 0x2e7676 <FT_Load_Glyph+0x112>
 *   @0x2e7666 ldr.w r2, [r6, #0x28c]
 *   @0x2e766a cmp r2, #0x0
 *   @0x2e7672 movs r0, #0x23
 *   @0x2e7676 ldr r3, [r7, #0xc]
 *   @0x2e767a ldr r1, [r6, #0x58]
 *   @0x2e767e ldr r7, [r3, #0x48]
 *   @0x2e7682 blx r7
 *   @0x2e7686 bne.w 0x2e7878 <FT_Load_Glyph+0x314>
 *   @0x2e768a ldr r3, [r4, #0x48]
 *   @0x2e768e cmp r3, r2
 *   @0x2e7692 movs r7, #0x0
 *   @0x2e7696 mov r0, r8
 *   @0x2e769e cmp r0, #0x0
 *   @0x2e76a6 bmi 0x2e7692 <FT_Load_Glyph+0x12e>
 *   @0x2e76ae ldr r3, [r4, #0x24]
 *   @0x2e76b2 ldr.w r12, [r4, #0x18]
 *   @0x2e76b6 ldr r1, [r4, #0x30]
 *   @0x2e76ba adds r3, #0x3f
 *   @0x2e76be bic r3, r3, #0x3f
 *   @0x2e76c2 str r3, [r4, #0x24]
 *   @0x2e76c6 add.w r12, r12, #0x3f
 *   @0x2e76ca bic r0, r0, #0x3f
 *   @0x2e76ce bic r12, r12, #0x3f
 *   @0x2e76d2 add r3, r1
 *   @0x2e76da bic r2, r2, #0x3f
 *   @0x2e76de bic r3, r3, #0x3f
 *   @0x2e76e2 str r0, [r4, #0x2c]
 *   @0x2e76e6 rsb r0, r0, r12
 *   @0x2e76ea subs r1, r3, r1
 *   @0x2e76ee str r0, [r4, #0x18]
 *   @0x2e76f2 b 0x2e772a <FT_Load_Glyph+0x1c6>
 *   @0x2e76fa ldr r1, [r4, #0x1c]
 *   @0x2e76fe add.w r12, r12, #0x3f
 *   @0x2e7702 bic r2, r2, #0x3f
 *   @0x2e7706 subs r1, r3, r1
 *   @0x2e770a bic r3, r3, #0x3f
 *   @0x2e770e bic r12, r12, #0x3f
 *   @0x2e7712 bic r1, r1, #0x3f
 *   @0x2e7716 bic r0, r0, #0x3f
 *   @0x2e771a str r2, [r4, #0x20]
 *   @0x2e7722 subs r3, r3, r1
 *   @0x2e7726 str r2, [r4, #0x18]
 *   @0x2e772a ldr r3, [r4, #0x28]
 *   @0x2e772e bic r3, r3, #0x3f
 *   @0x2e7732 str r3, [r4, #0x28]
 *   @0x2e7736 adds r3, #0x20
 *   @0x2e773e ands r2, r5, #0x10
 *   @0x2e7742 beq 0x2e774e <FT_Load_Glyph+0x1ea>
 *   @0x2e7746 str r3, [r4, #0x40]
 *   @0x2e774a str r3, [r4, #0x44]
 *   @0x2e774e ldr r3, [r4, #0x28]
 *   @0x2e7752 str r3, [r4, #0x40]
 *   @0x2e7756 bmi 0x2e777e <FT_Load_Glyph+0x21a>
 *   @0x2e775a lsls r2, r3, #0x1f
 *   @0x2e775e ldr.w r9, [r6, #0x58]
 *   @0x2e7762 movs r2, #0x40
 *   @0x2e7766 ldr.w r1, [r9, #0x10]
 *   @0x2e776a bl 0x2e4d3c <FT_MulDiv>
 *   @0x2e776e movs r2, #0x40
 *   @0x2e7772 ldr r0, [r4, #0x3c]
 *   @0x2e777e lsls r3, r5, #0x14
 *   @0x2e7782 ldr.w r6, [r6, #0x80]
 *   @0x2e7786 ldr r3, [r6, #0x18]
 *   @0x2e778a beq 0x2e77f0 <FT_Load_Glyph+0x28c>
 *   @0x2e778e ldr r3, [r3, #0x60]
 *   @0x2e7792 ldr.w r3, [r0, #0x9c]
 *   @0x2e7796 cbz r3, 0x2e77a0 <FT_Load_Glyph+0x23c>
 *   @0x2e779a ldr r2, [r4, #0x48]
 *   @0x2e779e beq 0x2e77ac <FT_Load_Glyph+0x248>
 *   @0x2e77a2 movs r2, #0x0
 *   @0x2e77aa cbz r0, 0x2e77c0 <FT_Load_Glyph+0x25c>
 *   @0x2e77ae mov r0, r3
 *   @0x2e77b2 add.w r3, r6, #0x10
 *   @0x2e77b6 ldr r7, [r2, #0x2c]
 *   @0x2e77ba blx r7
 *   @0x2e77be b 0x2e77e6 <FT_Load_Glyph+0x282>
 *   @0x2e77c2 ldr r2, [pc, #0xbc]
 *   @0x2e77c6 bne 0x2e77e6 <FT_Load_Glyph+0x282>
 *   @0x2e77ca lsls r0, r3, #0x1f
 *   @0x2e77ce mov r0, r8
 *   @0x2e77d2 bl 0x2e6580 <FT_Outline_Transform>
 *   @0x2e77d6 ldr r3, [r6, #0x18]
 *   @0x2e77da bpl 0x2e77e6 <FT_Load_Glyph+0x282>
 *   @0x2e77de ldr r1, [r6, #0x10]
 *   @0x2e77e2 bl 0x2e6424 <FT_Outline_Translate>
 *   @0x2e77e6 add.w r0, r4, #0x40
 *   @0x2e77ea mov r1, r6
 *   @0x2e77f2 ldr r3, [r4, #0x48]
 *   @0x2e77f6 cmp r3, r2
 *   @0x2e77fa ldr r2, [pc, #0x8c]
 *   @0x2e77fe beq 0x2e7820 <FT_Load_Glyph+0x2bc>
 *   @0x2e7802 bpl 0x2e7820 <FT_Load_Glyph+0x2bc>
 *   @0x2e780a tst.w r5, #0x1000
 *   @0x2e780e ite eq
 *   @0x2e7812 movne r1, #0x2
 *   @0x2e7816 add sp, #0x14
 *   @0x2e7822 b 0x2e7878 <FT_Load_Glyph+0x314>
 *   @0x2e7826 bpl 0x2e782c <FT_Load_Glyph+0x2c8>
 *   @0x2e782a bpl 0x2e785a <FT_Load_Glyph+0x2f6>
 *   @0x2e7832 mov r1, r4
 *   @0x2e783a movs r3, #0x0
 *   @0x2e7846 str r5, [sp]
 *   @0x2e784a ldr r7, [r3, #0xc]
 *   @0x2e784e blx r7
 *   @0x2e7852 str.w r3, [r11, #0x18]
 *   @0x2e7856 mov r7, r0
 *   @0x2e785a ldr r3, [r7, #0xc]
 *   @0x2e785e ldr r1, [r6, #0x58]
 *   @0x2e7862 ldr r7, [r3, #0x48]
 *   @0x2e786a cmp r0, #0x0
 *   @0x2e786e ldr r3, [r4, #0x48]
 *   @0x2e7872 cmp r3, r2
 *   @0x2e7876 b 0x2e7692 <FT_Load_Glyph+0x12e>
 *   @0x2e787a pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e787e nop
 *   @0x2e7882 ldr r5, [r6, #0x74]
 *   @0x2e7886 str r1, [r5, #0x24]
 *   @0x2e788a str r7, [r5, #0x34]
 *
 * ══ FT_Get_Advances  0x2e788c  size 196  本节 38 条（Thumb-2 半字段）｜入度 9
 * @func 0x2e7892 0x2e794e  size 188  38 条
 * 部分覆盖: 本节 38/85 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7892 mov r7, r2
 *   @0x2e7896 ldr.w r8, [sp, #0x28]
 *   @0x2e789a mov r4, r0
 *   @0x2e789e beq 0x2e793c <FT_Get_Advances+0xb0>
 *   @0x2e78a6 ldr r3, [r0, #0x10]
 *   @0x2e78aa bhs 0x2e7944 <FT_Get_Advances+0xb8>
 *   @0x2e78b2 cmp r9, r3
 *   @0x2e78b6 cbnz r2, 0x2e78bc <FT_Get_Advances+0x30>
 *   @0x2e78ba b 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e78be ldr r3, [r3, #0xc]
 *   @0x2e78ca lsls r2, r6, #0x2
 *   @0x2e78ce orr r6, r6, #0x100
 *   @0x2e78d2 sub.w r7, r8, #0x4
 *   @0x2e78d6 and r8, r6, #0x10
 *   @0x2e78da b 0x2e7932 <FT_Get_Advances+0xa6>
 *   @0x2e78de bne 0x2e78e8 <FT_Get_Advances+0x5c>
 *   @0x2e78e6 bne 0x2e78ca <FT_Get_Advances+0x3e>
 *   @0x2e78ee mov r1, r5
 *   @0x2e78f2 mov r3, r6
 *   @0x2e78f6 cbnz r0, 0x2e790c <FT_Get_Advances+0x80>
 *   @0x2e78fe mov r2, r7
 *   @0x2e7902 add sp, #0xc
 *   @0x2e790e cmp r3, #0x7
 *   @0x2e7912 b 0x2e78ca <FT_Get_Advances+0x3e>
 *   @0x2e7916 mov r1, r5
 *   @0x2e791a bl 0x2e7564 <FT_Load_Glyph>
 *   @0x2e791e cbnz r0, 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e7922 cmp.w r8, #0x0
 *   @0x2e7926 beq 0x2e7938 <FT_Get_Advances+0xac>
 *   @0x2e792a adds r5, #0x1
 *   @0x2e792e str r3, [r7, #4]!
 *   @0x2e7932 cmp r5, r9
 *   @0x2e7936 b 0x2e78b8 <FT_Get_Advances+0x2c>
 *   @0x2e793a b 0x2e792a <FT_Get_Advances+0x9e>
 *   @0x2e793e b 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e7942 b 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e7946 b 0x2e794a <FT_Get_Advances+0xbe>
 *   @0x2e794a add sp, #0xc
 *
 * ══ FT_Get_Advance  0x2e7950  size 122  本节 24 条（Thumb-2 半字段）｜入度 8
 * @func 0x2e7952 0x2e79ca  size 120  24 条
 * 部分覆盖: 本节 24/54 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7952 mov r7, r1
 *   @0x2e7956 mov r6, r3
 *   @0x2e795a cmp r0, #0x0
 *   @0x2e795e cmp r3, #0x0
 *   @0x2e7962 ldr r3, [r0, #0x10]
 *   @0x2e7966 bhs 0x2e79c4 <FT_Get_Advance+0x74>
 *   @0x2e796a ldr r3, [r3, #0xc]
 *   @0x2e7976 str r6, [sp]
 *   @0x2e797a mov r1, r7
 *   @0x2e797e mov r3, r5
 *   @0x2e7986 lsls r3, r2, #0x1e
 *   @0x2e798a ubfx r3, r2, #0x10, #0x4
 *   @0x2e798e cmp r3, #0x1
 *   @0x2e7992 str r6, [sp]
 *   @0x2e7996 mov r1, r7
 *   @0x2e799a mov r3, r5
 *   @0x2e799e cbnz r0, 0x2e79b4 <FT_Get_Advance+0x64>
 *   @0x2e79a6 movs r2, #0x1
 *   @0x2e79aa add sp, #0xc
 *   @0x2e79b6 cmp r3, #0x7
 *   @0x2e79ba b 0x2e7976 <FT_Get_Advance+0x26>
 *   @0x2e79be b 0x2e79c6 <FT_Get_Advance+0x76>
 *   @0x2e79c2 b 0x2e79c6 <FT_Get_Advance+0x76>
 *   @0x2e79c6 add sp, #0xc
 *
 * ══ FT_Load_Char  0x2e79ca  size 38  本节 9 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e79cc 0x2e79f0  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e79cc mov r3, r1
 *   @0x2e79d0 mov r4, r0
 *   @0x2e79d4 ldr r5, [r0, #0x5c]
 *   @0x2e79d8 bl 0x2e5960 <FT_Get_Char_Index>
 *   @0x2e79dc mov r3, r0
 *   @0x2e79e0 mov r2, r6
 *   @0x2e79e4 pop.w {r4, r5, r6, lr}
 *   @0x2e79e8 b.w 0x2e7564 <FT_Load_Glyph>
 *   @0x2e79ec movs r0, #0x23
 *
 * ══ ft_glyphslot_alloc_bitmap  0x2e79f0  size 58  本节 13 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e79f2 0x2e7a2a  size 56  13 条
 * 部分覆盖: 本节 13/27 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e79f2 mov r6, r1
 *   @0x2e79f6 mov r4, r0
 *   @0x2e79fa ldr.w r3, [r0, #0x9c]
 *   @0x2e79fe ldr r2, [r3, #0x4]
 *   @0x2e7a02 bpl 0x2e7a12 <ft_glyphslot_alloc_bitmap+0x22>
 *   @0x2e7a06 ldr r1, [r4, #0x58]
 *   @0x2e7a0e str r3, [r4, #0x58]
 *   @0x2e7a12 orr r2, r2, #0x1
 *   @0x2e7a16 str r2, [r3, #0x4]
 *   @0x2e7a1a mov r1, r6
 *   @0x2e7a1e bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e7a22 str r0, [r4, #0x58]
 *   @0x2e7a26 add sp, #0x8
 *
 * ══ anon_2e7a2c  0x2e7a2c  size 64  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7a6c 0x2e7a70  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7a6c ldcllt p0, c3, [r0, #-624]!
 *
 * ══ FT_New_GlyphSlot  0x2e7a70  size 170  本节 38 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e7a76 0x2e7b1a  size 164  38 条
 * 部分覆盖: 本节 38/79 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7a76 mov r5, r0
 *   @0x2e7a7a beq 0x2e7b0e <FT_New_GlyphSlot+0x9e>
 *   @0x2e7a7e cmp r3, #0x0
 *   @0x2e7a82 ldr.w r8, [r3, #0x8]
 *   @0x2e7a86 mov r2, sp
 *   @0x2e7a8a mov r0, r8
 *   @0x2e7a8e bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e7a92 ldr r3, [sp]
 *   @0x2e7a96 cmp r3, #0x0
 *   @0x2e7a9a str r5, [r0, #0x4]
 *   @0x2e7a9e ldr r7, [r5, #0x60]
 *   @0x2e7aa2 str r3, [r2, #-4]!
 *   @0x2e7aa6 ldr.w r9, [r7, #0x8]
 *   @0x2e7aaa ldr r3, [r7, #0x4]
 *   @0x2e7ab2 mov r0, r9
 *   @0x2e7aba mov r1, r0
 *   @0x2e7abe str.w r0, [r4, #0x9c]
 *   @0x2e7ac2 ldr r3, [r7]
 *   @0x2e7ac6 lsls r3, r3, #0x16
 *   @0x2e7aca mov r0, r9
 *   @0x2e7ad2 ldr r3, [sp, #0x4]
 *   @0x2e7ad6 ldr.w r3, [r10, #0x40]
 *   @0x2e7ada cbz r3, 0x2e7ae2 <FT_New_GlyphSlot+0x72>
 *   @0x2e7ade blx r3
 *   @0x2e7ae2 ldr r3, [sp, #0x4]
 *   @0x2e7ae6 cbz r3, 0x2e7af8 <FT_New_GlyphSlot+0x88>
 *   @0x2e7aea bl 0x2e7a2a <ft_glyphslot_alloc_bitmap+0x3a>
 *   @0x2e7aee mov r0, r8
 *   @0x2e7af2 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7af6 b 0x2e7b0a <FT_New_GlyphSlot+0x9a>
 *   @0x2e7afa str r3, [r4, #0x8]
 *   @0x2e7afe cbz r6, 0x2e7b0a <FT_New_GlyphSlot+0x9a>
 *   @0x2e7b02 b 0x2e7b0a <FT_New_GlyphSlot+0x9a>
 *   @0x2e7b06 movs r3, #0x0
 *   @0x2e7b0a ldr r0, [sp]
 *   @0x2e7b0e movs r0, #0x23
 *   @0x2e7b12 movs r0, #0x6
 *   @0x2e7b16 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ FT_Done_GlyphSlot  0x2e7b1a  size 66  本节 16 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e7b1c 0x2e7b5c  size 64  16 条
 * 部分覆盖: 本节 16/32 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7b1c mov r4, r0
 *   @0x2e7b20 ldr r2, [r0, #0x4]
 *   @0x2e7b24 ldr r3, [r2, #0x60]
 *   @0x2e7b28 ldr r3, [r2, #0x54]
 *   @0x2e7b2c cmp r3, r4
 *   @0x2e7b30 ldr r3, [r4, #0x8]
 *   @0x2e7b34 str r3, [r2, #0x54]
 *   @0x2e7b38 str r3, [r1, #0x8]
 *   @0x2e7b3c cbz r3, 0x2e7b42 <FT_Done_GlyphSlot+0x28>
 *   @0x2e7b40 blx r3
 *   @0x2e7b44 bl 0x2e7a2a <ft_glyphslot_alloc_bitmap+0x3a>
 *   @0x2e7b48 mov r0, r5
 *   @0x2e7b4c pop.w {r3, r4, r5, lr}
 *   @0x2e7b50 b.w 0x2e7336 <ft_mem_free>
 *   @0x2e7b54 mov r1, r3
 *   @0x2e7b58 b 0x2e7b2a <FT_Done_GlyphSlot+0x10>
 *
 * ══ anon_2e7b5e  0x2e7b5e  size 600  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7db6 0x2e7dba  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7db6 blt 0xff2a5dba <b2_toiTime+0xfffffffffeb4c916>
 *
 * ══ FT_Outline_Done_Internal  0x2e7dba  size 68  本节 14 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e7dbc 0x2e7e04  size 72  15 条
 * 部分覆盖: 本节 14/31 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7dbc mov r6, r0
 *   @0x2e7dc0 cbz r1, 0x2e7df6 <FT_Outline_Done_Internal+0x3c>
 *   @0x2e7dc4 ldr r3, [r1, #0x10]
 *   @0x2e7dc8 bpl 0x2e7de8 <FT_Outline_Done_Internal+0x2e>
 *   @0x2e7dcc movs r5, #0x0
 *   @0x2e7dd4 ldr r1, [r4, #0x8]
 *   @0x2e7dd8 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7ddc str r5, [r4, #0x8]
 *   @0x2e7de0 ldr r1, [r4, #0xc]
 *   @0x2e7de8 mov r0, r4
 *   @0x2e7dec movs r2, #0x14
 *   @0x2e7df4 pop {r4, r5, r6, pc}
 *   @0x2e7df8 pop {r4, r5, r6, pc}
 *   @0x2e7dfc pop {r4, r5, r6, pc}
 *
 * ══ FT_Outline_Done  0x2e7dfe  size 12  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7e00 0x2e7e1c  size 28  6 条
 * 部分覆盖: 本节 2/5 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7e00 ldr r0, [r0]
 *   @0x2e7e08 bx lr
 *
 * ══ FT_Stream_ReleaseFrame  0x2e7e0a  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7e0c 0x2e7e24  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7e0c mov r4, r1
 *   @0x2e7e10 ldr r3, [r0, #0x14]
 *   @0x2e7e14 ldr r0, [r0, #0x1c]
 *   @0x2e7e18 bl 0x2e7336 <ft_mem_free>
 *   @0x2e7e1c movs r3, #0x0
 *   @0x2e7e20 pop {r4, pc}
 *
 * ══ FT_Stream_EnterFrame  0x2e7e22  size 128  本节 27 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e7e28 0x2e7ea0  size 120  27 条
 * 部分覆盖: 本节 27/57 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7e28 str r3, [sp, #0x4]
 *   @0x2e7e2c ldr r3, [r0, #0x14]
 *   @0x2e7e30 ldr r2, [r0, #0x4]
 *   @0x2e7e34 cmp r1, r2
 *   @0x2e7e3c movs r3, #0x55
 *   @0x2e7e40 b 0x2e7e9a <FT_Stream_EnterFrame+0x78>
 *   @0x2e7e44 mov r0, r8
 *   @0x2e7e4c mov r2, r0
 *   @0x2e7e50 cbnz r6, 0x2e7e9a <FT_Stream_EnterFrame+0x78>
 *   @0x2e7e54 mov r0, r4
 *   @0x2e7e58 mov r3, r5
 *   @0x2e7e5c cmp r0, r5
 *   @0x2e7e60 bhs 0x2e7e70 <FT_Stream_EnterFrame+0x4e>
 *   @0x2e7e64 ldr r1, [r4]
 *   @0x2e7e6c str r6, [r4]
 *   @0x2e7e70 ldr r3, [r4]
 *   @0x2e7e74 str r5, [r4, #0x24]
 *   @0x2e7e78 ldr r3, [r4, #0x8]
 *   @0x2e7e7c str r7, [r4, #0x8]
 *   @0x2e7e80 ldr r3, [r0, #0x8]
 *   @0x2e7e84 bhs 0x2e7e3c <FT_Stream_EnterFrame+0x1a>
 *   @0x2e7e88 cmp r2, r1
 *   @0x2e7e8c ldr r2, [r0]
 *   @0x2e7e90 str r5, [r0, #0x8]
 *   @0x2e7e94 str r2, [r0, #0x20]
 *   @0x2e7e98 str r2, [r0, #0x24]
 *   @0x2e7e9c add sp, #0x8
 *
 * ══ FT_Stream_ExtractFrame  0x2e7ea2  size 22  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7ea4 0x2e7eb8  size 20  5 条
 * 部分覆盖: 本节 5/10 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7ea4 mov r4, r0
 *   @0x2e7ea8 bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2e7eac cbnz r0, 0x2e7eb6 <FT_Stream_ExtractFrame+0x14>
 *   @0x2e7eb0 str r3, [r5]
 *   @0x2e7eb4 str r0, [r4, #0x24]
 *
 * ══ FT_Stream_ExitFrame  0x2e7eb8  size 28  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e7eba 0x2e7ed6  size 28  6 条
 * 部分覆盖: 本节 6/13 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7eba mov r4, r0
 *   @0x2e7ebe cbz r3, 0x2e7ecc <FT_Stream_ExitFrame+0x14>
 *   @0x2e7ec2 ldr r1, [r4]
 *   @0x2e7eca str r3, [r4]
 *   @0x2e7ece str r3, [r4, #0x20]
 *   @0x2e7ed2 pop {r4, pc}
 *
 * ══ FT_Stream_ReadFields  0x2e7ed4  size 316  本节 63 条（Thumb-2 半字段）｜入度 17
 * @func 0x2e7eda 0x2e800e  size 308  63 条
 * 部分覆盖: 本节 63/140 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e7eda mov r7, r2
 *   @0x2e7ede beq.w 0x2e7ffe <FT_Stream_ReadFields+0x12a>
 *   @0x2e7ee2 cmp r0, #0x0
 *   @0x2e7eea adds r5, r1, #0x4
 *   @0x2e7ef6 cmp r2, #0x15
 *   @0x2e7efa tbb [pc, r2]
 *   @0x2e7efe str r3, [r1, #0x10]
 *   @0x2e7f02 cmp r0, #0x28
 *   @0x2e7f06 cmp r4, #0x2c
 *   @0x2e7f0a adds r7, #0x37
 *   @0x2e7f0e ldr r6, [pc, #0x138]
 *   @0x2e7f12 adds r1, r3, r4
 *   @0x2e7f16 ldrh r1, [r5, #-2]
 *   @0x2e7f1a bl 0x2e7e22 <FT_Stream_EnterFrame>
 *   @0x2e7f1e mov r4, r0
 *   @0x2e7f22 bne 0x2e7ff0 <FT_Stream_ReadFields+0x11c>
 *   @0x2e7f26 mov.w r8, #0x1
 *   @0x2e7f2a adds r5, #0x4
 *   @0x2e7f2e b 0x2e7ef0 <FT_Stream_ReadFields+0x1c>
 *   @0x2e7f36 adds r4, r3, r2
 *   @0x2e7f3a bhi 0x2e7fee <FT_Stream_ReadFields+0x11a>
 *   @0x2e7f3e bne 0x2e7f2a <FT_Stream_ReadFields+0x56>
 *   @0x2e7f46 add r0, r7
 *   @0x2e7f4e adds r4, r3, #0x1
 *   @0x2e7f52 ldrb r3, [r3]
 *   @0x2e7f56 adds r4, r3, #0x2
 *   @0x2e7f5a ldrb r3, [r3, #0x1]
 *   @0x2e7f5e adds r4, r3, #0x2
 *   @0x2e7f62 ldrb r3, [r3]
 *   @0x2e7f6a b 0x2e7fc6 <FT_Stream_ReadFields+0xf2>
 *   @0x2e7f6e adds r4, r3, #0x4
 *   @0x2e7f72 lsls r2, r2, #0x10
 *   @0x2e7f7a ldrb r3, [r3, #0x2]
 *   @0x2e7f7e b 0x2e7f92 <FT_Stream_ReadFields+0xbe>
 *   @0x2e7f82 adds r4, r3, #0x4
 *   @0x2e7f86 lsls r2, r2, #0x10
 *   @0x2e7f8e ldrb r3, [r3, #0x1]
 *   @0x2e7f92 orr.w r3, r2, r3, lsl #8
 *   @0x2e7f96 movs r1, #0x0
 *   @0x2e7f9a ldrb r1, [r3, #0x1]
 *   @0x2e7f9e ldrb r2, [r3]
 *   @0x2e7fa2 orr.w r1, r1, r2, lsl #16
 *   @0x2e7fa6 ldrb r2, [r3, #0x2]
 *   @0x2e7faa ldrb r1, [r3, #0x1]
 *   @0x2e7fae ldrb r2, [r3, #0x2]
 *   @0x2e7fb2 orr.w r1, r1, r2, lsl #16
 *   @0x2e7fb6 ldrb r2, [r3]
 *   @0x2e7fbe b 0x2e7fc6 <FT_Stream_ReadFields+0xf2>
 *   @0x2e7fc2 movs r4, #0x0
 *   @0x2e7fc6 lsls r2, r0, #0x1f
 *   @0x2e7fce lslmi r3, r1
 *   @0x2e7fd2 ldrb r1, [r5, #-3]
 *   @0x2e7fd6 cmp r1, #0x2
 *   @0x2e7fda cmp r1, #0x4
 *   @0x2e7fde cmp r1, #0x1
 *   @0x2e7fe2 strb r3, [r7, r2]
 *   @0x2e7fe6 strh r3, [r7, r2]
 *   @0x2e7fea str r3, [r7, r2]
 *   @0x2e7fee movs r4, #0x55
 *   @0x2e7ff6 mov r0, r6
 *   @0x2e7ffe movs r0, #0x6
 *   @0x2e8006 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e800a mov r0, r4
 *
 * ══ ft_mem_qrealloc  0x2e8010  size 126  本节 22 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e801a 0x2e808e  size 116  22 条
 * 部分覆盖: 本节 22/51 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e801a mov r6, r0
 *   @0x2e8022 ldr r4, [sp, #0x20]
 *   @0x2e8026 blt 0x2e8030 <ft_mem_qrealloc+0x20>
 *   @0x2e802a blt 0x2e8030 <ft_mem_qrealloc+0x20>
 *   @0x2e802e bge 0x2e8034 <ft_mem_qrealloc+0x24>
 *   @0x2e8032 b 0x2e807a <ft_mem_qrealloc+0x6a>
 *   @0x2e8036 cbnz r1, 0x2e8044 <ft_mem_qrealloc+0x34>
 *   @0x2e803a mov r0, r6
 *   @0x2e8042 b 0x2e8080 <ft_mem_qrealloc+0x70>
 *   @0x2e804e ble 0x2e8054 <ft_mem_qrealloc+0x44>
 *   @0x2e8052 b 0x2e807a <ft_mem_qrealloc+0x6a>
 *   @0x2e805e mov r1, r2
 *   @0x2e8062 add r2, sp, #0x4
 *   @0x2e806a ldr r7, [r6, #0xc]
 *   @0x2e806e mul r1, r5, r8
 *   @0x2e8072 mov r3, r4
 *   @0x2e8076 cbnz r0, 0x2e807e <ft_mem_qrealloc+0x6e>
 *   @0x2e807a str r3, [sp, #0x4]
 *   @0x2e807e mov r4, r0
 *   @0x2e8082 mov r0, r4
 *   @0x2e8086 str r2, [r3]
 *   @0x2e808a pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ ft_mem_realloc  0x2e808e  size 66  本节 13 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8094 0x2e80d0  size 60  13 条
 * 部分覆盖: 本节 13/28 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8094 movs r7, #0x0
 *   @0x2e8098 str r7, [r5, #-4]!
 *   @0x2e809c mov r4, r2
 *   @0x2e80a0 mov r8, r3
 *   @0x2e80a4 str r7, [sp]
 *   @0x2e80ac mov r5, r0
 *   @0x2e80b0 cmp r8, r4
 *   @0x2e80b4 rsb r2, r4, r8
 *   @0x2e80b8 mla r0, r6, r4, r0
 *   @0x2e80bc muls r2, r6, r2
 *   @0x2e80c4 mov r0, r5
 *   @0x2e80c8 str r2, [r3]
 *   @0x2e80cc pop.w {r4, r5, r6, r7, r8, pc}
 *
 * ══ FT_GlyphLoader_CreateExtra  0x2e80d0  size 54  本节 10 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e80d2 0x2e8106  size 52  10 条
 * 部分覆盖: 本节 10/23 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e80d2 mov r4, r0
 *   @0x2e80d6 movs r2, #0x0
 *   @0x2e80da str r2, [sp]
 *   @0x2e80de movs r1, #0x8
 *   @0x2e80e2 ldr r0, [r0]
 *   @0x2e80ea str r0, [r4, #0x28]
 *   @0x2e80ee movs r3, #0x1
 *   @0x2e80f2 ldr r3, [r4, #0x4]
 *   @0x2e80fa mov r0, r4
 *   @0x2e8102 add sp, #0x10
 *
 * ══ FT_GlyphLoader_CheckPoints  0x2e8106  size 248  本节 48 条（Thumb-2 半字段）｜入度 7
 * @func 0x2e810c 0x2e81fc  size 240  48 条
 * 部分覆盖: 本节 48/108 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e810c ldrsh.w r5, [r0, #0x3a]
 *   @0x2e8110 sub sp, #0x14
 *   @0x2e8118 ldr r6, [r0, #0x4]
 *   @0x2e811c add r5, r2
 *   @0x2e8120 add r1, r5
 *   @0x2e8124 cmp r1, r6
 *   @0x2e8128 adds r5, r1, #0x7
 *   @0x2e8134 movs r0, #0xa
 *   @0x2e8138 ldr r3, [r0, #0x18]
 *   @0x2e8140 str.w r8, [sp, #0x4]
 *   @0x2e8144 movs r1, #0x8
 *   @0x2e8148 str r3, [sp]
 *   @0x2e814c bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8150 ldr r3, [sp, #0xc]
 *   @0x2e8154 cmp r3, #0x0
 *   @0x2e8158 ldr r3, [r4, #0x1c]
 *   @0x2e815c movs r1, #0x1
 *   @0x2e8160 stm.w sp, {r3, r8}
 *   @0x2e8164 mov r3, r5
 *   @0x2e816c str r0, [r4, #0x1c]
 *   @0x2e8170 bne 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6>
 *   @0x2e8174 cbz r3, 0x2e81a4 <FT_GlyphLoader_CheckPoints+0x9e>
 *   @0x2e8178 movs r1, #0x8
 *   @0x2e817c lsls r2, r6, #0x1
 *   @0x2e8184 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8188 ldr r3, [sp, #0xc]
 *   @0x2e818c str r0, [r4, #0x28]
 *   @0x2e8190 lsl.w r8, r5, #0x3
 *   @0x2e8194 lsls r2, r6, #0x3
 *   @0x2e8198 add r1, r2
 *   @0x2e81a0 add r3, r8
 *   @0x2e81a4 movs r3, #0x1
 *   @0x2e81a8 ldrsh.w r5, [r4, #0x38]
 *   @0x2e81ac ldrsh.w r1, [r4, #0x14]
 *   @0x2e81b0 ldr r2, [r4, #0x8]
 *   @0x2e81b4 add r9, r5
 *   @0x2e81b8 bls 0x2e81e4 <FT_GlyphLoader_CheckPoints+0xde>
 *   @0x2e81c8 ldr r3, [r4, #0x20]
 *   @0x2e81cc movs r1, #0x2
 *   @0x2e81d0 add r3, sp, #0xc
 *   @0x2e81d4 mov r3, r5
 *   @0x2e81dc str r0, [r4, #0x20]
 *   @0x2e81e0 str r5, [r4, #0x8]
 *   @0x2e81e4 cbz r3, 0x2e81ec <FT_GlyphLoader_CheckPoints+0xe6>
 *   @0x2e81e8 bl 0x2e4944 <_ZNK11b2GearJoint8GetRatioEv+0x40>
 *   @0x2e81ec ldr r3, [sp, #0xc]
 *   @0x2e81f0 mov r0, r4
 *   @0x2e81f8 add sp, #0x14
 *
 * ══ FT_GlyphLoader_CopyPoints  0x2e81fe  size 118  本节 20 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8204 0x2e8274  size 112  20 条
 * 部分覆盖: 本节 20/48 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8204 ldrh.w r10, [r1, #0x16]
 *   @0x2e8208 mov r4, r0
 *   @0x2e8218 mov r2, r11
 *   @0x2e8220 cbnz r0, 0x2e826e <FT_GlyphLoader_CopyPoints+0x70>
 *   @0x2e8224 ldr r1, [r5, #0x18]
 *   @0x2e8228 mov r2, r6
 *   @0x2e8230 mov r2, r7
 *   @0x2e8234 blx 0xb65bc <memcpy@plt>
 *   @0x2e8238 ldr r0, [r4, #0x20]
 *   @0x2e823c lsl.w r2, r11, #0x1
 *   @0x2e8240 blx 0xb65bc <memcpy@plt>
 *   @0x2e8244 ldrb r3, [r4, #0x10]
 *   @0x2e8248 ldrb r3, [r5, #0x10]
 *   @0x2e824c ldr r1, [r5, #0x28]
 *   @0x2e8250 ldr r0, [r4, #0x28]
 *   @0x2e8258 ldr r1, [r5, #0x2c]
 *   @0x2e825c blx 0xb65bc <memcpy@plt>
 *   @0x2e8260 strh.w r10, [r4, #0x16]
 *   @0x2e8264 mov r0, r4
 *   @0x2e8270 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ FT_GlyphLoader_CheckSubGlyphs  0x2e8274  size 70  本节 16 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8276 0x2e82ba  size 68  16 条
 * 部分覆盖: 本节 16/33 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8276 sub sp, #0x14
 *   @0x2e827a movs r3, #0x0
 *   @0x2e827e str r3, [sp, #0xc]
 *   @0x2e8282 ldr r2, [r4, #0xc]
 *   @0x2e8286 ldr r0, [r0]
 *   @0x2e828a cmp r1, r2
 *   @0x2e828e ldr r3, [r4, #0x34]
 *   @0x2e8292 bic r5, r5, #0x1
 *   @0x2e8296 movs r1, #0x20
 *   @0x2e829a add r3, sp, #0xc
 *   @0x2e829e mov r3, r5
 *   @0x2e82a6 str r0, [r4, #0x34]
 *   @0x2e82aa ldr r3, [r4, #0x30]
 *   @0x2e82ae add.w r0, r0, r3, lsl #5
 *   @0x2e82b2 str r0, [r4, #0x58]
 *   @0x2e82b6 add sp, #0x14
 *
 * ══ ft_hash_str_init  0x2e82bc  size 60  本节 14 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e82be 0x2e830a  size 76  18 条
 * 部分覆盖: 本节 15/31 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 14/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e82be mov r4, r0
 *   @0x2e82c2 movs r2, #0x50
 *   @0x2e82ca str r2, [r0, #0x8]
 *   @0x2e82ce str r2, [sp]
 *   @0x2e82d2 str r0, [r4, #0xc]
 *   @0x2e82d6 add r0, pc
 *   @0x2e82da add r0, sp, #0xc
 *   @0x2e82de mov r0, r1
 *   @0x2e82e2 bl 0x2e808e <ft_mem_realloc>
 *   @0x2e82e6 str r0, [r4, #0x14]
 *   @0x2e82ea add sp, #0x10
 *   @0x2e82ee nop
 *   @0x2e82f2 vtbx.8 d28, {d15, d16}, d5
 *   @0x2e82f6 .word 0xffff b5f0
 *
 * ══ FT_CMap_Done  0x2e82f8  size 126  本节 26 条（Thumb-2 半字段）｜入度 7
 * @func 0x2e82fa 0x2e8376  size 124  26 条
 * 部分覆盖: 本节 26/57 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e82fa mov r6, r0
 *   @0x2e82fe cmp r0, #0x0
 *   @0x2e8302 ldr r4, [r0]
 *   @0x2e8306 ldr r0, [r4, #0x64]
 *   @0x2e830a cmp r5, r2
 *   @0x2e830e ldr r3, [r4, #0x28]
 *   @0x2e8316 bne 0x2e836e <FT_CMap_Done+0x76>
 *   @0x2e831e ldr.w r7, [r3, r1, lsl #2]
 *   @0x2e8322 movs r1, #0x4
 *   @0x2e8326 add r3, sp, #0xc
 *   @0x2e832a subs r3, r2, #0x1
 *   @0x2e8332 str r0, [r4, #0x28]
 *   @0x2e8336 adds r3, r5, #0x1
 *   @0x2e833a ldr r2, [r4, #0x24]
 *   @0x2e833e add.w r2, r2, #0xffffffff
 *   @0x2e8342 bge 0x2e835a <FT_CMap_Done+0x62>
 *   @0x2e8346 ldr r2, [r4, #0x28]
 *   @0x2e834e addne r1, r2, r5
 *   @0x2e8352 ldrne r1, [r1, #0x4]
 *   @0x2e8356 adds r5, #0x4
 *   @0x2e835a ldr r3, [r4, #0x5c]
 *   @0x2e835e str r2, [r4, #0x24]
 *   @0x2e8362 itt eq
 *   @0x2e8366 streq r3, [r4, #0x5c]
 *   @0x2e836e adds r5, #0x1
 *   @0x2e8372 add sp, #0x14
 *
 * ══ FT_CMap_New  0x2e8376  size 148  本节 29 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e837c 0x2e8408  size 140  29 条
 * 部分覆盖: 本节 29/64 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e837c mov r8, r3
 *   @0x2e8380 movs r3, #0x0
 *   @0x2e8384 str r3, [sp, #0xc]
 *   @0x2e8388 cmp r0, #0x0
 *   @0x2e838c cmp r2, #0x0
 *   @0x2e8390 ldr r5, [r2]
 *   @0x2e8394 beq 0x2e8402 <FT_CMap_New+0x8c>
 *   @0x2e83a0 mov r2, r10
 *   @0x2e83a4 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e83a8 ldr r3, [sp, #0xc]
 *   @0x2e83ac cbnz r3, 0x2e83f4 <FT_CMap_New+0x7e>
 *   @0x2e83b4 stm.w r4, {r0, r1, r2}
 *   @0x2e83b8 ldr r3, [r7, #0x4]
 *   @0x2e83bc ldr r3, [r5, #0x28]
 *   @0x2e83c0 ldr r2, [r5, #0x24]
 *   @0x2e83c4 stm.w sp, {r3, r10}
 *   @0x2e83c8 adds r3, r2, #0x1
 *   @0x2e83d0 str r0, [r5, #0x28]
 *   @0x2e83d4 ldr r3, [r5, #0x24]
 *   @0x2e83d8 str r2, [r5, #0x24]
 *   @0x2e83e0 mov r0, r4
 *   @0x2e83e4 blx r3
 *   @0x2e83e8 cmp r0, #0x0
 *   @0x2e83ec mov r0, r4
 *   @0x2e83f0 bl 0x2e7b5c <FT_Done_GlyphSlot+0x42>
 *   @0x2e83f4 cmp.w r8, #0x0
 *   @0x2e83f8 beq 0x2e83fe <FT_CMap_New+0x88>
 *   @0x2e8400 b 0x2e8404 <FT_CMap_New+0x8e>
 *   @0x2e8404 add sp, #0x14
 *
 * ══ FT_Outline_New_Internal  0x2e840a  size 156  本节 29 条（Thumb-2 半字段）｜入度 6
 * @func 0x2e8410 0x2e84a4  size 148  29 条
 * 部分覆盖: 本节 29/66 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8410 mov r6, r1
 *   @0x2e8414 mov r4, r3
 *   @0x2e8418 movs r0, #0x6
 *   @0x2e841c cmp r0, #0x0
 *   @0x2e8420 mov r0, r3
 *   @0x2e8424 movs r2, #0x14
 *   @0x2e842c blt 0x2e8418 <FT_Outline_New_Internal+0xe>
 *   @0x2e8430 bhi 0x2e8418 <FT_Outline_New_Internal+0xe>
 *   @0x2e8438 movs r2, #0x0
 *   @0x2e8440 mov r0, r5
 *   @0x2e8448 mov r3, r6
 *   @0x2e8450 str r0, [r4, #0x4]
 *   @0x2e8454 stm.w sp, {r2, r8}
 *   @0x2e8458 mov r0, r5
 *   @0x2e845c mov r3, r6
 *   @0x2e8464 str r0, [r4, #0x8]
 *   @0x2e8468 stm.w sp, {r2, r8}
 *   @0x2e846c mov r0, r5
 *   @0x2e8470 mov r3, r7
 *   @0x2e8478 ldr r0, [sp, #0xc]
 *   @0x2e847c ldr r3, [r4, #0x10]
 *   @0x2e8480 orr r3, r3, #0x1
 *   @0x2e8484 strh r7, [r4]
 *   @0x2e8488 b 0x2e84a0 <FT_Outline_New_Internal+0x96>
 *   @0x2e848c mov r0, r5
 *   @0x2e8490 orr r3, r3, #0x1
 *   @0x2e8494 str r3, [r4, #0x10]
 *   @0x2e849c b 0x2e84a0 <FT_Outline_New_Internal+0x96>
 *   @0x2e84a0 add sp, #0x10
 *
 * ══ FT_Outline_New  0x2e84a6  size 12  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e84a8 0x2e84be  size 22  5 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e84a8 ldr r0, [r0]
 *   @0x2e84b0 bx lr
 *
 * ══ anon_2e84b2  0x2e84b2  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e84b2 0x2e84be  size 12  3 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e84b2 ldrlt r0, [pc, #-0x0]
 *
 * ══ ft_hash_num_init  0x2e84b4  size 60  本节 14 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e84b6 0x2e84f2  size 60  14 条
 * 部分覆盖: 本节 14/29 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e84b6 mov r4, r0
 *   @0x2e84ba movs r2, #0x50
 *   @0x2e84c2 str r2, [r0, #0x8]
 *   @0x2e84c6 str r2, [sp]
 *   @0x2e84ca str r0, [r4, #0xc]
 *   @0x2e84ce add r0, pc
 *   @0x2e84d2 add r0, sp, #0xc
 *   @0x2e84d6 mov r0, r1
 *   @0x2e84da bl 0x2e808e <ft_mem_realloc>
 *   @0x2e84de str r0, [r4, #0x14]
 *   @0x2e84e2 add sp, #0x10
 *   @0x2e84e6 nop
 *   @0x2e84ea .word 0xffff c4db
 *   @0x2e84ee vtbl.8 d30, {d15, d16}, d29
 *
 * ══ anon_2e84f0  0x2e84f0  size 180  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e85a4 0x2e85a8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e85a4 .word 0x87f0e8bd
 *
 * ══ ft_hash_str_insert  0x2e85a8  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e85aa 0x2e85ba  size 16  4 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e85aa bl 0x2e84f0 <ft_hash_num_init+0x3c>
 *   @0x2e85ae pop {r3, pc}
 *
 * ══ ft_hash_num_insert  0x2e85b0  size 8  本节 2 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e85b2 0x2e85ba  size 8  2 条
 * 部分覆盖: 本节 2/4 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e85b2 bl 0x2e84f0 <ft_hash_num_init+0x3c>
 *   @0x2e85b6 pop {r3, pc}
 *
 * ══ FT_Raccess_Get_DataOffsets  0x2e85b8  size 396  本节 76 条（Thumb-2 半字段）｜入度 12
 * @func 0x2e85be 0x2e8746  size 392  76 条
 * 部分覆盖: 本节 76/174 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e85be ldr.w r8, [r0]
 *   @0x2e85c2 mov r4, r1
 *   @0x2e85c6 mov r1, r2
 *   @0x2e85ca str r3, [sp, #0xc]
 *   @0x2e85ce bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e85d2 str r0, [sp, #0x14]
 *   @0x2e85d6 bne.w 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e85da add r5, sp, #0x14
 *   @0x2e85de mov r1, r5
 *   @0x2e85e6 cmp r7, #0x0
 *   @0x2e85fa movs r0, #0x8
 *   @0x2e85fe mov r0, r4
 *   @0x2e8602 bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e8606 ldr r3, [sp, #0x14]
 *   @0x2e860a cmp r3, #0x0
 *   @0x2e8612 mov r1, r5
 *   @0x2e861a mov r3, r0
 *   @0x2e861e bne.w 0x2e8730 <FT_Raccess_Get_DataOffsets+0x178>
 *   @0x2e8622 mov r1, r5
 *   @0x2e8626 str r3, [sp, #0x8]
 *   @0x2e862e ldr r3, [sp, #0x8]
 *   @0x2e8632 cmp r2, #0x0
 *   @0x2e8636 ldr r2, [sp, #0x40]
 *   @0x2e863a beq 0x2e8644 <FT_Raccess_Get_DataOffsets+0x8c>
 *   @0x2e863e cmp r7, r9
 *   @0x2e8642 b 0x2e8734 <FT_Raccess_Get_DataOffsets+0x17c>
 *   @0x2e8646 adds r2, r3, #0x1
 *   @0x2e864a movw r2, #0xaa6
 *   @0x2e864e cmp r3, r2
 *   @0x2e8652 mov r0, r4
 *   @0x2e865e str r0, [sp, #0x14]
 *   @0x2e8662 bne 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e866a movs r1, #0x8
 *   @0x2e866e bl 0x2e808e <ft_mem_realloc>
 *   @0x2e8672 mov r9, r0
 *   @0x2e8676 cmp r0, #0x0
 *   @0x2e867a mov r7, r9
 *   @0x2e867e ldr r1, [r6]
 *   @0x2e8682 bge 0x2e86e2 <FT_Raccess_Get_DataOffsets+0x12a>
 *   @0x2e8686 mov r1, r5
 *   @0x2e868e ldr r3, [sp, #0x14]
 *   @0x2e8692 bne 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170>
 *   @0x2e8696 movs r1, #0x2
 *   @0x2e869e cmp r0, #0x0
 *   @0x2e86a2 mov r0, r4
 *   @0x2e86a6 bl 0x2e6dc4 <FT_Stream_ReadULong>
 *   @0x2e86aa ldr r3, [sp, #0x14]
 *   @0x2e86ae cmp r3, #0x0
 *   @0x2e86b2 mov r0, r4
 *   @0x2e86b6 bl 0x2e6930 <FT_Stream_Skip>
 *   @0x2e86ba str r0, [sp, #0x14]
 *   @0x2e86be ldrsh.w r3, [r7]
 *   @0x2e86c2 cmp r3, #0x0
 *   @0x2e86c6 cmp.w r11, #0x0
 *   @0x2e86ca add.w r7, r7, #0x8
 *   @0x2e86ce bge 0x2e86d4 <FT_Raccess_Get_DataOffsets+0x11c>
 *   @0x2e86d2 b 0x2e8726 <FT_Raccess_Get_DataOffsets+0x16e>
 *   @0x2e86e2 ldrb.w r3, [sp, #0x44]
 *   @0x2e86e6 cbz r3, 0x2e86f4 <FT_Raccess_Get_DataOffsets+0x13c>
 *   @0x2e86ea mov r0, r9
 *   @0x2e86ee add r3, pc
 *   @0x2e86f6 mov r0, r8
 *   @0x2e86fe ldr r3, [r6]
 *   @0x2e8706 cbnz r3, 0x2e8728 <FT_Raccess_Get_DataOffsets+0x170>
 *   @0x2e870a cmp r3, r2
 *   @0x2e870e add.w r2, r9, r3, lsl #3
 *   @0x2e8712 ldr r1, [sp, #0xc]
 *   @0x2e8716 add r2, r1
 *   @0x2e871e b 0x2e8708 <FT_Raccess_Get_DataOffsets+0x150>
 *   @0x2e8722 str r0, [r3]
 *   @0x2e8726 str r3, [sp, #0x14]
 *   @0x2e872a mov r1, r9
 *   @0x2e8732 b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e8736 b 0x2e873a <FT_Raccess_Get_DataOffsets+0x182>
 *   @0x2e873a add sp, #0x1c
 *   @0x2e8742 vtbl.8 d30, {d15, d16}, d29
 *
 * ══ FT_Get_Sfnt_Name  0x2e8744  size 164  本节 35 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e874a 0x2e87e6  size 156  35 条
 * 部分覆盖: 本节 35/74 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e874a movs r3, #0x6
 *   @0x2e874e str r3, [sp, #0xc]
 *   @0x2e8752 beq 0x2e87e0 <FT_Get_Sfnt_Name+0x9c>
 *   @0x2e8756 beq 0x2e87e0 <FT_Get_Sfnt_Name+0x9c>
 *   @0x2e875a lsls r3, r3, #0x1c
 *   @0x2e875e ldrh.w r3, [r0, #0x154]
 *   @0x2e8762 cmp r1, r3
 *   @0x2e8766 movs r7, #0x14
 *   @0x2e876e add.w r4, r8, r7
 *   @0x2e8772 ldrh r3, [r4, #0x8]
 *   @0x2e8776 ldr r2, [r4, #0x10]
 *   @0x2e877a ldr.w r9, [r0, #0x64]
 *   @0x2e877e add r1, sp, #0xc
 *   @0x2e8782 str r1, [sp, #0x4]
 *   @0x2e8786 str r2, [sp]
 *   @0x2e878a bl 0x2e808e <ft_mem_realloc>
 *   @0x2e878e ldr r3, [sp, #0xc]
 *   @0x2e8792 cbz r3, 0x2e87a4 <FT_Get_Sfnt_Name+0x60>
 *   @0x2e8796 ldr r1, [r4, #0x10]
 *   @0x2e879e str r3, [r4, #0x10]
 *   @0x2e87a2 b 0x2e87c2 <FT_Get_Sfnt_Name+0x7e>
 *   @0x2e87a6 ldr r1, [r4, #0xc]
 *   @0x2e87ae cmp r0, #0x0
 *   @0x2e87b2 mov r0, r6
 *   @0x2e87b6 ldrh r2, [r4, #0x8]
 *   @0x2e87be cmp r0, #0x0
 *   @0x2e87c2 ldrh.w r3, [r8, r7]
 *   @0x2e87c6 strh r3, [r5]
 *   @0x2e87ca strh r3, [r5, #0x2]
 *   @0x2e87ce strh r3, [r5, #0x4]
 *   @0x2e87d2 strh r3, [r5, #0x6]
 *   @0x2e87d6 str r3, [r5, #0x8]
 *   @0x2e87da str r3, [r5, #0xc]
 *   @0x2e87de str r3, [sp, #0xc]
 *   @0x2e87e2 add sp, #0x14
 *
 * ══ FT_Get_Sfnt_LangTag  0x2e87e8  size 176  本节 37 条（Thumb-2 半字段）｜入度 4
 * @func 0x2e87ee 0x2e8896  size 168  37 条
 * 部分覆盖: 本节 37/79 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e87ee mov r3, r1
 *   @0x2e87f2 movs r1, #0x6
 *   @0x2e87f6 str r1, [sp, #0xc]
 *   @0x2e87fa beq 0x2e888c <FT_Get_Sfnt_LangTag+0xa4>
 *   @0x2e87fe beq 0x2e888c <FT_Get_Sfnt_LangTag+0xa4>
 *   @0x2e8802 lsls r2, r2, #0x1c
 *   @0x2e8806 ldrh.w r1, [r0, #0x158]
 *   @0x2e880a cmp r1, #0x1
 *   @0x2e880e cmp.w r3, #0x8000
 *   @0x2e8812 bls 0x2e888c <FT_Get_Sfnt_LangTag+0xa4>
 *   @0x2e881e bhs 0x2e888c <FT_Get_Sfnt_LangTag+0xa4>
 *   @0x2e8822 ldr.w r7, [r5, #0x16c]
 *   @0x2e8826 muls r6, r3, r6
 *   @0x2e882e ldrh r3, [r7, r6]
 *   @0x2e8832 ldr r2, [r4, #0x8]
 *   @0x2e8836 ldr.w r9, [r5, #0x64]
 *   @0x2e883a add r0, sp, #0xc
 *   @0x2e883e str r0, [sp, #0x4]
 *   @0x2e8842 mov r0, r9
 *   @0x2e884a str r0, [r4, #0x8]
 *   @0x2e884e mov r0, r9
 *   @0x2e8852 bl 0x2e7336 <ft_mem_free>
 *   @0x2e8856 movs r3, #0x0
 *   @0x2e885a strh r3, [r7, r6]
 *   @0x2e885e mov r0, r5
 *   @0x2e8862 bl 0x2e68a6 <FT_Stream_Seek>
 *   @0x2e8866 str r0, [sp, #0xc]
 *   @0x2e886a bne 0x2e884e <FT_Get_Sfnt_LangTag+0x66>
 *   @0x2e886e ldr r1, [r4, #0x8]
 *   @0x2e8872 bl 0x2e698e <FT_Stream_Read>
 *   @0x2e8876 str r0, [sp, #0xc]
 *   @0x2e887a bne 0x2e884e <FT_Get_Sfnt_LangTag+0x66>
 *   @0x2e887e str.w r3, [r8]
 *   @0x2e8882 ldrh r3, [r7, r6]
 *   @0x2e888a str r3, [sp, #0xc]
 *   @0x2e888e b 0x2e8892 <FT_Get_Sfnt_LangTag+0xaa>
 *   @0x2e8892 add sp, #0x14
 *
 * ══ ft_mem_dup  0x2e8898  size 42  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e889a 0x2e88c2  size 40  8 条
 * 部分覆盖: 本节 8/18 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e889a mov r5, r1
 *   @0x2e889e mov r1, r2
 *   @0x2e88a2 mov r6, r3
 *   @0x2e88aa mov r7, r0
 *   @0x2e88ae cbz r5, 0x2e88b8 <ft_mem_dup+0x20>
 *   @0x2e88b2 mov r2, r4
 *   @0x2e88ba mov r0, r7
 *   @0x2e88be add sp, #0xc
 *
 * ══ ft_mem_strdup  0x2e88c2  size 36  本节 6 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e88c4 0x2e88e0  size 28  6 条
 * 部分覆盖: 本节 6/13 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e88c4 mov r6, r0
 *   @0x2e88c8 mov r4, r1
 *   @0x2e88cc mov r0, r1
 *   @0x2e88d4 b 0x2e88d8 <ft_mem_strdup+0x16>
 *   @0x2e88d8 mov r0, r6
 *   @0x2e88dc mov r3, r5
 *
 * ══ ft_mem_strcpyn  0x2e88e6  size 40  本节 10 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e88e8 0x2e8920  size 56  14 条
 * 部分覆盖: 本节 11/22 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 10/20 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e88e8 push {r4, lr}
 *   @0x2e88ec mov r4, r1
 *   @0x2e88f0 bhi 0x2e8900 <ft_mem_strcpyn+0x1a>
 *   @0x2e88f4 strb r3, [r0]
 *   @0x2e88f8 subs r0, r0, r3
 *   @0x2e88fc movne r0, #0x1
 *   @0x2e8900 ldrb r3, [r1], #1
 *   @0x2e8904 cmp r3, #0x0
 *   @0x2e8908 strb r3, [r0], #1
 *   @0x2e890c b 0x2e88ea <ft_mem_strcpyn+0x4>
 *
 * ══ FT_List_Find  0x2e890e  size 18  本节 4 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8910 0x2e8920  size 16  4 条
 * 部分覆盖: 本节 4/8 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8910 ldr r0, [r0]
 *   @0x2e8914 ldr r3, [r0, #0x8]
 *   @0x2e8918 beq 0x2e891e <FT_List_Find+0x10>
 *   @0x2e891c b 0x2e8912 <FT_List_Find+0x4>
 *
 * ══ FT_List_Add  0x2e8920  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8922 0x2e893a  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8922 cbz r1, 0x2e8936 <FT_List_Add+0x16>
 *   @0x2e8926 movs r2, #0x0
 *   @0x2e892a str r3, [r1]
 *   @0x2e892e str r1, [r3, #0x4]
 *   @0x2e8932 str r1, [r0]
 *   @0x2e8936 bx lr
 *
 * ══ FT_New_Size  0x2e8938  size 162  本节 36 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e893e 0x2e89da  size 156  36 条
 * 部分覆盖: 本节 36/75 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e893e mov r5, r0
 *   @0x2e8942 beq 0x2e89ca <FT_New_Size+0x92>
 *   @0x2e8946 beq 0x2e89ce <FT_New_Size+0x96>
 *   @0x2e894a cmp r3, #0x0
 *   @0x2e894e movs r7, #0x0
 *   @0x2e8952 ldr r3, [r0, #0x60]
 *   @0x2e895a mov r2, r9
 *   @0x2e8962 ldr.w r1, [r10, #0x28]
 *   @0x2e8966 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e896a ldr r3, [sp, #0x4]
 *   @0x2e896e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a>
 *   @0x2e8972 movs r1, #0xc
 *   @0x2e8976 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e897a ldr r3, [sp, #0x4]
 *   @0x2e897e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a>
 *   @0x2e8982 mov r0, r6
 *   @0x2e8986 mov r2, r9
 *   @0x2e898e cbnz r3, 0x2e89b2 <FT_New_Size+0x7a>
 *   @0x2e8992 ldr.w r3, [r10, #0x38]
 *   @0x2e8996 cbz r3, 0x2e899e <FT_New_Size+0x66>
 *   @0x2e899a blx r3
 *   @0x2e899e ldr r3, [sp, #0x4]
 *   @0x2e89a2 str.w r4, [r8]
 *   @0x2e89a6 add.w r0, r5, #0x6c
 *   @0x2e89aa str r4, [r7, #0x8]
 *   @0x2e89ae bl 0x2e8920 <FT_List_Add>
 *   @0x2e89b2 ldr r3, [sp, #0x4]
 *   @0x2e89b6 mov r0, r6
 *   @0x2e89ba bl 0x2e7336 <ft_mem_free>
 *   @0x2e89be mov r0, r6
 *   @0x2e89c2 bl 0x2e7336 <ft_mem_free>
 *   @0x2e89c6 ldr r0, [sp, #0x4]
 *   @0x2e89ca movs r0, #0x23
 *   @0x2e89ce movs r0, #0x6
 *   @0x2e89d2 movs r0, #0x22
 *   @0x2e89d6 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *
 * ══ FT_List_Insert  0x2e89da  size 24  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e89dc 0x2e8a04  size 40  10 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e89dc cbz r1, 0x2e89f0 <FT_List_Insert+0x16>
 *   @0x2e89e0 movs r2, #0x0
 *   @0x2e89e4 str r3, [r1, #0x4]
 *   @0x2e89e8 str r1, [r0, #0x4]
 *   @0x2e89ec str r1, [r3]
 *   @0x2e89f0 bx lr
 *
 * ══ FT_List_Remove  0x2e89f2  size 26  本节 6 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e89f4 0x2e8a0c  size 24  6 条
 * 部分覆盖: 本节 6/12 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e89f4 cbz r1, 0x2e8a0a <FT_List_Remove+0x18>
 *   @0x2e89f8 ldr r2, [r1, #0x4]
 *   @0x2e89fc str r2, [r3, #0x4]
 *   @0x2e8a00 str r2, [r0]
 *   @0x2e8a04 str r3, [r2]
 *   @0x2e8a08 str r3, [r0, #0x4]
 *
 * ══ FT_Done_Size  0x2e8a0c  size 106  本节 20 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e8a12 0x2e8a76  size 100  20 条
 * 部分覆盖: 本节 20/45 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8a12 cbnz r0, 0x2e8a1a <FT_Done_Size+0xe>
 *   @0x2e8a16 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e8a1a ldr r4, [r0]
 *   @0x2e8a1e ldr r6, [r4, #0x60]
 *   @0x2e8a22 add.w r9, r4, #0x6c
 *   @0x2e8a26 mov r1, r5
 *   @0x2e8a2e bl 0x2e890e <FT_List_Find>
 *   @0x2e8a32 mov r7, r0
 *   @0x2e8a36 beq 0x2e8a14 <FT_Done_Size+0x8>
 *   @0x2e8a3a mov r1, r7
 *   @0x2e8a42 mov r1, r7
 *   @0x2e8a4a cmp r3, r5
 *   @0x2e8a4e movs r3, #0x0
 *   @0x2e8a52 ldr r3, [r4, #0x6c]
 *   @0x2e8a56 ldr r3, [r3, #0x8]
 *   @0x2e8a5a mov r0, r8
 *   @0x2e8a5e mov r2, r6
 *   @0x2e8a66 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e8a6a movs r0, #0x23
 *   @0x2e8a72 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ FT_List_Up  0x2e8a76  size 36  本节 9 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8a78 0x2e8a9e  size 38  10 条
 * 部分覆盖: 本节 10/19 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8a78 cbz r1, 0x2e8a98 <FT_List_Up+0x22>
 *   @0x2e8a7c ldr r2, [r1, #0x4]
 *   @0x2e8a80 str r2, [r3, #0x4]
 *   @0x2e8a84 str r3, [r2]
 *   @0x2e8a88 str r3, [r0, #0x4]
 *   @0x2e8a8c str r3, [r1]
 *   @0x2e8a90 str r3, [r1, #0x4]
 *   @0x2e8a94 str r1, [r3]
 *   @0x2e8a98 bx lr
 *
 * ══ anon_2e8a9a  0x2e8a9a  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8a9a 0x2e8a9e  size 4  1 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8a9a .word 0xe92d0000
 *
 * ══ FT_Set_Renderer  0x2e8a9c  size 104  本节 21 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e8aa2 0x2e8b16  size 116  25 条
 * 部分覆盖: 本节 24/52 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 23/50 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 21/46 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8aa2 mov r5, r2
 *   @0x2e8aa6 mov r7, r0
 *   @0x2e8aaa cbnz r1, 0x2e8ab2 <FT_Set_Renderer+0x16>
 *   @0x2e8aae pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e8ab2 cbz r2, 0x2e8ab8 <FT_Set_Renderer+0x1c>
 *   @0x2e8ab6 beq 0x2e8aac <FT_Set_Renderer+0x10>
 *   @0x2e8abe mov r0, r8
 *   @0x2e8ac6 cmp r0, #0x0
 *   @0x2e8aca mov r0, r8
 *   @0x2e8ace bl 0x2e8a76 <FT_List_Up>
 *   @0x2e8ad2 ldr r3, [r4, #0x10]
 *   @0x2e8ad6 cmp r3, r2
 *   @0x2e8ada streq.w r4, [r7, #0x9c]
 *   @0x2e8ade ldr r3, [r4, #0xc]
 *   @0x2e8ae2 cbz r5, 0x2e8af4 <FT_Set_Renderer+0x58>
 *   @0x2e8aea blx r7
 *   @0x2e8aee cbnz r0, 0x2e8afc <FT_Set_Renderer+0x60>
 *   @0x2e8af2 b 0x2e8ae2 <FT_Set_Renderer+0x46>
 *   @0x2e8af6 pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e8afa movs r0, #0x21
 *   @0x2e8b02 ldr r5, [r6, #0x74]
 *
 * ══ FT_List_Iterate  0x2e8b04  size 32  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8b06 0x2e8b26  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8b06 mov r4, r1
 *   @0x2e8b0a cbz r0, 0x2e8b20 <FT_List_Iterate+0x1c>
 *   @0x2e8b0e ldr r0, [r0]
 *   @0x2e8b12 mov r1, r6
 *   @0x2e8b16 blx r4
 *   @0x2e8b1a mov r0, r5
 *   @0x2e8b1e pop {r4, r5, r6, pc}
 *   @0x2e8b22 pop {r4, r5, r6, pc}
 *
 * ══ FT_List_Finalize  0x2e8b24  size 54  本节 11 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e8b2a 0x2e8b5a  size 48  11 条
 * 部分覆盖: 本节 11/23 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8b2a mov r6, r2
 *   @0x2e8b2e mov r5, r0
 *   @0x2e8b32 cbz r2, 0x2e8b56 <FT_List_Finalize+0x32>
 *   @0x2e8b36 cbz r4, 0x2e8b52 <FT_List_Finalize+0x2e>
 *   @0x2e8b3e cbz r7, 0x2e8b46 <FT_List_Finalize+0x22>
 *   @0x2e8b42 mov r2, r8
 *   @0x2e8b46 mov r1, r4
 *   @0x2e8b4a bl 0x2e7336 <ft_mem_free>
 *   @0x2e8b4e mov r4, r9
 *   @0x2e8b52 str r4, [r5]
 *   @0x2e8b56 pop.w {r3, r4, r5, r6, r7, r8, r9, pc}
 *
 * ══ anon_2e8b5c  0x2e8b5c  size 124  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e8bd8 0x2e8bdc  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8bd8 .word 0xfffff1fd
 *
 * ══ FT_Done_Face  0x2e8bdc  size 92  本节 16 条（Thumb-2 半字段）｜入度 2
 * @func 0x2e8be2 0x2e8c36  size 84  16 条
 * 部分覆盖: 本节 16/37 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e8be2 cbz r0, 0x2e8c2c <FT_Done_Face+0x50>
 *   @0x2e8be6 cbz r3, 0x2e8c2c <FT_Done_Face+0x50>
 *   @0x2e8bee subs r2, #0x1
 *   @0x2e8bf2 ldr.w r3, [r0, #0x80]
 *   @0x2e8bf6 ldr r3, [r3, #0x40]
 *   @0x2e8bfa bgt 0x2e8c32 <FT_Done_Face+0x56>
 *   @0x2e8bfe mov r1, r4
 *   @0x2e8c06 mov r0, r8
 *   @0x2e8c0e cbz r0, 0x2e8c2c <FT_Done_Face+0x50>
 *   @0x2e8c12 mov r1, r6
 *   @0x2e8c1a mov r1, r6
 *   @0x2e8c22 mov r1, r4
 *   @0x2e8c26 bl 0x2e8b5c <FT_List_Finalize+0x38>
 *   @0x2e8c2a b 0x2e8c32 <FT_Done_Face+0x56>
 *   @0x2e8c2e pop.w {r4, r5, r6, r7, r8, pc}
 *   @0x2e8c32 movs r0, #0x0
 *
 * ══ anon_2e90d4  0x2e90d4  size 0  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e90d4 0x2e90d8  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e90d4 andeq pc, pc, r6, lsr #21
 *
 * ══ FT_New_Face  0x2e90d8  size 34  本节 8 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e90da 0x2e90fa  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e90da sub sp, #0x28
 *   @0x2e90de str r1, [sp, #0x14]
 *   @0x2e90e2 str r1, [sp, #0x18]
 *   @0x2e90e6 str r1, [sp]
 *   @0x2e90ea movs r4, #0x4
 *   @0x2e90ee bl 0x2e8c38 <FT_Done_Face+0x5c>
 *   @0x2e90f2 b 0x2e90f6 <FT_New_Face+0x1e>
 *   @0x2e90f6 add sp, #0x28
 *
 * ══ anon_2e9398  0x2e9398  size 852  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e96ec 0x2e96f0  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e96ec andeq r5, r10, r11, ror #1
 *
 * ══ FT_New_Memory_Face  0x2e96f0  size 38  本节 9 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e96f2 0x2e9716  size 36  9 条
 * 部分覆盖: 本节 9/18 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e96f2 sub sp, #0x28
 *   @0x2e96f6 movs r4, #0x1
 *   @0x2e96fa str r2, [sp, #0x10]
 *   @0x2e96fe movs r2, #0x0
 *   @0x2e9702 str r2, [sp, #0x18]
 *   @0x2e9706 ldr r3, [sp, #0x30]
 *   @0x2e970a bl 0x2e8c38 <FT_Done_Face+0x5c>
 *   @0x2e970e b 0x2e9712 <FT_New_Memory_Face+0x22>
 *   @0x2e9712 add sp, #0x28
 *
 * ══ FT_Open_Face  0x2e9716  size 14  本节 3 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9718 0x2e9724  size 12  3 条
 * 部分覆盖: 本节 3/6 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9718 movs r4, #0x1
 *   @0x2e971c bl 0x2e8c38 <FT_Done_Face+0x5c>
 *   @0x2e9720 add sp, #0x8
 *
 * ══ FT_Remove_Module  0x2e9724  size 236  本节 47 条（Thumb-2 半字段）｜入度 3
 * @func 0x2e972a 0x2e980e  size 228  47 条
 * 部分覆盖: 本节 47/104 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e972a cmp r0, #0x0
 *   @0x2e972e cmp r1, #0x0
 *   @0x2e9732 ldr r5, [r0, #0x10]
 *   @0x2e973e mov r3, r1
 *   @0x2e9742 ldr r6, [r3]
 *   @0x2e9746 cmp r6, r4
 *   @0x2e974a subs r5, #0x1
 *   @0x2e974e subs r0, r2, #0x4
 *   @0x2e9752 bhs 0x2e975c <FT_Remove_Module+0x38>
 *   @0x2e9756 str r1, [r3], #4
 *   @0x2e975a b 0x2e9750 <FT_Remove_Module+0x2c>
 *   @0x2e975e str r1, [r2, #-4]
 *   @0x2e9762 ldr r3, [r4, #0x4]
 *   @0x2e976e ldr.w r2, [r3, #0xa0]
 *   @0x2e9772 cmp r2, r4
 *   @0x2e9776 streq.w r1, [r3, #0xa0]
 *   @0x2e977a ldr r3, [r4]
 *   @0x2e977e lsls r2, r3, #0x1e
 *   @0x2e9782 ldr r5, [r4, #0x4]
 *   @0x2e9786 mov r6, r5
 *   @0x2e978a ldr r10, [r6], #148
 *   @0x2e978e mov r0, r6
 *   @0x2e9796 cbz r0, 0x2e97ca <FT_Remove_Module+0xa6>
 *   @0x2e979a ldr r1, [pc, #0x6c]
 *   @0x2e979e cmp r3, r1
 *   @0x2e97a2 ldr r0, [r4, #0x34]
 *   @0x2e97a6 ldr r2, [r2, #0x38]
 *   @0x2e97aa blx r2
 *   @0x2e97ae mov r1, r7
 *   @0x2e97b6 mov r1, r7
 *   @0x2e97be ldr r1, [pc, #0x48]
 *   @0x2e97c2 bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e97c6 str.w r0, [r5, #0x9c]
 *   @0x2e97ca ldr r3, [r4]
 *   @0x2e97ce lsls r3, r3, #0x1f
 *   @0x2e97d2 ldr r1, [pc, #0x38]
 *   @0x2e97da mov r3, r4
 *   @0x2e97de bl 0x2e8b24 <FT_List_Finalize>
 *   @0x2e97e2 ldr.w r3, [r9, #0x1c]
 *   @0x2e97e6 cbz r3, 0x2e97ec <FT_Remove_Module+0xc8>
 *   @0x2e97ea blx r3
 *   @0x2e97ee mov r1, r4
 *   @0x2e97f6 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2e97fa movs r0, #0x21
 *   @0x2e9802 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2e9806 nop
 *   @0x2e980a ldr r5, [r6, #0x74]
 *
 * ══ FT_Add_Module  0x2e9810  size 380  本节 81 条（Thumb-2 半字段）｜入度 8
 * @func 0x2e9816 0x2e998e  size 376  81 条
 * 部分覆盖: 本节 81/175 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9816 mov r5, r0
 *   @0x2e981a beq.w 0x2e9970 <FT_Add_Module+0x160>
 *   @0x2e981e cmp r1, #0x0
 *   @0x2e9826 ldr r2, [pc, #0x15c]
 *   @0x2e982a bgt.w 0x2e9978 <FT_Add_Module+0x168>
 *   @0x2e982e ldr.w r9, [r0, #0x10]
 *   @0x2e9832 movs r4, #0x0
 *   @0x2e9836 beq 0x2e9868 <FT_Add_Module+0x58>
 *   @0x2e983e ldr r7, [r3, #0x14]
 *   @0x2e984e ldr r3, [r6, #0xc]
 *   @0x2e9856 ble.w 0x2e997c <FT_Add_Module+0x16c>
 *   @0x2e985a mov r0, r5
 *   @0x2e985e bl 0x2e9724 <FT_Remove_Module>
 *   @0x2e9862 b 0x2e9868 <FT_Add_Module+0x58>
 *   @0x2e9866 b 0x2e9834 <FT_Add_Module+0x24>
 *   @0x2e986a str r3, [sp]
 *   @0x2e986e ldr.w r8, [r5]
 *   @0x2e9872 cmp r3, #0x1f
 *   @0x2e9876 movs r3, #0x30
 *   @0x2e987a b 0x2e9950 <FT_Add_Module+0x140>
 *   @0x2e987e ldr r1, [r6, #0x4]
 *   @0x2e9882 bl 0x2e7126 <ft_mem_alloc>
 *   @0x2e9886 ldr r3, [sp]
 *   @0x2e988a cmp r3, #0x0
 *   @0x2e988e str r5, [r0, #0x4]
 *   @0x2e9896 ldr r3, [r6]
 *   @0x2e989a bmi 0x2e98aa <FT_Add_Module+0x9a>
 *   @0x2e989e ldr r3, [r3]
 *   @0x2e98a2 bpl 0x2e991a <FT_Add_Module+0x10a>
 *   @0x2e98aa ldr.w r9, [r5]
 *   @0x2e98ae movs r1, #0xc
 *   @0x2e98b2 mov r0, r9
 *   @0x2e98ba mov r10, r0
 *   @0x2e98be ldr r7, [r4]
 *   @0x2e98c2 str r7, [r4, #0xc]
 *   @0x2e98c6 str r3, [r4, #0x10]
 *   @0x2e98ca cmp r3, r2
 *   @0x2e98ce ldr r3, [r7, #0x38]
 *   @0x2e98d2 cbz r3, 0x2e98ea <FT_Add_Module+0xda>
 *   @0x2e98d6 add.w r1, r4, #0x34
 *   @0x2e98da blx r3
 *   @0x2e98de cbnz r0, 0x2e9906 <FT_Add_Module+0xf6>
 *   @0x2e98e2 ldr r3, [r3, #0x10]
 *   @0x2e98e6 ldr r3, [r7, #0x28]
 *   @0x2e98ea add.w r0, r5, #0x94
 *   @0x2e98ee mov r1, r10
 *   @0x2e98fa ldr r1, [pc, #0x8c]
 *   @0x2e98fe bl 0x2e5e36 <FT_Lookup_Renderer>
 *   @0x2e9902 str.w r0, [r5, #0x9c]
 *   @0x2e9906 ldr r3, [sp, #0x4]
 *   @0x2e990a mov r0, r9
 *   @0x2e990e bl 0x2e7336 <ft_mem_free>
 *   @0x2e9912 ldr r3, [sp, #0x4]
 *   @0x2e9916 cbnz r3, 0x2e9940 <FT_Add_Module+0x130>
 *   @0x2e991a ldr r3, [r4]
 *   @0x2e991e lsls r2, r2, #0x1f
 *   @0x2e9922 strmi r3, [r4, #0xc]
 *   @0x2e9926 cbnz r3, 0x2e9936 <FT_Add_Module+0x126>
 *   @0x2e992a adds r2, r3, #0x1
 *   @0x2e992e add.w r5, r5, r3, lsl #2
 *   @0x2e9932 str r4, [r5, #0x14]
 *   @0x2e9936 mov r0, r4
 *   @0x2e993a str r0, [sp]
 *   @0x2e993e beq 0x2e9928 <FT_Add_Module+0x118>
 *   @0x2e9942 ldr r3, [r3]
 *   @0x2e9946 bmi 0x2e9954 <FT_Add_Module+0x144>
 *   @0x2e994a mov r1, r4
 *   @0x2e9952 b 0x2e997e <FT_Add_Module+0x16e>
 *   @0x2e9956 cmp r3, #0x0
 *   @0x2e995a ldr r2, [r3, #0x24]
 *   @0x2e995e cmp r2, r1
 *   @0x2e9962 ldr r0, [r4, #0x34]
 *   @0x2e9966 beq 0x2e9948 <FT_Add_Module+0x138>
 *   @0x2e996a ldr r3, [r3, #0x14]
 *   @0x2e996e b 0x2e9948 <FT_Add_Module+0x138>
 *   @0x2e9972 b 0x2e997e <FT_Add_Module+0x16e>
 *   @0x2e9976 b 0x2e997e <FT_Add_Module+0x16e>
 *   @0x2e997a b 0x2e997e <FT_Add_Module+0x16e>
 *   @0x2e997e add sp, #0x8
 *   @0x2e9986 movs r2, r0
 *   @0x2e998a ldr r5, [r6, #0x74]
 *
 * ══ FT_Done_Library  0x2e998c  size 148  本节 32 条（Thumb-2 半字段）｜入度 5
 * @func 0x2e9992 0x2e9a32  size 160  36 条
 * 部分覆盖: 本节 36/76 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 34/72 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 33/70 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 32/68 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9992 cmp r0, #0x0
 *   @0x2e9996 ldr.w r3, [r0, #0xbc]
 *   @0x2e999a movs r6, #0x0
 *   @0x2e999e str.w r3, [r0, #0xbc]
 *   @0x2e99a2 cmp r3, #0x0
 *   @0x2e99a6 ldr.w r9, [r0]
 *   @0x2e99aa ldr r3, [pc, #0x70]
 *   @0x2e99ae stm.w sp, {r3, r6}
 *   @0x2e99b2 movs r5, #0x0
 *   @0x2e99b6 cmp r5, r3
 *   @0x2e99ba add.w r3, r4, r5, lsl #2
 *   @0x2e99be ldr r7, [r3, #0x14]
 *   @0x2e99c2 ldr r1, [r6, r3]
 *   @0x2e99ce blx 0xb6574 <strcmp@plt>
 *   @0x2e99d2 cbnz r0, 0x2e99e8 <FT_Done_Library+0x5c>
 *   @0x2e99da bpl 0x2e99e8 <FT_Done_Library+0x5c>
 *   @0x2e99de cbz r3, 0x2e99e8 <FT_Done_Library+0x5c>
 *   @0x2e99e2 bl 0x2e8bdc <FT_Done_Face>
 *   @0x2e99e6 b 0x2e99dc <FT_Done_Library+0x50>
 *   @0x2e99ea b 0x2e99b4 <FT_Done_Library+0x28>
 *   @0x2e99ee cmp r6, #0x8
 *   @0x2e99f2 ldr r6, [r4, #0x10]
 *   @0x2e99f6 add.w r6, r4, r6, lsl #2
 *   @0x2e99fa mov r0, r4
 *   @0x2e99fe bl 0x2e9724 <FT_Remove_Module>
 *   @0x2e9a02 b 0x2e99f2 <FT_Done_Library+0x66>
 *   @0x2e9a06 mov r1, r4
 *   @0x2e9a0e movs r0, #0x21
 *   @0x2e9a12 mov r0, r6
 *   @0x2e9a16 pop.w {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2e9a1a nop
 *   @0x2e9a1e movs r2, r1
 *
 * ══ FT_Add_Default_Modules  0x2e9a20  size 32  本节 8 条（Thumb-2 半字段）｜入度 1
 * @func 0x2e9a22 0x2e9a42  size 32  8 条
 * 部分覆盖: 本节 8/16 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9a22 mov r5, r0
 *   @0x2e9a26 add r4, pc
 *   @0x2e9a2a ldr r1, [r4, #4]!
 *   @0x2e9a2e cbz r1, 0x2e9a38 <FT_Add_Default_Modules+0x18>
 *   @0x2e9a32 bl 0x2e9810 <FT_Add_Module>
 *   @0x2e9a36 b 0x2e9a2a <FT_Add_Default_Modules+0xa>
 *   @0x2e9a3a nop
 *   @0x2e9a3e movs r0, r2
 *
 * ══ FT_Set_Default_Properties  0x2e9a40  size 240  本节 51 条（Thumb-2 半字段）｜入度 15
 * @func 0x2e9a46 0x2e9b36  size 240  52 条
 * 部分覆盖: 本节 52/112 条（其余由其它卡的同一 @func 主张）
 * 部分覆盖: 本节 51/110 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9a46 ldr r5, [pc, #0xe0]
 *   @0x2e9a4a ldr r0, [pc, #0xe0]
 *   @0x2e9a4e ldr r5, [r5]
 *   @0x2e9a52 ldr r3, [r5]
 *   @0x2e9a56 str r3, [sp, #0x18c]
 *   @0x2e9a5e cmp r0, #0x0
 *   @0x2e9a62 add.w r10, sp, #0x108
 *   @0x2e9a66 mov r7, sp
 *   @0x2e9a6a cmp r3, #0x0
 *   @0x2e9a6e cmp r3, #0x20
 *   @0x2e9a72 cmp r3, #0x9
 *   @0x2e9a76 mov r1, r4
 *   @0x2e9a7a mov r3, r1
 *   @0x2e9a82 cmp r0, #0x3a
 *   @0x2e9a86 strb r0, [r7, r2]
 *   @0x2e9a8a cmp r2, #0x80
 *   @0x2e9a8e bne 0x2e9a7a <FT_Set_Default_Properties+0x3a>
 *   @0x2e9a92 strb r0, [r7, r2]
 *   @0x2e9a96 cmp r2, #0x3a
 *   @0x2e9a9a cmp r3, r4
 *   @0x2e9a9e adds r6, r3, #0x1
 *   @0x2e9aa2 mov r4, r0
 *   @0x2e9aa6 mov r3, r1
 *   @0x2e9aae cmp r0, #0x3d
 *   @0x2e9ab2 strb r0, [r2, r4]
 *   @0x2e9ab6 cmp r4, #0x80
 *   @0x2e9aba bne 0x2e9aa6 <FT_Set_Default_Properties+0x66>
 *   @0x2e9abe strb r5, [r2, r4]
 *   @0x2e9ac2 cmp r1, #0x3d
 *   @0x2e9ac6 cmp r3, r6
 *   @0x2e9aca adds r3, #0x1
 *   @0x2e9ace mov r4, r6
 *   @0x2e9ada cmp r1, #0x9
 *   @0x2e9ade strb.w r1, [r5, r10]
 *   @0x2e9ae2 adds r5, #0x1
 *   @0x2e9ae6 mov r4, r6
 *   @0x2e9aea add r1, sp, #0x190
 *   @0x2e9aee movs r1, #0x0
 *   @0x2e9af6 tst.w r1, #0xdf
 *   @0x2e9afa beq 0x2e9b00 <FT_Set_Default_Properties+0xc0>
 *   @0x2e9afe bne 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9b02 beq 0x2e9b12 <FT_Set_Default_Properties+0xd2>
 *   @0x2e9b06 mov r1, sp
 *   @0x2e9b0a bl 0x2e5fa6 <ft_property_string_set>
 *   @0x2e9b0e adds r4, #0x1
 *   @0x2e9b12 ldr r2, [sp, #0x18c]
 *   @0x2e9b1a beq 0x2e9b20 <FT_Set_Default_Properties+0xe0>
 *   @0x2e9b22 pop.w {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2e9b26 nop
 *   @0x2e9b2a movs r0, r2
 *   @0x2e9b2e movs r2, r1
 *
 * ══ FT_Init_FreeType  0x2e9b30  size 50  本节 9 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9b32 0x2e9b62  size 48  9 条
 * 部分覆盖: 本节 9/21 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9b32 mov r4, r0
 *   @0x2e9b3a cbz r0, 0x2e9b5e <FT_Init_FreeType+0x2e>
 *   @0x2e9b3e bl 0x2e72f8 <FT_New_Library>
 *   @0x2e9b42 mov r5, r0
 *   @0x2e9b46 mov r0, r6
 *   @0x2e9b4e ldr r0, [r4]
 *   @0x2e9b56 bl 0x2e9a40 <FT_Set_Default_Properties>
 *   @0x2e9b5a mov r0, r5
 *   @0x2e9b5e movs r0, #0x7
 *
 * ══ FT_Done_FreeType  0x2e9b62  size 24  本节 5 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9b64 0x2e9b7c  size 24  5 条
 * 部分覆盖: 本节 5/11 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9b64 cbz r0, 0x2e9b76 <FT_Done_FreeType+0x14>
 *   @0x2e9b68 bl 0x2e998c <FT_Done_Library>
 *   @0x2e9b6c mov r0, r4
 *   @0x2e9b74 pop {r4, pc}
 *   @0x2e9b78 pop {r4, pc}
 *
 * ══ anon_2e9b7a  0x2e9b7a  size 88  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9bd2 0x2e9be6  size 20  5 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9bd2 ldrblt r11, [r0, #-0xfb4]!
 *
 * ══ FT_Stream_Open  0x2e9bd4  size 112  本节 23 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9bd6 0x2e9c3e  size 104  23 条
 * 部分覆盖: 本节 23/49 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9bd6 mov r4, r0
 *   @0x2e9bda beq 0x2e9c30 <FT_Stream_Open+0x5c>
 *   @0x2e9bde str r1, [r0, #0x10]
 *   @0x2e9be2 str r5, [r0]
 *   @0x2e9be6 str r5, [r0, #0x14]
 *   @0x2e9bea mov r0, r1
 *   @0x2e9bee add r1, pc
 *   @0x2e9bf6 cbz r0, 0x2e9c34 <FT_Stream_Open+0x60>
 *   @0x2e9bfa movs r2, #0x2
 *   @0x2e9c02 blx 0xb68e0 <ftell@plt>
 *   @0x2e9c06 str r0, [r4, #0x4]
 *   @0x2e9c0a mov r0, r6
 *   @0x2e9c12 pop {r4, r5, r6, pc}
 *   @0x2e9c16 mov r1, r5
 *   @0x2e9c1a blx 0xb68d4 <fseek@plt>
 *   @0x2e9c1e ldr r3, [pc, #0x1c]
 *   @0x2e9c22 mov r0, r5
 *   @0x2e9c26 str r3, [r4, #0x14]
 *   @0x2e9c2a add r3, pc
 *   @0x2e9c2e pop {r4, r5, r6, pc}
 *   @0x2e9c32 pop {r4, r5, r6, pc}
 *   @0x2e9c36 pop {r4, r5, r6, pc}
 *   @0x2e9c3a movs r2, r1
 *
 * ══ FT_New_Memory  0x2e9c44  size 48  本节 8 条（Thumb-2 半字段）｜入度 0
 * @func 0x2e9c46 0x2e9c6a  size 36  8 条
 * 部分覆盖: 本节 8/17 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2e9c46 movs r0, #0x10
 *   @0x2e9c4e movs r3, #0x0
 *   @0x2e9c52 ldr r3, [pc, #0x14]
 *   @0x2e9c56 str r3, [r0, #0x4]
 *   @0x2e9c5a add r3, pc
 *   @0x2e9c5e ldr r3, [pc, #0x10]
 *   @0x2e9c62 str r3, [r0, #0x8]
 *   @0x2e9c66 nop
 *
 * ══ anon_2e9c78  0x2e9c78  size 26568  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f0440 0x2f0444  size 4  1 条
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f0440 ldclt p6, c4, [r0, #-64]!
 *
 * ══ anonT_2f08c6  0x2f08c6  size 1110  本节 80 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f08d4 0x2f0d18  size 1092  80 条
 * 部分覆盖: 本节 80/481 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f08d4 shasxmi pc, r0, r0
 *   @0x2f08ec adcvs pc, r5, r4, lsr #26
 *   @0x2f0914 .word 0xf844fd10
 *   @0x2f0918 .word 0xf8447c08
 *   @0x2f091c .word 0xf8447c10
 *   @0x2f0920 .word 0xf8447c0c
 *   @0x2f0924 strb r7, [lr, r4, lsl #24]!
 *   @0x2f092c adcvs pc, lr, r4, lsl #26
 *   @0x2f094c .word 0x4628ffd5
 *   @0x2f0954 movwhs pc, #0xcf0
 *   @0x2f097c .word 0x6125ffdd
 *   @0x2f0990 .word 0xf8c130d0
 *   @0x2f0994 .word 0xf8c1319c
 *   @0x2f0998 .word 0xf8c133a0
 *   @0x2f099c .word 0xf8c135a4
 *   @0x2f09a0 .word 0xf7f637a8
 *   @0x2f09a4 ldrbmi r11, [r0, -r8, asr #25]!
 *   @0x2f09b0 movwls r0, #0x3804
 *   @0x2f09c0 movwhs r11, #0x1000
 *   @0x2f09d8 andhs r12, r0, #4, #24
 *   @0x2f09e0 ldcne p12, c0, [r12, #-48]
 *   @0x2f09e8 andhs r9, r1, #4, #24
 *   @0x2f0a08 stmdavs r3!, {r8, r9, r10, r11} ^
 *   @0x2f0a3c stm r5, {r0, r1, r2, r3}
 *   @0x2f0a40 ldrb r0, [r1, pc]!
 *   @0x2f0a48 tstlt r11, r0, lsl #4
 *   @0x2f0a5c bllo 0x372a74 <_ZTS13C_UTF16String+0x9b20>
 *   @0x2f0a70 andlt r11, r7, r0
 *   @0x2f0a90 strmi r7, [r4], -r1, lsl #10
 *   @0x2f0aa0 andhs pc, r1, r3, lsl #31
 *   @0x2f0abc .word 0xf1040324
 *   @0x2f0ac0 ldrmi r0, [r1], -r4, lsl #16
 *   @0x2f0acc strbmi r0, [pc], #-1795
 *   @0x2f0af0 .word 0xf1037c1c
 *   @0x2f0af4 .word 0xf8430320
 *   @0x2f0af8 ldrtmi r12, [r12], #3124
 *   @0x2f0b20 bl 0xff623ba8 <b2_toiTime+0xfffffffffeeca704>
 *   @0x2f0b24 .word 0xf8530c07
 *   @0x2f0b28 strbmi r7, [r7, #-0xc1c]!
 *   @0x2f0b30 .word 0xf853cc1c
 *   @0x2f0b34 stmdblo r1, {r5, r10, r11, lr, pc}
 *   @0x2f0b48 mvnle r12, r4, lsr r12
 *   @0x2f0b54 ldrbmi r0, [r0], #2051
 *   @0x2f0b70 addsvs r1, r9, r12
 *   @0x2f0b84 ldrtmi r1, [r1], #-1090
 *   @0x2f0b90 andsle r0, r3, r4, lsl #8
 *   @0x2f0ba4 blne 0xfe9b342c <b2_toiTime+0xfffffffffe259f88>
 *   @0x2f0bb4 .word 0xf8c80109
 *   @0x2f0bb8 ldrb r1, [r11, r12]
 *   @0x2f0bc0 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f0bc4 strdlt r4, r5, [r9], r0
 *   @0x2f0bcc andls r6, r5, #28, #2
 *   @0x2f0be0 andvs r8, r6, r9, lsl #1
 *   @0x2f0bf0 .word 0xf10420d4
 *   @0x2f0bf4 .word 0xf8940080
 *   @0x2f0bf8 addsmi r2, r10, #124
 *   @0x2f0c00 rfedb r0!
 *   @0x2f0c04 movwlo lr, #0x1013
 *   @0x2f0c10 .word 0xf105307c
 *   @0x2f0c14 .word 0xf1040114
 *   @0x2f0c18 .word 0x260c009a
 *   @0x2f0c20 rfeia r4!
 *   @0x2f0c24 adcvs r3, r11, r10, ror r0
 *   @0x2f0c2c addsmi r2, r10, #125
 *   @0x2f0c34 rfedb r0!
 *   @0x2f0c38 movwlo lr, #0x1013
 *   @0x2f0c44 .word 0xf505307d
 *   @0x2f0c48 .word 0xf1047cce
 *   @0x2f0c4c strhs r0, [r0], -r12, lsl #22
 *   @0x2f0c74 .word 0xf8cd0a01
 *   @0x2f0c78 .word 0xf7ffc010
 *   @0x2f0c7c .word 0xf8ddfefd
 *   @0x2f0c80 svcvs #0x62c010
 *   @0x2f0ca0 .word 0x4649fbbd
 *   @0x2f0cb4 .word 0x4639fbb3
 *   @0x2f0cc4 .word 0xf7f4707a
 *   @0x2f0cc8 mcrvs p8, #0x7, pc, c3, c6, #0x7
 *   @0x2f0cdc svcvs #0x6339b0
 *   @0x2f0d0c ldclpl p1, c0, [r0], {7}
 *   @0x2f0d14 andmi pc, r8, r1, lsl #2
 *
 * ══ anon_2f0d1c  0x2f0d1c  size 1060  本节 1 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f1140 0x2f1148  size 8  2 条
 * 部分覆盖: 本节 1/2 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f1140 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *
 * ══ anonT_2f1142  0x2f1142  size 700  本节 44 条（Thumb-2 半字段）｜入度 0
 * @func 0x2f1144 0x2f1400  size 700  44 条
 * 部分覆盖: 本节 44/318 条（其余由其它卡的同一 @func 主张）
 * 说明: 本节只补「4 字节栅格漏掉」的指令；该函数的主体与结构事实见其它卡的同一 @func
 * 未主张: 语义（本卡只为把归属与逐条锚点补正，不新增语义）
 *   @0x2f1144 .word 0x469a4ff0
 *   @0x2f115c .word 0xf8d310c4
 *   @0x2f1160 stmdbvs r3, {r3, r6, r7, sp, lr}
 *   @0x2f1168 .word 0xf0400708
 *   @0x2f116c stmdavs r0, {r0, r2, r6, r8, pc}
 *   @0x2f117c bls 0x3f1040
 *   @0x2f1194 stmdblt r11!, {r0, r3, r4, r5, r6, r12, sp}
 *   @0x2f11a0 and r3, r1, r10, ror r0
 *   @0x2f11c8 .word 0xf8d839bc
 *   @0x2f11cc ldrbmi r0, [pc], #-412
 *   @0x2f11d8 bl 0xff3978c0 <b2_toiTime+0xfffffffffec3e41c>
 *   @0x2f11dc .word 0xf1c90c07
 *   @0x2f11e0 ldrmi r0, [r4, #0x200]
 *   @0x2f11f4 ldrmi r2, [r4, #0x9b4]
 *   @0x2f11fc smladhs r1, r0, r0, r9
 *   @0x2f1214 strbmi r9, [pc], -r0
 *   @0x2f1234 addsmi r0, r9, #0, #6
 *   @0x2f1254 stmdbvs r3, {r1, r8, r9, r10}
 *   @0x2f1278 adcvs r0, r5, r9, lsl #10
 *   @0x2f129c .word 0x071b3010
 *   @0x2f12ac .word 0xf8dbff4a
 *   @0x2f12b0 .word 0xf8db600c
 *   @0x2f12b4 stmdavs r0!, {r3, r12, sp} ^
 *   @0x2f12c0 bl 0x3b92d8 <error_g0017+0x11f7c>
 *   @0x2f12c4 .word 0xf8db0060
 *   @0x2f12c8 stmdbls r6, {r12, sp}
 *   @0x2f12d4 ldrtmi pc, [r0], #-3843
 *   @0x2f12f8 eors r0, r12, pc, lsr r6
 *   @0x2f1300 ldcle p3, c0, [r3, #-128]
 *   @0x2f1308 .word 0xf101033f
 *   @0x2f130c blne 0xfea71b94 <b2_toiTime+0xfffffffffe3186f0>
 *   @0x2f135c .word 0xdc02023f
 *   @0x2f136c and r0, r2, r6, lsr r5
 *   @0x2f1374 ldmdbne r2!, {r0, r1, r2, r3, r4, r5, r8, r10} ^
 *   @0x2f1380 .word 0xf022033f
 *   @0x2f1384 blne 0xfe9b1c88 <b2_toiTime+0xfffffffffe2587e4>
 *   @0x2f138c bl 0xfeb0d720 <b2_toiTime+0xfffffffffe3b427c>
 *   @0x2f1390 blne 0x178d724 <b2_toiTime+0x1034280>
 *   @0x2f1398 bl 0xfeb4db28 <b2_toiTime+0xfffffffffe3f4684>
 *   @0x2f139c addmi r7, r8, #-2147483592
 *   @0x2f13b8 movths r0, #0x33f
 *   @0x2f13d4 rscvs r0, r3, r0, asr #30
 *   @0x2f13f4 .word 0x61230308
 *   @0x2f13fc strdeq r8, r9, [r0], -r0
 */
