/* cally 逆向卡：CSprite::DrawDictionaryItem（原版 libyoyo.so，armv7）
 * @func 0x1e9c10 0x1eba8c  size 7808  1952 字（17 个池字：1ea0d0 = 0.0f（s30 的常量）+
 *       1ea0d4/d8/dc 三个 GOT 偏移 + 1ea0e0..f8 七个 .word + 1eba78..8c 六个 .word；真指令 1935）
 * 级别: 正文（1952/1952 逐条落锚；形参落位、两道守卫、24/84 B 两级记录遍历、四条顶点变换通道、
 *       双色流水（p7/p8/p9/p10/p11）、十处 AllocVerts 提交（16/24 B 顶点）、分块上限、
 *       type 1/2/3 的纹理与矩阵合成全部证到指令。
 *       未钉：element->+0x08 颜色表为何用「点数」当下标；AllocVerts 第 2 形参(Pvi)语义
 *       （实参是 Texture* 或 0）；ePrimType=4 的枚举名；+0x3ed71c 告警单例的类名；
 *       渐变底位图路径（1eb82c..）里两组 diag 的取整次序只到「先乘后除」这一级）
 * 符号: _ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff
 *       → int CSprite::DrawDictionaryItem(SWF_DictionaryItem* item, yyMatrix m, float f3,
 *                                        bool b4, bool b5, yyMatrix* p6, uint* p7, uint* p8,
 *                                        int* p9, int* p10, int* p11, Texture* p12,
 *                                        float f13, float f14)
 * 同层: CSprite::DrawSWF 0x1ebf08、DrawShape 0x1ed768（唯一调用者，4 个调用点 1edce0/1ee1ec/
 *       1ee3fc/1ee654）、DrawSWFObject 0x1eba90、Graphics::AllocVerts 0x185418、
 *       Graphics::GetMaxDynamicVertexCount 0x18561c、yyMatrix::Multiply 0x27aa00、
 *       RenderStateManager::SetSamplerState 0x167ef4、GR_Texture_Exists 0x173e2c
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   这是 SWF 形状的**唯一顶点出口**：把 item（形状定义）→ 24 B 元素 → 84 B 子记录 里的四组点
 *   用同一个 yyMatrix 变换到四块 .bss 静态缓冲，再按「线/填充 × AA边/实心 × 16B/24B」十条通道
 *   调 Graphics::AllocVerts 直接写顶点；本函数一条 GR_Texture_Draw 都没有，纹理只以
 *   「Texture* 交给 AllocVerts」+「SetSamplerState 改两处采样器状态」的形式出现。
 *   返回值 = 本次提交的三角形总数。
 *
 * ── 重点 1 · 顶点变换（四条通道，同一个矩阵）──────────────────────
 *   四条循环完全同构（1e9df8 / 1e9e8c / 1e9f5c / 1e9fe8），只差源、目标与是否叠加上一遍结果：
 *     ① 填充点  记录+0x00（count +0x30）→ g_SWFvertbuff      x' = x·m0 + y·m4 + m12
 *     ② 填充 AA 记录+0x18（count +0x48）→ g_SWFaavertbuff     out = M·(src·f3) + ①
 *     ③ 线点    记录+0x0c（count +0x3c）→ g_SWFlinevertbuff   同 ①
 *     ④ 线 AA   记录+0x20（count +0x50）→ g_SWFlineaavertbuff  out = M·(src·f3) + ③
 *   ⇒ 「行向量 × 列主序 4×4」：m0/m1 = x 基、m4/m5 = y 基、m12/m13 = 平移；m2/m3/m6/m7/m14/m15
 *     全函数一次都没读。AA 顶点不是独立几何，而是「主点 + f3·偏移点」——f3 就是 DrawShape
 *     用 Graphics 三矩阵合成算出的那个归一化比例，这里只当乘数用。
 *   四个目标缓冲都是 512 KB（32768 点 × 16 B）且基址相邻 0x80000，.dynsym 具名：
 *     g_SWFlineaavertbuff 0x5530c8 / g_SWFaavertbuff 0x5d30c8 /
 *     g_SWFlinevertbuff   0x6530c8 / g_SWFvertbuff    0x6d30c8
 *   取用方式：GOT 基址 0x3f1c58 + 负偏移 0xfffff188/8c/90/94 → 四个槽 0x3f0de0..0x3f0dec。
 *
 * ── 重点 2 · 纹理绑定（三条路径，零 GR_Texture_Draw）───────────────
 *   type 1（实色）：纹理 = 形参 p12；顶点 24 B，uv 恒为 (f13,f14) ⇒ 整批采一个 texel。
 *   type 2（位图）：bmp = this->+0x54[子对象->+0x08]；texid = (int16)bmp->+20；
 *                   GR_Texture_Exists(texid) 为 0 就整条跳过；纹理对象从
 *                   (*GOT 0x3ed924)->+4[texid] 取，+4/+8 = 宽高；
 *                   uv 矩阵 = bmp[+0x0c] · p6 · diag(矩形/(w,h))（三次 Multiply）。
 *   type 3（渐变）：rec = this->+0x7c[子对象->+0x0c]；若 rec->+0x10 >= 0 → 走「渐变底是位图」
 *                   分支（与 type 2 共用 UV 矩阵段）；否则 diag(1/w,1/h)·obj[+0x10] 作 uv 矩阵。
 *   采样器：SetSamplerState(rsm, idx, 2, v) 与 (…,3,v)，v = 子对象->+0x04 ∈{0,2} ? 该值 : 1；
 *           rsm = *GOT 0x3edd00（.bss 0x4859c8，与 DrawShape 同一槽）。本函数不改回，属调用方契约。
 *
 * ── 重点 3 · 批量提交（10 处 AllocVerts）──────────────────────────
 *   Graphics::AllocVerts(ePrimType=4, Pvi, stride, count) 返回可写顶点块，本函数填完就走；
 *   1ea838/1eb378 之外没有任何 flush/绘制调用 ⇒ 批次由 Graphics 记账、帧末统一提交（推断）。
 *   顶点格式：16 B = {x, y, z, colour}；24 B = {x, y, z, colour, u, v}；
 *   z 取 *GOT 0x3ed928 的全局 float（每批重读一次），colour 是 ARGB。
 *   分块：单元数 = min(记录计数, maxVerts/6)（四边形）或 min(计数, maxVerts/3)（三角形），
 *         maxVerts 来自 Graphics::GetMaxDynamicVertexCount()，循环切批直到剩余为 0。
 *   十处提交（地址 / 索引 / 点数 / 顶点 / uv）：
 *     1ea154 线AA边 16B (+0x1c,+0x4c) · 1ea390 线实心 16B (+0x10,+0x40)
 *     1ea560 线AA边 24B (+0x1c,+0x4c) · 1ea7cc 线实心 24B (+0x10,+0x40)
 *     1eaa08 实色填充 24B (+0x14,+0x44) · 1eac84 实色填充三角 24B (+0x08,+0x38)
 *     1eaf18 位图/渐变填充 24B · 1eb2a8 位图/渐变三角 24B
 *     1eb3f4 实色填充 16B(b5=0) · 1eb630 实色填充三角 16B(b5=0)
 *
 * ── 颜色流水（两个颜色一份调色板）────────────────────────────────
 *   基色 = 元素->+0x08[r12]（r12 = 上一变换循环的计数，b4=0 时是填充点数，否则 AA 点数 —— 二进制事实）
 *   C  = clamp8( p11[k] + (p9[k]·((基色×p7[k])>>8) >> 8) )      ⇒ 主顶点颜色
 *   C2 = clamp8( p11[k] + (p9[k]·((基色×p8[k])>>8) >> 8) )      ⇒ AA 顶点颜色
 *   （type 2/3 那一份把偏移换成 p10；调用者传 p10/p11 是同一个指针 obj+196）
 *   ⇒ p7/p8 = 填充/AA 两个 ARGB 乘子，p9 = 通道缩放，p10/p11 = 通道偏移。
 *
 * ── 数据模型（两级记录，全部只有用法证据）─────────────────────────
 *   item（SWF_DictionaryItem）: +0x00 = 1（标签）· +0x08 元素数组 · +0x1c 元素数
 *   element（24 B）: +0x00 子记录数组 · +0x04 子对象指针表 · +0x08 颜色表 · +0x0c 子记录数
 *   record（84 B）: +0x00 填充点 · +0x08 填充三角索引 · +0x0c 线点 · +0x10 线三角索引
 *                   +0x14 填充四边形索引 · +0x18 填充AA点 · +0x1c 线四边形索引 · +0x20 线AA点
 *                   +0x28 子对象下标 · +0x2c 闸(>=0) · +0x30/38/3c/40/44/48/4c/50 八个计数
 *   subobj: +0x00 类型(1/2/3) · +0x04 颜色或采样器位 · +0x08 位图下标 · +0x0c 渐变下标
 *
 * ── 与纹理档（cards/CSprite_Draw.c）的差异 ──────────────────────
 *   ① 不看 this+0x74 后端档位，也不看 g_SWF_AA（0x7530c8）：AA 几何无条件生成，只受 b4 控制。
 *   ② 不读 g(0x3f0ddc)/g2(0x3ee5c0)，不做 deg→rad 换算、不做四边剔除、不用 CProfiler。
 *   ③ 状态责任更弱：只写采样器 2/3 两处，不保存不还原（DrawSWF 存/还原 8 项）。
 *
 * ── 调用计数（本函数 30 个调用点）────────────────────────────────
 *   Graphics::AllocVerts ×10 · yyMatrix::Multiply ×7 · RenderStateManager::SetSamplerState ×8 ·
 *   GR_Texture_Exists ×2 · Graphics::GetMaxDynamicVertexCount ×1 · 虚调用 blx ×2（告警）
 *   store：435 条（238 条 sp 相对；其余全部写四块 .bss 顶点缓冲或 AllocVerts 顶点块，零条写 this）
 */

/* ══ 段 A · 入口：帧 608、形参落位、两道守卫 ═══════════════════════════════════════════════
 *   序言：sub 8 + push 9×4 + vpush 8×8 + sub 500 ⇒ 帧 608 = 0x260；栈形参从 sp+608 起。
 *   形参落位（与唯一调用者 CSprite::DrawShape 1edc50 起的实参块互证）：
 *     r0  = CSprite* this            → [sp+0xa8]
 *     r1  = SWF_DictionaryItem* item → [sp+0xa0]
 *     r2/r3 = m0/m1（yyMatrix 头两字）→ stmib 落到 sp+600/604
 *     sp+608..663 = m2..m15（14 字）  ⇒ 16 字矩阵在 sp+600..663 连成整块
 *     sp+664 f3(float) · sp+668 b4(bool) · sp+672 b5(bool) · sp+676 p6(yyMatrix*)
 *     sp+680 p7(uint*) · sp+684 p8(uint*) · sp+688 p9(int*) · sp+692 p10(int*)
 *     sp+696 p11(int*) · sp+700 p12(Texture*) · sp+704 f13(float) · sp+708 f14(float)
 *   ★ 「矩阵 2 寄存器 + 14 栈字」不是教科书 AAPCS 拆法，但调用侧实参与取参逐项对齐，
 *     且 callee 立刻把 r2/r3 补回 sp+600/604 拼成连续 64 B ⇒ 按二进制事实记。
 *   ★ 返回值 = 本次提交的三角形总数（累加在 [sp+0x54]，出口 1e9cec 读出）。
 */

/* @0x1e9c10 sub sp, sp, #8 */
/* @0x1e9c14 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e9c18 vpush {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1e9c1c sub sp, sp, #500 */
/* @0x1e9c20 vldr s20, [sp, #664] */
/* @0x1e9c24 ldr r4, [sp, #0x2a8] */
/* @0x1e9c28 ldr r5, [sp, #0x2a8] */
/* @0x1e9c2c ldr r6, [sp, #0x2a8] */
/* @0x1e9c30 ldr r7, [sp, #0x2a8] */
/* @0x1e9c34 ldr r8, [sp, #0x2ac] */
/* @0x1e9c38 ldr r9, [sp, #0x2ac] */
/* @0x1e9c3c ldr r10, [sp, #0x2ac] */
/* @0x1e9c40 ldr r11, [sp, #0x2ac] */
/* @0x1e9c44 ldr r9, [r9, #0x4] */

/* ── 8 个颜色通道 + 2 个 bool 先落栈 ────────────────────────────────────────────────
 *   [sp+0x68..0x74] = p7[0..3]、[sp+0x78..0x84] = p8[0..3]，两组都是 B,G,R,A 四通道。
 *   [sp+0x60] = b4、[sp+0x88] = b5：两把闸后面各管一半流程（b4=AA/纹理通道，b5=第二色阶段）。
 */

/* @0x1e9c48 ldr r4, [r4] */
/* @0x1e9c4c ldr r5, [r5, #0x4] */
/* @0x1e9c50 ldr r6, [r6, #0x8] */
/* @0x1e9c54 ldr r7, [r7, #0xc] */
/* @0x1e9c58 ldr r8, [r8] */
/* @0x1e9c5c ldr r10, [r10, #0x8] */
/* @0x1e9c60 ldr r11, [r11, #0xc] */

/* ── 矩阵与浮点形参进 VFP（s16..s29 全是函数级常量）────────────────────────────────
 *   s19/s18 = m0/m1，s17/s16 = m4/m5，s22/s21 = m12/m13，s20 = f3，s29/s28 = f13/f14
 *   ⇒ 16 字矩阵只有 6 个字被单独提进 VFP：x 基 (m0,m1)、y 基 (m4,m5)、平移 (m12,m13)。
 *     m2/m3/m6/m7/m14/m15 全函数一次都没读 —— 2D 仿射用不到第三列/齐次行。
 */

/* @0x1e9c64 ldrb r12, [sp, #0x29c] */
/* @0x1e9c68 str r0, [sp, #0xa8] */
/* @0x1e9c6c add r0, sp, #596 */
/* @0x1e9c70 str r1, [sp, #0xa0] */
/* @0x1e9c74 stmib r0, {r2, r3} */
/* @0x1e9c78 vldr s19, [sp, #600] */
/* @0x1e9c7c str r4, [sp, #0x68] */
/* @0x1e9c80 vldr s18, [sp, #604] */
/* @0x1e9c84 str r5, [sp, #0x6c] */
/* @0x1e9c88 str r6, [sp, #0x70] */
/* @0x1e9c8c str r9, [sp, #0x7c] */
/* @0x1e9c90 str r7, [sp, #0x74] */
/* @0x1e9c94 str r8, [sp, #0x78] */
/* @0x1e9c98 str r10, [sp, #0x80] */
/* @0x1e9c9c str r11, [sp, #0x84] */
/* @0x1e9ca0 str r12, [sp, #0x60] */
/* @0x1e9ca4 vldr s29, [sp, #704] */
/* @0x1e9ca8 ldrb r4, [sp, #0x2a0] */
/* @0x1e9cac vldr s28, [sp, #708] */
/* @0x1e9cb0 vldr s17, [sp, #616] */
/* @0x1e9cb4 vldr s16, [sp, #620] */
/* @0x1e9cb8 vldr s22, [sp, #648] */
/* @0x1e9cbc vldr s21, [sp, #652] */
/* @0x1e9cc0 str r4, [sp, #0x88] */

/* ── 上限来源：Graphics::GetMaxDynamicVertexCount() ────────────────────────────────
 *   1e9cc4 的返回值不是死值：1e9d20/1e9d34 直接拿它做 /6 与 /3（见下）。
 *   1e9ccc 池字 0x00207f7c + pc(1e9cdc) = 0x3f1c58 = 本函数 GOT 基址（与 DrawShape 同一个），
 *   存 [sp+0x44] 后全函数 32 处复用它取槽。
 */

/* @0x1e9cc4 bl 0x18561c <_ZN8Graphics24GetMaxDynamicVertexCountEv> */
/* @0x1e9cc8 ldr r5, [sp, #0xa0] */
/* @0x1e9ccc ldr r6, [pc, #0x400] */
/* @0x1e9cd0 ldr r3, [r5] */
/* @0x1e9cd4 add r6, pc, r6 */
/* @0x1e9cd8 str r6, [sp, #0x44] */

/* ── 两道守卫 ──────────────────────────────────────────────────────────────────────
 *   ① item->+0x00 != 1 → 返回 [sp+0x54]（初值 0：一个三角形都没交）
 *   ② item->+0x1c == 0 → 走 1eba58，同样返回 0
 *   ⇒ item 是 SWF 形状定义：+0x00 类型标签（必须 1），+0x1c 子形状数。
 */

/* @0x1e9cdc cmp r3, #1 */
/* @0x1e9ce0 movne r9, #0 */
/* @0x1e9ce4 strne r9, [sp, #0x54] */
/* @0x1e9ce8 beq 0x1e9d04 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xf4> */
/* @0x1e9cec ldr r0, [sp, #0x54] */
/* @0x1e9cf0 add sp, sp, #500 */
/* @0x1e9cf4 vpop {d8, d9, d10, d11, d12, d13, d14, d15} */
/* @0x1e9cf8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1e9cfc add sp, sp, #8 */
/* @0x1e9d00 bx lr */
/* @0x1e9d04 ldr r3, [r5, #0x1c] */
/* @0x1e9d08 cmp r3, #0 */
/* @0x1e9d0c beq 0x1eba58 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e48> */

/* ── 每批上限：maxVerts/6 与 maxVerts/3 ────────────────────────────────────────────
 *   0x2AAAAAAB 定点乘 + rsb 补符号 = 有符号 /6；0x55555556 同法 = /3。
 *   [sp+0x58] = maxVerts/6（四边形批上限，每单元 6 顶点）；[sp+0x8c] = maxVerts/3（三角形批）。
 *   s30 = 池字 0x00000000 = 0.0f（全函数清矩阵元素用）
 *   [sp+0xac]/[sp+0xa4] = .rodata 0x352620 / 0x3525fc 两个告警串（见 1ea838 / 1eb378）。
 */

/* @0x1e9d10 movw r1, #0xaaab */
/* @0x1e9d14 movw r12, #0x5556 */
/* @0x1e9d18 movt r1, #0x2aaa */
/* @0x1e9d1c movt r12, #0x5555 */
/* @0x1e9d20 asr r2, r0, #31 */
/* @0x1e9d24 ldr r7, [pc, #0x3ac] */
/* @0x1e9d28 smull r8, r1, r1, r0 */
/* @0x1e9d2c vldr s30, [pc, #924] */
/* @0x1e9d30 ldr r9, [pc, #0x3a4] */
/* @0x1e9d34 smull r10, r0, r12, r0 */
/* @0x1e9d38 mov r11, #0 */
/* @0x1e9d3c add r7, pc, r7 */
/* @0x1e9d40 add r9, pc, r9 */
/* @0x1e9d44 rsb r1, r2, r1 */
/* @0x1e9d48 rsb r0, r2, r0 */
/* @0x1e9d4c str r7, [sp, #0xac] */
/* @0x1e9d50 str r9, [sp, #0xa4] */
/* @0x1e9d54 str r1, [sp, #0x58] */
/* @0x1e9d58 str r11, [sp, #0x9c] */
/* @0x1e9d5c str r0, [sp, #0x8c] */

/* ── 外层：24 B 元素数组（item->+0x08，count = item->+0x1c）────────────────────────
 *   r2 = 3*i；元素 = base + 24*i（ldr/str 三连 + lsl#3 的 8 倍步进）。
 *   元素布局（后文取证）：+0x00 子记录数组 · +0x04 子对象指针表 · +0x08 颜色表 · +0x0c 子记录数。
 */

/* @0x1e9d60 str r11, [sp, #0x54] */
/* @0x1e9d64 ldr r12, [sp, #0x9c] */
/* @0x1e9d68 ldr r4, [sp, #0xa0] */
/* @0x1e9d6c add r2, r12, r12, lsl #1 */
/* @0x1e9d70 ldr r1, [r4, #0x8] */
/* @0x1e9d74 add r1, r1, r2, lsl #3 */
/* @0x1e9d78 str r1, [sp, #0x50] */
/* @0x1e9d7c ldr r2, [r1, #0xc] */
/* @0x1e9d80 cmp r2, #0 */
/* @0x1e9d84 beq 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1e9d88 mov r5, #0 */
/* @0x1e9d8c str r5, [sp, #0x48] */

