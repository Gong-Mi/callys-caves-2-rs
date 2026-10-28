/* cally 逆向卡：Command_More（原版 libyoyo.so，armv7）
 * 本卡把 Command_* 剩下的 32 个小函数一次收完（另附 Run_Room_Set 与 Contact_TestFree 两个
 * 只有几条指令的夹具），并与已有卡分工：Command_Change / Command_Destroy / Command_Collision
 * （Line/Rectangle）/ Command_InstancePlace / Command_SaveUnzip（SaveGame(int)/Unzip/Bounce）
 * 已各自成卡，本卡不重复锚定它们的字节。
 * @func 0x1c89a4 0x1c8bb4  size 528  132 条  Command_CollisionPoint(CInstance*, float, float, int, bool, bool)
 * @func 0x1c8bb4 0x1c8df8  size 580  145 条  Command_CollisionEllipse(CInstance*, float, float, float, float, int, bool, bool)
 * @func 0x1c8ed0 0x1c90cc  size 508  127 条  Command_InstanceNumber(int)
 * @func 0x1c90cc 0x1c9290  size 452  113 条  Command_InstancePosition(float, float, int)
 * @func 0x1c9290 0x1c9414  size 388  97 条  Command_InstanceNearest(float, float, int)
 * @func 0x1c9414 0x1c9594  size 384  96 条  Command_InstanceFurthest(float, float, int)
 * @func 0x1c9594 0x1c961c  size 136  34 条  Command_Snap(CInstance*, float, float)
 * @func 0x1c961c 0x1c97ec  size 464  116 条  Command_Wrap(CInstance*, bool, bool)
 * @func 0x1c97ec 0x1c983c  size 80  20 条  Command_MoveTowards(CInstance*, float, float, float)
 * @func 0x1c983c 0x1c98d4  size 152  38 条  Command_Create(int, float, float)
 * @func 0x1c98d4 0x1c9980  size 172  43 条  Command_Create_Depth(int, float, float, int)
 * @func 0x1c9980 0x1c9a74  size 244  61 条  Command_Create_Layer(int, float, float, int)
 * @func 0x1c9a74 0x1c9b54  size 224  56 条  Command_Create_Layer(int, float, float, char const*)
 * @func 0x1c9c88 0x1c9cf8  size 112  28 条  Command_DestroyAt(float, float)
 * @func 0x1c9cf8 0x1c9da8  size 176  44 条  Command_ChangeAt(float, float, int, bool)
 * @func 0x1c9da8 0x1c9dbc  size 20  5 条  Command_ObjectAt(float, float, int)
 * @func 0x1c9dbc 0x1c9e08  size 76  19 条  Command_SetSprite(CInstance*, int)
 * @func 0x1c9e08 0x1c9e68  size 96  24 条  Command_GotoRoom(int, int)
 * @func 0x1c9e68 0x1c9ed0  size 104  26 条  Command_PreviousRoom(int)
 * @func 0x1c9ed0 0x1c9f38  size 104  26 条  Command_NextRoom(int)
 * @func 0x1c9f38 0x1c9f50  size 24  6 条  Command_CurrentRoom(int)
 * @func 0x1c9f50 0x1c9f54  size 4  1 条  Command_EndGame()
 * @func 0x1c9f54 0x1c9fac  size 88  22 条  Command_RestartGame()
 * @func 0x1c9fac 0x1ca040  size 148  37 条  Command_ScreenShot(char const*)
 * @func 0x1ca9f8 0x1caa1c  size 36  9 条  Command_IsMeeting(CInstance*, int, float, float)
 * @func 0x1caa1c 0x1cab94  size 376  94 条  Command_IsEmpty(CInstance*, float, float)
 * @func 0x1cab94 0x1cad18  size 388  97 条  Command_IsFree(CInstance*, float, float)
 * @func 0x1cad18 0x1cad28  size 16  4 条  Contact_TestFree(CInstance*, float, float, bool)
 * @func 0x1cad28 0x1cae64  size 316  79 条  Command_MoveContact(CInstance*, float, float, bool)
 * @func 0x1cae64 0x1caf90  size 300  75 条  Command_MoveOutside(CInstance*, float, float, bool)
 * @func 0x1cba58 0x1cba6c  size 20  5 条  Run_Room_Set(CRoom*)
 * @func 0x1d0dd8 0x1d0ed0  size 248  62 条  Command_LoadGame(int)
 * @func 0x1d1468 0x1d14fc  size 148  37 条  Command_SaveGame(char const*)
 * @func 0x1d14fc 0x1d168c  size 400  100 条  Command_LoadGame(char const*)
 * 锚点总数: 1878 条（= 下面每段的 [起,止) 在 asm/index-Command_More.tsv 里的全部行；
 *           literal pool 的字也在内，mnem 照 index 原样，多为 .word 或 objdump 的误译）
 * 级别: 正文（每个函数都逐条落锚；参数落位、分支门、全局写、被调函数全部定位）
 *       —— 例外三处，逐处标注：① Command_EndGame 只有一条 bx lr（本卡给它一行锚）；
 *          ② Wrap 的 Sprite_Data 字段号 28/32 语义只证到「宽×xscale / 高×yscale」；
 *          ③ Command_LoadGame(int) 的 0x3f511c 队列槽只证「-1 = 空」。
 * 位置: 0x1c89a4..0x1cb770 的 Command_* 主簇（0x1c8df8 的 ShouldUseFastCollision 与
 *       0x1cb234 的 RTree::SearchLine 不属于本卡）+ 0x1d0dd8 起的存档簇 + 0x1cba58 的
 *       Run_Room_Set。整簇在 .text 里连续排布，只有已出卡的 8 个函数被跳过。
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   这 32 个函数是 GML 动作层的「执行端」：内建层（F_*）把 RValue 实参拆成 C 实参、
 *   重排后调进来，命令层只碰三类东西 —— ①对象表/实例表（查询与派发）、②CInstance 的
 *   位置/速度/精灵字段、③房间与存档的全局信箱（0x542950/0x542954/0x542958/0x54298c）。
 *   它们自己不含 VM 逻辑，也没有一条指令碰 RValue。
 *
 * ── 分层：内建层 → 命令层 的实参对照（本卡实测，跨层只给地址不给锚点）──────
 *   内建                                    命令层调用点        实参重排
 *   F_InstanceCreate 109598                 Command_Create      1095ac args[2]→obj、args[0]→x、args[1]→y
 *                                          0x1095dc            ⇒ Create(obj, x, y)（GML 侧是 (x,y,obj)）
 *   YYGML_instance_create 10b09c            Command_Create      r0=x→r1、r1=y→r2、r2=obj→r0（同一次重排）
 *   F_InstanceCreateDepth 109634            Create_Depth        r3 = depth、obj 走栈
 *   F_InstanceCreateLayer 1096e4            Create_Layer×2      (obj, x, y, layer|name)
 *   F_PlaceMeeting 107fb4                   Command_IsMeeting   107fd8 args[2]→obj（-1/-2 换成
 *                                          0x108044            inst->0x78/other->0x78，-4 直接返回 0）
 *                                                              ⇒ IsMeeting(inst, obj, x, y)
 *   Command_IsMeeting 自己                  InstancePlace       0x1caa0c 把 (obj,x,y) 再排成 (x,y,obj)
 *   F_RoomGoto 109ab8                       Command_GotoRoom    109ac4 YYGetInt32(args,0)=房号；
 *                                                              r1 = transition_kind(0x542950)
 *   F_RoomGotoPrevious/Next 109ae0/109af4   Prev/NextRoom       同：r0 = transition_kind
 *   YYGML_room_goto_previous/next 10c2e4    Prev/NextRoom       同
 *   YYGML_room_restart 10c30c               Command_CurrentRoom 同
 *   YYGML_game_end 10c320 / restart 10c324  EndGame/Restart     b 尾跳，无实参
 *   F_GameSave 109c1c / F_GameLoad 109c04   SaveGame/LoadGame   YYGetString(args,0) → char const*
 *   F_GameSaveBuffer 109c34 / Buffer 109c4c SaveGame/LoadGame   YYGetInt32(args,0) → int bufid
 *   F_CollisionPoint 108f80                 CollisionPoint      直接照签名传 6 参
 *   F_PositionDestroy 13e0cc / F_ActionKillPosition / F_PositionChange / F_PositionMeeting /
 *   F_PlaceEmpty / F_PlaceFree / F_MoveContact* / F_MoveRandom / TestFree / Contact_TestFree /
 *   Bounce_Test —— 都是「排好参就 b/bl 进来」的一层薄壳（调用者表见每节）。
 *   ⇒ 规律：命令层的参数序一律是「主语在前」——实例指针先、标量后、对象/层在后；
 *     GML 内建层的参数序是「GM 手册序」。两者之间只有一次重排，没有第二层语义。
 *
 * ── 全局表（本卡真正读写的；GOT 槽 → 全局址 全部按 relocation/文件内容实测）──────
 *   0x542374  ptr   对象索引表：{buckets@+0, mask@+4}；entry{next@+4, key@+8, payload@+0xc}
 *                   读于 CollisionPoint/Ellipse/InstanceNumber/InstancePosition/Nearest/Furthest
 *   0x536f28  ptr   实例 id 表（同形状）；obj > 99999 时走它
 *   0x54298c  ptr   Run_Room（CRoom*）；写者只有 Run_Room_Set 0x1cba58（本卡附行）
 *   0x542990  ptr   Run_Room_List（导出符号，size 8）：{count@+0, array@+4}；StartRoom 读，本卡不碰
 *   0x542958  int   当前房间号（StartRoom 0x1d3938 写；本卡 3 个函数读）
 *   0x542954  int   换房信箱 New_Room（StartRoom 0x1d3910 写 -1；本卡 4 个函数写码值）
 *   0x542950  int   transition_kind（GV_/SV_TransitionKind 的实体；GotoRoom 写 0）
 *   0x542a64  struct 全局活动实例数组 {elem@+0, count@+8}；InstanceNumber 数的第二个来源
 *   0x542379  byte  option_use_fast_collision；IsEmpty/IsFree 的路径开关
 *   0x5429a8  ptr   RTree 根；IsEmpty/IsFree 送进 UpdateTree/Search
 *   0x5428b4  byte  RTree 搜索命中标志（搜索前置 1，回调清 0，函数返回它）
 *   0x5429cc  ptr   待消费的载入 IBuffer；Command_LoadGame(int) 写
 *   0x3f511c  int   载入队列槽（-1 = 空）；LoadGame(int) 读、LoadGame(str) 收尾写
 *   0x54295c  ptr   存档名指针；LoadGame() 0x1d1cb4 解引用后交给 LoadGame(str)
 *   0x5428e8  byte  Zeus/调试字节；RestartGame、LoadGame(int) 读
 *   0x544c38  ptr   二级指针（==0 才允许打 Debug_AddTag）；RestartGame、LoadGame(int) 读
 *   0x3eb70c → 0x47a118  错误/警告 vtable 派发器（r0=对象，r1=串，调 [vt+0xc]）
 *
 * ── 三条查询路径（CollisionPoint / Ellipse / InstanceNumber / InstancePosition 共用骨架）──
 *   路径 A  obj == -3             → 0x1c8b24 / 0x1c8d60 / 0x1c8ff4 / 0x1c919c
 *           当前房 CRoom+0x80 为链头、+0x178 为 next，全链遍历。
 *   路径 B  obj >  99999（有符号） → 0x1c8a9c / 0x1c8cd0 / 0x1c9040 / 0x1c91fc
 *           先拿 obj 与 inst+0x78（实例 id）比，相等即「是自己」；否则查 id 表 0x536f28。
 *   路径 C  其余（含 -1/-2 与普通对象索引）→ 0x1c89d4 / 0x1c8bf8 / 0x1c8ef4 / 0x1c90f0
 *           对象表 0x542374，键 = obj & mask，桶链 entry->key 比对。
 *   三条路径的候选实例都要过同样的闸（顺序固定）：
 *     notme（仅 A/B 有：cand == inst 且第 6 参为真 → 跳过）、+0x68 skip、+0x69 deactivated。
 *   ±1 差异：InstanceNumber 把 C 路径的「对象链」与全局数组 0x542a64 一起数；
 *            InstancePosition 把判定恒设为 Collision_Point(...,1) 且不查 notme；
 *            Nearest/Furthest 干脆没有 B 路径（>99999 直接 0）。
 */


/* ══ §1 碰撞/查询（0x1c89a4..0x1c9594，6 个函数）════════════════════════════════════
 * 这一族是本卡最大的一块，但结构只有三份骨架 + 一处计数变体：
 *   CollisionPoint/Ellipse/InstancePosition 都是「按 obj 选路径 → 逐候选过闸 → 拼好
 *   Collision_* 的实参 → 命中即返回该 CInstance*」；InstanceNumber 走同一骨架但只计数。
 *   返回值口径：命中返回 CInstance*，未命中返回 0（被上层当 bool 用，见 §5 ObjectAt）。
 */

/* ── 1.1 Command_CollisionPoint(inst, x, y, obj, solid, notme)  0x1c89a4..0x1c8bb4 ──
 * 实参落位: r10=inst、r9=x、r7=y、r3=obj；r8=[sp+0x20]=solid、r6=[sp+0x24]=notme
 *          （push {r4-r10,lr} 压 8 个寄存器 ⇒ 第 5/6 个值参正好在 sp+0x20/sp+0x24）
 * 入口第一句 cmn r3,#3 就是路径 A 的判定，发生在压栈之前（0x1c89a4 在 push 之前）。
 * 判定调用: CInstance::Collision_Point(inst, x, y, solid) 0x1944b0 —— solid 就是第 6 个
 *          形参之前的那个 bool（r8），notme 只在本函数内部用，不下传。
 * 对象链形状: entry->[0xc] 给首个 CInstance*，再由 inst+0xd0 拿遍历节点 {next@+0, inst@+8}；
 *          节点链为 0 就收工（0x1c8a24 / 0x1c8a34）。
 * 已知坑: 0x1c8a40 的 notme 判定是 `cmp r10,r5 / movne r3,#0 / andeq r3,r6,#1`，
 *          即「只有 cand==inst 时 r3 才可能为 1，且还要 notme 为真」——反了会自杀。
 */


/* ── 入口：obj 先判 -3，再判 >99999（0x1c89a4..0x1c89d0）── */

/* @0x1c89a4 cmn r3, #3 */
/* @0x1c89a8 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1c89ac mov r10, r0 */
/* @0x1c89b0 mov r9, r1 */
/* @0x1c89b4 mov r7, r2 */
/* @0x1c89b8 ldrb r8, [sp, #0x20] */
/* @0x1c89bc ldrb r6, [sp, #0x24] */
/* @0x1c89c0 beq 0x1c8b24 <_Z22Command_CollisionPointP9CInstanceffibb+0x180> */
/* @0x1c89c4 movw r2, #0x869f */
/* @0x1c89c8 movt r2, #0x1 */
/* @0x1c89cc cmp r3, r2 */
/* @0x1c89d0 bgt 0x1c8a9c <_Z22Command_CollisionPointP9CInstanceffibb+0xf8> */

/* ── 路径 C：对象表 0x542374（0x1c89d4..0x1c8a94）；0x1c8a90 是全函数的 0 出口 ── */

/* @0x1c89d4 ldr r2, [pc, #0x1cc] */
/* @0x1c89d8 ldr r2, [pc, r2] */
/* @0x1c89dc ldr r2, [r2] */
/* @0x1c89e0 ldr r1, [r2, #0x4] */
/* @0x1c89e4 ldr r2, [r2] */
/* @0x1c89e8 and r1, r3, r1 */
/* @0x1c89ec ldr r12, [r2, r1, lsl #3] */
/* @0x1c89f0 cmp r12, #0 */
/* @0x1c89f4 bne 0x1c8a08 <_Z22Command_CollisionPointP9CInstanceffibb+0x64> */
/* @0x1c89f8 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c89fc ldr r12, [r12, #0x4] */
/* @0x1c8a00 cmp r12, #0 */
/* @0x1c8a04 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a08 ldr r2, [r12, #0x8] */
/* @0x1c8a0c cmp r3, r2 */
/* @0x1c8a10 bne 0x1c89fc <_Z22Command_CollisionPointP9CInstanceffibb+0x58> */
/* @0x1c8a14 ldr r3, [r12, #0xc] */
/* @0x1c8a18 cmp r3, #0 */
/* @0x1c8a1c ldrne r4, [r3, #0xd0] */
/* @0x1c8a20 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a24 cmp r4, #0 */
/* @0x1c8a28 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a2c ldr r3, [r4, #0x8] */
/* @0x1c8a30 cmp r3, #0 */
/* @0x1c8a34 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8a38 ldr r5, [r4, #0x8] */
/* @0x1c8a3c ldr r4, [r4] */
/* @0x1c8a40 cmp r10, r5 */
/* @0x1c8a44 movne r3, #0 */
/* @0x1c8a48 andeq r3, r6, #1 */
/* @0x1c8a4c cmp r3, #0 */
/* @0x1c8a50 bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a54 ldrb r3, [r5, #0x68] */
/* @0x1c8a58 cmp r3, #0 */
/* @0x1c8a5c bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a60 ldrb r3, [r5, #0x69] */
/* @0x1c8a64 cmp r3, #0 */
/* @0x1c8a68 bne 0x1c8a24 <_Z22Command_CollisionPointP9CInstanceffibb+0x80> */
/* @0x1c8a6c mov r0, r5 */
/* @0x1c8a70 mov r1, r9 */
/* @0x1c8a74 mov r2, r7 */
/* @0x1c8a78 mov r3, r8 */
/* @0x1c8a7c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8a80 cmp r0, #0 */
/* @0x1c8a84 bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8a88 cmp r4, #0 */
/* @0x1c8a8c bne 0x1c8a2c <_Z22Command_CollisionPointP9CInstanceffibb+0x88> */
/* @0x1c8a90 mov r5, #0 */
/* @0x1c8a94 mov r0, r5 */
/* @0x1c8a98 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 路径 B：obj>99999 → 先比 inst+0x78，再查 id 表 0x536f28（0x1c8a9c..0x1c8b20）── */

/* @0x1c8a9c cmp r6, #0 */
/* @0x1c8aa0 bne 0x1c8b98 <_Z22Command_CollisionPointP9CInstanceffibb+0x1f4> */
/* @0x1c8aa4 ldr r2, [pc, #0x100] */
/* @0x1c8aa8 ldr r2, [pc, r2] */
/* @0x1c8aac ldr r1, [r2, #0x4] */
/* @0x1c8ab0 ldr r2, [r2] */
/* @0x1c8ab4 and r1, r3, r1 */
/* @0x1c8ab8 ldr r2, [r2, r1, lsl #3] */
/* @0x1c8abc cmp r2, #0 */
/* @0x1c8ac0 bne 0x1c8ad4 <_Z22Command_CollisionPointP9CInstanceffibb+0x130> */
/* @0x1c8ac4 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8ac8 ldr r2, [r2, #0x4] */
/* @0x1c8acc cmp r2, #0 */
/* @0x1c8ad0 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8ad4 ldr r1, [r2, #0x8] */
/* @0x1c8ad8 cmp r3, r1 */
/* @0x1c8adc bne 0x1c8ac8 <_Z22Command_CollisionPointP9CInstanceffibb+0x124> */
/* @0x1c8ae0 ldr r5, [r2, #0xc] */
/* @0x1c8ae4 cmp r5, #0 */
/* @0x1c8ae8 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8aec ldrb r3, [r5, #0x68] */
/* @0x1c8af0 cmp r3, #0 */
/* @0x1c8af4 bne 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8af8 ldrb r3, [r5, #0x69] */
/* @0x1c8afc cmp r3, #0 */
/* @0x1c8b00 bne 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b04 mov r1, r9 */
/* @0x1c8b08 mov r3, r8 */
/* @0x1c8b0c mov r2, r7 */
/* @0x1c8b10 mov r0, r5 */
/* @0x1c8b14 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8b18 cmp r0, #0 */
/* @0x1c8b1c bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8b20 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */

/* ── 路径 A：obj==-3 → 当前房链（CRoom+0x80 / +0x178）（0x1c8b24..0x1c8b94）── */

/* @0x1c8b24 ldr r3, [pc, #0x84] */
/* @0x1c8b28 ldr r3, [pc, r3] */
/* @0x1c8b2c ldr r3, [r3] */
/* @0x1c8b30 ldr r5, [r3, #0x80] */
/* @0x1c8b34 cmp r5, #0 */
/* @0x1c8b38 beq 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b3c cmp r10, r5 */
/* @0x1c8b40 movne r3, #0 */
/* @0x1c8b44 andeq r3, r6, #1 */
/* @0x1c8b48 ldr r4, [r5, #0x178] */
/* @0x1c8b4c cmp r3, #0 */
/* @0x1c8b50 bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b54 ldrb r3, [r5, #0x68] */
/* @0x1c8b58 cmp r3, #0 */
/* @0x1c8b5c bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b60 ldrb r3, [r5, #0x69] */
/* @0x1c8b64 cmp r3, #0 */
/* @0x1c8b68 bne 0x1c8b88 <_Z22Command_CollisionPointP9CInstanceffibb+0x1e4> */
/* @0x1c8b6c mov r0, r5 */
/* @0x1c8b70 mov r1, r9 */
/* @0x1c8b74 mov r2, r7 */
/* @0x1c8b78 mov r3, r8 */
/* @0x1c8b7c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c8b80 cmp r0, #0 */
/* @0x1c8b84 bne 0x1c8a94 <_Z22Command_CollisionPointP9CInstanceffibb+0xf0> */
/* @0x1c8b88 cmp r4, #0 */
/* @0x1c8b8c mov r5, r4 */
/* @0x1c8b90 bne 0x1c8b3c <_Z22Command_CollisionPointP9CInstanceffibb+0x198> */
/* @0x1c8b94 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */
/* @0x1c8b98 ldr r2, [r0, #0x78] */
/* @0x1c8b9c cmp r3, r2 */
/* @0x1c8ba0 bne 0x1c8aa4 <_Z22Command_CollisionPointP9CInstanceffibb+0x100> */
/* @0x1c8ba4 b 0x1c8a90 <_Z22Command_CollisionPointP9CInstanceffibb+0xec> */

/* ── 三个池字（非指令）：0x225264 / 0x22519c / 0x224e00 → GOT 槽 0x3edc44/0x3edc4c/0x3ed930 ── */

/* @0x1c8ba8 eoreq r5, r2, r4, ror #4 */
/* @0x1c8bac mlaeq r2, r12, r1, r5 */
/* @0x1c8bb0 eoreq r4, r2, r0, lsl #28 */

/* ── 1.2 Command_CollisionEllipse(inst, x, y, w, h, obj, solid, notme)  0x1c8bb4..0x1c8df8 ──
 * 栈参数布局: push 9 个(r4-r11,lr)=36 + vpush{d8}=8 + sub sp,#12 ⇒ 值参从 sp+0x38 起：
 *          [sp+0x38]=h（0x1c8bc0 vldr s16）、[sp+0x3c]=obj（0x1c8bcc）、
 *          [sp+0x40]=solid（0x1c8bd8）、[sp+0x44]=notme（0x1c8be0）。
 *          ⇒ 与声明 (inst,x,y,w,h,obj,bool,bool) 完全对齐，第 4 个 float 之后全部走栈。
 * 与 1.1 的唯一语义差异是判定函数换成 CInstance::Collision_Ellipse(x,y,w,h,solid) 0x194a90，
 *          它是成员函数：r0=候选实例、r1..r3=x,y,w，h 与 solid 依次压在 [sp]/[sp+4]
 *          （0x1c8c90 vstr s16,[sp] / 0x1c8c94 str r10,[sp+4]）。
 * 三路径、三闸、返回口径与 1.1 逐条同构（地址见每段注释）。
 */


