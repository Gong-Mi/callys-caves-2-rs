/* cally 逆向卡：层移除三件（原版 libyoyo.so，armv7）—— 一卡三节
 * @func 三节按地址升序，逐节自带 @func 头与逐条锚点：
 *   §1 0x1b8fdc CLayerManager::RemoveElement             size 1004   251 行（全指令）
 *   §2 0x1b95d8 CLayerManager::RemoveLayer               size  836   209 行（208 指令 + 1 池字）
 *   §3 0x1b991c CLayerManager::RemoveInstanceFromLayer   size 1344   336 行（333 指令 + 3 池字）
 * 总账: 796 锚点 = 792 条指令 + 4 个字面量池字（1b9918 / 1b9e50 / 1b9e54 / 1b9e58），
 *       与 asm/index-LayerRemove_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py → index=796 card=796 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 *       ⇒ 三个函数共 3184 B = 1344 + 1004 + 836，无一条指令漏锚。
 * 级别: 正文（三节都逐条解码到控制流 / 字段写点 / 算式 / 跳表；每节末尾单列本节 open，
 *       没钉的地方不冒充已钉。tier = bytecode_anchored）
 * 锚点来源: 全部由 asm_index.py 从二进制生成，本卡未手写转录。四个池字保留 objdump 的写法
 *       （strhteq / andseq / eoreq×2，其中 1b9e50 被译成 .word），在各节注释里逐字标「非指令」。
 *
 * ── 全局坐标（本轮按 .rel.dyn（R_ARM_RELATIVE=23）槽内 addend 直读 + .symtab 实测）──
 *   GOT 槽      目标        符号（.symtab 原名）                        本卡用处
 *   0x3f0864 → 0x5426a0   CLayerManager::m_LayerPool（20 B）            §2 回池
 *   0x3f086c → 0x542678   CLayerManager::m_InstanceElementPool（20 B）  §3 回池
 *   0x3ed71c → 0x3eb70c   dbg_csol（4 B 指针，值 0x47a118 = _dbg_csol，.bss） §3 诊断宿主
 *   ⇒ 前两条与 LayerHelpers 卡、AddInstanceToLayer 卡同槽独立吻合；dbg_csol 与 AddInstanceToLayer 卡的
 *     报错槽 0x3ed718（宿主 0x479a94）只差 4 B，是**两个不同宿主对象**，别混用。
 *   串 0x34d6d0 = "Layer system integrity compromised, instance %d not on layer %d\n"
 *      （同一 .rodata 段里紧邻 "jni/../jni/yoyo/../../../Files/Room/Room_Layers.h" 源路径串）
 *
 * ── 房间三张 CHashMap（本卡三节全部踩到；每簇 20 B：+0x00 容量 / +0x04 已用 / +0x08 掩码 /
 *    +0x0c 阈值 / +0x10 桶，桶项 12 B = {+0x00 键(int) / +0x04 值(指针) / +0x08 31 位哈希}，
 *    布局以 AddInstanceToLayer 卡为准，本卡三处探测/删除全部与之一致）──
 *   表 1 @ room+0xe4   键 layer->id(+0x00)    值 CLayer*                 §2 ④ 删
 *   表 2 @ room+0xf8   键 elem->uid(+0x04)    值 CLayerElementBase*      §1 ② / §3 ④ 删
 *   表 3 @ room+0x110  键 elem->inst(+0x1c)   值 CLayerInstanceElement*  §1 ⑤(type2) / §3 ②⑤ 查+删
 *   另：room+0x10c = GetElementFromID 0x1bc2a0 的「最后查到的元素」单条缓存（1bc2b0..1bc2c4 命中即返回、
 *       1bc394..1bc39c 查到即回写、1bc3a4 直接用缓存答 out-layer）。§1/§3 摘掉元素时都会在相等时清 0。
 *
 * ── 跨节结论（本题五个重点）──────────────────────────────────────────────
 *   A. 移除与添加的对称性（§3 详表）：Add 侧 AddInstanceToLayer 0x1c5a38 是「出池 → 填字段 → 回写实例三字段
 *      → 尾调 AddElementToLayer 0x1c451c（那里才插链、插表 2、插表 3）」；移除侧被拆成三只：
 *        · RemoveElement（§1）        = 摘表 2 / 摘表 3 / 清缓存 / 清运行期数据 → 尾跳族回收器
 *        · RemoveInstanceElement      = 摘链 / 回 36 B 池 / 清实例 +0x170,+0x174 /（可选）销毁实例
 *        · RemoveInstanceFromLayer（§3）= 自己把上面两件事都做一遍（不销毁实例、不清运行期数据）
 *      ⇒ **同一个语义有两条实现**：通用路走 RemoveElement(…,b)+族回收器；按实例的快捷路走 §3。
 *        两条路的字段终值逐项相同（§3 末表），差别只有「谁清 CleanElementRuntimeData」和「谁销毁实例」。
 *   B. 层删除时的元素清理（§2 ②⑥）：先 `while (layer+0x58) RemoveElement(room, layer, head, true)` 把
 *      每个元素按族回收（type 2 顺带 DoInstanceDestroy 硬销毁实例），**然后**才摘层链、删表 1、放名字；
 *      末尾还有一段按 layer+0x64 的残余元素回收（1/2/3 三档），但正常路径下链已空，是死块（§2 ⑥）。
 *   C. 三张表的分工：表 2/表 3 在 §1（元素级），表 1 在 §2（层级）；§3 自己同时删表 2 和表 3 但不碰表 1。
 *      ⇒ 想看「元素销号」只看 §1；想看「层销号」只看 §2 ④；§3 是两者的合并快捷路。
 *   D. 两条自动删层的收尾：§3 ⑧（layer+0x19 != 0 且 layer+0x60 == 0 → 尾跳 RemoveLayer(room, layer->id, -1)）
 *      与四实参重载 RemoveElement 0x1c013c（b1 != 0 且同两条 → RemoveLayer(room, layer->id, 0)）是同一策略的
 *      两个入口：**最后一个元素离开动态层时，层自己消失**。两者传的第 3 实参一个是 -1 一个是 0 —— 因为
 *      RemoveLayer 根本不读它（§2 ⑧）。
 *   E. 池协议的移除侧：层池 112 B 用 +0x68/+0x6c 串自由链（§2），元素池 36 B 用 +0x14/+0x18（§3），
 *      与 Add 侧的取方用**同一对偏移**，且回池时都把「链指针 + 类型 + uid + 属层/属实例」写回初值。
 *
 * ── 汇总 open（各节还有细项）──
 *   · 内联回移删除（三个函数里共 5 处副本）的逐位规则只证到「命中后把后续同簇条目向前搬、末槽哈希清 0、
 *     已用数 -1」，没有逐条还原「哪些条目算同簇」。CHashMapCalculateHash 0x1b6e44 的算法未读。
 *   · 三处探测都只比桶项 +0x08 的 31 位哈希，**不重比 +0x00 的键**（三个函数里没有任何一处读桶项的键）。
 *     键碰撞时会不会被当成同一条，取决于写方（AddElementToLayer）是否也用哈希当键，本卡不证全局契约。
 *   · layer+0x64 的枚举名（1/2/3）、layer+0x19 的正式名（LayerHelpers 卡叫「动态层筛子」）、
 *     elem+0x0c 的语义（§1/§3 之外的写方未知）。
 *   · type ∉ 1..7 的元素：§1 ④ 默认分支直接返回、不摘链 ⇒ §2 ② 的 while 会原地死循环（控制流推论，未实测）。
 *   · 七个族回收器内部只抽检了 RemoveBackgroundElement / RemoveTileElement 的摘链五条写点，未逐条读。
 */

