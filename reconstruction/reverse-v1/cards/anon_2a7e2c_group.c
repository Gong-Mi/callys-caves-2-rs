/* cally 逆向卡：anon_2a6ff0 / anon_2a7e2c / anon_2a804c（原版 libyoyo.so，ELF32 ARM，stripped）
 *
 * @card  0x2a6ff0 .. 0x2a87b0（三段连续：1112 + 544 + 1892 = 3,548 B；三个 @func 小节，地址各只出现一次）
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，ELF32 ARM，stripped，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-anon_2a6ff0.tsv(278) / asm/index-anon_2a7e2c.tsv(136) / asm/index-anon_2a804c.tsv(473)
 * 级别:  骨架（锚点全覆盖、逐字一致；语义钉到顶部：模块归属、14 个函数契约、chunk 分派链、
 *        字段偏移；函数体内部只钉关键块，其余按 Thumb 原文逐条列出但不解释）
 *
 * ══ 一句话结论 ═══════════════════════════════════════════════════════
 *   这三段不是"被 strip 的匿名函数"，而是 libyoyo.so 里**静态链接的 libpng 读侧 API**
 *   （.rodata @0x38c2ab 有 "libpng version 1.4.19 - December 17, 2015"，同区还有
 *    "Application is running with png.c from libpng-%.20s"）。三段共 14 个具名函数：
 *
 *     anon_2a6ff0 (1112 B) = png_read_info                                    1 个
 *     anon_2a7e2c ( 544 B) = png_destroy_read_struct 140 + png_set_read_status_fn 8
 *                          + png_read_png 324 + png_default_read_data 44 + png_read_data 28
 *     anon_2a804c (1892 B) = png_set_read_fn 80 + png_set_crc_action 140 + png_set_background 92
 *                          + png_set_strip_16 16 + png_set_strip_alpha 16 + png_set_quantize 1426
 *                          + png_set_gamma 88 + png_set_expand 32
 *   三者同模块且**地址首尾相接**：anon_2a7e2c 的末字节 0x2a804b 紧接 anon_2a804c 的首字节；
 *   anon_2a6ff0 的终点 0x2a7448 与 anon_2a7e2c 之间（0x2a7448..0x2a7e2c，2532 B）仍是同一模块的
 *   png_read_update_info / png_start_read_image / png_read_row / png_read_rows / png_read_image /
 *   png_read_end / png_read_destroy。整个 libpng 块在 .so 里占 0x2a5a24（png_set_sig_bytes）..
 *   0x2b2b00 左右（write 侧到 png_write_find_filter），本卡只覆盖其中三个 anon 区间。
 *
 * ══ 为什么 functions.tsv 把它们记成 anon ══════════════════════════════
 *   .dynsym 里这些函数的 st_value 都是**奇数**（png_read_info=0x2a6ff1、png_destroy_read_struct=0x2a7e2d、
 *   png_set_read_fn=0x2a804d …），即 ARM/Thumb 的 Thumb 位；清点脚本把 st_value 原样写进
 *   functions.tsv（"2a6ff1  1112  png_read_info"），而匿名区间按偶数起址切（0x2a6ff0+1112），
 *   两边对不上 → 区间得到 anon_ 名、具名行变成"另一条零指令记录"。llvm-nm -D 会掩掉低位，
 *   显示的就是 002a6ff0 T png_read_info。**符号在，只是低位被当成地址不同。**
 *
 * ══ 重要：本卡锚点逐字抄 index，但 index 的助记符是 ARM 误解码 ═════════
 *   scripts/asm_index.py 用 `llvm-objdump --triple=armv7-linux-androideabi`（纯 ARM 模式）扫区间，
 *   而这三段是 **Thumb-2**：
 *     0x2a6ff0 首字 0x4ff0e92d = 半字 0xe92d,0x4ff0 = push.w {r4-r11,lr}
 *       → index 记作 `svcmi #0xf0e92d`；
 *     0x2a804c 首字 0x4604b510 = 半字 0xb510,0x4604 = push {r4,lr} ; mov r4,r0
 *       → index 记作 `.word 0x4604b510`。
 *   判据三条：① .dynsym st_value 低位为 1（Thumb）；② `llvm-objdump --triple=thumbv7-linux-androideabi`
 *   解出完整自洽的 libpng 代码（本卡每条锚点 "——" 之后就是它的原文，逐条可复核）；
 *   ③ 按 ARM 读则函数无出口、无调用、无栈帧，全是 svc/stm/ldm 噪声。
 *   所以本卡：**锚点文本 = index 原文（保证 check_card_anchors / verify_reverse_v1 逐字一致），
 *   语义一律按 "——" 后的 Thumb 原文读**。这与 README 规矩 3（literal pool 数据字保留 objdump
 *   写法、注释标"非指令"）同构，但规模是整段——index 该用 --triple=thumbv7-linux-androideabi 重生成，
 *   见 open 1。
 *
 * ══ 计数（口径写死）═══════════════════════════════════════════════════
 *   区段          index 行(4 B 栅格)   真实 Thumb 指令   外部调用点   内部出边
 *   anon_2a6ff0        278                 417              6           51
 *   anon_2a7e2c        136                 201             22           26
 *   anon_2a804c        473                 660              9           16
 *   —— "真实 Thumb 指令" = 递归下降（含 tbb 跳表展开）可达指令数，不含 literal pool；
 *      "外部调用点" = bl/blx/b(尾跳) 目标落在本段、调用者在段外的点（全库 8,913 个具名函数扫一遍）；
 *      "内部出边" = 本段内发出的 bl/blx/尾跳点数（含块内 memcmp、png_malloc 等）。
 *   对外调用点：派活时给的 18/5/5 来自 cards/auto 里 `blx 0x<目标>` 的行数统计，只覆盖被自动卡
 *   覆盖的 bank，是**部分账**；本卡按全库 8,913 个具名函数重算 = anon_2a6ff0 6、anon_2a7e2c 22、
 *   anon_2a804c 9（见各节"谁调它"）。
 *
 * ══ 契约表（按 libpng 1.4.x 公共 API 写，每条的字段/寄存器用法都在下文指到指令）══
 *   0x2a6ff0  void png_read_info(png_structp png, png_infop info)
 *   0x2a7e2c  void png_destroy_read_struct(png_structpp *, png_infopp *, png_infopp *)
 *   0x2a7eb8  void png_set_read_status_fn(png_structp, png_read_status_ptr)
 *   0x2a7ec0  void png_read_png(png_structp, png_infop, int transforms, png_voidp params)
 *   0x2a8004  void png_default_read_data(png_structp, png_bytep data, size_t length)
 *   0x2a8030  void png_read_data(png_structp, png_bytep data, size_t length)
 *   0x2a804c  void png_set_read_fn(png_structp, png_voidp io_ptr, png_rw_ptr read_data_fn)
 *   0x2a809c  void png_set_crc_action(png_structp, int crit_action, int ancil_action)
 *   0x2a8128  void png_set_background(png_structp, png_const_color_16p bg, int gamma_code,
 *                                     int need_expand, double background_gamma)
 *   0x2a8184  void png_set_strip_16(png_structp)
 *   0x2a8194  void png_set_strip_alpha(png_structp)
 *   0x2a81a4  void png_set_quantize(png_structp, png_colorp palette, int num_palette,
 *                                    int maximum_colors, png_uint_16p histogram, int full_quantize)
 *   0x2a8738  void png_set_gamma(png_structp, double screen_gamma, double override_file_gamma)
 *   0x2a8790  void png_set_expand(png_structp)
 *   字段偏移（本件实测，png_struct）：+0x110 write_data_fn / +0x114 read_data_fn / +0x118 io_ptr /
 *     +0x12c mode / +0x130 flags / +0x134 transformations / +0x1d0 idat_size / +0x1e0 chunk_name /
 *     +0x1ea color_type / +0x1eb bit_depth / +0x1f4 background_gamma_type / +0x1f8 background_gamma /
 *     +0x1fc..+0x204 background(png_color_16) / +0x210 一个 32 位字（png_set_read_fn 清零，身份 open）/
 *     +0x220 gamma / +0x224 screen_gamma / +0x25c read_status_fn / +0x2b4,+0x2f8 quantize 两数组 /
 *     +0x2e8 free_fn / +0x2f0 mem_ptr
 *   png_info：+0x04 height / +0x08 valid / +0x44（png_set_shift 用的通道位）/ +0xb8 free_me / +0xf8 row_pointers
 */

/* ════════════════════════════════════════════════════════════════════
 * 节 1/3  anon_2a6ff0 = png_read_info（0x2a6ff0..0x2a7448，1112 B，417 条）
 *   读到第一个 IDAT 为止：签名 → 逐 chunk 读头 → 按 4 字节名字线性 memcmp 分派给 20 个
 *   png_handle_* + 2 条 unknown 出口；碰到 IDAT 做 IHDR/PLTE 前置校验后置 idat_size 并返回。
 *   调了谁（51 个点）：memcmp@plt×25 / png_read_sig / png_read_chunk_header / png_handle_as_unknown /
 *     png_error / 20 个 png_handle_* / png_handle_unknown×2（明细见下）。
 *   谁调它（6 个点，全库扫描）：_Z11loadTextureP7Texture(0x1895ec)@0x1896cc、
 *     _Z14getTextureInfoP7Texture(0x189968)@0x189aac、_Z13ReadPNGHeaderP9yyPNGFile(0x189b78)@0x189c68、
 *     _Z7ReadPNGP9yyPNGFile(0x189e80)@0x189f70、_Z11loadTextureP3zipPKcPiS3_(0x28fe70)@0x28ff70、
 *     png_read_png(0x2a7ec0)@0x2a7ece。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a6ff0 0x2a7448 anon_2a6ff0 png_read_info */

/* ---- 序言 + 双 NULL 门 ----
 * 契约：r0 = png_ptr，r1 = info_ptr；返回 void。
 *   0x2a6ff0 push.w {r4-r11,lr} / 0x2a6ff6 sub sp,#0xb4 → 帧 0xb4（21×8 B 名字表 168 B + 余量）
 *   0x2a6ffa cmp r0,#0 / 0x2a6ffc beq 0x2a742c —— png_ptr == NULL 直接返回
 *   0x2a7000 cmp r1,#0 / 0x2a7002 beq 0x2a742c —— info_ptr == NULL 直接返回
 * 两个门都不写字段、不报错：空参是静默无操作（libpng 的惯例），不是 png_error。 */
/* @0x2a6ff0 svcmi #0xf0e92d —— push.w {r4, r5, r6, r7, r8, sb, sl, fp, lr} */
/* @0x2a6ff4 adclt r4, sp, pc, lsl #12 —— mov r7, r1 ; sub sp, #0xb4 */
/* @0x2a6ff8 stmdahs r0, {r2, r9, r10, lr} —— mov r4, r0 ; cmp r0, #0 */
/* @0x2a6ffc andshi pc, r6, #0 —— beq.w #0x2a742c */
/* @0x2a7000 .word 0xf0002900 —— cmp r1, #0 ; beq.w #0x2a742c */
/* @0x2a7004 .word 0xf8df8213 —— ldr.w r8, [pc, #0x42c] */
/* @0x2a7008 .word 0xf004842c —— bl #0x2abb94 */
/* @0x2a700c .word 0xf10dfdc3 —— add.w sl, sp, #8 */
/* @0x2a7010 ldrbtmi r0, [r8], #2568 —— add r8, pc */
/* @0x2a7014 mullo r4, r8, r8 —— ldrb.w r3, [r8, #4] */
/* @0x2a7018 andlo pc, r7, sp, lsl #17 —— strb.w r3, [sp, #7] */

/* ---- 循环头 0x2a701c：每轮把 21 个 chunk 名铺到栈上 ----
 * 21 项 ×（ldr r0,[r8+5i] + ldrb r3,[r8+5i+4] + str r0,[sp+8+8i] + strb r3,[sp+0xc+8i]）
 *   → 栈槽 sp+8, +0x10, …, +0xa8（5 字节串放进 8 字节槽），r9=sb 指槽 1、r10=sl 指槽 0、
 *   r11=fp 指槽 3。
 * 这不是一次性序言：所有分派出口都 `b 0x2a701c`，即**每个 chunk 都重铺一遍**；417 条指令里
 * 约 100 条是这个常量展开。 */
/* @0x2a701c mullo r7, sp, r8 —— ldrb.w r3, [sp, #7] */
/* @0x2a7020 ldmdbeq r0, {r0, r2, r3, r8, r12, sp, lr, pc} —— add.w sb, sp, #0x10 */
/* @0x2a7024 .word 0x0000f8d8 —— ldr.w r0, [r8] */
/* @0x2a7028 ldrbvc pc, [r0, #0x504]! —— add.w r5, r4, #0x1e0 */
/* @0x2a702c bleq 0xae3468 <b2_toiTime+0x389fc4> —— add.w fp, sp, #0x20 */
/* @0x2a7030 andlo pc, r4, r10, lsl #17 —— strb.w r3, [sl, #4] */
/* @0x2a7034 .word 0xf8ca4643 —— mov r3, r8 ; str.w r0, [sl] */
/* @0x2a7038 .word 0xf8530000 —— ldr r0, [r3, #5]! */
/* @0x2a703c ldmdbvc r11, {r0, r2, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a7040 .word 0xf88d9004 —— str r0, [sp, #0x10] ; strb.w r3, [sp, #0x14] */
/* @0x2a7044 .word 0x46433014 —— mov r3, r8 */
/* @0x2a7048 svceq #0xaf853 —— ldr r0, [r3, #0xa]! */
/* @0x2a704c andls r7, r6, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x18] */
/* @0x2a7050 andslo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x1c] */
/* @0x2a7054 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0xf]! */
/* @0x2a7058 ldmdbvc r11, {r0, r1, r2, r3, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a705c .word 0xf88d9008 —— str r0, [sp, #0x20] ; strb.w r3, [sp, #0x24] */
/* @0x2a7060 strbmi r3, [r3], -r4, lsr #32 —— mov r3, r8 */
/* @0x2a7064 svceq #0x14f853 —— ldr r0, [r3, #0x14]! */
/* @0x2a7068 andls r7, r10, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x28] */
/* @0x2a706c eorlo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x2c] */
/* @0x2a7070 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x19]! */
/* @0x2a7074 ldmdbvc r11, {r0, r3, r4, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a7078 .word 0xf88d900c —— str r0, [sp, #0x30] ; strb.w r3, [sp, #0x34] */
/* @0x2a707c .word 0x46433034 —— mov r3, r8 */
/* @0x2a7080 svceq #0x1ef853 —— ldr r0, [r3, #0x1e]! */
/* @0x2a7084 andls r7, lr, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x38] */
/* @0x2a7088 eorslo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x3c] */
/* @0x2a708c .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x23]! */
/* @0x2a7090 ldmdbvc r11, {r0, r1, r5, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a7094 .word 0xf88d9010 —— str r0, [sp, #0x40] ; strb.w r3, [sp, #0x44] */
/* @0x2a7098 strbmi r3, [r3], -r4, asr #32 —— mov r3, r8 */
/* @0x2a709c svceq #0x28f853 —— ldr r0, [r3, #0x28]! */
/* @0x2a70a0 ldmdbvc r11, {r1, r4, r12, pc} —— str r0, [sp, #0x48] ; ldrb r3, [r3, #4] */
/* @0x2a70a4 sublo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x4c] */
/* @0x2a70a8 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x2d]! */
/* @0x2a70ac ldmdbvc r11, {r0, r2, r3, r5, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a70b0 .word 0xf88d9014 —— str r0, [sp, #0x50] ; strb.w r3, [sp, #0x54] */
/* @0x2a70b4 .word 0x46433054 —— mov r3, r8 */
/* @0x2a70b8 svceq #0x32f853 —— ldr r0, [r3, #0x32]! */
/* @0x2a70bc andsls r7, r6, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x58] */
/* @0x2a70c0 subslo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x5c] */
/* @0x2a70c4 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x37]! */
/* @0x2a70c8 ldmdbvc r11, {r0, r1, r2, r4, r5, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a70cc .word 0xf88d9018 —— str r0, [sp, #0x60] ; strb.w r3, [sp, #0x64] */
/* @0x2a70d0 strbmi r3, [r3], -r4, rrx —— mov r3, r8 */
/* @0x2a70d4 svceq #0x3cf853 —— ldr r0, [r3, #0x3c]! */
/* @0x2a70d8 andsls r7, r10, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x68] */
/* @0x2a70dc rsblo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x6c] */
/* @0x2a70e0 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x41]! */
/* @0x2a70e4 ldmdbvc r11, {r0, r6, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a70e8 .word 0xf88d901c —— str r0, [sp, #0x70] ; strb.w r3, [sp, #0x74] */
/* @0x2a70ec .word 0x46433074 —— mov r3, r8 */
/* @0x2a70f0 svceq #0x46f853 —— ldr r0, [r3, #0x46]! */
/* @0x2a70f4 andsls r7, lr, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x78] */
/* @0x2a70f8 rsbslo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x7c] */
/* @0x2a70fc .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x4b]! */
/* @0x2a7100 ldmdbvc r11, {r0, r1, r3, r6, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a7104 .word 0xf88d9020 —— str r0, [sp, #0x80] ; strb.w r3, [sp, #0x84] */
/* @0x2a7108 strbmi r3, [r3], -r4, lsl #1 —— mov r3, r8 */
/* @0x2a710c svceq #0x50f853 —— ldr r0, [r3, #0x50]! */
/* @0x2a7110 eorls r7, r2, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x88] */
/* @0x2a7114 addlo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x8c] */
/* @0x2a7118 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x55]! */
/* @0x2a711c ldmdbvc r11, {r0, r2, r4, r6, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a7120 .word 0xf88d9024 —— str r0, [sp, #0x90] ; strb.w r3, [sp, #0x94] */
/* @0x2a7124 .word 0x46433094 —— mov r3, r8 */
/* @0x2a7128 svceq #0x5af853 —— ldr r0, [r3, #0x5a]! */
/* @0x2a712c eorls r7, r6, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0x98] */
/* @0x2a7130 addslo pc, r12, sp, lsl #17 —— strb.w r3, [sp, #0x9c] */
/* @0x2a7134 .word 0xf8534643 —— mov r3, r8 ; ldr r0, [r3, #0x5f]! */
/* @0x2a7138 ldmdbvc r11, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11} —— ldrb r3, [r3, #4] */
/* @0x2a713c .word 0xf88d9028 —— str r0, [sp, #0xa0] ; strb.w r3, [sp, #0xa4] */
/* @0x2a7140 strbmi r3, [r3], -r4, lsr #1 —— mov r3, r8 */
/* @0x2a7144 svceq #0x64f853 —— ldr r0, [r3, #0x64]! */
/* @0x2a7148 eorls r7, r10, r11, lsl r9 —— ldrb r3, [r3, #4] ; str r0, [sp, #0xa8] */
/* @0x2a714c .word 0xf88d4620 —— mov r0, r4 ; strb.w r3, [sp, #0xac] */
/* @0x2a7150 .word 0xf00630ac —— bl #0x2adbc4 */
/* @0x2a7154 .word 0x4649fd37 —— mov r1, sb */
/* @0x2a7158 strmi r2, [r6], -r4, lsl #4 —— movs r2, #4 ; mov r6, r0 */
/* @0x2a715c .word 0xf60f4628 —— mov r0, r5 ; blx #0xb6c40 */
/* @0x2a7160 ldmdblt r8!, {r4, r5, r6, r8, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7174 */

