/* cally 逆向卡：anon_21362c / anon_2d49b8 / anon_153710 / anon_230674
 *（原版 libyoyo.so，ELF32 ARM，stripped）
 *
 * @card  0x21362c..0x2140d4（2,732 B / 683 字）+ 0x2d49b8..0x2d4fb8（1,540 B / 385 字）
 *         + 0x153710..0x153be0（1,240 B / 309 字）+ 0x230674..0x230b64（1,268 B / 317 字）
 *         四段互不相邻，合计 6,780 B / 1,694 条锚点
 * 来源:  libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f841d3910c11f05985bcaecc6bc0fbe3a
 *        （4,689,844 B，ELF32 ARM，stripped，.text 0xb6fd0..0x31bb7c）
 * 锚表:  asm/index-anon_21362c.tsv(683) / index-anon_2d49b8.tsv(385) / index-anon_153710.tsv(309)
 *        / index-anon_230674.tsv(317)；全部由 scripts/asm_index.py --so libyoyo.so --start --end
 *        生成（ARM triple，未加 --thumb；四段首条指令都是 ARM 自洽的 ldr/push 或 push/sub 序列，
 *        且与 asm/instructions.jsonl 的助记符逐地址相同；不是 a7e2c 那类 Thumb 位问题）。
 * 级别:  骨架（锚点全覆盖、逐字一致；语义只钉到顶部——四段各是什么、子函数边界、调用契约、关键
 *        字段偏移与常量；函数体内部按 objdump 原文逐条列出，不逐条解释）
 *
 * ══ 一句话结论 ═══════════════════════════════════════════════════════
 *   四段都不是游戏逻辑，是**静态链接进 libyoyo.so 的库代码**，靠"谁调它 + 常量表 + RTTI +
 *   全局槽 + 错误码"定名，四段的证据互相独立：
 *
 *     匿名段        尺寸    真实指令  身份
 *     anon_21362c  2732 B   683      MD5Transform(u32 state[4], const u8 block[64]) —— MD5 单块压缩
 *     anon_2d49b8  1540 B   382      std::sort<b2ParticleSystem::Proxy*> 的 libstdc++ 排序内核
 *                                    ＋ b2QueryCallback 删除析构的三份 TU 内弱副本
 *     anon_153710  1240 B   293      IAP（Billing）请求「提交器 + 执行器」两段式管道
 *     anon_230674  1268 B   317      vorbisfile 的 _bisect_forward_serialno（链式流二分定位，递归）
 *
 *   四段为什么被记成匿名：.dynsym 里都没有对应符号，而它们又都**紧贴某个具名函数的尾部或夹在
 *   具名函数之间**。objdump 按"最近的前驱符号"给标签，于是反汇编里分别显示成
 *   `_Z7LoadCSVPc+0x104` / `_ZN15b2QueryCallbackD0Ev+0x28` / `_Z16InitIAPFunctionsv+0x23c` /
 *   `vorbis_packet_blocksize+0x9f8` —— **那是前驱符号的偏移，不是它自己的名字**。
 *
 * ══ 计数口径（写死，便于复核）═══════════════════════════════════════
 *   区段          index 行   literal pool 字   真实指令   入口       收尾
 *   anon_21362c     683          0              683    0x21362c   0x2140d4 bx lr
 *   anon_2d49b8     385          3              382    0x2d49b8   0x2d4fb8 b 0x2d4f40
 *   anon_153710     309         16              293    0x153710   0x153be0（尾 4 B 是 0 填充）
 *   anon_230674     317          0              317    0x230674   0x230b64 b 0x230858
 *   —— index 行 = asm_index.py 对 [start,end) 的 4 B 栅格输出；"literal pool 字" 是 objdump 把
 *      数据字译成的伪指令，卡里保留原文并按 README 规矩 3 标"非指令"。
 *   —— functions.tsv 的 size 列比 [end) 多算到 4 B 对齐（2732 = 683×4、1540 = 385×4、
 *      1240 = 310×4、1268 = 317×4），所以 0x153710 的末 4 B 是池字、0x153be4 是 0 填充。
 *
 * ══ 与并行任务的分工（2026-10-28 17:19 复核）═════════════════════════
 *   cards/anon_batch2.c（另一并行任务，写于 17:18）覆盖 25bbb0 / 25c2f8 / 25ceac / 25db38 /
 *   230048 / 230334 / 28b3fc / 2b3f58 / 2bdb14 / 2bb3c4 共 10 段，**不含本卡任何地址**。
 *   本卡与它零交集（verify_reverse_v1 的 addresses_claimed_by_two_cards 里没有本卡地址）；
 *   230674 与它的 230334 首尾相接（0x230334+832 = 0x230674），是同一匿名大块 0x22fd0c 的两个
 *   相邻切块，不是同一函数。本卡曾为它让出 0x21362c，17:18 复核它已移出该段，故收回。
 *
 * ══ claims 对照 ═══════════════════════════════════════════════════════
 *   claims-batchBQ.jsonl: BQB3-001..BQB3-013（proven 11 / narrowed 2）
 * ════════════════════════════════════════════════════════════════════ */

/* ═══════════════════════════════════════════════════════════════════════
 * §1  anon_21362c = MD5Transform：MD5 的单块压缩函数（64 步全展开）
 * ═══════════════════════════════════════════════════════════════════════
 *
 * 身份证据（四条独立，任一条单独成立都不够，合起来闭合）
 *   ① 调用者具名：0x2141bc(MD5Update 0x214118) 与 0x21424c(MD5Final 0x214250 区) 各有一条 bl
 *      落进本段；上一函数 0x2140d8 是 MD5Init，三者同属 MD5 组。
 *   ② 入口契约与 MD5_CTX 完全对齐：r0 只读/写 +0/+4/+8/+0xc 四个字，r1 只读 +0..+0x3c 十六个字。
 *      MD5Init(0x2140d8) 把 0x67452301/0xefcdab89/0x98badcfe/0x10325476 写进 ctx+8..ctx+0x14，
 *      MD5Update 在 0x214148 取 r6 = ctx+8，0x214158/0x214150 维护 ctx+0/+4 的 bit 计数，
 *      0x2141b4 mov r0,r6 → **r0 = &ctx->state[0]**；0x2141b8 mov r1,sp → r1 = 64 B 块缓冲。
 *      即 MD5_CTX = {u32 count[2]; u32 state[4]; u8 buffer[64]}（88 B），本段签名
 *      void anon_21362c(u32 state[4], const u8 block[64])。
 *   ③ 常量表：63 个 movw/movt 常量对，命中 MD5 的 T 表前八项 0xd76aa478(0x213630+0x213640)、
 *      0xe8c7b756(0x213648+0x213650)、0x242070db(0x2136a8+0x2136ac)、0xc1bdceee(0x2136cc+0x2136d0)、
 *      0xf57c0faf / 0x4787c62a / 0xa8304613 / 0xfd469501 全部在场。
 *   ④ 轮次结构：64 条 `add rX, rY, rZ, ror #imm` 一步一条，imm 集合正好是 {25,20,15,10 / 27,23,18,12 /
 *      28,21,16,9 / 26,22,17,11} = 32 减 MD5 的 {7,12,17,22 / 5,9,14,20 / 4,11,16,23 / 6,10,15,21}；
 *      第 17/33/49 步的首个 ror 分别是 #27/#28/#26（= 轮 2/3/4 的首个移位量 5/4/6）。
 *      三步分界落在 0x21395c / 0x213c18 / 0x213e8c，本卡用块注释标出。
 *   ⑤ 叶子：push {r4-r11} **不存 lr**，全段无 bl/blx，唯一的出口是 0x2140d4 bx lr —— 不可能调人。
 *
 * 结构（683 字，无循环、无分支回边，全直线）
 *   0x21362c..0x213658  序言：M[0] 预取→溢出→取回；state[0..3] 装进 r9/r6/r7/r5；T[0]/T[1] 装 r2/r12
 *   0x21365c..0x213934  轮 1，16 步，F(x,y,z) = (x&y)|(~x&z)，用 bic/and/orr（0x21365c 起）
 *   0x21395c..0x213bf4  轮 2，16 步，G(x,y,z) = (x&z)|(y&~z)，移位数 5/9/14/20
 *   0x213c18..0x213e64  轮 3，16 步，H = x^y^z，48 条 eor（16 步 × 3）
 *   0x213e8c..0x2140c4  轮 4，16 步，I = y^(x|~z)，每步 1 条 mvn + 1 条 eor
 *   0x214080..0x2140c8  四次 str 回写 state（+0/+0xc/+8/+4 次序），0x2140cc add sp,#0x48、
 *                       0x2140d0 pop {r4-r11}、0x2140d4 bx lr
 *   栈帧 0x48：只用到 sp+0x14（M[0] 的溢出槽），其余 64 B 未碰 —— 因为整轮不调用、不需要保存上下文。
 *
 * 与"另一个解释"的区分：不是 SHA-1（无 5 字状态、无 0x5a827999/0x6ed9eba1 常量）、不是 CRC（无查表）。
 * 唯一疑点：64 步要 64 个 T 常量，movw/movt 只有 63 对 —— 少的那一项是被相邻步共用了同一个常量
 * 寄存器（同一 T 值只装一次），不影响轮数与身份判断，见 open 1。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x21362c 0x2140d4 anon_21362c md5_transform_block */
/* ---- 序言：M[0] 预取、state[0..3] 入寄存器、T[0]/T[1] 常量 ----
 * 契约：r0 = u32 state[4]（= MD5_CTX+8），r1 = const u8 block[64]；返回 void，原地改 state。
 *   0x21362c ldr r3,[r1]        先取 M[0]，编译器把这次装载提到序言之前（不算"越界"，r1 已就绪）
 *   0x213634 push {r4-r11}      不存 lr → 全函数无调用
 *   0x213638 sub sp,#0x48       帧 72 B，但只用 sp+0x14 一个槽
 *   0x21363c/0x21364c/0x213654/0x213660  state[1]/state[3]/state[2]/state[0] → r6/r5/r7/r9
 *   0x213644→0x213658  M[0] 溢出到 sp+0x14 再取回 r8（寄存器压力，不是语义）
 *   0x213630+0x213640 r2 = T[1] = 0xd76aa478；0x213648+0x213650 r12 = T[2] = 0xe8c7b756 */
/* @0x21362c ldr r3, [r1] */
/* @0x213630 movw r2, #0xa478 */
/* @0x213634 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x213638 sub sp, sp, #72 */
/* @0x21363c ldr r6, [r0, #0x4] */
/* @0x213640 movt r2, #0xd76a */
/* @0x213644 str r3, [sp, #0x14] */
/* @0x213648 movw r12, #0xb756 */
/* @0x21364c ldr r5, [r0, #0xc] */
/* @0x213650 movt r12, #0xe8c7 */
/* @0x213654 ldr r7, [r0, #0x8] */
/* @0x213658 ldr r8, [sp, #0x14] */
/* ---- 轮 1 第 1 步：F(x,y,z) = (x&y) | (~x&z)，用 bic+and+orr 三指令组合 ----
 * r4 = r5 & ~r6（bic r4,r5,r6）、r3 = r7 & r6、orr → F 值；0x213670 加 state[0]、0x213678 加 T[1]，
 * 0x213688 `add r3, r6, r3, ror #25` 即 a = b + rol(tmp,7)（ror #25 = 32-7）。一步到此结束。 */
/* @0x21365c bic r4, r5, r6 */
/* @0x213660 ldr r9, [r0] */
/* @0x213664 and r3, r7, r6 */
/* @0x213668 add r2, r8, r2 */
/* @0x21366c orr r3, r4, r3 */
/* @0x213670 add r2, r2, r9 */
/* @0x213674 ldr r10, [r1, #0x4] */
/* @0x213678 add r3, r2, r3 */
/* @0x21367c ldr r11, [r1, #0x8] */
/* @0x213680 add r12, r10, r12 */
/* @0x213684 ldr r4, [r0, #0x8] */
/* @0x213688 add r3, r6, r3, ror #25 —— 第 1/64 步 · 轮 1 · F · a=b+rol(tmp,7) */
/* @0x21368c add r12, r12, r5 */
/* @0x213690 bic r7, r7, r3 */
/* @0x213694 and r2, r3, r6 */
/* @0x213698 orr r2, r7, r2 */
/* @0x21369c ldr r5, [r0, #0x4] */
/* @0x2136a0 add r12, r12, r2 */
/* @0x2136a4 ldr r2, [r1, #0xc] */
/* @0x2136a8 movw r6, #0x70db */
/* @0x2136ac movt r6, #0x2420 */
/* @0x2136b0 add r12, r3, r12, ror #20 —— 第 2/64 步 · 轮 1 · F · a=b+rol(tmp,12) */
/* @0x2136b4 add r6, r11, r6 */
/* @0x2136b8 str r2, [sp, #0x20] */
/* @0x2136bc add r6, r6, r4 */
/* @0x2136c0 and r2, r12, r3 */
/* @0x2136c4 bic r4, r5, r12 */
/* @0x2136c8 orr r4, r4, r2 */
/* @0x2136cc movw r7, #0xceee */
/* @0x2136d0 add r4, r6, r4 */
/* @0x2136d4 ldr r6, [sp, #0x20] */
/* @0x2136d8 movt r7, #0xc1bd */
/* @0x2136dc ldr r8, [r1, #0x10] */
/* @0x2136e0 add r4, r12, r4, ror #15 —— 第 3/64 步 · 轮 1 · F · a=b+rol(tmp,17) */
/* @0x2136e4 add r7, r6, r7 */
/* @0x2136e8 add r7, r7, r5 */
/* @0x2136ec and r2, r4, r12 */
/* @0x2136f0 bic r5, r3, r4 */
/* @0x2136f4 ldr r9, [r1, #0x14] */
/* @0x2136f8 orr r2, r5, r2 */
/* @0x2136fc movw r5, #0xfaf */
/* @0x213700 add r2, r7, r2 */
/* @0x213704 movt r5, #0xf57c */
/* @0x213708 add r5, r8, r5 */
/* @0x21370c movw r7, #0xc62a */
/* @0x213710 add r2, r4, r2, ror #10 —— 第 4/64 步 · 轮 1 · F · a=b+rol(tmp,22) */
/* @0x213714 add r3, r5, r3 */
/* @0x213718 bic r6, r12, r2 */
/* @0x21371c and r5, r2, r4 */
/* @0x213720 orr r5, r6, r5 */
/* @0x213724 movt r7, #0x4787 */
/* @0x213728 add r5, r3, r5 */
/* @0x21372c add r7, r9, r7 */
/* @0x213730 add r7, r7, r12 */
/* @0x213734 str r10, [sp, #0x18] */
/* @0x213738 add r5, r2, r5, ror #25 —— 第 5/64 步 · 轮 1 · F · a=b+rol(tmp,7) */
/* @0x21373c ldr r10, [r1, #0x18] */
/* @0x213740 and r3, r5, r2 */
/* @0x213744 bic r12, r4, r5 */
/* @0x213748 orr r12, r12, r3 */
/* @0x21374c movw r6, #0x4613 */
/* @0x213750 add r12, r7, r12 */
/* @0x213754 movt r6, #0xa830 */
/* @0x213758 add r6, r10, r6 */
/* @0x21375c str r11, [sp, #0x1c] */
/* @0x213760 add r12, r5, r12, ror #20 —— 第 6/64 步 · 轮 1 · F · a=b+rol(tmp,12) */
/* @0x213764 add r4, r6, r4 */
/* @0x213768 and r3, r12, r5 */
/* @0x21376c bic r6, r2, r12 */
/* @0x213770 orr r6, r6, r3 */
/* @0x213774 ldr r11, [r1, #0x1c] */
/* @0x213778 ldr r3, [r1, #0x20] */
/* @0x21377c add r6, r4, r6 */
/* @0x213780 movw r7, #0x9501 */
/* @0x213784 movt r7, #0xfd46 */
/* @0x213788 add r6, r12, r6, ror #15 —— 第 7/64 步 · 轮 1 · F · a=b+rol(tmp,17) */
/* @0x21378c add r7, r11, r7 */
/* @0x213790 str r3, [sp, #0x34] */
/* @0x213794 add r7, r7, r2 */
/* @0x213798 and r3, r6, r12 */
/* @0x21379c bic r2, r5, r6 */
/* @0x2137a0 orr r2, r2, r3 */
/* @0x2137a4 ldr r4, [sp, #0x34] */
/* @0x2137a8 add r2, r7, r2 */
/* @0x2137ac movw r3, #0x98d8 */
/* @0x2137b0 ldr r7, [r1, #0x24] */
/* @0x2137b4 movt r3, #0x6980 */
/* @0x2137b8 add r2, r6, r2, ror #10 —— 第 8/64 步 · 轮 1 · F · a=b+rol(tmp,22) */
/* @0x2137bc add r3, r4, r3 */
/* @0x2137c0 add r5, r3, r5 */
/* @0x2137c4 bic r4, r12, r2 */
/* @0x2137c8 and r3, r2, r6 */
/* @0x2137cc str r7, [sp, #0x38] */
/* @0x2137d0 orr r4, r4, r3 */
/* @0x2137d4 str r8, [sp, #0x24] */
/* @0x2137d8 add r5, r5, r4 */
/* @0x2137dc ldr r8, [sp, #0x38] */
/* @0x2137e0 movw r7, #0xf7af */
/* @0x2137e4 movt r7, #0x8b44 */
/* @0x2137e8 add r5, r2, r5, ror #25 —— 第 9/64 步 · 轮 1 · F · a=b+rol(tmp,7) */
/* @0x2137ec add r7, r8, r7 */
/* @0x2137f0 and r3, r5, r2 */
/* @0x2137f4 add r7, r7, r12 */
/* @0x2137f8 bic r12, r6, r5 */
/* @0x2137fc str r9, [sp, #0x28] */
/* @0x213800 orr r12, r12, r3 */
/* @0x213804 ldr r9, [r1, #0x28] */
/* @0x213808 add r12, r7, r12 */
/* @0x21380c str r10, [sp, #0x2c] */
/* @0x213810 sub r4, r9, #41984 */
/* @0x213814 ldr r10, [r1, #0x2c] */
/* @0x213818 add r12, r5, r12, ror #20 —— 第 10/64 步 · 轮 1 · F · a=b+rol(tmp,12) */
/* @0x21381c sub r4, r4, #79 */
/* @0x213820 add r4, r4, r6 */
/* @0x213824 and r3, r12, r5 */
/* @0x213828 bic r6, r2, r12 */
/* @0x21382c movw r7, #0xd7be */
/* @0x213830 orr r3, r6, r3 */
/* @0x213834 movt r7, #0x895c */
/* @0x213838 add r3, r4, r3 */
/* @0x21383c str r11, [sp, #0x30] */
/* @0x213840 str r9, [sp, #0x3c] */
/* @0x213844 add r7, r10, r7 */
/* @0x213848 str r10, [sp, #0x40] */
/* @0x21384c add r3, r12, r3, ror #15 —— 第 11/64 步 · 轮 1 · F · a=b+rol(tmp,17) */
/* @0x213850 ldr r4, [r1, #0x30] */
/* @0x213854 bic r6, r5, r3 */
/* @0x213858 add r7, r7, r2 */
/* @0x21385c movw r11, #0x1122 */
/* @0x213860 and r2, r3, r12 */
/* @0x213864 movt r11, #0x6b90 */
/* @0x213868 add r11, r4, r11 */
/* @0x21386c orr r2, r6, r2 */
/* @0x213870 add r5, r11, r5 */
/* @0x213874 add r2, r7, r2 */
/* @0x213878 ldr r11, [r1, #0x34] */
/* @0x21387c movw r7, #0x7193 */
/* @0x213880 add r2, r3, r2, ror #10 —— 第 12/64 步 · 轮 1 · F · a=b+rol(tmp,22) */
/* @0x213884 movt r7, #0xfd98 */
/* @0x213888 and r6, r2, r3 */
/* @0x21388c str r11, [sp, #0x44] */
/* @0x213890 bic r11, r12, r2 */
/* @0x213894 orr r11, r11, r6 */
/* @0x213898 movw r6, #0x438e */
/* @0x21389c add r11, r5, r11 */
/* @0x2138a0 ldr r5, [sp, #0x44] */
/* @0x2138a4 movt r6, #0xa679 */
/* @0x2138a8 add r11, r2, r11, ror #25 —— 第 13/64 步 · 轮 1 · F · a=b+rol(tmp,7) */
/* @0x2138ac add r7, r5, r7 */
/* @0x2138b0 bic r8, r3, r11 */
/* @0x2138b4 add r12, r7, r12 */
/* @0x2138b8 and r7, r11, r2 */
/* @0x2138bc ldr r5, [r1, #0x38] */
/* @0x2138c0 orr r7, r8, r7 */
/* @0x2138c4 add r7, r12, r7 */
/* @0x2138c8 add r6, r5, r6 */
/* @0x2138cc add r3, r6, r3 */
/* @0x2138d0 ldr r12, [r1, #0x3c] */
/* @0x2138d4 add r7, r11, r7, ror #20 —— 第 14/64 步 · 轮 1 · F · a=b+rol(tmp,12) */
/* @0x2138d8 movw r1, #0x821 */
/* @0x2138dc and r6, r7, r11 */
/* @0x2138e0 movt r1, #0x49b4 */
/* @0x2138e4 mvn r8, r7 */
/* @0x2138e8 and r9, r8, r2 */
/* @0x2138ec orr r6, r9, r6 */
/* @0x2138f0 ldr r9, [sp, #0x18] */
/* @0x2138f4 add r6, r3, r6 */
/* @0x2138f8 add r1, r12, r1 */
/* @0x2138fc movw r3, #0x2562 */
/* @0x213900 movt r3, #0xf61e */
/* @0x213904 add r6, r7, r6, ror #15 —— 第 15/64 步 · 轮 1 · F · a=b+rol(tmp,17) */
/* @0x213908 add r1, r1, r2 */
/* @0x21390c add r3, r9, r3 */
/* @0x213910 and r2, r6, r7 */
/* @0x213914 mvn r10, r6 */
/* @0x213918 and r9, r10, r11 */
/* @0x21391c orr r2, r9, r2 */
/* @0x213920 add r11, r3, r11 */
/* @0x213924 add r2, r1, r2 */
/* @0x213928 ldr r3, [sp, #0x2c] */
/* @0x21392c movw r9, #0xb340 */
/* @0x213930 movt r9, #0xc040 */
/* @0x213934 add r2, r6, r2, ror #10 —— 第 16/64 步 · 轮 1 · F · a=b+rol(tmp,22) */
/* @0x213938 and r8, r6, r8 */
/* @0x21393c add r9, r3, r9 */
/* @0x213940 and r3, r2, r7 */
/* @0x213944 orr r3, r3, r8 */
/* @0x213948 ldr r8, [sp, #0x40] */
/* @0x21394c add r3, r11, r3 */
/* @0x213950 movw r1, #0x5a51 */
/* @0x213954 movt r1, #0x265e */
/* @0x213958 and r10, r2, r10 */
/* ---- 轮 1 结束 / 轮 2 开始（第 17 步）----
 * 移位量集合从 {7,12,17,22} 换成 {5,9,14,20}，故 ror 立即数变成 {27,23,18,12}：本步 ror #27 = 32-5。
 * 混合函数从 F 换成 G = (x&z) | (y&~z)：下面的 bic/and/orr 操作数次序也随之换位。 */
