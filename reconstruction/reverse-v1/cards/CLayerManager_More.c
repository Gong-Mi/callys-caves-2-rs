/* cally 逆向卡：CLayer 管理六件（原版 libyoyo.so，armv7）—— 一卡六节
 * @func 0x1b6f00 0x1b7700  size 2048  510 条  _ZN13CLayerManager4InitEv
 * @func 0x1c30f8 0x1c33e4  size 748  187 条  _ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer
 * @func 0x1b8868 0x1b8930  size 200  50 条  _ZN13CLayerManager14GetLayerFromIDEP5CRoomi
 * @func 0x1b8200 0x1b87f4  size 1524  381 条  _ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib
 * @func 0x1b8948 0x1b897c  size 52  13 条  _ZN13CLayerManager16ChangeLayerDepthEP5CRoomiib
 * @func 0x1c5ff0 0x1c606c  size 124  31 条  _ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb
 * 总账: 1172 锚点 = 1172 字，与 asm/index-CLayerManager_More_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py → index=1172 card=1172 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 *       ⚠ 唯一不对应字节的是 §1 的 1b7378/1b737c：d9 的 8 字节零字，objdump 按零字省略，索引里本来就没有这两行，
 *         本卡也不给它们锚点（写上去反而会算 extra）。
 * 级别: 六节都是「正文」，每节末尾单列 open；§4 的合流分支标了「静态可达但只在单一条件下触发」，不冒充常规路径。
 * 锚点来源: 全部由 scripts/asm_index.py 从二进制生成后逐行照抄，本卡没有手写转录；字面量池里被 objdump 译成指令的字
 *       保留原样（如 andseq / svclo），各节注释里点名「这是池字，不是指令」。
 *
 * ── 本卡要回答的三个问题 ────────────────────────────────────────────────
 *   ① 初始化：CLayer 系统一共几个池、各多大、各预分配多少、初值是谁写的、写在哪一行源码。
 *   ② 改层深：链（room+0xd4 的 depth 升序双链）怎么摘、怎么插、同 depth 时插在组头还是组尾。
 *   ③ 表：层 id 表（room+0xe4 簇）在「入链」和「改深」时各被怎么改，删除是哪种算法。
 *
 * ── 全局坐标（本轮实测：.rel.dyn 全是 R_ARM_RELATIVE，加数就地存在 GOT 槽里，逐个读出来的）──
 *   GOT 槽      目标        符号（.dynsym 原名，全部带 CLayerManager:: 前缀）
 *   0x3f0860 → 0x5425ed   m_bInitialised（1 B）
 *   0x3f0864 → 0x5426a0   m_LayerPool（20 B，层池）
 *   0x3f0868 → 0x54268c   m_BackgroundElementPool（32 B 元素）
 *   0x3f086c → 0x542678   m_InstanceElementPool（36 B）
 *   0x3f0870 → 0x542664   m_OldTilemapElementPool（52 B）
 *   0x3f0874 → 0x542650   m_SpriteElementPool（72 B）
 *   0x3f0878 → 0x54263c   m_TilemapElementPool（60 B）
 *   0x3f087c → 0x542628   m_ParticleElementPool（32 B）
 *   0x3f0880 → 0x542614   m_TileElementPool（80 B）
 *   0x3f0884 → 0x5425fc   m_TilePool（1804 B = 0x70c）
 *   0x3f0820 → 0x3f50e0   ★ 无名 int（.data）。Init 收尾写它 = 0x7fffffff；F_TilemapSet / F_TilemapSetAtPixel
 *                          读它当「tile 标志掩码」，与 elem+0x38 相与（本卡按行为叫它 g_TileFlagsMask，名字未证）
 *   0x3edc78 → 0x542610   m_pScriptInstance（CInstance*）：Init/Close 删它并置 0，ExecuteLayerScript 拿它当 self/other
 *   0x3f0ae8 → 0x5425f0   m_CurrentElementID · 0x3f0ae4 → 0x5425f4 m_CurrentLayerID · 0x3f0888 → 0x5425f8 m_LayerIDWatermark
 *   基址寄存器一律是 0x3f1c58（= 函数体里 add rX, pc, rX 得到的 GOT 基址），所以「槽 = 0x3f1c58 + 负偏移」。
 *   本卡里 §1 是唯一用「逐条 ldr rX,[pc,#imm] 再 ldr rX,[pc,rX]」双段寻址的（没有 base 寄存器），
 *   算法：字面量地址 = ldr 地址 + 8 + imm；槽 = (第二条 ldr 地址 + 8) + 字面量值。
 *
 * ── 三个结构的公共知识（后文各节只写差分）─────────────────────────────────
 *   CPool（20 B，9 个池共用；源码在 Room_Layers.h）：
 *     +0x00 自由链头 +0x04 自由链尾 +0x08 可用数 +0x0c 恒写 3（本卡未找到读方）+0x10 容量
 *     取用 = 头弹出（+0x08 - 1）；归还 = 头插；扩容 = 可用数 0 时按容量循环 Alloc 再「容量 <<= 1」。
 *     （取用/扩容两段由 LayerHelpers 卡 §3 AddDynamicLayer 逐条证过，本卡只复述；本卡新增的是「Init 怎么把它们铺满」。）
 *     链接字段：层 +0x68(next)/+0x6c(prev)；元素 +0x14(next)/+0x18(prev)；tile +0x704(next)/+0x708(prev)。
 *   CLayer（112 B）：+0x00 id +0x04 depth +0x08 x +0x0c y +0x10 hspeed +0x14 vspeed
 *     +0x18 visible(1 B) +0x19 动态层筛子(1 B) +0x1c name +0x20/+0x24/+0x28 = -1
 *     +0x30..+0x57 CTimingSource +0x58 元素链头 +0x5c 链尾 +0x60 元素数
 *     +0x64 回收档(1/2/3) +0x68 next +0x6c prev
 *   room 侧：+0xd4 层链头 +0xd8 层链尾 +0xdc 层数；表 1 = room+0xe4 簇（+0xe4 容量/+0xe8 已用/+0xec 掩码/+0xf0 阈值/+0xf4 桶）；
 *     表 2 = room+0xf8 簇（元素 uid → 元素）；表 3 = room+0x110 簇（实例 id → 实例元素）。
 *     桶项 12 B：+0x00 键(int) +0x04 值(指针) +0x08 哈希（== 0 表示空桶）。
 *   哈希：CHashMapCalculateHash<int> 0x1b6e44 = `add r0,r0,#1`，即 h = key + 1（在 int 上是单射 ⇒
 *     「哈希相等」等价于「键相等」，后文 §3/§4 的查找都只比哈希不比键，正是靠这一条）。
 *
 * ── 跨节结论（四条，全部有锚点支撑）───────────────────────────────────────
 *   A. Init 只做三件事：9 个池预分配、m_pScriptInstance 清场、m_bInitialised 置 1；收尾（含「已初始化」的早退）
 *      一律把 g_TileFlagsMask 写 0x7fffffff。它**不碰任何 CHashMap**，也不碰三个 id 计数器 —— 表是「每房间」的，
 *      计数器是「跨房间累计」的。
 *   B. 层链唯一的排序者就是 InsertLayerIntoActiveList：按 +0x04 升序，同 depth 一律排在**该组末尾**（后面追加）。
 *      ChangeLayerDepth 摘了再插时，减深落在**同 depth 组首**、加深落在**组尾** —— 两个方向不同，容易读错。
 *   C. 层 id 表（表 1）只有三个写点：InsertLayerIntoActiveList（upsert：先 used+1，命中同键再 used-1）、
 *      ChangeLayerDepth 的合流分支（后移填补式删除）、DuplicateRoomLayers / CRoom 侧的批量重建。
 *   D. AddNewElement 是「发 uid → AddElementToLayer(头插 + 表 2 + 表 3) → 可选建运行期数据」的三段流水；
 *      它把插链的第 4 实参**恒写 0**，所以 AddNewElement 挂的元素永远进层头（AddInstanceToLayer 才做尾插）。
 */

/* ══ §1 CLayerManager::Init 0x1b6f00 ═══════════════════════════════════════
 * @func 0x1b6f00 0x1b7700  size 2048  510 条（512 字 - 1b7378/1b737c 两个零字）
 * 级别: 正文（510/510。九个池的「头清零 → 预分配 → 写初值 → 头插自由链 → 写容量」五段全部逐条落锚；
 *       收尾三件事与「已初始化」早退也全部解出。未钉：+0x0c 恒写 3 的语义与读方、g_TileFlagsMask 的正式名、
 *       为什么 tile 池只预分配 32 个而 tile 元素池要 1024 个）
 * 符号: _ZN13CLayerManager4InitEv → void CLayerManager::Init()
 * 调用者（全库唯一）：CLayerManager::BuildRoomLayers 0x1c6c6c（`bl`；那张卡已证：块头门为 0 时先 Init() 再回 0x1c60b4 重读块头）
 * 读 m_bInitialised 的三处：Init 0x1b6f20、Close 0x1b7714（0x3f0860 同一槽）、BuildRoomLayers 0x1c6454 的池字
 * 同层: Close 0x1b7700（严格镜像：按 +0x64 回收层内元素 → 逐池 Free）、AddDynamicLayer 0x1c33e4（扩容模板与本函数逐字同构）、
 *       MemoryManager::Alloc 0x27ce78、CTimingSource::Reset 0x214728
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   首次调用时把 9 个池各预分配一批对象、全部串进自由链；删掉上一轮残留的 m_pScriptInstance；
 *   置 m_bInitialised = 1；然后（两条路径都）落到同一个尾巴：g_TileFlagsMask = 0x7fffffff，返回。
 *
 * ── 控制流（只有一个分叉）───────────────────────────────────────────────
 *   入口读 m_bInitialised：== 0 → 1b6f60 建池；!= 0 → 1b6f2c（三条指令）写掩码后返回。
 *   建池完 → 1b76f0 置 m_bInitialised = 1 → 1b76fc `b 1b6f2c` → 同一段收尾。
 *   ⇒ 「已初始化」不是一个空返回：它每次都把 g_TileFlagsMask 重置成 0x7fffffff。
 *   ⇒ BuildRoomLayers 只调一次 Init，但每次进房间文件都会走一遍这条「掩码复位」。
 *
 * ── 九个池（本卡的核心表；顺序即代码顺序）──────────────────────────────────
 *   序 池（符号）                     对象大小  预分配  容量(+0x10)  本函数写进去的初值
 *   ① m_LayerPool          0x5426a0    112      32      32        CLayer 全字段（见 ①）
 *   ② m_BackgroundElementPool 0x54268c   32      32      32        type=1, uid=-1, +0x08..+0x1c=0
 *   ③ m_InstanceElementPool   0x542678   36     256     256        type=2, uid=-1, +0x1c=-1, +0x20=0, 其余 0
 *   ④ m_OldTilemapElementPool 0x542664   52      32      32        type=3, uid=-1, +0x30=1, 其余 0
 *   ⑤ m_SpriteElementPool     0x542650   72      64      64        type=4, uid=-1, +0x1c=-1, +0x38=-1,
 *                                                                 +0x24/+0x2c/+0x30/+0x3c = 1.0f，其余 0
 *   ⑥ m_TilemapElementPool    0x54263c   60      32      32        type=5, uid=-1, +0x1c=-1, +0x38=0x7fffffff，
 *                                                                 +0x20/+0x24/+0x30 = 0
 *   ⑦ m_ParticleElementPool   0x542628   32      32      32        type=6, uid=-1, +0x1c=-1, 其余 0
 *   ⑧ m_TileElementPool       0x542614   80    1024    1024        type=7, uid=-1, +0x20=-1, +0x40=-1,
 *                                                                 +0x34/+0x38/+0x44 = 1.0f，其余 0
 *   ⑨ m_TilePool              0x5425fc 1804      32      32        ★ 只写 +0x700=0、+0x704=next、+0x708=prev
 *   合计预分配 32*112 + 32*32 + 256*36 + 32*52 + 64*72 + 32*60 + 32*32 + 1024*80 + 32*1804 = 162,688 B。
 *   ⇒ 带 float 初值的是 ①③⑤⑧（层 + 实例/精灵/tile 元素四种）；元素 uid 一律 -1（哈希 = uid+1 = 0 = 空桶标记，
 *     详见 AddElementToLayer 卡的「空桶判据」）。
 *
 * ── 五段模板（①为样板，②..⑨ 只差数字）──────────────────────────────────
 *   甲 头清零：`str 0,[pool]`（头）、`[pool+4]`（尾）、`[pool+8]`（可用数）、`str 3,[pool+0xc]`。
 *      ⚠ 这里的 0 寄存器不是新起的：r3 就是入口 `ldrb` 读到的那个 0 字节，后续池复用循环计数器的残值（r9/r4/r11 等）。
 *      读第二段以后各池时，看到 `str r9,[r5]` 别以为 r9 有别的含义 —— 它只是「上一轮循环跑完剩下的 0」。
 *   乙 预分配：`bl MemoryManager::Alloc(大小, "jni/../jni/yoyo/../../../Files/Room/Room_Layers.h", 45, 1)`，
 *      九处**行号全是 45、文件串全同**（0x34d69c）。⇒ 这不是各元素的 ctor，而是 Room_Layers.h 里同一个
 *      「池::预留 N 个」内联（第 45 行）；AddDynamicLayer 扩容走的同一族内联在**第 63 行**（见 LayerHelpers §3）。
 *   丙 写初值：只在本轮 Alloc 成功（r6/r0 != 0）时执行；失败则跳过整段初值但仍会执行丁的链接（计数照样 +1）。
 *   丁 头插自由链（层/元素/tile 三套链接偏移，逻辑逐字相同）：
 *        head == 0 → tail = obj；head = obj；obj->next = 0；obj->prev = 0
 *        head != 0 → head->prev = obj；obj->next = head；obj->prev = 0；head = obj
 *        count(=+0x08) += 1（两条路都加）
 *      ⇒ 「尾」只在**第一次**插入时写，之后一直是**最早**那个对象的地址；弹出永远从 head 取（LIFO）。
 *   戊 容量：循环退出后 `str N,[pool+0x10]`，N = 本轮预分配个数。
 *
 * ── 收尾（1b76c4..1b76fc）───────────────────────────────────────────────
 *   `ldr r4,[r12, slot 0x3edc78]` → r4 = &m_pScriptInstance(0x542610)；若非空：
 *   `r3 = *obj; r3 = *(r3+4); blx r3` = 虚表槽 1 = 删除析构；然后 `*r4 = 0`（r5 恰为 0：⑨ 的循环计数器）。
 *   再 `strb 1,[&m_bInitialised]`，`b 1b6f2c` → 掩码 = 0x7fffffff → 返回。
 *   ⇒ m_pScriptInstance 是**单例 CInstance**：ExecuteLayerScript 0x1b3418 把 `*[0x542610]` 同时当 self 与 other
 *     传给 Script_Perform（1b3488/1b34a0）。Init 先删旧的再建池，Close 0x1b79a0 也删同一个 ⇒ 这是「跨 Init/Close 周期
 *     唯一被显式销毁的全局对象」。
 *
 * ── 本函数**没有**做的事（都是容易误以为有的）────────────────────────────
 *   · 不初始化任何 CHashMap：全函数没有一次对 room+0xe4/+0xf8/+0x110 簇的写（那三张表是每房间的，
 *     由 CRoom 侧 / DuplicateRoomLayers / DeSerializeLayer 建）。
 *   · 不复位 m_CurrentLayerID / m_CurrentElementID / m_LayerIDWatermark（0x5425f4/f0/f8 一次都没出现）。
 *   · 不写 CLayer 的 +0x2c（与 LayerHelpers 卡的「+0x2c 无写方」一致：Init 也不写）。
 *   · 不为 tile 池写对象内容 —— tile 块的 +0x00..+0x6ff 在池里是未初始化内存，谁弹出谁负责填。
 */

