/* cally 逆向卡：CRoom::LoadFromStream（原版 libyoyo.so，armv7）
 * @func 0x1ae3f8 0x1aea38  size 1604  401 条（0x1aea38 为 literal pool，1 字）
 * 级别: 正文（整条流序、字段落位、唯一失败出口全部逐条钉住，并与 CRoom::LoadFromChunk 0x1aea3c、
 *             CRoom::DeSerialise 0x1ac33c、CRoom::Serialise 0x1aa228、CRoom::Clear 0x1ad0a4、
 *             CRoom::AddTile 0x1ac240、CInstance::C2 0x1994dc、CStream::ReadInteger 0x201730 /
 *             ReadString 0x2018e8 / ReadBoolean 0x2019b0 交叉印证；
 *             未钉：每实例读出来又被 Free 掉的那个字符串本该装到哪、+0x160/+0x164 的用途、
 *             本函数历史上由谁调用）
 * 符号: _ZN5CRoom14LoadFromStreamEP7CStream → bool CRoom::LoadFromStream(CStream* stream)
 * ABI : softfp（float 走核心寄存器）；返回 bool（r0），失败返回 0
 * 同层: CRoom::LoadFromChunk 0x1aea3c（另一条装载路径，源是 YYRoom*+WAD）、
 *       CRoom::DeSerialise 0x1ac33c（存档路径，源是 IBuffer*）、CRoom::Serialise 0x1aa228、
 *       CRoom::Clear 0x1ad0a4（本函数第一件事）、CRoom::AddTile 0x1ac240（本函数**不**调用）、
 *       CStream 读端 ReadInteger 0x201730 / ReadString 0x2018e8 / ReadBoolean 0x2019b0、
 *       CInstance::C2 0x1994dc、MemoryManager::Alloc 0x27ce78 / ReAlloc 0x27cedc / Free 0x27c2d0、
 *       operator new 0x27c524、Background_Exists 0xc3640 / Background_Data 0xc3794 /
 *       CBackground::GetWidth 0xc2d78 / CBackground::GetHeight 0xc2d80
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   拿一个 CStream（顺序字节流）把一个房间**纯数据**地读回来：magic 0x21d → 名字 → 头六字段 →
 *   代码串 → n 个背景 → 启用位 → n 个视野 → n 个实例 → n 个 tile。没有相机、没有物理、没有层、
 *   没有实例注册、没有 ID 表，字段也比另两条路径少（缺口用常量补齐）。唯一失败出口是 magic 不符。
 *
 * ── ★ 全库零调用者：这是 2.1.9 的死代码 ───────────────────────────
 *   0x1ae3f8 在整个 libyoyo.so 里只出现 1 次，位置在 .dynsym（符号值），不是 .text 里的
 *   bl/b/blx，也不是任何函数指针表项（instructions.jsonl.xz 里指向 0x1ae3f8 的 bl/b/blx 命中 0 条）。
 *   magic 0x21d 同样全库只此一处（movw #0x21d 只有 0x1ae418 一条）。
 *   ⇒ 它是原版留着的「CStream 版房间读取器」：装 game.droid 走 LoadFromChunk，读存档走 DeSerialise。
 *   本卡照实描述它做了什么，但**不主张它有运行期作用**。
 *
 * ── 三条加载路径的分工（本卡的核心结论）────────────────────────────
 *   路径                入口        数据源               调用者（唯一）
 *   ------------------  ----------  -------------------  -------------------------------------
 *   LoadFromChunk       0x1aea3c    YYRoom* + WAD 基址    Room_Load 0x1b4edc
 *                                                        ← LoadGameData 0x1de638
 *                                                        ← RunnerLoadWad 0x1df5dc
 *   LoadFromStream      0x1ae3f8    CStream*             无（死代码）
 *   DeSerialise         0x1ac33c    IBuffer* + bool      Check_LoadGameState 0x1d13d8
 *   （写侧）Serialise   0x1aa228    IBuffer*             Command_SaveGame 0x1d0ce8
 *   （内存对拷）Assign  0x1ad70c    CRoom*               Room_Duplicate / Room_Assign / StartRoom
 *   一句话分工：chunk = **资产装载**（WAD 里的房间结构 → 运行时 CRoom，带相机/物理/层/代码入口）；
 *   stream = **同一份房间语义的纯数据流版**（CStream，无副作用、字段裁剪、常量补齐）；
 *   DeSerialise = **存档往返**（IBuffer，字段最全，含两段实例表 + 可选注册）。
 *   三者写的是同一批 CRoom 偏移，但只有 DeSerialise 与 Serialise 严格互逆。
 *
 * ── 与 DeSerialise 的关系（逐项）──────────────────────────────────
 *   1. 同序的六字段：+0x10 / +0x14 / +0xc / +0x18(bool) / +0x1c / +0x20(bool)。本函数与 DeSerialise
 *      逐项同序同型；LoadFromChunk 也是这个序，只是源换成 YYRoom 的整数字段。
 *   2. +0xcc（房间数据在 WAD 里的相对路径）只有 LoadFromChunk 会写，本函数不写。
 *   3. 本函数缺的东西：+0xac/+0xb0（源指针）、+0x6c（CCode）、+0x45/+0x46（另两个标志位）、
 *      +0x70/+0x74/+0x78/+0x7c（3D 头）、+0xb4（CPhysicsWorld）、+0xc4/+0xc8（tile/code 指针表）。
 *   4. 本函数实例段**只有一段**（活动链 +0x84/+0x80/+0x88）；DeSerialise 有两段（另一段非活动
 *      +0x90/+0x8c/+0x94，见 DeSerialise 卡：两段对应 [inst+0x69] 的两态）。
 *   5. 本函数**不**调 AddTile、**不**碰 room_maxtileid、**不**写 CRoom+0x00（最新 tile 下标）；
 *      DeSerialise 逐条 AddTile 再把全局计数逐条减回。
 *   6. 本函数**不**收 bRegister 参数 ⇒ 没有 ms_ID2InstanceE 插入、没有 CLayerManager::AddInstance。
 *      DeSerialise 的 bool 参数就是这两件事的开关。
 *
 * ── 流序总表（读到的顺序 = 格式；无版本号、无长度前缀，只有开头一个 magic）──────
 *   int          magic，必须 == 0x21d，否则 return 0（唯一失败出口，且此时房间已被 Clear）
 *   ReadString   → CRoom+0x08   （先 Free 旧的）
 *   int          → CRoom+0x10
 *   int          → CRoom+0x14
 *   int          → CRoom+0x0c
 *   bool         → CRoom+0x18   byte
 *   int          → CRoom+0x1c
 *   bool         → CRoom+0x20   byte
 *   ReadString   → CRoom+0x68   （先 Free 旧的）
 *   int n        → 背景条数；同时把 CRoom+0x70 清 0
 *   n × { bool,bool,int,int,int,bool,bool,int,int,bool }  9 字段 + 尾部缩放门
 *   bool         → CRoom+0x44
 *   int n        → 视野条数
 *   n × { bool, 14 × int }  15 字段（+0x24 写 0）
 *   int n        → 实例条数
 *   n × { int,int,int,int, ReadString }  CInstance(x,y,…) 后挂 +0x84 深度降序链；串读完即 Free
 *   int n        → tile 条数 = CRoom+0xb8 = CRoom+0xbc，ReAlloc(n*56)
 *   n × { 9 × int }  9 字段 + 5 常量（+0x24/+0x28/+0x30 = 1.0f、+0x2c = 0x00FFFFFF、+0x34 = 1）
 *   return true
 *
 * ── CStream 的读协议（3 个读原语，全部直调，没有虚表）────────────────
 *   ReadInteger() 0x201730              → int（r0）
 *   ReadString(const char**) 0x2018e8   → 写 *arg（旧值由调用方先释放）
 *   ReadBoolean() 0x2019b0              → 0/1
 *   ★ 与 DeSerialise 的 IBuffer 协议完全不同：那边是 vtable[+0xc] + 内嵌 RValue + YYGetXxx 三连，
 *     类型码写在流里；这边读什么类型在编译期就定了，流里不带类型码。
 *   ★ 所以本格式**不可自描述**：读错一个类型后面全歪，也没有长度/校验可以回退。
 *
 * ── 失败路径（只有一条，且不回滚）──────────────────────────────────
 *   magic != 0x21d → movne r0,#0 → 直接返回 false。此时 CRoom 已被 Clear() 清空，
 *   调用者拿到 false 但房间是「空房间」，不是原状态。
 *   其余异常（条数为负/超大、magic 之后截断）一概不检查：本函数不判任何读原语的返回值，
 *   条数直接来自流且没有上界（背景/视野各只有 8 格指针数组）。
 *
 * ── 未定（open）──────────────────────────────────────────────
 *   1. 每实例那一串 ReadString：读进 [sp+0x14]、随后把 inst+0x160/+0x164 写成 0、循环尾 Free
 *      —— 既不挂到实例也不保留。疑似原版漏存（或旧版 +0x160 是 char*，本版本已废）。
 *   2. CInstance::C2 的 4 个整数实参：流里第 3、4 个 int 被**交换**后分别进 r3（第 3 参）与
 *      [sp]（第 4 参），本卡只钉位置不钉名。
 *   3. 背景/视野条数为数据驱动却只有 8 格指针：>8 是否越界写 CRoom+0x44 及以上（未运行期验证）。
 *   4. 本函数历史上由谁调用（哪个版本、哪个 CStream 生产者）—— 2.1.9 里已无调用者。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────
 */

