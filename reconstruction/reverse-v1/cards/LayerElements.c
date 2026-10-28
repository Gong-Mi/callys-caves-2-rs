/* cally 逆向卡：层元素三件（原版 libyoyo.so，armv7）—— 一卡三节
 * @func 节序按调用关系排（插入 → 存储实例移除 → 旧 tilemap 移除），不是地址升序；逐节自带 @func 头与逐条锚点：
 *   §1 0x1c451c CLayerManager::AddElementToLayer                size  708   177 行 = 175 指令 + 2 池字（1c47d8 / 1c47dc）
 *   §2 0x1b9ea4 CLayerManager::RemoveStorageInstanceFromLayer   size 1300   325 行 = 322 指令 + 3 池字（1ba3ac / 1ba3b0 / 1ba3b4）
 *   §3 0x1b7bac CLayerManager::RemoveOldTilemapElement          size  332    83 行 =  82 指令 + 1 池字（1b7cf4）
 * 总账: 585 锚点 = 579 条指令 + 6 个字面量池字，与 asm/index-CLayerManager_AddElementToLayer.tsv(177)、
 *       asm/index-CLayerManager_RemoveStorageInstanceFromLayer.tsv(325)、
 *       asm/index-CLayerManager_RemoveOldTilemapElement.tsv(83) 逐字一致
 *       （scripts/check_card_anchors.py 两种口径都跑过：
 *        ① 三张 TSV 拼成一份 585 行的合并索引 → index=585 card=585 missing=0 extra=0
 *           mismatch=0 RESULT EXACT（合并索引只落在 scratch，不进仓库）；
 *        ② 按本卡三节的地址区间切片，与各自的 TSV 逐条对齐 → 177/177、325/325、83/83 各 EXACT）。
 *       ⇒ 708 + 1300 + 332 = 2340 B = 579*4 + 6*4，无一条指令漏锚。
 * 级别: 正文（三节都逐条解码到控制流 / 字段写点 / 算式 / 跳转；每节末尾单列本节 open，
 *       没钉的地方不冒充已钉。tier = bytecode_anchored）
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录。六个池字保留 objdump 的写法
 *       （按节序：svclo / andseq / eoreq / andseq / .word / eoreq），在各节注释里逐字标「非指令」。
 *
 * ── 全局坐标（.rel.dyn（R_ARM_RELATIVE=23）槽内 addend 直读 + .symtab 实测）──
 *   GOT 槽      目标        符号（.symtab 原名，OBJECT 20 B）                本卡用处
 *   0x3f086c → 0x542678   CLayerManager::m_InstanceElementPool             §2 回池（36 B 元素）
 *   0x3f0870 → 0x542664   CLayerManager::m_OldTilemapElementPool           §3 回池（52 B 元素）
 *   0x3ed71c → 0x3eb70c   dbg_csol（4 B 指针，值 0x47a118 = _dbg_csol）      §2 诊断宿主
 *   ⇒ 前两条与 LayerRemove 卡（0x3f086c / 0x3ed71c）、AddInstanceToLayer 卡（0x3f086c）同槽独立吻合。
 *   池对象布局（ObjectPool<T>，20 B；两个工厂与 §2/§3 的回收侧逐字段一致）：+0x00 自由链头 / +0x04 链尾 / +0x08 可用数 /
 *     +0x0c 逐元素回收方式 / +0x10 本轮回填容量。+0x0c 只有 ~ObjectPool<T> 读它：
 *     1b6c8c 的 1b6cc4..1b6d28 按 {1 → operator delete, 2 → MemoryManager::Free,
 *     3 → 先做元素析构再 Free} 三档分派。
 *   元素类与字节数（Alloc 实参实测）：CLayerInstanceElement 36 B（GetNewInstanceElement 1c0d14
 *     `mov r0,#36`）、CLayerOldTilemapElement 52 B（GetNewOldTilemapElement 1c0e20 `mov r0,#52`）；
 *     两处 Alloc 的 file/line 都是 "…/Room/Room_Layers.h" 第 63 行。
 *   §1 的扩容走另一条记账：Alloc(size, "jni/../jni/yoyo/../../../Platform/MemoryManager.h", 70, true)
 *     —— 串 0x331038 由 1c46c8 的 `add r1,pc,r1` + 池字 1c47dc(0x0016c968) 算出。
 *   串 0x34d6d0 = "Layer system integrity compromised, instance %d not on layer %d\n"（§2 诊断用，
 *     与 LayerRemove §3 属层校验串**同一地址、同一条 fail-soft 策略**；两个 %d = 实例 id、层 id）。
 *
 * ── 哈希：CHashMapCalculateHash<int> 0x1b6e44 只有两条指令（add r0,r0,#1 / bx lr）──
 *   ⇒ h(key) = key + 1，调用方再 `bic r0,r0,#-2147483648` 清符号位 ⇒ 桶哈希 = (key+1) & 0x7fffffff。
 *   ⇒ **这个映射在 31 位内是单射**（两个键要碰撞得相差 2^31）。LayerRemove 卡留的 open
 *     「三处探测都不重比键、撞哈希会被当成同一条」在本卡可以收口：插入侧（本卡 §1）比哈希也比键，
 *     删除侧只比哈希，但两者在 uid / 实例 id 的真实取值域上等价 —— 除非有人塞进相差 2^31 的两个键。
 *   ⚠ 副产物：key = -1 的哈希是 0，正好等于「空槽」哨兵（桶项 +0x08 == 0 判空）。活元素的 uid 从
 *     计数器 0x5425f0 起（AddNewElement 1c6024 取旧值再 +1）、实例 id 的 -1 被 §2 的门挡掉，
 *     所以这条只在池对象上成立，不是可达缺陷。
 *
 * ── 房间三张 CHashMap（每簇 20 B：+0x00 容量 / +0x04 已用 / +0x08 掩码 / +0x0c 阈值 / +0x10 桶；
 *    桶项 12 B = {+0x00 键(int) / +0x04 值(指针) / +0x08 31 位哈希}）──
 *   表 1 @ room+0xe4   键 layer->id(+0x00)   值 CLayer*                 本卡不碰
 *   表 2 @ room+0xf8   键 elem->uid(+0x04)   值 CLayerElementBase*      §1 插 / §2 删
 *   表 3 @ room+0x110  键 实例 id(+0x1c)     值 CLayerInstanceElement*  §1 插（仅 type 2）/ §2 删
 *   另：room+0x10c = GetElementFromID 0x1bc2a0 的单条缓存；§2 摘掉元素时相等则清 0。
 *
 * ── 元素字段地图（本卡三节 + 两个工厂的写点实测）──
 *   偏移   36 B CLayerInstanceElement            52 B CLayerOldTilemapElement
 *   +0x00  type = 2                              type = 3
 *   +0x04  uid（池态 -1）                        uid（池态 -1）
 *   +0x08  池/在用字节（活 1 / 池 0）            同
 *   +0x0c  0                                     0
 *   +0x10  所属 CLayer*（0 = 不在层上）           同
 *   +0x14  next（池态当自由链 next）              同
 *   +0x18  prev（池态当自由链 prev）              同
 *   +0x1c  实例 id（池态 -1）                    **堆指针：本类自有负载，§3 ① 无条件 Free**
 *   +0x20  CInstance*（0 = 只存 id 的存储元素）   0（本卡未见非 0 写方）
 *   +0x24  —（类大小到 +0x24 为止）              **负载对象指针（§3 ④ 按 +0x30 释放）**
 *   +0x28  —                                     0（本卡未见非 0 写方）
 *   +0x2c  —                                     0（本卡未见非 0 写方）
 *   +0x30  —                                     **负载种类 1/2/3（0 = 无负载）**
 *   ⇒ 同一个 +0x1c 在实例元素里是「键」，在旧 tilemap 元素里是「要释放的指针」：七个族回收器是逐类
 *     编译的（RemoveElement 的 type 跳表 1b90dc..1b90f4 各自尾跳），不要跨类套用偏移语义。
 *
 * ── 跨节结论（本题三个重点）──────────────────────────────────────────────
 *   A. 插入侧只有一条路，移除侧按「有没有 CInstance」分成四只：
 *        §1 AddElementToLayer(room, layer, elem, bTail)      插链 + 计数 + 表 2 [+ 表 3]
 *        RemoveElement(room, layer, elem, bDestroy)          通用路：删表 → 交族回收器（LayerRemove §1）
 *        RemoveInstanceFromLayer(room, layer, CInstance*)    有实例：删表 → 摘链 → 回池 → 写 inst+0x170/+0x174
 *        §2 RemoveStorageInstanceFromLayer(room, layer, int) 只有 id：删表 → 摘链 → 回池 → **不碰 CInstance**
 *        §3 RemoveOldTilemapElement(layer, elem)             **没有 room 实参** ⇒ 物理上不能删表
 *      ⇒ 表 2/表 3 的删除只发生在「拿得到 room」的移除函数里；拿不到 room 的族回收器只管链表与池。
 *   B. 链插入与链摘除逐字段对称，但**顺序相反**：
 *        插入（§1 ②③）：elem+0x10 = layer 在 1c45b0 写；+0x14/+0x18 接链；layer+0x58/+0x5c 改头尾；
 *                         layer+0x60 计数 +1（1c4544 / 1c4580，在空链判定之前）。
 *        摘除（§2 ⑥ / §3 ②）：prev ? prev->next = next : layer+0x58 = next；
 *                         next ? next->prev = prev : layer+0x5c = prev；layer+0x60 计数 -1。
 *      ⇒ 元素回池时 +0x14/+0x18 被清 0 后当池自由链用：**同一对偏移，活对象上是层链、池对象上是自由链**。
 *      ⇒ 顺序不对称：插入是「先插链、后插表」（§1 的链在 1c4534..1c45b8，表在 1c45bc 之后），
 *        移除是「先删表、后摘链」（§2 的表在 1b9fdc/1ba07c，摘链在 1ba11c）。中间态方向相反：
 *        插入期「链上已有、表里还查不到」，移除期「表里已查不到、链上还在」。两者都只在帧内可见。
 *   C. 池协议对称：回收侧写回的每个字段都等于工厂侧初值（type / uid = -1 / +0x08 = 0 /
 *      +0x0c..+0x20 全 0，§3 另加 +0x24/+0x28/+0x2c 与 +0x30 = 1），然后头插自由链、可用数 +1。
 *      ⇒ 「回池 = 回到出厂状态」，不是只清链指针。§2 与 §3 的复位写点可逐条对上各自的工厂：
 *      GetNewInstanceElement 1c0d30..1c0d44 / GetNewOldTilemapElement 1c0e3c..1c0e6c。
 *   D. 「存储实例」特例 = 没有 CInstance 实参的那条：唯一调用者是 GML `layer_add_instance`
 *      （F_LayerAddInstance 0x1c6cf4）的搬层路径，它用「删旧元素 + 造新元素」实现搬层，所以 §2 必须
 *      把旧元素完整回池；新元素的 +0x20 保持 0，元素只靠 +0x1c 的 id 指向实例。详见 §2 头部。
 *   E. 「旧 tilemap」特例 = 唯一在摘链**之前**释放自有负载的移除器，且是唯一没有 room 的移除器。
 *      它的负载释放段与 ~ObjectPool<CLayerOldTilemapElement>（0x1b6c8c）里的元素析构
 *      1b6d04..1b6e28 是同一段代码 ⇒ 可以确认那是**元素析构**而不是引用计数。详见 §3 头部。
 *   F. 动态层自删：§2 末尾（1ba1dc..1ba204）判 layer+0x19 != 0 && layer+0x60 == 0 →
 *      尾跳 RemoveLayer(room, layer->id, -1)，与 RemoveInstanceFromLayer 的 1b9c58..1b9c80 逐条同构；
 *      §3 没有 room，不做。第 3 实参两个入口传的都是 0（§2 是「刚减到 0 的层计数」、0x1c013c 是常量 0），
 *      而 RemoveLayer 不读它（LayerRemove §2 已证）⇒ 这个槽从来没有被赋予语义。
 *      ⚠ 勘误：LayerRemove 卡 §3 把该实参记成 -1，那是沿用了 1b9c4c 的 `mvn r2,#0`；1b9c64 的
 *      `ldr r2,[r10,#0x60]` 会覆盖它。本卡按机器码纠正（见 §2 ⑩）。
 *
 * ── 汇总 open（各节还有细项）──
 *   · 表 2 的初始容量：§1 只做「已用数 > 阈值 ⇒ 翻倍」，容量为 0 时既不会扩容也无法落位
 *     ⇒ 两张表必由房间构造期铺好；谁铺的（CRoom ctor / CLayerManager::Build）本卡未核。
 *   · CHashMap<int,CLayerElementBase*,7>::Insert 0x1c384c（1640 B）内部：重插时是否改 +0x104、
 *     是否自己也会扩容、值指针是否被复制 —— 未读；§1 ⑨ 结尾「再算一次阈值」正是为它留的余量。
 *   · §2 的两段回移压缩只证到「遇到空槽或探测距离为 0 的槽就停、逐槽搬 {哈希,键,值}、末槽哈希清 0、
 *     已用数 -1」，逐位的同簇判定未还原（与 LayerRemove 卡同一处 open）。
 *   · §2 里 1b9f14 的 `tst r1,r12 / bmi`（掩码不含 bit31）与 1b9f70 的 `cmn r3,#1`、
 *     1b9f80 的 `cmn r8,#4` 都是**恒不跳**的编译残迹；源语言形态未还原，保留记录以免误读成真门。
 *   · §3 的 +0x24 所指对象类型名、+0x30 三个取值的语义名（1/2/3）未证；只知道它与 ObjectPool<T>
 *     的 +0x0c 用同一套三档约定，且对象自带一条 +0x704 链。
 *   · 元素类大小的完整七类表（32/36/52/60/72/80）来自 DuplicateRoomLayers 卡的池簇；本卡只实测了
 *     36（实例）与 52（旧 tilemap）两个。
 */

