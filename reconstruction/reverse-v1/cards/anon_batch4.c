/* cally 逆向卡：anon_batch4 —— libjpeg 的 10 个静态示例程（原版 libyoyo.so，armv7）
 *（stripped，ELF32 ARM，armeabi-v7a）
 *
 * @card  10 段互不相邻，合计 11,528 B / 2,882 条锚点：
 *        0x2b3bac..0x2b3edc  816 B   0x2b4878..0x2b4c50   984 B
 *        0x2b4c50..0x2b57b0 2912 B   0x2b6a50..0x2b6e98  1096 B
 *        0x2b71dc..0x2b74f8  796 B   0x2b7608..0x2b7ac0  1208 B
 *        0x2b7ac0..0x2b7d50  656 B   0x2b7d50..0x2b7fd8   648 B
 *        0x2bec98..0x2bf198 1280 B   0x2b8500..0x2b896c  1132 B
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-anon_{2b3bac,2b4878,2b4c50,2b6a50,2b71dc,2b7608,2b7ac0,2b7d50,2bec98,2b8500}.tsv
 *        全部由 scripts/asm_index.py --so libyoyo.so --start --end 生成（ARM triple，未加 --thumb：
 *        十段首条都是 ARM 自洽的 push，且 2,882 条槽位里 .word 伪指令 = 0 —— 若误把 Thumb 段按
 *        ARM 解，ldr/mov 的立即数字段会大量解码成 .word 与条件后缀乱码，这批一个都没有。
 *        十段地址也都不在 asm/thumb_symbols.tsv 里，与规则一致。）
 * 级别:  骨架（锚点全覆盖、逐字一致；语义钉到"段是什么、入口契约、方法槽安装点、调用面、
 *        段内函数边界"，函数体内部按 objdump 原文逐条列出，不逐条解释）
 *
 * ══ 一句话结论 ═══════════════════════════════════════════════════════
 *   十段全是**静态链接进 libyoyo.so 的 libjpeg（IJG jpeg-9 系）例程**，集中在 jdhuff.c /
 *   jdphuff.c / jdmarker.c / jdinput.c / jdmerge.c / jdsample.c 六个 TU：
 *
 *     段         大小   指令  身份                                        证据类型
 *     2b3bac     816   204   jdinput.c  consume_markers                    方法槽 inputctl+0x0
 *     2b4878     984   246   jdmarker.c get_dht                            bl jpeg_alloc_huff_table
 *     2b4c50    2912   728   jdmarker.c read_markers                      方法槽 marker+0x4
 *     2b6a50    1096   274   jdmerge.c  merged_1v + h2v1 + h2v2（3 个函数）  方法槽 upsample+0x4/+0xc
 *     2b71dc     796   199   jdphuff.c  start_pass_phuff_decoder           方法槽 entropy+0x0
 *     2b7608    1208   302   jdphuff.c  decode_mcu_*（DC 族）              process_restart 同族
 *     2b7ac0     656   164   jdphuff.c  decode_mcu_*（AC 族）              process_restart 同族
 *     2b7d50     648   162   jdphuff.c  decode_mcu_*（AC 族，natural_order） process_restart 同族
 *     2bec98    1280   320   jdhuff.c   decode_mcu（基线）                方法槽 entropy+0x4
 *     2b8500    1132   283   jdsample.c sep_upsample + 4 放大例程（5 函数+1 续块） jinit_upsampler 装表
 *
 *   为什么这十段会被切成匿名段（split 的两个信号都收不到）：
 *     ① 它们没有符号（stripped），也**没有直接 bl 边**——除 get_dht 有 1 条来自
 *        read_markers 的 bl 外，其余九段的入口都是 jinit_* 写进 cinfo->xxx 结构方法槽的函数
 *        指针（§10 的分派器安装点本卡没找到，见 open 4）。
 *     ② split_anon.py 的"prologue 紧跟在池字/bx/pop 之后"启发式在这些位置失效：多数函数的
 *        首条是 `ldr rX,[r0,#imm]`（把 cinfo 字段取进寄存器做 shrink-wrap），push 落在 +4，
 *        切分器把 4 B 的预序言单独切成一段，真正的函数从 push 起算（本卡沿用 split 起点，
 *        在每节注明"真入口 = 起点 - 4"）。
 *     ③ jdmerge / jdsample 那两段里，几个函数之间只有间接调用，且后两个是无 lr 的叶子
 *        （push 不带 lr、出口 bx lr），切分器两个信号都看不到，于是一段里塞了 3~5 个函数。
 *
 * ══ 计数口径（写死，便于复核）═══════════════════════════════════════
 *   段        [start,end)      index 行  .word 伪指令  真入口     出口
 *   2b3bac    2b3bac..2b3edc     204        0       2b3bac    6 个 pop
 *   2b4878    2b4878..2b4c50     246        0       2b4878    2b4ba0 pop
 *   2b4c50    2b4c50..2b57b0     728        0       2b4c4c    3 个 pop
 *   2b6a50    2b6a50..2b6e98     274        0       2b6a50    3 个（3 个函数各一）
 *   2b71dc    2b71dc..2b74f8     199        0       2b71d8    2b7464 pop
 *   2b7608    2b7608..2b7ac0     302        0       2b7608    2 个 pop
 *   2b7ac0    2b7ac0..2b7d50     164        0       2b7ac0    2 个 pop
 *   2b7d50    2b7d50..2b7fd8     162        0       2b7d50    2 个 pop
 *   2bec98    2bec98..2bf198     320        0       2bec94    2 个 pop
 *   2b8500    2b8500..2b896c     283        0       2b8500    6 个（5 函数 + 1 续块）
 *   —— index 行 = asm_index.py 对 [start,end) 的 4 B 栅格输出；十段合计 2,882 行，与
 *      wc -l 十张索引之和一致。
 *   —— 段尾常见 1~3 个池字/下一函数预序言被 objdump 译成带条件后缀的"指令"
 *      （andeq/andseq/strdeq 之类），按 README 规矩 3 保留 objdump 原文并就地标"非本函数"。
 *
 * ══ 与其它卡的分工（2026-10-28 18:0x 复核）════════════════════════════
 *   cards/anon_batch2.c 覆盖 2b3f58（1052 B）/ 2bb3c4 / 2bdb14 —— 与本卡零地址交集。
 *     2b3f58 是 read_markers 的三个 bl 目标之一（§3 的调用面），本卡不重复锚它。
 *   已具名、不在本卡的 libjpeg 例程：jpeg_alloc_huff_table 0x2bc908、jpeg_alloc_quant_table
 *   0x2bc8e4、jpeg_make_d_derived_tbl 0x2be510、jpeg_fill_bit_buffer 0x2bea2c、
 *   jpeg_huff_decode 0x2beb8c、jinit_* 全部具名。
 *   本卡未收的相邻匿名段（缺卡）：2b7148（148 B process_restart，§6/§7/§8 三段都调它）、
 *   2b5cf8（164 B read_restart_marker）、2b4850（40 B reset_marker_reader）。
 *
 * ══ 匿名段覆盖账（本卡落盘后）═════════════════════════════════════
 *   asm/anon_splits.tsv 521 段 / 399,240 B
 *   落盘前已覆盖 31 段 / 82,128 B（anon_batch3 15 / anon_batch2 10 / anon_319414 2 /
 *   anon_268fb4 1 / 其余 3 段靠 anchor 命中：153b54、230674、26f1e8）
 *   本卡 +10 段 / +11,528 B  →  41 段 / 93,656 B = 7.9% 段数 / 23.5% 字节数
 *   （段数占比低是因为大块匿名区被切成很多 <512 B 的小段；≥512 B 的未覆盖段从 122 降到 112）
 *
 * ══ open（本卡未闭合的 5 条）═════════════════════════════════════════
 *   1. §1 consume_markers 的消费方未逐点验证：本卡只证"槽 #0 = 本段"，没去数 jpeg_consume_input
 *      (0x2b2f08) 等公共入口里对 [inputctl+0x0] 的 blx 点（cinfo 偏移在别的结构里也复用，
 *      简单扫描会把 30 个无关函数算进来）。
 *   2. get_dht 的第二个入口（marker 处理器表）在 .rodata，本卡没读那段数据，只证了 read_markers
 *      的那条 bl。
 *   3. §6/§7/§8 与 DC_first / DC_refine / AC_first / AC_refine 的一一对应没做运行期对照，
 *      只按 blocks_in_MCU / natural_order / 循环体长度分到 DC 族与 AC 族。
 *   4. §10 的分派器 0x2b8500 没找到直接的 str 安装点（jinit_upsampler 里对它的赋值可能经栈槽
 *      中转），"它是 jpeg_upsampler 槽 #1 upsample" 只是按调用形态（7 参数、读 output_width、
 *      按组件调 methods[]）推的。
 *   5. §10 的 0x2b85b8 块：入口读 r5+0x24 但 r5 无定义，判为 0x2b8500 的冷块/续块，未证。
 *
 * ══ claims 对照 ═══════════════════════════════════════════════════════
 *   claims-batchBT.jsonl: BT4-001..BT4-014
 * ════════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════════
 * §1  anon_2b3bac = jdinput.c consume_markers（jpeg_input_controller 槽 #0）
 * ═══════════════════════════════════════════════════════════════════════
 * 契约：int consume_markers(j_decompress_ptr cinfo)——r0 = cinfo，返回 0/1/2
 *       （jpeglib.h：JPEG_SUSPENDED=0 / JPEG_ROW_COMPLETED=1 / JPEG_SCAN_COMPLETED=2）
 *
 * 身份证据（两条独立）
 *   ① 安装点：jinit_input_controller(0x2b3ee0) 在 0x2b3f24 把 alloc_small 的返回值写进
 *      cinfo+0x190（= cinfo->inputctl），0x2b3f2c `str r6,[r0]` 把本段地址写进结构体 +0
 *      ⇒ jpeg_input_controller 的第 1 个方法槽 consume_input。同一函数在 0x2b3f34 写 +0xc
 *      （finish_input_pass）、0x2b3f30 的 stmib 写 +4/+8（reset_input_controller /
 *      has_multiple_scans），四个槽与 jpeglib.h 的字段次序逐一对上。
 *   ② 体内形态：0x2b3bb4 读 cinfo+0x190 → 0x2b3bb8 读 inputctl+0x11 的 1 字节标志，
 *      非 0 立刻 `mov r0,#2` 返回；否则 0x2b3bcc 读 cinfo+0x194（marker reader）→
 *      0x2b3bd0 取 +0x4 槽（= 本卡 §3 0x2b4c50 read_markers）→ blx；返回值 1/2/0 三分支。
 *      这正是 consume_markers 的"把 read_markers 的三态返回再翻译一层"协议。
 *
 * 它调谁：read_markers（经 [marker+0x4]，= §3）、jdiv_round_up(0x2bc7ec) ×5
 * 谁调它：0 处直接 bl（全库扫过 645,282 条指令，没有任何 bl/blx 落到 0x2b3bac..0x2b3edc）。
 *         唯一入口是方法槽 cinfo->inputctl->consume_input；消费方是 jpeg_consume_input
 *         (0x2b2f08，688 B，具名) 等公共入口，本卡未逐点验证（open 1）。
 * 边界：单函数，6 个 pop 出口（0x2b3bc8 / 2b3c2c / 2b3c54 / 2b3c58 / 2b3c70 / 2b3e70）；
 *       0x2b3ed0 是一条无条件 b，其后的 0x2b3ed4/0x2b3ed8（mov #8 / str [r4+0x118]）不可达，
 *       是本段末尾的死码，不是下一函数的入口（下一函数 jinit_input_controller 在 0x2b3ee0）。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b3bac 0x2b3edc anon_2b3bac consume_markers */

/* @0x2b3bac push {r4, r5, r6, r7, r8, r9, r10, lr} —— 序言：保存 8 个寄存器，无栈帧 */
/* @0x2b3bb0 mov r4, r0 */
/* @0x2b3bb4 ldr r5, [r0, #0x190] —— cinfo+0x190 = cinfo->inputctl（jinit_input_controller 在 0x2b3f24 写入） */
/* @0x2b3bb8 ldrb r3, [r5, #0x11] —— inputctl+0x11 的 1 字节标志：非 0 直接返回 2 */
/* @0x2b3bbc cmp r3, #0 */
/* @0x2b3bc0 beq 0x2b3bcc <jpeg_finish_output+0x3dc> */
/* @0x2b3bc4 mov r0, #2 —— 返回 2 = JPEG_SCAN_COMPLETED（第 1 个出口） */
/* @0x2b3bc8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3bcc ldr r3, [r0, #0x194] —— cinfo+0x194 = cinfo->marker */
/* @0x2b3bd0 ldr r3, [r3, #0x4] —— marker+0x4 = read_markers 槽（= §3 的 0x2b4c50） */
/* @0x2b3bd4 blx r3 —— blx → read_markers（本段唯一外部调用） */
/* @0x2b3bd8 cmp r0, #1 —— 返回 1/2 分流：1=ROW_COMPLETED，2=SCAN_COMPLETED */
/* @0x2b3bdc mov r6, r0 */
/* @0x2b3be0 beq 0x2b3c30 <jpeg_finish_output+0x440> */
/* @0x2b3be4 cmp r0, #2 */
/* @0x2b3be8 bne 0x2b3c58 <jpeg_finish_output+0x468> */
/* @0x2b3bec ldrb r3, [r5, #0x14] */
/* @0x2b3bf0 mov r2, #1 */
/* @0x2b3bf4 strb r2, [r5, #0x11] —— 置 inputctl+0x11 = 1（记住已到扫描尾） */
/* @0x2b3bf8 cmp r3, #0 */
/* @0x2b3bfc beq 0x2b3c5c <jpeg_finish_output+0x46c> */
/* @0x2b3c00 ldr r3, [r4, #0x194] —— marker+0xd 的 1 字节标志 */
/* @0x2b3c04 ldrb r3, [r3, #0xd] */
/* @0x2b3c08 cmp r3, #0 */
/* @0x2b3c0c beq 0x2b3bc4 <jpeg_finish_output+0x3d4> */
/* @0x2b3c10 ldr r3, [r4] */
/* @0x2b3c14 mov r0, r4 */
/* @0x2b3c18 mov r1, #59 */
/* @0x2b3c1c ldr r2, [r3] */
/* @0x2b3c20 str r1, [r3, #0x14] */
/* @0x2b3c24 blx r2 */
/* @0x2b3c28 mov r0, r6 */
/* @0x2b3c2c pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c30 ldrb r3, [r5, #0x14] */
/* @0x2b3c34 cmp r3, #0 */
/* @0x2b3c38 bne 0x2b3c74 <jpeg_finish_output+0x484> */
/* @0x2b3c3c ldrb r3, [r5, #0x10] */
/* @0x2b3c40 cmp r3, #0 */
/* @0x2b3c44 beq 0x2b3e74 <jpeg_finish_output+0x684> */
/* @0x2b3c48 mov r0, r4 */
/* @0x2b3c4c bl 0x2b3908 <jpeg_finish_output+0x118> */
/* @0x2b3c50 mov r0, #1 */
/* @0x2b3c54 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c58 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c5c ldr r3, [r4, #0x7c] */
/* @0x2b3c60 ldr r2, [r4, #0x84] */
/* @0x2b3c64 cmp r2, r3 */
/* @0x2b3c68 ble 0x2b3bc4 <jpeg_finish_output+0x3d4> */
/* @0x2b3c6c str r3, [r4, #0x84] */
/* @0x2b3c70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3c74 ldr r2, [r4, #0x20] */
/* @0x2b3c78 movw r3, #0xffdc */
/* @0x2b3c7c cmp r2, r3 */
/* @0x2b3c80 bgt 0x2b3c90 <jpeg_finish_output+0x4a0> */
/* @0x2b3c84 ldr r2, [r4, #0x1c] */
/* @0x2b3c88 cmp r2, r3 */
/* @0x2b3c8c ble 0x2b3cb4 <jpeg_finish_output+0x4c4> */
/* @0x2b3c90 ldr r3, [r4] */
/* @0x2b3c94 movw r2, #0xffdc */
/* @0x2b3c98 mov r1, #41 */
/* @0x2b3c9c mov r0, r4 */
/* @0x2b3ca0 str r2, [r3, #0x18] */
/* @0x2b3ca4 ldr r2, [r4] */
/* @0x2b3ca8 str r1, [r3, #0x14] */
/* @0x2b3cac ldr r3, [r2] */
/* @0x2b3cb0 blx r3 */
/* @0x2b3cb4 ldr r3, [r4, #0xc0] */
/* @0x2b3cb8 cmp r3, #8 */
/* @0x2b3cbc beq 0x2b3ce0 <jpeg_finish_output+0x4f0> */
/* @0x2b3cc0 ldr r2, [r4] */
/* @0x2b3cc4 mov r1, #15 */
/* @0x2b3cc8 mov r0, r4 */
/* @0x2b3ccc str r3, [r2, #0x18] */
/* @0x2b3cd0 ldr r3, [r4] */
/* @0x2b3cd4 str r1, [r2, #0x14] */
/* @0x2b3cd8 ldr r3, [r3] */
/* @0x2b3cdc blx r3 */
/* @0x2b3ce0 ldr r12, [r4, #0x24] */
/* @0x2b3ce4 cmp r12, #10 */
/* @0x2b3ce8 bgt 0x2b3ea0 <jpeg_finish_output+0x6b0> */
/* @0x2b3cec cmp r12, #0 */
/* @0x2b3cf0 mov r1, #1 */
/* @0x2b3cf4 ldr r6, [r4, #0xc4] */
/* @0x2b3cf8 str r1, [r4, #0x110] */
/* @0x2b3cfc str r1, [r4, #0x114] */
/* @0x2b3d00 ble 0x2b3ed4 <jpeg_finish_output+0x6e4> */
/* @0x2b3d04 mov r7, #0 */
/* @0x2b3d08 mov r8, #18 */
/* @0x2b3d0c b 0x2b3d4c <jpeg_finish_output+0x55c> */
/* @0x2b3d10 ldr r2, [r6, #0xc] */
/* @0x2b3d14 sub r1, r2, #1 */
/* @0x2b3d18 cmp r1, #3 */
/* @0x2b3d1c bhi 0x2b3d64 <jpeg_finish_output+0x574> */
/* @0x2b3d20 ldr r0, [r4, #0x110] */
/* @0x2b3d24 add r6, r6, #84 */
/* @0x2b3d28 ldr r1, [r4, #0x114] */
/* @0x2b3d2c cmp r0, r3 */
/* @0x2b3d30 strge r0, [r4, #0x110] */
/* @0x2b3d34 strlt r3, [r4, #0x110] */
/* @0x2b3d38 cmp r1, r2 */
/* @0x2b3d3c movlt r1, r2 */
/* @0x2b3d40 cmp r7, r12 */
/* @0x2b3d44 str r1, [r4, #0x114] */
/* @0x2b3d48 bge 0x2b3d84 <jpeg_finish_output+0x594> */
/* @0x2b3d4c ldr r3, [r6, #0x8] */
/* @0x2b3d50 mov r0, r4 */
/* @0x2b3d54 add r7, r7, #1 */
/* @0x2b3d58 sub r2, r3, #1 */
/* @0x2b3d5c cmp r2, #3 */
/* @0x2b3d60 bls 0x2b3d10 <jpeg_finish_output+0x520> */
/* @0x2b3d64 ldr r2, [r4] */
/* @0x2b3d68 ldr r3, [r2] */
/* @0x2b3d6c str r8, [r2, #0x14] */
/* @0x2b3d70 blx r3 */
/* @0x2b3d74 ldr r3, [r6, #0x8] */
/* @0x2b3d78 ldr r2, [r6, #0xc] */
/* @0x2b3d7c ldr r12, [r4, #0x24] */
/* @0x2b3d80 b 0x2b3d20 <jpeg_finish_output+0x530> */
/* @0x2b3d84 cmp r12, #0 */
/* @0x2b3d88 mov r10, #8 */
/* @0x2b3d8c ldr r6, [r4, #0xc4] */
/* @0x2b3d90 movgt r7, #0 */
/* @0x2b3d94 str r10, [r4, #0x118] */
/* @0x2b3d98 movgt r9, r7 */
/* @0x2b3d9c movgt r8, #1 */
/* @0x2b3da0 ble 0x2b3e30 <jpeg_finish_output+0x640> */
/* @0x2b3da4 str r10, [r6, #0x24] */
/* @0x2b3da8 add r7, r7, #1 */
/* @0x2b3dac ldr r3, [r4, #0x1c] */
/* @0x2b3db0 add r6, r6, #84 */
/* @0x2b3db4 ldr r0, [r6, #-0x4c] */
/* @0x2b3db8 ldr r1, [r4, #0x110] */
/* @0x2b3dbc mul r0, r0, r3 */
/* @0x2b3dc0 lsl r1, r1, #3 */
/* @0x2b3dc4 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3dc8 ldr r3, [r6, #-0x48] */
/* @0x2b3dcc str r0, [r6, #-0x38] */
/* @0x2b3dd0 ldr r0, [r4, #0x20] */
/* @0x2b3dd4 ldr r1, [r4, #0x114] */
/* @0x2b3dd8 mul r0, r3, r0 */
/* @0x2b3ddc lsl r1, r1, #3 */
/* @0x2b3de0 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3de4 ldr r3, [r6, #-0x4c] */
/* @0x2b3de8 str r0, [r6, #-0x34] */
/* @0x2b3dec ldr r0, [r4, #0x1c] */
/* @0x2b3df0 ldr r1, [r4, #0x110] */
/* @0x2b3df4 mul r0, r3, r0 */
/* @0x2b3df8 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3dfc ldr r3, [r6, #-0x48] */
/* @0x2b3e00 str r0, [r6, #-0x2c] */
/* @0x2b3e04 ldr r0, [r4, #0x20] */
/* @0x2b3e08 ldr r1, [r4, #0x114] */
/* @0x2b3e0c mul r0, r3, r0 */
/* @0x2b3e10 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3e14 strb r8, [r6, #-0x24] */
/* @0x2b3e18 str r9, [r6, #-0x8] */
/* @0x2b3e1c str r0, [r6, #-0x28] */
/* @0x2b3e20 ldr r3, [r4, #0x24] */
/* @0x2b3e24 cmp r7, r3 */
/* @0x2b3e28 blt 0x2b3da4 <jpeg_finish_output+0x5b4> */
/* @0x2b3e2c ldr r1, [r4, #0x114] */
/* @0x2b3e30 lsl r1, r1, #3 */
/* @0x2b3e34 ldr r0, [r4, #0x20] */
/* @0x2b3e38 bl 0x2bc7ec <jdiv_round_up> */
/* @0x2b3e3c ldr r2, [r4, #0x124] */
/* @0x2b3e40 ldr r3, [r4, #0x24] */
/* @0x2b3e44 cmp r2, r3 */
/* @0x2b3e48 str r0, [r4, #0x11c] */
/* @0x2b3e4c blt 0x2b3e90 <jpeg_finish_output+0x6a0> */
/* @0x2b3e50 ldrb r3, [r4, #0xc8] */
/* @0x2b3e54 cmp r3, #0 */
/* @0x2b3e58 bne 0x2b3e90 <jpeg_finish_output+0x6a0> */
/* @0x2b3e5c ldr r2, [r4, #0x190] */
/* @0x2b3e60 strb r3, [r2, #0x10] */
/* @0x2b3e64 mov r3, #0 */
/* @0x2b3e68 mov r0, #1 */
/* @0x2b3e6c strb r3, [r5, #0x14] */
/* @0x2b3e70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x2b3e74 ldr r3, [r4] */
/* @0x2b3e78 mov r2, #35 */
/* @0x2b3e7c mov r0, r4 */
/* @0x2b3e80 str r2, [r3, #0x14] */
/* @0x2b3e84 ldr r3, [r3] */
/* @0x2b3e88 blx r3 */
/* @0x2b3e8c b 0x2b3c48 <jpeg_finish_output+0x458> */
/* @0x2b3e90 ldr r3, [r4, #0x190] */
/* @0x2b3e94 mov r2, #1 */
/* @0x2b3e98 strb r2, [r3, #0x10] */
/* @0x2b3e9c b 0x2b3e64 <jpeg_finish_output+0x674> */
/* @0x2b3ea0 ldr r3, [r4] */
/* @0x2b3ea4 mov lr, #26 */
/* @0x2b3ea8 mov r1, #10 */
/* @0x2b3eac mov r0, r4 */
/* @0x2b3eb0 str r12, [r3, #0x18] */
/* @0x2b3eb4 ldr r2, [r4] */
/* @0x2b3eb8 str lr, [r3, #0x14] */
/* @0x2b3ebc str r1, [r2, #0x1c] */
/* @0x2b3ec0 ldr r3, [r4] */
/* @0x2b3ec4 ldr r3, [r3] */
/* @0x2b3ec8 blx r3 */
/* @0x2b3ecc ldr r12, [r4, #0x24] */
/* @0x2b3ed0 b 0x2b3cec <jpeg_finish_output+0x4fc> */
/* @0x2b3ed4 mov r3, #8 */
/* @0x2b3ed8 str r3, [r4, #0x118] */
/* ═══════════════════════════════════════════════════════════════════════
 * §2  anon_2b4878 = jdmarker.c get_dht（DHT 段解析；308 B 栈帧 + canary）
 * ═══════════════════════════════════════════════════════════════════════
 * 契约：boolean get_dht(j_decompress_ptr cinfo)——r0 = cinfo，返回 1（成功）/0（挂起）；
 *       解析 M_DHT 段：长度字段 → 逐表 (Tc/Th, bits[17], huffval[]) → 装进 dc_huff_tbl_ptrs /
 *       ac_huff_tbl_ptrs。
 *
 * 身份证据（四条）
 *   ① 唯一直接调用者：本卡 §3 read_markers 在 0x2b5298 `bl 0x2b4878`（DHT 的处理器）。
 *   ② 0x2b4c18 `bl 0x2bc908 jpeg_alloc_huff_table` —— 全库只有这一处调用它；DQT 走的是
 *      jpeg_alloc_quant_table（对比 §3 里 0x2b5764 的那条 bl）。表类型由此唯一确定。
 *   ③ 0x2b48b8..0x2b48d0 是标准的段长解码：`lsl r6,r3,#8`（b0<<8）、`ldrb r9,[r5]`、
 *      `add r9,r9,r6`、`sub r9,r9,#2` = 两字节大端减 2（长度字段含自身 2 B）——只有
 *      DHT/DQT/DRI 这类"长度 + 表"的段这么读。
 *   ④ 0x2b487c `sub sp,sp,#308`：308 B 恰好装 bits[17] + huffval[256] + 对齐；同帧里的
 *      0x2b4898 从 GOT 单例取 canary、0x2b4c44 `bl __stack_chk_fail` —— GCC 只在含大数组的
 *      局部帧上插栈保护。三者合起来把"变长表段"钉成 DHT 而不是 DQT（DQT 的数组是 64 B，
 *      不会要 308 B 帧，也不会调 huff 表分配器）。
 *
 * 它调谁：jpeg_alloc_huff_table(0x2bc908) ×1、__stack_chk_fail(0xb65d4@plt) ×1（失败路径）
 * 谁调它：read_markers 直接 bl ×1（0x2b5298）；另经 marker 处理器表间接调用（表在 .rodata，
 *         本卡未读，open 2）
 * 边界：单函数，唯一出口 0x2b4ba0 `pop {r4..r11,pc}`；0x2b4c48 是池字（objdump 译成 andseq），
 *       0x2b4c4c 的 `ldr r3,[r0,#0x17c]` 已是 §3 read_markers 的预序言（split 多算了这 4 B）。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b4878 0x2b4c50 anon_2b4878 get_dht */