/* ── 内层：84 B 子记录（元素->+0x00，count = 元素->+0x0c）──────────────────────────
 *   记录 = 数组基 + 84*k（mov r6,#84 + mul）。
 *   +0x28 < 0 → 整条跳过（1e9db4 blt）；+0x38 == 0 → 跳过填充点变换（1e9dc0 beq）。
 *   +0x30 = 填充点数（>65536 走 1ea838 告警）；+0x00 = 填充点数组（float2）。
 *   +0x1c = 填充四边形索引（uint16 两两一组），个数 = +0x4c。
 */

/* @0x1e9d90 ldr r7, [sp, #0x48] */
/* @0x1e9d94 mov r6, #84 */
/* @0x1e9d98 ldr r8, [sp, #0x50] */
/* @0x1e9d9c mul r2, r6, r7 */
/* @0x1e9da0 ldr r1, [r8] */
/* @0x1e9da4 add r9, r1, r2 */
/* @0x1e9da8 str r9, [sp, #0x38] */
/* @0x1e9dac ldr r4, [r9, #0x28] */
/* @0x1e9db0 cmp r4, #0 */
/* @0x1e9db4 blt 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9db8 ldr r3, [r9, #0x38] */
/* @0x1e9dbc cmp r3, #0 */
/* @0x1e9dc0 beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9dc4 ldr r12, [r9, #0x30] */
/* @0x1e9dc8 ldr r2, [r1, r2] */
/* @0x1e9dcc cmp r12, #65536 */
/* @0x1e9dd0 bhi 0x1ea838 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc28> */
/* @0x1e9dd4 cmp r12, #65536 */
/* @0x1e9dd8 movhs r12, #65536 */
/* @0x1e9ddc cmp r12, #0 */
/* @0x1e9de0 beq 0x1e9e34 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x224> */
/* @0x1e9de4 ldr r0, [pc, #0x304] */
/* @0x1e9de8 mov r1, #0 */
/* @0x1e9dec ldr r5, [sp, #0x44] */
/* @0x1e9df0 ldr r0, [r5, r0] */
/* @0x1e9df4 add r0, r0, #8 */

/* ── 变换通道 ①：填充点 → g_SWFvertbuff ────────────────────────────────────────────
 *   目标 = *GOT 0x3f0de8（= g_SWFvertbuff，.bss 0x6d30c8，524288 B）+8 预增。
 *   逐点：x' = x·m0 + y·m4 + m12 ；y' = x·m1 + y·m5 + m13。
 *   ★ 即「行向量 × 列主序 4×4」：m0/m1 是 x 基、m4/m5 是 y 基、m12/m13 是平移。
 *   ★ 本函数不读 g(0x3f0ddc)/g2(0x3ee5c0)/g_SWF_AA(0x7530c8)：单位换算与总开关都在 DrawShape 侧。
 */

/* @0x1e9df8 vldr s15, [r2, #4] */
/* @0x1e9dfc vmul.f32 s14, s15, s17 */
/* @0x1e9e00 vldr s13, [r2] */
/* @0x1e9e04 add r1, r1, #1 */
/* @0x1e9e08 cmp r12, r1 */
/* @0x1e9e0c add r2, r2, #8 */
/* @0x1e9e10 add r0, r0, #8 */
/* @0x1e9e14 vmul.f32 s15, s15, s16 */
/* @0x1e9e18 vmla.f32 s14, s13, s19 */
/* @0x1e9e1c vmla.f32 s15, s13, s18 */
/* @0x1e9e20 vadd.f32 s14, s14, s22 */
/* @0x1e9e24 vadd.f32 s15, s15, s21 */
/* @0x1e9e28 vstr s14, [r0, #-16] */
/* @0x1e9e2c vstr s15, [r0, #-12] */
/* @0x1e9e30 bne 0x1e9df8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e8> */

/* ── 变换通道 ②：填充 AA 点 → g_SWFaavertbuff（叠在 ① 上）──────────────────────────
 *   闸：b4 != 0 且 +0x38 != 0 且 +0x48（AA 点数）非 0，点数同样 clamp 65536。
 *   目标 *GOT 0x3f0dec = g_SWFaavertbuff（0x5d30c8），源 +0x18。
 *   公式：out[i] = M·(src[i]·f3) + g_SWFvertbuff[i]（s20 = f3；先乘 f3 进矩阵，再加 ① 的结果）。
 *   ⇒ AA 边不是独立几何，而是「填充点的位移量」：f3 是 DrawShape 三矩阵合成算出的归一化比例，
 *     AA 顶点 = 填充点 + f3·(AA 偏移点)。读回 ① 的 [r0-8]/[r0-4] 就是那一步 vadd。
 */

/* @0x1e9e34 ldr r11, [sp, #0x60] */
/* @0x1e9e38 cmp r11, #0 */
/* @0x1e9e3c beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e40 ldr r7, [sp, #0x38] */
/* @0x1e9e44 ldr r2, [r7, #0x18] */
/* @0x1e9e48 cmp r2, #0 */
/* @0x1e9e4c beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e50 ldr r5, [r7, #0x48] */
/* @0x1e9e54 cmp r5, #65536 */
/* @0x1e9e58 bhi 0x1eb378 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1768> */
/* @0x1e9e5c cmp r5, #65536 */
/* @0x1e9e60 movhs r5, #65536 */
/* @0x1e9e64 cmp r5, #0 */
/* @0x1e9e68 beq 0x1e9edc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2cc> */
/* @0x1e9e6c ldr r9, [sp, #0x44] */
/* @0x1e9e70 mov r12, #0 */
/* @0x1e9e74 ldr r0, [pc, #0x274] */
/* @0x1e9e78 ldr r1, [pc, #0x274] */
/* @0x1e9e7c ldr r0, [r9, r0] */
/* @0x1e9e80 ldr r1, [r9, r1] */
/* @0x1e9e84 add r0, r0, #8 */
/* @0x1e9e88 add r1, r1, #8 */
/* @0x1e9e8c vldr s15, [r2, #4] */
/* @0x1e9e90 vmul.f32 s15, s15, s20 */
/* @0x1e9e94 vldr s13, [r2] */
/* @0x1e9e98 vldr s11, [r0, #-4] */
/* @0x1e9e9c vldr s12, [r0, #-8] */
/* @0x1e9ea0 add r12, r12, #1 */
/* @0x1e9ea4 cmp r5, r12 */
/* @0x1e9ea8 add r2, r2, #8 */
/* @0x1e9eac add r0, r0, #8 */
/* @0x1e9eb0 add r1, r1, #8 */
/* @0x1e9eb4 vmul.f32 s14, s15, s16 */
/* @0x1e9eb8 vmul.f32 s13, s13, s20 */
/* @0x1e9ebc vmul.f32 s15, s15, s17 */
/* @0x1e9ec0 vmla.f32 s14, s13, s18 */
/* @0x1e9ec4 vmla.f32 s15, s13, s19 */
/* @0x1e9ec8 vadd.f32 s14, s14, s11 */
/* @0x1e9ecc vadd.f32 s15, s15, s12 */
/* @0x1e9ed0 vstr s14, [r1, #-12] */
/* @0x1e9ed4 vstr s15, [r1, #-16] */
/* @0x1e9ed8 bne 0x1e9e8c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x27c> */

/* ── 子对象分派：元素->+0x04[记录->+0x28] 的 +0x00 是填充类型 ──────────────────────
 *   1 → 1ea85c（实色填充）  2/3 → 1ead0c（位图 / 渐变）  其它 → 1e9f08（只画线）
 *   1e9efc/1e9f00：sub r3,r7,#2; cmp r3,#1; bls ⇒ 2 与 3 同门。
 */

/* @0x1e9edc ldr r6, [sp, #0x50] */
/* @0x1e9ee0 ldr r2, [r6, #0x4] */
/* @0x1e9ee4 ldr r6, [r2, r4, lsl #2] */
/* @0x1e9ee8 cmp r6, #0 */
/* @0x1e9eec beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1e9ef0 ldr r7, [r6] */
/* @0x1e9ef4 cmp r7, #1 */
/* @0x1e9ef8 beq 0x1ea85c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc4c> */
/* @0x1e9efc sub r3, r7, #2 */
/* @0x1e9f00 cmp r3, #1 */
/* @0x1e9f04 bls 0x1ead0c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10fc> */

/* ── 变换通道 ③：线（描边）点 → g_SWFlinevertbuff ──────────────────────────────────
 *   闸：+0x2c >= 0 且 +0x40 != 0；点数 = +0x3c，clamp 65536；源 +0x0c。
 *   目标 *GOT 0x3f0de4 = g_SWFlinevertbuff（0x6530c8），公式同 ①。
 */

/* @0x1e9f08 ldr r10, [sp, #0x38] */
/* @0x1e9f0c ldr r12, [r10, #0x2c] */
/* @0x1e9f10 cmp r12, #0 */
/* @0x1e9f14 blt 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1e9f18 ldr r1, [r10, #0x40] */
/* @0x1e9f1c cmp r1, #0 */
/* @0x1e9f20 beq 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */
/* @0x1e9f24 ldr r3, [r10, #0xc] */
/* @0x1e9f28 cmp r3, #0 */
/* @0x1e9f2c beq 0x1e9f98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x388> */
/* @0x1e9f30 ldr r5, [sp, #0x38] */
/* @0x1e9f34 ldr r4, [r5, #0x3c] */
/* @0x1e9f38 cmp r4, #65536 */
/* @0x1e9f3c movhs r4, #65536 */
/* @0x1e9f40 cmp r4, #0 */
/* @0x1e9f44 beq 0x1e9f98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x388> */
/* @0x1e9f48 ldr r0, [pc, #0x194] */
/* @0x1e9f4c mov r2, #0 */
/* @0x1e9f50 ldr r6, [sp, #0x44] */
/* @0x1e9f54 ldr r0, [r6, r0] */
/* @0x1e9f58 add r0, r0, #8 */
/* @0x1e9f5c vldr s15, [r3, #4] */
/* @0x1e9f60 vmul.f32 s14, s15, s17 */
/* @0x1e9f64 vldr s13, [r3] */
/* @0x1e9f68 add r2, r2, #1 */
/* @0x1e9f6c cmp r4, r2 */
/* @0x1e9f70 add r3, r3, #8 */
/* @0x1e9f74 add r0, r0, #8 */
/* @0x1e9f78 vmul.f32 s15, s15, s16 */
/* @0x1e9f7c vmla.f32 s14, s13, s19 */
/* @0x1e9f80 vmla.f32 s15, s13, s18 */
/* @0x1e9f84 vadd.f32 s14, s14, s22 */
/* @0x1e9f88 vadd.f32 s15, s15, s21 */
/* @0x1e9f8c vstr s14, [r0, #-16] */
/* @0x1e9f90 vstr s15, [r0, #-12] */
/* @0x1e9f94 bne 0x1e9f5c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x34c> */

/* ── 变换通道 ④：线 AA 点 → g_SWFlineaavertbuff（叠在 ③ 上）────────────────────────
 *   闸：b4 != 0 且 +0x20 != 0 且 +0x50（线 AA 点数）非 0；源 +0x20。
 *   目标 *GOT 0x3f0de0 = g_SWFlineaavertbuff（0x5530c8），公式同 ②（f3 缩放 + 加 ③）。
 *   ⇒ 四个 .bss 缓冲两两成对：(填充, 填充AA) 与 (线, 线AA)，各 512 KB = 32768 点 × 16 B，
 *     四块基址正好相距 0x80000：0x5530c8 / 0x5d30c8 / 0x6530c8 / 0x6d30c8（.dynsym 具名）。
 */

/* @0x1e9f98 ldr r11, [sp, #0x60] */
/* @0x1e9f9c cmp r11, #0 */
/* @0x1e9fa0 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fa4 ldr r11, [sp, #0x38] */
/* @0x1e9fa8 ldr r3, [r11, #0x20] */
/* @0x1e9fac cmp r3, #0 */
/* @0x1e9fb0 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fb4 ldr r5, [r11, #0x50] */
/* @0x1e9fb8 cmp r5, #65536 */
/* @0x1e9fbc movhs r5, #65536 */
/* @0x1e9fc0 cmp r5, #0 */
/* @0x1e9fc4 beq 0x1ea038 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x428> */
/* @0x1e9fc8 ldr r6, [sp, #0x44] */
/* @0x1e9fcc mov r4, #0 */
/* @0x1e9fd0 ldr r0, [pc, #0x10c] */
/* @0x1e9fd4 ldr r2, [pc, #0x104] */
/* @0x1e9fd8 ldr r0, [r6, r0] */
/* @0x1e9fdc ldr r2, [r6, r2] */
/* @0x1e9fe0 add r0, r0, #8 */
/* @0x1e9fe4 add r2, r2, #8 */
/* @0x1e9fe8 vldr s15, [r3, #4] */
/* @0x1e9fec vmul.f32 s15, s15, s20 */
/* @0x1e9ff0 vldr s13, [r3] */
/* @0x1e9ff4 vldr s11, [r0, #-4] */
/* @0x1e9ff8 vldr s12, [r0, #-8] */
/* @0x1e9ffc add r4, r4, #1 */
/* @0x1ea000 cmp r5, r4 */
/* @0x1ea004 add r3, r3, #8 */
/* @0x1ea008 add r0, r0, #8 */
/* @0x1ea00c add r2, r2, #8 */
/* @0x1ea010 vmul.f32 s14, s15, s16 */
/* @0x1ea014 vmul.f32 s13, s13, s20 */
/* @0x1ea018 vmul.f32 s15, s15, s17 */
/* @0x1ea01c vmla.f32 s14, s13, s18 */
/* @0x1ea020 vmla.f32 s15, s13, s19 */
/* @0x1ea024 vadd.f32 s14, s14, s11 */
/* @0x1ea028 vadd.f32 s15, s15, s12 */
/* @0x1ea02c vstr s14, [r2, #-12] */
/* @0x1ea030 vstr s15, [r2, #-16] */
/* @0x1ea034 bne 0x1e9fe8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x3d8> */

/* ── 颜色流水 ①：调色板色 × p7，再过 p9/p11 ───────────────────────────────────────
 *   基色 = 元素->+0x08[ r12 ]（r12 = 上一变换循环的计数：b4==0 时是填充点数，否则是 AA 点数）
 *   ★ 用「点数」当颜色表下标是二进制事实；为何不是常量下标未钉（open）。
 *   cB = B×p7[0]>>8 · cG = G×p7[1]>>8 · cR = R×p7[2]>>8 · cA = A×p7[3]>>8 → sp+0x170..0x17c
 *   再逐通道 k：c = clamp8( p11[k] + (p9[k]·c >> 8) )（usat #8）
 *   ⇒ p7 = 填充色乘子（ARGB 四通道）；p9 = 通道缩放；p11 = 通道偏移（p10 在渐变路径当偏移）。
 */

/* @0x1ea038 ldr r7, [sp, #0x50] */
/* @0x1ea03c add r4, sp, #368 */
/* @0x1ea040 ldr r8, [sp, #0x6c] */
/* @0x1ea044 mov r3, #0 */
/* @0x1ea048 ldr r10, [sp, #0x68] */
/* @0x1ea04c ldr r2, [r7, #0x8] */
/* @0x1ea050 ldr r11, [sp, #0x70] */
/* @0x1ea054 ldr r0, [r2, r12, lsl #2] */
/* @0x1ea058 ubfx r5, r0, #0x8, #0x8 */
/* @0x1ea05c ubfx r12, r0, #0x10, #0x8 */
/* @0x1ea060 uxtb r6, r0 */
/* @0x1ea064 lsr r0, r0, #24 */
/* @0x1ea068 mul r9, r5, r8 */
/* @0x1ea06c mul r2, r6, r10 */
/* @0x1ea070 ldr r10, [sp, #0x74] */
/* @0x1ea074 mul r8, r12, r11 */
/* @0x1ea078 mul r7, r0, r10 */
/* @0x1ea07c lsr r9, r9, #8 */
/* @0x1ea080 str r9, [sp, #0x174] */
/* @0x1ea084 lsr r2, r2, #8 */
/* @0x1ea088 ldr r9, [sp, #0x2b4] */
/* @0x1ea08c lsr r8, r8, #8 */
/* @0x1ea090 str r8, [sp, #0x178] */
/* @0x1ea094 ldr r8, [sp, #0x2b0] */
/* @0x1ea098 lsr r7, r7, #8 */
/* @0x1ea09c str r2, [sp, #0x170] */
/* @0x1ea0a0 str r7, [sp, #0x17c] */
/* @0x1ea0a4 ldr r10, [r8, r3] */
/* @0x1ea0a8 ldr r7, [r9, r3] */
/* @0x1ea0ac mul r2, r10, r2 */
/* @0x1ea0b0 add r2, r7, r2, asr #8 */
/* @0x1ea0b4 usat r2, #0x8, r2 */
/* @0x1ea0b8 str r2, [r4, r3] */
/* @0x1ea0bc add r3, r3, #4 */
/* @0x1ea0c0 cmp r3, #16 */
/* @0x1ea0c4 beq 0x1ea440 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x830> */
/* @0x1ea0c8 ldr r2, [r4, r3] */
/* @0x1ea0cc b 0x1ea0a4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x494> */
/* @0x1ea0d0 andeq r0, r0, r0 */

/* ══ 段 B · 批量提交：四边形（16 B 顶点）+ 三角形（16 B 顶点）══════════════════════════════
 *   16 B 顶点：+0 x(float) +4 y(float) +8 z(float，*GOT 0x3ed928 的全局 z) +12 颜色(ARGB)
 *   语义分工：四边形批 = 主点↔AA 点之间的**抗锯齿边带**（每单元 2 个索引、6 个顶点）；
 *             三角形批 = 只用主点的**实心面**（每单元 3 个索引、3 个顶点）。
 *   提交方式：Graphics::AllocVerts(ePrimType=4, Pvi, stride, count) 拿一段可写顶点块直接填；
 *   本函数内 0 条 GR_Texture_Draw / DrawPrimitives —— 绘制由 AllocVerts 记账、帧末统一 flush。
 *   每批最多 maxVerts/6（四边形）或 maxVerts/3（三角形）个单元，循环到剩余为 0。
 *   ★ 本段锚点里 1ea0d4..1ea0f8 七个字是 literal pool（objdump 把 GOT 偏移解成 eoreq/andeq 之类），
 *     不是代码：0x00207f7c 是 GOT 基址偏移，其余是四个缓冲槽与 z/纹理表/RSM 的负偏移。
 */

/* @0x1ea0d4 eoreq r7, r0, r12, ror pc */
/* @0x1ea0d8 ldrsbeq r8, [r6], -r12 */
/* @0x1ea0dc ldrheq r8, [r6], -r4 */
/* @0x1ea0e0 .word 0xfffff188 */
/* @0x1ea0e4 .word 0xfffff18c */
/* @0x1ea0e8 .word 0xffffbac4 */
/* @0x1ea0ec .word 0xffffc0a8 */
/* @0x1ea0f0 .word 0xfffff190 */
/* @0x1ea0f4 .word 0xfffff194 */
/* @0x1ea0f8 .word 0xffffbcd0 */
/* @0x1ea0fc ldr r5, [sp, #0x60] */
/* @0x1ea100 cmp r5, #0 */
/* @0x1ea104 beq 0x1ea358 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x748> */
/* @0x1ea108 ldr r6, [sp, #0x38] */
/* @0x1ea10c ldr r3, [r6, #0x4c] */
/* @0x1ea110 cmp r3, #0 */
/* @0x1ea114 beq 0x1ea358 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x748> */
/* @0x1ea118 ldr r7, [r6, #0x1c] */
/* @0x1ea11c str r3, [sp, #0x40] */
/* @0x1ea120 str r7, [sp, #0x4c] */
/* @0x1ea124 ble 0x1ea34c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x73c> */
/* @0x1ea128 str r8, [sp, #0x18] */

/* ── 四边形批：闸 + 分配 ──────────────────────────────────────────────────────────
 *   闸：b4 != 0 且 记录->+0x4c != 0；单元数 = min(+0x4c, maxVerts/6)，顶点数 = 单元×6。
 *   AllocVerts(4, 0, 16, n*6) —— 第 2 实参 0 = 无纹理绑定。
 */

