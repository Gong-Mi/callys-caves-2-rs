/* cally 逆向卡：CLayerManager::AddInstanceToLayer（原版 libyoyo.so，armv7）
 * @func 0x1c5a38 0x1c5d14 size 736  184 条（179 条指令 + 1c5d04..1c5d14 五个字面量池字）
 * 级别: 骨架（184/184 锚定。三道门、第三张哈希表的内联查找（哈希/桶/命中三态）、36 B 专用池的扩容与弹出、
 *             新元素的八个初值、实例三字段回写、两条入层路径（建新 vs 复用）、尾调 AddElementToLayer /
 *             UpdateInstanceActivation 全部逐条钉住。未钉：哈希表探测/换位的逐位规则（只证到「比较 31 位哈希 +
 *             按探测距离决定推进或插新」）、错误虚调用的宿主对象（槽 0x3ed718 → 0x479a94）叫什么、
 *             UpdateInstanceActivation 内部、元素 +0x08 字节的语义、
 *             「表 3 的表项指着已回池元素」这一状态是否可达（复用分支的合法输入域））
 * 符号: _ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance
 *       → CLayerManager::AddInstanceToLayer(CRoom*, CLayer*, CInstance*)
 * 同层: AddInstance 0x1c5d18（尾调进来）、AddElementToLayer 0x1c451c（尾调出去）、
 *       UpdateInstanceActivation 0x1b8a28（第二出口）、CHashMapCalculateHash 0x1b6e44、
 *       MemoryManager::Alloc 0x27ce78、GetNewInstanceElement 0x1c0ce4（同一个 36 B 池的另一工厂）、
 *       CHashMap<int,CLayerInstanceElement*,7>::Insert 0x1c3eb4（表 3 的写入口在 AddElementToLayer 里）、
 *       AddNewElement 0x1c5ff0（共用同一个元素 uid 计数器 0x5425f0）、
 *       RemoveInstanceFromLayer 0x1b991c / RemoveInstanceElement 0x1b7ac4（同一 36 B 池的回收侧）
 *       调用者（全仓 5 处）：CRoom::AddInstance(float,float,CLayer*,int) 0x1ab5d8、CRoom::Assign 0x1adfec、
 *       AddInstance 0x1c5d78、F_LayerAddInstance 0x1c6e78（GML 内建 layer_add_instance）、SV_Layer 0x1fc1d8
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把一个实例挂到**指定**层：过了三道门，先在「实例 id → 层元素」那张表里找现成的 CLayerInstanceElement——
 *   找到就只补指针与状态（不重插链、不重插表），没有就从 36 B 专用池造一个 type 2 元素并交给
 *   AddElementToLayer（那里才把它插进层元素链、表 2 和表 3），两种路都把实例的层 id / 已归层标志 / 深度写掉。
 *
 * ── 三道门（1c5a38..1c5a70）────────────────────────────────────
 *   layer == 0 || room == 0 → 返回；instance == 0 → 返回；instance+0x174 != 0 → 返回。
 *   ⚠ 机器码里先比 r1（layer）再 cmpne r0（room）；两者都非 0 才继续，所以门是「与非」关系。
 *   ⚠ 第三道门与 AddInstance 完全同源：**已经在层上的实例，本函数什么都不做**（幂等）。
 *     也正因为这道门，下面的「复用」分支只可能在「元素还在表里、但实例已被摘下来」时命中。
 *
 * ── 归层前先按实例 id 查一次表（本题重点 1）────────────────────
 *   哈希：CHashMapCalculateHash(instance+0x78) & 0x7fffffff（+0x78 = CInstance 的 id，见 CInstance ctor 卡）
 *   表：room+0x110 这一簇（每个簇 20 B：+0x00 容量、+0x04 已用、+0x08 掩码=容量-1、
 *       +0x0c 阈值=（int)(0.6*容量)、+0x10 桶指针）；本函数读的是 +0x118 掩码与 +0x120 桶，
 *       探测步长用的是 +0x110 容量（1c5aac）。
 *   桶项 12 B：{+0x00 键(int)、+0x04 值(指针)、+0x08 31 位哈希}（落位见 AddElementToLayer 的 1c4698 stm）。
 *   命中判定只比 +0x08 的哈希（1c5aa4 / 1c5c1c），命中后取值 +0x04。
 *   三种命中态：
 *     · 桶空（1c5a9c）或链上找不到 → 造新元素（1c5ac4）
 *     · 值非 0 且 elem+0x20 == 0 → **复用**（1c5cc0）
 *     · 值非 0 且 elem+0x20 != 0 → 虚调用报错 + 直接返回（1c5c94..1c5cbc）
 *       实参 r1 = 常量串 0x35285c，内容就是 " ERROR: Adding too many variables"；r2 = instance+0x78。
 *       宿主对象 = 槽 0x3ed718 → 0x479a94 的全局对象，走它的 vtable+0xc。⇒ 同一实例出现两个活元素时
 *       这里会报「变量太多」并原样退出，不改任何字段（fail-soft，不是 assert）。
 *   ⇒ 这张表就是「实例 id → 它的层元素」的唯一索引；**归层不会给同一实例造第二个元素**。
 *
 * ── 造新元素：36 B 专池（1c5ac4..1c5c18）───────────────────────
 *   池对象 = 全局 0x542678（槽 0x3f086c）。结构 {+0x00 链头, +0x04 链尾, +0x08 可用数, +0x10 容量}，
 *   +0x0c 空着 —— 与 DuplicateRoomLayers 卡的池协议同构。
 *   同池的六处访问点（全 .text GOT 槽扫描）：GetNewInstanceElement 0x1c0ce4（工厂）、本函数、
 *   BuildInstanceElementRuntimeData 0x1b8154、RemoveInstanceElement 0x1b7b50、
 *   RemoveInstanceFromLayer 0x1b9be8、RemoveStorageInstanceFromLayer 0x1ba170 —— 全是 CLayerInstanceElement
 *   的生命周期函数。⇒ 36 B 池**专供 CLayerInstanceElement**（type 2）；房间其它 6 类元素的池在
 *   DuplicateRoomLayers 卡描述的那个「以层池为基、负偏移取」的簇里，与这个不是同一组。
 *   扩容：可用数 == 0 时一次 Alloc(36, "…/Files/Room/Room_Layers.h", 63, 1) 造「容量」个、头插进自由链，
 *         再把容量翻倍（1c5b80 lsl r3,r3,#1）；容量 <= 0 时只翻倍不分配（1c5ae0）。
 *   初值：+0x00 = 2(type)、+0x04 = -1、+0x0c..+0x18 = 0、+0x1c = -1、+0x20 = 0（1c5b14..1c5b34）。
 *   弹出：链头出，摘链用 +0x14(next)/+0x18(prev) —— 同一对偏移在活对象上是元素链，在自由链上是池链。
 *   交付：+0x20 = instance、+0x04 = 计数器 0x5425f0 的旧值（随后 +1，首个元素得 0）、
 *         +0x1c = instance+0x78、+0x08 = 1。
 *   ⇒ 0x5425f0 是**全局元素 uid 计数器**，不只本函数在用：AddNewElement 0x1c6020 也在同一个槽上取旧值
 *     写进 elem+0x04 再 +1（1c6024..1c6030）。表 2 的键就是这个 uid。
 *
 * ── 实例三字段回写（两条路都做同一组写，本题重点 2）────────────
 *   instance+0x170 = layer+0x00（层 id）   instance+0x174 = 1（已归层）
 *   instance+0x180 = (float)layer+0x04（层深度）
 *   ⇒ **归层会覆盖实例自己的 depth**（+0x180 从对象 depth 改成层 depth）。AddInstance 的第二级正是靠
 *     +0x180 找动态层，所以这一步让「实例深度」与「层深度」在归层后对齐 —— 除非有人再改 +0x180，
 *     否则此后按 depth 反查只会落回同一层。
 *
 * ── 入层的两条路（差异是本题重点 3）────────────────────────────
 *   A. 新元素（1c5c10..1c5c18）：先 pop 掉本函数帧，再**尾调**
 *      AddElementToLayer(room, layer, elem, instance+0x69)。
 *      · 第 4 实参 = instance+0x69（1c5c00 ldrb；这一字节就是 CInstance::SetDeactivated 0x19230c 写的「停用」位）
 *        ⇒ 未停用 → false → AddElementToLayer 走**头插**（1c4570：新元素成为 layer+0x58 的新头）；
 *          已停用 → true  → 走**尾插**（1c4534：接到 layer+0x5c 的链尾）。
 *        ⇒ 同一层里的元素顺序按「是否停用」分流：停用的排在尾端（画在最后），未停用的排在最前。
 *      · AddElementToLayer 还会顺手做三件事：layer+0x60 计数 +1、把元素插进表 2（room+0xf8，键 = elem+0x04）、
 *        elem+0x00 == 2 时再插进表 3（room+0x110，键 = elem+0x1c = 实例 id）。
 *   B. 复用（1c5cc0..1c5cf0）：只写六个字段 —— elem+0x20 = instance、elem+0x08 = 1、
 *      instance+0x170 = 层 id、+0x174 = 1、+0x180 = (float)层 depth；随后
 *      instance+0x69 != 0 → 尾调 UpdateInstanceActivation(room, instance)（停用的实例要刷活跃表），
 *      否则直接返回。
 *      **不调 AddElementToLayer** ⇒ 不入层链、不入表 2、不插表 3，也不动 layer+0x58/+0x5c/+0x60。
 *   ⚠ 两条路的差别不是笔误：A 的元素是刚出池的新对象，必须靠 AddElementToLayer 入链入表；
 *     B 的元素仍被表 3 指着（+0x20 已被清成 0 的那个状态），再插一次会重链。
 *   ⚠ B 这条路的状态由谁制造，本卡未证。已知的邻居：RemoveInstanceFromLayer 0x1b991c 会把元素从
 *     layer+0x58 链上摘掉（1b9ba4..1b9bdc 改 +0x14/+0x18 与 +0x60 计数）、把元素压回 36 B 池
 *     （1b9be8..1b9c38）、并把 elem+0x1c 清成 -1、elem+0x20 清成 0、instance+0x170 清成 -1、
 *     instance+0x174 清成 0（1b9c18/1b9c1c/1b9c44/1b9c50）。它是否同时摘掉表 3 的桶未取证
 *     ⇒ 「表项指着已回池的元素」这种状态是否可达、B 分支是否会复活一个池对象，都记 open。
 *
 * ── 三张表各自是谁（跨卡交叉证，本题重点 4）────────────────────
 *   表 1 room+0xe4 簇：int 层 id → CLayer*          （InsertLayerIntoActiveList / GetLayerFromID 用）
 *   表 2 room+0xf8 簇：int 元素 uid(+0x04) → CLayerElementBase*（AddElementToLayer 写，本函数不直接碰）
 *   表 3 room+0x110 簇：int 实例 id(+0x78) → CLayerInstanceElement*（本函数查、AddElementToLayer 写）
 *   ⇒ DuplicateRoomLayers 卡里「表 2/3 只被重建、没有直接 Insert」的 open，答案在这里：
 *     它们的写入全部发生在 AddElementToLayer 里，而 DuplicateRoomLayers 每个元素都会调它。
 *
 * ── 返回值 ─────────────────────────────────────────────────────
 *   void。四条出口：三道门（1c5a6c 公共 pop）、报错虚调用后（1c5cb8）、复用后（1c5cec → 1c5a6c）、
 *   以及两条尾调（b 而不是 bl，本函数帧已先 pop）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 三道门 + 公共出口 ───────────────────────────────────────
 *   push {r4-r11,lr} + sub sp,#4（只为 8 字节对齐，无局部量）。
 *   r9 = room、r10 = layer、r8 = instance（此后 r0/r1/r2 全部改作他用）。
 *   1c5a54 的 beq 覆盖「layer 空或 room 空」；1c5a5c 覆盖 instance 空；
 *   1c5a68 的 beq 才放行 —— 注意它是 beq（+0x174 == 0 才继续），不是 bne。
 */