/* ── ⓪ 入口：栈帧、GOT 基址、读 m_bInitialised ────────────────────────────
 *   r7 = (1b6f1c) + 0x0023ad3c = 0x3f1c58（GOT 基址）；r3 = *(0x3f1c58-0x13f8) = &m_bInitialised；
 *   ldrb → 0 落到 1b6f60 建池，非 0 落到 1b6f2c 只写掩码。
 */
/* @0x1b6f00 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b6f04 vpush {d8, d9} */
/* @0x1b6f08 sub sp, sp, #12 */
/* @0x1b6f0c ldr r7, [pc, #0x34] */
/* @0x1b6f10 ldr r3, [pc, #0x34] */
/* @0x1b6f14 add r7, pc, r7 */
/* @0x1b6f18 ldr r3, [r7, r3] */
/* @0x1b6f1c str r3, [sp, #0x4] */
/* @0x1b6f20 ldrb r3, [r3] */
/* @0x1b6f24 cmp r3, #0 */
/* @0x1b6f28 beq 0x1b6f60 <_ZN13CLayerManager4InitEv+0x60> */
/* ── ⓘ 收尾/早退共用尾：g_TileFlagsMask = 0x7fffffff ──────────────────────
 *   mvn r2,#-2147483648 编码的立即数是 0x80000000 ⇒ 取反后 r2 = 0x7fffffff（不是负数）。
 *   槽 0x3f1c58-0x1438 = 0x3f0820 → 0x3f50e0（.data 里一个无名 int）。
 */
/* @0x1b6f2c ldr r3, [pc, #0x1c] */
/* @0x1b6f30 mvn r2, #-2147483648 */
/* @0x1b6f34 ldr r3, [r7, r3] */
/* @0x1b6f38 str r2, [r3] */
/* @0x1b6f3c add sp, sp, #12 */
/* @0x1b6f40 vpop {d8, d9} */
/* @0x1b6f44 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 字面量池 1b6f48..1b6f5c（6 字，非指令）────────────────────────────────
 *   前六字里 1b6f48（eoreq）/1b6f58（andseq）/1b6f5c（andeq）是 objdump 把数据译成了指令，非指令。
 *   1b6f48 = 0x0023ad3c（GOT 基址相对量）  1b6f4c = 0xffffec08 → 槽 0x3f0860 → &m_bInitialised
 *   1b6f50 = 0xffffebc8 → 槽 0x3f0820 → 0x3f50e0   1b6f54 = 0xffffec0c → 槽 0x3f0864 → m_LayerPool
 *   1b6f58 = 0x00196718 → 串 0x34d69c（Room_Layers.h）  1b6f5c = 0x00000000 → s16 = 0.0f
 */
/* @0x1b6f48 eoreq r10, r3, r12, lsr sp */
/* @0x1b6f4c .word 0xffffec08 */
/* @0x1b6f50 .word 0xffffebc8 */
/* @0x1b6f54 .word 0xffffec0c */
/* @0x1b6f58 andseq r6, r9, r8, lsl r7 */
/* @0x1b6f5c andeq r0, r0, r0 */
/* ── ① m_LayerPool 0x5426a0：112 B × 32 ────────────────────────────────────
 *   甲：头/尾/可用数 = 0、+0x0c = 3；乙：Alloc(112, Room_Layers.h, 45, 1) 共 32 次（r9 计数）。
 *   s16 = 0.0f（+0x08..+0x14 四个 float）；d9 = 0（+0x48/+0x4c 两个字）。
 */
/* @0x1b6f60 ldr r1, [pc, #-0x14] */
/* @0x1b6f64 mov r9, #32 */
/* @0x1b6f68 ldr r11, [pc, #-0x18] */
/* @0x1b6f6c mov r10, #1 */
/* @0x1b6f70 mov r2, #3 */
/* @0x1b6f74 vldr s16, [pc, #-32] */
/* @0x1b6f78 ldr r8, [r7, r1] */
/* @0x1b6f7c add r11, pc, r11 */
/* @0x1b6f80 vldr d9, [pc, #1008] */
/* @0x1b6f84 str r3, [r8, #0x4] */
/* @0x1b6f88 str r3, [r8] */
/* @0x1b6f8c str r3, [r8, #0x8] */
/* @0x1b6f90 str r2, [r8, #0xc] */
/* @0x1b6f94 mov r2, #45 */
/* @0x1b6f98 mov r0, #112 */
/* @0x1b6f9c mov r1, r11 */
/* @0x1b6fa0 mov r3, #1 */
/* @0x1b6fa4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b6fa8 mov r4, #0 */
/* @0x1b6fac mvn r2, #0 */
/* @0x1b6fb0 subs r6, r0, #0 */
/* @0x1b6fb4 add r0, r6, #48 */
/* @0x1b6fb8 beq 0x1b700c <_ZN13CLayerManager4InitEv+0x10c> */
/* ── ①-b CLayer 初值（只在 Alloc 成功时执行；r2 = -1，r4/r11 = 0，r10 = 1）─────
 *   +0x00 id = -1   +0x04 depth = 0   +0x08 x/+0x0c y/+0x10 hspeed/+0x14 vspeed = 0.0f
 *   +0x18 visible = 1   +0x19 动态筛子 = 0   +0x1c name = 0   +0x20/+0x24/+0x28 = -1
 *   +0x48/+0x4c = 0（vstr d9）→ CTimingSource::Reset(+0x30) → +0x58/+0x5c/+0x60 = 0
 *   +0x64 = 1（回收档）   +0x68/+0x6c = 0。**+0x2c 不写**（全库无写方）。
 */
/* @0x1b6fbc str r2, [r6] */
/* @0x1b6fc0 vstr s16, [r6, #8] */
/* @0x1b6fc4 str r4, [r6, #0x4] */
/* @0x1b6fc8 vstr s16, [r6, #12] */
/* @0x1b6fcc vstr s16, [r6, #16] */
/* @0x1b6fd0 vstr s16, [r6, #20] */
/* @0x1b6fd4 strb r10, [r6, #0x18] */
/* @0x1b6fd8 vstr d9, [r6, #72] */
/* @0x1b6fdc strb r4, [r6, #0x19] */
/* @0x1b6fe0 str r4, [r6, #0x1c] */
/* @0x1b6fe4 str r2, [r6, #0x20] */
/* @0x1b6fe8 str r2, [r6, #0x24] */
/* @0x1b6fec str r2, [r6, #0x28] */
/* @0x1b6ff0 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b6ff4 str r4, [r6, #0x5c] */
/* @0x1b6ff8 str r4, [r6, #0x58] */
/* @0x1b6ffc str r4, [r6, #0x60] */
/* @0x1b7000 str r10, [r6, #0x64] */
/* @0x1b7004 str r4, [r6, #0x68] */
/* @0x1b7008 str r4, [r6, #0x6c] */
/* ── ①-c 头插自由链（层版；head==0 与 !=0 两路，写 +0x68/+0x6c，计数 +1）────── */
/* @0x1b700c ldr r3, [r8] */
/* @0x1b7010 mov r1, #0 */
/* @0x1b7014 ldr r2, [r8, #0x8] */
/* @0x1b7018 cmp r3, r1 */
/* @0x1b701c streq r6, [r8, #0x4] */
/* @0x1b7020 strne r6, [r3, #0x6c] */
/* @0x1b7024 add r2, r2, #1 */
/* @0x1b7028 streq r6, [r8] */
/* @0x1b702c streq r3, [r6, #0x6c] */
/* @0x1b7030 streq r3, [r6, #0x68] */
/* @0x1b7034 strne r6, [r8] */
/* @0x1b7038 strne r3, [r6, #0x68] */
/* @0x1b703c strne r1, [r6, #0x6c] */
/* @0x1b7040 subs r9, r9, #1 */
/* @0x1b7044 str r2, [r8, #0x8] */
/* @0x1b7048 bne 0x1b6f94 <_ZN13CLayerManager4InitEv+0x94> */
/* ── ② m_BackgroundElementPool 0x54268c：32 B × 32，type=1 ─────────────────
 *   初值：+0x00=1 +0x04=-1 +0x08(byte)/+0x0c/+0x10/+0x14/+0x18/+0x1c = 0。
 *   链接改元素版 +0x14/+0x18（同一段模板，只有两个偏移不同）。
 */
/* @0x1b704c ldr r2, [pc, #0x32c] */
/* @0x1b7050 mov r3, #32 */
/* @0x1b7054 ldr r6, [pc, #0x328] */
/* @0x1b7058 mov r11, #1 */
/* @0x1b705c str r3, [r8, #0x10] */
/* @0x1b7060 mvn r10, #0 */
/* @0x1b7064 ldr r5, [r7, r2] */
/* @0x1b7068 add r6, pc, r6 */
/* @0x1b706c mov r8, r9 */
/* @0x1b7070 mov r4, r3 */
/* @0x1b7074 mov r3, #3 */
/* @0x1b7078 str r9, [r5, #0x4] */
/* @0x1b707c str r9, [r5] */
/* @0x1b7080 str r9, [r5, #0x8] */
/* @0x1b7084 str r3, [r5, #0xc] */
/* @0x1b7088 mov r3, #1 */
/* @0x1b708c mov r0, #32 */
/* @0x1b7090 mov r1, r6 */
/* @0x1b7094 mov r2, #45 */
/* @0x1b7098 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b709c ldr r3, [r5] */
/* @0x1b70a0 cmp r0, #0 */
/* @0x1b70a4 beq 0x1b70c8 <_ZN13CLayerManager4InitEv+0x1c8> */
/* @0x1b70a8 strb r8, [r0, #0x8] */
/* @0x1b70ac str r8, [r0, #0xc] */
/* @0x1b70b0 str r8, [r0, #0x10] */
/* @0x1b70b4 str r8, [r0, #0x14] */
/* @0x1b70b8 str r8, [r0, #0x18] */
/* @0x1b70bc str r10, [r0, #0x4] */
/* @0x1b70c0 str r8, [r0, #0x1c] */
/* @0x1b70c4 str r11, [r0] */
/* @0x1b70c8 cmp r3, #0 */
/* @0x1b70cc ldr r2, [r5, #0x8] */
/* @0x1b70d0 strne r0, [r3, #0x18] */
/* @0x1b70d4 streq r0, [r5, #0x4] */
/* @0x1b70d8 add r2, r2, #1 */
/* @0x1b70dc streq r0, [r5] */
/* @0x1b70e0 streq r3, [r0, #0x18] */
/* @0x1b70e4 streq r3, [r0, #0x14] */
/* @0x1b70e8 strne r0, [r5] */
/* @0x1b70ec strne r3, [r0, #0x14] */
/* @0x1b70f0 strne r8, [r0, #0x18] */
/* @0x1b70f4 subs r4, r4, #1 */
/* @0x1b70f8 str r2, [r5, #0x8] */
/* @0x1b70fc bne 0x1b7088 <_ZN13CLayerManager4InitEv+0x188> */
/* ── ③ m_InstanceElementPool 0x542678：36 B × 256（唯一 256 个的元素池）───────
 *   初值：+0x00=2 +0x04=-1 +0x1c=-1 +0x20=0，其余 0。r8 是计数 256（不是 32）。
 */
/* @0x1b7100 ldr r3, [pc, #0x280] */
/* @0x1b7104 mov r2, #32 */
/* @0x1b7108 ldr r9, [pc, #0x27c] */
/* @0x1b710c mov r10, r4 */
/* @0x1b7110 str r2, [r5, #0x10] */
/* @0x1b7114 mov r8, #256 */
/* @0x1b7118 ldr r5, [r7, r3] */
/* @0x1b711c add r9, pc, r9 */
/* @0x1b7120 mvn r6, #0 */
/* @0x1b7124 mov r3, #3 */
/* @0x1b7128 str r4, [r5, #0x4] */
/* @0x1b712c str r4, [r5] */
/* @0x1b7130 str r4, [r5, #0x8] */
/* @0x1b7134 str r3, [r5, #0xc] */
/* @0x1b7138 mov r2, #45 */
/* @0x1b713c mov r3, #1 */
/* @0x1b7140 mov r0, #36 */
/* @0x1b7144 mov r1, r9 */
/* @0x1b7148 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b714c ldr r3, [r5] */
/* @0x1b7150 mov r2, #2 */
/* @0x1b7154 cmp r0, #0 */
/* @0x1b7158 beq 0x1b7180 <_ZN13CLayerManager4InitEv+0x280> */
/* @0x1b715c strb r10, [r0, #0x8] */
/* @0x1b7160 str r10, [r0, #0xc] */
/* @0x1b7164 str r10, [r0, #0x10] */
/* @0x1b7168 str r10, [r0, #0x14] */
/* @0x1b716c str r10, [r0, #0x18] */
/* @0x1b7170 str r6, [r0, #0x4] */
/* @0x1b7174 str r6, [r0, #0x1c] */
/* @0x1b7178 str r10, [r0, #0x20] */
/* @0x1b717c str r2, [r0] */
/* @0x1b7180 cmp r3, #0 */
/* @0x1b7184 ldr r2, [r5, #0x8] */
/* @0x1b7188 strne r0, [r3, #0x18] */
/* @0x1b718c streq r0, [r5, #0x4] */
/* @0x1b7190 add r2, r2, #1 */
/* @0x1b7194 streq r0, [r5] */
/* @0x1b7198 streq r3, [r0, #0x18] */
/* @0x1b719c streq r3, [r0, #0x14] */
/* @0x1b71a0 strne r0, [r5] */
/* @0x1b71a4 strne r3, [r0, #0x14] */
/* @0x1b71a8 strne r10, [r0, #0x18] */
/* @0x1b71ac subs r8, r8, #1 */
/* @0x1b71b0 str r2, [r5, #0x8] */
/* @0x1b71b4 bne 0x1b7138 <_ZN13CLayerManager4InitEv+0x238> */
/* ── ④ m_OldTilemapElementPool 0x542664：52 B × 32，type=3 ─────────────────
 *   初值：+0x00=3 +0x04=-1 +0x1c/+0x20/+0x24/+0x28/+0x2c = 0，**+0x30 = 1**，其余 0。
 */
