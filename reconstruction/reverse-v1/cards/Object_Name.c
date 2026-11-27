/* cally 逆向卡：Object_Name（原版 libyoyo.so，armv7）
 * @func 0x19ed54 0x19edf4  size 160  40 条（35 条指令 + 末 5 字 0x19ede0..0x19edf0 为 literal pool）
 * 级别: 正文（40/40 逐条落锚；表结构、四层失败出口、默认串、同名表的其他消费者全部钉住）
 * 符号: _Z11Object_Namei → const char* Object_Name(int objindex)
 * 位置: Object_* 家族里：Object_Exists(0x19ecf8, 92B) → 本函数 → Object_Find(0x19edf4, 200B)
 *       → Object_Add(0x19eebc)；本函数是「对象号 → 名字」方向，Object_Find 是「名字 → 对象号」反向
 * 同层/共用结构: SetObjectIndex 0x193290..0x1932b4、WithObjIterator 0x19d098..0x19d0fc 读同一个
 *       GOT 槽 0x3EDC44（= 全局字 0x542374）；CInstance 构造 0x199660 调 SetObjectIndex ⇒ 本表就是
 *       「对象号 → CObjectGM*」的全局对象表
 *
 * ── 语义草案 ────────────────────────────────────────────────────────────────
 *   struct ObjTable { Node** bucket; int mask; };          // bucket 每项 8 字节 {head,tail}
 *   struct Node     { Node* prev; Node* next; int objindex; CObjectGM* obj; };   // 16 字节
 *
 *   const char* Object_Name(int objindex) {
 *     ObjTable* t = *g_pObjTable;                 // 全局字 0x542374，值为表结构指针
 *     if (!t)                          return "<undefined>";     // 0x19edbc 出口
 *     Node* n = t->bucket[objindex & t->mask];                   // 桶下标 = objindex & mask
 *     if (!n)                          return "<undefined>";     // 0x19edc8 出口
 *     while (n->objindex != objindex) {                          // 先比头结点，再沿 next 走
 *        n = n->next;                                            //   node+0x04
 *        if (!n)                       return "<undefined>";     // 0x19edb0 出口
 *     }
 *     CObjectGM* o = n->obj;                                     //   node+0x0c
 *     if (!o)                          return "<undefined>";     // 0x19edd4 出口
 *     return o->name;                                            //   CObjectGM+0x14（见 CObjectGM_ctor 卡）
 *   }
 *
 * ── 已证（指令级）─────────────────────────────────────────────────────────
 *  1. 表是「指针的指针」：19ed54 取 PC 相对字 0x0024eee4 → 19ed58 得 GOT 槽 0x3EDC44 →
 *     槽值是 .bss 全局字 0x542374 → 19ed5c 再解一次才拿到表结构。所以 0x542374 本身只存 4 字节指针，
 *     表结构在别处（+0x00 bucket 数组、+0x04 mask）。旁证：紧随其后的 0x542378 是 option_test_fast_collision，
 *     若表结构内联在 0x542374 就会踩到它。
 *  2. 桶宽 8 字节（ldr r3,[r3,r2,lsl #3]）、节点 16 字节、next 在 +0x04、id 在 +0x08、对象指针在 +0x0c ——
 *     与 ms_ID2InstanceE 的 {prev,next,id,payload} 完全同构（live-oracle-registrations §3.2），
 *     本表只是 payload 换成 CObjectGM*。
 *  3. 同一个 GOT 槽 0x3EDC44 有三个独立消费者：本函数、SetObjectIndex（0x193294，用 mask 查对象后写 inst+0x80）、
 *     WithObjIterator（0x19d0c0，with(obj) 时从对象拿 CObjectGM 再走 +0xd0 实例链）⇒ 「对象号→CObjectGM*」定性成立。
 *  4. 四处失败出口返回的是**同一条**字符串：0x19edb0 / 0x19edbc / 0x19edc8 / 0x19edd4 各自的
 *     add r0,pc,lit 都算到 0x330AC8 = "<undefined>"（编译器把四个相同字面量合并了）。
 *     0x330AC8 前后是 "Add %s\n"、Background_Main.cpp 路径、__newbackground%d，可见 rodata 是共享池。
 *  5. 函数不写任何全局、不分配、不抛异常；objindex 为负也不崩（and 之后按无符号桶下标用）。
 *  6. mask 取自表头 +0x04（值不在本卡钉；同族 ms_ID2InstanceE 是 511，本表未证同值）。
 *
 * ── open ────────────────────────────────────────────────────────────────
 *  · 0x542374 指向的表结构由谁、在哪分配（以及 mask 是否 511）未定位；本卡只证读取侧。
 *  · 节点 +0x00 (prev) 与桶 +0x04 (tail) 本函数一次都没读 —— 删除/尾插在别的函数里。
 *  · 对象名（CObjectGM+0x14）的生命周期不归本函数管：返回裸指针，调用方不得跨越改名/销毁。
 *
 * ── 逐条锚点 ───────────────────────────────────────────────────────────────
 */

