/* cally 逆向卡：CRoom::AddTile / CRoom::AddTileToStorage（原版 libyoyo.so，armv7）
 *
 * @card 0x001aaf78 .. 0x001ac338（2 个函数 / 162 条锚点，地址各只出现一次）
 *        —— 两节：AddTile（房间自持 56 B tile 表）与 AddTileToStorage（+0xc4 的 48 B 暂存表）。
 *           verify_reverse_v1 的 range 列只取第一个 @func（0x001ac240..0x001ac338）。
 * @func 0x1ac240 0x1ac338  size 252  63 条（61 条指令 + 尾 2 池字；无栈实参、无死代码）
 * @func 0x1aaf78 0x1ab100  size 396  99 条（97 条指令 + 尾 2 池字；11 个值参 8 个在栈上）
 * 级别: 正文（162/162 条锚定；容量增长、56 B 记录拷贝、id 分配、48 B 记录的 12 个字段落位、
 *            整块重建与 Free 时序全部逐条钉住。未钉：两种 tile 记录「字段名」、CRoom+0x00 的读者、
 *            +0xc4 的初始化者、以及 store 版没有返回值的契约）
 * 符号: _ZN5CRoom7AddTileEP5RTile                          int CRoom::AddTile(RTile* tile)
 *       _ZN5CRoom16AddTileToStorageEiiiiiiiiffj             void CRoom::AddTileToStorage(
 *             int, int, int, int, int, int, int, int, float, float, unsigned int)
 * ABI : softfp；栈上的 float 实参仍占 4 B（vldr s17,[sp,#92] / vldr s16,[sp,#96]）。
 * 来源: libyoyo.so sha256 3bbedd09ad0cc60f3f3cad86a257275f…（4,689,844 B，stripped，ELF32 ARM）
 * 锚表: asm/index-CRoom_AddTile.tsv（63 行）+ asm/index-CRoom_AddTileToStorage.tsv（99 行）
 * 同层: CRoom::DeSerialise 0x1ac33c（唯一按条调 AddTile 的地方，且立刻把 id 计数器减回去）、
 *       CRoom::LoadFromStream 0x1ae3f8 / LoadFromChunk 0x1aea3c（绕过 AddTile 直填 +0xb8 表）、
 *       CRoom::AddInstanceToStorage 0x1aadac（同一套 cARRAY 惯用法 + 同一个 room_maxid）、
 *       Room_Get_maxtileid 0x1b5e2c / Room_Set_maxtileid 0x1b5e40（同一 GOT 槽 0x3f0818）、
 *       MemoryManager::ReAlloc 0x27cedc / Alloc 0x27ce78 / Free 0x27c2d0
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   AddTile 往**房间自持**的 56 B 记录表（room+0xb8 计数 / +0xbc 容量 / +0xc0 数据）追加一条，
 *   顺手把全局 room_maxtileid++ 写进记录的 +0x20，再把 room+0x00 记成这条的下标，返回该下标。
 *   AddTileToStorage 不碰房间表：它把一条 48 B 记录追加进 room+0xc4 指向的独立堆数组
 *   （每次整块重建），同样向 room_maxtileid 取号写进 +0x20，**无返回值**。
 *
 * ── 两张 tile 表的对照（本卡最该记住的一张表）────────────────
 *                      AddTile                         AddTileToStorage
 *   目标                room+0xb8/+0xbc/+0xc0 内联表    room+0xc4 → 独立堆块
 *   记录大小            56 B（14 字）                   48 B（12 字）
 *   扩容方式            ReAlloc(56*(count+10))          Alloc(52*(n+1)+4) → 全量拷贝 → Free 旧块
 *   容量策略            count >= cap 时 cap = count+10   无容量字段，每次按 count+1 精确重建
 *   计数                1ac274/1ac278 抬 +0xb8           [块+0x00]，1ab0ec 抬 1
 *   id                  ++room_maxtileid → +0x20         ++room_maxtileid → +0x20（同一全局）
 *   副作用              room+0x00 = 本条下标             无（不写 room+0x00）
 *   返回值              旧 count（= 新记录下标）         无
 *   NULL 检查           无（+0xc0 由 +0xbc 决定）        无（**直接解引用 +0xc4**，不判空）
 *   调用者              F_TileAdd 0x11c3f8、DeSerialise 0x1acc6c
 *                                                       F_RoomTileAdd 0x12e9f4、F_RoomTileAddExt 0x12ebbc
 *   ⇒ 两条路吃同一串 room_maxtileid（GOT 0x3f0818 → .bss 0x542558），所以「暂存过的 tile」与
 *     「进房间表的 tile」会交错消耗同一个号段（open 5，与 AddInstance 侧 open 5 同源）。
 *
 * ── room_maxtileid 的取证链（本卡两处 + 两个访问器三方互证）──────
 *   AddTile 1ac26c ldr r7,[pc,#0xc0]（池字 1ac334 = 0x00244594）+ 1ac27c ldr r7,[pc,r7]
 *     → pc 1ac284 + 0x244594 = 0x3f0818 → 槽内 addend 0x542558（.bss）
 *   Room_Get_maxtileid 0x1b5e2c / Room_Set_maxtileid 0x1b5e40 用**同一个槽 0x3f0818**
 *   AddTileToStorage 1ab064/1ab074 走池字 1ab100（0x0024579c）落到同一个 0x3f0818
 *   ⇒ 三处指向同一个 int，AddTile 的 ++ 与 DeSerialise 的 -- 才可能互相抵消。
 *
 * ── 未定（open）────────────────────────────────────────────
 *   1. RTile 的 14 个字（+0x00..+0x34）与 store 版 12 个字的**字段名**：本卡只证「逐字节拷贝」
 *      与「+0x20 被 id 覆写」；两套记录相差 8 B，谁多谁少未证
 *   2. CRoom+0x00（AddTile 写「最新 tile 下标」）的读者：全库执行流里未出现，与 DeSerialise 卡 open 4 同悬
 *   3. AddTile 的零容量出口（1ac2c0 count+10 == 0 → 1ac304/1ac320）：只有 count == 0xFFFFFFF6
 *      才可达，正常调用不可达；它是 CArray 模板 SetSize(0) 尾巴被内联进来的残留
 *   4. CRoom+0xc4 由谁初始化：AddTileToStorage 不判空就 `ldr r12,[r7]`，说明别处（ctor/Assign?）建
 *   5. room_maxtileid 双入口共用号段的实际后果（重号是否被下游查表依赖）未做运行期验证
 *   6. AddTileToStorage 每次整块重建 ⇒ 旧指针失效，但没有任何文档/断言把这条契约钉住
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ══════════════════════════════════════════════════════════════════
 * 1) AddTile(RTile* tile) —— 房间自持 56 B tile 表（+0xb8/+0xbc/+0xc0）
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口：r6 = this、r4 = src(RTile*)、r5 = [this+0xb8]（count）、r3 = [this+0xbc]（cap）──
 *   帧：push {r4-r9,lr} + sub sp,#12（12 B 里只有 [sp] 用得上：ReAlloc 的第 5 实参 false）。
 */