/* ---- IDAT 前置守卫（0x2a7164..0x2a7170）----
 * 若 chunk == IDAT 且 mode(+0x12c) 的 bit3 = 1，则 mode |= 0x2000（bit13）。
 * bit3 在本件其它处被当作 PNG_AFTER_IDAT 用（见 png_read_png 的 valid 位、IDAT 块）；
 * 0x2000 这个 mode 位的名字未定 → open 3。 */
/* @0x2a7164 .word 0x312cf8d4 —— ldr.w r3, [r4, #0x12c] */
/* @0x2a7168 svclt #0x44071a —— lsls r2, r3, #0x1c ; itt mi */
/* @0x2a716c movwpl pc, #0x443 —— orr r3, r3, #0x2000 */
/* @0x2a7170 smlawtlo r12, r4, r8, pc —— str.w r3, [r4, #0x12c] */
/* @0x2a7174 ldrbmi r4, [r1], -r8, lsr #12 —— mov r0, r5 ; mov r1, sl */
/* @0x2a7178 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a717c stmdblt r8!, {r1, r5, r6, r8, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a718c */
/* @0x2a7180 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7184 .word 0xf0044632 —— mov r2, r6 ; bl #0x2abe50 */
/* @0x2a7188 strb pc, [r7, -r3, ror #28] —— b #0x2a701c */
/* @0x2a718c stmdbge r6, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x18 */
/* @0x2a7190 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7194 stmdblt r8!, {r1, r2, r4, r6, r8, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a71a4 */
/* @0x2a7198 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a719c .word 0xf0044632 —— mov r2, r6 ; bl #0x2ac0c8 */
/* @0x2a71a0 .word 0xe73bff93 —— b #0x2a701c */
/* @0x2a71a4 strtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r5 */

/* ---- png_handle_as_unknown 分支（0x2a71a8..0x2a7228）----
 * 0x2a71a8 bl 0x2a5fe4 png_handle_as_unknown(png_ptr, &chunk_name)；== 0 → 跳 0x2a722c 走主链。
 * != 0（该 chunk 被用户登记为"按 unknown 保留"）：
 *   0x2a71b6 chunk==IDAT → mode |= 0x04；
 *   0x2a71ce bl 0x2ada34 png_handle_unknown(png_ptr, info_ptr, length)；
 *   0x2a71d8 chunk==PLTE → mode |= 0x02，回循环头；
 *   0x2a71f2 chunk==IDAT → 完整校验：mode bit0（HAVE_IHDR）为 0 → png_error
 *     "Missing IHDR before IDAT"（串 @0x38c7da）；color_type(+0x1ea)==3 且 mode bit1（HAVE_PLTE）
 *     为 0 → png_error "Missing PLTE before IDAT"（串 @0x38c7f3）；否则返回。
 *   png_error 是尾跳（0x2a7222 add sp / pop / b.w 0x2a642c）—— noreturn 通道，出错即离栈。 */
/* @0x2a71a8 .word 0xff1cf7fe —— bl #0x2a5fe4 */
/* @0x2a71ac eorsle r2, sp, r0, lsl #16 —— cmp r0, #0 ; beq #0x2a722c */
/* @0x2a71b0 strbmi r4, [r9], -r8, lsr #12 —— mov r0, r5 ; mov r1, sb */
/* @0x2a71b4 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a71b8 stmdblt r8!, {r2, r6, r8, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a71c8 */
/* @0x2a71bc .word 0x312cf8d4 —— ldr.w r3, [r4, #0x12c] */
/* @0x2a71c0 movweq pc, #0x4043 —— orr r3, r3, #4 */
/* @0x2a71c4 smlawtlo r12, r4, r8, pc —— str.w r3, [r4, #0x12c] */
/* @0x2a71c8 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a71cc .word 0xf0064632 —— mov r2, r6 ; bl #0x2ada34 */
/* @0x2a71d0 qasxmi pc, r8, r1 —— mov r0, r5 */
/* @0x2a71d4 andhs r4, r4, #93323264 —— mov r1, fp ; movs r2, #4 */
/* @0x2a71d8 ldc p6, c15, [r2, #-60]! —— blx #0xb6c40 */
/* @0x2a71dc .word 0xf8d4b930 —— cbnz r0, #0x2a71ec ; ldr.w r3, [r4, #0x12c] */
/* @0x2a71e0 .word 0xf043312c —— orr r3, r3, #2 */
/* @0x2a71e4 .word 0xf8c40302 —— str.w r3, [r4, #0x12c] */
/* @0x2a71e8 ldr r3, [r7, -r12, lsr #2] —— b #0x2a701c */
/* @0x2a71ec strbmi r4, [r9], -r8, lsr #12 —— mov r0, r5 ; mov r1, sb */
/* @0x2a71f0 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a71f4 stmdahs r0, {r1, r2, r5, r8, r10, r11, sp, lr, pc} —— cmp r0, #0 */
/* @0x2a71f8 svcge #0x10f47f —— bne.w #0x2a701c */
/* @0x2a71fc .word 0x312cf8d4 —— ldr.w r3, [r4, #0x12c] */
/* @0x2a7200 strle r0, [r3], #-2008 —— lsls r0, r3, #0x1f ; bmi #0x2a720c */
/* @0x2a7204 strtmi r4, [r0], -r12, lsl #19 —— ldr r1, [pc, #0x230] ; mov r0, r4 */
/* @0x2a7208 and r4, r10, r9, ror r4 —— add r1, pc ; b #0x2a7222 */
/* @0x2a720c .word 0x21eaf894 —— ldrb.w r2, [r4, #0x1ea] */
/* @0x2a7210 .word 0xf0402a03 —— cmp r2, #3 ; bne.w #0x2a742c */
/* @0x2a7214 ldreq r8, [r9, r11, lsl #2] —— lsls r1, r3, #0x1e */
/* @0x2a7218 .word 0x8108f100 —— bmi.w #0x2a742c */
/* @0x2a721c strtmi r4, [r0], -r7, lsl #19 —— ldr r1, [pc, #0x21c] ; mov r0, r4 */
/* @0x2a7220 eorlt r4, sp, r9, ror r4 —— add r1, pc ; add sp, #0xb4 */
/* @0x2a7224 svcmi #0xf0e8bd —— pop.w {r4, r5, r6, r7, r8, sb, sl, fp, lr} */
/* @0x2a7228 stmdblt r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} —— b.w #0x2a642c */

/* ---- 主链：PLTE → IDAT（0x2a722c..0x2a7286）----
 * 0x2a723e bl 0x2abf64 png_handle_PLTE。
 * 0x2a724a memcmp(&chunk_name,"IDAT",4) 命中 →
 *   0x2a7258 mode bit0 为 0 → png_error "Missing IHDR before IDAT"；
 *   0x2a726c color_type==3（PALETTE）且 mode bit1 为 0 → png_error "Missing PLTE before IDAT"；
 *   0x2a727a png_ptr->idat_size(+0x1d0) = length；mode |= 0x04；返回 0x2a742c。
 *   ⇒ **读完第一个 IDAT 头就结束**，像素数据由 png_read_image / png_read_row 接走。 */
/* @0x2a722c ldrbmi r4, [r9], -r8, lsr #12 —— mov r0, r5 ; mov r1, fp */
/* @0x2a7230 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7234 stmdblt r8!, {r1, r2, r8, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7244 */
/* @0x2a7238 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a723c .word 0xf0044632 —— mov r2, r6 ; bl #0x2abf64 */
/* @0x2a7240 usat pc, #0xb, r1, lsl #29 —— b #0x2a701c */
/* @0x2a7244 strbmi r4, [r9], -r8, lsr #12 —— mov r0, r5 ; mov r1, sb */
/* @0x2a7248 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a724c ldmiblt r8, {r1, r3, r4, r5, r6, r7, r10, r11, sp, lr, pc} ^ —— cbnz r0, #0x2a7288 */
/* @0x2a7250 .word 0x312cf8d4 —— ldr.w r3, [r4, #0x12c] */
/* @0x2a7254 strle r0, [r3], #-2010 —— lsls r2, r3, #0x1f ; bmi #0x2a7260 */
/* @0x2a7258 qsub16mi r4, r0, r9 —— ldr r1, [pc, #0x1e4] ; mov r0, r4 */
/* @0x2a725c and r4, r8, r9, ror r4 —— add r1, pc ; b #0x2a7272 */
/* @0x2a7260 .word 0x21eaf894 —— ldrb.w r2, [r4, #0x1ea] */
/* @0x2a7264 .word 0xd1062a03 —— cmp r2, #3 ; bne #0x2a7276 */
/* @0x2a7268 strle r0, [r4], #-1947 —— lsls r3, r3, #0x1e ; bmi #0x2a7276 */
/* @0x2a726c qsub16mi r4, r0, r5 —— ldr r1, [pc, #0x1d4] ; mov r0, r4 */
/* @0x2a7270 .word 0xf7ff4479 —— add r1, pc ; bl #0x2a642c */
/* @0x2a7274 .word 0xf8d4f8db —— ldr.w r3, [r4, #0x12c] */
/* @0x2a7278 .word 0xf8c4312c —— str.w r6, [r4, #0x1d0] */
/* @0x2a727c .word 0xf04361d0 —— orr r3, r3, #4 */
/* @0x2a7280 .word 0xf8c40304 —— str.w r3, [r4, #0x12c] */
/* @0x2a7284 sbcs r3, r1, r12, lsr #2 —— b #0x2a742c */

/* ---- 其余 19 个 ancillary handler（0x2a7288..0x2a741e）----
 * 每个都是「memcmp 4 字节 → bl handler → b 循环头」三段式，参数恒为 (r4=png_ptr, r7=info_ptr,
 * r6=length)。顺序即上列分派链；这里不解释各 handler 语义（它们不在本卡区间）。 */
/* @0x2a7288 stmdbge r10, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x28 */
/* @0x2a728c .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7290 stmdblt r8!, {r3, r4, r6, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a72a0 */
/* @0x2a7294 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7298 .word 0xf0054632 —— mov r2, r6 ; bl #0x2acd60 */
/* @0x2a729c ldrt pc, [sp], r1, ror #26 —— b #0x2a701c */
/* @0x2a72a0 stmdbge r12, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x30 */
/* @0x2a72a4 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a72a8 stmdblt r8!, {r2, r3, r6, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a72b8 */
/* @0x2a72ac ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a72b0 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ac328 */
/* @0x2a72b4 .word 0xe6b1f839 —— b #0x2a701c */
/* @0x2a72b8 stmdbge lr, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x38 */
/* @0x2a72bc .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a72c0 stmdblt r8!, {r6, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a72d0 */
/* @0x2a72c4 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a72c8 .word 0xf0044632 —— mov r2, r6 ; bl #0x2ac110 */
/* @0x2a72cc strt pc, [r5], r1, lsr #30 —— b #0x2a701c */
/* @0x2a72d0 ldmdbge r0, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x40 */
/* @0x2a72d4 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a72d8 stmdblt r8!, {r2, r4, r5, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a72e8 */
/* @0x2a72dc ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a72e0 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ace98 */
/* @0x2a72e4 .word 0xe699fdd9 —— b #0x2a701c */
/* @0x2a72e8 ldmdbge r6, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x58 */
/* @0x2a72ec .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a72f0 stmdblt r8!, {r3, r5, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7300 */
/* @0x2a72f4 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a72f8 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ad030 */
/* @0x2a72fc pkhbt pc, sp, r9, lsl #29 —— b #0x2a701c */
/* @0x2a7300 ldmdbge r8, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x60 */
/* @0x2a7304 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7308 stmdblt r8!, {r2, r3, r4, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7318 */
/* @0x2a730c ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7310 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ad128 */
/* @0x2a7314 str pc, [r1], r9, lsl #30 —— b #0x2a701c */
/* @0x2a7318 ldmdbge lr, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x78 */
/* @0x2a731c .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7320 stmdblt r8!, {r4, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7330 */
/* @0x2a7324 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7328 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ad350 */
/* @0x2a732c uhadd16 pc, r5, r1 —— b #0x2a701c */
/* @0x2a7330 ldmdbge r10, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x68 */
/* @0x2a7334 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7338 stmdblt r8!, {r2, r7, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7348 */
/* @0x2a733c ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7340 .word 0xf0054632 —— mov r2, r6 ; bl #0x2acf58 */
/* @0x2a7344 strbt pc, [r9], -r9, lsl #28 —— b #0x2a701c */
/* @0x2a7348 ldmdbge r12, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x70 */
/* @0x2a734c .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7350 stmdblt r8!, {r3, r4, r5, r6, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7360 */
/* @0x2a7354 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7358 .word 0xf0044632 —— mov r2, r6 ; bl #0x2ac238 */
/* @0x2a735c ldrb pc, [sp], -sp, ror #30 —— b #0x2a701c */
/* @0x2a7360 stmdbge r2!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x88 */
/* @0x2a7364 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7368 stmdblt r8!, {r2, r3, r5, r6, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7378 */
/* @0x2a736c ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7370 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ac694 */
/* @0x2a7374 ldrb pc, [r1], -pc, lsl #19 —— b #0x2a701c */
/* @0x2a7378 ldmdbge r2, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x48 */
/* @0x2a737c .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7380 stmdblt r8!, {r5, r6, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7390 */
/* @0x2a7384 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7388 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ac814 */
/* @0x2a738c strb pc, [r5], -r3, asr #20 —— b #0x2a701c */
/* @0x2a7390 stmdbge r0!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x80 */
/* @0x2a7394 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7398 stmdblt r8!, {r2, r4, r6, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a73a8 */
/* @0x2a739c ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a73a0 .word 0xf0054632 —— mov r2, r6 ; bl #0x2ac9ec */
/* @0x2a73a4 ldrt pc, [r9], -r3, lsr #22 —— b #0x2a701c */
/* @0x2a73a8 stmdbge r4!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x90 */
/* @0x2a73ac .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a73b0 stmdblt r8!, {r3, r6, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a73c0 */
/* @0x2a73b4 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a73b8 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ad584 */
/* @0x2a73bc strt pc, [sp], -r3, ror #17 —— b #0x2a701c */
/* @0x2a73c0 stmdbge r6!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x98 */
/* @0x2a73c4 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a73c8 stmdblt r8!, {r2, r3, r4, r5, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a73d8 */
/* @0x2a73cc ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a73d0 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ad4d0 */
/* @0x2a73d4 qsub16 pc, r1, sp —— b #0x2a701c */
/* @0x2a73d8 stmdbge r8!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0xa0 */
/* @0x2a73dc .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a73e0 stmdblt r8!, {r4, r5, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a73f0 */
/* @0x2a73e4 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a73e8 .word 0xf0054632 —— mov r2, r6 ; bl #0x2acbec */
/* @0x2a73ec ssub8 pc, r5, pc —— b #0x2a701c */
/* @0x2a73f0 stmdbge r10!, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0xa8 */
/* @0x2a73f4 .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a73f8 stmdblt r8!, {r2, r5, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7408 */
/* @0x2a73fc ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7400 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ad6cc */
/* @0x2a7404 str pc, [r9], -r3, ror #18 —— b #0x2a701c */
/* @0x2a7408 ldmdbge r4, {r3, r5, r9, r10, lr} —— mov r0, r5 ; add r1, sp, #0x50 */
/* @0x2a740c .word 0xf60f2204 —— movs r2, #4 ; blx #0xb6c40 */
/* @0x2a7410 stmdblt r8!, {r3, r4, r10, r11, sp, lr, pc} —— cbnz r0, #0x2a7420 */
/* @0x2a7414 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7418 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ad850 */
/* @0x2a741c ldrb pc, [sp, #0xa19]! —— b #0x2a701c */

