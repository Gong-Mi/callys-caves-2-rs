/* cally 逆向卡：libpng 读侧 9 函数（原版 libyoyo.so，ELF32 ARM，stripped）
 *
 * @card  0x2a6ff0 .. 0x2a809c —— 9 个 @func 小节，函数体合计 4,076 B，锚点 1,529 条
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，ELF32 ARM，stripped，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-libpng_read_all.tsv —— 9 节拼接，llvm-objdump --triple=thumbv7-linux-androideabi
 *        生成，即 **Thumb-2 按真 ISA 解码**，不再是 ARM 误解码
 * 级别:  骨架
 *        · 锚点：9 节全覆盖，逐字等于 index（check_card_anchors.py → RESULT EXACT）
 *        · 语义：钉死读链路顺序、chunk 名表与分派顺序、IDAT/PLTE 的重复比较、png_struct 读侧
 *          字段偏移、内嵌 zstream 位置、png_struct 尺寸、销毁顺序与释放清单
 *        · 未钉：inflate 驱动、反滤波、行变换、隔行合成这些**内层内核**只标不解释；
 *          上游 1.4.19 源码逐行对照未做（见 open）
 *
 * ══ 这张卡是什么 ═══════════════════════════════════════════════════════
 *   它是 cards/anon_2a7e2c_group.c 的正式替代。那张卡的区间覆盖了其中 3 个 anon 段，但锚点来自
 *   asm_index.py 的 ARM 模式解码，而这三段是 Thumb-2：ARM 读法把 push.w {r4-r11,lr} 读成
 *   `svcmi #0xf0e92d`、把每条 32 位指令读成两条假 ARM 指令，"锚点逐字一致"与真实 ISA 无关，
 *   语义只能靠行尾"——"里手写的内容硬撑。本卡的锚表用 --thumb 重新生成，锚点文本**就是**真指令：
 *
 *      0x2a6ff0  e92d 4ff0   push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr}   （旧卡：svcmi #0xf0e92d）
 *      0x2a7488  e92d 43f0   push.w {r4, r5, r6, r7, r8, r9, lr}            （旧卡整段无此行）
 *      0x2a804c  b510         push {r4, lr}                                  （旧卡：.word 0x4604b510）
 *
 *   本卡不继承旧卡"——"列的任何结论：每条主张按 Thumb 原文重推。与旧卡结论一致的，在文中标"（同旧卡）"；
 *   不一致或旧卡没说的，按本卡自己的锚点重写。
 *
 * ══ 9 个函数与读链路 ══════════════════════════════════════════════════
 *   0x2a6ff0 png_read_info          1112 B  428 行 / 418 指令  签名 + chunk 循环，读到第一个 IDAT 为止
 *   0x2a7448 png_read_update_info     48 B   19 行 /  17 指令  起行缓冲 + 尾跳 png_read_transform_info
 *   0x2a7488 png_read_row            856 B  315 行 / 302 指令  解压一行 + 反滤波 + 变换 + 合成
 *   0x2a7840 png_read_image           60 B   23 行 /  23 指令  按 pass × 行 调 png_read_row
 *   0x2a787c png_read_end           1000 B  387 行 / 381 指令  IDAT 之后的 chunk 循环，读到 IEND
 *   0x2a7c64 png_read_destroy        456 B  146 行 / 146 指令  释放读侧缓冲 + 整个 png_struct 清零
 *   0x2a7e2c png_destroy_read_struct 140 B   54 行 /  54 指令  png + 两个 info 的幂等销毁
 *   0x2a7ec0 png_read_png            324 B  125 行 / 123 指令  info→变换位→update→image→end 一步到位
 *   0x2a804c png_set_read_fn          80 B   32 行 /  26 指令  设 io_ptr 与读回调
 *   （"指令数" = index 行数 − 已标数据行 39 行：literal pool 18 字（36 行）+ tbb 表 6 字节（3 行））
 *
 *   读链路（箭头 = 直接调用/尾跳，均在批内可核）：
 *
 *     png_set_read_fn ──► io_ptr/read_data_fn
 *            │
 *     png_read_info ──► png_read_sig ──► png_read_chunk_header ──► 21 名 memcmp 链 ──► png_handle_*
 *            │                    （读到第一个 IDAT 头即返回，只记 idat_size）
 *            ▼
 *     png_read_update_info ──► png_read_start_row ──► png_read_transform_info
 *            ▼
 *     png_read_image ──► (pass 0..n) × (row 0..h) ──► png_read_row ──► inflate / 反滤波 / 变换 / combine
 *            │                                              └──► png_read_finish_row ──► read_status_fn
 *            ▼
 *     png_read_end ──► png_crc_finish(0) ──► 21 名 memcmp 链（IHDR/IEND/as_unknown/PLTE/bKGD…） ──► IEND
 *            ▼
 *     png_read_destroy ──► png_info_destroy ×2 ──► 20 个 png_free/zfree ──► inflateEnd ──► memset 0x338
 *            ▼
 *     png_destroy_read_struct ──► png_read_destroy + png_free_data + png_destroy_struct_2 ×3
 *
 *   GameMaker 侧的真实路径（全库 ARM 索引里的 blx 调用点，逐个地址可复核）：
 *     _Z11loadTextureP7Texture     (0x1895ec) set_read_fn 0x1896b4 → read_info 0x1896cc →
 *                                             update_info 0x189774 → read_image 0x1897e8 → destroy ×4
 *     _Z14getTextureInfoP7Texture  (0x189968) set_read_fn 0x189a94 → read_info 0x189aac → destroy ×3
 *     _Z13ReadPNGHeaderP9yyPNGFile (0x189b78) set_read_fn 0x189c48 → read_info 0x189c68 → update_info 0x189d24
 *     _Z7ReadPNGP9yyPNGFile        (0x189e80) set_read_fn 0x189f50 → read_info 0x189f70 → update 0x18a030 →
 *                                             read_image 0x18a0cc → destroy 0x18a140/0x18a188/0x18a1c4
 *     _Z11loadTextureP3zipPKcPiS3_ (0x28fe70) 同构五连（0x28ff58 / 0x28ff70 / 0x28ffc4 / 0x290044）
 *     _Z7FreePNGP9yyPNGFile        (0x189b3c) 只调 destroy_read_struct（0x189b50）
 *   ⇒ **游戏从不调 png_read_end / png_read_png**：read_end 只有 png_read_png 尾部一个调用点，
 *     png_read_png 自身 0 个调用点（导出但未用）。真实路径是 read_info → update_info → read_image → destroy。
 *
 * ══ 跨函数已证事实（全部由本卡 9 节内部互证，逐条给锚点）══════════════════
 *   F1. 21 个 chunk 名只有一份副本，在 .rodata 0x38f90c，按 5 字节紧排：
 *       IHDR IDAT IEND PLTE bKGD cHRM gAMA hIST iCCP iTXt oFFs pCAL pHYs sBIT sCAL sPLT sRGB
 *       tEXt tIME tRNS zTXt（第 22 项起 0x000000ff / 0x00000f00 / 0x00ff0000 / 0x330000ff 已是别的东西）
 *       read_info 用 0x2a7006 ldr.w r8,[pc,#0x42c] + 0x2a7012 add r8,pc 解到 0x38f90c；
 *       read_end 用 0x2a788c/0x2a789a 解到同一地址；read_row 只取其中第 2 项 IDAT（0x2a74a2 的 [r7,#5]）。
 *   F2. 名表**每个 chunk 重铺一遍**：read_info 循环头 0x2a701c 起 100 条把 21×5 字节重写到
 *       sp+8..sp+0xac（8 B 槽 × 21，第 5 字节单存 sp+7）；read_end 在 0x2a78a4 起同构。
 *       这不是序言——所有分派出口都 `b 0x2a701c (read_info) / b 0x2a7c46 → 0x2a78a4 (read_end)`。
 *   F3. 分派 = 线性 4 字节 memcmp 链，每项 `memcmp(&chunk_name, 槽k, 4) → bl png_handle_*`：
 *       read_info 顺序：IDAT 前置守卫 → IHDR → IEND → [as_unknown] → PLTE → IDAT(break) →
 *         bKGD cHRM gAMA hIST oFFs pCAL sCAL pHYs sBIT sRGB iCCP sPLT tEXt tIME tRNS zTXt iTXt → unknown
 *       read_end  顺序：IHDR → IEND → [as_unknown] → PLTE → bKGD cHRM gAMA hIST oFFs pCAL sCAL pHYs
 *         sBIT sRGB iCCP sPLT tEXt tIME tRNS zTXt iTXt → unknown（**没有 IDAT→handler 的路**）
 *       槽位与名字的对应由 0x38f90c 的表 + 每条 memcmp 的 r1（r9/r10/r11/sp+0xNN）逐条对上，
 *       本卡每个 memcmp 锚点行都直接写出比的是哪个名字。
 *   F4. IDAT 在 read_info 里被比较 4 次（旧卡只说"4 次"没说位置，这里逐处给出）：
 *       ① 0x2a715e 循环顶前置守卫：命中且 mode bit3(0x8) 置位 → mode |= 0x2000
 *       ② 0x2a71b6 as_unknown 分支：命中 → mode |= 0x4
 *       ③ 0x2a71f2 as_unknown 分支内层：命中 → 校验 IHDR/PLTE 后**直接返回**（不写 idat_size）
 *       ④ 0x2a724a 主链：命中 → 同一套校验 → idat_size(+0x1d0) = length、mode |= 0x4、返回
 *       PLTE 在 read_info 里 2 次：0x2a71d8（as_unknown 内，mode |= 0x2）、0x2a7232（主链 → png_handle_PLTE）。
 *       read_end 另有 IDAT 2 次（0x2a7a20 / 0x2a7a68，只做 "Too many IDATs found" 守卫）、
 *       PLTE 2 次（0x2a7a4a → mode |= 0x2；0x2a7a92 → png_handle_PLTE）；read_row 有 IDAT 1 次（0x2a7604）。
 *       ⇒ 读侧全链 **IDAT 7 次、PLTE 4 次** 比较，全部是 4 字节 memcmp —— 本件没有一处 32 位整字比较。
 *   F5. mode(+0x12c) 的位用法在本卡内闭合，没有悬空位：
 *       bit0 0x1 = 有 IHDR（0x2a7200/0x2a7254 测，缺则 "Missing IHDR before IDAT"）
 *       bit1 0x2 = 有 PLTE（0x2a7216/0x2a7268 测；调色板图缺则 "Missing PLTE before IDAT"）
 *       bit2 0x4 = 有 IDAT（0x2a759c 测，缺则 read_row 报 "Invalid attempt to read row data"）
 *       bit3 0x8 = 已过 IDAT（0x2a7168 测；0x2a7674 在 zlib 流正常结束时置）
 *       bit4 0x10 = 有 IEND（0x2a7c4a 测 —— read_end 的唯一出口条件）
 *       bit13 0x2000 = 0x2a716c 置（IDAT 且已过 IDAT），0x2a7a2c / 0x2a7a74 消费 ⇒ 位不悬空（旧卡 open 3 到此闭合一半）
 *   F6. flags(+0x130) bit6(0x40) = 行缓冲已初始化，**三处独立判据**：
 *       read_update_info 0x2a7450（置位 → 告警 "Ignoring extra png_read_update_info() call…"）、
 *       read_row 0x2a74d0（置位 → 跳过 png_read_start_row）、
 *       以及不属本卡的 png_start_read_image（0x2a7478，16 B，同形）。png_set_expand 会 bic 这一位（旧卡已证）。
 *   F7. zstream 内嵌在 png+0x138（read_destroy 0x2a7dd0 的 inflateEnd(&png+0x138) 与 read_row
 *       0x2a7646 的 inflate(&png+0x138, 1) 互证）；next_out 直指 row_buf(+0x1b0)、
 *       avail_out = rowbytes+1 ⇒ inflate 就地写「滤波字节 + 一行像素」。
 *   F8. 销毁面：png_read_destroy 末尾 memset(png, 0, 0x338) ⇒ **sizeof(png_struct) = 0x338**；
 *       清零后恢复前 0x100 B（jmp_buf 区）与 +0x104/+0x108/+0x10c/+0x2f0(mem_ptr)。
 *       释放面共 20 个 png_free/png_zfree 调用点：9 个无条件（+0x170 +0x2f4 +0x1ac +0x330 +0x2b0 +0x2b4
 *       +0x228 +0x22c +0x230）+ 3 个按 +0x2c0 位守护（bit12→zfree(+0x1d8)、bit13→+0x24c、bit3→+0x2b8）
 *       + 3 张指针数组（+0x234/+0x238/+0x23c：每张逐元素 free 再 free 数组体，长度 = 1<<(8−[+0x21c])）
 *       + 收尾两个（+0x2bc、+0x274）。
 *
 * ══ 字段表（本卡实测；png_struct，单位字节偏移）═════════════════════════════
 *   +0x104 +0x108 +0x10c  三个字，销毁时保留（疑 error_fn/warning_fn/error_ptr，见 open 5）
 *   +0x110  write_data_fn        +0x114  read_data_fn        +0x118  io_ptr
 *   +0x12c  mode                 +0x130  flags               +0x134  transformations
 *   +0x138  zstream（0x38 B：next_in/avail_in/total_in/next_out/avail_out/total_out/msg/
 *           state/zalloc/zfree/opaque/data_type/adler/reserved）
 *   +0x170  zbuf                 +0x174  zbuf_size
 *   +0x18c  未知（隔行快路径拿它和 4/2/1 比阈值）      +0x190  行数源    +0x194  行数副本
 *   +0x19c  rowbytes             +0x1a4  usr_width           +0x1a8  row_number
 *   +0x1ac  prev_row             +0x1b0  row_buf
 *   +0x1c4  row_info{width(+0x1c4), rowbytes(+0x1c8), color_type(+0x1cc), bit_depth(+0x1cd),
 *           channels(+0x1ce), pixel_depth(+0x1cf)}
 *   +0x1d0  idat_size            +0x1d8  zlib 分配指针（走 png_zfree，由 +0x2c0 bit12 守护）
 *   +0x1e0  chunk_name[5]        +0x1e7  interlaced   +0x1e8  pass
 *   +0x1ea  color_type           +0x1eb  bit_depth    +0x1ed  pixel_depth   +0x1ee  channels
 *   +0x210  一个 32 位字（set_read_fn 整字清零，身份未定）
 *   +0x21c  通道/位深类计数（数组长度 = 1<<(8−x)）
 *   +0x228 +0x22c +0x230 +0x234 +0x238 +0x23c +0x24c +0x274 +0x2b0 +0x2b4 +0x2b8 +0x2bc
 *           +0x2f4 +0x330  释放点（+0x234/+0x238/+0x23c 是指针数组）
 *   +0x25c  read_status_fn
 *   +0x2c0  释放位图：bit12→png_zfree(+0x1d8)、bit13→png_free(+0x24c)、bit3→png_free(+0x2b8)
 *   +0x2dc  bit2 与 +0x2e4==0x40 共同决定是否调 png_do_read_intrapixel
 *   +0x2e8  free_fn              +0x2f0  mem_ptr
 *   png_info：+0x04 height  +0x08 valid  +0x44 png_set_shift 的通道位源  +0xb8 free_me  +0xf8 row_pointers
 *     valid(+0x08) 的位：bit1 sBIT（0x2a7f32）、bit4 tRNS（0x2a7f18）、bit15 IDAT（0x2a7f9c 置 0x8000）——
 *     三处用法与上游 PNG_INFO_* 的位号一致，故 0x0010 = tRNS 的判断有两处独立支撑。
 *
 * ══ 计数（口径写死）══════════════════════════════════════════════════════
 *   区段  index 行  数据行  指令   外部调用点(blx)  内部调用点
 *   read_info          428      10    418        5           1（read_png）
 *   read_update_info    19       2     17        4           1（read_png）
 *   read_row           315      13    302        0           4（read_rows ×3、read_image ×1）
 *   read_image          23       0     23        3           1（read_png）
 *   read_end           387       6    381        0           1（read_png 尾跳）
 *   read_destroy       146       0    146        0           1（destroy_read_struct）
 *   destroy_read_struct 54       0     54       18           0
 *   read_png           125       2    123        0           0
 *   set_read_fn         32       6     26        5           1（png_create_read_struct_2）
 *   合计              1529      39   1490       35           9
 *   "外部调用点" = 全库 ARM 索引里 blx 到该入口的 C++ 调用者（ARM 侧函数，用 blx 跨 ISA）；
 *   "内部调用点" = 本卡 9 节 + png_read_rows 之间的 bl/尾跳（Thumb 侧直呼）。
 */

/* ════════════════════════════════════════════════════════════════════
 * 节 1/9  png_read_info（0x2a6ff0 .. 0x2a7448，1112 B，418 条）
 *   契约：void png_read_info(png_structp png, png_infop info)
 *   读到第一个 IDAT 头为止：签名 → 逐 chunk 读头 → 4 字节名字线性 memcmp 分派给 20 个
 *   png_handle_* + 2 条 unknown 出口；碰到 IDAT 做 IHDR/PLTE 前置校验，置 idat_size 后返回。
 *
 *   帧：push.w 9 寄存器 + sub sp,#0xb4 → 21 个 8 B 名槽（sp+8..sp+0xac）+ 第 5 字节暂存 sp+7。
 *   寄存器：r4=png  r7=info  r5=png+0x1e0(chunk_name)  r8=0x38f90c(名表)  r6=length
 *           r9=sp+0x10(槽1=IDAT)  r10=sp+8(槽0=IHDR)  r11=sp+0x20(槽3=PLTE)
 *
 *   调了谁：png_read_sig / png_read_chunk_header / memcmp@plt ×25（21 个名字各 1 次 + IDAT 多 3 次 + PLTE 多 1 次）/
 *     20 个 png_handle_*（IHDR、IEND、PLTE + 17 个 ancillary）/ png_handle_as_unknown /
 *     png_handle_unknown ×2（合计 23 个 handler 调用点）/ png_error 2 个调用点
 *     （0x2a7228 尾跳、0x2a7272 bl），承载 4 条错误消息路径
 *   谁调它：外部 5 个 blx（0x1896cc / 0x189aac / 0x189c68 / 0x189f70 / 0x28ff70）+ png_read_png 0x2a7ece
 *     （同旧卡的 6 个点）
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a6ff0 0x2a7448 png_read_info */

/* @0x2a6ff0 push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— push.w {r4-r11,lr}；帧 0xb4（21 名表 168 B @sp+8..sp+0xaf + 余量） */
/* @0x2a6ff4 mov r7, r1 —— r7 = info_ptr */
/* @0x2a6ff6 sub sp, #0xb4 */
/* @0x2a6ff8 mov r4, r0 —— r4 = png_ptr */
/* @0x2a6ffa cmp r0, #0x0 —— png_ptr == NULL ? */
/* @0x2a6ffc beq.w 0x2a742c <png_read_info+0x43c> —— → 0x2a742c 静默返回（空参不是 png_error，同旧卡） */
/* @0x2a7000 cmp r1, #0x0 —— info_ptr == NULL ? */
/* @0x2a7002 beq.w 0x2a742c <png_read_info+0x43c> —— → 静默返回 */
/* @0x2a7006 ldr.w r8, [pc, #0x42c] —— r8 ← 字面量 0x000e88f6（名表的 pc 相对偏移） */
/* @0x2a700a bl 0x2abb94 <png_read_sig> —— bl png_read_sig(png, info)：先吃 8 字节签名 */
/* @0x2a700e add.w r10, sp, #0x8 —— r10 = sp+8（名表槽 0） */
/* @0x2a7012 add r8, pc —— r8 += pc → 0x38f90c（.rodata 里 21 个 5 字节 chunk 名的唯一副本） */
/* @0x2a7014 ldrb.w r3, [r8, #0x4] —— ldrb r3,[r8,#4] = 名 0 的第 5 字节 */
/* @0x2a7018 strb.w r3, [sp, #0x7] —— 存 sp+7：memcmp 只比 4 字节，第 5 字节单独留一格 */
/* @0x2a701c ldrb.w r3, [sp, #0x7] —— 循环头：把 sp+7 写回槽 0 第 5 字节 */
/* @0x2a7020 add.w r9, sp, #0x10 —— r9 = sp+0x10（槽 1 = IDAT） */
/* @0x2a7024 ldr.w r0, [r8] —— r0 = [r8] = "IHDR" 前 4 字节 */
/* @0x2a7028 add.w r5, r4, #0x1e0 —— r5 = png+0x1e0 = chunk_name[5]（比较的另一侧） */
/* @0x2a702c add.w r11, sp, #0x20 —— r11 = sp+0x20（槽 3 = PLTE） */
/* @0x2a7030 strb.w r3, [r10, #0x4] —— 槽 0 第 5 字节落位 */
/* ---- 槽 1..20 的铺设（0x2a7034..0x2a714c，100 条）----
 * 每个名字 5 字节 = ldr 4 字节 + ldrb 第 5 字节，写进 8 B 槽（sp+8+8k）；源 = 0x38f90c + 5k。
 * 21 个槽位（k: offset: name）：
 *   0 sp+8    IHDR   1 sp+0x10 IDAT   2 sp+0x18 IEND   3 sp+0x20 PLTE   4 sp+0x28 bKGD
 *   5 sp+0x30 cHRM   6 sp+0x38 gAMA   7 sp+0x40 hIST   8 sp+0x48 iCCP   9 sp+0x50 iTXt
 *  10 sp+0x58 oFFs  11 sp+0x60 pCAL  12 sp+0x68 pHYs  13 sp+0x70 sBIT  14 sp+0x78 sCAL
 *  15 sp+0x80 sPLT  16 sp+0x88 sRGB  17 sp+0x90 tEXt  18 sp+0x98 tIME  19 sp+0xa0 tRNS
 *  20 sp+0xa8 zTXt
 * 槽序 = 名表的字母序；分派序 ≠ 槽序（见 F3），所以后面的 memcmp 是"按槽跳"而不是顺扫。 */
