/* cally 逆向卡：CRoom::Serialise（原版 libyoyo.so，armv7）
 * @func 0x1aa228 0x1aad50  size 2856  714 条（0x1aa228..0x1aad48 共 713 条指令；0x1aad4c 是 1 个池字，
 *       objdump 按 ldrheq 译码，实际是 0x001a24bc 的加数）
 * 级别: 正文（12 段流序、段内 55 个写点与 2 个 Write(const char*)、三个类型码、四条链/表的遍历方向、
 *             物理房间的错误出口 全部逐条落锚，并与 CRoom::DeSerialise 0x1ac33c 按「段—字段—类型码」
 *             逐项对齐；未钉：CRoom+0x6c/+0x74/+0x78/+0x7c 的语义（本函数一律不读）、+0x70 物理标志的
 *             上游写入者、背景 13 字段与视野 7 个 int 的名字、Error_Show 的调用方与写失败时的流状态）
 * 符号: _ZN5CRoom9SerialiseEP7IBuffer → void CRoom::Serialise(IBuffer* buf)
 * ABI : softfp（float/double 走核心寄存器；本函数无返回值、无栈帧外参数）
 * 同层: CRoom::DeSerialise 0x1ac33c（严格互逆）、CRoom::AddTile 0x1ac240（56 B 表唯一写入口）、
 *       CRoom::ClearTiles 0x1ad060（+0xb8/+0xbc/+0xc0 的另一处写者）、CLayer::Serialize 0x1a9428、
 *       CInstance::Serialise 0x196bf4、IBuffer::Write(const char*) 0xcddb8、Error_Show 0xecd7c、
 *       CRoom::LoadFromChunk 0x1aed3c（+0x70 的写入者之一）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把一间房按固定次序摊成一条流：名字 → 6 个标量 → 第二串 → 8 个背景记录（13 字段）→ 1 个字节
 *   → 8 个视野记录（17 字段）→ tile 表（计数 + n×14 字段）→ 层表（计数 + 沿链逐层）→
 *   活动实例（计数 + 沿 prev 反向走）→ 非活动实例（同法）。没有版本号、没有长度前缀、没有段标记，
 *   次序即格式。写之前若 +0x70（带物理）非 0，先喊一句错误串，然后**照写不误**。
 *
 * ── 帧 ────────────────────────────────────────────────────────
 *   push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}：10 个寄存器、无 sub sp（本函数不需要栈上暂存，
 *   唯一的缓冲是 IBuffer 内嵌的 16 B RValue 槽）。
 *   r9 = this(CRoom*)、r6 = buf(IBuffer*)、r7 = buf+0x2c（RValue 的数据槽）、
 *   r5 = 0（写 tag 用的零）、r8 = 0（后段当零/回填用）、r10 = 0（背景循环计数）、
 *   r11 = this（背景段的指针数组游标；进视野段时被改成 0 当计数，进 tile 段又当临时量）。
 *
 * ── 写协议（与 DeSerialise 的读协议同一块暂存区）──────────────────
 *   调用形状固定：r0 = buf、r1 = 类型码、r2 = buf+0x2c、blx [buf->vt+0x8]（写）；
 *   数据先落到 buf+0x2c..0x33（8 字节，按 double 存），tag 在 buf+0x38 恒置 0。
 *   类型码实见三种：6 = int（byte/bool 也走它，写出 0/1）、5 = uint32（只有 +0x1c）、8 = float/real。
 *   与 DeSerialise 侧「6/5/8」三种读码完全一致。
 *   字符串不走虚表：直调 IBuffer::Write(const char*) 0xcddb8（两处：0x1aa248、0x1aa37c）。
 *   整数写出的两种等价记账（softfp 下 d7 = s14:s15、d6 = s12:s13）：
 *     vcvt.f64.s32 d7,s14 → vstr s14,[r6,#44] + vstr s15,[r6,#48]
 *     vcvt.f64.u32 d6,s13 → vmov r4,r5,d6 → vstr s12,[r6,#44] + str r5,[r6,#0x30]
 *   两者都是「低字进 +0x2c、高字进 +0x30」，读卡时别把 vstr s12 看成别的值。
 *
 * ── 55 个写点（静态计数，与 DeSerialise 的 55 个读点一一对应）──────
 *   全函数 blx 55 条 = 55 个写点（37 条走 r12、18 条走 r3），静态分布：
 *     6（头标量）+ 13（背景循环体）+ 1（+0x44）+ 17（视野循环体）+ 14（tile 循环体）
 *     + 4（tile / 层 / A / B 四个计数）= 55
 *   DeSerialise 全函数也是 55 个 blx 读点，同样 6+13+1+17+14+4 —— 这是「逐段互逆」最硬的计数证据。
 *
 * ── 流序总表（左 = 本函数写出，右 = DeSerialise 读入；类型码逐项相同）──
 *   Write(const char*)  ← CRoom+0x08            ↔ ReadString()                → +0x08
 *   int   t6            ← CRoom+0x10            ↔ int                         → +0x10
 *   int   t6            ← CRoom+0x14            ↔ int                         → +0x14
 *   int   t6            ← CRoom+0x0c            ↔ int                         → +0x0c
 *   int   t6 (byte)     ← CRoom+0x18            ↔ YYGetBool                    → +0x18
 *   u32   t5            ← CRoom+0x1c            ↔ YYGetUint32                  → +0x1c
 *   int   t6 (byte)     ← CRoom+0x20            ↔ YYGetBool                    → +0x20
 *   Write(const char*)  ← CRoom+0x68            ↔ ReadString()                → +0x68
 *   8 × 13 字段         ← *(CRoom+0x24+i*4)     ↔ 8 × 13 字段                  → *(CRoom+0x24+i*4)
 *   int   t6 (byte)     ← CRoom+0x44            ↔ YYGetBool                    → +0x44
 *   8 × 17 字段         ← *(CRoom+0x48+i*4)     ↔ 8 × 17 字段                  → *(CRoom+0x48+i*4)
 *   int   t6            ← CRoom+0xb8（计数）    ↔ int n → ReAlloc(n*56)+AddTile
 *   n × 14 字段         ← *(CRoom+0xc0+k*56)    ↔ n × 14 字段                  → 栈上记录
 *   int   t6            ← CRoom+0xdc（计数）    ↔ int n → DeSerializeLayer × n
 *   链：+0xd4 沿 +0x68  ← CLayer               ↔ 委派（按 CLayer+0x04 升序插回，见下）
 *   int   t6            ← CRoom+0x88（计数）    ↔ int n
 *   链：+0x80 沿 +0x178 ← CInstance            ↔ n × (new + DeSerialise + 深度降序插入)
 *   int   t6            ← CRoom+0x94（计数）    ↔ int n
 *   链：+0x8c 沿 +0x178 ← CInstance            ↔ n × (new + DeSerialise + 头插)
 *
 * ── 严格互逆？逐段说清楚 ────────────────────────────────────────
 *   1. 段结构、段内字段次序、每个字段的类型码：**严格互逆**（上表逐项对齐，55:55 计数相同）。
 *   2. 四条遍历方向都是「为了让对端能重建同一条链」而选的，且四条都对：
 *      · 层：从链头 +0xd4 沿 next(+0x68) 正序写出。链本身是 CLayer+0x04 升序（插入点由
 *        InsertLayerIntoActiveList 0x1c3110..0x1c3148 决定：走到第一个 +0x04 大于新层的现有层
 *        之前插入，一路不遇到就接尾）⇒ 正序写出即按该键升序；对端用同一函数按同键插回，
 *        等键稳定 ⇒ 顺序不变。
 *      · 活动实例 A：从**尾** +0x80 沿 prev(+0x178) 逆序写出（即 depth 升序）；
 *        对端「插到第一个 key <= new 之前」= 降序插入 ⇒ 精确还原，equal-key 也稳定
 *        （链上 x 在 y 前且等值时，写出序是 y,x；读回时先插 y 再插 x，x 落回 y 之前）。
 *        ★ key 不对称：链上存的是**插入时的快照** +0x184，而比较时对新实例取的是**实时** +0x180。
 *          若某实例的 depth 在插入之后被改过，链序与实时 depth 就已不一致；存读一轮会按实时
 *          depth 重排 ⇒ 那种状态下「往返」是重排而非纯拷贝（open）。
 *      · 非活动实例 B：从尾 +0x8c 沿 prev 逆序写出 = 原始插入序；对端头插 ⇒ 精确还原。
 *      · tile 表：正序 0..n-1 ⇒ 对端逐条 AddTile 追加，下标一致。
 *   3. 但**不是对象级互逆**，有四处确定的偏差：
 *      (a) 视野 +0x04/+0x08/+0x0c/+0x10 在内存里是 float、流里是 int：本函数 vcvt.s32.f32
 *          **截断取整**，对端 vcvt.f32.s32 还原 ⇒ 小数部分丢失。数据通常整数值（room chunk 的
 *          视野矩形就是 int）所以运行期看不出，但只要有人把 +0x04 设成 0.5，存读一轮就变 0。
 *      (b) tile 容量不往返：本函数只写计数 +0xb8，不写容量 +0xbc；对端把 +0xbc 置成 n 且不清 +0xb8
 *          ⇒ 往返后 cap == count，原先扩容过的容量丢失。
 *      (c) CRoom+0x00（最后一条 tile 下标）不写：对端由 AddTile 逐条推进，清表时 ClearTiles 置 -1。
 *      (d) 一堆字段根本不在流里：+0x00、+0x04、+0x45、+0x46、+0x6c、+0x70、+0x74、+0x78、+0x7c、
 *          +0xa4、+0xa8、+0xac、+0xb0、+0xb4（物理世界）、+0xbc、+0xc4、+0xc8、+0xcc、+0xd0、
 *          +0xd4、+0xd8、+0xf4、+0x108、+0x120。⇒ 存读只保「几何 + 层 + 两条实例链」，
 *          物理与五格房间附加字段靠 CRoom::Assign 那条路复制（见 Assign 卡）。
 *   4. 带物理的房间：+0x70 != 0 时只喊串、不 abort，也不把物理世界写进流 ⇒ 存读会静默丢物理。
 *
 * ── 未定（open）────────────────────────────────────────────────
 *   1. CRoom+0x6c/+0x74/+0x78/+0x7c 的语义（本函数不读，故连类型都只从 Assign 的搬运宽度推）
 *   2. CRoom+0x70 的置位者：已见 LoadFromChunk 0x1aecf8 / 0x1aed3c 从 chunk 两处来源写它；
 *      Clear/C2 置 0；DeSerialise 不写 ⇒ 存读后物理标志归 0，谁负责补回未证
 *   3. 背景 13 字段 / 视野 +0x14..+0x20 与 +0x28..+0x40 的名字（偏移、类型、流序全证，名字未证）
 *   4. Error_Show(str, 1) 之后无条件回主线（0x1aad48 b 0x1aa240）：是否有调用方依赖这条串做分流，未证
 *   5. IBuffer::Write 是否可能失败（返回值被完全忽略：55 个写点没有一个看 r0）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 入口：r9 = this、r6 = buf；先查「带物理」门 ───────────────────
 *   ldrb r3,[r0,#0x70] → 非 0 就跳 0x1aad38 喊串，然后 b 0x1aa240 回主线（不 abort、不改流）。
 *   与 CRoom::LoadFromChunk 对上：+0x70 是 chunk 里的物理开关；DeSerialise 完全不写它。
 */