/* ---- 全不命中 → png_handle_unknown，然后回循环 ---- */
/* @0x2a7420 ldrtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r7 */
/* @0x2a7424 .word 0xf0064632 —— mov r2, r6 ; bl #0x2ada34 */
/* @0x2a7428 ldrb pc, [r7, #0xb05]! —— b #0x2a701c */

/* ---- 唯一出口 ----
 * 0x2a742c add sp,#0xb4 / 0x2a742e pop.w {r4-r11,pc}：所有正常路径（双 NULL 门、IDAT 命中、
 * 签名后空图）都汇到这里；出错路径不走这里而走 png_error 尾跳。
 * 0x2a7434 是本函数唯一的池字（0x000e88f6，与 add r8,pc 一起构成名字表基址），不是指令。 */
/* @0x2a742c pop {r0, r2, r3, r5, r12, sp, pc} —— add sp, #0xb4 ; pop.w {r4, r5, r6, r7, r8, sb, sl, fp, pc} */
/* @0x2a7430 svclt #0x8ff0 —— （0x2a742e 起 32 位指令的后半字，非指令起点） */
/* @0x2a7434 strdeq r8, r9, [lr], -r6 —— （数据字：literal pool） */
/* @0x2a7438 andeq r5, lr, lr, asr #11 —— （数据字：literal pool） */
/* @0x2a743c andeq r5, lr, pc, asr #11 —— （数据字：literal pool） */
/* @0x2a7440 andeq r5, lr, r10, ror r5 —— （数据字：literal pool） */
/* @0x2a7444 andeq r5, lr, pc, ror r5 —— （数据字：literal pool） */

/* ════════════════════════════════════════════════════════════════════
 * 节 2/3  anon_2a7e2c（0x2a7e2c..0x2a804c，544 B，201 条）= 5 个函数
 *   0x2a7e2c png_destroy_read_struct  140 B  54 条
 *   0x2a7eb8 png_set_read_status_fn     8 B   3 条
 *   0x2a7ec0 png_read_png             324 B 123 条
 *   0x2a8004 png_default_read_data     44 B  16 条
 *   0x2a8030 png_read_data             28 B   5 条
 *   调了谁（26 个点）：png_free_data×3 / png_destroy_struct_2×3 / png_malloc×2 / png_error /
 *     png_read_destroy / png_read_info / png_read_update_info / png_read_image / png_get_rowbytes /
 *     png_set_{strip_16,strip_alpha,expand,gray_to_rgb,bgr,swap,packswap,shift,swap_alpha,
 *     invert_alpha,invert_mono} 各 1 / fread@plt 1(尾) —— 明细见下。
 *   谁调它（22 个点，全库扫描）：_Z11loadTextureP7Texture ×4(0x18981c/0x1898c0/0x189900/0x189944)、
 *     _Z11loadTextureP3zipPKcPiS3_ ×4(0x29012c/0x29017c/0x2901c0/0x290204)、
 *     _Z14getTextureInfoP7Texture ×3、_Z13ReadPNGHeaderP9yyPNGFile ×3、_Z7ReadPNGP9yyPNGFile ×3、
 *     _Z7FreePNGP9yyPNGFile(0x189b3c) ×1(0x189b50)；另有 libpng 内部 4 点，**全部打 png_read_data**：
 *     png_read_sig@0x2abbb6 / png_crc_read@0x2abc16 / png_crc_error@0x2abc5e /
 *     png_read_chunk_header@0x2adbe4（即 png_read_data 是全库读字节的唯一漏斗）。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7e2c 0x2a804c anon_2a7e2c */

/* ---- 0x2a7e2c png_destroy_read_struct（140 B / 54 条）----
 * 契约：void png_destroy_read_struct(png_structpp pp, png_infopp info_pp, png_infopp end_pp)
 *   r0=pp, r1=info_pp, r2=end_pp。
 *   0x2a7e36 cmp r0,#0 / beq 0x2a7eb4 → pp == NULL 直接返回
 *   0x2a7e3a ldr r4,[r0] —— 取 *pp；0x2a7e3c cmp r4,#0 / beq → *pp == NULL 返回
 *   0x2a7e40 ldr fp,[r4,#0x2f0] = mem_ptr；0x2a7e44 ldr sl,[r4,#0x2e8] = free_fn
 *   0x2a7e4c/0x2a7e54 解引用两个 info 二级指针（空则取 0）
 *   0x2a7e5e bl 0x2a7c64 png_read_destroy(png_ptr, info, end_info)
 *   info 非空：0x2a7e70 png_free_data(png_ptr, info, 0x4000, -1) → 0x2a7e7a png_destroy_struct_2(
 *     info, mem_ptr, free_fn) → 0x2a7e80 *info_pp = NULL；end_info 同构（0x2a7e92 / 0x2a7e9c / 0x2a7ea2）
 *   0x2a7eaa png_destroy_struct_2(png_ptr, mem_ptr, free_fn)；0x2a7eb0 *pp = NULL
 *   ⇒ 三条指针都被置 NULL（幂等销毁）；自定义分配器随 png_ptr 的 mem_ptr/free_fn 一并对 info 生效。
 *   png_free_data 的 mask 0x4000 与 num -1 是本件实测量，语义名（PNG_FREE_*）见 open 4。 */
/* @0x2a7e2c svcmi #0xf8e92d —— push.w {r3, r4, r5, r6, r7, r8, sb, sl, fp, lr} */
/* @0x2a7e30 ldrmi r4, [r7], -r8, lsl #13 —— mov r8, r1 ; mov r7, r2 */
/* @0x2a7e34 stmdahs r0, {r0, r7, r9, r10, lr} —— mov sb, r0 ; cmp r0, #0 */
/* @0x2a7e38 stmdavs r4, {r2, r3, r4, r5, r12, lr, pc} —— beq #0x2a7eb4 ; ldr r4, [r0] */
/* @0x2a7e3c eorsle r2, r9, r0, lsl #24 —— cmp r4, #0 ; beq #0x2a7eb4 */
/* @0x2a7e40 rscslt pc, r0, #212, #16 —— ldr.w fp, [r4, #0x2f0] */
/* @0x2a7e44 rscge pc, r8, #212, #16 —— ldr.w sl, [r4, #0x2e8] */
/* @0x2a7e48 stmdavs lr, {r0, r3, r8, r12, sp, pc} —— cbz r1, #0x2a7e4e ; ldr r6, [r1] */
/* @0x2a7e4c strmi lr, [lr], -r0 —— b #0x2a7e50 ; mov r6, r1 */
/* @0x2a7e50 ldmdavs sp!, {r0, r1, r2, r3, r8, r12, sp, pc} —— cbz r7, #0x2a7e56 ; ldr r5, [r7] */
/* @0x2a7e54 ldrtmi lr, [sp], -r0 —— b #0x2a7e58 ; mov r5, r7 */
/* @0x2a7e58 ldrtmi r4, [r1], -r0, lsr #12 —— mov r0, r4 ; mov r1, r6 */
/* @0x2a7e5c .word 0xf7ff462a —— mov r2, r5 ; bl #0x2a7c64 */
/* @0x2a7e60 cmnlt lr, r1, lsl #30 —— cbz r6, #0x2a7e84 */
/* @0x2a7e64 .word 0x33fff04f —— mov.w r3, #-1 */
/* @0x2a7e68 ldrtmi r4, [r1], -r0, lsr #12 —— mov r0, r4 ; mov r1, r6 */
/* @0x2a7e6c addmi pc, r0, #1325400064 —— mov.w r2, #0x4000 */
/* @0x2a7e70 mcr2 p7, #0x5, pc, c6, c13, #0x7 —— bl #0x2a5bc0 */
/* @0x2a7e74 uasxmi r4, r9, r0 —— mov r0, r6 ; mov r1, fp */
/* @0x2a7e78 .word 0xf7fe4652 —— mov r2, sl ; bl #0x2a6c5e */
/* @0x2a7e7c movwhs pc, #0xef0 —— movs r3, #0 */
/* @0x2a7e80 andlo pc, r0, r8, asr #17 —— str.w r3, [r8] */
/* @0x2a7e84 .word 0xf04fb175 —— cbz r5, #0x2a7ea4 ; mov.w r3, #-1 */
/* @0x2a7e88 qsub8mi r3, r0, pc —— mov r0, r4 */
/* @0x2a7e8c .word 0xf44f4629 —— mov r1, r5 ; mov.w r2, #0x4000 */
/* @0x2a7e90 .word 0xf7fd4280 —— bl #0x2a5bc0 */
/* @0x2a7e94 qadd8mi pc, r8, r5 —— mov r0, r5 */
/* @0x2a7e98 usaxmi r4, r2, r9 —— mov r1, fp ; mov r2, sl */
/* @0x2a7e9c mrc2 p7, #0x6, apsr_nzcv, c15, c14, #0x7 —— bl #0x2a6c5e */
/* @0x2a7ea0 eorsvs r2, r11, r0, lsl #6 —— movs r3, #0 ; str r3, [r7] */
/* @0x2a7ea4 ldrbmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, fp */
/* @0x2a7ea8 .word 0xf7fe4652 —— mov r2, sl ; bl #0x2a6c5e */
/* @0x2a7eac movwhs pc, #0xed8 —— movs r3, #0 */
/* @0x2a7eb0 andlo pc, r0, r9, asr #17 —— str.w r3, [sb] */
/* @0x2a7eb4 svchi #0xf8e8bd —— pop.w {r3, r4, r5, r6, r7, r8, sb, sl, fp, pc} */

/* ---- 0x2a7eb8 png_set_read_status_fn（8 B / 3 条）----
 * 0x2a7eb8 cbz r0 → NULL 直接 bx lr；否则 0x2a7eba str.w r1,[r0,#0x25c] = read_status_fn。
 * 唯一的 8 字节 setter：只写一个函数指针，不碰 flags/transformations。 */
/* @0x2a7eb8 .word 0xf8c0b108 —— cbz r0, #0x2a7ebe ; str.w r1, [r0, #0x25c] */
/* @0x2a7ebc .word 0x4770125c —— bx lr */

/* ---- 0x2a7ec0 png_read_png（324 B / 123 条）----
 * 契约：void png_read_png(png_structp png, png_infop info, int transforms, png_voidp params)
 *   r0=png, r1=info, r2=transforms, r3=params。
 *   0x2a7ec8 cbz r0 → 返回；0x2a7ece bl png_read_info（读完所有前置 chunk）
 *   0x2a7ed2 ldr r3,[info+4]=height；>= 0x40000000 → png_error
 *     "Image is too high to process with png_read_png()"（串 @0x38c8c9）
 *   变换位 → setter（位号即 PNG_TRANSFORM_* 的位）：
 *     bit0  0x2a7eea png_set_strip_16     bit1  0x2a7ef4 png_set_strip_alpha
 *     bit3  0x2a7efe png_set_packswap     bit4  0x2a7f1e png_set_expand
 *            （bit4 有条件：bit_depth(+0x1eb)>7 && color_type!=3 && (info->valid bit4)==0，
 *              即 8 位以上、非调色板、无 tRNS 才展开）
 *     bit5  0x2a7f28 png_set_invert_mono  bit6  0x2a7f3c png_set_shift(png, info+0x44)
 *     bit7  0x2a7f46 png_set_bgr          bit8  0x2a7f50 png_set_swap_alpha
 *     bit9  0x2a7f5a png_set_swap         bit10 0x2a7f64 png_set_invert_alpha
 *     bit13 0x2a7f6e png_set_gray_to_rgb
 *     没有分支的位：bit2（PACKING）、bit11/12（STRIP_FILLER*）—— 本编译单元把这些支持裁掉了。
 *   0x2a7f76 png_read_update_info(png, info)
 *   0x2a7f82 png_free_data(png, info, 0x40=PNG_FREE_ROWS, 0) —— 丢掉旧行指针
 *   0x2a7f86 ldr r6,[info+0xf8] = row_pointers；为 0 则：png_malloc(height*4)（0x2a7fb0）→
 *     info->row_pointers，逐项清零（0x2a7fc6），info->free_me(+0xb8) |= 0x40（0x2a7fd8），
 *     再按行 png_get_rowbytes → png_malloc（0x2a7ff2）填满
 *   0x2a7f92 png_read_image(png, info->row_pointers)
 *   0x2a7f9c info->valid(+8) |= 0x8000（PNG_INFO_IDAT）；0x2a7fa6 尾跳 png_read_end（0x2a787c）
 *   ⇒ 一次调用完成「读头 → 应用变换 → 分配行缓冲 → 读像素 → 读尾」，params 全程未用（r3 不进任何调用）。 */
