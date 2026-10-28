/* cally 逆向卡：Code_Variable_Find_Name（原版 libyoyo.so，armv7）
 * @func 0xd25fc 0xd2618  size 28  7 条（无帧、无保存寄存器、两个出口都是尾跳）
 * 级别: 正文（7/7 条逐条锚定；分界常数与两条尾跳的语义都被被调函数反向验证）
 * 符号: _Z23Code_Variable_Find_NamePKcii → char const* Code_Variable_Find_Name(char const* name, int type, int id)
 *
 * ── 一句话 ──────────────────────────────────────────────────────
 *   按变量 id 二路分派：id >= 100000 走作用域查名，否则走内置变量表按 id 直查。
 *   两个出口都是 b（尾跳），本函数不建帧、不保存寄存器、没有局部变量 ——
 *   它是「零成本转发器」，真正的逻辑全在两个被调函数里。
 *
 * ── 分界常数 99999 = 100000 - 1 ─────────────────────────────────
 *   movw r3,#0x869f + movt r3,#0x1 拼出 0x1869F = 99999，配 cmp r2,r3 + bgt：
 *   判定式等价于 id > 99999 即 id >= 100000。
 *   另一侧独立出现同一个 100000：被调函数 Variable_GetName_Scope(0xd2228) 的头两条实算就是
 *   sub r7,r2,#99328 加 subs r7,r7,#672（99328+672 = 100000）⇒ r7 = id - 100000。
 *   ⇒ 与「变量 id 基址 100000」的既有结论一致，且此处是硬编码常数、无符号可读。
 *
 * ── 低区间（id < 100000）：按 id 查内置表，第 2/3 参数被丢弃 ──────────
 *   mov r0,r2 把 id 顶到首参后尾跳 Variable_BuiltIn_Find_Name(int) —— name/type 到此为止。
 *   表逻辑在 0x1f3b38：
 *     id < 0             → 0x1f3b70 分支返回 0x3527c8 的 "<unknown built-in variable>"
 *     id >= 单例[0]      → 0x1f3b64 分支，与负数共用同一个兜底返回点
 *     否则               → 0x1f3b5c ldr r0,[r3,r0,lsl #4]：槽步长 16，取槽内第 0 个字
 *   单例走 GOT：字面量 0x1f3b7c = 0x001fa0f0，pc(0x1f3b4c)+0x1fa0f0 = GOT 0x3edc3c → 0x753108（计数）；
 *   第二个字面量 0x1f3b80 = 0x001fa0e0，pc(0x1f3b60)+0x1fa0e0 = GOT 0x3edc40 → 0x75310c（表基），
 *   正好是单例 +4 —— 与「全局表来自 GOT 单例 +4」的既有结论逐字对上。
 *   ⇒ 内置域查名只认 id：名字在槽 +0、步长 16、越界与负数同一兜底串。
 *
 * ── 高区间（id >= 100000）：按名字 + 类型 + 作用域下标查 ─────────────
 *   b 0xd2228 把 (name, type, id) 三个寄存器原样交出，Variable_GetName_Scope 内部：
 *     0xd22c4/0xd22c8  strcmp(表项名, name) 线性搜索
 *     0xd22d8          ldr r0,[r3,r7,lsl #2]：命中后用 [id-100000] 索引，4 字节步长
 *     0xd2404          Script_Find_Parent(name) 分支；找不到父脚本落 0xd22f4 兜底串
 *   type 只在这一侧参与分派（0xd2274 / 0xd227c / 0xd231c 对 -5 / -12 / -7 / 1 各有一条路）。
 *
 * ── 调用点（返回值口径的旁证）────────────────────────────────────
 *   0xd4b1c..0xd4b28（DoPushLocal）：r0 = [exec+0x34]、r1 = -7、r2 = 变量 id；
 *   0xe6788（DoPop）：r0 = [exec+0x34]、r1/r2 = 上游寄存器。
 *   两处都把返回值直接当 %s 实参送进 VMError ⇒ 返回的是变量名的文本，不是句柄。
 *
 * 结论（新增五条硬事实）:
 *   1. 分派键只有第 3 参数 id：id>=100000 → 作用域路、id<100000 → 内置表；7 条指令全部服务于这一个比较。
 *   2. 内置域的 100000 个 id 是扁平命名空间：一张 16 字节步长表 + 一个 count，没有作用域维度。
 *   3. 内置查名对 name/type 零依赖（寄存器被 mov r0,r2 覆盖），越界与负数返回同一个兜底串。
 *   4. 100000 是硬编码常数，但在两处独立出现（本函数 99999、GetName_Scope 的 99328+672），互为校验。
 *   5. 两个出口都是尾跳，返回值 = 被调函数返回值，本函数不影响栈与返回地址。
 * open:
 *   1. 首参 r0 在低区间被整条丢弃；[exec+0x34] 究竟是 VMExec 的哪个字段未钉死。
 *   2. 高区间里 type 的四个取值（-5/-7/-12/1）分别对应哪类作用域未逐一证。
 */
/* ── 入口：拼 99999（分两半：低 16 位 0x869f、高 16 位 0x1） */
/* @0xd25fc movw r3, #0x869f */
/* @0xd2600 movt r3, #0x1 */
/* ── 比较：cmp r2, r3 —— r2 是第 3 参数（id） */
/* @0xd2604 cmp r2, r3 */
/* id > 99999 → 高区间（作用域路） */
/* @0xd2608 bgt 0xd2614 <_Z23Code_Variable_Find_NamePKcii+0x18> */
/* 低区间：id 顶到首参 */
/* @0xd260c mov r0, r2 */
/* 尾跳 Variable_BuiltIn_Find_Name(int)；name/type 在此作废 */
/* @0xd2610 b 0x1f3b38 <_Z26Variable_BuiltIn_Find_Namei> */
/* 高区间：尾跳 Variable_GetName_Scope(name, type, id)，三参原样 */
/* @0xd2614 b 0xd2228 <_Z22Variable_GetName_ScopePKcii> */