/* @0x1ea12c ldr r8, [sp, #0x40] */
/* @0x1ea130 mov r0, #4 */
/* @0x1ea134 ldr r9, [sp, #0x58] */
/* @0x1ea138 mov r1, #0 */
/* @0x1ea13c mov r2, #16 */
/* @0x1ea140 cmp r8, r9 */
/* @0x1ea144 movge r8, r9 */
/* @0x1ea148 str r8, [sp, #0x3c] */
/* @0x1ea14c add r3, r8, r8, lsl #1 */
/* @0x1ea150 lsl r3, r3, #1 */
/* @0x1ea154 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea158 cmp r8, #0 */
/* @0x1ea15c ble 0x1ea324 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x714> */
/* @0x1ea160 ldr r4, [sp, #0x44] */

/* ── 四边形批：指针装配 ──────────────────────────────────────────────────────────
 *   [sp+0x20] = *GOT 0x3f0de4 = g_SWFlinevertbuff（主点）
 *   [sp+0x1c] = *GOT 0x3f0de0 = g_SWFlineaavertbuff（AA 点）
 *   6 个顶点指针 = 块基址 +0/16/32/48/64/80；r3 = 基址+192，用 -192 回指第 0 个。
 *   索引表 = 记录->+0x1c（uint16 两两一组），游标 r4 每轮 +4。
 */

/* @0x1ea164 add r10, r0, #16 */
/* @0x1ea168 ldr r1, [pc, #-0x8c] */
/* @0x1ea16c add r11, r0, #32 */
/* @0x1ea170 str r10, [sp, #0x34] */
/* @0x1ea174 add r12, r0, #48 */
/* @0x1ea178 str r11, [sp, #0x30] */
/* @0x1ea17c add r5, r0, #64 */
/* @0x1ea180 str r12, [sp, #0x2c] */
/* @0x1ea184 add r6, r0, #80 */
/* @0x1ea188 ldr r1, [r4, r1] */
/* @0x1ea18c mov r8, r12 */
/* @0x1ea190 ldr r3, [pc, #-0xb8] */
/* @0x1ea194 mov r7, r11 */
/* @0x1ea198 str r5, [sp, #0x28] */
/* @0x1ea19c str r1, [sp, #0x20] */
/* @0x1ea1a0 ldr r3, [r4, r3] */
/* @0x1ea1a4 str r6, [sp, #0x24] */
/* @0x1ea1a8 mov r6, r5 */
/* @0x1ea1ac str r10, [sp, #0x10] */
/* @0x1ea1b0 ldr r2, [pc, #-0xc0] */
/* @0x1ea1b4 ldr r9, [sp, #0x3c] */
/* @0x1ea1b8 ldr r10, [sp, #0x44] */
/* @0x1ea1bc ldr r5, [sp, #0x24] */
/* @0x1ea1c0 ldr r4, [sp, #0x4c] */
/* @0x1ea1c4 str r3, [sp, #0x1c] */
/* @0x1ea1c8 add r3, r0, #96 */
/* @0x1ea1cc str r9, [sp, #0xc] */
/* @0x1ea1d0 ldr r2, [r10, r2] */
/* @0x1ea1d4 vldr s15, [r2] */
/* @0x1ea1d8 ldrh r9, [r4, #2] */

/* ── 四边形批：每单元 6 顶点（A0, A1, B0, B0, A1, B1）──────────────────────────────
 *   A = g_SWFlinevertbuff[i]（主点），B = g_SWFlineaavertbuff[i]（AA 点）
 *   写入次序：v0=A[i0] · v1=A[i1] · v2=B[i0] · v3=B[i0] · v4=A[i1] · v5=B[i1]
 *   ⇒ 两个三角形 (A0,A1,B0)+(B0,A1,B1) 拼成 A 线到 B 线之间的四边形；同索引 B 点重复写
 *     两次（1ea2c8 与 1ea2e0 都用 s12/s13），这是三角形列表的共享边。
 *   颜色：A 组用 C（[sp+0x18]），B 组用 C2（[sp+0x14]）。
 */

/* @0x1ea1dc add r3, r3, #96 */
/* @0x1ea1e0 ldr r1, [sp, #0x10] */
/* @0x1ea1e4 add r4, r4, #4 */
/* @0x1ea1e8 ldr r2, [sp, #0x34] */
/* @0x1ea1ec ldrh r10, [r4, #-4] */
/* @0x1ea1f0 rsb r12, r0, r1 */
/* @0x1ea1f4 ldr r11, [sp, #0xc] */
/* @0x1ea1f8 lsl r9, r9, #3 */
/* @0x1ea1fc str r9, [sp, #0x5c] */
/* @0x1ea200 add r12, r12, r2 */
/* @0x1ea204 ldr r9, [sp, #0x2c] */
/* @0x1ea208 rsb r2, r0, r8 */
/* @0x1ea20c subs r11, r11, #1 */
/* @0x1ea210 str r11, [sp, #0xc] */
/* @0x1ea214 add r2, r2, r9 */
/* @0x1ea218 ldr r11, [sp, #0x30] */
/* @0x1ea21c ldr r9, [sp, #0x20] */
/* @0x1ea220 rsb r1, r0, r7 */
/* @0x1ea224 lsl r10, r10, #3 */
/* @0x1ea228 add r1, r1, r11 */
/* @0x1ea22c add r11, r9, r10 */
/* @0x1ea230 ldr r9, [sp, #0x1c] */
/* @0x1ea234 vldr s8, [r11] */
/* @0x1ea238 vldr s9, [r11, #4] */
/* @0x1ea23c add r10, r9, r10 */
/* @0x1ea240 ldr r11, [sp, #0x20] */
/* @0x1ea244 ldr r9, [sp, #0x5c] */
/* @0x1ea248 vldr s12, [r10] */
/* @0x1ea24c vldr s13, [r10, #4] */
/* @0x1ea250 add r7, r7, #96 */
/* @0x1ea254 add r10, r11, r9 */
/* @0x1ea258 ldr r11, [sp, #0x1c] */
/* @0x1ea25c vldr s14, [r10] */
/* @0x1ea260 vldr s2, [r10, #4] */
/* @0x1ea264 add r11, r11, r9 */
/* @0x1ea268 vldr s10, [r11] */
/* @0x1ea26c vldr s11, [r11, #4] */
/* @0x1ea270 ldr r11, [sp, #0x28] */
/* @0x1ea274 ldr r9, [sp, #0x10] */
/* @0x1ea278 rsb r10, r0, r6 */
/* @0x1ea27c add r10, r10, r11 */
/* @0x1ea280 ldr r11, [sp, #0x24] */
/* @0x1ea284 add r9, r9, #96 */
/* @0x1ea288 str r9, [sp, #0x10] */
/* @0x1ea28c rsb r9, r0, r5 */
/* @0x1ea290 vstr s8, [r3, #-192] */
/* @0x1ea294 add r11, r9, r11 */
/* @0x1ea298 ldr r9, [sp, #0x18] */
/* @0x1ea29c vstr s9, [r3, #-188] */
/* @0x1ea2a0 vstr s15, [r3, #-184] */
/* @0x1ea2a4 str r11, [sp, #0x5c] */
/* @0x1ea2a8 add r8, r8, #96 */
/* @0x1ea2ac str r9, [r3, #-0xb4] */
/* @0x1ea2b0 vstr s14, [r12, #-16] */
/* @0x1ea2b4 vstr s2, [r12, #-12] */
/* @0x1ea2b8 vstr s15, [r12, #-8] */
/* @0x1ea2bc str r9, [r12, #-0x4] */
/* @0x1ea2c0 add r6, r6, #96 */
/* @0x1ea2c4 ldr r12, [sp, #0x5c] */
/* @0x1ea2c8 vstr s12, [r1, #-32] */
/* @0x1ea2cc ldr r11, [sp, #0x14] */
/* @0x1ea2d0 vstr s13, [r1, #-28] */
/* @0x1ea2d4 vstr s15, [r1, #-24] */
/* @0x1ea2d8 add r5, r5, #96 */
/* @0x1ea2dc str r11, [r1, #-0x14] */
/* @0x1ea2e0 vstr s12, [r2, #-48] */
/* @0x1ea2e4 vstr s13, [r2, #-44] */
/* @0x1ea2e8 vstr s15, [r2, #-40] */
/* @0x1ea2ec str r11, [r2, #-0x24] */
/* @0x1ea2f0 vstr s14, [r10, #-64] */
/* @0x1ea2f4 vstr s2, [r10, #-60] */
/* @0x1ea2f8 vstr s15, [r10, #-56] */
/* @0x1ea2fc str r9, [r10, #-0x34] */
/* @0x1ea300 vstr s10, [r12, #-80] */
/* @0x1ea304 vstr s11, [r12, #-76] */
/* @0x1ea308 vstr s15, [r12, #-72] */
/* @0x1ea30c str r11, [r12, #-0x44] */
/* @0x1ea310 bne 0x1ea1d8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x5c8> */
/* @0x1ea314 ldr r5, [sp, #0x3c] */

/* ── 四边形批：批次推进 ──────────────────────────────────────────────────────────
 *   索引游标 += n；剩余 -= n；还有剩余就回 1ea12c 再切一批。
 *   批结束后 [sp+0x54] += 2×总四边形数（一个四边形算 2 个三角形）。
 */

/* @0x1ea318 ldr r4, [sp, #0x4c] */
/* @0x1ea31c add r4, r4, r5, lsl #2 */
/* @0x1ea320 str r4, [sp, #0x4c] */
/* @0x1ea324 ldr r6, [sp, #0x40] */
/* @0x1ea328 ldr r7, [sp, #0x3c] */
/* @0x1ea32c rsb r6, r7, r6 */
/* @0x1ea330 str r6, [sp, #0x40] */
/* @0x1ea334 cmp r6, #0 */
/* @0x1ea338 bgt 0x1ea12c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x51c> */
/* @0x1ea33c ldr r9, [sp, #0x38] */
/* @0x1ea340 ldr r8, [sp, #0x18] */
/* @0x1ea344 ldr r3, [r9, #0x4c] */
/* @0x1ea348 ldr r1, [r9, #0x40] */
/* @0x1ea34c ldr r10, [sp, #0x54] */
/* @0x1ea350 add r10, r10, r3, lsl #1 */
/* @0x1ea354 str r10, [sp, #0x54] */
/* @0x1ea358 ldr r11, [sp, #0x38] */

/* ── 三角形批：闸 + 分配 ─────────────────────────────────────────────────────────
 *   闸：+0x40（三角形数）> 0；单元数 = min(+0x40, maxVerts/3)，顶点数 = 单元×3。
 *   源 = 记录->+0x10 的 uint16 索引，索引字节数 = 6×三角形数（步进 2 B）。
 *   AllocVerts(4, 0, 16, n*3)；每轮写 1 个 16 B 顶点（预增 +16 一次、循环内再 +16），共 3n 轮。
 */

/* @0x1ea35c subs r4, r1, #0 */
/* @0x1ea360 ldr r5, [r11, #0x10] */
/* @0x1ea364 ble 0x1ea3f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e8> */
/* @0x1ea368 ldr r7, [sp, #0x8c] */
/* @0x1ea36c ldr r9, [sp, #0x44] */
/* @0x1ea370 cmp r4, r7 */
/* @0x1ea374 movlt r6, r4 */
/* @0x1ea378 movge r6, r7 */
/* @0x1ea37c mov r0, #4 */
/* @0x1ea380 mov r1, #0 */
/* @0x1ea384 mov r2, #16 */
/* @0x1ea388 add r10, r6, r6, lsl #1 */
/* @0x1ea38c mov r3, r10 */
/* @0x1ea390 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea394 cmp r10, #0 */
/* @0x1ea398 ble 0x1ea3e4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7d4> */
/* @0x1ea39c ldr r2, [pc, #-0x2ac] */
/* @0x1ea3a0 add r3, r5, r10, lsl #1 */
/* @0x1ea3a4 ldr r1, [pc, #-0x2c8] */
/* @0x1ea3a8 add r0, r0, #16 */
/* @0x1ea3ac ldr r2, [r9, r2] */
/* @0x1ea3b0 ldr r12, [r9, r1] */
/* @0x1ea3b4 ldr r10, [r2] */
/* @0x1ea3b8 ldrh r2, [r5], #2 */

/* ── 三角形批：逐索引写顶点（坐标 g_SWFlinevertbuff，颜色 C）────────────────────────
 *   z = *GOT 0x3ed928 的全局 float；颜色 r8 = C（[sp+0x18]）。
 */

/* @0x1ea3bc add r0, r0, #16 */
/* @0x1ea3c0 cmp r5, r3 */
/* @0x1ea3c4 add r2, r12, r2, lsl #3 */
/* @0x1ea3c8 ldr r1, [r2] */
/* @0x1ea3cc ldr r2, [r2, #0x4] */
/* @0x1ea3d0 str r10, [r0, #-0x18] */
/* @0x1ea3d4 str r1, [r0, #-0x20] */
/* @0x1ea3d8 str r2, [r0, #-0x1c] */
/* @0x1ea3dc str r8, [r0, #-0x14] */
/* @0x1ea3e0 bne 0x1ea3b8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7a8> */
/* @0x1ea3e4 rsb r4, r6, r4 */
/* @0x1ea3e8 cmp r4, #0 */
/* @0x1ea3ec bgt 0x1ea370 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x760> */
/* @0x1ea3f0 ldr r12, [sp, #0x38] */
/* @0x1ea3f4 ldr r1, [r12, #0x40] */
/* @0x1ea3f8 ldr r4, [sp, #0x54] */

/* ── 三角形批收尾 + 两个循环回边 ─────────────────────────────────────────────────
 *   [sp+0x54] += 三角形数；子记录 k++ 与 +0x0c 比较（bhi 回 1e9d90）；
 *   元素 i++ 与 item->+0x1c 比较（bhi 回 1e9d64）；全做完 → 1e9cec 返回累计三角形数。
 */

/* @0x1ea3fc add r4, r1, r4 */
/* @0x1ea400 str r4, [sp, #0x54] */
/* @0x1ea404 ldr r5, [sp, #0x50] */
/* @0x1ea408 ldr r6, [sp, #0x48] */
/* @0x1ea40c ldr r3, [r5, #0xc] */
/* @0x1ea410 add r6, r6, #1 */
/* @0x1ea414 str r6, [sp, #0x48] */
/* @0x1ea418 cmp r3, r6 */
/* @0x1ea41c bhi 0x1e9d90 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x180> */
/* @0x1ea420 ldr r7, [sp, #0xa0] */
/* @0x1ea424 ldr r3, [r7, #0x1c] */
/* @0x1ea428 ldr r8, [sp, #0x9c] */
/* @0x1ea42c add r8, r8, #1 */
/* @0x1ea430 str r8, [sp, #0x9c] */
/* @0x1ea434 cmp r3, r8 */
/* @0x1ea438 bhi 0x1e9d64 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x154> */
/* @0x1ea43c b 0x1e9cec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdc> */

/* ── 颜色打包：C 留 [sp+0x18]，C2（×p8 再过 p9/p11）留 [sp+0x14] ──────────────────
 *   1ea440 的 r9/r8/r7/r10 = p8[2]/p8[1]/p8[0]/p8[3]；r12/r5/r6/r0 仍是调色板 B,G,R,A，
 *   各乘 p8 一遍（>>8）→ [sp+0x1b0..0x1bc]；1ea4b0..1ea4c4 再对这四个通道跑一遍
 *   c = clamp8(p11[k] + (p9[k]·c >> 8))（与 1ea0a4 那段同一套，作用在 p8 色上）。
 *   1ea490 把 sp+0x170/174/178/17c（p7 → p9/p11）拼成 r8 = C → [sp+0x18]；
 *   1ea4d8 起把 p8 → p9/p11 的结果拼成 r12 = C2 → [sp+0x14]。
 *   ⇒ 两个颜色走同一条缩放/偏移流水，只差乘子数组：C 用 p7、C2 用 p8。
 */

/* @0x1ea440 ldr r9, [sp, #0x80] */
/* @0x1ea444 ldr r8, [sp, #0x7c] */
/* @0x1ea448 ldr r3, [sp, #0x178] */
/* @0x1ea44c ldr r2, [sp, #0x174] */
/* @0x1ea450 ldr r7, [sp, #0x78] */
/* @0x1ea454 mul r12, r12, r9 */
/* @0x1ea458 ldr r10, [sp, #0x84] */
/* @0x1ea45c mul r5, r5, r8 */
/* @0x1ea460 lsl r3, r3, #16 */
/* @0x1ea464 orr r3, r3, r2, lsl #8 */
/* @0x1ea468 ldr r2, [sp, #0x170] */
/* @0x1ea46c mul r6, r6, r7 */
/* @0x1ea470 orr r3, r3, r2 */
/* @0x1ea474 mul r0, r0, r10 */
/* @0x1ea478 ldr r2, [sp, #0x17c] */
/* @0x1ea47c lsr r12, r12, #8 */
/* @0x1ea480 ldr r4, [sp, #0x2b8] */
/* @0x1ea484 str r12, [sp, #0x1b8] */
/* @0x1ea488 lsr r5, r5, #8 */
/* @0x1ea48c ldr r12, [sp, #0x2b0] */
/* @0x1ea490 orr r8, r3, r2, lsl #24 */
/* @0x1ea494 str r5, [sp, #0x1b4] */
/* @0x1ea498 add r5, sp, #432 */
/* @0x1ea49c mov r3, #0 */
/* @0x1ea4a0 lsr r6, r6, #8 */
/* @0x1ea4a4 lsr r0, r0, #8 */
/* @0x1ea4a8 str r6, [sp, #0x1b0] */
/* @0x1ea4ac str r0, [sp, #0x1bc] */
/* @0x1ea4b0 ldr r2, [r12, r3] */
/* @0x1ea4b4 ldr r0, [r4, r3] */
/* @0x1ea4b8 mul r2, r2, r6 */
/* @0x1ea4bc add r2, r0, r2, asr #8 */
/* @0x1ea4c0 usat r2, #0x8, r2 */
/* @0x1ea4c4 str r2, [r5, r3] */
/* @0x1ea4c8 add r3, r3, #4 */
/* @0x1ea4cc cmp r3, #16 */
/* @0x1ea4d0 ldrne r6, [r5, r3] */
/* @0x1ea4d4 bne 0x1ea4b0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x8a0> */
/* @0x1ea4d8 ldr r3, [sp, #0x1b8] */

/* ── b5 闸 ──────────────────────────────────────────────────────────────────────
 *   b5 == 0 → 回 1ea0fc（只交 16 B 实心/AA 两批）；b5 != 0 → 进 24 B 纹理通道。
 */

/* @0x1ea4dc ldr r2, [sp, #0x1b4] */
/* @0x1ea4e0 ldr r11, [sp, #0x88] */
/* @0x1ea4e4 ldr r0, [sp, #0x1b0] */
/* @0x1ea4e8 lsl r3, r3, #16 */
/* @0x1ea4ec ldr r12, [sp, #0x1bc] */
/* @0x1ea4f0 orr r3, r3, r2, lsl #8 */
/* @0x1ea4f4 cmp r11, #0 */
/* @0x1ea4f8 orr r3, r3, r0 */
/* @0x1ea4fc orr r12, r3, r12, lsl #24 */
/* @0x1ea500 str r12, [sp, #0x14] */
/* @0x1ea504 beq 0x1ea0fc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x4ec> */
/* @0x1ea508 ldr r12, [sp, #0x60] */

/* ══ 段 C · 24 B 纹理顶点通道（线 AA 边）══════════════════════════════════════════════════
 *   24 B 顶点：+0 x  +4 y  +8 z  +12 颜色  +16 u  +20 v
 *   AllocVerts(4, p12, 24, n*6) ⇒「纹理绑定」不在 GR 调用里，而是把 Texture* 交给分配器；
 *   第 2 实参 p12 就是 DrawShape 传进来的那个 Texture*（实色/无纹理时为 0）。
 */