/* ── 装载：入口、清场 ───────────────────────────────────────────
 *   帧：push {r4-r11,lr} + vpush {d8} + sub sp,#28
 *   r6 = this(CRoom*)、r4 = stream(CStream*)；sp+0xc 存 tile 条数、sp+0x14(=sp+20) 是
 *   实例段 ReadString 的输出槽（= sp+0x14）。
 *   第一件事 CRoom::Clear()：本函数不做增量修补，先清空再整体重建（与 LoadFromChunk 同一习惯）。
 */

/* @0x1ae3f8 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1ae3fc vpush {d8} */
/* @0x1ae400 mov r4, r1 */
/* @0x1ae404 sub sp, sp, #28 */
/* @0x1ae408 mov r6, r0 */
/* @0x1ae40c bl 0x1ad0a4 <_ZN5CRoom5ClearEv> */
/* ── magic 门：唯一的失败出口 ────────────────────────────────────
 *   ReadInteger() 必须 == 0x21d（541）。不等 → r0 = 0 → 立刻返回 false。
 *   ★ 检查发生在 Clear() 之后：失败返回时房间已被清空，没有回滚。
 *   ★ 0x21d 全库只此一处，既不匹配任何已知 GM 版本号，也不与其他 Load 函数共享。
 */

/* @0x1ae410 mov r0, r4 */
/* @0x1ae414 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae418 movw r3, #0x21d */
/* @0x1ae41c cmp r0, r3 */
/* @0x1ae420 movne r0, #0 */
/* @0x1ae424 beq 0x1ae434 <_ZN5CRoom14LoadFromStreamEP7CStream+0x3c> */
/* @0x1ae428 add sp, sp, #28 */
/* @0x1ae42c vpop {d8} */
/* @0x1ae430 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 房间名：先释放旧串，再 ReadString 到 CRoom+0x08 ────────────────
 *   ReadString 的语义是「把新串写进 *arg」，所以旧值必须自己先 Free 并置 0，否则泄漏。
 *   ★ 这套三步（if(p) Free(p); p=0; ReadString(&p)）在本函数出现两次（+0x08、+0x68）；
 *     DeSerialise 里一次都没有 —— 那边是「读进暂存的 RValue，再 YYStrDup」，不碰旧值。
 */

/* @0x1ae434 ldr r0, [r6, #0x8] */
/* @0x1ae438 cmp r0, #0 */
/* @0x1ae43c beq 0x1ae44c <_ZN5CRoom14LoadFromStreamEP7CStream+0x54> */
/* @0x1ae440 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae444 mov r3, #0 */
/* @0x1ae448 str r3, [r6, #0x8] */
/* @0x1ae44c add r1, r6, #8 */
/* @0x1ae450 mov r0, r4 */
/* @0x1ae454 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* ── 房间头六字段：+0x10, +0x14, +0xc, +0x18, +0x1c, +0x20 ─────────────
 *   与 DeSerialise 0x1ac398-0x1ac460、LoadFromChunk 0x1aec94-0x1aecac **完全同序同型**。
 *   CRoom::Clear 0x1ad0c4/0x1ad0f0/0x1ad0d4 预置 +0x10=640 / +0x14=480 / +0xc=30
 *   ⇒ +0x10 = 宽、+0x14 = 高、+0xc = speed。
 *   ★ 布尔也用 ReadBoolean —— 流里没有独立的 bool 类型，靠调用点函数名区分。
 */