/* @0x2b4878 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言 + 308 B 帧（bits[17] + huffval[256] + 对齐） */
/* @0x2b487c sub sp, sp, #308 */
/* @0x2b4880 ldr r11, [r0, #0x18] —— cinfo+0x18 = cinfo->src */
/* @0x2b4884 mov r7, r0 */
/* @0x2b4888 ldr r12, [pc, #0x3b8] */
/* @0x2b488c ldr r12, [pc, r12] */
/* @0x2b4890 ldr r4, [r11, #0x4] */
/* @0x2b4894 str r12, [sp, #0x8] */
/* @0x2b4898 ldr r3, [r12] —— canary 从 GOT 单例取（__stack_chk_guard） */
/* @0x2b489c cmp r4, #0 */
/* @0x2b48a0 ldr r5, [r11] */
/* @0x2b48a4 str r3, [sp, #0x12c] */
/* @0x2b48a8 beq 0x2b4b74 <jinit_input_controller+0xc94> */
/* @0x2b48ac ldrb r3, [r5] */
/* @0x2b48b0 subs r4, r4, #1 */
/* @0x2b48b4 addne r5, r5, #1 */
/* @0x2b48b8 lsl r6, r3, #8 —— b0 << 8 */
/* @0x2b48bc beq 0x2b4be8 <jinit_input_controller+0xd08> */
/* @0x2b48c0 ldrb r9, [r5] */
/* @0x2b48c4 sub r4, r4, #1 */
/* @0x2b48c8 add r5, r5, #1 */
/* @0x2b48cc add r9, r9, r6 —— | b1（两字节大端） */
/* @0x2b48d0 sub r9, r9, #2 —— 段长 = 两字节 - 2 */
/* @0x2b48d4 str r9, [sp] */
/* @0x2b48d8 cmp r9, #16 */
/* @0x2b48dc ble 0x2b4b58 <jinit_input_controller+0xc78> */
/* @0x2b48e0 add r9, sp, #40 */
/* @0x2b48e4 add r12, sp, #24 */
/* @0x2b48e8 str r12, [sp, #0x14] */
/* @0x2b48ec cmp r4, #0 */
/* @0x2b48f0 bne 0x2b4910 <jinit_input_controller+0xa30> */
/* @0x2b48f4 ldr r3, [r11, #0xc] */
/* @0x2b48f8 mov r0, r7 */
/* @0x2b48fc blx r3 */
/* @0x2b4900 cmp r0, #0 */
/* @0x2b4904 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4908 ldr r5, [r11] */
/* @0x2b490c ldr r4, [r11, #0x4] */
/* @0x2b4910 ldrb r2, [r5] */
/* @0x2b4914 mov r1, #1 */
/* @0x2b4918 ldr r3, [r7] */
/* @0x2b491c mov r12, #80 */
/* @0x2b4920 mov r0, r7 */
/* @0x2b4924 sub r4, r4, #1 */
/* @0x2b4928 str r2, [sp, #0x4] */
/* @0x2b492c add r5, r5, #1 */
/* @0x2b4930 str r2, [r3, #0x18] */
/* @0x2b4934 add r10, sp, #24 */
/* @0x2b4938 str r2, [sp, #0x10] */
/* @0x2b493c mov r8, #0 */
/* @0x2b4940 ldr r2, [r7] */
/* @0x2b4944 str r12, [r3, #0x14] */
/* @0x2b4948 ldr r3, [r2, #0x4] */
/* @0x2b494c blx r3 */
/* @0x2b4950 mov r1, #0 */
/* @0x2b4954 strb r1, [sp, #0x18] */
/* @0x2b4958 b 0x2b4978 <jinit_input_controller+0xa98> */
/* @0x2b495c ldrb r3, [r5] */
/* @0x2b4960 sub r4, r4, #1 */
/* @0x2b4964 add r5, r5, #1 */
/* @0x2b4968 add r8, r8, r3 */
/* @0x2b496c strb r3, [r10, #0x1]! */
/* @0x2b4970 cmp r10, r9 */
/* @0x2b4974 beq 0x2b49a0 <jinit_input_controller+0xac0> */
/* @0x2b4978 cmp r4, #0 */
/* @0x2b497c bne 0x2b495c <jinit_input_controller+0xa7c> */
/* @0x2b4980 ldr r3, [r11, #0xc] */
/* @0x2b4984 mov r0, r7 */
/* @0x2b4988 blx r3 */
/* @0x2b498c cmp r0, #0 */
/* @0x2b4990 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4994 ldr r5, [r11] */
/* @0x2b4998 ldr r4, [r11, #0x4] */
/* @0x2b499c b 0x2b495c <jinit_input_controller+0xa7c> */
/* @0x2b49a0 ldr r2, [r7] */
/* @0x2b49a4 mov r0, r7 */
/* @0x2b49a8 ldrb r12, [sp, #0x1a] */
/* @0x2b49ac mov r1, #2 */
/* @0x2b49b0 ldrb lr, [sp, #0x19] */
/* @0x2b49b4 ldrb r10, [sp, #0x1b] */
/* @0x2b49b8 str r12, [r2, #0x1c] */
/* @0x2b49bc ldrb r12, [sp, #0x1c] */
/* @0x2b49c0 str lr, [r2, #0x18] */
/* @0x2b49c4 ldrb lr, [sp, #0x1d] */
/* @0x2b49c8 str r12, [r2, #0x24] */
/* @0x2b49cc ldrb r12, [sp, #0x1e] */
/* @0x2b49d0 str lr, [r2, #0x28] */
/* @0x2b49d4 ldrb lr, [sp, #0x1f] */
/* @0x2b49d8 str r12, [r2, #0x2c] */
/* @0x2b49dc ldrb r12, [sp, #0x20] */
/* @0x2b49e0 ldr r3, [sp] */
/* @0x2b49e4 str r10, [r2, #0x20] */
/* @0x2b49e8 str lr, [r2, #0x30] */
/* @0x2b49ec sub r3, r3, #17 */
/* @0x2b49f0 str r12, [r2, #0x34] */
/* @0x2b49f4 str r3, [sp] */
/* @0x2b49f8 mov r3, #86 */
/* @0x2b49fc str r3, [r2, #0x14] */
/* @0x2b4a00 ldr r2, [r2, #0x4] */
/* @0x2b4a04 blx r2 */
/* @0x2b4a08 ldr r2, [r7] */
/* @0x2b4a0c ldrb lr, [sp, #0x22] */
/* @0x2b4a10 mov r3, #86 */
/* @0x2b4a14 ldrb r12, [sp, #0x23] */
/* @0x2b4a18 mov r0, r7 */
/* @0x2b4a1c ldrb r10, [sp, #0x21] */
/* @0x2b4a20 mov r1, #2 */
/* @0x2b4a24 str lr, [r2, #0x1c] */
/* @0x2b4a28 ldrb lr, [sp, #0x24] */
/* @0x2b4a2c str r12, [r2, #0x20] */
/* @0x2b4a30 ldrb r12, [sp, #0x25] */
/* @0x2b4a34 str lr, [r2, #0x24] */
/* @0x2b4a38 ldrb lr, [sp, #0x26] */
/* @0x2b4a3c str r12, [r2, #0x28] */
/* @0x2b4a40 ldrb r12, [sp, #0x27] */
/* @0x2b4a44 str lr, [r2, #0x2c] */
/* @0x2b4a48 ldrb lr, [sp, #0x28] */
/* @0x2b4a4c str r12, [r2, #0x30] */
/* @0x2b4a50 str r3, [r2, #0x14] */
/* @0x2b4a54 str r10, [r2, #0x18] */
/* @0x2b4a58 str lr, [r2, #0x34] */
/* @0x2b4a5c ldr r2, [r2, #0x4] */
/* @0x2b4a60 blx r2 */
/* @0x2b4a64 ldr r12, [sp] */
/* @0x2b4a68 cmp r8, #256 */
/* @0x2b4a6c cmple r8, r12 */
/* @0x2b4a70 bgt 0x2b4ba4 <jinit_input_controller+0xcc4> */
/* @0x2b4a74 cmp r8, #0 */
/* @0x2b4a78 add r12, sp, #44 */
/* @0x2b4a7c str r12, [sp, #0xc] */
/* @0x2b4a80 beq 0x2b4ad0 <jinit_input_controller+0xbf0> */
/* @0x2b4a84 add r6, sp, #43 */
/* @0x2b4a88 add r10, r6, r8 */
/* @0x2b4a8c b 0x2b4aa8 <jinit_input_controller+0xbc8> */
/* @0x2b4a90 ldrb r3, [r5] */
/* @0x2b4a94 sub r4, r4, #1 */
/* @0x2b4a98 add r5, r5, #1 */
/* @0x2b4a9c strb r3, [r6, #0x1]! */
/* @0x2b4aa0 cmp r6, r10 */
/* @0x2b4aa4 beq 0x2b4ad0 <jinit_input_controller+0xbf0> */
/* @0x2b4aa8 cmp r4, #0 */
/* @0x2b4aac bne 0x2b4a90 <jinit_input_controller+0xbb0> */
/* @0x2b4ab0 ldr r3, [r11, #0xc] */
/* @0x2b4ab4 mov r0, r7 */
/* @0x2b4ab8 blx r3 */
/* @0x2b4abc cmp r0, #0 */
/* @0x2b4ac0 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4ac4 ldr r5, [r11] */
/* @0x2b4ac8 ldr r4, [r11, #0x4] */
/* @0x2b4acc b 0x2b4a90 <jinit_input_controller+0xbb0> */
/* @0x2b4ad0 ldr r2, [sp, #0x4] */
/* @0x2b4ad4 ldr r3, [sp] */
/* @0x2b4ad8 tst r2, #16 */
/* @0x2b4adc rsb r8, r8, r3 */
/* @0x2b4ae0 addne r3, r2, #28 */
/* @0x2b4ae4 ldreq r2, [sp, #0x4] */
/* @0x2b4ae8 subne r12, r2, #16 */
/* @0x2b4aec addne r6, r7, r3, lsl #2 */
/* @0x2b4af0 strne r12, [sp, #0x10] */
/* @0x2b4af4 addeq r6, r2, #40 */
/* @0x2b4af8 ldr r3, [sp, #0x10] */
/* @0x2b4afc str r8, [sp] */
/* @0x2b4b00 addeq r6, r7, r6, lsl #2 */
/* @0x2b4b04 cmp r3, #3 */
/* @0x2b4b08 bhi 0x2b4bc0 <jinit_input_controller+0xce0> */
/* @0x2b4b0c ldr lr, [r6] */
/* @0x2b4b10 cmp lr, #0 */
/* @0x2b4b14 beq 0x2b4c14 <jinit_input_controller+0xd34> */
/* @0x2b4b18 add r12, sp, #24 */
/* @0x2b4b1c ldm r12!, {r0, r1, r2, r3} */
/* @0x2b4b20 ldrb r12, [r12] */
/* @0x2b4b24 str r1, [lr, #0x4] */
/* @0x2b4b28 str r2, [lr, #0x8] */
/* @0x2b4b2c mov r2, #256 */
/* @0x2b4b30 strb r12, [lr, #0x10] */
/* @0x2b4b34 str r0, [lr] */
/* @0x2b4b38 str r3, [lr, #0xc] */
/* @0x2b4b3c ldr r0, [r6] */
/* @0x2b4b40 ldr r1, [sp, #0xc] */
/* @0x2b4b44 add r0, r0, #17 */
/* @0x2b4b48 bl 0xb65bc <memcpy@plt> */
/* @0x2b4b4c ldr r12, [sp] */
/* @0x2b4b50 cmp r12, #16 */
/* @0x2b4b54 bgt 0x2b48ec <jinit_input_controller+0xa0c> */
/* @0x2b4b58 ldr r12, [sp] */
/* @0x2b4b5c cmp r12, #0 */
/* @0x2b4b60 bne 0x2b4c28 <jinit_input_controller+0xd48> */
/* @0x2b4b64 mov r0, #1 */
/* @0x2b4b68 str r5, [r11] */
/* @0x2b4b6c str r4, [r11, #0x4] */
/* @0x2b4b70 b 0x2b4b88 <jinit_input_controller+0xca8> */
/* @0x2b4b74 ldr r3, [r11, #0xc] */
/* @0x2b4b78 blx r3 */
/* @0x2b4b7c cmp r0, #0 */
/* @0x2b4b80 bne 0x2b4c08 <jinit_input_controller+0xd28> */
/* @0x2b4b84 mov r0, #0 */
/* @0x2b4b88 ldr r12, [sp, #0x8] */
/* @0x2b4b8c ldr r2, [sp, #0x12c] */
/* @0x2b4b90 ldr r3, [r12] */
/* @0x2b4b94 cmp r2, r3 */
/* @0x2b4b98 bne 0x2b4c44 <jinit_input_controller+0xd64> */
/* @0x2b4b9c add sp, sp, #308 */
/* @0x2b4ba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 唯一出口 pop {r4..r11,pc} */
/* @0x2b4ba4 ldr r2, [r7] */
/* @0x2b4ba8 mov r1, #8 */
/* @0x2b4bac mov r0, r7 */
/* @0x2b4bb0 str r1, [r2, #0x14] */
/* @0x2b4bb4 ldr r2, [r2] */
/* @0x2b4bb8 blx r2 */
/* @0x2b4bbc b 0x2b4a74 <jinit_input_controller+0xb94> */
/* @0x2b4bc0 ldr r3, [r7] */
/* @0x2b4bc4 mov r1, #30 */
/* @0x2b4bc8 ldr r12, [sp, #0x10] */
/* @0x2b4bcc mov r0, r7 */
/* @0x2b4bd0 str r12, [r3, #0x18] */
/* @0x2b4bd4 ldr r2, [r7] */
/* @0x2b4bd8 str r1, [r3, #0x14] */
/* @0x2b4bdc ldr r3, [r2] */
/* @0x2b4be0 blx r3 */
/* @0x2b4be4 b 0x2b4b0c <jinit_input_controller+0xc2c> */
/* @0x2b4be8 ldr r3, [r11, #0xc] */
/* @0x2b4bec mov r0, r7 */
/* @0x2b4bf0 blx r3 */
/* @0x2b4bf4 cmp r0, #0 */
/* @0x2b4bf8 beq 0x2b4b84 <jinit_input_controller+0xca4> */
/* @0x2b4bfc ldr r5, [r11] */
/* @0x2b4c00 ldr r4, [r11, #0x4] */
/* @0x2b4c04 b 0x2b48c0 <jinit_input_controller+0x9e0> */
/* @0x2b4c08 ldr r5, [r11] */
/* @0x2b4c0c ldr r4, [r11, #0x4] */
/* @0x2b4c10 b 0x2b48ac <jinit_input_controller+0x9cc> */
/* @0x2b4c14 mov r0, r7 */
/* @0x2b4c18 bl 0x2bc908 <jpeg_alloc_huff_table> —— bl jpeg_alloc_huff_table —— 全库唯一调用点，DHT 的身份锚 */
/* @0x2b4c1c mov lr, r0 */
/* @0x2b4c20 str r0, [r6] */
/* @0x2b4c24 b 0x2b4b18 <jinit_input_controller+0xc38> */
/* @0x2b4c28 ldr r3, [r7] */
/* @0x2b4c2c mov r1, #11 */
/* @0x2b4c30 mov r0, r7 */
/* @0x2b4c34 ldr r2, [r3] */
/* @0x2b4c38 str r1, [r3, #0x14] */
/* @0x2b4c3c blx r2 */
/* @0x2b4c40 b 0x2b4b64 <jinit_input_controller+0xc84> */
/* @0x2b4c44 bl 0xb65d4 <__stack_chk_fail@plt> —— bl __stack_chk_fail（canary 失败路径） */
/* @0x2b4c48 andseq r9, r3, r4, asr #1 */
/* @0x2b4c4c ldr r3, [r0, #0x17c] */
/* ═══════════════════════════════════════════════════════════════════════
 * §3  anon_2b4c50 = jdmarker.c read_markers（标记分派主循环）
 * ═══════════════════════════════════════════════════════════════════════
 * 契约：int read_markers(j_decompress_ptr cinfo)——r0 = cinfo，返回 0/1/2（与 §1 同一套码）；
 *       逐个读标记、按 unread_marker 分派给 jdmarker.c 的静态处理器，遇到 SOS/EOI 收尾。
 *
 * 身份证据（三条）
 *   ① 安装点：jinit_marker_reader(0x2b5efc) 的 0x2b5f54 `str r8,[r0,#0x4]`，r8 由
 *      0x2b5f28 的池字 0xffffed04 经 `add r8,pc,r8`（pc=0x2b5f48）算出 = 0x2b4c4c
 *      ⇒ jpeg_marker_reader 槽 #1 read_markers。同函数 0x2b5f50 写槽 #0（0x2b4850，
 *      reset_marker_reader，40 B）、0x2b5f58 写槽 #2（0x2b5cf4，read_restart_marker，164 B）。
 *   ② 入口形态：真入口 0x2b4c4c（本段起点晚 4 B）读 cinfo+0x17c = unread_marker
 *      （jinit_marker_reader 在 0x2b5f90 把它清零，同一偏移）；0x2b4c74 读 cinfo+0x18 =
 *      cinfo->src，0x2b4c78/0x2b4c7c 取 src->bytes_in_buffer / src->next_input_byte，
 *      0x2b4ca4 比较 0xFF 与 0xD8 —— GCC 把 LOCAL 的 next_marker 内联进了入口。
 *   ③ 调用面全是 jdmarker.c 的段处理器：3×0x2b3f58、1×0x2b46e0、1×0x2b4604、
 *      1×0x2b4878（§2 get_dht）、1×jpeg_alloc_quant_table（DQT）。
 *
 * 它调谁：0x2b3f58 ×3（已由 anon_batch2 卡片覆盖）/ 0x2b46e0 ×1 / 0x2b4604 ×1 /
 *         get_dht ×1 / jpeg_alloc_quant_table(0x2bc8e4) ×1
 * 谁调它：① §1 consume_markers 经 [marker+0x4] blx；② 0 处直接 bl。
 * 边界：单函数，3 个 pop 出口（0x2b50c4 / 0x2b50e4 / 0x2b55e0）；0x2b57a8 无条件 b 之后
 *       0x2b57ac 是池字（andseq），不是指令。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b4c50 0x2b57b0 anon_2b4c50 read_markers */

