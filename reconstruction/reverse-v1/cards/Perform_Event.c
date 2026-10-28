/* cally 逆向卡：Perform_Event（原版 libyoyo.so，armv7）
 * @func 0xf3380 0xf33b0  size 48  12 条（无 literal 池、无栈 canary）
 * 级别: 正文（12/12 逐条落锚；唯一分支、实参转位、被调函数、nullptr 短路全证）
 * 符号: _Z13Perform_EventP9CInstanceS0_ii → void Perform_Event(CInstance* inst, CInstance* other, int type, int num)
 * 位置: 紧接 Perform_Event_Object(0xf32e4) 之后；其后是 Perform_Event_All(0xf33b0)
 * 同层: Perform_Event_Object 0xf32e4（本函数唯一的被调）、Perform_Event_Object_ASync 0xf31f8、
 *       Perform_Event_TimeLine 0xf30ec、Perform_Event_All 0xf33b0
 *
 * ── 语义草案 ────────────────────────────────────────────────────────────────
 *   void Perform_Event(CInstance* inst, CInstance* other, int type, int num) {
 *     if (!inst) return;                                   // 0xf3390
 *     Perform_Event_Object(inst, other, inst->[0x7c], type, num);
 *   }
 *   ⇒ 调用方只给「实例 + 类型 + 子号」，对象索引由实例自己带（+0x7c 由 SetObjectIndex 写）。
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1. 五个寄存器/栈位的落位：r0=inst、r1=other、r2=type、r3=num。
 *     0xf3388 mov r4,r3 把 num 存进 callee-saved；0xf339c str r4,[sp] 把它摆成被调函数的第 5 实参；
 *     0xf3398 mov r3,r2 把 type 挪到 r3（第 4 实参）；0xf33a0 mov r2,r12 把 inst->[0x7c] 当第 3 实参；
 *     r1 从入口到调用一次都没被写 ⇒ other 原样下传。
 *  2. nullptr 短路：0xf3380 subs r12,r0,#0 设标志，隔了 push / mov r4,r3 / sub sp 三条不带 s 的指令
 *     （都不改 CPSR）后 0xf3390 beq 仍成立 ⇒ inst==0 直接跳到 0xf33a8 收尾，
 *     other/type/num 一个都不读、也不会有任何事件派发。
 *  3. 被调函数是 bl 0xf32e4 <Perform_Event_Object>，不是尾跳：本函数有自己的
 *     0xf33a8 add sp,#8 / 0xf33ac pop {r4,pc} 出口，栈帧 8 字节只是为了给第 5 实参留槽（AAPCS 栈对齐）。
 *  4. 本函数不读全局、不碰 +0x68/+0x69/+0x67（三道闸门都在 0xf32e4 里），也不做任何返回值处理：
 *     void，且 r0 里留着 Perform_Event_Object 的残留值，调用者不得把它当返回值用。
 *  5. 交叉：DoDestroy(0x10b0fc) 以 type=12 调本函数 ⇒ 事件号 12 的派发链是
 *     DoDestroy → Perform_Event → Perform_Event_Object(inst,inst,inst->[0x7c],12,0)；
 *     DoDestroy 卡里"立刻转 Perform_Event_Object"这一句在本卡逐条落地（含 +0x7c 的来源）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 无。本函数 12 条全部可达，语义闭合。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */

/* ── 1. 入口：inst 空判（subs 设标志）+ 保 num 到 r4，8 字节帧（0xf3380..0xf338c）──── */
/* @0xf3380 subs r12, r0, #0 */
/* @0xf3384 push {r4, lr} */
/* @0xf3388 mov r4, r3 */
/* @0xf338c sub sp, sp, #8 */
/* @0xf3390 beq 0xf33a8 <_Z13Perform_EventP9CInstanceS0_ii+0x28> */
/* ── 2. 取实例自带的对象索引 → 重排实参：r3=type、[sp]=num、r2=objindex、r1=other（0xf3394..0xf33a0）── */
/* @0xf3394 ldr r12, [r12, #0x7c] */
/* @0xf3398 mov r3, r2 */
/* @0xf339c str r4, [sp] */
/* @0xf33a0 mov r2, r12 */
/* ── 3. 唯一调用：Perform_Event_Object(inst, other, inst->[0x7c], type, num)（0xf33a4）───── */
/* @0xf33a4 bl 0xf32e4 <_Z20Perform_Event_ObjectP9CInstanceS0_iii> */
/* ── 4. 出口（nullptr 路径与正常路径共用一条 epilogue）（0xf33a8..0xf33ac）───────── */
/* @0xf33a8 add sp, sp, #8 */
/* @0xf33ac pop {r4, pc} */
