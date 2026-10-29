/* cally 逆向卡：Room_Add / Room_Duplicate / Room_Free（原版 libyoyo.so，armv7）—— 一卡三节
 * @func 0x1b5044 0x1b523c  size 504  126 条   §1 Room_Free()          （115 指令 + 11 池字）
 * @func 0x1b5348 0x1b56f0  size 936  234 条   §2 Room_Add()           （211 指令 + 19 池字）
 * @func 0x1b56e0 0x1b5af4  size 1044  261 条   §3 Room_Duplicate(int)  （240 指令 + 21 池字）
 * 总账: 617 锚点 = 566 条指令 + 51 个池字，与 asm/index-RoomOps_all.tsv 逐字一致
 *       （scripts/check_card_anchors.py --index asm/index-RoomOps_all.tsv →
 *        index=617 card=617 missing=0 extra=0 mismatch=0 RESULT EXACT）；
 *       逐节账：§1 126 = 115 + 11（0x1b5210..0x1b5238）、§2 230 = 211 + 19（0x1b5694..0x1b56dc）、
 *       §3 261 = 240 + 21（0x1b5aa0..0x1b5af0）。池字按 objdump 写法保留，注释里标「非指令」并给出真值。
 * 级别: 正文（三节 617/617 逐条落锚；三函数对全局房间表 0x5425d0 的每一格读写、两条 ReAlloc 的文件名/行号、
 *       全部 new/delete 路径、两处栈保护字、九段死支的边界都已钉死。未钉的只有运行期后果与
 *       「谁在本库之外改这两张表」，逐节 open 单列）
 *       tier = bytecode_anchored
 * 符号: _Z9Room_Freev(0x1b5044,504) / _Z8Room_Addv(0x1b5348,920) / _Z14Room_Duplicatei(0x1b56e0,1044)，
 *       三个都是 .dynsym FUNC GLOBAL DEFAULT（st_size 直读，与 asm/functions.tsv 一致）。
 * ABI : softfp。Room_Add 返回 int（新房间下标），Room_Duplicate 返回 int（下标或 -1），Room_Free 无返回。
 *       返回值在 GML 侧一律转 double：F_RoomAdd 0x12e7d0-0x12e7e4（vmov s15,r0 / vcvt.f64.s32 / stm），
 *       F_RoomDuplicate 0x12e818 同款。
 * 同层: 全局房间表 0x5425d0（24 B 六格，语义见 Room_Load 卡）；Room_Data 0x1b52c4 / Room_Number 0x1b523c /
 *       Room_Find 0x1b524c / Room_Name 0x1b530c / Room_Exists 0x1b52f8 / Room_Assign 0x1b5af4 /
 *       Room_LoadOrder 0x1b5ba0 / Room_First 0x1b5d08 / Room_Last 0x1b5d20 / Room_Previous 0x1b5d40 /
 *       Room_Next 0x1b5da4；CRoom::C2 0x1ad2cc / CRoom::CreateWADStorage 0x1a92c0 / CRoom::Assign 0x1ad70c /
 *       CRoom::~CRoom 0x1afa00；operator new 0x27c524 / operator delete 0x27d1d0 /
 *       MemoryManager::Alloc 0x27ce78 / ReAlloc 0x27cedc / Free 0x27c2d0 / IsAllocated 0x27c454 /
 *       YYStrDup 0xdb8c8 / snprintf@plt 0xb65c8 / __stack_chk_fail@plt 0xb65d4；
 *       FINALIZE_Room_Main 0x1b5e54（Room_Free 的唯一调用点 0x1b5e58）、F_RoomAdd 0x12e7bc、
 *       F_RoomDuplicate 0x12e7ec（Room_Add / Room_Duplicate 的唯一调用点 0x12e7cc / 0x12e814）。
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   Room_Add 与 Room_Duplicate 是同一段「向两张平行表各追加一格」的模板的两次实例化：
 *   snprintf(buf,128,"__newroom%d", <计数>) → YYStrDup → ReAlloc 名字表 (n+1)*4 → 名字计数 +1 → 存串；
 *   new(292) + CRoom::C2()（Add 另加 CreateWADStorage）→ ReAlloc 房间表 (m+1)*4 → 房间计数 +1 → 存指针；
 *   注意 new/C2 发生在房间表扩容**之前**，而名字是在 new 之前就落进名字表的。
 *   差别只有三处：① 名字编号取哪个计数（Add 取名字计数 [+0x08]，Duplicate 取房间计数 [+0x00]）；
 *   ② Add 在 C2 之后补一次 CRoom::CreateWADStorage()，Duplicate 不补；
 *   ③ Duplicate 在存指针之后把新房间的 +0xd0 置 1，再 CRoom::Assign(src, false) 把源房间内容搬进来。
 *   Room_Free 是唯一把六格全拆掉的函数：先把 Run_Room(0x54298c) 清 0，再逐 CRoom 析构 + operator delete、
 *   放房间数组、清房间计数，然后放顺序表、放名字表（逐串 IsAllocated 后 Free）、清两个名字/顺序计数。
 *   它是 FINALIZE_Room_Main 0x1b5e54 的唯一动作（0x1b5e58），也就是退出时的房间总拆。
 *
 * ── 六格 × 四函数：本卡与 Room_Load 的一致性（全部逐条锚定）────────────────
 *   格      Room_Load(0x1b4cd8)        Room_Add(§2)              Room_Duplicate(§3)      Room_Free(§1)
 *   +0x00   = n（0x1b4de4）            = n+1（0x1b5594）          = n+1（0x1b5968）        = 0（0x1b5124 / 0x1b5114）
 *   +0x04   ReAlloc(n*4) @1b4fe0       ReAlloc((n+1)*4) @1b5664   ReAlloc((n+1)*4) @1b5a4c  Free + 0（0x1b5104 / 0x1b5204）
 *   +0x08   = n（0x1b4e84）            = n+1（0x1b5430）          = n+1（0x1b580c）        = 0（0x1b51dc）
 *   +0x0c   ReAlloc(n*4) @1b4f94       ReAlloc((n+1)*4) @1b561c   ReAlloc((n+1)*4) @1b57f0 逐串 Free + Free + 0（0x1b51bc..0x1b51cc）
 *   +0x10   不碰（Room_LoadOrder 写）  不碰                       不碰                     = 0（0x1b5158）
 *   +0x14   不碰（Room_LoadOrder 写）  不碰                       不碰                     Free + 0（0x1b513c / 0x1b5144）
 *   ⇒ 两条「+n」路径（Add/Dup）从不碰 +0x10/+0x14：顺序表只在 Room_LoadOrder 里重建，所以新加/复制出来的房间
 *     不进顺序链，Room_First/Last/Previous/Next（只读这两格，0x1b5d08..0x1b5dfc）看不到它们。
 *   ⇒ 两条 ReAlloc 的 (文件, 行) 与 Room_Load 完全同一对：名字表 cARRAY_MEMORY.h:92（串 0x34d330）、
 *     房间表 cARRAY_CLASS.h:135（串 0x34d2f8）；第 5 个参数恒 false（不清零），与 Room_Load 一致。
 *
 * ── 三条最硬的结论（本卡新增）────────────────────────────────────────────
 *   1. **Room_Free 释放 CRoom、也清名字表**：析构循环 0x1b5094..0x1b50fc 对每个非空非 0xfeeefeee 的槽调
 *      CRoom::~CRoom + operator delete 并回写 0；名字表 0x1b515c..0x1b51b4 对每个 IsAllocated 的串 Free 并回写 0，
 *      随后 0x1b51bc 放数组、0x1b51cc 清 +0x0c、0x1b51dc 清 +0x08。六格无一遗漏。
 *   2. **Room_Duplicate 是 CRoom+0xd0 的唯一置 1 者**：0x1b59d8 `strb r3,[r0,#0xd0]`（r3=1），对刚存进
 *      rooms[n] 的新房间执行，发生在 CRoom::Assign 之前。全 .text 里 `strb <reg>, [<reg>, #0xd0]` 只有 3 条：
 *      CRoom::C2 0x1ad4e4（写 0）、本函数 0x1b59d8（写 1，活）、0x1b5a28（写 1，死支，r3=0 会写绝对地址 0xd0）。
 *      ⇒ CRoom_Assign 卡里「+0xd0 的置位者未在已索引函数中出现」这条 open，答案在这里：复制房间时置 1
 *      （Assign 段7 因此走「深建 96 B tile 容器」而不是浅共享）。
 *   3. **名字串格式是 "__newroom%d"**：§2 0x1b5364/0x1b5374 与 §3 0x1b5710/0x1b5720 都取 0x34d39c 处的
 *      串；该地址的实测字节 = "__newroom%d"（它位于 0x34d368 的 "jni/../jni/yoyo/../../../Files/Room/
 *      Room_Main.cpp"（49 字符 + NUL）之后 0x34 字节处，中间隔 2 字节对齐空洞）。
 *      4 号参数分别是旧名字计数（Add）/ 旧房间计数（Duplicate）。
 *      ⇒ 新房间在 Room_Find/Room_Name 眼里名叫 "__newroom0"、"__newroom1"……；而 CRoom+0x08 的内部名字
 *      仍是 C2 写的 0（Add 路径）或 Assign 从源房间 YYStrDup 来的串（Duplicate 路径）——两套名字。
 *
 * ── 结构性事实与缺口（按证据强度分级）──────────────────────────────────────
 *   ① [已证] Room_Free 在 count==0 而 rooms!=0 时不释放数组（0x1b5068 beq 0x1b5128 整段跳过），
 *      而名字表按指针判空（0x1b515c）——同一状态下两表待遇不同，房间数组是唯一会漏的一块。
 *   ② [已证] Room_Free 先把 Run_Room 写 0（0x1b5060）再析构房间：析构期间全局「当前房间」已为空。
 *      后果（推断，未做运行期对照）：~CRoom/operator delete 里若有回调读 Run_Room，会读到 NULL。
 *   ③ [已证] Add/Dup 的 ReAlloc 只放大到 (n+1)*4、不预先析构旧 CRoom；因为它们只追加、从不覆盖已有槽，
 *      所以不像 Room_Load 的 n!=0 分支那样泄漏 CRoom。代价是这两张表在库内永不缩小。
 *   ④ [已证] 两个计数（+0x00 房间 / +0x08 名字）在库内始终同值：Room_Init 同时清 0、Room_Load 同时写 n、
 *      Free 同时清 0、Add/Dup 各自 +1，没有第三个写者。模板把「插入下标」写死成其中一个计数：
 *      Add 用名字计数去索引 rooms（0x1b55e0 的 r5 = [+0x08]），Duplicate 用房间计数去索引 names
 *      （0x1b5864 的 r5 = [+0x00]）。两计数一旦被外部拆开，这两处就会错位/越界——这是形状事实，
 *      可达性取决于库外写者（见 §2/§3 open）。
 *   ⑤ [已证] 九段死支（§2 四段 A1..A4、§3 五段 B1..B5）都是 cARRAY::Add(index) 模板的内联残形：插入下标 == 元素个数时
 *      「先移位」段恒不执行；「size==0 清空」段只在计数 == -1 时进入。其中 0x1b5a28 若可达会向绝对地址
 *      0xd0 写字节（必崩），是本卡唯一「不可达即安全」的指令。
 *   ⑥ [已证] 栈保护：§2 保护字在 sp+0x9c、§3 在 sp+0xa4，都取 GOT 0x3ed958 = __stack_chk_guard（GLOB_DAT）；
 *      §1 没有栈保护（帧里没有 canary 槽，也没有 __stack_chk_fail 调用）。
 *   ⑦ [已证] Room_Free **不重置** room_maxid(0x54255c) 与 room_maxtileid(0x542558)：三节 617 条里没有一条指令
 *      落到这两个地址。51 个池字逐一落表：42 个 → 0x5425d0，6 个 → 三处字符串（"__newroom%d" /
 *      cARRAY_MEMORY.h / cARRAY_CLASS.h），3 个 → GOT 槽（1 个 Run_Room 0x3ed930、2 个 __stack_chk_guard
 *      0x3ed958）。后果（推断）：maxid 在 Free/Load 之后继续单调。
 *
 * ── 读法 ───────────────────────────────────────────────────────────
 *   锚点逐字取自 asm/index-RoomOps_all.tsv，未手写转录；字面量注释里的「+ pc」都指该条 ldr 的 pc = 地址+8。
 *   §1/§2/§3 各以一条 ══ 横幅开始，横幅里给该节的符号、帧、寄存器约定与分支表；每节末尾给本节 open。
 */


