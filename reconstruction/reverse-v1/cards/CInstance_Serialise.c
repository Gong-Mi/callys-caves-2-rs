/* cally 逆向卡：CInstance::Serialise(IBuffer*)（原版 libyoyo.so，armv7）
 * @func 0x196bf4 0x19766c  size 2680  670 字（669 条指令 + 末 1 字 0x197668 为 literal pool）
 * 级别: 正文（670/670 逐条落锚。54 个写点的类型码与源偏移、写协议、+0x64 脏标记前置重算、
 *       变量块三条外部路径、与 DeSerialise 0x19766c 的 54 项逐项对照全部钉死；未钉的只是
 *       五个槽（+0x144 / +0x148 / +0x150 / +0x15e / +0x0b0）的语义名，以及 RValue 暂存槽 +0x34 由谁维护。
 *       tier = bytecode_anchored）
 * 符号: _ZN9CInstance9SerialiseEP7IBuffer → void CInstance::Serialise(IBuffer* buf)
 * ABI : softfp；无返回值（三处出口都是 pop {r3,r4,r5,r6,r7,r8,r9,r10,r11,pc}）；
 *       不建栈帧（push 10 个寄存器后直接开工，全程无 sub sp）；double 中转用 d6/d7(= s12..s15)，
 *       属 caller-saved 的 d0..d7，所以不需要 vpush
 * 位置: YYObjectBase::FindOrAllocValue 0x196bc4 之后；CInstance::DeSerialise 0x19766c 之前
 *       （0x197668 那一个字是本函数的 literal pool，不是指令）
 * 调用点: 全图唯二（扫已索引函数的 bl 目标）：CRoom::Serialise 0x1aacc8（活动实例链）与
 *         0x1aad24（非活动实例链）；两处都 r0=实例、r1=buf，链沿 +0x178（prev）从尾往前走，
 *         与 CRoom::DeSerialise 的两处 DeSerialise 调用点严格镜像
 * 同层: CInstance::DeSerialise 0x19766c（流布局严格互逆）、CInstance::Compute_BoundingBox 0x192340、
 *       CInstance::SetObjectIndex 0x19324c、RValue::Serialise 0xcf47c、YYObjectBase::InternalGetYYVar 0x196a70、
 *       CInstance::Assign 0x1986ec、CInstance::C2 0x1994dc、CRoom::Serialise 0x1aa228
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   一条 CInstance 存档记录 = 54 项带类型码的标量（其中 alarm 是一个写点循环 12 次）
 *   + 1 个变量块（个数 n + n 个 RValue）。写侧从 this 的 53 个固定偏移取值、按固定次序交给
 *   IBuffer::Serialize；这个次序与 DeSerialise 的读序逐项相同（51/54 连偏移都一样），
 *   所以两侧共用同一份格式定义：没有版本号、没有长度前缀、没有字段名，写错一项后面全歪。
 *   只有三处不是「照抄字段」：object_index 直读 +0x7c（读侧走 SetObjectIndex）、alarm 用
 *   this 游标、变量个数取自全局 *(int*)0x544b48 而不是 this+0x24。
 *   另有一条**只在写侧存在**的前置动作：+0x64（bbox 脏）非 0 时先 Compute_BoundingBox(true)。
 *   ⇒ 本函数不是纯读：脏实例被存盘会重算 bbox 并改 RTree。
 *
 * ── 语义草案 ──────────────────────────────────────────────────────────────
 *   // 每一次写都是 buf->Serialize(类型码, (RValue*)((char*)buf+0x2c))，虚槽 vt+0x08
 *   void CInstance::Serialise(IBuffer* buf) {
 *     if (this->[0x64]) Compute_BoundingBox(true);      // 0x196bfc → 0x19764c（唯一副作用）
 *     W(6, this->id);                                   // +0x078
 *     W(6, this->deactivated);                          // +0x069（字节）
 *     W(6, this->objindex);                             // +0x07c（直读）
 *     W(6, this->sprite_index);                         // +0x08c
 *     W(8, image_index); W(8, image_speed); W(8, image_xscale); W(8, image_yscale);
 *     W(8, image_angle); W(8, image_alpha);              // +0x090..+0x0a4
 *     W(5, this->image_blend);                           // +0x0a8（唯一码 5）
 *     W(6, this->mask_index);                            // +0x0ac
 *     W(8, this->depth);                                 // +0x180（f32，跳偏移写）
 *     W(6, this->[0xb0]);                                // 字节
 *     W(8, x,y,xstart,ystart,xprevious,yprevious,direction,speed,friction,
 *          gravity_direction,gravity,hspeed,vspeed);      // +0x0b4..+0x0e4（13 项）
 *     W(6, bbox.left); W(6, bbox.right); W(6, bbox.top); W(6, bbox.bottom);  // +0xe8,+0xf0,+0xec,+0xf4
 *     W(6, visible); W(6, solid); W(6, persistent);       // +0x065/+0x066/+0x067（字节）
 *     for (i = 0; i < 12; i++) W(6, alarm[i]);            // +0x0f8..+0x124（单写点）
 *     W(6, this->[0x68]);                                 // skip（字节）
 *     W(6, this->path_index);                             // +0x128
 *     W(8, path_position); W(8, path_positionprevious); W(8, path_speed);
 *     W(8, path_scale); W(8, path_orientation);           // +0x12c..+0x13c
 *     W(6, this->path_endaction);                         // +0x140
 *     W(8, this->[0x144]); W(8, this->[0x148]);           // 未定
 *     W(6, this->timeline_index);                         // +0x14c
 *     W(8, this->[0x150]); W(8, timeline_position); W(8, timeline_speed);  // +0x150/+0x154/+0x158
 *     W(6, timeline_running); W(6, timeline_loop); W(6, this->[0x15e]);    // +0x15c/+0x15d/+0x15e
 *     W(6, this->layer);                                  // +0x170
 *     if (*(int*)((char*)this + 0x24) == 0) return;        // 没有变量槽 ⇒ 连个数都不写
 *     W(6, *(int*)0x544b48);                              // ★ 全局计数，不是 this+0x24
 *     int n = *(int*)0x544b48;
 *     if (n <= 0) return;
 *     for (i = 0; i < n; i++)
 *       RValue::Serialise(VarSlot(i), buf);               // base + i*16 或 InternalGetYYVar(this,i)
 *   }
 *
 * ── 写协议（54 个写点全同形，与 DeSerialise 的读协议共用同一块暂存区）──────────
 *   固定形状：r0 = buf、r1 = 类型码、r2 = buf+0x2c（IBuffer 内嵌的 16 B RValue 暂存槽）、
 *   `ldr r3,[buf]; ldr r3,[r3,#0x08]; blx r3`。虚槽 +0x08 是写（Serialize），+0x0c 是读。
 *   值先转成 double：低字进 buf+0x2c、高字进 buf+0x30（两种写法等价：`vstr s14/s15` 一对，
 *   或 `vmov r4,r5,d6` 后 `vstr s12,[+0x2c]` + `str r5,[+0x30]`，后者能被编译器省一条 vstr）。
 *   tag 字 buf+0x38（RValue+0x0c）每次写前清 0，由三个零寄存器轮换提供（r5 → r10 → r8）；
 *   buf+0x34（RValue+0x08）本函数**从不写**。
 *   类型码只有三种：8 = real（vcvt.f64.f32）、6 = int32（vcvt.f64.s32；bool 也用它，从字节
 *   ldrb 后 vcvt.f64.u32）、5 = uint32（只有 image_blend 一处）。54 项的码分布 = 30×8 + 14×6(int)
 *   + 9×6(bool 字节) + 1×5，与读侧 YYGetFloat/YYGetInt32/YYGetBool/YYGetUint32 的 30/14/9/1 一一对应。
 *   全函数 56 条读 this 的指令（入口 0x196bfc 那条经 r0，其余 55 条经 r7/r11）、0 条写 this 的指令；
 *   唯一的写路径是 0x197650 的 Compute_BoundingBox。
 *
 * ── 流序总表（左 = 流里第几项 / 类型码 / 写侧源；右 = 读侧落点）──────────────────
 *    1   6  int    +0x078 id              → +0x078
 *    2   6  bool   +0x069 deactivated     → +0x069（字节）
 *    3   6  int    +0x07c object_index    → ★ 读侧走 SetObjectIndex，无直接落点
 *    4   6  int    +0x08c sprite_index    → +0x08c
 *    5   8  float  +0x090 image_index     → +0x090
 *    6   8  float  +0x094 image_speed     → +0x094
 *    7   8  float  +0x098 image_xscale    → +0x098
 *    8   8  float  +0x09c image_yscale    → +0x09c
 *    9   8  float  +0x0a0 image_angle     → +0x0a0
 *   10   8  float  +0x0a4 image_alpha     → +0x0a4
 *   11   5  uint32 +0x0a8 image_blend     → +0x0a8
 *   12   6  int    +0x0ac mask_index      → +0x0ac
 *   13   8  float  +0x180 depth           → +0x180   ← 不按偏移顺序：mask 之后直接跳 0x180
 *   14   6  bool   +0x0b0（spr+0x30 缓存）→ +0x0b0（字节）
 *   15   8  float  +0x0b4 x               → +0x0b4
 *   16   8  float  +0x0b8 y               → +0x0b8
 *   17   8  float  +0x0bc xstart          → +0x0bc
 *   18   8  float  +0x0c0 ystart          → +0x0c0
 *   19   8  float  +0x0c4 xprevious       → +0x0c4
 *   20   8  float  +0x0c8 yprevious       → +0x0c8
 *   21   8  float  +0x0cc direction        → +0x0cc
 *   22   8  float  +0x0d0 speed            → +0x0d0
 *   23   8  float  +0x0d4 friction         → +0x0d4
 *   24   8  float  +0x0d8 gravity_direction→ +0x0d8
 *   25   8  float  +0x0dc gravity          → +0x0dc
 *   26   8  float  +0x0e0 hspeed           → +0x0e0
 *   27   8  float  +0x0e4 vspeed           → +0x0e4
 *   28   6  int    +0x0e8 bbox.left        → +0x0e8
 *   29   6  int    +0x0f0 bbox.right       → +0x0f0   ← 次序是 L,R,T,B（不是 L,T,R,B）
 *   30   6  int    +0x0ec bbox.top         → +0x0ec
 *   31   6  int    +0x0f4 bbox.bottom      → +0x0f4
 *   32   6  bool   +0x065 visible          → +0x065（字节）
 *   33   6  bool   +0x066 solid            → +0x066（字节）
 *   34   6  bool   +0x067 persistent       → +0x067（字节）
 *   35   6  int    +0x0f8..+0x124 alarm[]  → 同（单写点 12 次，游标 +4/轮）
 *   36   6  bool   +0x068 skip             → +0x068（字节）
 *   37   6  int    +0x128 path_index        → +0x128
 *   38   8  float  +0x12c path_position     → +0x12c
 *   39   8  float  +0x130 path_positionprevious → +0x130
 *   40   8  float  +0x134 path_speed        → +0x134
 *   41   8  float  +0x138 path_scale        → +0x138
 *   42   8  float  +0x13c path_orientation  → +0x13c
 *   43   6  int    +0x140 path_endaction    → +0x140
 *   44   8  float  +0x144（未定①）          → +0x144
 *   45   8  float  +0x148（未定②）          → +0x148
 *   46   6  int    +0x14c timeline_index    → +0x14c
 *   47   8  float  +0x150（未定③）          → +0x150
 *   48   8  float  +0x154 timeline_position → +0x154
 *   49   8  float  +0x158 timeline_speed    → +0x158
 *   50   6  bool   +0x15c timeline_running  → +0x15c（字节）
 *   51   6  bool   +0x15d timeline_loop     → +0x15d（字节）
 *   52   6  bool   +0x15e（未定④）          → +0x15e（字节）
 *   53   6  int    +0x170 layer             → +0x170
 *   54   6  int    ★ 全局 *(int*)0x544b48   → 读侧只拿它对 n 做一致性检查
 *   n × RValue::Serialise(槽, buf)（直调 0xcf47c，不走 IBuffer 虚表）
 *   54 项里 53 项是字段（其中 alarm 一项占 12 槽）⇒ 字段槽 = 52 + 12 = 64；第 54 项是变量个数，
 *   不落 this。与 DeSerialise 卡的「54 项覆盖 64 槽」一致。
 *
 * ── 与 DeSerialise 是否严格互逆 ────────────────────────────────────────────
 *   结论：**流布局严格互逆，函数语义不互逆**。
 *   (1) 逐项偏移：脚本比对（写侧源偏移 vs 读侧落点）⇒ 54 项里 51 项完全相同，另 3 项是结构性
 *       差异（不是字段差异；其中 alarm 的语义在两侧都是「+0x0f8 起 12 个 int」，见下）：
 *       · 第 3 项：写侧 `vldr s14,[r7,#124]` 直读 +0x07c；读侧不写 +0x7c，改走
 *         SetObjectIndex(objindex, bRegister && !deactivated)。⇒ 单看流是互逆的；单看副作用不互逆
 *         （读档会重挂对象实例链、把 +0x080/+0x064/+0x065..0x067/+0x08c/+0x0ac/+0x180 一并重置，
 *         其中 +0x08c/+0x0ac/+0x180/+0x065..0x067 随后被第 4/12/13/32/33/34 项覆盖回来
 *         ⇒ 流的次序在这里是**必须**的，不是编译噪声）。
 *       · 第 35 项：写侧游标 r11 = this，每轮**先取** [r11+0xf8] 再 add r11,#4；读侧游标 r8 的初值
 *         也是 this（0x197694 mov r8,r6），但每轮**先 add r8,#4** 再存 [r8+0xf4]（首次 = this+0xf8）。
 *       · 第 54 项：写侧写的是全局 *(int*)0x544b48；读侧把流里的 n 与同一个全局比较、不等只打
 *         warning 不中断。写侧从不读 this+0x24 当值，只用它当门（== 0 就整段变量块都不写）。
 *   (2) 前置换算（写侧独有）：入口 0x196bfc 读 +0x64，非 0 就 0x19764c Compute_BoundingBox(true)
 *       再回 0x196c0c。它会重写 +0x0e8/+0x0ec/+0x0f0/+0x0f4 与 +0x0b0、清 +0x64，并且因为
 *       updateRTree=true 还调 CollisionUpdate（先按旧盒摘 RTree、再按新盒插入）。读侧没有这条路径，
 *       它靠 SetObjectIndex 把 +0x64 置 1，交给之后的 HandleOther 惰性重算。
 *       ⇒ 「存盘」不是纯读：脏实例存盘会改自己的 bbox 和碰撞 RTree。
 *   (3) 循环条件：写侧 `cmp r3,r8` / `bgt`（count > i+1）；读侧 `cmp r5,r7` / `bne`（i != n）。
 *       正常的非负计数两者等价；流里若出现**负的 n**，读侧不会退出，写侧根本产生不了负数。
 *   ⇒ 所以「Serialise 再 DeSerialise 回来」得到的是：64 个字段槽全等于**写进流那一刻**的值
 *     （写的是脏实例时，其中 bbox 四边与 +0x0b0 是刚被重算出来的新值，而不是调用前的旧值），
 *     而引擎侧状态（+0x044/+0x064/+0x080/+0x084/+0x088/+0x178/+0x188..+0x1ac 三链、
 *     +0x160/+0x164/+0x168/+0x16c/+0x174/+0x184）回到 ctor 默认值或保持旧值。
 *
 * ── 丢字段清单（ctor 字段表里有、流里没有）────────────────────────────────
 *   A 引擎/房间簿记（房间侧重建，或由读侧 SetObjectIndex 重建）
 *     +0x044 全局实例表槽号      （CRoom 侧另算；析构用它清槽）
 *     +0x064 bbox 脏标记         （写侧只当门用、不入流；读侧由 SetObjectIndex 置 1）
 *     +0x080 CObjectGM*          （读侧由 SetObjectIndex 按 objindex 查表重建）
 *     +0x178/+0x17c 房间步进/绘制链 next/prev（正是 CRoom::Serialise 遍历用的那条链）
 *     +0x188 碰撞网格槽号（-1 哨兵）、+0x18c/+0x190 碰撞测试链 link + +0x194 链头、
 *     +0x198/+0x19c 碰撞脏链 link + +0x1a0 链头、+0x1a4/+0x1a8 句柄链 link + +0x1ac 链头
 *   B 指针/外部对象（不可序列化）
 *     +0x084 CPhysicsObject*、+0x088 CSkeletonInstance*
 *     +0x004..+0x060 基类写区（vtable、创建栈 +0x010/+0x014、变量槽基址 +0x04、变量槽计数 +0x24、
 *     名称哈希表 +0x060 等）—— 其中 +0x04/+0x24 被本函数当**结构**用（基址/门），不进流
 *   C 引擎内部状态（存档不承载）
 *     +0x048（=1 标记，语义未定）、+0x06a 硬销毁标记、+0x06b、+0x06c
 *     +0x070/+0x074 ms_CurrentCreateCounter 快照（8 B）
 *     +0x160、+0x164  ★ 重点：ctor 置 0、Assign 逐字抄，但 Serialise 与 DeSerialise **都不碰**
 *                     ⇒ 走「new + DeSerialise」读档后恒为 0；就地 DeSerialise 则保留旧值
 *     +0x168（ChangeObjectIndex/RelinkObjectTypes 读写）、+0x16c（=2，HandleEnter 读）、
 *     +0x174（字节，GV_Layer 先读它）、+0x184（CRoom::AddInstance/RelinkObjectTypes 读）
 *   ⇒ 读档后的实例：没有物理体、没有骨架实例、不在任何碰撞/句柄链上、没有实例表槽号、
 *     bbox 脏标记是 1（等下一次 HandleOther 重算）。
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1. 54 个写点，形状完全同一：`ldr r3,[r9]`（buf 虚表）→ `str <零>,[r9,#0x38]`（清 tag）→
 *     低字/高字两存 → `mov r1,#码` → `ldr r3,[r3,#0x8]` → `blx r3`。计数：blx 54 条全指 vt+0x08；
 *     `str …, [r9,#0x38]` 54 条；低字 54 条（vstr s14×40 + vstr s12×14）；高字 54 条
 *     （vstr s15×33 + str r5×21）。码分布 30×8 + 14×6(int) + 9×6(bool) + 1×5。
 *  2. 值一律先转 double：vcvt.f64.f32 ×30、vcvt.f64.s32 ×14、vcvt.f64.u32 ×10，合计 54，
 *     与 54 个写点一一对应；码 5 只有 0x196df0 一处（image_blend，vcvt.f64.u32）。
 *  3. 脏标记前置（唯一副作用）：0x196bfc `ldrb r3,[r0,#0x64]` → 0x196c04 cmp → 0x196c08
 *     `bne 0x19764c` → 0x19764c `mov r1,#1` / 0x197650 `bl CInstance::Compute_BoundingBox(bool)` /
 *     0x197654 `b 0x196c0c`。全函数 56 条读 this、0 条写 this ⇒ this 的改动只可能来自这条路径。
 *  4. 第 3 项直读 +0x7c：0x196c7c `vldr s14,[r7,#124]` + 0x196c80 `vcvt.f64.s32`，没有
 *     SetObjectIndex / GetObjectIndex 调用（全函数 bl 只有 3 个目标：0x192340、0x196a70、0xcf47c）。
 *  5. alarm 是单写点 12 次循环：0x196c38 `mov r8,#12`；循环体 0x197210..0x19724c（`ldr r4,[r11,#0xf8]`、
 *     `add r11,r11,#4`、`subs r8,r8,#1`、`bne 0x197210`）⇒ 首项 +0x0f8、末项 +0x124。
 *     循环结束后 r8 = 0，被后面当成常量零复用（tag 清零用的是 r8）。
 *  6. 变量块的门：0x1975d0 `ldr r3,[r7,#0x24]` / 0x1975d4 cmp / 0x1975d8 `popeq` ⇒ 实例没有变量槽时
 *     **连个数都不写**（与读侧 0x197ef0..0x197efc 同形同址的门）。
 *  7. 计数值来自全局：0x1975dc `ldr r10,[pc,#0x84]`（literal 在 0x197668 = 0x00256728）→
 *     0x1975ec `ldr r10,[pc,r10]` → GOT 0x3EDD1C → 0x1975f0 `vldr s15,[r10]` = *(int*)0x544b48。
 *     与基类构造的第 1 实参、读侧那条 warning 的比较对象是同一个全局。
 *  8. 槽寻址与调用：0x197620 `ldr r0,[r7,#0x4]`、0x197628 `add r0,r0,r8,lsl #4`（16 B/槽）、
 *     0x19762c `beq 0x197658`；base==0 时 0x197658 `mov r0,r7` / `mov r1,r8` /
 *     `bl YYObjectBase::InternalGetYYVar` / `b 0x197630`。两条路最后都进 0x197638
 *     `bl RValue::Serialise(0xcf47c)`（直调，不走 IBuffer 虚表）。
 *  9. 循环条件差异：写侧 0x19763c `ldr r3,[r10]` / 0x197640 `cmp r3,r8` / 0x197644 `bgt`；
 *     读侧 0x197f84 / 0x197f88 是 `cmp r5,r7` / `bne`（见互逆判定 3）。
 * 10. 三处出口 + 6 条分支：popeq 0x1975d8、pople 0x19761c、pop 0x197648；分支
 *     bne×2（0x196c08、0x19724c）、beq 0x19762c、bgt 0x197644、b×2（0x197654、0x197664）。
 * 11. 不建栈帧、无异常表、无 vpush：push 10 个寄存器后直接开工；double 中转全用 d6/d7（= s12..s15，
 *     属 caller-saved 的 d0..d7）。与 DeSerialise「全函数不碰 VFP」正好相反 —— 写侧必须现场造 double。
 * 12. 54 项与读侧逐项同偏移：脚本（写侧源偏移 vs 读侧落点）比对，51/54 直接相等，另 3 项见上。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. +0x144/+0x148/+0x150/+0x15e 四个槽的语义名未定：前三个都按 f32 读写，ctor 不初始化、
 *     Assign 不复制，Compute_BoundingBox 也不写 ⇒ 只由存档流承载（既不是 bbox 的边，也不是指针）；
 *     +0x15e 是 timeline 组里第三个字节 bool，与 +0x15c/+0x15d 同批读写。
 *  2. +0x0b0：Compute_BoundingBox 从 spr+0x30 抄一个字节，本函数按码 6 存、读侧按字节写回；
 *     spr+0x30 的官方名（bbox mode / 掩码种类？）未证。
 *  3. RValue 暂存槽 +0x34（buf+0x34）本函数从不写；「由 IBuffer::Serialize 依类型码维护」只是推断
 *     —— IBuffer::Serialize 本体尚未出卡。
 *  4. 变量个数取全局而非 this+0x24：若某实例的 +0x24 与全局不等，写侧会按全局次数遍历
 *     *(this+0x04) 数组 ⇒ 越界读。正常构造下二者同源（基类第 1 实参就是该全局），但本函数不校验；
 *     只有读侧有那条 warning。
 *  5. 脏实例被 Serialise 会顺带重算 bbox 并改碰撞 RTree（CollisionUpdate）；存盘期间是否与
 *     HandleOther 的惰性重算构成竞态未证。
 *  6. +0x64 在读档后保持 1（SetObjectIndex 置位、读侧不重算），要等下一次 HandleOther 派发才清；
 *     与写侧「存盘前必先清」正好互补，但 HandleOther 的派发细节在另一张卡。
 *
 * ── 逐条锚点（地址/字/mnemonic/operands 全部来自 asm/index-CInstance_Serialise.tsv）────
 */


