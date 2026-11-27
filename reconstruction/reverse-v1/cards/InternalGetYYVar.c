/* cally 逆向卡：YYObjectBase::InternalGetYYVar（原版 libyoyo.so，armv7）
 * @func 0x196a70 0x196b84  size 276  69 条指令
 * 级别: 正文（69/69 逐条锚定；CHashMap 布局、Robin-Hood 探测、未命中路径的 RValue 初值全部解码）
 * 符号: _ZN12YYObjectBase16InternalGetYYVarEi → RValue* YYObjectBase::InternalGetYYVar(int key)
 *
 * ── 一句话 ───────────────────────────────────────────────────────
 *   「按槽号取 RValue*」。槽号就是 Code_Variable_Find_Slot_From_Name 返回的那个 int（见同批卡）。
 *   命中 → 返回节点里的 RValue*；未命中 → **惰性造一个 RValue 插进去再返回**。
 *   存储是 CHashMap<int,RValue*,3>（this+0x60），不是数组；数组路线由 this+0x04 的另一套存储负责。
 *
 * ── 映射表布局（本函数读 + AllocVars/Insert 写，三方对齐；AllocVars 在 0x1917dc，非本卡范围）──
 *   +0x00 size      初始 8      Insert 里做距离计算的基数
 *   +0x04 count     初始 0      Insert 先比 count 与 threshold 再 ++
 *   +0x08 mask      初始 7      idx = hash & mask；回绕也用它
 *   +0x0c threshold 初始 4      vcvt.s32(8 * 0.6f) = 4（常量 0x3f19999a）；count > 4 时扩容
 *   +0x10 nodes     8 × 12 B    MemoryManager::Alloc(96) 后 memset，再逐节点把 +8 写 0
 *   节点 12 字节：+0 key(int)、+4 RValue*、+8 hash（0 = 空槽）
 *   hash = CHashMapCalculateHash<int>(key) = **key + 1**（0x190f40: add r0,r0,#1 / bx lr），
 *   再 bic #0x8000_0000 清符号位存进 +8。0 被留作空槽哨兵 —— 这也是 key = -1 不可用的原因。
 *
 * ── 探测算法（Robin Hood，与 Insert 同一套距离公式）────────────────────
 *   idx  = (key+1) & 0x7FFF_FFFF & mask
 *   dist = ((idx + size) - (stored & mask)) & mask
 *   首探：stored == 0 → 未命中；stored == hash → 命中（直接 0x196b5c）
 *   循环：idx=(idx+1)&mask、probe++、重算 dist；stored==0 → 未命中；stored==hash → 命中；
 *         dist < probe → 未命中（提前退出，Robin-Hood 的「后面的更近，别提了」判据）
 *   ⇒ **只比 hash，从不比节点里的 key(+0)**：因为 hash = key+1 且只清符号位，二者是单射；
 *     唯一撞车是 key 与 key^0x8000_0000（实际槽号是小正整数，永不发生）。
 *
 * ── 未命中路径：读时惰性创建 ───────────────────────────────────
 *   1) this->vars_map(+0x60) == 0 → 先 AllocVars() 建表，再重取 +0x60 回到入口（0x196b78 / 0x196b7c）
 *   2) rv = GetRValue()（0x190dc0 池分配 16 字节；整块首次 memset 过，**复用时不擦**）
 *   3) [rv+0] = 0、[rv+4] = 0、[rv+0xc] = this->+0x58、**不写 [rv+8]**
 *   4) Insert(key, rv)，返回 rv
 *   ⇒ this+0x58 是**对象级默认 tag**：基类 ctor 0x19188c 里 `str r2,[r4,#0x58]`，
 *     而 CInstance 的 ctor 在 0x199500 用 `mvn r2,#-16777216` 传入 **0x00FFFFFF**。
 *     于是「首次读一个从未赋值的实例变量」拿到的是 tag = 0x00FFFFFF 的
 *     **未解析变量引用**占位 —— 正是 DoPushLocal（0xd4af0 比较后 beq 0xd4b1c）与 DoPush/DoConv
 *     检测的那个标记。三处互证（claims IGYV-004/005/006）。
 *
 * ── 两套存储：flat 数组 vs 这张表 ──────────────────────────────
 *   YYObjectBase::FindValue(0x196b84) 先调 Find_Slot_From_Name 拿 slot，再用 this+0x04 的
 *   **16 字节步长 flat 数组**直取；只有该指针为 0 才尾跳本函数。
 *   DoPushLocal（0xd4a4c ldr r6,[r0,#4] / 0xd4a7c beq 0xd4bc8）与 DoPushGlobal（0xd4d18 一带）
 *   同一判据，且它们传的 key = 变量 id − 100000（0xd4a60 / 0xd4a68 的 99328+672）。
 *
 * ── 两处死检查（模板残留，写进卡以免被当成语义）─────────────────────
 *   0x196ad0 tst r2,r12 + 0x196ad4 bmi：mask 恒 < 0x8000_0000，bit31 永远 0 ⇒ 永不跳。
 *   0x196b64 cmn r9,#4：只有节点地址 == -4 才成立，堆指针不可能 ⇒ 永不跳
 *   （Local_Name 0xd2040 有同型指令，属于同一份模板）。
 *
 * open:
 *   1. this+0x58 在另两个构造点（CScriptRef 0x191de0 未显式装 r2；YYObjectBase::Alloc 0x191b2c
 *      传 r4 参数）分别是什么，没有逐点取证。
 *   2. 「slot = 变量 id − 100000」由 DoPushLocal 锚死；slot 是否等于「对象内声明顺序」要看
 *      Find_Slot_From_Name 卡里的两张表，尚无真机验证。
 *   3. 未写 [rv+8] 的后果未证：tag = 0x00FFFFFF 时 +8 会不会被下游读到（DoPushLocal 的某些路径
 *      确实把 +8 抄到值栈）。
 */
