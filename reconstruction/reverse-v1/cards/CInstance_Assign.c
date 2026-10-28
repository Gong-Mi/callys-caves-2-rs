/* cally 逆向卡：CInstance::Assign(CInstance*, bool)（原版 libyoyo.so，armv7）
 * @func 0x1986ec 0x198dac  size 1728  432 条（429 条指令 + 3 字 literal pool 0x198cac..0x198cb4，
 *       池夹在代码中间，objdump 会把它译成 svclo/andseq，**非指令**）
 * 级别: 正文（432/432 逐条落锚。三段字段拷贝、alarm 循环、对象链摘/挂、骨架深拷贝、变量哈希表
 *       深拷贝（含内联的插入探测与扩容）、碰撞脏标记冷路径逐条解出。
 *       未钉：RValue kind 3/8/11/14 的具体类型名、+0x0b0 的语义）
 * 符号: _ZN9CInstance6AssignEPS_b → void CInstance::Assign(CInstance* src, bool bAddToObject)
 * ABI : softfp；void；VFP 只用来算哈希表装载因子 (int)(cap * 0.6f)
 * 位置: CInstance::DeSerialise 0x19766c 之后；CInstance::~CInstance 0x199320 之前
 * 调用点（6 处，b 逐处核过）:
 *   0x109830  F_InstanceCopy(RValue&,CInstance*,CInstance*,int,RValue*) 0x1097ec —— r2=1
 *   0x1ad9ac  CRoom::Assign(CRoom*,bool) 0x1ad70c（第一段实例表）—— r2=0
 *   0x1add70  CRoom::Assign（第二段实例表）—— r2=0
 *   0x1d18b0  EndRoom(bool) 0x1d1724 —— r2=0
 *   0x1d3b34  StartRoom(int,bool) 0x1d38e0 —— r2=1
 *   0x1d3e64  StartRoom —— r2=1
 *   （两处 StartRoom 在 Assign 之后紧接 RebuildPhysicsBody 0x192fa4 —— 物理体不在拷贝范围内）
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   把一个已存在实例 src 的**状态**盖到 this 上：先把自己从旧对象实例链摘下，再抄 64 个标量槽
 *   （含 12 个 alarm），然后按需重建两张「拥有」的结构 —— +0x060 变量哈希表（新表头 + 新桶数组 +
 *   逐值 GetRValue）与 +0x088 骨架实例（new 52 B + 拷贝构造），最后可选把 this 挂进
 *   src->+0x080 那个 CObjectGM 的实例链。对象的**身份**（vtable、变量数组、实例表槽号、创建计数、
 *   三条侵入链、物理体）一律不动。
 *
 * ── 语义草案 ──────────────────────────────────────────────────────────────
 *   void CInstance::Assign(CInstance* src, bool bAddToObject) {
 *     if (this->object) { CObjectGM::RemoveInstance(this); this->object = 0; }   // +0x080
 *     // 第 1 段：26 个标量（实际 store 次序见下表）
 *     image_index=src->image_index; image_speed=...; image_angle=...; image_alpha=...;
 *     id=src->id; sprite_index=src->sprite_index; image_xscale/yscale=...; mask_index=...;
 *     [0xb0]=src->[0xb0]; [0x6b]=0;                            // ← 常量 0，不是抄来的
 *     x,y,xstart,ystart,xprevious,yprevious,image_blend=...; depth=src->depth;
 *     direction,speed,friction,gravity_direction,gravity,hspeed,vspeed=...;
 *     [0x64]=src->[0x64];
 *     if (src->hasObject) CollisionMarkDirty(this);              // 冷路径 0x198da0
 *     // 第 2 段：4 个 int + 3 个标志字节 + 对象解析结果
 *     [0xe8..0xf4]=src->...; visible/solid/persistent=...;
 *     object_index=src->object_index;                           // 原样抄，不查对象表
 *     object=src->object;                                       // CObjectGM* 指针浅拷贝
 *     if (bAddToObject && this->object) CObjectGM::AddInstance(this);
 *     for (i=0;i<12;i++) alarm[i]=src->alarm[i];
 *     // 第 3 段：变量表深拷贝
 *     if (src->varMap) {
 *       m = new(20);  m->cap=8; m->count=0; m->mask=7; m->threshold=(int)(8*0.6f);
 *       m->buckets = MemoryManager::Alloc(8*12, "…/MemoryManager.h", 70, 1); memset(m->buckets,0,96);
 *       for (each src bucket with hash>0) {
 *         RValue* nv = GetRValue();
 *         switch (srcValue->kind & 0x00FFFFFF) { ... 按 kind 拷载荷 ... }
 *         CHashMap<int,RValue*,3>::Insert(m, key, nv);           // 满了先扩容到 cap*2
 *       }
 *       this->varMap = m;                                        // +0x060
 *     }
 *     // 第 4 段：路径/时间线/骨架/layer
 *     [0x12c..0x140]=src->...; [0x128]=...; [0x14c]=...; [0x150..0x158]=...;
 *     [0x68]=src->[0x68]; [0x69]=src->[0x69]; [0x15c..0x15e]=...;
 *     [0x160]=src->[0x160]; [0x164]=src->[0x164];
 *     if (src->skeleton) { delete this->skeleton; this->skeleton = new CSkeletonInstance(src->skeleton); }
 *     [0x170]=src->[0x170];
 *   }
 *
 * ── 拷贝范围总表（按实际 store 次序；src 侧偏移 → this 侧同偏移）─────────────
 *   第 1 段（0x198728..0x198804，27 个落点，其中 +0x06b 写常量）
 *     +0x090 image_index      +0x094 image_speed    +0x078 id             +0x08c sprite_index
 *     +0x098 image_xscale     +0x09c image_yscale   +0x0a0 image_angle    +0x0ac mask_index
 *     +0x0b0（未定字节）      +0x06b ← 常量 0       +0x0b4 x              +0x0a8 image_blend
 *     +0x0b8 y                +0x0bc xstart         +0x0a4 image_alpha    +0x180 depth
 *     +0x0c0 ystart           +0x0c4 xprevious      +0x0c8 yprevious      +0x0cc direction
 *     +0x0d0 speed            +0x0d4 friction       +0x0d8 gravity_dir    +0x0dc gravity
 *     +0x0e0 hspeed           +0x0e4 vspeed         +0x064 标志字节
 *   第 2 段（0x198808..0x1988a0）
 *     +0x0e8 +0x0ec +0x0f0 +0x0f4（一条 ldr 预索引 + 三次 ldr 的 4 连抄）
 *     +0x065 visible  +0x066 solid  +0x067 persistent
 *     +0x07c object_index（原样抄）  +0x080 CObjectGM*（指针浅拷贝）
 *     optional CObjectGM::AddInstance(this)
 *     alarm[0..11]（12 轮循环，落点 0x0f8..0x124）
 *   第 4 段（0x198b9c..0x198ca0）
 *     +0x134 +0x12c +0x130 +0x138 +0x13c +0x140 +0x128 +0x14c +0x150 +0x154 +0x158
 *     +0x068 +0x069 +0x15c +0x15d +0x15e +0x160 +0x164
 *     +0x088 骨架（析构旧的 → new 52 + CSkeletonInstance 拷贝构造）
 *     +0x170 layer
 *   ⇒ 全函数 68 个 store 落点（第 1 段 27 + 第 2 段 9 + alarm 12 + 第 4 段 20）；不复制：+0x000 vtable、
 *      +0x004 变量数组、+0x044 实例表槽号、+0x048、
 *      +0x060（重建但指针本身是新表）、+0x06a/+0x06c、+0x070/+0x074 创建计数、+0x084 CPhysicsObject*、
 *      +0x144/+0x148、+0x168、+0x16c、+0x174、+0x178/+0x17c 房间链、+0x184 深度快照、
 *      +0x188..+0x1ac 碰撞/句柄三链。
 *
 * ── 深/浅拷贝边界（本卡最重要的一节）────────────────────────────────────
 *   【深：新分配】
 *     +0x060 变量哈希表 —— 表头 20 B（operator new）+ 桶数组 cap*12 B（MemoryManager::Alloc）全新
 *           分配，逐桶重插；旧表既不释放也不改（src 继续拥有它）。
 *     每个变量的 RValue —— GetRValue() 取新对象，再按 src 值的 kind 复制；kind 0/11/14 直接
 *           8 字节值拷贝，kind 1 给 [ptr+4] 加计数，kind 2 给 [ptr+0] 加计数并在 [ptr+8] 空时回填
 *           新 RValue，kind 7 走 DeterminePotentialRoot（登记为潜在根），kind 3/8 只抄指针，
 *           其余 kind 只抄 kind/标志、不复制载荷。
 *     +0x088 CSkeletonInstance —— 旧骨架先 ~CSkeletonInstance + operator delete，再 new(52) +
 *           CSkeletonInstance::CSkeletonInstance(src)（拷贝构造 0xc04d8）。
 *   【浅：直接抄】
 *     +0x080 CObjectGM* —— 两个实例指向同一个对象模板；只在 bAddToObject 时决定是否挂链。
 *     +0x084 CPhysicsObject* —— **不抄也不重建**；StartRoom 两处在 Assign 之后另调
 *           RebuildPhysicsBody 0x192fa4 补建，instance_copy 路径沿用新实例自己的物理体。
 *   【原样抄、但不校验】
 *     +0x07c object_index 与 +0x064「对象已解析」标志、+0x08c sprite、+0x0ac mask —— 成对拷贝，
 *     不去全局对象表核对；若 src 的 object_index 与 +0x080 不一致，this 会继承这种不一致。
 *   【完全不碰】
 *     +0x144/+0x148（DeSerialise 会写、Assign 不抄）、+0x044、+0x048、+0x06a、+0x06c、
 *     +0x070/+0x074、+0x168、+0x16c、+0x174、+0x178/+0x17c、+0x184、+0x188..+0x1ac。
 *     ⇒ 三条侵入链的链指针与属主指针保持 this 原状，复制完只在 src->+0x64 非 0 时补一次
 *       CollisionMarkDirty。
 *
 * ── Assign 与构造函数（CInstance::C2 0x1994dc）的区别 ──────────────────────
 *   1. 前提不同：ctor 假定整块 432 B 已被 operator new 清零，只写「默认值 + 身份」；Assign 假定
 *      this 是一个**活着**的实例，先摘对象链再逐字段覆盖。ctor 里没有 RemoveInstance，Assign
 *      第一条实义指令就是它。
 *   2. 身份字段：ctor 写 vtable 0x3EBAF8、+0x188=-1、三段自环、+0x070/+0x074 创建计数快照、
 *      +0x16c=2、+0x044 实例表槽号、+0x048=1；Assign **一个都不写**（vtable/计数/槽号/链都保持原值）。
 *   3. 对象解析：ctor 走 SetObjectIndex(objindex, addToObject)，由它写 +0x07c/+0x080/+0x064/
 *      +0x065..0x067/+0x08c/+0x0ac/+0x180 并尾调 CollisionMarkDirty；Assign 直接把这一串**结果**
 *      抄过来（含 +0x080 指针），只有 bAddToObject 时才补一次 CObjectGM::AddInstance。
 *   4. 变量表：ctor 不碰 +0x060（基类构造置 0）；Assign 深拷贝整张表。
 *   5. 骨架：ctor 不碰 +0x088；Assign 析构旧的、new 新的、拷贝构造。
 *   6. alarm：ctor 先清 0 再填 -1（两遍）；Assign 直接抄 12 个值。
 *   7. +0x06b：ctor 清 0（未定字节），Assign 也显式清 0 —— 全函数唯一一处「写常量而非抄 src」。
 *   8. 默认值：ctor 给的 -1/1.0f/270.0f/0x00FFFFFF 一个都不出现，Assign 全盘取 src 的值 ⇒
 *      复制出来的实例其 image_speed=1.0f 之类靠的是 src 里本来就是 1.0f，而不是 Assign 兜底。
 *
 * ── Assign 与 DeSerialise（0x19766c）的区别 ────────────────────────────────
 *   1. 数据源不同：Assign 从另一个实例按偏移抄；DeSerialise 从 IBuffer 按固定流序读 54 项。
 *   2. 覆盖面不同：DeSerialise 写 64 个槽（含 +0x144/+0x148/+0x0b0）但不写 +0x060/+0x088/
 *      +0x080/+0x07c（后两者由它调用的 SetObjectIndex 代写）；Assign 写 68 个落点但不写 +0x144/+0x148，
 *      并负责 +0x060/+0x088 的深拷贝。
 *   3. 一致性检查：DeSerialise 拿变量个数 n 与 *(int*)0x544b48 比、不等只打印警告；Assign 不做
 *      任何校验（连 object_index 都不核）。
 *   4. 收尾：DeSerialise 无副作用收尾（SetObjectIndex 的 CollisionMarkDirty 发生在第 3 项，
 *      此时位置还没读进来）；Assign 在 src->+0x64 非 0 时在拷贝途中补 CollisionMarkDirty。
 *
 * ── 已证（指令级）────────────────────────────────────────────────────────
 *  1. 入口先摘链：0x198700 ldr r0,[r0,#0x80] → 0x198710 CObjectGM::RemoveInstance(this) →
 *     0x19871c str 0（+0x080 = 0）。这条分支只看 this 自己的 +0x080。
 *  2. +0x064 是唯一同时影响控制流的拷贝字段：0x1987c0 读、0x1987f8 写、0x198804 bne 0x198da0
 *     （= 先 CollisionMarkDirty(this)，0x198da8 再 b 回 0x198808 继续拷贝）⇒ 不是早退。
 *  3. bAddToObject 生效条件：0x19880c cmp r4,#0 → 0x198864 beq 跳过；0x198868 cmp r0,#0 → 0x19886c beq 跳过
 *     ⇒ 只有 b 为真**且** src->+0x080 非 0 才 AddInstance(this)（0x198874）。
 *  4. alarm 循环：0x19887c mov r4,#12；r2=src、r3=this 各 +4；落点 [r3+0xf4] ⇒ 0x0f8..0x124。
 *  5. 变量表：0x1988ac operator new(20) 建表头；0x1988c8..0x1988dc 写 [0]=8、[8]=7；0x1988e0
 *     MemoryManager::Alloc(96, "…/Platform/MemoryManager.h", 70, 1)；0x1988f0 memset 0；
 *     0x1988fc 起 [4]=0、[0xc]=(int)(8*0.6f)=4（常量 0x3F19999A 在 0x198cac）、桶数组 8*12=96 B
 *     逐桶清 [桶+8]；0x19893c 把新表指针写进 this+0x060。
 *  6. 变量表遍历：0x198940 取 src->+0x060；0x19896c 取桶基址；每桶 12 B（[0] key、[4] RValue*、
 *     [8] hash>0 才算有效）；0x198998 r7 = key；0x19899c GetRValue()；0x1989a0 r4 = 值的 RValue*。
 *  7. RValue 头 16 B：[0..7] 载荷、[8] 标志、[0xc] kind（& 0x00FFFFFF 后查 15 项跳表）。
 *     跳表基址 0x1989cc：kind 0/11/14 → 0x198af8（ldm/stm 8 字节值拷贝）、1 → 0x198b54
 *     （[ptr+4]++）、2 → 0x198b28（[ptr]++ 且 [ptr+8] 空时回填新值）、3/8 → 0x198a08（只抄指针）、
 *     7 → 0x198b04（DeterminePotentialRoot(栈顶, ptr)）、其余 → 0x198a10（只抄头）。
 *  8. 插入：0x198a18 读 count、0x198a1c 读阈值、0x198a24 bgt 扩容；0x198a34
 *     CHashMapCalculateHashi(key)；索引用 hash & mask（r0 先清符号位）、桶步长 12 B；桶被占时按
 *     「距离」比较决定继续探测还是把当前桶搬走（robin-hood 式），key+hash 都相等则更新原槽；
 *     空桶落到 0x198b6c 写 {key, value, hash}。
 *  9. 扩容（冷路径 0x198cb8..0x198d9c）：cap*=2 → mask=cap-1 → 重算阈值 (int)(cap*0.6f) →
 *     Alloc(cap*12) + memset + 逐桶清 hash → 遍历旧桶逐个 Insert → Free 旧桶数组 → 回到 0x198a28
 *     继续插入。翻倍用的是 `lsl r0,r9,r3`（r3=1）。
 * 10. 骨架：0x198c28 读 src->+0x088，非 0 才做；0x198c4c..0x198c6c 析构 + 清 this->+0x088；
 *     0x198c70 operator new(52)、0x198c84 CSkeletonInstance::CSkeletonInstance(src)、0x198c8c 落盘。
 * 11. 全函数 bl 18 条 / 15 个不同目标、无 blx、无异常表引用；分支 53 条（b 25 / bne 10 / beq 9 /
 *     ble 6 / bgt 2 / blt 1）。literal 池只有 3 字（0x198cac 的 0.6f、0x198cb0/0x198cb4 两个
 *     文件名字符串偏移）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  1. RValue kind 3 / 8 / 11 / 14 的类型名（本卡只证到「3/8 只抄指针」「11/14 按 8 字节值拷贝」）。
 *  2. +0x0b0 的语义（ctor 不写，Assign/DeSerialise 都按字节过一遍）。
 *  3. 变量表里 value 的所有权：GetRValue() 造的新 RValue 是否同时登记进 +0x004 的变量数组 ——
 *     本函数只把它塞进新表，没有第二处落盘。
 *  4. src->+0x64 非 0 才 CollisionMarkDirty 的理由（推测与「对象已解析 ⇒ 已在对象实例表里」有关，未证）。
 *  5. `if (src->varMap)` 为假时 this 原有的 +0x060 保留不动（不释放、不清零）——是否有意为之未证。
 *
 * ── 逐条锚点（地址/字/mnemonic/operands 全部来自 asm/index-CInstance_Assign.tsv）─────────
 */