/* @0x1aa228 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aa22c mov r9, r0 */
/* @0x1aa230 ldrb r3, [r0, #0x70] */
/* @0x1aa234 mov r6, r1 */
/* @0x1aa238 cmp r3, #0 */
/* @0x1aa23c bne 0x1aad38 <_ZN5CRoom9SerialiseEP7IBuffer+0xb10> */
/* ── 第 1 段：房间名 → Write(const char*)（不走虚表）───────────────
 *   ldr r1,[r9,#8] + bl IBuffer::Write(const char*) 0xcddb8。
 *   对端是 IBuffer::ReadString() 0xcde74。空指针（新房间 +0x08 == 0）时 Write 收到 0，行为未证（open）。
 */

/* @0x1aa240 ldr r1, [r9, #0x8] */
/* @0x1aa244 mov r0, r6 */
/* @0x1aa248 bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* ── 第 2~7 段：六个标量，落位序 +0x10, +0x14, +0xc, +0x18, +0x1c, +0x20 ──
 *   本段同时初始化三个「零」寄存器与暂存槽指针，后面全函数复用：
 *     r7 = buf+0x2c（RValue 数据槽）、r5 = 0（tag）、r10/r8 = 0、r11 = this（背景游标）
 *   ★ +0x10/+0x14/+0xc 用 vldr s12/s14,[r9,#16/20/12] 再 vcvt.f64.s32。vldr 只是把这 32 位
 *     搬进 VFP 寄存器（按位搬，不解释类型），类型由紧随的 vcvt 定：vcvt.f64.**s32** ⇒ 这三个
 *     字段在内存里是 int（与 +0x1c 的 vcvt.f64.u32 对照，一个带符号一个无符号）。
 *   ★ +0x18/+0x20 是字节：ldrb → vmov s14,rN → vcvt.f64.u32 → 类型码仍是 6。
 *     流里没有独立 bool 类型，读端 YYGetBool 负责归一到 0/1。
 *   ★ +0x1c 是唯一用类型码 5（uint32）的字段；+0x18 与 +0x1c 都走 vcvt.f64.u32（无符号），
 *     差别只在类型码 6 / 5 —— 所以「bool 走 6、uint32 走 5」这条不是靠 vcvt 分的，是靠码分的。
 */

/* @0x1aa24c vldr s12, [r9, #16] */
/* @0x1aa250 vcvt.f64.s32 d7, s12 */
/* @0x1aa254 ldr r12, [r6] */
/* @0x1aa258 add r7, r6, #44 */
/* @0x1aa25c mov r5, #0 */
/* @0x1aa260 mov r1, #6 */
/* @0x1aa264 str r5, [r6, #0x38] */
/* @0x1aa268 mov r2, r7 */
/* @0x1aa26c mov r0, r6 */
/* @0x1aa270 mov r10, r5 */
/* @0x1aa274 mov r8, r5 */
/* @0x1aa278 mov r11, r9 */
/* @0x1aa27c vstr s14, [r6, #44] */
/* @0x1aa280 vstr s15, [r6, #48] */
/* @0x1aa284 ldr r12, [r12, #0x8] */
/* @0x1aa288 blx r12 */
/* @0x1aa28c vldr s14, [r9, #20] */
/* @0x1aa290 vcvt.f64.s32 d7, s14 */
/* @0x1aa294 ldr r12, [r6] */
/* @0x1aa298 mov r2, r7 */
/* @0x1aa29c str r5, [r6, #0x38] */
/* @0x1aa2a0 mov r1, #6 */
/* @0x1aa2a4 mov r0, r6 */
/* @0x1aa2a8 vstr s14, [r6, #44] */
/* @0x1aa2ac vstr s15, [r6, #48] */
/* @0x1aa2b0 ldr r12, [r12, #0x8] */
/* @0x1aa2b4 blx r12 */
/* @0x1aa2b8 vldr s14, [r9, #12] */
/* @0x1aa2bc vcvt.f64.s32 d7, s14 */
/* @0x1aa2c0 ldr r12, [r6] */
/* @0x1aa2c4 mov r2, r7 */
/* @0x1aa2c8 str r5, [r6, #0x38] */
/* @0x1aa2cc mov r1, #6 */
/* @0x1aa2d0 mov r0, r6 */
/* @0x1aa2d4 vstr s14, [r6, #44] */
/* @0x1aa2d8 vstr s15, [r6, #48] */
/* @0x1aa2dc ldr r12, [r12, #0x8] */
/* @0x1aa2e0 blx r12 */
/* @0x1aa2e4 ldrb r2, [r9, #0x18] */
/* @0x1aa2e8 ldr r12, [r6] */
/* @0x1aa2ec mov r1, #6 */
/* @0x1aa2f0 str r5, [r6, #0x38] */
/* @0x1aa2f4 mov r0, r6 */
/* @0x1aa2f8 vmov s14, r2 */
/* @0x1aa2fc mov r2, r7 */
/* @0x1aa300 vcvt.f64.u32 d7, s14 */
/* @0x1aa304 vstr s14, [r6, #44] */
/* @0x1aa308 vstr s15, [r6, #48] */
/* @0x1aa30c ldr r12, [r12, #0x8] */
/* @0x1aa310 blx r12 */
/* @0x1aa314 vldr s14, [r9, #28] */
/* @0x1aa318 vcvt.f64.u32 d7, s14 */
/* @0x1aa31c ldr r12, [r6] */
/* @0x1aa320 mov r2, r7 */
/* @0x1aa324 str r5, [r6, #0x38] */
/* @0x1aa328 mov r1, #5 */
/* @0x1aa32c mov r0, r6 */
/* @0x1aa330 vstr s14, [r6, #44] */
/* @0x1aa334 vstr s15, [r6, #48] */
/* @0x1aa338 ldr r12, [r12, #0x8] */
/* @0x1aa33c blx r12 */
/* @0x1aa340 ldrb r4, [r9, #0x20] */
/* @0x1aa344 str r5, [r6, #0x38] */
/* @0x1aa348 mov r1, #6 */
/* @0x1aa34c ldr r12, [r6] */
/* @0x1aa350 mov r2, r7 */
/* @0x1aa354 vmov s13, r4 */
/* @0x1aa358 mov r0, r6 */
/* @0x1aa35c vcvt.f64.u32 d6, s13 */
/* @0x1aa360 vmov r4, r5, d6 */
/* @0x1aa364 vstr s12, [r6, #44] */
/* @0x1aa368 str r5, [r6, #0x30] */
/* @0x1aa36c ldr r12, [r12, #0x8] */
/* @0x1aa370 blx r12 */
/* ── 第 8 段：第二串 → CRoom+0x68（房间的 code 串那一格）────────────
 *   与第 1 段同一条重载；对端 ReadString 后 str 到 +0x68。
 */