/* ── 入口与栈实参（0x1c8bb4..0x1c8be4）── */

/* @0x1c8bb4 push {r4, r5, r6, r7, r8, r9, r10, r11, lr} */
/* @0x1c8bb8 vpush {d8} */
/* @0x1c8bbc sub sp, sp, #12 */
/* @0x1c8bc0 vldr s16, [sp, #56] */
/* @0x1c8bc4 mov r11, r0 */
/* @0x1c8bc8 mov r9, r1 */
/* @0x1c8bcc ldr r12, [sp, #0x3c] */
/* @0x1c8bd0 mov r8, r2 */
/* @0x1c8bd4 mov r7, r3 */
/* @0x1c8bd8 ldrb r10, [sp, #0x40] */
/* @0x1c8bdc cmn r12, #3 */
/* @0x1c8be0 ldrb r6, [sp, #0x44] */
/* @0x1c8be4 beq 0x1c8d60 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x1ac> */

/* ── 路径 C：对象表（0x1c8be8..0x1c8cbc）── */

/* @0x1c8be8 movw r3, #0x869f */
/* @0x1c8bec movt r3, #0x1 */
/* @0x1c8bf0 cmp r12, r3 */
/* @0x1c8bf4 bgt 0x1c8cd0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x11c> */
/* @0x1c8bf8 ldr r3, [pc, #0x1ec] */
/* @0x1c8bfc ldr r3, [pc, r3] */
/* @0x1c8c00 ldr r3, [r3] */
/* @0x1c8c04 ldr r2, [r3, #0x4] */
/* @0x1c8c08 ldr r3, [r3] */
/* @0x1c8c0c and r2, r12, r2 */
/* @0x1c8c10 ldr r3, [r3, r2, lsl #3] */
/* @0x1c8c14 cmp r3, #0 */
/* @0x1c8c18 bne 0x1c8c2c <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x78> */
/* @0x1c8c1c b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c20 ldr r3, [r3, #0x4] */
/* @0x1c8c24 cmp r3, #0 */
/* @0x1c8c28 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c2c ldr r2, [r3, #0x8] */
/* @0x1c8c30 cmp r12, r2 */
/* @0x1c8c34 bne 0x1c8c20 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x6c> */
/* @0x1c8c38 ldr r3, [r3, #0xc] */
/* @0x1c8c3c cmp r3, #0 */
/* @0x1c8c40 ldrne r4, [r3, #0xd0] */
/* @0x1c8c44 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c48 cmp r4, #0 */
/* @0x1c8c4c beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c50 ldr r3, [r4, #0x8] */
/* @0x1c8c54 cmp r3, #0 */
/* @0x1c8c58 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8c5c ldr r5, [r4, #0x8] */
/* @0x1c8c60 ldr r4, [r4] */
/* @0x1c8c64 cmp r11, r5 */
/* @0x1c8c68 movne r3, #0 */
/* @0x1c8c6c andeq r3, r6, #1 */
/* @0x1c8c70 cmp r3, #0 */
/* @0x1c8c74 bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c78 ldrb r3, [r5, #0x68] */
/* @0x1c8c7c cmp r3, #0 */
/* @0x1c8c80 bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c84 ldrb r3, [r5, #0x69] */
/* @0x1c8c88 cmp r3, #0 */
/* @0x1c8c8c bne 0x1c8c48 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x94> */
/* @0x1c8c90 vstr s16, [sp] */
/* @0x1c8c94 str r10, [sp, #0x4] */
/* @0x1c8c98 mov r0, r5 */
/* @0x1c8c9c mov r1, r9 */
/* @0x1c8ca0 mov r2, r8 */
/* @0x1c8ca4 mov r3, r7 */
/* @0x1c8ca8 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8cac cmp r0, #0 */
/* @0x1c8cb0 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8cb4 cmp r4, #0 */
/* @0x1c8cb8 bne 0x1c8c50 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x9c> */
/* @0x1c8cbc mov r5, #0 */
/* @0x1c8cc0 mov r0, r5 */
/* @0x1c8cc4 add sp, sp, #12 */
/* @0x1c8cc8 vpop {d8} */
/* @0x1c8ccc pop {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── 路径 B：id 表（0x1c8cd0..0x1c8d5c）── */

/* @0x1c8cd0 cmp r6, #0 */
/* @0x1c8cd4 bne 0x1c8ddc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x228> */
/* @0x1c8cd8 ldr r3, [pc, #0x110] */
/* @0x1c8cdc ldr r3, [pc, r3] */
/* @0x1c8ce0 ldr r2, [r3, #0x4] */
/* @0x1c8ce4 ldr r3, [r3] */
/* @0x1c8ce8 and r2, r12, r2 */
/* @0x1c8cec ldr r3, [r3, r2, lsl #3] */
/* @0x1c8cf0 cmp r3, #0 */
/* @0x1c8cf4 bne 0x1c8d08 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x154> */
/* @0x1c8cf8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8cfc ldr r3, [r3, #0x4] */
/* @0x1c8d00 cmp r3, #0 */
/* @0x1c8d04 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d08 ldr r2, [r3, #0x8] */
/* @0x1c8d0c cmp r12, r2 */
/* @0x1c8d10 bne 0x1c8cfc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x148> */
/* @0x1c8d14 ldr r5, [r3, #0xc] */
/* @0x1c8d18 cmp r5, #0 */
/* @0x1c8d1c beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d20 ldrb r3, [r5, #0x68] */
/* @0x1c8d24 cmp r3, #0 */
/* @0x1c8d28 bne 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d2c ldrb r3, [r5, #0x69] */
/* @0x1c8d30 cmp r3, #0 */
/* @0x1c8d34 bne 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d38 vstr s16, [sp] */
/* @0x1c8d3c str r10, [sp, #0x4] */
/* @0x1c8d40 mov r1, r9 */
/* @0x1c8d44 mov r0, r5 */
/* @0x1c8d48 mov r2, r8 */
/* @0x1c8d4c mov r3, r7 */
/* @0x1c8d50 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8d54 cmp r0, #0 */
/* @0x1c8d58 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8d5c b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */

/* ── 路径 A：房间链（0x1c8d60..0x1c8dd8）── */

/* @0x1c8d60 ldr r3, [pc, #0x8c] */
/* @0x1c8d64 ldr r3, [pc, r3] */
/* @0x1c8d68 ldr r3, [r3] */
/* @0x1c8d6c ldr r5, [r3, #0x80] */
/* @0x1c8d70 cmp r5, #0 */
/* @0x1c8d74 beq 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8d78 cmp r11, r5 */
/* @0x1c8d7c movne r3, #0 */
/* @0x1c8d80 andeq r3, r6, #1 */
/* @0x1c8d84 ldr r4, [r5, #0x178] */
/* @0x1c8d88 cmp r3, #0 */
/* @0x1c8d8c bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8d90 ldrb r3, [r5, #0x68] */
/* @0x1c8d94 cmp r3, #0 */
/* @0x1c8d98 bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8d9c ldrb r3, [r5, #0x69] */
/* @0x1c8da0 cmp r3, #0 */
/* @0x1c8da4 bne 0x1c8dcc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x218> */
/* @0x1c8da8 vstr s16, [sp] */
/* @0x1c8dac str r10, [sp, #0x4] */
/* @0x1c8db0 mov r0, r5 */
/* @0x1c8db4 mov r1, r9 */
/* @0x1c8db8 mov r2, r8 */
/* @0x1c8dbc mov r3, r7 */
/* @0x1c8dc0 bl 0x194a90 <_ZN9CInstance17Collision_EllipseEffffb> */
/* @0x1c8dc4 cmp r0, #0 */
/* @0x1c8dc8 bne 0x1c8cc0 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x10c> */
/* @0x1c8dcc cmp r4, #0 */
/* @0x1c8dd0 mov r5, r4 */
/* @0x1c8dd4 bne 0x1c8d78 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x1c4> */
/* @0x1c8dd8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */
/* @0x1c8ddc ldr r3, [r0, #0x78] */
/* @0x1c8de0 cmp r12, r3 */
/* @0x1c8de4 bne 0x1c8cd8 <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x124> */
/* @0x1c8de8 b 0x1c8cbc <_Z24Command_CollisionEllipseP9CInstanceffffibb+0x108> */

/* ── 三个池字（非指令）：0x225040 / 0x224f68 / 0x224bc4 ── */

/* @0x1c8dec eoreq r5, r2, r0, asr #32 */
/* @0x1c8df0 eoreq r4, r2, r8, ror #30 */
/* @0x1c8df4 eoreq r4, r2, r4, asr #23 */

/* ── 1.3 Command_InstanceNumber(int obj)  0x1c8ed0..0x1c90cc ──
 * 计数口径（三路径各自成段）：
 *   A  obj == -3          数当前房链上 +0x68==0 且 +0x69==0 的实例（0x1c900c..0x1c9034）
 *   B  obj >  99999       在 id 表里定位到唯一实例，返回 (0x68==0 && 0x69==0) ? 1 : 0
 *                         （0x1c9090..0x1c90a0 的 movne/ldrbeq/eoreq 就是这条三目）
 *   C  其余               先数对象链（entry->[0xc] → inst+0xd0 节点链，0x1c8f48..0x1c8f98），
 *                         再数全局数组 0x542a64（{elem@+0,count@+8}，按 inst+0x7c 对象索引过滤，
 *                         0x1c8f9c..0x1c8ff0）—— 两个来源相加，源码里没有互斥判断。
 * ★ 0x1c8ed8/0x1c8edc 先把 GOT 基址算进 r4（add pc → 0x3f1c58），后面全用负偏移取槽
 *   （0xffffbfec/-0x4010 等），这是本卡唯一采用该写法的函数；锚点里的 .word 负数就是这些槽偏移。
 */


/* ── 入口：GOT 基址 + 三路选择（0x1c8ed0..0x1c8ef0）── */

/* @0x1c8ed0 push {r4, r5} */
/* @0x1c8ed4 cmn r0, #3 */
/* @0x1c8ed8 ldr r4, [pc, #0x1d8] */
/* @0x1c8edc add r4, pc, r4 */
/* @0x1c8ee0 beq 0x1c8ff4 <_Z22Command_InstanceNumberi+0x124> */
/* @0x1c8ee4 movw r3, #0x869f */
/* @0x1c8ee8 movt r3, #0x1 */
/* @0x1c8eec cmp r0, r3 */
/* @0x1c8ef0 bgt 0x1c9040 <_Z22Command_InstanceNumberi+0x170> */

/* ── 路径 C（0x1c8ef4..0x1c8f40）：对象链 ── */

/* @0x1c8ef4 ldr r3, [pc, #0x1c0] */
/* @0x1c8ef8 ldr r3, [r4, r3] */
/* @0x1c8efc ldr r3, [r3] */
/* @0x1c8f00 ldr r2, [r3, #0x4] */
/* @0x1c8f04 ldr r3, [r3] */
/* @0x1c8f08 and r2, r0, r2 */
/* @0x1c8f0c ldr r3, [r3, r2, lsl #3] */
/* @0x1c8f10 cmp r3, #0 */
/* @0x1c8f14 bne 0x1c8f30 <_Z22Command_InstanceNumberi+0x60> */
/* @0x1c8f18 mov r0, r3 */
/* @0x1c8f1c pop {r4, r5} */
/* @0x1c8f20 bx lr */
/* @0x1c8f24 ldr r3, [r3, #0x4] */
/* @0x1c8f28 cmp r3, #0 */
/* @0x1c8f2c beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8f30 ldr r2, [r3, #0x8] */
/* @0x1c8f34 cmp r0, r2 */
/* @0x1c8f38 bne 0x1c8f24 <_Z22Command_InstanceNumberi+0x54> */
/* @0x1c8f3c ldr r3, [r3, #0xc] */
/* @0x1c8f40 cmp r3, #0 */
/* @0x1c8f44 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */

/* ── 路径 C 续：节点链计数（0x1c8f48..0x1c8f98）── */

/* @0x1c8f48 ldr r2, [r3, #0xd0] */
/* @0x1c8f4c cmp r2, #0 */
/* @0x1c8f50 beq 0x1c90a8 <_Z22Command_InstanceNumberi+0x1d8> */
/* @0x1c8f54 ldr r3, [r2, #0x8] */
/* @0x1c8f58 cmp r3, #0 */
/* @0x1c8f5c beq 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c8f60 mov r3, #0 */
/* @0x1c8f64 b 0x1c8f74 <_Z22Command_InstanceNumberi+0xa4> */
/* @0x1c8f68 ldr r1, [r2, #0x8] */
/* @0x1c8f6c cmp r1, #0 */
/* @0x1c8f70 beq 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c8f74 ldr r1, [r2, #0x8] */
/* @0x1c8f78 ldr r2, [r2] */
/* @0x1c8f7c ldrb r12, [r1, #0x68] */
/* @0x1c8f80 cmp r12, #0 */
/* @0x1c8f84 bne 0x1c8f94 <_Z22Command_InstanceNumberi+0xc4> */
/* @0x1c8f88 ldrb r1, [r1, #0x69] */
/* @0x1c8f8c cmp r1, #0 */
/* @0x1c8f90 addeq r3, r3, #1 */
/* @0x1c8f94 cmp r2, #0 */
/* @0x1c8f98 bne 0x1c8f68 <_Z22Command_InstanceNumberi+0x98> */

/* ── 路径 C 续：全局活动数组 0x542a64 计数（0x1c8f9c..0x1c8ff0）── */

/* @0x1c8f9c ldr r2, [pc, #0x11c] */
/* @0x1c8fa0 ldr r5, [r4, r2] */
/* @0x1c8fa4 ldr r4, [r5, #0x8] */
/* @0x1c8fa8 cmp r4, #0 */
/* @0x1c8fac ble 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8fb0 mov r2, #0 */
/* @0x1c8fb4 b 0x1c8fc4 <_Z22Command_InstanceNumberi+0xf4> */
/* @0x1c8fb8 add r2, r2, #1 */
/* @0x1c8fbc cmp r2, r4 */
/* @0x1c8fc0 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c8fc4 ldr r1, [r5] */
/* @0x1c8fc8 ldr r1, [r1, r2, lsl #2] */
/* @0x1c8fcc ldr r12, [r1, #0x7c] */
/* @0x1c8fd0 cmp r0, r12 */
/* @0x1c8fd4 bne 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */
/* @0x1c8fd8 ldrb r12, [r1, #0x68] */
/* @0x1c8fdc cmp r12, #0 */
/* @0x1c8fe0 bne 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */
/* @0x1c8fe4 ldrb r1, [r1, #0x69] */
/* @0x1c8fe8 cmp r1, #0 */
/* @0x1c8fec addeq r3, r3, #1 */
/* @0x1c8ff0 b 0x1c8fb8 <_Z22Command_InstanceNumberi+0xe8> */

/* ── 路径 A：obj==-3 房间链计数（0x1c8ff4..0x1c903c）── */

/* @0x1c8ff4 ldr r3, [pc, #0xc8] */
/* @0x1c8ff8 ldr r3, [r4, r3] */
/* @0x1c8ffc ldr r3, [r3] */
/* @0x1c9000 ldr r2, [r3, #0x80] */
/* @0x1c9004 cmp r2, #0 */
/* @0x1c9008 beq 0x1c90b0 <_Z22Command_InstanceNumberi+0x1e0> */
/* @0x1c900c mov r0, #0 */
/* @0x1c9010 ldrb r12, [r2, #0x68] */
/* @0x1c9014 ldr r1, [r2, #0x178] */
/* @0x1c9018 cmp r12, #0 */
/* @0x1c901c bne 0x1c902c <_Z22Command_InstanceNumberi+0x15c> */
/* @0x1c9020 ldrb r12, [r2, #0x69] */
/* @0x1c9024 cmp r12, #0 */
/* @0x1c9028 addeq r0, r0, #1 */
/* @0x1c902c cmp r1, #0 */
/* @0x1c9030 mov r2, r1 */
/* @0x1c9034 bne 0x1c9010 <_Z22Command_InstanceNumberi+0x140> */
/* @0x1c9038 pop {r4, r5} */
/* @0x1c903c bx lr */

/* ── 路径 B：obj>99999 单实例 0/1（0x1c9040..0x1c90a4）── */

/* @0x1c9040 ldr r3, [pc, #0x80] */
/* @0x1c9044 ldr r3, [r4, r3] */
/* @0x1c9048 ldr r2, [r3, #0x4] */
/* @0x1c904c ldr r3, [r3] */
/* @0x1c9050 and r2, r0, r2 */
/* @0x1c9054 ldr r3, [r3, r2, lsl #3] */
/* @0x1c9058 cmp r3, #0 */
/* @0x1c905c beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c9060 ldr r2, [r3, #0x8] */
/* @0x1c9064 cmp r0, r2 */
/* @0x1c9068 beq 0x1c9084 <_Z22Command_InstanceNumberi+0x1b4> */
/* @0x1c906c ldr r3, [r3, #0x4] */
/* @0x1c9070 cmp r3, #0 */
/* @0x1c9074 beq 0x1c8f18 <_Z22Command_InstanceNumberi+0x48> */
/* @0x1c9078 ldr r2, [r3, #0x8] */
/* @0x1c907c cmp r0, r2 */
/* @0x1c9080 bne 0x1c906c <_Z22Command_InstanceNumberi+0x19c> */
/* @0x1c9084 ldr r0, [r3, #0xc] */
/* @0x1c9088 cmp r0, #0 */
/* @0x1c908c beq 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */
/* @0x1c9090 ldrb r3, [r0, #0x68] */
/* @0x1c9094 cmp r3, #0 */
/* @0x1c9098 movne r0, #0 */
/* @0x1c909c ldrbeq r0, [r0, #0x69] */
/* @0x1c90a0 eoreq r0, r0, #1 */
/* @0x1c90a4 b 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */

/* ── 两条小尾巴（0x1c90a8 / 0x1c90b0）与四个池字（0x1c90b8..）── */

/* @0x1c90a8 mov r3, r2 */
/* @0x1c90ac b 0x1c8f9c <_Z22Command_InstanceNumberi+0xcc> */
/* @0x1c90b0 mov r0, r2 */
/* @0x1c90b4 b 0x1c8f1c <_Z22Command_InstanceNumberi+0x4c> */
/* @0x1c90b8 eoreq r8, r2, r4, ror sp */
/* @0x1c90bc .word 0xffffbfec */
/* @0x1c90c0 .word 0xffffbff0 */
/* @0x1c90c4 .word 0xffffbcd8 */
/* @0x1c90c8 .word 0xffffbff4 */

/* ── 1.4 Command_InstancePosition(float x, float y, int obj)  0x1c90cc..0x1c9290 ──
 * 返回 CInstance*。与 1.1 的差异只有两处、且都在判定调用上：
 *   ① 0x1c917c / 0x1c91d0 / 0x1c9270 三处都是 mov r3,#1 ⇒ Collision_Point 的 solid 恒真，
 *      本函数没有 solid 形参；
 *   ② 没有 notme 形参，也就没有 0x1c8a40 那种自比较闸 —— 传进来的 inst 不参与过滤。
 * Command_ObjectAt（§4）就是它的 != 0。
 */


/* ── 入口（0x1c90cc..0x1c90ec）── */

/* @0x1c90cc cmn r2, #3 */
/* @0x1c90d0 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c90d4 mov r7, r0 */
/* @0x1c90d8 mov r6, r1 */
/* @0x1c90dc beq 0x1c919c <_Z24Command_InstancePositionffi+0xd0> */
/* @0x1c90e0 movw r3, #0x869f */
/* @0x1c90e4 movt r3, #0x1 */
/* @0x1c90e8 cmp r2, r3 */
/* @0x1c90ec bgt 0x1c91fc <_Z24Command_InstancePositionffi+0x130> */

/* ── 路径 C（0x1c90f0..0x1c9198），命中在 0x1c9118 返回 r5 ── */

/* @0x1c90f0 ldr r3, [pc, #0x18c] */
/* @0x1c90f4 ldr r3, [pc, r3] */
/* @0x1c90f8 ldr r3, [r3] */
/* @0x1c90fc ldr r1, [r3, #0x4] */
/* @0x1c9100 ldr r3, [r3] */
/* @0x1c9104 and r1, r2, r1 */
/* @0x1c9108 ldr r3, [r3, r1, lsl #3] */
/* @0x1c910c cmp r3, #0 */
/* @0x1c9110 bne 0x1c912c <_Z24Command_InstancePositionffi+0x60> */
/* @0x1c9114 mov r5, #0 */
/* @0x1c9118 mov r0, r5 */
/* @0x1c911c pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9120 ldr r3, [r3, #0x4] */
/* @0x1c9124 cmp r3, #0 */
/* @0x1c9128 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c912c ldr r1, [r3, #0x8] */
/* @0x1c9130 cmp r2, r1 */
/* @0x1c9134 bne 0x1c9120 <_Z24Command_InstancePositionffi+0x54> */
/* @0x1c9138 ldr r3, [r3, #0xc] */
/* @0x1c913c cmp r3, #0 */
/* @0x1c9140 ldrne r4, [r3, #0xd0] */
/* @0x1c9144 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9148 cmp r4, #0 */
/* @0x1c914c beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9150 ldr r3, [r4, #0x8] */
/* @0x1c9154 cmp r3, #0 */
/* @0x1c9158 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c915c ldr r5, [r4, #0x8] */
/* @0x1c9160 ldr r4, [r4] */
/* @0x1c9164 ldrb r3, [r5, #0x68] */
/* @0x1c9168 cmp r3, #0 */
/* @0x1c916c bne 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c9170 ldrb r3, [r5, #0x69] */
/* @0x1c9174 cmp r3, #0 */
/* @0x1c9178 bne 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c917c mov r3, #1 */
/* @0x1c9180 mov r0, r5 */
/* @0x1c9184 mov r1, r7 */
/* @0x1c9188 mov r2, r6 */
/* @0x1c918c bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9190 cmp r0, #0 */
/* @0x1c9194 beq 0x1c9148 <_Z24Command_InstancePositionffi+0x7c> */
/* @0x1c9198 b 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */

/* ── 路径 A（0x1c919c..0x1c91f8）── */

