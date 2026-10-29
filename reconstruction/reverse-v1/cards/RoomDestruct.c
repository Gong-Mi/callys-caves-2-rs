/* cally 逆向卡：CRoom 析构与清扫族（原版 libyoyo.so，armv7）—— 一卡 22 节
 * @card 0x001a92c0 .. 0x001afee8（22 个函数 / 1443 条锚点（1419 指令 + 24 池字），地址各只出现一次）
 *       覆盖面：functions.tsv 里 CRoom:: 开头的方法共 37 个；本卡收 22 个未出卡的，其余 15 个已在
 *       CRoom_ctor / Assign / Serialise / DeSerialise / LoadFromStream / LoadFromChunk / UpdateActive /
 *       AddInstance（5 个）/ AddTile（2 个）/ CollisionUpdate_Room（UpdateLayers）里出卡
 *       ⇒ 22 + 15 = 37，无重叠、无缺口（按 @func 首地址比对）。
 * @func 0x1afa00 0x1afef0  size 1264  316 条  §1  CRoom::~CRoom()                 （314 指令 + 2 池字）
 * @func 0x1abb24 0x1abd9c  size 632  158 条  §2  CRoom::RemoveMarked()           （152 + 6）
 * @func 0x1ad0a4 0x1ad2cc  size 552  138 条  §3  CRoom::Clear()                  （134 + 4）
 * @func 0x1ab798 0x1ab9d4  size 572  143 条  §4  CRoom::ClearInstances()          （135 + 5）
 * @func 0x1ab9c8 0x1abae0  size 280  70 条  §5  CRoom::ClearDeactiveInstances()  （66 + 1）
 * @func 0x1ad060 0x1ad0b0  size 80  20 条  §6  CRoom::ClearTiles()
 * @func 0x1ab104 0x1ab144  size 64  16 条  §7  CRoom::ClearStorageTiles()       （14 + 1）
 * @func 0x1ab140 0x1ab144  size 4  1 条  §8  CRoom::ClearStorageInstances()   （bx lr）
 * @func 0x1abad4 0x1abb30  size 92  23 条  §9  CRoom::CleanPersistent()
 * @func 0x1ac200 0x1ac240  size 64  16 条  §10 CRoom::ScrollBackground()
 * @func 0x1af2bc 0x1af368  size 172  43 条  §11 CRoom::FindTile(int)
 * @func 0x1af35c 0x1af400  size 164  41 条  §12 CRoom::DeleteTile(int)
 * @func 0x1af3f4 0x1af590  size 412  103 条  §13 CRoom::SortTiles()
 * @func 0x1af584 0x1af5d0  size 76  19 条  §14 CRoom::HideTilesDepth(float)
 * @func 0x1af5c4 0x1af610  size 76  19 条  §15 CRoom::ShowTilesDepth(float)
 * @func 0x1af604 0x1af6d4  size 208  52 条  §16 CRoom::DeleteTilesDepth(float)
 * @func 0x1af6c8 0x1af738  size 112  28 条  §17 CRoom::ShiftTilesDepth(float,float,float)
 * @func 0x1af72c 0x1af86c  size 320  80 条  §18 CRoom::FindTileAtDepth(float,float,float)（76 + 1）
 * @func 0x1af860 0x1af9c8  size 360  90 条  §19 CRoom::DeleteTilesAtDepth(float,float,float)
 * @func 0x1af9bc 0x1afa0c  size 80  20 条  §20 CRoom::ChangeTilesDepth(float,float)
 * @func 0x1a92c0 0x1a9394  size 212  53 条  §21 CRoom::CreateWADStorage()        （49 + 1）
 * @func 0x1a9388 0x1a9428  size 160  40 条  §22 CRoom::Debug()                   （37 + 3）
 * 级别: 正文（22 节 1443/1443 逐条落锚。析构的十段顺序与全部落空分支、RemoveMarked 的五全局/三闸门/
 *       两链摘除、Clear 的 8 背景 + 8 视野 + 三桶数组、两条实例清扫、七条 tile 表操作全部逐条钉死；
 *       未钉：事件号 12 的官方名、三张哈希图节点的释放点、tile 记录 +0x14/+0x18/+0x24/+0x28 的字段名、
 *       +0xac 容器不被释放是否原版有意为之（逐节 open 单列）tier = bytecode_anchored）
 * 符号: _ZN5CRoomD2Ev / _ZN5CRoomD1Ev 0x1afa00（同址两别名，本卡只发一次锚点）、_ZN5CRoom12RemoveMarkedEv、
 *       _ZN5CRoom5ClearEv … 全部取自 asm/functions.tsv 第 4535..4577 行区间与 .dynsym（st_size 直读）。
 * ABI : softfp；本族全体是 this 调用（r0 = CRoom*），无返回值（FindTile/FindTileAtDepth 例外：返回 int）。
 * 锚表: 22 张按函数切分的索引由 scripts/asm_index.py 从同一 libyoyo.so 现生成（--start <首> --end <末+4>），
 *       行数与 asm/functions.tsv 的指令数列逐节相等：1443 = 1443。★ 本卡的索引**不在 asm/ 里**（本卡只写
 *       cards/RoomDestruct.c 与 claims-batchBY.jsonl），生成物落在 scratch：
 *         .hermes/cache/scratch/roomdestruct/<mangled>.tsv（22 个）+ index-RoomDestruct_all.tsv（拼接版）
 *       复现（入库版）示例：python3 scripts/asm_index.py --so libyoyo.so --start 0x1afa00
 *         --end 0x1afef0 --out asm/index-CRoom_dtor.tsv   # end 取「末条+4」，含 2 个池字
 *       合并校验（本次实跑）: python3 scripts/check_card_anchors.py --card cards/RoomDestruct.c
 *         --index <scratch>/index-RoomDestruct_all.tsv → index=1443 card=1443 missing=0 extra=0
 *         mismatch=0 RESULT EXACT；全库口径 scripts/verify_reverse_v1.py → RoomDestruct 正文 1443 EXACT。
 * 同层: CRoom::CRoom 0x1ad2cc（对象布局与初值，见 CRoom_ctor 卡）、CRoom::Assign 0x1ad70c、
 *       CRoom::AddTile 0x1ac240 / AddTileToStorage 0x1aaf78（tile 表的两条生产者）、
 *       CRoom::AddInstance 家族 0x1aadac..0x1ab794、CLayerManager::CleanRoomLayers 0x1b93c8 /
 *       RemoveInstance 0x1b9e5c、CInstance::ms_ID2InstanceE 0x536f28、CInstance::ms_markedCount 0x536d7c、
 *       CPhysicsWorld::~CPhysicsWorld 0x239e68、MemoryInWad 0x1aad50、Perform_Event 0xf3380、
 *       CCameraManager::DestroyCamera 0x16f2cc、RebuildTree 0x1cdb1c、MemoryManager::{Alloc 0x27ce78,
 *       Free 0x27c2d0}、operator delete _ZdlPv 0x27d1d0、memset@plt 0xb65b0、strlen@plt 0xb6538、
 *       strcpy@plt 0xb65a4；Run_Room 0x54298c、g_isZeus 0x5428e8、g_tree 0x5429a8、
 *       option_use_fast_collision 0x542379、三待办队列 0x542a4c/0x542a58/0x542a64、dbg_csol 0x3eb70c。
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   房间的拆除分四层，本卡拍中间三层：Room_Free（已出卡）拆**全局房间表**；~CRoom 拆**对象本身**；
 *   Clear 把房间体复位成"空房间"；RemoveMarked / ClearInstances / ClearDeactiveInstances 拆**实例**；
 *   ClearTiles / DeleteTile / DeleteTilesDepth / DeleteTilesAtDepth 拆 **tile 表**；
 *   ClearStorageTiles/Instances 是两条**无人调用**的残件。
 *   ~CRoom 的顺序（十段）：Run_Room 换成本对象 → (g_isZeus 门) 给"未持久/未标删/未去激活"的实例跑事件 12
 *   → 释 tile 容器两张子表 → 释两串 → Clear() → 删 8 背景记录 → 删 8 视野记录 → 删物理世界
 *   → memset(this,0,292) → 尾段全落空。
 *
 * ── 析构十段（§1 的分段表；地址即锚点区间）────────────────────────────
 *   段  区间                 动作                                                        证据
 *   ①  1afa00..1afa24  push/取址; Run_Room = this（旧值存 r8）                            1afa24 str r0,[r7]
 *   ②  1afa28..1afa74  if (g_isZeus) 沿 room+0x80 → inst+0x178 走，遇到 +0x67/+0x68/+0x69 全 0 的
 *                      实例调 Perform_Event(inst, inst, 12, 0)                           1afa64/1afa68
 *   ③  1afa78..1afac4  if (byte+d0 && +0xac) { Free(+0xc8); Free(+0xc4); +0xac=0 }        1afa94..1afac4
 *   ④  1afac8..1afaf4  Free(+0x08) 名字串；Free(+0x68) 第二串                             1afad4 / 1afaec
 *   ⑤  1afaf8..1afb00  CRoom::Clear()                                                    1afb00 bl 1ad0a4
 *   ⑥  1afb04..1afb28  8 × operator delete [this+0x24+4i]（44 B 背景记录）+ 槽写 0        1afb18/1afb1c
 *   ⑦  1afb2c..1afb54  8 × operator delete [this+0x48+4i]（68 B 视野记录）+ 槽写 0        1afb44/1afb48
 *   ⑧  1afb58..1afb78  ~CPhysicsWorld(+0xb4) 后 operator delete，+0xb4=0                   1afb68/1afb70/1afb78
 *   ⑨  1afb7c..1afb88  memset(this, 0, 292)                                              1afb88 bl memset
 *   ⑩  1afb8c..1afee4  恢复 Run_Room（1afb90）；随后三桶数组 Free / 层链 / 两条实例链的释放
 *                      **全部读到 0**，只有 1afed8 的 Free(0) 真的执行                         见 §1 收尾段
 *
 * ── 槽位释放归属表（292 B 里每一个指针格：谁释放）──────────────────────
 *   偏移        内容                              释放者                       备注
 *   ----------  --------------------------------  ---------------------------  ----------------------------
 *   +0x08       char* 名字串                      ~CRoom (Free)                Clear 只写 0，不 Free
 *   +0x24..40   8 × 44 B 背景记录                 ~CRoom (operator delete)     Clear 只重置记录体
 *   +0x48..64   8 × 68 B 视野记录                 ~CRoom (operator delete)     同上
 *   +0x68       char* 第二串                      ~CRoom (Free)                Clear 只写 0
 *   +0x80/+0x84 实例链 A（尾/头）                  ClearInstances               对象经 vtbl+4（删除式析构）
 *   +0x8c/+0x90 实例链 B（尾/头）                  ClearDeactiveInstances       同上
 *   +0x94/+0x88 两条链的计数                      同上两个函数                  逐条 --
 *   +0xa4       int* id 数组                      Clear (Free)                 +0xa8 计数清零
 *   +0xac       void* 96 B tile 容器              **无人释放**                   ~CRoom 只写 0（见 facts 6）
 *   +0xb0       容器影子格（与 +0xac 同址）        **无人释放**                  只在 CreateWADStorage/Assign 写
 *   +0xb4       CPhysicsWorld*                    ~CRoom (析构 + delete)        Clear 不碰
 *   +0xb8/0xbc/0xc0 tile 计数/容量/数据            ClearTiles (Free)            Delete* 之内联版本同款
 *   +0xc4       WAD tile 指针表                    ~CRoom (仅 +0xd0 非 0 时)     CreateWADStorage 给的是容器内偏移
 *   +0xc8       WAD 记录指针表                     ~CRoom (仅 +0xd0 非 0 时)     AddInstanceToStorage 扩容
 *   +0xcc       char* 房间名（chunk 路径）          **无人释放**                  LoadFromChunk 换新前自己 Free 旧值
 *   +0xd4/d8/dc 层链（头/尾/计数）                  CLayerManager::CleanRoomLayers ~CRoom 尾段有重复实现但落空
 *   +0xe4/+0xf8/+0x110 三张 20 B 哈希图           Clear 只放桶数组(+0xf4/0x108/0x120)  图内节点无释放点（open 3）
 *   ⇒ **真正会漏的只有三格：+0xac（每次 room_add 漏 96+4+4 B）、+0xb0（别名，不重复计）、+0xcc（房间名）**；
 *     三张图的桶数组由 Clear 放，图内节点若由 new 而来则也漏（本卡未能定位节点的生产者，open 3）。
 *
 * ── 与 Room_Free / Clear 的分工（同一批数据的三层视角）────────────────
 *   Room_Free 0x1b5044（RoomOps 卡 §1）：把 g_rooms[0x5425d0] 清空 —— Run_Room 先清 0，再对每个槽
 *     ~CRoom + operator delete、放 rooms 数组、放 names 数组、放 order 数组、清三对计数。
 *     **它自己不做任何 CRoom 内部清理**（不碰 tile、不碰层、不碰实例），全部转包给 ~CRoom。
 *   ~CRoom：单对象；把"房间体"（实例/层/tile/哈希图桶）交给 Clear 去拆，自己只拆"对象外壳"
 *     （两串、两张 WAD 表、8+8 记录、物理世界），最后 memset 把 292 B 洗白。
 *   Clear：房间体复位。它**不**释放任何"外壳"资源（+0x08/+0x68/+0xcc/+0xac/+0xb4/8+8 记录），
 *     只释放 +0xa4、三个桶数组、tile 表、两条实例链、层链。因此"Clear 之后房间可复用"成立，
 *     "Clear 之后对象可 delete"不成立（外壳仍在）。
 *   RemoveMarked：只处理 +0x68 已置 1 的实例（instance_destroy 的延迟删除），**只从 A 链尾进入**；
 *     ClearInstances/ClearDeactiveInstances 是无条件全清。⇒ 前者=每帧增量，后者=整房间归零。
 *
 * ── 逐节锚点 ───────────────────────────────────────────────────────────
 */


/* ── §1 序（0x1afa00..0x1afa24）：帧、Run_Room 换入
 *  push {r3,r4,r5,r6,r7,r8,r9,lr}（32 B，无 canary、无栈上局部量）；r4 = this；
 *  r3 走 GOT 0x3ed92c → 0x5428e8 = g_isZeus（1 B）；r7 走 GOT 0x3ed930 → 0x54298c = Run_Room（指针）。
 *  0x1afa1c 先把旧 Run_Room 存进 r8，0x1afa24 再写 this —— 析构期间「当前房间」= 正在拆的房间，
 *  直到 0x1afb90 才恢复。两个池字同值 0x23df14（同一 GOT 基址 0x3f1c58 的两个负偏移）。 */
/* @0x1afa00 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1afa04 mov r4, r0 */
/* @0x1afa08 ldr r3, [pc, #0x4d8] */
/* @0x1afa0c ldr r7, [pc, #0x4d8] */
/* @0x1afa10 ldr r3, [pc, r3] */
/* @0x1afa14 ldr r7, [pc, r7] */
/* @0x1afa18 ldrb r3, [r3] */
/* @0x1afa1c ldr r8, [r7] */
/* @0x1afa20 cmp r3, #0 */
/* @0x1afa24 str r0, [r7] */

/* ── §1 事件 12 清扫（0x1afa28..0x1afa74）：g_isZeus 门 + 三道实例闸
 *  g_isZeus == 0 → 整段跳过（0x1afa28）。非 0 且 room+0x80（A 链尾）非 0 时，沿 inst+0x178（next）走到 0；
 *  对 +0x68（标删）== 0 且 +0x69（非活动）== 0 且 +0x67（persistent）== 0 的实例调
 *  Perform_Event(inst, inst, 12, 0)。★ 三个闸门与 §9 CleanPersistent 正好互补（那里要 +0x67 != 0）。 */
/* @0x1afa28 beq 0x1afa78 <_ZN5CRoomD2Ev+0x78> */
/* @0x1afa2c ldr r0, [r0, #0x80] */
/* @0x1afa30 cmp r0, #0 */
/* @0x1afa34 beq 0x1afa78 <_ZN5CRoomD2Ev+0x78> */
/* @0x1afa38 ldrb r3, [r0, #0x68] */
/* @0x1afa3c ldr r5, [r0, #0x178] */
/* @0x1afa40 cmp r3, #0 */
/* @0x1afa44 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa48 ldrb r3, [r0, #0x69] */
/* @0x1afa4c cmp r3, #0 */
/* @0x1afa50 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa54 ldrb r3, [r0, #0x67] */
/* @0x1afa58 mov r1, r0 */
/* @0x1afa5c mov r2, #12 */
/* @0x1afa60 cmp r3, #0 */
/* @0x1afa64 bne 0x1afa6c <_ZN5CRoomD2Ev+0x6c> */
/* @0x1afa68 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1afa6c cmp r5, #0 */
/* @0x1afa70 mov r0, r5 */
/* @0x1afa74 bne 0x1afa38 <_ZN5CRoomD2Ev+0x38> */

/* ── §1 tile 容器分支（0x1afa78..0x1afac4）：+0xd0 && +0xac 才动手
 *  Free(+0xc8) → +0xc8=0；Free(+0xc4) → +0xc4=0；最后 +0xac=0（容器本体**不** Free，+0xb0 同址别名也不碰）。
 *  ★ +0xc4 的初值来自 §21 CreateWADStorage：container+0x5c（块内偏移）；只有 Assign/LoadFromChunk 会把它
 *  重指到独立分配块。+0xd0 全库只有 Room_Duplicate 置 1（RoomOps 卡 §3 0x1b59d8），而它紧接着调 Assign。 */
/* @0x1afa78 ldrb r3, [r4, #0xd0] */
/* @0x1afa7c cmp r3, #0 */
/* @0x1afa80 beq 0x1afac8 <_ZN5CRoomD2Ev+0xc8> */
/* @0x1afa84 ldr r3, [r4, #0xac] */
/* @0x1afa88 cmp r3, #0 */
/* @0x1afa8c beq 0x1afac8 <_ZN5CRoomD2Ev+0xc8> */
/* @0x1afa90 ldr r0, [r4, #0xc8] */
/* @0x1afa94 cmp r0, #0 */
/* @0x1afa98 beq 0x1afaa8 <_ZN5CRoomD2Ev+0xa8> */
/* @0x1afa9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afaa0 mov r3, #0 */
/* @0x1afaa4 str r3, [r4, #0xc8] */
/* @0x1afaa8 ldr r0, [r4, #0xc4] */
/* @0x1afaac cmp r0, #0 */
/* @0x1afab0 beq 0x1afac0 <_ZN5CRoomD2Ev+0xc0> */
/* @0x1afab4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afab8 mov r3, #0 */
/* @0x1afabc str r3, [r4, #0xc4] */
/* @0x1afac0 mov r3, #0 */
/* @0x1afac4 str r3, [r4, #0xac] */

/* ── §1 两串（0x1afac8..0x1afaf4）：+0x08 名字串、+0x68 第二串
 *  都是「非 0 才 Free、Free 后写 0」。Clear 也写这两格但只写 0，不 Free ⇒ 释放责任在本函数。 */
/* @0x1afac8 ldr r0, [r4, #0x8] */
/* @0x1afacc cmp r0, #0 */
/* @0x1afad0 beq 0x1afae0 <_ZN5CRoomD2Ev+0xe0> */
/* @0x1afad4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afad8 mov r3, #0 */
/* @0x1afadc str r3, [r4, #0x8] */
/* @0x1afae0 ldr r0, [r4, #0x68] */
/* @0x1afae4 cmp r0, #0 */
/* @0x1afae8 beq 0x1afaf8 <_ZN5CRoomD2Ev+0xf8> */
/* @0x1afaec bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afaf0 mov r3, #0 */
/* @0x1afaf4 str r3, [r4, #0x68] */

/* ── §1 Clear（0x1afaf8..0x1afb00）：房间体交给它
 *  mov r5,r4 把 this 留在 r5 给后面两个 8 循环用；Clear 拆实例链/层/tile/id 数组/三桶数组。 */
/* @0x1afaf8 mov r0, r4 */
/* @0x1afafc mov r5, r4 */
/* @0x1afb00 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */

/* ── §1 八背景（0x1afb04..0x1afb28）：operator delete 而非 MemoryManager::Free
 *  r6=8 计数、r9=0 回填值、r5 从 this 起每轮 +4；读 [r5+0x24] ⇒ 字段 +0x24..+0x40 共 8 格，
 *  与 CRoom_ctor 的「8 × operator new(44)」一一对应 —— 分配器/释放器配对，用 _ZdlPv 0x27d1d0。 */