/* ══ §1 CLayerManager::RemoveElement 0x1b8fdc ═════════════════════════════
 * @func 0x1b8fdc 0x1b93c8 size 1004  251 条（251 指令，无字面量池）
 * 级别: 正文（251/251。两处门、表 2 内联删除、缓存清 0、CleanElementRuntimeData 调用、七路 type 跳表全部钉住。
 *       未钉：内联回移删除的逐位规则、CHashMapCalculateHash 算法、七个族回收器内部）
 * 符号: _ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb
 *       → void CLayerManager::RemoveElement(CRoom* room, CLayer* layer, CLayerElementBase* elem, bool bDestroy)
 * 同层: 同名四实参重载 RemoveElement(CRoom*,int,bool,bool) 0x1c013c（唯一外部调用者：先 GetElementFromID
 *       0x1bc2a0 解出 elem 与属层，再进来；第 3 实参非 0 且层空且 +0x19 → 调 RemoveLayer）、
 *       RemoveLayer 0x1b95d8（层删除时逐个调，b=1）、CleanRoomLayers 0x1b93c8（房间清理时调）、
 *       CleanElementRuntimeData 0x1b8ed0、七个族回收器：
 *       RemoveBackgroundElement 0x1b7a04 / RemoveInstanceElement 0x1b7ac4 / RemoveOldTilemapElement 0x1b7bac /
 *       RemoveSpriteElement 0x1b7cf8 / RemoveTilemapElement 0x1b7dcc / RemoveParticleElement 0x1b7ec0 /
 *       RemoveTileElement 0x1b7f64
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   元素销号的总入口：按 elem->uid 从表 2 摘桶、按 elem->inst 从表 3 摘桶（只对 type 2）、清 room+0x10c 缓存、
 *   清运行期数据，再把元素交给它自己那一族的回收器（pop 后尾跳，本函数不返回）。
 *   **本函数不回池、不改实例字段、不摘层链** —— 这三件事在族回收器里（type 2 是 RemoveInstanceElement）。
 *
 * ── ① 两处门（1b8fe0..1b9004）────────────────────────────────────────────
 *   `cmp r2,#0`（elem）`cmpne r1,#0`（layer）：两者任一为 0 → add sp/pop 返回，无任何副作用。
 *   ⚠ **不判 room**：r0 直接进 r11 供后面 `[r11+0x100]` 解引用。
 *   ⚠ r4 被写成 0（两参都非 0）或 1（有参为 0）—— 这是个死值，后面 r4 被复用成探测计数器。
 *   三个实参先落栈：[sp+8] = layer、[sp+4] = elem、[sp+0x10] = bDestroy（后面尾跳时按这三格取回）。
 *
 * ── ② 表 2 摘桶（1b9010..1b90a4 + 命中后 1b9100..1b91b8）───────────────
 *   键 = elem+0x04（uid）。哈希 CHashMapCalculateHash 0x1b6e44 → `bic r0,r0,#-2147483648`（清符号位得
 *   31 位正哈希）→ 桶下标 = (h & room+0x100)，桶项地址 = room+0x108 + 12*idx（`r3*3*4`）。
 *   三态：桶项 +0x08 == 0（空桶）→ 直接跳 1b90a8（**不删表也照样往下走**）；
 *         +0x08 == h → 命中，跳 1b9100 进内联回移删除；
 *         不等 → 用 `(idx + room+0xf8容量) - (对方哈希 & 掩码)` 与掩码做 tst（1b9050..1b905c），
 *         符号位为 0 就继续扫描，否则判定「不在表里」跳 1b90a8。
 *   删除段：从命中槽起，把后面同簇的条目逐槽回移（三个字段一起搬：+0x00 键、+0x04 值、+0x08 哈希），
 *   末槽 +0x08 清 0，`room+0xfc`（已用数）-1（1b91a0..1b91b4）。淘汰/结束槽由 1b91bc 处理（把 idx 交给回移尾）。
 *   ⇒ 这是 20 B 簇的「开放寻址 + 回移压缩」删除，不是墓碑标记。
 *
 * ── ③ 缓存与运行期数据（1b90a8..1b90c0）────────────────────────────────
 *   if (room+0x10c == elem) room+0x10c = 0 —— 摘掉 GetElementFromID 的单条缓存；
 *   然后 CleanElementRuntimeData(elem) 0x1b8ed0（清元素挂的运行期句柄；其内部对 +0x20/+0x1c 的处理见
 *   RemoveInstanceElement 卡 §open）。这两步在**找不到表项时也会执行**（三态汇合点就在 1b90a8）。
 *
 * ── ④ type 跳表（1b90c4..1b90f4）────────────────────────────────────────
 *   r3 = elem->type - 1；type == 0 或 type > 7（r3 > 6）→ 跳 1b9008 直接返回（**既不摘链也不回收**）；
 *   否则 `addls pc, pc, r3, lsl #2`，表项在 1b90dc..1b90f4（pc 基址 1b90dc）：
 *     type 1 → 1b91d8 尾跳 RemoveBackgroundElement
 *     type 2 → 1b91ec 表 3 摘桶后尾跳 RemoveInstanceElement
 *     type 3 → 1b92a4 尾跳 RemoveOldTilemapElement
 *     type 4 → 1b92e0 尾跳 RemoveSpriteElement
 *     type 5 → 1b92b8 尾跳 RemoveTilemapElement
 *     type 6 → 1b92cc 尾跳 RemoveParticleElement
 *     type 7 → 1b91c4 尾跳 RemoveTileElement
 *   七个出口的形状完全一致：`ldr r0,[sp+8]`（layer）/`ldr r1,[sp+4]`（elem）→ `add sp,#28` → pop 到 lr → `b`。
 *   ⚠ 尾跳前把 sp 还原并 pop 掉自己的栈帧，所以族回收器看到的是「本函数的调用者」的栈 —— 族回收器返回时
 *     直接回到 RemoveElement 的调用者。
 *
 * ── ⑤ type 2 专段（1b91ec..1b93bc）──────────────────────────────────────
 *   键 = elem+0x1c（实例 id）→ 31 位哈希 → 桶下标 = (h & room+0x118)，桶项 = room+0x120 + 12*idx。
 *   探测三态与 ② 同构（空桶/命中/越距），删除段也同构（回移 + 末槽清 0 + `room+0x114` 已用数 -1）。
 *   然后 1b928c 取三个落栈实参，尾跳 RemoveInstanceElement(layer, elem, bDestroy)。
 *   ⇒ 表 3 的桶在 type 2 上是「自己删」，在其它 type 上不该存在（键 elem+0x1c 只对实例元素有意义）。
 *
 * ── 与添加侧对称（对照 AddElementToLayer 0x1c451c / AddInstanceToLayer 0x1c5a38）──
 *   Add 侧：插链（head/tail 由 inst+0x69 决定头插还是尾插）+ 插表 2（键 uid）+ 插表 3（键 inst id）。
 *   Remove 侧：摘表 2（本函数 ②）+ 摘表 3（本函数 ⑤，仅 type 2）+ 族回收器摘链。
 *   ⇒ 表 2 对所有 type 都删，表 3 只对 type 2 删 —— 因为表 3 的键（实例 id）只有实例元素有。
 *
 * ── 四个实参的重载 0x1c013c（本函数唯一的卡外入口，30 条）─────────────────
 *   RemoveElement(CRoom* room, int elemId, bool b1, bool b2)：
 *     room == 0 → 返回；`str 0,[sp,#4]` 先给 out 层指针一个 0 → GetElementFromID(room, elemId, &layer)；
 *     elem == 0 → 返回；本函数(room, layer, elem, b2)；
 *     b1 != 0 && layer+0x19 != 0 && layer+0x60 == 0 → RemoveLayer(room, layer->id, 0)  ← 与 §3 ⑧ 同策略
 *   ⇒ b2 = 往下传的 bDestroy，b1 = 「若删空了动态层就顺手删层」。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 回移删除只证到「搬三字段 / 清末槽哈希 / 已用 -1」，同簇判定（tst …掩码）的逐位含义未还原。
 *   · 三处探测全都不重比 +0x00 的键 ⇒ 「两个不同 uid 落到同一 31 位哈希」时会被当成同一条。
 *     理论上需要 CHashMapCalculateHash 有碰撞才发生；本卡不证碰撞率，也不证写方是否同样只比哈希。
 *   · elem+0x0c：本函数不碰，各族回收器会清 0；全仓未见非 0 写方（LayerHelpers 卡同结论）。
 *   · type 0 / > 7：默认分支直接返回，元素既留在链上也留在表里 —— 这种元素从哪来（构造期没有 type 0 的池）。
 *   · 七个族回收器内部未逐条读（只抽检了 type 1/type 7 的摘链五条写点，见 §2 ② 的注）。
 */