/* @0x1ae458 mov r0, r4 */
/* @0x1ae45c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae460 str r0, [r6, #0x10] */
/* @0x1ae464 mov r0, r4 */
/* @0x1ae468 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae46c str r0, [r6, #0x14] */
/* @0x1ae470 mov r0, r4 */
/* @0x1ae474 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae478 str r0, [r6, #0xc] */
/* @0x1ae47c mov r0, r4 */
/* @0x1ae480 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae484 strb r0, [r6, #0x18] */
/* @0x1ae488 mov r0, r4 */
/* @0x1ae48c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae490 str r0, [r6, #0x1c] */
/* @0x1ae494 mov r0, r4 */
/* @0x1ae498 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* ── 代码串 +0x68：同样先 Free 再 ReadString ────────────────────────
 *   DeSerialise 用 ReadString→YYStrDup 写这格；LoadFromChunk 写的是 YYStrDup("") 空串。
 *   ★ +0x6c（CCode*）本函数**不读**，保持 ctor/Clear 的清零值。
 *   ★ +0x20 的存回（strb）被编译器挪到了这里，落在两次 Free 判断之间 —— 不是新的一次读。
 */

/* @0x1ae49c ldr r3, [r6, #0x68] */
/* @0x1ae4a0 cmp r3, #0 */
/* @0x1ae4a4 strb r0, [r6, #0x20] */
/* @0x1ae4a8 beq 0x1ae4bc <_ZN5CRoom14LoadFromStreamEP7CStream+0xc4> */
/* @0x1ae4ac mov r0, r3 */
/* @0x1ae4b0 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae4b4 mov r3, #0 */
/* @0x1ae4b8 str r3, [r6, #0x68] */
/* @0x1ae4bc mov r0, r4 */
/* @0x1ae4c0 add r1, r6, #104 */
/* @0x1ae4c4 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* ── 背景段：条数 + 两个常量 + 循环骨架 ────────────────────────────
 *   n = ReadInteger()；CRoom+0x70 清 0（本函数此后不再写它；LoadFromChunk 那边 +0x70 是 3D 门）。
 *   n <= 0 → 直接跳视野段 0x1ae654。
 *   循环：r5 是指针游标（this+0x24 起、每轮 +4，**没有 8 的上界检查**）、r7 计数、r9 上界。
 *   s16 = 1.0f、r10 = mvn(#-16777216) = 0x00FFFFFF 是两个常量。
 *   ★ 0x00FFFFFF 不是 0xFF000000：mvn 取反后是「低 24 位全 1」，与 tile+0x2c 用的同一常量。
 */

/* @0x1ae4c8 mov r0, r4 */
/* @0x1ae4cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae4d0 mov r7, #0 */
/* @0x1ae4d4 strb r7, [r6, #0x70] */
/* @0x1ae4d8 subs r9, r0, #0 */
/* @0x1ae4dc vmovgt.f32 s16, #1.000000e+00 */
/* @0x1ae4e0 movgt r5, r6 */
/* @0x1ae4e4 mvngt r10, #-16777216 */
/* @0x1ae4e8 bgt 0x1ae500 <_ZN5CRoom14LoadFromStreamEP7CStream+0x108> */
/* @0x1ae4ec b 0x1ae654 <_ZN5CRoom14LoadFromStreamEP7CStream+0x25c> */
/* ── 背景循环尾（「本条不算缩放」的出口）与循环头 ────────────────────
 *   0x1ae4f0：+1、指针 +4、比上界；0x1ae64c 是「算完缩放」的出口，两条都回到 0x1ae500 或跳出。
 */

/* @0x1ae4f0 add r7, r7, #1 */
/* @0x1ae4f4 add r5, r5, #4 */
/* @0x1ae4f8 cmp r7, r9 */
/* @0x1ae4fc beq 0x1ae654 <_ZN5CRoom14LoadFromStreamEP7CStream+0x25c> */
/* ── 背景记录体：9 个流字段 + 2 个常量 + 尾部缩放门 ───────────────────
 *   落位（首次 r5 = this，此后 r5 = this+4i；记录指针 = [r5+0x24]）：
 *     rec+0x00 = ReadBoolean                       (r8)
 *     rec+0x01 = ReadBoolean                       (r11)
 *     rec+0x04 = ReadInteger                       (r8)
 *     rec+0x08 = (float)(int)ReadInteger           (r11, vcvt.f32.s32)
 *     rec+0x0c = (float)(int)ReadInteger           (r8)
 *     rec+0x10 = ReadBoolean                       (r11)
 *     rec+0x11 = ReadBoolean                       (r8)
 *     rec+0x14 = (float)(int)ReadInteger           (r11)
 *     rec+0x18 = (float)(int)ReadInteger           (r8)
 *     rec+0x24 = 0x00FFFFFF                        常量
 *     rec+0x28 = 1.0f                              常量
 *     gate     = ReadBoolean()  ← 这一格**不进记录**，只决定要不要算缩放
 *   ★ 与 DeSerialise 的 13 字段表对照：那边 +0x1c/+0x20/+0x24/+0x28 全从流里读；这边
 *     +0x24/+0x28 是常量、+0x1c/+0x20 由缩放公式算，gate 换成尾部一个 bool。
 *   ★ 流里存的是**整数**（vcvt.f32.s32 才变 float）：落位点在 0x1ae54c/0x1ae564/0x1ae59c/
 *     0x1ae5b4 的 vstr，只看 vstr 会漏掉中间的 vcvt。
 *   ★ 编译器把「读下一条」排在「存上一条」之前，两个寄存器交替用（r8/r11、s13/s14/s15），
 *     读卡时别把某个 vstr 认成上一条读的结果。
 */