/* @0x1aa374 mov r0, r6 */
/* @0x1aa378 ldr r1, [r9, #0x68] */
/* @0x1aa37c bl 0xcddb8 <_ZN7IBuffer5WriteEPKc> */
/* ── 第 9 段：8 个背景记录，每个 13 字段（记录 44 B，指针在 +0x24+i*4）──
 *   循环：r4 = *(r11)，r11 += 4，r10 计数到 8（0x1aa5dc cmp r10,#8）。
 *   字段次序与类型码（与 DeSerialise 的 13 个读点逐项同序同型）：
 *     +0x00 byte t6   +0x01 byte t6   +0x04 int t6    +0x08 float t8  +0x0c float t8
 *     +0x10 byte t6   +0x11 byte t6   +0x14 float t8  +0x18 float t8  +0x1c float t8
 *     +0x20 float t8  +0x24 int t6    +0x28 float t8
 *   ★ +0x04 走 vcvt.f64.s32（按 int 取），+0x08/+0x0c/+0x14/+0x18/+0x1c/+0x20/+0x28 走
 *     vcvt.f64.f32（按 float 取）—— 同一段里两种取法，读卡时按 vcvt 的源类型分，别按 ldr/vldr 分。
 *   名字按 GM 房间背景序推断（visible/foreground/背景号/x/y/htiled/vtiled/xscale/yscale/
 *   hspeed/vspeed/blend/alpha），未证（open 3）。
 */