/* ══ §1 CLayerManager::AddElementToLayer 0x1c451c ═══════════════════════
 * @func 0x1c451c 0x1c47e0 size 708  177 行（175 指令 + 2 池字 1c47d8 / 1c47dc）
 * 级别: 正文（175/175。头插/尾插两条链路径、计数、表 2 的 Robin-Hood 插入、同键覆盖、
 *       0.6 负载因子的翻倍重建、type 2 尾调表 3 Insert 全部钉住。未钉：表 2 的初始容量由谁铺、
 *       CHashMap::Insert 0x1c384c 内部、覆盖路径旧值指针的归属）
 * 符号: _ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb
 *       → void CLayerManager::AddElementToLayer(CRoom* room, CLayer* layer, CLayerElementBase* elem, bool bTail)
 * 调用者（全 .text 9 处直呼）：DuplicateRoomLayers 的 7 个 bl（1c4ecc / 1c5068 / 1c5204 /
 *       1c539c / 1c54bc / 1c5804 / 1c59f4）、AddNewElement 0x1c5ff0 的 1c6034、DeSerializeLayer 的 1c8364
 * 同层: AddInstanceToLayer 0x1c5a38（把 instance+0x69 原样当第 4 实参传进来）、
 *       CHashMapCalculateHash<int> 0x1b6e44、CHashMap<int,CLayerElementBase*,7>::Insert 0x1c384c、
 *       CHashMap<int,CLayerInstanceElement*,7>::Insert 0x1c3eb4、MemoryManager::Alloc 0x27ce78、
 *       MemoryManager::Free 0x27c2d0、memset@plt 0xb65b0
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   把已经填好字段的元素挂到层上：按第 4 实参决定头插还是尾插 → 计数 +1 → 写 elem+0x10 = layer →
 *   插进 room 的表 2（键 = elem+0x04 的 uid；负载因子 0.6，超了先把桶翻倍重建）→
 *   type == 2 时再尾调表 3 的 Insert（键 = elem+0x1c 的实例 id）。
 *   **本函数不写 type / uid / +0x08 / +0x1c / +0x20**（那是调用方的事），**不判任何实参非空**，
 *   **不碰 room+0x10c 缓存、不碰表 1、不建运行期数据**。
 *
 * ── ① 入口：只按第 4 实参分流，没有任何守卫（1c451c..1c4530）──────────────
 *   push 九个寄存器、留 12 B 栈；r8 = room；[sp+4] = elem；`cmp r3,#0` + `beq 1c4570`：
 *     r3 != 0 → 尾插（②）；r3 == 0 → 头插（③）。
 *   ⚠ **没有 elem == 0 / layer == 0 / room == 0 的检查**：1c4534 立刻读 [r1,#0x5c]、
 *     1c45a0 立刻读 [r8,#0xfc]。⇒ 三实参非空是调用方契约（AddNewElement 1c5ff4..1c6014 自己有三道门、
 *     DuplicateRoomLayers 按链遍历、AddInstanceToLayer 三道门）。
 *   ⚠ 第 4 实参的来源与语义：AddInstanceToLayer 卡已证它来自 CInstance::SetDeactivated 写的
 *     instance+0x69。未停用 → 0 → 头插（成为 layer+0x58 的新头）；已停用 → 非 0 → 尾插（接到
 *     layer+0x5c）。⇒ 同层元素链是「未停用在前、停用在尾」的双端插入表，不是纯 FIFO/LIFO。
 *   ⚠ 同一个 bool 在 AddNewElement 里还有第二个含义：1c6038 判它非 0 才调 BuildElementRuntimeData
 *     0x1ba6bc。本函数只把它当「插尾部」用；两者是否在所有调用点同向，未逐点核（open）。
 */

/* @0x1c451c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c4520 cmp r3, #0 */
/* @0x1c4524 sub sp, sp, #12 */
/* @0x1c4528 mov r8, r0 */
/* @0x1c452c str r2, [sp, #0x4] */
/* @0x1c4530 beq 0x1c4570 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x54> */

/* ── ② 尾插（bTail != 0，1c4534..1c456c）────────────────────────────────
 *   r3 = layer+0x5c（链尾）、r2 = layer+0x60（计数）；**先把计数 +1 写回**（1c453c..1c4544），
 *   再判链尾是否为空：
 *     空   → 跳 1c47a4（⑩ 空链分支），本段不写链；
 *     非空 → old_tail->next(+0x14) = elem；elem->prev(+0x18) = old_tail；
 *            layer+0x5c = elem；elem->next(+0x14) = 0。
 *   ⇒ 尾插 = 三个真写点 + 一次清 0，与头插（③）逐字段镜像；两次计数 +1 都在「空链判定之前」，
 *     所以 2/3/⑩ 三条路都不会漏计数。
 */

/* @0x1c4534 ldr r3, [r1, #0x5c] */
/* @0x1c4538 ldr r2, [r1, #0x60] */
/* @0x1c453c cmp r3, #0 */
/* @0x1c4540 add r2, r2, #1 */
/* @0x1c4544 str r2, [r1, #0x60] */
/* @0x1c4548 beq 0x1c47a4 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x288> */
/* @0x1c454c ldr r2, [sp, #0x4] */
/* @0x1c4550 ldr r0, [sp, #0x4] */
/* @0x1c4554 str r2, [r3, #0x14] */
/* @0x1c4558 mov r3, #0 */
/* @0x1c455c ldr r2, [r1, #0x5c] */
/* @0x1c4560 str r2, [r0, #0x18] */
/* @0x1c4564 str r0, [r1, #0x5c] */
/* @0x1c4568 str r3, [r0, #0x14] */
/* @0x1c456c b 0x1c45a0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x84> */

/* ── ③ 头插（bTail == 0，1c4570..1c459c）─────────────────────────────────
 *   r2 = layer+0x58（链头）、r0 = 计数 → +1 写回；空 → 1c47a4；非空 →
 *   old_head->prev(+0x18) = elem；elem->next(+0x14) = old_head；layer+0x58 = elem；
 *   elem->prev(+0x18) = 0（这里复用 r3 当零值 —— 本分支上 r3 恒为 0，正是第 4 实参）。
 *   ⇒ 两条插入路径的差别只有「改 +0x58 还是 +0x5c」和「接 next 还是 prev」这两对写点。
 */

/* @0x1c4570 ldr r2, [r1, #0x58] */
/* @0x1c4574 ldr r0, [r1, #0x60] */
/* @0x1c4578 cmp r2, #0 */
/* @0x1c457c add r0, r0, #1 */
/* @0x1c4580 str r0, [r1, #0x60] */
/* @0x1c4584 beq 0x1c47a4 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x288> */
/* @0x1c4588 ldr r0, [sp, #0x4] */
/* @0x1c458c str r0, [r2, #0x18] */
/* @0x1c4590 ldr r2, [r1, #0x58] */
/* @0x1c4594 str r2, [r0, #0x14] */
/* @0x1c4598 str r0, [r1, #0x58] */
/* @0x1c459c str r3, [r0, #0x18] */

/* ── ④ 写属层 + 负载因子门（1c45a0..1c45b8）──────────────────────────────
 *   r3 = room+0xfc（表 2 已用数）、r2 = room+0x104（表 2 阈值）；
 *   **elem+0x10 = layer**（1c45b0）——属层字段，无论走扩容还是直接插都先写；
 *   r7 = elem+0x04（uid，后面当键；扩容路径不碰 r7，所以 1c45c0 还能接着用）；
 *   `cmp r3,r2` + `bgt 1c46b0` ⇒ 已用数 > 阈值 → 先扩容（⑨），否则直接插（⑤）。
 *   ⚠ 判的是「插入前的已用数」是否**大于**阈值，等于不算超；阈值 = (int)(0.6 * 容量)（见 ⑨）。
 */

/* @0x1c45a0 ldr r3, [r8, #0xfc] */
/* @0x1c45a4 ldr r2, [r8, #0x104] */
/* @0x1c45a8 ldr r0, [sp, #0x4] */
/* @0x1c45ac cmp r3, r2 */
/* @0x1c45b0 str r1, [r0, #0x10] */
/* @0x1c45b4 ldr r7, [r0, #0x4] */
/* @0x1c45b8 bgt 0x1c46b0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x194> */

/* ── ⑤ 计数 +1、算哈希、探测准备（1c45bc..1c45f8）────────────────────────
 *   r3 = 已用数 + 1 写回（1c45c0 / 1c45c4 —— 扩容路径 1c47a0 也跳回这里，两条路共用这一条 +1）；
 *   r0 = uid → CHashMapCalculateHash（0x1b6e44 = `add r0,r0,#1`）→ 再清符号位 ⇒ 哈希 = (uid+1) & 0x7fffffff；
 *   r4 = 掩码(+0x100)、r10 = 桶基址(+0x108)、r3 = 槽下标 = 哈希 & 掩码、r2 = 桶基址 + 12*下标；
 *   桶项 +0x08（哈希）== 0 → 空桶，跳 1c468c 直接落位（⑧）；
 *   否则 r11 = 容量(+0xf8)、r5 = 0（「必须超过的距离门槛」初值）、r9 = elem，进 ⑥ 的探测。
 *   ⚠ 空桶判据是**哈希字段为 0**，不是键为 0；配合「h = key+1」⇒ 只有 key = -1 才哈希 0（池态专有）。
 */