/* @0x21395c add r3, r2, r3, ror #27 —— 第 17/64 步 · 轮 2 · G · a=b+rol(tmp,5) */
/* @0x213960 add r1, r8, r1 */
/* @0x213964 add r1, r1, r6 */
/* @0x213968 and r6, r3, r6 */
/* @0x21396c orr r6, r6, r10 */
/* @0x213970 add r7, r9, r7 */
/* @0x213974 ldr r10, [sp, #0x14] */
/* @0x213978 add r7, r7, r6 */
/* @0x21397c movw r11, #0xc7aa */
/* @0x213980 movt r11, #0xe9b6 */
/* @0x213984 add r8, r3, r7, ror #23 —— 第 18/64 步 · 轮 2 · G · a=b+rol(tmp,9) */
/* @0x213988 add r11, r10, r11 */
/* @0x21398c bic r9, r3, r2 */
/* @0x213990 add r11, r11, r2 */
/* @0x213994 and r2, r8, r2 */
/* @0x213998 movw r6, #0x105d */
/* @0x21399c orr r2, r2, r9 */
/* @0x2139a0 ldr r9, [sp, #0x28] */
/* @0x2139a4 add r1, r1, r2 */
/* @0x2139a8 movt r6, #0xd62f */
/* @0x2139ac add r6, r9, r6 */
/* @0x2139b0 bic r7, r8, r3 */
/* @0x2139b4 add r1, r8, r1, ror #18 —— 第 19/64 步 · 轮 2 · G · a=b+rol(tmp,14) */
/* @0x2139b8 add r9, r6, r3 */
/* @0x2139bc and r3, r1, r3 */
/* @0x2139c0 ldr r10, [sp, #0x3c] */
/* @0x2139c4 orr r7, r3, r7 */
/* @0x2139c8 movw r2, #0x1453 */
/* @0x2139cc add r7, r11, r7 */
/* @0x2139d0 movt r2, #0x244 */
/* @0x2139d4 add r2, r10, r2 */
/* @0x2139d8 bic r6, r1, r8 */
/* @0x2139dc add r7, r1, r7, ror #12 —— 第 20/64 步 · 轮 2 · G · a=b+rol(tmp,20) */
/* @0x2139e0 add r2, r2, r8 */
/* @0x2139e4 and r8, r7, r8 */
/* @0x2139e8 movw r3, #0xe681 */
/* @0x2139ec orr r6, r8, r6 */
/* @0x2139f0 movt r3, #0xd8a1 */
/* @0x2139f4 add r6, r9, r6 */
/* @0x2139f8 add r3, r12, r3 */
/* @0x2139fc bic r11, r7, r1 */
/* @0x213a00 add r3, r3, r1 */
/* @0x213a04 add r6, r7, r6, ror #27 —— 第 21/64 步 · 轮 2 · G · a=b+rol(tmp,5) */
/* @0x213a08 ldr r8, [sp, #0x24] */
/* @0x213a0c and r1, r6, r1 */
/* @0x213a10 movw r10, #0xfbc8 */
/* @0x213a14 orr r1, r1, r11 */
/* @0x213a18 movt r10, #0xe7d3 */
/* @0x213a1c add r2, r2, r1 */
/* @0x213a20 add r10, r8, r10 */
/* @0x213a24 bic r11, r6, r7 */
/* @0x213a28 add r10, r10, r7 */
/* @0x213a2c add r2, r6, r2, ror #23 —— 第 22/64 步 · 轮 2 · G · a=b+rol(tmp,9) */
/* @0x213a30 ldr r1, [sp, #0x38] */
/* @0x213a34 and r7, r2, r7 */
/* @0x213a38 movw r9, #0xcde6 */
/* @0x213a3c orr r7, r7, r11 */
/* @0x213a40 movt r9, #0x21e1 */
/* @0x213a44 add r3, r3, r7 */
/* @0x213a48 add r9, r1, r9 */
/* @0x213a4c add r9, r9, r6 */
/* @0x213a50 bic r11, r2, r6 */
/* @0x213a54 add r3, r2, r3, ror #18 —— 第 23/64 步 · 轮 2 · G · a=b+rol(tmp,14) */
/* @0x213a58 ldr r1, [sp, #0x20] */
/* @0x213a5c and r6, r3, r6 */
/* @0x213a60 movw r8, #0x7d6 */
/* @0x213a64 orr r11, r6, r11 */
/* @0x213a68 movt r8, #0xc337 */
/* @0x213a6c add r11, r10, r11 */
/* @0x213a70 add r8, r5, r8 */
/* @0x213a74 movw r7, #0xd87 */
/* @0x213a78 movt r7, #0xf4d5 */
/* @0x213a7c add r11, r3, r11, ror #12 —— 第 24/64 步 · 轮 2 · G · a=b+rol(tmp,20) */
/* @0x213a80 add r8, r8, r2 */
/* @0x213a84 add r7, r1, r7 */
/* @0x213a88 bic r1, r3, r2 */
/* @0x213a8c and r2, r11, r2 */
/* @0x213a90 add r7, r7, r3 */
/* @0x213a94 orr r2, r2, r1 */
/* @0x213a98 bic r1, r11, r3 */
/* @0x213a9c add r2, r9, r2 */
/* @0x213aa0 ldr r9, [sp, #0x44] */
/* @0x213aa4 movw r10, #0xe905 */
/* @0x213aa8 movt r10, #0xa9e3 */
/* @0x213aac add r2, r11, r2, ror #27 —— 第 25/64 步 · 轮 2 · G · a=b+rol(tmp,5) */
/* @0x213ab0 str r7, [sp, #0x10] */
/* @0x213ab4 and r3, r2, r3 */
/* @0x213ab8 ldr r7, [sp, #0x34] */
/* @0x213abc orr r3, r3, r1 */
/* @0x213ac0 add r10, r9, r10 */
/* @0x213ac4 add r3, r8, r3 */
/* @0x213ac8 add r10, r10, r2 */
/* @0x213acc movw r6, #0x14ed */
/* @0x213ad0 str r10, [sp, #0xc] */
/* @0x213ad4 movt r6, #0x455a */
/* @0x213ad8 ldr r10, [sp, #0x1c] */
/* @0x213adc add r3, r2, r3, ror #23 —— 第 26/64 步 · 轮 2 · G · a=b+rol(tmp,9) */
/* @0x213ae0 add r6, r7, r6 */
/* @0x213ae4 movw r9, #0xa3f8 */
/* @0x213ae8 movt r9, #0xfcef */
/* @0x213aec add r6, r6, r11 */
/* @0x213af0 bic r1, r2, r11 */
/* @0x213af4 add r9, r10, r9 */
/* @0x213af8 and r11, r3, r11 */
/* @0x213afc ldr r10, [sp, #0x10] */
/* @0x213b00 orr r1, r11, r1 */
/* @0x213b04 bic r11, r3, r2 */
/* @0x213b08 ldr r7, [sp, #0x30] */
/* @0x213b0c add r1, r10, r1 */
/* @0x213b10 movw r8, #0x2d9 */
/* @0x213b14 movt r8, #0x676f */
/* @0x213b18 add r9, r9, r3 */
/* @0x213b1c add r1, r3, r1, ror #18 —— 第 27/64 步 · 轮 2 · G · a=b+rol(tmp,14) */
/* @0x213b20 add r8, r7, r8 */
/* @0x213b24 and r2, r1, r2 */
/* @0x213b28 movw r7, #0x4c8a */
/* @0x213b2c orr r2, r2, r11 */
/* @0x213b30 movt r7, #0x8d2a */
/* @0x213b34 add r2, r6, r2 */
/* @0x213b38 add r7, r4, r7 */
/* @0x213b3c bic r11, r1, r3 */
/* @0x213b40 add r8, r8, r1 */
/* @0x213b44 add r2, r1, r2, ror #12 —— 第 28/64 步 · 轮 2 · G · a=b+rol(tmp,20) */
/* @0x213b48 ldr r10, [sp, #0x28] */
/* @0x213b4c add r7, r7, r2 */
/* @0x213b50 and r3, r2, r3 */
/* @0x213b54 str r7, [sp, #0x10] */
/* @0x213b58 orr r3, r3, r11 */
/* @0x213b5c ldr r7, [sp, #0xc] */
/* @0x213b60 bic r11, r2, r1 */
/* @0x213b64 movw r6, #0x3942 */
/* @0x213b68 movt r6, #0xfffa */
/* @0x213b6c add r3, r7, r3 */
/* @0x213b70 ldr r7, [sp, #0x34] */
/* @0x213b74 add r6, r10, r6 */
/* @0x213b78 movw r10, #0xf681 */
/* @0x213b7c add r3, r2, r3, ror #27 —— 第 29/64 步 · 轮 2 · G · a=b+rol(tmp,5) */
/* @0x213b80 movt r10, #0x8771 */
/* @0x213b84 and r1, r3, r1 */
/* @0x213b88 add r10, r7, r10 */
/* @0x213b8c orr r1, r1, r11 */
/* @0x213b90 bic r11, r3, r2 */
/* @0x213b94 add r9, r9, r1 */
/* @0x213b98 add r6, r6, r3 */
/* @0x213b9c str r6, [sp, #0xc] */
/* @0x213ba0 movw r1, #0x6122 */
/* @0x213ba4 add r9, r3, r9, ror #23 —— 第 30/64 步 · 轮 2 · G · a=b+rol(tmp,9) */
/* @0x213ba8 ldr r6, [sp, #0x40] */
/* @0x213bac and r2, r9, r2 */
/* @0x213bb0 add r10, r10, r9 */
/* @0x213bb4 orr r2, r2, r11 */
/* @0x213bb8 str r10, [sp, #0x8] */
/* @0x213bbc add r8, r8, r2 */
/* @0x213bc0 bic r11, r9, r3 */
/* @0x213bc4 ldr r10, [sp, #0x10] */
/* @0x213bc8 movt r1, #0x6d9d */
/* @0x213bcc add r8, r9, r8, ror #18 —— 第 31/64 步 · 轮 2 · G · a=b+rol(tmp,14) */
/* @0x213bd0 add r1, r6, r1 */
/* @0x213bd4 and r3, r8, r3 */
/* @0x213bd8 add r1, r1, r8 */
/* @0x213bdc orr r3, r3, r11 */
/* @0x213be0 str r1, [sp, #0x4] */
/* @0x213be4 add r7, r10, r3 */
/* @0x213be8 ldr r1, [sp, #0x18] */
/* @0x213bec ldr r10, [sp, #0xc] */
/* @0x213bf0 eor r9, r8, r9 */
/* @0x213bf4 add r7, r8, r7, ror #12 —— 第 32/64 步 · 轮 2 · G · a=b+rol(tmp,20) */
/* @0x213bf8 movw r3, #0xea44 */
/* @0x213bfc eor r9, r9, r7 */
/* @0x213c00 movt r3, #0xa4be */
/* @0x213c04 add r6, r10, r9 */
/* @0x213c08 add r3, r1, r3 */
/* @0x213c0c ldr r1, [sp, #0x24] */
/* @0x213c10 movw r11, #0xcfa9 */
/* @0x213c14 movt r11, #0x4bde */
/* ---- 轮 2 结束 / 轮 3 开始（第 33 步）----
 * 移位量 {4,11,16,23} → ror #28 = 32-4；混合函数 H = x^y^z，此后每步出现 3 条 eor
 * （全函数 48 条 eor = 轮 3 的 16×3 与轮 4 的 16×1 之和的另一半，0x213c 区开始集中出现）。 */
