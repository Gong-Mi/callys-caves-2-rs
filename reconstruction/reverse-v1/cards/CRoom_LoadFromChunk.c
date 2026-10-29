/* cally 逆向卡：CRoom::LoadFromChunk（原版 libyoyo.so，armv7）
 * @func 0x1aea3c 0x1af2bc  size 2176  544 条（0x1aed98..0x1aedd8 为内联 literal pool，17 字）
 * 级别: 正文（装载次序、字段落位、各可选块、代码入口/相机/物理/层/三张哈希表的重建全部逐条钉住，
 *             并与 CRoom::CRoom 0x1ad2cc、CRoom::Clear 0x1ad0a4、CRoom::AddTile 0x1ac240、
 *             CRoom::AddTileToStorage 0x1aaf78、CRoom::DeSerialise 0x1ac33c、CRoom::LoadFromStream
 *             0x1ae3f8、CLayerManager::InsertLayerIntoActiveList 0x1c30f8、Room_Load 0x1b4cd8
 *             八处交叉印证；
 *             未钉：g_FunctionClassifications > 5 这条门的语义、.bss 0x542be8 与 0x544bc0 两个
 *             未导出全局的角色、CPhysicsWorld 两个构造分支各自适用的场景）
 * 符号: _ZN5CRoom13LoadFromChunkEP6YYRoomPh → bool CRoom::LoadFromChunk(YYRoom* pRoom, uchar* pWAD)
 * ABI : softfp（float 走核心寄存器）；返回 bool，但**只有 return true 一条出口**
 * 同层: Room_Load 0x1b4cd8（唯一调用者）、CRoom::CRoom 0x1ad2cc / CRoom::Clear 0x1ad0a4（前置）、
 *       CRoom::DeSerialise 0x1ac33c / CRoom::LoadFromStream 0x1ae3f8（另两条装载路径）、
 *       CRoom::AddTile 0x1ac240 / AddTileToStorage 0x1aaf78（tile 的两种存储）、
 *       CLayerManager::BuildRoomLayers 0x1c6070（层）、CCameraManager::CreateCameraFromView 0x16f108 /
 *       CCamera::GetID 0x16d12c（相机）、CPhysicsWorld::C2 0x237ca0 / SetGravity 0x238c14（物理）、
 *       CCode::C2 0xcefc8 / Code_CreateEntry 0xcf324（代码入口）、
 *       Background_Exists 0xc3640 / Background_Data 0xc3794 / CBackground::GetWidth 0xc2d78 /
 *       GetHeight 0xc2d80、MemoryManager::Alloc 0x27ce78 / ReAlloc 0x27cedc / Free 0x27c2d0、
 *       operator new 0x27c524、YYStrDup 0xdb8c8、strlen@plt / strcpy@plt / memset@plt
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把「WAD 里的房间结构 + 整块 WAD 基址」直接铺成一个运行时 CRoom：先 Clear 再重建三张哈希表，
 *   然后字符串/头六字段/位域/版本 → 背景表 → 视野表（含相机）→ 代码表 → tile 指针表 → 层，
 *   中间可选地建 3D 头与 CPhysicsWorld。
 *   ★ 拷贝策略分两种：字符串（+0x08 / +0xcc / +0x68）与背景/视野记录（44 B / 68 B × 8）是**真的
 *     复制**进 CRoom 自己的内存；而 code 与 tile 记录**不复制**，CRoom 只拿到指向 WAD 的指针表
 *     （+0xc8 / +0xc4）—— 所以 chunk 载入不需要按房间的 tile 数分配记录内存。
 *
 * ── 谁调它（chunk 这个名字的来历）──────────────────────────────
 *   唯一调用点 0x1b4edc 在 Room_Load(unsigned char* data, unsigned int size, uchar* wad) 0x1b4cd8：
 *       new(292) → CRoom::CRoom() → CRoom::LoadFromChunk(YYRoom* = wad + 该房间的块偏移,
 *                                                        uchar*  = wad)
 *   Room_Load 再把这个 CRoom* 和房间路径串一起塞进两张平行数组。
 *   Room_Load 的唯一调用者是 LoadGameData 0x1de638（按 chunk 名派发：Header_Load / Room_Load /
 *   FUNC_Load / Option_Load / Extension_Load / Audio_Load …，每个都传同一个 wad 基址），
 *   LoadGameData 的唯一调用者是 RunnerLoadWad 0x1df5dc。
 *   ⇒ "chunk" = game.droid 里的 ROOM 块，不是 IBuffer 流、也不是 CStream。**启动装载路径**。
 *
 * ── 三条加载路径的分工（本卡的核心结论）────────────────────────────
 *   路径                入口        数据源               调用者（唯一）        失败出口
 *   ------------------  ----------  -------------------  --------------------  ----------------
 *   LoadFromChunk       0x1aea3c    YYRoom* + WAD         Room_Load 0x1b4edc    无（恒 true）
 *                                                        ← LoadGameData 0x1de638
 *                                                        ← RunnerLoadWad 0x1df5dc
 *   LoadFromStream      0x1ae3f8    CStream*              无（死代码）          magic 0x21d
 *   DeSerialise         0x1ac33c    IBuffer* + bool       Check_LoadGameState   无
 *   （写侧）Serialise   0x1aa228    IBuffer*              Command_SaveGame      —
 *   （内存对拷）Assign  0x1ad70c    CRoom*                Room_Duplicate / Room_Assign / StartRoom
 *   一句话分工：chunk = **资产装载**（WAD → 运行时房间，带相机/物理/层/代码入口，几乎零拷贝）；
 *   stream = **同一份房间语义的纯数据流版**（CStream，字段裁剪 + 常量补齐，无任何副作用）；
 *   DeSerialise = **存档往返**（IBuffer，字段最全，含两段实例表与可选注册）。
 *
 * ── 与 DeSerialise 的关系（逐项对照）──────────────────────────────
 *   1. 头六字段同序同型：+0x10/+0x14/+0xc/+0x18/+0x1c/+0x20（本卡段 4 ↔ DeSerialise 0x1ac398 段）。
 *   2. 本函数**多**两格：+0xac/+0xb0（源 YYRoom* 和 WAD 基址）、+0xcc（房间数据的 WAD 相对路径）。
 *      DeSerialise 全不写这三格。
 *   3. 本函数**多**四格 3D 相关：+0x70/+0x74/+0x78/+0x7c + 指针 +0xb4（CPhysicsWorld）。
 *      DeSerialise/LoadFromStream 都不碰。
 *   4. 背景：本函数 9 字段 + 2 常量 + 缩放门（记录自己的 +0x24）；DeSerialise 13 字段全读。
 *      落位逐格一致，只是常量替掉了 4 格、缩放替掉了 2 格。
 *   5. 视野：本函数 15 字段（+0x3c/+0x40 不写，+0x40 留给相机 id，+0x24 = 0.0f）；
 *      DeSerialise 17 字段全读。
 *   6. tile：本函数只把 WAD 里的 RTile* 收进指针表（+0xb8 条数、+0xc4 表），**不调 AddTile、
 *      不碰 room_maxtileid、不写 CRoom+0x00**；DeSerialise 逐条 AddTile（14 字段）再回退全局计数。
 *   7. 实例：本函数**一个 CInstance 都不建**（全函数没有 new(432)），实例只能来自
 *      BuildRoomLayers 解析的层；DeSerialise 逐条 new+CInstance::DeSerialise+挂链（两段）。
 *   8. 层：本函数要求版本 > 1 且 YYRoom+0x58 != 0 才 BuildRoomLayers；DeSerialise 固定读 n 次
 *      CLayerManager::DeSerializeLayer。
 *
 * ── 落位总表（YYRoom 侧 → CRoom 侧）──────────────────────────────
 *   YYRoom+0x00 (WAD 相对偏移) → 加 g_pWADBaseAddress 后 strcpy  → CRoom+0xcc（新 Alloc，strlen+1）
 *   YYRoom+0x04 (WAD 相对偏移) → 加基址后 YYStrDup               → CRoom+0x08
 *   YYRoom+0x08 → CRoom+0x10（宽）      YYRoom+0x0c → CRoom+0x14（高）
 *   YYRoom+0x10 → CRoom+0xc （speed）   YYRoom+0x14 ≠0 → CRoom+0x18（bool）
 *   YYRoom+0x18 → CRoom+0x1c（uint32）  YYRoom+0x1c ≠0 → CRoom+0x20（bool）
 *   YYRoom+0x24 位域：bit0→+0x44, bit1→+0x45, bit2→+0x46（**取反**）, >>16→版本
 *   YYRoom+0x28 → 背景指针数组（[0]=条数）  YYRoom+0x2c → 视野指针数组（[0]=条数）
 *   YYRoom+0x30 → 代码指针数组（[0]=条数）  YYRoom+0x34 → tile 指针数组（[0]=条数）
 *   YYRoom+0x38 ≠0 → 建物理世界；+0x4c/+0x50 → +0x74/+0x78（截成整数精度）；+0x54 → +0x7c
 *   YYRoom+0x20 → CCode 的 id（-1 表示不建）      YYRoom+0x58 → YYRoomLayers（版本>1 才用）
 *
 * ── 失败路径：没有 ────────────────────────────────────────────────
 *   全函数唯一出口是 0x1af0d0 的 mov r0,#1，返回恒为 true。数据坏掉时没有回滚也没有报错，
 *   只能落到以下几种结果之一：
 *     · YYRoom+0x28/+0x2c/+0x30/+0x34 == 0 → 0x1aed74/0x1af014/0x1af040 会直接解引用 0
 *       （那几处只对「要不要加 WAD 基址」做了判 0，判完照样 ldr [0]）→ 崩。
 *     · YYRoom+0x00 == 0 → 0x1aec24 strlen(0) → 崩（同一类：只判了加不加基址）。
 *     · 背景/视野条数 > 8 → 顺着 CRoom+0x24/+0x48 的 8 格指针数组继续往上写 → 越界。
 *   这些都是「数据恒合法」前提下的写法，不是可达的优雅失败路径。
 *
 * ── 未定（open）──────────────────────────────────────────────
 *   1. g_FunctionClassifications（.bss 0x544bf0，导出符号名）的**首字** > 5 才做 3D 头 ——
 *      为什么拿「函数分类表」当 3D 开关，本卡只到指令级。
 *   2. .bss 0x542be8（未导出字节）同时门控「每视野建相机」和「建 CPhysicsWorld」；
 *      .bss 0x544bc0（未导出 double，落在 g_MD5 尾巴里）是物理世界第二个实参的一个来源。
 *      两者都没有符号名，角色待定。
 *   3. CPhysicsWorld::C2 的两个分支（arg2 = g_double 截断 / CRoom+0xc 房间宽）分别对应什么场景。
 *   4. 背景/视野条数为数据驱动却只有 8 格：>8 的实际后果未运行期验证。
 *   5. 同一条 +0xb8 在 chunk 路径（WAD storage tile 数，配 +0xc4）与 DeSerialise/AddTile
 *      （自持 56 B 数组条数，配 +0xbc/+0xc0）含义不同；chunk 载入后再 AddTile 会因 +0xbc=0
 *      直接走「容量 = count+10」的扩容分支，[0,count) 位是未初始化内存（未运行期验证）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 装载：入口、清场 ───────────────────────────────────────────
 *   帧：push {r4-r11,lr} + vpush {d8} + sub sp,#20
 *   r4 = this(CRoom*)、r8 = 第 1 参 YYRoom*（WAD 里的房间结构）、r5 = 第 2 参 uchar*
 *   （整块 game.droid 缓冲区的基址，由 Room_Load 的第 3 参透传）。
 *   sp+0x4 = 代码表暂存、sp+0x8 = this 副本（视野段的相机分支用）、sp+0xc = 房间版本。
 *   第一件事 CRoom::Clear()：不做增量修补，先清空再整体重建（与 LoadFromStream 同一习惯）。
 */