/* @0x1aa380 ldr r4, [r11, #0x24] */
/* @0x1aa384 mov r1, #6 */
/* @0x1aa388 ldr r12, [r6] */
/* @0x1aa38c mov r0, r6 */
/* @0x1aa390 add r10, r10, #1 */
/* @0x1aa394 add r11, r11, #4 */
/* @0x1aa398 ldrb r2, [r4] */
/* @0x1aa39c str r8, [r6, #0x38] */
/* @0x1aa3a0 vmov s14, r2 */
/* @0x1aa3a4 mov r2, r7 */
/* @0x1aa3a8 vcvt.f64.u32 d7, s14 */
/* @0x1aa3ac vstr s14, [r6, #44] */
/* @0x1aa3b0 vstr s15, [r6, #48] */
/* @0x1aa3b4 ldr r12, [r12, #0x8] */
/* @0x1aa3b8 blx r12 */
/* @0x1aa3bc ldrb r3, [r4, #0x1] */
/* @0x1aa3c0 ldr r12, [r6] */
/* @0x1aa3c4 mov r1, #6 */
/* @0x1aa3c8 mov r2, r7 */
/* @0x1aa3cc mov r0, r6 */
/* @0x1aa3d0 vmov s14, r3 */
/* @0x1aa3d4 str r8, [r6, #0x38] */
/* @0x1aa3d8 vcvt.f64.u32 d7, s14 */
/* @0x1aa3dc vstr s14, [r6, #44] */
/* @0x1aa3e0 vstr s15, [r6, #48] */
/* @0x1aa3e4 ldr r12, [r12, #0x8] */
/* @0x1aa3e8 blx r12 */
/* @0x1aa3ec vldr s14, [r4, #4] */
/* @0x1aa3f0 vcvt.f64.s32 d7, s14 */
/* @0x1aa3f4 ldr r12, [r6] */
/* @0x1aa3f8 mov r1, #6 */
/* @0x1aa3fc mov r2, r7 */
/* @0x1aa400 mov r0, r6 */
/* @0x1aa404 str r8, [r6, #0x38] */
/* @0x1aa408 vstr s14, [r6, #44] */
/* @0x1aa40c vstr s15, [r6, #48] */
/* @0x1aa410 ldr r12, [r12, #0x8] */
/* @0x1aa414 blx r12 */
/* @0x1aa418 vldr s14, [r4, #8] */
/* @0x1aa41c vcvt.f64.f32 d7, s14 */
/* @0x1aa420 ldr r12, [r6] */
/* @0x1aa424 mov r1, #8 */
/* @0x1aa428 mov r2, r7 */
/* @0x1aa42c str r8, [r6, #0x38] */
/* @0x1aa430 mov r0, r6 */
/* @0x1aa434 vstr s14, [r6, #44] */
/* @0x1aa438 vstr s15, [r6, #48] */
/* @0x1aa43c ldr r12, [r12, #0x8] */
/* @0x1aa440 blx r12 */
/* @0x1aa444 vldr s14, [r4, #12] */
/* @0x1aa448 vcvt.f64.f32 d7, s14 */
/* @0x1aa44c ldr r12, [r6] */
/* @0x1aa450 mov r1, #8 */
/* @0x1aa454 mov r2, r7 */
/* @0x1aa458 str r8, [r6, #0x38] */
/* @0x1aa45c mov r0, r6 */
/* @0x1aa460 vstr s14, [r6, #44] */
/* @0x1aa464 vstr s15, [r6, #48] */
/* @0x1aa468 ldr r12, [r12, #0x8] */
/* @0x1aa46c blx r12 */
/* @0x1aa470 ldrb r2, [r4, #0x10] */
/* @0x1aa474 ldr r12, [r6] */
/* @0x1aa478 mov r1, #6 */
/* @0x1aa47c mov r0, r6 */
/* @0x1aa480 str r8, [r6, #0x38] */
/* @0x1aa484 vmov s14, r2 */
/* @0x1aa488 mov r2, r7 */
/* @0x1aa48c vcvt.f64.u32 d7, s14 */
/* @0x1aa490 vstr s14, [r6, #44] */
/* @0x1aa494 vstr s15, [r6, #48] */
/* @0x1aa498 ldr r12, [r12, #0x8] */
/* @0x1aa49c blx r12 */
/* @0x1aa4a0 ldrb r3, [r4, #0x11] */
/* @0x1aa4a4 ldr r12, [r6] */
/* @0x1aa4a8 mov r1, #6 */
/* @0x1aa4ac mov r2, r7 */
/* @0x1aa4b0 mov r0, r6 */
/* @0x1aa4b4 vmov s14, r3 */
/* @0x1aa4b8 str r8, [r6, #0x38] */
/* @0x1aa4bc vcvt.f64.u32 d7, s14 */
/* @0x1aa4c0 vstr s14, [r6, #44] */
/* @0x1aa4c4 vstr s15, [r6, #48] */
/* @0x1aa4c8 ldr r12, [r12, #0x8] */
/* @0x1aa4cc blx r12 */
/* @0x1aa4d0 vldr s14, [r4, #20] */
/* @0x1aa4d4 vcvt.f64.f32 d7, s14 */
/* @0x1aa4d8 ldr r12, [r6] */
/* @0x1aa4dc mov r1, #8 */
/* @0x1aa4e0 mov r2, r7 */
/* @0x1aa4e4 str r8, [r6, #0x38] */
/* @0x1aa4e8 mov r0, r6 */
/* @0x1aa4ec vstr s14, [r6, #44] */
/* @0x1aa4f0 vstr s15, [r6, #48] */
/* @0x1aa4f4 ldr r12, [r12, #0x8] */
/* @0x1aa4f8 blx r12 */
/* @0x1aa4fc vldr s14, [r4, #24] */
/* @0x1aa500 vcvt.f64.f32 d7, s14 */
/* @0x1aa504 ldr r12, [r6] */
/* @0x1aa508 mov r1, #8 */
/* @0x1aa50c mov r2, r7 */
/* @0x1aa510 str r8, [r6, #0x38] */
/* @0x1aa514 mov r0, r6 */
/* @0x1aa518 vstr s14, [r6, #44] */
/* @0x1aa51c vstr s15, [r6, #48] */
/* @0x1aa520 ldr r12, [r12, #0x8] */
/* @0x1aa524 blx r12 */
/* @0x1aa528 vldr s14, [r4, #28] */
/* @0x1aa52c vcvt.f64.f32 d7, s14 */
/* @0x1aa530 ldr r12, [r6] */
/* @0x1aa534 mov r1, #8 */
/* @0x1aa538 mov r2, r7 */
/* @0x1aa53c str r8, [r6, #0x38] */
/* @0x1aa540 mov r0, r6 */
/* @0x1aa544 vstr s14, [r6, #44] */
/* @0x1aa548 vstr s15, [r6, #48] */
/* @0x1aa54c ldr r12, [r12, #0x8] */
/* @0x1aa550 blx r12 */
/* @0x1aa554 vldr s14, [r4, #32] */
/* @0x1aa558 vcvt.f64.f32 d7, s14 */
/* @0x1aa55c ldr r12, [r6] */
/* @0x1aa560 mov r1, #8 */
/* @0x1aa564 mov r2, r7 */
/* @0x1aa568 str r8, [r6, #0x38] */
/* @0x1aa56c mov r0, r6 */
/* @0x1aa570 vstr s14, [r6, #44] */
/* @0x1aa574 vstr s15, [r6, #48] */
/* @0x1aa578 ldr r12, [r12, #0x8] */
/* @0x1aa57c blx r12 */
/* @0x1aa580 vldr s14, [r4, #36] */
/* @0x1aa584 vcvt.f64.s32 d7, s14 */
/* @0x1aa588 ldr r12, [r6] */
/* @0x1aa58c mov r1, #6 */
/* @0x1aa590 mov r2, r7 */
/* @0x1aa594 mov r0, r6 */
/* @0x1aa598 str r8, [r6, #0x38] */
/* @0x1aa59c vstr s14, [r6, #44] */
/* @0x1aa5a0 vstr s15, [r6, #48] */
/* @0x1aa5a4 ldr r12, [r12, #0x8] */
/* @0x1aa5a8 blx r12 */
/* @0x1aa5ac vldr s15, [r4, #40] */
/* @0x1aa5b0 vcvt.f64.f32 d6, s15 */
/* @0x1aa5b4 ldr r12, [r6] */
/* @0x1aa5b8 str r8, [r6, #0x38] */
/* @0x1aa5bc mov r0, r6 */
/* @0x1aa5c0 mov r1, #8 */
/* @0x1aa5c4 mov r2, r7 */
/* @0x1aa5c8 vmov r4, r5, d6 */
/* @0x1aa5cc vstr s12, [r6, #44] */
/* @0x1aa5d0 str r5, [r6, #0x30] */
/* @0x1aa5d4 ldr r12, [r12, #0x8] */
/* @0x1aa5d8 blx r12 */
/* @0x1aa5dc cmp r10, #8 */
/* @0x1aa5e0 bne 0x1aa380 <_ZN5CRoom9SerialiseEP7IBuffer+0x158> */
/* ── 第 10 段：房间级字节 CRoom+0x44（位于背景与视野之间）──────────
 *   ldrb → u32 → 类型码 6。GM 房间头这一格通常是 enable-views 类开关，本卡不钉其名。
 *   ★ 注意同族的 +0x45/+0x46 不在流里（Assign 会搬、LoadFromChunk 会写）——流比 chunk 少两格。
 */

/* @0x1aa5e4 ldrb r4, [r9, #0x44] */
/* @0x1aa5e8 mov r2, #0 */
/* @0x1aa5ec ldr r12, [r6] */
/* @0x1aa5f0 mov r11, #0 */
/* @0x1aa5f4 str r2, [r6, #0x38] */
/* @0x1aa5f8 mov r0, r6 */
/* @0x1aa5fc vmov s13, r4 */
/* @0x1aa600 mov r1, #6 */
/* @0x1aa604 mov r2, r7 */
/* @0x1aa608 mov r8, r11 */
/* @0x1aa60c vcvt.f64.u32 d6, s13 */
/* @0x1aa610 mov r10, r9 */
/* @0x1aa614 vmov r4, r5, d6 */
/* @0x1aa618 vstr s12, [r6, #44] */
/* @0x1aa61c str r5, [r6, #0x30] */
/* @0x1aa620 ldr r12, [r12, #0x8] */
/* @0x1aa624 blx r12 */
/* ── 第 11 段：8 个视野记录，每个 17 字段（记录 68 B，指针在 +0x48+i*4）──
 *   循环：r4 = *(r10)，r10 += 4，r11 计数到 8（0x1aa93c）。
 *     +0x00 byte t6
 *     +0x04 float→int t6  ★ vcvt.s32.f32 先取整（对端 vcvt.f32.s32 还原 ⇒ 小数丢失，见头部 3(a)）
 *     +0x08 float→int t6  同上
 *     +0x0c float→int t6  同上
 *     +0x10 float→int t6  同上
 *     +0x14 int t6   +0x18 int t6   +0x1c int t6   +0x20 int t6
 *     +0x24 float t8
 *     +0x28 int t6   +0x2c int t6   +0x30 int t6   +0x34 int t6   +0x38 int t6
 *     +0x3c int t6   +0x40 int t6   ← +0x40 是相机 id（Assign 侧由 CCameraManager::CloneCamera 重给）
 *   ★ 前四个矩形值「浮点存储、整数入流」：Serialize 0x1aa668/0x1aa698/0x1aa6c8/0x1aa6f8 的
 *     vcvt.s32.f32 与 DeSerialise 0x1ac728..0x1ac7bc 的 vcvt.f32.s32 正好对偶。
 *   ★ +0x14..+0x20 与 +0x28..+0x40 全部按 int 取（vcvt.f64.s32 或直接 ldr），与 DeSerialise 的
 *     str 落位一致；Draw_Room 0x1b4298 只喂前五个 float（视口矩形 + 缩放）。
 */

