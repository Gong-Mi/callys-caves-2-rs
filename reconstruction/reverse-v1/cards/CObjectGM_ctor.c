/* cally 逆向卡：CObjectGM::CObjectGM(int)（原版 libyoyo.so，armv7）
 * @func 0x19d4f4 0x19d558  size 100  25 条（无 literal 池、无栈 canary、无死代码；25 条全部可达）
 * 级别: 正文（25/25 逐条落锚；15 槽事件表、Clear() 的前置条件、sizeof=220、+0x18/+0x48 全解出）
 * 符号: _ZN9CObjectGMC1Ei / _ZN9CObjectGMC2Ei → CObjectGM::CObjectGM(int)
 *       同一地址两个符号（C1 完整对象 / C2 基类子对象别名），functions.tsv 4270/4271 行
 * 位置: 紧接 CObjectGM::Clear(0x19d3d8)，其后是 ~CObjectGM(0x19d558)、YYCreateEvent(0x19d60c)
 * 调用点: 全图 2 处 bl —— 0x19eae4（Object_Load）、0x19ef00（Object_Add）；
 *         两处都在 bl 之前 mov r0,#220 后调 operator new(0x27c524) ⇒ sizeof(CObjectGM)=220=0xDC
 *
 * ── 语义草案 ────────────────────────────────────────────────────────────────
 *   CObjectGM* CObjectGM::CObjectGM(int id) {
 *     this->[0xc8] = this->[0xc4] = this->[0xcc] = 0;
 *     this->[0xd4] = this->[0xd0] = this->[0xd8] = 0;
 *     this->[0x14] = 0;                       // 名字指针（SetName/Clear/Object_Name 共用）
 *     for (int i = 0; i < 15; i++) {          // 15 个事件类型槽 = {count, CEvent**}
 *       this->[0x50 + 8*i] = 0;               //   数组基址
 *       this->[0x4c + 8*i] = 0;               //   元素个数
 *     }
 *     Clear();                                // 0x19d3d8
 *     this->[0x18] = id;                      // 构造参数
 *     this->[0x48] = 0;
 *     return this;
 *   }
 *
 * ── 段1 这个构造函数真正在做的事：为零化 + 让 Clear() 能安全跑 ─────────────────
 *   Clear()(0x19d3d8) 一进门就无条件读并释放：+0x14 名字、15 个槽的数组、+0xc4 链、+0xd0 链。
 *   对象刚从 operator new 出来（malloc 语义、不清零），所以构造函数的 7 条 str + 15×2 条循环 str
 *   恰好覆盖 Clear() 会「读」的每一个字段 —— 这不是「初始化成员」，是「给 Clear() 铺前提」。
 *   反过来，Clear() 会无条件覆写的 5 个字段（+0x00=18、+0x04=-1、+0x08=0、+0x0c=-1、+0x10=-1）
 *   构造函数一个都没预置 ⇒ 二者互补，可以逐字段对表（见 段5 的字段图）。
 *
 * ── 段2 15 个槽的边界是硬证据，不是估计 ─────────────────────────────────────
 *   循环计数器 r4=15（0x19d50c），decrement-first 写法（subs 在循环体首），游标 r3 从 this 起每轮 +8：
 *   第 14 轮 r3 = this+112 ⇒ 写 this+0xBC 与 this+0xC0（0xC0..0xC3 是最后一个数组指针）。
 *   紧接着的 +0xC4 起是另外四个字段（构造函数逐条清、Clear() 单独释放 +0xC4 链）⇒ 15 槽占 0x4C..0xC3，
 *   与 +0xC4 不重叠。同一组常数在四个函数里完全一致（互证见 段5）。
 *
 * ── 段3 +0x18 与 +0x48 写在 Clear() 之后 ────────────────────────────────────
 *   Clear() 不碰 +0x18，也不写 +0x48 以外的东西（它自己会写 +0x48=0）；
 *   构造函数在 Clear() 之后再写一次 +0x48，写的是 r4 —— 循环出口时 r4 恒为 0。
 *   ⇒ +0x48 在本构建里没有任何「保留构造参数」的痕迹，就是一个被清零的标量。
 *
 * ── 段4 字段图（本卡直接证到的用 ▲，跨函数互证的用 ○）──────────────────────
 *   +0x00 int   对象标志位：bit0 solid、bit1 visible、bit2 persistent        ○ CInstance::SetObjectIndex 0x193318..0x193330
 *   +0x04 int   精灵索引                                                     ○ 同上 0x193314 → SetSpriteIndex
 *   +0x08 float 深度                                                         ○ 同上 0x193300/0x193334
 *   +0x0c int   父对象索引（-1 = 无父；Find_Event 沿它上溯）                  ○ 0x19d3fc / 0xf2efc
 *   +0x10 int   碰撞掩码索引                                                 ○ 0x193308/0x19331c
 *   +0x14 char* 名字（SetName 分配、Clear 释放、Object_Name 返回）            ▲ 0x19d528
 *   +0x18 int   构造参数（Clear/LoadFromChunk 都不碰）                        ▲ 0x19d548
 *   +0x1c..+0x44 LoadFromChunk 写区（+0x1c/+0x1d/+0x3c/+0x3d 是字节）        ○ 0x19d73c..0x19d7dc
 *   +0x48 int   被清零的标量                                                 ▲ 0x19d54c
 *   +0x4c+8i int    事件类型 i 的元素个数（i=0..14）                          ▲ 0x19d534
 *   +0x50+8i CEvent** 事件类型 i 的数组基址                                  ▲ 0x19d530
 *   +0xc4 ptr   一条用 [node+0] 串起来的链表（Clear 沿它逐个 Free）           ○ 0x19d490..0x19d4ac
 *   +0xc8/+0xcc int                                                          ▲ 0x19d510/0x19d518
 *   +0xd0/+0xd4/+0xd8 实例链 head/tail/count（AddInstance/RemoveInstance）   ○ 0x19e02c/0x19e0fc
 *   合计最大偏移 0xDB ⇒ 与 sizeof=0xDC 自洽。
 *
 * ── 已证（每条都指到指令）──────────────────────────────────────────────────
 *   1. 25 条全部可达、无池字：0x19d4f4..0x19d554 连续 25 条，唯二分支是 0x19d53c 回边与
 *      0x19d544 的调用返回，没有任何 b/条件 b 跳出函数体。
 *   2. sizeof = 220：两个调用点（0x19eae4 / 0x19ef00）之前的 mov r0,#220(0xDC) + operator new。
 *   3. 15 个类型槽：计数器 15、游标步长 8、先 array 后 count（0x19d530/0x19d534）、
 *      count 在 +0x4c、array 在 +0x50 —— 与 GetEventDirect(0x19da9c/0x19daa8)、
 *      Clear(0x19d424/0x19d428)、Compile(0x19da08/0x19da24, 循环上界 15)、
 *      YYCreateEvent(0x19d618/0x19d624, SetLength 目标 = this+type*8+0x50) 五处一致。
 *   4. Clear() 在零化之后调用，且只在这一处调用（0x19d544）——构造期不会释放未初始化指针。
 *   5. +0x18 = 构造参数（唯一写点 0x19d548，写在 Clear 之后）；+0x48 = 0（0x19d54c，源寄存器是已归零的 r4）。
 *   6. 返回 this：0x19d550 mov r0,r5 + 0x19d554 pop（r0 是 C++ 返回 this 的 ABI 约定）。
 *   7. r0 与 r2 同时为 0（0x19d4fc mov r0,#0 / 0x19d508 mov r2,r0）：r2 是循环体两个 store 的零源。
 *   8. 本函数不调用除 Clear() 之外的任何函数、不读任何全局 ⇒ 纯内存初始化。
 *
 * ── 结论 ───────────────────────────────────────────────────────────────────
 *   这就是「事件表容器」的构造：把 15 个 {count, CEvent**} 槽和四条挂链字段清成 0，再交给 Clear()
 *   做一次「空表的释放」（实际什么都不释放），最后存下构造参数与一个被清零的标量。
 *   事件号的意义在别处：类型 i 就是槽下标，子号就是槽内数组下标 —— 本卡只负责把槽造出来。
 *
 * ── open ───────────────────────────────────────────────────────────────────
 *   1. +0x18 的语义：两个调用点把 Object_Load/Object_Add 的某个 int 传进来，本卡只能证「只由构造决定、
 *      Clear/LoadFromChunk 都不写」。它是不是「对象索引」需在 Object_Load/Object_Add 里钉（那两处未出卡）。
 *   2. +0x00 在 Clear() 里被写成 18（0x19d3f4），LoadFromChunk 又写别的值；18 的含义（类型码？版本？）未钉。
 *   3. +0xc4 那条链的节点结构只知道「+0 是 next」（Clear 0x19d49c ldr r4,[r0]），谁在往里挂、节点多大未钉。
 *   4. +0xc8/+0xcc 两个 int 的用途未钉（本卡只证被清零）。
 */

