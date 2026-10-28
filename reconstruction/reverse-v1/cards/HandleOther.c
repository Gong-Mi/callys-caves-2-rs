/* cally 逆向卡：HandleOther（原版 libyoyo.so，armv7）
 * @func 0x1ce594  size 6944  1736 条 = 1723 指令 + 13 池字（0x1cec14..0x1cec3c 11 字；
 *       0x1d00ac/0x1d00b0 是尾部 2 个池字 —— 池字一并锚，注释里标「非指令」）
 * 级别: 骨架（四类 Other 事件的事件号与派发顺序、四趟候选表遍历、每趟开头的创建计数器
 *             快照、房间/视口两套边界谓词、包围盒惰性重算、profiler 段号已逐条钉住；
 *             未钉：0x536F70 / 0x53AB70 两个 .bss 聚合体的完整布局与维护者、
 *             旋转视口四边平面判定的精确几何（只钉到「逐边叉积 < 0 即在外」）、
 *             0x5428E8（Zeus）为何决定视口取矩形的路径、视口矩形取整后 ±1 的边界约定）
 * 符号: _Z11HandleOtherv → void HandleOther()
 * 同层: DoAStep 0x1d32c0 的 Update 段在 HandleInstanceMovement 之后、HandleAsyncEvents
 *       之前调本函数（1d34b4）；HandleStep 0x1cdf6c / HandleAlarm 0x1cdd70 与本函数共用
 *       同一套「事件候选表 → g_ObjectHash → 实例链」写法；Perform_Event 0xf3380、
 *       CInstance::Compute_BoundingBox 0x192340、Sprite_Exists 0x1eee98、
 *       CProfiler::Push/Pop 0x2a0738 / 0x2a08ac、CCameraManager::GetCamera 0x16f45c、
 *       CCamera::GetInvViewProjMat 0x16d260、HandleTimeLine 0x1d00b4（紧接本函数之后）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   本函数 **不跑 Step、不做碰撞检测、不碰 hspeed/vspeed(+0xe0/+0xe4)、不写重力/摩擦**。
 *   它只把 GameMaker「Other」事件按固定顺序派发一轮（事件类型恒为 7）：
 *
 *       ① Other 0    Outside Room              （1cec08，r3=0，边沿去重）
 *       ② Other 1    Intersect Boundary        （1ce900，r3=#1）
 *       ③ Other 40+i Outside View i    i=0..7  （1cf090，r3=r8=i+40）
 *       ④ Other 50+i Intersect Boundary View i （1cf3ac，r3=[sp+0x44]=i+50）
 *
 *   ①③ 是「完全在外」谓词，②④ 是「跨边」谓词；只有 ① 带 byte +0x15E 的边沿去重。
 *   每一趟都先给全局创建计数器拍一次快照，本趟开始后新建的实例收不到本趟事件。
 *
 * ── 遍历协议（四趟同构）────────────────────────────────────────
 *   1) 事件候选表：0x53AB70 + 0x3804 + 8×事件号 处是一个指针，指向「有该事件的对象 id 数组」；
 *      数组长度在 0x536F70 的平行计数数组里（① 用 +0x1C00，② 用 +0x1C04，
 *      ③ 用 +0x1CA0+4i，④ 用 +0x1CC8+32i）。
 *   2) 对每个对象 id，在 g_ObjectHash（GOT 0x3EDC44 → 0x542374，指针变量）里做
 *      开放链哈希查找：结构 {+0 桶数组, +4 掩码}，桶 8 B，节点 {+4 next, +8 key, +0xC value}。
 *   3) value+0xC4 是该对象的实例链头，节点 {+0 next, +8 CInstance*}。
 *   4) 逐实例四道闸门：+0x68/+0x69 非 0 跳过；[inst+0x70]（8 B 创建序）> 本趟快照跳过；
 *      sprite_index(+0x8C) 与 mask_index(+0xAC) 都不存在 → 退化成 (x,y) 点判；
 *      +0x64 非 0 → 先 Compute_BoundingBox(inst, true)。
 *   5) 三个循环变量互不干扰：i 走 id 数组，r4/r9/r5 走实例链，r10/r11 走候选表基址。
 *
 * ── CInstance 字段（本函数读到的，全为实测）─────────────────────
 *   +0x64 byte 包围盒脏（非 0 先重算）           +0x68/+0x69 byte 非 0 跳过
 *   +0x70 int64 创建序（与快照比）               +0x8C int sprite_index
 *   +0xAC int mask_index                         +0xB4/+0xB8 float x/y
 *   +0xE8/+0xEC/+0xF0/+0xF4 **int32** tagYYRECT 左/上/右/下
 *   ⚠ 修正（batchAI，cards/CInstance_Compute_BoundingBox.c）：不是 float —— 写入是
 *     vcvt.s32.f32 + vstr、CollisionUpdate 用 ldr 当 int* 传给 RTree；四判用整数比较是对的
 *   +0x15E byte 「已在房间外」边沿标志（本函数**唯一**的实例写）
 *
 * ── 全局（GOT → .bss/.data，实测）──────────────────────────────
 *   0x3EDB70 → 0x757E7C  g_bProfile（1 B）        0x3EDB74 → 0x757E80 g_Profiler
 *   0x3ED930 → 0x54298C  &Run_Room（CRoom*）      0x3EDC44 → 0x542374 &g_ObjectHash
 *   0x3EFB0C → 0x536F20  ms_CurrentCreateCounter（8 B，契约 live-oracle §3.3）
 *   0x3EFB10 → 0x536F70  事件候选计数/视口聚合体   0x3EFB14 → 0x53AB70 事件候选 id 表
 *   0x3ED92C → 0x5428E8  g_isZeus（DoBreak 卡命名）  0x3EDC7C → 0x48F78C CCameraManager 单例
 *
 * ── profiler ───────────────────────────────────────────────────
 *   g_bProfile 非 0：入口 CProfiler::Push(0x757E80, 6, 10)，出口尾调 CProfiler::Pop()
 *   （段号 10；对照 UpdateActiveLists 同类写法段号 7）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 帧与 profiler 闸门 ──────────────────────────────────────────
 *   push {r4-r11,lr} + vpush {d8-d11} + sub sp,#828（828 B 局部区：4 组 int 视口矩形、
 *   8 份 32 B 角点/边向量、8 个 float 角度、8 个候选计数指针、4 个计数器快照）
 *   r12 = GOT 基址 0x3F1C58（pc 0x1CE5AC + 0x2236AC），存 [sp+0x40] 备用
 *   [GOT-0x40E8] = 0x757E7C = g_bProfile；非 0 先去 1d000c 压一个 profiler 段再回来
 */
/* @0x1ce594 ldr r12, [pc, #0x680] —— r12 = 0x2236AC（配合 1ce5a4 得 GOT 基址 0x3F1C58） */
/* @0x1ce598 ldr r3, [pc, #0x680] —— r3 = -0x40E8 → GOT 槽 0x3EDB70 = 0x757E7C（g_bProfile） */
/* @0x1ce59c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ce5a0 vpush {d8, d9, d10, d11} */
/* @0x1ce5a4 add r12, pc, r12 —— r12 = pc + r12 = 0x3F1C58 = GOT 基址 */
/* @0x1ce5a8 sub sp, sp, #828 —— 局部区 828 B（0x33C） */
/* @0x1ce5ac str r12, [sp, #0x40] —— [sp+0x40] = GOT 基址 */
/* @0x1ce5b0 ldr r3, [r12, r3] —— r3 = [GOT 0x3EDB70] = &g_bProfile（1 字节开关） */
/* @0x1ce5b4 str r3, [sp, #0x54] */
/* @0x1ce5b8 ldrb r3, [r3] */
/* @0x1ce5bc cmp r3, #0 */
/* @0x1ce5c0 bne 0x1d000c <_Z11HandleOtherv+0x1a78> —— g_bProfile 非 0 → 1d000c（先 CProfiler::Push(0x757E80,6,10)） */
/* ── 装载全局 + 第 1 趟快照（Outside Room）───────────────────────
 *   [sp+0x44] = 0x536F20 = ms_CurrentCreateCounter（8 B）：ldrd 旧值 → 存 [sp+8]（快照①）
 *    → adds/adc +1 → strd 回写。此后整趟都用「旧值」比较。
 *   [sp+0x48] = 0x536F70（事件候选计数聚合体），count1 = [0x536F70+0x1C00]；<=0 跳 1d0044
 *   r10 = &Run_Room→[sp+0x3C]；r6 = 0x53AB70→[sp+0x18]；r7 = &g_ObjectHash；r11 = 0x536F70
 *   r9 = 0x3804 = 第 0 号事件的候选 id 表偏移（0x53AB70+0x3804）
 */
/* @0x1ce5c4 ldr r12, [sp, #0x40] —— ← 1d0020 回到这里（profiler 已压段） */
/* @0x1ce5c8 mov r8, #7168 —— r8 = 7168 = 0x1C00（第 0 号事件的候选计数偏移） */
/* @0x1ce5cc ldr r3, [pc, #0x650] —— -0x214C → 槽 0x3EFB0C = 0x536F20 */
/* @0x1ce5d0 ldr r1, [pc, #0x650] —— -0x2148 → 槽 0x3EFB10 = 0x536F70 */
/* @0x1ce5d4 ldr r3, [r12, r3] —— r3 = 0x536F20 = ms_CurrentCreateCounter（8 B） */
/* @0x1ce5d8 str r3, [sp, #0x44] —— [sp+0x44] = &计数器 */
/* @0x1ce5dc ldrd r2, r3, [r3] —— ldrd 旧值（lo,hi） */
/* @0x1ce5e0 ldr r12, [sp, #0x44] */
/* @0x1ce5e4 strd r2, r3, [sp, #8] —— 快照① → [sp+8] */
/* @0x1ce5e8 adds r2, r2, #1 —— 旧值 +1 */
/* @0x1ce5ec adc r3, r3, #0 —— 进位 */
/* @0x1ce5f0 strd r2, r3, [r12] —— 写回全局计数器（第 1 次自增） */
/* @0x1ce5f4 ldr r12, [sp, #0x40] */
/* @0x1ce5f8 ldr r1, [r12, r1] —— r1 = [GOT 0x3EFB10] = 0x536F70（事件候选计数聚合体） */
/* @0x1ce5fc str r1, [sp, #0x48] —— [sp+0x48] = 0x536F70 */
/* @0x1ce600 ldr r1, [r1, r8] —— count1 = [0x536F70+0x1C00] */
/* @0x1ce604 cmp r1, #0 */
/* @0x1ce608 ble 0x1d0044 <_Z11HandleOtherv+0x1ab0> —— count1 <= 0 → 1d0044（跳过第 1 趟，但仍要装 r10） */
/* @0x1ce60c ldr r3, [pc, #0x618] —— -0x4328 → 槽 0x3ED930 = 0x54298C = &Run_Room */
/* @0x1ce610 mov r5, #0 —— i = 0 */
/* @0x1ce614 ldr r2, [pc, #0x61c] —— -0x2144 → 槽 0x3EFB14 = 0x53AB70（候选 id 表基址） */
/* @0x1ce618 movw r9, #0x3804 —— r9 = 0x3804 = 事件 0 的候选 id 表偏移 */
/* @0x1ce61c ldr r1, [pc, #0x618] —— -0x4014 → 槽 0x3EDC44 = 0x542374 = &g_ObjectHash */
/* @0x1ce620 ldr r3, [r12, r3] —— r3 = &Run_Room */
/* @0x1ce624 ldr r6, [r12, r2] —— r6 = 0x53AB70 */
/* @0x1ce628 ldr r11, [sp, #0x48] —— r11 = 0x536F70 */
/* @0x1ce62c mov r10, r3 —— r10 = &Run_Room（[r10] 才是 CRoom*） */
/* @0x1ce630 ldr r7, [r12, r1] —— r7 = &g_ObjectHash（指针变量，再解一层） */
/* @0x1ce634 str r3, [sp, #0x3c] —— [sp+0x3c] = &Run_Room */
/* @0x1ce638 str r6, [sp, #0x18] —— [sp+0x18] = 0x53AB70 */
/* ── ① Outside Room：按对象 id 列表遍历（i = r5）──────────────────
 *   ids = *(int**)(0x53AB70 + 0x3804)；id = ids[i]；i 上限 = [0x536F70+0x1C00]
 *   对每个 id 在 g_ObjectHash 里查：(buckets=[*h], mask=[*h+4], 桶步长 8 B)
 */
/* @0x1ce63c ldr r12, [sp, #0x18] —— 循环头：r12 = 0x53AB70 */
/* @0x1ce640 ldr r3, [r7] —— r3 = *g_ObjectHash = {+0 桶数组, +4 掩码} */
/* @0x1ce644 ldr r1, [r12, r9] —— r1 = *(int**)(0x53AB70+0x3804) = 候选 id 数组 */
/* @0x1ce648 ldr r2, [r3, #0x4] —— 掩码 */
/* @0x1ce64c ldr r3, [r3] —— 桶数组 */
/* @0x1ce650 ldr r1, [r1, r5, lsl #2] —— id = ids[i] */
/* @0x1ce654 and r2, r1, r2 —— h = id & mask */
/* @0x1ce658 ldr r3, [r3, r2, lsl #3] —— node = buckets[h]（桶步长 8 B） */
/* @0x1ce65c cmp r3, #0 —— node == 0 → 换下一个 id */
/* @0x1ce660 bne 0x1ce674 <_Z11HandleOtherv+0xe0> */
/* @0x1ce664 b 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* ── 哈希链：节点 {+4 next, +8 key, +0xC value}，按完整 id 比对 ──── */
/* @0x1ce668 ldr r3, [r3, #0x4] —— node = node->next（+4） */
/* @0x1ce66c cmp r3, #0 */
/* @0x1ce670 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce674 ldr r2, [r3, #0x8] —— key = node->key（+8） */
/* @0x1ce678 cmp r1, r2 */
/* @0x1ce67c bne 0x1ce668 <_Z11HandleOtherv+0xd4> —— key != id → 继续走链 */
/* @0x1ce680 ldr r3, [r3, #0xc] —— value = node->value（+0xC） */
/* @0x1ce684 cmp r3, #0 */
/* @0x1ce688 ldrne r4, [r3, #0xc4] —— r4 = value->[0xC4] = 对象实例链头 */
/* @0x1ce68c beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* ── 实例链：value+0xC4 是链头，节点 {+0 next, +8 CInstance*} ───────
 *   r6 = inst，r4 = 下一个链节点；链空即回外层换 id
 */
/* @0x1ce690 cmp r4, #0 —— 实例链循环：r4 为链节点 */
/* @0x1ce694 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce698 ldr r3, [r4, #0x8] —— node->inst（+8）判空 */
/* @0x1ce69c cmp r3, #0 */
/* @0x1ce6a0 beq 0x1ce768 <_Z11HandleOtherv+0x1d4> */
/* @0x1ce6a4 ldr r6, [r4, #0x8] —— r6 = CInstance* */
/* @0x1ce6a8 ldr r4, [r4] —— r4 = node->next（+0） */
/* @0x1ce6ac ldrb r3, [r6, #0x68] —— 闸门：软销毁标记 +0x68 */
/* @0x1ce6b0 cmp r3, #0 */
/* @0x1ce6b4 bne 0x1ce690 <_Z11HandleOtherv+0xfc> */
/* @0x1ce6b8 ldrb r3, [r6, #0x69] —— 闸门：硬销毁标记 +0x69 */
/* @0x1ce6bc cmp r3, #0 */
/* @0x1ce6c0 bne 0x1ce690 <_Z11HandleOtherv+0xfc> */
/* ── 三道闸门：销毁标记 / 创建序 / 精灵存在性 ─────────────────────
 *   [inst+0x68] 或 [inst+0x69] 非 0 → 跳过（软/硬销毁标记，见 DoDestroy 卡）
 *   [inst+0x70..0x77]（8 B 创建序）> 快照① → 跳过：本趟开始后新建的实例不收本趟事件
 *   Sprite_Exists(inst->sprite_index[+0x8C])；不存在 → 1ceb90 再试 mask_index[+0xAC]
 */
/* @0x1ce6c4 ldrd r2, r3, [r6, #112] —— ldrd [inst+0x70] = 8 B 创建序 */
/* @0x1ce6c8 ldrd r0, r1, [sp, #8] —— 快照① */
/* @0x1ce6cc cmp r0, r2 —— 64 位比较 */
/* @0x1ce6d0 sbcs r1, r1, r3 */
/* @0x1ce6d4 blt 0x1ce690 <_Z11HandleOtherv+0xfc> —— 创建序 > 快照 → 跳过（本趟新建） */
/* @0x1ce6d8 ldr r0, [r6, #0x8c] —— sprite_index */
/* @0x1ce6dc bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists(sprite_index) */
/* @0x1ce6e0 cmp r0, #0 */
/* @0x1ce6e4 beq 0x1ceb90 <_Z11HandleOtherv+0x5fc> —— 无 sprite → 1ceb90 试 mask_index */
/* ── 包围盒 + 「完全在房间外」四判 ───────────────────────────────
 *   [inst+0x64] 非 0 → 1cf828：Compute_BoundingBox(inst,true) 后回 1ce6f4 重判
 *   四判（全用整数比较，bbox 是 float 但非负 float 的位模式可当有符号整数比）：
 *     右 +0xF0 < 0 → 外；左 +0xE8 > room->[+0x10] → 外；
 *     下 +0xF4 < 0 → 外；上 +0xEC > room->[+0x14] → 外
 *   room = *(&Run_Room)，宽高是 int（1ce70c/1ce74c 才 ldr 出来）
 */