/* @0x1c5a38 cmp r1, #0 */
/* @0x1c5a3c cmpne r0, #0 */
/* @0x1c5a40 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5a44 mov r9, r0 */
/* @0x1c5a48 sub sp, sp, #4 */
/* @0x1c5a4c mov r10, r1 */
/* @0x1c5a50 mov r8, r2 */
/* @0x1c5a54 beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1c5a58 cmp r2, #0 */
/* @0x1c5a5c beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1c5a60 ldrb r5, [r2, #0x174] */
/* @0x1c5a64 cmp r5, #0 */
/* @0x1c5a68 beq 0x1c5a74 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x3c> */
/* @0x1c5a6c add sp, sp, #4 */
/* @0x1c5a70 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 表 3 查找：算哈希、定位首桶、取桶哈希 ───────────────────
 *   r0 = instance+0x78；哈希去符号位；桶索引 = 哈希 & 掩码(room+0x118)；桶项 12 B（r3*3*4）；
 *   1c5a98 取出的是桶项的 +0x08（31 位哈希 / 空槽时为 0）。桶空 → 1c5ac4 造新。
 */

/* @0x1c5a74 ldr r0, [r2, #0x78] */
/* @0x1c5a78 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1c5a7c ldr r4, [r9, #0x118] */
/* @0x1c5a80 ldr r1, [r9, #0x120] */
/* @0x1c5a84 bic r0, r0, #-2147483648 */
/* @0x1c5a88 and r3, r0, r4 */
/* @0x1c5a8c lsl r6, r3, #1 */
/* @0x1c5a90 add r2, r6, r3 */
/* @0x1c5a94 add r2, r1, r2, lsl #2 */
/* @0x1c5a98 ldr r2, [r2, #0x8] */
/* @0x1c5a9c cmp r2, #0 */
/* @0x1c5aa0 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5aa4 cmp r0, r2 */
/* @0x1c5aa8 beq 0x1c5c6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x234> */
/* @0x1c5aac ldr r11, [r9, #0x110] */
/* @0x1c5ab0 and r2, r4, r2 */
/* @0x1c5ab4 add r12, r11, r3 */
/* @0x1c5ab8 rsb r2, r2, r12 */
/* @0x1c5abc tst r2, r4 */
/* @0x1c5ac0 bpl 0x1c5c2c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x1f4> */

