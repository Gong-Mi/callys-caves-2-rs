/* cally 逆向卡：CRoom::Assign（原版 libyoyo.so，armv7）
 * @func 0x1ad70c 0x1ae3f4  size 3308  827 条（813 条指令 + 0x1ae2e4..0x1ae318 共 14 个池字；
 *       池字被 objdump 译成指令/未知字，卡内按索引原样保留并逐个标出真值）
 * 级别: 正文（8 段的深/浅边界、全部新分配点、两条实例链的克隆与插入方向、tile 表的两种来源、
 *             房间附加 5 格、视角相机克隆、物理世界拷贝、层委派 全部逐条落锚；
 *             未钉：CRoom+0xd0 的置位者、96 B 容器 +0xac 各字段语义、+0xa4 数组的名字、
 *             池里两个全局的业务含义（符号名已知，见下））
 * 符号: _ZN5CRoom6AssignEPS_b → void CRoom::Assign(CRoom* src, bool bRebuild)
 * ABI : softfp；两参走 r1/r2；无返回值。
 * 同层: CRoom::Clear 0x1ad0a4（本函数第一条动作）、CRoom::C2 0x1ad2cc（8 背景/8 视野记录的分配者）、
 *       CLayerManager::DuplicateRoomLayers 0x1c47e0（层由它整包复制）、CInstance::Assign 0x1986ec、
 *       CInstance::C2 0x1994dc、CLayerManager::AddInstance 0x1c5d18 /
 *       AddInstanceToLayer 0x1c5a38 / GetLayerIDForInstance 0x1b8cb8 / GetLayerFromID 0x1b8868、
 *       CollisionInsert 0x1cc494、Code_GetEntry 0xced64、CInstance::CreatePhysicsBody 0x192cd4、
 *       CPhysicsWorld::C2(CPhysicsWorld*) 0x237d90、CCameraManager::CloneCamera 0x170658、
 *       CCamera::GetID 0x16d12c、YYStrDup 0xdb8c8、MemoryManager Alloc/ReAlloc/Free
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   Assign(dest, src, bRebuild) = 「先把 dest 清空，再把 src 按 8 段搬进 dest」。搬的方式按段而异：
 *   字符串深拷贝、8 背景/8 视野记录**复用 dest 自己的记录**只拷内容、相机与物理世界新建、
 *   层整包委派给 DuplicateRoomLayers、tile 表有「直拷字节」和「由原始记录重建」两条路、
 *   两条实例链逐条 new + CInstance::Assign 克隆。CRoom+0xd0 决定 tile 容器是深建还是浅共享。
 *
 * ── 8 段拷贝边界（本卡的主干）─────────────────────────────────────
 *   段0 前置   CRoom::Clear(dest)                     —— 无条件先清；src==0 就到此为止
 *   段1  头标量 + 两条字符串                          —— 串**深**（YYStrDup ×2），其余值拷贝
 *        +0x08 name、+0x10、+0x14、+0x0c、+0x18、+0x1c、+0x20、+0x68 第二串
 *   段2  房间附加 5 格 +0x6c/+0x70(byte)/+0x74/+0x78/+0x7c —— 纯值拷贝，
 *        这 5 格**不在 Serialise 流里**（Assign 比存读多搬这 5 格）
 *   段3  8 × 背景记录（44 B，指针 +0x24+i*4）        —— 目标记录**不重分配**，只拷 13 字段
 *   段4  3 字节 +0x44/+0x45/+0x46，8 × 视野记录（68 B）—— 目标记录不重分配，只拷 15 字段；
 *        +0x3c **不拷**、+0x40 **不拷**（改由相机克隆给出新 id，失败给 -1）
 *   段5  物理世界 +0xb4                              —— **深**（new 488 B + 拷贝构造）
 *   段6  层（+0xd4 链 / +0xdc 计数）                 —— 委派 CLayerManager::DuplicateRoomLayers
 *   段7  tile 容器 +0xac/+0xb0、原始表 +0xc4/+0xc8、RTile 表 +0xb8/+0xbc/+0xc0
 *        —— 由 dest+0xd0 与 bRebuild 两个开关决定「深建 / 浅共享 / 直拷 / 重建」
 *   段8  实例两链 A(+0x84/+0x80/+0x88) 与 B(+0x90/+0x8c/+0x94)，ID 表、+0xa4/+0xa8 id 数组
 *        —— **深**（每实例 new 432 + CInstance::Assign）；bRebuild 时还会从模板新建实例
 *
 * ── 深 / 浅一览（谁新分配、谁共用）──────────────────────────────
 *   新分配：name 串、+0x68 串、CPhysicsWorld(488)、96 B 容器(+0xac/+0xb0)、+0xc8 指针表、
 *           +0xc4 指针表、+0xa4 id 数组、每实例 CInstance(432)、每实例 16 B 哈希节点、
 *           ReAlloc 的 RTile 表(+0xc0)、以及 DuplicateRoomLayers 内部的层与元素（见那张卡）
 *   共用：  +0xd0 == 0 时 +0xac/+0xb0 直接指到 src 的容器（浅共享）
 *   复用：  8 背景记录（44 B）与 8 视野记录（68 B）本身不新建，改 dest 已有记录的内容
 *   不搬：  +0x00、+0x04、+0xcc、+0xd0、+0xd4、+0xd8、+0xdc、+0xf4、+0x108、+0x120、
 *           视野记录 +0x3c，以及 8 背景/8 视野的**指针本身**（不重定向，记录复用）
 *   ★ 与之对照：+0x45/+0x46 是搬的（段4），但 Serialise 的流里没有这两格 ⇒「Assign 多搬」。
 *
 * ── 两个开关（决定段7、段8 的形态）────────────────────────────────
 *   dest+0xd0（byte，本函数只读不写；Clear 不动它，C2 置 0；置 1 的写入者未在已索引函数中出现）
 *     == 0 → 段7 **浅**：dest+0xac = src+0xac、dest+0xb0 = src+0xb0，原始表 +0xc4/+0xc8 保持 0；
 *            随后 0x1ae2b8 把 RTile 表**逐字节直拷**（count = src+0xb8，cap 也置 count）
 *     != 0 → 段7 **深**：新建 96 B 容器 + 两张原始表；RTile 表**不直拷**
 *   bRebuild（第二参，本卡命名推断）
 *     != 0 → 0x1ade68：从 src+0xc8 的 40 B 记录**逐条新建 CInstance**（挂 A 链 + 哈希 + 层 + 碰撞）、
 *            再从 src+0xc4 的 48 B 记录**重建 RTile 表**（14 字段展开）
 *     == 0 → 跳过实例化；只有 dest+0xd0 == 0 时才走 RTile 直拷
 *
 * ── Assign 与 DuplicateRoomLayers 的差别 ─────────────────────────
 *   DuplicateRoomLayers(dest, src) 0x1c47e0：只做「层 + 层内元素」。先 CleanRoomLayers(dest)、
 *     重建 dest 的三张 CHashMap，再沿 src 的 +0xd4 链逐层从池取对象、逐字段填（层名深/浅分叉）、
 *     逐元素按 type 分派克隆（7 类，32..80 B），最后尾插层链 + 插 map。它**不碰**房间头、
 *     8 背景/8 视野、tile 表、实例链（那张卡明确：全函数无 0xb8/0xc0 访问）。
 *   CRoom::Assign(dest, src, b)：整房间复制 = Clear + 段1..段5 + **调** DuplicateRoomLayers 管层
 *     + 段7 tile 两张表 + 段8 两条实例链。它自己**不写** +0xd4/+0xd8/+0xdc（层链），也不碰
 *     层内元素；反过来 DuplicateRoomLayers 不碰 Assign 的其余 7 段。
 *   两者都写「已存在的目标」，都不为 8 背景/8 视野记录本身分配内存（那 16 条记录属 CRoom::C2）。
 *
 * ── 帧与寄存器 ─────────────────────────────────────────────────
 *   push {r4-r11,lr} + vpush {d8} + sub sp,#52。
 *   r4 = this(dest)；[sp+0x10] = src（后段被复用作 Hash.h 串指针）；
 *   [sp+0x1c] = bRebuild；[sp+0x18] = GOT 基址 0x3f1c58（0x1ad738 + 0x244520）；
 *   [sp+0x14]/[sp+0x20]/[sp+0x24]/[sp+0x28]/[sp+0x2c] 在段7/8 里当 count、指针、alloc 尺寸的暂存。
 *   ★ 段3/段4 的循环游标直接用房间自身当数组：src 游标从 src 起、dest 游标从 dest 起，各 +4/轮，
 *     读 [游标+0x24]（背景）/[游标+0x48]（视野）拿到记录指针 —— 所以「指针本身不重定向」。
 *
 * ── 池（0x1ae2e4..0x1ae318，14 字；括号内是 ldr 站点与真值）──────────
 *   1ae2e4  0x437f0000 = 255.0f                             （0x1ae150 vldr s11，alpha 除数）
 *   1ae2e8  0x00244520 → GOT 基址加数：0x1ad738+0x244520 = 0x3f1c58（0x1ad71c）
 *   1ae2ec  0xffffbcd4 → GOT-0x432c = 0x3ed92c → .bss 0x5428e8 = **g_isZeus**（1 B，符号名已证）
 *   1ae2f0  0xffffc024 → GOT-0x3fdc = 0x3edc7c → .bss 0x48f78c = **g_CM**（28 B 全局对象，符号名已证）
 *   1ae2f4  0xffffbff4 → GOT-0x400c = 0x3edc4c → .bss 0x536f28 = **CInstance::ms_ID2InstanceE**（12 B）
 *   1ae2f8  0x0019f340 → 0x1ad974+0x19f340 = 0x34ccb4 = "jni/../jni/yoyo/../../../Platform/Hash.h"
 *   1ae2fc  0x0019f6a8 → 0x1adb08+0x19f6a8 = 0x34d1b0 = "jni/../jni/yoyo/../../../Files/Room/Room_Class.cpp"
 *   1ae300  0x0019f568 → 0x1adc48+0x19f568 = 0x34d1b0（同一串）
 *   1ae304  0x0019ef7c → 0x1add38+0x19ef7c = 0x34ccb4（Hash.h）
 *   1ae308  0x0019f2f0 → 0x1adec0+0x19f2f0 = 0x34d1b0（Room_Class.cpp）
 *   1ae30c  0x0019edb8 → 0x1adefc+0x19edb8 = 0x34ccb4（Hash.h）
 *   1ae310  0xffffc168 → GOT-0x3e98 = 0x3eddc0 → .bss 0x54290c = **Current_Object**（4 B）
 *   1ae314  0x0019f10c → 0x1ae130+0x19f10c = 0x34d23c = "jni/../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"
 *   1ae318  0x0019eec8 → 0x1ae374+0x19eec8 = 0x34d23c（同一串）
 *   0x34ccb4 的实际内容是 "jni/../jni/yoyo/../../../Platform/Hash.h"（与 DeSerialise 卡同一串）；
 *   0x34d1b0 = "jni/../jni/yoyo/../../../Files/Room/Room_Class.cpp"；
 *   0x34d23c = "jni/../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"。
 *   四个符号名来自 .dynsym：g_isZeus / g_CM / Current_Object / CInstance::ms_ID2InstanceE，
 *   这就是「相机克隆开关」「引擎全局对象」「当前对象」「实例 ID 表」四件事的直接证据。
 *
 * ── 未定（open）────────────────────────────────────────────────
 *   1. CRoom+0xd0 的置位者（已索引函数里只有本函数读它两次、C2 写 0）⇒ 「深/浅」何时被选中未证
 *   2. 96 B 容器 +0xac 的语义：+0x30 = 88 = 0x58、+0x34 = 92 = 0x5c，恰好是它自己两个数组指针字段
 *      的偏移（自描述容器）；+0x10 从 src 拷来但用途未证；是否有人 Free 它（Clear 只置 0）未证
 *   3. +0xa4/+0xa8（int 数组 + 计数，按模板创建实例时逐个追加 rec+0x0c）的名字与消费者未证
 *   4. 40 B 记录（+0xc8）与 48 B 记录（+0xc4）的字段名：本卡只钉「谁读哪一格、写进哪里」
 *   5. g_isZeus 为 0 时 8 个视野的 +0x40 保持 Clear 之后的值 —— 该值是否被别处当有效相机 id 用未证
 *   6. Assign(dest, dest) 自别名无保护：0x1ad728 先 Clear(dest) 再读 src，等价于自毁（未运行期验证）
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 帧：r4 = this(dest)、[sp+0x10] = src、[sp+0x1c] = bRebuild、[sp+0x18] = GOT ──
 *   0x1ad71c ldr r7,[pc,#0xbc4] → 池 0x1ae2e8 = 0x00244520；0x1ad730 add r7,pc,r7
 *   （pc = 0x1ad738）⇒ 0x3f1c58 = GOT 基址，存 [sp+0x18] 供后面所有全局取用。
 */

