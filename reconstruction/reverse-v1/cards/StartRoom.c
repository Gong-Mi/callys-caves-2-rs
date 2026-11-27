/* cally 逆向卡：StartRoom（原版 libyoyo.so，armv7）
 * @func 0x1d38e0 0x1d4450  size 2928  732 条（最后一条 1d444c；1d440c..1d444c 为 literal pool，17 字；
 *       实际指令 715 条，其中 1d43f0-1d4400 静态不可达）
 * 级别: 骨架（换房流水线的执行顺序已逐条钉住：房间对象表与 Run_Room 的归属、承接实例的实体化、
 *             14/0 与 7/2、7/4 的派发位置、房间创建代码的两条执行路径、收尾门字节；
 *             未钉：CRoom+0x110/+0x118/+0x120 那张表的字段名、Perform_Event_Object 第 5 实参的含义、
 *             0x7590b1 与 0x542a48 两个门字节的身份、CInstance::vtable[1] 的正式语义、
 *             room->[0xa4] 数组里 id 的生成者（只证 CRoom::Assign 往里追加））
 * 符号: _Z9StartRoomib → void StartRoom(int roomIndex, bool bGameStart)
 * 调用者: 全库只有两处 bl（StartGame 0x1d4718、TickDebugger 0x29d930，两处 r1 都传 1），
 *         换房的常规入口是 SwitchRoom 0x1d4450 的尾调（r1 = 0）：EndRoom(false) → StartRoom(room, false)
 * 同层: EndRoom 0x1d1724（镜像函数，也是下面「承接表」的生产者）、Run_Room_Set 0x1cba58、
 *       Room_Data 0x1b52c4、CRoom::CRoom 0x1ad2cc / Assign 0x1ad70c / RemoveMarked 0x1abb24、
 *       CLayerManager::BuildRoomLayerRuntimeData 0x1c5dbc / AddInstance 0x1c5d18 / RemoveInstance 0x1b9e5c、
 *       CObjectGM::AddInstance 0x19e02c、Perform_Event_All 0xf33b0、Perform_Event_Object 0xf32e4、
 *       Code_Execute 0xcfc60、CInstance::CInstance 0x1994dc / Assign 0x1986ec / RebuildPhysicsBody 0x192fa4
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   把全局 Run_Room 指到 roomIndex 号房间：没有 CRoom 就 new 一个并用 Room_Data/CRoom::Assign 建出来，
 *   然后把上一房间 EndRoom 克隆下来的 persistent 实例逐个「实体化」进本房间，
 *   再（仅新建房间）按 room+0xa4 的创建顺序表跑 PreCreate(14)+Create(0)、接着跑房间创建代码，
 *   最后无条件 Perform_Event_All(7,4) 抛 Room Start 并置门字节。整个过程不返回任何值。
 *
 * ── 全局表（GOT 基址 0x3f1c58；每个地址都是「池字偏移 → GOT 槽 → 槽内 addend」实测）──
 *   0x542954 int    退出/中断码闸门：本函数入口无条件写 -1；DoAStep 的 13 个检查点要求它仍为 -1
 *                   （ASTEP-003）；EndRoom 会先存档再恢复
 *   0x5425d0 int    房间对象表 count   ┐ {count, CRoom** array}，下标 = 房间号
 *   ⚠ 修正（batchAN，cards/Room_Load.c）：房间表在 **0x5425d0**（24 B 匿名块，六格）；
 *     0x542990 是导出符号 **Run_Room_List**（size 8），只被 Run_EndGame 读，与本函数无关
 *   0x542994 ptr    房间对象表 array   ┘
 *   0x542958 int    当前房间号（本函数写两次）
 *   0x54298c ptr    Run_Room（CRoom*，读写函数 Run_Room_Set 0x1cba58）
 *   0x536f28 struct CInstance::ms_ID2Instance：id(int) → CInstance* 哈希表
 *                   {+0 桶数组(每桶 8 字节 {head,tail})、+4 mask、+8 count}，节点 16 字节 {next,prev,key,value}
 *   0x542a0c struct 「承接表」数组对象 {+0 capacity、+4 CInstance** data}（CArray<CInstance*>，文件
 *                   "…/Files/Platform/cARRAY_CLASS.h"）；生产者是 EndRoom，消费者是本函数
 *   0x542a14 int    承接表已用条数（与上面 capacity 分开存）；EndRoom 清 0、StartGame 0x1d46ac 也清 0
 *   0x5428e8 uint8  Zeus 调试器在线字节（DoBreak 卡）；本函数用它决定是否 CCameraManager::StartRoom()
 *                   以及是否抄源实例的 depth
 *   0x47f295 uint8  生成式 GC 开关字节（DoGenerationalGC 卡；也是 PushContextStack 的门）；本函数用它
 *                   选房间创建代码在哪个实例上跑
 *   0x7590b1 uint8  未知门字节：非 0 → 本函数直接 exit(0)（全 .text 只有两处池字引用该 GOT 偏移：
 *                   本卡 1d443c 与 ProcessCommandLine 的池 0x2a276c）
 *   0x542a48 uint8  收尾置 1 的「房间已起」字节（该 GOT 偏移在全 .text 只出现 1 次，就是这个写点）
 *   0x544be0 ptr    全局变量宿主 CInstance*（Code_Variable_Find_Slot_From_Name 卡：全局/内建变量槽挂在这个
 *                   实例上；本函数在 GC 开时拿它当房间创建代码的 self）
 *   0x48f78c ptr    CCameraManager 单例
 *
 * ── 字段表（本函数真正读写的，全部实测；命名凡未在别卡证过的都标「推断」）──
 *   CRoom
 *     +0x18  byte   房间持久标志（EndRoom 用它决定留不留 CRoom；本卡不读，仅旁证）
 *     +0x68  char*  房间创建代码的源码字符串（CRoom::Assign 0x1ad77c 用 YYStrDup 复制）
 *     +0x6c  CCode* 同一段创建代码的编译产物（0x1ad790 直接拷指针；本函数拿它喂 Code_Execute）
 *     +0x84  inst   实例链**头**（沿 +0x17c 前进）    +0x80  inst 链**尾**（沿 +0x178 后退）
 *     ⚠ 修正（2026-10-28，取 CRoom::DeSerialise 0x1acd58..0x1acda4 的实证）：头尾与 next/prev 原先写反了
 *     +0x88  int    实例数（本卡只证 +1）
 *     +0xa4  int*   实例创建顺序表（元素是 id）
 *     +0xa8  int    上面这张表的元素数
 *     +0x110 int 容量 / +0x114 已用 / +0x118 mask / +0x11c 阈值 / +0x120 桶   一张按 id 哈希的
 *                   开放寻址表（12 字节/项）。布局取自 CLayerManager_DuplicateRoomLayers 卡对同一
 *                   结构的独立实测（那张卡只说「表 3 在本函数里只重建、不 Insert」）；命中项 +4 是
 *                   记录对象、记录 +0x20 才是 CInstance* —— 这两个名字仍未钉
 *   CInstance
 *     +0x67  byte   persistent（EndRoom 只克隆它非 0 的；本卡不读，仅承接表语义旁证）
 *     +0x68  byte   已销毁/跳过；+0x69 byte 已 deactivate（两卡同址）
 *     +0x6b  byte   「已被承接/已激活」：本函数给实体化出来的实例置 1，创建事件循环见到 1 就
 *                   清 0 并跳过 Create（持久实例不重跑 Create 的机制）
 *     +0x6c  byte   「Create 已跑」：创建事件循环末尾置 1
 *     +0x78  int    实例 id（哈希表键、承接匹配键）
 *     +0x7c  int    object_index（喂 Perform_Event_Object 的第 3 实参）
 *     +0xb4 float x、+0xb8 float y
 *     +0x160 CCode* 房间定义里第 1 个代码槽（CRoom::Assign 0x1adf4c..0x1adf54 由 Code_GetEntry 填）
 *     +0x164 CCode* 房间定义里第 2 个代码槽（0x1adf58..0x1adf64）
 *     +0x170 int    本函数写 -1      +0x174 byte 本函数写 0
 *     +0x178 inst   next（向链头方向）  +0x17c inst prev（向链尾方向）
 *     +0x180 float  depth             +0x184 float depth 的缓存副本（排序用）
 *
 * ── 换房时的建实例顺序（本卡主结论，全部由锚点定序）───────────────
 *   1. 复位：0x542954 = -1 → [bGameStart] IO_Clear() → Effect_Clear()
 *   2. 房间对象表：count <= idx 时 ReAlloc((idx+1)*4) 并清零新槽；idx < 0 走「销毁全部房间」分支
 *   3. *0x542958 = idx；Run_Room_Set(g_rooms.array[idx]) —— 此时 Run_Room 可能是 0
 *   4. Run_Room == 0 → new CRoom(292) + CRoom::CRoom + 存回 array[idx] + CRoom::Assign(Room_Data(idx), true)
 *      + 再 Run_Room_Set(array[idx])；CRoom::Assign 里就把房间自带的实例造完（含层、物理体、碰撞），
 *      并把它们的 id 依次追加进 room+0xa4 —— 这些实例 +0x6b == 0
 *      Run_Room != 0（持久房间重入）→ 只把 +0x80 链上每个实例重新 CObjectGM::AddInstance + 插入 id 表
 *   5. [Zeus] CCameraManager::StartRoom() → BuildRoomLayerRuntimeData → ParticleSystem_AddAllToLayers
 *      → Draw_Room_SetSize
 *   6. 承接表实体化（两条路径都做）：对 data[i]（上一房间 persistent 实例的克隆）按 id 在 +0x80 链里找
 *      同 id 实例：找到就原地复用，找不到才 new CInstance(x,y,id,obj,false)；然后一律
 *      Assign(源, true) → RebuildPhysicsBody → 插入 depth 有序链（+0x88 只加一次，说明是单表双端）
 *      → 插入 0x536f28 id 表 → [Zeus] 按 id 定点从层表里摘掉旧记录 → CLayerManager::AddInstance
 *      → +0x6b = 1、+0x170 = -1、+0x174 = 0 → 销毁源克隆。最后 Free(承接表 data) 并把 capacity/
 *      used/data 三清零
 *   7. CRoom::RemoveMarked(Run_Room)；承接表 used 再清一次
 *   8. [bGameStart] Perform_Event_All(7,2)（Game Start 位）+ RemoveMarked
 *   9. 仅新建房间：按 room+0xa4 的顺序取 id → 查 0x536f28 表 → +0x6b 非 0 就清 0 跳过，
 *      +0x68 非 0 就跳过，否则 Perform_Event_Object(inst,inst,obj,14,0) → Code_Execute(+0x164)
 *      → Perform_Event_Object(…,0,0) → Code_Execute(+0x160) → +0x6c = 1；跑完 Free(room+0xa4) 并清零
 *   10. 仅新建房间：room+0x68 && room+0x6c 时跑房间创建代码（GC 开 → 用 *(0x544be0)；GC 关 → 临时实例），
 *      之后 0x7590b1 非 0 就 exit(0)
 *   11. Perform_Event_All(7,4)（Room Start 位）→ RemoveMarked → 0x542a48 = 1 → 返回
 *
 *   事件号的名字来自三处互证（本卡只证参数，不证名字）：
 *     EndRoom 直接证 7/5 = Room End、7/3 = Game End（0x1d1784 / 0x1d1ad0）；
 *     DoAStep/Instance_Animate 证 7/7 = Animation End、HandleInstanceMovement 证 7/8 = End of Path；
 *     于是同一编号序列里 7/2 = Game Start、7/4 = Room Start 只是按序推断。
 *     14 = PreCreate 由 Command_Change（0x1c9bb4：先 1、12 再 14、0）与「14 在 0 之前」互证。
 *
 * ── open（写清而不是含糊带过）────────────────────────────────────
 *   · Perform_Event_Object 的第 5 实参：本函数两处都传 0（r10/r3），而 Command_Change 也传 0、
 *     Code_Execute 的第 5 实参这里传 1（创建事件码）与 5（房间创建代码），含义未钉
 *   · CInstance::vtable[1] 被当作「释放实例」调用（源克隆与临时实例各一次），无 delete 跟随，语义未钉
 *   · roomIndex < 0 时尾部按 array[-1] 取值（此时 array 已被置 0），静态可达性未证，本卡只记指令
 *   · 1d4254 的 `count == idx+1` 分支在入口条件（count <= idx）下不可达，仍完整入卡
 */

