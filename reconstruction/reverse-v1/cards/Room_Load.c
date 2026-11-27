/* cally 逆向卡：Room_Load（原版 libyoyo.so，armv7）
 * @func 0x1b4cd8 0x1b5044  size 876  219 条（0x1b4ffc..0x1b5040 为 literal pool，18 字；objdump 当指令译，实为数据）
 * 级别: 正文（三组平行表的建立顺序、两条释放路径、逐房间 new(292) → CRoom::CRoom → LoadFromChunk → 名字复制
 *             全部逐条钉住；并与 Room_Number 0x1b523c / Room_Data 0x1b52c4 / Room_Find 0x1b524c / Room_Name 0x1b530c /
 *             Room_First 0x1b5d08 / Room_Last 0x1b5d20 / Room_Previous 0x1b5d40 / Room_Next 0x1b5da4 /
 *             Room_LoadOrder 0x1b5ba0 / CRoom::LoadFromChunk 0x1aea3c / LoadGameData 0x1de638 交叉印证，
 *             并用 assets/game.droid 的 ROOM 块实测数据核过；
 *             未钉：param1 的语义（函数体从不读）、off==0 与名字偏移==0 两种空值的运行期后果、被覆盖的旧 CRoom 是否有别的持有者）
 * 符号: _Z9Room_LoadPhjS_ → bool Room_Load(uchar* pRoomList, unsigned int size, uchar* pWAD)
 * ABI : softfp；返回 bool，但**唯一出口恒 true**（0x1b4fbc mov r0, #1）
 * 同层: Room_LoadOrder 0x1b5ba0（同一 24 B 全局块的 +0x10/+0x14 两格）、CRoom::CRoom 0x1ad2cc、
 *       CRoom::LoadFromChunk 0x1aea3c、CRoom::~CRoom 0x1afa00、operator new 0x27c524 / operator delete 0x27d1d0、
 *       MemoryManager::Alloc 0x27ce78 / ReAlloc 0x27cedc / Free 0x27c2d0 / IsAllocated 0x27c454、
 *       strlen@plt 0xb6538 / strcpy@plt 0xb65a4、LoadGameData 0x1de638（唯一调用者）
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把 ROOM 块的「房间清单」铺成三组平行全局表：按清单里的 WAD 偏移逐块 new(292) + CRoom::CRoom() +
 *   CRoom::LoadFromChunk(YYRoom*, pWAD)，再给每个房间复制一份自己的名字串。清单里偏移为 0 = 空槽，
 *   两个数组同时写 NULL。全程没有失败分支，返回恒 true。
 *
 * ── 全局房间表：.bss 0x5425d0，24 B，六格（本卡的核心）────────────────
 *   +0x00  int       room 计数          本函数写（resize 段末尾 0x1b4de4）
 *   +0x04  CRoom**   CRoom* 数组        本函数写（ReAlloc 0x1b4fe0 / Free 0x1b4dd4）
 *   +0x08  int       名字计数（= room 计数，同步写）0x1b4e84
 *   +0x0c  char**    名字串数组         本函数写（ReAlloc 0x1b4f94 / Free 0x1b4fac）
 *   +0x10  int       顺序表计数         Room_LoadOrder 写
 *   +0x14  int*      顺序表             Room_LoadOrder 写
 *   ★ 这六格没有任何导出符号名：它夹在 g_roomExtents（0x5425c0，size 0x10，恰好到 0x5425d0）与
 *     CLayerManager::m_ForcedDepth（0x5425e8）之间，.dynsym 里前后两个符号正好把它框成 0x18 字节。
 *     本函数 14 处、Room_LoadOrder 5 处、Room_Add/Duplicate/Free/Assign/Data/Find/Name/First/Last/Next/Previous
 *     共 70 处 pc 相对引用都落在这个基址上（全库按 ldr/add 对扫出的直接引用表）。
 *   ★ 对照：0x542990 不是房间表，它是**导出符号 Run_Room_List**（size 8，紧接 Run_Room 0x54298c），
 *     由 Run_EndGame 读；Room_Load / Room_LoadOrder 都不碰它（本函数 18 个字面量里 14 个指向 0x5425d0、3 个是文件名串、1 个是 GOT 偏移）。
 *
 * ── 参数与三处全局 ────────────────────────────────────────────────
 *   param0 = ROOM 块里「计数 + 偏移数组」的头：+0x00 = count、+0x04 起 count 个 uint32 WAD 偏移。
 *            实测 assets/game.droid：count = 114，offs[0] = 0x73c10（与 apk/identity.md 的 114 ROOM 一致）。
 *   param1 = size：**全函数从不读**（r1 只被当临时寄存器重写）。签名里的这个参数是编译期遗留。
 *   param2 = pWAD：只做一件事 —— 0x1b4ed8 原样当第 3 参传给 CRoom::LoadFromChunk。
 *   求 YYRoom* 用的是另一个全局：g_pWADBaseAddress（.bss 0x544c44，导出符号），
 *     0x1b4eac 经 GOT 槽 0x3ed94c 取到它（Object_Load / Background_Load / Extension_Load 等 *_Load 同款）。
 *   文件名字符串：Alloc 用 ".../Files/Room/Room_Main.cpp" 行 170；ReAlloc 数组用 cARRAY_CLASS.h 行 135；
 *     ReAlloc 名字表用 cARRAY_MEMORY.h 行 92。
 *
 * ── 建立顺序（五段，次序即语义）────────────────────────────────────
 *   ① 计数比较：n = pRoomList[0]；n == g_count 就整段跳过 resize（0x1b4cfc → 0x1b4df0）。
 *   ② 旧房间释放：**只有 n == 0 且数组非 0 才进**（0x1b4d00/0x1b4d0c 两道门）：
 *      逐条跳过 0xfeeefeee（已删标记）→ ~CRoom() + operator delete → Free(数组) → 数组 = 0。
 *   ③ 数组 resize：n != 0 → ReAlloc(旧数组, n*4)（cARRAY_CLASS.h:135）；n == 0 → Free(旧数组)。
 *      随后 g_count = n（0x1b4de4，两条路都汇到这里）。
 *   ④ 名字表 resize：n != 0 → ReAlloc(名字表, n*4)（cARRAY_MEMORY.h:92）；
 *      n == 0 → 逐条 IsAllocated 后 Free 每个串 + Free(名字表) + 置 0。
 *      随后 名字计数 = n（0x1b4e84）；n == 0 直接 return true。
 *   ⑤ 逐房间装配（i = 0..n-1）：off = offs[i]
 *        off == 0 或 g_pWADBaseAddress+off == 0 → rooms[i] = NULL、名字[i] = NULL（不 new、不 Alloc）
 *        否则 new(292) → CRoom::CRoom() → LoadFromChunk(room, wad+off, pWAD)
 *          nameOff = *(int*)(wad+off)   ← YYRoom+0x00
 *          name = nameOff ? wad+nameOff : NULL
 *          Alloc(strlen(name)+1, Room_Main.cpp:170) + strcpy → 名字[i]
 *        存之前先 Free 名字[i] 的旧串（0x1b4f2c），rooms[i] 直接覆盖（不析构）。
 *
 * ── 两处结构性缺陷（本卡实证，不是推测）───────────────────────────
 *   1. 旧 CRoom 只在 n == 0 时被析构。n != 0 时（计数变或不变）0x1b4fe0 的 ReAlloc 会把旧指针
 *      原样搬过来，随后 0x1b4f40 逐格覆盖 ⇒ 旧 CRoom 对象与其内部资源全部泄漏。
 *      名字表**不**这样：每个槽存之前都 Free（0x1b4f2c）——两张表不对称。
 *   2. nameOff == 0 时 r11 被写成 0 后直接 strlen（0x1b4eec → 0x1b4ef8），即 strlen(NULL)。
 *      本资产 114 个房间的 YYRoom+0x00 都非 0（实测 "rm_town" / "rm_level1"），所以没踩到。
 *
 * ── 实测锚点（assets/game.droid）──────────────────────────────────
 *   ROOM 块 0x73a3c："ROOM" + "Lg1\0" + count(114) + 114 个 uint32 偏移；offs 由 0x73c10 起。
 *   第一间 YYRoom：+0x00 = 0x4f7677 → 串 "rm_town"；+0x04 = 0x4f1001 → 空串；
 *                  +0x08 = 1024（宽）、+0x0c = 576（高）、+0x10 = 30（speed）。
 *   ⇒ 名字表里存的是 GML 的 room 名（"rm_town"），所以 Room_Find 能按名字 strcmp、Room_Name 能返回它。
 *
 * ── 未定（open）──────────────────────────────────────────────────
 *   1. param1 为什么存在（所有 *_Load 都带同一个 size，都被各自函数忽略/部分忽略）。
 *   2. 旧 CRoom 被覆盖时是否有别处还持有（StartRoom / Run_Room_List 的持有关系未在本卡证明）。
 *   3. 0xfeeefeee 判据只用在 n == 0 的释放路径；谁会把 CRoom* 写成这个值未在本卡证明（AddInstance 侧同款判据）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 装载：入口 ──────────────────────────────────────────────────
 *   帧：push {r4-r11,lr} + sub sp,#28（28 B：sp+0xc 存 param0、sp+0x10 存 param2、sp+0x14 存文件名串）
 *   r8 = param0、r9 = pRoomList[0] = n、r6 = 全局表基址 0x5425d0、r5/r7 = 0（0 常量）、r4/r10/r11 = 游标
 */


