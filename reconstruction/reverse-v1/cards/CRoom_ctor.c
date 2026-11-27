/* cally 逆向卡：CRoom::CRoom（原版 libyoyo.so，armv7）
 * @func 0x1ad2cc 0x1ad70c  size 1088  272 条（0x1ad6f0..0x1ad708 为 literal pool，7 字；objdump 当指令译，实为数据）
 * 级别: 正文（每一格初值、两轮三张哈希图的建立、8 背景 / 8 视野的分配与预置、Clear 之后的重建全部逐条钉住，
 *             并与 CRoom::Clear 0x1ad0a4、CRoom::Assign 0x1ad70c、CRoom::LoadFromChunk 0x1aea3c、
 *             Room_Load 0x1b4cd8（new(292) 的唯一来源）四处交叉印证；
 *             未钉：+0x98 与 +0xe0 这两个被置 1 的 int 的语义、+0x10c 属于哪张表、+0x9c/+0xa0 从未被任何函数写）
 * 符号: _ZN5CRoomC2Ev → CRoom::CRoom()（完整对象构造 C2，无 C1 别名）
 * ABI : softfp；返回 this（0x1ad6e8 mov r0, r4）
 * 同层: CRoom::Clear 0x1ad0a4（构造期内被调用一次，**会释放三张图的桶数组并改写 5 个字段**）、
 *       CRoom::ClearInstances 0x1ab798 / ClearDeactiveInstances 0x1ab9c8 / ClearTiles 0x1ad060
 *       （Clear 的下游）、CLayerManager::CleanRoomLayers 0x1b93c8、CCameraManager::DestroyCamera 0x16f2cc、
 *       MemoryManager::Alloc 0x27ce78、operator new 0x27c524、memset@plt 0xb65b0
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   CRoom 是 292 B（0x124）的对象：三张 20 B 的哈希图占尾部 0xe4/0xf8/0x110，其余是指针/标量。
 *   构造分两段：先把三张图建好、标量清零、8 个背景与 8 个视野各 new 出来；然后调 CRoom::Clear()
 *   —— Clear 释放三张图的桶数组、把房间默认值写进去 —— 再**重新建**三张图。所以最终能用的三张图
 *   是 Clear 之后那一轮，前一轮 3×1536 B 建完就被拆掉。
 *
 * ── 对象布局（0x00..0x123，单位 B）──────────────────────────────
 *   0x00..0x0c   CRoom 头部标量（+0x00 最近 tile 下标、+0x04 自指、+0x08 名字串、+0x0c speed）
 *   0x10..0x20   宽 / 高 / 一个 byte / uint32 背景色 / 一个 byte
 *   0x24..0x40   8 × ptr → 44 B 背景记录
 *   0x44..0x46   3 × byte 房间标志
 *   0x48..0x64   8 × ptr → 68 B 视野记录
 *   0x68..0x7c   第二串 / 3D 头四格
 *   0x80..0x98   实例链 A（尾/头/计数）+ 实例链 B（尾/头/计数）+ 一个 int
 *   0x9c..0xb0   未定区（+0xa4/+0xa8 id 数组、+0xac 容器、+0xb0 影子格）
 *   0xb4..0xc0   CPhysicsWorld* + tile 表三格
 *   0xc4..0xdc   两张 WAD 指针表 + 房间名 + 深/浅开关 + 层链三格
 *   0xe0         int（构造置 1）
 *   0xe4..0xf7   哈希图 1（20 B）
 *   0xf8..0x10b  哈希图 2（20 B）
 *   0x10c        int（本函数不写，Clear 置 0）
 *   0x110..0x123 哈希图 3（20 B）
 *   校验：0x110 + 0x14 = 0x124 = 292 = Room_Load 0x1b4ebc 的 `mov r0, #292`。
 *
 * ── 字段初值表（本函数写的每一格；"Clear 后" = 构造返回时的实际值）─────────
 *   偏移     类型      本函数初值                   Clear 后        说明
 *   -------  --------  ---------------------------  --------------  --------------------------------
 *   +0x00    int       0                            （ClearTiles 会写 -1）最近 tile 下标
 *   +0x04    CRoom*    this（自指，stm 一次性写）   不变            仅本函数写；Assign 不搬
 *   +0x08    char*     0                            0               名字串（Clear 只清不 Free）
 *   +0x0c    int       0                            30              speed
 *   +0x10    int       0                            640             宽
 *   +0x14    int       0                            480             高
 *   +0x18    byte      0                            0               bool
 *   +0x1c    uint32    0                            0x00C0C0C0      背景色（movw/movt 0xc0c0/0xc0）
 *   +0x20    byte      0                            1               bool
 *   +0x24    ptr[8]    8 × operator new(44)         记录体由 Clear 初始化   背景记录指针
 *   +0x40    ↑ 末格
 *   +0x44    byte      0                            0               标志
 *   +0x45    byte      1                            0               标志
 *   +0x46    byte      1                            0               标志
 *   +0x48    ptr[8]    8 × operator new(68)         记录体由 Clear 初始化   视野记录指针
 *   +0x64    ↑ 末格
 *   +0x68    char*     0                            0               第二串
 *   +0x6c    int       0                            0
 *   +0x70    byte      ——（不写）                   0               3D 头字段（LoadFromChunk 才给值）
 *   +0x74    int       不写                         ——              只在 LoadFromChunk 3D 分支写 ★未初始化
 *   +0x78    int       不写                         ——              同上 ★未初始化
 *   +0x7c    int       不写                         ——              同上 ★未初始化
 *   +0x80    ptr       0                            0               实例链 A 尾
 *   +0x84    ptr       0                            0               实例链 A 头
 *   +0x88    int       0                            0               实例链 A 计数
 *   +0x8c    ptr       0                            0               实例链 B 尾
 *   +0x90    ptr       0                            0               实例链 B 头
 *   +0x94    int       0                            0               实例链 B 计数
 *   +0x98    int       1                            ——              语义未定（只有本函数写 1）★
 *   +0x9c    int       不写                         ——              ★从未被本函数/Clear 写
 *   +0xa0    int       不写                         ——              ★同上
 *   +0xa4    ptr       0                            0               id 数组（Clear 先 Free 再清）
 *   +0xa8    int       0                            0               id 计数
 *   +0xac    ptr       不写                         0               容器（chunk 路径 = YYRoom*）
 *   +0xb0    ptr       不写                         ——              影子格（chunk 路径 = WAD 基址）★未初始化
 *   +0xb4    ptr       0                            ——              CPhysicsWorld*
 *   +0xb8    int       0                            ——              RTile 计数
 *   +0xbc    int       0                            ——              RTile 容量
 *   +0xc0    ptr       0                            ——              RTile 数据
 *   +0xc4    ptr       不写                         0               WAD tile 指针表
 *   +0xc8    ptr       不写                         0               WAD 记录指针表
 *   +0xcc    char*     0                            ——              房间名（chunk 路径）
 *   +0xd0    byte      0                            ——              tile 容器 深/浅 开关
 *   +0xd4    ptr       0                            ——              层链
 *   +0xd8    ptr       0                            ——              层链
 *   +0xdc    int       0                            ——              层链
 *   +0xe0    int       1                            ——              语义未定（紧邻哈希图 1）★
 *   +0xe4    CHashMap  见下表                       桶数组被 Clear 释放后重建   图 1
 *   +0xf8    CHashMap  见下表                       同上            图 2
 *   +0x10c   int       不写                         0               未定（20 B 图之后多出的一格）
 *   +0x110   CHashMap  见下表                       同上            图 3
 *
 * ── 哈希图布局与初始化（三张完全同构，参数一致）──────────────────
 *   +0x00  int  capacity  = 128
 *   +0x04  int  count     = 0
 *   +0x08  int  mask      = capacity-1 = 127
 *   +0x0c  int  threshold = (int)(capacity * 0.6f) = 76（0.6f = 0x3f19999a，vcvt.s32 截断）
 *   +0x10  ptr  buckets   = Alloc(1536) + memset 0；1536 = 128 × 12 ⇒ 桶 12 B
 *   每轮建完还会把 128 个桶的 +0x08 各清 0（12 B 步长循环）—— 与 memset 重复，是源码里 Reset 的痕迹。
 *   Alloc 的四个实参：r0 = 1536、r1 = "jni/../jni/yoyo/../../../Platform/MemoryManager.h"、r2 = 70、r3 = 1。
 *
 * ── 构造顺序（不可换；换了就是空指针）────────────────────────────
 *   ① 建图 1（0x1ad334 Alloc）→ ② 建图 2（0x1ad3bc）→ ③ 建图 3（0x1ad444）
 *   ④ 标量清零 + 两个 1（0x1ad4a0..0x1ad4f4）→ ⑤ 8 × new(44) 背景（0x1ad4f8..0x1ad510）
 *   ⑥ 8 × new(68) 视野，每格 +0x3c/+0x40 预置 -1（0x1ad514..0x1ad540）
 *   ⑦ tile 三格清零（0x1ad544..0x1ad554）→ ⑧ CRoom::Clear()（0x1ad558）
 *   ⑨ 重建图 1（0x1ad590）→ ⑩ 重建图 2（0x1ad614）→ ⑪ 重建图 3（0x1ad698）→ 返回 this
 *   ★ ⑧ 的 Clear 先在 0x1ad264/0x1ad274/0x1ad28c 读 +0xf4/+0x108/+0x120，再在 0x1ad270/0x1ad288/0x1ad2a4 三处 bl Free 并把三格置 0，
 *     同时把 +0xc/+0x10/+0x14/+0x1c/+0x20 改成 30/640/480/0x00C0C0C0/1，+0x8/+0x68/+0x70/+0xac/+0xc4/+0xc8 清 0。
 *     ⇒ ①..③ 与 ④ 里写的那几格全部被覆盖，前 3×1536 B 全部被释放：净效果等价于「Clear 之后再建三张图」。
 *   ★ 若照抄成「Clear 之后不重建」，三张图的 buckets 会是 NULL 而 capacity 仍是 128 → 首次插入必崩。
 *
 * ── 视野记录的 -1 预置 ──────────────────────────────────────────
 *   0x1ad534/0x1ad538 把新视野记录的 +0x3c 与 +0x40 都写成 -1：
 *   +0x40 是相机 id 槽，Clear 会对它调 CCameraManager::DestroyCamera(-1) 再清 0；
 *   +0x3c 全库没有别的写入者（LoadFromChunk 也不写它），构造后恒为 -1。
 *
 * ── 未定（open）──────────────────────────────────────────────────
 *   1. +0x98 = 1 与 +0xe0 = 1 的语义：两者都是 int，除本函数外已索引函数里没有写入者。
 *   2. +0x10c 这一格（图 2 与图 3 之间）只有 Clear 写 0；它是否属于某张图的第 6 字段未证（三张图各 20 B 时它多出来）。
 *   3. +0x9c/+0xa0 从未被本函数与 Clear 写；若 operator new 不清零，构造后是脏值（谁读它们未证）。
 *   4. +0x74/+0x78/+0x7c（3D 头）与 +0xb0 同样未初始化 —— 只在 LoadFromChunk 的 3D/物理分支里才被写。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 入口：先建三张哈希图的第一轮（0x1ad2cc..0x1ad350）──────────
 *   帧：push {r3,r4,r5,r6,r7,lr}；r4 = this、r5 = 0、r1 = 1、r2 = 128、r3 = 127。
 *   这一段的 store 全用 r0（此时 r0 == this）；0x1ad300 起切到 r4。
 */