/* @0x1c45bc add r3, r3, #1 */
/* @0x1c45c0 mov r0, r7 */
/* @0x1c45c4 str r3, [r8, #0xfc] */
/* @0x1c45c8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c45cc ldr r4, [r8, #0x100] */
/* @0x1c45d0 ldr r10, [r8, #0x108] */
/* @0x1c45d4 bic r0, r0, #-2147483648 */
/* @0x1c45d8 and r3, r0, r4 */
/* @0x1c45dc add r2, r3, r3, lsl #1 */
/* @0x1c45e0 add r2, r10, r2, lsl #2 */
/* @0x1c45e4 ldr r1, [r2, #0x8] */
/* @0x1c45e8 cmp r1, #0 */
/* @0x1c45ec beq 0x1c468c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x170> */
/* @0x1c45f0 ldr r11, [r8, #0xf8] */
/* @0x1c45f4 mov r5, #0 */
/* @0x1c45f8 ldr r9, [sp, #0x4] */
/* @0x1c45fc b 0x1c4640 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x124> */

/* ── ⑥ 线性探测 + Robin-Hood 换位（1c4600..1c4664）───────────────────────
 *   先算槽位距离：dist = ((capacity + idx) - (slot_hash & mask)) & mask
 *     ⇒ 即 (idx - home) mod capacity，home = 该条目的哈希 & 掩码。
 *   三种走法（1c4650..1c4664）：
 *     dist < 门槛(r5) → **抢位**（1c4600）：把槽里的 {哈希, 键, 值} 换进我们的寄存器、
 *                       把我们的三元组写进该槽，然后 idx+1、门槛 = dist+1，继续往后找空位搬运；
 *     dist > 门槛     → 不抢（movne / bne 1c4620），门槛保持不变，继续下一步；
 *     dist == 门槛    → 这时才比内容：先比哈希（1c4660），不等也继续；相等再到 ⑦ 比键。
 *   ⇒ 标准 Robin-Hood：**先按距离决定抢不抢，距离相同才比内容**。与删除侧的「回移压缩」是同一张
 *     开放寻址表的两种维护动作（§2 ⑨⑩）。
 *   ⚠ 槽空（桶项 +0x08 == 0）在 1c4638/1c463c 判，命中就带搬运中的三元组落到 1c4690（⑧）。
 *   ⚠ 本循环没有「探测次数超过容量」的保险：0.6 的负载因子保证必有空槽（④ 的门）。
 */

/* @0x1c4600 ldr r6, [r2] */
/* @0x1c4604 ldr r5, [r2, #0x4] */
/* @0x1c4608 str r0, [r2, #0x8] */
/* @0x1c460c mov r0, r1 */
/* @0x1c4610 str r7, [r2] */
/* @0x1c4614 mov r7, r6 */
/* @0x1c4618 str r9, [r2, #0x4] */
/* @0x1c461c mov r9, r5 */
/* @0x1c4620 add r3, r3, #1 */
/* @0x1c4624 add r5, r12, #1 */
/* @0x1c4628 and r3, r3, r4 */
/* @0x1c462c add r2, r3, r3, lsl #1 */
/* @0x1c4630 add r2, r10, r2, lsl #2 */
/* @0x1c4634 ldr r1, [r2, #0x8] */
/* @0x1c4638 cmp r1, #0 */
/* @0x1c463c beq 0x1c4690 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x174> */
/* @0x1c4640 add r12, r11, r3 */
/* @0x1c4644 and r6, r1, r4 */
/* @0x1c4648 rsb r12, r6, r12 */
/* @0x1c464c and r12, r12, r4 */
/* @0x1c4650 cmp r12, r5 */
/* @0x1c4654 blt 0x1c4600 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0xe4> */
/* @0x1c4658 movne r12, r5 */
/* @0x1c465c bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */
/* @0x1c4660 cmp r1, r0 */
/* @0x1c4664 bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */

/* ── ⑦ 同键覆盖（1c4668..1c4688）─────────────────────────────────────────
 *   哈希相等（⑥ 末尾）且键相等（1c4668 ldr r5,[r2] / 1c466c cmp r7,r5）⇒ **覆盖**：
 *     stm r2,{r7,r9}（键 = uid、值 = elem）、哈希原样回写、已用数 -1（抵掉 ⑤ 的 +1，净增 0）、
 *     跳到 1c4698 做 type 检查。
 *   ⇒ 表 2 的语义是 map（uid 唯一），不是多重集合；同一元素重复插入幂等，不会长链。
 *   ⚠ 覆盖路径**不释放**旧值指针；正常调用序里同一个 uid 不会有两个元素，但「谁保证」本卡不证。
 */

/* @0x1c4668 ldr r5, [r2] */
/* @0x1c466c cmp r7, r5 */
/* @0x1c4670 bne 0x1c4620 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x104> */
/* @0x1c4674 ldr r3, [r8, #0xfc] */
/* @0x1c4678 stm r2, {r7, r9} */
/* @0x1c467c sub r3, r3, #1 */
/* @0x1c4680 str r1, [r2, #0x8] */
/* @0x1c4684 str r3, [r8, #0xfc] */
/* @0x1c4688 b 0x1c4698 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x17c> */

/* ── ⑧ 落位（1c468c..1c4694）+ type 检查与正常出口（1c4698..1c46ac）──────
 *   落位两处入口：空桶（1c468c 先补 r9 = elem）与「搬运到空槽」（从 1c463c 来，三元组已在
 *   r7/r9/r0）；都走 stm r2,{r7,r9} + 写哈希。
 *   然后 r3 = elem->type(+0x00)；== 2 → 跳 1c47c0（⑪ 插表 3）；否则 add sp,#12 + pop 九寄存器返回。
 *   ⇒ 表 3 只索引实例元素：键 elem+0x1c 只有 type 2 有意义 —— 与 LayerRemove §1 ⑤「只在 type 2 上
 *     删表 3」严格对称。
 */

/* @0x1c468c ldr r9, [sp, #0x4] */
/* @0x1c4690 stm r2, {r7, r9} */
/* @0x1c4694 str r0, [r2, #0x8] */
/* @0x1c4698 ldr r0, [sp, #0x4] */
/* @0x1c469c ldr r3, [r0] */
/* @0x1c46a0 cmp r3, #2 */
/* @0x1c46a4 beq 0x1c47c0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x2a4> */
/* @0x1c46a8 add sp, sp, #12 */
/* @0x1c46ac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── ⑨ 表 2 扩容重建（1c46b0..1c47a0）────────────────────────────────────
 *   ① oldcap = room+0xf8；newcap = oldcap << 1；掩码 = newcap - 1（1c46b0..1c46d8）。
 *   ② 分配字节数：r4 = (newcap + 4*oldcap) << 2。因 newcap = 2*oldcap ⇒ 4*(2+4)*oldcap = 24*oldcap
 *      = 12*newcap —— **就是 12 B/项的桶数组**（编译器的强度削减写法，别读成「多算了 16*oldcap」）。
 *      Alloc(字节, "jni/../jni/yoyo/../../../Platform/MemoryManager.h", 70, true)（1c46e4）。
 *   ③ 新桶挂上 +0x108、memset 清 0（1c46f0/1c46f4）、已用数清 0（1c4708）、
 *      阈值 = (int)((float)newcap * 0.6f)（1c470c..1c471c；0.6f 的池字是 1c47d8 = 0x3f19999a）。
 *   ④ 再把新桶每个槽的哈希字段清一遍（1c4724..1c473c，memset 之后冗余，形状是 for 循环）。
 *   ⑤ oldcap > 0 时：按 12 B 步长扫旧桶，逐项（哈希 > 0 的）调
 *      CHashMap<int,CLayerElementBase*,7>::Insert 重插（1c4754..1c4778），然后 Free 旧桶
 *      （1c477c / 1c4780）。
 *   ⑥ 再按容量重算一次阈值（1c4784..1c479c，同一个 0.6f 池字），跳回 1c45bc 做本次插入。
 *   ⚠ 阈值写两次（1c471c 与 1c479c）、算式相同：中间夹着重插与 Free ⇒ 重插期间 Insert 0x1c384c
 *     可能自己改 +0x104，所以结尾重算落定。Insert 内部是否改阈值，本卡未逐条读（open）。
 *   ⚠ 首插不会进这条路：容量 0 时阈值 0、已用数 0，`0 > 0` 不成立 ⇒ 表的初始容量由房间构造期铺好，
 *     本函数只用不建（谁铺的 → open）。
 *   ⚠ vldr s13,[r8,#248] 是把 +0xf8 的**整数位型**当 s32 读（VFP 只搬位），vcvt.f32.s32 才解释它。
 */

/* @0x1c46b0 ldr r9, [r8, #0xf8] */
/* @0x1c46b4 mov r3, #1 */
/* @0x1c46b8 ldr r1, [pc, #0x11c] */
/* @0x1c46bc mov r2, #70 */
/* @0x1c46c0 ldr r6, [r8, #0x108] */
/* @0x1c46c4 lsl r0, r9, r3 */
/* @0x1c46c8 add r1, pc, r1 */
/* @0x1c46cc add r4, r0, r9, lsl #2 */
/* @0x1c46d0 str r0, [r8, #0xf8] */
/* @0x1c46d4 sub r0, r0, #1 */
/* @0x1c46d8 str r0, [r8, #0x100] */
/* @0x1c46dc lsl r4, r4, #2 */
/* @0x1c46e0 mov r0, r4 */
/* @0x1c46e4 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c46e8 mov r2, r4 */
/* @0x1c46ec mov r1, #0 */
/* @0x1c46f0 str r0, [r8, #0x108] */
/* @0x1c46f4 bl 0xb65b0 <memset@plt> */
/* @0x1c46f8 ldr r2, [r8, #0xf8] */
/* @0x1c46fc vldr s15, [pc, #212] */
/* @0x1c4700 mov r1, #0 */
/* @0x1c4704 cmp r2, r1 */
/* @0x1c4708 str r1, [r8, #0xfc] */
/* @0x1c470c vmov s13, r2 */
/* @0x1c4710 vcvt.f32.s32 s14, s13 */
/* @0x1c4714 vmul.f32 s15, s14, s15 */
/* @0x1c4718 vcvt.s32.f32 s15, s15 */
/* @0x1c471c vstr s15, [r8, #260] */
/* @0x1c4720 ble 0x1c4740 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x224> */
/* @0x1c4724 add r2, r2, r2, lsl #1 */
/* @0x1c4728 ldr r3, [r8, #0x108] */
/* @0x1c472c add r2, r3, r2, lsl #2 */
/* @0x1c4730 str r1, [r3, #0x8] */
/* @0x1c4734 add r3, r3, #12 */
/* @0x1c4738 cmp r3, r2 */
/* @0x1c473c bne 0x1c4730 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x214> */
/* @0x1c4740 cmp r9, #0 */
/* @0x1c4744 addgt r10, r8, #248 */
/* @0x1c4748 movgt r4, r6 */
/* @0x1c474c movgt r5, #0 */
/* @0x1c4750 ble 0x1c477c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x260> */
/* @0x1c4754 ldr r3, [r4, #0x8] */
/* @0x1c4758 mov r0, r10 */
/* @0x1c475c add r5, r5, #1 */
/* @0x1c4760 cmp r3, #0 */
/* @0x1c4764 ble 0x1c4770 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x254> */
/* @0x1c4768 ldm r4, {r1, r2} */
/* @0x1c476c bl 0x1c384c <_ZN8CHashMapIiP17CLayerElementBaseLi7EE6InsertEiS1_> */
/* @0x1c4770 cmp r5, r9 */
/* @0x1c4774 add r4, r4, #12 */
/* @0x1c4778 bne 0x1c4754 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x238> */
/* @0x1c477c mov r0, r6 */
/* @0x1c4780 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1c4784 vldr s13, [r8, #248] */
/* @0x1c4788 vcvt.f32.s32 s14, s13 */
/* @0x1c478c vldr s15, [pc, #68] */
/* @0x1c4790 ldr r3, [r8, #0xfc] */
/* @0x1c4794 vmul.f32 s15, s14, s15 */
/* @0x1c4798 vcvt.s32.f32 s15, s15 */
/* @0x1c479c vstr s15, [r8, #260] */
/* @0x1c47a0 b 0x1c45bc <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0xa0> */

