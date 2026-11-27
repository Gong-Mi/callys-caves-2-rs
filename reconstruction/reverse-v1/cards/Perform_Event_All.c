/* cally 逆向卡：Perform_Event_All（原版 libyoyo.so，armv7）
 * @func 0xf33b0 0xf344c  size 156  39 条（37 条指令 + 末二字 f3444/f3448 为 literal pool）
 * 级别: 正文（37/37 逐条落锚；两道入口门、两道逐实例闩、五个实参的落位、链表起点与步进、
 *       两次两级 GOT 解析全部实测；字段名与事件号名字依赖跨卡，逐条注明出处）
 * 符号: _Z17Perform_Event_Allii → void Perform_Event_All(int type, int num)
 * 位置: 紧跟 Perform_Event(0xf3380) 之后；0xf344c 起是下一个函数 StepToStri(int)
 * 调用者: 全 .text 精确 9 处（扫全部 B/BL 编码：7 bl + 2 b）——
 *       DoAStep 1d35d8 All(8,65)；StartRoom 1d3e08 All(7,4)、StartRoom 1d41d0 All(7,2)；
 *       EndRoom 1d1784 All(7,5)、EndRoom 1d1ad0 All(7,3)；
 *       SV_Lives 1fb32c 与 F_ActionSetLife 140c70 All(7,6)（lives 归零时）；
 *       SV_Health 1fb3a4 与 F_ActionSetHealth 140cdc All(7,9)（health 归零时）
 * 同层: Perform_Event 0xf3380、Perform_Event_Object 0xf32e4、Perform_Event_Object_ASync 0xf31f8、
 *       Find_Event 0xf2e80、CEvent::Execute 0xf2e34
 *
 * ── 一句话 ─────────────────────────────────────────────────────
 *   「对当前房间里所有还在链上的实例，各派同一个事件」：只有在没有待切换房间（New_Room == -1）、
 *   Run_Room 存在且实例链非空时才工作；逐个实例跳过 +0x68（已销毁）与 +0x69（已 deactivate），
 *   其余一律以 other = 自身、objindex = inst->[0x7c] 调 Perform_Event_Object。本函数自己不改任何内存。
 *
 * ── 语义草案 ───────────────────────────────────────────────────
 *   void Perform_Event_All(int type, int num) {
 *     if (*(int*)0x542954（New_Room）!= -1) return;          // f33b0..f33d0
 *     CRoom* room = *(CRoom**)0x54298c（Run_Room）;           // f33dc..f33e4
 *     if (!room) return;                                      // f33e8..f33ec
 *     CInstance* inst = room->[0x80]（实例链尾）;              // f33f0..f33f8
 *     while (inst) {
 *        CInstance* next = inst->[0x178];                     // f3400：先取后继，再派事件
 *        if (!inst->[0x68] && !inst->[0x69])                  // f33fc..f3420：skip / deactivated
 *           Perform_Event_Object(inst, inst, inst->[0x7c], type, num);   // f3424..f342c
 *        inst = next;                                         // f3430..f3438
 *     }
 *   }
 *
 * ── 与 Perform_Event / Perform_Event_Object 的关系（本卡重点）─────────────
 *   三层是一条链，参数形态逐层是 (inst,other,type,num) → (type,num) → (inst,other,objindex,type,num)：
 *     Perform_Event(inst, other, type, num)                   0xf3380
 *        = if (!inst) return;
 *          Perform_Event_Object(inst, other, inst->[0x7c], type, num);   ← 唯一 bl 0xf32e4
 *     Perform_Event_All(type, num)                            0xf33b0（本卡）
 *        = if (New_Room != -1) return;
 *          for (inst ∈ Run_Room 的实例链)
 *             Perform_Event_Object(inst, inst, inst->[0x7c], type, num); ← 唯一 bl 0xf32e4
 *     Perform_Event_Object(inst, other, objindex, type, num)   0xf32e4
 *        = 三道闸（type12×Code_Error_Occured / New_Room+persistent 白名单 / 类型白名单）
 *          → 尾调真正的执行器 Perform_Event_Object_ASync(inst, other, objindex, type, num)
 *   三点差别，全部由指令证：
 *     a) All 不经过 Perform_Event：本卡 39 条里只有一条 bl，目标是 0xf32e4；Perform_Event 的入口
 *        0xf3380 在本卡一次都没出现。⇒ All 是「Perform_Event 的批量版」，不是它的调用者之一。
 *        旁证（全库调用点计数）：Perform_Event 70 处（65 bl + 5 b）、Perform_Event_Object 7 处
 *        （4 bl + 3 b）；All 就是那 4 个 bl 里的一个，另三个是 Perform_Event 0xf33a4、StartRoom
 *        0x1d407c / 0x1d40fc；3 个 b 分别是 F_EventObject 1146a8、F_EventInherited 116984、
 *        F_ActionInherited 141374。
 *     b) other 固定 = inst：All 把 r1 也设成 inst（f3414），处理器看到的 other 恒为自身；
 *        Perform_Event 则原样下传调用方给的 other（Perform_Event 卡：r1 全程没被写）。
 *     c) 自己的门多两道：入口要求 New_Room == -1（Perform_Event 根本不查这个全局；
 *        Perform_Event_Object 用同一全局但极性相反 —— 只有 != -1 才进换房白名单），
 *        逐实例再按 +0x68/+0x69 跳过（Perform_Event 与 Perform_Event_Object 都不查这两个字节）。
 *   合起来看（两条函数的锚点都已落地，属组合推断）：All 只在「没有待切换房间」时工作，此刻
 *   Perform_Event_Object 的第 ② 道门恒为放行 ⇒ 换房白名单 {0,1,2,7,14} 对 All 不起过滤作用，
 *   能拦下 All 的只有「type == 12 且 Code_Error_Occured != 0」这一条。反过来，若某个处理器在
 *   广播途中触发换房（把 New_Room 写成非 -1），剩余实例就会被 Perform_Event_Object 的门 ③④
 *   （persistent / room_persistent、类型白名单）截断 —— All 自己的 New_Room 门只在入口查一次。
 *
 * ── 门表（按执行顺序；全部实测）────────────────────────────────
 *   ① New_Room(0x542954) == -1 ？          f33b0..f33d0    否 → 直接返回
 *   ② Run_Room(0x54298c) != 0 ？           f33dc..f33ec    否 → 返回
 *   ③ Run_Room->[0x80] != 0 ？（链尾）       f33f0..f33f8    否 → 返回（空房间）
 *   ④ 逐实例 inst->[0x68] == 0 ？           f33fc..f3408    非 0 → 跳过该实例
 *   ⑤ 逐实例 inst->[0x69] == 0 ？           f340c..f3420    非 0 → 跳过该实例
 *   ⇒ ④⑤ 只是「跳过这个实例」，两个 bne 都跳到 f3430 步进；循环不会因为跳过而中断。
 *
 * ── 全局/字段表（全部实测；名字凡未在本卡证过的都标出处）──────────────
 *   全局（.bss）
 *     0x542954 int    New_Room  本卡要求 == -1。同一全局：Perform_Event_Object 卡是换房门，
 *                                StartRoom 卡是「退出/中断码闸门」（入口无条件写 -1）
 *     0x54298c CRoom* Run_Room  当前房间；写入口 Run_Room_Set 0x1cba58（StartRoom 卡）
 *   CRoom
 *     +0x80  CInstance*  实例链尾（+0x84 才是链头；本卡从链尾起走）
 *   CInstance
 *     +0x178 CInstance*  next（朝链头方向；+0x17c 朝链尾）—— StartRoom 卡 + CRoom::DeSerialise
 *                        1acd90..1acda4 的尾插实测
 *     +0x68  byte  skip（已销毁）—— Command_Destroy 置 1；DoPushEnv 的 with 遍历、本函数、
 *                  DrawInstancesOnly 都按它跳过（Command_Destroy 卡）
 *     +0x69  byte  deactivated
 *     +0x7c  int   object_index（喂 Perform_Event_Object 的第 3 实参）
 *   写集: 只有一条 str r6,[sp]（f3428，给被调函数摆第 5 实参）—— 本函数不改任何内存。
 *
 * ── 已证（指令级）─────────────────────────────────────────────
 *  1. 两个全局的两级 GOT 解析（槽内值是从二进制读出来的，不是按名字推的）：
 *     · f33b0 ldr r2,[pc,#0x8c] 取池字 f3444 = 0x002fa9ec；f33b8 ldr r2,[pc,r2]（PC=f33c0）
 *       ⇒ 地址 0x3eddac，槽内实测 = 0x542954 ⇒ r2 = &New_Room；f33c4 ldr r3,[r2] 取值。
 *     · f33dc ldr r3,[pc,#0x64] 取池字 f3448 = 0x002fa548；f33e0 ldr r3,[pc,r3]（PC=f33e8）
 *       ⇒ 地址 0x3ed930，槽内实测 = 0x54298c ⇒ &Run_Room；f33e4 取值。
 *  2. New_Room 的判据是 cmn r3,#1（f33cc）——与 -1 相加看进位，和 Perform_Event_Object 卡
 *     0xf3300 的写法逐字相同。三个提前返回（f33d0 / f33ec / f33f8）共用 f33d4..f33d8 一条出口。
 *  3. Run_Room 的空判是 f33e8 cmp r3,#0 / f33ec beq，不是 cmn：脏值（例如 -1）不会被当成空房间。
 *  4. 链表起点是 room+0x80（链尾），步进是 inst+0x178（朝链头）⇒ 派发顺序与链顺序相反。
 *     链在 CRoom::DeSerialise 里按 depth 降序插入（1acd74..1acd8c 的 vcmpe/bge + 1acd90..1acda4
 *     的尾插），所以等价于「depth 升序派发」—— 后一句依赖 +0x184 = depth 缓存（StartRoom 卡），
 *     属跨卡推断。
 *  5. 后继在派发之前取：f3400 ldr r4,[r2,#0x178] 在 f342c 的 bl 之前，且 r4 是 callee-saved
 *     ⇒ 处理器销毁/摘链当前实例也不会打断本轮遍历（f3430..f3438 用 r4 前进）。这与 Command_Destroy
 *     卡「+0x68 只是闩、不摘链」互补。
 *  6. 两把闩都是「先取后继 → 判 → 跳过但前进」：f33fc ldrb r12,[r2,#0x68] / f3404 cmp /
 *     f3408 bne 0xf3430；f340c ldrb r12,[r2,#0x69] / f341c cmp / f3420 bne 0xf3430。
 *     被跳过的实例不改写任何东西。
 *  7. 五实参落位的顺序有讲究：f3410 mov r0,r2、f3414 mov r1,r2 先把 inst 摆进前两参，
 *     f3418 mov r3,r5 把 type 摆进第 4 参，f3424 ldr r2,[r2,#0x7c] 最后才覆盖 r2（此时 r2 已被
 *     消费完），f3428 str r6,[sp] 把 num 摆到第 5 参。type/num 存在 callee-saved 的 r5/r6
 *     ⇒ 处理器改不了本轮剩下的 type/num。
 *  8. 本函数只有一条 bl（f342c → 0xf32e4），没有 bl 到 0xf3380；唯一的内存写是 f3428 的 str r6,[sp]。
 *  9. 帧：push {r4,r5,r6,lr}（16 B）+ sub sp,#8（f33bc）= 24 B，[sp] 正好是 Perform_Event_Object
 *     的第 5 实参槽（AAPCS 8 字节对齐）；两条出口（f33d4..f33d8 / f343c..f3440）都 add sp,#8 后
 *     pop 四个寄存器，没有半开栈帧。
 * 10. 调用者与事件号：9 个调用点、7 个不同 (type,num) 组合 —— All(8,65)、(7,2)、(7,3)、(7,4)、
 *     (7,5)、(7,6)、(7,9)。7/6 与 7/9 只出现在 lives / health 归零处（SV_Lives 1fb2f4..1fb304
 *     的 cmp/ble、SV_Health 1fb378..1fb380 的 vcmpe/bls），与 GM 的 No More Lives(6) /
 *     No More Health(9) 对齐；7/2、7/4 落在 StartRoom，7/3、7/5 落在 EndRoom；8/65 落在 DoAStep
 *     的 pending-draw 段（65 按 GM 的 draw 子事件表对应 Draw GUI Begin）。编号与调用点实测，
 *     名字是 GM 常量表的推断。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 链的方向与顺序（+0x80 = 链尾、+0x178 朝链头、链按 depth 降序）来自 StartRoom 卡与
 *    CRoom::DeSerialise 的跨卡实测；本卡只证「起点 room+0x80、步进 +0x178」。
 *  · +0x68 / +0x69 的语义名来自 Command_Destroy / DoDestroy 卡；本卡只证「非 0 就跳过该实例」。
 *  · New_Room 的「换房请求」语义来自 Perform_Event_Object / StartRoom 卡。
 *  · 事件号 7/x 与 8/65 的名字来自 GM 常量表与调用点上下文；本二进制没有事件名表可对。
 *  · 本函数只遍历 Run_Room 这一条链：其它房间的实例、以及已摘链但未释放的实例都收不到广播；
 *    哪些实例会处于这些状态，本卡不穷举。
 *  · 「广播途中换房会截断剩余实例」是两条函数锚点的组合推断，本卡未做运行时验证。
 *  · DoAStep 那个 All(8,65) 的 65 具体语义未钉（DoAStep 卡同 open）。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────────
 */

