/* cally 逆向卡：Code_Variable_Find_Slot_From_Name（原版 libyoyo.so，armv7）
 * @func 0xd21ec 0xd2228  size 60  15 条（含末尾 2 个 literal pool 字，objdump 译成指令，按规矩保留原写法）
 * 级别: 正文（15/15 逐条锚定；两个全局、两路分派、两个被调表的形状都解码）
 * 符号: _Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc
 *   → int Code_Variable_Find_Slot_From_Name(YYObjectBase* self, char const* name)
 *
 * ── 一句话 ───────────────────────────────────────────────────────
 *   名字 → 槽号（int）。只有两个结果来源，且都是**尾跳**（b 不是 bl）：本函数不建帧、不保存寄存器、
 *   不碰栈，返回值就是被调函数的返回值。找不到时两侧都返回 -1。
 *
 * ── 分派（3 个条件、2 个出口）────────────────────────────────────
 *   if (self != *g_host)              → Local_Name(name)
 *   else if (*(uint8_t*)&g_mode == 0) → Global_Name(name)
 *   else                              → Local_Name(name)
 *   即：**只有「self 就是那个全局宿主对象」且「模式字节为 0」时才走全局名表**。
 *
 * ── 两个全局（都走 GOT；.text 里没有它们的绝对地址字面量，已扫 0 命中）────────
 *   字面量 0x31b9c4（0xd2220）→ GOT 0x3edbbc → .bss 0x544be0（**指针**变量，ldr 解引用后与 self 比）
 *   字面量 0x31b9ac（0xd2224）→ GOT 0x3edbc0 → .bss 0x47f295（**字节**开关，ldrb）
 *   两个 addend 在全库 .rel.dyn 的 13414 条 RELATIVE 里各只出现一次 ⇒ 这两个全局的
 *   「谁碰过」等价于「谁碰过这两个 GOT 槽」，可穷举：
 *     0x544be0：0xd21ec（本卡）、0x114dc4（F_VariableGlobalGet）、0x114e64（F_VariableGlobalSet）
 *               —— 三处全是读
 *     0x47f295：0xd2208（本卡）、0xdae58（VM::GetRuntimeState）、0x1087f0（F_InstanceFind）、
 *               0x1095e0 / 0x109690 / 0x10974c（F_InstanceCreate / CreateDepth / CreateLayer）
 *               —— 六处全是 ldrb，无一处写
 *   （穷举口径：GOT 取址对「ldr Rd,[pc,#imm] + ldr Rd,[pc,Rd]」精确配对，全库 427 个解析点。）
 *
 * ── 0x544be0 的身份：全局变量宿主 ────────────────────────────────
 *   F_VariableGlobalGet(0x114db0) 把它的角色钉死：
 *     r5 = *g_host；name = YYGetString(arg,0)；idx = Variable_BuiltIn_Find(name)
 *     idx >= 0 → Variable_GetValue_Direct(r5, idx, INT_MIN, out)
 *     idx <  0 → slot = Find_Slot_From_Name(r5, name)（未命中为 -1，此处不 +100000）
 *                命中（>=0）→ slot += 100000（0x114e3c 的 99328 + 0x114e40 的 672）
 *                → Variable_Global_GetVar(slot', INT_MIN, out)
 *   ⇒ 传进来的 self 就是全局宿主；返回的 slot 要 **+100000** 才是全局 var id
 *     —— 与「变量 id 基址 100000」这条既有结论同源。Set 侧 0x114e50 同构，换成
 *     FindAlloc_Slot_From_Name(0xd2c84)。
 *
 * ── 两个被调表形状不同（这就是分派存在的理由）────────────────────────
 *   Local_Name 0xd1f74：CHashMap<char const*, int>（单例在 .bss 0x47a178），key 是字符串指针，
 *     哈希命中后调 CHashMapCompareKeys<char const*>(0x1eeba8) 做 strcmp；返回 [node+4] = slot；未命中 -1。
 *   Global_Name 0xd2054：**线性 strcmp 扫描**一张名字数组（.bss 0x47a19c：+0 size、+4 count、+0xc char**），
 *     返回数组下标；未命中 -1。全程无哈希。
 *   ⇒ 全局域是「声明顺序即 id」的扁平命名空间；本地域是哈希表。
 *
 * ── 返回值落到哪（三处调用点旁证）──────────────────────────────
 *   YYObjectBase::FindValue 0x196b84：slot == -1 → 返回 NULL；否则走 this+0x04 的 flat 数组
 *     （vars + slot*16）；该指针为 0 才尾跳 InternalGetYYVar(slot)。
 *   YYObjectBase::FindOrAllocValue 0x196bc4：用 FindAlloc_Slot_From_Name(0xd2c84) 的同构版本。
 *   F_VariableGlobalGet 0x114e28：见上（slot + 100000）。
 *   ⇒ 返回的是**槽号**不是指针；**0 是合法槽号**，只有 -1 表示不存在
 *     （FindValue 用 cmn r0,#1 判，不是 cmp r0,#0）—— 这一点纠正「0 当空」的直觉。
 *
 * open:
 *   1. 0x47f295 的模式字节在 .text 里只有 6 个读点、没有写点，写入者/来源未取证。
 *      它在 F_InstanceFind/F_InstanceCreate 里决定返回值编码（一支给 -4.0 / -1.0，另一支给实例句柄），
 *      在 VM::GetRuntimeState 里也分流状态序列化 ⇒ 更像 runner 级「新模式/兼容模式」开关，
 *      而不是变量系统专属。
 *   2. 0x544be0 在 .text 里只有 3 个读点、没有写点，宿主对象由谁创建未取证。
 *   3. Global_Name 的数组 0x47a19c 由谁 append 名字未查（影响「id = 声明顺序」的判定）。
 *   4. Local_Name 的字符串哈希 CHashMapCalculateHash<char const*>(0x1eeb88) 未在本卡展开。
 *   5. 穷举口径的边界：只覆盖「相邻两条 GOT 取址」这一种访问形态；若有代码先把 GOT 偏移存进
 *      寄存器再用，可能漏计（.text 里没有绝对地址字面量，故不可能是直连寻址）。
 */