/* ── ⑩ 空链分支（1c47a4..1c47bc，地址在函数尾部）────────────────────────
 *   layer+0x5c = elem、layer+0x58 = elem、elem+0x18 = 0、elem+0x14 = 0，跳回 1c45a0 继续。
 *   ⇒ 头插与尾插在空链上收敛到同一条路径（计数已在 ②/③ 加过）；这也是「单元素链上头尾指针相等」
 *     的唯一写点。写的是 r1（layer），不是 r8（room）——两个寄存器在这里不能混。
 */

/* @0x1c47a4 ldr r0, [sp, #0x4] */
/* @0x1c47a8 mov r3, #0 */
/* @0x1c47ac str r0, [r1, #0x5c] */
/* @0x1c47b0 str r0, [r1, #0x58] */
/* @0x1c47b4 str r3, [r0, #0x18] */
/* @0x1c47b8 str r3, [r0, #0x14] */
/* @0x1c47bc b 0x1c45a0 <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb+0x84> */

/* ── ⑪ type 2 的尾声：尾调表 3 Insert（1c47c0..1c47d4）──────────────────
 *   r0 = room+0x110（表 3 簇对象）、r1 = elem+0x1c（实例 id）、r2 = elem；
 *   先 add sp,#12 + pop（含 lr），再 `b 0x1c3eb4` = CHashMap<int,CLayerInstanceElement*,7>::Insert。
 *   ⇒ 尾调后本函数不再回到自己的帧；表 3 的扩容/覆盖规则在 Insert 里（本卡不证）。
 *   ⇒ 表 2 是「本函数自己算 + 自己扩容」，表 3 是「整包甩给 Insert」——两条路的维护方式不对称。
 */

/* @0x1c47c0 ldr r2, [sp, #0x4] */
/* @0x1c47c4 add r0, r8, #272 */
/* @0x1c47c8 ldr r1, [r2, #0x1c] */
/* @0x1c47cc add sp, sp, #12 */
/* @0x1c47d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c47d4 b 0x1c3eb4 <_ZN8CHashMapIiP21CLayerInstanceElementLi7EE6InsertEiS1_> */

/* 池字（非指令）：0x3f19999a = 0.6f，供 1c46fc / 1c478c 两处 vldr 共用 */

/* @0x1c47d8 svclo #0x19999a */

/* 池字（非指令）：0x0016c968，供 1c46b8 的 ldr r1,[pc,#0x11c] 取 Alloc 的 file 串（1c46c8 add r1,pc,r1 → 0x331038）*/

/* @0x1c47dc andseq r12, r6, r8, ror #18 */

/* ── open（本节）─────────────────────────────────────────────────────────
 *   · 表 2 的初始容量/首建：本函数只做「满了翻倍」；容量为 0 时既不扩容也无法落位 ⇒ 必由房间构造期
 *     铺好。谁铺的（CRoom ctor / CLayerManager::Build）本卡未核。
 *   · CHashMap<int,CLayerElementBase*,7>::Insert 0x1c384c（1640 B）内部：重插时是否改 +0x104、
 *     自己是否也会扩容、值指针是否被复制 —— 未读。
 *   · 覆盖路径（⑦）留下的旧值指针没有释放点；正常调用序里同一个 uid 不会有两个元素，谁保证未证。
 *   · 第 4 实参在 7 个 DuplicateRoomLayers 调用点各传什么，未逐点核；它与 AddNewElement 的
 *     「建运行期数据」是否恒同向，也未证。
 *   · 桶项哈希字段被当作空槽哨兵（== 0），而 key = -1 的哈希正好是 0；活元素不用 -1 当 uid，
 *     所以只是潜在坑，未实测。
 */

/* ══ §2 CLayerManager::RemoveStorageInstanceFromLayer 0x1b9ea4 ═══════════
 * @func 0x1b9ea4 0x1ba3b8 size 1300  325 行（322 指令 + 3 池字 1ba3ac / 1ba3b0 / 1ba3b4）
 * 级别: 正文（322/322。三道门 / 表 3 查元素 / 属层校验与诊断串 / 表 2 删 / 表 3 删 / 摘链回池 /
 *       缓存清 0 / 动态层自删 / 两段回移压缩的入口与终止条件全部钉住；
 *       未钉：回移压缩的逐位同簇判定、三处恒不跳的编译残迹的源语言形态）
 * 符号: _ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri
 *       → void CLayerManager::RemoveStorageInstanceFromLayer(CRoom* room, CLayer* layer, int instId)
 * 调用者（全 .text 1 处）：F_LayerAddInstance 0x1c6cf4 的 1c6dbc
 * 同层: RemoveInstanceFromLayer 0x1b991c（同一池、同一摘链协议，但要 CInstance*）、
 *       RemoveInstanceElement 0x1b7ac4（bDestroy 版）、RemoveElement 0x1b8fdc（通用路）、
 *       RemoveLayer 0x1b95d8（⑪ 的尾跳目标）、GetElementFromID 0x1bc2a0（+0x10c 缓存）、
 *       GetNewInstanceElement 0x1c0cdc、AddNewElement 0x1c5ff0、dbg_csol（槽 0x3ed71c）、
 *       m_InstanceElementPool 0x542678
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   「按实例 id 把一个层元素摘下来」：只用一个 int id 在表 3 里找到元素 → 校验它确实属于这一层 →
 *   删表 2、删表 3 → 摘链、元素回 36 B 实例池 → 清 GetElementFromID 缓存 → 动态层空了就把层删掉。
 *   **整个函数不碰任何 CInstance 字段**（根本没有 CInstance 实参），也不要求实例带「已归层」标志。
 *
 * ── 唯一调用者与「存储实例」的真身（本题重点 2）──────────────────────────
 *   F_LayerAddInstance（GML `layer_add_instance`，0x1c6cf4）的搬层路径：
 *     · 1c6d98 GetLayerIDForInstance(room, id)（0x1b8cb8）→ 实例当前所在层 id；
 *     · 返回 -1（不在任何层上）→ 直接跳过删除；
 *     · 否则 GetLayerFromID(room, 旧层 id)（1c6dac → 0x1b8868）→ 本函数(room, 旧层, id)（1c6dbc）；
 *     · 然后 GetNewInstanceElement() → `elem+0x1c = id` → AddNewElement(room, 新层, elem, 0)
 *       （1c6dc0..1c6ddc，第 4 实参 0 ⇒ 走 §1 的头插）。
 *   ⇒ `layer_add_instance` 的「搬层」是**删旧元素 + 造新元素**，不是复用旧元素 ⇒ 本函数必须把旧元素
 *     完整回池，否则每次搬层漏一个 36 B。
 *   ⇒ 造出来的新元素只写了 +0x1c（实例 id），**+0x20（CInstance*）保持工厂初值 0** ⇒ 这类元素是
 *     「只存 id 的存储元素」，也就解释了函数名里的 Storage：它没有回指 CInstance 的指针。
 *     与 AddInstanceToLayer 造的「活元素」（+0x20 = CInstance*）是同一个 36 B 类、同一个 type 2，
 *     区别只在 +0x20 是否有值。
 *   ⚠ 与 RemoveInstanceFromLayer 的分工（两条路终态逐项相同，见 §2 末表）：
 *       RemoveInstanceFromLayer(room, layer, CInstance*)
 *         · 门：inst != 0 **且 inst+0x174 != 0**（要求「已归层」）；
 *         · 键来源：inst+0x78；
 *         · 收尾多写 inst+0x174 = 0、inst+0x170 = -1。
 *       本函数(room, layer, int id)
 *         · 门：id != -1，**不要求任何实例状态**；
 *         · 键来源：实参；
 *         · 收尾不碰 CInstance（没有实例可碰）。
 *   ⇒ 同一个语义的两种入口：有实例对象走前者，只有 id 走后者。这与 AddInstanceToLayer 的第三道门
 *     （+0x174 != 0 就返回）正好互补：那边只管没归层的，这边只管「不需要实例」的。
 *   ⚠ 推论（未证）：既然 +0x20 可以是 0，DrawLayerInstanceElement 0x1b1600 之类必须能只靠 +0x1c
 *     的 id 找到实例；本卡未读它。
 */

/* ── ① 三道门（1b9ea4..1b9ec8）───────────────────────────────────────────
 *   room == 0 → 返回；layer == 0 → 返回；**id == -1 → 返回**（`cmn r2,#1`）。
 *   ⇒ 比 RemoveInstanceFromLayer 少一道门（那边还要求 inst+0x174 != 0），多一道「id 哨兵」门。
 *     -1 在这里是「没有实例」的哨兵 —— 与池态元素的 +0x1c = -1、AddInstanceToLayer 的 +0x174 门同源。
 *   push 九寄存器 + 20 B 栈（[sp] 存 elem、[sp+4..+0x14] 给两段回移压缩临时用）。
 */

/* @0x1b9ea4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9ea8 subs r4, r0, #0 */
/* @0x1b9eac sub sp, sp, #20 */
/* @0x1b9eb0 mov r11, r1 */
/* @0x1b9eb4 mov r9, r2 */
/* @0x1b9eb8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9ebc cmp r1, #0 */
/* @0x1b9ec0 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9ec4 cmn r2, #1 */
/* @0x1b9ec8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */

/* ── ② 按 id 查表 3（1b9ecc..1b9f20）─────────────────────────────────────
 *   哈希 = CHashMapCalculateHash(id)（= id+1）→ 清符号位；簇 = room+0x110：
 *     掩码 +0x118、桶 +0x120、已用 +0x114；槽下标 = 哈希 & 掩码，桶项 = 桶 + 12*下标。
 *   空桶（+0x08 == 0）→ 直接返回（①的公共出口）；哈希相等 → 跳 1b9f78（⑤ 命中落地）；
 *   否则算这一槽的距离 dist = ((capacity + idx) - (slot_hash & mask)) & mask，垫进探测循环。
 *   ⚠ 1b9f14 的 `tst r1,r12 / bmi` 是**恒不跳**的（r12 是掩码，不含 bit31）——编译残迹，
 *     真正起作用的是 ③ 里「探测次数超过槽的距离」那条退出。
 *   ⚠ 命中只比 31 位哈希，不重比桶项 +0x00 的键，也不校验 elem+0x1c == id；因 h = key+1 在 31 位内
 *     单射，这与「比键」等价（见卡头）。
 */

/* @0x1b9ecc mov r0, r2 */
/* @0x1b9ed0 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9ed4 ldr r12, [r4, #0x118] */
/* @0x1b9ed8 ldr r8, [r4, #0x120] */
/* @0x1b9edc bic r0, r0, #-2147483648 */
/* @0x1b9ee0 and r3, r0, r12 */
/* @0x1b9ee4 lsl r6, r3, #1 */
/* @0x1b9ee8 add r2, r6, r3 */
/* @0x1b9eec add r2, r8, r2, lsl #2 */
/* @0x1b9ef0 ldr r1, [r2, #0x8] */
/* @0x1b9ef4 cmp r1, #0 */
/* @0x1b9ef8 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9efc cmp r0, r1 */
/* @0x1b9f00 beq 0x1b9f78 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xd4> */
/* @0x1b9f04 ldr r2, [r4, #0x110] */
/* @0x1b9f08 and r1, r12, r1 */
/* @0x1b9f0c add r5, r2, r3 */
/* @0x1b9f10 rsb r1, r1, r5 */
/* @0x1b9f14 tst r1, r12 */
/* @0x1b9f18 bmi 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f1c mov r5, #0 */
/* @0x1b9f20 b 0x1b9f34 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x90> */