/* @0x1aea3c push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1aea40 vpush {d8} */
/* @0x1aea44 mov r4, r0 */
/* @0x1aea48 sub sp, sp, #20 */
/* @0x1aea4c mov r8, r1 */
/* @0x1aea50 mov r5, r2 */
/* @0x1aea54 bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* ── 重建 CRoom 内嵌的第一张哈希表（+0xe4 起）─────────────────────────
 *   ★ 本段到 0x1aebec 为止，与 CRoom::CRoom 0x1ad558-0x1ad6e4 是**同一条源语句的两次实例化**
 *     （构造函数里 Clear 之后又来一遍），所以判读方式完全一样。表结构由
 *     CLayerManager::InsertLayerIntoActiveList 0x1c3180-0x1c33a0 钉死：
 *       { +0x00 size, +0x04 count, +0x08 mask, +0x0c threshold(float), +0x10 nodes }
 *       节点 12 B = { +0 key(int), +4 value(ptr), +8 hash }；扩容 = size<<1、重算 mask、旧节点 rehash；
 *       表 A 的元素类型是 CHashMap<int, CLayer*, 7>（0x1c336c 直接 bl CHashMap<...>::Insert，
 *       且 this = room+0xe4）。
 *   本段做的事：mask = size-1；nodes = Alloc(12*size)；memset 0；count = 0；threshold = 0.6*size。
 *   size 取的是 Clear 之前的旧值（新建房间 = ctor 给的 128），所以重装后大小沿用上次的容量。
 */

/* @0x1aea58 ldr r0, [r4, #0xe4] */
/* @0x1aea5c mov r2, #70 */
/* @0x1aea60 ldr r1, [pc, #0x334] */
/* @0x1aea64 mov r3, #1 */
/* @0x1aea68 sub r12, r0, #1 */
/* @0x1aea6c str r12, [r4, #0xec] */
/* @0x1aea70 add r0, r0, r0, lsl #1 */
/* @0x1aea74 add r1, pc, r1 */
/* @0x1aea78 ldr r7, [pc, #0x320] */
/* @0x1aea7c lsl r6, r0, #2 */
/* @0x1aea80 add r7, pc, r7 */
/* @0x1aea84 mov r0, r6 */
/* @0x1aea88 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aea8c mov r2, r6 */
/* @0x1aea90 mov r1, #0 */
/* @0x1aea94 str r0, [r4, #0xf4] */
/* @0x1aea98 bl 0xb65b0 <memset@plt> */
/* ── 阈值 + 逐节点清 hash ────────────────────────────────────────
 *   s15 = 池 0x1aed98 = 0x3f19999a = 0.6f；0.6 × 128 = 76.8 → vcvt.s32 截成 76 → 再当 float 存。
 *   末尾那个 12 B 步长的循环把每个节点的 +0x8(hash) 清零 —— memset 之后是冗余的，
 *   它是源码里「for (i=0;i<size;i++) nodes[i].hash = 0;」的痕迹。
 */

/* @0x1aea9c ldr r2, [r4, #0xe4] */
/* @0x1aeaa0 vldr s15, [pc, #752] */
/* @0x1aeaa4 mov r1, #0 */
/* @0x1aeaa8 cmp r2, r1 */
/* @0x1aeaac str r1, [r4, #0xe8] */
/* @0x1aeab0 vmov s11, r2 */
/* @0x1aeab4 vcvt.f32.s32 s14, s11 */
/* @0x1aeab8 vmul.f32 s15, s14, s15 */
/* @0x1aeabc vcvt.s32.f32 s15, s15 */
/* @0x1aeac0 vstr s15, [r4, #240] */
/* @0x1aeac4 ble 0x1aeae4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0xa8> */
/* @0x1aeac8 add r2, r2, r2, lsl #1 */
/* @0x1aeacc ldr r3, [r4, #0xf4] */
/* @0x1aead0 add r2, r3, r2, lsl #2 */
/* @0x1aead4 str r1, [r3, #0x8] */
/* @0x1aead8 add r3, r3, #12 */
/* @0x1aeadc cmp r3, r2 */
/* @0x1aeae0 bne 0x1aead4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x98> */
/* ── 第二张哈希表（+0xf8 起）：size/count/mask/threshold/nodes = +0xf8/+0xfc/+0x100/+0x104/+0x108 ──
 *   与上段逐指令同构，只有基址不同。元素类型未证（open，同构推断为 CHashMap<...,7> 的另一次实例化）。
 */