/* @0x1ea50c cmp r12, #0 */
/* @0x1ea510 beq 0x1ea790 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb80> */
/* @0x1ea514 ldr r4, [sp, #0x38] */
/* @0x1ea518 ldr r3, [r4, #0x4c] */
/* @0x1ea51c cmp r3, #0 */
/* @0x1ea520 beq 0x1ea790 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb80> */
/* @0x1ea524 ldr r5, [r4, #0x1c] */
/* @0x1ea528 str r3, [sp, #0x40] */
/* @0x1ea52c str r5, [sp, #0x4c] */
/* @0x1ea530 ble 0x1ea784 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb74> */
/* @0x1ea534 str r8, [sp, #0x18] */
/* @0x1ea538 ldr r6, [sp, #0x40] */
/* @0x1ea53c mov r0, #4 */
/* @0x1ea540 ldr r7, [sp, #0x58] */
/* @0x1ea544 mov r2, #24 */
/* @0x1ea548 ldr r1, [sp, #0x2bc] */
/* @0x1ea54c cmp r6, r7 */
/* @0x1ea550 movge r6, r7 */
/* @0x1ea554 str r6, [sp, #0x3c] */
/* @0x1ea558 add r3, r6, r6, lsl #1 */
/* @0x1ea55c lsl r3, r3, #1 */
/* @0x1ea560 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea564 cmp r6, #0 */

/* ── 24 B 批：指针/常量装配（与 16 B 批同源）──────────────────────────────────────
 *   [sp+0x20] = g_SWFlinevertbuff、[sp+0x1c] = g_SWFlineaavertbuff，
 *   6 个顶点指针步进 24 B；r3 = 基址+288，用 -288 回指第 0 个；z 仍取 *GOT 0x3ed928。
 */

/* @0x1ea568 ble 0x1ea75c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb4c> */
/* @0x1ea56c ldr r12, [sp, #0x44] */
/* @0x1ea570 add r8, r0, #24 */
/* @0x1ea574 ldr r1, [pc, #-0x498] */
/* @0x1ea578 add r9, r0, #48 */
/* @0x1ea57c str r8, [sp, #0x28] */
/* @0x1ea580 add r10, r0, #72 */
/* @0x1ea584 str r9, [sp, #0x24] */
/* @0x1ea588 mov r7, r9 */
/* @0x1ea58c str r10, [sp, #0x34] */
/* @0x1ea590 ldr r3, [pc, #-0x4b8] */
/* @0x1ea594 ldr r1, [r12, r1] */
/* @0x1ea598 ldr r4, [sp, #0x3c] */
/* @0x1ea59c ldr r2, [pc, #-0x4ac] */
/* @0x1ea5a0 str r1, [sp, #0x20] */
/* @0x1ea5a4 add r1, r0, #96 */
/* @0x1ea5a8 str r1, [sp, #0x30] */
/* @0x1ea5ac ldr r3, [r12, r3] */
/* @0x1ea5b0 mov r6, r1 */
/* @0x1ea5b4 str r4, [sp, #0xc] */
/* @0x1ea5b8 ldr r4, [sp, #0x4c] */
/* @0x1ea5bc str r3, [sp, #0x1c] */
/* @0x1ea5c0 add r3, r0, #120 */
/* @0x1ea5c4 str r3, [sp, #0x2c] */
/* @0x1ea5c8 add r3, r0, #144 */
/* @0x1ea5cc ldr r5, [sp, #0x2c] */
/* @0x1ea5d0 str r8, [sp, #0x10] */
/* @0x1ea5d4 mov r8, r10 */
/* @0x1ea5d8 ldr r2, [r12, r2] */
/* @0x1ea5dc vldr s15, [r2] */
/* @0x1ea5e0 ldr r9, [sp, #0xc] */

/* ── 24 B 批：每单元 6 顶点，uv 是常量 (f13,f14) ──────────────────────────────────
 *   位置/颜色取法与 16 B 批完全相同，只多写两个 float：s29 → +16、s28 → +20。
 *   ⇒ 整批采样同一个 texel：这是「用纹理取一个颜色」的画法，与 DrawSWF 把 UV 压到
 *     (0.5,0.5) 的固定矩阵同一思路。颜色：A 组 C（[sp+0x18]），B 组 C2（[sp+0x14]）。
 */

/* @0x1ea5e4 add r4, r4, #4 */
/* @0x1ea5e8 ldr r11, [sp, #0x10] */
/* @0x1ea5ec add r3, r3, #144 */
/* @0x1ea5f0 subs r9, r9, #1 */
/* @0x1ea5f4 str r9, [sp, #0xc] */
/* @0x1ea5f8 ldrh r9, [r4, #-2] */
/* @0x1ea5fc rsb r12, r0, r11 */
/* @0x1ea600 ldr r1, [sp, #0x28] */
/* @0x1ea604 ldr r2, [sp, #0x24] */
/* @0x1ea608 ldrh r10, [r4, #-4] */
/* @0x1ea60c add r12, r12, r1 */
/* @0x1ea610 lsl r9, r9, #3 */
/* @0x1ea614 rsb r1, r0, r7 */
/* @0x1ea618 str r9, [sp, #0x5c] */
/* @0x1ea61c add r1, r1, r2 */
/* @0x1ea620 ldr r9, [sp, #0x34] */
/* @0x1ea624 rsb r2, r0, r8 */
/* @0x1ea628 lsl r10, r10, #3 */
/* @0x1ea62c add r7, r7, #144 */
/* @0x1ea630 add r2, r2, r9 */
/* @0x1ea634 ldr r9, [sp, #0x20] */
/* @0x1ea638 add r8, r8, #144 */
/* @0x1ea63c add r11, r9, r10 */
/* @0x1ea640 ldr r9, [sp, #0x1c] */
/* @0x1ea644 vldr s8, [r11] */
/* @0x1ea648 vldr s9, [r11, #4] */
/* @0x1ea64c add r10, r9, r10 */
/* @0x1ea650 ldr r11, [sp, #0x20] */
/* @0x1ea654 ldr r9, [sp, #0x5c] */
/* @0x1ea658 vldr s12, [r10] */
/* @0x1ea65c vldr s13, [r10, #4] */
/* @0x1ea660 add r10, r11, r9 */
/* @0x1ea664 ldr r11, [sp, #0x1c] */
/* @0x1ea668 vldr s14, [r10] */
/* @0x1ea66c vldr s2, [r10, #4] */
/* @0x1ea670 add r11, r11, r9 */
/* @0x1ea674 vldr s10, [r11] */
/* @0x1ea678 vldr s11, [r11, #4] */
/* @0x1ea67c ldr r11, [sp, #0x30] */
/* @0x1ea680 ldr r9, [sp, #0x10] */
/* @0x1ea684 rsb r10, r0, r6 */
/* @0x1ea688 add r10, r10, r11 */
/* @0x1ea68c ldr r11, [sp, #0x2c] */
/* @0x1ea690 add r9, r9, #144 */
/* @0x1ea694 str r9, [sp, #0x10] */
/* @0x1ea698 rsb r9, r0, r5 */
/* @0x1ea69c vstr s8, [r3, #-288] */
/* @0x1ea6a0 add r11, r9, r11 */
/* @0x1ea6a4 ldr r9, [sp, #0x18] */
/* @0x1ea6a8 vstr s9, [r3, #-284] */
/* @0x1ea6ac str r11, [sp, #0x5c] */
/* @0x1ea6b0 vstr s15, [r3, #-280] */
/* @0x1ea6b4 vstr s29, [r3, #-272] */
/* @0x1ea6b8 str r9, [r3, #-0x114] */
/* @0x1ea6bc vstr s28, [r3, #-268] */
/* @0x1ea6c0 vstr s14, [r12, #-24] */
/* @0x1ea6c4 vstr s2, [r12, #-20] */
/* @0x1ea6c8 vstr s15, [r12, #-16] */
/* @0x1ea6cc str r9, [r12, #-0xc] */
/* @0x1ea6d0 vstr s29, [r12, #-8] */
/* @0x1ea6d4 vstr s28, [r12, #-4] */
/* @0x1ea6d8 ldr r11, [sp, #0x14] */
/* @0x1ea6dc vstr s12, [r1, #-48] */
/* @0x1ea6e0 ldr r12, [sp, #0x5c] */
/* @0x1ea6e4 vstr s13, [r1, #-44] */
/* @0x1ea6e8 vstr s15, [r1, #-40] */
/* @0x1ea6ec vstr s29, [r1, #-32] */
/* @0x1ea6f0 str r11, [r1, #-0x24] */
/* @0x1ea6f4 vstr s28, [r1, #-28] */
/* @0x1ea6f8 add r6, r6, #144 */
/* @0x1ea6fc vstr s12, [r2, #-72] */
/* @0x1ea700 vstr s13, [r2, #-68] */
/* @0x1ea704 vstr s15, [r2, #-64] */
/* @0x1ea708 str r11, [r2, #-0x3c] */
/* @0x1ea70c vstr s29, [r2, #-56] */
/* @0x1ea710 vstr s28, [r2, #-52] */
/* @0x1ea714 add r5, r5, #144 */
/* @0x1ea718 vstr s14, [r10, #-96] */
/* @0x1ea71c vstr s2, [r10, #-92] */
/* @0x1ea720 vstr s15, [r10, #-88] */
/* @0x1ea724 str r9, [r10, #-0x54] */
/* @0x1ea728 vstr s29, [r10, #-80] */
/* @0x1ea72c vstr s28, [r10, #-76] */
/* @0x1ea730 vstr s10, [r12, #-120] */
/* @0x1ea734 vstr s11, [r12, #-116] */
/* @0x1ea738 vstr s15, [r12, #-112] */
/* @0x1ea73c str r11, [r12, #-0x6c] */
/* @0x1ea740 vstr s29, [r12, #-104] */
/* @0x1ea744 vstr s28, [r12, #-100] */
/* @0x1ea748 bne 0x1ea5e0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x9d0> */
/* @0x1ea74c ldr r5, [sp, #0x3c] */

/* ── 24 B 批：分块推进 ───────────────────────────────────────────────────────────
 *   游标 4 B/单元、剩余递减、回 1ea538 再切一批（与 16 B 批同一套账）。
 */

/* @0x1ea750 ldr r4, [sp, #0x4c] */
/* @0x1ea754 add r4, r4, r5, lsl #2 */
/* @0x1ea758 str r4, [sp, #0x4c] */
/* @0x1ea75c ldr r6, [sp, #0x40] */
/* @0x1ea760 ldr r7, [sp, #0x3c] */
/* @0x1ea764 rsb r6, r7, r6 */
/* @0x1ea768 str r6, [sp, #0x40] */
/* @0x1ea76c cmp r6, #0 */
/* @0x1ea770 bgt 0x1ea538 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x928> */
/* @0x1ea774 ldr r9, [sp, #0x38] */
/* @0x1ea778 ldr r8, [sp, #0x18] */
/* @0x1ea77c ldr r3, [r9, #0x4c] */
/* @0x1ea780 ldr r1, [r9, #0x40] */
/* @0x1ea784 ldr r10, [sp, #0x54] */
/* @0x1ea788 add r10, r10, r3, lsl #1 */
/* @0x1ea78c str r10, [sp, #0x54] */
/* @0x1ea790 ldr r11, [sp, #0x38] */
/* @0x1ea794 subs r4, r1, #0 */
/* @0x1ea798 ldr r5, [r11, #0x10] */
/* @0x1ea79c ble 0x1ea3f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e8> */
/* @0x1ea7a0 ldr r7, [sp, #0x8c] */

/* ── 24 B 三角形批（线实心）───────────────────────────────────────────────────────
 *   索引 = 记录->+0x10、个数 = +0x40；AllocVerts(4, p12, 24, n*3)；
 *   逐索引一个顶点，坐标 g_SWFlinevertbuff[idx]，uv 仍是常量 (f13,f14)，颜色 C。
 */

/* @0x1ea7a4 ldr r9, [sp, #0x2bc] */
/* @0x1ea7a8 ldr r10, [sp, #0x44] */
/* @0x1ea7ac cmp r4, r7 */
/* @0x1ea7b0 movlt r6, r4 */
/* @0x1ea7b4 movge r6, r7 */
/* @0x1ea7b8 mov r0, #4 */
/* @0x1ea7bc mov r1, r9 */
/* @0x1ea7c0 mov r2, #24 */
/* @0x1ea7c4 add r11, r6, r6, lsl #1 */
/* @0x1ea7c8 mov r3, r11 */
/* @0x1ea7cc bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1ea7d0 cmp r11, #0 */
/* @0x1ea7d4 ble 0x1ea828 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xc18> */
/* @0x1ea7d8 ldr r2, [pc, #-0x6e8] */
/* @0x1ea7dc add r3, r5, r11, lsl #1 */
/* @0x1ea7e0 ldr r1, [pc, #-0x704] */
/* @0x1ea7e4 add r0, r0, #24 */
/* @0x1ea7e8 ldr r2, [r10, r2] */
/* @0x1ea7ec ldr r1, [r10, r1] */
/* @0x1ea7f0 ldr r11, [r2] */
/* @0x1ea7f4 ldrh r2, [r5], #2 */
/* @0x1ea7f8 add r0, r0, #24 */
/* @0x1ea7fc cmp r5, r3 */
/* @0x1ea800 add r2, r1, r2, lsl #3 */
/* @0x1ea804 ldr r12, [r2] */
/* @0x1ea808 ldr r2, [r2, #0x4] */
/* @0x1ea80c vstr s29, [r0, #-32] */
/* @0x1ea810 str r11, [r0, #-0x28] */
/* @0x1ea814 vstr s28, [r0, #-28] */
/* @0x1ea818 str r12, [r0, #-0x30] */
/* @0x1ea81c str r2, [r0, #-0x2c] */
/* @0x1ea820 str r8, [r0, #-0x24] */
/* @0x1ea824 bne 0x1ea7f4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xbe4> */
/* @0x1ea828 rsb r4, r6, r4 */
/* @0x1ea82c cmp r4, #0 */
/* @0x1ea830 bgt 0x1ea7ac <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xb9c> */
/* @0x1ea834 b 0x1ea3f0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7e0> */
/* @0x1ea838 ldr r10, [sp, #0x44] */

/* ── 溢出告警：点数 > 65536 → 虚调用（.rodata 0x3525fc / 0x352620）────────────────
 *   this = *GOT 0x3ed71c（.data.rel.ro 0x3eb70c 的单例对象，vptr 运行时填）
 *   调用 = vtable[3]( 字符串 )：填充侧 "SWF subshape has too many verts!!"、
 *   线 AA 侧 "SWF subshape has too many aa verts!!"（1eb378 用 [sp+0xac]）。
 *   ★ 类名未钉（open）：只能证到「单例 + 第 4 个虚函数 + 一个 char* 实参」。
 */

/* @0x1ea83c ldr r3, [pc, #-0x75c] */
/* @0x1ea840 ldr r1, [sp, #0xa4] */
/* @0x1ea844 ldr r3, [r10, r3] */
/* @0x1ea848 ldr r0, [r3] */
/* @0x1ea84c ldr r3, [r0] */
/* @0x1ea850 ldr r3, [r3, #0xc] */
/* @0x1ea854 blx r3 */
/* @0x1ea858 b 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */

/* ══ 段 D · type 1（实色填充）：基色 = 子对象->+0x04 ═══════════════════════════════════════
 *   子对象 = 元素->+0x04[记录->+0x28]，+0x04 是打包 ARGB（B,G,R,A 逐字节拆）。
 *   流水与公共色同构：×p7（1ea87c..1ea8b8）→ p9/p11（1ea8c0..1ea8e4）→ 打包 C；
 *   并行的 ×p8（1ea8fc..1ea954）→ p9/p11（1ea958..1ea97c）→ 打包 C2。
 */

/* @0x1ea85c ldr r9, [r6, #0x4] */
/* @0x1ea860 add r4, sp, #368 */
/* @0x1ea864 ldr r10, [sp, #0x6c] */
/* @0x1ea868 mov r2, #0 */
/* @0x1ea86c ldr r12, [sp, #0x70] */
/* @0x1ea870 ubfx r7, r9, #0x8, #0x8 */
/* @0x1ea874 ubfx r8, r9, #0x10, #0x8 */
/* @0x1ea878 ldr r11, [sp, #0x68] */
/* @0x1ea87c mul r6, r7, r10 */
/* @0x1ea880 ldr r10, [sp, #0x74] */
/* @0x1ea884 mul r5, r8, r12 */
/* @0x1ea888 uxtb r0, r9 */
/* @0x1ea88c lsr r9, r9, #24 */
/* @0x1ea890 mul r1, r0, r11 */
/* @0x1ea894 lsr r6, r6, #8 */
/* @0x1ea898 mul r12, r9, r10 */
/* @0x1ea89c lsr r5, r5, #8 */
/* @0x1ea8a0 str r6, [sp, #0x174] */
/* @0x1ea8a4 str r5, [sp, #0x178] */
/* @0x1ea8a8 ldr r6, [sp, #0x2b4] */
/* @0x1ea8ac lsr r1, r1, #8 */
/* @0x1ea8b0 ldr r5, [sp, #0x2b0] */
/* @0x1ea8b4 lsr r12, r12, #8 */
/* @0x1ea8b8 str r1, [sp, #0x170] */
/* @0x1ea8bc str r12, [sp, #0x17c] */
/* @0x1ea8c0 ldr r10, [r5, r2] */
/* @0x1ea8c4 ldr r12, [r6, r2] */
/* @0x1ea8c8 mul r1, r10, r1 */
/* @0x1ea8cc add r1, r12, r1, asr #8 */
/* @0x1ea8d0 usat r1, #0x8, r1 */
/* @0x1ea8d4 str r1, [r4, r2] */
/* @0x1ea8d8 add r2, r2, #4 */
/* @0x1ea8dc cmp r2, #16 */
/* @0x1ea8e0 ldrne r1, [r4, r2] */
/* @0x1ea8e4 bne 0x1ea8c0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xcb0> */
/* @0x1ea8e8 ldr r4, [sp, #0x80] */
/* @0x1ea8ec ldr r11, [sp, #0x78] */
/* @0x1ea8f0 ldr r12, [sp, #0x7c] */

/* ── type 1：两个颜色打包 + 闸 ────────────────────────────────────────────────────
 *   C（r8）留在寄存器里给顶点用；C2 → [sp+0x14]。
 *   b5 == 0 → 1eb39c（16 B 无纹理填充批）；b5 != 0 → 24 B 纹理批。
 */

/* @0x1ea8f4 ldr r5, [sp, #0x84] */
/* @0x1ea8f8 ldr r1, [sp, #0x178] */
/* @0x1ea8fc mul r8, r8, r4 */
/* @0x1ea900 ldr r6, [sp, #0x2b8] */
/* @0x1ea904 mul r2, r0, r11 */
/* @0x1ea908 ldr r0, [sp, #0x174] */
/* @0x1ea90c mul r7, r7, r12 */
/* @0x1ea910 lsl r1, r1, #16 */
/* @0x1ea914 mul r9, r9, r5 */
/* @0x1ea918 orr r1, r1, r0, lsl #8 */
/* @0x1ea91c ldr r12, [sp, #0x17c] */
/* @0x1ea920 add r5, sp, #432 */
/* @0x1ea924 ldr r0, [sp, #0x170] */
/* @0x1ea928 lsr r2, r2, #8 */
/* @0x1ea92c ldr r4, [sp, #0x2b0] */
/* @0x1ea930 lsr r7, r7, #8 */
/* @0x1ea934 orr r1, r1, r0 */
/* @0x1ea938 lsr r0, r8, #8 */
/* @0x1ea93c orr r8, r1, r12, lsl #24 */
/* @0x1ea940 mov r1, #0 */
/* @0x1ea944 lsr r9, r9, #8 */
/* @0x1ea948 str r2, [sp, #0x1b0] */
/* @0x1ea94c str r7, [sp, #0x1b4] */
/* @0x1ea950 str r0, [sp, #0x1b8] */
/* @0x1ea954 str r9, [sp, #0x1bc] */
/* @0x1ea958 ldr r12, [r4, r1] */
/* @0x1ea95c ldr r0, [r6, r1] */
/* @0x1ea960 mul r2, r12, r2 */
/* @0x1ea964 add r2, r0, r2, asr #8 */
/* @0x1ea968 usat r2, #0x8, r2 */
/* @0x1ea96c str r2, [r5, r1] */
/* @0x1ea970 add r1, r1, #4 */
/* @0x1ea974 cmp r1, #16 */
/* @0x1ea978 ldrne r2, [r5, r1] */
/* @0x1ea97c bne 0x1ea958 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xd48> */
/* @0x1ea980 ldr r2, [sp, #0x1b8] */
/* @0x1ea984 ldr r1, [sp, #0x1b4] */
/* @0x1ea988 ldr r6, [sp, #0x88] */
/* @0x1ea98c ldr r0, [sp, #0x1b0] */
/* @0x1ea990 lsl r2, r2, #16 */
/* @0x1ea994 ldr r12, [sp, #0x1bc] */
/* @0x1ea998 orr r2, r2, r1, lsl #8 */
/* @0x1ea99c cmp r6, #0 */
/* @0x1ea9a0 orr r2, r2, r0 */
/* @0x1ea9a4 orr r12, r2, r12, lsl #24 */
/* @0x1ea9a8 str r12, [sp, #0x14] */
/* @0x1ea9ac beq 0x1eb39c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x178c> */
/* @0x1ea9b0 ldr r7, [sp, #0x60] */