/* @0x1c919c ldr r3, [pc, #0xe4] */
/* @0x1c91a0 ldr r3, [pc, r3] */
/* @0x1c91a4 ldr r3, [r3] */
/* @0x1c91a8 ldr r5, [r3, #0x80] */
/* @0x1c91ac cmp r5, #0 */
/* @0x1c91b0 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c91b4 ldrb r3, [r5, #0x68] */
/* @0x1c91b8 ldr r4, [r5, #0x178] */
/* @0x1c91bc cmp r3, #0 */
/* @0x1c91c0 bne 0x1c91ec <_Z24Command_InstancePositionffi+0x120> */
/* @0x1c91c4 ldrb r3, [r5, #0x69] */
/* @0x1c91c8 cmp r3, #0 */
/* @0x1c91cc bne 0x1c91ec <_Z24Command_InstancePositionffi+0x120> */
/* @0x1c91d0 mov r3, #1 */
/* @0x1c91d4 mov r0, r5 */
/* @0x1c91d8 mov r1, r7 */
/* @0x1c91dc mov r2, r6 */
/* @0x1c91e0 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c91e4 cmp r0, #0 */
/* @0x1c91e8 bne 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */
/* @0x1c91ec cmp r4, #0 */
/* @0x1c91f0 mov r5, r4 */
/* @0x1c91f4 bne 0x1c91b4 <_Z24Command_InstancePositionffi+0xe8> */
/* @0x1c91f8 b 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */

/* ── 路径 B（0x1c91fc..0x1c9280）── */

/* @0x1c91fc ldr r3, [pc, #0x88] */
/* @0x1c9200 ldr r3, [pc, r3] */
/* @0x1c9204 ldr r1, [r3, #0x4] */
/* @0x1c9208 ldr r3, [r3] */
/* @0x1c920c and r1, r2, r1 */
/* @0x1c9210 ldr r3, [r3, r1, lsl #3] */
/* @0x1c9214 cmp r3, #0 */
/* @0x1c9218 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c921c ldr r1, [r3, #0x8] */
/* @0x1c9220 cmp r2, r1 */
/* @0x1c9224 beq 0x1c9240 <_Z24Command_InstancePositionffi+0x174> */
/* @0x1c9228 ldr r3, [r3, #0x4] */
/* @0x1c922c cmp r3, #0 */
/* @0x1c9230 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9234 ldr r1, [r3, #0x8] */
/* @0x1c9238 cmp r2, r1 */
/* @0x1c923c bne 0x1c9228 <_Z24Command_InstancePositionffi+0x15c> */
/* @0x1c9240 ldr r5, [r3, #0xc] */
/* @0x1c9244 cmp r5, #0 */
/* @0x1c9248 beq 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c924c ldrb r3, [r5, #0x68] */
/* @0x1c9250 cmp r3, #0 */
/* @0x1c9254 bne 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9258 ldrb r3, [r5, #0x69] */
/* @0x1c925c cmp r3, #0 */
/* @0x1c9260 bne 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9264 mov r1, r7 */
/* @0x1c9268 mov r0, r5 */
/* @0x1c926c mov r2, r6 */
/* @0x1c9270 mov r3, #1 */
/* @0x1c9274 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9278 cmp r0, #0 */
/* @0x1c927c bne 0x1c9118 <_Z24Command_InstancePositionffi+0x4c> */
/* @0x1c9280 b 0x1c9114 <_Z24Command_InstancePositionffi+0x48> */
/* @0x1c9284 eoreq r4, r2, r8, asr #22 */
/* @0x1c9288 eoreq r4, r2, r8, lsl #15 */
/* @0x1c928c eoreq r4, r2, r4, asr #20 */

/* ── 1.5 Command_InstanceNearest(float x, float y, int obj)  0x1c9290..0x1c9414 ──
 * 返回最近的实例（平方欧氏距离，字段 +0xb4/+0xb8，不查 bbox、不看 solid）。
 *   · 初值 s11 = 0x7f7fffff（FLT_MAX，池字 0x1c9408）；
 *   · 只有严格更小才换：C 路径 0x1c9354 vcmpe s15,s11 + 0x1c935c vmovmi/movmi，
 *     A 路径 0x1c93d4 vcmpe s11,s15 + 0x1c93e0 vmovgt/movgt —— 两条是同一件事的两种写法，
 *     相等时保留先遇到的（链头方向的第一个）。
 *   · obj > 99999 直接 return 0（0x1c93fc mov r0,#0）—— 本函数不认实例 id。
 *   · 0x1c9310 的 bxeq lr 是「链上节点存在但 inst 为空」的早退，返回 r0=0。
 */


/* ── 入口与三路选择（0x1c9290..0x1c92b0）── */

/* @0x1c9290 cmn r2, #3 */
/* @0x1c9294 vmov s13, r0 */
/* @0x1c9298 vmov s12, r1 */
/* @0x1c929c beq 0x1c9380 <_Z23Command_InstanceNearestffi+0xf0> */
/* @0x1c92a0 movw r3, #0x869f */
/* @0x1c92a4 movt r3, #0x1 */
/* @0x1c92a8 cmp r2, r3 */
/* @0x1c92ac bgt 0x1c93fc <_Z23Command_InstanceNearestffi+0x16c> */

/* ── 路径 C（0x1c92b0..0x1c9378）── */

/* @0x1c92b0 ldr r3, [pc, #0x154] */
/* @0x1c92b4 ldr r3, [pc, r3] */
/* @0x1c92b8 ldr r3, [r3] */
/* @0x1c92bc ldr r1, [r3, #0x4] */
/* @0x1c92c0 ldr r3, [r3] */
/* @0x1c92c4 and r1, r2, r1 */
/* @0x1c92c8 ldr r0, [r3, r1, lsl #3] */
/* @0x1c92cc cmp r0, #0 */
/* @0x1c92d0 bne 0x1c92e4 <_Z23Command_InstanceNearestffi+0x54> */
/* @0x1c92d4 bx lr */
/* @0x1c92d8 ldr r0, [r0, #0x4] */
/* @0x1c92dc cmp r0, #0 */
/* @0x1c92e0 beq 0x1c937c <_Z23Command_InstanceNearestffi+0xec> */
/* @0x1c92e4 ldr r3, [r0, #0x8] */
/* @0x1c92e8 cmp r2, r3 */
/* @0x1c92ec bne 0x1c92d8 <_Z23Command_InstanceNearestffi+0x48> */
/* @0x1c92f0 ldr r0, [r0, #0xc] */
/* @0x1c92f4 cmp r0, #0 */
/* @0x1c92f8 beq 0x1c9404 <_Z23Command_InstanceNearestffi+0x174> */
/* @0x1c92fc ldr r3, [r0, #0xd0] */
/* @0x1c9300 cmp r3, #0 */
/* @0x1c9304 beq 0x1c93f4 <_Z23Command_InstanceNearestffi+0x164> */
/* @0x1c9308 ldr r0, [r3, #0x8] */
/* @0x1c930c cmp r0, #0 */
/* @0x1c9310 bxeq lr */
/* @0x1c9314 mov r0, #0 */
/* @0x1c9318 vldr s11, [pc, #232] */
/* @0x1c931c ldr r2, [r3, #0x8] */
/* @0x1c9320 ldr r3, [r3] */
/* @0x1c9324 ldrb r1, [r2, #0x68] */
/* @0x1c9328 cmp r1, #0 */
/* @0x1c932c bne 0x1c9364 <_Z23Command_InstanceNearestffi+0xd4> */
/* @0x1c9330 ldrb r1, [r2, #0x69] */
/* @0x1c9334 cmp r1, #0 */
/* @0x1c9338 bne 0x1c9364 <_Z23Command_InstanceNearestffi+0xd4> */
/* @0x1c933c vldr s15, [r2, #184] */
/* @0x1c9340 vsub.f32 s15, s15, s12 */
/* @0x1c9344 vldr s14, [r2, #180] */
/* @0x1c9348 vmul.f32 s15, s15, s15 */
/* @0x1c934c vsub.f32 s14, s14, s13 */
/* @0x1c9350 vmla.f32 s15, s14, s14 */
/* @0x1c9354 vcmpe.f32 s15, s11 */
/* @0x1c9358 vmrs APSR_nzcv, fpscr */
/* @0x1c935c vmovmi.f32 s11, s15 */
/* @0x1c9360 movmi r0, r2 */
/* @0x1c9364 cmp r3, #0 */
/* @0x1c9368 bxeq lr */
/* @0x1c936c ldr r2, [r3, #0x8] */
/* @0x1c9370 cmp r2, #0 */
/* @0x1c9374 bne 0x1c931c <_Z23Command_InstanceNearestffi+0x8c> */
/* @0x1c9378 bx lr */
/* @0x1c937c bx lr */

/* ── 路径 A（0x1c9380..0x1c93f0）── */

/* @0x1c9380 ldr r3, [pc, #0x88] */
/* @0x1c9384 ldr r3, [pc, r3] */
/* @0x1c9388 ldr r3, [r3] */
/* @0x1c938c ldr r3, [r3, #0x80] */
/* @0x1c9390 cmp r3, #0 */
/* @0x1c9394 beq 0x1c93f4 <_Z23Command_InstanceNearestffi+0x164> */
/* @0x1c9398 mov r0, #0 */
/* @0x1c939c vldr s11, [pc, #100] */
/* @0x1c93a0 ldrb r1, [r3, #0x68] */
/* @0x1c93a4 ldr r2, [r3, #0x178] */
/* @0x1c93a8 cmp r1, #0 */
/* @0x1c93ac bne 0x1c93e4 <_Z23Command_InstanceNearestffi+0x154> */
/* @0x1c93b0 ldrb r1, [r3, #0x69] */
/* @0x1c93b4 cmp r1, #0 */
/* @0x1c93b8 bne 0x1c93e4 <_Z23Command_InstanceNearestffi+0x154> */
/* @0x1c93bc vldr s15, [r3, #184] */
/* @0x1c93c0 vsub.f32 s15, s15, s12 */
/* @0x1c93c4 vldr s14, [r3, #180] */
/* @0x1c93c8 vmul.f32 s15, s15, s15 */
/* @0x1c93cc vsub.f32 s14, s14, s13 */
/* @0x1c93d0 vmla.f32 s15, s14, s14 */
/* @0x1c93d4 vcmpe.f32 s11, s15 */
/* @0x1c93d8 vmrs APSR_nzcv, fpscr */
/* @0x1c93dc vmovgt.f32 s11, s15 */
/* @0x1c93e0 movgt r0, r3 */
/* @0x1c93e4 cmp r2, #0 */
/* @0x1c93e8 mov r3, r2 */
/* @0x1c93ec bne 0x1c93a0 <_Z23Command_InstanceNearestffi+0x110> */
/* @0x1c93f0 bx lr */

/* ── 出口族与常量（0x1c93f4..0x1c9410）── */

/* @0x1c93f4 mov r0, r3 */
/* @0x1c93f8 bx lr */
/* @0x1c93fc mov r0, #0 */
/* @0x1c9400 bx lr */
/* @0x1c9404 bx lr */
/* @0x1c9408 svcvc #0x7fffff */
/* @0x1c940c eoreq r4, r2, r8, lsl #19 */
/* @0x1c9410 eoreq r4, r2, r4, lsr #11 */

/* ── 1.6 Command_InstanceFurthest(float x, float y, int obj)  0x1c9414..0x1c9594 ──
 * 与 1.5 逐条镜像，唯一差异是初值与比较方向：
 *   0x1c9498 / 0x1c951c  vmov.f32 s11,#-1.000000e+00（不是 FLT_MIN，也不是 0）
 *   0x1c94d8 vcmpe s15,s11 + vmovgt/movgt（C 路径）；0x1c9558 vcmpe s11,s15 + vmovmi/movmi（A 路径）
 * ⇒ 因为距离平方恒 >= 0，初值 -1 等价于「还没有候选」；不认实例 id（0x1c9580 mov r0,#0）。
 */


/* ── 入口与三路选择（0x1c9414..0x1c9434）── */

/* @0x1c9414 cmn r2, #3 */
/* @0x1c9418 vmov s13, r0 */
/* @0x1c941c vmov s12, r1 */
/* @0x1c9420 beq 0x1c9504 <_Z24Command_InstanceFurthestffi+0xf0> */
/* @0x1c9424 movw r3, #0x869f */
/* @0x1c9428 movt r3, #0x1 */
/* @0x1c942c cmp r2, r3 */
/* @0x1c9430 bgt 0x1c9580 <_Z24Command_InstanceFurthestffi+0x16c> */

/* ── 路径 C（0x1c9434..0x1c94fc）── */

/* @0x1c9434 ldr r3, [pc, #0x150] */
/* @0x1c9438 ldr r3, [pc, r3] */
/* @0x1c943c ldr r3, [r3] */
/* @0x1c9440 ldr r1, [r3, #0x4] */
/* @0x1c9444 ldr r3, [r3] */
/* @0x1c9448 and r1, r2, r1 */
/* @0x1c944c ldr r0, [r3, r1, lsl #3] */
/* @0x1c9450 cmp r0, #0 */
/* @0x1c9454 bne 0x1c9468 <_Z24Command_InstanceFurthestffi+0x54> */
/* @0x1c9458 bx lr */
/* @0x1c945c ldr r0, [r0, #0x4] */
/* @0x1c9460 cmp r0, #0 */
/* @0x1c9464 beq 0x1c9500 <_Z24Command_InstanceFurthestffi+0xec> */
/* @0x1c9468 ldr r3, [r0, #0x8] */
/* @0x1c946c cmp r2, r3 */
/* @0x1c9470 bne 0x1c945c <_Z24Command_InstanceFurthestffi+0x48> */
/* @0x1c9474 ldr r0, [r0, #0xc] */
/* @0x1c9478 cmp r0, #0 */
/* @0x1c947c beq 0x1c9588 <_Z24Command_InstanceFurthestffi+0x174> */
/* @0x1c9480 ldr r3, [r0, #0xd0] */
/* @0x1c9484 cmp r3, #0 */
/* @0x1c9488 beq 0x1c9578 <_Z24Command_InstanceFurthestffi+0x164> */
/* @0x1c948c ldr r0, [r3, #0x8] */
/* @0x1c9490 cmp r0, #0 */
/* @0x1c9494 bxeq lr */
/* @0x1c9498 vmov.f32 s11, #-1.000000e+00 */
/* @0x1c949c mov r0, #0 */
/* @0x1c94a0 ldr r2, [r3, #0x8] */
/* @0x1c94a4 ldr r3, [r3] */
/* @0x1c94a8 ldrb r1, [r2, #0x68] */
/* @0x1c94ac cmp r1, #0 */
/* @0x1c94b0 bne 0x1c94e8 <_Z24Command_InstanceFurthestffi+0xd4> */
/* @0x1c94b4 ldrb r1, [r2, #0x69] */
/* @0x1c94b8 cmp r1, #0 */
/* @0x1c94bc bne 0x1c94e8 <_Z24Command_InstanceFurthestffi+0xd4> */
/* @0x1c94c0 vldr s15, [r2, #184] */
/* @0x1c94c4 vsub.f32 s15, s15, s12 */
/* @0x1c94c8 vldr s14, [r2, #180] */
/* @0x1c94cc vmul.f32 s15, s15, s15 */
/* @0x1c94d0 vsub.f32 s14, s14, s13 */
/* @0x1c94d4 vmla.f32 s15, s14, s14 */
/* @0x1c94d8 vcmpe.f32 s15, s11 */
/* @0x1c94dc vmrs APSR_nzcv, fpscr */
/* @0x1c94e0 vmovgt.f32 s11, s15 */
/* @0x1c94e4 movgt r0, r2 */
/* @0x1c94e8 cmp r3, #0 */
/* @0x1c94ec bxeq lr */
/* @0x1c94f0 ldr r2, [r3, #0x8] */
/* @0x1c94f4 cmp r2, #0 */
/* @0x1c94f8 bne 0x1c94a0 <_Z24Command_InstanceFurthestffi+0x8c> */
/* @0x1c94fc bx lr */
/* @0x1c9500 bx lr */

/* ── 路径 A（0x1c9504..0x1c9574）── */

/* @0x1c9504 ldr r3, [pc, #0x84] */
/* @0x1c9508 ldr r3, [pc, r3] */
/* @0x1c950c ldr r3, [r3] */
/* @0x1c9510 ldr r3, [r3, #0x80] */
/* @0x1c9514 cmp r3, #0 */
/* @0x1c9518 beq 0x1c9578 <_Z24Command_InstanceFurthestffi+0x164> */
/* @0x1c951c vmov.f32 s11, #-1.000000e+00 */
/* @0x1c9520 mov r0, #0 */
/* @0x1c9524 ldrb r1, [r3, #0x68] */
/* @0x1c9528 ldr r2, [r3, #0x178] */
/* @0x1c952c cmp r1, #0 */
/* @0x1c9530 bne 0x1c9568 <_Z24Command_InstanceFurthestffi+0x154> */
/* @0x1c9534 ldrb r1, [r3, #0x69] */
/* @0x1c9538 cmp r1, #0 */
/* @0x1c953c bne 0x1c9568 <_Z24Command_InstanceFurthestffi+0x154> */
/* @0x1c9540 vldr s15, [r3, #184] */
/* @0x1c9544 vsub.f32 s15, s15, s12 */
/* @0x1c9548 vldr s14, [r3, #180] */
/* @0x1c954c vmul.f32 s15, s15, s15 */
/* @0x1c9550 vsub.f32 s14, s14, s13 */
/* @0x1c9554 vmla.f32 s15, s14, s14 */
/* @0x1c9558 vcmpe.f32 s11, s15 */
/* @0x1c955c vmrs APSR_nzcv, fpscr */
/* @0x1c9560 vmovmi.f32 s11, s15 */
/* @0x1c9564 movmi r0, r3 */
/* @0x1c9568 cmp r2, #0 */
/* @0x1c956c mov r3, r2 */
/* @0x1c9570 bne 0x1c9524 <_Z24Command_InstanceFurthestffi+0x110> */
/* @0x1c9574 bx lr */

/* ── 出口族（0x1c9578..0x1c9590）── */

/* @0x1c9578 mov r0, r3 */
/* @0x1c957c bx lr */
/* @0x1c9580 mov r0, #0 */
/* @0x1c9584 bx lr */
/* @0x1c9588 bx lr */
/* @0x1c958c eoreq r4, r2, r4, lsl #16 */
/* @0x1c9590 eoreq r4, r2, r0, lsr #8 */

/* ══ §2 运动原语（0x1c9594..0x1c983c，3 个函数）══════════════════════════════════════
 * 三个函数都不做碰撞，只改 CInstance 的位置/速度字段；字段名沿用 CInstance_Setters 卡：
 *   +0xb4 x、+0xb8 y（0x193e7c SetPosition 的全部写集）、+0xe0 hspeed、+0xe4 vspeed。
 */

/* ── 2.1 Command_Snap(inst, hsnap, vsnap)  0x1c9594..0x1c961c ──
 * 语义: x = hsnap > 0 ? lrint(x / hsnap) * hsnap : x；y 同理（用 vsnap）。两个轴独立。
 * 闸: 0x1c95ac vcmpe s18,#0 + 0x1c95b8 ble ⇒ hsnap<=0（含 0 与负数）时该轴原样保留；
 *     这是因为 lrint(±inf) 会崩，源码用 <=0 把它挡掉。
 * 取整: 0x1c95c4 vcvt.f64.f32 → lrint(double) 0xb66e8 → vcvt.f32.s32 回 float，
 *      ⇒ 是「就近取整（当前舍入模式）」而不是 floor/trunc。
 * 写: 只走 0x1c9618 尾调 CInstance::SetPosition(x,y)，本函数不直接写任何字段。
 */


/* ── 入口：三个实参进 s18/s16，读 inst 的 x/y（0x1c9594..0x1c95b4）── */

/* @0x1c9594 push {r4, lr} */
/* @0x1c9598 vpush {d8, d9} */
/* @0x1c959c vmov s18, r1 */
/* @0x1c95a0 vldr s17, [r0, #180] */
/* @0x1c95a4 mov r4, r0 */
/* @0x1c95a8 vmov s16, r2 */
/* @0x1c95ac vcmpe.f32 s18, #0 */
/* @0x1c95b0 vldr s19, [r0, #184] */
/* @0x1c95b4 vmrs APSR_nzcv, fpscr */

/* ── x 轴（0x1c95bc..0x1c95d4）── */

/* @0x1c95b8 ble 0x1c95d8 <_Z12Command_SnapP9CInstanceff+0x44> */
/* @0x1c95bc vdiv.f32 s17, s17, s18 */
/* @0x1c95c0 vcvt.f64.f32 d6, s17 */
/* @0x1c95c4 vmov r0, r1, d6 */
/* @0x1c95c8 bl 0xb66e8 <lrint@plt> */
/* @0x1c95cc vmov s13, r0 */
/* @0x1c95d0 vcvt.f32.s32 s17, s13 */
/* @0x1c95d4 vmul.f32 s17, s17, s18 */

/* ── y 轴（0x1c95d8..0x1c9600）── */

/* @0x1c95d8 vcmpe.f32 s16, #0 */
/* @0x1c95dc vmrs APSR_nzcv, fpscr */
/* @0x1c95e0 ble 0x1c9604 <_Z12Command_SnapP9CInstanceff+0x70> */
/* @0x1c95e4 vldr s15, [r4, #184] */
/* @0x1c95e8 vdiv.f32 s15, s15, s16 */
/* @0x1c95ec vcvt.f64.f32 d6, s15 */
/* @0x1c95f0 vmov r0, r1, d6 */
/* @0x1c95f4 bl 0xb66e8 <lrint@plt> */
/* @0x1c95f8 vmov s13, r0 */
/* @0x1c95fc vcvt.f32.s32 s19, s13 */
/* @0x1c9600 vmul.f32 s19, s19, s16 */

/* ── 尾调 SetPosition（0x1c9604..0x1c9618）── */

/* @0x1c9604 vmov r1, s17 */
/* @0x1c9608 mov r0, r4 */
/* @0x1c960c vmov r2, s19 */
/* @0x1c9610 vpop {d8, d9} */
/* @0x1c9614 pop {r4, lr} */
/* @0x1c9618 b 0x193e7c <_ZN9CInstance11SetPositionEff> */

/* ── 2.2 Command_Wrap(inst, wrapx, wrapy)  0x1c961c..0x1c97ec ──
 * 语义: 出界就绕回房间的另一侧，绕回量 = 房间尺寸 + 精灵有效尺寸（宽×xscale / 高×yscale）。
 *   ① 0x1c9638/0x1c963c 先把 GOT 基址装进 r5（0x3f1c58），之后用 0xffffbcd8 取槽。
 *   ② s17/s16 的来源：Sprite_Exists(inst+0x8c) 为真时
 *        s17 = Sprite_Data(0x1ef03c)->[+0x1c] * inst+0x98（0x1c9714 vcvt.f32.s32 + 0x1c9720 vmul）
 *        s16 = Sprite_Data->[+0x20] * inst+0x9c（0x1c972c/0x1c9734）
 *      为假时 s17=s16=0（0x1c9648 vldr s16,[pc] 的两个 0.0f）。
 *      ⇒ 精灵没加载时退化成「只按房间尺寸绕」。
 *   ③ x 轴（wrapx 为真才做）：
 *        hspeed(inst+0xe0) > 0 且 x >= 房宽(room+0x10)  → SetPosition(x - 房宽 - s17, y)（0x1c973c..0x1c9754）
 *        hspeed < 0 且 x < 0                            → SetPosition(x + 房宽 + s17, y)（0x1c97ac..0x1c97dc）
 *   ④ y 轴（wrapy 为真才做）镜像：vspeed(+0xe4) > 0 且 y >= 房高(room+0x14) → y - 房高 - s16；
 *      vspeed < 0 且 y < 0 → y + 房高 + s16（0x1c96e0..0x1c96fc / 0x1c9768..0x1c9798）。
 *   ★ 房宽/房高是 int（0x1c9688 / 0x1c96d0 的 vcvt.f32.s32），不是 float。
 *   ★ 速度符号决定了「往哪边绕」，不是位移方向 —— 0 速度时两个分支都不走。
 */