/* ── ① 两处门：elem == 0 || layer == 0 直接返回（不判 room）── */
/* @0x1b8fdc push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b8fe0 cmp r2, #0 */
/* @0x1b8fe4 cmpne r1, #0 */
/* @0x1b8fe8 sub sp, sp, #28 */
/* @0x1b8fec mov r11, r0 */
/* @0x1b8ff0 movne r4, #0 */
/* @0x1b8ff4 moveq r4, #1 */
/* @0x1b8ff8 str r1, [sp, #0x8] */
/* @0x1b8ffc str r2, [sp, #0x4] */
/* @0x1b9000 str r3, [sp, #0x10] */
/* @0x1b9004 bne 0x1b9010 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x34> */
/* @0x1b9008 add sp, sp, #28 */
/* @0x1b900c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ② 表 2 摘桶：键 elem+0x04，簇 room+0xf8（掩码 +0x100 / 桶 +0x108 / 已用 +0xfc）── */
/* @0x1b9010 ldr r0, [r2, #0x4] */
/* @0x1b9014 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9018 ldr r2, [r11, #0x100] */
/* @0x1b901c ldr r12, [r11, #0x108] */
/* @0x1b9020 bic r0, r0, #-2147483648 */
/* @0x1b9024 and r3, r0, r2 */
/* @0x1b9028 lsl r1, r3, #1 */
/* @0x1b902c add lr, r1, r3 */
/* @0x1b9030 add lr, r12, lr, lsl #2 */
/* @0x1b9034 ldr lr, [lr, #0x8] */
/* @0x1b9038 cmp lr, #0 */
/* @0x1b903c beq 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9040 cmp r0, lr */
/* @0x1b9044 beq 0x1b9100 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x124> */
/* @0x1b9048 ldr r6, [r11, #0xf8] */
/* @0x1b904c and lr, r2, lr */
/* @0x1b9050 add r1, r3, r6 */
/* @0x1b9054 rsb lr, lr, r1 */
/* @0x1b9058 tst lr, r2 */
/* @0x1b905c bpl 0x1b9074 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x98> */
/* @0x1b9060 b 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9064 cmp r0, lr */
/* @0x1b9068 beq 0x1b90f8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x11c> */
/* @0x1b906c cmp r5, r4 */
/* @0x1b9070 blt 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9074 add r3, r3, #1 */
/* @0x1b9078 add r4, r4, #1 */
/* @0x1b907c and r3, r2, r3 */
/* @0x1b9080 add r7, r3, r6 */
/* @0x1b9084 lsl r1, r3, #1 */
/* @0x1b9088 add lr, r1, r3 */
/* @0x1b908c add lr, r12, lr, lsl #2 */
/* @0x1b9090 ldr lr, [lr, #0x8] */
/* @0x1b9094 and r5, r2, lr */
/* @0x1b9098 cmp lr, #0 */
/* @0x1b909c rsb r5, r5, r7 */
/* @0x1b90a0 and r5, r5, r2 */
/* @0x1b90a4 bne 0x1b9064 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x88> */
/* ── ③ room+0x10c 缓存相等则清 0，再 CleanElementRuntimeData(elem) ── */
/* @0x1b90a8 ldr r3, [r11, #0x10c] */
/* @0x1b90ac ldr r1, [sp, #0x4] */
/* @0x1b90b0 ldr r0, [sp, #0x4] */
/* @0x1b90b4 cmp r3, r1 */
/* @0x1b90b8 moveq r3, #0 */
/* @0x1b90bc streq r3, [r11, #0x10c] */
/* @0x1b90c0 bl 0x1b8ed0 <_ZN13CLayerManager23CleanElementRuntimeDataEP17CLayerElementBase> */
/* ── ④ 按 type-1 七路跳表分派：1b90dc..1b90f4 是表项，全部 pop 后尾跳族回收器 ── */
/* @0x1b90c4 ldr r2, [sp, #0x4] */
/* @0x1b90c8 ldr r3, [r2] */
/* @0x1b90cc sub r3, r3, #1 */
/* @0x1b90d0 cmp r3, #6 */
/* @0x1b90d4 addls pc, pc, r3, lsl #2 */
/* @0x1b90d8 b 0x1b9008 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2c> */
/* @0x1b90dc b 0x1b91d8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1fc> */
/* @0x1b90e0 b 0x1b91ec <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x210> */
/* @0x1b90e4 b 0x1b92a4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2c8> */
/* @0x1b90e8 b 0x1b92e0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x304> */
/* @0x1b90ec b 0x1b92b8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2dc> */
/* @0x1b90f0 b 0x1b92cc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2f0> */
/* @0x1b90f4 b 0x1b91c4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e8> */
/* @0x1b90f8 cmn r3, #1 */
/* @0x1b90fc beq 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b9100 add r5, r3, #1 */
/* @0x1b9104 and r5, r5, r2 */
/* @0x1b9108 add r4, r5, r5, lsl #1 */
/* @0x1b910c add r4, r12, r4, lsl #2 */
/* @0x1b9110 ldr lr, [r4, #0x8] */
/* @0x1b9114 cmp lr, #0 */
/* @0x1b9118 beq 0x1b91bc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e0> */
/* @0x1b911c ldr r7, [r11, #0xf8] */
/* @0x1b9120 and r0, r2, lr */
/* @0x1b9124 add r6, r5, r7 */
/* @0x1b9128 rsb r0, r0, r6 */
/* @0x1b912c tst r0, r2 */
/* @0x1b9130 strne r11, [sp, #0xc] */
/* @0x1b9134 movne r11, r7 */
/* @0x1b9138 bne 0x1b914c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x170> */
/* @0x1b913c b 0x1b91bc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1e0> */
/* @0x1b9140 tst r9, r2 */
/* @0x1b9144 beq 0x1b9198 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1bc> */
/* @0x1b9148 mov r5, r0 */
/* @0x1b914c add r7, r1, r3 */
/* @0x1b9150 add r0, r5, #1 */
/* @0x1b9154 and r0, r0, r2 */
/* @0x1b9158 ldr r8, [r4, #0x4] */
/* @0x1b915c add r6, r12, r7, lsl #2 */
/* @0x1b9160 add r9, r0, r11 */
/* @0x1b9164 add r10, r0, r0, lsl #1 */
/* @0x1b9168 mov r3, r5 */
/* @0x1b916c str lr, [r6, #0x8] */
/* @0x1b9170 lsl r1, r5, #1 */
/* @0x1b9174 ldr r4, [r4] */
/* @0x1b9178 str r4, [r12, r7, lsl #2] */
/* @0x1b917c add r4, r12, r10, lsl #2 */
/* @0x1b9180 ldr lr, [r4, #0x8] */
/* @0x1b9184 str r8, [r6, #0x4] */
/* @0x1b9188 cmp lr, #0 */
/* @0x1b918c and r7, r2, lr */
/* @0x1b9190 rsb r9, r7, r9 */
/* @0x1b9194 bne 0x1b9140 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x164> */
/* @0x1b9198 ldr r11, [sp, #0xc] */
/* @0x1b919c add r5, r5, r5, lsl #1 */
/* @0x1b91a0 ldr r3, [r11, #0xfc] */
/* @0x1b91a4 mov r2, #0 */
/* @0x1b91a8 add r12, r12, r5, lsl #2 */
/* @0x1b91ac sub r3, r3, #1 */
/* @0x1b91b0 str r2, [r12, #0x8] */
/* @0x1b91b4 str r3, [r11, #0xfc] */
/* @0x1b91b8 b 0x1b90a8 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0xcc> */
/* @0x1b91bc mov r5, r3 */
/* @0x1b91c0 b 0x1b919c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x1c0> */
/* @0x1b91c4 ldr r0, [sp, #0x8] */
/* @0x1b91c8 ldr r1, [sp, #0x4] */
/* @0x1b91cc add sp, sp, #28 */
/* @0x1b91d0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b91d4 b 0x1b7f64 <_ZN13CLayerManager17RemoveTileElementEP6CLayerP17CLayerTileElement> */
/* @0x1b91d8 ldr r0, [sp, #0x8] */
/* @0x1b91dc ldr r1, [sp, #0x4] */
/* @0x1b91e0 add sp, sp, #28 */
/* @0x1b91e4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b91e8 b 0x1b7a04 <_ZN13CLayerManager23RemoveBackgroundElementEP6CLayerP23CLayerBackgroundElement> */
/* ── ⑤ type 2 专段：表 3 摘桶（键 elem+0x1c，簇 room+0x110）后尾跳 RemoveInstanceElement ── */
/* @0x1b91ec ldr r6, [sp, #0x4] */
/* @0x1b91f0 ldr r0, [r6, #0x1c] */
/* @0x1b91f4 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b91f8 ldr r2, [r11, #0x118] */
/* @0x1b91fc ldr r10, [r11, #0x120] */
/* @0x1b9200 bic r0, r0, #-2147483648 */
/* @0x1b9204 and r3, r0, r2 */
/* @0x1b9208 lsl r1, r3, #1 */
/* @0x1b920c add r12, r1, r3 */
/* @0x1b9210 add r12, r10, r12, lsl #2 */
/* @0x1b9214 ldr r12, [r12, #0x8] */
/* @0x1b9218 cmp r12, #0 */
/* @0x1b921c beq 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9220 cmp r0, r12 */
/* @0x1b9224 beq 0x1b92fc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x320> */
/* @0x1b9228 ldr r7, [r11, #0x110] */
/* @0x1b922c and r12, r2, r12 */
/* @0x1b9230 add r1, r7, r3 */
/* @0x1b9234 rsb r1, r12, r1 */
/* @0x1b9238 tst r1, r2 */
/* @0x1b923c bmi 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9240 mov r4, #0 */
/* @0x1b9244 b 0x1b9258 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x27c> */
/* @0x1b9248 cmp r0, r12 */
/* @0x1b924c beq 0x1b92f4 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x318> */
/* @0x1b9250 cmp r5, r4 */
/* @0x1b9254 blt 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b9258 add r3, r3, #1 */
/* @0x1b925c add r4, r4, #1 */
/* @0x1b9260 and r3, r2, r3 */
/* @0x1b9264 add r6, r7, r3 */
/* @0x1b9268 lsl r1, r3, #1 */
/* @0x1b926c add r12, r1, r3 */
/* @0x1b9270 add r12, r10, r12, lsl #2 */
/* @0x1b9274 ldr r12, [r12, #0x8] */
/* @0x1b9278 and r5, r2, r12 */
/* @0x1b927c cmp r12, #0 */
/* @0x1b9280 rsb r5, r5, r6 */
/* @0x1b9284 and r5, r5, r2 */
/* @0x1b9288 bne 0x1b9248 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x26c> */
/* @0x1b928c ldr r0, [sp, #0x8] */
/* @0x1b9290 ldr r1, [sp, #0x4] */
/* @0x1b9294 ldr r2, [sp, #0x10] */
/* @0x1b9298 add sp, sp, #28 */
/* @0x1b929c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92a0 b 0x1b7ac4 <_ZN13CLayerManager21RemoveInstanceElementEP6CLayerP21CLayerInstanceElementb> */
/* @0x1b92a4 ldr r0, [sp, #0x8] */
/* @0x1b92a8 ldr r1, [sp, #0x4] */
/* @0x1b92ac add sp, sp, #28 */
/* @0x1b92b0 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92b4 b 0x1b7bac <_ZN13CLayerManager23RemoveOldTilemapElementEP6CLayerP23CLayerOldTilemapElement> */
/* @0x1b92b8 ldr r0, [sp, #0x8] */
/* @0x1b92bc ldr r1, [sp, #0x4] */
/* @0x1b92c0 add sp, sp, #28 */
/* @0x1b92c4 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92c8 b 0x1b7dcc <_ZN13CLayerManager20RemoveTilemapElementEP6CLayerP20CLayerTilemapElement> */
/* @0x1b92cc ldr r0, [sp, #0x8] */
/* @0x1b92d0 ldr r1, [sp, #0x4] */
/* @0x1b92d4 add sp, sp, #28 */
/* @0x1b92d8 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92dc b 0x1b7ec0 <_ZN13CLayerManager21RemoveParticleElementEP6CLayerP21CLayerParticleElement> */
/* @0x1b92e0 ldr r0, [sp, #0x8] */
/* @0x1b92e4 ldr r1, [sp, #0x4] */
/* @0x1b92e8 add sp, sp, #28 */
/* @0x1b92ec pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b92f0 b 0x1b7cf8 <_ZN13CLayerManager19RemoveSpriteElementEP6CLayerP19CLayerSpriteElement> */
/* @0x1b92f4 cmn r3, #1 */
/* @0x1b92f8 beq 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b92fc add r0, r3, #1 */
/* @0x1b9300 and r7, r0, r2 */
/* @0x1b9304 add r4, r7, r7, lsl #1 */
/* @0x1b9308 add r4, r10, r4, lsl #2 */
/* @0x1b930c ldr r12, [r4, #0x8] */
/* @0x1b9310 cmp r12, #0 */
/* @0x1b9314 beq 0x1b93c0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3e4> */
/* @0x1b9318 ldr r0, [r11, #0x110] */
/* @0x1b931c str r0, [sp, #0xc] */
/* @0x1b9320 and r0, r2, r12 */
/* @0x1b9324 ldr r6, [sp, #0xc] */
/* @0x1b9328 add r5, r7, r6 */
/* @0x1b932c rsb r0, r0, r5 */
/* @0x1b9330 tst r0, r2 */
/* @0x1b9334 strne r11, [sp, #0x14] */
/* @0x1b9338 bne 0x1b934c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x370> */
/* @0x1b933c b 0x1b93c0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3e4> */
/* @0x1b9340 tst r6, r2 */
/* @0x1b9344 beq 0x1b939c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3c0> */
/* @0x1b9348 mov r7, r0 */
/* @0x1b934c add r6, r1, r3 */
/* @0x1b9350 add r0, r7, #1 */
/* @0x1b9354 and r0, r0, r2 */
/* @0x1b9358 ldr r8, [r4, #0x4] */
/* @0x1b935c add r5, r10, r6, lsl #2 */
/* @0x1b9360 ldr r1, [sp, #0xc] */
/* @0x1b9364 add r11, r0, r0, lsl #1 */
/* @0x1b9368 mov r3, r7 */
/* @0x1b936c str r12, [r5, #0x8] */
/* @0x1b9370 add r9, r1, r0 */
/* @0x1b9374 ldr r4, [r4] */
/* @0x1b9378 lsl r1, r7, #1 */
/* @0x1b937c str r4, [r10, r6, lsl #2] */
/* @0x1b9380 add r4, r10, r11, lsl #2 */
/* @0x1b9384 ldr r12, [r4, #0x8] */
/* @0x1b9388 str r8, [r5, #0x4] */
/* @0x1b938c cmp r12, #0 */
/* @0x1b9390 and r6, r2, r12 */
/* @0x1b9394 rsb r6, r6, r9 */
/* @0x1b9398 bne 0x1b9340 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x364> */
/* @0x1b939c ldr r11, [sp, #0x14] */
/* @0x1b93a0 add r3, r7, r7, lsl #1 */
/* @0x1b93a4 ldr r1, [r11, #0x114] */
/* @0x1b93a8 mov r2, #0 */
/* @0x1b93ac add r10, r10, r3, lsl #2 */
/* @0x1b93b0 sub r3, r1, #1 */
/* @0x1b93b4 str r2, [r10, #0x8] */
/* @0x1b93b8 str r3, [r11, #0x114] */
/* @0x1b93bc b 0x1b928c <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x2b0> */
/* @0x1b93c0 mov r7, r3 */
/* @0x1b93c4 b 0x1b93a0 <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb+0x3c4> */