/* @0x2a7ec0 .word 0x460db5f8 —— push {r3, r4, r5, r6, r7, lr} ; mov r5, r1 */
/* @0x2a7ec4 .word 0x46044616 —— mov r6, r2 ; mov r4, r0 */
/* @0x2a7ec8 .word 0xf0002800 —— cmp r0, #0 ; beq.w #0x2a7ffe */
/* @0x2a7ecc .word 0xf7ff8098 —— bl #0x2a6ff0 */
/* @0x2a7ed0 stmdavs r11!, {r0, r1, r2, r3, r7, r11, r12, sp, lr, pc} ^ —— ldr r3, [r5, #4] */
/* @0x2a7ed4 svcmi #0x80f1b3 —— cmp.w r3, #0x40000000 */
/* @0x2a7ed8 stmdbmi r9, {r2, r8, r9, r12, lr, pc} ^ —— blo #0x2a7ee4 ; ldr r1, [pc, #0x124] */
/* @0x2a7edc ldrbtmi r4, [r9], #-1568 —— mov r0, r4 ; add r1, pc */
/* @0x2a7ee0 blx 0xfebe5ee0 <b2_toiTime+0xfffffffffe48ca3c> —— bl #0x2a642c */
/* @0x2a7ee4 strle r0, [r2, #-0x7f1] —— lsls r1, r6, #0x1f ; bpl #0x2a7eee */
/* @0x2a7ee8 .word 0xf0004620 —— mov r0, r4 ; bl #0x2a8184 */
/* @0x2a7eec ldreq pc, [r2, r11, asr #18]! —— lsls r2, r6, #0x1e */
/* @0x2a7ef0 strtmi sp, [r0], -r2, lsl #10 —— bpl #0x2a7ef8 ; mov r0, r4 */
/* @0x2a7ef4 .word 0xf94ef000 —— bl #0x2a8194 */
/* @0x2a7ef8 strle r0, [r2, #-0x733] —— lsls r3, r6, #0x1c ; bpl #0x2a7f02 */
/* @0x2a7efc .word 0xf0074620 —— mov r0, r4 ; bl #0x2af77e */
/* @0x2a7f00 .word 0x06f7fc3e —— lsls r7, r6, #0x1b */
/* @0x2a7f04 .word 0xf894d50d —— bpl #0x2a7f22 ; ldrb.w r3, [r4, #0x1eb] */
/* @0x2a7f08 blhs 0x4746bc <g_RomDisk+0x7ce9c> —— cmp r3, #7 */
/* @0x2a7f0c .word 0xf894d906 —— bls #0x2a7f1c ; ldrb.w r3, [r4, #0x1ea] */
/* @0x2a7f10 blhs 0x3746c0 <_ZTS13C_UTF16String+0xb76c> —— cmp r3, #3 */
/* @0x2a7f14 stmvs r11!, {r1, r12, lr, pc} —— beq #0x2a7f1c ; ldr r3, [r5, #8] */
/* @0x2a7f18 strle r0, [r2, #-0x6d8] —— lsls r0, r3, #0x1b ; bpl #0x2a7f22 */
/* @0x2a7f1c .word 0xf0004620 —— mov r0, r4 ; bl #0x2a8790 */
/* @0x2a7f20 .word 0x06b1fc37 —— lsls r1, r6, #0x1a */
/* @0x2a7f24 strtmi sp, [r0], -r2, lsl #10 —— bpl #0x2a7f2c ; mov r0, r4 */
/* @0x2a7f28 stc2 p0, c15, [pc], {7} —— bl #0x2af84a */
/* @0x2a7f2c strle r0, [r7, #-0x672] —— lsls r2, r6, #0x19 ; bpl #0x2a7f40 */
/* @0x2a7f30 ldreq r6, [r11, r11, lsr #17] —— ldr r3, [r5, #8] ; lsls r3, r3, #0x1e */
/* @0x2a7f34 strtmi sp, [r0], -r4, lsl #10 —— bpl #0x2a7f40 ; mov r0, r4 */
/* @0x2a7f38 mrseq pc, spsr —— add.w r1, r5, #0x44 */
/* @0x2a7f3c stc2 p0, c15, [r11], #-28 —— bl #0x2af796 */
/* @0x2a7f40 strle r0, [r2, #-0x637] —— lsls r7, r6, #0x18 ; bpl #0x2a7f4a */
/* @0x2a7f44 .word 0xf0074620 —— mov r0, r4 ; bl #0x2af738 */
/* @0x2a7f48 ldrbeq pc, [r0, #0xbf7]! —— lsls r0, r6, #0x17 */
/* @0x2a7f4c strtmi sp, [r0], -r2, lsl #10 —— bpl #0x2a7f54 ; mov r0, r4 */
/* @0x2a7f50 stc2l p0, c15, [r11], #-28 —— bl #0x2af82a */
/* @0x2a7f54 strle r0, [r2, #-0x5b1] —— lsls r1, r6, #0x16 ; bpl #0x2a7f5e */
/* @0x2a7f58 .word 0xf0074620 —— mov r0, r4 ; bl #0x2af748 */
/* @0x2a7f5c ldrbeq pc, [r2, #-0xbf5]! —— lsls r2, r6, #0x15 */
/* @0x2a7f60 strtmi sp, [r0], -r2, lsl #10 —— bpl #0x2a7f68 ; mov r0, r4 */
/* @0x2a7f64 stc2l p0, c15, [r9], #-28 —— bl #0x2af83a */
/* @0x2a7f68 strle r0, [r2, #-0x4b3] —— lsls r3, r6, #0x12 ; bpl #0x2a7f72 */
/* @0x2a7f6c .word 0xf0004620 —— mov r0, r4 ; bl #0x2a880a */
/* @0x2a7f70 strtmi pc, [r0], -r12, asr #24 —— mov r0, r4 */
/* @0x2a7f74 .word 0xf7ff4629 —— mov r1, r5 ; bl #0x2a7448 */
/* @0x2a7f78 strtmi pc, [r0], -r7, ror #20 —— mov r0, r4 */
/* @0x2a7f7c subhs r4, r0, #42991616 —— mov r1, r5 ; movs r2, #0x40 */
/* @0x2a7f80 .word 0xf7fd2300 —— movs r3, #0 ; bl #0x2a5bc0 */
/* @0x2a7f84 .word 0xf8d5fe1d —— ldr.w r6, [r5, #0xf8] */
/* @0x2a7f88 ldrshlt r6, [r6, #-8]! —— cbz r6, #0x2a7faa */
/* @0x2a7f8c .word 0xf8d54620 —— mov r0, r4 ; ldr.w r1, [r5, #0xf8] */
/* @0x2a7f90 .word 0xf7ff10f8 —— bl #0x2a7840 */
/* @0x2a7f94 stmvs r11!, {r0, r2, r4, r6, r10, r11, r12, sp, lr, pc} —— ldr r3, [r5, #8] */
/* @0x2a7f98 strtmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, r5 */
/* @0x2a7f9c movwmi pc, #0x443 —— orr r3, r3, #0x8000 */
/* @0x2a7fa0 pop {r0, r1, r3, r5, r7, sp, lr} —— str r3, [r5, #8] ; pop.w {r3, r4, r5, r6, r7, lr} */
/* @0x2a7fa4 .word 0xf7ff40f8 —— b.w #0x2a787c */
/* @0x2a7fa8 stmdavs r9!, {r0, r3, r5, r6, r10, r11, r12, sp, pc} ^ —— ldr r1, [r5, #4] */
/* @0x2a7fac addeq r4, r9, r0, lsr #12 —— mov r0, r4 ; lsls r1, r1, #2 */
/* @0x2a7fb0 mrc2 p7, #0x3, apsr_nzcv, c6, c14, #0x7 —— bl #0x2a6ca0 */
/* @0x2a7fb4 shasxmi r4, r1, r3 —— mov r3, r6 ; mov r1, r6 */
/* @0x2a7fb8 rscseq pc, r8, r5, asr #17 —— str.w r0, [r5, #0xf8] */
/* @0x2a7fbc addsmi r6, r3, #6946816 —— ldr r2, [r5, #4] ; cmp r3, r2 */
/* @0x2a7fc0 .word 0xf8d5d205 —— bhs #0x2a7fce ; ldr.w r2, [r5, #0xf8] */
/* @0x2a7fc4 .word 0xf84220f8 —— str.w r1, [r2, r3, lsl #2] */
/* @0x2a7fc8 movwlo r1, #0x1023 —— adds r3, #1 */
/* @0x2a7fcc .word 0xf8d5e7f6 —— b #0x2a7fbc ; ldr.w r3, [r5, #0xb8] */
/* @0x2a7fd0 .word 0x260030b8 —— movs r6, #0 */
/* @0x2a7fd4 movteq pc, #0x43 —— orr r3, r3, #0x40 */
/* @0x2a7fd8 adcslo pc, r8, r5, asr #17 —— str.w r3, [r5, #0xb8] */
/* @0x2a7fdc addsmi r6, lr, #7012352 —— ldr r3, [r5, #4] ; cmp r6, r3 */
/* @0x2a7fe0 .word 0x4629dad4 —— bge #0x2a7f8c ; mov r1, r5 */
/* @0x2a7fe4 .word 0xf8d54620 —— mov r0, r4 ; ldr.w r7, [r5, #0xf8] */
/* @0x2a7fe8 .word 0xf7fe70f8 —— bl #0x2a6574 */
/* @0x2a7fec strmi pc, [r1], -r3, asr #21 —— mov r1, r0 */
/* @0x2a7ff0 .word 0xf7fe4620 —— mov r0, r4 ; bl #0x2a6ca0 */
/* @0x2a7ff4 .word 0xf847fe55 —— str.w r0, [r7, r6, lsl #2] */
/* @0x2a7ff8 strlo r0, [r1], -r6, lsr #32 —— adds r6, #1 */
/* @0x2a7ffc ldcllt p7, c14, [r8, #952]! —— b #0x2a7fdc ; pop {r3, r4, r5, r6, r7, pc} */
/* @0x2a8000 andeq r4, lr, r7, ror #19 —— （数据字：literal pool） */

/* ---- 0x2a8004 png_default_read_data（44 B / 16 条）----
 * 契约：void png_default_read_data(png_structp png, png_bytep data, size_t length)
 *   0x2a800a cbz r0 → 返回（png == NULL 静默）
 *   0x2a800e ldr r3,[png+0x118] = io_ptr（FILE*）；参数按 fread(data, 1, length, file) 摆：
 *     r0=data(r1 换手) / r1=1 / r2=length / r3=io_ptr
 *   0x2a8014 blx 0xb68c8 = fread@plt
 *   0x2a8018 cmp r0,r5（返回值 vs length）；不等 → 0x2a8026 尾跳 png_error(png, "Read Error")
 *   ⇒ 短读一律 png_error，不重试、不部分填充。 */
/* @0x2a8004 sasxmi r11, r5, r8 —— push {r3, r4, r5, lr} ; mov r5, r2 */
/* @0x2a8008 cmnlt r0, r4, lsl #12 —— mov r4, r0 ; cbz r0, #0x2a802a */
/* @0x2a800c .word 0xf8d44608 —— mov r0, r1 ; ldr.w r3, [r4, #0x118] */
/* @0x2a8010 .word 0x21013118 —— movs r1, #1 */
/* @0x2a8014 mrrc p6, #0x0, pc, r8, c14 —— blx #0xb68c8 */
/* @0x2a8018 andle r4, r6, r8, lsr #5 —— cmp r0, r5 ; beq #0x2a802a */
/* @0x2a801c strtmi r4, [r0], -r3, lsl #18 —— ldr r1, [pc, #0xc] ; mov r0, r4 */
/* @0x2a8020 ldrhtmi lr, [r8], -sp —— pop.w {r3, r4, r5, lr} */
/* @0x2a8024 .word 0xf7fe4479 —— add r1, pc ; b.w #0x2a642c */
/* @0x2a8028 vldmdblt r8!, {s22} —— pop {r3, r4, r5, pc} */
/* @0x2a802c ldrdeq r4, r5, [lr], -r2 —— （数据字：literal pool） */

/* ---- 0x2a8030 png_read_data（28 B / 5 条）----
 * 契约：void png_read_data(png_structp png, png_bytep data, size_t length)
 *   0x2a8032 ldr.w r3,[png+0x114] = read_data_fn；cbz → 返回（未设回调时静默丢数据）
 *   0x2a8038 blx r3 —— 间接调用用户回调，参数原样 (png, data, length)
 *   0x2a803a pop {r3,pc}：push {r3,lr} 只为保住 lr 与 8 字节栈对齐。
 *   ⇒ png_read_data 是 libpng 内部所有读字节的唯一漏斗；回调空则读请求被吞掉。 */
/* @0x2a8030 .word 0xf8d0b508 —— push {r3, lr} ; ldr.w r3, [r0, #0x114] */
/* @0x2a8034 .word 0xb10b3114 —— cbz r3, #0x2a803c */
/* @0x2a8038 stclt p7, c4, [r8, #-608] —— blx r3 ; pop {r3, pc} */
/* @0x2a803c pop {r1, r8, r11, lr} —— （未达：跳表/对齐填充） */
/* @0x2a8040 ldrbtmi r4, [r9], #-8 —— （未达：跳表/对齐填充） */
/* @0x2a8044 ldmiblt r2!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} ^ —— （未达：跳表/对齐填充） */
/* @0x2a8048 strheq r4, [lr], -pc —— （未达：跳表/对齐填充） */

/* ════════════════════════════════════════════════════════════════════
 * 节 3/3  anon_2a804c（0x2a804c..0x2a87b0，1892 B，660 条）= 8 个函数
 *   0x2a804c png_set_read_fn        80 B   26 条
 *   0x2a809c png_set_crc_action    140 B   56 条（含两张 tbb 跳表）
 *   0x2a8128 png_set_background     92 B   29 条
 *   0x2a8184 png_set_strip_16       16 B    5 条
 *   0x2a8194 png_set_strip_alpha    16 B    5 条
 *   0x2a81a4 png_set_quantize     1426 B  507 条
 *   0x2a8738 png_set_gamma          88 B   23 条
 *   0x2a8790 png_set_expand         32 B    9 条
 *   调了谁（16 个点）：png_malloc×5 / png_free×5 / png_calloc×2 / png_warning×2 / png_malloc_warn /
 *     memset@plt（全部集中在 png_set_quantize 与 png_set_read_fn）。
 *   谁调它（9 个点，全库扫描）：png_read_png ×3（0x2a7eea strip_16 / 0x2a7ef4 strip_alpha /
 *     0x2a7f1e expand，即 PNG_TRANSFORM 位 0/1/4 的落点）、_Z11loadTextureP7Texture@0x1896b4、
 *     _Z14getTextureInfoP7Texture@0x189a94、_Z13ReadPNGHeaderP9yyPNGFile@0x189c48、
 *     _Z7ReadPNGP9yyPNGFile@0x189f50、_Z11loadTextureP3zipPKcPiS3_@0x28ff58（这 5 个都是 png_set_read_fn）、
 *     png_create_read_struct_2(0x2a6d4c)@0x2a6f84（png_set_read_fn(png, NULL, NULL) 设默认回调）。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a804c 0x2a87b0 anon_2a804c */

/* ---- 0x2a804c png_set_read_fn（80 B / 26 条）----
 * 契约：void png_set_read_fn(png_structp png, png_voidp io_ptr, png_rw_ptr read_data_fn)
 *   0x2a8050 cbz r0 → 返回
 *   0x2a8052 str.w r1,[png+0x118] —— io_ptr 无条件写
 *   0x2a8056 cbz r2 → 0x2a805e 取 GOT 里的 png_default_read_data 填 +0x114；
 *     否则 0x2a8058 str.w r2,[png+0x114]
 *   0x2a8068 ldr r3,[png+0x110] = write_data_fn；非空 → 清 0（0x2a8074）并两次
 *     png_warning(0x2a6474)：0x2a807a、0x2a8084（两条不同串）
 *   0x2a8088 movs r3,#0 / str.w r3,[png+0x210] —— 清一个 32 位字（字段身份 open 5）
 *   ⇒ 读回调与写回调互斥：给读设备设读回调时会把写回调打掉并告警。 */