/* ── ③ 探测循环（1b9f24..1b9f64）+ 公共出口（1b9f68..1b9f6c）────────────
 *   r5 = 已走步数，r7 = 当前槽的探测距离（当作「还能走多远」的门槛）：
 *     哈希相等 → 1b9f70（⑤）；距离 < 步数 → 放弃，返回（键不在表里）；
 *     否则 idx+1（回卷 &掩码）、步数 +1、取下一槽哈希与距离；下一槽空 → 返回；占用 → 回到比较。
 *   ⇒ 与 §1 ⑥ 的插入探测同构，但目的相反：插入要抢位，删除只要能证明「不在表里」就提前收手。
 *   ⇒ 公共出口只有 add sp,#20 + pop（②③④⑪ 的四个返回点全部汇到这里或尾跳出去）。
 */

/* @0x1b9f24 cmp r0, r1 */
/* @0x1b9f28 beq 0x1b9f70 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xcc> */
/* @0x1b9f2c cmp r7, r5 */
/* @0x1b9f30 blt 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f34 add r3, r3, #1 */
/* @0x1b9f38 add r5, r5, #1 */
/* @0x1b9f3c and r3, r12, r3 */
/* @0x1b9f40 add r10, r2, r3 */
/* @0x1b9f44 lsl r6, r3, #1 */
/* @0x1b9f48 add r1, r6, r3 */
/* @0x1b9f4c add r1, r8, r1, lsl #2 */
/* @0x1b9f50 ldr r1, [r1, #0x8] */
/* @0x1b9f54 and r7, r12, r1 */
/* @0x1b9f58 cmp r1, #0 */
/* @0x1b9f5c rsb r7, r7, r10 */
/* @0x1b9f60 and r7, r7, r12 */
/* @0x1b9f64 bne 0x1b9f24 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x80> */
/* @0x1b9f68 add sp, sp, #20 */
/* @0x1b9f6c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── ④ 命中落地 + 四道判空 + 属层比较（1b9f70..1b9fa8）──────────────────
 *   1b9f70 `cmn r3,#1 / beq 返回`（idx == -1 的哨兵检查，**恒不跳**：idx 是掩码内的下标）；
 *   1b9f78 重新算 &桶项[下标]，1b9f80 `cmn r8,#4 / beq 返回`（&桶项 == -4 的空指针塌缩检查，
 *     同样恒不跳 —— 与 LayerRemove §3 的 1b9a08 是同一段编译产物）；
 *   1b9f88 取桶项 +0x04 = elem，判空 → 返回；存 [sp]（后面全程用这份）；
 *   1b9f98 elem+0x10（属层）== 0 → 返回（元素已不在任何层上，不该在这张表里）；
 *   1b9fa4 elem+0x10 == layer → 跳 1b9fdc（⑦ 删表 2）；不等 → ⑤ 的诊断。
 *   ⇒ **本函数对元素做了三层一致性校验**（elem 非空 / 属层非空 / 属层相符），而 RemoveInstanceFromLayer
 *     只做前两层：因为这里的 key 是外部传进来的裸 id，比 +0x174 的信任链更弱。
 */

/* @0x1b9f70 cmn r3, #1 */
/* @0x1b9f74 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f78 add r3, r6, r3 */
/* @0x1b9f7c add r8, r8, r3, lsl #2 */
/* @0x1b9f80 cmn r8, #4 */
/* @0x1b9f84 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f88 ldr r8, [r8, #0x4] */
/* @0x1b9f8c cmp r8, #0 */
/* @0x1b9f90 str r8, [sp] */
/* @0x1b9f94 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9f98 ldr r3, [r8, #0x10] */
/* @0x1b9f9c cmp r3, #0 */
/* @0x1b9fa0 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1b9fa4 cmp r11, r3 */
/* @0x1b9fa8 beq 0x1b9fdc <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x138> */

/* ── ⑤ 属层不符 → 诊断后原样返回（1b9fac..1b9fd8）──────────────────────
 *   宿主 = 槽 0x3ed71c → 0x3eb70c = dbg_csol（值 0x47a118，.bss，无文件内容）；
 *   `ldr r12,[宿主]; ldr r12,[r12,#0xc]; blx r12` = 调 vtable 槽 3，三个实参：
 *     r1 = 串 0x34d6d0 = "Layer system integrity compromised, instance %d not on layer %d\n"
 *     r2 = id（r9，就是实参）   r3 = layer+0x00（层 id）
 *   然后 add sp/pop 返回 —— **不删表、不摘链、不改字段**（fail-soft，不是 assert）。
 *   ⚠ 与 AddInstanceToLayer 的报错槽 0x3ed718（宿主 0x479a94）只差 4 B：两个不同的全局宿主，别混。
 *   ⚠ 串 0x34d6d0 与 LayerRemove §3 用的是**同一条**（那里 r2 = inst+0x78）；这里 r2 是裸 id，
 *     说明两者的 id 域相同（CInstance+0x78 == 表 3 的键 == 本函数的第 3 实参）。
 */

/* @0x1b9fac ldr r0, [pc, #0x3f8] */
/* @0x1b9fb0 mov r2, r9 */
/* @0x1b9fb4 ldr r1, [pc, #0x3f4] */
/* @0x1b9fb8 ldr r0, [pc, r0] */
/* @0x1b9fbc ldr r3, [r11] */
/* @0x1b9fc0 add r1, pc, r1 */
/* @0x1b9fc4 ldr r0, [r0] */
/* @0x1b9fc8 ldr r12, [r0] */
/* @0x1b9fcc ldr r12, [r12, #0xc] */
/* @0x1b9fd0 blx r12 */
/* @0x1b9fd4 add sp, sp, #20 */
/* @0x1b9fd8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── ⑥ 表 2 摘桶：键 elem+0x04（1b9fdc..1ba078）─────────────────────────
 *   哈希 = CHashMapCalculateHash(elem+0x04) → 簇 = room+0xf8（掩码 +0x100 / 桶 +0x108 / 已用 +0xfc）；
 *   空桶 → 跳 1ba07c（⑦ 继续删表 3，**不中断**）；哈希相等 → 跳 1ba210（⑫ 回移压缩）；
 *   否则按「距离 < 步数」提前收手（1ba040..1ba044），收手也跳 1ba07c。
 *   ⇒ 删表 2 失败**不阻止**后续删表 3 与摘链：这是一条「尽力而为」的清理路径，与 RemoveElement 的
 *     三态汇合（LayerRemove §1 ②）同一风格。
 */

/* @0x1b9fdc ldr r1, [sp] */
/* @0x1b9fe0 ldr r0, [r1, #0x4] */
/* @0x1b9fe4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9fe8 ldr r2, [r4, #0x100] */
/* @0x1b9fec ldr r12, [r4, #0x108] */
/* @0x1b9ff0 bic r0, r0, #-2147483648 */
/* @0x1b9ff4 and r3, r0, r2 */
/* @0x1b9ff8 lsl r1, r3, #1 */
/* @0x1b9ffc add lr, r1, r3 */
/* @0x1ba000 add lr, r12, lr, lsl #2 */
/* @0x1ba004 ldr lr, [lr, #0x8] */
/* @0x1ba008 cmp lr, #0 */
/* @0x1ba00c beq 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba010 cmp r0, lr */
/* @0x1ba014 beq 0x1ba210 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x36c> */
/* @0x1ba018 ldr r8, [r4, #0xf8] */
/* @0x1ba01c and lr, r2, lr */
/* @0x1ba020 add r1, r3, r8 */
/* @0x1ba024 rsb r1, lr, r1 */
/* @0x1ba028 tst r1, r2 */
/* @0x1ba02c bmi 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba030 mov r5, #0 */
/* @0x1ba034 b 0x1ba048 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1a4> */
/* @0x1ba038 cmp r0, lr */
/* @0x1ba03c beq 0x1ba208 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x364> */
/* @0x1ba040 cmp r6, r5 */
/* @0x1ba044 blt 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba048 add r3, r3, #1 */
/* @0x1ba04c add r5, r5, #1 */
/* @0x1ba050 and r3, r2, r3 */
/* @0x1ba054 add r7, r3, r8 */
/* @0x1ba058 lsl r1, r3, #1 */
/* @0x1ba05c add lr, r1, r3 */
/* @0x1ba060 add lr, r12, lr, lsl #2 */
/* @0x1ba064 ldr lr, [lr, #0x8] */
/* @0x1ba068 and r6, r2, lr */
/* @0x1ba06c cmp lr, #0 */
/* @0x1ba070 rsb r6, r6, r7 */
/* @0x1ba074 and r6, r6, r2 */
/* @0x1ba078 bne 0x1ba038 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x194> */

/* ── ⑦ 表 3 摘桶：键 elem+0x1c（1ba07c..1ba118）─────────────────────────
 *   哈希 = CHashMapCalculateHash(elem+0x1c) → 簇 = room+0x110（掩码 +0x118 / 桶 +0x120 / 已用 +0x114）；
 *   空桶或提前收手 → 跳 1ba11c（⑧ 摘链回池）；哈希相等 → 跳 1ba2d4（⑬ 回移压缩）。
 *   ⚠ ② 已经用**实参 id** 在这张表上命中过一次，⑦ 是「用元素自己记的 id 再删一次」——两次的键来源
 *     不同（② 用 id，⑦ 用 elem+0x1c）。两者不等时 ② 就找不到，也就到不了这里；所以正常路径上
 *     ⑦ 必然命中。代码不校验这点，只靠写方（§1 ⑪ / AddInstanceToLayer / F_LayerAddInstance）保证。
 *   ⚠ 1ba0b0..1ba0cc 与 1ba050..1ba078 是同一条探测的第八个副本（本函数共 4 段探测，每段各带一份
 *     回移压缩的落地块）。
 */

/* @0x1ba07c ldr r2, [sp] */
/* @0x1ba080 ldr r0, [r2, #0x1c] */
/* @0x1ba084 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1ba088 ldr r2, [r4, #0x118] */
/* @0x1ba08c ldr r12, [r4, #0x120] */
/* @0x1ba090 bic r0, r0, #-2147483648 */
/* @0x1ba094 and r3, r0, r2 */
/* @0x1ba098 lsl r1, r3, #1 */
/* @0x1ba09c add r5, r1, r3 */
/* @0x1ba0a0 add r5, r12, r5, lsl #2 */
/* @0x1ba0a4 ldr r5, [r5, #0x8] */
/* @0x1ba0a8 cmp r5, #0 */
/* @0x1ba0ac beq 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0b0 cmp r0, r5 */
/* @0x1ba0b4 beq 0x1ba2d4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x430> */
/* @0x1ba0b8 ldr r8, [r4, #0x110] */
/* @0x1ba0bc and r5, r2, r5 */
/* @0x1ba0c0 add r1, r8, r3 */
/* @0x1ba0c4 rsb r1, r5, r1 */
/* @0x1ba0c8 tst r1, r2 */
/* @0x1ba0cc bmi 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0d0 mov r6, #0 */
/* @0x1ba0d4 b 0x1ba0e8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x244> */
/* @0x1ba0d8 cmp r0, r5 */
/* @0x1ba0dc beq 0x1ba2cc <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x428> */
/* @0x1ba0e0 cmp r7, r6 */
/* @0x1ba0e4 blt 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba0e8 add r3, r3, #1 */
/* @0x1ba0ec add r6, r6, #1 */
/* @0x1ba0f0 and r3, r2, r3 */
/* @0x1ba0f4 add r9, r8, r3 */
/* @0x1ba0f8 lsl r1, r3, #1 */
/* @0x1ba0fc add r5, r1, r3 */
/* @0x1ba100 add r5, r12, r5, lsl #2 */
/* @0x1ba104 ldr r5, [r5, #0x8] */
/* @0x1ba108 and r7, r2, r5 */
/* @0x1ba10c cmp r5, #0 */
/* @0x1ba110 rsb r7, r7, r9 */
/* @0x1ba114 and r7, r7, r2 */
/* @0x1ba118 bne 0x1ba0d8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x234> */

