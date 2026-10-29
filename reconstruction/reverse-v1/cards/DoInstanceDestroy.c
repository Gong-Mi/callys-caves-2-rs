/* cally 逆向卡：DoInstanceDestroy（原版 libyoyo.so，armv7）
 * @func 0x10b12c 0x10b190  size 100  25 条（末条指令 0x10b18c，栈帧 52 字节）
 * 级别: 正文（参数重排、WithObjIterator 构造、do-while、hard 透传全证；迭代器内部状态机只到边界，未逐态展开）
 * 符号: _Z17DoInstanceDestroyP9CInstanceS0_ib → void DoInstanceDestroy(CInstance* self, CInstance* other, int id, bool hard)
 *
 * ── 语义草案 ─────────────────────────────────────────────────────────────
 *   void DoInstanceDestroy(CInstance* self, CInstance* other, int id, bool hard) {
 *     WithObjIterator it(id, self, other, false);   // 迭代器对象在 sp+12，0x10b134..0x10b158
 *     while (CInstance* o = it.de()) {              // 0x10b174..0x10b184（先判条件）
 *       DoDestroy(o, hard);                         // 0x10b160 / 0x10b168
 *       it.Next();                                  // 0x10b170
 *     }
 *   }
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1) 帧 52 字节：push {r4,r5,lr} + sub sp,sp,#52；迭代器对象落在 sp+12（add r4,sp,#12，0x10b134），
 *     其后 12 字节供 ctor 的第 5 实参槽使用（0x10b154 str r12,[sp]）。
 *  2) 参数重排（原 4 参 → ctor(id, CInstance*, CInstance*, bool)）：
 *       r0 = &it              （0x10b150）
 *       r1 = id   = 原 r2     （0x10b140）
 *       r2 = self = 原 r0     （0x10b148）
 *       r3 = other= 原 r1     （0x10b138 mov r12,r1 / 0x10b144 mov r3,r12）
 *       [sp] = 0              （0x10b14c mov r12,#0 / 0x10b154）→ ctor 的 bool 实参 = false
 *  3) hard 保存在 r5（0x10b13c），循环体前 mov r1,r5（0x10b164）原样透传给 DoDestroy —— 不被迭代改写。
 *  4) 循环形态是 do/while：入口 0x10b15c b 0x10b174 先求条件，条件 = it.de() != 0
 *     （0x10b178 bl 0x19de4c、0x10b17c cmp r0,#0、0x10b184 bne 0x10b160）。
 *     循环体再调一次 de()（0x10b160），其返回值就是 DoDestroy 的 r0。
 *     ⇒ 每条实例 2 次 de()（条件 1 + 体 1）+ 1 次 Next()（0x10b170）＝ 3 次调用/实例。
 *  5) 迭代器分流（WithObjIterator::WithObjIterator 0x19d060；字段 +0x14=id、+0x18=状态、+0x20=bool、
 *     +0x10=单实例、+0x0=对象实例链、+0x4=活动链、+0xc=CObjectGM*）：
 *       id == -1        → +0x10 = self ，状态 -1（只处理 self）            [0x19d080 / 0x19d074]
 *       id == -2        → +0x10 = other，状态 -1（只处理 other）           [0x19d09c→0x19d170]
 *       id == -3        → 状态 -2，+0x4 = *(*(g)+0x80)（全局活动实例链头），沿 +0x178 前进（全体活动实例）
 *       id <= 99999（非 -1/-2/-3，含 -4 以下）→ 状态 0；id&mask 走对象表哈希桶（比较 [entry+8]==id），entry->[0xC] → +0xc(CObjectGM*)，
 *                         objgm->[0xD0] → +0x0（该对象的实例链）
 *       id > 99999      → **另一张表**（GOT 0x3edc4c，≠ 上面用的 0x3edc44；表在 .bss 0x536f28），
 *                          命中项 [0xC] 直接写 +0x10（状态仍 -1）
 *                          ⚠ 修正（batchS，cards/Variable_SetValue.c：两处 GOT 槽实测不同）
 *  6) de()(0x19de4c) 按状态取当前实例：-2 → +0x4；-1 → +0x10；0 → [[0]+8]；1/2 → 全局实例数组
 *     （计数在 *(g)+8）按 inst->[0x7C] == id 过滤；3 → +0x8 链，[0x7C] 相等或 CObjectGM::IsDecendentOf 放行。
 *     de() 返回 0 即迭代结束 —— 因此「哪些实例被销毁」完全由 id 决定，与本函数无关。
 *  7) ctor 第 5 实参传 false 的实际作用：de() 的状态 3 尾部若 +0x20 非 0 会改取 *(*(g)+0x8C)
 *     （0x19dfd0..0x19dff0）；这里传 0 把该尾巴关掉。
 *  8) 调用者（全图 3 处，都是尾跳或直接 bl）：
 *       0x10b1d8  F_InstanceDestroy(0x10b190)：argc>1 → id=YYGetInt32(args,0)、hard=YYGetBool(args,1)；
 *                 argc==1 → hard=1（0x10b1e8 mov r7,r3）；argc==0 → id=-1、hard=1（0x10b1dc）
 *       0x10b230  YYGML_instance_destroy(0x10b1f0)：同构，args[0]/args[4] 直取
 *       0x1b7b08  CLayerManager::RemoveInstanceElement(0x1b7ac4)：element+0x1c != -14 时
 *                 DoInstanceDestroy(NULL, NULL, elem[0x1c], 1) —— self/other 传 0，说明 id>=0 路径不依赖这两个指针
 *     ⇒ 对外语义：GML instance_destroy(对象/实例 id [, 是否跑销毁事件])，缺省 hard=1（硬销毁）。
 *  9) 与 DoPop/DoPush 的调用关系（纠正常见误解）：两者都「不调用」本函数，也不调用 DoDestroy。
 *     - DoPop/DoPush 的 tag 1..4 释放路径调的是 FREE_RValue__Pre(0xc0a7c)（DoPop 9 处，如 0xe69f8；
 *       DoPush 8 处），它是 RValue 载荷释放，与实例销毁是两条独立路径；其直接 bl 目标里没有任何销毁入口。
 *     - 对整份 .so 做 4 字节地址搜索：0x10B12C 只出现在 .dynsym st_value（文件偏移 0x876C）与 3 个分支指令
 *       （0x10b1d8 / 0x10b230 / 0x1b7b08）—— 没有函数指针，故 VM 的 pop/push 不可能间接到此。
 *     - 真正的耦合点是数据而非调用：DoPushEnv 的 with 作用域遍历按 +0x68/+0x69 跳过
 *       （0xd4f9c..0xd4fb8 计数、0xd50f0..0xd510c 派发），而 DoDestroy 正是置 +0x68 的那一处。
 *       即「销毁置位 → 后续 with 不再纳入」，不是「pop 触发销毁」。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 迭代器状态 1/2 依赖的全局实例数组（*(g)、*(g)+8 计数、*(g)+0x8C）字段语义未定。
 *  · id > 99999 分支把查表命中项 [0xC] 当实例指针用（0x19d130..0x19d170），未验证其正确性。
 *  · id == -3（全活动实例）在实际运行中是否被使用未知：已知调用者只传 -1、具体 id 或 elem[0x1c]。
 *  · 摘链与内存释放不在本函数：全程不改 +0x178/+0x17C，也不调用 free/delete/析构。
 *
 * ── 本批补证：销毁实例（逐条锚在下方）──
 *   WithObjIterator ctor/de/Next + DoDestroy(inst,bool) —— 迭代 with 目标后逐个销毁
 *   open 1 是否受 deactivated 影响
 *   open 2 DoDestroy 第二实参的来源
 */