/* @0x2b4c50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（9 寄存器 + 12 B 帧） */
/* @0x2b4c54 cmp r3, #0 */
/* @0x2b4c58 sub sp, sp, #12 */
/* @0x2b4c5c mov r11, r0 */
/* @0x2b4c60 bne 0x2b4cc0 <jinit_input_controller+0xde0> */
/* @0x2b4c64 ldr r3, [r11, #0x194] —— cinfo+0x194 = cinfo->marker */
/* @0x2b4c68 ldrb r3, [r3, #0xc] —— marker+0xc 的 1 字节 */
/* @0x2b4c6c cmp r3, #0 */
/* @0x2b4c70 bne 0x2b4e14 <jinit_input_controller+0xf34> */
/* @0x2b4c74 ldr r4, [r11, #0x18] —— cinfo+0x18 = cinfo->src */
/* @0x2b4c78 ldr r3, [r4, #0x4] —— src->bytes_in_buffer */
/* @0x2b4c7c ldr r7, [r4] —— src->next_input_byte */
/* @0x2b4c80 cmp r3, #0 */
/* @0x2b4c84 beq 0x2b50c8 <jinit_input_controller+0x11e8> */
/* @0x2b4c88 subs r3, r3, #1 */
/* @0x2b4c8c ldrb r9, [r7] */
/* @0x2b4c90 addne r7, r7, #1 */
/* @0x2b4c94 beq 0x2b5178 <jinit_input_controller+0x1298> */
/* @0x2b4c98 ldrb r5, [r7] */
/* @0x2b4c9c sub r6, r3, #1 */
/* @0x2b4ca0 add r7, r7, #1 */
/* @0x2b4ca4 cmp r9, #255 —— cmp 0xFF + cmp 0xD8（SOI）：内联的 next_marker 扫描 */
/* @0x2b4ca8 cmpeq r5, #216 */
/* @0x2b4cac bne 0x2b55e4 <jinit_input_controller+0x1704> */
/* @0x2b4cb0 mov r3, r5 */
/* @0x2b4cb4 str r5, [r11, #0x17c] —— cinfo+0x17c = unread_marker */
/* @0x2b4cb8 str r7, [r4] */
/* @0x2b4cbc str r6, [r4, #0x4] */
/* @0x2b4cc0 cmp r3, #207 */
/* @0x2b4cc4 ble 0x2b4db8 <jinit_input_controller+0xed8> */
/* @0x2b4cc8 cmp r3, #219 */
/* @0x2b4ccc beq 0x2b52a8 <jinit_input_controller+0x13c8> */
/* @0x2b4cd0 ble 0x2b4e2c <jinit_input_controller+0xf4c> */
/* @0x2b4cd4 cmp r3, #239 */
/* @0x2b4cd8 bgt 0x2b5210 <jinit_input_controller+0x1330> */
/* @0x2b4cdc cmp r3, #224 */
/* @0x2b4ce0 bge 0x2b5234 <jinit_input_controller+0x1354> */
/* @0x2b4ce4 cmp r3, #220 */
/* @0x2b4ce8 beq 0x2b5128 <jinit_input_controller+0x1248> */
/* @0x2b4cec cmp r3, #221 */
/* @0x2b4cf0 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b4cf4 ldr r4, [r11, #0x18] */
/* @0x2b4cf8 ldm r4, {r2, r3} */
/* @0x2b4cfc cmp r3, #0 */
/* @0x2b4d00 beq 0x2b56ac <jinit_input_controller+0x17cc> */
/* @0x2b4d04 ldrb r6, [r2] */
/* @0x2b4d08 subs r3, r3, #1 */
/* @0x2b4d0c addne r5, r2, #1 */
/* @0x2b4d10 lsl r6, r6, #8 */
/* @0x2b4d14 beq 0x2b5708 <jinit_input_controller+0x1828> */
/* @0x2b4d18 ldrb r2, [r5] */
/* @0x2b4d1c sub r7, r3, #1 */
/* @0x2b4d20 add r6, r6, r2 */
/* @0x2b4d24 cmp r6, #4 */
/* @0x2b4d28 beq 0x2b4d44 <jinit_input_controller+0xe64> */
/* @0x2b4d2c ldr r3, [r11] */
/* @0x2b4d30 mov lr, #11 */
/* @0x2b4d34 mov r0, r11 */
/* @0x2b4d38 str lr, [r3, #0x14] */
/* @0x2b4d3c ldr r3, [r3] */
/* @0x2b4d40 blx r3 */
/* @0x2b4d44 cmp r7, #0 */
/* @0x2b4d48 addne r5, r5, #1 */
/* @0x2b4d4c beq 0x2b5744 <jinit_input_controller+0x1864> */
/* @0x2b4d50 ldrb r6, [r5] */
/* @0x2b4d54 subs r7, r7, #1 */
/* @0x2b4d58 addne r5, r5, #1 */
/* @0x2b4d5c lsl r6, r6, #8 */
/* @0x2b4d60 bne 0x2b4d7c <jinit_input_controller+0xe9c> */
/* @0x2b4d64 ldr r3, [r4, #0xc] */
/* @0x2b4d68 mov r0, r11 */
/* @0x2b4d6c blx r3 */
/* @0x2b4d70 cmp r0, #0 */
/* @0x2b4d74 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4d78 ldm r4, {r5, r7} */
/* @0x2b4d7c ldr r3, [r11] */
/* @0x2b4d80 mov r1, #82 */
/* @0x2b4d84 ldrb r2, [r5], #1 */
/* @0x2b4d88 mov r0, r11 */
/* @0x2b4d8c sub r7, r7, #1 */
/* @0x2b4d90 add r6, r2, r6 */
/* @0x2b4d94 str r6, [r3, #0x18] */
/* @0x2b4d98 ldr r2, [r11] */
/* @0x2b4d9c str r1, [r3, #0x14] */
/* @0x2b4da0 mov r1, #1 */
/* @0x2b4da4 ldr r3, [r2, #0x4] */
/* @0x2b4da8 blx r3 */
/* @0x2b4dac str r6, [r11, #0xfc] */
/* @0x2b4db0 stm r4, {r5, r7} */
/* @0x2b4db4 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b4db8 cmp r3, #205 */
/* @0x2b4dbc bge 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4dc0 cmp r3, #196 */
/* @0x2b4dc4 beq 0x2b5294 <jinit_input_controller+0x13b4> */
/* @0x2b4dc8 ble 0x2b50e8 <jinit_input_controller+0x1208> */
/* @0x2b4dcc cmp r3, #201 */
/* @0x2b4dd0 beq 0x2b5278 <jinit_input_controller+0x1398> */
/* @0x2b4dd4 blt 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4dd8 cmp r3, #203 */
/* @0x2b4ddc beq 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b4de0 movle r1, #1 */
/* @0x2b4de4 bgt 0x2b5128 <jinit_input_controller+0x1248> */
/* @0x2b4de8 mov r0, r11 */
/* @0x2b4dec mov r2, r1 */
/* @0x2b4df0 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b4df4 cmp r0, #0 */
/* @0x2b4df8 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4dfc mov r3, #0 */
/* @0x2b4e00 str r3, [r11, #0x17c] */
/* @0x2b4e04 ldr r3, [r11, #0x194] */
/* @0x2b4e08 ldrb r3, [r3, #0xc] */
/* @0x2b4e0c cmp r3, #0 */
/* @0x2b4e10 beq 0x2b4c74 <jinit_input_controller+0xd94> */
/* @0x2b4e14 mov r0, r11 */
/* @0x2b4e18 bl 0x2b46e0 <jinit_input_controller+0x800> */
/* @0x2b4e1c cmp r0, #0 */
/* @0x2b4e20 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4e24 ldr r3, [r11, #0x17c] */
/* @0x2b4e28 b 0x2b4cc0 <jinit_input_controller+0xde0> */
/* @0x2b4e2c cmp r3, #216 */
/* @0x2b4e30 beq 0x2b5514 <jinit_input_controller+0x1634> */
/* @0x2b4e34 blt 0x2b5100 <jinit_input_controller+0x1220> */
/* @0x2b4e38 cmp r3, #217 */
/* @0x2b4e3c beq 0x2b55b4 <jinit_input_controller+0x16d4> */
/* @0x2b4e40 cmp r3, #218 */
/* @0x2b4e44 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b4e48 ldr r3, [r11, #0x194] */
/* @0x2b4e4c ldr r8, [r11, #0x18] */
/* @0x2b4e50 ldrb r3, [r3, #0xd] */
/* @0x2b4e54 ldr r5, [r8] */
/* @0x2b4e58 cmp r3, #0 */
/* @0x2b4e5c ldr r4, [r8, #0x4] */
/* @0x2b4e60 beq 0x2b5674 <jinit_input_controller+0x1794> */
/* @0x2b4e64 cmp r4, #0 */
/* @0x2b4e68 beq 0x2b5654 <jinit_input_controller+0x1774> */
/* @0x2b4e6c ldrb r3, [r5] */
/* @0x2b4e70 subs r4, r4, #1 */
/* @0x2b4e74 addne r5, r5, #1 */
/* @0x2b4e78 lsl r6, r3, #8 */
/* @0x2b4e7c beq 0x2b56e8 <jinit_input_controller+0x1808> */
/* @0x2b4e80 ldrb r3, [r5] */
/* @0x2b4e84 subs r12, r4, #1 */
/* @0x2b4e88 addne r5, r5, #1 */
/* @0x2b4e8c add r6, r6, r3 */
/* @0x2b4e90 bne 0x2b4eac <jinit_input_controller+0xfcc> */
/* @0x2b4e94 ldr r3, [r8, #0xc] */
/* @0x2b4e98 mov r0, r11 */
/* @0x2b4e9c blx r3 */
/* @0x2b4ea0 cmp r0, #0 */
/* @0x2b4ea4 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b4ea8 ldm r8, {r5, r12} */
/* @0x2b4eac ldrb r10, [r5] */
/* @0x2b4eb0 mov lr, #103 */
/* @0x2b4eb4 ldr r3, [r11] */
/* @0x2b4eb8 mov r1, #1 */
/* @0x2b4ebc mov r0, r11 */
/* @0x2b4ec0 sub r9, r12, #1 */
/* @0x2b4ec4 add r5, r5, r1 */
/* @0x2b4ec8 str r10, [r3, #0x18] */
/* @0x2b4ecc ldr r2, [r11] */
/* @0x2b4ed0 str lr, [r3, #0x14] */
/* @0x2b4ed4 ldr r3, [r2, #0x4] */
/* @0x2b4ed8 blx r3 */
/* @0x2b4edc add r3, r10, #3 */
/* @0x2b4ee0 cmp r6, r3, lsl #1 */
/* @0x2b4ee4 beq 0x2b5644 <jinit_input_controller+0x1764> */
/* @0x2b4ee8 ldr r3, [r11] */
/* @0x2b4eec mov r2, #11 */
/* @0x2b4ef0 mov r0, r11 */
/* @0x2b4ef4 str r2, [r3, #0x14] */
/* @0x2b4ef8 ldr r3, [r3] */
/* @0x2b4efc blx r3 */
/* @0x2b4f00 cmp r10, #0 */
/* @0x2b4f04 str r10, [r11, #0x124] */
/* @0x2b4f08 beq 0x2b5000 <jinit_input_controller+0x1120> */
/* @0x2b4f0c mov r7, r11 */
/* @0x2b4f10 mov r6, #1 */
/* @0x2b4f14 add r10, r10, #1 */
/* @0x2b4f18 str r10, [sp, #0x4] */
/* @0x2b4f1c cmp r9, #0 */
/* @0x2b4f20 beq 0x2b51cc <jinit_input_controller+0x12ec> */
/* @0x2b4f24 subs r9, r9, #1 */
/* @0x2b4f28 ldrb r10, [r5] */
/* @0x2b4f2c addne r3, r5, #1 */
/* @0x2b4f30 beq 0x2b51f4 <jinit_input_controller+0x1314> */
/* @0x2b4f34 ldr r0, [r11, #0x24] */
/* @0x2b4f38 sub r9, r9, #1 */
/* @0x2b4f3c add r5, r3, #1 */
/* @0x2b4f40 ldrb r1, [r3] */
/* @0x2b4f44 cmp r0, #0 */
/* @0x2b4f48 ldr r4, [r11, #0xc4] */
/* @0x2b4f4c ble 0x2b4f80 <jinit_input_controller+0x10a0> */
/* @0x2b4f50 ldr r3, [r4] */
/* @0x2b4f54 cmp r10, r3 */
/* @0x2b4f58 beq 0x2b4fa8 <jinit_input_controller+0x10c8> */
/* @0x2b4f5c mov r3, #0 */
/* @0x2b4f60 b 0x2b4f70 <jinit_input_controller+0x1090> */
/* @0x2b4f64 ldr r2, [r4] */
/* @0x2b4f68 cmp r10, r2 */
/* @0x2b4f6c beq 0x2b4fa8 <jinit_input_controller+0x10c8> */
/* @0x2b4f70 add r3, r3, #1 */
/* @0x2b4f74 add r4, r4, #84 */
/* @0x2b4f78 cmp r3, r0 */
/* @0x2b4f7c bne 0x2b4f64 <jinit_input_controller+0x1084> */
/* @0x2b4f80 ldr r3, [r11] */
/* @0x2b4f84 mov r12, #5 */
/* @0x2b4f88 mov r0, r11 */
/* @0x2b4f8c str r10, [r3, #0x18] */
/* @0x2b4f90 ldr r2, [r11] */
/* @0x2b4f94 str r12, [r3, #0x14] */
/* @0x2b4f98 ldr r3, [r2] */
/* @0x2b4f9c str r1, [sp] */
/* @0x2b4fa0 blx r3 */
/* @0x2b4fa4 ldr r1, [sp] */
/* @0x2b4fa8 str r4, [r7, #0x128] */
/* @0x2b4fac asr r2, r1, #4 */
/* @0x2b4fb0 ldr r3, [r11] */
/* @0x2b4fb4 and r1, r1, #15 */
/* @0x2b4fb8 str r2, [r4, #0x14] */
/* @0x2b4fbc mov r12, #104 */
/* @0x2b4fc0 str r1, [r4, #0x18] */
/* @0x2b4fc4 mov r0, r11 */
/* @0x2b4fc8 str r10, [r3, #0x18] */
/* @0x2b4fcc mov r1, #1 */
/* @0x2b4fd0 ldr lr, [r4, #0x14] */
/* @0x2b4fd4 add r6, r6, #1 */
/* @0x2b4fd8 ldr r2, [r3, #0x4] */
/* @0x2b4fdc add r7, r7, #4 */
/* @0x2b4fe0 str lr, [r3, #0x1c] */
/* @0x2b4fe4 ldr lr, [r4, #0x18] */
/* @0x2b4fe8 str r12, [r3, #0x14] */
/* @0x2b4fec str lr, [r3, #0x20] */
/* @0x2b4ff0 blx r2 */
/* @0x2b4ff4 ldr r2, [sp, #0x4] */
/* @0x2b4ff8 cmp r6, r2 */
/* @0x2b4ffc bne 0x2b4f1c <jinit_input_controller+0x103c> */
/* @0x2b5000 cmp r9, #0 */
/* @0x2b5004 beq 0x2b5774 <jinit_input_controller+0x1894> */
/* @0x2b5008 ldrb r3, [r5] */
/* @0x2b500c subs r12, r9, #1 */
/* @0x2b5010 addne r5, r5, #1 */
/* @0x2b5014 str r3, [r11, #0x16c] */
/* @0x2b5018 beq 0x2b5790 <jinit_input_controller+0x18b0> */
/* @0x2b501c ldrb r3, [r5] */
/* @0x2b5020 subs r6, r12, #1 */
/* @0x2b5024 addne r4, r5, #1 */
/* @0x2b5028 str r3, [r11, #0x170] */
/* @0x2b502c bne 0x2b5048 <jinit_input_controller+0x1168> */
/* @0x2b5030 ldr r3, [r8, #0xc] */
/* @0x2b5034 mov r0, r11 */
/* @0x2b5038 blx r3 */
/* @0x2b503c cmp r0, #0 */
/* @0x2b5040 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5044 ldm r8, {r4, r6} */
/* @0x2b5048 ldrb r2, [r4], #1 */
/* @0x2b504c mov lr, #105 */
/* @0x2b5050 ldr r3, [r11] */
/* @0x2b5054 mov r0, r11 */
/* @0x2b5058 ldr r1, [r11, #0x16c] */
/* @0x2b505c and r12, r2, #15 */
/* @0x2b5060 asr r2, r2, #4 */
/* @0x2b5064 str r12, [r11, #0x178] */
/* @0x2b5068 str r2, [r11, #0x174] */
/* @0x2b506c sub r6, r6, #1 */
/* @0x2b5070 str r1, [r3, #0x18] */
/* @0x2b5074 mov r1, #1 */
/* @0x2b5078 ldr r12, [r11, #0x170] */
/* @0x2b507c ldr r2, [r3, #0x4] */
/* @0x2b5080 str r12, [r3, #0x1c] */
/* @0x2b5084 ldr r12, [r11, #0x174] */
/* @0x2b5088 str r12, [r3, #0x20] */
/* @0x2b508c ldr r12, [r11, #0x178] */
/* @0x2b5090 str lr, [r3, #0x14] */
/* @0x2b5094 str r12, [r3, #0x24] */
/* @0x2b5098 blx r2 */
/* @0x2b509c ldr r1, [r11, #0x194] */
/* @0x2b50a0 ldr r2, [r11, #0x7c] */
/* @0x2b50a4 mov r3, #0 */
/* @0x2b50a8 mov r0, #1 */
/* @0x2b50ac str r3, [r1, #0x10] */
/* @0x2b50b0 add r2, r2, r0 */
/* @0x2b50b4 str r2, [r11, #0x7c] */
/* @0x2b50b8 stm r8, {r4, r6} */
/* @0x2b50bc str r3, [r11, #0x17c] */
/* @0x2b50c0 add sp, sp, #12 */
/* @0x2b50c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x2b50c8 ldr r3, [r4, #0xc] */
/* @0x2b50cc mov r0, r11 */
/* @0x2b50d0 blx r3 */
/* @0x2b50d4 cmp r0, #0 */
/* @0x2b50d8 bne 0x2b5160 <jinit_input_controller+0x1280> */
/* @0x2b50dc mov r0, #0 */
/* @0x2b50e0 add sp, sp, #12 */
/* @0x2b50e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2b50e8 cmp r3, #193 */
/* @0x2b50ec bgt 0x2b513c <jinit_input_controller+0x125c> */
/* @0x2b50f0 cmp r3, #192 */
/* @0x2b50f4 bge 0x2b5198 <jinit_input_controller+0x12b8> */
/* @0x2b50f8 cmp r3, #1 */
/* @0x2b50fc bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b5100 ldr r2, [r11] */
/* @0x2b5104 mov r12, #92 */
/* @0x2b5108 mov r0, r11 */
/* @0x2b510c mov r1, #1 */
/* @0x2b5110 str r3, [r2, #0x18] */
/* @0x2b5114 ldr r3, [r11] */
/* @0x2b5118 str r12, [r2, #0x14] */
/* @0x2b511c ldr r3, [r3, #0x4] */
/* @0x2b5120 blx r3 */
/* @0x2b5124 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5128 mov r0, r11 */
/* @0x2b512c bl 0x2b4604 <jinit_input_controller+0x724> */
/* @0x2b5130 cmp r0, #0 */
/* @0x2b5134 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5138 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b513c cmp r3, #194 */
/* @0x2b5140 bne 0x2b51a0 <jinit_input_controller+0x12c0> */
/* @0x2b5144 mov r0, r11 */
/* @0x2b5148 mov r1, #1 */
/* @0x2b514c mov r2, #0 */
/* @0x2b5150 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b5154 cmp r0, #0 */
/* @0x2b5158 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b515c b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5160 ldr r3, [r4, #0x4] */
/* @0x2b5164 ldr r7, [r4] */
/* @0x2b5168 subs r3, r3, #1 */
/* @0x2b516c ldrb r9, [r7] */
/* @0x2b5170 addne r7, r7, #1 */
/* @0x2b5174 bne 0x2b4c98 <jinit_input_controller+0xdb8> */
/* @0x2b5178 ldr r3, [r4, #0xc] */
/* @0x2b517c mov r0, r11 */
/* @0x2b5180 blx r3 */
/* @0x2b5184 cmp r0, #0 */
/* @0x2b5188 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b518c ldr r7, [r4] */
/* @0x2b5190 ldr r3, [r4, #0x4] */
/* @0x2b5194 b 0x2b4c98 <jinit_input_controller+0xdb8> */
/* @0x2b5198 mov r1, #0 */
/* @0x2b519c b 0x2b4de8 <jinit_input_controller+0xf08> */
/* @0x2b51a0 cmp r3, #195 */
/* @0x2b51a4 beq 0x2b5254 <jinit_input_controller+0x1374> */
/* @0x2b51a8 ldr r2, [r11] */
/* @0x2b51ac mov lr, #68 */
/* @0x2b51b0 mov r0, r11 */
/* @0x2b51b4 str r3, [r2, #0x18] */
/* @0x2b51b8 ldr r3, [r11] */
/* @0x2b51bc str lr, [r2, #0x14] */
/* @0x2b51c0 ldr r3, [r3] */
/* @0x2b51c4 blx r3 */
/* @0x2b51c8 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b51cc ldr r3, [r8, #0xc] */
/* @0x2b51d0 mov r0, r11 */
/* @0x2b51d4 blx r3 */
/* @0x2b51d8 cmp r0, #0 */
/* @0x2b51dc beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b51e0 ldm r8, {r5, r9} */
/* @0x2b51e4 subs r9, r9, #1 */
/* @0x2b51e8 ldrb r10, [r5] */
/* @0x2b51ec addne r3, r5, #1 */
/* @0x2b51f0 bne 0x2b4f34 <jinit_input_controller+0x1054> */
/* @0x2b51f4 ldr r3, [r8, #0xc] */
/* @0x2b51f8 mov r0, r11 */
/* @0x2b51fc blx r3 */
/* @0x2b5200 cmp r0, #0 */
/* @0x2b5204 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5208 ldm r8, {r3, r9} */
/* @0x2b520c b 0x2b4f34 <jinit_input_controller+0x1054> */
/* @0x2b5210 cmp r3, #254 */
/* @0x2b5214 bne 0x2b51a8 <jinit_input_controller+0x12c8> */
/* @0x2b5218 ldr r3, [r11, #0x194] */
/* @0x2b521c mov r0, r11 */
/* @0x2b5220 ldr r3, [r3, #0x18] */
/* @0x2b5224 blx r3 */
/* @0x2b5228 cmp r0, #0 */
/* @0x2b522c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5230 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5234 ldr r2, [r11, #0x194] */
/* @0x2b5238 mov r0, r11 */
/* @0x2b523c add r3, r2, r3, lsl #2 */
/* @0x2b5240 ldr r3, [r3, #-0x364] */
/* @0x2b5244 blx r3 */
/* @0x2b5248 cmp r0, #0 */
/* @0x2b524c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5250 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5254 ldr r2, [r11] */
/* @0x2b5258 mov r1, #60 */
/* @0x2b525c mov r0, r11 */
/* @0x2b5260 str r3, [r2, #0x18] */
/* @0x2b5264 ldr r3, [r11] */
/* @0x2b5268 str r1, [r2, #0x14] */
/* @0x2b526c ldr r3, [r3] */
/* @0x2b5270 blx r3 */
/* @0x2b5274 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5278 mov r0, r11 */
/* @0x2b527c mov r1, #0 */
/* @0x2b5280 mov r2, #1 */
/* @0x2b5284 bl 0x2b3f58 <jinit_input_controller+0x78> */
/* @0x2b5288 cmp r0, #0 */
/* @0x2b528c bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5290 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5294 mov r0, r11 */
/* @0x2b5298 bl 0x2b4878 <jinit_input_controller+0x998> —— bl 0x2b4878 = get_dht（§2） */
/* @0x2b529c cmp r0, #0 */
/* @0x2b52a0 bne 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b52a4 b 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b52a8 ldr r6, [r11, #0x18] */
/* @0x2b52ac ldm r6, {r2, r3} */
/* @0x2b52b0 cmp r3, #0 */
/* @0x2b52b4 beq 0x2b5690 <jinit_input_controller+0x17b0> */
/* @0x2b52b8 ldrb r7, [r2] */
/* @0x2b52bc subs r3, r3, #1 */
/* @0x2b52c0 addne r2, r2, #1 */
/* @0x2b52c4 lsl r7, r7, #8 */
/* @0x2b52c8 beq 0x2b5728 <jinit_input_controller+0x1848> */
/* @0x2b52cc ldrb r1, [r2] */
/* @0x2b52d0 sub r4, r3, #1 */
/* @0x2b52d4 add r5, r2, #1 */
/* @0x2b52d8 add r7, r7, r1 */
/* @0x2b52dc sub r7, r7, #2 */
/* @0x2b52e0 str r7, [sp, #0x4] */
/* @0x2b52e4 cmp r7, #0 */
/* @0x2b52e8 ble 0x2b54e4 <jinit_input_controller+0x1604> */
/* @0x2b52ec cmp r4, #0 */
/* @0x2b52f0 bne 0x2b5310 <jinit_input_controller+0x1430> */
/* @0x2b52f4 ldr r3, [r6, #0xc] */
/* @0x2b52f8 mov r0, r11 */
/* @0x2b52fc blx r3 */
/* @0x2b5300 cmp r0, #0 */
/* @0x2b5304 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5308 ldr r5, [r6] */
/* @0x2b530c ldr r4, [r6, #0x4] */
/* @0x2b5310 ldr r3, [r11] */
/* @0x2b5314 mov r12, #81 */
/* @0x2b5318 ldrb r8, [r5] */
/* @0x2b531c mov r1, #1 */
/* @0x2b5320 mov r0, r11 */
/* @0x2b5324 add r5, r5, r1 */
/* @0x2b5328 and r7, r8, #15 */
/* @0x2b532c str r7, [r3, #0x18] */
/* @0x2b5330 ldr r2, [r11] */
/* @0x2b5334 asr r8, r8, #4 */
/* @0x2b5338 str r12, [r3, #0x14] */
/* @0x2b533c sub r4, r4, #1 */
/* @0x2b5340 str r8, [r2, #0x1c] */
/* @0x2b5344 ldr r3, [r11] */
/* @0x2b5348 ldr r3, [r3, #0x4] */
/* @0x2b534c blx r3 */
/* @0x2b5350 cmp r7, #3 */
/* @0x2b5354 bgt 0x2b5620 <jinit_input_controller+0x1740> */
/* @0x2b5358 add r7, r11, r7, lsl #2 */
/* @0x2b535c ldr r10, [r7, #0x90] */
/* @0x2b5360 cmp r10, #0 */
/* @0x2b5364 beq 0x2b5760 <jinit_input_controller+0x1880> */
/* @0x2b5368 ldr r1, [pc, #0x43c] */
/* @0x2b536c ldr r1, [pc, r1] */
/* @0x2b5370 sub r7, r1, #4 */
/* @0x2b5374 add r9, r1, #252 */
/* @0x2b5378 b 0x2b53bc <jinit_input_controller+0x14dc> */
/* @0x2b537c cmp r4, #0 */
/* @0x2b5380 beq 0x2b53dc <jinit_input_controller+0x14fc> */
/* @0x2b5384 ldrb r2, [r5] */
/* @0x2b5388 subs r4, r4, #1 */
/* @0x2b538c addne r5, r5, #1 */
/* @0x2b5390 lsl r2, r2, #8 */
/* @0x2b5394 beq 0x2b541c <jinit_input_controller+0x153c> */
/* @0x2b5398 ldrb r3, [r5] */
/* @0x2b539c sub r4, r4, #1 */
/* @0x2b53a0 add r5, r5, #1 */
/* @0x2b53a4 add r2, r3, r2 */
/* @0x2b53a8 ldr r3, [r7, #0x4]! */
/* @0x2b53ac cmp r7, r9 */
/* @0x2b53b0 lsl r3, r3, #1 */
/* @0x2b53b4 strh r2, [r10, r3] */
/* @0x2b53b8 beq 0x2b5444 <jinit_input_controller+0x1564> */
/* @0x2b53bc cmp r8, #0 */
/* @0x2b53c0 bne 0x2b537c <jinit_input_controller+0x149c> */
/* @0x2b53c4 cmp r4, #0 */
/* @0x2b53c8 beq 0x2b53fc <jinit_input_controller+0x151c> */
/* @0x2b53cc ldrb r2, [r5] */
/* @0x2b53d0 sub r4, r4, #1 */
/* @0x2b53d4 add r5, r5, #1 */
/* @0x2b53d8 b 0x2b53a8 <jinit_input_controller+0x14c8> */
/* @0x2b53dc ldr r3, [r6, #0xc] */
/* @0x2b53e0 mov r0, r11 */
/* @0x2b53e4 blx r3 */
/* @0x2b53e8 cmp r0, #0 */
/* @0x2b53ec beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b53f0 ldr r5, [r6] */
/* @0x2b53f4 ldr r4, [r6, #0x4] */
/* @0x2b53f8 b 0x2b5384 <jinit_input_controller+0x14a4> */
/* @0x2b53fc ldr r3, [r6, #0xc] */
/* @0x2b5400 mov r0, r11 */
/* @0x2b5404 blx r3 */
/* @0x2b5408 cmp r0, #0 */
/* @0x2b540c beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5410 ldr r5, [r6] */
/* @0x2b5414 ldr r4, [r6, #0x4] */
/* @0x2b5418 b 0x2b53cc <jinit_input_controller+0x14ec> */
/* @0x2b541c ldr r3, [r6, #0xc] */
/* @0x2b5420 mov r0, r11 */
/* @0x2b5424 str r2, [sp] */
/* @0x2b5428 blx r3 */
/* @0x2b542c ldr r2, [sp] */
/* @0x2b5430 cmp r0, #0 */
/* @0x2b5434 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5438 ldr r5, [r6] */
/* @0x2b543c ldr r4, [r6, #0x4] */
/* @0x2b5440 b 0x2b5398 <jinit_input_controller+0x14b8> */
/* @0x2b5444 ldr r3, [r11] */
/* @0x2b5448 ldr r2, [r3, #0x68] */
/* @0x2b544c cmp r2, #1 */
/* @0x2b5450 movgt r7, #8 */
/* @0x2b5454 bgt 0x2b5460 <jinit_input_controller+0x1580> */
/* @0x2b5458 b 0x2b54c4 <jinit_input_controller+0x15e4> */
/* @0x2b545c ldr r3, [r11] */
/* @0x2b5460 ldrh r12, [r10] */
/* @0x2b5464 mov lr, #93 */
/* @0x2b5468 mov r0, r11 */
/* @0x2b546c ldr r2, [r3, #0x4] */
/* @0x2b5470 mov r1, #2 */
/* @0x2b5474 add r10, r10, #16 */
/* @0x2b5478 str r12, [r3, #0x18] */
/* @0x2b547c ldrh r12, [r10, #-14] */
/* @0x2b5480 str r12, [r3, #0x1c] */
/* @0x2b5484 ldrh r12, [r10, #-12] */
/* @0x2b5488 str r12, [r3, #0x20] */
/* @0x2b548c ldrh r12, [r10, #-10] */
/* @0x2b5490 str r12, [r3, #0x24] */
/* @0x2b5494 ldrh r12, [r10, #-8] */
/* @0x2b5498 str r12, [r3, #0x28] */
/* @0x2b549c ldrh r12, [r10, #-6] */
/* @0x2b54a0 str r12, [r3, #0x2c] */
/* @0x2b54a4 ldrh r12, [r10, #-4] */
/* @0x2b54a8 str r12, [r3, #0x30] */
/* @0x2b54ac ldrh r12, [r10, #-2] */
/* @0x2b54b0 str lr, [r3, #0x14] */
/* @0x2b54b4 str r12, [r3, #0x34] */
/* @0x2b54b8 blx r2 */
/* @0x2b54bc subs r7, r7, #1 */
/* @0x2b54c0 bne 0x2b545c <jinit_input_controller+0x157c> */
/* @0x2b54c4 cmp r8, #0 */
/* @0x2b54c8 beq 0x2b5610 <jinit_input_controller+0x1730> */
/* @0x2b54cc ldr r3, [sp, #0x4] */
/* @0x2b54d0 sub r3, r3, #129 */
/* @0x2b54d4 str r3, [sp, #0x4] */
/* @0x2b54d8 ldr r12, [sp, #0x4] */
/* @0x2b54dc cmp r12, #0 */
/* @0x2b54e0 bgt 0x2b52ec <jinit_input_controller+0x140c> */
/* @0x2b54e4 ldr r2, [sp, #0x4] */
/* @0x2b54e8 cmp r2, #0 */
/* @0x2b54ec beq 0x2b5508 <jinit_input_controller+0x1628> */
/* @0x2b54f0 ldr r3, [r11] */
/* @0x2b54f4 mov r12, #11 */
/* @0x2b54f8 mov r0, r11 */
/* @0x2b54fc str r12, [r3, #0x14] */
/* @0x2b5500 ldr r3, [r3] */
/* @0x2b5504 blx r3 */
/* @0x2b5508 str r5, [r6] */
/* @0x2b550c str r4, [r6, #0x4] */
/* @0x2b5510 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b5514 ldr r3, [r11] */
/* @0x2b5518 mov r2, #102 */
/* @0x2b551c mov r0, r11 */
/* @0x2b5520 mov r1, #1 */
/* @0x2b5524 str r2, [r3, #0x14] */
/* @0x2b5528 ldr r3, [r3, #0x4] */
/* @0x2b552c blx r3 */
/* @0x2b5530 ldr r4, [r11, #0x194] */
/* @0x2b5534 ldrb r3, [r4, #0xc] */
/* @0x2b5538 cmp r3, #0 */
/* @0x2b553c bne 0x2b56c8 <jinit_input_controller+0x17e8> */
/* @0x2b5540 mov r2, #0 */
/* @0x2b5544 mov r3, r11 */
/* @0x2b5548 mov lr, r2 */
/* @0x2b554c mov r12, #5 */
/* @0x2b5550 add r2, r2, #1 */
/* @0x2b5554 mov r1, #1 */
/* @0x2b5558 cmp r2, #16 */
/* @0x2b555c strb r1, [r3, #0xda] */
/* @0x2b5560 strb lr, [r3, #0xca] */
/* @0x2b5564 mov r1, #0 */
/* @0x2b5568 strb r12, [r3, #0xea] */
/* @0x2b556c mov r0, #1 */
/* @0x2b5570 add r3, r3, #1 */
/* @0x2b5574 bne 0x2b5550 <jinit_input_controller+0x1670> */
/* @0x2b5578 mov r2, #260 */
/* @0x2b557c movw r3, #0x106 */
/* @0x2b5580 str r1, [r11, #0xfc] */
/* @0x2b5584 str r1, [r11, #0x28] */
/* @0x2b5588 strb r1, [r11, #0x10a] */
/* @0x2b558c strb r1, [r11, #0x100] */
/* @0x2b5590 strb r0, [r11, #0x101] */
/* @0x2b5594 strb r0, [r11, #0x102] */
/* @0x2b5598 strb r1, [r11, #0x103] */
/* @0x2b559c strb r1, [r11, #0x108] */
/* @0x2b55a0 strb r1, [r11, #0x109] */
/* @0x2b55a4 strh r0, [r11, r2] */
/* @0x2b55a8 strh r0, [r11, r3] */
/* @0x2b55ac strb r0, [r4, #0xc] */
/* @0x2b55b0 b 0x2b4dfc <jinit_input_controller+0xf1c> */
/* @0x2b55b4 ldr r3, [r11] */
/* @0x2b55b8 mov r2, #85 */
/* @0x2b55bc mov r0, r11 */
/* @0x2b55c0 mov r1, #1 */
/* @0x2b55c4 str r2, [r3, #0x14] */
/* @0x2b55c8 ldr r3, [r3, #0x4] */
/* @0x2b55cc blx r3 */
/* @0x2b55d0 mov r3, #0 */
/* @0x2b55d4 mov r0, #2 */
/* @0x2b55d8 str r3, [r11, #0x17c] */
/* @0x2b55dc add sp, sp, #12 */
/* @0x2b55e0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 3 */
/* @0x2b55e4 ldr r3, [r11] */
/* @0x2b55e8 mov r1, #53 */
/* @0x2b55ec mov r0, r11 */
/* @0x2b55f0 str r9, [r3, #0x18] */
/* @0x2b55f4 ldr r2, [r11] */
/* @0x2b55f8 str r1, [r3, #0x14] */
/* @0x2b55fc str r5, [r2, #0x1c] */
/* @0x2b5600 ldr r3, [r11] */
/* @0x2b5604 ldr r3, [r3] */
/* @0x2b5608 blx r3 */
/* @0x2b560c b 0x2b4cb0 <jinit_input_controller+0xdd0> */
/* @0x2b5610 ldr r2, [sp, #0x4] */
/* @0x2b5614 sub r2, r2, #65 */
/* @0x2b5618 str r2, [sp, #0x4] */
/* @0x2b561c b 0x2b54d8 <jinit_input_controller+0x15f8> */
/* @0x2b5620 ldr r3, [r11] */
/* @0x2b5624 mov lr, #31 */
/* @0x2b5628 mov r0, r11 */
/* @0x2b562c str r7, [r3, #0x18] */
/* @0x2b5630 ldr r2, [r11] */
/* @0x2b5634 str lr, [r3, #0x14] */
/* @0x2b5638 ldr r3, [r2] */
/* @0x2b563c blx r3 */
/* @0x2b5640 b 0x2b5358 <jinit_input_controller+0x1478> */
/* @0x2b5644 sub r3, r10, #1 */
/* @0x2b5648 cmp r3, #3 */
/* @0x2b564c bls 0x2b4f00 <jinit_input_controller+0x1020> */
/* @0x2b5650 b 0x2b4ee8 <jinit_input_controller+0x1008> */
/* @0x2b5654 ldr r3, [r8, #0xc] */
/* @0x2b5658 mov r0, r11 */
/* @0x2b565c blx r3 */
/* @0x2b5660 cmp r0, #0 */
/* @0x2b5664 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5668 ldr r5, [r8] */
/* @0x2b566c ldr r4, [r8, #0x4] */
/* @0x2b5670 b 0x2b4e6c <jinit_input_controller+0xf8c> */
/* @0x2b5674 ldr r3, [r11] */
/* @0x2b5678 mov r2, #62 */
/* @0x2b567c mov r0, r11 */
/* @0x2b5680 str r2, [r3, #0x14] */
/* @0x2b5684 ldr r3, [r3] */
/* @0x2b5688 blx r3 */
/* @0x2b568c b 0x2b4e64 <jinit_input_controller+0xf84> */
/* @0x2b5690 ldr r3, [r6, #0xc] */
/* @0x2b5694 mov r0, r11 */
/* @0x2b5698 blx r3 */
/* @0x2b569c cmp r0, #0 */
/* @0x2b56a0 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56a4 ldm r6, {r2, r3} */
/* @0x2b56a8 b 0x2b52b8 <jinit_input_controller+0x13d8> */
/* @0x2b56ac ldr r3, [r4, #0xc] */
/* @0x2b56b0 mov r0, r11 */
/* @0x2b56b4 blx r3 */
/* @0x2b56b8 cmp r0, #0 */
/* @0x2b56bc beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56c0 ldm r4, {r2, r3} */
/* @0x2b56c4 b 0x2b4d04 <jinit_input_controller+0xe24> */
/* @0x2b56c8 ldr r3, [r11] */
/* @0x2b56cc mov r2, #61 */
/* @0x2b56d0 mov r0, r11 */
/* @0x2b56d4 str r2, [r3, #0x14] */
/* @0x2b56d8 ldr r3, [r3] */
/* @0x2b56dc blx r3 */
/* @0x2b56e0 ldr r4, [r11, #0x194] */
/* @0x2b56e4 b 0x2b5540 <jinit_input_controller+0x1660> */
/* @0x2b56e8 ldr r3, [r8, #0xc] */
/* @0x2b56ec mov r0, r11 */
/* @0x2b56f0 blx r3 */
/* @0x2b56f4 cmp r0, #0 */
/* @0x2b56f8 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b56fc ldr r5, [r8] */
/* @0x2b5700 ldr r4, [r8, #0x4] */
/* @0x2b5704 b 0x2b4e80 <jinit_input_controller+0xfa0> */
/* @0x2b5708 ldr r3, [r4, #0xc] */
/* @0x2b570c mov r0, r11 */
/* @0x2b5710 blx r3 */
/* @0x2b5714 cmp r0, #0 */
/* @0x2b5718 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b571c ldr r5, [r4] */
/* @0x2b5720 ldr r3, [r4, #0x4] */
/* @0x2b5724 b 0x2b4d18 <jinit_input_controller+0xe38> */
/* @0x2b5728 ldr r3, [r6, #0xc] */
/* @0x2b572c mov r0, r11 */
/* @0x2b5730 blx r3 */
/* @0x2b5734 cmp r0, #0 */
/* @0x2b5738 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b573c ldm r6, {r2, r3} */
/* @0x2b5740 b 0x2b52cc <jinit_input_controller+0x13ec> */
/* @0x2b5744 ldr r3, [r4, #0xc] */
/* @0x2b5748 mov r0, r11 */
/* @0x2b574c blx r3 */
/* @0x2b5750 cmp r0, #0 */
/* @0x2b5754 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5758 ldm r4, {r5, r7} */
/* @0x2b575c b 0x2b4d50 <jinit_input_controller+0xe70> */
/* @0x2b5760 mov r0, r11 */
/* @0x2b5764 bl 0x2bc8e4 <jpeg_alloc_quant_table> —— bl jpeg_alloc_quant_table（DQT 处理器） */
/* @0x2b5768 mov r10, r0 */
/* @0x2b576c str r0, [r7, #0x90] */
/* @0x2b5770 b 0x2b5368 <jinit_input_controller+0x1488> */
/* @0x2b5774 ldr r3, [r8, #0xc] */
/* @0x2b5778 mov r0, r11 */
/* @0x2b577c blx r3 */
/* @0x2b5780 cmp r0, #0 */
/* @0x2b5784 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b5788 ldm r8, {r5, r9} */
/* @0x2b578c b 0x2b5008 <jinit_input_controller+0x1128> */
/* @0x2b5790 ldr r3, [r8, #0xc] */
/* @0x2b5794 mov r0, r11 */
/* @0x2b5798 blx r3 */
/* @0x2b579c cmp r0, #0 */
/* @0x2b57a0 beq 0x2b50dc <jinit_input_controller+0x11fc> */
/* @0x2b57a4 ldm r8, {r5, r12} */
/* @0x2b57a8 b 0x2b501c <jinit_input_controller+0x113c> */
/* @0x2b57ac andseq r12, r3, r12, lsr r7 */
/* ═══════════════════════════════════════════════════════════════════════
 * §4  anon_2b6a50 = jdmerge.c 合并上采样三件套（转发器 + h2v1 + h2v2）
 * ═══════════════════════════════════════════════════════════════════════
 * 段内三个函数（split 并成一段，边界由出口/序言确定）：
 *   0x2b6a50..0x2b6a90   68 B   merged_1v_upsample    —— 只转发：读 cinfo->upsample(+0x1a0)
 *                                的 +0xc 槽（color_convert），blx 过去，不做垂直合并
 *   0x2b6a94..0x2b6c30  416 B   h2v1_merged_upsample  —— 无 lr 的叶子（push {r4..r11} 不含 lr，
 *                                出口 bx lr），逐行 YCbCr→RGB
 *   0x2b6c3c..0x2b6e8c  596 B   h2v2_merged_upsample  —— 2 行垂直合并，同构但多一路
 *   （0x2b6c34 是 4 B 池字；0x2b6e90/0x2b6e94 是另一条分支的尾巴）
 *
 * 身份证据：jinit_merged_upsampler(0x2b6f9c) 的三处安装，全部先 `add rX,pc,rX` 再 str：
 *   0x2b6fc4 `str r0,[r4,#0x1a0]`  ← cinfo->upsample = 新分配的结构（0x2b6fc0 之前算好）
 *   0x2b7004 `str r1,[r5,#0x4]`    ← 0x2b6a50（jpeg_upsampler 槽 #1 upsample）
 *   0x2b7008 `str r2,[r5,#0xc]`    ← 0x2b6a94
 *   0x2b7124 `str r12,[r5,#0xc]`   ← 0x2b6c3c（同一槽的另一分支：按 h/v 采样率二选一）
 *   ⇒ +0x4 是全格式共用的转发器，+0xc 是颜色转换器；两个 color converter 落在同一段里，
 *     正是 jdmerge.c 的 h2v1/h2v2 两分支。
 *
 * 它调谁：0 处 bl；0x2b6a50 的唯一外部调用是 0x2b6a74 `blx r12`（[upsample+0xc]）
 * 谁调它：只经方法槽（cinfo->upsample 的 +0x4 / +0xc），0 处直接 bl
 * 边界：三个函数之间无 bl 边、后两个无 lr，切分器的两个信号都收不到 → 并成一段。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b6a50 0x2b6e98 anon_2b6a50 merged_upsample_block */