/* ── 0. 入口：r0=this、r1=src、r2=bAddToObject。r4=b、[sp]=this、[sp+4]=src。
 *    先摘对象链（+0x080 非 0 时），再进第 1 段拷贝。── */
/* @0x1986ec push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1986f0 vpush {d8} */
/* @0x1986f4 sub sp, sp, #20 */
/* @0x1986f8 mov r4, r2 */
/* @0x1986fc stm sp, {r0, r1} */
/* @0x198700 ldr r0, [r0, #0x80] */   —— this->+0x080 == 0 ? 跳过摘链
/* @0x198704 cmp r0, #0 */
/* @0x198708 beq 0x198720 <_ZN9CInstance6AssignEPS_b+0x34> */
/* @0x19870c ldr r1, [sp] */
/* @0x198710 bl 0x19e0fc <_ZN9CObjectGM14RemoveInstanceEP9CInstance> */   —— CObjectGM::RemoveInstance(this)
/* @0x198714 ldr r5, [sp] */
/* @0x198718 mov r3, #0 */
/* @0x19871c str r3, [r5, #0x80] */   —— this->+0x080 = 0
/* @0x198720 ldr r6, [sp, #0x4] */

/* ── 1. 第 1 段拷贝：27 个标量落点（编译器交织，落点次序即下表）────────────
 *    r6=src、r7=this。注意 image_index/speed 先抄，id/sprite 后抄，depth 夹在中间 ——
 *    这是纯逐字段赋值，没有 memcpy。── */
