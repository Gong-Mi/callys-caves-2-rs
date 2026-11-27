/* cally 逆向卡：DuplicateRoomLayers（原版 libyoyo.so，armv7）
 * @func 0x1c47e0 0x1c5a34  size 4692  1171 条（1173 字 - 1c4c58/1c4c5c 两个字对齐空洞；
 *       1c4c60..1c4ccc 是 28 字字面量池，objdump 按 ARM 指令译码显示，不是指令）
 * 级别: 骨架（房间层链、CLayer 112 字节、7 类元素 32..80 字节的偏移表、池的扩容/弹出协议、
 *             7 路 switch 的逐类拷贝清单、五处新分配深拷贝、名字串的 MemoryInWad 深浅分叉、
 *             层尾插与 CHashMap 插入 全部逐条落锚；未钉：后两个 CHashMap 的用途、
 *             CLayer 的 +0x2c/+0x5c/+0x60/+0x64 语义、AddElementToLayer 内部、
 *             类型 2/3/6 的 GML 侧名字 —— 故不升正文）
 * 符号: _ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_
 *       → CLayerManager::DuplicateRoomLayers(CRoom*, CRoom*)
 * 同层: CleanRoomLayers 0x1b93c8、InsertLayerIntoActiveList 0x1c30f8、AddElementToLayer 0x1c451c、
 *       AddNewElement 0x1c5ff0、DeSerializeLayer 0x1c74d0、GetNewBackgroundElement 0x1c0bd8、
 *       GetNewSpriteElement 0x1c0f00、GetNewTilemapElement 0x1c1034、MemoryInWad 0x1aad50、
 *       CHashMap<int,CLayer*,7>::Insert 0x1c2a90、DoSlowDrawRoom 0x1b06a0（绘制侧读同一房间）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把源房间的「层（CLayer）+ 层内元素」整套复制到目标房间：先 CleanRoomLayers 清目标、
 *   重建目标的三张 CHashMap，再沿源层链（room+0xd4，next 在 +0x68）逐层克隆；每层从
 *   该类自己的全局池取对象、按偏移逐字段填（层名有一次深拷贝分叉），再沿源层元素链
 *   （layer+0x58，next 在 +0x14）逐元素按 type 分派克隆；最后把新层尾插进目标层链并
 *   插进第一张 map。
 *
 * ── 尺寸先说清楚：层不是 56 字节 ─────────────────────────────────
 *   CLayer           = 112 字节（0x70）。池对象，Alloc 记录写 112 / "Room_Layers.h" / 行 70
 *                      （ctor 内联在头文件里，所以站点串是 .h 而不是 .cpp）
 *   元素类           = 32 / 36 / 52 / 60 / 72 / 80 字节（见下表），全部来自同一个头文件的池
 *   CRoom+0xb8/+0xc0 = 56 字节步长的「层项记录」数组，是绘制侧（DoSlowDrawRoom）读的那一份；
 *                      本函数一次都没读它（全函数无 0xb8/0xc0 访问），两者不是同一种东西。
 *                      depth 在 +0x1c 是那条 56 字节记录的语义，不是 CLayer 的。
 *
 * ── CLayer（112 字节）字段表：两个函数互相坐实 ────────────────────
 *   +0x00 int    id                 ← 层链插入 map 的键（本函数 1c4f24）
 *   +0x04 int                       ← DeSerialize 第 3 字段
 *   +0x08 float                     ← DeSerialize 第 4 字段
 *   +0x0c float                     ← 第 5
 *   +0x10 float                     ← 第 6
 *   +0x14 float                     ← 第 7
 *   +0x18 byte  bool（ctor 初值 1）  ← 第 8
 *   +0x19 byte  bool（ctor 初值 0）  ← 第 9；★ 本函数不搬（新层保持 0）
 *   +0x1c char* name                ← 第 2 字段（ReadString）；本函数按归属做深/浅分叉
 *   +0x20 int（ctor -1）             ← 第 10
 *   +0x24 int（ctor -1）             ← 第 11
 *   +0x28 int（ctor -1）             ← 第 12
 *   +0x2c 未读（两个函数都不碰）
 *   +0x30 CTimingSource（40 字节，+0x48 处是 8 字节 0.0 双精度）；ctor 只 Reset，本函数不复制
 *   +0x58 元素链头（AddElementToLayer 维护）
 *   +0x5c / +0x60 ctor 置 0，语义未证
 *   +0x64 int，ctor 置 1，语义未证
 *   +0x68 next（房间层链）
 *   +0x6c prev
 *
 * ── 池协议（层池、7 个元素池、1804 字节块池共用一套）─────────────
 *   池头：+0x00 链头  +0x04 链尾  +0x08 可用数  +0x10 容量（+0x0c 空着）
 *   节点链接：层用 +0x68(next)/+0x6c(prev)；元素用 +0x14(next)/+0x18(prev)；
 *            1804 字节块用 +0x704(next)/+0x708(prev)；1792 载荷在块 +0x00..0x6ff
 *   取用 = 链头弹出；用完 = **插回链头（LIFO）**；可用数为 0 时一次分配「容量」个，然后容量翻倍。
 *   ⚠ 修正（batchBD，cards/CLayerManager_Build.c 0x1c4ad4 处逐字相同）：早先写「尾插压回」是错的。
 *   空闲节点把「活链的 next/prev 字段」直接当自由链用（同一对偏移，两用）。
 *
 * ── 7 类元素：尺寸、初值、拷贝清单（源偏移 = 目标偏移）─────────────
 *   type 1 background  0x20  拷 +0x04 +0x0c +0x1c   + 深拷贝 44B 子对象（13 字段）
 *                            GetNewBackgroundElement 实证：Alloc 32 + type = 1
 *   type 2             0x24  拷 +0x04 +0x0c +0x1c   无嵌套
 *   type 3             0x34  拷 +0x04；+0x08 = 1；+0x1c = 深拷贝记录数组；
 *                            +0x24/+0x28/+0x2c = 新建的 1792B 块链（不搬源值）
 *   type 4 sprite      0x48  拷 13 个裸字 +0x04 +0x0c +0x1c +0x20 +0x24 +0x28 +0x2c
 *                            +0x30 +0x34 +0x38 +0x3c +0x40 +0x44   GetNewSpriteElement: 72/type 4
 *   type 5 tilemap     0x3c  拷 8 个裸字 + 深拷贝 +0x34 像素（w*h*4）
 *                            GetNewTilemapElement: 60/type 5；★ +0x38 不拷
 *   type 6             0x20  拷 +0x04 +0x0c +0x1c   无嵌套
 *   type 7             0x50  拷 15 个裸字 +0x04 +0x0c +0x1c(字节) +0x20 +0x24 +0x28
 *                            +0x2c +0x30 +0x34 +0x38 +0x3c +0x40 +0x44 +0x48 +0x4c
 *   共同的元素头：+0x00 type、+0x04 int(ctor -1)、+0x08 byte(ctor 1)、+0x0c int、+0x10 int、
 *   +0x14 next、+0x18 prev；>=+0x1c 由各子类自己定义（所以「+0x1c 是什么」按类不同：
 *   类型 1 是子对象指针、类型 3 是记录数组指针、类型 7 是字节、类型 5 是 int）
 *
 * ── 深拷贝 / 浅拷贝边界（本卡的核心结论）─────────────────────────
 *   深（新分配 + 内容复制）共 5 处：
 *     1) 层名：仅在 MemoryInWad(name) == 0 时；wad 内的名字改为共享指针（1c4bf4 分叉）
 *     2) type 1 的 +0x1c → 44 字节子对象，逐 13 字段搬（Room_Layers.cpp 行 608）
 *     3) type 3 的 +0x1c → n*52+4 的记录块，源侧 n 个 48 字节节点压平复制
 *     4) type 3 的 +0x24 链 → 每个 1792 字节块复制进一个 1804 字节池对象
 *     5) type 5 的 +0x34 → w*h*4 像素缓冲
 *   浅（裸字拷贝，与源共享）：
 *     所有标量字段；以及 type 5 的 +0x0c（流里是 ReadString 得来的 char*，这里没有 strdup）
 *   完全不拷（新对象停在 ctor 值）：
 *     CLayer：+0x19、+0x2c、+0x30..0x57（计时器只 Reset）、+0x58/+0x5c/+0x60（元素链重建）、+0x64
 *     元素：+0x08/+0x10 一律不拷；type 5 的 +0x38；type 3 的 +0x0c/+0x20..+0x44
 *   未知类型（type 不在 1..7）→ 整个元素被跳过（1c4d04 的默认分支），不打日志、不占位
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */


/* @0x1c47e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c47e4 vpush {d8, d9} */
/* ── 帧与形参：r0、r1 都当 CRoom* 用，r2 从未被读 ──────────────────
 *   push {r4-r11,lr} + vpush {d8,d9} + sub sp,#68（68 字节临时区：6 个池/字符串槽 + 保存位）
 *   subs r4,r0,#0 → r4 = r0 = this，并存进 sp+0xc；mov r4,r1 → r4 = 第 1 形参
 *   两处判空都退到 1c4f44（撤帧直接返回）：1c4804（this 为空）、1c480c（第 1 形参为空）
 *   r12 = GOT 基址 0x3F1C58（1c47f0 的字面量 0x0022d458 加 pc），存进 sp+0x24
 *   ★ 符号里有两个 CRoom* 形参，但函数体只读 r0 与 r1，r2 一次都没读；而 r0 直接被当房间用
 *     （1c4810 传给 CleanRoomLayers，之后所有写落在 r0+0xd4/0xd8/0xdc/0xe4...）。
 *     可操作口径：r0 = 目标房间（被清空并重建的那个），r1 = 源房间。多出的那个形参记 open。
 */

/* @0x1c47e8 subs r4, r0, #0 */
/* @0x1c47ec sub sp, sp, #68 */
/* @0x1c47f0 ldr r12, [pc, #0x470] */
/* @0x1c47f4 str r4, [sp, #0xc] */
/* @0x1c47f8 add r12, pc, r12 */
/* @0x1c47fc mov r4, r1 */
/* @0x1c4800 str r12, [sp, #0x24] */
/* @0x1c4804 beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* @0x1c4808 cmp r1, #0 */
/* @0x1c480c beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* ── 清空目标房间：CleanRoomLayers(目标房间) ────────────────────────
 *   只传 r0。返回后立刻重建三张哈希表，说明它清掉的是层链与表内容；
 *   但桶数组在下面被直接覆写（+0xf4/+0x108/+0x120）而没有显式释放 —— 旧桶谁释放
 *   在本函数里看不到，记 open。
 */

/* @0x1c4810 bl 0x1b93c8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom> */
/* ── 表 1 重建（room+0xe4）：容量沿用原值，桶按 12 字节/桶重分配 ──────
 *   1c4828 cap = [room+0xe4]          1c4830 room+0xec = cap-1（掩码）
 *   1c4838/1c4844 size = cap*3*4 = cap*12
 *   1c484c Alloc(size, "Platform/MemoryManager.h", 70, 1) —— 分配点落在 MemoryManager.h 的
 *          内联模板里（这坐实了这个 20 字节结构就是声明在 MemoryManager.h 里的 CHashMap）
 *   1c485c room+0xf4 = 桶数组；1c4860 memset(桶, 0, size)
 *   1c4874 room+0xe8 = 0（已用数）；1c488c room+0xf0 = (int)(float(cap) * 0.6f)（扩容阈值）
 *   0.6f = 1c4c60 的 0x3f19999a
 *   1c48a4..1c48b0 桶链清零：for(p = 桶; p != 桶+cap*12; p += 12) p[+8] = 0
 *   ⇒ 桶 = 12 字节 {+0 键, +4 值, +8 next}，与 1c4f2c 的 Insert 用法一致
 */