/* @0x2b6a50 push {r3, r4, r5, lr} —— merged_1v_upsample 入口（68 B 转发器） */
/* @0x2b6a54 mov r4, r2 */
/* @0x2b6a58 ldr r5, [sp, #0x14] */
/* @0x2b6a5c ldr r12, [r0, #0x1a0] —— cinfo+0x1a0 = cinfo->upsample */
/* @0x2b6a60 ldr r3, [sp, #0x10] */
/* @0x2b6a64 ldr lr, [r5] */
/* @0x2b6a68 ldr r2, [r2] */
/* @0x2b6a6c ldr r12, [r12, #0xc] —— upsample+0xc = color_convert 槽 */
/* @0x2b6a70 add r3, r3, lr, lsl #2 */
/* @0x2b6a74 blx r12 —— blx color_convert —— 1v 只转发，不做垂直合并 */
/* @0x2b6a78 ldr r3, [r5] */
/* @0x2b6a7c add r3, r3, #1 */
/* @0x2b6a80 str r3, [r5] */
/* @0x2b6a84 ldr r3, [r4] */
/* @0x2b6a88 add r3, r3, #1 */
/* @0x2b6a8c str r3, [r4] */
/* @0x2b6a90 pop {r3, r4, r5, pc} —— merged_1v 出口 pop {r3,r4,r5,pc} */
/* @0x2b6a94 push {r4, r5, r6, r7, r8, r9, r10, r11} —— h2v1_merged_upsample 入口（无 lr 叶子） */
/* @0x2b6a98 sub sp, sp, #32 */
/* @0x2b6a9c ldr r5, [r0, #0x1a0] */
/* @0x2b6aa0 str r0, [sp, #0x10] */
/* @0x2b6aa4 ldr r4, [r0, #0x5c] */
/* @0x2b6aa8 ldr r12, [r1] */
/* @0x2b6aac ldr r0, [r1, #0x4] */
/* @0x2b6ab0 ldr r1, [r1, #0x8] */
/* @0x2b6ab4 lsrs r6, r4, #1 */
/* @0x2b6ab8 ldr r12, [r12, r2, lsl #2] */
/* @0x2b6abc str r6, [sp, #0x14] */
/* @0x2b6ac0 ldr r3, [r3] */
/* @0x2b6ac4 ldr r7, [r5, #0x14] */
/* @0x2b6ac8 ldr r1, [r1, r2, lsl #2] */
/* @0x2b6acc ldr r6, [sp, #0x10] */
/* @0x2b6ad0 str r12, [sp, #0x18] */
/* @0x2b6ad4 str r3, [sp, #0xc] */
/* @0x2b6ad8 ldr r12, [r0, r2, lsl #2] */
/* @0x2b6adc ldr r10, [r5, #0x10] */
/* @0x2b6ae0 str r7, [sp, #0x4] */
/* @0x2b6ae4 ldr r11, [r5, #0x18] */
/* @0x2b6ae8 ldr r9, [r5, #0x1c] */
/* @0x2b6aec str r1, [sp, #0x1c] */
/* @0x2b6af0 ldr r0, [r6, #0x120] */
/* @0x2b6af4 beq 0x2b6c34 <jinit_master_decompress+0x55c> */
/* @0x2b6af8 ldr r2, [sp, #0x18] */
/* @0x2b6afc mov r8, r1 */
/* @0x2b6b00 ldr r7, [sp, #0x14] */
/* @0x2b6b04 str r9, [sp] */
/* @0x2b6b08 add r7, r12, r7 */
/* @0x2b6b0c str r7, [sp, #0x8] */
/* @0x2b6b10 ldrb r4, [r12], #1 */
/* @0x2b6b14 add r2, r2, #2 */
/* @0x2b6b18 ldr r9, [sp, #0x8] */
/* @0x2b6b1c add r3, r3, #6 */
/* @0x2b6b20 ldrb r5, [r8], #1 */
/* @0x2b6b24 cmp r12, r9 */
/* @0x2b6b28 ldr r9, [sp] */
/* @0x2b6b2c ldrb r1, [r2, #-0x2] */
/* @0x2b6b30 ldr r6, [r10, r5, lsl #2] */
/* @0x2b6b34 ldr r7, [r9, r4, lsl #2] */
/* @0x2b6b38 ldr r5, [r11, r5, lsl #2] */
/* @0x2b6b3c add r6, r0, r6 */
/* @0x2b6b40 ldr r9, [sp, #0x4] */
/* @0x2b6b44 add r5, r7, r5 */
/* @0x2b6b48 ldrb r7, [r6, r1] */
/* @0x2b6b4c add r5, r0, r5, asr #16 */
/* @0x2b6b50 ldr r4, [r9, r4, lsl #2] */
/* @0x2b6b54 strb r7, [r3, #-0x6] */
/* @0x2b6b58 ldrb r7, [r5, r1] */
/* @0x2b6b5c add r4, r0, r4 */
/* @0x2b6b60 strb r7, [r3, #-0x5] */
/* @0x2b6b64 ldrb r1, [r4, r1] */
/* @0x2b6b68 strb r1, [r3, #-0x4] */
/* @0x2b6b6c ldrb r1, [r2, #-0x1] */
/* @0x2b6b70 ldrb r6, [r6, r1] */
/* @0x2b6b74 strb r6, [r3, #-0x3] */
/* @0x2b6b78 ldrb r5, [r5, r1] */
/* @0x2b6b7c strb r5, [r3, #-0x2] */
/* @0x2b6b80 ldrb r1, [r4, r1] */
/* @0x2b6b84 strb r1, [r3, #-0x1] */
/* @0x2b6b88 bne 0x2b6b10 <jinit_master_decompress+0x438> */
/* @0x2b6b8c ldr r12, [sp, #0x14] */
/* @0x2b6b90 ldr r6, [sp, #0x10] */
/* @0x2b6b94 ldr r1, [sp, #0x1c] */
/* @0x2b6b98 lsl r3, r12, #1 */
/* @0x2b6b9c ldr r9, [sp] */
/* @0x2b6ba0 ldr r4, [r6, #0x5c] */
/* @0x2b6ba4 add r1, r1, r12 */
/* @0x2b6ba8 add r2, r3, r12 */
/* @0x2b6bac ldr r7, [sp, #0x18] */
/* @0x2b6bb0 ldr r12, [sp, #0xc] */
/* @0x2b6bb4 add r7, r7, r3 */
/* @0x2b6bb8 str r1, [sp, #0x1c] */
/* @0x2b6bbc add r12, r12, r2, lsl #1 */
/* @0x2b6bc0 str r7, [sp, #0x18] */
/* @0x2b6bc4 str r12, [sp, #0xc] */
/* @0x2b6bc8 tst r4, #1 */
/* @0x2b6bcc beq 0x2b6c28 <jinit_master_decompress+0x550> */
/* @0x2b6bd0 ldr r2, [sp, #0x1c] */
/* @0x2b6bd4 ldr r3, [sp, #0x8] */
/* @0x2b6bd8 ldr r6, [sp, #0x18] */
/* @0x2b6bdc ldrb r1, [r2] */
/* @0x2b6be0 ldrb r2, [r3] */
/* @0x2b6be4 ldr r7, [sp, #0x4] */
/* @0x2b6be8 ldrb r3, [r6] */
/* @0x2b6bec ldr r5, [r9, r2, lsl #2] */
/* @0x2b6bf0 ldr r12, [r11, r1, lsl #2] */
/* @0x2b6bf4 add r4, r0, r3 */
/* @0x2b6bf8 ldr r1, [r10, r1, lsl #2] */
/* @0x2b6bfc ldr r2, [r7, r2, lsl #2] */
/* @0x2b6c00 add r12, r5, r12 */
/* @0x2b6c04 ldr r9, [sp, #0xc] */
/* @0x2b6c08 ldrb r1, [r4, r1] */
/* @0x2b6c0c add r2, r0, r2 */
/* @0x2b6c10 add r0, r0, r12, asr #16 */
/* @0x2b6c14 strb r1, [r9] */
/* @0x2b6c18 ldrb r1, [r0, r3] */
/* @0x2b6c1c strb r1, [r9, #0x1] */
/* @0x2b6c20 ldrb r3, [r2, r3] */
/* @0x2b6c24 strb r3, [r9, #0x2] */
/* @0x2b6c28 add sp, sp, #32 */
/* @0x2b6c2c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6c30 bx lr —— h2v1 出口 bx lr */
/* @0x2b6c34 str r12, [sp, #0x8] —— 4 B 池字（非指令） */
/* @0x2b6c38 b 0x2b6bc8 <jinit_master_decompress+0x4f0> */
/* @0x2b6c3c push {r4, r5, r6, r7, r8, r9, r10, r11} —— h2v2_merged_upsample 入口 */
/* @0x2b6c40 sub sp, sp, #48 */
/* @0x2b6c44 ldr r5, [r1] */
/* @0x2b6c48 str r0, [sp, #0x1c] */
/* @0x2b6c4c ldr r7, [sp, #0x1c] */
/* @0x2b6c50 add r6, r5, r2, lsl #3 */
/* @0x2b6c54 ldr r12, [r1, #0x4] */
/* @0x2b6c58 ldr r5, [r5, r2, lsl #3] */
/* @0x2b6c5c ldr r4, [r7, #0x1a0] */
/* @0x2b6c60 ldr r0, [r0, #0x5c] */
/* @0x2b6c64 ldr r1, [r1, #0x8] */
/* @0x2b6c68 ldr r11, [r4, #0x10] */
/* @0x2b6c6c lsrs r10, r0, #1 */
/* @0x2b6c70 ldr r6, [r6, #0x4] */
/* @0x2b6c74 str r10, [sp, #0x20] */
/* @0x2b6c78 str r5, [sp, #0x24] */
/* @0x2b6c7c str r11, [sp, #0x4] */
/* @0x2b6c80 ldr r5, [r4, #0x18] */
/* @0x2b6c84 ldr r11, [r3] */
/* @0x2b6c88 ldr r10, [r4, #0x14] */
/* @0x2b6c8c ldr r1, [r1, r2, lsl #2] */
/* @0x2b6c90 ldr r4, [r4, #0x1c] */
/* @0x2b6c94 ldr r3, [r3, #0x4] */
/* @0x2b6c98 str r6, [sp, #0x28] */
/* @0x2b6c9c str r5, [sp, #0x8] */
/* @0x2b6ca0 str r4, [sp, #0xc] */
/* @0x2b6ca4 ldr r8, [r12, r2, lsl #2] */
/* @0x2b6ca8 str r1, [sp, #0x2c] */
/* @0x2b6cac ldr r7, [r7, #0x120] */
/* @0x2b6cb0 str r11, [sp, #0x14] */
/* @0x2b6cb4 str r3, [sp, #0x18] */
/* @0x2b6cb8 beq 0x2b6e90 <jinit_master_decompress+0x7b8> */
/* @0x2b6cbc ldr r5, [sp, #0x24] */
/* @0x2b6cc0 mov r2, r3 */
/* @0x2b6cc4 ldr r12, [sp, #0x20] */
/* @0x2b6cc8 mov r4, r6 */
/* @0x2b6ccc mov r9, r1 */
/* @0x2b6cd0 mov r3, r11 */
/* @0x2b6cd4 add r12, r8, r12 */
/* @0x2b6cd8 str r10, [sp] */
/* @0x2b6cdc str r12, [sp, #0x10] */
/* @0x2b6ce0 ldrb r0, [r9], #1 */
/* @0x2b6ce4 add r5, r5, #2 */
/* @0x2b6ce8 ldr r10, [sp, #0x4] */
/* @0x2b6cec add r3, r3, #6 */
/* @0x2b6cf0 ldrb r1, [r8], #1 */
/* @0x2b6cf4 add r4, r4, #2 */
/* @0x2b6cf8 ldr r11, [sp, #0x10] */
/* @0x2b6cfc add r2, r2, #6 */
/* @0x2b6d00 ldr r12, [r10, r0, lsl #2] */
/* @0x2b6d04 ldr r10, [sp, #0x8] */
/* @0x2b6d08 cmp r8, r11 */
/* @0x2b6d0c ldrb r6, [r5, #-0x2] */
/* @0x2b6d10 add r12, r7, r12 */
/* @0x2b6d14 ldr r0, [r10, r0, lsl #2] */
/* @0x2b6d18 ldr r10, [sp, #0xc] */
/* @0x2b6d1c ldr r11, [r10, r1, lsl #2] */
/* @0x2b6d20 ldr r10, [sp] */
/* @0x2b6d24 add r0, r11, r0 */
/* @0x2b6d28 ldrb r11, [r12, r6] */
/* @0x2b6d2c add r0, r7, r0, asr #16 */
/* @0x2b6d30 ldr r1, [r10, r1, lsl #2] */
/* @0x2b6d34 strb r11, [r3, #-0x6] */
/* @0x2b6d38 ldrb r11, [r0, r6] */
/* @0x2b6d3c add r1, r7, r1 */
/* @0x2b6d40 strb r11, [r3, #-0x5] */
/* @0x2b6d44 ldrb r6, [r1, r6] */
/* @0x2b6d48 strb r6, [r3, #-0x4] */
/* @0x2b6d4c ldrb r6, [r5, #-0x1] */
/* @0x2b6d50 ldrb r11, [r12, r6] */
/* @0x2b6d54 strb r11, [r3, #-0x3] */
/* @0x2b6d58 ldrb r11, [r0, r6] */
/* @0x2b6d5c strb r11, [r3, #-0x2] */
/* @0x2b6d60 ldrb r6, [r1, r6] */
/* @0x2b6d64 strb r6, [r3, #-0x1] */
/* @0x2b6d68 ldrb r6, [r4, #-0x2] */
/* @0x2b6d6c ldrb r11, [r12, r6] */
/* @0x2b6d70 strb r11, [r2, #-0x6] */
/* @0x2b6d74 ldrb r11, [r0, r6] */
/* @0x2b6d78 strb r11, [r2, #-0x5] */
/* @0x2b6d7c ldrb r6, [r1, r6] */
/* @0x2b6d80 strb r6, [r2, #-0x4] */
/* @0x2b6d84 ldrb r6, [r4, #-0x1] */
/* @0x2b6d88 ldrb r12, [r12, r6] */
/* @0x2b6d8c strb r12, [r2, #-0x3] */
/* @0x2b6d90 ldrb r0, [r0, r6] */
/* @0x2b6d94 strb r0, [r2, #-0x2] */
/* @0x2b6d98 ldrb r1, [r1, r6] */
/* @0x2b6d9c strb r1, [r2, #-0x1] */
/* @0x2b6da0 bne 0x2b6ce0 <jinit_master_decompress+0x608> */
/* @0x2b6da4 ldr r11, [sp, #0x20] */
/* @0x2b6da8 ldr r4, [sp, #0x1c] */
/* @0x2b6dac ldr r12, [sp, #0x2c] */
/* @0x2b6db0 lsl r3, r11, #1 */
/* @0x2b6db4 ldr r5, [sp, #0x24] */
/* @0x2b6db8 add r2, r3, r11 */
/* @0x2b6dbc ldr r0, [r4, #0x5c] */
/* @0x2b6dc0 add r12, r12, r11 */
/* @0x2b6dc4 ldr r1, [sp, #0x18] */
/* @0x2b6dc8 ldr r11, [sp, #0x28] */
/* @0x2b6dcc lsl r2, r2, #1 */
/* @0x2b6dd0 str r12, [sp, #0x2c] */
/* @0x2b6dd4 add r5, r5, r3 */
/* @0x2b6dd8 ldr r12, [sp, #0x14] */
/* @0x2b6ddc add r11, r11, r3 */
/* @0x2b6de0 add r1, r1, r2 */
/* @0x2b6de4 str r5, [sp, #0x24] */
/* @0x2b6de8 add r12, r12, r2 */
/* @0x2b6dec str r11, [sp, #0x28] */
/* @0x2b6df0 str r12, [sp, #0x14] */
/* @0x2b6df4 str r1, [sp, #0x18] */
/* @0x2b6df8 tst r0, #1 */
/* @0x2b6dfc beq 0x2b6e84 <jinit_master_decompress+0x7ac> */
/* @0x2b6e00 ldr r2, [sp, #0x2c] */
/* @0x2b6e04 ldr r3, [sp, #0x10] */
/* @0x2b6e08 ldr r4, [sp, #0x24] */
/* @0x2b6e0c ldrb r0, [r2] */
/* @0x2b6e10 ldr r5, [sp, #0x4] */
/* @0x2b6e14 ldrb r2, [r3] */
/* @0x2b6e18 ldr r11, [sp, #0x8] */
/* @0x2b6e1c ldrb r3, [r4] */
/* @0x2b6e20 ldr r4, [sp, #0xc] */
/* @0x2b6e24 ldr r1, [r5, r0, lsl #2] */
/* @0x2b6e28 ldr r0, [r11, r0, lsl #2] */
/* @0x2b6e2c ldr r12, [r4, r2, lsl #2] */
/* @0x2b6e30 add r1, r7, r1 */
/* @0x2b6e34 ldr r2, [r10, r2, lsl #2] */
/* @0x2b6e38 add r12, r12, r0 */
/* @0x2b6e3c ldr r5, [sp, #0x14] */
/* @0x2b6e40 ldrb r0, [r1, r3] */
/* @0x2b6e44 add r2, r7, r2 */
/* @0x2b6e48 add r7, r7, r12, asr #16 */
/* @0x2b6e4c ldr r10, [sp, #0x28] */
/* @0x2b6e50 ldr r11, [sp, #0x18] */
/* @0x2b6e54 strb r0, [r5] */
/* @0x2b6e58 ldrb r0, [r7, r3] */
/* @0x2b6e5c strb r0, [r5, #0x1] */
/* @0x2b6e60 ldrb r3, [r2, r3] */
/* @0x2b6e64 strb r3, [r5, #0x2] */
/* @0x2b6e68 ldrb r3, [r10] */
/* @0x2b6e6c ldrb r1, [r1, r3] */
/* @0x2b6e70 strb r1, [r11] */
/* @0x2b6e74 ldrb r1, [r7, r3] */
/* @0x2b6e78 strb r1, [r11, #0x1] */
/* @0x2b6e7c ldrb r3, [r2, r3] */
/* @0x2b6e80 strb r3, [r11, #0x2] */
/* @0x2b6e84 add sp, sp, #48 */
/* @0x2b6e88 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b6e8c bx lr —— h2v2 出口 bx lr */
/* @0x2b6e90 str r8, [sp, #0x10] —— 另一分支的尾巴（非新函数入口） */
/* @0x2b6e94 b 0x2b6df8 <jinit_master_decompress+0x720> */
/* ═══════════════════════════════════════════════════════════════════════
 * §5  anon_2b71dc = jdphuff.c start_pass_phuff_decoder
 * ═══════════════════════════════════════════════════════════════════════
 * 契约：void start_pass_phuff_decoder(j_decompress_ptr cinfo)——r0 = cinfo；每次
 *       start_pass / 每次新扫描时重建 DC、AC 两张 derived table，并按 Ss/Se/Ah/Al 选解码器。
 *
 * 身份证据（三条）
 *   ① 安装点：jinit_phuff_decoder(0x2b7fdc) 的 0x2b8008 取池字 0xfffff1c0、0x2b8010
 *      `add lr,pc,lr`（pc=0x2b8018）→ 0x2b71d8，0x2b8024 `str lr,[r3]` 写进 entropy 结构
 *      +0x0 ⇒ jpeg_entropy_decoder 槽 #0 start_pass。真入口 0x2b71d8（本段起点晚 4 B）。
 *   ② 0x2b71fc 读 cinfo+0x170、0x2b720c 读 +0x174、0x2b7210 读 +0x178，0x2b7228
 *      `cmp r2,#13` + `ble` —— 这是 Ss/Se 的谱段闸门（渐进 AC 的 Se 上限 13 = 8x8 块内
 *      63 个系数的索引上限）。三个相邻 int 字段 + 13 的上界，只有 phuff 的 Ss/Se 对得上。
 *   ③ 0x2b71f4 读 cinfo+0x198（entropy），全段两次 `bl jpeg_make_d_derived_tbl` ——
 *      start_pass 是唯一"为 DC/AC 各建一张 derived table"的地方。
 *
 * 它调谁：jpeg_make_d_derived_tbl(0x2be510) ×2
 * 谁调它：jinit_phuff_decoder 写槽；0 处直接 bl
 * 边界：单函数，唯一出口 0x2b7464 `pop {r4..r11,pc}`；0x2b74e0..0x2b74ec 是池字
 *       （strdeq/andeq/andeq），0x2b74f0/0x2b74f4（ldr r2,[r0,#0xfc] / mov r3,#1）是下一
 *       函数 0x2b74f8 的预序言。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b71dc 0x2b74f8 anon_2b71dc start_pass_phuff_decoder */