/* @0x1aeae4 ldr r0, [r4, #0xf8] */
/* @0x1aeae8 mov r2, #70 */
/* @0x1aeaec ldr r1, [pc, #0x2b0] */
/* @0x1aeaf0 mov r3, #1 */
/* @0x1aeaf4 sub r12, r0, #1 */
/* @0x1aeaf8 str r12, [r4, #0x100] */
/* @0x1aeafc add r0, r0, r0, lsl #1 */
/* @0x1aeb00 add r1, pc, r1 */
/* @0x1aeb04 lsl r6, r0, #2 */
/* @0x1aeb08 mov r0, r6 */
/* @0x1aeb0c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aeb10 mov r2, r6 */
/* @0x1aeb14 mov r1, #0 */
/* @0x1aeb18 str r0, [r4, #0x108] */
/* @0x1aeb1c bl 0xb65b0 <memset@plt> */
/* @0x1aeb20 ldr r2, [r4, #0xf8] */
/* @0x1aeb24 vldr s15, [pc, #620] */
/* @0x1aeb28 mov r1, #0 */
/* @0x1aeb2c cmp r2, r1 */
/* @0x1aeb30 str r1, [r4, #0xfc] */
/* @0x1aeb34 vmov s13, r2 */
/* @0x1aeb38 vcvt.f32.s32 s14, s13 */
/* @0x1aeb3c vmul.f32 s15, s14, s15 */
/* @0x1aeb40 vcvt.s32.f32 s15, s15 */
/* @0x1aeb44 vstr s15, [r4, #260] */
/* @0x1aeb48 ble 0x1aeb68 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x12c> */
/* @0x1aeb4c add r2, r2, r2, lsl #1 */
/* @0x1aeb50 ldr r3, [r4, #0x108] */
/* @0x1aeb54 add r2, r3, r2, lsl #2 */
/* @0x1aeb58 str r1, [r3, #0x8] */
/* @0x1aeb5c add r3, r3, #12 */
/* @0x1aeb60 cmp r3, r2 */
/* @0x1aeb64 bne 0x1aeb58 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x11c> */
/* ── 第三张哈希表（+0x110 起）：+0x110/+0x114/+0x118/+0x11c/+0x120 ──────────
 *   同样同构。★ 三张表都不在 CRoom::Serialise / CRoom::Assign 的字段里（两张索引里 0xe0..0x12c
 *   一次都没出现）⇒ 纯运行期索引，不进存档、不随 Assign 复制。
 */

/* @0x1aeb68 ldr r0, [r4, #0x110] */
/* @0x1aeb6c mov r2, #70 */
/* @0x1aeb70 ldr r1, [pc, #0x230] */
/* @0x1aeb74 mov r3, #1 */
/* @0x1aeb78 sub r12, r0, #1 */
/* @0x1aeb7c str r12, [r4, #0x118] */
/* @0x1aeb80 add r0, r0, r0, lsl #1 */
/* @0x1aeb84 add r1, pc, r1 */
/* @0x1aeb88 lsl r6, r0, #2 */
/* @0x1aeb8c mov r0, r6 */
/* @0x1aeb90 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aeb94 mov r2, r6 */
/* @0x1aeb98 mov r1, #0 */
/* @0x1aeb9c str r0, [r4, #0x120] */
/* @0x1aeba0 bl 0xb65b0 <memset@plt> */
/* @0x1aeba4 ldr r1, [r4, #0x110] */
/* @0x1aeba8 vldr s15, [pc, #488] */
/* @0x1aebac mov r2, #0 */
/* @0x1aebb0 cmp r1, r2 */
/* @0x1aebb4 str r2, [r4, #0x114] */
/* @0x1aebb8 vmov s11, r1 */
/* @0x1aebbc vcvt.f32.s32 s14, s11 */
/* @0x1aebc0 vmul.f32 s15, s14, s15 */
/* @0x1aebc4 vcvt.s32.f32 s15, s15 */
/* @0x1aebc8 vstr s15, [r4, #284] */
/* @0x1aebcc ble 0x1aebec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1b0> */
/* @0x1aebd0 add r1, r1, r1, lsl #1 */
/* @0x1aebd4 ldr r3, [r4, #0x120] */
/* @0x1aebd8 add r1, r3, r1, lsl #2 */
/* @0x1aebdc str r2, [r3, #0x8] */
/* @0x1aebe0 add r3, r3, #12 */
/* @0x1aebe4 cmp r3, r1 */
/* @0x1aebe8 bne 0x1aebdc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1a0> */
/* ── 绑定源指针 + 路径串 → CRoom+0xcc ──────────────────────────────
 *   CRoom+0xac = 第 1 参 YYRoom*；CRoom+0xb0 = 第 2 参（整块 WAD 基址）。
 *   ★ 这里的字符串不是内联在结构里，而是**相对 WAD 基址的偏移**：
 *       绝对地址 = *g_pWADBaseAddress + YYRoom->field    （g_pWADBaseAddress = .bss 0x544c44，
 *                                                          GOT 偏移 0xffffbcf4，导出符号）
 *   YYRoom+0x00 → strlen+1 → Alloc(Room_Class.h, 行 0x25b=603) → strcpy → CRoom+0xcc
 *   ★ +0xcc 是「房间数据在 WAD 里的相对路径」，只有这条路径会产生；DeSerialise/LoadFromStream 都不写。
 *   ★ 偏移为 0 时只跳过了「加基址」，随后 strlen(0) 会崩 —— 属数据恒非 0 的假设，不是失败分支。
 */

/* @0x1aebec ldr r3, [r8] */
/* @0x1aebf0 str r5, [r4, #0xb0] */
/* @0x1aebf4 cmp r3, #0 */
/* @0x1aebf8 str r8, [r4, #0xac] */
/* @0x1aebfc moveq r5, r3 */
/* @0x1aec00 ldrne r2, [pc, #0x1c8] */
/* @0x1aec04 ldrne r2, [r7, r2] */
/* @0x1aec08 ldrne r5, [r2] */
/* @0x1aec0c addne r5, r5, r3 */
/* @0x1aec10 ldr r0, [r4, #0xcc] */
/* @0x1aec14 cmp r0, #0 */
/* @0x1aec18 beq 0x1aec20 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x1e4> */
/* @0x1aec1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aec20 mov r0, r5 */
/* @0x1aec24 bl 0xb6538 <strlen@plt> */
/* @0x1aec28 ldr r1, [pc, #0x17c] */
/* @0x1aec2c mov r3, #1 */
/* @0x1aec30 movw r2, #0x25b */
/* @0x1aec34 add r1, pc, r1 */
/* @0x1aec38 add r0, r0, r3 */
/* @0x1aec3c bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1aec40 mov r1, r5 */
/* @0x1aec44 str r0, [r4, #0xcc] */
/* @0x1aec48 bl 0xb65a4 <strcpy@plt> */
/* ── 第二串：房间名 → CRoom+0x08 ──────────────────────────────────
 *   YYRoom+0x04 → 加 WAD 基址 → YYStrDup → CRoom+0x08。
 *   与 DeSerialise 同格同义（那边是 ReadString→YYStrDup），与 LoadFromStream 也同格（那边直接
 *   ReadString 进 +0x08）。★ 偏移为 0 时不加基址、直接 YYStrDup(0)（依赖它容忍 NULL）。
 */

/* @0x1aec4c ldr r0, [r8, #0x4] */
/* @0x1aec50 cmp r0, #0 */
/* @0x1aec54 ldrne r3, [pc, #0x174] */
/* @0x1aec58 ldrne r3, [r7, r3] */
/* @0x1aec5c ldrne r3, [r3] */
/* @0x1aec60 addne r0, r3, r0 */
/* @0x1aec64 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* ── 房间头六字段：+0x10, +0x14, +0xc, +0x18, +0x1c, +0x20 ─────────────
 *   +0x10 = YYRoom+0x08   +0x14 = YYRoom+0x0c   +0xc = YYRoom+0x10
 *   +0x18 = (YYRoom+0x14 != 0)   +0x1c = YYRoom+0x18   +0x20 = (YYRoom+0x1c != 0)
 *   与 DeSerialise 0x1ac398-0x1ac460、LoadFromStream 0x1ae458-0x1ae498 **完全同序同型**。
 *   CRoom::Clear 0x1ad0c4/0x1ad0f0/0x1ad0d4 预置 +0x10=640 / +0x14=480 / +0xc=30
 *   ⇒ +0x10 = 宽、+0x14 = 高、+0xc = speed。
 *   ★ 存回顺序被编译器打散（0x1aec94..0x1aecac），+0x08 最后写 —— 别按读序当写序。
 */

/* @0x1aec68 ldr lr, [r8, #0x14] */
/* @0x1aec6c ldr r1, [r8, #0x1c] */
/* @0x1aec70 adds lr, lr, #0 */
/* @0x1aec74 ldr r6, [r8, #0x8] */
/* @0x1aec78 ldr r5, [r8, #0xc] */
/* @0x1aec7c ldr r12, [r8, #0x10] */
/* @0x1aec80 movne lr, #1 */
/* @0x1aec84 ldr r2, [r8, #0x18] */
/* @0x1aec88 adds r1, r1, #0 */
/* @0x1aec8c ldr r3, [pc, #0x11c] */
/* @0x1aec90 movne r1, #1 */
/* @0x1aec94 str r6, [r4, #0x10] */
/* @0x1aec98 str r5, [r4, #0x14] */
/* @0x1aec9c strb lr, [r4, #0x18] */
/* @0x1aeca0 str r12, [r4, #0xc] */
/* @0x1aeca4 strb r1, [r4, #0x20] */
/* @0x1aeca8 str r2, [r4, #0x1c] */
/* @0x1aecac str r0, [r4, #0x8] */
/* ── g_fCompiledToVM / g_fYYC 门：只有「编译成 VM 或 YYC」的构建才建房间创建码对象 ──
 *   两个导出字节任一非 0 → 跳到 0x1af0e0（段 9：代码串 + CCode），走完再落回 0x1aecd4；
 *   都为 0 → 直接落到 0x1aecd4，+0x68/+0x6c 保持 ctor/Clear 的清零值。
 *   （g_fCompiledToVM = .bss 0x544c04 ← GOT 偏移 0xffffbf10；g_fYYC = 0x544c48 ← 0xffffbecc）
 */

