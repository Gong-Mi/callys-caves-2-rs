/* cally 逆向卡：DoTheWork（原版 libyoyo.so，armv7）
 * @func 0x2a16dc 0x2a1794  size 184  46 条（0x2a1780..0x2a1790 是 5 个 literal 字，objdump 译成 andseq/andeq/ldrheq）
 * 级别: 正文（4 个调用、两个分支、srand48 种子、三处虚表消息输出、返回值全部落地；open 只剩「控制台实例是哪个子类」
 *            与「被调函数自己的返回值语义」，都不改变本函数的控制流）
 * 符号: _Z9DoTheWorkv → void DoTheWork()
 * 位置: Java_com_yoyogames_runner_RunnerJNILib_Startup(0x29062c) → bl BeginToEnd(0x290704) → BeginToEnd 尾调本函数
 *       （0x2a1ab0 的 b 0x2a16dc）。也就是说它是「JNI 启动 → 真正跑游戏」的最后一段。
 *       全库对 0x2a16dc 的引用只有这一处。
 *
 * ── 逐段语义（地址即锚点）─────────────────────────────────────────
 *   0x2a16e0..0x2a16e8   srand48(0x2012e4 = 2101988)：硬编码种子，不是 time()。每次启动 rand48 序列相同。
 *   0x2a16ec             RunnerLoadWad()：内部先经同一个控制台槽（0x3efb24 → 0x3eb6b8 → 0x479d08）打印 "LoadGameData()\n"，
 *                        再尾调 LoadGameData(0x1ddce4)；它的返回值就是 LoadGameData 的返回值。
 *   0x2a16f0..0x2a16f4   r4 = 返回值；== 0 → 失败分支（0x2a1758）。
 *   ── 成功分支 ──
 *   0x2a16f8             Variable_Global_Init()：初始化全局变量表（成功后才会做）。
 *   0x2a16fc..0x2a171c   取全局控制台对象：GOT 0x3efb24 → 0x3eb6b8（.data.rel.ro 的对象指针槽）→ 对象 0x479d08；
 *                        再 obj->[0] 取虚表、[vtable+0xc] 取函数，r0=对象、r1="PrepareGame()\n"(0x35a048) → blx。
 *                        先打印、后调用：这是「进入 PrepareGame 前先记一行」的顺序。
 *   0x2a1720             PrepareGame()；r4 = 返回值。
 *   0x2a1728 bne         非 0 → 继续；== 0 → 0x2a172c 直接返回 0（**不打印任何东西**）。
 *   0x2a1734..0x2a1748   同一对象（r5 复用）、同一虚表槽，打印 "Run_Start\n"(0x35a058) → blx。
 *   0x2a174c             Run_Start()。
 *   0x2a1750..0x2a1754   r0 = r4（= PrepareGame() 的非 0 返回值）→ 返回。
 *   ── 失败分支（RunnerLoadWad()==0）──
 *   0x2a1758..0x2a1774   另一个全局槽 GOT 0x3eed1c → 0x3eb70c → 对象 0x47a118，间接层数与成功路相同
 *                        （槽 → 指针槽 → 对象 → [对象] 取虚表），只是不需要复用对象、直接放 r0；
 *                        同一槽 +0xc，r1="Failed to load the game\n"(0x35a02c)。
 *   0x2a1778..0x2a177c   r0 = r4（此时为 0）→ 返回 0。
 *
 * ── 那个「虚表槽 +0xc」是什么（虚表本身已静态认出；实例归属为 narrowed）──────
 *   三处输出都是 obj->[0] 取虚表、[vtable+0xc] 取函数、blx，实参 (this, const char*)。
 *   .data.rel.ro 里紧邻的两张控制台虚表：TConsole 0x3eb6e0（+0x8 = TConsole::Create、+0xc = TConsole::Output 0xc481c）、
 *   TRelConsole 0x3eb6f8（+0xc = TRelConsole::Output 0xc4890）；typeinfo 串 "8TConsole"/"11TRelConsole" 在 0x3eb6c4/0x3eb6cc，
 *   紧贴在这两张表前面。→ 该槽在这两张表里的落点都是 TConsole::Output(const char*, ...)；据此外推为控制台打印，
 *   但「对象 vptr 确实指向这两张表之一」只能靠构造期代码取证（见 open 第 1 条），所以这条外推记为 narrowed。
 *   旁证：CDS_Grid::Cell_Operation 越界时用完全相同的分派打印
 *   "Grid %d, index out of bounds writing [%d,%d] - size is [%d,%d]\n"（0x207d78..0x207d9c 七条指令与 0x2a1758..0x2a1774 一一对应）。
 *   两条 trace 串的措辞也自洽：LoadGameData() / PrepareGame() / Run_Start —— 打印的都是「即将进入的函数名」。
 *   两个对象都在 .bss（0x479d08 / 0x47a118），虚表指针由构造期写入，静态只看到 .data.rel.ro 里的对象指针槽，
 *   所以「实例是 TConsole 还是 TRelConsole/TErrStreamConsole」仍未定 → open。
 *
 * ── 已证的硬事实（可直接引用）─────────────────────────────────────
 *   1. 顺序固定：srand48 → RunnerLoadWad → 成功则 (Variable_Global_Init → 打印 PrepareGame() → PrepareGame →
 *      打印 Run_Start → Run_Start)，失败则 (打印 Failed to load the game → 返回 0)。
 *      三处打印中，PrepareGame()/Run_Start 的打印在调用**之前**，Failed 的打印是失败后的汇报。
 *   2. 返回值：失败 = 0；成功 = PrepareGame() 的非 0 返回值（不是 1，也不是 RunnerLoadWad 的返回值）。
 *   3. 两个 0/非 0 判据各自独立：RunnerLoadWad 决定「有没有 WAD」，PrepareGame 决定「要不要 Run_Start」。
 *   4. 没有栈帧：只 push {r3,r4,r5,lr}（r3 是占位），不 sub sp；活变量只有 r4（返回值暂存）与 r5（控制台对象）。
 *   5. srand48 的种子是硬编码 0x2012e4，不是 time()：每次启动的 rand48 序列相同（可复现）。
 *   6. 只有成功路会调用 Variable_Global_Init —— 加载失败时全局变量表保持未初始化状态。
 *
 * ── open ─────────────────────────────────────────────────────────
 *   · 0x479d08 / 0x47a118 两个控制台实例的具体子类（虚表在 .bss，静态看不到写入点）；
 *   · RunnerLoadWad(0x1df59c) 与 PrepareGame(0x1df714) 自己的返回值语义（本卡只证 0/非 0 的用法）；
 *   · Variable_Global_Init(0x1f3354) 具体初始化哪些全局表（未出卡）；
 *   · 三条 trace 是否受某 debug 开关控制 —— 本函数里没有任何条件，恒打印。
 */