/* ── type 1 · 24 B 四边形批：闸 + 分配 ────────────────────────────────────────────
 *   闸：b4 != 0 且 +0x44（四边形数）!= 0；索引 = 记录->+0x14；AllocVerts(4, p12, 24, n*6)。
 */

/* @0x1ea9b4 cmp r7, #0 */
/* @0x1ea9b8 beq 0x1eac48 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1038> */
/* @0x1ea9bc ldr r9, [sp, #0x38] */
/* @0x1ea9c0 ldr r2, [r9, #0x44] */
/* @0x1ea9c4 cmp r2, #0 */
/* @0x1ea9c8 beq 0x1eac48 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1038> */
/* @0x1ea9cc ldr r10, [r9, #0x14] */
/* @0x1ea9d0 str r2, [sp, #0x40] */
/* @0x1ea9d4 str r10, [sp, #0x4c] */
/* @0x1ea9d8 ble 0x1eac3c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x102c> */
/* @0x1ea9dc str r8, [sp, #0x18] */
/* @0x1ea9e0 ldr r11, [sp, #0x40] */
/* @0x1ea9e4 mov r0, #4 */
/* @0x1ea9e8 ldr r12, [sp, #0x58] */
/* @0x1ea9ec mov r2, #24 */
/* @0x1ea9f0 ldr r1, [sp, #0x2bc] */
/* @0x1ea9f4 cmp r11, r12 */
/* @0x1ea9f8 movge r11, r12 */
/* @0x1ea9fc str r11, [sp, #0x3c] */
/* @0x1eaa00 add r3, r11, r11, lsl #1 */
/* @0x1eaa04 lsl r3, r3, #1 */
/* @0x1eaa08 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eaa0c cmp r11, #0 */

/* ── type 1 · 24 B 四边形批：装配 ────────────────────────────────────────────────
 *   [sp+0x20] = *0xfffff190 = g_SWFvertbuff；[sp+0x1c] = *0xfffff194 = g_SWFaavertbuff。
 */

/* @0x1eaa10 ble 0x1eac14 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1004> */
/* @0x1eaa14 ldr r6, [sp, #0x44] */
/* @0x1eaa18 add r4, r0, #48 */
/* @0x1eaa1c ldr r1, [pc, #-0x934] */
/* @0x1eaa20 add r5, r0, #72 */
/* @0x1eaa24 str r4, [sp, #0x30] */
/* @0x1eaa28 add r2, r0, #24 */
/* @0x1eaa2c str r5, [sp, #0x2c] */
/* @0x1eaa30 add r7, r0, #96 */
/* @0x1eaa34 str r2, [sp, #0x34] */
/* @0x1eaa38 add r8, r0, #120 */
/* @0x1eaa3c ldr r1, [r6, r1] */
/* @0x1eaa40 ldr r3, [pc, #-0x954] */
/* @0x1eaa44 str r7, [sp, #0x28] */
/* @0x1eaa48 mov r7, r4 */
/* @0x1eaa4c str r1, [sp, #0x20] */
/* @0x1eaa50 ldr r2, [pc, #-0x960] */
/* @0x1eaa54 ldr r3, [r6, r3] */
/* @0x1eaa58 ldr r9, [sp, #0x34] */
/* @0x1eaa5c ldr r10, [sp, #0x44] */
/* @0x1eaa60 str r8, [sp, #0x24] */
/* @0x1eaa64 mov r8, r5 */
/* @0x1eaa68 ldr r6, [sp, #0x28] */
/* @0x1eaa6c ldr r5, [sp, #0x24] */
/* @0x1eaa70 ldr r4, [sp, #0x4c] */
/* @0x1eaa74 str r3, [sp, #0x1c] */
/* @0x1eaa78 add r3, r0, #144 */
/* @0x1eaa7c str r9, [sp, #0x10] */
/* @0x1eaa80 str r11, [sp, #0xc] */
/* @0x1eaa84 ldr r2, [r10, r2] */
/* @0x1eaa88 vldr s15, [r2] */
/* @0x1eaa8c mov r2, r7 */
/* @0x1eaa90 mov r7, r6 */
/* @0x1eaa94 mov r6, r2 */
/* @0x1eaa98 ldrh r9, [r4, #2] */
/* @0x1eaa9c add r3, r3, #144 */
/* @0x1eaaa0 ldr r1, [sp, #0x10] */
/* @0x1eaaa4 add r4, r4, #4 */
/* @0x1eaaa8 ldr r2, [sp, #0x34] */
/* @0x1eaaac ldrh r10, [r4, #-4] */
/* @0x1eaab0 rsb r12, r0, r1 */
/* @0x1eaab4 ldr r11, [sp, #0xc] */
/* @0x1eaab8 lsl r9, r9, #3 */
/* @0x1eaabc str r9, [sp, #0x5c] */
/* @0x1eaac0 add r12, r12, r2 */
/* @0x1eaac4 ldr r9, [sp, #0x2c] */
/* @0x1eaac8 rsb r2, r0, r8 */
/* @0x1eaacc subs r11, r11, #1 */
/* @0x1eaad0 str r11, [sp, #0xc] */
/* @0x1eaad4 add r2, r2, r9 */
/* @0x1eaad8 ldr r11, [sp, #0x30] */
/* @0x1eaadc ldr r9, [sp, #0x20] */
/* @0x1eaae0 rsb r1, r0, r6 */

/* ── type 1 · 24 B 四边形批：每单元 6 顶点，uv = (f13,f14) ──────────────────────────
 *   A 组（填充点）与 B 组（填充 AA 点）交替写；A 组颜色 C（[sp+0x18]），B 组 C2。
 */

/* @0x1eaae4 lsl r10, r10, #3 */
/* @0x1eaae8 add r1, r1, r11 */
/* @0x1eaaec add r11, r9, r10 */
/* @0x1eaaf0 ldr r9, [sp, #0x1c] */
/* @0x1eaaf4 vldr s8, [r11] */
/* @0x1eaaf8 vldr s9, [r11, #4] */
/* @0x1eaafc add r10, r9, r10 */
/* @0x1eab00 ldr r11, [sp, #0x20] */
/* @0x1eab04 ldr r9, [sp, #0x5c] */
/* @0x1eab08 vldr s12, [r10] */
/* @0x1eab0c vldr s13, [r10, #4] */
/* @0x1eab10 add r6, r6, #144 */
/* @0x1eab14 add r10, r11, r9 */
/* @0x1eab18 ldr r11, [sp, #0x1c] */
/* @0x1eab1c vldr s14, [r10] */
/* @0x1eab20 vldr s2, [r10, #4] */
/* @0x1eab24 add r11, r11, r9 */
/* @0x1eab28 vldr s10, [r11] */
/* @0x1eab2c vldr s11, [r11, #4] */
/* @0x1eab30 ldr r11, [sp, #0x28] */
/* @0x1eab34 ldr r9, [sp, #0x10] */
/* @0x1eab38 rsb r10, r0, r7 */
/* @0x1eab3c add r10, r10, r11 */
/* @0x1eab40 ldr r11, [sp, #0x24] */
/* @0x1eab44 add r9, r9, #144 */
/* @0x1eab48 str r9, [sp, #0x10] */
/* @0x1eab4c rsb r9, r0, r5 */
/* @0x1eab50 vstr s8, [r3, #-288] */
/* @0x1eab54 add r11, r9, r11 */
/* @0x1eab58 ldr r9, [sp, #0x18] */
/* @0x1eab5c vstr s9, [r3, #-284] */
/* @0x1eab60 str r11, [sp, #0x5c] */
/* @0x1eab64 vstr s15, [r3, #-280] */
/* @0x1eab68 vstr s29, [r3, #-272] */
/* @0x1eab6c str r9, [r3, #-0x114] */
/* @0x1eab70 vstr s28, [r3, #-268] */
/* @0x1eab74 vstr s14, [r12, #-24] */
/* @0x1eab78 vstr s2, [r12, #-20] */
/* @0x1eab7c vstr s15, [r12, #-16] */
/* @0x1eab80 str r9, [r12, #-0xc] */
/* @0x1eab84 vstr s29, [r12, #-8] */
/* @0x1eab88 vstr s28, [r12, #-4] */
/* @0x1eab8c ldr r11, [sp, #0x14] */
/* @0x1eab90 vstr s12, [r1, #-48] */
/* @0x1eab94 ldr r12, [sp, #0x5c] */
/* @0x1eab98 vstr s13, [r1, #-44] */
/* @0x1eab9c vstr s15, [r1, #-40] */
/* @0x1eaba0 vstr s29, [r1, #-32] */
/* @0x1eaba4 str r11, [r1, #-0x24] */
/* @0x1eaba8 vstr s28, [r1, #-28] */
/* @0x1eabac add r8, r8, #144 */
/* @0x1eabb0 vstr s12, [r2, #-72] */
/* @0x1eabb4 vstr s13, [r2, #-68] */
/* @0x1eabb8 vstr s15, [r2, #-64] */
/* @0x1eabbc str r11, [r2, #-0x3c] */
/* @0x1eabc0 vstr s29, [r2, #-56] */
/* @0x1eabc4 vstr s28, [r2, #-52] */
/* @0x1eabc8 add r7, r7, #144 */
/* @0x1eabcc vstr s14, [r10, #-96] */
/* @0x1eabd0 vstr s2, [r10, #-92] */
/* @0x1eabd4 vstr s15, [r10, #-88] */
/* @0x1eabd8 str r9, [r10, #-0x54] */
/* @0x1eabdc vstr s29, [r10, #-80] */
/* @0x1eabe0 vstr s28, [r10, #-76] */
/* @0x1eabe4 add r5, r5, #144 */
/* @0x1eabe8 vstr s10, [r12, #-120] */
/* @0x1eabec vstr s11, [r12, #-116] */
/* @0x1eabf0 vstr s15, [r12, #-112] */
/* @0x1eabf4 str r11, [r12, #-0x6c] */
/* @0x1eabf8 vstr s29, [r12, #-104] */
/* @0x1eabfc vstr s28, [r12, #-100] */
/* @0x1eac00 bne 0x1eaa98 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xe88> */
/* @0x1eac04 ldr r5, [sp, #0x3c] */
/* @0x1eac08 ldr r4, [sp, #0x4c] */
/* @0x1eac0c add r4, r4, r5, lsl #2 */
/* @0x1eac10 str r4, [sp, #0x4c] */
/* @0x1eac14 ldr r6, [sp, #0x40] */

/* ── type 1 · 三角形批（24 B）：分配 ──────────────────────────────────────────────
 *   索引 = 记录->+0x08、个数 = +0x38；AllocVerts(4, p12, 24, n*3)。
 */

/* @0x1eac18 ldr r7, [sp, #0x3c] */
/* @0x1eac1c rsb r6, r7, r6 */
/* @0x1eac20 str r6, [sp, #0x40] */
/* @0x1eac24 cmp r6, #0 */
/* @0x1eac28 bgt 0x1ea9e0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdd0> */
/* @0x1eac2c ldr r9, [sp, #0x38] */
/* @0x1eac30 ldr r8, [sp, #0x18] */
/* @0x1eac34 ldr r2, [r9, #0x44] */
/* @0x1eac38 ldr r3, [r9, #0x38] */
/* @0x1eac3c ldr r10, [sp, #0x54] */
/* @0x1eac40 add r10, r10, r2, lsl #1 */
/* @0x1eac44 str r10, [sp, #0x54] */
/* @0x1eac48 ldr r11, [sp, #0x38] */
/* @0x1eac4c subs r4, r3, #0 */
/* @0x1eac50 ldr r6, [r11, #0x8] */
/* @0x1eac54 ble 0x1eacfc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10ec> */
/* @0x1eac58 ldr r7, [sp, #0x8c] */
/* @0x1eac5c ldr r9, [sp, #0x2bc] */
/* @0x1eac60 ldr r10, [sp, #0x44] */
/* @0x1eac64 cmp r4, r7 */

/* ── type 1 · 三角形批：逐索引写顶点 + 收尾 ────────────────────────────────────────
 *   坐标 g_SWFvertbuff[idx]，uv 常量 (f13,f14)，颜色 C；[sp+0x54] += 三角形数，
 *   然后 b 1e9f08 —— 回去跑公共的「线」通道（每个记录都要画线）。
 */

/* @0x1eac68 movlt r5, r4 */
/* @0x1eac6c movge r5, r7 */
/* @0x1eac70 mov r0, #4 */
/* @0x1eac74 mov r1, r9 */
/* @0x1eac78 mov r2, #24 */
/* @0x1eac7c add r11, r5, r5, lsl #1 */
/* @0x1eac80 mov r3, r11 */
/* @0x1eac84 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eac88 cmp r11, #0 */
/* @0x1eac8c ble 0x1eace8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10d8> */
/* @0x1eac90 ldr r12, [pc, #-0xba8] */
/* @0x1eac94 mov r2, r6 */
/* @0x1eac98 ldr r1, [pc, #-0xba8] */
/* @0x1eac9c add r6, r6, r11, lsl #1 */
/* @0x1eaca0 add r3, r0, #24 */
/* @0x1eaca4 ldr r12, [r10, r12] */
/* @0x1eaca8 ldr r1, [r10, r1] */
/* @0x1eacac vldr s15, [r1] */
/* @0x1eacb0 ldrh r1, [r2], #2 */
/* @0x1eacb4 add r3, r3, #24 */
/* @0x1eacb8 cmp r2, r6 */
/* @0x1eacbc add r1, r12, r1, lsl #3 */
/* @0x1eacc0 ldr r0, [r1] */
/* @0x1eacc4 ldr r1, [r1, #0x4] */
/* @0x1eacc8 vstr s15, [r3, #-40] */
/* @0x1eaccc str r8, [r3, #-0x24] */
/* @0x1eacd0 vstr s29, [r3, #-32] */
/* @0x1eacd4 str r0, [r3, #-0x30] */
/* @0x1eacd8 vstr s28, [r3, #-28] */
/* @0x1eacdc str r1, [r3, #-0x2c] */
/* @0x1eace0 bne 0x1eacb0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10a0> */
/* @0x1eace4 mov r6, r2 */
/* @0x1eace8 rsb r4, r5, r4 */
/* @0x1eacec cmp r4, #0 */
/* @0x1eacf0 bgt 0x1eac64 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1054> */
/* @0x1eacf4 ldr r12, [sp, #0x38] */
/* @0x1eacf8 ldr r3, [r12, #0x38] */
/* @0x1eacfc ldr r4, [sp, #0x54] */
/* @0x1ead00 add r4, r3, r4 */
/* @0x1ead04 str r4, [sp, #0x54] */
/* @0x1ead08 b 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */

/* ══ 段 E · type 2/3（位图 / 渐变填充）══════════════════════════════════════════════════════
 *   type 2 = 位图；type 3 = 先取 this->+0x7c[子对象->+0x0c]：
 *     · 记录 +0x10 >= 0 → 渐变底是一张位图（走 1eb82c，与 type 2 共用 UV 矩阵段）
 *     · 否则 +0x0c 指向一个 {w,h} 记录 → 按 diag(1/w,1/h) 建矩阵（渐变条）
 *   1ead0c 先按 r7（子对象类型）分：2 → 1eb69c，3 → 继续，其它 → 1e9f08。
 */

/* @0x1ead0c cmp r7, #2 */
/* @0x1ead10 beq 0x1eb69c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a8c> */
/* @0x1ead14 cmp r7, #3 */
/* @0x1ead18 bne 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead1c ldr r3, [r6, #0xc] */
/* @0x1ead20 cmn r3, #1 */
/* @0x1ead24 beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead28 ldr r8, [sp, #0xa8] */
/* @0x1ead2c ldr r2, [r8, #0x7c] */
/* @0x1ead30 ldr r3, [r2, r3, lsl #2] */
/* @0x1ead34 ldr r2, [r3, #0x10] */
/* @0x1ead38 cmp r2, #0 */
/* @0x1ead3c bge 0x1eb82c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1c1c> */
/* @0x1ead40 ldr r3, [r3, #0xc] */
/* @0x1ead44 cmp r3, #0 */
/* @0x1ead48 str r3, [sp, #0x90] */
/* @0x1ead4c beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1ead50 vmov.f32 s15, #1.000000e+00 */

/* ── 渐变矩阵：diag(1/w, 1/h, 1, 1) × 对象矩阵(obj+0x10) ───────────────────────────
 *   s14 = (float)rec->+4、s13 = (float)rec->+8；sp+432 先全填 0.0f（s30），
 *   再写 e0 = 1/s14、e5 = 1/s13、e10 = e15 = 1.0f（列主序：e0/e5 是 x/y 缩放）。
 *   Multiply(sp+176, 对象矩阵@r6+0x10, sp+432) ⇒ 合成矩阵供逐顶点取 uv。
 */

/* @0x1ead54 vldr s14, [r3, #4] */
/* @0x1ead58 vldr s13, [r3, #8] */
/* @0x1ead5c add r0, sp, #176 */
/* @0x1ead60 add r1, r6, #16 */
/* @0x1ead64 add r2, sp, #432 */
/* @0x1ead68 vstr s30, [sp, #488] */
/* @0x1ead6c vstr s30, [sp, #484] */
/* @0x1ead70 vstr s30, [sp, #480] */
/* @0x1ead74 vstr s30, [sp, #476] */
/* @0x1ead78 vstr s30, [sp, #468] */
/* @0x1ead7c vstr s30, [sp, #464] */
/* @0x1ead80 vstr s30, [sp, #460] */
/* @0x1ead84 vstr s30, [sp, #456] */
/* @0x1ead88 vstr s30, [sp, #448] */
/* @0x1ead8c vstr s30, [sp, #444] */
/* @0x1ead90 vstr s30, [sp, #440] */
/* @0x1ead94 vstr s30, [sp, #436] */
/* @0x1ead98 vcvt.f32.s32 s13, s13 */
/* @0x1ead9c vstr s15, [sp, #492] */
/* @0x1eada0 vstr s15, [sp, #472] */
/* @0x1eada4 vcvt.f32.s32 s14, s14 */
/* @0x1eada8 vdiv.f32 s14, s15, s14 */
/* @0x1eadac vdiv.f32 s15, s15, s13 */
/* @0x1eadb0 vstr s14, [sp, #432] */
/* @0x1eadb4 vstr s15, [sp, #452] */
/* @0x1eadb8 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eadbc ldr r6, [r6, #0x4] */

/* ── 采样器状态：由子对象->+0x04 的位决定 ──────────────────────────────────────────
 *   bics r6,r6,#2：r6 ∈ {0,2} → SetSamplerState(rsm, r6, 2, r6) 与 (rsm, r6, 3, r6)；
 *   否则 → 1eba08 的 (0,2,1)/(0,3,1)。
 *   this = *GOT 0x3edd00（.bss 0x4859c8，与 DrawShape 同一槽）⇒ RSM 单例。
 *   ★ 采样器状态 2/3 在这里被显式改写，本函数不保存也不还原（不同于 DrawSWF 的 8 项存取）。
 */