/* ── 段1：帧 + 全局闸门复位（1d38e0-1d3914）────────────────────────
 *   帧：push {r4-r11,lr} + sub sp,#68。三个栈槽先占好：
 *     sp+0x2c = 第 2 实参 bGameStart（全函数只有 1d3cec 读它）
 *     sp+0x30 = 一个 16 字节 RValue 的基址（+0 值、+8 指针位、+0xc tag），这里只清 +0
 *     sp+0x14 稍后先当「&Run_Room」、再当「&Zeus 字节」复用
 *   r7 = roomIndex（后面 1d398c 起 r7 被借去当「下一个实例」，房间号只从栈/全局再取）
 *   GOT 基址：1d38e8 装 0x21e358，1d38f8 的 add 用 pc=0x1d3900 → 0x3f1c58
 *   ★ 1d3904 mvn r2,#0 / 1d3910 str r2,[r3]：入口无条件把 *(int*)0x542954 写 -1 ——
 *     这是 DoAStep 每段都查的「退出码闸门」（只有 -1 才继续整帧），换房开头必须复位。
 *   1d3914 bne 0x1d4308 = bGameStart 才 IO_Clear()（外挂的输入/手柄状态），Effect_Clear 无条件。 */
/* @0x1d38e0 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1d38e4 sub sp, sp, #68 */
/* @0x1d38e8 ldr r11, [pc, #0xb1c] */
/* @0x1d38ec mov r2, #0 */
/* @0x1d38f0 ldr r3, [pc, #0xb18] */
/* @0x1d38f4 cmp r1, #0 */
/* @0x1d38f8 add r11, pc, r11 */
/* @0x1d38fc str r2, [sp, #0x30] */
/* @0x1d3900 str r1, [sp, #0x2c] */
/* @0x1d3904 mvn r2, #0 */
/* @0x1d3908 ldr r3, [r11, r3] */
/* @0x1d390c mov r7, r0 */
/* @0x1d3910 str r2, [r3] */
/* @0x1d3914 bne 0x1d4308 <_Z9StartRoomib+0xa28> */
/* ── 段2：Effect_Clear / 房间对象表 / 当前房间号 / 第一次 Run_Room_Set（1d3918-1d3944）
 *   r4 = &g_rooms(0x5425d0)，r5 = count；count <= roomIndex → 1d424c 扩容（段36、39-41）。
 *   r3 = &curRoom(0x542958)，1d3938 写入 roomIndex。
 *   1d393c/1d3940 取 array[roomIndex]，1d3944 交给 Run_Room_Set ——
 *   注意此刻 array[idx] 可能是 NULL（新房间），所以 1d3948 立刻要判断 Run_Room 是否为空。 */
/* @0x1d3918 bl 0x1a277c <_Z12Effect_Clearv> */
/* @0x1d391c ldr r3, [pc, #0xaf0] */
/* @0x1d3920 ldr r4, [r11, r3] */
/* @0x1d3924 ldr r5, [r4] */
/* @0x1d3928 cmp r5, r7 */
/* @0x1d392c ble 0x1d424c <_Z9StartRoomib+0x96c> */
/* @0x1d3930 ldr r3, [pc, #0xae0] */
/* @0x1d3934 ldr r3, [r11, r3] */
/* @0x1d3938 str r7, [r3] */
/* @0x1d393c ldr r3, [r4, #0x4] */
/* @0x1d3940 ldr r0, [r3, r7, lsl #2] */
/* @0x1d3944 bl 0x1cba58 <_Z12Run_Room_SetP5CRoom> */
/* ── 段3：读 Run_Room → 记 had_room → 取实例链头（1d3948-1d3970）
 *   r6 = &Run_Room(0x54298c)；r3 = *r6。
 *   1d3954 adds/movne/cmp/str = sp+0x20 = (Run_Room != 0) 的布尔化，全函数反复读它当「房间是否已存在」。
 *   1d3964 beq 0x1d41f0：Run_Room 为空 → 新建 CRoom（段35）。
 *   1d3968 r4 = room->[0x80]（实例链头）；为空 → 1d3a18 跳过重注册循环。 */
/* @0x1d3948 ldr r3, [pc, #0xacc] */
/* @0x1d394c ldr r6, [r11, r3] */
/* @0x1d3950 ldr r3, [r6] */
/* @0x1d3954 adds r12, r3, #0 */
/* @0x1d3958 movne r12, #1 */
/* @0x1d395c cmp r12, #0 */
/* @0x1d3960 str r12, [sp, #0x20] */
/* @0x1d3964 beq 0x1d41f0 <_Z9StartRoomib+0x910> */
/* @0x1d3968 ldr r4, [r3, #0x80] */
/* @0x1d396c cmp r4, #0 */
/* @0x1d3970 beq 0x1d3a18 <_Z9StartRoomib+0x138> */
/* ── 段4：持久房间重入时的「重注册」循环（1d3974-1d3a14）──────────
 *   只在 Run_Room 非空时走。r5 = &ms_ID2Instance(0x536f28)，r10 = "…/Platform/Hash.h"。
 *   循环体（1d3990-1d3a10）对链上每个实例做两件事：
 *     ① CObjectGM::AddInstance(inst->[0x80], inst) —— 把实例重新挂回它所属对象的实例表
 *     ② 往 id 表插一个 16 字节节点：MemoryManager::Alloc(16, "Hash.h", 306, true)，
 *        key = inst->[0x78]、value = inst；桶数组每桶 8 字节 {head,tail}，恒插到桶尾，count++
 *   next 在调用前就先取出（1d3998），所以事件里改链不影响本趟遍历。
 *   ★ 这一步是「只重挂、不重建」：持久房间重入时实例对象与状态都留着（EndRoom 只是把它们从
 *     objGM/层表/id 表里摘掉），所以后面既不会跑 Create，也不会跑房间创建代码。 */
/* @0x1d3974 ldr r3, [pc, #0xaa4] */
/* @0x1d3978 ldr r10, [pc, #0xaa4] */
/* @0x1d397c ldr r5, [r11, r3] */
/* @0x1d3980 add r10, pc, r10 */
/* @0x1d3984 str r6, [sp, #0x14] */
/* @0x1d3988 b 0x1d3990 <_Z9StartRoomib+0xb0> */
/* @0x1d398c mov r4, r7 */
/* @0x1d3990 ldr r0, [r4, #0x80] */
/* @0x1d3994 mov r1, r4 */
/* @0x1d3998 ldr r7, [r4, #0x178] */
/* @0x1d399c bl 0x19e02c <_ZN9CObjectGM11AddInstanceEP9CInstance> */
/* @0x1d39a0 movw r2, #0x132 */
/* @0x1d39a4 mov r3, #1 */
/* @0x1d39a8 mov r0, #16 */
/* @0x1d39ac mov r1, r10 */
/* @0x1d39b0 ldr r8, [r5] */
/* @0x1d39b4 ldr r6, [r4, #0x78] */
/* @0x1d39b8 ldr r9, [r5, #0x4] */
/* @0x1d39bc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d39c0 and r9, r6, r9 */
/* @0x1d39c4 ldr r2, [r8, r9, lsl #3] */
/* @0x1d39c8 add r3, r8, r9, lsl #3 */
/* @0x1d39cc cmp r2, #0 */
/* @0x1d39d0 ldrne r2, [r3, #0x4] */
/* @0x1d39d4 movne lr, #0 */
/* @0x1d39d8 str r6, [r0, #0x8] */
/* @0x1d39dc str r4, [r0, #0xc] */
/* @0x1d39e0 strne r2, [r0] */
/* @0x1d39e4 streq r0, [r3, #0x4] */
/* @0x1d39e8 strne r0, [r2, #0x4] */
/* @0x1d39ec streq r0, [r8, r9, lsl #3] */
/* @0x1d39f0 strne r0, [r3, #0x4] */
/* @0x1d39f4 streq r2, [r0, #0x4] */
/* @0x1d39f8 streq r2, [r0] */
/* @0x1d39fc strne lr, [r0, #0x4] */
/* @0x1d3a00 cmp r7, #0 */
/* @0x1d3a04 ldr r3, [r5, #0x8] */
/* @0x1d3a08 add r3, r3, #1 */
/* @0x1d3a0c str r3, [r5, #0x8] */
/* @0x1d3a10 bne 0x1d398c <_Z9StartRoomib+0xac> */
/* @0x1d3a14 ldr r6, [sp, #0x14] */
/* ── 段5：Zeus 字节 → 相机（1d3a18-1d3a2c）
 *   sp+0x14 从「&Run_Room」改存「&0x5428e8」（Zeus 调试器在线字节，DoBreak 卡同址）。
 *   非 0 → 1d41e0 调 CCameraManager::StartRoom() 后回来继续；为 0 直接往下。 */
/* @0x1d3a18 ldr r3, [pc, #0xa08] */
/* @0x1d3a1c ldr r3, [r11, r3] */
/* @0x1d3a20 str r3, [sp, #0x14] */
/* @0x1d3a24 ldrb r3, [r3] */
/* @0x1d3a28 cmp r3, #0 */
/* @0x1d3a2c bne 0x1d41e0 <_Z9StartRoomib+0x900> */
/* ── 段6：层运行时数据 / 粒子挂层 / 绘制尺寸（1d3a30-1d3a3c）
 *   三连尾随调用，r0 都是 Run_Room。顺序固定：先建层运行时数据，再把粒子系统整体挂进层，
 *   最后按房间尺寸设 Draw_Room 的绘制范围。承接来的实例在这一步之后才 AddInstance（段12）。 */