/* ── 0. 入口（0x196bf4..0x196c08）：r0=this、r1=buf；先把 +0x64（bbox 脏标记）过一遍 ——
 *    SetObjectIndex 置 1、Compute_BoundingBox 清 0；非 0 就跳到函数末尾的 0x19764c 先重算 bbox，
 *    回来再从 0x196c0c 开始写流。这是本函数唯一的副作用，也是它与 DeSerialise 的唯一非对称动作。
 *    寄存器分配：r7 = this、r9 = buf、r6 = buf+0x2c（暂存槽）、r5/r10/r8 = 三个零常量、
 *    r11 = this（alarm 游标，此后 +4 前进）。── */
/* @0x196bf4 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */   —— 入口；10 个寄存器入栈，无栈帧
/* @0x196bf8 mov r7, r0 */   —— r7 = this
/* @0x196bfc ldrb r3, [r0, #0x64] */   —— ★ 读 +0x64 = bbox 脏标记（SetObjectIndex 置 1 / Compute_BoundingBox 清 0）
/* @0x196c00 mov r9, r1 */   —— r9 = buf
/* @0x196c04 cmp r3, #0 */
/* @0x196c08 bne 0x19764c <_ZN9CInstance9SerialiseEP7IBuffer+0xa58> */   —— 脏 ⇒ 先转 0x19764c 重算 bbox，再回 0x196c0c 写第 1 项

