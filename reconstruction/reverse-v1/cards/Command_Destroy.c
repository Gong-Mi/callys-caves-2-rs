/* cally 逆向卡：Command_Destroy（原版 libyoyo.so，armv7）
 * @func 0x1c9b54 0x1c9bb4  size 96  24 条（0x1c9bb0 为 literal pool 一个字，真指令 23）
 * 级别: 正文（23 条真指令全部落锚：闸门、置闸、两个事件、skip 闩、全局计数器、返回；
 *             写集只有 3 个位置，除事件外的副作用全部点清）
 * 符号: _Z15Command_DestroyP9CInstance → void Command_Destroy(CInstance* inst)
 * 位置: 与 Command_Change 0x1c9bb4、Command_DestroyAt 0x1c9c88、Command_ChangeAt 0x1c9cf8 同族
 *       （运行时命令处理器的「销毁」一格）。全库两个入口：
 *         ① DoDestroy 0x10b124 的 b（hard 尾跳，见 DoDestroy 卡）
 *         ② Command_DestroyAt 0x1c9ce4 的 bl（按点位置找实例后再销毁）
 *
 * ── 一句话 ─────────────────────────────────────────────────────────────
 *   硬销毁入口：一次性闸门（+0x6a）→ 置闸 → 派 Destroy(1) 与 CleanUp(12) 两个事件 →
 *   置 skip 闩（+0x68）→ 全局销毁计数器 ++。不摘链、不释放、不递减任何计数、不检查空指针。
 *
 * ── 语义草案（可编译）────────────────────────────────────────────────
 *   void Command_Destroy(CInstance* inst) {
 *     if (inst->[0x6a]) return;                    // 1c9b5c..1c9b64：已在销毁流程里 → 什么都不做
 *     inst->[0x6a] = 1;                            // 1c9b68..1c9b70：先把闸立起来，再派事件
 *     Perform_Event(inst, inst, 1, 0);             // 1c9b74..1c9b7c：1 = Destroy
 *     Perform_Event(inst, inst, 12, 0);            // 1c9b80..1c9b90：12 = CleanUp（编号含义跨卡推断）
 *     inst->[0x68] = 1;                            // 1c9b98：skip 闩（事件之后才置）
 *     ++*(uint32_t*)0x536d7c;                      // 1c9b94..1c9ba8：经 GOT 0x3ee0bc
 *   }
 *
 * ── 三个字节闸门的分工（跨卡对齐）────────────────────────────────────
 *   +0x68  skip        本函数与 DoDestroy 软路径都置 1；DoPushEnv 的 with 遍历、Perform_Event_All、
 *                      DrawInstancesOnly、DoDestroy 入口都按它跳过（DoDestroy / DoInstanceDestroy 卡）
 *   +0x69  deactivated 只被读、不被本函数碰：Command_Destroy 不检查它 ⇒ 已 deactivated 的实例
 *                      仍可被硬销毁一次（软路径在 DoDestroy 入口就被 +0x69 挡住）
 *   +0x6a  destroying 本函数独占：唯一闸门 + 唯一置位者，保证 Destroy/CleanUp 事件只派一次
 *
 * ── 已证（逐条指到指令）──────────────────────────────────────────────
 *   1. 无空指针闸：push 之后立刻 mov r4,r0 并 ldrb [r0,#0x6a]（1c9b54..1c9b60）。
 *      空指针保护在调用方 DoDestroy（其 0x10b0c8 处的 subs/popeq），本函数不重复。
 *   2. 唯一闸门是 +0x6a：非 0 → popne {r4,r5,r6,pc} 直返，既不派事件也不计数（1c9b5c..1c9b64）。
 *   3. 置闸在派事件之前（1c9b68 mov r6,#1 / 1c9b70 strb）⇒ 事件处理器里再调
 *      instance_destroy/本函数会被闸门挡掉，Destroy/CleanUp 至多各一次。
 *   4. 两个 Perform_Event 的四个参数都是 (inst, inst, type, 0)：r0 自入口未改、r1=mov r0、
 *      r3=r5（=0）、r2 分别是 1 与 12（1c9b6c..1c9b90）。Perform_Event 0xf3380 立刻转
 *      Perform_Event_Object(inst, other, inst->[0x7c], type, num)（DoDestroy 卡已锚定该转发）。
 *   5. 事件顺序固定：先 1 后 12，且 +0x68 在两者之后才置（1c9b98 在 1c9b90 之后）
 *      ⇒ 两个事件执行期间实例还没被 skip 掉，仍会出现在 with/绘制遍历里。
 *   6. 计数器：literal 0x00224518（1c9bb0）→ pc 相对加得 0x3ee0bc（.got，R_ARM_RELATIVE，
 *      槽内值 0x536d7c，.bss 4 字节）→ ldr/add #1/str ⇒ ++(*(uint32*)0x536d7c)（1c9b94..1c9ba8）。
 *      与 DoDestroy 软路径共用同一格（其 0x10b100..0x10b118 序列同构）。
 *   7. 写集只有三处：inst+0x6a（=1）、inst+0x68（=1）、0x536d7c（+1）。读集：inst+0x6a、计数器。
 *      不碰 +0x69、不碰实例链 +0x178/+0x17c、不调任何释放函数、不递减活动计数
 *      ⇒ 「标记」与「真正摘链/释放」是两件事，后者不在本函数（DoDestroy 卡同结论）。
 *   8. 无返回值约定：所有出口都是 pop {...,pc}（1c9b64 / 1c9bac），r0 未被设置过。
 *
 * ── open ─────────────────────────────────────────────────────────────
 *  1. 事件号 12 的名称：DoDestroy 卡据 Command_Change 的调用顺序（换对象索引前跑 1、12，后跑 14、0）
 *     推断 1=Destroy、12=CleanUp；本卡只证编号与顺序，不证名字（GMS2 的 Cleanup 事件在运行器里是 12，
 *     与推断一致，但本二进制内没有事件名表可对）。
 *  2. 0x536d7c 的用途未定（.bss 无符号名）：软硬两路都 ++，既不递减也不清零；
 *     可能是「本帧销毁数」类的统计量，但没有读者定位，不写死。
 *  3. 谁消费 +0x68 的置位到「真正移除」之间的一步（MarkAndSweep / UpdateActiveLists / CRoom::RemoveMarked
 *     之一）本卡未定位；本函数只是把闩立起来。
 *
 * ── 逐条锚点 ─────────────────────────────────────────────────────────
 */