/* ── 入口：GOT 基址、精灵尺寸（0x1c961c..0x1c9644）── */

/* @0x1c961c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9620 vpush {d8} */
/* @0x1c9624 mov r4, r0 */
/* @0x1c9628 ldr r0, [r0, #0x8c] */
/* @0x1c962c mov r7, r1 */
/* @0x1c9630 mov r6, r2 */
/* @0x1c9634 bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1c9638 ldr r5, [pc, #0x1a4] */
/* @0x1c963c add r5, pc, r5 */
/* @0x1c9640 cmp r0, #0 */
/* @0x1c9644 bne 0x1c9708 <_Z12Command_WrapP9CInstancebb+0xec> */

/* ── 精灵缺失时的 0 尺寸 + x 轴闸（0x1c9648..0x1c9694）── */

/* @0x1c9648 vldr s16, [pc, #400] */
/* @0x1c964c vmov.f32 s17, s16 */
/* @0x1c9650 cmp r7, #0 */
/* @0x1c9654 beq 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */
/* @0x1c9658 vldr s15, [r4, #224] */
/* @0x1c965c vcmpe.f32 s15, #0 */
/* @0x1c9660 vmrs APSR_nzcv, fpscr */
/* @0x1c9664 bmi 0x1c979c <_Z12Command_WrapP9CInstancebb+0x180> */
/* @0x1c9668 vcmpe.f32 s15, #0 */
/* @0x1c966c vmrs APSR_nzcv, fpscr */
/* @0x1c9670 ble 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */
/* @0x1c9674 ldr r3, [pc, #0x16c] */
/* @0x1c9678 vldr s14, [r4, #180] */
/* @0x1c967c ldr r3, [r5, r3] */
/* @0x1c9680 ldr r3, [r3] */
/* @0x1c9684 vldr s15, [r3, #16] */
/* @0x1c9688 vcvt.f32.s32 s15, s15 */
/* @0x1c968c vcmpe.f32 s14, s15 */
/* @0x1c9690 vmrs APSR_nzcv, fpscr */
/* @0x1c9694 bge 0x1c973c <_Z12Command_WrapP9CInstancebb+0x120> */

/* ── y 轴闸（0x1c9698..0x1c96dc）── */

/* @0x1c9698 cmp r6, #0 */
/* @0x1c969c beq 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */
/* @0x1c96a0 vldr s15, [r4, #228] */
/* @0x1c96a4 vcmpe.f32 s15, #0 */
/* @0x1c96a8 vmrs APSR_nzcv, fpscr */
/* @0x1c96ac bmi 0x1c9758 <_Z12Command_WrapP9CInstancebb+0x13c> */
/* @0x1c96b0 vcmpe.f32 s15, #0 */
/* @0x1c96b4 vmrs APSR_nzcv, fpscr */
/* @0x1c96b8 ble 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */
/* @0x1c96bc ldr r3, [pc, #0x124] */
/* @0x1c96c0 vldr s14, [r4, #184] */
/* @0x1c96c4 ldr r3, [r5, r3] */
/* @0x1c96c8 ldr r3, [r3] */
/* @0x1c96cc vldr s15, [r3, #20] */
/* @0x1c96d0 vcvt.f32.s32 s15, s15 */
/* @0x1c96d4 vcmpe.f32 s14, s15 */
/* @0x1c96d8 vmrs APSR_nzcv, fpscr */
/* @0x1c96dc blt 0x1c9700 <_Z12Command_WrapP9CInstancebb+0xe4> */

/* ── y 正向绕回（0x1c96e0..0x1c96fc）── */

/* @0x1c96e0 vsub.f32 s15, s14, s15 */
/* @0x1c96e4 mov r0, r4 */
/* @0x1c96e8 ldr r1, [r4, #0xb4] */
/* @0x1c96ec vsub.f32 s15, s15, s16 */
/* @0x1c96f0 vpop {d8} */
/* @0x1c96f4 pop {r3, r4, r5, r6, r7, lr} */
/* @0x1c96f8 vmov r2, s15 */
/* @0x1c96fc b 0x193e7c <_ZN9CInstance11SetPositionEff> */

/* ── 什么都不做时从这里出（0x1c9700..0x1c9704）── */

/* @0x1c9700 vpop {d8} */
/* @0x1c9704 pop {r3, r4, r5, r6, r7, pc} */

/* ── 精灵存在：有效尺寸 = 精灵尺寸 × 缩放（0x1c9708..0x1c9738）── */

/* @0x1c9708 ldr r0, [r4, #0x8c] */
/* @0x1c970c bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1c9710 vldr s15, [r4, #152] */
/* @0x1c9714 vldr s17, [r0, #28] */
/* @0x1c9718 vcvt.f32.s32 s17, s17 */
/* @0x1c971c ldr r0, [r4, #0x8c] */
/* @0x1c9720 vmul.f32 s17, s17, s15 */
/* @0x1c9724 bl 0x1ef03c <_Z11Sprite_Datai> */
/* @0x1c9728 vldr s15, [r4, #156] */
/* @0x1c972c vldr s16, [r0, #32] */
/* @0x1c9730 vcvt.f32.s32 s16, s16 */
/* @0x1c9734 vmul.f32 s16, s16, s15 */
/* @0x1c9738 b 0x1c9650 <_Z12Command_WrapP9CInstancebb+0x34> */

/* ── x 正向绕回（0x1c973c..0x1c9754）── */

/* @0x1c973c vsub.f32 s15, s14, s15 */
/* @0x1c9740 mov r0, r4 */
/* @0x1c9744 ldr r2, [r4, #0xb8] */
/* @0x1c9748 vsub.f32 s15, s15, s17 */
/* @0x1c974c vmov r1, s15 */
/* @0x1c9750 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c9754 b 0x1c9698 <_Z12Command_WrapP9CInstancebb+0x7c> */

/* ── y 负向绕回（0x1c9758..0x1c9798）── */

/* @0x1c9758 vldr s14, [r4, #184] */
/* @0x1c975c vcmpe.f32 s14, #0 */
/* @0x1c9760 vmrs APSR_nzcv, fpscr */
/* @0x1c9764 bpl 0x1c96b0 <_Z12Command_WrapP9CInstancebb+0x94> */
/* @0x1c9768 ldr r3, [pc, #0x78] */
/* @0x1c976c mov r0, r4 */
/* @0x1c9770 ldr r1, [r4, #0xb4] */
/* @0x1c9774 ldr r3, [r5, r3] */
/* @0x1c9778 ldr r3, [r3] */
/* @0x1c977c vldr s15, [r3, #20] */
/* @0x1c9780 vcvt.f32.s32 s15, s15 */
/* @0x1c9784 vadd.f32 s14, s14, s15 */
/* @0x1c9788 vadd.f32 s14, s14, s16 */
/* @0x1c978c vmov r2, s14 */
/* @0x1c9790 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c9794 vldr s15, [r4, #228] */
/* @0x1c9798 b 0x1c96b0 <_Z12Command_WrapP9CInstancebb+0x94> */

/* ── x 负向绕回（0x1c979c..0x1c97dc）── */

/* @0x1c979c vldr s14, [r4, #180] */
/* @0x1c97a0 vcmpe.f32 s14, #0 */
/* @0x1c97a4 vmrs APSR_nzcv, fpscr */
/* @0x1c97a8 bpl 0x1c9668 <_Z12Command_WrapP9CInstancebb+0x4c> */
/* @0x1c97ac ldr r3, [pc, #0x34] */
/* @0x1c97b0 mov r0, r4 */
/* @0x1c97b4 ldr r2, [r4, #0xb8] */
/* @0x1c97b8 ldr r3, [r5, r3] */
/* @0x1c97bc ldr r3, [r3] */
/* @0x1c97c0 vldr s15, [r3, #16] */
/* @0x1c97c4 vcvt.f32.s32 s15, s15 */
/* @0x1c97c8 vadd.f32 s14, s14, s15 */
/* @0x1c97cc vadd.f32 s14, s14, s17 */
/* @0x1c97d0 vmov r1, s14 */
/* @0x1c97d4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1c97d8 vldr s15, [r4, #224] */
/* @0x1c97dc b 0x1c9668 <_Z12Command_WrapP9CInstancebb+0x4c> */

/* ── 三个常量：0.0f / GOT 偏移 / -0x4328（0x1c97e0..0x1c97e8）── */

/* @0x1c97e0 andeq r0, r0, r0 */
/* @0x1c97e4 eoreq r8, r2, r4, lsl r6 */
/* @0x1c97e8 .word 0xffffbcd8 */

/* ── 2.3 Command_MoveTowards(inst, x, y, speed)  0x1c97ec..0x1c983c ──
 * 语义只有三条写：hspeed = x - inst.x、vspeed = y - inst.y、speed = 第 4 参。
 *   ★ 前两条是「指向目标的位移矢量」而不是单位化方向 ⇒ 初速随距离放大；随后 SetSpeed 用
 *     第 4 参整体覆盖幅值（SetSpeed 0x1930d4 内部重算 hspeed/vspeed，CInstance_Setters 卡 §3）。
 *   ★ SetHspeed/SetVspeed 的入参是 float（r1 = vmov 出来的标量），不是双精度。
 *   ★ 本函数不读 +0xb4/+0xb8 之外任何字段，也不做 clamp。
 */


/* ── 入口：先算 dx（0x1c97ec..0x1c9810）── */

/* @0x1c97ec vmov s14, r1 */
/* @0x1c97f0 vldr s15, [r0, #180] */
/* @0x1c97f4 push {r3, r4, r5, lr} */
/* @0x1c97f8 vpush {d8} */
/* @0x1c97fc vsub.f32 s14, s14, s15 */
/* @0x1c9800 vmov s16, r2 */
/* @0x1c9804 mov r4, r0 */
/* @0x1c9808 mov r5, r3 */
/* @0x1c980c vmov r1, s14 */
/* @0x1c9810 bl 0x1930f4 <_ZN9CInstance9SetHspeedEf> */

/* ── dy 与尾调 SetSpeed（0x1c9814..0x1c9838）── */

/* @0x1c9814 vldr s15, [r4, #184] */
/* @0x1c9818 vsub.f32 s15, s16, s15 */
/* @0x1c981c mov r0, r4 */
/* @0x1c9820 vmov r1, s15 */
/* @0x1c9824 bl 0x193114 <_ZN9CInstance9SetVspeedEf> */
/* @0x1c9828 vpop {d8} */
/* @0x1c982c mov r0, r4 */
/* @0x1c9830 mov r1, r5 */
/* @0x1c9834 pop {r3, r4, r5, lr} */
/* @0x1c9838 b 0x1930d4 <_ZN9CInstance8SetSpeedEf> */

/* ══ §3 生成实例（0x1c983c..0x1c9b54，4 个函数）══════════════════════════════════════
 * 四个函数是同一段流水线的四份实例化，尾部三步完全一样：
 *   ① 造实例（CRoom::AddInstance 的三个重载之一）→ ② Perform_Event(inst,inst,14,0)=PreCreate
 *   → ③ Perform_Event(inst,inst,0,0)=Create → ④ inst+0x6c = 1 → 返回 inst。
 *   ②③ 的实参顺序是 (self=inst, other=inst, num=14|0, sub=0)，与 Command_Change 卡看到的
 *   同一组事件号（14 在 0 之前 = PreCreate 在 Create 之前）互证。
 *   ★ 差别只有两处：拿房间对象的方式，和「用哪个 AddInstance 重载」。
 *     Create        cur = *(0x54298c)  → AddInstance(x,y,obj)          0x1ab144
 *     Create_Depth  cur = *(0x54298c)  → AddInstance(x,y,depth,obj)    0x1ab2e4（obj 走栈）
 *     Create_Layer  cur → GetLayerFromID(cur,id) → AddInstance(x,y,layer,obj) 0x1ab494
 *     Create_Layer  cur → GetLayerFromName(cur,name) → 同一个 0x1ab494
 *   ★ 四个函数的失败口径都不一样，重建时必须分开写：
 *     Create/Create_Depth  「对象不存在」→ Error_Show_Action("Creating instance for non-existing
 *        object: "+obj, 0)，返回 0；
 *     Create_Layer(id)     「层不存在」→ 走 vtable 派发器（0x3eb70c→0x47a118→[vt+0xc]）打
 *        "Specified layer does not exist"（无实参、无格式串），返回 0；
 *     Create_Layer(name)   「层不存在」→ YYError(0xd547c) 打
 *        "instance_create_layer :: specified layer \"%s\" does not exist"，把**名字**当 %s。
 *     ⇒ 同一族里"非致命错误"与"致命错误"混用，是这个 build 的真实行为，不要统一。
 */

/* ── 3.1 Command_Create(int obj, float x, float y)  0x1c983c..0x1c98d4 ──
 * 实参: r4=obj、r6=x、r5=y（注意顺序：obj 在 r0，与 GML instance_create(x,y,obj) 相反）。
 * 返回: CInstance*（失败 0）。调用者 F_InstanceCreate 1095dc / YYGML_instance_create 10b0b0
 *       拿到后一律读 +0x78（实例 id）当 GML 返回值，失败时给 -1.0。
 */


/* ── 入口与 Object_Exists 闸（0x1c983c..0x1c9854）── */

/* @0x1c983c push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9840 mov r6, r1 */
/* @0x1c9844 mov r4, r0 */
/* @0x1c9848 mov r5, r2 */
/* @0x1c984c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9850 subs r7, r0, #0 */
/* @0x1c9854 beq 0x1c98ac <_Z14Command_Createiff+0x70> */

/* ── 造实例 + PreCreate(14) + Create(0) + +0x6c=1（0x1c9858..0x1c98a8）── */

/* @0x1c9858 ldr r12, [pc, #0x6c] */
/* @0x1c985c mov r3, r4 */
/* @0x1c9860 mov r1, r6 */
/* @0x1c9864 mov r2, r5 */
/* @0x1c9868 ldr r12, [pc, r12] */
/* @0x1c986c ldr r0, [r12] */
/* @0x1c9870 bl 0x1ab144 <_ZN5CRoom11AddInstanceEffi> */
/* @0x1c9874 mov r2, #14 */
/* @0x1c9878 mov r3, #0 */
/* @0x1c987c mov r1, r0 */
/* @0x1c9880 mov r4, r0 */
/* @0x1c9884 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9888 mov r2, #0 */
/* @0x1c988c mov r0, r4 */
/* @0x1c9890 mov r3, r2 */
/* @0x1c9894 mov r1, r4 */
/* @0x1c9898 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c989c mov r3, #1 */
/* @0x1c98a0 mov r0, r4 */
/* @0x1c98a4 strb r3, [r4, #0x6c] */
/* @0x1c98a8 pop {r3, r4, r5, r6, r7, pc} */

/* ── 错误出口："Creating instance for non-existing object: "（0x1c98ac..0x1c98d0）── */

/* @0x1c98ac ldr r0, [pc, #0x1c] */
/* @0x1c98b0 mov r1, r4 */
/* @0x1c98b4 add r0, pc, r0 */
/* @0x1c98b8 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c98bc mov r1, r7 */
/* @0x1c98c0 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c98c4 mov r0, r7 */
/* @0x1c98c8 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c98cc eoreq r4, r2, r0, asr #1 */
/* @0x1c98d0 ldrsbeq r7, [r8], -r0 */

/* ── 3.2 Command_Create_Depth(int obj, float x, float y, int depth)  0x1c98d4..0x1c9980 ──
 * 实参: r4=obj、r6=x、r5=y、r7=depth。
 * 关键在 0x1c98fc..0x1c9914：r3 = depth（r7）、`str r4,[sp]` = obj 压栈，然后 bl 0x1ab2e4
 *   ⇒ 调的是 AddInstance(float x, float y, int depth, int objindex)，第 3 个 int 是 depth、
 *     第 4 个才是对象索引 —— 与 CRoom_AddInstance 卡「3 参版第 3 参是 objindex、4 参版第 3 参
 *     是 depth」的坑完全对齐（那张卡还预言了本函数的摆参方式，此处实测吻合）。
 * 其余（闸、事件、+0x6c、返回值）与 3.1 逐条相同。
 */


/* ── 入口与 Object_Exists（0x1c98d4..0x1c98f4）── */

/* @0x1c98d4 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c98d8 sub sp, sp, #8 */
/* @0x1c98dc mov r6, r1 */
/* @0x1c98e0 mov r7, r3 */
/* @0x1c98e4 mov r5, r2 */
/* @0x1c98e8 mov r4, r0 */
/* @0x1c98ec bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c98f0 subs r8, r0, #0 */
/* @0x1c98f4 beq 0x1c9954 <_Z20Command_Create_Depthiffi+0x80> */

/* ── AddInstance(x,y,depth,obj)：depth=r3、obj=[sp]（0x1c98f8..0x1c9914）── */

/* @0x1c98f8 ldr r12, [pc, #0x78] */
/* @0x1c98fc mov r3, r7 */
/* @0x1c9900 mov r1, r6 */
/* @0x1c9904 mov r2, r5 */
/* @0x1c9908 ldr r12, [pc, r12] */
/* @0x1c990c ldr r0, [r12] */
/* @0x1c9910 str r4, [sp] */
/* @0x1c9914 bl 0x1ab2e4 <_ZN5CRoom11AddInstanceEffii> */

/* ── 事件 14 → 0，然后 +0x6c=1（0x1c9918..0x1c9950）── */

/* @0x1c9918 mov r2, #14 */
/* @0x1c991c mov r3, #0 */
/* @0x1c9920 mov r1, r0 */
/* @0x1c9924 mov r4, r0 */
/* @0x1c9928 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c992c mov r2, #0 */
/* @0x1c9930 mov r0, r4 */
/* @0x1c9934 mov r3, r2 */
/* @0x1c9938 mov r1, r4 */
/* @0x1c993c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9940 mov r0, r4 */
/* @0x1c9944 mov r3, #1 */
/* @0x1c9948 strb r3, [r4, #0x6c] */
/* @0x1c994c add sp, sp, #8 */
/* @0x1c9950 pop {r4, r5, r6, r7, r8, pc} */

/* ── 错误出口（0x1c9954..0x1c997c）── */

/* @0x1c9954 ldr r0, [pc, #0x20] */
/* @0x1c9958 mov r1, r4 */
/* @0x1c995c add r0, pc, r0 */
/* @0x1c9960 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9964 mov r1, r8 */
/* @0x1c9968 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c996c mov r0, r8 */
/* @0x1c9970 add sp, sp, #8 */
/* @0x1c9974 pop {r4, r5, r6, r7, r8, pc} */
/* @0x1c9978 eoreq r4, r2, r0, lsr #32 */
/* @0x1c997c andseq r7, r8, r8, lsr #4 */

/* ── 3.3 Command_Create_Layer(int obj, float x, float y, int layerid)  0x1c9980..0x1c9a74 ──
 * 实参: r5=obj、r8=x、r7=y、r6=layerid。
 * 层查找: CLayerManager::GetLayerFromID(cur, layerid) 0x1b8868（0x1c99b4）—— 是「按 id」。
 * 造实例: AddInstance(cur, x, y, layer, obj) 0x1ab494（obj 走栈：0x1c99cc str r5,[sp]）。
 *        该重载内部把 depth 抄自 layer+0x04（见 CRoom_AddInstance 卡）。
 * 层不存在: 0x1c9a34..0x1c9a54 —— 取出 0x3eb70c 指向的对象，再解引用 [0x47a118] 拿 vtable，
 *        调 [vt+0xc](r0=对象, r1="Specified layer does not exist")，然后把 r3（=0）当返回值。
 *        ★ 这条路径没有格式串、也没有 %s，与 3.4 的 YYError 不是同一个出口。
 */


/* ── 入口与 Object_Exists（0x1c9980..0x1c999c）── */

/* @0x1c9980 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9984 sub sp, sp, #16 */
/* @0x1c9988 mov r8, r1 */
/* @0x1c998c mov r6, r3 */
/* @0x1c9990 mov r7, r2 */
/* @0x1c9994 mov r5, r0 */
/* @0x1c9998 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c999c subs r4, r0, #0 */
/* @0x1c99a0 beq 0x1c9a10 <_Z20Command_Create_Layeriffi+0x90> */

/* ── GetLayerFromID + AddInstance(x,y,layer,obj)（0x1c99a4..0x1c99d0）── */

/* @0x1c99a4 ldr r4, [pc, #0xb8] */
/* @0x1c99a8 mov r1, r6 */
/* @0x1c99ac ldr r4, [pc, r4] */
/* @0x1c99b0 ldr r0, [r4] */
/* @0x1c99b4 bl 0x1b8868 <_ZN13CLayerManager14GetLayerFromIDEP5CRoomi> */
/* @0x1c99b8 subs r3, r0, #0 */
/* @0x1c99bc beq 0x1c9a34 <_Z20Command_Create_Layeriffi+0xb4> */
/* @0x1c99c0 ldr r0, [r4] */
/* @0x1c99c4 mov r1, r8 */
/* @0x1c99c8 mov r2, r7 */
/* @0x1c99cc str r5, [sp] */
/* @0x1c99d0 bl 0x1ab494 <_ZN5CRoom11AddInstanceEffP6CLayeri> */

/* ── 事件 14 → 0 → +0x6c=1（0x1c99d4..0x1c9a0c）── */

/* @0x1c99d4 mov r2, #14 */
/* @0x1c99d8 mov r3, #0 */
/* @0x1c99dc mov r1, r0 */
/* @0x1c99e0 mov r4, r0 */
/* @0x1c99e4 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c99e8 mov r2, #0 */
/* @0x1c99ec mov r0, r4 */
/* @0x1c99f0 mov r3, r2 */
/* @0x1c99f4 mov r1, r4 */
/* @0x1c99f8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c99fc mov r0, r4 */
/* @0x1c9a00 mov r3, #1 */
/* @0x1c9a04 strb r3, [r4, #0x6c] */
/* @0x1c9a08 add sp, sp, #16 */
/* @0x1c9a0c pop {r4, r5, r6, r7, r8, pc} */

/* ── 对象不存在出口（0x1c9a10..0x1c9a30）── */

/* @0x1c9a10 ldr r0, [pc, #0x50] */
/* @0x1c9a14 mov r1, r5 */
/* @0x1c9a18 add r0, pc, r0 */
/* @0x1c9a1c bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9a20 mov r1, r4 */
/* @0x1c9a24 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9a28 mov r0, r4 */
/* @0x1c9a2c add sp, sp, #16 */
/* @0x1c9a30 pop {r4, r5, r6, r7, r8, pc} */

/* ── 层不存在出口：vtable 派发器（0x1c9a34..0x1c9a60）── */