/* ── 造新元素①：容量检查 + 一次分配「容量」个 36 B ────────────
 *   r4 = [槽 0x3f086c] → 0x542678（池对象）。可用数 0 → 容量 <= 0 只翻倍；否则循环 Alloc。
 *   Alloc 站点串 = 0x34d69c（…/Files/Room/Room_Layers.h），行 63，flag 1。
 */

/* @0x1c5ac4 ldr r4, [pc, #0x238] */
/* @0x1c5ac8 ldr r4, [pc, r4] */
/* @0x1c5acc ldr r11, [r4, #0x8] */
/* @0x1c5ad0 cmp r11, #0 */
/* @0x1c5ad4 bne 0x1c5b88 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x150> */
/* @0x1c5ad8 ldr r3, [r4, #0x10] */
/* @0x1c5adc cmp r3, #0 */
/* @0x1c5ae0 ble 0x1c5b80 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x148> */
/* @0x1c5ae4 ldr r7, [pc, #0x21c] */
/* @0x1c5ae8 mov r5, r11 */
/* @0x1c5aec mvn r6, #0 */
/* @0x1c5af0 add r7, pc, r7 */
/* @0x1c5af4 mov r3, #1 */
/* @0x1c5af8 mov r0, #36 */
/* @0x1c5afc mov r1, r7 */
/* @0x1c5b00 mov r2, #63 */
/* @0x1c5b04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */

/* ── 造新元素②：初值 + 头插自由链 + 继续循环 ─────────────────
 *   +0x00 = 2、+0x04 = -1、+0x1c = -1、+0x0c..+0x18 = 0、+0x20 = 0、+0x08 = 0。
 *   自由链插入用 +0x18(prev)/+0x14(next)（与活对象的元素链同一对偏移）。
 */

/* @0x1c5b08 mov r3, #2 */
/* @0x1c5b0c cmp r0, #0 */
/* @0x1c5b10 beq 0x1c5b38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x100> */
/* @0x1c5b14 strb r5, [r0, #0x8] */
/* @0x1c5b18 str r5, [r0, #0xc] */
/* @0x1c5b1c str r5, [r0, #0x10] */
/* @0x1c5b20 str r5, [r0, #0x14] */
/* @0x1c5b24 str r5, [r0, #0x18] */
/* @0x1c5b28 str r6, [r0, #0x4] */
/* @0x1c5b2c str r6, [r0, #0x1c] */
/* @0x1c5b30 str r5, [r0, #0x20] */
/* @0x1c5b34 str r3, [r0] */
/* @0x1c5b38 ldr r3, [r4] */
/* @0x1c5b3c add r11, r11, #1 */
/* @0x1c5b40 ldr r2, [r4, #0x8] */
/* @0x1c5b44 cmp r3, #0 */
/* @0x1c5b48 streq r0, [r4, #0x4] */
/* @0x1c5b4c strne r0, [r3, #0x18] */
/* @0x1c5b50 add r2, r2, #1 */
/* @0x1c5b54 streq r3, [r0, #0x18] */
/* @0x1c5b58 streq r3, [r0, #0x14] */
/* @0x1c5b5c strne r3, [r0, #0x14] */
/* @0x1c5b60 ldr r3, [r4, #0x10] */
/* @0x1c5b64 streq r0, [r4] */
/* @0x1c5b68 strne r0, [r4] */
/* @0x1c5b6c strne r5, [r0, #0x18] */
/* @0x1c5b70 cmp r11, r3 */
/* @0x1c5b74 str r2, [r4, #0x8] */
/* @0x1c5b78 blt 0x1c5af4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0xbc> */