/* @0x1afb04 mov r6, #8 */
/* @0x1afb08 mov r9, #0 */
/* @0x1afb0c ldr r0, [r5, #0x24] */
/* @0x1afb10 cmp r0, #0 */
/* @0x1afb14 beq 0x1afb20 <_ZN5CRoomD2Ev+0x120> */
/* @0x1afb18 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb1c str r9, [r5, #0x24] */
/* @0x1afb20 subs r6, r6, #1 */
/* @0x1afb24 add r5, r5, #4 */
/* @0x1afb28 bne 0x1afb0c <_ZN5CRoomD2Ev+0x10c> */

/* ── §1 八视野（0x1afb2c..0x1afb54）：+0x48..+0x64
 *  与 8 背景同构，对应 ctor 的「8 × operator new(68)」。r9 = r6 在这里是 0（r6 已被上一轮减到 0），
 *  所以「清零」用的是同一个 0 寄存器，不是笔误。 */
/* @0x1afb2c mov r5, r4 */
/* @0x1afb30 mov r9, r6 */
/* @0x1afb34 ldr r0, [r5, #0x48] */
/* @0x1afb38 add r6, r6, #1 */
/* @0x1afb3c cmp r0, #0 */
/* @0x1afb40 beq 0x1afb4c <_ZN5CRoomD2Ev+0x14c> */
/* @0x1afb44 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb48 str r9, [r5, #0x48] */
/* @0x1afb4c cmp r6, #8 */
/* @0x1afb50 add r5, r5, #4 */
/* @0x1afb54 bne 0x1afb34 <_ZN5CRoomD2Ev+0x134> */

/* ── §1 物理世界（0x1afb58..0x1afb78）：+0xb4
 *  非 0 → CPhysicsWorld::~CPhysicsWorld(0x239e68) → operator delete → +0xb4=0。
 *  ★ Clear 不碰 +0xb4：物理世界与 tile/实例/层不同，不属于「房间体复位」的一部分。 */
/* @0x1afb58 ldr r5, [r4, #0xb4] */
/* @0x1afb5c cmp r5, #0 */
/* @0x1afb60 beq 0x1afb7c <_ZN5CRoomD2Ev+0x17c> */
/* @0x1afb64 mov r0, r5 */
/* @0x1afb68 bl 0x239e68 <_ZN13CPhysicsWorldD2Ev> */
/* @0x1afb6c mov r0, r5 */
/* @0x1afb70 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afb74 mov r3, #0 */
/* @0x1afb78 str r3, [r4, #0xb4] */

/* ── §1 memset(this,0,292)（0x1afb7c..0x1afb88）：本卡头号发现（一）
 *  mov r0,r4 / mov r1,#0 / mov r2,#292 / bl memset@plt —— 整对象洗白，**发生在其后所有释放动作之前**。
 *  0x1afb8c 起的每一条释放都要先读一个已被清零的格子 ⇒ 见下一段的死尾。 */
/* @0x1afb7c mov r0, r4 */
/* @0x1afb80 mov r1, #0 */
/* @0x1afb84 mov r2, #292 */
/* @0x1afb88 bl 0xb65b0 <memset@plt> */

/* ── §1 死尾 A（0x1afb8c..0x1afbd4）：恢复 Run_Room + 三个桶数组（全部落空）
 *  0x1afb90 str r8,[r7] 把 Run_Room 恢复成旧值 —— 这是 memset 之后唯一有效的写。
 *  随后 Free(+0x120)/Free(+0x108)/Free(+0xf4)：三格刚被 memset 清 0 → 三条 beq 全跳，一次也没 Free。
 *  （三张图的桶数组实际由 §3 Clear 在 0x1ad270/0x1ad288/0x1ad2a4 释放。） */
/* @0x1afb8c ldr r0, [r4, #0x120] */
/* @0x1afb90 str r8, [r7] */
/* @0x1afb94 cmp r0, #0 */
/* @0x1afb98 beq 0x1afba8 <_ZN5CRoomD2Ev+0x1a8> */
/* @0x1afb9c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afba0 mov r3, #0 */
/* @0x1afba4 str r3, [r4, #0x120] */
/* @0x1afba8 ldr r0, [r4, #0x108] */
/* @0x1afbac cmp r0, #0 */
/* @0x1afbb0 beq 0x1afbc0 <_ZN5CRoomD2Ev+0x1c0> */
/* @0x1afbb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afbb8 mov r3, #0 */
/* @0x1afbbc str r3, [r4, #0x108] */
/* @0x1afbc0 ldr r0, [r4, #0xf4] */
/* @0x1afbc4 cmp r0, #0 */
/* @0x1afbc8 beq 0x1afbd8 <_ZN5CRoomD2Ev+0x1d8> */
/* @0x1afbcc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afbd0 mov r3, #0 */
/* @0x1afbd4 str r3, [r4, #0xf4] */

/* ── §1 死尾 B（0x1afbd8..0x1afc2c）：层链遍历（r8 = +0xe0 = 0 → 整段跳过）
 *  0x1afbd8 读 +0xe0（链类型标签，ctor 置 1），memset 后为 0 → 0x1afbe0 beq 直接跳到 0x1afc30。
 *  这段本来是「按类型 1/2/3 选 operator delete 或 MemoryManager::Free 的链表析构」：层头 +0xd4、
 *  节点 next 在 +0x68、节点子表头 +0x58 / 子类型 +0x64 / 子链 next +0x14。 */
/* @0x1afbd8 ldr r8, [r4, #0xe0] */
/* @0x1afbdc cmp r8, #0 */
/* @0x1afbe0 beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afbe4 ldr r5, [r4, #0xd4] */
/* @0x1afbe8 cmp r5, #0 */
/* @0x1afbec beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afbf0 mov r9, #0 */
/* @0x1afbf4 b 0x1afc14 <_ZN5CRoomD2Ev+0x214> */
/* @0x1afbf8 cmp r8, #3 */
/* @0x1afbfc beq 0x1afcf4 <_ZN5CRoomD2Ev+0x2f4> */
/* @0x1afc00 cmp r8, #1 */
/* @0x1afc04 beq 0x1afd98 <_ZN5CRoomD2Ev+0x398> */
/* @0x1afc08 cmp r7, #0 */
/* @0x1afc0c beq 0x1afc30 <_ZN5CRoomD2Ev+0x230> */
/* @0x1afc10 mov r5, r7 */
/* @0x1afc14 cmp r8, #2 */
/* @0x1afc18 ldr r7, [r5, #0x68] */
/* @0x1afc1c bne 0x1afbf8 <_ZN5CRoomD2Ev+0x1f8> */
/* @0x1afc20 mov r0, r5 */
/* @0x1afc24 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afc28 cmp r7, #0 */
/* @0x1afc2c bne 0x1afc10 <_ZN5CRoomD2Ev+0x210> */

/* ── §1 死尾 C（0x1afc30..0x1afc58）：层链三格清零 + Free(+0xc0)
 *  三格被 memset 后本就是 0（这里再写一次）；r6 = +0xc0 = 0 → 0x1afc48 beq 0x1afed8，
 *  那条路径会调用 MemoryManager::Free(NULL) 再回 0x1afc58 —— **整段死尾里唯一真的被执行的调用**。 */
/* @0x1afc30 ldr r6, [r4, #0xc0] */
/* @0x1afc34 mov r5, #0 */
/* @0x1afc38 str r5, [r4, #0xdc] */
/* @0x1afc3c cmp r6, r5 */
/* @0x1afc40 str r5, [r4, #0xd8] */
/* @0x1afc44 str r5, [r4, #0xd4] */
/* @0x1afc48 beq 0x1afed8 <_ZN5CRoomD2Ev+0x4d8> */
/* @0x1afc4c mov r0, r6 */
/* @0x1afc50 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afc54 str r5, [r4, #0xc0] */
/* @0x1afc58 ldr r3, [r4, #0x98] */

/* ── §1 死尾 D（0x1afc5c..0x1afc9c）：实例链 B 的析构遍历（r3 = +0x98 = 0 → 跳过）
 *  +0x98 是这条实例链的类型标签（ctor 置 1）；memset 后为 0 → 0x1afc68 beq 跳过整段。
 *  形制：头 +0x8c、next inst+0x178，类型 2/3 走 MemoryManager::Free、类型 1 走 operator delete。 */
/* @0x1afc5c mov r2, #0 */
/* @0x1afc60 str r2, [r4, #0xbc] */
/* @0x1afc64 cmp r3, r2 */
/* @0x1afc68 beq 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afc6c ldr r5, [r4, #0x8c] */
/* @0x1afc70 cmp r5, #0 */
/* @0x1afc74 beq 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afc78 cmp r3, #2 */
/* @0x1afc7c beq 0x1afe24 <_ZN5CRoomD2Ev+0x424> */
/* @0x1afc80 cmp r3, #3 */
/* @0x1afc84 beq 0x1afe88 <_ZN5CRoomD2Ev+0x488> */
/* @0x1afc88 cmp r3, #1 */
/* @0x1afc8c beq 0x1afeb4 <_ZN5CRoomD2Ev+0x4b4> */
/* @0x1afc90 ldr r6, [r5, #0x178] */
/* @0x1afc94 cmp r6, #0 */
/* @0x1afc98 mov r5, r6 */
/* @0x1afc9c bne 0x1afc90 <_ZN5CRoomD2Ev+0x290> */

/* ── §1 死尾 E（0x1afca0..0x1afcf0）：B 链三格清零 + A 链虚析构遍历 + 收尾
 *  先把 +0x94/+0x90/+0x8c（B 链）清 0；再读 +0x80（A 链尾）——已清零 → 0x1afcb8 beq 到 0x1afcdc，
 *  那段「逐实例 blx [vtbl+4]」的循环一次也不进。最后清 +0x88/+0x84/+0x80 并 pop。
 *  ★ 这条返回路径是本函数真正走的那条：Clear 已把六格清零，这里的写只是重复。 */
/* @0x1afca0 ldr r3, [r4, #0x80] */
/* @0x1afca4 mov r2, #0 */
/* @0x1afca8 str r2, [r4, #0x94] */
/* @0x1afcac cmp r3, r2 */
/* @0x1afcb0 str r2, [r4, #0x90] */
/* @0x1afcb4 str r2, [r4, #0x8c] */
/* @0x1afcb8 beq 0x1afcdc <_ZN5CRoomD2Ev+0x2dc> */
/* @0x1afcbc ldr r2, [r3] */
/* @0x1afcc0 mov r0, r3 */
/* @0x1afcc4 ldr r5, [r3, #0x178] */
/* @0x1afcc8 ldr r3, [r2, #0x4] */
/* @0x1afccc blx r3 */
/* @0x1afcd0 cmp r5, #0 */
/* @0x1afcd4 mov r3, r5 */
/* @0x1afcd8 bne 0x1afcbc <_ZN5CRoomD2Ev+0x2bc> */
/* @0x1afcdc mov r3, #0 */
/* @0x1afce0 mov r0, r4 */
/* @0x1afce4 str r3, [r4, #0x88] */
/* @0x1afce8 str r3, [r4, #0x84] */
/* @0x1afcec str r3, [r4, #0x80] */
/* @0x1afcf0 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── §1 死尾 F（0x1afcf4..0x1afe6c）：层链节点删除的四个类型分支（不可达）
 *  类型 3 → 0x1afcf4（节点 [node+0x1c] 先过 MemoryInWad 再决定 Free；子表 +0x64/+0x58 按子类型
 *  2/3/1 分别 Free/Free/delete；节点用 MemoryManager::Free）；类型 1 → 0x1afd98（同一形状，节点用 _ZdlPv）。
 *  ★ 全部只在 0x1afbf8 分派后可达，而 0x1afbf8 已被 0x1afbe0 的 beq 挡死 ⇒ 整段不可达。 */
/* @0x1afcf4 ldr r0, [r5, #0x1c] */
/* @0x1afcf8 bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1afcfc cmp r0, #0 */
/* @0x1afd00 bne 0x1afd0c <_ZN5CRoomD2Ev+0x30c> */
/* @0x1afd04 ldr r0, [r5, #0x1c] */
/* @0x1afd08 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd0c ldr r3, [r5, #0x64] */
/* @0x1afd10 str r9, [r5, #0x1c] */
/* @0x1afd14 cmp r3, #0 */
/* @0x1afd18 beq 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd1c ldr r0, [r5, #0x58] */
/* @0x1afd20 cmp r0, #0 */
/* @0x1afd24 beq 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd28 cmp r3, #2 */
/* @0x1afd2c beq 0x1afd68 <_ZN5CRoomD2Ev+0x368> */
/* @0x1afd30 cmp r3, #3 */
/* @0x1afd34 beq 0x1afd80 <_ZN5CRoomD2Ev+0x380> */
/* @0x1afd38 cmp r3, #1 */
/* @0x1afd3c beq 0x1afe70 <_ZN5CRoomD2Ev+0x470> */
/* @0x1afd40 ldr r6, [r0, #0x14] */
/* @0x1afd44 cmp r6, #0 */
/* @0x1afd48 mov r0, r6 */
/* @0x1afd4c bne 0x1afd40 <_ZN5CRoomD2Ev+0x340> */
/* @0x1afd50 str r9, [r5, #0x60] */
/* @0x1afd54 mov r0, r5 */
/* @0x1afd58 str r9, [r5, #0x5c] */
/* @0x1afd5c str r9, [r5, #0x58] */
/* @0x1afd60 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd64 b 0x1afc08 <_ZN5CRoomD2Ev+0x208> */
/* @0x1afd68 ldr r6, [r0, #0x14] */
/* @0x1afd6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd70 cmp r6, #0 */
/* @0x1afd74 mov r0, r6 */
/* @0x1afd78 bne 0x1afd68 <_ZN5CRoomD2Ev+0x368> */
/* @0x1afd7c b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd80 ldr r6, [r0, #0x14] */
/* @0x1afd84 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afd88 cmp r6, #0 */
/* @0x1afd8c mov r0, r6 */
/* @0x1afd90 bne 0x1afd80 <_ZN5CRoomD2Ev+0x380> */
/* @0x1afd94 b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afd98 ldr r0, [r5, #0x1c] */
/* @0x1afd9c bl 0x1aad50 <_Z11MemoryInWadPv> */
/* @0x1afda0 cmp r0, #0 */
/* @0x1afda4 bne 0x1afdb0 <_ZN5CRoomD2Ev+0x3b0> */
/* @0x1afda8 ldr r0, [r5, #0x1c] */
/* @0x1afdac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afdb0 ldr r3, [r5, #0x64] */
/* @0x1afdb4 str r9, [r5, #0x1c] */
/* @0x1afdb8 cmp r3, #0 */
/* @0x1afdbc beq 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afdc0 ldr r0, [r5, #0x58] */
/* @0x1afdc4 cmp r0, #0 */
/* @0x1afdc8 beq 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afdcc cmp r3, #2 */
/* @0x1afdd0 beq 0x1afe0c <_ZN5CRoomD2Ev+0x40c> */
/* @0x1afdd4 cmp r3, #3 */
/* @0x1afdd8 beq 0x1afe40 <_ZN5CRoomD2Ev+0x440> */
/* @0x1afddc cmp r3, #1 */
/* @0x1afde0 beq 0x1afe58 <_ZN5CRoomD2Ev+0x458> */
/* @0x1afde4 ldr r6, [r0, #0x14] */
/* @0x1afde8 cmp r6, #0 */
/* @0x1afdec mov r0, r6 */
/* @0x1afdf0 bne 0x1afde4 <_ZN5CRoomD2Ev+0x3e4> */
/* @0x1afdf4 str r9, [r5, #0x60] */
/* @0x1afdf8 mov r0, r5 */
/* @0x1afdfc str r9, [r5, #0x5c] */
/* @0x1afe00 str r9, [r5, #0x58] */
/* @0x1afe04 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe08 b 0x1afc08 <_ZN5CRoomD2Ev+0x208> */
/* @0x1afe0c ldr r6, [r0, #0x14] */
/* @0x1afe10 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe14 cmp r6, #0 */
/* @0x1afe18 mov r0, r6 */
/* @0x1afe1c bne 0x1afe0c <_ZN5CRoomD2Ev+0x40c> */
/* @0x1afe20 b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afe24 ldr r6, [r5, #0x178] */
/* @0x1afe28 mov r0, r5 */
/* @0x1afe2c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe30 cmp r6, #0 */
/* @0x1afe34 mov r5, r6 */
/* @0x1afe38 bne 0x1afe24 <_ZN5CRoomD2Ev+0x424> */
/* @0x1afe3c b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afe40 ldr r6, [r0, #0x14] */
/* @0x1afe44 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afe48 cmp r6, #0 */
/* @0x1afe4c mov r0, r6 */
/* @0x1afe50 bne 0x1afe40 <_ZN5CRoomD2Ev+0x440> */
/* @0x1afe54 b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */
/* @0x1afe58 ldr r6, [r0, #0x14] */
/* @0x1afe5c bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe60 cmp r6, #0 */
/* @0x1afe64 mov r0, r6 */
/* @0x1afe68 bne 0x1afe58 <_ZN5CRoomD2Ev+0x458> */
/* @0x1afe6c b 0x1afdf4 <_ZN5CRoomD2Ev+0x3f4> */

/* ── §1 死尾 G（0x1afe70..0x1afee4）：最后两条子链分支 + Free(0) 出口
 *  0x1afed8 是 0x1afc48 的落点：mov r0,r6(=0) / bl MemoryManager::Free / str r6,[+0xc0] / b 0x1afc58。
 *  MemoryManager::Free 对 NULL 的处理决定这次调用是否真落地（未做运行期取证，open 2）。 */
/* @0x1afe70 ldr r6, [r0, #0x14] */
/* @0x1afe74 bl 0x27d1d0 <_ZdlPv> */
/* @0x1afe78 cmp r6, #0 */
/* @0x1afe7c mov r0, r6 */
/* @0x1afe80 bne 0x1afe70 <_ZN5CRoomD2Ev+0x470> */
/* @0x1afe84 b 0x1afd50 <_ZN5CRoomD2Ev+0x350> */
/* @0x1afe88 ldr r3, [r5] */
/* @0x1afe8c mov r0, r5 */
/* @0x1afe90 ldr r6, [r5, #0x178] */
/* @0x1afe94 ldr r3, [r3] */
/* @0x1afe98 blx r3 */
/* @0x1afe9c mov r0, r5 */
/* @0x1afea0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afea4 cmp r6, #0 */
/* @0x1afea8 mov r5, r6 */
/* @0x1afeac bne 0x1afe88 <_ZN5CRoomD2Ev+0x488> */
/* @0x1afeb0 b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afeb4 ldr r3, [r5] */
/* @0x1afeb8 mov r0, r5 */
/* @0x1afebc ldr r6, [r5, #0x178] */
/* @0x1afec0 ldr r3, [r3, #0x4] */
/* @0x1afec4 blx r3 */
/* @0x1afec8 cmp r6, #0 */
/* @0x1afecc mov r5, r6 */
/* @0x1afed0 bne 0x1afeb4 <_ZN5CRoomD2Ev+0x4b4> */
/* @0x1afed4 b 0x1afca0 <_ZN5CRoomD2Ev+0x2a0> */
/* @0x1afed8 mov r0, r6 */
/* @0x1afedc bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1afee0 str r6, [r4, #0xc0] */
/* @0x1afee4 b 0x1afc58 <_ZN5CRoomD2Ev+0x258> */

/* ── §1 literal pool（0x1afee8..0x1afeec，2 字；非指令）
 *  0x1afee8 = 0x0023df14 → 配 0x1afa10 的 pc(0x1afa18) = GOT 0x3ed92c → 0x5428e8 g_isZeus；
 *  0x1afeec = 0x0023df14 → 配 0x1afa14 的 pc(0x1afa1c) = GOT 0x3ed930 → 0x54298c Run_Room。
 *  objdump 把两字都译成 `eoreq sp, r3, r4, lsl pc`，按规矩保留原写法。 */
/* @0x1afee8 eoreq sp, r3, r4, lsl pc */
/* @0x1afeec eoreq sp, r3, r4, lsl pc */