/* @0x1aa628 ldr r4, [r10, #0x48] */
/* @0x1aa62c mov r1, #6 */
/* @0x1aa630 ldr r12, [r6] */
/* @0x1aa634 mov r0, r6 */
/* @0x1aa638 add r11, r11, #1 */
/* @0x1aa63c add r10, r10, #4 */
/* @0x1aa640 ldrb r2, [r4] */
/* @0x1aa644 str r8, [r6, #0x38] */
/* @0x1aa648 vmov s14, r2 */
/* @0x1aa64c mov r2, r7 */
/* @0x1aa650 vcvt.f64.u32 d7, s14 */
/* @0x1aa654 vstr s14, [r6, #44] */
/* @0x1aa658 vstr s15, [r6, #48] */
/* @0x1aa65c ldr r12, [r12, #0x8] */
/* @0x1aa660 blx r12 */
/* @0x1aa664 vldr s14, [r4, #4] */
/* @0x1aa668 vcvt.s32.f32 s14, s14 */
/* @0x1aa66c ldr r12, [r6] */
/* @0x1aa670 mov r1, #6 */
/* @0x1aa674 mov r2, r7 */
/* @0x1aa678 str r8, [r6, #0x38] */
/* @0x1aa67c mov r0, r6 */
/* @0x1aa680 vcvt.f64.s32 d7, s14 */
/* @0x1aa684 vstr s14, [r6, #44] */
/* @0x1aa688 vstr s15, [r6, #48] */
/* @0x1aa68c ldr r12, [r12, #0x8] */
/* @0x1aa690 blx r12 */
/* @0x1aa694 vldr s14, [r4, #8] */
/* @0x1aa698 vcvt.s32.f32 s14, s14 */
/* @0x1aa69c ldr r12, [r6] */
/* @0x1aa6a0 mov r1, #6 */
/* @0x1aa6a4 mov r2, r7 */
/* @0x1aa6a8 str r8, [r6, #0x38] */
/* @0x1aa6ac mov r0, r6 */
/* @0x1aa6b0 vcvt.f64.s32 d7, s14 */
/* @0x1aa6b4 vstr s14, [r6, #44] */
/* @0x1aa6b8 vstr s15, [r6, #48] */
/* @0x1aa6bc ldr r12, [r12, #0x8] */
/* @0x1aa6c0 blx r12 */
/* @0x1aa6c4 vldr s14, [r4, #12] */
/* @0x1aa6c8 vcvt.s32.f32 s14, s14 */
/* @0x1aa6cc ldr r12, [r6] */
/* @0x1aa6d0 mov r1, #6 */
/* @0x1aa6d4 mov r2, r7 */
/* @0x1aa6d8 str r8, [r6, #0x38] */
/* @0x1aa6dc mov r0, r6 */
/* @0x1aa6e0 vcvt.f64.s32 d7, s14 */
/* @0x1aa6e4 vstr s14, [r6, #44] */
/* @0x1aa6e8 vstr s15, [r6, #48] */
/* @0x1aa6ec ldr r12, [r12, #0x8] */
/* @0x1aa6f0 blx r12 */
/* @0x1aa6f4 vldr s14, [r4, #16] */
/* @0x1aa6f8 vcvt.s32.f32 s14, s14 */
/* @0x1aa6fc ldr r12, [r6] */
/* @0x1aa700 mov r1, #6 */
/* @0x1aa704 mov r2, r7 */
/* @0x1aa708 str r8, [r6, #0x38] */
/* @0x1aa70c mov r0, r6 */
/* @0x1aa710 vcvt.f64.s32 d7, s14 */
/* @0x1aa714 vstr s14, [r6, #44] */
/* @0x1aa718 vstr s15, [r6, #48] */
/* @0x1aa71c ldr r12, [r12, #0x8] */
/* @0x1aa720 blx r12 */
/* @0x1aa724 vldr s14, [r4, #20] */
/* @0x1aa728 vcvt.f64.s32 d7, s14 */
/* @0x1aa72c ldr r12, [r6] */
/* @0x1aa730 mov r1, #6 */
/* @0x1aa734 mov r2, r7 */
/* @0x1aa738 mov r0, r6 */
/* @0x1aa73c str r8, [r6, #0x38] */
/* @0x1aa740 vstr s14, [r6, #44] */
/* @0x1aa744 vstr s15, [r6, #48] */
/* @0x1aa748 ldr r12, [r12, #0x8] */
/* @0x1aa74c blx r12 */
/* @0x1aa750 vldr s14, [r4, #24] */
/* @0x1aa754 vcvt.f64.s32 d7, s14 */
/* @0x1aa758 ldr r12, [r6] */
/* @0x1aa75c mov r1, #6 */
/* @0x1aa760 mov r2, r7 */
/* @0x1aa764 mov r0, r6 */
/* @0x1aa768 str r8, [r6, #0x38] */
/* @0x1aa76c vstr s14, [r6, #44] */
/* @0x1aa770 vstr s15, [r6, #48] */
/* @0x1aa774 ldr r12, [r12, #0x8] */
/* @0x1aa778 blx r12 */
/* @0x1aa77c vldr s14, [r4, #28] */
/* @0x1aa780 vcvt.f64.s32 d7, s14 */
/* @0x1aa784 ldr r12, [r6] */
/* @0x1aa788 mov r1, #6 */
/* @0x1aa78c mov r2, r7 */
/* @0x1aa790 mov r0, r6 */
/* @0x1aa794 str r8, [r6, #0x38] */
/* @0x1aa798 vstr s14, [r6, #44] */
/* @0x1aa79c vstr s15, [r6, #48] */
/* @0x1aa7a0 ldr r12, [r12, #0x8] */
/* @0x1aa7a4 blx r12 */
/* @0x1aa7a8 vldr s14, [r4, #32] */
/* @0x1aa7ac vcvt.f64.s32 d7, s14 */
/* @0x1aa7b0 ldr r12, [r6] */
/* @0x1aa7b4 mov r1, #6 */
/* @0x1aa7b8 mov r2, r7 */
/* @0x1aa7bc mov r0, r6 */
/* @0x1aa7c0 str r8, [r6, #0x38] */
/* @0x1aa7c4 vstr s14, [r6, #44] */
/* @0x1aa7c8 vstr s15, [r6, #48] */
/* @0x1aa7cc ldr r12, [r12, #0x8] */
/* @0x1aa7d0 blx r12 */
/* @0x1aa7d4 vldr s14, [r4, #36] */
/* @0x1aa7d8 vcvt.f64.f32 d7, s14 */
/* @0x1aa7dc ldr r12, [r6] */
/* @0x1aa7e0 mov r1, #8 */
/* @0x1aa7e4 mov r2, r7 */
/* @0x1aa7e8 str r8, [r6, #0x38] */
/* @0x1aa7ec mov r0, r6 */
/* @0x1aa7f0 vstr s14, [r6, #44] */
/* @0x1aa7f4 vstr s15, [r6, #48] */
/* @0x1aa7f8 ldr r12, [r12, #0x8] */
/* @0x1aa7fc blx r12 */
/* @0x1aa800 vldr s14, [r4, #40] */
/* @0x1aa804 vcvt.f64.s32 d7, s14 */
/* @0x1aa808 ldr r12, [r6] */
/* @0x1aa80c mov r1, #6 */
/* @0x1aa810 mov r2, r7 */
/* @0x1aa814 mov r0, r6 */
/* @0x1aa818 str r8, [r6, #0x38] */
/* @0x1aa81c vstr s14, [r6, #44] */
/* @0x1aa820 vstr s15, [r6, #48] */
/* @0x1aa824 ldr r12, [r12, #0x8] */
/* @0x1aa828 blx r12 */
/* @0x1aa82c vldr s14, [r4, #44] */
/* @0x1aa830 vcvt.f64.s32 d7, s14 */
/* @0x1aa834 ldr r12, [r6] */
/* @0x1aa838 mov r1, #6 */
/* @0x1aa83c mov r2, r7 */
/* @0x1aa840 mov r0, r6 */
/* @0x1aa844 str r8, [r6, #0x38] */
/* @0x1aa848 vstr s14, [r6, #44] */
/* @0x1aa84c vstr s15, [r6, #48] */
/* @0x1aa850 ldr r12, [r12, #0x8] */
/* @0x1aa854 blx r12 */
/* @0x1aa858 vldr s14, [r4, #48] */
/* @0x1aa85c vcvt.f64.s32 d7, s14 */
/* @0x1aa860 ldr r12, [r6] */
/* @0x1aa864 mov r1, #6 */
/* @0x1aa868 mov r2, r7 */
/* @0x1aa86c mov r0, r6 */
/* @0x1aa870 str r8, [r6, #0x38] */
/* @0x1aa874 vstr s14, [r6, #44] */
/* @0x1aa878 vstr s15, [r6, #48] */
/* @0x1aa87c ldr r12, [r12, #0x8] */
/* @0x1aa880 blx r12 */
/* @0x1aa884 vldr s14, [r4, #52] */
/* @0x1aa888 vcvt.f64.s32 d7, s14 */
/* @0x1aa88c ldr r12, [r6] */
/* @0x1aa890 mov r1, #6 */
/* @0x1aa894 mov r2, r7 */
/* @0x1aa898 mov r0, r6 */
/* @0x1aa89c str r8, [r6, #0x38] */
/* @0x1aa8a0 vstr s14, [r6, #44] */
/* @0x1aa8a4 vstr s15, [r6, #48] */
/* @0x1aa8a8 ldr r12, [r12, #0x8] */
/* @0x1aa8ac blx r12 */
/* @0x1aa8b0 vldr s14, [r4, #56] */
/* @0x1aa8b4 vcvt.f64.s32 d7, s14 */
/* @0x1aa8b8 ldr r12, [r6] */
/* @0x1aa8bc mov r1, #6 */
/* @0x1aa8c0 mov r2, r7 */
/* @0x1aa8c4 mov r0, r6 */
/* @0x1aa8c8 str r8, [r6, #0x38] */
/* @0x1aa8cc vstr s14, [r6, #44] */
/* @0x1aa8d0 vstr s15, [r6, #48] */
/* @0x1aa8d4 ldr r12, [r12, #0x8] */
/* @0x1aa8d8 blx r12 */
/* @0x1aa8dc vldr s14, [r4, #60] */
/* @0x1aa8e0 vcvt.f64.s32 d7, s14 */
/* @0x1aa8e4 ldr r12, [r6] */
/* @0x1aa8e8 mov r1, #6 */
/* @0x1aa8ec mov r2, r7 */
/* @0x1aa8f0 mov r0, r6 */
/* @0x1aa8f4 str r8, [r6, #0x38] */
/* @0x1aa8f8 vstr s14, [r6, #44] */
/* @0x1aa8fc vstr s15, [r6, #48] */
/* @0x1aa900 ldr r12, [r12, #0x8] */
/* @0x1aa904 blx r12 */
/* @0x1aa908 ldr r4, [r4, #0x40] */
/* @0x1aa90c ldr r12, [r6] */
/* @0x1aa910 mov r0, r6 */
/* @0x1aa914 str r8, [r6, #0x38] */
/* @0x1aa918 mov r1, #6 */
/* @0x1aa91c vmov s13, r4 */
/* @0x1aa920 mov r2, r7 */
/* @0x1aa924 vcvt.f64.s32 d6, s13 */
/* @0x1aa928 vmov r4, r5, d6 */
/* @0x1aa92c vstr s12, [r6, #44] */
/* @0x1aa930 str r5, [r6, #0x30] */
/* @0x1aa934 ldr r12, [r12, #0x8] */
/* @0x1aa938 blx r12 */
/* @0x1aa93c cmp r11, #8 */
/* @0x1aa940 bne 0x1aa628 <_ZN5CRoom9SerialiseEP7IBuffer+0x400> */
/* ── 第 12 段之一：tile 表计数 = CRoom+0xb8（**计数，不是容量**）────────
 *   0x1aa944 ldr r4,[r9,#0xb8] → 类型码 6。
 *   ★ +0xb8/+0xbc/+0xc0 的角色由三处共同定死：AddTile（+0xb8 递增、+0xbc 是扩容对手）、
 *     ClearTiles（三者一起清、+0x00 置 -1）、本函数（只读 +0xb8 与 +0xc0）。
 *     ⇒ 写流用计数，读流把容量置成计数（偏差 3(b)）。
 *   ★ n == 0 时直接跳到 0x1aac20 写层计数：空表不产生任何字段。
 */