/* ══ §1 Room_Free()  0x1b5044..0x1b5238  size 504  126 条（115 指令 + 11 池字）══════════════════
 * 唯一调用点: FINALIZE_Room_Main 0x1b5e58（全 .text 扫 bl/b 到 0x1b5044 只有这一条）。
 * 帧: push {r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}（40 B，sp 8 对齐）；无栈保护、无栈上局部量。
 * 寄存器约定：r8/r10/r11 都在用前各自重取一次 0x5425d0（每段独立取址，不是全程持有），
 *   r4 兼作「零值」与循环下标，r9 恒 0（回写槽的值）、r7 = i*4，r3 是 Run_Room 的地址（仅入口用一次）。
 *
 * ── 入口（0x1b5044..0x1b5063）：先清 Run_Room，再读计数 ─────────────────
 *   r8 = 0x5425d0（表基址）、r3 = *(GOT 0x3ed930) = 0x54298c = Run_Room、r2 = [+0x00] 房间计数。
 *   ★ 0x1b5060 `str r4,[r3]` 把 Run_Room 写 0 —— 发生在任何释放之前，是本函数的第一条副作用。
 */

/* @0x1b5044 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b5048 mov r4, #0 */
/* @0x1b504c ldr r8, [pc, #0x1bc] */
/* @0x1b5050 ldr r3, [pc, #0x1bc] */
/* @0x1b5054 add r8, pc, r8 */
/* @0x1b5058 ldr r3, [pc, r3] */
/* @0x1b505c ldr r2, [r8] */
/* @0x1b5060 str r4, [r3] */

/* ── 分流（0x1b5064..0x1b5077）────────────────────────────────────────
 *   count == 0                    → 0x1b5128（**跳过整段房间数组处理**，连 Free 都不做）
 *   count != 0 → r5 = [+0x04]      rooms == 0 → 0x1b5200（Free(0) → [+0x04]=0 → [+0x00]=0）
 *   count < 0                     → 0x1b5100（Free 数组 → 清两格，不跑析构循环；
 *                                   count > 0 的循环走完 0x1b50fc 也落到同一条 0x1b5100）
 *   第一条是真实缺口：count==0 且数组非空时，房间数组既不 Free 也不置 0（见头部 ①）。
 */

/* @0x1b5064 cmp r2, r4 */
/* @0x1b5068 beq 0x1b5128 <_Z9Room_Freev+0xe4> */
/* @0x1b506c ldr r5, [r8, #0x4] */
/* @0x1b5070 cmp r5, r4 */
/* @0x1b5074 beq 0x1b5200 <_Z9Room_Freev+0x1bc> */

/* ── 旧 CRoom 析构循环（0x1b5078..0x1b50fc）────────────────────────────
 *   count <= 0 → 0x1b5100；否则 r10/r11 各取一次 0x5425d0（一个在 delete 后重取数组，一个取数组本身），
 *   r9 = 0（回写槽的值）、r7 = i*4（0x1b50ac 计算）。循环体：三道闸门 → ~CRoom + operator delete → 槽写 0。
 *   闸门 1（0x1b5094）：每次重读 array[0]，与 0xfeeefeee 比 —— cARRAY_CLASS 模板的「数组块已释放」判据
 *     （MemoryManager::Free 把块头写成 0xfeeefeee），命中则整轮跳过但仍 ++i。
 *   闸门 2（0x1b50b4/0x1b50bc）：array[i] == 0 → 空槽，跳过。
 *   闸门 3（0x1b50c8/0x1b50cc）：array[i][0] == 0xfeeefeee → 对象已删过，跳过析构，但仍把槽写 0。
 *   ★ 0xfeeefeee 由谁写进对象首字，本卡未证（open 5）；三处判据与 Room_Load 段②、CRoom_AddInstance 同款。
 */

/* @0x1b5078 cmp r2, r4 */
/* @0x1b507c ble 0x1b5100 <_Z9Room_Freev+0xbc> */
/* @0x1b5080 ldr r10, [pc, #0x190] */
/* @0x1b5084 mov r9, r4 */
/* @0x1b5088 ldr r11, [pc, #0x18c] */
/* @0x1b508c add r10, pc, r10 */
/* @0x1b5090 add r11, pc, r11 */
/* @0x1b5094 ldr r1, [r5] */
/* @0x1b5098 movw r3, #0xfeee */
/* @0x1b509c movt r3, #0xfeee */
/* @0x1b50a0 movw r2, #0xfeee */
/* @0x1b50a4 cmp r1, r3 */
/* @0x1b50a8 movt r2, #0xfeee */
/* @0x1b50ac lsl r7, r4, #2 */
/* @0x1b50b0 beq 0x1b50f0 <_Z9Room_Freev+0xac> */
/* @0x1b50b4 ldr r6, [r5, r4, lsl #2] */
/* @0x1b50b8 add r3, r5, r7 */
/* @0x1b50bc cmp r6, #0 */
/* @0x1b50c0 mov r0, r6 */
/* @0x1b50c4 beq 0x1b50f0 <_Z9Room_Freev+0xac> */
/* @0x1b50c8 ldr r1, [r6] */
/* @0x1b50cc cmp r1, r2 */
/* @0x1b50d0 beq 0x1b50e8 <_Z9Room_Freev+0xa4> */
/* @0x1b50d4 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b50d8 mov r0, r6 */
/* @0x1b50dc bl 0x27d1d0 <_ZdlPv> */
/* @0x1b50e0 ldr r3, [r11, #0x4] */
/* @0x1b50e4 add r3, r3, r7 */
/* @0x1b50e8 str r9, [r3] */
/* @0x1b50ec ldr r5, [r10, #0x4] */
/* @0x1b50f0 ldr r3, [r8] */
/* @0x1b50f4 add r4, r4, #1 */
/* @0x1b50f8 cmp r4, r3 */
/* @0x1b50fc blt 0x1b5094 <_Z9Room_Freev+0x50> */

/* ── 收尾 A（0x1b5100..0x1b5127）：放数组 + 清两格 ──────────────────────
 *   Free(rooms) → [+0x04] = 0（0x1b5108..0x1b5114）→ [+0x00] = 0（0x1b5118..0x1b5124）。
 *   两次都重新取 0x5425d0（模板每次寻址都重算基址），顺序是「先放数组、后清计数」。
 */

/* @0x1b5100 mov r0, r5 */
/* @0x1b5104 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5108 ldr r3, [pc, #0x110] */
/* @0x1b510c mov r2, #0 */
/* @0x1b5110 add r3, pc, r3 */
/* @0x1b5114 str r2, [r3, #0x4] */
/* @0x1b5118 ldr r3, [pc, #0x104] */
/* @0x1b511c mov r2, #0 */
/* @0x1b5120 add r3, pc, r3 */
/* @0x1b5124 str r2, [r3] */

/* ── 顺序表（0x1b5128..0x1b5158）：+0x14 数组 / +0x10 计数，本函数第 5、6 格 ─────────
 *   r4 = [+0x14]；非 0 → Free（0x1b513c）→ [+0x14] = 0（0x1b5144）；
 *   为 0 → 0x1b51e4 的 Free(0) → [+0x14] = 0。
 *   两条路汇合于 0x1b5148，随后 0x1b5158 无条件写 [+0x10] = 0。
 *   这两格是 Room_First/Last/Previous/Next 的唯一读源（0x1b5d10/0x1b5d28/0x1b5d50/0x1b5db0），
 *   在本卡里只有 Free 会动它们；重建只发生在 Room_LoadOrder。
 */

/* @0x1b5128 ldr r5, [pc, #0xf8] */
/* @0x1b512c add r5, pc, r5 */
/* @0x1b5130 ldr r4, [r5, #0x14] */
/* @0x1b5134 subs r0, r4, #0 */
/* @0x1b5138 beq 0x1b51e4 <_Z9Room_Freev+0x1a0> */
/* @0x1b513c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5140 mov r3, #0 */
/* @0x1b5144 str r3, [r5, #0x14] */
/* @0x1b5148 ldr r5, [pc, #0xdc] */
/* @0x1b514c mov r4, #0 */
/* @0x1b5150 add r5, pc, r5 */
/* @0x1b5154 ldr r6, [r5, #0xc] */
/* @0x1b5158 str r4, [r5, #0x10] */

/* ── 名字表（0x1b515c..0x1b51b7）：逐串释放，再放数组 ───────────────────
 *   判空按**指针**（r6 = [+0x0c]，cmp r6,r4），不按计数 —— 与房间表那条按计数的门不同（头部 ①）。
 *   逐串：IsAllocated(names[i]) 为真才 Free（0x1b5184/0x1b5198），与 Room_Load 的 n==0 支同款；
 *   然后把槽写 0（str r7，r7=0）。循环里 r6 被 i*4 覆盖，故每次 bottom（0x1b51b0）都重读 [+0x0c]。
 *   ⇒ **清名字表：是**。串、数组、+0x08/+0x0c 两个计数全清。
 */