/* ── ⑧ 摘链 + 回 36 B 元素池 + 字段复位（1ba11c..1ba1c4）────────────────
 *   摘链（五条写点，与 §3 ② 及 RemoveInstanceElement 逐条同构）：
 *     prev = +0x18、next = +0x14；prev ? prev->next = next : layer+0x58 = next；
 *     next ? next->prev = prev : layer+0x5c = prev；layer+0x60 = 计数 -1。
 *   字段复位（顺序即机器码顺序）：+0x0c = 0、+0x10 = 0（属层）、+0x00 = 2（type）、
 *     +0x08 = 0（字节）、+0x04 = -1（uid）、+0x14 = 0、+0x18 = 0、+0x20 = 0、+0x1c = -1。
 *   回池（m_InstanceElementPool，槽 0x3f086c → 0x542678）：可用数(+0x08)+1；头非空 →
 *     旧头->prev(+0x18) = elem、池头 = elem、elem->next(+0x14) = 旧头、elem->prev(+0x18) = 0；
 *     池空 → 池尾(+0x04) = elem、池头 = elem。
 *   ⇒ 复位后的九个字段与 GetNewInstanceElement 1c0d30..1c0d44 的初值逐一相同（见卡头 C 条）。
 *   ⇒ **没有 bDestroy**：不调 DoInstanceDestroy；也**不调 CleanElementRuntimeData**（通用路是
 *     RemoveElement 1b90c0 调的）。⇒ 走这条路的元素回池时仍可能带着运行期数据；+0x20 已被清 0，
 *     其它运行期字段原样（是否有第二处清理，见 open）。
 */

/* @0x1ba11c ldr r10, [sp] */
/* @0x1ba120 mvn r0, #0 */
/* @0x1ba124 ldr r6, [sp] */
/* @0x1ba128 mov r5, #2 */
/* @0x1ba12c ldr r3, [r10, #0x18] */
/* @0x1ba130 cmp r3, #0 */
/* @0x1ba134 ldrne r1, [sp] */
/* @0x1ba138 ldreq r2, [r10, #0x14] */
/* @0x1ba13c ldrne r2, [r1, #0x14] */
/* @0x1ba140 streq r2, [r11, #0x58] */
/* @0x1ba144 strne r2, [r3, #0x14] */
/* @0x1ba148 ldrne r3, [r1, #0x18] */
/* @0x1ba14c ldrne r2, [r1, #0x14] */
/* @0x1ba150 ldr r1, [r11, #0x60] */
/* @0x1ba154 cmp r2, #0 */
/* @0x1ba158 streq r3, [r11, #0x5c] */
/* @0x1ba15c strne r3, [r2, #0x18] */
/* @0x1ba160 add r1, r1, r0 */
/* @0x1ba164 ldr r2, [pc, #0x248] */
/* @0x1ba168 mov r3, #0 */
/* @0x1ba16c str r1, [r11, #0x60] */
/* @0x1ba170 ldr r2, [pc, r2] */
/* @0x1ba174 str r3, [r6, #0xc] */
/* @0x1ba178 str r3, [r6, #0x10] */
/* @0x1ba17c ldr r1, [r2] */
/* @0x1ba180 ldr r12, [r2, #0x8] */
/* @0x1ba184 cmp r1, r3 */
/* @0x1ba188 str r5, [r6] */
/* @0x1ba18c strb r3, [r6, #0x8] */
/* @0x1ba190 add r12, r12, #1 */
/* @0x1ba194 ldrne r8, [sp] */
/* @0x1ba198 str r0, [r6, #0x4] */
/* @0x1ba19c str r3, [r6, #0x14] */
/* @0x1ba1a0 str r3, [r6, #0x18] */
/* @0x1ba1a4 str r3, [r6, #0x20] */
/* @0x1ba1a8 str r0, [r6, #0x1c] */
/* @0x1ba1ac streq r6, [r2, #0x4] */
/* @0x1ba1b0 strne r8, [r1, #0x18] */
/* @0x1ba1b4 streq r6, [r2] */
/* @0x1ba1b8 strne r8, [r2] */
/* @0x1ba1bc strne r1, [r8, #0x14] */
/* @0x1ba1c0 str r12, [r2, #0x8] */
/* @0x1ba1c4 strne r3, [r8, #0x18] */

/* ── ⑨ 清 GetElementFromID 的单条缓存（1ba1c8..1ba1d8）──────────────────
 *   if (room+0x10c == elem) room+0x10c = 0 —— 与 RemoveElement（LayerRemove §1 ③）、
 *   RemoveInstanceFromLayer（1b9c40/1b9c54）同一处。
 *   ⇒ 三条移除路径都把这条缓存当作「最后一个碰过的元素」，摘掉时必须失效，否则 GetElementFromID 会
 *     返回已回池的对象。
 */

/* @0x1ba1c8 ldr r3, [r4, #0x10c] */
/* @0x1ba1cc ldr r10, [sp] */
/* @0x1ba1d0 cmp r10, r3 */
/* @0x1ba1d4 moveq r3, #0 */
/* @0x1ba1d8 streq r3, [r4, #0x10c] */

/* ── ⑩ 动态层自删（1ba1dc..1ba204）───────────────────────────────────────
 *   if (layer+0x19 != 0 && layer+0x60 == 0) → 先 add sp/pop，再 `b 0x1b95d8`：
 *   RemoveLayer(room, layer+0x00, r2 = -1)（r2 是 1ba120 的 `mvn r0,#0` 关系链外残留，见注解）。
 *   ⇒ 「动态层（+0x19）的最后一个元素离开时，层自己消失」。与 RemoveInstanceFromLayer 的
 *     1b9c58..1b9c80、四实参重载 RemoveElement 0x1c013c 是同一策略；第 3 实参三处都是 0
 *     （本处 = 刚减到 0 的层计数；RemoveInstanceFromLayer 1b9c64 也是层计数；0x1c013c 是常量 0），
 *     而 RemoveLayer 根本不读它（LayerRemove §2 已证）。
 *   ⚠ 第 3 实参是**顺手的层计数**，不是常量：1ba1e8 的 `ldr r2,[r11,#0x60]` 把「刚在 ⑧ 减到 0 的
 *     层元素计数」装进 r2，1ba1f4..1ba204 之间再没改写 r2 ⇒ 传进去的是 0。
 *     对照 RemoveInstanceFromLayer 的 1b9c64 `ldr r2,[r10,#0x60]`（同样在减到 0 之后）⇒ 两处都是 0；
 *     四实参重载 0x1c013c 传的是常量 0。三个调用点数值全等，但没有一个在表达语义 ——
 *     这正是 RemoveLayer 不读第 3 实参（LayerRemove §2）的旁证。
 *   ⚠ 勘误：LayerRemove 卡 §3 写「传的是 -1」，那来自 1b9c4c 的 `mvn r2,#0`；它被 1b9c64 覆盖。
 *     本卡按机器码记为 0。
 */

/* @0x1ba1dc ldrb r3, [r11, #0x19] */
/* @0x1ba1e0 cmp r3, #0 */
/* @0x1ba1e4 beq 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1ba1e8 ldr r2, [r11, #0x60] */
/* @0x1ba1ec cmp r2, #0 */
/* @0x1ba1f0 bne 0x1b9f68 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0xc4> */
/* @0x1ba1f4 mov r0, r4 */
/* @0x1ba1f8 ldr r1, [r11] */
/* @0x1ba1fc add sp, sp, #20 */
/* @0x1ba200 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ba204 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */

/* ── ⑪ 表 2 回移压缩：命中后的落地块（1ba208..1ba2c8）───────────────────
 *   入口两种：⑥ 的哈希命中直接跳 1ba210；⑥ 的探测在「idx == -1」时跳 1ba208（哨兵检查后跳过表 2）。
 *   算法（与 RemoveElement / RemoveInstanceFromLayer 的内联副本同构）：
 *     hole = idx；从 idx+1 起逐槽看下一项：
 *       空槽（哈希 == 0）         → 停，hole 保持当前值；
 *       探测距离 == 0（本就在 home）→ 停；
 *       否则把该槽的 {哈希, 键, 值} 三字段搬到前一槽，hole 前移一格，继续。
 *     收尾：把 hole 槽的哈希清 0、room+0xfc（已用数）-1，跳回 1ba07c 继续删表 3。
 *   ⇒ **开放寻址 + 回移压缩**（不是墓碑标记）；「同簇」的判据就是「探测距离非 0」，本卡只证到这一层，
 *     逐位推导未还原（与 LayerRemove §1 ② 同一处 open）。
 *   ⚠ 搬运期间借用 [sp+4]/[sp+8]/[sp+0xc]/[sp+0x10] 保存 r4/r11/r10，收尾再 ldmib 取回。
 */

/* @0x1ba208 cmn r3, #1 */
/* @0x1ba20c beq 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */
/* @0x1ba210 add r6, r3, #1 */
/* @0x1ba214 and r6, r6, r2 */
/* @0x1ba218 add r5, r6, r6, lsl #1 */
/* @0x1ba21c add r5, r12, r5, lsl #2 */
/* @0x1ba220 ldr lr, [r5, #0x8] */
/* @0x1ba224 cmp lr, #0 */
/* @0x1ba228 beq 0x1ba3a4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x500> */
/* @0x1ba22c ldr r8, [r4, #0xf8] */
/* @0x1ba230 and r0, r2, lr */
/* @0x1ba234 add r7, r6, r8 */
/* @0x1ba238 rsb r0, r0, r7 */
/* @0x1ba23c tst r0, r2 */
/* @0x1ba240 beq 0x1ba3a4 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x500> */
/* @0x1ba244 stmib sp, {r4, r11} */
/* @0x1ba248 mov r11, r8 */
/* @0x1ba24c b 0x1ba25c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x3b8> */
/* @0x1ba250 tst r9, r2 */
/* @0x1ba254 beq 0x1ba2a8 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x404> */
/* @0x1ba258 mov r6, r0 */
/* @0x1ba25c add r7, r1, r3 */
/* @0x1ba260 add r0, r6, #1 */
/* @0x1ba264 and r0, r0, r2 */
/* @0x1ba268 ldr r8, [r5, #0x4] */
/* @0x1ba26c add r4, r12, r7, lsl #2 */
/* @0x1ba270 add r9, r0, r11 */
/* @0x1ba274 add r10, r0, r0, lsl #1 */
/* @0x1ba278 mov r3, r6 */
/* @0x1ba27c str lr, [r4, #0x8] */
/* @0x1ba280 lsl r1, r6, #1 */
/* @0x1ba284 ldr r5, [r5] */
/* @0x1ba288 str r5, [r12, r7, lsl #2] */
/* @0x1ba28c add r5, r12, r10, lsl #2 */
/* @0x1ba290 ldr lr, [r5, #0x8] */
/* @0x1ba294 str r8, [r4, #0x4] */
/* @0x1ba298 cmp lr, #0 */
/* @0x1ba29c and r7, r2, lr */
/* @0x1ba2a0 rsb r9, r7, r9 */
/* @0x1ba2a4 bne 0x1ba250 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x3ac> */
/* @0x1ba2a8 ldmib sp, {r4, r11} */
/* @0x1ba2ac add r6, r6, r6, lsl #1 */
/* @0x1ba2b0 ldr r3, [r4, #0xfc] */
/* @0x1ba2b4 mov r2, #0 */
/* @0x1ba2b8 add r12, r12, r6, lsl #2 */
/* @0x1ba2bc sub r3, r3, #1 */
/* @0x1ba2c0 str r2, [r12, #0x8] */
/* @0x1ba2c4 str r3, [r4, #0xfc] */
/* @0x1ba2c8 b 0x1ba07c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x1d8> */