/* @0x1c9a34 ldr r2, [pc, #0x30] */
/* @0x1c9a38 ldr r1, [pc, #0x30] */
/* @0x1c9a3c ldr r2, [pc, r2] */
/* @0x1c9a40 add r1, pc, r1 */
/* @0x1c9a44 ldr r0, [r2] */
/* @0x1c9a48 ldr r2, [r0] */
/* @0x1c9a4c ldr r2, [r2, #0xc] */
/* @0x1c9a50 str r3, [sp, #0xc] */
/* @0x1c9a54 blx r2 */
/* @0x1c9a58 ldr r3, [sp, #0xc] */
/* @0x1c9a5c mov r0, r3 */
/* @0x1c9a60 b 0x1c9a08 <_Z20Command_Create_Layeriffi+0x88> */

/* ── 三个池字（0x1c9a64 / 0x1c9a68 / 0x1c9a6c / 0x1c9a70）── */

/* @0x1c9a64 eoreq r3, r2, r12, ror pc */
/* @0x1c9a68 andseq r7, r8, r12, ror #2 */
/* @0x1c9a6c .word 0x00223cd8 */
/* @0x1c9a70 andseq r7, r8, r0, ror r1 */

/* ── 3.4 Command_Create_Layer(int obj, float x, float y, char const* layer)  0x1c9a74..0x1c9b54 ──
 * 与 3.3 只差层查找函数和错误出口：
 *   GetLayerFromName(cur, name) 0x1b897c（0x1c9aa8）
 *   层不存在 → YYError(0xd547c, "instance_create_layer :: specified layer \"%s\" does not exist", name)
 *   （0x1c9b28..0x1c9b38；r1 = r6 = 层名字符串）
 * ★ 这两个同名重载在 dynsym 里是两个不同符号（...iffi 与 ...iffPKc），调用者靠实参类型分派
 *   —— F_InstanceCreateLayer 1096e4 内部就按字符串/整数分支各调一次（0x10.. 与 0xfc）。
 */


/* ── 入口与 Object_Exists（0x1c9a74..0x1c9a94）── */

/* @0x1c9a74 push {r4, r5, r6, r7, r8, lr} */
/* @0x1c9a78 sub sp, sp, #16 */
/* @0x1c9a7c mov r8, r1 */
/* @0x1c9a80 mov r6, r3 */
/* @0x1c9a84 mov r7, r2 */
/* @0x1c9a88 mov r5, r0 */
/* @0x1c9a8c bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9a90 subs r4, r0, #0 */
/* @0x1c9a94 beq 0x1c9b04 <_Z20Command_Create_LayeriffPKc+0x90> */

/* ── GetLayerFromName + AddInstance（0x1c9a98..0x1c9ac4）── */

/* @0x1c9a98 ldr r4, [pc, #0xa8] */
/* @0x1c9a9c mov r1, r6 */
/* @0x1c9aa0 ldr r4, [pc, r4] */
/* @0x1c9aa4 ldr r0, [r4] */
/* @0x1c9aa8 bl 0x1b897c <_ZN13CLayerManager16GetLayerFromNameEP5CRoomPKc> */
/* @0x1c9aac subs r3, r0, #0 */
/* @0x1c9ab0 beq 0x1c9b28 <_Z20Command_Create_LayeriffPKc+0xb4> */
/* @0x1c9ab4 ldr r0, [r4] */
/* @0x1c9ab8 mov r1, r8 */
/* @0x1c9abc mov r2, r7 */
/* @0x1c9ac0 str r5, [sp] */
/* @0x1c9ac4 bl 0x1ab494 <_ZN5CRoom11AddInstanceEffP6CLayeri> */

/* ── 事件 14 → 0 → +0x6c=1（0x1c9ac8..0x1c9b00）── */

/* @0x1c9ac8 mov r2, #14 */
/* @0x1c9acc mov r3, #0 */
/* @0x1c9ad0 mov r1, r0 */
/* @0x1c9ad4 mov r4, r0 */
/* @0x1c9ad8 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9adc mov r2, #0 */
/* @0x1c9ae0 mov r0, r4 */
/* @0x1c9ae4 mov r3, r2 */
/* @0x1c9ae8 mov r1, r4 */
/* @0x1c9aec bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */
/* @0x1c9af0 mov r0, r4 */
/* @0x1c9af4 mov r3, #1 */
/* @0x1c9af8 strb r3, [r4, #0x6c] */
/* @0x1c9afc add sp, sp, #16 */
/* @0x1c9b00 pop {r4, r5, r6, r7, r8, pc} */

/* ── 对象不存在出口（0x1c9b04..0x1c9b24）── */

/* @0x1c9b04 ldr r0, [pc, #0x40] */
/* @0x1c9b08 mov r1, r5 */
/* @0x1c9b0c add r0, pc, r0 */
/* @0x1c9b10 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9b14 mov r1, r4 */
/* @0x1c9b18 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9b1c mov r0, r4 */
/* @0x1c9b20 add sp, sp, #16 */
/* @0x1c9b24 pop {r4, r5, r6, r7, r8, pc} */

/* ── 层不存在出口：YYError + %s（0x1c9b28..0x1c9b44）── */

/* @0x1c9b28 ldr r0, [pc, #0x20] */
/* @0x1c9b2c mov r1, r6 */
/* @0x1c9b30 str r3, [sp, #0xc] */
/* @0x1c9b34 add r0, pc, r0 */
/* @0x1c9b38 bl 0xd547c <_Z7YYErrorPKcz> */
/* @0x1c9b3c ldr r3, [sp, #0xc] */
/* @0x1c9b40 mov r0, r3 */
/* @0x1c9b44 b 0x1c9afc <_Z20Command_Create_LayeriffPKc+0x88> */

/* ── 三个池字（0x1c9b48 / 0x1c9b4c / 0x1c9b50）── */

/* @0x1c9b48 eoreq r3, r2, r8, lsl #29 */
/* @0x1c9b4c andseq r7, r8, r8, ror r0 */
/* @0x1c9b50 mulseq r8, r12, r0 */

/* ══ §4 按坐标派发 + 精灵（0x1c9c88..0x1c9e08，4 个函数）════════════════════════════════
 * DestroyAt/ChangeAt 是「遍历当前房 + 点命中就转发给已出卡的单体版」，ObjectAt 是
 * InstancePosition 的布尔化，SetSprite 是一次带存在性检查的 SetSpriteIndex。
 */

/* ── 4.1 Command_DestroyAt(float x, float y)  0x1c9c88..0x1c9cf8 ──
 * 遍历当前房全链（CRoom+0x80 → +0x178），对每个实例 Collision_Point(inst,x,y,1)，
 * 命中就 Command_Destroy(inst) 0x1c9b54。
 * ★ 关键顺序：0x1c9ccc 在 bl 之前先 `ldr r5,[r4,#0x178]` 把 next 取出来，然后才判定/销毁
 *   —— 这样即使 Command_Destroy 改了链也能继续走（但它其实不摘链，见该卡）。
 * ★ 没有对象过滤、没有 solid/notme 形参：只要是点命中的实例就销毁。
 */


/* ── 入口与链头（0x1c9c88..0x1c9cb8）── */

/* @0x1c9c88 push {r3, r4, r5, r6, r7, lr} */
/* @0x1c9c8c mov r7, r0 */
/* @0x1c9c90 ldr r3, [pc, #0x5c] */
/* @0x1c9c94 mov r6, r1 */
/* @0x1c9c98 ldr r3, [pc, r3] */
/* @0x1c9c9c ldr r3, [r3] */
/* @0x1c9ca0 ldr r4, [r3, #0x80] */
/* @0x1c9ca4 cmp r4, #0 */
/* @0x1c9ca8 bne 0x1c9cbc <_Z17Command_DestroyAtff+0x34> */
/* @0x1c9cac pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9cb0 cmp r5, #0 */
/* @0x1c9cb4 mov r4, r5 */
/* @0x1c9cb8 beq 0x1c9cf0 <_Z17Command_DestroyAtff+0x68> */

/* ── 循环体：先取 next（0x1c9ccc），再判定、再 Destroy（0x1c9cbc..0x1c9cec）── */

/* @0x1c9cbc mov r0, r4 */
/* @0x1c9cc0 mov r1, r7 */
/* @0x1c9cc4 mov r2, r6 */
/* @0x1c9cc8 mov r3, #1 */
/* @0x1c9ccc ldr r5, [r4, #0x178] */
/* @0x1c9cd0 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9cd4 cmp r0, #0 */
/* @0x1c9cd8 beq 0x1c9cb0 <_Z17Command_DestroyAtff+0x28> */
/* @0x1c9cdc mov r0, r4 */
/* @0x1c9ce0 mov r4, r5 */
/* @0x1c9ce4 bl 0x1c9b54 <_Z15Command_DestroyP9CInstance> */
/* @0x1c9ce8 cmp r5, #0 */
/* @0x1c9cec bne 0x1c9cbc <_Z17Command_DestroyAtff+0x34> */
/* @0x1c9cf0 pop {r3, r4, r5, r6, r7, pc} */
/* @0x1c9cf4 mlaeq r2, r0, r12, r3 */

/* ── 4.2 Command_ChangeAt(float x, float y, int obj, bool perf)  0x1c9cf8..0x1c9da8 ──
 * 实参: r6=x、r7=y、r8=obj、r9=perf。
 * 闸: Object_Exists(obj) 0x19ecf8，失败组 "Asking to change into non-existing object: " +
 *     obj 交给 Error_Show_Action(str, 0)（第 2 实参恒 0）—— 与 Command_Change.c 卡用的是**同一个串**
 *     （0x350c18），本卡只给地址，不重复锚定那个函数的字节。
 * 主体: 全链遍历 + Collision_Point(inst,x,y,1) → Command_Change(inst, obj, perf) 0x1c9bb4。
 * ★ 同一处「先取 next 再调用」（0x1c9d54）。
 * ★ perf 原样透传，本函数不判断它 —— 是否派 Destroy/CleanUp/PreCreate/Create 由 Command_Change 定。
 */


/* ── 入口与 Object_Exists（0x1c9cf8..0x1c9d18）── */

/* @0x1c9cf8 push {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c9cfc mov r6, r0 */
/* @0x1c9d00 mov r0, r2 */
/* @0x1c9d04 mov r8, r2 */
/* @0x1c9d08 mov r7, r1 */
/* @0x1c9d0c mov r9, r3 */
/* @0x1c9d10 bl 0x19ecf8 <_Z13Object_Existsi> */
/* @0x1c9d14 subs r4, r0, #0 */
/* @0x1c9d18 beq 0x1c9d84 <_Z16Command_ChangeAtffib+0x8c> */

/* ── 循环体（0x1c9d1c..0x1c9d7c）── */

/* @0x1c9d1c ldr r3, [pc, #0x7c] */
/* @0x1c9d20 ldr r3, [pc, r3] */
/* @0x1c9d24 ldr r3, [r3] */
/* @0x1c9d28 ldr r4, [r3, #0x80] */
/* @0x1c9d2c cmp r4, #0 */
/* @0x1c9d30 bne 0x1c9d44 <_Z16Command_ChangeAtffib+0x4c> */
/* @0x1c9d34 pop {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x1c9d38 cmp r5, #0 */
/* @0x1c9d3c mov r4, r5 */
/* @0x1c9d40 beq 0x1c9d80 <_Z16Command_ChangeAtffib+0x88> */
/* @0x1c9d44 mov r0, r4 */
/* @0x1c9d48 mov r1, r6 */
/* @0x1c9d4c mov r2, r7 */
/* @0x1c9d50 mov r3, #1 */
/* @0x1c9d54 ldr r5, [r4, #0x178] */
/* @0x1c9d58 bl 0x1944b0 <_ZN9CInstance15Collision_PointEffb> */
/* @0x1c9d5c cmp r0, #0 */
/* @0x1c9d60 beq 0x1c9d38 <_Z16Command_ChangeAtffib+0x40> */
/* @0x1c9d64 mov r0, r4 */
/* @0x1c9d68 mov r1, r8 */
/* @0x1c9d6c mov r2, r9 */
/* @0x1c9d70 mov r4, r5 */
/* @0x1c9d74 bl 0x1c9bb4 <_Z14Command_ChangeP9CInstanceib> */
/* @0x1c9d78 cmp r5, #0 */
/* @0x1c9d7c bne 0x1c9d44 <_Z16Command_ChangeAtffib+0x4c> */
/* @0x1c9d80 pop {r3, r4, r5, r6, r7, r8, r9, pc} */

/* ── 错误出口（0x1c9d84..0x1c9da4）── */

/* @0x1c9d84 ldr r0, [pc, #0x18] */
/* @0x1c9d88 mov r1, r8 */
/* @0x1c9d8c add r0, pc, r0 */
/* @0x1c9d90 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9d94 mov r1, r4 */
/* @0x1c9d98 pop {r3, r4, r5, r6, r7, r8, r9, lr} */
/* @0x1c9d9c b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9da0 eoreq r3, r2, r8, lsl #24 */
/* @0x1c9da4 andseq r6, r8, r4, lsl #29 */

/* ── 4.3 Command_ObjectAt(float x, float y, int obj)  0x1c9da8..0x1c9dbc ──
 * 只有 5 条：push / bl InstancePosition / adds+movne / pop。即 `return InstancePosition(...) != 0`。
 * ★ 调用方只有三个内建：F_PositionEmpty 0x109a58+0x3c、F_PositionMeeting 0x10d77c+0xc4、
 *   YYGML_position_meeting 0x10d8f8+0x80（全是 bl）。
 */

/* @0x1c9da8 push {r3, lr} */
/* @0x1c9dac bl 0x1c90cc <_Z24Command_InstancePositionffi> */
/* @0x1c9db0 adds r0, r0, #0 */
/* @0x1c9db4 movne r0, #1 */
/* @0x1c9db8 pop {r3, pc} */

/* ── 4.4 Command_SetSprite(inst, sprite)  0x1c9dbc..0x1c9e08 ──
 * 闸: Sprite_Exists(sprite) 0x1eee98；失败组 "Setting instance to non-existing sprite: " + sprite
 *     交给 Error_Show_Action(str, 0)（第 2 实参 = exists 的残值 0），此时**不写** inst 的任何字段。
 * 成功: 尾调 CInstance::SetSpriteIndex(sprite) 0x1931c0（那一侧负责 +0x8c 与派生字段）。
 * ★ 本函数自己一条 str 都没有：既不改 +0x8c，也不改掩码/尺寸（都在 SetSpriteIndex 里）。
 */


/* ── 入口与 Sprite_Exists（0x1c9dbc..0x1c9dd4）── */

/* @0x1c9dbc push {r4, r5, r6, lr} */
/* @0x1c9dc0 mov r5, r0 */
/* @0x1c9dc4 mov r0, r1 */
/* @0x1c9dc8 mov r4, r1 */
/* @0x1c9dcc bl 0x1eee98 <_Z13Sprite_Existsi> */
/* @0x1c9dd0 subs r6, r0, #0 */
/* @0x1c9dd4 beq 0x1c9de8 <_Z17Command_SetSpriteP9CInstancei+0x2c> */

/* ── 成功：尾调 SetSpriteIndex（0x1c9dd8..0x1c9de4）── */

/* @0x1c9dd8 mov r0, r5 */
/* @0x1c9ddc mov r1, r4 */
/* @0x1c9de0 pop {r4, r5, r6, lr} */
/* @0x1c9de4 b 0x1931c0 <_ZN9CInstance14SetSpriteIndexEi> */

/* ── 失败：组串 + Error_Show_Action（0x1c9de8..0x1c9e04）── */

/* @0x1c9de8 ldr r0, [pc, #0x14] */
/* @0x1c9dec mov r1, r4 */
/* @0x1c9df0 add r0, pc, r0 */
/* @0x1c9df4 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9df8 mov r1, r6 */
/* @0x1c9dfc pop {r4, r5, r6, lr} */
/* @0x1c9e00 b 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9e04 andseq r6, r8, r12, asr #28 */

/* ══ §5 房间与游戏控制（0x1c9e08..0x1ca040 + 0x1cba58，7 个 + 1 个夹具）══════════════════
 * 这一族是全卡的重点：它们把「要做什么」写进两个全局信箱，真正的执行在帧循环里：
 *   0x542954 New_Room（换房信箱/中断码，int）
 *   0x542958 当前房间号（int）
 *   0x54298c Run_Room（CRoom*，唯一写者 Run_Room_Set 0x1cba58）
 *   0x542950 transition_kind（int）
 * 命令层只写信箱、不做房间切换；切换由 SingleStep/SwitchRoom/StartRoom 消费。
 * 消费侧的地址（不属本卡，只给地址）：
 *   SingleStep 0x1d4dd8：ProcessMessages → DoAStep → r0=*New_Room →
 *       -1  → 0x1d4e50（有 0x542910 才推进一帧）
 *       -200→ 0x1d4e78 Run_EndGame + GamePadRestart + StartGame + srand48(0x2012e4)
 *       -300→ 0x1d4e14 LoadGame() 0x1d1cb4
 *       -400 与 -100 → 0x1d4e3c 把 0x54297a 清 0 后返回（不换房）
 *       其余 → 0x1d4e30 SwitchRoom(*New_Room) 0x1d4450 → EndRoom(0)+StartRoom(room,0)
 *   StartRoom 0x1d38e0：0x1d3910 *New_Room = -1；0x1d3938 当前房号 = idx；
 *                       0x1d3944 Run_Room_Set(g_rooms[idx])；0x1d4244 第二次 Run_Room_Set
 *   LoadGame  0x1d1cb4：*New_Room = -1；IO_Clear()；Command_LoadGame(*(char**)0x54295c)
 *   ⇒ 命令层写的是「码」，帧循环按码分派；负数码是控制指令，>=0 才是房号。
 */

/* ── 5.1 Command_GotoRoom(int room, int transition_kind)  0x1c9e08..0x1c9e68 ──
 * 写集（按指令序）:
 *   0x1c9e20  *(int*)0x542954 = room          （GOT 槽 0x3eddac，实测指向 0x542954）
 *   0x1c9e24  *(int*)0x542950 = r2 = 0        （GOT 槽 0x3ee0b0 → 0x542950）
 *     ⇒ transition_kind 被**无条件清零**；第 2 形参 r1 全函数零引用（死参）：
 *       0x1c9e0c mov r2,#0 之后就再没有一条指令读 r1。调用者确实都按
 *       「r1 = transition_kind」摆（F_RoomGoto 0x109ad0 从 0x542950 读、SV_Room 0x1fa7e8 同），
 *       但本 build 里这份实参被丢掉。
 * 校验: Room_Exists(room) 0x1b52f8（0x1c9e28）。
 *   真 → 直接 pop 返回（0x1c9e30 popne）。
 *   假 → 0x1c9e34 取串池字 → 0x1c9e3c add pc → 0x350c70 "Unexisting room number: "，
 *        r1 = *(int*)0x542954（刚写入的 room）交给拼接器 0x1c8380，再
 *        Error_Show_Action(str, 0) 0xecf70（注意第 2 实参是 0，不是 1）；
 *        最后 0x1c9e54 把 -400（0xfffffe70）写回 0x542954。
 *   ⇒ 失败时信箱里留的是 -400，正好落到 SingleStep 的「忽略」分支。
 * ★ 本函数没有任何一条指令碰 0x542958 或 0x54298c：它只排队，不切换。
 */


/* ── 入口：两个全局的 GOT 槽（0x1c9e08..0x1c9e24）── */

/* @0x1c9e08 push {r4, lr} */
/* @0x1c9e0c mov r2, #0 */
/* @0x1c9e10 ldr r4, [pc, #0x44] */
/* @0x1c9e14 ldr r3, [pc, #0x44] */
/* @0x1c9e18 ldr r4, [pc, r4] */
/* @0x1c9e1c ldr r3, [pc, r3] */
/* @0x1c9e20 str r0, [r4] */
/* @0x1c9e24 str r2, [r3] */

/* ── Room_Exists 闸（0x1c9e28..0x1c9e30）── */

/* @0x1c9e28 bl 0x1b52f8 <_Z11Room_Existsi> */
/* @0x1c9e2c cmp r0, #0 */
/* @0x1c9e30 popne {r4, pc} */

/* ── 失败：组串 + Error_Show_Action + 写 -400（0x1c9e34..0x1c9e58）── */

/* @0x1c9e34 ldr r0, [pc, #0x28] */
/* @0x1c9e38 ldr r1, [r4] */
/* @0x1c9e3c add r0, pc, r0 */
/* @0x1c9e40 bl 0x1c8380 <_ZN13CLayerManager16DeSerializeLayerEP5CRoomP7IBuffer+0xeb0> */
/* @0x1c9e44 mov r1, #1 */
/* @0x1c9e48 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9e4c movw r3, #0xfe70 */
/* @0x1c9e50 movt r3, #0xffff */
/* @0x1c9e54 str r3, [r4] */
/* @0x1c9e58 pop {r4, pc} */

/* ── 三个池字：0x223f8c→槽0x3eddac、0x22428c→槽0x3ee0b0、0x186e2c→串 0x350c70 ── */

/* @0x1c9e5c eoreq r3, r2, r12, lsl #31 */
/* @0x1c9e60 eoreq r4, r2, r12, lsl #5 */
/* @0x1c9e64 andseq r6, r8, r12, lsr #28 */

/* ── 5.2 Command_PreviousRoom(int transition_kind)  0x1c9e68..0x1c9ed0 ──
 * 流程: cur = *(int*)0x542958（0x1c9e7c）→ Room_First() 0x1b5d08 →
 *       cur == first ? 报错 : Room_Previous(cur) 0x1b5d40 → GotoRoom(prev, 本函数参数)。
 * 报错: 0x350c8c "Moving to previous room before the first room."，
 *       **Error_Show_Action(str, 1)**（第 2 实参是 1，与 5.1 的 0 相反），
 *       然后 0x1c9ebc 把 -400 写进 0x542954。
 * 尾调: 0x1c9e94 pop / 0x1c9e98 b GotoRoom，r1 = r4 = 本函数参数 ⇒ 参数被原样转手
 *       （虽然 GotoRoom 不读它）。
 * ★ 边界口径是「当前房号 == Room_First()」，不是 `<=`：房间号不连续时也不会误判。
 */


/* ── 入口：cur = *(0x542958)（0x1c9e68..0x1c9e84）── */

/* @0x1c9e68 push {r4, lr} */
/* @0x1c9e6c mov r4, r0 */
/* @0x1c9e70 bl 0x1b5d08 <_Z10Room_Firstv> */
/* @0x1c9e74 ldr r3, [pc, #0x48] */
/* @0x1c9e78 ldr r3, [pc, r3] */
/* @0x1c9e7c ldr r3, [r3] */
/* @0x1c9e80 cmp r0, r3 */
/* @0x1c9e84 beq 0x1c9e9c <_Z20Command_PreviousRoomi+0x34> */

/* ── 非边界：Room_Previous → 尾调 GotoRoom（0x1c9e88..0x1c9e98）── */

/* @0x1c9e88 mov r0, r3 */
/* @0x1c9e8c bl 0x1b5d40 <_Z13Room_Previousi> */
/* @0x1c9e90 mov r1, r4 */
/* @0x1c9e94 pop {r4, lr} */
/* @0x1c9e98 b 0x1c9e08 <_Z16Command_GotoRoomii> */

/* ── 边界：报错 + 写 -400（0x1c9e9c..0x1c9ec0）── */