/* @0x213c18 add r6, r7, r6, ror #28 —— 第 33/64 步 · 轮 3 · H · a=b+rol(tmp,4) */
/* @0x213c1c eor r8, r7, r8 */
/* @0x213c20 add r11, r1, r11 */
/* @0x213c24 ldr r1, [sp, #0x8] */
/* @0x213c28 eor r8, r8, r6 */
/* @0x213c2c movw r2, #0x380c */
/* @0x213c30 movt r2, #0xfde5 */
/* @0x213c34 add r2, r5, r2 */
/* @0x213c38 add r10, r1, r8 */
/* @0x213c3c add r3, r3, r6 */
/* @0x213c40 str r3, [sp, #0xc] */
/* @0x213c44 ldr r8, [sp, #0x30] */
/* @0x213c48 add r9, r2, r7 */
/* @0x213c4c movw r2, #0x4b60 */
/* @0x213c50 movt r2, #0xf6bb */
/* @0x213c54 add r10, r6, r10, ror #21 —— 第 34/64 步 · 轮 3 · H · a=b+rol(tmp,11) */
/* @0x213c58 eor r7, r6, r7 */
/* @0x213c5c add r2, r8, r2 */
/* @0x213c60 ldr r8, [sp, #0x4] */
/* @0x213c64 eor r7, r7, r10 */
/* @0x213c68 eor r6, r10, r6 */
/* @0x213c6c add r1, r8, r7 */
/* @0x213c70 ldr r7, [sp, #0x3c] */
/* @0x213c74 movw r3, #0xbc70 */
/* @0x213c78 movt r3, #0xbebf */
/* @0x213c7c add r1, r10, r1, ror #16 —— 第 35/64 步 · 轮 3 · H · a=b+rol(tmp,16) */
/* @0x213c80 add r11, r11, r10 */
/* @0x213c84 eor r6, r6, r1 */
/* @0x213c88 add r3, r7, r3 */
/* @0x213c8c add r6, r9, r6 */
/* @0x213c90 ldr r7, [sp, #0xc] */
/* @0x213c94 eor r10, r1, r10 */
/* @0x213c98 str r11, [sp, #0x10] */
/* @0x213c9c add r6, r1, r6, ror #9 —— 第 36/64 步 · 轮 3 · H · a=b+rol(tmp,23) */
/* @0x213ca0 add r2, r2, r1 */
/* @0x213ca4 eor r10, r10, r6 */
/* @0x213ca8 eor r1, r6, r1 */
/* @0x213cac add r10, r7, r10 */
/* @0x213cb0 ldr r7, [sp, #0x10] */
/* @0x213cb4 add r3, r3, r6 */
/* @0x213cb8 ldr r8, [sp, #0x44] */
/* @0x213cbc add r10, r6, r10, ror #28 —— 第 37/64 步 · 轮 3 · H · a=b+rol(tmp,4) */
/* @0x213cc0 str r3, [sp, #0xc] */
/* @0x213cc4 eor r1, r1, r10 */
/* @0x213cc8 eor r6, r10, r6 */
/* @0x213ccc add r1, r7, r1 */
/* @0x213cd0 ldr r3, [sp, #0x14] */
/* @0x213cd4 movw r11, #0x7ec6 */
/* @0x213cd8 movt r11, #0x289b */
/* @0x213cdc add r1, r10, r1, ror #21 —— 第 38/64 步 · 轮 3 · H · a=b+rol(tmp,11) */
/* @0x213ce0 add r11, r8, r11 */
/* @0x213ce4 eor r6, r6, r1 */
/* @0x213ce8 movw r9, #0x27fa */
/* @0x213cec add r2, r2, r6 */
/* @0x213cf0 ldr r6, [sp, #0x2c] */
/* @0x213cf4 movt r9, #0xeaa1 */
/* @0x213cf8 movw r7, #0x1d05 */
/* @0x213cfc movt r7, #0x488 */
/* @0x213d00 add r2, r1, r2, ror #16 —— 第 39/64 步 · 轮 3 · H · a=b+rol(tmp,16) */
/* @0x213d04 add r11, r11, r10 */
/* @0x213d08 add r7, r6, r7 */
/* @0x213d0c add r9, r3, r9 */
/* @0x213d10 ldr r6, [sp, #0xc] */
/* @0x213d14 ldr r3, [sp, #0x20] */
/* @0x213d18 eor r10, r1, r10 */
/* @0x213d1c eor r10, r10, r2 */
/* @0x213d20 movw r8, #0x3085 */
/* @0x213d24 movt r8, #0xd4ef */
/* @0x213d28 add r9, r9, r1 */
/* @0x213d2c add r8, r3, r8 */
/* @0x213d30 add r3, r6, r10 */
/* @0x213d34 eor r1, r2, r1 */
/* @0x213d38 ldr r6, [sp, #0x38] */
/* @0x213d3c add r3, r2, r3, ror #9 —— 第 40/64 步 · 轮 3 · H · a=b+rol(tmp,23) */
/* @0x213d40 str r9, [sp, #0x10] */
/* @0x213d44 eor r1, r1, r3 */
/* @0x213d48 movw r9, #0xd039 */
/* @0x213d4c add r1, r11, r1 */
/* @0x213d50 movt r9, #0xd9d4 */
/* @0x213d54 add r10, r8, r2 */
/* @0x213d58 add r9, r6, r9 */
/* @0x213d5c add r1, r3, r1, ror #28 —— 第 41/64 步 · 轮 3 · H · a=b+rol(tmp,4) */
/* @0x213d60 ldr r6, [sp, #0x10] */
/* @0x213d64 eor r2, r3, r2 */
/* @0x213d68 add r11, r7, r3 */
/* @0x213d6c eor r2, r2, r1 */
/* @0x213d70 eor r3, r1, r3 */
/* @0x213d74 add r2, r6, r2 */
/* @0x213d78 add r9, r9, r1 */
/* @0x213d7c movw r8, #0x99e5 */
/* @0x213d80 movt r8, #0xe6db */
/* @0x213d84 add r2, r1, r2, ror #21 —— 第 42/64 步 · 轮 3 · H · a=b+rol(tmp,11) */
/* @0x213d88 add r8, r4, r8 */
/* @0x213d8c eor r3, r3, r2 */
/* @0x213d90 eor r1, r2, r1 */
/* @0x213d94 add r3, r10, r3 */
/* @0x213d98 add r8, r8, r2 */
/* @0x213d9c str r8, [sp, #0x10] */
/* @0x213da0 movw r6, #0x5665 */
/* @0x213da4 add r3, r2, r3, ror #16 —— 第 43/64 步 · 轮 3 · H · a=b+rol(tmp,16) */
/* @0x213da8 ldr r8, [sp, #0x1c] */
/* @0x213dac eor r1, r1, r3 */
/* @0x213db0 movt r6, #0xc4ac */
/* @0x213db4 add r1, r11, r1 */
/* @0x213db8 add r6, r8, r6 */
/* @0x213dbc eor r2, r3, r2 */
/* @0x213dc0 ldr r8, [sp, #0x14] */
/* @0x213dc4 add r1, r3, r1, ror #9 —— 第 44/64 步 · 轮 3 · H · a=b+rol(tmp,23) */
/* @0x213dc8 movw r10, #0x2244 */
/* @0x213dcc eor r2, r2, r1 */
/* @0x213dd0 movt r10, #0xf429 */
/* @0x213dd4 add r10, r8, r10 */
/* @0x213dd8 add r2, r9, r2 */
/* @0x213ddc ldr r8, [sp, #0x30] */
/* @0x213de0 movw r7, #0x7cf8 */
/* @0x213de4 movt r7, #0x1fa2 */
/* @0x213de8 movw r11, #0xff97 */
/* @0x213dec add r7, r12, r7 */
/* @0x213df0 movt r11, #0x432a */
/* @0x213df4 add r2, r1, r2, ror #28 —— 第 45/64 步 · 轮 3 · H · a=b+rol(tmp,4) */
/* @0x213df8 add r7, r7, r3 */
/* @0x213dfc add r11, r8, r11 */
/* @0x213e00 eor r3, r1, r3 */
/* @0x213e04 ldr r8, [sp, #0x10] */
/* @0x213e08 eor r3, r3, r2 */
/* @0x213e0c add r9, r6, r1 */
/* @0x213e10 eor r1, r2, r1 */
/* @0x213e14 add r3, r8, r3 */
/* @0x213e18 movw r6, #0x23a7 */
/* @0x213e1c movt r6, #0xab94 */
/* @0x213e20 add r8, r10, r2 */
/* @0x213e24 add r3, r2, r3, ror #21 —— 第 46/64 步 · 轮 3 · H · a=b+rol(tmp,11) */
/* @0x213e28 add r6, r5, r6 */
/* @0x213e2c eor r1, r1, r3 */
/* @0x213e30 eor r2, r3, r2 */
/* @0x213e34 add r1, r7, r1 */
/* @0x213e38 mvn r5, r3 */
/* @0x213e3c add r11, r11, r3 */
/* @0x213e40 movw r10, #0xa039 */
/* @0x213e44 add r3, r3, r1, ror #16 —— 第 47/64 步 · 轮 3 · H · a=b+rol(tmp,16) */
/* @0x213e48 ldr r1, [sp, #0x28] */
/* @0x213e4c eor r2, r2, r3 */
/* @0x213e50 add r6, r6, r3 */
/* @0x213e54 add r9, r9, r2 */
/* @0x213e58 mvn r2, r3 */
/* @0x213e5c movt r10, #0xfc93 */
/* @0x213e60 movw r7, #0x59c3 */
/* @0x213e64 add r9, r3, r9, ror #9 —— 第 48/64 步 · 轮 3 · H · a=b+rol(tmp,23) */
/* @0x213e68 add r10, r1, r10 */
/* @0x213e6c orr r5, r9, r5 */
/* @0x213e70 movw r1, #0xcc92 */
/* @0x213e74 eor r3, r5, r3 */
/* @0x213e78 mvn r5, r9 */
/* @0x213e7c add r8, r8, r3 */
/* @0x213e80 ldr r3, [sp, #0x20] */
/* @0x213e84 movt r1, #0x8f0c */
/* @0x213e88 add r10, r10, r9 */
/* ---- 轮 3 结束 / 轮 4 开始（第 49 步）----
 * 移位量 {6,10,15,21} → ror #26 = 32-6；混合函数 I = y ^ (x | ~z)：每步先 mvn 再 orr/eor，
 * 这是全段唯一出现 mvn 的区（16 条，一一对应 16 步）。 */
/* @0x213e8c add r8, r9, r8, ror #26 —— 第 49/64 步 · 轮 4 · I · a=b+rol(tmp,6) */
/* @0x213e90 add r1, r3, r1 */
/* @0x213e94 orr r2, r8, r2 */
/* @0x213e98 movt r7, #0x655b */
/* @0x213e9c eor r2, r2, r9 */
/* @0x213ea0 mvn r3, r8 */
/* @0x213ea4 add r11, r11, r2 */
/* @0x213ea8 add r7, r4, r7 */
/* @0x213eac add r7, r7, r8 */
/* @0x213eb0 ldr r9, [sp, #0x3c] */
/* @0x213eb4 add r11, r8, r11, ror #22 —— 第 50/64 步 · 轮 4 · I · a=b+rol(tmp,10) */
/* @0x213eb8 movw r4, #0xf47d */
/* @0x213ebc orr r5, r11, r5 */
/* @0x213ec0 add r1, r1, r11 */
/* @0x213ec4 eor r5, r5, r8 */
/* @0x213ec8 mvn r2, r11 */
/* @0x213ecc add r6, r6, r5 */
/* @0x213ed0 movt r4, #0xffef */
/* @0x213ed4 ldr r5, [sp, #0x18] */
/* @0x213ed8 add r4, r9, r4 */
/* @0x213edc add r6, r11, r6, ror #17 —— 第 51/64 步 · 轮 4 · I · a=b+rol(tmp,15) */
/* @0x213ee0 ldr r8, [sp, #0x34] */
/* @0x213ee4 orr r3, r6, r3 */
/* @0x213ee8 movw r9, #0x5dd1 */
/* @0x213eec eor r11, r3, r11 */
/* @0x213ef0 mvn r3, r6 */
/* @0x213ef4 add r10, r10, r11 */
/* @0x213ef8 movt r9, #0x8584 */
/* @0x213efc add r9, r5, r9 */
/* @0x213f00 movw r11, #0xe6e0 */
/* @0x213f04 add r10, r6, r10, ror #11 —— 第 52/64 步 · 轮 4 · I · a=b+rol(tmp,21) */
/* @0x213f08 movw r5, #0x7e4f */
/* @0x213f0c orr r2, r10, r2 */
/* @0x213f10 movt r5, #0x6fa8 */
/* @0x213f14 eor r2, r2, r6 */
/* @0x213f18 movt r11, #0xfe2c */
/* @0x213f1c add r7, r7, r2 */
/* @0x213f20 ldr r2, [sp, #0x2c] */
/* @0x213f24 add r5, r8, r5 */
/* @0x213f28 add r11, r12, r11 */
/* @0x213f2c add r7, r10, r7, ror #26 —— 第 53/64 步 · 轮 4 · I · a=b+rol(tmp,6) */
/* @0x213f30 mvn r12, r10 */
/* @0x213f34 orr r3, r7, r3 */
/* @0x213f38 movw r8, #0x4314 */
/* @0x213f3c eor r3, r3, r10 */
/* @0x213f40 movt r8, #0xa301 */
/* @0x213f44 add r1, r1, r3 */
/* @0x213f48 add r5, r5, r7 */
/* @0x213f4c add r4, r4, r6 */
/* @0x213f50 add r8, r2, r8 */
/* @0x213f54 add r1, r7, r1, ror #22 —— 第 54/64 步 · 轮 4 · I · a=b+rol(tmp,10) */
/* @0x213f58 mvn r2, r7 */
/* @0x213f5c orr r12, r1, r12 */
/* @0x213f60 add r9, r9, r10 */
/* @0x213f64 eor r7, r12, r7 */
/* @0x213f68 add r11, r11, r1 */
/* @0x213f6c add r4, r4, r7 */
/* @0x213f70 str r11, [sp, #0x18] */
/* @0x213f74 ldr r11, [sp, #0x40] */
/* @0x213f78 movw r7, #0xf235 */
/* @0x213f7c add r4, r1, r4, ror #17 —— 第 55/64 步 · 轮 4 · I · a=b+rol(tmp,15) */
/* @0x213f80 str r5, [sp, #0x14] */
/* @0x213f84 orr r2, r4, r2 */
/* @0x213f88 movt r7, #0xbd3a */
/* @0x213f8c eor r2, r2, r1 */
/* @0x213f90 ldr r5, [sp, #0x24] */
/* @0x213f94 add r9, r9, r2 */
/* @0x213f98 mvn r12, r1 */
/* @0x213f9c add r7, r11, r7 */
/* @0x213fa0 ldr r11, [sp, #0x14] */
/* @0x213fa4 add r9, r4, r9, ror #11 —— 第 56/64 步 · 轮 4 · I · a=b+rol(tmp,21) */
/* @0x213fa8 movw r10, #0x7e82 */
/* @0x213fac orr r12, r9, r12 */
/* @0x213fb0 movt r10, #0xf753 */
/* @0x213fb4 eor r12, r12, r4 */
/* @0x213fb8 add r10, r5, r10 */
/* @0x213fbc add r5, r11, r12 */
/* @0x213fc0 ldr r3, [sp, #0x44] */
/* @0x213fc4 movw r6, #0x11a1 */
/* @0x213fc8 movt r6, #0x4e08 */
/* @0x213fcc add r5, r9, r5, ror #26 —— 第 57/64 步 · 轮 4 · I · a=b+rol(tmp,6) */
/* @0x213fd0 add r6, r3, r6 */
/* @0x213fd4 mvn r1, r4 */
/* @0x213fd8 orr r1, r5, r1 */
/* @0x213fdc add r8, r8, r4 */
/* @0x213fe0 add r6, r6, r9 */
/* @0x213fe4 mvn r4, r9 */
/* @0x213fe8 eor r1, r1, r9 */
/* @0x213fec ldr r9, [sp, #0x18] */
/* @0x213ff0 movw r3, #0xd2bb */
/* @0x213ff4 ldr r2, [sp, #0x1c] */
/* @0x213ff8 movt r3, #0x2ad7 */
/* @0x213ffc add r1, r9, r1 */
/* @0x214000 ldr r12, [sp, #0x38] */
/* @0x214004 add r3, r2, r3 */
/* @0x214008 movw r2, #0xd391 */
/* @0x21400c add r1, r5, r1, ror #22 —— 第 58/64 步 · 轮 4 · I · a=b+rol(tmp,10) */
/* @0x214010 movt r2, #0xeb86 */
/* @0x214014 orr r4, r1, r4 */
/* @0x214018 add r2, r12, r2 */
/* @0x21401c add r10, r10, r5 */
/* @0x214020 mvn r12, r5 */
/* @0x214024 eor r5, r4, r5 */
/* @0x214028 mvn r9, r1 */
/* @0x21402c add r5, r8, r5 */
/* @0x214030 add r7, r7, r1 */
/* @0x214034 add r5, r1, r5, ror #17 —— 第 59/64 步 · 轮 4 · I · a=b+rol(tmp,15) */
/* @0x214038 orr r12, r5, r12 */
/* @0x21403c add r3, r3, r5 */
/* @0x214040 eor r12, r12, r1 */
/* @0x214044 mvn r4, r5 */
/* @0x214048 add r12, r6, r12 */
/* @0x21404c ldr r1, [r0] */
/* @0x214050 add r12, r5, r12, ror #11 —— 第 60/64 步 · 轮 4 · I · a=b+rol(tmp,21) */
/* @0x214054 orr r9, r12, r9 */
/* @0x214058 add r2, r2, r12 */
/* @0x21405c eor r9, r9, r5 */
/* @0x214060 mvn r11, r12 */
/* @0x214064 add r10, r10, r9 */
/* @0x214068 add r10, r12, r10, ror #26 —— 第 61/64 步 · 轮 4 · I · a=b+rol(tmp,6) */
/* @0x21406c orr r4, r10, r4 */
/* @0x214070 add r5, r10, r1 */
/* @0x214074 eor r12, r4, r12 */
/* @0x214078 mvn r8, r10 */
/* @0x21407c add r7, r7, r12 */
/* ---- 收尾：四次回写 state 后返回 ----
 * 0x214080 str r5,[r0] / 0x2140a4 str r1,[r0,#0xc] / 0x2140c0 str r3,[r0,#8] / 0x2140c8 str r2,[r0,#4]
 *   —— 四个字全部落回 state[0..3]，次序 0/-4 交错，是因为轮 4 里 a/b/c/d 已换名到 r5/r2/r3/…
 * 0x2140cc add sp,#0x48、0x2140d0 pop {r4-r11}、0x2140d4 bx lr（最后这条是本段唯一的返回）。 */
/* @0x214080 str r5, [r0] */
/* @0x214084 ldr r4, [r0, #0xc] */
/* @0x214088 add r7, r10, r7, ror #22 —— 第 62/64 步 · 轮 4 · I · a=b+rol(tmp,10) */
/* @0x21408c ldr r5, [r0, #0x4] */
/* @0x214090 orr r11, r7, r11 */
/* @0x214094 add r1, r7, r4 */
/* @0x214098 eor r10, r11, r10 */
/* @0x21409c ldr r6, [r0, #0x8] */
/* @0x2140a0 add r3, r3, r10 */
/* @0x2140a4 str r1, [r0, #0xc] */
/* @0x2140a8 add r3, r7, r3, ror #17 —— 第 63/64 步 · 轮 4 · I · a=b+rol(tmp,15) */
/* @0x2140ac orr r12, r3, r8 */
/* @0x2140b0 add r1, r3, r5 */
/* @0x2140b4 eor r7, r12, r7 */
/* @0x2140b8 add r3, r3, r6 */
/* @0x2140bc add r2, r2, r7 */
/* @0x2140c0 str r3, [r0, #0x8] */
/* @0x2140c4 add r2, r1, r2, ror #11 —— 第 64/64 步 · 轮 4 · I · a=b+rol(tmp,21) */
/* @0x2140c8 str r2, [r0, #0x4] */
/* @0x2140cc add sp, sp, #72 */
/* @0x2140d0 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x2140d4 bx lr */


/* ═══════════════════════════════════════════════════════════════════════
 * §2  anon_2d49b8 = std::sort<b2ParticleSystem::Proxy*> 的排序内核
 *                  ＋ b2QueryCallback 删除析构的三份弱副本
 * ═══════════════════════════════════════════════════════════════════════
 *
 * 身份证据
 *   ① 具名调用者：0x2d4d10（插入排序）被 `void std::sort<b2ParticleSystem::Proxy*>(Proxy*, Proxy*)`
 *      以 b(0x2da5e0) 与 bl(0x2da5f0) 各调一次 —— 这个 std::sort 实例化是 .dynsym 里的具名函数，
 *      它的两个子过程只能落进本段；0x2d4a30 被 b2ParticleSystem::CreateParticle(0x2da508)、
 *      GetParticleColorBuffer(0x2d98a0)、SolveColorMixing(0x2d6600) 三处 bl。
 *   ② 元素形状：全段按 **8 字节记录** 搬运（lsl #3 下标、ldm/stm 成对、ldr/str 成对），比较的是记录
 *      **+4 处的 32 位 float**（0x2d4ac4 起 `ldr r5,[r0,#4]` / `ldr r1,[r0,#-4]` / `cmp`），
 *      与 b2ParticleSystem::Proxy {float weight; void* userData} 完全一致。
 *   ③ 三个 36 B 删除析构共用同一 vtable 槽：0x2d49b8 / 0x2d49e0 / 0x2d4a08 的 `ldr r3,[pc,r3]` 都解到
 *      GOT 0x3f1b88，其值 0x3ec698 是 vtable 头 {offset_to_top=0, typeinfo=0x3ec690}，
 *      typeinfo 的 name 指针 0x390438 指向字符串 "15b2QueryCallback" → 类名 **b2QueryCallback**；
 *      三者都 `str vptr,+8`（地址点）→ operator delete(0x27d1d0) → 返回 this，与具名
 *      `_ZN15b2QueryCallbackD0Ev`(0x2d4990，40 B，同形但少 +8) 是同族。
 *
 * 子函数表（边界以 push/序言为准；anon_splits.tsv 的 4/8 B 段是序言碎片，不是函数）
 *   0x2d49b8   40 B（含池字 0x2d49dc）  b2QueryCallback 删除析构副本 #1：vptr=[0x3f1b88]+8 → delete → 返 this
 *   0x2d49e0   40 B（含池字 0x2d4a04）  同上，副本 #2
 *   0x2d4a08   40 B（含池字 0x2d4a2c）  同上，副本 #3
 *   0x2d4a30   52 B                     void* f(T* self, b2BlockAllocator** pp)：n=*self；
 *                                       p=pp->Allocate(n<<2)(0x2c65c0)；memset(p,0,n<<2)；返回 p
 *   0x2d4a64  292 B                     __adjust_heap 下沉：n = 记录数，子下标 = 2*(i+1)，键 = +4 float
 *   0x2d4b88    ┐ 8 B 序言碎片（rsb/cmp #135 = 16 条记录 + 7）后**直落**进 0x2d4b90，同一函数
 *   0x2d4b90  384 B                     __introsort_loop(first,last,depth)：中位三数 + Hoare 划分；
 *                                       depth 用尽时内联 __partial_sort（调 0x2d4a64 建堆+排序）
 *   0x2d4d10  212 B                     __final_insertion_sort：8 B 记录左移插入
 *   0x2d4de4    ┐ 4 B 序言碎片（rsb/cmp）同样直落
 *   0x2d4de8  468 B                     __rotate/__merge 家族：用 __aeabi_idivmod 求 gcd 的整块轮转
 *                                       （0x2d4e98 起）+ __divsi3 算块数
 *   —— 235 + 8 + 384 + 212 + 4 + 468 之和 = 1540 B，与 anon_splits.tsv 的 parent=0x2d49b8 逐段相加相等。
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x2d49b8 0x2d4fb8 anon_2d49b8 sort_proxy_kernel */
/* ---- 析构副本 #1：vptr = [GOT 0x3f1b88] + 8，operator delete，返回 this ----
 * 0x2d49b8 ldr r3,[pc,#0x1c] → 池字 0x2d49dc = 0x0011d1c0（GOT 槽相对偏移，非指令）
 * 0x2d49c0 ldr r3,[pc,r3]    → r3 = [0x2d49c8+0x11d1c0] = [0x3f1b88] = 0x3ec698（vtable 头）
 * 0x2d49c8 add r3,#8 → 地址点 0x3ec6a0；0x2d49cc str r3,[r0]（复位 vptr，二级基布局）
 * 0x2d49d0 bl _ZdlPv(0x27d1d0)；0x2d49d4 mov r0,r4（把 this 还给调用者）；0x2d49d8 pop {r4,pc}
 * vtable 头 {0, 0x3ec690} 的 typeinfo.name(0x390438) = "15b2QueryCallback" → 类名闭合。 */