/* @0x2a804c .word 0x4604b510 —— push {r4, lr} ; mov r4, r0 */
/* @0x2a8050 .word 0xf8c0b1e8 —— cbz r0, #0x2a808e ; str.w r1, [r0, #0x118] */
/* @0x2a8054 tstlt r2, r8, lsl r1 —— cbz r2, #0x2a805e */
/* @0x2a8058 tsths r4, r0, asr #17 —— str.w r2, [r0, #0x114] */
/* @0x2a805c blmi 0x5e0074 <g_SWFaavertbuff+0xcfac> —— b #0x2a8068 ; ldr r3, [pc, #0x30] */
/* @0x2a8060 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} —— add r3, pc ; ldr r3, [r3] */
/* @0x2a8064 tstlo r4, r0, asr #17 —— str.w r3, [r0, #0x114] */
/* @0x2a8068 ldrsblo pc, [r0, -r4] —— ldr.w r3, [r4, #0x110] */
/* @0x2a806c stmdbmi r9, {r0, r1, r5, r6, r8, r12, sp, pc} —— cbz r3, #0x2a8088 ; ldr r1, [pc, #0x24] */
/* @0x2a8070 strtmi r2, [r0], -r0, lsl #6 —— movs r3, #0 ; mov r0, r4 */
/* @0x2a8074 tstlo r0, r4, asr #17 —— str.w r3, [r4, #0x110] */
/* @0x2a8078 .word 0xf7fe4479 —— add r1, pc ; bl #0x2a6474 */
/* @0x2a807c stmdbmi r6, {r0, r1, r3, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} —— ldr r1, [pc, #0x18] */
/* @0x2a8080 ldrbtmi r4, [r9], #-1568 —— mov r0, r4 ; add r1, pc */
/* @0x2a8084 .word 0xf9f6f7fe —— bl #0x2a6474 */
/* @0x2a8088 .word 0xf8c42300 —— movs r3, #0 ; str.w r3, [r4, #0x210] */
/* @0x2a808c ldclt p2, c3, [r0, #-64] —— pop {r4, pc} */
/* @0x2a8090 andseq r9, r4, r0, asr #20 —— （数据字：literal pool） */
/* @0x2a8094 andeq r4, lr, r4, lsr #17 —— （数据字：literal pool） */
/* @0x2a8098 ldrdeq r4, r5, [lr], -r11 —— （数据字：literal pool） */

/* ---- 0x2a809c png_set_crc_action（140 B / 56 条）----
 * 契约：void png_set_crc_action(png_structp png, int crit_action, int ancil_action)
 *   0x2a80a6 subs r1,#2 / cmp #3 / bhi → crit_action 只对 2..5 走跳表，其余落到 0x2a80d4
 *   两张内联 tbb 跳表：0x2a80ac（crit，表 @0x2a80b0 = 0e 02 09 18）、
 *                    0x2a80e6（ancil，表 @0x2a80ea = 0f 16 03 0a 1c 00）
 *   作用点全是 flags(+0x130) 的两个位段：crit 用 0xC00、ancil 用 0x300。
 *     crit=2 → png_warning 后 flags &= ~0xC00（0x2a80cc/0x2a80d0）
 *     crit=3 → flags = (flags & ~0xC00) | 0x400（0x2a80b4）
 *     crit=4 → flags |= 0xC00（0x2a80c2）
 *     crit=5 与越界 → flags &= ~0xC00（0x2a80d4）
 *     ancil=1 → (flags & ~0x300) | 0x200（0x2a8108）
 *     ancil=2 与越界 → flags &= ~0x300（0x2a8116）
 *     ancil=3 → (flags & ~0x300) | 0x100（0x2a80f0）
 *     ancil=4 → flags |= 0x300（0x2a80fe）
 *     ancil=5 → 直接返回，不动 flags（0x2a8122）
 *   ⇒ 两个参数各自独立编码「校验失败时怎么办」，落在同一 flags 的两个相邻位段上。 */
/* @0x2a809c sasxmi r11, r5, r8 —— push {r3, r4, r5, lr} ; mov r5, r2 */
/* @0x2a80a0 stmdahs r0, {r2, r9, r10, lr} —— mov r4, r0 ; cmp r0, #0 */
/* @0x2a80a4 stmdblo r2, {r0, r2, r3, r4, r5, r12, lr, pc} —— beq #0x2a8122 ; subs r1, #2 */
/* @0x2a80a8 ldmdale r3, {r0, r1, r8, r11, sp} —— cmp r1, #3 ; bhi #0x2a80d4 */
/* @0x2a80ac .word 0xf001e8df —— tbb [pc, r1] */
/* @0x2a80b0 stmdane r9, {r1, r2, r3, r9} —— lsls r6, r1, #8 ; adds r1, r1, r0 */
/* @0x2a80b4 ldrsblo pc, [r0, -r0]! —— ldr.w r3, [r0, #0x130] ; adds r1, #0x30 */
/* @0x2a80b8 movtvs pc, #0x423 —— bic r3, r3, #0xc00 */
/* @0x2a80bc orrvs pc, r0, #1124073472 —— orr r3, r3, #0x400 ; str r0, [r0, #0x38] */
/* @0x2a80c0 .word 0xf8d0e00c —— b #0x2a80dc ; ldr.w r3, [r0, #0x130] */
/* @0x2a80c4 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 —— adds r1, #0x30 ; orr r3, r3, #0xc00 */
/* @0x2a80c8 and r6, r7, r0, asr #6 —— str r0, [r0, #0x34] ; b #0x2a80dc */
/* @0x2a80cc ldrbtmi r4, [r9], #-2325 —— ldr r1, [pc, #0x54] ; add r1, pc */
/* @0x2a80d0 .word 0xf9d0f7fe —— bl #0x2a6474 */
/* @0x2a80d4 ldrsblo pc, [r0, -r4]! —— ldr.w r3, [r4, #0x130] */
/* @0x2a80d8 movtvs pc, #0x423 —— bic r3, r3, #0xc00 ; str r0, [r0, #0x34] */
/* @0x2a80dc teqlo r0, r4, asr #17 —— str.w r3, [r4, #0x130] ; adds r1, #0x30 */
/* @0x2a80e0 bhs 0x3afa90 <error_g0017+0x8734> —— subs r2, r5, #1 ; cmp r2, #4 */
/* @0x2a80e4 ldm pc, {r0, r1, r2, r4, r11, r12, lr, pc} ^ —— bhi #0x2a8116 ; tbb [pc, r2] */
/* @0x2a80e8 strne pc, [pc], -r2 —— and r6, r2, #0xf000f ; asrs r7, r1, #0x18 */
/* @0x2a80ec andseq r0, r12, r3, lsl #20 —— lsrs r3, r0, #8 ; movs r4, r3 */
/* @0x2a80f0 ldrsblo pc, [r0, -r4]! —— ldr.w r3, [r4, #0x130] */
/* @0x2a80f4 movtvc pc, #0x423 —— bic r3, r3, #0x300 ; strb r0, [r0, #0xd] */
/* @0x2a80f8 orrvc pc, r0, #1124073472 —— orr r3, r3, #0x100 */
/* @0x2a80fc .word 0xf8d4e00f —— b #0x2a811e ; ldr.w r3, [r4, #0x130] */
/* @0x2a8100 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 —— orr r3, r3, #0x300 */
/* @0x2a8104 and r7, r10, r0, asr #6 —— strb r0, [r0, #0xd] ; b #0x2a811e */
/* @0x2a8108 ldrsblo pc, [r0, -r4]! —— ldr.w r3, [r4, #0x130] */
/* @0x2a810c movtvc pc, #0x423 —— bic r3, r3, #0x300 */
/* @0x2a8110 movwvc pc, #0x443 —— orr r3, r3, #0x200 ; strb r0, [r0, #0xc] */
/* @0x2a8114 .word 0xf8d4e003 —— b #0x2a811e ; ldr.w r3, [r4, #0x130] */
/* @0x2a8118 vld4.8 {d3, d5, d7, d9}, [r3:256], r0 —— bic r3, r3, #0x300 */
/* @0x2a811c .word 0xf8c47340 —— str.w r3, [r4, #0x130] */
/* @0x2a8120 ldclt p1, c3, [r8, #-192]! —— pop {r3, r4, r5, pc} */
/* @0x2a8124 andeq r4, lr, r0, asr #17 —— （数据字：literal pool） */

/* ---- 0x2a8128 png_set_background（92 B / 29 条）----
 * 契约：void png_set_background(png_structp png, png_const_color_16p bg, int gamma_code,
 *                              int need_expand, double background_gamma)
 *   r0=png, r1=bg, r2=gamma_code, r3=need_expand, d5=background_gamma（[sp] 传入）
 *   0x2a8132 cbnz r2 → 正常路；gamma_code == 0 → png_warning("Application must supply a known
 *     background gamma", 串 @0x38c9bb) 并返回（0x2a813c 尾跳 png_warning）
 *   0x2a8140 transformations(+0x134) |= 0x80（PNG_BACKGROUND）
 *   0x2a815a/0x2a8160/0x2a8166 把 png_color_16 三字段抄到 +0x1fc(word)/+0x200(word)/+0x204(half)
 *   0x2a8168 vstr s14 → +0x1f8（background_gamma，f64→f32）；0x2a816c strb r2 → +0x1f4（gamma_code）
 *   0x2a8148..0x2a8180 need_expand ? transformations |= 0x100 : 0，再 or 回。
 *   ⇒ 5 条实参全被消费，没有丢弃；bg 只读 10 字节（word/word/half）。 */
/* @0x2a8128 ldc p5, c11, [sp, #192] —— push {r4, r5, lr} ; vldr d7, [sp, #0xc] */
/* @0x2a812c strmi r7, [r4], -r3, lsl #22 —— mov r4, r0 */
/* @0x2a8130 stmdblt r10!, {r3, r5, r8, r9, r12, sp, pc} —— cbz r0, #0x2a817e ; cbnz r2, #0x2a8140 */
/* @0x2a8134 pop {r1, r4, r8, r11, lr} —— ldr r1, [pc, #0x48] ; pop.w {r4, r5, lr} */
/* @0x2a8138 ldrbtmi r4, [r9], #-48 —— add r1, pc */
/* @0x2a813c ldmiblt r10, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} —— b.w #0x2a6474 */
/* @0x2a8140 ldrsbeq pc, [r4, -r0]! —— ldr.w r0, [r0, #0x134] */
/* @0x2a8144 blvc 0xff4a3c28 <b2_toiTime+0xfffffffffed4a784> —— vcvt.f32.f64 s14, d7 */
/* @0x2a8148 svclt #0x142b00 —— cmp r3, #0 ; ite ne */
/* @0x2a814c orrvc pc, r0, #1325400064 —— mov.w r3, #0x100 */
/* @0x2a8150 .word 0xf0402300 —— movs r3, #0 ; orr r0, r0, #0x80 */
/* @0x2a8154 .word 0xf8c40080 —— str.w r0, [r4, #0x134] */
/* @0x2a8158 stmdavs r8, {r2, r4, r5, r8} —— ldr r0, [r1] */
/* @0x2a815c mvnseq pc, r4, asr #17 —— str.w r0, [r4, #0x1fc] */
/* @0x2a8160 .word 0xf8c46848 —— ldr r0, [r1, #4] ; str.w r0, [r4, #0x200] */
/* @0x2a8164 stmdbhi r9, {r9} —— ldrh r1, [r1, #8] */
/* @0x2a8168 bvc 0x2263780 <b2_toiTime+0x1b0a2dc> —— vstr s14, [r4, #0x1f8] */
/* @0x2a816c mvnshs pc, r4, lsl #17 —— strb.w r2, [r4, #0x1f4] */
/* @0x2a8170 ldrsbhs pc, [r4, -r4]! —— ldr.w r2, [r4, #0x134] */
/* @0x2a8174 andne pc, r4, #164, #16 —— strh.w r1, [r4, #0x204] */
/* @0x2a8178 .word 0xf8c4431a —— orrs r2, r3 ; str.w r2, [r4, #0x134] */
/* @0x2a817c ldclt p1, c2, [r0, #-208]! —— pop {r4, r5, pc} */
/* @0x2a8180 andeq r4, lr, sp, ror r8 —— （数据字：literal pool） */

/* ---- 0x2a8184 png_set_strip_16（16 B / 5 条）----
 * 0x2a8186 ldr r3,[png+0x134] / orr #0x400 / str —— 只置 transformations 的 PNG_STRIP_16 位。
 * NULL 则直接 bx lr。 */
/* @0x2a8184 .word 0xf8d0b128 —— cbz r0, #0x2a8192 ; ldr.w r3, [r0, #0x134] */
/* @0x2a8188 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 —— orr r3, r3, #0x400 */
/* @0x2a818c .word 0xf8c06380 —— str.w r3, [r0, #0x134] */
/* @0x2a8190 .word 0x47703134 —— bx lr */

/* ---- 0x2a8194 png_set_strip_alpha（16 B / 5 条）----
 * 与 strip_16 同构，但位落在 flags(+0x130) 而不是 transformations：orr #0x400000。
 * ⇒ 「16 位降 8 位」是行变换，「丢 alpha」是读侧标志，两者不同字段。 */
/* @0x2a8194 .word 0xf8d0b128 —— cbz r0, #0x2a81a2 ; ldr.w r3, [r0, #0x130] */
/* @0x2a8198 vst4.8 {d19, d21, d23, d25}, [r3:256], r0 —— orr r3, r3, #0x400000 */
/* @0x2a819c .word 0xf8c00380 —— str.w r3, [r0, #0x130] */
/* @0x2a81a0 .word 0x47703130 —— bx lr */

/* ---- 0x2a81a4 png_set_quantize（1426 B / 507 条 —— 本卡最大件）----
 * 契约：void png_set_quantize(png_structp png, png_colorp palette, int num_palette,
 *                            int maximum_colors, png_uint_16p histogram, int full_quantize)
 *   r0=png / r1=palette / r2=num_palette / r3=maximum_colors
 *   [sp+0x58]=histogram（→r7） / [sp+0x5c]=full_quantize（→[sp+0x18]）
 *   0x2a81be transformations |= 0x40（PNG_QUANTIZE）—— 入口无条件置位
 *   分岔：full_quantize != 0 且 num_palette > maximum_colors → 0x2a81ee 量化路；
 *     否则 0x2a81d4 png_malloc(num_palette) 填 png_ptr+0x2b4（索引数组），
 *     再按需 png_malloc 填 +0x2f8（trans 数组，0x2a81f8）
 *   堆面：png_malloc×5 / png_calloc×2 / png_free×5 / png_malloc_warn×1 / memset@plt×1
 *   ⇒ 这是本段唯一碰堆的函数（其余 7 个只写标量字段）。函数体 507 条只钉入口分岔与堆调用面，
 *     排序/降采样内核未逐条解释（骨架级）。 */