/* @0x1b515c cmp r6, r4 */
/* @0x1b5160 beq 0x1b51f0 <_Z9Room_Freev+0x1ac> */
/* @0x1b5164 ldr r3, [r5, #0x8] */
/* @0x1b5168 cmp r3, r4 */
/* @0x1b516c ble 0x1b51b8 <_Z9Room_Freev+0x174> */
/* @0x1b5170 ldr r8, [pc, #0xb8] */
/* @0x1b5174 mov r7, r4 */
/* @0x1b5178 add r8, pc, r8 */
/* @0x1b517c ldr r0, [r6, r4, lsl #2] */
/* @0x1b5180 lsl r6, r4, #2 */
/* @0x1b5184 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b5188 cmp r0, #0 */
/* @0x1b518c beq 0x1b519c <_Z9Room_Freev+0x158> */
/* @0x1b5190 ldr r3, [r8, #0xc] */
/* @0x1b5194 ldr r0, [r3, r4, lsl #2] */
/* @0x1b5198 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b519c ldr r2, [r5, #0x8] */
/* @0x1b51a0 add r4, r4, #1 */
/* @0x1b51a4 ldr r3, [r5, #0xc] */
/* @0x1b51a8 cmp r4, r2 */
/* @0x1b51ac str r7, [r3, r6] */
/* @0x1b51b0 ldr r6, [r5, #0xc] */
/* @0x1b51b4 blt 0x1b517c <_Z9Room_Freev+0x138> */

/* ── 收尾 B（0x1b51b8..0x1b51e0）：放名字数组、清两计数、返回 ──────────────
 *   Free(names) → [+0x0c] = 0 → [+0x08] = 0 → pop（r3 也一起弹出，帧平衡）。
 *   ★ 到这里六格全零：+0x00/+0x04 房间、+0x08/+0x0c 名字、+0x10/+0x14 顺序。
 *     本函数**不碰** room_maxid 0x54255c / room_maxtileid 0x542558（头部 ⑦）。
 */

/* @0x1b51b8 mov r0, r6 */
/* @0x1b51bc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51c0 ldr r3, [pc, #0x6c] */
/* @0x1b51c4 mov r2, #0 */
/* @0x1b51c8 add r3, pc, r3 */
/* @0x1b51cc str r2, [r3, #0xc] */
/* @0x1b51d0 ldr r3, [pc, #0x60] */
/* @0x1b51d4 mov r2, #0 */
/* @0x1b51d8 add r3, pc, r3 */
/* @0x1b51dc str r2, [r3, #0x8] */
/* @0x1b51e0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 三条旁路落点（0x1b51e4..0x1b520c）──────────────────────────────────
 *   0x1b51e4：顺序表为 0 → Free(0) → [+0x14] = 0 → 回 0x1b5148（继续名字表段）
 *   0x1b51f0：名字表为 0 → Free(0) → [+0x0c] = 0 → 回 0x1b51d0（清 +0x08）
 *   0x1b5200：计数非 0 但数组为 0 → Free(0) → [+0x04] = 0 → 回 0x1b5118（清 +0x00）
 *   0x1b520c 是 0x1b5200 的尾跳，回到 0x1b5118 后才顺序落到 0x1b5128。
 */

/* @0x1b51e4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51e8 str r4, [r5, #0x14] */
/* @0x1b51ec b 0x1b5148 <_Z9Room_Freev+0x104> */
/* @0x1b51f0 mov r0, r6 */
/* @0x1b51f4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b51f8 str r6, [r5, #0xc] */
/* @0x1b51fc b 0x1b51d0 <_Z9Room_Freev+0x18c> */
/* @0x1b5200 mov r0, r5 */
/* @0x1b5204 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5208 str r5, [r8, #0x4] */
/* @0x1b520c b 0x1b5118 <_Z9Room_Freev+0xd4> */

/* ── literal pool（0x1b5210..0x1b5238，11 字；非指令）────────────────────
 *   0x1b5210 0x0038d574 + pc 0x1b505c = 0x5425d0   表基址（r8）
 *   0x1b5214 0x002388d0 供 0x1b5058 `ldr r3,[pc,r3]`：0x1b5060 + 0x2388d0 = 0x3ed930（Run_Room 的 GOT 槽）
 *   0x1b5218 0x0038d53c + pc 0x1b5094 = 0x5425d0   （r10，析构循环里重取数组）
 *   0x1b521c 0x0038d538 + pc 0x1b5098 = 0x5425d0   （r11，同上）
 *   0x1b5220 0x0038d4b8 + pc 0x1b5118 = 0x5425d0   （清 +0x04 后清 +0x00）
 *   0x1b5224 0x0038d4a8 + pc 0x1b5128 = 0x5425d0   （同上）
 *   0x1b5228 0x0038d49c + pc 0x1b5134 = 0x5425d0   （顺序表段基址）
 *   0x1b522c 0x0038d478 + pc 0x1b5158 = 0x5425d0   （名字表段基址）
 *   0x1b5230 0x0038d450 + pc 0x1b5180 = 0x5425d0   （取 [+0x0c]）
 *   0x1b5234 0x0038d400 + pc 0x1b51d0 = 0x5425d0   （写 [+0x0c] = 0）
 *   0x1b5238 0x0038d3f0 + pc 0x1b51e0 = 0x5425d0   （写 [+0x08] = 0）
 *   ⇒ 11 个池字里 10 个落 0x5425d0、1 个落 Run_Room 的 GOT 槽；本节不引用任何字符串。
 */

/* @0x1b5210 eorseq sp, r8, r4, ror r5 */
/* @0x1b5214 .word 0x002388d0 */
/* @0x1b5218 eorseq sp, r8, r12, lsr r5 */
/* @0x1b521c eorseq sp, r8, r8, lsr r5 */
/* @0x1b5220 ldrhteq sp, [r8], -r8 */
/* @0x1b5224 eorseq sp, r8, r8, lsr #9 */
/* @0x1b5228 mlaseq r8, r12, r4, sp */
/* @0x1b522c eorseq sp, r8, r8, ror r4 */
/* @0x1b5230 eorseq sp, r8, r0, asr r4 */
/* @0x1b5234 eorseq sp, r8, r0, lsl #8 */
/* @0x1b5238 ldrshteq sp, [r8], -r0 */

/* ── §1 小结 / open ─────────────────────────────────────────────────
 * 小结：Free = 「Run_Room 置空 → 逐 CRoom 析构+delete（三道闸）→ 放房间数组 → 清房间计数 →
 *        放顺序数组 → 清顺序计数 → 逐串 Free 名字 → 放名字数组 → 清名字计数」。
 *        名字表清得干净，房间数组在 count==0 且指针非 0 时会漏（头部 ①）。
 * open 1: 0x1b5068 那条「count==0 就跳」是否在真实退出路径上踩到（Room_Init 之后未 Load 就退出？），
 *         本卡只给形状，不给触发条件。
 * open 2: Run_Room 清 0 的意图（防悬垂指针 / 让 Run_EndGame 看到空房间）未证；FINALIZE_Room_Main 在
 *         Free 之后还把 g_CurrViewSurfaceTexture(0x5428ec) 清 0（0x1b5e64 槽 0x3f0844）。
 * open 3: ~CRoom 0x1afa00 内部是否释放名字 / tile / 层（已另有卡则不重述；本卡只证明调用点）。
 * open 4: room_maxid / room_maxtileid 在 Free 后不复位，是否会让后续 Room_Add 的 id 继续增长 —— 需要
 *         StartRoom/AddInstance 侧的运行期对照（本卡不涉及）。
 * open 5: 0xfeeefeee 的写入者（MemoryManager::Free 的填充策略）未在本卡取证。
 */


/* ══ §2 Room_Add()  0x1b5348..0x1b56dc  size 920  230 条（211 指令 + 19 池字）══════════════════
 * 唯一调用点: F_RoomAdd 0x12e7bc 的 0x12e7cc（GML room_add()；返回值 vcvt.f64.s32 → RValue double）。
 * 帧: push 9 字 + sub sp,#164；snprintf 缓冲 128 B 在 sp+0x1c（0x1c..0x9b），canary 在 sp+0x9c。
 * 寄存器: r6 = 0x5425d0（每段重取）、r8 = &__stack_chk_guard（GOT 0x3ed958，R_ARM_GLOB_DAT）、
 *   r5 = 旧名字计数（本节里同时充当新槽下标与返回值）、r4 = 缓冲/计数临时、
 *   sp+0xc = n+1（此后被 (n+1)*4 覆盖）、sp+0x10 = 新名字串。
 * 源码级步骤（指令序）:
 *   ① snprintf(buf,128,"__newroom%d",[+0x08]) ; YYStrDup(buf)     0x1b5370..0x1b539c
 *   ② ReAlloc(名字表,(n+1)*4,cARRAY_MEMORY.h,92,false) → [+0x0c]  0x1b55f8..0x1b5628
 *   ③ [+0x08] = n+1 ; names[n] = 串                                0x1b5430 / 0x1b5480
 *   ④ new(292) ; CRoom::C2() ; CRoom::CreateWADStorage()           0x1b5488..0x1b5498
 *   ⑤ ReAlloc(房间表,(m+1)*4,cARRAY_CLASS.h,135,false) → [+0x04]   0x1b5648..0x1b5670
 *   ⑥ [+0x00] = m+1 ; rooms[n] = 新 CRoom ; return n               0x1b5594 / 0x1b55e0 / 0x1b55dc
 *   ★ ⑥ 的写入下标是 n（旧**名字**计数），数组长度是 m+1（旧**房间**计数+1）。两计数在库内同值，故重合。
 *
 * ── ① 造名（0x1b5348..0x1b539c）────────────────────────────────────
 *   r5 = [+0x08]（名字计数）→ snprintf 4 号参数；格式串 0x34d39c = "__newroom%d"。
 *   YYStrDup 0xdb8c8 是唯一堆串来源：名字表里存的是这份副本，不是 buf。
 *   0x1b5380 存 canary 到 sp+0x9c；0x1b55e4 读出比对，不等 → 0x1b5690 __stack_chk_fail。
 */

/* @0x1b5348 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b534c sub sp, sp, #164 */
/* @0x1b5350 ldr r6, [pc, #0x33c] */
/* @0x1b5354 add r4, sp, #28 */
/* @0x1b5358 ldr r8, [pc, #0x338] */
/* @0x1b535c mov r1, #128 */
/* @0x1b5360 add r6, pc, r6 */
/* @0x1b5364 ldr r2, [pc, #0x330] */
/* @0x1b5368 ldr r8, [pc, r8] */
/* @0x1b536c mov r0, r4 */
/* @0x1b5370 ldr r5, [r6, #0x8] */
/* @0x1b5374 add r2, pc, r2 */
/* @0x1b5378 ldr r12, [r8] */
/* @0x1b537c mov r3, r5 */
/* @0x1b5380 str r12, [sp, #0x9c] */
/* @0x1b5384 bl 0xb65c8 <snprintf@plt> */
/* @0x1b5388 mov r0, r4 */
/* @0x1b538c bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1b5390 ldr r4, [r6, #0x8] */
/* @0x1b5394 adds r1, r4, #1 */
/* @0x1b5398 str r1, [sp, #0xc] */
/* @0x1b539c str r0, [sp, #0x10] */