/* @0x1ad2cc push {r3, r4, r5, r6, r7, lr} */
/* @0x1ad2d0 mov r1, #1 */
/* @0x1ad2d4 mov r4, r0 */
/* @0x1ad2d8 mov r5, #0 */
/* @0x1ad2dc mov r2, #128 */
/* @0x1ad2e0 str r5, [r0, #0x84] */
/* @0x1ad2e4 str r2, [r0, #0xe4] */
/* @0x1ad2e8 mov r3, #127 */
/* @0x1ad2ec str r3, [r0, #0xec] */
/* @0x1ad2f0 mov r3, r1 */
/* @0x1ad2f4 str r1, [r4, #0x98] */
/* @0x1ad2f8 mov r2, #70 */
/* @0x1ad2fc str r1, [r4, #0xe0] */
/* @0x1ad300 mov r0, #1536 */
/* @0x1ad304 ldr r1, [pc, #0x3e8] */
/* @0x1ad308 str r5, [r4, #0x80] */
/* @0x1ad30c add r1, pc, r1 */
/* @0x1ad310 str r5, [r4, #0x88] */
/* @0x1ad314 str r5, [r4, #0x90] */
/* @0x1ad318 str r5, [r4, #0x8c] */
/* @0x1ad31c str r5, [r4, #0x94] */
/* @0x1ad320 str r5, [r4, #0xbc] */
/* @0x1ad324 str r5, [r4, #0xc0] */
/* @0x1ad328 str r5, [r4, #0xd8] */
/* @0x1ad32c str r5, [r4, #0xd4] */
/* @0x1ad330 str r5, [r4, #0xdc] */
/* @0x1ad334 str r5, [r4, #0xf4] */
/* @0x1ad338 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad33c mov r2, #1536 */
/* @0x1ad340 mov r1, r5 */
/* @0x1ad344 str r0, [r4, #0xf4] */
/* @0x1ad348 bl 0xb65b0 <memset@plt> */
/* @0x1ad34c ldr r2, [r4, #0xe4] */
/* @0x1ad350 vldr s15, [pc, #920] */