/* ===== 逐条锚点 ===== */

/* ── 1. 入口：保存 this/参数，建立零源与 15 次循环计数（0x19d4f4..0x19d50c）────────── */
/* @0x19d4f4 push {r4, r5, r6, lr} */
/* @0x19d4f8 mov r5, r0 */
/* @0x19d4fc mov r0, #0 */
/* @0x19d500 mov r6, r1 */
/* @0x19d504 mov r3, r5 */
/* @0x19d508 mov r2, r0 */
/* @0x19d50c mov r4, #15 */

/* ── 2. 七个字段清零：+0xc8 +0xc4 +0xcc +0xd4 +0xd0 +0xd8 +0x14（0x19d510..0x19d528）── */
/* @0x19d510 str r0, [r5, #0xc8] */
/* @0x19d514 str r0, [r5, #0xc4] */
/* @0x19d518 str r0, [r5, #0xcc] */
/* @0x19d51c str r0, [r5, #0xd4] */
/* @0x19d520 str r0, [r5, #0xd0] */
/* @0x19d524 str r0, [r5, #0xd8] */
/* @0x19d528 str r0, [r5, #0x14] */

/* ── 3. 15 个事件类型槽零化：{+0x4c count, +0x50 array} 步长 8（0x19d52c..0x19d53c）──── */
/* @0x19d52c subs r4, r4, #1 */
/* @0x19d530 str r2, [r3, #0x50] */
/* @0x19d534 str r2, [r3, #0x4c] */
/* @0x19d538 add r3, r3, #8 */
/* @0x19d53c bne 0x19d52c <_ZN9CObjectGMC2Ei+0x38> */

/* ── 4. Clear()：空表释放（0x19d540..0x19d544）─────────────────────────────────────── */
/* @0x19d540 mov r0, r5 */
/* @0x19d544 bl 0x19d3d8 <_ZN9CObjectGM5ClearEv> */

/* ── 5. 存构造参数 +0x18、清零 +0x48、返回 this（0x19d548..0x19d554）────────────────── */
/* @0x19d548 str r6, [r5, #0x18] */
/* @0x19d54c str r4, [r5, #0x48] */
/* @0x19d550 mov r0, r5 */
/* @0x19d554 pop {r4, r5, r6, pc} */
