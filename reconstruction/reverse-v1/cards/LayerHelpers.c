/* cally 逆向卡：层/碰撞辅助七件（原版 libyoyo.so，armv7）—— 一卡七节
 * @func 七节按地址升序，逐节自带 @func 头与逐条锚点：
 *   §1 0x1b7ac4 CLayerManager::RemoveInstanceElement  size 232
 *   §2 0x1b87f4 CLayerManager::GetLayerWithDepth      size 116
 *   §3 0x1c33e4 CLayerManager::AddDynamicLayer        size 436
 *   §4 0x1cc494 CollisionInsert                       size 108
 *   §5 0x1cd9f0 CollisionRemove                       size 300
 *   §6 0x19230c CInstance::SetDeactivated             size  52
 *   §7 0x192fa4 CInstance::RebuildPhysicsBody         size  72
 * 总账: 329 锚点 = 314 条指令 + 15 个池字，与 asm/index-LayerHelpers_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py → index=329 card=329 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 * 级别: 正文（七节都逐条解码到控制流/算式；每节末尾单列本节 open，未钉的地方不冒充已钉）。
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录；池字保留 objdump 的「像指令」写法，
 *       并在各节注释里逐字标出「非指令」。
 *
 * ── 全局坐标（本轮读 libyoyo.so 的 .rel.dyn（R_ARM_RELATIVE=23）+ .dynsym 实测，不是从字符串猜的）──
 *   GOT 槽      目标        符号（.dynsym 原名）
 *   0x3ed92c → 0x5428e8   g_isZeus（1 B）
 *   0x3ed930 → 0x54298c   Run_Room（CRoom*，4 B）
 *   0x3ee24c → 0x5429a8   g_tree（RTree<CInstance*,int,float,6,2>*，4 B）
 *   0x3f0688 → 0x542379   option_use_fast_collision（1 B）
 *   0x3f0b44 → 0x5429ac   s_dirty_list（12 B）
 *   0x3f0b3c → 0x5429b8   s_test_list（12 B）
 *   0x3f086c → 0x542678   CLayerManager::m_InstanceElementPool（20 B）
 *   0x3f0864 → 0x5426a0   CLayerManager::m_LayerPool（20 B）
 *   0x3f0ae8 → 0x5425f0   CLayerManager::m_CurrentElementID
 *   0x3f0ae4 → 0x5425f4   CLayerManager::m_CurrentLayerID
 *   0x3f0888 → 0x5425f8   CLayerManager::m_LayerIDWatermark
 *   ⇒ 其中 0x3f086c→0x542678、0x3f0ae8→0x5425f0 两处与 CLayerManager_AddInstanceToLayer 卡独立吻合；
 *     0x3ed92c→g_isZeus、0x3ed930→Run_Room 与 DoBreak / DoAStep 卡吻合。
 *   ⚠ 碰撞两件（§4/§5）的门是 option_use_fast_collision（0x542379），**不是** g_isZeus：
 *     两者 GOT 槽不同（0x3f0688 vs 0x3ed92c），别按「层系统开关」去解释碰撞代码。
 *
 * ── 两个池的公共协议（20 B，本卡两池都按这个读）──
 *   +0x00 自由链头、+0x04 自由链尾、+0x08 可用数、+0x0c 空（无访问）、+0x10 容量。
 *   自由链与活链共用链接偏移：层池 +0x68(next)/+0x6c(prev)，元素池 +0x14(next)/+0x18(prev)。
 *   ⇒ 同一个 112 B 块在池里用 +0x68/+0x6c 串自由链，被 InsertLayerIntoActiveList 拿走后又用同一对偏移串活链；
 *     36 B 元素块同理（池链 +0x14/+0x18 与层内元素链 +0x14/+0x18 是同一对）。
 *   扩容策略两池一致：可用数 == 0 → 容量 > 0 就循环 Alloc 到填满容量并逐个头插自由链，然后把容量翻倍。
 *
 * ── CLayer（112 B）本卡直接写到的字段 ──
 *   +0x00 id(int)  +0x04 depth(int)  +0x08/+0x0c/+0x10/+0x14 = 0.0f
 *   +0x18 可见位  +0x19 动态层筛子（GetLayerWithDepth 第 3 实参选的就是它）
 *   +0x1c 名字指针（AddLayer 分配 strlen+1）  +0x20/+0x24/+0x28 = -1
 *   +0x2c 本函数不写（全卡无写方，见 open）
 *   +0x30..+0x57 CTimingSource（Reset 写 +0x30..+0x57 内的一段）  +0x48/+0x4c = 0
 *   +0x58 元素链头  +0x5c 元素链尾  +0x60 元素数
 *   +0x64 层类别/回收档（1/2/3；ChangeLayerDepth 0x1b85e4 按它分派三种元素回收路径）
 *   +0x68 next  +0x6c prev（活链 = room 的按 depth 升序层链）
 *   room 侧：+0xd4 层链头、+0xd8 层链尾、+0xdc 层数；表 1 在 +0xe4 簇（+0xe4 容量/+0xe8 已用/+0xec 掩码/+0xf0 阈值/+0xf4 桶）。
 *
 * ── 元素与实例的公共头（本卡用到的）──
 *   CLayerElementBase：+0x00 type  +0x04 uid  +0x08 在用位  +0x0c ?  +0x10 所属 CLayer*
 *                      +0x14 next  +0x18 prev
 *   CLayerInstanceElement（type 2，36 B）：+0x1c 实例 id（= instance+0x78）  +0x20 CInstance*
 *   CInstance：+0x69 deactivated(1 B)  +0x78 id  +0x80 CObjectGM*  +0x84 CPhysicsObject*
 *              +0x170 层 id  +0x174 已归层(1 B)  +0x180 depth(float)
 *              +0xe8/+0xec/+0xf0/+0xf4 bbox(left/top/right/bottom，int)
 *              +0x18c/+0x190/+0x194 碰撞测试侵入链(link.next/link.prev/属主)  +0x198/+0x19c/+0x1a0 碰撞脏链
 *              +0x68 已销毁  +0x64 bbox 脏位（都是字节）
 *   ⇒ 侵入链的「属主」字段存的是**全局链表头地址**（本卡碰到的两条是 &s_test_list / &s_dirty_list；
 *     第三条 +0x1a4/+0x1a8/+0x1ac 见 CInstance ctor 卡，本卡不解剖），
 *     链节点存的是 link 字段地址（this+0x18c），不是 this —— 见 CInstance ctor 卡三段自环。
 *
 * ── 跨节结论（本题五个重点）──
 *   A. Remove ↔ Add 的对称性（§1）：AddInstanceToLayer 是「出池 → 填字段 → 回写实例三字段 → 尾调 AddElementToLayer（插链插表）」；
 *      RemoveInstanceElement 只做「回写实例 →（可选）销毁实例 → 摘链 → 回池」。
 *      **表 2/表 3 的删除不在本函数**，因为它签名里没有 room —— 唯一调用者 RemoveElement(room,…) 在尾跳前做完。
 *      两边的字段表逐项对照见 §1。
 *   B. GetLayerWithDepth 的提前返回（§2）：层链按 +0x04 升序，一遇「当前层 depth > 目标」就立即返回 0；
 *      命中同 depth 时，dynOnly 模式还要求 +0x19 != 0，为 0 是「继续往后找」而不是停住。
 *   C. SetDeactivated 的两条路（§6）：字节 +0x69 先无条件写；g_isZeus == 0 就地返回（纯写字节）；
 *      g_isZeus != 0 则尾调 UpdateInstanceActivation(Run_Room, this)，把元素挪到层链尾（停用）/头（恢复）。
 *   D. 停用顺序不是装饰（§6 末）：DrawRoomLayers 对 +0x69 != 0 的元素是**跳出整层循环**，不是跳过单个元素。
 *   E. 碰撞两件全由 option_use_fast_collision 一个字节开关；CollisionInsert 懒建 g_tree 后并**不直接插树**，
 *      真正摘旧插新发生在 Compute_BoundingBox(true) → CollisionUpdate 里；CollisionRemove 摘树 + 摘两条侵入链。
 *
 * ── 汇总 open（各节还有细项）──
 *   · g_isZeus 的语义：层系统三个入口（AddInstance 0x1c5d18、UpdateInstanceActivation 0x1b8a28、SetDeactivated）
 *     都要求它 != 0 才工作；但 CLayerManager_AddInstance 卡正文写成「非 0 → 直接返回」，与机器码 popeq 相反。
 *     谁写这个字节、为什么叫 Zeus，都未证（claims 里单列一条纠正）。
 *   · CLayer +0x64 的枚举名、+0x2c 的用途、m_LayerPool 初始容量由谁预置（AddDynamicLayer 在 cap<=0 时只把 0 翻倍）。
 *   · elem+0x1c == -14 为什么免销毁；elem+0x0c 的非 0 写方。
 *   · RTree 构造的唯一实参 1024、RTree::Remove 的第 4 实参 true、CObjectGM+0x1c 的正式名。
 */