/* @0x2a81a4 svcmi #0xf0e92d —— push.w {r4, r5, r6, r7, r8, sb, sl, fp, lr} */
/* @0x2a81a8 ldrmi r11, [r5], -sp, lsl #1 —— sub sp, #0x34 ; mov r5, r2 */
/* @0x2a81ac bls 0x8799ec <b2_toiTime+0x120548> —— mov r6, r1 ; ldr r2, [sp, #0x5c] */
/* @0x2a81b0 movwls r4, #0x5604 —— mov r4, r0 ; str r3, [sp, #0x14] */
/* @0x2a81b4 andls r9, r6, #22, #30 —— ldr r7, [sp, #0x58] ; str r2, [sp, #0x18] */
/* @0x2a81b8 .word 0xf0002800 —— cmp r0, #0 ; beq.w #0x2a8730 */
/* @0x2a81bc .word 0xf8d082b9 —— ldr.w r3, [r0, #0x134] */
/* @0x2a81c0 .word 0xf0433134 —— orr r3, r3, #0x40 */
/* @0x2a81c4 .word 0xf8c00340 —— str.w r3, [r0, #0x134] */
/* @0x2a81c8 tstlt r10, r4, lsr r1 —— cbz r2, #0x2a81d4 */
/* @0x2a81cc addsmi r9, sp, #5120 —— ldr r3, [sp, #0x14] ; cmp r5, r3 */
/* @0x2a81d0 ands sp, sp, #3328 —— bgt #0x2a81ee ; b #0x2a8610 */
/* @0x2a81d4 .word 0xf7fe4629 —— mov r1, r5 ; bl #0x2a6ca0 */
/* @0x2a81d8 blls 0x46776c <g_RomDisk+0x6ff4c> —— ldr r3, [sp, #0x18] */
/* @0x2a81dc adcseq pc, r4, #196, #16 —— str.w r0, [r4, #0x2b4] */
/* @0x2a81e0 ble 0xfff78c94 <b2_toiTime+0xffffffffff81f7f0> —— cmp r3, r5 ; bge #0x2a81cc */
/* @0x2a81e4 adcshs pc, r4, #212, #16 —— ldr.w r2, [r4, #0x2b4] */
/* @0x2a81e8 movwlo r5, #0x14d3 —— strb r3, [r2, r3] ; adds r3, #1 */
/* @0x2a81ec qsub8mi lr, r0, r8 —— b #0x2a81e0 ; mov r0, r4 */
/* @0x2a81f0 svchs #0x4629 —— mov r1, r5 ; cmp r7, #0 */
/* @0x2a81f4 rschi pc, r9, r0 —— beq.w #0x2a83ca */
/* @0x2a81f8 ldc2l p7, c15, [r2, #-1016] —— bl #0x2a6ca0 */
/* @0x2a81fc .word 0xf8c42300 —— movs r3, #0 ; str.w r0, [r4, #0x2f8] */
/* @0x2a8200 adcmi r0, r11, #248, #4 —— cmp r3, r5 */
/* @0x2a8204 .word 0xf8d4da04 —— bge #0x2a8210 ; ldr.w r2, [r4, #0x2f8] */
/* @0x2a8208 ldrbpl r2, [r3], #760 —— strb r3, [r2, r3] */
/* @0x2a820c ldrb r3, [r8, r1, lsl #6]! —— adds r3, #1 ; b #0x2a8202 */
/* @0x2a8210 .word 0xf8dd1e6a —— subs r2, r5, #1 ; ldr.w sl, [sp, #0x14] */
/* @0x2a8214 ldrbmi r10, [r2, #-0x14] —— cmp r2, sl */
/* @0x2a8218 svcls #0x6da07 —— bge #0x2a822a ; ldr r7, [sp, #0x18] */
/* @0x2a821c shasxmi r11, r3, r7 —— cbnz r7, #0x2a826c ; mov r3, r6 */
/* @0x2a8220 bls 0x439acc <g_RomDisk+0x422ac> —— mov r1, r5 ; ldr r2, [sp, #0x18] */
/* @0x2a8224 cdpeq p0, #0x0, c15, c3, c15, #0x2 —— mov.w lr, #3 */
/* @0x2a8228 movwhs lr, #0x48 —— b #0x2a82bc ; movs r3, #0 */
/* @0x2a822c cdpeq p0, #0x0, c15, c1, c15, #0x2 —— mov.w lr, #1 */
/* @0x2a8230 ble 0x838c84 <b2_toiTime+0xdf7e0> —— cmp r3, r2 ; bge #0x2a8262 */
/* @0x2a8234 rscseq pc, r8, #212, #16 —— ldr.w r0, [r4, #0x2f8] */
/* @0x2a8238 .word 0xf8101c59 —— adds r1, r3, #1 ; ldrb.w ip, [r0, r3] */
/* @0x2a823c .word 0xf810c003 —— ldrb.w r8, [r0, r1] */
/* @0x2a8240 rfeda r7! —— ldrh.w sl, [r7, ip, lsl #1] */
/* @0x2a8244 rfeda r7! —— ldrh.w sb, [r7, r8, lsl #1] */
/* @0x2a8248 strbmi r9, [r10, #0x18] —— cmp sl, sb */
/* @0x2a824c .word 0xf800d207 —— bhs #0x2a825e ; strb.w r8, [r0, r3] */
/* @0x2a8250 .word 0xf04f8003 —— mov.w lr, #0 */
/* @0x2a8254 .word 0xf8d40e00 —— ldr.w r3, [r4, #0x2f8] */
/* @0x2a8258 .word 0xf80332f8 —— strb.w ip, [r3, r1] */
/* @0x2a825c strmi r12, [r11], -r1 —— mov r3, r1 */
/* @0x2a8260 .word 0xf1bee7e6 —— b #0x2a8230 ; cmp.w lr, #0 */
/* @0x2a8264 bicsle r0, r8, r0, lsl #30 —— bne #0x2a821a */
/* @0x2a8268 ldrb r3, [r2, r1, lsl #20] —— subs r2, #1 ; b #0x2a8212 */
/* @0x2a826c andhs r2, r3, #0, #6 —— movs r3, #0 ; movs r2, #3 */
/* @0x2a8270 adcsmi r9, r11, #5, #30 —— ldr r7, [sp, #0x14] ; cmp r3, r7 */
/* @0x2a8274 .word 0xf8d4da29 —— bge #0x2a82ca ; ldr.w r1, [r4, #0x2f8] */
/* @0x2a8278 .word 0xf8dd12f8 —— ldr.w fp, [sp, #0x14] */
/* @0x2a827c stclpl p0, c11, [r8], {20} —— ldrb r0, [r1, r3] */
/* @0x2a8280 blle 0x6b97e8 <g_SWFlinevertbuff+0x66720> —— cmp r0, fp ; blt #0x2a82a6 */
/* @0x2a8284 .word 0xf8dd3d01 —— subs r5, #1 ; ldr.w ip, [sp, #0x14] */
/* @0x2a8288 stclpl p0, c12, [r8, #-80] —— ldrb r0, [r1, r5] */
/* @0x2a828c ble 0xf9814 <_ZN7CFontGM8CreateItEv+0x1b4> —— cmp r0, ip ; bge #0x2a8284 */
/* @0x2a8290 .word 0x6105fb02 —— mla r1, r2, r5, r6 */
/* @0x2a8294 .word 0xf003fb02 —— mul r0, r2, r3 */
/* @0x2a8298 strh pc, [r0], -r1 —— ldrh.w lr, [r1] */
/* @0x2a829c .word 0xf8261837 —— adds r7, r6, r0 ; strh.w lr, [r6, r0] */
/* @0x2a82a0 stmvc r9, {sp, lr, pc} —— ldrb r1, [r1, #2] */
/* @0x2a82a4 movwlo r7, #0x10b9 —— strb r1, [r7, #2] ; adds r3, #1 */
/* @0x2a82a8 .word 0xf8d4e7e2 —— b #0x2a8270 ; ldr.w r0, [r4, #0x2f8] */
/* @0x2a82ac .word 0xf8dd02f8 —— ldr.w sl, [sp, #0x14] */
/* @0x2a82b0 stcpl p0, c10, [r7], {20} —— ldrb r7, [r0, r2] */
/* @0x2a82b4 ble 0x6f9818 <g_SWFvertbuff+0x26750> —— cmp r7, sl ; bge #0x2a82dc */
/* @0x2a82b8 movwlo r3, #0x3201 —— adds r2, #1 ; adds r3, #3 */
/* @0x2a82bc ldrsbgt pc, [r4], -sp —— ldr.w ip, [sp, #0x14] */
/* @0x2a82c0 blle 0xfff39850 <b2_toiTime+0xffffffffff7e03ac> —— cmp r2, ip ; blt #0x2a82aa */
/* @0x2a82c4 adcmi r2, r11, #0, #6 —— movs r3, #0 ; cmp r3, r5 */
/* @0x2a82c8 strtmi sp, [r0], -r10, lsr #22 —— blt #0x2a8320 ; mov r0, r4 */
/* @0x2a82cc rscsne pc, r8, #212, #16 —— ldr.w r1, [r4, #0x2f8] */
/* @0x2a82d0 ldc2 p7, c15, [r4, #-1016] —— bl #0x2a6cfc */
/* @0x2a82d4 .word 0xf8c42300 —— movs r3, #0 ; str.w r3, [r4, #0x2f8] */
/* @0x2a82d8 ldrsh r3, [r8, r8] —— b #0x2a860e */
/* @0x2a82dc .word 0xf8dd3901 —— subs r1, #1 ; ldr.w fp, [sp, #0x14] */
/* @0x2a82e0 mcrrpl p0, #0x1, r11, r7, c4 —— ldrb r7, [r0, r1] */
/* @0x2a82e4 ble 0xf9868 <_ZN7CFontGM8CreateItEv+0x208> —— cmp r7, fp ; bge #0x2a82dc */
/* @0x2a82e8 .word 0xf701fb0e —— mul r7, lr, r1 */
/* @0x2a82ec strhge pc, [r0], -r3 —— ldrh.w sl, [r3] */
/* @0x2a82f0 .word 0xf81619f0 —— adds r0, r6, r7 ; ldrb.w sb, [r6, r7] */
/* @0x2a82f4 .word 0xf8909007 —— ldrb.w ip, [r0, #2] */
/* @0x2a82f8 .word 0xf890c002 —— ldrb.w r8, [r0, #1] */
/* @0x2a82fc .word 0xf8268001 —— strh.w sl, [r6, r7] */
/* @0x2a8300 ldmvc pc, {r0, r1, r2, sp, pc} —— ldrb r7, [r3, #2] */
/* @0x2a8304 .word 0xf8837087 —— strb r7, [r0, #2] ; strb.w sb, [r3] */
/* @0x2a8308 .word 0xf8839000 —— strb.w r8, [r3, #1] */
/* @0x2a830c .word 0xf8838001 —— strb.w ip, [r3, #2] */
/* @0x2a8310 .word 0xf8d4c002 —— ldr.w r0, [r4, #0x2b4] */
/* @0x2a8314 strbpl r0, [r2], #-692 —— strb r2, [r0, r1] */
/* @0x2a8318 adcseq pc, r4, #212, #16 —— ldr.w r0, [r4, #0x2b4] */
/* @0x2a831c strb r5, [r11, r1, lsl #9] —— strb r1, [r0, r2] ; b #0x2a82b8 */
/* @0x2a8320 adcshs pc, r4, #212, #16 —— ldr.w r2, [r4, #0x2b4] */
/* @0x2a8324 bl 0x34ff40 —— ldr r7, [sp, #0x14] ; add.w sb, r2, r3 */
/* @0x2a8328 ldclpl p9, c0, [r2], {3} —— ldrb r2, [r2, r3] */
/* @0x2a832c blle 0x1538e1c <b2_toiTime+0xddf978> —— cmp r2, r7 ; blt #0x2a83c6 */
/* @0x2a8330 subeq lr, r2, #2048 —— add.w r2, r2, r2, lsl #1 */
/* @0x2a8334 ldmne r1!, {r4, r5, r11, r12, sp, lr} —— ldrb r0, [r6] ; adds r1, r6, r2 */
/* @0x2a8338 .word 0xf8162700 —— movs r7, #0 ; ldrb.w lr, [r6, r2] */
/* @0x2a833c .word 0xf891e002 —— ldrb.w ip, [r1, #1] */
/* @0x2a8340 ldmdavc r2!, {r0, lr, pc} ^ —— ldrb r2, [r6, #1] */
/* @0x2a8344 andeq lr, lr, r0, asr #23 —— rsb r0, r0, lr */
/* @0x2a8348 svclt #0xb82800 —— cmp r0, #0 ; it lt */
/* @0x2a834c .word 0xf8914240 —— rsbs r0, r0, #0 ; ldrb.w r8, [r1, #2] */
/* @0x2a8350 bl 0xff348360 <b2_toiTime+0xfffffffffebeeebc> —— rsb r2, r2, ip */
/* @0x2a8354 .word 0x2101020c —— movs r1, #1 */
/* @0x2a8358 svclt #0xb82a00 —— cmp r2, #0 ; it lt */
/* @0x2a835c ldrmi r4, [r0], #-594 —— rsbs r2, r2, #0 ; add r0, r2 */
/* @0x2a8360 bl 0xff346630 <b2_toiTime+0xfffffffffebed18c> —— ldrb r2, [r6, #2] ; rsb r2, r2, r8 */
/* @0x2a8364 bhs 0x2a8b8c <png_do_unpack+0x5e> —— cmp r2, #0 */
/* @0x2a8368 subsmi r11, r2, #184, #30 —— it lt ; rsbs r2, r2, #0 */
/* @0x2a836c shadd16mi r4, r2, r0 —— add r0, r2 ; mov r2, r6 */
/* @0x2a8370 ldrsbge pc, [r4], -sp —— ldr.w sl, [sp, #0x14] */
/* @0x2a8374 ble 0xbb98c0 <b2_toiTime+0x46041c> —— cmp r1, sl ; bge #0x2a83c2 */
/* @0x2a8378 mullt r3, r2, r8 —— ldrb.w fp, [r2, #3] */
/* @0x2a837c .word 0xf8923203 —— adds r2, #3 ; ldrb.w sl, [r2, #1] */
/* @0x2a8380 bl 0xff59038c <b2_toiTime+0xfffffffffee36ee8> —— rsb fp, fp, lr */
/* @0x2a8384 bl 0xff52afc4 <b2_toiTime+0xfffffffffedd1b20> —— rsb sl, sl, ip */
/* @0x2a8388 .word 0xf1bb0a0c —— cmp.w fp, #0 */
/* @0x2a838c svclt #0xb80f00 —— it lt */
/* @0x2a8390 bleq 0x2e4ac4 <_ZNK11b2GearJoint8GetRatioEv+0x1c0> —— rsb.w fp, fp, #0 */
/* @0x2a8394 svceq #0xf1ba —— cmp.w sl, #0 */
/* @0x2a8398 .word 0xf1cabfb8 —— it lt ; rsb.w sl, sl, #0 */
/* @0x2a839c ldrbmi r0, [r3], #2560 —— add fp, sl */
/* @0x2a83a0 mulge r2, r2, r8 —— ldrb.w sl, [r2, #2] */
/* @0x2a83a4 beq 0x4e32d4 <SrcVerts+0x40318> —— rsb sl, sl, r8 */
/* @0x2a83a8 svceq #0xf1ba —— cmp.w sl, #0 */
/* @0x2a83ac .word 0xf1cabfb8 —— it lt ; rsb.w sl, sl, #0 */
/* @0x2a83b0 ldrbmi r0, [r10], #2560 —— add sl, fp */
/* @0x2a83b4 svclt #0xac4582 —— cmp sl, r0 ; ite ge */
/* @0x2a83b8 strmi r4, [pc], -r2, lsl #13 —— mov sl, r0 ; mov r7, r1 */
/* @0x2a83bc qaddlo r4, r0, r1 —— mov r0, sl ; adds r1, #1 */
/* @0x2a83c0 .word 0xf889e7d6 —— b #0x2a8370 ; strb.w r7, [sb] */
/* @0x2a83c4 movwlo r7, #0x1000 —— adds r3, #1 */
/* @0x2a83c8 .word 0xf7fee77d —— b #0x2a82c6 ; bl #0x2a6ca0 */
/* @0x2a83cc strtmi pc, [r9], -r9, ror #24 —— mov r1, r5 */
/* @0x2a83d0 rscseq pc, r12, #196, #16 —— str.w r0, [r4, #0x2fc] */
/* @0x2a83d4 .word 0xf7fe4620 —— mov r0, r4 ; bl #0x2a6ca0 */
/* @0x2a83d8 .word 0xf8c4fc63 —— str.w r0, [r4, #0x300] */
/* @0x2a83dc adcmi r0, pc, #0, #6 —— cmp r7, r5 */
/* @0x2a83e0 .word 0xf8d4da08 —— bge #0x2a83f4 ; ldr.w r2, [r4, #0x2fc] */
/* @0x2a83e4 rscslt r2, r11, #252, #4 —— uxtb r3, r7 */
/* @0x2a83e8 .word 0xf8d455d3 —— strb r3, [r2, r7] ; ldr.w r2, [r4, #0x300] */
/* @0x2a83ec ldrbpl r2, [r3, #0x300] —— strb r3, [r2, r7] */
/* @0x2a83f0 ldrb r3, [r4, r1, lsl #14]! —— adds r7, #1 ; b #0x2a83de */
/* @0x2a83f4 .word 0xf6404620 —— mov r0, r4 ; movw r1, #0xc04 */
/* @0x2a83f8 .word 0xf7fe4104 —— bl #0x2a6cd8 */
/* @0x2a83fc strtmi pc, [pc], -sp, ror #24 —— mov r7, r5 */
/* @0x2a8400 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} —— mov.w r8, #0 */
/* @0x2a8404 bleq 0x1ae4548 <b2_toiTime+0x138b0a4> —— mov.w fp, #0x60 */
/* @0x2a8408 eorlt pc, r0, sp, asr #17 —— str.w fp, [sp, #0x20] */
/* @0x2a840c ldrtmi r9, [r1], r7 —— str r0, [sp, #0x1c] ; mov sb, r6 */
/* @0x2a8410 beq 0x2e4554 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x4f0> —— mov.w sl, #0 */
/* @0x2a8414 andls r1, r9, #1952 —— subs r2, r7, #1 ; str r2, [sp, #0x24] */
/* @0x2a8418 ldrmi r9, [r10, #0xb09] —— ldr r3, [sp, #0x24] ; cmp sl, r3 */
/* @0x2a841c .word 0xf10ada49 —— bge #0x2a84b2 ; add.w sl, sl, #1 */
/* @0x2a8420 strbmi r0, [r11], r1, lsl #20 —— mov fp, sb */
/* @0x2a8424 ldcllo p1, c15, [pc], #40 —— add.w ip, sl, #-1 */
/* @0x2a8428 adcsmi r4, r11, #87031808 —— mov r3, sl ; cmp r3, r7 */
/* @0x2a842c .word 0xf89bd03b —— beq #0x2a84a6 ; ldrb.w r2, [fp, #3] */
/* @0x2a8430 .word 0xf8992003 —— ldrb.w r1, [sb] */
/* @0x2a8434 .word 0xf8991000 —— ldrb.w r0, [sb, #1] */
/* @0x2a8438 bne 0xfe4e8444 <b2_toiTime+0xfffffffffdd8efa0> —— subs r1, r1, r2 */
/* @0x2a843c mulhs r4, r11, r8 —— ldrb.w r2, [fp, #4] */
/* @0x2a8440 svclt #0xb82900 —— cmp r1, #0 ; it lt */
/* @0x2a8444 bne 0xfe338d70 <b2_toiTime+0xfffffffffdbdf8cc> —— rsbs r1, r1, #0 ; subs r2, r0, r2 */
/* @0x2a8448 muleq r2, r9, r8 —— ldrb.w r0, [sb, #2] */
/* @0x2a844c svclt #0xb82a00 —— cmp r2, #0 ; it lt */
/* @0x2a8450 strmi r4, [r10], #-594 —— rsbs r2, r2, #0 ; add r2, r1 */
/* @0x2a8454 mulne r5, r11, r8 —— ldrb.w r1, [fp, #5] */
/* @0x2a8458 stmdals r8, {r0, r6, r9, r11, r12} —— subs r1, r0, r1 ; ldr r0, [sp, #0x20] */
/* @0x2a845c svclt #0xb82900 —— cmp r1, #0 ; it lt */
/* @0x2a8460 strmi r4, [r10], #-585 —— rsbs r1, r1, #0 ; add r2, r1 */
/* @0x2a8464 .word 0xdc1a4282 —— cmp r2, r0 ; bgt #0x2a849e */
/* @0x2a8468 .word 0x21084620 —— mov r0, r4 ; movs r1, #8 */
/* @0x2a846c movwls r9, #0x2204 —— str r2, [sp, #0x10] ; str r3, [sp, #8] */
/* @0x2a8470 andgt pc, r12, sp, asr #17 —— str.w ip, [sp, #0xc] */
/* @0x2a8474 mcrr2 p7, #0xf, pc, pc, c14 —— bl #0x2a6d16 */
/* @0x2a8478 blls 0x34ec90 —— ldr r2, [sp, #0x10] ; ldr r3, [sp, #8] */
/* @0x2a847c .word 0xc00cf8dd —— ldr.w ip, [sp, #0xc] */
/* @0x2a8480 stmdahs r0, {r7, r9, r10, lr} —— mov r8, r0 ; cmp r0, #0 */
/* @0x2a8484 cmphi r1, r0 —— beq.w #0x2a872a */
/* @0x2a8488 .word 0xf8509807 —— ldr r0, [sp, #0x1c] ; ldr.w r1, [r0, r2, lsl #2] */
/* @0x2a848c .word 0xf8881022 —— strb.w ip, [r8, #4] */
/* @0x2a8490 .word 0xf888c004 —— strb.w r3, [r8, #5] */
/* @0x2a8494 .word 0xf8c83005 —— str.w r1, [r8] */
/* @0x2a8498 .word 0xf8401000 —— str.w r8, [r0, r2, lsl #2] */
/* @0x2a849c movwlo r8, #0x1022 —— adds r3, #1 */
/* @0x2a84a0 bleq 0x3a48d4 <af_blue_strings+0x25b0> —— add.w fp, fp, #3 */
/* @0x2a84a4 .word 0xf109e7c1 —— b #0x2a842a ; add.w sb, sb, #3 */
/* @0x2a84a8 .word 0xf1b80903 —— cmp.w r8, #0 */
/* @0x2a84ac .word 0xd1b30f00 —— bne #0x2a8418 */
/* @0x2a84b0 .word 0xf1b8e13b —— b #0x2a872a ; cmp.w r8, #0 */
/* @0x2a84b4 rsbsle r0, r0, r0, lsl #30 —— beq #0x2a859a */
/* @0x2a84b8 bls 0x4704c0 <g_RomDisk+0x78ca0> —— movs r0, #0 ; ldr r2, [sp, #0x1c] */
/* @0x2a84bc eorne pc, r0, r2, asr r8 —— ldr.w r1, [r2, r0, lsl #2] */
/* @0x2a84c0 rsble r2, r5, r0, lsl #18 —— cmp r1, #0 ; beq #0x2a8590 */
/* @0x2a84c4 rscshs pc, r12, #212, #16 —— ldr.w r2, [r4, #0x2fc] */
/* @0x2a84c8 mul r4, r1, r8 —— ldrb.w lr, [r1, #4] */
/* @0x2a84cc andlo pc, lr, r2, lsl r8 —— ldrb.w r3, [r2, lr] */
/* @0x2a84d0 ble 0x18b8fc4 <b2_toiTime+0x115fb20> —— cmp r3, r7 ; bge #0x2a8586 */
/* @0x2a84d4 mullt r5, r1, r8 —— ldrb.w fp, [r1, #5] */
/* @0x2a84d8 andlo pc, r11, r2, lsl r8 —— ldrb.w r3, [r2, fp] */
/* @0x2a84dc ble 0x1738fd0 <b2_toiTime+0xfdfb2c> —— cmp r3, r7 ; bge #0x2a8586 */
/* @0x2a84e0 .word 0xf10707fb —— lsls r3, r7, #0x1f ; add.w r7, r7, #-1 */
/* @0x2a84e4 .word 0xf04f37ff —— mov.w sl, #3 */
/* @0x2a84e8 svclt #0x560a03 —— itet pl */
/* @0x2a84ec uhsaxmi r4, r3, r11 —— mov r3, fp ; mov r3, lr */
/* @0x2a84f0 .word 0xf81246f3 —— mov fp, lr ; ldrb.w lr, [r2, r3] */
/* @0x2a84f4 blx 0x56050a <g_SWFlineaavertbuff+0xd442> —— mla r2, sl, r7, r6 */
/* @0x2a84f8 bl 0x640d1c <g_SWFaavertbuff+0x6dc54> —— add.w lr, lr, lr, lsl #1 */
/* @0x2a84fc bl 0x42be3c <g_RomDisk+0x3461c> —— add.w ip, r6, lr */
/* @0x2a8500 rfeia r2! —— ldrh.w sb, [r2] */
/* @0x2a8504 .word 0xf8269000 —— strh.w sb, [r6, lr] */
/* @0x2a8508 ldmvc r2, {r1, r2, r3, r12, pc} —— ldrb r2, [r2, #2] */
/* @0x2a850c andhs pc, r2, r12, lsl #17 —— strb.w r2, [ip, #2] */
/* @0x2a8510 biclt r9, r2, r6, lsl #20 —— ldr r2, [sp, #0x18] ; cbz r2, #0x2a8546 */
/* @0x2a8514 rscs pc, r12, #212, #16 —— ldr.w lr, [r4, #0x2fc] */
/* @0x2a8518 movwhs pc, #0x8d4 —— ldr.w r2, [r4, #0x300] */
/* @0x2a851c andgt pc, r3, lr, lsl r8 —— ldrb.w ip, [lr, r3] */
/* @0x2a8520 .word 0xf80e5dd2 —— ldrb r2, [r2, r7] ; strb.w ip, [lr, r2] */
/* @0x2a8524 .word 0xf8d4c002 —— ldr.w lr, [r4, #0x300] */
/* @0x2a8528 .word 0xf8d4e300 —— ldr.w r2, [r4, #0x2fc] */
/* @0x2a852c .word 0xf81e22fc —— ldrb.w ip, [lr, r7] */
/* @0x2a8530 ldclpl p0, c12, [r2], {7} —— ldrb r2, [r2, r3] */
/* @0x2a8534 andgt pc, r2, lr, lsl #16 —— strb.w ip, [lr, r2] */
/* @0x2a8538 rscshs pc, r12, #212, #16 —— ldr.w r2, [r4, #0x2fc] */
/* @0x2a853c .word 0xf8d454d7 —— strb r7, [r2, r3] ; ldr.w r2, [r4, #0x300] */
/* @0x2a8540 ldrbpl r2, [r3, #0x300] —— strb r3, [r2, r7] */
/* @0x2a8544 .word 0xf8dde01f —— b #0x2a8586 ; ldr.w lr, [sp, #0x18] */
/* @0x2a8548 strmi lr, [lr, #0x18]! —— cmp lr, r5 */
/* @0x2a854c .word 0xf8d4dae2 —— bge #0x2a8514 ; ldr.w ip, [r4, #0x2fc] */
/* @0x2a8550 .word 0xf8d4c2fc —— ldr.w r2, [r4, #0x2b4] */
/* @0x2a8554 .word 0xf81c22b4 —— ldrb.w sb, [ip, r3] */
/* @0x2a8558 .word 0xf8129003 —— ldrb.w sl, [r2, lr] */
/* @0x2a855c strbmi r10, [r10, #0xe] —— cmp sl, sb */
/* @0x2a8560 .word 0xf81cbf04 —— itt eq ; ldrb.w ip, [ip, fp] */
/* @0x2a8564 .word 0xf802c00b —— strb.w ip, [r2, lr] */
/* @0x2a8568 .word 0xf8d4c00e —— ldr.w ip, [r4, #0x2b4] */
/* @0x2a856c .word 0xf81cc2b4 —— ldrb.w r2, [ip, lr] */
/* @0x2a8570 adcsmi r2, r10, #14 —— cmp r2, r7 */
/* @0x2a8574 .word 0xf8d4d104 —— bne #0x2a8580 ; ldr.w r2, [r4, #0x2fc] */
/* @0x2a8578 ldclpl p2, c2, [r2], {252} —— ldrb r2, [r2, r3] */
/* @0x2a857c andhs pc, lr, r12, lsl #16 —— strb.w r2, [ip, lr] */
/* @0x2a8580 cdpeq p1, #0x0, c15, c1, c14, #0x0 —— add.w lr, lr, #1 */
/* @0x2a8584 blls 0x422510 <g_RomDisk+0x2acf0> —— b #0x2a854a ; ldr r3, [sp, #0x14] */
/* @0x2a8588 stcle p2, c4, [r6, #-636] —— cmp r7, r3 ; ble #0x2a859a */
/* @0x2a858c ldr r6, [r7, r9, lsl #16] —— ldr r1, [r1] ; b #0x2a84c0 */
/* @0x2a8590 .word 0xa020f8dd —— ldr.w sl, [sp, #0x20] */
/* @0x2a8594 ldrbmi r3, [r0, #-0x1] —— adds r0, #1 ; cmp r0, sl */
/* @0x2a8598 .word 0xf04fdd8f —— ble #0x2a84ba ; mov.w sb, #0 */
/* @0x2a859c .word 0xf6400900 —— movw fp, #0xc04 */
/* @0x2a85a0 strbmi r4, [r11], -r4, lsl #22 —— mov r3, sb */
/* @0x2a85a4 ldrsbgt pc, [r12], -sp —— ldr.w ip, [sp, #0x1c] */
/* @0x2a85a8 andne pc, r9, r12, asr r8 —— ldr.w r1, [ip, sb] */
/* @0x2a85ac .word 0xf8d1b159 —— cbz r1, #0x2a85c6 ; ldr.w r8, [r1] */
/* @0x2a85b0 strtmi r8, [r0], -r0 —— mov r0, r4 */
/* @0x2a85b4 .word 0xf7fe9302 —— str r3, [sp, #8] ; bl #0x2a6cfc */
/* @0x2a85b8 blls 0x367444 <_ZTS12CDS_Priority+0x949c> —— ldr r3, [sp, #8] */
/* @0x2a85bc svceq #0xf1b8 —— cmp.w r8, #0 */
/* @0x2a85c0 strbmi sp, [r1], -r1 —— beq #0x2a85c6 ; mov r1, r8 */
/* @0x2a85c4 bls 0x4a2598 <g_SrcBlend+0x198> —— b #0x2a85ae ; ldr r2, [sp, #0x1c] */
/* @0x2a85c8 beq 0x2e470c <_ZN11b2GearJointC2EPK14b2GearJointDef+0x184> —— mov.w sl, #0 */
/* @0x2a85cc andlo pc, r9, r2, asr #16 —— str.w r3, [r2, sb] */
/* @0x2a85d0 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc} —— add.w sb, sb, #4 */
/* @0x2a85d4 ldrdle r4, r5, [r5, #89]! —— cmp sb, fp ; bne #0x2a85a4 */
/* @0x2a85d8 ldrsblt pc, [r4], -sp —— ldr.w fp, [sp, #0x14] */
/* @0x2a85dc ldrbmi r9, [pc, #-0xb08] —— ldr r3, [sp, #0x20] ; cmp r7, fp */
/* @0x2a85e0 msreq SPSR, #3221225472 —— add.w r3, r3, #0x60 */
/* @0x2a85e4 .word 0xf73f9308 —— str r3, [sp, #0x20] ; bgt.w #0x2a840e */
/* @0x2a85e8 sadd16mi r10, r1, r2 —— mov r1, r2 */
/* @0x2a85ec .word 0xf7fe4620 —— mov r0, r4 ; bl #0x2a6cfc */
/* @0x2a85f0 strtmi pc, [r0], -r5, lsl #23 —— mov r0, r4 */
/* @0x2a85f4 movwne pc, #0x8d4 —— ldr.w r1, [r4, #0x300] */
/* @0x2a85f8 blx 0xfe2e65fa <b2_toiTime+0xfffffffffdb8d156> —— bl #0x2a6cfc */
/* @0x2a85fc .word 0xf8d44620 —— mov r0, r4 ; ldr.w r1, [r4, #0x2fc] */
/* @0x2a8600 .word 0xf7fe12fc —— bl #0x2a6cfc */
/* @0x2a8604 .word 0xf8c4fb7b —— str.w sl, [r4, #0x300] */
/* @0x2a8608 .word 0xf8c4a300 —— str.w sl, [r4, #0x2fc] */
/* @0x2a860c stcls p2, c10, [r5, #-1008] —— ldr r5, [sp, #0x14] */
/* @0x2a8610 ldrsblo pc, [r8, #132] —— ldr.w r3, [r4, #0x1d8] */
/* @0x2a8614 .word 0xf8c4b90b —— cbnz r3, #0x2a861a ; str.w r6, [r4, #0x1d8] */
/* @0x2a8618 bls 0x440d80 <g_RomDisk+0x49560> —— ldr r2, [sp, #0x18] */
/* @0x2a861c bicspl pc, r12, r4, lsr #17 —— strh.w r5, [r4, #0x1dc] */
/* @0x2a8620 .word 0xf0002a00 —— cmp r2, #0 ; beq.w #0x2a8730 */
/* @0x2a8624 vst4.32 {d24, d25, d26, d27}, [pc], r5 —— mov.w r1, #0x8000 */
/* @0x2a8628 strtmi r4, [r0], -r0, lsl #2 —— mov r0, r4 */
/* @0x2a862c blx 0x17e662e <b2_toiTime+0x108d18a> —— bl #0x2a6cd8 */
/* @0x2a8630 .word 0x4100f44f —— mov.w r1, #0x8000 */
/* @0x2a8634 adcseq pc, r0, #196, #16 —— str.w r0, [r4, #0x2b0] */
/* @0x2a8638 .word 0xf7fe4620 —— mov r0, r4 ; bl #0x2a6ca0 */
/* @0x2a863c mvnshs pc, r1, lsr r11 —— movs r1, #0xff */
/* @0x2a8640 andmi pc, r0, #1325400064 —— mov.w r2, #0x8000 */
/* @0x2a8644 .word 0xf60d4681 —— mov sb, r0 ; blx #0xb65b0 */
/* @0x2a8648 .word 0xf04fefb4 —— mov.w ip, #0 */
/* @0x2a864c strbtmi r0, [r0], r0, lsl #24 —— mov r8, ip */
/* @0x2a8650 ble 0x1b79cf8 <b2_toiTime+0x1420854> —— cmp r8, r5 ; bge #0x2a871c */
/* @0x2a8654 andlo pc, r12, r6, lsl r8 —— ldrb.w r3, [r6, ip] */
/* @0x2a8658 movwls r0, #0x58db —— lsrs r3, r3, #3 ; str r3, [sp, #0x14] */
/* @0x2a865c movweq lr, #0xcb06 —— add.w r3, r6, ip */
/* @0x2a8660 ldmvc r11, {r1, r3, r4, r6, r11, r12, sp, lr} —— ldrb r2, [r3, #1] ; ldrb r3, [r3, #2] */
/* @0x2a8664 andls r0, r6, #13762560 —— lsrs r2, r2, #3 ; str r2, [sp, #0x18] */
/* @0x2a8668 movwls r0, #0x78db —— lsrs r3, r3, #3 ; str r3, [sp, #0x1c] */
/* @0x2a866c svcls #0x52300 —— movs r3, #0 ; ldr r7, [sp, #0x14] */
/* @0x2a8670 stcle p2, c4, [r4, #-748] —— cmp r3, r7 ; ble #0x2a867e */
/* @0x2a8674 beq 0x3a3598 <af_blue_strings+0x1274> —— rsb sl, r7, r3 */
/* @0x2a8678 andge pc, r4, sp, asr #17 —— str.w sl, [sp, #4] */
/* @0x2a867c .word 0xf8dde005 —— b #0x2a868a ; ldr.w fp, [sp, #0x14] */
/* @0x2a8680 bl 0xff3946d8 <b2_toiTime+0xfffffffffec3b234> —— rsb fp, r3, fp */
/* @0x2a8684 .word 0xf8cd0b0b —— str.w fp, [sp, #4] */
/* @0x2a8688 andhs r11, r0, #4 —— movs r2, #0 */
/* @0x2a868c mulls r8, r8, r2 —— lsls r0, r3, #0xa ; str r0, [sp, #0x20] */
/* @0x2a8690 .word 0xf8dd9906 —— ldr r1, [sp, #0x18] ; ldr.w sl, [sp, #4] */
/* @0x2a8694 addmi r10, r10, #4 —— cmp r2, r1 */
/* @0x2a8698 .word 0xb004f8dd —— ldr.w fp, [sp, #4] */
/* @0x2a869c bl 0xff3185dc <b2_toiTime+0xfffffffffebbf138> —— itee gt ; rsb r0, r1, r2 */
/* @0x2a86a0 svcls #0x60002 —— ldr r7, [sp, #0x18] */
/* @0x2a86a4 andeq lr, r7, r2, asr #23 —— rsb r0, r2, r7 */
/* @0x2a86a8 strmi r2, [r2], #1792 —— movs r7, #0 ; add sl, r0 */
/* @0x2a86ac svclt #0xa84558 —— cmp r0, fp ; it ge */
/* @0x2a86b0 stmdals r8, {r0, r1, r7, r9, r10, lr} —— mov fp, r0 ; ldr r0, [sp, #0x20] */
/* @0x2a86b4 eorge pc, r4, sp, asr #17 —— str.w sl, [sp, #0x24] */
/* @0x2a86b8 subne lr, r2, r0, asr #20 —— orr.w r0, r0, r2, lsl #5 */
/* @0x2a86bc eorlt pc, r8, sp, asr #17 —— str.w fp, [sp, #0x28] */
/* @0x2a86c0 .word 0xf8dd900b —— str r0, [sp, #0x2c] ; ldr.w sl, [sp, #0x1c] */
/* @0x2a86c4 stmdbls r11, {r2, r3, r4, sp, pc} —— ldr r1, [sp, #0x2c] */
/* @0x2a86c8 b 0x1479c2c <b2_toiTime+0xd20788> —— cmp r7, sl ; orr.w r0, r7, r1 */
/* @0x2a86cc stmdbls r10, {r0} —— ldr r1, [sp, #0x28] */
/* @0x2a86d0 .word 0xf8ddbfd6 —— itet le ; ldr.w fp, [sp, #0x1c] */
/* @0x2a86d4 bl 0xff55474c <b2_toiTime+0xfffffffffedfb2a8> —— rsb sl, sl, r7 */
/* @0x2a86d8 bl 0xff46aefc <b2_toiTime+0xfffffffffed11a58> —— rsb sl, r7, fp */
/* @0x2a86dc .word 0xf8dd0a0b —— ldr.w fp, [sp, #0x24] */
/* @0x2a86e0 strmi r11, [r10, #0x24] —— cmp sl, r1 */
/* @0x2a86e4 ldrbmi r11, [r3], #4012 —— ite ge ; add fp, sl */
/* @0x2a86e8 ldrbmi r4, [r10], #1163 —— add fp, r1 ; add sl, fp */
/* @0x2a86ec andlt pc, r0, r9, lsl r8 —— ldrb.w fp, [sb, r0] */
/* @0x2a86f0 ble 0x3f9e60 <g_RomDisk+0x2640> —— cmp sl, fp ; bge #0x2a8700 */
/* @0x2a86f4 andge pc, r0, r9, lsl #16 —— strb.w sl, [sb, r0] */
/* @0x2a86f8 adcsne pc, r0, #212, #16 —— ldr.w r1, [r4, #0x2b0] */
/* @0x2a86fc andhi pc, r0, r1, lsl #16 —— strb.w r8, [r1, r0] */
/* @0x2a8700 svchs #0x203701 —— adds r7, #1 ; cmp r7, #0x20 */
/* @0x2a8704 andlo sp, r1, #1073741879 —— bne #0x2a86c2 ; adds r2, #1 */
/* @0x2a8708 bicle r2, r1, r0, lsr #20 —— cmp r2, #0x20 ; bne #0x2a8690 */
/* @0x2a870c blhs 0xab5318 <b2_toiTime+0x35be74> —— adds r3, #1 ; cmp r3, #0x20 */
/* @0x2a8710 .word 0xf108d1ad —— bne #0x2a866e ; add.w r8, r8, #1 */
/* @0x2a8714 .word 0xf10c0801 —— add.w ip, ip, #3 */
/* @0x2a8718 ldr r0, [r9, r3, lsl #24] —— b #0x2a8650 */
/* @0x2a871c strbmi r4, [r9], -r0, lsr #12 —— mov r0, r4 ; mov r1, sb */
/* @0x2a8720 pop {r0, r2, r3, r12, sp, pc} —— add sp, #0x34 ; pop.w {r4, r5, r6, r7, r8, sb, sl, fp, lr} */
/* @0x2a8724 .word 0xf7fe4ff0 —— b.w #0x2a6cfc */
/* @0x2a8728 .word 0xf04fbae9 —— mov.w r8, #0 */
/* @0x2a872c ldr r0, [r4, -r0, lsl #16]! —— b #0x2a859a */
/* @0x2a8730 pop {r0, r2, r3, r12, sp, pc} —— add sp, #0x34 ; pop.w {r4, r5, r6, r7, r8, sb, sl, fp, pc} */
/* @0x2a8734 strdeq r8, r9, [r0], -r0 —— （0x2a8732 起 32 位指令的后半字，非指令起点） */