/* ── §1 前置：硬编码种子 + 加载 WAD（失败即整段结束）─────────────────────────── */
/* @0x2a16dc push {r3, r4, r5, lr} —— 帧：push {r3,r4,r5,lr}（r3 占位），不 sub sp */
/* @0x2a16e0 movw r0, #0x12e4 —— 低半 0x12e4 */
/* @0x2a16e4 movt r0, #0x20 —— 高半 0x20 → r0 = 0x2012e4 = 2101988 */
/* @0x2a16e8 bl 0xb69c4 <srand48@plt> —— srand48(2101988)（固定种子） */
/* @0x2a16ec bl 0x1df59c <_Z13RunnerLoadWadv> —— RunnerLoadWad()（内部打印 LoadGameData() 后尾调 LoadGameData） */
/* @0x2a16f0 subs r4, r0, #0 —— r4 = 返回值，同时置标志 */
/* @0x2a16f4 beq 0x2a1758 <_Z9DoTheWorkv+0x7c> —— == 0 → 失败分支 */
/* ── §2 成功分支：全局变量初始化 → 打印 PrepareGame() → PrepareGame() ─────────── */
/* @0x2a16f8 bl 0x1f3354 <_Z20Variable_Global_Initv> —— Variable_Global_Init()（仅成功路） */
/* @0x2a16fc ldr r3, [pc, #0x7c] —— GOT 增量 0x14e418 */
/* @0x2a1700 ldr r1, [pc, #0x7c] —— 串增量 0xb8938（0x35a048） */
/* @0x2a1704 ldr r3, [pc, r3] —— r3 = *(0x3efb24) = 0x3eb6b8（对象指针槽） */
/* @0x2a1708 add r1, pc, r1 —— r1 = "PrepareGame()\n" */
/* @0x2a170c ldr r5, [r3] —— r5 = 控制台对象 0x479d08 */
/* @0x2a1710 ldr r3, [r5] —— r3 = 虚表 */
/* @0x2a1714 mov r0, r5 —— this */
/* @0x2a1718 ldr r3, [r3, #0xc] —— 槽 +0xc = Output */
/* @0x2a171c blx r3 —— 打印 PrepareGame()\n */
/* @0x2a1720 bl 0x1df714 <_Z11PrepareGamev> —— PrepareGame() */
/* @0x2a1724 subs r4, r0, #0 —— r4 = 返回值 */
/* ── §3 PrepareGame()==0：不打印、不跑 Run_Start，直接返回 0 ────────────────── */
/* @0x2a1728 bne 0x2a1734 <_Z9DoTheWorkv+0x58> —— 非 0 → 继续 */
/* @0x2a172c mov r0, r4 —— r0 = 0 */
/* @0x2a1730 pop {r3, r4, r5, pc} —— 返回 0（静默失败） */
/* ── §4 打印 Run_Start → Run_Start() → 返回 PrepareGame 的非 0 值 ────────────── */
/* @0x2a1734 ldr r3, [r5] —— r3 = 虚表（复用 r5） */
/* @0x2a1738 mov r0, r5 —— this */
/* @0x2a173c ldr r1, [pc, #0x44] —— 串增量 0xb890c（0x35a058） */
/* @0x2a1740 ldr r3, [r3, #0xc] —— 槽 +0xc */
/* @0x2a1744 add r1, pc, r1 —— r1 = "Run_Start\n" */
/* @0x2a1748 blx r3 —— 打印 Run_Start\n */
/* @0x2a174c bl 0x1d4ed8 <_Z9Run_Startv> —— Run_Start() */
/* @0x2a1750 mov r0, r4 —— r0 = r4（PrepareGame 的非 0 值） */
/* @0x2a1754 pop {r3, r4, r5, pc} —— 返回非 0 */
/* ── §5 失败分支：另一控制台对象打印 Failed to load the game，返回 0 ──────────── */
/* @0x2a1758 ldr r3, [pc, #0x2c] —— GOT 增量 0x14bfb4 */
/* @0x2a175c ldr r1, [pc, #0x2c] —— 串增量 0xb88c0（0x35a02c） */
/* @0x2a1760 ldr r3, [pc, r3] —— r3 = *(0x3eed1c) = 0x3eb70c（另一个对象指针槽） */
/* @0x2a1764 add r1, pc, r1 —— r1 = "Failed to load the game\n" */
/* @0x2a1768 ldr r0, [r3] —— r0 = 对象 0x47a118（与成功路同层数：槽→指针槽→对象→虚表） */
/* @0x2a176c ldr r3, [r0] —— r3 = 虚表 */
/* @0x2a1770 ldr r3, [r3, #0xc] —— 槽 +0xc */
/* @0x2a1774 blx r3 —— 打印失败串 */
/* @0x2a1778 mov r0, r4 —— r0 = 0 */
/* @0x2a177c pop {r3, r4, r5, pc} —— 返回 0 */
/* ── §6 literal pool：5 个数据字（objdump 译成 andseq/andeq/ldrheq），非指令 ──── */
/* @0x2a1780 andseq lr, r4, r8, lsl r4 —— literal 0x14e418：成功路控制台槽的 GOT 增量（非指令） */
/* @0x2a1784 andeq r8, r11, r8, lsr r9 —— literal 0xb8938：PrepareGame()\n 的 pc 增量（非指令） */
/* @0x2a1788 andeq r8, r11, r12, lsl #18 —— literal 0xb890c：Run_Start\n 的 pc 增量（非指令） */
/* @0x2a178c ldrheq r11, [r4], -r4 —— literal 0x14bfb4：失败路控制台槽的 GOT 增量（非指令） */
/* @0x2a1790 andeq r8, r11, r0, asr #17 —— literal 0xb88c0：Failed to load the game\n 的 pc 增量（非指令） */