/* ── ② 分流：adds r1,r4,#1 的 Z 标志（0x1b53a0）────────────────────────
 *   n+1 != 0 → 0x1b55f8（正常：名字表 ReAlloc）
 *   n+1 == 0（n = -1）→ 0x1b53a4 的零长度清空支（死支 A1）
 *   与 Room_Load 段④的 n==0 支同源：cARRAY_MEMORY::ReAlloc 包装器在 size==0 时「先放干再加」。
 */

/* @0x1b53a0 bne 0x1b55f8 <_Z8Room_Addv+0x2b0> */

/* ── 死支 A1（0x1b53a4..0x1b5404）：n == -1 时的名字表清空 ──────────────
 *   名字表为 0 → 0x1b562c；否则逐串 IsAllocated → Free → 槽写 0（r7 = 0），循环上界 [+0x08]。
 *   ★ 只有 [+0x08] 被写成 -1 才会进来。库内写这一格的只有 Room_Init(0)、Room_Load(n)、Room_Free(0)、
 *     Add/Duplicate(n+1)；本资产 n=114，不可达。
 */

/* @0x1b53a4 ldr r0, [r6, #0xc] */
/* @0x1b53a8 cmp r0, #0 */
/* @0x1b53ac beq 0x1b562c <_Z8Room_Addv+0x2e4> */
/* @0x1b53b0 cmp r4, #0 */
/* @0x1b53b4 ble 0x1b5408 <_Z8Room_Addv+0xc0> */
/* @0x1b53b8 ldr r11, [pc, #0x2e0] */
/* @0x1b53bc mov r9, r6 */
/* @0x1b53c0 mov r10, r1 */
/* @0x1b53c4 mov r7, r1 */
/* @0x1b53c8 add r11, pc, r11 */
/* @0x1b53cc ldr r0, [r0, r10, lsl #2] */
/* @0x1b53d0 lsl r6, r10, #2 */
/* @0x1b53d4 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b53d8 cmp r0, #0 */
/* @0x1b53dc beq 0x1b53ec <_Z8Room_Addv+0xa4> */
/* @0x1b53e0 ldr r3, [r11, #0xc] */
/* @0x1b53e4 ldr r0, [r3, r10, lsl #2] */
/* @0x1b53e8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b53ec ldr r2, [r9, #0x8] */
/* @0x1b53f0 add r10, r10, #1 */
/* @0x1b53f4 ldr r3, [r9, #0xc] */
/* @0x1b53f8 cmp r10, r2 */
/* @0x1b53fc str r7, [r3, r6] */
/* @0x1b5400 ldr r0, [r9, #0xc] */
/* @0x1b5404 blt 0x1b53cc <_Z8Room_Addv+0x84> */

/* ── 0x1b5408..0x1b541c：死支 A1 的尾（Free 名字数组 → [+0x0c] = 0）────
 *   0x1b5420 是死支与活路的汇合点（0x1b5628 的 b 也跳到这里）：随后无条件写 [+0x08] = n+1。
 *   活路此时 r2 = ② 的返回值（0x1b5620 `mov r2,r0`），死支把 r2 置 0（0x1b5418）。
 */

/* @0x1b5408 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b540c ldr r1, [pc, #0x290] */
/* @0x1b5410 mov r3, #0 */
/* @0x1b5414 add r1, pc, r1 */
/* @0x1b5418 mov r2, r3 */
/* @0x1b541c str r3, [r1, #0xc] */
/* @0x1b5420 ldr r3, [pc, #0x280] */
/* @0x1b5424 cmp r5, r4 */
/* @0x1b5428 ldr r1, [sp, #0xc] */
/* @0x1b542c add r3, pc, r3 */
/* @0x1b5430 str r1, [r3, #0x8] */
/* @0x1b5434 bge 0x1b5474 <_Z8Room_Addv+0x12c> */

/* ── 死支 A2（0x1b5438..0x1b5464）：名字表「先移位」段 ──────────────────
 *   条件是 r5 < r4（插入下标 < 元素个数）；本节 r5 = r4 = 旧名字计数 ⇒ 0x1b5434 的 bge 恒跳。
 *   形状：names[j-1] → names[j]，j 从 count 递减到 r5+1（r3 = j*4，每次 -4）。
 */

/* @0x1b5438 ldr r0, [pc, #0x26c] */
/* @0x1b543c lsl r3, r4, #2 */
/* @0x1b5440 add r0, pc, r0 */
/* @0x1b5444 b 0x1b544c <_Z8Room_Addv+0x104> */
/* @0x1b5448 ldr r2, [r0, #0xc] */
/* @0x1b544c add r1, r2, r3 */
/* @0x1b5450 sub r4, r4, #1 */
/* @0x1b5454 cmp r4, r5 */
/* @0x1b5458 ldr r1, [r1, #-0x4] */
/* @0x1b545c str r1, [r2, r3] */
/* @0x1b5460 sub r3, r3, #4 */
/* @0x1b5464 bne 0x1b5448 <_Z8Room_Addv+0x100> */

/* ── ③④ 存名字串、造 CRoom（0x1b5468..0x1b5498）───────────────────────
 *   names[n] = 串（0x1b5480；n = r5 = 旧名字计数）。活路的 r2 是 ② 的新数组，不经 0x1b5470 的重取。
 *   new(292) = CRoom 的 sizeof（与 Room_Load 段⑤、Room_Assign 0x1b5b1c 三处同值）。
 *   ★ CreateWADStorage 0x1a92c0（200 B，50 条）：Alloc(96,"…/Files/Room/Room_Class.cpp",111,true) → [+0xac]，
 *     memset(96,0) → [+0xb0] = 同一块；容器 +0x10 = 30、+0x30 = 88、+0x34 = 92；
 *     再 Alloc(4,…,121,true) → 容器 +0x58、Alloc(4,…,124,true) → 容器 +0x5c（两块各 4 B 零），
 *     并把 [+0xc4] 指向容器 +0x5c 那块。⇒ 新房间有自己的空 tile 容器 + 空原始表。
 *     这一步 Room_Duplicate **没有**（§3 只调 C2）—— 两函数的第一个实质差别。
 */

/* @0x1b5468 ldr r3, [pc, #0x240] */
/* @0x1b546c add r3, pc, r3 */
/* @0x1b5470 ldr r2, [r3, #0xc] */
/* @0x1b5474 ldr r3, [sp, #0x10] */
/* @0x1b5478 mov r0, #292 */
/* @0x1b547c ldr r6, [pc, #0x230] */
/* @0x1b5480 str r3, [r2, r5, lsl #2] */
/* @0x1b5484 add r6, pc, r6 */
/* @0x1b5488 bl 0x27c524 <_Znwj> */
/* @0x1b548c mov r10, r0 */
/* @0x1b5490 bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b5494 mov r0, r10 */
/* @0x1b5498 bl 0x1a92c0 <_ZN5CRoom16CreateWADStorageEv> */

/* ── ⑤ 房间表扩容的分流（0x1b549c..0x1b54b4）───────────────────────────
 *   r4 = [+0x00] 房间计数 m、r0 = [+0x04] 房间表、r9 = m+1。
 *   m+1 != 0 → 0x1b5648（ReAlloc）；m+1 == 0（m = -1）→ 0x1b54ac 死支 A3。
 */

/* @0x1b549c ldr r4, [r6] */
/* @0x1b54a0 ldr r0, [r6, #0x4] */
/* @0x1b54a4 adds r9, r4, #1 */
/* @0x1b54a8 bne 0x1b5648 <_Z8Room_Addv+0x300> */
/* @0x1b54ac cmp r0, #0 */
/* @0x1b54b0 beq 0x1b5674 <_Z8Room_Addv+0x32c> */
/* @0x1b54b4 cmp r4, #0 */

/* ── 死支 A3（0x1b54b8..0x1b556c）：m == -1 时的房间表清空 ──────────────
 *   与 Room_Load 段②逐句同形：闸门 1（array[0] == 0xfeeefeee，数组块已释放）→ 闸门 2（空槽）→
 *   闸门 3（对象首字 == 0xfeeefeee，已删过）→ ~CRoom + operator delete → 槽写 0。
 *   ★ 这是本节唯一出现 CRoom 析构的地方：正常路（只追加）从不析构任何已有房间。
 */

/* @0x1b54b8 ble 0x1b5570 <_Z8Room_Addv+0x228> */
/* @0x1b54bc ldr r1, [pc, #0x1f4] */
/* @0x1b54c0 mov r2, r6 */
/* @0x1b54c4 ldr r12, [pc, #0x1f0] */
/* @0x1b54c8 mov r6, r9 */
/* @0x1b54cc add r1, pc, r1 */
/* @0x1b54d0 str r5, [sp, #0xc] */
/* @0x1b54d4 add r12, pc, r12 */
/* @0x1b54d8 str r4, [sp, #0x10] */
/* @0x1b54dc mov r3, r0 */
/* @0x1b54e0 mov r4, r1 */
/* @0x1b54e4 mov r5, r12 */
/* @0x1b54e8 mov r11, r2 */
/* @0x1b54ec str r8, [sp, #0x14] */
/* @0x1b54f0 ldr r2, [r3] */
/* @0x1b54f4 movw r0, #0xfeee */
/* @0x1b54f8 movt r0, #0xfeee */
/* @0x1b54fc cmp r2, r0 */
/* @0x1b5500 beq 0x1b5550 <_Z8Room_Addv+0x208> */
/* @0x1b5504 ldr r7, [r3, r6, lsl #2] */
/* @0x1b5508 lsl r8, r6, #2 */
/* @0x1b550c add r0, r3, r8 */
/* @0x1b5510 cmp r7, #0 */
/* @0x1b5514 beq 0x1b5550 <_Z8Room_Addv+0x208> */
/* @0x1b5518 ldr lr, [r7] */
/* @0x1b551c movw r3, #0xfeee */
/* @0x1b5520 movt r3, #0xfeee */
/* @0x1b5524 cmp lr, r3 */
/* @0x1b5528 beq 0x1b5544 <_Z8Room_Addv+0x1fc> */
/* @0x1b552c mov r0, r7 */
/* @0x1b5530 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b5534 mov r0, r7 */
/* @0x1b5538 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b553c ldr r0, [r5, #0x4] */
/* @0x1b5540 add r0, r0, r8 */
/* @0x1b5544 mov r1, #0 */
/* @0x1b5548 str r1, [r0] */
/* @0x1b554c ldr r3, [r4, #0x4] */
/* @0x1b5550 ldr r2, [r11] */
/* @0x1b5554 add r6, r6, #1 */
/* @0x1b5558 cmp r6, r2 */
/* @0x1b555c blt 0x1b54f0 <_Z8Room_Addv+0x1a8> */
/* @0x1b5560 ldr r5, [sp, #0xc] */
/* @0x1b5564 mov r0, r3 */
/* @0x1b5568 ldr r4, [sp, #0x10] */
/* @0x1b556c ldr r8, [sp, #0x14] */