/* ── 入口：self=r0、name=r1；无帧、无保存寄存器，两条出口都是尾跳 */
/* 字面量 0x31b9c4 是 GOT 偏移（不是地址），下一指令 +8 才是取址点 */
/* @0xd21ec ldr r3, [pc, #0x2c] */
/* GOT 0x3edbbc → .bss 0x544be0（全局宿主指针） */
/* @0xd21f0 ldr r3, [pc, r3] */
/* 解引用：r3 = *g_host */
/* @0xd21f4 ldr r3, [r3] */
/* 判 self == 全局宿主（其余对象一律走本地名表） */
/* @0xd21f8 cmp r3, r0 */
/* name 顶到首参：两个尾跳都只吃一个参数（self 到此作废） */
/* @0xd21fc mov r0, r1 */
/* 是宿主 → 到 0xd2208 看模式字节 */
/* @0xd2200 beq 0xd2208 <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc+0x1c> */
/* 本地名表尾跳（未命中返 -1） */
/* @0xd2204 b 0xd1f74 <_Z39Code_Variable_Find_Slot_From_Local_NamePKc> */
/* 字面量 0x31b9ac → GOT 0x3edbc0 → .bss 0x47f295（模式字节） */
/* @0xd2208 ldr r3, [pc, #0x14] */
/* @0xd220c ldr r3, [pc, r3] */
/* @0xd2210 ldrb r3, [r3] */
/* 模式字节 == 0 才走全局名表；非 0 回落本地表 */
/* @0xd2214 cmp r3, #0 */
/* @0xd2218 bne 0xd2204 <_Z33Code_Variable_Find_Slot_From_NameP12YYObjectBasePKc+0x18> */
/* 全局名表尾跳（声明顺序扫描，未命中返 -1） */
/* @0xd221c b 0xd2054 <_Z40Code_Variable_Find_Slot_From_Global_NamePKc> */
/* 非指令：literal pool（GOT 偏移 0x31b9c4） */
/* @0xd2220 eorseq r11, r1, r4, asr #19 */
/* 非指令：literal pool（GOT 偏移 0x31b9ac） */
/* @0xd2224 eorseq r11, r1, r12, lsr #19 */