/* @0x2b71dc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 序言（9 寄存器 + 12 B 帧） */
/* @0x2b71e0 rsbs r2, r3, #1 */
/* @0x2b71e4 sub sp, sp, #12 */
/* @0x2b71e8 mov r4, r0 */
/* @0x2b71ec movlo r2, #0 */
/* @0x2b71f0 cmp r2, #0 */
/* @0x2b71f4 ldr r10, [r0, #0x198] —— cinfo+0x198 = cinfo->entropy */
/* @0x2b71f8 str r2, [sp, #0x4] */
/* @0x2b71fc ldr r0, [r0, #0x170] —— cinfo+0x170（Ss） */
/* @0x2b7200 beq 0x2b7358 <jinit_merged_upsampler+0x3bc> */
/* @0x2b7204 adds r0, r0, #0 */
/* @0x2b7208 movne r0, #1 */
/* @0x2b720c ldr r1, [r4, #0x174] —— cinfo+0x174 */
/* @0x2b7210 ldr r2, [r4, #0x178] —— cinfo+0x178（Se） */
/* @0x2b7214 cmp r1, #0 */
/* @0x2b7218 beq 0x2b7228 <jinit_merged_upsampler+0x28c> */
/* @0x2b721c sub r1, r1, #1 */
/* @0x2b7220 cmp r2, r1 */
/* @0x2b7224 bne 0x2b7230 <jinit_merged_upsampler+0x294> */
/* @0x2b7228 cmp r2, #13 —— cmp #13 = 谱段上界闸门 */
/* @0x2b722c ble 0x2b73d0 <jinit_merged_upsampler+0x434> */
/* @0x2b7230 ldr r2, [r4] */
/* @0x2b7234 mov r12, #16 */
/* @0x2b7238 mov r0, r4 */
/* @0x2b723c str r3, [r2, #0x18] */
/* @0x2b7240 ldr r3, [r4] */
/* @0x2b7244 ldr r1, [r4, #0x170] */
/* @0x2b7248 str r12, [r2, #0x14] */
/* @0x2b724c str r1, [r3, #0x1c] */
/* @0x2b7250 ldr r3, [r4] */
/* @0x2b7254 ldr r2, [r4, #0x174] */
/* @0x2b7258 str r2, [r3, #0x20] */
/* @0x2b725c ldr r3, [r4] */
/* @0x2b7260 ldr r2, [r4, #0x178] */
/* @0x2b7264 str r2, [r3, #0x24] */
/* @0x2b7268 ldr r3, [r4] */
/* @0x2b726c ldr r3, [r3] */
/* @0x2b7270 blx r3 */
/* @0x2b7274 ldr r3, [r4, #0x124] */
/* @0x2b7278 cmp r3, #0 */
/* @0x2b727c ble 0x2b7330 <jinit_merged_upsampler+0x394> */
/* @0x2b7280 mov r9, r4 */
/* @0x2b7284 mov r8, #0 */
/* @0x2b7288 mov r7, #115 */
/* @0x2b728c ldr r3, [r9, #0x128] */
/* @0x2b7290 ldr r2, [sp, #0x4] */
/* @0x2b7294 ldr r6, [r3, #0x4] */
/* @0x2b7298 cmp r2, #0 */
/* @0x2b729c ldr r2, [r4, #0x8c] */
/* @0x2b72a0 add r11, r2, r6, lsl #8 */
/* @0x2b72a4 bne 0x2b72b4 <jinit_merged_upsampler+0x318> */
/* @0x2b72a8 ldr r2, [r2, r6, lsl #8] */
/* @0x2b72ac cmp r2, #0 */
/* @0x2b72b0 blt 0x2b74b0 <jinit_merged_upsampler+0x514> */
/* @0x2b72b4 ldr r5, [r4, #0x16c] */
/* @0x2b72b8 ldr r2, [r4, #0x170] */
/* @0x2b72bc cmp r5, r2 */
/* @0x2b72c0 addle r11, r11, r5, lsl #2 */
/* @0x2b72c4 bgt 0x2b731c <jinit_merged_upsampler+0x380> */
/* @0x2b72c8 ldr r2, [r11], #4 */
/* @0x2b72cc mov r0, r4 */
/* @0x2b72d0 ldr r12, [r4, #0x174] */
/* @0x2b72d4 mvn r1, #0 */
/* @0x2b72d8 bic r2, r2, r2, asr #31 */
/* @0x2b72dc cmp r12, r2 */
/* @0x2b72e0 beq 0x2b7304 <jinit_merged_upsampler+0x368> */
/* @0x2b72e4 ldr r2, [r4] */
/* @0x2b72e8 str r6, [r2, #0x18] */
/* @0x2b72ec ldr r12, [r4] */
/* @0x2b72f0 str r7, [r2, #0x14] */
/* @0x2b72f4 str r5, [r12, #0x1c] */
/* @0x2b72f8 ldr r2, [r4] */
/* @0x2b72fc ldr r2, [r2, #0x4] */
/* @0x2b7300 blx r2 */
/* @0x2b7304 ldr r2, [r4, #0x178] */
/* @0x2b7308 add r5, r5, #1 */
/* @0x2b730c str r2, [r11, #-0x4] */
/* @0x2b7310 ldr r2, [r4, #0x170] */
/* @0x2b7314 cmp r2, r5 */
/* @0x2b7318 bge 0x2b72c8 <jinit_merged_upsampler+0x32c> */
/* @0x2b731c ldr r3, [r4, #0x124] */
/* @0x2b7320 add r8, r8, #1 */
/* @0x2b7324 add r9, r9, #4 */
/* @0x2b7328 cmp r3, r8 */
/* @0x2b732c bgt 0x2b728c <jinit_merged_upsampler+0x2f0> */
/* @0x2b7330 ldr r2, [r4, #0x174] */
/* @0x2b7334 ldr r1, [sp, #0x4] */
/* @0x2b7338 cmp r2, #0 */
/* @0x2b733c bne 0x2b7374 <jinit_merged_upsampler+0x3d8> */
/* @0x2b7340 cmp r1, #0 */
/* @0x2b7344 beq 0x2b7484 <jinit_merged_upsampler+0x4e8> */
/* @0x2b7348 ldr r1, [pc, #0x190] */
/* @0x2b734c add r1, pc, r1 */
/* @0x2b7350 str r1, [r10, #0x4] */
/* @0x2b7354 b 0x2b7388 <jinit_merged_upsampler+0x3ec> */
/* @0x2b7358 cmp r3, r0 */
/* @0x2b735c movgt r0, #1 */
/* @0x2b7360 ble 0x2b7468 <jinit_merged_upsampler+0x4cc> */
/* @0x2b7364 ldr r2, [r4, #0x124] */
/* @0x2b7368 cmp r2, #1 */
/* @0x2b736c movne r0, #1 */
/* @0x2b7370 b 0x2b720c <jinit_merged_upsampler+0x270> */
/* @0x2b7374 cmp r1, #0 */
/* @0x2b7378 beq 0x2b73dc <jinit_merged_upsampler+0x440> */
/* @0x2b737c ldr r1, [pc, #0x160] */
/* @0x2b7380 add r1, pc, r1 */
/* @0x2b7384 str r1, [r10, #0x4] */
/* @0x2b7388 cmp r3, #0 */
/* @0x2b738c ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b7390 mov r5, #0 */
/* @0x2b7394 mov r7, r4 */
/* @0x2b7398 mov r8, r5 */
/* @0x2b739c mov r6, r10 */
/* @0x2b73a0 cmp r2, #0 */
/* @0x2b73a4 ldr r3, [r7, #0x128] */
/* @0x2b73a8 add r5, r5, #1 */
/* @0x2b73ac add r7, r7, #4 */
/* @0x2b73b0 beq 0x2b7494 <jinit_merged_upsampler+0x4f8> */
/* @0x2b73b4 str r8, [r6, #0x18] */
/* @0x2b73b8 add r6, r6, #4 */
/* @0x2b73bc ldr r3, [r4, #0x124] */
/* @0x2b73c0 cmp r3, r5 */
/* @0x2b73c4 ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b73c8 ldr r2, [r4, #0x174] */
/* @0x2b73cc b 0x2b73a0 <jinit_merged_upsampler+0x404> */
/* @0x2b73d0 cmp r0, #0 */
/* @0x2b73d4 beq 0x2b7274 <jinit_merged_upsampler+0x2d8> */
/* @0x2b73d8 b 0x2b7230 <jinit_merged_upsampler+0x294> */
/* @0x2b73dc ldr r2, [pc, #0x104] */
/* @0x2b73e0 add r2, pc, r2 */
/* @0x2b73e4 str r2, [r10, #0x4] */
/* @0x2b73e8 cmp r3, #0 */
/* @0x2b73ec ble 0x2b7444 <jinit_merged_upsampler+0x4a8> */
/* @0x2b73f0 mov r5, #0 */
/* @0x2b73f4 mov r7, r4 */
/* @0x2b73f8 mov r9, r5 */
/* @0x2b73fc mov r6, r10 */
/* @0x2b7400 ldr r3, [r7, #0x128] */
/* @0x2b7404 mov r0, r4 */
/* @0x2b7408 mov r1, #0 */
/* @0x2b740c add r5, r5, #1 */
/* @0x2b7410 add r7, r7, #4 */
/* @0x2b7414 add r6, r6, #4 */
/* @0x2b7418 ldr r2, [r3, #0x18] */
/* @0x2b741c add r8, r2, #10 */
/* @0x2b7420 add r8, r10, r8, lsl #2 */
/* @0x2b7424 add r3, r8, #4 */
/* @0x2b7428 bl 0x2be510 <jpeg_make_d_derived_tbl> —— bl jpeg_make_d_derived_tbl（建 DC/AC derived table） */
/* @0x2b742c ldr r3, [r8, #0x4] */
/* @0x2b7430 str r3, [r10, #0x3c] */
/* @0x2b7434 str r9, [r6, #0x14] */
/* @0x2b7438 ldr r3, [r4, #0x124] */
/* @0x2b743c cmp r3, r5 */
/* @0x2b7440 bgt 0x2b7400 <jinit_merged_upsampler+0x464> */
/* @0x2b7444 mov r3, #0 */
/* @0x2b7448 strb r3, [r10, #0x8] */
/* @0x2b744c ldr r2, [r4, #0xfc] */
/* @0x2b7450 str r3, [r10, #0x10] */
/* @0x2b7454 str r3, [r10, #0xc] */
/* @0x2b7458 str r2, [r10, #0x28] */
/* @0x2b745c str r3, [r10, #0x14] */
/* @0x2b7460 add sp, sp, #12 */
/* @0x2b7464 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 唯一出口 pop {r4..r11,pc} */
/* @0x2b7468 cmp r0, #63 */
/* @0x2b746c ldr r2, [r4, #0x124] */
/* @0x2b7470 movle r0, #0 */
/* @0x2b7474 movgt r0, #1 */
/* @0x2b7478 cmp r2, #1 */
/* @0x2b747c movne r0, #1 */
/* @0x2b7480 b 0x2b720c <jinit_merged_upsampler+0x270> */
/* @0x2b7484 ldr r2, [pc, #0x60] */
/* @0x2b7488 add r2, pc, r2 */
/* @0x2b748c str r2, [r10, #0x4] */
/* @0x2b7490 b 0x2b73e8 <jinit_merged_upsampler+0x44c> */
/* @0x2b7494 ldr r2, [r3, #0x14] */
/* @0x2b7498 mov r0, r4 */
/* @0x2b749c mov r1, #1 */
/* @0x2b74a0 add r3, r10, r2, lsl #2 */
/* @0x2b74a4 add r3, r3, #44 */
/* @0x2b74a8 bl 0x2be510 <jpeg_make_d_derived_tbl> */
/* @0x2b74ac b 0x2b73b4 <jinit_merged_upsampler+0x418> */
/* @0x2b74b0 ldr r2, [r4] */
/* @0x2b74b4 mov r0, r4 */
/* @0x2b74b8 ldr r3, [sp, #0x4] */
/* @0x2b74bc mvn r1, #0 */
/* @0x2b74c0 str r6, [r2, #0x18] */
/* @0x2b74c4 ldr r12, [r4] */
/* @0x2b74c8 str r7, [r2, #0x14] */
/* @0x2b74cc str r3, [r12, #0x1c] */
/* @0x2b74d0 ldr r2, [r4] */
/* @0x2b74d4 ldr r2, [r2, #0x4] */
/* @0x2b74d8 blx r2 */
/* @0x2b74dc b 0x2b72b4 <jinit_merged_upsampler+0x318> */
/* @0x2b74e0 strdeq r0, r1, [r0], -r12 */
/* @0x2b74e4 andeq r0, r0, r8, ror #2 */
/* @0x2b74e8 andeq r0, r0, r12, lsl r2 */
/* @0x2b74ec andeq r0, r0, r12, lsr #12 */
/* @0x2b74f0 ldr r2, [r0, #0xfc] */
/* @0x2b74f4 mov r3, #1 */
/* ═══════════════════════════════════════════════════════════════════════
 * §6/§7/§8  anon_2b7608 / anon_2b7ac0 / anon_2b7d50 = jdphuff.c 的三个 decode_mcu_*
 * ═══════════════════════════════════════════════════════════════════════
 * 三段同族，共同形态（每段首条 bl 都是同一个 148 B 的 0x2b7148）：
 *   0x2b7148 是 process_restart：读 cinfo+0x198（entropy）+0x10 的 bits_left、折算成字节数
 *   记到 marker+0x14（bytes_read），再取 marker+0x8（read_restart_marker 槽）blx，回来后
 *   清 bits_left。四段（§5 之外的三段 + §9 走的是另一条 fill_bit_buffer 路）都靠它处理 RSTn。
 *   之后进入 MCU 循环：jpeg_fill_bit_buffer 补位 + jpeg_huff_decode 取 Huffman 码，
 *   把系数写进 MCU_data 的 8x8 块。
 *
 * 三段的差异（用来区分 DC/AC 两个族）
 *   §6 0x2b7608  302 条  读 cinfo+0x234（blocks_in_MCU）+ 每块 1 个系数 → DC 族
 *   §7 0x2b7ac0  164 条  读 +0x1b4 / +0x1fc，循环体最短 → AC 族（run-length 展开）
 *   §8 0x2b7d50  162 条  读 +0x1d8（natural_order 指针，zig-zag 反查表）→ AC 族
 *
 * 为什么不一一定名：DC_first / DC_refine / AC_first / AC_refine 四个变体在 -O2 下高度同形
 * （都调 process_restart + fill_bit_buffer + huff_decode，都用同一批 cinfo 字段），本卡只钉到
 * "三段都是 phuff 的 decode_mcu 变体、§6 是 DC 族、§7/§8 是 AC 族"；一一对应留 open 3。
 * DC_refine 不调 jpeg_huff_decode（只读 1 bit），不在这三段里。
 *
 * 它调谁：process_restart(0x2b7148) ×1、jpeg_fill_bit_buffer(0x2bea2c) ×2..5、
 *         jpeg_huff_decode(0x2beb8c) ×1
 * 谁调它：0 处直接 bl。调用只可能来自 jdcoefct 的 decompress_data 经 entropy 结构的方法槽
 *         （槽序：+0 start_pass / +4 decode_mcu / +8 finish_pass），本卡未逐点验证（open 3）。
 * 边界：每段都是单函数；段尾 1~2 个池字（andseq/strdeq）+ 下一函数的预序言
 *       （0x2b7abc 的 ldr r3,[r0,#0xfc] 属于 0x2b7ac0；0x2b7d48 之后是池字）。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b7608 0x2b7ac0 anon_2b7608 phuff_decode_mcu_dc */