/* @0x1d3a30 ldr r0, [r6] */
/* @0x1d3a34 bl 0x1c5dbc <_ZN13CLayerManager25BuildRoomLayerRuntimeDataEP5CRoom> */
/* @0x1d3a38 bl 0x1a5b9c <_Z29ParticleSystem_AddAllToLayersv> */
/* @0x1d3a3c bl 0x1b29bc <_Z17Draw_Room_SetSizev> */
/* ── 段7：承接表装载（1d3a40-1d3a78）────────────────────────────
 *   sp+0x18 = &0x542a14（已用条数）；1d3a4c 读它，<= 0 就整段跳过（1d43e8）。
 *   r7 = *(0x542a0c) = {+0 capacity、+4 data}；sp+0x24 = GOT 基址（r11 要借去当字节偏移）。
 *   r11 = 0（data 的字节偏移，每轮 +4）、r8 = 0（序号）。
 *   ★ 承接表的内容是 EndRoom 造的：EndRoom 把 +0x67(persistent) 非 0 的实例克隆一份塞进这个
 *     数组、把原件置 +0x68=1，然后把 data ReAlloc 成 10 项、used 清 0（0x1d17a8-0x1d17e8、0x1d19f0）。 */
/* @0x1d3a40 ldr r3, [pc, #0x9e4] */
/* @0x1d3a44 ldr r3, [r11, r3] */
/* @0x1d3a48 str r3, [sp, #0x18] */
/* @0x1d3a4c ldr r3, [r3] */
/* @0x1d3a50 cmp r3, #0 */
/* @0x1d3a54 ldr r3, [pc, #0x9d4] */
/* @0x1d3a58 ble 0x1d43e8 <_Z9StartRoomib+0xb08> */
/* @0x1d3a5c ldr r0, [pc, #0x9d0] */
/* @0x1d3a60 mov r12, #0 */
/* @0x1d3a64 mov r8, r12 */
/* @0x1d3a68 add r0, pc, r0 */
/* @0x1d3a6c str r0, [sp, #0x28] */
/* @0x1d3a70 ldr r7, [r11, r3] */
/* @0x1d3a74 str r11, [sp, #0x24] */
/* @0x1d3a78 mov r11, r12 */
/* ── 段8：按 id 在房间实例链里找同一个 id（1d3a7c-1d3ad0）
 *   src = data[i]（i < used 才取，否则 r4 = 0）；r9 = src->[0x78]（id）。
 *   从 room->[0x80] 起沿 +0x178 走，比较 node->[0x78] == r9：
 *     命中在链头 → 1d3ab4 的 b 到 1d3e44（r5 = 命中实例）
 *     命中在链中 → 1d3e48（r5 已在循环里）
 *   两次「取 next」都在比较之前（1d3aa8/1d3abc），所以命中时 r5 已是候选、r2 是后继。
 *   ★ 1d3a8c 的 r4=0 只在 i >= used 时发生，而循环条件（1d3a84/1d3c70）已排除它，
 *     但 1d3a9c 会立刻解引用 r4 —— 又一处「不可达的防御代码」。
 *   找不到 → 落到 1d3ad4 新建。 */
/* @0x1d3a7c ldr r3, [r7] */
/* @0x1d3a80 ldr r10, [r6] */
/* @0x1d3a84 cmp r3, r8 */
/* @0x1d3a88 ldrgt r3, [r7, #0x4] */
/* @0x1d3a8c movle r4, #0 */
/* @0x1d3a90 ldrgt r4, [r3, r11] */
/* @0x1d3a94 ldr r3, [r10, #0x80] */
/* @0x1d3a98 cmp r3, #0 */
/* @0x1d3a9c ldr r9, [r4, #0x78] */
/* @0x1d3aa0 beq 0x1d3ad4 <_Z9StartRoomib+0x1f4> */
/* @0x1d3aa4 ldr r2, [r3, #0x78] */
/* @0x1d3aa8 ldr r5, [r3, #0x178] */
/* @0x1d3aac cmp r2, r9 */
/* @0x1d3ab0 bne 0x1d3acc <_Z9StartRoomib+0x1ec> */
/* @0x1d3ab4 b 0x1d3e44 <_Z9StartRoomib+0x564> */
/* @0x1d3ab8 ldr r3, [r5, #0x78] */
/* @0x1d3abc ldr r2, [r5, #0x178] */
/* @0x1d3ac0 cmp r3, r9 */
/* @0x1d3ac4 beq 0x1d3e48 <_Z9StartRoomib+0x568> */
/* @0x1d3ac8 mov r5, r2 */
/* @0x1d3acc cmp r5, #0 */
/* @0x1d3ad0 bne 0x1d3ab8 <_Z9StartRoomib+0x1d8> */
/* ── 段9：找不到同 id → new 一个实例（1d3ad4-1d3b10）────────────
 *   operator new(432)；CInstance::CInstance(r1 = src->[0xb4](x), r2 = src->[0xb8](y),
 *   r3 = src->[0x78](id), [sp] = src->[0x7c](object_index), [sp+4] = 0(false))。
 *   ⇒ +0x78 是 id、+0x7c 是 object_index（1d3b08/1d3b0c 与 1d3ad4/1d3ae4 的搬运互相印证）。 */
/* @0x1d3ad4 ldr r3, [r4, #0x7c] */
/* @0x1d3ad8 mov r0, #432 */
/* @0x1d3adc ldr r1, [r4, #0xb4] */
/* @0x1d3ae0 ldr r10, [r4, #0xb8] */
/* @0x1d3ae4 str r3, [sp, #0xc] */
/* @0x1d3ae8 str r1, [sp, #0x10] */
/* @0x1d3aec bl 0x27c524 <_Znwj> */
/* @0x1d3af0 ldr r3, [sp, #0xc] */
/* @0x1d3af4 mov lr, #0 */
/* @0x1d3af8 ldr r1, [sp, #0x10] */
/* @0x1d3afc mov r2, r10 */
/* @0x1d3b00 str lr, [sp, #0x4] */
/* @0x1d3b04 str r3, [sp] */
/* @0x1d3b08 mov r3, r9 */
/* @0x1d3b0c mov r5, r0 */
/* @0x1d3b10 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* ── 段10：可选深度复制 / Assign / 重建物理体（1d3b14-1d3b40）
 *   [Zeus 字节] 非 0 才把 depth(+0x180) 从源抄过来（1d3b18-1d3b24）。
 *   CInstance::Assign(dst, src, true) —— 把自己造/复用出来的实例的整份状态改写成源的；
 *   RebuildPhysicsBody(Run_Room) 必须在 Assign 之后，才能按新尺寸/位置重建刚体。 */
/* @0x1d3b14 ldr r12, [sp, #0x14] */
/* @0x1d3b18 ldrb r3, [r12] */
/* @0x1d3b1c cmp r3, #0 */
/* @0x1d3b20 ldrne r3, [r4, #0x180] */
/* @0x1d3b24 strne r3, [r5, #0x180] */
/* @0x1d3b28 mov r2, #1 */
/* @0x1d3b2c mov r0, r5 */
/* @0x1d3b30 mov r1, r4 */
/* @0x1d3b34 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1d3b38 ldr r1, [r6] */
/* @0x1d3b3c mov r0, r5 */
/* @0x1d3b40 bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> */
/* ── 段11：插入 depth 有序链（1d3b44-1d3b94）────────────────────
 *   room->[0x88]++（★ 只加一次 → 这是**一张**表，不是两张）。
 *   从链尾 room->[0x84] 起沿 +0x17c 后退，比较节点缓存的 depth(+0x184) 与本实例 depth(+0x180)：
 *     node.[0x184] <= new.depth → 插到该节点「后面」（朝链尾方向，1d3f7c）
 *     走空（r3==0）→ 新实例成为新链头：new.next = 老链头、老链头.prev = new、room->[0x80] = new、
 *                    new.prev = 0、new.[0x184] = depth（1d3b80-1d3b94）
 *   ⇒ 头 room+0x84 / 尾 room+0x80 / next +0x17c / prev +0x178 / 缓存深度 +0x184。
 *   ⚠ 修正（2026-10-28，本函数尾插现场 0x1d3b80..0x1d3b94）：tail=[+0x80]、tail[0x17c]=inst、
 *     inst[0x178]=tail、[+0x80]=inst、inst[0x17c]=0 —— 与 CRoom::DeSerialise 0x1acd58 完全一致。
 *     早先本卡写的「+0x80 头 / +0x178 next」是反的，已作废。 */
/* @0x1d3b44 ldr r2, [r6] */
/* @0x1d3b48 ldr r3, [r2, #0x84] */
/* @0x1d3b4c ldr r1, [r2, #0x88] */
/* @0x1d3b50 cmp r3, #0 */
/* @0x1d3b54 vldrne s14, [r5, #384] */
/* @0x1d3b58 add r1, r1, #1 */
/* @0x1d3b5c str r1, [r2, #0x88] */
/* @0x1d3b60 beq 0x1d41ac <_Z9StartRoomib+0x8cc> */
/* @0x1d3b64 vldr s15, [r3, #388] */
/* @0x1d3b68 vcmpe.f32 s15, s14 */
/* @0x1d3b6c vmrs APSR_nzcv, fpscr */
/* @0x1d3b70 bls 0x1d3f7c <_Z9StartRoomib+0x69c> */
/* @0x1d3b74 ldr r3, [r3, #0x17c] */
/* @0x1d3b78 cmp r3, #0 */
/* @0x1d3b7c bne 0x1d3b64 <_Z9StartRoomib+0x284> */
/* @0x1d3b80 ldr r1, [r2, #0x80] */
/* @0x1d3b84 vstr s14, [r5, #388] */
/* @0x1d3b88 str r5, [r1, #0x17c] */
/* @0x1d3b8c str r1, [r5, #0x178] */
/* @0x1d3b90 str r5, [r2, #0x80] */
/* @0x1d3b94 str r3, [r5, #0x17c] */
/* ── 段12：id 表插入 + 字段定值 + 挂层（1d3b98-1d3c40）
 *   与段4 同一套 id 表插入（Alloc 16、"Hash.h" 306、桶尾追加、count++），key = 新实例 +0x78。
 *   ★ Alloc 的四个实参在 1d3b9c-1d3bac 摆好（r2 = 行号 306、r3 = true、r1 = "Hash.h"、r0 = 16），
 *     但 1d3bb4-1d3bc8 又插进来取桶（r9 = *(GOT)、ldm r9,{r10,r12} 取 {buckets,mask}），1d3bcc 才 bl ——
 *     与段4 同构，只是寄存器分配不同。
 *   三个字段：+0x174 = 0、+0x170 = -1、+0x6b = 1（与段22 的命中分支完全一致）。
 *   CLayerManager::AddInstance(Run_Room, inst) 是「进层」的唯一入口，在字段定值之后。 */