/* @0x2a7034 mov r3, r8 —— 槽 1 的 4 字节落位（下面整段是铺设，见上） */
/* @0x2a7036 str.w r0, [r10] */
/* @0x2a703a ldr r0, [r3, #5]! */
/* @0x2a703e ldrb r3, [r3, #0x4] */
/* @0x2a7040 str r0, [sp, #0x10] */
/* @0x2a7042 strb.w r3, [sp, #0x14] */
/* @0x2a7046 mov r3, r8 */
/* @0x2a7048 ldr r0, [r3, #10]! */
/* @0x2a704c ldrb r3, [r3, #0x4] */
/* @0x2a704e str r0, [sp, #0x18] */
/* @0x2a7050 strb.w r3, [sp, #0x1c] */
/* @0x2a7054 mov r3, r8 */
/* @0x2a7056 ldr r0, [r3, #15]! */
/* @0x2a705a ldrb r3, [r3, #0x4] */
/* @0x2a705c str r0, [sp, #0x20] */
/* @0x2a705e strb.w r3, [sp, #0x24] */
/* @0x2a7062 mov r3, r8 */
/* @0x2a7064 ldr r0, [r3, #20]! */
/* @0x2a7068 ldrb r3, [r3, #0x4] */
/* @0x2a706a str r0, [sp, #0x28] */
/* @0x2a706c strb.w r3, [sp, #0x2c] */
/* @0x2a7070 mov r3, r8 */
/* @0x2a7072 ldr r0, [r3, #25]! */
/* @0x2a7076 ldrb r3, [r3, #0x4] */
/* @0x2a7078 str r0, [sp, #0x30] */
/* @0x2a707a strb.w r3, [sp, #0x34] */
/* @0x2a707e mov r3, r8 */
/* @0x2a7080 ldr r0, [r3, #30]! */
/* @0x2a7084 ldrb r3, [r3, #0x4] */
/* @0x2a7086 str r0, [sp, #0x38] */
/* @0x2a7088 strb.w r3, [sp, #0x3c] */
/* @0x2a708c mov r3, r8 */
/* @0x2a708e ldr r0, [r3, #35]! */
/* @0x2a7092 ldrb r3, [r3, #0x4] */
/* @0x2a7094 str r0, [sp, #0x40] */
/* @0x2a7096 strb.w r3, [sp, #0x44] */
/* @0x2a709a mov r3, r8 */
/* @0x2a709c ldr r0, [r3, #40]! */
/* @0x2a70a0 str r0, [sp, #0x48] */
/* @0x2a70a2 ldrb r3, [r3, #0x4] */
/* @0x2a70a4 strb.w r3, [sp, #0x4c] */
/* @0x2a70a8 mov r3, r8 */
/* @0x2a70aa ldr r0, [r3, #45]! */
/* @0x2a70ae ldrb r3, [r3, #0x4] */
/* @0x2a70b0 str r0, [sp, #0x50] */
/* @0x2a70b2 strb.w r3, [sp, #0x54] */
/* @0x2a70b6 mov r3, r8 */
/* @0x2a70b8 ldr r0, [r3, #50]! */
/* @0x2a70bc ldrb r3, [r3, #0x4] */
/* @0x2a70be str r0, [sp, #0x58] */
/* @0x2a70c0 strb.w r3, [sp, #0x5c] */
/* @0x2a70c4 mov r3, r8 */
/* @0x2a70c6 ldr r0, [r3, #55]! */
/* @0x2a70ca ldrb r3, [r3, #0x4] */
/* @0x2a70cc str r0, [sp, #0x60] */
/* @0x2a70ce strb.w r3, [sp, #0x64] */
/* @0x2a70d2 mov r3, r8 */
/* @0x2a70d4 ldr r0, [r3, #60]! */
/* @0x2a70d8 ldrb r3, [r3, #0x4] */
/* @0x2a70da str r0, [sp, #0x68] */
/* @0x2a70dc strb.w r3, [sp, #0x6c] */
/* @0x2a70e0 mov r3, r8 */
/* @0x2a70e2 ldr r0, [r3, #65]! */
/* @0x2a70e6 ldrb r3, [r3, #0x4] */
/* @0x2a70e8 str r0, [sp, #0x70] */
/* @0x2a70ea strb.w r3, [sp, #0x74] */
/* @0x2a70ee mov r3, r8 */
/* @0x2a70f0 ldr r0, [r3, #70]! */
/* @0x2a70f4 ldrb r3, [r3, #0x4] */
/* @0x2a70f6 str r0, [sp, #0x78] */
/* @0x2a70f8 strb.w r3, [sp, #0x7c] */
/* @0x2a70fc mov r3, r8 */
/* @0x2a70fe ldr r0, [r3, #75]! */
/* @0x2a7102 ldrb r3, [r3, #0x4] */
/* @0x2a7104 str r0, [sp, #0x80] */
/* @0x2a7106 strb.w r3, [sp, #0x84] */
/* @0x2a710a mov r3, r8 */
/* @0x2a710c ldr r0, [r3, #80]! */
/* @0x2a7110 ldrb r3, [r3, #0x4] */
/* @0x2a7112 str r0, [sp, #0x88] */
/* @0x2a7114 strb.w r3, [sp, #0x8c] */
/* @0x2a7118 mov r3, r8 */
/* @0x2a711a ldr r0, [r3, #85]! */
/* @0x2a711e ldrb r3, [r3, #0x4] */
/* @0x2a7120 str r0, [sp, #0x90] */
/* @0x2a7122 strb.w r3, [sp, #0x94] */
/* @0x2a7126 mov r3, r8 */
/* @0x2a7128 ldr r0, [r3, #90]! */
/* @0x2a712c ldrb r3, [r3, #0x4] */
/* @0x2a712e str r0, [sp, #0x98] */
/* @0x2a7130 strb.w r3, [sp, #0x9c] */
/* @0x2a7134 mov r3, r8 */
/* @0x2a7136 ldr r0, [r3, #95]! */
/* @0x2a713a ldrb r3, [r3, #0x4] */
/* @0x2a713c str r0, [sp, #0xa0] */
/* @0x2a713e strb.w r3, [sp, #0xa4] */
/* @0x2a7142 mov r3, r8 */
/* @0x2a7144 ldr r0, [r3, #100]! */
/* @0x2a7148 ldrb r3, [r3, #0x4] */
/* @0x2a714a str r0, [sp, #0xa8] */
/* @0x2a714c mov r0, r4 —— r0 = png_ptr（名表铺完，进入读头） */
/* @0x2a714e strb.w r3, [sp, #0xac] */
/* @0x2a7152 bl 0x2adbc4 <png_read_chunk_header> —— bl png_read_chunk_header(png) → length */
/* @0x2a7156 mov r1, r9 —— r1 = r9（槽 1） */
/* @0x2a7158 movs r2, #0x4 —— r2 = 4 */
/* @0x2a715a mov r6, r0 —— r6 = length（后续所有 handler 的第 3 实参） */
/* @0x2a715c mov r0, r5 —— r0 = &chunk_name */
/* @0x2a715e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：IDAT 比较 #1/4（循环顶前置守卫）：命中且 mode bit3 置位 → 0x2a716c 置 bit13 */
/* @0x2a7162 cbnz r0, 0x2a7174 <png_read_info+0x184> —— 不相等 → 0x2a7174 */
/* @0x2a7164 ldr.w r3, [r4, #0x12c] —— mode(+0x12c) */
/* @0x2a7168 lsls r2, r3, #0x1c —— lsls #0x1c → 测 bit3 (0x8) */
/* @0x2a716a itt mi */
/* @0x2a716c orrmi r3, r3, #0x2000 —— orr #0x2000（bit13） */
/* @0x2a7170 strmi.w r3, [r4, #0x12c] —— strmi 写回（条件写，不置位则完全不碰 mode） */
/* @0x2a7174 mov r0, r5 —— r0 = &chunk_name */
/* @0x2a7176 mov r1, r10 —— r1 = r10（槽 0） */
/* @0x2a7178 movs r2, #0x4 */
/* @0x2a717a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IHDR", 4) */
/* @0x2a717e cbnz r0, 0x2a718c <png_read_info+0x19c> —— 不相等 → 0x2a718c */
/* @0x2a7180 mov r0, r4 —— r0 = png */
/* @0x2a7182 mov r1, r7 —— r1 = info */
/* @0x2a7184 mov r2, r6 —— r2 = length */
/* @0x2a7186 bl 0x2abe50 <png_handle_IHDR> —— bl png_handle_IHDR(png, info, length) */
/* @0x2a718a b 0x2a701c <png_read_info+0x2c> —— 回循环头（整张名表重铺） */
/* @0x2a718c mov r0, r5 —— r0 = &chunk_name */
/* @0x2a718e add r1, sp, #0x18 —— r1 = sp+0x18（槽 2） */
/* @0x2a7190 movs r2, #0x4 */
/* @0x2a7192 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IEND", 4) */
/* @0x2a7196 cbnz r0, 0x2a71a4 <png_read_info+0x1b4> —— 不相等 → 0x2a71a4 */
/* @0x2a7198 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a719a mov r1, r7 */
/* @0x2a719c mov r2, r6 */
/* @0x2a719e bl 0x2ac0c8 <png_handle_IEND> —— bl png_handle_IEND */
/* @0x2a71a2 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a71a4 mov r0, r4 —— r0 = png */
/* @0x2a71a6 mov r1, r5 —— r1 = &chunk_name */
/* @0x2a71a8 bl 0x2a5fe4 <png_handle_as_unknown> —— bl png_handle_as_unknown(png, &chunk_name) */
/* @0x2a71ac cmp r0, #0x0 —— == 0（没被登记成 unknown）→ 0x2a722c 主链 */
/* @0x2a71ae beq 0x2a722c <png_read_info+0x23c> */
/* @0x2a71b0 mov r0, r5 —— r0 = &chunk_name */
/* @0x2a71b2 mov r1, r9 —— r1 = r9（槽 1） */
/* @0x2a71b4 movs r2, #0x4 */
/* @0x2a71b6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：#2/4（as_unknown 分支）：命中 → mode |= 0x4 */
/* @0x2a71ba cbnz r0, 0x2a71c8 <png_read_info+0x1d8> —— 不相等 → 0x2a71c8 */
/* @0x2a71bc ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a71c0 orr r3, r3, #0x4 —— orr #0x4（bit2 = 有 IDAT） */
/* @0x2a71c4 str.w r3, [r4, #0x12c] —— 写回 */
/* @0x2a71c8 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a71ca mov r1, r7 */
/* @0x2a71cc mov r2, r6 */
/* @0x2a71ce bl 0x2ada34 <png_handle_unknown> —— bl png_handle_unknown(png, info, length) */
/* @0x2a71d2 mov r0, r5 —— r0 = &chunk_name */
/* @0x2a71d4 mov r1, r11 —— r1 = r11（槽 3） */
/* @0x2a71d6 movs r2, #0x4 */
/* @0x2a71d8 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "PLTE", 4)：PLTE #1/2（as_unknown 分支）：命中 → mode |= 0x2 */
/* @0x2a71dc cbnz r0, 0x2a71ec <png_read_info+0x1fc> —— 不相等 → 0x2a71ec */
/* @0x2a71de ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a71e2 orr r3, r3, #0x2 —— orr #0x2（bit1 = 有 PLTE） */
/* @0x2a71e6 str.w r3, [r4, #0x12c] —— 写回 */
/* @0x2a71ea b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a71ec mov r0, r5 —— r0 = &chunk_name */
/* @0x2a71ee mov r1, r9 —— r1 = r9（槽 1） */
/* @0x2a71f0 movs r2, #0x4 */
/* @0x2a71f2 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：#3/4（as_unknown 分支内层）：命中 → 校验 IHDR/PLTE 后直接返回，不写 idat_size */
/* @0x2a71f6 cmp r0, #0x0 —— 不相等 → 回循环头 */
/* @0x2a71f8 bne.w 0x2a701c <png_read_info+0x2c> */
/* @0x2a71fc ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7200 lsls r0, r3, #0x1f —— lsls #0x1f → 测 bit0 (0x1 = 有 IHDR) */
/* @0x2a7202 bmi 0x2a720c <png_read_info+0x21c> —— 置位 → 0x2a720c 继续查 PLTE */
/* @0x2a7204 ldr r1, [pc, #0x230] —— r1 = "Missing IHDR before IDAT"（0x38c7da） */
/* @0x2a7206 mov r0, r4 */
/* @0x2a7208 add r1, pc */
/* @0x2a720a b 0x2a7222 <png_read_info+0x232> —— → 0x2a7222 */
/* @0x2a720c ldrb.w r2, [r4, #0x1ea] —— color_type(+0x1ea) */
/* @0x2a7210 cmp r2, #0x3 —— != 3（非调色板）→ 0x2a742c 正常返回 */
/* @0x2a7212 bne.w 0x2a742c <png_read_info+0x43c> */
/* @0x2a7216 lsls r1, r3, #0x1e —— lsls #0x1e → 测 bit1 (0x2 = 有 PLTE) */
/* @0x2a7218 bmi.w 0x2a742c <png_read_info+0x43c> —— 置位 → 0x2a742c 正常返回 */
/* @0x2a721c ldr r1, [pc, #0x21c] —— r1 = "Missing PLTE before IDAT"（0x38c7f3） */
/* @0x2a721e mov r0, r4 */
/* @0x2a7220 add r1, pc */
/* @0x2a7222 add sp, #0xb4 */
/* @0x2a7224 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— pop.w {r4-r11,lr} */
/* @0x2a7228 b.w 0x2a642c <png_error> —— b.w png_error：noreturn 通道：出错即离栈，不回到本函数 */
/* @0x2a722c mov r0, r5 —— 主链：r0 = &chunk_name */
/* @0x2a722e mov r1, r11 —— r1 = r11（槽 3） */
/* @0x2a7230 movs r2, #0x4 */
/* @0x2a7232 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "PLTE", 4)：PLTE #2/2（主链）：命中 → png_handle_PLTE */
/* @0x2a7236 cbnz r0, 0x2a7244 <png_read_info+0x254> —— 不相等 → 0x2a7244 */
/* @0x2a7238 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a723a mov r1, r7 */
/* @0x2a723c mov r2, r6 */
/* @0x2a723e bl 0x2abf64 <png_handle_PLTE> —— bl png_handle_PLTE(png, info, length) */
/* @0x2a7242 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7244 mov r0, r5 —— r0 = &chunk_name */
/* @0x2a7246 mov r1, r9 —— r1 = r9（槽 1） */
/* @0x2a7248 movs r2, #0x4 */
/* @0x2a724a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：#4/4（主链）：命中 → 校验后 idat_size = length、mode |= 0x4、返回 */
/* @0x2a724e cbnz r0, 0x2a7288 <png_read_info+0x298> —— 不相等 → 0x2a7288（转 ancillary 链） */
/* @0x2a7250 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7254 lsls r2, r3, #0x1f —— 测 bit0 */
/* @0x2a7256 bmi 0x2a7260 <png_read_info+0x270> —— 置位 → 0x2a7260 */
/* @0x2a7258 ldr r1, [pc, #0x1e4] —— r1 = "Missing IHDR before IDAT" */
/* @0x2a725a mov r0, r4 */
/* @0x2a725c add r1, pc */
/* @0x2a725e b 0x2a7272 <png_read_info+0x282> —— → 0x2a7272 */
/* @0x2a7260 ldrb.w r2, [r4, #0x1ea] —— color_type */
/* @0x2a7264 cmp r2, #0x3 —— != 3 → 0x2a7276 */
/* @0x2a7266 bne 0x2a7276 <png_read_info+0x286> */
/* @0x2a7268 lsls r3, r3, #0x1e —— 测 bit1 */
/* @0x2a726a bmi 0x2a7276 <png_read_info+0x286> —— 置位 → 0x2a7276 */
/* @0x2a726c ldr r1, [pc, #0x1d4] —— r1 = "Missing PLTE before IDAT" */
/* @0x2a726e mov r0, r4 */
/* @0x2a7270 add r1, pc */
/* @0x2a7272 bl 0x2a642c <png_error> —— bl png_error（本函数唯一一处 bl 形式的 png_error） */
/* @0x2a7276 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a727a str.w r6, [r4, #0x1d0] —— idat_size(+0x1d0) = length */
/* @0x2a727e orr r3, r3, #0x4 —— orr #0x4（有 IDAT） */
/* @0x2a7282 str.w r3, [r4, #0x12c] —— 写回 */
/* @0x2a7286 b 0x2a742c <png_read_info+0x43c> —— → 0x2a742c：拿到第一个 IDAT 头就收工，像素留给 read_row / read_image */
/* @0x2a7288 mov r0, r5 */
/* @0x2a728a add r1, sp, #0x28 */
/* @0x2a728c movs r2, #0x4 */
/* @0x2a728e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "bKGD", 4) */
/* @0x2a7292 cbnz r0, 0x2a72a0 <png_read_info+0x2b0> */
/* @0x2a7294 mov r0, r4 */
/* @0x2a7296 mov r1, r7 */
/* @0x2a7298 mov r2, r6 */
/* @0x2a729a bl 0x2acd60 <png_handle_bKGD> —— bl png_handle_*（png, info, length） */
/* @0x2a729e b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a72a0 mov r0, r5 */
/* @0x2a72a2 add r1, sp, #0x30 */
/* @0x2a72a4 movs r2, #0x4 */
/* @0x2a72a6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "cHRM", 4) */
/* @0x2a72aa cbnz r0, 0x2a72b8 <png_read_info+0x2c8> */
/* @0x2a72ac mov r0, r4 */
/* @0x2a72ae mov r1, r7 */
/* @0x2a72b0 mov r2, r6 */
/* @0x2a72b2 bl 0x2ac328 <png_handle_cHRM> —— bl png_handle_*（png, info, length） */
/* @0x2a72b6 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a72b8 mov r0, r5 */
/* @0x2a72ba add r1, sp, #0x38 */
/* @0x2a72bc movs r2, #0x4 */
/* @0x2a72be blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "gAMA", 4) */
/* @0x2a72c2 cbnz r0, 0x2a72d0 <png_read_info+0x2e0> */
/* @0x2a72c4 mov r0, r4 */
/* @0x2a72c6 mov r1, r7 */
/* @0x2a72c8 mov r2, r6 */
/* @0x2a72ca bl 0x2ac110 <png_handle_gAMA> —— bl png_handle_*（png, info, length） */
/* @0x2a72ce b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a72d0 mov r0, r5 */
/* @0x2a72d2 add r1, sp, #0x40 */
/* @0x2a72d4 movs r2, #0x4 */
/* @0x2a72d6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "hIST", 4) */
/* @0x2a72da cbnz r0, 0x2a72e8 <png_read_info+0x2f8> */
/* @0x2a72dc mov r0, r4 */
/* @0x2a72de mov r1, r7 */
/* @0x2a72e0 mov r2, r6 */
/* @0x2a72e2 bl 0x2ace98 <png_handle_hIST> —— bl png_handle_*（png, info, length） */
/* @0x2a72e6 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a72e8 mov r0, r5 */
/* @0x2a72ea add r1, sp, #0x58 */
/* @0x2a72ec movs r2, #0x4 */
/* @0x2a72ee blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "oFFs", 4) */
/* @0x2a72f2 cbnz r0, 0x2a7300 <png_read_info+0x310> */
/* @0x2a72f4 mov r0, r4 */
/* @0x2a72f6 mov r1, r7 */
/* @0x2a72f8 mov r2, r6 */
/* @0x2a72fa bl 0x2ad030 <png_handle_oFFs> —— bl png_handle_*（png, info, length） */
/* @0x2a72fe b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7300 mov r0, r5 */
/* @0x2a7302 add r1, sp, #0x60 */
/* @0x2a7304 movs r2, #0x4 */
/* @0x2a7306 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "pCAL", 4) */
/* @0x2a730a cbnz r0, 0x2a7318 <png_read_info+0x328> */
/* @0x2a730c mov r0, r4 */
/* @0x2a730e mov r1, r7 */
/* @0x2a7310 mov r2, r6 */
/* @0x2a7312 bl 0x2ad128 <png_handle_pCAL> —— bl png_handle_*（png, info, length） */
/* @0x2a7316 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7318 mov r0, r5 */
/* @0x2a731a add r1, sp, #0x78 */
/* @0x2a731c movs r2, #0x4 */
/* @0x2a731e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sCAL", 4) */
/* @0x2a7322 cbnz r0, 0x2a7330 <png_read_info+0x340> */
/* @0x2a7324 mov r0, r4 */
/* @0x2a7326 mov r1, r7 */
/* @0x2a7328 mov r2, r6 */
/* @0x2a732a bl 0x2ad350 <png_handle_sCAL> —— bl png_handle_*（png, info, length） */
/* @0x2a732e b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7330 mov r0, r5 */
/* @0x2a7332 add r1, sp, #0x68 */
/* @0x2a7334 movs r2, #0x4 */
/* @0x2a7336 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "pHYs", 4) */
/* @0x2a733a cbnz r0, 0x2a7348 <png_read_info+0x358> */
/* @0x2a733c mov r0, r4 */
/* @0x2a733e mov r1, r7 */
/* @0x2a7340 mov r2, r6 */
/* @0x2a7342 bl 0x2acf58 <png_handle_pHYs> —— bl png_handle_*（png, info, length） */
/* @0x2a7346 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7348 mov r0, r5 */
/* @0x2a734a add r1, sp, #0x70 */
/* @0x2a734c movs r2, #0x4 */
/* @0x2a734e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sBIT", 4) */
/* @0x2a7352 cbnz r0, 0x2a7360 <png_read_info+0x370> */
/* @0x2a7354 mov r0, r4 */
/* @0x2a7356 mov r1, r7 */
/* @0x2a7358 mov r2, r6 */
/* @0x2a735a bl 0x2ac238 <png_handle_sBIT> —— bl png_handle_*（png, info, length） */
/* @0x2a735e b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7360 mov r0, r5 */
/* @0x2a7362 add r1, sp, #0x88 */
/* @0x2a7364 movs r2, #0x4 */
/* @0x2a7366 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sRGB", 4) */
/* @0x2a736a cbnz r0, 0x2a7378 <png_read_info+0x388> */
/* @0x2a736c mov r0, r4 */
/* @0x2a736e mov r1, r7 */
/* @0x2a7370 mov r2, r6 */
/* @0x2a7372 bl 0x2ac694 <png_handle_sRGB> —— bl png_handle_*（png, info, length） */
/* @0x2a7376 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7378 mov r0, r5 */
/* @0x2a737a add r1, sp, #0x48 */
/* @0x2a737c movs r2, #0x4 */
/* @0x2a737e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "iCCP", 4) */
/* @0x2a7382 cbnz r0, 0x2a7390 <png_read_info+0x3a0> */
/* @0x2a7384 mov r0, r4 */
/* @0x2a7386 mov r1, r7 */
/* @0x2a7388 mov r2, r6 */
/* @0x2a738a bl 0x2ac814 <png_handle_iCCP> —— bl png_handle_*（png, info, length） */
/* @0x2a738e b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7390 mov r0, r5 */
/* @0x2a7392 add r1, sp, #0x80 */
/* @0x2a7394 movs r2, #0x4 */
/* @0x2a7396 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sPLT", 4) */
/* @0x2a739a cbnz r0, 0x2a73a8 <png_read_info+0x3b8> */
/* @0x2a739c mov r0, r4 */
/* @0x2a739e mov r1, r7 */
/* @0x2a73a0 mov r2, r6 */
/* @0x2a73a2 bl 0x2ac9ec <png_handle_sPLT> —— bl png_handle_*（png, info, length） */
/* @0x2a73a6 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a73a8 mov r0, r5 */
/* @0x2a73aa add r1, sp, #0x90 */
/* @0x2a73ac movs r2, #0x4 */
/* @0x2a73ae blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tEXt", 4) */
/* @0x2a73b2 cbnz r0, 0x2a73c0 <png_read_info+0x3d0> */
/* @0x2a73b4 mov r0, r4 */
/* @0x2a73b6 mov r1, r7 */
/* @0x2a73b8 mov r2, r6 */
/* @0x2a73ba bl 0x2ad584 <png_handle_tEXt> —— bl png_handle_*（png, info, length） */
/* @0x2a73be b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a73c0 mov r0, r5 */
/* @0x2a73c2 add r1, sp, #0x98 */
/* @0x2a73c4 movs r2, #0x4 */
/* @0x2a73c6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tIME", 4) */
/* @0x2a73ca cbnz r0, 0x2a73d8 <png_read_info+0x3e8> */
/* @0x2a73cc mov r0, r4 */
/* @0x2a73ce mov r1, r7 */
/* @0x2a73d0 mov r2, r6 */
/* @0x2a73d2 bl 0x2ad4d0 <png_handle_tIME> —— bl png_handle_*（png, info, length） */
/* @0x2a73d6 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a73d8 mov r0, r5 */
/* @0x2a73da add r1, sp, #0xa0 */
/* @0x2a73dc movs r2, #0x4 */
/* @0x2a73de blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tRNS", 4) */
/* @0x2a73e2 cbnz r0, 0x2a73f0 <png_read_info+0x400> */
/* @0x2a73e4 mov r0, r4 */
/* @0x2a73e6 mov r1, r7 */
/* @0x2a73e8 mov r2, r6 */
/* @0x2a73ea bl 0x2acbec <png_handle_tRNS> —— bl png_handle_*（png, info, length） */
/* @0x2a73ee b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a73f0 mov r0, r5 */
/* @0x2a73f2 add r1, sp, #0xa8 */
/* @0x2a73f4 movs r2, #0x4 */
/* @0x2a73f6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "zTXt", 4) */
/* @0x2a73fa cbnz r0, 0x2a7408 <png_read_info+0x418> */
/* @0x2a73fc mov r0, r4 */
/* @0x2a73fe mov r1, r7 */
/* @0x2a7400 mov r2, r6 */
/* @0x2a7402 bl 0x2ad6cc <png_handle_zTXt> —— bl png_handle_*（png, info, length） */
/* @0x2a7406 b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7408 mov r0, r5 */
/* @0x2a740a add r1, sp, #0x50 */
/* @0x2a740c movs r2, #0x4 */
/* @0x2a740e blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "iTXt", 4) */
/* @0x2a7412 cbnz r0, 0x2a7420 <png_read_info+0x430> */
/* @0x2a7414 mov r0, r4 */
/* @0x2a7416 mov r1, r7 */
/* @0x2a7418 mov r2, r6 */
/* @0x2a741a bl 0x2ad850 <png_handle_iTXt> —— bl png_handle_*（png, info, length） */
/* @0x2a741e b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a7420 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a7422 mov r1, r7 */
/* @0x2a7424 mov r2, r6 */
/* @0x2a7426 bl 0x2ada34 <png_handle_unknown> —— bl png_handle_unknown：21 名全不命中（同旧卡） */
/* @0x2a742a b 0x2a701c <png_read_info+0x2c> —— 回循环头 */
/* @0x2a742c add sp, #0xb4 —— 唯一正常出口（双 NULL 门 / IDAT 命中 / png_error 分支的落点） */
/* @0x2a742e pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— pop.w {r4-r11,pc} */
/* @0x2a7432 nop —— nop（对齐填充） */
/* @0x2a7434 ldrh r6, [r6, #0x6] —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7436 movs r6, r1 —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7438 strb r6, [r1, r7] —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a743a movs r6, r1 —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a743c strb r7, [r1, r7] —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a743e movs r6, r1 —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7440 strb r2, [r7, r5] —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7442 movs r6, r1 —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7444 strb r7, [r7, r5] —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */
/* @0x2a7446 movs r6, r1 —— 数据字：literal pool（0x2a7434 = 0x000e88f6 名表基址；之后 4 字 = 两条错误串偏移 0x000e55ce/0x000e55cf/0x000e557a/0x000e557f） */