/* @0x1c4814 ldr r12, [sp, #0xc] */
/* @0x1c4818 ldr lr, [sp, #0xc] */
/* @0x1c481c mov r2, #70 */
/* @0x1c4820 ldr r1, [pc, #0x444] */
/* @0x1c4824 mov r3, #1 */
/* @0x1c4828 ldr r0, [r12, #0xe4] */
/* @0x1c482c add r1, pc, r1 */
/* @0x1c4830 sub r12, r0, #1 */
/* @0x1c4834 str r12, [lr, #0xec] */
/* @0x1c4838 add r0, r0, r0, lsl #1 */
/* @0x1c483c add r12, lr, #228 */
/* @0x1c4840 str r12, [sp, #0x28] */
/* @0x1c4844 lsl r5, r0, #2 */
/* @0x1c4848 mov r0, r5 */
/* @0x1c484c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4850 ldr r12, [sp, #0xc] */
/* @0x1c4854 mov r2, r5 */
/* @0x1c4858 mov r1, #0 */
/* @0x1c485c str r0, [r12, #0xf4] */
/* @0x1c4860 bl 0xb65b0 <memset@plt> */
/* @0x1c4864 ldr r12, [sp, #0xc] */
/* @0x1c4868 vldr s15, [pc, #1008] */
/* @0x1c486c mov r1, #0 */
/* @0x1c4870 ldr r2, [r12, #0xe4] */
/* @0x1c4874 str r1, [r12, #0xe8] */
/* @0x1c4878 cmp r2, r1 */
/* @0x1c487c vmov s13, r2 */
/* @0x1c4880 vcvt.f32.s32 s14, s13 */
/* @0x1c4884 vmul.f32 s15, s14, s15 */
/* @0x1c4888 vcvt.s32.f32 s15, s15 */
/* @0x1c488c vstr s15, [r12, #240] */
/* @0x1c4890 ble 0x1c48b4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd4> */
/* @0x1c4894 ldr r12, [sp, #0xc] */
/* @0x1c4898 add r2, r2, r2, lsl #1 */
/* @0x1c489c ldr r3, [r12, #0xf4] */
/* @0x1c48a0 add r2, r3, r2, lsl #2 */
/* @0x1c48a4 str r1, [r3, #0x8] */
/* @0x1c48a8 add r3, r3, #12 */
/* @0x1c48ac cmp r3, r2 */
/* @0x1c48b0 bne 0x1c48a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc4> */
/* ── 表 2 重建（room+0xf8）：同构 ──────────────────────────────────
 *   掩码 +0x100、桶 +0x108、阈值 +0x104、已用 +0xfc；1c48e4 的 Alloc 站点串同样是 MemoryManager.h
 */

/* @0x1c48b4 ldr r12, [sp, #0xc] */
/* @0x1c48b8 mov r2, #70 */
/* @0x1c48bc ldr lr, [sp, #0xc] */
/* @0x1c48c0 mov r3, #1 */
/* @0x1c48c4 ldr r1, [pc, #0x3a4] */
/* @0x1c48c8 ldr r0, [r12, #0xf8] */
/* @0x1c48cc add r1, pc, r1 */
/* @0x1c48d0 sub r12, r0, #1 */
/* @0x1c48d4 str r12, [lr, #0x100] */
/* @0x1c48d8 add r0, r0, r0, lsl #1 */
/* @0x1c48dc lsl r5, r0, #2 */
/* @0x1c48e0 mov r0, r5 */
/* @0x1c48e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c48e8 ldr r12, [sp, #0xc] */
/* @0x1c48ec mov r2, r5 */
/* @0x1c48f0 mov r1, #0 */
/* @0x1c48f4 str r0, [r12, #0x108] */
/* @0x1c48f8 bl 0xb65b0 <memset@plt> */
/* @0x1c48fc ldr r12, [sp, #0xc] */
/* @0x1c4900 vldr s15, [pc, #856] */
/* @0x1c4904 mov r1, #0 */
/* @0x1c4908 ldr r2, [r12, #0xf8] */
/* @0x1c490c str r1, [r12, #0xfc] */
/* @0x1c4910 cmp r2, r1 */
/* @0x1c4914 vmov s13, r2 */
/* @0x1c4918 vcvt.f32.s32 s14, s13 */
/* @0x1c491c vmul.f32 s15, s14, s15 */
/* @0x1c4920 vcvt.s32.f32 s15, s15 */
/* @0x1c4924 vstr s15, [r12, #260] */
/* @0x1c4928 ble 0x1c494c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x16c> */
/* @0x1c492c ldr r12, [sp, #0xc] */
/* @0x1c4930 add r2, r2, r2, lsl #1 */
/* @0x1c4934 ldr r3, [r12, #0x108] */
/* @0x1c4938 add r2, r3, r2, lsl #2 */
/* @0x1c493c str r1, [r3, #0x8] */
/* @0x1c4940 add r3, r3, #12 */
/* @0x1c4944 cmp r3, r2 */
/* @0x1c4948 bne 0x1c493c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x15c> */
/* ── 表 3 重建（room+0x110）：同构 ─────────────────────────────────
 *   掩码 +0x118、桶 +0x120、阈值 +0x11c、已用 +0x114
 *   ★ 三张表结构相同，但本函数只往表 1 插入（1c4f2c）；表 2/3 只被重建、没有任何 Insert
 *     → 它们服务别的东西（未证），记 open。
 */

/* @0x1c494c ldr r12, [sp, #0xc] */
/* @0x1c4950 mov r2, #70 */
/* @0x1c4954 ldr lr, [sp, #0xc] */
/* @0x1c4958 mov r3, #1 */
/* @0x1c495c ldr r1, [pc, #0x310] */
/* @0x1c4960 ldr r0, [r12, #0x110] */
/* @0x1c4964 add r1, pc, r1 */
/* @0x1c4968 sub r12, r0, #1 */
/* @0x1c496c str r12, [lr, #0x118] */
/* @0x1c4970 add r0, r0, r0, lsl #1 */
/* @0x1c4974 lsl r5, r0, #2 */
/* @0x1c4978 mov r0, r5 */
/* @0x1c497c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4980 ldr r12, [sp, #0xc] */
/* @0x1c4984 mov r2, r5 */
/* @0x1c4988 mov r1, #0 */
/* @0x1c498c str r0, [r12, #0x120] */
/* @0x1c4990 bl 0xb65b0 <memset@plt> */
/* @0x1c4994 ldr r12, [sp, #0xc] */
/* @0x1c4998 vldr s15, [pc, #704] */
/* @0x1c499c mov r1, #0 */
/* @0x1c49a0 ldr r2, [r12, #0x110] */
/* @0x1c49a4 str r1, [r12, #0x114] */
/* @0x1c49a8 cmp r2, r1 */
/* @0x1c49ac vmov s13, r2 */
/* @0x1c49b0 vcvt.f32.s32 s14, s13 */
/* @0x1c49b4 vmul.f32 s15, s14, s15 */
/* @0x1c49b8 vcvt.s32.f32 s15, s15 */
/* @0x1c49bc vstr s15, [r12, #284] */
/* @0x1c49c0 ble 0x1c49e4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x204> */
/* @0x1c49c4 ldr r12, [sp, #0xc] */
/* @0x1c49c8 add r2, r2, r2, lsl #1 */
/* @0x1c49cc ldr r3, [r12, #0x120] */
/* @0x1c49d0 add r2, r3, r2, lsl #2 */
/* @0x1c49d4 str r1, [r3, #0x8] */
/* @0x1c49d8 add r3, r3, #12 */
/* @0x1c49dc cmp r3, r2 */
/* @0x1c49e0 bne 0x1c49d4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1f4> */
/* ── 源房间层链：src+0xd4 是链头；空则直接返回 ────────────────────
 *   1c49e4 r4 = [src+0xd4]；1c49ec 存 sp+8（当前源层）；为 0 → 1c4f44 返回
 *   1c49f4..1c4a3c 预取全局槽（全部 PC 相对 + 加数，值已按段表核算）：
 *     sp+0x34 = 0x34D69C = "jni/../jni/yoyo/../../../Files/Room/Room_Layers.h"
 *     sp+0x38 = 0x34D774 = ".../Files/Room/Room_Layers.cpp"
 *     sp+0x2c / sp+0x30 = 同一个 Room_Layers.h（类型 7 / 类型 6 的池分配站点也在这个头里）
 *     r10 = [GOT-0x13f4] = 层池对象；其余 7 个池用 r10 + 负偏移取（1c4c98..1c4cc4）
 *   ⇒ 层池与元素池同属一个全局簇（以层池地址为基、负偏移访问别的池）；簇的结构名未证。
 */

/* @0x1c49e4 ldr r4, [r4, #0xd4] */
/* @0x1c49e8 cmp r4, #0 */
/* @0x1c49ec str r4, [sp, #0x8] */
/* @0x1c49f0 beq 0x1c4f44 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x764> */
/* @0x1c49f4 ldr r4, [pc, #0x27c] */
/* @0x1c49f8 vldr s18, [pc, #612] */
/* @0x1c49fc ldr r3, [pc, #0x278] */
/* @0x1c4a00 vldr d8, [pc, #592] */
/* @0x1c4a04 add r4, pc, r4 */
/* @0x1c4a08 str r4, [sp, #0x34] */
/* @0x1c4a0c ldr r4, [sp, #0x24] */
/* @0x1c4a10 ldr r12, [pc, #0x268] */
/* @0x1c4a14 add r12, pc, r12 */
/* @0x1c4a18 str r12, [sp, #0x38] */
/* @0x1c4a1c ldr r11, [r4, r3] */
/* @0x1c4a20 ldr r12, [pc, #0x25c] */
/* @0x1c4a24 ldr r4, [pc, #0x25c] */
/* @0x1c4a28 mov r10, r11 */
/* @0x1c4a2c add r12, pc, r12 */
/* @0x1c4a30 add r4, pc, r4 */
/* @0x1c4a34 str r12, [sp, #0x2c] */
/* @0x1c4a38 str r4, [sp, #0x30] */
/* ── 层池扩容：可用数为 0 时一次分配「容量」个 112 字节对象并压链 ────────
 *   1c4a3c 可用数；非 0 → 1c4b28 直接弹
 *   1c4a48 容量；<=0 → 1c4b20（只翻倍、不分配）
 *   1c4a60 r0 = 112（CLayer 的 sizeof）、站点串 Room_Layers.h、行 70
 *   压链（尾插）：空则 池尾 = 新；否则 旧尾.next = 新；新.next = 0；新.prev = 旧尾；池头 = 新
 *   1c4a84..1c4ad0 新对象初值：+0x00 = -1、+0x04 = 0、+0x08/+0x0c/+0x10/+0x14 = 0.0f、
 *     +0x18 字节 = 1、+0x19 字节 = 0、+0x1c = 0、+0x20/+0x24/+0x28 = -1、
 *     +0x48..0x4f = 0.0 双精度（vstr d8，d8 取 1c4c58 的两个零字）、
 *     CTimingSource::Reset(对象+0x30) → +0x30..0x57 是 40 字节计时器子对象、
 *     +0x58 = 0、+0x5c = 0、+0x60 = 0、+0x64 = 1、+0x68 = 0、+0x6c = 0
 *   1c4b20/1c4b24 每次补齐后容量翻倍（lsl #1）——容量是等比增长，不是定值
 */