/* @0x1b71b8 ldr r3, [pc, #0x1d0] */
/* @0x1b71bc mov r2, #256 */
/* @0x1b71c0 ldr r6, [pc, #0x1cc] */
/* @0x1b71c4 mov r4, r8 */
/* @0x1b71c8 str r2, [r5, #0x10] */
/* @0x1b71cc mov r11, #32 */
/* @0x1b71d0 ldr r5, [r7, r3] */
/* @0x1b71d4 add r6, pc, r6 */
/* @0x1b71d8 mov r10, #1 */
/* @0x1b71dc mvn r9, #0 */
/* @0x1b71e0 mov r3, #3 */
/* @0x1b71e4 str r8, [r5, #0x4] */
/* @0x1b71e8 str r8, [r5] */
/* @0x1b71ec str r8, [r5, #0x8] */
/* @0x1b71f0 str r3, [r5, #0xc] */
/* @0x1b71f4 mov r2, #45 */
/* @0x1b71f8 mov r3, #1 */
/* @0x1b71fc mov r0, #52 */
/* @0x1b7200 mov r1, r6 */
/* @0x1b7204 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7208 ldr r3, [r5] */
/* @0x1b720c mov r2, #3 */
/* @0x1b7210 cmp r0, #0 */
/* @0x1b7214 beq 0x1b724c <_ZN13CLayerManager4InitEv+0x34c> */
/* @0x1b7218 strb r4, [r0, #0x8] */
/* @0x1b721c str r4, [r0, #0xc] */
/* @0x1b7220 str r4, [r0, #0x10] */
/* @0x1b7224 str r4, [r0, #0x14] */
/* @0x1b7228 str r4, [r0, #0x18] */
/* @0x1b722c str r9, [r0, #0x4] */
/* @0x1b7230 str r4, [r0, #0x1c] */
/* @0x1b7234 str r4, [r0, #0x20] */
/* @0x1b7238 str r4, [r0, #0x28] */
/* @0x1b723c str r4, [r0, #0x24] */
/* @0x1b7240 str r4, [r0, #0x2c] */
/* @0x1b7244 str r10, [r0, #0x30] */
/* @0x1b7248 str r2, [r0] */
/* @0x1b724c cmp r3, #0 */
/* @0x1b7250 ldr r2, [r5, #0x8] */
/* @0x1b7254 strne r0, [r3, #0x18] */
/* @0x1b7258 streq r0, [r5, #0x4] */
/* @0x1b725c add r2, r2, #1 */
/* @0x1b7260 streq r0, [r5] */
/* @0x1b7264 streq r3, [r0, #0x18] */
/* @0x1b7268 streq r3, [r0, #0x14] */
/* @0x1b726c strne r0, [r5] */
/* @0x1b7270 strne r3, [r0, #0x14] */
/* @0x1b7274 strne r4, [r0, #0x18] */
/* @0x1b7278 subs r11, r11, #1 */
/* @0x1b727c str r2, [r5, #0x8] */
/* @0x1b7280 bne 0x1b71f4 <_ZN13CLayerManager4InitEv+0x2f4> */
/* ── ⑤ m_SpriteElementPool 0x542650：72 B × 64，type=4 ─────────────────────
 *   初值：+0x00=4 +0x04=-1 +0x1c=-1 +0x38=-1；+0x24/+0x2c/+0x30/+0x3c = 1.0f；
 *   +0x20/+0x28/+0x34/+0x40/+0x44 = 0。
 */
/* @0x1b7284 ldr r3, [pc, #0x10c] */
/* @0x1b7288 mov r2, #32 */
/* @0x1b728c ldr r9, [pc, #0x108] */
/* @0x1b7290 mov r4, r11 */
/* @0x1b7294 str r2, [r5, #0x10] */
/* @0x1b7298 mov r6, #64 */
/* @0x1b729c ldr r5, [r7, r3] */
/* @0x1b72a0 add r9, pc, r9 */
/* @0x1b72a4 mov r10, #0 */
/* @0x1b72a8 mov r3, #3 */
/* @0x1b72ac str r11, [r5, #0x4] */
/* @0x1b72b0 str r11, [r5] */
/* @0x1b72b4 str r11, [r5, #0x8] */
/* @0x1b72b8 str r3, [r5, #0xc] */
/* @0x1b72bc mov r1, r9 */
/* @0x1b72c0 mov r2, #45 */
/* @0x1b72c4 mov r0, #72 */
/* @0x1b72c8 mov r3, #1 */
/* @0x1b72cc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b72d0 ldr r2, [r5] */
/* @0x1b72d4 mvn r1, #0 */
/* @0x1b72d8 mov r12, #4 */
/* @0x1b72dc cmp r0, #0 */
/* @0x1b72e0 beq 0x1b7330 <_ZN13CLayerManager4InitEv+0x430> */
/* @0x1b72e4 mov r3, #1065353216 */
/* @0x1b72e8 strb r4, [r0, #0x8] */
/* @0x1b72ec str r4, [r0, #0xc] */
/* @0x1b72f0 str r10, [r0, #0x20] */
/* @0x1b72f4 str r4, [r0, #0x10] */
/* @0x1b72f8 str r10, [r0, #0x34] */
/* @0x1b72fc str r4, [r0, #0x14] */
/* @0x1b7300 str r10, [r0, #0x40] */
/* @0x1b7304 str r4, [r0, #0x18] */
/* @0x1b7308 str r10, [r0, #0x44] */
/* @0x1b730c str r1, [r0, #0x4] */
/* @0x1b7310 str r1, [r0, #0x1c] */
/* @0x1b7314 str r4, [r0, #0x28] */
/* @0x1b7318 str r1, [r0, #0x38] */
/* @0x1b731c str r12, [r0] */
/* @0x1b7320 str r3, [r0, #0x24] */
/* @0x1b7324 str r3, [r0, #0x2c] */
/* @0x1b7328 str r3, [r0, #0x30] */
/* @0x1b732c str r3, [r0, #0x3c] */
/* @0x1b7330 cmp r2, #0 */
/* @0x1b7334 ldr r3, [r5, #0x8] */
/* @0x1b7338 strne r0, [r2, #0x18] */
/* @0x1b733c streq r0, [r5, #0x4] */
/* @0x1b7340 add r3, r3, #1 */
/* @0x1b7344 streq r0, [r5] */
/* @0x1b7348 streq r2, [r0, #0x18] */
/* @0x1b734c streq r2, [r0, #0x14] */
/* @0x1b7350 strne r0, [r5] */
/* @0x1b7354 strne r2, [r0, #0x14] */
/* @0x1b7358 strne r4, [r0, #0x18] */
/* @0x1b735c subs r6, r6, #1 */
/* @0x1b7360 str r3, [r5, #0x8] */
/* @0x1b7364 bne 0x1b72bc <_ZN13CLayerManager4InitEv+0x3bc> */
/* ── ⑥ m_TilemapElementPool 0x54263c：60 B × 32，type=5（主体在 1b73c4）───── */
/* @0x1b7368 ldr r3, [pc, #0x30] */
/* @0x1b736c mov r2, #64 */
/* @0x1b7370 b 0x1b73c4 <_ZN13CLayerManager4InitEv+0x4c4> */
/* ── 字面量池 1b7374..1b73c0（nop + 10 字，非指令）──────────────────────────
 *   1b7374 nop = 对齐填充；1b7378/1b737c = d9 的 8 字节零（objdump 省略，索引里没有）⇒ 本卡不给锚点。
 *   1b7380..1b73bc 是 ②..⑨ 八个池的「槽偏移 + Alloc 文件串偏移」四字一组交替（ec10/ec14/ec18/ec1c/ec20/ec24/ec28/ec2c
 *   各配一个 0x0019xxxx 串偏移，1b7384/1b738c/… 那几行也是池字，objdump 译成 andseq 而已），
 *   1b73c0 = 0xffffc020 → 槽 0x3edc78 → m_pScriptInstance。
 */
/* @0x1b7374 nop */
/* @0x1b7380 .word 0xffffec10 */
/* @0x1b7384 andseq r6, r9, r12, lsr #12 */
/* @0x1b7388 .word 0xffffec14 */
/* @0x1b738c andseq r6, r9, r8, ror r5 */
/* @0x1b7390 .word 0xffffec18 */
/* @0x1b7394 andseq r6, r9, r0, asr #9 */
/* @0x1b7398 .word 0xffffec1c */
/* @0x1b739c ldrsheq r6, [r9], -r4 */
/* @0x1b73a0 .word 0xffffec20 */
/* @0x1b73a4 ldrheq r6, [r9], -r12 */
/* @0x1b73a8 .word 0xffffec24 */
/* @0x1b73ac andseq r6, r9, r4, ror #3 */
/* @0x1b73b0 .word 0xffffec28 */
/* @0x1b73b4 andseq r6, r9, r0, lsr r1 */
/* @0x1b73b8 .word 0xffffec2c */
/* @0x1b73bc andseq r6, r9, r8, asr #32 */
/* @0x1b73c0 .word 0xffffc020 */
/* ── ⑥-b 60 B 元素主体：Alloc(60,…,45,1) × 32 ─────────────────────────────
 *   初值：+0x00=5 +0x04=-1 +0x1c=-1 +0x20/+0x24/+0x30 = 0 +0x38 = 0x7fffffff（r12 = mvn 0x80000000）。
 */
/* @0x1b73c4 ldr r9, [pc, #-0x28] */
/* @0x1b73c8 mov r4, r6 */
/* @0x1b73cc str r2, [r5, #0x10] */
/* @0x1b73d0 mov r10, #32 */
/* @0x1b73d4 ldr r5, [r7, r3] */
/* @0x1b73d8 add r9, pc, r9 */
/* @0x1b73dc mov r11, #0 */
/* @0x1b73e0 mov r3, #3 */
/* @0x1b73e4 str r6, [r5, #0x4] */
/* @0x1b73e8 str r6, [r5] */
/* @0x1b73ec str r6, [r5, #0x8] */
/* @0x1b73f0 str r3, [r5, #0xc] */
/* @0x1b73f4 mov r1, r9 */
/* @0x1b73f8 mov r2, #45 */
/* @0x1b73fc mov r3, #1 */
/* @0x1b7400 mov r0, #60 */
/* @0x1b7404 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7408 ldr r3, [r5] */
/* @0x1b740c mvn r2, #0 */
/* @0x1b7410 mvn r12, #-2147483648 */
/* @0x1b7414 mov r1, #5 */
/* @0x1b7418 cmp r0, #0 */
/* @0x1b741c beq 0x1b745c <_ZN13CLayerManager4InitEv+0x55c> */
/* @0x1b7420 strb r4, [r0, #0x8] */
/* @0x1b7424 str r11, [r0, #0x20] */
/* @0x1b7428 str r4, [r0, #0xc] */
/* @0x1b742c str r11, [r0, #0x24] */
/* @0x1b7430 str r4, [r0, #0x10] */
/* @0x1b7434 str r11, [r0, #0x30] */
/* @0x1b7438 str r4, [r0, #0x14] */
/* @0x1b743c str r4, [r0, #0x18] */
/* @0x1b7440 str r2, [r0, #0x4] */
/* @0x1b7444 str r2, [r0, #0x1c] */
/* @0x1b7448 str r4, [r0, #0x28] */
/* @0x1b744c str r4, [r0, #0x2c] */
/* @0x1b7450 str r4, [r0, #0x34] */
/* @0x1b7454 str r12, [r0, #0x38] */
/* @0x1b7458 str r1, [r0] */
/* @0x1b745c cmp r3, #0 */
/* @0x1b7460 ldr r2, [r5, #0x8] */
/* @0x1b7464 strne r0, [r3, #0x18] */
/* @0x1b7468 streq r0, [r5, #0x4] */
/* @0x1b746c add r2, r2, #1 */
/* @0x1b7470 streq r0, [r5] */
/* @0x1b7474 streq r3, [r0, #0x18] */
/* @0x1b7478 streq r3, [r0, #0x14] */
/* @0x1b747c strne r0, [r5] */
/* @0x1b7480 strne r3, [r0, #0x14] */
/* @0x1b7484 strne r4, [r0, #0x18] */
/* @0x1b7488 subs r10, r10, #1 */
/* @0x1b748c str r2, [r5, #0x8] */
/* @0x1b7490 bne 0x1b73f4 <_ZN13CLayerManager4InitEv+0x4f4> */
/* ── ⑦ m_ParticleElementPool 0x542628：32 B × 32，type=6 ───────────────────
 *   初值：+0x00=6 +0x04=-1 +0x1c=-1，其余 0。与 ② 同为 32 B 但多写一个 +0x1c=-1。
 */
/* @0x1b7494 ldr r2, [pc, #-0xf4] */
/* @0x1b7498 mov r3, #32 */
/* @0x1b749c ldr r4, [pc, #-0xf8] */
/* @0x1b74a0 mov r11, r10 */
/* @0x1b74a4 str r3, [r5, #0x10] */
/* @0x1b74a8 mvn r9, #0 */
/* @0x1b74ac ldr r5, [r7, r2] */
/* @0x1b74b0 add r4, pc, r4 */
/* @0x1b74b4 mov r6, r3 */
/* @0x1b74b8 mov r3, #3 */
/* @0x1b74bc str r10, [r5, #0x4] */
/* @0x1b74c0 str r10, [r5] */
/* @0x1b74c4 str r10, [r5, #0x8] */
/* @0x1b74c8 str r3, [r5, #0xc] */
/* @0x1b74cc mov r2, #45 */
/* @0x1b74d0 mov r3, #1 */
/* @0x1b74d4 mov r0, #32 */
/* @0x1b74d8 mov r1, r4 */
/* @0x1b74dc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b74e0 ldr r3, [r5] */
/* @0x1b74e4 mov r2, #6 */
/* @0x1b74e8 cmp r0, #0 */
/* @0x1b74ec beq 0x1b7510 <_ZN13CLayerManager4InitEv+0x610> */
/* @0x1b74f0 strb r11, [r0, #0x8] */
/* @0x1b74f4 str r11, [r0, #0xc] */
/* @0x1b74f8 str r11, [r0, #0x10] */
/* @0x1b74fc str r11, [r0, #0x14] */
/* @0x1b7500 str r11, [r0, #0x18] */
/* @0x1b7504 str r9, [r0, #0x4] */
/* @0x1b7508 str r9, [r0, #0x1c] */
/* @0x1b750c str r2, [r0] */
/* @0x1b7510 cmp r3, #0 */
/* @0x1b7514 ldr r2, [r5, #0x8] */
/* @0x1b7518 strne r0, [r3, #0x18] */
/* @0x1b751c streq r0, [r5, #0x4] */
/* @0x1b7520 add r2, r2, #1 */
/* @0x1b7524 streq r0, [r5] */
/* @0x1b7528 streq r3, [r0, #0x18] */
/* @0x1b752c streq r3, [r0, #0x14] */
/* @0x1b7530 strne r0, [r5] */
/* @0x1b7534 strne r3, [r0, #0x14] */
/* @0x1b7538 strne r11, [r0, #0x18] */
/* @0x1b753c subs r6, r6, #1 */
/* @0x1b7540 str r2, [r5, #0x8] */
/* @0x1b7544 bne 0x1b74cc <_ZN13CLayerManager4InitEv+0x5cc> */
/* ── ⑧ m_TileElementPool 0x542614：80 B × 1024（本函数最大的元素池，81,920 B）──
 *   初值：+0x00=7 +0x04=-1 +0x20=-1 +0x40=-1；+0x34/+0x38/+0x44 = 1.0f；其余 0。
 */