/* @0x198724 ldr r7, [sp] */
/* @0x198728 ldr r12, [r6, #0x78] */   —— src->+0x078 id
/* @0x19872c ldr r2, [r6, #0x90] */   —— src->+0x090 image_index
/* @0x198730 ldr r0, [r6, #0x8c] */   —— src->+0x08c sprite_index
/* @0x198734 ldr r3, [r6, #0x94] */   —— src->+0x094 image_speed
/* @0x198738 ldr r1, [r6, #0xa8] */   —— src->+0x0a8 image_blend
/* @0x19873c ldr r5, [r6, #0x98] */   —— src->+0x098 image_xscale
/* @0x198740 str r2, [r7, #0x90] */   —— this->+0x090 image_index
/* @0x198744 ldr r2, [r6, #0xac] */   —— src->+0x0ac mask_index
/* @0x198748 str r3, [r7, #0x94] */   —— this->+0x094 image_speed
/* @0x19874c ldrb r3, [r6, #0xb0] */   —— src->+0x0b0（字节）
/* @0x198750 str r12, [r7, #0x78] */   —— this->+0x078 id
/* @0x198754 str r0, [r7, #0x8c] */   —— this->+0x08c sprite_index
/* @0x198758 ldr r12, [r6, #0x9c] */   —— src->+0x09c image_yscale
/* @0x19875c ldr r0, [r6, #0xa0] */   —— src->+0x0a0 image_angle
/* @0x198760 str r5, [r7, #0x98] */   —— this->+0x098 image_xscale
/* @0x198764 str r12, [r7, #0x9c] */   —— this->+0x09c image_yscale
/* @0x198768 str r0, [r7, #0xa0] */   —— this->+0x0a0 image_angle
/* @0x19876c ldr r12, [r6, #0xa4] */   —— src->+0x0a4 image_alpha
/* @0x198770 ldr r0, [r6, #0x180] */   —— src->+0x180 depth
/* @0x198774 str r2, [r7, #0xac] */   —— this->+0x0ac mask_index
/* @0x198778 ldr r2, [r6, #0xb4] */   —— src->+0x0b4 x
/* @0x19877c strb r3, [r7, #0xb0] */   —— this->+0x0b0（字节）
/* @0x198780 mov r3, #0 */
/* @0x198784 strb r3, [r7, #0x6b] */   —— this->+0x06b ← 常量 0（不抄 src）
/* @0x198788 str r2, [r7, #0xb4] */   —— this->+0x0b4 x
/* @0x19878c ldr r2, [r6, #0xb8] */   —— src->+0x0b8 y
/* @0x198790 ldr r3, [r6, #0xbc] */   —— src->+0x0bc xstart
/* @0x198794 str r1, [r7, #0xa8] */   —— this->+0x0a8 image_blend
/* @0x198798 str r2, [r7, #0xb8] */   —— this->+0x0b8 y
/* @0x19879c ldr r2, [r6, #0xc0] */   —— src->+0x0c0 ystart
/* @0x1987a0 str r3, [r7, #0xbc] */   —— this->+0x0bc xstart
/* @0x1987a4 str r12, [r7, #0xa4] */   —— this->+0x0a4 image_alpha
/* @0x1987a8 ldr r3, [r6, #0xc4] */   —— src->+0x0c4 xprevious
/* @0x1987ac str r0, [r7, #0x180] */   —— this->+0x180 depth（按 32 位字抄，不做 float 转换）
/* @0x1987b0 str r2, [r7, #0xc0] */   —— this->+0x0c0 ystart
/* @0x1987b4 ldr r1, [r6, #0xc8] */   —— src->+0x0c8 yprevious
/* @0x1987b8 ldr r2, [r6, #0xcc] */   —— src->+0x0cc direction
/* @0x1987bc str r3, [r7, #0xc4] */   —— this->+0x0c4 xprevious
/* @0x1987c0 ldrb r3, [r6, #0x64] */   —— src->+0x064（对象已解析标志）
/* @0x1987c4 str r1, [r7, #0xc8] */   —— this->+0x0c8 yprevious
/* @0x1987c8 str r2, [r7, #0xcc] */   —— this->+0x0cc direction
/* @0x1987cc cmp r3, #0 */
/* @0x1987d0 ldr r1, [r6, #0xd0] */   —— src->+0x0d0 speed
/* @0x1987d4 ldr r2, [r6, #0xd4] */   —— src->+0x0d4 friction
/* @0x1987d8 str r1, [r7, #0xd0] */   —— this->+0x0d0 speed
/* @0x1987dc str r2, [r7, #0xd4] */   —— this->+0x0d4 friction
/* @0x1987e0 ldr r1, [r6, #0xd8] */   —— src->+0x0d8 gravity_direction
/* @0x1987e4 ldr r2, [r6, #0xdc] */   —— src->+0x0dc gravity
/* @0x1987e8 str r1, [r7, #0xd8] */   —— this->+0x0d8 gravity_direction
/* @0x1987ec str r2, [r7, #0xdc] */   —— this->+0x0dc gravity
/* @0x1987f0 ldr r1, [r6, #0xe0] */   —— src->+0x0e0 hspeed
/* @0x1987f4 ldr r2, [r6, #0xe4] */   —— src->+0x0e4 vspeed
/* @0x1987f8 strb r3, [r7, #0x64] */   —— this->+0x064（对象已解析标志，成对抄）
/* @0x1987fc str r1, [r7, #0xe0] */   —— this->+0x0e0 hspeed
/* @0x198800 str r2, [r7, #0xe4] */   —— this->+0x0e4 vspeed
/* @0x198804 bne 0x198da0 <_ZN9CInstance6AssignEPS_b+0x6b4> */   —— src->+0x64 != 0 ⇒ 先 CollisionMarkDirty（冷路径 0x198da0）

