/* cally 逆向卡：CInstance::DeSerialise(IBuffer*, bool)（原版 libyoyo.so，armv7）
 * @func 0x19766c 0x197fac  size 2368  592 条（589 条指令 + 末 3 字 0x197fa0..0x197fa8 为 literal pool）
 * 级别: 正文（592/592 逐条落锚。54 个 IBuffer::Read 读点、54 次 YYGet* 拆值、52 个直接落点逐条解出
 *       ⇒ 流序即字段序；写侧 CInstance::Serialise 0x196bf4 的 54 个写点与本函数逐一对应。
 *       ⚠ 修正（batchAL，cards/CInstance_Serialise.c）：不对称共三处，不是一处 ——
 *         ① object_index 读侧走 SetObjectIndex、写侧直读 +0x7c；
 *         ② 写侧入口在 +0x64(bbox 脏) 非 0 时先 Compute_BoundingBox(true)；
 *         ③ 变量块个数写侧取全局 *(int*)0x544b48，读侧用 *(this+0x24) 当门。
 *       未钉：+0x144 / +0x148 / +0x0b0 三个槽位的语义名，以及 *(int*)0x544b48 计的是什么）
 * 符号: _ZN9CInstance11DeSerialiseEP7IBufferb → void CInstance::DeSerialise(IBuffer* buf, bool bRegister)
 * ABI : softfp；无返回值（三处出口都是直接 pop {..., pc}）；全函数不碰 VFP
 * 位置: CInstance::Serialise 0x196bf4 之后；YYObjectBase::InternalGetYYVarRef 0x197fac 之前
 *       （0x197fa0..0x197fa8 三个字是本函数的 literal pool，不是指令）
 * 调用点: 全图只有 CRoom::DeSerialise 0x1ac33c 两处 —— 0x1acd54（活动实例表）与 0x1ace48
 *         （非活动实例表），两处都把 CRoom::DeSerialise 的第 2 实参 bRegister 原样放进 r2
 * 同层: CInstance::Serialise 0x196bf4（严格互逆）、CInstance::Assign 0x1986ec、CInstance::C2 0x1994dc、
 *       RValue::DeSerialise 0xcf6e4、YYObjectBase::InternalGetYYVar 0x196a70、IBuffer::Read 0xcd304、
 *       IBuffer::SizeOf 0xcd100、YYGetInt32 0xce870 / YYGetBool 0xce768 / YYGetFloat 0xcec84 /
 *       YYGetUint32 0xce950、CInstance::SetObjectIndex 0x19324c
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   一条 CInstance 存档记录 = 54 个带类型码的标量（其中 alarm 是一个读点循环 12 次）
 *   + 1 个变量块（个数 n + n 个 RValue）。本函数按固定次序「从 IBuffer 读一项 → 用 YYGet* 拆成
 *   标量 → 写进 this 的某个偏移」，次序即格式：没有版本号、没有长度前缀、没有字段名，
 *   读错一个类型码后面全歪。唯一带副作用的读点是 object_index（第 3 项，走 SetObjectIndex）。
 *
 * ── 语义草案 ──────────────────────────────────────────────────────────────
 *   void CInstance::DeSerialise(IBuffer* buf, bool bRegister) {
 *     // 每次读都是 buf->Read(type, (RValue*)((char*)buf+0x2c))，再 YYGetXxx(槽, 0)
 *     this->id          = INT(6);                       // +0x078
 *     this->deactivated = BOOL(6);                      // +0x069
 *     SetObjectIndex(INT(6), bRegister && !this->deactivated);   // +0x07c/+0x080/+0x08c/+0x0ac/+0x180/标志
 *     this->sprite_index = INT(6);                      // +0x08c 直写，不经 SetSpriteIndex
 *     this->image_index  = FLOAT(8);                    // +0x090
 *     this->image_speed  = FLOAT(8);                    // +0x094
 *     this->image_xscale = FLOAT(8);                    // +0x098
 *     this->image_yscale = FLOAT(8);                    // +0x09c
 *     this->image_angle  = FLOAT(8);                    // +0x0a0
 *     this->image_alpha  = FLOAT(8);                    // +0x0a4
 *     this->image_blend  = UINT32(5);                   // +0x0a8（全函数唯一的类型码 5）
 *     this->mask_index   = INT(6);                      // +0x0ac 直写，不经 Set_MaskIndex
 *     this->depth        = FLOAT(8);                    // +0x180（float，不是 int）
 *     this->[0x0b0]      = BOOL(6);                     // 未定字段
 *     x, y, xstart, ystart, xprevious, yprevious, direction, speed, friction,
 *     gravity_direction, gravity, hspeed, vspeed = FLOAT(8) × 13;      // +0x0b4..+0x0e4
 *     this->[0x0e8] = INT(6); this->[0x0f0] = INT(6);
 *     this->[0x0ec] = INT(6); this->[0x0f4] = INT(6);    // 次序是 e8, f0, ec, f4
 *     visible=BOOL(6); solid=BOOL(6); persistent=BOOL(6);               // +0x065/0x066/0x067
 *     for (i = 0; i < 12; i++) this->alarm[i] = INT(6);  // +0x0f8..+0x124
 *     this->[0x068] = BOOL(6);                           // skip
 *     this->path_index = INT(6);                         // +0x128
 *     this->[0x12c] = FLOAT(8); this->[0x130] = FLOAT(8); this->[0x134] = FLOAT(8);
 *     this->[0x138] = FLOAT(8); this->[0x13c] = FLOAT(8); this->[0x140] = INT(6);
 *     this->[0x144] = FLOAT(8); this->[0x148] = FLOAT(8);
 *     this->[0x14c] = INT(6); this->[0x150] = FLOAT(8);
 *     this->[0x154] = FLOAT(8); this->[0x158] = FLOAT(8);
 *     this->[0x15c] = BOOL(6); this->[0x15d] = BOOL(6); this->[0x15e] = BOOL(6);
 *     this->[0x170] = INT(6);                            // layer
 *     if (*(int*)((char*)this + 0x24) == 0) return;      // 没有变量槽 ⇒ 流里也没有变量块
 *     n = INT(6);
 *     if (n != *(int*)0x544b48)                          // 不等只报警，不中断
 *        g_console->vtable[3]("WARNING! game_load variable mismatch - unpredictable results!");
 *     for (i = 0; i < n; i++) RValue::DeSerialise(VarSlot(i), buf);
 *   }
 *
 * ── IBuffer 读协议（54 个读点全同形）──────────────────────────────────────
 *   r0 = buf，r1 = 类型码，r2 = buf+0x2c（IBuffer 内嵌的 16 B RValue 暂存槽），blx [buf->vt+0x0c]
 *   随后 YYGetXxx(buf+0x2c, 0) 拆成标量再落盘；虚槽 +0x08 是写侧（Serialise 用），+0x0c 是读侧。
 *   类型码只有三种：6 = int（bool 也用它，序列化里没有独立 bool 码）、8 = float/real、5 = uint32。
 *   全函数复用同一个暂存槽 ⇒ 落盘必须在下一次读之前完成；编译器把「拆值」排在下一次「读」之后，
 *   逐条对锚点时别错拍（本卡在每条 blx 上标了「读第 N 项」，在每条 str/strb 上标了落点）。
 *   不走虚表的两个读：变量块里 n 次 RValue::DeSerialise（直调 0xcf6e4）、取变量槽用
 *   YYObjectBase::InternalGetYYVar（直调 0x196a70）。
 *
 * ── 流序总表（左 = 流里第几项 / 类型码 / 拆值结果；右 = 落点）────────────────
 *    1   6  int    → +0x078 id
 *    2   6  bool   → +0x069 deactivated
 *    3   6  int    → 实参进 SetObjectIndex（不直写 +0x07c）
 *    4   6  int    → +0x08c sprite_index
 *    5   8  float  → +0x090 image_index
 *    6   8  float  → +0x094 image_speed
 *    7   8  float  → +0x098 image_xscale
 *    8   8  float  → +0x09c image_yscale
 *    9   8  float  → +0x0a0 image_angle
 *   10   8  float  → +0x0a4 image_alpha
 *   11   5  uint32 → +0x0a8 image_blend
 *   12   6  int    → +0x0ac mask_index
 *   13   8  float  → +0x180 depth        ← 不按偏移顺序走：mask 之后直接跳 depth
 *   14   6  bool   → +0x0b0（未定）
 *   15   8  float  → +0x0b4 x
 *   16   8  float  → +0x0b8 y
 *   17   8  float  → +0x0bc xstart
 *   18   8  float  → +0x0c0 ystart
 *   19   8  float  → +0x0c4 xprevious
 *   20   8  float  → +0x0c8 yprevious
 *   21   8  float  → +0x0cc direction
 *   22   8  float  → +0x0d0 speed
 *   23   8  float  → +0x0d4 friction
 *   24   8  float  → +0x0d8 gravity_direction
 *   25   8  float  → +0x0dc gravity
 *   26   8  float  → +0x0e0 hspeed
 *   27   8  float  → +0x0e4 vspeed
 *   28   6  int    → +0x0e8（未定）
 *   29   6  int    → +0x0f0（未定）      ← 次序 f0 在 ec 之前
 *   30   6  int    → +0x0ec（未定）
 *   31   6  int    → +0x0f4（未定）
 *   32   6  bool   → +0x065 visible
 *   33   6  bool   → +0x066 solid
 *   34   6  bool   → +0x067 persistent
 *   35   6  int    → +0x0f8..+0x124 alarm[0..11]（一个读点，12 次循环）
 *   36   6  bool   → +0x068 skip
 *   37   6  int    → +0x128 path_index
 *   38   8  float  → +0x12c path_position
 *   39   8  float  → +0x130 path_positionprevious
 *   40   8  float  → +0x134 path_speed
 *   41   8  float  → +0x138 path_scale
 *   42   8  float  → +0x13c path_orientation
 *   43   6  int    → +0x140 path_endaction
 *   44   8  float  → +0x144（未定；ctor 不初始化、Assign 不复制）
 *   45   8  float  → +0x148（同上）
 *   46   6  int    → +0x14c timeline_index
 *   47   8  float  → +0x150（未定）
 *   48   8  float  → +0x154 timeline_position
 *   49   8  float  → +0x158 timeline_speed
 *   50   6  bool   → +0x15c timeline_running
 *   51   6  bool   → +0x15d timeline_loop
 *   52   6  bool   → +0x15e（未定）
 *   53   6  int    → +0x170 layer
 *   54   6  int    → n（变量个数；不落盘，只当循环上限 + 一致性检查）
 *   n × RValue::DeSerialise(buf) → 变量槽 i（+0x04 数组的第 i 个 16 B 项，或 InternalGetYYVar(this,i)）
 *
 * ── 不参与序列化的字段（ctor 字段表里有、本函数与 Serialise 都不碰）──────────
 *   +0x044 实例表槽号、+0x048、+0x060 变量名哈希表、+0x064（由 SetObjectIndex 间接置位）、
 *   +0x06a / +0x06b / +0x06c、+0x070/+0x074 ms_CurrentCreateCounter 快照、+0x084 CPhysicsObject*、
 *   +0x088 CSkeletonInstance*、+0x160、+0x164、+0x168、+0x16c、+0x174、+0x178/+0x17c 房间步进/绘制链、
 *   +0x184、+0x188..+0x1ac 碰撞/句柄三链，以及基类写区 +0x004..+0x060。
 *   ⇒ 读档后的实例：没有物理体、没有骨架实例、不在任何碰撞链上、没有实例表槽号（+0x044 待
 *     CRoom 侧另算），碰撞脏标记只靠第 3 项 SetObjectIndex 的尾调 CollisionMarkDirty 打一次
 *     （此时 x/y/depth 还没读进来，所以它只标脏、不重算）。
 *   ⇒ 反过来：本函数写的 64 个槽位与 ctor 的默认值表是同一批偏移，唯一例外是 +0x144/+0x148
 *     （ctor 从不写、本函数按 float 覆盖）和 +0x0b0（ctor 从不写、本函数按 bool 覆盖）。
 *   ⇒ +0x160/+0x164 特别记一笔：ctor 置 0、Assign 会逐字抄、但**写侧 Serialise 与本函数都不碰**
 *     ⇒ 走 CRoom::DeSerialise 的「new + DeSerialise」路径读档后恒为 0；若是就地 DeSerialise，
 *     则保留调用前的旧值。ctor 卡里「+0x160/+0x164 由 Assign/Serialise 处理」的后半句不成立
 *     （Serialise 0x196bf4 里没有对这两个偏移的读写，已逐指令核过）。
 *
 * ── 已证（指令级）────────────────────────────────────────────────────────
 *  1. 54 个读点 ↔ 写侧 54 个写点：本函数 blx [vt+0x0c] 共 55 次，其中 54 次是 IBuffer::Read、
 *     1 次是变量块末尾对全局控制台的虚调用；拆值 54 次 = 30 float + 14 int32 + 9 bool + 1 uint32。
 *     Serialise 0x196bf4 的 blx [vt+0x08] 也是 54 次，次序与落点逐一对应。
 *  2. 类型码 = eBuffer_Type（IBuffer::Read 0xcd304 / SizeOf 0xcd100 的 r1）：6/8/5 三种，bool 用 6。
 *  3. object_index 的第二实参 = bRegister && !deactivated：0x1976f8 ldrb r2,[r6,#0x69] →
 *     0x1976fc cmp r2,#0 → 0x197700 moveq r2,r7（r7 = bRegister）→ 0x197704 movne r2,#0
 *     → 0x197714 bl SetObjectIndex。⇒ 非活动实例即使 bRegister=true 也不会挂进对象的实例链，
 *     而 +0x69 是第 2 项刚写进去的**新值**，不是旧值。
 *  4. alarm 是单读点 12 次循环：r7=12（0x197708），循环头 0x197bf0，r8 从 this 起每轮 +4，
 *     落点 [r8+0xf4] ⇒ 首轮 0x0f8、末轮 0x124。
 *  5. 变量块：0x197ef0 先看 *(int*)(this+0x24)（基类变量槽计数），为 0 就直接 pop 返回，
 *     **连 n 都不读**；否则读 n，再与 *(int*)0x544b48 比较（GOT 0x3EDD1C → 0x544b48，
 *     同一个全局被基类构造当第 1 实参），不等则取 GOT 0x3ED71C → 0x3EB70C 的全局对象，
 *     走它的 vtable[3] 打一条 0x34CCE0 = "WARNING! game_load variable mismatch - unpredictable
 *     results!"。相等不打印、不等也不中断。
 *  6. 变量槽寻址二选一：*(int**)(this+0x04) 非 0 → RValue* = base + i*16（`add r0,r3,r5,lsl #4`）；
 *     为 0 → YYObjectBase::InternalGetYYVar(this, i) 的返回值（0x197f90..0x197f98），
 *     随后同样落进 RValue::DeSerialise(buf)。
 *  7. 三处出口都是 pop/无返回值：0x197efc popeq（变量槽计数为 0）、0x197f60 pople（n == 0）、
 *     0x197f8c pop（循环走完）。全函数只有 5 条分支指令（bne×2 / beq×2 / b×1）。
 *  8. sprite_index(+0x8c) 与 mask_index(+0xac) 是直写，不经 SetSpriteIndex 0x1931c0 /
 *     Set_MaskIndex 0x192ba8 ⇒ 流里的精灵号/掩码号不做存在性校验，写成什么就是什么；
 *     只有 object_index 走 SetObjectIndex，会连带写 +0x080/+0x064/+0x065..0x067/+0x08c/
 *     +0x0ac/+0x180 并尾调 CollisionMarkDirty。
 *  9. 落盘顺序里有三处「非升序」是**格式的一部分**，不能当编译噪声：mask(0xac) 之后跳 depth(0x180)
 *     再回 +0x0b0/+0xb4；0xf0 在 0xec 之前；0x144/0x148 夹在 path_endaction 与 timeline_index 之间。
 * 10. 全函数 bl 57 条（7 个目标）+ blx 55 条，无 blx 到别处、无异常表引用；不碰 VFP。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. +0x0b0（第 14 项，bool）：ctor 从不写（new 清零后恒 0），只有本函数与 Serialise 过一遍。
 *  2. +0x144/+0x148：本函数与 Serialise 都按 **float** 读写，但 ctor 不初始化、Assign 不复制 ⇒
 *     只能由存档流或本文件之外的代码写。ctor 卡里「疑似 CPath*/CTimeline*」的猜测据此否掉
 *     （不可能是指针：这里做的是 float 存取，Serialise 侧还走 vcvt.f64.f32）。
 *  3. *(int*)0x544b48 计的是什么（基类构造的第 1 实参同源）；本函数只拿它跟 n 比，用途未证。
 *  4. 变量块不扩容、不校验 i 越界：n 大于现有槽容量时后面 n 步会写过界（是否被上层限制未证）。
 *  5. 本函数只按**索引**恢复变量槽，完全不碰 +0x060 的名称哈希表。若表里存的是指向这些槽的
 *     指针，就地覆盖即自洽；若存的是独立 RValue，则按名查询看不到新值。哪一种未证。
 *  6. bRegister=false 时谁负责把实例挂进对象实例链（CRoom::DeSerialise 的调用点只传标志，
 *     挂链在 CRoom 侧另做）。
 *
 * ── 逐条锚点（地址/字/mnemonic/operands 全部来自 asm/index-CInstance_DeSerialise.tsv）────
 */