/* @0x2d49b8 ldr r3, [pc, #0x1c] */
/* @0x2d49bc push {r4, lr} */
/* @0x2d49c0 ldr r3, [pc, r3] */
/* @0x2d49c4 mov r4, r0 */
/* @0x2d49c8 add r3, r3, #8 */
/* @0x2d49cc str r3, [r0] */
/* @0x2d49d0 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d49d4 mov r0, r4 */
/* @0x2d49d8 pop {r4, pc} */
/* @0x2d49dc andseq sp, r1, r0, asr #3 —— 非指令（literal pool：vtable 槽的相对偏移 0x0011d1c0） */
/* ---- 析构副本 #2：与 #1 逐指令同形（池字 0x2d4a04 换成 0x0011d198，仍解到 0x3f1b88）----
 * 差别只有池字偏移（因为 pc 前进了 0x28，偏移同步减 0x28），落点完全相同 → 同一 vtable、同一 vptr 值。
 * 这是弱符号析构在多个 TU 里各留一份、链接器未合并的典型形态（见 open 3）。 */
/* @0x2d49e0 ldr r3, [pc, #0x1c] */
/* @0x2d49e4 push {r4, lr} */
/* @0x2d49e8 ldr r3, [pc, r3] */
/* @0x2d49ec mov r4, r0 */
/* @0x2d49f0 add r3, r3, #8 */
/* @0x2d49f4 str r3, [r0] */
/* @0x2d49f8 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d49fc mov r0, r4 */
/* @0x2d4a00 pop {r4, pc} */
/* @0x2d4a04 mulseq r1, r8, r1 —— 非指令（literal pool：vtable 槽相对偏移 0x0011d198） */
/* ---- 析构副本 #3：同形（池字 0x2d4a2c = 0x0011d170，解到 0x3f1b88）----
 * 三份副本合计 120 B；加上具名 _ZN15b2QueryCallbackD0Ev(0x2d4990, 40 B) 与 D1/D2(0x2d48a0, 24 B)，
 * b2QueryCallback 的析构在本 .so 里共 5 个入口。 */
/* @0x2d4a08 ldr r3, [pc, #0x1c] */
/* @0x2d4a0c push {r4, lr} */
/* @0x2d4a10 ldr r3, [pc, r3] */
/* @0x2d4a14 mov r4, r0 */
/* @0x2d4a18 add r3, r3, #8 */
/* @0x2d4a1c str r3, [r0] */
/* @0x2d4a20 bl 0x27d1d0 <_ZdlPv> */
/* @0x2d4a24 mov r0, r4 */
/* @0x2d4a28 pop {r4, pc} */
/* @0x2d4a2c andseq sp, r1, r0, ror r1 —— 非指令（literal pool：vtable 槽相对偏移 0x0011d170） */
/* ---- 分配并清零：void* f(T* self, b2BlockAllocator** pp) ----
 *   r0 = self（+0 处是一个计数 n），r1 = 指向 b2BlockAllocator* 的指针（二级指针）
 *   0x2d4a38 ldr r0,[r1] → r0 = 分配器对象；0x2d4a3c/0x2d4a40 n<<2 作字节数；
 *   0x2d4a44 bl b2BlockAllocator::Allocate(0x2c65c0)；0x2d4a48 再取一次 n → memset(p,0,n<<2)
 *   （0x2d4a58 bl memset@plt）；0x2d4a5c 返回 p。调用者：CreateParticle / GetParticleColorBuffer /
 *   SolveColorMixing —— 都是"给 N 个粒子准备一个 4 B 数组"的用法。 */
/* @0x2d4a30 push {r3, r4, r5, lr} */
/* @0x2d4a34 mov r4, r0 */
/* @0x2d4a38 ldr r0, [r1] */
/* @0x2d4a3c ldr r1, [r4] */
/* @0x2d4a40 lsl r1, r1, #2 */
/* @0x2d4a44 bl 0x2c65c0 <_ZN16b2BlockAllocator8AllocateEi> */
/* @0x2d4a48 ldr r2, [r4] */
/* @0x2d4a4c mov r1, #0 */
/* @0x2d4a50 lsl r2, r2, #2 */
/* @0x2d4a54 mov r5, r0 */
/* @0x2d4a58 bl 0xb65b0 <memset@plt> */
/* @0x2d4a5c mov r0, r5 */
/* @0x2d4a60 pop {r3, r4, r5, pc} */
/* ---- 8 B 记录堆下沉（__adjust_heap 内核）----
 *   入口 r0 = 记录基址、r1 = holeIndex、r2 = 记录数、r3/r?(栈) = 被下沉的记录键值
 *   0x2d4a64 add r12,r1,#1 / 0x2d4a6c lsl r12,#1 → 子下标 = 2*(i+1)（二叉堆的下标公式）
 *   0x2d4a70 cmp r12,r2 → 子越界就走 0x2d4ae4（取最后一条记录补洞，经典 adjust_heap 尾巴）
 *   0x2d4ab4/0x2d4abc 读两个 8 B 记录的 +4（float 键）比较；0x2d4acc ldm r3,{r0,r1} 成对搬记录
 *   0x2d4b74 str r7,[r3] / str r5,[r3,#4] 把键值写进洞；0x2d4b84 bx lr
 *   本函数被 0x2d4b90 末尾的 __partial_sort 内联体调用两次（0x2d4cb8、0x2d4cfc）。 */
/* @0x2d4a64 add r12, r1, #1 */
/* @0x2d4a68 sub sp, sp, #8 */
/* @0x2d4a6c lsl r12, r12, #1 */
/* @0x2d4a70 cmp r12, r2 */
/* @0x2d4a74 push {r4, r5, r6, r7, r8} */
/* @0x2d4a78 movge r5, r12 */
/* @0x2d4a7c str r3, [sp, #0x18] */
/* @0x2d4a80 mov r8, r1 */
/* @0x2d4a84 mov r4, r0 */
/* @0x2d4a88 addge r3, r0, r1, lsl #3 */
/* @0x2d4a8c movge r12, r1 */
/* @0x2d4a90 bge 0x2d4ae4 <_ZN15b2QueryCallbackD0Ev+0x154> */
/* @0x2d4a94 mov r7, r1 */
/* @0x2d4a98 b 0x2d4aa0 <_ZN15b2QueryCallbackD0Ev+0x110> */
/* @0x2d4a9c mov r12, r5 */
/* @0x2d4aa0 lsl r3, r12, #3 */
/* @0x2d4aa4 add r6, r4, r7, lsl #3 */
/* @0x2d4aa8 add r0, r4, r3 */
/* @0x2d4aac sub r3, r3, #8 */
/* @0x2d4ab0 add r3, r4, r3 */
/* @0x2d4ab4 ldr r5, [r0, #0x4] */
/* @0x2d4ab8 ldr r1, [r0, #-0x4] */
/* @0x2d4abc cmp r5, r1 */
/* @0x2d4ac0 sublo r12, r12, #1 */
/* @0x2d4ac4 add r5, r12, #1 */
/* @0x2d4ac8 movhs r3, r0 */
/* @0x2d4acc ldm r3, {r0, r1} */
/* @0x2d4ad0 mov r7, r12 */
/* @0x2d4ad4 lsl r5, r5, #1 */
/* @0x2d4ad8 cmp r5, r2 */
/* @0x2d4adc stm r6, {r0, r1} */
/* @0x2d4ae0 blt 0x2d4a9c <_ZN15b2QueryCallbackD0Ev+0x10c> */
/* @0x2d4ae4 cmp r5, r2 */
/* @0x2d4ae8 bne 0x2d4b04 <_ZN15b2QueryCallbackD0Ev+0x174> */
/* @0x2d4aec sub r2, r5, #-536870911 */
/* @0x2d4af0 sub r12, r5, #1 */
/* @0x2d4af4 add r2, r4, r2, lsl #3 */
/* @0x2d4af8 ldm r2, {r0, r1} */
/* @0x2d4afc stm r3, {r0, r1} */
/* @0x2d4b00 mov r3, r2 */
/* @0x2d4b04 cmp r8, r12 */
/* @0x2d4b08 ldr r7, [sp, #0x18] */
/* @0x2d4b0c ldr r5, [sp, #0x1c] */
/* @0x2d4b10 bge 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b14 sub r2, r12, #1 */
/* @0x2d4b18 add r2, r2, r2, lsr #31 */
/* @0x2d4b1c asr r2, r2, #1 */
/* @0x2d4b20 lsl r1, r2, #3 */
/* @0x2d4b24 add r0, r4, r1 */
/* @0x2d4b28 ldr r0, [r0, #0x4] */
/* @0x2d4b2c cmp r5, r0 */
/* @0x2d4b30 bls 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b34 add r3, r4, r1 */
/* @0x2d4b38 sub r6, r2, #1 */
/* @0x2d4b3c add r12, r4, r12, lsl #3 */
/* @0x2d4b40 cmp r8, r2 */
/* @0x2d4b44 ldm r3, {r0, r1} */
/* @0x2d4b48 add r6, r6, r6, lsr #31 */
/* @0x2d4b4c asr r6, r6, #1 */
/* @0x2d4b50 stm r12, {r0, r1} */
/* @0x2d4b54 bge 0x2d4b74 <_ZN15b2QueryCallbackD0Ev+0x1e4> */
/* @0x2d4b58 lsl r1, r6, #3 */
/* @0x2d4b5c mov r12, r2 */
/* @0x2d4b60 add r0, r4, r1 */
/* @0x2d4b64 mov r2, r6 */
/* @0x2d4b68 ldr r0, [r0, #0x4] */
/* @0x2d4b6c cmp r0, r5 */
/* @0x2d4b70 blo 0x2d4b34 <_ZN15b2QueryCallbackD0Ev+0x1a4> */
/* @0x2d4b74 str r7, [r3] */
/* @0x2d4b78 str r5, [r3, #0x4] */
/* @0x2d4b7c pop {r4, r5, r6, r7, r8} */
/* @0x2d4b80 add sp, sp, #8 */
/* @0x2d4b84 bx lr */
/* ---- 序言碎片（8 B）+ __introsort_loop 主体 ----
 * 0x2d4b88 rsb r3,r0,r1 / 0x2d4b8c cmp r3,#135 —— **135 = 16*8 + 7**，就是 libstdc++ 的
 *   _S_threshold=16 条记录；这两条在 push 之前执行，所以 split 表把 0x2d4b88 记成独立 8 B 段，
 *   实际与 0x2d4b90 是同一函数（0x2d4b90 的 push 紧接着执行，无分支进入）。
 * 0x2d4b94 起：r6=first、r7=last、r8=depth_limit；0x2d4bac depth==0 → 直接 0x2d4c8c 走堆排序；
 * 0x2d4bb0 起中位三数（比较 lr/[r3+4]/r5 三个键）→ Hoare 划分 → 0x2d4c4c 递归小半、循环大半；
 * 0x2d4c58 bl 0x2d4b88 即自递归（r0=新 first、r1=新 last、r2=depth-1）。 */
/* @0x2d4b88 rsb r3, r0, r1 */
/* @0x2d4b8c cmp r3, #135 */
/* ---- __introsort_loop 主体（承接上一条序言碎片）----
 *   0x2d4b90 push {r4-r8,lr} / sub sp,#16；r6=first r7=last r8=depth_limit
 *   0x2d4ba4 ble 0x2d4d08 → 区间 ≤135 B 直接返回（交给 0x2d4d10 的插入排序）
 *   0x2d4bac beq 0x2d4c8c → depth 用尽 → 内联 __partial_sort：0x2d4ca0..0x2d4cb8 建堆（逐次调 0x2d4a64），
 *     0x2d4ccc..0x2d4cfc 反复"取堆顶→末尾→再下沉"，0x2d4d00 cmp r5,#15 控制循环
 *   0x2d4c58 bl 0x2d4b88 → 对左半递归；右半走 0x2d4c70 的循环（尾递归消除）
 *   —— 三条出口：0x2d4d08（区间够小）、0x2d4c90（堆排序完成）、0x2d4d00 循环退出。 */
/* @0x2d4b90 push {r4, r5, r6, r7, r8, lr} */
/* @0x2d4b94 mov r6, r0 */
/* @0x2d4b98 sub sp, sp, #16 */
/* @0x2d4b9c mov r7, r1 */
/* @0x2d4ba0 mov r8, r2 */
/* @0x2d4ba4 ble 0x2d4d08 <_ZN15b2QueryCallbackD0Ev+0x378> */
/* @0x2d4ba8 cmp r2, #0 */
/* @0x2d4bac beq 0x2d4c8c <_ZN15b2QueryCallbackD0Ev+0x2fc> */
/* @0x2d4bb0 asr r3, r3, #4 */
/* @0x2d4bb4 ldr lr, [r6, #0x4] */
/* @0x2d4bb8 sub r8, r8, #1 */
/* @0x2d4bbc ldr r5, [r7, #-0x4] */
/* @0x2d4bc0 add r3, r6, r3, lsl #3 */
/* @0x2d4bc4 ldr r12, [r3, #0x4] */
/* @0x2d4bc8 cmp lr, r12 */
/* @0x2d4bcc bhs 0x2d4c78 <_ZN15b2QueryCallbackD0Ev+0x2e8> */
/* @0x2d4bd0 cmp r12, r5 */
/* @0x2d4bd4 blo 0x2d4be4 <_ZN15b2QueryCallbackD0Ev+0x254> */
/* @0x2d4bd8 cmp lr, r5 */
/* @0x2d4bdc movhs r12, lr */
/* @0x2d4be0 movlo r12, r5 */
/* @0x2d4be4 mov r3, r7 */
/* @0x2d4be8 mov r2, r6 */
/* @0x2d4bec cmp r12, lr */
/* @0x2d4bf0 mov r4, r2 */
/* @0x2d4bf4 bls 0x2d4c08 <_ZN15b2QueryCallbackD0Ev+0x278> */
/* @0x2d4bf8 add r4, r4, #8 */
/* @0x2d4bfc ldr lr, [r4, #0x4] */
/* @0x2d4c00 cmp lr, r12 */
/* @0x2d4c04 blo 0x2d4bf8 <_ZN15b2QueryCallbackD0Ev+0x268> */
/* @0x2d4c08 cmp r12, r5 */
/* @0x2d4c0c sub r3, r3, #8 */
/* @0x2d4c10 bhs 0x2d4c24 <_ZN15b2QueryCallbackD0Ev+0x294> */
/* @0x2d4c14 sub r3, r3, #8 */
/* @0x2d4c18 ldr r5, [r3, #0x4] */
/* @0x2d4c1c cmp r5, r12 */
/* @0x2d4c20 bhi 0x2d4c14 <_ZN15b2QueryCallbackD0Ev+0x284> */
/* @0x2d4c24 cmp r4, r3 */
/* @0x2d4c28 bhs 0x2d4c4c <_ZN15b2QueryCallbackD0Ev+0x2bc> */
/* @0x2d4c2c ldr r5, [r4] */
/* @0x2d4c30 add r2, r4, #8 */
/* @0x2d4c34 ldm r3, {r0, r1} */
/* @0x2d4c38 stm r4, {r0, r1} */
/* @0x2d4c3c stm r3, {r5, lr} */
/* @0x2d4c40 ldr r5, [r3, #-0x4] */
/* @0x2d4c44 ldr lr, [r4, #0xc] */
/* @0x2d4c48 b 0x2d4bec <_ZN15b2QueryCallbackD0Ev+0x25c> */
/* @0x2d4c4c mov r1, r7 */
/* @0x2d4c50 mov r0, r4 */
/* @0x2d4c54 mov r2, r8 */
/* @0x2d4c58 bl 0x2d4b88 <_ZN15b2QueryCallbackD0Ev+0x1f8> */
/* @0x2d4c5c rsb r3, r6, r4 */
/* @0x2d4c60 cmp r3, #135 */
/* @0x2d4c64 ble 0x2d4d08 <_ZN15b2QueryCallbackD0Ev+0x378> */
/* @0x2d4c68 cmp r8, #0 */
/* @0x2d4c6c beq 0x2d4c90 <_ZN15b2QueryCallbackD0Ev+0x300> */
/* @0x2d4c70 mov r7, r4 */
/* @0x2d4c74 b 0x2d4bb0 <_ZN15b2QueryCallbackD0Ev+0x220> */
/* @0x2d4c78 cmp r12, r5 */
/* @0x2d4c7c movlo r12, r5 */
/* @0x2d4c80 cmp lr, r5 */
/* @0x2d4c84 movlo r12, lr */
/* @0x2d4c88 b 0x2d4be4 <_ZN15b2QueryCallbackD0Ev+0x254> */
/* @0x2d4c8c mov r4, r7 */
/* @0x2d4c90 asr r8, r3, #3 */
/* @0x2d4c94 sub r5, r8, #2 */
/* @0x2d4c98 asr r5, r5, #1 */
/* @0x2d4c9c add r7, r6, r5, lsl #3 */
/* @0x2d4ca0 ldr r12, [r7, #0x4] */
/* @0x2d4ca4 mov r1, r5 */
/* @0x2d4ca8 ldr r3, [r7], #-8 */
/* @0x2d4cac mov r0, r6 */
/* @0x2d4cb0 mov r2, r8 */
/* @0x2d4cb4 str r12, [sp] */
/* @0x2d4cb8 bl 0x2d4a64 <_ZN15b2QueryCallbackD0Ev+0xd4> */
/* @0x2d4cbc cmp r5, #0 */
/* @0x2d4cc0 sub r5, r5, #1 */
/* @0x2d4cc4 bne 0x2d4ca0 <_ZN15b2QueryCallbackD0Ev+0x310> */
/* @0x2d4cc8 add r7, sp, #8 */
/* @0x2d4ccc sub r4, r4, #8 */
/* @0x2d4cd0 rsb r5, r6, r4 */
/* @0x2d4cd4 ldm r4, {r0, r1} */
/* @0x2d4cd8 asr r2, r5, #3 */
/* @0x2d4cdc stm r7, {r0, r1} */
/* @0x2d4ce0 ldm r6, {r0, r1} */
/* @0x2d4ce4 ldr r12, [sp, #0xc] */
/* @0x2d4ce8 ldr r3, [sp, #0x8] */
/* @0x2d4cec stm r4, {r0, r1} */
/* @0x2d4cf0 mov r0, r6 */
/* @0x2d4cf4 str r12, [sp] */
/* @0x2d4cf8 mov r1, #0 */
/* @0x2d4cfc bl 0x2d4a64 <_ZN15b2QueryCallbackD0Ev+0xd4> */
/* @0x2d4d00 cmp r5, #15 */
/* @0x2d4d04 bgt 0x2d4ccc <_ZN15b2QueryCallbackD0Ev+0x33c> */
/* @0x2d4d08 add sp, sp, #16 */
/* @0x2d4d0c pop {r4, r5, r6, r7, r8, pc} */
/* ---- 插入排序（__final_insertion_sort）----
 *   入口 r0 = first、r1 = last；r6=first r9=last r4=cursor r5=cursor+8
 *   0x2d4d34 起：取 cur 的键（+4 float）与前一记录比较，0x2d4d64..0x2d4d7c 用 ldm/stm 把记录
 *   一条条后移 8 B，0x2d4d80 落位；0x2d4d84 游标 +8 直到 r9。
 *   0x2d4d94 pop/bx lr 是正常出口；0x2d4dd8/0x2d4d9c 是"键更小/更大"两条捷径的落点。
 *   唯一具名调用者就是 std::sort<b2ParticleSystem::Proxy*>（0x2da5e0 b / 0x2da5f0 bl）。 */