/* @0x1c4a3c ldr r4, [r10, #0x8] */
/* @0x1c4a40 cmp r4, #0 */
/* @0x1c4a44 bne 0x1c4b28 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x348> */
/* @0x1c4a48 ldr r3, [r10, #0x10] */
/* @0x1c4a4c cmp r3, #0 */
/* @0x1c4a50 ble 0x1c4b20 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x340> */
/* @0x1c4a54 ldr r8, [sp, #0x34] */
/* @0x1c4a58 mov r5, #1 */
/* @0x1c4a5c mov r3, #1 */
/* @0x1c4a60 mov r0, #112 */
/* @0x1c4a64 mov r1, r8 */
/* @0x1c4a68 mov r2, #63 */
/* @0x1c4a6c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4a70 mov r7, #0 */
/* @0x1c4a74 mvn r3, #0 */
/* @0x1c4a78 subs r6, r0, #0 */
/* @0x1c4a7c add r0, r6, #48 */
/* @0x1c4a80 beq 0x1c4ad4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x2f4> */
/* @0x1c4a84 str r3, [r6] */
/* @0x1c4a88 vstr s18, [r6, #8] */
/* @0x1c4a8c str r7, [r6, #0x4] */
/* @0x1c4a90 vstr s18, [r6, #12] */
/* @0x1c4a94 vstr s18, [r6, #16] */
/* @0x1c4a98 vstr s18, [r6, #20] */
/* @0x1c4a9c strb r5, [r6, #0x18] */
/* @0x1c4aa0 vstr d8, [r6, #72] */
/* @0x1c4aa4 strb r7, [r6, #0x19] */
/* @0x1c4aa8 str r7, [r6, #0x1c] */
/* @0x1c4aac str r3, [r6, #0x20] */
/* @0x1c4ab0 str r3, [r6, #0x24] */
/* @0x1c4ab4 str r3, [r6, #0x28] */
/* @0x1c4ab8 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c4abc str r7, [r6, #0x5c] */
/* @0x1c4ac0 str r7, [r6, #0x58] */
/* @0x1c4ac4 str r7, [r6, #0x60] */
/* @0x1c4ac8 str r5, [r6, #0x64] */
/* @0x1c4acc str r7, [r6, #0x68] */
/* @0x1c4ad0 str r7, [r6, #0x6c] */
/* @0x1c4ad4 ldr r3, [r10] */
/* @0x1c4ad8 mov r1, #0 */
/* @0x1c4adc add r4, r4, #1 */
/* @0x1c4ae0 ldr r2, [r10, #0x8] */
/* @0x1c4ae4 cmp r3, r1 */
/* @0x1c4ae8 streq r6, [r10, #0x4] */
/* @0x1c4aec strne r6, [r3, #0x6c] */
/* @0x1c4af0 add r2, r2, #1 */
/* @0x1c4af4 streq r3, [r6, #0x6c] */
/* @0x1c4af8 streq r3, [r6, #0x68] */
/* @0x1c4afc strne r3, [r6, #0x68] */
/* @0x1c4b00 ldr r3, [r10, #0x10] */
/* @0x1c4b04 streq r6, [r10] */
/* @0x1c4b08 strne r6, [r10] */
/* @0x1c4b0c strne r1, [r6, #0x6c] */
/* @0x1c4b10 cmp r4, r3 */
/* @0x1c4b14 str r2, [r10, #0x8] */
/* @0x1c4b18 blt 0x1c4a5c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x27c> */
/* @0x1c4b1c ldr r4, [r10, #0x8] */
/* @0x1c4b20 lsl r3, r3, #1 */
/* @0x1c4b24 str r3, [r10, #0x10] */
/* ── 弹一个 CLayer，把源层的 11 个标量字段搬过去 ─────────────────────
 *   弹出（链头出）：prev = [头+0x6c]；prev==0 → 池头 = next，否则 prev.next = next；
 *                   next==0 → 池尾 = prev，否则 next.prev = prev；1c4b74 可用数 -1
 *   搬字段（源在 sp+8，新层在 sp+4）：
 *     +0x00 ← +0x00  +0x04 ← +0x04  +0x08 ← +0x08  +0x0c ← +0x0c  +0x10 ← +0x10
 *     +0x14 ← +0x14  +0x18 字节 ← +0x18  +0x20 ← +0x20  +0x24 ← +0x24  +0x28 ← +0x28
 *   1c4bdc 只搬 +0x18 这一个字节；+0x19 没有对应指令（新层保持 ctor 的 0）
 *   ⇒ 对照 DeSerializeLayer 读流的 12 个头部字段（那边含 +0x19）可知 +0x19 是被这里丢掉的
 */

/* @0x1c4b28 ldr r12, [r10] */
/* @0x1c4b2c sub r4, r4, #1 */
/* @0x1c4b30 ldr r3, [r12, #0x6c] */
/* @0x1c4b34 str r12, [sp, #0x4] */
/* @0x1c4b38 cmp r3, #0 */
/* @0x1c4b3c ldrne r12, [sp, #0x4] */
/* @0x1c4b40 ldreq r2, [r12, #0x68] */
/* @0x1c4b44 ldrne r2, [r12, #0x68] */
/* @0x1c4b48 streq r2, [r10] */
/* @0x1c4b4c strne r2, [r3, #0x68] */
/* @0x1c4b50 ldrne r2, [r12, #0x68] */
/* @0x1c4b54 ldrne r3, [r12, #0x6c] */
/* @0x1c4b58 ldr r12, [sp, #0x8] */
/* @0x1c4b5c cmp r2, #0 */
/* @0x1c4b60 streq r3, [r10, #0x4] */
/* @0x1c4b64 strne r3, [r2, #0x6c] */
/* @0x1c4b68 ldr r1, [r12, #0x8] */
/* @0x1c4b6c ldr r2, [r12] */
/* @0x1c4b70 ldr r3, [r12, #0x4] */
/* @0x1c4b74 str r4, [r10, #0x8] */
/* @0x1c4b78 ldr r4, [sp, #0x4] */
/* @0x1c4b7c ldr r0, [r12, #0x1c] */
/* @0x1c4b80 str r1, [r4, #0x8] */
/* @0x1c4b84 mov r4, r12 */
/* @0x1c4b88 ldr r1, [r4, #0x20] */
/* @0x1c4b8c cmp r0, #0 */
/* @0x1c4b90 ldr r4, [sp, #0x4] */
/* @0x1c4b94 ldrb r12, [r12, #0x18] */
/* @0x1c4b98 str r2, [r4] */
/* @0x1c4b9c ldr r4, [sp, #0x8] */
/* @0x1c4ba0 ldr r2, [r4, #0x24] */
/* @0x1c4ba4 ldr r4, [sp, #0x4] */
/* @0x1c4ba8 str r3, [r4, #0x4] */
/* @0x1c4bac ldr r4, [sp, #0x8] */
/* @0x1c4bb0 ldr r3, [r4, #0xc] */
/* @0x1c4bb4 ldr r4, [sp, #0x4] */
/* @0x1c4bb8 str r3, [r4, #0xc] */
/* @0x1c4bbc ldr r4, [sp, #0x8] */
/* @0x1c4bc0 ldr r3, [r4, #0x28] */
/* @0x1c4bc4 ldr lr, [r4, #0x10] */
/* @0x1c4bc8 ldr r4, [sp, #0x4] */
/* @0x1c4bcc str lr, [r4, #0x10] */
/* @0x1c4bd0 ldr r4, [sp, #0x8] */
/* @0x1c4bd4 ldr lr, [r4, #0x14] */
/* @0x1c4bd8 ldr r4, [sp, #0x4] */
/* @0x1c4bdc strb r12, [r4, #0x18] */
/* @0x1c4be0 str lr, [r4, #0x14] */
/* @0x1c4be4 str r1, [r4, #0x20] */
/* @0x1c4be8 str r2, [r4, #0x24] */
/* @0x1c4bec str r3, [r4, #0x28] */
/* @0x1c4bf0 beq 0x1c59fc <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x121c> */
/* ── 层名的深/浅分叉：全函数唯一一处「看归属再决定拷不拷」────────────
 *   1c4b7c r0 = [src+0x1c]（名字指针）；1c4bf0 为 0 → 1c59fc 把 0 写进新层 +0x1c
 *   1c4bf4 MemoryInWad(名字)：非 0 → 1c59fc 直接把源指针写进新层（共享；合理推断是这块内存归
 *     wad/资源堆、不随层释放，推断部分未独立取证）
 *   为 0 → strlen+1 → Alloc(len+1, "Room_Layers.cpp", 585, 1) → memcpy（深）
 *   ⇒ 「层名总是深拷贝」是错的：wad 内走浅拷贝，堆上才复制。
 */

/* @0x1c4bf4 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1c4bf8 ldr r12, [sp, #0x8] */
/* @0x1c4bfc cmp r0, #0 */
/* @0x1c4c00 ldr r0, [r12, #0x1c] */
/* @0x1c4c04 bne 0x1c59fc <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x121c> */
/* @0x1c4c08 bl 0xb6538 <strlen@plt> */
/* @0x1c4c0c mov r3, #1 */
/* @0x1c4c10 ldr r1, [sp, #0x38] */
/* @0x1c4c14 movw r2, #0x249 */
/* @0x1c4c18 add r4, r0, r3 */
/* @0x1c4c1c mov r0, r4 */
/* @0x1c4c20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4c24 mov r2, r4 */
/* @0x1c4c28 ldr r12, [sp, #0x8] */
/* @0x1c4c2c ldr r4, [sp, #0x4] */
/* @0x1c4c30 str r0, [r4, #0x1c] */
/* @0x1c4c34 ldr r1, [r12, #0x1c] */
/* @0x1c4c38 bl 0xb65bc <memcpy@plt> */
/* ── 源层元素链：layer+0x58 是链头，元素靠 +0x14 推进 ────────────────
 *   1c4c40 r11 = [src_layer+0x58]；为空 → 1c4ee0（该层没有元素，直接收层）
 *   1c4ed0 r11 = [r11+0x14] → 下一个元素，非 0 回 1c4cf4
 */

/* @0x1c4c3c ldr r4, [sp, #0x8] */
/* @0x1c4c40 ldr r11, [r4, #0x58] */
/* @0x1c4c44 cmp r11, #0 */
/* @0x1c4c48 beq 0x1c4ee0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x700> */
/* @0x1c4c4c ldr r4, [pc, #0x38] */
/* @0x1c4c50 str r10, [sp, #0x14] */
/* @0x1c4c54 b 0x1c4cd0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x4f0> */
/* ── 字面量池 1c4c60..1c4ccc（objdump 把前几个字按 ARM 译码显示，不是指令）──
 *   1c4c60 = 0x3f19999a (0.6f 阈值系数)     1c4c64 = 0.0f (s18)
 *   1c4c68 = GOT 基址加数 → 0x3F1C58
 *   1c4c6c / 1c4c70 / 1c4c74 → 三张表的 Alloc 站点串（MemoryManager.h）
 *   1c4c78 → Room_Layers.h；1c4c80 → Room_Layers.cpp
 *   1c4c7c / 1c4c98 / 1c4c9c / 1c4ca0 / 1c4ca4 / 1c4ca8 / 1c4cb0 / 1c4cbc / 1c4cc4
 *     = 层池与 7 个元素池的 GOT 负偏移（0xffffec0c .. 0xffffec2c）
 *   1c4cac / 1c4cb4 / 1c4cb8 / 1c4cc0 / 1c4cc8 / 1c4ccc = 各元素池的 Alloc 站点串
 *   1c4c58 与 1c4c5c 两个字不在索引里（对齐空洞），本卡不落锚。
 */

/* @0x1c4c60 svclo #0x19999a */
/* @0x1c4c64 andeq r0, r0, r0 */
/* @0x1c4c68 eoreq sp, r2, r8, asr r4 */
/* @0x1c4c6c andseq r12, r6, r4, lsl #16 */
/* @0x1c4c70 andseq r12, r6, r4, ror #14 */
/* @0x1c4c74 andseq r12, r6, r12, asr #13 */
/* @0x1c4c78 mulseq r8, r0, r12 */
/* @0x1c4c7c .word 0xffffec0c */
/* @0x1c4c80 andseq r8, r8, r8, asr sp */
/* @0x1c4c84 andseq r8, r8, r8, ror #24 */
/* @0x1c4c88 andseq r8, r8, r4, ror #24 */
/* @0x1c4c8c mulseq r8, r8, r10 */
/* @0x1c4c90 ldrheq r8, [r8], -r0 */
/* @0x1c4c94 andseq r8, r8, r8, lsr #19 */
/* @0x1c4c98 .word 0xffffec28 */
/* @0x1c4c9c .word 0xffffec24 */
/* @0x1c4ca0 .word 0xffffec20 */
/* @0x1c4ca4 .word 0xffffec1c */
/* @0x1c4ca8 .word 0xffffec14 */
/* @0x1c4cac andseq r8, r8, r4, asr #5 */
/* @0x1c4cb0 .word 0xffffec18 */
/* @0x1c4cb4 mulseq r8, r4, r1 */
/* @0x1c4cb8 andseq r8, r8, r4, ror #2 */
/* @0x1c4cbc .word 0xffffec2c */
/* @0x1c4cc0 andseq r7, r8, r8, asr #31 */
/* @0x1c4cc4 .word 0xffffec10 */
/* @0x1c4cc8 andseq r7, r8, r12, asr #28 */
/* @0x1c4ccc andseq r7, r8, r0, lsl #29 */
/* ── 每处理一个元素都重取池/站点槽，然后按 type 七路跳表分派 ───────────
 *   1c4cd0..1c4cf0 把 sp+0x24(GOT) 与 sp+0x10/0x18/0x1c（站点串）重新装回寄存器：每轮重取，
 *     说明元素池是按 type 现取的（不是循环外一次算好）
 *   1c4cf4 r3 = [元素+0x00]（type）；1c4cf8 type-1；1c4cfc 与 6 比较
 *   1c4d00 addls pc,pc,r3,lsl #2 → 7 路跳表（1c4d08 起）：
 *     type1 → 1c580c   type2 → 1c53a4   type3 → 1c54c4   type4 → 1c520c
 *     type5 → 1c5070   type6 → 1c4f50   type7 → 1c4d24   其它 → 1c4ed0（跳过）
 *   ★ 1/4/5 的类身份由工厂坐实：GetNewBackgroundElement 0x1c0bd8 = Alloc(32)+type 1；
 *     GetNewSpriteElement 0x1c0f00 = Alloc(72)+type 4；GetNewTilemapElement 0x1c1034 =
 *     Alloc(60)+type 5。本函数同尺寸同 type，可对号入座。2/3/6/7 没有工厂，只在池里就地构造。
 */