/* ══ §1 CLayerManager::RemoveInstanceElement 0x1b7ac4 ═════════════════════
 * @func 0x1b7ac4 0x1b7ba8 size 232  58 条（57 指令 + 1b7ba8 一个字面量池字）
 * 级别: 正文（58/58。控制流是一条直线 + 两处条件写 + 一处条件调用；无循环、无分配）
 * 符号: _ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb
 *       → void RemoveInstanceElement(CLayer* layer, CLayerInstanceElement* elem, bool bDestroy)
 * 同层: AddElementToLayer 0x1c451c（插链/插表的反面）、AddInstanceToLayer 0x1c5a38（同一个 36 B 池的取方）、
 *       RemoveElement 0x1b8fdc（唯一调用者，尾跳进来）、DoInstanceDestroy 0x10b12c（可选副作用）、
 *       CleanInstanceElementRuntimeData 0x1b8d9c（另一条清 +0x20/+0x170/+0x174 的路）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   把实例元素从层元素链上摘下来、压回 36 B 元素池，并清掉实例的「层 id / 已归层」；
 *   bDestroy 时再按元素记的实例 id 硬销毁该实例。**不碰房间的三张哈希表，也不还原实例 depth。**
 *
 * ── 逐段（本函数三个入参一个都不判空，第一条指令就解引用 r1）──────────────
 *   ① 0x1b7ac4 取 elem+0x20（挂着的实例）。非 0 才回写：instance+0x170 = -1、instance+0x174 = 0。
 *      为 0（元素没挂实例）就跳过这组回写；⚠ 但第 ③ 步照样摘链 —— 对一个已回池（+0x14/+0x18 已清 0）的元素
 *      再调一次，会把 layer+0x58/+0x5c 清成 0 并多减一次计数，不是无害操作（见 open）。
 *   ② bDestroy != 0 且 elem+0x1c != -14 才 DoInstanceDestroy(NULL, NULL, elem+0x1c, 1)。
 *      cmn r2,#14 就是「r2 == -14 ?」；第 4 实参 1 = hard（DoInstanceDestroy 卡：hard 原样透传 DoDestroy）。
 *      ⚠ 用的是**元素记的 id**而不是 elem+0x20 的指针，self/other 传 0 —— 与 DoInstanceDestroy 卡
 *        「id >= 0 路径不依赖 self/other」互证。
 *   ③ 摘链：prev = elem+0x18、next = elem+0x14；prev != 0 → prev->next = next；prev == 0 → layer+0x58 = next；
 *      next == 0 → layer+0x5c = prev；next != 0 → next->prev = prev；layer+0x60 -= 1。
 *   ④ 回池（m_InstanceElementPool 0x542678）：先把 +0x14/+0x18 清 0，再写 type=2、uid=-1、+0x08=0、+0x0c=0、
 *      +0x10=0、+0x20=0、+0x1c=-1；可用数 +1；头插自由链（旧头非 0：旧头->prev = elem、elem->next = 旧头、
 *      elem->prev = 0；池空：head = tail = elem）。
 *   ⑤ 出口 pop {r4,r5,r6,pc}，void。
 *
 * ── 与 Add 侧的对称性（本题重点 1；右边是本函数）───────────────────────────
 *   环节        Add（AddInstanceToLayer 0x1c5a38 + AddElementToLayer 0x1c451c）        Remove（本函数）
 *   池          从 m_InstanceElementPool 弹出（1c5b88..1c5c0c）                        压回同一池（1b7b5c..1b7ba0）
 *   元素初值    type=2、uid=m_CurrentElementID++、+0x08=1、+0x1c=inst+0x78、+0x20=inst   type=2、uid=-1、+0x08=0、+0x1c=-1、+0x20=0
 *   +0x10       不写（由 AddElementToLayer 1c45b0 写层指针）                            清 0
 *   链          AddElementToLayer：第 4 实参（= inst+0x69）非 0 → 尾插，否则头插；count+1   按 +0x14/+0x18 摘；count-1
 *   实例字段    +0x170=层 id、+0x174=1、+0x180=(float)层 depth                          +0x170=-1、+0x174=0（**+0x180 不动**）
 *   表 2/表 3   AddElementToLayer 插：room+0xf8 键 elem+0x04、room+0x110 键 elem+0x1c    不碰（由 RemoveElement 做）
 *   附加        —                                                                        bDestroy → DoInstanceDestroy(id, hard=1)
 *   ⇒ 唯一的**非对称**是 depth(+0x180)：Add 把它改成层深度，Remove 不还原。所以「摘下来」之后实例仍带着旧层深度、
 *     层 id 却是 -1；下次 AddInstance 走第 2 级按 depth 找动态层时，若那一层已被并/改深度，实例会落到别的层。
 *     本卡只证字段事实，这条路径是否可达记 open。
 *
 * ── 为什么表删在 RemoveElement（跨卡证据）────────────────────────────────
 *   RemoveElement(CRoom*,CLayer*,CLayerElementBase*,bool) 0x1b8fdc：
 *     · 0x1b9010 按 elem+0x04 查表 2（room+0xf8 容量/0x100 掩码/0x108 桶）并清桶；
 *     · 0x1b90a8 把 room+0x10c 的缓存层指针在相等时清 0；0x1b90c0 调 CleanElementRuntimeData(elem)；
 *     · 0x1b90d0..0x1b90d4 按 elem->type-1（0..6）跳表；type==2 走 0x1b91ec：以 elem+0x1c 为键再查表 3
 *       （room+0x110 簇，+0x118 掩码/+0x120 桶），删完在 0x1b92a0 用 b 尾跳本函数。
 *   ⇒ 「一个实例元素从层上消失」= RemoveElement（两张表 + 运行期数据）+ 本函数（链 + 池 + 实例）。
 *     只看本函数会误判为「表泄漏」；只看 RemoveElement 会漏掉池回收。两边要合起来读。
 *   ⇒ 另一个同效果的入口是 CleanInstanceElementRuntimeData 0x1b8d9c：它把 elem+0x20 清 0，并用实例 id 查
 *     「id → CInstance」表把 instance+0x174/+0x170 清掉 —— 所以本函数第 ① 步不是唯一清实例字段的地方。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · elem+0x1c == -14 为什么免销毁。已知的负值约定只有 GML 的 -1/-2/-3（self/other/all），-14 无对应；
 *     也未见别处写 -14（池初值是 -1）。
 *   · elem+0x0c 本函数清 0，Add 侧初值也写 0；全卡范围没有任何非 0 写方，语义未知。
 *   · 同一 elem 被调两次：第二次会二次头插自由链（池里两个同指针节点），并把目标层的头/尾清 0、计数多减 1
 *     （因为 +0x14/+0x18 已被清 0）。有没有防护、这种调用是否可达，未证。
 */