/* ── 1. 第 1 项：id（码 6，int 位模式）→ +0x078 ── */
/* @0x196c0c vldr s14, [r7, #120] */   —— +0x078 id（int 位模式）
/* @0x196c10 vcvt.f64.s32 d7, s14 */
/* @0x196c14 ldr r3, [r9] */   —— buf->vtable
/* @0x196c18 add r6, r9, #44 */   —— r6 = buf+0x2c = IBuffer 内嵌的 16 B RValue 暂存槽
/* @0x196c1c mov r5, #0 */   —— r5 = 0（tag 零常量①）
/* @0x196c20 mov r1, #6 */
/* @0x196c24 mov r2, r6 */   —— r2 = &暂存槽
/* @0x196c28 str r5, [r9, #0x38] */   —— ★ 清 tag：RValue+0x0c = buf+0x38
/* @0x196c2c mov r0, r9 */   —— r0 = buf
/* @0x196c30 mov r10, r5 */   —— r10 = 0（零常量②）
/* @0x196c34 mov r11, r7 */   —— r11 = this（alarm 游标）
/* @0x196c38 mov r8, #12 */   —— r8 = 12（alarm 次数；循环后归 0，再被当零常量③）
/* @0x196c3c vstr s14, [r9, #44] */   —— 低字 → buf+0x2c
/* @0x196c40 vstr s15, [r9, #48] */   —— 高字 → buf+0x30
/* @0x196c44 ldr r3, [r3, #0x8] */   —— vtable[+0x08] = IBuffer::Serialize(码, RValue*)
/* @0x196c48 blx r3 */   —— 写第 1 项（码 6）

/* ── 2. 第 2 项：deactivated（码 6，字节 bool）→ +0x069 ── */
/* @0x196c4c ldrb r3, [r7, #0x69] */   —— +0x069 deactivated（ldrb → vcvt.u32，码仍是 6）
/* @0x196c50 mov r2, r6 */
/* @0x196c54 str r5, [r9, #0x38] */
/* @0x196c58 mov r1, #6 */
/* @0x196c5c mov r0, r9 */
/* @0x196c60 vmov s14, r3 */   —— 字节 → 无符号 vmov
/* @0x196c64 ldr r3, [r9] */
/* @0x196c68 vcvt.f64.u32 d7, s14 */
/* @0x196c6c vstr s14, [r9, #44] */
/* @0x196c70 vstr s15, [r9, #48] */
/* @0x196c74 ldr r3, [r3, #0x8] */
/* @0x196c78 blx r3 */   —— 写第 2 项（码 6）