/* ── 段①：计数比较与分支选择 ──────────────────────────────────────
 *   r2 = g_room_count；n == g_room_count → 0x1b4df0（**整段 resize 跳过**，旧房间不析构）
 *   n != 0 → 0x1b4dc8（ReAlloc）；n == 0 且数组 != 0 → 0x1b4d14（逐条析构）；n == 0 且数组 == 0 → 0x1b4dc8（Free(0)）
 */

/* @0x1b4cd8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1b4cdc sub sp, sp, #28 */
/* @0x1b4ce0 ldr r6, [pc, #0x314] */
/* @0x1b4ce4 mov r8, r0 */
/* @0x1b4ce8 ldr r9, [r0] */
/* @0x1b4cec add r6, pc, r6 */
/* @0x1b4cf0 str r2, [sp, #0x10] */
/* @0x1b4cf4 ldr r2, [r6] */
/* @0x1b4cf8 cmp r9, r2 */
/* @0x1b4cfc beq 0x1b4df0 <_Z9Room_LoadPhjS_+0x118> */
/* @0x1b4d00 cmp r9, #0 */
/* @0x1b4d04 ldr r3, [r6, #0x4] */
/* @0x1b4d08 bne 0x1b4dc8 <_Z9Room_LoadPhjS_+0xf0> */
/* @0x1b4d0c cmp r3, #0 */
/* @0x1b4d10 beq 0x1b4dc8 <_Z9Room_LoadPhjS_+0xf0> */