/* @0x1ad70c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ad710 vpush {d8} */
/* @0x1ad714 sub sp, sp, #52 */
/* @0x1ad718 mov r4, r0 */
/* @0x1ad71c ldr r7, [pc, #0xbc4] */
/* @0x1ad720 str r1, [sp, #0x10] */
/* @0x1ad724 str r2, [sp, #0x1c] */
/* ── 段0：**先清空自己** ────────────────────────────────────────
 *   bl CRoom::Clear 0x1ad0a4 —— 无条件、无别名检查。Clear 做什么（0x1ad0a4..0x1ad2c8）：
 *     · +0x08/+0x68 置 0（不 Free 旧串 —— 串的所有权在别处，见 open）
 *     · +0x10 = 640、+0xc = 30、+0x14 = 480、+0x1c = 0xC0C0C0、+0x20 = 1、+0x18 = 0、+0x70 = 0
 *     · 8 背景记录：只重置记录内容（+0x1c/+0x20 = 1.0f 等），**不 Free、不重分配**
 *     · 8 视野：DestroyCamera(记录+0x40) 后重置
 *     · +0xa4 数组 Free、ClearTiles（Free +0xc0，+0xb8/+0xbc 置 0，+0x00 置 -1）
 *     · CleanRoomLayers（清层）、Free +0xf4/+0x108/+0x120（三个 storage 数组）
 *     · +0xac/+0xc4/+0xc8 只置 0、**不 Free**（所以段7 的浅共享不会二次释放，只会泄漏）
 *     · +0xd0 **完全不动** ⇒ Assign 的深/浅分叉看的是「dest 进来之前」的 +0xd0
 *   ⇒ Assign(dest,dest) 会先把源清掉再读 ⇒ 自毁（open 6）。
 */

/* @0x1ad728 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* @0x1ad72c ldr r6, [sp, #0x10] */
/* @0x1ad730 add r7, pc, r7 */
/* @0x1ad734 str r7, [sp, #0x18] */
/* ── src == 0：只清空，直接返回（0x1ada5c 出口）────────────────────── */

/* @0x1ad738 cmp r6, #0 */
/* @0x1ad73c beq 0x1ada5c <_ZN5CRoom6AssignEPS_b+0x350> */
/* ── 段1：头标量 + 两条字符串 ─────────────────────────────────────
 *   0x1ad740 ldr r0,[r6,#8]（src+0x08 名字串）+ YYStrDup 0xdb8c8 ⇒ **深**（新分配一份）
 *   随后 0x1ad748..0x1ad774 取/存 5 个标量：+0x10、+0x14、+0xc（三个 int）、
 *     +0x18（byte）、+0x1c（u32）、+0x20（byte）；0x1ad778 才把新串写进 +0x08。
 *   0x1ad77c ldr r0,[r6,#0x68] + YYStrDup ⇒ 第二条串也是**深**，0x1ad7bc 写进 +0x68。
 *   ★ 全函数只有这两处 YYStrDup：其余字符串相关的深拷贝在 DuplicateRoomLayers 里（层名）。
 *   ★ src+0x08 == 0 时 YYStrDup(0) 的行为未证（open）；Clear 已把 dest+0x08 置 0。
 */

/* @0x1ad740 ldr r0, [r6, #0x8] */
/* @0x1ad744 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1ad748 ldr r5, [r6, #0x10] */
/* @0x1ad74c ldr lr, [r6, #0x14] */
/* @0x1ad750 ldr r12, [r6, #0xc] */
/* @0x1ad754 ldrb r1, [r6, #0x18] */
/* @0x1ad758 ldr r2, [r6, #0x1c] */
/* @0x1ad75c ldrb r3, [r6, #0x20] */
/* @0x1ad760 str r5, [r4, #0x10] */
/* @0x1ad764 str lr, [r4, #0x14] */
/* @0x1ad768 str r12, [r4, #0xc] */
/* @0x1ad76c strb r1, [r4, #0x18] */
/* @0x1ad770 str r2, [r4, #0x1c] */
/* @0x1ad774 strb r3, [r4, #0x20] */
/* @0x1ad778 str r0, [r4, #0x8] */
/* @0x1ad77c ldr r0, [r6, #0x68] */
/* @0x1ad780 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* ── 段2：房间附加 5 格 +0x6c / +0x70(byte) / +0x74 / +0x78 / +0x7c ──────
 *   纯值拷贝，五格全在 0x1ad790..0x1ad7b8 一次搬完。
 *   ★ 这 5 格**不在 CRoom::Serialise 的流里**（那边只写 +0x08..+0x20/+0x68/8 背景/0x44/8 视野/
 *     tile/层/两链）⇒ 存读会丢这 5 格，Assign 不会。+0x70 就是 Serialise 用来判「带物理」的那一格
 *     （LoadFromChunk 0x1aecf8/0x1aed3c 写它），这里照搬。
 */

/* @0x1ad784 ldr r9, [sp, #0x10] */
/* @0x1ad788 mov r12, r4 */
/* @0x1ad78c mov r1, #8 */
/* @0x1ad790 ldr r6, [r9, #0x6c] */
/* @0x1ad794 mov lr, r9 */
/* @0x1ad798 ldrb r5, [r9, #0x70] */
/* @0x1ad79c ldr r2, [r9, #0x74] */
/* @0x1ad7a0 ldr r3, [r9, #0x78] */
/* @0x1ad7a4 str r6, [r4, #0x6c] */
/* @0x1ad7a8 ldr r6, [r9, #0x7c] */
/* @0x1ad7ac strb r5, [r4, #0x70] */
/* @0x1ad7b0 str r2, [r4, #0x74] */
/* @0x1ad7b4 str r6, [r4, #0x7c] */
/* @0x1ad7b8 str r3, [r4, #0x78] */
/* @0x1ad7bc str r0, [r4, #0x68] */
/* ── 段3：8 × 背景记录（44 B）—— 记录复用，只拷 13 字段 ──────────────
 *   循环体：r2 = *(src 游标 + 0x24)、r3 = *(dest 游标 + 0x24)（两者都是房间自身 + i*4 的格），
 *   游标每轮 +4、计数器 r1 从 8 递减到 0（0x1ad83c bne）。
 *   13 个字段（写序是编译器排的，不是偏移序）：+0x08 +0x0c +0x01 +0x1c +0x00 +0x04 +0x10 +0x11
 *   +0x24 +0x20 +0x14 +0x18 +0x28 —— 全覆盖（与 Serialise/DeSerialise 的 13 字段同一张表）。
 *   ★ **不分配**：dest 的 8 条 44 B 记录由 CRoom::C2（1ad4f8 new(44) 写 +0x24+i*4）建好，
 *     Clear 只重置内容 ⇒ 这里直接把内容覆盖进去是安全的。这就是「记录级浅、字段级深」。
 */

/* @0x1ad7c0 ldr r2, [lr, #0x24] */
/* @0x1ad7c4 subs r1, r1, #1 */
/* @0x1ad7c8 ldr r3, [r12, #0x24] */
/* @0x1ad7cc add lr, lr, #4 */
/* @0x1ad7d0 add r12, r12, #4 */
/* @0x1ad7d4 ldr r6, [r2, #0x8] */
/* @0x1ad7d8 ldr r5, [r2, #0xc] */
/* @0x1ad7dc ldrb r8, [r2, #0x1] */
/* @0x1ad7e0 ldr r0, [r2, #0x1c] */
/* @0x1ad7e4 ldrb r9, [r2] */
/* @0x1ad7e8 ldr r7, [r2, #0x4] */
/* @0x1ad7ec str r6, [r3, #0x8] */
/* @0x1ad7f0 ldrb r6, [r2, #0x10] */
/* @0x1ad7f4 str r5, [r3, #0xc] */
/* @0x1ad7f8 ldrb r5, [r2, #0x11] */
/* @0x1ad7fc str r0, [r3, #0x1c] */
/* @0x1ad800 ldr r0, [r2, #0x24] */
/* @0x1ad804 strb r8, [r3, #0x1] */
/* @0x1ad808 ldr r8, [r2, #0x20] */
/* @0x1ad80c strb r6, [r3, #0x10] */
/* @0x1ad810 ldr r6, [r2, #0x14] */
/* @0x1ad814 strb r5, [r3, #0x11] */
/* @0x1ad818 ldr r5, [r2, #0x18] */
/* @0x1ad81c ldr r2, [r2, #0x28] */
/* @0x1ad820 strb r9, [r3] */
/* @0x1ad824 str r7, [r3, #0x4] */
/* @0x1ad828 str r8, [r3, #0x20] */
/* @0x1ad82c str r6, [r3, #0x14] */
/* @0x1ad830 str r5, [r3, #0x18] */
/* @0x1ad834 str r0, [r3, #0x24] */
/* @0x1ad838 str r2, [r3, #0x28] */
/* @0x1ad83c bne 0x1ad7c0 <_ZN5CRoom6AssignEPS_b+0xb4> */
/* ── 段4 前奏：三个房间字节 +0x44 / +0x45 / +0x46 ────────────────────
 *   三个 ldrb/strb 连搬。★ 流里只有 +0x44 这一格（Serialise 第 10 段），+0x45/+0x46 只存在于
 *   chunk 与本函数 —— 又一处「Assign 比存读多搬」。
 *   顺带把段4 的循环准备好：r8 = 0（计数，来自 r1 归零）、r5 = dest、r7 = src、r10 = GOT、
 *   r9 = *(g_isZeus)（0x1ad878 ldr r9,[r12,r3]，r3 = 池 0x1ae2ec）。
 */

