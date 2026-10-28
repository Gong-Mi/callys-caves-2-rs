/* cally 逆向卡：对象表四件 —— Object_Add / Object_Prepare / Object_Load / Object_GetInstance
 * （原版 libyoyo.so，armv7；§1 的 Alloc 直接指到 Files/Object/Object_Main.cpp 第 226 行，§2/§3 与它地址相邻、
 *   调用同一批符号 ⇒ 推断同 TU，但没有直接的源文件证据；§4 在 0x14ec2c，与三节无相邻关系）
 * @func §1 0x19eebc 0x19f010  size 344  86 条（80 条指令 + 0x19effc..0x19f010 六个池字；其后 0x19f014 Object_Delete(int)）
 * @func §2 0x19ebb4 0x19ecf4  size 324  81 条（74 条指令 + 0x19ecdc..0x19ecf4 七个池字；其后 0x19ecf8 Object_Exists(int)）
 * @func §3 0x19ea7c 0x19ebb0  size 312  78 条（74 条指令 + 0x19eba4..0x19ebb0 四个池字；其后紧接 §2 的 0x19ebb4）
 * @func §4 0x14ec2c 0x14ed00  size 216  54 条（52 条指令 + 0x14ecfc/0x14ed00 两个池字；其后 0x14ed04 F_PhysicsCreateDistanceJoint）
 * 总账: 299 锚点与 asm/index-ObjectOps_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py → index=299 card=299 missing=0 extra=0 mismatch=0 RESULT EXACT）。
 * 级别: 正文（四节都逐条解码到控制流/算式，四段语义都能写成可编译 C。已钉：OBJT 块的条数/偏移基址/名字所有权、
 *       对象表的节点与桶布局、id 空间的四段分派、父链回填时机、g_ObjectNumber 的两个写点。
 *       未钉的只有：§3 第二实参为什么留着不用、g_ObjectHash 表本体的分配者、CObjectGM +0xc4/+0xd0 两条平行链的分工。）
 *
 * ── 地址顺序与本卡的四节 ─────────────────────────────────────────────────────
 *   0x14ec2c §4 Object_GetInstance(int, CInstance*, CInstance*)   216 B   查询
 *   0x19ea7c §3 Object_Load(uchar*, unsigned int, uchar*)         312 B   启动期装载（OBJT 块）
 *   0x19ebb4 §2 Object_Prepare()                                  324 B   启动期编译
 *   0x19eebc §1 Object_Add()                                      344 B   运行时新增
 *   ⇒ 0x19ea7c..0x19ecf8 是连续的三连（Load → Prepare → Exists），Add 单独在 0x19eebc；四节都在同一 TU。
 *
 * ── 全局坐标（读 libyoyo.so 的 .got 槽内容 + .dynsym 原名，不是从字符串猜的）────────────
 *   GOT 槽      目标        符号（.dynsym 原名，4 B 除注明）              本卡用处
 *   0x3f06ec → 0x542370   g_ObjectNumber                               §1 取号/自增、§2 打印条数、§3 整写条数
 *   0x3edc44 → 0x542374   g_ObjectHash（**指针变量**，再解一层才是表）    §1/§3 插入、§2 遍历、§4 查对象
 *   0x3edc4c → 0x536f28   CInstance::ms_ID2InstanceE（12 B 静态本体）     §4 id > 99999 的路径
 *   0x3ed94c → 0x544c44   g_pWADBaseAddress                             §3 块偏移与名字偏移的基址
 *   0x3eddc0 → 0x54290c   Current_Object                               §2 编译前写入「当前对象号」
 *   0x3efb24 → 0x3eb6b8（槽里是对象指针槽 0x3eb6b8，内容是 0x479d08）    §2 两处控制台打印的对象
 *   0x3ed958 → __stack_chk_guard（UND，装载期填；文件内为 0）            §1 栈保护
 *
 * ── 对象表的结构（本卡四节一致；与 CInstance_SetObjectIndex 卡同构，但那张卡没写 +0x00）──────
 *   g_ObjectHash 0x542374 是指针变量 → 表结构 12 B：{+0x00 桶数组, +0x04 掩码, +0x08 计数}
 *   桶 8 B：{+0x00 链头, +0x04 链尾}；桶下标 = 对象号 & 掩码（掩码 = 桶数-1）
 *   节点 16 B：{+0x00 prev, +0x04 next, +0x08 key(对象号), +0x0c value(CObjectGM*)}
 *   插入 = 尾插（写 bucket.tail）：node->prev = 旧尾、旧尾->next = node、bucket.tail = node、node->next = 0；
 *   空桶时 bucket.head 与 bucket.tail 同时指向新节点。查找 = 从桶头沿 +0x04 走、比 +0x08。
 *   ⚠ 本表节点 [0]=prev / [4]=next，而 CObjectGM 实例链的 12 B 节点是 [0]=next / [4]=prev（§4 已证），别混。
 *   ms_ID2InstanceE 0x536f28 是同构的第二张表（12 B 表头直接在 .bss，不再解一层），key = 实例号，value = CInstance*。
 *
 * ── CObjectGM 侧本卡用到的字段（sizeof=220，见 CObjectGM_ctor 卡）────────────────────
 *   +0x14 char*  名字：§3 用 SetName（复制）、§1 用 SetNameRef（接管），两者都先 Free 旧值
 *   +0x18 int    对象号：构造参数；§3 给循环下标、§1 给 g_ObjectNumber；§2 打印它、并写进 Current_Object
 *   +0x48 ptr    父对象 CObjectGM*：PatchParents 用 +0xc（父对象号）查表回填；AddInstance/RemoveInstance 沿它递归
 *   +0xc4/+0xc8/+0xcc 与 +0xd0/+0xd4/+0xd8  两条平行的实例链（头/尾/计数），节点 12 B {+0 next, +4 prev, +8 CInstance*}
 *
 * ── id 空间（§4 是唯一的分派点）────────────────────────────────────────────────
 *   -1        → self（第二实参）
 *   -2        → other（第三实参）
 *   0..99999  → 对象号：g_ObjectHash 查 CObjectGM*，再取它 +0xd0 实例链的第一个实例
 *   >99999    → 实例号：ms_ID2InstanceE 直接查 CInstance*
 *   ⚠ -3 及以下不特判：有符号 bgt 不成立 ⇒ 落到对象表被 and 掩码索引。
 *
 * ── 四节的接缝（一句话串起来）──────────────────────────────────────────────────
 *   §3 启动期把 OBJT 块里的 191 条记录变成 191 个 CObjectGM(i) 并插进对象表，g_ObjectNumber 置 191；
 *   §2 在 PrepareGame 里把所有对象 Compile 一遍（失败即启动失败），编译前把 Current_Object 设成对象号；
 *   §1 给运行时新增对象发号（从 191 起）、自动命名 "__newobject<id>"、同样插表并把 g_ObjectNumber 推到 id+1；
 *   §4 把「-1/-2/对象号/实例号」四种 id 解析成一个 CInstance*，供 9 个物理 joint 内建找 bodyA/bodyB。
 */