/* @0x1eadc0 ldr r0, [pc, #-0xcdc] */
/* @0x1eadc4 bics r6, r6, #2 */
/* @0x1eadc8 bne 0x1eba08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1df8> */
/* @0x1eadcc ldr r12, [sp, #0x44] */
/* @0x1eadd0 add r4, sp, #368 */
/* @0x1eadd4 mov r1, r6 */
/* @0x1eadd8 mov r2, #2 */
/* @0x1eaddc mov r3, r6 */
/* @0x1eade0 ldr r5, [r12, r0] */
/* @0x1eade4 mov r0, r5 */
/* @0x1eade8 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eadec mov r0, r5 */
/* @0x1eadf0 mov r1, r6 */
/* @0x1eadf4 mov r2, r7 */
/* @0x1eadf8 mov r3, r6 */
/* @0x1eadfc bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */

/* ── type 2/3 公共颜色：p7 × p9/p10 ───────────────────────────────────────────────
 *   与 1ea038 那段同构，但偏移数组用 p10（1ea038 段用 p11）：
 *   c = clamp8( p10[k] + (p9[k]·(p7[k]·c)>>8) >> 8 )，结果留在 sp+0x170..0x17c。
 */

/* @0x1eae00 ldr r12, [sp, #0x2a8] */
/* @0x1eae04 mov r3, #0 */
/* @0x1eae08 ldr r5, [sp, #0x2b0] */
/* @0x1eae0c ldr r6, [sp, #0x2b4] */
/* @0x1eae10 ldr r1, [r5, r3] */
/* @0x1eae14 ldr r0, [r12, r3] */
/* @0x1eae18 ldr r2, [r6, r3] */
/* @0x1eae1c mul r1, r0, r1 */
/* @0x1eae20 add r2, r2, r1, lsr #8 */
/* @0x1eae24 usat r2, #0x8, r2 */
/* @0x1eae28 str r2, [r4, r3] */
/* @0x1eae2c add r3, r3, #4 */
/* @0x1eae30 cmp r3, #16 */
/* @0x1eae34 bne 0x1eae10 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1200> */

/* ── type 2/3：打包 + b4 闸 ──────────────────────────────────────────────────────
 *   r4 = pack(C)（1eae5c 的 orr r4,r3,r0,lsl#24）；b4 == 0 → 1eb264（跳过四边形批）。
 */

/* @0x1eae38 ldr r3, [sp, #0x178] */
/* @0x1eae3c ldr r2, [sp, #0x174] */
/* @0x1eae40 ldr r7, [sp, #0x60] */
/* @0x1eae44 ldr r1, [sp, #0x170] */
/* @0x1eae48 lsl r3, r3, #16 */
/* @0x1eae4c ldr r0, [sp, #0x17c] */
/* @0x1eae50 orr r3, r3, r2, lsl #8 */
/* @0x1eae54 cmp r7, #0 */
/* @0x1eae58 orr r3, r3, r1 */
/* @0x1eae5c orr r4, r3, r0, lsl #24 */
/* @0x1eae60 beq 0x1eb264 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1654> */

/* ── type 2/3 · 四边形批：闸 + 分配 ──────────────────────────────────────────────
 *   闸：b4 != 0 且 +0x44 != 0；索引 = 记录->+0x14；顶点 = g_SWFvertbuff/AA；
 *   AllocVerts(4, [sp+0x90], 24, n*6)，[sp+0x90] 是该填充记录里的纹理对象指针。
 */

/* @0x1eae64 ldr r8, [sp, #0x38] */
/* @0x1eae68 ldr r0, [r8, #0x44] */
/* @0x1eae6c cmp r0, #0 */
/* @0x1eae70 beq 0x1eb264 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1654> */
/* @0x1eae74 ldr r6, [sp, #0x2ac] */
/* @0x1eae78 add r5, sp, #432 */
/* @0x1eae7c ldr r7, [sp, #0x2b0] */
/* @0x1eae80 mov r3, #0 */
/* @0x1eae84 ldr r8, [sp, #0x2b8] */
/* @0x1eae88 ldr r1, [r7, r3] */
/* @0x1eae8c ldr r12, [r6, r3] */
/* @0x1eae90 ldr r2, [r8, r3] */
/* @0x1eae94 mul r1, r12, r1 */
/* @0x1eae98 add r2, r2, r1, lsr #8 */
/* @0x1eae9c usat r2, #0x8, r2 */
/* @0x1eaea0 str r2, [r5, r3] */
/* @0x1eaea4 add r3, r3, #4 */
/* @0x1eaea8 cmp r3, #16 */
/* @0x1eaeac bne 0x1eae88 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1278> */
/* @0x1eaeb0 ldr r3, [sp, #0x1b8] */
/* @0x1eaeb4 subs r9, r0, #0 */
/* @0x1eaeb8 ldr r10, [sp, #0x38] */
/* @0x1eaebc ldr r2, [sp, #0x1b4] */
/* @0x1eaec0 ldr r1, [sp, #0x1b0] */
/* @0x1eaec4 lsl r3, r3, #16 */
/* @0x1eaec8 ldr r12, [sp, #0x1bc] */
/* @0x1eaecc ldr r10, [r10, #0x14] */
/* @0x1eaed0 orr r3, r3, r2, lsl #8 */
/* @0x1eaed4 orr r3, r3, r1 */
/* @0x1eaed8 str r9, [sp, #0x94] */
/* @0x1eaedc orr r12, r3, r12, lsl #24 */
/* @0x1eaee0 str r12, [sp, #0x20] */
/* @0x1eaee4 str r10, [sp, #0x98] */
/* @0x1eaee8 ble 0x1eb258 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1648> */
/* @0x1eaeec str r4, [sp, #0x1c] */

/* ── type 2/3 · 四边形批：分块（min 上限）与分配 ─────────────────────────────────
 *   s9/s12 = m0/m1、s10/s13 = m4/m5、s11/s14 = m12/m13（sp+176 起的矩阵）。
 *   与段 A 的变换通道一样只用这 6 个字。
 */

/* @0x1eaef0 ldr r11, [sp, #0x94] */
/* @0x1eaef4 mov r0, #4 */
/* @0x1eaef8 ldr r12, [sp, #0x58] */
/* @0x1eaefc mov r2, #24 */
/* @0x1eaf00 ldr r1, [sp, #0x90] */
/* @0x1eaf04 cmp r11, r12 */
/* @0x1eaf08 movge r11, r12 */
/* @0x1eaf0c str r11, [sp, #0x64] */
/* @0x1eaf10 add r3, r11, r11, lsl #1 */
/* @0x1eaf14 lsl r3, r3, #1 */
/* @0x1eaf18 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eaf1c cmp r11, #0 */
/* @0x1eaf20 ble 0x1eb234 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1624> */
/* @0x1eaf24 ldr r6, [sp, #0x44] */
/* @0x1eaf28 add r4, r0, #48 */
/* @0x1eaf2c ldr r1, [pc, #-0xe44] */
/* @0x1eaf30 add r5, r0, #72 */
/* @0x1eaf34 str r4, [sp, #0x3c] */
/* @0x1eaf38 add r2, r0, #24 */
/* @0x1eaf3c str r5, [sp, #0x40] */
/* @0x1eaf40 add r7, r0, #96 */
/* @0x1eaf44 str r2, [sp, #0x34] */
/* @0x1eaf48 add r8, r0, #120 */
/* @0x1eaf4c ldr r1, [r6, r1] */

/* ── type 2/3 · 四边形批：每单元 6 顶点，uv = M·(点) ────────────────────────────────
 *   与 16 B 批相比只多两步：先算 p = A[i] + f3·B[i]（s20 = f3，vmul/vmla），
 *   再用 m0..m13 变换成 (u,v) 写 +16/+20；位置写 p 本身，z 取全局。
 *   ⇒ 位图/渐变的 uv 是「对象空间坐标」，由 FillStyle 矩阵链映射到纹理空间。
 */

/* @0x1eaf50 vldr s9, [sp, #176] */
/* @0x1eaf54 ldr r3, [pc, #-0xe68] */
/* @0x1eaf58 vldr s10, [sp, #192] */
/* @0x1eaf5c ldr r9, [sp, #0x38] */
/* @0x1eaf60 vldr s11, [sp, #224] */
/* @0x1eaf64 ldr r10, [sp, #0x38] */
/* @0x1eaf68 vldr s12, [sp, #180] */
/* @0x1eaf6c str r1, [sp, #0x30] */
/* @0x1eaf70 vldr s13, [sp, #196] */
/* @0x1eaf74 str r7, [sp, #0x4c] */
/* @0x1eaf78 vldr s14, [sp, #228] */
/* @0x1eaf7c ldr r3, [r6, r3] */
/* @0x1eaf80 mov r6, r8 */
/* @0x1eaf84 ldr r10, [r10, #0x18] */
/* @0x1eaf88 ldr r11, [sp, #0x34] */
/* @0x1eaf8c str r4, [sp, #0x10] */
/* @0x1eaf90 ldr r2, [pc, #-0xea0] */
/* @0x1eaf94 ldr r4, [sp, #0x44] */
/* @0x1eaf98 ldr r9, [r9] */
/* @0x1eaf9c ldr r12, [sp, #0x64] */
/* @0x1eafa0 str r3, [sp, #0x2c] */
/* @0x1eafa4 add r3, r0, #144 */
/* @0x1eafa8 str r10, [sp, #0x28] */
/* @0x1eafac str r11, [sp, #0xc] */
/* @0x1eafb0 mov r11, r7 */
/* @0x1eafb4 str r5, [sp, #0x18] */
/* @0x1eafb8 str r8, [sp, #0x5c] */
/* @0x1eafbc str r9, [sp, #0x24] */
/* @0x1eafc0 str r12, [sp, #0x14] */
/* @0x1eafc4 ldr r2, [r4, r2] */
/* @0x1eafc8 ldr r5, [sp, #0x98] */
/* @0x1eafcc ldr r4, [r2] */
/* @0x1eafd0 mov r10, r5 */
/* @0x1eafd4 ldrh r12, [r10] */
/* @0x1eafd8 add r3, r3, #144 */
/* @0x1eafdc ldr r5, [sp, #0x14] */
/* @0x1eafe0 add r10, r10, #4 */
/* @0x1eafe4 ldr r7, [sp, #0xc] */
/* @0x1eafe8 ldrh r2, [r10, #-2] */
/* @0x1eafec subs r5, r5, #1 */
/* @0x1eaff0 ldr r8, [sp, #0x34] */
/* @0x1eaff4 lsl r12, r12, #3 */
/* @0x1eaff8 str r5, [sp, #0x14] */
/* @0x1eaffc rsb r1, r0, r7 */

/* ── type 2/3 · 四边形批：emit 续体 + 收尾（累加 2×四边形数）───────────────────────────
 *   [sp+0x54] += 2×四边形数；然后进三角形批。
 */

/* @0x1eb000 ldr r5, [sp, #0x24] */
/* @0x1eb004 add r1, r1, r8 */
/* @0x1eb008 ldr r8, [sp, #0x28] */
/* @0x1eb00c lsl r2, r2, #3 */
/* @0x1eb010 add r9, r5, r12 */
/* @0x1eb014 vldr s2, [r9, #4] */
/* @0x1eb018 vmov.f32 s6, s2 */
/* @0x1eb01c add r7, r7, #144 */
/* @0x1eb020 str r7, [sp, #0xc] */
/* @0x1eb024 add r7, r5, r2 */
/* @0x1eb028 add r5, r8, r2 */
/* @0x1eb02c vldr s4, [r7, #4] */
/* @0x1eb030 str r7, [sp, #0x8] */
/* @0x1eb034 add r7, r8, r12 */
/* @0x1eb038 ldr r8, [sp, #0x2c] */
/* @0x1eb03c vldr s7, [r7, #4] */
/* @0x1eb040 vldr s5, [r7] */
/* @0x1eb044 ldr r7, [sp, #0x30] */
/* @0x1eb048 vldr s8, [r5, #4] */
/* @0x1eb04c vmla.f32 s6, s7, s20 */
/* @0x1eb050 vldr s7, [r5] */
/* @0x1eb054 add r5, r7, r12 */
/* @0x1eb058 add r12, r8, r12 */
/* @0x1eb05c vldr s1, [r5] */
/* @0x1eb060 vldr s3, [r5, #4] */
/* @0x1eb064 ldr r5, [sp, #0x2c] */
/* @0x1eb068 vldr s23, [r9] */
/* @0x1eb06c ldr r8, [r12, #0x4] */
/* @0x1eb070 ldr r9, [sp, #0x8] */
/* @0x1eb074 vldr s0, [r9] */
/* @0x1eb078 ldr r9, [r12] */
/* @0x1eb07c add r12, r7, r2 */
/* @0x1eb080 add r2, r5, r2 */
/* @0x1eb084 vldr s15, [r12] */
/* @0x1eb088 vldr s26, [r2, #4] */
/* @0x1eb08c vstr s15, [sp] */
/* @0x1eb090 vldr s15, [r12, #4] */
/* @0x1eb094 vstr s15, [sp, #8] */
/* @0x1eb098 vldr s15, [r2] */
/* @0x1eb09c vstr s1, [r3, #-288] */
/* @0x1eb0a0 vstr s3, [r3, #-284] */
/* @0x1eb0a4 ldr r5, [sp, #0x10] */
/* @0x1eb0a8 ldr r7, [sp, #0x3c] */
/* @0x1eb0ac ldr r12, [sp, #0x1c] */
/* @0x1eb0b0 rsb r2, r0, r5 */
/* @0x1eb0b4 add r5, r5, #144 */
/* @0x1eb0b8 str r5, [sp, #0x10] */
/* @0x1eb0bc ldr r5, [sp, #0x18] */
/* @0x1eb0c0 add r2, r2, r7 */
/* @0x1eb0c4 ldr r7, [sp, #0x40] */
/* @0x1eb0c8 rsb r5, r0, r5 */
/* @0x1eb0cc str r12, [r3, #-0x114] */
/* @0x1eb0d0 add r12, r5, r7 */
/* @0x1eb0d4 ldr r5, [sp, #0x18] */
/* @0x1eb0d8 ldr r7, [sp, #0x20] */
/* @0x1eb0dc add r5, r5, #144 */
/* @0x1eb0e0 str r5, [sp, #0x18] */
/* @0x1eb0e4 vmov.f32 s3, s4 */
/* @0x1eb0e8 ldr r5, [sp, #0x1c] */
/* @0x1eb0ec str r4, [r3, #-0x118] */
/* @0x1eb0f0 vmla.f32 s3, s8, s20 */
/* @0x1eb0f4 vmov.f32 s25, s23 */
/* @0x1eb0f8 vmov.f32 s24, s0 */
/* @0x1eb0fc vmla.f32 s25, s5, s20 */
/* @0x1eb100 vmla.f32 s24, s7, s20 */
/* @0x1eb104 vmul.f32 s1, s2, s10 */
/* @0x1eb108 vmul.f32 s2, s2, s13 */
/* @0x1eb10c vmov.f32 s8, s3 */
/* @0x1eb110 vmul.f32 s3, s4, s10 */
/* @0x1eb114 vmul.f32 s4, s4, s13 */
/* @0x1eb118 vmul.f32 s5, s6, s10 */
/* @0x1eb11c vmul.f32 s6, s6, s13 */
/* @0x1eb120 vmul.f32 s7, s8, s10 */
/* @0x1eb124 vmul.f32 s8, s8, s13 */
/* @0x1eb128 vmla.f32 s1, s23, s9 */
/* @0x1eb12c vmla.f32 s2, s23, s12 */
/* @0x1eb130 vmla.f32 s3, s0, s9 */
/* @0x1eb134 vmla.f32 s4, s0, s12 */
/* @0x1eb138 vmla.f32 s5, s25, s9 */
/* @0x1eb13c vmla.f32 s6, s25, s12 */
/* @0x1eb140 vmla.f32 s7, s24, s9 */
/* @0x1eb144 vmla.f32 s8, s24, s12 */
/* @0x1eb148 vadd.f32 s2, s2, s14 */
/* @0x1eb14c vadd.f32 s1, s1, s11 */
/* @0x1eb150 vstr s2, [r3, #-268] */
/* @0x1eb154 vldr s2, [sp] */
/* @0x1eb158 vadd.f32 s3, s3, s11 */
/* @0x1eb15c vstr s1, [r3, #-272] */
/* @0x1eb160 str r5, [r1, #-0xc] */
/* @0x1eb164 vstr s2, [r1, #-24] */
/* @0x1eb168 ldr r5, [sp, #0x4c] */
/* @0x1eb16c vldr s2, [sp, #8] */
/* @0x1eb170 str r4, [r1, #-0x10] */
/* @0x1eb174 vstr s2, [r1, #-20] */
/* @0x1eb178 vadd.f32 s4, s4, s14 */
/* @0x1eb17c vstr s3, [r1, #-8] */
/* @0x1eb180 vadd.f32 s5, s5, s11 */
/* @0x1eb184 vstr s4, [r1, #-4] */
/* @0x1eb188 str r7, [r2, #-0x24] */
/* @0x1eb18c rsb r1, r0, r11 */
/* @0x1eb190 ldr r7, [sp, #0x5c] */
/* @0x1eb194 add r1, r1, r5 */
/* @0x1eb198 str r8, [r2, #-0x2c] */
/* @0x1eb19c add r11, r11, #144 */
/* @0x1eb1a0 str r9, [r2, #-0x30] */
/* @0x1eb1a4 str r4, [r2, #-0x28] */
/* @0x1eb1a8 vadd.f32 s6, s6, s14 */
/* @0x1eb1ac vstr s5, [r2, #-32] */
/* @0x1eb1b0 vadd.f32 s7, s7, s11 */
/* @0x1eb1b4 vstr s6, [r2, #-28] */
/* @0x1eb1b8 rsb r2, r0, r6 */
/* @0x1eb1bc vstr s5, [r12, #-56] */
/* @0x1eb1c0 vstr s6, [r12, #-52] */
/* @0x1eb1c4 str r9, [r12, #-0x48] */
/* @0x1eb1c8 str r8, [r12, #-0x44] */
/* @0x1eb1cc add r2, r2, r7 */
/* @0x1eb1d0 ldr r8, [sp, #0x20] */
/* @0x1eb1d4 vldr s2, [sp] */
/* @0x1eb1d8 ldr r5, [sp, #0x1c] */
/* @0x1eb1dc add r6, r6, #144 */
/* @0x1eb1e0 str r4, [r12, #-0x40] */
/* @0x1eb1e4 str r8, [r12, #-0x3c] */
/* @0x1eb1e8 vstr s3, [r1, #-80] */
/* @0x1eb1ec vstr s4, [r1, #-76] */
/* @0x1eb1f0 vstr s2, [r1, #-96] */
/* @0x1eb1f4 str r4, [r1, #-0x58] */
/* @0x1eb1f8 vldr s3, [sp, #8] */
/* @0x1eb1fc vadd.f32 s8, s8, s14 */
/* @0x1eb200 vstr s3, [r1, #-92] */
/* @0x1eb204 str r5, [r1, #-0x54] */
/* @0x1eb208 vstr s15, [r2, #-120] */
/* @0x1eb20c vstr s26, [r2, #-116] */
/* @0x1eb210 str r4, [r2, #-0x70] */
/* @0x1eb214 str r8, [r2, #-0x6c] */
/* @0x1eb218 vstr s7, [r2, #-104] */
/* @0x1eb21c vstr s8, [r2, #-100] */
/* @0x1eb220 bne 0x1eafd4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x13c4> */
/* @0x1eb224 ldr r7, [sp, #0x64] */
/* @0x1eb228 ldr r6, [sp, #0x98] */
/* @0x1eb22c add r6, r6, r7, lsl #2 */
/* @0x1eb230 str r6, [sp, #0x98] */
/* @0x1eb234 ldr r8, [sp, #0x94] */
/* @0x1eb238 ldr r9, [sp, #0x64] */
/* @0x1eb23c rsb r8, r9, r8 */
/* @0x1eb240 str r8, [sp, #0x94] */
/* @0x1eb244 cmp r8, #0 */
/* @0x1eb248 bgt 0x1eaef0 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x12e0> */
/* @0x1eb24c ldr r10, [sp, #0x38] */
/* @0x1eb250 ldr r4, [sp, #0x1c] */
/* @0x1eb254 ldr r0, [r10, #0x44] */
/* @0x1eb258 ldr r11, [sp, #0x54] */
/* @0x1eb25c add r11, r11, r0, lsl #1 */
/* @0x1eb260 str r11, [sp, #0x54] */