/* @0x2b7608 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（302 条，本族最大；读 cinfo+0x234 = blocks_in_MCU） */
/* @0x2b760c cmp r3, #0 */
/* @0x2b7610 ldr r5, [r0, #0x198] */
/* @0x2b7614 sub sp, sp, #332 */
/* @0x2b7618 ldr r9, [r0, #0x170] */
/* @0x2b761c str r0, [sp, #0x14] */
/* @0x2b7620 str r5, [sp, #0x18] */
/* @0x2b7624 ldr r4, [r0, #0x178] */
/* @0x2b7628 beq 0x2b763c <jinit_merged_upsampler+0x6a0> */
/* @0x2b762c ldr r12, [sp, #0x18] */
/* @0x2b7630 ldr r3, [r12, #0x28] */
/* @0x2b7634 cmp r3, #0 */
/* @0x2b7638 beq 0x2b7a54 <jinit_merged_upsampler+0xab8> */
/* @0x2b763c ldr r6, [sp, #0x18] */
/* @0x2b7640 ldrb r12, [r6, #0x8] */
/* @0x2b7644 cmp r12, #0 */
/* @0x2b7648 bne 0x2b7854 <jinit_merged_upsampler+0x8b8> */
/* @0x2b764c ldr r5, [sp, #0x14] */
/* @0x2b7650 mov r2, #1 */
/* @0x2b7654 ldr r6, [sp, #0x18] */
/* @0x2b7658 mvn r3, #0 */
/* @0x2b765c ldr r7, [r1] */
/* @0x2b7660 lsl r3, r3, r4 */
/* @0x2b7664 ldr r1, [sp, #0x18] */
/* @0x2b7668 lsl r11, r2, r4 */
/* @0x2b766c ldr r6, [r6, #0x14] */
/* @0x2b7670 ldr r0, [r5, #0x18] */
/* @0x2b7674 str r3, [sp, #0x28] */
/* @0x2b7678 cmp r6, #0 */
/* @0x2b767c ldr r3, [r1, #0xc] */
/* @0x2b7680 ldr r2, [r1, #0x10] */
/* @0x2b7684 ldr r1, [r1, #0x3c] */
/* @0x2b7688 str r6, [sp, #0x2c] */
/* @0x2b768c str r5, [sp, #0x44] */
/* @0x2b7690 ldr r6, [r0, #0x4] */
/* @0x2b7694 ldr r5, [r0] */
/* @0x2b7698 str r1, [sp, #0x1c] */
/* @0x2b769c ldr r1, [sp, #0x14] */
/* @0x2b76a0 str r5, [sp, #0x34] */
/* @0x2b76a4 str r6, [sp, #0x38] */
/* @0x2b76a8 ldr r4, [r1, #0x16c] */
/* @0x2b76ac bne 0x2b7870 <jinit_merged_upsampler+0x8d4> */
/* @0x2b76b0 cmp r9, r4 */
/* @0x2b76b4 blt 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b76b8 ldr r5, [sp, #0x2c] */
/* @0x2b76bc str r5, [sp, #0x24] */
/* @0x2b76c0 cmp r2, #7 */
/* @0x2b76c4 ble 0x2b79c4 <jinit_merged_upsampler+0xa28> */
/* @0x2b76c8 sub r0, r2, #8 */
/* @0x2b76cc ldr r6, [sp, #0x1c] */
/* @0x2b76d0 asr r0, r3, r0 */
/* @0x2b76d4 uxtb r0, r0 */
/* @0x2b76d8 add r1, r0, #36 */
/* @0x2b76dc ldr r1, [r6, r1, lsl #2] */
/* @0x2b76e0 cmp r1, #0 */
/* @0x2b76e4 beq 0x2b7994 <jinit_merged_upsampler+0x9f8> */
/* @0x2b76e8 add r0, r6, r0 */
/* @0x2b76ec rsb r2, r1, r2 */
/* @0x2b76f0 ldrb r0, [r0, #0x490] */
/* @0x2b76f4 ands r10, r0, #15 */
/* @0x2b76f8 asr r8, r0, #4 */
/* @0x2b76fc beq 0x2b7938 <jinit_merged_upsampler+0x99c> */
/* @0x2b7700 cmp r10, #1 */
/* @0x2b7704 beq 0x2b7738 <jinit_merged_upsampler+0x79c> */
/* @0x2b7708 ldr r5, [sp, #0x14] */
/* @0x2b770c mvn r1, #0 */
/* @0x2b7710 mov r6, #118 */
/* @0x2b7714 ldr r12, [r5] */
/* @0x2b7718 mov r0, r5 */
/* @0x2b771c str r6, [r12, #0x14] */
/* @0x2b7720 ldr r12, [r12, #0x4] */
/* @0x2b7724 str r2, [sp, #0x8] */
/* @0x2b7728 str r3, [sp, #0xc] */
/* @0x2b772c blx r12 */
/* @0x2b7730 ldr r3, [sp, #0xc] */
/* @0x2b7734 ldr r2, [sp, #0x8] */
/* @0x2b7738 cmp r2, #0 */
/* @0x2b773c ble 0x2b79f8 <jinit_merged_upsampler+0xa5c> */
/* @0x2b7740 sub r2, r2, #1 */
/* @0x2b7744 ldr r10, [sp, #0x28] */
/* @0x2b7748 asr r1, r3, r2 */
/* @0x2b774c tst r1, #1 */
/* @0x2b7750 movne r10, r11 */
/* @0x2b7754 ldr r12, [pc, #0x358] */
/* @0x2b7758 add r6, sp, #52 */
/* @0x2b775c str r6, [sp, #0x10] */
/* @0x2b7760 mov r1, r3 */
/* @0x2b7764 ldr r12, [pc, r12] */
/* @0x2b7768 str r10, [sp, #0x20] */
/* @0x2b776c add r6, r12, r4, lsl #2 */
/* @0x2b7770 mov r10, r11 */
/* @0x2b7774 sub r6, r6, #4 */
/* @0x2b7778 mov r11, r12 */
/* @0x2b777c b 0x2b77c8 <jinit_merged_upsampler+0x82c> */
/* @0x2b7780 cmp r2, #0 */
/* @0x2b7784 ble 0x2b7918 <jinit_merged_upsampler+0x97c> */
/* @0x2b7788 sub r2, r2, #1 */
/* @0x2b778c asr r3, r1, r2 */
/* @0x2b7790 tst r3, #1 */
/* @0x2b7794 beq 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b7798 ldrh r0, [r7, r5] */
/* @0x2b779c sxth r3, r0 */
/* @0x2b77a0 tst r3, r10 */
/* @0x2b77a4 bne 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b77a8 cmp r3, #0 */
/* @0x2b77ac addge r0, r0, r10 */
/* @0x2b77b0 ldrlt r12, [sp, #0x28] */
/* @0x2b77b4 addlt r0, r0, r12 */
/* @0x2b77b8 strh r0, [r7, r5] */
/* @0x2b77bc add r4, r4, #1 */
/* @0x2b77c0 cmp r9, r4 */
/* @0x2b77c4 blt 0x2b77e4 <jinit_merged_upsampler+0x848> */
/* @0x2b77c8 ldr r5, [r6, #0x4]! */
/* @0x2b77cc lsl r5, r5, #1 */
/* @0x2b77d0 ldrsh r0, [r7, r5] */
/* @0x2b77d4 cmp r0, #0 */
/* @0x2b77d8 bne 0x2b7780 <jinit_merged_upsampler+0x7e4> */
/* @0x2b77dc subs r8, r8, #1 */
/* @0x2b77e0 bhs 0x2b77bc <jinit_merged_upsampler+0x820> */
/* @0x2b77e4 mov r12, r11 */
/* @0x2b77e8 mov r11, r10 */
/* @0x2b77ec ldr r10, [sp, #0x20] */
/* @0x2b77f0 mov r3, r1 */
/* @0x2b77f4 cmp r10, #0 */
/* @0x2b77f8 beq 0x2b7820 <jinit_merged_upsampler+0x884> */
/* @0x2b77fc ldr r1, [r12, r4, lsl #2] */
/* @0x2b7800 add r6, sp, #328 */
/* @0x2b7804 ldr r5, [sp, #0x24] */
/* @0x2b7808 lsl r0, r1, #1 */
/* @0x2b780c add r12, r6, r5, lsl #2 */
/* @0x2b7810 add r5, r5, #1 */
/* @0x2b7814 strh r10, [r7, r0] */
/* @0x2b7818 str r1, [r12, #-0x100] */
/* @0x2b781c str r5, [sp, #0x24] */
/* @0x2b7820 add r4, r4, #1 */
/* @0x2b7824 cmp r9, r4 */
/* @0x2b7828 bge 0x2b76c0 <jinit_merged_upsampler+0x724> */
/* @0x2b782c ldr r12, [sp, #0x14] */
/* @0x2b7830 ldr r5, [sp, #0x34] */
/* @0x2b7834 ldr r6, [sp, #0x38] */
/* @0x2b7838 ldr r0, [r12, #0x18] */
/* @0x2b783c stm r0, {r5, r6} */
/* @0x2b7840 ldr r12, [sp, #0x18] */
/* @0x2b7844 ldr r5, [sp, #0x2c] */
/* @0x2b7848 str r3, [r12, #0xc] */
/* @0x2b784c str r2, [r12, #0x10] */
/* @0x2b7850 str r5, [r12, #0x14] */
/* @0x2b7854 ldr r6, [sp, #0x18] */
/* @0x2b7858 mov r0, #1 */
/* @0x2b785c ldr r3, [r6, #0x28] */
/* @0x2b7860 sub r3, r3, #1 */
/* @0x2b7864 str r3, [r6, #0x28] */
/* @0x2b7868 add sp, sp, #332 */
/* @0x2b786c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7870 str r12, [sp, #0x24] */
/* @0x2b7874 cmp r9, r4 */
/* @0x2b7878 blt 0x2b7a70 <jinit_merged_upsampler+0xad4> */
/* @0x2b787c ldr r1, [pc, #0x234] */
/* @0x2b7880 add r8, sp, #52 */
/* @0x2b7884 ldr r1, [pc, r1] */
/* @0x2b7888 add r1, r1, r4, lsl #2 */
/* @0x2b788c sub r6, r1, #4 */
/* @0x2b7890 mov r1, r3 */
/* @0x2b7894 b 0x2b78dc <jinit_merged_upsampler+0x940> */
/* @0x2b7898 sub r2, r2, #1 */
/* @0x2b789c asr r0, r1, r2 */
/* @0x2b78a0 tst r0, #1 */
/* @0x2b78a4 beq 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78a8 ldrh r0, [r7, r5] */
/* @0x2b78ac sxth r3, r0 */
/* @0x2b78b0 tst r3, r11 */
/* @0x2b78b4 bne 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78b8 cmp r3, #0 */
/* @0x2b78bc add r3, r0, r11 */
/* @0x2b78c0 strhge r3, [r7, r5] */
/* @0x2b78c4 ldrlt r12, [sp, #0x28] */
/* @0x2b78c8 addlt r0, r0, r12 */
/* @0x2b78cc strhlt r0, [r7, r5] */
/* @0x2b78d0 add r4, r4, #1 */
/* @0x2b78d4 cmp r9, r4 */
/* @0x2b78d8 blt 0x2b7a6c <jinit_merged_upsampler+0xad0> */
/* @0x2b78dc ldr r5, [r6, #0x4]! */
/* @0x2b78e0 lsl r5, r5, #1 */
/* @0x2b78e4 ldrsh r12, [r7, r5] */
/* @0x2b78e8 cmp r12, #0 */
/* @0x2b78ec beq 0x2b78d0 <jinit_merged_upsampler+0x934> */
/* @0x2b78f0 cmp r2, #0 */
/* @0x2b78f4 bgt 0x2b7898 <jinit_merged_upsampler+0x8fc> */
/* @0x2b78f8 mov r0, r8 */
/* @0x2b78fc mov r3, #1 */
/* @0x2b7900 bl 0x2bea2c <jpeg_fill_bit_buffer> —— bl jpeg_fill_bit_buffer（补位） */
/* @0x2b7904 cmp r0, #0 */
/* @0x2b7908 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b790c ldr r1, [sp, #0x3c] */
/* @0x2b7910 ldr r2, [sp, #0x40] */
/* @0x2b7914 b 0x2b7898 <jinit_merged_upsampler+0x8fc> */
/* @0x2b7918 add r0, sp, #52 */
/* @0x2b791c mov r3, #1 */
/* @0x2b7920 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7924 cmp r0, #0 */
/* @0x2b7928 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b792c ldr r1, [sp, #0x3c] */
/* @0x2b7930 ldr r2, [sp, #0x40] */
/* @0x2b7934 b 0x2b7788 <jinit_merged_upsampler+0x7ec> */
/* @0x2b7938 cmp r8, #15 */
/* @0x2b793c beq 0x2b7754 <jinit_merged_upsampler+0x7b8> */
/* @0x2b7940 cmp r8, #0 */
/* @0x2b7944 mov r1, #1 */
/* @0x2b7948 lsl r1, r1, r8 */
/* @0x2b794c str r1, [sp, #0x2c] */
/* @0x2b7950 beq 0x2b7974 <jinit_merged_upsampler+0x9d8> */
/* @0x2b7954 cmp r8, r2 */
/* @0x2b7958 bgt 0x2b7a90 <jinit_merged_upsampler+0xaf4> */
/* @0x2b795c ldr r5, [sp, #0x2c] */
/* @0x2b7960 rsb r2, r8, r2 */
/* @0x2b7964 sub r1, r5, #1 */
/* @0x2b7968 and r1, r1, r3, asr r2 */
/* @0x2b796c add r5, r5, r1 */
/* @0x2b7970 str r5, [sp, #0x2c] */
/* @0x2b7974 ldr r5, [sp, #0x2c] */
/* @0x2b7978 cmp r5, #0 */
/* @0x2b797c bne 0x2b7874 <jinit_merged_upsampler+0x8d8> */
/* @0x2b7980 ldr r6, [sp, #0x14] */
/* @0x2b7984 ldr r5, [sp, #0x34] */
/* @0x2b7988 ldr r0, [r6, #0x18] */
/* @0x2b798c ldr r6, [sp, #0x38] */
/* @0x2b7990 b 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b7994 add r5, sp, #52 */
/* @0x2b7998 mov r1, #9 */
/* @0x2b799c str r1, [sp] */
/* @0x2b79a0 mov r0, r5 */
/* @0x2b79a4 mov r1, r3 */
/* @0x2b79a8 ldr r3, [sp, #0x1c] */
/* @0x2b79ac bl 0x2beb8c <jpeg_huff_decode> —— bl jpeg_huff_decode（取 Huffman 码） */
/* @0x2b79b0 cmp r0, #0 */
/* @0x2b79b4 blt 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b79b8 ldr r3, [sp, #0x3c] */
/* @0x2b79bc ldr r2, [sp, #0x40] */
/* @0x2b79c0 b 0x2b76f4 <jinit_merged_upsampler+0x758> */
/* @0x2b79c4 add r5, sp, #52 */
/* @0x2b79c8 mov r1, r3 */
/* @0x2b79cc mov r3, #0 */
/* @0x2b79d0 mov r0, r5 */
/* @0x2b79d4 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b79d8 cmp r0, #0 */
/* @0x2b79dc beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b79e0 ldr r2, [sp, #0x40] */
/* @0x2b79e4 ldr r3, [sp, #0x3c] */
/* @0x2b79e8 cmp r2, #7 */
/* @0x2b79ec bgt 0x2b76c8 <jinit_merged_upsampler+0x72c> */
/* @0x2b79f0 mov r1, #1 */
/* @0x2b79f4 b 0x2b799c <jinit_merged_upsampler+0xa00> */
/* @0x2b79f8 mov r1, r3 */
/* @0x2b79fc add r0, sp, #52 */
/* @0x2b7a00 mov r3, #1 */
/* @0x2b7a04 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7a08 cmp r0, #0 */
/* @0x2b7a0c ldrne r3, [sp, #0x3c] */
/* @0x2b7a10 ldrne r2, [sp, #0x40] */
/* @0x2b7a14 bne 0x2b7740 <jinit_merged_upsampler+0x7a4> */
/* @0x2b7a18 ldr r12, [sp, #0x24] */
/* @0x2b7a1c cmp r12, #0 */
/* @0x2b7a20 beq 0x2b7a48 <jinit_merged_upsampler+0xaac> */
/* @0x2b7a24 ldr r12, [sp, #0x24] */
/* @0x2b7a28 add r1, sp, #72 */
/* @0x2b7a2c mov r0, #0 */
/* @0x2b7a30 add r3, r1, r12, lsl #2 */
/* @0x2b7a34 ldr r2, [r3, #-0x4]! */
/* @0x2b7a38 cmp r3, r1 */
/* @0x2b7a3c lsl r2, r2, #1 */
/* @0x2b7a40 strh r0, [r7, r2] */
/* @0x2b7a44 bne 0x2b7a34 <jinit_merged_upsampler+0xa98> */
/* @0x2b7a48 mov r0, #0 */
/* @0x2b7a4c add sp, sp, #332 */
/* @0x2b7a50 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7a54 str r1, [sp, #0xc] */
/* @0x2b7a58 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> —— bl process_restart（148 B，未卡片：折算 bits_left → marker+0x8 read_restart_marker） */
/* @0x2b7a5c ldr r1, [sp, #0xc] */
/* @0x2b7a60 cmp r0, #0 */
/* @0x2b7a64 bne 0x2b763c <jinit_merged_upsampler+0x6a0> */
/* @0x2b7a68 b 0x2b7a48 <jinit_merged_upsampler+0xaac> */
/* @0x2b7a6c mov r3, r1 */
/* @0x2b7a70 ldr r5, [sp, #0x14] */
/* @0x2b7a74 ldr r6, [sp, #0x2c] */
/* @0x2b7a78 ldr r0, [r5, #0x18] */
/* @0x2b7a7c sub r6, r6, #1 */
/* @0x2b7a80 ldr r5, [sp, #0x34] */
/* @0x2b7a84 str r6, [sp, #0x2c] */
/* @0x2b7a88 ldr r6, [sp, #0x38] */
/* @0x2b7a8c b 0x2b783c <jinit_merged_upsampler+0x8a0> */
/* @0x2b7a90 mov r1, r3 */
/* @0x2b7a94 add r0, sp, #52 */
/* @0x2b7a98 mov r3, r8 */
/* @0x2b7a9c bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7aa0 cmp r0, #0 */
/* @0x2b7aa4 beq 0x2b7a18 <jinit_merged_upsampler+0xa7c> */
/* @0x2b7aa8 ldr r3, [sp, #0x3c] */
/* @0x2b7aac ldr r2, [sp, #0x40] */
/* @0x2b7ab0 b 0x2b795c <jinit_merged_upsampler+0x9c0> */
/* @0x2b7ab4 andseq r10, r3, r4, asr #6 */
/* @0x2b7ab8 andseq r10, r3, r4, lsr #4 */
/* @0x2b7abc ldr r3, [r0, #0xfc] */

/* ═══ §7 anon_2b7ac0（同族，见上）═══ */
/* @func 0x2b7ac0 0x2b7d50 anon_2b7ac0 phuff_decode_mcu_ac_a */
/* @0x2b7ac0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（164 条，循环体最短） */
/* @0x2b7ac4 cmp r3, #0 */
/* @0x2b7ac8 sub sp, sp, #52 */
/* @0x2b7acc mov r8, r0 */
/* @0x2b7ad0 ldr r7, [r0, #0x198] */
/* @0x2b7ad4 ldr r9, [r0, #0x170] */
/* @0x2b7ad8 ldr r11, [r0, #0x178] */
/* @0x2b7adc beq 0x2b7aec <jinit_merged_upsampler+0xb50> */
/* @0x2b7ae0 ldr r3, [r7, #0x28] */
/* @0x2b7ae4 cmp r3, #0 */
/* @0x2b7ae8 beq 0x2b7cec <jinit_merged_upsampler+0xd50> */
/* @0x2b7aec ldrb r3, [r7, #0x8] */
/* @0x2b7af0 cmp r3, #0 */
/* @0x2b7af4 bne 0x2b7c58 <jinit_merged_upsampler+0xcbc> */
/* @0x2b7af8 ldr r3, [r7, #0x14] */
/* @0x2b7afc cmp r3, #0 */
/* @0x2b7b00 str r3, [sp, #0x10] */
/* @0x2b7b04 subne r3, r3, #1 */
/* @0x2b7b08 strne r3, [sp, #0x10] */
/* @0x2b7b0c bne 0x2b7c50 <jinit_merged_upsampler+0xcb4> */
/* @0x2b7b10 ldr r3, [r8, #0x18] */
/* @0x2b7b14 ldr r5, [r8, #0x16c] */
/* @0x2b7b18 ldr r4, [r1] */
/* @0x2b7b1c ldr r0, [r3] */
/* @0x2b7b20 cmp r9, r5 */
/* @0x2b7b24 ldr r12, [r3, #0x4] */
/* @0x2b7b28 str r8, [sp, #0x2c] */
/* @0x2b7b2c str r0, [sp, #0x1c] */
/* @0x2b7b30 str r12, [sp, #0x20] */
/* @0x2b7b34 ldr r1, [r7, #0xc] */
/* @0x2b7b38 ldr r2, [r7, #0x10] */
/* @0x2b7b3c ldr r6, [r7, #0x3c] */
/* @0x2b7b40 blt 0x2b7c44 <jinit_merged_upsampler+0xca8> */
/* @0x2b7b44 ldr r10, [pc, #0x1fc] */
/* @0x2b7b48 str r7, [sp, #0x14] */
/* @0x2b7b4c mov r7, r5 */
/* @0x2b7b50 add r10, pc, r10 */
/* @0x2b7b54 mov r5, r4 */
/* @0x2b7b58 b 0x2b7bb4 <jinit_merged_upsampler+0xc18> */
/* @0x2b7b5c cmp r2, r4 */
/* @0x2b7b60 add r7, r7, r0 */
/* @0x2b7b64 blt 0x2b7ccc <jinit_merged_upsampler+0xd30> */
/* @0x2b7b68 mov r3, #1 */
/* @0x2b7b6c rsb r2, r4, r2 */
/* @0x2b7b70 lsl r0, r3, r4 */
/* @0x2b7b74 ldr r3, [r10, r4, lsl #2] */
/* @0x2b7b78 sub r0, r0, #1 */
/* @0x2b7b7c and r0, r0, r1, asr r2 */
/* @0x2b7b80 cmp r0, r3 */
/* @0x2b7b84 addlt r4, r10, r4, lsl #2 */
/* @0x2b7b88 ldrlt r3, [r4, #0x40] */
/* @0x2b7b8c addlt r0, r0, r3 */
/* @0x2b7b90 ldr r3, [pc, #0x1b4] */
/* @0x2b7b94 ldr r3, [pc, r3] */
/* @0x2b7b98 lsl r0, r0, r11 */
/* @0x2b7b9c ldr r3, [r3, r7, lsl #2] */
/* @0x2b7ba0 lsl r3, r3, #1 */
/* @0x2b7ba4 strh r0, [r5, r3] */
/* @0x2b7ba8 add r7, r7, #1 */
/* @0x2b7bac cmp r9, r7 */
/* @0x2b7bb0 blt 0x2b7d0c <jinit_merged_upsampler+0xd70> */
/* @0x2b7bb4 cmp r2, #7 */
/* @0x2b7bb8 ble 0x2b7c9c <jinit_merged_upsampler+0xd00> */
/* @0x2b7bbc sub r0, r2, #8 */
/* @0x2b7bc0 asr r0, r1, r0 */
/* @0x2b7bc4 uxtb r0, r0 */
/* @0x2b7bc8 add r3, r0, #36 */
/* @0x2b7bcc ldr r3, [r6, r3, lsl #2] */
/* @0x2b7bd0 cmp r3, #0 */
/* @0x2b7bd4 beq 0x2b7c70 <jinit_merged_upsampler+0xcd4> */
/* @0x2b7bd8 add r0, r6, r0 */
/* @0x2b7bdc rsb r2, r3, r2 */
/* @0x2b7be0 ldrb r0, [r0, #0x490] */
/* @0x2b7be4 ands r4, r0, #15 */
/* @0x2b7be8 asr r0, r0, #4 */
/* @0x2b7bec bne 0x2b7b5c <jinit_merged_upsampler+0xbc0> */
/* @0x2b7bf0 cmp r0, #15 */
/* @0x2b7bf4 addeq r7, r7, #15 */
/* @0x2b7bf8 beq 0x2b7ba8 <jinit_merged_upsampler+0xc0c> */
/* @0x2b7bfc mov r4, #1 */
/* @0x2b7c00 cmp r0, #0 */
/* @0x2b7c04 lsl r4, r4, r0 */
/* @0x2b7c08 ldr r7, [sp, #0x14] */
/* @0x2b7c0c mov r12, r0 */
/* @0x2b7c10 mov r3, r4 */
/* @0x2b7c14 beq 0x2b7c30 <jinit_merged_upsampler+0xc94> */
/* @0x2b7c18 cmp r0, r2 */
/* @0x2b7c1c bgt 0x2b7d20 <jinit_merged_upsampler+0xd84> */
/* @0x2b7c20 rsb r2, r12, r2 */
/* @0x2b7c24 sub r3, r4, #1 */
/* @0x2b7c28 and r3, r3, r1, asr r2 */
/* @0x2b7c2c add r3, r4, r3 */
/* @0x2b7c30 sub r3, r3, #1 */
/* @0x2b7c34 ldr r0, [sp, #0x1c] */
/* @0x2b7c38 str r3, [sp, #0x10] */
/* @0x2b7c3c ldr r12, [sp, #0x20] */
/* @0x2b7c40 ldr r3, [r8, #0x18] */
/* @0x2b7c44 stm r3, {r0, r12} */
/* @0x2b7c48 str r1, [r7, #0xc] */
/* @0x2b7c4c str r2, [r7, #0x10] */
/* @0x2b7c50 ldr r3, [sp, #0x10] */
/* @0x2b7c54 str r3, [r7, #0x14] */
/* @0x2b7c58 ldr r3, [r7, #0x28] */
/* @0x2b7c5c mov r0, #1 */
/* @0x2b7c60 sub r3, r3, #1 */
/* @0x2b7c64 str r3, [r7, #0x28] */
/* @0x2b7c68 add sp, sp, #52 */
/* @0x2b7c6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7c70 add r4, sp, #28 */
/* @0x2b7c74 mov r3, #9 */
/* @0x2b7c78 str r3, [sp] */
/* @0x2b7c7c mov r0, r4 */
/* @0x2b7c80 mov r3, r6 */
/* @0x2b7c84 bl 0x2beb8c <jpeg_huff_decode> —— bl jpeg_huff_decode（取 Huffman 码） */
/* @0x2b7c88 cmp r0, #0 */
/* @0x2b7c8c blt 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7c90 ldr r1, [sp, #0x24] */
/* @0x2b7c94 ldr r2, [sp, #0x28] */
/* @0x2b7c98 b 0x2b7be4 <jinit_merged_upsampler+0xc48> */
/* @0x2b7c9c add r4, sp, #28 */
/* @0x2b7ca0 mov r3, #0 */
/* @0x2b7ca4 mov r0, r4 */
/* @0x2b7ca8 bl 0x2bea2c <jpeg_fill_bit_buffer> —— bl jpeg_fill_bit_buffer（补位） */
/* @0x2b7cac cmp r0, #0 */
/* @0x2b7cb0 beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7cb4 ldr r2, [sp, #0x28] */
/* @0x2b7cb8 ldr r1, [sp, #0x24] */
/* @0x2b7cbc cmp r2, #7 */
/* @0x2b7cc0 bgt 0x2b7bbc <jinit_merged_upsampler+0xc20> */
/* @0x2b7cc4 mov r3, #1 */
/* @0x2b7cc8 b 0x2b7c78 <jinit_merged_upsampler+0xcdc> */
/* @0x2b7ccc add r0, sp, #28 */
/* @0x2b7cd0 mov r3, r4 */
/* @0x2b7cd4 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7cd8 cmp r0, #0 */
/* @0x2b7cdc beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7ce0 ldr r1, [sp, #0x24] */
/* @0x2b7ce4 ldr r2, [sp, #0x28] */
/* @0x2b7ce8 b 0x2b7b68 <jinit_merged_upsampler+0xbcc> */
/* @0x2b7cec str r1, [sp, #0xc] */
/* @0x2b7cf0 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> —— bl process_restart（148 B，未卡片：折算 bits_left → marker+0x8 read_restart_marker） */
/* @0x2b7cf4 ldr r1, [sp, #0xc] */
/* @0x2b7cf8 cmp r0, #0 */
/* @0x2b7cfc bne 0x2b7aec <jinit_merged_upsampler+0xb50> */
/* @0x2b7d00 mov r0, #0 */
/* @0x2b7d04 add sp, sp, #52 */
/* @0x2b7d08 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7d0c ldr r7, [sp, #0x14] */
/* @0x2b7d10 ldr r3, [r8, #0x18] */
/* @0x2b7d14 ldr r0, [sp, #0x1c] */
/* @0x2b7d18 ldr r12, [sp, #0x20] */
/* @0x2b7d1c b 0x2b7c44 <jinit_merged_upsampler+0xca8> */
/* @0x2b7d20 mov r3, r12 */
/* @0x2b7d24 add r0, sp, #28 */
/* @0x2b7d28 str r12, [sp, #0xc] */
/* @0x2b7d2c bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7d30 ldr r12, [sp, #0xc] */
/* @0x2b7d34 cmp r0, #0 */
/* @0x2b7d38 beq 0x2b7d00 <jinit_merged_upsampler+0xd64> */
/* @0x2b7d3c ldr r1, [sp, #0x24] */
/* @0x2b7d40 ldr r2, [sp, #0x28] */
/* @0x2b7d44 b 0x2b7c20 <jinit_merged_upsampler+0xc84> */
/* @0x2b7d48 strdeq r8, r9, [sp], -r0 */
/* @0x2b7d4c andseq r9, r3, r4, lsl pc */