/* @0x1c4cd0 ldr r10, [sp, #0x24] */
/* @0x1c4cd4 add r4, pc, r4 */
/* @0x1c4cd8 ldr r12, [pc, #-0x50] */
/* @0x1c4cdc str r4, [sp, #0x10] */
/* @0x1c4ce0 ldr r4, [pc, #-0x54] */
/* @0x1c4ce4 add r12, pc, r12 */
/* @0x1c4ce8 str r12, [sp, #0x18] */
/* @0x1c4cec add r4, pc, r4 */
/* @0x1c4cf0 str r4, [sp, #0x1c] */
/* @0x1c4cf4 ldr r3, [r11] */
/* @0x1c4cf8 sub r3, r3, #1 */
/* @0x1c4cfc cmp r3, #6 */
/* @0x1c4d00 addls pc, pc, r3, lsl #2 */
/* @0x1c4d04 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c4d08 b 0x1c580c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x102c> */
/* @0x1c4d0c b 0x1c53a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xbc4> */
/* @0x1c4d10 b 0x1c54c4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xce4> */
/* @0x1c4d14 b 0x1c520c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xa2c> */
/* @0x1c4d18 b 0x1c5070 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x890> */
/* @0x1c4d1c b 0x1c4f50 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x770> */
/* @0x1c4d20 b 0x1c4d24 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x544> */
/* ── case 7：80 字节元素（无工厂，池里就地构造）──────────────────────
 *   Alloc(80, Room_Layers.h, 63, 1)；初值 +0x00 = 7、+0x04 = -1、+0x08 字节 = 1、
 *   +0x0c..+0x18 = 非 0（复用循环计数，随即被拷贝覆盖）、+0x1c = 0、+0x20 = -1、
 *   +0x24/+0x28 = 0.0f、+0x2c/+0x30 = 非 0、+0x34/+0x38 = 1.0f、+0x3c = 0.0f、
 *   +0x40 = -1、+0x44 = 1.0f、+0x48/+0x4c = 非 0
 *   ⇒ 与 DeSerializeLayer 第四组就地构造的 80 字节对象同尺寸、同初值（那边 1c8050..1c80c0）
 */

/* @0x1c4d24 ldr r3, [pc, #-0x94] */
/* @0x1c4d28 ldr r5, [r10, r3] */
/* @0x1c4d2c ldr r6, [r5, #0x8] */
/* @0x1c4d30 cmp r6, #0 */
/* @0x1c4d34 bne 0x1c4e10 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x630> */
/* @0x1c4d38 ldr r3, [r5, #0x10] */
/* @0x1c4d3c cmp r3, #0 */
/* @0x1c4d40 ble 0x1c4e08 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x628> */
/* @0x1c4d44 ldr r7, [sp, #0x2c] */
/* @0x1c4d48 mov r4, r6 */
/* @0x1c4d4c mov r2, #63 */
/* @0x1c4d50 mov r3, #1 */
/* @0x1c4d54 mov r0, #80 */
/* @0x1c4d58 mov r1, r7 */
/* @0x1c4d5c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4d60 ldr r3, [r5] */
/* @0x1c4d64 mvn r2, #0 */
/* @0x1c4d68 mov r12, #7 */
/* @0x1c4d6c cmp r0, #0 */
/* @0x1c4d70 beq 0x1c4dc4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x5e4> */
/* @0x1c4d74 mov r1, #1065353216 */
/* @0x1c4d78 strb r4, [r0, #0x8] */
/* @0x1c4d7c str r4, [r0, #0xc] */
/* @0x1c4d80 vstr s18, [r0, #36] */
/* @0x1c4d84 str r4, [r0, #0x10] */
/* @0x1c4d88 vstr s18, [r0, #40] */
/* @0x1c4d8c str r4, [r0, #0x14] */
/* @0x1c4d90 vstr s18, [r0, #60] */
/* @0x1c4d94 str r4, [r0, #0x18] */
/* @0x1c4d98 str r2, [r0, #0x4] */
/* @0x1c4d9c str r2, [r0, #0x20] */
/* @0x1c4da0 str r4, [r0, #0x2c] */
/* @0x1c4da4 str r4, [r0, #0x30] */
/* @0x1c4da8 str r2, [r0, #0x40] */
/* @0x1c4dac str r4, [r0, #0x48] */
/* @0x1c4db0 str r1, [r0, #0x34] */
/* @0x1c4db4 str r4, [r0, #0x4c] */
/* @0x1c4db8 str r1, [r0, #0x38] */
/* @0x1c4dbc str r12, [r0] */
/* @0x1c4dc0 str r1, [r0, #0x44] */
/* @0x1c4dc4 cmp r3, #0 */
/* @0x1c4dc8 strne r0, [r3, #0x18] */
/* @0x1c4dcc streq r3, [r0, #0x18] */
/* @0x1c4dd0 add r6, r6, #1 */
/* @0x1c4dd4 streq r3, [r0, #0x14] */
/* @0x1c4dd8 strne r3, [r0, #0x14] */
/* @0x1c4ddc ldr r3, [r5, #0x10] */
/* @0x1c4de0 ldr r2, [r5, #0x8] */
/* @0x1c4de4 streq r0, [r5, #0x4] */
/* @0x1c4de8 streq r0, [r5] */
/* @0x1c4dec add r2, r2, #1 */
/* @0x1c4df0 strne r0, [r5] */
/* @0x1c4df4 strne r4, [r0, #0x18] */
/* @0x1c4df8 cmp r6, r3 */
/* @0x1c4dfc str r2, [r5, #0x8] */
/* @0x1c4e00 blt 0x1c4d4c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x56c> */
/* @0x1c4e04 ldr r6, [r5, #0x8] */
/* @0x1c4e08 lsl r3, r3, #1 */
/* @0x1c4e0c str r3, [r5, #0x10] */
/* ── case 7 弹出 + 15 个字段裸拷（无任何新分配 → 全浅拷贝）──────────────
 *   拷贝清单（源偏移 = 目标偏移）：+0x04 +0x0c +0x1c(字节) +0x20 +0x24 +0x28
 *                                +0x2c +0x30 +0x34 +0x38 +0x3c +0x40 +0x44 +0x48 +0x4c
 *   不拷：+0x08（池标志）、+0x10、+0x14/+0x18（链接，交给 AddElementToLayer）
 */

/* @0x1c4e10 ldr r3, [r5] */
/* @0x1c4e14 sub r6, r6, #1 */
/* @0x1c4e18 ldr r12, [r11, #0x4] */
/* @0x1c4e1c ldr lr, [r11, #0x34] */
/* @0x1c4e20 ldr r2, [r3, #0x18] */
/* @0x1c4e24 ldr r1, [r3, #0x14] */
/* @0x1c4e28 cmp r2, #0 */
/* @0x1c4e2c str r6, [r5, #0x8] */
/* @0x1c4e30 ldr r4, [r11, #0x30] */
/* @0x1c4e34 strne r1, [r2, #0x14] */
/* @0x1c4e38 ldrne r1, [r3, #0x14] */
/* @0x1c4e3c ldrne r2, [r3, #0x18] */
/* @0x1c4e40 streq r1, [r5] */
/* @0x1c4e44 cmp r1, #0 */
/* @0x1c4e48 streq r2, [r5, #0x4] */
/* @0x1c4e4c strne r2, [r1, #0x18] */
/* @0x1c4e50 ldr r1, [r11, #0x20] */
/* @0x1c4e54 ldr r0, [r11, #0xc] */
/* @0x1c4e58 ldr r2, [r11, #0x40] */
/* @0x1c4e5c str lr, [r3, #0x34] */
/* @0x1c4e60 ldr lr, [r11, #0x48] */
/* @0x1c4e64 str r12, [r3, #0x4] */
/* @0x1c4e68 ldr r12, [r11, #0x4c] */
/* @0x1c4e6c str r0, [r3, #0xc] */
/* @0x1c4e70 ldr r0, [r11, #0x2c] */
/* @0x1c4e74 str r1, [r3, #0x20] */
/* @0x1c4e78 ldr r1, [r11, #0x38] */
/* @0x1c4e7c str r1, [r3, #0x38] */
/* @0x1c4e80 ldr r1, [r11, #0x3c] */
/* @0x1c4e84 str r2, [r3, #0x40] */
/* @0x1c4e88 ldr r2, [r11, #0x44] */
/* @0x1c4e8c str r1, [r3, #0x3c] */
/* @0x1c4e90 ldrb r1, [r11, #0x1c] */
/* @0x1c4e94 str r2, [r3, #0x44] */
/* @0x1c4e98 ldr r2, [r11, #0x24] */
/* @0x1c4e9c str r2, [r3, #0x24] */
/* @0x1c4ea0 ldr r2, [r11, #0x28] */
/* @0x1c4ea4 str lr, [r3, #0x48] */
/* @0x1c4ea8 str r0, [r3, #0x2c] */
/* @0x1c4eac str r2, [r3, #0x28] */
/* @0x1c4eb0 mov r2, r3 */
/* @0x1c4eb4 strb r1, [r3, #0x1c] */
/* @0x1c4eb8 str r12, [r3, #0x4c] */
/* @0x1c4ebc str r4, [r3, #0x30] */
/* ── 收一个元素：AddElementToLayer(目标房间, 新层, 新元素, false) ──────────
 *   实参 r0 = sp+0xc、r1 = sp+4（新层）、r2 = 新元素、r3 = 0
 *   ⇒ 元素链在新层里重建，不是把源链指针接过来；链序是否与源一致取决于这个函数的插入点
 *     （本卡未证，记 open）
 */

/* @0x1c4ec0 mov r3, #0 */
/* @0x1c4ec4 ldr r0, [sp, #0xc] */
/* @0x1c4ec8 ldr r1, [sp, #0x4] */
/* @0x1c4ecc bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c4ed0 ldr r11, [r11, #0x14] */
/* @0x1c4ed4 cmp r11, #0 */
/* @0x1c4ed8 bne 0x1c4cf4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x514> */
/* @0x1c4edc ldr r10, [sp, #0x14] */
/* ── 收层：尾插进目标层链，再插进表 1 ────────────────────────────────
 *   room+0xdc = 层数+1；room+0xd8 是链尾；为空 → 1c5a18 首插
 *   非空：旧尾+0x68(next) = 新层；新层+0x6c(prev) = 旧尾；room+0xd8 = 新层；新层+0x68 = 0
 *   ⇒ room+0xd4 链头 / +0xd8 链尾 / +0xdc 计数；next = +0x68、prev = +0x6c
 */

/* @0x1c4ee0 ldr r12, [sp, #0xc] */
/* @0x1c4ee4 ldr r3, [r12, #0xd8] */
/* @0x1c4ee8 ldr r2, [r12, #0xdc] */
/* @0x1c4eec cmp r3, #0 */
/* @0x1c4ef0 add r2, r2, #1 */
/* @0x1c4ef4 str r2, [r12, #0xdc] */
/* @0x1c4ef8 beq 0x1c5a18 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1238> */
/* @0x1c4efc ldr r4, [sp, #0x4] */
/* @0x1c4f00 ldr r12, [sp, #0xc] */
/* @0x1c4f04 str r4, [r3, #0x68] */
/* @0x1c4f08 mov r3, #0 */
/* @0x1c4f0c ldr r2, [r12, #0xd8] */
/* @0x1c4f10 str r2, [r4, #0x6c] */
/* @0x1c4f14 str r4, [r12, #0xd8] */
/* @0x1c4f18 str r3, [r4, #0x68] */
/* ── CHashMap<int, CLayer*, 7>::Insert(room+0xe4, 新层+0x00, 新层) ──────
 *   键就是层的 +0x00（id）。三张表只有表 1 收到插入。
 */

/* @0x1c4f1c ldr r4, [sp, #0x4] */
/* @0x1c4f20 ldr r0, [sp, #0x28] */
/* @0x1c4f24 ldr r1, [r4] */
/* @0x1c4f28 mov r2, r4 */
/* @0x1c4f2c bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_> */
/* ── 下一层：cur = cur+0x68，非 0 回 1c4a3c ────────────────────────
 */

/* @0x1c4f30 ldr r12, [sp, #0x8] */
/* @0x1c4f34 ldr r12, [r12, #0x68] */
/* @0x1c4f38 cmp r12, #0 */
/* @0x1c4f3c str r12, [sp, #0x8] */
/* @0x1c4f40 bne 0x1c4a3c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x25c> */
/* ── 公共出口：add sp,#68 / vpop {d8,d9} / pop {r4-r11,pc}（void，无返回值）──
 */