/* ── 2. 第 2 段：+0x0e8..+0x0f4 四连抄 + 三个标志字节 + 对象解析结果 ────────
 *    0x198818 用 `ldr r5,[r3,#0xe8]!` 预索引把 src 游标推到 0x0e8，随后 +4/+8/+0xc 三次 ldr；
 *    r12 = this+0xe8。── */
/* @0x198808 ldr r3, [sp, #0x4] */
/* @0x19880c cmp r4, #0 */   —— bAddToObject == 0 ⇒ 跳过 AddInstance
/* @0x198810 ldr r8, [sp] */
/* @0x198814 ldr r9, [sp, #0x4] */
/* @0x198818 ldr r5, [r3, #0xe8]! */   —— src->+0x0e8（预索引，游标变 src+0xe8）
/* @0x19881c add r12, r8, #232 */
/* @0x198820 ldr r0, [r3, #0x4] */
/* @0x198824 ldr r1, [r3, #0x8] */
/* @0x198828 ldr r2, [r3, #0xc] */
/* @0x19882c str r5, [r8, #0xe8] */   —— this->+0x0e8
/* @0x198830 str r0, [r12, #0x4] */   —— this->+0x0ec
/* @0x198834 str r1, [r12, #0x8] */   —— this->+0x0f0
/* @0x198838 str r2, [r12, #0xc] */   —— this->+0x0f4

/* ── 2b. visible/solid/persistent + object_index + CObjectGM* ───────────────
 *    +0x07c 与 +0x080 是**原样抄**：不查全局对象表、不重算 sprite/mask/深度。── */
/* @0x19883c ldrb r12, [r9, #0x65] */   —— src->+0x065 visible
/* @0x198840 ldrb r1, [r9, #0x66] */   —— src->+0x066 solid
/* @0x198844 ldrb r2, [r9, #0x67] */   —— src->+0x067 persistent
/* @0x198848 ldr r3, [r9, #0x7c] */   —— src->+0x07c object_index
/* @0x19884c ldr r0, [r9, #0x80] */   —— src->+0x080 CObjectGM*
/* @0x198850 strb r12, [r8, #0x65] */   —— this->+0x065 visible
/* @0x198854 strb r1, [r8, #0x66] */   —— this->+0x066 solid
/* @0x198858 strb r2, [r8, #0x67] */   —— this->+0x067 persistent
/* @0x19885c str r3, [r8, #0x7c] */   —— this->+0x07c object_index（原样抄）
/* @0x198860 str r0, [r8, #0x80] */   —— this->+0x080 CObjectGM*（浅拷贝）

/* ── 2c. b && src->object ⇒ CObjectGM::AddInstance(this)（两个门都要过）────── */
/* @0x198864 beq 0x198878 <_ZN9CInstance6AssignEPS_b+0x18c> */
/* @0x198868 cmp r0, #0 */   —— src->+0x080 == 0 ⇒ 跳过 AddInstance
/* @0x19886c beq 0x198878 <_ZN9CInstance6AssignEPS_b+0x18c> */
/* @0x198870 mov r1, r8 */
/* @0x198874 bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */   —— CObjectGM::AddInstance(this)