/* ── 3. 第 3 项：object_index（码 6）→ 直读 +0x07c，不走 SetObjectIndex ── */
/* @0x196c7c vldr s14, [r7, #124] */   —— ★ 源 +0x07c object_index：直读，没有 SetObjectIndex/GetObjectIndex
/* @0x196c80 vcvt.f64.s32 d7, s14 */
/* @0x196c84 ldr r3, [r9] */
/* @0x196c88 mov r2, r6 */
/* @0x196c8c str r5, [r9, #0x38] */
/* @0x196c90 mov r1, #6 */
/* @0x196c94 mov r0, r9 */
/* @0x196c98 vstr s14, [r9, #44] */
/* @0x196c9c vstr s15, [r9, #48] */
/* @0x196ca0 ldr r3, [r3, #0x8] */
/* @0x196ca4 blx r3 */   —— 写第 3 项（码 6）

/* ── 4. 第 4 项：sprite_index（码 6）→ +0x08c ── */
/* @0x196ca8 vldr s14, [r7, #140] */   —— +0x08c sprite_index（int 位模式）
/* @0x196cac vcvt.f64.s32 d7, s14 */
/* @0x196cb0 ldr r3, [r9] */
/* @0x196cb4 mov r2, r6 */
/* @0x196cb8 str r5, [r9, #0x38] */
/* @0x196cbc mov r1, #6 */
/* @0x196cc0 mov r0, r9 */
/* @0x196cc4 vstr s14, [r9, #44] */
/* @0x196cc8 vstr s15, [r9, #48] */
/* @0x196ccc ldr r3, [r3, #0x8] */
/* @0x196cd0 blx r3 */   —— 写第 4 项（码 6）

/* ── 5..10. 图像组 6 项（码 8，f32）：+0x090 image_index / +0x094 image_speed / +0x098 image_xscale
 *    / +0x09c image_yscale / +0x0a0 image_angle / +0x0a4 image_alpha ── */
/* @0x196cd4 vldr s14, [r7, #144] */   —— +0x090 image_index（f32 → double）
/* @0x196cd8 vcvt.f64.f32 d7, s14 */
/* @0x196cdc ldr r3, [r9] */
/* @0x196ce0 str r5, [r9, #0x38] */
/* @0x196ce4 mov r2, r6 */
/* @0x196ce8 mov r1, #8 */
/* @0x196cec mov r0, r9 */
/* @0x196cf0 vstr s14, [r9, #44] */
/* @0x196cf4 vstr s15, [r9, #48] */
/* @0x196cf8 ldr r3, [r3, #0x8] */
/* @0x196cfc blx r3 */   —— 写第 5 项（码 8）
/* @0x196d00 vldr s14, [r7, #148] */   —— +0x094 image_speed
/* @0x196d04 vcvt.f64.f32 d7, s14 */
/* @0x196d08 ldr r3, [r9] */
/* @0x196d0c str r5, [r9, #0x38] */
/* @0x196d10 mov r2, r6 */
/* @0x196d14 mov r1, #8 */
/* @0x196d18 mov r0, r9 */
/* @0x196d1c vstr s14, [r9, #44] */
/* @0x196d20 vstr s15, [r9, #48] */
/* @0x196d24 ldr r3, [r3, #0x8] */
/* @0x196d28 blx r3 */   —— 写第 6 项（码 8）
/* @0x196d2c vldr s14, [r7, #152] */   —— +0x098 image_xscale
/* @0x196d30 vcvt.f64.f32 d7, s14 */
/* @0x196d34 ldr r3, [r9] */
/* @0x196d38 str r5, [r9, #0x38] */
/* @0x196d3c mov r2, r6 */
/* @0x196d40 mov r1, #8 */
/* @0x196d44 mov r0, r9 */
/* @0x196d48 vstr s14, [r9, #44] */
/* @0x196d4c vstr s15, [r9, #48] */
/* @0x196d50 ldr r3, [r3, #0x8] */
/* @0x196d54 blx r3 */   —— 写第 7 项（码 8）
/* @0x196d58 vldr s14, [r7, #156] */   —— +0x09c image_yscale
/* @0x196d5c vcvt.f64.f32 d7, s14 */
/* @0x196d60 ldr r3, [r9] */
/* @0x196d64 str r5, [r9, #0x38] */
/* @0x196d68 mov r2, r6 */
/* @0x196d6c mov r1, #8 */
/* @0x196d70 mov r0, r9 */
/* @0x196d74 vstr s14, [r9, #44] */
/* @0x196d78 vstr s15, [r9, #48] */
/* @0x196d7c ldr r3, [r3, #0x8] */
/* @0x196d80 blx r3 */   —— 写第 8 项（码 8）
/* @0x196d84 vldr s14, [r7, #160] */   —— +0x0a0 image_angle
/* @0x196d88 vcvt.f64.f32 d7, s14 */
/* @0x196d8c ldr r3, [r9] */
/* @0x196d90 str r5, [r9, #0x38] */
/* @0x196d94 mov r2, r6 */
/* @0x196d98 mov r1, #8 */
/* @0x196d9c mov r0, r9 */
/* @0x196da0 vstr s14, [r9, #44] */
/* @0x196da4 vstr s15, [r9, #48] */
/* @0x196da8 ldr r3, [r3, #0x8] */
/* @0x196dac blx r3 */   —— 写第 9 项（码 8）
/* @0x196db0 vldr s14, [r7, #164] */   —— +0x0a4 image_alpha
/* @0x196db4 vcvt.f64.f32 d7, s14 */
/* @0x196db8 ldr r3, [r9] */
/* @0x196dbc str r5, [r9, #0x38] */
/* @0x196dc0 mov r2, r6 */
/* @0x196dc4 mov r1, #8 */
/* @0x196dc8 mov r0, r9 */
/* @0x196dcc vstr s14, [r9, #44] */
/* @0x196dd0 vstr s15, [r9, #48] */
/* @0x196dd4 ldr r3, [r3, #0x8] */
/* @0x196dd8 blx r3 */   —— 写第 10 项（码 8）

/* ── 6. 第 11 项：image_blend（码 5，uint32；全函数唯一的码 5）→ +0x0a8 ── */
/* @0x196ddc vldr s14, [r7, #168] */   —— +0x0a8 image_blend（uint32 位模式）
/* @0x196de0 vcvt.f64.u32 d7, s14 */
/* @0x196de4 ldr r3, [r9] */
/* @0x196de8 mov r2, r6 */
/* @0x196dec str r5, [r9, #0x38] */
/* @0x196df0 mov r1, #5 */
/* @0x196df4 mov r0, r9 */
/* @0x196df8 vstr s14, [r9, #44] */
/* @0x196dfc vstr s15, [r9, #48] */
/* @0x196e00 ldr r3, [r3, #0x8] */
/* @0x196e04 blx r3 */   —— 写第 11 项（码 5）

/* ── 7. 第 12 项：mask_index（码 6）→ +0x0ac ── */
/* @0x196e08 vldr s14, [r7, #172] */   —— +0x0ac mask_index
/* @0x196e0c vcvt.f64.s32 d7, s14 */
/* @0x196e10 ldr r3, [r9] */
/* @0x196e14 mov r2, r6 */
/* @0x196e18 str r5, [r9, #0x38] */
/* @0x196e1c mov r1, #6 */
/* @0x196e20 mov r0, r9 */
/* @0x196e24 vstr s14, [r9, #44] */
/* @0x196e28 vstr s15, [r9, #48] */
/* @0x196e2c ldr r3, [r3, #0x8] */
/* @0x196e30 blx r3 */   —— 写第 12 项（码 6）

/* ── 8. 第 13 项：depth（码 8，f32）→ +0x180；★ 流序在这里跳偏移：mask(0xac) 之后直接跳 0x180 ── */
/* @0x196e34 vldr s14, [r7, #384] */   —— ★ 源 0x180 depth（f32，跳偏移）
/* @0x196e38 vcvt.f64.f32 d7, s14 */
/* @0x196e3c ldr r3, [r9] */
/* @0x196e40 str r5, [r9, #0x38] */
/* @0x196e44 mov r2, r6 */
/* @0x196e48 mov r1, #8 */
/* @0x196e4c mov r0, r9 */
/* @0x196e50 vstr s14, [r9, #44] */
/* @0x196e54 vstr s15, [r9, #48] */
/* @0x196e58 ldr r3, [r3, #0x8] */
/* @0x196e5c blx r3 */   —— 写第 13 项（码 8）

/* ── 9. 第 14 项：+0x0b0（码 6，字节）—— Compute_BoundingBox 从 spr+0x30 抄来的缓存字节 ── */
/* @0x196e60 ldrb r12, [r7, #0xb0] */   —— +0x0b0（ldrb → vcvt.u32）
/* @0x196e64 ldr r3, [r9] */
/* @0x196e68 mov r2, r6 */
/* @0x196e6c str r5, [r9, #0x38] */
/* @0x196e70 mov r1, #6 */
/* @0x196e74 vmov s14, r12 */
/* @0x196e78 mov r0, r9 */
/* @0x196e7c vcvt.f64.u32 d7, s14 */
/* @0x196e80 vstr s14, [r9, #44] */
/* @0x196e84 vstr s15, [r9, #48] */
/* @0x196e88 ldr r3, [r3, #0x8] */
/* @0x196e8c blx r3 */   —— 写第 14 项（码 6）