/* @0x1c9e9c ldr r0, [pc, #0x24] */
/* @0x1c9ea0 mov r1, #1 */
/* @0x1c9ea4 add r0, pc, r0 */
/* @0x1c9ea8 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9eac ldr r3, [pc, #0x18] */
/* @0x1c9eb0 movw r2, #0xfe70 */
/* @0x1c9eb4 movt r2, #0xffff */
/* @0x1c9eb8 ldr r3, [pc, r3] */
/* @0x1c9ebc str r2, [r3] */
/* @0x1c9ec0 pop {r4, pc} */

/* ── 三个池字：0x22555c→槽0x3ef3dc、0x186de0→串 0x350c8c、0x223eec→槽0x3eddac ── */

/* @0x1c9ec4 eoreq r5, r2, r12, asr r5 */
/* @0x1c9ec8 andseq r6, r8, r0, ror #27 */
/* @0x1c9ecc eoreq r3, r2, r12, ror #29 */

/* ── 5.3 Command_NextRoom(int transition_kind)  0x1c9ed0..0x1c9f38 ──
 * 与 5.2 逐条镜像：Room_Last() 0x1b5d20、Room_Next 0x1b5da4、
 * 报错串 0x350cbc "Moving to next room after the last room."（池字 0x186da8）、
 * Error_Show_Action(str, 1)、-400 写回 0x542954、尾调 GotoRoom(next, 参数)。
 */


/* ── 入口：cur = *(0x542958)（0x1c9ed0..0x1c9eec）── */

/* @0x1c9ed0 push {r4, lr} */
/* @0x1c9ed4 mov r4, r0 */
/* @0x1c9ed8 bl 0x1b5d20 <_Z9Room_Lastv> */
/* @0x1c9edc ldr r3, [pc, #0x48] */
/* @0x1c9ee0 ldr r3, [pc, r3] */
/* @0x1c9ee4 ldr r3, [r3] */
/* @0x1c9ee8 cmp r0, r3 */
/* @0x1c9eec beq 0x1c9f04 <_Z16Command_NextRoomi+0x34> */

/* ── 非边界：Room_Next → 尾调 GotoRoom（0x1c9ef0..0x1c9f00）── */

/* @0x1c9ef0 mov r0, r3 */
/* @0x1c9ef4 bl 0x1b5da4 <_Z9Room_Nexti> */
/* @0x1c9ef8 mov r1, r4 */
/* @0x1c9efc pop {r4, lr} */
/* @0x1c9f00 b 0x1c9e08 <_Z16Command_GotoRoomii> */

/* ── 边界：报错 + 写 -400（0x1c9f04..0x1c9f28）── */

/* @0x1c9f04 ldr r0, [pc, #0x24] */
/* @0x1c9f08 mov r1, #1 */
/* @0x1c9f0c add r0, pc, r0 */
/* @0x1c9f10 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1c9f14 ldr r3, [pc, #0x18] */
/* @0x1c9f18 movw r2, #0xfe70 */
/* @0x1c9f1c movt r2, #0xffff */
/* @0x1c9f20 ldr r3, [pc, r3] */
/* @0x1c9f24 str r2, [r3] */
/* @0x1c9f28 pop {r4, pc} */

/* ── 三个池字：0x2254f4→槽0x3ef3dc、0x186da8→串 0x350cbc、0x223e84→槽0x3eddac ── */

/* @0x1c9f2c .word 0x002254f4 */
/* @0x1c9f30 andseq r6, r8, r8, lsr #27 */
/* @0x1c9f34 eoreq r3, r2, r4, lsl #29 */

/* ── 5.4 Command_CurrentRoom(int transition_kind)  0x1c9f38..0x1c9f50 ──
 * 只有 4 条有效指令：r0 = *(int*)0x542958（当前房号）、r1 = 本函数的 r0、尾调 GotoRoom。
 * ★ 它**不是 getter**：没有任何返回路径能跳出 GotoRoom，返回值也是 GotoRoom 的（void）。
 *   语义是 room_restart —— 重进当前房间。三个调用者全是 restart 语义
 *   （F_RoomRestart 0x109bf4、YYGML_room_restart 0x10c318、F_ActionCurrentRoom 0x13e6d4）。
 * ★ 名字里的 "CurrentRoom" 只说明「取当前房号当目标」，不说明它返回房号；
 *   重建时若把 GML 的 room_restart() 绑成「读 current room」会静默不换房。
 */


/* ── 全部 6 条：取房号 → 尾调 GotoRoom；最后一条是池字（槽 0x3ef3dc）── */

/* @0x1c9f38 ldr r3, [pc, #0xc] */
/* @0x1c9f3c mov r1, r0 */
/* @0x1c9f40 ldr r3, [pc, r3] */
/* @0x1c9f44 ldr r0, [r3] */
/* @0x1c9f48 b 0x1c9e08 <_Z16Command_GotoRoomii> */
/* @0x1c9f4c mlaeq r2, r4, r4, r5 */

/* ── 5.5 Command_EndGame()  0x1c9f50..0x1c9f54 ──
 * 一条 e12fff1e `bx lr`。5 个调用者（F_GameEnd 109bfc / YYGML_game_end 10c320 /
 * F_ActionEndGame 13ec4c / YYGML_action_end_game 141ca0 / DoAStep 1d35c0）都是 b 尾跳，
 * 所以它等价于「什么都不做」。详见 Command_Change.c 的附注（该卡已把这条链讲透）。
 * 本卡只补一行锚，让「32 个函数全部落锚」这件事在 index 层面也成立。
 */
/* @0x1c9f50 bx lr */



/* ── 5.6 Command_RestartGame()  0x1c9f54..0x1c9fac ──
 * 写: 0x1c9f6c *(int*)0x542954 = r1 = mvn r1,#199 = 0xffffff38 = **-200**（不是 -201：
 *     ~199 = -200；且 SingleStep 0x1d4df8 用的是 `cmn r0,#200`，即 r0 == -200 才进重启分支，
 *     两条独立证据同向 ⇒ Command_Change.c 附注里写的 "-201" 是笔误，本卡以 -200 为准）。
 * 读: 0x5428e8 一个字节（0x1c9f68）；为 0 就直接 bx lr（0x1c9f74）—— 即「调试模式下不重启」。
 *     再读 *(void**)0x544c38（0x1c9f80），非 0 也直接返回（0x1c9f88）。
 * 尾: 两条闸都过才 0x1c9f98 b Debug_AddTag(2, 0x350ce8)。
 * ⇒ 本函数只做「把 -200 塞进信箱」，真正重启在 SingleStep 0x1d4e78
 *   （Run_EndGame → GamePadRestart → StartGame → srand48(0x2012e4)）。
 */


/* ── 入口：三个 GOT 槽 → 0x5428e8 / 0x542954（0x1c9f54..0x1c9f6c）── */

/* @0x1c9f54 ldr r2, [pc, #0x40] */
/* @0x1c9f58 mvn r1, #199 */
/* @0x1c9f5c ldr r3, [pc, #0x3c] */
/* @0x1c9f60 ldr r2, [pc, r2] */
/* @0x1c9f64 ldr r3, [pc, r3] */
/* @0x1c9f68 ldrb r2, [r2] */
/* @0x1c9f6c str r1, [r3] */

/* ── 两道调试闸（0x1c9f70..0x1c9f88）── */

/* @0x1c9f70 cmp r2, #0 */
/* @0x1c9f74 bxeq lr */
/* @0x1c9f78 ldr r3, [pc, #0x24] */
/* @0x1c9f7c ldr r3, [pc, r3] */
/* @0x1c9f80 ldr r3, [r3] */
/* @0x1c9f84 cmp r3, #0 */
/* @0x1c9f88 bxne lr */

/* ── 尾调 Debug_AddTag(2, 串)（0x1c9f8c..0x1c9fa8）── */

/* @0x1c9f8c ldr r1, [pc, #0x14] */
/* @0x1c9f90 mov r0, #2 */
/* @0x1c9f94 add r1, pc, r1 */
/* @0x1c9f98 b 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1c9f9c eoreq r3, r2, r4, asr #19 */
/* @0x1c9fa0 eoreq r3, r2, r0, asr #28 */
/* @0x1c9fa4 eoreq r4, r2, r4, lsr #9 */
/* @0x1c9fa8 andseq r6, r8, r12, asr #26 */

/* ── 5.7 Command_ScreenShot(char const* name)  0x1c9fac..0x1ca040 ──
 * 闸: name == 0（0x1c9fb0 subs）或 name[0] == 0（0x1c9fbc ldrb）→
 *     Error_Show_Action("Trying to save screen to empty image file name.", 0)，不碰图形。
 * 抓屏: GR_Window_Get_Region_Width 0x179988 → w；GR_Window_Get_Region_Height 0x17999c → h；
 *       Graphics::GrabScreenRect(w, h, 0, 0, &w, &h) 0x17e0dc（两个出参就是栈上的 w/h 槽，
 *       0x1c9fec ldr r0,[r12,#-8]! 与 0x1c9ff0 stm sp,{r12,lr}）。
 * 落盘: 指针非 0 才 WritePNG32(name, ptr, w, h) 0x16cc8c，然后 MemoryManager::Free(ptr) 0x27c2d0。
 * ★ 只有这一条路径会分配内存；返回 0 时既不写文件也不释放。
 */


/* ── 入口与空名闸（0x1c9fac..0x1c9fc4）── */

/* @0x1c9fac push {r4, r5, lr} */
/* @0x1c9fb0 subs r4, r0, #0 */
/* @0x1c9fb4 sub sp, sp, #20 */
/* @0x1c9fb8 beq 0x1ca024 <_Z18Command_ScreenShotPKc+0x78> */
/* @0x1c9fbc ldrb r3, [r4] */
/* @0x1c9fc0 cmp r3, #0 */
/* @0x1c9fc4 beq 0x1ca024 <_Z18Command_ScreenShotPKc+0x78> */

/* ── 取窗口尺寸 + GrabScreenRect（0x1c9fc8..0x1c9ff4）── */

/* @0x1c9fc8 bl 0x179988 <_Z26GR_Window_Get_Region_Widthv> */
/* @0x1c9fcc str r0, [sp, #0x8] */
/* @0x1c9fd0 bl 0x17999c <_Z27GR_Window_Get_Region_Heightv> */
/* @0x1c9fd4 add r12, sp, #16 */
/* @0x1c9fd8 mov r2, #0 */
/* @0x1c9fdc add lr, sp, #12 */
/* @0x1c9fe0 mov r3, r2 */
/* @0x1c9fe4 mov r1, r0 */
/* @0x1c9fe8 str r0, [sp, #0xc] */
/* @0x1c9fec ldr r0, [r12, #-0x8]! */
/* @0x1c9ff0 stm sp, {r12, lr} */
/* @0x1c9ff4 bl 0x17e0dc <_ZN8Graphics14GrabScreenRectEiiiiPiS0_> */

/* ── 写 PNG + 释放（0x1c9ff8..0x1ca018）── */

/* @0x1c9ff8 subs r5, r0, #0 */
/* @0x1c9ffc beq 0x1ca01c <_Z18Command_ScreenShotPKc+0x70> */
/* @0x1ca000 mov r0, r4 */
/* @0x1ca004 mov r1, r5 */
/* @0x1ca008 ldr r2, [sp, #0x8] */
/* @0x1ca00c ldr r3, [sp, #0xc] */
/* @0x1ca010 bl 0x16cc8c <_Z10WritePNG32PcPvii> */
/* @0x1ca014 mov r0, r5 */
/* @0x1ca018 bl 0x27c2d0 <_ZN13MemoryManager4FreeEPKv> */

/* ── 空名出口（0x1ca01c..0x1ca03c）── */

/* @0x1ca01c add sp, sp, #20 */
/* @0x1ca020 pop {r4, r5, pc} */
/* @0x1ca024 ldr r0, [pc, #0x10] */
/* @0x1ca028 mov r1, #0 */
/* @0x1ca02c add r0, pc, r0 */
/* @0x1ca030 bl 0xecf70 <_Z17Error_Show_ActionPKcb> */
/* @0x1ca034 add sp, sp, #20 */
/* @0x1ca038 pop {r4, r5, pc} */
/* @0x1ca03c andseq r6, r8, r4, asr #25 */

/* ── 5.8 Run_Room_Set(CRoom* room)  0x1cba58..0x1cba6c（夹具，不属 Command_*）──
 * 4 条指令 + 末端 1 个池字：取 GOT 槽（0x1cba68 池字 0x221ecc → 0x3ed930）→ `str r0,[r3]` → bx lr。
 * 即 *(void**)0x54298c = room。**这是 Run_Room 在整个 .text 里唯一的写点**：
 * 全库只有两处 bl 指向本函数，都在 StartRoom（0x1d3944 与 0x1d4244）。
 * ★ 注意 Run_Room 是 CRoom* 不是房号；房号在 0x542958（5.2/5.3/5.4 读、StartRoom 写）。
 *   GML 变量 room 读的是房号（GV_Room 0x1f79ec），不是这个指针。
 */

/* @0x1cba58 ldr r3, [pc, #0x8] */
/* @0x1cba5c ldr r3, [pc, r3] */
/* @0x1cba60 str r0, [r3] */
/* @0x1cba64 bx lr */
/* @0x1cba68 eoreq r1, r2, r12, asr #29 */

/* ══ §6 碰撞谓词与接触移动（0x1ca9f8..0x1caf90，4 个 + 1 个夹具）══════════════════════
 * 这一族的开关是全局字节 0x542379（option_use_fast_collision，Builtins_Instance 卡命名）：
 *   非 0 → UpdateTree() 0x1cc24c + RTree::Search 0x10d720（带一个回调）
 *   为 0 → 遍历当前房实例链逐个 CInstance::Collision_Instance 0x195558
 * 两条路径都必须「临时把实例挪到 (x,y)」再判定，因为 Collision_* 用的是实例自己的 bbox。
 */

/* ── 6.1 Command_IsMeeting(inst, obj, x, y)  0x1ca9f8..0x1caa1c ──
 * 全部 9 条就是一次实参重排 + 一次调用 + 一次 !=0 归一：
 *   0x1ca9f8 mov r12,r1（obj 暂存）→ 0x1ca9fc mov r1,r2（x 进 r1）→ 0x1caa04 mov r2,r3（y 进 r2）
 *   → 0x1caa08 mov r3,r12（obj 进 r3）→ bl Command_InstancePlace(inst, x, y, obj)。
 *   ⇒ 命令层 IsMeeting 的参数序是 (inst, obj, x, y)，而 InstancePlace 是 (inst, x, y, obj)；
 *     内建层 place_meeting 又是 (x, y, obj)。三层三种顺序，重建时最容易在这里错位。
 * 返回: 0x1caa10 adds r0,r0,#0 / movne r0,#1 ⇒ bool。
 * 调用者: F_PlaceMeeting 0x108044、F_ActionIfObject 0x13eec8+0x78 与 +0xb0（两处）、
 *         TestFree 0x19c6f4+0x24 —— 全 .text 共 4 处，全是 bl。
 */


/* ── 9 条全部：重排 (obj,x,y) → (x,y,obj)，再 !=0 ── */

/* @0x1ca9f8 mov r12, r1 */
/* @0x1ca9fc mov r1, r2 */
/* @0x1caa00 push {r3, lr} */
/* @0x1caa04 mov r2, r3 */
/* @0x1caa08 mov r3, r12 */
/* @0x1caa0c bl 0x1ca6d8 <_Z21Command_InstancePlaceP9CInstanceffi> */
/* @0x1caa10 adds r0, r0, #0 */
/* @0x1caa14 movne r0, #1 */
/* @0x1caa18 pop {r3, pc} */

/* ── 6.2 Command_IsEmpty(inst, float x, float y)  0x1caa1c..0x1cab94 ──
 * 语义: 「把 inst 放到 (x,y) 后，房间里有没有任何实例与它相撞」——没有就是 empty。
 * 两条路径（0x1caa3c 判 0x542379）：
 *   A 快路径（0x1caa44..0x1caae4）: UpdateTree → 临时 SetPosition(inst,x,y) →
 *       inst+0x64 != 0 时先 Compute_BoundingBox(inst,1) 0x192340（0x1cab70）→
 *       把 inst+0xe8/+0xec/+0xf0/+0xf4 四字段按 min/max 归一成查询矩形（0x1caaac..0x1caad8，
 *       用 strle/strgt 与 strge/strlt 两两比较，各存 min 与 max）→
 *       0x5428b4 置 1 → RTree::Search(0x10d720) 带回调 0x1c8744 → 还原位置 → 返回 0x5428b4。
 *       ⇒ 标志的极性是「1 = 空」：搜索前置 1，回调发现命中才清 0。
 *   B 慢路径（0x1cab04..0x1cab44）: 临时 SetPosition → 遍历 CRoom+0x80/+0x178，
 *       逐个 CInstance::Collision_Instance(other, inst, 1) 0x195558 → 命中返回 0，走完返回 1。
 * ★ 两条路径都**不设对象过滤**（place_empty = 对所有实例）。
 * ★ 两条路径都临时改过 inst 的位置，出口处一律 SetPosition 还原
 *   （0x1caae4 / 0x1cab04 / 0x1cab58 三处还原点，四条出口都覆盖）。
 */


/* ── 入口：0x542379 选路（0x1caa1c..0x1caa40）── */

/* @0x1caa1c ldr r3, [pc, #0x15c] */
/* @0x1caa20 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1caa24 ldr r3, [pc, r3] */
/* @0x1caa28 sub sp, sp, #24 */
/* @0x1caa2c mov r5, r0 */
/* @0x1caa30 ldrb r3, [r3] */
/* @0x1caa34 mov r6, r1 */
/* @0x1caa38 mov r4, r2 */
/* @0x1caa3c cmp r3, #0 */
/* @0x1caa40 beq 0x1caafc <_Z15Command_IsEmptyP9CInstanceff+0xe0> */

/* ── 快路径：UpdateTree + 临时 SetPosition（0x1caa44..0x1caa68）── */

/* @0x1caa44 bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1caa48 mov r1, r6 */
/* @0x1caa4c mov r2, r4 */
/* @0x1caa50 mov r0, r5 */
/* @0x1caa54 ldr r8, [r5, #0xb4] */
/* @0x1caa58 ldr r7, [r5, #0xb8] */
/* @0x1caa5c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caa60 ldrb r3, [r5, #0x64] */
/* @0x1caa64 cmp r3, #0 */
/* @0x1caa68 bne 0x1cab70 <_Z15Command_IsEmptyP9CInstanceff+0x154> */

/* ── 快路径：查询矩形 + RTree::Search（0x1caa6c..0x1caadc）── */

/* @0x1caa6c ldr r3, [pc, #0x110] */
/* @0x1caa70 add r1, sp, #8 */
/* @0x1caa74 ldr r4, [pc, #0x10c] */
/* @0x1caa78 add r2, sp, #16 */
/* @0x1caa7c ldr r3, [pc, r3] */
/* @0x1caa80 ldr r12, [r5, #0xec] */
/* @0x1caa84 ldr lr, [r5, #0xf4] */
/* @0x1caa88 add r4, pc, r4 */
/* @0x1caa8c ldr r6, [r5, #0xe8] */
/* @0x1caa90 mov r10, #1 */
/* @0x1caa94 ldr r9, [r5, #0xf0] */
/* @0x1caa98 ldr r0, [r3] */
/* @0x1caa9c ldr r3, [pc, #0xe8] */
/* @0x1caaa0 str r5, [sp] */
/* @0x1caaa4 add r3, pc, r3 */
/* @0x1caaa8 strb r10, [r4, #0x200] */
/* @0x1caaac cmp lr, r12 */
/* @0x1caab0 strle lr, [sp, #0xc] */
/* @0x1caab4 strgt r12, [sp, #0xc] */
/* @0x1caab8 cmp lr, r12 */
/* @0x1caabc strge lr, [sp, #0x14] */
/* @0x1caac0 strlt r12, [sp, #0x14] */
/* @0x1caac4 cmp r9, r6 */
/* @0x1caac8 strle r9, [sp, #0x8] */
/* @0x1caacc strgt r6, [sp, #0x8] */
/* @0x1caad0 cmp r9, r6 */
/* @0x1caad4 strge r9, [sp, #0x10] */
/* @0x1caad8 strlt r6, [sp, #0x10] */
/* @0x1caadc bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */

/* ── 快路径收尾：还原位置、取标志（0x1caae0..0x1caaf8）── */

/* @0x1caae0 mov r0, r5 */
/* @0x1caae4 mov r1, r8 */
/* @0x1caae8 mov r2, r7 */
/* @0x1caaec bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caaf0 ldrb r0, [r4, #0x200] */
/* @0x1caaf4 add sp, sp, #24 */
/* @0x1caaf8 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 慢路径：SetPosition + 逐实例 Collision_Instance（0x1caafc..0x1cab6c）── */

/* @0x1caafc ldr r7, [r0, #0xb4] */
/* @0x1cab00 ldr r6, [r0, #0xb8] */
/* @0x1cab04 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cab08 ldr r3, [pc, #0x80] */
/* @0x1cab0c ldr r3, [pc, r3] */
/* @0x1cab10 ldr r3, [r3] */
/* @0x1cab14 ldr r3, [r3, #0x80] */
/* @0x1cab18 cmp r3, #0 */
/* @0x1cab1c beq 0x1cab48 <_Z15Command_IsEmptyP9CInstanceff+0x12c> */
/* @0x1cab20 mov r0, r3 */
/* @0x1cab24 mov r1, r5 */
/* @0x1cab28 mov r2, #1 */
/* @0x1cab2c ldr r4, [r3, #0x178] */
/* @0x1cab30 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cab34 mov r3, r4 */
/* @0x1cab38 cmp r0, #0 */
/* @0x1cab3c bne 0x1cab68 <_Z15Command_IsEmptyP9CInstanceff+0x14c> */
/* @0x1cab40 cmp r4, #0 */
/* @0x1cab44 bne 0x1cab20 <_Z15Command_IsEmptyP9CInstanceff+0x104> */
/* @0x1cab48 mov r4, #1 */
/* @0x1cab4c mov r0, r5 */
/* @0x1cab50 mov r1, r7 */
/* @0x1cab54 mov r2, r6 */
/* @0x1cab58 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cab5c mov r0, r4 */
/* @0x1cab60 add sp, sp, #24 */
/* @0x1cab64 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1cab68 mov r4, #0 */
/* @0x1cab6c b 0x1cab4c <_Z15Command_IsEmptyP9CInstanceff+0x130> */

/* ── inst+0x64 非 0 时的 Compute_BoundingBox(inst,1)（0x1cab70..0x1cab7c）── */

/* @0x1cab70 mov r0, r5 */
/* @0x1cab74 mov r1, #1 */
/* @0x1cab78 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cab7c b 0x1caa6c <_Z15Command_IsEmptyP9CInstanceff+0x50> */

/* ── 四个池字（0x1cab80..0x1cab90）── */

/* @0x1cab80 eoreq r5, r2, r12, asr r12 */
/* @0x1cab84 eoreq r3, r2, r8, asr #15 */
/* @0x1cab88 eorseq r7, r7, r4, lsr #24 */
/* @0x1cab8c .word 0xffffdc98 */
/* @0x1cab90 eoreq r2, r2, r12, lsl lr */