/* @0x1ae500 mov r0, r4 */
/* @0x1ae504 ldr r8, [r5, #0x24] */
/* @0x1ae508 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae50c ldr r11, [r5, #0x24] */
/* @0x1ae510 strb r0, [r8] */
/* @0x1ae514 mov r0, r4 */
/* @0x1ae518 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae51c ldr r8, [r5, #0x24] */
/* @0x1ae520 strb r0, [r11, #0x1] */
/* @0x1ae524 mov r0, r4 */
/* @0x1ae528 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae52c ldr r11, [r5, #0x24] */
/* @0x1ae530 str r0, [r8, #0x4] */
/* @0x1ae534 mov r0, r4 */
/* @0x1ae538 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae53c ldr r8, [r5, #0x24] */
/* @0x1ae540 vmov s13, r0 */
/* @0x1ae544 mov r0, r4 */
/* @0x1ae548 vcvt.f32.s32 s15, s13 */
/* @0x1ae54c vstr s15, [r11, #8] */
/* @0x1ae550 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae554 ldr r11, [r5, #0x24] */
/* @0x1ae558 vmov s14, r0 */
/* @0x1ae55c mov r0, r4 */
/* @0x1ae560 vcvt.f32.s32 s15, s14 */
/* @0x1ae564 vstr s15, [r8, #12] */
/* @0x1ae568 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae56c ldr r8, [r5, #0x24] */
/* @0x1ae570 strb r0, [r11, #0x10] */
/* @0x1ae574 mov r0, r4 */
/* @0x1ae578 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae57c ldr r11, [r5, #0x24] */
/* @0x1ae580 strb r0, [r8, #0x11] */
/* @0x1ae584 mov r0, r4 */
/* @0x1ae588 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae58c ldr r8, [r5, #0x24] */
/* @0x1ae590 vmov s13, r0 */
/* @0x1ae594 mov r0, r4 */
/* @0x1ae598 vcvt.f32.s32 s15, s13 */
/* @0x1ae59c vstr s15, [r11, #20] */
/* @0x1ae5a0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae5a4 ldr r3, [r5, #0x24] */
/* @0x1ae5a8 vmov s14, r0 */
/* @0x1ae5ac mov r0, r4 */
/* @0x1ae5b0 vcvt.f32.s32 s15, s14 */
/* @0x1ae5b4 vstr s15, [r8, #24] */
/* @0x1ae5b8 str r10, [r3, #0x24] */
/* @0x1ae5bc vstr s16, [r3, #40] */
/* @0x1ae5c0 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae5c4 cmp r0, #0 */
/* @0x1ae5c8 beq 0x1ae4f0 <_ZN5CRoom14LoadFromStreamEP7CStream+0xf8> */
/* ── 背景缩放：gate 为真且 Background_Exists 才跳到这里 ────────────────
 *   rec+0x1c = CRoom+0x10 / (float)CBackground::GetWidth()
 *   rec+0x20 = CRoom+0x14 / (float)CBackground::GetHeight()
 *   两道 vcmpe.f32 #0 + vldrgt 守卫：宽/高为 0（或负）就整段跳过，不除。
 *   ★ 注意 r3 在 0x1ae5e0/0x1ae5f8 是重新 ldr 的（[r5+0x24]、[r5+0x20]）：r5 已 +4，
 *     所以 [r5+0x20] 仍是同一条记录。tile/背景的游标语义要按「先加后取」读。
 */

/* @0x1ae5cc ldr r3, [r5, #0x24] */
/* @0x1ae5d0 ldr r0, [r3, #0x4] */
/* @0x1ae5d4 bl 0xc3640 <_Z17Background_Existsi> */
/* @0x1ae5d8 cmp r0, #0 */
/* @0x1ae5dc beq 0x1ae4f0 <_ZN5CRoom14LoadFromStreamEP7CStream+0xf8> */
/* @0x1ae5e0 ldr r3, [r5, #0x24] */
/* @0x1ae5e4 add r7, r7, #1 */
/* @0x1ae5e8 add r5, r5, #4 */
/* @0x1ae5ec ldr r0, [r3, #0x4] */
/* @0x1ae5f0 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ae5f4 bl 0xc2d78 <_ZN11CBackground8GetWidthEv> */
/* @0x1ae5f8 ldr r3, [r5, #0x20] */
/* @0x1ae5fc vmov s13, r0 */
/* @0x1ae600 ldr r0, [r3, #0x4] */
/* @0x1ae604 vcvt.f32.s32 s15, s13 */
/* @0x1ae608 vcmpe.f32 s15, #0 */
/* @0x1ae60c vmrs APSR_nzcv, fpscr */
/* @0x1ae610 vldrgt s13, [r6, #16] */
/* @0x1ae614 vcvtgt.f32.s32 s14, s13 */
/* @0x1ae618 vdivgt.f32 s15, s14, s15 */
/* @0x1ae61c vstrgt s15, [r3, #28] */
/* @0x1ae620 bl 0xc3794 <_Z15Background_Datai> */
/* @0x1ae624 bl 0xc2d80 <_ZN11CBackground9GetHeightEv> */
/* @0x1ae628 vmov s14, r0 */
/* @0x1ae62c vcvt.f32.s32 s15, s14 */
/* @0x1ae630 vcmpe.f32 s15, #0 */
/* @0x1ae634 vmrs APSR_nzcv, fpscr */
/* @0x1ae638 vldrgt s13, [r6, #20] */
/* @0x1ae63c vcvtgt.f32.s32 s14, s13 */
/* @0x1ae640 ldrgt r3, [r5, #0x20] */
/* @0x1ae644 vdivgt.f32 s15, s14, s15 */
/* @0x1ae648 vstrgt s15, [r3, #32] */
/* @0x1ae64c cmp r7, r9 */
/* @0x1ae650 bne 0x1ae500 <_ZN5CRoom14LoadFromStreamEP7CStream+0x108> */
/* ── 视野段：启用位 + 条数 ───────────────────────────────────────
 *   CRoom+0x44 = ReadBoolean()（DeSerialise/LoadFromChunk 里同一格来自流/YYRoom 位域 bit0）。
 *   ★ +0x45/+0x46 本函数**不写**（那两个字节只有 LoadFromChunk 从 YYRoom+0x24 bit1/bit2 写）。
 *   n <= 0 → 跳过整段（r10 是上界）。循环游标 r5 = this，记录指针 = [r5+0x48]。
 */