/* ── 图 1 的收尾：count / threshold / 清桶（0x1ad354..0x1ad38c）─────
 *   0x1ad350 vldr s15 = 0.6f（字面量 0x3f19999a）；0x1ad35c..0x1ad368 把 128 转 float、乘 0.6、截断成 76；
 *   0x1ad36c vstr 到 +0xf0（threshold）；+0xe8（count）= 0；0x1ad380 的循环按 12 B 步长把每桶 +0x08 清 0。
 */

/* @0x1ad354 str r5, [r4, #0xe8] */
/* @0x1ad358 cmp r2, r5 */
/* @0x1ad35c vmov s13, r2 */
/* @0x1ad360 vcvt.f32.s32 s14, s13 */
/* @0x1ad364 vmul.f32 s15, s14, s15 */
/* @0x1ad368 vcvt.s32.f32 s15, s15 */
/* @0x1ad36c vstr s15, [r4, #240] */
/* @0x1ad370 ble 0x1ad390 <_ZN5CRoomC2Ev+0xc4> */
/* @0x1ad374 add r2, r2, r2, lsl #1 */
/* @0x1ad378 ldr r3, [r4, #0xf4] */
/* @0x1ad37c add r2, r3, r2, lsl #2 */
/* @0x1ad380 str r5, [r3, #0x8] */
/* @0x1ad384 add r3, r3, #12 */
/* @0x1ad388 cmp r3, r2 */
/* @0x1ad38c bne 0x1ad380 <_ZN5CRoomC2Ev+0xb4> */