/* ── 10. 第 15..27 项：位置/运动学 13 项（码 8，f32）
 *    +0x0b4 x / +0x0b8 y / +0x0bc xstart / +0x0c0 ystart / +0x0c4 xprevious / +0x0c8 yprevious /
 *    +0x0cc direction / +0x0d0 speed / +0x0d4 friction / +0x0d8 gravity_direction / +0x0dc gravity /
 *    +0x0e0 hspeed / +0x0e4 vspeed ── */
/* @0x196e90 vldr s14, [r7, #180] */   —— +0x0b4 x
/* @0x196e94 vcvt.f64.f32 d7, s14 */
/* @0x196e98 ldr r3, [r9] */
/* @0x196e9c str r5, [r9, #0x38] */
/* @0x196ea0 mov r2, r6 */
/* @0x196ea4 mov r1, #8 */
/* @0x196ea8 mov r0, r9 */
/* @0x196eac vstr s14, [r9, #44] */
/* @0x196eb0 vstr s15, [r9, #48] */
/* @0x196eb4 ldr r3, [r3, #0x8] */
/* @0x196eb8 blx r3 */   —— 写第 15 项（码 8）
/* @0x196ebc vldr s14, [r7, #184] */   —— +0x0b8 y
/* @0x196ec0 vcvt.f64.f32 d7, s14 */
/* @0x196ec4 ldr r3, [r9] */
/* @0x196ec8 str r5, [r9, #0x38] */
/* @0x196ecc mov r2, r6 */
/* @0x196ed0 mov r1, #8 */
/* @0x196ed4 mov r0, r9 */
/* @0x196ed8 vstr s14, [r9, #44] */
/* @0x196edc vstr s15, [r9, #48] */
/* @0x196ee0 ldr r3, [r3, #0x8] */
/* @0x196ee4 blx r3 */   —— 写第 16 项（码 8）
/* @0x196ee8 vldr s14, [r7, #188] */   —— +0x0bc xstart
/* @0x196eec vcvt.f64.f32 d7, s14 */
/* @0x196ef0 ldr r3, [r9] */
/* @0x196ef4 str r5, [r9, #0x38] */
/* @0x196ef8 mov r2, r6 */
/* @0x196efc mov r1, #8 */
/* @0x196f00 mov r0, r9 */
/* @0x196f04 vstr s14, [r9, #44] */
/* @0x196f08 vstr s15, [r9, #48] */
/* @0x196f0c ldr r3, [r3, #0x8] */
/* @0x196f10 blx r3 */   —— 写第 17 项（码 8）
/* @0x196f14 vldr s14, [r7, #192] */   —— +0x0c0 ystart
/* @0x196f18 vcvt.f64.f32 d7, s14 */
/* @0x196f1c ldr r3, [r9] */
/* @0x196f20 str r5, [r9, #0x38] */
/* @0x196f24 mov r2, r6 */
/* @0x196f28 mov r1, #8 */
/* @0x196f2c mov r0, r9 */
/* @0x196f30 vstr s14, [r9, #44] */
/* @0x196f34 vstr s15, [r9, #48] */
/* @0x196f38 ldr r3, [r3, #0x8] */
/* @0x196f3c blx r3 */   —— 写第 18 项（码 8）
/* @0x196f40 vldr s14, [r7, #196] */   —— +0x0c4 xprevious
/* @0x196f44 vcvt.f64.f32 d7, s14 */
/* @0x196f48 ldr r3, [r9] */
/* @0x196f4c str r5, [r9, #0x38] */
/* @0x196f50 mov r2, r6 */
/* @0x196f54 mov r1, #8 */
/* @0x196f58 mov r0, r9 */
/* @0x196f5c vstr s14, [r9, #44] */
/* @0x196f60 vstr s15, [r9, #48] */
/* @0x196f64 ldr r3, [r3, #0x8] */
/* @0x196f68 blx r3 */   —— 写第 19 项（码 8）
/* @0x196f6c vldr s14, [r7, #200] */   —— +0x0c8 yprevious
/* @0x196f70 vcvt.f64.f32 d7, s14 */
/* @0x196f74 ldr r3, [r9] */
/* @0x196f78 str r5, [r9, #0x38] */
/* @0x196f7c mov r2, r6 */
/* @0x196f80 mov r1, #8 */
/* @0x196f84 mov r0, r9 */
/* @0x196f88 vstr s14, [r9, #44] */
/* @0x196f8c vstr s15, [r9, #48] */
/* @0x196f90 ldr r3, [r3, #0x8] */
/* @0x196f94 blx r3 */   —— 写第 20 项（码 8）
/* @0x196f98 vldr s14, [r7, #204] */   —— +0x0cc direction
/* @0x196f9c vcvt.f64.f32 d7, s14 */
/* @0x196fa0 ldr r3, [r9] */
/* @0x196fa4 str r5, [r9, #0x38] */
/* @0x196fa8 mov r2, r6 */
/* @0x196fac mov r1, #8 */
/* @0x196fb0 mov r0, r9 */
/* @0x196fb4 vstr s14, [r9, #44] */
/* @0x196fb8 vstr s15, [r9, #48] */
/* @0x196fbc ldr r3, [r3, #0x8] */
/* @0x196fc0 blx r3 */   —— 写第 21 项（码 8）
/* @0x196fc4 vldr s14, [r7, #208] */   —— +0x0d0 speed
/* @0x196fc8 vcvt.f64.f32 d7, s14 */
/* @0x196fcc ldr r3, [r9] */
/* @0x196fd0 str r5, [r9, #0x38] */
/* @0x196fd4 mov r2, r6 */
/* @0x196fd8 mov r1, #8 */
/* @0x196fdc mov r0, r9 */
/* @0x196fe0 vstr s14, [r9, #44] */
/* @0x196fe4 vstr s15, [r9, #48] */
/* @0x196fe8 ldr r3, [r3, #0x8] */
/* @0x196fec blx r3 */   —— 写第 22 项（码 8）
/* @0x196ff0 vldr s14, [r7, #212] */   —— +0x0d4 friction
/* @0x196ff4 vcvt.f64.f32 d7, s14 */
/* @0x196ff8 ldr r3, [r9] */
/* @0x196ffc str r5, [r9, #0x38] */
/* @0x197000 mov r2, r6 */
/* @0x197004 mov r1, #8 */
/* @0x197008 mov r0, r9 */
/* @0x19700c vstr s14, [r9, #44] */
/* @0x197010 vstr s15, [r9, #48] */
/* @0x197014 ldr r3, [r3, #0x8] */
/* @0x197018 blx r3 */   —— 写第 23 项（码 8）
/* @0x19701c vldr s14, [r7, #216] */   —— +0x0d8 gravity_direction
/* @0x197020 vcvt.f64.f32 d7, s14 */
/* @0x197024 ldr r3, [r9] */
/* @0x197028 str r5, [r9, #0x38] */
/* @0x19702c mov r2, r6 */
/* @0x197030 mov r1, #8 */
/* @0x197034 mov r0, r9 */
/* @0x197038 vstr s14, [r9, #44] */
/* @0x19703c vstr s15, [r9, #48] */
/* @0x197040 ldr r3, [r3, #0x8] */
/* @0x197044 blx r3 */   —— 写第 24 项（码 8）
/* @0x197048 vldr s14, [r7, #220] */   —— +0x0dc gravity
/* @0x19704c vcvt.f64.f32 d7, s14 */
/* @0x197050 ldr r3, [r9] */
/* @0x197054 str r5, [r9, #0x38] */
/* @0x197058 mov r2, r6 */
/* @0x19705c mov r1, #8 */
/* @0x197060 mov r0, r9 */
/* @0x197064 vstr s14, [r9, #44] */
/* @0x197068 vstr s15, [r9, #48] */
/* @0x19706c ldr r3, [r3, #0x8] */
/* @0x197070 blx r3 */   —— 写第 25 项（码 8）
/* @0x197074 vldr s14, [r7, #224] */   —— +0x0e0 hspeed
/* @0x197078 vcvt.f64.f32 d7, s14 */
/* @0x19707c ldr r3, [r9] */
/* @0x197080 str r5, [r9, #0x38] */
/* @0x197084 mov r2, r6 */
/* @0x197088 mov r1, #8 */
/* @0x19708c mov r0, r9 */
/* @0x197090 vstr s14, [r9, #44] */
/* @0x197094 vstr s15, [r9, #48] */
/* @0x197098 ldr r3, [r3, #0x8] */
/* @0x19709c blx r3 */   —— 写第 26 项（码 8）
/* @0x1970a0 vldr s14, [r7, #228] */   —— +0x0e4 vspeed
/* @0x1970a4 vcvt.f64.f32 d7, s14 */
/* @0x1970a8 ldr r3, [r9] */
/* @0x1970ac str r5, [r9, #0x38] */
/* @0x1970b0 mov r2, r6 */
/* @0x1970b4 mov r1, #8 */
/* @0x1970b8 mov r0, r9 */
/* @0x1970bc vstr s14, [r9, #44] */
/* @0x1970c0 vstr s15, [r9, #48] */
/* @0x1970c4 ldr r3, [r3, #0x8] */
/* @0x1970c8 blx r3 */   —— 写第 27 项（码 8）