/* ════════════════════════════════════════════════════════════════════
 * 节 2/9  png_read_update_info（0x2a7448 .. 0x2a7478，48 B，17 条）
 *   契约：void png_read_update_info(png_structp png, png_infop info)
 *   本函数自己只做一件事：**首次调用时起行缓冲**（flags bit6 未置 → png_read_start_row），
 *   然后无条件尾跳 png_read_transform_info(png, info)。第二次调用只发一条告警，不重分配。
 *   尾跳前已 pop 掉自己的帧（0x2a746a），所以栈上是干净的转移。
 *   谁调它：外部 4 个 blx（0x189774 / 0x189d24 / 0x18a030 / 0x28ffc4）+ png_read_png 0x2a7f76
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7448 0x2a7478 png_read_update_info */

/* @0x2a7448 push {r3, r4, r5, lr} —— push {r3,r4,r5,lr}（r3 只为 8 B 对齐） */
/* @0x2a744a mov r5, r1 —— r5 = info_ptr */
/* @0x2a744c mov r4, r0 —— r4 = png_ptr */
/* @0x2a744e cbz r0, 0x2a7472 <png_read_update_info+0x2a> —— png_ptr == NULL ? → 0x2a7472 返回 */
/* @0x2a7450 ldr.w r3, [r0, #0x130] —— flags(+0x130) */
/* @0x2a7454 lsls r3, r3, #0x19 —— lsls #0x19 → 测 bit6 (0x40 = 行缓冲已初始化) */
/* @0x2a7456 bmi 0x2a745e <png_read_update_info+0x16> —— 置位 → 0x2a745e 走告警 */
/* @0x2a7458 bl 0x2ae494 <png_read_start_row> —— bl png_read_start_row(png)：首次调用才起行缓冲 */
/* @0x2a745c b 0x2a7466 <png_read_update_info+0x1e> —— → 0x2a7466 */
/* @0x2a745e ldr r1, [pc, #0x14] —— r1 = 告警串（0x38c80c） */
/* @0x2a7460 add r1, pc —— r1 += pc */
/* @0x2a7462 bl 0x2a6474 <png_warning> —— bl png_warning(png, "Ignoring extra png_read_update_info() call; row buffer not reallocated") */
/* @0x2a7466 mov r0, r4 —— r0 = png */
/* @0x2a7468 mov r1, r5 —— r1 = info */
/* @0x2a746a pop.w {r3, r4, r5, lr} —— pop.w {r3,r4,r5,lr}：先拆帧再尾跳 */
/* @0x2a746e b.w 0x2a89bc <png_read_transform_info> —— b.w png_read_transform_info(png, info)：本函数不做别的事 */
/* @0x2a7472 pop {r3, r4, r5, pc} */
/* @0x2a7474 strh r0, [r5, r6] —— 数据字：literal pool（0x2a7474 = 0x000e53a8 → 0x38c80c 告警串） */
/* @0x2a7476 movs r6, r1 —— 数据字：literal pool（0x2a7474 = 0x000e53a8 → 0x38c80c 告警串） */

/* ════════════════════════════════════════════════════════════════════
 * 节 3/9  png_read_row（0x2a7488 .. 0x2a77e0，856 B，302 条）
 *   契约：void png_read_row(png_structp png, png_bytep row, png_bytep dsp_row)
 *   r4=png  r8=row（可 NULL）  r5=dsp_row（可 NULL）。
 *
 *   ★ 开头两件事，都是常量铺栈：
 *     ① sp+8 铺 "IDAT"（取自 0x38f90c 名表第 2 项，4 字节 + 第 5 字节）—— 后面 0x2a7604 用它判 IDAT；
 *     ② sp+0x10 / sp+0x2c 各铺 28 B = **7 个 32 位常量**，值取自 .rodata 0x38f978 / 0x38f994：
 *        0x38f978 = ff 0f ff 33 ff 55 ff   （= 上游 png_pass_dsp_mask 的 7 项，本件按 32 位存）
 *        0x38f994 = 80 08 88 22 aa 55 ff   （= 上游 png_pass_mask     的 7 项，本件按 32 位存）
 *        两张表按 pass 取值，直接作为 png_combine_row 的**第 3 实参**（不是 display 布尔）——
 *        dsp_row 用 dsp_mask、row 用 pass_mask，见 0x2a7770 / 0x2a778c。这是本件与上游签名的一处硬差异。
 *
 *   ★ 隔行快路径（0x2a74de..0x2a75a0）：interlaced && (transformations & 0x2) 时按 pass 走 6 项 tbb，
 *     判据全部是 row_number(+0x1a8) 的位 + [+0x18c] 的阈值比较（4 / 2 / 1）：
 *        pass 0 → (row & 4) == 0
 *        pass 1 → (row & 4) == 0 且 [+0x18c] > 4
 *        pass 2 → (row & 7) == 4
 *        pass 3 → (row & 2) == 0 且 [+0x18c] > 2
 *        pass 4 → (row & 3) == 2
 *        pass 5 → (row & 1) == 0 且 [+0x18c] > 1
 *        pass 6 → (row & 1) == 1
 *     命中「本行不在本 pass」→ 只对 dsp_row 做 png_combine_row(dsp_mask[pass]) 后
 *     **尾跳 png_read_finish_row 直接返回**（不解压、不反滤波）。阈值 4/2/1 与 Adam7 的
 *     ystart/yinc 形状一致，但 [+0x18c] 究竟是 height 还是 num_rows 未定（open 2）。
 *
 *   ★ 主路径：mode bit2 检查 → 算 rowbytes → 喂 zlib（zbuf 经 png_crc_read）→ inflate
 *     → 反滤波（png_read_filter_row，5 实参含滤波类型）→ prev_row := row_buf
 *     → intrapixel（条件门）→ png_do_read_transformations → 隔行：png_do_read_interlace + combine
 *     → png_read_finish_row → 可选 read_status_fn(png, row_number, pass)。
 *     zlib 正常结束时置 mode bit3 与 flags bit0x20；不正常时错误串取 zstream.msg 或 "Decompression error"。
 *
 *   调了谁：png_read_start_row / png_crc_finish / png_read_chunk_header / memcmp@plt(IDAT) /
 *     png_crc_read / inflate@plt / png_read_filter_row / memcpy@plt / png_do_read_intrapixel /
 *     png_do_read_transformations / png_do_read_interlace / png_combine_row ×N / png_read_finish_row /
 *     png_error ×4（Invalid attempt / Not enough image data / Extra compressed data / Decompression error）
 *     另有 read_status_fn（经 +0x25c 间接调）
 *   谁调它：png_read_rows 3 处（0x2a7804 / 0x2a781c / 0x2a7836）+ png_read_image 0x2a786e；
 *     外部 0 个 blx —— 游戏从不直接按行读，一律走 png_read_image。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7488 0x2a77e0 png_read_row */

/* @0x2a7488 push.w {r4, r5, r6, r7, r8, r9, lr} —— push.w {r4-r9,lr}；帧 0x4c */
/* @0x2a748c mov r4, r0 —— r4 = png_ptr */
/* @0x2a748e ldr r7, [pc, #0x33c] —— r7 ← 字面量 0x000e8472 */
/* @0x2a7490 sub sp, #0x4c */
/* @0x2a7492 mov r8, r1 —— r8 = row（第 2 实参，可以为 NULL） */
/* @0x2a7494 mov r5, r2 —— r5 = dsp_row（第 3 实参，可以为 NULL） */
/* @0x2a7496 add r7, pc —— r7 += pc → 0x38f90c（名表基址） */
/* @0x2a7498 add r6, sp, #0x10 —— r6 = sp+0x10 */
/* @0x2a749a add.w r12, r7, #0x6c —— r12 = r7+0x6c = 0x38f978 */
/* @0x2a749e mov r3, r7 —— r3 = r7 */
/* @0x2a74a0 adds r7, #0x88 —— r7 += 0x88 → 0x38f994 */
/* @0x2a74a2 ldr r0, [r3, #5]! —— ldr r0,[r3,#5]! = 名 #1 "IDAT" 前 4 字节 */
/* @0x2a74a6 ldrb r3, [r3, #0x4] —— ldrb r3,[r3,#4] = 第 5 字节 */
/* @0x2a74a8 str r0, [sp, #0x8] */
/* @0x2a74aa strb.w r3, [sp, #0xc] —— strb.w r3,[sp,#0xc]：栈上得到可 memcmp 的 "IDAT" */
/* ---- 两张 7 项常量表铺到栈上（0x2a74ae..0x2a74c6）----
 *   sp+0x10 ← 0x38f978 = {ff,0f,ff,33,ff,55,ff}（值与上游 png_pass_dsp_mask 逐项相同）
 *   sp+0x2c ← 0x38f994 = {80,08,88,22,aa,55,ff}（值与上游 png_pass_mask     逐项相同）
 * 本件把这两张表存成 32 位宽（每项 4 字节），所以 ldr [sp,#0x10+4*pass] 直接取到掩码值本身，
 * 作为 png_combine_row 的第 3 实参。 */