/* ── 段②：旧房间析构循环（只有 n == 0 才走）────────────────────────
 *   r9 此时是 0，r4 是循环下标、r11 = i*4、r7 = 0；0xfeee/0xfeee 是 GameMaker 的「已释放」标记。
 *   注意 store 在 0x1b4d90：先 ~CRoom + operator delete，再把数组该格清 0（末尾统一 Free 整块）。
 */

/* @0x1b4d14 cmp r2, #0 */
/* @0x1b4d18 ble 0x1b4dac <_Z9Room_LoadPhjS_+0xd4> */
/* @0x1b4d1c ldr r12, [pc, #0x2dc] */
/* @0x1b4d20 mov r4, r9 */
/* @0x1b4d24 ldr r10, [pc, #0x2d8] */
/* @0x1b4d28 mov r7, r9 */
/* @0x1b4d2c add r12, pc, r12 */
/* @0x1b4d30 str r0, [sp, #0xc] */
/* @0x1b4d34 add r10, pc, r10 */
/* @0x1b4d38 mov r8, r12 */
/* @0x1b4d3c ldr r0, [r3] */
/* @0x1b4d40 movw r2, #0xfeee */
/* @0x1b4d44 movt r2, #0xfeee */
/* @0x1b4d48 movw r1, #0xfeee */
/* @0x1b4d4c cmp r0, r2 */
/* @0x1b4d50 movt r1, #0xfeee */
/* @0x1b4d54 lsl r11, r4, #2 */
/* @0x1b4d58 beq 0x1b4d98 <_Z9Room_LoadPhjS_+0xc0> */
/* @0x1b4d5c ldr r5, [r3, r4, lsl #2] */
/* @0x1b4d60 add r2, r3, r11 */
/* @0x1b4d64 cmp r5, #0 */
/* @0x1b4d68 mov r0, r5 */
/* @0x1b4d6c beq 0x1b4d98 <_Z9Room_LoadPhjS_+0xc0> */
/* @0x1b4d70 ldr r3, [r5] */
/* @0x1b4d74 cmp r3, r1 */
/* @0x1b4d78 beq 0x1b4d90 <_Z9Room_LoadPhjS_+0xb8> */
/* @0x1b4d7c bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1b4d80 mov r0, r5 */
/* @0x1b4d84 bl 0x27d1d0 <_ZdlPv> */
/* @0x1b4d88 ldr r2, [r8, #0x4] */
/* @0x1b4d8c add r2, r2, r11 */
/* @0x1b4d90 str r7, [r2] */
/* @0x1b4d94 ldr r3, [r10, #0x4] */
/* @0x1b4d98 ldr r2, [r6] */
/* @0x1b4d9c add r4, r4, #1 */
/* @0x1b4da0 cmp r4, r2 */
/* @0x1b4da4 blt 0x1b4d3c <_Z9Room_LoadPhjS_+0x64> */
/* @0x1b4da8 ldr r8, [sp, #0xc] */
/* @0x1b4dac mov r0, r3 */
/* @0x1b4db0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4db4 ldr r3, [pc, #0x24c] */
/* @0x1b4db8 mov r2, #0 */
/* @0x1b4dbc add r3, pc, r3 */
/* @0x1b4dc0 str r2, [r3, #0x4] */
/* @0x1b4dc4 b 0x1b4de4 <_Z9Room_LoadPhjS_+0x10c> */