/* @0x2d4d10 cmp r0, r1 */
/* @0x2d4d14 push {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2d4d18 mov r6, r0 */
/* @0x2d4d1c mov r9, r1 */
/* @0x2d4d20 beq 0x2d4d94 <_ZN15b2QueryCallbackD0Ev+0x404> */
/* @0x2d4d24 add r4, r0, #8 */
/* @0x2d4d28 cmp r1, r4 */
/* @0x2d4d2c beq 0x2d4d94 <_ZN15b2QueryCallbackD0Ev+0x404> */
/* @0x2d4d30 add r5, r0, #16 */
/* @0x2d4d34 ldr r12, [r4, #0x4] */
/* @0x2d4d38 mov r2, r4 */
/* @0x2d4d3c ldr r3, [r6, #0x4] */
/* @0x2d4d40 mov r7, r5 */
/* @0x2d4d44 ldr r8, [r5, #-0x8] */
/* @0x2d4d48 cmp r12, r3 */
/* @0x2d4d4c bhs 0x2d4d9c <_ZN15b2QueryCallbackD0Ev+0x40c> */
/* @0x2d4d50 rsb r2, r6, r4 */
/* @0x2d4d54 asr r2, r2, #3 */
/* @0x2d4d58 cmp r2, #0 */
/* @0x2d4d5c movgt r10, r5 */
/* @0x2d4d60 ble 0x2d4d80 <_ZN15b2QueryCallbackD0Ev+0x3f0> */
/* @0x2d4d64 sub r1, r10, #16 */
/* @0x2d4d68 sub r3, r10, #8 */
/* @0x2d4d6c subs r2, r2, #1 */
/* @0x2d4d70 ldm r1, {r0, r1} */
/* @0x2d4d74 mov r10, r3 */
/* @0x2d4d78 stm r3, {r0, r1} */
/* @0x2d4d7c bne 0x2d4d64 <_ZN15b2QueryCallbackD0Ev+0x3d4> */
/* @0x2d4d80 stm r6, {r8, r12} */
/* @0x2d4d84 cmp r9, r7 */
/* @0x2d4d88 add r4, r4, #8 */
/* @0x2d4d8c add r5, r5, #8 */
/* @0x2d4d90 bne 0x2d4d34 <_ZN15b2QueryCallbackD0Ev+0x3a4> */
/* @0x2d4d94 pop {r4, r5, r6, r7, r8, r9, r10} */
/* @0x2d4d98 bx lr */
/* @0x2d4d9c ldr r1, [r4, #-0x4] */
/* @0x2d4da0 sub r3, r4, #8 */
/* @0x2d4da4 cmp r12, r1 */
/* @0x2d4da8 blo 0x2d4db4 <_ZN15b2QueryCallbackD0Ev+0x424> */
/* @0x2d4dac b 0x2d4dd8 <_ZN15b2QueryCallbackD0Ev+0x448> */
/* @0x2d4db0 mov r3, r10 */
/* @0x2d4db4 ldm r3, {r0, r1} */
/* @0x2d4db8 sub r10, r3, #8 */
/* @0x2d4dbc stm r2, {r0, r1} */
/* @0x2d4dc0 mov r2, r3 */
/* @0x2d4dc4 ldr r1, [r3, #-0x4] */
/* @0x2d4dc8 cmp r12, r1 */
/* @0x2d4dcc blo 0x2d4db0 <_ZN15b2QueryCallbackD0Ev+0x420> */
/* @0x2d4dd0 stm r3, {r8, r12} */
/* @0x2d4dd4 b 0x2d4d84 <_ZN15b2QueryCallbackD0Ev+0x3f4> */
/* @0x2d4dd8 mov r3, r4 */
/* @0x2d4ddc stm r3, {r8, r12} */
/* @0x2d4de0 b 0x2d4d84 <_ZN15b2QueryCallbackD0Ev+0x3f4> */
/* ---- 序言碎片（4 B）+ __rotate/__merge ---- */
/* @0x2d4de4 rsb r3, r0, r1 */
/* ---- 整块轮转（gcd 版 __rotate）----
 *   0x2d4de4 rsb r3,r0,r1（区间字节数）→ 0x2d4df0 asrs #3 转成记录数，直落进本函数
 *   0x2d4e14 起：n = 记录数、g = gcd(n, k)（0x2d4e9c bl __aeabi_idivmod 的循环求余，0x2d4e98 回边）
 *   0x2d4ef8/0x2d4f64 bl __divsi3 算每轮块数；0x2d4f10..0x2d4f3c、0x2d4f80..0x2d4fac 两段循环
 *   按 8 B 记录整块搬运（ldm/stm + vldr/vstr s16/s17 保键），0x2d4f44/0x2d4f4c 落位
 *   出口 0x2d4e88（add sp,#20 / vpop {d8} / pop {r4-r11,pc}）。
 *   —— 与 0x2d4d10/0x2d4b90 同属一个 std::sort<Proxy*> 实例的 inplace_merge 路径。 */
/* @0x2d4de8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x2d4dec vpush {d8} */
/* @0x2d4df0 asrs r3, r3, #3 */
/* @0x2d4df4 sub sp, sp, #20 */
/* @0x2d4df8 mov r9, r2 */
/* @0x2d4dfc rsb r2, r1, r2 */
/* @0x2d4e00 mov r6, r0 */
/* @0x2d4e04 add r2, r0, r2 */
/* @0x2d4e08 mov r4, r1 */
/* @0x2d4e0c str r3, [sp] */
/* @0x2d4e10 moveq r0, r9 */
/* @0x2d4e14 str r2, [sp, #0xc] */
/* @0x2d4e18 beq 0x2d4e8c <_ZN15b2QueryCallbackD0Ev+0x4fc> */
/* @0x2d4e1c rsb r0, r6, r9 */
/* @0x2d4e20 asr r0, r0, #3 */
/* @0x2d4e24 rsb r2, r3, r0 */
/* @0x2d4e28 str r2, [sp, #0x4] */
/* @0x2d4e2c cmp r3, r2 */
/* @0x2d4e30 ldrne r10, [sp] */
/* @0x2d4e34 bne 0x2d4e9c <_ZN15b2QueryCallbackD0Ev+0x50c> */
/* @0x2d4e38 cmp r6, r1 */
/* @0x2d4e3c beq 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4e40 add r12, r6, #8 */
/* @0x2d4e44 add r3, r1, #8 */
/* @0x2d4e48 mov r7, r1 */
/* @0x2d4e4c mov r5, r12 */
/* @0x2d4e50 mov r2, r5 */
/* @0x2d4e54 ldmdb r3, {r0, r1} */
/* @0x2d4e58 ldr r8, [r6, #0x4] */
/* @0x2d4e5c cmp r4, r12 */
/* @0x2d4e60 ldr r9, [r2, #-0x8]! */
/* @0x2d4e64 mov r6, r12 */
/* @0x2d4e68 add r5, r5, #8 */
/* @0x2d4e6c add r12, r12, #8 */
/* @0x2d4e70 add r3, r3, #8 */
/* @0x2d4e74 add r7, r7, #8 */
/* @0x2d4e78 stm r2, {r0, r1} */
/* @0x2d4e7c str r9, [r3, #-0x10] */
/* @0x2d4e80 str r8, [r7, #-0x4] */
/* @0x2d4e84 bne 0x2d4e50 <_ZN15b2QueryCallbackD0Ev+0x4c0> */
/* @0x2d4e88 ldr r0, [sp, #0xc] */
/* @0x2d4e8c add sp, sp, #20 */
/* @0x2d4e90 vpop {d8} */
/* @0x2d4e94 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2d4e98 mov r10, r1 */
/* @0x2d4e9c mov r1, r10 */
/* @0x2d4ea0 bl 0x318dec <__aeabi_idivmod> */
/* @0x2d4ea4 mov r0, r10 */
/* @0x2d4ea8 cmp r1, #0 */
/* @0x2d4eac bne 0x2d4e98 <_ZN15b2QueryCallbackD0Ev+0x508> */
/* @0x2d4eb0 cmp r10, #0 */
/* @0x2d4eb4 ble 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4eb8 ldr r3, [sp, #0x4] */
/* @0x2d4ebc mov r11, r1 */
/* @0x2d4ec0 ldr r2, [sp] */
/* @0x2d4ec4 lsl r3, r3, #3 */
/* @0x2d4ec8 str r3, [sp, #0x8] */
/* @0x2d4ecc lsl r4, r2, #3 */
/* @0x2d4ed0 rsb r5, r3, #0 */
/* @0x2d4ed4 rsb r9, r4, r9 */
/* @0x2d4ed8 ldr r3, [sp] */
/* @0x2d4edc vldr s17, [r6] */
/* @0x2d4ee0 ldr r2, [sp, #0x4] */
/* @0x2d4ee4 vldr s16, [r6, #4] */
/* @0x2d4ee8 cmp r3, r2 */
/* @0x2d4eec blt 0x2d4f5c <_ZN15b2QueryCallbackD0Ev+0x5cc> */
/* @0x2d4ef0 mov r0, r3 */
/* @0x2d4ef4 mov r1, r10 */
/* @0x2d4ef8 bl 0x318d10 <__divsi3> */
/* @0x2d4efc cmp r0, #1 */
/* @0x2d4f00 subgt r7, r0, #1 */
/* @0x2d4f04 movgt r2, r6 */
/* @0x2d4f08 movgt r12, #0 */
/* @0x2d4f0c ble 0x2d4fb4 <_ZN15b2QueryCallbackD0Ev+0x624> */
/* @0x2d4f10 cmp r9, r2 */
/* @0x2d4f14 add r3, r2, r4 */
/* @0x2d4f18 add r12, r12, #1 */
/* @0x2d4f1c ldmhi r3, {r0, r1} */
/* @0x2d4f20 stmhi r2, {r0, r1} */
/* @0x2d4f24 movhi r2, r3 */
/* @0x2d4f28 add r3, r2, r5 */
/* @0x2d4f2c cmp r12, r7 */
/* @0x2d4f30 ldm r3, {r0, r1} */
/* @0x2d4f34 stm r2, {r0, r1} */
/* @0x2d4f38 mov r2, r3 */
/* @0x2d4f3c bne 0x2d4f10 <_ZN15b2QueryCallbackD0Ev+0x580> */
/* @0x2d4f40 add r11, r11, #1 */
/* @0x2d4f44 vstr s17, [r3] */
/* @0x2d4f48 cmp r11, r10 */
/* @0x2d4f4c vstr s16, [r3, #4] */
/* @0x2d4f50 add r6, r6, #8 */
/* @0x2d4f54 bne 0x2d4ed8 <_ZN15b2QueryCallbackD0Ev+0x548> */
/* @0x2d4f58 b 0x2d4e88 <_ZN15b2QueryCallbackD0Ev+0x4f8> */
/* @0x2d4f5c ldr r0, [sp, #0x4] */
/* @0x2d4f60 mov r1, r10 */
/* @0x2d4f64 bl 0x318d10 <__divsi3> */
/* @0x2d4f68 subs r7, r0, #0 */
/* @0x2d4f6c ble 0x2d4fb4 <_ZN15b2QueryCallbackD0Ev+0x624> */
/* @0x2d4f70 ldr r3, [sp, #0x8] */
/* @0x2d4f74 mov r2, r6 */
/* @0x2d4f78 mov r12, #0 */
/* @0x2d4f7c add r8, r6, r3 */
/* @0x2d4f80 cmp r8, r2 */
/* @0x2d4f84 add r3, r2, r5 */
/* @0x2d4f88 add r12, r12, #1 */
/* @0x2d4f8c ldmlo r3, {r0, r1} */
/* @0x2d4f90 stmlo r2, {r0, r1} */
/* @0x2d4f94 movlo r2, r3 */
/* @0x2d4f98 add r3, r2, r4 */
/* @0x2d4f9c cmp r12, r7 */
/* @0x2d4fa0 ldm r3, {r0, r1} */
/* @0x2d4fa4 stm r2, {r0, r1} */
/* @0x2d4fa8 mov r2, r3 */
/* @0x2d4fac bne 0x2d4f80 <_ZN15b2QueryCallbackD0Ev+0x5f0> */
/* @0x2d4fb0 b 0x2d4f40 <_ZN15b2QueryCallbackD0Ev+0x5b0> */
/* @0x2d4fb4 mov r3, r6 */
/* @0x2d4fb8 b 0x2d4f40 <_ZN15b2QueryCallbackD0Ev+0x5b0> */


/* ═══════════════════════════════════════════════════════════════════════
 * §3  anon_153710 = IAP（Billing）请求管道：执行器 + 提交器
 * ═══════════════════════════════════════════════════════════════════════
 *
 * 身份证据
 *   ① 具名调用者：0x153acc 被 **五个 GML 内建**各调一次 —— F_IAP_Activate(0x154c38)、
 *      F_IAP_Acquire(0x1551ac)、F_IAP_Consume(0x15529c)、F_IAP_RestoreAll(0x1552ec，尾跳)、
 *      F_IAP_ProductDetails(0x1553c8)；0x153710 被 YYIAPEventsDispatch(0x153f9c) 调。
 *      一个"事件派发器 + 五个内建"都指向同一段 = 请求从内建进、从事件派发出。
 *   ② 字符串常量（.rodata，本段 pc 相对寻址算出，逐条可复核）：
 *      0x346124 "s_purchased"      0x346130 "type"        0x346138 "product"
 *      0x346140 "purchaseIndex"    0x346150 "payload"
 *      0x346158 "BILLING: Request ignored; Store is not available\n"
 *      0x34618c "BILLING: Request deferred, store isn't available right now\n"
 *      0x3461c8 "BILLING: Activate request ignored; Store has already loaded\n"
 *      同区还有 iap_is_purchased / iap_enumerate_products / iap_restore_all / iap_product_details /
 *      iap_purchase_details / iap_store_status / iap_event_queue / iap_product_status 等键名。
 *   ③ 全局槽（GOT 基址 = 0x3f1c58，与 .dynamic 的 PLTGOT 相同）：
 *      槽 0x3efacc → 0x3f2358（.data+0x358）   store 状态字（本段读/写的就是它）
 *      槽 0x3ed944 → 0x4836b0（.bss+0x9c20）   IAP 全局块：+0 未追，+4 = ds_map id 数组基址
 *      槽 0x3ed948 → 0x3eb708（.data.rel.ro）  里面存着全局日志对象指针（*(0x3eb708) 才是对象）
 *      池字 0x29e7e0（0x153b5c）→ 0x3f2348（.data）  事件队列结构，+4 = 队列句柄（== -1 时现建）
 *
 * 结构（三段拼接）
 *   A 0x153710..0x153ac4（956 B）**执行器**：入参 r0 = CDS_Map*（不是 ds_map 号：由 0x154a70 用
 *      operator new(4)+CDS_Map::C2 现造，五个内建各造一个，见 open 6）。
 *      0x15372c DS_AutoMutex 上锁 → 0x153740 YYSetString(&rv,"type") → 0x15374c CDS_Map::Find(map,&rv)
 *      → 校验 rv.type==1（字符串，0x153750 的 (t-1)&~0xFF000000&~3==0）→ 0x153788 YYGetInt32(值)
 *      → 0x153790 cmp #4 / 0x153794 五路跳表（表基 0x15379c）：
 *         type=0 → 0x1537f4  g_storeStatus←0   IAP_Activate()
 *         type=1 → 0x153808  g_storeStatus←2   "product"+YYGetInt32+ "purchaseIndex" → IAP_Acquire(p,id,n)
 *         type=2 → 0x15394c  g_storeStatus←2   "product" → IAP_Consume(p)
 *         type=3 → 0x1539cc  g_storeStatus←2   "product" → IAP_GetProductDetailM(p)
 *         type=4 → 0x1537bc  g_storeStatus←3   IAP_RestoreM()
 *         else   → 0x153a4c  g_storeStatus←1   不调平台
 *      公共尾 0x1537cc：FindFreeDsMapIndex(0x100014) → g_iap[+4][idx] = map → DestroyDsMap(0x205334)
 *      → DS_AutoMutex 解锁析构 → 返回。即"请求处理完把 map 存档再销毁"。
 *   B 0x153acc..0x153ad4（12 B）不是函数：三条指令算出 GOT 基址 r3=0x3f1c58 与槽偏移 r2=-0x218c，
 *      直落进 C（没有 push，split 表把它切成 12 B 是"bl 落点"效应）。
 *   C 0x153ad8..0x153be0（296 B）**提交器**：入参 r0 = CDS_Map*（调用点由 0x154a70 返回），
 *      r1 = 请求种类 0..4（F_IAP_Activate 传 0、RestoreAll 传 4，见 0x154c30-0x154c34 / 0x1552e0）。
 *      0x153ae8 读 g_storeStatus → 0x153aec +2 → 0x153af0 cmp #4 / 0x153af4 五路跳表（表基 0x153afc）：
 *         状态 -2/-1（store 不可用）且 kind!=0 → 日志 "Request ignored; Store is not available"
 *         状态 -2/-1 且 kind==0（Activate）      → 0x153b48 尾跳 A，直接执行
 *         状态 1（已加载）且 kind==0             → 日志 "Activate request ignored; Store has already loaded"
 *         状态 1 且 kind!=0                      → 0x153b48 尾跳 A
 *         状态 0/2                               → 日志 "Request deferred, ..." → 入队：
 *             0x153bb8 若 g_queue(+4)==-1 则 DsQueueCreate()，0x153b9c DsQueueEnqueue(q,1,0,0,map)
 *      日志走 0x153b24：r3 = [槽 0x3ed948] = 0x3eb708 → r0 = *(0x3eb708)（全局日志对象）
 *      → r3 = [r0]（vptr）→ [r3+0xc](r0=obj, r1=msg) → blx。
 *   D 0x153b54 不是新函数：`pop {r4,r5,lr}` 之后 `b 0x153710`，是 A 的尾跳入口（被 anon_b6fd0 的
 *      bl 落点带出来，见 open 2）。
 *
 * 一句话契约：**五个 F_IAP_* 先把请求攒进一个 ds_map，提交器按 store 状态决定「立刻执行 / 报错 /
 * 入队延后」，执行器再按 map["type"] 调平台 API 并把结果 map 存进槽表。**
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x153710 0x153be0 anon_153710 iap_dispatch */
/* ---- A 段入口：执行器（r0 = iap ds_map）----
 * 0x153710 push {r4-r10,lr} / sub sp,#24：帧 24 B，r7=锁对象(sp+4)、r4=RValue 槽(sp+8)、
 *   r5=GOT 基址（0x153738 add r5,pc,r5 → 0x3f1c58）、r6=入参 map（0x15371c mov r6,r0）
 * 0x15372c bl DS_AutoMutex::C2(0xfec18) —— 整个执行器在一把自动锁里
 * 0x153740 YYSetString(&rv, "type")（pc 相对算出 0x346130）
 * 0x15374c CDS_Map::Find(map,&rv) → r8 = 命中的桶节点；命中节点的值 RValue 在 +0x10，
 *   其 type 字段在 +0x1c（0x1538e4 处用 [r8,#0x1c] 读的就是它）—— 与 RValue 的 type 在 +0xc 一致
 *   （这里 +0x10+0xc = +0x1c）。 */