/* @0x1ac240 push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x1ac244 mov r6, r0 */
/* ── count（+0xb8）与 cap（+0xbc）分别进 r5/r3，1ac258 cmp 后 bge 走扩容 ──
 *   扩容完在 1ac2f8 重新读 count（ReAlloc 之后 r3/r5 不保证存活）。
 */

/* @0x1ac248 ldr r5, [r0, #0xb8] */
/* @0x1ac24c sub sp, sp, #12 */
/* @0x1ac250 ldr r3, [r0, #0xbc] */
/* @0x1ac254 mov r4, r1 */
/* @0x1ac258 cmp r5, r3 */
/* ── count >= cap → 1ac2c0 扩容；否则 1ac260 直接拿数据基址 ──
 *   ★ 是「满则扩容」而不是「满则失败」：容量不足永远靠 ReAlloc 解决，没有上限检查。
 */

/* @0x1ac25c bge 0x1ac2c0 <_ZN5CRoom7AddTileEP5RTile+0x80> */
/* ── 目标地址 = data + 56*count ─────────────────────────
 *   r12 = (count<<3) - count = 7*count，再 lsl #3 ⇒ 56*count；1ac270 r8 = [this+0xc0] + 56*count。
 *   注意 1ac274/1ac278 先把 count+1 写回 +0xb8，**再**开始拷贝。
 */