/* ── 段③：数组 resize 与计数落位 ──────────────────────────────────
 *   0x1b4dc8 是 ReAlloc 分支（n != 0）：r4 = n*4；0x1b4fc8 里 ReAlloc(旧数组, n*4, cARRAY_CLASS.h, 135, true)。
 *   0x1b4dd4 是 n == 0 的收尾：Free(旧数组) 后数组格写 r4(=0)。
 *   0x1b4de4 两条路汇合：g_room_count = n。
 */

/* @0x1b4dc8 lsls r4, r9, #2 */
/* @0x1b4dcc mov r0, r3 */
/* @0x1b4dd0 bne 0x1b4fc8 <_Z9Room_LoadPhjS_+0x2f0> */
/* @0x1b4dd4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4dd8 ldr r3, [pc, #0x22c] */
/* @0x1b4ddc add r3, pc, r3 */
/* @0x1b4de0 str r4, [r3, #0x4] */
/* @0x1b4de4 ldr r3, [pc, #0x224] */
/* @0x1b4de8 add r3, pc, r3 */
/* @0x1b4dec str r9, [r3] */

/* ── 段④：名字表 resize（0x1b4df0..0x1b4e74）─────────────────────
 *   n == 0：名字表非空则逐条 IsAllocated → Free 串 → 清格，最后 Free 整块并置 0；
 *   n != 0：0x1b4f68 起读旧表 → 0x1b4f74 判断 n*4，走 0x1b4f7c 的 ReAlloc(cARRAY_MEMORY.h, 92)。
 *   0x1b4e84 把 n 同时写进 +0x08（名字计数），所以 8 与 0 两格永远相等。
 */