/* ── 容量翻倍（补齐后无条件执行）────────────────────────────── */

/* @0x1c5b7c ldr r11, [r4, #0x8] */
/* @0x1c5b80 lsl r3, r3, #1 */
/* @0x1c5b84 str r3, [r4, #0x10] */

/* ── 弹出 + 交付（本函数最长的一段直线代码）────────────────────
 *   1c5b88 r12 = 池头；1c5b8c 可用数 -1；1c5ba4 取计数器的槽（0x3f0ae8 → 0x5425f0）；
 *   1c5bb0..1c5bd0 摘链（+0x14/+0x18）；1c5bd4 计数器旧值 → 1c5be4 写进 elem+0x04；
 *   1c5bdc elem+0x20 = instance；1c5be8 elem+0x1c = instance+0x78；1c5bf0 instance+0x170 = 层 id；
 *   1c5bfc instance+0x174 = 1；1c5c08 instance+0x180 = (float)层 depth；1c5c0c elem+0x08 = 1；
 *   1c5c00 顺便把 instance+0x69（停用位）读进 r3 —— 它就是尾调 AddElementToLayer 的第 4 实参。
 */

/* @0x1c5b88 ldr r12, [r4] */
/* @0x1c5b8c sub r11, r11, #1 */
/* @0x1c5b90 ldr r5, [pc, #0x174] */
/* @0x1c5b94 mov r0, r9 */
/* @0x1c5b98 ldr r7, [r10] */
/* @0x1c5b9c mov r1, r10 */
/* @0x1c5ba0 ldr r3, [r12, #0x18] */
/* @0x1c5ba4 ldr r5, [pc, r5] */
/* @0x1c5ba8 ldr r2, [r12, #0x14] */
/* @0x1c5bac cmp r3, #0 */
/* @0x1c5bb0 str r11, [r4, #0x8] */
/* @0x1c5bb4 strne r2, [r3, #0x14] */
/* @0x1c5bb8 ldrne r2, [r12, #0x14] */
/* @0x1c5bbc ldrne r3, [r12, #0x18] */
/* @0x1c5bc0 streq r2, [r4] */
/* @0x1c5bc4 cmp r2, #0 */
/* @0x1c5bc8 streq r3, [r4, #0x4] */
/* @0x1c5bcc mov r4, #1 */
/* @0x1c5bd0 strne r3, [r2, #0x18] */
/* @0x1c5bd4 ldr r3, [r5] */
/* @0x1c5bd8 ldr r2, [r8, #0x78] */
/* @0x1c5bdc str r8, [r12, #0x20] */
/* @0x1c5be0 add r6, r3, r4 */
/* @0x1c5be4 str r3, [r12, #0x4] */
/* @0x1c5be8 str r2, [r12, #0x1c] */
/* @0x1c5bec mov r2, r12 */
/* @0x1c5bf0 str r7, [r8, #0x170] */
/* @0x1c5bf4 vldr s15, [r10, #4] */
/* @0x1c5bf8 vcvt.f32.s32 s15, s15 */
/* @0x1c5bfc strb r4, [r8, #0x174] */
/* @0x1c5c00 ldrb r3, [r8, #0x69] */
/* @0x1c5c04 str r6, [r5] */
/* @0x1c5c08 vstr s15, [r8, #384] */
/* @0x1c5c0c strb r4, [r12, #0x8] */
/* @0x1c5c10 add sp, sp, #4 */
/* @0x1c5c14 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5c18 b 0x1c451c <_ZN13CLayerManager17AddElementToLayerEP5CRoomP6CLayerP17CLayerElementBaseb> */