/* ── §1 小结 / open ────────────────────────────────────────────────────
 * 小结：~CRoom = 「Run_Room 换入 →（Zeus）事件 12 清扫 → 容器两表 → 两串 → Clear → 8 背景 delete →
 *   8 视野 delete → delete 物理世界 → memset(292) → 恢复 Run_Room → 一段全落空的尾」。
 *   ★ 语义上真正释放外壳的是 ③④⑥⑦⑧；房间体由 Clear 拆；尾段（0x1afb94..0x1afee4，约 150 条）是
 *     Clear + CleanRoomLayers + ClearInstances 的**重复实现**，且被自己的 memset 挡死。
 * open 1: 事件号 12 的官方名（GM 事件枚举里的 CleanUp）未由符号/字符串证实；本卡只证实参 (12, 0)。
 *         g_isZeus 门控的动机（为什么 3D 模式才给实例跑这次事件）未证。
 * open 2: MemoryManager::Free(NULL) 是空操作还是记账失败路径，本卡未取证；它决定 0x1afed8 是否可观测。
 * open 3: 三张 20 B 哈希图（+0xe4/+0xf8/+0x110）的节点生产者与释放点：已索引函数里没有对节点的遍历删除，
 *         若节点由 new 而来则每次房间销毁都漏（与 Clear 只放桶数组一致）。
 * open 4: +0xac 的 96 B 容器**从不** Free（+0xb0 同址）。Room_Add 每加一个房间就漏 96+4+4 B ——
 *         推断，未做运行期 malloc 对照。
 * open 5: memset 的位置是原版源码顺序（编译器不能把它挪过随后对 this 的读），但「先 memset 再释放」
 *         是有意（防重复释放）还是重构残留，无法从字节判定。
 * open 6: 0x1afed8 的 Free(0) 之后 str r6,[+0xc0] 把 0 写回（已是 0），若 Free 对 NULL 会写块头，
 *         这格可能被改成 0xfeeefeee —— 未验证。
 */

/* ── §2 序与五个全局（0x1abb24..0x1abb44）：帧、GOT 基址 0x3f1c58
 *  帧 push 9 字 + sub sp,#12（sp+0x4 存「option 字节指针」）。r5 = this；r10 = 0x3f1c58（GOT 基址，
 *  池字 0x1abd84 = 0x246118）。四个负偏移依次落：r7 = 0x536d7c = CInstance::ms_markedCount（4 B）、
 *  r3 = 0x542379 = option_use_fast_collision（1 B）、0x542a58 = ChangeInstanceDepths 待办队列、
 *  0x536f28 = CInstance::ms_ID2InstanceE、0x5429a8 = g_tree（碰撞树）。 */
/* @0x1abb24 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1abb28 sub sp, sp, #12 */
/* @0x1abb2c ldr r10, [pc, #0x250] */
/* @0x1abb30 mov r5, r0 */
/* @0x1abb34 ldr r2, [pc, #0x24c] */
/* @0x1abb38 add r10, pc, r10 */
/* @0x1abb3c ldr r3, [pc, #0x248] */
/* @0x1abb40 ldr r7, [r10, r2] */
/* @0x1abb44 ldr r3, [r10, r3] */

/* ── §2 双闸（0x1abb48..0x1abb6c）：>250 与 option
 *  r8 = ms_markedCount；`cmp r8,#250 / movle r8,#0 / movgt r8,#1` 把计数压成「>250」布尔。
 *  option_use_fast_collision == 0 → 0x1abb70（跳过整段树处理）；
 *  option != 0 且 >250 → 0x1abd44（先拆 g_tree，再回来扫）。★ 250 这个门槛只决定树的处置，
 *  不决定要不要扫 —— 扫是无条件的。 */
/* @0x1abb48 ldr r8, [r7] */
/* @0x1abb4c str r3, [sp, #0x4] */
/* @0x1abb50 cmp r8, #250 */
/* @0x1abb54 ldrb r3, [r3] */
/* @0x1abb58 movle r8, #0 */
/* @0x1abb5c movgt r8, #1 */
/* @0x1abb60 cmp r3, #0 */
/* @0x1abb64 beq 0x1abb70 <_ZN5CRoom12RemoveMarkedEv+0x4c> */
/* @0x1abb68 cmp r8, #0 */
/* @0x1abb6c bne 0x1abd44 <_ZN5CRoom12RemoveMarkedEv+0x220> */

/* ── §2 遍历起点与标删判据（0x1abb70..0x1abb9c）：只从 A 链尾进
 *  r4 = room+0x80（A 链尾）；非 0 → r6 = 0（回填值）；循环头每次先存 next = inst+0x178，
 *  再看 inst+0x68（标删）。+0x68 == 0 → 直接下一只（0x1abb84）。
 *  ★ 起点固定在 +0x80 ⇒ B 链（+0x8c）里的实例本函数看不到；后面按 +0x69 分派到 B 的那条分支
 *  只能命中「还在 A 链但已被标成非活动、UpdateActive 尚未搬走」的实例（推断，见 open 2）。 */
/* @0x1abb70 ldr r4, [r5, #0x80] */
/* @0x1abb74 cmp r4, #0 */
/* @0x1abb78 movne r6, #0 */
/* @0x1abb7c bne 0x1abb90 <_ZN5CRoom12RemoveMarkedEv+0x6c> */
/* @0x1abb80 b 0x1abcdc <_ZN5CRoom12RemoveMarkedEv+0x1b8> */
/* @0x1abb84 cmp r9, #0 */
/* @0x1abb88 beq 0x1abcdc <_ZN5CRoom12RemoveMarkedEv+0x1b8> */
/* @0x1abb8c mov r4, r9 */
/* @0x1abb90 ldrb r3, [r4, #0x68] */
/* @0x1abb94 ldr r9, [r4, #0x178] */
/* @0x1abb98 cmp r3, #0 */
/* @0x1abb9c beq 0x1abb84 <_ZN5CRoom12RemoveMarkedEv+0x60> */

/* ── §2 清一条待办队列（0x1abba0..0x1abbf4）：0x542a58
 *  带头压缩：0x542a58 是 12 B 的 {ptr@+0, ?@+4, count@+8}；把数组里等于本实例的项全部挤掉、
 *  命中就 count--。写法与 §4 的三处压缩逐字同形（r11 标记是否命中）。
 *  ★ 只清这一条（ChangeInstanceDepths），另两条 0x542a4c / 0x542a64 不碰 —— 与 §4 清三条不同。 */
/* @0x1abba0 ldr r3, [pc, #0x1e8] */
/* @0x1abba4 ldr r12, [r10, r3] */
/* @0x1abba8 ldr lr, [r12, #0x8] */
/* @0x1abbac cmp lr, #0 */
/* @0x1abbb0 ble 0x1abbf8 <_ZN5CRoom12RemoveMarkedEv+0xd4> */
/* @0x1abbb4 ldr r2, [r12] */
/* @0x1abbb8 mov r11, #0 */
/* @0x1abbbc mov r3, r11 */
/* @0x1abbc0 mov r1, r11 */
/* @0x1abbc4 ldr r0, [r2, r3, lsl #2] */
/* @0x1abbc8 str r0, [r2, r1, lsl #2] */
/* @0x1abbcc ldr r2, [r12] */
/* @0x1abbd0 ldr r0, [r2, r3, lsl #2] */
/* @0x1abbd4 add r3, r3, #1 */
/* @0x1abbd8 cmp r4, r0 */
/* @0x1abbdc addne r1, r1, #1 */
/* @0x1abbe0 moveq r11, #1 */
/* @0x1abbe4 cmp r3, lr */
/* @0x1abbe8 bne 0x1abbc4 <_ZN5CRoom12RemoveMarkedEv+0xa0> */
/* @0x1abbec cmp r11, #0 */
/* @0x1abbf0 subne r3, r3, #1 */
/* @0x1abbf4 strne r3, [r12, #0x8] */

/* ── §2 层内摘除（0x1abbf8..0x1abc00）：CLayerManager::RemoveInstance(room, inst)
 *  先摘层再摘哈希/链，顺序与 §4 ClearInstances 一致。 */
/* @0x1abbf8 mov r0, r5 */
/* @0x1abbfc mov r1, r4 */
/* @0x1abc00 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */

/* ── §2 摘 id 哈希（0x1abc04..0x1abc78）：ms_ID2InstanceE，键 = inst+0x78
 *  桶步长 8（{head@+0, tail@+4}）、掩码在表头 +0x4、节点 {prev@+0, next@+4, key@+8}；
 *  key & mask 选桶 → 顺 next 找 key → 摘链（首元素/尾元素/中间三路）→ Free(节点) → 表计数--。
 *  ★ 这是 CInstance 的唯一 id→指针表：对象一死就必须在这里摘掉，否则 id 查表会拿到悬垂指针。 */
/* @0x1abc04 ldr r3, [pc, #0x188] */
/* @0x1abc08 ldr r1, [r4, #0x78] */
/* @0x1abc0c ldr r11, [r10, r3] */
/* @0x1abc10 ldm r11, {r0, r12} */
/* @0x1abc14 and r12, r1, r12 */
/* @0x1abc18 ldr r3, [r0, r12, lsl #3] */
/* @0x1abc1c add lr, r0, r12, lsl #3 */
/* @0x1abc20 cmp r3, #0 */
/* @0x1abc24 bne 0x1abc38 <_ZN5CRoom12RemoveMarkedEv+0x114> */
/* @0x1abc28 b 0x1abc7c <_ZN5CRoom12RemoveMarkedEv+0x158> */
/* @0x1abc2c ldr r3, [r3, #0x4] */
/* @0x1abc30 cmp r3, #0 */
/* @0x1abc34 beq 0x1abc7c <_ZN5CRoom12RemoveMarkedEv+0x158> */
/* @0x1abc38 ldr r2, [r3, #0x8] */
/* @0x1abc3c cmp r1, r2 */
/* @0x1abc40 bne 0x1abc2c <_ZN5CRoom12RemoveMarkedEv+0x108> */
/* @0x1abc44 ldr r2, [r3] */
/* @0x1abc48 ldr r1, [r3, #0x4] */
/* @0x1abc4c cmp r2, #0 */
/* @0x1abc50 strne r1, [r2, #0x4] */
/* @0x1abc54 ldrne r1, [r3, #0x4] */
/* @0x1abc58 streq r1, [r0, r12, lsl #3] */
/* @0x1abc5c mov r0, r3 */
/* @0x1abc60 cmp r1, #0 */
/* @0x1abc64 streq r2, [lr, #0x4] */
/* @0x1abc68 strne r2, [r1] */
/* @0x1abc6c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1abc70 ldr r3, [r11, #0x8] */
/* @0x1abc74 sub r3, r3, #1 */
/* @0x1abc78 str r3, [r11, #0x8] */

/* ── §2 按 +0x69 分派 + A 链摘除 + 删除式析构 + 计数（0x1abc7c..0x1abcd8）
 *  读 +0x69（非活动）→ 非 0 走 B 分支（0x1abd04）。A 路：prev = inst+0x17c、next = inst+0x178，
 *  四路摘链（改 prev->next / next->prev / room+0x80 尾 / room+0x84 头）；把 inst+0x178/+0x17c 写 0；
 *  blx [vtbl+4]（Itanium ABI 的 deleting dtor D0 槽）；room+0x88--。 */
/* @0x1abc7c ldrb r3, [r4, #0x69] */
/* @0x1abc80 ldr r2, [r4, #0x178] */
/* @0x1abc84 cmp r3, #0 */
/* @0x1abc88 ldr r3, [r4, #0x17c] */
/* @0x1abc8c bne 0x1abd04 <_ZN5CRoom12RemoveMarkedEv+0x1e0> */
/* @0x1abc90 cmp r3, #0 */
/* @0x1abc94 strne r2, [r3, #0x178] */
/* @0x1abc98 streq r2, [r5, #0x80] */
/* @0x1abc9c mov r0, r4 */
/* @0x1abca0 ldrne r3, [r4, #0x17c] */
/* @0x1abca4 ldrne r2, [r4, #0x178] */
/* @0x1abca8 cmp r2, #0 */
/* @0x1abcac streq r3, [r5, #0x84] */
/* @0x1abcb0 strne r3, [r2, #0x17c] */
/* @0x1abcb4 ldr r3, [r4] */
/* @0x1abcb8 str r6, [r4, #0x178] */
/* @0x1abcbc str r6, [r4, #0x17c] */
/* @0x1abcc0 ldr r3, [r3, #0x4] */
/* @0x1abcc4 blx r3 */
/* @0x1abcc8 ldr r3, [r5, #0x88] */
/* @0x1abccc cmp r9, #0 */
/* @0x1abcd0 sub r3, r3, #1 */
/* @0x1abcd4 str r3, [r5, #0x88] */
/* @0x1abcd8 bne 0x1abb8c <_ZN5CRoom12RemoveMarkedEv+0x68> */

/* ── §2 收尾判据（0x1abcdc..0x1abd00）：计数清零 + 可选重建
 *  option == 0 → 0x1abcf4：只把 ms_markedCount 清 0。option != 0 且 >250 → 0x1abd70：RebuildTree()
 *  然后同样清 0。★ 这是 ms_markedCount 在已索引函数里唯一的清零点（Command_Destroy 卡 open 2 的答案）。 */
/* @0x1abcdc ldr r2, [sp, #0x4] */
/* @0x1abce0 ldrb r3, [r2] */
/* @0x1abce4 cmp r3, #0 */
/* @0x1abce8 beq 0x1abcf4 <_ZN5CRoom12RemoveMarkedEv+0x1d0> */
/* @0x1abcec cmp r8, #0 */
/* @0x1abcf0 bne 0x1abd70 <_ZN5CRoom12RemoveMarkedEv+0x24c> */
/* @0x1abcf4 mov r3, #0 */
/* @0x1abcf8 str r3, [r7] */
/* @0x1abcfc add sp, sp, #12 */
/* @0x1abd00 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── §2 B 分支（0x1abd04..0x1abd40）：摘 B 链，**不清指针**
 *  同四路摘链，但改的是 room+0x8c（尾）/room+0x90（头）；摘完直接 blx [vtbl+4] 并把 room+0x94--。
 *  ★ 与 A 路唯一的不对称：这里没有 `str 0,[inst+0x178]/[inst+0x17c]` 两句 —— 被删对象的两个链指针
 *  保持指向前后邻居（对象随后被 delete，若内存复用则有滞后读风险，open 3）。 */
/* @0x1abd04 cmp r3, #0 */
/* @0x1abd08 strne r2, [r3, #0x178] */
/* @0x1abd0c streq r2, [r5, #0x8c] */
/* @0x1abd10 mov r0, r4 */
/* @0x1abd14 ldrne r3, [r4, #0x17c] */
/* @0x1abd18 ldrne r2, [r4, #0x178] */
/* @0x1abd1c cmp r2, #0 */
/* @0x1abd20 streq r3, [r5, #0x90] */
/* @0x1abd24 strne r3, [r2, #0x17c] */
/* @0x1abd28 ldr r3, [r4] */
/* @0x1abd2c ldr r3, [r3, #0x4] */
/* @0x1abd30 blx r3 */
/* @0x1abd34 ldr r3, [r5, #0x94] */
/* @0x1abd38 sub r3, r3, #1 */
/* @0x1abd3c str r3, [r5, #0x94] */
/* @0x1abd40 b 0x1abb84 <_ZN5CRoom12RemoveMarkedEv+0x60> */

/* ── §2 拆碰撞树（0x1abd44..0x1abd6c）：>250 且 option 非 0 的入口段
 *  r4 = 0x5429a8 = g_tree；[g_tree] 非 0 → blx [vtbl+4] 析构 → [g_tree] = 0。
 *  然后 b 0x1abb70 回到主循环（先把树扔掉，扫完再建）。 */
/* @0x1abd44 ldr r3, [pc, #0x4c] */
/* @0x1abd48 ldr r4, [r10, r3] */
/* @0x1abd4c ldr r0, [r4] */
/* @0x1abd50 cmp r0, #0 */
/* @0x1abd54 beq 0x1abd64 <_ZN5CRoom12RemoveMarkedEv+0x240> */
/* @0x1abd58 ldr r3, [r0] */
/* @0x1abd5c ldr r3, [r3, #0x4] */
/* @0x1abd60 blx r3 */
/* @0x1abd64 mov r3, #0 */
/* @0x1abd68 str r3, [r4] */
/* @0x1abd6c b 0x1abb70 <_ZN5CRoom12RemoveMarkedEv+0x4c> */

/* ── §2 重建碰撞树（0x1abd70..0x1abd80）：RebuildTree() + 清计数 + 返回
 *  bl 0x1cdb1c RebuildTree；ms_markedCount = 0；pop。与 0x1abcf4 的区别只有这一条 bl。 */
/* @0x1abd70 bl 0x1cdb1c <_Z11RebuildTreev> */
/* @0x1abd74 mov r3, #0 */
/* @0x1abd78 str r3, [r7] */
/* @0x1abd7c add sp, sp, #12 */
/* @0x1abd80 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── §2 literal pool（0x1abd84..0x1abd98，6 字；非指令）
 *  0x1abd84 = 0x246118 → 配 0x1abb38 的 pc(0x1abb40) = GOT 基址 0x3f1c58；
 *  0x1abd88 = -0x3b9c → 0x536d7c ms_markedCount；0x1abd8c = -0x15d0 → 0x542379 option_use_fast_collision；
 *  0x1abd90 = -0x3bac → 0x542a58；0x1abd94 = -0x400c → 0x536f28 ms_ID2InstanceE；
 *  0x1abd98 = -0x3a0c → 0x5429a8 g_tree。首字被 objdump 译成 `eoreq r6, r4, r8, lsl r1`，非指令。 */
/* @0x1abd84 eoreq r6, r4, r8, lsl r1 */
/* @0x1abd88 .word 0xffffc464 */
/* @0x1abd8c .word 0xffffea30 */
/* @0x1abd90 .word 0xffffc454 */
/* @0x1abd94 .word 0xffffbff4 */
/* @0x1abd98 .word 0xffffc5f4 */

/* ── §2 小结 / open ────────────────────────────────────────────────────
 * 小结：RemoveMarked = 「option 且 >250 → 先拆 g_tree」→ 从 A 链尾逐实例：+0x68 标删才算 →
 *   清 0x542a58 队列 → 层内摘除 → 摘 id 哈希 → 按 +0x69 摘 A 或 B 链 → 删除式析构 → 计数-- →
 *   「option 且 >250 → RebuildTree」→ ms_markedCount 清零。
 *   三个调用点族：DoAStep 0x1d32c0（每帧 3 处）、StartRoom 0x1d38e0（3 处）、EndRoom 0x1d1724（4 处）。
 * open 1: 250 这个门槛的来源（每帧 250 个删除就重建树）未证；它不参与「扫不扫」的判定。
 * open 2: B 分支的可达性依赖「实例仍在 A 链而 +0x69 已置 1」这一瞬时状态；该状态由谁制造未证。
 * open 3: B 路不清 inst+0x178/+0x17c：若 CInstance 内存被池化复用，邻居链指针会看到已删对象（推断）。
 * open 4: 只清 0x542a58 一条队列，另两条（0x542a4c/0x542a64）为何不用清 —— 可能那两条另有消费点
 *         会自己判活（未证）。
 */

/* ── §3 序与标量默认值（0x1ad0a4..0x1ad118）：Clear 的第一件事是把房间改成出厂值
 *  帧 push 9 字 + vpush {d8} + sub sp,#12。写集：+0x10=640、+0xc=30、+0x14=480、+0x1c=0x00C0C0C0、
 *  +0x20=1、+0xc4=0、+0xc8=0、+0xac=0、+0x8=0、+0x18=0、+0x68=0、+0x70=0。
 *  ★ 注意 +0x8/+0x68/+0xac/+0xc4/+0xc8 是**只写 0、不 Free** —— 释放责任在 ~CRoom（§1 ③④）。 */
/* @0x1ad0a4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ad0a8 vpush {d8} */
/* @0x1ad0ac mov r6, r0 */
/* @0x1ad0b0 mov r3, #0 */
/* @0x1ad0b4 mov r8, #1 */
/* @0x1ad0b8 sub sp, sp, #12 */
/* @0x1ad0bc mov r2, #640 */
/* @0x1ad0c0 mov r12, #1065353216 */
/* @0x1ad0c4 str r2, [r6, #0x10] */
/* @0x1ad0c8 mov r4, r3 */
/* @0x1ad0cc mov r2, #30 */
/* @0x1ad0d0 mov lr, r8 */
/* @0x1ad0d4 str r2, [r6, #0xc] */
/* @0x1ad0d8 mov r1, #8 */
/* @0x1ad0dc mvn r7, #0 */
/* @0x1ad0e0 mvn r5, #-16777216 */
/* @0x1ad0e4 mov r2, #0 */
/* @0x1ad0e8 mov r9, #480 */
/* @0x1ad0ec str r3, [r6, #0xc4] */
/* @0x1ad0f0 str r9, [r6, #0x14] */
/* @0x1ad0f4 movw r9, #0xc0c0 */
/* @0x1ad0f8 str r3, [r6, #0xc8] */
/* @0x1ad0fc movt r9, #0xc0 */
/* @0x1ad100 str r3, [r6, #0xac] */
/* @0x1ad104 str r9, [r6, #0x1c] */
/* @0x1ad108 str r3, [r6, #0x8] */
/* @0x1ad10c strb r3, [r6, #0x18] */
/* @0x1ad110 str r3, [r6, #0x68] */
/* @0x1ad114 strb r3, [r6, #0x70] */
/* @0x1ad118 strb r8, [r6, #0x20] */