/* ── 11. 第 28..31 项：bbox 四条边（码 6，int）—— 次序是 left(0xe8), right(0xf0), top(0xec), bottom(0xf4)
 *    不是 L,T,R,B，也不是升序：这条次序是格式的一部分，读侧同样按 e8,f0,ec,f4 落盘 ── */
/* @0x1970cc vldr s14, [r7, #232] */   —— +0x0e8 bbox.left（int）
/* @0x1970d0 vcvt.f64.s32 d7, s14 */
/* @0x1970d4 ldr r3, [r9] */
/* @0x1970d8 mov r2, r6 */
/* @0x1970dc str r5, [r9, #0x38] */
/* @0x1970e0 mov r1, #6 */
/* @0x1970e4 mov r0, r9 */
/* @0x1970e8 vstr s14, [r9, #44] */
/* @0x1970ec vstr s15, [r9, #48] */
/* @0x1970f0 ldr r3, [r3, #0x8] */
/* @0x1970f4 blx r3 */   —— 写第 28 项（码 6）
/* @0x1970f8 vldr s14, [r7, #240] */   —— ★ +0x0f0 bbox.right —— right 在 top 之前
/* @0x1970fc vcvt.f64.s32 d7, s14 */
/* @0x197100 ldr r3, [r9] */
/* @0x197104 mov r2, r6 */
/* @0x197108 str r5, [r9, #0x38] */
/* @0x19710c mov r1, #6 */
/* @0x197110 mov r0, r9 */
/* @0x197114 vstr s14, [r9, #44] */
/* @0x197118 vstr s15, [r9, #48] */
/* @0x19711c ldr r3, [r3, #0x8] */
/* @0x197120 blx r3 */   —— 写第 29 项（码 6）
/* @0x197124 vldr s14, [r7, #236] */   —— +0x0ec bbox.top
/* @0x197128 vcvt.f64.s32 d7, s14 */
/* @0x19712c ldr r3, [r9] */
/* @0x197130 mov r2, r6 */
/* @0x197134 str r5, [r9, #0x38] */
/* @0x197138 mov r1, #6 */
/* @0x19713c mov r0, r9 */
/* @0x197140 vstr s14, [r9, #44] */
/* @0x197144 vstr s15, [r9, #48] */
/* @0x197148 ldr r3, [r3, #0x8] */
/* @0x19714c blx r3 */   —— 写第 30 项（码 6）
/* @0x197150 vldr s14, [r7, #244] */   —— +0x0f4 bbox.bottom
/* @0x197154 vcvt.f64.s32 d7, s14 */
/* @0x197158 ldr r3, [r9] */
/* @0x19715c mov r2, r6 */
/* @0x197160 str r5, [r9, #0x38] */
/* @0x197164 mov r1, #6 */
/* @0x197168 mov r0, r9 */
/* @0x19716c vstr s14, [r9, #44] */
/* @0x197170 vstr s15, [r9, #48] */
/* @0x197174 ldr r3, [r3, #0x8] */
/* @0x197178 blx r3 */   —— 写第 31 项（码 6）

/* ── 12. 第 32..34 项：visible / solid / persistent（码 6，各一字节）→ +0x065/+0x066/+0x067 ── */
/* @0x19717c ldrb r3, [r7, #0x65] */   —— +0x065 visible（ldrb）
/* @0x197180 mov r2, r6 */
/* @0x197184 str r5, [r9, #0x38] */
/* @0x197188 mov r1, #6 */
/* @0x19718c mov r0, r9 */
/* @0x197190 vmov s14, r3 */
/* @0x197194 ldr r3, [r9] */
/* @0x197198 vcvt.f64.u32 d7, s14 */
/* @0x19719c vstr s14, [r9, #44] */
/* @0x1971a0 vstr s15, [r9, #48] */
/* @0x1971a4 ldr r3, [r3, #0x8] */
/* @0x1971a8 blx r3 */   —— 写第 32 项（码 6）
/* @0x1971ac ldrb r12, [r7, #0x66] */   —— +0x066 solid（ldrb）
/* @0x1971b0 ldr r3, [r9] */
/* @0x1971b4 mov r2, r6 */
/* @0x1971b8 str r5, [r9, #0x38] */
/* @0x1971bc mov r1, #6 */
/* @0x1971c0 vmov s14, r12 */
/* @0x1971c4 mov r0, r9 */
/* @0x1971c8 vcvt.f64.u32 d7, s14 */
/* @0x1971cc vstr s14, [r9, #44] */
/* @0x1971d0 vstr s15, [r9, #48] */
/* @0x1971d4 ldr r3, [r3, #0x8] */
/* @0x1971d8 blx r3 */   —— 写第 33 项（码 6）
/* @0x1971dc ldrb r4, [r7, #0x67] */   —— +0x067 persistent（ldrb）
/* @0x1971e0 str r5, [r9, #0x38] */
/* @0x1971e4 mov r2, r6 */
/* @0x1971e8 ldr r3, [r9] */
/* @0x1971ec mov r0, r9 */
/* @0x1971f0 vmov s13, r4 */
/* @0x1971f4 mov r1, #6 */
/* @0x1971f8 vcvt.f64.u32 d6, s13 */
/* @0x1971fc vmov r4, r5, d6 */
/* @0x197200 vstr s12, [r9, #44] */
/* @0x197204 str r5, [r9, #0x30] */
/* @0x197208 ldr r3, [r3, #0x8] */
/* @0x19720c blx r3 */   —— 写第 34 项（码 6）

/* ── 13. 第 35 项：alarm[0..11]（码 6）—— 单写点 12 次循环
 *    游标 r11 从 this 起（0x196c34），取 [r11+0xf8]，每轮 +4；r8 从 12 递减到 0；
 *    首轮落 +0x0f8、末轮落 +0x124。r8 归零后被后面复用成零常量（tag 清零）。── */
/* @0x197210 ldr r4, [r11, #0xf8] */   —— alarm 第 1 轮：r11 当前 = this
/* @0x197214 mov r0, r9 */
/* @0x197218 ldr r3, [r9] */
/* @0x19721c mov r1, #6 */
/* @0x197220 str r10, [r9, #0x38] */
/* @0x197224 mov r2, r6 */
/* @0x197228 vmov s15, r4 */
/* @0x19722c add r11, r11, #4 */   —— 游标 +4（下一轮 [r11+0xf8] = 本轮的 +0xfc）
/* @0x197230 vcvt.f64.s32 d7, s15 */
/* @0x197234 vmov r4, r5, d7 */
/* @0x197238 vstr s14, [r9, #44] */
/* @0x19723c str r5, [r9, #0x30] */
/* @0x197240 ldr r3, [r3, #0x8] */
/* @0x197244 blx r3 */   —— 写第 35 项（码 6）—— 循环体内，每轮一项（12 轮）
/* @0x197248 subs r8, r8, #1 */   —— 12 → 11 → ... → 0
/* @0x19724c bne 0x197210 <_ZN9CInstance9SerialiseEP7IBuffer+0x61c> */   —— 12 次后落 0 退出；此后 r8 被当零常量用

/* ── 14. 第 36 项：skip（码 6，字节）→ +0x068 ── */
/* @0x197250 ldrb r4, [r7, #0x68] */   —— +0x068 skip（ldrb）
/* @0x197254 mov r1, #6 */
/* @0x197258 ldr r3, [r9] */
/* @0x19725c mov r2, r6 */
/* @0x197260 mov r0, r9 */
/* @0x197264 str r8, [r9, #0x38] */
/* @0x197268 vmov s13, r4 */
/* @0x19726c vcvt.f64.u32 d6, s13 */
/* @0x197270 vmov r4, r5, d6 */
/* @0x197274 vstr s12, [r9, #44] */
/* @0x197278 str r5, [r9, #0x30] */
/* @0x19727c ldr r3, [r3, #0x8] */
/* @0x197280 blx r3 */   —— 写第 36 项（码 6）

/* ── 15. 第 37 项：path_index（码 6）→ +0x128 ── */
/* @0x197284 ldr r4, [r7, #0x128] */   —— +0x128 path_index（ldr）
/* @0x197288 ldr r3, [r9] */
/* @0x19728c mov r1, #6 */
/* @0x197290 mov r2, r6 */
/* @0x197294 mov r0, r9 */
/* @0x197298 vmov s15, r4 */
/* @0x19729c str r8, [r9, #0x38] */
/* @0x1972a0 vcvt.f64.s32 d7, s15 */
/* @0x1972a4 vmov r4, r5, d7 */
/* @0x1972a8 vstr s14, [r9, #44] */
/* @0x1972ac str r5, [r9, #0x30] */
/* @0x1972b0 ldr r3, [r3, #0x8] */
/* @0x1972b4 blx r3 */   —— 写第 37 项（码 6）