/* @0x1aa944 ldr r4, [r9, #0xb8] */
/* @0x1aa948 mov r2, #0 */
/* @0x1aa94c ldr r3, [r6] */
/* @0x1aa950 mov r0, r6 */
/* @0x1aa954 str r2, [r6, #0x38] */
/* @0x1aa958 mov r1, #6 */
/* @0x1aa95c vmov s13, r4 */
/* @0x1aa960 mov r2, r7 */
/* @0x1aa964 vcvt.f64.s32 d6, s13 */
/* @0x1aa968 vmov r4, r5, d6 */
/* @0x1aa96c vstr s12, [r6, #44] */
/* @0x1aa970 str r5, [r6, #0x30] */
/* @0x1aa974 ldr r3, [r3, #0x8] */
/* @0x1aa978 blx r3 */
/* @0x1aa97c ldr r3, [r9, #0xb8] */
/* @0x1aa980 cmp r3, #0 */
/* @0x1aa984 movgt r10, #0 */
/* @0x1aa988 movgt r11, r10 */
/* @0x1aa98c movgt r8, r10 */
/* @0x1aa990 ble 0x1aac20 <_ZN5CRoom9SerialiseEP7IBuffer+0x9f8> */
/* ── tile 循环体：n × 14 字段，步长 56（r10 += 56，0x1aa9bc）────────
 *   基址 +0xc0，逐条按 +0x00..+0x34 走，与 DeSerialise 的 14 个读点逐项同序同型：
 *     +0x00 float t8  +0x04 float t8  +0x08 int t6   +0x0c int t6   +0x10 int t6
 *     +0x14 int t6    +0x18 int t6    +0x1c float t8 +0x20 int t6   +0x24 float t8
 *     +0x28 float t8  +0x2c int t6    +0x30 float t8 +0x34 byte t6
 *   ★ 这里把 DeSerialise 卡里那处「+0x2c 是 int、+0x30 是 float」再钉一次：0x1aab88 对 +0x2c 用
 *     vcvt.f64.s32（int），0x1aabb4 对 +0x30 用 vcvt.f64.f32（float）。两卡三处（DeSerialise /
 *     Serialise / Assign 的 0x1ae1d8）一致。
 *   ★ +0x20 是 tile 的 id（int）：DeSerialise 在 AddTile 之后专门用流里的值覆盖它。
 */