/* ── §3 八背景复位（0x1ad11c..0x1ad15c）：44 B 记录逐字段重写，不重新分配
 *  r0 从 this 起每轮 +4，读 [r0+0x24] ⇒ 8 格。写：+0x0=0、+0x1=0、+0x4=-1、+0x8=0、+0xc=0、
 *  +0x10=1、+0x11=1、+0x14=0、+0x18=0、+0x1c=1.0f、+0x20=1.0f、+0x24=0xFF000000、+0x28=1.0f。
 *  1.0f = 0x3F800000（r12），-1 = mvn r7,#0，0xFF000000 = mvn r5,#-16777216。 */
/* @0x1ad11c ldr r3, [r0, #0x24] */
/* @0x1ad120 subs r1, r1, #1 */
/* @0x1ad124 add r0, r0, #4 */
/* @0x1ad128 str r2, [r3, #0x8] */
/* @0x1ad12c str r2, [r3, #0xc] */
/* @0x1ad130 str r12, [r3, #0x1c] */
/* @0x1ad134 str r12, [r3, #0x20] */
/* @0x1ad138 strb r4, [r3] */
/* @0x1ad13c str r2, [r3, #0x14] */
/* @0x1ad140 strb r4, [r3, #0x1] */
/* @0x1ad144 str r2, [r3, #0x18] */
/* @0x1ad148 str r7, [r3, #0x4] */
/* @0x1ad14c str r12, [r3, #0x28] */
/* @0x1ad150 strb lr, [r3, #0x10] */
/* @0x1ad154 strb lr, [r3, #0x11] */
/* @0x1ad158 str r5, [r3, #0x24] */
/* @0x1ad15c bne 0x1ad11c <_ZN5CRoom5ClearEv+0x78> */

/* ── §3 视野表头与 Zeus 门（0x1ad160..0x1ad1a0）：g_isZeus 决定要不要销毁相机
 *  0x1ad160 取池字 0x1ad2c4(=0x2407b4) + pc(0x1ad168) = GOT 0x3ed92c → 0x5428e8；
 *  0x1ad18c/0x1ad190 取两个字面量 640.0f/480.0f（s17/s16）填视野记录。+0x44/+0x45/+0x46 三个字节清 0。 */
/* @0x1ad160 ldr r10, [pc, #0x15c] */
/* @0x1ad164 mov r7, r1 */
/* @0x1ad168 mov r8, r1 */
/* @0x1ad16c mov r4, r6 */
/* @0x1ad170 ldr r10, [pc, r10] */
/* @0x1ad174 mov r2, #640 */
/* @0x1ad178 mov r11, #480 */
/* @0x1ad17c strb r1, [r6, #0x44] */
/* @0x1ad180 strb r1, [r6, #0x45] */
/* @0x1ad184 mov r9, #0 */
/* @0x1ad188 strb r1, [r6, #0x46] */
/* @0x1ad18c vldr s17, [pc, #296] */
/* @0x1ad190 vldr s16, [pc, #296] */
/* @0x1ad194 b 0x1ad1a4 <_ZN5CRoom5ClearEv+0x100> */
/* @0x1ad198 cmp r7, #8 */
/* @0x1ad19c add r4, r4, #4 */
/* @0x1ad1a0 beq 0x1ad228 <_ZN5CRoom5ClearEv+0x184> */

/* ── §3 八视野复位（0x1ad1a4..0x1ad1f8）：68 B 记录
 *  写：+0x00=1、+0x04=0、+0x08=0、+0x0c=640.0f、+0x10=480.0f、+0x14=1、+0x18=1、+0x1c=640、
 *  +0x20=480、+0x24=0、+0x28=32、+0x2c=32、+0x30=-1、+0x34=-1、+0x38=-1。
 *  ★ +0x40（相机 id）只在 Zeus 路上被改写（见下一段），非 Zeus 路保留旧值。 */
/* @0x1ad1a4 ldrb r0, [r10] */
/* @0x1ad1a8 mvn r5, #0 */
/* @0x1ad1ac ldr r3, [r4, #0x48] */
/* @0x1ad1b0 mov r1, #32 */
/* @0x1ad1b4 cmp r0, #0 */
/* @0x1ad1b8 add r7, r7, #1 */
/* @0x1ad1bc vstr s17, [r3, #12] */
/* @0x1ad1c0 vstr s16, [r3, #16] */
/* @0x1ad1c4 strb r8, [r3] */
/* @0x1ad1c8 str r9, [r3, #0x4] */
/* @0x1ad1cc str r9, [r3, #0x8] */
/* @0x1ad1d0 str r8, [r3, #0x14] */
/* @0x1ad1d4 str r8, [r3, #0x18] */
/* @0x1ad1d8 str r9, [r3, #0x24] */
/* @0x1ad1dc str r2, [r3, #0x1c] */
/* @0x1ad1e0 str r11, [r3, #0x20] */
/* @0x1ad1e4 str r1, [r3, #0x28] */
/* @0x1ad1e8 str r1, [r3, #0x2c] */
/* @0x1ad1ec str r5, [r3, #0x30] */
/* @0x1ad1f0 str r5, [r3, #0x34] */
/* @0x1ad1f4 str r5, [r3, #0x38] */
/* @0x1ad1f8 beq 0x1ad198 <_ZN5CRoom5ClearEv+0xf4> */

/* ── §3 相机销毁（0x1ad1fc..0x1ad224）：只有 g_isZeus != 0 才走
 *  r0 = GOT 0x3edc7c → 0x48f78c（相机管理器），r1 = view+0x40（相机 id）→ CCameraManager::DestroyCamera(id)；
 *  随后 view+0x40 = -1。非 Zeus 路直接 0x1ad198 跳回循环头，不写 +0x40。
 *  ★ 这是 §1 事件 12 之外第二处 g_isZeus 门控（同一个全局、同一个字节）。 */
/* @0x1ad1fc ldr r0, [pc, #0xc4] */
/* @0x1ad200 add r4, r4, #4 */
/* @0x1ad204 ldr r1, [r3, #0x40] */
/* @0x1ad208 ldr r0, [pc, r0] */
/* @0x1ad20c str r2, [sp, #0x4] */
/* @0x1ad210 bl 0x16f2cc <_ZN14CCameraManager13DestroyCameraEi> */
/* @0x1ad214 ldr r3, [r4, #0x44] */
/* @0x1ad218 cmp r7, #8 */
/* @0x1ad21c ldr r2, [sp, #0x4] */
/* @0x1ad220 str r5, [r3, #0x40] */
/* @0x1ad224 bne 0x1ad1a4 <_ZN5CRoom5ClearEv+0x100> */

/* ── §3 四件套（0x1ad228..0x1ad260）：ClearInstances → ClearDeactiveInstances → id 数组 → ClearTiles → CleanRoomLayers
 *  顺序固定：① ClearInstances（A 链）② ClearDeactiveInstances（B 链）③ Free(+0xa4)、+0xa8=0
 *  ④ ClearTiles（+0xc0 表）⑤ CLayerManager::CleanRoomLayers(this)（层链）。
 *  ★ 先拆实例再拆 tile/层：实例析构期间仍能读到自己所在的 tile 与层。 */
/* @0x1ad228 mov r0, r6 */
/* @0x1ad22c mov r4, #0 */
/* @0x1ad230 bl 0x1ab798 <_ZN5CRoom14ClearInstancesEv> */
/* @0x1ad234 mov r0, r6 */
/* @0x1ad238 bl 0x1ab9c8 <_ZN5CRoom22ClearDeactiveInstancesEv> */
/* @0x1ad23c ldr r0, [r6, #0xa4] */
/* @0x1ad240 str r4, [r6, #0xa8] */
/* @0x1ad244 cmp r0, r4 */
/* @0x1ad248 beq 0x1ad254 <_ZN5CRoom5ClearEv+0x1b0> */
/* @0x1ad24c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad250 str r4, [r6, #0xa4] */
/* @0x1ad254 mov r0, r6 */
/* @0x1ad258 bl 0x1ad060 <_ZN5CRoom10ClearTilesEv> */
/* @0x1ad25c mov r0, r6 */
/* @0x1ad260 bl 0x1b93c8 <_ZN13CLayerManager15CleanRoomLayersEP5CRoom> */

/* ── §3 三张桶数组（0x1ad264..0x1ad2b8）：+0xf4 / +0x108 / +0x120
 *  逐个判空 Free 后写 0（+0xf4 在 0x1ad27c、+0x108 在 0x1ad294、+0x120 在 0x1ad2ac）；
 *  0x1ad298 `str r3,[r6,#0x10c]` 把图 2 与图 3 之间那一格也清 0。
 *  ★ 只放桶数组，不动图内节点（+0xe0/+0x98 这些类型标签也不动）—— 与 §1 死尾的意图正好相反。 */
/* @0x1ad264 ldr r0, [r6, #0xf4] */
/* @0x1ad268 cmp r0, #0 */
/* @0x1ad26c beq 0x1ad274 <_ZN5CRoom5ClearEv+0x1d0> */
/* @0x1ad270 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad274 ldr r0, [r6, #0x108] */
/* @0x1ad278 mov r3, #0 */
/* @0x1ad27c str r3, [r6, #0xf4] */
/* @0x1ad280 cmp r0, r3 */
/* @0x1ad284 beq 0x1ad28c <_ZN5CRoom5ClearEv+0x1e8> */
/* @0x1ad288 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad28c ldr r0, [r6, #0x120] */
/* @0x1ad290 mov r3, #0 */
/* @0x1ad294 str r3, [r6, #0x108] */
/* @0x1ad298 cmp r0, r3 */
/* @0x1ad29c str r3, [r6, #0x10c] */
/* @0x1ad2a0 beq 0x1ad2a8 <_ZN5CRoom5ClearEv+0x204> */
/* @0x1ad2a4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad2a8 mov r3, #0 */
/* @0x1ad2ac str r3, [r6, #0x120] */
/* @0x1ad2b0 add sp, sp, #12 */
/* @0x1ad2b4 vpop {d8} */
/* @0x1ad2b8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── §3 literal pool（0x1ad2bc..0x1ad2c8，4 字；非指令）
 *  0x1ad2bc = 0x44200000 = 640.0f（s17）；0x1ad2c0 = 0x43f00000 = 480.0f（s16）；
 *  0x1ad2c4 = 0x2407b4 → GOT 0x3ed92c（g_isZeus）；0x1ad2c8 = 0x240a6c → GOT 0x3edc7c（相机管理器）。
 *  objdump 译成 `strtmi r0,[r0],#-0` / `mvnsmi r0,#0` / `.word` / `eoreq …`，均非指令。 */
/* @0x1ad2bc strtmi r0, [r0], #-0 */
/* @0x1ad2c0 mvnsmi r0, #0 */
/* @0x1ad2c4 .word 0x002407b4 */
/* @0x1ad2c8 eoreq r0, r4, r12, ror #20 */

/* ── §3 小结 / open ────────────────────────────────────────────────────
 * 小结：Clear = 「写回出厂标量 → 8 背景记录复位 → 8 视野记录复位（Zeus 时销毁相机）→
 *   ClearInstances → ClearDeactiveInstances → Free(id 数组) → ClearTiles → CleanRoomLayers →
 *   释放三张图的桶数组」。它是**唯一**让房间可复用的函数，也是 ctor 第二步就调的那个（ctor 卡 §8）。
 * open 1: +0x10c（图 2/图 3 之间那一格）只有这里写 0，语义未定（ctor 卡 open 2 同款）。
 * open 2: 两个 8 循环都不判空：若 ctor 的 operator new 返回 0（或指针格被外部改脏），这里会解引用空指针。
 * open 3: 视野记录 +0x40 在非 Zeus 路上不清（保留旧相机 id），是否会造成「下一房间复用旧 id」未证。
 * open 4: Clear 之后 +0xac/+0xc4/+0xc8 全 0，而 +0xb0（容器影子）**不清** —— 三格状态不一致，
 *         若之后走 §21 CreateWADStorage 会重写 +0xac/+0xb0，但 +0xb0 的旧值在中间窗口可读（推断）。
 */

/* ── §4 序（0x1ab798..0x1ab7d0）：帧、A 链尾、四个全局
 *  帧 push 10 字（r3..r11,lr）。r5 = this；r4 = room+0x80（A 链尾）；空链 → 0x1ab9a0 只清三格。
 *  0x1ab7a4 取池字（0x1ab9b4 = 0x2464a4）+ pc(0x1ab7ac) = GOT 基址 0x3f1c58，再用四个负偏移取：
 *  r7 = 0x536f28 ms_ID2InstanceE、r10 = 0x542a58、r9 = 0x542a64、r8 = 0x542a4c（三条待办队列）。 */
/* @0x1ab798 push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ab79c mov r5, r0 */
/* @0x1ab7a0 ldr r4, [r0, #0x80] */
/* @0x1ab7a4 ldr r3, [pc, #0x208] */
/* @0x1ab7a8 cmp r4, #0 */
/* @0x1ab7ac add r3, pc, r3 */
/* @0x1ab7b0 beq 0x1ab9a0 <_ZN5CRoom14ClearInstancesEv+0x208> */
/* @0x1ab7b4 ldr r12, [pc, #0x1fc] */
/* @0x1ab7b8 ldr r0, [pc, #0x1fc] */
/* @0x1ab7bc ldr r1, [pc, #0x1fc] */
/* @0x1ab7c0 ldr r2, [pc, #0x1fc] */
/* @0x1ab7c4 ldr r7, [r3, r12] */
/* @0x1ab7c8 ldr r10, [r3, r0] */
/* @0x1ab7cc ldr r9, [r3, r1] */
/* @0x1ab7d0 ldr r8, [r3, r2] */

/* ── §4 循环头（0x1ab7d4..0x1ab7e0）：先存 next，再摘层
 *  r6 = inst+0x178（next，先存）；然后 CLayerManager::RemoveInstance(room, inst)。
 *  ★ 顺序：层 → id 哈希 → 房间链 → 三条待办队列 → 析构。 */
/* @0x1ab7d4 mov r0, r5 */
/* @0x1ab7d8 mov r1, r4 */
/* @0x1ab7dc ldr r6, [r4, #0x178] */
/* @0x1ab7e0 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */

/* ── §4 摘 id 哈希（0x1ab7e4..0x1ab850）：键 = inst+0x78
 *  ldm r7,{r0,r12} 一次取表头两格（桶数组、掩码），idx = (inst+0x78) & mask，桶 8 B {head,tail}；
 *  节点 {prev@+0, next@+4, key@+8}；四路摘链后 MemoryManager::Free(节点)、表计数 +0x8--。
 *  与 §2 的摘除代码逐句同形（同一段内联模板）。 */
/* @0x1ab7e4 ldm r7, {r0, r12} */
/* @0x1ab7e8 ldr r1, [r4, #0x78] */
/* @0x1ab7ec and r12, r1, r12 */
/* @0x1ab7f0 ldr r3, [r0, r12, lsl #3] */
/* @0x1ab7f4 add lr, r0, r12, lsl #3 */
/* @0x1ab7f8 cmp r3, #0 */
/* @0x1ab7fc bne 0x1ab810 <_ZN5CRoom14ClearInstancesEv+0x78> */
/* @0x1ab800 b 0x1ab854 <_ZN5CRoom14ClearInstancesEv+0xbc> */
/* @0x1ab804 ldr r3, [r3, #0x4] */
/* @0x1ab808 cmp r3, #0 */
/* @0x1ab80c beq 0x1ab854 <_ZN5CRoom14ClearInstancesEv+0xbc> */
/* @0x1ab810 ldr r2, [r3, #0x8] */
/* @0x1ab814 cmp r1, r2 */
/* @0x1ab818 bne 0x1ab804 <_ZN5CRoom14ClearInstancesEv+0x6c> */
/* @0x1ab81c ldr r2, [r3] */
/* @0x1ab820 ldr r1, [r3, #0x4] */
/* @0x1ab824 cmp r2, #0 */
/* @0x1ab828 strne r1, [r2, #0x4] */
/* @0x1ab82c ldrne r1, [r3, #0x4] */
/* @0x1ab830 streq r1, [r0, r12, lsl #3] */
/* @0x1ab834 mov r0, r3 */
/* @0x1ab838 cmp r1, #0 */
/* @0x1ab83c streq r2, [lr, #0x4] */
/* @0x1ab840 strne r2, [r1] */
/* @0x1ab844 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ab848 ldr r3, [r7, #0x8] */
/* @0x1ab84c sub r3, r3, #1 */
/* @0x1ab850 str r3, [r7, #0x8] */

/* ── §4 摘 A 链 + 零链 + 删除式析构（0x1ab854..0x1ab894）
 *  prev = inst+0x17c、next = inst+0x178：prev 非 0 → prev->next = next，否则 room+0x80（尾）= next；
 *  next 非 0 → next->prev = prev，否则 room+0x84（头）= prev；然后 inst+0x178/+0x17c = 0；
 *  blx [vtbl+4]、room+0x88--。★ 与 §2 的 A 路逐句同形（含清零两句）。 */
/* @0x1ab854 ldr r3, [r4, #0x17c] */
/* @0x1ab858 mov r0, r4 */
/* @0x1ab85c ldr r2, [r4, #0x178] */
/* @0x1ab860 cmp r3, #0 */
/* @0x1ab864 strne r2, [r3, #0x178] */
/* @0x1ab868 ldrne r2, [r4, #0x178] */
/* @0x1ab86c ldrne r3, [r4, #0x17c] */
/* @0x1ab870 streq r2, [r5, #0x80] */
/* @0x1ab874 cmp r2, #0 */
/* @0x1ab878 streq r3, [r5, #0x84] */
/* @0x1ab87c strne r3, [r2, #0x17c] */
/* @0x1ab880 mov r2, #0 */
/* @0x1ab884 ldr r3, [r4] */
/* @0x1ab888 str r2, [r4, #0x178] */
/* @0x1ab88c str r2, [r4, #0x17c] */
/* @0x1ab890 ldr r3, [r3, #0x4] */
/* @0x1ab894 blx r3 */

/* ── §4 队列 0x542a58 压缩（0x1ab898..0x1ab8f0）
 *  12 B 表 {arr@+0, ?@+4, count@+8}；从 0 到 count-1 把非本实例的元素前移，命中过就 count--。
 *  ★ 三条队列的压缩块是三份逐字重复的代码，只有表地址不同（r10/r9/r8）。 */
/* @0x1ab898 ldr r12, [r10, #0x8] */
/* @0x1ab89c ldr r3, [r5, #0x88] */
/* @0x1ab8a0 cmp r12, #0 */
/* @0x1ab8a4 sub r3, r3, #1 */
/* @0x1ab8a8 str r3, [r5, #0x88] */
/* @0x1ab8ac ble 0x1ab8f4 <_ZN5CRoom14ClearInstancesEv+0x15c> */
/* @0x1ab8b0 ldr r2, [r10] */
/* @0x1ab8b4 mov r11, #0 */
/* @0x1ab8b8 mov r3, r11 */
/* @0x1ab8bc mov r1, r11 */
/* @0x1ab8c0 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab8c4 str r0, [r2, r1, lsl #2] */
/* @0x1ab8c8 ldr r2, [r10] */
/* @0x1ab8cc ldr r0, [r2, r3, lsl #2] */
/* @0x1ab8d0 add r3, r3, #1 */
/* @0x1ab8d4 cmp r4, r0 */
/* @0x1ab8d8 addne r1, r1, #1 */
/* @0x1ab8dc moveq r11, #1 */
/* @0x1ab8e0 cmp r3, r12 */
/* @0x1ab8e4 bne 0x1ab8c0 <_ZN5CRoom14ClearInstancesEv+0x128> */
/* @0x1ab8e8 cmp r11, #0 */
/* @0x1ab8ec subne r3, r3, #1 */
/* @0x1ab8f0 strne r3, [r10, #0x8] */

/* ── §4 队列 0x542a64 压缩（0x1ab8f4..0x1ab940）：同形
 *  0x542a64 = ChangeInstanceTypes 队列（UpdateActiveLists 卡的分派表）。 */