/* @0x1b7548 ldr r3, [pc, #-0x1a0] */
/* @0x1b754c mov r2, #32 */
/* @0x1b7550 ldr r9, [pc, #-0x1a4] */
/* @0x1b7554 mov r4, r6 */
/* @0x1b7558 str r2, [r5, #0x10] */
/* @0x1b755c mov r10, #1024 */
/* @0x1b7560 ldr r5, [r7, r3] */
/* @0x1b7564 add r9, pc, r9 */
/* @0x1b7568 mov r11, #0 */
/* @0x1b756c mov r3, #3 */
/* @0x1b7570 str r6, [r5, #0x4] */
/* @0x1b7574 str r6, [r5] */
/* @0x1b7578 str r6, [r5, #0x8] */
/* @0x1b757c str r3, [r5, #0xc] */
/* @0x1b7580 mov r2, #45 */
/* @0x1b7584 mov r3, #1 */
/* @0x1b7588 mov r0, #80 */
/* @0x1b758c mov r1, r9 */
/* @0x1b7590 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7594 ldr r3, [r5] */
/* @0x1b7598 mvn r2, #0 */
/* @0x1b759c mov r12, #7 */
/* @0x1b75a0 cmp r0, #0 */
/* @0x1b75a4 beq 0x1b75f8 <_ZN13CLayerManager4InitEv+0x6f8> */
/* @0x1b75a8 mov r1, #1065353216 */
/* @0x1b75ac strb r4, [r0, #0x8] */
/* @0x1b75b0 str r4, [r0, #0xc] */
/* @0x1b75b4 str r11, [r0, #0x24] */
/* @0x1b75b8 str r4, [r0, #0x10] */
/* @0x1b75bc str r11, [r0, #0x28] */
/* @0x1b75c0 str r4, [r0, #0x14] */
/* @0x1b75c4 str r11, [r0, #0x3c] */
/* @0x1b75c8 str r4, [r0, #0x18] */
/* @0x1b75cc str r2, [r0, #0x4] */
/* @0x1b75d0 str r2, [r0, #0x20] */
/* @0x1b75d4 str r4, [r0, #0x2c] */
/* @0x1b75d8 str r4, [r0, #0x30] */
/* @0x1b75dc str r2, [r0, #0x40] */
/* @0x1b75e0 str r4, [r0, #0x48] */
/* @0x1b75e4 str r1, [r0, #0x34] */
/* @0x1b75e8 str r4, [r0, #0x4c] */
/* @0x1b75ec str r1, [r0, #0x38] */
/* @0x1b75f0 str r12, [r0] */
/* @0x1b75f4 str r1, [r0, #0x44] */
/* @0x1b75f8 cmp r3, #0 */
/* @0x1b75fc ldr r2, [r5, #0x8] */
/* @0x1b7600 strne r0, [r3, #0x18] */
/* @0x1b7604 streq r0, [r5, #0x4] */
/* @0x1b7608 add r2, r2, #1 */
/* @0x1b760c streq r0, [r5] */
/* @0x1b7610 streq r3, [r0, #0x18] */
/* @0x1b7614 streq r3, [r0, #0x14] */
/* @0x1b7618 strne r0, [r5] */
/* @0x1b761c strne r3, [r0, #0x14] */
/* @0x1b7620 strne r4, [r0, #0x18] */
/* @0x1b7624 subs r10, r10, #1 */
/* @0x1b7628 str r2, [r5, #0x8] */
/* @0x1b762c bne 0x1b7580 <_ZN13CLayerManager4InitEv+0x680> */
/* ── ⑨ m_TilePool 0x5425fc：1804 B（0x70c）× 32 ───────────────────────────
 *   ★ 唯一不写对象内容的池：只写 +0x700 = 0、+0x704 = next、+0x708 = prev（三个链接字）。
 *   注意 1b7684 先把计数 +1、再用 strne 写三个链接字、streq 写头尾 —— 与 ①..⑧ 的顺序不同，
 *   但语义一样（计数在成功/失败两条路都加）。
 */
/* @0x1b7630 ldr r3, [pc, #-0x280] */
/* @0x1b7634 mov r2, #1024 */
/* @0x1b7638 ldr r6, [pc, #-0x284] */
/* @0x1b763c mov r9, r10 */
/* @0x1b7640 str r2, [r5, #0x10] */
/* @0x1b7644 mov r5, #32 */
/* @0x1b7648 ldr r4, [r7, r3] */
/* @0x1b764c add r6, pc, r6 */
/* @0x1b7650 mov r3, #3 */
/* @0x1b7654 str r10, [r4, #0x4] */
/* @0x1b7658 str r10, [r4] */
/* @0x1b765c str r10, [r4, #0x8] */
/* @0x1b7660 str r3, [r4, #0xc] */
/* @0x1b7664 mov r2, #45 */
/* @0x1b7668 mov r3, #1 */
/* @0x1b766c movw r0, #0x70c */
/* @0x1b7670 mov r1, r6 */
/* @0x1b7674 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b7678 ldr r3, [r4] */
/* @0x1b767c ldr r2, [r4, #0x8] */
/* @0x1b7680 add r2, r2, #1 */
/* @0x1b7684 str r2, [r4, #0x8] */
/* @0x1b7688 cmp r0, #0 */
/* @0x1b768c strne r9, [r0, #0x704] */
/* @0x1b7690 strne r9, [r0, #0x708] */
/* @0x1b7694 strne r9, [r0, #0x700] */
/* @0x1b7698 cmp r3, #0 */
/* @0x1b769c strne r0, [r3, #0x708] */
/* @0x1b76a0 streq r0, [r4, #0x4] */
/* @0x1b76a4 streq r0, [r4] */
/* @0x1b76a8 streq r3, [r0, #0x708] */
/* @0x1b76ac streq r3, [r0, #0x704] */
/* @0x1b76b0 strne r0, [r4] */
/* @0x1b76b4 strne r3, [r0, #0x704] */
/* @0x1b76b8 strne r9, [r0, #0x708] */
/* @0x1b76bc subs r5, r5, #1 */
/* @0x1b76c0 bne 0x1b7664 <_ZN13CLayerManager4InitEv+0x764> */
/* ── ⑩ 收尾：删 m_pScriptInstance、置 m_bInitialised、跳回掩码尾 ────────────── */
/* @0x1b76c4 ldr r3, [pc, #-0x30c] */
/* @0x1b76c8 mov r2, #32 */
/* @0x1b76cc str r2, [r4, #0x10] */
/* @0x1b76d0 ldr r4, [r7, r3] */
/* @0x1b76d4 ldr r0, [r4] */
/* @0x1b76d8 cmp r0, #0 */
/* @0x1b76dc beq 0x1b76f0 <_ZN13CLayerManager4InitEv+0x7f0> */
/* @0x1b76e0 ldr r3, [r0] */
/* @0x1b76e4 ldr r3, [r3, #0x4] */
/* @0x1b76e8 blx r3 */
/* @0x1b76ec str r5, [r4] */
/* @0x1b76f0 ldr r2, [sp, #0x4] */
/* @0x1b76f4 mov r3, #1 */
/* @0x1b76f8 strb r3, [r2] */
/* @0x1b76fc b 0x1b6f2c <_ZN13CLayerManager4InitEv+0x2c> */

/* ══ §2 CLayerManager::InsertLayerIntoActiveList 0x1c30f8 ══════════════════
 * @func 0x1c30f8 0x1c33e4  size 748  187 条（185 指令 + 1c33dc/1c33e0 两字：0.6f 与 0x0016dd68）
 * 级别: 正文（187/187。链定位/四种落点/表 1 的 Robin-Hood 插入/同键覆盖/翻倍重建 + 0.6 阈值全部解出。
 *       未钉：桶项三个字段的正式名、为什么阈值判「>」而不是「>=」的取舍）
 * 符号: _ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer
 *       → void CLayerManager::InsertLayerIntoActiveList(CRoom* room, CLayer* layer)
 * 调用者（全库 4 处，全是 bl）：AddDynamicLayer 1c3570、AddLayer 1c376c、BuildRoomLayers 1c6a50、DeSerializeLayer 1c782c
 * 同层: ChangeLayerDepth 0x1b8200（唯一会「摘了再插」的函数，但它自己手写了摘链/插链、**没有**调用本函数）、
 *       GetLayerFromID 0x1b8868（表 1 的读侧）、CHashMap<int,CLayer*,7>::Insert 0x1c2a90（扩容时逐项重放用它）、
 *       CHashMapCalculateHash<int> 0x1b6e44、memset@plt 0xb65b0、MemoryManager::Alloc 0x27ce78、Free 0x27c2d0
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   按 depth 升序把层插进 room+0xd4 的双链（同 depth 落在该组末尾），再把层 id 写进表 1（upsert：
 *   已存在就覆盖值并把已用数补回去），必要时先把表 1 的桶翻倍重建。
 *
 * ── ① 定位（1c3110..1c3144）────────────────────────────────────────────
 *   head = room+0xd4；head == 0 → 尾/空链落点（1c3264）。
 *   new < head->depth → 插到 head 之前（1c32a8 → 1c3148，此时 r1 = head）。
 *   否则从 head 起前进：`r1 = r1->next; if (!r1) 尾落点; if (r1->depth > new) 停;` 
 *   ⇒ 停在**第一个 depth 严格大于 new** 的层上，插在它前面 ⇒ 同 depth 的一串里，新层排在**最后**。
 *   ⚠ 判据是 `ble`（<= 就继续走），不是 `<`：等深的层一个一个被跨过去，这是「组尾」而不是「组头」。
 *
 * ── ② 三个落点（都在 1c3148..1c33d8 之间，最后都汇到 1c3180 写表）──────────
 *   a 插到 r1 之前（1c3148）：P = r1->prev；P == 0 → 走 c（其实是头）；否则
 *     layer->prev = P；layer->next = P->next；若 P->next == 0 → room+0xd8 = layer；否则 P->next->prev = layer；
 *     P->next = layer；room+0xdc += 1。
 *   b 插到头（1c33a4，来自 P == 0）：room+0xdc += 1；head->prev = layer；layer->next = head；
 *     room+0xd4 = layer；layer->prev = 0。
 *   c 尾/空链（1c3264）：room+0xdc += 1；tail == 0 → 1c33c8（head = tail = layer，两个链接都清 0）；
 *     否则 tail->next = layer；layer->prev = tail；room+0xd8 = layer；layer->next = 0。
 *   ⇒ 三个真写点都成对：改 next 必改 prev，改头/尾必改 room 侧。**没有任何「是否已在链上」的检查**：
 *     同一层连插两次会把链写坏（唯一的安全用法是 ChangeLayerDepth 那种「先摘后插」）。
 *
 * ── ③ 表 1：负载门 + 落位（1c3180..1c31d0、1c3298）───────────────────────
 *   used = room+0xe8，threshold = room+0xf0；`if (used > threshold) 扩容`（等于不扩）。
 *   然后 used += 1 写回，key = layer+0x00，h = (key+1) & 0x7fffffff，idx = h & mask(room+0xec)，
 *   桶项 = base(room+0xf4) + 12*idx；桶项 +0x08（哈希）== 0 → 空桶，直接写 {key, value, h} 返回。
 *
 * ── ④ Robin-Hood 探测（1c3214..1c3260）──────────────────────────────────
 *   进环前：r10 = 容量(room+0xe4)、r6 = 0（本项已让出的距离）。
 *   dist = ((idx + cap) - (h_resident & mask)) & mask；
 *     dist <  r6 → 本项比驻留项「更该在这儿」→ 交换：驻留项的 (key,value,h) 存进桶，
 *                  被挤出的 (key,value,h) 变成新的待插项，r6 = dist + 1，idx 前进，继续；
 *     dist != r6 → 前进（r6 += 1，idx = (idx+1) & mask）；
 *     dist == r6 → 比哈希：不等就前进；相等再比键（桶项 +0x00 == layer->id）：
 *                  相等 → 覆盖 +0x00/+0x04/+0x08，并**把 used 减 1**（1c3254/1c325c）后返回。
 *   ⇒ upsert 的净效果：新键 used+1，老键不变（先 +1 再 -1）。这也是为什么「同键覆盖」这条路不会让计数漂。
 *
 * ── ⑤ 扩容（1c32b0..1c33a0）────────────────────────────────────────────
 *   newcap = cap * 2；room+0xe4 = newcap；room+0xec = newcap - 1；
 *   Alloc(12 * newcap, **Platform/MemoryManager.h**, **70**, 1)（★ 与池的 Room_Layers.h:45/63 不是同一文件：
 *   CHashMap 这个模板类声明在 MemoryManager.h，扩容内联在第 70 行 —— 与 DuplicateRoomLayers 卡的同一结论吻合）
 *   → memset(0) → room+0xf4 = 新桶；
 *   room+0xe8 = 0；阈值 = (int)(0.6f * newcap)（池字 1c33dc = 0x3f19999a）→ room+0xf0；
 *   再逐项重放旧桶：hash > 0 的项 `CHashMap<int,CLayer*,7>::Insert(room+0xe4, key, value)`（1c336c），
 *   重放完 Free(旧桶)，用 room+0xe4 重算一次阈值（1c3384..1c339c，与上面同值），回到 1c3194 插新项。
 *   ⚠ 阈值用**浮点**算：vcvt.f32.s32 → vmul.f32 0.6 → vcvt.s32.f32（截断，不是四舍五入）。
 */