/* ── 6.3 Command_IsFree(inst, float x, float y)  0x1cab94..0x1cad18 ──
 * 与 6.2 逐条同构，只有两处不同 —— 而这两处正是 place_empty 与 place_free 的全部差别：
 *   ① RTree 回调换成 0x1c87d8（0x1cac1c add pc 的池字 0xffffdbb4）；
 *   ② 慢路径多一道 solid 过滤：0x1cacd8 `ldrb r12,[r0,#0x66]` + 0x1cace0 `beq` 跳过
 *      ⇒ 只测 inst+0x66 != 0 的实例（solid 标记）。
 *   ⇒ place_free 只和 solid 冲突，place_empty 和一切冲突。
 * 其余（快路径、临时挪位、0x5428b4 极性、还原点）与 6.2 一致。
 */


/* ── 入口：0x542379 选路（0x1cab94..0x1cabb8）── */

/* @0x1cab94 ldr r3, [pc, #0x168] */
/* @0x1cab98 push {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x1cab9c ldr r3, [pc, r3] */
/* @0x1caba0 sub sp, sp, #24 */
/* @0x1caba4 mov r5, r0 */
/* @0x1caba8 ldrb r3, [r3] */
/* @0x1cabac mov r6, r1 */
/* @0x1cabb0 mov r4, r2 */
/* @0x1cabb4 cmp r3, #0 */
/* @0x1cabb8 beq 0x1cac74 <_Z14Command_IsFreeP9CInstanceff+0xe0> */

/* ── 快路径：UpdateTree + 临时 SetPosition（0x1cabbc..0x1cabe0）── */

/* @0x1cabbc bl 0x1cc24c <_Z10UpdateTreev> */
/* @0x1cabc0 mov r1, r6 */
/* @0x1cabc4 mov r2, r4 */
/* @0x1cabc8 mov r0, r5 */
/* @0x1cabcc ldr r8, [r5, #0xb4] */
/* @0x1cabd0 ldr r7, [r5, #0xb8] */
/* @0x1cabd4 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cabd8 ldrb r3, [r5, #0x64] */
/* @0x1cabdc cmp r3, #0 */
/* @0x1cabe0 bne 0x1cacec <_Z14Command_IsFreeP9CInstanceff+0x158> */

/* ── 快路径：查询矩形 + RTree::Search（0x1cabe4..0x1cac54）── */

/* @0x1cabe4 ldr r3, [pc, #0x11c] */
/* @0x1cabe8 add r1, sp, #8 */
/* @0x1cabec ldr r4, [pc, #0x118] */
/* @0x1cabf0 add r2, sp, #16 */
/* @0x1cabf4 ldr r3, [pc, r3] */
/* @0x1cabf8 ldr r12, [r5, #0xec] */
/* @0x1cabfc ldr lr, [r5, #0xf4] */
/* @0x1cac00 add r4, pc, r4 */
/* @0x1cac04 ldr r6, [r5, #0xe8] */
/* @0x1cac08 mov r10, #1 */
/* @0x1cac0c ldr r9, [r5, #0xf0] */
/* @0x1cac10 ldr r0, [r3] */
/* @0x1cac14 ldr r3, [pc, #0xf4] */
/* @0x1cac18 str r5, [sp] */
/* @0x1cac1c add r3, pc, r3 */
/* @0x1cac20 strb r10, [r4, #0x200] */
/* @0x1cac24 cmp lr, r12 */
/* @0x1cac28 strle lr, [sp, #0xc] */
/* @0x1cac2c strgt r12, [sp, #0xc] */
/* @0x1cac30 cmp lr, r12 */
/* @0x1cac34 strge lr, [sp, #0x14] */
/* @0x1cac38 strlt r12, [sp, #0x14] */
/* @0x1cac3c cmp r9, r6 */
/* @0x1cac40 strle r9, [sp, #0x8] */
/* @0x1cac44 strgt r6, [sp, #0x8] */
/* @0x1cac48 cmp r9, r6 */
/* @0x1cac4c strge r9, [sp, #0x10] */
/* @0x1cac50 strlt r6, [sp, #0x10] */
/* @0x1cac54 bl 0x10d720 <_ZN5RTreeIP9CInstanceifLi6ELi2EE6SearchEPKiS4_PFbS1_PvES5_> */

/* ── 快路径收尾（0x1cac58..0x1cac70）── */

/* @0x1cac58 mov r0, r5 */
/* @0x1cac5c mov r1, r8 */
/* @0x1cac60 mov r2, r7 */
/* @0x1cac64 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cac68 ldrb r0, [r4, #0x200] */
/* @0x1cac6c add sp, sp, #24 */
/* @0x1cac70 pop {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── 慢路径：+0x66 solid 过滤是关键（0x1cac74..0x1cad00）── */

/* @0x1cac74 ldr r7, [r0, #0xb4] */
/* @0x1cac78 ldr r6, [r0, #0xb8] */
/* @0x1cac7c bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cac80 ldr r3, [pc, #0x8c] */
/* @0x1cac84 ldr r3, [pc, r3] */
/* @0x1cac88 ldr r3, [r3] */
/* @0x1cac8c ldr r0, [r3, #0x80] */
/* @0x1cac90 cmp r0, #0 */
/* @0x1cac94 bne 0x1cacd8 <_Z14Command_IsFreeP9CInstanceff+0x144> */
/* @0x1cac98 mov r4, #1 */
/* @0x1cac9c mov r0, r5 */
/* @0x1caca0 mov r1, r7 */
/* @0x1caca4 mov r2, r6 */
/* @0x1caca8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cacac mov r0, r4 */
/* @0x1cacb0 add sp, sp, #24 */
/* @0x1cacb4 pop {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x1cacb8 mov r1, r5 */
/* @0x1cacbc mov r2, #1 */
/* @0x1cacc0 bl 0x195558 <_ZN9CInstance18Collision_InstanceEPS_b> */
/* @0x1cacc4 cmp r0, #0 */
/* @0x1cacc8 bne 0x1cacfc <_Z14Command_IsFreeP9CInstanceff+0x168> */
/* @0x1caccc cmp r4, #0 */
/* @0x1cacd0 mov r0, r4 */
/* @0x1cacd4 beq 0x1cac98 <_Z14Command_IsFreeP9CInstanceff+0x104> */
/* @0x1cacd8 ldrb r12, [r0, #0x66] */
/* @0x1cacdc ldr r4, [r0, #0x178] */
/* @0x1cace0 cmp r12, #0 */
/* @0x1cace4 beq 0x1caccc <_Z14Command_IsFreeP9CInstanceff+0x138> */
/* @0x1cace8 b 0x1cacb8 <_Z14Command_IsFreeP9CInstanceff+0x124> */
/* @0x1cacec mov r0, r5 */
/* @0x1cacf0 mov r1, #1 */
/* @0x1cacf4 bl 0x192340 <_ZN9CInstance19Compute_BoundingBoxEb> */
/* @0x1cacf8 b 0x1cabe4 <_Z14Command_IsFreeP9CInstanceff+0x50> */
/* @0x1cacfc mov r4, #0 */
/* @0x1cad00 b 0x1cac9c <_Z14Command_IsFreeP9CInstanceff+0x108> */

/* ── 四个池字（0x1cad04..0x1cad14）── */

/* @0x1cad04 eoreq r5, r2, r4, ror #21 */
/* @0x1cad08 eoreq r3, r2, r0, asr r6 */
/* @0x1cad0c eorseq r7, r7, r12, lsr #21 */
/* @0x1cad10 .word 0xffffdbb4 */
/* @0x1cad14 eoreq r2, r2, r4, lsr #25 */

/* ── 6.4 Contact_TestFree(inst, x, y, allObjects)  0x1cad18..0x1cad28（夹具）──
 * 4 条指令就是一次二选一尾跳：0x1cad18 cmp r3,#0 / bne → Command_IsEmpty（全实例）
 * 否则 → Command_IsFree（只 solid）。
 * ⇒ 「第 4 个 bool = true 表示对全部实例判」这个口径的唯一实现点就在这里；
 *   MoveContact / MoveOutside 的 allObjects 形参原样传进来。
 * （同极性的另一份是 Bounce_Test 0x1caf90，属 Command_Bounce 卡。）
 */


/* ── 4 条全部（含 0x1cad24 的 Command_IsEmpty 尾跳）── */

/* @0x1cad18 cmp r3, #0 */
/* @0x1cad1c bne 0x1cad24 <_Z16Contact_TestFreeP9CInstanceffb+0xc> */
/* @0x1cad20 b 0x1cab94 <_Z14Command_IsFreeP9CInstanceff> */
/* @0x1cad24 b 0x1caa1c <_Z15Command_IsEmptyP9CInstanceff> */

/* ── 6.5 Command_MoveContact(inst, dir, dist, allObjects)  0x1cad28..0x1cae64 ──
 * 语义: 沿 dir（**度**，0 = +x）逐步前进，直到「下一步会碰」为止。
 * 角度: 0x1cad50 池字 0x40490fdb = π(float)、0x1cad5c 0x43340000 = 180.0f ⇒ 弧度 = dir*π/180；
 *       cosf 0xb658c → s17、sinf 0xb6580 → s16。
 * 步长: 每步恰好 1 像素（0x1cadb8 vadd s14,s17 与 0x1cadbc vsub s15,s16 —— 没有乘 dist）。
 *       dist 只决定**最多走几步**：>0 → lrint((double)dist)（0x1cad58），<=0 → 1000（0x1cae50）。
 * 方向: x += cos、y -= sin（屏幕 y 向下 ⇒ 数学角逆时针）。
 * 极性: 先测当前位；不 free → 直接返回（0x1cad98 beq 出口）；
 *       free → 循环：先算下一步，若那一步仍 free 才 SetPosition 并继续；一旦不 free 就停。
 * ⇒ 结果是「停在最后一次成功移动的位置」，不是撞上后回退。
 */


/* ── 入口：dist>0 走 lrint，cos/sin（0x1cad28..0x1cad80）── */

/* @0x1cad28 vmov s15, r2 */
/* @0x1cad2c push {r3, r4, r5, r6, r7, lr} */
/* @0x1cad30 vpush {d8} */
/* @0x1cad34 vcmpe.f32 s15, #0 */
/* @0x1cad38 mov r4, r0 */
/* @0x1cad3c mov r6, r3 */
/* @0x1cad40 vmov s17, r1 */
/* @0x1cad44 vmrs APSR_nzcv, fpscr */
/* @0x1cad48 bls 0x1cae10 <_Z19Command_MoveContactP9CInstanceffb+0xe8> */
/* @0x1cad4c vcvt.f64.f32 d6, s15 */
/* @0x1cad50 vldr s16, [pc, #260] */
/* @0x1cad54 vmov r0, r1, d6 */
/* @0x1cad58 bl 0xb66e8 <lrint@plt> */
/* @0x1cad5c vldr s15, [pc, #252] */
/* @0x1cad60 vmul.f32 s16, s17, s16 */
/* @0x1cad64 vdiv.f32 s16, s16, s15 */
/* @0x1cad68 mov r7, r0 */
/* @0x1cad6c vmov r0, s16 */
/* @0x1cad70 bl 0xb658c <cosf@plt> */
/* @0x1cad74 vmov s17, r0 */
/* @0x1cad78 vmov r0, s16 */
/* @0x1cad7c bl 0xb6580 <sinf@plt> */

/* ── 先测当前位（0x1cad80..0x1cad9c）── */

/* @0x1cad80 ldr r1, [r4, #0xb4] */
/* @0x1cad84 mov r3, r6 */
/* @0x1cad88 ldr r2, [r4, #0xb8] */
/* @0x1cad8c vmov s16, r0 */
/* @0x1cad90 mov r0, r4 */
/* @0x1cad94 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cad98 cmp r0, #0 */
/* @0x1cad9c beq 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */

/* ── 主循环：下一步 free 才落地（0x1cada0..0x1cadd0）── */

/* @0x1cada0 cmp r7, #0 */
/* @0x1cada4 ble 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */
/* @0x1cada8 mov r5, #1 */
/* @0x1cadac b 0x1cadd4 <_Z19Command_MoveContactP9CInstanceffb+0xac> */
/* @0x1cadb0 vldr s14, [r4, #180] */
/* @0x1cadb4 vldr s15, [r4, #184] */
/* @0x1cadb8 vadd.f32 s14, s17, s14 */
/* @0x1cadbc vsub.f32 s15, s15, s16 */
/* @0x1cadc0 vmov r1, s14 */
/* @0x1cadc4 vmov r2, s15 */
/* @0x1cadc8 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1cadcc cmp r5, r7 */
/* @0x1cadd0 bgt 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */

/* ── 循环体（0x1cadd4..0x1cae04）── */

/* @0x1cadd4 vldr s14, [r4, #180] */
/* @0x1cadd8 vldr s15, [r4, #184] */
/* @0x1caddc vadd.f32 s14, s17, s14 */
/* @0x1cade0 mov r0, r4 */
/* @0x1cade4 mov r3, r6 */
/* @0x1cade8 add r5, r5, #1 */
/* @0x1cadec vsub.f32 s15, s15, s16 */
/* @0x1cadf0 vmov r1, s14 */
/* @0x1cadf4 vmov r2, s15 */
/* @0x1cadf8 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cadfc cmp r0, #0 */
/* @0x1cae00 mov r0, r4 */
/* @0x1cae04 bne 0x1cadb0 <_Z19Command_MoveContactP9CInstanceffb+0x88> */

/* ── 公共出口（0x1cae08..0x1cae0c）── */

/* @0x1cae08 vpop {d8} */
/* @0x1cae0c pop {r3, r4, r5, r6, r7, pc} */

/* ── dist<=0 分支：同一角度、1000 步上限（0x1cae10..0x1cae58）── */

/* @0x1cae10 vldr s16, [pc, #68] */
/* @0x1cae14 vmul.f32 s16, s17, s16 */
/* @0x1cae18 vldr s15, [pc, #64] */
/* @0x1cae1c vdiv.f32 s16, s16, s15 */
/* @0x1cae20 vmov r0, s16 */
/* @0x1cae24 bl 0xb658c <cosf@plt> */
/* @0x1cae28 vmov s17, r0 */
/* @0x1cae2c vmov r0, s16 */
/* @0x1cae30 bl 0xb6580 <sinf@plt> */
/* @0x1cae34 ldr r1, [r4, #0xb4] */
/* @0x1cae38 mov r3, r6 */
/* @0x1cae3c ldr r2, [r4, #0xb8] */
/* @0x1cae40 vmov s16, r0 */
/* @0x1cae44 mov r0, r4 */
/* @0x1cae48 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1cae4c cmp r0, #0 */
/* @0x1cae50 movne r7, #1000 */
/* @0x1cae54 bne 0x1cada8 <_Z19Command_MoveContactP9CInstanceffb+0x80> */
/* @0x1cae58 b 0x1cae08 <_Z19Command_MoveContactP9CInstanceffb+0xe0> */

/* ── 两个常量：π / 180.0f（0x1cae5c / 0x1cae60）── */

/* @0x1cae5c ldrdmi r0, r1, [r9], #-251 */
/* @0x1cae60 teqmi r4, #0 */

/* ── 6.6 Command_MoveOutside(inst, dir, dist, allObjects)  0x1cae64..0x1caf90 ──
 * 与 6.5 极性完全相反：当前位 free → 立即返回；不 free → 每次「先落地、再测」，
 * 直到落地后 free 为止（0x1caf28 bl 之后的 beq 0x1caeec 就是「还没 free 就再来一步」）。
 * ⇒ move_outside 有「至少走一步」的隐含保证（先 SetPosition 再判定），
 *   而 move_contact 是「先判定再落地」。
 * 其它：角度公式、步长 1、dist<=0 → 1000 步、allObjects 透传，与 6.5 逐条相同
 * （常量在 0x1caf88/0x1caf8c，同样 π 与 180.0f）。
 */


/* ── 入口与 cos/sin（0x1cae64..0x1caebc）── */

/* @0x1cae64 vmov s15, r2 */
/* @0x1cae68 push {r3, r4, r5, r6, r7, lr} */
/* @0x1cae6c vpush {d8} */
/* @0x1cae70 vcmpe.f32 s15, #0 */
/* @0x1cae74 mov r4, r0 */
/* @0x1cae78 mov r6, r3 */
/* @0x1cae7c vmov s16, r1 */
/* @0x1cae80 vmrs APSR_nzcv, fpscr */
/* @0x1cae84 bls 0x1caf3c <_Z19Command_MoveOutsideP9CInstanceffb+0xd8> */
/* @0x1cae88 vcvt.f64.f32 d6, s15 */
/* @0x1cae8c vldr s17, [pc, #244] */
/* @0x1cae90 vmov r0, r1, d6 */
/* @0x1cae94 bl 0xb66e8 <lrint@plt> */
/* @0x1cae98 vldr s15, [pc, #236] */
/* @0x1cae9c vmul.f32 s17, s16, s17 */
/* @0x1caea0 vdiv.f32 s17, s17, s15 */
/* @0x1caea4 mov r7, r0 */
/* @0x1caea8 vmov r0, s17 */
/* @0x1caeac bl 0xb658c <cosf@plt> */
/* @0x1caeb0 vmov s16, r0 */
/* @0x1caeb4 vmov r0, s17 */
/* @0x1caeb8 bl 0xb6580 <sinf@plt> */

/* ── 先测当前位：free 就立刻返回（0x1caebc..0x1caee4）── */

/* @0x1caebc ldr r1, [r4, #0xb4] */
/* @0x1caec0 mov r3, r6 */
/* @0x1caec4 ldr r2, [r4, #0xb8] */
/* @0x1caec8 vmov s17, r0 */
/* @0x1caecc mov r0, r4 */
/* @0x1caed0 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caed4 cmp r0, #0 */
/* @0x1caed8 bne 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caedc cmp r7, #0 */
/* @0x1caee0 ble 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */
/* @0x1caee4 mov r5, #1 */
/* @0x1caee8 b 0x1caef4 <_Z19Command_MoveOutsideP9CInstanceffb+0x90> */
/* @0x1caeec cmp r5, r7 */
/* @0x1caef0 bgt 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */

/* ── 主循环：先落地再测（0x1caef4..0x1caf30）── */

/* @0x1caef4 vldr s14, [r4, #180] */
/* @0x1caef8 vldr s15, [r4, #184] */
/* @0x1caefc vadd.f32 s14, s16, s14 */
/* @0x1caf00 mov r0, r4 */
/* @0x1caf04 add r5, r5, #1 */
/* @0x1caf08 vsub.f32 s15, s15, s17 */
/* @0x1caf0c vmov r1, s14 */
/* @0x1caf10 vmov r2, s15 */
/* @0x1caf14 bl 0x193e7c <_ZN9CInstance11SetPositionEff> */
/* @0x1caf18 mov r0, r4 */
/* @0x1caf1c ldr r1, [r4, #0xb4] */
/* @0x1caf20 mov r3, r6 */
/* @0x1caf24 ldr r2, [r4, #0xb8] */
/* @0x1caf28 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caf2c cmp r0, #0 */
/* @0x1caf30 beq 0x1caeec <_Z19Command_MoveOutsideP9CInstanceffb+0x88> */

/* ── 公共出口（0x1caf34..0x1caf38）── */

/* @0x1caf34 vpop {d8} */
/* @0x1caf38 pop {r3, r4, r5, r6, r7, pc} */

/* ── dist<=0 分支（0x1caf3c..0x1caf84）── */

/* @0x1caf3c vldr s15, [pc, #68] */
/* @0x1caf40 vmul.f32 s16, s16, s15 */
/* @0x1caf44 vldr s15, [pc, #64] */
/* @0x1caf48 vdiv.f32 s17, s16, s15 */
/* @0x1caf4c vmov r0, s17 */
/* @0x1caf50 bl 0xb658c <cosf@plt> */
/* @0x1caf54 vmov s16, r0 */
/* @0x1caf58 vmov r0, s17 */
/* @0x1caf5c bl 0xb6580 <sinf@plt> */
/* @0x1caf60 ldr r1, [r4, #0xb4] */
/* @0x1caf64 mov r3, r6 */
/* @0x1caf68 ldr r2, [r4, #0xb8] */
/* @0x1caf6c vmov s17, r0 */
/* @0x1caf70 mov r0, r4 */
/* @0x1caf74 bl 0x1cad18 <_Z16Contact_TestFreeP9CInstanceffb> */
/* @0x1caf78 cmp r0, #0 */
/* @0x1caf7c moveq r7, #1000 */
/* @0x1caf80 beq 0x1caee4 <_Z19Command_MoveOutsideP9CInstanceffb+0x80> */
/* @0x1caf84 b 0x1caf34 <_Z19Command_MoveOutsideP9CInstanceffb+0xd0> */

/* ── 两个常量（0x1caf88 / 0x1caf8c）与下一函数的入口（0x1caf90 Bounce_Test，属 Bounce 卡）── */

/* @0x1caf88 ldrdmi r0, r1, [r9], #-251 */
/* @0x1caf8c teqmi r4, #0 */

/* ══ §7 存档（0x1d0dd8..0x1d168c，3 个函数）══════════════════════════════════════════
 * 分工: 命令层不碰磁盘以外的状态机 —— 它只负责「把一段内存或一个文件变成 IBuffer」，
 *       然后把 buffer id 塞进 0x3f511c 队列槽；真正的反序列化在帧循环的 LoadGame() 里。
 * 全局: 0x5429cc 待消费 IBuffer、0x3f511c 队列槽（-1 = 空）、0x54295c 存档名指针。
 */

/* ── 7.1 Command_LoadGame(int bufid)  0x1d0dd8..0x1d0ed0 ──
 * ① 队列闸: 0x1d0dec 读 *(0x3f511c)，0x1d0df4 `cmn r3,#1` ⇒ 只有 -1（空）才继续；
 *    否则 0x1d0e08 打 "WARNING: Load game being ignored due to load game already queued"
 *    （vtable 派发器 0x3eb70c→0x47a118→[vt+0xc]），返回 0。
 * ② 取 buffer: GetIBuffer(bufid) 0xc6720；为 0 → 0x1d0e94 打
 *    "WARNING: No buffer available for %d\n"（r2 = bufid，真的带参），返回 0。
 * ③ 登记: 0x1d0e3c `str r6,[r2]`，r2 = 0x5429cc ⇒ 待消费指针换成这块 buffer。
 * ④ 调试: 0x5428e8 != 0 且 *(0x544c38) == 0 时 Debug_AddTag(2, "Load game") 0x29c3ec。
 * ⑤ 返回 1。
 * ★ 本函数**不解析** buffer、不换房、不碰 New_Room；解析在 LoadGame() 0x1d1cb4。
 */


/* ── 入口：GOT 基址 + 队列闸（0x1d0dd8..0x1d0e20）── */