/* @0x1ae654 mov r0, r4 */
/* @0x1ae658 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae65c strb r0, [r6, #0x44] */
/* @0x1ae660 mov r0, r4 */
/* @0x1ae664 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae668 subs r10, r0, #0 */
/* @0x1ae66c movgt r5, r6 */
/* @0x1ae670 movgt r7, #0 */
/* @0x1ae674 movgt r11, #0 */
/* @0x1ae678 ble 0x1ae790 <_ZN5CRoom14LoadFromStreamEP7CStream+0x398> */
/* ── 视野记录体：15 个流字段 ─────────────────────────────────────
 *   落位（记录指针 = [r5+0x48] 或 +4 后的 [r5+0x44]）：
 *     rec+0x00 = ReadBoolean
 *     rec+0x04 = (float)(int)ReadInteger     rec+0x08 = (float)(int)…
 *     rec+0x0c = (float)(int)…               rec+0x10 = (float)(int)…
 *     rec+0x14 = ReadInteger  rec+0x18 = …   rec+0x1c = …   rec+0x20 = …
 *     rec+0x24 = 0（str r11，r11=0；按 float 读就是 0.0f）
 *     rec+0x28 = ReadInteger  rec+0x2c = …   rec+0x30 = …   rec+0x34 = …   rec+0x38 = …
 *   ★ 与 DeSerialise 的 17 字段表对照：那边 +0x28..+0x40 七个 int 全读，这边只读到 +0x38，
 *     +0x3c/+0x40 保持 ctor 的 -1（DeSerialise 卡 open 2 说 +0x28..+0x40 未命名，这里可补一条：
 *     chunk 路径把 +0x40 留给相机 id）。
 *   ★ 四个矩形同样是「整数入、浮点用」（vcvt.f32.s32），与 DeSerialise 0x1ac71c 段同一手法。
 *   ★ 写 rec+0x24 的 str 排在 bl ReadInteger 之后（0x1ae73c 在 0x1ae740 之前），
 *     别把它读成「读出来的值」。
 */

/* @0x1ae67c mov r0, r4 */
/* @0x1ae680 ldr r9, [r5, #0x48] */
/* @0x1ae684 bl 0x2019b0 <_ZN7CStream11ReadBooleanEv> */
/* @0x1ae688 ldr r8, [r5, #0x48] */
/* @0x1ae68c add r7, r7, #1 */
/* @0x1ae690 add r5, r5, #4 */
/* @0x1ae694 strb r0, [r9] */
/* @0x1ae698 mov r0, r4 */
/* @0x1ae69c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6a0 ldr r9, [r5, #0x44] */
/* @0x1ae6a4 vmov s14, r0 */
/* @0x1ae6a8 mov r0, r4 */
/* @0x1ae6ac vcvt.f32.s32 s15, s14 */
/* @0x1ae6b0 vstr s15, [r8, #4] */
/* @0x1ae6b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6b8 ldr r8, [r5, #0x44] */
/* @0x1ae6bc vmov s13, r0 */
/* @0x1ae6c0 mov r0, r4 */
/* @0x1ae6c4 vcvt.f32.s32 s15, s13 */
/* @0x1ae6c8 vstr s15, [r9, #8] */
/* @0x1ae6cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6d0 ldr r9, [r5, #0x44] */
/* @0x1ae6d4 vmov s14, r0 */
/* @0x1ae6d8 mov r0, r4 */
/* @0x1ae6dc vcvt.f32.s32 s15, s14 */
/* @0x1ae6e0 vstr s15, [r8, #12] */
/* @0x1ae6e4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae6e8 ldr r8, [r5, #0x44] */
/* @0x1ae6ec vmov s13, r0 */
/* @0x1ae6f0 mov r0, r4 */
/* @0x1ae6f4 vcvt.f32.s32 s15, s13 */
/* @0x1ae6f8 vstr s15, [r9, #16] */
/* @0x1ae6fc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae700 ldr r9, [r5, #0x44] */
/* @0x1ae704 str r0, [r8, #0x14] */
/* @0x1ae708 mov r0, r4 */
/* @0x1ae70c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae710 ldr r8, [r5, #0x44] */
/* @0x1ae714 str r0, [r9, #0x18] */
/* @0x1ae718 mov r0, r4 */
/* @0x1ae71c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae720 ldr r9, [r5, #0x44] */
/* @0x1ae724 str r0, [r8, #0x1c] */
/* @0x1ae728 mov r0, r4 */
/* @0x1ae72c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae730 ldr r8, [r5, #0x44] */
/* @0x1ae734 str r0, [r9, #0x20] */
/* @0x1ae738 mov r0, r4 */
/* @0x1ae73c str r11, [r8, #0x24] */
/* @0x1ae740 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae744 ldr r9, [r5, #0x44] */
/* @0x1ae748 str r0, [r8, #0x28] */
/* @0x1ae74c mov r0, r4 */
/* @0x1ae750 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae754 ldr r8, [r5, #0x44] */
/* @0x1ae758 str r0, [r9, #0x2c] */
/* @0x1ae75c mov r0, r4 */
/* @0x1ae760 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae764 ldr r9, [r5, #0x44] */
/* @0x1ae768 str r0, [r8, #0x30] */
/* @0x1ae76c mov r0, r4 */
/* @0x1ae770 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae774 ldr r8, [r5, #0x44] */
/* @0x1ae778 str r0, [r9, #0x34] */
/* @0x1ae77c mov r0, r4 */
/* @0x1ae780 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae784 cmp r7, r10 */
/* @0x1ae788 str r0, [r8, #0x38] */
/* @0x1ae78c bne 0x1ae67c <_ZN5CRoom14LoadFromStreamEP7CStream+0x284> */
/* ── 实例段：条数 → 每实例 4 个 int + 1 个字符串 → 活动链 ────────────────
 *   n = ReadInteger()（存 sp+0xc）；n <= 0 → 跳 tile 段。
 *   r10 = sp+20（= sp+0x14）是 ReadString 的输出槽，每轮读之前先被 str r7 清零。
 *   r8 = 计数、r7 = 0 常量。
 *   ★ 本函数只有这一段实例表；DeSerialise 有活动/非活动两段。
 *   ★ 全程没有 bRegister，所以没有 ms_ID2InstanceE 插入、没有 CLayerManager::AddInstance，
 *     连 CRoom::AddInstance 都没调 —— 链是在这里**内联**插的（与 AddInstance 0x1ab654 同构）。
 */