/* ── 1. 入口：取 &New_Room 的池字 + 压帧（f33b0..f33b8）──────────────────────────
 *    f33b0 取池字（f3444），f33b8 用它做 PC 相对寻址拿到 GOT 槽 0x3eddac；push 在两条之间。
 */

/* @0xf33b0 ldr r2, [pc, #0x8c] */
/* @0xf33b4 push {r4, r5, r6, lr} */
/* @0xf33b8 ldr r2, [pc, r2] */

/* ── 2. 存实参 + New_Room 门 + 三个提前返回共用的那段出口（f33bc..f33d8）─────────────
 *    r5=type、r6=num 都进 callee-saved；cmn r3,#1 命中 -1 才继续。
 */

/* @0xf33bc sub sp, sp, #8 */
/* @0xf33c0 mov r5, r0 */
/* @0xf33c4 ldr r3, [r2] */
/* @0xf33c8 mov r6, r1 */
/* @0xf33cc cmn r3, #1 */
/* @0xf33d0 beq 0xf33dc <_Z17Perform_Event_Allii+0x2c> */
/* @0xf33d4 add sp, sp, #8 */
/* @0xf33d8 pop {r4, r5, r6, pc} */

/* ── 3. Run_Room 门：空房间直接返回（f33dc..f33ec）────────────────────────────── */