/* ── 0. 入口：r0=this、r1=buf、r2=bRegister；r5 = buf+0x2c（内嵌 RValue 暂存槽）、
 *    r4=buf、r6=this、r7=bRegister、r8=this（后当 alarm 游标）。第一条指令就在 push 之前
 *    把 buf 的虚表取出来 —— 读点的形态是 `ldr r3,[r4]; ldr r3,[r3,#0xc]; blx r3`。── */
/* @0x19766c ldr r3, [r1] */   —— buf->vtable
/* @0x197670 push {r4, r5, r6, r7, r8, lr} */
/* @0x197674 add r5, r1, #44 */   —— r5 = buf+0x2c = 内嵌 RValue 暂存槽（16 B）
/* @0x197678 mov r4, r1 */
/* @0x19767c mov r6, r0 */
/* @0x197680 mov r7, r2 */
/* @0x197684 ldr r3, [r3, #0xc] */   —— vtable[+0x0c] = IBuffer::Read(eBuffer_Type, RValue*)
/* @0x197688 mov r2, r5 */
/* @0x19768c mov r0, r1 */
/* @0x197690 mov r1, #6 */
/* @0x197694 mov r8, r6 */
/* @0x197698 blx r3 */   —— 读第 1 项（类型码 6）；r0=buf r1=6 r2=&槽