/* ── 序与唯一闸门：+0x6a != 0 即返回（不派事件、不计数）────────────────────────
 *   r5 保存闸门字节本身，后面两次 Perform_Event 的 r3（子事件号）直接复用它 —— 值恒 0。
 */

/* @0x1c9b54 push {r4, r5, r6, lr} */
/* @0x1c9b58 mov r4, r0 */
/* @0x1c9b5c ldrb r5, [r0, #0x6a] */
/* @0x1c9b60 cmp r5, #0 */
/* @0x1c9b64 popne {r4, r5, r6, pc} */

/* ── 置闸：先写 +0x6a=1 再派事件（r6=1 同时充当后面的 r2 与 r3 素材）─────────── */

/* @0x1c9b68 mov r6, #1 */
/* @0x1c9b6c mov r1, r0 */
/* @0x1c9b70 strb r6, [r0, #0x6a] */

/* ── 事件 1（Destroy）：Perform_Event(r0=inst, r1=inst, r2=1, r3=0) ─────────────
 *   r0 自入口未改；r1=mov r0；r2=#1；r3=mov r5（闸门原值 0）。
 */

/* @0x1c9b74 mov r2, r6 */
/* @0x1c9b78 mov r3, r5 */
/* @0x1c9b7c bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── 事件 12（CleanUp 推定）：(r0=inst, r1=inst, r2=12, r3=0) ───────────────────
 *   r3 仍是 r5；r0/r1 重新从 r4 取（显式写，不依赖上一轮的残留）。
 */

/* @0x1c9b80 mov r3, r5 */
/* @0x1c9b84 mov r2, #12 */
/* @0x1c9b88 mov r0, r4 */
/* @0x1c9b8c mov r1, r4 */
/* @0x1c9b90 bl 0xf3380 <_Z13Perform_EventP9CInstanceS0_ii> */

/* ── skip 闩 + 全局计数器：+0x68=1，然后 ++0x536d7c（GOT 0x3ee0bc）──────────────
 *   1c9b94 取 literal 0x00224518（在 1c9bb0），1c9b9c [pc,r3] → 0x3ee0bc，槽内值 0x536d7c；
 *   1c9ba0..1c9ba8 是 ldr/add #1/str 的三条自增。1c9bac pop {r4,r5,r6,pc} 返回。
 */

/* @0x1c9b94 ldr r3, [pc, #0x14] */
/* @0x1c9b98 strb r6, [r4, #0x68] */
/* @0x1c9b9c ldr r3, [pc, r3] */
/* @0x1c9ba0 ldr r2, [r3] */
/* @0x1c9ba4 add r2, r2, r6 */
/* @0x1c9ba8 str r2, [r3] */
/* @0x1c9bac pop {r4, r5, r6, pc} */

/* ── literal pool 一字（非指令）：0x1c9bb0 = 0x00224518 = GOT 槽 0x3ee0bc 的偏移 ──
 *   1c9ba4 + 0x00224518 = 0x3ee0bc；objdump 译成 eoreq，非指令。
 */

/* @0x1c9bb0 eoreq r4, r2, r8, lsl r5 */