/* @0xf33dc ldr r3, [pc, #0x64] */
/* @0xf33e0 ldr r3, [pc, r3] */
/* @0xf33e4 ldr r3, [r3] */
/* @0xf33e8 cmp r3, #0 */
/* @0xf33ec beq 0xf33d4 <_Z17Perform_Event_Allii+0x24> */

/* ── 4. 取实例链尾；空链返回（f33f0..f33f8）───────────────────────────────────── */

/* @0xf33f0 ldr r2, [r3, #0x80] */
/* @0xf33f4 cmp r2, #0 */
/* @0xf33f8 beq 0xf33d4 <_Z17Perform_Event_Allii+0x24> */

/* ── 5. 循环头：先预取后继 r4，再看 +0x68 闩（f33fc..f3408）───────────────────────── */

/* @0xf33fc ldrb r12, [r2, #0x68] */
/* @0xf3400 ldr r4, [r2, #0x178] */
/* @0xf3404 cmp r12, #0 */
/* @0xf3408 bne 0xf3430 <_Z17Perform_Event_Allii+0x80> */

/* ── 6. +0x69 闩 + 五实参落位 + 唯一 bl（f340c..f342c）─────────────────────────────
 *    r0=r1=inst 先摆好，r3=type，r2 最后才被 objindex 覆盖，num 走栈。
 */