/* ── 0x1b5570..0x1b5594：死支 A3 的尾 + 计数落位 ───────────────────────
 *   Free(房间数组) → [+0x04] = 0（0x1b5574..0x1b5584）→ 汇合 0x1b5588；
 *   0x1b5594 `str r9,[r3]` 把 [+0x00] 写成 m+1 —— 两条路都经过这一句。
 */

/* @0x1b5570 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5574 ldr r2, [pc, #0x144] */
/* @0x1b5578 mov r3, #0 */
/* @0x1b557c add r2, pc, r2 */
/* @0x1b5580 mov r1, r3 */
/* @0x1b5584 str r3, [r2, #0x4] */
/* @0x1b5588 ldr r3, [pc, #0x134] */
/* @0x1b558c cmp r5, r4 */
/* @0x1b5590 add r3, pc, r3 */
/* @0x1b5594 str r9, [r3] */

/* ── 死支 A4（0x1b5598..0x1b55d4）：房间表「先移位」段 + 段后重取 ───────
 *   条件 r5 < r4（名字计数 < 房间计数）；同值时 0x1b5598 的 bge 直接跳到 0x1b55d8。
 *   ★ 所以活路**不执行** 0x1b55d4 的 `ldr r1,[r3,#0x4]`：r1 仍是 0x1b5668 `mov r1,r0` 留下的
 *     ReAlloc 返回值（新房间表基址）。死支 A3 里 r1 被 0x1b5580 置 0，走到 0x1b55e0 会成为空指针写。
 */

/* @0x1b5598 bge 0x1b55d8 <_Z8Room_Addv+0x290> */
/* @0x1b559c ldr r0, [pc, #0x124] */
/* @0x1b55a0 lsl r3, r4, #2 */
/* @0x1b55a4 add r0, pc, r0 */
/* @0x1b55a8 b 0x1b55b0 <_Z8Room_Addv+0x268> */
/* @0x1b55ac ldr r1, [r0, #0x4] */
/* @0x1b55b0 add r2, r1, r3 */
/* @0x1b55b4 sub r4, r4, #1 */
/* @0x1b55b8 cmp r4, r5 */
/* @0x1b55bc ldr r2, [r2, #-0x4] */
/* @0x1b55c0 str r2, [r1, r3] */
/* @0x1b55c4 sub r3, r3, #4 */
/* @0x1b55c8 bne 0x1b55ac <_Z8Room_Addv+0x264> */
/* @0x1b55cc ldr r3, [pc, #0xf8] */
/* @0x1b55d0 add r3, pc, r3 */
/* @0x1b55d4 ldr r1, [r3, #0x4] */

/* ── ⑥ 落位与返回（0x1b55d8..0x1b55f4）─────────────────────────────────
 *   rooms[n] = 新 CRoom（r1 = ⑤ 的返回值，见上条）；返回 r5 = 旧名字计数（即新槽下标）。
 *   canary（sp+0x9c）比对失败 → 0x1b5690。
 */

/* @0x1b55d8 ldr r2, [sp, #0x9c] */
/* @0x1b55dc mov r0, r5 */
/* @0x1b55e0 str r10, [r1, r5, lsl #2] */
/* @0x1b55e4 ldr r3, [r8] */
/* @0x1b55e8 cmp r2, r3 */
/* @0x1b55ec bne 0x1b5690 <_Z8Room_Addv+0x348> */
/* @0x1b55f0 add sp, sp, #164 */
/* @0x1b55f4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── ② 名字表 ReAlloc（0x1b55f8..0x1b5628）+ 零长度尾（0x1b562c..0x1b5644）──
 *   ReAlloc([+0x0c], (n+1)*4, "…/Files/Platform/cARRAY_MEMORY.h", 92, false) → [+0x0c]，返回值留 r2；
 *   随后 b 0x1b5420（写 [+0x08]）。
 *   0x1b5604 的 beq 与 0x1b562c 的落点同样只在 (n+1)*4 == 0 时成立（n = -1），死。
 */

/* @0x1b55f8 ldr r3, [sp, #0xc] */
/* @0x1b55fc ldr r0, [r6, #0xc] */
/* @0x1b5600 lsls r1, r3, #2 */
/* @0x1b5604 beq 0x1b562c <_Z8Room_Addv+0x2e4> */
/* @0x1b5608 ldr r2, [pc, #0xc0] */
/* @0x1b560c mov r3, #0 */
/* @0x1b5610 str r3, [sp] */
/* @0x1b5614 mov r3, #92 */
/* @0x1b5618 add r2, pc, r2 */
/* @0x1b561c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5620 mov r2, r0 */
/* @0x1b5624 str r0, [r6, #0xc] */
/* @0x1b5628 b 0x1b5420 <_Z8Room_Addv+0xd8> */
/* @0x1b562c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5630 ldr r1, [pc, #0x9c] */
/* @0x1b5634 mov r3, #0 */
/* @0x1b5638 add r1, pc, r1 */
/* @0x1b563c mov r2, r3 */
/* @0x1b5640 str r3, [r1, #0xc] */
/* @0x1b5644 b 0x1b5420 <_Z8Room_Addv+0xd8> */

/* ── ⑤ 房间表 ReAlloc（0x1b5648..0x1b5670）+ 零长度尾（0x1b5674..0x1b568c）──
 *   ReAlloc([+0x04], (m+1)*4, "…/Files/Platform/cARRAY_CLASS.h", 135, false) → [+0x04]，返回值留 r1；
 *   随后 b 0x1b5588（写 [+0x00]）。
 *   ★ 与 Room_Load 0x1b4fc8/0x1b4fe0 是同一对 (文件,行)：名字表 92 / 房间表 135，池字指向同一处字符串。
 */

/* @0x1b5648 lsls r1, r9, #2 */
/* @0x1b564c beq 0x1b5674 <_Z8Room_Addv+0x32c> */
/* @0x1b5650 ldr r2, [pc, #0x80] */
/* @0x1b5654 mov r3, #0 */
/* @0x1b5658 str r3, [sp] */
/* @0x1b565c mov r3, #135 */
/* @0x1b5660 add r2, pc, r2 */
/* @0x1b5664 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5668 mov r1, r0 */
/* @0x1b566c str r0, [r6, #0x4] */
/* @0x1b5670 b 0x1b5588 <_Z8Room_Addv+0x240> */
/* @0x1b5674 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5678 ldr r2, [pc, #0x5c] */
/* @0x1b567c mov r3, #0 */
/* @0x1b5680 add r2, pc, r2 */
/* @0x1b5684 mov r1, r3 */
/* @0x1b5688 str r3, [r2, #0x4] */
/* @0x1b568c b 0x1b5588 <_Z8Room_Addv+0x240> */

/* ── canary 失败出口（本函数唯一不返回的下行）─────────────────────────
 */

/* @0x1b5690 bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── literal pool（0x1b5694..0x1b56dc，19 字；非指令）──────────────────
 *   0x1b5694 0x0038d268 + pc 0x1b5368 = 0x5425d0   表基址（r6）
 *   0x1b5698 0x002385e8 供 0x1b5368 `ldr r8,[pc,r8]`：0x1b5370 + 0x2385e8 = 0x3ed958（__stack_chk_guard）
 *   0x1b569c 0x00198020 + pc 0x1b537c = 0x34d39c   "__newroom%d"
 *   0x1b56a0 0x0038d200 + pc 0x1b53d0 = 0x5425d0   （死支 A1 取 [+0x0c]）
 *   0x1b56a4 0x0038d1b4 + pc 0x1b541c = 0x5425d0
 *   0x1b56a8 0x0038d19c + pc 0x1b5434 = 0x5425d0
 *   0x1b56ac 0x0038d188 + pc 0x1b5448 = 0x5425d0   （死支 A2 取 [+0x0c]）
 *   0x1b56b0 0x0038d15c + pc 0x1b5474 = 0x5425d0
 *   0x1b56b4 0x0038d144 + pc 0x1b548c = 0x5425d0
 *   0x1b56b8 0x0038d0fc + pc 0x1b54d4 = 0x5425d0   （死支 A3 基址）
 *   0x1b56bc 0x0038d0f4 + pc 0x1b54dc = 0x5425d0   （死支 A3 取 [+0x04]）
 *   0x1b56c0 0x0038d04c + pc 0x1b5584 = 0x5425d0
 *   0x1b56c4 0x0038d038 + pc 0x1b5598 = 0x5425d0
 *   0x1b56c8 0x0038d024 + pc 0x1b55ac = 0x5425d0   （死支 A4 取 [+0x04]）
 *   0x1b56cc 0x0038cff8 + pc 0x1b55d8 = 0x5425d0
 *   0x1b56d0 0x00197d10 + pc 0x1b5620 = 0x34d330   "…/Files/Platform/cARRAY_MEMORY.h"
 *   0x1b56d4 0x0038cf90 + pc 0x1b5640 = 0x5425d0
 *   0x1b56d8 0x00197c90 + pc 0x1b5668 = 0x34d2f8   "…/Files/Platform/cARRAY_CLASS.h"
 *   0x1b56dc 0x0038cf48 + pc 0x1b5688 = 0x5425d0
 *   ⇒ 19 个字里 15 个落 0x5425d0、3 个落字符串（__newroom%d / cARRAY_MEMORY.h / cARRAY_CLASS.h）、
 *     1 个落 __stack_chk_guard 的 GOT 槽。
 */

/* @0x1b5694 eorseq sp, r8, r8, ror #4 */
/* @0x1b5698 eoreq r8, r3, r8, ror #11 */
/* @0x1b569c andseq r8, r9, r0, lsr #32 */
/* @0x1b56a0 eorseq sp, r8, r0, lsl #4 */
/* @0x1b56a4 ldrhteq sp, [r8], -r4 */
/* @0x1b56a8 mlaseq r8, r12, r1, sp */
/* @0x1b56ac eorseq sp, r8, r8, lsl #3 */
/* @0x1b56b0 eorseq sp, r8, r12, asr r1 */
/* @0x1b56b4 eorseq sp, r8, r4, asr #2 */
/* @0x1b56b8 ldrshteq sp, [r8], -r12 */
/* @0x1b56bc ldrshteq sp, [r8], -r4 */
/* @0x1b56c0 eorseq sp, r8, r12, asr #32 */
/* @0x1b56c4 eorseq sp, r8, r8, lsr r0 */
/* @0x1b56c8 eorseq sp, r8, r4, lsr #32 */
/* @0x1b56cc ldrshteq r12, [r8], -r8 */
/* @0x1b56d0 andseq r7, r9, r0, lsl sp */
/* @0x1b56d4 mlaseq r8, r0, pc, r12 */
/* @0x1b56d8 mulseq r9, r0, r12 */
/* @0x1b56dc eorseq r12, r8, r8, asr #30 */
/* ── §2 小结 / open ──────────────────────────────────────────────────
 * 小结：Room_Add = 造名 → 名字表 +1 → 房间表 +1 → new(292)+C2+CreateWADStorage → 返回旧名字计数。
 *   没有失败分支：ReAlloc/new 的行为由 MemoryManager 决定，本函数恒返回一个 int。
 *   两个 ReAlloc 的返回值直接留在 r2/r1 供随后的存储使用；「重取数组」的指令只活在死支里。
 *   本节不碰 +0x10/+0x14（顺序表），也不碰 Run_Room / maxid / maxtileid。
 * open 1: 新房间没有实例、没有 tile、（Add 路径）连 CRoom+0x08 内部名字都是 C2 写的 0，只有
 *         CreateWADStorage 的空容器。GML 侧「room_add() 之后能拿它做什么」（能否 startroom）本卡不证。
 * open 2: rooms 的写入下标取名字计数（0x1b55e0 的 r5 来自 0x1b5370 的 [+0x08]）。两计数同值时无差别；
 *         若被库外拆开，这句会越界。库内没有能把两者写不同值的路径（头部 ④）。
 * open 3: 0xfeeefeee 判据只在死支 A3 出现；正常追加路径从不检查旧指针。
 */