/* ── 1. 第 1 项：id（类型码 6 → YYGetInt32 → +0x078）──────────────────────── */
/* @0x19769c mov r1, #0 */
/* @0x1976a0 mov r0, r5 */
/* @0x1976a4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */   —— 拆值：YYGetInt32(&槽, 0)
/* @0x1976a8 ldr r3, [r4] */
/* @0x1976ac mov r2, r5 */
/* @0x1976b0 mov r1, #6 */
/* @0x1976b4 ldr r3, [r3, #0xc] */
/* @0x1976b8 str r0, [r6, #0x78] */   —— +0x078 id

/* ── 2. 第 2 项：deactivated（类型码 6 → YYGetBool → +0x069 字节）───────── */
/* @0x1976bc mov r0, r4 */
/* @0x1976c0 blx r3 */   —— 读第 2 项（6）
/* @0x1976c4 mov r1, #0 */
/* @0x1976c8 mov r0, r5 */
/* @0x1976cc bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1976d0 ldr r3, [r4] */
/* @0x1976d4 mov r2, r5 */
/* @0x1976d8 mov r1, #6 */
/* @0x1976dc ldr r3, [r3, #0xc] */
/* @0x1976e0 strb r0, [r6, #0x69] */   —— +0x069 deactivated（字节）

/* ── 3. 第 3 项：object_index —— 唯一带副作用的读点 ───────────────────────
 *    读进来先不落盘：r2 = (deactivated ? 0 : bRegister)，再 bl SetObjectIndex(objindex, r2)。
 *    所以 +0x07c/+0x080/+0x08c/+0x0ac/+0x180/标志位这一串由 SetObjectIndex 写，不在这里。── */
/* @0x1976e4 mov r0, r4 */
/* @0x1976e8 blx r3 */   —— 读第 3 项（6）= object_index
/* @0x1976ec mov r1, #0 */
/* @0x1976f0 mov r0, r5 */
/* @0x1976f4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x1976f8 ldrb r2, [r6, #0x69] */   —— 取刚写入的 deactivated（第 2 项的新值）
/* @0x1976fc cmp r2, #0 */
/* @0x197700 moveq r2, r7 */   —— deactivated==0 → r2 = bRegister
/* @0x197704 movne r2, #0 */   —— deactivated!=0 → r2 = 0
/* @0x197708 mov r7, #12 */   —— r7 = 12（alarm 循环计数）
/* @0x19770c mov r1, r0 */
/* @0x197710 mov r0, r6 */
/* @0x197714 bl 0x19324c <_ZN9CInstance14SetObjectIndexEib> */   —— SetObjectIndex(object_index, bRegister && !deactivated)