/* @0x1b7ac4 ldr r3, [r1, #0x20] */
/* @0x1b7ac8 push {r4, r5, r6, lr} */
/* @0x1b7acc cmp r3, #0 */
/* @0x1b7ad0 mov r4, r1 */
/* @0x1b7ad4 mov r5, r0 */
/* @0x1b7ad8 mvnne r1, #0 */
/* @0x1b7adc movne r0, #0 */
/* @0x1b7ae0 strne r1, [r3, #0x170] */
/* @0x1b7ae4 strbne r0, [r3, #0x174] */
/* @0x1b7ae8 cmp r2, #0 */
/* @0x1b7aec beq 0x1b7b0c <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb+0x48> */
/* @0x1b7af0 ldr r2, [r4, #0x1c] */
/* @0x1b7af4 cmn r2, #14 */
/* @0x1b7af8 beq 0x1b7b0c <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb+0x48> */
/* @0x1b7afc mov r0, #0 */
/* @0x1b7b00 mov r3, #1 */
/* @0x1b7b04 mov r1, r0 */
/* @0x1b7b08 bl 0x10b12c <_Z17DoInstanceDestroyP9CInstanceS0_ib> */
/* @0x1b7b0c ldr r3, [r4, #0x18] */
/* @0x1b7b10 mvn r0, #0 */
/* @0x1b7b14 ldr r2, [r4, #0x14] */
/* @0x1b7b18 mov r6, #2 */
/* @0x1b7b1c cmp r3, #0 */
/* @0x1b7b20 ldr r1, [r5, #0x60] */
/* @0x1b7b24 strne r2, [r3, #0x14] */
/* @0x1b7b28 add r1, r1, r0 */
/* @0x1b7b2c ldrne r2, [r4, #0x14] */
/* @0x1b7b30 ldrne r3, [r4, #0x18] */
/* @0x1b7b34 streq r2, [r5, #0x58] */
/* @0x1b7b38 cmp r2, #0 */
/* @0x1b7b3c streq r3, [r5, #0x5c] */
/* @0x1b7b40 strne r3, [r2, #0x18] */
/* @0x1b7b44 mov r3, #0 */
/* @0x1b7b48 ldr r2, [pc, #0x58] */
/* @0x1b7b4c str r1, [r5, #0x60] */
/* @0x1b7b50 ldr r2, [pc, r2] */
/* @0x1b7b54 str r3, [r4, #0x14] */
/* @0x1b7b58 str r3, [r4, #0x18] */
/* @0x1b7b5c ldr r1, [r2] */
/* @0x1b7b60 ldr r12, [r2, #0x8] */
/* @0x1b7b64 cmp r1, r3 */
/* @0x1b7b68 str r6, [r4] */
/* @0x1b7b6c str r0, [r4, #0x4] */
/* @0x1b7b70 add r12, r12, #1 */
/* @0x1b7b74 strb r3, [r4, #0x8] */
/* @0x1b7b78 str r3, [r4, #0xc] */
/* @0x1b7b7c str r3, [r4, #0x10] */
/* @0x1b7b80 str r3, [r4, #0x20] */
/* @0x1b7b84 str r0, [r4, #0x1c] */
/* @0x1b7b88 str r12, [r2, #0x8] */
/* @0x1b7b8c strne r4, [r1, #0x18] */
/* @0x1b7b90 streq r4, [r2, #0x4] */
/* @0x1b7b94 streq r4, [r2] */
/* @0x1b7b98 strne r4, [r2] */
/* @0x1b7b9c strne r1, [r4, #0x14] */
/* @0x1b7ba0 strne r3, [r4, #0x18] */
/* @0x1b7ba4 pop {r4, r5, r6, pc} */
/* @0x1b7ba8 eoreq r8, r3, r4, lsl sp */

/* ══ §2 CLayerManager::GetLayerWithDepth 0x1b87f4 ═════════════════════════
 * @func 0x1b87f4 0x1b8868 size 116  29 条（29 指令，无字面量池：末尾即下一个符号 GetLayerFromID）
 * 级别: 正文（29/29。叶子函数：不 push、不用 r4 以上，只有两个线性循环）
 * 符号: _ZN13CLayerManager17GetLayerWithDepthEP5CRoomib
 *       → CLayer* GetLayerWithDepth(CRoom* room, int depth, bool dynamicOnly)
 * 调用者（全图 2 处）：CLayerManager::AddInstance 0x1c5d90（r2 = 1）、
 *                     CLayerManager::AddNewElementAtDepth 0x1c6ca0（r2 = 它的第 5 实参）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   在房间的**按 depth 升序**层链上线性找 depth 相等的层；dynamicOnly 时还要求 layer+0x19 != 0。
 *   链走空或当前层 depth 已大于目标就返回 0（升序 ⇒ 后面不可能再有）。
 *
 * ── 两个循环（只在第 3 实参分叉，其余逐字同构）────────────────────────────
 *   入口：r0 = room ? room+0xd4 : 0；r0 == 0 → bxeq lr 返回 0（1b87f4/1b87f8 与 1b87fc/1b8804 两处）。
 *   循环 A（r2 != 0，dynamicOnly；1b8810..1b8840）：
 *     d = layer+0x04
 *     d == depth → 读 layer+0x19：非 0 → 返回该层（1b8830 bxne lr）；为 0 → **落到下一层**（不返回）
 *     d <  depth → 下一层（1b8834）
 *     d >  depth → r0 = 0，返回            ← 提前返回①
 *     下一层 = layer+0x68；为 0 → 返回 0
 *   循环 B（r2 == 0；1b8844..1b8864）：
 *     d == depth → 返回该层（**不看 +0x19**）
 *     depth < d  → r0 = 0，返回            ← 提前返回②
 *     否则下一层；为 0 → 返回 0
 *   ⇒ 全部出口只有三种：命中返回层 / 链空返回 0 / 「当前层 depth > 目标」提前返回 0。
 *     等 depth 但 +0x19 == 0 在 A 里是「继续」，不是返回 —— 这是最容易读错的一点。
 *
 * ── 提前返回的前提（谁维护升序）─────────────────────────────────────────
 *   InsertLayerIntoActiveList 0x1c30f8：从 room+0xd4 头开始按 +0x04 前进（1c311c..1c3144），
 *   在第一个 depth 更大的层前插入（1c3148..1c3180），空链写 room+0xd4/+0xd8（1c33c8..1c33d4），
 *   每次 room+0xdc += 1；随后把层 id 插进表 1（room+0xe4 簇，1c3180..1c337c）。
 *   ⇒ 升序是本函数的**唯一隐含前提**：谁若直接改 layer+0x04 而不重插链，提前返回会漏掉后面的层。
 *
 * ── 行为后果（跨卡）─────────────────────────────────────────────────────
 *   · AddInstance 0x1c5d18 只在「第 2 级」传 dynamicOnly = 1 ⇒ 层 id 为 -1 的实例永远进不了房间文件里的
 *     静态层（+0x19 == 0），只会命中动态层，或落到第 3 级 AddDynamicLayer 新建一个。
 *   · AddNewElementAtDepth 0x1c6c78 把这个 bool 用成「两用开关」：
 *       layer = GetLayerWithDepth(room, depth, b);
 *       if (layer) r4 = 0; else r4 = b & 1;            // 1c6ca4..1c6cac
 *       if (r4) layer = AddDynamicLayer(room, depth);  // 1c6cd8..1c6ce0
 *       return layer ? AddNewElement(room, layer, elem, b1) : -1;   // 1c6cc4 / 1c6cec
 *     ⇒ 同一 bool 既是「只认动态层」又是「缺了就建」。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · layer+0x19 的 GML 侧名字。本卡沿用「动态层筛子」：运行期唯一写 1 的是 AddDynamicLayer 1c3558；
 *     AddLayer 1c3704 写 0；DeSerializeLayer 1c77b0 从房间流把这个字节读进来。
 *   · 同一 depth 有多层时，A 只认 +0x19 != 0 的第一个、B 只认第一个（无论静态还是动态）——
 *     为什么静态层的「第一个」就够，未证（推测依赖 BuildRoomLayers 的插入顺序）。
 *   · 本函数不回写、不分配、不校验层链是否已被 RemoveLayer 改坏（纯读者）。
 */