/* @0x1ce6e8 ldrb r3, [r6, #0x64] —— bbox 脏标记 +0x64 */
/* @0x1ce6ec cmp r3, #0 */
/* @0x1ce6f0 bne 0x1cf828 <_Z11HandleOtherv+0x1294> —— 脏 → 1cf828 重算后回 1ce6f4 */
/* @0x1ce6f4 ldr r3, [r6, #0xf0] —— 框右 +0xF0 */
/* @0x1ce6f8 cmp r3, #0 */
/* @0x1ce6fc blt 0x1cebec <_Z11HandleOtherv+0x658> —— 右 < 0 → 完全在外（1cebec） */
/* @0x1ce700 ldrb r3, [r6, #0x64] */
/* @0x1ce704 cmp r3, #0 */
/* @0x1ce708 bne 0x1cf990 <_Z11HandleOtherv+0x13fc> */
/* @0x1ce70c ldr r3, [r10] —— room = *(&Run_Room) */
/* @0x1ce710 ldr r2, [r6, #0xe8] */
/* @0x1ce714 ldr r3, [r3, #0x10] —— 房间宽 [+0x10]（int） */
/* @0x1ce718 cmp r2, r3 */
/* @0x1ce71c bgt 0x1cebec <_Z11HandleOtherv+0x658> —— 左 +0xE8 > 宽 → 完全在外 */
/* @0x1ce720 ldrb r3, [r6, #0x64] —— bbox 脏标记（第二段） */
/* @0x1ce724 cmp r3, #0 */
/* @0x1ce728 bne 0x1cfa60 <_Z11HandleOtherv+0x14cc> —— 脏 → 1cfa60 重算后回 1ce72c */
/* @0x1ce72c ldr r3, [r6, #0xf4] —— 框下 +0xF4 */
/* @0x1ce730 cmp r3, #0 */
/* @0x1ce734 blt 0x1cebec <_Z11HandleOtherv+0x658> —— 下 < 0 → 完全在外 */
/* @0x1ce738 ldrb r3, [r6, #0x64] —— bbox 脏标记（第三段） */
/* @0x1ce73c cmp r3, #0 */
/* @0x1ce740 bne 0x1cfc94 <_Z11HandleOtherv+0x1700> —— 脏 → 1cfc94 重算后回 1ce744 */
/* @0x1ce744 ldr r3, [r10] —— room */
/* @0x1ce748 ldr r2, [r6, #0xec] —— 框上 +0xEC */
/* @0x1ce74c ldr r3, [r3, #0x14] —— 房间高 [+0x14]（int） */
/* @0x1ce750 cmp r2, r3 */
/* @0x1ce754 bgt 0x1cebec <_Z11HandleOtherv+0x658> —— 上 > 高 → 完全在外 */
/* ── 收尾：在内 → 清边沿标志；在外 → 1cebec 派发（去重）─────────── */
/* @0x1ce758 mov r3, #0 —— 四判全不中：r3 = 0 */
/* @0x1ce75c cmp r4, #0 */
/* @0x1ce760 strb r3, [r6, #0x15e] —— [inst+0x15E] = 0（本函数唯一的实例写） */
/* @0x1ce764 bne 0x1ce698 <_Z11HandleOtherv+0x104> */
/* @0x1ce768 ldr r3, [r11, r8] —— count1 */
/* @0x1ce76c add r5, r5, #1 —— i++ */
/* @0x1ce770 cmp r3, r5 */
/* @0x1ce774 bgt 0x1ce63c <_Z11HandleOtherv+0xa8> —— i < count1 → 下一个 id */
/* ── 第 2 趟快照（Intersect Boundary）────────────────────────────
 *   再 ldrd 当前计数器 → 存 [sp+8]（覆盖快照①）→ +1 回写（第 2 次自增）
 *   count2 = [0x536F70+0x1C04]；<=0 → 1ce91c（直接去视口段）
 *   r9 换成 0x380C = 第 1 号事件的候选 id 表偏移
 */
/* @0x1ce778 ldr r1, [sp, #0x44] —— [sp+0x44] = &计数器 */
/* @0x1ce77c ldrd r0, r1, [r1] —— ldrd 当前值 */
/* @0x1ce780 strd r0, r1, [sp, #8] —— 快照②（覆盖 [sp+8]） */
/* @0x1ce784 ldr r12, [sp, #0x48] */
/* @0x1ce788 movw r8, #0x1c04 */
/* @0x1ce78c ldrd r2, r3, [sp, #8] */
/* @0x1ce790 ldr r1, [r12, r8] —— count2 = [0x536F70+0x1C04] */
/* @0x1ce794 adds r2, r2, #1 —— +1 */
/* @0x1ce798 ldr r12, [sp, #0x44] */
/* @0x1ce79c adc r3, r3, #0 */
/* @0x1ce7a0 cmp r1, #0 */
/* @0x1ce7a4 strd r2, r3, [r12] —— 第 2 次自增 */
/* @0x1ce7a8 ble 0x1ce91c <_Z11HandleOtherv+0x388> —— count2 <= 0 → 1ce91c（直接去视口段） */
/* @0x1ce7ac ldr r12, [sp, #0x40] */
/* @0x1ce7b0 mov r5, #0 */
/* @0x1ce7b4 ldr r3, [pc, #0x47c] —— -0x2144 → 0x53AB70 */
/* @0x1ce7b8 movw r9, #0x380c */
/* @0x1ce7bc ldr r2, [pc, #0x478] —— -0x4014 → &g_ObjectHash */
/* @0x1ce7c0 ldr r10, [sp, #0x3c] —— [sp+0x3c] = &Run_Room */
/* @0x1ce7c4 ldr r6, [r12, r3] —— r6 = 0x53AB70 */
/* @0x1ce7c8 ldr r11, [sp, #0x48] —— r11 = 0x536F70 */
/* @0x1ce7cc ldr r7, [r12, r2] —— r7 = &g_ObjectHash */
/* @0x1ce7d0 str r6, [sp, #0x18] —— [sp+0x18] = 0x53AB70 */
/* ── ② Intersect Boundary：同一套 id→hash→实例链遍历 ─────────────── */
/* @0x1ce7d4 ldr r12, [sp, #0x18] */
/* @0x1ce7d8 ldr r3, [r7] —— 第 2 趟的 hash 查找（同 1ce640 结构） */
/* @0x1ce7dc ldr r1, [r12, r9] */
/* @0x1ce7e0 ldr r2, [r3, #0x4] */
/* @0x1ce7e4 ldr r3, [r3] */
/* @0x1ce7e8 ldr r1, [r1, r5, lsl #2] */
/* @0x1ce7ec and r2, r1, r2 */
/* @0x1ce7f0 ldr r3, [r3, r2, lsl #3] */
/* @0x1ce7f4 cmp r3, #0 */
/* @0x1ce7f8 bne 0x1ce80c <_Z11HandleOtherv+0x278> */
/* @0x1ce7fc b 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce800 ldr r3, [r3, #0x4] */
/* @0x1ce804 cmp r3, #0 */
/* @0x1ce808 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce80c ldr r2, [r3, #0x8] */
/* @0x1ce810 cmp r1, r2 */
/* @0x1ce814 bne 0x1ce800 <_Z11HandleOtherv+0x26c> */
/* @0x1ce818 ldr r3, [r3, #0xc] */
/* @0x1ce81c cmp r3, #0 */
/* @0x1ce820 ldrne r4, [r3, #0xc4] */
/* @0x1ce824 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce828 cmp r4, #0 */
/* @0x1ce82c beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce830 ldr r3, [r4, #0x8] */
/* @0x1ce834 cmp r3, #0 */
/* @0x1ce838 beq 0x1ce90c <_Z11HandleOtherv+0x378> */
/* @0x1ce83c ldr r6, [r4, #0x8] */
/* @0x1ce840 ldr r4, [r4] */
/* @0x1ce844 ldrb r3, [r6, #0x68] */
/* @0x1ce848 cmp r3, #0 */
/* @0x1ce84c bne 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce850 ldrb r3, [r6, #0x69] */
/* @0x1ce854 cmp r3, #0 */
/* @0x1ce858 bne 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce85c ldrd r2, r3, [r6, #112] */
/* @0x1ce860 ldrd r0, r1, [sp, #8] */
/* @0x1ce864 cmp r0, r2 */
/* @0x1ce868 sbcs r1, r1, r3 */
/* @0x1ce86c blt 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1ce870 ldr r0, [r6, #0x8c] */
/* @0x1ce874 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1ce878 cmp r0, #0 */
/* @0x1ce87c beq 0x1cf6a8 <_Z11HandleOtherv+0x1114> —— 无 sprite → 1cf6a8 试 mask */
/* ── 「跨房间边界」四判（每帧都发，无去重）────────────────────────
 *   左 +0xE8 < 0 / 右 +0xF0 > room 宽 / 上 +0xEC < 0 / 下 +0xF4 > room 高
 *   任一命中 → 1ce8f0 派发；四判全不中 → 下一个实例
 */
/* @0x1ce880 ldrb r3, [r6, #0x64] */
/* @0x1ce884 cmp r3, #0 */
/* @0x1ce888 bne 0x1cf838 <_Z11HandleOtherv+0x12a4> —— bbox 脏 → 1cf838 重算后回 1ce88c */
/* @0x1ce88c ldr r3, [r6, #0xe8] —— 框左 +0xE8 */
/* @0x1ce890 cmp r3, #0 */
/* @0x1ce894 blt 0x1ce8f0 <_Z11HandleOtherv+0x35c> —— 左 < 0 → 跨边界 */
/* @0x1ce898 ldrb r3, [r6, #0x64] —— bbox 脏（第二段） */
/* @0x1ce89c cmp r3, #0 */
/* @0x1ce8a0 bne 0x1cf9a0 <_Z11HandleOtherv+0x140c> —— 脏 → 1cf9a0 重算后回 1ce8a4 */
/* @0x1ce8a4 ldr r3, [r10] —— room */
/* @0x1ce8a8 ldr r2, [r6, #0xf0] */
/* @0x1ce8ac ldr r3, [r3, #0x10] —— 房间宽 */
/* @0x1ce8b0 cmp r2, r3 */
/* @0x1ce8b4 bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> —— 右 > 宽 → 跨边界 */
/* @0x1ce8b8 ldrb r3, [r6, #0x64] —— bbox 脏（第三段） */
/* @0x1ce8bc cmp r3, #0 */
/* @0x1ce8c0 bne 0x1cfa50 <_Z11HandleOtherv+0x14bc> —— 脏 → 1cfa50 重算后回 1ce8c4 */
/* @0x1ce8c4 ldr r3, [r6, #0xec] —— 框上 +0xEC */
/* @0x1ce8c8 cmp r3, #0 */
/* @0x1ce8cc blt 0x1ce8f0 <_Z11HandleOtherv+0x35c> —— 上 < 0 → 跨边界 */
/* @0x1ce8d0 ldrb r3, [r6, #0x64] —— bbox 脏（第四段） */
/* @0x1ce8d4 cmp r3, #0 */
/* @0x1ce8d8 bne 0x1cfca4 <_Z11HandleOtherv+0x1710> —— 脏 → 1cfca4 重算后回 1ce8dc */
/* @0x1ce8dc ldr r3, [r10] —— room */
/* @0x1ce8e0 ldr r2, [r6, #0xf4] */
/* @0x1ce8e4 ldr r3, [r3, #0x14] —— 房间高 */
/* @0x1ce8e8 cmp r2, r3 */
/* @0x1ce8ec ble 0x1ce828 <_Z11HandleOtherv+0x294> —— 下 > 高 → 跨边界 */
/* ── 派发 Other 1：Perform_Event(inst, inst, 7, 1) ───────────────── */
/* @0x1ce8f0 mov r0, r6 —— r0 = inst */
/* @0x1ce8f4 mov r2, #7 —— 事件类型 7 = Other */
/* @0x1ce8f8 mov r1, r6 —— r1 = inst（other = self） */
/* @0x1ce8fc mov r3, #1 —— 事件号 1 = Intersect Boundary */
/* @0x1ce900 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> —— Perform_Event(inst, inst, 7, 1) */
/* @0x1ce904 cmp r4, #0 */
/* @0x1ce908 bne 0x1ce830 <_Z11HandleOtherv+0x29c> */
/* @0x1ce90c ldr r3, [r11, r8] —— count2 */
/* @0x1ce910 add r5, r5, #1 */
/* @0x1ce914 cmp r3, r5 */
/* @0x1ce918 bgt 0x1ce7d4 <_Z11HandleOtherv+0x240> —— i < count2 → 下一个 id */
/* ── 视口几何：8 个视图各算一个世界坐标矩形 ──────────────────────
 *   栈上四组 int 数组：x(+120)/y(+152)/x2(+184)/y2(+216)，每组 8 个 int；
 *   8 份 32 B 角点记录（+88 起是角度、+312 起 4 个 float、+568 起 4 条边向量）；
 *   角度数组 [sp+0x58..0x74] 先清零（8 个 float）。
 *   s17 = 1e-05（角度阈值）、s19 = 0.0174533（度→弧度）、s18 = -1.0（「角度未知」哨兵）、
 *   s16 = 0.5（旋转角点路径取半宽/半高）
 */
/* @0x1ce91c vmov.f32 s16, #5.000000e-01 —— s16 = 0.5（旋转角点路径取半宽/半高） */
/* @0x1ce920 add r3, sp, #324 */
/* @0x1ce924 add r12, sp, #316 */
/* @0x1ce928 add r4, sp, #568 */
/* @0x1ce92c add r9, sp, #320 */
/* @0x1ce930 add r5, sp, #312 */
/* @0x1ce934 add r8, sp, #336 */
/* @0x1ce938 mov r2, #0 */
/* @0x1ce93c mov r11, r3 */
/* @0x1ce940 str r12, [sp, #0x34] */
/* @0x1ce944 mov r6, r2 */
/* @0x1ce948 str r2, [sp, #0x58] */
/* @0x1ce94c str r2, [sp, #0x5c] */
/* @0x1ce950 mov r7, r2 */
/* @0x1ce954 str r2, [sp, #0x60] */
/* @0x1ce958 mov r10, r12 */
/* @0x1ce95c str r2, [sp, #0x64] */
/* @0x1ce960 add r12, sp, #88 */
/* @0x1ce964 str r2, [sp, #0x68] */
/* @0x1ce968 vldr s17, [pc, #676] —— s17 = 1e-05（角度阈值；池字 0x1cec14 = 0x38D1B717） */
/* @0x1ce96c vmov.f32 s18, #-1.000000e+00 —— s18 = -1.0（角度数组哨兵） */
/* @0x1ce970 str r2, [sp, #0x6c] */
/* @0x1ce974 str r2, [sp, #0x70] */
/* @0x1ce978 vldr s19, [pc, #664] —— s19 = 0.0174533（度→弧度；池字 0x1cec18 = 0x3C8EFA35） */
/* @0x1ce97c str r2, [sp, #0x74] */
/* @0x1ce980 add r2, sp, #248 */
/* @0x1ce984 str r12, [sp, #0x4c] */
/* @0x1ce988 str r2, [sp, #0x10] */
/* ── 逐视图开关：room+0x44（view_enabled 字节）+ view[i][0]（可见字节）──
 *   view 数组 = room+0x48+4i（(18+i)*4）；不可见/未启用的视图整段跳过（1ced9c）
 */
/* @0x1ce98c ldr r12, [sp, #0x3c] —— r12 = &Run_Room，r1 = CRoom* */
/* @0x1ce990 ldr r1, [r12] */
/* @0x1ce994 ldrb r0, [r1, #0x44] —— room+0x44（按位置记为 view_enabled） */
/* @0x1ce998 cmp r0, #0 */
/* @0x1ce99c beq 0x1ced9c <_Z11HandleOtherv+0x808> —— 未启用视图 → 1ced9c */
/* @0x1ce9a0 add r12, r7, #18 —— r12 = 18 + i，随后 lsl #2 得 (18+i)*4 = 0x48 + 4i */
/* @0x1ce9a4 ldr r1, [r1, r12, lsl #2] —— r1 = room->view[i] */
/* @0x1ce9a8 ldrb r0, [r1] —— view->[0] = 可见字节 */
/* @0x1ce9ac cmp r0, #0 */
/* @0x1ce9b0 beq 0x1ced9c <_Z11HandleOtherv+0x808> —— 不可见 → 1ced9c */
/* @0x1ce9b4 ldr r0, [pc, #0x274] —— -0x432C → 槽 0x3ED92C = 0x5428E8（DoBreak 卡记为 g_isZeus） */
/* @0x1ce9b8 ldr r2, [sp, #0x40] */
/* @0x1ce9bc ldr r0, [r2, r0] */
/* @0x1ce9c0 ldrb r0, [r0] —— 读该字节 */
/* @0x1ce9c4 cmp r0, #0 */
/* @0x1ce9c8 beq 0x1cec40 <_Z11HandleOtherv+0x6ac> —— ==0（非 Zeus）→ 1cec40：直接读 view 字段算矩形 */
/* ── 相机路径：GetCamera(view->[0x40]) → IsViewDirty → CameraUpdate ──
 *   只有 0x5428E8 字节非 0（Zeus/调试标志）才走矩阵路径；为 0 时走 1cec40 直读 view 字段
 */
/* @0x1ce9cc ldr r12, [sp, #0x40] */
/* @0x1ce9d0 ldr r0, [pc, #0x25c] —— -0x3FDC → 槽 0x3EDC7C = 0x48F78C（CCameraManager 单例） */
/* @0x1ce9d4 ldr r1, [r1, #0x40] —— r1 = view->[0x40] = 相机号 */
/* @0x1ce9d8 ldr r0, [r12, r0] */
/* @0x1ce9dc bl 0x16f45c <_ZN14CCameraManager9GetCameraEi> —— CCameraManager::GetCamera(camera_no) */
/* @0x1ce9e0 subs r1, r0, #0 */
/* @0x1ce9e4 beq 0x1cfe24 <_Z11HandleOtherv+0x1890> —— 相机为空 → 1cfe24（矩形填 -1） */
/* @0x1ce9e8 str r1, [sp, #0x4] */
/* @0x1ce9ec bl 0x16d378 <_ZN7CCamera11IsViewDirtyEv> —— CCamera::IsViewDirty() */
/* @0x1ce9f0 ldr r1, [sp, #0x4] */
/* @0x1ce9f4 cmp r0, #0 */
/* @0x1ce9f8 beq 0x1cea0c <_Z11HandleOtherv+0x478> */
/* @0x1ce9fc mov r0, r1 */
/* @0x1cea00 str r1, [sp, #0x4] */
/* @0x1cea04 bl 0x170b30 <_ZN7CCamera12CameraUpdateEv> —— CCamera::CameraUpdate() */
/* @0x1cea08 ldr r1, [sp, #0x4] */
/* @0x1cea0c add r0, sp, #248 */
/* @0x1cea10 bl 0x16d260 <_ZN7CCamera17GetInvViewProjMatEv> —— CCamera::GetInvViewProjMat(&mat)（mat 在 sp+248） */
/* ── 由逆 view-proj 矩阵算 4 角（只取第 0/1 行 + 平移，不做 w 除法）────
 *   矩阵 16 float 在 sp+248：x = m0*sx + m1*sy + m12，y = m4*sx + m5*sy + m13
 *   （正交相机下 w=1，故与投影结果一致）；4 个角写成 4 组 (x,y) 8 个 float：
 *   sp+312/316、320/324、328/332、336/340
 */