/* @0x153710 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x153714 sub sp, sp, #24 */
/* @0x153718 add r7, sp, #4 */
/* @0x15371c mov r6, r0 */
/* @0x153720 add r4, sp, #8 */
/* @0x153724 ldr r5, [pc, #0x37c] */
/* @0x153728 mov r0, r7 */
/* @0x15372c bl 0xfec18 <_ZN12DS_AutoMutexC2Ev> */
/* @0x153730 ldr r1, [pc, #0x374] */
/* @0x153734 mov r0, r4 */
/* @0x153738 add r5, pc, r5 */
/* @0x15373c add r1, pc, r1 */
/* @0x153740 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153744 mov r0, r6 */
/* @0x153748 mov r1, r4 */
/* @0x15374c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153750 ldr r3, [sp, #0x14] */
/* @0x153754 sub r3, r3, #1 */
/* @0x153758 bic r3, r3, #-16777216 */
/* @0x15375c bic r3, r3, #3 */
/* @0x153760 cmp r3, #0 */
/* @0x153764 mov r8, r0 */
/* @0x153768 beq 0x1537b0 <_Z16InitIAPFunctionsv+0x2dc> */
/* ---- type 值取出 + 五路跳表 ----
 * 0x15376c ldr r3,[pc,#0x31c] → 池字 0x153ab0 = 0xffffde74（GOT 槽偏移，非指令）
 * 0x153770 add r0,r8,#16      → 指向 map 值的 RValue
 *   0x153780 把 5 写进 sp+0x14（即 sp+8 那个 RValue 的 type 槽）—— 见 open 4 的说明
 * 0x153788 YYGetInt32(value,0) → r0 = 0..4
 * 0x153790 cmp #4 / 0x153794 addls pc,pc,r0,lsl#2 → 表基 0x15379c，五个 case 各自先把请求码写进
 *   g_storeStatus（0x3f2358）：Activate=0、Acquire/Consume/ProductDetail=2、Restore=3、默认=1。
 *   写状态用的是 r3 = [GOT 0x3efacc]（文件内 addend 0x3f2358，R_ARM_RELATIVE），**不是**代码地址。 */
/* @0x15376c mov r3, #0 */
/* @0x153770 add r0, r8, #16 */
/* @0x153774 mov r1, r3 */
/* @0x153778 str r3, [sp, #0x10] */
/* @0x15377c str r3, [sp, #0x8] */
/* @0x153780 mov r3, #5 */
/* @0x153784 str r3, [sp, #0x14] */
/* @0x153788 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x15378c ldr r3, [pc, #0x31c] */
/* @0x153790 cmp r0, #4 */
/* @0x153794 addls pc, pc, r0, lsl #2 */
/* @0x153798 b 0x153a4c <_Z16InitIAPFunctionsv+0x578> */
/* @0x15379c b 0x1537f4 <_Z16InitIAPFunctionsv+0x320> */
/* @0x1537a0 b 0x153808 <_Z16InitIAPFunctionsv+0x334> */
/* @0x1537a4 b 0x15394c <_Z16InitIAPFunctionsv+0x478> */
/* @0x1537a8 b 0x1539cc <_Z16InitIAPFunctionsv+0x4f8> */
/* @0x1537ac b 0x1537bc <_Z16InitIAPFunctionsv+0x2e8> */
/* @0x1537b0 mov r0, r4 */
/* @0x1537b4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1537b8 b 0x15376c <_Z16InitIAPFunctionsv+0x298> */
/* ---- case 4：IAP_RestoreM() ----*/
/* @0x1537bc ldr r3, [r5, r3] */
/* @0x1537c0 mov r2, #3 */
/* @0x1537c4 str r2, [r3] */
/* @0x1537c8 bl 0x16186c <_Z12IAP_RestoreMv> */
/* ---- A 段公共尾：map 存槽 + 销毁 + 解锁 ----
 * 0x1537cc bl FindFreeDsMapIndex(0x100014) → r0 = 空槽号
 * 0x1537d0 ldr r3,[pc,#0x2dc] → 池字 0x153ab4 = 0xffffbcec → [0x3ed944] = &g_iap(0x4836b0)
 * 0x1537d8 ldr r3,[r3,#4] → g_iap+4 = ds_map id 数组基址
 * 0x1537dc str r6,[r3,r0,lsl#2] → 数组[idx] = 本次请求的 map
 * 0x1537e0 DestroyDsMap(map,0x205334)；0x1537e8 ~DS_AutoMutex；0x1537f0 pop {r4-r10,pc}
 * —— **注意执行顺序是"先存槽再销毁"**：存进去的是 map 句柄，DestroyDsMap 之后该句柄不再有效，
 *   但槽表保留它给上层查询（这是本段唯一"看起来危险"的地方，见 open 5）。 */
/* @0x1537cc bl 0x100014 <_Z18FindFreeDsMapIndexv> */
/* @0x1537d0 ldr r3, [pc, #0x2dc] */
/* @0x1537d4 ldr r3, [r5, r3] */
/* @0x1537d8 ldr r3, [r3, #0x4] */
/* @0x1537dc str r6, [r3, r0, lsl #2] */
/* @0x1537e0 bl 0x205334 <_Z12DestroyDsMapi> */
/* @0x1537e4 mov r0, r7 */
/* @0x1537e8 bl 0xfec6c <_ZN12DS_AutoMutexD2Ev> */
/* @0x1537ec add sp, sp, #24 */
/* @0x1537f0 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ---- case 0：IAP_Activate() ----*/
/* @0x1537f4 ldr r3, [r5, r3] */
/* @0x1537f8 mov r2, #0 */
/* @0x1537fc str r2, [r3] */
/* @0x153800 bl 0x16173c <_Z13IAP_ActivateMv> */
/* @0x153804 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* ---- case 1：IAP_Acquire(product, qty) ----
 * 0x153810 YYSetString(&rv,"product") → Find → 校验字符串类型 → YYGetInt32 取 qty
 * 0x1538e4 读 map["purchaseIndex-ish"]... 实为命中值的 type（[r8,#0x1c]）；
 * 0x15391c 取 [r10,#0x10]（字符串指针）→ r8 = 该串；0x153934 YYGetInt32 取数量；
 * 0x153944 IAP_Acquire(product, id, n)（签名 _Z12IAP_AcquireMPKcS0_i）。*/
/* @0x153808 ldr r3, [r5, r3] */
/* @0x15380c mov r0, r4 */
/* @0x153810 ldr r1, [pc, #0x2a0] */
/* @0x153814 mov r2, #2 */
/* @0x153818 add r1, pc, r1 */
/* @0x15381c str r2, [r3] */
/* @0x153820 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153824 mov r0, r6 */
/* @0x153828 mov r1, r4 */
/* @0x15382c bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153830 ldr r3, [sp, #0x14] */
/* @0x153834 sub r3, r3, #1 */
/* @0x153838 bic r3, r3, #-16777216 */
/* @0x15383c bic r3, r3, #3 */
/* @0x153840 cmp r3, #0 */
/* @0x153844 mov r8, r0 */
/* @0x153848 beq 0x153a5c <_Z16InitIAPFunctionsv+0x588> */
/* @0x15384c ldr r1, [pc, #0x268] */
/* @0x153850 mov r0, r4 */
/* @0x153854 mov r3, #0 */
/* @0x153858 mov r2, #5 */
/* @0x15385c add r1, pc, r1 */
/* @0x153860 str r3, [sp, #0x10] */
/* @0x153864 str r3, [sp, #0x8] */
/* @0x153868 str r2, [sp, #0x14] */
/* @0x15386c bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153870 mov r0, r6 */
/* @0x153874 mov r1, r4 */
/* @0x153878 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x15387c ldr r3, [sp, #0x14] */
/* @0x153880 sub r3, r3, #1 */
/* @0x153884 bic r3, r3, #-16777216 */
/* @0x153888 bic r3, r3, #3 */
/* @0x15388c cmp r3, #0 */
/* @0x153890 mov r9, r0 */
/* @0x153894 beq 0x153a8c <_Z16InitIAPFunctionsv+0x5b8> */
/* @0x153898 ldr r1, [pc, #0x220] */
/* @0x15389c mov r0, r4 */
/* @0x1538a0 mov r3, #0 */
/* @0x1538a4 mov r2, #5 */
/* @0x1538a8 add r1, pc, r1 */
/* @0x1538ac str r3, [sp, #0x10] */
/* @0x1538b0 str r3, [sp, #0x8] */
/* @0x1538b4 str r2, [sp, #0x14] */
/* @0x1538b8 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1538bc mov r0, r6 */
/* @0x1538c0 mov r1, r4 */
/* @0x1538c4 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1538c8 ldr r3, [sp, #0x14] */
/* @0x1538cc sub r3, r3, #1 */
/* @0x1538d0 bic r3, r3, #-16777216 */
/* @0x1538d4 bic r3, r3, #3 */
/* @0x1538d8 cmp r3, #0 */
/* @0x1538dc mov r10, r0 */
/* @0x1538e0 beq 0x153a80 <_Z16InitIAPFunctionsv+0x5ac> */
/* @0x1538e4 ldr r1, [r8, #0x1c] */
/* @0x1538e8 mov r3, #0 */
/* @0x1538ec mov r2, #5 */
/* @0x1538f0 str r3, [sp, #0x10] */
/* @0x1538f4 bic r1, r1, #-16777216 */
/* @0x1538f8 str r3, [sp, #0x8] */
/* @0x1538fc cmp r1, #1 */
/* @0x153900 str r2, [sp, #0x14] */
/* @0x153904 movne r4, r3 */
/* @0x153908 beq 0x153a98 <_Z16InitIAPFunctionsv+0x5c4> */
/* @0x15390c ldr r3, [r10, #0x1c] */
/* @0x153910 bic r3, r3, #-16777216 */
/* @0x153914 cmp r3, #1 */
/* @0x153918 movne r8, #0 */
/* @0x15391c bne 0x15392c <_Z16InitIAPFunctionsv+0x458> */
/* @0x153920 ldr r8, [r10, #0x10] */
/* @0x153924 cmp r8, #0 */
/* @0x153928 ldrne r8, [r8] */
/* @0x15392c add r0, r9, #16 */
/* @0x153930 mov r1, #0 */
/* @0x153934 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x153938 mov r1, r8 */
/* @0x15393c mov r2, r0 */
/* @0x153940 mov r0, r4 */
/* @0x153944 bl 0x16189c <_Z12IAP_AcquireMPKcS0_i> */
/* @0x153948 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* ---- case 2：IAP_Consume(product) ----*/
/* @0x15394c ldr r3, [r5, r3] */
/* @0x153950 mov r0, r4 */
/* @0x153954 ldr r1, [pc, #0x168] */
/* @0x153958 mov r2, #2 */
/* @0x15395c add r1, pc, r1 */
/* @0x153960 str r2, [r3] */
/* @0x153964 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x153968 mov r0, r6 */
/* @0x15396c mov r1, r4 */
/* @0x153970 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x153974 ldr r3, [sp, #0x14] */
/* @0x153978 sub r3, r3, #1 */
/* @0x15397c bic r3, r3, #-16777216 */
/* @0x153980 bic r3, r3, #3 */
/* @0x153984 cmp r3, #0 */
/* @0x153988 mov r8, r0 */
/* @0x15398c beq 0x153a74 <_Z16InitIAPFunctionsv+0x5a0> */
/* @0x153990 ldr r1, [r8, #0x1c] */
/* @0x153994 mov r3, #0 */
/* @0x153998 mov r2, #5 */
/* @0x15399c str r3, [sp, #0x10] */
/* @0x1539a0 bic r1, r1, #-16777216 */
/* @0x1539a4 str r3, [sp, #0x8] */
/* @0x1539a8 cmp r1, #1 */
/* @0x1539ac str r2, [sp, #0x14] */
/* @0x1539b0 movne r0, r3 */
/* @0x1539b4 bne 0x1539c4 <_Z16InitIAPFunctionsv+0x4f0> */
/* @0x1539b8 ldr r0, [r8, #0x10] */
/* @0x1539bc cmp r0, r3 */
/* @0x1539c0 ldrne r0, [r0] */
/* @0x1539c4 bl 0x161940 <_Z12IAP_ConsumeMPKc> */
/* @0x1539c8 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* ---- case 3：IAP_GetProductDetailM(product) ----*/
/* @0x1539cc ldr r3, [r5, r3] */
/* @0x1539d0 mov r0, r4 */
/* @0x1539d4 ldr r1, [pc, #0xec] */
/* @0x1539d8 mov r2, #2 */
/* @0x1539dc add r1, pc, r1 */
/* @0x1539e0 str r2, [r3] */
/* @0x1539e4 bl 0xdc308 <_Z11YYSetStringP6RValuePKc> */
/* @0x1539e8 mov r0, r6 */
/* @0x1539ec mov r1, r4 */
/* @0x1539f0 bl 0x2034e4 <_ZN7CDS_Map4FindEP6RValue> */
/* @0x1539f4 ldr r3, [sp, #0x14] */
/* @0x1539f8 sub r3, r3, #1 */
/* @0x1539fc bic r3, r3, #-16777216 */
/* @0x153a00 bic r3, r3, #3 */
/* @0x153a04 cmp r3, #0 */
/* @0x153a08 mov r8, r0 */
/* @0x153a0c beq 0x153a68 <_Z16InitIAPFunctionsv+0x594> */
/* @0x153a10 ldr r1, [r8, #0x1c] */
/* @0x153a14 mov r3, #0 */
/* @0x153a18 mov r2, #5 */
/* @0x153a1c str r3, [sp, #0x10] */
/* @0x153a20 bic r1, r1, #-16777216 */
/* @0x153a24 str r3, [sp, #0x8] */
/* @0x153a28 cmp r1, #1 */
/* @0x153a2c str r2, [sp, #0x14] */
/* @0x153a30 movne r0, r3 */
/* @0x153a34 bne 0x153a44 <_Z16InitIAPFunctionsv+0x570> */
/* @0x153a38 ldr r0, [r8, #0x10] */
/* @0x153a3c cmp r0, r3 */
/* @0x153a40 ldrne r0, [r0] */
/* @0x153a44 bl 0x161ae8 <_Z21IAP_GetProductDetailMPKc> */
/* @0x153a48 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* ---- default：type 越界（>4）→ 只写状态 1，不调平台 ----*/
/* @0x153a4c ldr r3, [r5, r3] */
/* @0x153a50 mov r2, #1 */
/* @0x153a54 str r2, [r3] */
/* @0x153a58 b 0x1537cc <_Z16InitIAPFunctionsv+0x2f8> */
/* @0x153a5c mov r0, r4 */
/* @0x153a60 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a64 b 0x15384c <_Z16InitIAPFunctionsv+0x378> */
/* @0x153a68 mov r0, r4 */
/* @0x153a6c bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a70 b 0x153a10 <_Z16InitIAPFunctionsv+0x53c> */
/* @0x153a74 mov r0, r4 */
/* @0x153a78 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a7c b 0x153990 <_Z16InitIAPFunctionsv+0x4bc> */
/* @0x153a80 mov r0, r4 */
/* @0x153a84 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a88 b 0x1538e4 <_Z16InitIAPFunctionsv+0x410> */
/* @0x153a8c mov r0, r4 */
/* @0x153a90 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x153a94 b 0x153898 <_Z16InitIAPFunctionsv+0x3c4> */
/* @0x153a98 ldr r4, [r8, #0x10] */
/* @0x153a9c cmp r4, r3 */
/* @0x153aa0 ldrne r4, [r4] */
/* @0x153aa4 b 0x15390c <_Z16InitIAPFunctionsv+0x438> */
/* @0x153aa8 eoreq lr, r9, r8, lsl r5 —— 非指令（池字 0x29e518：GOT 基址偏移，0x153738 处 add r5,pc,r5 用） */
/* @0x153aac andseq r2, pc, r12, ror #19 —— 非指令（池字 0x1f29ec → 串 "type" @0x346130） */
/* @0x153ab0 .word 0xffffde74 —— 非指令（池字 0xffffde74：GOT 偏移 -0x218c → 槽 0x3efacc） */
/* @0x153ab4 .word 0xffffbcec —— 非指令（池字 0xffffbcec：GOT 偏移 -0x4314 → 槽 0x3ed944） */
/* @0x153ab8 andseq r2, pc, r8, lsl r9 —— 非指令（池字 0x1f2918 → 串 "product" @0x346138） */
/* @0x153abc ldrsbeq r2, [pc], -r12 —— 非指令（池字 0x1f28dc → 串 "purchaseIndex" @0x346140） */
/* @0x153ac0 andseq r2, pc, r0, lsr #17 —— 非指令（池字 0x1f28a0 → 串 "payload" @0x346150） */
/* @0x153ac4 ldrsbeq r2, [pc], -r4 —— 非指令（池字 0x1f27d4 → 串 "product" @0x346138） */
/* @0x153ac8 andseq r2, pc, r4, asr r7 —— 非指令（池字 0x1f2754 → 串 "product" @0x346138） */
/* ---- B 段：不是函数，只是提交器的 GOT 基址准备（3 条），直落进 C ----*/
/* @0x153acc ldr r3, [pc, #0xf4] */
/* @0x153ad0 ldr r2, [pc, #0xf4] */
/* @0x153ad4 add r3, pc, r3 */
/* ---- C 段入口：提交器（r0 = iap ds_map，r1 = 请求种类 0..4）----
 * 0x153ad8 push {r4,r5,lr} / sub sp,#12；r4 = map
 * 0x153ae0 ldr r2,[r3,r2] → 槽 0x3efacc → 0x3f2358 = &g_storeStatus
 * 0x153ae8 ldr r2,[r2]     → 当前 store 状态
 * 0x153aec add r2,#2 / cmp #4 / addls pc,pc,r2,lsl#2 → 表基 0x153afc（状态 -2..2 五路）
 *   0/1 → 0x153b10，2 → 0x153b58，3 → 0x153b40，4 → 0x153b58
 * —— r1 是"种类"：F_IAP_Activate 传 0（0x154c30-0x154c34 mov r1,r4,r4=0），
 *    F_IAP_RestoreAll 传 4（0x1552e0 mov r1,#4）。 */
/* @0x153ad8 push {r4, r5, lr} */
/* @0x153adc mov r4, r0 */
/* @0x153ae0 ldr r2, [r3, r2] */
/* @0x153ae4 sub sp, sp, #12 */
/* @0x153ae8 ldr r2, [r2] */
/* @0x153aec add r2, r2, #2 */
/* ---- 五路跳表（表基 0x153afc）----*/
/* @0x153af0 cmp r2, #4 */
/* @0x153af4 addls pc, pc, r2, lsl #2 */
/* @0x153af8 b 0x153b38 <_Z16InitIAPFunctionsv+0x664> */
/* @0x153afc b 0x153b10 <_Z16InitIAPFunctionsv+0x63c> */
/* @0x153b00 b 0x153b10 <_Z16InitIAPFunctionsv+0x63c> */
/* @0x153b04 b 0x153b58 <_Z16InitIAPFunctionsv+0x684> */
/* @0x153b08 b 0x153b40 <_Z16InitIAPFunctionsv+0x66c> */
/* @0x153b0c b 0x153b58 <_Z16InitIAPFunctionsv+0x684> */
/* ---- 状态 -2/-1（store 不可用）----
 * kind==0（Activate）→ 0x153b48 尾跳执行器 A（Activate 允许在未就绪时先跑）
 * kind!=0 → 0x153b18 取串 0x346158 "BILLING: Request ignored; Store is not available\n"，
 *   0x153b24..0x153b34 经全局日志对象 vptr[+0xc](self, msg) 输出，然后 0x153b38 返回。 */