/* @0x1b87f4 cmp r0, #0 */
/* @0x1b87f8 bxeq lr */
/* @0x1b87fc ldr r0, [r0, #0xd4] */
/* @0x1b8800 cmp r0, #0 */
/* @0x1b8804 bxeq lr */
/* @0x1b8808 cmp r2, #0 */
/* @0x1b880c beq 0x1b8844 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x50> */
/* @0x1b8810 ldr r3, [r0, #0x4] */
/* @0x1b8814 cmp r3, r1 */
/* @0x1b8818 beq 0x1b8828 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x34> */
/* @0x1b881c ble 0x1b8834 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x40> */
/* @0x1b8820 mov r0, #0 */
/* @0x1b8824 bx lr */
/* @0x1b8828 ldrb r3, [r0, #0x19] */
/* @0x1b882c cmp r3, #0 */
/* @0x1b8830 bxne lr */
/* @0x1b8834 ldr r0, [r0, #0x68] */
/* @0x1b8838 cmp r0, #0 */
/* @0x1b883c bne 0x1b8810 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x1c> */
/* @0x1b8840 bx lr */
/* @0x1b8844 ldr r3, [r0, #0x4] */
/* @0x1b8848 cmp r3, r1 */
/* @0x1b884c bxeq lr */
/* @0x1b8850 cmp r1, r3 */
/* @0x1b8854 blt 0x1b8820 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x2c> */
/* @0x1b8858 ldr r0, [r0, #0x68] */
/* @0x1b885c cmp r0, #0 */
/* @0x1b8860 bne 0x1b8844 <_ZN13CLayerManager17GetLayerWithDepthEP5CRoomib+0x50> */
/* @0x1b8864 bx lr */

/* ══ §3 CLayerManager::AddDynamicLayer 0x1c33e4 ═══════════════════════════
 * @func 0x1c33e4 0x1c3598 size 436  109 条（104 指令 + 1c3584..1c3594 五个字面量池字）
 * 级别: 正文（109/109。扩容/初值/弹出/id/入链五段全解；两处外部前提记 open）
 * 符号: _ZN13CLayerManager15AddDynamicLayerEP5CRoomi
 *       → CLayer* AddDynamicLayer(CRoom* room, int depth)
 * 同层: AddLayer 0x1c3598（同池同骨架，多一个名字参数）、InsertLayerIntoActiveList 0x1c30f8（尾调）、
 *       GetLayerWithDepth 0x1b87f4（两个调用者都先问它）、SetLayerIndexWatermark 0x1b79f0（水位线 setter）
 * 调用者（全图 2 处）：AddInstance 0x1c5dac、AddNewElementAtDepth 0x1c6ce0
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   从 m_LayerPool 取一个 112 B 的 CLayer，写成「动态实例层」：可见、+0x19 = 1、元素链空、时间源 Reset；
 *   id = max(m_CurrentLayerID, m_LayerIDWatermark) + 1；再 InsertLayerIntoActiveList 入链入表 1。
 *
 * ── ① 扩容（1c33f0..1c34f4；池对象 m_LayerPool 0x5426a0，槽 0x3f0864）────────
 *   可用数 != 0 → 直接去 1c34f8 弹出。
 *   可用数 == 0：
 *     容量 > 0 → 循环「MemoryManager::Alloc(112, 串 0x34d69c = …/Files/Room/Room_Layers.h, 行 63, 1)
 *                → 写初值（见 ②）→ 头插自由链」直到可用数 == 容量（1c342c..1c34e8）；
 *                循环后容量 <<= 1 写回 +0x10（1c34ec..1c34f4）。
 *     容量 <= 0 → 只做那一次 <<= 1（0 还是 0），不分配，直接落到弹出。
 *   ⚠ 于是「可用数 == 0 且容量 <= 0」会拿 r4 = 池头 = 0 去解引用 +0x6c。⇒ 初始容量必须由别处预置；
 *     CLayerManager::Init 0x1b6f00 是唯一候选（本卡未取证，记 open）。36 B 元素池在 AddInstanceToLayer 里是同一套写法，
 *     同样的前提也在那张卡里没被点名。
 *
 * ── ② 每个新块的初值（1c3444..1c34a0，只在分配成功时执行）──────────────────
 *   +0x00 = -1
 *   +0x08/+0x0c/+0x10/+0x14 = 0.0f（s16 来自池字 1c3584 = 0x00000000）
 *   +0x18 = 1（可见）           +0x19 = 0（一会儿在 ④ 改 1）
 *   +0x48/+0x4c = 0（strd r4,r5，两字都是 0）
 *   +0x1c = 0（名字指针空）     +0x20/+0x24/+0x28 = -1
 *   CTimingSource::Reset(layer+0x30)（0x214728；写 +0x30/+0x34、+0x38/+0x3c、+0x40 字节、+0x50/+0x54）
 *   +0x58/+0x5c/+0x60 = 0（元素链头/尾/数）
 *   +0x64 = 1                   +0x68/+0x6c = 0（自由链链接）
 *   本函数自己的写区不含 +0x2c（+0x50/+0x54 由 Reset 写）。+0x2c 记 open。
 *
 * ── ③ 弹出（1c34f8..1c3534）──────────────────────────────────────────────
 *   自由链 next = +0x68、prev = +0x6c；head = 池+0x00、tail = 池+0x04；可用数 -1。
 *   摘链写法与 AddInstanceToLayer 弹出 36 B 元素逐字同构（同一段编译器模板）。
 *
 * ── ④ 交付（1c3538..1c3570）──────────────────────────────────────────────
 *   layer+0x04 = depth（第 2 实参经 [sp+4] 取出）
 *   t = max(m_CurrentLayerID(0x5425f4), m_LayerIDWatermark(0x5425f8)) + 1   // 1c3550..1c3564
 *   m_CurrentLayerID = t；layer+0x00 = t                                    // 1c3568/1c356c（水位线不动）
 *   layer+0x19 = 1                                                          // 1c3558
 *   InsertLayerIntoActiveList(room, layer)                                  // 1c3570
 *   返回 layer（1c3574 mov r0,r4）
 *
 * ── 与 AddLayer 0x1c3598 的差别（同池、同骨架、同扩容模板）───────────────
 *   AddLayer(room, depth, const char* name) 多两步：strlen(name)+1 后 Alloc 到 +0x1c 并 memcpy（1c3730..1c3760）；
 *   把 +0x19 写 **0**（1c3704）⇒ GML 的 layer_create 建的是「非动态」层，
 *   GetLayerWithDepth(room, depth, true) 看不见它 —— 这正是 AddInstance 第 2 级会「找不到」的那类层。
 *   AddLayer 随后同样调 InsertLayerIntoActiveList（1c376c）并返回层。
 *
 * ── 字面量池（1c3584..1c3594，5 字；objdump 把前 4 字译成指令，非指令）──────
 *   1c3584 = 0x00000000 → s16 = 0.0f（② 的四个 float）
 *   1c3588 = 0x0022d464 → 槽 0x3f0864 → 0x5426a0（m_LayerPool）
 *   1c358c = 0x0018a270 → 串 0x34d69c（Room_Layers.h，Alloc 站点；与 36 B 元素池同一串）
 *   1c3590 = 0x0022d340 → 槽 0x3f0888 → 0x5425f8（m_LayerIDWatermark）
 *   1c3594 = 0x0022d594 → 槽 0x3f0ae4 → 0x5425f4（m_CurrentLayerID）
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · m_LayerPool 的初始容量由谁预置（见 ①；Init 0x1b6f00 未查）。
 *   · +0x64 的语义：ChangeLayerDepth 0x1b85c4 读它，1/2/3 三档分别用 operator delete、MemoryManager::Free
 *     （两条不同循环）回收元素；但本卡查到的五个创建点（AddDynamicLayer 1c3498、AddLayer 1c3654、
 *     DuplicateRoomLayers 1c4ac8、BuildRoomLayers 1c61a4、DeSerializeLayer 1c7590）全都写 1，
 *     2/3 档的写方没找到 —— 要么在别的函数里，要么这三档对本作是死代码。名字未证。
 *   · +0x2c 无写方；+0x50/+0x54 假定属 CTimingSource（Reset 的覆盖范围按 0x28 B 估）。
 *   · 双计数器取 max 的理由（m_LayerIDWatermark 由 SetLayerIndexWatermark 0x1b79f0 写入、谁调未查）。
 */