/* ══ §2 CLayerManager::RemoveLayer 0x1b95d8 ═══════════════════════════════
 * @func 0x1b95d8 0x1b991c size 836  209 行（208 指令 + 1 池字 1b9918）
 * 级别: 正文（208/208。取层 / 清元素 / 摘层链 / 删表 1 / 放名字 / 按类别回收 / 全字段复位 / 回层池
 *       八段全部钉住；未钉：layer+0x64 的枚举名、MemoryInWad 的判定域、第 3 实参为什么不读）
 * 符号: _ZN13CLayerManager11RemoveLayerEP5CRoomib → void CLayerManager::RemoveLayer(CRoom*, int layerId, bool)
 * 调用者（BL 普查，全 .text 4 处）：RemoveInstanceFromLayer 0x1b991c 尾跳（1b9c80，第 3 实参 = -1）、
 *       RemoveStorageInstanceFromLayer 0x1b9ea4 尾跳（1ba204）、F_LayerDestroy 0x1bc0e0（1bc168，GML layer_destroy）、
 *       RemoveElement(CRoom*,int,bool,bool) 0x1c013c（1c01a8，第 3 实参 = 0）
 * 同层: GetLayerFromID 0x1b8868、RemoveElement 0x1b8fdc、MemoryInWad 0x1aad50、MemoryManager::Free 0x27c2d0、
 *       operator delete 0x27d1d0、CTimingSource::Reset 0x214728、m_LayerPool 0x5426a0
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   按 layer id 删一层，顺序是：**先把层里的元素逐个交给 RemoveElement（b=1）清掉**，再摘层链、删表 1、
 *   放名字，末尾按 layer+0x64 做一次残余元素回收，最后把 112 B 层块整块复位并头插回 m_LayerPool。
 *
 * ── ① 取层（1b95e0..1b95f0）─────────────────────────────────────────────
 *   r9 = room（第一个实参）；GetLayerFromID(room, layerId) 0x1b8868 查**表 1**（+0xe4 容量 / +0xec 掩码 /
 *   +0xf4 桶，1b8878..1b88a8 三处读点）。返回 0 → 直接 `b 1b97e4`（add sp/pop）返回，无副作用。
 *
 * ── ② 清空层内元素（1b95f4..1b960c）——本节最重要的一段 ───────────────────
 *   循环头在 1b9604：`ldr r2,[r4,#0x58]`（层元素链头）→ 为 0 跳出；否则回 1b95f4：
 *   `RemoveElement(room, layer, 链头, 1)`（第 4 实参 r3 = 1 = bDestroy）。
 *   ⇒ 语义：`while ((e = layer->[0x58]) != 0) RemoveElement(room, layer, e, true);`
 *   ⇒ **bDestroy = 1 的后果**：type 2 元素会走到 RemoveInstanceElement 的第 ② 步，
 *      `DoInstanceDestroy(NULL, NULL, elem+0x1c, 1)`（0x10b12c，hard=1）——**删层会硬销毁层里的实例**。
 *   ⚠ 循环条件每次重新读 +0x58，所以只有「每个元素都自摘链」才会终止。七个族回收器都按
 *     elem+0x14/+0x18 与 layer+0x58/+0x5c/+0x60 摘链（抽检 RemoveBackgroundElement 1b7a28..1b7a5c 与
 *     RemoveTileElement 1b7f64..1b7fa8 的两组五条写点，形状与 RemoveInstanceElement 完全相同）；
 *     type ∉ 1..7 时 RemoveElement ④ 直接返回不摘链 ⇒ 这里会原地死循环（控制流推论，见 §1 open）。
 *
 * ── ③ 摘层链（1b9610..1b9634 + 1b9900..1b9908）────────────────────────────
 *   next = layer+0x68、prev = layer+0x6c；prev != 0 → prev->next = next，prev == 0 → room+0xd4 = next（1b9900）；
 *   next != 0 → next->prev = prev，next == 0 → room+0xd8 = prev（1b9634）。
 *   ⇒ room+0xd4/+0xd8 是层链的头/尾（层链按 +0x04 depth 升序，见 GetLayerWithDepth 卡）。
 *
 * ── ④ 计数与表 1 摘桶（1b9638..1b96dc + 1b97ec..1b98ac）───────────────────
 *   room+0xdc（层数）-1（1b9638..1b9644）；键 = layer+0x00（id）→ CHashMapCalculateHash 0x1b6e44 →
 *   桶下标 = (h & room+0xec)、桶项 = room+0xf4 + 12*idx。三态与 §1 ② 同构（空桶/命中/越距），
 *   命中后同样的回移压缩，末槽 +0x08 清 0，`room+0xe8`（已用数）-1（1b9890..1b98a8）。
 *   ⇒ 表 1 = 「层 id → CLayer*」；GetLayerFromID 是它的读方，本段是删除侧的唯一写方（AddLayer 是插入方）。
 *   ⇒ **三张表里本函数只删表 1**：表 2（元素 uid）与表 3（实例 id）已经在 ② 里被每个元素的
 *     RemoveElement 各删一次。所以「删一层」= N 次元素销号（表 2/表 3）+ 1 次层销号（表 1）。
 *
 * ── ⑤ 名字串（1b96e0..1b9700）───────────────────────────────────────────
 *   p = layer+0x1c（AddLayer 按 strlen+1 分配）；`MemoryInWad(p)` 0x1aad50 返回 0 才 `MemoryManager::Free(p)`
 *   0x27c2d0；随后 +0x1c = 0。⇒ **wad 内的名字不释放**（避免 free 映射区内指针），只有运行期 strdup 的才 free。
 *
 * ── ⑥ 按 layer+0x64 回收残余元素（1b96f8..1b9714 判门，1b9718..1b98f4 分派）────────
 *   cat = layer+0x64；cat == 0 → 跳过；链头 layer+0x58 == 0 → 跳过；否则：
 *     cat == 2 → 1b98b0：`{ next = p->[0x14]; MemoryManager::Free(p); p = next; }`
 *     cat == 3 → 1b98c8：与 cat 2 **逐条同构**（也是 MemoryManager::Free，只是另一份代码副本）
 *     cat == 1 → 1b98e0：`{ next = p->[0x14]; operator delete(p); p = next; }`（_ZdlPv 0x27d1d0）
 *     其它值   → 1b9730：只沿 +0x14 走到尾，**一个都不释放**（还是一次空转遍历）
 *   ⚠ **正常路径上这段不执行**：第 ② 步已把层元素链清空，1b9710 的 `cmp r0,#0` 必然相等 → 跳 1b973c。
 *     它只在「② 里有元素没被摘链」时才有活，而那种 type 会让 ② 先死循环。⇒ 防御性/历史残留代码，
 *     唯一可证的用途是：它证明了层类别 1 用 delete、2/3 用池 Free 的三档回收约定（ChangeLayerDepth 0x1b85e4
 *     按同一字节分派三条回收路径，见 LayerHelpers 卡头部）。
 *
 * ── ⑦ 全字段复位 + 回 m_LayerPool（1b973c..1b97e0 + 1b990c..1b9914）────────
 *   写入顺序（注意 head/tail/count 被清了两次，1b977c..1b9784 与 1b97ac..1b97c0）：
 *     +0x00 = -1（id）  +0x04 = 0（depth）  +0x08/+0x0c/+0x10/+0x14 = 0（滚动/速度四个 float）
 *     +0x18 = 1（可见）  +0x19 = 0（动态筛子）  +0x1c = 0（名字，⑤已置 0，这里再写一次）
 *     +0x20/+0x24/+0x28 = -1  +0x48/+0x4c = 0（strd）  +0x58/+0x5c/+0x60 = 0（元素链头/尾/数）
 *     +0x68/+0x6c = 0（层链 next/prev）  CTimingSource::Reset(this+0x30) 0x214728
 *     +0x64 = **1**（层类别复位成 1；注意 ⑥ 用的是复位**前**的值）
 *   回池：池 = m_LayerPool（槽 0x3f0864 → 0x5426a0，20 B 协议 {自由头/+0x04 尾/+0x08 可用数/+0x10 容量}）；
 *     可用数 +1；旧自由头非 0 → 旧头->prev(+0x6c) = layer、layer->next(+0x68) = 旧头、layer->prev = 0、
 *     池头 = layer；池空 → 池头 = 池尾 = layer（1b990c/1b9910）。
 *   ⇒ 层池的自由链与活链共用 +0x68/+0x6c 这一对偏移（与 LayerHelpers 卡「池协议」一致）。
 *
 * ── ⑧ 第 3 实参 b 是死参数（整节证据）──────────────────────────────────
 *   函数体里 r2（第 3 实参）**一次也没被读取**：全节所有 r2 用法都是暂存（1b9604 起全是 `ldr r2,[…]`）。
 *   ⇒ 原版签名有 bool，实现忽略。两个真实调用点也印证：§3 传 -1、0x1c013c 传 0，行为不可能不同。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · layer+0x64 的枚举名：1 = operator delete 档、2/3 = MemoryManager::Free 档、0 = 不回收、其它 = 走链不释放。
 *     谁写 2/3（ChangeLayerDepth 只读不写）未证。
 *   · MemoryInWad 0x1aad50 的判定域（wad 区间怎么定）未读；只知道返回 0 才 Free。
 *   · ⑥ 是死块（见上）；若真有「元素留在链上」的合法状态，本函数的回收档选择就是唯一线索 —— 但那条状态不可达
 *     的证明依赖 ② 的终止性，本节只给控制流推论。
 *   · 池容量的预置方（cap <= 0 时 AddDynamicLayer 只把 0 翻倍）未证；本节只证「可用数 +1、头插」。
 */