/* ── 探测推进（冲突时）：比较探测距离，或换位或插新 ──────────
 *   1c5c1c 命中哈希 → 1c5c64；1c5c24 的 blt 是「占用者的探测距离比新项小」→ 直接插新（1c5ac4）。
 *   1c5c2c 起推进：索引 (idx+1)&掩码，重算 3*idx 与桶地址，距离 = (容量+idx) - (掩码&占用者哈希)。
 *   ⚠ 「换位/插入」的逐位规则没有全证：本节只能确定「按 31 位哈希命中；未命中时依探测距离决定推进还是插新」。
 */

/* @0x1c5c1c cmp r0, r12 */
/* @0x1c5c20 beq 0x1c5c64 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x22c> */
/* @0x1c5c24 cmp r7, r5 */
/* @0x1c5c28 blt 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c2c add r3, r3, #1 */
/* @0x1c5c30 add r5, r5, #1 */
/* @0x1c5c34 and r3, r4, r3 */
/* @0x1c5c38 add r7, r11, r3 */
/* @0x1c5c3c lsl r6, r3, #1 */
/* @0x1c5c40 add r2, r6, r3 */
/* @0x1c5c44 add r2, r1, r2, lsl #2 */
/* @0x1c5c48 ldr r12, [r2, #0x8] */
/* @0x1c5c4c and r2, r4, r12 */
/* @0x1c5c50 cmp r12, #0 */
/* @0x1c5c54 rsb r7, r2, r7 */
/* @0x1c5c58 and r7, r7, r4 */
/* @0x1c5c5c bne 0x1c5c1c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x1e4> */
/* @0x1c5c60 b 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */

/* ── 命中后取桶值：三条分叉 ─────────────────────────────────
 *   1c5c64：索引为 -1（不可能命中）→ 插新；1c5c6c 重算桶地址；1c5c7c 取值；
 *   值为 0 → 插新；值非 0 → 1c5c88 看 elem+0x20。
 */

/* @0x1c5c64 cmn r3, #1 */
/* @0x1c5c68 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c6c add r3, r6, r3 */
/* @0x1c5c70 add r1, r1, r3, lsl #2 */
/* @0x1c5c74 cmn r1, #4 */
/* @0x1c5c78 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c7c ldr r3, [r1, #0x4] */
/* @0x1c5c80 cmp r3, #0 */
/* @0x1c5c84 beq 0x1c5ac4 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x8c> */
/* @0x1c5c88 ldr r2, [r3, #0x20] */
/* @0x1c5c8c cmp r2, #0 */
/* @0x1c5c90 beq 0x1c5cc0 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x288> */