/* @0x1ae790 mov r0, r4 */
/* @0x1ae794 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae798 cmp r0, #0 */
/* @0x1ae79c str r0, [sp, #0xc] */
/* @0x1ae7a0 addgt r10, sp, #20 */
/* @0x1ae7a4 movgt r8, #0 */
/* @0x1ae7a8 movgt r7, r8 */
/* @0x1ae7ac ble 0x1ae894 <_ZN5CRoom14LoadFromStreamEP7CStream+0x49c> */
/* ── 单条实例：4 个 int → CInstance::C2 → ReadString → 挂链 ──────────────
 *   读序：a=ReadInteger, b=ReadInteger, c=ReadInteger, d=ReadInteger
 *   然后 new(432) + CInstance::C2(x=(float)a, y=(float)b, i1=d, i2=c, b=false)
 *   ★ 第 3、4 个 int 是**交换**进参数的：r3 拿第 4 个（d），[sp] 拿第 3 个（c）；
 *     softfp 下 r1/r2 是 x/y，r3 是第 3 参，[sp] 是第 4 参，[sp+4] 是 bool（此处 0）。
 *   ★ 与 DeSerialise 0x1acd24 的差别：那边 C2 全传 0（x/y/两个 int 都由后面的
 *     CInstance::DeSerialise 填），这边没有 DeSerialise，x/y 直接来自流。
 *   接着 ReadString(&sp+0x14) 读一个串，并把 inst+0x160/+0x164 置 0 —— 这个串在本函数里
 *   **没有落点**，循环尾被 Free（见 open 1）。
 */

/* @0x1ae7b0 mov r0, r4 */
/* @0x1ae7b4 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7b8 vmov s17, r0 */
/* @0x1ae7bc mov r0, r4 */
/* @0x1ae7c0 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7c4 vmov s16, r0 */
/* @0x1ae7c8 mov r0, r4 */
/* @0x1ae7cc bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7d0 mov r9, r0 */
/* @0x1ae7d4 mov r0, r4 */
/* @0x1ae7d8 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae7dc mov r11, r0 */
/* @0x1ae7e0 mov r0, #432 */
/* @0x1ae7e4 bl 0x27c524 <_Znwj> */
/* @0x1ae7e8 vcvt.f32.s32 s17, s17 */
/* @0x1ae7ec mov r3, r11 */
/* @0x1ae7f0 str r9, [sp] */
/* @0x1ae7f4 str r7, [sp, #0x4] */
/* @0x1ae7f8 vcvt.f32.s32 s16, s16 */
/* @0x1ae7fc vmov r1, s17 */
/* @0x1ae800 vmov r2, s16 */
/* @0x1ae804 mov r5, r0 */
/* @0x1ae808 bl 0x1994dc <_ZN9CInstanceC2Effiib> */
/* @0x1ae80c mov r0, r4 */
/* @0x1ae810 mov r1, r10 */
/* @0x1ae814 str r7, [sp, #0x14] */
/* @0x1ae818 bl 0x2018e8 <_ZN7CStream10ReadStringERPKc> */
/* ── 串读完：inst+0x160 / +0x164 清 0（串本身留在 sp+0x14）────────────────
 *   ★ 这两格是 DeSerialise 里 CInstance::DeSerialise 会填的字段（本卡不越界断言其名）。
 *     这里显式写 0，等于「流里带的串不生效」。
 */

/* @0x1ae81c str r7, [r5, #0x160] */
/* @0x1ae820 str r7, [r5, #0x164] */
/* ── 活动链插入：depth 降序（head = 最深）──────────────────────────────
 *   k = inst+0x180（depth），插入键 = inst+0x184（快照）。
 *   链头 +0x84、链尾 +0x80、计数 +0x88；链域 inst+0x178(prev) / +0x17c(next)。
 *   空表 → 0x1ae9f4：head=tail=inst、inst+0x184 = inst+0x180、prev/next=0。
 *   非空 → 从 head 起 while (cur+0x184 > new_depth) 前进，停在第一个 cur+0x184 <= new_depth 处前插
 *     （0x1ae9c0：prev==0 就顶替成为新 head，否则插在 prev 与 cur 之间）。
 *   ★ 条件码是 **bls（无符号）**，不是 DeSerialise 0x1acd7c 的 bge（有符号）：
 *     vcmpe.f32 s15,s14 + bls ⇔ cur_snapshot <= new_depth。对非负 depth 两者等价，
 *     负 depth 会分叉（本卡不判断哪个是本意，属实现差异）。
 *   ★ 计数 +0x88 在**判链之前**就 +1（0x1ae834），与 DeSerialise 0x1acd68 同位置。
 */

/* @0x1ae824 ldr r3, [r6, #0x84] */
/* @0x1ae828 ldr r2, [r6, #0x88] */
/* @0x1ae82c cmp r3, #0 */
/* @0x1ae830 vldrne s14, [r5, #384] */
/* @0x1ae834 add r2, r2, #1 */
/* @0x1ae838 str r2, [r6, #0x88] */
/* @0x1ae83c beq 0x1ae9f4 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5fc> */
/* @0x1ae840 vldr s15, [r3, #388] */
/* @0x1ae844 vcmpe.f32 s15, s14 */
/* @0x1ae848 vmrs APSR_nzcv, fpscr */
/* @0x1ae84c bls 0x1ae9c0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5c8> */
/* @0x1ae850 ldr r3, [r3, #0x17c] */
/* @0x1ae854 cmp r3, #0 */
/* @0x1ae858 bne 0x1ae840 <_ZN5CRoom14LoadFromStreamEP7CStream+0x448> */
/* @0x1ae85c ldr r2, [r6, #0x80] */
/* @0x1ae860 vstr s14, [r5, #388] */
/* @0x1ae864 str r5, [r2, #0x17c] */
/* @0x1ae868 str r2, [r5, #0x178] */
/* @0x1ae86c str r5, [r6, #0x80] */
/* @0x1ae870 str r3, [r5, #0x17c] */
/* ── 每轮收尾：释放临时串、计数 +1、比上界 ─────────────────────────────
 *   Free(sp+0x14) 就是被丢弃的那个实例字符串 —— 与 0x1ae81c 的清零配对，见 open 1。
 */