/* @0x1ab8f4 ldr r12, [r9, #0x8] */
/* @0x1ab8f8 cmp r12, #0 */
/* @0x1ab8fc ble 0x1ab944 <_ZN5CRoom14ClearInstancesEv+0x1ac> */
/* @0x1ab900 ldr r2, [r9] */
/* @0x1ab904 mov r11, #0 */
/* @0x1ab908 mov r3, r11 */
/* @0x1ab90c mov r1, r11 */
/* @0x1ab910 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab914 str r0, [r2, r1, lsl #2] */
/* @0x1ab918 ldr r2, [r9] */
/* @0x1ab91c ldr r0, [r2, r3, lsl #2] */
/* @0x1ab920 add r3, r3, #1 */
/* @0x1ab924 cmp r4, r0 */
/* @0x1ab928 addne r1, r1, #1 */
/* @0x1ab92c moveq r11, #1 */
/* @0x1ab930 cmp r3, r12 */
/* @0x1ab934 bne 0x1ab910 <_ZN5CRoom14ClearInstancesEv+0x178> */
/* @0x1ab938 cmp r11, #0 */
/* @0x1ab93c subne r3, r3, #1 */
/* @0x1ab940 strne r3, [r9, #0x8] */

/* ── §4 队列 0x542a4c 压缩（0x1ab944..0x1ab990）：同形
 *  0x542a4c = ProcessActivateDeactveLists 队列（同一张卡的第三张表）。 */
/* @0x1ab944 ldr r12, [r8, #0x8] */
/* @0x1ab948 cmp r12, #0 */
/* @0x1ab94c ble 0x1ab994 <_ZN5CRoom14ClearInstancesEv+0x1fc> */
/* @0x1ab950 ldr r2, [r8] */
/* @0x1ab954 mov r11, #0 */
/* @0x1ab958 mov r3, r11 */
/* @0x1ab95c mov r1, r11 */
/* @0x1ab960 ldr r0, [r2, r3, lsl #2] */
/* @0x1ab964 str r0, [r2, r1, lsl #2] */
/* @0x1ab968 ldr r2, [r8] */
/* @0x1ab96c ldr r0, [r2, r3, lsl #2] */
/* @0x1ab970 add r3, r3, #1 */
/* @0x1ab974 cmp r4, r0 */
/* @0x1ab978 addne r1, r1, #1 */
/* @0x1ab97c moveq r11, #1 */
/* @0x1ab980 cmp r3, r12 */
/* @0x1ab984 bne 0x1ab960 <_ZN5CRoom14ClearInstancesEv+0x1c8> */
/* @0x1ab988 cmp r11, #0 */
/* @0x1ab98c subne r3, r3, #1 */
/* @0x1ab990 strne r3, [r8, #0x8] */

/* ── §4 循环尾与收尾（0x1ab994..0x1ab9b0）：三格清零 + 返回
 *  r6（next）非 0 → r4 = r6 继续；走完把 room+0x88/+0x84/+0x80 全部写 0。
 *  ★ 计数 +0x88 逐条递减后又整体清 0：递减只为循环中可观测，最终值不依赖它。 */
/* @0x1ab994 cmp r6, #0 */
/* @0x1ab998 movne r4, r6 */
/* @0x1ab99c bne 0x1ab7d4 <_ZN5CRoom14ClearInstancesEv+0x3c> */
/* @0x1ab9a0 mov r3, #0 */
/* @0x1ab9a4 str r3, [r5, #0x88] */
/* @0x1ab9a8 str r3, [r5, #0x84] */
/* @0x1ab9ac str r3, [r5, #0x80] */
/* @0x1ab9b0 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── §4 literal pool（0x1ab9b4..0x1ab9c4，5 字；非指令）
 *  0x1ab9b4 = 0x2464a4 → GOT 基址 0x3f1c58（配 0x1ab7ac 的 pc）；
 *  0x1ab9b8 = -0x400c → ms_ID2InstanceE 0x536f28；0x1ab9bc = -0x3bac → 0x542a58；
 *  0x1ab9c0 = -0x4010 → 0x542a64；0x1ab9c4 = -0x4008 → 0x542a4c。
 *  首字被 objdump 译成 `eoreq r6, r4, r4, lsr #9`，其余三个是 `.word`。 */
/* @0x1ab9b4 eoreq r6, r4, r4, lsr #9 */
/* @0x1ab9b8 .word 0xffffbff4 */
/* @0x1ab9bc .word 0xffffc454 */
/* @0x1ab9c0 .word 0xffffbff0 */
/* @0x1ab9c4 .word 0xffffbff8 */

/* ── §5 序（0x1ab9c8..0x1ab9f0）：帧、B 链尾、id 表
 *  帧 push 6 字。r5 = this；r4 = room+0x8c（B 链尾）；空 → 0x1ababc 只清三格。
 *  r6 由池字 0x1abad0(0x242264)+pc(0x1ab9e4) = GOT 0x3edc4c → 0x536f28（ms_ID2InstanceE）。
 *  循环头先存 next = inst+0x178，再 CLayerManager::RemoveInstance(room, inst)。 */
/* @0x1ab9c8 push {r3, r4, r5, r6, r7, lr} */
/* @0x1ab9cc mov r5, r0 */
/* @0x1ab9d0 ldr r4, [r0, #0x8c] */
/* @0x1ab9d4 cmp r4, #0 */
/* @0x1ab9d8 beq 0x1ababc <_ZN5CRoom22ClearDeactiveInstancesEv+0xf4> */
/* @0x1ab9dc ldr r6, [pc, #0xec] */
/* @0x1ab9e0 ldr r6, [pc, r6] */
/* @0x1ab9e4 mov r0, r5 */
/* @0x1ab9e8 mov r1, r4 */
/* @0x1ab9ec ldr r7, [r4, #0x178] */
/* @0x1ab9f0 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */

/* ── §5 摘 id 哈希（0x1ab9f4..0x1aba68）：键 = inst+0x78，形状与 §4 同
 *  唯一差别：掩码与桶数组的取法是 `[r6+4]`/`[r6]` 两次 ldr（§4 用 ldm 一次取两格），语义等价。 */
/* @0x1ab9f4 ldr r12, [r4, #0x78] */
/* @0x1ab9f8 ldr r0, [r6, #0x4] */
/* @0x1ab9fc ldr r1, [r6] */
/* @0x1aba00 and r0, r12, r0 */
/* @0x1aba04 ldr r3, [r1, r0, lsl #3] */
/* @0x1aba08 add lr, r1, r0, lsl #3 */
/* @0x1aba0c cmp r3, #0 */
/* @0x1aba10 bne 0x1aba24 <_ZN5CRoom22ClearDeactiveInstancesEv+0x5c> */
/* @0x1aba14 b 0x1aba6c <_ZN5CRoom22ClearDeactiveInstancesEv+0xa4> */
/* @0x1aba18 ldr r3, [r3, #0x4] */
/* @0x1aba1c cmp r3, #0 */
/* @0x1aba20 beq 0x1aba6c <_ZN5CRoom22ClearDeactiveInstancesEv+0xa4> */
/* @0x1aba24 ldr r2, [r3, #0x8] */
/* @0x1aba28 cmp r12, r2 */
/* @0x1aba2c bne 0x1aba18 <_ZN5CRoom22ClearDeactiveInstancesEv+0x50> */
/* @0x1aba30 ldr r2, [r3] */
/* @0x1aba34 cmp r2, #0 */
/* @0x1aba38 ldrne r1, [r3, #0x4] */
/* @0x1aba3c ldreq r12, [r3, #0x4] */
/* @0x1aba40 strne r1, [r2, #0x4] */
/* @0x1aba44 ldrne r12, [r3, #0x4] */
/* @0x1aba48 streq r12, [r1, r0, lsl #3] */
/* @0x1aba4c mov r0, r3 */
/* @0x1aba50 cmp r12, #0 */
/* @0x1aba54 streq r2, [lr, #0x4] */
/* @0x1aba58 strne r2, [r12] */
/* @0x1aba5c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aba60 ldr r3, [r6, #0x8] */
/* @0x1aba64 sub r3, r3, #1 */
/* @0x1aba68 str r3, [r6, #0x8] */

/* ── §5 摘 B 链 + 删除式析构（0x1aba6c..0x1abaa0）
 *  prev = inst+0x17c、next = inst+0x178；改的是 room+0x8c（尾）/room+0x90（头）；
 *  ★ 与 §4 的 A 路同形，但同样**不清** inst+0x178/+0x17c 两句（B 链一路都不清，见 §2 open 3）。 */
/* @0x1aba6c ldr r3, [r4, #0x17c] */
/* @0x1aba70 mov r0, r4 */
/* @0x1aba74 ldr r2, [r4, #0x178] */
/* @0x1aba78 cmp r3, #0 */
/* @0x1aba7c strne r2, [r3, #0x178] */
/* @0x1aba80 ldrne r3, [r4, #0x17c] */
/* @0x1aba84 ldrne r2, [r4, #0x178] */
/* @0x1aba88 streq r2, [r5, #0x8c] */
/* @0x1aba8c cmp r2, #0 */
/* @0x1aba90 streq r3, [r5, #0x90] */
/* @0x1aba94 strne r3, [r2, #0x17c] */
/* @0x1aba98 ldr r3, [r4] */
/* @0x1aba9c ldr r3, [r3, #0x4] */
/* @0x1abaa0 blx r3 */

/* ── §5 计数与收尾（0x1abaa4..0x1abacc）：room+0x94-- ，走完清三格
 *  ★ 本函数**没有**三条待办队列的压缩段（§4 有）：去激活实例的待办项由 UpdateActive/其它消费点自己判活。 */
/* @0x1abaa4 ldr r3, [r5, #0x94] */
/* @0x1abaa8 cmp r7, #0 */
/* @0x1abaac sub r3, r3, #1 */
/* @0x1abab0 str r3, [r5, #0x94] */
/* @0x1abab4 movne r4, r7 */
/* @0x1abab8 bne 0x1ab9e4 <_ZN5CRoom22ClearDeactiveInstancesEv+0x1c> */
/* @0x1ababc mov r3, #0 */
/* @0x1abac0 str r3, [r5, #0x94] */
/* @0x1abac4 str r3, [r5, #0x90] */
/* @0x1abac8 str r3, [r5, #0x8c] */
/* @0x1abacc pop {r3, r4, r5, r6, r7, pc} */

/* ── §5 literal pool（0x1abad0，1 字；非指令）
 *  0x1abad0 = 0x00242264 → 配 0x1ab9e0 的 pc(0x1ab9e8) = GOT 0x3edc4c → 0x536f28 ms_ID2InstanceE。
 *  objdump 译成 `eoreq r2, r4, r4, ror #4`。 */
/* @0x1abad0 eoreq r2, r4, r4, ror #4 */

/* ── §6 序与分流（0x1ad060..0x1ad070）：+0xc0 表
 *  帧 push {r3,r4,r5,lr}；r4 = this；r5 = room+0xc0（RTile 数据）。subs 判空 → 0x1ad098 的空路。 */
/* @0x1ad060 push {r3, r4, r5, lr} */
/* @0x1ad064 mov r4, r0 */
/* @0x1ad068 ldr r5, [r0, #0xc0] */
/* @0x1ad06c subs r0, r5, #0 */
/* @0x1ad070 beq 0x1ad098 <_ZN5CRoom10ClearTilesEv+0x38> */

/* ── §6 非空路（0x1ad074..0x1ad094）：Free + 三格清零 + 返回
 *  Free(+0xc0) → +0xc0=0 → +0xbc=0（容量）→ +0xb8=0（计数）→ +0x00=-1（最近 tile 下标）。
 *  ★ +0x00 写 -1 只有这里与 §11/§18 的缓存写点，是全库仅有的三处（AddTile 写正下标）。 */
/* @0x1ad074 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad078 mov r3, #0 */
/* @0x1ad07c str r3, [r4, #0xc0] */
/* @0x1ad080 mov r3, #0 */
/* @0x1ad084 mvn r2, #0 */
/* @0x1ad088 str r3, [r4, #0xbc] */
/* @0x1ad08c str r3, [r4, #0xb8] */
/* @0x1ad090 str r2, [r4] */
/* @0x1ad094 pop {r3, r4, r5, pc} */

/* ── §6 空路（0x1ad098..0x1ad0a0）：仍调 Free(0)
 *  r0 仍是 0（subs 留下的），bl Free；str r5(=0),[+0xc0]；b 0x1ad080 汇合到三格清零。
 *  ⇒ 「判空只是为了跳过 Free」，三格清零两条路都做。 */
/* @0x1ad098 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ad09c str r5, [r4, #0xc0] */
/* @0x1ad0a0 b 0x1ad080 <_ZN5CRoom10ClearTilesEv+0x20> */

/* ── §7 序（0x1ab104..0x1ab138）：Free(+0xc4) 后立刻重建一块 4 B 的零
 *  帧 push {r4,lr}；r4 = this。Free(room+0xc4)（**不判空**）；
 *  Alloc(4, "…/Files/Room/Room_Class.cpp", 0x549=1353, true) → *p = 0 → room+0xc4 = p。
 *  文件串：池字 0x1ab13c(0x1a2088) + 0x1ab120 的 pc(0x1ab128) = 0x34d1b0。
 *  ★ 全库 645,282 条指令里没有任何 bl 指向 0x1ab104 ⇒ 本函数**不可达**（facts 9）。
 *  ★ 若可达：CreateWADStorage 后的 +0xc4 是容器内偏移（container+0x5c），这里会把块内地址交给 Free。 */
/* @0x1ab104 push {r4, lr} */
/* @0x1ab108 mov r4, r0 */
/* @0x1ab10c ldr r0, [r0, #0xc4] */
/* @0x1ab110 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ab114 ldr r1, [pc, #0x20] */
/* @0x1ab118 mov r3, #1 */
/* @0x1ab11c mov r0, #4 */
/* @0x1ab120 add r1, pc, r1 */
/* @0x1ab124 movw r2, #0x549 */
/* @0x1ab128 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1ab12c mov r3, #0 */
/* @0x1ab130 str r3, [r0] */
/* @0x1ab134 str r0, [r4, #0xc4] */
/* @0x1ab138 pop {r4, pc} */

/* ── §7 literal pool（0x1ab13c，1 字；非指令）
 *  0x1ab13c = 0x001a2088 → 配 0x1ab120 的 pc(0x1ab128) = 0x34d1b0 = "jni/../jni/yoyo/../../../Files/Room/Room_Class.cpp"。
 *  objdump 译成 `andseq r2, r10, r8, lsl #1`。 */
/* @0x1ab13c andseq r2, r10, r8, lsl #1 */

/* ── §8 全体（0x1ab140，1 条）：`bx lr` —— 空函数
 *  size 4 / 1 条指令，无帧、无全局、无池字。全库无 bl 指向 0x1ab140 ⇒ 不可达。
 *  ★ 语义上它是「清空暂存实例表」的桩：实例暂存走的是 §4/AddInstanceToStorage 的 +0xc8 表，
 *  原版这里留空，说明不需要额外动作（或实现被裁掉）。 */
/* @0x1ab140 bx lr */

/* ── §9 序（0x1abad4..0x1abae4）：只取 A 链尾，空链立即返回
 *  无栈帧（只在进入后 push {r4,lr} 给 bl 对齐）；r0 = room+0x80。 */
/* @0x1abad4 ldr r0, [r0, #0x80] */
/* @0x1abad8 push {r4, lr} */
/* @0x1abadc cmp r0, #0 */
/* @0x1abae0 bne 0x1abaf4 <_ZN5CRoom15CleanPersistentEv+0x20> */
/* @0x1abae4 pop {r4, pc} */

/* ── §9 循环尾（0x1abae8..0x1abaf0）：r4 = next 当游标
 *  下一轮用 r4（上一轮存的 inst+0x178）；r4 == 0 → 0x1abb20 pop 返回。 */
/* @0x1abae8 cmp r4, #0 */
/* @0x1abaec mov r0, r4 */
/* @0x1abaf0 beq 0x1abb20 <_ZN5CRoom15CleanPersistentEv+0x4c> */

/* ── §9 persistent 闸 + 事件 12（0x1abaf4..0x1abb1c）
 *  读 inst+0x67（persistent）：非 0 → Perform_Event(inst, inst, 12, 0)；为 0 → 跳过（0x1abb00 beq）。
 *  ★ 与 §1 ② 的闸门严格互补：那里要求 +0x67/+0x68/+0x69 全 0，这里要求 +0x67 != 0，且**没有** g_isZeus 门。
 *  ★ 唯一调用点：EndRoom 0x1d1724 @0x1d1ac4 —— 换房间时给持久实例跑一次事件 12。 */
/* @0x1abaf4 ldrb r3, [r0, #0x67] */
/* @0x1abaf8 ldr r4, [r0, #0x178] */
/* @0x1abafc cmp r3, #0 */
/* @0x1abb00 beq 0x1abae8 <_ZN5CRoom15CleanPersistentEv+0x14> */
/* @0x1abb04 mov r1, r0 */
/* @0x1abb08 mov r2, #12 */
/* @0x1abb0c mov r3, #0 */
/* @0x1abb10 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1abb14 cmp r4, #0 */
/* @0x1abb18 mov r0, r4 */
/* @0x1abb1c bne 0x1abaf4 <_ZN5CRoom15CleanPersistentEv+0x20> */
/* @0x1abb20 pop {r4, pc} */

/* ── §10 循环头（0x1ac200..0x1ac210）：8 格、跳过空槽
 *  r2 = 8 计数；r0 从 this 起每轮 +4，读 [r0+0x24] ⇒ 背景记录指针；为 0 直接下一格（0x1ac210）。
 *  无栈帧、无池字、无 bl —— 纯算术函数。 */
/* @0x1ac200 mov r2, #8 */
/* @0x1ac204 ldr r3, [r0, #0x24] */
/* @0x1ac208 add r0, r0, #4 */
/* @0x1ac20c cmp r3, #0 */
/* @0x1ac210 beq 0x1ac234 <_ZN5CRoom16ScrollBackgroundEv+0x34> */

/* ── §10 加法（0x1ac214..0x1ac230）：两条 scroll 速度
 *  记录 +0x08 += +0x14（x += speed_x）；记录 +0x0c += +0x18（y += speed_y）。
 *  ★ +0x14/+0x18 是「每帧位移」，不是速度乘 dt：本函数不读任何时间量（DoAStep 每帧调一次，
 *  0x1d3588 是唯一调用点）。 */
/* @0x1ac214 vldr s14, [r3, #8] */
/* @0x1ac218 vldr s15, [r3, #20] */
/* @0x1ac21c vldr s13, [r3, #12] */
/* @0x1ac220 vadd.f32 s14, s14, s15 */
/* @0x1ac224 vldr s15, [r3, #24] */
/* @0x1ac228 vadd.f32 s15, s13, s15 */
/* @0x1ac22c vstr s14, [r3, #8] */
/* @0x1ac230 vstr s15, [r3, #12] */

/* ── §10 尾（0x1ac234..0x1ac23c）：计数递减 + bx lr */
/* @0x1ac234 subs r2, r2, #1 */
/* @0x1ac238 bne 0x1ac204 <_ZN5CRoom16ScrollBackgroundEv+0x4> */
/* @0x1ac23c bx lr */

/* ── §11 序与缓存快路（0x1af2bc..0x1af2d4）：room+0x00 是「最近命中下标」
 *  r3 = room+0x00（缓存）；r4 = room+0xb8（count）。0 <= 缓存 < count 才试快路（0x1af2cc blt / 0x1af2d4 blt）。
 *  ★ room+0x00 的读者在 CRoom_AddTile 卡里记为未找到（其 open 2）；答案就是这里：FindTile 先看它、
 *    并在命中时写回。写点还有 §6 ClearTiles(-1)、§18 FindTileAtDepth(count，见 open 4)。 */
/* @0x1af2bc ldr r3, [r0] */
/* @0x1af2c0 str r4, [sp, #-0x4]! */
/* @0x1af2c4 cmp r3, #0 */
/* @0x1af2c8 ldr r4, [r0, #0xb8] */
/* @0x1af2cc blt 0x1af2d8 <_ZN5CRoom8FindTileEi+0x1c> */
/* @0x1af2d0 cmp r3, r4 */
/* @0x1af2d4 blt 0x1af324 <_ZN5CRoom8FindTileEi+0x68> */

/* ── §11 线性扫描头（0x1af2d8..0x1af2f4）：count <= 0 → -1；先试第 0 条
 *  r2 = room+0xc0（tile 数据）；比较 [r2+0x20]（tile id）与形参。命中跳 0x1af348（写缓存 0）。 */