/* ═══ §8 anon_2b7d50（同族，见上）═══ */
/* @func 0x2b7d50 0x2b7fd8 anon_2b7d50 phuff_decode_mcu_ac_b */
/* @0x2b7d50 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（162 条；读 cinfo+0x1d8 = natural_order） */
/* @0x2b7d54 sub sp, sp, #76 */
/* @0x2b7d58 ldr r5, [r0, #0x198] */
/* @0x2b7d5c mov r9, r0 */
/* @0x2b7d60 ldr r3, [r0, #0xfc] */
/* @0x2b7d64 mov r6, r1 */
/* @0x2b7d68 str r5, [sp, #0x10] */
/* @0x2b7d6c cmp r3, #0 */
/* @0x2b7d70 ldr r5, [r0, #0x178] */
/* @0x2b7d74 str r5, [sp, #0x14] */
/* @0x2b7d78 beq 0x2b7d8c <jinit_merged_upsampler+0xdf0> */
/* @0x2b7d7c ldr r5, [sp, #0x10] */
/* @0x2b7d80 ldr r3, [r5, #0x28] */
/* @0x2b7d84 cmp r3, #0 */
/* @0x2b7d88 beq 0x2b7fb8 <jinit_merged_upsampler+0x101c> */
/* @0x2b7d8c ldr r5, [sp, #0x10] */
/* @0x2b7d90 ldrb r7, [r5, #0x8] */
/* @0x2b7d94 cmp r7, #0 */
/* @0x2b7d98 bne 0x2b7f44 <jinit_merged_upsampler+0xfa8> */
/* @0x2b7d9c ldr r5, [sp, #0x10] */
/* @0x2b7da0 ldr r8, [r9, #0x140] */
/* @0x2b7da4 add r5, r5, #20 */
/* @0x2b7da8 str r5, [sp, #0x18] */
/* @0x2b7dac ldr r4, [sp, #0x18] */
/* @0x2b7db0 add r5, sp, #52 */
/* @0x2b7db4 str r5, [sp, #0x1c] */
/* @0x2b7db8 cmp r8, #0 */
/* @0x2b7dbc mov r12, r5 */
/* @0x2b7dc0 ldr r5, [r9, #0x18] */
/* @0x2b7dc4 ldm r4!, {r0, r1, r2, r3} */
/* @0x2b7dc8 ldr r8, [r5] */
/* @0x2b7dcc str r9, [sp, #0x30] */
/* @0x2b7dd0 stm r12!, {r0, r1, r2, r3} */
/* @0x2b7dd4 ldr r4, [r4] */
/* @0x2b7dd8 ldr r0, [sp, #0x10] */
/* @0x2b7ddc ldr r3, [r5, #0x4] */
/* @0x2b7de0 str r4, [r12] */
/* @0x2b7de4 str r8, [sp, #0x20] */
/* @0x2b7de8 str r3, [sp, #0x24] */
/* @0x2b7dec ldr r4, [r0, #0xc] */
/* @0x2b7df0 ldr r12, [r0, #0x10] */
/* @0x2b7df4 ble 0x2b7fd0 <jinit_merged_upsampler+0x1034> */
/* @0x2b7df8 ldr r8, [pc, #0x1d8] */
/* @0x2b7dfc mov r1, r4 */
/* @0x2b7e00 sub r11, r6, #4 */
/* @0x2b7e04 mov r5, r9 */
/* @0x2b7e08 add r8, pc, r8 */
/* @0x2b7e0c mov r2, r12 */
/* @0x2b7e10 mov r4, r8 */
/* @0x2b7e14 b 0x2b7e94 <jinit_merged_upsampler+0xef8> */
/* @0x2b7e18 add r8, r8, r0 */
/* @0x2b7e1c rsb r2, r3, r2 */
/* @0x2b7e20 ldrb r8, [r8, #0x490] */
/* @0x2b7e24 cmp r8, #0 */
/* @0x2b7e28 beq 0x2b7e60 <jinit_merged_upsampler+0xec4> */
/* @0x2b7e2c cmp r8, r2 */
/* @0x2b7e30 bgt 0x2b7f98 <jinit_merged_upsampler+0xffc> */
/* @0x2b7e34 mov r0, #1 */
/* @0x2b7e38 rsb r2, r8, r2 */
/* @0x2b7e3c lsl r3, r0, r8 */
/* @0x2b7e40 ldr r0, [r4, r8, lsl #2] */
/* @0x2b7e44 sub r3, r3, #1 */
/* @0x2b7e48 and r3, r3, r1, asr r2 */
/* @0x2b7e4c cmp r3, r0 */
/* @0x2b7e50 addlt r8, r4, r8, lsl #2 */
/* @0x2b7e54 movge r8, r3 */
/* @0x2b7e58 ldrlt r8, [r8, #0x40] */
/* @0x2b7e5c addlt r8, r8, r3 */
/* @0x2b7e60 add r3, sp, #72 */
/* @0x2b7e64 ldr r0, [r9, #0x140] */
/* @0x2b7e68 add r6, r3, r6, lsl #2 */
/* @0x2b7e6c add r7, r7, #1 */
/* @0x2b7e70 cmp r0, r7 */
/* @0x2b7e74 ldr r0, [sp, #0x14] */
/* @0x2b7e78 ldr r3, [r6, #-0x10] */
/* @0x2b7e7c add r5, r5, #4 */
/* @0x2b7e80 add r8, r8, r3 */
/* @0x2b7e84 str r8, [r6, #-0x10] */
/* @0x2b7e88 lsl r8, r8, r0 */
/* @0x2b7e8c strh r8, [r10] */
/* @0x2b7e90 ble 0x2b7f04 <jinit_merged_upsampler+0xf68> */
/* @0x2b7e94 ldr r6, [r5, #0x144] */
/* @0x2b7e98 cmp r2, #7 */
/* @0x2b7e9c ldr r0, [sp, #0x10] */
/* @0x2b7ea0 add r3, r6, #74 */
/* @0x2b7ea4 ldr r10, [r11, #0x4]! */
/* @0x2b7ea8 ldr r3, [r9, r3, lsl #2] */
/* @0x2b7eac ldr r3, [r3, #0x14] */
/* @0x2b7eb0 add r3, r0, r3, lsl #2 */
/* @0x2b7eb4 ldr r8, [r3, #0x2c] */
/* @0x2b7eb8 ble 0x2b7f60 <jinit_merged_upsampler+0xfc4> */
/* @0x2b7ebc sub r0, r2, #8 */
/* @0x2b7ec0 asr r0, r1, r0 */
/* @0x2b7ec4 uxtb r0, r0 */
/* @0x2b7ec8 add r3, r0, #36 */
/* @0x2b7ecc ldr r3, [r8, r3, lsl #2] */
/* @0x2b7ed0 cmp r3, #0 */
/* @0x2b7ed4 bne 0x2b7e18 <jinit_merged_upsampler+0xe7c> */
/* @0x2b7ed8 add r12, sp, #32 */
/* @0x2b7edc mov r3, #9 */
/* @0x2b7ee0 str r3, [sp] */
/* @0x2b7ee4 mov r0, r12 */
/* @0x2b7ee8 mov r3, r8 */
/* @0x2b7eec bl 0x2beb8c <jpeg_huff_decode> —— bl jpeg_huff_decode（取 Huffman 码） */
/* @0x2b7ef0 subs r8, r0, #0 */
/* @0x2b7ef4 blt 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7ef8 ldr r1, [sp, #0x28] */
/* @0x2b7efc ldr r2, [sp, #0x2c] */
/* @0x2b7f00 b 0x2b7e24 <jinit_merged_upsampler+0xe88> */
/* @0x2b7f04 ldr r5, [r9, #0x18] */
/* @0x2b7f08 mov r4, r1 */
/* @0x2b7f0c ldr r8, [sp, #0x20] */
/* @0x2b7f10 mov r12, r2 */
/* @0x2b7f14 ldr r7, [sp, #0x24] */
/* @0x2b7f18 add r9, sp, #52 */
/* @0x2b7f1c str r8, [r5] */
/* @0x2b7f20 str r7, [r5, #0x4] */
/* @0x2b7f24 ldm r9!, {r0, r1, r2, r3} */
/* @0x2b7f28 ldr r5, [sp, #0x10] */
/* @0x2b7f2c ldr r6, [sp, #0x18] */
/* @0x2b7f30 str r4, [r5, #0xc] */
/* @0x2b7f34 ldr r4, [r9] */
/* @0x2b7f38 str r12, [r5, #0x10] */
/* @0x2b7f3c stm r6!, {r0, r1, r2, r3} */
/* @0x2b7f40 str r4, [r6] */
/* @0x2b7f44 ldr r5, [sp, #0x10] */
/* @0x2b7f48 mov r0, #1 */
/* @0x2b7f4c ldr r3, [r5, #0x28] */
/* @0x2b7f50 sub r3, r3, #1 */
/* @0x2b7f54 str r3, [r5, #0x28] */
/* @0x2b7f58 add sp, sp, #76 */
/* @0x2b7f5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7f60 add r12, sp, #32 */
/* @0x2b7f64 mov r3, #0 */
/* @0x2b7f68 str r12, [sp, #0xc] */
/* @0x2b7f6c mov r0, r12 */
/* @0x2b7f70 bl 0x2bea2c <jpeg_fill_bit_buffer> —— bl jpeg_fill_bit_buffer（补位） */
/* @0x2b7f74 ldr r12, [sp, #0xc] */
/* @0x2b7f78 cmp r0, #0 */
/* @0x2b7f7c beq 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7f80 ldr r2, [sp, #0x2c] */
/* @0x2b7f84 ldr r1, [sp, #0x28] */
/* @0x2b7f88 cmp r2, #7 */
/* @0x2b7f8c bgt 0x2b7ebc <jinit_merged_upsampler+0xf20> */
/* @0x2b7f90 mov r3, #1 */
/* @0x2b7f94 b 0x2b7ee0 <jinit_merged_upsampler+0xf44> */
/* @0x2b7f98 add r0, sp, #32 */
/* @0x2b7f9c mov r3, r8 */
/* @0x2b7fa0 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2b7fa4 cmp r0, #0 */
/* @0x2b7fa8 beq 0x2b7fc4 <jinit_merged_upsampler+0x1028> */
/* @0x2b7fac ldr r1, [sp, #0x28] */
/* @0x2b7fb0 ldr r2, [sp, #0x2c] */
/* @0x2b7fb4 b 0x2b7e34 <jinit_merged_upsampler+0xe98> */
/* @0x2b7fb8 bl 0x2b7148 <jinit_merged_upsampler+0x1ac> —— bl process_restart（148 B，未卡片：折算 bits_left → marker+0x8 read_restart_marker） */
/* @0x2b7fbc cmp r0, #0 */
/* @0x2b7fc0 bne 0x2b7d8c <jinit_merged_upsampler+0xdf0> */
/* @0x2b7fc4 mov r0, #0 */
/* @0x2b7fc8 add sp, sp, #76 */
/* @0x2b7fcc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2b7fd0 mov r7, r3 */
/* @0x2b7fd4 b 0x2b7f18 <jinit_merged_upsampler+0xf7c> */

/* ═══════════════════════════════════════════════════════════════════════
 * §9  anon_2bec98 = jdhuff.c decode_mcu（基线 Huffman，整 MCU 解码）
 * ═══════════════════════════════════════════════════════════════════════
 * 契约：boolean decode_mcu(j_decompress_ptr cinfo, JBLOCKROW *MCU_data)——
 *       r0 = cinfo、r1 = MCU_data（块指针数组）；返回 1（成功）/0（数据不够，挂起）。
 *
 * 身份证据（三条）
 *   ① 安装点：jinit_huff_decoder(0x2bf19c) 的两个池字 0xfffff6e4 / 0xfffffac4 分别经
 *      0x2bf1c4/0x2bf1c8 的 `add rX,pc,rX`（pc=0x2bf1cc / 0x2bf1d0）算出 0x2be8b0 与
 *      0x2bec94，0x2bf1d0 `stm r0,{r1,r2}` 写进 entropy+0x0/+0x4
 *      ⇒ 槽 #0 = 0x2be8b0（start_pass_huff_decoder，372 B，本卡未收）、
 *        槽 #1 = 0x2bec94（decode_mcu，真入口比本段起点早 4 B）。
 *   ② 体内三处 `bl jpeg_huff_decode` + 六处 `bl jpeg_fill_bit_buffer`：基线解码的
 *      bit 缓冲协议（先补满 25+ bit，再按 derived table 取码）。
 *   ③ 0x2bf0fc / 0x2bef18 两个大分支 = "无重启间隔" 与 "走到重启点" 两条路（对应
 *      restart_interval == 0 / != 0），与 jdhuff.c 的 decode_mcu 结构一致。
 *
 * 它调谁：jpeg_fill_bit_buffer(0x2bea2c) ×6、jpeg_huff_decode(0x2beb8c) ×3
 * 谁调它：jinit_huff_decoder 写槽；0 处直接 bl
 * 边界：单函数，出口 0x2bef2c / 0x2bf09c；0x2bf190/0x2bf194 是池字（strheq/andeq）。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2bec98 0x2bf198 anon_2bec98 decode_mcu */

/* @0x2bec98 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 入口（真入口 0x2bec94，比本段起点早 4 B） */
/* @0x2bec9c cmp r3, #0 */
/* @0x2beca0 sub sp, sp, #84 */
/* @0x2beca4 mov r10, r0 */
/* @0x2beca8 mov r6, r1 */
/* @0x2becac ldr r9, [r0, #0x198] */
/* @0x2becb0 beq 0x2becc0 <jpeg_huff_decode+0x134> */
/* @0x2becb4 ldr r4, [r9, #0x24] */
/* @0x2becb8 cmp r4, #0 */
/* @0x2becbc beq 0x2bf0fc <jpeg_huff_decode+0x570> */
/* @0x2becc0 ldrb r3, [r9, #0x8] */
/* @0x2becc4 cmp r3, #0 */
/* @0x2becc8 bne 0x2bef18 <jpeg_huff_decode+0x38c> */
/* @0x2beccc add r4, r9, #20 */
/* @0x2becd0 str r4, [sp, #0x10] */
/* @0x2becd4 add r4, sp, #44 */
/* @0x2becd8 str r4, [sp, #0x14] */
/* @0x2becdc ldr r4, [sp, #0x10] */
/* @0x2bece0 ldr r5, [r10, #0x18] */
/* @0x2bece4 ldr r12, [r10, #0x140] */
/* @0x2bece8 ldm r4, {r0, r1, r2, r3} */
/* @0x2becec cmp r12, #0 */
/* @0x2becf0 ldm r5, {r7, r8} */
/* @0x2becf4 ldr r12, [sp, #0x14] */
/* @0x2becf8 str r10, [sp, #0x4c] */
/* @0x2becfc str r7, [sp, #0x3c] */
/* @0x2bed00 stm r12, {r0, r1, r2, r3} */
/* @0x2bed04 str r8, [sp, #0x40] */
/* @0x2bed08 ldr r4, [r9, #0xc] */
/* @0x2bed0c ldr r12, [r9, #0x10] */
/* @0x2bed10 ble 0x2beefc <jpeg_huff_decode+0x370> */
/* @0x2bed14 ldr r7, [pc, #0x474] */
/* @0x2bed18 mov r8, r9 */
/* @0x2bed1c ldr r0, [pc, #0x470] */
/* @0x2bed20 mov r1, r4 */
/* @0x2bed24 add r7, pc, r7 */
/* @0x2bed28 mov r2, r12 */
/* @0x2bed2c mov r4, r10 */
/* @0x2bed30 mov r11, r8 */
/* @0x2bed34 add r0, pc, r0 */
/* @0x2bed38 sub r6, r6, #4 */
/* @0x2bed3c mov r3, #0 */
/* @0x2bed40 str r0, [sp, #0x1c] */
/* @0x2bed44 str r6, [sp, #0xc] */
/* @0x2bed48 str r3, [sp, #0x18] */
/* @0x2bed4c str r9, [sp, #0x24] */
/* @0x2bed50 str r10, [sp, #0x20] */
/* @0x2bed54 ldr r6, [sp, #0xc] */
/* @0x2bed58 cmp r2, #7 */
/* @0x2bed5c ldr r5, [r9, #0x70] */
/* @0x2bed60 ldr r8, [r6, #0x4]! */
/* @0x2bed64 str r6, [sp, #0xc] */
/* @0x2bed68 ldr r6, [r9, #0x48] */
/* @0x2bed6c ble 0x2bf0cc <jpeg_huff_decode+0x540> */
/* @0x2bed70 sub r0, r2, #8 */
/* @0x2bed74 asr r0, r1, r0 */
/* @0x2bed78 uxtb r0, r0 */
/* @0x2bed7c add r3, r0, #36 */
/* @0x2bed80 ldr r3, [r6, r3, lsl #2] */
/* @0x2bed84 cmp r3, #0 */
/* @0x2bed88 beq 0x2bf0a0 <jpeg_huff_decode+0x514> */
/* @0x2bed8c add r0, r6, r0 */
/* @0x2bed90 rsb r2, r3, r2 */
/* @0x2bed94 ldrb r6, [r0, #0x490] */
/* @0x2bed98 cmp r6, #0 */
/* @0x2bed9c beq 0x2bedd8 <jpeg_huff_decode+0x24c> */
/* @0x2beda0 cmp r2, r6 */
/* @0x2beda4 blt 0x2bf170 <jpeg_huff_decode+0x5e4> */
/* @0x2beda8 mov r12, #1 */
/* @0x2bedac rsb r2, r6, r2 */
/* @0x2bedb0 lsl r3, r12, r6 */
/* @0x2bedb4 ldr r12, [sp, #0x1c] */
/* @0x2bedb8 sub r3, r3, #1 */
/* @0x2bedbc and r3, r3, r1, asr r2 */
/* @0x2bedc0 ldr r0, [r12, r6, lsl #2] */
/* @0x2bedc4 cmp r3, r0 */
/* @0x2bedc8 addlt r6, r12, r6, lsl #2 */
/* @0x2bedcc movge r6, r3 */
/* @0x2bedd0 ldrlt r6, [r6, #0x40] */
/* @0x2bedd4 addlt r6, r6, r3 */
/* @0x2bedd8 ldrb r3, [r11, #0x98] */
/* @0x2beddc cmp r3, #0 */
/* @0x2bede0 beq 0x2bee00 <jpeg_huff_decode+0x274> */
/* @0x2bede4 ldr r3, [r4, #0x144] */
/* @0x2bede8 add r0, sp, #80 */
/* @0x2bedec add r3, r0, r3, lsl #2 */
/* @0x2bedf0 ldr r0, [r3, #-0x24] */
/* @0x2bedf4 add r6, r6, r0 */
/* @0x2bedf8 str r6, [r3, #-0x24] */
/* @0x2bedfc strh r6, [r8] */
/* @0x2bee00 ldrb r3, [r11, #0xa2] */
/* @0x2bee04 cmp r3, #0 */
/* @0x2bee08 beq 0x2befac <jpeg_huff_decode+0x420> */
/* @0x2bee0c mov r10, #1 */
/* @0x2bee10 b 0x2bee68 <jpeg_huff_decode+0x2dc> */
/* @0x2bee14 cmp r2, r6 */
/* @0x2bee18 add r10, r10, r0 */
/* @0x2bee1c blt 0x2bef8c <jpeg_huff_decode+0x400> */
/* @0x2bee20 mov r12, #1 */
/* @0x2bee24 ldr r0, [r7, r6, lsl #2] */
/* @0x2bee28 lsl r3, r12, r6 */
/* @0x2bee2c rsb r2, r6, r2 */
/* @0x2bee30 sub r3, r3, #1 */
/* @0x2bee34 and r3, r3, r1, asr r2 */
/* @0x2bee38 cmp r3, r0 */
/* @0x2bee3c addlt r6, r7, r6, lsl #2 */
/* @0x2bee40 ldrlt r0, [r6, #0x40] */
/* @0x2bee44 addlt r3, r3, r0 */
/* @0x2bee48 ldr r0, [pc, #0x348] */
/* @0x2bee4c ldr r0, [pc, r0] */
/* @0x2bee50 ldr r0, [r0, r10, lsl #2] */
/* @0x2bee54 add r10, r10, #1 */
/* @0x2bee58 cmp r10, #63 */
/* @0x2bee5c lsl r0, r0, #1 */
/* @0x2bee60 strh r3, [r8, r0] */
/* @0x2bee64 bgt 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2bee68 cmp r2, #7 */
/* @0x2bee6c ble 0x2bef5c <jpeg_huff_decode+0x3d0> */
/* @0x2bee70 sub r0, r2, #8 */
/* @0x2bee74 asr r0, r1, r0 */
/* @0x2bee78 uxtb r0, r0 */
/* @0x2bee7c add r3, r0, #36 */
/* @0x2bee80 ldr r3, [r5, r3, lsl #2] */
/* @0x2bee84 cmp r3, #0 */
/* @0x2bee88 beq 0x2bef30 <jpeg_huff_decode+0x3a4> */
/* @0x2bee8c add r0, r5, r0 */
/* @0x2bee90 rsb r2, r3, r2 */
/* @0x2bee94 ldrb r0, [r0, #0x490] */
/* @0x2bee98 ands r6, r0, #15 */
/* @0x2bee9c asr r0, r0, #4 */
/* @0x2beea0 bne 0x2bee14 <jpeg_huff_decode+0x288> */
/* @0x2beea4 cmp r0, #15 */
/* @0x2beea8 bne 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2beeac add r10, r10, #15 */
/* @0x2beeb0 add r10, r10, #1 */
/* @0x2beeb4 cmp r10, #63 */
/* @0x2beeb8 ble 0x2bee68 <jpeg_huff_decode+0x2dc> */
/* @0x2beebc ldr r6, [sp, #0x20] */
/* @0x2beec0 add r9, r9, #4 */
/* @0x2beec4 ldr r12, [sp, #0x18] */
/* @0x2beec8 add r11, r11, #1 */
/* @0x2beecc add r4, r4, #4 */
/* @0x2beed0 ldr r3, [r6, #0x140] */
/* @0x2beed4 add r12, r12, #1 */
/* @0x2beed8 str r12, [sp, #0x18] */
/* @0x2beedc cmp r3, r12 */
/* @0x2beee0 bgt 0x2bed54 <jpeg_huff_decode+0x1c8> */
/* @0x2beee4 ldr r9, [sp, #0x24] */
/* @0x2beee8 mov r4, r1 */
/* @0x2beeec ldr r5, [r6, #0x18] */
/* @0x2beef0 mov r12, r2 */
/* @0x2beef4 ldr r7, [sp, #0x3c] */
/* @0x2beef8 ldr r8, [sp, #0x40] */
/* @0x2beefc ldr r6, [sp, #0x14] */
/* @0x2bef00 stm r5, {r7, r8} */
/* @0x2bef04 str r12, [r9, #0x10] */
/* @0x2bef08 ldm r6, {r0, r1, r2, r3} */
/* @0x2bef0c ldr r12, [sp, #0x10] */
/* @0x2bef10 str r4, [r9, #0xc] */
/* @0x2bef14 stm r12, {r0, r1, r2, r3} */
/* @0x2bef18 ldr r3, [r9, #0x24] —— 走到重启点的分支 */
/* @0x2bef1c mov r0, #1 */
/* @0x2bef20 sub r3, r3, #1 */
/* @0x2bef24 str r3, [r9, #0x24] */
/* @0x2bef28 add sp, sp, #84 */
/* @0x2bef2c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 1 */
/* @0x2bef30 add r6, sp, #60 */
/* @0x2bef34 mov r3, #9 */
/* @0x2bef38 str r3, [sp] */
/* @0x2bef3c mov r0, r6 */
/* @0x2bef40 mov r3, r5 */
/* @0x2bef44 bl 0x2beb8c <jpeg_huff_decode> —— bl jpeg_huff_decode（取 Huffman 码） */
/* @0x2bef48 cmp r0, #0 */
/* @0x2bef4c blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bef50 ldr r1, [sp, #0x44] */
/* @0x2bef54 ldr r2, [sp, #0x48] */
/* @0x2bef58 b 0x2bee98 <jpeg_huff_decode+0x30c> */
/* @0x2bef5c add r6, sp, #60 */
/* @0x2bef60 mov r3, #0 */
/* @0x2bef64 mov r0, r6 */
/* @0x2bef68 bl 0x2bea2c <jpeg_fill_bit_buffer> —— bl jpeg_fill_bit_buffer（补位） */
/* @0x2bef6c cmp r0, #0 */
/* @0x2bef70 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bef74 ldr r2, [sp, #0x48] */
/* @0x2bef78 ldr r1, [sp, #0x44] */
/* @0x2bef7c cmp r2, #7 */
/* @0x2bef80 bgt 0x2bee70 <jpeg_huff_decode+0x2e4> */
/* @0x2bef84 mov r3, #1 */
/* @0x2bef88 b 0x2bef38 <jpeg_huff_decode+0x3ac> */
/* @0x2bef8c add r0, sp, #60 */
/* @0x2bef90 mov r3, r6 */
/* @0x2bef94 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bef98 cmp r0, #0 */
/* @0x2bef9c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2befa0 ldr r1, [sp, #0x44] */
/* @0x2befa4 ldr r2, [sp, #0x48] */
/* @0x2befa8 b 0x2bee20 <jpeg_huff_decode+0x294> */
/* @0x2befac mov r6, #1 */
/* @0x2befb0 b 0x2befd0 <jpeg_huff_decode+0x444> */
/* @0x2befb4 cmp r2, r8 */
/* @0x2befb8 add r6, r6, r0 */
/* @0x2befbc blt 0x2bf078 <jpeg_huff_decode+0x4ec> */
/* @0x2befc0 rsb r2, r8, r2 */
/* @0x2befc4 add r6, r6, #1 */
/* @0x2befc8 cmp r6, #63 */
/* @0x2befcc bgt 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2befd0 cmp r2, #7 */
/* @0x2befd4 ble 0x2bf048 <jpeg_huff_decode+0x4bc> */
/* @0x2befd8 sub r0, r2, #8 */
/* @0x2befdc asr r0, r1, r0 */
/* @0x2befe0 uxtb r0, r0 */
/* @0x2befe4 add r3, r0, #36 */
/* @0x2befe8 ldr r3, [r5, r3, lsl #2] */
/* @0x2befec cmp r3, #0 */
/* @0x2beff0 beq 0x2bf01c <jpeg_huff_decode+0x490> */
/* @0x2beff4 add r0, r5, r0 */
/* @0x2beff8 rsb r2, r3, r2 */
/* @0x2beffc ldrb r0, [r0, #0x490] */
/* @0x2bf000 ands r8, r0, #15 */
/* @0x2bf004 asr r0, r0, #4 */
/* @0x2bf008 bne 0x2befb4 <jpeg_huff_decode+0x428> */
/* @0x2bf00c cmp r0, #15 */
/* @0x2bf010 bne 0x2beebc <jpeg_huff_decode+0x330> */
/* @0x2bf014 add r6, r6, #15 */
/* @0x2bf018 b 0x2befc4 <jpeg_huff_decode+0x438> */
/* @0x2bf01c add r8, sp, #60 */
/* @0x2bf020 mov r3, #9 */
/* @0x2bf024 str r3, [sp] */
/* @0x2bf028 mov r0, r8 */
/* @0x2bf02c mov r3, r5 */
/* @0x2bf030 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2bf034 cmp r0, #0 */
/* @0x2bf038 blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf03c ldr r1, [sp, #0x44] */
/* @0x2bf040 ldr r2, [sp, #0x48] */
/* @0x2bf044 b 0x2bf000 <jpeg_huff_decode+0x474> */
/* @0x2bf048 add r8, sp, #60 */
/* @0x2bf04c mov r3, #0 */
/* @0x2bf050 mov r0, r8 */
/* @0x2bf054 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf058 cmp r0, #0 */
/* @0x2bf05c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf060 ldr r2, [sp, #0x48] */
/* @0x2bf064 ldr r1, [sp, #0x44] */
/* @0x2bf068 cmp r2, #7 */
/* @0x2bf06c bgt 0x2befd8 <jpeg_huff_decode+0x44c> */
/* @0x2bf070 mov r3, #1 */
/* @0x2bf074 b 0x2bf024 <jpeg_huff_decode+0x498> */
/* @0x2bf078 add r0, sp, #60 */
/* @0x2bf07c mov r3, r8 */
/* @0x2bf080 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf084 cmp r0, #0 */
/* @0x2bf088 ldrne r1, [sp, #0x44] */
/* @0x2bf08c ldrne r2, [sp, #0x48] */
/* @0x2bf090 bne 0x2befc0 <jpeg_huff_decode+0x434> */
/* @0x2bf094 mov r0, #0 */
/* @0x2bf098 add sp, sp, #84 */
/* @0x2bf09c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 出口 2 */
/* @0x2bf0a0 add r10, sp, #60 */
/* @0x2bf0a4 mov r3, #9 */
/* @0x2bf0a8 str r3, [sp] */
/* @0x2bf0ac mov r0, r10 */
/* @0x2bf0b0 mov r3, r6 */
/* @0x2bf0b4 bl 0x2beb8c <jpeg_huff_decode> */
/* @0x2bf0b8 subs r6, r0, #0 */
/* @0x2bf0bc blt 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf0c0 ldr r1, [sp, #0x44] */
/* @0x2bf0c4 ldr r2, [sp, #0x48] */
/* @0x2bf0c8 b 0x2bed98 <jpeg_huff_decode+0x20c> */
/* @0x2bf0cc add r10, sp, #60 */
/* @0x2bf0d0 mov r3, #0 */
/* @0x2bf0d4 mov r0, r10 */
/* @0x2bf0d8 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf0dc cmp r0, #0 */
/* @0x2bf0e0 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf0e4 ldr r2, [sp, #0x48] */
/* @0x2bf0e8 ldr r1, [sp, #0x44] */
/* @0x2bf0ec cmp r2, #7 */
/* @0x2bf0f0 bgt 0x2bed70 <jpeg_huff_decode+0x1e4> */
/* @0x2bf0f4 mov r3, #1 */
/* @0x2bf0f8 b 0x2bf0a8 <jpeg_huff_decode+0x51c> */
/* @0x2bf0fc ldr r2, [r9, #0x10] —— restart_interval == 0 分支 */
/* @0x2bf100 ldr r3, [r0, #0x194] */
/* @0x2bf104 cmp r2, #0 */
/* @0x2bf108 add r1, r2, #7 */
/* @0x2bf10c ldr r12, [r3, #0x14] */
/* @0x2bf110 movlt r2, r1 */
/* @0x2bf114 ldr r1, [r3, #0x8] */
/* @0x2bf118 add r2, r12, r2, asr #3 */
/* @0x2bf11c str r2, [r3, #0x14] */
/* @0x2bf120 str r4, [r9, #0x10] */
/* @0x2bf124 blx r1 */
/* @0x2bf128 cmp r0, #0 */
/* @0x2bf12c beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf130 ldr r2, [r10, #0x124] */
/* @0x2bf134 cmp r2, #0 */
/* @0x2bf138 addgt r2, r9, r2, lsl #2 */
/* @0x2bf13c movgt r3, r9 */
/* @0x2bf140 ble 0x2bf154 <jpeg_huff_decode+0x5c8> */
/* @0x2bf144 str r4, [r3, #0x14] */
/* @0x2bf148 add r3, r3, #4 */
/* @0x2bf14c cmp r3, r2 */
/* @0x2bf150 bne 0x2bf144 <jpeg_huff_decode+0x5b8> */
/* @0x2bf154 ldr r3, [r10, #0x17c] */
/* @0x2bf158 ldr r2, [r10, #0xfc] */
/* @0x2bf15c cmp r3, #0 */
/* @0x2bf160 strbeq r3, [r9, #0x8] */
/* @0x2bf164 str r2, [r9, #0x24] */
/* @0x2bf168 beq 0x2beccc <jpeg_huff_decode+0x140> */
/* @0x2bf16c b 0x2becc0 <jpeg_huff_decode+0x134> */
/* @0x2bf170 add r0, sp, #60 */
/* @0x2bf174 mov r3, r6 */
/* @0x2bf178 bl 0x2bea2c <jpeg_fill_bit_buffer> */
/* @0x2bf17c cmp r0, #0 */
/* @0x2bf180 beq 0x2bf094 <jpeg_huff_decode+0x508> */
/* @0x2bf184 ldr r1, [sp, #0x44] */
/* @0x2bf188 ldr r2, [sp, #0x48] */
/* @0x2bf18c b 0x2beda8 <jpeg_huff_decode+0x21c> */
/* @0x2bf190 strheq r1, [sp], -r12 */
/* @0x2bf194 andeq r1, sp, r12, lsr #9 */