/* ── 4. 第 4 项：sprite_index（直写 +0x08c，不经 SetSpriteIndex）──────────── */
/* @0x197718 ldr r3, [r4] */
/* @0x19771c mov r2, r5 */
/* @0x197720 mov r1, #6 */
/* @0x197724 mov r0, r4 */
/* @0x197728 ldr r3, [r3, #0xc] */
/* @0x19772c blx r3 */   —— 读第 4 项（6）
/* @0x197730 mov r1, #0 */
/* @0x197734 mov r0, r5 */
/* @0x197738 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x19773c ldr r3, [r4] */
/* @0x197740 mov r2, r5 */
/* @0x197744 mov r1, #8 */
/* @0x197748 ldr r3, [r3, #0xc] */
/* @0x19774c str r0, [r6, #0x8c] */   —— +0x08c sprite_index

/* ── 5..10. 图像组 6 项（全 float）：image_index/speed/xscale/yscale/angle/alpha ── */
/* @0x197750 mov r0, r4 */
/* @0x197754 blx r3 */   —— 读第 5 项（8）
/* @0x197758 mov r1, #0 */
/* @0x19775c mov r0, r5 */
/* @0x197760 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197764 ldr r3, [r4] */
/* @0x197768 mov r2, r5 */
/* @0x19776c mov r1, #8 */
/* @0x197770 ldr r3, [r3, #0xc] */
/* @0x197774 str r0, [r6, #0x90] */   —— +0x090 image_index
/* @0x197778 mov r0, r4 */
/* @0x19777c blx r3 */   —— 读第 6 项（8）
/* @0x197780 mov r1, #0 */
/* @0x197784 mov r0, r5 */
/* @0x197788 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19778c ldr r3, [r4] */
/* @0x197790 mov r2, r5 */
/* @0x197794 mov r1, #8 */
/* @0x197798 ldr r3, [r3, #0xc] */
/* @0x19779c str r0, [r6, #0x94] */   —— +0x094 image_speed
/* @0x1977a0 mov r0, r4 */
/* @0x1977a4 blx r3 */   —— 读第 7 项（8）
/* @0x1977a8 mov r1, #0 */
/* @0x1977ac mov r0, r5 */
/* @0x1977b0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1977b4 ldr r3, [r4] */
/* @0x1977b8 mov r2, r5 */
/* @0x1977bc mov r1, #8 */
/* @0x1977c0 ldr r3, [r3, #0xc] */
/* @0x1977c4 str r0, [r6, #0x98] */   —— +0x098 image_xscale
/* @0x1977c8 mov r0, r4 */
/* @0x1977cc blx r3 */   —— 读第 8 项（8）
/* @0x1977d0 mov r1, #0 */
/* @0x1977d4 mov r0, r5 */
/* @0x1977d8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1977dc ldr r3, [r4] */
/* @0x1977e0 mov r2, r5 */
/* @0x1977e4 mov r1, #8 */
/* @0x1977e8 ldr r3, [r3, #0xc] */
/* @0x1977ec str r0, [r6, #0x9c] */   —— +0x09c image_yscale
/* @0x1977f0 mov r0, r4 */
/* @0x1977f4 blx r3 */   —— 读第 9 项（8）
/* @0x1977f8 mov r1, #0 */
/* @0x1977fc mov r0, r5 */
/* @0x197800 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197804 ldr r3, [r4] */
/* @0x197808 mov r2, r5 */
/* @0x19780c mov r1, #8 */
/* @0x197810 ldr r3, [r3, #0xc] */
/* @0x197814 str r0, [r6, #0xa0] */   —— +0x0a0 image_angle
/* @0x197818 mov r0, r4 */
/* @0x19781c blx r3 */   —— 读第 10 项（8）
/* @0x197820 mov r1, #0 */
/* @0x197824 mov r0, r5 */
/* @0x197828 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19782c ldr r3, [r4] */
/* @0x197830 mov r2, r5 */
/* @0x197834 mov r1, #5 */
/* @0x197838 ldr r3, [r3, #0xc] */
/* @0x19783c str r0, [r6, #0xa4] */   —— +0x0a4 image_alpha

/* ── 11. image_blend：全函数唯一的类型码 5（uint32）→ YYGetUint32 ─────────── */
/* @0x197840 mov r0, r4 */
/* @0x197844 blx r3 */   —— 读第 11 项（5 = uint32）
/* @0x197848 mov r1, #0 */
/* @0x19784c mov r0, r5 */
/* @0x197850 bl 0xce950 <_Z11YYGetUint32PK6RValuei> */
/* @0x197854 ldr r3, [r4] */
/* @0x197858 mov r2, r5 */
/* @0x19785c mov r1, #6 */
/* @0x197860 ldr r3, [r3, #0xc] */
/* @0x197864 str r0, [r6, #0xa8] */   —— +0x0a8 image_blend

/* ── 12. mask_index（int → +0x0ac 直写，不经 Set_MaskIndex）─────────────── */
/* @0x197868 mov r0, r4 */
/* @0x19786c blx r3 */   —— 读第 12 项（6）
/* @0x197870 mov r1, #0 */
/* @0x197874 mov r0, r5 */
/* @0x197878 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x19787c ldr r3, [r4] */
/* @0x197880 mov r2, r5 */
/* @0x197884 mov r1, #8 */
/* @0x197888 ldr r3, [r3, #0xc] */
/* @0x19788c str r0, [r6, #0xac] */   —— +0x0ac mask_index

/* ── 13. depth（float → +0x180）—— 注意不走偏移序：mask 之后直接跳 depth ──── */
/* @0x197890 mov r0, r4 */
/* @0x197894 blx r3 */   —— 读第 13 项（8）
/* @0x197898 mov r1, #0 */
/* @0x19789c mov r0, r5 */
/* @0x1978a0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1978a4 ldr r3, [r4] */
/* @0x1978a8 mov r2, r5 */
/* @0x1978ac mov r1, #6 */
/* @0x1978b0 ldr r3, [r3, #0xc] */
/* @0x1978b4 str r0, [r6, #0x180] */   —— +0x180 depth（float 位型）

/* ── 14. +0x0b0（bool；ctor 从不初始化，语义未定）──────────────────────── */
/* @0x1978b8 mov r0, r4 */
/* @0x1978bc blx r3 */   —— 读第 14 项（6，bool）
/* @0x1978c0 mov r1, #0 */
/* @0x1978c4 mov r0, r5 */
/* @0x1978c8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x1978cc ldr r3, [r4] */
/* @0x1978d0 mov r2, r5 */
/* @0x1978d4 mov r1, #8 */
/* @0x1978d8 ldr r3, [r3, #0xc] */
/* @0x1978dc strb r0, [r6, #0xb0] */   —— +0x0b0（字节，语义未定）