/* ══ §1 Object_Add 0x19eebc ═════════════════════════════════════════════════
 * @func 0x19eebc 0x19f010 size 344  86 条（80 指令 + 6 池字；末指令 0x19eff8，函数尾 0x19f014）
 * 级别: 正文（86/86 逐条落锚。名字块的三字常量、Alloc 长度、所有权转移、尾插两种分支、两个计数器全部钉死）
 * 符号: _Z10Object_Addv → void Object_Add()（**符号是 void，但 r0 事实上带回新对象号**，见已证 2）
 * 位置: 0x19eebc；其后 0x19f014 Object_Delete(int)。§1 自己的 Alloc 就指 Object_Main.cpp 第 226 行；
 *       §2/§3 与它地址相邻（0x19ea7c..0x19ecf8 连续），推断同一 TU
 * 调用点: 全图唯一 —— 0x12e144 在 F_ObjectAdd 0x12e134（48 B，游戏内建 object_add 的实现）里
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   给运行时新增的对象发号：id = g_ObjectNumber → new CObjectGM(id) → 名字做成 "__newobject<id>" →
 *   SetNameRef 接管这块内存 → 把 {id, obj} 尾插进 g_ObjectHash 的桶 → g_ObjectNumber 与表计数各 +1。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   void Object_Add() {                                  // 返回 void，r0 里残留 id
 *     char buf[256];
 *     int id = g_ObjectNumber;                           // 0x542370
 *     _itoa(id, buf, 10);                                // 0x19eeec
 *     CObjectGM* obj = new CObjectGM(id);                // operator new(220) + C2
 *     char* name = (char*)MemoryManager::Alloc(strlen(buf) + 12,
 *                    "jni/../jni/yoyo/../../../Files/Object/Object_Main.cpp", 226, true);
 *     memcpy(name, "__newobject\0", 12);                 // 三个字，rodata 0x34cf04
 *     strcpy(name + 11, buf);                            // 前缀 11 字符 + 数字串 + NUL
 *     obj->SetNameRef(name);                             // 0x19d348：接管，不复制
 *     HashTable* t = g_ObjectHash;                       // 指针变量 → 表结构
 *     int h = id & t->mask;
 *     Node* n = (Node*)MemoryManager::Alloc(16, "…/Platform/Hash.h", 306, true);
 *     n->key = id; n->value = obj;
 *     if (t->bucket[h].head == 0) { t->bucket[h].head = t->bucket[h].tail = n; n->prev = n->next = 0; }
 *     else { n->prev = t->bucket[h].tail; t->bucket[h].tail->next = n; t->bucket[h].tail = n; n->next = 0; }
 *     t->count++;                                        // [表+8]
 *     g_ObjectNumber = id + 1;                           // 0x19efe0
 *   }
 *
 * ── 逐段 ─────────────────────────────────────────────────────────────────
 *   ① 0x19eebc..0x19eee8 帧与取号：push 8 寄存器 + sub sp,#264（缓冲 256 B 在 sp+4，栈保护字在 sp+0x104）；
 *      r6 = GOT 0x3ed958（&__stack_chk_guard）、r4 = GOT 0x3f06ec（&g_ObjectNumber）；保护字落 sp+0x104。
 *   ② 0x19eeec _itoa(id, buf, 10)（符号 _Z5_itoaiPci；进制 10 由 0x19eed0 mov r2,#10 给，不是 16）。
 *   ③ 0x19eef0..0x19ef00 new(220) → r8；r1 = *g_ObjectNumber（同一值，尚未自增）→ CObjectGM::C2(id)。
 *   ④ 0x19ef04..0x19ef54 名字块：strlen(buf) → Alloc(len+12, Object_Main.cpp, 226, true)；
 *      三字常量写块头（0x656e5f5f / 0x6a626f77 / 0x00746365 = "__newobject\0"），
 *      strcpy(块+11, buf) —— 11 字节前缀 + 数字串 + NUL 恰好 = len+12；然后 SetNameRef(块)。
 *   ⑤ 0x19ef58..0x19efcc 插表：GOT 0x3edc44 → 0x542374（g_ObjectHash）→ 表结构，ldm 得 buckets(r7)/mask(r9)；
 *      桶下标 = id & mask；Alloc(16, Hash.h, 306, true)；node->key=id、node->value=obj；
 *      空桶（0x19efa4..0x19efcc 的 streq 组）与非空桶尾插（strne 组）两条路都逐条落锚。
 *   ⑥ 0x19efd0..0x19eff8 收尾：校验栈保护；r0 = *g_ObjectNumber、r2 = r0+1、写回；[表+8] += 1；r0 停在旧值。
 *
 * ── 已证（每条都指到指令）────────────────────────────────────────────────
 *   1. 唯一调用点 0x12e144（F_ObjectAdd 0x12e134 内）；bl 之后 0x12e148 vmov s15,r0 / 0x12e14c vcvt.f64.s32
 *      ⇒ 调用方把 r0 当 int 用（内建 object_add 的返回值就是新对象号）。
 *   2. 出口 r0 的值 = 0x19efd4 载入的自增前 g_ObjectNumber：这是返回前最后一次写 r0（其后只有 str/add/bne），
 *      所以「声明 void」只是源码写法，ABI 上等价于 int Object_Add()。
 *   3. 名字 = "__newobject" + itoa(id)：前缀来自 rodata 0x34cf04 的前 11 字节（0x19ef30 ldm 三个字、
 *      0x19ef34/0x19ef38/0x19ef40 三次 str），strcpy 落点 +11（0x19ef3c/0x19ef48），
 *      Alloc 长度 = strlen+12（0x19ef1c add r0,r0,#12）—— 三者互相钉死，长度没有余量也没有越界。
 *   4. 所有权：SetNameRef（0x19d348..0x19d368）只 Free 旧 +0x14 再存指针，不复制 ⇒ 这块 Alloc 必须由 §1 自己做，
 *      并且此后归 CObjectGM 所有（Clear 释放）。与 §3 的 SetName（复制）成对，两条路的 +0x14 都只由 Clear 释放。
 *   5. 插表代码与 §3 的插表逐条同构（0x19ef84..0x19efc8 vs 0x19eb34..0x19eb7c），都是 Hash.h:306 的内联插入，
 *      只有 key 的来源不同（§1 用 id，§3 用循环下标 i）——
 *      ⇒ 「HashTable::Add(key,value) 在 Hash.h 第 306 行、节点 16 B」这条不是猜的，是两处现场互证。
 *   6. 空桶分支的寄存器顺序：0x19efa4 是 movne r0,#0（空桶时不执行），所以 0x19efa8 streq r0,[r2,#4]
 *      写进 bucket.tail 的是节点自身；先写尾（0x19efa8）再写头（0x19efc4）。
 *   7. 两个计数器互不代用：g_ObjectNumber（0x542370，0x19efd4/0x19efe0 读改写）与表计数（[table+8]，0x19efd8/0x19efe8）。
 *   8. 栈保护：保护字来自导入符号 __stack_chk_guard（GOT 0x3ed958，文件内为 0、装载期由动态链接器填），
 *      0x19eff0 恢复 sp 后 0x19eff4 pop、0x19eff8 才是失败分支（bne 0x19eff8 跳的正是 __stack_chk_fail）。
 *   9. 无失败路径：new/Alloc 返回 0 时不判空，直接往下写（本函数没有任何比较返回值的指令）。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · F_ObjectAdd 的 RValue 打包（0x12e148..0x12e160 的 vmov/vcvt/stm）不在本卡锚点内，本卡只证「r0 当 int」。
 *   · g_ObjectHash 表本体（桶数组/掩码）的分配者与扩容策略未证；本卡只证「按 id & mask 尾插」。
 *   · g_ObjectNumber 的其它写点未穷举（本卡只见 §1 的自增与 §3 的整写；本卡外未扫）。
 *   · "__newobject" 前缀在游戏里是否可见（object_get_name 的返回）未验证。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */
/* @0x19eebc push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x19eec0 sub sp, sp, #264 —— 帧 264 B：256 B itoa 缓冲在 sp+4，栈保护字在 sp+0x104 */
/* @0x19eec4 ldr r6, [pc, #0x130] —— 池 0x24ea7c → GOT 0x3ed958（&__stack_chk_guard） */
/* @0x19eec8 add r7, sp, #4 —— r7 = buf */
/* @0x19eecc ldr r4, [pc, #0x12c] —— 池 0x251808 → 0x19eedc+该值 = GOT 0x3f06ec（&g_ObjectNumber） */
/* @0x19eed0 mov r2, #10 —— 进制 10 */
/* @0x19eed4 ldr r6, [pc, r6] */
/* @0x19eed8 mov r1, r7 */
/* @0x19eedc ldr r4, [pc, r4] */
/* @0x19eee0 ldr r3, [r6] */
/* @0x19eee4 ldr r0, [r4] —— r0 = *g_ObjectNumber = 本次的 id */
/* @0x19eee8 str r3, [sp, #0x104] */
/* @0x19eeec bl 0xc4964 <_Z5_itoaiPci> —— _itoa(id, buf, 10) */
/* @0x19eef0 mov r0, #220 —— sizeof(CObjectGM) = 220 */
/* @0x19eef4 bl 0x27c524 <_Znwj> —— operator new */
/* @0x19eef8 ldr r1, [r4] —— r1 = *g_ObjectNumber（未变） */
/* @0x19eefc mov r8, r0 —— r8 = 新对象 */
/* @0x19ef00 bl 0x19d4f4 <_ZN9CObjectGMC2Ei> —— CObjectGM::C2(id) */
/* @0x19ef04 mov r0, r7 */
/* @0x19ef08 bl 0xb6538 <strlen@plt> */
/* @0x19ef0c ldr r1, [pc, #0xf0] —— 池 0x1adfac → 0x34cecc（Object_Main.cpp） */
/* @0x19ef10 mov r2, #226 —— Alloc 行号 226 */
/* @0x19ef14 mov r3, #1 */
/* @0x19ef18 add r1, pc, r1 */
/* @0x19ef1c add r0, r0, #12 —— size = strlen+12 */
/* @0x19ef20 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— MemoryManager::Alloc(size, 文件, 226, true) */
/* @0x19ef24 ldr r3, [pc, #0xdc] —— 池 0x1adfd4 → 0x34cf04（"__newobject"） */
/* @0x19ef28 add r3, pc, r3 */
/* @0x19ef2c mov r5, r0 —— r5 = 名字块 */
/* @0x19ef30 ldm r3!, {r0, r1, r2} —— 三个字 = "__ne"/"wobj"/"ect\0" */
/* @0x19ef34 str r2, [r5, #0x8] */
/* @0x19ef38 str r0, [r5] */
/* @0x19ef3c add r0, r5, #11 —— 落点 = 块+11 */
/* @0x19ef40 str r1, [r5, #0x4] */
/* @0x19ef44 mov r1, r7 */
/* @0x19ef48 bl 0xb65a4 <strcpy@plt> —— strcpy(块+11, buf) */
/* @0x19ef4c mov r1, r5 */
/* @0x19ef50 mov r0, r8 */
/* @0x19ef54 bl 0x19d348 <_ZN9CObjectGM10SetNameRefEPc> —— SetNameRef(名字块) —— 接管不复制 */
/* @0x19ef58 ldr r12, [pc, #0xac] —— 池 0x24ecd8 → GOT 0x3edc44（&g_ObjectHash） */
/* @0x19ef5c ldr r1, [pc, #0xac] —— 池 0x1add40 → 0x34ccb4（Hash.h） */
/* @0x19ef60 movw r2, #0x132 —— Alloc 行号 306 */
/* @0x19ef64 ldr r12, [pc, r12] —— 表结构 */
/* @0x19ef68 mov r3, #1 */
/* @0x19ef6c add r1, pc, r1 */
/* @0x19ef70 mov r0, #16 —— 节点 16 B */
/* @0x19ef74 ldr r5, [r12] */
/* @0x19ef78 ldr r10, [r4] —— r10 = id */
/* @0x19ef7c ldm r5, {r7, r9} —— r7 = buckets, r9 = mask */
/* @0x19ef80 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— MemoryManager::Alloc(16, Hash.h, 306, true) */
/* @0x19ef84 and r9, r10, r9 —— 桶下标 = id & mask */
/* @0x19ef88 ldr r1, [r7, r9, lsl #3] —— r1 = 桶头 */
/* @0x19ef8c add r2, r7, r9, lsl #3 —— r2 = &bucket */
/* @0x19ef90 cmp r1, #0 */
/* @0x19ef94 ldrne r1, [r2, #0x4] —— 非空桶：r1 = 旧尾 */
/* @0x19ef98 mov r3, r0 —— r3 = 节点 */
/* @0x19ef9c str r8, [r0, #0xc] —— node->value = obj */
/* @0x19efa0 str r10, [r0, #0x8] —— node->key = id */
/* @0x19efa4 movne r0, #0 —— 非空桶把 r0 清 0 */
/* @0x19efa8 streq r0, [r2, #0x4] —— 空桶：bucket.tail = 节点 */
/* @0x19efac strne r1, [r3] —— 非空桶：node->prev = 旧尾 */
/* @0x19efb0 strne r3, [r1, #0x4] —— 旧尾->next = 节点 */
/* @0x19efb4 strne r3, [r2, #0x4] —— bucket.tail = 节点 */
/* @0x19efb8 strne r0, [r3, #0x4] —— node->next = 0 */
/* @0x19efbc ldr r2, [sp, #0x104] */
/* @0x19efc0 ldr r3, [r6] */
/* @0x19efc4 streq r0, [r7, r9, lsl #3] —— 空桶：bucket.head = 节点 */
/* @0x19efc8 streq r1, [r0] —— 空桶：node->prev = 0 */
/* @0x19efcc streq r1, [r0, #0x4] —— 空桶：node->next = 0 */
/* @0x19efd0 cmp r2, r3 —— 栈保护比较 */
/* @0x19efd4 ldr r0, [r4] —— r0 = 自增前的 id（出口残留值） */
/* @0x19efd8 ldr r3, [r5, #0x8] —— r3 = 表计数 */
/* @0x19efdc add r2, r0, #1 */
/* @0x19efe0 str r2, [r4] —— g_ObjectNumber = id+1 */
/* @0x19efe4 add r3, r3, #1 */
/* @0x19efe8 str r3, [r5, #0x8] —— 表计数 +1 */
/* @0x19efec bne 0x19eff8 <_Z10Object_Addv+0x13c> —— 不相等 → __stack_chk_fail */
/* @0x19eff0 add sp, sp, #264 */
/* @0x19eff4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x19eff8 bl 0xb65d4 <__stack_chk_fail@plt> —— __stack_chk_fail@plt */

/* ── 字面量池（0x19effc..0x19f010，6 字；反汇编器把数据字译成了指令，实为数据）──────────────────
 *   0x19effc = 0x0024ea7c → 0x19eedc + 该值 = 0x3ed958（GOT：&__stack_chk_guard）
 *   0x19f000 = 0x00251808 → 0x19eedc + 该值 = 0x3f06ec（GOT：&g_ObjectNumber）
 *   0x19f004 = 0x001adfac → 0x19ef20 + 该值 = 0x34cecc（"…/Files/Object/Object_Main.cpp"）
 *   0x19f008 = 0x001adfd4 → 0x19ef30 + 该值 = 0x34cf04（"__newobject"，12 B 含 NUL）
 *   0x19f00c = 0x0024ecd8 → 0x19ef6c + 该值 = 0x3edc44（GOT：&g_ObjectHash）
 *   0x19f010 = 0x001add40 → 0x19ef74 + 该值 = 0x34ccb4（"…/Platform/Hash.h"） */
/* @0x19effc eoreq lr, r4, r12, ror r10 —— 非指令：→ 0x3ed958 */
/* @0x19f000 eoreq r1, r5, r8, lsl #16 —— 非指令：→ 0x3f06ec */
/* @0x19f004 andseq sp, r10, r12, lsr #31 —— 非指令：→ 0x34cecc */
/* @0x19f008 ldrsbeq sp, [r10], -r4 —— 非指令：→ 0x34cf04 */
/* @0x19f00c .word 0x0024ecd8 —— 非指令：→ 0x3edc44 */
/* @0x19f010 andseq sp, r10, r0, asr #26 —— 非指令：→ 0x34ccb4 */

/* ══ §2 Object_Prepare 0x19ebb4 ═════════════════════════════════════════════
 * @func 0x19ebb4 0x19ecf4 size 324  81 条（74 指令 + 7 池字；末指令 0x19ecd8，函数尾 0x19ecf8 = Object_Exists）
 * 级别: 正文（81/81。控制流是「一遍表遍历 + 两个虚调用 + 一次 Compile + 一次 PatchParents」，两个提前出口都已钉）
 * 符号: _Z14Object_Preparev → int Object_Prepare()（返回 0/1，调用方只判 0）
 * 位置: 0x19ebb4；前接 §3 Object_Load(0x19ea7c..0x19ebb0)，后接 Object_Exists 0x19ecf8
 * 调用点: 全图唯一 —— 0x1df7cc 在 PrepareGame 0x1df714（504 B）里；PrepareGame 的唯一调用点又是 0x2a1720
 *         （DoTheWork 0x2a16dc，紧接在 RunnerLoadWad + Variable_Global_Init + 一次控制台打印之后）
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   启动期把所有对象编译一遍：先往控制台打 "Preparing %d objects:\n"（%d = g_ObjectNumber），
 *   然后遍历 g_ObjectHash 的每个桶/每个节点，逐条打印 "\tObjects %d: %s\n"（对象号 + 名字）、
 *   把 Current_Object 设成该对象号、调 CObjectGM::Compile()；任一 Compile 返回 0 就立刻返回 0
 *   （**不调 PatchParents**）；全部成功才 PatchParents() 并返回 1。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   int Object_Prepare() {
 *     Console* c = g_Console;                                   // 0x3efb24 → 0x3eb6b8 → 0x479d08
 *     c->vtbl->Print("Preparing %d objects:\n", g_ObjectNumber); // vtable+0xc
 *     HashTable* t = g_ObjectHash;                              // 指针变量 → 表结构
 *     for (int i = 0; i <= t->mask; i++)                        // 上界每轮重读 [t+4]
 *       for (Node* n = t->bucket[i].head; n; n = n->next) {     // node+0x4
 *         CObjectGM* o = n->value;                              // node+0xc
 *         if (!o) { PatchParents(); return 1; }                 // 整轮提前结束，不是跳过
 *         c->vtbl->Print("\tObjects %d: %s\n", o->id, o->name); // +0x18 / +0x14
 *         Current_Object = o->id;                               // 0x54290c
 *         if (!o->Compile()) return 0;                          // 0x19d9f4；失败不 PatchParents
 *       }
 *     PatchParents();                                          // 0x19e978
 *     return 1;
 *   }
 *
 * ── 逐段 ─────────────────────────────────────────────────────────────────
 *   ① 0x19ebb4..0x19ebf0 打印头：r8 = GOT 基址 0x3f1c58；槽 0x3efb24 → 0x3eb6b8 → 控制台对象 0x479d08
 *      （DoTheWork 卡已钉这条链）；r1 = 0x34cea0 "Preparing %d objects:\n"；r2 = *g_ObjectNumber；
 *      blx [*console + 0xc]（虚调用第 4 槽）。
 *   ② 0x19ebf4..0x19ec04 取表：槽 0x3edc44 → 0x542374 → 表结构 → r10；r2 = [r10] = 桶数组；b 到循环头。
 *   ③ 0x19ec08..0x19ec20 外层：r5 = 0 起、每轮 r3 = [r10+4]（掩码）重读、r5++、bgt 退出（r5 > mask 才停
 *      ⇒ 桶数 = mask+1）；桶头为 0 → 回 0x19ec08 取下一个桶。
 *   ④ 0x19ec24..0x19ec2c 首节点取值 + 判空：r6 = node->value；为 0 → 0x19ecd0（收尾），不是跳过。
 *   ⑤ 0x19ec30..0x19ec94 每对象：r8 = 槽 0x3eddc0 → Current_Object 的地址；r9 = 0x34ceb8；
 *      循环体先重取 r6 = node->value（0x19ec44）；虚调用 (console, fmt2, obj->+0x18, obj->+0x14)；
 *      Current_Object = obj->+0x18（0x19ec6c/0x19ec74）；Compile()；返回 0 → popeq 返回 0；
 *      然后 node = node->+0x4，非 0 回循环体。
 *   ⑥ 0x19ec98..0x19eccc 换桶：当前链走完，从 r5+1 起在剩下的桶里线性找下一个非空桶
 *      （r2 = 桶基址 + r5*8、每步 +8；上限仍从 [r10+4] 重读），遇到非空 → 回循环体。
 *   ⑦ 0x19ecd0..0x19ecd8 收尾：PatchParents(); return 1。
 *
 * ── 已证（每条都指到指令）────────────────────────────────────────────────
 *   1. 唯一调用者 PrepareGame 0x1df714（bl 0x1df7cc）；返回 0 时 PrepareGame 在 0x1df7d0/0x1df7d4 直接跳失败出口，
 *      PrepareGame 的唯一调用点 0x2a1720（DoTheWork）再用 subs/bne 判 0、为 0 就直接 return 0（不进 Run_Start 0x1d4ed8）
 *      ⇒ 「Prepare 失败 = 启动失败」；链路 = DoTheWork → PrepareGame → Object_Prepare。
 *   2. 两处 blx 是同一对象（0x479d08）、同一 vtable 槽（+0xc）：第一处实参 (fmt, g_ObjectNumber)，
 *      第二处 (fmt, obj->+0x18, obj->+0x14) ⇒ 控制台打印的实际形状，也是 +0x18/+0x14 语义的旁证
 *      （+0x18 = 对象号、+0x14 = 名字，与 §1/§3 一致）。
 *   3. 遍历上界取 [表+4]（掩码）、并且**每轮重读**（0x19ec08/0x19ec98），不是 [表+8] 的计数 ⇒
 *      计数只用于统计，遍历按桶。
 *   4. Current_Object 在 Compile 之前写入对象号（0x19ec6c ldr r3,[r6,#0x18] / 0x19ec74 str r3,[r8]）
 *      ⇒ 编译期间 Current_Object = 正在编译的对象（Perform_Event_Object 卡里同名全局用作「当前对象」）。
 *   5. 失败出口 0x19ec80 是 popeq：返回 0 且**跳过 PatchParents**；成功出口 0x19ecd0 必调 PatchParents 再返回 1。
 *   6. 节点 value 为 0 的两处（0x19ec2c 首节点、0x19ec4c 链上）都跳到 0x19ecd0 —— 提前结束但仍返回 1，
 *      是一条静默截断路径（表里只要有一个空 value，后面的对象不会被编译）。
 *   7. 本函数不分配、不释放：4 个调用（控制台虚调用 ×2、Compile、PatchParents）+ 全函数唯一的一条 str
 *      （0x19ec74 写 Current_Object），其余 30 条 ldr 全是读。
 *   8. 无判空：g_ObjectHash 为 0 时 0x19ebfc 直接解引用崩；控制台对象为 0 时 0x19ebe4 同样崩。
 *   9. 返回值只有 0/1：0 只来自 Compile 失败（0x19ec7c 的 cmp），1 来自 0x19ecd4。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · 控制台 +0xc 虚函数的正式名与可变参编码未证（本卡只证实参形状；DoTheWork 卡只钉了对象身份）。
 *   · Compile() 0x19d9f4 的返回语义（0 = 失败）未在本卡展开；它是否可能返回 0 取决于对象里的代码表，未验证。
 *   · PatchParents 0x19e978 未出卡：本卡只借它说明「遍历结束才回填父链」（0x19e9c4 读 obj+0xc、
 *     0x19ea08/0x19ea0c 写 obj+0x48），它自己的分支/边界不在本卡。
 *   · 表为空（掩码 0 且桶 0 空）时只打印头、直接返回 1；这条路径未在真机取证。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */
/* @0x19ebb4 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x19ebb8 mov r5, #0 —— r5 = 0（桶下标） */
/* @0x19ebbc ldr r8, [pc, #0x118] —— 池 0x25308c → GOT 基址 0x3f1c58 */
/* @0x19ebc0 ldr r2, [pc, #0x118] —— 池 0xffffdecc → 0x3efb24（控制台槽） */
/* @0x19ebc4 add r8, pc, r8 */
/* @0x19ebc8 ldr r3, [pc, #0x114] —— 池 0xffffea94 → 0x3f06ec（&g_ObjectNumber） */
/* @0x19ebcc ldr r1, [pc, #0x114] —— 池 0x1ae2c0 → 0x34cea0（"Preparing %d objects:\n"） */
/* @0x19ebd0 ldr r2, [r8, r2] —— r2 = &控制台指针槽 */
/* @0x19ebd4 ldr r3, [r8, r3] */
/* @0x19ebd8 add r1, pc, r1 */
/* @0x19ebdc ldr r7, [r2] —— r7 = 控制台对象 0x479d08 */
/* @0x19ebe0 ldr r2, [r3] —— r2 = *g_ObjectNumber */
/* @0x19ebe4 ldr r3, [r7] —— r3 = console->vtable */
/* @0x19ebe8 mov r0, r7 */
/* @0x19ebec ldr r3, [r3, #0xc] —— vtable+0xc */
/* @0x19ebf0 blx r3 —— printf(fmt, g_ObjectNumber) */
/* @0x19ebf4 ldr r3, [pc, #0xf0] —— 池 0xffffbfec → 0x3edc44（&g_ObjectHash） */
/* @0x19ebf8 ldr r3, [r8, r3] */
/* @0x19ebfc ldr r10, [r3] —— r10 = 表结构 */
/* @0x19ec00 ldr r2, [r10] —— r2 = 桶数组 */
/* @0x19ec04 b 0x19ec18 <_Z14Object_Preparev+0x64> */
/* @0x19ec08 ldr r3, [r10, #0x4] —— 掩码每轮重读 */
/* @0x19ec0c add r5, r5, #1 */
/* @0x19ec10 cmp r5, r3 */
/* @0x19ec14 bgt 0x19ecd0 <_Z14Object_Preparev+0x11c> —— r5 > mask → 收尾 */
/* @0x19ec18 ldr r4, [r2, r5, lsl #3] —— r4 = bucket[r5] */
/* @0x19ec1c cmp r4, #0 */
/* @0x19ec20 beq 0x19ec08 <_Z14Object_Preparev+0x54> —— 空桶 → 下一个 */
/* @0x19ec24 ldr r6, [r4, #0xc] —— r6 = node->value */
/* @0x19ec28 cmp r6, #0 */
/* @0x19ec2c beq 0x19ecd0 <_Z14Object_Preparev+0x11c> —— 空 value → 收尾（不跳过） */
/* @0x19ec30 ldr r3, [pc, #0xb8] —— 池 0xffffc168 → 0x3eddc0（&Current_Object） */
/* @0x19ec34 ldr r9, [pc, #0xb8] —— 池 0x1ae274 → 0x34ceb8（"\tObjects %d: %s\n"） */
/* @0x19ec38 ldr r8, [r8, r3] */
/* @0x19ec3c add r9, pc, r9 */
/* @0x19ec40 b 0x19ec50 <_Z14Object_Preparev+0x9c> */
/* @0x19ec44 ldr r6, [r4, #0xc] —— 重取 node->value */
/* @0x19ec48 cmp r6, #0 */
/* @0x19ec4c beq 0x19ecd0 <_Z14Object_Preparev+0x11c> —— 空 value → 收尾 */
/* @0x19ec50 ldr r12, [r7] —— r12 = 控制台 vtable */
/* @0x19ec54 mov r0, r7 */
/* @0x19ec58 mov r1, r9 —— r1 = fmt2 */
/* @0x19ec5c ldr r2, [r6, #0x18] —— r2 = obj->+0x18（对象号） */
/* @0x19ec60 ldr r3, [r6, #0x14] —— r3 = obj->+0x14（名字） */
/* @0x19ec64 ldr r12, [r12, #0xc] */
/* @0x19ec68 blx r12 —— printf(fmt2, id, name) */
/* @0x19ec6c ldr r3, [r6, #0x18] */
/* @0x19ec70 mov r0, r6 */
/* @0x19ec74 str r3, [r8] —— Current_Object = obj->id */
/* @0x19ec78 bl 0x19d9f4 <_ZN9CObjectGM7CompileEv> —— CObjectGM::Compile() */
/* @0x19ec7c cmp r0, #0 */
/* @0x19ec80 popeq {r4, r5, r6, r7, r8, r9, r10, pc} —— Compile 失败 → 直接返回 0（跳过 PatchParents） */
/* @0x19ec84 cmp r4, #0 */
/* @0x19ec88 beq 0x19ecd0 <_Z14Object_Preparev+0x11c> */
/* @0x19ec8c ldr r4, [r4, #0x4] —— node = node->next */
/* @0x19ec90 cmp r4, #0 */
/* @0x19ec94 bne 0x19ec44 <_Z14Object_Preparev+0x90> —— 非 0 回循环体 */
/* @0x19ec98 ldr r1, [r10, #0x4] */
/* @0x19ec9c add r3, r5, #1 */
/* @0x19eca0 cmp r3, r1 */
/* @0x19eca4 bgt 0x19ecd0 <_Z14Object_Preparev+0x11c> —— 越界 → 收尾 */
/* @0x19eca8 ldr r2, [r10] */
/* @0x19ecac add r2, r2, r5, lsl #3 —— r2 = 桶基址 + r5*8 */
/* @0x19ecb0 ldr r4, [r2, #0x8] —— 下一个桶头 */
/* @0x19ecb4 mov r5, r3 */
/* @0x19ecb8 add r2, r2, #8 */
/* @0x19ecbc add r3, r3, #1 */
/* @0x19ecc0 cmp r4, #0 */
/* @0x19ecc4 bne 0x19ec44 <_Z14Object_Preparev+0x90> —— 非空 → 回循环体 */
/* @0x19ecc8 cmp r3, r1 */
/* @0x19eccc ble 0x19ecb0 <_Z14Object_Preparev+0xfc> */
/* @0x19ecd0 bl 0x19e978 <_Z12PatchParentsv> —— PatchParents() */
/* @0x19ecd4 mov r0, #1 —— return 1 */
/* @0x19ecd8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 字面量池（0x19ecdc..0x19ecf4，7 字；全被译成指令，实为数据）──────────────────────────
 *   0x19ecdc = 0x0025308c → 0x19ebcc + 该值 = 0x3f1c58（GOT 基址）
 *   0x19ece0 = 0xffffdecc → 0x3f1c58 - 0x2134 = 0x3efb24（控制台槽）
 *   0x19ece4 = 0xffffea94 → 0x3f1c58 - 0x156c = 0x3f06ec（&g_ObjectNumber）
 *   0x19ece8 = 0x001ae2c0 → 0x19ebe0 + 该值 = 0x34cea0（"Preparing %d objects:\n"）
 *   0x19ecec = 0xffffbfec → 0x3f1c58 - 0x4014 = 0x3edc44（&g_ObjectHash）
 *   0x19ecf0 = 0xffffc168 → 0x3f1c58 - 0x3e98 = 0x3eddc0（&Current_Object）
 *   0x19ecf4 = 0x001ae274 → 0x19ec44 + 该值 = 0x34ceb8（"\tObjects %d: %s\n"） */