/* ── ⑫ 表 3 回移压缩：命中后的落地块（1ba2cc..1ba398）───────────────────
 *   与 ⑪ 逐条同构，只换了簇：起始槽来自 ⑦ 的命中，收尾清的是 room+0x114（表 3 已用数）-1，
 *   然后跳回 1ba11c（⑧ 摘链回池）。
 *   ⚠ 这一段把 r4/r11/r10 存在 [sp+8]/[sp+0xc]/[sp+0x10]，与 ⑪ 用 [sp+4..0x10] 的偏移不同 ——
 *     因为 [sp] 一直存着 elem，两段都不能覆盖它。
 */

/* @0x1ba2cc cmn r3, #1 */
/* @0x1ba2d0 beq 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */
/* @0x1ba2d4 add r0, r3, #1 */
/* @0x1ba2d8 and r9, r0, r2 */
/* @0x1ba2dc add r6, r9, r9, lsl #1 */
/* @0x1ba2e0 add r6, r12, r6, lsl #2 */
/* @0x1ba2e4 ldr r5, [r6, #0x8] */
/* @0x1ba2e8 cmp r5, #0 */
/* @0x1ba2ec beq 0x1ba39c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4f8> */
/* @0x1ba2f0 ldr r8, [r4, #0x110] */
/* @0x1ba2f4 and r0, r2, r5 */
/* @0x1ba2f8 add r7, r9, r8 */
/* @0x1ba2fc rsb r0, r0, r7 */
/* @0x1ba300 str r8, [sp, #0x4] */
/* @0x1ba304 tst r0, r2 */
/* @0x1ba308 strne r4, [sp, #0x8] */
/* @0x1ba30c strne r11, [sp, #0xc] */
/* @0x1ba310 bne 0x1ba324 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x480> */
/* @0x1ba314 b 0x1ba39c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4f8> */
/* @0x1ba318 tst r10, r2 */
/* @0x1ba31c beq 0x1ba374 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4d0> */
/* @0x1ba320 mov r9, r0 */
/* @0x1ba324 add r7, r1, r3 */
/* @0x1ba328 add r0, r9, #1 */
/* @0x1ba32c and r0, r0, r2 */
/* @0x1ba330 ldr r11, [sp, #0x4] */
/* @0x1ba334 add r4, r12, r7, lsl #2 */
/* @0x1ba338 ldr r8, [r6, #0x4] */
/* @0x1ba33c add r10, r0, r11 */
/* @0x1ba340 add r11, r0, r0, lsl #1 */
/* @0x1ba344 str r5, [r4, #0x8] */
/* @0x1ba348 mov r3, r9 */
/* @0x1ba34c ldr r6, [r6] */
/* @0x1ba350 lsl r1, r9, #1 */
/* @0x1ba354 str r6, [r12, r7, lsl #2] */
/* @0x1ba358 add r6, r12, r11, lsl #2 */
/* @0x1ba35c ldr r5, [r6, #0x8] */
/* @0x1ba360 str r8, [r4, #0x4] */
/* @0x1ba364 cmp r5, #0 */
/* @0x1ba368 and r7, r2, r5 */
/* @0x1ba36c rsb r10, r7, r10 */
/* @0x1ba370 bne 0x1ba318 <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x474> */
/* @0x1ba374 ldr r4, [sp, #0x8] */
/* @0x1ba378 ldr r11, [sp, #0xc] */
/* @0x1ba37c add r1, r9, r9, lsl #1 */
/* @0x1ba380 ldr r3, [r4, #0x114] */
/* @0x1ba384 mov r2, #0 */
/* @0x1ba388 add r12, r12, r1, lsl #2 */
/* @0x1ba38c sub r3, r3, #1 */
/* @0x1ba390 str r2, [r12, #0x8] */
/* @0x1ba394 str r3, [r4, #0x114] */
/* @0x1ba398 b 0x1ba11c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x278> */

/* ── ⑬ 两个「洞就停在当前槽」的汇合点（1ba39c..1ba3a8）──────────────────
 *   1ba39c（表 3 用）与 1ba3a4（表 2 用）都做 `hole = 当前 idx` 然后跳进各自的收尾段：
 *   前者 b 1ba37c（清 +0x114），后者 b 1ba2ac（清 +0xfc）。
 *   ⇒ 这两条就是「下一槽为空 / 下一槽本就在 home」时不移位的出口，也是回移压缩的最小终止条件。
 */

/* @0x1ba39c mov r9, r3 */
/* @0x1ba3a0 b 0x1ba37c <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x4d8> */
/* @0x1ba3a4 mov r6, r3 */
/* @0x1ba3a8 b 0x1ba2ac <_ZN13CLayerManager30RemoveStorageInstanceFromLayerEP5CRoomP6CLayeri+0x408> */

/* 池字（非指令）：0x0023375c → GOT 0x3ed71c = dbg_csol（供 1b9fb8 的 ldr r0,[pc,r0]）*/

/* @0x1ba3ac eoreq r3, r3, r12, asr r7 */

/* 池字（非指令）：0x00193708 → 串 0x34d6d0（供 1b9fc0 的 add r1,pc,r1）*/

/* @0x1ba3b0 andseq r3, r9, r8, lsl #14 */

/* 池字（非指令）：0x002366f4 → GOT 0x3f086c = m_InstanceElementPool（供 1ba170 的 ldr r2,[pc,r2]）*/

/* @0x1ba3b4 .word 0x002366f4 */

/* ── 移除 vs 添加：字段终值对照表（本题重点 1）────────────────────────────
 *   字段                 Add 侧终值（§1 + 调用方）          Remove 侧终值（本节）
 *   elem+0x00 type       调用方写（实例 = 2）               2
 *   elem+0x04 uid        调用方写（计数器 0x5425f0++）      -1
 *   elem+0x08 在用位      调用方写（活 = 1）                0
 *   elem+0x0c            0（本节不写）                      0
 *   elem+0x10 属层        **§1 ④ 写 layer**                 0
 *   elem+0x14/+0x18      进层链（头插/尾插由 bTail 定）      清 0 后当池自由链
 *   elem+0x1c 实例 id     调用方写                          -1
 *   elem+0x20 CInstance*  调用方写（存储元素保持 0）         0
 *   表 2（键 uid）        **§1 插**                         **本节删**
 *   表 3（键实例 id）      **§1 ⑪ 插（仅 type 2）**          **本节删**
 *   层链计数 +0x60        §1 ②③ +1                        ⑧ -1
 *   动态层自删             —                                ⑩（+0x19 && 计数 == 0）
 *   ⇒ 唯一非对称：Add 侧由**调用方**写 type/uid/+0x08/+0x1c/+0x20，Remove 侧由**本节**把它们打回池初值；
 *     §1 只写 +0x10 与链指针。⇒ 「谁写谁清」在两侧不是同一批函数，这是本卡最容易读错的地方。
 */

/* ── open（本节）─────────────────────────────────────────────────────────
 *   · dbg_csol 的 vtable 槽 3 方法名：宿主对象在 .bss（0x47a118 无文件内容），静态拿不到 vtable 指针；
 *     只能证「走 vtable+0xc、3 个实参（串 + 两个 %d）」。
 *   · 本节不调 CleanElementRuntimeData：回池元素带着运行期数据是否有害、有没有第二处清理，未证。
 *   · 两段回移压缩只证到「遇空槽或距离 0 停 / 逐槽搬三字段 / 末槽哈希清 0 / 已用数 -1」，
 *     逐位的同簇判定未还原（与 LayerRemove §1 ② 同一处 open）。
 *   · layer+0x19 的正式名（LayerHelpers 卡叫「动态层筛子」）、谁把它置 1，未在本卡核。
 *   · 三处恒不跳的编译残迹（1b9f14 tst/bmi、1b9f70 cmn r3,#1、1b9f80 cmn r8,#4）的源语言形态未还原。
 *   · 1ba1dc 段的第 3 实参来源已追到 1ba1e8（层计数，此处恒 0）；但「计数在其它状态下的取值」不证 ——
 *     反正 RemoveLayer 不读它（LayerRemove §2）。
 */

/* ══ §3 CLayerManager::RemoveOldTilemapElement 0x1b7bac ══════════════════
 * @func 0x1b7bac 0x1b7cf8 size 332  83 行（82 指令 + 1 池字 1b7cf4）
 * 级别: 正文（82/82。自有负载释放（+0x1c 与 +0x24/+0x30 两段）/ 摘链 / 计数 / 52 B 池回池与字段复位
 *       全部钉住；未钉：+0x24 所指对象的类型名、+0x30 三个取值的语义名、默认分支为何只走链不释放）
 * 符号: _ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement
 *       → void CLayerManager::RemoveOldTilemapElement(CLayer* layer, CLayerOldTilemapElement* elem)
 * 调用者（全 .text 0 处直呼）：只由 RemoveElement 0x1b8fdc 的 type 3 跳表项（1b90e4 → 1b92a4，
 *       再 `b 0x1b7bac`）尾跳进来 —— 本函数没有第二个入口
 * 同层: GetNewOldTilemapElement 0x1c0de4（同一 52 B 池的工厂：Alloc(52, …, "Room_Layers.h", 63, 1)）、
 *       ~ObjectPool<CLayerOldTilemapElement> 0x1b6c8c（同一段元素析构，见 1b6d04..1b6e28）、
 *       CleanOldTilemapElementRuntimeData 0x1b8e0c、BuildOldTilemapElementRuntimeData 0x1ba514、
 *       MemoryManager::Free 0x27c2d0、operator delete 0x27d1d0、m_OldTilemapElementPool 0x542664
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   旧式 tilemap 元素的「析构 + 回池」：先无条件 Free(elem+0x1c)，再按 elem+0x30 的种类释放 elem+0x24
 *   所指的负载（1 → operator delete，2/3 → MemoryManager::Free，各沿 +0x704 链逐个走），
 *   然后摘链、计数 -1、把元素按出厂初值复位后头插回 52 B 池。
 *   **没有 room 实参 ⇒ 不删表 2/表 3、不碰 room+0x10c 缓存、不做动态层自删。**
 *
 * ── 为什么它是特例（本题重点 3）──────────────────────────────────────────
 *   1) 七个族回收器里**唯一在摘链之前释放自有负载**的（① 的 `bl Free(elem+0x1c)` 在 ② 摘链之前）。
 *      其余六个（RemoveBackgroundElement 0x1b7a04 / RemoveInstanceElement 0x1b7ac4 /
 *      RemoveSpriteElement 0x1b7cf8 / RemoveTilemapElement 0x1b7dcc / RemoveParticleElement 0x1b7ec0 /
 *      RemoveTileElement 0x1b7f64）本卡未逐个读；LayerRemove 卡只抽检了 type 1 / type 7 的摘链五条
 *      写点，那两处没有 Free 调用。⇒ 这里的「唯一」只说「三节里唯一」，对另外六个保持未证。
 *   2) 七个族回收器里**唯一没有 room 实参**的（签名只有 layer + elem）。⇒ 元素销号（删表）与元素回收
 *      在编译期就被拆开了：表 2 的删除只能由 RemoveElement 完成，本函数物理上做不到。
 *   3) +0x1c 的语义与实例元素相反：实例元素 +0x1c 是「实例 id（整数键）」，本类 +0x1c 是「堆指针」。
 *      同一个偏移、两种语义，因为族回收器逐类编译（见卡头字段地图）。
 *
 * ── ① 入口 + 无条件 Free(elem+0x1c)（1b7bac..1b7bbc）─────────────────────
 *   push {r4,r5,r6,lr}；r4 = elem、r5 = layer；`ldr r0,[elem,#0x1c]` → MemoryManager::Free 0x27c2d0。
 *   ⚠ **不判空**（其它地方 Free 前都判）：要么 +0x1c 恒非空，要么 Free(NULL) 安全。本卡不证哪一种。
 *   ⚠ r0/r1 到这一步已被覆盖（r0 = 负载指针），room 从头到尾没进过本函数。
 */