/* ── type 2/3 · 三角形批（24 B）：分配 ────────────────────────────────────────────
 *   AllocVerts(4, [sp+0x90], 24, n*3)，索引 = 记录->+0x08、个数 = +0x38。
 */

/* @0x1eb264 ldr r12, [sp, #0x38] */
/* @0x1eb268 ldr r10, [r12, #0x38] */
/* @0x1eb26c ldr r7, [r12, #0x8] */
/* @0x1eb270 cmp r10, #0 */
/* @0x1eb274 mov r3, r10 */
/* @0x1eb278 ble 0x1eb368 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1758> */
/* @0x1eb27c ldr r6, [sp, #0x90] */
/* @0x1eb280 ldr r8, [sp, #0x8c] */
/* @0x1eb284 ldr r9, [sp, #0x44] */
/* @0x1eb288 cmp r10, r8 */
/* @0x1eb28c movlt r5, r10 */
/* @0x1eb290 movge r5, r8 */
/* @0x1eb294 mov r0, #4 */
/* @0x1eb298 mov r1, r6 */
/* @0x1eb29c mov r2, #24 */
/* @0x1eb2a0 add r11, r5, r5, lsl #1 */
/* @0x1eb2a4 mov r3, r11 */
/* @0x1eb2a8 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eb2ac cmp r11, #0 */
/* @0x1eb2b0 ble 0x1eb354 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1744> */

/* ── type 2/3 · 三角形批：每索引 1 顶点，uv = M·(点) ───────────────────────────────
 *   坐标只取 g_SWFvertbuff（无 AA 项），颜色 r4 = C，z 取全局；uv 与四边形批同法变换。
 */

/* @0x1eb2b4 ldr r1, [pc, #0x7bc] */
/* @0x1eb2b8 mov r2, r7 */
/* @0x1eb2bc ldr r12, [pc, #0x7b8] */
/* @0x1eb2c0 add r11, r7, r11, lsl #1 */
/* @0x1eb2c4 ldr r7, [sp, #0x38] */
/* @0x1eb2c8 add r0, r0, #24 */
/* @0x1eb2cc vldr s7, [sp, #176] */
/* @0x1eb2d0 vldr s8, [sp, #192] */
/* @0x1eb2d4 vldr s9, [sp, #224] */
/* @0x1eb2d8 vldr s10, [sp, #180] */
/* @0x1eb2dc ldr r3, [r7] */
/* @0x1eb2e0 vldr s11, [sp, #196] */
/* @0x1eb2e4 ldr r7, [r9, r1] */
/* @0x1eb2e8 vldr s12, [sp, #228] */
/* @0x1eb2ec ldr r1, [r9, r12] */
/* @0x1eb2f0 vldr s6, [r1] */
/* @0x1eb2f4 ldrh r1, [r2], #2 */
/* @0x1eb2f8 add r0, r0, #24 */
/* @0x1eb2fc cmp r2, r11 */
/* @0x1eb300 lsl r1, r1, #3 */
/* @0x1eb304 add r12, r7, r1 */
/* @0x1eb308 vldr s15, [r12] */
/* @0x1eb30c add r1, r3, r1 */
/* @0x1eb310 ldr r12, [r12, #0x4] */
/* @0x1eb314 vstr s15, [r0, #-48] */
/* @0x1eb318 vstr s6, [r0, #-40] */
/* @0x1eb31c str r12, [r0, #-0x2c] */
/* @0x1eb320 vldr s15, [r1, #4] */
/* @0x1eb324 vmul.f32 s14, s15, s8 */
/* @0x1eb328 vldr s13, [r1] */
/* @0x1eb32c str r4, [r0, #-0x24] */
/* @0x1eb330 vmul.f32 s15, s15, s11 */
/* @0x1eb334 vmla.f32 s14, s13, s7 */
/* @0x1eb338 vmla.f32 s15, s13, s10 */
/* @0x1eb33c vadd.f32 s14, s14, s9 */
/* @0x1eb340 vadd.f32 s15, s15, s12 */
/* @0x1eb344 vstr s14, [r0, #-32] */
/* @0x1eb348 vstr s15, [r0, #-28] */
/* @0x1eb34c bne 0x1eb2f4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x16e4> */
/* @0x1eb350 mov r7, r2 */
/* @0x1eb354 rsb r10, r5, r10 */
/* @0x1eb358 cmp r10, #0 */
/* @0x1eb35c bgt 0x1eb288 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1678> */
/* @0x1eb360 ldr r8, [sp, #0x38] */
/* @0x1eb364 ldr r3, [r8, #0x38] */

/* ── type 2/3 · 三角形批：收尾 + 线 AA 溢出告警 ───────────────────────────────────
 *   [sp+0x54] += 三角形数，b 1e9f08 回公共「线」通道。
 *   1eb378 是线 AA 的 >65536 告警（同 1ea838，串换成 "…aa verts!!"）。
 */

/* @0x1eb368 ldr r9, [sp, #0x54] */
/* @0x1eb36c add r9, r3, r9 */
/* @0x1eb370 str r9, [sp, #0x54] */
/* @0x1eb374 b 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1eb378 ldr r8, [sp, #0x44] */
/* @0x1eb37c ldr r3, [pc, #0x6fc] */
/* @0x1eb380 ldr r1, [sp, #0xac] */
/* @0x1eb384 ldr r3, [r8, r3] */
/* @0x1eb388 ldr r0, [r3] */
/* @0x1eb38c ldr r3, [r0] */
/* @0x1eb390 ldr r3, [r3, #0xc] */
/* @0x1eb394 blx r3 */
/* @0x1eb398 b 0x1ea404 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x7f4> */

/* ══ 段 F · type 1 且 b5==0：16 B 无纹理填充批 ══════════════════════════════════════════════
 *   1ea9ac 的 beq 落到这里：四边形（+0x14/+0x44，n*6）与三角形（+0x08/+0x38，n*3）都用
 *   16 B 顶点、AllocVerts(4, 0, 16, …)，坐标取 g_SWFvertbuff，颜色 C。
 *   闸：b4 != 0 且 +0x44 != 0，否则直接跳三角形批。
 */

/* @0x1eb39c ldr r5, [sp, #0x60] */
/* @0x1eb3a0 cmp r5, #0 */
/* @0x1eb3a4 beq 0x1eb5f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19e8> */
/* @0x1eb3a8 ldr r6, [sp, #0x38] */
/* @0x1eb3ac ldr r2, [r6, #0x44] */
/* @0x1eb3b0 cmp r2, #0 */
/* @0x1eb3b4 beq 0x1eb5f8 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19e8> */
/* @0x1eb3b8 ldr r7, [r6, #0x14] */
/* @0x1eb3bc str r2, [sp, #0x40] */
/* @0x1eb3c0 str r7, [sp, #0x4c] */
/* @0x1eb3c4 ble 0x1eb5ec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19dc> */
/* @0x1eb3c8 str r8, [sp, #0x18] */
/* @0x1eb3cc ldr r8, [sp, #0x40] */
/* @0x1eb3d0 mov r0, #4 */
/* @0x1eb3d4 ldr r9, [sp, #0x58] */
/* @0x1eb3d8 mov r1, #0 */
/* @0x1eb3dc mov r2, #16 */
/* @0x1eb3e0 cmp r8, r9 */
/* @0x1eb3e4 movge r8, r9 */
/* @0x1eb3e8 str r8, [sp, #0x3c] */
/* @0x1eb3ec add r3, r8, r8, lsl #1 */
/* @0x1eb3f0 lsl r3, r3, #1 */
/* @0x1eb3f4 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */

/* ── 16 B 填充四边形批：装配 ─────────────────────────────────────────────────────
 *   [sp+0x20] = g_SWFvertbuff（0xfffff190）、[sp+0x1c] = g_SWFaavertbuff（0xfffff194）。
 */

/* @0x1eb3f8 cmp r8, #0 */
/* @0x1eb3fc ble 0x1eb5c4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x19b4> */
/* @0x1eb400 ldr r4, [sp, #0x44] */
/* @0x1eb404 add r10, r0, #16 */
/* @0x1eb408 ldr r1, [pc, #0x668] */
/* @0x1eb40c add r11, r0, #32 */
/* @0x1eb410 str r10, [sp, #0x24] */
/* @0x1eb414 add r12, r0, #48 */
/* @0x1eb418 str r11, [sp, #0x2c] */
/* @0x1eb41c add r5, r0, #64 */
/* @0x1eb420 str r12, [sp, #0x28] */
/* @0x1eb424 add r6, r0, #80 */
/* @0x1eb428 ldr r1, [r4, r1] */
/* @0x1eb42c mov r8, r11 */
/* @0x1eb430 ldr r3, [pc, #0x64c] */
/* @0x1eb434 mov r7, r12 */
/* @0x1eb438 str r5, [sp, #0x34] */
/* @0x1eb43c str r1, [sp, #0x20] */
/* @0x1eb440 ldr r3, [r4, r3] */
/* @0x1eb444 str r6, [sp, #0x30] */
/* @0x1eb448 mov r6, r5 */
/* @0x1eb44c str r10, [sp, #0x10] */
/* @0x1eb450 ldr r2, [pc, #0x624] */
/* @0x1eb454 ldr r9, [sp, #0x3c] */
/* @0x1eb458 ldr r10, [sp, #0x44] */
/* @0x1eb45c ldr r5, [sp, #0x30] */
/* @0x1eb460 ldr r4, [sp, #0x4c] */
/* @0x1eb464 str r3, [sp, #0x1c] */
/* @0x1eb468 add r3, r0, #96 */
/* @0x1eb46c str r9, [sp, #0xc] */
/* @0x1eb470 ldr r2, [r10, r2] */
/* @0x1eb474 vldr s15, [r2] */

/* ── 16 B 填充四边形批：每单元 6 顶点（A0,A1,B0,B0,A1,B1）───────────────────────────
 *   写法与公共 16 B 批同构，只是源换成填充缓冲、颜色 C 与 C2。
 */

/* @0x1eb478 ldrh r9, [r4, #2] */
/* @0x1eb47c add r3, r3, #96 */
/* @0x1eb480 ldr r1, [sp, #0x10] */
/* @0x1eb484 add r4, r4, #4 */
/* @0x1eb488 ldr r2, [sp, #0x24] */
/* @0x1eb48c ldrh r10, [r4, #-4] */
/* @0x1eb490 rsb r12, r0, r1 */
/* @0x1eb494 ldr r11, [sp, #0xc] */
/* @0x1eb498 lsl r9, r9, #3 */
/* @0x1eb49c str r9, [sp, #0x5c] */
/* @0x1eb4a0 add r12, r12, r2 */
/* @0x1eb4a4 ldr r9, [sp, #0x28] */
/* @0x1eb4a8 rsb r2, r0, r7 */
/* @0x1eb4ac subs r11, r11, #1 */
/* @0x1eb4b0 str r11, [sp, #0xc] */
/* @0x1eb4b4 add r2, r2, r9 */
/* @0x1eb4b8 ldr r11, [sp, #0x2c] */
/* @0x1eb4bc ldr r9, [sp, #0x20] */
/* @0x1eb4c0 rsb r1, r0, r8 */
/* @0x1eb4c4 lsl r10, r10, #3 */
/* @0x1eb4c8 add r1, r1, r11 */
/* @0x1eb4cc add r11, r9, r10 */
/* @0x1eb4d0 ldr r9, [sp, #0x1c] */
/* @0x1eb4d4 vldr s8, [r11] */
/* @0x1eb4d8 vldr s9, [r11, #4] */
/* @0x1eb4dc add r10, r9, r10 */
/* @0x1eb4e0 ldr r11, [sp, #0x20] */
/* @0x1eb4e4 ldr r9, [sp, #0x5c] */
/* @0x1eb4e8 vldr s12, [r10] */
/* @0x1eb4ec vldr s13, [r10, #4] */
/* @0x1eb4f0 add r8, r8, #96 */
/* @0x1eb4f4 add r10, r11, r9 */
/* @0x1eb4f8 ldr r11, [sp, #0x1c] */
/* @0x1eb4fc vldr s14, [r10] */
/* @0x1eb500 vldr s2, [r10, #4] */
/* @0x1eb504 add r11, r11, r9 */
/* @0x1eb508 vldr s10, [r11] */
/* @0x1eb50c vldr s11, [r11, #4] */
/* @0x1eb510 ldr r11, [sp, #0x34] */
/* @0x1eb514 ldr r9, [sp, #0x10] */
/* @0x1eb518 rsb r10, r0, r6 */
/* @0x1eb51c add r10, r10, r11 */
/* @0x1eb520 ldr r11, [sp, #0x30] */
/* @0x1eb524 add r9, r9, #96 */
/* @0x1eb528 str r9, [sp, #0x10] */
/* @0x1eb52c rsb r9, r0, r5 */
/* @0x1eb530 vstr s8, [r3, #-192] */
/* @0x1eb534 add r11, r9, r11 */
/* @0x1eb538 ldr r9, [sp, #0x18] */
/* @0x1eb53c vstr s9, [r3, #-188] */
/* @0x1eb540 vstr s15, [r3, #-184] */
/* @0x1eb544 str r11, [sp, #0x5c] */
/* @0x1eb548 add r7, r7, #96 */
/* @0x1eb54c str r9, [r3, #-0xb4] */
/* @0x1eb550 vstr s14, [r12, #-16] */
/* @0x1eb554 vstr s2, [r12, #-12] */
/* @0x1eb558 vstr s15, [r12, #-8] */
/* @0x1eb55c str r9, [r12, #-0x4] */
/* @0x1eb560 add r6, r6, #96 */
/* @0x1eb564 ldr r12, [sp, #0x5c] */
/* @0x1eb568 vstr s12, [r1, #-32] */
/* @0x1eb56c ldr r11, [sp, #0x14] */
/* @0x1eb570 vstr s13, [r1, #-28] */
/* @0x1eb574 vstr s15, [r1, #-24] */
/* @0x1eb578 add r5, r5, #96 */
/* @0x1eb57c str r11, [r1, #-0x14] */
/* @0x1eb580 vstr s12, [r2, #-48] */
/* @0x1eb584 vstr s13, [r2, #-44] */
/* @0x1eb588 vstr s15, [r2, #-40] */
/* @0x1eb58c str r11, [r2, #-0x24] */
/* @0x1eb590 vstr s14, [r10, #-64] */
/* @0x1eb594 vstr s2, [r10, #-60] */
/* @0x1eb598 vstr s15, [r10, #-56] */
/* @0x1eb59c str r9, [r10, #-0x34] */
/* @0x1eb5a0 vstr s10, [r12, #-80] */
/* @0x1eb5a4 vstr s11, [r12, #-76] */
/* @0x1eb5a8 vstr s15, [r12, #-72] */
/* @0x1eb5ac str r11, [r12, #-0x44] */
/* @0x1eb5b0 bne 0x1eb478 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1868> */
/* @0x1eb5b4 ldr r5, [sp, #0x3c] */
/* @0x1eb5b8 ldr r4, [sp, #0x4c] */
/* @0x1eb5bc add r4, r4, r5, lsl #2 */
/* @0x1eb5c0 str r4, [sp, #0x4c] */

/* ── 16 B 填充四边形批：收尾 ─────────────────────────────────────────────────────
 *   [sp+0x54] += 2×四边形数（1eb5e4 读 +0x44）。
 */

/* @0x1eb5c4 ldr r6, [sp, #0x40] */
/* @0x1eb5c8 ldr r7, [sp, #0x3c] */
/* @0x1eb5cc rsb r6, r7, r6 */
/* @0x1eb5d0 str r6, [sp, #0x40] */
/* @0x1eb5d4 cmp r6, #0 */
/* @0x1eb5d8 bgt 0x1eb3cc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x17bc> */
/* @0x1eb5dc ldr r9, [sp, #0x38] */
/* @0x1eb5e0 ldr r8, [sp, #0x18] */
/* @0x1eb5e4 ldr r2, [r9, #0x44] */
/* @0x1eb5e8 ldr r3, [r9, #0x38] */
/* @0x1eb5ec ldr r10, [sp, #0x54] */
/* @0x1eb5f0 add r10, r10, r2, lsl #1 */
/* @0x1eb5f4 str r10, [sp, #0x54] */

/* ── 16 B 填充三角形批：分配 + 逐索引写顶点 ───────────────────────────────────────
 *   AllocVerts(4, 0, 16, n*3)，索引 = +0x08，坐标 = g_SWFvertbuff[idx]，颜色 C。
 *   1eb698 b 1eacf4 → 回 type 1 尾巴（累加三角形数后进公共线通道）。
 */

/* @0x1eb5f8 ldr r11, [sp, #0x38] */
/* @0x1eb5fc subs r4, r3, #0 */
/* @0x1eb600 ldr r6, [r11, #0x8] */
/* @0x1eb604 ble 0x1eacfc <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10ec> */
/* @0x1eb608 ldr r7, [sp, #0x8c] */
/* @0x1eb60c ldr r9, [sp, #0x44] */
/* @0x1eb610 cmp r4, r7 */
/* @0x1eb614 movlt r5, r4 */
/* @0x1eb618 movge r5, r7 */
/* @0x1eb61c mov r0, #4 */
/* @0x1eb620 mov r1, #0 */
/* @0x1eb624 mov r2, #16 */
/* @0x1eb628 add r10, r5, r5, lsl #1 */
/* @0x1eb62c mov r3, r10 */
/* @0x1eb630 bl 0x185418 <_ZN8Graphics10AllocVertsE9ePrimTypePvii> */
/* @0x1eb634 cmp r10, #0 */
/* @0x1eb638 ble 0x1eb68c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a7c> */
/* @0x1eb63c ldr r1, [pc, #0x438] */
/* @0x1eb640 mov r2, r6 */
/* @0x1eb644 ldr r12, [pc, #0x42c] */
/* @0x1eb648 add r6, r6, r10, lsl #1 */
/* @0x1eb64c add r3, r0, #16 */
/* @0x1eb650 ldr r1, [r9, r1] */
/* @0x1eb654 ldr r12, [r9, r12] */
/* @0x1eb658 ldr r10, [r1] */
/* @0x1eb65c ldrh r1, [r2], #2 */
/* @0x1eb660 add r3, r3, #16 */
/* @0x1eb664 cmp r2, r6 */
/* @0x1eb668 add r1, r12, r1, lsl #3 */
/* @0x1eb66c ldr r0, [r1] */
/* @0x1eb670 ldr r1, [r1, #0x4] */
/* @0x1eb674 str r10, [r3, #-0x18] */
/* @0x1eb678 str r0, [r3, #-0x20] */
/* @0x1eb67c str r1, [r3, #-0x1c] */
/* @0x1eb680 str r8, [r3, #-0x14] */
/* @0x1eb684 bne 0x1eb65c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a4c> */
/* @0x1eb688 mov r6, r2 */
/* @0x1eb68c rsb r4, r5, r4 */
/* @0x1eb690 cmp r4, #0 */
/* @0x1eb694 bgt 0x1eb610 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1a00> */
/* @0x1eb698 b 0x1eacf4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x10e4> */

/* ══ 段 G · type 2（位图）头部：texid → GR_Texture_Exists → UV 矩阵 ════════════════════════
 *   bmp = this->+0x54[ 子对象->+0x08 ]
 *   texid = (int16)bmp->+20；GR_Texture_Exists(texid) == 0 → 整条跳过（1eba6c）
 *   tex = (*GOT 0x3ed924 的纹理表)->+4[texid]；tex->+4 = 宽、+8 = 高（vcvt 后作除数）。
 *   ⇒ 这是全函数唯一的「纹理存在性」检查，也是唯一读纹理表的地方（两处 bl 都在此段）。
 */

/* @0x1eb69c ldr r3, [r6, #0x8] */
/* @0x1eb6a0 cmp r3, #0 */
/* @0x1eb6a4 blt 0x1eb9ac <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1d9c> */
/* @0x1eb6a8 ldr r5, [sp, #0xa8] */
/* @0x1eb6ac ldr r2, [r5, #0x54] */
/* @0x1eb6b0 ldr r8, [r2, r3, lsl #2] */
/* @0x1eb6b4 ldrsh r0, [r8, #20] */
/* @0x1eb6b8 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eb6bc cmp r0, #0 */
/* @0x1eb6c0 beq 0x1eba6c <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e5c> */
/* @0x1eb6c4 ldr r10, [sp, #0x44] */