/* @0x1aecb0 ldr r3, [r7, r3] */
/* @0x1aecb4 ldrb r3, [r3] */
/* @0x1aecb8 cmp r3, #0 */
/* @0x1aecbc bne 0x1af0e0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6a4> */
/* @0x1aecc0 ldr r3, [pc, #0xec] */
/* @0x1aecc4 ldr r3, [r7, r3] */
/* @0x1aecc8 ldrb r3, [r3] */
/* @0x1aeccc cmp r3, #0 */
/* @0x1aecd0 bne 0x1af0e0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6a4> */
/* ── YYRoom+0x24 位域 + 版本号 + 3D 门 ─────────────────────────────
 *   bit0 → CRoom+0x44（DeSerialise/LoadFromStream 里同一格来自 ReadBoolean）
 *   bit1 → CRoom+0x45
 *   bit2 → CRoom+0x46 **取反**（eor r2,r9,#4 之后取 bit2 = !bit2）
 *   >>16（asr，保留符号位）→ [sp+0xc] 版本号；段 8 用它判 layers、段 12 用它判物理世界
 *   CRoom+0x70 先写 0，3D 头成立时再被覆盖成 (YYRoom+0x38 != 0)。
 *   ★ 门：*(int*)&g_FunctionClassifications > 5（.bss 0x544bf0，GOT 偏移 0xffffea88）。
 *     0x544bf0 是 8 字节导出符号 g_FunctionClassifications，本函数只读首字；为什么拿它当 3D 开关
 *     只到指令级（open 1）。
 */

/* @0x1aecd4 ldr r9, [r8, #0x24] */
/* @0x1aecd8 mov r1, #0 */
/* @0x1aecdc ldr r3, [pc, #0xd4] */
/* @0x1aece0 eor r2, r9, #4 */
/* @0x1aece4 and r0, r9, #1 */
/* @0x1aece8 ubfx r2, r2, #0x2, #0x1 */
/* @0x1aecec strb r0, [r4, #0x44] */
/* @0x1aecf0 strb r2, [r4, #0x46] */
/* @0x1aecf4 ubfx r2, r9, #0x1, #0x1 */
/* @0x1aecf8 strb r1, [r4, #0x70] */
/* @0x1aecfc asr r9, r9, #16 */
/* @0x1aed00 strb r2, [r4, #0x45] */
/* @0x1aed04 str r9, [sp, #0xc] */
/* @0x1aed08 ldr r3, [r7, r3] */
/* @0x1aed0c ldr r3, [r3] */
/* @0x1aed10 cmp r3, #5 */
/* @0x1aed14 ble 0x1aed50 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x314> */
/* ── 3D 头（上面那道门成立才执行）──────────────────────────────────
 *   ★ 0x1aed18/0x1aed1c 是 vldr（按 float 取），紧接着 vcvt.s32.f32 截成整数，再 vcvt.f32.s32
 *     存回 —— 净效果是「只保留整数精度」，不是原样搬 float。这条容易看漏：vstr 的两个源寄存器
 *     在 0x1aed20/0x1aed40 被重写过。
 *   CRoom+0x74 = (float)(int)YYRoom+0x4c     CRoom+0x78 = (float)(int)YYRoom+0x50
 *   CRoom+0x7c = YYRoom+0x54（原样 int）
 *   CRoom+0x70 = (YYRoom+0x38 != 0)；非 0 时 bne 尾跳 0x1af1a4 建物理世界（段 12）
 */

/* @0x1aed18 vldr s14, [r8, #76] */
/* @0x1aed1c vldr s15, [r8, #80] */
/* @0x1aed20 vcvt.s32.f32 s14, s14 */
/* @0x1aed24 ldr r3, [r8, #0x38] */
/* @0x1aed28 ldr r2, [r8, #0x54] */
/* @0x1aed2c subs r3, r3, r1 */
/* @0x1aed30 movne r3, #1 */
/* @0x1aed34 cmp r3, r1 */
/* @0x1aed38 str r2, [r4, #0x7c] */
/* @0x1aed3c strb r3, [r4, #0x70] */
/* @0x1aed40 vcvt.s32.f32 s15, s15 */
/* @0x1aed44 vstr s14, [r4, #116] */
/* @0x1aed48 vstr s15, [r4, #120] */
/* @0x1aed4c bne 0x1af1a4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x768> */
/* ── 背景段：WAD 里的指针数组（相对偏移）──────────────────────────────
 *   r6 = g_pWADBase + YYRoom+0x28；[r6] = 条数，r6+4 起是每条背景记录的相对偏移。
 *   ★ 条数是**数据驱动**（ldr r12,[r6]），不是常量 8；而 CRoom 只有 8 格指针
 *     （ctor 0x1ad4f8 起循环 new(44) 填 +0x24..+0x40）⇒ >8 条会顺着 +0x44 往上越界写指针（open 4）。
 *   ★ YYRoom+0x28 == 0 时只把 r1 置 4，随后照样 ldr r12,[r6]（r6 仍是 0）→ 解引用 0。
 *     同类问题在 view/code/tile 四段都有：只判了「加不加基址」，没判解引用。
 */

/* @0x1aed50 ldr r6, [r8, #0x28] */
/* @0x1aed54 cmp r6, #0 */
/* @0x1aed58 moveq r1, #4 */
/* @0x1aed5c beq 0x1aed74 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x338> */
/* @0x1aed60 ldr r3, [pc, #0x68] */
/* @0x1aed64 ldr r3, [r7, r3] */
/* @0x1aed68 ldr r3, [r3] */
/* @0x1aed6c add r6, r3, r6 */
/* @0x1aed70 add r1, r6, #4 */
/* ── 背景循环骨架 ────────────────────────────────────────────────
 *   r12 = 条数（<=0 直接跳到视野段 0x1aeeb4）
 *   s16 = 1.0f（rec+0x28 的常量）、r9 = 指针数组游标（r1-4，配合 ldr [r9,#4]! 前加）、
 *   r10 = CRoom 侧游标（this 起、每轮 +4）、r11 = 计数、r5 = mvn(#-16777216) = 0x00FFFFFF。
 *   ★ 0x00FFFFFF 不是 0xFF000000：mvn 取反后是低 24 位全 1，与 tile+0x2c 同一个常量。
 */

/* @0x1aed74 ldr r12, [r6] */
/* @0x1aed78 cmp r12, #0 */
/* @0x1aed7c ble 0x1aeeb4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x478> */
/* @0x1aed80 vmov.f32 s16, #1.000000e+00 */
/* @0x1aed84 sub r9, r1, #4 */
/* @0x1aed88 mov r10, r4 */
/* @0x1aed8c mov r11, #0 */
/* @0x1aed90 mvn r5, #-16777216 */
/* @0x1aed94 b 0x1aedec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3b0> */
/* ── 内联 literal pool（0x1aed98..0x1aedd8，17 字；objdump 把数据字译成指令，非指令）──
 *   0x1aed98 0x3f19999a  float 0.6f（三处 vldr s15 取它当哈希表阈值系数）
 *   0x1aed9c 0x001825bc  → 0x1aea7c+0x1825bc = 0x331038 "…/Platform/MemoryManager.h"
 *   0x1aeda0 0x002431d0  → 0x1aea88+0x2431d0 = 0x3f1c58 GOT 基址（本函数所有 GOT 访问都从它加减）
 *   0x1aeda4 0x00182530  → 0x1aeb08+0x182530 = 0x331038（第二张表同一文件名）
 *   0x1aeda8 0x001824ac  → 0x1aeb8c+0x1824ac = 0x331038（第三张表同一文件名）
 *   0x1aedac 0x0019e63c  → 0x1aec3c+0x19e63c = 0x34d278 "…/Files/Room/Room_Class.h"
 *   0x1aedb0 0xffffbf10  -0x40f0 → 槽 0x3edb68 → .bss 0x544c04 g_fCompiledToVM
 *   0x1aedb4 0xffffbecc  -0x4134 → 槽 0x3edb24 → .bss 0x544c48 g_fYYC
 *   0x1aedb8 0xffffea88  -0x1578 → 槽 0x3f06e0 → .bss 0x544bf0 g_FunctionClassifications
 *   0x1aedbc 0xffffc024  -0x3fdc → 槽 0x3edc7c → .bss 0x48f78c g_CM（CCameraManager 单例，28 B）
 *   0x1aedc0 0x0019e150  → 0x1af060+0x19e150 = 0x34d1b0 "…/Files/Room/Room_Class.cpp"
 *   0x1aedc4 0x0017fa52  → 0x1af0ec+0x17fa52 = 0x32eb3e ""（空串，写进 CRoom+0x68）
 *   0x1aedc8 0xffffbcd4  -0x432c → 槽 0x3ed92c → .bss 0x542be8（未导出字节，open 2）
 *   0x1aedcc 0x0019dfa0  → 0x1af210+0x19dfa0 = 0x34d1b0（同一个 Room_Class.cpp 串）
 *   0x1aedd0 0xffffbcf4  -0x430c → 槽 0x3ed94c → .bss 0x544c44 g_pWADBaseAddress
 *   0x1aedd4 0xffffebc4  -0x143c → 槽 0x3f081c → .bss 0x544bc0（未导出 double，open 2）
 *   0x1aedd8 0x00000000  0.0f（视野 +0x24 的常量）
 *   ★ 池被放在 0x1aed94 的无条件 b 之后：控制流永远跳过它，objdump 仍按指令反汇编。
 */