/* @0x2a74ae ldm.w r12!, {r0, r1, r2, r3} —— ldm.w r12!,{r0-r3} */
/* @0x2a74b2 stm r6!, {r0, r1, r2, r3} —— stm r6!,{r0-r3} */
/* @0x2a74b4 ldm.w r12, {r0, r1, r2} */
/* @0x2a74b8 stm.w r6, {r0, r1, r2} —— stm.w r6,{r0,r1,r2}：sp+0x10 起 28 B = 7 个 32 位常量 = png_pass_dsp_mask */
/* @0x2a74bc add r6, sp, #0x2c —— r6 = sp+0x2c */
/* @0x2a74be ldm r7!, {r0, r1, r2, r3} —— ldm r7!,{r0-r3} */
/* @0x2a74c0 stm r6!, {r0, r1, r2, r3} —— stm r6!,{r0-r3} */
/* @0x2a74c2 ldm.w r7, {r0, r1, r2} */
/* @0x2a74c6 stm.w r6, {r0, r1, r2} —— stm.w r6,{r0,r1,r2}：sp+0x2c 起 28 B = png_pass_mask */
/* @0x2a74ca cmp r4, #0x0 —— png_ptr == NULL ? */
/* @0x2a74cc beq.w 0x2a77c6 <png_read_row+0x33e> —— → 0x2a77c6 返回 */
/* @0x2a74d0 ldr.w r3, [r4, #0x130] —— flags(+0x130) */
/* @0x2a74d4 lsls r3, r3, #0x19 —— lsls #0x19 → 测 bit6 (0x40 = 行缓冲已初始化) */
/* @0x2a74d6 bmi 0x2a74de <png_read_row+0x56> —— 置位 → 0x2a74de 跳过起缓冲 */
/* @0x2a74d8 mov r0, r4 —— r0 = png */
/* @0x2a74da bl 0x2ae494 <png_read_start_row> —— bl png_read_start_row(png) */
/* @0x2a74de ldrb.w r3, [r4, #0x1e7] —— interlaced(+0x1e7) */
/* @0x2a74e2 cmp r3, #0x0 —— interlaced == 0 ? */
/* @0x2a74e4 beq 0x2a759c <png_read_row+0x114> —— → 0x2a759c（非隔行主路径） */
/* @0x2a74e6 ldr.w r3, [r4, #0x134] —— transformations(+0x134) */
/* @0x2a74ea lsls r7, r3, #0x1e —— lsls #0x1e → 测 bit1 */
/* @0x2a74ec bpl 0x2a759c <png_read_row+0x114> —— 清 → 0x2a759c */
/* @0x2a74ee ldrb.w r2, [r4, #0x1e8] —— pass(+0x1e8) */
/* @0x2a74f2 ldr.w r3, [r4, #0x1a8] —— row_number(+0x1a8) */
/* @0x2a74f6 cmp r2, #0x5 —— pass > 5 ? */
/* @0x2a74f8 bhi 0x2a7598 <png_read_row+0x110> —— → 0x2a7598（pass 6 的 body） */
/* @0x2a74fa tbb [pc, r2] —— tbb [pc,r2]：6 项表 @0x2a74fe = 03 11 1d 29 35 41 */
/* @0x2a74fe asrs r3, r0, #0x4 —— 数据字节：tbb 表项 0/1（0x03,0x11 → pass0 = 0x2a7504，pass1 = 0x2a7520） */
/* @0x2a7500 cmp r1, #0x1d —— 数据字节：tbb 表项 2/3（0x1d,0x29 → pass2 = 0x2a7538，pass3 = 0x2a7550） */
/* @0x2a7502 asrs r5, r6 —— 数据字节：tbb 表项 4/5（0x35,0x41 → pass4 = 0x2a7568，pass5 = 0x2a7580） */
/* @0x2a7504 lsls r6, r3, #0x1d —— pass 0：测 row_number bit2 (0x4) */
/* @0x2a7506 beq 0x2a759c <png_read_row+0x114> —— bit2 == 0 → 0x2a759c 解码本行 */
/* @0x2a7508 cbz r5, 0x2a7514 <png_read_row+0x8c> —— dsp_row == NULL → 0x2a7514 */
/* @0x2a750a ldr r2, [sp, #0x10] —— r2 = dsp_mask[0] = 0xff */
/* @0x2a750c mov r0, r4 —— r0 = png */
/* @0x2a750e mov r1, r5 —— r1 = dsp_row */
/* @0x2a7510 bl 0x2adc30 <png_combine_row> —— bl png_combine_row(png, dsp_row, mask) */
/* @0x2a7514 mov r0, r4 —— r0 = png */
/* @0x2a7516 add sp, #0x4c */
/* @0x2a7518 pop.w {r4, r5, r6, r7, r8, r9, lr} —— pop.w {r4-r9,lr} */
/* @0x2a751c b.w 0x2ae25c <png_read_finish_row> —— b.w png_read_finish_row：跳过解码的出口（仍推进 row_number/pass） */
/* @0x2a7520 lsls r0, r3, #0x1d —— pass 1：测 row_number bit2 */
/* @0x2a7522 bne 0x2a752c <png_read_row+0xa4> —— bit2 置位 → 0x2a752c（不解码） */
/* @0x2a7524 ldr.w r3, [r4, #0x18c] —— r3 = [+0x18c]（阈值源，字段身份见 open 2） */
/* @0x2a7528 cmp r3, #0x4 —— （+0x18c vs 4） */
/* @0x2a752a bhi 0x2a759c <png_read_row+0x114> —— > 4 → 0x2a759c 解码本行；否则落到 0x2a752c 只合成 dsp_row */
/* @0x2a752c cmp r5, #0x0 —— dsp_row == NULL → 0x2a7514 */
/* @0x2a752e beq 0x2a7514 <png_read_row+0x8c> —— 否则合成 dsp_row */
/* @0x2a7530 mov r0, r4 —— r0 = png */
/* @0x2a7532 mov r1, r5 —— r1 = dsp_row */
/* @0x2a7534 ldr r2, [sp, #0x14] —— r2 = dsp_mask[1] = 0x0f */
/* @0x2a7536 b 0x2a7510 <png_read_row+0x88> —— → 0x2a7510 */
/* @0x2a7538 and r2, r3, #0x7 —— pass 2：(row_number & 7) */
/* @0x2a753c cmp r2, #0x4 —— cmp #4 */
/* @0x2a753e beq 0x2a759c <png_read_row+0x114> —— == 4 → 0x2a759c 解码（Adam7 pass 2 的行号） */
/* @0x2a7540 cmp r5, #0x0 —— dsp_row == NULL → 0x2a7514 */
/* @0x2a7542 beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7544 lsls r1, r3, #0x1d —— 测 row_number bit2 */
/* @0x2a7546 bpl 0x2a7514 <png_read_row+0x8c> —— 清 → 0x2a7514（不合成） */
/* @0x2a7548 mov r0, r4 —— r0 = png */
/* @0x2a754a mov r1, r5 —— r1 = dsp_row */
/* @0x2a754c ldr r2, [sp, #0x18] —— r2 = dsp_mask[2] = 0xff */
/* @0x2a754e b 0x2a7510 <png_read_row+0x88> —— → 0x2a7510 */
/* @0x2a7550 lsls r2, r3, #0x1e —— pass 3：测 row_number bit1 (0x2) */
/* @0x2a7552 bne 0x2a755c <png_read_row+0xd4> —— 置位 → 0x2a755c（不解码） */
/* @0x2a7554 ldr.w r3, [r4, #0x18c] —— r3 = [+0x18c] */
/* @0x2a7558 cmp r3, #0x2 —— （+0x18c vs 2） */
/* @0x2a755a bhi 0x2a759c <png_read_row+0x114> —— > 2 → 0x2a759c 解码；否则 0x2a755c */
/* @0x2a755c cmp r5, #0x0 —— dsp_row == NULL → 0x2a7514 */
/* @0x2a755e beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7560 mov r0, r4 —— r0 = png */
/* @0x2a7562 mov r1, r5 —— r1 = dsp_row */
/* @0x2a7564 ldr r2, [sp, #0x1c] —— r2 = dsp_mask[3] = 0x33 */
/* @0x2a7566 b 0x2a7510 <png_read_row+0x88> —— → 0x2a7510 */
/* @0x2a7568 and r2, r3, #0x3 —— pass 4：(row_number & 3) */
/* @0x2a756c cmp r2, #0x2 —— cmp #2 */
/* @0x2a756e beq 0x2a759c <png_read_row+0x114> —— == 2 → 0x2a759c 解码 */
/* @0x2a7570 cmp r5, #0x0 —— dsp_row == NULL → 0x2a7514 */
/* @0x2a7572 beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7574 lsls r3, r3, #0x1e —— 测 row_number bit1 */
/* @0x2a7576 bpl 0x2a7514 <png_read_row+0x8c> —— 清 → 0x2a7514 */
/* @0x2a7578 mov r0, r4 —— r0 = png */
/* @0x2a757a mov r1, r5 —— r1 = dsp_row */
/* @0x2a757c ldr r2, [sp, #0x20] —— r2 = dsp_mask[4] = 0xff */
/* @0x2a757e b 0x2a7510 <png_read_row+0x88> —— → 0x2a7510 */
/* @0x2a7580 lsls r7, r3, #0x1f —— pass 5：测 row_number bit0 (0x1) */
/* @0x2a7582 bmi 0x2a758c <png_read_row+0x104> —— 置位 → 0x2a758c（不解码） */
/* @0x2a7584 ldr.w r3, [r4, #0x18c] —— r3 = [+0x18c] */
/* @0x2a7588 cmp r3, #0x1 —— （+0x18c vs 1） */
/* @0x2a758a bhi 0x2a759c <png_read_row+0x114> —— > 1 → 0x2a759c 解码；否则 0x2a758c */
/* @0x2a758c cmp r5, #0x0 —— dsp_row == NULL → 0x2a7514 */
/* @0x2a758e beq 0x2a7514 <png_read_row+0x8c> */
/* @0x2a7590 mov r0, r4 —— r0 = png */
/* @0x2a7592 mov r1, r5 —— r1 = dsp_row */
/* @0x2a7594 ldr r2, [sp, #0x24] —— r2 = dsp_mask[5] = 0x55 */
/* @0x2a7596 b 0x2a7510 <png_read_row+0x88> —— → 0x2a7510 */
/* @0x2a7598 lsls r6, r3, #0x1f —— pass 6：测 row_number bit0 */
/* @0x2a759a bpl 0x2a7514 <png_read_row+0x8c> —— 清 → 0x2a7514；置位则落到 0x2a759c 解码 */
/* @0x2a759c ldr.w r3, [r4, #0x12c] —— mode(+0x12c) */
/* @0x2a75a0 lsls r0, r3, #0x1d —— lsls #0x1d → 测 bit2 (0x4 = 有 IDAT) */
/* @0x2a75a2 bmi 0x2a75ae <png_read_row+0x126> —— 置位 → 0x2a75ae */
/* @0x2a75a4 ldr r1, [pc, #0x228] —— r1 = "Invalid attempt to read row data"（0x38c867） */
/* @0x2a75a6 mov r0, r4 */
/* @0x2a75a8 add r1, pc —— r1 += pc */
/* @0x2a75aa bl 0x2a642c <png_error> —— bl png_error */
/* @0x2a75ae ldr.w r3, [r4, #0x1b0] —— r3 = row_buf(+0x1b0) */
/* @0x2a75b2 ldr.w r2, [r4, #0x1a4] —— r2 = usr_width(+0x1a4) */
/* @0x2a75b6 str.w r3, [r4, #0x144] —— zstream.next_out(+0x144) = row_buf */
/* @0x2a75ba ldrb.w r3, [r4, #0x1ed] —— pixel_depth(+0x1ed) */
/* @0x2a75be cmp r3, #0x7 —— cmp #7 */
/* @0x2a75c0 bls 0x2a75c8 <png_read_row+0x140> —— <= 7 → 0x2a75c8（不足一字节按位算） */
/* @0x2a75c2 lsrs r3, r3, #0x3 —— lsrs #3 */
/* @0x2a75c4 muls r3, r2, r3 */
/* @0x2a75c6 b 0x2a75ce <png_read_row+0x146> —— → 0x2a75ce */
/* @0x2a75c8 muls r3, r2, r3 */
/* @0x2a75ca adds r3, #0x7 —— +7 */
/* @0x2a75cc lsrs r3, r3, #0x3 —— >>3：rowbytes = PNG_ROWBYTES(pixel_depth, usr_width) */
/* @0x2a75ce add r6, sp, #0x8 —— r6 = sp+8（栈上的 "IDAT"） */
/* @0x2a75d0 adds r3, #0x1 —— +1（滤波字节） */
/* @0x2a75d2 str.w r3, [r4, #0x148] —— zstream.avail_out(+0x148) = rowbytes + 1 */
/* @0x2a75d6 ldr.w r3, [r4, #0x13c] —— zstream.avail_in(+0x13c) */
/* @0x2a75da cbnz r3, 0x2a7646 <png_read_row+0x1be> —— 非 0 → 0x2a7646 继续 inflate */
/* @0x2a75dc ldr.w r9, [pc, #0x1f4] —— r9 = "Not enough image data"（0x38c888） */
/* @0x2a75e0 add r9, pc —— r9 += pc */
/* @0x2a75e2 add.w r7, r4, #0x1e0 —— r7 = png+0x1e0（chunk_name） */
/* @0x2a75e6 ldr.w r3, [r4, #0x1d0] —— idat_size(+0x1d0) */
/* @0x2a75ea cbnz r3, 0x2a7616 <png_read_row+0x18e> —— 非 0 → 0x2a7616 去取压缩块 */
/* @0x2a75ec mov r1, r3 —— r1 = 0 */
/* @0x2a75ee mov r0, r4 —— r0 = png */
/* @0x2a75f0 bl 0x2abc94 <png_crc_finish> —— bl png_crc_finish(png, 0)：结掉上一块 IDAT */
/* @0x2a75f4 mov r0, r4 */
/* @0x2a75f6 bl 0x2adbc4 <png_read_chunk_header> —— bl png_read_chunk_header(png) → 新块长度 */
/* @0x2a75fa mov r1, r6 —— r1 = r6（"IDAT"） */
/* @0x2a75fc movs r2, #0x4 —— r2 = 4 */
/* @0x2a75fe str.w r0, [r4, #0x1d0] —— idat_size = 新块长度 */
/* @0x2a7602 mov r0, r7 —— r0 = &chunk_name */
/* @0x2a7604 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：IDAT 比较（read_row 唯一一处）：新 chunk 不是 IDAT → "Not enough image data" */
/* @0x2a7608 cmp r0, #0x0 —— 是 IDAT → 0x2a75e6 重查 idat_size */
/* @0x2a760a beq 0x2a75e6 <png_read_row+0x15e> —— 否则报错：像素还没读完就没有 IDAT 了 */
/* @0x2a760c mov r0, r4 —— r0 = png */
/* @0x2a760e mov r1, r9 —— r1 = r9 */
/* @0x2a7610 bl 0x2a642c <png_error> —— bl png_error("Not enough image data") */
/* @0x2a7614 b 0x2a75e2 <png_read_row+0x15a> —— → 0x2a75e2（png_error 名义上不返回；这里是编译器留的接续点） */
/* @0x2a7616 ldr.w r2, [r4, #0x174] —— r2 = zbuf_size(+0x174) */
/* @0x2a761a mov r0, r4 —— r0 = png */
/* @0x2a761c ldr.w r1, [r4, #0x170] —— r1 = zbuf(+0x170) */
/* @0x2a7620 cmp r2, r3 —— cmp zbuf_size, idat_size */
/* @0x2a7622 str.w r2, [r4, #0x13c] —— zstream.avail_in = zbuf_size */
/* @0x2a7626 str.w r1, [r4, #0x138] —— zstream.next_in = zbuf */
/* @0x2a762a it hi */
/* @0x2a762c strhi.w r3, [r4, #0x13c] —— 超了就把 avail_in 截成 idat_size */
/* @0x2a7630 ldr.w r2, [r4, #0x13c] —— r2 = avail_in */
/* @0x2a7634 bl 0x2abc0c <png_crc_read> —— bl png_crc_read(png, next_in, avail_in)：走 png_read_data 漏斗 */
/* @0x2a7638 ldr.w r2, [r4, #0x1d0] —— r2 = idat_size */
/* @0x2a763c ldr.w r3, [r4, #0x13c] —— r3 = avail_in */
/* @0x2a7640 subs r3, r2, r3 —— subs */
/* @0x2a7642 str.w r3, [r4, #0x1d0] —— idat_size -= avail_in */
/* @0x2a7646 add.w r0, r4, #0x138 —— r0 = &png->zstream(+0x138) */
/* @0x2a764a movs r1, #0x1 —— r1 = 1（flush 常量） */
/* @0x2a764c blx 0xb69dc <inflate@plt> —— blx inflate */
/* @0x2a7650 cmp r0, #0x1 —— cmp #1 */
/* @0x2a7652 bne 0x2a768a <png_read_row+0x202> —— != 1 → 0x2a768a */
/* @0x2a7654 ldr.w r3, [r4, #0x148] —— Z_STREAM_END：avail_out(+0x148) */
/* @0x2a7658 cbnz r3, 0x2a7666 <png_read_row+0x1de> —— 非 0 → 0x2a7666 报 "Extra compressed data" */
/* @0x2a765a ldr.w r3, [r4, #0x13c] —— avail_in */
/* @0x2a765e cbnz r3, 0x2a7666 <png_read_row+0x1de> —— 非 0 → 0x2a7666 */
/* @0x2a7660 ldr.w r3, [r4, #0x1d0] —— idat_size */
/* @0x2a7664 cbz r3, 0x2a7670 <png_read_row+0x1e8> —— == 0 → 0x2a7670（流干净结束） */
/* @0x2a7666 ldr r1, [pc, #0x170] —— r1 = "Extra compressed data"（0x38c89e） */
/* @0x2a7668 mov r0, r4 */
/* @0x2a766a add r1, pc */
/* @0x2a766c bl 0x2a642c <png_error> —— bl png_error：三个条件任一不满足即错误 */
/* @0x2a7670 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7674 orr r3, r3, #0x8 —— mode |= 0x8（bit3 = 已过 IDAT） */
/* @0x2a7678 str.w r3, [r4, #0x12c] */
/* @0x2a767c ldr.w r3, [r4, #0x130] */
/* @0x2a7680 orr r3, r3, #0x20 —— flags |= 0x20（zlib 流结束标志） */
/* @0x2a7684 str.w r3, [r4, #0x130] */
/* @0x2a7688 b 0x2a76a8 <png_read_row+0x220> —— → 0x2a76a8 */
/* @0x2a768a cbz r0, 0x2a76a0 <png_read_row+0x218> —— r0 == 0（Z_OK）→ 0x2a76a0 */
/* @0x2a768c ldr.w r3, [r4, #0x150] —— zstream.msg(+0x150) */
/* @0x2a7690 cbnz r3, 0x2a7698 <png_read_row+0x210> —— 非空 → 0x2a7698 */
/* @0x2a7692 ldr r1, [pc, #0x148] —— r1 = "Decompression error"（0x38c853） */
/* @0x2a7694 add r1, pc */
/* @0x2a7696 b 0x2a769a <png_read_row+0x212> —— → 0x2a769a */
/* @0x2a7698 mov r1, r3 —— r1 = zlib 自己的 msg */
/* @0x2a769a mov r0, r4 */
/* @0x2a769c bl 0x2a642c <png_error> —— bl png_error */
/* @0x2a76a0 ldr.w r3, [r4, #0x148] —— avail_out */
/* @0x2a76a4 cmp r3, #0x0 —— 非 0 → 0x2a75d6（这一行还没填满，继续喂） */
/* @0x2a76a6 bne 0x2a75d6 <png_read_row+0x14e> */
/* @0x2a76a8 ldrb.w r3, [r4, #0x1ea] —— color_type(+0x1ea) */
/* @0x2a76ac ldr.w r2, [r4, #0x1a4] —— usr_width(+0x1a4) */
/* @0x2a76b0 strb.w r3, [r4, #0x1cc] —— row_info.color_type(+0x1cc) */
/* @0x2a76b4 ldrb.w r3, [r4, #0x1ee] —— channels(+0x1ee) */
/* @0x2a76b8 str.w r2, [r4, #0x1c4] —— row_info.width(+0x1c4) */
/* @0x2a76bc strb.w r3, [r4, #0x1ce] —— row_info.channels(+0x1ce) */
/* @0x2a76c0 ldrb.w r3, [r4, #0x1eb] —— bit_depth(+0x1eb) */
/* @0x2a76c4 strb.w r3, [r4, #0x1cd] —— row_info.bit_depth(+0x1cd) */
/* @0x2a76c8 ldrb.w r3, [r4, #0x1ed] —— pixel_depth(+0x1ed) */
/* @0x2a76cc cmp r3, #0x7 —— cmp #7 */
/* @0x2a76ce strb.w r3, [r4, #0x1cf] —— row_info.pixel_depth(+0x1cf) */
/* @0x2a76d2 bls 0x2a76da <png_read_row+0x252> —— <= 7 → 0x2a76da */
/* @0x2a76d4 lsrs r3, r3, #0x3 —— lsrs #3 */
/* @0x2a76d6 muls r2, r3, r2 —— muls */
/* @0x2a76d8 b 0x2a76e0 <png_read_row+0x258> —— → 0x2a76e0 */
/* @0x2a76da muls r2, r3, r2 —— muls */
/* @0x2a76dc adds r2, #0x7 —— +7 */
/* @0x2a76de lsrs r2, r2, #0x3 —— >>3 */
/* @0x2a76e0 str.w r2, [r4, #0x1c8] —— row_info.rowbytes(+0x1c8) */
/* @0x2a76e4 ldr.w r2, [r4, #0x1b0] —— r2 = row_buf(+0x1b0) */
/* @0x2a76e8 ldrb r1, [r2] —— 滤波类型 = row_buf[0] */
/* @0x2a76ea cbz r1, 0x2a7700 <png_read_row+0x278> —— 0（None）→ 0x2a7700 跳过反滤波 */
/* @0x2a76ec ldr.w r3, [r4, #0x1ac] —— r3 = prev_row(+0x1ac) */
/* @0x2a76f0 mov r0, r4 —— r0 = png */
/* @0x2a76f2 str r1, [sp] —— 第 5 实参（栈） = 滤波类型 */
/* @0x2a76f4 adds r2, #0x1 —— r2 = row_buf + 1 */
/* @0x2a76f6 add.w r1, r4, #0x1c4 —— r1 = &row_info(+0x1c4) */
/* @0x2a76fa adds r3, #0x1 —— r3 = prev_row + 1 */
/* @0x2a76fc bl 0x2ae148 <png_read_filter_row> —— bl png_read_filter_row(png, &row_info, row_buf+1, prev_row+1, filter) */
/* @0x2a7700 ldr.w r2, [r4, #0x19c] —— r2 = rowbytes(+0x19c) */
/* @0x2a7704 ldr.w r1, [r4, #0x1b0] —— r1 = row_buf */
/* @0x2a7708 ldr.w r0, [r4, #0x1ac] —— r0 = prev_row */
/* @0x2a770c adds r2, #0x1 —— +1（含滤波字节） */
/* @0x2a770e blx 0xb65bc <memcpy@plt> —— memcpy(prev_row, row_buf, rowbytes+1)：本行成为下一行的 prev */
/* @0x2a7712 ldr.w r3, [r4, #0x2dc] —— 副变换字(+0x2dc) */
/* @0x2a7716 lsls r1, r3, #0x1d —— lsls #0x1d → 测 bit2 */
/* @0x2a7718 bpl 0x2a7730 <png_read_row+0x2a8> —— 清 → 0x2a7730 */
/* @0x2a771a ldrb.w r3, [r4, #0x2e4] —— 字节 +0x2e4 */
/* @0x2a771e cmp r3, #0x40 —— != 0x40 → 0x2a7730 */
/* @0x2a7720 bne 0x2a7730 <png_read_row+0x2a8> */
/* @0x2a7722 ldr.w r1, [r4, #0x1b0] —— r1 = row_buf + 1 */
/* @0x2a7726 add.w r0, r4, #0x1c4 —— r0 = &row_info */
/* @0x2a772a adds r1, #0x1 —— +1 */
/* @0x2a772c bl 0x2ab9f8 <png_do_read_intrapixel> —— bl png_do_read_intrapixel(png, &row_info, row_buf+1) */
/* @0x2a7730 ldr.w r3, [r4, #0x134] —— transformations(+0x134) */
/* @0x2a7734 cbnz r3, 0x2a773e <png_read_row+0x2b6> —— 非 0 → 0x2a773e */
/* @0x2a7736 ldr.w r3, [r4, #0x130] —— flags */
/* @0x2a773a lsls r2, r3, #0x9 —— lsls #9 → 测 bit22 (0x400000) */
/* @0x2a773c bpl 0x2a7744 <png_read_row+0x2bc> —— 清 → 0x2a7744 */
/* @0x2a773e mov r0, r4 —— r0 = png */
/* @0x2a7740 bl 0x2aa92c <png_do_read_transformations> —— bl png_do_read_transformations(png) */
/* @0x2a7744 ldrb.w r3, [r4, #0x1e7] —— interlaced(+0x1e7) */
/* @0x2a7748 cbz r3, 0x2a7792 <png_read_row+0x30a> —— == 0 → 0x2a7792（非隔行） */
/* @0x2a774a ldr.w r3, [r4, #0x134] —— transformations */
/* @0x2a774e lsls r3, r3, #0x1e —— 测 bit1 */
/* @0x2a7750 bpl 0x2a7792 <png_read_row+0x30a> —— 清 → 0x2a7792 */
/* @0x2a7752 ldrb.w r3, [r4, #0x1e8] —— pass */
/* @0x2a7756 cmp r3, #0x5 —— > 5 → 0x2a7760（pass 6 不做 interlace 展开） */
/* @0x2a7758 bhi 0x2a7760 <png_read_row+0x2d8> */
/* @0x2a775a mov r0, r4 —— bl png_do_read_interlace(png) */
/* @0x2a775c bl 0x2ade1c <png_do_read_interlace> */
/* @0x2a7760 cbz r5, 0x2a7778 <png_read_row+0x2f0> —— dsp_row == NULL → 0x2a7778 */
/* @0x2a7762 ldrb.w r3, [r4, #0x1e8] —— r3 = pass */
/* @0x2a7766 add r2, sp, #0x48 —— r2 = sp+0x48 */
/* @0x2a7768 mov r0, r4 */
/* @0x2a776a mov r1, r5 —— r1 = dsp_row */
/* @0x2a776c add.w r3, r2, r3, lsl #2 —— r3 = sp+0x48 + 4*pass */
/* @0x2a7770 ldr r2, [r3, #-56] —— r2 = [sp+0x10+4*pass] = png_pass_dsp_mask[pass] */
/* @0x2a7774 bl 0x2adc30 <png_combine_row> —— bl png_combine_row(png, dsp_row, dsp_mask[pass]) */
/* @0x2a7778 cmp.w r8, #0x0 —— row == NULL → 0x2a77ae */
/* @0x2a777c beq 0x2a77ae <png_read_row+0x326> */
/* @0x2a777e ldrb.w r3, [r4, #0x1e8] —— r3 = pass */
/* @0x2a7782 add r0, sp, #0x48 —— r0 = sp+0x48 */
/* @0x2a7784 mov r1, r8 —— r1 = row */
/* @0x2a7786 add.w r3, r0, r3, lsl #2 —— r3 = sp+0x48 + 4*pass */
/* @0x2a778a mov r0, r4 —— r0 = png */
/* @0x2a778c ldr r2, [r3, #-28] —— r2 = [sp+0x2c+4*pass] = png_pass_mask[pass] */
/* @0x2a7790 b 0x2a77aa <png_read_row+0x322> —— → 0x2a77aa */
/* @0x2a7792 cmp.w r8, #0x0 —— row == NULL → 0x2a77a2 */
/* @0x2a7796 beq 0x2a77a2 <png_read_row+0x31a> */
/* @0x2a7798 mov r0, r4 —— r0 = png */
/* @0x2a779a mov r1, r8 —— r1 = row */
/* @0x2a779c movs r2, #0xff —— r2 = 0xff */
/* @0x2a779e bl 0x2adc30 <png_combine_row> —— bl png_combine_row(png, row, 0xff) */
/* @0x2a77a2 cbz r5, 0x2a77ae <png_read_row+0x326> —— dsp_row == NULL → 0x2a77ae */
/* @0x2a77a4 mov r0, r4 —— r0 = png */
/* @0x2a77a6 mov r1, r5 —— r1 = dsp_row */
/* @0x2a77a8 movs r2, #0xff —— r2 = 0xff */
/* @0x2a77aa bl 0x2adc30 <png_combine_row> —— bl png_combine_row(png, dsp_row, 0xff) */
/* @0x2a77ae mov r0, r4 —— bl png_read_finish_row(png) */
/* @0x2a77b0 bl 0x2ae25c <png_read_finish_row> */
/* @0x2a77b4 ldr.w r3, [r4, #0x25c] —— read_status_fn(+0x25c) */
/* @0x2a77b8 cbz r3, 0x2a77c6 <png_read_row+0x33e> —— 空 → 0x2a77c6 返回 */
/* @0x2a77ba mov r0, r4 —— r0 = png */
/* @0x2a77bc ldr.w r1, [r4, #0x1a8] —— r1 = row_number(+0x1a8) */
/* @0x2a77c0 ldrb.w r2, [r4, #0x1e8] —— r2 = pass（字节 +0x1e8） */
/* @0x2a77c4 blx r3 —— blx r3：用户状态回调(png, row_number, pass) */
/* @0x2a77c6 add sp, #0x4c */
/* @0x2a77c8 pop.w {r4, r5, r6, r7, r8, r9, pc} —— pop.w {r4-r9,pc} */
/* @0x2a77cc strh r2, [r6, #0x22] —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77ce movs r6, r1 —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77d0 strh r3, [r7, r2] —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77d2 movs r6, r1 —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77d4 strh r4, [r4, r2] —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77d6 movs r6, r1 —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77d8 strh r0, [r6, r0] —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77da movs r6, r1 —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77dc str r3, [r7, r6] —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */
/* @0x2a77de movs r6, r1 —— 数据字：literal pool（0x2a77cc = 0x000e8472 名表基址；其后 = Invalid attempt to read row data / Not enough image data / Extra compressed data / Decompression error 四串偏移） */