/* ═══════════════════════════════════════════════════════════════════════
 * §10 anon_2b8500 = jdsample.c 的上采样分派器 + 4 个放大例程（5 个函数 + 1 个续块并成一段）
 * ═══════════════════════════════════════════════════════════════════════
 * 段内边界（由出口 bx lr / pop 与序言确定）
 *   0x2b8500..0x2b85b4  180 B   分派器：读 cinfo->upsample(+0x1a0) 与 cinfo+0x114
 *                               （output_width），按组件步进 4 B 调 methods[ci]
 *   0x2b85b8..0x2b8640  136 B   接在 pop 之后、以 bx lr 收尾的块：入口直接读 r5+0x24 的
 *                               计数而 r5 在本块内没有定义 ⇒ 更像 0x2b8500 的冷块/
 *                               jump-table 续块，不是独立函数（open 5）
 *   0x2b8644..0x2b864c   12 B   退化例程：`mov r2,#0; str r2,[r3]; bx lr`（*out_row_ctr = 0）
 *   0x2b8650..0x2b86b4  104 B   逐行放大（读 cinfo+0x114 = output_width）
 *   0x2b86b8..0x2b87c4  268 B   逐行放大主体
 *   0x2b87c8..0x2b895c  404 B   逐行放大主体（最大的一份）
 *
 * 身份证据（两条）
 *   ① jinit_upsampler(0x2b8ad0) 把段内 0x2b8644 / 0x2b86b8 / 0x2b87c8 写进**按组件排布**的
 *      upsample 私有表：0x2b8bb4 `str r3,[r6,#0x34]`、0x2b8c00 `str r0,[r6,#0x64]`、
 *      0x2b8cdc `str r0,[r6,#0xc]`、0x2b8d3c `str r0,[r6,#0x34]`，其中 r6 每组件 +4
 *      （0x2b8bc4 `add r6,r6,#4`）—— 只有 jdsample.c 的 per-component methods 表是这个形状。
 *   ② 分派器本体：0x2b851c `ldr r0,[r9,#0x5c]`（r9 = cinfo->upsample，next_row_out），
 *      0x2b852c `add r6,r9,#12` 后 +4 步进 → methods[0] 从 +0xc 起，与 ① 的 +0xc 对上；
 *      0x2b8510 读 cinfo+0x114（output_width）做行循环上限。
 *
 * 它调谁：全部是 blx 间接（methods[ci]）；0 处 bl
 * 谁调它：分派器本身由 jpeg_upsampler 槽 #1 upsample 调用（jinit_upsampler 里对 0x2b8500
 *         的直接 str 本卡没找到 —— 它可能经栈槽中转，open 4）；段内 4 个方法则由 ① 装表
 * 边界：段尾 0x2b8960/0x2b8964/0x2b8968（mov r6,r3 / mov r3,r12 / b 0x2b88e8）落在最后
 *       一个 bx lr 之后，是另一条分支的尾巴，不是新函数入口。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2b8500 0x2b896c anon_2b8500 sep_upsample_block */

/* @0x2b8500 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— 分派器入口（方法表遍历） */
/* @0x2b8504 mov r5, r0 */
/* @0x2b8508 ldr r9, [r0, #0x1a0] */
/* @0x2b850c sub sp, sp, #20 */
/* @0x2b8510 ldr r4, [r0, #0x114] —— cinfo+0x114 = output_width（行循环上限） */
/* @0x2b8514 mov r11, r2 */
/* @0x2b8518 ldr r10, [sp, #0x3c] */
/* @0x2b851c ldr r0, [r9, #0x5c] —— upsample+0x5c = next_row_out */
/* @0x2b8520 cmp r0, r4 */
/* @0x2b8524 bge 0x2b85b8 <jinit_d_post_controller+0x1ac> */
/* @0x2b8528 mov r2, r0 */
/* @0x2b852c add r6, r9, #12 —— methods[0] 从 +0xc 起 */
/* @0x2b8530 str r6, [sp, #0xc] */
/* @0x2b8534 ldr r3, [r10] */
/* @0x2b8538 rsb r0, r0, r4 */
/* @0x2b853c ldr r6, [sp, #0x40] */
/* @0x2b8540 ldr lr, [r9, #0x60] */
/* @0x2b8544 ldr r12, [r5, #0x1a4] */
/* @0x2b8548 rsb r4, r3, r6 */
/* @0x2b854c ldr r6, [sp, #0x38] */
/* @0x2b8550 cmp r4, lr */
/* @0x2b8554 movhs r4, lr */
/* @0x2b8558 cmp r4, r0 */
/* @0x2b855c movhs r4, r0 */
/* @0x2b8560 ldr r1, [sp, #0xc] */
/* @0x2b8564 str r4, [sp] */
/* @0x2b8568 add r3, r6, r3, lsl #2 */
/* @0x2b856c mov r0, r5 */
/* @0x2b8570 ldr r12, [r12, #0x4] */
/* @0x2b8574 blx r12 */
/* @0x2b8578 ldr r3, [r10] */
/* @0x2b857c add r3, r3, r4 */
/* @0x2b8580 str r3, [r10] */
/* @0x2b8584 ldr r3, [r9, #0x5c] */
/* @0x2b8588 ldr r1, [r5, #0x114] */
/* @0x2b858c add r3, r4, r3 */
/* @0x2b8590 ldr r2, [r9, #0x60] */
/* @0x2b8594 cmp r3, r1 */
/* @0x2b8598 str r3, [r9, #0x5c] */
/* @0x2b859c rsb r4, r4, r2 */
/* @0x2b85a0 str r4, [r9, #0x60] */
/* @0x2b85a4 ldrge r3, [r11] */
/* @0x2b85a8 addge r3, r3, #1 */
/* @0x2b85ac strge r3, [r11] */
/* @0x2b85b0 add sp, sp, #20 */
/* @0x2b85b4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 分派器出口 */
/* @0x2b85b8 ldr r3, [r5, #0x24] —— 续块入口（r5 在本块内无定义，不当作独立函数） */
/* @0x2b85bc ldr r6, [r5, #0xc4] */
/* @0x2b85c0 cmp r3, #0 */
/* @0x2b85c4 ble 0x2b8630 <jinit_d_post_controller+0x224> */
/* @0x2b85c8 add lr, r9, #12 */
/* @0x2b85cc sub r8, r1, #4 */
/* @0x2b85d0 mov r7, #0 */
/* @0x2b85d4 str lr, [sp, #0xc] */
/* @0x2b85d8 mov r4, lr */
/* @0x2b85dc ldr r2, [r11] */
/* @0x2b85e0 mov r1, r6 */
/* @0x2b85e4 ldr lr, [r4, #0x58] */
/* @0x2b85e8 mov r0, r5 */
/* @0x2b85ec ldr r3, [r8, #0x4]! */
/* @0x2b85f0 add r7, r7, #1 */
/* @0x2b85f4 lsl r2, r2, #2 */
/* @0x2b85f8 ldr r12, [r4, #0x28] */
/* @0x2b85fc add r6, r6, #84 */
/* @0x2b8600 mla r2, lr, r2, r3 */
/* @0x2b8604 mov r3, r4 */
/* @0x2b8608 blx r12 */
/* @0x2b860c ldr r3, [r5, #0x24] */
/* @0x2b8610 add r4, r4, #4 */
/* @0x2b8614 cmp r3, r7 */
/* @0x2b8618 bgt 0x2b85dc <jinit_d_post_controller+0x1d0> */
/* @0x2b861c ldr r4, [r5, #0x114] */
/* @0x2b8620 mov r2, #0 */
/* @0x2b8624 str r2, [r9, #0x5c] */
/* @0x2b8628 mov r0, r2 */
/* @0x2b862c b 0x2b8534 <jinit_d_post_controller+0x128> */
/* @0x2b8630 add r6, r9, #12 */
/* @0x2b8634 str r6, [sp, #0xc] */
/* @0x2b8638 b 0x2b8620 <jinit_d_post_controller+0x214> */
/* @0x2b863c str r2, [r3] */
/* @0x2b8640 bx lr */
/* @0x2b8644 mov r2, #0 —— 12 B 退化例程：*out_row_ctr = 0 */
/* @0x2b8648 str r2, [r3] */
/* @0x2b864c bx lr */
/* @0x2b8650 ldr r1, [r0, #0x114] —— 第 4 个例程入口（读 output_width） */
/* @0x2b8654 push {r4, r5, r6, r7} */
/* @0x2b8658 cmp r1, #0 */
/* @0x2b865c ldr r7, [r3] */
/* @0x2b8660 ble 0x2b86b0 <jinit_d_post_controller+0x2a4> */
/* @0x2b8664 mov r5, #0 */
/* @0x2b8668 mov r6, r5 */
/* @0x2b866c ldr r3, [r7, r5] */
/* @0x2b8670 ldr r4, [r0, #0x5c] */
/* @0x2b8674 ldr r12, [r2, r5] */
/* @0x2b8678 add r4, r3, r4 */
/* @0x2b867c cmp r3, r4 */
/* @0x2b8680 bhs 0x2b86a0 <jinit_d_post_controller+0x294> */
/* @0x2b8684 ldrb r1, [r12], #1 */
/* @0x2b8688 add r3, r3, #2 */
/* @0x2b868c strb r1, [r3, #-0x2] */
/* @0x2b8690 strb r1, [r3, #-0x1] */
/* @0x2b8694 cmp r4, r3 */
/* @0x2b8698 bhi 0x2b8684 <jinit_d_post_controller+0x278> */
/* @0x2b869c ldr r1, [r0, #0x114] */
/* @0x2b86a0 add r6, r6, #1 */
/* @0x2b86a4 add r5, r5, #4 */
/* @0x2b86a8 cmp r1, r6 */
/* @0x2b86ac bgt 0x2b866c <jinit_d_post_controller+0x260> */
/* @0x2b86b0 pop {r4, r5, r6, r7} */
/* @0x2b86b4 bx lr */
/* @0x2b86b8 push {r4, r5, r6, r7, r8, r9, r10, r11} —— 第 5 个例程入口 */
/* @0x2b86bc sub sp, sp, #16 */
/* @0x2b86c0 ldr r3, [r3] */
/* @0x2b86c4 mov r11, r0 */
/* @0x2b86c8 str r1, [sp, #0x8] */
/* @0x2b86cc ldr r1, [r0, #0x114] */
/* @0x2b86d0 str r2, [sp, #0xc] */
/* @0x2b86d4 cmp r1, #0 */
/* @0x2b86d8 str r3, [sp, #0x4] */
/* @0x2b86dc ble 0x2b87bc <jinit_d_post_controller+0x3b0> */
/* @0x2b86e0 mov r9, #0 */
/* @0x2b86e4 mov r0, #3 */
/* @0x2b86e8 mov r10, r9 */
/* @0x2b86ec ldr r2, [sp, #0xc] */
/* @0x2b86f0 ldr r12, [r2, r9] */
/* @0x2b86f4 ldr r2, [sp, #0x4] */
/* @0x2b86f8 add r7, r12, #1 */
/* @0x2b86fc ldr r3, [r2, r9] */
/* @0x2b8700 ldrb r2, [r12] */
/* @0x2b8704 mov r6, r3 */
/* @0x2b8708 strb r2, [r6], #2 */
/* @0x2b870c ldrb r1, [r12, #0x1] */
/* @0x2b8710 smlabb r2, r0, r2, r1 */
/* @0x2b8714 add r2, r2, #2 */
/* @0x2b8718 asr r2, r2, #2 */
/* @0x2b871c strb r2, [r3, #0x1] */
/* @0x2b8720 ldr r3, [sp, #0x8] */
/* @0x2b8724 ldr r8, [r3, #0x28] */
/* @0x2b8728 subs r2, r8, #2 */
/* @0x2b872c str r2, [sp] */
/* @0x2b8730 beq 0x2b878c <jinit_d_post_controller+0x380> */
/* @0x2b8734 sub r5, r8, #1 */
/* @0x2b8738 mov r2, r7 */
/* @0x2b873c add r5, r12, r5 */
/* @0x2b8740 mov r3, r6 */
/* @0x2b8744 ldrb r1, [r12, #0x1]! */
/* @0x2b8748 add r3, r3, #2 */
/* @0x2b874c ldrb r4, [r2, #-0x1] */
/* @0x2b8750 smlabb r4, r0, r1, r4 */
/* @0x2b8754 add r4, r4, #1 */
/* @0x2b8758 asr r4, r4, #2 */
/* @0x2b875c strb r4, [r3, #-0x2] */
/* @0x2b8760 ldrb r4, [r2, #0x1]! */
/* @0x2b8764 cmp r2, r5 */
/* @0x2b8768 smlabb r1, r0, r1, r4 */
/* @0x2b876c add r1, r1, #2 */
/* @0x2b8770 asr r1, r1, #2 */
/* @0x2b8774 strb r1, [r3, #-0x1] */
/* @0x2b8778 bne 0x2b8744 <jinit_d_post_controller+0x338> */
/* @0x2b877c sub r8, r8, #-2147483646 */
/* @0x2b8780 ldr r3, [sp] */
/* @0x2b8784 add r6, r6, r8, lsl #1 */
/* @0x2b8788 add r7, r7, r3 */
/* @0x2b878c ldrb r3, [r7] */
/* @0x2b8790 add r10, r10, #1 */
/* @0x2b8794 ldrb r2, [r7, #-0x1] */
/* @0x2b8798 add r9, r9, #4 */
/* @0x2b879c strb r3, [r6, #0x1] */
/* @0x2b87a0 smlabb r3, r0, r3, r2 */
/* @0x2b87a4 add r3, r3, #1 */
/* @0x2b87a8 asr r3, r3, #2 */
/* @0x2b87ac strb r3, [r6] */
/* @0x2b87b0 ldr r3, [r11, #0x114] */
/* @0x2b87b4 cmp r3, r10 */
/* @0x2b87b8 bgt 0x2b86ec <jinit_d_post_controller+0x2e0> */
/* @0x2b87bc add sp, sp, #16 */
/* @0x2b87c0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b87c4 bx lr */
/* @0x2b87c8 push {r4, r5, r6, r7, r8, r9, r10, r11} —— 第 6 个例程入口（最大） */
/* @0x2b87cc sub sp, sp, #32 */
/* @0x2b87d0 ldr r3, [r3] */
/* @0x2b87d4 str r1, [sp, #0x18] */
/* @0x2b87d8 ldr r1, [r0, #0x114] */
/* @0x2b87dc str r0, [sp, #0x1c] */
/* @0x2b87e0 cmp r1, #0 */
/* @0x2b87e4 ble 0x2b8954 <jinit_d_post_controller+0x548> */
/* @0x2b87e8 mov r10, #3 */
/* @0x2b87ec sub r2, r2, #4 */
/* @0x2b87f0 sub r3, r3, #4 */
/* @0x2b87f4 mov r0, #0 */
/* @0x2b87f8 str r2, [sp, #0x8] */
/* @0x2b87fc str r3, [sp, #0x10] */
/* @0x2b8800 str r0, [sp, #0x14] */
/* @0x2b8804 ldr r3, [sp, #0x10] */
/* @0x2b8808 mov r5, #0 */
/* @0x2b880c str r5, [sp, #0x4] */
/* @0x2b8810 str r3, [sp, #0xc] */
/* @0x2b8814 ldr r1, [sp, #0x4] */
/* @0x2b8818 ldr r2, [sp, #0x8] */
/* @0x2b881c cmp r1, #0 */
/* @0x2b8820 ldrne r5, [sp, #0x8] */
/* @0x2b8824 ldr r3, [r2, #0x4] */
/* @0x2b8828 ldreq r2, [r2] */
/* @0x2b882c ldrne r2, [r5, #0x8] */
/* @0x2b8830 mov r1, r3 */
/* @0x2b8834 ldrb r0, [r3, #0x1] */
/* @0x2b8838 ldrb r5, [r1], #2 */
/* @0x2b883c mov r4, r2 */
/* @0x2b8840 ldrb r3, [r2, #0x1] */
/* @0x2b8844 ldrb r12, [r4], #2 */
/* @0x2b8848 smlabb r3, r10, r0, r3 */
/* @0x2b884c smlabb r12, r10, r5, r12 */
/* @0x2b8850 ldr r5, [sp, #0xc] */
/* @0x2b8854 ldr r2, [r5, #0x4]! */
/* @0x2b8858 add r0, r12, r12, lsl #1 */
/* @0x2b885c add r0, r0, r3 */
/* @0x2b8860 str r5, [sp, #0xc] */
/* @0x2b8864 add r0, r0, #7 */
/* @0x2b8868 add r5, r12, #2 */
/* @0x2b886c mov r9, r2 */
/* @0x2b8870 asr r0, r0, #4 */
/* @0x2b8874 lsr r5, r5, #2 */
/* @0x2b8878 strb r5, [r9], #2 */
/* @0x2b887c strb r0, [r2, #0x1] */
/* @0x2b8880 ldr r0, [sp, #0x18] */
/* @0x2b8884 ldr r11, [r0, #0x28] */
/* @0x2b8888 subs r8, r11, #2 */
/* @0x2b888c beq 0x2b8960 <jinit_d_post_controller+0x554> */
/* @0x2b8890 add r8, r1, r8 */
/* @0x2b8894 mov r2, r9 */
/* @0x2b8898 b 0x2b88a0 <jinit_d_post_controller+0x494> */
/* @0x2b889c mov r3, r6 */
/* @0x2b88a0 ldrb r7, [r1], #1 */
/* @0x2b88a4 add r0, r3, r3, lsl #1 */
/* @0x2b88a8 ldrb r6, [r4], #1 */
/* @0x2b88ac add r5, r0, r12 */
/* @0x2b88b0 add r5, r5, #8 */
/* @0x2b88b4 cmp r1, r8 */
/* @0x2b88b8 mov r12, r3 */
/* @0x2b88bc add r2, r2, #2 */
/* @0x2b88c0 smlabb r6, r10, r7, r6 */
/* @0x2b88c4 asr r5, r5, #4 */
/* @0x2b88c8 strb r5, [r2, #-0x2] */
/* @0x2b88cc add r0, r6, r0 */
/* @0x2b88d0 add r0, r0, #7 */
/* @0x2b88d4 asr r0, r0, #4 */
/* @0x2b88d8 strb r0, [r2, #-0x1] */
/* @0x2b88dc bne 0x2b889c <jinit_d_post_controller+0x490> */
/* @0x2b88e0 sub r11, r11, #-2147483646 */
/* @0x2b88e4 add r9, r9, r11, lsl #1 */
/* @0x2b88e8 ldr r1, [sp, #0x4] */
/* @0x2b88ec add r2, r6, r6, lsl #1 */
/* @0x2b88f0 add r3, r2, r3 */
/* @0x2b88f4 lsl r6, r6, #2 */
/* @0x2b88f8 add r1, r1, #1 */
/* @0x2b88fc add r3, r3, #8 */
/* @0x2b8900 add r6, r6, #7 */
/* @0x2b8904 cmp r1, #2 */
/* @0x2b8908 asr r3, r3, #4 */
/* @0x2b890c str r1, [sp, #0x4] */
/* @0x2b8910 asr r6, r6, #4 */
/* @0x2b8914 strb r3, [r9] */
/* @0x2b8918 strb r6, [r9, #0x1] */
/* @0x2b891c bne 0x2b8814 <jinit_d_post_controller+0x408> */
/* @0x2b8920 ldr r5, [sp, #0x1c] */
/* @0x2b8924 ldr r0, [sp, #0x14] */
/* @0x2b8928 ldr r1, [sp, #0x8] */
/* @0x2b892c ldr r3, [r5, #0x114] */
/* @0x2b8930 add r0, r0, #2 */
/* @0x2b8934 ldr r2, [sp, #0x10] */
/* @0x2b8938 add r1, r1, #4 */
/* @0x2b893c cmp r3, r0 */
/* @0x2b8940 str r0, [sp, #0x14] */
/* @0x2b8944 add r2, r2, #8 */
/* @0x2b8948 str r1, [sp, #0x8] */
/* @0x2b894c str r2, [sp, #0x10] */
/* @0x2b8950 bgt 0x2b8804 <jinit_d_post_controller+0x3f8> */
/* @0x2b8954 add sp, sp, #32 */
/* @0x2b8958 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2b895c bx lr —— 最后出口 bx lr */
/* @0x2b8960 mov r6, r3 —— 另一分支尾巴（非新函数入口） */
/* @0x2b8964 mov r3, r12 */
/* @0x2b8968 b 0x2b88e8 <jinit_d_post_controller+0x4dc> */