/* @0x1af2d8 cmp r4, #0 */
/* @0x1af2dc ble 0x1af314 <_ZN5CRoom8FindTileEi+0x58> */
/* @0x1af2e0 ldr r2, [r0, #0xc0] */
/* @0x1af2e4 ldr r3, [r2, #0x20] */
/* @0x1af2e8 cmp r1, r3 */
/* @0x1af2ec movne r3, #0 */
/* @0x1af2f0 bne 0x1af304 <_ZN5CRoom8FindTileEi+0x48> */
/* @0x1af2f4 b 0x1af348 <_ZN5CRoom8FindTileEi+0x8c> */

/* ── §11 扫描体（0x1af2f8..0x1af310）：步长 56 B，比较 +0x20
 *  每条记录 56 B（14 字）；id 在 +0x20（AddTile 用 ++room_maxtileid 写这一格）。 */
/* @0x1af2f8 ldr r12, [r2, #0x20] */
/* @0x1af2fc cmp r1, r12 */
/* @0x1af300 beq 0x1af34c <_ZN5CRoom8FindTileEi+0x90> */
/* @0x1af304 add r3, r3, #1 */
/* @0x1af308 add r2, r2, #56 */
/* @0x1af30c cmp r3, r4 */
/* @0x1af310 bne 0x1af2f8 <_ZN5CRoom8FindTileEi+0x3c> */

/* ── §11 未命中（0x1af314..0x1af320）：返回 -1（不写缓存） */
/* @0x1af314 mvn r3, #0 */
/* @0x1af318 ldr r4, [sp], #4 */
/* @0x1af31c mov r0, r3 */
/* @0x1af320 bx lr */

/* ── §11 快路命中（0x1af324..0x1af344）：直接返回缓存下标
 *  0x1af328 `rsb r12, r3, r3, lsl #3` = 7*i，再 lsl #3 = 56*i ⇒ 与扫描体同一寻址。
 *  ★ 快路命中**不重写**缓存（值本来就相等）。 */
/* @0x1af324 ldr r2, [r0, #0xc0] */
/* @0x1af328 rsb r12, r3, r3, lsl #3 */
/* @0x1af32c add r2, r2, r12, lsl #3 */
/* @0x1af330 ldr r2, [r2, #0x20] */
/* @0x1af334 cmp r2, r1 */
/* @0x1af338 bne 0x1af2d8 <_ZN5CRoom8FindTileEi+0x1c> */
/* @0x1af33c mov r0, r3 */
/* @0x1af340 ldr r4, [sp], #4 */
/* @0x1af344 bx lr */

/* ── §11 扫描命中（0x1af348..0x1af358）：写缓存 + 返回下标
 *  0x1af34c str r3,[r0] 把命中下标写进 room+0x00 ⇒ 下一次同一 tile 走快路。 */
/* @0x1af348 mov r3, #0 */
/* @0x1af34c str r3, [r0] */
/* @0x1af350 mov r0, r3 */
/* @0x1af354 ldr r4, [sp], #4 */
/* @0x1af358 bx lr */

/* ── §12 序与边界（0x1af35c..0x1af380）：i < 0 或 i >= count 直接返回
 *  push {r4..r8,lr}；r6 = i、r8 = this、r7 = count。两条 poplt/popge 早退。
 *  0x1af378 count-1 进 r7：i == count-1 时跳 0x1af3c8（无需搬移，直接收尾）。 */
/* @0x1af35c push {r4, r5, r6, r7, r8, lr} */
/* @0x1af360 subs r6, r1, #0 */
/* @0x1af364 mov r8, r0 */
/* @0x1af368 poplt {r4, r5, r6, r7, r8, pc} */
/* @0x1af36c ldr r7, [r0, #0xb8] */
/* @0x1af370 cmp r6, r7 */
/* @0x1af374 popge {r4, r5, r6, r7, r8, pc} */
/* @0x1af378 sub r7, r7, #1 */
/* @0x1af37c cmp r6, r7 */
/* @0x1af380 bge 0x1af3c8 <_ZN5CRoom10DeleteTileEi+0x6c> */

/* ── §12 搬移（0x1af384..0x1af3c4）：56 B/条 的前移覆盖
 *  r5 = &tiles[i]、r4 = &tiles[i+1]；循环把 records[j+1] 整条搬到 records[j]（4+4+4 字 + 2 字 = 56 B，
 *  三次 ldm/stm 加一次两字收尾）；j 从 i 到 count-2。★ 这是 memmove 的内联展开，不调 memmove@plt。 */
/* @0x1af384 rsb r5, r6, r6, lsl #3 */
/* @0x1af388 ldr r3, [r0, #0xc0] */
/* @0x1af38c add r5, r3, r5, lsl #3 */
/* @0x1af390 add r4, r5, #56 */
/* @0x1af394 mov r12, r5 */
/* @0x1af398 add r6, r6, #1 */
/* @0x1af39c mov r5, r4 */
/* @0x1af3a0 cmp r6, r7 */
/* @0x1af3a4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3a8 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3ac ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3b0 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3b4 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af3b8 stm r12!, {r0, r1, r2, r3} */
/* @0x1af3bc ldm r4, {r0, r1} */
/* @0x1af3c0 stm r12, {r0, r1} */
/* @0x1af3c4 bne 0x1af390 <_ZN5CRoom10DeleteTileEi+0x34> */

/* ── §12 收尾（0x1af3c8..0x1af3f0）：count-- ；归零才 Free
 *  0x1af3cc str r7,[+0xb8]（count-1）；count != 0 → pop 返回；== 0 → Free(tiles)（空指针走 moveq 传 0）、
 *  +0xc0=0、+0xbc=0。★ 与 §6 ClearTiles 的差别：这里保留 room+0x00（最近下标）不动。 */
/* @0x1af3c8 cmp r7, #0 */
/* @0x1af3cc str r7, [r8, #0xb8] */
/* @0x1af3d0 popne {r4, r5, r6, r7, r8, pc} */
/* @0x1af3d4 ldr r0, [r8, #0xc0] */
/* @0x1af3d8 cmp r0, #0 */
/* @0x1af3dc moveq r0, r7 */
/* @0x1af3e0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af3e4 mov r3, #0 */
/* @0x1af3e8 str r7, [r8, #0xc0] */
/* @0x1af3ec str r3, [r8, #0xbc] */
/* @0x1af3f0 pop {r4, r5, r6, r7, r8, pc} */

/* ── §13 序与首趟探测（0x1af3f4..0x1af410）：先看有没有逆序
 *  帧 push 8 字 + sub sp,#80（56 B 的临时记录 + 4 个游标槽）。r7 = count、r2 = 56（字节步长）、
 *  r3 = 0、r4 = count-1、[sp+0x14] = count；0x1af410 跳到比较块。 */
/* @0x1af3f4 push {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af3f8 sub sp, sp, #80 */
/* @0x1af3fc ldr r7, [r0, #0xb8] */
/* @0x1af400 mov r2, #56 */
/* @0x1af404 mov r3, #0 */
/* @0x1af408 sub r4, r7, #1 */
/* @0x1af40c str r7, [sp, #0x14] */
/* @0x1af410 b 0x1af434 <_ZN5CRoom9SortTilesEv+0x40> */

/* ── §13 逆序探测（0x1af414..0x1af430）：比较 depth(+0x1c)
 *  s14 = tiles[i+1]+0x1c、s15 = tiles[i]+0x1c；`vcmpe.f32` 后 bgt 0x1af44c ⇒ 只要出现「后一条 depth 更大」
 *  就转去插入排序；否则继续扫（0x1af434）。
 *  ★ 比较的是 +0x1c 的 float（tile depth）。降序：depth 大的排前面（先画远处）。 */
/* @0x1af414 ldr r12, [r0, #0xc0] */
/* @0x1af418 add r1, r12, r2 */
/* @0x1af41c vldr s14, [r1, #28] */
/* @0x1af420 vldr s15, [r1, #-28] */
/* @0x1af424 vcmpe.f32 s14, s15 */
/* @0x1af428 add r2, r2, #56 */
/* @0x1af42c vmrs APSR_nzcv, fpscr */
/* @0x1af430 bgt 0x1af44c <_ZN5CRoom9SortTilesEv+0x58> */

/* ── §13 首趟尾（0x1af434..0x1af448）：无逆序 → 原样返回
 *  0x1af438 add r3,#1 / cmp r3,r4 / blt 0x1af414；扫完 add sp,#80 → pop → bx lr。
 *  ★ count <= 1 时 r4 = 0 或 -1，0x1af434 的 cmp/blt 直接落空 ⇒ 也走这里返回。 */
/* @0x1af434 cmp r3, r4 */
/* @0x1af438 add r3, r3, #1 */
/* @0x1af43c blt 0x1af414 <_ZN5CRoom9SortTilesEv+0x20> */
/* @0x1af440 add sp, sp, #80 */
/* @0x1af444 pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af448 bx lr */

/* ── §13 插入排序准备（0x1af44c..0x1af46c）：length <= 1 再兜一次
 *  r7 = count；count <= 1 → 0x1af440 返回。i 记在 [sp+0x10]（从 1 起）、当前记录指针 [sp+0xc]、
 *  临时缓冲指针 [sp+0x8] = sp+24。 */
/* @0x1af44c ldr r7, [sp, #0x14] */
/* @0x1af450 cmp r7, #1 */
/* @0x1af454 ble 0x1af440 <_ZN5CRoom9SortTilesEv+0x4c> */
/* @0x1af458 mov r7, #1 */
/* @0x1af45c add r12, r12, #56 */
/* @0x1af460 str r7, [sp, #0x10] */
/* @0x1af464 add r7, sp, #24 */
/* @0x1af468 str r12, [sp, #0xc] */
/* @0x1af46c str r7, [sp, #0x8] */

/* ── §13 外层头（0x1af470..0x1af498）：先判当前记录是否已经有序
 *  s14 = cur+0x1c、s15 = prev+0x1c；`ble 0x1af550`（cur <= prev → 这一条已在位，跳到外层尾）。
 *  ★ 这是「先比较后插入」的短路，省掉有序情况下的搬移。 */
/* @0x1af470 ldr r7, [sp, #0xc] */
/* @0x1af474 vldr s14, [r7, #28] */
/* @0x1af478 vldr s15, [r7, #-28] */
/* @0x1af47c vcmpe.f32 s14, s15 */
/* @0x1af480 mov r9, r7 */
/* @0x1af484 ldr r7, [sp, #0x10] */
/* @0x1af488 sub r11, r9, #56 */
/* @0x1af48c sub r7, r7, #1 */
/* @0x1af490 vmrs APSR_nzcv, fpscr */
/* @0x1af494 str r7, [sp, #0x4] */
/* @0x1af498 ble 0x1af550 <_ZN5CRoom9SortTilesEv+0x15c> */

/* ── §13 找插入位（0x1af49c..0x1af4b8）：内层向后比较
 *  s14 = [r10-0x1c]、s15 = [r9-0x1c]（前一格 depth vs 当前 depth）；`ble 0x1af550` → 找到位。
 *  r10 是被移动的记录指针、r9 是当前记录指针，二者每次各退 56 B。 */
/* @0x1af49c mov r10, r9 */
/* @0x1af4a0 b 0x1af4bc <_ZN5CRoom9SortTilesEv+0xc8> */
/* @0x1af4a4 vldr s14, [r10, #-28] */
/* @0x1af4a8 vldr s15, [r9, #-28] */
/* @0x1af4ac vcmpe.f32 s14, s15 */
/* @0x1af4b0 mov r10, r9 */
/* @0x1af4b4 vmrs APSR_nzcv, fpscr */
/* @0x1af4b8 ble 0x1af550 <_ZN5CRoom9SortTilesEv+0x15c> */

/* ── §13 56 B 搬移（0x1af4bc..0x1af54c）：临时记录 + 三次 ldm/stm
 *  把当前记录整条读到 sp+24（临时），再把 [r10-56, r10) 的整块后移一格，最后把临时写回空位；
 *  每轮 r7（[sp+0x4] 的计数）递减，bne 0x1af4a4 继续比。★ 全是寄存器块搬移，不调 memmove。 */
/* @0x1af4bc mov r5, r9 */
/* @0x1af4c0 add r4, sp, #24 */
/* @0x1af4c4 ldm r5!, {r0, r1, r2, r3} */
/* @0x1af4c8 mov r12, r11 */
/* @0x1af4cc ldr r7, [sp, #0x4] */
/* @0x1af4d0 mov r8, r9 */
/* @0x1af4d4 mov r6, r11 */
/* @0x1af4d8 sub r9, r10, #56 */
/* @0x1af4dc cmp r7, #0 */
/* @0x1af4e0 sub r7, r7, #1 */
/* @0x1af4e4 stm r4!, {r0, r1, r2, r3} */
/* @0x1af4e8 sub r11, r10, #112 */
/* @0x1af4ec ldm r5!, {r0, r1, r2, r3} */
/* @0x1af4f0 str r7, [sp, #0x4] */
/* @0x1af4f4 add r7, sp, #24 */
/* @0x1af4f8 stm r4!, {r0, r1, r2, r3} */
/* @0x1af4fc ldm r5!, {r0, r1, r2, r3} */
/* @0x1af500 stm r4!, {r0, r1, r2, r3} */
/* @0x1af504 ldm r5, {r0, r1} */
/* @0x1af508 stm r4, {r0, r1} */
/* @0x1af50c ldm r12!, {r0, r1, r2, r3} */
/* @0x1af510 stm r8!, {r0, r1, r2, r3} */
/* @0x1af514 ldm r12!, {r0, r1, r2, r3} */
/* @0x1af518 stm r8!, {r0, r1, r2, r3} */
/* @0x1af51c ldm r12!, {r0, r1, r2, r3} */
/* @0x1af520 stm r8!, {r0, r1, r2, r3} */
/* @0x1af524 ldm r12, {r0, r1} */
/* @0x1af528 stm r5, {r0, r1} */
/* @0x1af52c ldm r7!, {r0, r1, r2, r3} */
/* @0x1af530 stm r6!, {r0, r1, r2, r3} */
/* @0x1af534 ldm r7!, {r0, r1, r2, r3} */
/* @0x1af538 stm r6!, {r0, r1, r2, r3} */
/* @0x1af53c ldm r7!, {r0, r1, r2, r3} */
/* @0x1af540 stm r6!, {r0, r1, r2, r3} */
/* @0x1af544 ldm r4, {r0, r1} */
/* @0x1af548 stm r12, {r0, r1} */
/* @0x1af54c bne 0x1af4a4 <_ZN5CRoom9SortTilesEv+0xb0> */

/* ── §13 外层尾（0x1af550..0x1af580）：i++、指针 +56、直到 count
 *  唯一调用点：Draw_Room 0x1b3e98 @0x1b4118（每帧画房间前重排一次）。 */
/* @0x1af550 ldr r7, [sp, #0x10] */
/* @0x1af554 ldr r1, [sp, #0x14] */
/* @0x1af558 add r7, r7, #1 */
/* @0x1af55c str r7, [sp, #0x10] */
/* @0x1af560 ldr r7, [sp, #0xc] */
/* @0x1af564 add r7, r7, #56 */
/* @0x1af568 str r7, [sp, #0xc] */
/* @0x1af56c ldr r7, [sp, #0x10] */
/* @0x1af570 cmp r7, r1 */
/* @0x1af574 bne 0x1af470 <_ZN5CRoom9SortTilesEv+0x7c> */
/* @0x1af578 add sp, sp, #80 */
/* @0x1af57c pop {r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x1af580 bx lr */

/* ── §14 序（0x1af584..0x1af5a0）：算表尾，无帧
 *  r2 = count；<= 0 → bx lr。r3 = tiles；`rsb r2, r2, r2, lsl #3` = 7*count，再 lsl #3 = 56*count
 *  ⇒ 结束指针 = tiles + 56*count（指向最后一条之后）。r1 = 0（要写的字节值）。 */
/* @0x1af584 ldr r2, [r0, #0xb8] */
/* @0x1af588 vmov s14, r1 */
/* @0x1af58c cmp r2, #0 */
/* @0x1af590 bxle lr */
/* @0x1af594 ldr r3, [r0, #0xc0] */
/* @0x1af598 rsb r2, r2, r2, lsl #3 */
/* @0x1af59c mov r1, #0 */
/* @0x1af5a0 add r2, r3, r2, lsl #3 */

/* ── §14 循环体（0x1af5a4..0x1af5bc）：depth 相等才写 +0x34=0
 *  s15 = [r3+0x1c]（depth）与形参 float 比；`strbeq r1,[r3,#-0x4]`：r3 已 +56，故写到 record+0x34。
 *  ⇒ tile 记录 +0x34 = 可见性字节，Hide 写 0。★ 与 §15 只差 r1 的初值（0 vs 1）。 */
/* @0x1af5a4 vldr s15, [r3, #28] */
/* @0x1af5a8 vcmp.f32 s15, s14 */
/* @0x1af5ac add r3, r3, #56 */
/* @0x1af5b0 vmrs APSR_nzcv, fpscr */
/* @0x1af5b4 strbeq r1, [r3, #-0x4] */
/* @0x1af5b8 cmp r3, r2 */
/* @0x1af5bc bne 0x1af5a4 <_ZN5CRoom14HideTilesDepthEf+0x20> */
/* @0x1af5c0 bx lr */

/* ── §15 序（0x1af5c4..0x1af5e0）：与 §14 逐字同形，只有 r1 = 1 */
/* @0x1af5c4 ldr r2, [r0, #0xb8] */
/* @0x1af5c8 vmov s14, r1 */
/* @0x1af5cc cmp r2, #0 */
/* @0x1af5d0 bxle lr */
/* @0x1af5d4 ldr r3, [r0, #0xc0] */
/* @0x1af5d8 rsb r2, r2, r2, lsl #3 */
/* @0x1af5dc mov r1, #1 */
/* @0x1af5e0 add r2, r3, r2, lsl #3 */

/* ── §15 循环体（0x1af5e4..0x1af5fc）：depth 相等写 +0x34=1 */
/* @0x1af5e4 vldr s15, [r3, #28] */
/* @0x1af5e8 vcmp.f32 s15, s14 */
/* @0x1af5ec add r3, r3, #56 */
/* @0x1af5f0 vmrs APSR_nzcv, fpscr */
/* @0x1af5f4 strbeq r1, [r3, #-0x4] */
/* @0x1af5f8 cmp r3, r2 */
/* @0x1af5fc bne 0x1af5e4 <_ZN5CRoom14ShowTilesDepthEf+0x20> */
/* @0x1af600 bx lr */

/* ── §16 序与空表（0x1af604..0x1af618）：count <= 0 → 0x1af6b8
 *  帧 push 8 字；s14 = 形参 depth；r8 = count、r9 = this、r7 = tiles。 */
/* @0x1af604 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1af608 vmov s14, r1 */
/* @0x1af60c ldr r8, [r0, #0xb8] */
/* @0x1af610 mov r9, r0 */
/* @0x1af614 cmp r8, #0 */
/* @0x1af618 ble 0x1af6b8 <_ZN5CRoom16DeleteTilesDepthEf+0xb4> */

/* ── §16 循环头（0x1af61c..0x1af650）：r6 = 写游标，r5 = 读指针 +0x1c
 *  r8 = tiles + 56*count + 0x1c（结束指针）、r5 = tiles + 0x1c（depth 槽）、r4 = r5 - 0x1c（记录首字节）。
 *  `vcmp` 比 depth，beq 0x1af678 ⇒ 相等就跳过搬移（即删除）。 */
/* @0x1af61c ldr r7, [r0, #0xc0] */
/* @0x1af620 rsb r8, r8, r8, lsl #3 */
/* @0x1af624 mov r6, #0 */
/* @0x1af628 add r8, r7, r8, lsl #3 */
/* @0x1af62c add r5, r7, #28 */
/* @0x1af630 add r8, r8, #28 */
/* @0x1af634 vldr s15, [r5] */
/* @0x1af638 vcmp.f32 s15, s14 */
/* @0x1af63c rsb r12, r6, r6, lsl #3 */
/* @0x1af640 sub r4, r5, #28 */
/* @0x1af644 add r5, r5, #56 */
/* @0x1af648 add r12, r7, r12, lsl #3 */
/* @0x1af64c vmrs APSR_nzcv, fpscr */
/* @0x1af650 beq 0x1af678 <_ZN5CRoom16DeleteTilesDepthEf+0x74> */

/* ── §16 搬移（0x1af654..0x1af674）：整条 56 B 前移到游标
 *  三次 ldm/stm（48 B）+ 一次两字（8 B）；r6（写游标）++。
 *  ★ 与 §12 DeleteTile 的搬移同形，但这里是「过滤式压缩」而不是删单条。 */