/* ════════════════════════════════════════════════════════════════════
 * 节 4/9  png_read_image（0x2a7840 .. 0x2a787c，60 B，23 条）
 *   契约：void png_read_image(png_structp png, png_bytepp image)
 *   pass 数 = png_set_interlace_handling(png)；行数 = [+0x190]（同时写进 [+0x194] 作副本）。
 *   双层循环：pass 0..n-1 × row 0..h-1，每行 png_read_row(png, image[row], NULL)。
 *   第 3 实参恒为 0（0x2a786a）⇒ 本函数**从不生成显示行**，隔行合成只落在 image[] 上。
 *   谁调它：外部 3 个 blx（0x1897e8 / 0x18a0cc / 0x290044）+ png_read_png 0x2a7f92
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7840 0x2a787c png_read_image */

/* @0x2a7840 push.w {r3, r4, r5, r6, r7, r8, r9, lr} —— push.w {r3-r9,lr} */
/* @0x2a7844 mov r8, r1 —— r8 = image（png_bytepp 行指针数组） */
/* @0x2a7846 mov r5, r0 —— r5 = png_ptr */
/* @0x2a7848 cbz r0, 0x2a7878 <png_read_image+0x38> —— png_ptr == NULL ? → 0x2a7878 返回 */
/* @0x2a784a bl 0x2af7b2 <png_set_interlace_handling> —— bl png_set_interlace_handling(png) → 返回 pass 数 */
/* @0x2a784e ldr.w r7, [r5, #0x190] —— r7 = [+0x190]（行数源） */
/* @0x2a7852 movs r6, #0x0 —— r6 = 0（pass 计数） */
/* @0x2a7854 str.w r7, [r5, #0x194] —— [+0x194] = r7（行数副本） */
/* @0x2a7858 mov r9, r0 —— r9 = pass 数 */
/* @0x2a785a cmp r6, r9 */
/* @0x2a785c bge 0x2a7878 <png_read_image+0x38> —— >= → 0x2a7878 返回 */
/* @0x2a785e movs r4, #0x0 —— r4 = 0（行号） */
/* @0x2a7860 cmp r4, r7 */
/* @0x2a7862 beq 0x2a7874 <png_read_image+0x34> —— == → 0x2a7874（下一个 pass） */
/* @0x2a7864 ldr.w r1, [r8, r4, lsl #2] —— r1 = image[y] */
/* @0x2a7868 mov r0, r5 —— r0 = png */
/* @0x2a786a movs r2, #0x0 —— r2 = 0：dsp_row 恒为 NULL（本函数从不填显示行） */
/* @0x2a786c adds r4, #0x1 —— r4++ */
/* @0x2a786e bl 0x2a7488 <png_read_row> —— bl png_read_row(png, image[y], NULL) */
/* @0x2a7872 b 0x2a7860 <png_read_image+0x20> —— → 0x2a7860 */
/* @0x2a7874 adds r6, #0x1 —— r6++ */
/* @0x2a7876 b 0x2a785a <png_read_image+0x1a> —— → 0x2a785a */
/* @0x2a7878 pop.w {r3, r4, r5, r6, r7, r8, r9, pc} —— pop.w {r3-r9,pc} */

/* ════════════════════════════════════════════════════════════════════
 * 节 5/9  png_read_end（0x2a787c .. 0x2a7c64，1000 B，381 条）
 *   契约：void png_read_end(png_structp png, png_infop info)
 *   进门先 png_crc_finish(png, 0) 结掉最后一个 IDAT 的 CRC，然后与 read_info **同一张** 21 名表、
 *   同一种「每轮重铺 + 线性 memcmp」的循环，读到 IEND（mode bit4 置位）为止。
 *
 *   与 read_info 的三处结构差异（逐条有锚点）：
 *     ① 没有 IDAT 前置守卫，也没有 IDAT→handler：IDAT 只做 "Too many IDATs found" 守卫
 *        （length != 0 或 mode bit13 置位 → png_error；否则 png_crc_finish 吃掉空块）；
 *     ② 循环尾在 0x2a7c46（read_info 是 0x2a701c 前的返回点），出口判据是 mode bit4(0x10)；
 *     ③ 进来了 IHDR 也照分派（0x2a79f2 png_handle_IHDR）—— IHDR 出现在 IDAT 之后时由 handler 自己判错。
 *   帧：push.w 9 寄存器 + sub sp,#0xb4，名槽布局与 read_info 相同（r9=槽0 IHDR、r11=槽1 IDAT、r10=槽3 PLTE）。
 *   调了谁：png_crc_finish ×2 / png_read_chunk_header / png_handle_as_unknown / memcmp@plt ×23 /
 *     20 个 png_handle_* / png_handle_unknown ×2 / png_error ×2（都指向 "Too many IDATs found"）
 *   谁调它：只有 png_read_png 的尾跳（0x2a7fa6）；外部 0 个 blx —— 游戏不走这条路。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a787c 0x2a7c64 png_read_end */

/* @0x2a787c push.w {r4, r5, r6, r7, r8, r9, r10, r11, lr} —— push.w {r4-r11,lr}；帧 0xb4 */
/* @0x2a7880 mov r7, r1 —— r7 = info_ptr */
/* @0x2a7882 sub sp, #0xb4 */
/* @0x2a7884 mov r4, r0 —— r4 = png_ptr */
/* @0x2a7886 cmp r0, #0x0 —— png_ptr == NULL ? → 0x2a7c50 返回 */
/* @0x2a7888 beq.w 0x2a7c50 <png_read_end+0x3d4> */
/* @0x2a788c ldr.w r8, [pc, #0x3c8] —— r8 ← 字面量 0x000e806e */
/* @0x2a7890 movs r1, #0x0 —— r1 = 0 */
/* @0x2a7892 bl 0x2abc94 <png_crc_finish> —— bl png_crc_finish(png, 0)：进门先结掉最后一个 IDAT 的 CRC */
/* @0x2a7896 add.w r9, sp, #0x8 —— r9 = sp+8（名表槽 0） */
/* @0x2a789a add r8, pc —— r8 += pc → 0x38f90c（与 read_info 同一个名表） */
/* @0x2a789c ldrb.w r3, [r8, #0x4] —— ldrb r3,[r8,#4] */
/* @0x2a78a0 strb.w r3, [sp, #0x7] —— 第 5 字节暂存 sp+7 */
/* @0x2a78a4 ldrb.w r3, [sp, #0x7] —— 循环头：写回槽 0 第 5 字节 */
/* @0x2a78a8 add.w r6, r4, #0x1e0 —— r6 = png+0x1e0（chunk_name） */
/* @0x2a78ac ldr.w r0, [r8] —— r0 = [r8] */
/* @0x2a78b0 add.w r11, sp, #0x10 —— r11 = sp+0x10（槽 1 = IDAT） */
/* @0x2a78b4 add.w r10, sp, #0x20 —— r10 = sp+0x20（槽 3 = PLTE） */
/* ---- 与 read_info 同一张表、同一种铺法（0x2a78b8..0x2a79d2，100 条）----
 * 槽位布局与节 1 完全一致（sp+8 IHDR / sp+0x10 IDAT / sp+0x20 PLTE ...），源同为 0x38f90c。 */