/* @0x1b4df0 cmp r9, #0 */
/* @0x1b4df4 bne 0x1b4f68 <_Z9Room_LoadPhjS_+0x290> */
/* @0x1b4df8 ldr r5, [pc, #0x214] */
/* @0x1b4dfc add r5, pc, r5 */
/* @0x1b4e00 ldr r0, [r5, #0xc] */
/* @0x1b4e04 cmp r0, #0 */
/* @0x1b4e08 beq 0x1b4f74 <_Z9Room_LoadPhjS_+0x29c> */
/* @0x1b4e0c ldr r3, [r5, #0x8] */
/* @0x1b4e10 cmp r3, #0 */
/* @0x1b4e14 ble 0x1b4e64 <_Z9Room_LoadPhjS_+0x18c> */
/* @0x1b4e18 ldr r7, [pc, #0x1f8] */
/* @0x1b4e1c mov r4, r9 */
/* @0x1b4e20 mov r6, r9 */
/* @0x1b4e24 add r7, pc, r7 */
/* @0x1b4e28 ldr r0, [r0, r4, lsl #2] */
/* @0x1b4e2c lsl r10, r4, #2 */
/* @0x1b4e30 bl 0x27c454 <_ZN13MemoryManager11IsAllocatedEPKv> */
/* @0x1b4e34 cmp r0, #0 */
/* @0x1b4e38 beq 0x1b4e48 <_Z9Room_LoadPhjS_+0x170> */
/* @0x1b4e3c ldr r3, [r7, #0xc] */
/* @0x1b4e40 ldr r0, [r3, r4, lsl #2] */
/* @0x1b4e44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4e48 ldr r2, [r5, #0x8] */
/* @0x1b4e4c add r4, r4, #1 */
/* @0x1b4e50 ldr r3, [r5, #0xc] */
/* @0x1b4e54 cmp r4, r2 */
/* @0x1b4e58 str r6, [r3, r10] */
/* @0x1b4e5c ldr r0, [r5, #0xc] */
/* @0x1b4e60 blt 0x1b4e28 <_Z9Room_LoadPhjS_+0x150> */
/* @0x1b4e64 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4e68 ldr r3, [pc, #0x1ac] */
/* @0x1b4e6c mov r2, #0 */
/* @0x1b4e70 add r3, pc, r3 */
/* @0x1b4e74 str r2, [r3, #0xc] */

/* ── 段⑤ 入口（0x1b4e78..0x1b4ea4）：装配前的一次性 setup ─────────
 *   r10 = 表基址、[+0x08] = n、r7 = 表基址、r4 = 0、[sp+0xc] = n、[sp+0x14] = 文件名串，然后跳进循环头。
 *   r8 从 param0+4 起每轮 +4（`ldr r5,[r8,#0x4]!` 就是「读下一个偏移并推进」）。
 *   r11 = g_pWADBaseAddress（GOT 槽 0x3ed94c → .bss 0x544c44），r1 = wad + off 即 YYRoom*。
 *   off == 0 → 0x1b4f60 把 r6(room) 与 r5(name) 都置 0，跳到 0x1b4f1c 的空槽收尾。
 *   off != 0 → new(292) / CRoom::CRoom / LoadFromChunk；再读 YYRoom+0x00 当名字偏移做 Alloc+strcpy。
 *   ★ LoadFromChunk 拿到的第 3 参是 param2（本函数原样透传），与上面求 YYRoom* 用的全局不是同一个来源。
 */

/* @0x1b4e78 ldr r10, [pc, #0x1a0] */
/* @0x1b4e7c cmp r9, #0 */
/* @0x1b4e80 add r10, pc, r10 */
/* @0x1b4e84 str r9, [r10, #0x8] */
/* @0x1b4e88 beq 0x1b4fbc <_Z9Room_LoadPhjS_+0x2e4> */
/* @0x1b4e8c ldr r3, [pc, #0x190] */
/* @0x1b4e90 mov r7, r10 */
/* @0x1b4e94 mov r4, #0 */
/* @0x1b4e98 str r9, [sp, #0xc] */
/* @0x1b4e9c add r3, pc, r3 */
/* @0x1b4ea0 str r3, [sp, #0x14] */
/* @0x1b4ea4 b 0x1b4f54 <_Z9Room_LoadPhjS_+0x27c> */