/* ── 15..27. 位置/运动学 13 项（全 float）：x y xstart ystart xprevious yprevious
 *    direction speed friction gravity_direction gravity hspeed vspeed ─────────── */
/* @0x1978e0 mov r0, r4 */
/* @0x1978e4 blx r3 */   —— 读第 15 项（8）
/* @0x1978e8 mov r1, #0 */
/* @0x1978ec mov r0, r5 */
/* @0x1978f0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1978f4 ldr r3, [r4] */
/* @0x1978f8 mov r2, r5 */
/* @0x1978fc mov r1, #8 */
/* @0x197900 ldr r3, [r3, #0xc] */
/* @0x197904 str r0, [r6, #0xb4] */   —— +0x0b4 x
/* @0x197908 mov r0, r4 */
/* @0x19790c blx r3 */   —— 读第 16 项（8）
/* @0x197910 mov r1, #0 */
/* @0x197914 mov r0, r5 */
/* @0x197918 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19791c ldr r3, [r4] */
/* @0x197920 mov r2, r5 */
/* @0x197924 mov r1, #8 */
/* @0x197928 ldr r3, [r3, #0xc] */
/* @0x19792c str r0, [r6, #0xb8] */   —— +0x0b8 y
/* @0x197930 mov r0, r4 */
/* @0x197934 blx r3 */   —— 读第 17 项（8）
/* @0x197938 mov r1, #0 */
/* @0x19793c mov r0, r5 */
/* @0x197940 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197944 ldr r3, [r4] */
/* @0x197948 mov r2, r5 */
/* @0x19794c mov r1, #8 */
/* @0x197950 ldr r3, [r3, #0xc] */
/* @0x197954 str r0, [r6, #0xbc] */   —— +0x0bc xstart
/* @0x197958 mov r0, r4 */
/* @0x19795c blx r3 */   —— 读第 18 项（8）
/* @0x197960 mov r1, #0 */
/* @0x197964 mov r0, r5 */
/* @0x197968 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x19796c ldr r3, [r4] */
/* @0x197970 mov r2, r5 */
/* @0x197974 mov r1, #8 */
/* @0x197978 ldr r3, [r3, #0xc] */
/* @0x19797c str r0, [r6, #0xc0] */   —— +0x0c0 ystart
/* @0x197980 mov r0, r4 */
/* @0x197984 blx r3 */   —— 读第 19 项（8）
/* @0x197988 mov r1, #0 */
/* @0x19798c mov r0, r5 */
/* @0x197990 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197994 ldr r3, [r4] */
/* @0x197998 mov r2, r5 */
/* @0x19799c mov r1, #8 */
/* @0x1979a0 ldr r3, [r3, #0xc] */
/* @0x1979a4 str r0, [r6, #0xc4] */   —— +0x0c4 xprevious
/* @0x1979a8 mov r0, r4 */
/* @0x1979ac blx r3 */   —— 读第 20 项（8）
/* @0x1979b0 mov r1, #0 */
/* @0x1979b4 mov r0, r5 */
/* @0x1979b8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1979bc ldr r3, [r4] */
/* @0x1979c0 mov r2, r5 */
/* @0x1979c4 mov r1, #8 */
/* @0x1979c8 ldr r3, [r3, #0xc] */
/* @0x1979cc str r0, [r6, #0xc8] */   —— +0x0c8 yprevious
/* @0x1979d0 mov r0, r4 */
/* @0x1979d4 blx r3 */   —— 读第 21 项（8）
/* @0x1979d8 mov r1, #0 */
/* @0x1979dc mov r0, r5 */
/* @0x1979e0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x1979e4 ldr r3, [r4] */
/* @0x1979e8 mov r2, r5 */
/* @0x1979ec mov r1, #8 */
/* @0x1979f0 ldr r3, [r3, #0xc] */
/* @0x1979f4 str r0, [r6, #0xcc] */   —— +0x0cc direction
/* @0x1979f8 mov r0, r4 */
/* @0x1979fc blx r3 */   —— 读第 22 项（8）
/* @0x197a00 mov r1, #0 */
/* @0x197a04 mov r0, r5 */
/* @0x197a08 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a0c ldr r3, [r4] */
/* @0x197a10 mov r2, r5 */
/* @0x197a14 mov r1, #8 */
/* @0x197a18 ldr r3, [r3, #0xc] */
/* @0x197a1c str r0, [r6, #0xd0] */   —— +0x0d0 speed
/* @0x197a20 mov r0, r4 */
/* @0x197a24 blx r3 */   —— 读第 23 项（8）
/* @0x197a28 mov r1, #0 */
/* @0x197a2c mov r0, r5 */
/* @0x197a30 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a34 ldr r3, [r4] */
/* @0x197a38 mov r2, r5 */
/* @0x197a3c mov r1, #8 */
/* @0x197a40 ldr r3, [r3, #0xc] */
/* @0x197a44 str r0, [r6, #0xd4] */   —— +0x0d4 friction
/* @0x197a48 mov r0, r4 */
/* @0x197a4c blx r3 */   —— 读第 24 项（8）
/* @0x197a50 mov r1, #0 */
/* @0x197a54 mov r0, r5 */
/* @0x197a58 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a5c ldr r3, [r4] */
/* @0x197a60 mov r2, r5 */
/* @0x197a64 mov r1, #8 */
/* @0x197a68 ldr r3, [r3, #0xc] */
/* @0x197a6c str r0, [r6, #0xd8] */   —— +0x0d8 gravity_direction
/* @0x197a70 mov r0, r4 */
/* @0x197a74 blx r3 */   —— 读第 25 项（8）
/* @0x197a78 mov r1, #0 */
/* @0x197a7c mov r0, r5 */
/* @0x197a80 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197a84 ldr r3, [r4] */
/* @0x197a88 mov r2, r5 */
/* @0x197a8c mov r1, #8 */
/* @0x197a90 ldr r3, [r3, #0xc] */
/* @0x197a94 str r0, [r6, #0xdc] */   —— +0x0dc gravity
/* @0x197a98 mov r0, r4 */
/* @0x197a9c blx r3 */   —— 读第 26 项（8）
/* @0x197aa0 mov r1, #0 */
/* @0x197aa4 mov r0, r5 */
/* @0x197aa8 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197aac ldr r3, [r4] */
/* @0x197ab0 mov r2, r5 */
/* @0x197ab4 mov r1, #8 */
/* @0x197ab8 ldr r3, [r3, #0xc] */
/* @0x197abc str r0, [r6, #0xe0] */   —— +0x0e0 hspeed
/* @0x197ac0 mov r0, r4 */
/* @0x197ac4 blx r3 */   —— 读第 27 项（8）
/* @0x197ac8 mov r1, #0 */
/* @0x197acc mov r0, r5 */
/* @0x197ad0 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197ad4 ldr r3, [r4] */
/* @0x197ad8 mov r2, r5 */
/* @0x197adc mov r1, #6 */
/* @0x197ae0 ldr r3, [r3, #0xc] */
/* @0x197ae4 str r0, [r6, #0xe4] */   —— +0x0e4 vspeed