/* ── 1. 三层取表：PC 字 → GOT 槽 0x3EDC44 → 全局字 0x542374 → 表结构；空表返回默认串（0x19ed54..0x19ed64）── */
/* @0x19ed54 ldr r3, [pc, #0x84] */
/* @0x19ed58 ldr r3, [pc, r3] */
/* @0x19ed5c ldr r3, [r3] */
/* @0x19ed60 cmp r3, #0 */
/* @0x19ed64 beq 0x19edbc <_Z11Object_Namei+0x68> */
/* ── 2. 桶定位：mask=表+0x04、bucket=表+0x00、下标 = objindex & mask、项宽 8 字节（0x19ed68..0x19ed7c）── */
/* @0x19ed68 ldr r2, [r3, #0x4] */
/* @0x19ed6c ldr r3, [r3] */
/* @0x19ed70 and r2, r0, r2 */
/* @0x19ed74 ldr r3, [r3, r2, lsl #3] */
/* @0x19ed78 cmp r3, #0 */
/* @0x19ed7c bne 0x19ed90 <_Z11Object_Namei+0x3c> */
/* ── 3. 桶空 → 默认串（0x19ed80）────────────────────────────────────────── */
/* @0x19ed80 b 0x19edc8 <_Z11Object_Namei+0x74> */
/* ── 4. 链上比较：先比头结点 id(+0x08)，不等则 next(+0x04)，走空 → 默认串（0x19ed84..0x19ed98）── */
/* @0x19ed84 ldr r3, [r3, #0x4] */
/* @0x19ed88 cmp r3, #0 */
/* @0x19ed8c beq 0x19edb0 <_Z11Object_Namei+0x5c> */
/* @0x19ed90 ldr r2, [r3, #0x8] */
/* @0x19ed94 cmp r0, r2 */
/* @0x19ed98 bne 0x19ed84 <_Z11Object_Namei+0x30> */
/* ── 5. 命中：取 node+0x0c 的 CObjectGM*；为空 → 默认串，否则返回 CObjectGM+0x14 名字指针（0x19ed9c..0x19edac）── */
/* @0x19ed9c ldr r3, [r3, #0xc] */
/* @0x19eda0 cmp r3, #0 */
/* @0x19eda4 beq 0x19edd4 <_Z11Object_Namei+0x80> */
/* @0x19eda8 ldr r0, [r3, #0x14] */
/* @0x19edac bx lr */
/* ── 6. 四个失败出口（0x19edb0 链尽 / 0x19edbc 表空 / 0x19edc8 桶空 / 0x19edd4 对象空）──
 *    四处 add r0,pc,lit 全部落到 0x330AC8 = "<undefined>"；每条都是 ldr+add+bx 三连，无其他副作用。
 */
/* @0x19edb0 ldr r0, [pc, #0x2c] */
/* @0x19edb4 add r0, pc, r0 */
/* @0x19edb8 bx lr */
/* @0x19edbc ldr r0, [pc, #0x24] */
/* @0x19edc0 add r0, pc, r0 */
/* @0x19edc4 bx lr */
/* @0x19edc8 ldr r0, [pc, #0x1c] */
/* @0x19edcc add r0, pc, r0 */
/* @0x19edd0 bx lr */
/* @0x19edd4 ldr r0, [pc, #0x14] */
/* @0x19edd8 add r0, pc, r0 */
/* @0x19eddc bx lr */
/* ── 7. literal pool（5 字；反汇编器把五个数据字全译成了指令，实为数据）────────────────
 *   0x19ede0 = 0x0024eee4 → 0x19ed60+0x0024eee4 = 0x3EDC44（GOT 槽 → 0x542374）
 *   0x19ede4 = 0x00191d0c → 0x19edbc+该值 = 0x330AC8      0x19ede8 = 0x00191d00 → 0x19edc8+该值 = 0x330AC8
 *   0x19edec = 0x00191cf4 → 0x19edd4+该值 = 0x330AC8      0x19edf0 = 0x00191ce8 → 0x19ede0+该值 = 0x330AC8
 *   （四条默认串字面量同址 ⇒ 编译器合并；0x330AC8 内容 = "<undefined>"）
 */
/* @0x19ede0 eoreq lr, r4, r4, ror #29 */
/* @0x19ede4 andseq r1, r9, r12, lsl #26 */
/* @0x19ede8 andseq r1, r9, r0, lsl #26 */
/* @0x19edec ldrsheq r1, [r9], -r4 */
/* @0x19edf0 andseq r1, r9, r8, ror #25 */
