/* cally 逆向卡：_RefThing<char const*>::assign（原版 libyoyo.so，armv7）
 * @func 0xdc418 0xdc42c  size 20  5 条（无字面量池、无栈帧、无调用）
 * 级别: 正文（唯一动作、返回约定、8 个调用点的 RValue 载荷形态、与 tag2 内联 retain 的并排关系全部落锚；
 *            open 2 条见文末）
 * 符号: _ZN9_RefThingIPKcE6assignEPS2_
 *       → _RefThing<char const*>* _RefThing<char const*>::assign(_RefThing<char const*>*)
 *
 * ── 语义 ─────────────────────────────────────────────────────────────
 *   assign(p) { if (p) ++p->count; return p; }      // count 在 +4
 *   _RefThing 布局（与 dec 卡、FREE_RValue__Pre 卡段1 一致）：{+0 char* text, +4 int count, +8 int len}，
 *   本体 12 字节、堆上分配、由 RValue 的 tag 1 载荷指向。
 *   0xdc418 cmp r0,#0 → 0xdc41c 只有非空才 ldrne +4 → 0xdc420 addne #1 → 0xdc424 strne → 0xdc428 bx lr。
 *   r0 全程没被改写 ⇒ 返回值就是入参本身；r1 一条指令都没读。
 *   ⇒ 机器码上无法区分「this 是 p」还是「唯一入参是 p」：Itanium 名字带隐式 this，但本体只用一个寄存器。
 *     两种读法的可观测语义完全相同：把该对象的计数 +1，并把它原样返回。
 *
 * ── 与 dec 的关系：互逆，但同步策略不对称 ─────────────────────────────
 *   dec(0xc09f8，132 B)：LOCK；if(--[this+4]) {UNLOCK; ret;} else {YYFree([this]); ...; delete this;}
 *   本函数：只有 4 条条件指令，一条锁都没调（对比 FREE_RValue__Pre 0xc0ac0 / 0xc0ac8 那对
 *   LOCK/UNLOCK_RVALUE_MUTEX）⇒ 保留侧无同步、释放侧有同步。
 *
 * ── 调用面（8 个 bl 点，全在字符串 RValue 的构造 / 拷贝路径上）──────────
 *   DoPop 0xe745c / 0xe77dc / 0xe7b60、DoCall 0xe93c4 / 0xe961c、DoPush 0xea71c / 0xea72c / 0xeafb8
 *   8 处全部把返回值直接写进目标 RValue 的载荷槽：
 *     0xe7464 str r0, [r5, r6, lsl #4]    （数组元素槽，RValue 步长 16）
 *     0xe77e4 str r0, [r6]                0xe7b68 str r0, [r3]
 *     0xe93cc / 0xe9624 / 0xea724 str r0, [r4, #-0x10]
 *     0xeafc0 str r0, [r4, #0x10]
 *   ⇒ 这就是 tag1（字符串）RValue 的 retain 路径：dst.payload = assign(src.payload)。
 *
 * ── 与 tag2 内联 retain 的并排证据（同一 tag 分派里相邻的两个 case）────
 *   DoPop 的 tag 分派里，容器 case 在 0xe7428..0xe7444 被内联展开：
 *     ldr r3,[r8]; cmp r3,#0; str r3,[r5,r6,lsl #4]; beq …
 *     ldr r0,[r3,#0x8]; ldr r2,[r3]; cmp r0,#0; streq r1,[r3,#0x8]; add r2,r2,#1; str r2,[r3]
 *     ⇒ ++[c+0]（refcount），[c+8]（holder）为空则回指该 RValue 槽 —— 与 FREE_RValue__Pre 卡段2 的
 *       容器字段（+0 计数 / +4 chunk 表 / +8 holder / +0x10 chunk 数）完全吻合。
 *   紧接的字符串 case 在 0xe744c..0xe745c 落成本函数的 out-of-line 调用。
 *   DoPush 0xea6f0..0xea704 是同一对（容器内联，holder 空则写 r10），0xea71c .. 才是 assign。
 *   ⇒ 编译器把数组 retain 内联、把字符串 retain 留在本函数；两条路径共用「+0/+8 计数与回指」这套字段语义。
 *
 * ── open ────────────────────────────────────────────────────────────
 *   1. 计数 +4 的原子性：无锁的 ++ 在多线程（VM 主线程 vs audio/JS 回调）下是否会撕裂未验；
 *      静态侧只能确认「retain 不加锁、release 加锁」这个不对称。
 *   2. 谁负责释放被覆盖的旧值：本函数不碰目标槽；调用点是否总在同一块里先调 remove(0xdc42c)，
 *      没有逐点建表（DoCall 0xe961c 的下游紧跟 remove，DoPush/DoPop 的若干点未见）。
 */

/* ---- retain：非空则 ++[p+4]，并原样返回 p ---- */
/* @0xdc418 cmp r0, #0 */
/* @0xdc41c ldrne r3, [r0, #0x4] */
/* @0xdc420 addne r3, r3, #1 */
/* @0xdc424 strne r3, [r0, #0x4] */
/* @0xdc428 bx lr */