/* @0x1cea14 vldr s5, [sp, #248] —— 读矩阵 16 float（m[0],m[1],m[2],m[4],m[5],m[6],m[8]…） */
/* @0x1cea18 vldr s6, [sp, #264] */
/* @0x1cea1c vldr s10, [sp, #252] */
/* @0x1cea20 vsub.f32 s12, s6, s5 */
/* @0x1cea24 vldr s7, [sp, #268] */
/* @0x1cea28 vldr s8, [sp, #296] */
/* @0x1cea2c vldr s9, [sp, #300] */
/* @0x1cea30 vadd.f32 s14, s6, s5 */
/* @0x1cea34 vneg.f32 s4, s10 */
/* @0x1cea38 vneg.f32 s11, s5 */
/* @0x1cea3c vsub.f32 s13, s7, s10 */
/* @0x1cea40 vadd.f32 s15, s7, s10 */
/* @0x1cea44 vsub.f32 s11, s11, s6 */
/* @0x1cea48 vsub.f32 s10, s10, s7 */
/* @0x1cea4c vsub.f32 s6, s5, s6 */
/* @0x1cea50 vsub.f32 s7, s4, s7 */
/* @0x1cea54 vadd.f32 s12, s12, s8 */
/* @0x1cea58 vadd.f32 s14, s14, s8 */
/* @0x1cea5c vstr s12, [r5] */
/* @0x1cea60 vadd.f32 s13, s13, s9 */
/* @0x1cea64 vadd.f32 s15, s15, s9 */
/* @0x1cea68 vstr s13, [r10] */
/* @0x1cea6c vstr s14, [r9] */
/* @0x1cea70 vadd.f32 s11, s11, s8 */
/* @0x1cea74 vstr s15, [r11] */
/* @0x1cea78 vadd.f32 s10, s10, s9 */
/* @0x1cea7c vadd.f32 s8, s6, s8 */
/* @0x1cea80 vstr s10, [r5, #20] */
/* @0x1cea84 vadd.f32 s9, s7, s9 */
/* @0x1cea88 vstr s8, [r5, #16] */
/* @0x1cea8c vstr s11, [r8] */
/* ── 4 角的 min/max 选择（旋转/斜视口 → AABB）────────────────────
 *   每条边用 vcmpe + bpl/bmi 在两两之间选小/选大，选完 vcvt.s32.f32 存回 int 数组；
 *   NaN/相等走 1cfa1c 等兜底块
 */
/* @0x1cea90 vcmpe.f32 s12, s14 —— 4 角 x 的 min/max 比较 */
/* @0x1cea94 vstr s9, [r5, #28] */
/* @0x1cea98 vmrs APSR_nzcv, fpscr */
/* @0x1cea9c bpl 0x1cf9e8 <_Z11HandleOtherv+0x1454> —— s12 >= s14 → 1cf9e8 交换 */
/* @0x1ceaa0 vcmpe.f32 s12, s11 */
/* @0x1ceaa4 vmrs APSR_nzcv, fpscr */
/* @0x1ceaa8 bpl 0x1cfccc <_Z11HandleOtherv+0x1738> */
/* @0x1ceaac vcmpe.f32 s12, s8 */
/* @0x1ceab0 vmrs APSR_nzcv, fpscr */
/* @0x1ceab4 bmi 0x1cfa1c <_Z11HandleOtherv+0x1488> */
/* @0x1ceab8 vcvt.s32.f32 s7, s8 */
/* @0x1ceabc vmov r0, s7 */
/* @0x1ceac0 add r1, sp, #120 */
/* @0x1ceac4 vcmpe.f32 s13, s15 */
/* @0x1ceac8 vmrs APSR_nzcv, fpscr */
/* @0x1ceacc str r0, [r6, r1] —— x1 取整后存 int 数组 [sp+120+4i] */
/* @0x1cead0 bpl 0x1cfcd4 <_Z11HandleOtherv+0x1740> */
/* @0x1cead4 vcmpe.f32 s13, s9 */
/* @0x1cead8 vmrs APSR_nzcv, fpscr */
/* @0x1ceadc bpl 0x1cfe1c <_Z11HandleOtherv+0x1888> */
/* @0x1ceae0 vcmpe.f32 s13, s10 */
/* @0x1ceae4 vmrs APSR_nzcv, fpscr */
/* @0x1ceae8 bmi 0x1cfd08 <_Z11HandleOtherv+0x1774> */
/* @0x1ceaec vcvt.s32.f32 s7, s10 */
/* @0x1ceaf0 vmov r2, s7 */
/* @0x1ceaf4 add r1, sp, #152 */
/* @0x1ceaf8 vcmpe.f32 s12, s14 */
/* @0x1ceafc vmrs APSR_nzcv, fpscr */
/* @0x1ceb00 str r2, [r6, r1] */
/* @0x1ceb04 ble 0x1cfd3c <_Z11HandleOtherv+0x17a8> */
/* @0x1ceb08 vcmpe.f32 s12, s11 */
/* @0x1ceb0c vmrs APSR_nzcv, fpscr */
/* @0x1ceb10 ble 0x1cfe0c <_Z11HandleOtherv+0x1878> */
/* @0x1ceb14 vcmpe.f32 s12, s8 */
/* @0x1ceb18 vmrs APSR_nzcv, fpscr */
/* @0x1ceb1c bgt 0x1cfd70 <_Z11HandleOtherv+0x17dc> */
/* @0x1ceb20 vcvt.s32.f32 s14, s8 —— y2 取整 */
/* @0x1ceb24 vmov r3, s14 */
/* @0x1ceb28 add r1, sp, #184 */
/* @0x1ceb2c vcmpe.f32 s13, s15 */
/* @0x1ceb30 vmrs APSR_nzcv, fpscr */
/* @0x1ceb34 str r3, [r6, r1] —— y2 存 [sp+216+4i] */
/* @0x1ceb38 ble 0x1cfda4 <_Z11HandleOtherv+0x1810> */
/* @0x1ceb3c vcmpe.f32 s13, s9 */
/* @0x1ceb40 vmrs APSR_nzcv, fpscr */
/* @0x1ceb44 ble 0x1cfe14 <_Z11HandleOtherv+0x1880> */
/* @0x1ceb48 vcmpe.f32 s13, s10 */
/* @0x1ceb4c vmrs APSR_nzcv, fpscr */
/* @0x1ceb50 bgt 0x1cfdd8 <_Z11HandleOtherv+0x1844> */
/* @0x1ceb54 vcvt.s32.f32 s13, s10 */
/* @0x1ceb58 vmov r12, s13 */
/* @0x1ceb5c add r1, sp, #216 */
/* @0x1ceb60 add r0, sp, #88 */
/* @0x1ceb64 vldr s15, [r9] */
/* @0x1ceb68 vldr s14, [r5] */
/* @0x1ceb6c vldr s13, [r11] */
/* @0x1ceb70 str r12, [r6, r1] */
/* @0x1ceb74 add r1, r0, r6 —— r1 = sp+88+4i（角度数组） */
/* @0x1ceb78 vstr s18, [r1] —— 角度 = -1.0（矩阵路径不知道角度 → 走 4 边平面判定） */
/* @0x1ceb7c vldr s12, [r10] */
/* @0x1ceb80 vldr s11, [r5, #16] */
/* @0x1ceb84 vldr s10, [r5, #20] */
/* @0x1ceb88 vldr s8, [r8] */
/* @0x1ceb8c b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* ── 无 sprite 退化：先试 mask_index，再退成 (x,y) 点判 ─────────────
 *   Sprite_Exists(mask_index) 为真 → 回 1ce6e8 用 bbox；
 *   都无 → 用 x(+0xB4)/y(+0xB8) 直接和房间宽高比（1ceba0..1cebe8）
 */
/* @0x1ceb90 ldr r0, [r6, #0xac] —— mask_index */
/* @0x1ceb94 bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists(mask_index) */
/* @0x1ceb98 cmp r0, #0 */
/* @0x1ceb9c bne 0x1ce6e8 <_Z11HandleOtherv+0x154> —— 有 mask → 回 1ce6e8 用 bbox */
/* @0x1ceba0 vldr s14, [r6, #180] —— 无 sprite 也无 mask：改用 x（float） */
/* @0x1ceba4 vcmpe.f32 s14, #0 */
/* @0x1ceba8 vmrs APSR_nzcv, fpscr */
/* @0x1cebac bmi 0x1cebec <_Z11HandleOtherv+0x658> —— x < 0 → 在外 */
/* @0x1cebb0 ldr r3, [r10] —— room */
/* @0x1cebb4 vldr s12, [r3, #16] —— 房间宽 */
/* @0x1cebb8 vcvt.f32.s32 s15, s12 —— int → float */
/* @0x1cebbc vcmpe.f32 s14, s15 */
/* @0x1cebc0 vmrs APSR_nzcv, fpscr */
/* @0x1cebc4 bgt 0x1cebec <_Z11HandleOtherv+0x658> —— x > 宽 → 在外 */
/* @0x1cebc8 vldr s15, [r6, #184] —— y */
/* @0x1cebcc vcmpe.f32 s15, #0 */
/* @0x1cebd0 vmrs APSR_nzcv, fpscr */
/* @0x1cebd4 bmi 0x1cebec <_Z11HandleOtherv+0x658> */
/* @0x1cebd8 vldr s14, [r3, #20] —— 房间高 */
/* @0x1cebdc vcvt.f32.s32 s14, s14 */
/* @0x1cebe0 vcmpe.f32 s15, s14 */
/* @0x1cebe4 vmrs APSR_nzcv, fpscr */
/* @0x1cebe8 ble 0x1ce758 <_Z11HandleOtherv+0x1c4> —— 在内 → 1ce758 */
/* ── 派发 Other 0：边沿去重 + Perform_Event(inst, inst, 7, 0) ───────
 *   [inst+0x15E] 已是 1 → 不重发，维持 1；是 0 → r3=0 → Perform_Event(...,7,0)，
 *   返回后置 1（1cec0c），再由 1ce75c 统一 strb 回 [inst+0x15E]
 */
/* @0x1cebec ldrb r3, [r6, #0x15e] —— [inst+0x15E]：上一帧是否已在外面 */
/* @0x1cebf0 cmp r3, #0 */
/* @0x1cebf4 movne r3, #1 —— 已置位 → r3 = 1（不重发） */
/* @0x1cebf8 bne 0x1ce75c <_Z11HandleOtherv+0x1c8> —— → 1ce75c 统一写回 */
/* @0x1cebfc mov r0, r6 —— r0 = inst */
/* @0x1cec00 mov r1, r6 —— r1 = inst */
/* @0x1cec04 mov r2, #7 —— 事件类型 7 */
/* @0x1cec08 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> —— Perform_Event(inst, inst, 7, r3=0 = Outside Room) */
/* @0x1cec0c mov r3, #1 —— r3 = 1（置边沿标志） */
/* @0x1cec10 b 0x1ce75c <_Z11HandleOtherv+0x1c8> —— → 1ce75c 写 [inst+0x15E] */
/* ── literal pool（非指令，objdump/index 的译码是数据）───────────────
 *   1cec14: 0x38D1B717 = 1e-05f      1cec18: 0x3C8EFA35 = 0.0174533f
 *   1cec1c: 0x2236AC（GOT 基址偏移）  1cec20..1cec3C: 7 个 GOT 负偏移
 */
/* @0x1cec14 ldmlo r1, {r0, r1, r2, r4, r8, r9, r10, r12, sp, pc} ^ —— 非指令：1e-05f */
/* @0x1cec18 vstmialo lr, {s30, s31} —— 非指令：0.0174533f */
/* @0x1cec1c eoreq r3, r2, r12, lsr #13 —— 非指令：GOT 基址偏移 0x2236AC */
/* @0x1cec20 .word 0xffffbf18 —— 非指令：-0x40E8（g_bProfile） */
/* @0x1cec24 .word 0xffffdeb4 —— 非指令：-0x214C（0x536F20） */
/* @0x1cec28 .word 0xffffdeb8 —— 非指令：-0x2148（0x536F70） */
/* @0x1cec2c .word 0xffffbcd8 —— 非指令：-0x4328（&Run_Room） */
/* @0x1cec30 .word 0xffffbcd4 —— 非指令：-0x432C（0x5428E8） */
/* @0x1cec34 .word 0xffffc024 —— 非指令：-0x3FDC（0x48F78C） */
/* @0x1cec38 .word 0xffffdebc —— 非指令：-0x2144（0x53AB70） */
/* @0x1cec3c .word 0xffffbfec —— 非指令：-0x4014（&g_ObjectHash） */
/* ── 轴对齐路径：直接读 view 字段算矩形（view+4=x, +8=y, +12=w, +16=h）──
 *   view->[0x24]（+36）是角度：> 1e-05 → 1cfa70 走 sinf/cosf 旋转角点；
 *   否则 lrint(x)、lrint(y)、lrint(x+w)、lrint(y+h) 存 int 数组（4 次 lrint）
 */
/* @0x1cec40 vldr s15, [r1, #36] —— view->[0x24]（+36）= 角度 */
/* @0x1cec44 vcmpe.f32 s15, s17 —— 角度 vs 1e-05 */
/* @0x1cec48 vmrs APSR_nzcv, fpscr */
/* @0x1cec4c bhi 0x1cfa70 <_Z11HandleOtherv+0x14dc> —— 角度 > 1e-05 → 1cfa70 走旋转路径 */
/* @0x1cec50 vldr s15, [r1, #4] —— view->[4] = x */
/* @0x1cec54 vcvt.f64.f32 d6, s15 */
/* @0x1cec58 str r12, [sp] */
/* @0x1cec5c vmov r0, r1, d6 */
/* @0x1cec60 bl 0xb66e8 <lrint@plt> —— lrint(x) */
/* @0x1cec64 ldr r12, [sp] */
/* @0x1cec68 vmov s22, r0 */
/* @0x1cec6c ldr r0, [sp, #0x3c] */
/* @0x1cec70 vmov r2, s22 */
/* @0x1cec74 ldr r1, [r0] */
/* @0x1cec78 add r0, sp, #120 */
/* @0x1cec7c ldr r1, [r1, r12, lsl #2] —— view->[8] = y */
/* @0x1cec80 vldr s15, [r1, #8] */
/* @0x1cec84 vcvt.f64.f32 d6, s15 */
/* @0x1cec88 str r2, [r6, r0] —— y 存 [sp+152+4i] */
/* @0x1cec8c vmov r0, r1, d6 */
/* @0x1cec90 bl 0xb66e8 <lrint@plt> —— lrint(y) */
/* @0x1cec94 ldr r12, [sp] */
/* @0x1cec98 add lr, sp, #152 */
/* @0x1cec9c vmov s21, r0 */
/* @0x1ceca0 ldr r0, [sp, #0x3c] */
/* @0x1ceca4 vmov r2, s21 */
/* @0x1ceca8 ldr r1, [r0] —— view */
/* @0x1cecac ldr r1, [r1, r12, lsl #2] */
/* @0x1cecb0 vldr s14, [r1, #4] —— x + w（view->[0xC]） */
/* @0x1cecb4 vldr s15, [r1, #12] */
/* @0x1cecb8 vadd.f32 s15, s14, s15 */
/* @0x1cecbc vcvt.f64.f32 d6, s15 */
/* @0x1cecc0 str r2, [r6, lr] —— x2 存 [sp+184+4i] */
/* @0x1cecc4 vmov r0, r1, d6 */
/* @0x1cecc8 bl 0xb66e8 <lrint@plt> —— lrint(x+w) */
/* @0x1ceccc ldr r12, [sp] */
/* @0x1cecd0 add lr, sp, #184 */
/* @0x1cecd4 vmov s20, r0 */
/* @0x1cecd8 ldr r0, [sp, #0x3c] */
/* @0x1cecdc vmov r2, s20 */
/* @0x1cece0 ldr r1, [r0] */
/* @0x1cece4 ldr r1, [r1, r12, lsl #2] */
/* @0x1cece8 vldr s14, [r1, #8] —— y + h（view->[0x10]） */
/* @0x1cecec vldr s15, [r1, #16] */
/* @0x1cecf0 vadd.f32 s15, s14, s15 */
/* @0x1cecf4 vcvt.f64.f32 d6, s15 */
/* @0x1cecf8 str r2, [r6, lr] —— y2 存 [sp+216+4i] */
/* @0x1cecfc vmov r0, r1, d6 */
/* @0x1ced00 bl 0xb66e8 <lrint@plt> —— lrint(y+h) */
/* @0x1ced04 add r1, sp, #216 */
/* ── 把矩形同时写成 float 角点（4 角 8 个 float）────────────────── */
/* @0x1ced08 vcvt.f32.s32 s22, s22 */
/* @0x1ced0c vcvt.f32.s32 s21, s21 */
/* @0x1ced10 vstr s22, [r5] —— 4 角的 float 副本（x,y,x2,y2 → 8 float） */
/* @0x1ced14 vcvt.f32.s32 s20, s20 */
/* @0x1ced18 vstr s21, [r10] */
/* @0x1ced1c vstr s20, [r9] */
/* @0x1ced20 vstr s21, [r11] */
/* @0x1ced24 vstr s20, [r5, #16] */
/* @0x1ced28 vmov s13, r0 */
/* @0x1ced2c str r0, [r6, r1] */
/* @0x1ced30 vcvt.f32.s32 s9, s13 */
/* @0x1ced34 vstr s9, [r5, #20] */
/* @0x1ced38 vstr s22, [r8] */
/* @0x1ced3c vstr s9, [r5, #28] */
/* @0x1ced40 vldr s14, [r5] */
/* @0x1ced44 vldr s15, [r9] */
/* @0x1ced48 vldr s13, [r11] */
/* @0x1ced4c vldr s12, [r10] */
/* @0x1ced50 vldr s11, [r5, #16] */
/* @0x1ced54 vldr s10, [r5, #20] */
/* @0x1ced58 vldr s8, [r8] */
/* ── 4 条边向量：(p1-p0),(p2-p1),(p3-p2),(p0-p3) 写 32 B 记录 ────── */
/* @0x1ced5c vsub.f32 s7, s15, s14 —— 边向量 = p[i+1]-p[i] */
/* @0x1ced60 vsub.f32 s15, s11, s15 */
/* @0x1ced64 vstr s7, [r4] */
/* @0x1ced68 vsub.f32 s11, s8, s11 */
/* @0x1ced6c vstr s15, [r4, #8] */
/* @0x1ced70 vsub.f32 s14, s14, s8 */
/* @0x1ced74 vstr s11, [r4, #16] */
/* @0x1ced78 vsub.f32 s15, s13, s12 */
/* @0x1ced7c vstr s14, [r4, #24] */
/* @0x1ced80 vsub.f32 s13, s10, s13 */
/* @0x1ced84 vstr s15, [r4, #4] */
/* @0x1ced88 vsub.f32 s10, s9, s10 */
/* @0x1ced8c vstr s13, [r4, #12] */
/* @0x1ced90 vsub.f32 s12, s12, s9 */
/* @0x1ced94 vstr s10, [r4, #20] */
/* @0x1ced98 vstr s12, [r4, #28] */
/* ── 下一个视图：r7 += 1（视图号）、r6 += 4（int 数组下标）、r10 += 32 ──
 *   其余指针（r4/r5/r8/r9/r11）各 += 32；r7==8 退出视口段
 */
