/* cally 逆向卡：DoVariableInstanceExists（原版 libyoyo.so，armv7）
 * @func 0x1178b8 0x117938  size 132  33 条（无 literal pool，尾部直接是下一条函数）
 * 级别: 正文（逐条锚定，控制流与判据全部落地，可直译）
 * 符号: _Z24DoVariableInstanceExistsP9CInstancePKc → int DoVariableInstanceExists(CInstance* inst, const char* name)
 * 实参: r0=inst(r5) r1=name(r4)；返回 0/1
 *
 * ── 流程 ────────────────────────────────────────────────────────────
 *   RValue v（栈上 16 B，sp+0..sp+0xf）先清零
 *   id = Variable_BuiltIn_Find(name)        ; 哈希表查内建变量名，未命中返回 -1
 *   if (id < 0) {
 *       slot = Code_Variable_Find_Slot_From_Name(inst, name)
 *       if (slot < 0) return 0;             ; 名字既不是内建也不是实例变量 → 不存在
 *       id = slot + 100000;                 ; add #99328 再 add #672（= 100000，全库同一基址约定）
 *   }
 *   Variable_GetValue_Direct(inst, id, 0x80000000, &v)
 *   return (v.tag & 0x00FFFFFF) != 0x00FFFFFF;   ; mvn #-16777216 = 0x00FFFFFF
 *
 * ── 三处跨函数互证 ──────────────────────────────────────────────────
 *   1. Variable_GetValue_Direct(YYObjectBase*, int id, int idx, RValue*)：id <= 9999 走内建变量跳板
 *      （表项 16 B，函数指针在 +4），否则取 inst[0x04] + (id-100000)*16 的槽再尾调 GET_RValue。
 *      ⇒ 100000 基址 + 16 B 槽步长在本函数与取值器里是同一套（本卡把 +100000 摆在了 id 侧）。
 *   2. 第 3 实参常量 0x80000000 = INT_MIN 是「不按下标取值」的哨兵：GET_RValue 里
 *      cmp r2,#-2147483648 相等才跳过 YYError（0xd13e4/0xd13e8），即非数组却带下标会报错。
 *   3. 判据不是「槽存在」而是「取到的 RValue 的 tag 不是 0x00FFFFFF」——0x00FFFFFF 是全库的
 *      「未解析变量引用」占位（README 三事实之一），所以本函数答的是"取得到真值吗"，不是"名字在不在"。
 *
 * 结论（新增三条硬事实）:
 *   1. 名字解析有两条腿：内建变量哈希（负返回 = 不是内建）→ 实例变量名到槽号（负 = 没有该槽）；
 *      两条都失败才返回 0，且此路径不触碰任何 RValue。
 *   2. 存在性判据 = 取值结果的 tag != 0x00FFFFFF（不是查表成功与否），所以"名字在但值未解析"会答 0。
 *   3. 函数无全局、无释放、无副作用，栈帧只有 20 B（16 B RValue + 4 B 对齐垫）。
 * open:
 *   1. 谁负责把 tag 写成 0x00FFFFFF（本函数只读；GET_RValue 的拷贝路径也没有写它）。
 *   2. CInstance* 直接当 YYObjectBase* 传给取值器 —— 两者是同址基类还是原型期别名，本卡未证。
 *   3. Variable_BuiltIn_Find 命中时返回的 id 与实例槽 +100000 是否共用同一 id 空间（只证到取值器按 9999 分界）。
 */

/* ── 序：20 B 栈帧，sp+0..sp+0xf 是清零的临时 RValue ── */
/* @0x1178b8 push {r4, r5, lr} */
/* @0x1178bc mov r5, r0 */
/* @0x1178c0 sub sp, sp, #20 */
/* @0x1178c4 mov r0, r1 */
/* @0x1178c8 mov r4, r1 */

/* ── 内建变量哈希查询：负返回 = 不是内建名 ── */
/* @0x1178cc bl 0x1f3a5c <_Z21Variable_BuiltIn_FindPKc> */
/* @0x1178d0 subs r1, r0, #0 */
/* @0x1178d4 blt 0x117918 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x60> */

/* ── 取值：Variable_GetValue_Direct(inst, id, INT_MIN, &v) ── */
/* @0x1178d8 mov r3, sp */
/* @0x1178dc mov r0, r5 */
/* @0x1178e0 mov r2, #-2147483648 */
/* @0x1178e4 mov r12, #0 */
/* @0x1178e8 str r12, [sp] */
/* @0x1178ec str r12, [sp, #0x4] */
/* @0x1178f0 str r12, [sp, #0x8] */
/* @0x1178f4 str r12, [sp, #0xc] */
/* @0x1178f8 bl 0x1f3b8c <_Z24Variable_GetValue_DirectP12YYObjectBaseiiP6RValue> */

/* ── 判据：tag & 0x00FFFFFF != 0x00FFFFFF → 1，否则 0 ── */
/* @0x1178fc ldr r0, [sp, #0xc] */
/* @0x117900 mvn r3, #-16777216 */
/* @0x117904 and r0, r0, r3 */
/* @0x117908 subs r0, r0, r3 */
/* @0x11790c movne r0, #1 */
/* @0x117910 add sp, sp, #20 */
/* @0x117914 pop {r4, r5, pc} */

/* ── 实例变量名 → 槽号；<0 返回 0，否则 id = 槽号 + 100000 ── */
/* @0x117918 mov r1, r4 */
/* @0x11791c mov r0, r5 */
/* @0x117920 bl 0xd21ec <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc> */
/* @0x117924 cmp r0, #0 */
/* @0x117928 movlt r0, #0 */
/* @0x11792c blt 0x117910 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x58> */
/* @0x117930 add r1, r0, #99328 */
/* @0x117934 add r1, r1, #672 */
/* @0x117938 b 0x1178d8 <_Z24DoVariableInstanceExistsP9CInstancePKc+0x20> */