/* @0x1b7bac push {r4, r5, r6, lr} */
/* @0x1b7bb0 mov r4, r1 */
/* @0x1b7bb4 mov r5, r0 */
/* @0x1b7bb8 ldr r0, [r1, #0x1c] */
/* @0x1b7bbc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── ② 摘链（1b7bc0..1b7be4）─────────────────────────────────────────────
 *   prev = elem+0x18、next = elem+0x14；
 *   prev ? prev->next(+0x14) = next : layer+0x58 = next；
 *   next ? next->prev(+0x18) = prev : layer+0x5c = prev。
 *   ⇒ 与 §2 ⑧、RemoveInstanceElement、RemoveElement 的族回收段逐条同构：**五个写点、两处条件清头尾**。
 *     这是全库统一的元素链摘除协议，改一处就要同时改七处。
 *   ⚠ 摘链在负载释放**之后**：如果 Free 触发回调/异常，链上会留一个已释放负载的元素。
 *     本卡的证据只能说明顺序，不能说明这是有意为之（open）。
 */

/* @0x1b7bc0 ldr r3, [r4, #0x18] */
/* @0x1b7bc4 ldr r2, [r4, #0x14] */
/* @0x1b7bc8 cmp r3, #0 */
/* @0x1b7bcc strne r2, [r3, #0x14] */
/* @0x1b7bd0 ldrne r2, [r4, #0x14] */
/* @0x1b7bd4 ldrne r3, [r4, #0x18] */
/* @0x1b7bd8 streq r2, [r5, #0x58] */
/* @0x1b7bdc cmp r2, #0 */
/* @0x1b7be0 streq r3, [r5, #0x5c] */
/* @0x1b7be4 strne r3, [r2, #0x18] */

/* ── ③ 计数 -1 + 负载种类门（1b7be8..1b7bfc）─────────────────────────────
 *   r3 = elem+0x30（负载种类）；r2 = layer+0x60（计数）- 1 → 写回；
 *   r3 == 0 → 跳 1b7c34（⑤ 直接回池）：**种类 0 = 没有第二段负载**。
 *   ⇒ 计数递减无条件（在种类判定之前），所以任何分支都不会漏减。
 *   ⚠ 计数在摘链之后减：② 已经改过头尾指针，③ 才改计数 —— 与 §1 ②③「先加计数再改链」相反的顺序，
 *     但两者都在同一帧内完成，外部看不到中间态。
 */

/* @0x1b7be8 ldr r3, [r4, #0x30] */
/* @0x1b7bec ldr r2, [r5, #0x60] */
/* @0x1b7bf0 cmp r3, #0 */
/* @0x1b7bf4 sub r2, r2, #1 */
/* @0x1b7bf8 str r2, [r5, #0x60] */
/* @0x1b7bfc beq 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */

/* ── ④ 负载释放三档（1b7c00..1b7c30）─────────────────────────────────────
 *   r0 = elem+0x24（负载对象）；== 0 → 跳 1b7c34（⑤）。
 *   否则按 r3 = elem+0x30 分派：
 *     2 → 1b7cac（⑥ `while (p) { next = p->[0x704]; Free(p); p = next; }`）
 *     3 → 1b7cc4（同上，也是 Free）
 *     1 → 1b7cdc（⑦ 同上，但用 operator delete 0x27d1d0）
 *     其它 → 1b7c24 的**只走链不释放**循环（r0 = r0->[0x704] 直到 0，一个字节都不放）
 *   ⇒ 1/2/3 的语义是「负载当初怎么分配的」：1 = new/delete 家族，2/3 = MemoryManager 家族。
 *     这套约定与 ObjectPool<T> 的 +0x0c 完全一致（1b6cc4..1b6d28 同一三段分派）；
 *     ~ObjectPool<CLayerOldTilemapElement> 1b6c8c 在 1b6d04..1b6e28 有一份**逐条相同**的代码
 *     （同一串 `ldr r3,[e,#0x30]` / `ldr r0,[e,#0x24]` / +0x704 链 / 1:delete、2:Free、3:Free），
 *     所以 1b7c00..1b7c30 是 CLayerOldTilemapElement 的元素析构被内联进本函数 —— 依据是逐条比对，
 *     不是符号名。
 *   ⇒ 负载对象的**块链在 +0x704**，与 ObjectPool<T> 的块链同构（1b6d34 的循环）⇒ 它自己也是一个池/分配器。
 *   ⚠ 默认分支（种类 ∉ {0,1,2,3}）只遍历不释放，是 switch 的 default 空壳；正常数据下不该出现（open）。
 */

/* @0x1b7c00 ldr r0, [r4, #0x24] */
/* @0x1b7c04 cmp r0, #0 */
/* @0x1b7c08 beq 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7c0c cmp r3, #2 */
/* @0x1b7c10 beq 0x1b7cac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x100> */
/* @0x1b7c14 cmp r3, #3 */
/* @0x1b7c18 beq 0x1b7cc4 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x118> */
/* @0x1b7c1c cmp r3, #1 */
/* @0x1b7c20 beq 0x1b7cdc <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x130> */
/* @0x1b7c24 ldr r5, [r0, #0x704] */
/* @0x1b7c28 cmp r5, #0 */
/* @0x1b7c2c mov r0, r5 */
/* @0x1b7c30 bne 0x1b7c24 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x78> */

/* ── ⑤ 回 52 B 池 + 字段复位（1b7c34..1b7ca8）────────────────────────────
 *   池 = m_OldTilemapElementPool（池字 1b7cf4 → GOT 0x3f0870 → 0x542664）。
 *   复位（顺序即机器码顺序）：+0x08 = 0（字节）、+0x14 = 0、+0x18 = 0、+0x00 = 3（type）、
 *     +0x04 = -1（uid）、+0x2c = 0、+0x28 = 0、+0x24 = 0、+0x0c = 0、+0x10 = 0（属层）、
 *     +0x1c = 0、+0x20 = 0、**+0x30 = 1**（种类默认值，不是 0 —— 与工厂一致）。
 *   回池：可用数(+0x08)+1；头非空 → 旧头->prev(+0x18) = elem、池头 = elem、elem->next(+0x14) = 旧头、
 *     elem->prev(+0x18) = 0；池空 → 池尾(+0x04) = elem、池头 = elem。
 *   ⇒ 这 13 个写点与 GetNewOldTilemapElement 1c0e3c..1c0e6c 的 13 个写点**逐字段相同**
 *     （连 +0x04 = -1 与 +0x30 = 1 都一样，只有写入顺序不同）⇒ 「回池 = 回到出厂状态」。
 *   ⚠ +0x30 = 1 而种类 1 是「operator delete 家族」：即池里的备用元素默认按 new/delete 记账，
 *     复用时由调用方重写这个字段。
 */

/* @0x1b7c34 ldr r2, [pc, #0xb8] */
/* @0x1b7c38 mov r3, #0 */
/* @0x1b7c3c mov r12, #1 */
/* @0x1b7c40 strb r3, [r4, #0x8] */
/* @0x1b7c44 ldr r2, [pc, r2] */
/* @0x1b7c48 str r3, [r4, #0x14] */
/* @0x1b7c4c str r3, [r4, #0x18] */
/* @0x1b7c50 mvn r6, #0 */
/* @0x1b7c54 ldr r1, [r2] */
/* @0x1b7c58 mov r5, #3 */
/* @0x1b7c5c ldr r0, [r2, #0x8] */
/* @0x1b7c60 cmp r1, r3 */
/* @0x1b7c64 stm r4, {r5, r6} */
/* @0x1b7c68 str r3, [r4, #0x2c] */
/* @0x1b7c6c add r0, r0, r12 */
/* @0x1b7c70 str r3, [r4, #0x28] */
/* @0x1b7c74 str r3, [r4, #0x24] */
/* @0x1b7c78 str r3, [r4, #0xc] */
/* @0x1b7c7c str r3, [r4, #0x10] */
/* @0x1b7c80 str r3, [r4, #0x1c] */
/* @0x1b7c84 str r3, [r4, #0x20] */
/* @0x1b7c88 str r12, [r4, #0x30] */
/* @0x1b7c8c str r0, [r2, #0x8] */
/* @0x1b7c90 strne r4, [r1, #0x18] */
/* @0x1b7c94 strne r4, [r2] */
/* @0x1b7c98 strne r1, [r4, #0x14] */
/* @0x1b7c9c strne r3, [r4, #0x18] */
/* @0x1b7ca0 streq r4, [r2, #0x4] */
/* @0x1b7ca4 streq r4, [r2] */
/* @0x1b7ca8 pop {r4, r5, r6, pc} */

/* ── ⑥ 种类 2/3 的逐项释放循环（1b7cac..1b7cd8）──────────────────────────
 *   `next = p->[0x704]; Free(p); if (!next) break; p = next;`  —— 先 Free 头、再前进，
 *   与 ④ 的默认分支（只前进不 Free）正好配对：一个释放、一个仅遍历。
 *   收尾 `b 1b7c34`（⑤ 回池）。两个入口（1b7cac 来自种类 2、1b7cc4 来自种类 3）的循环体逐条同形，
 *   动作完全相同（都调 MemoryManager::Free）⇒ 2 与 3 在**释放动作上不可区分**，差别只在记账语义。
 */

/* @0x1b7cac ldr r5, [r0, #0x704] */
/* @0x1b7cb0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7cb4 cmp r5, #0 */
/* @0x1b7cb8 mov r0, r5 */
/* @0x1b7cbc bne 0x1b7cac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x100> */
/* @0x1b7cc0 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */
/* @0x1b7cc4 ldr r5, [r0, #0x704] */
/* @0x1b7cc8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b7ccc cmp r5, #0 */
/* @0x1b7cd0 mov r0, r5 */
/* @0x1b7cd4 bne 0x1b7cc4 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x118> */
/* @0x1b7cd8 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */

/* ── ⑦ 种类 1 的逐项 delete 循环（1b7cdc..1b7cf0）────────────────────────
 *   形状与 ⑥ 完全相同，只有被调用者换成 operator delete 0x27d1d0。
 *   ⇒ 同一条链在两个分配家族里走同一个偏移（+0x704）、同一个顺序（先释放头再前进）。
 */

/* @0x1b7cdc ldr r5, [r0, #0x704] */
/* @0x1b7ce0 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b7ce4 cmp r5, #0 */
/* @0x1b7ce8 mov r0, r5 */
/* @0x1b7cec bne 0x1b7cdc <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x130> */
/* @0x1b7cf0 b 0x1b7c34 <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement+0x88> */

/* 池字（非指令）：0x00238c24，供 1b7c34 的 ldr r2,[pc,#0xb8] 取相对偏移（1b7c44 add 后 → 0x3f0870）*/

/* @0x1b7cf4 eoreq r8, r3, r4, lsr #24 */

/* ── open（本节）─────────────────────────────────────────────────────────
 *   · elem+0x24 所指对象的类型名：只知道它自带一条 +0x704 块链、按 1/2/3 三档释放，
 *     与 ObjectPool<T> 的块链布局同构，具体类名未证。
 *   · elem+0x30 三个取值（1/2/3）的语义名未证；只证「1 走 operator delete、2/3 走 MemoryManager::Free」。
 *   · 默认分支（种类 ∉ {0,1,2,3}）只遍历不释放：是编译器 default 空壳还是「种类 4+ 由别人管」，
 *     未证；正常数据下种类只会是 1（池初值）或工厂/构造方写的值。
 *   · Free(elem+0x1c) 不判空就调：Free(NULL) 是否安全、或 +0x1c 是否恒非空，本卡不证。
 *   · 本函数不调 CleanOldTilemapElementRuntimeData 0x1b8e0c（它是 180 B 的独立函数）：
 *     运行期数据由谁清、清在 RemoveElement 之前还是之后，未证（CleanElementRuntimeData 0x1b8ed0
 *     按 type 分派到 Clean*ElementRuntimeData，本卡未读它的 type 3 分支）。
 *   · 摘链在负载释放之后（② 在 ① 之后），这个顺序是否有意，未证。
 */