/* @0x1ad840 ldr r12, [sp, #0x10] */
/* @0x1ad844 mov r8, r1 */
/* @0x1ad848 ldr r3, [pc, #0xa9c] */
/* @0x1ad84c mov r5, r4 */
/* @0x1ad850 mvn r6, #0 */
/* @0x1ad854 ldrb r0, [r12, #0x44] */
/* @0x1ad858 mov r7, r12 */
/* @0x1ad85c ldrb r1, [r12, #0x45] */
/* @0x1ad860 ldrb r2, [r12, #0x46] */
/* @0x1ad864 ldr r12, [sp, #0x18] */
/* @0x1ad868 strb r0, [r4, #0x44] */
/* @0x1ad86c strb r1, [r4, #0x45] */
/* @0x1ad870 strb r2, [r4, #0x46] */
/* @0x1ad874 mov r10, r12 */
/* @0x1ad878 ldr r9, [r12, r3] */
/* @0x1ad87c b 0x1ad894 <_ZN5CRoom6AssignEPS_b+0x188> */
/* @0x1ad880 add r8, r8, #1 */
/* @0x1ad884 add r5, r5, #4 */
/* @0x1ad888 cmp r8, #8 */
/* @0x1ad88c add r7, r7, #4 */
/* @0x1ad890 beq 0x1ada68 <_ZN5CRoom6AssignEPS_b+0x35c> */
/* ── 段4：8 × 视野记录（68 B）—— 记录复用，只拷 15 字段 ──────────────
 *   r3 = *(src+0x48+i*4)、r2 = *(dest+0x48+i*4)。
 *   拷贝清单（连续 15 格）：+0x00(byte)、+0x04(float，用 vldr/vstr)、+0x08、+0x0c、+0x10、
 *   +0x14、+0x18、+0x1c、+0x20、+0x24、+0x28、+0x2c、+0x30、+0x34、+0x38。
 *   ★ **+0x3c 与 +0x40 不拷**：
 *     · +0x3c 本函数完全不碰（Clear 也不动它）⇒ 副本里保留 dest 自己的旧值（open）
 *     · +0x40 是相机 id，由下面 0x1ad918 起的相机克隆重新给，不继承 src 的
 *   ★ 只有 +0x04 用 vldr/vstr 搬（float 语义明确）；其余 14 格一律 ldr/str 整字搬。softfp 下
 *     float 也是这样整字搬的，所以「ldr/str」不构成类型反证 —— 类型仍按 Serialise 的码定
 *     （+0x24 float t8、+0x28..+0x40 int t6）。
 */

/* @0x1ad894 ldr r3, [r7, #0x48] */
/* @0x1ad898 vldr s15, [r3, #4] */
/* @0x1ad89c ldr r2, [r5, #0x48] */
/* @0x1ad8a0 ldr r12, [r3, #0x8] */
/* @0x1ad8a4 ldrb r0, [r3] */
/* @0x1ad8a8 ldr r11, [r3, #0xc] */
/* @0x1ad8ac ldr r1, [r3, #0x14] */
/* @0x1ad8b0 ldr lr, [r3, #0x18] */
/* @0x1ad8b4 strb r0, [r2] */
/* @0x1ad8b8 ldr r0, [r5, #0x48] */
/* @0x1ad8bc vstr s15, [r0, #4] */
/* @0x1ad8c0 ldr r0, [r3, #0x20] */
/* @0x1ad8c4 str r12, [r2, #0x8] */
/* @0x1ad8c8 ldr r12, [r3, #0x1c] */
/* @0x1ad8cc str r11, [r2, #0xc] */
/* @0x1ad8d0 ldr r11, [r3, #0x10] */
/* @0x1ad8d4 str r1, [r2, #0x14] */
/* @0x1ad8d8 ldr r1, [r3, #0x28] */
/* @0x1ad8dc str lr, [r2, #0x18] */
/* @0x1ad8e0 ldr lr, [r3, #0x2c] */
/* @0x1ad8e4 str r12, [r2, #0x1c] */
/* @0x1ad8e8 ldr r12, [r3, #0x30] */
/* @0x1ad8ec str r0, [r2, #0x20] */
/* @0x1ad8f0 ldr r0, [r3, #0x24] */
/* @0x1ad8f4 str r1, [r2, #0x28] */
/* @0x1ad8f8 ldr r1, [r3, #0x38] */
/* @0x1ad8fc str r0, [r2, #0x24] */
/* @0x1ad900 ldr r0, [r3, #0x34] */
/* @0x1ad904 str r11, [r2, #0x10] */
/* @0x1ad908 str lr, [r2, #0x2c] */
/* @0x1ad90c str r12, [r2, #0x30] */
/* @0x1ad910 str r0, [r2, #0x34] */
/* @0x1ad914 str r1, [r2, #0x38] */
/* ── 段4 尾：相机克隆开关 g_isZeus ────────────────────────────────
 *   0x1ad918 ldrb r2,[r9]（r9 = *(0x5428e8) = g_isZeus，1 B）→ == 0 就下一轮视野。
 *   != 0：0x1ad924 ldr r2,[pc,#0x9c4] → 池 0x1ae2f0 → GOT 槽 0x3edc7c → g_CM（0x48f78c，28 B 全局对象）
 *         0x1ad928 ldr r1,[r3,#0x40] = src 视野的相机 id
 *         0x1ad930 bl CCameraManager::CloneCamera(int)（this = g_CM）
 *         成功：0x1ad940 CCamera::GetID() ⇒ dest 视野 +0x40 = 新相机 id（**深**：新相机对象）
 *         失败：0x1ade3c dest 视野 +0x40 = -1（r6 在 0x1ad850 被 mvn 成 -1）
 *   ⇒ +0x40 是「相机 id」，且是段4 里唯一的深拷贝点；g_isZeus 是全局开关（谁写它未证）。
 */

/* @0x1ad918 ldrb r2, [r9] */
/* @0x1ad91c cmp r2, #0 */
/* @0x1ad920 beq 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* ── 相机克隆：this = g_CM，参数 = src 视野 +0x40 ────────────────────
 *   g_CM（0x48f78c）是 28 B 的全局对象，.bss 里的引擎全局，符号名来自 .dynsym。
 */

/* @0x1ad924 ldr r2, [pc, #0x9c4] */
/* @0x1ad928 ldr r1, [r3, #0x40] */
/* @0x1ad92c ldr r0, [r10, r2] */
/* @0x1ad930 bl 0x170658 <_ZN14CCameraManager11CloneCameraEi> */
/* @0x1ad934 cmp r0, #0 */
/* @0x1ad938 beq 0x1ade3c <_ZN5CRoom6AssignEPS_b+0x730> */
/* @0x1ad93c ldr r11, [r5, #0x48] */
/* @0x1ad940 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x1ad944 str r0, [r11, #0x40] */
/* @0x1ad948 b 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* ── 段8 之 B 链：非活动实例（+0x90 头 / +0x8c 尾 / +0x94 计数）────────
 *   从**尾** src+0x8c 起，沿 +0x178（prev）逆向走（0x1ad97c ldr r10,[r8,#0x178]）——
 *   与 Serialise 的 B 段遍历方向完全一致（那张卡：从 +0x8c 沿 prev）。
 *   每轮：new(432) → CInstance::C2(0,0,0,0,false) → **CInstance::Assign(new, srcInst, false)**
 *         → 头插 dest B 链（0x90/0x8c/0x94，与 DeSerialise 0x1ace58 同一套 streq/strne）
 *         → 插 ms_ID2InstanceE（Alloc 16、"Hash.h"、行 306）→ 计数 +1。
 *   ★ 第三参 = **0**：CInstance::Assign 0x198864 的 `beq` 决定「bool==0 ⇒ 不调
 *     CObjectGM::AddInstance」⇒ 非活动实例**不注册进对象表**（与「deactivate 的实例不参与事件」自洽）。
 *   ★ 这条路与本段 A 链的差别只有三处：源尾 +0x8c、插入方式（头插）、CInstance::Assign 第三参 0/1。
 */

/* @0x1ad94c ldr r6, [sp, #0x10] */
/* @0x1ad950 ldr r8, [r6, #0x8c] */
/* @0x1ad954 cmp r8, #0 */
/* @0x1ad958 beq 0x1ada5c <_ZN5CRoom6AssignEPS_b+0x350> */
/* @0x1ad95c ldr r3, [pc, #0x990] */
/* @0x1ad960 mov r7, #0 */
/* @0x1ad964 ldr r9, [sp, #0x18] */
/* @0x1ad968 ldr r6, [pc, #0x988] */
/* @0x1ad96c add r6, pc, r6 */
/* @0x1ad970 str r6, [sp, #0x10] */
/* @0x1ad974 ldr r6, [r9, r3] */
/* @0x1ad978 mov r0, #432 */
/* @0x1ad97c ldr r10, [r8, #0x178] */
/* @0x1ad980 bl 0x27c524 <_Znwj> */
/* @0x1ad984 mov r1, #0 */
/* @0x1ad988 mov r3, #0 */
/* @0x1ad98c mov r2, r1 */
/* @0x1ad990 str r7, [sp] */
/* @0x1ad994 str r7, [sp, #0x4] */
/* @0x1ad998 mov r5, r0 */
/* @0x1ad99c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ad9a0 mov r1, r8 */
/* @0x1ad9a4 mov r0, r5 */
/* @0x1ad9a8 mov r2, #0 */
/* @0x1ad9ac bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1ad9b0 ldr r3, [r4, #0x90] */
/* @0x1ad9b4 ldr r2, [r4, #0x94] */
/* @0x1ad9b8 mov r0, #16 */
/* @0x1ad9bc cmp r3, #0 */
/* @0x1ad9c0 ldr r1, [sp, #0x10] */
/* @0x1ad9c4 add r2, r2, #1 */
/* @0x1ad9c8 str r2, [r4, #0x94] */
/* @0x1ad9cc strne r5, [r3, #0x178] */
/* @0x1ad9d0 movw r2, #0x132 */
/* @0x1ad9d4 ldrne r3, [r4, #0x90] */
/* @0x1ad9d8 streq r5, [r4, #0x90] */
/* @0x1ad9dc streq r5, [r4, #0x8c] */
/* @0x1ad9e0 strne r3, [r5, #0x17c] */
/* @0x1ad9e4 streq r3, [r5, #0x17c] */
/* @0x1ad9e8 streq r3, [r5, #0x178] */
/* @0x1ad9ec mov r3, #1 */
/* @0x1ad9f0 strne r5, [r4, #0x90] */
/* @0x1ad9f4 strne r7, [r5, #0x178] */
/* @0x1ad9f8 ldr r8, [r6] */
/* @0x1ad9fc ldr r11, [r5, #0x78] */
/* @0x1ada00 ldr r9, [r6, #0x4] */
/* @0x1ada04 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ada08 and r9, r11, r9 */
/* @0x1ada0c ldr r2, [r8, r9, lsl #3] */
/* @0x1ada10 add r3, r8, r9, lsl #3 */
/* @0x1ada14 cmp r2, #0 */
/* @0x1ada18 ldrne r2, [r3, #0x4] */
/* @0x1ada1c str r11, [r0, #0x8] */
/* @0x1ada20 str r5, [r0, #0xc] */
/* @0x1ada24 strne r2, [r0] */
/* @0x1ada28 streq r0, [r3, #0x4] */
/* @0x1ada2c strne r0, [r2, #0x4] */
/* @0x1ada30 streq r0, [r8, r9, lsl #3] */
/* @0x1ada34 mov r8, r10 */
/* @0x1ada38 strne r0, [r3, #0x4] */
/* @0x1ada3c streq r2, [r0, #0x4] */
/* @0x1ada40 streq r2, [r0] */
/* @0x1ada44 strne r7, [r0, #0x4] */
/* @0x1ada48 cmp r10, #0 */
/* @0x1ada4c ldr r3, [r6, #0x8] */
/* @0x1ada50 add r3, r3, #1 */
/* @0x1ada54 str r3, [r6, #0x8] */
/* @0x1ada58 bne 0x1ad978 <_ZN5CRoom6AssignEPS_b+0x26c> */
/* ── 返回（无返回值）─────────────────────────────────────────────
 *   0x1ada5c add sp,#52 / vpop {d8} / pop {r4-r11,pc}。
 *   两个出口：src==0（0x1ad958）与正常走完（0x1ada58）。
 */