/* @0x1c4f44 add sp, sp, #68 */
/* @0x1c4f48 vpop {d8, d9} */
/* @0x1c4f4c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── case 6：32 字节元素，只搬 3 个字段 ─────────────────────────────
 *   Alloc(32, Room_Layers.h, 63, 1)；初值 +0x00 = 6、+0x04 = -1、+0x08 字节 = 1、+0x1c = -1
 *   拷贝：+0x04 ← +0x04（1c5050）、+0x1c ← +0x1c（1c5054）、+0x0c ← +0x0c（1c5058）
 */

/* @0x1c4f50 ldr r3, [pc, #-0x2bc] */
/* @0x1c4f54 ldr r4, [r10, r3] */
/* @0x1c4f58 ldr r7, [r4, #0x8] */
/* @0x1c4f5c cmp r7, #0 */
/* @0x1c4f60 bne 0x1c500c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x82c> */
/* @0x1c4f64 ldr r3, [r4, #0x10] */
/* @0x1c4f68 cmp r3, #0 */
/* @0x1c4f6c ble 0x1c5004 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x824> */
/* @0x1c4f70 ldr r8, [sp, #0x30] */
/* @0x1c4f74 mvn r6, #0 */
/* @0x1c4f78 mov r5, r7 */
/* @0x1c4f7c mov r2, #63 */
/* @0x1c4f80 mov r3, #1 */
/* @0x1c4f84 mov r0, #32 */
/* @0x1c4f88 mov r1, r8 */
/* @0x1c4f8c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c4f90 ldr r3, [r4] */
/* @0x1c4f94 mov r2, #6 */
/* @0x1c4f98 cmp r0, #0 */
/* @0x1c4f9c beq 0x1c4fc0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x7e0> */
/* @0x1c4fa0 strb r5, [r0, #0x8] */
/* @0x1c4fa4 str r5, [r0, #0xc] */
/* @0x1c4fa8 str r5, [r0, #0x10] */
/* @0x1c4fac str r5, [r0, #0x14] */
/* @0x1c4fb0 str r5, [r0, #0x18] */
/* @0x1c4fb4 str r6, [r0, #0x4] */
/* @0x1c4fb8 str r6, [r0, #0x1c] */
/* @0x1c4fbc str r2, [r0] */
/* @0x1c4fc0 cmp r3, #0 */
/* @0x1c4fc4 strne r0, [r3, #0x18] */
/* @0x1c4fc8 streq r3, [r0, #0x18] */
/* @0x1c4fcc add r7, r7, #1 */
/* @0x1c4fd0 streq r3, [r0, #0x14] */
/* @0x1c4fd4 strne r3, [r0, #0x14] */
/* @0x1c4fd8 ldr r3, [r4, #0x10] */
/* @0x1c4fdc ldr r2, [r4, #0x8] */
/* @0x1c4fe0 streq r0, [r4, #0x4] */
/* @0x1c4fe4 streq r0, [r4] */
/* @0x1c4fe8 add r2, r2, #1 */
/* @0x1c4fec strne r0, [r4] */
/* @0x1c4ff0 strne r5, [r0, #0x18] */
/* @0x1c4ff4 cmp r7, r3 */
/* @0x1c4ff8 str r2, [r4, #0x8] */
/* @0x1c4ffc blt 0x1c4f7c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x79c> */
/* @0x1c5000 ldr r7, [r4, #0x8] */
/* @0x1c5004 lsl r3, r3, #1 */
/* @0x1c5008 str r3, [r4, #0x10] */
/* @0x1c500c ldr r3, [r4] */
/* @0x1c5010 sub r7, r7, #1 */
/* @0x1c5014 ldr r0, [r11, #0x4] */
/* @0x1c5018 str r7, [r4, #0x8] */
/* @0x1c501c ldr r2, [r3, #0x18] */
/* @0x1c5020 ldr r1, [r3, #0x14] */
/* @0x1c5024 cmp r2, #0 */
/* @0x1c5028 strne r1, [r2, #0x14] */
/* @0x1c502c ldrne r1, [r3, #0x14] */
/* @0x1c5030 ldrne r2, [r3, #0x18] */
/* @0x1c5034 streq r1, [r4] */
/* @0x1c5038 cmp r1, #0 */
/* @0x1c503c streq r2, [r4, #0x4] */
/* @0x1c5040 strne r2, [r1, #0x18] */
/* @0x1c5044 mov r2, r3 */
/* @0x1c5048 ldr r1, [r11, #0x1c] */
/* @0x1c504c ldr r12, [r11, #0xc] */
/* @0x1c5050 str r0, [r3, #0x4] */
/* @0x1c5054 str r1, [r3, #0x1c] */
/* @0x1c5058 str r12, [r3, #0xc] */
/* @0x1c505c mov r3, #0 */
/* @0x1c5060 ldr r0, [sp, #0xc] */
/* @0x1c5064 ldr r1, [sp, #0x4] */
/* @0x1c5068 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c506c b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── case 5：60 字节 tilemap 元素（+0x34 像素缓冲深拷贝）──────────────
 *   Alloc(60, Room_Layers.h, 63, 1)；初值 +0x00 = 5、+0x04 = -1、+0x08 字节 = 1、+0x1c = -1、
 *     +0x20/+0x24/+0x30 = 0.0f、+0x28/+0x2c = 非 0、+0x34 = 0.0f、+0x38 = 0x80000000
 *   1c514c..1c51d0 裸拷 8 个字段：+0x04 +0x0c +0x1c +0x20 +0x24 +0x28 +0x2c +0x30
 *   1c51a4/1c51ac 取 w = [src+0x28]、h = [src+0x2c]；1c519c mul、1c51b8 lsl #2 → w*h*4
 *   1c51d4 Alloc(w*h*4, Room_Layers.cpp, 0x2f1, 1) → 1c51e8 写新 +0x34
 *   1c51f0 memcpy(新+0x34, 源+0x34, w*h*4) —— 深拷贝
 *   ★ 不拷 +0x38：源值被丢掉，新对象保留 ctor 的 0x80000000（DeSerializeLayer 是把流里的
 *     uint32 读进 +0x38 的，两边对不上）
 *   ★ +0x0c 是裸字拷贝：DeSerializeLayer 里该字段来自 IBuffer::ReadString（char*），
 *     这里没有 strdup → 两个房间共享同一个字符串
 */

/* @0x1c5070 ldr r3, [pc, #-0x3d8] */
/* @0x1c5074 ldr r5, [r10, r3] */
/* @0x1c5078 ldr r6, [r5, #0x8] */
/* @0x1c507c cmp r6, #0 */
/* @0x1c5080 bne 0x1c514c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x96c> */
/* @0x1c5084 ldr r3, [r5, #0x10] */
/* @0x1c5088 cmp r3, #0 */
/* @0x1c508c ble 0x1c5144 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x964> */
/* @0x1c5090 ldr r7, [sp, #0x18] */
/* @0x1c5094 mov r4, r6 */
/* @0x1c5098 mov r1, r7 */
/* @0x1c509c mov r2, #63 */
/* @0x1c50a0 mov r3, #1 */
/* @0x1c50a4 mov r0, #60 */
/* @0x1c50a8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c50ac ldr r3, [r5] */
/* @0x1c50b0 mvn r2, #0 */
/* @0x1c50b4 mvn r12, #-2147483648 */
/* @0x1c50b8 mov r1, #5 */
/* @0x1c50bc cmp r0, #0 */
/* @0x1c50c0 beq 0x1c5100 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x920> */
/* @0x1c50c4 strb r4, [r0, #0x8] */
/* @0x1c50c8 vstr s18, [r0, #32] */
/* @0x1c50cc str r4, [r0, #0xc] */
/* @0x1c50d0 vstr s18, [r0, #36] */
/* @0x1c50d4 str r4, [r0, #0x10] */
/* @0x1c50d8 vstr s18, [r0, #48] */
/* @0x1c50dc str r4, [r0, #0x14] */
/* @0x1c50e0 str r4, [r0, #0x18] */
/* @0x1c50e4 str r2, [r0, #0x4] */
/* @0x1c50e8 str r2, [r0, #0x1c] */
/* @0x1c50ec str r4, [r0, #0x28] */
/* @0x1c50f0 str r4, [r0, #0x2c] */
/* @0x1c50f4 str r4, [r0, #0x34] */
/* @0x1c50f8 str r12, [r0, #0x38] */
/* @0x1c50fc str r1, [r0] */
/* @0x1c5100 cmp r3, #0 */
/* @0x1c5104 strne r0, [r3, #0x18] */
/* @0x1c5108 streq r3, [r0, #0x18] */
/* @0x1c510c add r6, r6, #1 */
/* @0x1c5110 streq r3, [r0, #0x14] */
/* @0x1c5114 strne r3, [r0, #0x14] */
/* @0x1c5118 ldr r3, [r5, #0x10] */
/* @0x1c511c ldr r2, [r5, #0x8] */
/* @0x1c5120 streq r0, [r5, #0x4] */
/* @0x1c5124 streq r0, [r5] */
/* @0x1c5128 add r2, r2, #1 */
/* @0x1c512c strne r0, [r5] */
/* @0x1c5130 strne r4, [r0, #0x18] */
/* @0x1c5134 cmp r6, r3 */
/* @0x1c5138 str r2, [r5, #0x8] */
/* @0x1c513c blt 0x1c5098 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x8b8> */
/* @0x1c5140 ldr r6, [r5, #0x8] */
/* @0x1c5144 lsl r3, r3, #1 */
/* @0x1c5148 str r3, [r5, #0x10] */
/* @0x1c514c ldr r4, [r5] */
/* @0x1c5150 sub r6, r6, #1 */
/* @0x1c5154 ldr lr, [r11, #0x20] */
/* @0x1c5158 ldr r1, [r11, #0x1c] */
/* @0x1c515c ldr r3, [r4, #0x18] */
/* @0x1c5160 ldr r2, [r4, #0x14] */
/* @0x1c5164 cmp r3, #0 */
/* @0x1c5168 ldr r12, [r11, #0x4] */
/* @0x1c516c str r6, [r5, #0x8] */
/* @0x1c5170 strne r2, [r3, #0x14] */
/* @0x1c5174 ldrne r2, [r4, #0x14] */
/* @0x1c5178 ldrne r3, [r4, #0x18] */
/* @0x1c517c streq r2, [r5] */
/* @0x1c5180 cmp r2, #0 */
/* @0x1c5184 streq r3, [r5, #0x4] */
/* @0x1c5188 strne r3, [r2, #0x18] */
/* @0x1c518c ldr r2, [r11, #0x28] */
/* @0x1c5190 ldr r3, [r11, #0x2c] */
/* @0x1c5194 str lr, [r4, #0x20] */
/* @0x1c5198 ldr lr, [r11, #0xc] */
/* @0x1c519c mul r0, r3, r2 */
/* @0x1c51a0 str r1, [r4, #0x1c] */
/* @0x1c51a4 ldr r1, [r11, #0x24] */
/* @0x1c51a8 str r3, [r4, #0x2c] */
/* @0x1c51ac ldr r3, [r11, #0x30] */
/* @0x1c51b0 str r12, [r4, #0x4] */
/* @0x1c51b4 str r2, [r4, #0x28] */
/* @0x1c51b8 lsl r0, r0, #2 */
/* @0x1c51bc str r1, [r4, #0x24] */
/* @0x1c51c0 movw r2, #0x2f1 */
/* @0x1c51c4 str lr, [r4, #0xc] */
/* @0x1c51c8 ldr r1, [sp, #0x10] */
/* @0x1c51cc str r3, [r4, #0x30] */
/* @0x1c51d0 mov r3, #1 */
/* @0x1c51d4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c51d8 ldr r3, [r4, #0x28] */
/* @0x1c51dc ldr r2, [r4, #0x2c] */
/* @0x1c51e0 mul r2, r2, r3 */
/* @0x1c51e4 lsl r2, r2, #2 */
/* @0x1c51e8 str r0, [r4, #0x34] */
/* @0x1c51ec ldr r1, [r11, #0x34] */
/* @0x1c51f0 bl 0xb65bc <memcpy@plt> */
/* @0x1c51f4 ldr r0, [sp, #0xc] */
/* @0x1c51f8 ldr r1, [sp, #0x4] */
/* @0x1c51fc mov r2, r4 */
/* @0x1c5200 mov r3, #0 */
/* @0x1c5204 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c5208 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── case 4：72 字节 sprite 元素 ────────────────────────────────────
 *   Alloc(72, Room_Layers.h, 63, 1)；初值 +0x00 = 4、+0x04 = -1、+0x1c = -1、+0x38 = -1、
 *     +0x20/+0x34/+0x40/+0x44 = 0.0f、+0x24/+0x2c/+0x30/+0x3c = 1.0f
 *   1c52f4..1c5390 裸拷 13 个字段：+0x04 +0x0c +0x1c +0x20 +0x24 +0x28 +0x2c +0x30
 *                                  +0x34 +0x38 +0x3c +0x40 +0x44（无新分配 → 全浅）
 *   注意本类的 +0x24/+0x28/+0x2c 是浮点字段，与类型 3 的同偏移（链头/链尾/计数）同名不同义
 */