/* ── 28..31. +0x0e8 / +0x0f0 / +0x0ec / +0x0f4（四个 int，次序不是升序）───── */
/* @0x197ae8 mov r0, r4 */
/* @0x197aec blx r3 */   —— 读第 28 项（6）
/* @0x197af0 mov r1, #0 */
/* @0x197af4 mov r0, r5 */
/* @0x197af8 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197afc ldr r3, [r4] */
/* @0x197b00 mov r2, r5 */
/* @0x197b04 mov r1, #6 */
/* @0x197b08 ldr r3, [r3, #0xc] */
/* @0x197b0c str r0, [r6, #0xe8] */   —— +0x0e8（未定）
/* @0x197b10 mov r0, r4 */
/* @0x197b14 blx r3 */   —— 读第 29 项（6）
/* @0x197b18 mov r1, #0 */
/* @0x197b1c mov r0, r5 */
/* @0x197b20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b24 ldr r3, [r4] */
/* @0x197b28 mov r2, r5 */
/* @0x197b2c mov r1, #6 */
/* @0x197b30 ldr r3, [r3, #0xc] */
/* @0x197b34 str r0, [r6, #0xf0] */   —— +0x0f0（未定）
/* @0x197b38 mov r0, r4 */
/* @0x197b3c blx r3 */   —— 读第 30 项（6）
/* @0x197b40 mov r1, #0 */
/* @0x197b44 mov r0, r5 */
/* @0x197b48 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b4c ldr r3, [r4] */
/* @0x197b50 mov r2, r5 */
/* @0x197b54 mov r1, #6 */
/* @0x197b58 ldr r3, [r3, #0xc] */
/* @0x197b5c str r0, [r6, #0xec] */   —— +0x0ec（未定）
/* @0x197b60 mov r0, r4 */
/* @0x197b64 blx r3 */   —— 读第 31 项（6）

/* ── 32..34. visible / solid / persistent（三个字节）─────────────────────── */
/* @0x197b68 mov r1, #0 */
/* @0x197b6c mov r0, r5 */
/* @0x197b70 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197b74 ldr r3, [r4] */
/* @0x197b78 mov r2, r5 */
/* @0x197b7c mov r1, #6 */
/* @0x197b80 ldr r3, [r3, #0xc] */
/* @0x197b84 str r0, [r6, #0xf4] */   —— +0x0f4（未定）
/* @0x197b88 mov r0, r4 */
/* @0x197b8c blx r3 */   —— 读第 32 项（6，bool）
/* @0x197b90 mov r1, #0 */
/* @0x197b94 mov r0, r5 */
/* @0x197b98 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197b9c ldr r3, [r4] */
/* @0x197ba0 mov r2, r5 */
/* @0x197ba4 mov r1, #6 */
/* @0x197ba8 ldr r3, [r3, #0xc] */
/* @0x197bac strb r0, [r6, #0x65] */   —— +0x065 visible
/* @0x197bb0 mov r0, r4 */
/* @0x197bb4 blx r3 */   —— 读第 33 项（6，bool）
/* @0x197bb8 mov r1, #0 */
/* @0x197bbc mov r0, r5 */
/* @0x197bc0 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197bc4 ldr r3, [r4] */
/* @0x197bc8 mov r2, r5 */
/* @0x197bcc mov r1, #6 */
/* @0x197bd0 ldr r3, [r3, #0xc] */
/* @0x197bd4 strb r0, [r6, #0x66] */   —— +0x066 solid
/* @0x197bd8 mov r0, r4 */
/* @0x197bdc blx r3 */   —— 读第 34 项（6，bool）
/* @0x197be0 mov r0, r5 */
/* @0x197be4 mov r1, #0 */
/* @0x197be8 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197bec strb r0, [r6, #0x67] */   —— +0x067 persistent

/* ── 35. alarm[0..11]：单读点 12 次循环 ────────────────────────────────
 *    循环头 0x197bf0；r7 初值 12（0x197708），每轮 subs 后存；r8 从 this 起每轮 +4，
 *    `str r0,[r8,#0xf4]` 在 +4 之后执行 ⇒ 落点 0x0f8,0x0fc,...,0x124。── */
/* @0x197bf0 ldr r3, [r4] */
/* @0x197bf4 mov r1, #6 */
/* @0x197bf8 mov r2, r5 */
/* @0x197bfc mov r0, r4 */
/* @0x197c00 add r8, r8, #4 */
/* @0x197c04 ldr r3, [r3, #0xc] */
/* @0x197c08 blx r3 */   —— 读第 35 项（6）×12（循环体）
/* @0x197c0c mov r0, r5 */
/* @0x197c10 mov r1, #0 */
/* @0x197c14 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197c18 subs r7, r7, #1 */   —— 循环计数 -1（共 12 轮）
/* @0x197c1c str r0, [r8, #0xf4] */   —— alarm[i] ← [r8+0xf4]，r8 = this+4(i+1) ⇒ 0x0f8..0x124
/* @0x197c20 bne 0x197bf0 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x584> */   —— 回到 0x197bf0（alarm 循环头）

/* ── 36. skip（bool → +0x068 字节）─────────────────────────────────────── */
/* @0x197c24 ldr r3, [r4] */
/* @0x197c28 mov r2, r5 */
/* @0x197c2c mov r1, #6 */
/* @0x197c30 mov r0, r4 */
/* @0x197c34 ldr r3, [r3, #0xc] */
/* @0x197c38 blx r3 */   —— 读第 36 项（6，bool）
/* @0x197c3c mov r1, r7 */
/* @0x197c40 mov r0, r5 */
/* @0x197c44 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197c48 ldr r3, [r4] */
/* @0x197c4c mov r2, r5 */
/* @0x197c50 mov r1, #6 */
/* @0x197c54 ldr r3, [r3, #0xc] */
/* @0x197c58 strb r0, [r6, #0x68] */   —— +0x068 skip（字节）