/* @0xf340c ldrb r12, [r2, #0x69] */
/* @0xf3410 mov r0, r2 */
/* @0xf3414 mov r1, r2 */
/* @0xf3418 mov r3, r5 */
/* @0xf341c cmp r12, #0 */
/* @0xf3420 bne 0xf3430 <_Z17Perform_Event_Allii+0x80> */
/* @0xf3424 ldr r2, [r2, #0x7c] */
/* @0xf3428 str r6, [sp] */
/* @0xf342c bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */

/* ── 7. 步进与出口：r2 每次用 r4 复位，链走完就收帧（f3430..f3440）─────────────────── */

/* @0xf3430 cmp r4, #0 */
/* @0xf3434 mov r2, r4 */
/* @0xf3438 bne 0xf33fc <_Z17Perform_Event_Allii+0x4c> */
/* @0xf343c add sp, sp, #8 */
/* @0xf3440 pop {r4, r5, r6, pc} */

/* ── literal pool 二字（非指令）：f3444 = 0x002fa9ec → 槽 0x3eddac；
 *                              f3448 = 0x002fa548 → 槽 0x3ed930
 *    f33c0 + 0x002fa9ec = 0x3eddac；f33e8 + 0x002fa548 = 0x3ed930。objdump 译成 eoreq，非指令。
 */

/* @0xf3444 eoreq r10, pc, r12, ror #19 */
/* @0xf3448 eoreq r10, pc, r8, asr #10 */