/* @0x1ada5c add sp, sp, #52 */
/* @0x1ada60 vpop {d8} */
/* @0x1ada64 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 段5：物理世界 +0xb4 —— 深拷贝 ────────────────────────────────
 *   src+0xb4 != 0 → new(488) + CPhysicsWorld::C2(CPhysicsWorld*) 0x237d90（拷贝构造）→ dest+0xb4。
 *   src+0xb4 == 0 → 跳过（dest+0xb4 保持 Clear 之后的 0）。
 *   ★ 这一格 Serialise 明说不写（带物理的房间只喊 "ERROR: game_save unavailable for rooms using
 *     physics"）⇒ 物理世界只能靠 Assign 这条路径复制，存读必丢。
 */

/* @0x1ada68 ldr r6, [sp, #0x10] */
/* @0x1ada6c ldr r3, [r6, #0xb4] */
/* @0x1ada70 cmp r3, #0 */
/* @0x1ada74 beq 0x1ada90 <_ZN5CRoom6AssignEPS_b+0x384> */
/* @0x1ada78 mov r0, #488 */
/* @0x1ada7c bl 0x27c524 <_Znwj> */
/* @0x1ada80 ldr r1, [r6, #0xb4] */
/* @0x1ada84 mov r5, r0 */
/* @0x1ada88 bl 0x237d90 <_ZN13CPhysicsWorldC2EPS_> */
/* @0x1ada8c str r5, [r4, #0xb4] */
/* ── 段6：层 —— 委派 CLayerManager::DuplicateRoomLayers(dest, src) ──────
 *   本函数只出一条 bl：层对象、层内 7 类元素、层名字串深浅、层链尾插、三张 CHashMap 全部在被调方
 *   （0x1c47e0..0x1c5a34，见 DuplicateRoomLayers 卡）。⇒ dest+0xd4/+0xd8/+0xdc 不由本函数直接写。
 *   ★ 注意顺序：先搬 8 背景/8 视野/物理，再复制层，然后才轮到 tile 与实例（段的先后是硬性的，
 *     因为 bRebuild 的实例化要用到层（AddInstanceToLayer））。
 */

/* @0x1ada90 mov r0, r4 */
/* @0x1ada94 ldr r1, [sp, #0x10] */
/* @0x1ada98 bl 0x1c47e0 <_ZN13CLayerManager19DuplicateRoomLayersEP5CRoomS1_> */
/* ── 段7 分支点 ①：dest+0xd0 决定 tile 容器深建还是浅共享 ──────────────
 *   ldrb r3,[r4,#0xd0]；== 0 → 0x1ade48（浅）；!= 0 → 0x1adaa8（深）。
 *   ★ 这是全函数唯一读 +0xd0 的地方（第二处读在 0x1add04，判断 RTile 表要不要直拷）。
 *     +0xd0 在 Clear 里不被重置，所以它反映「dest 进函数之前」的状态。
 */

/* @0x1ada9c ldrb r3, [r4, #0xd0] */
/* @0x1adaa0 cmp r3, #0 */
/* @0x1adaa4 beq 0x1ade48 <_ZN5CRoom6AssignEPS_b+0x73c> */
/* @0x1adaa8 ldr r9, [sp, #0x10] */
/* @0x1adaac ldr r3, [r9, #0xac] */
/* @0x1adab0 ldr r12, [r3, #0x34] */
/* @0x1adab4 cmp r12, #0 */
/* @0x1adab8 str r12, [sp, #0x20] */
/* @0x1adabc beq 0x1ae27c <_ZN5CRoom6AssignEPS_b+0xb70> */
/* @0x1adac0 ldr r6, [r9, #0xc4] */
/* @0x1adac4 mov r2, #52 */
/* @0x1adac8 ldr r7, [r6], #4 */
/* @0x1adacc mul r2, r2, r7 */
/* @0x1adad0 lsl r9, r7, #2 */
/* @0x1adad4 str r6, [sp, #0x28] */
/* @0x1adad8 str r7, [sp, #0x14] */
/* @0x1adadc add r2, r2, #4 */
/* @0x1adae0 str r9, [sp, #0x20] */
/* @0x1adae4 str r2, [sp, #0x2c] */
/* ── 段7 深建：96 B 容器 + 两张 {count, ptr×N, rec×N} 表 ─────────────────
 *   容器：Alloc(96, "Room_Class.cpp", 行 0x14e) → memset(容器, 0, 88) → dest+0xac = dest+0xb0 = 容器
 *         （0x1adb6c 把同一指针也写进 +0xb0；+0xb0 是 +0xac 的影子格）
 *         容器格：+0x30 = 88、+0x34 = 92（= 0x58 / 0x5c，正好是它自己两个数组指针字段的偏移）、
 *                 +0x10 = 源容器 +0x10（原样搬，用途未证）
 *   表1（源 src+0xc8，40 B 记录）：M = [src+0xc8]；alloc = 4 + 44M（4 头 + 4M 指针 + 40M 记录）；
 *         目的 +0xc8 = 基址；表头 [0] = M；指针表写在基址+4 起，记录紧随其后
 *         ⇒ 指针是「重算」出来的（不是把源的指针抄过来）：每条记录都在新块里，指针指向新位置
 *   表2（源 src+0xc4，48 B 记录）：N = [src+0xc4]；alloc = 4 + 52N（4 头 + 4N 指针 + 48N 记录）；
 *         目的 +0xc4 = 基址（0x1adcf8）；同一指针也写进容器 +0x5c（0x1adc5c）
 *   ★ 两张表的记录都是**逐字节搬**（表1 40 B = 2×16 + 8；表2 48 B = 3×16），不解释字段。
 *   ★ 源容器 [+0xac]+0x30(=88) 为 0 时走 0x1ae27c 的退化路径：M = 0、alloc 尺寸 4、指针表为空。
 */

/* @0x1adae8 ldr r8, [r3, #0x30] */
/* @0x1adaec movw r2, #0x14e */
/* @0x1adaf0 ldr r6, [pc, #0x804] */
/* @0x1adaf4 mov r3, #1 */
/* @0x1adaf8 cmp r8, #0 */
/* @0x1adafc mov r0, #96 */
/* @0x1adb00 add r6, pc, r6 */
/* @0x1adb04 mov r5, #88 */
/* @0x1adb08 ldrne r7, [sp, #0x10] */
/* @0x1adb0c moveq r9, #4 */
/* @0x1adb10 mov r1, r6 */
/* @0x1adb14 moveq r10, r8 */
/* @0x1adb18 moveq r7, r9 */
/* @0x1adb1c ldrne r9, [r7, #0xc8] */
/* @0x1adb20 movne r7, #44 */
/* @0x1adb24 ldrne r10, [r9], #4 */
/* @0x1adb28 mulne r7, r7, r10 */
/* @0x1adb2c lslne r8, r10, #2 */
/* @0x1adb30 addne r7, r7, #4 */
/* @0x1adb34 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adb38 mov r2, r5 */
/* @0x1adb3c mov r1, #0 */
/* @0x1adb40 str r0, [r4, #0xac] */
/* @0x1adb44 bl 0xb65b0 <memset@plt> */
/* ── 表1 落位：容器 +0x58 = 表1 整块基址；房间 +0xc8 = 同一基址 ────────────
 *   0x1adb4c ldr r11,[r4,#0xac]（新容器）；1adb6c str r11,[r4,#0xb0]；1adb8c 容器+0x58 = 新块。
 *   块内布局： [0] = count(M)（1adbb0 写；之前 1adb90..1adba4 用 4 条 strb 把这一字清 0）、
 *             [4 .. 4+4M) = M 个记录指针（1adbc8 str r1,[r0,#0x4]! 起，每个 +4）、
 *             [4+4M 起] = M 条记录，stride 40（两条 16 B + 8 B 搬完）
 *   ⇒ 指针不是抄源的，而是「重算」：每条记录都落在新块的记录区，指针指向新位置。
 *   房间 +0xc8 在 1adc3c 才写，值与容器 +0x58 相同。
 */

/* @0x1adb48 ldr r12, [sp, #0x10] */
/* @0x1adb4c ldr r11, [r4, #0xac] */
/* @0x1adb50 mov lr, #92 */
/* @0x1adb54 mov r1, r6 */
/* @0x1adb58 mov r2, #344 */
/* @0x1adb5c ldr r3, [r12, #0xac] */
/* @0x1adb60 mov r0, r7 */
/* @0x1adb64 ldr r12, [r3, #0x10] */
/* @0x1adb68 mov r3, #1 */
/* @0x1adb6c str r11, [r4, #0xb0] */
/* @0x1adb70 str lr, [r11, #0x34] */
/* @0x1adb74 str r5, [r11, #0x30] */
/* @0x1adb78 str r12, [r11, #0x10] */
/* @0x1adb7c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adb80 mov r2, #0 */
/* @0x1adb84 cmp r10, r2 */
/* @0x1adb88 mov r3, r0 */
/* @0x1adb8c str r0, [r11, #0x58] */
/* @0x1adb90 strb r2, [r3], #1 */
/* @0x1adb94 add r3, r3, #1 */
/* @0x1adb98 strb r2, [r0, #0x1] */
/* @0x1adb9c strb r2, [r3], #1 */
/* @0x1adba0 strb r2, [r3] */
/* @0x1adba4 ldr lr, [r11, #0x58] */
/* @0x1adba8 mov r1, lr */
/* @0x1adbac str lr, [sp, #0x24] */
/* @0x1adbb0 str r10, [r1], #4 */
/* @0x1adbb4 add r1, r1, r8 */
/* @0x1adbb8 ble 0x1adc28 <_ZN5CRoom6AssignEPS_b+0x51c> */
/* @0x1adbbc ldr r0, [sp, #0x24] */
/* @0x1adbc0 sub r12, r9, #4 */
/* @0x1adbc4 mov r9, r2 */
/* @0x1adbc8 str r1, [r0, #0x4]! */
/* @0x1adbcc mov r2, r1 */
/* @0x1adbd0 ldr r3, [r12, #0x4]! */
/* @0x1adbd4 add lr, r3, #32 */
/* @0x1adbd8 ldr r8, [r3] */
/* @0x1adbdc add r3, r3, #16 */
/* @0x1adbe0 ldr r7, [r3, #-0xc] */
/* @0x1adbe4 add r2, r2, #16 */
/* @0x1adbe8 ldr r6, [r3, #-0x8] */
/* @0x1adbec ldr r5, [r3, #-0x4] */
/* @0x1adbf0 cmp r3, lr */
/* @0x1adbf4 str r8, [r2, #-0x10] */
/* @0x1adbf8 str r7, [r2, #-0xc] */
/* @0x1adbfc str r6, [r2, #-0x8] */
/* @0x1adc00 str r5, [r2, #-0x4] */
/* @0x1adc04 bne 0x1adbd8 <_ZN5CRoom6AssignEPS_b+0x4cc> */
/* @0x1adc08 ldr lr, [r3] */
/* @0x1adc0c add r9, r9, #1 */
/* @0x1adc10 ldr r3, [r3, #0x4] */
/* @0x1adc14 cmp r9, r10 */
/* @0x1adc18 add r1, r1, #40 */
/* @0x1adc1c str lr, [r2] */
/* @0x1adc20 str r3, [r2, #0x4] */
/* @0x1adc24 bne 0x1adbc8 <_ZN5CRoom6AssignEPS_b+0x4bc> */
/* ── 表2 落位（48 B 记录）+ N 写回房间 +0xb8 ──────────────────────────
 *   0x1adc3c str r0,[r4,#0xc8]（表1 基址）；0x1adc48 Alloc(4+52N) → 容器 +0x5c；
 *   0x1adc5c str r0,[r11,#0x5c]；0x1adc84 str r6,[r4,#0xb8]（= N）。
 *   逐条搬 48 B（0x1adca8..0x1adcdc，3 次 16 B），指针表写在基址+4 起、stride 48。
 *   ★ 表1 与表2 的「记录区起点」不同带来的差别只有一个：+0xc8 的 stride 40、+0xc4 的 stride 48。
 */