/* ── ⓪ 两道门 + 定位：head 空 / 比 head 小 / 逐个前进 ────────────────────── */
/* @0x1c30f8 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c30fc subs r9, r0, #0 */
/* @0x1c3100 mov r7, r1 */
/* @0x1c3104 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3108 cmp r1, #0 */
/* @0x1c310c popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3110 ldr r2, [r9, #0xd4] */
/* @0x1c3114 cmp r2, #0 */
/* @0x1c3118 beq 0x1c3264 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x16c> */
/* @0x1c311c ldr r3, [r1, #0x4] */
/* @0x1c3120 ldr r1, [r2, #0x4] */
/* @0x1c3124 cmp r3, r1 */
/* @0x1c3128 movge r1, r2 */
/* @0x1c312c blt 0x1c32a8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1b0> */
/* @0x1c3130 ldr r1, [r1, #0x68] */
/* @0x1c3134 cmp r1, #0 */
/* @0x1c3138 beq 0x1c3264 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x16c> */
/* @0x1c313c ldr r0, [r1, #0x4] */
/* @0x1c3140 cmp r0, r3 */
/* @0x1c3144 ble 0x1c3130 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x38> */
/* ── ①-a 插到 r1 之前（P = r1->prev；P==0 转头插）────────────────────────── */
/* @0x1c3148 ldr r3, [r1, #0x6c] */
/* @0x1c314c cmp r3, #0 */
/* @0x1c3150 beq 0x1c33a4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x2ac> */
/* @0x1c3154 ldr r2, [r9, #0xdc] */
/* @0x1c3158 add r2, r2, #1 */
/* @0x1c315c str r2, [r9, #0xdc] */
/* @0x1c3160 str r3, [r7, #0x6c] */
/* @0x1c3164 ldr r2, [r3, #0x68] */
/* @0x1c3168 str r2, [r7, #0x68] */
/* @0x1c316c ldr r2, [r3, #0x68] */
/* @0x1c3170 cmp r2, #0 */
/* @0x1c3174 streq r7, [r9, #0xd8] */
/* @0x1c3178 strne r7, [r2, #0x6c] */
/* @0x1c317c str r7, [r3, #0x68] */
/* ── ② 表 1 入口：used/threshold、key、哈希、空桶 ─────────────────────────── */
/* @0x1c3180 ldr r3, [r9, #0xe8] */
/* @0x1c3184 ldr r2, [r9, #0xf0] */
/* @0x1c3188 ldr r8, [r7] */
/* @0x1c318c cmp r3, r2 */
/* @0x1c3190 bgt 0x1c32b0 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1b8> */
/* @0x1c3194 add r3, r3, #1 */
/* @0x1c3198 mov r0, r8 */
/* @0x1c319c str r3, [r9, #0xe8] */
/* @0x1c31a0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c31a4 ldr r5, [r9, #0xec] */
/* @0x1c31a8 ldr r1, [r9, #0xf4] */
/* @0x1c31ac bic r0, r0, #-2147483648 */
/* @0x1c31b0 and r3, r0, r5 */
/* @0x1c31b4 add r2, r3, r3, lsl #1 */
/* @0x1c31b8 add r2, r1, r2, lsl #2 */
/* @0x1c31bc ldr r12, [r2, #0x8] */
/* @0x1c31c0 cmp r12, #0 */
/* @0x1c31c4 ldrne r10, [r9, #0xe4] */
/* @0x1c31c8 movne r6, #0 */
/* @0x1c31cc bne 0x1c3214 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x11c> */
/* @0x1c31d0 b 0x1c3298 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1a0> */
/* ── ③ Robin-Hood 交换：驻留项让位，被挤出的项带着 r6=dist+1 继续 ─────────── */
/* @0x1c31d4 ldr r11, [r2] */
/* @0x1c31d8 ldr r6, [r2, #0x4] */
/* @0x1c31dc str r0, [r2, #0x8] */
/* @0x1c31e0 mov r0, r12 */
/* @0x1c31e4 str r8, [r2] */
/* @0x1c31e8 mov r8, r11 */
/* @0x1c31ec str r7, [r2, #0x4] */
/* @0x1c31f0 mov r7, r6 */
/* @0x1c31f4 add r3, r3, #1 */
/* @0x1c31f8 add r6, r4, #1 */
/* @0x1c31fc and r3, r3, r5 */
/* @0x1c3200 add r2, r3, r3, lsl #1 */
/* @0x1c3204 add r2, r1, r2, lsl #2 */
/* @0x1c3208 ldr r12, [r2, #0x8] */
/* @0x1c320c cmp r12, #0 */
/* @0x1c3210 beq 0x1c3298 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x1a0> */
/* @0x1c3214 add r4, r10, r3 */
/* @0x1c3218 and r11, r12, r5 */
/* @0x1c321c rsb r4, r11, r4 */
/* @0x1c3220 and r4, r4, r5 */
/* @0x1c3224 cmp r4, r6 */
/* @0x1c3228 blt 0x1c31d4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xdc> */
/* @0x1c322c movne r4, r6 */
/* @0x1c3230 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* ── ③-b 同哈希 → 比键 → 同键覆盖并 used-1（净计数不变）──────────────────── */
/* @0x1c3234 cmp r12, r0 */
/* @0x1c3238 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* @0x1c323c ldr r6, [r2] */
/* @0x1c3240 cmp r8, r6 */
/* @0x1c3244 bne 0x1c31f4 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0xfc> */
/* @0x1c3248 ldr r3, [r9, #0xe8] */
/* @0x1c324c str r8, [r2] */
/* @0x1c3250 str r7, [r2, #0x4] */
/* @0x1c3254 sub r3, r3, #1 */
/* @0x1c3258 str r12, [r2, #0x8] */
/* @0x1c325c str r3, [r9, #0xe8] */
/* @0x1c3260 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ①-c 尾/空链落点：room+0xdc += 1，tail 空则头尾都设成本层 ─────────────── */
/* @0x1c3264 ldr r3, [r9, #0xd8] */
/* @0x1c3268 ldr r2, [r9, #0xdc] */
/* @0x1c326c cmp r3, #0 */
/* @0x1c3270 add r2, r2, #1 */
/* @0x1c3274 str r2, [r9, #0xdc] */
/* @0x1c3278 beq 0x1c33c8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x2d0> */
/* @0x1c327c str r7, [r3, #0x68] */
/* @0x1c3280 mov r3, #0 */
/* @0x1c3284 ldr r2, [r9, #0xd8] */
/* @0x1c3288 str r2, [r7, #0x6c] */
/* @0x1c328c str r7, [r9, #0xd8] */
/* @0x1c3290 str r3, [r7, #0x68] */
/* @0x1c3294 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* @0x1c3298 str r8, [r2] */
/* @0x1c329c str r7, [r2, #0x4] */
/* @0x1c32a0 str r0, [r2, #0x8] */
/* @0x1c32a4 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c32a8 mov r1, r2 */
/* @0x1c32ac b 0x1c3148 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x50> */
/* ── ④ 扩容：cap<<=1、mask、Alloc(12*newcap, 行 70)、memset、阈值 0.6 ─────── */
/* @0x1c32b0 ldr r10, [r9, #0xe4] */
/* @0x1c32b4 mov r3, #1 */
/* @0x1c32b8 ldr r1, [pc, #0x120] */
/* @0x1c32bc mov r2, #70 */
/* @0x1c32c0 ldr r6, [r9, #0xf4] */
/* @0x1c32c4 lsl r0, r10, r3 */
/* @0x1c32c8 add r1, pc, r1 */
/* @0x1c32cc add r4, r0, r10, lsl #2 */
/* @0x1c32d0 str r0, [r9, #0xe4] */
/* @0x1c32d4 sub r0, r0, #1 */
/* @0x1c32d8 str r0, [r9, #0xec] */
/* @0x1c32dc lsl r4, r4, #2 */
/* @0x1c32e0 mov r0, r4 */
/* @0x1c32e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c32e8 mov r2, r4 */
/* @0x1c32ec mov r1, #0 */
/* @0x1c32f0 str r0, [r9, #0xf4] */
/* @0x1c32f4 bl 0xb65b0 <memset@plt> */
/* @0x1c32f8 ldr r2, [r9, #0xe4] */
/* @0x1c32fc vldr s15, [pc, #216] */
/* @0x1c3300 mov r1, #0 */
/* @0x1c3304 cmp r2, r1 */
/* @0x1c3308 str r1, [r9, #0xe8] */
/* @0x1c330c vmov s13, r2 */
/* @0x1c3310 vcvt.f32.s32 s14, s13 */
/* @0x1c3314 vmul.f32 s15, s14, s15 */
/* @0x1c3318 vcvt.s32.f32 s15, s15 */
/* @0x1c331c vstr s15, [r9, #240] */
/* @0x1c3320 ble 0x1c3340 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x248> */
/* @0x1c3324 add r2, r2, r2, lsl #1 */
/* @0x1c3328 ldr r3, [r9, #0xf4] */
/* @0x1c332c add r2, r3, r2, lsl #2 */
/* @0x1c3330 str r1, [r3, #0x8] */
/* @0x1c3334 add r3, r3, #12 */
/* @0x1c3338 cmp r3, r2 */
/* @0x1c333c bne 0x1c3330 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x238> */
/* ── ④-b 重放旧桶（hash>0 才插）+ Free 旧桶 + 重算阈值 + 回 1c3194 ────────── */
/* @0x1c3340 cmp r10, #0 */
/* @0x1c3344 addgt r11, r9, #228 */
/* @0x1c3348 movgt r4, r6 */
/* @0x1c334c movgt r5, #0 */
/* @0x1c3350 ble 0x1c337c <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x284> */
/* @0x1c3354 ldr r3, [r4, #0x8] */
/* @0x1c3358 mov r0, r11 */
/* @0x1c335c add r5, r5, #1 */
/* @0x1c3360 cmp r3, #0 */
/* @0x1c3364 ble 0x1c3370 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x278> */
/* @0x1c3368 ldm r4, {r1, r2} */
/* @0x1c336c bl 0x1c2a90 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_> */
/* @0x1c3370 cmp r5, r10 */
/* @0x1c3374 add r4, r4, #12 */
/* @0x1c3378 bne 0x1c3354 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x25c> */
/* @0x1c337c mov r0, r6 */
/* @0x1c3380 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c3384 vldr s13, [r9, #228] */
/* @0x1c3388 vcvt.f32.s32 s14, s13 */
/* @0x1c338c vldr s15, [pc, #72] */
/* @0x1c3390 ldr r3, [r9, #0xe8] */
/* @0x1c3394 vmul.f32 s15, s14, s15 */
/* @0x1c3398 vcvt.s32.f32 s15, s15 */
/* @0x1c339c vstr s15, [r9, #240] */
/* @0x1c33a0 b 0x1c3194 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x9c> */
/* ── ①-b 头插落点（来自 P==0）：head 前插，room+0xd4 更新 ─────────────────── */
/* @0x1c33a4 ldr r1, [r9, #0xdc] */
/* @0x1c33a8 add r1, r1, #1 */
/* @0x1c33ac str r1, [r9, #0xdc] */
/* @0x1c33b0 str r7, [r2, #0x6c] */
/* @0x1c33b4 ldr r2, [r9, #0xd4] */
/* @0x1c33b8 str r2, [r7, #0x68] */
/* @0x1c33bc str r7, [r9, #0xd4] */
/* @0x1c33c0 str r3, [r7, #0x6c] */
/* @0x1c33c4 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* ── ①-c' 空链落点：head = tail = layer，两链接清 0；两字池（0.6f = 1c33dc）── */
/* @0x1c33c8 str r7, [r9, #0xd8] */
/* @0x1c33cc str r7, [r9, #0xd4] */
/* @0x1c33d0 str r3, [r7, #0x6c] */
/* @0x1c33d4 str r3, [r7, #0x68] */
/* @0x1c33d8 b 0x1c3180 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer+0x88> */
/* @0x1c33dc svclo #0x19999a */
/* @0x1c33e0 andseq sp, r6, r8, ror #26 */

/* ══ §3 CLayerManager::GetLayerFromID 0x1b8868 ═════════════════════════════
 * @func 0x1b8868 0x1b8930  size 200  50 条（50 指令，无字面量池：末尾即下一个符号 GetLayerDepth）
 * 级别: 正文（50/50。哈希、首桶判空、命中判据、探测环、两处出口全解；无分配、无写）
 * 符号: _ZN13CLayerManager14GetLayerFromIDEP5CRoomi → CLayer* GetLayerFromID(CRoom* room, int id)
 * 调用者（全库 57 处 bl，本卡逐个列过）：layer_* 系列内建占大头（layer_get_depth 0x1bab40、layer_x 0x1bb090、
 *       layer_destroy 0x1bc148、layer_get_all_elements 0x1bbcbc … 共 30 余处）、粒子系统三处（1a4320/1a46ec/1a5c3c）、
 *       CRoom::Assign 0x1adfdc、Command_Create_Layer 0x1c99b4、GV_Layer 0x1fae18、SV_Layer 0x1fc1c4，
 *       以及 CLayerManager 内部：AddInstance 0x1c5d60、ChangeInstanceDepth 0x1c5f68、UpdateInstanceActivation 0x1b8a68、
 *       RemoveLayer 0x1b95e4、RemoveInstance 0x1b9e7c、GetLayerDepth 0x1b8934、ChangeLayerDepth(id) 0x1b895c
 * 同层: GetLayerDepth 0x1b8930（尾调它 + 取 layer+0x04，找不到给 0）、ChangeLayerDepth 的 ID 重载 0x1b8948、
 *       InsertLayerIntoActiveList 0x1c30f8（同一张表的写侧）、CHashMapCalculateHash<int> 0x1b6e44
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   在表 1（room+0xe4 簇）上做一次内联的线性探测查找：h = (id+1) & 0x7fffffff，命中返回桶项 +0x04，
 *   空桶或探测越界返回 0。**只比哈希，不比键**。
 *
 * ── 逐段 ────────────────────────────────────────────────────────────────
 *   ① 1b886c..1b8894：r5 = room；r0 = id → CHashMapCalculateHash（h = id+1）→ bic 清符号位；
 *      r1 = mask(room+0xec)、r7 = base(room+0xf4)、idx = h & mask、entry = base + 12*idx
 *      （`lsl r4,r3,#1` + `add r2,r4,r3` 是 3*idx 的定点写法）。
 *   ② 1b8898..1b88a4：entry->hash(+0x08) == 0 → 返回 0；== h → 1b891c 命中。
 *   ③ 1b88a8..1b88c4：算「首桶让出的距离」d0 = (idx + 容量) - (entry->hash & mask)；
 *      1b88b8 `tst r2,r1` + 1b88bc `bmi` —— **这段守卫永远不成立**：mask 最高位恒 0 ⇒ N 恒 0。
 *      这是编译器把「d0 < 0」写成了 tst+掩码的痕迹，真正的出口在下一条循环判断。
 *   ④ 1b88c8..1b8908：探测环。`idx = (idx+1) & mask`；每步算 dist = ((idx+cap) - (h_i & mask)) & mask；
 *      先判命中（hash == h → 1b8914）、再判 `dist < 已走步数` → 1b890c 返回 0（Robin-Hood 的提前放弃）、
 *      hash == 0 → 落出循环返回 0。
 *   ⑤ 1b8914..1b8928：命中返回。1b8914 的 `cmn r3,#1` 只在「idx == -1」这种不可能态上改路；
 *      1b891c 用 `adds r0,r7,#4` + `ldrne` 取桶项 +0x04 —— adds 只为置标志，取值的条件恒真。
 *
 * ── 为什么「只比哈希」是安全的（这也是本卡唯一需要推理的地方）──────────────
 *   CHashMapCalculateHash<int> = key + 1，在 32 位 int 上是单射 ⇒ 两个不同的 id 不可能得到同一个 h。
 *   于是 h 相等 ⟺ id 相等，省掉键比较是合法的。两个边界态例外（都不是正常 id 范围）：
 *     · id = -1 → h = 0 → 与「空桶」同值，永远查不到；
 *     · id = 0x7fffffff → h = 0x80000000 → bic 清符号位后也是 0 → 同上。
 *   ⇒ 层 id 由计数器发（AddDynamicLayer/AddLayer 取 max(m_CurrentLayerID, 水位)+1），碰不到这两点。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 本函数**不检查 room 是否为空**：room = 0 会在 1b8878 直接解引用 +0xec。空指针契约由调用方保证。
 *   · 表 1 的桶项三个字段（键/值/哈希）的正式名；本卡按「键、值、哈希」写。
 */