/* @0x2a78b8 strb.w r3, [r9, #0x4] —— 槽 0 第 5 字节落位 */
/* @0x2a78bc mov r3, r8 */
/* @0x2a78be str.w r0, [r9] */
/* @0x2a78c2 ldr r0, [r3, #5]! */
/* @0x2a78c6 ldrb r3, [r3, #0x4] */
/* @0x2a78c8 str r0, [sp, #0x10] */
/* @0x2a78ca strb.w r3, [sp, #0x14] */
/* @0x2a78ce mov r3, r8 */
/* @0x2a78d0 ldr r0, [r3, #10]! */
/* @0x2a78d4 ldrb r3, [r3, #0x4] */
/* @0x2a78d6 str r0, [sp, #0x18] */
/* @0x2a78d8 strb.w r3, [sp, #0x1c] */
/* @0x2a78dc mov r3, r8 */
/* @0x2a78de ldr r0, [r3, #15]! */
/* @0x2a78e2 ldrb r3, [r3, #0x4] */
/* @0x2a78e4 str r0, [sp, #0x20] */
/* @0x2a78e6 strb.w r3, [sp, #0x24] */
/* @0x2a78ea mov r3, r8 */
/* @0x2a78ec ldr r0, [r3, #20]! */
/* @0x2a78f0 ldrb r3, [r3, #0x4] */
/* @0x2a78f2 str r0, [sp, #0x28] */
/* @0x2a78f4 strb.w r3, [sp, #0x2c] */
/* @0x2a78f8 mov r3, r8 */
/* @0x2a78fa ldr r0, [r3, #25]! */
/* @0x2a78fe ldrb r3, [r3, #0x4] */
/* @0x2a7900 str r0, [sp, #0x30] */
/* @0x2a7902 strb.w r3, [sp, #0x34] */
/* @0x2a7906 mov r3, r8 */
/* @0x2a7908 ldr r0, [r3, #30]! */
/* @0x2a790c ldrb r3, [r3, #0x4] */
/* @0x2a790e str r0, [sp, #0x38] */
/* @0x2a7910 strb.w r3, [sp, #0x3c] */
/* @0x2a7914 mov r3, r8 */
/* @0x2a7916 ldr r0, [r3, #35]! */
/* @0x2a791a ldrb r3, [r3, #0x4] */
/* @0x2a791c str r0, [sp, #0x40] */
/* @0x2a791e strb.w r3, [sp, #0x44] */
/* @0x2a7922 mov r3, r8 */
/* @0x2a7924 ldr r0, [r3, #40]! */
/* @0x2a7928 str r0, [sp, #0x48] */
/* @0x2a792a ldrb r3, [r3, #0x4] */
/* @0x2a792c strb.w r3, [sp, #0x4c] */
/* @0x2a7930 mov r3, r8 */
/* @0x2a7932 ldr r0, [r3, #45]! */
/* @0x2a7936 ldrb r3, [r3, #0x4] */
/* @0x2a7938 str r0, [sp, #0x50] */
/* @0x2a793a strb.w r3, [sp, #0x54] */
/* @0x2a793e mov r3, r8 */
/* @0x2a7940 ldr r0, [r3, #50]! */
/* @0x2a7944 ldrb r3, [r3, #0x4] */
/* @0x2a7946 str r0, [sp, #0x58] */
/* @0x2a7948 strb.w r3, [sp, #0x5c] */
/* @0x2a794c mov r3, r8 */
/* @0x2a794e ldr r0, [r3, #55]! */
/* @0x2a7952 ldrb r3, [r3, #0x4] */
/* @0x2a7954 str r0, [sp, #0x60] */
/* @0x2a7956 strb.w r3, [sp, #0x64] */
/* @0x2a795a mov r3, r8 */
/* @0x2a795c ldr r0, [r3, #60]! */
/* @0x2a7960 ldrb r3, [r3, #0x4] */
/* @0x2a7962 str r0, [sp, #0x68] */
/* @0x2a7964 strb.w r3, [sp, #0x6c] */
/* @0x2a7968 mov r3, r8 */
/* @0x2a796a ldr r0, [r3, #65]! */
/* @0x2a796e ldrb r3, [r3, #0x4] */
/* @0x2a7970 str r0, [sp, #0x70] */
/* @0x2a7972 strb.w r3, [sp, #0x74] */
/* @0x2a7976 mov r3, r8 */
/* @0x2a7978 ldr r0, [r3, #70]! */
/* @0x2a797c ldrb r3, [r3, #0x4] */
/* @0x2a797e str r0, [sp, #0x78] */
/* @0x2a7980 strb.w r3, [sp, #0x7c] */
/* @0x2a7984 mov r3, r8 */
/* @0x2a7986 ldr r0, [r3, #75]! */
/* @0x2a798a ldrb r3, [r3, #0x4] */
/* @0x2a798c str r0, [sp, #0x80] */
/* @0x2a798e strb.w r3, [sp, #0x84] */
/* @0x2a7992 mov r3, r8 */
/* @0x2a7994 ldr r0, [r3, #80]! */
/* @0x2a7998 ldrb r3, [r3, #0x4] */
/* @0x2a799a str r0, [sp, #0x88] */
/* @0x2a799c strb.w r3, [sp, #0x8c] */
/* @0x2a79a0 mov r3, r8 */
/* @0x2a79a2 ldr r0, [r3, #85]! */
/* @0x2a79a6 ldrb r3, [r3, #0x4] */
/* @0x2a79a8 str r0, [sp, #0x90] */
/* @0x2a79aa strb.w r3, [sp, #0x94] */
/* @0x2a79ae mov r3, r8 */
/* @0x2a79b0 ldr r0, [r3, #90]! */
/* @0x2a79b4 ldrb r3, [r3, #0x4] */
/* @0x2a79b6 str r0, [sp, #0x98] */
/* @0x2a79b8 strb.w r3, [sp, #0x9c] */
/* @0x2a79bc mov r3, r8 */
/* @0x2a79be ldr r0, [r3, #95]! */
/* @0x2a79c2 ldrb r3, [r3, #0x4] */
/* @0x2a79c4 str r0, [sp, #0xa0] */
/* @0x2a79c6 strb.w r3, [sp, #0xa4] */
/* @0x2a79ca mov r3, r8 */
/* @0x2a79cc ldr r0, [r3, #100]! */
/* @0x2a79d0 ldrb r3, [r3, #0x4] */
/* @0x2a79d2 str r0, [sp, #0xa8] */
/* @0x2a79d4 mov r0, r4 */
/* @0x2a79d6 strb.w r3, [sp, #0xac] */
/* @0x2a79da bl 0x2adbc4 <png_read_chunk_header> —— bl png_read_chunk_header(png) */
/* @0x2a79de mov r1, r9 —— r1 = r9（槽 0） */
/* @0x2a79e0 movs r2, #0x4 —— r2 = 4 */
/* @0x2a79e2 mov r5, r0 —— r5 = length */
/* @0x2a79e4 mov r0, r6 —— r0 = &chunk_name */
/* @0x2a79e6 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IHDR", 4)：IHDR 比较（read_end 也分派 IHDR） */
/* @0x2a79ea cbnz r0, 0x2a79f8 <png_read_end+0x17c> —— 不相等 → 0x2a79f8 */
/* @0x2a79ec mov r0, r4 —— r0 = png */
/* @0x2a79ee mov r1, r7 —— r1 = info */
/* @0x2a79f0 mov r2, r5 —— r2 = length */
/* @0x2a79f2 bl 0x2abe50 <png_handle_IHDR> —— bl png_handle_IHDR */
/* @0x2a79f6 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a79f8 mov r0, r6 —— r0 = &chunk_name */
/* @0x2a79fa add r1, sp, #0x18 —— r1 = sp+0x18（槽 2） */
/* @0x2a79fc movs r2, #0x4 */
/* @0x2a79fe blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IEND", 4)：IEND 比较 */
/* @0x2a7a02 cbnz r0, 0x2a7a10 <png_read_end+0x194> —— 不相等 → 0x2a7a10 */
/* @0x2a7a04 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a7a06 mov r1, r7 */
/* @0x2a7a08 mov r2, r5 */
/* @0x2a7a0a bl 0x2ac0c8 <png_handle_IEND> —— bl png_handle_IEND */
/* @0x2a7a0e b 0x2a7c46 <png_read_end+0x3ca> —— → 循环尾 */
/* @0x2a7a10 mov r0, r4 —— r0 = png */
/* @0x2a7a12 mov r1, r6 —— r1 = &chunk_name */
/* @0x2a7a14 bl 0x2a5fe4 <png_handle_as_unknown> —— bl png_handle_as_unknown(png, &chunk_name) */
/* @0x2a7a18 cbz r0, 0x2a7a62 <png_read_end+0x1e6> —— == 0 → 0x2a7a62 主链 */
/* @0x2a7a1a mov r0, r6 —— r0 = &chunk_name */
/* @0x2a7a1c mov r1, r11 —— r1 = r11（槽 1） */
/* @0x2a7a1e movs r2, #0x4 */
/* @0x2a7a20 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：IDAT #1/2（read_end as_unknown 分支）：只做 Too many IDATs 守卫 */
/* @0x2a7a24 cbnz r0, 0x2a7a3a <png_read_end+0x1be> —— 不相等 → 0x2a7a3a */
/* @0x2a7a26 cbnz r5, 0x2a7a30 <png_read_end+0x1b4> —— length != 0 → 0x2a7a30 报错 */
/* @0x2a7a28 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7a2c lsls r1, r3, #0x12 —— lsls #0x12 → 测 bit13 (0x2000) */
/* @0x2a7a2e bpl 0x2a7a3a <png_read_end+0x1be> —— 清 → 0x2a7a3a 放行（bit13 是 read_info 0x2a716c 置的） */
/* @0x2a7a30 ldr r1, [pc, #0x228] —— r1 = "Too many IDATs found"（0x38c8b4） */
/* @0x2a7a32 mov r0, r4 */
/* @0x2a7a34 add r1, pc */
/* @0x2a7a36 bl 0x2a642c <png_error> —— bl png_error */
/* @0x2a7a3a mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a7a3c mov r1, r7 */
/* @0x2a7a3e mov r2, r5 */
/* @0x2a7a40 bl 0x2ada34 <png_handle_unknown> —— bl png_handle_unknown */
/* @0x2a7a44 mov r0, r6 —— r0 = &chunk_name */
/* @0x2a7a46 mov r1, r10 —— r1 = r10（槽 3） */
/* @0x2a7a48 movs r2, #0x4 */
/* @0x2a7a4a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "PLTE", 4)：PLTE #1/2（read_end as_unknown 分支）：命中 → mode |= 0x2 */
/* @0x2a7a4e cmp r0, #0x0 —— 不相等 → 0x2a7c46 循环尾 */
/* @0x2a7a50 bne.w 0x2a7c46 <png_read_end+0x3ca> */
/* @0x2a7a54 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7a58 orr r3, r3, #0x2 —— orr #0x2（有 PLTE） */
/* @0x2a7a5c str.w r3, [r4, #0x12c] —— 写回 */
/* @0x2a7a60 b 0x2a7c46 <png_read_end+0x3ca> —— → 循环尾 */
/* @0x2a7a62 mov r0, r6 —— 主链：r0 = &chunk_name */
/* @0x2a7a64 mov r1, r11 —— r1 = r11（槽 1） */
/* @0x2a7a66 movs r2, #0x4 */
/* @0x2a7a68 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "IDAT", 4)：IDAT #2/2（read_end 主链）：同上 */
/* @0x2a7a6c cbnz r0, 0x2a7a8c <png_read_end+0x210> —— 不相等 → 0x2a7a8c */
/* @0x2a7a6e cbnz r5, 0x2a7a78 <png_read_end+0x1fc> —— length != 0 → 0x2a7a78 报错 */
/* @0x2a7a70 ldr.w r3, [r4, #0x12c] —— mode */
/* @0x2a7a74 lsls r2, r3, #0x12 —— 测 bit13 */
/* @0x2a7a76 bpl 0x2a7a82 <png_read_end+0x206> —— 清 → 0x2a7a82 */
/* @0x2a7a78 ldr r1, [pc, #0x1e4] —— r1 = "Too many IDATs found" */
/* @0x2a7a7a mov r0, r4 */
/* @0x2a7a7c add r1, pc */
/* @0x2a7a7e bl 0x2a642c <png_error> —— bl png_error */
/* @0x2a7a82 mov r0, r4 —— r0 = png */
/* @0x2a7a84 mov r1, r5 —— r1 = length（= 0） */
/* @0x2a7a86 bl 0x2abc94 <png_crc_finish> —— bl png_crc_finish(png, length)：空 IDAT 直接吃掉 */
/* @0x2a7a8a b 0x2a7c46 <png_read_end+0x3ca> —— → 循环尾 */
/* @0x2a7a8c mov r0, r6 —— r0 = &chunk_name */
/* @0x2a7a8e mov r1, r10 —— r1 = r10（槽 3） */
/* @0x2a7a90 movs r2, #0x4 */
/* @0x2a7a92 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "PLTE", 4)：PLTE #2/2（read_end 主链）：命中 → png_handle_PLTE */
/* @0x2a7a96 cbnz r0, 0x2a7aa4 <png_read_end+0x228> —— 不相等 → 0x2a7aa4 */
/* @0x2a7a98 mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a7a9a mov r1, r7 */
/* @0x2a7a9c mov r2, r5 */
/* @0x2a7a9e bl 0x2abf64 <png_handle_PLTE> —— bl png_handle_PLTE */
/* @0x2a7aa2 b 0x2a7c46 <png_read_end+0x3ca> —— → 循环尾 */
/* @0x2a7aa4 mov r0, r6 */
/* @0x2a7aa6 add r1, sp, #0x28 */
/* @0x2a7aa8 movs r2, #0x4 */
/* @0x2a7aaa blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "bKGD", 4) */
/* @0x2a7aae cbnz r0, 0x2a7abc <png_read_end+0x240> */
/* @0x2a7ab0 mov r0, r4 */
/* @0x2a7ab2 mov r1, r7 */
/* @0x2a7ab4 mov r2, r5 */
/* @0x2a7ab6 bl 0x2acd60 <png_handle_bKGD> —— bl png_handle_*（png, info, length） */
/* @0x2a7aba b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7abc mov r0, r6 */
/* @0x2a7abe add r1, sp, #0x30 */
/* @0x2a7ac0 movs r2, #0x4 */
/* @0x2a7ac2 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "cHRM", 4) */
/* @0x2a7ac6 cbnz r0, 0x2a7ad4 <png_read_end+0x258> */
/* @0x2a7ac8 mov r0, r4 */
/* @0x2a7aca mov r1, r7 */
/* @0x2a7acc mov r2, r5 */
/* @0x2a7ace bl 0x2ac328 <png_handle_cHRM> —— bl png_handle_*（png, info, length） */
/* @0x2a7ad2 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7ad4 mov r0, r6 */
/* @0x2a7ad6 add r1, sp, #0x38 */
/* @0x2a7ad8 movs r2, #0x4 */
/* @0x2a7ada blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "gAMA", 4) */
/* @0x2a7ade cbnz r0, 0x2a7aec <png_read_end+0x270> */
/* @0x2a7ae0 mov r0, r4 */
/* @0x2a7ae2 mov r1, r7 */
/* @0x2a7ae4 mov r2, r5 */
/* @0x2a7ae6 bl 0x2ac110 <png_handle_gAMA> —— bl png_handle_*（png, info, length） */
/* @0x2a7aea b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7aec mov r0, r6 */
/* @0x2a7aee add r1, sp, #0x40 */
/* @0x2a7af0 movs r2, #0x4 */
/* @0x2a7af2 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "hIST", 4) */
/* @0x2a7af6 cbnz r0, 0x2a7b04 <png_read_end+0x288> */
/* @0x2a7af8 mov r0, r4 */
/* @0x2a7afa mov r1, r7 */
/* @0x2a7afc mov r2, r5 */
/* @0x2a7afe bl 0x2ace98 <png_handle_hIST> —— bl png_handle_*（png, info, length） */
/* @0x2a7b02 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b04 mov r0, r6 */
/* @0x2a7b06 add r1, sp, #0x58 */
/* @0x2a7b08 movs r2, #0x4 */
/* @0x2a7b0a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "oFFs", 4) */
/* @0x2a7b0e cbnz r0, 0x2a7b1c <png_read_end+0x2a0> */
/* @0x2a7b10 mov r0, r4 */
/* @0x2a7b12 mov r1, r7 */
/* @0x2a7b14 mov r2, r5 */
/* @0x2a7b16 bl 0x2ad030 <png_handle_oFFs> —— bl png_handle_*（png, info, length） */
/* @0x2a7b1a b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b1c mov r0, r6 */
/* @0x2a7b1e add r1, sp, #0x60 */
/* @0x2a7b20 movs r2, #0x4 */
/* @0x2a7b22 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "pCAL", 4) */
/* @0x2a7b26 cbnz r0, 0x2a7b34 <png_read_end+0x2b8> */
/* @0x2a7b28 mov r0, r4 */
/* @0x2a7b2a mov r1, r7 */
/* @0x2a7b2c mov r2, r5 */
/* @0x2a7b2e bl 0x2ad128 <png_handle_pCAL> —— bl png_handle_*（png, info, length） */
/* @0x2a7b32 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b34 mov r0, r6 */
/* @0x2a7b36 add r1, sp, #0x78 */
/* @0x2a7b38 movs r2, #0x4 */
/* @0x2a7b3a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sCAL", 4) */
/* @0x2a7b3e cbnz r0, 0x2a7b4c <png_read_end+0x2d0> */
/* @0x2a7b40 mov r0, r4 */
/* @0x2a7b42 mov r1, r7 */
/* @0x2a7b44 mov r2, r5 */
/* @0x2a7b46 bl 0x2ad350 <png_handle_sCAL> —— bl png_handle_*（png, info, length） */
/* @0x2a7b4a b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b4c mov r0, r6 */
/* @0x2a7b4e add r1, sp, #0x68 */
/* @0x2a7b50 movs r2, #0x4 */
/* @0x2a7b52 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "pHYs", 4) */
/* @0x2a7b56 cbnz r0, 0x2a7b64 <png_read_end+0x2e8> */
/* @0x2a7b58 mov r0, r4 */
/* @0x2a7b5a mov r1, r7 */
/* @0x2a7b5c mov r2, r5 */
/* @0x2a7b5e bl 0x2acf58 <png_handle_pHYs> —— bl png_handle_*（png, info, length） */
/* @0x2a7b62 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b64 mov r0, r6 */
/* @0x2a7b66 add r1, sp, #0x70 */
/* @0x2a7b68 movs r2, #0x4 */
/* @0x2a7b6a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sBIT", 4) */
/* @0x2a7b6e cbnz r0, 0x2a7b7c <png_read_end+0x300> */
/* @0x2a7b70 mov r0, r4 */
/* @0x2a7b72 mov r1, r7 */
/* @0x2a7b74 mov r2, r5 */
/* @0x2a7b76 bl 0x2ac238 <png_handle_sBIT> —— bl png_handle_*（png, info, length） */
/* @0x2a7b7a b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b7c mov r0, r6 */
/* @0x2a7b7e add r1, sp, #0x88 */
/* @0x2a7b80 movs r2, #0x4 */
/* @0x2a7b82 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sRGB", 4) */
/* @0x2a7b86 cbnz r0, 0x2a7b94 <png_read_end+0x318> */
/* @0x2a7b88 mov r0, r4 */
/* @0x2a7b8a mov r1, r7 */
/* @0x2a7b8c mov r2, r5 */
/* @0x2a7b8e bl 0x2ac694 <png_handle_sRGB> —— bl png_handle_*（png, info, length） */
/* @0x2a7b92 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7b94 mov r0, r6 */
/* @0x2a7b96 add r1, sp, #0x48 */
/* @0x2a7b98 movs r2, #0x4 */
/* @0x2a7b9a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "iCCP", 4) */
/* @0x2a7b9e cbnz r0, 0x2a7bac <png_read_end+0x330> */
/* @0x2a7ba0 mov r0, r4 */
/* @0x2a7ba2 mov r1, r7 */
/* @0x2a7ba4 mov r2, r5 */
/* @0x2a7ba6 bl 0x2ac814 <png_handle_iCCP> —— bl png_handle_*（png, info, length） */
/* @0x2a7baa b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7bac mov r0, r6 */
/* @0x2a7bae add r1, sp, #0x80 */
/* @0x2a7bb0 movs r2, #0x4 */
/* @0x2a7bb2 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "sPLT", 4) */
/* @0x2a7bb6 cbnz r0, 0x2a7bc4 <png_read_end+0x348> */
/* @0x2a7bb8 mov r0, r4 */
/* @0x2a7bba mov r1, r7 */
/* @0x2a7bbc mov r2, r5 */
/* @0x2a7bbe bl 0x2ac9ec <png_handle_sPLT> —— bl png_handle_*（png, info, length） */
/* @0x2a7bc2 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7bc4 mov r0, r6 */
/* @0x2a7bc6 add r1, sp, #0x90 */
/* @0x2a7bc8 movs r2, #0x4 */
/* @0x2a7bca blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tEXt", 4) */
/* @0x2a7bce cbnz r0, 0x2a7bdc <png_read_end+0x360> */
/* @0x2a7bd0 mov r0, r4 */
/* @0x2a7bd2 mov r1, r7 */
/* @0x2a7bd4 mov r2, r5 */
/* @0x2a7bd6 bl 0x2ad584 <png_handle_tEXt> —— bl png_handle_*（png, info, length） */
/* @0x2a7bda b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7bdc mov r0, r6 */
/* @0x2a7bde add r1, sp, #0x98 */
/* @0x2a7be0 movs r2, #0x4 */
/* @0x2a7be2 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tIME", 4) */
/* @0x2a7be6 cbnz r0, 0x2a7bf4 <png_read_end+0x378> */
/* @0x2a7be8 mov r0, r4 */
/* @0x2a7bea mov r1, r7 */
/* @0x2a7bec mov r2, r5 */
/* @0x2a7bee bl 0x2ad4d0 <png_handle_tIME> —— bl png_handle_*（png, info, length） */
/* @0x2a7bf2 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7bf4 mov r0, r6 */
/* @0x2a7bf6 add r1, sp, #0xa0 */
/* @0x2a7bf8 movs r2, #0x4 */
/* @0x2a7bfa blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "tRNS", 4) */
/* @0x2a7bfe cbnz r0, 0x2a7c0c <png_read_end+0x390> */
/* @0x2a7c00 mov r0, r4 */
/* @0x2a7c02 mov r1, r7 */
/* @0x2a7c04 mov r2, r5 */
/* @0x2a7c06 bl 0x2acbec <png_handle_tRNS> —— bl png_handle_*（png, info, length） */
/* @0x2a7c0a b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7c0c mov r0, r6 */
/* @0x2a7c0e add r1, sp, #0xa8 */
/* @0x2a7c10 movs r2, #0x4 */
/* @0x2a7c12 blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "zTXt", 4) */
/* @0x2a7c16 cbnz r0, 0x2a7c24 <png_read_end+0x3a8> */
/* @0x2a7c18 mov r0, r4 */
/* @0x2a7c1a mov r1, r7 */
/* @0x2a7c1c mov r2, r5 */
/* @0x2a7c1e bl 0x2ad6cc <png_handle_zTXt> —— bl png_handle_*（png, info, length） */
/* @0x2a7c22 b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7c24 mov r0, r6 */
/* @0x2a7c26 add r1, sp, #0x50 */
/* @0x2a7c28 movs r2, #0x4 */
/* @0x2a7c2a blx 0xb6c40 <memcmp@plt> —— memcmp(&chunk_name, "iTXt", 4) */
/* @0x2a7c2e cbnz r0, 0x2a7c3c <png_read_end+0x3c0> */
/* @0x2a7c30 mov r0, r4 */
/* @0x2a7c32 mov r1, r7 */
/* @0x2a7c34 mov r2, r5 */
/* @0x2a7c36 bl 0x2ad850 <png_handle_iTXt> —— bl png_handle_*（png, info, length） */
/* @0x2a7c3a b 0x2a7c46 <png_read_end+0x3ca> —— → 0x2a7c46 循环尾 */
/* @0x2a7c3c mov r0, r4 —— r0 = png ; r1 = info ; r2 = length */
/* @0x2a7c3e mov r1, r7 */
/* @0x2a7c40 mov r2, r5 */
/* @0x2a7c42 bl 0x2ada34 <png_handle_unknown> —— bl png_handle_unknown */
/* @0x2a7c46 ldr.w r3, [r4, #0x12c] —— 循环尾：mode(+0x12c) */
/* @0x2a7c4a lsls r3, r3, #0x1b —— lsls #0x1b → 测 bit4 (0x10 = 有 IEND) */
/* @0x2a7c4c bpl.w 0x2a78a4 <png_read_end+0x28> —— 清 → 0x2a78a4 继续读（名表重铺） */
/* @0x2a7c50 add sp, #0xb4 —— 出口：add sp, #0xb4 */
/* @0x2a7c52 pop.w {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— pop.w {r4-r11,pc} */
/* @0x2a7c56 nop —— nop（对齐填充） */
/* @0x2a7c58 strh r6, [r5, #0x2] —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */
/* @0x2a7c5a movs r6, r1 —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */
/* @0x2a7c5c ldr r6, [pc, #0x1f0] —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */
/* @0x2a7c5e movs r6, r1 —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */
/* @0x2a7c60 ldr r6, [pc, #0xd0] —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */
/* @0x2a7c62 movs r6, r1 —— 数据字：literal pool（0x2a7c58 = 0x000e806e 名表基址；0x2a7c5c / 0x2a7c60 都指向 0x38c8b4 "Too many IDATs found"） */

/* ════════════════════════════════════════════════════════════════════
 * 节 6/9  png_read_destroy（0x2a7c64 .. 0x2a7e2c，456 B，146 条）
 *   契约：void png_read_destroy(png_structp png, png_infop info, png_infop end_info)
 *   顺序固定，且**不看 NULL 以外任何条件**地走完：
 *     ① png_info_destroy(png, info)（info 非 NULL） ② png_info_destroy(png, end_info)（同）
 *     ③ 9 个无条件 png_free：+0x170 +0x2f4 +0x1ac +0x330 +0x2b0 +0x2b4 +0x228 +0x22c +0x230
 *     ④ 3 个按 [+0x2c0] 位守护的释放：bit12 → png_zfree(+0x1d8) / bit13 → png_free(+0x24c) /
 *        bit3 → png_free(+0x2b8)；每处释放后对应位被 bic 清掉（幂等化）
 *     ⑤ 3 张指针数组 +0x234 / +0x238 / +0x23c：长度 = 1 << (8 − [+0x21c])，逐元素 free 再 free 数组体
 *     ⑥ png_free(+0x2bc) → inflateEnd(&png->zstream (+0x138)) → png_free(+0x274)
 *     ⑦ memset(png, 0, 0x338)，再恢复前 0x100 B 与 +0x104/+0x108/+0x10c/+0x2f0
 *   ⑦ 的 0x338 就是 **sizeof(png_struct)**；被恢复的 5 处说明它们是「销毁后仍可能被用到」的
 *   长寿命字段（jmp_buf 区与分配器钩子），其余全部归零 —— 这也让二次调用 png_read_destroy 变成安全操作。
 *   注意：row_buf(+0x1b0) **不在**释放清单里（只有 prev_row(+0x1ac) 和 +0x2f4 被 free）；若 row_buf
 *   是指向 +0x2f4 那块大缓冲的内部指针，则它随 +0x2f4 一起释放 —— 这条映射未证（open 10）。
 *   谁调它：png_destroy_read_struct 0x2a7e5e（唯一一处）；外部 0 个 blx。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7c64 0x2a7e2c png_read_destroy */