/* @0x1ced9c add r7, r7, #1 —— 视图号 +1 */
/* @0x1ceda0 add r4, r4, #32 */
/* @0x1ceda4 cmp r7, #8 */
/* @0x1ceda8 add r6, r6, #4 —— int 数组下标 +4 */
/* @0x1cedac add r9, r9, #32 */
/* @0x1cedb0 add r5, r5, #32 */
/* @0x1cedb4 add r11, r11, #32 */
/* @0x1cedb8 add r10, r10, #32 */
/* @0x1cedbc add r8, r8, #32 */
/* @0x1cedc0 bne 0x1ce98c <_Z11HandleOtherv+0x3f8> —— 还有视图 → 1ce98c */
/* ── 第 3 趟快照（Outside View）+ pass3 初始化 ────────────────────
 *   计数器第 3 次自增，旧值 → [sp+16]；i 存 [sp+0x20]（步长 1，字节偏移另存 [sp+0x2c]）
 */
/* @0x1cedc4 ldr r1, [sp, #0x44] —— [sp+0x44] = &计数器 */
/* @0x1cedc8 add r12, sp, #572 */
/* @0x1cedcc str r12, [sp, #0x38] */
/* @0x1cedd0 add r12, sp, #256 */
/* @0x1cedd4 str r12, [sp, #0x18] */
/* @0x1cedd8 add r12, sp, #572 */
/* @0x1ceddc ldrd r0, r1, [r1] —— ldrd 当前值 */
/* @0x1cede0 add r6, sp, #288 —— [sp+16] = 快照③ */
/* @0x1cede4 str r12, [sp, #0x24] */
/* @0x1cede8 add r12, sp, #88 */
/* @0x1cedec str r12, [sp, #0x30] */
/* @0x1cedf0 adds r2, r0, #1 */
/* @0x1cedf4 ldr r12, [sp, #0x44] */
/* @0x1cedf8 mov r7, #0 */
/* @0x1cedfc adc r3, r1, #0 */
/* @0x1cee00 strd r0, r1, [sp, #16] */
/* @0x1cee04 str r7, [sp, #0x20] */
/* @0x1cee08 strd r2, r3, [r12] —— 第 3 次自增 */
/* @0x1cee0c add r12, sp, #316 */
/* @0x1cee10 str r12, [sp, #0x28] */
/* ── ③ Outside View i：逐视图的候选表遍历 ─────────────────────────
 *   事件号 r8 = i + 40；候选 id 表 = *(int**)(0x53AB70 + 0x3944 + 8i)；
 *   长度 = [0x536F70 + 0x1CA0 + 4i]（<=0 跳本视图）
 *   谓词：bbox 与视图 AABB 四向都不相交才算「完全在外」→ 1cf080 派发
 */
/* @0x1cee14 ldr r12, [sp, #0x3c] —— 第 3 趟：room */
/* @0x1cee18 ldr r3, [r12] */
/* @0x1cee1c ldrb r2, [r3, #0x44] —— view_enabled */
/* @0x1cee20 cmp r2, #0 */
/* @0x1cee24 beq 0x1cf0bc <_Z11HandleOtherv+0xb28> —— 未启用 → 1cf0bc */
/* @0x1cee28 ldr r12, [sp, #0x20] */
/* @0x1cee2c add r2, r12, #18 */
/* @0x1cee30 ldr r3, [r3, r2, lsl #2] —— view[i] */
/* @0x1cee34 ldrb r3, [r3] —— view->[0] 可见 */
/* @0x1cee38 cmp r3, #0 */
/* @0x1cee3c beq 0x1cf0bc <_Z11HandleOtherv+0xb28> —— 不可见 → 1cf0bc */
/* @0x1cee40 ldr r12, [sp, #0x48] */
/* @0x1cee44 add r3, r12, r7 —— r3 = 0x536F70 + 4i + 0x1C80 */
/* @0x1cee48 ldr r12, [sp, #0x20] */
/* @0x1cee4c add r3, r3, #7296 */
/* @0x1cee50 add r8, r12, #40 —— 事件号 r8 = i + 40（Outside View i） */
/* @0x1cee54 add r12, r3, #32 */
/* @0x1cee58 ldr r0, [r3, #0x20] —— count = [0x536F70+0x1CA0+4i] */
/* @0x1cee5c str r12, [sp, #0x2c] */
/* @0x1cee60 cmp r0, #0 */
/* @0x1cee64 ble 0x1cf0bc <_Z11HandleOtherv+0xb28> —— count <= 0 → 下一个视图 */
/* @0x1cee68 ldr r12, [sp, #0x40] */
/* @0x1cee6c mov r5, #0 */
/* @0x1cee70 ldr r2, [pc, #-0x240] */
/* @0x1cee74 ldr r3, [pc, #-0x240] */
/* @0x1cee78 ldr r10, [r12, r2] —— r10 = 0x53AB70 */
/* @0x1cee7c ldr r11, [r12, r3] */
/* @0x1cee80 ldr r12, [sp, #0x20] */
/* @0x1cee84 add r10, r10, r12, lsl #3 —— r10 += 8i */
/* @0x1cee88 add r10, r10, #14656 —— +0x3940 */
/* @0x1cee8c add r10, r10, #4 —— +4 → 0x53AB70+0x3944+8i = 事件 40+i 的 id 表 */
/* @0x1cee90 ldr r3, [r11] */
/* @0x1cee94 ldr r1, [r10] —— ids 指针 */
/* @0x1cee98 ldr r2, [r3, #0x4] */
/* @0x1cee9c ldr r1, [r1, r5, lsl #2] */
/* @0x1ceea0 ldr r3, [r3] */
/* @0x1ceea4 and r2, r1, r2 */
/* @0x1ceea8 ldr r3, [r3, r2, lsl #3] */
/* @0x1ceeac cmp r3, #0 */
/* @0x1ceeb0 bne 0x1ceec4 <_Z11HandleOtherv+0x930> */
/* @0x1ceeb4 b 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceeb8 ldr r3, [r3, #0x4] */
/* @0x1ceebc cmp r3, #0 */
/* @0x1ceec0 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceec4 ldr r2, [r3, #0x8] */
/* @0x1ceec8 cmp r1, r2 */
/* @0x1ceecc bne 0x1ceeb8 <_Z11HandleOtherv+0x924> */
/* @0x1ceed0 ldr r3, [r3, #0xc] */
/* @0x1ceed4 cmp r3, #0 */
/* @0x1ceed8 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceedc ldr r4, [r3, #0xc4] */
/* @0x1ceee0 cmp r4, #0 */
/* @0x1ceee4 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceee8 ldr r3, [r4, #0x8] */
/* @0x1ceeec cmp r3, #0 */
/* @0x1ceef0 beq 0x1cf0b0 <_Z11HandleOtherv+0xb1c> */
/* @0x1ceef4 ldr r9, [r4, #0x8] */
/* @0x1ceef8 ldr r4, [r4] */
/* @0x1ceefc ldrb r3, [r9, #0x68] */
/* @0x1cef00 cmp r3, #0 */
/* @0x1cef04 bne 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef08 ldrb r3, [r9, #0x69] */
/* @0x1cef0c cmp r3, #0 */
/* @0x1cef10 bne 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef14 ldrd r2, r3, [r9, #112] */
/* @0x1cef18 ldrd r0, r1, [sp, #16] */
/* @0x1cef1c cmp r0, r2 */
/* @0x1cef20 sbcs r1, r1, r3 */
/* @0x1cef24 blt 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cef28 ldr r0, [r9, #0x8c] */
/* @0x1cef2c bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists */
/* @0x1cef30 cmp r0, #0 */
/* @0x1cef34 beq 0x1cf41c <_Z11HandleOtherv+0xe88> —— 无 sprite → 1cf41c 试 mask */
/* @0x1cef38 ldrb r3, [r9, #0x64] */
/* @0x1cef3c cmp r3, #0 */
/* @0x1cef40 bne 0x1cf534 <_Z11HandleOtherv+0xfa0> —— bbox 脏 → 1cf534 重算后回 1cef44 */
/* @0x1cef44 add r3, sp, #120 —— 框右 vs 视图 x1 */
/* @0x1cef48 ldr r2, [r9, #0xf0] */
/* @0x1cef4c ldr r3, [r7, r3] */
/* @0x1cef50 cmp r2, r3 */
/* @0x1cef54 blt 0x1cf080 <_Z11HandleOtherv+0xaec> —— 右 < x1 → 1cf080（完全在外 → 派发） */
/* @0x1cef58 ldrb r3, [r9, #0x64] */
/* @0x1cef5c cmp r3, #0 */
/* @0x1cef60 bne 0x1cf698 <_Z11HandleOtherv+0x1104> —— bbox 脏（第二段） */
/* @0x1cef64 add r3, sp, #184 */
/* @0x1cef68 ldr r2, [r9, #0xe8] —— 框左 vs x2 */
/* @0x1cef6c ldr r3, [r7, r3] */
/* @0x1cef70 cmp r2, r3 */
/* @0x1cef74 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> —— 左 > x2 → 派发 */
/* @0x1cef78 ldrb r3, [r9, #0x64] */
/* @0x1cef7c cmp r3, #0 */
/* @0x1cef80 bne 0x1cf958 <_Z11HandleOtherv+0x13c4> —— bbox 脏（第三段） */
/* @0x1cef84 add r3, sp, #152 */
/* @0x1cef88 ldr r2, [r9, #0xf4] —— 框下 vs y1 */
/* @0x1cef8c ldr r3, [r7, r3] */
/* @0x1cef90 cmp r2, r3 */
/* @0x1cef94 blt 0x1cf080 <_Z11HandleOtherv+0xaec> —— 下 < y1 → 派发 */
/* @0x1cef98 ldrb r3, [r9, #0x64] */
/* @0x1cef9c cmp r3, #0 —— bbox 脏（第四段） */
/* @0x1cefa0 bne 0x1cf9d8 <_Z11HandleOtherv+0x1444> */
/* @0x1cefa4 vldr s13, [r9, #236] —— 框上 vs y2 */
/* @0x1cefa8 vmov r2, s13 */
/* @0x1cefac add r3, sp, #216 */
/* @0x1cefb0 ldr r3, [r7, r3] */
/* @0x1cefb4 cmp r2, r3 */
/* @0x1cefb8 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> —— 上 > y2 → 派发 */
/* @0x1cefbc ldr r12, [sp, #0x30] —— 角度数组 */
/* @0x1cefc0 vldr s15, [r12] */
/* @0x1cefc4 vcmp.f32 s15, #0 */
/* @0x1cefc8 vmrs APSR_nzcv, fpscr */
/* @0x1cefcc beq 0x1cf094 <_Z11HandleOtherv+0xb00> —— 角度 == 0 → 1cf094（AABB 已精确，无需 4 边判定） */
/* @0x1cefd0 ldrb r3, [r9, #0x64] */
/* @0x1cefd4 cmp r3, #0 */
/* @0x1cefd8 bne 0x1cf708 <_Z11HandleOtherv+0x1174> */
/* @0x1cefdc vldr s14, [r9, #232] */
/* @0x1cefe0 vcvt.f32.s32 s16, s14 */
/* @0x1cefe4 vstr s16, [sp, #248] */
/* @0x1cefe8 vcvt.f32.s32 s17, s13 */
/* @0x1cefec vstr s17, [sp, #252] */
/* @0x1ceff0 vldr s15, [r9, #240] */
/* @0x1ceff4 vcvt.f32.s32 s12, s15 */
/* @0x1ceff8 vstr s12, [sp, #256] */
/* @0x1ceffc vcvt.f32.s32 s13, s13 */
/* @0x1cf000 vstr s13, [sp, #260] */
/* @0x1cf004 vcvt.f32.s32 s15, s15 */
/* @0x1cf008 vstr s15, [sp, #264] */
/* @0x1cf00c vldr s15, [r9, #244] */
/* @0x1cf010 vcvt.f32.s32 s13, s15 */
/* @0x1cf014 vstr s13, [sp, #268] */
/* @0x1cf018 vcvt.f32.s32 s14, s14 */
/* @0x1cf01c vstr s14, [sp, #272] */
/* @0x1cf020 vcvt.f32.s32 s15, s15 */
/* @0x1cf024 ldr r1, [sp, #0x24] */
/* @0x1cf028 ldr r2, [sp, #0x28] */
/* @0x1cf02c mov r0, #4 */
/* @0x1cf030 vstr s15, [sp, #276] */
/* @0x1cf034 vmov.f32 s14, s17 */
/* @0x1cf038 add r3, sp, #256 */
/* @0x1cf03c vldr s10, [r2, #-4] */
/* @0x1cf040 vldr s11, [r2] */
/* @0x1cf044 vldr s12, [r1, #-4] */
/* @0x1cf048 vldr s13, [r1] */
/* @0x1cf04c vmov.f32 s15, s16 */
/* @0x1cf050 add r3, r3, #8 */
/* @0x1cf054 vsub.f32 s15, s15, s10 */
/* @0x1cf058 vmul.f32 s15, s15, s13 */
/* @0x1cf05c vsub.f32 s14, s14, s11 */
/* @0x1cf060 vnmls.f32 s15, s14, s12 */
/* @0x1cf064 vcmpe.f32 s15, #0 */
/* @0x1cf068 vmrs APSR_nzcv, fpscr */
/* @0x1cf06c bmi 0x1cf674 <_Z11HandleOtherv+0x10e0> */
/* @0x1cf070 cmp r3, r6 */
/* @0x1cf074 vldrne s15, [r3, #-8] */
/* @0x1cf078 vldrne s14, [r3, #-4] */
/* @0x1cf07c bne 0x1cf050 <_Z11HandleOtherv+0xabc> */
/* ── 派发 Other 40+i：Perform_Event(inst, inst, 7, r8) ────────────── */
/* @0x1cf080 mov r0, r9 —— r0 = inst */
/* @0x1cf084 mov r2, #7 —— 事件类型 7 */
/* @0x1cf088 mov r1, r9 —— r1 = inst */
/* @0x1cf08c mov r3, r8 —— 事件号 = r8 = 40+i */
/* @0x1cf090 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> —— Perform_Event(inst, inst, 7, 40+i) */
/* @0x1cf094 cmp r4, #0 */
/* @0x1cf098 beq 0x1cf0a8 <_Z11HandleOtherv+0xb14> */
/* @0x1cf09c ldr r3, [r4, #0x8] */
/* @0x1cf0a0 cmp r3, #0 */
/* @0x1cf0a4 bne 0x1ceef4 <_Z11HandleOtherv+0x960> */
/* @0x1cf0a8 ldr r12, [sp, #0x2c] —— 计数指针 */
/* @0x1cf0ac ldr r0, [r12] */
/* @0x1cf0b0 add r5, r5, #1 —— 下一个 id */
/* @0x1cf0b4 cmp r0, r5 */
/* @0x1cf0b8 bgt 0x1cee90 <_Z11HandleOtherv+0x8fc> */
/* ── 下一个视图（i++；[sp+0x28]/[0x24]/[0x30] 各 +32/+4）─────────── */
/* @0x1cf0bc ldr r12, [sp, #0x20] */
/* @0x1cf0c0 add r7, r7, #4 —— i++ */
/* @0x1cf0c4 add r12, r12, #1 */
/* @0x1cf0c8 str r12, [sp, #0x20] */
/* @0x1cf0cc cmp r12, #8 */
/* @0x1cf0d0 ldr r12, [sp, #0x28] */
/* @0x1cf0d4 add r12, r12, #32 */
/* @0x1cf0d8 str r12, [sp, #0x28] */
/* @0x1cf0dc ldr r12, [sp, #0x24] */
/* @0x1cf0e0 add r12, r12, #32 */
/* @0x1cf0e4 str r12, [sp, #0x24] */
/* @0x1cf0e8 ldr r12, [sp, #0x30] */
/* @0x1cf0ec add r12, r12, #4 */
/* @0x1cf0f0 str r12, [sp, #0x30] */
/* @0x1cf0f4 bne 0x1cee14 <_Z11HandleOtherv+0x880> —— i < 8 → 1cee14 */
/* ── 第 4 趟快照（Intersect Boundary View）+ pass4 初始化 ───────────
 *   计数器第 4 次自增，旧值 → [sp+24]；[sp+0x2c] 重新从 0 起
 */