/* @0x1c33e4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c33e8 vpush {d8} */
/* @0x1c33ec sub sp, sp, #12 */
/* @0x1c33f0 ldr r10, [pc, #0x190] */
/* @0x1c33f4 stm sp, {r0, r1} */
/* @0x1c33f8 ldr r10, [pc, r10] */
/* @0x1c33fc ldr r7, [r10, #0x8] */
/* @0x1c3400 cmp r7, #0 */
/* @0x1c3404 bne 0x1c34f8 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x114> */
/* @0x1c3408 ldr r3, [r10, #0x10] */
/* @0x1c340c cmp r3, #0 */
/* @0x1c3410 ble 0x1c34f0 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x10c> */
/* @0x1c3414 ldr r9, [pc, #0x170] */
/* @0x1c3418 mov r8, #1 */
/* @0x1c341c mov r4, #0 */
/* @0x1c3420 mov r5, #0 */
/* @0x1c3424 add r9, pc, r9 */
/* @0x1c3428 vldr s16, [pc, #340] */
/* @0x1c342c mov r2, #63 */
/* @0x1c3430 mov r0, #112 */
/* @0x1c3434 mov r1, r9 */
/* @0x1c3438 mov r3, #1 */
/* @0x1c343c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1c3440 mov r11, #0 */
/* @0x1c3444 mvn r2, #0 */
/* @0x1c3448 subs r6, r0, #0 */
/* @0x1c344c add r0, r6, #48 */
/* @0x1c3450 beq 0x1c34a4 <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0xc0> */
/* @0x1c3454 str r2, [r6] */
/* @0x1c3458 vstr s16, [r6, #8] */
/* @0x1c345c str r11, [r6, #0x4] */
/* @0x1c3460 vstr s16, [r6, #12] */
/* @0x1c3464 vstr s16, [r6, #16] */
/* @0x1c3468 vstr s16, [r6, #20] */
/* @0x1c346c strb r8, [r6, #0x18] */
/* @0x1c3470 strd r4, r5, [r6, #72] */
/* @0x1c3474 strb r11, [r6, #0x19] */
/* @0x1c3478 str r11, [r6, #0x1c] */
/* @0x1c347c str r2, [r6, #0x20] */
/* @0x1c3480 str r2, [r6, #0x24] */
/* @0x1c3484 str r2, [r6, #0x28] */
/* @0x1c3488 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1c348c str r11, [r6, #0x5c] */
/* @0x1c3490 str r11, [r6, #0x58] */
/* @0x1c3494 str r11, [r6, #0x60] */
/* @0x1c3498 str r8, [r6, #0x64] */
/* @0x1c349c str r11, [r6, #0x68] */
/* @0x1c34a0 str r11, [r6, #0x6c] */
/* @0x1c34a4 ldr r3, [r10] */
/* @0x1c34a8 mov r1, #0 */
/* @0x1c34ac add r7, r7, #1 */
/* @0x1c34b0 ldr r2, [r10, #0x8] */
/* @0x1c34b4 cmp r3, r1 */
/* @0x1c34b8 streq r6, [r10, #0x4] */
/* @0x1c34bc strne r6, [r3, #0x6c] */
/* @0x1c34c0 add r2, r2, #1 */
/* @0x1c34c4 streq r3, [r6, #0x6c] */
/* @0x1c34c8 streq r3, [r6, #0x68] */
/* @0x1c34cc strne r3, [r6, #0x68] */
/* @0x1c34d0 ldr r3, [r10, #0x10] */
/* @0x1c34d4 streq r6, [r10] */
/* @0x1c34d8 strne r6, [r10] */
/* @0x1c34dc strne r1, [r6, #0x6c] */
/* @0x1c34e0 cmp r7, r3 */
/* @0x1c34e4 str r2, [r10, #0x8] */
/* @0x1c34e8 blt 0x1c342c <_ZN13CLayerManager15AddDynamicLayerEP5CRoomi+0x48> */
/* @0x1c34ec ldr r7, [r10, #0x8] */
/* @0x1c34f0 lsl r3, r3, #1 */
/* @0x1c34f4 str r3, [r10, #0x10] */
/* @0x1c34f8 ldr r4, [r10] */
/* @0x1c34fc mov lr, #1 */
/* @0x1c3500 ldr r1, [sp, #0x4] */
/* @0x1c3504 sub r7, r7, #1 */
/* @0x1c3508 ldr r0, [sp] */
/* @0x1c350c ldr r3, [r4, #0x6c] */
/* @0x1c3510 ldr r2, [r4, #0x68] */
/* @0x1c3514 cmp r3, #0 */
/* @0x1c3518 str r7, [r10, #0x8] */
/* @0x1c351c strne r2, [r3, #0x68] */
/* @0x1c3520 ldrne r2, [r4, #0x68] */
/* @0x1c3524 ldrne r3, [r4, #0x6c] */
/* @0x1c3528 streq r2, [r10] */
/* @0x1c352c cmp r2, #0 */
/* @0x1c3530 streq r3, [r10, #0x4] */
/* @0x1c3534 strne r3, [r2, #0x6c] */
/* @0x1c3538 ldr r2, [pc, #0x50] */
/* @0x1c353c ldr r3, [pc, #0x50] */
/* @0x1c3540 ldr r2, [pc, r2] */
/* @0x1c3544 str r1, [r4, #0x4] */
/* @0x1c3548 ldr r3, [pc, r3] */
/* @0x1c354c mov r1, r4 */
/* @0x1c3550 ldr r12, [r2] */
/* @0x1c3554 ldr r2, [r3] */
/* @0x1c3558 strb lr, [r4, #0x19] */
/* @0x1c355c cmp r2, r12 */
/* @0x1c3560 movlt r2, r12 */
/* @0x1c3564 add r2, r2, lr */
/* @0x1c3568 str r2, [r3] */
/* @0x1c356c str r2, [r4] */
/* @0x1c3570 bl 0x1c30f8 <_ZN13CLayerManager25InsertLayerIntoActiveListEP5CRoomP6CLayer> */
/* @0x1c3574 mov r0, r4 */
/* @0x1c3578 add sp, sp, #12 */
/* @0x1c357c vpop {d8} */
/* @0x1c3580 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1c3584 andeq r0, r0, r0 */
/* @0x1c3588 eoreq sp, r2, r4, ror #8 */
/* @0x1c358c andseq r10, r8, r0, ror r2 */
/* @0x1c3590 eoreq sp, r2, r0, asr #6 */
/* @0x1c3594 mlaeq r2, r4, r5, sp */

/* ══ §4 CollisionInsert 0x1cc494 ═════════════════════════════════════════
 * @func 0x1cc494 0x1cc4f8 size 108  27 条（25 指令 + 1cc4f8/1cc4fc 两个池字）
 * 级别: 正文（27/27。三段：门 → 懒建树 → 重算 bbox + 挂测试链）
 * 符号: _Z15CollisionInsertP9CInstance → void CollisionInsert(CInstance*)（自由函数，非成员）
 * 同层: CollisionMarkTest 0x1cbfc0（尾调）、CollisionUpdate 0x1cdc1c（Compute_BoundingBox 内部真正插树的地方）、
 *       RTree<CInstance*,int,float,6,2> ctor 0x1cc320、CInstance::Compute_BoundingBox 0x192340
 * 调用者（全图 5 处调用点，函数 → 调用点）：CRoom::AddInstance(float,float,int) → 0x1ab278、
 *   CRoom::AddInstance(float,float,int,int) → 0x1ab428、CRoom::AddInstance(float,float,CLayer*,int) → 0x1ab5e0、
 *   CRoom::AddInstance(CInstance*) → 0x1ab73c（b 尾跳）、CRoom::Assign → 0x1ae0c0
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   「把实例纳入快速碰撞」：确认树存在 → 重算 bbox（顺带把新旧矩形在树里换掉）→ 挂进待测链 s_test_list。
 *   整个函数被 option_use_fast_collision 一个字节控住，关掉时连 bbox 都不重算。
 *
 * ── ① 门（1cc494..1cc4ac）────────────────────────────────────────────────
 *   ldrb [option_use_fast_collision]（0x542379，槽 0x3f0688）；== 0 → popeq 返回。
 *
 * ── ② 懒建 g_tree（1cc4b0..1cc4f4）──────────────────────────────────────
 *   g_tree（0x5429a8，槽 0x3ee24c）== 0 → operator new(24)（0x27c524）→
 *   RTree<CInstance*,int,float,6,2>::RTree(1024)（0x1cc320）→ 存回 g_tree。
 *   1024 是构造的唯一实参（含义见 open；树对象 24 B）。
 *
 * ── ③ Compute_BoundingBox(inst, true)（1cc4c4..1cc4cc）────────────────────
 *   第 2 实参 r1 = 1。它重算 +0xe8..+0xf4 并清 +0x64；updateRTree=true 时调 CollisionUpdate(inst, 旧盒)。
 *   **真正把矩形写进 RTree 的是 CollisionUpdate**（见 Compute_BoundingBox 卡 §12）。它的四道门（0x1cdc2c..0x1cdc6c）：
 *     option_use_fast_collision != 0；inst+0x68 == 0（未销毁）；inst+0x69 == 0（未停用）；
 *     inst+0x80 != 0 且 [obj+0x00] & 0x10（对象标志位 bit4，含义未定）。
 *   任一不满足就返回。⇒ 已停用实例即便走到这里也不会进树，但第 ④ 步仍会把它挂进测试链。
 *
 * ── ④ 尾调 CollisionMarkTest(inst)（1cc4d0..1cc4d8）────────────────────────
 *   CollisionMarkTest 0x1cbfc0：同一 option 门；把 this+0x18c 作为 link 挂到 s_test_list（0x5429b8）**头部**
 *   （先做「若 [this+0x194] == &s_test_list 则按 +0x18c/+0x190 摘链」的 move-to-front，挂完
 *   [this+0x194] = &s_test_list、[this+0x18c] = 旧头、旧头->prev = link）。
 *   ⇒ 尾调（1cc4d8 b），本函数不再有出口代码。
 *
 * ── 字面量池（1cc4f8/1cc4fc，2 字；objdump 译成 eoreq/mlaeq，非指令）────────
 *   1cc4f8 = 0x002241e4 → 槽 0x3f0688 → 0x542379（option_use_fast_collision）
 *   1cc4fc = 0x00221d90 → 槽 0x3ee24c → 0x5429a8（g_tree）
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · RTree ctor 的 1024 是什么（模板参数是 <T,int,float,6,2>，1024 既不像节点容量也不像最小填充；
 *     疑为「rect 预留」）。
 *   · 为什么 bbox 重算（已经含树的新旧替换）之后还要 MarkTest —— 两者写的是不同结构（树 vs 测试链）。
 *   · obj+0x00 bit4 的正式名（CObjectGM 卡只证 bit0 solid / bit1 visible / bit2 persistent）。
 */