/* ── 16. 第 38..42 项：path 浮点组（码 8）：+0x12c path_position / +0x130 path_positionprevious /
 *    +0x134 path_speed / +0x138 path_scale / +0x13c path_orientation ── */
/* @0x1972b8 vldr s15, [r7, #300] */   —— +0x12c path_position
/* @0x1972bc vcvt.f64.f32 d6, s15 */
/* @0x1972c0 ldr r3, [r9] */
/* @0x1972c4 mov r1, #8 */
/* @0x1972c8 mov r2, r6 */
/* @0x1972cc str r8, [r9, #0x38] */
/* @0x1972d0 mov r0, r9 */
/* @0x1972d4 vmov r4, r5, d6 */
/* @0x1972d8 vstr s12, [r9, #44] */
/* @0x1972dc str r5, [r9, #0x30] */
/* @0x1972e0 ldr r3, [r3, #0x8] */
/* @0x1972e4 blx r3 */   —— 写第 38 项（码 8）
/* @0x1972e8 vldr s15, [r7, #304] */   —— +0x130 path_positionprevious
/* @0x1972ec vcvt.f64.f32 d6, s15 */
/* @0x1972f0 ldr r3, [r9] */
/* @0x1972f4 mov r1, #8 */
/* @0x1972f8 mov r2, r6 */
/* @0x1972fc str r8, [r9, #0x38] */
/* @0x197300 mov r0, r9 */
/* @0x197304 vmov r4, r5, d6 */
/* @0x197308 vstr s12, [r9, #44] */
/* @0x19730c str r5, [r9, #0x30] */
/* @0x197310 ldr r3, [r3, #0x8] */
/* @0x197314 blx r3 */   —— 写第 39 项（码 8）
/* @0x197318 vldr s15, [r7, #308] */   —— +0x134 path_speed
/* @0x19731c vcvt.f64.f32 d6, s15 */
/* @0x197320 ldr r3, [r9] */
/* @0x197324 mov r1, #8 */
/* @0x197328 mov r2, r6 */
/* @0x19732c str r8, [r9, #0x38] */
/* @0x197330 mov r0, r9 */
/* @0x197334 vmov r4, r5, d6 */
/* @0x197338 vstr s12, [r9, #44] */
/* @0x19733c str r5, [r9, #0x30] */
/* @0x197340 ldr r3, [r3, #0x8] */
/* @0x197344 blx r3 */   —— 写第 40 项（码 8）
/* @0x197348 vldr s15, [r7, #312] */   —— +0x138 path_scale
/* @0x19734c vcvt.f64.f32 d6, s15 */
/* @0x197350 ldr r3, [r9] */
/* @0x197354 mov r1, #8 */
/* @0x197358 mov r2, r6 */
/* @0x19735c str r8, [r9, #0x38] */
/* @0x197360 mov r0, r9 */
/* @0x197364 vmov r4, r5, d6 */
/* @0x197368 vstr s12, [r9, #44] */
/* @0x19736c str r5, [r9, #0x30] */
/* @0x197370 ldr r3, [r3, #0x8] */
/* @0x197374 blx r3 */   —— 写第 41 项（码 8）
/* @0x197378 vldr s15, [r7, #316] */   —— +0x13c path_orientation
/* @0x19737c vcvt.f64.f32 d6, s15 */
/* @0x197380 ldr r3, [r9] */
/* @0x197384 mov r1, #8 */
/* @0x197388 mov r2, r6 */
/* @0x19738c str r8, [r9, #0x38] */
/* @0x197390 mov r0, r9 */
/* @0x197394 vmov r4, r5, d6 */
/* @0x197398 vstr s12, [r9, #44] */
/* @0x19739c str r5, [r9, #0x30] */
/* @0x1973a0 ldr r3, [r3, #0x8] */
/* @0x1973a4 blx r3 */   —— 写第 42 项（码 8）

/* ── 17. 第 43 项：path_endaction（码 6）→ +0x140 ── */
/* @0x1973a8 ldr r4, [r7, #0x140] */   —— +0x140 path_endaction（ldr）
/* @0x1973ac ldr r3, [r9] */
/* @0x1973b0 mov r1, #6 */
/* @0x1973b4 mov r2, r6 */
/* @0x1973b8 mov r0, r9 */
/* @0x1973bc vmov s15, r4 */
/* @0x1973c0 str r8, [r9, #0x38] */
/* @0x1973c4 vcvt.f64.s32 d7, s15 */
/* @0x1973c8 vmov r4, r5, d7 */
/* @0x1973cc vstr s14, [r9, #44] */
/* @0x1973d0 str r5, [r9, #0x30] */
/* @0x1973d4 ldr r3, [r3, #0x8] */
/* @0x1973d8 blx r3 */   —— 写第 43 项（码 6）

/* ── 18. 第 44..45 项：+0x144 / +0x148（码 8，f32）—— 语义名未定，但两侧都按 f32 存取 ── */
/* @0x1973dc vldr s15, [r7, #324] */   —— +0x144（未定①，f32）
/* @0x1973e0 vcvt.f64.f32 d6, s15 */
/* @0x1973e4 ldr r3, [r9] */
/* @0x1973e8 mov r1, #8 */
/* @0x1973ec mov r2, r6 */
/* @0x1973f0 str r8, [r9, #0x38] */
/* @0x1973f4 mov r0, r9 */
/* @0x1973f8 vmov r4, r5, d6 */
/* @0x1973fc vstr s12, [r9, #44] */
/* @0x197400 str r5, [r9, #0x30] */
/* @0x197404 ldr r3, [r3, #0x8] */
/* @0x197408 blx r3 */   —— 写第 44 项（码 8）
/* @0x19740c vldr s15, [r7, #328] */   —— +0x148（未定②，f32）
/* @0x197410 vcvt.f64.f32 d6, s15 */
/* @0x197414 ldr r3, [r9] */
/* @0x197418 mov r1, #8 */
/* @0x19741c mov r2, r6 */
/* @0x197420 str r8, [r9, #0x38] */
/* @0x197424 mov r0, r9 */
/* @0x197428 vmov r4, r5, d6 */
/* @0x19742c vstr s12, [r9, #44] */
/* @0x197430 str r5, [r9, #0x30] */
/* @0x197434 ldr r3, [r3, #0x8] */
/* @0x197438 blx r3 */   —— 写第 45 项（码 8）

/* ── 19. 第 46 项：timeline_index（码 6）→ +0x14c ── */
/* @0x19743c ldr r4, [r7, #0x14c] */   —— +0x14c timeline_index（ldr）
/* @0x197440 ldr r3, [r9] */
/* @0x197444 mov r1, #6 */
/* @0x197448 mov r2, r6 */
/* @0x19744c mov r0, r9 */
/* @0x197450 vmov s15, r4 */
/* @0x197454 str r8, [r9, #0x38] */
/* @0x197458 vcvt.f64.s32 d7, s15 */
/* @0x19745c vmov r4, r5, d7 */
/* @0x197460 vstr s14, [r9, #44] */
/* @0x197464 str r5, [r9, #0x30] */
/* @0x197468 ldr r3, [r3, #0x8] */
/* @0x19746c blx r3 */   —— 写第 46 项（码 6）

/* ── 20. 第 47..49 项：timeline 浮点组（码 8）：+0x150（未定）/ +0x154 timeline_position /
 *    +0x158 timeline_speed ── */
/* @0x197470 vldr s15, [r7, #336] */   —— +0x150（未定③，f32）
/* @0x197474 vcvt.f64.f32 d6, s15 */
/* @0x197478 ldr r3, [r9] */
/* @0x19747c mov r1, #8 */
/* @0x197480 mov r2, r6 */
/* @0x197484 str r8, [r9, #0x38] */
/* @0x197488 mov r0, r9 */
/* @0x19748c vmov r4, r5, d6 */
/* @0x197490 vstr s12, [r9, #44] */
/* @0x197494 str r5, [r9, #0x30] */
/* @0x197498 ldr r3, [r3, #0x8] */
/* @0x19749c blx r3 */   —— 写第 47 项（码 8）
/* @0x1974a0 vldr s15, [r7, #340] */   —— +0x154 timeline_position
/* @0x1974a4 vcvt.f64.f32 d6, s15 */
/* @0x1974a8 ldr r3, [r9] */
/* @0x1974ac mov r1, #8 */
/* @0x1974b0 mov r2, r6 */
/* @0x1974b4 str r8, [r9, #0x38] */
/* @0x1974b8 mov r0, r9 */
/* @0x1974bc vmov r4, r5, d6 */
/* @0x1974c0 vstr s12, [r9, #44] */
/* @0x1974c4 str r5, [r9, #0x30] */
/* @0x1974c8 ldr r3, [r3, #0x8] */
/* @0x1974cc blx r3 */   —— 写第 48 项（码 8）
/* @0x1974d0 vldr s15, [r7, #344] */   —— +0x158 timeline_speed
/* @0x1974d4 vcvt.f64.f32 d6, s15 */
/* @0x1974d8 ldr r3, [r9] */
/* @0x1974dc mov r1, #8 */
/* @0x1974e0 mov r2, r6 */
/* @0x1974e4 str r8, [r9, #0x38] */
/* @0x1974e8 mov r0, r9 */
/* @0x1974ec vmov r4, r5, d6 */
/* @0x1974f0 vstr s12, [r9, #44] */
/* @0x1974f4 str r5, [r9, #0x30] */
/* @0x1974f8 ldr r3, [r3, #0x8] */
/* @0x1974fc blx r3 */   —— 写第 49 项（码 8）