/* ── 图 2（0x1ad390..0x1ad414）───────────────────────────────────
 *   与图 1 同构：+0xf8 = 128、+0x100 = 127、+0x108 = Alloc(1536)、+0xfc = 0、+0x104 = 76。
 *   注意 0x1ad3a4 的 add 用的是 pc 0x1ad3ac，字面量 0x183c8c → 0x331038（同一个 MemoryManager.h）。
 */

/* @0x1ad390 ldr r1, [pc, #0x360] */
/* @0x1ad394 mov r5, #0 */
/* @0x1ad398 mov r2, #128 */
/* @0x1ad39c mov r3, #127 */
/* @0x1ad3a0 str r2, [r4, #0xf8] */
/* @0x1ad3a4 add r1, pc, r1 */
/* @0x1ad3a8 str r3, [r4, #0x100] */
/* @0x1ad3ac mov r2, #70 */
/* @0x1ad3b0 mov r3, #1 */
/* @0x1ad3b4 str r5, [r4, #0x108] */
/* @0x1ad3b8 mov r0, #1536 */
/* @0x1ad3bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad3c0 mov r2, #1536 */
/* @0x1ad3c4 mov r1, r5 */
/* @0x1ad3c8 str r0, [r4, #0x108] */
/* @0x1ad3cc bl 0xb65b0 <memset@plt> */
/* @0x1ad3d0 ldr r2, [r4, #0xf8] */
/* @0x1ad3d4 vldr s15, [pc, #788] */
/* @0x1ad3d8 str r5, [r4, #0xfc] */
/* @0x1ad3dc cmp r2, r5 */
/* @0x1ad3e0 vmov s13, r2 */
/* @0x1ad3e4 vcvt.f32.s32 s14, s13 */
/* @0x1ad3e8 vmul.f32 s15, s14, s15 */
/* @0x1ad3ec vcvt.s32.f32 s15, s15 */
/* @0x1ad3f0 vstr s15, [r4, #260] */
/* @0x1ad3f4 ble 0x1ad418 <_ZN5CRoomC2Ev+0x14c> */
/* @0x1ad3f8 add r2, r2, r2, lsl #1 */
/* @0x1ad3fc ldr r3, [r4, #0x108] */
/* @0x1ad400 mov r1, r5 */
/* @0x1ad404 add r2, r3, r2, lsl #2 */
/* @0x1ad408 str r1, [r3, #0x8] */
/* @0x1ad40c add r3, r3, #12 */
/* @0x1ad410 cmp r3, r2 */
/* @0x1ad414 bne 0x1ad408 <_ZN5CRoomC2Ev+0x13c> */