/* ══ §3 Room_Duplicate(int)  0x1b56e0..0x1b5af0  size 1044  261 条（240 指令 + 21 池字）══════
 * 唯一调用点: F_RoomDuplicate 0x12e814；它自己在 0x12e804/0x12e80c 已用 Room_Data(i) 判过一次空，
 *   所以本函数的 -1 返回只在「判空之后到调用之间状态变了」时才可见。
 * 帧: push 9 字 + sub sp,#172；snprintf 缓冲 128 B 在 sp+0x24（0x24..0xa3），canary 在 sp+0xa4，
 *   形参 i 存在 sp+0x14。
 * 寄存器: r4 / r11 都是 0x5425d0（r11 在 0x1b5718 与 0x1b586c 两段各取一次）、
 *   r10 = &__stack_chk_guard、r5 = 旧**房间**计数（新槽下标 + 返回值）、
 *   r11(前段) = 旧名字计数、sp+0xc 先存 n_name+1 后改存 m*4、sp+0x10 先存名字串后改存新 CRoom。
 * 源码级步骤（指令序）:
 *   ① src = Room_Data(i)；src == 0 → return -1                    0x1b56fc..0x1b5704 / 0x1b5a94
 *   ② snprintf(buf,128,"__newroom%d",[+0x00]) ; YYStrDup          0x1b5724..0x1b5734
 *   ③ ReAlloc(名字表,(n_name+1)*4,cARRAY_MEMORY.h,92,false)       0x1b57cc..0x1b57f8
 *   ④ [+0x08] = n_name+1 ; names[m] = 串                          0x1b580c / 0x1b5864
 *   ⑤ new(292) ; CRoom::C2()（**无** CreateWADStorage）             0x1b5868..0x1b5874
 *   ⑥ ReAlloc(房间表,(m+1)*4,cARRAY_CLASS.h,135,false)             0x1b5a30..0x1b5a58
 *   ⑦ [+0x00] = m+1 ; rooms[m] = 新 CRoom ; 新->[+0xd0] = 1       0x1b5968 / 0x1b59b8 / 0x1b59d8
 *   ⑧ 新->Assign(rooms[i], false)                                  0x1b59fc
 *   ⑨ return m                                                     0x1b5a04
 *   ★ ④ 的 names 下标用 m（房间计数），而 ③ 扩的是 n_name+1 格 —— 与 §2 互为镜像（§2 用名字计数索引 rooms）。
 *
 * ── 入口（0x1b56e0..0x1b5704）────────────────────────────────────────
 *   canary → sp+0xa4；sp+0x14 = i；r10 = &__stack_chk_guard。
 *   0x1b56fc bl Room_Data：范围检查（0 <= i < [+0x00]）后返回 rooms[i]，越界与空槽都给 NULL。
 *   NULL → 0x1b5a94 `mvn r5,#0`：返回值 -1，直接过 canary 返回 —— 此时一次分配都没发生。
 */

/* @0x1b56e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b56e4 sub sp, sp, #172 */
/* @0x1b56e8 ldr r10, [pc, #0x3b0] */
/* @0x1b56ec str r0, [sp, #0x14] */
/* @0x1b56f0 ldr r10, [pc, r10] */
/* @0x1b56f4 ldr r3, [r10] */
/* @0x1b56f8 str r3, [sp, #0xa4] */
/* @0x1b56fc bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1b5700 cmp r0, #0 */
/* @0x1b5704 beq 0x1b5a94 <_Z14Room_Duplicatei+0x3b4> */

/* ── ② 造名（0x1b5708..0x1b5748）───────────────────────────────────────
 *   r5 = [+0x00]（**房间**计数）→ snprintf 4 号参数（§2 用的是 [+0x08] 名字计数）。
 *   格式串同样 0x34d39c = "__newroom%d"；YYStrDup 后 sp+0x10 = 串。
 *   r11 = [+0x08] 名字计数；sp+0xc = n_name+1；0x1b5748 bne 0x1b57cc（正常路）。
 */

/* @0x1b5708 ldr r4, [pc, #0x394] */
/* @0x1b570c add r6, sp, #36 */
/* @0x1b5710 ldr r2, [pc, #0x390] */
/* @0x1b5714 mov r1, #128 */
/* @0x1b5718 add r4, pc, r4 */
/* @0x1b571c mov r0, r6 */
/* @0x1b5720 add r2, pc, r2 */
/* @0x1b5724 ldr r5, [r4] */
/* @0x1b5728 mov r3, r5 */
/* @0x1b572c bl 0xb65c8 <snprintf@plt> */
/* @0x1b5730 mov r0, r6 */
/* @0x1b5734 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1b5738 ldr r11, [r4, #0x8] */
/* @0x1b573c adds r1, r11, #1 */
/* @0x1b5740 str r1, [sp, #0xc] */
/* @0x1b5744 str r0, [sp, #0x10] */
/* @0x1b5748 bne 0x1b57cc <_Z14Room_Duplicatei+0xec> */

/* ── 死支 B1（0x1b574c..0x1b57a8）：n_name == -1 时的名字表清空 ─────────
 *   与 §2 的 A1 逐句同形：IsAllocated → Free → 槽写 0（r6 = 槽值 0、r7 = 下标）。
 */

/* @0x1b574c ldr r0, [r4, #0xc] */
/* @0x1b5750 cmp r0, #0 */
/* @0x1b5754 beq 0x1b5a78 <_Z14Room_Duplicatei+0x398> */
/* @0x1b5758 cmp r11, #0 */
/* @0x1b575c ble 0x1b57b0 <_Z14Room_Duplicatei+0xd0> */
/* @0x1b5760 ldr r9, [pc, #0x344] */
/* @0x1b5764 mov r8, r4 */
/* @0x1b5768 mov r7, r1 */
/* @0x1b576c mov r6, r1 */
/* @0x1b5770 add r9, pc, r9 */
/* @0x1b5774 ldr r0, [r0, r7, lsl #2] */
/* @0x1b5778 lsl r4, r7, #2 */
/* @0x1b577c bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b5780 cmp r0, #0 */
/* @0x1b5784 beq 0x1b5794 <_Z14Room_Duplicatei+0xb4> */
/* @0x1b5788 ldr r3, [r9, #0xc] */
/* @0x1b578c ldr r0, [r3, r7, lsl #2] */
/* @0x1b5790 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5794 ldr r2, [r8, #0x8] */
/* @0x1b5798 add r7, r7, #1 */
/* @0x1b579c ldr r3, [r8, #0xc] */
/* @0x1b57a0 cmp r7, r2 */
/* @0x1b57a4 str r6, [r3, r4] */
/* @0x1b57a8 ldr r0, [r8, #0xc] */
/* @0x1b57ac blt 0x1b5774 <_Z14Room_Duplicatei+0x94> */

/* ── 0x1b57b0..0x1b57c8：死支 B1 的尾（Free 名字数组 → [+0x0c] = 0 → 0x1b57fc）──
 *   活路从 0x1b57cc 进来，两路在 0x1b57fc 汇合；活路 r2 = 0x1b57f4 `mov r2,r0`（新名字表）。
 */

/* @0x1b57b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b57b4 ldr r1, [pc, #0x2f4] */
/* @0x1b57b8 mov r3, #0 */
/* @0x1b57bc add r1, pc, r1 */
/* @0x1b57c0 mov r2, r3 */
/* @0x1b57c4 str r3, [r1, #0xc] */
/* @0x1b57c8 b 0x1b57fc <_Z14Room_Duplicatei+0x11c> */

/* ── ③ 名字表 ReAlloc（0x1b57cc..0x1b57f8）─────────────────────────────
 *   ReAlloc([+0x0c], (n_name+1)*4, "…/Files/Platform/cARRAY_MEMORY.h", 92, false) → [+0x0c]，返回值留 r2。
 *   0x1b57d8 的 beq 与 0x1b5a78 的零长度尾都只在 n_name == -1 时可达（死）。
 */

/* @0x1b57cc ldr r2, [sp, #0xc] */
/* @0x1b57d0 ldr r0, [r4, #0xc] */
/* @0x1b57d4 lsls r1, r2, #2 */
/* @0x1b57d8 beq 0x1b5a78 <_Z14Room_Duplicatei+0x398> */
/* @0x1b57dc ldr r2, [pc, #0x2d0] */
/* @0x1b57e0 mov r3, #0 */
/* @0x1b57e4 str r3, [sp] */
/* @0x1b57e8 mov r3, #92 */
/* @0x1b57ec add r2, pc, r2 */
/* @0x1b57f0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b57f4 mov r2, r0 */
/* @0x1b57f8 str r0, [r4, #0xc] */

/* ── ④ 名字计数落位（0x1b57fc..0x1b5810）───────────────────────────────
 *   [+0x08] = n_name+1（0x1b580c）。
 *   0x1b5800 `cmp r5,r11`（房间计数 vs 名字计数）是移位支的门；同值 → 0x1b5810 bge 跳过。
 */

/* @0x1b57fc ldr r3, [pc, #0x2b4] */
/* @0x1b5800 cmp r5, r11 */
/* @0x1b5804 ldr r1, [sp, #0xc] */
/* @0x1b5808 add r3, pc, r3 */
/* @0x1b580c str r1, [r3, #0x8] */
/* @0x1b5810 bge 0x1b5850 <_Z14Room_Duplicatei+0x170> */

/* ── 死支 B2（0x1b5814..0x1b5840）：名字表「先移位」段 ─────────────────
 *   仅当 r5(房间计数) < r11(名字计数) 时执行：names[j-1] → names[j]。
 */