/* ── 37..43. 路径组：path_index(int) + 5 float + path_endaction(int) ─────── */
/* @0x197c5c mov r0, r4 */
/* @0x197c60 blx r3 */   —— 读第 37 项（6）
/* @0x197c64 mov r1, r7 */
/* @0x197c68 mov r0, r5 */
/* @0x197c6c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197c70 ldr r3, [r4] */
/* @0x197c74 mov r2, r5 */
/* @0x197c78 mov r1, #8 */
/* @0x197c7c ldr r3, [r3, #0xc] */
/* @0x197c80 str r0, [r6, #0x128] */   —— +0x128 path_index
/* @0x197c84 mov r0, r4 */
/* @0x197c88 blx r3 */   —— 读第 38 项（8）
/* @0x197c8c mov r1, r7 */
/* @0x197c90 mov r0, r5 */
/* @0x197c94 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197c98 ldr r3, [r4] */
/* @0x197c9c mov r2, r5 */
/* @0x197ca0 mov r1, #8 */
/* @0x197ca4 ldr r3, [r3, #0xc] */
/* @0x197ca8 str r0, [r6, #0x12c] */   —— +0x12c path_position
/* @0x197cac mov r0, r4 */
/* @0x197cb0 blx r3 */   —— 读第 39 项（8）
/* @0x197cb4 mov r1, r7 */
/* @0x197cb8 mov r0, r5 */
/* @0x197cbc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197cc0 ldr r3, [r4] */
/* @0x197cc4 mov r2, r5 */
/* @0x197cc8 mov r1, #8 */
/* @0x197ccc ldr r3, [r3, #0xc] */
/* @0x197cd0 str r0, [r6, #0x130] */   —— +0x130 path_positionprevious
/* @0x197cd4 mov r0, r4 */
/* @0x197cd8 blx r3 */   —— 读第 40 项（8）
/* @0x197cdc mov r1, r7 */
/* @0x197ce0 mov r0, r5 */
/* @0x197ce4 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197ce8 ldr r3, [r4] */
/* @0x197cec mov r2, r5 */
/* @0x197cf0 mov r1, #8 */
/* @0x197cf4 ldr r3, [r3, #0xc] */
/* @0x197cf8 str r0, [r6, #0x134] */   —— +0x134 path_speed
/* @0x197cfc mov r0, r4 */
/* @0x197d00 blx r3 */   —— 读第 41 项（8）
/* @0x197d04 mov r1, r7 */
/* @0x197d08 mov r0, r5 */
/* @0x197d0c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d10 ldr r3, [r4] */
/* @0x197d14 mov r2, r5 */
/* @0x197d18 mov r1, #8 */
/* @0x197d1c ldr r3, [r3, #0xc] */
/* @0x197d20 str r0, [r6, #0x138] */   —— +0x138 path_scale
/* @0x197d24 mov r0, r4 */
/* @0x197d28 blx r3 */   —— 读第 42 项（8）
/* @0x197d2c mov r1, r7 */
/* @0x197d30 mov r0, r5 */
/* @0x197d34 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d38 ldr r3, [r4] */
/* @0x197d3c mov r2, r5 */
/* @0x197d40 mov r1, #6 */
/* @0x197d44 ldr r3, [r3, #0xc] */
/* @0x197d48 str r0, [r6, #0x13c] */   —— +0x13c path_orientation
/* @0x197d4c mov r0, r4 */
/* @0x197d50 blx r3 */   —— 读第 43 项（6）
/* @0x197d54 mov r1, r7 */
/* @0x197d58 mov r0, r5 */
/* @0x197d5c bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197d60 ldr r3, [r4] */
/* @0x197d64 mov r2, r5 */
/* @0x197d68 mov r1, #8 */
/* @0x197d6c ldr r3, [r3, #0xc] */
/* @0x197d70 str r0, [r6, #0x140] */   —— +0x140 path_endaction

/* ── 44..49. +0x144 / +0x148（float，未定）+ 时间线组 ────────────────────── */
/* @0x197d74 mov r0, r4 */
/* @0x197d78 blx r3 */   —— 读第 44 项（8）
/* @0x197d7c mov r1, r7 */
/* @0x197d80 mov r0, r5 */
/* @0x197d84 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197d88 ldr r3, [r4] */
/* @0x197d8c mov r2, r5 */
/* @0x197d90 mov r1, #8 */
/* @0x197d94 ldr r3, [r3, #0xc] */
/* @0x197d98 str r0, [r6, #0x144] */   —— +0x144（float，未定）
/* @0x197d9c mov r0, r4 */
/* @0x197da0 blx r3 */   —— 读第 45 项（8）
/* @0x197da4 mov r1, r7 */
/* @0x197da8 mov r0, r5 */
/* @0x197dac bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197db0 ldr r3, [r4] */
/* @0x197db4 mov r2, r5 */
/* @0x197db8 mov r1, #6 */
/* @0x197dbc ldr r3, [r3, #0xc] */
/* @0x197dc0 str r0, [r6, #0x148] */   —— +0x148（float，未定）
/* @0x197dc4 mov r0, r4 */
/* @0x197dc8 blx r3 */   —— 读第 46 项（6）
/* @0x197dcc mov r1, r7 */
/* @0x197dd0 mov r0, r5 */
/* @0x197dd4 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197dd8 ldr r3, [r4] */
/* @0x197ddc mov r2, r5 */
/* @0x197de0 mov r1, #8 */
/* @0x197de4 ldr r3, [r3, #0xc] */
/* @0x197de8 str r0, [r6, #0x14c] */   —— +0x14c timeline_index
/* @0x197dec mov r0, r4 */
/* @0x197df0 blx r3 */   —— 读第 47 项（8）
/* @0x197df4 mov r1, r7 */
/* @0x197df8 mov r0, r5 */
/* @0x197dfc bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e00 ldr r3, [r4] */
/* @0x197e04 mov r2, r5 */
/* @0x197e08 mov r1, #8 */
/* @0x197e0c ldr r3, [r3, #0xc] */
/* @0x197e10 str r0, [r6, #0x150] */   —— +0x150（float，未定）
/* @0x197e14 mov r0, r4 */
/* @0x197e18 blx r3 */   —— 读第 48 项（8）
/* @0x197e1c mov r1, r7 */
/* @0x197e20 mov r0, r5 */
/* @0x197e24 bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e28 ldr r3, [r4] */
/* @0x197e2c mov r2, r5 */
/* @0x197e30 mov r1, #8 */
/* @0x197e34 ldr r3, [r3, #0xc] */
/* @0x197e38 str r0, [r6, #0x154] */   —— +0x154 timeline_position
/* @0x197e3c mov r0, r4 */
/* @0x197e40 blx r3 */   —— 读第 49 项（8）
/* @0x197e44 mov r1, r7 */

/* ── 50..52. timeline_running / timeline_loop / +0x15e（三个字节）──────────── */
/* @0x197e48 mov r0, r5 */
/* @0x197e4c bl 0xcec84 <_Z10YYGetFloatPK6RValuei> */
/* @0x197e50 ldr r3, [r4] */
/* @0x197e54 mov r2, r5 */
/* @0x197e58 mov r1, #6 */
/* @0x197e5c ldr r3, [r3, #0xc] */
/* @0x197e60 str r0, [r6, #0x158] */   —— +0x158 timeline_speed
/* @0x197e64 mov r0, r4 */
/* @0x197e68 blx r3 */   —— 读第 50 项（6，bool）
/* @0x197e6c mov r1, r7 */
/* @0x197e70 mov r0, r5 */
/* @0x197e74 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197e78 ldr r3, [r4] */
/* @0x197e7c mov r2, r5 */
/* @0x197e80 mov r1, #6 */
/* @0x197e84 ldr r3, [r3, #0xc] */
/* @0x197e88 strb r0, [r6, #0x15c] */   —— +0x15c timeline_running（字节）
/* @0x197e8c mov r0, r4 */
/* @0x197e90 blx r3 */   —— 读第 51 项（6，bool）
/* @0x197e94 mov r1, r7 */
/* @0x197e98 mov r0, r5 */
/* @0x197e9c bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197ea0 ldr r3, [r4] */
/* @0x197ea4 mov r2, r5 */
/* @0x197ea8 mov r1, #6 */
/* @0x197eac ldr r3, [r3, #0xc] */
/* @0x197eb0 strb r0, [r6, #0x15d] */   —— +0x15d timeline_loop（字节）
/* @0x197eb4 mov r0, r4 */
/* @0x197eb8 blx r3 */   —— 读第 52 项（6，bool）
/* @0x197ebc mov r1, r7 */
/* @0x197ec0 mov r0, r5 */
/* @0x197ec4 bl 0xce768 <_Z9YYGetBoolPK6RValuei> */
/* @0x197ec8 ldr r3, [r4] */
/* @0x197ecc mov r1, #6 */
/* @0x197ed0 mov r2, r5 */
/* @0x197ed4 ldr r3, [r3, #0xc] */
/* @0x197ed8 strb r0, [r6, #0x15e] */   —— +0x15e（字节，未定）
/* @0x197edc mov r0, r4 */
/* @0x197ee0 blx r3 */   —— 读第 53 项（6）
/* @0x197ee4 mov r0, r5 */
/* @0x197ee8 mov r1, r7 */