/* @0x2a7c64 push.w {r4, r5, r6, r7, r8, r9, lr} —— push.w {r4-r9,lr}；帧 0x104（暂存 png_struct 前 0x100 B） */
/* @0x2a7c68 mov r4, r0 —— r4 = png_ptr */
/* @0x2a7c6a sub sp, #0x104 */
/* @0x2a7c6c mov r5, r2 —— r5 = end_info */
/* @0x2a7c6e cbz r1, 0x2a7c74 <png_read_destroy+0x10> —— info != NULL ? */
/* @0x2a7c70 bl 0x2a5ebe <png_info_destroy> —— bl png_info_destroy(png, info) */
/* @0x2a7c74 cbz r5, 0x2a7c7e <png_read_destroy+0x1a> —— end_info != NULL ? */
/* @0x2a7c76 mov r0, r4 —— r0 = png */
/* @0x2a7c78 mov r1, r5 —— r1 = end_info */
/* @0x2a7c7a bl 0x2a5ebe <png_info_destroy> —— bl png_info_destroy(png, end_info) */
/* @0x2a7c7e mov r0, r4 —— r0 = png */
/* @0x2a7c80 ldr.w r1, [r4, #0x170] —— r1 = [+0x170]（zbuf） */
/* @0x2a7c84 bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7c88 mov r0, r4 —— r0 = png */
/* @0x2a7c8a ldr.w r1, [r4, #0x2f4] —— r1 = [+0x2f4] */
/* @0x2a7c8e bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7c92 mov r0, r4 —— r0 = png */
/* @0x2a7c94 ldr.w r1, [r4, #0x1ac] —— r1 = [+0x1ac]（prev_row） */
/* @0x2a7c98 bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7c9c mov r0, r4 —— r0 = png */
/* @0x2a7c9e ldr.w r1, [r4, #0x330] —— r1 = [+0x330] */
/* @0x2a7ca2 bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7ca6 mov r0, r4 —— r0 = png */
/* @0x2a7ca8 ldr.w r1, [r4, #0x2b0] —— r1 = [+0x2b0] */
/* @0x2a7cac bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7cb0 mov r0, r4 —— r0 = png */
/* @0x2a7cb2 ldr.w r1, [r4, #0x2b4] —— r1 = [+0x2b4]（旧卡 anon_2a804c_group 证过 png_set_quantize 分配这个槽） */
/* @0x2a7cb6 bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7cba mov r0, r4 —— r0 = png */
/* @0x2a7cbc ldr.w r1, [r4, #0x228] —— r1 = [+0x228] */
/* @0x2a7cc0 bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7cc4 mov r0, r4 —— r0 = png */
/* @0x2a7cc6 ldr.w r1, [r4, #0x22c] —— r1 = [+0x22c] */
/* @0x2a7cca bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7cce ldr.w r1, [r4, #0x230] —— r1 = [+0x230] */
/* @0x2a7cd2 mov r0, r4 —— r0 = png */
/* @0x2a7cd4 bl 0x2a6cfc <png_free> —— png_free：以上 9 个指针无条件释放（不看空、不看标志） */
/* @0x2a7cd8 ldr.w r3, [r4, #0x2c0] —— 释放位图 [+0x2c0] */
/* @0x2a7cdc lsls r1, r3, #0x13 —— lsls #0x13 → 测 bit12 (0x1000) */
/* @0x2a7cde bpl 0x2a7cea <png_read_destroy+0x86> —— 清 → 0x2a7cea */
/* @0x2a7ce0 mov r0, r4 —— r0 = png */
/* @0x2a7ce2 ldr.w r1, [r4, #0x1d8] —— r1 = [+0x1d8] */
/* @0x2a7ce6 bl 0x2a5af0 <png_zfree> —— bl png_zfree：zlib 的分配通道（不是 png_free） */
/* @0x2a7cea ldr.w r3, [r4, #0x2c0] —— 重读 [+0x2c0] */
/* @0x2a7cee bic r2, r3, #0x1000 —— bic #0x1000（清位） */
/* @0x2a7cf2 str.w r2, [r4, #0x2c0] —— 写回 */
/* @0x2a7cf6 lsls r2, r3, #0x12 —— lsls #0x12 → 测 bit13 (0x2000) */
/* @0x2a7cf8 bpl 0x2a7d04 <png_read_destroy+0xa0> */
/* @0x2a7cfa mov r0, r4 —— png_free([+0x24c]) */
/* @0x2a7cfc ldr.w r1, [r4, #0x24c] */
/* @0x2a7d00 bl 0x2a6cfc <png_free> */
/* @0x2a7d04 ldr.w r3, [r4, #0x2c0] —— 重读 [+0x2c0] */
/* @0x2a7d08 bic r2, r3, #0x2000 —— bic #0x2000 */
/* @0x2a7d0c lsls r3, r3, #0x1c —— lsls #0x1c → 测 bit3 (0x8) */
/* @0x2a7d0e str.w r2, [r4, #0x2c0] —— 写回（清 bit13） */
/* @0x2a7d12 bpl 0x2a7d1e <png_read_destroy+0xba> —— 清 → 0x2a7d1e */
/* @0x2a7d14 mov r0, r4 —— r0 = png */
/* @0x2a7d16 ldr.w r1, [r4, #0x2b8] —— r1 = [+0x2b8] */
/* @0x2a7d1a bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7d1e ldr.w r3, [r4, #0x2c0] —— 重读 [+0x2c0] */
/* @0x2a7d22 bic r3, r3, #0x8 —— bic #0x8 */
/* @0x2a7d26 str.w r3, [r4, #0x2c0] —— 写回 */
/* @0x2a7d2a ldr.w r3, [r4, #0x234] —— 若 [+0x234]（指针数组）非空 */
/* @0x2a7d2e cbz r3, 0x2a7d5e <png_read_destroy+0xfa> */
/* @0x2a7d30 ldr.w r3, [r4, #0x21c] —— r3 = [+0x21c] */
/* @0x2a7d34 movs r6, #0x1 */
/* @0x2a7d36 movs r5, #0x0 */
/* @0x2a7d38 rsb.w r3, r3, #0x8 —— count = 1 << (8 - [+0x21c]) */
/* @0x2a7d3c lsls r6, r3 —— r6 = count */
/* @0x2a7d3e cmp r5, r6 —— cmp i, count */
/* @0x2a7d40 bge 0x2a7d54 <png_read_destroy+0xf0> —— >= → 0x2a7d54 释放数组本身 */
/* @0x2a7d42 ldr.w r3, [r4, #0x234] —— r3 = [+0x234] */
/* @0x2a7d46 mov r0, r4 */
/* @0x2a7d48 ldr.w r1, [r3, r5, lsl #2] —— r1 = 数组[i] */
/* @0x2a7d4c adds r5, #0x1 —— i++ */
/* @0x2a7d4e bl 0x2a6cfc <png_free> —— png_free(数组[i]) */
/* @0x2a7d52 b 0x2a7d3e <png_read_destroy+0xda> */
/* @0x2a7d54 mov r0, r4 —— r0 = png */
/* @0x2a7d56 ldr.w r1, [r4, #0x234] —— r1 = [+0x234] */
/* @0x2a7d5a bl 0x2a6cfc <png_free> —— png_free(数组) */
/* @0x2a7d5e ldr.w r3, [r4, #0x238] —— 若 [+0x238] 非空（第二张同类数组，同构） */
/* @0x2a7d62 cbz r3, 0x2a7d92 <png_read_destroy+0x12e> */
/* @0x2a7d64 ldr.w r3, [r4, #0x21c] */
/* @0x2a7d68 movs r6, #0x1 */
/* @0x2a7d6a movs r5, #0x0 */
/* @0x2a7d6c rsb.w r3, r3, #0x8 —— count = 1 << (8 - [+0x21c]) */
/* @0x2a7d70 lsls r6, r3 */
/* @0x2a7d72 cmp r5, r6 */
/* @0x2a7d74 bge 0x2a7d88 <png_read_destroy+0x124> */
/* @0x2a7d76 ldr.w r3, [r4, #0x238] */
/* @0x2a7d7a mov r0, r4 */
/* @0x2a7d7c ldr.w r1, [r3, r5, lsl #2] */
/* @0x2a7d80 adds r5, #0x1 */
/* @0x2a7d82 bl 0x2a6cfc <png_free> */
/* @0x2a7d86 b 0x2a7d72 <png_read_destroy+0x10e> */
/* @0x2a7d88 mov r0, r4 */
/* @0x2a7d8a ldr.w r1, [r4, #0x238] */
/* @0x2a7d8e bl 0x2a6cfc <png_free> —— png_free([+0x238]) */
/* @0x2a7d92 ldr.w r3, [r4, #0x23c] —— 若 [+0x23c] 非空（第三张同类数组，同构） */
/* @0x2a7d96 cbz r3, 0x2a7dc6 <png_read_destroy+0x162> */
/* @0x2a7d98 ldr.w r3, [r4, #0x21c] */
/* @0x2a7d9c movs r6, #0x1 */
/* @0x2a7d9e movs r5, #0x0 */
/* @0x2a7da0 rsb.w r3, r3, #0x8 */
/* @0x2a7da4 lsls r6, r3 */
/* @0x2a7da6 cmp r5, r6 */
/* @0x2a7da8 bge 0x2a7dbc <png_read_destroy+0x158> */
/* @0x2a7daa ldr.w r3, [r4, #0x23c] */
/* @0x2a7dae mov r0, r4 */
/* @0x2a7db0 ldr.w r1, [r3, r5, lsl #2] */
/* @0x2a7db4 adds r5, #0x1 */
/* @0x2a7db6 bl 0x2a6cfc <png_free> */
/* @0x2a7dba b 0x2a7da6 <png_read_destroy+0x142> */
/* @0x2a7dbc mov r0, r4 */
/* @0x2a7dbe ldr.w r1, [r4, #0x23c] */
/* @0x2a7dc2 bl 0x2a6cfc <png_free> —— png_free([+0x23c]) */
/* @0x2a7dc6 ldr.w r1, [r4, #0x2bc] —— r1 = [+0x2bc] */
/* @0x2a7dca mov r0, r4 —— r0 = png */
/* @0x2a7dcc bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7dd0 add.w r0, r4, #0x138 —— r0 = png+0x138（内嵌 zstream） */
/* @0x2a7dd4 blx 0xb69e8 <inflateEnd@plt> —— blx inflateEnd：与 read_row 的 inflate(&png+0x138) 互证 zstream 位置 */
/* @0x2a7dd8 mov r0, r4 —— r0 = png */
/* @0x2a7dda ldr.w r1, [r4, #0x274] —— r1 = [+0x274] */
/* @0x2a7dde bl 0x2a6cfc <png_free> —— png_free */
/* @0x2a7de2 mov r1, r4 —— r1 = png */
/* @0x2a7de4 mov r0, sp —— r0 = sp */
/* @0x2a7de6 mov.w r2, #0x100 —— r2 = 0x100 */
/* @0x2a7dea blx 0xb65bc <memcpy@plt> —— memcpy(sp, png, 0x100)：暂存前 0x100 B（jmp_buf 区） */
/* @0x2a7dee ldr.w r9, [r4, #0x104] —— r9 = [+0x104] */
/* @0x2a7df2 ldr.w r8, [r4, #0x108] —— r8 = [+0x108] */
/* @0x2a7df6 mov r0, r4 */
/* @0x2a7df8 ldr.w r7, [r4, #0x10c] —— r7 = [+0x10c] */
/* @0x2a7dfc movs r1, #0x0 */
/* @0x2a7dfe ldr.w r6, [r4, #0x2f0] —— r6 = [+0x2f0]（mem_ptr） */
/* @0x2a7e02 mov.w r2, #0x338 —— r2 = 0x338 */
/* @0x2a7e06 blx 0xb65b0 <memset@plt> —— memset(png, 0, 0x338)：**sizeof(png_struct) = 0x338**（本件实测） */
/* @0x2a7e0a str.w r9, [r4, #0x104] —— [+0x104] 回填 */
/* @0x2a7e0e str.w r8, [r4, #0x108] —— [+0x108] 回填 */
/* @0x2a7e12 mov r0, r4 */
/* @0x2a7e14 str.w r7, [r4, #0x10c] —— [+0x10c] 回填 */
/* @0x2a7e18 mov r1, sp */
/* @0x2a7e1a str.w r6, [r4, #0x2f0] —— [+0x2f0] 回填 */
/* @0x2a7e1e mov.w r2, #0x100 —— r2 = 0x100 */
/* @0x2a7e22 blx 0xb65bc <memcpy@plt> —— memcpy(png, sp, 0x100)：前 0x100 B 复原 */
/* @0x2a7e26 add sp, #0x104 */
/* @0x2a7e28 pop.w {r4, r5, r6, r7, r8, r9, pc} —— pop.w {r4-r9,pc} */

/* ════════════════════════════════════════════════════════════════════
 * 节 7/9  png_destroy_read_struct（0x2a7e2c .. 0x2a7eb8，140 B，54 条）
 *   契约：void png_destroy_read_struct(png_structpp pp, png_infopp info_pp, png_infopp end_pp)
 *   r0=pp  r1=info_pp  r2=end_pp。
 *   两道门：pp == NULL → 返回；*pp == NULL → 返回（**幂等**，二次销毁不炸）。
 *   取 mem_ptr(+0x2f0)/free_fn(+0x2e8) 备用 → 解引用两个 info 二级指针（空指针当 0 传）
 *   → png_read_destroy(png, info, end_info)
 *   → 每个非空 info：png_free_data(png, info, 0x4000, -1) + png_destroy_struct_2(info, mem_ptr, free_fn)
 *     + *info_pp = NULL
 *   → png_destroy_struct_2(png, mem_ptr, free_fn) + *pp = NULL
 *   ⇒ 三条指针都被置空；自定义分配器（mem_ptr/free_fn）跟着 png_ptr 一起作用到两个 info 上。
 *   注意：清零条件是「该槽里的指针非空」（cbz r6 / cbz r5），不是「槽指针本身非空」——
 *   槽非空而 *槽 == 0 时只是跳过一条 `str 0`，结果相同，所以这里没有可观测差异。
 *   谁调它：外部 18 个 blx（loadTexture ×4 / loadTextureP3zip ×4 / getTextureInfo ×3 /
 *     ReadPNGHeader ×3 / ReadPNG ×3 / FreePNG ×1）；内部 0。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7e2c 0x2a7eb8 png_destroy_read_struct */

/* @0x2a7e2c push.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} —— push.w {r3-r11,lr}（r3 只为对齐） */
/* @0x2a7e30 mov r8, r1 —— r8 = info_pp */
/* @0x2a7e32 mov r7, r2 —— r7 = end_pp */
/* @0x2a7e34 mov r9, r0 —— r9 = pp */
/* @0x2a7e36 cmp r0, #0x0 —— pp == NULL ? */
/* @0x2a7e38 beq 0x2a7eb4 <png_destroy_read_struct+0x88> —— → 0x2a7eb4 直接返回 */
/* @0x2a7e3a ldr r4, [r0] —— r4 = *pp */
/* @0x2a7e3c cmp r4, #0x0 —— *pp == NULL ? */
/* @0x2a7e3e beq 0x2a7eb4 <png_destroy_read_struct+0x88> —— → 返回（幂等：销毁两次不炸） */
/* @0x2a7e40 ldr.w r11, [r4, #0x2f0] —— r11 = mem_ptr(+0x2f0) */
/* @0x2a7e44 ldr.w r10, [r4, #0x2e8] —— r10 = free_fn(+0x2e8) */
/* @0x2a7e48 cbz r1, 0x2a7e4e <png_destroy_read_struct+0x22> —— info_pp == NULL ? */
/* @0x2a7e4a ldr r6, [r1] —— r6 = *info_pp */
/* @0x2a7e4c b 0x2a7e50 <png_destroy_read_struct+0x24> —— → 0x2a7e50 */
/* @0x2a7e4e mov r6, r1 —— r6 = info_pp（即 0）—— 二级指针为空就拿 0 当 info */
/* @0x2a7e50 cbz r7, 0x2a7e56 <png_destroy_read_struct+0x2a> —— end_pp == NULL ? */
/* @0x2a7e52 ldr r5, [r7] —— r5 = *end_pp */
/* @0x2a7e54 b 0x2a7e58 <png_destroy_read_struct+0x2c> */
/* @0x2a7e56 mov r5, r7 —— r5 = end_pp（即 0） */
/* @0x2a7e58 mov r0, r4 —— r0 = png */
/* @0x2a7e5a mov r1, r6 —— r1 = info */
/* @0x2a7e5c mov r2, r5 —— r2 = end_info */
/* @0x2a7e5e bl 0x2a7c64 <png_read_destroy> —— bl png_read_destroy(png, info, end_info) */
/* @0x2a7e62 cbz r6, 0x2a7e84 <png_destroy_read_struct+0x58> —— info == NULL ? */
/* @0x2a7e64 mov.w r3, #0xffffffff —— r3 = -1（num_text 类参数 = 全部） */
/* @0x2a7e68 mov r0, r4 —— r0 = png */
/* @0x2a7e6a mov r1, r6 —— r1 = info */
/* @0x2a7e6c mov.w r2, #0x4000 —— r2 = 0x4000（mask） */
/* @0x2a7e70 bl 0x2a5bc0 <png_free_data> —— bl png_free_data(png, info, 0x4000, -1) */
/* @0x2a7e74 mov r0, r6 —— r0 = info */
/* @0x2a7e76 mov r1, r11 —— r1 = mem_ptr */
/* @0x2a7e78 mov r2, r10 —— r2 = free_fn */
/* @0x2a7e7a bl 0x2a6c5e <png_destroy_struct_2> —— bl png_destroy_struct_2(info, mem_ptr, free_fn) */
/* @0x2a7e7e movs r3, #0x0 —— r3 = 0 */
/* @0x2a7e80 str.w r3, [r8] —— *info_pp = NULL */
/* @0x2a7e84 cbz r5, 0x2a7ea4 <png_destroy_read_struct+0x78> —— end_info == NULL ? */
/* @0x2a7e86 mov.w r3, #0xffffffff —— r3 = -1 */
/* @0x2a7e8a mov r0, r4 —— r0 = png */
/* @0x2a7e8c mov r1, r5 —— r1 = end_info */
/* @0x2a7e8e mov.w r2, #0x4000 —— r2 = 0x4000 */
/* @0x2a7e92 bl 0x2a5bc0 <png_free_data> —— bl png_free_data(png, end_info, 0x4000, -1) */
/* @0x2a7e96 mov r0, r5 —— r0 = end_info */
/* @0x2a7e98 mov r1, r11 —— r1 = mem_ptr */
/* @0x2a7e9a mov r2, r10 —— r2 = free_fn */
/* @0x2a7e9c bl 0x2a6c5e <png_destroy_struct_2> —— bl png_destroy_struct_2(end_info, …) */
/* @0x2a7ea0 movs r3, #0x0 —— r3 = 0 */
/* @0x2a7ea2 str r3, [r7] —— *end_pp = NULL */
/* @0x2a7ea4 mov r0, r4 —— r0 = png */
/* @0x2a7ea6 mov r1, r11 —— r1 = mem_ptr */
/* @0x2a7ea8 mov r2, r10 —— r2 = free_fn */
/* @0x2a7eaa bl 0x2a6c5e <png_destroy_struct_2> —— bl png_destroy_struct_2(png, mem_ptr, free_fn) */
/* @0x2a7eae movs r3, #0x0 —— r3 = 0 */
/* @0x2a7eb0 str.w r3, [r9] —— *pp = NULL */
/* @0x2a7eb4 pop.w {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} —— pop.w {r3-r11,pc} */

/* ════════════════════════════════════════════════════════════════════
 * 节 8/9  png_read_png（0x2a7ec0 .. 0x2a8004，324 B，123 条）
 *   契约：void png_read_png(png_structp png, png_infop info, int transforms, png_voidp params)
 *   r0=png  r1=info  r2=transforms  r3=params（**params 全程不进任何调用**）。
 *   ① png_read_info → info->height(+4) >= 0x40000000 → png_error "Image is too high to process with
 *      png_read_png()"（0x38c8c9）
 *   ② 变换位 → setter（位号 = PNG_TRANSFORM_*）：
 *        bit0 strip_16   bit1 strip_alpha   bit3 packswap   bit4 expand（带三选一判据）
 *        bit5 invert_mono bit6 shift（还要求 info->valid bit1 = sBIT）  bit7 bgr  bit8 swap_alpha
 *        bit9 swap      bit10 invert_alpha  bit13 gray_to_rgb
 *      **没有分支的位：2 / 11 / 12 / 14 / 15** —— 本编译单元把 PACKING 与 STRIP_FILLER* 裁掉了。
 *      bit4 的判据是本件与上游最不一样的地方：展开条件是「bit_depth ≤ 7 **或** color_type == 3
 *      **或** valid bit4(tRNS) 置位」（0x2a7f06..0x2a7f1c），方向与上游 1.4.19 的守卫相反（见 open 1）。
 *   ③ png_read_update_info → png_free_data(png, info, 0x40, 0)（丢掉旧行指针）
 *      → 若 info->row_pointers(+0xf8) 为空：png_malloc(height*4) + 逐项清零 + free_me |= 0x40
 *        + 逐行 png_get_rowbytes/png_malloc
 *   ④ png_read_image(png, row_pointers) → info->valid |= 0x8000（PNG_INFO_IDAT）→ 尾跳 png_read_end
 *   谁调它：0 个（导出但全库无人调用，连内部也没有）—— 这条路在本作里是死代码，但仍完整可执行。
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a7ec0 0x2a8004 png_read_png */