/* @0x1ac260 ldr r8, [r0, #0xc0] */
/* @0x1ac264 ldm r4!, {r0, r1, r2, r3} */
/* @0x1ac268 rsb r12, r5, r5, lsl #3 */
/* ── room_maxtileid：池字 1ac334 = 0x00244594 → pc 1ac284 + 0x244594 = 0x3f0818 ──
 *   槽内 addend = .bss 0x542558；Room_Get_maxtileid 0x1b5e2c / Room_Set_maxtileid 0x1b5e40
 *   用同一个槽 ⇒ 三处互证同一个 int。
 */

/* @0x1ac26c ldr r7, [pc, #0xc0] */
/* @0x1ac270 add r8, r8, r12, lsl #3 */
/* @0x1ac274 add r12, r5, #1 */
/* @0x1ac278 str r12, [r6, #0xb8] */
/* @0x1ac27c ldr r7, [pc, r7] */
/* @0x1ac280 mov r12, r8 */
/* @0x1ac284 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac288 ldm r4!, {r0, r1, r2, r3} */
/* ── id = ++room_maxtileid（先加后取，单调、不查重）──
 *   1ac2b0 把这一格写进新记录的 +0x20 ⇒ **src 的 +0x20 被丢弃**。
 *   ★ DeSerialise 每读完一条就把它减回去（0x1acc7c sub r1,#1），净效果计数器不动，见 CRoom_DeSerialise 卡。
 */

/* @0x1ac28c ldr r9, [r7] */
/* @0x1ac290 add r9, r9, #1 */
/* @0x1ac294 str r9, [r7] */
/* @0x1ac298 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac29c ldm r4!, {r0, r1, r2, r3} */
/* @0x1ac2a0 stm r12!, {r0, r1, r2, r3} */
/* @0x1ac2a4 ldm r4, {r0, r1} */
/* @0x1ac2a8 stm r12, {r0, r1} */
/* ── 返回与两个落点 ───────────────────────────────────
 *   r0 = r5 = **旧 count**（= 新记录下标，0 基）；
 *   [r8+0x20] = 新 id（1ac2b0）；[r6+0x00] = 同一个下标（1ac2b4）—— CRoom+0x00 的读者未证（open 2）。
 */

/* @0x1ac2ac mov r0, r5 */
/* @0x1ac2b0 str r9, [r8, #0x20] */
/* @0x1ac2b4 str r5, [r6] */
/* @0x1ac2b8 add sp, sp, #12 */
/* @0x1ac2bc pop {r4, r5, r6, r7, r8, r9, pc} */
/* ── 扩容分支：cap = count + 10 ───────────────────────
 *   adds r7,r5,#10 顺带置标志：count+10 == 0（即 count == 0xFFFFFFF6）时 beq 1ac304，
 *   走「容量 0」的退化出口（open 3）。正常路径 r7 = count+10 ≥ 10。
 */

/* @0x1ac2c0 adds r7, r5, #10 */
/* @0x1ac2c4 beq 0x1ac304 <_ZN5CRoom7AddTileEP5RTile+0xc4> */
/* @0x1ac2c8 rsb r1, r7, r7, lsl #3 */
/* @0x1ac2cc ldr r0, [r0, #0xc0] */
/* ── 字节数 = 56*(count+10)（rsb 求 7*r7，再 lsl #3）──
 *   lsls 之后再判 0：bytes == 0 也归到 1ac320 的退化出口。
 */

/* @0x1ac2d0 lsls r1, r1, #3 */
/* @0x1ac2d4 beq 0x1ac320 <_ZN5CRoom7AddTileEP5RTile+0xe0> */
/* @0x1ac2d8 ldr r2, [pc, #0x58] */
/* @0x1ac2dc mov r3, #0 */
/* ── ReAlloc(data=+0xc0, 56*(count+10), "…/Files/Platform/cARRAY_STRUCTURE.h", 106, false) ──
 *   文件串走池字 1ac338 = 0x001a0f4c：pc 1ac2f0 + 0x1a0f4c = 0x34d23c（cARRAY_STRUCTURE.h）。
 *   行 106 与 Variable_Global_Init 0x1f3354 用的是**同一行** —— 同一个模板 Resize 被内联了两处。
 *   第 5 实参 false = 不清零：多出来的 560 B 是脏的，但只有 [0..count] 会被读到。
 */