/* @0x1af654 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af658 add r6, r6, #1 */
/* @0x1af65c stm r12!, {r0, r1, r2, r3} */
/* @0x1af660 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af664 stm r12!, {r0, r1, r2, r3} */
/* @0x1af668 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af66c stm r12!, {r0, r1, r2, r3} */
/* @0x1af670 ldm r4, {r0, r1} */
/* @0x1af674 stm r12, {r0, r1} */

/* ── §16 循环尾与清零（0x1af678..0x1af688）：count = 写游标
 *  `cmp r5,r8 / bne 0x1af634`；走完 str r6,[+0xb8]；count != 0 → pop 返回（0x1af688 popne）。 */
/* @0x1af678 cmp r5, r8 */
/* @0x1af67c bne 0x1af634 <_ZN5CRoom16DeleteTilesDepthEf+0x30> */
/* @0x1af680 cmp r6, #0 */
/* @0x1af684 str r6, [r9, #0xb8] */
/* @0x1af688 popne {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── §16 全删收尾（0x1af68c..0x1af6a8）：count == 0 → Free 表
 *  subs r0,r7,#0 → 非 0 → Free(tiles)；+0xc0=0、+0xbc=0；pop。 */
/* @0x1af68c subs r0, r7, #0 */
/* @0x1af690 beq 0x1af6ac <_ZN5CRoom16DeleteTilesDepthEf+0xa8> */
/* @0x1af694 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af698 mov r3, #0 */
/* @0x1af69c str r3, [r9, #0xc0] */
/* @0x1af6a0 mov r3, #0 */
/* @0x1af6a4 str r3, [r9, #0xbc] */
/* @0x1af6a8 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── §16 空指针路（0x1af6ac..0x1af6b4）：tiles == 0 也调 Free(0)
 *  bl Free（r0 仍是 0）；str r7,[+0xc0]（=0）；b 0x1af6a0 汇合到 +0xbc=0。 */
/* @0x1af6ac bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af6b0 str r7, [r9, #0xc0] */
/* @0x1af6b4 b 0x1af6a0 <_ZN5CRoom16DeleteTilesDepthEf+0x9c> */

/* ── §16 count==0 直接进收尾（0x1af6b8..0x1af6c4）
 *  把 +0xb8 写 0、r7 = tiles、跳 0x1af68c 走同一条 Free 路。★ 与 §19 的空表处理逐字同形。 */
/* @0x1af6b8 mov r3, #0 */
/* @0x1af6bc ldr r7, [r0, #0xc0] */
/* @0x1af6c0 str r3, [r0, #0xb8] */
/* @0x1af6c4 b 0x1af68c <_ZN5CRoom16DeleteTilesDepthEf+0x88> */

/* ── §17 序（0x1af6c8..0x1af6ec）：三个 float 进 s14/s12/s11，无帧
 *  s14 = depth、s12 = dx、s11 = dy；r1 = count；<= 0 → bx lr；r2 = tiles + 56*count + 0x1c（尾）。 */
/* @0x1af6c8 vmov s14, r1 */
/* @0x1af6cc ldr r1, [r0, #0xb8] */
/* @0x1af6d0 vmov s12, r2 */
/* @0x1af6d4 cmp r1, #0 */
/* @0x1af6d8 vmov s11, r3 */
/* @0x1af6dc bxle lr */
/* @0x1af6e0 ldr r3, [r0, #0xc0] */
/* @0x1af6e4 rsb r1, r1, r1, lsl #3 */
/* @0x1af6e8 add r2, r3, r1, lsl #3 */
/* @0x1af6ec add r3, r3, #28 */
/* @0x1af6f0 add r2, r2, #28 */

/* ── §17 比较（0x1af6f4..0x1af700）：depth 不等 → 下一条
 *  s15 = [r3]（record+0x1c）与 s14 比；bne 0x1af71c。 */
/* @0x1af6f4 vldr s15, [r3] */
/* @0x1af6f8 vcmp.f32 s15, s14 */
/* @0x1af6fc vmrs APSR_nzcv, fpscr */
/* @0x1af700 bne 0x1af71c <_ZN5CRoom15ShiftTilesDepthEfff+0x54> */

/* ── §17 加法（0x1af704..0x1af718）：改 x/y，不改 depth
 *  s13 = [r3-0x1c]（record+0x00）、s15 = [r3-0x18]（record+0x04）；分别 += dx、dy 再写回。
 *  ⇒ 「按深度平移一批 tile」，把同一 depth 的整层挪位。 */
/* @0x1af704 vldr s13, [r3, #-28] */
/* @0x1af708 vldr s15, [r3, #-24] */
/* @0x1af70c vadd.f32 s13, s13, s12 */
/* @0x1af710 vadd.f32 s15, s15, s11 */
/* @0x1af714 vstr s13, [r3, #-28] */
/* @0x1af718 vstr s15, [r3, #-24] */

/* ── §17 尾（0x1af71c..0x1af728）：+56 直到尾指针 */
/* @0x1af71c add r3, r3, #56 */
/* @0x1af720 cmp r3, r2 */
/* @0x1af724 bne 0x1af6f4 <_ZN5CRoom15ShiftTilesDepthEfff+0x2c> */
/* @0x1af728 bx lr */

/* ── §18 序（0x1af72c..0x1af744）：三个 float 进 s11/s9/s8
 *  s11 = depth、s9 = x、s8 = y；r1 = count；<= 0 → 0x1af854（返回 -1）。 */
/* @0x1af72c vmov s11, r1 */
/* @0x1af730 ldr r1, [r0, #0xb8] */
/* @0x1af734 str r4, [sp, #-0x4]! */
/* @0x1af738 cmp r1, #0 */
/* @0x1af73c vmov s9, r2 */
/* @0x1af740 vmov s8, r3 */
/* @0x1af744 ble 0x1af854 <_ZN5CRoom15FindTileAtDepthEfff+0x128> */

/* ── §18 常量与指针（0x1af748..0x1af75c）：0.5 与 FLT_MAX
 *  s7 = 0.5f（`vmov.f32 s7,#5.000000e-01` 立即数形式，无池字）；r12 = -1（未命中哨兵）、r2 = 0（下标）、
 *  r3 = tiles + 0x28；s6 = [pc,#248] → 池字 0x1af85c = 0x7f7fffff = FLT_MAX（最小距离初值）。 */
/* @0x1af748 vmov.f32 s7, #5.000000e-01 */
/* @0x1af74c ldr r3, [r0, #0xc0] */
/* @0x1af750 mvn r12, #0 */
/* @0x1af754 mov r2, #0 */
/* @0x1af758 add r3, r3, #40 */
/* @0x1af75c vldr s6, [pc, #248] */

/* ── §18 depth 闸（0x1af760..0x1af76c）：只处理同深度
 *  s15 = [r3-0x0c]（r3 = record+0x28 ⇒ record+0x1c）与 s11 比；bne 0x1af830（下一条）。 */
/* @0x1af760 vldr s15, [r3, #-12] */
/* @0x1af764 vcmp.f32 s15, s11 */
/* @0x1af768 vmrs APSR_nzcv, fpscr */
/* @0x1af76c bne 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */

/* ── §18 AABB（0x1af770..0x1af7a0）：x1/y1 = pos + 尺寸×缩放
 *  s5 = (float)(int)record+0x14；x1 = record+0x00 + s5 * record+0x24；
 *  s5 = (float)(int)record+0x18；y1 = record+0x04 + s5 * record+0x28。
 *  ⇒ +0x14/+0x18 读作宽/高（int）、+0x24/+0x28 读作 xscale/yscale（float），是唯一自洽解释（字段名 open 5）。 */
/* @0x1af770 vldr s5, [r3, #-20] */
/* @0x1af774 vcvt.f32.s32 s10, s5 */
/* @0x1af778 vldr s15, [r3, #-40] */
/* @0x1af77c vldr s13, [r3, #-4] */
/* @0x1af780 vldr s14, [r3, #-36] */
/* @0x1af784 vldr s12, [r3] */
/* @0x1af788 vmov.f32 s5, s15 */
/* @0x1af78c vmla.f32 s5, s10, s13 */
/* @0x1af790 vmov.f32 s13, s5 */
/* @0x1af794 vldr s5, [r3, #-16] */
/* @0x1af798 vcvt.f32.s32 s10, s5 */
/* @0x1af79c vmov.f32 s5, s14 */
/* @0x1af7a0 vmla.f32 s5, s10, s12 */

/* ── §18 归一化与包含判定（0x1af7a4..0x1af7fc）：四条比较
 *  先把 x1>x2 / y1>y2 两种情形交换（`vmovle` 三连换），得到 x1<=x2、y1<=y2；然后：
 *  x1 > x → 跳过；x2 <= x → 跳过；y1 > y → 跳过；y2 <= y → 跳过。⇒ **严格包含**（左闭右开）。
 *  ★ 与 §19 的判定块互为镜像（那里把「跳过」换成「落进压缩块」）。 */
/* @0x1af7a4 vcmpe.f32 s15, s13 */
/* @0x1af7a8 vmrs APSR_nzcv, fpscr */
/* @0x1af7ac vcmpe.f32 s14, s5 */
/* @0x1af7b0 vmovle.f32 s10, s13 */
/* @0x1af7b4 vmovle.f32 s13, s15 */
/* @0x1af7b8 vmovle.f32 s15, s10 */
/* @0x1af7bc vmrs APSR_nzcv, fpscr */
/* @0x1af7c0 vcmpe.f32 s13, s9 */
/* @0x1af7c4 vmovle.f32 s10, s5 */
/* @0x1af7c8 vmov.f32 s12, s5 */
/* @0x1af7cc vmovle.f32 s12, s14 */
/* @0x1af7d0 vmovle.f32 s14, s10 */
/* @0x1af7d4 vmrs APSR_nzcv, fpscr */
/* @0x1af7d8 bhi 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7dc vcmpe.f32 s15, s9 */
/* @0x1af7e0 vmrs APSR_nzcv, fpscr */
/* @0x1af7e4 ble 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7e8 vcmpe.f32 s12, s8 */
/* @0x1af7ec vmrs APSR_nzcv, fpscr */
/* @0x1af7f0 bhi 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */
/* @0x1af7f4 vcmpe.f32 s14, s8 */
/* @0x1af7f8 vmrs APSR_nzcv, fpscr */
/* @0x1af7fc ble 0x1af830 <_ZN5CRoom15FindTileAtDepthEfff+0x104> */

/* ── §18 距离（0x1af800..0x1af82c）：取最近中心
 *  cx = (x1+x2)*0.5、cy = (y1+y2)*0.5；d² = (x-cx)² + (y-cy)²；`vcmpe s15,s6` + vmovmi 更新 s6/r12。
 *  ★ 比较用 `vcmpe` + `vmovmi`（d² < best）⇒ 严格小于，等距时保留先出现的那条。 */
/* @0x1af800 vadd.f32 s14, s12, s14 */
/* @0x1af804 vmov.f32 s12, s8 */
/* @0x1af808 vnmls.f32 s12, s14, s7 */
/* @0x1af80c vadd.f32 s15, s13, s15 */
/* @0x1af810 vmov.f32 s14, s9 */
/* @0x1af814 vnmls.f32 s14, s15, s7 */
/* @0x1af818 vmul.f32 s15, s12, s12 */
/* @0x1af81c vmla.f32 s15, s14, s14 */
/* @0x1af820 vcmpe.f32 s15, s6 */
/* @0x1af824 vmrs APSR_nzcv, fpscr */
/* @0x1af828 vmovmi.f32 s6, s15 */
/* @0x1af82c movmi r12, r2 */

/* ── §18 循环尾与返回（0x1af830..0x1af850）：写缓存 + 返回哨兵
 *  r2++、r3 += 56、cmp r2,r1、bne 0x1af760。结束时 `cmn r12,#1`（== -1？）→ `strne r2,[r0]` 写 room+0x00。
 *  ★ 此处 r2 == count（循环跑到底），写进去的是 **count 而不是命中下标** —— 见 open 4。 */
/* @0x1af830 add r2, r2, #1 */
/* @0x1af834 add r3, r3, #56 */
/* @0x1af838 cmp r2, r1 */
/* @0x1af83c bne 0x1af760 <_ZN5CRoom15FindTileAtDepthEfff+0x34> */
/* @0x1af840 cmn r12, #1 */
/* @0x1af844 strne r2, [r0] */
/* @0x1af848 mov r0, r12 */
/* @0x1af84c ldr r4, [sp], #4 */
/* @0x1af850 bx lr */

/* ── §18 空表（0x1af854..0x1af858）：r12 = -1 后 b 0x1af848 返回 -1 */
/* @0x1af854 mvn r12, #0 */
/* @0x1af858 b 0x1af848 <_ZN5CRoom15FindTileAtDepthEfff+0x11c> */

/* ── §18 literal pool（0x1af85c，1 字；非指令）
 *  0x1af85c = 0x7f7fffff = FLT_MAX，配 0x1af75c 的 pc(0x1af764)。objdump 译成 `svcvc #0x7fffff`。 */
/* @0x1af85c svcvc #0x7fffff */

/* ── §19 序（0x1af860..0x1af87c）：三个 float + 空表
 *  帧 push 8 字；s11 = depth、s9 = x、s8 = y；r8 = count、r9 = this；<= 0 → 0x1af9ac。 */
/* @0x1af860 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1af864 vmov s11, r1 */
/* @0x1af868 ldr r8, [r0, #0xb8] */
/* @0x1af86c mov r9, r0 */
/* @0x1af870 vmov s9, r2 */
/* @0x1af874 cmp r8, #0 */
/* @0x1af878 vmov s8, r3 */
/* @0x1af87c ble 0x1af9ac <_ZN5CRoom18DeleteTilesAtDepthEfff+0x14c> */

/* ── §19 循环头（0x1af880..0x1af8a4）：r6 = 写游标、r5 = record+0x28
 *  r7 = tiles；r8 = tiles + 56*count + 0x28（尾）；r5 = tiles + 0x28；depth 槽是 [r5-0x0c]。 */
/* @0x1af880 ldr r7, [r0, #0xc0] */
/* @0x1af884 rsb r8, r8, r8, lsl #3 */
/* @0x1af888 mov r6, #0 */
/* @0x1af88c add r8, r7, r8, lsl #3 */
/* @0x1af890 add r5, r7, #40 */
/* @0x1af894 add r8, r8, #40 */

/* ── §19 depth 闸（0x1af898..0x1af8a4）：不等 → 0x1af938（压缩块）
 *  ★ 注意方向：depth **不等**也跳进 0x1af938 —— 那是「保留并搬移」的块，不是跳过。 */
/* @0x1af898 vldr s15, [r5, #-12] */
/* @0x1af89c vcmp.f32 s15, s11 */
/* @0x1af8a0 vmrs APSR_nzcv, fpscr */
/* @0x1af8a4 bne 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */

/* ── §19 AABB（0x1af8a8..0x1af8d8）：与 §18 逐字段同形
 *  x1 = record+0x00 + (int)record+0x14 * record+0x24；y1 同构用 +0x18/+0x28。 */
/* @0x1af8a8 vldr s7, [r5, #-20] */
/* @0x1af8ac vcvt.f32.s32 s10, s7 */
/* @0x1af8b0 vldr s15, [r5, #-40] */
/* @0x1af8b4 vldr s13, [r5, #-4] */
/* @0x1af8b8 vldr s14, [r5, #-36] */
/* @0x1af8bc vldr s12, [r5] */
/* @0x1af8c0 vmov.f32 s7, s15 */
/* @0x1af8c4 vmla.f32 s7, s10, s13 */
/* @0x1af8c8 vmov.f32 s13, s7 */
/* @0x1af8cc vldr s7, [r5, #-16] */
/* @0x1af8d0 vcvt.f32.s32 s10, s7 */
/* @0x1af8d4 vmov.f32 s7, s14 */
/* @0x1af8d8 vmla.f32 s7, s10, s12 */

/* ── §19 归一化（0x1af8dc..0x1af90c）：交换 x/y 两端
 *  四个 `vmovle` 把 (x1,x2)、(y1,y2) 排成升序，与 §18 一致。 */
/* @0x1af8dc vcmpe.f32 s15, s13 */
/* @0x1af8e0 vmrs APSR_nzcv, fpscr */
/* @0x1af8e4 vcmpe.f32 s14, s7 */
/* @0x1af8e8 vmovle.f32 s10, s13 */
/* @0x1af8ec vmovle.f32 s13, s15 */
/* @0x1af8f0 vmovle.f32 s15, s10 */
/* @0x1af8f4 vmrs APSR_nzcv, fpscr */
/* @0x1af8f8 vcmpe.f32 s13, s9 */
/* @0x1af8fc vmovle.f32 s10, s7 */
/* @0x1af900 vmov.f32 s12, s7 */
/* @0x1af904 vmovle.f32 s12, s14 */
/* @0x1af908 vmovle.f32 s14, s10 */
/* @0x1af90c vmrs APSR_nzcv, fpscr */

/* ── §19 包含判定（0x1af910..0x1af934）：四条比较，全部落向压缩块
 *  x1 > x → 0x1af938；x2 <= x → 0x1af938；y1 > y → 0x1af938；y2 > y → 0x1af968（**跳过压缩**）。
 *  ⇒ 删除条件 = x1<=x<x2 且 y1<=y<y2，与 §18 的包含判定完全一致（此处「不满足即保留」）。 */
/* @0x1af910 bgt 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af914 vcmpe.f32 s15, s9 */
/* @0x1af918 vmrs APSR_nzcv, fpscr */
/* @0x1af91c bls 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af920 vcmpe.f32 s12, s8 */
/* @0x1af924 vmrs APSR_nzcv, fpscr */
/* @0x1af928 bgt 0x1af938 <_ZN5CRoom18DeleteTilesAtDepthEfff+0xd8> */
/* @0x1af92c vcmpe.f32 s14, s8 */
/* @0x1af930 vmrs APSR_nzcv, fpscr */
/* @0x1af934 bhi 0x1af968 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x108> */

/* ── §19 压缩搬移（0x1af938..0x1af964）：保留的条目前移
 *  三次 ldm/stm + 两字收尾；r6（游标）++。★ 与 §16 的搬移同形。 */
/* @0x1af938 sub r4, r5, #40 */
/* @0x1af93c rsb r12, r6, r6, lsl #3 */
/* @0x1af940 add r6, r6, #1 */
/* @0x1af944 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af948 add r12, r7, r12, lsl #3 */
/* @0x1af94c stm r12!, {r0, r1, r2, r3} */
/* @0x1af950 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af954 stm r12!, {r0, r1, r2, r3} */
/* @0x1af958 ldm r4!, {r0, r1, r2, r3} */
/* @0x1af95c stm r12!, {r0, r1, r2, r3} */
/* @0x1af960 ldm r4, {r0, r1} */
/* @0x1af964 stm r12, {r0, r1} */

/* ── §19 循环尾（0x1af968..0x1af970）：r5 += 56 直到尾指针 */
/* @0x1af968 add r5, r5, #56 */
/* @0x1af96c cmp r5, r8 */
/* @0x1af970 bne 0x1af898 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x38> */

/* ── §19 收尾（0x1af974..0x1af99c）：count = 游标，count==0 才 Free
 *  str r6,[+0xb8]；popne 早退；否则 Free(tiles) → +0xc0=0、+0xbc=0。 */
/* @0x1af974 cmp r6, #0 */
/* @0x1af978 str r6, [r9, #0xb8] */
/* @0x1af97c popne {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1af980 subs r0, r7, #0 */
/* @0x1af984 beq 0x1af9a0 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x140> */
/* @0x1af988 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af98c mov r3, #0 */
/* @0x1af990 str r3, [r9, #0xc0] */
/* @0x1af994 mov r3, #0 */
/* @0x1af998 str r3, [r9, #0xbc] */
/* @0x1af99c pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── §19 空指针路（0x1af9a0..0x1af9a8）：Free(0) 后汇合 */
/* @0x1af9a0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1af9a4 str r7, [r9, #0xc0] */
/* @0x1af9a8 b 0x1af994 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x134> */

/* ── §19 空表路（0x1af9ac..0x1af9b8）：+0xb8=0 → 直接走 Free 收尾 */
/* @0x1af9ac mov r3, #0 */
/* @0x1af9b0 ldr r7, [r0, #0xc0] */
/* @0x1af9b4 str r3, [r0, #0xb8] */
/* @0x1af9b8 b 0x1af980 <_ZN5CRoom18DeleteTilesAtDepthEfff+0x120> */

/* ── §20 序（0x1af9bc..0x1af9dc）：两个 float，无帧
 *  s14 = 旧 depth（r1）、r2 = 新 depth（原样留在整数寄存器）；r12 = count；<= 0 → bx lr；
 *  r3 = tiles + 0x1c（第一条的 depth 槽）、r1 = tiles + 56*count + 0x1c（尾）。 */