/* @0x1aed98 svclo #0x19999a */
/* @0x1aed9c ldrheq r2, [r8], -r12 */
/* @0x1aeda0 .word 0x002431d0 */
/* @0x1aeda4 andseq r2, r8, r0, lsr r5 */
/* @0x1aeda8 andseq r2, r8, r12, lsr #9 */
/* @0x1aedac andseq lr, r9, r12, lsr r6 */
/* @0x1aedb0 .word 0xffffbf10 */
/* @0x1aedb4 .word 0xffffbecc */
/* @0x1aedb8 .word 0xffffea88 */
/* @0x1aedbc .word 0xffffc024 */
/* @0x1aedc0 andseq lr, r9, r0, asr r1 */
/* @0x1aedc4 andseq pc, r7, r2, asr r10 */
/* @0x1aedc8 .word 0xffffbcd4 */
/* @0x1aedcc andseq sp, r9, r0, lsr #31 */
/* @0x1aedd0 .word 0xffffbcf4 */
/* @0x1aedd4 .word 0xffffebc4 */
/* @0x1aedd8 andeq r0, r0, r0 */
/* ── 背景循环尾：+1、指针 +4、比上界；跳出 → 视野段 0x1aeeb4 ────────────
 */

/* @0x1aeddc add r11, r11, #1 */
/* @0x1aede0 add r10, r10, #4 */
/* @0x1aede4 cmp r12, r11 */
/* @0x1aede8 ble 0x1aeeb4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x478> */
/* ── 背景记录体：9 个字段 + 2 个常量 ───────────────────────────────
 *   每条：r9 前加取「相对偏移」，非 0 才加 WAD 基址得 YYRoomBackground*；
 *   CRoom 侧记录 = this+0x24+4i（r10 游标）。落位：
 *     rec+0x00 = (bg+0x00 != 0)            bytes
 *     rec+0x01 = (bg+0x04 != 0)
 *     rec+0x04 = bg+0x08                   int
 *     rec+0x08 = (float)(int)bg+0x0c
 *     rec+0x0c = (float)(int)bg+0x10
 *     rec+0x10 = (bg+0x14 != 0)
 *     rec+0x11 = (bg+0x18 != 0)
 *     rec+0x14 = (float)(int)bg+0x1c
 *     rec+0x18 = (float)(int)bg+0x20
 *     rec+0x24 = 0x00FFFFFF                常量
 *     rec+0x28 = 1.0f                      常量
 *   ★ 与 DeSerialise 的 13 字段表逐格对照：那边 rec+0x1c/+0x20/+0x24/+0x28 全从流里读；
 *     这边 +0x24/+0x28 用常量、+0x1c/+0x20 交给缩放分支算（见 0x1aee94）。
 *   ★ 流/结构里存的是**整数**（vcvt.f32.s32 才变 float）；落位点要看 0x1aee64/0x1aee80/
 *     0x1aee88/0x1aee8c 的 vstr。
 *   ★ 记录里所有 bool 都是 strb 单字节、无对齐填充（0x2c = 精确 44 字节，与 ctor 的 new(44) 对齐）。
 *   ★ 写常量的两条（0x1aee78 str r5、0x1aee4c vstr s16）夹在中间，别当成读出来的值。
 */

/* @0x1aedec ldr r2, [r9, #0x4]! */
/* @0x1aedf0 cmp r2, #0 */
/* @0x1aedf4 ldrne r3, [pc, #-0x2c] */
/* @0x1aedf8 ldrne r3, [r7, r3] */
/* @0x1aedfc ldrne r3, [r3] */
/* @0x1aee00 addne r2, r3, r2 */
/* @0x1aee04 ldr r1, [r2] */
/* @0x1aee08 vldr s13, [r2, #16] */
/* @0x1aee0c ldr r3, [r10, #0x24] */
/* @0x1aee10 vldr s14, [r2, #28] */
/* @0x1aee14 ldr r0, [r2, #0x4] */
/* @0x1aee18 adds r1, r1, #0 */
/* @0x1aee1c vldr s15, [r2, #32] */
/* @0x1aee20 vldr s11, [r2, #12] */
/* @0x1aee24 movne r1, #1 */
/* @0x1aee28 adds r0, r0, #0 */
/* @0x1aee2c strb r1, [r3] */
/* @0x1aee30 vcvt.f32.s32 s12, s11 */
/* @0x1aee34 ldr r1, [r2, #0x14] */
/* @0x1aee38 movne r0, #1 */
/* @0x1aee3c ldr lr, [r2, #0x18] */
/* @0x1aee40 adds r1, r1, #0 */
/* @0x1aee44 strb r0, [r3, #0x1] */
/* @0x1aee48 ldr r0, [r2, #0x8] */
/* @0x1aee4c vstr s16, [r3, #40] */
/* @0x1aee50 movne r1, #1 */
/* @0x1aee54 strb r1, [r3, #0x10] */
/* @0x1aee58 ldr r1, [r2, #0x24] */
/* @0x1aee5c adds r2, lr, #0 */
/* @0x1aee60 vcvt.f32.s32 s13, s13 */
/* @0x1aee64 vstr s12, [r3, #8] */
/* @0x1aee68 movne r2, #1 */
/* @0x1aee6c cmp r1, #0 */
/* @0x1aee70 str r0, [r3, #0x4] */
/* @0x1aee74 strb r2, [r3, #0x11] */
/* @0x1aee78 str r5, [r3, #0x24] */
/* @0x1aee7c vcvt.f32.s32 s14, s14 */
/* @0x1aee80 vstr s13, [r3, #12] */
/* @0x1aee84 vcvt.f32.s32 s15, s15 */
/* @0x1aee88 vstr s14, [r3, #20] */
/* @0x1aee8c vstr s15, [r3, #24] */
/* @0x1aee90 beq 0x1aeddc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3a0> */
/* ── 背景缩放门：bg+0x24 != 0 且 Background_Exists(bg+4) 才跳 0x1af124 ──────
 *   ★ 与 LoadFromStream 的差别：那边门是流里额外读的一个 bool，这边门是记录自己的 +0x24。
 *     两者都把「算缩放」表达成「（记录/流里）有一个非 0 标记」。
 *   ★ 条件是两级：先 cmp [r2,#0x24]（beq 回循环尾），再 Background_Exists 返回非 0。
 *     后者为 0 时也直接回循环尾 —— 背景不存在就不算比例，但记录其余字段已经写好了。
 */

/* @0x1aee94 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1aee98 cmp r0, #0 */
/* @0x1aee9c bne 0x1af124 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x6e8> */
/* @0x1aeea0 ldr r12, [r6] */
/* @0x1aeea4 add r11, r11, #1 */
/* @0x1aeea8 add r10, r10, #4 */
/* @0x1aeeac cmp r12, r11 */
/* @0x1aeeb0 bgt 0x1aedec <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3b0> */
/* ── 视野段：同样是指针数组 + 68 B 记录 ───────────────────────────────
 *   r9 = g_pWADBase + YYRoom+0x2c（0 时只把 r10 置 4），[r9] = 条数，r10 走每条相对偏移。
 *   r5 = CRoom 侧游标（this 起、每轮 +4），记录 = [r5+0x48]。
 *   ★ 条数同样数据驱动、CRoom 侧同样只有 8 格（ctor 0x1ad51c 起 new(68) 填 +0x48..+0x64）。
 */