/* ── ① 入口：哈希、清符号位、首桶地址 ─────────────────────────────────────── */
/* @0x1b8868 push {r4, r5, r6, r7, r8, lr} */
/* @0x1b886c mov r5, r0 */
/* @0x1b8870 mov r0, r1 */
/* @0x1b8874 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8878 ldr r1, [r5, #0xec] */
/* @0x1b887c ldr r7, [r5, #0xf4] */
/* @0x1b8880 bic r8, r0, #-2147483648 */
/* @0x1b8884 and r3, r8, r1 */
/* @0x1b8888 lsl r4, r3, #1 */
/* @0x1b888c add r2, r4, r3 */
/* @0x1b8890 add r2, r7, r2, lsl #2 */
/* @0x1b8894 ldr r2, [r2, #0x8] */
/* @0x1b8898 cmp r2, #0 */
/* @0x1b889c beq 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88a0 cmp r8, r2 */
/* @0x1b88a4 beq 0x1b891c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xb4> */
/* ── ② 首桶距离守卫（tst+bmi，永不成立）→ 探测环起步 ─────────────────────── */
/* @0x1b88a8 ldr r0, [r5, #0xe4] */
/* @0x1b88ac and r2, r1, r2 */
/* @0x1b88b0 add r12, r3, r0 */
/* @0x1b88b4 rsb r2, r2, r12 */
/* @0x1b88b8 tst r2, r1 */
/* @0x1b88bc bmi 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88c0 mov r12, #0 */
/* @0x1b88c4 b 0x1b88d8 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0x70> */
/* ── ③ 探测环体：命中判据 / dist < 步数就放弃 / 空桶就放弃 ─────────────────── */
/* @0x1b88c8 cmp r8, r2 */
/* @0x1b88cc beq 0x1b8914 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xac> */
/* @0x1b88d0 cmp r5, r12 */
/* @0x1b88d4 blt 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b88d8 add r3, r3, #1 */
/* @0x1b88dc add r12, r12, #1 */
/* @0x1b88e0 and r3, r1, r3 */
/* @0x1b88e4 add r6, r3, r0 */
/* @0x1b88e8 lsl r4, r3, #1 */
/* @0x1b88ec add r2, r4, r3 */
/* @0x1b88f0 add r2, r7, r2, lsl #2 */
/* @0x1b88f4 ldr r2, [r2, #0x8] */
/* @0x1b88f8 and r5, r1, r2 */
/* @0x1b88fc cmp r2, #0 */
/* @0x1b8900 rsb r5, r5, r6 */
/* @0x1b8904 and r5, r5, r1 */
/* @0x1b8908 bne 0x1b88c8 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0x60> */
/* @0x1b890c mov r0, #0 */
/* @0x1b8910 pop {r4, r5, r6, r7, r8, pc} */
/* ── ④ 命中与返回（cmn idx,#1 是死路；返回值取桶项 +0x04）─────────────────── */
/* @0x1b8914 cmn r3, #1 */
/* @0x1b8918 beq 0x1b890c <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi+0xa4> */
/* @0x1b891c add r3, r4, r3 */
/* @0x1b8920 add r7, r7, r3, lsl #2 */
/* @0x1b8924 adds r0, r7, #4 */
/* @0x1b8928 ldrne r0, [r7, #0x4] */
/* @0x1b892c pop {r4, r5, r6, r7, r8, pc} */

/* ══ §4 CLayerManager::ChangeLayerDepth(CRoom*, CLayer*, int, bool) 0x1b8200 ══
 * @func 0x1b8200 0x1b87f4  size 1524  381 条（381 指令 + 1b87f0 一个字面量池字 0x002381d8 → 槽 0x3f0864 = m_LayerPool）
 * 级别: 正文（381/381。两条主路径 + 合流分支 + 表 1 的后移填补删除 + 回收/回池全部逐条落锚）。
 *       ⚠ 两处需要读者自己判轻重：① 合流分支要求第 4 实参 != 0，而三个调用点分别是「常量 0」（F_LayerDepth）、
 *         「r3 残值 1」（ChangeInstanceDepth）、「原样转发」（ID 重载，但它自己无调用者）；
 *         ② 合流到「空元素链」的目标层时有一段写了 prev 自环，本卡按缺陷记录，不粉饰。
 * 符号: _ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib
 *       → void CLayerManager::ChangeLayerDepth(CRoom* room, CLayer* layer, int depth, bool bMergeDynamic)
 * 调用者（全库 3 处，本卡逐个看了第 4 实参）：
 *   · 0x1bbf9c `bl`  F_LayerDepth（GML 的 layer_depth）：1bbf98 `mov r3,#0` ⇒ **恒 0**，永不进合流分支。
 *   · 0x1b8978 `b`   ChangeLayerDepth(room,id,…) 重载：原样转发它自己的第 4 实参（而该重载全库无调用者，见 §5）。
 *   · 0x1c5fec `b`   ChangeInstanceDepth（实例改深度）：走到这里的条件是「目标层是动态层(+0x19!=0) 且
 *     元素数(+0x60) == 1 且 唯一元素的 type==2 且 elem+0x20 == 本实例」；此时 r3 正是 1c5f9c `cmp r3,#1` 留下的
 *     **1** ⇒ 合流分支是**活路径**，触发面很窄（单元素动态层）。
 * 同层: InsertLayerIntoActiveList 0x1c30f8（本函数自己手写了「摘 + 插」，没有复用它）、GetLayerFromID 0x1b8868、
 *       ChangeInstanceDepth 0x1c5f40、F_LayerDepth 0x1bbeec、MemoryManager::Free 0x27c2d0、_ZdlPv 0x27d1d0、
 *       MemoryInWad 0x1aad50、CTimingSource::Reset 0x214728
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   改层深 = 写 +0x04 → 在 depth 升序双链上重新找位置（真挪的话「摘了再插」）→ 若第 4 实参非 0 且
 *   增深时撞上**同 depth 的动态层**，就把本层元素整体并给那一层、把本层摘链、删表 1 键、回池。
 *
 * ── ⓪ 三道门与分流（1b8204..1b8228）──────────────────────────────────────
 *   room == 0 → 返回；layer == 0 → 返回；layer->depth == 新 depth → **直接返回（什么都不写）**。
 *   否则先 `str r2,[r1,#4]`（**先改字段，再挪链**），再看 1b821c 留下的标志：
 *   `ble`（旧 <= 新，增深）→ 1b82ac；否则（旧 > 新，减深）→ 1b822c。
 *
 * ── ① 减深（1b822c..1b8260，往回找）────────────────────────────────────
 *   P = layer->prev；P == 0（本来就是头）→ 1b843c：head = layer->next，然后走「卸载 + 头插」。
 *   否则从 P 往回走：`while (cur->depth >= 新深度) cur = cur->prev;`
 *     走到 0 → 1b8264（超到头了 ⇒ 卸载 + 头插）
 *     停在 cur->depth < 新深度 的节点 P' → 1b844c
 *   ⇒ 停点是**第一个比新深度浅的前驱**，插到它**后面** ⇒ 减深时新层落在「同 depth 组」的**组首**。
 *   ⚠ 1b8240/1b8244 的 `movle r3,r12` + `ble` 里，mov 不改标志：`ble` 判的仍是 1b823c 的 `cmp r2,r3`。
 *     同理 1b82c4/1b82c8 的 `cmp r3,#0` + `mov r3,r12` + `bne` 判的是第 4 实参，不是刚装好的指针。
 *
 * ── ② 增深（1b82ac..1b82f0，往前找）────────────────────────────────────
 *   next = layer->next；next == 0（本来就是尾）→ 1b82f4：卸载 + 尾插。
 *   `if (新深度 < next->depth) → 1b8380`（插到 next 前，即 next->prev 之后）。
 *   若第 4 实参 == 0：`r3 = next` 后逐个前进，`if (新深度 < r3->depth) → 1b8384`，走到尾就尾插。
 *   若第 4 实参 != 0：先做同深度判定（③），否则同上前进。
 *   ⇒ 停点是**第一个严格更深的后继**，插到它前面 ⇒ 增深时新层落在同 depth 组的**组尾**。
 *   ⚠ 1b82c0 的 `blt 1b8380` 分支实际上必然从 1b8388 直接返回：既然 layer->next == 该后继，
 *     「layer == 后继->prev」恒真 ⇒ 增深路径的第一次比较只会得到「不用动」。
 *
 * ── ③ 同深度判定（1b8344..1b8358，只有第 4 实参 != 0 才可达）──────────────
 *   命中「后继 depth == 新深度」时看两层的 +0x19：候选是静态层 → 跳过继续走；候选动态但本层静态 → 跳过；
 *   两层都是动态 → 1b83e8 **合流**。
 *
 * ── ④ 合流（1b83e8..1b84fc + 表 1 删除 + 回收）────────────────────────────
 *   ④-1 搬元素（1b83e8..1b8424）：遍历本层元素链（+0x14 next）：
 *          elem->+0x10 = 候选层（属层）；
 *          type == 2 且 elem+0x20 != 0 → instance(+0x20)->+0x170 = 候选层 id。
 *   ④-2 接链（1b847c..1b84b8）：候选链尾 == 0 → 候选头/尾都指向本层头；否则候选尾->next = 本层头；
 *          本层头->prev = 候选尾；候选尾 = 本层尾；候选元素数 += 本层元素数。
 *   ④-3 摘本层（1b84bc..1b84fc）：本层 head/tail/count 清零；prev->next = next（prev 空则 head = next）；
 *          next->prev = prev（next 空则 tail = prev）；room+0xdc -= 1。
 *   ④-4 删表 1（1b8504..1b87e4）：h = (id+1)&0x7fffffff → 线性探测找到同哈希桶 → **后移填补**
 *          （Knuth 6.4 Algorithm R：反复把「距离 > 0」的后继桶搬进空位，直到遇到距离 0 或空桶）→
 *          末位桶 hash = 0、room+0xe8 -= 1。
 *   ④-5 回收本层（1b85a0..1b86cc）：MemoryInWad(name)==0 才 Free(name)，name = 0；
 *          按 +0x64 回收元素（1 → `operator delete` 循环；2/3 → MemoryManager::Free 循环；其它非 0 → 只走链不释放）；
 *          因为 ④-3 已把元素链清零，这一段对本层实际是空转；
 *          再把 112 B 重置成 ctor 态（id=-1、depth/x/y/hspeed/vspeed=0、visible=1、+0x19=0、name=0、
 *          +0x20/+0x24/+0x28=-1、CTimingSource::Reset、+0x58/+0x5c/+0x60=0、+0x64=1、+0x68/+0x6c=0），
 *          最后压回 m_LayerPool 自由链头（+0x08 += 1）。
 *
 * ── ⑤ 已证缺陷：合流到空链目标层时 prev 自环（1b8484..1b84a4）──────────────
 *   r0 = 候选尾；`cmp r0,#0` 之后：候选空 → 1b848c/1b8498 把候选头尾都指向本层头，
 *   但 1b849c `ldrne r2,[r3,#0x5c]`（取候选尾）**被跳过**，r2 仍是本层头 ⇒ 1b84a4 `str r2,[lr,#0x18]`
 *   把「本层头->prev」写成了**它自己**，而不是 0。
 *   ⇒ 被搬进空动态层的元素链，头节点的 prev 成了自环。凡以 prev==0 判链头的摘链代码都会走错（下游后果未逐点追，open）。
 *   ⇒ 触发面：候选层必须是「同 depth、动态、且元素链为空」的层 —— AddDynamicLayer 建出来的层正是空链，
 *     所以这条不是纯理论路径（虽然要经 ChangeInstanceDepth 那个窄门）。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 第 4 实参的正式名：本卡按行为叫 bMergeDynamic。ID 重载把 1 传进来的可能性存在但该重载无调用者。
 *   · 减深时「同 depth 落组首」、增深时「落组尾」是两条不同规则 —— 是否与 GetLayerWithDepth 的「取第一个」
 *     语义配合，未证（只知 GetLayerWithDepth 命中即返回，不区分组内顺序）。
 *   · 合流后元素链的 tail->next 是否为 0、以及被搬链内部 prev 是否全对，本卡只证了头节点的 prev 缺陷。
 */