/* @0x1cc494 ldr r3, [pc, #0x5c] */
/* @0x1cc498 push {r4, r5, r6, lr} */
/* @0x1cc49c ldr r3, [pc, r3] */
/* @0x1cc4a0 mov r5, r0 */
/* @0x1cc4a4 ldrb r3, [r3] */
/* @0x1cc4a8 cmp r3, #0 */
/* @0x1cc4ac popeq {r4, r5, r6, pc} */
/* @0x1cc4b0 ldr r4, [pc, #0x44] */
/* @0x1cc4b4 ldr r4, [pc, r4] */
/* @0x1cc4b8 ldr r3, [r4] */
/* @0x1cc4bc cmp r3, #0 */
/* @0x1cc4c0 beq 0x1cc4dc <_Z15CollisionInsertP9CInstance+0x48> */
/* @0x1cc4c4 mov r0, r5 */
/* @0x1cc4c8 mov r1, #1 */
/* @0x1cc4cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cc4d0 mov r0, r5 */
/* @0x1cc4d4 pop {r4, r5, r6, lr} */
/* @0x1cc4d8 b 0x1cbfc0 <_Z17CollisionMarkTestP9CInstance> */
/* @0x1cc4dc mov r0, #24 */
/* @0x1cc4e0 bl 0x27c524 <_Znwj> */
/* @0x1cc4e4 mov r1, #1024 */
/* @0x1cc4e8 mov r6, r0 */
/* @0x1cc4ec bl 0x1cc320 <_ZN5RTreeIP9CInstanceifLi6ELi2EEC2Ei> */
/* @0x1cc4f0 str r6, [r4] */
/* @0x1cc4f4 b 0x1cc4c4 <_Z15CollisionInsertP9CInstance+0x30> */
/* @0x1cc4f8 eoreq r4, r2, r4, ror #3 */
/* @0x1cc4fc mlaeq r2, r0, sp, r1 */

/* ══ §5 CollisionRemove 0x1cd9f0 ═════════════════════════════════════════
 * @func 0x1cd9f0 0x1cdb08 size 300  75 条（70 指令 + 1cdb08..1cdb18 五个池字）
 * 级别: 正文（75/75。门 → 矩形构造 → RTree::Remove → 两条侵入链摘除，全部逐条解出）
 * 符号: _Z15CollisionRemoveP9CInstance → void CollisionRemove(CInstance*)
 * 同层: RTree::Remove(const int*,const int*,CInstance* const&,bool) 0x1cd978、
 *       CollisionUpdate 0x1cdc1c（插入侧）、CollisionMarkDirty 0x1cc1d0 / CollisionMarkTest 0x1cbfc0（挂链侧）、
 *       CInstance::~CInstance 0x199320（唯一调用者）
 * 调用者（全图 1 处）：CInstance::~CInstance 0x1993dc —— 物理体/对象/骨架/槽位都拆完之后、基类析构之前。
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   「把实例从快速碰撞里摘掉」：有树就按当前 bbox 从 RTree 删一次；然后把它从 s_dirty_list 与 s_test_list
 *   两条侵入链上摘下来（自环 + 属主清 0）。同样被 option_use_fast_collision 整函数控住。
 *
 * ── ① 门（1cd9f0..1cda14）────────────────────────────────────────────────
 *   option_use_fast_collision（槽 0x3f0688）== 0 → 直接到 1cdb00 出口（连两条链都不摘）。
 *
 * ── ② 从树里删（1cda18..1cda88）──────────────────────────────────────────
 *   g_tree（槽 0x3ee24c）== 0 → 跳过（**不建树**，与 CollisionInsert 的懒建相反），直接去摘链。
 *   否则按 bbox 组矩形，不假定 left<right / top<bottom，各做一次条件存：
 *     [sp+0x10] = min(+0xe8, +0xf0) = xmin     [sp+0x18] = max(...) = xmax
 *     [sp+0x14] = min(+0xec, +0xf4) = ymin     [sp+0x1c] = max(...) = ymax
 *     [sp] = 1（第 4 实参）
 *   r1 = &min(sp+0x10)、r2 = &max(sp+0x18)、r3 = &inst(sp+0xc)，bl RTree::Remove 0x1cd978。
 *   ⚠ 本函数不查 +0x69/+0x68/对象碰撞位：停用实例虽然从没进过树（CollisionUpdate 的门），这里照样调 Remove，
 *     由 RTree 找不到而空转 —— 代价是一次无命中搜索，行为上安全。
 *
 * ── ③ 摘 s_dirty_list（1cda8c..1cdacc）────────────────────────────────────
 *   link = this+0x198（next）、this+0x19c（prev）；属主 = this+0x1a0；全局头 = &s_dirty_list（0x5429ac）。
 *   owner == &s_dirty_list → next->prev = prev、prev->next = next（按 +0x198/+0x19c）。
 *   随后无条件：this+0x198 = this+0x19c = this+0x198（自环）、this+0x1a0 = 0。
 *
 * ── ④ 摘 s_test_list（1cdad0..1cdafc）────────────────────────────────────
 *   link = this+0x18c/+0x190；属主 = this+0x194；全局头 = &s_test_list（0x5429b8）。同构。
 *   ⇒ 与 CollisionMarkTest 0x1cbfc0 / CollisionMarkDirty 0x1cc1d0 的挂链严格互逆：
 *     链节点存的是 link 字段地址（this+0x18c / this+0x198），属主存的是全局链表头地址，不是 this。
 *
 * ── 不写什么 ────────────────────────────────────────────────────────────
 *   +0x188（碰撞网格槽号）、+0x64（bbox 脏位）、bbox 四字段、+0x84（物理体）全都不动。
 *   ⇒ 它只负责「宽相 + 两条队列」，实例的几何/物理清理是调用者（析构）或别处的事。
 *
 * ── 字面量池（1cdb08..1cdb18，5 字）──────────────────────────────────────
 *   1cdb08 = 0x00224250 → add r4,pc 后得 GOT 基址 0x3f1c58（本函数余下所有槽都用它做基）
 *   1cdb0c = 0xffffea30（-0x15d0）→ [0x3f1c58-0x15d0] = 槽 0x3f0688 → option_use_fast_collision
 *   1cdb10 = 0xffffc5f4（-0x3a0c）→ 槽 0x3ee24c → g_tree
 *   1cdb14 = 0xffffeeec（-0x1114）→ 槽 0x3f0b44 → s_dirty_list
 *   1cdb18 = 0xffffeee4（-0x111c）→ 槽 0x3f0b3c → s_test_list
 *   （1cdb0c..1cdb18 在索引里就是 .word；1cdb08 被译成 eoreq，也不是指令。）
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · RTree::Remove 第 4 实参 true 的语义（CollisionUpdate 0x1cdcd8 也传 1；别的调用点未逐一枚举）。
 *   · 两条链的摘除也放在 option 门内：关掉快速碰撞时析构不会清属主。若那两条链只在快速碰撞模式下才有节点，
 *     这是自洽的；「有没有别的写方在非快速模式下挂链」未证。
 *   · s_test_list/s_dirty_list 都是 12 B 结构，第三字（+0x08）在本卡范围内没有读写。
 */