/* ── 入口：this=r0（进 r7）、key=r1（进 r8）；保存 r4-r10+lr */
/* @0x196a70 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x196a74 mov r7, r0 */
/* map = this+0x60（CHashMap<int,RValue*,3>*） */
/* @0x196a78 ldr r4, [r0, #0x60] */
/* @0x196a7c mov r8, r1 */
/* 空表 → AllocVars 后再回入口（读时惰性建表） */
/* @0x196a80 cmp r4, #0 */
/* @0x196a84 beq 0x196b78 <_ZN12YYObjectBase16InternalGetYYVarEi+0x108> */
/* @0x196a88 mov r0, r8 */
/* hash = key + 1（0x190f40 两条指令），0 留作空槽 */
/* @0x196a8c bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* mask = map+0x08；nodes = map+0x10；size = map+0x00（下面用） */
/* @0x196a90 ldr r12, [r4, #0x8] */
/* @0x196a94 ldr r9, [r4, #0x10] */
/* 清符号位：hash &= 0x7FFF_FFFF */
/* @0x196a98 bic r0, r0, #-2147483648 */
/* idx = mask & hash */
/* @0x196a9c and r3, r12, r0 */
/* node = nodes + 3*idx*4 = nodes + 12*idx（节点步长 12 字节） */
/* @0x196aa0 lsl r5, r3, #1 */
/* @0x196aa4 add r2, r5, r3 */
/* @0x196aa8 add r2, r9, r2, lsl #2 */
/* stored = node+0x08（哈希，0 表示空槽） */
/* @0x196aac ldr r2, [r2, #0x8] */
/* @0x196ab0 cmp r2, #0 */
/* 空槽 → 0x196b24 未命中（走惰性创建） */
/* @0x196ab4 beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* @0x196ab8 cmp r0, r2 */
/* 首探命中：hash 相等即返回（不经 -1 保护） */
/* @0x196abc beq 0x196b5c <_ZN12YYObjectBase16InternalGetYYVarEi+0xec> */
/* dist = ((idx + size) - (stored & mask)) & mask —— Robin-Hood 距离 */
/* @0x196ac0 ldr r10, [r4] */
/* @0x196ac4 and r2, r12, r2 */
/* @0x196ac8 add r1, r3, r10 */
/* @0x196acc rsb r2, r2, r1 */
/* tst + bmi：mask < 2^31 时 bit31 恒 0 ⇒ 死检查（见卡头） */
/* @0x196ad0 tst r2, r12 */
/* @0x196ad4 bmi 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* probe = 0，进入探测循环 */
/* @0x196ad8 mov r4, #0 */
/* @0x196adc b 0x196af0 <_ZN12YYObjectBase16InternalGetYYVarEi+0x80> */
/* 命中判定：只比哈希（key+1 是单射，故等价于比 key） */
/* @0x196ae0 cmp r0, r2 */
/* @0x196ae4 beq 0x196b54 <_ZN12YYObjectBase16InternalGetYYVarEi+0xe4> */
/* Robin-Hood 提前退出：dist < probe ⇒ 后面的更近，本 key 必不在 */
/* @0x196ae8 cmp r6, r4 */
/* @0x196aec blt 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* 循环体：idx = (idx+1) & mask、probe++（回绕用 mask，不是 size） */
/* @0x196af0 add r3, r3, #1 */
/* @0x196af4 add r4, r4, #1 */
/* @0x196af8 and r3, r12, r3 */
/* @0x196afc add r1, r3, r10 */
/* @0x196b00 lsl r5, r3, #1 */
/* @0x196b04 add r2, r5, r3 */
/* @0x196b08 add r2, r9, r2, lsl #2 */
/* 重取 stored，再算距离 */
/* @0x196b0c ldr r2, [r2, #0x8] */
/* @0x196b10 and r6, r12, r2 */
/* @0x196b14 cmp r2, #0 */
/* dist 在掩码域里相减后回绕 */
/* @0x196b18 rsb r6, r6, r1 */
/* @0x196b1c and r6, r6, r12 */
/* stored != 0 → 到比较点；stored == 0 → 落 0x196b24 */
/* @0x196b20 bne 0x196ae0 <_ZN12YYObjectBase16InternalGetYYVarEi+0x70> */
/* ── 未命中：GetRValue() 从池里取 16 字节 */
/* @0x196b24 bl 0x190dc0 <_Z9GetRValuev> */
/* rv->[0] = 0、rv->[4] = 0 */
/* @0x196b28 mov r3, #0 */
/* @0x196b2c mov r1, r8 */
/* @0x196b30 mov r4, r0 */
/* tag = this+0x58（对象级默认 tag；CInstance 的 ctor 传 0x00FFFFFF） */
/* @0x196b34 ldr r0, [r7, #0x58] */
/* @0x196b38 mov r2, r4 */
/* @0x196b3c str r3, [r4] */
/* @0x196b40 str r3, [r4, #0x4] */
/* 写 tag —— 注意 [rv+8] 一个字都没写（池复用时不擦） */
/* @0x196b44 str r0, [r4, #0xc] */
/* @0x196b48 ldr r0, [r7, #0x60] */
/* Insert(key, rv)（0x196408，1640 B） */
/* @0x196b4c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */
/* @0x196b50 b 0x196b70 <_ZN12YYObjectBase16InternalGetYYVarEi+0x100> */
/* 循环命中路径的 idx == -1 保护（模板约定 -1 = 未命中） */
/* @0x196b54 cmn r3, #1 */
/* @0x196b58 beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* &node = nodes + 12*idx，返回 node->value（+4） */
/* @0x196b5c add r3, r5, r3 */
/* @0x196b60 add r9, r9, r3, lsl #2 */
/* cmn r9,#4：节点地址 == -4 的空自检，堆地址永不成立 */
/* @0x196b64 cmn r9, #4 */
/* @0x196b68 ldrne r4, [r9, #0x4] */
/* @0x196b6c beq 0x196b24 <_ZN12YYObjectBase16InternalGetYYVarEi+0xb4> */
/* ── 唯一正常出口：r0 = RValue* */
/* @0x196b70 mov r0, r4 */
/* @0x196b74 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* ── map 为空：AllocVars()（建 8 槽表、mask=7、threshold=4、节点 +8 清零） */
/* @0x196b78 bl 0x1917dc <_ZN12YYObjectBase9AllocVarsEv> */
/* 重取 map，回 0x196a88 走同一条查找 */
/* @0x196b7c ldr r4, [r7, #0x60] */
/* @0x196b80 b 0x196a88 <_ZN12YYObjectBase16InternalGetYYVarEi+0x18> */
