/* cally 逆向卡：UpdateActiveLists（原版 libyoyo.so，armv7）
 * @func 0x1d30a4 0x1d3164  size 192  48 条（42 条指令 + 6 个字面量池字，池 0x1d314c..0x1d3160）
 * 级别: 正文（48/48 条锚定；五个 GOT 槽→五个 .bss 全局全部落地，三个 handler 与三个列表逐一绑定，profile 开关成对）
 * 符号: _Z17UpdateActiveListsv → void UpdateActiveLists()
 *
 * ── 一句话 ──────────────────────────────────────────────────────
 *   每帧的「待办列表」冲刷器：三个全局列表的 +8 计数只要非 0，就跑对应的重建函数，
 *   跑完跳到下一个检查；全程带一层可选的 CProfiler 计时（Push(6,7) / Pop）。无参、无返回、无循环。
 *
 * ── 全局寻址：一个 .got 基址 + 五个负偏移 ─────────────────────────
 *   r4 = pc(0x1d30b8) + 字面量(0x1d314c = 0x0021eba0) = 0x3F1C58 —— 落在 .got 段（0x3ed718..0x3f2000）内的锚点。
 *   之后所有全局都是 ldr rX,[r4, rY] 取 GOT 槽，槽内是 R_ARM_RELATIVE 重定位后的本模块 .bss 地址
 *   （readelf -r 逐条确认：五个槽全部 R_ARM_RELATIVE，addend 已在文件里，不是外部符号）：
 *     偏移 -0x40e8 (=0x3edb70) → 0x757e7c  1 字节开关
 *     偏移 -0x40e4 (=0x3edb74) → 0x757e80  CProfiler 实例（Push/Pop 共用）
 *     偏移 -0x4008 (=0x3edc50) → 0x542a4c  列表 A，count 在 +8
 *     偏移 -0x4010 (=0x3edc48) → 0x542a64  列表 B，count 在 +8
 *     偏移 -0x3bac (=0x3ee0ac) → 0x542a58  列表 C，count 在 +8
 *   字面量池：0x1d3150 = 0xffffbf18(-0x40e8)、0x1d3154 = 0xffffbff8(-0x4008)、0x1d3158 = 0xffffbff0(-0x4010)、
 *              0x1d315c = 0xffffc454(-0x3bac)、0x1d3160 = 0xffffbf1c(-0x40e4)；0x1d314c 是唯一非负的那个锚点偏移。
 *
 * ── 三个列表 → 三个 handler（用 handler 自己的取址反证，不是靠顺序猜）───────
 *   A 0x542a4c +8≠0 → ProcessActivateDeactveLists(0x1d3074)
 *       反证：该函数第二条取址 pc(0x1d3098)+0x21abb8 = GOT 0x3edc50 → 0x542a4c，并在体内 str 0,[r3,#8] 清零；
 *       它先拿 CRoom 单例（pc 0x1d3084+0x21a8ac = GOT 0x3ed930）调 CRoom::UpdateActive()。
 *   B 0x542a64 +8≠0 → ChangeInstanceTypes(0x1d2ea0)
 *       反证：pc(0x1d2eb0)+0x21ad98 = GOT 0x3edc48 → 0x542a64；体内 for(i<[obj+8]) CInstance::RelinkObjectTypes(obj->[i])，末尾 [obj+8]=0。
 *   C 0x542a58 +8≠0 → ChangeInstanceDepths(0x1d2ee8)
 *       反证：pc(0x1d2ef8)+0x21b1b4 = GOT 0x3ee0ac → 0x542a58；体内同样以 [obj+8] 做计数循环。
 *   ⇒ 检查的对象与处理的对象逐一重合，这是本卡最硬的一处交叉证据；+8 是「待办条数」而不是布尔脏位。
 *   三个列表首地址 0x542a4c / 0x542a58 / 0x542a64 步长 12（{ptr@+0, ?@+4, count@+8}），落在同一片 .bss。
 *
 * ── 计时开关：同一字节进、同一字节出 ─────────────────────────────
 *   0x757e7c 的字节在入口读一次（0x1d30b8/0x1d30bc）：非 0 → CProfiler::Push(0x757e80, 6, 7)（0x1d3134..0x1d3144）；
 *   结尾 0x1d3100 再读同一字节：为 0 直接 popeq 返回，非 0 则尾跳 CProfiler::Pop(0x757e80)（0x1d3114..0x1d3118）。
 *   Push 内部先 Timing_Time() 再 FindOrCreateNode(6,7)，压一条 {a,b,node,time} 记录 ⇒ (6,7) 是节区/子项编号。
 *   ⇒ Push 与 Pop 严格配对（同字节、同对象、同一次调用内），不存在只 Push 不 Pop 的路径。
 *
 * ── 控制流骨架（无循环、无早退、每条 if 都「处理完落到下一个检查」）──────
 *   入口 → [profile?] Push → 检查 A → 检查 B → 检查 C → [profile?] Pop → 返回
 *   三条 b 是回接到下一个检查的本地回跳（0x1d3130→0x1d30d8、0x1d3128→0x1d30ec、0x1d3120→0x1d3100），
 *   不是循环：三个检查各只有一条前向路径，一帧内每个 handler 最多跑一次。
 *
 * 结论（新增五条硬事实）:
 *   1. UpdateActiveLists 是「三个待办队列的每帧冲刷」，判据是 [list+8] 计数非 0，处理完由 handler 自己把计数清 0。
 *   2. 三个列表是同一模板的三份实例（12 字节、count@+8，地址相邻 0x542a4c/58/64），与 CRoom::UpdateActive、
 *      CInstance::RelinkObjectTypes、深度重建三者一一对应。
 *   3. 全局访问统一走 0x3f1c58 这个 .got 锚点 + 负偏移，五个槽都是 R_ARM_RELATIVE ⇒ 目标是本模块 .bss，
 *      不是导入符号；因此无法从符号表反查名字，只能靠 handler 体内的取址互证。
 *   4. 计时开关是 1 字节全局 0x757e7c，profile 对象是紧邻的 0x757e80（差 4 字节），二者在本函数内成对使用。
 *   5. 函数本身零状态：不建帧（push {r3,r4,r5,lr} 只为对齐）、不返回、不改任何列表字段。
 * open:
 *   1. 三个列表对象的类名未定：只能证 12 字节布局与 count@+8，.bss 无符号可查。
 *   2. 0x757e7c 与 0x757e80 是否属于同一聚合体（前者恰在后者前 4 字节）未定，只证同函数内配对使用。
 *   3. Push(6,7) 的 (6,7) 语义只到「FindOrCreateNode(a,b) 的入参」这一层，节区编号表未展开。
 */