/* @0x1aeeb4 ldr r2, [r8, #0x2c] */
/* @0x1aeeb8 cmp r2, #0 */
/* @0x1aeebc moveq r9, r2 */
/* @0x1aeec0 moveq r10, #4 */
/* @0x1aeec4 beq 0x1aeedc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4a0> */
/* @0x1aeec8 ldr r3, [pc, #-0x100] */
/* @0x1aeecc ldr r3, [r7, r3] */
/* @0x1aeed0 ldr r3, [r3] */
/* @0x1aeed4 add r9, r3, r2 */
/* @0x1aeed8 add r10, r9, #4 */
/* @0x1aeedc ldr r12, [r9] */
/* @0x1aeee0 cmp r12, #0 */
/* @0x1aeee4 ble 0x1aeffc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5c0> */
/* @0x1aeee8 ldr r3, [pc, #-0x128] */
/* @0x1aeeec sub r10, r10, #4 */
/* @0x1aeef0 mov r5, r4 */
/* @0x1aeef4 mov r6, #0 */
/* ── 视野循环常量：s16 = 池 0x1aedd8 = 0.0f（写 rec+0x24）────────────────
 *   ★ 注意这格在 DeSerialise 里是从流里读的 float；本路径直接归 0。
 *   r11 = &(.bss 0x542be8)（未导出字节），后面用它决定要不要建相机。
 */

/* @0x1aeef8 vldr s16, [pc, #-296] */
/* @0x1aeefc ldr r11, [r7, r3] */
/* @0x1aef00 str r4, [sp, #0x8] */
/* @0x1aef04 b 0x1aef14 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4d8> */
/* @0x1aef08 cmp r12, r6 */
/* @0x1aef0c add r5, r5, #4 */
/* @0x1aef10 ble 0x1aeff8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5bc> */
/* ── 视野记录体：15 个字段 ───────────────────────────────────────
 *   落位（记录 = [r5+0x48]，r5 已 +4 时用 [r5+0x44]）：
 *     rec+0x00 = (v+0x00 != 0)          bool
 *     rec+0x04 = (float)(int)v+0x04     rec+0x08 = (float)(int)v+0x08
 *     rec+0x0c = (float)(int)v+0x0c     rec+0x10 = (float)(int)v+0x10
 *     rec+0x14 = v+0x14   rec+0x18 = v+0x18   rec+0x1c = v+0x1c   rec+0x20 = v+0x20
 *     rec+0x24 = 0.0f
 *     rec+0x28 = v+0x24   rec+0x2c = v+0x28   rec+0x30 = v+0x2c
 *     rec+0x34 = v+0x30   rec+0x38 = v+0x34
 *   ★ rec+0x3c / rec+0x40 本段**不写**：0x40 留给相机 id（0x1aeff0），0x3c 保持 ctor 的 -1
 *     （ctor 0x1ad534/0x1ad538 把 +0x3c/+0x40 预置成 0xFFFFFFFF）。而 DeSerialise 会把
 *     +0x28..+0x40 七个 int 全读出来 —— 这是三条路径里字段最多的一条。
 *   ★ 前四个矩形值「整数入、浮点用」（vcvt.f32.s32），与 DeSerialise 0x1ac71c 段同一手法；
 *     与 Draw_Room 0x1b4298 喂 GR_D3D_Set_View_Area 的用法互相印证（DeSerialise 卡已证）。
 */

/* @0x1aef14 ldr r3, [r10, #0x4]! */
/* @0x1aef18 add r6, r6, #1 */
/* @0x1aef1c ldr r2, [pc, #-0x154] */
/* @0x1aef20 cmp r3, #0 */
/* @0x1aef24 mov r1, r3 */
/* @0x1aef28 ldrne r2, [r7, r2] */
/* @0x1aef2c ldrne r1, [r2] */
/* @0x1aef30 addne r1, r1, r3 */
/* @0x1aef34 ldr r3, [r5, #0x48] */
/* @0x1aef38 vldr s13, [r1, #8] */
/* @0x1aef3c vldr s14, [r1, #12] */
/* @0x1aef40 ldr r2, [r1] */
/* @0x1aef44 vldr s15, [r1, #16] */
/* @0x1aef48 vldr s11, [r1, #4] */
/* @0x1aef4c ldr r0, [r1, #0x18] */
/* @0x1aef50 adds r2, r2, #0 */
/* @0x1aef54 vcvt.f32.s32 s12, s11 */
/* @0x1aef58 ldr lr, [r1, #0x20] */
/* @0x1aef5c movne r2, #1 */
/* @0x1aef60 strb r2, [r3] */
/* @0x1aef64 ldrb r2, [r11] */
/* @0x1aef68 cmp r2, #0 */
/* @0x1aef6c ldr r2, [r1, #0x14] */
/* @0x1aef70 vcvt.f32.s32 s13, s13 */
/* @0x1aef74 vstr s12, [r3, #4] */
/* @0x1aef78 str r2, [r3, #0x14] */
/* @0x1aef7c ldr r2, [r1, #0x1c] */
/* @0x1aef80 vstr s16, [r3, #36] */
/* @0x1aef84 str r0, [r3, #0x18] */
/* @0x1aef88 ldr r0, [r1, #0x24] */
/* @0x1aef8c str r2, [r3, #0x1c] */
/* @0x1aef90 ldr r2, [r1, #0x28] */
/* @0x1aef94 vcvt.f32.s32 s14, s14 */
/* @0x1aef98 str lr, [r3, #0x20] */
/* @0x1aef9c ldr lr, [r1, #0x2c] */
/* @0x1aefa0 vstr s13, [r3, #8] */
/* @0x1aefa4 str r0, [r3, #0x28] */
/* @0x1aefa8 ldr r0, [r1, #0x30] */
/* @0x1aefac str r2, [r3, #0x2c] */
/* @0x1aefb0 ldr r2, [r1, #0x34] */
/* @0x1aefb4 str lr, [r3, #0x30] */
/* @0x1aefb8 vcvt.f32.s32 s15, s15 */
/* @0x1aefbc vstr s14, [r3, #12] */
/* @0x1aefc0 str r0, [r3, #0x34] */
/* @0x1aefc4 vstr s15, [r3, #16] */
/* @0x1aefc8 str r2, [r3, #0x38] */
/* @0x1aefcc beq 0x1aef08 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4cc> */
/* ── 相机：.bss 0x542be8 非 0 才建 ───────────────────────────────
 *   CCameraManager::CreateCameraFromView(&g_CM, &YYRoomView)（r0 = g_CM 当 this，r1 = 该视野）
 *   → CCamera::GetID() → rec+0x40
 *   ★ 同一个字节也门控段 12 的 CPhysicsWorld，本卡称它「3D/相机开关」（open 2）。
 *   ★ 0x1aefe0 的 ldr r4,[r5,#0x44] 复用的是 this 副本：r5 已在 0x1aefd4 +4，
 *     所以 [r5+0x44] 就是当前视野那一格；随后 0x1aeff8 从 [sp,#8] 取回真 this。
 */

/* @0x1aefd0 ldr r3, [pc, #-0x21c] */
/* @0x1aefd4 add r5, r5, #4 */
/* @0x1aefd8 ldr r0, [r7, r3] */
/* @0x1aefdc bl 0x16f108 <_ZN14CCameraManager20CreateCameraFromViewEP10YYRoomView> */
/* @0x1aefe0 ldr r4, [r5, #0x44] */
/* @0x1aefe4 bl 0x16d12c <_ZN7CCamera5GetIDEv> */
/* @0x1aefe8 ldr r12, [r9] */
/* @0x1aefec cmp r12, r6 */
/* @0x1aeff0 str r0, [r4, #0x40] */
/* @0x1aeff4 bgt 0x1aef14 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x4d8> */
/* @0x1aeff8 ldr r4, [sp, #0x8] */
/* ── 代码表：YYRoom+0x30 的指针数组 → CRoom+0xc8 ────────────────────
 *   形状：Alloc(4 + 4n)，头字存 n，随后 n 个 YYRoomCode*（内存来自 WAD，不拷贝）。
 *   每条 code 记录**就地打补丁**：把 +0x10、+0x24 两个字段从「WAD 里的原始值」换成
 *   Code_CreateEntry(值, false) 的返回值（r1 = 0）。注意这是写回 WAD 缓冲区本身，
 *   不是写到 CRoom 的副本 —— 同一份 game.droid 二次装载会拿到已被替换过的指针。
 *   ★ n == 0 时把 YYRoom+0x30 也清 0、CRoom+0xc8 = 0。
 *   ★ 行号 0x325 = 805，文件名 Room_Class.cpp（池 0x1aedd0/0x1aedcc）。
 */