/* ── ① GetLayerFromID(room, id)：返回 0 就直接回 ── */
/* @0x1b95d8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b95dc sub sp, sp, #12 */
/* @0x1b95e0 mov r9, r0 */
/* @0x1b95e4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1b95e8 subs r4, r0, #0 */
/* @0x1b95ec bne 0x1b9604 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2c> */
/* @0x1b95f0 b 0x1b97e4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x20c> */
/* ── ② 清空层内元素：while ((e = layer+0x58)) RemoveElement(room, layer, e, true) ── */
/* @0x1b95f4 mov r0, r9 */
/* @0x1b95f8 mov r1, r4 */
/* @0x1b95fc mov r3, #1 */
/* @0x1b9600 bl 0x1b8fdc <_ZN13CLayerManager13RemoveElementEP5CRoomP6CLayerP17CLayerElementBaseb> */
/* @0x1b9604 ldr r2, [r4, #0x58] */
/* @0x1b9608 cmp r2, #0 */
/* @0x1b960c bne 0x1b95f4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x1c> */
/* ── ③ 摘层链：+0x68/+0x6c 与 room+0xd4/+0xd8 ── */
/* @0x1b9610 ldr r3, [r4, #0x6c] */
/* @0x1b9614 cmp r3, #0 */
/* @0x1b9618 beq 0x1b9900 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x328> */
/* @0x1b961c ldr r2, [r4, #0x68] */
/* @0x1b9620 str r2, [r3, #0x68] */
/* @0x1b9624 ldr r2, [r4, #0x68] */
/* @0x1b9628 ldr r3, [r4, #0x6c] */
/* @0x1b962c cmp r2, #0 */
/* @0x1b9630 strne r3, [r2, #0x6c] */
/* @0x1b9634 streq r3, [r9, #0xd8] */
/* ── ④ room+0xdc 层数 -1，表 1 摘桶（键 layer+0x00）── */
/* @0x1b9638 ldr r3, [r9, #0xdc] */
/* @0x1b963c ldr r0, [r4] */
/* @0x1b9640 sub r3, r3, #1 */
/* @0x1b9644 str r3, [r9, #0xdc] */
/* @0x1b9648 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b964c ldr r2, [r9, #0xec] */
/* @0x1b9650 ldr r12, [r9, #0xf4] */
/* @0x1b9654 bic r0, r0, #-2147483648 */
/* @0x1b9658 and r3, r0, r2 */
/* @0x1b965c lsl r1, r3, #1 */
/* @0x1b9660 add lr, r1, r3 */
/* @0x1b9664 add lr, r12, lr, lsl #2 */
/* @0x1b9668 ldr lr, [lr, #0x8] */
/* @0x1b966c cmp lr, #0 */
/* @0x1b9670 beq 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b9674 cmp r0, lr */
/* @0x1b9678 beq 0x1b97f4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x21c> */
/* @0x1b967c ldr r8, [r9, #0xe4] */
/* @0x1b9680 and lr, r2, lr */
/* @0x1b9684 add r1, r3, r8 */
/* @0x1b9688 rsb lr, lr, r1 */
/* @0x1b968c tst lr, r2 */
/* @0x1b9690 bmi 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b9694 mov r5, #0 */
/* @0x1b9698 b 0x1b96ac <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0xd4> */
/* @0x1b969c cmp r0, lr */
/* @0x1b96a0 beq 0x1b97ec <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x214> */
/* @0x1b96a4 cmp r6, r5 */
/* @0x1b96a8 blt 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b96ac add r3, r3, #1 */
/* @0x1b96b0 add r5, r5, #1 */
/* @0x1b96b4 and r3, r2, r3 */
/* @0x1b96b8 add r7, r3, r8 */
/* @0x1b96bc lsl r1, r3, #1 */
/* @0x1b96c0 add lr, r1, r3 */
/* @0x1b96c4 add lr, r12, lr, lsl #2 */
/* @0x1b96c8 ldr lr, [lr, #0x8] */
/* @0x1b96cc and r6, r2, lr */
/* @0x1b96d0 cmp lr, #0 */
/* @0x1b96d4 rsb r6, r6, r7 */
/* @0x1b96d8 and r6, r6, r2 */
/* @0x1b96dc bne 0x1b969c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0xc4> */
/* ── ⑤ 名字串：MemoryInWad 为 0 才 MemoryManager::Free ── */
/* @0x1b96e0 ldr r0, [r4, #0x1c] */
/* @0x1b96e4 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1b96e8 cmp r0, #0 */
/* @0x1b96ec bne 0x1b96f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x120> */
/* @0x1b96f0 ldr r0, [r4, #0x1c] */
/* @0x1b96f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* ── ⑥ 按 +0x64 回收残余元素：2/3 = MemoryManager::Free，1 = operator delete，其它只走链不释放 ── */
/* @0x1b96f8 ldr r3, [r4, #0x64] */
/* @0x1b96fc mov r2, #0 */
/* @0x1b9700 str r2, [r4, #0x1c] */
/* @0x1b9704 cmp r3, r2 */
/* @0x1b9708 beq 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b970c ldr r0, [r4, #0x58] */
/* @0x1b9710 cmp r0, #0 */
/* @0x1b9714 beq 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b9718 cmp r3, #2 */
/* @0x1b971c beq 0x1b98b0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2d8> */
/* @0x1b9720 cmp r3, #3 */
/* @0x1b9724 beq 0x1b98c8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2f0> */
/* @0x1b9728 cmp r3, #1 */
/* @0x1b972c beq 0x1b98e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x308> */
/* @0x1b9730 ldr r0, [r0, #0x14] */
/* @0x1b9734 cmp r0, #0 */
/* @0x1b9738 bne 0x1b9730 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x158> */
/* ── ⑦ 全字段复位 + CTimingSource::Reset + 回 m_LayerPool（+0x64 置 1）── */
/* @0x1b973c mov r5, #0 */
/* @0x1b9740 mvn r1, #0 */
/* @0x1b9744 mov r3, #0 */
/* @0x1b9748 mov r6, #1 */
/* @0x1b974c mov r2, #0 */
/* @0x1b9750 str r3, [r4, #0x8] */
/* @0x1b9754 str r3, [r4, #0xc] */
/* @0x1b9758 add r0, r4, #48 */
/* @0x1b975c str r3, [r4, #0x10] */
/* @0x1b9760 str r3, [r4, #0x14] */
/* @0x1b9764 mov r3, #0 */
/* @0x1b9768 str r1, [r4] */
/* @0x1b976c strd r2, r3, [r4, #72] */
/* @0x1b9770 str r1, [r4, #0x20] */
/* @0x1b9774 str r1, [r4, #0x24] */
/* @0x1b9778 str r1, [r4, #0x28] */
/* @0x1b977c str r5, [r4, #0x60] */
/* @0x1b9780 str r5, [r4, #0x5c] */
/* @0x1b9784 str r5, [r4, #0x58] */
/* @0x1b9788 str r5, [r4, #0x4] */
/* @0x1b978c strb r5, [r4, #0x19] */
/* @0x1b9790 str r5, [r4, #0x1c] */
/* @0x1b9794 strb r6, [r4, #0x18] */
/* @0x1b9798 bl 0x214728 <_ZN13CTimingSource5ResetEv> */
/* @0x1b979c ldr r3, [pc, #0x174] */
/* @0x1b97a0 str r5, [r4, #0x68] */
/* @0x1b97a4 ldr r3, [pc, r3] */
/* @0x1b97a8 str r5, [r4, #0x6c] */
/* @0x1b97ac str r5, [r4, #0x5c] */
/* @0x1b97b0 ldr r2, [r3] */
/* @0x1b97b4 ldr r1, [r3, #0x8] */
/* @0x1b97b8 cmp r2, r5 */
/* @0x1b97bc str r5, [r4, #0x58] */
/* @0x1b97c0 str r5, [r4, #0x60] */
/* @0x1b97c4 add r1, r1, r6 */
/* @0x1b97c8 str r6, [r4, #0x64] */
/* @0x1b97cc str r1, [r3, #0x8] */
/* @0x1b97d0 strne r4, [r2, #0x6c] */
/* @0x1b97d4 strne r4, [r3] */
/* @0x1b97d8 strne r2, [r4, #0x68] */
/* @0x1b97dc strne r5, [r4, #0x6c] */
/* @0x1b97e0 beq 0x1b990c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x334> */
/* @0x1b97e4 add sp, sp, #12 */
/* @0x1b97e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b97ec cmn r3, #1 */
/* @0x1b97f0 beq 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b97f4 add r6, r3, #1 */
/* @0x1b97f8 and r6, r6, r2 */
/* @0x1b97fc add r5, r6, r6, lsl #1 */
/* @0x1b9800 add r5, r12, r5, lsl #2 */
/* @0x1b9804 ldr lr, [r5, #0x8] */
/* @0x1b9808 cmp lr, #0 */
/* @0x1b980c beq 0x1b98f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x320> */
/* @0x1b9810 ldr r8, [r9, #0xe4] */
/* @0x1b9814 and r0, r2, lr */
/* @0x1b9818 add r7, r6, r8 */
/* @0x1b981c rsb r0, r0, r7 */
/* @0x1b9820 tst r0, r2 */
/* @0x1b9824 beq 0x1b98f8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x320> */
/* @0x1b9828 stm sp, {r4, r9} */
/* @0x1b982c mov r9, r8 */
/* @0x1b9830 b 0x1b9840 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x268> */
/* @0x1b9834 tst r10, r2 */
/* @0x1b9838 beq 0x1b988c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2b4> */
/* @0x1b983c mov r6, r0 */
/* @0x1b9840 add r7, r1, r3 */
/* @0x1b9844 add r0, r6, #1 */
/* @0x1b9848 and r0, r0, r2 */
/* @0x1b984c ldr r8, [r5, #0x4] */
/* @0x1b9850 add r4, r12, r7, lsl #2 */
/* @0x1b9854 add r10, r0, r9 */
/* @0x1b9858 add r11, r0, r0, lsl #1 */
/* @0x1b985c mov r3, r6 */
/* @0x1b9860 str lr, [r4, #0x8] */
/* @0x1b9864 lsl r1, r6, #1 */
/* @0x1b9868 ldr r5, [r5] */
/* @0x1b986c str r5, [r12, r7, lsl #2] */
/* @0x1b9870 add r5, r12, r11, lsl #2 */
/* @0x1b9874 ldr lr, [r5, #0x8] */
/* @0x1b9878 str r8, [r4, #0x4] */
/* @0x1b987c cmp lr, #0 */
/* @0x1b9880 and r7, r2, lr */
/* @0x1b9884 rsb r10, r7, r10 */
/* @0x1b9888 bne 0x1b9834 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x25c> */
/* @0x1b988c ldm sp, {r4, r9} */
/* @0x1b9890 add r6, r6, r6, lsl #1 */
/* @0x1b9894 ldr r3, [r9, #0xe8] */
/* @0x1b9898 mov r2, #0 */
/* @0x1b989c add r12, r12, r6, lsl #2 */
/* @0x1b98a0 sub r3, r3, #1 */
/* @0x1b98a4 str r2, [r12, #0x8] */
/* @0x1b98a8 str r3, [r9, #0xe8] */
/* @0x1b98ac b 0x1b96e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x108> */
/* @0x1b98b0 ldr r5, [r0, #0x14] */
/* @0x1b98b4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b98b8 cmp r5, #0 */
/* @0x1b98bc mov r0, r5 */
/* @0x1b98c0 bne 0x1b98b0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2d8> */
/* @0x1b98c4 b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98c8 ldr r5, [r0, #0x14] */
/* @0x1b98cc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b98d0 cmp r5, #0 */
/* @0x1b98d4 mov r0, r5 */
/* @0x1b98d8 bne 0x1b98c8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2f0> */
/* @0x1b98dc b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98e0 ldr r5, [r0, #0x14] */
/* @0x1b98e4 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b98e8 cmp r5, #0 */
/* @0x1b98ec mov r0, r5 */
/* @0x1b98f0 bne 0x1b98e0 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x308> */
/* @0x1b98f4 b 0x1b973c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x164> */
/* @0x1b98f8 mov r6, r3 */
/* @0x1b98fc b 0x1b9890 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x2b8> */
/* @0x1b9900 ldr r2, [r4, #0x68] */
/* @0x1b9904 str r2, [r9, #0xd4] */
/* @0x1b9908 b 0x1b962c <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x54> */
/* @0x1b990c str r4, [r3, #0x4] */
/* @0x1b9910 str r4, [r3] */
/* @0x1b9914 b 0x1b97e4 <_ZN13CLayerManager11RemoveLayerEP5CRoomib+0x20c> */
/* 池字（非指令）：0x002370b8 → GOT 0x3f0864 = m_LayerPool（供 1b979c 的 ldr r3,[pc,#0x174]）*/
/* @0x1b9918 strhteq r7, [r3], -r8 */