/* @0x1ac2e0 str r3, [sp] */
/* @0x1ac2e4 mov r3, #106 */
/* @0x1ac2e8 add r2, pc, r2 */
/* @0x1ac2ec bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* ── ReAlloc 之后：r8 = 新基址、+0xc0 = 新基址、重读 count、+0xbc = 新容量 ──
 *   ★ 回跳目标是 1ac264（拷贝），不是 1ac260：r8 已是新基址，1ac270 只再加 56*count 的偏移。
 *     看反了会以为它在重读 [r0+0xc0]（r0 此刻是 ReAlloc 的返回值，读不得）。
 */

/* @0x1ac2f0 mov r8, r0 */
/* @0x1ac2f4 str r0, [r6, #0xc0] */
/* @0x1ac2f8 ldr r5, [r6, #0xb8] */
/* @0x1ac2fc str r7, [r6, #0xbc] */
/* @0x1ac300 b 0x1ac264 <_ZN5CRoom7AddTileEP5RTile+0x24> */
/* ── 退化出口（count == 0xFFFFFFF6）：data != 0 → Free 后 capacity = 0、data = 0（r7 此时为 0）；
 *    data == 0 → 直接跳 1ac320 再 Free 一次（Free(NULL)）──
 *   两条都会回跳 1ac264 继续「拷贝到 NULL」，所以只有这条路径**不可达**才安全；正常调用进不来。
 */

/* @0x1ac304 ldr r0, [r0, #0xc0] */
/* @0x1ac308 cmp r0, #0 */
/* @0x1ac30c beq 0x1ac320 <_ZN5CRoom7AddTileEP5RTile+0xe0> */
/* @0x1ac310 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac314 mov r8, r7 */
/* @0x1ac318 str r7, [r6, #0xc0] */
/* @0x1ac31c b 0x1ac2f8 <_ZN5CRoom7AddTileEP5RTile+0xb8> */
/* @0x1ac320 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ac324 mov r3, #0 */
/* @0x1ac328 mov r8, r3 */
/* @0x1ac32c str r3, [r6, #0xc0] */
/* @0x1ac330 b 0x1ac2f8 <_ZN5CRoom7AddTileEP5RTile+0xb8> */
/* ── literal pool（2 字）─────────────────────────────────
 *   1ac334 = 0x00244594  → pc 1ac284 + 0x244594 = 0x3f0818 = &room_maxtileid（.bss 0x542558）
 *   1ac338 = 0x001a0f4c  → pc 1ac2f0 + 0x1a0f4c = 0x34d23c = "…/Files/Platform/cARRAY_STRUCTURE.h"
 */

/* @0x1ac334 mlaeq r4, r4, r5, r4 */
/* @0x1ac338 andseq r0, r10, r12, asr #30 */
/* ══════════════════════════════════════════════════════════════════
 * 2) AddTileToStorage(8×int, 2×float, uint) —— room+0xc4 的 48 B 暂存表
 * ══════════════════════════════════════════════════════════════════ */

/* ── 入口与实参落位（11 个值参：3 个在 r1-r3，8 个在栈上）────────
 *   帧：push {r4-r11,lr}(36 B) + vpush {d8}(8 B) + sub sp,#28 ⇒ 栈实参从 sp+0x48 起。
 *   p1=r1[p+0xc]  p2=r2[p+0x10]  p3=r3[p+0x14]  p4=[sp+0x48]  p5=[sp+0x4c]
 *   p6=[sp+0x50]  p7=[sp+0x54]   p8=[sp+0x58]
 *   p9=float [sp+0x5c]（vldr s17,[sp,#92]）  p10=float [sp+0x60]（vldr s16,[sp,#96]）
 *   p11=uint [sp+0x64]
 *   ★ 全部 11 个值参**一个不落**地进了记录，没有丢弃项；记录 12 个字里只有 +0x20 是算出来的。
 */