/* @0x153b10 cmp r1, #0 */
/* @0x153b14 beq 0x153b48 <_Z16InitIAPFunctionsv+0x674> */
/* @0x153b18 ldr r1, [pc, #0xb0] */
/* @0x153b1c ldr r2, [pc, #0xb0] */
/* @0x153b20 add r1, pc, r1 */
/* @0x153b24 ldr r3, [r3, r2] */
/* @0x153b28 ldr r0, [r3] */
/* @0x153b2c ldr r3, [r0] */
/* @0x153b30 ldr r3, [r3, #0xc] */
/* @0x153b34 blx r3 */
/* @0x153b38 add sp, sp, #12 */
/* @0x153b3c pop {r4, r5, pc} */
/* ---- 状态 1（store 已加载）----
 * kind==0（重复 Activate）→ 0x153ba8 取串 0x3461c8 "BILLING: Activate request ignored;
 *   Store has already loaded\n" → 0x153bb4 跳 0x153b24 打日志
 * kind!=0 → 0x153b48 尾跳 A。 */
/* @0x153b40 cmp r1, #0 */
/* @0x153b44 beq 0x153ba8 <_Z16InitIAPFunctionsv+0x6d4> */
/* ---- 直接执行路径：pop 掉本帧后尾跳 A 段（不是新函数）----
 * 0x153b48 mov r0,r4（map 交回）→ add sp,#12 → pop {r4,r5,lr} → 0x153b54 b 0x153710
 * 这就是 split 表把 0x153b54 单独切成 148 B 段的原因（有 bl 从这里进），实际是 A 的第二个入口。 */
/* @0x153b48 mov r0, r4 */
/* @0x153b4c add sp, sp, #12 */
/* @0x153b50 pop {r4, r5, lr} */
/* ---- A 段尾跳入口（被 anon_b6fd0 的 bl 直接落进来，见 open 2）----*/
/* @0x153b54 b 0x153710 <_Z16InitIAPFunctionsv+0x23c> */
/* ---- 状态 0/2：延后入队 ----
 * 0x153b5c ldr r5,[pc,#0x74] → 池字 0x153bd8 = 0x29e7e0 → r5 = 0x3f2348（队列结构）
 * 0x153b60 ldr r1,[pc,#0x74] → 池字 0x153bdc = 0x1f2618 → 串 0x34618c
 *   "BILLING: Request deferred, store isn't available right now\n" → 0x153b7c blx vptr[+0xc]
 * 0x153b80 ldr r0,[r5,#4] → 队列 id；0x153b84 cmn r0,#1（== -1）→ 0x153bb8 DsQueueCreate
 * 0x153b9c DsQueueEnqueue(q, 1, 0, 0, map)（第 5 个参数 [sp] = r4 = map）
 * —— **入队的是 map 句柄本身**，五个参数里 r1=1 是事件类型、r2/r3=0 是保留位。 */
/* @0x153b58 ldr r2, [pc, #0x74] */
/* @0x153b5c ldr r5, [pc, #0x74] */
/* @0x153b60 ldr r1, [pc, #0x74] */
/* @0x153b64 ldr r3, [r3, r2] */
/* @0x153b68 add r5, pc, r5 */
/* @0x153b6c add r1, pc, r1 */
/* @0x153b70 ldr r0, [r3] */
/* @0x153b74 ldr r3, [r0] */
/* @0x153b78 ldr r3, [r3, #0xc] */
/* @0x153b7c blx r3 */
/* @0x153b80 ldr r0, [r5, #0x4] */
/* @0x153b84 cmn r0, #1 */
/* @0x153b88 beq 0x153bb8 <_Z16InitIAPFunctionsv+0x6e4> */
/* @0x153b8c str r4, [sp] */
/* @0x153b90 mov r1, #1 */
/* @0x153b94 mov r2, #0 */
/* @0x153b98 mov r3, #0 */
/* @0x153b9c bl 0x2054a4 <_Z17DsQueueEnqueuePtriiz> */
/* @0x153ba0 add sp, sp, #12 */
/* @0x153ba4 pop {r4, r5, pc} */
/* ---- 重复 Activate 的日志串（0x3461c8）----*/
/* @0x153ba8 ldr r1, [pc, #0x30] */
/* @0x153bac ldr r2, [pc, #0x20] */
/* @0x153bb0 add r1, pc, r1 */
/* @0x153bb4 b 0x153b24 <_Z16InitIAPFunctionsv+0x650> */
/* ---- 首次入队：DsQueueCreate() 后把 id 存进 g_queue+4 ----*/
/* @0x153bb8 bl 0x2053bc <_Z13DsQueueCreatev> */
/* @0x153bbc mov r3, r0 */
/* @0x153bc0 str r3, [r5, #0x4] */
/* @0x153bc4 b 0x153b8c <_Z16InitIAPFunctionsv+0x6b8> */
/* @0x153bc8 eoreq lr, r9, r12, ror r1 —— 非指令（池字 0x29e17c：GOT 基址偏移，0x153ad4 处 add r3,pc,r3 用） */
/* @0x153bcc .word 0xffffde74 —— 非指令（池字 0xffffde74：GOT 偏移 -0x218c → 槽 0x3efacc） */
/* @0x153bd0 andseq r2, pc, r0, lsr r6 —— 非指令（池字 0x1f2630 → 串 "Request ignored; Store is not available" @0x346158） */
/* @0x153bd4 .word 0xffffbcf0 —— 非指令（池字 0xffffbcf0：GOT 偏移 -0x4310 → 槽 0x3ed948） */
/* @0x153bd8 eoreq lr, r9, r0, ror #15 —— 非指令（池字 0x29e7e0 → 0x3f2348 队列结构） */
/* @0x153bdc andseq r2, pc, r8, lsl r6 —— 非指令（池字 0x1f2618 → 串 "Request deferred" @0x34618c） */
/* @0x153be0 andseq r2, pc, r0, lsl r6 —— 非指令（池字 0x1f2610 → 串 "Activate request ignored" @0x3461c8） */


/* ═══════════════════════════════════════════════════════════════════════
 * §4  anon_230674 = vorbisfile 的 _bisect_forward_serialno（链式流二分定位，递归）
 * ═══════════════════════════════════════════════════════════════════════
 *
 * 身份证据（四条）
 *   ① 位置：本段是匿名大块 0x22fd0c（4,536 B，functions.tsv 记 anon_22fd0c）的第 7 个切块
 *      （anon_splits.tsv parent=0x22fd0c，[0x230674,+1268)），整块夹在 0x22fc7c
 *      vorbis_packet_blocksize 与 0x230ec4 ov_clear 之间 —— 正是 vorbisfile.c 静态函数群的位置。
 *   ② 调用面：整块 0x22fd0c..0x230ec0 里 bl 到 ogg_page_serialno(10 次)、ogg_page_bos(4)、
 *      ogg_page_granulepos(3)、ogg_stream_pagein(5)、ogg_stream_packetout(4)、ogg_sync_pageseek(2)、
 *      ogg_stream_reset_serialno(2)、vorbis_synthesis_pcmout(4) —— 全是 vorbisfile 的工具箱。
 *   ③ 本段**自递归**（0x230948 bl 0x230674 是唯一递归点），全程 64 位偏移运算（ldrd/strd/sbcs 在
 *      0x2306e8-0x2306f4、0x230738-0x23074c、0x230858-0x23089c 反复出现），并 malloc/realloc 建数组
 *      （0x230ab8..0x230b04 六连分配）。vorbisfile 里同时满足"递归 + 64 位 offset + 建链"的只有
 *      _bisect_forward_serialno。
 *   ④ 错误码：0x230b3c 直接返回 **-128 = OV_EREAD**（vorbisfile 的"读媒体出错"常量），
 *      0x23094c 用 `subs r12,r0,#0 / bne` 判返回值，成功路径 0x230b30 返回 r12=0。
 *
 * 契约（骨架级，11 个机器字实参）
 *   int anon_230674(OggVorbis_File *vf,  ogg_int64_t begin,  ogg_int64_t searched,
 *                   ogg_int64_t end,  ogg_uint32_t *current_serialno,
 *                   ogg_int64_t *dataoffset,  int *chained)
 *   落位（本段实测）：r0 = vf（+0x1c8 在入口被读进 r9）；r2:r3 = begin（r1 是 AAPCS 的 64 位对齐
 *   空档，从入口起没被读）；[sp+0xd0]:[sp+0xd4] = searched；[sp+0xd8]:[sp+0xdc] = end；
 *   [sp+0xe8] = current_serialno（进入后被本函数改作局部槽，0x230a4c 有 str）；
 *   [sp+0xec] = dataoffset；[sp+0xf0] = chained。
 *   返回：0 成功；-128 OV_EREAD（读页失败，0x230b3c）；其余值原样透传（0x230b4c）。
 *   vf 字段：**+8 = vf->offset**，本函数在三处写它（0x230864 / 0x23088c / 0x230b2c 的 strd），
 *   即"边搜边把读位置推进"；+0x1c8 入 r9 当页码/偏移缓存。
 *   —— 参数布局与 vorbisfile `_bisect_forward_serialno(vf, begin, searched, end, currentno,
 *      dataoffset, chained)` 的 3×int64 + 3 指针完全对齐（0xe0/0xe4 全段从未被读 → 只有三组 int64，
 *      说明这一版没有 endsearch 参数）。函数名属**推断**，证据链在 ①-④，见 open 1。
 *
 * 结构（317 字，无池字）
 *   0x230674..0x23068c  序言：push {r4-r11,lr} / sub sp,#172 → 帧 208 B；vf→r6、begin→r4:r5、
 *                       [0xec]→r8、[0xf0]→r10、[0xe8]→r0、*(vf+0x1c8)→r9
 *   0x230690..0x2306e4  小线性扫描：在 r8 指向的 serialno 表里找 r0（0x2306d0 的 ldr/比较/回边）
 *   0x2306e8..0x230704  64 位比较（ldrd + sbcs）：begin/searched/end 谁大谁小决定入口分支；
 *                       bge 0x230b5c 走"直接进主循环"
 *   0x230708..0x230844  主二分循环：反复算中点（64 位减 + 移位）、比对 end/searched
 *   0x230858..0x2308ac  取页主体：strd 写 vf+8（offset）→ bl 0x230048（_get_prev_page 候选）循环
 *                       直到页码不再变（0x230890 bne 回边）→ bl 0x22ffe0（_seek_helper 候选）
 *   0x2308b8..0x230928  分派：bl 0x22fd0c / 0x230334 / 0x22fed4（同块其它切块）与 ogg_page_serialno
 *   0x23092c..0x230950  递归准备 + **bl 0x230674**；返回非 0 → 0x230b30 透传
 *   0x230954..0x230a24  递归后的链更新循环（0x230a24 b 0x230838 回边）
 *   0x230a38..0x230a9c  错误展开：三处 free@plt(0x230964/0x230a7c/0x230a8c/0x230a9c)
 *   0x230ab8..0x230b04  malloc/realloc 六连（links 链数组扩容）+ __errno
 *   0x230b28..0x230b64  收尾：strd 写回 vf+8；0x230b30 add sp,#172 / pop {r4-r11,pc}；
 *                       0x230b3c 返回 -128（OV_EREAD）
 * ═══════════════════════════════════════════════════════════════════════ */
/* @func 0x230674 0x230b64 anon_230674 vorbisfile_bisect_forward_serialno */
/* ---- 序言：9 个实参落位（vf/begin/searched/end/3 指针），帧 208 B ----
 * 0x230674 push {r4-r11,lr}（保存 lr → 有调用，且自己是递归函数）
 * 0x230678 sub sp,#172：帧 172 + 保存区 36 = 208 B；调用者栈实参从 sp+0xd0 起
 *   r6 = vf（r0）／r4:r5 = begin（r2:r3）／r8 = [sp+0xec]／r10 = [sp+0xf0]／r0 = [sp+0xe8]
 *   r9 = *(vf+0x1c8)（0x23068c）；0x230690-0x2306a0 把本地 64 位槽 [sp+96] 置 -1（mvn #0 两次 + strd）
 * 0x2306a8 beq 0x2306e8：r8 为空 → 跳过扫描；0x2306b0 同判 r10 为空
 * 0x2306b4..0x2306e4：以 [r8] 为表头、按 4 B 步长线性找 r0（r3 计数、r12 上限 r10-1） */
/* @0x230674 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x230678 sub sp, sp, #172 */
/* @0x23067c mov r6, r0 */
/* @0x230680 mov r4, r2 */
/* @0x230684 ldr r8, [sp, #0xec] */
/* @0x230688 mov r5, r3 */
/* @0x23068c ldr r9, [r0, #0x1c8] */
/* @0x230690 mvn r2, #0 */
/* @0x230694 cmp r8, #0 */
/* @0x230698 mvn r3, #0 */
/* @0x23069c ldr r10, [sp, #0xf0] */
/* @0x2306a0 strd r2, r3, [sp, #96] */
/* @0x2306a4 ldr r0, [sp, #0xe8] */
/* @0x2306a8 beq 0x2306e8 <vorbis_packet_blocksize+0xa6c> */
/* @0x2306ac cmp r10, #0 */
/* @0x2306b0 beq 0x2306e8 <vorbis_packet_blocksize+0xa6c> */
/* @0x2306b4 ldr r3, [r8] */
/* @0x2306b8 cmp r0, r3 */
/* @0x2306bc subne r12, r10, #1 */
/* @0x2306c0 movne r2, r8 */
/* @0x2306c4 movne r3, #0 */
/* @0x2306c8 bne 0x2306dc <vorbis_packet_blocksize+0xa60> */
/* @0x2306cc b 0x230a28 <vorbis_packet_blocksize+0xdac> */
/* @0x2306d0 ldr r1, [r2, #0x4]! */
/* @0x2306d4 cmp r0, r1 */
/* @0x2306d8 beq 0x230a28 <vorbis_packet_blocksize+0xdac> */
/* @0x2306dc cmp r3, r12 */
/* @0x2306e0 add r3, r3, #1 */
/* @0x2306e4 bne 0x2306d0 <vorbis_packet_blocksize+0xa54> */
/* ---- 64 位入口判据：begin vs searched vs end ----
 * 0x2306e8/0x2306ec 两组 ldrd 取 [sp+216](=searched) 与 [sp+208](=begin)
 * 0x2306f0 cmp / 0x2306f4 sbcs r3,r1,r3 → 64 位无符号比较（ARM 的高低位借位链）
 * 0x230704 bge 0x230b5c → 已搜区间够大：直接跳到主循环入口（0x230b5c 把 end 装进 [sp+72] 后 b 0x230858）
 * 否则 0x230708 起把两个 64 位值装进 r10:r11 与 [sp+72]，进入 0x230738 的主循环。 */
/* @0x2306e8 ldrd r2, r3, [sp, #216] */
/* @0x2306ec ldrd r0, r1, [sp, #208] */
/* @0x2306f0 cmp r0, r2 */
/* @0x2306f4 sbcs r3, r1, r3 */
/* @0x2306f8 mov r3, #0 */
/* @0x2306fc str r3, [sp, #0x58] */
/* @0x230700 str r3, [sp, #0x5c] */
/* @0x230704 bge 0x230b5c <vorbis_packet_blocksize+0xee0> */
/* @0x230708 ldrd r0, r1, [sp, #216] */
/* @0x23070c sub r7, r10, #1 */
/* @0x230710 add r11, sp, #104 */
/* @0x230714 str r9, [sp, #0x54] */
/* @0x230718 str r8, [sp, #0x44] */
/* @0x23071c mov r9, r6 */
/* @0x230720 str r10, [sp, #0x50] */
/* @0x230724 mov r8, r7 */
/* @0x230728 str r11, [sp, #0x38] */
/* @0x23072c mov r10, r0 */
/* @0x230730 mov r11, r1 */
/* @0x230734 strd r0, r1, [sp, #72] */
/* ---- 主二分循环（每轮把区间折半）----
 * 0x230738 ldrd [sp+208] / 0x23073c movw r0,#0x7fff（掩码/上限）→ 0x230748 subs 做 64 位相减
 * 后续用 lsr/asr 把差值右移得到中点，再与 searched 比较决定往哪半边走；
 * 0x230844 blt 0x230738 是回边（区间还大就继续折半）。 */
/* @0x230738 ldrd r2, r3, [sp, #208] */
/* @0x23073c movw r0, #0x7fff */
/* @0x230740 mov r1, #0 */
/* @0x230744 ldrd r4, r5, [sp, #208] */
/* @0x230748 subs r2, r10, r2 */
/* @0x23074c sbc r3, r11, r3 */
/* @0x230750 cmp r0, r2 */
/* @0x230754 sbcs r1, r1, r3 */
/* @0x230758 bge 0x230778 <vorbis_packet_blocksize+0xafc> */
/* @0x23075c adds r4, r4, r10 */
/* @0x230760 adc r5, r5, r11 */
/* @0x230764 lsr r3, r5, #31 */
/* @0x230768 adds r4, r4, r3 */
/* @0x23076c adc r5, r5, #0 */
/* @0x230770 asrs r5, r5, #1 */
/* @0x230774 rrx r4, r4 */
/* @0x230778 ldrd r2, r3, [r9, #8] */
/* @0x23077c cmp r3, r5 */
/* @0x230780 cmpeq r2, r4 */
/* @0x230784 beq 0x2307a0 <vorbis_packet_blocksize+0xb24> */
/* @0x230788 mov r0, r9 */
/* @0x23078c mov r2, r4 */
/* @0x230790 mov r3, r5 */
/* @0x230794 bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x230798 cmp r0, #0 */
/* @0x23079c bne 0x230b4c <vorbis_packet_blocksize+0xed0> */
/* @0x2307a0 mvn r2, #0 */
/* @0x2307a4 mvn r3, #0 */
/* @0x2307a8 mov r0, r9 */
/* @0x2307ac ldr r1, [sp, #0x38] */
/* @0x2307b0 bl 0x22fd0c <vorbis_packet_blocksize+0x90> */
/* @0x2307b4 mvn r2, #127 */
/* @0x2307b8 mvn r3, #0 */
/* @0x2307bc mov r6, r0 */
/* @0x2307c0 mov r7, r1 */
/* @0x2307c4 cmp r7, r3 */
/* @0x2307c8 cmpeq r6, r2 */
/* @0x2307cc beq 0x230b3c <vorbis_packet_blocksize+0xec0> */
/* @0x2307d0 cmp r6, #0 */
/* @0x2307d4 sbcs r3, r7, #0 */
/* @0x2307d8 blt 0x230830 <vorbis_packet_blocksize+0xbb4> */
/* @0x2307dc ldr r0, [sp, #0x38] */
/* @0x2307e0 bl 0x23409c <ogg_page_serialno> */
/* @0x2307e4 ldr r1, [sp, #0x44] */
/* @0x2307e8 cmp r1, #0 */
/* @0x2307ec beq 0x23082c <vorbis_packet_blocksize+0xbb0> */
/* @0x2307f0 ldr r2, [sp, #0x50] */
/* @0x2307f4 cmp r2, #0 */
/* @0x2307f8 beq 0x23082c <vorbis_packet_blocksize+0xbb0> */
/* @0x2307fc ldr r3, [r1] */
/* @0x230800 cmp r0, r3 */
/* @0x230804 beq 0x230a1c <vorbis_packet_blocksize+0xda0> */
/* @0x230808 mov r2, r1 */
/* @0x23080c mov r3, #0 */
/* @0x230810 b 0x230820 <vorbis_packet_blocksize+0xba4> */
/* @0x230814 ldr r1, [r2, #0x4]! */
/* @0x230818 cmp r0, r1 */
/* @0x23081c beq 0x230a1c <vorbis_packet_blocksize+0xda0> */
/* @0x230820 cmp r3, r8 */
/* @0x230824 add r3, r3, #1 */
/* @0x230828 bne 0x230814 <vorbis_packet_blocksize+0xb98> */
/* @0x23082c strd r6, r7, [sp, #72] */
/* @0x230830 mov r10, r4 */
/* @0x230834 mov r11, r5 */
/* @0x230838 ldrd r0, r1, [sp, #208] */
/* @0x23083c cmp r0, r10 */
/* @0x230840 sbcs r1, r1, r11 */
/* @0x230844 blt 0x230738 <vorbis_packet_blocksize+0xabc> */
/* @0x230848 mov r6, r9 */
/* @0x23084c ldr r8, [sp, #0x44] */
/* @0x230850 ldr r9, [sp, #0x54] */
/* @0x230854 ldr r10, [sp, #0x50] */
/* ---- 取页主体：先落 offset，再反复取上一页直到页码稳定 ----
 * 0x230858 ldrd r0,r1,[sp,72]（本层 offset）→ 0x230864 strd r0,r1,[r6,#8]  ← **vf->offset = 当前搜索位置**
 * 0x230868 循环头：r3=sp+136（ogg_page）、[sp]=sp+96（granulepos 槽），bl 0x230048（同块第 4 切块，取页）
 * 0x23088c 再把 r0:r1 写回 vf+8（取页后游标推进），0x230890 bne 0x230868 直到返回页码与 r9 相同
 * 0x230894..0x2308a0 拿 [sp+72] 与返回值做 64 位 cmpeq；不等 → 0x2308a4 bl 0x22ffe0（同块第 3 切块，
 *   移动读位置）。 */