/* @0x1d3b98 ldr r12, [r5, #0x78] */
/* @0x1d3b9c movw r2, #0x132 */
/* @0x1d3ba0 ldr lr, [pc, #0x878] */
/* @0x1d3ba4 mov r3, #1 */
/* @0x1d3ba8 ldr r1, [sp, #0x28] */
/* @0x1d3bac mov r0, #16 */
/* @0x1d3bb0 str r12, [sp, #0x1c] */
/* @0x1d3bb4 ldr r12, [sp, #0x24] */
/* @0x1d3bb8 ldr r9, [r12, lr] */
/* @0x1d3bbc ldr lr, [sp, #0x1c] */
/* @0x1d3bc0 ldm r9, {r10, r12} */
/* @0x1d3bc4 and r12, lr, r12 */
/* @0x1d3bc8 str r12, [sp, #0x10] */
/* @0x1d3bcc bl 0x27ce78 <_ZN13MemoryManager5AllocEjPKcib> */
/* @0x1d3bd0 ldr r12, [sp, #0x10] */
/* @0x1d3bd4 ldr r1, [sp, #0x1c] */
/* @0x1d3bd8 ldr r2, [r10, r12, lsl #3] */
/* @0x1d3bdc add r3, r10, r12, lsl #3 */
/* @0x1d3be0 cmp r2, #0 */
/* @0x1d3be4 ldrne r2, [r3, #0x4] */
/* @0x1d3be8 str r1, [r0, #0x8] */
/* @0x1d3bec mov r1, r5 */
/* @0x1d3bf0 strne r2, [r0] */
/* @0x1d3bf4 str r5, [r0, #0xc] */
/* @0x1d3bf8 streq r0, [r3, #0x4] */
/* @0x1d3bfc strne r0, [r2, #0x4] */
/* @0x1d3c00 movne r2, #0 */
/* @0x1d3c04 strne r0, [r3, #0x4] */
/* @0x1d3c08 ldr r3, [r9, #0x8] */
/* @0x1d3c0c streq r0, [r10, r12, lsl #3] */
/* @0x1d3c10 mov r12, #0 */
/* @0x1d3c14 streq r2, [r0, #0x4] */
/* @0x1d3c18 add r3, r3, #1 */
/* @0x1d3c1c streq r2, [r0] */
/* @0x1d3c20 strne r2, [r0, #0x4] */
/* @0x1d3c24 mvn r2, #0 */
/* @0x1d3c28 strb r12, [r5, #0x174] */
/* @0x1d3c2c str r2, [r5, #0x170] */
/* @0x1d3c30 ldr r0, [r6] */
/* @0x1d3c34 str r3, [r9, #0x8] */
/* @0x1d3c38 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1d3c3c mov lr, #1 */
/* @0x1d3c40 strb lr, [r5, #0x6b] */
/* ── 段13：销毁源克隆 + 清槽 + 循环尾（1d3c44-1d3c74）
 *   ldr r3,[r4] / ldr r3,[r3,#4] / blx r3 = 调源实例 vtable[1]（无 delete 跟随，语义未钉）；
 *   data[i] = 0；字节偏移 +4；序号 r8++（先加），与 *0x542a14 比较决定是否再跑一轮。
 *   ⇒ 承接表是一次性消耗品：克隆被实体化后立即销毁。 */
/* @0x1d3c44 ldr r3, [r4] */
/* @0x1d3c48 mov r0, r4 */
/* @0x1d3c4c add r8, r8, #1 */
/* @0x1d3c50 ldr r3, [r3, #0x4] */
/* @0x1d3c54 blx r3 */
/* @0x1d3c58 ldr r12, [sp, #0x18] */
/* @0x1d3c5c ldr r3, [r7, #0x4] */
/* @0x1d3c60 mov lr, #0 */
/* @0x1d3c64 ldr r2, [r12] */
/* @0x1d3c68 str lr, [r3, r11] */
/* @0x1d3c6c add r11, r11, #4 */
/* @0x1d3c70 cmp r2, r8 */
/* @0x1d3c74 bgt 0x1d3a7c <_Z9StartRoomib+0x19c> */
/* ── 段14：释放承接表 + 三清零 + had_room 分支（1d3c78-1d3cd8）
 *   恢复 r11 = GOT 基址；r4 = data；空 → 1d43c0 短路。
 *   按 capacity（[r7]）把 data 逐项清 0 → MemoryManager::Free(data) → data = 0 → capacity = 0
 *   → used(0x542a14) = 0。★ 这里是「Free 而不是留着复用」，与 EndRoom 每次 ReAlloc 呼应。
 *   1d3cd8 beq 0x1d3fb0：had_room == 0（新建房间）才走创建顺序事件循环（段25-29）。 */
/* @0x1d3c78 ldr r11, [sp, #0x24] */
/* @0x1d3c7c ldr r4, [r7, #0x4] */
/* @0x1d3c80 cmp r4, #0 */
/* @0x1d3c84 beq 0x1d43c0 <_Z9StartRoomib+0xae0> */
/* @0x1d3c88 ldr r2, [r7] */
/* @0x1d3c8c cmp r2, #0 */
/* @0x1d3c90 ble 0x1d3cb0 <_Z9StartRoomib+0x3d0> */
/* @0x1d3c94 mov r3, #0 */
/* @0x1d3c98 mov r1, r3 */
/* @0x1d3c9c str r1, [r4, r3, lsl #2] */
/* @0x1d3ca0 add r3, r3, #1 */
/* @0x1d3ca4 cmp r3, r2 */
/* @0x1d3ca8 ldr r4, [r7, #0x4] */
/* @0x1d3cac bne 0x1d3c9c <_Z9StartRoomib+0x3bc> */
/* @0x1d3cb0 mov r0, r4 */
/* @0x1d3cb4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d3cb8 mov r3, #0 */
/* @0x1d3cbc str r3, [r7, #0x4] */
/* @0x1d3cc0 ldr r12, [sp, #0x20] */
/* @0x1d3cc4 mov r3, #0 */
/* @0x1d3cc8 str r3, [r7] */
/* @0x1d3ccc cmp r12, #0 */
/* @0x1d3cd0 ldr r12, [sp, #0x18] */
/* @0x1d3cd4 str r3, [r12] */
/* @0x1d3cd8 beq 0x1d3fb0 <_Z9StartRoomib+0x6d0> */
/* ── 段15：RemoveMarked / used 清零 / Game Start / had_room 门 / 创建代码前置检查（1d3cdc-1d3d20）
 *   1d3cdc-1d3ce0：CRoom::RemoveMarked(Run_Room)（统一回收 +0x68 标记的实例）。
 *   1d3cf4：*0x542a14 = 0（段14 之后第二次清，保证承接表彻底归零）。
 *   1d3cf8 bne 0x1d41c8：bGameStart 才抛 Perform_Event_All(7,2)（段33）。
 *   1d3d04 bne 0x1d3e00：had_room 非 0（持久房间重入）→ 跳过创建代码，直接去 Room Start。
 *   1d3d08/1d3d18：room->[0x68]（源码串）与 room->[0x6c]（CCode*）**都**非 0 才跑创建代码。 */
/* @0x1d3cdc ldr r0, [r6] */
/* @0x1d3ce0 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d3ce4 ldr r12, [sp, #0x2c] */
/* @0x1d3ce8 mov r3, #0 */
/* @0x1d3cec cmp r12, #0 */
/* @0x1d3cf0 ldr r12, [sp, #0x18] */
/* @0x1d3cf4 str r3, [r12] */
/* @0x1d3cf8 bne 0x1d41c8 <_Z9StartRoomib+0x8e8> */
/* @0x1d3cfc ldr r12, [sp, #0x20] */
/* @0x1d3d00 cmp r12, #0 */
/* @0x1d3d04 bne 0x1d3e00 <_Z9StartRoomib+0x520> */
/* @0x1d3d08 ldr r3, [r6] */
/* @0x1d3d0c ldr r2, [r3, #0x68] */
/* @0x1d3d10 cmp r2, #0 */
/* @0x1d3d14 beq 0x1d3e00 <_Z9StartRoomib+0x520> */
/* @0x1d3d18 ldr r2, [r3, #0x6c] */
/* @0x1d3d1c cmp r2, #0 */
/* @0x1d3d20 beq 0x1d3e00 <_Z9StartRoomib+0x520> */
/* ── 段16：GC 开关字节门 + 分配临时实例（1d3d24-1d3d40）
 *   0x47f295（DoGenerationalGC 卡的「生成式 GC 开关」，也是 PushContextStack 的门）非 0
 *   → 1d417c：直接在 *(0x544be0) 这个全局变量宿主实例上跑创建代码，不 new（段30）。
 *   为 0 → 本段：operator new(432)。r5 = sp+0x30 = &RValue，留给 Code_Execute 当结果槽。 */
/* @0x1d3d24 ldr r3, [pc, #0x70c] */
/* @0x1d3d28 ldr r3, [r11, r3] */
/* @0x1d3d2c ldrb r3, [r3] */
/* @0x1d3d30 cmp r3, #0 */
/* @0x1d3d34 bne 0x1d417c <_Z9StartRoomib+0x89c> */
/* @0x1d3d38 mov r0, #432 */
/* @0x1d3d3c add r5, sp, #48 */
/* @0x1d3d40 bl 0x27c524 <_Znwj> */
/* ── 段17：构造临时实例 + 初始化 RValue + Code_Execute(房间创建代码, 第5实参 5)（1d3d44-1d3da4）
 *   r3 = [sp+0x20] = had_room = 0（这里必为 0）→ CInstance::CInstance(0,0,0,0,false)：
 *   r1/r2 = 0.0/0.0、r3 = 0、[sp] = 0、[sp+4] = 0。
 *   1d3d60-1d3d74：对 sp+0x3c 的 tag 做「减 1、去高字节、去低 2 位后非 0 才跳过」的检查，
 *   命中就先 FREE_RValue__Pre(&rv)（1d43dc）—— 这一槽此刻还没被本函数写过，属复用同一 RValue
 *   槽的防御性释放。
 *   1d3d90 r2 = room->[0x6c]（CCode*）；1d3d94-1d3da0 把 RValue 复位成 {+0=0, +8=0, +0xc=5}；
 *   1d3da4 Code_Execute(self=tmp, other=tmp, code=room->[0x6c], &rv, 5)。
 *   ★ 实参顺序证明：r0/r1 都是 tmp、r2 来自 room->[0x6c]、r3 = sp+0x30。 */
/* @0x1d3d44 ldr r3, [sp, #0x20] */
/* @0x1d3d48 mov r1, #0 */
/* @0x1d3d4c mov r2, r1 */
/* @0x1d3d50 str r3, [sp] */
/* @0x1d3d54 str r3, [sp, #0x4] */
/* @0x1d3d58 mov r4, r0 */
/* @0x1d3d5c bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1d3d60 ldr r3, [sp, #0x3c] */
/* @0x1d3d64 sub r3, r3, #1 */
/* @0x1d3d68 bic r3, r3, #-16777216 */
/* @0x1d3d6c bic r3, r3, #3 */
/* @0x1d3d70 cmp r3, #0 */
/* @0x1d3d74 beq 0x1d43dc <_Z9StartRoomib+0xafc> */
/* @0x1d3d78 ldr r2, [r6] */
/* @0x1d3d7c mov r12, #0 */
/* @0x1d3d80 mov r3, r5 */
/* @0x1d3d84 mov r0, r4 */
/* @0x1d3d88 mov r1, r4 */
/* @0x1d3d8c mov lr, #5 */
/* @0x1d3d90 ldr r2, [r2, #0x6c] */
/* @0x1d3d94 str r12, [sp] */
/* @0x1d3d98 str r12, [sp, #0x38] */
/* @0x1d3d9c str r12, [sp, #0x30] */
/* @0x1d3da0 str lr, [sp, #0x3c] */
/* @0x1d3da4 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* ── 段18：创建代码返回值的释放判定（1d3da8-1d3dc0）
 *   tag = [sp+0x3c]；t = ((tag-1) & 0x00FFFFFF) & ~3；t == 0 ⇒ tag ∈ {1,2,3,4}（字符串/数组/指针类）
 *   → 1d43d0 FREE_RValue__Pre(&rv)。tag 仍是 5（undefined）就什么也不做。 */