/* @0x1aeffc ldr r11, [r8, #0x30] */
/* @0x1af000 cmp r11, #0 */
/* @0x1af004 ldrne r3, [pc, #-0x23c] */
/* @0x1af008 ldrne r3, [r7, r3] */
/* @0x1af00c ldrne r3, [r3] */
/* @0x1af010 addne r11, r3, r11 */
/* @0x1af014 ldr r3, [r11] */
/* @0x1af018 cmp r3, #0 */
/* @0x1af01c bne 0x1af1f8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x7bc> */
/* @0x1af020 str r3, [r8, #0x30] */
/* @0x1af024 str r3, [r4, #0xc8] */
/* ── tile 表：YYRoom+0x34 的指针数组 → CRoom+0xb8(条数) + CRoom+0xc4(表) ─────
 *   CRoom+0xb8 = n（**直接赋值**，不是 AddTile 的 ++），CRoom+0xc4 = Alloc(4+4n) 的 {n, RTile*…}。
 *   ★ 本函数**不拷贝 tile 记录**（WAD 里 48 B 的记录，见 AddTileToStorage 0x1aab08 的 48 B 循环），
 *     也**不调用 CRoom::AddTile**（全库 AddTile 只有 0x1acc6c（DeSerialise）和 0x11c3f8 两个调用点）。
 *   ⇒ CRoom 上于是并存两套 tile 表示：
 *       chunk 路径：+0xb8 = storage 条数、+0xc4 = {n, &tile…}（与 AddTileToStorage 0x1aaf84 同一对字段）
 *       DeSerialise/AddTile：+0xb8 = 自持 56 B 数组条数、+0xbc = 容量、+0xc0 = 基址
 *     同一个 +0xb8 在两条路径里含义不同（open 5）。
 *   ★ 0x1af030 的 ldrne 只保护「加基址」，YYRoom+0x34 == 0 时 0x1af040 会 ldr [0]。
 */

/* @0x1af028 ldr r5, [r8, #0x34] */
/* @0x1af02c cmp r5, #0 */
/* @0x1af030 ldrne r3, [pc, #-0x268] */
/* @0x1af034 ldrne r3, [r7, r3] */
/* @0x1af038 ldrne r12, [r3] */
/* @0x1af03c addne r5, r12, r5 */
/* @0x1af040 ldr r12, [r5] */
/* @0x1af044 movw r2, #0x337 */
/* @0x1af048 ldr r1, [pc, #-0x290] */
/* @0x1af04c mov r3, #1 */
/* @0x1af050 lsl r0, r12, #2 */
/* @0x1af054 str r12, [r4, #0xb8] */
/* @0x1af058 add r1, pc, r1 */
/* @0x1af05c add r0, r0, #4 */
/* @0x1af060 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1af064 ldr r3, [r5] */
/* @0x1af068 str r3, [r0] */
/* @0x1af06c ldr r6, [r5] */
/* @0x1af070 cmp r6, #0 */
/* @0x1af074 addgt r6, r0, r6, lsl #2 */
/* @0x1af078 movgt r12, r5 */
/* @0x1af07c movgt r2, r0 */
/* @0x1af080 ble 0x1af0ac <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x670> */
/* @0x1af084 ldr r3, [r12, #0x4]! */
/* @0x1af088 ldr r5, [pc, #-0x2c0] */
/* @0x1af08c cmp r3, #0 */
/* @0x1af090 mov r1, r3 */
/* @0x1af094 ldrne r1, [r7, r5] */
/* @0x1af098 ldrne r1, [r1] */
/* @0x1af09c addne r1, r1, r3 */
/* @0x1af0a0 str r1, [r2, #0x4]! */
/* @0x1af0a4 cmp r2, r6 */
/* @0x1af0a8 bne 0x1af084 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x648> */
/* ── 版本门 + 层 + 唯一出口 ──────────────────────────────────────
 *   CRoom+0xc4 = 上面的 tile 表。
 *   版本 <= 1 → 直接 return true（老房间没有层结构，tile 走 +0xc4 的 storage 表）。
 *   版本 > 1 且 YYRoom+0x58 != 0 → BuildRoomLayers(this, g_pWADBase + YYRoom+0x58)；
 *     YYRoom+0x58 == 0 时 r1 保持 0 → BuildRoomLayers(this, 0)（由它自己容错）。
 *   ★ 本函数自身**不创建任何 CInstance**（全函数没有 new(432)）：版本 > 1 的房间，实例只能来自
 *     BuildRoomLayers 解析的层；这是「chunk 只装房间骨架、实例交给层」的直接证据。
 *   ★ 出口只有这一处：mov r0,#1 → add sp / vpop / pop → 返回 true，**没有失败分支**。
 */

/* @0x1af0ac ldr r3, [sp, #0xc] */
/* @0x1af0b0 str r0, [r4, #0xc4] */
/* @0x1af0b4 cmp r3, #1 */
/* @0x1af0b8 ble 0x1af0d0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x694> */
/* @0x1af0bc ldr r1, [r8, #0x58] */
/* @0x1af0c0 cmp r1, #0 */
/* @0x1af0c4 bne 0x1af190 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x754> */
/* @0x1af0c8 mov r0, r4 */
/* @0x1af0cc bl 0x1c6070 <_ZN13CLayerManager15BuildRoomLayersEP5CRoomP12YYRoomLayers> */
/* @0x1af0d0 mov r0, #1 */
/* @0x1af0d4 add sp, sp, #20 */
/* @0x1af0d8 vpop {d8} */
/* @0x1af0dc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 房间创建码：+0x68 空串 + +0x6c CCode（段 3 的门进来，做完落回 0x1aecd4）────
 *   +0x68 = YYStrDup("")（池 0x1aedc4 → 0x32eb3e，真的是空串）
 *   YYRoom+0x20 == -1 → +0x6c = 0（并把 +0x6c 显式写 0）
 *   否则 new(124) → CCode::C2(YYRoom+0x20, false) → +0x6c
 *   ★ 与 DeSerialise 对照：那边 +0x68 是 ReadString（真从流里读串）、+0x6c 根本不读。
 *     本路径的 +0x68 因此恒为空串，房间创建码全靠 +0x6c 那个 CCode。
 */

/* @0x1af0e0 ldr r0, [pc, #-0x324] */
/* @0x1af0e4 add r0, pc, r0 */
/* @0x1af0e8 bl 0xdb8c8 <_Z8YYStrDupPKc> */
/* @0x1af0ec ldr r3, [r8, #0x20] */
/* @0x1af0f0 cmn r3, #1 */
/* @0x1af0f4 moveq r3, #0 */
/* @0x1af0f8 streq r3, [r4, #0x6c] */
/* @0x1af0fc str r0, [r4, #0x68] */
/* @0x1af100 beq 0x1aecd4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x298> */
/* @0x1af104 mov r0, #124 */
/* @0x1af108 bl 0x27c524 <_Znwj> */
/* @0x1af10c ldr r1, [r8, #0x20] */
/* @0x1af110 mov r2, #0 */
/* @0x1af114 mov r5, r0 */
/* @0x1af118 bl 0xcefc8 <_ZN5CCodeC2Eib> */
/* @0x1af11c str r5, [r4, #0x6c] */
/* @0x1af120 b 0x1aecd4 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x298> */
/* ── 背景缩放比（0x1aee9c 跳过来）────────────────────────────────
 *   rec+0x1c = CRoom+0x10 / (float)CBackground::GetWidth()
 *   rec+0x20 = CRoom+0x14 / (float)CBackground::GetHeight()
 *   两道 vcmpe.f32 #0 + vldrgt 守卫：宽/高为 0（或负）就跳过，不除。
 *   ★ r10 此刻仍指向「当前背景指针那一格」，[r10+0x24] 复用的就是同一条记录；
 *     0x1af180 的 ldrgt r3,[r10,#0x24] 是同一条重读（编译器没复用 r3）。
 *   ★ 与 LoadFromStream 0x1ae5e0 段是同一个公式、同一套守卫，只是门不同（那边是流里的 bool）。
 */