/* ── 循环体（0x1b4ea8..0x1b4f50）：三件事 —— 判空、装配、落位 ────────
 *   0x1b4eb4 adds r1, r11, r5（wad + off）；为 0 走 0x1b4ff4 退化。
 *   0x1b4ebc mov r0,#292 → operator new → 0x1b4ecc CRoom::CRoom() → 0x1b4edc LoadFromChunk(r6, wad+off, pWAD)。
 *   0x1b4ee0 ldr r12,[r11, r5] 读的是 YYRoom+0x00（名字偏移）；0x1b4ee8 ldrne r3,[r9] 再取一次 g_pWADBaseAddress。
 *   nameOff == 0 → 0x1b4eec moveq r11, r12（r11 = 0）→ 0x1b4ef8 strlen(0)（潜在崩点，见头部缺陷 2）。
 *   0x1b4ef8..0x1b4f18：strlen → +1 → Alloc(…, Room_Main.cpp, 170, true) → strcpy。
 *   0x1b4f1c..0x1b4f30：名字[i] 非 0 就先 Free（**不做 IsAllocated 判断**，与 0x1b4e30 那条路不同）。
 */

/* @0x1b4ea8 ldr r9, [pc, #0x178] */
/* @0x1b4eac ldr r9, [pc, r9] */
/* @0x1b4eb0 ldr r11, [r9] */
/* @0x1b4eb4 adds r1, r11, r5 */
/* @0x1b4eb8 beq 0x1b4ff4 <_Z9Room_LoadPhjS_+0x31c> */
/* @0x1b4ebc mov r0, #292 */
/* @0x1b4ec0 str r1, [sp, #0x8] */
/* @0x1b4ec4 bl 0x27c524 <_Znwj> */
/* @0x1b4ec8 mov r6, r0 */
/* @0x1b4ecc bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1b4ed0 ldr r1, [sp, #0x8] */
/* @0x1b4ed4 mov r0, r6 */
/* @0x1b4ed8 ldr r2, [sp, #0x10] */
/* @0x1b4edc bl 0x1aea3c <_ZN5CRoom13LoadFromChunkEP6YYRoomPh> */
/* @0x1b4ee0 ldr r12, [r11, r5] */
/* @0x1b4ee4 cmp r12, #0 */
/* @0x1b4ee8 ldrne r3, [r9] */
/* @0x1b4eec moveq r11, r12 */
/* @0x1b4ef0 addne r11, r3, r12 */
/* @0x1b4ef4 mov r0, r11 */
/* @0x1b4ef8 bl 0xb6538 <strlen@plt> */
/* @0x1b4efc ldr r1, [sp, #0x14] */
/* @0x1b4f00 mov r3, #1 */
/* @0x1b4f04 mov r2, #170 */
/* @0x1b4f08 add r0, r0, r3 */
/* @0x1b4f0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1b4f10 mov r1, r11 */
/* @0x1b4f14 mov r5, r0 */
/* @0x1b4f18 bl 0xb65a4 <strcpy@plt> */
/* @0x1b4f1c ldr r2, [r10, #0xc] */
/* @0x1b4f20 lsl r11, r4, #2 */
/* @0x1b4f24 ldr r0, [r2, r4, lsl #2] */
/* @0x1b4f28 cmp r0, #0 */
/* @0x1b4f2c beq 0x1b4f34 <_Z9Room_LoadPhjS_+0x25c> */
/* @0x1b4f30 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4f34 ldr r2, [r7, #0x4] */
/* @0x1b4f38 add r4, r4, #1 */
/* @0x1b4f3c ldr r3, [sp, #0xc] */
/* @0x1b4f40 str r6, [r2, r11] */
/* @0x1b4f44 cmp r4, r3 */
/* @0x1b4f48 ldr r2, [r7, #0xc] */
/* @0x1b4f4c str r5, [r2, r11] */
/* @0x1b4f50 beq 0x1b4fbc <_Z9Room_LoadPhjS_+0x2e4> */