/* @0x1d3da8 ldr r3, [sp, #0x3c] */
/* @0x1d3dac sub r3, r3, #1 */
/* @0x1d3db0 bic r3, r3, #-16777216 */
/* @0x1d3db4 bic r3, r3, #3 */
/* @0x1d3db8 cmp r3, #0 */
/* @0x1d3dbc beq 0x1d43d0 <_Z9StartRoomib+0xaf0> */
/* ── 段19：销毁临时实例（1d3dc0-1d3de8）
 *   先把 RValue 再复位成 {0,0,tag5}（丢弃返回值），再 if (tmp) tmp->vtable[1](tmp)。
 *   ★ 与段13 同一调用形状（vtable 第 2 槽、无 delete 跟随）；vtable[1] 的正式语义未钉。 */
/* @0x1d3dc0 cmp r4, #0 */
/* @0x1d3dc4 mov r3, #0 */
/* @0x1d3dc8 mov r2, #5 */
/* @0x1d3dcc str r3, [sp, #0x38] */
/* @0x1d3dd0 str r3, [sp, #0x30] */
/* @0x1d3dd4 str r2, [sp, #0x3c] */
/* @0x1d3dd8 beq 0x1d3dec <_Z9StartRoomib+0x50c> */
/* @0x1d3ddc ldr r3, [r4] */
/* @0x1d3de0 mov r0, r4 */
/* @0x1d3de4 ldr r3, [r3, #0x4] */
/* @0x1d3de8 blx r3 */
/* ── 段20：未知门字节 → exit(0)（1d3dec-1d3dfc）
 *   *(uint8_t*)0x7590b1 非 0 就 1d4404 exit(0)。该 GOT 偏移在全 .text 只有两处池字（本卡 + ProcessCommandLine），
 *   谁写它未证 —— 推测是「创建代码里要求退出游戏」的落点，本卡只记事实。 */
/* @0x1d3dec ldr r3, [pc, #0x648] */
/* @0x1d3df0 ldr r3, [r11, r3] */
/* @0x1d3df4 ldrb r3, [r3] */
/* @0x1d3df8 cmp r3, #0 */
/* @0x1d3dfc bne 0x1d4404 <_Z9StartRoomib+0xb24> */
/* ── 段21：Perform_Event_All(7,4) + 收尾（1d3e00-1d3e40）
 *   7/4 = Room Start（编号见头部事件号说明）。之后又做一次 RValue 释放判定（tag 1..4 → 1d41a0），
 *   再把 byte 0x542a48 置 1，撤帧返回。
 *   ★ 0x542a48 这个 GOT 偏移在全 .text 只出现这一次 —— 静态上「只写不读」，读点只能来自 .data 里的指针。 */
/* @0x1d3e00 mov r0, #7 */
/* @0x1d3e04 mov r1, #4 */
/* @0x1d3e08 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d3e0c ldr r0, [r6] */
/* @0x1d3e10 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d3e14 ldr r3, [sp, #0x3c] */
/* @0x1d3e18 sub r3, r3, #1 */
/* @0x1d3e1c bic r3, r3, #-16777216 */
/* @0x1d3e20 bic r3, r3, #3 */
/* @0x1d3e24 cmp r3, #0 */
/* @0x1d3e28 beq 0x1d41a0 <_Z9StartRoomib+0x8c0> */
/* @0x1d3e2c ldr r3, [pc, #0x60c] */
/* @0x1d3e30 mov r2, #1 */
/* @0x1d3e34 ldr r3, [r11, r3] */
/* @0x1d3e38 strb r2, [r3] */
/* @0x1d3e3c add sp, sp, #68 */
/* @0x1d3e40 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 段22：命中分支：复用同 id 的既有实例（1d3e44-1d3e98）──
 *   r5 = 命中实例（1d3aac 命中走这里，1d3ac0 命中则 1d3e48 直接进）。
 *   [Zeus] 非 0 → 1d3e9c 的定点摘链（段23）；否则 1d3e58：
 *     Assign(match, src, true) → RebuildPhysicsBody(match, Run_Room)
 *     → match->[0x174] = 0、[0x170] = -1、[0x6b] = 1 → CLayerManager::AddInstance → 回 1d3c44。
 *   ★ Assign(源,true) 会把源克隆的字段整份拷过来，而克隆是新建的（+0x68 == 0）——
 *     所以持久房间重入时，被 EndRoom 置了 +0x68 = 1 的原实例正是在这一步复活的（顺序：先 Assign 后挂层）。 */
/* @0x1d3e44 mov r5, r3 */
/* @0x1d3e48 ldr r12, [sp, #0x14] */
/* @0x1d3e4c ldrb r3, [r12] */
/* @0x1d3e50 cmp r3, #0 */
/* @0x1d3e54 bne 0x1d3e9c <_Z9StartRoomib+0x5bc> */
/* @0x1d3e58 mov r0, r5 */
/* @0x1d3e5c mov r1, r4 */
/* @0x1d3e60 mov r2, #1 */
/* @0x1d3e64 bl 0x1986ec <_ZN9CInstance6AssignEPS_b> */
/* @0x1d3e68 mov r0, r5 */
/* @0x1d3e6c ldr r1, [r6] */
/* @0x1d3e70 bl 0x192fa4 <_ZN9CInstance18RebuildPhysicsBodyEP5CRoom> */
/* @0x1d3e74 mov lr, #1 */
/* @0x1d3e78 mov r0, #0 */
/* @0x1d3e7c mvn r3, #0 */
/* @0x1d3e80 strb r0, [r5, #0x174] */
/* @0x1d3e84 mov r1, r5 */
/* @0x1d3e88 strb lr, [r5, #0x6b] */
/* @0x1d3e8c str r3, [r5, #0x170] */
/* @0x1d3e90 ldr r0, [r6] */
/* @0x1d3e94 bl 0x1c5d18 <_ZN13CLayerManager11AddInstanceEP5CRoomP9CInstance> */
/* @0x1d3e98 b 0x1d3c44 <_Z9StartRoomib+0x364> */
/* ── 段23：Zeus 分支：抄 depth + 按 id 从房间层表里定点摘除（1d3e9c-1d3f78）
 *   1d3e9c/1d3ea0：match->[0x180] = src->[0x180]。
 *   1d3ea4-1d3ed8：hash = CHashMapCalculateHash(src->[0x78]) & 0x7FFFFFFF，h = hash & room->[0x118]，
 *     槽 = room->[0x120] + 12*h，槽内 +8 是存进来的 key（hash）：0 = 空 → 未命中（去 1d3e58 正常路径），
 *     相等 → 命中（1d3f48）。
 *   1d3edc-1d3f44：不相等时按「探测距离」继续（rsb 算 distance、tst+bmi 判负、循环里比对距离后放弃），
 *     形似 robin-hood 线性探测；room->[0x110] 是表的容量，距离 = (h + 容量) - 键的 home 桶。
 *   1d3f48-1d3f78：命中项 +4 → 记录对象；记录 +0x20 → CInstance*；非空则
 *     CLayerManager::RemoveInstance(Run_Room, 该实例)。★ 该实例是不是 src 本身无法静态判定（同 id），
 *     所以这里只记「按 id 找到层记录再摘除」。1d3f50 的 cmn r9,#4 是哨兵比较，含义未钉。 */
/* @0x1d3e9c ldr r3, [r4, #0x180] */
/* @0x1d3ea0 str r3, [r5, #0x180] */
/* @0x1d3ea4 ldr r0, [r4, #0x78] */
/* @0x1d3ea8 bl 0x1b6e44 <_Z21CHashMapCalculateHashi> */
/* @0x1d3eac ldr r1, [r10, #0x118] */
/* @0x1d3eb0 ldr r9, [r10, #0x120] */
/* @0x1d3eb4 bic r0, r0, #-2147483648 */
/* @0x1d3eb8 and r3, r0, r1 */
/* @0x1d3ebc lsl lr, r3, #1 */
/* @0x1d3ec0 add r2, lr, r3 */
/* @0x1d3ec4 add r2, r9, r2, lsl #2 */
/* @0x1d3ec8 ldr r2, [r2, #0x8] */
/* @0x1d3ecc cmp r2, #0 */
/* @0x1d3ed0 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3ed4 cmp r0, r2 */
/* @0x1d3ed8 beq 0x1d3f48 <_Z9StartRoomib+0x668> */
/* @0x1d3edc ldr r10, [r10, #0x110] */
/* @0x1d3ee0 and r2, r1, r2 */
/* @0x1d3ee4 add r12, r3, r10 */
/* @0x1d3ee8 rsb r2, r2, r12 */
/* @0x1d3eec tst r2, r1 */
/* @0x1d3ef0 bmi 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3ef4 mov r12, #0 */
/* @0x1d3ef8 b 0x1d3f14 <_Z9StartRoomib+0x634> */
/* @0x1d3efc and r2, r1, r2 */
/* @0x1d3f00 add lr, r3, r10 */
/* @0x1d3f04 rsb r2, r2, lr */
/* @0x1d3f08 and r2, r2, r1 */
/* @0x1d3f0c cmp r2, r12 */
/* @0x1d3f10 blt 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f14 add r3, r3, #1 */
/* @0x1d3f18 add r12, r12, #1 */
/* @0x1d3f1c and r3, r1, r3 */
/* @0x1d3f20 lsl lr, r3, #1 */
/* @0x1d3f24 add r2, lr, r3 */
/* @0x1d3f28 add r2, r9, r2, lsl #2 */
/* @0x1d3f2c ldr r2, [r2, #0x8] */
/* @0x1d3f30 cmp r2, #0 */
/* @0x1d3f34 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f38 cmp r0, r2 */
/* @0x1d3f3c bne 0x1d3efc <_Z9StartRoomib+0x61c> */
/* @0x1d3f40 cmn r3, #1 */
/* @0x1d3f44 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f48 add r3, lr, r3 */
/* @0x1d3f4c add r9, r9, r3, lsl #2 */
/* @0x1d3f50 cmn r9, #4 */
/* @0x1d3f54 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f58 ldr r3, [r9, #0x4] */
/* @0x1d3f5c cmp r3, #0 */
/* @0x1d3f60 beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f64 ldr r1, [r3, #0x20] */
/* @0x1d3f68 cmp r1, #0 */
/* @0x1d3f6c beq 0x1d3e58 <_Z9StartRoomib+0x578> */
/* @0x1d3f70 ldr r0, [r6] */
/* @0x1d3f74 bl 0x1b9e5c <_ZN13CLayerManager14RemoveInstanceEP5CRoomP9CInstance> */
/* @0x1d3f78 b 0x1d3e58 <_Z9StartRoomib+0x578> */
/* ── 段24：链非空时的插入（1d3f7c-1d3fac）──────────────────────
 *   r1 = r3->[0x178]（r3 是第一个 cache_depth <= new.depth 的节点）：
 *     r1 == 0（r3 是链尾）→ new.prev = r3、r3.next = new、room->[0x84] = new、new.next = 0
 *     r1 != 0            → new.next = r1、new.prev = r3、r1.prev = new、r3.next = new
 *   ⇒ 双向插入的四个指针与「尾指针 +0x84」在这一段被同时写，证明 +0x178/+0x17c 是 next/prev。 */