/* @0x1cd9f0 push {r4, r5, r6, r7, lr} */
/* @0x1cd9f4 sub sp, sp, #36 */
/* @0x1cd9f8 ldr r4, [pc, #0x108] */
/* @0x1cd9fc ldr r3, [pc, #0x108] */
/* @0x1cda00 add r4, pc, r4 */
/* @0x1cda04 str r0, [sp, #0xc] */
/* @0x1cda08 ldr r3, [r4, r3] */
/* @0x1cda0c ldrb r3, [r3] */
/* @0x1cda10 cmp r3, #0 */
/* @0x1cda14 beq 0x1cdb00 <_Z15CollisionRemoveP9CInstance+0x110> */
/* @0x1cda18 ldr r3, [pc, #0xf0] */
/* @0x1cda1c ldr r3, [r4, r3] */
/* @0x1cda20 ldr r2, [r3] */
/* @0x1cda24 cmp r2, #0 */
/* @0x1cda28 beq 0x1cda8c <_Z15CollisionRemoveP9CInstance+0x9c> */
/* @0x1cda2c mov r3, r0 */
/* @0x1cda30 ldr r5, [r0, #0xe8] */
/* @0x1cda34 ldr r6, [r3, #0xf0] */
/* @0x1cda38 mov r7, #1 */
/* @0x1cda3c ldr r12, [r3, #0xec] */
/* @0x1cda40 mov r0, r2 */
/* @0x1cda44 ldr lr, [r3, #0xf4] */
/* @0x1cda48 add r1, sp, #16 */
/* @0x1cda4c add r2, sp, #24 */
/* @0x1cda50 add r3, sp, #12 */
/* @0x1cda54 str r7, [sp] */
/* @0x1cda58 cmp r6, r5 */
/* @0x1cda5c strle r6, [sp, #0x10] */
/* @0x1cda60 strgt r5, [sp, #0x10] */
/* @0x1cda64 cmp r6, r5 */
/* @0x1cda68 strge r6, [sp, #0x18] */
/* @0x1cda6c strlt r5, [sp, #0x18] */
/* @0x1cda70 cmp lr, r12 */
/* @0x1cda74 strle lr, [sp, #0x14] */
/* @0x1cda78 strgt r12, [sp, #0x14] */
/* @0x1cda7c cmp lr, r12 */
/* @0x1cda80 strge lr, [sp, #0x1c] */
/* @0x1cda84 strlt r12, [sp, #0x1c] */
/* @0x1cda88 bl 0x1cd978 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6RemoveEPKiS4_RKS1_b> */
/* @0x1cda8c ldr r3, [sp, #0xc] */
/* @0x1cda90 ldr r2, [pc, #0x7c] */
/* @0x1cda94 ldr r12, [pc, #0x7c] */
/* @0x1cda98 add r1, r3, #408 */
/* @0x1cda9c ldr r0, [r3, #0x1a0] */
/* @0x1cdaa0 ldr r2, [r4, r2] */
/* @0x1cdaa4 cmp r0, r2 */
/* @0x1cdaa8 ldreq r0, [r3, #0x19c] */
/* @0x1cdaac ldreq r2, [r3, #0x198] */
/* @0x1cdab0 streq r0, [r2, #0x4] */
/* @0x1cdab4 ldreq r0, [r3, #0x19c] */
/* @0x1cdab8 streq r2, [r0] */
/* @0x1cdabc mov r0, #0 */
/* @0x1cdac0 str r1, [r3, #0x198] */
/* @0x1cdac4 add r2, r3, #396 */
/* @0x1cdac8 str r0, [r3, #0x1a0] */
/* @0x1cdacc str r1, [r3, #0x19c] */
/* @0x1cdad0 ldr r0, [r3, #0x194] */
/* @0x1cdad4 ldr r1, [r4, r12] */
/* @0x1cdad8 cmp r0, r1 */
/* @0x1cdadc ldreq r1, [r3, #0x18c] */
/* @0x1cdae0 ldreq r0, [r3, #0x190] */
/* @0x1cdae4 streq r0, [r1, #0x4] */
/* @0x1cdae8 ldreq r0, [r3, #0x190] */
/* @0x1cdaec streq r1, [r0] */
/* @0x1cdaf0 mov r1, #0 */
/* @0x1cdaf4 str r2, [r3, #0x18c] */
/* @0x1cdaf8 str r2, [r3, #0x190] */
/* @0x1cdafc str r1, [r3, #0x194] */
/* @0x1cdb00 add sp, sp, #36 */
/* @0x1cdb04 pop {r4, r5, r6, r7, pc} */
/* @0x1cdb08 eoreq r4, r2, r0, asr r2 */
/* @0x1cdb0c .word 0xffffea30 */
/* @0x1cdb10 .word 0xffffc5f4 */
/* @0x1cdb14 .word 0xffffeeec */
/* @0x1cdb18 .word 0xffffeee4 */

/* ══ §6 CInstance::SetDeactivated 0x19230c ════════════════════════════════
 * @func 0x19230c 0x192338 size 52  13 条（11 指令 + 192338/19233c 两个池字）
 * 级别: 正文（13/13。两条路只有一个分叉点：ldrb g_isZeus + cmp + bxeq）
 * 符号: _ZN9CInstance14SetDeactivatedEb → void CInstance::SetDeactivated(bool)
 * 同层: CLayerManager::UpdateInstanceActivation 0x1b8a28（路 2 的尾调）、CLayerManager::GetLayerFromID 0x1b8868、
 *       DrawRoomLayers（读 +0x69 的地方）、instance_activate_all/object 等 15 处调用点
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   先把 this+0x69 无条件写成实参；然后看全局字节 g_isZeus：为 0 就地返回（纯写一个字节），
 *   非 0 就把 (Run_Room, this) 尾调给 UpdateInstanceActivation，让层里的元素重新排到头/尾。
 *
 * ── 路 1：g_isZeus == 0（1 条写 + 直接 bxeq lr）──────────────────────────
 *   0x192310 strb r1,[r0,#0x69]            ← 无条件，先写
 *   0x192314..0x192320 读 g_isZeus（槽 0x3ed92c → 0x5428e8）；== 0 → bxeq lr
 *   ⇒ 停用位生效，但层链表顺序由别人维护（谁、何时，本卡未证）。
 *
 * ── 路 2：g_isZeus != 0（写 + 尾调）──────────────────────────────────────
 *   0x192324..0x192330 r0 = *(Run_Room)（槽 0x3ed930 → 0x54298c，CRoom*）
 *   0x192328           r1 = this
 *   0x192334           b 0x1b8a28（尾调用，本函数无栈帧、无 pop）
 *   ⇒ **room 不是入参**，是全局 Run_Room；本函数只有一个 bool 形参。
 *   ⇒ Run_Room 为 0 时 UpdateInstanceActivation 会在 room == 0 的门上直接返回（1b8a48），不会炸。
 *
 * ── 路 2 的实际效果：UpdateInstanceActivation 0x1b8a28（468 B，逐段已解）────────
 *   门：g_isZeus != 0（同一字节，1b8a28..1b8a44）→ room != 0 → inst != 0 → inst+0x174 != 0。
 *   GetLayerFromID(room, inst+0x170)（1b8a64/1b8a68），0 → 返回。
 *   以 inst+0x78 查表 3（room+0x118 掩码/+0x120 桶，1b8a74..1b8b30），取桶 +0x04 得 elem，空 → 返回。
 *   要求 elem+0x10 != 0（1b8b38；= 所属 CLayer*，AddElementToLayer 1c45b0 写、RemoveInstanceElement 清 0），否则返回。
 *   按 elem+0x14(next)/+0x18(prev) 从层链摘下、layer+0x60 -= 1（1b8b44..1b8b7c）。
 *   按 inst+0x69 二选一：
 *     非 0（停用）→ **尾插**：接到 layer+0x5c 链尾（1b8b84..1b8bbc）
 *     为 0（恢复）→ **头插**：接到 layer+0x58 链头（1b8bc0..1b8bf4）
 *   layer+0x60 写回摘链前的值（净变化 0）。
 *   ⇒ 语义 = 「把这个实例的元素按停用位重新排到层链的头/尾」，不增删元素、不动表。
 *
 * ── 为什么顺序要紧（跨卡，行为事实）──────────────────────────────────────
 *   DrawRoomLayers 卡实测：type 2 元素遇到 +0x69 != 0 不是「跳过该元素」，而是**跳出整层元素循环**
 *   （1b3abc 读 elem+0x20 → 1b3a18 走本层出口）。⇒ 停用元素必须排在层链尾端，否则它后面的元素全部不画。
 *   这就是 AddElementToLayer「停用 → 尾插」与 UpdateInstanceActivation「停用 → 挪尾」的存在理由。
 *   路 1（g_isZeus == 0）只改字节不重排 —— 那条路上停用实例的顺序谁维护，本卡未证（记 open）。
 *
 * ── 字面量池（192338/19233c，2 字）──────────────────────────────────────
 *   192338 = 0x0025b610 → 槽 0x3ed92c → 0x5428e8（g_isZeus）
 *   19233c = 0x0025b5fc → 槽 0x3ed930 → 0x54298c（Run_Room）
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · g_isZeus 的语义与写方：三个层入口（AddInstance 0x1c5d18、UpdateInstanceActivation、本函数）都要求它 != 0；
 *     CLayerManager_AddInstance 卡正文说「非 0 → 直接返回」，与机器码 popeq 相反（claims 单列纠正）。
 *     合理的读法是「它非 0 才启用层系统」，但为什么符号叫 Zeus（调试器）未证。
 *   · 路 1 下停用元素的顺序维护者；DrawRoomLayers 的 break 语义是不是有意（那张卡已记 open）。
 *   · UpdateInstanceActivation 要求 elem 在表 3 里（键是实例 id，不是 uid），所以表 3 被 RemoveElement 删掉后
 *     这次重排会直接返回 —— 「先删表再改停用位」的时序后果未证。
 */