/* @0x1b5814 ldr r0, [pc, #0x2a0] */
/* @0x1b5818 lsl r3, r11, #2 */
/* @0x1b581c add r0, pc, r0 */
/* @0x1b5820 b 0x1b5828 <_Z14Room_Duplicatei+0x148> */
/* @0x1b5824 ldr r2, [r0, #0xc] */
/* @0x1b5828 add r1, r2, r3 */
/* @0x1b582c sub r11, r11, #1 */
/* @0x1b5830 cmp r11, r5 */
/* @0x1b5834 ldr r1, [r1, #-0x4] */
/* @0x1b5838 str r1, [r2, r3] */
/* @0x1b583c sub r3, r3, #4 */
/* @0x1b5840 bne 0x1b5824 <_Z14Room_Duplicatei+0x144> */

/* ── 0x1b5844..0x1b584c：移位段之后的「重取名字表」（死支 B2 专用）─────
 *   活路跳过这句，直接用 ③ 的返回值（r2）。
 */

/* @0x1b5844 ldr r3, [pc, #0x274] */
/* @0x1b5848 add r3, pc, r3 */
/* @0x1b584c ldr r2, [r3, #0xc] */

/* ── ④⑤ names[m] = 串；new(292) + C2（无 CreateWADStorage）────────────
 *   0x1b5858 `lsl r1,r5,#2` 把「房间计数*4」写进 sp+0xc（**覆盖**原来的 n_name+1）。
 *   0x1b5864 names[m] = 串（m = 旧房间计数，r2 = ③ 的返回值）；
 *   0x1b5868 new(292)；0x1b5874 CRoom::C2()；0x1b5870 把对象指针存进 sp+0x10（覆盖串指针）。
 *   ★ 与 §2 的差别：这里**没有** CreateWADStorage ⇒ 新房间的 +0xac/+0xb0/+0xc4 全靠 Assign 建
 *     （+0xd0 = 1 ⇒ Assign 段7 走深建 96 B 容器，见 CRoom_Assign 卡）。
 */

/* @0x1b5850 ldr r3, [sp, #0x10] */
/* @0x1b5854 mov r0, #292 */
/* @0x1b5858 lsl r1, r5, #2 */
/* @0x1b585c str r1, [sp, #0xc] */
/* @0x1b5860 ldr r11, [pc, #0x25c] */
/* @0x1b5864 str r3, [r2, r5, lsl #2] */
/* @0x1b5868 bl 0x27c524 <_Znwj> */
/* @0x1b586c add r11, pc, r11 */
/* @0x1b5870 str r0, [sp, #0x10] */
/* @0x1b5874 bl 0x1ad2cc <_ZN5CRoomC2Ev> */

/* ── ⑥ 房间表扩容分流（0x1b5878..0x1b5884）─────────────────────────────
 *   r4 = [+0x00] m、r0 = [+0x04]、r9 = m+1；m+1 != 0 → 0x1b5a30（ReAlloc），否则 0x1b5888 死支 B3。
 */

/* @0x1b5878 ldr r4, [r11] */
/* @0x1b587c ldr r0, [r11, #0x4] */
/* @0x1b5880 adds r9, r4, #1 */
/* @0x1b5884 bne 0x1b5a30 <_Z14Room_Duplicatei+0x350> */

/* ── 死支 B3（0x1b5888..0x1b5934）：m == -1 时的房间表清空 ──────────────
 *   与 §2 的 A3 同形（三道 0xfeeefeee/空槽闸门 + ~CRoom + operator delete + 槽写 0），
 *   循环体因上界为 -1 而直接跳过；0x1b5904 前后的 str r2,[sp,#8] 是移位段寄存器的临时保存。
 *   ★ 这是 §3 唯一出现 CRoom 析构的地方。
 */

/* @0x1b5888 cmp r0, #0 */
/* @0x1b588c beq 0x1b5a5c <_Z14Room_Duplicatei+0x37c> */
/* @0x1b5890 cmp r4, #0 */
/* @0x1b5894 ble 0x1b5944 <_Z14Room_Duplicatei+0x264> */
/* @0x1b5898 ldr r1, [pc, #0x228] */
/* @0x1b589c mov r6, r9 */
/* @0x1b58a0 ldr r12, [pc, #0x224] */
/* @0x1b58a4 mov r2, r9 */
/* @0x1b58a8 add r1, pc, r1 */
/* @0x1b58ac str r4, [sp, #0x1c] */
/* @0x1b58b0 add r12, pc, r12 */
/* @0x1b58b4 mov r3, r0 */
/* @0x1b58b8 mov r8, r1 */
/* @0x1b58bc str r5, [sp, #0x18] */
/* @0x1b58c0 mov r4, r12 */
/* @0x1b58c4 ldr r1, [r3] */
/* @0x1b58c8 movw r0, #0xfeee */
/* @0x1b58cc movt r0, #0xfeee */
/* @0x1b58d0 cmp r1, r0 */
/* @0x1b58d4 beq 0x1b5928 <_Z14Room_Duplicatei+0x248> */
/* @0x1b58d8 ldr r7, [r3, r6, lsl #2] */
/* @0x1b58dc lsl r5, r6, #2 */
/* @0x1b58e0 add r0, r3, r5 */
/* @0x1b58e4 cmp r7, #0 */
/* @0x1b58e8 beq 0x1b5928 <_Z14Room_Duplicatei+0x248> */
/* @0x1b58ec ldr lr, [r7] */
/* @0x1b58f0 movw r3, #0xfeee */
/* @0x1b58f4 movt r3, #0xfeee */
/* @0x1b58f8 cmp lr, r3 */
/* @0x1b58fc beq 0x1b5920 <_Z14Room_Duplicatei+0x240> */
/* @0x1b5900 mov r0, r7 */
/* @0x1b5904 str r2, [sp, #0x8] */
/* @0x1b5908 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b590c mov r0, r7 */
/* @0x1b5910 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b5914 ldr r0, [r4, #0x4] */
/* @0x1b5918 ldr r2, [sp, #0x8] */
/* @0x1b591c add r0, r0, r5 */
/* @0x1b5920 str r2, [r0] */
/* @0x1b5924 ldr r3, [r8, #0x4] */
/* @0x1b5928 ldr r1, [r11] */
/* @0x1b592c add r6, r6, #1 */
/* @0x1b5930 cmp r6, r1 */
/* @0x1b5934 blt 0x1b58c4 <_Z14Room_Duplicatei+0x1e4> */
/* @0x1b5938 ldr r5, [sp, #0x18] */
/* @0x1b593c mov r0, r3 */
/* @0x1b5940 ldr r4, [sp, #0x1c] */

/* ── 0x1b5944..0x1b5968：死支 B3 的尾 + 房间计数落位 ───────────────────
 *   Free(房间数组) → [+0x04] = 0 → 0x1b5968 `str r9,[r3]` 写 [+0x00] = m+1（两路都过）。
 */

/* @0x1b5944 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5948 ldr r1, [pc, #0x180] */
/* @0x1b594c mov r3, #0 */
/* @0x1b5950 add r1, pc, r1 */
/* @0x1b5954 mov r2, r3 */
/* @0x1b5958 str r3, [r1, #0x4] */
/* @0x1b595c ldr r3, [pc, #0x170] */
/* @0x1b5960 cmp r5, r4 */
/* @0x1b5964 add r3, pc, r3 */
/* @0x1b5968 str r9, [r3] */
/* @0x1b596c bge 0x1b59ac <_Z14Room_Duplicatei+0x2cc> */

/* ── 死支 B4（0x1b5970..0x1b599c）：房间表「先移位」段 ─────────────────
 *   条件 r5 < r4（此处 r4 = 旧房间计数、r5 同值）⇒ 不可达；0x1b59a0..0x1b59ac 是段后重取。
 */

/* @0x1b5970 ldr r0, [pc, #0x160] */
/* @0x1b5974 lsl r3, r4, #2 */
/* @0x1b5978 add r0, pc, r0 */
/* @0x1b597c b 0x1b5984 <_Z14Room_Duplicatei+0x2a4> */
/* @0x1b5980 ldr r2, [r0, #0x4] */
/* @0x1b5984 add r1, r2, r3 */
/* @0x1b5988 sub r4, r4, #1 */
/* @0x1b598c cmp r4, r5 */
/* @0x1b5990 ldr r1, [r1, #-0x4] */
/* @0x1b5994 str r1, [r2, r3] */
/* @0x1b5998 sub r3, r3, #4 */
/* @0x1b599c bne 0x1b5980 <_Z14Room_Duplicatei+0x2a0> */

/* ── 0x1b59a0..0x1b59ac：移位段后的重取（死支 B4 专用）──────────────────
 *   活路的 r2 来自 0x1b5a50 `mov r2,r0`（ReAlloc 返回值）。
 */

/* @0x1b59a0 ldr r3, [pc, #0x134] */
/* @0x1b59a4 add r3, pc, r3 */
/* @0x1b59a8 ldr r2, [r3, #0x4] */

/* ── ⑦ 落位：rooms[m] = 新 CRoom；新->[+0xd0] = 1（本卡头号发现）───────
 *   0x1b59b4 r3 = sp+0xc = m*4；0x1b59b8 rooms[m] = 新 CRoom（r1 = sp+0x10）。
 *   0x1b59bc `cmp r5,r9`（m vs m+1）恒不成立 ⇒ 顺序落到 0x1b59c0：
 *   0x1b59d4 r0 = rooms[m]（重取一次，不信任 r1）；0x1b59d8 `strb r3,[r0,#0xd0]`（r3 = 1）。
 *   ★ 全 .text 里 `strb <r>, [<r>, #0xd0]` 只有三条：CRoom::C2 0x1ad4e4（写 0）、本节 0x1b59d8（写 1）、
 *     0x1b5a28（写 1，死支 B5，r3 = 0 → 写绝对地址 0xd0）。
 *     ⇒ CRoom_Assign 卡里「+0xd0 的置位者未在已索引函数中出现」的答案就是这一条：
 *       复制房间时把新房间标成「深建 tile 容器」，于是 Assign 段7 不浅共享。
 */

/* @0x1b59ac ldr r1, [sp, #0x10] */
/* @0x1b59b0 cmp r5, r9 */
/* @0x1b59b4 ldr r3, [sp, #0xc] */
/* @0x1b59b8 str r1, [r2, r3] */
/* @0x1b59bc bge 0x1b5a1c <_Z14Room_Duplicatei+0x33c> */
/* @0x1b59c0 ldr r2, [pc, #0x118] */
/* @0x1b59c4 mov r3, #1 */
/* @0x1b59c8 ldr r1, [sp, #0xc] */
/* @0x1b59cc add r2, pc, r2 */
/* @0x1b59d0 ldr r2, [r2, #0x4] */
/* @0x1b59d4 ldr r0, [r2, r1] */
/* @0x1b59d8 strb r3, [r0, #0xd0] */