/* @0x1d3f7c ldr r1, [r3, #0x178] */
/* @0x1d3f80 cmp r1, #0 */
/* @0x1d3f84 streq r3, [r5, #0x17c] */
/* @0x1d3f88 strne r1, [r5, #0x178] */
/* @0x1d3f8c ldrne r2, [r3, #0x178] */
/* @0x1d3f90 streq r5, [r3, #0x178] */
/* @0x1d3f94 strne r3, [r5, #0x17c] */
/* @0x1d3f98 streq r5, [r2, #0x84] */
/* @0x1d3f9c strne r5, [r2, #0x17c] */
/* @0x1d3fa0 streq r1, [r5, #0x178] */
/* @0x1d3fa4 strne r5, [r3, #0x178] */
/* @0x1d3fa8 vstr s14, [r5, #388] */
/* @0x1d3fac b 0x1d3b98 <_Z9StartRoomib+0x2b8> */
/* ── 段25：创建顺序表循环头（1d3fb0-1d3fdc）────────────────────
 *   只在 had_room == 0（新房间）时进入。r8 = 1（后面既当 +0x6c=1 又当 Code_Execute 的第 5 实参），
 *   r4 = [sp+0x20] = 0 = i，r7 = 5（RValue tag），r9 = sp+0x30（&RValue），r10 = r4 = 0（零值/第 5 实参）。
 *   界：room->[0xa8]（元素数）；表：room->[0xa4]（id 数组，i*4）。 */
/* @0x1d3fb0 ldr r3, [r6] */
/* @0x1d3fb4 mov r8, #1 */
/* @0x1d3fb8 ldr r4, [sp, #0x20] */
/* @0x1d3fbc mov r7, #5 */
/* @0x1d3fc0 add r9, sp, #48 */
/* @0x1d3fc4 ldr r12, [r3, #0xa8] */
/* @0x1d3fc8 mov r10, r4 */
/* @0x1d3fcc ldr r0, [r3, #0xa4] */
/* @0x1d3fd0 cmp r4, r12 */
/* @0x1d3fd4 bge 0x1d404c <_Z9StartRoomib+0x76c> */
/* @0x1d3fd8 ldr r2, [pc, #0x440] */
/* @0x1d3fdc ldr r3, [r0, r4, lsl #2] */
/* ── 段26：按 id 查全局实例表 + 两道闸门（1d3fe0-1d4048）
 *   查 0x536f28（与段4/12 同一张表）：hash & mask → 桶 → 沿 +4 链比较节点 +8 的 key。
 *   命中 → r5 = 节点 +0xc（实例）；未命中/实例 0 → 下一个 id。
 *   闸门：+0x6b 非 0 → 把它清 0 并跳过（★ 这就是「承接进来的持久实例不重跑 Create」的机制，
 *         因为段12/22 给它们置了 1）；+0x68 非 0 → 跳过（已销毁）；其余 → 1d4068 派发。 */
/* @0x1d3fe0 ldr r2, [r11, r2] */
/* @0x1d3fe4 ldr r1, [r2, #0x4] */
/* @0x1d3fe8 ldr r2, [r2] */
/* @0x1d3fec and r1, r3, r1 */
/* @0x1d3ff0 ldr r2, [r2, r1, lsl #3] */
/* @0x1d3ff4 cmp r2, #0 */
/* @0x1d3ff8 bne 0x1d400c <_Z9StartRoomib+0x72c> */
/* @0x1d3ffc b 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4000 ldr r2, [r2, #0x4] */
/* @0x1d4004 cmp r2, #0 */
/* @0x1d4008 beq 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d400c ldr r1, [r2, #0x8] */
/* @0x1d4010 cmp r3, r1 */
/* @0x1d4014 bne 0x1d4000 <_Z9StartRoomib+0x720> */
/* @0x1d4018 ldr r5, [r2, #0xc] */
/* @0x1d401c cmp r5, #0 */
/* @0x1d4020 beq 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4024 ldrb r3, [r5, #0x6b] */
/* @0x1d4028 cmp r3, #0 */
/* @0x1d402c strbne r10, [r5, #0x6b] */
/* @0x1d4030 bne 0x1d4040 <_Z9StartRoomib+0x760> */
/* @0x1d4034 ldrb r3, [r5, #0x68] */
/* @0x1d4038 cmp r3, #0 */
/* @0x1d403c beq 0x1d4068 <_Z9StartRoomib+0x788> */
/* @0x1d4040 add r4, r4, #1 */
/* @0x1d4044 cmp r4, r12 */
/* @0x1d4048 blt 0x1d3fd8 <_Z9StartRoomib+0x6f8> */
/* ── 段27：释放创建顺序数组（1d404c-1d4064）──────────────────
 *   MemoryManager::Free(room->[0xa4])；room->[0xa4] = 0；room->[0xa8] = 0。
 *   ★ 这张表是 CRoom::Assign 建房间时追加的（id 逐个 append），跑完 Create 就销毁 ——
 *     所以「创建顺序」只在房间刚建好那一次存在，持久房间重入时它是空的。
 *   之后 b 到 1d3ce0（RemoveMarked）。 */
/* @0x1d404c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d4050 ldr r3, [r6] */
/* @0x1d4054 mov r2, #0 */
/* @0x1d4058 mov r0, r3 */
/* @0x1d405c str r2, [r3, #0xa4] */
/* @0x1d4060 str r2, [r3, #0xa8] */
/* @0x1d4064 b 0x1d3ce0 <_Z9StartRoomib+0x400> */
/* ── 段28：PreCreate(14) + 实例自己的第 1 段代码（1d4068-1d40e4）
 *   Perform_Event_Object(inst, inst, inst->[0x7c](object_index), 14, 0)（第 5 实参 = r3 = 0）。
 *   然后 if (inst->[0x164]) Code_Execute(inst, inst, inst->[0x164], &rv, 1)：RValue 先复位成
 *   {0,0,tag5}（1d40b4-1d40bc），第 5 实参 = r8 = 1；返回值同样按 tag 1..4 释放（1d431c/1d43d0 路径）。
 *   ★ Perform_Event_Object 走对象事件表（含父对象链），Code_Execute 走实例自带的 CCode*，两者成对出现。 */
/* @0x1d4068 ldr r2, [r5, #0x7c] */
/* @0x1d406c mov r0, r5 */
/* @0x1d4070 str r3, [sp] */
/* @0x1d4074 mov r1, r5 */
/* @0x1d4078 mov r3, #14 */
/* @0x1d407c bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x1d4080 ldr r2, [r5, #0x164] */
/* @0x1d4084 cmp r2, #0 */
/* @0x1d4088 beq 0x1d40e8 <_Z9StartRoomib+0x808> */
/* @0x1d408c ldr r3, [sp, #0x3c] */
/* @0x1d4090 sub r3, r3, #1 */
/* @0x1d4094 bic r3, r3, #-16777216 */
/* @0x1d4098 bic r3, r3, #3 */
/* @0x1d409c cmp r3, #0 */
/* @0x1d40a0 beq 0x1d431c <_Z9StartRoomib+0xa3c> */
/* @0x1d40a4 mov r3, r9 */
/* @0x1d40a8 str r8, [sp] */
/* @0x1d40ac mov r0, r5 */
/* @0x1d40b0 mov r1, r5 */
/* @0x1d40b4 str r10, [sp, #0x38] */
/* @0x1d40b8 str r7, [sp, #0x3c] */
/* @0x1d40bc str r10, [sp, #0x30] */
/* @0x1d40c0 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d40c4 ldr r3, [sp, #0x3c] */
/* @0x1d40c8 sub r3, r3, #1 */
/* @0x1d40cc bic r3, r3, #-16777216 */
/* @0x1d40d0 bic r3, r3, #3 */
/* @0x1d40d4 cmp r3, #0 */
/* @0x1d40d8 beq 0x1d4330 <_Z9StartRoomib+0xa50> */
/* @0x1d40dc str r10, [sp, #0x38] */
/* @0x1d40e0 str r7, [sp, #0x3c] */
/* @0x1d40e4 str r10, [sp, #0x30] */
/* ── 段29：Create(0) + 实例自己的第 2 段代码 + 置 +0x6c（1d40e8-1d4178）
 *   Perform_Event_Object(inst, inst, inst->[0x7c], 0, 0)（第 5 实参 = r10 = 0）。
 *   if (inst->[0x160]) Code_Execute(inst, inst, inst->[0x160], &rv, 1)。
 *   末尾 inst->[0x6c] = 1（Create 已跑）后回 1d4040 继续下一个 id。
 *   ⇒ 一个新房间的实例事件顺序：PreCreate(14) [+0x164] → Create(0) [+0x160]，先 14 后 0。 */
/* @0x1d40e8 ldr r2, [r5, #0x7c] */
/* @0x1d40ec mov r0, r5 */
/* @0x1d40f0 str r10, [sp] */
/* @0x1d40f4 mov r1, r5 */
/* @0x1d40f8 mov r3, #0 */
/* @0x1d40fc bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* @0x1d4100 ldr r2, [r5, #0x160] */
/* @0x1d4104 cmp r2, #0 */
/* @0x1d4108 beq 0x1d4168 <_Z9StartRoomib+0x888> */
/* @0x1d410c ldr r3, [sp, #0x3c] */
/* @0x1d4110 sub r3, r3, #1 */
/* @0x1d4114 bic r3, r3, #-16777216 */
/* @0x1d4118 bic r3, r3, #3 */
/* @0x1d411c cmp r3, #0 */
/* @0x1d4120 beq 0x1d433c <_Z9StartRoomib+0xa5c> */
/* @0x1d4124 mov r3, r9 */
/* @0x1d4128 str r8, [sp] */
/* @0x1d412c mov r0, r5 */
/* @0x1d4130 mov r1, r5 */
/* @0x1d4134 str r10, [sp, #0x38] */
/* @0x1d4138 str r7, [sp, #0x3c] */
/* @0x1d413c str r10, [sp, #0x30] */
/* @0x1d4140 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d4144 ldr r3, [sp, #0x3c] */
/* @0x1d4148 sub r3, r3, #1 */
/* @0x1d414c bic r3, r3, #-16777216 */
/* @0x1d4150 bic r3, r3, #3 */
/* @0x1d4154 cmp r3, #0 */
/* @0x1d4158 beq 0x1d4310 <_Z9StartRoomib+0xa30> */
/* @0x1d415c str r10, [sp, #0x38] */
/* @0x1d4160 str r7, [sp, #0x3c] */
/* @0x1d4164 str r10, [sp, #0x30] */
/* @0x1d4168 ldr r3, [r6] */
/* @0x1d416c strb r8, [r5, #0x6c] */
/* @0x1d4170 ldr r12, [r3, #0xa8] */
/* @0x1d4174 ldr r0, [r3, #0xa4] */
/* @0x1d4178 b 0x1d4040 <_Z9StartRoomib+0x760> */
/* ── 段30：GC 开时的替代路径：在全局宿主实例上跑创建代码（1d417c-1d419c）
 *   r1 = &0x544be0（全局变量宿主 CInstance*），r0 = *r1 = 宿主实例；r2 仍是 room->[0x6c]；
 *   r3 = &RValue；[sp] = had_room（= 0）。
 *   Code_Execute(host, host, room->[0x6c], &rv, 5) —— 与段17 同一调用，只是 self/other 换成宿主。
 *   ★ 为什么由 GC 开关字节 0x47f295 二选一，静态上无法解释（可能是「GC 开时不能有游离实例」），
 *     本卡只证「哪个字节决定哪条路径」。跑完 b 到 1d3dec 的门字节检查。 */