/* @0x1c520c ldr r3, [pc, #-0x570] */
/* @0x1c5210 ldr r4, [r10, r3] */
/* @0x1c5214 ldr r6, [r4, #0x8] */
/* @0x1c5218 cmp r6, #0 */
/* @0x1c521c bne 0x1c52f4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xb14> */
/* @0x1c5220 ldr r3, [r4, #0x10] */
/* @0x1c5224 cmp r3, #0 */
/* @0x1c5228 ble 0x1c52ec <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xb0c> */
/* @0x1c522c ldr r7, [sp, #0x1c] */
/* @0x1c5230 mov r5, r6 */
/* @0x1c5234 mov r1, r7 */
/* @0x1c5238 mov r2, #63 */
/* @0x1c523c mov r0, #72 */
/* @0x1c5240 mov r3, #1 */
/* @0x1c5244 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5248 ldr r2, [r4] */
/* @0x1c524c mvn r1, #0 */
/* @0x1c5250 mov r12, #4 */
/* @0x1c5254 cmp r0, #0 */
/* @0x1c5258 beq 0x1c52a8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xac8> */
/* @0x1c525c mov r3, #1065353216 */
/* @0x1c5260 strb r5, [r0, #0x8] */
/* @0x1c5264 str r5, [r0, #0xc] */
/* @0x1c5268 vstr s18, [r0, #32] */
/* @0x1c526c str r5, [r0, #0x10] */
/* @0x1c5270 vstr s18, [r0, #52] */
/* @0x1c5274 str r5, [r0, #0x14] */
/* @0x1c5278 vstr s18, [r0, #64] */
/* @0x1c527c str r5, [r0, #0x18] */
/* @0x1c5280 vstr s18, [r0, #68] */
/* @0x1c5284 str r1, [r0, #0x4] */
/* @0x1c5288 str r1, [r0, #0x1c] */
/* @0x1c528c str r5, [r0, #0x28] */
/* @0x1c5290 str r1, [r0, #0x38] */
/* @0x1c5294 str r12, [r0] */
/* @0x1c5298 str r3, [r0, #0x24] */
/* @0x1c529c str r3, [r0, #0x2c] */
/* @0x1c52a0 str r3, [r0, #0x30] */
/* @0x1c52a4 str r3, [r0, #0x3c] */
/* @0x1c52a8 ldr r3, [r4, #0x8] */
/* @0x1c52ac add r6, r6, #1 */
/* @0x1c52b0 cmp r2, #0 */
/* @0x1c52b4 strne r0, [r2, #0x18] */
/* @0x1c52b8 add r3, r3, #1 */
/* @0x1c52bc str r3, [r4, #0x8] */
/* @0x1c52c0 ldr r3, [r4, #0x10] */
/* @0x1c52c4 streq r0, [r4, #0x4] */
/* @0x1c52c8 streq r0, [r4] */
/* @0x1c52cc streq r2, [r0, #0x18] */
/* @0x1c52d0 streq r2, [r0, #0x14] */
/* @0x1c52d4 strne r0, [r4] */
/* @0x1c52d8 strne r2, [r0, #0x14] */
/* @0x1c52dc strne r5, [r0, #0x18] */
/* @0x1c52e0 cmp r6, r3 */
/* @0x1c52e4 blt 0x1c5234 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xa54> */
/* @0x1c52e8 ldr r6, [r4, #0x8] */
/* @0x1c52ec lsl r3, r3, #1 */
/* @0x1c52f0 str r3, [r4, #0x10] */
/* @0x1c52f4 ldr r2, [r4] */
/* @0x1c52f8 sub r6, r6, #1 */
/* @0x1c52fc ldr r0, [r11, #0x1c] */
/* @0x1c5300 ldr lr, [r11, #0x20] */
/* @0x1c5304 ldr r3, [r2, #0x18] */
/* @0x1c5308 ldr r1, [r2, #0x14] */
/* @0x1c530c cmp r3, #0 */
/* @0x1c5310 ldr r12, [r11, #0x4] */
/* @0x1c5314 str r6, [r4, #0x8] */
/* @0x1c5318 strne r1, [r3, #0x14] */
/* @0x1c531c ldrne r1, [r2, #0x14] */
/* @0x1c5320 ldrne r3, [r2, #0x18] */
/* @0x1c5324 streq r1, [r4] */
/* @0x1c5328 cmp r1, #0 */
/* @0x1c532c streq r3, [r4, #0x4] */
/* @0x1c5330 strne r3, [r1, #0x18] */
/* @0x1c5334 ldr r1, [r11, #0x28] */
/* @0x1c5338 ldr r3, [r11, #0x38] */
/* @0x1c533c str lr, [r2, #0x20] */
/* @0x1c5340 ldr lr, [r11, #0xc] */
/* @0x1c5344 str r0, [r2, #0x1c] */
/* @0x1c5348 ldr r0, [r11, #0x24] */
/* @0x1c534c str r1, [r2, #0x28] */
/* @0x1c5350 ldr r1, [r11, #0x2c] */
/* @0x1c5354 str r0, [r2, #0x24] */
/* @0x1c5358 str r12, [r2, #0x4] */
/* @0x1c535c str r1, [r2, #0x2c] */
/* @0x1c5360 ldr r1, [r11, #0x30] */
/* @0x1c5364 str r1, [r2, #0x30] */
/* @0x1c5368 ldr r1, [r11, #0x34] */
/* @0x1c536c str r1, [r2, #0x34] */
/* @0x1c5370 ldr r1, [r11, #0x3c] */
/* @0x1c5374 str r3, [r2, #0x38] */
/* @0x1c5378 ldr r3, [r11, #0x44] */
/* @0x1c537c str r1, [r2, #0x3c] */
/* @0x1c5380 ldr r1, [r11, #0x40] */
/* @0x1c5384 str r1, [r2, #0x40] */
/* @0x1c5388 str r3, [r2, #0x44] */
/* @0x1c538c mov r3, #0 */
/* @0x1c5390 str lr, [r2, #0xc] */
/* @0x1c5394 ldr r0, [sp, #0xc] */
/* @0x1c5398 ldr r1, [sp, #0x4] */
/* @0x1c539c bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c53a0 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── case 2：36 字节元素，只搬 3 个字段 ─────────────────────────────
 *   Alloc(36, Room_Layers.h, 63, 1)；初值 +0x00 = 2、+0x04 = -1、+0x1c = -1、+0x20 = 0
 *   拷贝：+0x04 ← +0x04（1c54a8）、+0x1c ← +0x1c（1c54b0）、+0x0c ← +0x0c
 *   （字段集与 case 6 完全相同，只是 sizeof 与 type 不同）
 */

/* @0x1c53a4 ldr r3, [pc, #-0x704] */
/* @0x1c53a8 ldr r4, [r10, r3] */
/* @0x1c53ac ldr r8, [r4, #0x8] */
/* @0x1c53b0 cmp r8, #0 */
/* @0x1c53b4 bne 0x1c5468 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc88> */
/* @0x1c53b8 ldr r3, [r4, #0x10] */
/* @0x1c53bc cmp r3, #0 */
/* @0x1c53c0 ble 0x1c5460 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc80> */
/* @0x1c53c4 ldr r7, [pc, #-0x720] */
/* @0x1c53c8 mov r5, r8 */
/* @0x1c53cc mvn r6, #0 */
/* @0x1c53d0 add r7, pc, r7 */
/* @0x1c53d4 mov r2, #63 */
/* @0x1c53d8 mov r3, #1 */
/* @0x1c53dc mov r0, #36 */
/* @0x1c53e0 mov r1, r7 */
/* @0x1c53e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c53e8 ldr r3, [r4] */
/* @0x1c53ec mov r2, #2 */
/* @0x1c53f0 cmp r0, #0 */
/* @0x1c53f4 beq 0x1c541c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xc3c> */
/* @0x1c53f8 strb r5, [r0, #0x8] */
/* @0x1c53fc str r5, [r0, #0xc] */
/* @0x1c5400 str r5, [r0, #0x10] */
/* @0x1c5404 str r5, [r0, #0x14] */
/* @0x1c5408 str r5, [r0, #0x18] */
/* @0x1c540c str r6, [r0, #0x4] */
/* @0x1c5410 str r6, [r0, #0x1c] */
/* @0x1c5414 str r5, [r0, #0x20] */
/* @0x1c5418 str r2, [r0] */
/* @0x1c541c cmp r3, #0 */
/* @0x1c5420 strne r0, [r3, #0x18] */
/* @0x1c5424 streq r3, [r0, #0x18] */
/* @0x1c5428 add r8, r8, #1 */
/* @0x1c542c streq r3, [r0, #0x14] */
/* @0x1c5430 strne r3, [r0, #0x14] */
/* @0x1c5434 ldr r3, [r4, #0x10] */
/* @0x1c5438 ldr r2, [r4, #0x8] */
/* @0x1c543c streq r0, [r4, #0x4] */
/* @0x1c5440 streq r0, [r4] */
/* @0x1c5444 add r2, r2, #1 */
/* @0x1c5448 strne r0, [r4] */
/* @0x1c544c strne r5, [r0, #0x18] */
/* @0x1c5450 cmp r8, r3 */
/* @0x1c5454 str r2, [r4, #0x8] */
/* @0x1c5458 blt 0x1c53d4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xbf4> */
/* @0x1c545c ldr r8, [r4, #0x8] */
/* @0x1c5460 lsl r3, r3, #1 */
/* @0x1c5464 str r3, [r4, #0x10] */
/* @0x1c5468 ldr r3, [r4] */
/* @0x1c546c sub r8, r8, #1 */
/* @0x1c5470 ldr r0, [r11, #0x4] */
/* @0x1c5474 str r8, [r4, #0x8] */
/* @0x1c5478 ldr r2, [r3, #0x18] */
/* @0x1c547c ldr r1, [r3, #0x14] */
/* @0x1c5480 cmp r2, #0 */
/* @0x1c5484 strne r1, [r2, #0x14] */
/* @0x1c5488 ldrne r1, [r3, #0x14] */
/* @0x1c548c ldrne r2, [r3, #0x18] */
/* @0x1c5490 streq r1, [r4] */
/* @0x1c5494 cmp r1, #0 */
/* @0x1c5498 streq r2, [r4, #0x4] */
/* @0x1c549c strne r2, [r1, #0x18] */
/* @0x1c54a0 mov r2, r3 */
/* @0x1c54a4 ldr r1, [r11, #0x1c] */
/* @0x1c54a8 str r0, [r3, #0x4] */
/* @0x1c54ac ldr r0, [sp, #0xc] */
/* @0x1c54b0 str r1, [r3, #0x1c] */
/* @0x1c54b4 mov r3, #0 */
/* @0x1c54b8 ldr r1, [sp, #0x4] */
/* @0x1c54bc bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c54c0 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── case 3：52 字节元素 + 两条独立深拷贝（记录数组、1792 字节块链）───────
 *   入口先看 src+0x1c：为 0 → 1c5a08 再看 src+0x2c，>0 才继续造元素（1c5a10）
 *   池 Alloc(52, Room_Layers.h, 63, 1)；初值 +0x00 = 3、+0x08 字节 = 1、+0x30 = 1
 *   标量面几乎不搬：只有 +0x04 ← +0x04（1c55e8）；+0x1c 由新数组覆盖；
 *     1c57f0 把 +0x08 置 1（有块的标志）
 *   ⇒ 类型 3 的载荷全在 +0x1c 与 +0x24 两条链里
 */