/* ── 1. 入口：帧 52 字节，迭代器对象在 sp+12（0x10b12c..0x10b134）────────────── */
/* @0x10b12c push {r4, r5, lr} */
/* @0x10b130 sub sp, sp, #52 */
/* @0x10b134 add r4, sp, #12 */

/* ── 2. 参数重排并构造 WithObjIterator(id, self, other, false)（0x10b138..0x10b158）── */
/* @0x10b138 mov r12, r1 */
/* @0x10b13c mov r5, r3 */
/* @0x10b140 mov r1, r2 */
/* @0x10b144 mov r3, r12 */
/* @0x10b148 mov r2, r0 */
/* @0x10b14c mov r12, #0 */
/* @0x10b150 mov r0, r4 */
/* @0x10b154 str r12, [sp] */
/* @0x10b158 bl 0x19d060 <_ZN15WithObjIteratorC2EiP9CInstanceS1_b> */

/* ── 3. 先跳去求条件（do/while）（0x10b15c）────────────────────────────────── */
/* @0x10b15c b 0x10b174 <_Z17DoInstanceDestroyP9CInstanceS0_ib+0x48> */

/* ── 4. 循环体：de() → DoDestroy(inst, hard) → Next()（0x10b160..0x10b170）────── */
/* @0x10b160 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10b164 mov r1, r5 */
/* @0x10b168 bl 0x10b0c4 <_Z9DoDestroyP9CInstanceb> */
/* @0x10b16c mov r0, r4 */
/* @0x10b170 bl 0x19d1c8 <_ZN15WithObjIterator4NextEv> */

/* ── 5. 条件：de() != 0 才继续（0x10b174..0x10b184）──────────────────────────── */
/* @0x10b174 mov r0, r4 */
/* @0x10b178 bl 0x19de4c <_ZN15WithObjIteratordeEv> */
/* @0x10b17c cmp r0, #0 */
/* @0x10b180 mov r0, r4 */
/* @0x10b184 bne 0x10b160 <_Z17DoInstanceDestroyP9CInstanceS0_ib+0x34> */

/* ── 6. 收尾：add sp,#52 / pop {r4,r5,pc}（0x10b188..0x10b18c）───────────────── */
/* @0x10b188 add sp, sp, #52 */
/* @0x10b18c pop {r4, r5, pc} */