/* ── ⓪ 三道门 → 写 depth → 按「旧 vs 新」分流（ble = 增深）──────────────────── */
/* @0x1b8200 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b8204 subs r4, r0, #0 */
/* @0x1b8208 sub sp, sp, #20 */
/* @0x1b820c beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8210 cmp r1, #0 */
/* @0x1b8214 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8218 ldr r0, [r1, #0x4] */
/* @0x1b821c cmp r0, r2 */
/* @0x1b8220 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8224 str r2, [r1, #0x4] */
/* @0x1b8228 ble 0x1b82ac <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xac> */
/* ── ① 减深：P == 0 走 1b843c；否则从 P 往回找「第一个更浅的前驱」──────────────── */
/* @0x1b822c ldr r12, [r1, #0x6c] */
/* @0x1b8230 cmp r12, #0 */
/* @0x1b8234 beq 0x1b843c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x23c> */
/* @0x1b8238 ldr r3, [r12, #0x4] */
/* @0x1b823c cmp r2, r3 */
/* @0x1b8240 movle r3, r12 */
/* @0x1b8244 ble 0x1b8258 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x58> */
/* @0x1b8248 b 0x1b8448 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x248> */
/* ── ①-b 回退环体：new > cur->depth 就停（1b844c），否则再往 prev 走 ───────────── */
/* @0x1b824c ldr r0, [r3, #0x4] */
/* @0x1b8250 cmp r2, r0 */
/* @0x1b8254 bgt 0x1b844c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x24c> */
/* @0x1b8258 ldr r3, [r3, #0x6c] */
/* @0x1b825c cmp r3, #0 */
/* @0x1b8260 bne 0x1b824c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4c> */
/* ── ①-c 超到头：卸载本层（prev->next / next->prev / tail 三修）───────────────── */
/* @0x1b8264 ldr r3, [r1, #0x68] */
/* @0x1b8268 str r3, [r12, #0x68] */
/* @0x1b826c ldr r3, [r1, #0x68] */
/* @0x1b8270 ldr r12, [r1, #0x6c] */
/* ── ①-d 卸载后的头插落点（head 空 → 1b8428 头尾同设）───────────────────────── */
/* @0x1b8274 cmp r3, #0 */
/* @0x1b8278 strne r12, [r3, #0x6c] */
/* @0x1b827c ldr r3, [r4, #0xd4] */
/* @0x1b8280 streq r12, [r4, #0xd8] */
/* @0x1b8284 cmp r3, #0 */
/* @0x1b8288 beq 0x1b8428 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x228> */
/* @0x1b828c str r1, [r3, #0x6c] */
/* @0x1b8290 mov r3, #0 */
/* @0x1b8294 ldr r2, [r4, #0xd4] */
/* @0x1b8298 str r2, [r1, #0x68] */
/* @0x1b829c str r1, [r4, #0xd4] */
/* @0x1b82a0 str r3, [r1, #0x6c] */
/* @0x1b82a4 add sp, sp, #20 */
/* @0x1b82a8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ② 增深：next == 0 走尾插；先比 next->depth，再看第 4 实参决定要不要查同深度 ── */
/* @0x1b82ac ldr r12, [r1, #0x68] */
/* @0x1b82b0 cmp r12, #0 */
/* @0x1b82b4 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b82b8 ldr r0, [r12, #0x4] */
/* @0x1b82bc cmp r2, r0 */
/* @0x1b82c0 blt 0x1b8380 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x180> */
/* ── ②-b cmp r3,#0 判第 4 实参（mov r3,r12 不改标志）→ 同深度判定或直接前进 ────── */
/* @0x1b82c4 cmp r3, #0 */
/* @0x1b82c8 mov r3, r12 */
/* @0x1b82cc bne 0x1b8374 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x174> */
/* @0x1b82d0 ldr r3, [r3, #0x68] */
/* @0x1b82d4 cmp r3, #0 */
/* @0x1b82d8 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b82dc ldr r0, [r3, #0x4] */
/* @0x1b82e0 cmp r2, r0 */
/* @0x1b82e4 blt 0x1b8384 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x184> */
/* @0x1b82e8 ldr r3, [r3, #0x68] */
/* @0x1b82ec cmp r3, #0 */
/* @0x1b82f0 bne 0x1b82dc <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xdc> */
/* ── ②-c 走到尾：卸载 + 尾插（tail->next = 本层，room+0xd8 更新）──────────────── */
/* @0x1b82f4 ldr r3, [r1, #0x6c] */
/* @0x1b82f8 cmp r3, #0 */
/* @0x1b82fc streq r12, [r4, #0xd4] */
/* @0x1b8300 strne r12, [r3, #0x68] */
/* @0x1b8304 ldrne r12, [r1, #0x68] */
/* @0x1b8308 ldrne r3, [r1, #0x6c] */
/* @0x1b830c cmp r12, #0 */
/* @0x1b8310 streq r3, [r4, #0xd8] */
/* @0x1b8314 strne r3, [r12, #0x6c] */
/* @0x1b8318 ldrne r3, [r4, #0xd8] */
/* @0x1b831c cmp r3, #0 */
/* @0x1b8320 beq 0x1b8428 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x228> */
/* @0x1b8324 str r1, [r3, #0x68] */
/* @0x1b8328 mov r3, #0 */
/* @0x1b832c ldr r2, [r4, #0xd8] */
/* @0x1b8330 str r2, [r1, #0x6c] */
/* @0x1b8334 str r1, [r4, #0xd8] */
/* @0x1b8338 str r3, [r1, #0x68] */
/* @0x1b833c add sp, sp, #20 */
/* @0x1b8340 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ③ 同深度：候选 +0x19 / 本层 +0x19 都是非 0（都动态）→ 1b83e8 合流 ────────── */
/* @0x1b8344 ldrb r0, [r3, #0x19] */
/* @0x1b8348 cmp r0, #0 */
/* @0x1b834c beq 0x1b835c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x15c> */
/* @0x1b8350 ldrb r0, [r1, #0x19] */
/* @0x1b8354 cmp r0, #0 */
/* @0x1b8358 bne 0x1b83e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1e8> */
/* @0x1b835c ldr r3, [r3, #0x68] */
/* @0x1b8360 cmp r3, #0 */
/* @0x1b8364 beq 0x1b82f4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xf4> */
/* @0x1b8368 ldr r0, [r3, #0x4] */
/* @0x1b836c cmp r2, r0 */
/* @0x1b8370 blt 0x1b8384 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x184> */
/* @0x1b8374 cmp r2, r0 */
/* @0x1b8378 bne 0x1b835c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x15c> */
/* @0x1b837c b 0x1b8344 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x144> */
/* ── ②-d 找到更深后继：先判「本层 == 后继->prev」→ 直接返回；否则卸载 + 插到后继之前 ── */
/* @0x1b8380 mov r3, r12 */
/* @0x1b8384 ldr r2, [r3, #0x6c] */
/* @0x1b8388 cmp r1, r2 */
/* @0x1b838c beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8390 ldr r2, [r1, #0x6c] */
/* @0x1b8394 cmp r2, #0 */
/* @0x1b8398 streq r12, [r4, #0xd4] */
/* @0x1b839c beq 0x1b83b8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1b8> */
/* @0x1b83a0 str r12, [r2, #0x68] */
/* @0x1b83a4 ldr r12, [r1, #0x68] */
/* @0x1b83a8 ldr r2, [r1, #0x6c] */
/* @0x1b83ac cmp r12, #0 */
/* @0x1b83b0 streq r2, [r4, #0xd8] */
/* @0x1b83b4 beq 0x1b83bc <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1bc> */
/* @0x1b83b8 str r2, [r12, #0x6c] */
/* @0x1b83bc ldr r3, [r3, #0x6c] */
/* ── ②-e 插到 r3 之后（三写点：prev/next/前驱的 next；next 空则 room+0xd8）──────── */
/* @0x1b83c0 str r3, [r1, #0x6c] */
/* @0x1b83c4 ldr r2, [r3, #0x68] */
/* @0x1b83c8 str r2, [r1, #0x68] */
/* @0x1b83cc ldr r2, [r3, #0x68] */
/* @0x1b83d0 cmp r2, #0 */
/* @0x1b83d4 streq r1, [r4, #0xd8] */
/* @0x1b83d8 strne r1, [r2, #0x6c] */
/* @0x1b83dc str r1, [r3, #0x68] */
/* @0x1b83e0 add sp, sp, #20 */
/* @0x1b83e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ④-1 合流：遍历本层元素，改 +0x10 属层；type2 且 +0x20 非空再改 instance+0x170 ── */
/* @0x1b83e8 ldr r2, [r1, #0x58] */
/* @0x1b83ec cmp r2, #0 */
/* @0x1b83f0 bne 0x1b8408 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x208> */
/* @0x1b83f4 b 0x1b8480 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x280> */
/* ── ④-1' 环尾：elem+0x10 = 候选层，elem = elem->next(+0x14) ──────────────────── */
/* @0x1b83f8 str r3, [r2, #0x10] */
/* @0x1b83fc ldr r2, [r2, #0x14] */
/* @0x1b8400 cmp r2, #0 */
/* @0x1b8404 beq 0x1b847c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x27c> */
/* @0x1b8408 ldr r0, [r2] */
/* @0x1b840c cmp r0, #2 */
/* @0x1b8410 bne 0x1b83f8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1f8> */
/* @0x1b8414 ldr r0, [r2, #0x20] */
/* @0x1b8418 cmp r0, #0 */
/* @0x1b841c ldrne r12, [r3] */
/* @0x1b8420 strne r12, [r0, #0x170] */
/* @0x1b8424 b 0x1b83f8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1f8> */
/* ── 空链落点（head = tail = 本层，两链接清 0）────────────────────────────────── */
/* @0x1b8428 str r1, [r4, #0xd8] */
/* @0x1b842c str r1, [r4, #0xd4] */
/* @0x1b8430 str r3, [r1, #0x6c] */
/* @0x1b8434 str r3, [r1, #0x68] */
/* @0x1b8438 b 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* ── ①-e 减深且本层是头：head = 本层->next，然后并到卸载段 ────────────────────── */
/* @0x1b843c ldr r3, [r1, #0x68] */
/* @0x1b8440 str r3, [r4, #0xd4] */
/* @0x1b8444 b 0x1b8274 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x74> */
/* ── ①-f 找到更浅前驱 P'：先判「本层 == P'->next」→ 返回；否则卸载 ──────────────── */
/* @0x1b8448 mov r3, r12 */
/* @0x1b844c ldr r2, [r3, #0x68] */
/* @0x1b8450 cmp r1, r2 */
/* @0x1b8454 beq 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* @0x1b8458 ldr r2, [r1, #0x68] */
/* @0x1b845c str r2, [r12, #0x68] */
/* @0x1b8460 ldr r2, [r1, #0x68] */
/* @0x1b8464 cmp r2, #0 */
/* @0x1b8468 ldreq r2, [r1, #0x6c] */
/* @0x1b846c ldrne r0, [r1, #0x6c] */
/* @0x1b8470 streq r2, [r4, #0xd8] */
/* @0x1b8474 strne r0, [r2, #0x6c] */
/* @0x1b8478 b 0x1b83c0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x1c0> */
/* ── ④-2 接链：候选尾空则头尾都设成本层头；否则候选尾->next 串上；再并计数 ────────── */
/* @0x1b847c ldr r2, [r1, #0x58] */
/* @0x1b8480 ldr r0, [r3, #0x5c] */
/* @0x1b8484 ldr r12, [r3, #0x60] */
/* @0x1b8488 cmp r0, #0 */
/* @0x1b848c streq r2, [r3, #0x5c] */
/* @0x1b8490 strne r2, [r0, #0x14] */
/* @0x1b8494 mov r0, #0 */
/* @0x1b8498 streq r2, [r3, #0x58] */
/* @0x1b849c ldrne r2, [r3, #0x5c] */
/* @0x1b84a0 ldr lr, [r1, #0x58] */
/* @0x1b84a4 str r2, [lr, #0x18] */
/* @0x1b84a8 ldr r2, [r1, #0x5c] */
/* @0x1b84ac str r2, [r3, #0x5c] */
/* @0x1b84b0 ldr r2, [r1, #0x60] */
/* @0x1b84b4 add r2, r12, r2 */
/* @0x1b84b8 str r2, [r3, #0x60] */
/* @0x1b84bc ldr r2, [r1, #0x6c] */
/* @0x1b84c0 ldr r3, [r1, #0x68] */
/* @0x1b84c4 cmp r2, r0 */
/* @0x1b84c8 str r0, [r1, #0x60] */
/* @0x1b84cc str r0, [r1, #0x5c] */
/* @0x1b84d0 str r0, [r1, #0x58] */
/* @0x1b84d4 strne r3, [r2, #0x68] */
/* @0x1b84d8 ldrne r3, [r1, #0x68] */
/* @0x1b84dc ldrne r2, [r1, #0x6c] */
/* @0x1b84e0 streq r3, [r4, #0xd4] */
/* @0x1b84e4 cmp r3, #0 */
/* @0x1b84e8 ldr r0, [r1] */
/* @0x1b84ec strne r2, [r3, #0x6c] */
/* @0x1b84f0 ldr r3, [r4, #0xdc] */
/* @0x1b84f4 streq r2, [r4, #0xd8] */
/* @0x1b84f8 sub r3, r3, #1 */
/* @0x1b84fc str r3, [r4, #0xdc] */
/* ── ④-4 表 1 删除：哈希 → 线性探测找同哈希桶 ────────────────────────────────── */
/* @0x1b8500 str r1, [sp, #0x4] */
/* @0x1b8504 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b8508 ldr r2, [r4, #0xec] */
/* @0x1b850c ldr lr, [r4, #0xf4] */
/* @0x1b8510 ldr r1, [sp, #0x4] */
/* @0x1b8514 bic r0, r0, #-2147483648 */
/* @0x1b8518 and r3, r0, r2 */
/* @0x1b851c lsl r12, r3, #1 */
/* @0x1b8520 add r5, r12, r3 */
/* @0x1b8524 add r5, lr, r5, lsl #2 */
/* @0x1b8528 ldr r5, [r5, #0x8] */
/* @0x1b852c cmp r5, #0 */
/* @0x1b8530 beq 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8534 cmp r0, r5 */
/* @0x1b8538 beq 0x1b8724 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x524> */
/* @0x1b853c ldr r9, [r4, #0xe4] */
/* @0x1b8540 and r5, r2, r5 */
/* @0x1b8544 add r12, r3, r9 */
/* @0x1b8548 rsb r12, r5, r12 */
/* @0x1b854c tst r12, r2 */
/* @0x1b8550 bmi 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8554 mov r6, #0 */
/* @0x1b8558 b 0x1b856c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x36c> */
/* ── ④-4' 探测环体（与 §3 同构，只比哈希）+ 首桶距离守卫（tst/bmi 永不成立）─────── */
/* @0x1b855c cmp r0, r5 */
/* @0x1b8560 beq 0x1b871c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x51c> */
/* @0x1b8564 cmp r7, r6 */
/* @0x1b8568 blt 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b856c add r3, r3, #1 */
/* @0x1b8570 add r6, r6, #1 */
/* @0x1b8574 and r3, r2, r3 */
/* @0x1b8578 add r8, r3, r9 */
/* @0x1b857c lsl r12, r3, #1 */
/* @0x1b8580 add r5, r12, r3 */
/* @0x1b8584 add r5, lr, r5, lsl #2 */
/* @0x1b8588 ldr r5, [r5, #0x8] */
/* @0x1b858c and r7, r2, r5 */
/* @0x1b8590 cmp r5, #0 */
/* @0x1b8594 rsb r7, r7, r8 */
/* @0x1b8598 and r7, r7, r2 */
/* @0x1b859c bne 0x1b855c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x35c> */
/* ── ④-5 回收：MemoryInWad(name) → Free(name)；name 清 0；按 +0x64 分派元素回收 ──── */
/* @0x1b85a0 ldr r0, [r1, #0x1c] */
/* @0x1b85a4 str r1, [sp, #0x4] */
/* @0x1b85a8 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b85ac ldr r1, [sp, #0x4] */
/* @0x1b85b0 cmp r0, #0 */
/* @0x1b85b4 bne 0x1b85c4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3c4> */
/* @0x1b85b8 ldr r0, [r1, #0x1c] */
/* @0x1b85bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b85c0 ldr r1, [sp, #0x4] */
/* @0x1b85c4 ldr r3, [r1, #0x64] */
/* @0x1b85c8 mov r2, #0 */
/* @0x1b85cc str r2, [r1, #0x1c] */
/* @0x1b85d0 cmp r3, r2 */
/* @0x1b85d4 beq 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b85d8 ldr r0, [r1, #0x58] */
/* @0x1b85dc cmp r0, #0 */
/* @0x1b85e0 beq 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b85e4 cmp r3, #2 */
/* @0x1b85e8 moveq r5, r1 */
/* @0x1b85ec beq 0x1b86d0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4d0> */
/* @0x1b85f0 cmp r3, #3 */
/* @0x1b85f4 moveq r5, r1 */
/* @0x1b85f8 beq 0x1b86ec <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4ec> */
/* @0x1b85fc cmp r3, #1 */
/* @0x1b8600 moveq r5, r1 */
/* @0x1b8604 beq 0x1b8704 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x504> */
/* @0x1b8608 mov r3, r0 */
/* @0x1b860c ldr r3, [r3, #0x14] */
/* @0x1b8610 cmp r3, #0 */
/* @0x1b8614 bne 0x1b860c <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x40c> */
/* ── ④-5' 重置成 ctor 态（id=-1、depth/x/y/速度=0、visible=1、+0x19=0、+0x64=1…）── */
/* @0x1b8618 mov r4, #0 */
/* @0x1b861c mvn r12, #0 */
/* @0x1b8620 mov r3, #0 */
/* @0x1b8624 str r4, [r1, #0x60] */
/* @0x1b8628 str r3, [r1, #0x8] */
/* @0x1b862c mov r5, #1 */
/* @0x1b8630 str r3, [r1, #0xc] */
/* @0x1b8634 mov r2, #0 */
/* @0x1b8638 str r3, [r1, #0x10] */
/* @0x1b863c add r0, r1, #48 */
/* @0x1b8640 str r3, [r1, #0x14] */
/* @0x1b8644 mov r3, #0 */
/* @0x1b8648 str r4, [r1, #0x5c] */
/* @0x1b864c strd r2, r3, [r1, #72] */
/* @0x1b8650 str r4, [r1, #0x58] */
/* @0x1b8654 str r4, [r1, #0x4] */
/* @0x1b8658 strb r4, [r1, #0x19] */
/* @0x1b865c str r4, [r1, #0x1c] */
/* @0x1b8660 str r12, [r1] */
/* @0x1b8664 str r12, [r1, #0x20] */
/* @0x1b8668 str r12, [r1, #0x24] */
/* @0x1b866c str r12, [r1, #0x28] */
/* @0x1b8670 strb r5, [r1, #0x18] */
/* @0x1b8674 str r1, [sp, #0x4] */
/* @0x1b8678 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* ── ④-5'' 压回 m_LayerPool 自由链头（槽 0x3f0864），计数 +1 ──────────────────── */
/* @0x1b867c ldr r3, [pc, #0x16c] */
/* @0x1b8680 ldr r1, [sp, #0x4] */
/* @0x1b8684 ldr r3, [pc, r3] */
/* @0x1b8688 ldr r2, [r3] */
/* @0x1b868c ldr r0, [r3, #0x8] */
/* @0x1b8690 cmp r2, r4 */
/* @0x1b8694 str r4, [r1, #0x68] */
/* @0x1b8698 str r4, [r1, #0x6c] */
/* @0x1b869c add r0, r0, r5 */
/* @0x1b86a0 str r4, [r1, #0x5c] */
/* @0x1b86a4 str r4, [r1, #0x58] */
/* @0x1b86a8 str r4, [r1, #0x60] */
/* @0x1b86ac str r5, [r1, #0x64] */
/* @0x1b86b0 str r0, [r3, #0x8] */
/* @0x1b86b4 strne r1, [r2, #0x6c] */
/* @0x1b86b8 strne r1, [r3] */
/* @0x1b86bc strne r2, [r1, #0x68] */
/* @0x1b86c0 strne r4, [r1, #0x6c] */
/* @0x1b86c4 streq r1, [r3, #0x4] */
/* @0x1b86c8 streq r1, [r3] */
/* @0x1b86cc b 0x1b82a4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0xa4> */
/* ── +0x64 == 2 / == 3：MemoryManager::Free 逐元素（两段同构）───────────────── */
/* @0x1b86d0 ldr r4, [r0, #0x14] */
/* @0x1b86d4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b86d8 cmp r4, #0 */
/* @0x1b86dc mov r0, r4 */
/* @0x1b86e0 bne 0x1b86d0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4d0> */
/* @0x1b86e4 mov r1, r5 */
/* @0x1b86e8 b 0x1b8618 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x418> */
/* @0x1b86ec ldr r4, [r0, #0x14] */
/* @0x1b86f0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b86f4 cmp r4, #0 */
/* @0x1b86f8 mov r0, r4 */
/* @0x1b86fc bne 0x1b86ec <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4ec> */
/* @0x1b8700 b 0x1b86e4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4e4> */
/* ── +0x64 == 1：operator delete 逐元素 ─────────────────────────────────────── */
/* @0x1b8704 ldr r4, [r0, #0x14] */
/* @0x1b8708 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b870c cmp r4, #0 */
/* @0x1b8710 mov r0, r4 */
/* @0x1b8714 bne 0x1b8704 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x504> */
/* @0x1b8718 b 0x1b86e4 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x4e4> */
/* ── ④-4'' 命中后的删除：后移填补循环（距离 > 0 就把后继桶搬进空位）────────────── */
/* @0x1b871c cmn r3, #1 */
/* @0x1b8720 beq 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* @0x1b8724 add r0, r3, #1 */
/* @0x1b8728 and r9, r0, r2 */
/* @0x1b872c add r6, r9, r9, lsl #1 */
/* @0x1b8730 add r6, lr, r6, lsl #2 */
/* @0x1b8734 ldr r5, [r6, #0x8] */
/* @0x1b8738 cmp r5, #0 */
/* @0x1b873c beq 0x1b87e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5e8> */
/* @0x1b8740 ldr r8, [r4, #0xe4] */
/* @0x1b8744 and r0, r2, r5 */
/* @0x1b8748 add r7, r9, r8 */
/* @0x1b874c rsb r0, r0, r7 */
/* @0x1b8750 tst r0, r2 */
/* @0x1b8754 strne r4, [sp, #0x8] */
/* @0x1b8758 strne r1, [sp, #0xc] */
/* @0x1b875c movne r11, r8 */
/* @0x1b8760 bne 0x1b8774 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x574> */
/* @0x1b8764 b 0x1b87e8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5e8> */
/* @0x1b8768 tst r4, r2 */
/* @0x1b876c beq 0x1b87c0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5c0> */
/* @0x1b8770 mov r9, r1 */
/* @0x1b8774 add r4, r12, r3 */
/* @0x1b8778 add r1, r9, #1 */
/* @0x1b877c and r1, r1, r2 */
/* @0x1b8780 ldr r7, [r6, #0x4] */
/* @0x1b8784 add r0, lr, r4, lsl #2 */
/* @0x1b8788 add r8, r1, r11 */
/* @0x1b878c add r10, r1, r1, lsl #1 */
/* @0x1b8790 mov r3, r9 */
/* @0x1b8794 str r5, [r0, #0x8] */
/* @0x1b8798 lsl r12, r9, #1 */
/* @0x1b879c ldr r6, [r6] */
/* @0x1b87a0 str r6, [lr, r4, lsl #2] */
/* @0x1b87a4 add r6, lr, r10, lsl #2 */
/* @0x1b87a8 ldr r5, [r6, #0x8] */
/* @0x1b87ac str r7, [r0, #0x4] */
/* @0x1b87b0 cmp r5, #0 */
/* @0x1b87b4 and r4, r2, r5 */
/* @0x1b87b8 rsb r4, r4, r8 */
/* @0x1b87bc bne 0x1b8768 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x568> */
/* ── ④-4''' 末位桶 hash = 0、room+0xe8 -= 1，回 1b85a0 回收 ───────────────────── */
/* @0x1b87c0 ldr r4, [sp, #0x8] */
/* @0x1b87c4 ldr r1, [sp, #0xc] */
/* @0x1b87c8 add r0, r9, r9, lsl #1 */
/* @0x1b87cc ldr r3, [r4, #0xe8] */
/* @0x1b87d0 mov r2, #0 */
/* @0x1b87d4 add lr, lr, r0, lsl #2 */
/* @0x1b87d8 sub r3, r3, #1 */
/* @0x1b87dc str r2, [lr, #0x8] */
/* @0x1b87e0 str r3, [r4, #0xe8] */
/* @0x1b87e4 b 0x1b85a0 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x3a0> */
/* ── 未命中/空槽：直接清该桶（r9 = r3）并回收 ────────────────────────────────── */
/* @0x1b87e8 mov r9, r3 */
/* @0x1b87ec b 0x1b87c8 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib+0x5c8> */
/* @0x1b87f0 .word 0x002381d8 */