/* @0x19ecdc eoreq r3, r5, r12, lsl #1 —— 非指令：→ 0x3f1c58 */
/* @0x19ece0 .word 0xffffdecc —— 非指令：→ 0x3efb24 */
/* @0x19ece4 .word 0xffffea94 —— 非指令：→ 0x3f06ec */
/* @0x19ece8 andseq lr, r10, r0, asr #5 —— 非指令：→ 0x34cea0 */
/* @0x19ecec .word 0xffffbfec —— 非指令：→ 0x3edc44 */
/* @0x19ecf0 .word 0xffffc168 —— 非指令：→ 0x3eddc0 */
/* @0x19ecf4 andseq lr, r10, r4, ror r2 —— 非指令：→ 0x34ceb8 */

/* ══ §3 Object_Load 0x19ea7c ════════════════════════════════════════════════
 * @func 0x19ea7c 0x19ebb0 size 312  78 条（74 指令 + 4 池字；末指令 0x19eba0，函数尾 0x19ebb4 = §2 的入口）
 * 级别: 正文（78/78。OBJT 块的记录布局、偏移基址、跳过条件、名字所有权、插表、父链回填时机全部钉死；
 *       没钉的只有第二实参的用途与 LoadFromChunk 内部）
 * 符号: _Z11Object_LoadPhjS_ → Object_Load(unsigned char* pTable, unsigned int unused, unsigned char* pBase)
 *       （返回类型在符号里不可见；唯一出口 0x19eb98 mov r0,#1 ⇒ 事实上恒 true）
 * 位置: 0x19ea7c；前接 PatchParents 0x19e978（0x19ea78 是这个函数的末池字），后接 §2 Object_Prepare 0x19ebb4
 * 调用点: 全图唯一 —— 0x1de54c 在 LoadGameData 0x1ddce4 的 OBJT 分支（块名常量 0x544a424f，见 0x1de2b0/0x1de2b8）
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   装 OBJT 块：把块头条数写进 g_ObjectNumber，然后对 i = 0..count-1 逐条 new CObjectGM(i)、
 *   用 g_pWADBaseAddress + 偏移_i 找到对象记录、LoadFromChunk(记录, 第三实参)、
 *   SetName(base + 记录[0]) 复制名字、把 {i, obj} 尾插进 g_ObjectHash；全部装完 PatchParents() 并返回 1。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   int Object_Load(unsigned char* pTable, unsigned int unused, unsigned char* pBase) {
 *     int count = ((int32_t*)pTable)[0];                  // 0x19ea84
 *     g_ObjectNumber = count;                             // 0x19ea98（无条件，先写再判）
 *     if (count <= 0) { PatchParents(); return 1; }       // 0x19ea9c ble
 *     for (int i = 0; i < g_ObjectNumber; i++) {          // 上界每轮重读 g_ObjectNumber
 *       int32_t off = ((int32_t*)pTable)[1 + i];          // 0x19eab4 ldr r5,[r7,#4]!
 *       if (off == 0) continue;                           // 0x19eac0
 *       unsigned char* chunk = (unsigned char*)g_pWADBaseAddress + off;  // 0x19eacc/0x19ead0
 *       if (chunk == 0) continue;                         // 0x19ead4 adds/beq
 *       CObjectGM* o = new CObjectGM(i);                  // new(220) + C2(i)
 *       o->LoadFromChunk((YYObject*)chunk, pBase);         // 0x19eaf4；第三实参原样透传
 *       int32_t nameOff = *(int32_t*)chunk;                // 0x19eaf8 = base+off 处的第一个字
 *       o->SetName(nameOff ? (char*)((char*)g_pWADBaseAddress + nameOff) : 0);  // 复制
 *       // 插表：与 §1 同一段 Hash.h:306 内联代码，key = i，value = o
 *     }
 *     PatchParents();                                     // 0x19eb94
 *     return 1;                                           // 0x19eb98 mov r0,#1
 *   }
 *
 * ── OBJT 块的实际形状（本卡最硬的一段：代码 + 真数据双向对齐）────────────────────
 *   入参 pTable 指向块的一个 payload，布局 = { int32 count; int32 offset[count]; }，
 *   offset 是**相对 g_pWADBaseAddress 的绝对偏移**（不是相对 payload、也不是相对上一个记录）。
 *   证据链（代码侧）：
 *     · 0x19ea84 ldr r3,[r0] → 条数；0x19ea98 str r3,[r8] → 写 g_ObjectNumber；
 *     · 0x19eaa8 mov r7,r0 后 0x19eab4 ldr r5,[r7,#4]! → 第 i 个 int32，游标每次 +4；
 *     · 0x19eacc ldr r11,[r10] → r11 = *g_pWADBaseAddress；0x19ead0 adds r9,r11,r5 → 记录指针 = 基址 + 偏移；
 *     · 0x19eaf8 ldr r2,[r11,r5] → 记录的第一个字（名字偏移），0x19eb08/0x19eb0c 再加回同一个基址。
 *   证据链（数据侧，assets/game.droid 实测；OBJT 块头在 0x5be58、payload 在 0x5be60、块长 97244）：
 *     · payload[0] = 191（= LoadGameData 卡记的「OBJT 97244 B（191）」）；
 *     · 191 个偏移全部落在 payload 内且严格递增：0x5c160 … 0x73658；
 *     · 每个记录的第一个字都指向 STRG 段里的名字串，191/191 可解：
 *       记录 0 → "obj_player"（其余字段按 LoadFromChunk 的写入顺序读：sprite 0x1d、visible 1、solid 0、
 *       depth 0、persistent 1、parent -100、mask -1）；记录 1 → "obj_tree"；记录 2 → "obj_house"；末条 → "obj_bosspuff"。
 *     ⇒ 「WAD 绝对偏移」这条有数据实证，不是从代码反推的假设。
 *
 * ── 逐段 ─────────────────────────────────────────────────────────────────
 *   ① 0x19ea7c..0x19ea9c 头：push {r4..r11,lr} + sub sp,#12；r3 = [pTable] 条数；[sp] = 第三实参；
 *      r8 = GOT 0x3f06ec（&g_ObjectNumber）；*r8 = 条数；条数 <= 0（有符号 ble）→ 0x19eb94。
 *   ② 0x19eaa0..0x19eab4：r3 = 0x34ccb4 "…/Platform/Hash.h" 存 [sp+4]（插表 Alloc 的文件串，行号 306 在 0x19eb18）；
 *      r4 = 0（i）；r7 = pTable；ldr r5,[r7,#4]! 取 offset[i] 且游标前移。
 *   ③ 0x19eab8..0x19ead4：offset == 0 → 跳过；r10 = GOT 0x3ed94c（&g_pWADBaseAddress）、r11 = 基址、r9 = 基址+偏移；
 *      r9 == 0 → 跳过（基址与偏移相加恰为 0 才会成立；正常装载下不会）。全段无越界校验。
 *   ④ 0x19ead8..0x19eaf4：new(220) → r6；C2(i)；r1 = 记录、r2 = [sp]（第三实参）、r0 = 对象 → LoadFromChunk。
 *   ⑤ 0x19eaf8..0x19eb10：r2 = *(基址+偏移) = 记录[0]；为 0 → r1 = 0，否则 r1 = 基址 + r2；SetName(r1)（复制）。
 *   ⑥ 0x19eb14..0x19eb80 插表：与 §1 逐条同构（槽 0x3edc44 → 0x542374 → 表结构；Alloc(16, Hash.h, 306, true)；
 *      key = i、value = obj；桶 = i & mask；空桶/尾插两条路；[表+8] += 1）。
 *   ⑦ 0x19eb84..0x19eba0 循环尾与出口：r3 = *g_ObjectNumber（每轮重读）、i++、bgt 回 0x19eab4；
 *      PatchParents(); return 1。
 *
 * ── 已证（每条都指到指令）────────────────────────────────────────────────
 *   1. 唯一调用点 0x1de54c（LoadGameData 的 OBJT 分支）；现场 0x1de540..0x1de54c = r0 = r10+r7、
 *      r1 = r5、r2 = r10 ⇒ 与同族 loader（Shader_Load 0x1de538、Sound_Load 0x1de58c、Path_Load 0x1de5a0）
 *      完全同形的三实参：payload 指针 / 块长 / WAD 基址。
 *   2. 第二实参（unsigned int）在本函数体内**从未被读**：0x19ea7c..0x19eae4 区间没有任何以 r1 为源的指令，
 *      0x19eadc 才第一次写 r1（mov r1,r4）—— 与同族 loader 用 r1 传块长的惯例不一致，是「签名留位、实现不用」。
 *   3. 偏移基址不是第三实参，是全局 g_pWADBaseAddress（0x544c44）：0x19eacc 先取 *g_pWADBaseAddress 再 0x19ead0 相加；
 *      名字偏移同样加回这个全局（0x19eb08 ldrne r1,[r10] / 0x19eb0c addne），第三实参只被原样转交 LoadFromChunk。
 *   4. 名字所有权与 §1 相反：SetName（0x19d2d4..0x19d340）先 Free 旧 +0x14，再 Alloc(strlen+1) + memcpy ⇒
 *      名字被复制出 WAD 缓冲区，对象不持有指向 game.droid 的指针；chunk[0] == 0 时 SetName(0) 只清名字（0x19d2f8 popeq）。
 *   5. 对象号 = 循环下标 i（0x19eadc mov r1,r4）⇒ 对象号就是 OBJT 记录序号；装完 g_ObjectNumber = count（= 191），
 *      后续 §1 从 191 起发号，两个函数的号段天然不重叠。
 *   6. 循环上界每轮从 g_ObjectNumber 重读（0x19eb84），而该全局只在 0x19ea98 写过一次 ⇒ 若循环体内有代码改它，
 *      循环长度会变；本卡的两个被调方（LoadFromChunk/SetName）都不写它，所以实际边界 = 条数。
 *   7. 唯一出口 0x19eb98 mov r0,#1；没有失败返回、没有越界校验、没有异常保护 ⇒ 偏移/名字偏移落在垃圾上会直接崩
 *      （与 CRoom::LoadFromChunk 卡「没有失败路径」同一种风格）。
 *   8. count 为负时 g_ObjectNumber 会被写成负值（0x19ea98 在 0x19ea9c 的 ble 之前执行），随后直接 PatchParents 返回 1
 *      ⇒ 一个畸形块能把全局对象号写成负数（实际后果未证，记 open）。
 *   9. 插表键与 §1 的差别只有来源：§3 用 r4（循环下标）、§1 用 r10（*g_ObjectNumber）；两处 Alloc 的文件串/行号
 *      （Hash.h 第 306 行）与节点大小 16 完全相同 ⇒ 同一个 HashTable::Add 被内联了两次。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · LoadFromChunk 0x19d688 拿第三实参做什么：它一进门 0x19d698 str r2,[sp,#4] 收下了，但后续用途不在本卡锚点内。
 *   · 记录 +0x04..+0x1c 的字段名（sprite / visible / solid / depth / persistent / parent / mask）来自
 *     LoadFromChunk 的写入顺序（0x19d6d8..0x19d738），属该函数的卡；本卡只用到记录[0]。
 *   · count 与 payload 实际长度的关系没有任何校验（本卡只证「条数被直接信任」）。
 *   · offset 为 0 被当作「空槽」跳过，但 0 也是合法的「基址本身」偏移 —— 语义上为什么禁掉 0，未证。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */
/* @0x19ea7c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x19ea80 sub sp, sp, #12 —— 帧 12 B：只放第三实参 */
/* @0x19ea84 ldr r3, [r0] —— r3 = pTable[0] = 条数 */
/* @0x19ea88 ldr r8, [pc, #0x114] —— 池 0x251c50 → GOT 0x3f06ec（&g_ObjectNumber） */
/* @0x19ea8c cmp r3, #0 —— 条数 <= 0 ? */
/* @0x19ea90 str r2, [sp] —— [sp] = 第三实参 */
/* @0x19ea94 ldr r8, [pc, r8] */
/* @0x19ea98 str r3, [r8] —— g_ObjectNumber = 条数（无条件） */
/* @0x19ea9c ble 0x19eb94 <_Z11Object_LoadPhjS_+0x118> —— <= 0 → 0x19eb94 收尾 */
/* @0x19eaa0 ldr r3, [pc, #0x100] —— 池 0x1ae200 → 0x34ccb4（Hash.h） */
/* @0x19eaa4 mov r4, #0 —— i = 0 */
/* @0x19eaa8 mov r7, r0 —— r7 = pTable */
/* @0x19eaac add r3, pc, r3 */
/* @0x19eab0 str r3, [sp, #0x4] —— [sp+4] = 文件串 */
/* @0x19eab4 ldr r5, [r7, #0x4]! —— r5 = offset[i]，游标 +4 */
/* @0x19eab8 mov r0, #220 —— sizeof(CObjectGM) = 220 */
/* @0x19eabc ldr r10, [pc, #0xe8] —— 池 0x24ee7c → GOT 0x3ed94c（&g_pWADBaseAddress） */
/* @0x19eac0 cmp r5, #0 —— offset == 0 ? */
/* @0x19eac4 beq 0x19eb84 <_Z11Object_LoadPhjS_+0x108> —— 跳过 */
/* @0x19eac8 ldr r10, [pc, r10] */
/* @0x19eacc ldr r11, [r10] —— r11 = *g_pWADBaseAddress */
/* @0x19ead0 adds r9, r11, r5 —— r9 = 基址 + offset */
/* @0x19ead4 beq 0x19eb84 <_Z11Object_LoadPhjS_+0x108> —— 记录指针为 0 → 跳过 */
/* @0x19ead8 bl 0x27c524 <_Znwj> —— operator new(220) */
/* @0x19eadc mov r1, r4 —— r1 = i（对象号 = 记录序号） */
/* @0x19eae0 mov r6, r0 —— r6 = 新对象 */
/* @0x19eae4 bl 0x19d4f4 <_ZN9CObjectGMC2Ei> —— CObjectGM::C2(i) */
/* @0x19eae8 mov r1, r9 —— r1 = 记录 */
/* @0x19eaec ldr r2, [sp] —— r2 = 第三实参（原样透传） */
/* @0x19eaf0 mov r0, r6 */
/* @0x19eaf4 bl 0x19d688 <_ZN9CObjectGM13LoadFromChunkEP8YYObjectPh> —— LoadFromChunk(记录, 第三实参) */
/* @0x19eaf8 ldr r2, [r11, r5] —— r2 = 记录[0]（名字偏移） */
/* @0x19eafc mov r0, r6 */
/* @0x19eb00 cmp r2, #0 */
/* @0x19eb04 mov r1, r2 */
/* @0x19eb08 ldrne r1, [r10] —— r1 = 基址 */
/* @0x19eb0c addne r1, r1, r2 —— r1 = 基址 + 名字偏移 */
/* @0x19eb10 bl 0x19d2d4 <_ZN9CObjectGM7SetNameEPc> —— SetName（复制） */
/* @0x19eb14 ldr r12, [pc, #0x94] —— 池 0x24f11c → 0x3edc44（&g_ObjectHash） */
/* @0x19eb18 movw r2, #0x132 —— Alloc 行号 306 */
/* @0x19eb1c mov r3, #1 */
/* @0x19eb20 ldr r12, [pc, r12] */
/* @0x19eb24 mov r0, #16 —— 节点 16 B */
/* @0x19eb28 ldr r1, [sp, #0x4] */
/* @0x19eb2c ldr r5, [r12] —— r5 = 表结构 */
/* @0x19eb30 ldm r5, {r9, r12} —— r9 = buckets, r12 = mask */
/* @0x19eb34 and r10, r4, r12 —— 桶下标 = i & mask */
/* @0x19eb38 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> —— Alloc(16, Hash.h, 306, true) */
/* @0x19eb3c ldr r2, [r9, r10, lsl #3] —— r2 = 桶头 */
/* @0x19eb40 add r3, r9, r10, lsl #3 —— r3 = &bucket */
/* @0x19eb44 cmp r2, #0 */
/* @0x19eb48 ldrne r2, [r3, #0x4] —— 非空桶：r2 = 旧尾 */
/* @0x19eb4c str r4, [r0, #0x8] —— node->key = i */
/* @0x19eb50 str r6, [r0, #0xc] —— node->value = obj */
/* @0x19eb54 strne r2, [r0] —— 非空桶：node->prev = 旧尾 */
/* @0x19eb58 streq r0, [r3, #0x4] —— 空桶：bucket.tail = 节点 */
/* @0x19eb5c strne r0, [r2, #0x4] —— 旧尾->next = 节点 */
/* @0x19eb60 strne r0, [r3, #0x4] —— bucket.tail = 节点 */
/* @0x19eb64 movne r3, #0 —— 非空桶把 r3 清 0 */
/* @0x19eb68 strne r3, [r0, #0x4] —— node->next = 0 */
/* @0x19eb6c ldr r3, [r5, #0x8] —— r3 = 表计数 */
/* @0x19eb70 streq r0, [r9, r10, lsl #3] —— 空桶：bucket.head = 节点 */
/* @0x19eb74 add r3, r3, #1 */
/* @0x19eb78 streq r2, [r0, #0x4] —— 空桶：node->next = 0 */
/* @0x19eb7c streq r2, [r0] —— 空桶：node->prev = 0 */
/* @0x19eb80 str r3, [r5, #0x8] —— 表计数 +1 */
/* @0x19eb84 ldr r3, [r8] —— r3 = *g_ObjectNumber（每轮重读） */
/* @0x19eb88 add r4, r4, #1 —— i++ */
/* @0x19eb8c cmp r3, r4 */
/* @0x19eb90 bgt 0x19eab4 <_Z11Object_LoadPhjS_+0x38> —— 还有剩余 → 回 0x19eab4 */
/* @0x19eb94 bl 0x19e978 <_Z12PatchParentsv> —— PatchParents() */
/* @0x19eb98 mov r0, #1 —— return 1 */
/* @0x19eb9c add sp, sp, #12 */
/* @0x19eba0 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 字面量池（0x19eba4..0x19ebb0，4 字）────────────────────────────────────────────
 *   0x19eba4 = 0x00251c50 → 0x19ea9c + 该值 = 0x3f06ec（&g_ObjectNumber）
 *   0x19eba8 = 0x001ae200 → 0x19eab4 + 该值 = 0x34ccb4（"…/Platform/Hash.h"）
 *   0x19ebac = 0x0024ee7c → 0x19ead0 + 该值 = 0x3ed94c（&g_pWADBaseAddress）
 *   0x19ebb0 = 0x0024f11c → 0x19eb28 + 该值 = 0x3edc44（&g_ObjectHash） */