/* @0x1adc28 ldr r0, [sp, #0x24] */
/* @0x1adc2c mov r3, #1 */
/* @0x1adc30 ldr r1, [pc, #0x6c8] */
/* @0x1adc34 movw r2, #0x165 */
/* @0x1adc38 mov r10, #0 */
/* @0x1adc3c str r0, [r4, #0xc8] */
/* @0x1adc40 add r1, pc, r1 */
/* @0x1adc44 ldr r0, [sp, #0x2c] */
/* @0x1adc48 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adc4c ldr r6, [sp, #0x14] */
/* @0x1adc50 ldr r7, [sp, #0x20] */
/* @0x1adc54 cmp r6, r10 */
/* @0x1adc58 mov r3, r0 */
/* @0x1adc5c str r0, [r11, #0x5c] */
/* @0x1adc60 strb r10, [r3], #1 */
/* @0x1adc64 add r3, r3, #1 */
/* @0x1adc68 strb r10, [r0, #0x1] */
/* @0x1adc6c strb r10, [r3], #1 */
/* @0x1adc70 strb r10, [r3] */
/* @0x1adc74 ldr r11, [r11, #0x5c] */
/* @0x1adc78 mov r1, r11 */
/* @0x1adc7c str r6, [r1], #4 */
/* @0x1adc80 add r1, r1, r7 */
/* @0x1adc84 str r6, [r4, #0xb8] */
/* @0x1adc88 ble 0x1adcf4 <_ZN5CRoom6AssignEPS_b+0x5e8> */
/* @0x1adc8c ldr r9, [sp, #0x28] */
/* @0x1adc90 mov r0, r11 */
/* @0x1adc94 str r4, [sp, #0x20] */
/* @0x1adc98 ldr r4, [sp, #0x14] */
/* @0x1adc9c sub r12, r9, #4 */
/* @0x1adca0 str r1, [r0, #0x4]! */
/* @0x1adca4 mov r2, r1 */
/* @0x1adca8 ldr r3, [r12, #0x4]! */
/* @0x1adcac add r5, r3, #48 */
/* @0x1adcb0 ldr r9, [r3] */
/* @0x1adcb4 add r3, r3, #16 */
/* @0x1adcb8 ldr r8, [r3, #-0xc] */
/* @0x1adcbc add r2, r2, #16 */
/* @0x1adcc0 ldr r7, [r3, #-0x8] */
/* @0x1adcc4 ldr r6, [r3, #-0x4] */
/* @0x1adcc8 cmp r3, r5 */
/* @0x1adccc str r9, [r2, #-0x10] */
/* @0x1adcd0 str r8, [r2, #-0xc] */
/* @0x1adcd4 str r7, [r2, #-0x8] */
/* @0x1adcd8 str r6, [r2, #-0x4] */
/* @0x1adcdc bne 0x1adcb0 <_ZN5CRoom6AssignEPS_b+0x5a4> */
/* @0x1adce0 add r10, r10, #1 */
/* @0x1adce4 add r1, r1, #48 */
/* @0x1adce8 cmp r10, r4 */
/* @0x1adcec bne 0x1adca0 <_ZN5CRoom6AssignEPS_b+0x594> */
/* @0x1adcf0 ldr r4, [sp, #0x20] */
/* ── 段7 深分支收尾：+0xc4 落位 + bRebuild 分叉 ─────────────────────
 *   0x1adcf8 str r11,[r4,#0xc4]（r11 已在 0x1adc74 变成新数组基址）；0x1add00 看 bRebuild：
 *   != 0 → 0x1ade68（实例化并重建 RTile）；== 0 → 0x1add04（可能直拷 RTile）。
 */

/* @0x1adcf4 ldr r12, [sp, #0x1c] */
/* @0x1adcf8 str r11, [r4, #0xc4] */
/* @0x1adcfc cmp r12, #0 */
/* @0x1add00 bne 0x1ade68 <_ZN5CRoom6AssignEPS_b+0x75c> */
/* ── 段7 分支点 ②：dest+0xd0 决定 RTile 表直拷还是跳过 ────────────────
 *   == 0 → 0x1ae2b8：count = src+0xb8，ReAlloc(dest+0xc0, count*56)，dest+0xbc = count，
 *          然后 n 次 **56 B 整块搬**（3 组 ldm/stm 各 16 B + 2 字 = 56 B，0x1ae3ac..0x1ae3d0）。
 *   != 0 → 直接 0x1add10（RTile 表留给 bRebuild 那条路重建，或保持空）。
 */

/* @0x1add04 ldrb r3, [r4, #0xd0] */
/* @0x1add08 cmp r3, #0 */
/* @0x1add0c beq 0x1ae2b8 <_ZN5CRoom6AssignEPS_b+0xbac> */
/* ── 段8 之 A 链：活动实例（+0x84 头 / +0x80 尾 / +0x88 计数）──────────
 *   从**尾** src+0x80 起，沿 +0x178（prev）逆向走（0x1add40 ldr r8,[r7,#0x178]）。
 *   每轮：new(432) → CInstance::C2(0,0,0,0,false) → **CInstance::Assign(new, srcInst, true)**
 *         → 插 dest A 链（深度降序，0x1add90 起）→ 插 ms_ID2InstanceE → 计数 +1。
 *   ★ 第三参 = **1** ⇒ CInstance::Assign 会调 CObjectGM::AddInstance，把新实例注册进对象表。
 *   ★ 插入比较：vldrne s14,[r5,#384]（新实例 +0x180 = depth）与 vldr s15,[r3,#388]（链上 +0x184
 *     = 插入时的 depth 快照），`vcmpe s15,s14` + `bls` ⇒ 遇到「快照 <= 新 depth」就停 ⇒ 链保持
 *     **depth 降序、head = 最深**。与 DeSerialise 0x1acd78（那里写的是 `vcmpe s14,s15` + `bge`，
 *     语义等价）和 AddInstance 0x1ab740 三处同构。
 *   ★ 空链分支 0x1ae22c：+0x84 = +0x80 = 新实例、+0x184 = 新实例 +0x180（快照）、两链域清零。
 *   ★ 与 Serialise/DeSerialise 同一处不对称：链上比较用**快照** +0x184，新实例取**实时** +0x180
 *     ⇒ 若 depth 插入后被改，克隆会按实时 depth 重排（不是纯拷贝）。
 */

/* @0x1add10 ldr r6, [sp, #0x10] */
/* @0x1add14 ldr r7, [r6, #0x80] */
/* @0x1add18 cmp r7, #0 */
/* @0x1add1c beq 0x1ad94c <_ZN5CRoom6AssignEPS_b+0x240> */
/* @0x1add20 ldr r3, [pc, #0x5cc] */
/* @0x1add24 mov r10, #0 */
/* @0x1add28 ldr r12, [sp, #0x18] */
/* @0x1add2c ldr r9, [pc, #0x5d0] */
/* @0x1add30 add r9, pc, r9 */
/* @0x1add34 str r9, [sp, #0x14] */
/* @0x1add38 ldr r6, [r12, r3] */
/* @0x1add3c mov r0, #432 */
/* @0x1add40 ldr r8, [r7, #0x178] */
/* @0x1add44 bl 0x27c524 <_Znwj> */
/* @0x1add48 mov r1, #0 */
/* @0x1add4c mov r3, #0 */
/* @0x1add50 mov r2, r1 */
/* @0x1add54 str r10, [sp] */
/* @0x1add58 str r10, [sp, #0x4] */
/* @0x1add5c mov r5, r0 */
/* @0x1add60 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1add64 mov r2, #1 */
/* @0x1add68 mov r0, r5 */
/* @0x1add6c mov r1, r7 */
/* @0x1add70 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1add74 ldr r3, [r4, #0x84] */
/* @0x1add78 ldr r2, [r4, #0x88] */
/* @0x1add7c cmp r3, #0 */
/* @0x1add80 vldrne s14, [r5, #384] */
/* @0x1add84 add r2, r2, #1 */
/* @0x1add88 str r2, [r4, #0x88] */
/* @0x1add8c beq 0x1ae22c <_ZN5CRoom6AssignEPS_b+0xb20> */
/* @0x1add90 vldr s15, [r3, #388] */
/* @0x1add94 vcmpe.f32 s15, s14 */
/* @0x1add98 vmrs APSR_nzcv, fpscr */
/* @0x1add9c bls 0x1ae1f8 <_ZN5CRoom6AssignEPS_b+0xaec> */
/* @0x1adda0 ldr r3, [r3, #0x17c] */
/* @0x1adda4 cmp r3, #0 */
/* @0x1adda8 bne 0x1add90 <_ZN5CRoom6AssignEPS_b+0x684> */
/* @0x1addac ldr r2, [r4, #0x80] */
/* @0x1addb0 vstr s14, [r5, #388] */
/* @0x1addb4 str r5, [r2, #0x17c] */
/* @0x1addb8 str r2, [r5, #0x178] */
/* @0x1addbc str r5, [r4, #0x80] */
/* @0x1addc0 str r3, [r5, #0x17c] */
/* @0x1addc4 movw r2, #0x132 */
/* @0x1addc8 mov r3, #1 */
/* @0x1addcc mov r0, #16 */
/* @0x1addd0 ldr r1, [sp, #0x14] */
/* @0x1addd4 ldr r7, [r6] */
/* @0x1addd8 ldr r9, [r5, #0x78] */
/* @0x1adddc ldr r11, [r6, #0x4] */
/* @0x1adde0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adde4 and r11, r9, r11 */
/* @0x1adde8 ldr r2, [r7, r11, lsl #3] */
/* @0x1addec add r3, r7, r11, lsl #3 */
/* @0x1addf0 cmp r2, #0 */
/* @0x1addf4 ldrne r2, [r3, #0x4] */
/* @0x1addf8 str r9, [r0, #0x8] */
/* @0x1addfc str r5, [r0, #0xc] */
/* @0x1ade00 strne r2, [r0] */
/* @0x1ade04 streq r0, [r3, #0x4] */
/* @0x1ade08 strne r0, [r2, #0x4] */
/* @0x1ade0c streq r0, [r7, r11, lsl #3] */
/* @0x1ade10 strne r0, [r3, #0x4] */
/* @0x1ade14 streq r2, [r0, #0x4] */
/* @0x1ade18 streq r2, [r0] */
/* @0x1ade1c strne r10, [r0, #0x4] */
/* @0x1ade20 cmp r8, #0 */
/* @0x1ade24 ldr r3, [r6, #0x8] */
/* @0x1ade28 add r3, r3, #1 */
/* @0x1ade2c str r3, [r6, #0x8] */
/* @0x1ade30 beq 0x1ad94c <_ZN5CRoom6AssignEPS_b+0x240> */
/* @0x1ade34 mov r7, r8 */
/* @0x1ade38 b 0x1add3c <_ZN5CRoom6AssignEPS_b+0x630> */
/* ── 相机克隆失败的出口：dest 视野 +0x40 = -1 ────────────────────────
 *   0x1ad850 mvn r6,#0 ⇒ r6 = -1；这里 ldr r3,[r5,#0x48] 取 dest 视野记录再 str r6,[r3,#0x40]。
 *   ⇒ +0x40 = -1 表示「没有相机」，不是 0。
 */