/* @0x1d417c ldr r1, [pc, #0x2c0] */
/* @0x1d4180 add r3, sp, #48 */
/* @0x1d4184 ldr r12, [sp, #0x20] */
/* @0x1d4188 ldr r1, [r11, r1] */
/* @0x1d418c str r12, [sp] */
/* @0x1d4190 ldr r0, [r1] */
/* @0x1d4194 mov r1, r0 */
/* @0x1d4198 bl 0xcfc60 <_Z12Code_ExecuteP9CInstanceS0_P5CCodeP6RValuei> */
/* @0x1d419c b 0x1d3dec <_Z9StartRoomib+0x50c> */
/* ── 段31：Room Start 之后的 RValue 释放（1d41a0-1d41a8）
 *   FREE_RValue__Pre(&rv) 后回 1d3e2c（置门字节并返回）。入口是 1d3e28 的 beq。 */
/* @0x1d41a0 add r0, sp, #48 */
/* @0x1d41a4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d41a8 b 0x1d3e2c <_Z9StartRoomib+0x54c> */
/* ── 段32：链为空时的插入（1d41ac-1d41c4）──────────────────────
 *   room->[0x84] = room->[0x80] = new；new->[0x184] = depth；new->[0x17c] = new->[0x178] = 0。
 *   入口是 1d3b60 的 beq（room->[0x84] == 0）。 */
/* @0x1d41ac ldr r1, [r5, #0x180] */
/* @0x1d41b0 str r5, [r2, #0x84] */
/* @0x1d41b4 str r5, [r2, #0x80] */
/* @0x1d41b8 str r1, [r5, #0x184] */
/* @0x1d41bc str r3, [r5, #0x17c] */
/* @0x1d41c0 str r3, [r5, #0x178] */
/* @0x1d41c4 b 0x1d3b98 <_Z9StartRoomib+0x2b8> */
/* ── 段33：Perform_Event_All(7,2) Game Start（1d41c8-1d41dc）
 *   入口是 1d3cf8 的 bne（bGameStart 非 0）。7/2 按编号序列是 Game Start（头部说明），本卡只证参数。
 *   之后 RemoveMarked 再回 1d3cfc，接着才判 had_room、跑创建代码、抛 7/4 —— 即
 *   Game Start 在 Create 之后、房间创建代码与 Room Start 之前。 */
/* @0x1d41c8 mov r0, #7 */
/* @0x1d41cc mov r1, #2 */
/* @0x1d41d0 bl 0xf33b0 <_Z17Perform_Event_Allii> */
/* @0x1d41d4 ldr r0, [r6] */
/* @0x1d41d8 bl 0x1abb24 <_ZN5CRoom12RemoveMarkedEv> */
/* @0x1d41dc b 0x1d3cfc <_Z9StartRoomib+0x41c> */
/* ── 段34：CCameraManager::StartRoom()（1d41e0-1d41ec）
 *   r0 = *(0x48f78c)（相机单例）；入口是 1d3a2c 的 bne（Zeus 字节非 0）。回来后 b 到 1d3a30。 */
/* @0x1d41e0 ldr r3, [pc, #0x260] */
/* @0x1d41e4 ldr r0, [r11, r3] */
/* @0x1d41e8 bl 0x16ec9c <_ZN14CCameraManager9StartRoomEv> */
/* @0x1d41ec b 0x1d3a30 <_Z9StartRoomib+0x150> */
/* ── 段35：新建 CRoom（1d41f0-1d4248）────────────────────────────
 *   operator new(292) → CRoom::CRoom() → g_rooms.array[idx] = 新对象（1d420c 无条件写入；
 *   1d4210/1d4214/1d4218 是 idx < count 的三条条件搬运，把 r5 重新读成 array[idx] ——
 *   由于段2 已保证 idx < count，1d4214 的「r5 = 0」分支不可达）。
 *   Room_Data(idx) → CRoom::Assign(newRoom, roomData, true)：房间自带的实例、层、物理体、碰撞、
 *   以及 room+0xa4 的创建顺序 id 表都在这一步造出来（CRoom::Assign 0x1adec0-0x1ae0d8 里追加 id）。
 *   最后再 Run_Room_Set(array[idx])（此时非 0），b 到 1d3a18。
 *   ★ 所以「新房间的实例」是 CRoom::Assign 造的，「承接来的实例」是段9/22 造的，两者汇合在段11-12 的链/层。 */
/* @0x1d41f0 mov r0, #292 */
/* @0x1d41f4 bl 0x27c524 <_Znwj> */
/* @0x1d41f8 mov r5, r0 */
/* @0x1d41fc bl 0x1ad2cc <_ZN5CRoomC2Ev> */
/* @0x1d4200 ldm r4, {r2, r3} */
/* @0x1d4204 mov r0, r7 */
/* @0x1d4208 cmp r7, r2 */
/* @0x1d420c str r5, [r3, r7, lsl #2] */
/* @0x1d4210 ldrlt r3, [r4, #0x4] */
/* @0x1d4214 ldrge r5, [sp, #0x20] */
/* @0x1d4218 ldrlt r5, [r3, r7, lsl #2] */
/* @0x1d421c bl 0x1b52c4 <_Z9Room_Datai> */
/* @0x1d4220 mov r2, #1 */
/* @0x1d4224 mov r1, r0 */
/* @0x1d4228 mov r0, r5 */
/* @0x1d422c bl 0x1ad70c <_ZN5CRoom6AssignEPS_b> */
/* @0x1d4230 ldr r3, [r4] */
/* @0x1d4234 cmp r7, r3 */
/* @0x1d4238 ldrlt r3, [r4, #0x4] */
/* @0x1d423c movge r0, #0 */
/* @0x1d4240 ldrlt r0, [r3, r7, lsl #2] */
/* @0x1d4244 bl 0x1cba58 <_Z12Run_Room_SetP5CRoom> */
/* @0x1d4248 b 0x1d3a18 <_Z9StartRoomib+0x138> */
/* ── 段36：roomIndex < 0 → 销毁全部房间（1d424c-1d4304）─────────
 *   r6 = idx+1；idx+1 == 0（即 idx == -1）才进本段（1d4258 的 bne 走段39 的扩容）。
 *   r0 = array；空 → 1d42f8。
 *   遍历 0..count-1：跳过 0 字槽；另外两处 0xEEEEFEEE 判等：1d4284 读的是 array[0]（不是 array[i]，形似「容器已释放」标记），
 *   1d42b8 才针对每个对象的 vtable，
 *   其余 CRoom::~CRoom() + operator delete，槽写 0。
 *   收尾 MemoryManager::Free(array)、array = 0、b 到 1d4374（count = 0 的那套）。
 *   ★ idx == -1 时 1d43b4 仍写 *0x542958 = -1，随后按 array[-1] 取 Run_Room 的实参（array 已是 0）
 *     —— 越界读，静态可达性未证（见头部 open）。 */
/* @0x1d424c add r6, r7, #1 */
/* @0x1d4250 cmp r5, r6 */
/* @0x1d4254 beq 0x1d43f0 <_Z9StartRoomib+0xb10> */
/* @0x1d4258 cmp r6, #0 */
/* @0x1d425c ldr r0, [r4, #0x4] */
/* @0x1d4260 bne 0x1d4350 <_Z9StartRoomib+0xa70> */
/* @0x1d4264 cmp r0, #0 */
/* @0x1d4268 beq 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d426c cmp r5, #0 */
/* @0x1d4270 ble 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d4274 mov r8, r6 */
/* @0x1d4278 mov r10, r6 */
/* @0x1d427c mov r3, r0 */
/* @0x1d4280 str r5, [sp, #0x14] */
/* @0x1d4284 ldr r1, [r3] */
/* @0x1d4288 movw r2, #0xfeee */
/* @0x1d428c movt r2, #0xfeee */
/* @0x1d4290 cmp r1, r2 */
/* @0x1d4294 beq 0x1d42e0 <_Z9StartRoomib+0xa00> */
/* @0x1d4298 ldr r9, [r3, r8, lsl #2] */
/* @0x1d429c lsl r5, r8, #2 */
/* @0x1d42a0 add r1, r3, r5 */
/* @0x1d42a4 cmp r9, #0 */
/* @0x1d42a8 beq 0x1d42e0 <_Z9StartRoomib+0xa00> */
/* @0x1d42ac ldr r0, [r9] */
/* @0x1d42b0 movw r3, #0xfeee */
/* @0x1d42b4 movt r3, #0xfeee */
/* @0x1d42b8 cmp r0, r3 */
/* @0x1d42bc beq 0x1d42d8 <_Z9StartRoomib+0x9f8> */
/* @0x1d42c0 mov r0, r9 */
/* @0x1d42c4 bl 0x1afa00 <_ZN5CRoomD2Ev> */
/* @0x1d42c8 mov r0, r9 */
/* @0x1d42cc bl 0x27d1d0 <_ZdlPv> */
/* @0x1d42d0 ldr r1, [r4, #0x4] */
/* @0x1d42d4 add r1, r1, r5 */
/* @0x1d42d8 str r10, [r1] */
/* @0x1d42dc ldr r3, [r4, #0x4] */
/* @0x1d42e0 ldr r2, [r4] */
/* @0x1d42e4 add r8, r8, #1 */
/* @0x1d42e8 cmp r8, r2 */
/* @0x1d42ec blt 0x1d4284 <_Z9StartRoomib+0x9a4> */
/* @0x1d42f0 ldr r5, [sp, #0x14] */
/* @0x1d42f4 mov r0, r3 */
/* @0x1d42f8 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d42fc mov r3, #0 */
/* @0x1d4300 str r3, [r4, #0x4] */
/* @0x1d4304 b 0x1d4374 <_Z9StartRoomib+0xa94> */
/* ── 段37：IO_Clear（1d4308-1d430c）
 *   只在 bGameStart 非 0 时进入（1d3914 的 bne），回来 b 到 1d3918。 */