/* @0x1c54c4 ldr r3, [r11, #0x1c] */
/* @0x1c54c8 cmp r3, #0 */
/* @0x1c54cc beq 0x1c5a08 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1228> */
/* @0x1c54d0 ldr r3, [pc, #-0x828] */
/* @0x1c54d4 ldr r5, [r10, r3] */
/* @0x1c54d8 ldr r9, [r5, #0x8] */
/* @0x1c54dc cmp r9, #0 */
/* @0x1c54e0 bne 0x1c55a8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xdc8> */
/* @0x1c54e4 ldr r3, [r5, #0x10] */
/* @0x1c54e8 cmp r3, #0 */
/* @0x1c54ec ble 0x1c55a0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xdc0> */
/* @0x1c54f0 ldr r6, [pc, #-0x844] */
/* @0x1c54f4 mov r4, r9 */
/* @0x1c54f8 mov r8, #1 */
/* @0x1c54fc mvn r7, #0 */
/* @0x1c5500 add r6, pc, r6 */
/* @0x1c5504 mov r2, #63 */
/* @0x1c5508 mov r3, #1 */
/* @0x1c550c mov r0, #52 */
/* @0x1c5510 mov r1, r6 */
/* @0x1c5514 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5518 ldr r3, [r5] */
/* @0x1c551c mov r2, #3 */
/* @0x1c5520 cmp r0, #0 */
/* @0x1c5524 beq 0x1c555c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd7c> */
/* @0x1c5528 strb r4, [r0, #0x8] */
/* @0x1c552c str r4, [r0, #0xc] */
/* @0x1c5530 str r4, [r0, #0x10] */
/* @0x1c5534 str r4, [r0, #0x14] */
/* @0x1c5538 str r4, [r0, #0x18] */
/* @0x1c553c str r7, [r0, #0x4] */
/* @0x1c5540 str r4, [r0, #0x1c] */
/* @0x1c5544 str r4, [r0, #0x20] */
/* @0x1c5548 str r4, [r0, #0x28] */
/* @0x1c554c str r4, [r0, #0x24] */
/* @0x1c5550 str r4, [r0, #0x2c] */
/* @0x1c5554 str r8, [r0, #0x30] */
/* @0x1c5558 str r2, [r0] */
/* @0x1c555c cmp r3, #0 */
/* @0x1c5560 strne r0, [r3, #0x18] */
/* @0x1c5564 streq r3, [r0, #0x18] */
/* @0x1c5568 add r9, r9, #1 */
/* @0x1c556c streq r3, [r0, #0x14] */
/* @0x1c5570 strne r3, [r0, #0x14] */
/* @0x1c5574 ldr r3, [r5, #0x10] */
/* @0x1c5578 ldr r2, [r5, #0x8] */
/* @0x1c557c streq r0, [r5, #0x4] */
/* @0x1c5580 streq r0, [r5] */
/* @0x1c5584 add r2, r2, #1 */
/* @0x1c5588 strne r0, [r5] */
/* @0x1c558c strne r4, [r0, #0x18] */
/* @0x1c5590 cmp r9, r3 */
/* @0x1c5594 str r2, [r5, #0x8] */
/* @0x1c5598 blt 0x1c5504 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xd24> */
/* @0x1c559c ldr r9, [r5, #0x8] */
/* @0x1c55a0 lsl r3, r3, #1 */
/* @0x1c55a4 str r3, [r5, #0x10] */
/* @0x1c55a8 ldr r4, [r5] */
/* @0x1c55ac sub r9, r9, #1 */
/* @0x1c55b0 ldr r3, [r4, #0x18] */
/* @0x1c55b4 ldr r2, [r4, #0x14] */
/* @0x1c55b8 cmp r3, #0 */
/* @0x1c55bc strne r2, [r3, #0x14] */
/* @0x1c55c0 ldrne r2, [r4, #0x14] */
/* @0x1c55c4 ldrne r3, [r4, #0x18] */
/* @0x1c55c8 streq r2, [r5] */
/* @0x1c55cc cmp r2, #0 */
/* @0x1c55d0 streq r3, [r5, #0x4] */
/* @0x1c55d4 strne r3, [r2, #0x18] */
/* @0x1c55d8 ldr r3, [r11, #0x1c] */
/* @0x1c55dc ldr r2, [r11, #0x4] */
/* @0x1c55e0 cmp r3, #0 */
/* @0x1c55e4 str r9, [r5, #0x8] */
/* @0x1c55e8 str r2, [r4, #0x4] */
/* @0x1c55ec beq 0x1c56a4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xec4> */
/* ── 深拷贝①：+0x1c 的「计数 + 指针槽 + 48 字节记录」复合块 ─────────────
 *   1c55f0 r6 = [src+0x1c] 的第一个字 = 记录数 n；为 0 则跳过
 *   1c5604/1c560c size = n*52 + 4；1c5610 Alloc(size, Room_Layers.h, 63, 1)
 *   1c5620 新块 +0x03 字节清 0；1c5628 新块 +0x00 = n；1c5648 新块 +0x04 = 记录区首址
 *     （= 块基址 + 4 + n*4，正好是 n 个指针槽之后）
 *   源侧是一个指针表：1c5650 依次取 [src_array+4]、+8、…，每条指向一个独立分配的 48 字节节点；
 *   1c5658..1c5684 每次搬 48 字节（三趟 16 字节），按 48 步长紧凑排在记录区
 *   1c56a0 新元素 +0x1c = 新块
 *   ⇒ 源 = n 个散节点 + 指针表，目标 = 一整块压平（4 + 4n + 48n = 4 + 52n）
 *   ★ 目标只写了 +0x00/+0x03/+0x04 与第一个指针槽，其余 n-1 个指针槽没有写
 *     （Alloc 第 4 实参是否为清零未证）→ 记 open
 */

/* @0x1c55f0 ldr r6, [r3] */
/* @0x1c55f4 mov r0, #52 */
/* @0x1c55f8 ldr r1, [pc, #-0x948] */
/* @0x1c55fc movw r2, #0x296 */
/* @0x1c5600 mov r3, #1 */
/* @0x1c5604 mul r0, r0, r6 */
/* @0x1c5608 add r1, pc, r1 */
/* @0x1c560c add r0, r0, #4 */
/* @0x1c5610 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5614 cmp r6, #0 */
/* @0x1c5618 mov r1, #0 */
/* @0x1c561c mov r2, r0 */
/* @0x1c5620 strb r1, [r0, #0x3] */
/* @0x1c5624 str r0, [sp, #0x20] */
/* @0x1c5628 str r6, [r2], #4 */
/* @0x1c562c add r2, r2, r6, lsl #2 */
/* @0x1c5630 ldr r12, [r11, #0x1c] */
/* @0x1c5634 ble 0x1c569c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xebc> */
/* @0x1c5638 ldr r0, [sp, #0x20] */
/* @0x1c563c mov r5, r1 */
/* @0x1c5640 str r4, [sp, #0x3c] */
/* @0x1c5644 mov r4, r6 */
/* @0x1c5648 str r2, [r0, #0x4]! */
/* @0x1c564c mov r1, r2 */
/* @0x1c5650 ldr r3, [r12, #0x4]! */
/* @0x1c5654 add lr, r3, #48 */
/* @0x1c5658 ldr r9, [r3] */
/* @0x1c565c add r3, r3, #16 */
/* @0x1c5660 ldr r8, [r3, #-0xc] */
/* @0x1c5664 add r1, r1, #16 */
/* @0x1c5668 ldr r7, [r3, #-0x8] */
/* @0x1c566c ldr r6, [r3, #-0x4] */
/* @0x1c5670 cmp r3, lr */
/* @0x1c5674 str r9, [r1, #-0x10] */
/* @0x1c5678 str r8, [r1, #-0xc] */
/* @0x1c567c str r7, [r1, #-0x8] */
/* @0x1c5680 str r6, [r1, #-0x4] */
/* @0x1c5684 bne 0x1c5658 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xe78> */
/* @0x1c5688 add r5, r5, #1 */
/* @0x1c568c add r2, r2, #48 */
/* @0x1c5690 cmp r5, r4 */
/* @0x1c5694 bne 0x1c5648 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xe68> */
/* @0x1c5698 ldr r4, [sp, #0x3c] */
/* @0x1c569c ldr r12, [sp, #0x20] */
/* @0x1c56a0 str r12, [r4, #0x1c] */
/* ── 深拷贝②：+0x24 的 1792 字节块链 ──────────────────────────────
 *   1c56a4 r3 = [src+0x2c] = 块数；<=0 → 1c57f4
 *   1c56b0 r8 = [src+0x24] = 源链首；为空 → 1c57ec
 *   源链推进用 [块+0x704]（1c57e0）；块内链接 +0x704(next)/+0x708(prev)（见 1c57bc/1c57cc），
 *     还有一个 +0x700 的字被单独搬（1c5764 读出、1c57a0 写回）
 *   池：1c56f0 Alloc(0x70c = 1804, Room_Layers.h, 63, 1)，1804 = 1792 载荷 + 0x700 那个字 + next/prev
 *   1c575c 弹池 → 1c5798/1c579c memcpy(新块, 源块, 1792) → 1c57a0 补 +0x700
 *   1c57a8..1c57dc 把新块尾插进「新元素」的 +0x24 链（链头 +0x24、链尾 +0x28、计数 +0x2c 全部新建）
 *   ★ 这三处偏移在类型 4 里是浮点字段，勿混用
 */

/* @0x1c56a4 ldr r3, [r11, #0x2c] */
/* @0x1c56a8 cmp r3, #0 */
/* @0x1c56ac ble 0x1c57f4 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x1014> */
/* @0x1c56b0 ldr r8, [r11, #0x24] */
/* @0x1c56b4 cmp r8, #0 */
/* @0x1c56b8 beq 0x1c57ec <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x100c> */
/* @0x1c56bc ldr r3, [pc, #-0xa08] */
/* @0x1c56c0 mov r6, #0 */
/* @0x1c56c4 ldr r7, [pc, #-0xa0c] */
/* @0x1c56c8 ldr r5, [r10, r3] */
/* @0x1c56cc add r7, pc, r7 */
/* @0x1c56d0 ldr r9, [r5, #0x8] */
/* @0x1c56d4 cmp r9, #0 */
/* @0x1c56d8 bne 0x1c575c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf7c> */
/* @0x1c56dc ldr r3, [r5, #0x10] */
/* @0x1c56e0 cmp r3, #0 */
/* @0x1c56e4 ble 0x1c5754 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf74> */
/* @0x1c56e8 mov r2, #63 */
/* @0x1c56ec mov r3, #1 */
/* @0x1c56f0 movw r0, #0x70c */
/* @0x1c56f4 mov r1, r7 */
/* @0x1c56f8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c56fc ldr r3, [r5] */
/* @0x1c5700 add r9, r9, #1 */
/* @0x1c5704 ldr r2, [r5, #0x8] */
/* @0x1c5708 add r2, r2, #1 */
/* @0x1c570c str r2, [r5, #0x8] */
/* @0x1c5710 cmp r0, #0 */
/* @0x1c5714 strne r6, [r0, #0x704] */
/* @0x1c5718 strne r6, [r0, #0x708] */
/* @0x1c571c strne r6, [r0, #0x700] */
/* @0x1c5720 cmp r3, #0 */
/* @0x1c5724 strne r0, [r3, #0x708] */
/* @0x1c5728 streq r3, [r0, #0x708] */
/* @0x1c572c streq r3, [r0, #0x704] */
/* @0x1c5730 strne r3, [r0, #0x704] */
/* @0x1c5734 ldr r3, [r5, #0x10] */
/* @0x1c5738 streq r0, [r5, #0x4] */
/* @0x1c573c streq r0, [r5] */
/* @0x1c5740 strne r0, [r5] */
/* @0x1c5744 strne r6, [r0, #0x708] */
/* @0x1c5748 cmp r9, r3 */
/* @0x1c574c blt 0x1c56e8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xf08> */
/* @0x1c5750 ldr r9, [r5, #0x8] */
/* @0x1c5754 lsl r3, r3, #1 */
/* @0x1c5758 str r3, [r5, #0x10] */
/* @0x1c575c ldr r3, [r5] */
/* @0x1c5760 sub r9, r9, #1 */
/* @0x1c5764 ldr r12, [r8, #0x700] */
/* @0x1c5768 str r9, [r5, #0x8] */
/* @0x1c576c ldr r2, [r3, #0x708] */
/* @0x1c5770 mov r0, r3 */
/* @0x1c5774 ldr r1, [r3, #0x704] */
/* @0x1c5778 cmp r2, #0 */
/* @0x1c577c strne r1, [r2, #0x704] */
/* @0x1c5780 ldrne r1, [r3, #0x704] */
/* @0x1c5784 ldrne r2, [r3, #0x708] */
/* @0x1c5788 streq r1, [r5] */
/* @0x1c578c cmp r1, #0 */
/* @0x1c5790 streq r2, [r5, #0x4] */
/* @0x1c5794 strne r2, [r1, #0x708] */
/* @0x1c5798 mov r1, r8 */
/* @0x1c579c mov r2, #1792 */
/* @0x1c57a0 str r12, [r3, #0x700] */
/* @0x1c57a4 bl 0xb65bc <memcpy@plt> */
/* @0x1c57a8 ldr r2, [r4, #0x28] */
/* @0x1c57ac ldr r1, [r4, #0x2c] */
/* @0x1c57b0 cmp r2, #0 */
/* @0x1c57b4 add r1, r1, #1 */
/* @0x1c57b8 str r1, [r4, #0x2c] */
/* @0x1c57bc strne r0, [r2, #0x704] */
/* @0x1c57c0 ldrne r2, [r4, #0x28] */
/* @0x1c57c4 streq r0, [r4, #0x28] */
/* @0x1c57c8 streq r0, [r4, #0x24] */
/* @0x1c57cc strne r2, [r0, #0x708] */
/* @0x1c57d0 streq r2, [r0, #0x708] */
/* @0x1c57d4 streq r2, [r0, #0x704] */
/* @0x1c57d8 strne r0, [r4, #0x28] */
/* @0x1c57dc strne r6, [r0, #0x704] */
/* @0x1c57e0 ldr r8, [r8, #0x704] */
/* @0x1c57e4 cmp r8, #0 */
/* @0x1c57e8 bne 0x1c56d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xef0> */
/* @0x1c57ec mov r3, #1 */
/* @0x1c57f0 strb r3, [r4, #0x8] */
/* @0x1c57f4 mov r2, r4 */
/* @0x1c57f8 ldr r0, [sp, #0xc] */
/* @0x1c57fc ldr r1, [sp, #0x4] */
/* @0x1c5800 mov r3, #0 */
/* @0x1c5804 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c5808 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── case 1：32 字节 background 元素 + 44 字节子对象深拷贝 ────────────────
 *   入口看 src+0x1c（子对象指针）：为空 → 1c4ed0 跳过该元素
 *   池 Alloc(32, Room_Layers.h, 63, 1)；初值 +0x00 = 1、+0x04 = -1、+0x08 字节 = 1
 *   拷贝：+0x04 ← +0x04（1c5920）、+0x0c ← +0x0c（1c59f0）、+0x1c ← 新子对象（1c596c）
 *   ★ 1c5914 的 mov r2,#608 是 Alloc 的「行号」实参，不是大小；真正的大小是 1c58e4 的 44
 */