/* ══ §3 CLayerManager::RemoveInstanceFromLayer 0x1b991c ═══════════════════
 * @func 0x1b991c 0x1b9e5c size 1344  336 行（333 指令 + 3 池字 1b9e50/1b9e54/1b9e58）
 * 级别: 正文（333/333。四道门 / 表 3 查元素 / 属层校验与诊断串 / 表 2 删 / 表 3 删 / 摘链回池 /
 *       实例两字段 / 动态层自删 全部钉住；未钉：诊断宿主 vtable 槽 3 的方法名、CleanElementRuntimeData
 *       为什么不在这里调）
 * 符号: _ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance
 *       → void CLayerManager::RemoveInstanceFromLayer(CRoom* room, CLayer* layer, CInstance* inst)
 * 调用者（全 .text 2 处）：RemoveInstance 0x1b9e5c 尾跳（1b9ea0）、F_LayerRemoveInstance 0x1c1398 尾跳（1c14e0，
 *       GML layer_remove_instance）
 * 同层: RemoveInstanceElement 0x1b7ac4（同一池、同一摘链协议的另一实现）、RemoveElement 0x1b8fdc（通用路）、
 *       RemoveLayer 0x1b95d8（⑧ 的尾跳目标）、GetElementFromID 0x1bc2a0（+0x10c 缓存）、
 *       dbg_csol（槽 0x3ed71c）、m_InstanceElementPool 0x542678
 *
 * ── 一句话 ──────────────────────────────────────────────────────────────
 *   「把某实例从某层上摘下来，但不要销毁实例」：按实例 id 在表 3 里找到它的层元素 → 校验该元素确实属于这一层 →
 *   删表 2、删表 3 → 摘链、元素回 36 B 池 → 清实例的 +0x170/+0x174 → 若层是动态层且已空，顺手把层删掉。
 *
 * ── ① 四道门（1b9920..1b994c）───────────────────────────────────────────
 *   room == 0 / layer == 0 / inst == 0 → 返回；`ldrb r3,[inst+0x174]` == 0 → 返回。
 *   ⇒ **要求实例带「已归层」标记**（+0x174 != 0）。这一点与 RemoveInstanceElement 相反（那边不要求）。
 *     与 AddInstanceToLayer 的第三道门（+0x174 != 0 就返回）正好互补：一个只管没归层的，一个只管归了层的。
 *
 * ── ② 按实例 id 查表 3（1b9958..1b9a2c）─────────────────────────────────
 *   键 = inst+0x78（实例 id）→ CHashMapCalculateHash → 31 位哈希 → 桶下标 = (h & room+0x118)、
 *   桶项 = room+0x120 + 12*idx。空桶/越距 → 返回；命中 → `ldr r9,[桶项+0x04]` = 元素指针。
 *   四道判空：elem == 0 / elem+0x10（属层）== 0 / elem+0x10 == layer（通过）/ 否则报错。
 *   ⚠ 命中只比 31 位哈希，**不重比桶项 +0x00 的键，也不校验 elem+0x1c == inst+0x78** —— 表的一致性靠写方。
 *
 * ── ③ 属层不符 → 诊断打印后原样返回（1b9a30..1b9a5c）──────────────────────
 *   宿主 = 槽 0x3ed71c → 0x3eb70c = `dbg_csol`（4 B 指针，值 = 0x47a118 = `_dbg_csol`，在 .bss，无文件内容）；
 *   `ldr r12,[宿主]; ldr r12,[r12,#0xc]; blx r12` = 调 vtable 槽 3；三个实参：
 *     r1 = 串 0x34d6d0 = "Layer system integrity compromised, instance %d not on layer %d\n"
 *     r2 = inst+0x78（实例 id）   r3 = layer+0x00（层 id）
 *   然后 add sp/pop 返回 —— **不删表、不摘链、不改字段**（fail-soft，不是 assert）。
 *   ⚠ 与 AddInstanceToLayer 的报错槽 0x3ed718（宿主 0x479a94）只差 4 B：两个不同的全局宿主，别混。
 *   该串紧邻 "…/Files/Room/Room_Layers.h" 源路径串，说明这条断言属于 Room_Layers.h 的层一致性检查。
 *
 * ── ④ 表 2 摘桶（1b9a60..1b9af8 + 命中后 1b9c84..1b9d50）─────────────────
 *   键 = elem+0x04（uid）；簇 = room+0xf8（掩码 +0x100 / 桶 +0x108 / 已用 +0xfc）。
 *   未命中 → 跳 1b9afc 继续（**不中断**）；命中 → 与 §1 ② 同构的回移压缩，末槽清 0，room+0xfc -1。
 *
 * ── ⑤ 表 3 摘桶（1b9afc..1b9ba0 + 命中后 1b9d58..1b9e3c）─────────────────
 *   键 = elem+0x1c（实例 id）；簇 = room+0x110（掩码 +0x118 / 桶 +0x120 / 已用 +0x114）。
 *   未命中 → 直接进 ⑥；命中 → 回移压缩，末槽清 0，room+0x114 -1。
 *   ⚠ ② 已经用同一张表 3 命中过一次，⑤ 是「用元素上记的 id 再删一次」——两次用的键来源不同
 *     （② 用 inst+0x78，⑤ 用 elem+0x1c）。若两者不等，② 找不到、⑤ 也可能删不掉，但代码不会报错。
 *
 * ── ⑥ 摘链 + 回 36 B 元素池（1b9ba4..1b9c54）─────────────────────────────
 *   与 RemoveInstanceElement 逐条同构：prev = +0x18、next = +0x14；prev ? prev->next = next : layer+0x58 = next；
 *   next ? next->prev = prev : layer+0x5c = prev；layer+0x60 -= 1；
 *   元素字段清成池初值：type(+0x00) = 2、uid(+0x04) = -1、+0x08 = 0、+0x0c = 0、+0x10 = 0（属层）、
 *   +0x1c = -1、+0x20 = 0；+0x14/+0x18 先清 0；
 *   池 = m_InstanceElementPool（槽 0x3f086c → 0x542678）：可用数 +1，旧头非 0 → 旧头->prev = elem、
 *   elem->next = 旧头、elem->prev = 0、池头 = elem；池空 → 池头 = 池尾 = elem。
 *   ⚠ 与 RemoveInstanceElement 的两处差异：**没有 bDestroy**（不调 DoInstanceDestroy）、
 *     **不调 CleanElementRuntimeData**（通用路是 RemoveElement 1b90c0 调的）。⇒ 走这条路回池的元素仍带
 *     运行期数据（+0x20 已被清 0，其它运行期字段原样）；是否在别处清，未证（open）。
 *   附带：room+0x10c == elem 时清 0（1b9c40/1b9c54），摘掉 GetElementFromID 的单条缓存。
 *
 * ── ⑦ 实例两字段（1b9c44 / 1b9c50）──────────────────────────────────────
 *   inst+0x174 = 0（已归层）、inst+0x170 = -1（层 id）。**inst+0x180（depth）不动**。
 *
 * ── ⑧ 动态层自删（1b9c58..1b9c80）───────────────────────────────────────
 *   if (layer+0x19 != 0 && layer+0x60 == 0) → pop 后 `b 0x1b95d8`：
 *   RemoveLayer(room, layer+0x00, r2 = -1)（r2 还是 1b9c4c 的 `mvn r2,#0` 留下的 -1）。
 *   ⇒ 「动态层（+0x19）的最后一个元素被摘走时，层自己消失」。这是 RemoveLayer 的第 1 个调用来源，
 *     也是 §2 ⑧ 里「第 3 实参没人读」的直接证据：这里传 -1，0x1c013c 传 0。
 *
 * ── 移除 vs 添加：字段终值对照表（本题重点）──────────────────────────────
 *   字段                Add 侧终值（AddInstanceToLayer + AddElementToLayer）   Remove 侧终值（本节/族回收器）
 *   elem+0x00 type      2                                                    2
 *   elem+0x04 uid       计数器 m_CurrentElementID++                          -1
 *   elem+0x08 在用位     1                                                    0
 *   elem+0x0c           0（AddElementToLayer 不写，池初值 0）                 0
 *   elem+0x10 属层       AddElementToLayer 写 layer                          0
 *   elem+0x14/+0x18      进层链（头插/尾插由 inst+0x69 定）                    清 0 后当池自由链指针用
 *   elem+0x1c inst id    inst+0x78                                           -1
 *   elem+0x20 CInstance* inst                                                 0
 *   inst+0x170           层 id                                               -1
 *   inst+0x174           1                                                   0
 *   inst+0x180 depth     (float)layer depth                                  **不动**
 *   表 2（键 uid）       插                                                  §1 ② / 本节 ④ 删
 *   表 3（键 inst id）    插                                                  §1 ⑤ / 本节 ⑤ 删
 *   层链 count +0x60     +1                                                 -1
 *   ⇒ 唯一非对称：depth（+0x180）Add 改成层深度、Remove 不还原（LayerHelpers 卡 §1 已记同一条）。
 *   ⇒ 销毁：只有 RemoveElement(…, bDestroy=1) 这条路会 DoInstanceDestroy；本节永不销毁实例。
 *
 * ── 三张表各自由谁删（本题重点）──────────────────────────────────────────
 *   路径                                 表 1(+0xe4)  表 2(+0xf8)  表 3(+0x110)  层链  元素链  回池
 *   RemoveElement(通用, bDestroy)           —            ①           ①(type2)      —     族回收器 族回收器
 *   RemoveInstanceElement(被尾跳)            —            —            —            —      自身    自身
 *   RemoveInstanceFromLayer(本节)            —            ④            ⑤            —      ⑥      ⑥
 *   RemoveLayer(§2)                          ④            —(②已逐个删)   —(同左)      ③     ②      ②
 *   ⇒ 「删一个实例元素」有三条入口，终态一致；「删一层」只有一条，且它靠 RemoveElement 做元素级销号。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · dbg_csol 的 vtable 槽 3 方法名：宿主对象在 .bss（0x47a118 无文件内容），静态拿不到 vtable 指针；
 *     只能证「走 vtable+0xc、3 个实参（串 + 两个 %d）」。
 *   · 本节不调 CleanElementRuntimeData：回池元素带着运行期数据是否有害、有没有第二处清理，未证。
 *   · elem+0x20（CInstance*）在本节只用判空（AddInstanceToLayer 复用分支用同一字节判「元素还挂着实例」），
 *     元素回池后 +0x20 = 0 ⇒ 复用分支会认为它可复用 —— 与 §3 的做法自洽。
 *   · layer+0x19 的正式名（LayerHelpers 卡叫「动态层筛子」）；谁把它置 1（AddDynamicLayer？）未在本卡核。
 *   · 池字 1b9e50 被 objdump 译成 .word、1b9e54/1b9e58 被译成 andseq/eoreq —— 三个都是池字，不是指令。
 */