/* @0x1aaf78 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aaf7c vpush {d8} */
/* @0x1aaf80 mov r6, r0 */
/* ── r7 = [this+0xc4]（暂存数组指针）→ r12 = [r7]（count）──
 *   ★ 这里**不判空**：+0xc4 == 0 会直接段错。对照 AddInstanceToStorage，那边有 beq 首建分支。
 *     ⇒ +0xc4 必须由别处（CRoom 构造/Assign）先建好（open 4）。
 */

/* @0x1aaf84 ldr r7, [r6, #0xc4] */
/* ── 新块字节数 = 52*(count+1) + 4 ───────────────────────
 *   52 = 4（槽）+ 48（记录）每元素；+4 是 count 头。
 *   布局与 AddInstanceToStorage 同构：{count, slots[n+1], entries[n+1]}，
 *   总计 4 + 4(n+1) + 48(n+1) = 52(n+1)+4 —— 每个元素既有一格指针又有一份内联记录。
 */

/* @0x1aaf88 mov r0, #52 */
/* @0x1aaf8c sub sp, sp, #28 */
/* @0x1aaf90 vldr s17, [sp, #92] */
/* @0x1aaf94 vldr s16, [sp, #96] */
/* @0x1aaf98 ldr r12, [r7] */
/* @0x1aaf9c str r1, [sp, #0xc] */
/* ── 文件串 = "jni/../jni/yoyo/../../../Files/Room/Room_Class.cpp"（池字 1ab0fc）──
 *   pc 1aafb8 + 0x1a21f8 = 0x34d1b0；行 0x51b = 1307；第 5 实参 true = 清零。
 *   ★ 这里用 Alloc(…, true) 而不是 ReAlloc：新块要清零，旧块随后整体 Free（1ab05c）。
 */

/* @0x1aafa0 ldr r1, [pc, #0x154] */
/* @0x1aafa4 mla r0, r12, r0, r0 */
/* @0x1aafa8 str r2, [sp, #0x10] */
/* @0x1aafac str r3, [sp, #0x14] */
/* @0x1aafb0 add r1, pc, r1 */
/* @0x1aafb4 movw r2, #0x51b */
/* @0x1aafb8 mov r3, #1 */
/* @0x1aafbc str r0, [sp, #0x4] */
/* @0x1aafc0 add r0, r0, #4 */
/* @0x1aafc4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* ── 旧块回放（与 AddInstanceToStorage 同一套循环，只是记录 48 B）──
 *   r2 = [old] = count；r1 = new + 4*count + 8 = 新 entries 区起点；
 *   lr 走新槽游标（从 new+4 起），r4 走旧槽游标（从 old+4 起）。
 *   1aaff4 每轮先写 slots[i] = 记录新址，再判旧槽是否为 NULL（streq 把刚写的槽改回 0 并跳过复制）。
 *   ★ 复制源是**旧槽指向的记录**，不是旧块里的内联位置 —— 旧块只信 slot 数组。
 */

/* @0x1aafc8 ldr r2, [r7] */
/* @0x1aafcc cmp r2, #0 */
/* @0x1aafd0 add r1, r0, #4 */
/* @0x1aafd4 str r1, [sp, #0x8] */
/* @0x1aafd8 add r1, r0, r2, lsl #2 */
/* @0x1aafdc mov r10, r0 */
/* @0x1aafe0 add r1, r1, #8 */
/* @0x1aafe4 ble 0x1ab054 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0xdc> */
/* @0x1aafe8 ldr lr, [sp, #0x8] */
/* @0x1aafec mov r4, r7 */
/* @0x1aaff0 mov r12, #0 */
/* @0x1aaff4 str r1, [lr], #4 */
/* @0x1aaff8 ldr r3, [r4, #0x4]! */
/* @0x1aaffc cmp r3, #0 */
/* @0x1ab000 streq r3, [lr, #-0x4] */
/* @0x1ab004 beq 0x1ab044 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0xcc> */
/* ── 单条记录复制：48 B（12 字 = 3 轮 4 字）──
 *   r0 = src+48 作界，r3 从 src+16 起按 -0xc/-8/-4 回读前 4 字，r2 同步前进 16 B；
 *   纯 POD，无指针/引用计数，抄完即可（槽在 1aaff4 已重指向）。
 */