/* @0x1af9bc ldr r12, [r0, #0xb8] */
/* @0x1af9c0 vmov s14, r1 */
/* @0x1af9c4 cmp r12, #0 */
/* @0x1af9c8 bxle lr */
/* @0x1af9cc ldr r3, [r0, #0xc0] */
/* @0x1af9d0 rsb r12, r12, r12, lsl #3 */
/* @0x1af9d4 add r1, r3, r12, lsl #3 */
/* @0x1af9d8 add r3, r3, #28 */
/* @0x1af9dc add r1, r1, #28 */

/* ── §20 循环体（0x1af9e0..0x1af9f8）：相等就把新值写回 depth 槽
 *  `streq r2,[r3,#-0x38]`：r3 已 +56，故写到 record+0x1c —— **改的是 depth 本身**（不是 x）。
 *  ⇒ ChangeTilesDepth(old, new)：把整层的 depth 换成 new。
 *  ★ 与 §14/§15（改 +0x34 可见性）、§17（改 x/y）三者共用同一「按 depth 选择」的模板。 */
/* @0x1af9e0 vldr s15, [r3] */
/* @0x1af9e4 vcmp.f32 s15, s14 */
/* @0x1af9e8 add r3, r3, #56 */
/* @0x1af9ec vmrs APSR_nzcv, fpscr */
/* @0x1af9f0 streq r2, [r3, #-0x38] */
/* @0x1af9f4 cmp r3, r1 */
/* @0x1af9f8 bne 0x1af9e0 <_ZN5CRoom16ChangeTilesDepthEff+0x24> */
/* @0x1af9fc bx lr */

/* ── §21 序与 96 B 容器（0x1a92c0..0x1a92f8）：Alloc + memset
 *  帧 push 6 字；r6 = this、r7 = 文件串 0x34d1b0（池字 0x1a9384=0x1a3ed0 + 0x1a92d8 的 pc 0x1a92e0）、
 *  r0 = 96、r1 = 串、r2 = 111、r3 = 1 → Alloc(96, "…/Room_Class.cpp", 111, true) → room+0xac；
 *  然后 memset(container, 0, 88)（r8 = 88，只清前 88 B，后 8 B 靠下面的字段写覆盖）。 */
/* @0x1a92c0 push {r4, r5, r6, r7, r8, lr} */
/* @0x1a92c4 mov r3, #1 */
/* @0x1a92c8 ldr r7, [pc, #0xb4] */
/* @0x1a92cc mov r6, r0 */
/* @0x1a92d0 mov r2, #111 */
/* @0x1a92d4 mov r0, #96 */
/* @0x1a92d8 add r7, pc, r7 */
/* @0x1a92dc mov r4, #0 */
/* @0x1a92e0 mov r8, #88 */
/* @0x1a92e4 mov r1, r7 */
/* @0x1a92e8 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a92ec mov r2, r8 */
/* @0x1a92f0 mov r1, r4 */
/* @0x1a92f4 str r0, [r6, #0xac] */
/* @0x1a92f8 bl 0xb65b0 <memset@plt> */

/* ── §21 容器字段（0x1a92fc..0x1a9324）：三格常量 + 影子格
 *  room+0xb0 = 同一指针（+0xac 的影子）；container+0x10 = 30、+0x30 = 88、+0x34 = 92。
 *  ★ +0x30/+0x34 恰好是 memset 的 88 与 92 —— 一块「自身描述」的容器头。 */
/* @0x1a92fc ldr r5, [r6, #0xac] */
/* @0x1a9300 mov lr, #92 */
/* @0x1a9304 mov r12, #30 */
/* @0x1a9308 mov r1, r7 */
/* @0x1a930c mov r2, #121 */
/* @0x1a9310 str r5, [r6, #0xb0] */
/* @0x1a9314 mov r3, #1 */
/* @0x1a9318 str lr, [r5, #0x34] */
/* @0x1a931c mov r0, #4 */
/* @0x1a9320 str r12, [r5, #0x10] */
/* @0x1a9324 str r8, [r5, #0x30] */

/* ── §21 第一块 4 B（0x1a9328..0x1a9350）：Alloc(4, …, 121, true) → container+0x58
 *  随后用 4 条 strb 把它清零（`strb r4,[r3],#1` 会写 1 字节并把 r3 加 1，故 0x1a9340 的 add 是跳过 1 字节）。
 *  ★ 4 条 strb 的偏移分别是 0、1、2、3（r3 递增链），不是重复写同一格。 */
/* @0x1a9328 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a932c mov r1, r7 */
/* @0x1a9330 mov r2, #124 */
/* @0x1a9334 mov r3, r0 */
/* @0x1a9338 str r0, [r5, #0x58] */
/* @0x1a933c strb r4, [r3], #1 */
/* @0x1a9340 add r3, r3, #1 */
/* @0x1a9344 strb r4, [r0, #0x1] */
/* @0x1a9348 mov r0, #4 */
/* @0x1a934c strb r4, [r3], #1 */
/* @0x1a9350 strb r4, [r3] */

/* ── §21 第二块 4 B（0x1a9354..0x1a9374）：Alloc(4, …, 124, true) → container+0x5c
 *  同样 4 条 strb 清零。★ 行号 111/121/124 三个 Alloc 全在同一文件。 */
/* @0x1a9354 mov r3, #1 */
/* @0x1a9358 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1a935c mov r3, r0 */
/* @0x1a9360 str r0, [r5, #0x5c] */
/* @0x1a9364 strb r4, [r3], #1 */
/* @0x1a9368 add r3, r3, #1 */
/* @0x1a936c strb r4, [r0, #0x1] */
/* @0x1a9370 strb r4, [r3], #1 */
/* @0x1a9374 strb r4, [r3] */

/* ── §21 收尾（0x1a9378..0x1a9380）：room+0xc4 = container+0x5c
 *  ★ 这是本卡对 CRoom_AddTile 卡 open 4（「+0xc4 由谁初始化」）的答案：容器内偏移，不是独立分配。
 *    也解释了 §1 ③ 的乱序风险：清 +0xc4 会把块内地址交给 Free（只有 +0xd0 为 1 且未被重指时才踩）。 */
/* @0x1a9378 ldr r3, [r5, #0x5c] */
/* @0x1a937c str r3, [r6, #0xc4] */
/* @0x1a9380 pop {r4, r5, r6, r7, r8, pc} */

/* ── §21 literal pool（0x1a9384，1 字；非指令）
 *  0x1a9384 = 0x001a3ed0 → 配 0x1a92d8 的 pc(0x1a92e0) = 0x34d1b0 = "jni/../jni/yoyo/../../../Files/Room/Room_Class.cpp"。
 *  objdump 译成 `ldrsbeq r3, [r10], -r0`。 */
/* @0x1a9384 ldrsbeq r3, [r10], -r0 */

/* ── §22 序（0x1a9388..0x1a93b4）：取调试控制台单例并打标题
 *  0x1a9388 池字 0x1a941c(0x244384) + pc(0x1a9390) = GOT 0x3ed71c → 0x3eb70c = dbg_csol（TRelConsole*，
 *  指针变量，其值 0x47a118 是 vtable）；r6 = *dbg_csol。
 *  标题串：0x1a9420 池字(0x1a3e38) + pc(0x1a93ac) = 0x34d1e4 = "Dump active list"。
 *  `ldr r3,[r6] / ldr r3,[r3,#0xc] / blx r3` ⇒ 调 vtable 第 4 槽（printf 形态：r0 = this、r1 = 串）。 */
/* @0x1a9388 ldr r3, [pc, #0x8c] */
/* @0x1a938c push {r4, r5, r6, r7, lr} */
/* @0x1a9390 ldr r3, [pc, r3] */
/* @0x1a9394 ldr r1, [pc, #0x84] */
/* @0x1a9398 mov r4, r0 */
/* @0x1a939c ldr r6, [r3] */
/* @0x1a93a0 sub sp, sp, #20 */
/* @0x1a93a4 add r1, pc, r1 */
/* @0x1a93a8 ldr r3, [r6] */
/* @0x1a93ac mov r0, r6 */
/* @0x1a93b0 ldr r3, [r3, #0xc] */
/* @0x1a93b4 blx r3 */

/* ── §22 链与循环头（0x1a93b8..0x1a93cc）：A 链尾 + 1000 次上限
 *  r4 = room+0x80；空链 → 0x1a9414 返回。r5 = 1000（防死循环的硬上限）、r7 = 格式串 0x34d1f8。 */
/* @0x1a93b8 ldr r4, [r4, #0x80] */
/* @0x1a93bc cmp r4, #0 */
/* @0x1a93c0 beq 0x1a9414 <_ZN5CRoom5DebugEv+0x8c> */
/* @0x1a93c4 ldr r7, [pc, #0x58] */
/* @0x1a93c8 mov r5, #1000 */
/* @0x1a93cc add r7, pc, r7 */

/* ── §22 循环体（0x1a93d0..0x1a9408）：三条实参
 *  s14 = [r4+384] = inst+0x180（float，深度快照）；vcvt.f64.f32 d7 → vstr d7,[sp]（第 2 实参，%f）；
 *  r12 = [[r4+0x80]+0x14] → str r12,[sp,#8]（第 3 实参，%s）；r2 = inst（%p）。
 *  ★ inst+0x80 = CObjectGM*（SetObjectIndex 0x193294 写它）、CObjectGM+0x14 = 对象名（Object_Name 卡 0x19edd4），
 *  所以第 3 实参是「实例所属对象的名字」。
 *  格式串 = "0x%p\t%f\t%s"。下一个 r4 = inst+0x178（next）。 */
/* @0x1a93d0 vldr s14, [r4, #384] */
/* @0x1a93d4 vcvt.f64.f32 d7, s14 */
/* @0x1a93d8 ldr r3, [r6] */
/* @0x1a93dc mov r2, r4 */
/* @0x1a93e0 mov r0, r6 */
/* @0x1a93e4 mov r1, r7 */
/* @0x1a93e8 vstr d7, [sp] */
/* @0x1a93ec ldr r12, [r4, #0x80] */
/* @0x1a93f0 ldr r12, [r12, #0x14] */
/* @0x1a93f4 str r12, [sp, #0x8] */
/* @0x1a93f8 ldr r3, [r3, #0xc] */
/* @0x1a93fc blx r3 */

/* ── §22 尾（0x1a9400..0x1a9410）：1000 次或链尾退出
 *  cmp r4,#0 → 0x1a9414；subs r5,#1 → bne 0x1a93d0。★ 每帧最多打 1000 条。 */
/* @0x1a9400 ldr r4, [r4, #0x178] */
/* @0x1a9404 cmp r4, #0 */
/* @0x1a9408 beq 0x1a9414 <_ZN5CRoom5DebugEv+0x8c> */
/* @0x1a940c subs r5, r5, #1 */
/* @0x1a9410 bne 0x1a93d0 <_ZN5CRoom5DebugEv+0x48> */

/* ── §22 返回（0x1a9414..0x1a9418）：add sp,#20 → pop */
/* @0x1a9414 add sp, sp, #20 */
/* @0x1a9418 pop {r4, r5, r6, r7, pc} */

/* ── §22 literal pool（0x1a941c..0x1a9424，3 字；非指令）
 *  0x1a941c = 0x244384（→ GOT 0x3ed71c dbg_csol）；0x1a9420 = 0x1a3e38（→ 0x34d1e4 "Dump active list"）；
 *  0x1a9424 = 0x1a3e24（→ 0x34d1f8 "0x%p\t%f\t%s"）。objdump 译成 `eoreq`/`andseq`，非指令。 */
/* @0x1a941c eoreq r4, r4, r4, lsl #7 */
/* @0x1a9420 andseq r3, r10, r8, lsr lr */
/* @0x1a9424 andseq r3, r10, r4, lsr #28 */

/* ══ §4..§22 小结（一张表看完清扫族）════════════════════════════════════
 *  节   函数                          入口链                       出口（谁调）
 *  §4   ClearInstances()              room+0x80 A 链尾 → +0x178     Clear 0x1ad230；无其它调用点
 *  §5   ClearDeactiveInstances()      room+0x8c B 链尾 → +0x178     Clear 0x1ad238；无其它
 *  §6   ClearTiles()                  无（清整表）                  Clear 0x1ad258；无其它
 *  §7   ClearStorageTiles()           无                            **无调用点（不可达）**
 *  §8   ClearStorageInstances()       无（bx lr）                   **无调用点（不可达）**
 *  §9   CleanPersistent()             room+0x80 A 链尾 → +0x178     EndRoom 0x1d1ac4
 *  §10  ScrollBackground()            room+0x24 八格                DoAStep 0x1d3588
 *  §11  FindTile(int)                 room+0xc0 线性 + room+0x00 缓存  未在本卡取证（调用点不在 CRoom 内）
 *  §12  DeleteTile(int)               room+0xc0 搬移                F_TileDelete 一族（未取证）
 *  §13  SortTiles()                   room+0xc0 插入排序           Draw_Room 0x1b4118
 *  §14  HideTilesDepth(float)         room+0xc0 按 depth 过滤       未取证
 *  §15  ShowTilesDepth(float)         同上                          未取证
 *  §16  DeleteTilesDepth(float)       同上（压缩删除）              未取证
 *  §17  ShiftTilesDepth(f,f,f)        同上（x/y 平移）              未取证
 *  §18  FindTileAtDepth(f,f,f)        同上（AABB 命中 + 最近中心）  未取证
 *  §19  DeleteTilesAtDepth(f,f,f)     同上（AABB 命中即删）         未取证
 *  §20  ChangeTilesDepth(f,f)         同上（改 depth）              未取证
 *  §21  CreateWADStorage()            无（建 96 B 容器 + 两块 4 B） Room_Add 0x1b5498（唯一）
 *  §22  Debug()                       无（打 A 链前 1000 条）        **无调用点（不可达）**
 *  ⇒ 七条 tile 深度函数共用同一模板：`r3 = tiles + 0x1c; 尾 = tiles + 56*count + 0x1c;` 逐条比较 +0x1c，
 *    只是命中后的动作不同（写 +0x34 / 改 +0x00/+0x04 / 改 +0x1c / 压缩掉 / 选最近）。depth 是 float，
 *    比较用 `vcmp` + 条件码，没有 epsilon（相等判定是位相等语义的浮点比较）。
 *
 * ── §4..§22 的 open ───────────────────────────────────────────────────
 * open A: §7/§8/§22 三条不可达函数的存在意义（原版裁剩的桩 / 另一套 API 的遗留）未证；
 *         §7 若被调用会把容器内偏移交给 Free（§1 ③ 同款风险）。
 * open B: 实例暂存表 +0xc8 的容量/计数形态只在 AddInstanceToStorage（已出卡）里；§8 为空说明
 *         「清暂存实例」不需要动作，或原版丢了实现。
 * open C: §11..§20 的外部调用点未逐一定位（本卡只证函数体；全库 bl 扫描显示它们都不在 CRoom 族内被调）。
 * open D: tile 记录 +0x14/+0x18/+0x24/+0x28 的字段名（§18 的 AABB 公式给出最小自洽解释：w/h + 缩放）。
 * open E: §18 命中后把 room+0x00 写成 count 而非命中下标 —— 原版 bug 还是「长度缓存」约定，未证。
 * open F: §13 的排序只在 Draw_Room 之前跑；tile depth 在运行期被 §17/§20 改动后是否重排，本卡不证。
 *
 * ══ 本卡已证事实（编号供 claims 引用）══════════════════════════════════
 *  F1  ~CRoom 的释放顺序是「外壳 → Clear → 8 背景 → 8 视野 → 物理世界 → memset(this,0,292)」，
 *      而 memset 之后还有 ~150 条释放指令（三桶数组 / 层链 / 两条实例链）—— 它们读到的每一格
 *      都已被 memset 清零，**全部落空**；整段里唯一真的执行的是 0x1afed8 的 MemoryManager::Free(NULL)。
 *      ⇒ 层链、实例链、桶数组的实际释放者是 Clear / CleanRoomLayers / ClearInstances / ClearDeactiveInstances。
 *  F2  ~CRoom 的第一条副作用是 Run_Room(0x54298c) = this（0x1afa24，旧值存 r8），直到 0x1afb90
 *      才恢复 ⇒ 整个析构期间「当前房间」= 正在销毁的房间（Perform_Event、ClearInstances、
 *      CleanRoomLayers 都在这个窗口里跑）。
 *  F3  事件 12 的两条清扫互补且互斥：~CRoom 只对 +0x67==0 && +0x68==0 && +0x69==0 的实例跑，
 *      且受 g_isZeus(0x5428e8) 门控；CleanPersistent 只对 +0x67!=0 的实例跑，无门控。
 *      两处都把 (self, self, 12, 0) 四个实参写死。
 *  F4  RemoveMarked 的 >250（ms_markedCount 0x536d7c）与 option_use_fast_collision(0x542379)
 *      只决定 g_tree(0x5429a8) 的处置：两者都成立时先 blx [vtbl+4] 拆树、扫完 RebuildTree()；
 *      无论走哪条，ms_markedCount 都清 0（该计数器唯一的清零点）。
 *  F5  RemoveMarked 只从 A 链尾（room+0x80）出发；摘除时按 inst+0x69 选 A 链（+0x80/+0x84）
 *      或 B 链（+0x8c/+0x90），A 路把 inst+0x178/+0x17c 写 0，**B 路不写**；
 *      它只压缩 0x542a58 一条待办队列，而 ClearInstances 压缩三条（0x542a58/0x542a64/0x542a4c）。
 *  F6  释放归属表里真正会漏的三格：+0xac（96 B 容器，~CRoom 只清零，+0xb0 同址别名也不 Free）、
 *      +0xcc（room 名，LoadFromChunk 换新前自己 Free 旧值，析构/Clear 都不碰）、以及三张哈希图的
 *      **节点**（Clear 只放桶数组 +0xf4/+0x108/+0x120；已索引函数里没有节点遍历删除）。
 *      另 +0xc4 的初值是容器内偏移（container+0x5c，§21 0x1a937c），只有 +0xd0 非 0 且未被
 *      Assign/LoadFromChunk 重指时，§1 ③ 才会把块内地址交给 Free。
 *  F7  Clear 是唯一让房间可复用的函数：写回 30/640/480/0x00C0C0C0/1，复位 8+8 记录（+0x40 相机 id
 *      只在 g_isZeus 非 0 时销毁并写 -1），然后 ClearInstances / ClearDeactiveInstances /
 *      Free(+0xa4) / ClearTiles / CleanRoomLayers / 三桶数组 / +0x10c=0。
 *      它**不**释放 +0x08/+0x68/+0xcc/+0xac/+0xb4/8+8 记录 —— 那些是 ~CRoom 的活。
 *  F8  三条不可达函数：ClearStorageTiles 0x1ab104、ClearStorageInstances 0x1ab140（bx lr）、
 *      Debug 0x1a9388 —— 全库 645,282 条指令里指向它们的 bl 数为 0。
 *  F9  tile 表（56 B 记录）的字段定位：+0x00 x、+0x04 y、+0x14/+0x18 两个 int（读作 w/h）、
 *      +0x1c depth(float)、+0x20 id、+0x24/+0x28 两个 float（读作 xscale/yscale）、+0x34 可见性字节。
 *      room+0x00 是「最近命中的 tile 下标」：FindTile 先查它、命中时写回真下标；ClearTiles 写 -1；
 *      FindTileAtDepth 命中时写成 count（见 open E）。
 *
 * ── 本卡 open（总）────────────────────────────────────────────────────
 *  1. 事件号 12 的官方名（GM 事件枚举 CleanUp）未由符号/字符串证实；g_isZeus 门控的动机未证。
 *  2. MemoryManager::Free(NULL) 的语义未取证（决定 0x1afed8 是否可观测、是否回写 0xfeeefeee）。
 *  3. 三张 20 B 哈希图的节点生产者/释放点未定位（若 new 而来，每次房间销毁都漏）。
 *  4. +0xac 容器从不释放、+0xcc 房间名从不释放：是否为原版有意的「WAD 内存在别处统一回收」未证。
 *  5. tile 记录 +0x14/+0x18/+0x24/+0x28 的字段名（只有 §18/§19 的 AABB 公式给出最小自洽解释）。
 *  6. FindTileAtDepth 把 room+0x00 写成 count 的意图（bug 还是约定）未证。
 *  7. RemoveMarked 的 B 路不清链指针：对象内存若被池化复用，邻居可能读到已删对象（推断）。
 *  8. 250 这个门槛、以及「拆树 → 扫 → 重建树」的代价模型未做运行期验证。
 */