/* @0x1cf0f8 ldr r1, [sp, #0x44] —— [sp+0x44] = &计数器 */
/* @0x1cf0fc add r12, sp, #256 */
/* @0x1cf100 str r12, [sp, #0x28] */
/* @0x1cf104 add r12, sp, #572 */
/* @0x1cf108 str r12, [sp, #0x38] */
/* @0x1cf10c add r12, sp, #316 —— ldrd 当前值 */
/* @0x1cf110 ldrd r0, r1, [r1] */
/* @0x1cf114 mov r8, #0 —— r8 = 0 */
/* @0x1cf118 str r12, [sp, #0x34] */
/* @0x1cf11c add r11, sp, #288 */
/* @0x1cf120 ldr r12, [sp, #0x44] */
/* @0x1cf124 adds r2, r0, #1 */
/* @0x1cf128 mov r10, r8 */
/* @0x1cf12c adc r3, r1, #0 */
/* @0x1cf130 strd r0, r1, [sp, #24] —— 快照④ → [sp+24] */
/* @0x1cf134 strd r2, r3, [r12] —— 第 4 次自增 */
/* @0x1cf138 str r8, [sp, #0x2c] */
/* ── ④ Intersect Boundary View i ────────────────────────────────
 *   事件号 = i + 50，存 [sp+0x44]；候选 id 表 = *(int**)(0x53AB70 + 0x3994 + 8i)；
 *   长度 = [0x536F70 + 0x1CC8 + 32i]
 *   先四向「完全不相交就跳过」，再判「跨边」（1cf348..1cf398）；
 *   [sp+88+4i]（角度）非 0 → 1cf544 用 4 条边平面做精确判定
 */
/* @0x1cf13c ldr r12, [sp, #0x3c] —— 第 4 趟：room */
/* @0x1cf140 ldr r3, [r12] */
/* @0x1cf144 ldrb r2, [r3, #0x44] —— view_enabled */
/* @0x1cf148 cmp r2, #0 */
/* @0x1cf14c beq 0x1cf3d0 <_Z11HandleOtherv+0xe3c> —— 未启用 → 1cf3d0 */
/* @0x1cf150 ldr r12, [sp, #0x2c] */
/* @0x1cf154 add r2, r12, #18 */
/* @0x1cf158 ldr r3, [r3, r2, lsl #2] —— view[i] */
/* @0x1cf15c ldrb r7, [r3] —— view->[0] 可见 */
/* @0x1cf160 cmp r7, #0 */
/* @0x1cf164 beq 0x1cf3d0 <_Z11HandleOtherv+0xe3c> —— 不可见 → 1cf3d0 */
/* @0x1cf168 ldr r12, [sp, #0x48] */
/* @0x1cf16c add r3, r12, r10 */
/* @0x1cf170 ldr r12, [sp, #0x2c] */
/* @0x1cf174 add r3, r3, #7360 —— r3 = 0x536F70 + 32i + 0x1CC0 */
/* @0x1cf178 add r12, r12, #50 —— 事件号 = i + 50（Intersect Boundary View i） */
/* @0x1cf17c str r12, [sp, #0x44] —— [sp+0x44] = 事件号 */
/* @0x1cf180 ldr r0, [r3, #0x8] —— count = [0x536F70+0x1CC8+32i] */
/* @0x1cf184 add r12, r3, #8 */
/* @0x1cf188 str r12, [sp, #0x30] */
/* @0x1cf18c cmp r0, #0 */
/* @0x1cf190 ble 0x1cf3d0 <_Z11HandleOtherv+0xe3c> —— count <= 0 → 下一视图 */
/* @0x1cf194 add r12, sp, #88 */
/* @0x1cf198 ldr r3, [pc, #-0x568] —— -0x2144 → 0x53AB70 */
/* @0x1cf19c add r12, r12, r10 */
/* @0x1cf1a0 ldr r2, [pc, #-0x56c] —— -0x4014 → &g_ObjectHash */
/* @0x1cf1a4 str r12, [sp, #0x50] */
/* @0x1cf1a8 mov r6, #0 */
/* @0x1cf1ac ldr r12, [sp, #0x40] */
/* @0x1cf1b0 ldr r3, [r12, r3] */
/* @0x1cf1b4 ldr r2, [r12, r2] */
/* @0x1cf1b8 ldr r12, [sp, #0x2c] */
/* @0x1cf1bc str r10, [sp, #0x8] */
/* @0x1cf1c0 str r2, [sp, #0x24] */
/* @0x1cf1c4 add r3, r3, r12, lsl #3 —— +8i */
/* @0x1cf1c8 add r3, r3, #14720 —— +0x3980 */
/* @0x1cf1cc add r3, r3, #20 —— +0x14 → 0x53AB70+0x3994+8i = 事件 50+i 的 id 表 */
/* @0x1cf1d0 str r3, [sp, #0x20] */
/* @0x1cf1d4 ldr r12, [sp, #0x24] */
/* @0x1cf1d8 ldr r3, [r12] */
/* @0x1cf1dc ldr r12, [sp, #0x20] */
/* @0x1cf1e0 ldr r2, [r3, #0x4] */
/* @0x1cf1e4 ldr r1, [r12] */
/* @0x1cf1e8 ldr r3, [r3] */
/* @0x1cf1ec ldr r1, [r1, r6, lsl #2] */
/* @0x1cf1f0 and r2, r1, r2 */
/* @0x1cf1f4 ldr r3, [r3, r2, lsl #3] */
/* @0x1cf1f8 cmp r3, #0 */
/* @0x1cf1fc bne 0x1cf210 <_Z11HandleOtherv+0xc7c> */
/* @0x1cf200 b 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf204 ldr r3, [r3, #0x4] */
/* @0x1cf208 cmp r3, #0 */
/* @0x1cf20c beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf210 ldr r2, [r3, #0x8] */
/* @0x1cf214 cmp r1, r2 */
/* @0x1cf218 bne 0x1cf204 <_Z11HandleOtherv+0xc70> */
/* @0x1cf21c ldr r3, [r3, #0xc] */
/* @0x1cf220 cmp r3, #0 */
/* @0x1cf224 beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf228 ldr r4, [r3, #0xc4] */
/* @0x1cf22c cmp r4, #0 */
/* @0x1cf230 beq 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf234 ldr r3, [r4, #0x8] */
/* @0x1cf238 cmp r3, #0 */
/* @0x1cf23c bne 0x1cf250 <_Z11HandleOtherv+0xcbc> */
/* @0x1cf240 b 0x1cf3c0 <_Z11HandleOtherv+0xe2c> */
/* @0x1cf244 ldr r3, [r4, #0x8] */
/* @0x1cf248 cmp r3, #0 */
/* @0x1cf24c beq 0x1cf3b8 <_Z11HandleOtherv+0xe24> */
/* @0x1cf250 ldr r5, [r4, #0x8] */
/* @0x1cf254 ldr r4, [r4] */
/* @0x1cf258 ldrb r3, [r5, #0x68] */
/* @0x1cf25c cmp r3, #0 */
/* @0x1cf260 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf264 ldrb r3, [r5, #0x69] */
/* @0x1cf268 cmp r3, #0 */
/* @0x1cf26c bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf270 ldrd r2, r3, [r5, #112] */
/* @0x1cf274 ldrd r0, r1, [sp, #24] */
/* @0x1cf278 cmp r0, r2 */
/* @0x1cf27c sbcs r1, r1, r3 */
/* @0x1cf280 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf284 ldr r0, [r5, #0x8c] */
/* @0x1cf288 bl 0x1eee98 <_Z13Sprite_Existsi> —— Sprite_Exists */
/* @0x1cf28c cmp r0, #0 */
/* @0x1cf290 beq 0x1cf508 <_Z11HandleOtherv+0xf74> —— 无 sprite → 1cf508 试 mask */
/* @0x1cf294 ldrb r3, [r5, #0x64] */
/* @0x1cf298 cmp r3, #0 */
/* @0x1cf29c bne 0x1cf524 <_Z11HandleOtherv+0xf90> —— bbox 脏 → 1cf524 重算后回 1cf2a0 */
/* @0x1cf2a0 ldr r12, [sp, #0x8] —— x1（视图左） */
/* @0x1cf2a4 add r2, sp, #120 */
/* @0x1cf2a8 ldr r3, [r5, #0xf0] */
/* @0x1cf2ac ldr r8, [r12, r2] —— 框右 +0xF0 */
/* @0x1cf2b0 cmp r3, r8 */
/* @0x1cf2b4 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> —— 右 < x1 → 不相交，跳过 */
/* @0x1cf2b8 ldrb r3, [r5, #0x64] */
/* @0x1cf2bc cmp r3, #0 */
/* @0x1cf2c0 bne 0x1cf688 <_Z11HandleOtherv+0x10f4> —— bbox 脏（第二段） */
/* @0x1cf2c4 ldr r12, [sp, #0x8] —— x2（视图右） */
/* @0x1cf2c8 add r2, sp, #184 */
/* @0x1cf2cc ldr r3, [r5, #0xe8] */
/* @0x1cf2d0 ldr r9, [r12, r2] —— 框左 +0xE8 */
/* @0x1cf2d4 cmp r3, r9 */
/* @0x1cf2d8 bgt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> —— 左 > x2 → 跳过 */
/* @0x1cf2dc ldrb r3, [r5, #0x64] */
/* @0x1cf2e0 cmp r3, #0 */
/* @0x1cf2e4 bne 0x1cf968 <_Z11HandleOtherv+0x13d4> —— bbox 脏（第三段） */
/* @0x1cf2e8 ldr r12, [sp, #0x8] —— y1（视图上） */
/* @0x1cf2ec add r2, sp, #152 */
/* @0x1cf2f0 ldr r3, [r5, #0xf4] —— 框下 +0xF4 */
/* @0x1cf2f4 ldr r10, [r12, r2] */
/* @0x1cf2f8 cmp r3, r10 */
/* @0x1cf2fc blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> —— 下 < y1 → 跳过 */
/* @0x1cf300 ldrb r3, [r5, #0x64] */
/* @0x1cf304 cmp r3, #0 */
/* @0x1cf308 bne 0x1cf9b0 <_Z11HandleOtherv+0x141c> —— bbox 脏（第四段） */
/* @0x1cf30c vldr s15, [r5, #236] —— 框上 +0xEC */
/* @0x1cf310 vmov r0, s15 */
/* @0x1cf314 ldr r12, [sp, #0x8] */
/* @0x1cf318 add r3, sp, #216 */
/* @0x1cf31c ldr r3, [r12, r3] */
/* @0x1cf320 cmp r0, r3 —— 上 > y2 → 跳过 */
/* @0x1cf324 bgt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf328 ldr r12, [sp, #0x50] */
/* @0x1cf32c vldr s14, [r12] —— 角度数组 [sp+88+4i] */
/* @0x1cf330 vcmp.f32 s14, #0 */
/* @0x1cf334 vmrs APSR_nzcv, fpscr */
/* @0x1cf338 bne 0x1cf544 <_Z11HandleOtherv+0xfb0> —— 角度 != 0 → 1cf544 走 4 边平面判定 */
/* @0x1cf33c ldrb r2, [r5, #0x64] */
/* @0x1cf340 cmp r2, #0 */
/* @0x1cf344 bne 0x1cf978 <_Z11HandleOtherv+0x13e4> */
/* @0x1cf348 ldr r2, [r5, #0xf0] —— 框右 vs x2 */
/* @0x1cf34c cmp r9, r2 */
/* @0x1cf350 ble 0x1cf39c <_Z11HandleOtherv+0xe08> —— x2 <= 右 → 跨右边 → 派发 */
/* @0x1cf354 ldrb r2, [r5, #0x64] */
/* @0x1cf358 cmp r2, #0 */
/* @0x1cf35c bne 0x1cf9c0 <_Z11HandleOtherv+0x142c> */
/* @0x1cf360 ldr r2, [r5, #0xe8] —— 框左 vs x1 */
/* @0x1cf364 cmp r8, r2 */
/* @0x1cf368 bge 0x1cf39c <_Z11HandleOtherv+0xe08> —— x1 >= 左 → 跨左边 → 派发 */
/* @0x1cf36c ldrb r2, [r5, #0x64] */
/* @0x1cf370 cmp r2, #0 */
/* @0x1cf374 bne 0x1cfcb4 <_Z11HandleOtherv+0x1720> */
/* @0x1cf378 ldr r2, [r5, #0xf4] —— 框下 vs y2 */
/* @0x1cf37c cmp r3, r2 */
/* @0x1cf380 ble 0x1cf39c <_Z11HandleOtherv+0xe08> —— y2 <= 下 → 跨下边 → 派发 */
/* @0x1cf384 ldrb r3, [r5, #0x64] */
/* @0x1cf388 cmp r3, #0 */
/* @0x1cf38c bne 0x1cffe0 <_Z11HandleOtherv+0x1a4c> */
/* @0x1cf390 ldr r3, [r5, #0xec] —— 框上 vs y1 */
/* @0x1cf394 cmp r10, r3 */
/* @0x1cf398 blt 0x1cf3b0 <_Z11HandleOtherv+0xe1c> —— y1 < 上 → 未跨上边 → 跳过 */
/* ── 派发 Other 50+i：Perform_Event(inst, inst, 7, [sp+0x44]) ─────── */
/* @0x1cf39c mov r0, r5 —— r0 = inst */
/* @0x1cf3a0 mov r2, #7 —— 事件类型 7 */
/* @0x1cf3a4 mov r1, r5 —— r1 = inst */
/* @0x1cf3a8 ldr r3, [sp, #0x44] —— 事件号 = [sp+0x44] = 50+i */
/* @0x1cf3ac bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> —— Perform_Event(inst, inst, 7, 50+i) */
/* @0x1cf3b0 cmp r4, #0 */
/* @0x1cf3b4 bne 0x1cf244 <_Z11HandleOtherv+0xcb0> */
/* @0x1cf3b8 ldr r12, [sp, #0x30] */
/* @0x1cf3bc ldr r0, [r12] */
/* @0x1cf3c0 add r6, r6, #1 —— 下一个 id */
/* @0x1cf3c4 cmp r0, r6 */
/* @0x1cf3c8 bgt 0x1cf1d4 <_Z11HandleOtherv+0xc40> */
/* @0x1cf3cc ldr r10, [sp, #0x8] —— i++ */
/* @0x1cf3d0 ldr r12, [sp, #0x2c] */
/* @0x1cf3d4 add r10, r10, #4 */
/* @0x1cf3d8 add r12, r12, #1 */
/* @0x1cf3dc str r12, [sp, #0x2c] */
/* @0x1cf3e0 cmp r12, #8 */
/* @0x1cf3e4 ldr r12, [sp, #0x34] */
/* @0x1cf3e8 add r12, r12, #32 */
/* @0x1cf3ec str r12, [sp, #0x34] */
/* @0x1cf3f0 ldr r12, [sp, #0x38] */
/* @0x1cf3f4 add r12, r12, #32 */
/* @0x1cf3f8 str r12, [sp, #0x38] */
/* @0x1cf3fc bne 0x1cf13c <_Z11HandleOtherv+0xba8> —— i < 8 → 1cf13c */
/* ── 出口：g_bProfile 非 0 → 1cfff0 尾调 CProfiler::Pop；否则裸返回 ── */
/* @0x1cf400 ldr r12, [sp, #0x54] —— g_bProfile */
/* @0x1cf404 ldrb r3, [r12] */
/* @0x1cf408 cmp r3, #0 */
/* @0x1cf40c bne 0x1cfff0 <_Z11HandleOtherv+0x1a5c> —— 非 0 → 1cfff0（Pop） */
/* @0x1cf410 add sp, sp, #828 */
/* @0x1cf414 vpop {d8, d9, d10, d11} */
/* @0x1cf418 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} —— 裸返回 */
/* ── 兜底块群：sprite 缺失/bbox 脏/角度分支的续块 ────────────────────
 *   1cf41c/1cf508 是 pass3/pass4 的「sprite 不存在 → 试 mask_index」；
 *   1cf534/1cf53c 重算 bbox 后回 1cef44 / 1cf2a0；其余为 4 次 lrint 之后的分支续块
 */