/* ── 异常态：同一 id 已有活元素 → 虚调用报错 " ERROR: Adding too many variables" ──
 *   1c5c94/1c5c98 取宿主对象槽（0x3ed718 → 0x479a94）与字符串槽（0x1c5d14 → 0x35285c），
 *   1c5ca0 r2 = instance+0x78，1c5cac..1c5cb4 走 [vtable+0xc]；随后 pop 返回，**一个字段都不改**。
 */

/* @0x1c5c94 ldr r3, [pc, #0x74] */
/* @0x1c5c98 ldr r1, [pc, #0x74] */
/* @0x1c5c9c ldr r3, [pc, r3] */
/* @0x1c5ca0 ldr r2, [r8, #0x78] */
/* @0x1c5ca4 add r1, pc, r1 */
/* @0x1c5ca8 ldr r0, [r3] */
/* @0x1c5cac ldr r3, [r0] */
/* @0x1c5cb0 ldr r3, [r3, #0xc] */
/* @0x1c5cb4 blx r3 */
/* @0x1c5cb8 add sp, sp, #4 */
/* @0x1c5cbc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 复用分支：元素已在表里但没挂实例（+0x20 == 0）─────────────
 *   1c5cc0 r0 = 层 id；1c5cc8 elem+0x20 = instance；1c5ccc 读停用位；
 *   1c5cd0 instance+0x170 = 层 id；1c5ce0 instance+0x174 = 1；1c5ce4 instance+0x180 = 层 depth；
 *   1c5ce4 之后 1c5ce8 elem+0x08 = 1；1c5cec 停用位为 0 → 直接返回（不调 UpdateInstanceActivation）。
 *   ⚠ 本分支**不改 layer 的元素链、不动表 2/3** —— 元素已经挂在某个层上，这里只补指针。
 */

/* @0x1c5cc0 ldr r0, [r10] */
/* @0x1c5cc4 mov r2, #1 */
/* @0x1c5cc8 str r8, [r3, #0x20] */
/* @0x1c5ccc ldrb r1, [r8, #0x69] */
/* @0x1c5cd0 str r0, [r8, #0x170] */
/* @0x1c5cd4 vldr s15, [r10, #4] */
/* @0x1c5cd8 vcvt.f32.s32 s15, s15 */
/* @0x1c5cdc cmp r1, #0 */
/* @0x1c5ce0 strb r2, [r8, #0x174] */
/* @0x1c5ce4 vstr s15, [r8, #384] */
/* @0x1c5ce8 strb r2, [r3, #0x8] */
/* @0x1c5cec beq 0x1c5a6c <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance+0x34> */

/* ── 复用分支的第二出口：停用实例要刷活跃表（尾调）─────────── */

/* @0x1c5cf0 mov r0, r9 */
/* @0x1c5cf4 mov r1, r8 */
/* @0x1c5cf8 add sp, sp, #4 */
/* @0x1c5cfc pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c5d00 b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */

/* ── 字面量池（1c5d04..1c5d14，5 字；前两字被 objdump 译成指令）──
 *   1c5d04 = 0x0022ad9c → 槽 0x3f086c（0x542678 36 B 池）
 *   1c5d08 = 0x00187ba4 → 串 0x34d69c（Room_Layers.h，Alloc 站点）
 *   1c5d0c = 0x0022af3c → 槽 0x3f0ae8（0x5425f0 元素 uid 计数器）
 *   1c5d10 = 0x00227a78 → 槽 0x3ed718（0x479a94 报错宿主对象）
 *   1c5d14 = 0x0018abb8 → 串 0x35285c（" ERROR: Adding too many variables"）
 */

/* @0x1c5d04 mlaeq r2, r12, sp, r10 */
/* @0x1c5d08 andseq r7, r8, r4, lsr #23 */
/* @0x1c5d0c eoreq r10, r2, r12, lsr pc */
/* @0x1c5d10 eoreq r7, r2, r8, ror r10 */
/* @0x1c5d14 ldrheq r10, [r8], -r8 */