/* @0x1d0dd8 ldr r3, [pc, #0xd0] */
/* @0x1d0ddc push {r4, r5, r6, lr} */
/* @0x1d0de0 add r3, pc, r3 */
/* @0x1d0de4 ldr r4, [pc, #0xc8] */
/* @0x1d0de8 mov r5, r0 */
/* @0x1d0dec ldr r3, [r3, #0x4] */
/* @0x1d0df0 add r4, pc, r4 */
/* @0x1d0df4 cmn r3, #1 */
/* @0x1d0df8 beq 0x1d0e24 <_Z16Command_LoadGamei+0x4c> */
/* @0x1d0dfc ldr r3, [pc, #0xb4] */
/* @0x1d0e00 ldr r1, [pc, #0xb4] */
/* @0x1d0e04 ldr r3, [r4, r3] */
/* @0x1d0e08 add r1, pc, r1 */
/* @0x1d0e0c ldr r0, [r3] */
/* @0x1d0e10 ldr r3, [r0] */
/* @0x1d0e14 ldr r3, [r3, #0xc] */
/* @0x1d0e18 blx r3 */
/* @0x1d0e1c mov r0, #0 */
/* @0x1d0e20 pop {r4, r5, r6, pc} */

/* ── GetIBuffer + 登记到 0x5429cc（0x1d0e24..0x1d0e3c）── */

/* @0x1d0e24 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d0e28 subs r6, r0, #0 */
/* @0x1d0e2c beq 0x1d0e84 <_Z16Command_LoadGamei+0xac> */
/* @0x1d0e30 ldr r2, [pc, #0x88] */
/* @0x1d0e34 ldr r3, [pc, #0x88] */
/* @0x1d0e38 add r2, pc, r2 */
/* @0x1d0e3c str r6, [r2] */

/* ── 调试两闸 + Debug_AddTag（0x1d0e40..0x1d0e80）── */

/* @0x1d0e40 ldr r3, [r4, r3] */
/* @0x1d0e44 ldrb r3, [r3] */
/* @0x1d0e48 cmp r3, #0 */
/* @0x1d0e4c beq 0x1d0e64 <_Z16Command_LoadGamei+0x8c> */
/* @0x1d0e50 ldr r3, [pc, #0x70] */
/* @0x1d0e54 ldr r3, [r4, r3] */
/* @0x1d0e58 ldr r3, [r3] */
/* @0x1d0e5c cmp r3, #0 */
/* @0x1d0e60 beq 0x1d0e6c <_Z16Command_LoadGamei+0x94> */
/* @0x1d0e64 mov r0, #1 */
/* @0x1d0e68 pop {r4, r5, r6, pc} */
/* @0x1d0e6c ldr r1, [pc, #0x58] */
/* @0x1d0e70 mov r0, #2 */
/* @0x1d0e74 add r1, pc, r1 */
/* @0x1d0e78 bl 0x29c3ec <_Z12Debug_AddTag12eTagNameTypePKcz> */
/* @0x1d0e7c mov r0, #1 */
/* @0x1d0e80 pop {r4, r5, r6, pc} */

/* ── buffer 为空：带 %d 的警告（0x1d0e84..0x1d0eac）── */

/* @0x1d0e84 ldr r3, [pc, #0x2c] */
/* @0x1d0e88 mov r2, r5 */
/* @0x1d0e8c ldr r1, [pc, #0x3c] */
/* @0x1d0e90 ldr r3, [r4, r3] */
/* @0x1d0e94 add r1, pc, r1 */
/* @0x1d0e98 ldr r0, [r3] */
/* @0x1d0e9c ldr r3, [r0] */
/* @0x1d0ea0 ldr r3, [r3, #0xc] */
/* @0x1d0ea4 blx r3 */
/* @0x1d0ea8 mov r0, r6 */
/* @0x1d0eac pop {r4, r5, r6, pc} */

/* ── 七个池字（0x1d0eb0..0x1d0ecc）── */

/* @0x1d0eb0 eoreq r4, r2, r0, lsr r3 */
/* @0x1d0eb4 eoreq r0, r2, r0, ror #28 */
/* @0x1d0eb8 .word 0xffffbac4 */
/* @0x1d0ebc ldrsbeq pc, [r7], -r8 */
/* @0x1d0ec0 eorseq r1, r7, r12, lsl #23 */
/* @0x1d0ec4 .word 0xffffbcd4 */
/* @0x1d0ec8 .word 0xffffc7d0 */
/* @0x1d0ecc ldrsbeq pc, [r7], -r8 */

/* ── 7.2 Command_SaveGame(char const* name)  0x1d1468..0x1d14f8 ──
 * 栈: sub sp,#1024 + #12，并在 0x1d1490 存栈金丝雀（GOT 槽 0x3ed958 → 目标 0 处的 TLS 槽；
 *     出口 0x1d14e0 比对，不等就 __stack_chk_fail）。
 * 流程: CreateBuffer(0x20000, format=1, 1) 0xc6ad0 → id → Command_SaveGame(int) 0x1d07c8
 *       （已出卡：序列化进 buffer）→ GetIBuffer(id) → LoadSave::_GetSaveFileName(dst,1024,name)
 *       0x18f964 → LoadSave::WriteFile(filename, buf+0xc, buf+0x1c) 0x18fa3c → FreeIBuffer(id)。
 *       ⇒ buf+0xc = 数据指针、buf+0x1c = 长度（IBuffer 布局，与 Command_LoadGame(str) 的
 *         fread(buf+0xc,1,len,fp) 互为反证）。
 * ★ 名字只经过 _GetSaveFileName 变形（落到存档目录），本函数不自己做路径拼接。
 */


/* ── 入口 + 栈金丝雀（0x1d1468..0x1d1490）── */

/* @0x1d1468 push {r4, r5, r6, r7, lr} */
/* @0x1d146c sub sp, sp, #1024 */
/* @0x1d1470 ldr r4, [pc, #0x80] */
/* @0x1d1474 sub sp, sp, #12 */
/* @0x1d1478 mov r1, #1 */
/* @0x1d147c mov r7, r0 */
/* @0x1d1480 ldr r4, [pc, r4] */
/* @0x1d1484 mov r2, r1 */
/* @0x1d1488 mov r0, #131072 */
/* @0x1d148c ldr r3, [r4] */
/* @0x1d1490 str r3, [sp, #0x404] */

/* ── CreateBuffer + 序列化（0x1d1494..0x1d149c）── */

/* @0x1d1494 bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x1d1498 mov r5, r0 */
/* @0x1d149c bl 0x1d07c8 <_Z16Command_SaveGamei> */

/* ── 取名 + 写文件 + 释放（0x1d14a0..0x1d14d4）── */

/* @0x1d14a0 mov r0, r5 */
/* @0x1d14a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d14a8 mov r2, r7 */
/* @0x1d14ac add r7, sp, #4 */
/* @0x1d14b0 mov r1, #1024 */
/* @0x1d14b4 mov r6, r0 */
/* @0x1d14b8 mov r0, r7 */
/* @0x1d14bc bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1d14c0 ldr r2, [r6, #0x1c] */
/* @0x1d14c4 ldr r1, [r6, #0xc] */
/* @0x1d14c8 mov r0, r7 */
/* @0x1d14cc bl 0x18fa3c <_ZN8LoadSave9WriteFileEPKcS1_i> */
/* @0x1d14d0 mov r0, r5 */
/* @0x1d14d4 bl 0xc6a88 <_Z11FreeIBufferi> */

/* ── 金丝雀校验（0x1d14d8..0x1d14f4）── */

/* @0x1d14d8 ldr r2, [sp, #0x404] */
/* @0x1d14dc ldr r3, [r4] */
/* @0x1d14e0 cmp r2, r3 */
/* @0x1d14e4 bne 0x1d14f4 <_Z16Command_SaveGamePKc+0x8c> */
/* @0x1d14e8 add sp, sp, #1024 */
/* @0x1d14ec add sp, sp, #12 */
/* @0x1d14f0 pop {r4, r5, r6, r7, pc} */
/* @0x1d14f4 bl 0xb65d4 <__stack_chk_fail@plt> */

/* ── 池字 0x0021c4d0（= 0x1d1470 那条 ldr 的槽偏移；落在 dynsym size 之外但仍是本函数的字）── */

/* @0x1d14f8 .word 0x0021c4d0 */

/* ── 7.3 Command_LoadGame(char const* name)  0x1d14fc..0x1d168c ──
 * 入口: name == 0 → 0x1d1658 打 "WARNING: Game load failed, null filename passed\n"，返回。
 * 取名（三条支路，0x1d1530/0x1d1540）:
 *   LoadSave::SaveFileExists(name)  0x18fb6c 真 → _GetSaveFileName(dst,1024,name) 0x18f964
 *   LoadSave::BundleFileExists(name) 0x18f8ac 真 → _GetBundleFileName(dst,1024,name) 0x18f78c
 *   都不存在                          → dst 保留原名（0x1d1528 只写了 dst[0]=0，随后 fopen 失败）
 * 读文件: fopen(dst,"rb") 0x18db48；失败 → "WARNING: Game load failed, %s not found\n"（r2 = dst）。
 *   fseek(fp,0,SEEK_END) → ftell → fseek(fp,0,SEEK_SET) → CreateBuffer(len,1,1)
 *   → GetIBuffer → fread(buf+0xc, 1, len, fp) 0x18e070 → fclose。
 * 收尾: Command_LoadGame(int) 0x1d0dd8（登记到 0x5429cc），然后 0x1d15d4 `str r5,[r3+4]`
 *   ⇒ *(int*)0x3f511c = bufid —— 把队列槽从 -1 改成这次要消费的 id。
 *   ⇒ 队列槽的写者只有这一处；清回 -1 的消费者不在本卡（LoadGame() 0x1d1cb4 只清 New_Room）。
 * ★ 三条路径的 "rb" 常量在 0x337c00（池字 0x1666a0）。
 */


/* ── 入口 + 栈金丝雀（0x1d14fc..0x1d1524）── */

/* @0x1d14fc push {r4, r5, r6, r7, lr} */
/* @0x1d1500 sub sp, sp, #1024 */
/* @0x1d1504 ldr r5, [pc, #0x168] */
/* @0x1d1508 sub sp, sp, #12 */
/* @0x1d150c ldr r3, [pc, #0x164] */
/* @0x1d1510 subs r4, r0, #0 */
/* @0x1d1514 add r5, pc, r5 */
/* @0x1d1518 ldr r6, [r5, r3] */
/* @0x1d151c ldr r3, [r6] */
/* @0x1d1520 str r3, [sp, #0x404] */
/* @0x1d1524 beq 0x1d164c <_Z16Command_LoadGamePKc+0x150> */

/* ── name != 0 分支：清零 dst、查 SaveFileExists（0x1d1528..0x1d1538）── */

/* @0x1d1528 mov r3, #0 */
/* @0x1d152c strb r3, [sp, #0x4] */
/* @0x1d1530 bl 0x18fb6c <_ZN8LoadSave14SaveFileExistsEPKc> */
/* @0x1d1534 cmp r0, #0 */
/* @0x1d1538 bne 0x1d15f4 <_Z16Command_LoadGamePKc+0xf8> */

/* ── BundleFileExists 与第三条支路（0x1d153c..0x1d154c）── */

/* @0x1d153c mov r0, r4 */
/* @0x1d1540 bl 0x18f8ac <_ZN8LoadSave16BundleFileExistsEPKc> */
/* @0x1d1544 cmp r0, #0 */
/* @0x1d1548 addeq r7, sp, #4 */
/* @0x1d154c bne 0x1d1634 <_Z16Command_LoadGamePKc+0x138> */

/* ── fopen("rb")（0x1d1550..0x1d1564）── */

/* @0x1d1550 ldr r1, [pc, #0x124] */
/* @0x1d1554 mov r0, r7 */
/* @0x1d1558 add r1, pc, r1 */
/* @0x1d155c bl 0x18db48 <_ZN8LoadSave5fopenEPKcS1_> */
/* @0x1d1560 subs r4, r0, #0 */
/* @0x1d1564 beq 0x1d160c <_Z16Command_LoadGamePKc+0x110> */

/* ── 求长度：fseek end / ftell / fseek 0（0x1d1568..0x1d158c）── */

/* @0x1d1568 mov r1, #0 */
/* @0x1d156c mov r2, #2 */
/* @0x1d1570 bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */
/* @0x1d1574 mov r0, r4 */
/* @0x1d1578 bl 0x18de24 <_ZN8LoadSave5ftellEP7_YYFILE> */
/* @0x1d157c mov r1, #0 */
/* @0x1d1580 mov r2, r1 */
/* @0x1d1584 mov r7, r0 */
/* @0x1d1588 mov r0, r4 */
/* @0x1d158c bl 0x18de30 <_ZN8LoadSave5fseekEP7_YYFILEli> */

/* ── 建 buffer + fread + fclose + 交给 int 版（0x1d1590..0x1d15c8）── */

/* @0x1d1590 mov r1, #1 */
/* @0x1d1594 mov r2, r1 */
/* @0x1d1598 mov r0, r7 */
/* @0x1d159c bl 0xc6ad0 <_Z12CreateBufferi14eBuffer_Formati> */
/* @0x1d15a0 mov r5, r0 */
/* @0x1d15a4 bl 0xc6720 <_Z10GetIBufferi> */
/* @0x1d15a8 mov r3, r4 */
/* @0x1d15ac mov r2, r7 */
/* @0x1d15b0 mov r1, #1 */
/* @0x1d15b4 ldr r0, [r0, #0xc] */
/* @0x1d15b8 bl 0x18e070 <_ZN8LoadSave5freadEPKvjjP7_YYFILE> */
/* @0x1d15bc mov r0, r4 */
/* @0x1d15c0 bl 0x18ddb8 <_ZN8LoadSave6fcloseEP7_YYFILE> */
/* @0x1d15c4 mov r0, r5 */
/* @0x1d15c8 bl 0x1d0dd8 <_Z16Command_LoadGamei> */

/* ── 队列槽 0x3f511c = bufid（0x1d15cc..0x1d15d8）── */

/* @0x1d15cc ldr r3, [pc, #0xac] */
/* @0x1d15d0 add r3, pc, r3 */
/* @0x1d15d4 str r5, [r3, #0x4] */
/* @0x1d15d8 ldr r2, [sp, #0x404] */
/* @0x1d15dc ldr r3, [r6] */
/* @0x1d15e0 cmp r2, r3 */
/* @0x1d15e4 bne 0x1d1670 <_Z16Command_LoadGamePKc+0x174> */
/* @0x1d15e8 add sp, sp, #1024 */
/* @0x1d15ec add sp, sp, #12 */
/* @0x1d15f0 pop {r4, r5, r6, r7, pc} */

/* ── 存档文件存在时的取名支路（0x1d15f4..0x1d1608）── */

/* @0x1d15f4 add r7, sp, #4 */
/* @0x1d15f8 mov r2, r4 */
/* @0x1d15fc mov r1, #1024 */
/* @0x1d1600 mov r0, r7 */
/* @0x1d1604 bl 0x18f964 <_ZN8LoadSave16_GetSaveFileNameEPciPKc> */
/* @0x1d1608 b 0x1d1550 <_Z16Command_LoadGamePKc+0x54> */

/* ── fopen 失败出口（0x1d160c..0x1d1630）── */

/* @0x1d160c ldr r3, [pc, #0x70] */
/* @0x1d1610 mov r2, r7 */
/* @0x1d1614 ldr r1, [pc, #0x6c] */
/* @0x1d1618 ldr r3, [r5, r3] */
/* @0x1d161c add r1, pc, r1 */
/* @0x1d1620 ldr r0, [r3] */
/* @0x1d1624 ldr r3, [r0] */
/* @0x1d1628 ldr r3, [r3, #0xc] */
/* @0x1d162c blx r3 */
/* @0x1d1630 b 0x1d15d8 <_Z16Command_LoadGamePKc+0xdc> */

/* ── bundle 取名支路（0x1d1634..0x1d1648）── */

/* @0x1d1634 add r7, sp, #4 */
/* @0x1d1638 mov r2, r4 */
/* @0x1d163c mov r1, #1024 */
/* @0x1d1640 mov r0, r7 */
/* @0x1d1644 bl 0x18f78c <_ZN8LoadSave18_GetBundleFileNameEPciPKc> */
/* @0x1d1648 b 0x1d1550 <_Z16Command_LoadGamePKc+0x54> */

/* ── name == 0 出口（0x1d164c..0x1d166c）── */

/* @0x1d164c ldr r3, [pc, #0x30] */
/* @0x1d1650 ldr r1, [pc, #0x34] */
/* @0x1d1654 ldr r3, [r5, r3] */
/* @0x1d1658 add r1, pc, r1 */
/* @0x1d165c ldr r0, [r3] */
/* @0x1d1660 ldr r3, [r0] */
/* @0x1d1664 ldr r3, [r3, #0xc] */
/* @0x1d1668 blx r3 */
/* @0x1d166c b 0x1d15d8 <_Z16Command_LoadGamePKc+0xdc> */

/* ── 金丝雀失败 + 六个池字（0x1d1670..0x1d1688）── */

/* @0x1d1670 bl 0xb65d4 <__stack_chk_fail@plt> */
/* @0x1d1674 eoreq r0, r2, r12, lsr r7 */
/* @0x1d1678 .word 0xffffbd00 */
/* @0x1d167c andseq r6, r6, r0, lsr #13 */
/* @0x1d1680 eoreq r3, r2, r0, asr #22 */
/* @0x1d1684 .word 0xffffbac4 */
/* @0x1d1688 andseq pc, r7, r0, ror r8 */

/* ══ 汇总 A：本卡已证（指令级）══════════════════════════════════════════════════════════
 *  A1. Command_CurrentRoom(0x1c9f38) 不是 getter，而是 room_restart：4 条有效指令读
 *      *(int*)0x542958 当目标房号、把本函数唯一实参当 transition_kind 传给 Command_GotoRoom，
 *      没有任何路径返回房号。三个调用者（F_RoomRestart 109bf4 / YYGML_room_restart 10c318 /
 *      F_ActionCurrentRoom 13e6d4）都是 restart 语义 —— 名字与语义的反差是本卡最大的坑。
 *  A2. Command_GotoRoom 的第 2 形参是死参：r1 全函数零引用，且它把 transition_kind
 *      （0x542950）无条件写 0（0x1c9e0c mov r2,#0 → 0x1c9e24 str r2,[r3]）。三个内建入口
 *      （F_RoomGoto 109ad0、F_RoomGotoPrevious 109ae8、F_RoomGotoNext 109afc）都老老实实
 *      从 0x542950 读出来填进去，等于白传。
 *  A3. New_Room（0x542954）是「码」不是纯房号，本卡贡献 4 个写点：GotoRoom 正常 = 房号、
 *      失败 = -400、Prev/Next 越界 = -400、RestartGame = -200；LoadGame() 0x1d1cb4 写 -1。
 *      消费侧 SingleStep 0x1d4dd8 用 cmn 逐码分派（-1/-100/-200/-300/-400/其余），
 *      StartRoom 0x1d3910 入口也写 -1 —— 三处独立同向。
 *  A4. Run_Room（0x54298c，CRoom*）全库唯一写者是 Run_Room_Set 0x1cba58 的一条 str；
 *      它的两个调用点都在 StartRoom（0x1d3944 / 0x1d4244）。房号（0x542958）与它不是一个
 *      东西：前者由 StartRoom 0x1d3938 写、由 CurrentRoom/Prev/Next 与 GV_Room 读。
 *  A5. 参数序是三层三次重排：GML instance_create(x,y,obj) → 命令 Command_Create(obj,x,y)
 *      （1095ac/1095dc）→ CRoom::AddInstance(x,y,obj)（0x1ab144）。place_meeting 同理：
 *      (x,y,obj) → IsMeeting(inst,obj,x,y)（107fd8/108044）→ InstancePlace(inst,x,y,obj)（0x1caa0c）。
 *  A6. IsMeeting 只有 9 条指令，其中 4 条是寄存器搬运、1 条 bl、1 条 !=0 归一 —— 它没有任何
 *      自己的碰撞逻辑，也不对 obj 做特殊值处理；-1/-2/-4 的语义全在内建层 F_PlaceMeeting
 *      （0x107fdc..0x10800c）里被就地改写。
 *  A7. place_empty 与 place_free 的唯一差别是 inst+0x66 的 solid 过滤（0x1cacd8）与 RTree 回调
 *      （0x1c8744 vs 0x1c87d8）；两条路径都会临时挪动 inst 再还原。
 *  A8. Command_EndGame 是空实现（一条 bx lr，5 个调用者全是 b 尾跳），与 Command_Change.c 附注一致。
 *  A9. Command_RestartGame 写的是 -200（mvn r1,#199）；Command_Change.c 附注里的 "-201" 应更正为 -200
 *      （第二证据：SingleStep 0x1d4df8 `cmn r0,#200`）。本卡只陈述，不改别人的卡。
 *  A10. 三个 Create 尾部完全同构：Perform_Event(inst,inst,14,0) → Perform_Event(inst,inst,0,0)
 *      → inst+0x6c = 1。+0x6c 在本卡只证「新建完置 1」，语义名未证。
 *  A11. 四个 Create 的错误出口刻意不统一：对象不存在走 Error_Show_Action(str,0)（非致命），
 *      层不存在：id 版走 vtable 派发器、name 版走 YYError —— 与 3.3/3.4 的地址一一对应。
 *  A12. LoadGame(int) 只做三件事：查队列槽（-1 才放行）、登记 0x5429cc、返回 1；
 *      LoadGame(str) 追加文件 IO 并把 0x3f511c 写成 bufid。解析全在 LoadGame() 0x1d1cb4。
 *
 * ══ 汇总 B：open（本卡没证到的）════════════════════════════════════════════════════════
 *  B1. 0x54297a（SingleStep 在 -100/-400 分支清零的字节）语义未证；本卡只引用地址。
 *  B2. inst+0x6c 的字段名未证（只证「Create 末尾置 1」与 ctor 清零）。
 *  B3. inst+0x64（IsEmpty/IsFree 里决定要不要 Compute_BoundingBox 的字节）语义名未证。
 *  B4. inst+0x66（IsFree 的 solid 过滤依据）语义名未证 —— 只证「非 0 才参与 place_free」。
 *  B5. 对象表 0x542374 与 id 表 0x536f28 的初始化者、mask 的增长策略未追（属 Builtins_Object 侧）。
 *  B6. Sprite_Data+0x1c / +0x20 两个字段只证「乘缩放后当绕回量」，字段名未证。
 *  B7. Command_LoadGame(str) 的 0x3f511c 谁清回 -1 未定位（LoadGame() 0x1d1cb4 不清它）——
 *      若无人清，第二次 game_load 会被 7.1 的队列闸挡掉，这条要么是死代码要么消费者在别处。
 *  B8. Error_Show_Action 第 2 实参的语义（GotoRoom 传 0、Prev/Next 传 1、其余族传 0）未证。
 *
 * ══ 汇总 C：对重建方的约束（从上面推出来的，不是新事实）════════════════════════════════
 *  C1. 不要把 room_restart 实现成「读 room 变量」——必须走 GotoRoom(当前房号)。
 *  C2. 不要给 GotoRoom 造第二参语义；本 build 里它被丢弃，重建时保留形参即可。
 *  C3. 换房必须是「写信箱 + 帧末消费」，命令层直接切房会与 SingleStep 的 -400/-200/-300 分派打架。
 *  C4. Create 的四个变体必须保留各自的错误出口行为（致命/非致命混用）。
 *  C5. move_contact 是「先判后走」，move_outside 是「先走后判」——两者不能共用一个循环。
 */