/* @0x1c580c ldr r3, [r11, #0x1c] */
/* @0x1c5810 cmp r3, #0 */
/* @0x1c5814 beq 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* @0x1c5818 ldr r3, [pc, #-0xb5c] */
/* @0x1c581c ldr r4, [r10, r3] */
/* @0x1c5820 ldr r9, [r4, #0x8] */
/* @0x1c5824 cmp r9, #0 */
/* @0x1c5828 bne 0x1c58d8 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10f8> */
/* @0x1c582c ldr r3, [r4, #0x10] */
/* @0x1c5830 cmp r3, #0 */
/* @0x1c5834 ble 0x1c58d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10f0> */
/* @0x1c5838 ldr r6, [pc, #-0xb78] */
/* @0x1c583c mov r5, r9 */
/* @0x1c5840 mov r8, #1 */
/* @0x1c5844 mvn r7, #0 */
/* @0x1c5848 add r6, pc, r6 */
/* @0x1c584c mov r3, #1 */
/* @0x1c5850 mov r0, #32 */
/* @0x1c5854 mov r1, r6 */
/* @0x1c5858 mov r2, #63 */
/* @0x1c585c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c5860 ldr r3, [r4] */
/* @0x1c5864 cmp r0, #0 */
/* @0x1c5868 beq 0x1c588c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x10ac> */
/* @0x1c586c strb r5, [r0, #0x8] */
/* @0x1c5870 str r5, [r0, #0xc] */
/* @0x1c5874 str r5, [r0, #0x10] */
/* @0x1c5878 str r5, [r0, #0x14] */
/* @0x1c587c str r5, [r0, #0x18] */
/* @0x1c5880 str r7, [r0, #0x4] */
/* @0x1c5884 str r5, [r0, #0x1c] */
/* @0x1c5888 str r8, [r0] */
/* @0x1c588c cmp r3, #0 */
/* @0x1c5890 strne r0, [r3, #0x18] */
/* @0x1c5894 streq r3, [r0, #0x18] */
/* @0x1c5898 add r9, r9, #1 */
/* @0x1c589c streq r3, [r0, #0x14] */
/* @0x1c58a0 strne r3, [r0, #0x14] */
/* @0x1c58a4 ldr r3, [r4, #0x10] */
/* @0x1c58a8 ldr r2, [r4, #0x8] */
/* @0x1c58ac streq r0, [r4, #0x4] */
/* @0x1c58b0 streq r0, [r4] */
/* @0x1c58b4 add r2, r2, #1 */
/* @0x1c58b8 strne r0, [r4] */
/* @0x1c58bc strne r5, [r0, #0x18] */
/* @0x1c58c0 cmp r9, r3 */
/* @0x1c58c4 str r2, [r4, #0x8] */
/* @0x1c58c8 blt 0x1c584c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x106c> */
/* @0x1c58cc ldr r9, [r4, #0x8] */
/* @0x1c58d0 lsl r3, r3, #1 */
/* @0x1c58d4 str r3, [r4, #0x10] */
/* @0x1c58d8 ldr r5, [r4] */
/* @0x1c58dc sub r9, r9, #1 */
/* @0x1c58e0 ldr r1, [pc, #-0xc1c] */
/* @0x1c58e4 mov r0, #44 */
/* @0x1c58e8 ldr r3, [r5, #0x18] */
/* @0x1c58ec add r1, pc, r1 */
/* @0x1c58f0 ldr r2, [r5, #0x14] */
/* @0x1c58f4 cmp r3, #0 */
/* @0x1c58f8 strne r2, [r3, #0x14] */
/* @0x1c58fc ldrne r2, [r5, #0x14] */
/* @0x1c5900 ldrne r3, [r5, #0x18] */
/* @0x1c5904 streq r2, [r4] */
/* @0x1c5908 cmp r2, #0 */
/* @0x1c590c streq r3, [r4, #0x4] */
/* @0x1c5910 strne r3, [r2, #0x18] */
/* @0x1c5914 mov r2, #608 */
/* @0x1c5918 ldr r3, [r11, #0x4] */
/* @0x1c591c str r9, [r4, #0x8] */
/* @0x1c5920 str r3, [r5, #0x4] */
/* @0x1c5924 mov r3, #1 */
/* ── 44 字节子对象：初值 0 + 5 个 0.0f ────────────────────────────
 *   1c5938..1c5948 vstr s18 = 0.0f → +0x0c/+0x10/+0x1c/+0x20/+0x24
 *   1c594c..1c595c 字节 +0x00/+0x01/+0x08/+0x09/+0x14 = 0
 *   1c5954/1c5964/1c5968 字 +0x04/+0x18/+0x28 = 0
 *   1c596c 元素+0x1c = 子对象
 */

/* @0x1c5928 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c592c subs r3, r0, #0 */
/* @0x1c5930 beq 0x1c596c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x118c> */
/* @0x1c5934 mov r2, #0 */
/* @0x1c5938 vstr s18, [r3, #12] */
/* @0x1c593c vstr s18, [r3, #16] */
/* @0x1c5940 vstr s18, [r3, #28] */
/* @0x1c5944 vstr s18, [r3, #32] */
/* @0x1c5948 vstr s18, [r3, #36] */
/* @0x1c594c strb r2, [r3] */
/* @0x1c5950 strb r2, [r3, #0x1] */
/* @0x1c5954 str r2, [r3, #0x4] */
/* @0x1c5958 strb r2, [r3, #0x8] */
/* @0x1c595c strb r2, [r3, #0x9] */
/* @0x1c5960 strb r2, [r3, #0x14] */
/* @0x1c5964 str r2, [r3, #0x18] */
/* @0x1c5968 str r2, [r3, #0x28] */
/* @0x1c596c str r3, [r5, #0x1c] */
/* @0x1c5970 mov r2, r5 */
/* ── 子对象 13 字段逐字搬（源子对象在 r1 = [src+0x1c]）──────────────
 *   +0x00 字节、+0x01 字节、+0x04 字、+0x08 字节、+0x09 字节、+0x0c 字、+0x10 字、
 *   +0x14 字节、+0x18 字、+0x1c 字、+0x20 字、+0x24 字、+0x28 字
 *   ⇒ 与 DeSerializeLayer 第一组读进 44 字节子对象的 13 个字段一一对应（顺序也一致）
 */

/* @0x1c5974 ldr r1, [r11, #0x1c] */
/* @0x1c5978 ldr r12, [r11, #0xc] */
/* @0x1c597c ldrb lr, [r1] */
/* @0x1c5980 ldr r7, [r1, #0x1c] */
/* @0x1c5984 ldr r6, [r1, #0xc] */
/* @0x1c5988 ldrb r0, [r1, #0x1] */
/* @0x1c598c strb lr, [r3] */
/* @0x1c5990 ldr lr, [r1, #0x4] */
/* @0x1c5994 strb r0, [r3, #0x1] */
/* @0x1c5998 ldrb r0, [r1, #0x8] */
/* @0x1c599c str lr, [r3, #0x4] */
/* @0x1c59a0 ldrb lr, [r1, #0x9] */
/* @0x1c59a4 ldr r4, [r1, #0x18] */
/* @0x1c59a8 strb r0, [r3, #0x8] */
/* @0x1c59ac ldrb r0, [r1, #0x14] */
/* @0x1c59b0 strb lr, [r3, #0x9] */
/* @0x1c59b4 ldr lr, [r1, #0x10] */
/* @0x1c59b8 strb r0, [r3, #0x14] */
/* @0x1c59bc ldr r0, [r1, #0x20] */
/* @0x1c59c0 str lr, [r3, #0x10] */
/* @0x1c59c4 ldr lr, [r1, #0x28] */
/* @0x1c59c8 ldr r1, [r1, #0x24] */
/* @0x1c59cc str r7, [r3, #0x1c] */
/* @0x1c59d0 str r6, [r3, #0xc] */
/* @0x1c59d4 str r4, [r3, #0x18] */
/* @0x1c59d8 str r0, [r3, #0x20] */
/* @0x1c59dc str r1, [r3, #0x24] */
/* @0x1c59e0 str lr, [r3, #0x28] */
/* @0x1c59e4 mov r3, #0 */
/* @0x1c59e8 ldr r0, [sp, #0xc] */
/* @0x1c59ec ldr r1, [sp, #0x4] */
/* @0x1c59f0 str r12, [r5, #0xc] */
/* @0x1c59f4 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c59f8 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── 两条浅路径的汇合点：名字为空 / 名字在 wad 内，都把 r0 原样写进新层 +0x1c ──
 *   然后 b 1c4c3c 回元素循环
 */

/* @0x1c59fc ldr r4, [sp, #0x4] */
/* @0x1c5a00 str r0, [r4, #0x1c] */
/* @0x1c5a04 b 0x1c4c3c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x45c> */
/* ── case 3 的第二入口条件：+0x1c 为空但 +0x2c > 0 时仍造元素（1c5a10 回 1c54d0）──
 *   否则（+0x2c <= 0）→ 1c4ed0 跳过
 */

/* @0x1c5a08 ldr r3, [r11, #0x2c] */
/* @0x1c5a0c cmp r3, #0 */
/* @0x1c5a10 bgt 0x1c54d0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0xcf0> */
/* @0x1c5a14 b 0x1c4ed0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x6f0> */
/* ── 目标层链为空时的首插：room+0xd4 = room+0xd8 = 新层，next/prev 清零 ──────
 *   1c5a20/1c5a24 两个字段写同一个指针；1c5a28/1c5a2c 把 +0x6c(prev) 与 +0x68(next) 清零
 *   随后 b 1c4f1c 走公共的 CHashMap 插入
 */

/* @0x1c5a18 ldr r4, [sp, #0x4] */
/* @0x1c5a1c ldr r12, [sp, #0xc] */
/* @0x1c5a20 str r4, [r12, #0xd8] */
/* @0x1c5a24 str r4, [r12, #0xd4] */
/* @0x1c5a28 str r3, [r4, #0x6c] */
/* @0x1c5a2c str r3, [r4, #0x68] */
/* @0x1c5a30 b 0x1c4f1c <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_+0x73c> */
