/* cally 逆向卡：Call_RValue（原版 libyoyo.so，armv7）
 * @func 0x249860 0x249898  size 56  14 条（无池字、无帧）
 * 级别: 正文（14/14 逐条落锚；两级类型闸、返回值口径、尾调用点与被调端契约全部定死）
 * 符号: _Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_ → Call_RValue(YYObjectBase*, RValue*, RValue*, int, RValue*)
 *       返回类型未定：拒绝路显式 r0 = 1；接受路不设 r0，直接透传 Call_ScriptRef 的返回值（尾调用）。
 * 导出: .dynsym 里 GLOBAL DEFAULT（公开 ABI）。
 * 位置: 0x249590 是 Call_ScriptRef、0x24931c 是 Call_Accessor_Set、0x248fec 是 Call_Accessor_Get；
 *       本函数是这一族里最薄的一层，只做「类型闸 + 转发」。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────
 *   把「可调用的 RValue」翻成对象指针，验明是脚本引用（[obj+0x48] == 3），然后**尾调用** Call_ScriptRef。
 *   自己不做任何实参搬运、不压帧、不碰引用计数 —— 第 5 个实参本来就躺在 [sp] 上，尾跳不需要动栈。
 *
 * ── 逐条读法 ──────────────────────────────────────────────────────────
 *   入口：r0 = YYObjectBase*（原样透传）、r1 = 第 2 实参（原样透传）、r2 = 可调用 RValue*、
 *         r3 = int（实参个数，原样透传）、[sp] = 第 5 实参（RValue* 数组，原样透传）。
 *   1. 0x249860 r12 = [r2+0xc]，0x249868 掩到 24 位 ⇒ tag = RValue.tag & 0x00FFFFFF。
 *   2. tag != 6（对象）→ 0x249874 r0 = 1、复原栈、bx lr ⇒ **返回 1，不调用**。
 *   3. tag == 6 → 0x249880 r2 = [r2]（取 value = 对象指针），0x249884 r12 = [r2+0x48]。
 *   4. [obj+0x48] != 3 → 同样返回 1。
 *   5. [obj+0x48] == 3 → 0x249890 复原栈、0x249894 **b**（不是 bl）Call_ScriptRef(r0, r1, obj, r3, [sp])。
 *   栈上那对 str/ldr 只是保存并恢复 r4，函数体从未用 r4（净效果为零），它的唯一作用是让第 5 实参在尾跳前
 *   回到 [sp] 原位。
 *
 * ── 与 DoCall / DoCallScript / DoCallLibrary 的分工（本卡重点）──────────
 *   1. DoCall 的 kind == 5 分支处理的是同一类目标，判据一模一样：RValue tag == 6，且 [obj+0x48] == 3；
 *      连失败语义都同构（DoCall 抛 "Invalid callv target #1/#2"，本函数则安静返回 1）。
 *      ⇒ 这两处是**同一个「可调用对象」判定**在两条入口上的两份实现：字节码侧在 DoCall 里，
 *        C 侧（内建函数要回调 GML 时）在本函数里。
 *   2. 本函数不自己压帧：Call_ScriptRef(0x249590) 里才做 [obj+0x88]==6 → 取 [obj+0x7c]、
 *      scr = [obj+0x64]、[obj+0x78]==6 → 把 [obj+0x6c] 写进局部栈 +0xc、YYAllocLocalStackNew 建局部栈，
 *      与 DoCall kind5 对象路是同一组字段、同一步骤 —— 也就是说这条 C 侧入口最终仍然落到 VM 帧上，
 *      与 DLL_Call/Call_Normal 那条「直接 blx +0xc」的快路径是两条完全不同的落地方式。
 *   3. 与 DoCallScript 的关系是**间接**的：本函数 →（尾调）Call_ScriptRef → 局部栈 + 执行器；
 *      DoCallScript 的「必压帧」约定在这里没有被绕过，只是入口更靠上。
 *
 * ── 唯一已见的调用点 ──────────────────────────────────────────────────
 *   DoReplace 的 0x24abb0：r0 = [r7]（实例/对象）、r1 = sp-64（结果 RValue）、r2 = [r11-0x7c]（回调 RValue）、
 *   r3 = *(int*)r5 + 2（[r5] 那个计数的语义本卡不定，+2 是硬事实）、[sp] = r6（RValue 数组）。
 *   ⇒ 典型用途是「字符串替换的回调函数」。该调用点**不读返回值**（bl 之后直接 ldr 重载别的寄存器），
 *     所以「返回 1」的语义目前没有消费者，只能定为「未调用/未处理」的标记。
 *
 * 结论：
 *   1. 判据 = (RValue.tag & 0x00FFFFFF) == 6 且 [value+0x48] == 3，两个条件都在本函数里，别处不再复检。
 *   2. 它是纯转发：5 个实参一个不动、一个不加，尾跳 Call_ScriptRef；r4 的 push/pop 是死保存。
 *   3. 与 DoCall kind5 的同构是硬证据：同 tag、同 +0x48==3、同 [0x64]/[0x78]/[0x88] 字段组。
 * open:
 *   1. 「返回 1」到底是「失败」还是「已处理但未产生值」—— 无消费者，无法从代码定。
 *   2. r0 与 r1 的真实身份（本函数只透传）：Call_ScriptRef 的首参是 self 还是实例、次参是结果槽还是别的。
 *   3. [obj+0x48] == 3 的类型枚举含义（DoCall 卡同样留了这条）。
 */
/* ── 段 1 · 取 tag（r2 的第 3 实参 = 可调用 RValue）── */
/* @0x249860 ldr r12, [r2, #0xc] */
/* @0x249864 str r4, [sp, #-0x4]! */
/* @0x249868 bic r12, r12, #-16777216 */
/* @0x24986c cmp r12, #6 */
/* @0x249870 beq 0x249880 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_+0x20> */
/* ── 段 2 · 拒绝路：r0 = 1，复原 r4 后返回 ── */
/* @0x249874 mov r0, #1 */
/* @0x249878 ldr r4, [sp], #4 */
/* @0x24987c bx lr */
/* ── 段 3 · 接受路：取对象，验 [obj+0x48] == 3，然后尾跳 Call_ScriptRef ── */
/* @0x249880 ldr r2, [r2] */
/* @0x249884 ldr r12, [r2, #0x48] */
/* @0x249888 cmp r12, #3 */
/* @0x24988c bne 0x249874 <_Z11Call_RValueP12YYObjectBaseP6RValueS2_iS2_+0x14> */
/* @0x249890 ldr r4, [sp], #4 */
/* @0x249894 b 0x249590 <_Z14Call_ScriptRefP12YYObjectBaseP6RValueP10CScriptRefiS2_> */