/* @0x1d4308 bl 0x18c2c8 <_Z8IO_Clearv> */
/* @0x1d430c b 0x1d3918 <_Z9StartRoomib+0x38> */
/* ── 段38：三处 RValue 释放出口（1d4310-1d434c）─────────────────
 *   1d4310：+0x160 那份代码执行完、tag ∈ 1..4 → 释放后回 1d415c（继续 Create 之后的收尾）。
 *   1d431c：+0x164 那份（1d40a0 的 beq 进来，先把 r2 暂存到 sp+0x10）→ 释放后回 1d40a4。
 *   1d4330：+0x160 的第二个释放点（1d40d8 进来）→ 释放后回 1d40dc。
 *   1d433c：+0x164 的第二个释放点（1d4158 进来）→ 释放后回 1d4124。
 *   ⇒ 四段代码共享同一个 sp+0x30 的 RValue 槽，谁在栈上留了引用值谁负责释放。 */
/* @0x1d4310 mov r0, r9 */
/* @0x1d4314 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4318 b 0x1d415c <_Z9StartRoomib+0x87c> */
/* @0x1d431c mov r0, r9 */
/* @0x1d4320 str r2, [sp, #0x10] */
/* @0x1d4324 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4328 ldr r2, [sp, #0x10] */
/* @0x1d432c b 0x1d40a4 <_Z9StartRoomib+0x7c4> */
/* @0x1d4330 mov r0, r9 */
/* @0x1d4334 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4338 b 0x1d40dc <_Z9StartRoomib+0x7fc> */
/* @0x1d433c mov r0, r9 */
/* @0x1d4340 str r2, [sp, #0x10] */
/* @0x1d4344 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d4348 ldr r2, [sp, #0x10] */
/* @0x1d434c b 0x1d4124 <_Z9StartRoomib+0x844> */
/* ── 段39：房间表扩容（1d4350-1d4370）──────────────────────────
 *   1d4350 lsls r1,r6,#2 = (idx+1)*4 字节；(idx+1)==0 时短路到 1d42f8（此时表已空）。
 *   MemoryManager::ReAlloc(array, (idx+1)*4, "…/Files/Platform/cARRAY_CLASS.h", 135, false)。
 *   ★ 与 EndRoom 里承接表的 ReAlloc 是同一个模板文件（行号 76/135 不同），说明两者都是 CArray<T>。 */
/* @0x1d4350 lsls r1, r6, #2 */
/* @0x1d4354 beq 0x1d42f8 <_Z9StartRoomib+0xa18> */
/* @0x1d4358 ldr r2, [pc, #0xec] */
/* @0x1d435c mov r3, #0 */
/* @0x1d4360 str r3, [sp] */
/* @0x1d4364 mov r3, #135 */
/* @0x1d4368 add r2, pc, r2 */
/* @0x1d436c bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1d4370 str r0, [r4, #0x4] */
/* ── 段40：写 count + 清零新槽（1d4374-1d43a0）
 *   count = idx+1 先写（1d4378），再判旧 count（r5）是否已 >= idx+1：是就跳过清零，
 *   否则把 array[旧count .. idx] 逐个写 0。⇒ 新槽一定是 0，所以段3 的 had_room 必为 0。 */
/* @0x1d4374 cmp r5, r6 */
/* @0x1d4378 str r6, [r4] */
/* @0x1d437c bge 0x1d43a4 <_Z9StartRoomib+0xac4> */
/* @0x1d4380 lsl r3, r5, #2 */
/* @0x1d4384 mov r1, #0 */
/* @0x1d4388 ldr r2, [r4, #0x4] */
/* @0x1d438c add r5, r5, #1 */
/* @0x1d4390 str r1, [r2, r3] */
/* @0x1d4394 add r3, r3, #4 */
/* @0x1d4398 ldr r6, [r4] */
/* @0x1d439c cmp r6, r5 */
/* @0x1d43a0 bgt 0x1d4388 <_Z9StartRoomib+0xaa8> */
/* ── 段41：写当前房间号 + 取 Run_Room 实参（1d43a4-1d43bc）
 *   *0x542958 = idx；idx >= count 时 r0 = 0（1d43ac 的 movge，正常情况下 idx < count 不成立），
 *   否则 r0 = array[idx]。1d43b8 直接 b 到 1d3944 的 bl（跳过 1d393c 的取值），1d43bc b 到 1d393c。 */
/* @0x1d43a4 ldr r3, [pc, #0x6c] */
/* @0x1d43a8 cmp r7, r6 */
/* @0x1d43ac movge r0, #0 */
/* @0x1d43b0 ldr r3, [r11, r3] */
/* @0x1d43b4 str r7, [r3] */
/* @0x1d43b8 bge 0x1d3944 <_Z9StartRoomib+0x64> */
/* @0x1d43bc b 0x1d393c <_Z9StartRoomib+0x5c> */
/* ── 段42：承接表 data == 0 的短路（1d43c0-1d43cc）
 *   Free(NULL)、data = 0，然后 b 到 1d3cc0（继续 used/capacity 清零）。 */
/* @0x1d43c0 mov r0, r4 */
/* @0x1d43c4 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1d43c8 str r4, [r7, #0x4] */
/* @0x1d43cc b 0x1d3cc0 <_Z9StartRoomib+0x3e0> */
/* ── 段43：房间创建代码路径的 RValue 释放（1d43d0-1d43d8）
 *   FREE_RValue__Pre(&rv) 后 b 到 1d3dc0（销毁临时实例）。入口是 1d3dbc 的 beq。 */
/* @0x1d43d0 mov r0, r5 */
/* @0x1d43d4 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d43d8 b 0x1d3dc0 <_Z9StartRoomib+0x4e0> */
/* ── 段44：构造临时实例前的防御性释放（1d43dc-1d43e4）
 *   FREE_RValue__Pre(&rv) 后 b 到 1d3d78（取 room->[0x6c] 之前）。入口是 1d3d74 的 beq。 */
/* @0x1d43dc mov r0, r5 */
/* @0x1d43e0 bl 0xc0a7c <_Z16FREE_RValue__PreP6RValue> */
/* @0x1d43e4 b 0x1d3d78 <_Z9StartRoomib+0x498> */
/* ── 段45：承接表 used <= 0 的短路（1d43e8-1d43ec）
 *   仍要把 r7 = *(0x542a0c) 装进来（供段14 的 Free 用），再 b 到 1d3c7c。 */
/* @0x1d43e8 ldr r7, [r11, r3] */
/* @0x1d43ec b 0x1d3c7c <_Z9StartRoomib+0x39c> */
/* ── 段46：count == idx+1 分支（1d43f0-1d4400）★ 不可达
 *   1d4254 的 beq 只会在 count == idx+1 时进入，而进入 1d424c 的前提是 count <= idx，
 *   两者矛盾 —— 这段是编译器为「恰好卡在边界」留的分支，实测不可达（仍完整入卡）。
 *   若执行：*0x542958 = idx，r0 = 0 后直接 b 到 Run_Room_Set 的 bl。 */
/* @0x1d43f0 ldr r3, [pc, #0x20] */
/* @0x1d43f4 mov r0, #0 */
/* @0x1d43f8 ldr r3, [r11, r3] */
/* @0x1d43fc str r7, [r3] */
/* @0x1d4400 b 0x1d3944 <_Z9StartRoomib+0x64> */
/* ── 段47：exit(0)（1d4404-1d4408）
 *   本函数唯一的退出点，入口是 1d3dfc 的 bne（0x7590b1 非 0）。 */
/* @0x1d4404 mov r0, #0 */
/* @0x1d4408 bl 0xb6688 <exit@plt> */
/* ── 段48：literal pool（1d440c-1d444c，17 字；objdump 把前 1/6/9/11/17 个字译成了指令，非指令）──
 *   1d440c 0x0021e358  GOT 基址加数（1d38f8 的 add 用 pc=0x1d3900 → 0x3f1c58）
 *   1d4410 0xffffc154 → 槽 0x3eddac → 0x542954  退出码闸门
 *   1d4414 0xffffeed8 → 槽 0x3f0b30 → 0x5425d0  房间表 count（+4 即 array）
 *   1d4418 0xffffd784 → 槽 0x3ef3dc → 0x542958  当前房间号
 *   1d441c 0xffffbcd8 → 槽 0x3ed930 → 0x54298c  Run_Room
 *   1d4420 0xffffbff4 → 槽 0x3edc4c → 0x536f28  ms_ID2Instance
 *   1d4424 0x0017932c  字符串 "…/Platform/Hash.h"（1d3988 的 add 用 pc=0x1d3988 → 0x34ccb4）
 *   1d4428 0xffffbcd4 → 槽 0x3ed92c → 0x5428e8  Zeus 字节
 *   1d442c 0xffffeef4 → 槽 0x3f0b4c → 0x542a14  承接表 used
 *   1d4430 0xffffeef8 → 槽 0x3f0b50 → 0x542a0c  承接表对象
 *   1d4434 0x00179244  字符串 "%s = "（1d3a68 的 add 用 pc=0x1d3a68 → 0x34ccac）—— 本函数未用到这段文本，
 *                      只是因为池按 4 字节对齐被排在这里（1d3a5c 装的就是它，随后 1d3a68 add 成 0x34ccac，
 *                      但本函数没有任何地方读 [sp+0x28]，属编译器留下的死值）
 *   1d4438 0xffffbf68 → 槽 0x3edbc0 → 0x47f295  GC 开关字节
 *   1d443c 0xffffef38 → 槽 0x3f0b90 → 0x7590b1  exit 门字节
 *   1d4440 0xffffef3c → 槽 0x3f0b94 → 0x542a48  「房间已起」字节
 *   1d4444 0xffffbf64 → 槽 0x3edbbc → 0x544be0  全局变量宿主实例
 *   1d4448 0xffffc024 → 槽 0x3edc7c → 0x48f78c  CCameraManager 单例
 *   1d444c 0x00178f88  字符串 "…/Files/Platform/cARRAY_CLASS.h"（1d4370 的 add → 0x34b2f8） */
/* @0x1d440c eoreq lr, r1, r8, asr r3 */
/* @0x1d4410 .word 0xffffc154 */
/* @0x1d4414 .word 0xffffeed8 */
/* @0x1d4418 .word 0xffffd784 */
/* @0x1d441c .word 0xffffbcd8 */
/* @0x1d4420 .word 0xffffbff4 */
/* @0x1d4424 andseq r9, r7, r12, lsr #6 */
/* @0x1d4428 .word 0xffffbcd4 */
/* @0x1d442c .word 0xffffeef4 */
/* @0x1d4430 .word 0xffffeef8 */
/* @0x1d4434 andseq r9, r7, r4, asr #4 */
/* @0x1d4438 .word 0xffffbf68 */
/* @0x1d443c .word 0xffffef38 */
/* @0x1d4440 .word 0xffffef3c */
/* @0x1d4444 .word 0xffffbf64 */
/* @0x1d4448 .word 0xffffc024 */
/* @0x1d444c andseq r8, r7, r8, lsl #31 */