/* @0x1ade3c ldr r3, [r5, #0x48] */
/* @0x1ade40 str r6, [r3, #0x40] */
/* @0x1ade44 b 0x1ad880 <_ZN5CRoom6AssignEPS_b+0x174> */
/* ── 段7 浅分支：容器只搬指针 ─────────────────────────────────────
 *   dest+0xac = src+0xac、dest+0xb0 = src+0xb0（两个字段指同一个 96 B 容器），
 *   +0xc4/+0xc8 保持 Clear 之后的 0（不复制原始表）。
 *   ★ 因为 Clear 对 +0xac/+0xc4/+0xc8 只置 0 不 Free，浅共享不会二次释放（但会泄漏）。
 *   然后 0x1ade64 看 bRebuild：!= 0 → 0x1ade68；== 0 → 0x1add04。
 */

/* @0x1ade48 ldr r7, [sp, #0x10] */
/* @0x1ade4c ldr r12, [sp, #0x1c] */
/* @0x1ade50 ldr r2, [r7, #0xac] */
/* @0x1ade54 cmp r12, #0 */
/* @0x1ade58 ldr r3, [r7, #0xb0] */
/* @0x1ade5c str r2, [r4, #0xac] */
/* @0x1ade60 str r3, [r4, #0xb0] */
/* @0x1ade64 beq 0x1add04 <_ZN5CRoom6AssignEPS_b+0x5f8> */
/* ── bRebuild 分支：从 src 的原始表把「活对象」建出来 ─────────────────
 *   0x1ade70 src+0xac == 0 → 放弃（跳 0x1add04）；
 *   0x1ade78 取 [src+0xac]+0x34（容器自描述字段，见 open 2）：== 0 → dest+0xb8 = 0、
 *   [sp+0x24] = 0（0x1ae2b8 之后的 tile 直拷会走空表）；!= 0 → 0x1ae294。
 *   0x1ae294：r7 = src+0xc4（原始 tile 表）；dest+0xb8 = 0 或 [src+0xc4][0]（= count）；
 *   [sp+0x24] = 该表的基址（0 表示没有表）。
 */

/* @0x1ade68 ldr r6, [sp, #0x10] */
/* @0x1ade6c ldr r3, [r6, #0xac] */
/* @0x1ade70 cmp r3, #0 */
/* @0x1ade74 beq 0x1add04 <_ZN5CRoom6AssignEPS_b+0x5f8> */
/* @0x1ade78 ldr r3, [r3, #0x34] */
/* @0x1ade7c cmp r3, #0 */
/* @0x1ade80 streq r3, [r4, #0xb8] */
/* @0x1ade84 streq r3, [sp, #0x24] */
/* @0x1ade88 bne 0x1ae294 <_ZN5CRoom6AssignEPS_b+0xb88> */
/* ── 段8 补充：按 +0xc8 的 40 B 记录逐条新建 CInstance ────────────────
 *   源：src+0xc8 = {count, count×ptr, count×40 B}（LoadFromChunk 0x1af1f8 建它时已对每条记录的
 *   +0x10/+0x24 做过 Code_CreateEntry ⇒ 这两格是已编译的代码入口）。
 *   分配：0x1adeb4 count*4 → dest+0xa4（int 数组，memset 0）、dest+0xa8 = 0（计数）。
 *   每条记录（r6）：
 *     +0x08 对象下标（< 0 跳过）、+0x00/+0x04 = x/y（int → vcvt.f32.s32 → 传 float）
 *     CInstance::C2(x, y, rec+0x0c, rec+0x08, true)（softfp：r1/r2 = float、r3 = rec+0x0c、
 *     [sp] = rec+0x08（第 4 参 = 对象下标，进函数前先判 < 0）、[sp+4] = 1）
 *     +0x10 → inst+0x160（Code_GetEntry）、+0x24 → inst+0x164（Code_GetEntry）
 *     +0x14/+0x18 → SetImageScaleX/Y、+0x1c & 0xFFFFFF → inst+0xa8（blend）、
 *     +0x1f/255.0f → inst+0xa4（alpha）、+0x20 → SetImageAngle
 *     → *Current_Object = inst+0x7c（池 0x1ae310 → .bss 0x54290c，符号名已证）
 *     → CInstance::CreatePhysicsBody(this)、按 (GetLayerIDForInstance → GetLayerFromID) 找层
 *     → AddInstanceToLayer → 插 A 链（depth 降序，同 0x1add90 那套）→ 插 ms_ID2InstanceE
 *     → CollisionInsert(inst) → dest+0xa4[dest+0xa8++] = rec+0x0c
 *   ★ 这套新建**不走 CInstance::Assign**：实例是从「房间 chunk 的模板」现造的，不是克隆别人。
 */