/* ── 帧：r3 入栈只为 4 字对齐 */
/* @0x1d30a4 push {r3, r4, r5, lr} */
/* 锚点偏移 0x0021eba0（配 0x1d30b0 的 add 用） */
/* @0x1d30a8 ldr r4, [pc, #0x9c] */
/* 第一个负偏移 -0x40e8（0x1d3150 处的池字） */
/* @0x1d30ac ldr r3, [pc, #0x9c] */
/* r4 = 0x1d30b8 + 0x21eba0 = 0x3F1C58（.got 内锚点） */
/* @0x1d30b0 add r4, pc, r4 */
/* r5 = *(0x3edb70) = 0x757e7c（1 字节开关所在对象的地址） */
/* @0x1d30b4 ldr r5, [r4, r3] */
/* 入口读开关 */
/* @0x1d30b8 ldrb r3, [r5] */
/* @0x1d30bc cmp r3, #0 */
/* 非 0 → 0x1d3134 起做 CProfiler::Push(this, 6, 7) */
/* @0x1d30c0 bne 0x1d3134 <_Z17UpdateActiveListsv+0x90> */
/* ── 检查 A：-0x4008 → GOT 0x3edc50 → 列表 0x542a4c */
/* @0x1d30c4 ldr r3, [pc, #0x88] */
/* 取槽内 .bss 地址 */
/* @0x1d30c8 ldr r3, [r4, r3] */
/* count @+8 */
/* @0x1d30cc ldr r3, [r3, #0x8] */
/* @0x1d30d0 cmp r3, #0 */
/* 非 0 → 0x1d312c 跑 ProcessActivateDeactveLists，再回 0x1d30d8 */
/* @0x1d30d4 bne 0x1d312c <_Z17UpdateActiveListsv+0x88> */
/* ── 检查 B：-0x4010 → GOT 0x3edc48 → 列表 0x542a64 */
/* @0x1d30d8 ldr r3, [pc, #0x78] */
/* @0x1d30dc ldr r3, [r4, r3] */
/* count @+8 */
/* @0x1d30e0 ldr r3, [r3, #0x8] */
/* @0x1d30e4 cmp r3, #0 */
/* 非 0 → 0x1d3124 跑 ChangeInstanceTypes，再回 0x1d30ec */
/* @0x1d30e8 bne 0x1d3124 <_Z17UpdateActiveListsv+0x80> */
/* ── 检查 C：-0x3bac → GOT 0x3ee0ac → 列表 0x542a58 */
/* @0x1d30ec ldr r3, [pc, #0x68] */
/* @0x1d30f0 ldr r3, [r4, r3] */
/* count @+8 */
/* @0x1d30f4 ldr r3, [r3, #0x8] */
/* @0x1d30f8 cmp r3, #0 */
/* 非 0 → 0x1d311c 跑 ChangeInstanceDepths，再回 0x1d3100 */
/* @0x1d30fc bne 0x1d311c <_Z17UpdateActiveListsv+0x78> */
/* ── 出口：重读同一个开关字节（不信任入口那次的值） */
/* @0x1d3100 ldrb r3, [r5] */
/* @0x1d3104 cmp r3, #0 */
/* 开关为 0 → 条件 pop 直接返回（不碰 CProfiler） */
/* @0x1d3108 popeq {r3, r4, r5, pc} */
/* -0x40e4（池字 0x1d3160）→ GOT 0x3edb74 → 0x757e80 */
/* @0x1d310c ldr r3, [pc, #0x4c] */
/* r0 = CProfiler 实例地址（this） */
/* @0x1d3110 ldr r0, [r4, r3] */
/* 先恢复寄存器与 lr */
/* @0x1d3114 pop {r3, r4, r5, lr} */
/* 尾跳 CProfiler::Pop，返回值直回调用者 */
/* @0x1d3118 b 0x2a08ac <_ZN9CProfiler3PopEv> */
/* handler C（ChangeInstanceDepths，396 字节） */
/* @0x1d311c bl 0x1d2ee8 <_Z20ChangeInstanceDepthsv> */
/* 回跳到「重读开关」 */
/* @0x1d3120 b 0x1d3100 <_Z17UpdateActiveListsv+0x5c> */
/* handler B（ChangeInstanceTypes，72 字节） */
/* @0x1d3124 bl 0x1d2ea0 <_Z19ChangeInstanceTypesv> */
/* 回跳到检查 C */
/* @0x1d3128 b 0x1d30ec <_Z17UpdateActiveListsv+0x48> */
/* handler A（ProcessActivateDeactveLists，48 字节） */
/* @0x1d312c bl 0x1d3074 <_Z27ProcessActivateDeactveListsv> */
/* 回跳到检查 B */
/* @0x1d3130 b 0x1d30d8 <_Z17UpdateActiveListsv+0x34> */
/* ── profile 入栈：-0x40e4（与 Pop 同一槽） */
/* @0x1d3134 ldr r3, [pc, #0x24] */
/* 第 2 实参 6 */
/* @0x1d3138 mov r1, #6 */
/* 第 3 实参 7 */
/* @0x1d313c mov r2, #7 */
/* this = 0x757e80 */
/* @0x1d3140 ldr r0, [r4, r3] */
/* CProfiler::Push(int,int)：Timing_Time + FindOrCreateNode(6,7) 后压记录 */
/* @0x1d3144 bl 0x2a0738 <_ZN9CProfiler4PushEii> */
/* Push 完落到检查 A */
/* @0x1d3148 b 0x1d30c4 <_Z17UpdateActiveListsv+0x20> */
/* literal pool 字 0x0021eba0（objdump 译成 eoreq，按规矩保留；不是指令） */
/* @0x1d314c eoreq lr, r1, r0, lsr #23 */
/* literal pool：-0x40e8 */
/* @0x1d3150 .word 0xffffbf18 */
/* literal pool：-0x4008 */
/* @0x1d3154 .word 0xffffbff8 */
/* literal pool：-0x4010 */
/* @0x1d3158 .word 0xffffbff0 */
/* literal pool：-0x3bac */
/* @0x1d315c .word 0xffffc454 */
/* literal pool：-0x40e4（Push 与 Pop 共用这一个字） */
/* @0x1d3160 .word 0xffffbf1c */