/* ── 21. 第 50..52 项：timeline 布尔组（码 6，各一字节）：+0x15c timeline_running /
 *    +0x15d timeline_loop / +0x15e（未定）── */
/* @0x197500 ldrb r4, [r7, #0x15c] */   —— +0x15c timeline_running（ldrb）
/* @0x197504 ldr r3, [r9] */
/* @0x197508 mov r1, #6 */
/* @0x19750c mov r2, r6 */
/* @0x197510 mov r0, r9 */
/* @0x197514 vmov s15, r4 */
/* @0x197518 str r8, [r9, #0x38] */
/* @0x19751c vcvt.f64.u32 d7, s15 */
/* @0x197520 vmov r4, r5, d7 */
/* @0x197524 vstr s14, [r9, #44] */
/* @0x197528 str r5, [r9, #0x30] */
/* @0x19752c ldr r3, [r3, #0x8] */
/* @0x197530 blx r3 */   —— 写第 50 项（码 6）
/* @0x197534 ldrb r4, [r7, #0x15d] */   —— +0x15d timeline_loop（ldrb）
/* @0x197538 ldr r3, [r9] */
/* @0x19753c mov r1, #6 */
/* @0x197540 mov r2, r6 */
/* @0x197544 mov r0, r9 */
/* @0x197548 vmov s13, r4 */
/* @0x19754c str r8, [r9, #0x38] */
/* @0x197550 vcvt.f64.u32 d6, s13 */
/* @0x197554 vmov r4, r5, d6 */
/* @0x197558 vstr s12, [r9, #44] */
/* @0x19755c str r5, [r9, #0x30] */
/* @0x197560 ldr r3, [r3, #0x8] */
/* @0x197564 blx r3 */   —— 写第 51 项（码 6）
/* @0x197568 ldrb r4, [r7, #0x15e] */   —— +0x15e（未定④，ldrb）
/* @0x19756c ldr r3, [r9] */
/* @0x197570 mov r1, #6 */
/* @0x197574 mov r2, r6 */
/* @0x197578 mov r0, r9 */
/* @0x19757c vmov s15, r4 */
/* @0x197580 str r8, [r9, #0x38] */
/* @0x197584 vcvt.f64.u32 d7, s15 */
/* @0x197588 vmov r4, r5, d7 */
/* @0x19758c vstr s14, [r9, #44] */
/* @0x197590 str r5, [r9, #0x30] */
/* @0x197594 ldr r3, [r3, #0x8] */
/* @0x197598 blx r3 */   —— 写第 52 项（码 6）

/* ── 22. 第 53 项：layer（码 6）→ +0x170 ── */
/* @0x19759c ldr r4, [r7, #0x170] */   —— +0x170 layer（ldr）
/* @0x1975a0 ldr r3, [r9] */
/* @0x1975a4 mov r0, r9 */
/* @0x1975a8 str r8, [r9, #0x38] */
/* @0x1975ac mov r1, #6 */
/* @0x1975b0 vmov s13, r4 */
/* @0x1975b4 mov r2, r6 */
/* @0x1975b8 vcvt.f64.s32 d6, s13 */
/* @0x1975bc vmov r4, r5, d6 */
/* @0x1975c0 vstr s12, [r9, #44] */
/* @0x1975c4 str r5, [r9, #0x30] */
/* @0x1975c8 ldr r3, [r3, #0x8] */
/* @0x1975cc blx r3 */   —— 写第 53 项（码 6）
/* @0x1975d0 ldr r3, [r7, #0x24] */   —— ★ 门：*(int*)(this+0x24)（基类变量槽计数）
/* @0x1975d4 cmp r3, #0 */
/* @0x1975d8 popeq {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */   —— 为 0 ⇒ 连个数都不写，直接返回（第 1 处出口）

/* ── 23. 第 54 项：变量个数 —— 门 + 全局计数 + 写流
 *    先看 *(int*)(this+0x24)（基类变量槽计数）：为 0 ⇒ 直接 pop（连个数都不写，与读侧同形）；
 *    否则把**全局** *(int*)0x544b48 当个数写进去（GOT 0x3EDD1C，literal 在 0x197668）。── */
/* @0x1975dc ldr r10, [pc, #0x84] */   —— ★ 全局计数的 GOT 偏移（literal 0x197668 = 0x00256728）
/* @0x1975e0 mov r2, r6 */
/* @0x1975e4 ldr r3, [r9] */
/* @0x1975e8 mov r0, r9 */
/* @0x1975ec ldr r10, [pc, r10] */   —— → GOT 0x3EDD1C
/* @0x1975f0 vldr s15, [r10] */   —— → *(int*)0x544b48（与基类构造第 1 实参、读侧 warning 的比较对象同一个全局）
/* @0x1975f4 vcvt.f64.s32 d7, s15 */   —— int → double
/* @0x1975f8 str r8, [r9, #0x38] */   —— 清 tag（r8 此刻 = 0）
/* @0x1975fc mov r1, #6 */
/* @0x197600 vmov r4, r5, d7 */
/* @0x197604 vstr s14, [r9, #44] */
/* @0x197608 str r5, [r9, #0x30] */
/* @0x19760c ldr r3, [r3, #0x8] */
/* @0x197610 blx r3 */   —— 写第 54 项（码 6）= 变量个数
/* @0x197614 ldr r3, [r10] */   —— 再读一次全局当循环上限（不缓存）
/* @0x197618 cmp r3, #0 */
/* @0x19761c pople {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */   —— 计数 0 ⇒ 返回（第 2 处出口）
/* @0x197620 ldr r0, [r7, #0x4] */   —— ★ 槽基址 = *(int**)(this+0x04)
/* @0x197624 cmp r0, #0 */
/* @0x197628 add r0, r0, r8, lsl #4 */   —— RValue* = base + i*16（每槽 16 B）
/* @0x19762c beq 0x197658 <_ZN9CInstance9SerialiseEP7IBuffer+0xa64> */   —— base == 0 ⇒ 走 InternalGetYYVar
/* @0x197630 mov r1, r9 */   —— r1 = buf
/* @0x197634 add r8, r8, #1 */   —— i++（先加后判 ⇒ 循环条件写成 count > i+1）
/* @0x197638 bl 0xcf47c <_ZN6RValue9SerialiseEP7IBuffer> */   —— RValue::Serialise(槽, buf)（直调 0xcf47c）
/* @0x19763c ldr r3, [r10] */   —— 重新读全局计数
/* @0x197640 cmp r3, r8 */
/* @0x197644 bgt 0x197620 <_ZN9CInstance9SerialiseEP7IBuffer+0xa2c> */   —— count > i+1 ⇒ 继续
/* @0x197648 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */   —— 第 3 处出口（循环走完）

/* ── 24. 脏标记分支（out-of-line，0x19764c..0x197654）：唯一会改 this 的路径
 *    r1 = 1 ⇒ updateRTree = true ⇒ Compute_BoundingBox 里还会 CollisionUpdate（先按旧盒摘 RTree、
 *    再按新盒插入）。返回后 b 0x196c0c，从第 1 项开始写 —— 所以脏实例存盘时，写进流的 bbox 四边
 *    与 +0x0b0 是**刚重算过**的值，而不是调用前内存里的旧值。── */
/* @0x19764c mov r1, #1 */   —— ★ 脏分支：Compute_BoundingBox(true)
/* @0x197650 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */   —— 全函数唯一改 this 的调用
/* @0x197654 b 0x196c0c <_ZN9CInstance9SerialiseEP7IBuffer+0x18> */   —— 回主线，开始写第 1 项

/* ── 25. base == 0 分支（out-of-line，0x197658..0x197664）：槽地址改由基类算
 *    YYObjectBase::InternalGetYYVar(this, i) 的返回值就是该槽的 RValue*；回来仍走 0x197630 的
 *     mov r1,r9 / add r8,r8,#1 / bl RValue::Serialise。── */
/* @0x197658 mov r0, r7 */   —— r0 = this
/* @0x19765c mov r1, r8 */   —— r1 = i
/* @0x197660 bl 0x196a70 <_ZN12YYObjectBase16InternalGetYYVarEi> */   —— YYObjectBase::InternalGetYYVar(this, i)
/* @0x197664 b 0x197630 <_ZN9CInstance9SerialiseEP7IBuffer+0xa3c> */   —— 回 0x197630（i++ 与调用）

/* ── 26. literal pool（1 字，objdump 当指令译出，**非指令**）──────────────
 *    0x197668 = 0x00256728 → 0x1975ec 处 +pc 得 GOT 0x3EDD1C（取 *(int*)0x544b48 用）。
 *    函数到此结束；0x19766c 起是 CInstance::DeSerialise。── */
/* @0x197668 eoreq r6, r5, r8, lsr #14 */   —— 0x00256728 = GOT 偏移（不是指令）