/* @0x1ab008 add r0, r3, #48 */
/* @0x1ab00c mov r2, r1 */
/* @0x1ab010 ldr r11, [r3] */
/* @0x1ab014 add r3, r3, #16 */
/* @0x1ab018 ldr r9, [r3, #-0xc] */
/* @0x1ab01c add r2, r2, #16 */
/* @0x1ab020 ldr r8, [r3, #-0x8] */
/* @0x1ab024 ldr r5, [r3, #-0x4] */
/* @0x1ab028 cmp r3, r0 */
/* @0x1ab02c str r11, [r2, #-0x10] */
/* @0x1ab030 str r9, [r2, #-0xc] */
/* @0x1ab034 str r8, [r2, #-0x8] */
/* @0x1ab038 str r5, [r2, #-0x4] */
/* @0x1ab03c bne 0x1ab010 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0x98> */
/* @0x1ab040 ldr r2, [r7] */
/* ── 循环推进：r12 计数、r1 += 48（记录游标）、cmp 与 [old] 比 ──
 *   与 AddInstanceToStorage 唯一的形态差别就在这里的步长（48 vs 40）。
 */

/* @0x1ab044 add r12, r12, #1 */
/* @0x1ab048 add r1, r1, #48 */
/* @0x1ab04c cmp r2, r12 */
/* @0x1ab050 bgt 0x1aaff4 <_ZN5CRoom16AddTileToStorageEiiiiiiiiffj+0x7c> */
/* ── 收尾时序：新块 [0] = count → Free(旧块) → 换 +0xc4 ──
 *   ★ 顺序是「先写新块 count、再 Free 旧块」；Free 之后旧 slots/entries 全部失效。
 *   r10 = 新块基址，1ab078 才把它写回 [this+0xc4]。
 */

/* @0x1ab054 str r2, [r10] */
/* @0x1ab058 mov r0, r7 */
/* @0x1ab05c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* ── 新记录偏移 = 52*(n+1) - 44 = 52n + 8 = entries 起点 + 48n ─────
 *   entries 起点 = new + 4n + 8，所以新记录正好接在旧记录之后，末尾 48 B 恰好用满
 *   Alloc 的 52(n+1)+4 字节（new + 52n + 8 + 48 == new + 52n + 56）。
 */

/* @0x1ab060 ldr r4, [sp, #0x4] */
/* ── 取号：池字 1ab100 = 0x0024579c → pc 1ab07c + 0x24579c = 0x3f0818 ──
 *   与 AddTile 1ac26c 是**同一个 GOT 槽**（room_maxtileid，.bss 0x542558）。
 */

/* @0x1ab064 ldr r3, [pc, #0x94] */
/* @0x1ab068 ldr r1, [r10] */
/* @0x1ab06c sub r2, r4, #44 */
/* @0x1ab070 ldr r4, [sp, #0x8] */
/* @0x1ab074 ldr r3, [pc, r3] */
/* @0x1ab078 str r10, [r6, #0xc4] */
/* @0x1ab07c add r12, r10, r2 */
/* @0x1ab080 ldr r0, [r3] */
/* ── 写槽：slots[count] = 新记录（r4 = new+4 是槽基址，r1 = [r10] 是旧 count）──
 *   紧接着 1ab094 起回读 [r10]，说明 count 到这一刻还没抬。
 */

/* @0x1ab084 str r12, [r4, r1, lsl #2] */
/* @0x1ab088 ldr r4, [sp, #0xc] */
/* @0x1ab08c add r0, r0, #1 */
/* @0x1ab090 str r0, [r3] */
/* ── 字段落位表（Record = 48 B，按本段实际 store 顺序）────────
 *   +0x08 = p1   1ab098      +0x0c = p2  1ab0a8      +0x10 = p3  1ab0b0
 *   +0x14 = p4   1ab0b8      +0x18 = p5  1ab0c0      +0x1c = p8  1ab0e0
 *   +0x00 = p6   1ab0c8（str r4,[r10,r2]，r2 = 52n+8 正好等于 r12）
 *   +0x04 = p7   1ab0d8
 *   +0x20 = id   1ab0a4（++room_maxtileid，与 AddTile 同源）
 *   +0x24 = p9  float 1ab0cc     +0x28 = p10 float 1ab0d4
 *   +0x2c = p11 uint  1ab0e8
 *   ★ 记录里**没有** depth、没有层、没有链域；与 AddTile 的 56 B 记录相差 8 B，
 *     两套结构是否同源未证（open 1）。
 */