/* @0x2a7ec0 push {r3, r4, r5, r6, r7, lr} —— push {r3-r7,lr}（r3 只为对齐） */
/* @0x2a7ec2 mov r5, r1 —— r5 = info_ptr */
/* @0x2a7ec4 mov r6, r2 —— r6 = transforms */
/* @0x2a7ec6 mov r4, r0 —— r4 = png_ptr */
/* @0x2a7ec8 cmp r0, #0x0 —— png_ptr == NULL ? → 0x2a7ffe 返回 */
/* @0x2a7eca beq.w 0x2a7ffe <png_read_png+0x13e> */
/* @0x2a7ece bl 0x2a6ff0 <png_read_info> —— bl png_read_info(png, info)：一次读到第一个 IDAT */
/* @0x2a7ed2 ldr r3, [r5, #0x4] —— r3 = info->height(+4) */
/* @0x2a7ed4 cmp.w r3, #0x40000000 —— cmp #0x40000000 */
/* @0x2a7ed8 blo 0x2a7ee4 <png_read_png+0x24> —— < → 0x2a7ee4 */
/* @0x2a7eda ldr r1, [pc, #0x124] —— r1 = "Image is too high to process with png_read_png()"（0x38c8c9） */
/* @0x2a7edc mov r0, r4 */
/* @0x2a7ede add r1, pc */
/* @0x2a7ee0 bl 0x2a642c <png_error> —— bl png_error */
/* @0x2a7ee4 lsls r1, r6, #0x1f —— lsls #0x1f → transforms bit0 (PNG_TRANSFORM_STRIP_16) */
/* @0x2a7ee6 bpl 0x2a7eee <png_read_png+0x2e> —— 清 → 0x2a7eee */
/* @0x2a7ee8 mov r0, r4 —— r0 = png */
/* @0x2a7eea bl 0x2a8184 <png_set_strip_16> —— bl png_set_strip_16 */
/* @0x2a7eee lsls r2, r6, #0x1e —— lsls #0x1e → bit1 (STRIP_ALPHA) */
/* @0x2a7ef0 bpl 0x2a7ef8 <png_read_png+0x38> */
/* @0x2a7ef2 mov r0, r4 */
/* @0x2a7ef4 bl 0x2a8194 <png_set_strip_alpha> —— bl png_set_strip_alpha */
/* @0x2a7ef8 lsls r3, r6, #0x1c —— lsls #0x1c → bit3 (PACKSWAP) */
/* @0x2a7efa bpl 0x2a7f02 <png_read_png+0x42> */
/* @0x2a7efc mov r0, r4 */
/* @0x2a7efe bl 0x2af77e <png_set_packswap> —— bl png_set_packswap */
/* @0x2a7f02 lsls r7, r6, #0x1b —— lsls #0x1b → bit4 (EXPAND) */
/* @0x2a7f04 bpl 0x2a7f22 <png_read_png+0x62> —— 清 → 0x2a7f22 */
/* @0x2a7f06 ldrb.w r3, [r4, #0x1eb] —— bit_depth(+0x1eb) */
/* @0x2a7f0a cmp r3, #0x7 —— cmp #7 */
/* @0x2a7f0c bls 0x2a7f1c <png_read_png+0x5c> —— <= 7 → 0x2a7f1c 展开 */
/* @0x2a7f0e ldrb.w r3, [r4, #0x1ea] —— color_type(+0x1ea) */
/* @0x2a7f12 cmp r3, #0x3 —— == 3（调色板）→ 展开 */
/* @0x2a7f14 beq 0x2a7f1c <png_read_png+0x5c> */
/* @0x2a7f16 ldr r3, [r5, #0x8] —— info->valid(+8) */
/* @0x2a7f18 lsls r0, r3, #0x1b —— lsls #0x1b → 测 bit4 (0x10 = tRNS) */
/* @0x2a7f1a bpl 0x2a7f22 <png_read_png+0x62> —— 清 → 0x2a7f22 不展开 */
/* @0x2a7f1c mov r0, r4 */
/* @0x2a7f1e bl 0x2a8790 <png_set_expand> —— bl png_set_expand：判据是「低深度 或 调色板 或 有 tRNS」 */
/* @0x2a7f22 lsls r1, r6, #0x1a —— lsls #0x1a → bit5 (INVERT_MONO) */
/* @0x2a7f24 bpl 0x2a7f2c <png_read_png+0x6c> */
/* @0x2a7f26 mov r0, r4 */
/* @0x2a7f28 bl 0x2af84a <png_set_invert_mono> —— bl png_set_invert_mono */
/* @0x2a7f2c lsls r2, r6, #0x19 —— lsls #0x19 → bit6 (SHIFT) */
/* @0x2a7f2e bpl 0x2a7f40 <png_read_png+0x80> —— 清 → 0x2a7f40 */
/* @0x2a7f30 ldr r3, [r5, #0x8] —— info->valid */
/* @0x2a7f32 lsls r3, r3, #0x1e —— lsls #0x1e → 测 bit1 (0x2 = sBIT) */
/* @0x2a7f34 bpl 0x2a7f40 <png_read_png+0x80> —— 清 → 0x2a7f40 */
/* @0x2a7f36 mov r0, r4 —— r0 = png */
/* @0x2a7f38 add.w r1, r5, #0x44 —— r1 = info+0x44（png_set_shift 的通道位源） */
/* @0x2a7f3c bl 0x2af796 <png_set_shift> —— bl png_set_shift */
/* @0x2a7f40 lsls r7, r6, #0x18 —— lsls #0x18 → bit7 (BGR) */
/* @0x2a7f42 bpl 0x2a7f4a <png_read_png+0x8a> */
/* @0x2a7f44 mov r0, r4 */
/* @0x2a7f46 bl 0x2af738 <png_set_bgr> —— bl png_set_bgr */
/* @0x2a7f4a lsls r0, r6, #0x17 —— lsls #0x17 → bit8 (SWAP_ALPHA) */
/* @0x2a7f4c bpl 0x2a7f54 <png_read_png+0x94> */
/* @0x2a7f4e mov r0, r4 */
/* @0x2a7f50 bl 0x2af82a <png_set_swap_alpha> —— bl png_set_swap_alpha */
/* @0x2a7f54 lsls r1, r6, #0x16 —— lsls #0x16 → bit9 (SWAP) */
/* @0x2a7f56 bpl 0x2a7f5e <png_read_png+0x9e> */
/* @0x2a7f58 mov r0, r4 */
/* @0x2a7f5a bl 0x2af748 <png_set_swap> —— bl png_set_swap */
/* @0x2a7f5e lsls r2, r6, #0x15 —— lsls #0x15 → bit10 (INVERT_ALPHA) */
/* @0x2a7f60 bpl 0x2a7f68 <png_read_png+0xa8> */
/* @0x2a7f62 mov r0, r4 */
/* @0x2a7f64 bl 0x2af83a <png_set_invert_alpha> —— bl png_set_invert_alpha */
/* @0x2a7f68 lsls r3, r6, #0x12 —— lsls #0x12 → bit13 (GRAY_TO_RGB) */
/* @0x2a7f6a bpl 0x2a7f72 <png_read_png+0xb2> */
/* @0x2a7f6c mov r0, r4 */
/* @0x2a7f6e bl 0x2a880a <png_set_gray_to_rgb> —— bl png_set_gray_to_rgb：未被测的位：2、11、12、14、15（本编译单元没有对应分支） */
/* @0x2a7f72 mov r0, r4 —— r0 = png */
/* @0x2a7f74 mov r1, r5 —— r1 = info */
/* @0x2a7f76 bl 0x2a7448 <png_read_update_info> —— bl png_read_update_info */
/* @0x2a7f7a mov r0, r4 —— r0 = png */
/* @0x2a7f7c mov r1, r5 —— r1 = info */
/* @0x2a7f7e movs r2, #0x40 —— r2 = 0x40（PNG_FREE_ROWS） */
/* @0x2a7f80 movs r3, #0x0 —— r3 = 0 */
/* @0x2a7f82 bl 0x2a5bc0 <png_free_data> —— bl png_free_data：丢掉调用方可能已给的行指针 */
/* @0x2a7f86 ldr.w r6, [r5, #0xf8] —— r6 = info->row_pointers(+0xf8) */
/* @0x2a7f8a cbz r6, 0x2a7faa <png_read_png+0xea> —— 非空 → 0x2a7f8c（不重新分配） */
/* @0x2a7f8c mov r0, r4 —— r0 = png */
/* @0x2a7f8e ldr.w r1, [r5, #0xf8] —— r1 = info->row_pointers */
/* @0x2a7f92 bl 0x2a7840 <png_read_image> —— bl png_read_image(png, row_pointers) */
/* @0x2a7f96 ldr r3, [r5, #0x8] —— r3 = info->valid */
/* @0x2a7f98 mov r0, r4 —— r0 = png */
/* @0x2a7f9a mov r1, r5 —— r1 = info */
/* @0x2a7f9c orr r3, r3, #0x8000 —— orr #0x8000（PNG_INFO_IDAT） */
/* @0x2a7fa0 str r3, [r5, #0x8] —— 写回 valid */
/* @0x2a7fa2 pop.w {r3, r4, r5, r6, r7, lr} —— pop.w {r3-r7,lr} */
/* @0x2a7fa6 b.w 0x2a787c <png_read_end> —— b.w png_read_end：尾跳，把 IEND 之后交给 read_end */
/* @0x2a7faa ldr r1, [r5, #0x4] —— r1 = height */
/* @0x2a7fac mov r0, r4 —— r0 = png */
/* @0x2a7fae lsls r1, r1, #0x2 —— lsls #2 → height*4 */
/* @0x2a7fb0 bl 0x2a6ca0 <png_malloc> —— bl png_malloc(png, height * 4) */
/* @0x2a7fb4 mov r3, r6 —— r3 = 0 */
/* @0x2a7fb6 mov r1, r6 —— r1 = 0 */
/* @0x2a7fb8 str.w r0, [r5, #0xf8] —— info->row_pointers = 新数组 */
/* @0x2a7fbc ldr r2, [r5, #0x4] —— r2 = height */
/* @0x2a7fbe cmp r3, r2 —— cmp i, height */
/* @0x2a7fc0 bhs 0x2a7fce <png_read_png+0x10e> —— >= → 0x2a7fce */
/* @0x2a7fc2 ldr.w r2, [r5, #0xf8] —— r2 = row_pointers */
/* @0x2a7fc6 str.w r1, [r2, r3, lsl #2] —— row_pointers[i] = 0 */
/* @0x2a7fca adds r3, #0x1 —— i++ */
/* @0x2a7fcc b 0x2a7fbc <png_read_png+0xfc> */
/* @0x2a7fce ldr.w r3, [r5, #0xb8] —— info->free_me(+0xb8) */
/* @0x2a7fd2 movs r6, #0x0 —— r6 = 0 */
/* @0x2a7fd4 orr r3, r3, #0x40 —— orr #0x40（PNG_FREE_ROWS） */
/* @0x2a7fd8 str.w r3, [r5, #0xb8] —— 写回 */
/* @0x2a7fdc ldr r3, [r5, #0x4] —— r3 = height */
/* @0x2a7fde cmp r6, r3 —— cmp i, height */
/* @0x2a7fe0 bge 0x2a7f8c <png_read_png+0xcc> —— >= → 0x2a7f8c 去读图 */
/* @0x2a7fe2 mov r1, r5 —— r1 = info */
/* @0x2a7fe4 mov r0, r4 —— r0 = png */
/* @0x2a7fe6 ldr.w r7, [r5, #0xf8] —— r7 = row_pointers */
/* @0x2a7fea bl 0x2a6574 <png_get_rowbytes> —— bl png_get_rowbytes(png, info) */
/* @0x2a7fee mov r1, r0 —— r1 = rowbytes */
/* @0x2a7ff0 mov r0, r4 —— r0 = png */
/* @0x2a7ff2 bl 0x2a6ca0 <png_malloc> —— bl png_malloc */
/* @0x2a7ff6 str.w r0, [r7, r6, lsl #2] —— 写回 */
/* @0x2a7ffa adds r6, #0x1 —— i++ */
/* @0x2a7ffc b 0x2a7fdc <png_read_png+0x11c> —— → 0x2a7fdc */
/* @0x2a7ffe pop {r3, r4, r5, r6, r7, pc} —— pop {r3-r7,pc} */
/* @0x2a8000 ldr r1, [pc, #0x39c] —— 数据字：literal pool（0x2a8000 = 0x000e49e7 → 0x38c8c9 "Image is too high…"） */
/* @0x2a8002 movs r6, r1 —— 数据字：literal pool（0x2a8000 = 0x000e49e7 → 0x38c8c9 "Image is too high…"） */

/* ════════════════════════════════════════════════════════════════════
 * 节 9/9  png_set_read_fn（0x2a804c .. 0x2a809c，80 B，26 条）
 *   契约：void png_set_read_fn(png_structp png, png_voidp io_ptr, png_rw_ptr read_data_fn)
 *   ① png == NULL → 返回
 *   ② io_ptr(+0x118) = r1（无条件写）
 *   ③ read_data_fn 非空 → 写 +0x114；为空 → 从 GOT 取 png_default_read_data 填上
 *      （0x2a8060 解到 0x3f1aa4，该 GOT 项 = 0x2a8005，即 Thumb 入口）
 *   ④ 若 write_data_fn(+0x110) 非空：清 0 + **两条** png_warning（0x38c920 / 0x38c961，拼起来是一句
 *      "It's an error to set both read_data_fn and write_data_fn in the same structure.
 *       Resetting write_data_fn to NULL"）
 *   ⑤ png+0x210 整字清零（字段身份仍未定，见 open 4）
 *   ⇒ 读回调与写回调在本件里互斥：设读回调会把写回调打掉并连发两条告警。
 *   谁调它：外部 5 个 blx（0x1896b4 / 0x189a94 / 0x189c48 / 0x189f50 / 0x28ff58）
 *     + png_create_read_struct_2 0x2a6f84（建结构时设默认回调）
 * ════════════════════════════════════════════════════════════════════ */
/* @func 0x2a804c 0x2a809c png_set_read_fn */

/* @0x2a804c push {r4, lr} */
/* @0x2a804e mov r4, r0 —— r4 = png_ptr */
/* @0x2a8050 cbz r0, 0x2a808e <png_set_read_fn+0x42> —— png_ptr == NULL ? → 0x2a808e 返回 */
/* @0x2a8052 str.w r1, [r0, #0x118] —— io_ptr(+0x118) = r1（无条件写） */
/* @0x2a8056 cbz r2, 0x2a805e <png_set_read_fn+0x12> —— read_data_fn == NULL ? */
/* @0x2a8058 str.w r2, [r0, #0x114] —— read_data_fn(+0x114) = r2 */
/* @0x2a805c b 0x2a8068 <png_set_read_fn+0x1c> —— → 0x2a8068 */
/* @0x2a805e ldr r3, [pc, #0x30] —— r3 ← 字面量 0x149a40（GOT 偏移） */
/* @0x2a8060 add r3, pc —— r3 += pc → 0x3f1aa4 */
/* @0x2a8062 ldr r3, [r3] —— r3 = [r3]（GOT 项）= 0x2a8005 = png_default_read_data */
/* @0x2a8064 str.w r3, [r0, #0x114] —— read_data_fn = png_default_read_data */
/* @0x2a8068 ldr.w r3, [r4, #0x110] —— write_data_fn(+0x110) */
/* @0x2a806c cbz r3, 0x2a8088 <png_set_read_fn+0x3c> —— 空 → 0x2a8088 */
/* @0x2a806e ldr r1, [pc, #0x24] —— r1 = 告警串 1（0x38c920） */
/* @0x2a8070 movs r3, #0x0 —— r3 = 0 */
/* @0x2a8072 mov r0, r4 —— r0 = png */
/* @0x2a8074 str.w r3, [r4, #0x110] —— write_data_fn = NULL（读回调与写回调互斥） */
/* @0x2a8078 add r1, pc —— r1 += pc */
/* @0x2a807a bl 0x2a6474 <png_warning> —— bl png_warning("It's an error to set both read_data_fn and write_data_fn in the ") */
/* @0x2a807e ldr r1, [pc, #0x18] —— r1 = 告警串 2（0x38c961） */
/* @0x2a8080 mov r0, r4 */
/* @0x2a8082 add r1, pc —— r1 += pc */
/* @0x2a8084 bl 0x2a6474 <png_warning> —— bl png_warning("same structure.  Resetting write_data_fn to NULL") */
/* @0x2a8088 movs r3, #0x0 —— r3 = 0 */
/* @0x2a808a str.w r3, [r4, #0x210] —— png+0x210 = 0（整字写 0，字段身份未定） */
/* @0x2a808e pop {r4, pc} */
/* @0x2a8090 ldr r2, [sp, #0x100] —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */
/* @0x2a8092 movs r4, r2 —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */
/* @0x2a8094 ldr r0, [pc, #0x290] —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */
/* @0x2a8096 movs r6, r1 —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */
/* @0x2a8098 ldr r0, [pc, #0x36c] —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */
/* @0x2a809a movs r6, r1 —— 数据字：literal pool（0x2a8090 = 0x00149a40 GOT 偏移 → 0x3f1aa4，该项 = 0x2a8005 png_default_read_data；0x2a8094 / 0x2a8098 = 两条告警串偏移） */

/* ════ 本卡未闭合（open）═════════════════════════════════════════════
 * 1. 与上游 1.4.19 源码的逐行对照没做。已知的**形状差异**（都是字节事实，但"是不是 GameMaker 改的"未定）：
 *    a) chunk 分派是「每轮重铺 21 项名表 + 4 字节 memcmp」，上游是 png_uint_32 chunk_name 的整字比较；
 *    b) IDAT 在 read_info 里被比 4 次（上游同一函数里 IDAT 出现在 3 处：前置守卫、as_unknown 分支、
 *       主链），本件把 as_unknown 分支里的那处拆成了两次比较；
 *    c) png_combine_row 的第 3 实参是**逐 pass 掩码**（0xff/0x0f/0xff/0x33/0xff/0x55/0xff 与
 *       0x80/0x08/0x88/0x22/0xaa/0x55/0xff），不是 display 布尔；
 *    d) png_read_png 的 EXPAND 判据方向与上游相反（本件：低深度 / 调色板 / 有 tRNS 才展开）。
 *    这四条要么是本件私有变体，要么是编译期常量折叠的结果 —— 没有源码无法判定。
 * 2. +0x18c 与 +0x190 / +0x194 三者的身份（height / num_rows 谁是谁）未定。隔行快路径 6 个 case 的
 *    判据已逐条给出（见节 3），但"为什么这样判"没有源码级解释；+0x194 只在 read_image 里被写一次，
 *    读侧没有任何消费者，是死字段还是给别的编译单元用，未定。
 * 3. intrapixel 门（+0x2dc bit2 && 字节 +0x2e4 == 0x40）的两个字段身份未定：本件没有别处引用它们，
 *    也没有字符串能把它们和某个 png_set_* 对上。png_do_read_intrapixel 本体（0x2ab9f8，134 B）未开卡。
 * 4. png+0x210 整字清零（set_read_fn 末尾）身份仍未定（旧卡 open 5，本卡无新增证据）。
 *    它是**整字写 0**而不是位清，因此不能假定等价于 flags &= ~PNG_FLAG_ROW_INIT。
 * 5. 销毁时被保留的 +0x104/+0x108/+0x10c 三个字，疑为 error_fn / warning_fn / error_ptr，
 *    本件没有直接写入点（只有 png_read_destroy 的保存-恢复）能证明。
 * 6. png_free_data 的 mask 0x4000 + num -1 未映射到 PNG_FREE_* 常量名；
 *    png_read_png 里的 0x40 与 info->free_me |= 0x40 已能对上 PNG_FREE_ROWS，0x4000 那个没找到同族证据。
 * 7. 本卡 9 节之外、但贴着它们的三段没发锚点：
 *      png_start_read_image（0x2a7478，16 B）= read_row/read_update_info 那条 flags bit6 门的独立第三例；
 *      png_set_read_status_fn（0x2a7eb8，8 B）= 只写 +0x25c；
 *      png_read_rows（0x2a77e0，96 B）= 内部 3 处调 png_read_row（0x2a7804/0x2a781c/0x2a7836）。
 *    它们不在 index-libpng_read_all.tsv 的 9 节里，按规矩不发锚点。
 * 8. 行为未跑：全卡是静态字节证据（bytecode_anchored），没有 oracle_anchored / device_anchored 对照；
 *    PNG 解码路径没有用真图跑过，inflate/滤波/变换的内核语义只到"调了谁、传了什么"。
 * 9. **校验口径的已知缺口（本卡落地后实测）**：
 *    · check_card_anchors.py --card cards/libpng_read.c --index asm/index-libpng_read_all.tsv
 *      → index=1529 card=1529 missing=0 extra=0 mismatch=0 / RESULT EXACT；
 *    · verify_reverse_v1.py（拿 asm/instructions.jsonl 比对助记符）→ 本卡 **1528 WRONG**（1,529 条里
 *      只有 1 条碰巧与 ARM 解码同字）。原因不是卡错，是全局 instructions.jsonl 仍是 ARM 误解码：
 *      它把 0x2a6ff0 记成 svcmi / 0x2a6ff1 这类假指令，而本卡写的是真 Thumb-2（push.w 等）。
 *    · 同一份输出里 addresses_claimed_by_two_cards 从 0 涨到 298 —— 全部是**本卡与
 *      cards/anon_2a7e2c_group.c 的区间重叠**（旧卡覆盖 0x2a6ff0..0x2a87b0 的那三段）。
 *      旧卡是本次要替代的那张，但按本批规矩"禁改别人的卡"，本卡没有动它 —— **退役 anon_2a7e2c_group.c
 *      这件事必须由卡主/流程来做**，否则全局账会一直显示 1528 WRONG + 298 处重复地址。
 *    修法与顺序：① 用 --thumb 重建全局 instructions.jsonl（--thumb 只对 st_value 为奇数的函数生效）；
 *    ② 退役 anon_2a7e2c_group.c（或把它裁到本卡不覆盖的部分：0x2a7448.. 之间的小函数与
 *    0x2a804c..0x2a87b0 的 8 个 setter）；③ 重跑 verify_reverse_v1.py。本批约束禁止重跑
 *    asm_index.py，故 ①② 都没做。
 * 10. row_buf(+0x1b0) 与 +0x2f4 / +0x330 三块缓冲的所有权关系未定：read_destroy 只 free 了
 *     prev_row(+0x1ac) 与 +0x2f4/+0x330，row_buf 一个字节也不 free；它在 read_row 里被 inflate
 *     直接写（next_out），若它落在 +0x2f4 那块大缓冲内部，则"不 free"是对的，但本卡没有找到
 *     设置 row_buf 的那条指令（png_read_start_row 未开卡）来证明这一点。
 */