/* ── 3. alarm[0..11]：12 轮循环，r2=src、r3=this 各 +4，落点 0x0f8..0x124 ──── */
/* @0x198878 ldr r2, [sp, #0x4] */
/* @0x19887c mov r4, #12 */   —— 12 轮计数
/* @0x198880 ldr r3, [sp] */
/* @0x198884 ldr r1, [r2, #0xf8] */   —— src->alarm[i]
/* @0x198888 subs r4, r4, #1 */
/* @0x19888c add r2, r2, #4 */
/* @0x198890 add r3, r3, #4 */
/* @0x198894 str r1, [r3, #0xf4] */   —— this->alarm[i]（r3 = this+4(i+1) ⇒ 0x0f8..0x124）
/* @0x198898 bne 0x198884 <_ZN9CInstance6AssignEPS_b+0x198> */   —— 回到 0x198884（alarm 循环头）

/* ── 4. 变量表门闸：src->+0x060 非 0 才进来；否则整段跳过（this 原有表不动）── */
/* @0x19889c ldr r12, [sp, #0x4] */
/* @0x1988a0 ldr r3, [r12, #0x60] */   —— src->+0x060 变量哈希表
/* @0x1988a4 cmp r3, #0 */
/* @0x1988a8 beq 0x198b98 <_ZN9CInstance6AssignEPS_b+0x4ac> */   —— src->+0x060 == 0 ⇒ 整段跳过（0x198b98）

/* ── 5. 新建变量哈希表：表头 20 B + 桶数组 96 B ─────────────────────────────
 *    表头布局：[0]=容量 8、[4]=count 0、[8]=mask 7、[0xc]=阈值 (int)(cap*0.6f)=4、
 *    [0x10]=桶基址。桶 12 B：{key:int, value:RValue*, hash:int}。
 *    文件串取 0x198cb0 的池字 → "…/Platform/MemoryManager.h"，行号 70。── */
/* @0x1988ac mov r0, #20 */
/* @0x1988b0 bl 0x27c524 <_Znwj> */   —— operator new(20) = 表头
/* @0x1988b4 ldr r1, [pc, #0x3f4] */
/* @0x1988b8 mov r2, #8 */
/* @0x1988bc mov r3, #7 */
/* @0x1988c0 add r1, pc, r1 */
/* @0x1988c4 mov r5, r0 */
/* @0x1988c8 str r2, [r0] */   —— [0] = 8（初始容量）
/* @0x1988cc str r3, [r0, #0x8] */   —— [8] = 7（mask）
/* @0x1988d0 mov r2, #70 */
/* @0x1988d4 str r4, [r0, #0x10] */
/* @0x1988d8 mov r3, #1 */
/* @0x1988dc mov r0, #96 */
/* @0x1988e0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */   —— MemoryManager::Alloc(96, "…/Platform/MemoryManager.h", 70, 1)
/* @0x1988e4 mov r2, #96 */
/* @0x1988e8 mov r1, r4 */
/* @0x1988ec str r0, [r5, #0x10] */
/* @0x1988f0 bl 0xb65b0 <memset@plt> */   —— memset(桶数组, 0, 96)
/* @0x1988f4 ldr r2, [r5] */

/* ── 6. 表头初始化 + 逐桶清 hash（8 桶 × 12 B = 96 B，0x198918..0x198934）────
 *    0x198928 `str r4,[r3,#8]` 把每桶的 hash 清 0（r3 从基址+12 起，写 +8 即上一桶的 hash）。── */
/* @0x1988f8 vldr s15, [pc, #940] */   —— 0.6f 装载因子
/* @0x1988fc str r4, [r5, #0x4] */   —— [4] = count = 0
/* @0x198900 cmp r2, #0 */
/* @0x198904 vmov s13, r2 */
/* @0x198908 vcvt.f32.s32 s14, s13 */
/* @0x19890c vmul.f32 s15, s14, s15 */
/* @0x198910 vcvt.s32.f32 s15, s15 */
/* @0x198914 vstr s15, [r5, #12] */   —— [0xc] = (int)(8 * 0.6f) = 4（阈值）
/* @0x198918 ble 0x198938 <_ZN9CInstance6AssignEPS_b+0x24c> */   —— cap <= 0 则不扫桶
/* @0x19891c add r2, r2, r2, lsl #1 */
/* @0x198920 ldr r3, [r5, #0x10] */
/* @0x198924 add r2, r3, r2, lsl #2 */
/* @0x198928 str r4, [r3, #0x8] */   —— 逐桶清 hash（桶 +8）
/* @0x19892c add r3, r3, #12 */
/* @0x198930 cmp r3, r2 */
/* @0x198934 bne 0x198928 <_ZN9CInstance6AssignEPS_b+0x23c> */

/* ── 7. 落盘：this->+0x060 = 新表；然后按 src 桶数遍历 ─────────────────────── */
/* @0x198938 ldr r4, [sp] */
/* @0x19893c str r5, [r4, #0x60] */   —— this->+0x060 = 新表
/* @0x198940 ldr r5, [sp, #0x4] */   —— src->+0x060
/* @0x198944 ldr r3, [r5, #0x60] */   —— src 表头
/* @0x198948 ldr r2, [r3, #0x4] */   —— src 的 count（有效项数，不是容量）
/* @0x19894c cmp r2, #0 */   —— count <= 0 ⇒ 没有变量
/* @0x198950 ble 0x198b98 <_ZN9CInstance6AssignEPS_b+0x4ac> */
/* @0x198954 ldr r6, [pc, #0x358] */
/* @0x198958 mov r7, #0 */
/* @0x19895c vldr s16, [pc, #840] */
/* @0x198960 str r7, [sp, #0x8] */
/* @0x198964 add r6, pc, r6 */
/* @0x198968 str r6, [sp, #0xc] */

/* ── 8. 逐桶取值：r4 = 桶游标，[r4+8]=hash（>0 才算有效），r7 = key ──────────── */
/* @0x19896c ldr r4, [r3, #0x10] */   —— 桶基址（扫描时跳过 hash<=0 的空桶，凑够 count 个有效项就停）
/* @0x198970 mov r3, #0 */
/* @0x198974 ldr r1, [sp, #0x8] */
/* @0x198978 b 0x198980 <_ZN9CInstance6AssignEPS_b+0x294> */
/* @0x19897c add r4, r4, #12 */
/* @0x198980 ldr r2, [r4, #0x8] */   —— [桶+8] = hash；<= 0 视为空桶
/* @0x198984 cmp r2, #0 */
/* @0x198988 ble 0x19897c <_ZN9CInstance6AssignEPS_b+0x290> */
/* @0x19898c cmp r1, r3 */   —— i == 已处理数 ⇒ 命中这个桶
/* @0x198990 add r3, r3, #1 */
/* @0x198994 bne 0x19897c <_ZN9CInstance6AssignEPS_b+0x290> */