/* @0x1cf41c ldr r0, [r9, #0xac] —— pass3：sprite 缺失 → 试 mask_index */
/* @0x1cf420 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf424 cmp r0, #0 */
/* @0x1cf428 bne 0x1cef38 <_Z11HandleOtherv+0x9a4> —— 有 mask → 回 1cef38 */
/* @0x1cf42c add r3, sp, #120 —— 都无 → 用 x/y 点判（vs 视图矩形 4 个 int 边界） */
/* @0x1cf430 vldr s11, [r9, #180] */
/* @0x1cf434 ldr r3, [r7, r3] */
/* @0x1cf438 vmov s15, r3 */
/* @0x1cf43c vcvt.f32.s32 s15, s15 */
/* @0x1cf440 vcmpe.f32 s11, s15 */
/* @0x1cf444 vmrs APSR_nzcv, fpscr */
/* @0x1cf448 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf44c add r3, sp, #184 */
/* @0x1cf450 ldr r3, [r7, r3] */
/* @0x1cf454 vmov s15, r3 */
/* @0x1cf458 vcvt.f32.s32 s15, s15 */
/* @0x1cf45c vcmpe.f32 s11, s15 */
/* @0x1cf460 vmrs APSR_nzcv, fpscr */
/* @0x1cf464 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf468 add r3, sp, #152 */
/* @0x1cf46c vldr s10, [r9, #184] */
/* @0x1cf470 ldr r3, [r7, r3] */
/* @0x1cf474 vmov s15, r3 */
/* @0x1cf478 vcvt.f32.s32 s15, s15 */
/* @0x1cf47c vcmpe.f32 s10, s15 */
/* @0x1cf480 vmrs APSR_nzcv, fpscr */
/* @0x1cf484 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf488 add r3, sp, #216 */
/* @0x1cf48c ldr r3, [r7, r3] */
/* @0x1cf490 vmov s15, r3 */
/* @0x1cf494 vcvt.f32.s32 s15, s15 */
/* @0x1cf498 vcmpe.f32 s10, s15 */
/* @0x1cf49c vmrs APSR_nzcv, fpscr */
/* @0x1cf4a0 bgt 0x1cf080 <_Z11HandleOtherv+0xaec> */
/* @0x1cf4a4 ldr r12, [sp, #0x30] —— 角度数组 */
/* @0x1cf4a8 vldr s15, [r12] */
/* @0x1cf4ac vcmp.f32 s15, #0 */
/* @0x1cf4b0 vmrs APSR_nzcv, fpscr */
/* @0x1cf4b4 beq 0x1cf094 <_Z11HandleOtherv+0xb00> —— 角度 == 0 → 1cf094（无事件） */
/* @0x1cf4b8 ldr r2, [sp, #0x24] */
/* @0x1cf4bc mov r1, #0 */
/* @0x1cf4c0 ldr r3, [sp, #0x28] */
/* @0x1cf4c4 vldr s15, [r3, #-4] —— 4 条边逐条叉积（vnmls） */
/* @0x1cf4c8 vsub.f32 s15, s11, s15 */
/* @0x1cf4cc vldr s12, [r2] */
/* @0x1cf4d0 vldr s13, [r3] */
/* @0x1cf4d4 vldr s14, [r2, #-4] */
/* @0x1cf4d8 add r1, r1, #1 */
/* @0x1cf4dc add r3, r3, #8 */
/* @0x1cf4e0 add r2, r2, #8 */
/* @0x1cf4e4 vmul.f32 s15, s15, s12 */
/* @0x1cf4e8 vsub.f32 s13, s10, s13 */
/* @0x1cf4ec vnmls.f32 s15, s13, s14 */
/* @0x1cf4f0 vcmpe.f32 s15, #0 */
/* @0x1cf4f4 vmrs APSR_nzcv, fpscr */
/* @0x1cf4f8 bmi 0x1cf080 <_Z11HandleOtherv+0xaec> —— 叉积 < 0 → 1cf080 派发 */
/* @0x1cf4fc cmp r1, #4 —— 4 条边循环计数 */
/* @0x1cf500 bne 0x1cf4c4 <_Z11HandleOtherv+0xf30> */
/* @0x1cf504 b 0x1cf094 <_Z11HandleOtherv+0xb00> —— 4 条边都没叉出去 → 无事件 */
/* @0x1cf508 ldr r0, [r5, #0xac] —— pass4：sprite 缺失 → 试 mask_index */
/* @0x1cf50c bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf510 cmp r0, #0 */
/* @0x1cf514 beq 0x1cf3b0 <_Z11HandleOtherv+0xe1c> —— 无 mask → 跳过 */
/* @0x1cf518 ldrb r3, [r5, #0x64] */
/* @0x1cf51c cmp r3, #0 */
/* @0x1cf520 beq 0x1cf2a0 <_Z11HandleOtherv+0xd0c> —— 有 mask 且 bbox 干净 → 回 1cf2a0 用 bbox */
/* @0x1cf524 mov r0, r5 */
/* @0x1cf528 mov r1, #1 —— Compute_BoundingBox 第二参 = true */
/* @0x1cf52c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf530 b 0x1cf2a0 <_Z11HandleOtherv+0xd0c> */
/* @0x1cf534 mov r0, r9 */
/* @0x1cf538 mov r1, #1 */
/* @0x1cf53c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> —— Compute_BoundingBox(inst=r9, true) */
/* @0x1cf540 b 0x1cef44 <_Z11HandleOtherv+0x9b0> */
/* @0x1cf544 ldrb r3, [r5, #0x64] */
/* @0x1cf548 cmp r3, #0 */
/* @0x1cf54c bne 0x1cf848 <_Z11HandleOtherv+0x12b4> */
/* @0x1cf550 vldr s14, [r5, #232] */
/* @0x1cf554 vcvt.f32.s32 s16, s14 */
/* @0x1cf558 vstr s16, [sp, #248] */
/* @0x1cf55c vcvt.f32.s32 s17, s15 */
/* @0x1cf560 vstr s17, [sp, #252] */
/* @0x1cf564 vldr s13, [r5, #240] */
/* @0x1cf568 vcvt.f32.s32 s12, s13 */
/* @0x1cf56c vstr s12, [sp, #256] */
/* @0x1cf570 vcvt.f32.s32 s15, s15 */
/* @0x1cf574 vstr s15, [sp, #260] */
/* @0x1cf578 vcvt.f32.s32 s13, s13 */
/* @0x1cf57c vstr s13, [sp, #264] */
/* @0x1cf580 vldr s15, [r5, #244] */
/* @0x1cf584 vcvt.f32.s32 s13, s15 */
/* @0x1cf588 vstr s13, [sp, #268] */
/* @0x1cf58c vcvt.f32.s32 s14, s14 */
/* @0x1cf590 vstr s14, [sp, #272] */
/* @0x1cf594 vcvt.f32.s32 s15, s15 */
/* @0x1cf598 ldr r9, [sp, #0x38] */
/* @0x1cf59c ldr r8, [sp, #0x34] */
/* @0x1cf5a0 mov r10, #4 */
/* @0x1cf5a4 mov r12, #1 */
/* @0x1cf5a8 vstr s15, [sp, #276] */
/* @0x1cf5ac vmov.f32 s14, s17 */
/* @0x1cf5b0 add r3, sp, #256 */
/* @0x1cf5b4 mov r0, #1 */
/* @0x1cf5b8 vldr s10, [r8, #-4] */
/* @0x1cf5bc vldr s11, [r8] */
/* @0x1cf5c0 vldr s12, [r9, #-4] */
/* @0x1cf5c4 vldr s13, [r9] */
/* @0x1cf5c8 vmov.f32 s15, s16 */
/* @0x1cf5cc eor r1, r0, #1 */
/* @0x1cf5d0 mov r2, r7 */
/* @0x1cf5d4 vsub.f32 s15, s15, s10 */
/* @0x1cf5d8 vmul.f32 s15, s15, s13 */
/* @0x1cf5dc vsub.f32 s14, s14, s11 */
/* @0x1cf5e0 vnmls.f32 s15, s14, s12 */
/* @0x1cf5e4 vcmpe.f32 s15, #0 */
/* @0x1cf5e8 vmrs APSR_nzcv, fpscr */
/* @0x1cf5ec movgt r12, #0 */
/* @0x1cf5f0 ble 0x1cf614 <_Z11HandleOtherv+0x1080> */
/* @0x1cf5f4 tst r1, r2 */
/* @0x1cf5f8 add r3, r3, #8 */
/* @0x1cf5fc bne 0x1cf630 <_Z11HandleOtherv+0x109c> */
/* @0x1cf600 cmp r3, r11 */
/* @0x1cf604 beq 0x1cf650 <_Z11HandleOtherv+0x10bc> */
/* @0x1cf608 vldr s15, [r3, #-8] */
/* @0x1cf60c vldr s14, [r3, #-4] */
/* @0x1cf610 b 0x1cf5cc <_Z11HandleOtherv+0x1038> */
/* @0x1cf614 eor r1, r0, #1 */
/* @0x1cf618 eor r2, r12, #1 */
/* @0x1cf61c movmi r1, r7 */
/* @0x1cf620 movmi r0, #0 */
/* @0x1cf624 tst r1, r2 */
/* @0x1cf628 add r3, r3, #8 */
/* @0x1cf62c beq 0x1cf600 <_Z11HandleOtherv+0x106c> */
/* @0x1cf630 subs r10, r10, #1 */
/* @0x1cf634 mov r12, #0 */
/* @0x1cf638 add r8, r8, #8 */
/* @0x1cf63c add r9, r9, #8 */
/* @0x1cf640 bne 0x1cf5ac <_Z11HandleOtherv+0x1018> */
/* @0x1cf644 cmp r12, #0 */
/* @0x1cf648 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf64c b 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf650 cmp r0, #0 */
/* @0x1cf654 bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf658 subs r10, r10, #1 */
/* @0x1cf65c add r8, r8, #8 */
/* @0x1cf660 add r9, r9, #8 */
/* @0x1cf664 bne 0x1cf5ac <_Z11HandleOtherv+0x1018> */
/* @0x1cf668 cmp r12, #0 */
/* @0x1cf66c bne 0x1cf3b0 <_Z11HandleOtherv+0xe1c> */
/* @0x1cf670 b 0x1cf39c <_Z11HandleOtherv+0xe08> */
/* @0x1cf674 subs r0, r0, #1 */
/* @0x1cf678 add r2, r2, #8 */
/* @0x1cf67c add r1, r1, #8 */
/* @0x1cf680 bne 0x1cf034 <_Z11HandleOtherv+0xaa0> */
/* @0x1cf684 b 0x1cf094 <_Z11HandleOtherv+0xb00> */
/* @0x1cf688 mov r0, r5 */
/* @0x1cf68c mov r1, #1 */
/* @0x1cf690 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> —— Compute_BoundingBox */
/* @0x1cf694 b 0x1cf2c4 <_Z11HandleOtherv+0xd30> */
/* @0x1cf698 mov r0, r9 */
/* @0x1cf69c mov r1, #1 */
/* @0x1cf6a0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> —— Compute_BoundingBox */
/* @0x1cf6a4 b 0x1cef64 <_Z11HandleOtherv+0x9d0> */
/* ── 惰性重算跳板：每个块 Compute_BoundingBox(inst,true) 后 b 回断点 ──
 *   回跳点成对出现：1ce6f4/1ce70c/1ce72c/1ce744/1ce8a4/1ce8c4/1ce8dc/1cef44/
 *   1cef64/1cef84/1cefa4/1cf2a0/1cf2c4/1cf2e8/1cf30c/1cf348/1cf360/1cf390 …
 */
/* @0x1cf6a8 ldr r0, [r6, #0xac] */
/* @0x1cf6ac bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1cf6b0 cmp r0, #0 */
/* @0x1cf6b4 bne 0x1ce880 <_Z11HandleOtherv+0x2ec> */
/* @0x1cf6b8 vldr s14, [r6, #180] */
/* @0x1cf6bc vcmpe.f32 s14, #0 */
/* @0x1cf6c0 vmrs APSR_nzcv, fpscr */
/* @0x1cf6c4 bmi 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6c8 ldr r3, [r10] */
/* @0x1cf6cc vldr s12, [r3, #16] */
/* @0x1cf6d0 vcvt.f32.s32 s15, s12 */
/* @0x1cf6d4 vcmpe.f32 s14, s15 */
/* @0x1cf6d8 vmrs APSR_nzcv, fpscr */
/* @0x1cf6dc bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6e0 vldr s15, [r6, #184] */
/* @0x1cf6e4 vcmpe.f32 s15, #0 */
/* @0x1cf6e8 vmrs APSR_nzcv, fpscr */
/* @0x1cf6ec bmi 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf6f0 vldr s14, [r3, #20] */
/* @0x1cf6f4 vcvt.f32.s32 s14, s14 */
/* @0x1cf6f8 vcmpe.f32 s15, s14 */
/* @0x1cf6fc vmrs APSR_nzcv, fpscr */
/* @0x1cf700 bgt 0x1ce8f0 <_Z11HandleOtherv+0x35c> */
/* @0x1cf704 b 0x1ce828 <_Z11HandleOtherv+0x294> */
/* @0x1cf708 mov r0, r9 */
/* @0x1cf70c mov r1, #1 */
/* @0x1cf710 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> —— Compute_BoundingBox */
/* @0x1cf714 vldr s14, [r9, #232] */
/* @0x1cf718 vcvt.f32.s32 s16, s14 */
/* @0x1cf71c ldrb r3, [r9, #0x64] */
/* @0x1cf720 cmp r3, #0 */
/* @0x1cf724 vldreq s13, [r9, #236] */
/* @0x1cf728 vstr s16, [sp, #248] */
/* @0x1cf72c beq 0x1cefe8 <_Z11HandleOtherv+0xa54> */
/* @0x1cf730 mov r0, r9 */
/* @0x1cf734 mov r1, #1 */
/* @0x1cf738 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf73c vldr s13, [r9, #236] */
/* @0x1cf740 vcvt.f32.s32 s17, s13 */
/* @0x1cf744 ldrb r3, [r9, #0x64] */
/* @0x1cf748 cmp r3, #0 */
/* @0x1cf74c vldreq s14, [r9, #232] */
/* @0x1cf750 vstr s17, [sp, #252] */
/* @0x1cf754 beq 0x1ceff0 <_Z11HandleOtherv+0xa5c> */
/* @0x1cf758 mov r0, r9 */
/* @0x1cf75c mov r1, #1 */
/* @0x1cf760 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf764 vldr s15, [r9, #240] */
/* @0x1cf768 vcvt.f32.s32 s14, s15 */
/* @0x1cf76c ldrb r3, [r9, #0x64] */
/* @0x1cf770 cmp r3, #0 */
/* @0x1cf774 vstr s14, [sp, #256] */
/* @0x1cf778 beq 0x1d0098 <_Z11HandleOtherv+0x1b04> */
/* @0x1cf77c mov r0, r9 */
/* @0x1cf780 mov r1, #1 */
/* @0x1cf784 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf788 vldr s12, [r9, #236] */
/* @0x1cf78c vcvt.f32.s32 s15, s12 */
/* @0x1cf790 ldrb r3, [r9, #0x64] */
/* @0x1cf794 cmp r3, #0 */
/* @0x1cf798 vstr s15, [sp, #260] */
/* @0x1cf79c beq 0x1d005c <_Z11HandleOtherv+0x1ac8> */
/* @0x1cf7a0 mov r0, r9 */
/* @0x1cf7a4 mov r1, #1 */
/* @0x1cf7a8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7ac vldr s13, [r9, #240] */
/* @0x1cf7b0 vcvt.f32.s32 s15, s13 */
/* @0x1cf7b4 ldrb r3, [r9, #0x64] */
/* @0x1cf7b8 cmp r3, #0 */
/* @0x1cf7bc vldreq s14, [r9, #232] */
/* @0x1cf7c0 vstr s15, [sp, #264] */
/* @0x1cf7c4 beq 0x1cf00c <_Z11HandleOtherv+0xa78> */
/* @0x1cf7c8 mov r0, r9 */
/* @0x1cf7cc mov r1, #1 */
/* @0x1cf7d0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7d4 vldr s15, [r9, #244] */
/* @0x1cf7d8 vcvt.f32.s32 s14, s15 */
/* @0x1cf7dc ldrb r3, [r9, #0x64] */
/* @0x1cf7e0 cmp r3, #0 */
/* @0x1cf7e4 vstr s14, [sp, #268] */
/* @0x1cf7e8 vldreq s14, [r9, #232] */
/* @0x1cf7ec beq 0x1cf018 <_Z11HandleOtherv+0xa84> */
/* @0x1cf7f0 mov r0, r9 */
/* @0x1cf7f4 mov r1, #1 */
/* @0x1cf7f8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf7fc vldr s14, [r9, #232] */
/* @0x1cf800 vcvt.f32.s32 s15, s14 */
/* @0x1cf804 ldrb r3, [r9, #0x64] */
/* @0x1cf808 cmp r3, #0 */
/* @0x1cf80c vstr s15, [sp, #272] */
/* @0x1cf810 beq 0x1cf820 <_Z11HandleOtherv+0x128c> */
/* @0x1cf814 mov r0, r9 */
/* @0x1cf818 mov r1, #1 */
/* @0x1cf81c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf820 vldr s15, [r9, #244] */
/* @0x1cf824 b 0x1cf020 <_Z11HandleOtherv+0xa8c> */
/* @0x1cf828 mov r0, r6 */
/* @0x1cf82c mov r1, #1 */
/* @0x1cf830 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf834 b 0x1ce6f4 <_Z11HandleOtherv+0x160> */
/* @0x1cf838 mov r0, r6 */
/* @0x1cf83c mov r1, #1 */
/* @0x1cf840 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf844 b 0x1ce88c <_Z11HandleOtherv+0x2f8> */
/* @0x1cf848 mov r0, r5 */
/* @0x1cf84c mov r1, #1 */
/* @0x1cf850 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf854 vldr s14, [r5, #232] */
/* @0x1cf858 vcvt.f32.s32 s16, s14 */
/* @0x1cf85c ldrb r3, [r5, #0x64] */
/* @0x1cf860 cmp r3, #0 */
/* @0x1cf864 vstr s16, [sp, #248] */
/* @0x1cf868 beq 0x1d0090 <_Z11HandleOtherv+0x1afc> */
/* @0x1cf86c mov r0, r5 */
/* @0x1cf870 mov r1, #1 */
/* @0x1cf874 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf878 vldr s15, [r5, #236] */
/* @0x1cf87c vcvt.f32.s32 s17, s15 */
/* @0x1cf880 ldrb r3, [r5, #0x64] */
/* @0x1cf884 cmp r3, #0 */
/* @0x1cf888 vstr s17, [sp, #252] */
/* @0x1cf88c beq 0x1d00a4 <_Z11HandleOtherv+0x1b10> */
/* @0x1cf890 mov r0, r5 */
/* @0x1cf894 mov r1, #1 */
/* @0x1cf898 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf89c vldr s13, [r5, #240] */
/* @0x1cf8a0 vcvt.f32.s32 s15, s13 */
/* @0x1cf8a4 ldrb r3, [r5, #0x64] */
/* @0x1cf8a8 cmp r3, #0 */
/* @0x1cf8ac vstr s15, [sp, #256] */
/* @0x1cf8b0 beq 0x1d007c <_Z11HandleOtherv+0x1ae8> */
/* @0x1cf8b4 mov r0, r5 */
/* @0x1cf8b8 mov r1, #1 */
/* @0x1cf8bc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf8c0 vldr s12, [r5, #236] */
/* @0x1cf8c4 vcvt.f32.s32 s15, s12 */
/* @0x1cf8c8 ldrb r3, [r5, #0x64] */
/* @0x1cf8cc cmp r3, #0 */
/* @0x1cf8d0 vstr s15, [sp, #260] */
/* @0x1cf8d4 beq 0x1d0070 <_Z11HandleOtherv+0x1adc> */
/* @0x1cf8d8 mov r0, r5 */
/* @0x1cf8dc mov r1, #1 */
/* @0x1cf8e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf8e4 vldr s13, [r5, #240] */
/* @0x1cf8e8 vcvt.f32.s32 s15, s13 */
/* @0x1cf8ec ldrb r3, [r5, #0x64] */
/* @0x1cf8f0 cmp r3, #0 */
/* @0x1cf8f4 vstr s15, [sp, #264] */
/* @0x1cf8f8 beq 0x1d0068 <_Z11HandleOtherv+0x1ad4> */
/* @0x1cf8fc mov r0, r5 */
/* @0x1cf900 mov r1, #1 */
/* @0x1cf904 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf908 vldr s15, [r5, #244] */
/* @0x1cf90c vcvt.f32.s32 s14, s15 */
/* @0x1cf910 ldrb r3, [r5, #0x64] */
/* @0x1cf914 cmp r3, #0 */
/* @0x1cf918 vstr s14, [sp, #268] */
/* @0x1cf91c beq 0x1d0088 <_Z11HandleOtherv+0x1af4> */
/* @0x1cf920 mov r0, r5 */
/* @0x1cf924 mov r1, #1 */
/* @0x1cf928 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf92c vldr s14, [r5, #232] */
/* @0x1cf930 vcvt.f32.s32 s15, s14 */
/* @0x1cf934 ldrb r3, [r5, #0x64] */
/* @0x1cf938 cmp r3, #0 */
/* @0x1cf93c vstr s15, [sp, #272] */
/* @0x1cf940 beq 0x1cf950 <_Z11HandleOtherv+0x13bc> */
/* @0x1cf944 mov r0, r5 */
/* @0x1cf948 mov r1, #1 */
/* @0x1cf94c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf950 vldr s15, [r5, #244] */
/* @0x1cf954 b 0x1cf594 <_Z11HandleOtherv+0x1000> */
/* @0x1cf958 mov r0, r9 */
/* @0x1cf95c mov r1, #1 */
/* @0x1cf960 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf964 b 0x1cef84 <_Z11HandleOtherv+0x9f0> */
/* @0x1cf968 mov r0, r5 */
/* @0x1cf96c mov r1, #1 */
/* @0x1cf970 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf974 b 0x1cf2e8 <_Z11HandleOtherv+0xd54> */
/* @0x1cf978 mov r0, r5 */
/* @0x1cf97c mov r1, #1 */
/* @0x1cf980 str r3, [sp, #0x4] */
/* @0x1cf984 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf988 ldr r3, [sp, #0x4] */
/* @0x1cf98c b 0x1cf348 <_Z11HandleOtherv+0xdb4> */
/* @0x1cf990 mov r0, r6 */
/* @0x1cf994 mov r1, #1 */
/* @0x1cf998 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf99c b 0x1ce70c <_Z11HandleOtherv+0x178> */
/* @0x1cf9a0 mov r0, r6 */
/* @0x1cf9a4 mov r1, #1 */
/* @0x1cf9a8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9ac b 0x1ce8a4 <_Z11HandleOtherv+0x310> */
/* @0x1cf9b0 mov r0, r5 */
/* @0x1cf9b4 mov r1, #1 */
/* @0x1cf9b8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9bc b 0x1cf30c <_Z11HandleOtherv+0xd78> */
/* @0x1cf9c0 mov r0, r5 */
/* @0x1cf9c4 mov r1, #1 */
/* @0x1cf9c8 str r3, [sp, #0x4] */
/* @0x1cf9cc bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9d0 ldr r3, [sp, #0x4] */
/* @0x1cf9d4 b 0x1cf360 <_Z11HandleOtherv+0xdcc> */
/* @0x1cf9d8 mov r0, r9 */
/* @0x1cf9dc mov r1, #1 */
/* @0x1cf9e0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cf9e4 b 0x1cefa4 <_Z11HandleOtherv+0xa10> */
/* ── 旋转角点的 min/max 选择（4 角两两比较，NaN→1d0024 等短跳板）───── */
/* @0x1cf9e8 vcmpe.f32 s14, s11 —— 旋转角点 min/max 选择块 */
/* @0x1cf9ec vmrs APSR_nzcv, fpscr */
/* @0x1cf9f0 bpl 0x1cfccc <_Z11HandleOtherv+0x1738> */
/* @0x1cf9f4 vcmpe.f32 s12, s14 */
/* @0x1cf9f8 vmrs APSR_nzcv, fpscr */
/* @0x1cf9fc vmovpl.f32 s7, s14 */
/* @0x1cfa00 bmi 0x1ceaac <_Z11HandleOtherv+0x518> */
/* @0x1cfa04 vcmpe.f32 s7, s8 */
/* @0x1cfa08 vmrs APSR_nzcv, fpscr */
/* @0x1cfa0c bpl 0x1ceab8 <_Z11HandleOtherv+0x524> */
/* @0x1cfa10 vcmpe.f32 s12, s14 */
/* @0x1cfa14 vmrs APSR_nzcv, fpscr */
/* @0x1cfa18 bpl 0x1cfa30 <_Z11HandleOtherv+0x149c> */
/* @0x1cfa1c vcmpe.f32 s12, s11 */
/* @0x1cfa20 vmrs APSR_nzcv, fpscr */
/* @0x1cfa24 bmi 0x1cfa48 <_Z11HandleOtherv+0x14b4> */
/* @0x1cfa28 vcvt.s32.f32 s7, s11 */
/* @0x1cfa2c b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1cfa30 vcmpe.f32 s14, s11 */
/* @0x1cfa34 vmrs APSR_nzcv, fpscr */
/* @0x1cfa38 bpl 0x1cfa28 <_Z11HandleOtherv+0x1494> */
/* @0x1cfa3c vcmpe.f32 s12, s14 */
/* @0x1cfa40 vmrs APSR_nzcv, fpscr */
/* @0x1cfa44 bpl 0x1d0024 <_Z11HandleOtherv+0x1a90> */
/* @0x1cfa48 vcvt.s32.f32 s7, s12 */
/* @0x1cfa4c b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1cfa50 mov r0, r6 */
/* @0x1cfa54 mov r1, #1 */
/* @0x1cfa58 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfa5c b 0x1ce8c4 <_Z11HandleOtherv+0x330> */
/* @0x1cfa60 mov r0, r6 */
/* @0x1cfa64 mov r1, #1 */
/* @0x1cfa68 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfa6c b 0x1ce72c <_Z11HandleOtherv+0x198> */
/* ── 旋转视口：sinf/cosf(角度×0.0174533) 后按半宽/半高生成 4 角 ──────
 *   s21 = -(angle*π/180)，s20 = sinf(s21)，s0 = cosf(s21)；
 *   view+4/+8 是中心（不是左上角），±半宽/半高旋转后写 4 角
 */