/* ── ① 四道门：room/layer/inst 非 0 且 inst+0x174 != 0 ── */
/* @0x1b991c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9920 subs r11, r0, #0 */
/* @0x1b9924 sub sp, sp, #28 */
/* @0x1b9928 mov r10, r1 */
/* @0x1b992c mov r4, r2 */
/* @0x1b9930 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9934 cmp r1, #0 */
/* @0x1b9938 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b993c cmp r2, #0 */
/* @0x1b9940 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9944 ldrb r3, [r2, #0x174] */
/* @0x1b9948 cmp r3, #0 */
/* @0x1b994c bne 0x1b9958 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3c> */
/* @0x1b9950 add sp, sp, #28 */
/* @0x1b9954 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ② 按 inst+0x78 查表 3 找元素（簇 room+0x110；桶值 +0x04 = elem）── */
/* @0x1b9958 ldr r0, [r2, #0x78] */
/* @0x1b995c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9960 ldr r1, [r11, #0x118] */
/* @0x1b9964 ldr r7, [r11, #0x120] */
/* @0x1b9968 bic r0, r0, #-2147483648 */
/* @0x1b996c and r3, r0, r1 */
/* @0x1b9970 lsl r5, r3, #1 */
/* @0x1b9974 add r2, r5, r3 */
/* @0x1b9978 add r2, r7, r2, lsl #2 */
/* @0x1b997c ldr r2, [r2, #0x8] */
/* @0x1b9980 cmp r2, #0 */
/* @0x1b9984 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9988 cmp r0, r2 */
/* @0x1b998c beq 0x1b9a00 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xe4> */
/* @0x1b9990 ldr r8, [r11, #0x110] */
/* @0x1b9994 and r2, r1, r2 */
/* @0x1b9998 add r12, r8, r3 */
/* @0x1b999c rsb r2, r2, r12 */
/* @0x1b99a0 tst r2, r1 */
/* @0x1b99a4 bmi 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99a8 mov r12, #0 */
/* @0x1b99ac b 0x1b99c0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xa4> */
/* @0x1b99b0 cmp r0, r2 */
/* @0x1b99b4 beq 0x1b99f8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0xdc> */
/* @0x1b99b8 cmp r6, r12 */
/* @0x1b99bc blt 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99c0 add r3, r3, #1 */
/* @0x1b99c4 add r12, r12, #1 */
/* @0x1b99c8 and r3, r1, r3 */
/* @0x1b99cc add r9, r8, r3 */
/* @0x1b99d0 lsl r5, r3, #1 */
/* @0x1b99d4 add r2, r5, r3 */
/* @0x1b99d8 add r2, r7, r2, lsl #2 */
/* @0x1b99dc ldr r2, [r2, #0x8] */
/* @0x1b99e0 and r6, r1, r2 */
/* @0x1b99e4 cmp r2, #0 */
/* @0x1b99e8 rsb r6, r6, r9 */
/* @0x1b99ec and r6, r6, r1 */
/* @0x1b99f0 bne 0x1b99b0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x94> */
/* @0x1b99f4 b 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b99f8 cmn r3, #1 */
/* @0x1b99fc beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a00 add r3, r5, r3 */
/* @0x1b9a04 add r7, r7, r3, lsl #2 */
/* @0x1b9a08 cmn r7, #4 */
/* @0x1b9a0c beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a10 ldr r9, [r7, #0x4] */
/* @0x1b9a14 cmp r9, #0 */
/* @0x1b9a18 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a1c ldr r3, [r9, #0x10] */
/* @0x1b9a20 cmp r3, #0 */
/* @0x1b9a24 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9a28 cmp r10, r3 */
/* @0x1b9a2c beq 0x1b9a60 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x144> */
/* ── ③ 属层不符 → dbg_csol vtable+0xc 打诊断串后原样返回 ── */
/* @0x1b9a30 ldr r0, [pc, #0x418] */
/* @0x1b9a34 ldr r1, [pc, #0x418] */
/* @0x1b9a38 ldr r0, [pc, r0] */
/* @0x1b9a3c ldr r2, [r4, #0x78] */
/* @0x1b9a40 ldr r3, [r10] */
/* @0x1b9a44 add r1, pc, r1 */
/* @0x1b9a48 ldr r0, [r0] */
/* @0x1b9a4c ldr r12, [r0] */
/* @0x1b9a50 ldr r12, [r12, #0xc] */
/* @0x1b9a54 blx r12 */
/* @0x1b9a58 add sp, sp, #28 */
/* @0x1b9a5c pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── ④ 表 2 摘桶（键 elem+0x04）── */
/* @0x1b9a60 ldr r0, [r9, #0x4] */
/* @0x1b9a64 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9a68 ldr r2, [r11, #0x100] */
/* @0x1b9a6c ldr r12, [r11, #0x108] */
/* @0x1b9a70 bic r0, r0, #-2147483648 */
/* @0x1b9a74 and r3, r0, r2 */
/* @0x1b9a78 lsl r1, r3, #1 */
/* @0x1b9a7c add lr, r1, r3 */
/* @0x1b9a80 add lr, r12, lr, lsl #2 */
/* @0x1b9a84 ldr lr, [lr, #0x8] */
/* @0x1b9a88 cmp lr, #0 */
/* @0x1b9a8c beq 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9a90 cmp r0, lr */
/* @0x1b9a94 beq 0x1b9c8c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x370> */
/* @0x1b9a98 ldr r7, [r11, #0xf8] */
/* @0x1b9a9c and lr, r2, lr */
/* @0x1b9aa0 add r1, r3, r7 */
/* @0x1b9aa4 rsb r1, lr, r1 */
/* @0x1b9aa8 tst r1, r2 */
/* @0x1b9aac bmi 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9ab0 mov r5, #0 */
/* @0x1b9ab4 b 0x1b9ac8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1ac> */
/* @0x1b9ab8 cmp r0, lr */
/* @0x1b9abc beq 0x1b9c84 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x368> */
/* @0x1b9ac0 cmp r6, r5 */
/* @0x1b9ac4 blt 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9ac8 add r3, r3, #1 */
/* @0x1b9acc add r5, r5, #1 */
/* @0x1b9ad0 and r3, r2, r3 */
/* @0x1b9ad4 add r8, r3, r7 */
/* @0x1b9ad8 lsl r1, r3, #1 */
/* @0x1b9adc add lr, r1, r3 */
/* @0x1b9ae0 add lr, r12, lr, lsl #2 */
/* @0x1b9ae4 ldr lr, [lr, #0x8] */
/* @0x1b9ae8 and r6, r2, lr */
/* @0x1b9aec cmp lr, #0 */
/* @0x1b9af0 rsb r6, r6, r8 */
/* @0x1b9af4 and r6, r6, r2 */
/* @0x1b9af8 bne 0x1b9ab8 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x19c> */
/* ── ⑤ 表 3 摘桶（键 elem+0x1c）── */
/* @0x1b9afc ldr r0, [r9, #0x1c] */
/* @0x1b9b00 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1b9b04 ldr r2, [r11, #0x118] */
/* @0x1b9b08 ldr r8, [r11, #0x120] */
/* @0x1b9b0c bic r0, r0, #-2147483648 */
/* @0x1b9b10 and r3, r0, r2 */
/* @0x1b9b14 lsl r1, r3, #1 */
/* @0x1b9b18 add r12, r1, r3 */
/* @0x1b9b1c add r12, r8, r12, lsl #2 */
/* @0x1b9b20 ldr r12, [r12, #0x8] */
/* @0x1b9b24 cmp r12, #0 */
/* @0x1b9b28 beq 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9b2c cmp r0, r12 */
/* @0x1b9b30 beq 0x1b9d64 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x448> */
/* @0x1b9b34 ldr r6, [r11, #0x110] */
/* @0x1b9b38 and r12, r2, r12 */
/* @0x1b9b3c add r1, r6, r3 */
/* @0x1b9b40 rsb r1, r12, r1 */
/* @0x1b9b44 tst r1, r2 */
/* @0x1b9b48 bmi 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9b4c str r9, [sp] */
/* @0x1b9b50 mov r5, #0 */
/* @0x1b9b54 mov r9, r6 */
/* @0x1b9b58 b 0x1b9b6c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x250> */
/* @0x1b9b5c cmp r0, r12 */
/* @0x1b9b60 beq 0x1b9d58 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x43c> */
/* @0x1b9b64 cmp r6, r5 */
/* @0x1b9b68 blt 0x1b9ba0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x284> */
/* @0x1b9b6c add r3, r3, #1 */
/* @0x1b9b70 add r5, r5, #1 */
/* @0x1b9b74 and r3, r2, r3 */
/* @0x1b9b78 add r7, r9, r3 */
/* @0x1b9b7c lsl r1, r3, #1 */
/* @0x1b9b80 add r12, r1, r3 */
/* @0x1b9b84 add r12, r8, r12, lsl #2 */
/* @0x1b9b88 ldr r12, [r12, #0x8] */
/* @0x1b9b8c and r6, r2, r12 */
/* @0x1b9b90 cmp r12, #0 */
/* @0x1b9b94 rsb r6, r6, r7 */
/* @0x1b9b98 and r6, r6, r2 */
/* @0x1b9b9c bne 0x1b9b5c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x240> */
/* @0x1b9ba0 ldr r9, [sp] */
/* ── ⑥ 摘链 + 回 36 B 元素池（与 RemoveInstanceElement 同构，但无 bDestroy）── */
/* @0x1b9ba4 ldr r3, [r9, #0x18] */
/* @0x1b9ba8 mvn r0, #0 */
/* @0x1b9bac ldr r2, [r9, #0x14] */
/* @0x1b9bb0 mov r5, #2 */
/* @0x1b9bb4 cmp r3, #0 */
/* @0x1b9bb8 ldr r1, [r10, #0x60] */
/* @0x1b9bbc strne r2, [r3, #0x14] */
/* @0x1b9bc0 add r1, r1, r0 */
/* @0x1b9bc4 ldrne r2, [r9, #0x14] */
/* @0x1b9bc8 ldrne r3, [r9, #0x18] */
/* @0x1b9bcc streq r2, [r10, #0x58] */
/* @0x1b9bd0 cmp r2, #0 */
/* @0x1b9bd4 streq r3, [r10, #0x5c] */
/* @0x1b9bd8 strne r3, [r2, #0x18] */
/* @0x1b9bdc mov r3, #0 */
/* @0x1b9be0 ldr r2, [pc, #0x270] */
/* @0x1b9be4 str r1, [r10, #0x60] */
/* @0x1b9be8 ldr r2, [pc, r2] */
/* @0x1b9bec str r3, [r9, #0x14] */
/* @0x1b9bf0 str r3, [r9, #0x18] */
/* @0x1b9bf4 ldr r1, [r2] */
/* @0x1b9bf8 ldr r12, [r2, #0x8] */
/* @0x1b9bfc cmp r1, r3 */
/* @0x1b9c00 str r5, [r9] */
/* @0x1b9c04 strb r3, [r9, #0x8] */
/* @0x1b9c08 add r12, r12, #1 */
/* @0x1b9c0c str r0, [r9, #0x4] */
/* @0x1b9c10 str r3, [r9, #0xc] */
/* @0x1b9c14 str r3, [r9, #0x10] */
/* @0x1b9c18 str r3, [r9, #0x20] */
/* @0x1b9c1c str r0, [r9, #0x1c] */
/* @0x1b9c20 strne r9, [r1, #0x18] */
/* @0x1b9c24 strne r3, [r9, #0x18] */
/* @0x1b9c28 mov r3, #0 */
/* @0x1b9c2c strne r1, [r9, #0x14] */
/* @0x1b9c30 ldr r1, [r11, #0x10c] */
/* @0x1b9c34 streq r9, [r2, #0x4] */
/* @0x1b9c38 streq r9, [r2] */
/* @0x1b9c3c strne r9, [r2] */
/* @0x1b9c40 cmp r9, r1 */
/* @0x1b9c44 strb r3, [r4, #0x174] */
/* @0x1b9c48 str r12, [r2, #0x8] */
/* @0x1b9c4c mvn r2, #0 */
/* @0x1b9c50 str r2, [r4, #0x170] */
/* @0x1b9c54 streq r3, [r11, #0x10c] */
/* ── ⑦ 动态层空了就尾跳 RemoveLayer（auto-remove）── */
/* @0x1b9c58 ldrb r3, [r10, #0x19] */
/* @0x1b9c5c cmp r3, #0 */
/* @0x1b9c60 beq 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9c64 ldr r2, [r10, #0x60] */
/* @0x1b9c68 cmp r2, #0 */
/* @0x1b9c6c bne 0x1b9950 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x34> */
/* @0x1b9c70 mov r0, r11 */
/* @0x1b9c74 ldr r1, [r10] */
/* @0x1b9c78 add sp, sp, #28 */
/* @0x1b9c7c pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b9c80 b 0x1b95d8 <_ZN13CLayerManager11RemoveLayerEP5CRoomib> */
/* @0x1b9c84 cmn r3, #1 */
/* @0x1b9c88 beq 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9c8c add r6, r3, #1 */
/* @0x1b9c90 and r6, r6, r2 */
/* @0x1b9c94 add r5, r6, r6, lsl #1 */
/* @0x1b9c98 add r5, r12, r5, lsl #2 */
/* @0x1b9c9c ldr lr, [r5, #0x8] */
/* @0x1b9ca0 cmp lr, #0 */
/* @0x1b9ca4 beq 0x1b9e48 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x52c> */
/* @0x1b9ca8 ldr r8, [r11, #0xf8] */
/* @0x1b9cac and r0, r2, lr */
/* @0x1b9cb0 add r7, r6, r8 */
/* @0x1b9cb4 rsb r0, r0, r7 */
/* @0x1b9cb8 tst r0, r2 */
/* @0x1b9cbc beq 0x1b9e48 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x52c> */
/* @0x1b9cc0 str r4, [sp, #0x10] */
/* @0x1b9cc4 mov r4, r8 */
/* @0x1b9cc8 stmib sp, {r9, r11} */
/* @0x1b9ccc str r10, [sp, #0xc] */
/* @0x1b9cd0 b 0x1b9ce0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3c4> */
/* @0x1b9cd4 tst r10, r2 */
/* @0x1b9cd8 beq 0x1b9d2c <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x410> */
/* @0x1b9cdc mov r6, r0 */
/* @0x1b9ce0 add r8, r1, r3 */
/* @0x1b9ce4 add r0, r6, #1 */
/* @0x1b9ce8 and r0, r0, r2 */
/* @0x1b9cec ldr r9, [r5, #0x4] */
/* @0x1b9cf0 add r7, r12, r8, lsl #2 */
/* @0x1b9cf4 add r10, r0, r4 */
/* @0x1b9cf8 add r11, r0, r0, lsl #1 */
/* @0x1b9cfc mov r3, r6 */
/* @0x1b9d00 str lr, [r7, #0x8] */
/* @0x1b9d04 lsl r1, r6, #1 */
/* @0x1b9d08 ldr r5, [r5] */
/* @0x1b9d0c str r5, [r12, r8, lsl #2] */
/* @0x1b9d10 add r5, r12, r11, lsl #2 */
/* @0x1b9d14 ldr lr, [r5, #0x8] */
/* @0x1b9d18 str r9, [r7, #0x4] */
/* @0x1b9d1c cmp lr, #0 */
/* @0x1b9d20 and r8, r2, lr */
/* @0x1b9d24 rsb r10, r8, r10 */
/* @0x1b9d28 bne 0x1b9cd4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x3b8> */
/* @0x1b9d2c ldmib sp, {r9, r11} */
/* @0x1b9d30 ldr r10, [sp, #0xc] */
/* @0x1b9d34 ldr r4, [sp, #0x10] */
/* @0x1b9d38 add r6, r6, r6, lsl #1 */
/* @0x1b9d3c ldr r3, [r11, #0xfc] */
/* @0x1b9d40 mov r2, #0 */
/* @0x1b9d44 add r12, r12, r6, lsl #2 */
/* @0x1b9d48 sub r3, r3, #1 */
/* @0x1b9d4c str r2, [r12, #0x8] */
/* @0x1b9d50 str r3, [r11, #0xfc] */
/* @0x1b9d54 b 0x1b9afc <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x1e0> */
/* @0x1b9d58 cmn r3, #1 */
/* @0x1b9d5c ldr r9, [sp] */
/* @0x1b9d60 beq 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9d64 add r0, r3, #1 */
/* @0x1b9d68 and r6, r0, r2 */
/* @0x1b9d6c add r5, r6, r6, lsl #1 */
/* @0x1b9d70 add r5, r8, r5, lsl #2 */
/* @0x1b9d74 ldr r12, [r5, #0x8] */
/* @0x1b9d78 cmp r12, #0 */
/* @0x1b9d7c beq 0x1b9e40 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x524> */
/* @0x1b9d80 ldr r0, [r11, #0x110] */
/* @0x1b9d84 str r0, [sp, #0x4] */
/* @0x1b9d88 and r0, r2, r12 */
/* @0x1b9d8c ldr r7, [sp, #0x4] */
/* @0x1b9d90 add r7, r6, r7 */
/* @0x1b9d94 rsb r0, r0, r7 */
/* @0x1b9d98 tst r0, r2 */
/* @0x1b9d9c strne r9, [sp, #0x8] */
/* @0x1b9da0 strne r11, [sp, #0xc] */
/* @0x1b9da4 strne r10, [sp, #0x10] */
/* @0x1b9da8 strne r4, [sp, #0x14] */
/* @0x1b9dac bne 0x1b9dc0 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x4a4> */
/* @0x1b9db0 b 0x1b9e40 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x524> */
/* @0x1b9db4 tst r10, r2 */
/* @0x1b9db8 beq 0x1b9e10 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x4f4> */
/* @0x1b9dbc mov r6, r0 */
/* @0x1b9dc0 add r7, r1, r3 */
/* @0x1b9dc4 add r0, r6, #1 */
/* @0x1b9dc8 and r0, r0, r2 */
/* @0x1b9dcc ldr r9, [r5, #0x4] */
/* @0x1b9dd0 add r4, r8, r7, lsl #2 */
/* @0x1b9dd4 ldr r1, [sp, #0x4] */
/* @0x1b9dd8 add r11, r0, r0, lsl #1 */
/* @0x1b9ddc mov r3, r6 */
/* @0x1b9de0 str r12, [r4, #0x8] */
/* @0x1b9de4 add r10, r0, r1 */
/* @0x1b9de8 ldr r5, [r5] */
/* @0x1b9dec lsl r1, r6, #1 */
/* @0x1b9df0 str r5, [r8, r7, lsl #2] */
/* @0x1b9df4 add r5, r8, r11, lsl #2 */
/* @0x1b9df8 ldr r12, [r5, #0x8] */
/* @0x1b9dfc str r9, [r4, #0x4] */
/* @0x1b9e00 cmp r12, #0 */
/* @0x1b9e04 and r7, r2, r12 */
/* @0x1b9e08 rsb r10, r7, r10 */
/* @0x1b9e0c bne 0x1b9db4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x498> */
/* @0x1b9e10 ldr r9, [sp, #0x8] */
/* @0x1b9e14 ldr r11, [sp, #0xc] */
/* @0x1b9e18 ldr r10, [sp, #0x10] */
/* @0x1b9e1c ldr r4, [sp, #0x14] */
/* @0x1b9e20 add r1, r6, r6, lsl #1 */
/* @0x1b9e24 ldr r3, [r11, #0x114] */
/* @0x1b9e28 mov r2, #0 */
/* @0x1b9e2c add r1, r8, r1, lsl #2 */
/* @0x1b9e30 sub r3, r3, #1 */
/* @0x1b9e34 str r2, [r1, #0x8] */
/* @0x1b9e38 str r3, [r11, #0x114] */
/* @0x1b9e3c b 0x1b9ba4 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x288> */
/* @0x1b9e40 mov r6, r3 */
/* @0x1b9e44 b 0x1b9e20 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x504> */
/* @0x1b9e48 mov r6, r3 */
/* @0x1b9e4c b 0x1b9d38 <_ZN13CLayerManager23RemoveInstanceFromLayerEP5CRoomP6CLayerP9CInstance+0x41c> */
/* 池字（非指令，objdump 记为 .word）：0x00233cdc → GOT 0x3ed71c = dbg_csol */
/* @0x1b9e50 .word 0x00233cdc */
/* 池字（非指令）：0x00193c84 → 串 0x34d6d0（供 1b9a44 的 add r1,pc,r1）*/
/* @0x1b9e54 andseq r3, r9, r4, lsl #25 */
/* 池字（非指令）：0x00236c7c → GOT 0x3f086c = m_InstanceElementPool */
/* @0x1b9e58 eoreq r6, r3, r12, ror r12 */