/* @0x1ade8c ldr r9, [sp, #0x10] */
/* @0x1ade90 ldr r9, [r9, #0xc8] */
/* @0x1ade94 cmp r9, #0 */
/* @0x1ade98 str r9, [sp, #0x14] */
/* @0x1ade9c beq 0x1ae0f0 <_ZN5CRoom6AssignEPS_b+0x9e4> */
/* @0x1adea0 ldr r6, [sp, #0x14] */
/* @0x1adea4 movw r2, #0x18e */
/* @0x1adea8 ldr r1, [pc, #0x458] */
/* @0x1adeac mov r3, #1 */
/* @0x1adeb0 mov r7, #0 */
/* @0x1adeb4 ldr r0, [r6] */
/* @0x1adeb8 add r1, pc, r1 */
/* @0x1adebc lsl r0, r0, #2 */
/* @0x1adec0 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1adec4 ldr r2, [r6] */
/* @0x1adec8 mov r1, r7 */
/* @0x1adecc str r7, [r4, #0xa8] */
/* @0x1aded0 lsl r2, r2, #2 */
/* @0x1aded4 str r0, [r4, #0xa4] */
/* @0x1aded8 bl 0xb65b0 <memset@plt> */
/* @0x1adedc ldr r2, [r6] */
/* @0x1adee0 cmp r2, r7 */
/* @0x1adee4 ble 0x1ae0f0 <_ZN5CRoom6AssignEPS_b+0x9e4> */
/* @0x1adee8 ldr r11, [sp, #0x14] */
/* @0x1adeec vldr s16, [pc, #1008] */
/* @0x1adef0 ldr r9, [pc, #0x414] */
/* @0x1adef4 add r9, pc, r9 */
/* @0x1adef8 str r9, [sp, #0x20] */
/* @0x1adefc ldr r6, [r11, #0x4]! */
/* @0x1adf00 ldr r3, [r6, #0x8] */
/* @0x1adf04 cmp r3, #0 */
/* @0x1adf08 blt 0x1ae0e4 <_ZN5CRoom6AssignEPS_b+0x9d8> */
/* @0x1adf0c mov r0, #432 */
/* @0x1adf10 mov r9, #1 */
/* @0x1adf14 bl 0x27c524 <_Znwj> */
/* @0x1adf18 vldr s10, [r6] */
/* @0x1adf1c vcvt.f32.s32 s10, s10 */
/* @0x1adf20 ldr r2, [r6, #0x4] */
/* @0x1adf24 ldr r12, [r6, #0x8] */
/* @0x1adf28 ldr r3, [r6, #0xc] */
/* @0x1adf2c str r9, [sp, #0x4] */
/* @0x1adf30 str r12, [sp] */
/* @0x1adf34 vmov r1, s10 */
/* @0x1adf38 vmov s10, r2 */
/* @0x1adf3c vcvt.f32.s32 s10, s10 */
/* @0x1adf40 vmov r2, s10 */
/* @0x1adf44 mov r5, r0 */
/* @0x1adf48 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1adf4c ldr r0, [r6, #0x10] */
/* @0x1adf50 bl 0xced64 <_Z13Code_GetEntryi> */
/* @0x1adf54 str r0, [r5, #0x160] */
/* @0x1adf58 ldr r0, [r6, #0x24] */
/* @0x1adf5c bl 0xced64 <_Z13Code_GetEntryi> */
/* @0x1adf60 ldr r1, [r6, #0x14] */
/* @0x1adf64 str r0, [r5, #0x164] */
/* @0x1adf68 mov r0, r5 */
/* @0x1adf6c bl 0x192fec <_ZN9CInstance14SetImageScaleXEf> */
/* @0x1adf70 mov r0, r5 */
/* @0x1adf74 ldr r1, [r6, #0x18] */
/* @0x1adf78 bl 0x193014 <_ZN9CInstance14SetImageScaleYEf> */
/* @0x1adf7c ldr r3, [r6, #0x1c] */
/* @0x1adf80 mov r0, r5 */
/* @0x1adf84 bic r3, r3, #-16777216 */
/* @0x1adf88 str r3, [r5, #0xa8] */
/* @0x1adf8c ldrb r1, [r6, #0x1f] */
/* @0x1adf90 vmov s15, r1 */
/* @0x1adf94 vcvt.f32.s32 s15, s15 */
/* @0x1adf98 vdiv.f32 s15, s15, s16 */
/* @0x1adf9c vstr s15, [r5, #164] */
/* @0x1adfa0 ldr r1, [r6, #0x20] */
/* @0x1adfa4 bl 0x19303c <_ZN9CInstance13SetImageAngleEf> */
/* @0x1adfa8 ldr r9, [sp, #0x18] */
/* @0x1adfac ldr r3, [pc, #0x35c] */
/* @0x1adfb0 mov r0, r5 */
/* @0x1adfb4 ldr r2, [r5, #0x7c] */
/* @0x1adfb8 mov r1, r4 */
/* @0x1adfbc ldr r3, [r9, r3] */
/* @0x1adfc0 str r2, [r3] */
/* @0x1adfc4 bl 0x192cd4 <_ZN9CInstance17CreatePhysicsBodyEP5CRoom> */
/* @0x1adfc8 ldr r1, [r5, #0x78] */
/* @0x1adfcc mov r0, r4 */
/* @0x1adfd0 bl 0x1b8cb8 <_ZN13CLayerManager21GetLayerIDForInstanceEP5CRoomi> */
/* @0x1adfd4 mov r1, r0 */
/* @0x1adfd8 mov r0, r4 */
/* @0x1adfdc bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1adfe0 mov r2, r5 */
/* @0x1adfe4 mov r1, r0 */
/* @0x1adfe8 mov r0, r4 */
/* @0x1adfec bl 0x1c5a38 <_ZN13CLayerManager18AddInstanceToLayerEP5CRoomP6CLayerP9CInstance> */
/* @0x1adff0 ldr r3, [r4, #0x84] */
/* @0x1adff4 ldr r2, [r4, #0x88] */
/* @0x1adff8 cmp r3, #0 */
/* @0x1adffc vldrne s14, [r5, #384] */
/* @0x1ae000 add r2, r2, #1 */
/* @0x1ae004 str r2, [r4, #0x88] */
/* @0x1ae008 beq 0x1ae334 <_ZN5CRoom6AssignEPS_b+0xc28> */
/* @0x1ae00c vldr s15, [r3, #388] */
/* @0x1ae010 vcmpe.f32 s15, s14 */
/* @0x1ae014 vmrs APSR_nzcv, fpscr */
/* @0x1ae018 bls 0x1ae248 <_ZN5CRoom6AssignEPS_b+0xb3c> */
/* @0x1ae01c ldr r3, [r3, #0x17c] */
/* @0x1ae020 cmp r3, #0 */
/* @0x1ae024 bne 0x1ae00c <_ZN5CRoom6AssignEPS_b+0x900> */
/* @0x1ae028 ldr r2, [r4, #0x80] */
/* @0x1ae02c vstr s14, [r5, #388] */
/* @0x1ae030 str r5, [r2, #0x17c] */
/* @0x1ae034 str r2, [r5, #0x178] */
/* @0x1ae038 str r5, [r4, #0x80] */
/* @0x1ae03c str r3, [r5, #0x17c] */
/* @0x1ae040 ldr lr, [pc, #0x2ac] */
/* @0x1ae044 movw r2, #0x132 */
/* @0x1ae048 ldr r9, [sp, #0x18] */
/* @0x1ae04c mov r3, #1 */
/* @0x1ae050 ldr r12, [r5, #0x78] */
/* @0x1ae054 mov r0, #16 */
/* @0x1ae058 ldr r1, [sp, #0x20] */
/* @0x1ae05c ldr r8, [r9, lr] */
/* @0x1ae060 ldm r8, {r9, r10} */
/* @0x1ae064 str r12, [sp, #0xc] */
/* @0x1ae068 and r10, r12, r10 */
/* @0x1ae06c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ae070 ldr r12, [sp, #0xc] */
/* @0x1ae074 ldr r2, [r9, r10, lsl #3] */
/* @0x1ae078 add r3, r9, r10, lsl #3 */
/* @0x1ae07c cmp r2, #0 */
/* @0x1ae080 ldrne r2, [r3, #0x4] */
/* @0x1ae084 movne r1, #0 */
/* @0x1ae088 str r12, [r0, #0x8] */
/* @0x1ae08c str r5, [r0, #0xc] */
/* @0x1ae090 strne r2, [r0] */
/* @0x1ae094 streq r0, [r3, #0x4] */
/* @0x1ae098 strne r0, [r2, #0x4] */
/* @0x1ae09c strne r0, [r3, #0x4] */
/* @0x1ae0a0 ldr r3, [r8, #0x8] */
/* @0x1ae0a4 streq r0, [r9, r10, lsl #3] */
/* @0x1ae0a8 strne r1, [r0, #0x4] */
/* @0x1ae0ac add r3, r3, #1 */
/* @0x1ae0b0 streq r2, [r0, #0x4] */
/* @0x1ae0b4 streq r2, [r0] */
/* @0x1ae0b8 mov r0, r5 */
/* @0x1ae0bc str r3, [r8, #0x8] */
/* @0x1ae0c0 bl 0x1cc494 <_Z15CollisionInsertP9CInstance> */
/* @0x1ae0c4 ldr r3, [r4, #0xa8] */
/* @0x1ae0c8 ldr r1, [r6, #0xc] */
/* @0x1ae0cc ldr r2, [r4, #0xa4] */
/* @0x1ae0d0 add r0, r3, #1 */
/* @0x1ae0d4 ldr r12, [sp, #0x14] */
/* @0x1ae0d8 str r0, [r4, #0xa8] */
/* @0x1ae0dc str r1, [r2, r3, lsl #2] */
/* @0x1ae0e0 ldr r2, [r12] */
/* @0x1ae0e4 add r7, r7, #1 */
/* @0x1ae0e8 cmp r2, r7 */
/* @0x1ae0ec bgt 0x1adefc <_ZN5CRoom6AssignEPS_b+0x7f0> */
/* ── 段7 重建：把 +0xc4 的 48 B 原始记录展开成 56 B RTile 表 ─────────
 *   条件：[sp+0x24]（src+0xc4）非 0。count = dest+0xb8（0x1ae2a0/0x1ae2b0 已置好）；
 *   count == 0 → 0x1ae31c（Free dest+0xc0 再置 0，然后继续）；
 *   否则 rsb 算出 count*7 → lsl #3 = count*56，ReAlloc(dest+0xc0)，dest+0xbc = count；
 *   逐条（r1 走指针数组 +4，r3 走目的 +56）：
 *     RTile+0x00 = (float)rec+0x00   +0x04 = (float)rec+0x04   +0x08 = rec+0x08
 *     +0x0c = rec+0x0c  +0x10 = rec+0x10  +0x14 = rec+0x14  +0x18 = rec+0x18
 *     +0x1c = (float)rec+0x1c（vcvt.f32.s32）  +0x20 = rec+0x20（id，整字搬）
 *     +0x24 = rec+0x24  +0x28 = rec+0x28（整字搬；Serialise/DeSerialise 对这两格用的是 t8，
 *       若源侧确实是 float 则位拷贝等价 —— 源记录这两格的实际类型未单独取证）
 *     +0x2c = rec+0x2c & 0xFFFFFF（blend）+0x30 = (rec+0x2c >> 24)/255.0f（alpha）
 *     +0x34 = 1（bool，恒真）
 *   ★ 这张映射表与 Serialise/DeSerialise 的 14 字段表逐项吻合（尤其 +0x2c int / +0x30 float），
 *     是「RTile 表 = 由 tile 模板展开」的直接证据；+0x34 恒 1 说明「由模板建的 tile 一律启用」。
 *   ★ 0x1ae1e0 strb r6,[r3,#-0x34]，r6 在 0x1ae148 置 1。
 */

/* @0x1ae0f0 ldr r12, [sp, #0x24] */
/* @0x1ae0f4 cmp r12, #0 */
/* @0x1ae0f8 beq 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae0fc ldr r5, [r4, #0xb8] */
/* @0x1ae100 cmp r5, #0 */
/* @0x1ae104 beq 0x1ae31c <_ZN5CRoom6AssignEPS_b+0xc10> */
/* @0x1ae108 rsb r3, r5, r5, lsl #3 */
/* @0x1ae10c ldr r0, [r4, #0xc0] */
/* @0x1ae110 lsls r1, r3, #3 */
/* @0x1ae114 beq 0x1ae3d8 <_ZN5CRoom6AssignEPS_b+0xccc> */
/* @0x1ae118 ldr r2, [pc, #0x1f4] */
/* @0x1ae11c mov r3, #0 */
/* @0x1ae120 str r3, [sp] */
/* @0x1ae124 mov r3, #106 */
/* @0x1ae128 add r2, pc, r2 */
/* @0x1ae12c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae130 str r0, [r4, #0xc0] */
/* @0x1ae134 ldr r7, [r4, #0xb8] */
/* @0x1ae138 str r5, [r4, #0xbc] */
/* @0x1ae13c cmp r7, #0 */
/* @0x1ae140 ble 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae144 ldr r3, [r4, #0xc0] */
/* @0x1ae148 mov r6, #1 */
/* @0x1ae14c ldr r1, [sp, #0x24] */
/* @0x1ae150 vldr s11, [pc, #396] */
/* @0x1ae154 add r3, r3, #48 */
/* @0x1ae158 add r7, r1, r7, lsl #2 */
/* @0x1ae15c ldr r2, [r1, #0x4]! */
/* @0x1ae160 vldr s14, [r2, #4] */
/* @0x1ae164 vldr s15, [r2, #28] */
/* @0x1ae168 vldr s10, [r2] */
/* @0x1ae16c vcvt.f32.s32 s14, s14 */
/* @0x1ae170 cmp r1, r7 */
/* @0x1ae174 ldr r0, [r2, #0x2c] */
/* @0x1ae178 add r3, r3, #56 */
/* @0x1ae17c ldr r8, [r2, #0x8] */
/* @0x1ae180 bic r12, r0, #-16777216 */
/* @0x1ae184 ldr r5, [r2, #0xc] */
/* @0x1ae188 lsr r0, r0, #24 */
/* @0x1ae18c ldr r9, [r2, #0x24] */
/* @0x1ae190 str r8, [r3, #-0x60] */
/* @0x1ae194 vmov s13, r0 */
/* @0x1ae198 ldr r8, [r2, #0x28] */
/* @0x1ae19c vcvt.f32.s32 s12, s10 */
/* @0x1ae1a0 str r5, [r3, #-0x5c] */
/* @0x1ae1a4 ldr r5, [r2, #0x10] */
/* @0x1ae1a8 ldr r0, [r2, #0x18] */
/* @0x1ae1ac str r5, [r3, #-0x58] */
/* @0x1ae1b0 ldr r5, [r2, #0x14] */
/* @0x1ae1b4 ldr r2, [r2, #0x20] */
/* @0x1ae1b8 vstr s14, [r3, #-100] */
/* @0x1ae1bc vcvt.f32.s32 s13, s13 */
/* @0x1ae1c0 vstr s12, [r3, #-104] */
/* @0x1ae1c4 str r9, [r3, #-0x44] */
/* @0x1ae1c8 str r5, [r3, #-0x54] */
/* @0x1ae1cc str r8, [r3, #-0x40] */
/* @0x1ae1d0 str r0, [r3, #-0x50] */
/* @0x1ae1d4 str r2, [r3, #-0x48] */
/* @0x1ae1d8 str r12, [r3, #-0x3c] */
/* @0x1ae1dc vdiv.f32 s13, s13, s11 */
/* @0x1ae1e0 strb r6, [r3, #-0x34] */
/* @0x1ae1e4 vcvt.f32.s32 s15, s15 */
/* @0x1ae1e8 vstr s13, [r3, #-56] */
/* @0x1ae1ec vstr s15, [r3, #-76] */
/* @0x1ae1f0 bne 0x1ae15c <_ZN5CRoom6AssignEPS_b+0xa50> */
/* @0x1ae1f4 b 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* ── A 链插入的两种落位（模板实例化路径复用同一套）─────────────────────
 *   A 链中段/头部插入：cur->prev == 0 → 成为新 head（+0x84 = inst）；否则插在 prev 与 cur 之间；
 *   两路最后都 vstr depth → inst+0x184（快照）。
 */