/* @0x1ae874 ldr r0, [sp, #0x14] */
/* @0x1ae878 cmp r0, #0 */
/* @0x1ae87c beq 0x1ae884 <_ZN5CRoom14LoadFromStreamEP7CStream+0x48c> */
/* @0x1ae880 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1ae884 ldr r3, [sp, #0xc] */
/* @0x1ae888 add r8, r8, #1 */
/* @0x1ae88c cmp r8, r3 */
/* @0x1ae890 bne 0x1ae7b0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x3b8> */
/* ── tile 段：条数 / 扩容 / 失败分支 ────────────────────────────────
 *   n = ReadInteger()；CRoom+0xb8 = n（**直接赋值**，不是 AddTile 的 ++）、r5 = n。
 *   n == 0 → 0x1aea10：旧数组非空先 Free，CRoom+0xc0 = 0，再跳到 0x1ae8d8 写 +0xbc = 0。
 *   n != 0 → 0x1ae8ac：尺寸 = n*7<<3 = n*56（rsb + lsl），ReAlloc([+0xc0], n*56, cARRAY_STRUCTURE.h, 106)
 *            → CRoom+0xc0 = 新基址；随后 CRoom+0xbc = n（容量）。
 *   ★ 尺寸算成 0 的兜底出口 0x1aea28 也走 Free 并把 +0xc0 清 0。
 *   ★ 与 DeSerialise 的关键差别：那边先 ReAlloc 再逐条 AddTile（会 ++room_maxtileid 再被逐条减回、
 *     还会写 CRoom+0x00=最新下标、并依赖 +0xb8 为 0）；本函数**直接 memcpy 式写数组**，
 *     +0xb8 一次到位，room_maxtileid 与 CRoom+0x00 都不动。副作用少，但也不再走 AddTile 的校验。
 *   ★ 文件名串由池 0x1aea38 = 0x0019e968 解引用：pc(0x1ae8d4) + 0x19e968 = 0x34d23c
 *     "../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"，行号 106（mov r3,#106）。
 */

/* @0x1ae894 mov r0, r4 */
/* @0x1ae898 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae89c cmp r0, #0 */
/* @0x1ae8a0 mov r5, r0 */
/* @0x1ae8a4 str r0, [r6, #0xb8] */
/* @0x1ae8a8 beq 0x1aea10 <_ZN5CRoom14LoadFromStreamEP7CStream+0x618> */
/* @0x1ae8ac rsb r3, r0, r0, lsl #3 */
/* @0x1ae8b0 ldr r0, [r6, #0xc0] */
/* @0x1ae8b4 lsls r1, r3, #3 */
/* @0x1ae8b8 beq 0x1aea28 <_ZN5CRoom14LoadFromStreamEP7CStream+0x630> */
/* @0x1ae8bc ldr r2, [pc, #0x174] */
/* @0x1ae8c0 mov r3, #0 */
/* @0x1ae8c4 str r3, [sp] */
/* @0x1ae8c8 mov r3, #106 */
/* @0x1ae8cc add r2, pc, r2 */
/* @0x1ae8d0 bl 0x27cedc <_ZN13MemoryManager7ReAllocEPvjPKcib> */
/* @0x1ae8d4 str r0, [r6, #0xc0] */
/* @0x1ae8d8 ldr r3, [r6, #0xb8] */
/* @0x1ae8dc str r5, [r6, #0xbc] */
/* @0x1ae8e0 cmp r3, #0 */
/* @0x1ae8e4 ble 0x1ae9b0 <_ZN5CRoom14LoadFromStreamEP7CStream+0x5b8> */
/* ── tile 记录体：9 个流字段 + 5 个常量 ─────────────────────────────
 *   r7 = 元素偏移（i*56）、r8 = 计数、r9 = 0x3F800000(1.0f)、r10 = 1、r11 = 0x00FFFFFF。
 *   落位（r5 = CRoom+0xc0 + i*56）：
 *     +0x00 = (float)(int)ReadInteger   +0x04 = (float)(int)ReadInteger
 *     +0x08 = ReadInteger   +0x0c = …   +0x10 = …   +0x14 = …   +0x18 = …
 *     +0x1c = (float)(int)ReadInteger   +0x20 = ReadInteger（第 9 个，最后一格读）
 *     +0x24 = 1.0f   +0x28 = 1.0f   +0x2c = 0x00FFFFFF   +0x30 = 1.0f   +0x34 = 1(bool)
 *   ★ 与 DeSerialise 的 14 字段表对照：那边 14 个全从流里读；这边只读 9 个，
 *     +0x24/+0x28/+0x2c/+0x30/+0x34 用常量补齐（tile 宽高归 1、blend 归 0x00FFFFFF、可见归 1）。
 *   ★ 写常量的指令夹在读之间（0x1ae990-0x1ae9a4 在 0x1ae988 的读之后），第 9 个读的结果
 *     直到 0x1ae9a8 才写进 +0x20 —— 顺序读错会把常量当成读出来的值。
 */