/* ── 循环头（0x1b4f54..0x1b4f64）：读下一个偏移并推进游标 ──────────
 *   `ldr r5,[r8,#0x4]!` = r8 += 4; r5 = offs[i]。r5 == 0 → r6 = 0，直接跳到 0x1b4f1c 写空槽。
 *   这是本函数唯一「空槽」判定点：off == 0 既不 new 也不 Alloc，两个数组都写 NULL。
 */

/* @0x1b4f54 ldr r5, [r8, #0x4]! */
/* @0x1b4f58 cmp r5, #0 */
/* @0x1b4f5c bne 0x1b4ea8 <_Z9Room_LoadPhjS_+0x1d0> */
/* @0x1b4f60 mov r6, r5 */
/* @0x1b4f64 b 0x1b4f1c <_Z9Room_LoadPhjS_+0x244> */

/* ── 名字表的第二个入口（0x1b4f68..0x1b4f74）与空表收尾（0x1b4fa8）──
 *   n != 0：0x1b4f68 取旧名字表 → 0x1b4f74 判 n*4 → 0x1b4f7c ReAlloc(…, cARRAY_MEMORY.h, 92, true)。
 *   n == 0 且旧表非空：0x1b4f74 的 r4 = 0 → beq 0x1b4fa8 → Free(旧表) → 格写 0 → 回 0x1b4e78。
 *   注意 0x1b4f8c/0x1b4f94 用的是 r2（文件名串），本函数三个 ReAlloc 各用不同 .h，不能互换。
 */

/* @0x1b4f68 ldr r3, [pc, #0xbc] */
/* @0x1b4f6c add r3, pc, r3 */
/* @0x1b4f70 ldr r0, [r3, #0xc] */
/* @0x1b4f74 lsls r4, r9, #2 */
/* @0x1b4f78 beq 0x1b4fa8 <_Z9Room_LoadPhjS_+0x2d0> */
/* @0x1b4f7c ldr r2, [pc, #0xac] */
/* @0x1b4f80 mov r3, #0 */
/* @0x1b4f84 mov r1, r4 */
/* @0x1b4f88 str r3, [sp] */
/* @0x1b4f8c add r2, pc, r2 */
/* @0x1b4f90 mov r3, #92 */
/* @0x1b4f94 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b4f98 ldr r3, [pc, #0x94] */
/* @0x1b4f9c add r3, pc, r3 */
/* @0x1b4fa0 str r0, [r3, #0xc] */
/* @0x1b4fa4 b 0x1b4e78 <_Z9Room_LoadPhjS_+0x1a0> */
/* @0x1b4fa8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1b4fac ldr r3, [pc, #0x84] */
/* @0x1b4fb0 add r3, pc, r3 */
/* @0x1b4fb4 str r4, [r3, #0xc] */
/* @0x1b4fb8 b 0x1b4e78 <_Z9Room_LoadPhjS_+0x1a0> */

/* ── 出口与两条分支落点（0x1b4fbc..0x1b4ff8）──────────────────────
 *   0x1b4fbc mov r0,#1 → 收栈返回：**无论装了几个房间、有没有跳过，都返回 true**。
 *   0x1b4fc8 = ReAlloc 房间数组（r2 = cARRAY_CLASS.h 串，r3 = 135）；0x1b4fdc 直接 str r0,[base+4]。
 *   0x1b4ff4 = wad+off == 0 的退化路：r5 = r1 = 0，之后与空槽同路。
 */

/* @0x1b4fbc mov r0, #1 */
/* @0x1b4fc0 add sp, sp, #28 */
/* @0x1b4fc4 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x1b4fc8 ldr r2, [pc, #0x6c] */
/* @0x1b4fcc mov r3, #0 */
/* @0x1b4fd0 mov r1, r4 */
/* @0x1b4fd4 str r3, [sp] */
/* @0x1b4fd8 add r2, pc, r2 */
/* @0x1b4fdc mov r3, #135 */
/* @0x1b4fe0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1b4fe4 ldr r3, [pc, #0x54] */
/* @0x1b4fe8 add r3, pc, r3 */
/* @0x1b4fec str r0, [r3, #0x4] */
/* @0x1b4ff0 b 0x1b4de4 <_Z9Room_LoadPhjS_+0x10c> */
/* @0x1b4ff4 mov r5, r1 */
/* @0x1b4ff8 b 0x1b4f60 <_Z9Room_LoadPhjS_+0x288> */