/* @0x1aa994 ldr r4, [r9, #0xc0] */
/* @0x1aa998 mov r1, #8 */
/* @0x1aa99c ldr r3, [r6] */
/* @0x1aa9a0 mov r2, r7 */
/* @0x1aa9a4 add r4, r4, r10 */
/* @0x1aa9a8 vldr s14, [r4] */
/* @0x1aa9ac vcvt.f64.f32 d7, s14 */
/* @0x1aa9b0 mov r0, r6 */
/* @0x1aa9b4 str r8, [r6, #0x38] */
/* @0x1aa9b8 add r11, r11, #1 */
/* @0x1aa9bc add r10, r10, #56 */
/* @0x1aa9c0 vstr s14, [r6, #44] */
/* @0x1aa9c4 vstr s15, [r6, #48] */
/* @0x1aa9c8 ldr r3, [r3, #0x8] */
/* @0x1aa9cc blx r3 */
/* @0x1aa9d0 vldr s14, [r4, #4] */
/* @0x1aa9d4 vcvt.f64.f32 d7, s14 */
/* @0x1aa9d8 ldr r3, [r6] */
/* @0x1aa9dc mov r1, #8 */
/* @0x1aa9e0 mov r2, r7 */
/* @0x1aa9e4 str r8, [r6, #0x38] */
/* @0x1aa9e8 mov r0, r6 */
/* @0x1aa9ec vstr s14, [r6, #44] */
/* @0x1aa9f0 vstr s15, [r6, #48] */
/* @0x1aa9f4 ldr r3, [r3, #0x8] */
/* @0x1aa9f8 blx r3 */
/* @0x1aa9fc vldr s14, [r4, #8] */
/* @0x1aaa00 vcvt.f64.s32 d7, s14 */
/* @0x1aaa04 ldr r3, [r6] */
/* @0x1aaa08 mov r1, #6 */
/* @0x1aaa0c mov r2, r7 */
/* @0x1aaa10 mov r0, r6 */
/* @0x1aaa14 str r8, [r6, #0x38] */
/* @0x1aaa18 vstr s14, [r6, #44] */
/* @0x1aaa1c vstr s15, [r6, #48] */
/* @0x1aaa20 ldr r3, [r3, #0x8] */
/* @0x1aaa24 blx r3 */
/* @0x1aaa28 vldr s14, [r4, #12] */
/* @0x1aaa2c vcvt.f64.s32 d7, s14 */
/* @0x1aaa30 ldr r3, [r6] */
/* @0x1aaa34 mov r1, #6 */
/* @0x1aaa38 mov r2, r7 */
/* @0x1aaa3c mov r0, r6 */
/* @0x1aaa40 str r8, [r6, #0x38] */
/* @0x1aaa44 vstr s14, [r6, #44] */
/* @0x1aaa48 vstr s15, [r6, #48] */
/* @0x1aaa4c ldr r3, [r3, #0x8] */
/* @0x1aaa50 blx r3 */
/* @0x1aaa54 vldr s14, [r4, #16] */
/* @0x1aaa58 vcvt.f64.s32 d7, s14 */
/* @0x1aaa5c ldr r3, [r6] */
/* @0x1aaa60 mov r1, #6 */
/* @0x1aaa64 mov r2, r7 */
/* @0x1aaa68 mov r0, r6 */
/* @0x1aaa6c str r8, [r6, #0x38] */
/* @0x1aaa70 vstr s14, [r6, #44] */
/* @0x1aaa74 vstr s15, [r6, #48] */
/* @0x1aaa78 ldr r3, [r3, #0x8] */
/* @0x1aaa7c blx r3 */
/* @0x1aaa80 vldr s14, [r4, #20] */
/* @0x1aaa84 vcvt.f64.s32 d7, s14 */
/* @0x1aaa88 ldr r3, [r6] */
/* @0x1aaa8c mov r1, #6 */
/* @0x1aaa90 mov r2, r7 */
/* @0x1aaa94 mov r0, r6 */
/* @0x1aaa98 str r8, [r6, #0x38] */
/* @0x1aaa9c vstr s14, [r6, #44] */
/* @0x1aaaa0 vstr s15, [r6, #48] */
/* @0x1aaaa4 ldr r3, [r3, #0x8] */
/* @0x1aaaa8 blx r3 */
/* @0x1aaaac vldr s14, [r4, #24] */
/* @0x1aaab0 vcvt.f64.s32 d7, s14 */
/* @0x1aaab4 ldr r3, [r6] */
/* @0x1aaab8 mov r1, #6 */
/* @0x1aaabc mov r2, r7 */
/* @0x1aaac0 mov r0, r6 */
/* @0x1aaac4 str r8, [r6, #0x38] */
/* @0x1aaac8 vstr s14, [r6, #44] */
/* @0x1aaacc vstr s15, [r6, #48] */
/* @0x1aaad0 ldr r3, [r3, #0x8] */
/* @0x1aaad4 blx r3 */
/* @0x1aaad8 vldr s14, [r4, #28] */
/* @0x1aaadc vcvt.f64.f32 d7, s14 */
/* @0x1aaae0 ldr r3, [r6] */
/* @0x1aaae4 mov r1, #8 */
/* @0x1aaae8 mov r2, r7 */
/* @0x1aaaec str r8, [r6, #0x38] */
/* @0x1aaaf0 mov r0, r6 */
/* @0x1aaaf4 vstr s14, [r6, #44] */
/* @0x1aaaf8 vstr s15, [r6, #48] */
/* @0x1aaafc ldr r3, [r3, #0x8] */
/* @0x1aab00 blx r3 */
/* @0x1aab04 vldr s14, [r4, #32] */
/* @0x1aab08 vcvt.f64.s32 d7, s14 */
/* @0x1aab0c ldr r3, [r6] */
/* @0x1aab10 mov r1, #6 */
/* @0x1aab14 mov r2, r7 */
/* @0x1aab18 mov r0, r6 */
/* @0x1aab1c str r8, [r6, #0x38] */
/* @0x1aab20 vstr s14, [r6, #44] */
/* @0x1aab24 vstr s15, [r6, #48] */
/* @0x1aab28 ldr r3, [r3, #0x8] */
/* @0x1aab2c blx r3 */
/* @0x1aab30 vldr s14, [r4, #36] */
/* @0x1aab34 vcvt.f64.f32 d7, s14 */
/* @0x1aab38 ldr r3, [r6] */
/* @0x1aab3c mov r1, #8 */
/* @0x1aab40 mov r2, r7 */
/* @0x1aab44 str r8, [r6, #0x38] */
/* @0x1aab48 mov r0, r6 */
/* @0x1aab4c vstr s14, [r6, #44] */
/* @0x1aab50 vstr s15, [r6, #48] */
/* @0x1aab54 ldr r3, [r3, #0x8] */
/* @0x1aab58 blx r3 */
/* @0x1aab5c vldr s14, [r4, #40] */
/* @0x1aab60 vcvt.f64.f32 d7, s14 */
/* @0x1aab64 ldr r3, [r6] */
/* @0x1aab68 mov r1, #8 */
/* @0x1aab6c mov r2, r7 */
/* @0x1aab70 str r8, [r6, #0x38] */
/* @0x1aab74 mov r0, r6 */
/* @0x1aab78 vstr s14, [r6, #44] */
/* @0x1aab7c vstr s15, [r6, #48] */
/* @0x1aab80 ldr r3, [r3, #0x8] */
/* @0x1aab84 blx r3 */
/* @0x1aab88 vldr s14, [r4, #44] */
/* @0x1aab8c vcvt.f64.s32 d7, s14 */
/* @0x1aab90 ldr r3, [r6] */
/* @0x1aab94 mov r1, #6 */
/* @0x1aab98 mov r2, r7 */
/* @0x1aab9c mov r0, r6 */
/* @0x1aaba0 str r8, [r6, #0x38] */
/* @0x1aaba4 vstr s14, [r6, #44] */
/* @0x1aaba8 vstr s15, [r6, #48] */
/* @0x1aabac ldr r3, [r3, #0x8] */
/* @0x1aabb0 blx r3 */
/* @0x1aabb4 vldr s14, [r4, #48] */
/* @0x1aabb8 vcvt.f64.f32 d7, s14 */
/* @0x1aabbc ldr r3, [r6] */
/* @0x1aabc0 mov r1, #8 */
/* @0x1aabc4 mov r2, r7 */
/* @0x1aabc8 str r8, [r6, #0x38] */
/* @0x1aabcc mov r0, r6 */
/* @0x1aabd0 vstr s14, [r6, #44] */
/* @0x1aabd4 vstr s15, [r6, #48] */
/* @0x1aabd8 ldr r3, [r3, #0x8] */
/* @0x1aabdc blx r3 */
/* @0x1aabe0 ldrb r4, [r4, #0x34] */
/* @0x1aabe4 ldr r3, [r6] */
/* @0x1aabe8 mov r0, r6 */
/* @0x1aabec str r8, [r6, #0x38] */
/* @0x1aabf0 mov r1, #6 */
/* @0x1aabf4 vmov s13, r4 */
/* @0x1aabf8 mov r2, r7 */
/* @0x1aabfc vcvt.f64.u32 d6, s13 */
/* @0x1aac00 vmov r4, r5, d6 */
/* @0x1aac04 vstr s12, [r6, #44] */
/* @0x1aac08 str r5, [r6, #0x30] */
/* @0x1aac0c ldr r3, [r3, #0x8] */
/* @0x1aac10 blx r3 */
/* @0x1aac14 ldr r3, [r9, #0xb8] */
/* @0x1aac18 cmp r3, r11 */
/* @0x1aac1c bgt 0x1aa994 <_ZN5CRoom9SerialiseEP7IBuffer+0x76c> */
/* ── 第 12 段之二：层计数 = CRoom+0xdc，随后沿 +0xd4 链逐层 ──────────
 *   计数 0x1aac20（ldr r4,[r9,#0xdc] → t6）。
 *   ★ 层集合在 +0xd4 链上（next 在 CLayer+0x68），不在 56 B 的 tile 表里 —— 这一条与
 *     DuplicateRoomLayers 卡、DeSerializeLayer 侧三方一致。
 */