/* @0x1ae8e8 mov r7, #0 */
/* @0x1ae8ec mov r9, #1065353216 */
/* @0x1ae8f0 mov r8, r7 */
/* @0x1ae8f4 mvn r11, #-16777216 */
/* @0x1ae8f8 mov r10, #1 */
/* @0x1ae8fc mov r0, r4 */
/* @0x1ae900 ldr r5, [r6, #0xc0] */
/* @0x1ae904 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae908 add r8, r8, #1 */
/* @0x1ae90c add r5, r5, r7 */
/* @0x1ae910 add r7, r7, #56 */
/* @0x1ae914 vmov s13, r0 */
/* @0x1ae918 mov r0, r4 */
/* @0x1ae91c vcvt.f32.s32 s15, s13 */
/* @0x1ae920 vstr s15, [r5] */
/* @0x1ae924 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae928 vmov s14, r0 */
/* @0x1ae92c mov r0, r4 */
/* @0x1ae930 vcvt.f32.s32 s15, s14 */
/* @0x1ae934 vstr s15, [r5, #4] */
/* @0x1ae938 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae93c str r0, [r5, #0x8] */
/* @0x1ae940 mov r0, r4 */
/* @0x1ae944 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae948 str r0, [r5, #0xc] */
/* @0x1ae94c mov r0, r4 */
/* @0x1ae950 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae954 str r0, [r5, #0x10] */
/* @0x1ae958 mov r0, r4 */
/* @0x1ae95c bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae960 str r0, [r5, #0x14] */
/* @0x1ae964 mov r0, r4 */
/* @0x1ae968 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae96c str r0, [r5, #0x18] */
/* @0x1ae970 mov r0, r4 */
/* @0x1ae974 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae978 vmov s13, r0 */
/* @0x1ae97c mov r0, r4 */
/* @0x1ae980 vcvt.f32.s32 s15, s13 */
/* @0x1ae984 vstr s15, [r5, #28] */
/* @0x1ae988 bl 0x201730 <_ZN7CStream11ReadIntegerEv> */
/* @0x1ae98c ldr r3, [r6, #0xb8] */
/* @0x1ae990 str r9, [r5, #0x24] */
/* @0x1ae994 cmp r3, r8 */
/* @0x1ae998 str r9, [r5, #0x28] */
/* @0x1ae99c str r11, [r5, #0x2c] */
/* @0x1ae9a0 str r9, [r5, #0x30] */
/* @0x1ae9a4 strb r10, [r5, #0x34] */
/* @0x1ae9a8 str r0, [r5, #0x20] */
/* @0x1ae9ac bgt 0x1ae8fc <_ZN5CRoom14LoadFromStreamEP7CStream+0x504> */
/* ── 正常出口：return true ───────────────────────────────────────
 *   全函数只有这一处成功返回，且返回值恒为 1。
 */

/* @0x1ae9b0 mov r0, #1 */
/* @0x1ae9b4 add sp, sp, #28 */
/* @0x1ae9b8 vpop {d8} */
/* @0x1ae9bc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* ── 深度降序链的「前插」（插在中间或成为新 head）───────────────────
 *   cur+0x178 == 0 → 成为新 head（room+0x84 = inst、inst+0x178 = 0、cur+0x178 = inst）
 *   否则插到 prev 与 cur 之间（inst+0x178 = prev、prev+0x17c = inst、inst+0x17c = cur、
 *   cur+0x178 = inst）
 *   两路最后 vstr depth → inst+0x184。与 DeSerialise 0x1acf50-0x1acf7c 逐条同构。
 *   ★ 0x1ae9d0 的 ldrne 是重读 prev（编译器没复用 r2），不是第二个指针。
 */

/* @0x1ae9c0 ldr r2, [r3, #0x178] */
/* @0x1ae9c4 cmp r2, #0 */
/* @0x1ae9c8 streq r3, [r5, #0x17c] */
/* @0x1ae9cc strne r2, [r5, #0x178] */
/* @0x1ae9d0 ldrne r2, [r3, #0x178] */
/* @0x1ae9d4 streq r5, [r3, #0x178] */
/* @0x1ae9d8 strne r3, [r5, #0x17c] */
/* @0x1ae9dc streq r5, [r6, #0x84] */
/* @0x1ae9e0 strne r5, [r2, #0x17c] */
/* @0x1ae9e4 streq r2, [r5, #0x178] */
/* @0x1ae9e8 strne r5, [r3, #0x178] */
/* @0x1ae9ec vstr s14, [r5, #388] */
/* @0x1ae9f0 b 0x1ae874 <_ZN5CRoom14LoadFromStreamEP7CStream+0x47c> */
/* ── 空链首插：head = tail = inst，+0x184 = +0x180（depth 快照），两链域清零 ──
 *   与 DeSerialise 0x1ad02c-0x1ad040 逐条同构。
 */

/* @0x1ae9f4 ldr r2, [r5, #0x180] */
/* @0x1ae9f8 str r5, [r6, #0x84] */
/* @0x1ae9fc str r5, [r6, #0x80] */
/* @0x1aea00 str r2, [r5, #0x184] */
/* @0x1aea04 str r3, [r5, #0x17c] */
/* @0x1aea08 str r3, [r5, #0x178] */
/* @0x1aea0c b 0x1ae874 <_ZN5CRoom14LoadFromStreamEP7CStream+0x47c> */
/* ── tile 段的两条清理出口 ───────────────────────────────────────
 *   0x1aea10：n == 0 且旧数组存在 → Free、+0xc0 = 0（r5 此时就是 0），跳 0x1ae8d8 写 +0xbc。
 *   0x1aea28：n*56 溢出成 0（lsls 置 Z）→ Free 旧指针、+0xc0 = 0，同样跳 0x1ae8d8。
 *   ★ 两条都不改 +0xb8（= n 已经写过），所以「条数非 0 但基址为 0」这个状态是可达的。
 */

/* @0x1aea10 ldr r0, [r6, #0xc0] */
/* @0x1aea14 cmp r0, #0 */
/* @0x1aea18 beq 0x1aea28 <_ZN5CRoom14LoadFromStreamEP7CStream+0x630> */
/* @0x1aea1c bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aea20 str r5, [r6, #0xc0] */
/* @0x1aea24 b 0x1ae8d8 <_ZN5CRoom14LoadFromStreamEP7CStream+0x4e0> */
/* @0x1aea28 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */
/* @0x1aea2c mov r3, #0 */
/* @0x1aea30 str r3, [r6, #0xc0] */
/* @0x1aea34 b 0x1ae8d8 <_ZN5CRoom14LoadFromStreamEP7CStream+0x4e0> */
/* @0x1aea38 andseq lr, r9, r8, ror #18 */

/* ── literal pool（0x1aea38，1 字；objdump 把数据字译成指令，非指令）──────────
 *   0x1aea38 = 0x0019e968  加数：pc(0x1ae8cc+8=0x1ae8d4) + 0x19e968 = 0x34d23c
 *            = "../jni/yoyo/../../../Files/Platform/cARRAY_STRUCTURE.h"（tile 数组 ReAlloc 的文件名）
 */