/* @0x1af124 ldr r3, [r10, #0x24] */
/* @0x1af128 ldr r0, [r3, #0x4] */
/* @0x1af12c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1af130 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1af134 ldr r3, [r10, #0x24] */
/* @0x1af138 vmov s11, r0 */
/* @0x1af13c vcvt.f32.s32 s15, s11 */
/* @0x1af140 vcmpe.f32 s15, #0 */
/* @0x1af144 vmrs APSR_nzcv, fpscr */
/* @0x1af148 vldrgt s13, [r4, #16] */
/* @0x1af14c vcvtgt.f32.s32 s14, s13 */
/* @0x1af150 vdivgt.f32 s15, s14, s15 */
/* @0x1af154 vstrgt s15, [r3, #28] */
/* @0x1af158 ldr r0, [r3, #0x4] */
/* @0x1af15c bl 0xc3794 <_Z15Background_Datai> */
/* @0x1af160 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1af164 ldr r12, [r6] */
/* @0x1af168 vmov s14, r0 */
/* @0x1af16c vcvt.f32.s32 s15, s14 */
/* @0x1af170 vcmpe.f32 s15, #0 */
/* @0x1af174 vmrs APSR_nzcv, fpscr */
/* @0x1af178 vldrgt s11, [r4, #20] */
/* @0x1af17c vcvtgt.f32.s32 s14, s11 */
/* @0x1af180 ldrgt r3, [r10, #0x24] */
/* @0x1af184 vdivgt.f32 s15, s14, s15 */
/* @0x1af188 vstrgt s15, [r3, #32] */
/* @0x1af18c b 0x1aeddc <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x3a0> */
/* ── YYRoom+0x58 非 0：把相对偏移换成绝对指针，再交给 BuildRoomLayers ────
 *   r1 = *g_pWADBaseAddress + YYRoom+0x58，然后 b 0x1af0c8。
 */

/* @0x1af190 ldr r3, [pc, #-0x3c8] */
/* @0x1af194 ldr r3, [r7, r3] */
/* @0x1af198 ldr r3, [r3] */
/* @0x1af19c add r1, r3, r1 */
/* @0x1af1a0 b 0x1af0c8 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x68c> */
/* ── 物理世界：先看 .bss 0x542be8 ────────────────────────────────
 *   r0 = 488 先备好，然后按这个未导出字节二选一（两个分支各自 bl operator new）：
 *     == 0 → 0x1af294：从 .bss 0x544bc0 取一个**全局 double**，vcvt.s32.f64 截成 int 当第 2 实参
 *     != 0 → 0x1af1bc：直接用 CRoom+0xc（房间宽）当第 2 实参
 *   第 1 实参两边都是 CRoom+0x7c（按 softfp 当 float 传，实际是 YYRoom+0x54 的原样 int）。
 *   ★ 0x544bc0 没有导出符号（落在 g_MD5[16] 的尾巴里），0x542be8 同样没有 —— 两者角色见 open 2/3。
 */

/* @0x1af1a4 ldr r3, [pc, #-0x3e4] */
/* @0x1af1a8 mov r0, #488 */
/* @0x1af1ac ldr r11, [r7, r3] */
/* @0x1af1b0 ldrb r3, [r11] */
/* @0x1af1b4 cmp r3, r1 */
/* @0x1af1b8 bne 0x1af294 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x858> */
/* @0x1af1bc bl 0x27c524 <_Znwj> */
/* @0x1af1c0 ldr r1, [r4, #0x7c] */
/* @0x1af1c4 ldr r2, [r4, #0xc] */
/* @0x1af1c8 mov r5, r0 */
/* @0x1af1cc bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi> */
/* ── 重力 + 存指针 ──────────────────────────────────────────────
 *   CPhysicsWorld::SetGravity((float)(int)CRoom+0x74, (float)(int)CRoom+0x78)
 *   两个值就是段 5 从 YYRoom+0x4c/+0x50 截出来的那两个整数，这里再 vcvt 回 float。
 *   → CRoom+0xb4 = 世界指针；然后 b 0x1aed50（回背景段，3D 头已经写完了）。
 *   ★ 注意 0x1af1d0 是**两个分支的汇合点**：0x1af1b8 的 bne 与 0x1af294 的 b 都落到这里。
 */

/* @0x1af1d0 vldr s14, [r4, #116] */
/* @0x1af1d4 vldr s15, [r4, #120] */
/* @0x1af1d8 vcvt.f32.s32 s14, s14 */
/* @0x1af1dc mov r0, r5 */
/* @0x1af1e0 vcvt.f32.s32 s15, s15 */
/* @0x1af1e4 vmov r1, s14 */
/* @0x1af1e8 vmov r2, s15 */
/* @0x1af1ec bl 0x238c14 <_ZN13CPhysicsWorld10SetGravityEff> */
/* @0x1af1f0 str r5, [r4, #0xb4] */
/* @0x1af1f4 b 0x1aed50 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x314> */
/* ── 代码表非空：分配指针表 + 逐条 Code_CreateEntry ─────────────────────
 *   Alloc(4 + 4n)（行 0x325=805，Room_Class.cpp），头字 = n；
 *   对每条 code：out[i] = &code（WAD 内地址，非 0 偏移才加基址），
 *   并把 code+0x10 / code+0x24 就地替换成 Code_CreateEntry(旧值, false)。
 *   ★ 循环里的 r9 前加取偏移、r10 前加写 out，两把游标都与数组头错开 4 字节。
 */

/* @0x1af1f8 ldr r1, [pc, #-0x434] */
/* @0x1af1fc lsl r0, r3, #2 */
/* @0x1af200 add r0, r0, #4 */
/* @0x1af204 mov r3, #1 */
/* @0x1af208 add r1, pc, r1 */
/* @0x1af20c movw r2, #0x325 */
/* @0x1af210 bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1af214 ldr r3, [r11] */
/* @0x1af218 str r3, [r0] */
/* @0x1af21c ldr r3, [r11] */
/* @0x1af220 str r0, [sp, #0x4] */
/* @0x1af224 cmp r3, #0 */
/* @0x1af228 ble 0x1af288 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x84c> */
/* @0x1af22c ldr r10, [sp, #0x4] */
/* @0x1af230 mov r9, r11 */
/* @0x1af234 mov r6, #0 */
/* @0x1af238 ldr r3, [r9, #0x4]! */
/* @0x1af23c mov r1, #0 */
/* @0x1af240 ldr r2, [pc, #-0x478] */
/* @0x1af244 add r6, r6, #1 */
/* @0x1af248 cmp r3, #0 */
/* @0x1af24c mov r5, r3 */
/* @0x1af250 ldrne r2, [r7, r2] */
/* @0x1af254 ldrne r5, [r2] */
/* @0x1af258 addne r5, r5, r3 */
/* @0x1af25c str r5, [r10, #0x4]! */
/* @0x1af260 ldr r0, [r5, #0x10] */
/* @0x1af264 bl 0xcf324 <_Z16Code_CreateEntryjb> */
/* @0x1af268 mov r1, #0 */
/* @0x1af26c str r0, [r5, #0x10] */
/* @0x1af270 ldr r0, [r5, #0x24] */
/* @0x1af274 bl 0xcf324 <_Z16Code_CreateEntryjb> */
/* @0x1af278 ldr r3, [r11] */
/* @0x1af27c cmp r3, r6 */
/* @0x1af280 str r0, [r5, #0x24] */
/* @0x1af284 bgt 0x1af238 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x7fc> */
/* ── 代码表落位 → 回 tile 段 ─────────────────────────────────────
 *   CRoom+0xc8 = 指针表，然后 b 0x1af028 继续 tile 表。
 */

/* @0x1af288 ldr r2, [sp, #0x4] */
/* @0x1af28c str r2, [r4, #0xc8] */
/* @0x1af290 b 0x1af028 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x5ec> */
/* ── 物理世界 · 分支 B（0x542be8 == 0）：第 2 实参来自全局 double ────────
 *   vldr d7,[0x544bc0] → vcvt.s32.f64 s13,d7 → vmov r2,s13 → CPhysicsWorld::C2(r1 = CRoom+0x7c, r2)
 *   然后 b 0x1af1d0 与分支 A 汇合（SetGravity + 存 +0xb4）。
 *   ★ 两个分支的 new(488) 是各自独立的（0x1af1bc 与 0x1af294 各一条 bl operator new），
 *     不是先 new 再选参数 —— 编译器把重复的 new 提到了分支里。
 */

/* @0x1af294 bl 0x27c524 <_Znwj> */
/* @0x1af298 ldr r3, [pc, #-0x4cc] */
/* @0x1af29c ldr r1, [r4, #0x7c] */
/* @0x1af2a0 ldr r3, [r7, r3] */
/* @0x1af2a4 vldr d7, [r3] */
/* @0x1af2a8 vcvt.s32.f64 s13, d7 */
/* @0x1af2ac vmov r2, s13 */
/* @0x1af2b0 mov r5, r0 */
/* @0x1af2b4 bl 0x237ca0 <_ZN13CPhysicsWorldC2Efi> */
/* @0x1af2b8 b 0x1af1d0 <_ZN5CRoom13LoadFromChunkEP6YYRoomPh+0x794> */

/* ── 结束：0x1af2b8 是本函数最后一条（b 0x1af1d0），literal pool 在 0x1aed98..0x1aedd8 已在上文标注 ──
 */