/* ── 9. 造新 RValue 并按 kind 复制载荷 ────────────────────────────────────
 *    0x19899c GetRValue() → r0 = 新 16 B RValue；0x1989a0 r4 = src 值的 RValue*；
 *    0x1989a4..0x1989b8 先抄 [0xc]（kind）与 [8]（标志）；0x1989bc 只留低 24 位查跳表。── */
/* @0x198998 ldr r7, [r4] */   —— r7 = key
/* @0x19899c bl 0x190dc0 <_Z9GetRValuev> */   —— GetRValue() 造新 RValue
/* @0x1989a0 ldr r4, [r4, #0x4] */   —— r4 = src 值的 RValue*
/* @0x1989a4 ldr r3, [r4, #0xc] */   —— 抄 kind
/* @0x1989a8 ldr r2, [r4, #0x8] */   —— 抄标志
/* @0x1989ac str r3, [r0, #0xc] */
/* @0x1989b0 mov r6, r0 */
/* @0x1989b4 ldr r3, [r4, #0xc] */
/* @0x1989b8 str r2, [r0, #0x8] */
/* @0x1989bc bic r3, r3, #-16777216 */   —— kind & 0x00FFFFFF
/* @0x1989c0 cmp r3, #14 */
/* @0x1989c4 addls pc, pc, r3, lsl #2 */   —— kind <= 14 查跳表

/* ── 9b. 15 项跳表（表基址 0x1989cc，kind 0..14；>14 落到 0x1989c8 → 0x198a10）────
 *    kind 0/11/14 → 0x198af8  8 字节值拷贝（ldm/stm）
 *    kind 1      → 0x198b54  [ptr+4]++
 *    kind 2      → 0x198b28  [ptr]++，[ptr+8] 为空时回填新 RValue
 *    kind 3/8    → 0x198a08  只抄指针
 *    kind 7      → 0x198b04  DeterminePotentialRoot(contextStackTop, ptr)
 *    其余        → 0x198a10  只抄头（载荷不复制）── */
/* @0x1989c8 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */   —— kind > 14 ⇒ 0x198a10（只抄头）
/* @0x1989cc b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x1989d0 b 0x198b54 <_ZN9CInstance6AssignEPS_b+0x468> */
/* @0x1989d4 b 0x198b28 <_ZN9CInstance6AssignEPS_b+0x43c> */
/* @0x1989d8 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x1989dc b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989e0 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989e4 b 0x198b04 <_ZN9CInstance6AssignEPS_b+0x418> */
/* @0x1989e8 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x1989ec b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989f0 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989f4 b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x1989f8 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x1989fc b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198a00 b 0x198af8 <_ZN9CInstance6AssignEPS_b+0x40c> */
/* @0x198a04 b 0x198a08 <_ZN9CInstance6AssignEPS_b+0x31c> */
/* @0x198a08 ldr r3, [r4] */   —— kind 3/8：只抄指针
/* @0x198a0c str r3, [r6] */

/* ── 10. 插入：count/threshold 检查 → 扩容 → hash → 探测 ────────────────── */
/* @0x198a10 ldr r9, [sp] */
/* @0x198a14 ldr r8, [r9, #0x60] */
/* @0x198a18 ldr r3, [r8, #0x4] */   —— count
/* @0x198a1c ldr r2, [r8, #0xc] */   —— 阈值
/* @0x198a20 cmp r3, r2 */
/* @0x198a24 bgt 0x198cb8 <_ZN9CInstance6AssignEPS_b+0x5cc> */   —— count > 阈值 ⇒ 扩容（0x198cb8）
/* @0x198a28 add r3, r3, #1 */
/* @0x198a2c mov r0, r7 */
/* @0x198a30 str r3, [r8, #0x4] */   —— count++
/* @0x198a34 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */   —— CHashMapCalculateHashi(key)
/* @0x198a38 ldr r4, [r8, #0x8] */
/* @0x198a3c ldr r10, [r8, #0x10] */
/* @0x198a40 bic r0, r0, #-2147483648 */   —— 清符号位
/* @0x198a44 and r3, r0, r4 */   —— idx = hash & mask
/* @0x198a48 add r2, r3, r3, lsl #1 */
/* @0x198a4c add r2, r10, r2, lsl #2 */   —— bucket = base + idx*12
/* @0x198a50 ldr r1, [r2, #0x8] */   —— 桶的 hash 字段
/* @0x198a54 cmp r1, #0 */   —— 空桶 ⇒ 直接落值（0x198b6c）
/* @0x198a58 ldrne r11, [r8] */
/* @0x198a5c movne r5, #0 */
/* @0x198a60 bne 0x198aa8 <_ZN9CInstance6AssignEPS_b+0x3bc> */
/* @0x198a64 b 0x198b6c <_ZN9CInstance6AssignEPS_b+0x480> */
/* @0x198a68 ldr r9, [r2] */   —— 搬运：把当前桶让给更近的项
/* @0x198a6c ldr r5, [r2, #0x4] */
/* @0x198a70 str r0, [r2, #0x8] */
/* @0x198a74 mov r0, r1 */
/* @0x198a78 str r7, [r2] */
/* @0x198a7c mov r7, r9 */
/* @0x198a80 str r6, [r2, #0x4] */
/* @0x198a84 mov r6, r5 */
/* @0x198a88 add r3, r3, #1 */
/* @0x198a8c add r5, r12, #1 */
/* @0x198a90 and r3, r3, r4 */
/* @0x198a94 add r2, r3, r3, lsl #1 */
/* @0x198a98 add r2, r10, r2, lsl #2 */
/* @0x198a9c ldr r1, [r2, #0x8] */
/* @0x198aa0 cmp r1, #0 */
/* @0x198aa4 beq 0x198b6c <_ZN9CInstance6AssignEPS_b+0x480> */
/* @0x198aa8 add r12, r11, r3 */
/* @0x198aac and r9, r1, r4 */   —— (空位索引 - 本桶索引) & mask
/* @0x198ab0 rsb r12, r9, r12 */
/* @0x198ab4 and r12, r12, r4 */
/* @0x198ab8 cmp r12, r5 */   —— 与本桶已走距离比较
/* @0x198abc blt 0x198a68 <_ZN9CInstance6AssignEPS_b+0x37c> */
/* @0x198ac0 movne r12, r5 */
/* @0x198ac4 bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198ac8 cmp r1, r0 */   —— hash 与 key 都相同 ⇒ 更新原槽
/* @0x198acc bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198ad0 ldr r5, [r2] */
/* @0x198ad4 cmp r7, r5 */
/* @0x198ad8 bne 0x198a88 <_ZN9CInstance6AssignEPS_b+0x39c> */
/* @0x198adc ldr r3, [r8, #0x4] */
/* @0x198ae0 str r7, [r2] */
/* @0x198ae4 str r6, [r2, #0x4] */
/* @0x198ae8 sub r3, r3, #1 */   —— count--
/* @0x198aec str r1, [r2, #0x8] */
/* @0x198af0 str r3, [r8, #0x4] */
/* @0x198af4 b 0x198b78 <_ZN9CInstance6AssignEPS_b+0x48c> */
/* @0x198af8 ldm r4, {r2, r3} */   —— kind 0/11/14：8 字节值拷贝
/* @0x198afc stm r0, {r2, r3} */
/* @0x198b00 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b04 ldr r3, [r4] */   —— kind 7：DeterminePotentialRoot
/* @0x198b08 str r3, [r0] */
/* @0x198b0c ldr r3, [r4] */
/* @0x198b10 cmp r3, #0 */
/* @0x198b14 beq 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b18 bl 0xd3a54 <_Z18GetContextStackTopv> */
/* @0x198b1c ldr r1, [r4] */
/* @0x198b20 bl 0x191710 <_Z22DeterminePotentialRootP12YYObjectBaseS0_> */
/* @0x198b24 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b28 ldr r3, [r4] */   —— kind 2：[ptr]++ / [ptr+8] 回填
/* @0x198b2c cmp r3, #0 */
/* @0x198b30 str r3, [r0] */
/* @0x198b34 beq 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b38 ldr r1, [r3, #0x8] */
/* @0x198b3c ldr r2, [r3] */
/* @0x198b40 cmp r1, #0 */
/* @0x198b44 streq r0, [r3, #0x8] */
/* @0x198b48 add r2, r2, #1 */
/* @0x198b4c str r2, [r3] */
/* @0x198b50 b 0x198a10 <_ZN9CInstance6AssignEPS_b+0x324> */
/* @0x198b54 ldr r3, [r4] */   —— kind 1：[ptr+4]++
/* @0x198b58 cmp r3, #0 */
/* @0x198b5c ldrne r2, [r3, #0x4] */
/* @0x198b60 addne r2, r2, #1 */
/* @0x198b64 strne r2, [r3, #0x4] */
/* @0x198b68 b 0x198a0c <_ZN9CInstance6AssignEPS_b+0x320> */