/* ── literal pool（0x1b4ffc..0x1b5040，18 字；非指令）──────────────
 *   0x1b4ffc 0x0038d8dc + pc 0x1b4cf4 = 0x5425d0  全局表基址（r6）
 *   0x1b5000 0x0038d89c + pc 0x1b4d34 = 0x5425d0  （r12，析构循环里重取数组）
 *   0x1b5004 0x0038d894 + pc 0x1b4d3c = 0x5425d0  （r10，同上）
 *   0x1b5008 0x0038d80c + pc 0x1b4dc4 = 0x5425d0  （数组格清零）
 *   0x1b500c 0x0038d7ec + pc 0x1b4de4 = 0x5425d0  （同上）
 *   0x1b5010 0x0038d7e0 + pc 0x1b4df0 = 0x5425d0  （写 count）
 *   0x1b5014 0x0038d7cc + pc 0x1b4e04 = 0x5425d0  （名字表基址，r5）
 *   0x1b5018 0x0038d7a4 + pc 0x1b4e2c = 0x5425d0  （r7，名字循环里取数组）
 *   0x1b501c 0x0038d758 + pc 0x1b4e78 = 0x5425d0  （r3，Free 后回填）
 *   0x1b5020 0x0038d748 + pc 0x1b4e88 = 0x5425d0  （r10，装配段基址）
 *   0x1b5024 0x001984c4 + pc 0x1b4ea4 = 0x34d368  ".../Files/Room/Room_Main.cpp"
 *   0x1b5028 0x00238a98 供 `ldr r9,[pc,r9]` @0x1b4eac：0x1b4eb4 + 0x238a98 = 0x3ed94c（GOT 槽）
 *            → [0x3ed94c] = 0x544c44 = g_pWADBaseAddress
 *   0x1b502c 0x0038d65c + pc 0x1b4f74 = 0x5425d0
 *   0x1b5030 0x0019839c + pc 0x1b4f94 = 0x34d330  ".../Platform/cARRAY_MEMORY.h"
 *   0x1b5034 0x0038d62c + pc 0x1b4fa4 = 0x5425d0
 *   0x1b5038 0x0038d618 + pc 0x1b4fb8 = 0x5425d0
 *   0x1b503c 0x00198318 + pc 0x1b4fe0 = 0x34d2f8  ".../Platform/cARRAY_CLASS.h"
 *   0x1b5040 0x0038d5e0 + pc 0x1b4ff0 = 0x5425d0
 */

/* @0x1b4ffc ldrsbteq sp, [r8], -r12 */
/* @0x1b5000 mlaseq r8, r12, r8, sp */
/* @0x1b5004 mlaseq r8, r4, r8, sp */
/* @0x1b5008 eorseq sp, r8, r12, lsl #16 */
/* @0x1b500c eorseq sp, r8, r12, ror #15 */
/* @0x1b5010 eorseq sp, r8, r0, ror #15 */
/* @0x1b5014 eorseq sp, r8, r12, asr #15 */
/* @0x1b5018 eorseq sp, r8, r4, lsr #15 */
/* @0x1b501c eorseq sp, r8, r8, asr r7 */
/* @0x1b5020 eorseq sp, r8, r8, asr #14 */
/* @0x1b5024 andseq r8, r9, r4, asr #9 */
/* @0x1b5028 mlaeq r3, r8, r10, r8 */
/* @0x1b502c eorseq sp, r8, r12, asr r6 */
/* @0x1b5030 mulseq r9, r12, r3 */
/* @0x1b5034 eorseq sp, r8, r12, lsr #12 */
/* @0x1b5038 eorseq sp, r8, r8, lsl r6 */
/* @0x1b503c andseq r8, r9, r8, lsl r3 */
/* @0x1b5040 eorseq sp, r8, r0, ror #11 */