/* @0x230858 ldrd r0, r1, [sp, #72] */
/* @0x23085c add r4, sp, #136 */
/* @0x230860 add r5, sp, #96 */
/* @0x230864 strd r0, r1, [r6, #8] */
/* @0x230868 mov r3, r4 */
/* @0x23086c str r5, [sp] */
/* @0x230870 mov r0, r6 */
/* @0x230874 mov r1, r8 */
/* @0x230878 mov r2, r10 */
/* @0x23087c str r9, [sp, #0x88] */
/* @0x230880 bl 0x230048 <vorbis_packet_blocksize+0x3cc> */
/* @0x230884 ldr r3, [sp, #0x88] */
/* @0x230888 cmp r3, r9 */
/* @0x23088c strd r0, r1, [r6, #8] */
/* @0x230890 bne 0x230868 <vorbis_packet_blocksize+0xbec> */
/* @0x230894 ldrd r8, r9, [sp, #72] */
/* @0x230898 cmp r1, r9 */
/* @0x23089c cmpeq r0, r8 */
/* @0x2308a0 beq 0x2308b8 <vorbis_packet_blocksize+0xc3c> */
/* @0x2308a4 mov r0, r6 */
/* @0x2308a8 ldrd r2, r3, [sp, #72] */
/* @0x2308ac bl 0x22ffe0 <vorbis_packet_blocksize+0x364> */
/* @0x2308b0 subs r12, r0, #0 */
/* @0x2308b4 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* ---- 分派：同块其它切块 + ogg 层接口 ----
 * 0x2308b8..0x2308dc：bl 0x230048 / 0x230334（同块第 6 切块，取包/处理包）—— 三处调用共享同一组
 *   栈上 out 参数（sp+72 的 64 位、sp+96 的 granulepos、sp+136 的 ogg_page）
 * 0x230904 bl 0x22fed4（同块第 2 切块，算 PCM 偏移候选）
 * 0x2307e0 bl 0x23409c ogg_page_serialno —— 本段唯一直接调 ogg 具名 API 的点。 */
/* @0x2308b8 add r5, sp, #120 */
/* @0x2308bc mov r3, #0 */
/* @0x2308c0 add r2, sp, #92 */
/* @0x2308c4 str r3, [sp, #0x4] */
/* @0x2308c8 str r2, [sp] */
/* @0x2308cc mov r0, r6 */
/* @0x2308d0 mov r2, r5 */
/* @0x2308d4 mov r1, r4 */
/* @0x2308d8 add r3, sp, #88 */
/* @0x2308dc bl 0x230334 <vorbis_packet_blocksize+0x6b8> */
/* @0x2308e0 subs r12, r0, #0 */
/* @0x2308e4 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x2308e8 ldr r9, [sp, #0xf4] */
/* @0x2308ec mov r0, r6 */
/* @0x2308f0 mov r1, r4 */
/* @0x2308f4 ldr r10, [r6, #0x1c8] */
/* @0x2308f8 add r7, r9, #1 */
/* @0x2308fc ldrd r8, r9, [r6, #8] */
/* @0x230900 strd r8, r9, [sp, #56] */
/* @0x230904 bl 0x22fed4 <vorbis_packet_blocksize+0x258> */
/* @0x230908 ldrd r8, r9, [r6, #8] */
/* @0x23090c ldrd r2, r3, [sp, #216] */
/* @0x230910 ldr r12, [sp, #0x58] */
/* @0x230914 strd r8, r9, [sp] */
/* @0x230918 ldrd r8, r9, [sp, #224] */
/* @0x23091c strd r2, r3, [sp, #8] */
/* @0x230920 str r12, [sp, #0x1c] */
/* @0x230924 str r7, [sp, #0x24] */
/* @0x230928 ldrd r2, r3, [sp, #72] */
/* ---- 递归：对"后半段"再二分一次 ----
 * 0x23092c ldrd r2,r3,[sp+72]（新的 begin）→ 0x23092c/0x230930/0x230934 把 r8:r9、r0:r1 存进
 *   递归帧的 out 槽（sp+16 / sp+48），r1 = [sp+0xe8]、[sp+0x20] = [sp+0x5c]
 * 0x230948 bl 0x230674 ← **自递归**（同一函数，上一层的 out 指针下传）
 * 0x23094c subs r12,r0,#0 / 0x230950 bne 0x230b30：子调用失败 → 原样返回其错误码
 * 成功则 0x230954 起检查 [sp+0x58] 的链标志，继续把本层结果并回去。 */
/* @0x23092c strd r8, r9, [sp, #16] */
/* @0x230930 strd r0, r1, [sp, #48] */
/* @0x230934 mov r0, r6 */
/* @0x230938 ldr r1, [sp, #0xe8] */
/* @0x23093c str r1, [sp, #0x18] */
/* @0x230940 ldr r1, [sp, #0x5c] */
/* @0x230944 str r1, [sp, #0x20] */
/* @0x230948 bl 0x230674 <vorbis_packet_blocksize+0x9f8> */
/* @0x23094c subs r12, r0, #0 */
/* @0x230950 bne 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x230954 ldr r0, [sp, #0x58] */
/* @0x230958 cmp r0, #0 */
/* @0x23095c beq 0x23096c <vorbis_packet_blocksize+0xcf0> */
/* @0x230960 str r12, [sp, #0x2c] */
/* @0x230964 bl 0xb655c <free@plt> */
/* @0x230968 ldr r12, [sp, #0x2c] */
/* @0x23096c lsl r8, r7, #3 */
/* @0x230970 str r8, [sp, #0x44] */
/* @0x230974 ldr r2, [r6, #0x38] */
/* @0x230978 ldr r3, [r6, #0x40] */
/* @0x23097c ldrd r8, r9, [sp, #72] */
/* @0x230980 ldr r11, [sp, #0x44] */
/* @0x230984 strd r8, r9, [r2, r11] */
/* @0x230988 lsl r8, r7, #4 */
/* @0x23098c str r10, [r3, r7, lsl #2] */
/* @0x230990 add r9, r8, #8 */
/* @0x230994 ldr r3, [r6, #0x48] */
/* @0x230998 ldr r11, [r6, #0x4c] */
/* @0x23099c add r7, r3, r7, lsl #5 */
/* @0x2309a0 str r8, [sp, #0x54] */
/* @0x2309a4 ldm r4!, {r0, r1, r2, r3} */
/* @0x2309a8 add r11, r11, r8 */
/* @0x2309ac str r9, [sp, #0x48] */
/* @0x2309b0 ldr r8, [sp, #0x44] */
/* @0x2309b4 ldr r9, [r6, #0x3c] */
/* @0x2309b8 str r11, [sp, #0x50] */
/* @0x2309bc ldrd r10, r11, [sp, #56] */
/* @0x2309c0 ldr r6, [r6, #0x44] */
/* @0x2309c4 strd r10, r11, [r9, r8] */
/* @0x2309c8 ldr r10, [sp, #0x54] */
/* @0x2309cc stm r7!, {r0, r1, r2, r3} */
/* @0x2309d0 add r8, r6, r10 */
/* @0x2309d4 ldm r4, {r0, r1, r2, r3} */
/* @0x2309d8 ldrd r10, r11, [sp, #96] */
/* @0x2309dc strd r10, r11, [sp, #56] */
/* @0x2309e0 stm r7, {r0, r1, r2, r3} */
/* @0x2309e4 ldm r5, {r0, r1, r2, r3} */
/* @0x2309e8 ldr r11, [sp, #0x50] */
/* @0x2309ec stm r11, {r0, r1, r2, r3} */
/* @0x2309f0 ldrd r10, r11, [sp, #56] */
/* @0x2309f4 strd r10, r11, [r8, #-8] */
/* @0x2309f8 ldrd r8, r9, [sp, #48] */
/* @0x2309fc ldr r10, [sp, #0x54] */
/* @0x230a00 ldr r11, [sp, #0x48] */
/* @0x230a04 strd r8, r9, [r6, r10] */
/* @0x230a08 ldrd r2, r3, [r6, r11] */
/* @0x230a0c subs r2, r2, r8 */
/* @0x230a10 sbc r3, r3, r9 */
/* @0x230a14 strd r2, r3, [r6, r11] */
/* @0x230a18 b 0x230b30 <vorbis_packet_blocksize+0xeb4> */
/* @0x230a1c ldrd r2, r3, [r9, #8] */
/* @0x230a20 strd r2, r3, [sp, #208] */
/* @0x230a24 b 0x230838 <vorbis_packet_blocksize+0xbbc> */
/* @0x230a28 cmp r9, r0 */
/* @0x230a2c addne r11, sp, #232 */
/* @0x230a30 addne r7, sp, #224 */
/* @0x230a34 beq 0x230a64 <vorbis_packet_blocksize+0xde8> */
/* ---- 错误展开：先释放本层已分配的中间数组，再返回错误码 ----
 * 0x230a38..0x230a60 循环里 bl 0x230048（取页）+ free@plt(0x230a7c/0x230a8c/0x230a9c)
 * 0x2309xx 的失败路径都汇到这里（jump target 被多条 bne/beq 共享），保证"半成品不泄漏"。 */
/* @0x230a38 mov r3, r11 */
/* @0x230a3c str r7, [sp] */
/* @0x230a40 mov r0, r6 */
/* @0x230a44 mov r1, r8 */
/* @0x230a48 mov r2, r10 */
/* @0x230a4c str r9, [sp, #0xe8] */
/* @0x230a50 bl 0x230048 <vorbis_packet_blocksize+0x3cc> */
/* @0x230a54 ldr r3, [sp, #0xe8] */
/* @0x230a58 cmp r3, r9 */
/* @0x230a5c strd r0, r1, [r6, #8] */
/* @0x230a60 bne 0x230a38 <vorbis_packet_blocksize+0xdbc> */
/* @0x230a64 ldr r0, [r6, #0x38] */
/* @0x230a68 ldr r8, [sp, #0xf4] */
/* @0x230a6c cmp r0, #0 */
/* @0x230a70 add r7, r8, #1 */
/* @0x230a74 str r7, [r6, #0x34] */
/* @0x230a78 beq 0x230a80 <vorbis_packet_blocksize+0xe04> */
/* @0x230a7c bl 0xb655c <free@plt> */
/* @0x230a80 ldr r0, [r6, #0x40] */
/* @0x230a84 cmp r0, #0 */
/* @0x230a88 beq 0x230a90 <vorbis_packet_blocksize+0xe14> */
/* @0x230a8c bl 0xb655c <free@plt> */
/* @0x230a90 ldr r0, [r6, #0x3c] */
/* @0x230a94 cmp r0, #0 */
/* @0x230a98 beq 0x230aa0 <vorbis_packet_blocksize+0xe24> */
/* @0x230a9c bl 0xb655c <free@plt> */
/* @0x230aa0 ldr r8, [r6, #0x34] */
/* @0x230aa4 mov r12, #0 */
/* @0x230aa8 str r12, [sp, #0x2c] */
/* @0x230aac lsl r7, r7, #3 */
/* @0x230ab0 add r0, r8, #1 */
/* @0x230ab4 lsl r0, r0, #3 */
/* ---- 建链数组：malloc/realloc 六连 ----
 * 0x230ab8 malloc@plt / 0x230ac8+0x230adc realloc@plt / 0x230aec..0x230b04 三次 malloc@plt
 * 中间穿插 __errno(0xb6bf8) 取错误号 —— 典型的"扩容失败就回 OV_EREAD/ENOMEM"写法；
 * 分配出来的是 serialno/offset 链数组（本函数递归返回后由上层把各层结果串起来）。 */
/* @0x230ab8 bl 0xb6544 <malloc@plt> */
/* @0x230abc lsl r1, r8, #5 */
/* @0x230ac0 str r0, [r6, #0x38] */
/* @0x230ac4 ldr r0, [r6, #0x48] */
/* @0x230ac8 bl 0xb6c28 <realloc@plt> */
/* @0x230acc ldr r1, [r6, #0x34] */
/* @0x230ad0 lsl r1, r1, #4 */
/* @0x230ad4 str r0, [r6, #0x48] */
/* @0x230ad8 ldr r0, [r6, #0x4c] */
/* @0x230adc bl 0xb6c28 <realloc@plt> */
/* @0x230ae0 ldr r8, [r6, #0x34] */
/* @0x230ae4 str r0, [r6, #0x4c] */
/* @0x230ae8 lsl r0, r8, #2 */
/* @0x230aec bl 0xb6544 <malloc@plt> */
/* @0x230af0 str r0, [r6, #0x40] */
/* @0x230af4 lsl r0, r8, #3 */
/* @0x230af8 bl 0xb6544 <malloc@plt> */
/* @0x230afc str r0, [r6, #0x3c] */
/* @0x230b00 lsl r0, r8, #4 */
/* @0x230b04 bl 0xb6544 <malloc@plt> */
/* @0x230b08 ldr r3, [r6, #0x38] */
/* @0x230b0c ldrd r10, r11, [sp, #216] */
/* @0x230b10 ldr r9, [sp, #0xf4] */
/* @0x230b14 ldr r12, [sp, #0x2c] */
/* @0x230b18 str r0, [r6, #0x44] */
/* @0x230b1c add r0, r0, r9, lsl #4 */
/* @0x230b20 strd r10, r11, [r3, r7]! */
/* @0x230b24 strd r4, r5, [r3, #-8] */
/* ---- 收尾：写回 vf+8，按 r12 返回 ----
 * 0x230b28 ldrd [sp+224] → 0x230b2c strd [r0,#8]（vf->offset 最终值）
 * 0x230b30 mov r0,r12 / add sp,#172 / pop {r4-r11,pc} ← 正常返回（r12 = 子调用或本层的返回值）
 * 0x230b3c mvn r12,#127 → **-128 = OV_EREAD**，读页失败的唯一硬错误码
 * 0x230b4c mov r12,r0 → 原样透传（另一个出口，返回调用者给的值）
 * 0x230b5c..0x230b64 主循环入口：把 end 装进 [sp+72] 后 b 0x230858（不回栈，纯尾跳）。 */
/* @0x230b28 ldrd r2, r3, [sp, #224] */
/* @0x230b2c strd r2, r3, [r0, #8] */
/* @0x230b30 mov r0, r12 */
/* @0x230b34 add sp, sp, #172 */
/* @0x230b38 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b3c mvn r12, #127 */
/* @0x230b40 mov r0, r12 */
/* @0x230b44 add sp, sp, #172 */
/* @0x230b48 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b4c mov r12, r0 */
/* @0x230b50 mov r0, r12 */
/* @0x230b54 add sp, sp, #172 */
/* @0x230b58 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x230b5c ldrd r2, r3, [sp, #216] */
/* @0x230b60 strd r2, r3, [sp, #72] */
/* @0x230b64 b 0x230858 <vorbis_packet_blocksize+0xbdc> */


/* ═══════════════════════════════════════════════════════════════════════
 * open（本卡没钉死的六处）
 *   1. §1 的 63 个常量对 vs MD5 的 64 项 T 表：少的不是常量而是"同一 T 值相邻步复用同一寄存器"，
 *      具体哪一步复用没有逐条比对 T 表（要比对得把 64 步的加数逐条对到 T[i]，本卡只做到轮/移位闭合）。
 *   2. §4 的函数名 _bisect_forward_serialno 是**推断**：依据是位置（vorbis_packet_blocksize 与
 *      ov_clear 之间）、调用面（ogg_page_serialno/ogg_stream_*）、自递归 + 三组 int64 + 六连
 *      malloc/realloc、以及 -128/OV_EREAD 错误码。要钉死得对上 vorbisfile 源码里该函数的参数表
 *      （本机没有 vorbisfile 源码可比），本卡只到"vorbisfile 的递归二分定位函数"这一层。
 *   3. §4 里 r9 的用法没读透：0x230888 把 [sp+0x88]（进循环前存的 r9）与 r9 比，r9 是 callee-saved，
 *      静态上这条 bne 恒不成立；可能是编译器把某个会被调用的 out 参数复用成了 r9，本卡未追。
 *   4. §3 公共尾 0x1537cc 的顺序是 FindFreeDsMapIndex → 表[idx]=r6 → DestroyDsMap(r0 仍是 idx)。
 *      存进去的是 CDS_Map 指针、销毁的却是槽号，静态上读不出"谁来释放这个指针"——
 *      要么 DestroyDsMap 内部按号取回对象再删（那就是正常交接），要么这里就是一处悬垂指针。
 *      本卡只记顺序，不下结论。
 *   5. §3 执行器 0x153778-0x153784 把 0x00000005 写进 sp+0x14（即 sp+8 处 RValue 的 type 槽），
 *      但紧接着传给 YYGetInt32 的是 r0 = 命中值指针（r8+0x10），并没有用这个临时 RValue。
 *      这三条 str 到底给谁用（可能是编译器为后面某个分支预留的槽），本卡未追。
 *   6. §2 的三份 b2QueryCallback 删除析构共用同一 vtable 槽、且与具名 D0Ev 并存：推测是多 TU 弱符号
 *      未合并（每个 TU 各发一份），未验证 .symtab 的 weak 属性（本 .so 已 strip）。
 *
 * 未做（明确不做，避免越界）
 *   · 没有上设备跑任何一段（本任务禁碰设备），所有"运行期才定"的点都留在 open 里。
 *   · 没有改 asm/ 下任何既有索引，也没有动别人的卡；本卡只新增四个 index-anon_*.tsv。
 * ═══════════════════════════════════════════════════════════════════════ */