/* ── 10c. 空桶落值 {key, value, hash}，然后取下一个 src 桶 ──────────────── */
/* @0x198b6c str r7, [r2] */   —— 写 {key, value, hash}
/* @0x198b70 str r6, [r2, #0x4] */
/* @0x198b74 str r0, [r2, #0x8] */
/* @0x198b78 ldr r4, [sp, #0x4] */
/* @0x198b7c ldr r5, [sp, #0x8] */
/* @0x198b80 ldr r3, [r4, #0x60] */
/* @0x198b84 add r5, r5, #1 */
/* @0x198b88 str r5, [sp, #0x8] */
/* @0x198b8c ldr r2, [r3, #0x4] */
/* @0x198b90 cmp r2, r5 */
/* @0x198b94 bgt 0x19896c <_ZN9CInstance6AssignEPS_b+0x280> */   —— i < count ⇒ 回到 0x19896c 取下一个有效桶

/* ── 11. 第 4 段：路径/时间线/骨架/layer ───────────────────────────────── */
/* @0x198b98 ldr r4, [sp, #0x4] */
/* @0x198b9c ldr r9, [sp, #0x4] */
/* @0x198ba0 ldr r8, [sp] */
/* @0x198ba4 ldr r3, [r4, #0x134] */   —— src->+0x134
/* @0x198ba8 ldrb r7, [r4, #0x68] */   —— src->+0x068
/* @0x198bac ldr r1, [r4, #0x12c] */   —— src->+0x12c
/* @0x198bb0 ldrb r6, [r4, #0x69] */   —— src->+0x069
/* @0x198bb4 ldr r2, [r4, #0x130] */   —— src->+0x130
/* @0x198bb8 ldr r5, [r4, #0x128] */   —— src->+0x128
/* @0x198bbc ldr r12, [r9, #0x14c] */   —— src->+0x14c
/* @0x198bc0 ldr r4, [r4, #0x140] */   —— src->+0x140
/* @0x198bc4 ldrb r0, [r9, #0x15c] */   —— src->+0x15c
/* @0x198bc8 str r3, [r8, #0x134] */   —— this->+0x134
/* @0x198bcc ldr r3, [r9, #0x138] */   —— src->+0x138
/* @0x198bd0 str r1, [r8, #0x12c] */   —— this->+0x12c
/* @0x198bd4 str r2, [r8, #0x130] */   —— this->+0x130
/* @0x198bd8 ldrb r1, [r9, #0x15d] */   —— src->+0x15d
/* @0x198bdc ldr r2, [r9, #0x160] */   —— src->+0x160
/* @0x198be0 str r3, [r8, #0x138] */   —— this->+0x138
/* @0x198be4 ldr r3, [r9, #0x164] */   —— src->+0x164
/* @0x198be8 ldr r8, [r9, #0x13c] */   —— src->+0x13c
/* @0x198bec ldr r9, [sp] */
/* @0x198bf0 strb r7, [r9, #0x68] */   —— this->+0x068
/* @0x198bf4 ldr r7, [sp, #0x4] */
/* @0x198bf8 strb r6, [r9, #0x69] */   —— this->+0x069
/* @0x198bfc str r8, [r9, #0x13c] */   —— this->+0x13c
/* @0x198c00 ldr r6, [r7, #0x150] */   —— src->+0x150
/* @0x198c04 str r4, [r9, #0x140] */   —— this->+0x140
/* @0x198c08 ldr r4, [r7, #0x154] */   —— src->+0x154
/* @0x198c0c str r5, [r9, #0x128] */   —— this->+0x128
/* @0x198c10 str r12, [r9, #0x14c] */   —— this->+0x14c
/* @0x198c14 str r6, [r9, #0x150] */   —— this->+0x150
/* @0x198c18 ldr r12, [r7, #0x158] */   —— src->+0x158
/* @0x198c1c str r4, [r9, #0x154] */   —— this->+0x154
/* @0x198c20 strb r0, [r9, #0x15c] */   —— this->+0x15c
/* @0x198c24 str r2, [r9, #0x160] */   —— this->+0x160
/* @0x198c28 ldr r2, [r7, #0x88] */   —— src->+0x088 骨架指针
/* @0x198c2c str r3, [r9, #0x164] */   —— this->+0x164
/* @0x198c30 ldrb r3, [r7, #0x15e] */   —— src->+0x15e
/* @0x198c34 cmp r2, #0 */
/* @0x198c38 str r12, [r9, #0x158] */   —— this->+0x158
/* @0x198c3c strb r1, [r9, #0x15d] */   —— this->+0x15d
/* @0x198c40 strb r3, [r9, #0x15e] */   —— this->+0x15e

