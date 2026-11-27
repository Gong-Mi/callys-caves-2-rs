/* cally 逆向卡：Perform_Event_Object（原版 libyoyo.so，armv7）
 * @func 0xf32e4 0xf3380  size 156  39 条（36 条指令 + 末 3 字 0xf3374..0xf337c 为 literal pool）
 * 级别: 正文（39/39 逐条落锚；三道门、类型白名单、执行器尾调与 5 个全局全部定名/定量）
 * 符号: _Z20Perform_Event_ObjectP9CInstanceS0_iii →
 *       void Perform_Event_Object(CInstance* inst, CInstance* other, int objindex, int type, int num)
 * 位置: 紧接 Perform_Event(0xf3380) 之前；前一是 Perform_Event_Object_ASync(0xf31f8)、
 *       Perform_Event_TimeLine(0xf30ec)
 * 同层: Perform_Event_Object_ASync 0xf31f8（本函数唯一的尾调目标，才是真正的执行器）、
 *       Find_Event 0xf2e80、CEvent::Execute 0xf2e34、Perform_Event_All 0xf33b0
 *
 * ── 语义草案 ────────────────────────────────────────────────────────────────
 *   void Perform_Event_Object(CInstance* inst, CInstance* other, int objindex, int type, int num) {
 *     if (type == 12) {                                     // 0xf32e4 / 0xf32f0
 *        if (*(char*)0x47f3c4 /*Code_Error_Occured*/) return;     // 0xf3354..0xf3364
 *        goto run;
 *     }
 *     if (*(int*)0x542954 /*New_Room*/ == -1) goto run;      // 0xf32f4..0xf3304：不在换房流程 → 一律执行
 *     if (inst->[0x67] /*persistent*/ != 0) goto type_filter;      // 0xf3308..0xf3310
 *     if (((CRoom*)*(void**)0x54298c /*Run_Room*/)->[0x18] /*room_persistent*/ != 0)
 *           goto type_filter;                                // 0xf3314..0xf3328
 *     return;                                                // 0xf332c：换房中、非持久实例、房间也不持久 → 丢弃
 *   type_filter:
 *     if (type == 14 || type <= 2 || type == 7) goto run;    // 0xf3334..0xf3344
 *     return;
 *   run:
 *     Perform_Event_Object_ASync(inst, other, objindex, type, num);   // 0xf3348..0xf3350 / 0xf3368..0xf3370
 *   }
 *
 * ── 门表（按执行顺序；换房期 = New_Room != -1）──────────────────────────────
 *   ① type == 12 ？
 *        是 → *Code_Error_Occured != 0 ? 丢弃 : 执行      （不看 New_Room、+0x67、房间标志）
 *        否 → ②
 *   ② New_Room == -1 ？（没有待切换的房间 = 正常游戏内派发）
 *        是 → 执行
 *        否 → ③
 *   ③ inst+0x67（persistent）!= 0 或 CRoom+0x18（room_persistent）!= 0 ？
 *        否 → 丢弃                                         （换房期的非持久实例，房间也不持久）
 *        是 → ④
 *   ④ type ∈ {0,1,2,7,14} ？
 *        是 → 执行；否 → 丢弃
 *   ⇒ 换房期放行的集合 = {0 Create, 1 Destroy, 2 Alarm, 7 Other, 14 PreCreate} ∪ {12 CleanUp}；
 *      3 Step/4 Collision/5..6/8 Draw/9..11/13 Gesture/15+ 一律丢弃。
 *      （事件号→名字是 GM 惯例，卡内只证集合；12=CleanUp 有 DoDestroy 卡的旁证）
 *   ⇒ 语义读法：房间持久 ⇒ 房间里的实例不随换房销毁，所以它们照样收换房前后的这几个事件。
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1. 第 5 实参（num）在入口被搬到 r4：0xf32e8 str r4,[sp,#-4]! 先把 r4 压栈，0xf32ec ldr r4,[sp,#4]
 *     再读回调用者的 [sp]（= 第 5 个整型实参）。两条出口都 str r4,[sp,#4] + ldr r4,[sp],#4 还原栈帧，
 *     所以 ASync 看到的是与调用者完全相同的 5 实参布局。
 *  2. 12 号门在最前：cmp r3,#12 + beq 0xf3354 先于 New_Room 检查 ⇒ CleanUp 不受换房/持久性影响，
 *     只受 Code_Error_Occured（0x47f3c4，.dynsym 有名字）抑制：非 0 就整条丢弃。
 *  3. New_Room（0x542954，.bss 4B）用 cmn r12,#1 判 -1；等于 -1 表示没有待切换的房间 → 直接放行。
 *     同一全局在 Perform_Event_All(0xf33cc) 里是「不等于 -1 就整体返回」，两处口径一致。
 *  4. Run_Room（0x54298c）存 CRoom*；0xf331c 解一次得到房间指针，0xf3320 读它的 +0x18 字节。
 *     该字节 = room_persistent：F_RoomSetPersistent 0x12e73c 写它、GV_RoomPersistent 0x1f7c58 读它、
 *     CRoom::CRoom 0x1ad4c4 清零 ⇒ 不是猜测。
 *  5. 类型白名单是 cmp r3,#14 / cmpne r3,#2 / bls 三连：r3==14 时 cmpne 被跳过、标志来自 cmp #14
 *     （C=1,Z=1 → LS 成立）；r3!=14 时标志来自与 2 的无符号比较（type<=2）。之后再 cmp #7 / bne 丢弃。
 *     即 {0,1,2,14} ∪ {7}，没有别的入口。
 *  6. 两个"执行"出口都是 b（尾跳）到 0xf31f8 <Perform_Event_Object_ASync>，不是 bl：
 *     本函数没有自己的 epilogue 之后还要执行的代码，r4 已在跳前弹出。
 *  7. literal pool 三字是绝对 GOT 槽（不是 GOT 基址偏移）：
 *     0xf3374 = 0x002faaac → 0xf3300+该值 = 0x3EDDAC → 0x542954（New_Room）
 *     0xf3378 = 0x002fa610 → 0xf3320+该值 = 0x3ED930 → 0x54298c（Run_Room）
 *     0xf337c = 0x002fa80c → 0xf3360+该值 = 0x3EDB6C → 0x47f3c4（Code_Error_Occured）
 *  8. 执行器（0xf31f8，不在本卡锚点内）做的事：Find_Event(objindex,type,num,&found) → 空则返回；
 *     全局递归计数 0x48340c 先自增再与 32 比较，超过就 Error_Show_Action(
 *     "PerformEvent recursion depth failure - check for infinite loops, check objects for parenting")，
 *     然后自减返回（事件不执行）；成功路径把 Current_Object(0x54290c)/Current_Event_Type(0x542908)/
 *     Current_Event_Number(0x542904) 三个全局压栈保存、改成 (found,type,num)、CEvent::Execute(inst,other)、
 *     再原样恢复。名字里的 ASync 与行为不符：它是同步执行器。
 *  9. 名字来源：三个 Current_* 与 New_Room/Run_Room/Code_Error_Occured 都是 .dynsym 里的全局符号；
 *     GV_EventType/GV_EventNumber/GV_EventObject(0x1f88d4/0x1f8914/0x1f8954) 正是读这三个全局。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · type 12 之外的「CleanUp 抑制」为什么挂在 Code_Error_Occured 上（错误发生后不再跑清理事件）——
 *    行为确定，动机未证。
 *  · +0x67 的「persistent」定性来自 SetObjectIndex 的位提取（objflags bit2）+ GV_Persistent 同址读取，
 *    本卡只证"这一位参与换房门"。
 *  · objindex 为负时本函数不校验，直接下传 Find_Event（未证其边界行为）。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */

/* ── 1. 入口：先判 type==12，并把第 5 实参（num）从调用者栈上取进 r4（0xf32e4..0xf32f0）───── */
/* @0xf32e4 cmp r3, #12 */
/* @0xf32e8 str r4, [sp, #-0x4]! */
/* @0xf32ec ldr r4, [sp, #0x4] */
/* @0xf32f0 beq 0xf3354 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x70> */
/* ── 2. New_Room 门：== -1（无待切换房间）就直奔执行器（0xf32f4..0xf3304）──────────────── */
/* @0xf32f4 ldr r12, [pc, #0x78] */
/* @0xf32f8 ldr r12, [pc, r12] */
/* @0xf32fc ldr r12, [r12] */
/* @0xf3300 cmn r12, #1 */
/* @0xf3304 beq 0xf3348 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x64> */
/* ── 3. 换房期第一道放行条件：实例自身持久（inst+0x67 != 0）（0xf3308..0xf3310）─────────── */
/* @0xf3308 ldrb r12, [r0, #0x67] */
/* @0xf330c cmp r12, #0 */
/* @0xf3310 bne 0xf3334 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x50> */
/* ── 4. 换房期第二道放行条件：Run_Room→CRoom+0x18（room_persistent）!= 0；都不满足则丢弃（0xf3314..0xf3330）── */
/* @0xf3314 ldr r12, [pc, #0x5c] */
/* @0xf3318 ldr r12, [pc, r12] */
/* @0xf331c ldr r12, [r12] */
/* @0xf3320 ldrb r12, [r12, #0x18] */
/* @0xf3324 cmp r12, #0 */
/* @0xf3328 bne 0xf3334 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x50> */
/* @0xf332c ldr r4, [sp], #4 */
/* @0xf3330 bx lr */
/* ── 5. 类型白名单：{0,1,2,14}（cmp #14 / cmpne #2 / bls）再并上 7；其余丢弃（0xf3334..0xf3344）── */
/* @0xf3334 cmp r3, #14 */
/* @0xf3338 cmpne r3, #2 */
/* @0xf333c bls 0xf3348 <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x64> */
/* @0xf3340 cmp r3, #7 */
/* @0xf3344 bne 0xf332c <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x48> */
/* ── 6. 执行出口 A：还原第 5 实参槽 + 弹 r4，尾跳 Perform_Event_Object_ASync（0xf3348..0xf3350）── */
/* @0xf3348 str r4, [sp, #0x4] */
/* @0xf334c ldr r4, [sp], #4 */
/* @0xf3350 b 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* ── 7. type==12（CleanUp）专用门：Code_Error_Occured 非 0 就丢弃，否则同一条执行出口 B（0xf3354..0xf3370）── */
/* @0xf3354 ldr r12, [pc, #0x20] */
/* @0xf3358 ldr r12, [pc, r12] */
/* @0xf335c ldrb r12, [r12] */
/* @0xf3360 cmp r12, #0 */
/* @0xf3364 bne 0xf332c <_Z20Perform_Event_ObjectP9CInstanceS0_iii+0x48> */
/* @0xf3368 str r4, [sp, #0x4] */
/* @0xf336c ldr r4, [sp], #4 */
/* @0xf3370 b 0xf31f8 <_Z26Perform_Event_Object_ASyncP9CInstanceS0_iii> */
/* ── 8. literal pool（3 字，反汇编器译成指令，实为数据）──────────────────────────
 *   0xf3374 = 0x002faaac → 0x3EDDAC → New_Room(0x542954)
 *   0xf3378 = 0x002fa610 → 0x3ED930 → Run_Room(0x54298c)
 *   0xf337c = 0x002fa80c → 0x3EDB6C → Code_Error_Occured(0x47f3c4)
 */
/* @0xf3374 eoreq r10, pc, r12, lsr #21 */
/* @0xf3378 eoreq r10, pc, r0, lsl r6 */
/* @0xf337c eoreq r10, pc, r12, lsl #16 */