/* @0x19eba4 eoreq r1, r5, r0, asr r12 —— 非指令：→ 0x3f06ec */
/* @0x19eba8 andseq lr, r10, r0, lsl #4 —— 非指令：→ 0x34ccb4 */
/* @0x19ebac eoreq lr, r4, r12, ror lr —— 非指令：→ 0x3ed94c */
/* @0x19ebb0 eoreq pc, r4, r12, lsl r1 —— 非指令：→ 0x3edc44 */

/* ══ §4 Object_GetInstance 0x14ec2c ═════════════════════════════════════════
 * @func 0x14ec2c 0x14ed00 size 216  54 条（52 指令 + 2 池字；末指令 0x14ecf8，函数尾 0x14ed04 = F_PhysicsCreateDistanceJoint）
 * 级别: 正文（54/54。四种 id 的分派、两张表的解引用层数、两条出口的返回类型差异、5 个返回点全部钉死）
 * 符号: _Z18Object_GetInstanceiP9CInstanceS0_ → CInstance* Object_GetInstance(int id, CInstance* self, CInstance* other)
 * 位置: 0x14ec2c；其后 0x14ed04 F_PhysicsCreateDistanceJoint（600 B）
 * 调用点: 全图 18 处，全部在 9 个 F_PhysicsCreate*Joint 里（每个函数两次：bodyA / bodyB）：
 *         Distance 0x14ed04、Rope 0x14ef5c、Revolute 0x14f1d0、Prismatic 0x14f4a8、Pulley 0x14f790、
 *         Wheel 0x14fa60、Gear 0x14fd30、Weld 0x14ff68、Friction 0x1501dc
 *
 * ── 一句话 ────────────────────────────────────────────────────────────────
 *   (id, self, other) → CInstance*：id == -1 返回 self、id == -2 返回 other；
 *   id <= 99999 走 g_ObjectHash 找 CObjectGM*，再取它 +0xd0 实例链头节点的 +8（该对象的第一个实例）；
 *   id > 99999 走 ms_ID2Instance 直接拿 CInstance*。找不到一律返回 0。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────────
 *   CInstance* Object_GetInstance(int id, CInstance* self, CInstance* other) {
 *     if (id == -1) return self;                            // 0x14ec2c/0x14ec30 → 0x14ec70
 *     if (id == -2) return other;                           // 0x14ec34/0x14ec38 → 0x14ecac
 *     if (id > 99999) {                                     // 0x14ec3c/0x14ec40/0x14ec44/0x14ec48（有符号）
 *       Node* n = HashFind(&CInstance::ms_ID2Instance, id);  // 0x536f28，一层解引用
 *       return n ? (CInstance*)n->value : 0;                // 0x14ecf0/0x14ecf4
 *     }
 *     Node* n = HashFind(g_ObjectHash, id);                  // 0x542374 → 表结构，两层解引用
 *     if (!n) return 0;                                     // 0x14ec68/0x14ec6c
 *     CObjectGM* o = (CObjectGM*)n->value;                  // node+0xc
 *     if (!o) return 0;                                     // 0x14ec94/0x14ec98
 *     InstNode* h = o->instHead;                            // +0xd0
 *     return h ? (CInstance*)h->inst : 0;                   // h+0x8
 *   }
 *
 * ── id 空间的四段（本函数是唯一分派点）────────────────────────────────────────
 *   值域        走哪张表                解引用层数                     返回
 *   -1          —                       —                              self（第二实参）
 *   -2          —                       —                              other（第三实参）
 *   0..99999    g_ObjectHash 0x542374   GOT 0x3edc44 → 0x542374 → 表    该对象 +0xd0 链头的第一实例
 *   >99999      ms_ID2Instance 0x536f28 GOT 0x3edc4c → 0x536f28       节点里的 CInstance* 本身
 *   ⚠ 阈值比较是 bgt（有符号）：-3、-4… 不特判，落到对象表被 id & 掩码 索引（负数的掩码结果是大正数）。
 *   ⚠ 对象路径只做掩码、不做「< 桶数」检查（掩码本身就保证了范围），也不校验 key 一定存在。
 *
 * ── 两条路径的返回值不是同一种东西（最容易读错的地方）──────────────────────────
 *   对象路径：node+0xc 是 CObjectGM*，还要再取两跳（+0xd0 → 链头节点的 +8）才得到 CInstance*；
 *   实例路径：node+0xc 就是 CInstance*，直接 bx lr（0x14ecf0/0x14ecf4 是**独立出口**，不落到 0x14ec90 那段）。
 *   ⇒ 0x14ecf4 与 0x14eca8 是两个不同的 bx lr；把 0x14ec90 之后的代码当成两条路共用会得出「实例指针还要再解 +0xd0」的错误结论。
 *
 * ── 逐段 ─────────────────────────────────────────────────────────────────
 *   ① 0x14ec2c..0x14ec38 两个哨兵：cmn r0,#1（id == -1）→ 0x14ec70 mov r0,r1；cmn r0,#2（id == -2）→ 0x14ecac mov r0,r2。
 *   ② 0x14ec3c..0x14ec48 阈值：movw 0x869f + movt 0x1 拼出 0x1869f = 99999；cmp + bgt 0x14ecb4。
 *   ③ 0x14ec4c..0x14ec6c 对象表：三层取表（池字 → GOT 0x3edc44 → 0x542374 → 表结构），
 *      ldr 掩码、ldr 桶数组、and 下标、ldr 桶头；为 0 → 0x14ec70 返回 0。
 *   ④ 0x14ec84..0x14ec8c 链走：node+0x8 与 id 比较，不等 → node+0x4 下一个，走到 0 → 0x14ec70 返回 0。
 *   ⑤ 0x14ec90..0x14eca8 命中：r0 = node+0xc（CObjectGM*）；为 0 → 0x14ecf8（bx lr，r0 = 0）；
 *      否则 r0 = [r0+0xd0]（实例链头），非 0 才 ldrne r0,[r0,#8] ⇒ 链空时 r0 保持 0。
 *   ⑥ 0x14ecb4..0x14ecf4 实例表：槽 0x3edc4c → 0x536f28（**本体**，少一层解引用）；同样的桶/节点形状；
 *      命中 → ldr r0,[node+0xc] 后直接 bx lr。
 *
 * ── 已证（每条都指到指令）────────────────────────────────────────────────
 *   1. 18 个调用点全部在 9 个 F_PhysicsCreate*Joint 里、每个两次；现场（0x14ed54..0x14ed60）=
 *      Object_GetInstance(YYGetInt32(参数, 0), self = r9, other = r8)，返回后 0x14ed64 subs + 0x14ed68 beq 走错误出口
 *      ⇒ 返回类型是 CInstance* 且调用方必须判空（找不到就报错，不会传 0 继续建 joint）。
 *   2. 两张表的解引用层数不同，这是本函数最容易搞混的地方：g_ObjectHash 是**指针变量**
 *      （0x14ec4c 池字 → 0x14ec50 ldr → 0x14ec54 ldr 才拿到表结构），ms_ID2Instance 是 .bss 静态本体
 *      （0x14ecb4 池字 → 0x14ecb8 ldr 直接就是表结构）。同构的第三处对照见 CInstance_SetObjectIndex 卡。
 *   3. 对象路径返回的是「+0xd0 链头节点的 +8」= 该对象实例链上的第一个实例；因为 AddInstance 会沿 +0x48
 *      父链递归（见 4），父对象的链里混着所有后代对象的实例 ⇒ 这里返回的也可能是**子对象**的实例，
 *      不只是对象号完全相同的那些。链空返回 0，不是「任意一个实例」也不是「最后一个」。
 *   4. +0xd0 链的节点是 12 B {+0 next, +4 prev, +8 CInstance*}：AddInstance 0x19e074/0x19e0c0 写 +8、
 *      0x19e0d8 沿父对象 +0x48 递归 ⇒ 一个实例同时挂在自己的对象和所有祖先对象上，所以「父对象号」也能查到子对象实例。
 *      RemoveInstance 0x19e160..0x19e1b8 用同样的键（+8 比较）摘链，也沿 +0x48 递归。
 *   5. 5 个返回点：0x14ec74（mov r0,r1；id=-1 时给 self、查表失败时 r1=0）、0x14eca8（对象命中）、
 *      0x14ecb0（返回 other）、0x14ecf4（实例命中）、0x14ecf8（值 0）。全函数无 bl、无栈帧、不写任何内存（纯读）。
 *   6. 阈值 0x1869f 与 PatchParents 0x19e9bc、DoPushEnv、Builtins_Motion 用的是同一个数
 *      ⇒ 「对象号上界 99999、100000 起是实例号」在本构建里是全局约定，不是本函数的局部魔法数。
 *   7. 负 id 只有 -1/-2 特判：因为 0x14ec44 是 cmp + 0x14ec48 bgt（有符号大于），-3 会走对象表；
 *      这与 CInstance::SetObjectIndex 的「查找用原始 -1」是同一类边角（那张卡记了 open）。
 *   8. 无判空：g_ObjectHash 为 0 时 0x14ec54 直接崩；ms_ID2Instance 是静态本体，不需要判空。
 *
 * ── open（本节）─────────────────────────────────────────────────────────
 *   · CObjectGM +0xc4/+0xc8/+0xcc 与 +0xd0/+0xd4/+0xd8 两条平行链的分工未证：AddInstance 同时挂两条、
 *     RemoveInstance 同时摘两条、ClearInstanceInfo 同时清两条，字段值完全相同；本卡只读 +0xd0。
 *   · 「第一个实例」的补位规则未证：链头实例被销毁后 RemoveInstance 摘链，头节点变成下一个；谁保证顺序稳定未验证。
 *   · 对象路径在「节点 value 为 0」时返回 0 而不是继续找下一个同号节点（0x14ec98 直接跳 0x14ecf8）—— 这是有意的还是缺陷未证。
 *   · -3 及以下的负数落到对象表后的行为（掩码索引）未在真机取证。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */
/* @0x14ec2c cmn r0, #1 —— id == -1 ? */
/* @0x14ec30 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> —— → 0x14ec70 返回 self */
/* @0x14ec34 cmn r0, #2 —— id == -2 ? */
/* @0x14ec38 beq 0x14ecac <_Z18Object_GetInstanceiP9CInstanceS0_+0x80> —— → 0x14ecac 返回 other */
/* @0x14ec3c movw r3, #0x869f —— 99999 的低半 */
/* @0x14ec40 movt r3, #0x1 —— movt 0x1 ⇒ 99999 */
/* @0x14ec44 cmp r0, r3 —— 有符号比较 */
/* @0x14ec48 bgt 0x14ecb4 <_Z18Object_GetInstanceiP9CInstanceS0_+0x88> —— id > 99999 → 实例表 */
/* @0x14ec4c ldr r3, [pc, #0xa8] —— 池 0x29efec → 0x14ec58+该值 = GOT 0x3edc44（&g_ObjectHash） */
/* @0x14ec50 ldr r3, [pc, r3] —— 第一层：取 &g_ObjectHash */
/* @0x14ec54 ldr r3, [r3] —— 第二层：表结构 */
/* @0x14ec58 ldr r2, [r3, #0x4] —— r2 = 掩码 */
/* @0x14ec5c ldr r3, [r3] —— r3 = 桶数组 */
/* @0x14ec60 and r2, r0, r2 —— 桶下标 = id & mask */
/* @0x14ec64 ldr r1, [r3, r2, lsl #3] —— r1 = 桶头 */
/* @0x14ec68 cmp r1, #0 */
/* @0x14ec6c bne 0x14ec84 <_Z18Object_GetInstanceiP9CInstanceS0_+0x58> —— 非空 → 0x14ec84 */
/* @0x14ec70 mov r0, r1 —— 返回 r1（查表失败时 r1=0；id=-1 时 r1=self） */
/* @0x14ec74 bx lr */
/* @0x14ec78 ldr r1, [r1, #0x4] —— node = node->next（+0x4） */
/* @0x14ec7c cmp r1, #0 */
/* @0x14ec80 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> —— 走到尾 → 返回 0 */
/* @0x14ec84 ldr r3, [r1, #0x8] —— r3 = node->key */
/* @0x14ec88 cmp r0, r3 —— id == key ? */
/* @0x14ec8c bne 0x14ec78 <_Z18Object_GetInstanceiP9CInstanceS0_+0x4c> —— 不等 → 下一个 */
/* @0x14ec90 ldr r0, [r1, #0xc] —— r0 = node->value（CObjectGM*） */
/* @0x14ec94 cmp r0, #0 */
/* @0x14ec98 beq 0x14ecf8 <_Z18Object_GetInstanceiP9CInstanceS0_+0xcc> —— value 为 0 → 0x14ecf8 返回 0 */
/* @0x14ec9c ldr r0, [r0, #0xd0] —— r0 = obj->+0xd0（实例链头） */
/* @0x14eca0 cmp r0, #0 */
/* @0x14eca4 ldrne r0, [r0, #0x8] —— 非空才取 head->+8 */
/* @0x14eca8 bx lr —— bx lr（对象命中） */
/* @0x14ecac mov r0, r2 —— 返回 other */
/* @0x14ecb0 bx lr —— -2 路径的出口 */
/* @0x14ecb4 ldr r3, [pc, #0x44] —— 池 0x29ef8c → 0x14ecc0+该值 = GOT 0x3edc4c（ms_ID2Instance 本体） */
/* @0x14ecb8 ldr r3, [pc, r3] —— 一层：直接是表结构 */
/* @0x14ecbc ldr r2, [r3, #0x4] —— r2 = 掩码 */
/* @0x14ecc0 ldr r3, [r3] —— r3 = 桶数组 */
/* @0x14ecc4 and r2, r0, r2 —— 桶下标 = id & mask */
/* @0x14ecc8 ldr r1, [r3, r2, lsl #3] —— r1 = 桶头 */
/* @0x14eccc cmp r1, #0 */
/* @0x14ecd0 bne 0x14ece4 <_Z18Object_GetInstanceiP9CInstanceS0_+0xb8> —— 非空 → 0x14ece4 */
/* @0x14ecd4 b 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> —— 空 → 返回 0 */
/* @0x14ecd8 ldr r1, [r1, #0x4] —— node = node->next */
/* @0x14ecdc cmp r1, #0 */
/* @0x14ece0 beq 0x14ec70 <_Z18Object_GetInstanceiP9CInstanceS0_+0x44> —— 走到尾 → 返回 0 */
/* @0x14ece4 ldr r3, [r1, #0x8] —— r3 = node->key */
/* @0x14ece8 cmp r0, r3 */
/* @0x14ecec bne 0x14ecd8 <_Z18Object_GetInstanceiP9CInstanceS0_+0xac> —— 不等 → 下一个 */
/* @0x14ecf0 ldr r0, [r1, #0xc] —— r0 = node->value（CInstance*） */
/* @0x14ecf4 bx lr —— 实例命中的独立出口 */
/* @0x14ecf8 bx lr —— 返回 0 的出口 */

/* ── 字面量池（0x14ecfc/0x14ed00，2 字）───────────────────────────────────────────
 *   0x14ecfc = 0x0029efec → 0x14ec58 + 该值 = 0x3edc44（GOT：&g_ObjectHash）
 *   0x14ed00 = 0x0029ef8c → 0x14ecc0 + 该值 = 0x3edc4c（GOT：0x536f28 ms_ID2InstanceE 本体） */
/* @0x14ecfc eoreq lr, r9, r12, ror #31 —— 非指令：→ 0x3edc44 */
/* @0x14ed00 eoreq lr, r9, r12, lsl #31 —— 非指令：→ 0x3edc4c */