/* ══ §5 CLayerManager::ChangeLayerDepth(CRoom*, int, int, bool) 0x1b8948 ════
 * @func 0x1b8948 0x1b897c  size 52  13 条（13 指令，无字面量池）
 * 级别: 正文（13/13。整函数是一条直线：两道门 + 一次查表 + 尾跳）
 * 符号: _ZN13CLayerManager16ChangeLayerDepthEP5CRoomiib
 *       → void CLayerManager::ChangeLayerDepth(CRoom* room, int id, int depth, bool bMergeDynamic)
 * 调用者: **全库 0 处**。按 BL(0xEB) 与 B(0xEA) 两种编码全 .text 扫了一遍，没有一条跳到 0x1b8948；
 *         0x001b8948 也不作为数据字出现在 .rodata/.data（只有 .dynsym 的符号表项），
 *         连「movw/movt 两半拼地址」的写法也扫过（imm16 = 0x8948 与 0x001b 一对都没有）。⇒ 本重载在本 so 里是**死代码**，
 *         保留它的唯一痕迹是导出表 —— 这也解释了为什么 §4 的合流分支只可能由 ChangeInstanceDepth 那条窄路触发。
 * 同层: §4 0x1b8200（尾跳目标）、GetLayerFromID 0x1b8868
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   把 id 换成 CLayer*（查不到就静默返回），再把四个实参原地转交给 §4，用 `b` 而不是 `bl`（先 pop 再跳）。
 *
 * ── 值得一读的只有寄存器搬运（1b894c..1b8978）────────────────────────────
 *   r4 = room、r6 = depth、r5 = bool 先落 callee-saved；room == 0 → `popeq` 直接返回；
 *   `bl GetLayerFromID(room, id)` → r1 = 返回值；`subs r1,r0,#0` + `popeq`（层不存在 → 静默返回，**不报错**）；
 *   再 `mov r0,r4 / r2,r6 / r3,r5` 摆好第 1/3/4 实参，`pop {r4,r5,r6,lr}` 恢复栈帧后 `b 0x1b8200` —— 尾调用。
 */

/* ── ⓪ 门（room）+ 查表 + 门（层）+ 尾跳 §4 ────────────────────────────────── */
/* @0x1b8948 push {r4, r5, r6, lr} */
/* @0x1b894c subs r4, r0, #0 */
/* @0x1b8950 mov r6, r2 */
/* @0x1b8954 mov r5, r3 */
/* @0x1b8958 popeq {r4, r5, r6, pc} */
/* @0x1b895c bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b8960 subs r1, r0, #0 */
/* @0x1b8964 popeq {r4, r5, r6, pc} */
/* @0x1b8968 mov r0, r4 */
/* @0x1b896c mov r2, r6 */
/* @0x1b8970 mov r3, r5 */
/* @0x1b8974 pop {r4, r5, r6, lr} */
/* @0x1b8978 b 0x1b8200 <_ZN13CLayerManager16ChangeLayerDepthEP5CRoomP6CLayerib> */

/* ══ §6 CLayerManager::AddNewElement 0x1c5ff0 ══════════════════════════════
 * @func 0x1c5ff0 0x1c606c  size 124  31 条（30 指令 + 1c6068 一个字面量池字 0x0022aac0）
 * 级别: 正文（31/31。门、发号、挂链顺序、运行期数据开关、返回值全解。未钉：第 4 实参在各调用点的业务含义）
 * 符号: _ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb
 *       → int CLayerManager::AddNewElement(CRoom* room, CLayer* layer, CLayerElementBase* elem, bool bBuildRuntimeData)
 * 调用者（全库 17 处：15 bl + 2 b）：BuildRoomLayers 5 处（1c6434/1c66b0/1c68e0/1c6a34/1c6c64）、
 *       DeSerializeLayer 3 处（1c7b48/1c7dc4/1c7fdc）、F_LayerAddInstance 2 处尾跳（1c6cd4/1c6ddc）、
 *       F_LayerBackgroundCreate 1c6fe8、F_LayerSpriteCreate 1c7130、F_LayerTilemapCreate 1c72d0、F_LayerTileCreate 1c7460、
 *       ParticleSystem_Create 1a44d4、ParticleSystem_Layer 1a475c、ParticleSystem_AddAllToLayers 1a5c5c
 * 同层: AddElementToLayer 0x1c451c（唯一的链/表写入口）、BuildElementRuntimeData 0x1ba6bc、
 *       CHashMapCalculateHash 无关；m_CurrentElementID 0x5425f0（槽 0x3f0ae8）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   发一个全局自增 uid 写进 elem+0x04 → 交给 AddElementToLayer 挂链（**第 4 实参恒 0 = 头插**）→
 *   若调用方要求，立刻建运行期数据 → 返回 uid；三个指针任一为空返回 -1。
 *
 * ── 逐段（全文只有一条直线 + 一个分叉）──────────────────────────────────
 *   ① 1c5ff0..1c6014：push {r4-r8,lr}；r8 = room、r5 = layer、r4 = elem、r6 = 第 4 实参；
 *      三道门（room/layer/elem 全非空）→ 否则 1c6060 `mvn r0,#0` 返回 -1。
 *   ② 1c6018..1c6030：双段取址 —— 池字 1c6068 = 0x0022aac0，`ldr r12,[pc,r12]`（pc = 1c6028）得
 *      0x3f0ae8 → m_CurrentElementID；`lr = *计数器; r7 = lr+1; *计数器 = r7; elem+0x04 = lr`。
 *      ⇒ **先取后加**：返回/写入的 uid 是自增**前**的值；计数器从 .bss 的 0 起跑。
 *   ③ 1c601c/1c6034：`mov r3,#0` 后 `bl AddElementToLayer(room, layer, elem, 0)` —— 头插（+0x58 侧），
 *      顺带写 elem+0x10 = layer、插表 2、type==2 再插表 3。
 *   ④ 1c6038..1c605c：第 4 实参 == 0 → 直接 `ldr r0,[r4,#4]` 返回 uid；
 *      != 0 → `bl BuildElementRuntimeData(room, layer, elem)`（0x1ba6bc，按 elem+0x00 的 type 分派）再返回 uid。
 *      ⇒ **顺序上挂链在前、建运行期数据在后**：运行期数据能看到「元素已经在链上、已经在表 2/表 3 里」。
 *
 * ── 第 4 实参（本卡把它钉到「只当开关用」，但各调用点的业务含义仍 open）──────────
 *   全库 17 个调用点里，既有常量也有现算的 bool，两种现算写法各出现一次：
 *     · F_LayerBackgroundCreate 1c6fbc..1c6fc4：`cmp r3,r8` + `movne #0` / `moveq #1`（== 的比较）
 *     · F_LayerSpriteCreate 1c711c..1c7124：`subs/rsbs/adcs` 三连（!= 的惯用法，r12 != 0 得 1）
 *   ⇒ 它进函数后**只**控制 ④ 的那一次调用，不影响挂链位置、不影响 uid、不影响返回值。
 *   ⇒ 顺带纠一条旧 open：CLayerManager_Build 卡写「AddNewElement 第 4 实参语义未钉」——本卡至少钉死了它**不是**
 *     「尾插开关」（尾插开关是 AddElementToLayer 的第 4 实参，而这里恒写 0）。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 那两种现算 bool 的业务含义（是「新建 vs 复用」还是「是否动态」）：要逐调用点读 GML 参数，本卡未做。
 *   · uid 计数器永不回绕检查（发到 0x7fffffff 会让哈希撞上「空桶 = 0」标记，见 §3 的边界说明）。
 */

/* ── ⓪ 三道门（room/layer/elem）→ 空则返回 -1 ──────────────────────────────── */
/* @0x1c5ff0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c5ff4 subs r8, r0, #0 */
/* @0x1c5ff8 mov r6, r3 */
/* @0x1c5ffc mov r5, r1 */
/* @0x1c6000 mov r4, r2 */
/* @0x1c6004 beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* @0x1c6008 cmp r1, #0 */
/* @0x1c600c beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* @0x1c6010 cmp r2, #0 */
/* @0x1c6014 beq 0x1c6060 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x70> */
/* ── ① 发号：槽 0x3f0ae8 = m_CurrentElementID，先取后加，写 elem+0x04 ─────────── */
/* @0x1c6018 ldr r12, [pc, #0x48] */
/* @0x1c601c mov r3, #0 */
/* @0x1c6020 ldr r12, [pc, r12] */
/* @0x1c6024 ldr lr, [r12] */
/* @0x1c6028 add r7, lr, #1 */
/* @0x1c602c str r7, [r12] */
/* @0x1c6030 str lr, [r2, #0x4] */
/* ── ② 挂链（第 4 实参恒 0 = 头插）→ ③ 可选建运行期数据 → 返回 uid ────────────── */
/* @0x1c6034 bl 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1c6038 cmp r6, #0 */
/* @0x1c603c bne 0x1c6048 <_ZN13CLayerManager13AddNewElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x58> */
/* @0x1c6040 ldr r0, [r4, #0x4] */
/* @0x1c6044 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6048 mov r0, r8 */
/* @0x1c604c mov r1, r5 */
/* @0x1c6050 mov r2, r4 */
/* @0x1c6054 bl 0x1ba6bc <_ZN13CLayerManager23BuildElementRuntimeDataEP5CRoomP6CLayerP17CLayerElementBase> */
/* @0x1c6058 ldr r0, [r4, #0x4] */
/* @0x1c605c pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6060 mvn r0, #0 */
/* @0x1c6064 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c6068 eoreq r10, r2, r0, asr #21 */