/* ---- 0x2a8738 png_set_gamma（88 B / 23 条）----
 * 契约：void png_set_gamma(png_structp png, double screen_gamma, double override_file_gamma)
 *   r0=png；d6 = screen_gamma(r2:r3)；d5 = override_file_gamma([sp])
 *   0x2a8746 vldr d4 = 1e-5（池 @0x2a8788 起 8 字节）
 *   0x2a874a vnmls d7 = 1.0 - d6*d5；0x2a874e vabs；0x2a8752 vcmpe d7,d4
 *   条件：|1 - screen*override| > 1e-5 或 color_type bit2（PALETTE 掩码）或 color_type==3
 *     → 0x2a876c transformations |= 0x2000（PNG_GAMMA）
 *   0x2a8774/0x2a8778 vcvt.f32.f64 后 vstr s10 → +0x220（override/file gamma）、
 *     s12 → +0x224（screen_gamma）
 *   ⇒ 两个 gamma 一律降成 f32 存；相等判定用 1e-5 绝对容差而不是精确比较。 */
/* @0x2a8738 blhs 0x86384c <b2_toiTime+0x10a3a8> —— vmov d6, r2, r3 */
/* @0x2a873c blpl 0x2e3db8 <_ZN11b2GearJoint24SolvePositionConstraintsERK12b2SolverData+0x1b4> —— vldr d5, [sp] */
/* @0x2a8740 cdp p3, #0xb, c11, c7, c0, #0x0 —— cbz r0, #0x2a8784 ; vmov.f64 d7, #1.000000e+00 */
/* @0x2a8744 vldr d7, [pc] —— vldr d4, [pc, #0x40] */
/* @0x2a8748 vmov.32 r4, d6[0] —— vnmls.f64 d7, d6, d5 */
/* @0x2a874c vmov.f64 d7, #2.625000e+00 —— vabs.f64 d7, d7 */
/* @0x2a8750 vcmpe.f64 d7, d7 —— vcmpe.f64 d7, d4 */
/* @0x2a8754 vsqrt.f64 d23, d4 —— vmrs apsr_nzcv, fpscr */
/* @0x2a8758 .word 0xdc05fa10 —— bgt #0x2a8768 */
/* @0x2a875c .word 0x31eaf890 —— ldrb.w r3, [r0, #0x1ea] */
/* @0x2a8760 strle r0, [r1], #-1882 —— lsls r2, r3, #0x1d ; bmi #0x2a8768 */
/* @0x2a8764 .word 0xd1052b03 —— cmp r3, #3 ; bne #0x2a8774 */
/* @0x2a8768 ldrsblo pc, [r4, -r0]! —— ldr.w r3, [r0, #0x134] */
/* @0x2a876c movwpl pc, #0x443 —— orr r3, r3, #0x2000 */
/* @0x2a8770 teqlo r4, r0, asr #17 —— str.w r3, [r0, #0x134] */
/* @0x2a8774 blpl 0xff424258 <b2_toiTime+0xfffffffffeccadb4> —— vcvt.f32.f64 s10, d5 */
/* @0x2a8778 blvs 0xff46425c <b2_toiTime+0xfffffffffed0adb8> —— vcvt.f32.f64 s12, d6 */
/* @0x2a877c bpl 0xfe4e3d84 <b2_toiTime+0xfffffffffdd8a8e0> —— vstr s10, [r0, #0x220] */
/* @0x2a8780 bvs 0xfe523d88 <b2_toiTime+0xfffffffffddca8e4> —— vstr s12, [r0, #0x224] */
/* @0x2a8784 svclt #0x4770 —— bx lr */
/* @0x2a8788 ldmibls r9, {r1, r3, r4, r7, r8, r11, r12, pc} —— （未达：跳表/对齐填充） */
/* @0x2a878c svclo #0xa99999 —— （未达：跳表/对齐填充） */