/* @0x1ab094 ldr r3, [r10] */
/* @0x1ab098 str r4, [r12, #0x8] */
/* @0x1ab09c ldr r4, [sp, #0x10] */
/* @0x1ab0a0 add r3, r3, #1 */
/* @0x1ab0a4 str r0, [r12, #0x20] */
/* @0x1ab0a8 str r4, [r12, #0xc] */
/* @0x1ab0ac ldr r4, [sp, #0x14] */
/* @0x1ab0b0 str r4, [r12, #0x10] */
/* @0x1ab0b4 ldr r4, [sp, #0x48] */
/* @0x1ab0b8 str r4, [r12, #0x14] */
/* @0x1ab0bc ldr r4, [sp, #0x4c] */
/* @0x1ab0c0 str r4, [r12, #0x18] */
/* @0x1ab0c4 ldr r4, [sp, #0x50] */
/* @0x1ab0c8 str r4, [r10, r2] */
/* @0x1ab0cc vstr s17, [r12, #36] */
/* @0x1ab0d0 ldr r4, [sp, #0x54] */
/* @0x1ab0d4 vstr s16, [r12, #40] */
/* @0x1ab0d8 str r4, [r12, #0x4] */
/* @0x1ab0dc ldr r4, [sp, #0x58] */
/* @0x1ab0e0 str r4, [r12, #0x1c] */
/* @0x1ab0e4 ldr r4, [sp, #0x64] */
/* @0x1ab0e8 str r4, [r12, #0x2c] */
/* ── count = n+1 → 返回（无返回值；r0 仍是 Alloc 的残留）──
 *   全函数只有这一处抬 count，且排在所有字段写之后 ⇒ 半写状态对读者不可见（单线程前提）。
 */

/* @0x1ab0ec str r3, [r10] */
/* @0x1ab0f0 add sp, sp, #28 */
/* @0x1ab0f4 vpop {d8} */
/* @0x1ab0f8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── literal pool（2 字）─────────────────────────────────
 *   1ab0fc = 0x001a21f8  → pc 1aafb8 + 0x1a21f8 = 0x34d1b0 = Room_Class.cpp
 *   1ab100 = 0x0024579c  → pc 1ab07c + 0x24579c = 0x3f0818 = &room_maxtileid
 */

/* @0x1ab0fc ldrsheq r2, [r10], -r8 */
/* @0x1ab100 mlaeq r4, r12, r7, r5 */
/* ══════════════════════════════════════════════════════════════════
 * 收尾：tile 侧两条路的分工（一句话版）
 * ══════════════════════════════════════════════════════════════════
 *   · AddTile 是**唯一**往 room+0xb8/+0xbc/+0xc0 那张 56 B 表追加记录的入口（全库 2 个调用点：
 *     F_TileAdd 0x11c3f8 与 CRoom::DeSerialise 0x1acc6c）；它改三个房间字段 + 一个全局 + room+0x00。
 *   · AddTileToStorage 只服务 room+0xc4 的 48 B 暂存表（F_RoomTileAdd / F_RoomTileAddExt）：不碰
 *     +0xb8/+0xbc/+0xc0、不写 room+0x00，甚至不返回下标 —— 调用方拿不到「刚存的第几条」。
 *   · 两者共用 room_maxtileid（0x3f0818 → 0x542558）：AddTile 的 ++ 在 DeSerialise 里被逐条抵回，
 *     而 store 版的 ++ **没有任何抵消点** ⇒ 只要存过一条 tile，下一次 AddTile 的号就会跳。
 *   · LoadFromStream / LoadFromChunk 是第三条路：直接写 +0xb8/+0xbc/+0xc0 且不取号（见各自卡），
 *     所以「tile id 只由 AddTile / AddTileToStorage 生产」这句话的边界要按调用者算，不按表算。
 */