/* @0x1aac20 ldr r4, [r9, #0xdc] */
/* @0x1aac24 mov r2, #0 */
/* @0x1aac28 ldr r3, [r6] */
/* @0x1aac2c mov r0, r6 */
/* @0x1aac30 str r2, [r6, #0x38] */
/* @0x1aac34 mov r1, #6 */
/* @0x1aac38 vmov s15, r4 */
/* @0x1aac3c mov r2, r7 */
/* @0x1aac40 vcvt.f64.s32 d7, s15 */
/* @0x1aac44 vmov r4, r5, d7 */
/* @0x1aac48 vstr s14, [r6, #44] */
/* @0x1aac4c str r5, [r6, #0x30] */
/* @0x1aac50 ldr r3, [r3, #0x8] */
/* @0x1aac54 blx r3 */
/* ── 层链遍历：while (layer) { CLayer::Serialize(buf); layer = layer->0x68 } ──
 *   从链头 +0xd4 正序走。层链是「CLayer+0x04 升序」表 —— 依据 CLayerManager::
 *   InsertLayerIntoActiveList 0x1c3110..0x1c3148：从 +0xd4 起比较 [cur+0x4] 与 [new+0x4]，
 *   走到第一个 cur+0x4 > new+0x4 的层之前插入，一路不大就接尾；即升序、等键稳定。
 *   DeSerializeLayer 把每条读出来的层交给同一个函数 ⇒ 正序写出 / 升序插回 = 顺序互逆。
 *   本函数不写层数以外的任何层字段（一切在被调方 0x1a9428）。
 */

/* @0x1aac58 ldr r4, [r9, #0xd4] */
/* @0x1aac5c cmp r4, #0 */
/* @0x1aac60 beq 0x1aac7c <_ZN5CRoom9SerialiseEP7IBuffer+0xa54> */
/* @0x1aac64 mov r0, r4 */
/* @0x1aac68 mov r1, r6 */
/* @0x1aac6c bl 0x1a9428 <_ZN6CLayer9SerializeEP7IBuffer> */
/* @0x1aac70 ldr r4, [r4, #0x68] */
/* @0x1aac74 cmp r4, #0 */
/* @0x1aac78 bne 0x1aac64 <_ZN5CRoom9SerialiseEP7IBuffer+0xa3c> */
/* ── 第 12 段之三：活动实例计数 = CRoom+0x88，链从**尾** +0x80 起 ──────
 *   ★ 方向：0x1aacb4 ldr r4,[r9,#0x80]（尾）+ 0x1aaccc ldr r4,[r4,#0x178]（prev）⇒ 逆向。
 *     逆向是必须的：对端按「插到第一个 key <= new 之前」做降序插入，只有拿到 depth 升序的流
 *     才能把链原样重建（含等值 stability，见头部 2）。
 *   ★ 同时反证 +0x178 = prev：A 链只需 prev 就能从尾走到头。
 */

/* @0x1aac7c ldr r4, [r9, #0x88] */
/* @0x1aac80 mov r2, #0 */
/* @0x1aac84 ldr r3, [r6] */
/* @0x1aac88 mov r0, r6 */
/* @0x1aac8c str r2, [r6, #0x38] */
/* @0x1aac90 mov r1, #6 */
/* @0x1aac94 vmov s15, r4 */
/* @0x1aac98 mov r2, r7 */
/* @0x1aac9c vcvt.f64.s32 d7, s15 */
/* @0x1aaca0 vmov r4, r5, d7 */
/* @0x1aaca4 vstr s14, [r6, #44] */
/* @0x1aaca8 str r5, [r6, #0x30] */
/* @0x1aacac ldr r3, [r3, #0x8] */
/* @0x1aacb0 blx r3 */
/* @0x1aacb4 ldr r4, [r9, #0x80] */
/* @0x1aacb8 cmp r4, #0 */
/* @0x1aacbc beq 0x1aacd8 <_ZN5CRoom9SerialiseEP7IBuffer+0xab0> */
/* @0x1aacc0 mov r0, r4 */
/* @0x1aacc4 mov r1, r6 */
/* @0x1aacc8 bl 0x196bf4 <_ZN9CInstance9SerialiseEP7IBuffer> */
/* @0x1aaccc ldr r4, [r4, #0x178] */
/* @0x1aacd0 cmp r4, #0 */
/* @0x1aacd4 bne 0x1aacc0 <_ZN5CRoom9SerialiseEP7IBuffer+0xa98> */
/* ── 第 12 段之四：非活动实例计数 = CRoom+0x94，链从尾 +0x8c 起 ────────
 *   同样的 prev 逆向遍历。B 链是头插建起来的（DeSerialise 0x1ace58/0x1ace6c），所以
 *   「从尾沿 prev」= 原始插入顺序；对端再头插一遍就精确还原。
 *   空链（+0x8c == 0）在 0x1aad18 直接 pop 返回 —— 全函数唯一的提前出口。
 */

/* @0x1aacd8 ldr r4, [r9, #0x94] */
/* @0x1aacdc mov r1, #0 */
/* @0x1aace0 ldr r3, [r6] */
/* @0x1aace4 mov r2, r7 */
/* @0x1aace8 str r1, [r6, #0x38] */
/* @0x1aacec mov r0, r6 */
/* @0x1aacf0 vmov s13, r4 */
/* @0x1aacf4 mov r1, #6 */
/* @0x1aacf8 vcvt.f64.s32 d6, s13 */
/* @0x1aacfc vmov r4, r5, d6 */
/* @0x1aad00 vstr s12, [r6, #44] */
/* @0x1aad04 str r5, [r6, #0x30] */
/* @0x1aad08 ldr r3, [r3, #0x8] */
/* @0x1aad0c blx r3 */
/* @0x1aad10 ldr r4, [r9, #0x8c] */
/* @0x1aad14 cmp r4, #0 */
/* @0x1aad18 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1aad1c mov r0, r4 */
/* @0x1aad20 mov r1, r6 */
/* @0x1aad24 bl 0x196bf4 <_ZN9CInstance9SerialiseEP7IBuffer> */
/* @0x1aad28 ldr r4, [r4, #0x178] */
/* @0x1aad2c cmp r4, #0 */
/* @0x1aad30 bne 0x1aad1c <_ZN5CRoom9SerialiseEP7IBuffer+0xaf4> */
/* @0x1aad34 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 错误出口：+0x70（带物理）非 0 时喊串，然后回主线 ────────────────
 *   ldr r0,[pc,#0xc] → 0x001a24bc；add r0,pc,r0（pc = 0x1aad48）⇒ 0x34d204
 *   = "ERROR: game_save unavailable for rooms using physics"
 *   Error_Show(str, true) 0xecd7c；然后 b 0x1aa240 —— **不 abort**：物理世界不写进流，
 *   其余照写。所以「带物理的房间存盘」= 串 + 静默丢物理（open 4）。
 */

/* @0x1aad38 ldr r0, [pc, #0xc] */
/* @0x1aad3c mov r1, #1 */
/* @0x1aad40 add r0, pc, r0 */
/* @0x1aad44 bl 0xecd7c <_Z10Error_ShowPKcb> */
/* @0x1aad48 b 0x1aa240 <_ZN5CRoom9SerialiseEP7IBuffer+0x18> */
/* ── 池字（0x1aad4c 是函数范围内的最后 4 字节，不是指令）─────────────
 *   0x001a24bc = 上面那条 pc 加数（0x1aad48 + 0x1a24bc = 0x34d204）。
 *   objdump 把它译成 ldrheq r2,[r10],-r12，锚点按索引原样保留。
 */

/* @0x1aad4c ldrheq r2, [r10], -r12 */