/* ── 图 3（0x1ad418..0x1ad49c）───────────────────────────────────
 *   +0x110 = 128、+0x118 = 127、+0x120 = Alloc(1536)、+0x114 = 0、+0x11c = 76。
 *   三张图全部建成之后才动标量域。
 */

/* @0x1ad418 ldr r1, [pc, #0x2dc] */
/* @0x1ad41c mov r5, #0 */
/* @0x1ad420 mov r2, #128 */
/* @0x1ad424 mov r3, #127 */
/* @0x1ad428 str r2, [r4, #0x110] */
/* @0x1ad42c add r1, pc, r1 */
/* @0x1ad430 str r3, [r4, #0x118] */
/* @0x1ad434 mov r2, #70 */
/* @0x1ad438 mov r3, #1 */
/* @0x1ad43c str r5, [r4, #0x120] */
/* @0x1ad440 mov r0, #1536 */
/* @0x1ad444 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad448 mov r2, #1536 */
/* @0x1ad44c mov r1, r5 */
/* @0x1ad450 str r0, [r4, #0x120] */
/* @0x1ad454 bl 0xb65b0 <memset@plt> */
/* @0x1ad458 ldr r2, [r4, #0x110] */
/* @0x1ad45c vldr s15, [pc, #652] */
/* @0x1ad460 str r5, [r4, #0x114] */
/* @0x1ad464 cmp r2, r5 */
/* @0x1ad468 vmov s13, r2 */
/* @0x1ad46c vcvt.f32.s32 s14, s13 */
/* @0x1ad470 vmul.f32 s15, s14, s15 */
/* @0x1ad474 vcvt.s32.f32 s15, s15 */
/* @0x1ad478 vstr s15, [r4, #284] */
/* @0x1ad47c ble 0x1ad4a0 <_ZN5CRoomC2Ev+0x1d4> */
/* @0x1ad480 add r2, r2, r2, lsl #1 */
/* @0x1ad484 ldr r3, [r4, #0x120] */
/* @0x1ad488 mov r1, r5 */
/* @0x1ad48c add r2, r3, r2, lsl #2 */
/* @0x1ad490 str r1, [r3, #0x8] */
/* @0x1ad494 add r3, r3, #12 */
/* @0x1ad498 cmp r3, r2 */
/* @0x1ad49c bne 0x1ad490 <_ZN5CRoomC2Ev+0x1c4> */

/* ── 标量域清零（0x1ad4a0..0x1ad4f4）─────────────────────────────
 *   0x1ad4b0 stm r4,{r3,r4} 是整个函数唯一的双字写：[+0x00] = 0、[+0x04] = this。
 *   随后按编译器排的顺序（不是偏移序）写 +0x08/+0x0c/+0x10/+0x14/+0x18/+0x1c/+0x20、
 *   +0x44/+0x68/+0x6c/+0xa4/+0xa8/+0xd0/+0xcc/+0xb4，最后把 +0x45/+0x46 置 1（r2 = 1）。
 *   ★ +0x74/+0x78/+0x7c/+0x9c/+0xa0/+0xb0/+0xc4/+0xc8/+0xac 在这一段里**没有**被写。
 */