/* ── 位图 UV 矩阵：两组 diag（M1 进 sp+240、M2 进 sp+304）─────────────────────────────
 *   M1(sp+240) = diag( (int16)bmp->+0 / w , (int16)bmp->+2 / h , 1, 1 )
 *   M2(sp+304) = diag( ((int16)bmp->+4 - 1) / w , ((int16)bmp->+6 - 1) / h , 1, 1 )
 *   Multiply(sp+368, M1, M2)；Multiply(sp+432, p6, sp+368)；Multiply(sp+176, bmp+0x0c, sp+432)
 *   ⇒ uv' = (bmp 自带矩阵) · p6 · 归一化矩形，落到 sp+176 供逐顶点变换。
 */

/* @0x1eb6c8 mov lr, #1065353216 */
/* @0x1eb6cc ldr r3, [pc, #0x3b4] */
/* @0x1eb6d0 add r4, sp, #368 */
/* @0x1eb6d4 ldrsh r2, [r8, #20] */
/* @0x1eb6d8 add r5, sp, #432 */
/* @0x1eb6dc ldrsh r9, [r8] */
/* @0x1eb6e0 mov r0, r4 */
/* @0x1eb6e4 ldr r3, [r10, r3] */
/* @0x1eb6e8 add r1, sp, #240 */
/* @0x1eb6ec ldrsh r11, [r8, #2] */
/* @0x1eb6f0 vmov s12, r9 */
/* @0x1eb6f4 ldr r3, [r3, #0x4] */
/* @0x1eb6f8 vmov s13, r11 */
/* @0x1eb6fc vcvt.f32.s32 s12, s12 */
/* @0x1eb700 ldr r3, [r3, r2, lsl #2] */
/* @0x1eb704 add r2, sp, #304 */
/* @0x1eb708 ldr r3, [r3] */
/* @0x1eb70c vldr s14, [r3, #4] */
/* @0x1eb710 vldr s15, [r3, #8] */
/* @0x1eb714 str lr, [sp, #0x16c] */
/* @0x1eb718 str lr, [sp, #0x158] */
/* @0x1eb71c vstr s30, [sp, #348] */
/* @0x1eb720 vcvt.f32.s32 s14, s14 */
/* @0x1eb724 str lr, [sp, #0x144] */
/* @0x1eb728 str lr, [sp, #0x130] */
/* @0x1eb72c vstr s30, [sp, #340] */
/* @0x1eb730 vstr s30, [sp, #336] */
/* @0x1eb734 vstr s30, [sp, #332] */
/* @0x1eb738 vstr s30, [sp, #328] */
/* @0x1eb73c vstr s30, [sp, #320] */
/* @0x1eb740 vstr s30, [sp, #316] */
/* @0x1eb744 vstr s30, [sp, #312] */
/* @0x1eb748 vstr s30, [sp, #308] */
/* @0x1eb74c vstr s30, [sp, #360] */
/* @0x1eb750 str r3, [sp, #0x90] */
/* @0x1eb754 vcvt.f32.s32 s15, s15 */
/* @0x1eb758 vcvt.f32.s32 s13, s13 */
/* @0x1eb75c vdiv.f32 s12, s12, s14 */
/* @0x1eb760 vdiv.f32 s13, s13, s15 */
/* @0x1eb764 vstr s12, [sp, #352] */
/* @0x1eb768 vstr s13, [sp, #356] */
/* @0x1eb76c ldrsh r12, [r8, #4] */
/* @0x1eb770 ldrsh r3, [r8, #6] */
/* @0x1eb774 vstr s30, [sp, #296] */
/* @0x1eb778 sub r12, r12, #1 */
/* @0x1eb77c str lr, [sp, #0x12c] */
/* @0x1eb780 sub r3, r3, #1 */
/* @0x1eb784 str lr, [sp, #0x118] */
/* @0x1eb788 vmov s2, r12 */
/* @0x1eb78c vstr s30, [sp, #292] */
/* @0x1eb790 vmov s3, r3 */
/* @0x1eb794 vstr s30, [sp, #288] */
/* @0x1eb798 vcvt.f32.s32 s12, s2 */
/* @0x1eb79c vstr s30, [sp, #284] */
/* @0x1eb7a0 vstr s30, [sp, #276] */
/* @0x1eb7a4 vstr s30, [sp, #272] */
/* @0x1eb7a8 vstr s30, [sp, #268] */
/* @0x1eb7ac vstr s30, [sp, #264] */
/* @0x1eb7b0 vstr s30, [sp, #256] */
/* @0x1eb7b4 vstr s30, [sp, #252] */
/* @0x1eb7b8 vstr s30, [sp, #248] */
/* @0x1eb7bc vstr s30, [sp, #244] */
/* @0x1eb7c0 vcvt.f32.s32 s13, s3 */
/* @0x1eb7c4 vdiv.f32 s14, s12, s14 */
/* @0x1eb7c8 vdiv.f32 s15, s13, s15 */
/* @0x1eb7cc vstr s14, [sp, #240] */
/* @0x1eb7d0 vstr s15, [sp, #260] */

/* ── 位图：三次 Multiply + 采样器（固定 1）───────────────────────────────────────
 *   SetSamplerState(rsm, 0, 2, 1) 与 (0, 3, 1)（r2 的第一次取值 = r7 = 类型号 2）；
 *   1eb828 b 1eae00 汇入公共颜色/四边形段。
 */

/* @0x1eb7d4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7d8 mov r2, r4 */
/* @0x1eb7dc mov r0, r5 */
/* @0x1eb7e0 ldr r1, [sp, #0x2a4] */
/* @0x1eb7e4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7e8 mov r2, r5 */
/* @0x1eb7ec add r1, r6, #12 */
/* @0x1eb7f0 add r0, sp, #176 */
/* @0x1eb7f4 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb7f8 ldr r0, [pc, #0x28c] */
/* @0x1eb7fc mov r2, r7 */
/* @0x1eb800 mov r1, #0 */
/* @0x1eb804 mov r3, #1 */
/* @0x1eb808 ldr r5, [r10, r0] */
/* @0x1eb80c mov r0, r5 */
/* @0x1eb810 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb814 mov r0, r5 */
/* @0x1eb818 mov r1, #0 */
/* @0x1eb81c mov r2, #3 */
/* @0x1eb820 mov r3, #1 */
/* @0x1eb824 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb828 b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */

/* ── 渐变底是位图（记录->+0x10 >= 0）：再查一次纹理 + 拼两组 diag ────────────────────
 *   bmp = this->+0x54[ 记录->+0x10 ]；GR_Texture_Exists((int16)bmp->+20) == 0 → 1eba60。
 *   用 bmp 的 6 个 int16（+0/+2/+4/+6 与 +16/+18）与纹理宽高拼两组 diag（先乘后除）：
 *   M2(sp+368) = diag( x0/w , y0/h ,1,1 )，M1(sp+304) = diag( (x1-1)/w·? , … )（见逐条锚点）。
 */

/* @0x1eb82c ldr r3, [r8, #0x54] */
/* @0x1eb830 ldr r4, [r3, r2, lsl #2] */
/* @0x1eb834 ldrsh r0, [r4, #20] */
/* @0x1eb838 bl 0x173e2c <_Z17GR_Texture_Existsi> */
/* @0x1eb83c cmp r0, #0 */
/* @0x1eb840 beq 0x1eba60 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e50> */
/* @0x1eb844 ldrsh r12, [r4, #6] */
/* @0x1eb848 vmov.f32 s15, #1.000000e+00 */
/* @0x1eb84c ldrsh lr, [r4, #18] */
/* @0x1eb850 add r5, sp, #432 */
/* @0x1eb854 ldrsh r10, [r4, #4] */
/* @0x1eb858 ldrsh r11, [r4, #16] */
/* @0x1eb85c vmov s8, r12 */
/* @0x1eb860 vmov s14, lr */
/* @0x1eb864 ldr r8, [sp, #0x44] */
/* @0x1eb868 vmov s7, r10 */
/* @0x1eb86c ldr r3, [pc, #0x214] */
/* @0x1eb870 vmov s13, r11 */
/* @0x1eb874 ldrsh r2, [r4, #20] */
/* @0x1eb878 ldrsh r9, [r4] */
/* @0x1eb87c mov r0, r5 */
/* @0x1eb880 ldr r3, [r8, r3] */
/* @0x1eb884 ldrsh r4, [r4, #2] */
/* @0x1eb888 vcvt.f32.s32 s7, s7 */
/* @0x1eb88c ldr r3, [r3, #0x4] */
/* @0x1eb890 vmov s10, r9 */
/* @0x1eb894 vmov s12, r4 */
/* @0x1eb898 add r4, sp, #368 */
/* @0x1eb89c ldr r3, [r3, r2, lsl #2] */
/* @0x1eb8a0 mov r1, r4 */
/* @0x1eb8a4 add r2, sp, #304 */
/* @0x1eb8a8 vcvt.f32.s32 s8, s8 */
/* @0x1eb8ac ldr r3, [r3] */
/* @0x1eb8b0 vldr s11, [r3, #4] */
/* @0x1eb8b4 vldr s9, [r3, #8] */
/* @0x1eb8b8 vstr s15, [sp, #428] */
/* @0x1eb8bc vstr s15, [sp, #408] */
/* @0x1eb8c0 vstr s15, [sp, #388] */
/* @0x1eb8c4 vstr s15, [sp, #368] */
/* @0x1eb8c8 vstr s15, [sp, #364] */
/* @0x1eb8cc vstr s15, [sp, #344] */
/* @0x1eb8d0 str r3, [sp, #0x90] */
/* @0x1eb8d4 vstr s30, [sp, #412] */
/* @0x1eb8d8 vstr s30, [sp, #404] */
/* @0x1eb8dc vstr s30, [sp, #400] */
/* @0x1eb8e0 vcvt.f32.s32 s13, s13 */
/* @0x1eb8e4 vstr s30, [sp, #396] */
/* @0x1eb8e8 vstr s30, [sp, #392] */
/* @0x1eb8ec vstr s30, [sp, #384] */
/* @0x1eb8f0 vstr s30, [sp, #380] */
/* @0x1eb8f4 vstr s30, [sp, #376] */
/* @0x1eb8f8 vstr s30, [sp, #372] */
/* @0x1eb8fc vstr s30, [sp, #424] */
/* @0x1eb900 vstr s30, [sp, #360] */
/* @0x1eb904 vstr s30, [sp, #356] */
/* @0x1eb908 vcvt.f32.s32 s14, s14 */
/* @0x1eb90c vdiv.f32 s13, s7, s13 */
/* @0x1eb910 vdiv.f32 s14, s8, s14 */
/* @0x1eb914 vcvt.f32.s32 s9, s9 */
/* @0x1eb918 vcvt.f32.s32 s11, s11 */
/* @0x1eb91c vdiv.f32 s11, s15, s11 */
/* @0x1eb920 vdiv.f32 s15, s15, s9 */
/* @0x1eb924 vcvt.f32.s32 s10, s10 */
/* @0x1eb928 vcvt.f32.s32 s12, s12 */
/* @0x1eb92c vdiv.f32 s10, s10, s13 */
/* @0x1eb930 vdiv.f32 s12, s12, s14 */
/* @0x1eb934 vstr s10, [sp, #416] */
/* @0x1eb938 vstr s30, [sp, #352] */
/* @0x1eb93c vstr s30, [sp, #348] */
/* @0x1eb940 vstr s30, [sp, #340] */
/* @0x1eb944 vstr s30, [sp, #336] */
/* @0x1eb948 vstr s30, [sp, #332] */
/* @0x1eb94c vstr s30, [sp, #328] */
/* @0x1eb950 vstr s30, [sp, #320] */
/* @0x1eb954 vstr s30, [sp, #316] */
/* @0x1eb958 vstr s30, [sp, #312] */
/* @0x1eb95c vstr s30, [sp, #308] */
/* @0x1eb960 vmul.f32 s13, s11, s13 */
/* @0x1eb964 vstr s12, [sp, #420] */
/* @0x1eb968 vmul.f32 s14, s15, s14 */
/* @0x1eb96c vstr s13, [sp, #304] */
/* @0x1eb970 vstr s14, [sp, #324] */

/* ── 渐变底是位图：Multiply(sp+432, M2, M1) 后 Multiply(sp+176, 记录矩阵, sp+432) ───
 *   采样器再写一次 (0, r7=3, 1) 与 (0, 3, 1)（r7 = 类型号 3），然后 b 1eade4 汇入
 *   同一条 SetSamplerState 尾巴。
 */

/* @0x1eb974 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb978 add r0, sp, #176 */
/* @0x1eb97c add r1, r6, #16 */
/* @0x1eb980 mov r2, r5 */
/* @0x1eb984 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb988 ldr r6, [r6, #0x4] */
/* @0x1eb98c ldr r0, [pc, #0xf8] */
/* @0x1eb990 bics r6, r6, #2 */
/* @0x1eb994 bne 0x1eba40 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e30> */
/* @0x1eb998 mov r1, r6 */
/* @0x1eb99c mov r2, #2 */
/* @0x1eb9a0 mov r3, r6 */
/* @0x1eb9a4 ldr r5, [r8, r0] */
/* @0x1eb9a8 b 0x1eade4 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11d4> */

/* ── 渐变记录 +0x0c 为空的旁路 ───────────────────────────────────────────────────
 *   1eb9ac：Multiply(sp+176, 记录+0x0c, p6)；[sp+0x90] = 记录->+0x58；
 *   写采样器 (0,2,3)/(0,3,1)；rec6 == 0 → 1e9f08（不画填充），否则 1eae00。
 */

/* @0x1eb9ac add r1, r6, #12 */
/* @0x1eb9b0 ldr r6, [r6, #0x58] */
/* @0x1eb9b4 add r0, sp, #176 */
/* @0x1eb9b8 ldr r2, [sp, #0x2a4] */
/* @0x1eb9bc str r6, [sp, #0x90] */
/* @0x1eb9c0 bl 0x27aa00 <_ZN8yyMatrix8MultiplyEPS_S0_S0_> */
/* @0x1eb9c4 ldr r0, [pc, #0xc0] */
/* @0x1eb9c8 mov r2, r7 */
/* @0x1eb9cc ldr r5, [sp, #0x44] */
/* @0x1eb9d0 mov r1, #0 */
/* @0x1eb9d4 mov r3, #1 */
/* @0x1eb9d8 ldr r4, [r5, r0] */
/* @0x1eb9dc mov r0, r4 */
/* @0x1eb9e0 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb9e4 mov r0, r4 */
/* @0x1eb9e8 mov r1, #0 */
/* @0x1eb9ec mov r2, #3 */
/* @0x1eb9f0 mov r3, #1 */
/* @0x1eb9f4 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eb9f8 cmp r6, #0 */
/* @0x1eb9fc beq 0x1e9f08 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x2f8> */
/* @0x1eba00 add r4, sp, #368 */
/* @0x1eba04 b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */

/* ── 采样器变体 / 循环续跑 / 池字 / 出口 ─────────────────────────────────────────
 *   1eba08：SetSamplerState(0,2,1) 与 (0,3,1)（子对象 +0x04 不是 {0,2} 时走这支）。
 *   1eba40：同一对的另一入口；1eba60/1eba6c：位图路径失败后取 item->+0x1c 续跑外层循环。
 *   1eba58：item->+0x1c == 0 的出口（返回 [sp+0x54] = 0）。
 *   1eba78..1eba8c：第二组池字（与 1ea0e0 段同一批 GOT 偏移，供后半段 PC 相对取用）。
 */

/* @0x1eba08 ldr r6, [sp, #0x44] */
/* @0x1eba0c add r4, sp, #368 */
/* @0x1eba10 mov r1, #0 */
/* @0x1eba14 mov r2, #2 */
/* @0x1eba18 mov r3, #1 */
/* @0x1eba1c ldr r5, [r6, r0] */
/* @0x1eba20 mov r0, r5 */
/* @0x1eba24 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eba28 mov r0, r5 */
/* @0x1eba2c mov r2, r7 */
/* @0x1eba30 mov r1, #0 */
/* @0x1eba34 mov r3, #1 */
/* @0x1eba38 bl 0x167ef4 <_ZN18RenderStateManager15SetSamplerStateEi13eSamplerStatej> */
/* @0x1eba3c b 0x1eae00 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x11f0> */
/* @0x1eba40 ldr r10, [sp, #0x44] */
/* @0x1eba44 mov r1, #0 */
/* @0x1eba48 mov r2, #2 */
/* @0x1eba4c mov r3, #1 */
/* @0x1eba50 ldr r5, [r10, r0] */
/* @0x1eba54 b 0x1eba20 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x1e10> */
/* @0x1eba58 str r3, [sp, #0x54] */
/* @0x1eba5c b 0x1e9cec <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0xdc> */
/* @0x1eba60 ldr r9, [sp, #0xa0] */
/* @0x1eba64 ldr r3, [r9, #0x1c] */
/* @0x1eba68 b 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1eba6c ldr r6, [sp, #0xa0] */
/* @0x1eba70 ldr r3, [r6, #0x1c] */
/* @0x1eba74 b 0x1ea428 <_ZN7CSprite18DrawDictionaryItemEP18SWF_DictionaryItem8yyMatrixfbbPS2_PjS4_PiS5_S5_P7Textureff+0x818> */
/* @0x1eba78 .word 0xfffff190 */
/* @0x1eba7c .word 0xffffbcd0 */
/* @0x1eba80 .word 0xffffbac4 */
/* @0x1eba84 .word 0xfffff194 */
/* @0x1eba88 .word 0xffffbccc */
/* @0x1eba8c .word 0xffffc0a8 */

/* ── open ─────────────────────────────────────────────────────────────────────
 *   1. element->+0x08 的颜色表下标 = 上一变换循环的计数（点数）：0x1ea04c 用 r12，
 *      b4=0 时 r12 = 填充点数、b4!=0 时 = AA 点数。二进制确定，语义未钉。
 *   2. AllocVerts 第 2 形参（.dynsym 写作 Pvi）：实参是 Texture*（type 1 用 p12，type 2/3 用
 *      记录里的纹理对象指针）或 0。到底是「纹理键」还是「顶点格式指针」未钉。
 *   3. ePrimType = 4 的枚举名未钉（10 处全同）；只能证到「每单元 6 或 3 个顶点」。
 *   4. GOT 0x3ed71c → .data.rel.ro 0x3eb70c 的单例，vptr 在 .bss（0x47a118）由构造器运行时填，
 *      只能证到 vtable[3](char*) 接收 .rodata 的两条 "SWF subshape has too many …" 串。
 *   5. 1eb82c.. 的「渐变底是位图」路径：两组 diag 用 bmp 的 6 个 int16 与 (w,h) 先乘后除，
 *      具体取整/减 1 的次序只到块级，未逐式定名。
 *   6. 84 B 记录里 +0x28（子对象下标）与 +0x2c（>=0 闸）的语义未钉：+0x2c 只用来判非负。
 *   7. 顶点 24 B 里的 z 与 16 B 里的 z 同源（*GOT 0x3ed928 = .bss 0x4859ac 的 float），
 *      该全局由谁写未钉（DrawShape 卡同样记 open）。
 *
 * ── 引用面（本轮只读，未改任何其它文件）────────────────────────────────────────
 *   asm/index-CSprite_DrawDictionaryItem.tsv（1952 行，唯一锚点来源）
 *   cards/CSprite_DrawShape.c（调用侧实参块 1edc50 起、矩阵/状态对照）
 *   cards/CSprite_Draw.c（纹理档差异对照）  cards/auto/bank_0166.c:1934（签名/尺寸）
 *   libyoyo.so（cally-oracle 副本）：.dynsym g_SWFvertbuff/g_SWFaavertbuff/g_SWFlinevertbuff/
 *     g_SWFlineaavertbuff/g_SWF_AA 的地址与尺寸；.got 槽值 0x3f0de0..0x3f0dec、
 *     0x3ed924/0x3ed928/0x3edd00/0x3ed71c；.rodata 0x3525fc/0x352620 两条告警串
 *   scripts/check_card_anchors.py（RESULT EXACT 判定器）
 */