/* ---- 0x2a8790 png_set_expand（32 B / 9 条）----
 * 0x2a8792 transformations |= 0x2000000；再 |= 0x1000（0x2a879a）；
 * 0x2a87a2 flags(+0x130) &= ~0x40（PNG_FLAG_ROW_INIT，清「行已初始化」）。
 * ⇒ 展开会改行布局，所以必须让行缓冲重新初始化 —— 这条清位是它与 strip_* 的实质差别。 */
/* @0x2a8790 .word 0xf8d0b168 —— cbz r0, #0x2a87ae ; ldr.w r3, [r0, #0x134] */
/* @0x2a8794 .word 0xf0433134 —— orr r3, r3, #0x2000000 */
/* @0x2a8798 vst2.8 {d23, d24, d25, d26}, [r3], r0 —— orr r3, r3, #0x1000 */
/* @0x2a879c .word 0xf8c05380 —— str.w r3, [r0, #0x134] */
/* @0x2a87a0 .word 0xf8d03134 —— ldr.w r3, [r0, #0x130] */
/* @0x2a87a4 .word 0xf0233130 —— bic r3, r3, #0x40 */
/* @0x2a87a8 .word 0xf8c00340 —— str.w r3, [r0, #0x130] */
/* @0x2a87ac .word 0x47703130 —— bx lr */

/* ════ 本卡未闭合（open）═════════════════════════════════════════════
 * 1. index 口径错：三个 index-*.tsv 与全库 instructions.jsonl 都是 llvm-objdump 的 ARM 模式解码，
 *    对这三段（Thumb-2）整体失真。本卡锚点仍按 index 原文写以保证机械一致；修法是给 asm_index.py
 *    加 --triple=thumbv7-linux-androideabi 并重生成这三个 index（另 368 个 anon 区间可能同病，
 *    凡 .dynsym 低位为 1 的都要查）。本轮约束禁止重跑 asm_index.py，故未做。
 * 2. 语义只到骨架：20 个 png_handle_* 的体（0x2abb94..0x2ada34）不在本卡区间，未开卡；
 *    png_read_info 的 chunk 分派链顺序按比较点地址给出了，但**同一段里有 4 处 IDAT 比较、2 处 PLTE**
 *    （0x2a715e 前置守卫、0x2a71b6/0x2a71f2 as_unknown 分支内、0x2a724a 主链 IDAT；
 *    0x2a71d8/0x2a7232 PLTE），与 libpng 上游"一处 IDAT 一处 PLTE"的形状不同 —— 是 GameMaker
 *    改过还是编译器复制，未定；两处 IDAT 的差（是否写 idat_size）已逐条列出但未解释。
 * 3. mode(+0x12c) 的 bit13（0x2000）未命名：出现在 IDAT 前置守卫里（mode bit3 置位时或上），
 *    本件其它地方 bit0/1/2/3 分别是 HAVE_IHDR/HAVE_PLTE/HAVE_IDAT(?)/AFTER_IDAT 的用法；
 *    bit13 的语义没有消费者证据。
 * 4. png_destroy_read_struct 里 png_free_data 的 mask 0x4000、num -1 未映射到 PNG_FREE_* 常量名；
 *    png_read_png 里 png_free_data(info, 0x40, 0) 与 info->free_me |= 0x40 已能对上 PNG_FREE_ROWS，
 *    但 0x4000 那个没找到同族证据。
 * 5. png_set_read_fn 结尾把 png_ptr+0x210 整字清零（movs r3,#0 + str.w）：既不是 flags(+0x130)
 *    也不是 transformations(+0x134)，字段身份未定。注意它是**整字写 0**而不是位清，所以不能假定
 *    等价于 libpng 常见的 flags &= ~PNG_FLAG_ROW_INIT（该对照本轮未核实上游源码）。
 * 6. 本件是游戏内置的静态 libpng 副本，.rodata 只有版本串 "libpng version 1.4.19 - December 17, 2015"；
 *    契约按 1.4.x 公共 API 写并逐条核对过字段用法，但**不能假定与上游源码逐行相同**（见 open 2 的
 *    IDAT 重复）。逐函数二进制级对照上游 1.4.19 源码未做。
 * 7. 行为未跑：本卡全部结论是静态字节证据（bytecode_anchored 级的指令锚 + 字段偏移），
 *    没有 oracle_anchored / device_anchored 的运行期对照；PNG 解码路径未用真图跑过。
 */