/* @0x1ad4a0 mov r3, #0 */
/* @0x1ad4a4 mov r5, r4 */
/* @0x1ad4a8 mov r6, r3 */
/* @0x1ad4ac mov r2, #1 */
/* @0x1ad4b0 stm r4, {r3, r4} */
/* @0x1ad4b4 str r3, [r4, #0x8] */
/* @0x1ad4b8 str r3, [r4, #0xc] */
/* @0x1ad4bc str r3, [r4, #0x10] */
/* @0x1ad4c0 str r3, [r4, #0x14] */
/* @0x1ad4c4 strb r3, [r4, #0x18] */
/* @0x1ad4c8 str r3, [r4, #0x1c] */
/* @0x1ad4cc strb r3, [r4, #0x20] */
/* @0x1ad4d0 strb r3, [r4, #0x44] */
/* @0x1ad4d4 str r3, [r4, #0x68] */
/* @0x1ad4d8 str r3, [r4, #0x6c] */
/* @0x1ad4dc str r3, [r4, #0xa4] */
/* @0x1ad4e0 str r3, [r4, #0xa8] */
/* @0x1ad4e4 strb r3, [r4, #0xd0] */
/* @0x1ad4e8 str r3, [r4, #0xcc] */
/* @0x1ad4ec str r3, [r4, #0xb4] */
/* @0x1ad4f0 strb r2, [r4, #0x45] */
/* @0x1ad4f4 strb r2, [r4, #0x46] */

/* ── 8 个背景记录：new(44)（0x1ad4f8..0x1ad510）─────────────────
 *   循环计数 r6 = 1..8，r5 从 this 起每次 +4，store 用 [r5,#0x20] ⇒ 落点 this+0x24+i*4。
 *   记录体（44 B）本函数一格都不写，全部由后面的 Clear 初始化。
 */

/* @0x1ad4f8 mov r0, #44 */
/* @0x1ad4fc add r6, r6, #1 */
/* @0x1ad500 bl 0x27c524 <_Znwj> */
/* @0x1ad504 cmp r6, #8 */
/* @0x1ad508 add r5, r5, #4 */
/* @0x1ad50c str r0, [r5, #0x20] */
/* @0x1ad510 bne 0x1ad4f8 <_ZN5CRoomC2Ev+0x22c> */

/* ── 8 个视野记录：new(68)，+0x3c/+0x40 预置 -1（0x1ad514..0x1ad540）──
 *   r7 = -1；落点 this+0x48+i*4（[r6,#0x44]，r6 从 this 起每次 +4）。
 *   +0x3c 全库只有这里写；+0x40 是相机 id，Clear 会 DestroyCamera([+0x40]) 之后清 0。
 */

/* @0x1ad514 mov r6, r4 */
/* @0x1ad518 mov r5, #0 */
/* @0x1ad51c mvn r7, #0 */
/* @0x1ad520 mov r0, #68 */
/* @0x1ad524 add r5, r5, #1 */
/* @0x1ad528 bl 0x27c524 <_Znwj> */
/* @0x1ad52c cmp r5, #8 */
/* @0x1ad530 add r6, r6, #4 */
/* @0x1ad534 str r7, [r0, #0x3c] */
/* @0x1ad538 str r7, [r0, #0x40] */
/* @0x1ad53c str r0, [r6, #0x44] */
/* @0x1ad540 bne 0x1ad520 <_ZN5CRoomC2Ev+0x254> */

/* ── tile 三格清零 + CRoom::Clear()（0x1ad544..0x1ad558）──────────
 *   Clear 是构造期唯一的外部调用（0x1ad0a4）：它释放三张图的桶数组、把房间默认值写进 +0xc/+0x10/+0x14/+0x1c/+0x20，
 *   并把 8 个背景/8 个视野的记录体初始化。**这一段之后 +0xf4/+0x108/+0x120 全为 0**。
 */

/* @0x1ad544 mov r5, #0 */
/* @0x1ad548 mov r0, r4 */
/* @0x1ad54c str r5, [r4, #0xbc] */
/* @0x1ad550 str r5, [r4, #0xc0] */
/* @0x1ad554 str r5, [r4, #0xb8] */
/* @0x1ad558 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */

/* ── 第二轮：重建图 1（0x1ad55c..0x1ad5dc）───────────────────────
 *   0x1ad55c 重新读 [+0xe4]（仍是 128，Clear 不改 capacity）→ 0x1ad578 写回 mask、
 *   0x1ad590 写回新 Alloc 的桶数组、0x1ad5a0 count = 0、0x1ad5b8 threshold = 76、再清一遍桶。
 */

/* @0x1ad55c ldr r0, [r4, #0xe4] */
/* @0x1ad560 ldr r1, [pc, #0x198] */
/* @0x1ad564 mov r2, #70 */
/* @0x1ad568 sub r12, r0, #1 */
/* @0x1ad56c mov r3, #1 */
/* @0x1ad570 add r0, r0, r0, lsl #1 */
/* @0x1ad574 add r1, pc, r1 */
/* @0x1ad578 str r12, [r4, #0xec] */
/* @0x1ad57c lsl r6, r0, #2 */
/* @0x1ad580 mov r0, r6 */
/* @0x1ad584 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad588 mov r2, r6 */
/* @0x1ad58c mov r1, r5 */
/* @0x1ad590 str r0, [r4, #0xf4] */
/* @0x1ad594 bl 0xb65b0 <memset@plt> */
/* @0x1ad598 ldr r2, [r4, #0xe4] */
/* @0x1ad59c vldr s15, [pc, #332] */
/* @0x1ad5a0 str r5, [r4, #0xe8] */
/* @0x1ad5a4 cmp r2, r5 */
/* @0x1ad5a8 vmov s13, r2 */
/* @0x1ad5ac vcvt.f32.s32 s14, s13 */
/* @0x1ad5b0 vmul.f32 s15, s14, s15 */
/* @0x1ad5b4 vcvt.s32.f32 s15, s15 */
/* @0x1ad5b8 vstr s15, [r4, #240] */
/* @0x1ad5bc ble 0x1ad5e0 <_ZN5CRoomC2Ev+0x314> */
/* @0x1ad5c0 add r2, r2, r2, lsl #1 */
/* @0x1ad5c4 ldr r3, [r4, #0xf4] */
/* @0x1ad5c8 mov r1, r5 */
/* @0x1ad5cc add r2, r3, r2, lsl #2 */
/* @0x1ad5d0 str r1, [r3, #0x8] */
/* @0x1ad5d4 add r3, r3, #12 */
/* @0x1ad5d8 cmp r3, r2 */
/* @0x1ad5dc bne 0x1ad5d0 <_ZN5CRoomC2Ev+0x304> */

/* ── 第二轮：重建图 2（0x1ad5e0..0x1ad660）与图 3（0x1ad664..0x1ad6e4）──
 *   与图 1 同序：读 [+0xf8]/[+0x110] → mask → Alloc → count=0 → threshold=76 → 清桶。
 *   0x1ad6e8 mov r0,r4 返回 this。
 */