/* @0x1ae1f8 ldr r2, [r3, #0x178] */
/* @0x1ae1fc cmp r2, #0 */
/* @0x1ae200 streq r3, [r5, #0x17c] */
/* @0x1ae204 strne r2, [r5, #0x178] */
/* @0x1ae208 ldrne r2, [r3, #0x178] */
/* @0x1ae20c streq r5, [r3, #0x178] */
/* @0x1ae210 strne r3, [r5, #0x17c] */
/* @0x1ae214 streq r5, [r4, #0x84] */
/* @0x1ae218 strne r5, [r2, #0x17c] */
/* @0x1ae21c streq r2, [r5, #0x178] */
/* @0x1ae220 strne r5, [r3, #0x178] */
/* @0x1ae224 vstr s14, [r5, #388] */
/* @0x1ae228 b 0x1addc4 <_ZN5CRoom6AssignEPS_b+0x6b8> */
/* ── A 链空链首插：head = tail = inst，+0x184 = +0x180（depth 快照），两链域清零 ── */

/* @0x1ae22c ldr r2, [r5, #0x180] */
/* @0x1ae230 str r5, [r4, #0x84] */
/* @0x1ae234 str r5, [r4, #0x80] */
/* @0x1ae238 str r2, [r5, #0x184] */
/* @0x1ae23c str r3, [r5, #0x17c] */
/* @0x1ae240 str r3, [r5, #0x178] */
/* @0x1ae244 b 0x1addc4 <_ZN5CRoom6AssignEPS_b+0x6b8> */
/* ── A 链插入（克隆路径用的那一份，与 0x1ae1f8 同构，寄存器分配不同）──── */

/* @0x1ae248 ldr r2, [r3, #0x178] */
/* @0x1ae24c cmp r2, #0 */
/* @0x1ae250 streq r3, [r5, #0x17c] */
/* @0x1ae254 strne r2, [r5, #0x178] */
/* @0x1ae258 ldrne r2, [r3, #0x178] */
/* @0x1ae25c streq r5, [r3, #0x178] */
/* @0x1ae260 strne r3, [r5, #0x17c] */
/* @0x1ae264 streq r5, [r4, #0x84] */
/* @0x1ae268 strne r5, [r2, #0x17c] */
/* @0x1ae26c streq r2, [r5, #0x178] */
/* @0x1ae270 strne r5, [r3, #0x178] */
/* @0x1ae274 vstr s14, [r5, #388] */
/* @0x1ae278 b 0x1ae040 <_ZN5CRoom6AssignEPS_b+0x934> */
/* ── 容器「退化」路径：src+0xac 存在但 +0x34 == 0 ──────────────────────
 *   把 [sp+0x28] 与 [sp+0x2c] 都置 4、[sp+0x14] = [sp+0x20]（此时 = 0，即 N = 0），
 *   跳回 0x1adae8 继续走「建 96 B 容器 + 两张空表」的同一段代码（两张表都只剩 4 字节表头）。
 */

/* @0x1ae27c ldr r6, [sp, #0x20] */
/* @0x1ae280 mov r12, #4 */
/* @0x1ae284 str r12, [sp, #0x28] */
/* @0x1ae288 str r12, [sp, #0x2c] */
/* @0x1ae28c str r6, [sp, #0x14] */
/* @0x1ae290 b 0x1adae8 <_ZN5CRoom6AssignEPS_b+0x3dc> */
/* ── +0xb8 的来源：src+0xc4 数组的 count 字 ─────────────────────────
 *   r7 = src+0xc4；dest+0xb8 = 0；[sp+0x24] = r7；若 r7 != 0 则 dest+0xb8 = [r7]（= count）。
 *   ⇒ +0xb8 = 「tile 模板条数」，也是即将重建的 RTile 条数（1:1 展开）。
 */

/* @0x1ae294 ldr r7, [sp, #0x10] */
/* @0x1ae298 mov r3, #0 */
/* @0x1ae29c ldr r7, [r7, #0xc4] */
/* @0x1ae2a0 str r3, [r4, #0xb8] */
/* @0x1ae2a4 cmp r7, r3 */
/* @0x1ae2a8 str r7, [sp, #0x24] */
/* @0x1ae2ac ldrne r3, [r7] */
/* @0x1ae2b0 strne r3, [r4, #0xb8] */
/* @0x1ae2b4 b 0x1ade8c <_ZN5CRoom6AssignEPS_b+0x780> */
/* ── RTile 直拷路径（dest+0xd0 == 0）───────────────────────────────
 *   r5 = src+0xb8（count）→ dest+0xb8 = r5；count != 0 → 0x1ae350（ReAlloc + 56 B 块搬）；
 *   count == 0 → Free dest+0xc0 并置 0，再走 0x1ae378 的空循环。
 *   注意这里 cap 也被置成 count（dest+0xbc = r5）—— 与 DeSerialise 同一种「容量 = 条数」归一。
 */

/* @0x1ae2b8 ldr r6, [sp, #0x10] */
/* @0x1ae2bc ldr r5, [r6, #0xb8] */
/* @0x1ae2c0 cmp r5, #0 */
/* @0x1ae2c4 str r5, [r4, #0xb8] */
/* @0x1ae2c8 bne 0x1ae350 <_ZN5CRoom6AssignEPS_b+0xc44> */
/* @0x1ae2cc ldr r0, [r4, #0xc0] */
/* @0x1ae2d0 cmp r0, #0 */
/* @0x1ae2d4 beq 0x1ae3e8 <_ZN5CRoom6AssignEPS_b+0xcdc> */
/* @0x1ae2d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae2dc str r5, [r4, #0xc0] */
/* @0x1ae2e0 b 0x1ae378 <_ZN5CRoom6AssignEPS_b+0xc6c> */
/* ── 字面量池（0x1ae2e4..0x1ae318，14 字；不是指令）───────────────────
 *   逐字真值见文件头「池」一节：255.0f / GOT 基址加数 / 4 个 GOT 偏移 / 8 个串加数。
 *   0x1ae2ec → g_isZeus、0x1ae2f0 → g_CM、0x1ae2f4 → CInstance::ms_ID2InstanceE、
 *   0x1ae310 → Current_Object（四个名字都来自 .dynsym）。
 *   下面 14 条锚点按索引原样保留（objdump 把它们译成 andseq/ldrsheq/.word 之类）。
 */

/* @0x1ae2e4 cmnmi pc, #0 */
/* @0x1ae2e8 eoreq r4, r4, r0, lsr #10 */
/* @0x1ae2ec .word 0xffffbcd4 */
/* @0x1ae2f0 .word 0xffffc024 */
/* @0x1ae2f4 .word 0xffffbff4 */
/* @0x1ae2f8 andseq pc, r9, r0, asr #6 */
/* @0x1ae2fc andseq pc, r9, r8, lsr #13 */
/* @0x1ae300 andseq pc, r9, r8, ror #10 */
/* @0x1ae304 andseq lr, r9, r12, ror pc */
/* @0x1ae308 ldrsheq pc, [r9], -r0 */
/* @0x1ae30c ldrheq lr, [r9], -r8 */
/* @0x1ae310 .word 0xffffc168 */
/* @0x1ae314 andseq pc, r9, r12, lsl #2 */
/* @0x1ae318 andseq lr, r9, r8, asr #29 */
/* ── 空表出口：Free dest+0xc0 → 0，再进 0x1ae378 的空循环 ──────────────── */

/* @0x1ae31c ldr r0, [r4, #0xc0] */
/* @0x1ae320 cmp r0, #0 */
/* @0x1ae324 beq 0x1ae3d8 <_ZN5CRoom6AssignEPS_b+0xccc> */
/* @0x1ae328 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae32c str r5, [r4, #0xc0] */
/* @0x1ae330 b 0x1ae134 <_ZN5CRoom6AssignEPS_b+0xa28> */
/* @0x1ae334 ldr r2, [r5, #0x180] */
/* @0x1ae338 str r5, [r4, #0x84] */
/* @0x1ae33c str r5, [r4, #0x80] */
/* @0x1ae340 str r2, [r5, #0x184] */
/* @0x1ae344 str r3, [r5, #0x17c] */
/* @0x1ae348 str r3, [r5, #0x178] */
/* @0x1ae34c b 0x1ae040 <_ZN5CRoom6AssignEPS_b+0x934> */
/* ── RTile 表 ReAlloc + 56 B 整块搬（0x1ae350..0x1ae3d4）──────────────
 *   rsb r2,r5,r5,lsl #3 → count*7；lsls r1,r2,#3 → count*56；ReAlloc(dest+0xc0, count*56)
 *   → dest+0xbc = count → 逐条 ldm/stm：4+4+4 字（48 B）+ 2 字（8 B）= 56 B，源 = src+0xc0 + k*56。
 *   ★ 这是纯字节搬运，不解释字段 —— 与 0x1ae0f0 的「逐字段展开」是同一个目的地的两种来源。
 */

/* @0x1ae350 rsb r2, r5, r5, lsl #3 */
/* @0x1ae354 ldr r0, [r4, #0xc0] */
/* @0x1ae358 lsls r1, r2, #3 */
/* @0x1ae35c beq 0x1ae3e8 <_ZN5CRoom6AssignEPS_b+0xcdc> */
/* @0x1ae360 ldr r2, [pc, #-0x50] */
/* @0x1ae364 str r3, [sp] */
/* @0x1ae368 mov r3, #106 */
/* @0x1ae36c add r2, pc, r2 */
/* @0x1ae370 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae374 str r0, [r4, #0xc0] */
/* @0x1ae378 ldr r7, [r4, #0xb8] */
/* @0x1ae37c str r5, [r4, #0xbc] */
/* @0x1ae380 cmp r7, #0 */
/* @0x1ae384 ble 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae388 ldr r12, [sp, #0x10] */
/* @0x1ae38c rsb r7, r7, r7, lsl #3 */
/* @0x1ae390 ldr r8, [r4, #0xc0] */
/* @0x1ae394 mov r6, #0 */
/* @0x1ae398 lsl r7, r7, #3 */
/* @0x1ae39c ldr r9, [r12, #0xc0] */
/* @0x1ae3a0 add r5, r9, r6 */
/* @0x1ae3a4 add r12, r8, r6 */
/* @0x1ae3a8 add r6, r6, #56 */
/* @0x1ae3ac ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3b0 cmp r6, r7 */
/* @0x1ae3b4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3b8 ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3bc stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3c0 ldm r5!, {r0, r1, r2, r3} */
/* @0x1ae3c4 stm r12!, {r0, r1, r2, r3} */
/* @0x1ae3c8 ldm r5, {r0, r1} */
/* @0x1ae3cc stm r12, {r0, r1} */
/* @0x1ae3d0 bne 0x1ae3a0 <_ZN5CRoom6AssignEPS_b+0xc94> */
/* @0x1ae3d4 b 0x1add10 <_ZN5CRoom6AssignEPS_b+0x604> */
/* @0x1ae3d8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae3dc mov r3, #0 */
/* @0x1ae3e0 str r3, [r4, #0xc0] */
/* @0x1ae3e4 b 0x1ae134 <_ZN5CRoom6AssignEPS_b+0xa28> */
/* @0x1ae3e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae3ec mov r3, #0 */
/* @0x1ae3f0 str r3, [r4, #0xc0] */
/* @0x1ae3f4 b 0x1ae378 <_ZN5CRoom6AssignEPS_b+0xc6c> */