/* @0x19230c ldr r3, [pc, #0x24] */
/* @0x192310 strb r1, [r0, #0x69] */
/* @0x192314 ldr r3, [pc, r3] */
/* @0x192318 ldrb r3, [r3] */
/* @0x19231c cmp r3, #0 */
/* @0x192320 bxeq lr */
/* @0x192324 ldr r3, [pc, #0x10] */
/* @0x192328 mov r1, r0 */
/* @0x19232c ldr r3, [pc, r3] */
/* @0x192330 ldr r0, [r3] */
/* @0x192334 b 0x1b8a28 <_ZN13CLayerManager24UpdateInstanceActivationEP5CRoomP9CInstance> */
/* @0x192338 eoreq r11, r5, r0, lsl r6 */
/* @0x19233c .word 0x0025b5fc */

/* ══ §7 CInstance::RebuildPhysicsBody 0x192fa4 ════════════════════════════
 * @func 0x192fa4 0x192fec size 72  18 条（18 指令，无字面量池）
 * 级别: 正文（18/18。拆旧 → 门 → 建新 三段，无循环）
 * 符号: _ZN9CInstance18RebuildPhysicsBodyEP5CRoom → void CInstance::RebuildPhysicsBody(CRoom*)
 * 同层: CPhysicsWorld::DestroyBody 0x238c08、CInstance::CreatePhysicsBody 0x192cd4、
 *       CPhysicsWorld::CreateBody 0x23894c（真正写 +0x84 的地方）、CInstance::Assign 0x1986ec（不搬 +0x84）
 * 调用者（全图 3 处）：CInstance::ChangeObjectIndex 0x19346c、StartRoom 0x1d3b40 / 0x1d3e70
 *   （StartRoom 两处都紧跟在 CInstance::Assign 之后 —— Assign 卡：+0x84 既不拷贝也不重建）
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   物理体重建：先按 room 的物理世界销毁旧体并清 +0x84，再看对象的「物理开关」字节，开就尾调 CreatePhysicsBody。
 *
 * ── ① 拆旧（192fa4..192fc8）──────────────────────────────────────────────
 *   body = this+0x84；非 0 → CPhysicsWorld::DestroyBody(room+0xb4, body)（r0 = 世界、r1 = 体），
 *   然后 this+0x84 = 0。
 *   room+0xb4 = CPhysicsWorld*：CRoom::LoadFromChunk 0x1af1ec 在同字段上 SetGravity、CRoom::Assign 0x1ada8c
 *   用 488 B operator new + CPhysicsWorld(CRoom*) 建它。
 *
 * ── ② 门（192fcc..192fd8）────────────────────────────────────────────────
 *   obj = this+0x80（CObjectGM*）；obj+0x1c 是字节，== 0 → popeq 返回。
 *   ⚠ **不判 obj 是否为空**：`ldr r3,[r4,#0x80]; ldrb r3,[r3,#0x1c]`。
 *     CreatePhysicsBody 0x192ce8..0x192d0c 是判的（+0x80 非空且 [obj+0x1c] != 0 才继续）。
 *     ⇒ 本函数的调用前提是实例已解析对象；否则这里是空指针解引用。
 *
 * ── ③ 建新（192fdc..192fe8）──────────────────────────────────────────────
 *   r0 = this、r1 = room，pop {r3,r4,r5,lr} 后 b 0x192cd4（尾调 CreatePhysicsBody）。
 *   CreatePhysicsBody 的完整门：+0x80 非空 → obj+0x1c != 0 → Sprite_Exists(this+0x8c) → room+0xb4 != 0；
 *   然后 CPhysicsFixtureFactory::CreateFixture + 逐点 SetPolygonShape/AddShapePoint，最后
 *   CPhysicsWorld::CreateBody(fixture, this, x, y)。
 *   真正把体写回 +0x84 的是 CreateBody 里的 0x238ba4（str r6,[r4,#0x84]），不是 CreatePhysicsBody 自己。
 *   同一个 CreateBody 在 [+0x84] 已存在时**不新建体**，而是给旧体 CreateFixture（0x2389c8..0x2389e4）——
 *   所以本函数必须先 DestroyBody，否则「重建」会退化成「加形状」。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · obj+0x1c 的正式名：CObjectGM 卡把它列为 LoadFromChunk 写区首字节之一（+0x1c/+0x1d 是字节，
 *     0x19d73c..0x19d7dc），CreatePhysicsBody 用它当「要不要物理体」的唯一开关。
 *   · room+0xb4 为空而 +0x84 非空时会拿空 world 调 DestroyBody（本卡只证不判空）。
 *   · ChangeObjectIndex 0x193368 调本函数的上下文（换对象索引后重建）未逐行读。
 */

/* @0x192fa4 push {r3, r4, r5, lr} */
/* @0x192fa8 mov r5, r1 */
/* @0x192fac ldr r1, [r0, #0x84] */
/* @0x192fb0 mov r4, r0 */
/* @0x192fb4 cmp r1, #0 */
/* @0x192fb8 beq 0x192fcc <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom+0x28> */
/* @0x192fbc ldr r0, [r5, #0xb4] */
/* @0x192fc0 bl 0x238c08 <_ZN13CPhysicsWorld11DestroyBodyEP14CPhysicsObject> */
/* @0x192fc4 mov r3, #0 */
/* @0x192fc8 str r3, [r4, #0x84] */
/* @0x192fcc ldr r3, [r4, #0x80] */
/* @0x192fd0 ldrb r3, [r3, #0x1c] */
/* @0x192fd4 cmp r3, #0 */
/* @0x192fd8 popeq {r3, r4, r5, pc} */
/* @0x192fdc mov r0, r4 */
/* @0x192fe0 mov r1, r5 */
/* @0x192fe4 pop {r3, r4, r5, lr} */
/* @0x192fe8 b 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