/* @0x1ad5e0 ldr r0, [r4, #0xf8] */
/* @0x1ad5e4 mov r2, #70 */
/* @0x1ad5e8 ldr r1, [pc, #0x114] */
/* @0x1ad5ec mov r3, #1 */
/* @0x1ad5f0 sub r12, r0, #1 */
/* @0x1ad5f4 str r12, [r4, #0x100] */
/* @0x1ad5f8 add r0, r0, r0, lsl #1 */
/* @0x1ad5fc add r1, pc, r1 */
/* @0x1ad600 lsl r5, r0, #2 */
/* @0x1ad604 mov r0, r5 */
/* @0x1ad608 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad60c mov r2, r5 */
/* @0x1ad610 mov r1, #0 */
/* @0x1ad614 str r0, [r4, #0x108] */
/* @0x1ad618 bl 0xb65b0 <memset@plt> */
/* @0x1ad61c ldr r2, [r4, #0xf8] */
/* @0x1ad620 vldr s15, [pc, #200] */
/* @0x1ad624 mov r1, #0 */
/* @0x1ad628 cmp r2, r1 */
/* @0x1ad62c str r1, [r4, #0xfc] */
/* @0x1ad630 vmov s13, r2 */
/* @0x1ad634 vcvt.f32.s32 s14, s13 */
/* @0x1ad638 vmul.f32 s15, s14, s15 */
/* @0x1ad63c vcvt.s32.f32 s15, s15 */
/* @0x1ad640 vstr s15, [r4, #260] */
/* @0x1ad644 ble 0x1ad664 <_ZN5CRoomC2Ev+0x398> */
/* @0x1ad648 add r2, r2, r2, lsl #1 */
/* @0x1ad64c ldr r3, [r4, #0x108] */
/* @0x1ad650 add r2, r3, r2, lsl #2 */
/* @0x1ad654 str r1, [r3, #0x8] */
/* @0x1ad658 add r3, r3, #12 */
/* @0x1ad65c cmp r3, r2 */
/* @0x1ad660 bne 0x1ad654 <_ZN5CRoomC2Ev+0x388> */
/* @0x1ad664 ldr r0, [r4, #0x110] */
/* @0x1ad668 mov r2, #70 */
/* @0x1ad66c ldr r1, [pc, #0x94] */
/* @0x1ad670 mov r3, #1 */
/* @0x1ad674 sub r12, r0, #1 */
/* @0x1ad678 str r12, [r4, #0x118] */
/* @0x1ad67c add r0, r0, r0, lsl #1 */
/* @0x1ad680 add r1, pc, r1 */
/* @0x1ad684 lsl r5, r0, #2 */
/* @0x1ad688 mov r0, r5 */
/* @0x1ad68c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ad690 mov r2, r5 */
/* @0x1ad694 mov r1, #0 */
/* @0x1ad698 str r0, [r4, #0x120] */
/* @0x1ad69c bl 0xb65b0 <memset@plt> */
/* @0x1ad6a0 ldr r2, [r4, #0x110] */
/* @0x1ad6a4 vldr s15, [pc, #68] */
/* @0x1ad6a8 mov r1, #0 */
/* @0x1ad6ac cmp r2, r1 */
/* @0x1ad6b0 str r1, [r4, #0x114] */
/* @0x1ad6b4 vmov s13, r2 */
/* @0x1ad6b8 vcvt.f32.s32 s14, s13 */
/* @0x1ad6bc vmul.f32 s15, s14, s15 */
/* @0x1ad6c0 vcvt.s32.f32 s15, s15 */
/* @0x1ad6c4 vstr s15, [r4, #284] */
/* @0x1ad6c8 ble 0x1ad6e8 <_ZN5CRoomC2Ev+0x41c> */
/* @0x1ad6cc add r2, r2, r2, lsl #1 */
/* @0x1ad6d0 ldr r3, [r4, #0x120] */
/* @0x1ad6d4 add r2, r3, r2, lsl #2 */
/* @0x1ad6d8 str r1, [r3, #0x8] */
/* @0x1ad6dc add r3, r3, #12 */
/* @0x1ad6e0 cmp r3, r2 */
/* @0x1ad6e4 bne 0x1ad6d8 <_ZN5CRoomC2Ev+0x40c> */
/* @0x1ad6e8 mov r0, r4 */
/* @0x1ad6ec pop {r3, r4, r5, r6, r7, pc} */

/* ── literal pool（0x1ad6f0..0x1ad708，7 字；非指令）────────────
 *   0x1ad6f0 0x3f19999a  0.6f（图 1/2/3 的 threshold 乘数，三处 vldr 都指向它）
 *   0x1ad6f4 0x00183d24 + pc 0x1ad314 = 0x331038  ".../Platform/MemoryManager.h"
 *   0x1ad6f8 0x00183c8c + pc 0x1ad3ac = 0x331038  同一串
 *   0x1ad6fc 0x00183c04 + pc 0x1ad434 = 0x331038  同一串
 *   0x1ad700 0x00183abc + pc 0x1ad57c = 0x331038  同一串
 *   0x1ad704 0x00183a34 + pc 0x1ad604 = 0x331038  同一串
 *   0x1ad708 0x001839b0 + pc 0x1ad688 = 0x331038  同一串
 */

/* @0x1ad6f0 svclo #0x19999a */
/* @0x1ad6f4 andseq r3, r8, r4, lsr #26 */
/* @0x1ad6f8 andseq r3, r8, r12, lsl #25 */
/* @0x1ad6fc andseq r3, r8, r4, lsl #24 */
/* @0x1ad700 ldrheq r3, [r8], -r12 */
/* @0x1ad704 andseq r3, r8, r4, lsr r10 */
/* @0x1ad708 ldrheq r3, [r8], -r0 */