/* ── 53. layer（int → +0x170）＋ 变量块门闸 ────────────────────────────────
 *    0x197ef0 取 *(int*)(this+0x24)（基类变量槽计数）；为 0 就 pop 返回，连 n 都不读。── */
/* @0x197eec bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197ef0 ldr r3, [r6, #0x24] */   —— *(int*)(this+0x24) = 变量槽计数
/* @0x197ef4 cmp r3, #0 */
/* @0x197ef8 str r0, [r6, #0x170] */   —— layer 落盘（在门闸之前，无条件执行）
/* @0x197efc popeq {r4, r5, r6, r7, r8, pc} */   —— 计数为 0 ⇒ 直接返回（不读 n）

/* ── 54. 变量块：个数 n + 一致性检查 ────────────────────────────────────────
 *    0x197f14 读 n；0x197f24/0x197f28/0x197f2c 走 GOT 0x3EDD1C → 0x544b48 取 *(int*)；
 *    不等则 0x197f3c..0x197f58 用 GOT 0x3ED71C → 0x3EB70C 的全局对象打一条字符串
 *    0x34CCE0 = "WARNING! game_load variable mismatch - unpredictable results!"。
 *    r7 从 0x197f34 起 = n（后面当循环上限）。── */
/* @0x197f00 ldr r3, [r4] */
/* @0x197f04 mov r1, #6 */
/* @0x197f08 mov r2, r5 */
/* @0x197f0c mov r0, r4 */
/* @0x197f10 ldr r3, [r3, #0xc] */
/* @0x197f14 blx r3 */   —— 读第 54 项（6）= 变量个数 n
/* @0x197f18 mov r1, r7 */
/* @0x197f1c mov r0, r5 */
/* @0x197f20 bl 0xce870 <_Z10YYGetInt32PK6RValuei> */
/* @0x197f24 ldr r3, [pc, #0x74] */   —— GOT 偏移 0x00255dec
/* @0x197f28 ldr r3, [pc, r3] */   —— → GOT 0x3EDD1C
/* @0x197f2c ldr r3, [r3] */   —— → *(int*)0x544b48（与基类构造第 1 实参同源）
/* @0x197f30 cmp r3, r0 */   —— n vs *(int*)0x544b48
/* @0x197f34 mov r7, r0 */   —— r7 = n（后面的循环上限）
/* @0x197f38 beq 0x197f5c <_ZN9CInstance11DeSerialiseEP7IBufferb+0x8f0> */   —— 相等 ⇒ 跳过警告
/* @0x197f3c ldr r3, [pc, #0x60] */   —— GOT 偏移 0x002557d0
/* @0x197f40 ldr r1, [pc, #0x60] */   —— 字符串偏移 0x001b4d90
/* @0x197f44 ldr r3, [pc, r3] */   —— → GOT 0x3ED71C
/* @0x197f48 add r1, pc, r1 */   —— r1 = 0x34CCE0 = "WARNING! game_load variable mismatch - unpredictable results!"
/* @0x197f4c ldr r0, [r3] */   —— r0 = 全局控制台对象
/* @0x197f50 ldr r3, [r0] */   —— vtable
/* @0x197f54 ldr r3, [r3, #0xc] */   —— vtable[3] = 日志/输出
/* @0x197f58 blx r3 */   —— 打警告（不中断）
/* @0x197f5c cmp r7, #0 */   —— n == 0 ⇒ 返回
/* @0x197f60 pople {r4, r5, r6, r7, r8, pc} */

/* ── 55. 变量块：n × RValue::DeSerialise(buf) ─────────────────────────────
 *    r5 = i，r4 = buf；*(int**)(this+0x04) 非 0 → RValue* = base + i*16（lsl #4）；
 *    为 0 → InternalGetYYVar(this, i)。两条路最后都进 0x197f80 的 RValue::DeSerialise。── */
/* @0x197f64 mov r5, #0 */
/* @0x197f68 ldr r3, [r6, #0x4] */   —— *(int**)(this+0x04) = 变量槽数组基址
/* @0x197f6c cmp r3, #0 */
/* @0x197f70 add r0, r3, r5, lsl #4 */   —— RValue* = base + i*16（16 B/槽）
/* @0x197f74 beq 0x197f90 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x924> */   —— base == 0 ⇒ 走 InternalGetYYVar 分支
/* @0x197f78 add r5, r5, #1 */
/* @0x197f7c mov r1, r4 */   —— r1 = buf
/* @0x197f80 bl 0xcf6e4 <_ZN6RValue11DeSerialiseEP7IBuffer> */   —— RValue::DeSerialise(buf) —— 就地覆盖第 i 个槽
/* @0x197f84 cmp r5, r7 */
/* @0x197f88 bne 0x197f68 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x8fc> */
/* @0x197f8c pop {r4, r5, r6, r7, r8, pc} */
/* @0x197f90 mov r0, r6 */   —— base == 0：r0 = this
/* @0x197f94 mov r1, r5 */   —— r1 = i
/* @0x197f98 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */   —— → 该槽的 RValue*
/* @0x197f9c b 0x197f78 <_ZN9CInstance11DeSerialiseEP7IBufferb+0x90c> */   —— 回到 0x197f78 的 i++ 与循环判断

/* ── 56. literal pool（3 字，objdump 当指令译出，**非指令**）────────────────
 *    0x197fa0 = 0x00255dec → 0x3EDD1C（读 *(int*)0x544b48 用）
 *    0x197fa4 = 0x002557d0 → GOT 0x3ED71C（取全局控制台对象）
 *    0x197fa8 = 0x001b4d90 → 0x34CCE0（"WARNING! game_load variable mismatch ..."）
 *    函数到此结束；0x197fac 起是 YYObjectBase::InternalGetYYVarRef。── */
/* @0x197fa0 eoreq r5, r5, r12, ror #27 */
/* @0x197fa4 .word 0x002557d0 */
/* @0x197fa8 mulseq r11, r0, sp */