/* ── 11b. 骨架深拷贝门闸：src->+0x088 非 0 才做 ─────────────────────────── */
/* @0x198c44 beq 0x198c90 <_ZN9CInstance6AssignEPS_b+0x5a4> */
/* @0x198c48 ldr r6, [sp] */   —— this 有旧骨架才析构
/* @0x198c4c ldr r4, [r6, #0x88] */   —— this->+0x088（旧的，要析构）
/* @0x198c50 cmp r4, #0 */
/* @0x198c54 beq 0x198c70 <_ZN9CInstance6AssignEPS_b+0x584> */
/* @0x198c58 mov r0, r4 */
/* @0x198c5c bl 0xbe194 <_ZN17CSkeletonInstanceD2Ev> */   —— ~CSkeletonInstance
/* @0x198c60 mov r0, r4 */
/* @0x198c64 bl 0x27d1d0 <_ZdlPv> */   —— operator delete
/* @0x198c68 mov r3, #0 */
/* @0x198c6c str r3, [r6, #0x88] */   —— this->+0x088 = 0（旧骨架已析构）
/* @0x198c70 mov r0, #52 */
/* @0x198c74 bl 0x27c524 <_Znwj> */   —— operator new(52)
/* @0x198c78 ldr r7, [sp, #0x4] */
/* @0x198c7c ldr r1, [r7, #0x88] */   —— src->+0x088（拷贝源）
/* @0x198c80 mov r4, r0 */
/* @0x198c84 bl 0xc04d8 <_ZN17CSkeletonInstanceC2EPS_> */   —— CSkeletonInstance::CSkeletonInstance(src)
/* @0x198c88 ldr r8, [sp] */
/* @0x198c8c str r4, [r8, #0x88] */   —— this->+0x088 = 新 CSkeletonInstance
/* @0x198c90 ldr r9, [sp, #0x4] */
/* @0x198c94 ldr r12, [sp] */
/* @0x198c98 ldr r3, [r9, #0x170] */   —— src->+0x170 layer
/* @0x198c9c str r3, [r12, #0x170] */   —— this->+0x170 layer
/* @0x198ca0 add sp, sp, #20 */
/* @0x198ca4 vpop {d8} */
/* @0x198ca8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 12. literal pool（3 字，**非指令**）───────────────────────────────────
 *    0x198cac = 0x3F19999A = 0.6f（哈希表装载因子）
 *    0x198cb0 = 偏移 → "jni/../jni/yoyo/../../../Platform/MemoryManager.h"
 *    0x198cb4 = 同一字符串偏移（第二次 Alloc 用）── */
/* @0x198cac svclo #0x19999a */
/* @0x198cb0 andseq r8, r9, r0, ror r7 */
/* @0x198cb4 andseq r8, r9, r12, asr #13 */

/* ── 10b. 扩容冷路径（由 0x198a24 的 bgt 跳进来；做完回 0x198a28 继续插入）──
 *    cap*=2、mask=cap-1、阈值=(int)(cap*0.6f)、Alloc(cap*12)+memset、逐桶清 hash、
 *    遍历旧桶重新 Insert、Free 旧桶数组。── */
/* @0x198cb8 ldr r9, [r8] */   —— 旧容量
/* @0x198cbc mov r3, #1 */
/* @0x198cc0 ldr r1, [sp, #0xc] */
/* @0x198cc4 mov r2, #70 */
/* @0x198cc8 ldr r5, [r8, #0x10] */
/* @0x198ccc lsl r0, r9, r3 */   —— cap *= 2
/* @0x198cd0 str r0, [r8] */
/* @0x198cd4 add r4, r0, r9, lsl #2 */
/* @0x198cd8 sub r0, r0, #1 */
/* @0x198cdc str r0, [r8, #0x8] */   —— mask = cap-1
/* @0x198ce0 lsl r4, r4, #2 */
/* @0x198ce4 mov r0, r4 */
/* @0x198ce8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */   —— Alloc(cap*12)
/* @0x198cec mov r2, r4 */
/* @0x198cf0 mov r1, #0 */
/* @0x198cf4 str r0, [r8, #0x10] */
/* @0x198cf8 bl 0xb65b0 <memset@plt> */
/* @0x198cfc ldr r2, [r8] */
/* @0x198d00 mov r12, #0 */
/* @0x198d04 str r12, [r8, #0x4] */   —— count 归零
/* @0x198d08 cmp r2, r12 */
/* @0x198d0c vmov s13, r2 */
/* @0x198d10 vcvt.f32.s32 s15, s13 */
/* @0x198d14 vmul.f32 s15, s15, s16 */   —— * 0.6f
/* @0x198d18 vcvt.s32.f32 s15, s15 */
/* @0x198d1c vstr s15, [r8, #12] */   —— 阈值重算
/* @0x198d20 ble 0x198d44 <_ZN9CInstance6AssignEPS_b+0x658> */
/* @0x198d24 add r2, r2, r2, lsl #1 */
/* @0x198d28 ldr r3, [r8, #0x10] */
/* @0x198d2c add r2, r3, r2, lsl #2 */
/* @0x198d30 mov r0, #0 */
/* @0x198d34 add r3, r3, #12 */
/* @0x198d38 str r0, [r3, #-0x4] */   —— 逐桶清 hash
/* @0x198d3c cmp r3, r2 */
/* @0x198d40 bne 0x198d30 <_ZN9CInstance6AssignEPS_b+0x644> */
/* @0x198d44 cmp r9, #0 */
/* @0x198d48 movgt r4, r5 */
/* @0x198d4c movgt r10, #0 */
/* @0x198d50 ble 0x198d7c <_ZN9CInstance6AssignEPS_b+0x690> */
/* @0x198d54 ldr r3, [r4, #0x8] */
/* @0x198d58 mov r0, r8 */
/* @0x198d5c add r10, r10, #1 */
/* @0x198d60 cmp r3, #0 */
/* @0x198d64 ble 0x198d70 <_ZN9CInstance6AssignEPS_b+0x684> */
/* @0x198d68 ldm r4, {r1, r2} */   —— 旧桶 {key, value}
/* @0x198d6c bl 0x196408 <_ZN8CHashMapIiP6RValueLi3EE6InsertEiS1_> */   —— CHashMap<int,RValue*,3>::Insert
/* @0x198d70 cmp r10, r9 */
/* @0x198d74 add r4, r4, #12 */
/* @0x198d78 bne 0x198d54 <_ZN9CInstance6AssignEPS_b+0x668> */
/* @0x198d7c mov r0, r5 */
/* @0x198d80 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */   —— Free(旧桶数组)
/* @0x198d84 vldr s13, [r8] */
/* @0x198d88 vcvt.f32.s32 s15, s13 */
/* @0x198d8c ldr r3, [r8, #0x4] */
/* @0x198d90 vmul.f32 s15, s15, s16 */
/* @0x198d94 vcvt.s32.f32 s15, s15 */
/* @0x198d98 vstr s15, [r8, #12] */
/* @0x198d9c b 0x198a28 <_ZN9CInstance6AssignEPS_b+0x33c> */   —— 回 0x198a28 继续插入

/* ── 13. 冷路径：src->+0x64 非 0 时先给 this 打碰撞脏标记，再回 0x198808 ──────
 *    这不是出口：0x198da8 的 b 直接把控制流送回第 2 段开头。── */
/* @0x198da0 mov r0, r7 */
/* @0x198da4 bl 0x1cc1d0 <_Z18CollisionMarkDirtyP9CInstance> */   —— CollisionMarkDirty(this)
/* @0x198da8 b 0x198808 <_ZN9CInstance6AssignEPS_b+0x11c> */   —— 回 0x198808（不是返回）