/* @0x1cfa70 vnmul.f32 s21, s15, s19 —— 角度取负 */
/* @0x1cfa74 str r1, [sp, #0x4] —— 保存 view 指针 */
/* @0x1cfa78 str r12, [sp] */
/* @0x1cfa7c vmov r0, s21 */
/* @0x1cfa80 bl 0xb6580 <sinf@plt> —— sinf(angle) */
/* @0x1cfa84 vmov s20, r0 */
/* @0x1cfa88 vmov r0, s21 */
/* @0x1cfa8c bl 0xb658c <cosf@plt> —— cosf(angle) */
/* @0x1cfa90 ldr r1, [sp, #0x4] */
/* @0x1cfa94 vldr s13, [r1, #12] */
/* @0x1cfa98 vmul.f32 s13, s13, s16 */
/* @0x1cfa9c vldr s15, [r1, #16] */
/* @0x1cfaa0 vldr s14, [r1, #4] */
/* @0x1cfaa4 vldr s10, [r1, #8] */
/* @0x1cfaa8 ldr r12, [sp] */
/* @0x1cfaac vmul.f32 s15, s15, s16 */
/* @0x1cfab0 vnmul.f32 s8, s20, s13 */
/* @0x1cfab4 vmov s11, r0 */
/* @0x1cfab8 vmul.f32 s12, s13, s11 */
/* @0x1cfabc vadd.f32 s13, s13, s14 */
/* @0x1cfac0 vmul.f32 s14, s15, s20 */
/* @0x1cfac4 vadd.f32 s10, s15, s10 */
/* @0x1cfac8 vmul.f32 s15, s15, s11 */
/* @0x1cfacc vsub.f32 s11, s13, s12 */
/* @0x1cfad0 vsub.f32 s9, s10, s8 */
/* @0x1cfad4 vadd.f32 s12, s12, s13 */
/* @0x1cfad8 vadd.f32 s13, s8, s10 */
/* @0x1cfadc vadd.f32 s10, s14, s11 */
/* @0x1cfae0 vsub.f32 s11, s11, s14 */
/* @0x1cfae4 vstr s10, [r5] —— 旋转后的 4 角（中心 ± 半宽/半高） */
/* @0x1cfae8 vadd.f32 s10, s14, s12 */
/* @0x1cfaec vsub.f32 s14, s12, s14 */
/* @0x1cfaf0 vadd.f32 s12, s15, s9 */
/* @0x1cfaf4 vsub.f32 s9, s9, s15 */
/* @0x1cfaf8 vstr s12, [r10] */
/* @0x1cfafc vstr s10, [r9] */
/* @0x1cfb00 vadd.f32 s12, s15, s13 */
/* @0x1cfb04 vsub.f32 s15, s13, s15 */
/* @0x1cfb08 vstr s12, [r11] */
/* @0x1cfb0c vstr s14, [r5, #16] */
/* @0x1cfb10 vstr s15, [r5, #20] */
/* @0x1cfb14 vstr s11, [r8] */
/* @0x1cfb18 vstr s9, [r5, #28] */
/* @0x1cfb1c vldr s14, [r5] */
/* @0x1cfb20 vldr s15, [r9] */
/* @0x1cfb24 vcmpe.f32 s14, s15 */
/* @0x1cfb28 vldr s11, [r5, #16] */
/* @0x1cfb2c vmrs APSR_nzcv, fpscr */
/* @0x1cfb30 bpl 0x1cfc28 <_Z11HandleOtherv+0x1694> */
/* @0x1cfb34 vcmpe.f32 s14, s11 */
/* @0x1cfb38 vmrs APSR_nzcv, fpscr */
/* @0x1cfb3c bpl 0x1cffa0 <_Z11HandleOtherv+0x1a0c> */
/* @0x1cfb40 vldr s8, [r8] */
/* @0x1cfb44 vcmpe.f32 s14, s8 */
/* @0x1cfb48 vmrs APSR_nzcv, fpscr */
/* @0x1cfb4c bmi 0x1cfc60 <_Z11HandleOtherv+0x16cc> */
/* @0x1cfb50 vcvt.s32.f32 s10, s8 */
/* @0x1cfb54 vmov r0, s10 */
/* @0x1cfb58 vldr s12, [r10] */
/* @0x1cfb5c vldr s13, [r11] */
/* @0x1cfb60 add r1, sp, #120 */
/* @0x1cfb64 vldr s10, [r5, #20] */
/* @0x1cfb68 vcmpe.f32 s12, s13 */
/* @0x1cfb6c vmrs APSR_nzcv, fpscr */
/* @0x1cfb70 str r0, [r6, r1] */
/* @0x1cfb74 bpl 0x1cfe68 <_Z11HandleOtherv+0x18d4> */
/* @0x1cfb78 vcmpe.f32 s10, s12 */
/* @0x1cfb7c vmrs APSR_nzcv, fpscr */
/* @0x1cfb80 ble 0x1cffa8 <_Z11HandleOtherv+0x1a14> */
/* @0x1cfb84 vcmpe.f32 s9, s12 */
/* @0x1cfb88 vmrs APSR_nzcv, fpscr */
/* @0x1cfb8c bgt 0x1cfe9c <_Z11HandleOtherv+0x1908> */
/* @0x1cfb90 vcvt.s32.f32 s7, s9 */
/* @0x1cfb94 vmov r2, s7 */
/* @0x1cfb98 add r1, sp, #152 */
/* @0x1cfb9c vcmpe.f32 s14, s15 */
/* @0x1cfba0 vmrs APSR_nzcv, fpscr */
/* @0x1cfba4 str r2, [r6, r1] */
/* @0x1cfba8 ble 0x1cfed0 <_Z11HandleOtherv+0x193c> */
/* @0x1cfbac vcmpe.f32 s14, s11 */
/* @0x1cfbb0 vmrs APSR_nzcv, fpscr */
/* @0x1cfbb4 ble 0x1cffb0 <_Z11HandleOtherv+0x1a1c> */
/* @0x1cfbb8 vcmpe.f32 s8, s14 */
/* @0x1cfbbc vmrs APSR_nzcv, fpscr */
/* @0x1cfbc0 bmi 0x1cff04 <_Z11HandleOtherv+0x1970> */
/* @0x1cfbc4 vcvt.s32.f32 s7, s8 */
/* @0x1cfbc8 vmov r3, s7 */
/* @0x1cfbcc add r1, sp, #184 */
/* @0x1cfbd0 vcmpe.f32 s12, s13 */
/* @0x1cfbd4 vmrs APSR_nzcv, fpscr */
/* @0x1cfbd8 str r3, [r6, r1] */
/* @0x1cfbdc ble 0x1cff38 <_Z11HandleOtherv+0x19a4> */
/* @0x1cfbe0 vcmpe.f32 s12, s10 */
/* @0x1cfbe4 vmrs APSR_nzcv, fpscr */
/* @0x1cfbe8 ble 0x1cffb8 <_Z11HandleOtherv+0x1a24> */
/* @0x1cfbec vcmpe.f32 s9, s12 */
/* @0x1cfbf0 vmrs APSR_nzcv, fpscr */
/* @0x1cfbf4 bmi 0x1cff6c <_Z11HandleOtherv+0x19d8> */
/* @0x1cfbf8 vcvt.s32.f32 s7, s9 */
/* @0x1cfbfc vmov r2, s7 */
/* @0x1cfc00 add r3, sp, #88 —— 角度数组 */
/* @0x1cfc04 ldr r1, [sp, #0x3c] */
/* @0x1cfc08 ldr r0, [r1] */
/* @0x1cfc0c add r1, sp, #216 */
/* @0x1cfc10 ldr r0, [r0, r12, lsl #2] */
/* @0x1cfc14 ldr r0, [r0, #0x24] —— view->[0x24] = 角度 */
/* @0x1cfc18 str r2, [r6, r1] */
/* @0x1cfc1c add r1, r3, r6 */
/* @0x1cfc20 str r0, [r1] —— 写回角度数组（真实角度） */
/* @0x1cfc24 b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* @0x1cfc28 vcmpe.f32 s15, s11 */
/* @0x1cfc2c vmrs APSR_nzcv, fpscr */
/* @0x1cfc30 bpl 0x1cffa0 <_Z11HandleOtherv+0x1a0c> */
/* @0x1cfc34 vcmpe.f32 s14, s15 */
/* @0x1cfc38 vmrs APSR_nzcv, fpscr */
/* @0x1cfc3c vmovpl.f32 s13, s15 */
/* @0x1cfc40 bmi 0x1cfb40 <_Z11HandleOtherv+0x15ac> */
/* @0x1cfc44 vldr s8, [r8] */
/* @0x1cfc48 vcmpe.f32 s13, s8 */
/* @0x1cfc4c vmrs APSR_nzcv, fpscr */
/* @0x1cfc50 bpl 0x1cfb50 <_Z11HandleOtherv+0x15bc> */
/* @0x1cfc54 vcmpe.f32 s14, s15 */
/* @0x1cfc58 vmrs APSR_nzcv, fpscr */
/* @0x1cfc5c bpl 0x1cfc74 <_Z11HandleOtherv+0x16e0> */
/* @0x1cfc60 vcmpe.f32 s14, s11 */
/* @0x1cfc64 vmrs APSR_nzcv, fpscr */
/* @0x1cfc68 bpl 0x1cffd8 <_Z11HandleOtherv+0x1a44> */
/* @0x1cfc6c vcvt.s32.f32 s10, s14 */
/* @0x1cfc70 b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cfc74 vcmpe.f32 s15, s11 */
/* @0x1cfc78 vmrs APSR_nzcv, fpscr */
/* @0x1cfc7c bpl 0x1cffd8 <_Z11HandleOtherv+0x1a44> */
/* @0x1cfc80 vcmpe.f32 s14, s15 */
/* @0x1cfc84 vmrs APSR_nzcv, fpscr */
/* @0x1cfc88 bmi 0x1cfc6c <_Z11HandleOtherv+0x16d8> */
/* @0x1cfc8c vcvt.s32.f32 s10, s15 */
/* @0x1cfc90 b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cfc94 mov r0, r6 */
/* @0x1cfc98 mov r1, #1 */
/* @0x1cfc9c bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfca0 b 0x1ce744 <_Z11HandleOtherv+0x1b0> */
/* @0x1cfca4 mov r0, r6 */
/* @0x1cfca8 mov r1, #1 */
/* @0x1cfcac bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfcb0 b 0x1ce8dc <_Z11HandleOtherv+0x348> */
/* @0x1cfcb4 mov r0, r5 */
/* @0x1cfcb8 mov r1, #1 */
/* @0x1cfcbc str r3, [sp, #0x4] */
/* @0x1cfcc0 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cfcc4 ldr r3, [sp, #0x4] */
/* @0x1cfcc8 b 0x1cf378 <_Z11HandleOtherv+0xde4> */
/* @0x1cfccc vmov.f32 s7, s11 */
/* @0x1cfcd0 b 0x1cfa04 <_Z11HandleOtherv+0x1470> */
/* @0x1cfcd4 vcmpe.f32 s15, s9 */
/* @0x1cfcd8 vmrs APSR_nzcv, fpscr */
/* @0x1cfcdc bpl 0x1cfe1c <_Z11HandleOtherv+0x1888> */
/* @0x1cfce0 vcmpe.f32 s13, s15 */
/* @0x1cfce4 vmrs APSR_nzcv, fpscr */
/* @0x1cfce8 vmovpl.f32 s7, s15 */
/* @0x1cfcec bmi 0x1ceae0 <_Z11HandleOtherv+0x54c> */
/* @0x1cfcf0 vcmpe.f32 s7, s10 */
/* @0x1cfcf4 vmrs APSR_nzcv, fpscr */
/* @0x1cfcf8 bpl 0x1ceaec <_Z11HandleOtherv+0x558> */
/* @0x1cfcfc vcmpe.f32 s13, s15 */
/* @0x1cfd00 vmrs APSR_nzcv, fpscr */
/* @0x1cfd04 bpl 0x1cfd1c <_Z11HandleOtherv+0x1788> */
/* @0x1cfd08 vcmpe.f32 s13, s9 */
/* @0x1cfd0c vmrs APSR_nzcv, fpscr */
/* @0x1cfd10 bmi 0x1cfd34 <_Z11HandleOtherv+0x17a0> */
/* @0x1cfd14 vcvt.s32.f32 s7, s9 */
/* @0x1cfd18 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1cfd1c vcmpe.f32 s15, s9 */
/* @0x1cfd20 vmrs APSR_nzcv, fpscr */
/* @0x1cfd24 bpl 0x1cfd14 <_Z11HandleOtherv+0x1780> */
/* @0x1cfd28 vcmpe.f32 s13, s15 */
/* @0x1cfd2c vmrs APSR_nzcv, fpscr */
/* @0x1cfd30 bpl 0x1d0034 <_Z11HandleOtherv+0x1aa0> */
/* @0x1cfd34 vcvt.s32.f32 s7, s13 */
/* @0x1cfd38 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1cfd3c vcmpe.f32 s14, s11 */
/* @0x1cfd40 vmrs APSR_nzcv, fpscr */
/* @0x1cfd44 ble 0x1cfe0c <_Z11HandleOtherv+0x1878> */
/* @0x1cfd48 vcmpe.f32 s12, s14 */
/* @0x1cfd4c vmrs APSR_nzcv, fpscr */
/* @0x1cfd50 vmovle.f32 s7, s14 */
/* @0x1cfd54 bgt 0x1ceb14 <_Z11HandleOtherv+0x580> */
/* @0x1cfd58 vcmpe.f32 s7, s8 */
/* @0x1cfd5c vmrs APSR_nzcv, fpscr */
/* @0x1cfd60 ble 0x1ceb20 <_Z11HandleOtherv+0x58c> */
/* @0x1cfd64 vcmpe.f32 s12, s14 */
/* @0x1cfd68 vmrs APSR_nzcv, fpscr */
/* @0x1cfd6c ble 0x1cfd84 <_Z11HandleOtherv+0x17f0> */
/* @0x1cfd70 vcmpe.f32 s12, s11 */
/* @0x1cfd74 vmrs APSR_nzcv, fpscr */
/* @0x1cfd78 bgt 0x1cfd9c <_Z11HandleOtherv+0x1808> */
/* @0x1cfd7c vcvt.s32.f32 s14, s11 */
/* @0x1cfd80 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1cfd84 vcmpe.f32 s14, s11 */
/* @0x1cfd88 vmrs APSR_nzcv, fpscr */
/* @0x1cfd8c ble 0x1cfd7c <_Z11HandleOtherv+0x17e8> */
/* @0x1cfd90 vcmpe.f32 s12, s14 */
/* @0x1cfd94 vmrs APSR_nzcv, fpscr */
/* @0x1cfd98 ble 0x1d003c <_Z11HandleOtherv+0x1aa8> */
/* @0x1cfd9c vcvt.s32.f32 s14, s12 */
/* @0x1cfda0 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1cfda4 vcmpe.f32 s15, s9 */
/* @0x1cfda8 vmrs APSR_nzcv, fpscr */
/* @0x1cfdac ble 0x1cfe14 <_Z11HandleOtherv+0x1880> */
/* @0x1cfdb0 vcmpe.f32 s13, s15 */
/* @0x1cfdb4 vmrs APSR_nzcv, fpscr */
/* @0x1cfdb8 vmovle.f32 s14, s15 */
/* @0x1cfdbc bgt 0x1ceb48 <_Z11HandleOtherv+0x5b4> */
/* @0x1cfdc0 vcmpe.f32 s14, s10 */
/* @0x1cfdc4 vmrs APSR_nzcv, fpscr */
/* @0x1cfdc8 ble 0x1ceb54 <_Z11HandleOtherv+0x5c0> */
/* @0x1cfdcc vcmpe.f32 s13, s15 */
/* @0x1cfdd0 vmrs APSR_nzcv, fpscr */
/* @0x1cfdd4 ble 0x1cfdec <_Z11HandleOtherv+0x1858> */
/* @0x1cfdd8 vcmpe.f32 s13, s9 */
/* @0x1cfddc vmrs APSR_nzcv, fpscr */
/* @0x1cfde0 bgt 0x1cfe04 <_Z11HandleOtherv+0x1870> */
/* @0x1cfde4 vcvt.s32.f32 s13, s9 */
/* @0x1cfde8 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1cfdec vcmpe.f32 s15, s9 */
/* @0x1cfdf0 vmrs APSR_nzcv, fpscr */
/* @0x1cfdf4 ble 0x1cfde4 <_Z11HandleOtherv+0x1850> */
/* @0x1cfdf8 vcmpe.f32 s13, s15 */
/* @0x1cfdfc vmrs APSR_nzcv, fpscr */
/* @0x1cfe00 ble 0x1d002c <_Z11HandleOtherv+0x1a98> */
/* @0x1cfe04 vcvt.s32.f32 s13, s13 */
/* @0x1cfe08 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1cfe0c vmov.f32 s7, s11 */
/* @0x1cfe10 b 0x1cfd58 <_Z11HandleOtherv+0x17c4> */
/* @0x1cfe14 vmov.f32 s14, s9 */
/* @0x1cfe18 b 0x1cfdc0 <_Z11HandleOtherv+0x182c> */
/* @0x1cfe1c vmov.f32 s7, s9 */
/* @0x1cfe20 b 0x1cfcf0 <_Z11HandleOtherv+0x175c> */
/* ── 相机缺失路径：四组 int 数组直接填 r1（=-1）→ 跳 1ced5c 算边向量 ── */
/* @0x1cfe24 add r0, sp, #216 —— 相机缺失：x2 */
/* @0x1cfe28 vldr s15, [r9] */
/* @0x1cfe2c vldr s14, [r5] */
/* @0x1cfe30 vldr s13, [r11] */
/* @0x1cfe34 str r1, [r6, r0] */
/* @0x1cfe38 add r0, sp, #184 */
/* @0x1cfe3c vldr s12, [r10] */
/* @0x1cfe40 vldr s11, [r5, #16] */
/* @0x1cfe44 str r1, [r6, r0] */
/* @0x1cfe48 add r0, sp, #152 */
/* @0x1cfe4c vldr s10, [r5, #20] */
/* @0x1cfe50 vldr s8, [r8] */
/* @0x1cfe54 str r1, [r6, r0] */
/* @0x1cfe58 add r0, sp, #120 */
/* @0x1cfe5c vldr s9, [r5, #28] */
/* @0x1cfe60 str r1, [r6, r0] —— 4 组 int 边界都填 r1（-1） */
/* @0x1cfe64 b 0x1ced5c <_Z11HandleOtherv+0x7c8> */
/* @0x1cfe68 vcmpe.f32 s13, s10 */
/* @0x1cfe6c vmrs APSR_nzcv, fpscr */
/* @0x1cfe70 bpl 0x1cffa8 <_Z11HandleOtherv+0x1a14> */
/* @0x1cfe74 vcmpe.f32 s12, s13 */
/* @0x1cfe78 vmrs APSR_nzcv, fpscr */
/* @0x1cfe7c vmovpl.f32 s7, s13 */
/* @0x1cfe80 bmi 0x1cfb84 <_Z11HandleOtherv+0x15f0> */
/* @0x1cfe84 vcmpe.f32 s7, s9 */
/* @0x1cfe88 vmrs APSR_nzcv, fpscr */
/* @0x1cfe8c bpl 0x1cfb90 <_Z11HandleOtherv+0x15fc> */
/* @0x1cfe90 vcmpe.f32 s12, s13 */
/* @0x1cfe94 vmrs APSR_nzcv, fpscr */
/* @0x1cfe98 bpl 0x1cfeb0 <_Z11HandleOtherv+0x191c> */
/* @0x1cfe9c vcmpe.f32 s12, s10 */
/* @0x1cfea0 vmrs APSR_nzcv, fpscr */
/* @0x1cfea4 bpl 0x1cffd0 <_Z11HandleOtherv+0x1a3c> */
/* @0x1cfea8 vcvt.s32.f32 s7, s12 */
/* @0x1cfeac b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cfeb0 vcmpe.f32 s13, s10 */
/* @0x1cfeb4 vmrs APSR_nzcv, fpscr */
/* @0x1cfeb8 bpl 0x1cffd0 <_Z11HandleOtherv+0x1a3c> */
/* @0x1cfebc vcmpe.f32 s12, s13 */
/* @0x1cfec0 vmrs APSR_nzcv, fpscr */
/* @0x1cfec4 bmi 0x1cfea8 <_Z11HandleOtherv+0x1914> */
/* @0x1cfec8 vcvt.s32.f32 s7, s13 */
/* @0x1cfecc b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cfed0 vcmpe.f32 s15, s11 */
/* @0x1cfed4 vmrs APSR_nzcv, fpscr */
/* @0x1cfed8 ble 0x1cffb0 <_Z11HandleOtherv+0x1a1c> */
/* @0x1cfedc vcmpe.f32 s14, s15 */
/* @0x1cfee0 vmrs APSR_nzcv, fpscr */
/* @0x1cfee4 vmovle.f32 s7, s15 */
/* @0x1cfee8 bgt 0x1cfbb8 <_Z11HandleOtherv+0x1624> */
/* @0x1cfeec vcmpe.f32 s7, s8 */
/* @0x1cfef0 vmrs APSR_nzcv, fpscr */
/* @0x1cfef4 ble 0x1cfbc4 <_Z11HandleOtherv+0x1630> */
/* @0x1cfef8 vcmpe.f32 s14, s15 */
/* @0x1cfefc vmrs APSR_nzcv, fpscr */
/* @0x1cff00 ble 0x1cff18 <_Z11HandleOtherv+0x1984> */
/* @0x1cff04 vcmpe.f32 s14, s11 */
/* @0x1cff08 vmrs APSR_nzcv, fpscr */
/* @0x1cff0c ble 0x1cffc8 <_Z11HandleOtherv+0x1a34> */
/* @0x1cff10 vcvt.s32.f32 s7, s14 */
/* @0x1cff14 b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cff18 vcmpe.f32 s15, s11 */
/* @0x1cff1c vmrs APSR_nzcv, fpscr */
/* @0x1cff20 ble 0x1cffc8 <_Z11HandleOtherv+0x1a34> */
/* @0x1cff24 vcmpe.f32 s14, s15 */
/* @0x1cff28 vmrs APSR_nzcv, fpscr */
/* @0x1cff2c bgt 0x1cff10 <_Z11HandleOtherv+0x197c> */
/* @0x1cff30 vcvt.s32.f32 s7, s15 */
/* @0x1cff34 b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cff38 vcmpe.f32 s13, s10 */
/* @0x1cff3c vmrs APSR_nzcv, fpscr */
/* @0x1cff40 ble 0x1cffb8 <_Z11HandleOtherv+0x1a24> */
/* @0x1cff44 vcmpe.f32 s12, s13 */
/* @0x1cff48 vmrs APSR_nzcv, fpscr */
/* @0x1cff4c vmovle.f32 s7, s13 */
/* @0x1cff50 bgt 0x1cfbec <_Z11HandleOtherv+0x1658> */
/* @0x1cff54 vcmpe.f32 s7, s9 */
/* @0x1cff58 vmrs APSR_nzcv, fpscr */
/* @0x1cff5c ble 0x1cfbf8 <_Z11HandleOtherv+0x1664> */
/* @0x1cff60 vcmpe.f32 s12, s13 */
/* @0x1cff64 vmrs APSR_nzcv, fpscr */
/* @0x1cff68 ble 0x1cff80 <_Z11HandleOtherv+0x19ec> */
/* @0x1cff6c vcmpe.f32 s12, s10 */
/* @0x1cff70 vmrs APSR_nzcv, fpscr */
/* @0x1cff74 ble 0x1cffc0 <_Z11HandleOtherv+0x1a2c> */
/* @0x1cff78 vcvt.s32.f32 s7, s12 */
/* @0x1cff7c b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cff80 vcmpe.f32 s13, s10 */
/* @0x1cff84 vmrs APSR_nzcv, fpscr */
/* @0x1cff88 ble 0x1cffc0 <_Z11HandleOtherv+0x1a2c> */
/* @0x1cff8c vcmpe.f32 s12, s13 */
/* @0x1cff90 vmrs APSR_nzcv, fpscr */
/* @0x1cff94 bgt 0x1cff78 <_Z11HandleOtherv+0x19e4> */
/* @0x1cff98 vcvt.s32.f32 s7, s13 */
/* @0x1cff9c b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cffa0 vmov.f32 s13, s11 */
/* @0x1cffa4 b 0x1cfc44 <_Z11HandleOtherv+0x16b0> */
/* @0x1cffa8 vmov.f32 s7, s10 */
/* @0x1cffac b 0x1cfe84 <_Z11HandleOtherv+0x18f0> */
/* @0x1cffb0 vmov.f32 s7, s11 */
/* @0x1cffb4 b 0x1cfeec <_Z11HandleOtherv+0x1958> */
/* @0x1cffb8 vmov.f32 s7, s10 */
/* @0x1cffbc b 0x1cff54 <_Z11HandleOtherv+0x19c0> */
/* @0x1cffc0 vcvt.s32.f32 s7, s10 */
/* @0x1cffc4 b 0x1cfbfc <_Z11HandleOtherv+0x1668> */
/* @0x1cffc8 vcvt.s32.f32 s7, s11 */
/* @0x1cffcc b 0x1cfbc8 <_Z11HandleOtherv+0x1634> */
/* @0x1cffd0 vcvt.s32.f32 s7, s10 */
/* @0x1cffd4 b 0x1cfb94 <_Z11HandleOtherv+0x1600> */
/* @0x1cffd8 vcvt.s32.f32 s10, s11 */
/* @0x1cffdc b 0x1cfb54 <_Z11HandleOtherv+0x15c0> */
/* @0x1cffe0 mov r0, r5 */
/* @0x1cffe4 mov r1, #1 */
/* @0x1cffe8 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cffec b 0x1cf390 <_Z11HandleOtherv+0xdfc> */
/* ── 尾调 CProfiler::Pop()（GOT 0x3EDB74 → 0x757E80）────────────── */
/* @0x1cfff0 ldr r3, [pc, #0xb4] —— r3 = -0x40E4 → 槽 0x3EDB74 = 0x757E80（g_Profiler） */
/* @0x1cfff4 ldr r12, [sp, #0x40] */
/* @0x1cfff8 ldr r0, [r12, r3] */
/* @0x1cfffc add sp, sp, #828 */
/* @0x1d0000 vpop {d8, d9, d10, d11} */
/* @0x1d0004 pop {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d0008 b 0x2a08ac <_ZN9CProfiler3PopEv> —— 尾调 CProfiler::Pop() */
/* ── 入口 profiler push：CProfiler::Push(0x757E80, 6, 10) 后回 1ce5c4 ── */
/* @0x1d000c ldr r3, [pc, #0x98] —— r3 = -0x40E4 → 槽 0x3EDB74 = 0x757E80 */
/* @0x1d0010 mov r1, #6 —— r1 = 6 */
/* @0x1d0014 mov r2, #10 —— r2 = 10（段号） */
/* @0x1d0018 ldr r0, [r12, r3] */
/* @0x1d001c bl 0x2a0738 <_ZN9CProfiler4PushEii> —— CProfiler::Push(g_Profiler, 6, 10) */
/* @0x1d0020 b 0x1ce5c4 <_Z11HandleOtherv+0x30> —— 回 1ce5c4 继续主流程 */
/* ── 短跳板群：vcvt.s32.f32 + b 回主流程（旋转角点选择用）─────────── */
/* @0x1d0024 vcvt.s32.f32 s7, s14 */
/* @0x1d0028 b 0x1ceabc <_Z11HandleOtherv+0x528> */
/* @0x1d002c vcvt.s32.f32 s13, s15 */
/* @0x1d0030 b 0x1ceb58 <_Z11HandleOtherv+0x5c4> */
/* @0x1d0034 vcvt.s32.f32 s7, s15 */
/* @0x1d0038 b 0x1ceaf0 <_Z11HandleOtherv+0x55c> */
/* @0x1d003c vcvt.s32.f32 s14, s14 */
/* @0x1d0040 b 0x1ceb24 <_Z11HandleOtherv+0x590> */
/* @0x1d0044 ldr r1, [pc, #0x64] —— count1==0 的快路径：r1 = -0x4328 → &Run_Room */
/* @0x1d0048 ldr r12, [sp, #0x40] */
/* @0x1d004c strd r2, r3, [sp, #8] */
/* @0x1d0050 ldr r3, [r12, r1] */
/* @0x1d0054 str r3, [sp, #0x3c] —— [sp+0x3c] = &Run_Room */
/* @0x1d0058 b 0x1ce784 <_Z11HandleOtherv+0x1f0> —— → 1ce784（第 2 趟） */
/* @0x1d005c vldr s15, [r9, #240] */
/* @0x1d0060 vldr s14, [r9, #232] */
/* @0x1d0064 b 0x1cf004 <_Z11HandleOtherv+0xa70> */
/* @0x1d0068 vldr s14, [r5, #232] */
/* @0x1d006c b 0x1cf580 <_Z11HandleOtherv+0xfec> */
/* @0x1d0070 vldr s13, [r5, #240] */
/* @0x1d0074 vldr s14, [r5, #232] */
/* @0x1d0078 b 0x1cf578 <_Z11HandleOtherv+0xfe4> */
/* @0x1d007c vldr s14, [r5, #232] */
/* @0x1d0080 vldr s15, [r5, #236] */
/* @0x1d0084 b 0x1cf570 <_Z11HandleOtherv+0xfdc> */
/* @0x1d0088 vldr s14, [r5, #232] */
/* @0x1d008c b 0x1cf58c <_Z11HandleOtherv+0xff8> */
/* @0x1d0090 vldr s15, [r5, #236] */
/* @0x1d0094 b 0x1cf55c <_Z11HandleOtherv+0xfc8> */
/* @0x1d0098 vldr s14, [r9, #232] */
/* @0x1d009c vldr s13, [r9, #236] */
/* @0x1d00a0 b 0x1ceffc <_Z11HandleOtherv+0xa68> */
/* @0x1d00a4 vldr s14, [r5, #232] */
/* @0x1d00a8 b 0x1cf564 <_Z11HandleOtherv+0xfd0> */
/* @0x1d00ac .word 0xffffbf1c —— 非指令：-0x40E4（g_Profiler） */
/* @0x1d00b0 .word 0xffffbcd8 —— 非指令：-0x4328（&Run_Room） */