/* ── ⑧⑨ Assign + 返回（0x1b59dc..0x1b5a18）─────────────────────────────
 *   界判用的是**新**计数 r9 = m+1：i < m+1 取 rooms[i]，否则 src = 0。
 *   （入口 0x1b56fc 已用 Room_Data 判过 i < m，正常路径这里必取到非空 src；src 是加表之后重读的。）
 *   CRoom::Assign(r0 = 新房间, r1 = src, r2 = 0)：bRebuild = false ⇒ 不重建实例、不重建 RTile 表；
 *   加上新房间 +0xd0 = 1（深建容器、且跳过 RTile 直拷）⇒ **复制品不带源房间的实例与 tile**。
 *   返回 r5 = 旧房间计数（新房间下标）；canary 失败 → 0x1b5a9c。
 */

/* @0x1b59dc ldr r2, [sp, #0x14] */
/* @0x1b59e0 cmp r2, r9 */
/* @0x1b59e4 movge r1, #0 */
/* @0x1b59e8 ldrlt r3, [pc, #0xf4] */
/* @0x1b59ec addlt r3, pc, r3 */
/* @0x1b59f0 ldrlt r3, [r3, #0x4] */
/* @0x1b59f4 ldrlt r1, [r3, r2, lsl #2] */
/* @0x1b59f8 mov r2, #0 */
/* @0x1b59fc bl 0x1ad70c <_ZN5CRoom6AssignEPS_b> */
/* @0x1b5a00 ldr r2, [sp, #0xa4] */
/* @0x1b5a04 mov r0, r5 */
/* @0x1b5a08 ldr r3, [r10] */
/* @0x1b5a0c cmp r2, r3 */
/* @0x1b5a10 bne 0x1b5a9c <_Z14Room_Duplicatei+0x3bc> */
/* @0x1b5a14 add sp, sp, #172 */
/* @0x1b5a18 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 死支 B5（0x1b5a1c..0x1b5a2c）─────────────────────────────────────
 *   只在 0x1b59bc 的 bge 成立（m >= m+1，不可能）时进入：r3 = 0，随后 `strb r2,[r3,#0xd0]`
 *   = 向绝对地址 0x000000d0 写 1 —— 若可达必崩。这是 cARRAY::Add 模板「插入下标 == 计数」尾形的残骸。
 */

/* @0x1b5a1c mov r3, #0 */
/* @0x1b5a20 mov r2, #1 */
/* @0x1b5a24 mov r0, r3 */
/* @0x1b5a28 strb r2, [r3, #0xd0] */
/* @0x1b5a2c b 0x1b59dc <_Z14Room_Duplicatei+0x2fc> */

/* ── ⑥ 房间表 ReAlloc（0x1b5a30..0x1b5a58）─────────────────────────────
 *   ReAlloc([+0x04], (m+1)*4, "…/Files/Platform/cARRAY_CLASS.h", 135, false) → [+0x04]，返回值留 r2。
 *   0x1b5a34 的 beq 与 0x1b5a5c 的零长度尾只在 m == -1 时可达（死）。
 */

/* @0x1b5a30 lsls r1, r9, #2 */
/* @0x1b5a34 beq 0x1b5a5c <_Z14Room_Duplicatei+0x37c> */
/* @0x1b5a38 ldr r2, [pc, #0xa8] */
/* @0x1b5a3c mov r3, #0 */
/* @0x1b5a40 str r3, [sp] */
/* @0x1b5a44 mov r3, #135 */
/* @0x1b5a48 add r2, pc, r2 */
/* @0x1b5a4c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b5a50 mov r2, r0 */
/* @0x1b5a54 str r0, [r11, #0x4] */
/* @0x1b5a58 b 0x1b595c <_Z14Room_Duplicatei+0x27c> */

/* ── 0x1b5a5c..0x1b5a74：房间表空时 Free(0) → [+0x04] = 0（死支 B3 尾）──
 */

/* @0x1b5a5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5a60 ldr r1, [pc, #0x84] */
/* @0x1b5a64 mov r3, #0 */
/* @0x1b5a68 add r1, pc, r1 */
/* @0x1b5a6c mov r2, r3 */
/* @0x1b5a70 str r3, [r1, #0x4] */
/* @0x1b5a74 b 0x1b595c <_Z14Room_Duplicatei+0x27c> */

/* ── 0x1b5a78..0x1b5a90：名字表空时 Free(0) → [+0x0c] = 0（死支 B1 尾）──
 */

/* @0x1b5a78 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b5a7c ldr r1, [pc, #0x6c] */
/* @0x1b5a80 mov r3, #0 */
/* @0x1b5a84 add r1, pc, r1 */
/* @0x1b5a88 mov r2, r3 */
/* @0x1b5a8c str r3, [r1, #0xc] */
/* @0x1b5a90 b 0x1b57fc <_Z14Room_Duplicatei+0x11c> */

/* ── 入口①的 -1 出口：mvn r5,#0 → 与正常出口共用 canary 检查与 pop ──────
 */

/* @0x1b5a94 mvn r5, #0 */
/* @0x1b5a98 b 0x1b5a00 <_Z14Room_Duplicatei+0x320> */

/* ── canary 失败出口 ────────────────────────────────────────────────
 */

/* @0x1b5a9c bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── literal pool（0x1b5aa0..0x1b5af0，21 字；非指令）──────────────────
 *   0x1b5aa0 0x00238260 供 0x1b56f0 `ldr r10,[pc,r10]`：0x1b56f8 + 0x238260 = 0x3ed958（__stack_chk_guard）
 *   0x1b5aa4 0x0038ceb0 + pc 0x1b5720 = 0x5425d0   表基址（r4）
 *   0x1b5aa8 0x00197c74 + pc 0x1b5728 = 0x34d39c   "__newroom%d"
 *   0x1b5aac 0x0038ce58 + pc 0x1b5778 = 0x5425d0   （死支 B1 取 [+0x0c]）
 *   0x1b5ab0 0x0038ce0c + pc 0x1b57c4 = 0x5425d0
 *   0x1b5ab4 0x00197b3c + pc 0x1b57f4 = 0x34d330   "…/Files/Platform/cARRAY_MEMORY.h"
 *   0x1b5ab8 0x0038cdc0 + pc 0x1b5810 = 0x5425d0
 *   0x1b5abc 0x0038cdac + pc 0x1b5824 = 0x5425d0   （死支 B2 取 [+0x0c]）
 *   0x1b5ac0 0x0038cd80 + pc 0x1b5850 = 0x5425d0
 *   0x1b5ac4 0x0038cd5c + pc 0x1b5874 = 0x5425d0
 *   0x1b5ac8 0x0038cd20 + pc 0x1b58b0 = 0x5425d0   （死支 B3 基址）
 *   0x1b5acc 0x0038cd18 + pc 0x1b58b8 = 0x5425d0   （死支 B3 取 [+0x04]）
 *   0x1b5ad0 0x0038cc78 + pc 0x1b5958 = 0x5425d0
 *   0x1b5ad4 0x0038cc64 + pc 0x1b596c = 0x5425d0
 *   0x1b5ad8 0x0038cc50 + pc 0x1b5980 = 0x5425d0   （死支 B4 取 [+0x04]）
 *   0x1b5adc 0x0038cc24 + pc 0x1b59ac = 0x5425d0
 *   0x1b5ae0 0x0038cbfc + pc 0x1b59d4 = 0x5425d0
 *   0x1b5ae4 0x0038cbdc 供 0x1b59e8 `ldrlt r3,[pc,#0xf4]`：0x1b59f4 + 0x38cbdc = 0x5425d0（取 [+0x04]）
 *   0x1b5ae8 0x001978a8 + pc 0x1b5a50 = 0x34d2f8   "…/Files/Platform/cARRAY_CLASS.h"
 *   0x1b5aec 0x0038cb60 + pc 0x1b5a70 = 0x5425d0
 *   0x1b5af0 0x0038cb44 + pc 0x1b5a8c = 0x5425d0
 *   ⇒ 21 个字里 17 个落 0x5425d0、3 个落字符串、1 个落 __stack_chk_guard 的 GOT 槽。
 */

/* @0x1b5aa0 eoreq r8, r3, r0, ror #4 */
/* @0x1b5aa4 ldrhteq r12, [r8], -r0 */
/* @0x1b5aa8 andseq r7, r9, r4, ror r12 */
/* @0x1b5aac eorseq r12, r8, r8, asr lr */
/* @0x1b5ab0 eorseq r12, r8, r12, lsl #28 */
/* @0x1b5ab4 andseq r7, r9, r12, lsr r11 */
/* @0x1b5ab8 eorseq r12, r8, r0, asr #27 */
/* @0x1b5abc eorseq r12, r8, r12, lsr #27 */
/* @0x1b5ac0 eorseq r12, r8, r0, lsl #27 */
/* @0x1b5ac4 eorseq r12, r8, r12, asr sp */
/* @0x1b5ac8 eorseq r12, r8, r0, lsr #26 */
/* @0x1b5acc eorseq r12, r8, r8, lsl sp */
/* @0x1b5ad0 eorseq r12, r8, r8, ror r12 */
/* @0x1b5ad4 eorseq r12, r8, r4, ror #24 */
/* @0x1b5ad8 eorseq r12, r8, r0, asr r12 */
/* @0x1b5adc eorseq r12, r8, r4, lsr #24 */
/* @0x1b5ae0 ldrshteq r12, [r8], -r12 */
/* @0x1b5ae4 ldrsbteq r12, [r8], -r12 */
/* @0x1b5ae8 andseq r7, r9, r8, lsr #17 */
/* @0x1b5aec eorseq r12, r8, r0, ror #22 */
/* @0x1b5af0 eorseq r12, r8, r4, asr #22 */
/* ── §3 小结 / open ──────────────────────────────────────────────────
 * 小结：Room_Duplicate(i) = 「取 src（空则 -1）→ 造名 → 名字表 +1 → 房间表 +1 → new+C2 →
 *   +0xd0 = 1 → Assign(src, false) → 返回 m」。它与 §2 共用同一段模板，差别是名字编号的计数源、
 *   不调 CreateWADStorage、以及最后那次 +0xd0 置位 + Assign。
 * open 1: bRebuild = false 且 +0xd0 = 1 ⇒ 实例与 tile 都不进复制品（这是按 CRoom_Assign 卡段7/段8 的分支
 *         条件推的，本卡只证明两个实参的值；运行期对照未做）。
 * open 2: names 的写入下标用房间计数（0x1b5864 的 r5 来自 0x1b5724 的 [+0x00]），扩表用的是名字计数+1；
 *         两计数同值时无差别，拆开就错位（镜像于 §2 open 2）。
 * open 3: -1 返回在 F_RoomDuplicate 里被自己的 Room_Data 判空挡在前面（0x12e80c），正常路径拿不到 -1；
 *         本函数为何仍保留这条出口（防御性 / 原版另有调用者）未证。
 */

