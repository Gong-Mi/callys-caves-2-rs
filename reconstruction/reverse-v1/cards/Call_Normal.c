/* cally 逆向卡：Call_Normal（原版 libyoyo.so，armv7）
 * @func 0x211fa8 0x212b0c  size 2916  729 条（727 条真指令 + 尾部 2 个字面池字）
 * 级别: 正文（729/729 逐条落锚；键公式、62 路分派逐键标定到 case 底址、两种返回口径、每参 real/string 的
 *       AAPCS 装填全证；62 个 case 的「char* 个数 / double 个数」已按指令逐一对上键位，0 例外）
 * 符号: _Z11Call_NormaliPdPPKcP6RValue → Call_Normal(int id, double* args, const char** strs, RValue* result)
 *       返回类型未定（唯一已知调用方 DLL_Call 不读 r0）；四个形参的身份由用法反推：
 *       r1 = double args[]（每实参 8 B）、r2 = const char* strs[]（每实参 4 B，只有字符串实参有效）、
 *       r3 = RValue* result（只写 [0]/[4] 与 +0xc 的 tag，全函数从不读）。
 * 导出: .dynsym 里 GLOBAL DEFAULT —— 与 DLL_Call / Call_Real / Call_RValue 一样是公开 ABI，不是内部私有。
 * 位置: 0x211fa8..0x212b00 是代码，紧跟 2 个池字；前邻 Call_Real(0x21161c)，后邻 DLL_Call(0x212b10)。
 *       孪生体 Call_Normal_std @0x210ab8 与本函数**代码逐字同构**（差异只有 3 个字，全为重定位，见末节）。
 *
 * ── 一句话 ────────────────────────────────────────────────────────────
 *   把「已经摊平成 C 形参」的实参按表项声明的签名装进 ARM 寄存器，直接 blx 表项的 +0xc。
 *   不压 VM 帧、不进 DoCallScript、不碰 DoCall 的 80 B 内建描述符表 —— 它是 id 表调用的「≤4 实参快路径」。
 *
 * ── 与 DoCall / DoCallScript / DoCallLibrary 的分工（本卡重点之一）────────
 *   字节码侧（VM opcode 调用谁）：
 *     DoCall(0xe8b48)        先按 id 区间四分流（<100000 内建 / +100000 脚本 / 499999 间接 / >500000 扩展），
 *                            再按 kind 二分流（2 = 按 id、5 = 按可调用 RValue）；内建路直接 blx builtinTable[id*80+0x40]，
 *                            只有脚本路和 kind5 才进 DoCallScript。实参是 VM 栈上的 16 B RValue 串，
 *                            argc = opcode 低 16 位。
 *     DoCallScript(0xe8588)  唯一的压帧入口（frame = sp-60，写 exec+0x28/+0x2c/+0x44/+0x50/+0x24）。
 *     DoCallLibrary(0xe3e58) 80 B 描述符表驱动，调用协议 fn(&result, exec[0x14], exec[0x18], nargs, args)。
 *   C 侧（本函数这一族）：
 *     DLL_Call(0x212b10)     把 RValue* args 拆成 double[] + char*[] 两套数组，再按 (argc, 表项 +0x10) 选叶子；
 *     Call_Normal / Call_Normal_std(0x210ab8)           argc ≤ 4   → 本卡（62 路键分派）
 *     Call_Real   / Call_Real_std  (0x21161c/0x21012c)  argc 5..16 → 两张 12 路跳表
 *   两边只差「实参怎么摆」：字节码侧是 16 B RValue 串、类型在 tag 里；C 侧是 8 B double 串 + 4 B 指针串、
 *   每个实参是 real 还是 string 由**表项里的 4 个标志**（+0x18/+0x1c/+0x20/+0x24）而不是 RValue tag 决定。
 *   交叉核对：本函数的全部外部调用只有两处 —— 表项 +0xc（每个 case 各一次）与 YYCreateString(0xe5258)（字符串返回尾调），
 *   对 DoCall / DoCallScript / DoCallLibrary 无任何调用边；反过来，在已建索引的 95 个函数里，本函数也只有一个调用方 DLL_Call。
 *
 * ── 分派键（0x211fe8..0x212060，核心）────────────────────────────────
 *   argc = entry->[0x14]（0x211fec）、ret = entry->[0x5c]（0x211fe8）
 *   key = (ret != 0 ? 2 : 1) + Σ over i in 0..min(argc,4)-1 of (entry->[0x18+4i] == 0 ? 1 : 2) * 10^(i+1)
 *   即十进制位编码：个位 = 返回口径（1 = 返回 double，2 = 返回 char* 需装箱），
 *   第 i+1 位 = 第 i 个实参（1 = 按 double 传，2 = 按 char* 传）。
 *   例：11111 = 返回 double、4 个 double 实参；12112 = 返回 char*、(double, double, char*, double)。
 *   每一位只看表项标志的零/非零，所以每位的取值只有两种；argc 0..4 共 2+4+8+16+32 = 62 个键，
 *   62 个键各有一个独立 case 体（无共用；对不上的键落 0x212110 的普通返回，相当于 default）——
 *   2916 B 的绝大部分就是这 62 段装填代码。
 *
 * ── 62 个键 → case 底址（本卡逐个标定，全部经「char* 个数 / double 个数」交叉验证）──
 *   argc=0 : 1→0x212628 2→0x212594
 *   argc=1 : 11→0x212570 12→0x21236c 21→0x212730 22→0x2125ec
 *   argc=2 : 111→0x21265c 112→0x21222c 121→0x2129dc 122→0x2129c4
 *            211→0x212718 212→0x212430 221→0x212a08 222→0x2129f4
 *   argc=3 : 1111→0x2129a4 1112→0x212170 1121→0x212874 1122→0x212854 1211→0x2125a4 1212→0x21246c 1221→0x212a7c 1222→0x212a64
 *            2111→0x212934 2112→0x212274 2121→0x2126d4 2122→0x2126b4 2211→0x212674 2212→0x212400 2221→0x212aa8 2222→0x212a94
 *   argc=4 : 11111→0x212954 11112→0x2120cc 11121→0x21290c 11122→0x2128e4 11211→0x2125c4
 *            11212→0x2124fc 11221→0x212768 11222→0x212744 12111→0x21268c 12112→0x2122c8
 *            12121→0x21282c 12122→0x212804 12211→0x212638 12212→0x2123b8 12221→0x212a40
 *            12222→0x212a1c 21111→0x21297c 21112→0x2121d4 21121→0x2128bc 21122→0x212894
 *            21211→0x212600 21212→0x2124b0 21221→0x212ae4 21222→0x212abc 22111→0x2126f4
 *            22112→0x212324 22121→0x2127b4 22122→0x21278c 22211→0x2120f4 22212→0x212548
 *            22221→0x2127f0 22222→0x2127dc
 *
 * ── case 体的四种形状（每个体 4..9 条；体内无条件分支，只有末尾一条 b 出口）──────
 *   ① 纯 double：ldrd r0,r1,[r4] / ldrd r2,r3,[r4,#8] / ldrd r8,r9,[r4,#16]+strd ..,[sp]
 *   ② 纯 char* ：ldm r7,{r0,r1} / ldm r7,{r0,r1,r2} / ldm r7,{r0,r1,r2,r3}
 *   ③ 混合（本卡主体）：char* 只吃 4 B 寄存器、double 要 8 B 且起点偶数，所以同一 argc 的不同类型组合
 *      必须用不同的装填顺序。三个实例（地址 → 键 → 装填）：
 *        0x212430  键 212   (double,char*)               r0:r1 = args[0]、r2 = strs[1]
 *        0x2123b8  键 12212 (double,char*,char*,double)  r0:r1 = args[0]、r2 = strs[1]、r3 = strs[2]、
 *                                                        [sp] = args[3]（先把 args[3] strd 到栈，再回填寄存器）
 *        0x2124b0  键 21212 (double,char*,double,char*)  r0:r1 = args[0]、r2 = strs[1]、
 *                                                        [sp] = args[2]、[sp,#8] = strs[3]
 *      规律：实参从左到右吃「r0、r1、r2、r3、[sp]、[sp+4]、[sp+8]…」，double 占两个相邻字且起点偶数
 *      （所以前面已有 char* 时 double 会跳到 r2:r3 或直接上栈）。
 *   ④ 字符串返回壳：末尾 mov r1,r0 + b 0x21237c，与 ①②③ 正交（任何形状都可能带）
 *   公共骨架：装填 → ldr r12,[r12,#0xc]（有的体把目的寄存器换成 r3/r1）→ blx → 按口径收尾。
 *
 * ── 两种返回口径（case 体唯一的收尾差异）──────────────────────────────
 *   A. 返回 double（键个位 = 1）：stm r6,{r0,r1} 把 r0:r1 原样写进 result 的 [0]/[4]，再走普通返回(0x212110)。
 *      tag 早在 0x21206c 由 entry->[0x5c] 写好 ⇒ 这条路上 [0x5c] 必须是 0（Real）。
 *   B. 返回 char*（键个位 = 2）：mov r1,r0 把指针挪到第 2 实参位，再 b 0x21237c。0x21237c 先判 r1 == 0：
 *      为 0 就直接普通返回（**不建字符串**，result 只剩 tag 与调用前的值）；非 0 则 mov r0,r6（result）、
 *      弹栈、尾调 YYCreateString(0xe5258)（sp 已复原，所以是尾调用而不是普通调用）。
 *      YYCreateString 自己按 tag 决定是否 FREE_RValue__Pre 旧值，然后 new 12 B 头 {char* data(+0)、
 *      int refcount(+4)、int len(+8)}、写 tag=1、写 [0]=那个 12 B 头
 *      ⇒ 字符串 RValue 的 value 是这层头，不是 char* 本身。DLL_Call 取 char* 时要再解一次引用，原因即此；
 *        两处互为证据（本卡 0x212390 与 DLL_Call 0x212ccc/0x212cd4）。
 *   C. 键不在 62 个里（只可能由越界 id 撞出来）：0x212110 直落普通返回，r0 不动、result 不再被写。
 *
 * ── 边界与坑（已证，不是推测）──────────────────────────────────────
 *   1. 中止字节：0x211fbc 读全局字节（GOT 槽 0x3f13b4 → .bss 0x75527c，紧贴表对象 count@0x755274 /
 *      entries@0x755278 之后）；非 0 就立刻普通返回，**连 result 的 tag 都不写** ⇒ 这个字节是「拒绝调用」闸。
 *   2. 无越界保护：id 与 count 的比较只作用在两条 ldrlt 上（0x211fe0/0x211fe4）。id ≥ count 时 r12 仍是
 *      0x75527c 那个字节指针，接着按它当表项读 +0x5c/+0x14 ⇒ 越界 id 不是返回，而是拿垃圾表项继续跑。
 *   3. argc 只编码前 4 个实参：0x212014/0x21202c/0x212044 三次 argc 截断后，argc ≥ 4 都落到「加完第 4 位就分派」，
 *      所以 argc ≥ 5 的键与 argc = 4 同形 ⇒ 第 5 个及以后的实参被静默丢弃。本函数自己不检查 argc，
 *      已知唯一调用方 DLL_Call 用 cmp argc,#4 拦在前面（>4 走 Call_Real），所以目前不可达；属潜在坑。
 *   4. result 的 +0x8 从不被本函数写；只有 DLL_Call 会顺带清它（见 DLL_Call 卡）。
 *
 * ── std 与非 std 的差异（本卡重点之二）──────────────────────────────
 *   选择点只有一处，在 DLL_Call：0x212c54 读 entry->[0x10]，==1 才走 _std 两支（0x212c5c beq 0x212ce8）。
 *   本函数与 Call_Normal_std(0x210ab8) 的代码**逐字相同**：729 个字里只有 3 个不同 ——
 *     · 0x212390 的远跳：两边都 b 0xe5258（YYCreateString），只因相对位移不同而机器码不同；
 *     · 尾部两个池字 0x212b04/0x212b08 = 0x001df3fc/0x001df3dc；孪生体是 0x001e08ec/0x001e08cc，
 *       差值恰为 0x14F0（十进制 5360）= 两函数地址差 ⇒ 指向同一对 GOT 槽（0x3f13b4 中止字节 / 0x3f13b8 表对象）。
 *   ⇒ 在 argc ≤ 4 这条路上，std 与非 std **没有行为差异**：同一份逻辑的两个链接名，由表项 +0x10 二选一。
 *   对照组（>4 实参那一族）：Call_Real(0x21161c) 与 Call_Real_std(0x21012c) 同为 2444 B/611 条，但块顺序被重排，
 *   指令多重集只差「1 条 cmp+beq 折成 1 条 b」与 2 个池字 ⇒ 同一份逻辑的两次生成，也不是两套协议。
 *   所以「std」在这四个叶子里不改变任何寄存器/栈约定；它标记的是**表项档位**（谁把 +0x10 置 1 见 open）。
 *
 * 结论（本卡新增的硬事实）：
 *   1. 分派键是「返回口径 + 每参 real/string」的十进制位编码，62 个组合各一支；不是 argc 的 5 路跳表。
 *   2. 每参 real/string 的判据是表项 +0x18/+0x1c/+0x20/+0x24 的**零/非零**，与 RValue tag 无关 ——
 *      这是 C 侧调用与字节码侧调用的根本分界。
 *   3. 返回 char* 的函数走同一条「装箱」尾路：YYCreateString 造 12 B 头、tag=1；返回 NULL 时静默不建字符串。
 *   4. result->tag 在分派前就被写成 entry->[0x5c]，两个返回口径共用这一个写点；只有中止字节那条路逃过它。
 * open:
 *   1. 中止字节（.bss 0x75527c；被谁置 1、语义是「不许调用」还是「异常展开中」）。
 *   2. entry->[0x5c] 的取值域：代码只做零/非零，但写进 tag 后与 RValue tag 同域，1 是唯一被观察到的非零值
 *      （YYCreateString 之后固定写 1）—— 是否还存在 2/3 之类需要另证。
 *   3. entry->[0xc] 对「GML 脚本项」意味着什么（C 函数指针？预热 stub？）本卡只证到「是个可 blx 的指针」。
 *   4. 表对象 0x755274 的填充点：与 Script_Data(0x1e069c) 用的 0x544c68/0x544c70 那一对不是同一份全局
 *      （两处 GOT 目标已验证不同），两张表的关系未定。
 */
/* ── 段 1 · 序言 / 中止字节 / 表项兜取（0x211fa8..0x211fe4）── */
/* @0x211fa8 ldr r12, [pc, #0xb54] */
/* @0x211fac push {r4, r5, r6, r7, r8, r9, lr} */
/* @0x211fb0 ldr r12, [pc, r12] */
/* @0x211fb4 sub sp, sp, #20 */
/* @0x211fb8 mov r4, r1 */
/* @0x211fbc ldrb r12, [r12] */
/* @0x211fc0 mov r7, r2 */
/* @0x211fc4 mov r6, r3 */
/* @0x211fc8 cmp r12, #0 */
/* @0x211fcc bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x211fd0 ldr r3, [pc, #0xb30] */
/* @0x211fd4 ldr r3, [pc, r3] */
/* @0x211fd8 ldr r2, [r3] */
/* @0x211fdc cmp r0, r2 */
/* @0x211fe0 ldrlt r3, [r3, #0x4] */
/* @0x211fe4 ldrlt r12, [r3, r0, lsl #2] */
/* ── 段 2 · 键构造：argc 截断 + 每参 real/string 十进制位（0x211fe8..0x212060）── */
/* @0x211fe8 ldr r1, [r12, #0x5c] */
/* @0x211fec ldr r2, [r12, #0x14] */
/* @0x211ff0 cmp r1, #0 */
/* @0x211ff4 movne r3, #2 */
/* @0x211ff8 moveq r3, #1 */
/* @0x211ffc cmp r2, #0 */
/* @0x212000 ble 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x212004 ldr r0, [r12, #0x18] */
/* @0x212008 cmp r0, #0 */
/* @0x21200c addeq r3, r3, #10 */
/* @0x212010 addne r3, r3, #20 */
/* @0x212014 cmp r2, #1 */
/* @0x212018 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x21201c ldr r0, [r12, #0x1c] */
/* @0x212020 cmp r0, #0 */
/* @0x212024 addeq r3, r3, #100 */
/* @0x212028 addne r3, r3, #200 */
/* @0x21202c cmp r2, #2 */
/* @0x212030 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x212034 ldr r0, [r12, #0x20] */
/* @0x212038 cmp r0, #0 */
/* @0x21203c addeq r3, r3, #1000 */
/* @0x212040 addne r3, r3, #2000 */
/* @0x212044 cmp r2, #3 */
/* @0x212048 beq 0x212064 <_Z11Call_NormaliPdPPKcP6RValue+0xbc> */
/* @0x21204c ldr r2, [r12, #0x24] */
/* @0x212050 cmp r2, #0 */
/* @0x212054 addeq r3, r3, #9984 */
/* @0x212058 addne r3, r3, #19968 */
/* @0x21205c addeq r3, r3, #16 */
/* @0x212060 addne r3, r3, #32 */
/* ── 段 3 · 62 路二分派发：键 → case 底址（0x212064..0x21236c）── */
/* @0x212064 movw r2, #0x2b67 */
/* @0x212068 cmp r3, r2 */
/* @0x21206c str r1, [r6, #0xc] */
/* @0x212070 beq 0x212954 <_Z11Call_NormaliPdPPKcP6RValue+0x9ac> */
/* @0x212074 ble 0x212118 <_Z11Call_NormaliPdPPKcP6RValue+0x170> */
/* @0x212078 movw r2, #0x5277 */
/* @0x21207c cmp r3, r2 */
/* @0x212080 beq 0x21297c <_Z11Call_NormaliPdPPKcP6RValue+0x9d4> */
/* @0x212084 bgt 0x212190 <_Z11Call_NormaliPdPPKcP6RValue+0x1e8> */
/* @0x212088 movw r2, #0x2f4f */
/* @0x21208c cmp r3, r2 */
/* @0x212090 beq 0x21268c <_Z11Call_NormaliPdPPKcP6RValue+0x6e4> */
/* @0x212094 bgt 0x212294 <_Z11Call_NormaliPdPPKcP6RValue+0x2ec> */
/* @0x212098 sub r2, r2, #900 */
/* @0x21209c cmp r3, r2 */
/* @0x2120a0 beq 0x2125c4 <_Z11Call_NormaliPdPPKcP6RValue+0x61c> */
/* @0x2120a4 bgt 0x2124d8 <_Z11Call_NormaliPdPPKcP6RValue+0x530> */
/* @0x2120a8 movw r2, #0x2b71 */
/* @0x2120ac cmp r3, r2 */
/* @0x2120b0 beq 0x21290c <_Z11Call_NormaliPdPPKcP6RValue+0x964> */
/* @0x2120b4 add r2, r2, #1 */
/* @0x2120b8 cmp r3, r2 */
/* @0x2120bc beq 0x2128e4 <_Z11Call_NormaliPdPPKcP6RValue+0x93c> */
/* @0x2120c0 movw r2, #0x2b68 */
/* @0x2120c4 cmp r3, r2 */
/* @0x2120c8 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2120cc ldrd r2, r3, [r4, #16] */
/* @0x2120d0 ldrd r0, r1, [r4, #24] */
/* @0x2120d4 strd r2, r3, [sp] */
/* @0x2120d8 strd r0, r1, [sp, #8] */
/* @0x2120dc ldrd r0, r1, [r4] */
/* @0x2120e0 ldr r12, [r12, #0xc] */
/* @0x2120e4 ldrd r2, r3, [r4, #8] */
/* @0x2120e8 blx r12 */
/* @0x2120ec mov r1, r0 */
/* @0x2120f0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2120f4 ldr lr, [r7, #0xc] */
/* @0x2120f8 ldrd r0, r1, [r4] */
/* @0x2120fc ldmib r7, {r2, r3} */
/* @0x212100 str lr, [sp] */
/* @0x212104 ldr r12, [r12, #0xc] */
/* @0x212108 blx r12 */
/* @0x21210c stm r6, {r0, r1} */
/* ── 段 3b · 普通返回：只弹帧，不写 result（越界键与中止字节都落这里）── */
/* @0x212110 add sp, sp, #20 */
/* @0x212114 pop {r4, r5, r6, r7, r8, r9, pc} */
/* @0x212118 movw r2, #0x457 */
/* @0x21211c cmp r3, r2 */
/* @0x212120 beq 0x2129a4 <_Z11Call_NormaliPdPPKcP6RValue+0x9fc> */
/* @0x212124 ble 0x2121fc <_Z11Call_NormaliPdPPKcP6RValue+0x254> */
/* @0x212128 movw r2, #0x83f */
/* @0x21212c cmp r3, r2 */
/* @0x212130 beq 0x212934 <_Z11Call_NormaliPdPPKcP6RValue+0x98c> */
/* @0x212134 cmp r3, #2112 */
/* @0x212138 bge 0x212244 <_Z11Call_NormaliPdPPKcP6RValue+0x29c> */
/* @0x21213c sub r2, r2, #900 */
/* @0x212140 cmp r3, r2 */
/* @0x212144 beq 0x2125a4 <_Z11Call_NormaliPdPPKcP6RValue+0x5fc> */
/* @0x212148 bgt 0x212448 <_Z11Call_NormaliPdPPKcP6RValue+0x4a0> */
/* @0x21214c movw r2, #0x461 */
/* @0x212150 cmp r3, r2 */
/* @0x212154 beq 0x212874 <_Z11Call_NormaliPdPPKcP6RValue+0x8cc> */
/* @0x212158 add r2, r2, #1 */
/* @0x21215c cmp r3, r2 */
/* @0x212160 beq 0x212854 <_Z11Call_NormaliPdPPKcP6RValue+0x8ac> */
/* @0x212164 movw r2, #0x458 */
/* @0x212168 cmp r3, r2 */
/* @0x21216c bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212170 ldrd r2, r3, [r4, #16] */
/* @0x212174 ldrd r0, r1, [r4] */
/* @0x212178 strd r2, r3, [sp] */
/* @0x21217c ldr r12, [r12, #0xc] */
/* @0x212180 ldrd r2, r3, [r4, #8] */
/* @0x212184 blx r12 */
/* @0x212188 mov r1, r0 */
/* @0x21218c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212190 movw r2, #0x565f */
/* @0x212194 cmp r3, r2 */
/* @0x212198 beq 0x2126f4 <_Z11Call_NormaliPdPPKcP6RValue+0x74c> */
/* @0x21219c bgt 0x2122f0 <_Z11Call_NormaliPdPPKcP6RValue+0x348> */
/* @0x2121a0 sub r2, r2, #900 */
/* @0x2121a4 cmp r3, r2 */
/* @0x2121a8 beq 0x212600 <_Z11Call_NormaliPdPPKcP6RValue+0x658> */
/* @0x2121ac bgt 0x21248c <_Z11Call_NormaliPdPPKcP6RValue+0x4e4> */
/* @0x2121b0 movw r2, #0x5281 */
/* @0x2121b4 cmp r3, r2 */
/* @0x2121b8 beq 0x2128bc <_Z11Call_NormaliPdPPKcP6RValue+0x914> */
/* @0x2121bc add r2, r2, #1 */
/* @0x2121c0 cmp r3, r2 */
/* @0x2121c4 beq 0x212894 <_Z11Call_NormaliPdPPKcP6RValue+0x8ec> */
/* @0x2121c8 movw r2, #0x5278 */
/* @0x2121cc cmp r3, r2 */
/* @0x2121d0 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2121d4 ldrd r2, r3, [r4, #16] */
/* @0x2121d8 ldr lr, [r7, #0xc] */
/* @0x2121dc ldrd r0, r1, [r4] */
/* @0x2121e0 strd r2, r3, [sp] */
/* @0x2121e4 ldrd r2, r3, [r4, #8] */
/* @0x2121e8 str lr, [sp, #0x8] */
/* @0x2121ec ldr r12, [r12, #0xc] */
/* @0x2121f0 blx r12 */
/* @0x2121f4 mov r1, r0 */
/* @0x2121f8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2121fc cmp r3, #111 */
/* @0x212200 beq 0x21265c <_Z11Call_NormaliPdPPKcP6RValue+0x6b4> */
/* @0x212204 ble 0x212348 <_Z11Call_NormaliPdPPKcP6RValue+0x3a0> */
/* @0x212208 cmp r3, #211 */
/* @0x21220c beq 0x212718 <_Z11Call_NormaliPdPPKcP6RValue+0x770> */
/* @0x212210 bgt 0x212418 <_Z11Call_NormaliPdPPKcP6RValue+0x470> */
/* @0x212214 cmp r3, #121 */
/* @0x212218 beq 0x2129dc <_Z11Call_NormaliPdPPKcP6RValue+0xa34> */
/* @0x21221c cmp r3, #122 */
/* @0x212220 beq 0x2129c4 <_Z11Call_NormaliPdPPKcP6RValue+0xa1c> */
/* @0x212224 cmp r3, #112 */
/* @0x212228 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21222c ldrd r0, r1, [r4] */
/* @0x212230 ldr r12, [r12, #0xc] */
/* @0x212234 ldrd r2, r3, [r4, #8] */
/* @0x212238 blx r12 */
/* @0x21223c mov r1, r0 */
/* @0x212240 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212244 movw r2, #0x8a3 */
/* @0x212248 cmp r3, r2 */
/* @0x21224c beq 0x212674 <_Z11Call_NormaliPdPPKcP6RValue+0x6cc> */
/* @0x212250 bgt 0x2123dc <_Z11Call_NormaliPdPPKcP6RValue+0x434> */
/* @0x212254 movw r2, #0x849 */
/* @0x212258 cmp r3, r2 */
/* @0x21225c beq 0x2126d4 <_Z11Call_NormaliPdPPKcP6RValue+0x72c> */
/* @0x212260 add r2, r2, #1 */
/* @0x212264 cmp r3, r2 */
/* @0x212268 beq 0x2126b4 <_Z11Call_NormaliPdPPKcP6RValue+0x70c> */
/* @0x21226c cmp r3, #2112 */
/* @0x212270 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212274 ldr lr, [r7, #0x8] */
/* @0x212278 ldrd r0, r1, [r4] */
/* @0x21227c ldrd r2, r3, [r4, #8] */
/* @0x212280 str lr, [sp] */
/* @0x212284 ldr r12, [r12, #0xc] */
/* @0x212288 blx r12 */
/* @0x21228c mov r1, r0 */
/* @0x212290 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212294 movw r2, #0x2fb3 */
/* @0x212298 cmp r3, r2 */
/* @0x21229c beq 0x212638 <_Z11Call_NormaliPdPPKcP6RValue+0x690> */
/* @0x2122a0 bgt 0x212394 <_Z11Call_NormaliPdPPKcP6RValue+0x3ec> */
/* @0x2122a4 movw r2, #0x2f59 */
/* @0x2122a8 cmp r3, r2 */
/* @0x2122ac beq 0x21282c <_Z11Call_NormaliPdPPKcP6RValue+0x884> */
/* @0x2122b0 add r2, r2, #1 */
/* @0x2122b4 cmp r3, r2 */
/* @0x2122b8 beq 0x212804 <_Z11Call_NormaliPdPPKcP6RValue+0x85c> */
/* @0x2122bc movw r2, #0x2f50 */
/* @0x2122c0 cmp r3, r2 */
/* @0x2122c4 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2122c8 ldrd r2, r3, [r4, #24] */
/* @0x2122cc ldr lr, [r7, #0x8] */
/* @0x2122d0 ldrd r0, r1, [r4] */
/* @0x2122d4 strd r2, r3, [sp, #8] */
/* @0x2122d8 ldrd r2, r3, [r4, #8] */
/* @0x2122dc str lr, [sp] */
/* @0x2122e0 ldr r12, [r12, #0xc] */
/* @0x2122e4 blx r12 */
/* @0x2122e8 mov r1, r0 */
/* @0x2122ec b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2122f0 movw r2, #0x56c3 */
/* @0x2122f4 cmp r3, r2 */
/* @0x2122f8 beq 0x2120f4 <_Z11Call_NormaliPdPPKcP6RValue+0x14c> */
/* @0x2122fc bgt 0x212524 <_Z11Call_NormaliPdPPKcP6RValue+0x57c> */
/* @0x212300 movw r2, #0x5669 */
/* @0x212304 cmp r3, r2 */
/* @0x212308 beq 0x2127b4 <_Z11Call_NormaliPdPPKcP6RValue+0x80c> */
/* @0x21230c add r2, r2, #1 */
/* @0x212310 cmp r3, r2 */
/* @0x212314 beq 0x21278c <_Z11Call_NormaliPdPPKcP6RValue+0x7e4> */
/* @0x212318 movw r2, #0x5660 */
/* @0x21231c cmp r3, r2 */
/* @0x212320 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212324 ldr r5, [r7, #0x8] */
/* @0x212328 ldr lr, [r7, #0xc] */
/* @0x21232c ldrd r0, r1, [r4] */
/* @0x212330 ldrd r2, r3, [r4, #8] */
/* @0x212334 stm sp, {r5, lr} */
/* @0x212338 ldr r12, [r12, #0xc] */
/* @0x21233c blx r12 */
/* @0x212340 mov r1, r0 */
/* @0x212344 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212348 cmp r3, #11 */
/* @0x21234c beq 0x212570 <_Z11Call_NormaliPdPPKcP6RValue+0x5c8> */
/* @0x212350 ble 0x212584 <_Z11Call_NormaliPdPPKcP6RValue+0x5dc> */
/* @0x212354 cmp r3, #21 */
/* @0x212358 beq 0x212730 <_Z11Call_NormaliPdPPKcP6RValue+0x788> */
/* @0x21235c cmp r3, #22 */
/* @0x212360 beq 0x2125ec <_Z11Call_NormaliPdPPKcP6RValue+0x644> */
/* @0x212364 cmp r3, #12 */
/* @0x212368 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21236c ldrd r0, r1, [r4] */
/* @0x212370 ldr r3, [r12, #0xc] */
/* @0x212374 blx r3 */
/* @0x212378 mov r1, r0 */
/* ── 段 4 · 字符串返回尾调：NULL 静默返回，否则尾调 YYCreateString(0xe5258) ── */
/* @0x21237c cmp r1, #0 */
/* @0x212380 beq 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212384 mov r0, r6 */
/* @0x212388 add sp, sp, #20 */
/* @0x21238c pop {r4, r5, r6, r7, r8, r9, lr} */
/* @0x212390 b 0xe5258 <_Z14YYCreateStringP6RValuePKc> */
/* ── 段 5 · case 体群（0x212394..0x212b00，62 个装填块按键序散布，体内无分支）── */
/* @0x212394 movw r2, #0x2fbd */
/* @0x212398 cmp r3, r2 */
/* @0x21239c beq 0x212a40 <_Z11Call_NormaliPdPPKcP6RValue+0xa98> */
/* @0x2123a0 add r2, r2, #1 */
/* @0x2123a4 cmp r3, r2 */
/* @0x2123a8 beq 0x212a1c <_Z11Call_NormaliPdPPKcP6RValue+0xa74> */
/* @0x2123ac movw r2, #0x2fb4 */
/* @0x2123b0 cmp r3, r2 */
/* @0x2123b4 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2123b8 ldrd r0, r1, [r4, #24] */
/* @0x2123bc ldr r2, [r7, #0x4] */
/* @0x2123c0 ldr r3, [r7, #0x8] */
/* @0x2123c4 strd r0, r1, [sp] */
/* @0x2123c8 ldrd r0, r1, [r4] */
/* @0x2123cc ldr r12, [r12, #0xc] */
/* @0x2123d0 blx r12 */
/* @0x2123d4 mov r1, r0 */
/* @0x2123d8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2123dc movw r2, #0x8ad */
/* @0x2123e0 cmp r3, r2 */
/* @0x2123e4 beq 0x212aa8 <_Z11Call_NormaliPdPPKcP6RValue+0xb00> */
/* @0x2123e8 add r2, r2, #1 */
/* @0x2123ec cmp r3, r2 */
/* @0x2123f0 beq 0x212a94 <_Z11Call_NormaliPdPPKcP6RValue+0xaec> */
/* @0x2123f4 movw r2, #0x8a4 */
/* @0x2123f8 cmp r3, r2 */
/* @0x2123fc bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212400 ldrd r0, r1, [r4] */
/* @0x212404 ldr r12, [r12, #0xc] */
/* @0x212408 ldmib r7, {r2, r3} */
/* @0x21240c blx r12 */
/* @0x212410 mov r1, r0 */
/* @0x212414 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212418 cmp r3, #221 */
/* @0x21241c beq 0x212a08 <_Z11Call_NormaliPdPPKcP6RValue+0xa60> */
/* @0x212420 cmp r3, #222 */
/* @0x212424 beq 0x2129f4 <_Z11Call_NormaliPdPPKcP6RValue+0xa4c> */
/* @0x212428 cmp r3, #212 */
/* @0x21242c bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212430 ldrd r0, r1, [r4] */
/* @0x212434 ldr r3, [r12, #0xc] */
/* @0x212438 ldr r2, [r7, #0x4] */
/* @0x21243c blx r3 */
/* @0x212440 mov r1, r0 */
/* @0x212444 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212448 movw r2, #0x4c5 */
/* @0x21244c cmp r3, r2 */
/* @0x212450 beq 0x212a7c <_Z11Call_NormaliPdPPKcP6RValue+0xad4> */
/* @0x212454 add r2, r2, #1 */
/* @0x212458 cmp r3, r2 */
/* @0x21245c beq 0x212a64 <_Z11Call_NormaliPdPPKcP6RValue+0xabc> */
/* @0x212460 movw r2, #0x4bc */
/* @0x212464 cmp r3, r2 */
/* @0x212468 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21246c ldrd r8, r9, [r4, #16] */
/* @0x212470 ldrd r0, r1, [r4] */
/* @0x212474 ldr r2, [r7, #0x4] */
/* @0x212478 strd r8, r9, [sp] */
/* @0x21247c ldr r3, [r12, #0xc] */
/* @0x212480 blx r3 */
/* @0x212484 mov r1, r0 */
/* @0x212488 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21248c movw r2, #0x52e5 */
/* @0x212490 cmp r3, r2 */
/* @0x212494 beq 0x212ae4 <_Z11Call_NormaliPdPPKcP6RValue+0xb3c> */
/* @0x212498 add r2, r2, #1 */
/* @0x21249c cmp r3, r2 */
/* @0x2124a0 beq 0x212abc <_Z11Call_NormaliPdPPKcP6RValue+0xb14> */
/* @0x2124a4 movw r2, #0x52dc */
/* @0x2124a8 cmp r3, r2 */
/* @0x2124ac bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2124b0 ldr r3, [r7, #0xc] */
/* @0x2124b4 ldrd r0, r1, [r4, #16] */
/* @0x2124b8 ldr r2, [r7, #0x4] */
/* @0x2124bc strd r0, r1, [sp] */
/* @0x2124c0 ldrd r0, r1, [r4] */
/* @0x2124c4 str r3, [sp, #0x8] */
/* @0x2124c8 ldr r3, [r12, #0xc] */
/* @0x2124cc blx r3 */
/* @0x2124d0 mov r1, r0 */
/* @0x2124d4 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2124d8 movw r2, #0x2bd5 */
/* @0x2124dc cmp r3, r2 */
/* @0x2124e0 beq 0x212768 <_Z11Call_NormaliPdPPKcP6RValue+0x7c0> */
/* @0x2124e4 add r2, r2, #1 */
/* @0x2124e8 cmp r3, r2 */
/* @0x2124ec beq 0x212744 <_Z11Call_NormaliPdPPKcP6RValue+0x79c> */
/* @0x2124f0 movw r2, #0x2bcc */
/* @0x2124f4 cmp r3, r2 */
/* @0x2124f8 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2124fc ldrd r0, r1, [r4, #16] */
/* @0x212500 ldrd r8, r9, [r4, #24] */
/* @0x212504 ldr r2, [r7, #0x4] */
/* @0x212508 strd r0, r1, [sp] */
/* @0x21250c strd r8, r9, [sp, #8] */
/* @0x212510 ldrd r0, r1, [r4] */
/* @0x212514 ldr r3, [r12, #0xc] */
/* @0x212518 blx r3 */
/* @0x21251c mov r1, r0 */
/* @0x212520 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212524 movw r2, #0x56cd */
/* @0x212528 cmp r3, r2 */
/* @0x21252c beq 0x2127f0 <_Z11Call_NormaliPdPPKcP6RValue+0x848> */
/* @0x212530 add r2, r2, #1 */
/* @0x212534 cmp r3, r2 */
/* @0x212538 beq 0x2127dc <_Z11Call_NormaliPdPPKcP6RValue+0x834> */
/* @0x21253c movw r2, #0x56c4 */
/* @0x212540 cmp r3, r2 */
/* @0x212544 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212548 ldrd r4, r5, [r4] */
/* @0x21254c ldr r1, [r7, #0xc] */
/* @0x212550 ldmib r7, {r2, r3} */
/* @0x212554 mov r0, r4 */
/* @0x212558 str r1, [sp] */
/* @0x21255c mov r1, r5 */
/* @0x212560 ldr r12, [r12, #0xc] */
/* @0x212564 blx r12 */
/* @0x212568 mov r1, r0 */
/* @0x21256c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212570 ldr r3, [r12, #0xc] */
/* @0x212574 ldrd r0, r1, [r4] */
/* @0x212578 blx r3 */
/* @0x21257c stm r6, {r0, r1} */
/* @0x212580 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212584 cmp r3, #1 */
/* @0x212588 beq 0x212628 <_Z11Call_NormaliPdPPKcP6RValue+0x680> */
/* @0x21258c cmp r3, #2 */
/* @0x212590 bne 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212594 ldr r3, [r12, #0xc] */
/* @0x212598 blx r3 */
/* @0x21259c mov r1, r0 */
/* @0x2125a0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2125a4 ldrd r8, r9, [r4, #16] */
/* @0x2125a8 ldr r2, [r7, #0x4] */
/* @0x2125ac ldrd r0, r1, [r4] */
/* @0x2125b0 strd r8, r9, [sp] */
/* @0x2125b4 ldr r3, [r12, #0xc] */
/* @0x2125b8 blx r3 */
/* @0x2125bc stm r6, {r0, r1} */
/* @0x2125c0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2125c4 ldrd r0, r1, [r4, #16] */
/* @0x2125c8 ldrd r8, r9, [r4, #24] */
/* @0x2125cc ldr r2, [r7, #0x4] */
/* @0x2125d0 strd r0, r1, [sp] */
/* @0x2125d4 strd r8, r9, [sp, #8] */
/* @0x2125d8 ldrd r0, r1, [r4] */
/* @0x2125dc ldr r3, [r12, #0xc] */
/* @0x2125e0 blx r3 */
/* @0x2125e4 stm r6, {r0, r1} */
/* @0x2125e8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2125ec ldr r3, [r12, #0xc] */
/* @0x2125f0 ldr r0, [r7] */
/* @0x2125f4 blx r3 */
/* @0x2125f8 mov r1, r0 */
/* @0x2125fc b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212600 ldr r3, [r7, #0xc] */
/* @0x212604 ldrd r0, r1, [r4, #16] */
/* @0x212608 ldr r2, [r7, #0x4] */
/* @0x21260c strd r0, r1, [sp] */
/* @0x212610 ldrd r0, r1, [r4] */
/* @0x212614 str r3, [sp, #0x8] */
/* @0x212618 ldr r3, [r12, #0xc] */
/* @0x21261c blx r3 */
/* @0x212620 stm r6, {r0, r1} */
/* @0x212624 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212628 ldr r3, [r12, #0xc] */
/* @0x21262c blx r3 */
/* @0x212630 stm r6, {r0, r1} */
/* @0x212634 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212638 ldrd r0, r1, [r4, #24] */
/* @0x21263c ldr r2, [r7, #0x4] */
/* @0x212640 ldr r3, [r7, #0x8] */
/* @0x212644 strd r0, r1, [sp] */
/* @0x212648 ldrd r0, r1, [r4] */
/* @0x21264c ldr r12, [r12, #0xc] */
/* @0x212650 blx r12 */
/* @0x212654 stm r6, {r0, r1} */
/* @0x212658 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21265c ldr r12, [r12, #0xc] */
/* @0x212660 ldrd r0, r1, [r4] */
/* @0x212664 ldrd r2, r3, [r4, #8] */
/* @0x212668 blx r12 */
/* @0x21266c stm r6, {r0, r1} */
/* @0x212670 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212674 ldr r12, [r12, #0xc] */
/* @0x212678 ldrd r0, r1, [r4] */
/* @0x21267c ldmib r7, {r2, r3} */
/* @0x212680 blx r12 */
/* @0x212684 stm r6, {r0, r1} */
/* @0x212688 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21268c ldrd r2, r3, [r4, #24] */
/* @0x212690 ldr lr, [r7, #0x8] */
/* @0x212694 ldrd r0, r1, [r4] */
/* @0x212698 strd r2, r3, [sp, #8] */
/* @0x21269c ldrd r2, r3, [r4, #8] */
/* @0x2126a0 str lr, [sp] */
/* @0x2126a4 ldr r12, [r12, #0xc] */
/* @0x2126a8 blx r12 */
/* @0x2126ac stm r6, {r0, r1} */
/* @0x2126b0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2126b4 ldr r1, [r7, #0x8] */
/* @0x2126b8 ldrd r2, r3, [r4, #8] */
/* @0x2126bc ldr r0, [r7] */
/* @0x2126c0 str r1, [sp] */
/* @0x2126c4 ldr r1, [r12, #0xc] */
/* @0x2126c8 blx r1 */
/* @0x2126cc mov r1, r0 */
/* @0x2126d0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2126d4 ldr r1, [r7, #0x8] */
/* @0x2126d8 ldrd r2, r3, [r4, #8] */
/* @0x2126dc ldr r0, [r7] */
/* @0x2126e0 str r1, [sp] */
/* @0x2126e4 ldr r1, [r12, #0xc] */
/* @0x2126e8 blx r1 */
/* @0x2126ec stm r6, {r0, r1} */
/* @0x2126f0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2126f4 ldr r5, [r7, #0x8] */
/* @0x2126f8 ldr lr, [r7, #0xc] */
/* @0x2126fc ldrd r0, r1, [r4] */
/* @0x212700 ldrd r2, r3, [r4, #8] */
/* @0x212704 stm sp, {r5, lr} */
/* @0x212708 ldr r12, [r12, #0xc] */
/* @0x21270c blx r12 */
/* @0x212710 stm r6, {r0, r1} */
/* @0x212714 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212718 ldr r3, [r12, #0xc] */
/* @0x21271c ldr r2, [r7, #0x4] */
/* @0x212720 ldrd r0, r1, [r4] */
/* @0x212724 blx r3 */
/* @0x212728 stm r6, {r0, r1} */
/* @0x21272c b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212730 ldr r3, [r12, #0xc] */
/* @0x212734 ldr r0, [r7] */
/* @0x212738 blx r3 */
/* @0x21273c stm r6, {r0, r1} */
/* @0x212740 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212744 ldrd r2, r3, [r4, #24] */
/* @0x212748 ldr r1, [r7, #0x4] */
/* @0x21274c ldr r0, [r7] */
/* @0x212750 strd r2, r3, [sp] */
/* @0x212754 ldrd r2, r3, [r4, #16] */
/* @0x212758 ldr r12, [r12, #0xc] */
/* @0x21275c blx r12 */
/* @0x212760 mov r1, r0 */
/* @0x212764 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212768 ldrd r2, r3, [r4, #24] */
/* @0x21276c ldr r0, [r7] */
/* @0x212770 ldr r1, [r7, #0x4] */
/* @0x212774 strd r2, r3, [sp] */
/* @0x212778 ldrd r2, r3, [r4, #16] */
/* @0x21277c ldr r12, [r12, #0xc] */
/* @0x212780 blx r12 */
/* @0x212784 stm r6, {r0, r1} */
/* @0x212788 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21278c ldr r1, [r7, #0xc] */
/* @0x212790 ldr lr, [r7, #0x8] */
/* @0x212794 ldrd r2, r3, [r4, #8] */
/* @0x212798 ldr r0, [r7] */
/* @0x21279c str lr, [sp] */
/* @0x2127a0 str r1, [sp, #0x4] */
/* @0x2127a4 ldr r1, [r12, #0xc] */
/* @0x2127a8 blx r1 */
/* @0x2127ac mov r1, r0 */
/* @0x2127b0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2127b4 ldr r1, [r7, #0xc] */
/* @0x2127b8 ldr lr, [r7, #0x8] */
/* @0x2127bc ldrd r2, r3, [r4, #8] */
/* @0x2127c0 ldr r0, [r7] */
/* @0x2127c4 str lr, [sp] */
/* @0x2127c8 str r1, [sp, #0x4] */
/* @0x2127cc ldr r1, [r12, #0xc] */
/* @0x2127d0 blx r1 */
/* @0x2127d4 stm r6, {r0, r1} */
/* @0x2127d8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2127dc ldm r7, {r0, r1, r2, r3} */
/* @0x2127e0 ldr r12, [r12, #0xc] */
/* @0x2127e4 blx r12 */
/* @0x2127e8 mov r1, r0 */
/* @0x2127ec b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2127f0 ldr r12, [r12, #0xc] */
/* @0x2127f4 ldm r7, {r0, r1, r2, r3} */
/* @0x2127f8 blx r12 */
/* @0x2127fc stm r6, {r0, r1} */
/* @0x212800 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212804 ldr r1, [r7, #0x8] */
/* @0x212808 ldrd r2, r3, [r4, #24] */
/* @0x21280c ldr r0, [r7] */
/* @0x212810 strd r2, r3, [sp, #8] */
/* @0x212814 ldrd r2, r3, [r4, #8] */
/* @0x212818 str r1, [sp] */
/* @0x21281c ldr r1, [r12, #0xc] */
/* @0x212820 blx r1 */
/* @0x212824 mov r1, r0 */
/* @0x212828 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21282c ldr r1, [r7, #0x8] */
/* @0x212830 ldrd r2, r3, [r4, #24] */
/* @0x212834 ldr r0, [r7] */
/* @0x212838 strd r2, r3, [sp, #8] */
/* @0x21283c ldrd r2, r3, [r4, #8] */
/* @0x212840 str r1, [sp] */
/* @0x212844 ldr r1, [r12, #0xc] */
/* @0x212848 blx r1 */
/* @0x21284c stm r6, {r0, r1} */
/* @0x212850 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212854 ldrd r8, r9, [r4, #16] */
/* @0x212858 ldr r0, [r7] */
/* @0x21285c ldrd r2, r3, [r4, #8] */
/* @0x212860 strd r8, r9, [sp] */
/* @0x212864 ldr r1, [r12, #0xc] */
/* @0x212868 blx r1 */
/* @0x21286c mov r1, r0 */
/* @0x212870 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212874 ldrd r8, r9, [r4, #16] */
/* @0x212878 ldr r0, [r7] */
/* @0x21287c ldrd r2, r3, [r4, #8] */
/* @0x212880 strd r8, r9, [sp] */
/* @0x212884 ldr r1, [r12, #0xc] */
/* @0x212888 blx r1 */
/* @0x21288c stm r6, {r0, r1} */
/* @0x212890 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212894 ldr r1, [r7, #0xc] */
/* @0x212898 ldrd r2, r3, [r4, #16] */
/* @0x21289c ldr r0, [r7] */
/* @0x2128a0 strd r2, r3, [sp] */
/* @0x2128a4 ldrd r2, r3, [r4, #8] */
/* @0x2128a8 str r1, [sp, #0x8] */
/* @0x2128ac ldr r1, [r12, #0xc] */
/* @0x2128b0 blx r1 */
/* @0x2128b4 mov r1, r0 */
/* @0x2128b8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2128bc ldr r1, [r7, #0xc] */
/* @0x2128c0 ldrd r2, r3, [r4, #16] */
/* @0x2128c4 ldr r0, [r7] */
/* @0x2128c8 strd r2, r3, [sp] */
/* @0x2128cc ldrd r2, r3, [r4, #8] */
/* @0x2128d0 str r1, [sp, #0x8] */
/* @0x2128d4 ldr r1, [r12, #0xc] */
/* @0x2128d8 blx r1 */
/* @0x2128dc stm r6, {r0, r1} */
/* @0x2128e0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2128e4 ldrd r2, r3, [r4, #16] */
/* @0x2128e8 ldrd r8, r9, [r4, #24] */
/* @0x2128ec ldr r0, [r7] */
/* @0x2128f0 strd r2, r3, [sp] */
/* @0x2128f4 strd r8, r9, [sp, #8] */
/* @0x2128f8 ldr r1, [r12, #0xc] */
/* @0x2128fc ldrd r2, r3, [r4, #8] */
/* @0x212900 blx r1 */
/* @0x212904 mov r1, r0 */
/* @0x212908 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x21290c ldrd r2, r3, [r4, #16] */
/* @0x212910 ldrd r8, r9, [r4, #24] */
/* @0x212914 ldr r0, [r7] */
/* @0x212918 strd r2, r3, [sp] */
/* @0x21291c strd r8, r9, [sp, #8] */
/* @0x212920 ldrd r2, r3, [r4, #8] */
/* @0x212924 ldr r1, [r12, #0xc] */
/* @0x212928 blx r1 */
/* @0x21292c stm r6, {r0, r1} */
/* @0x212930 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212934 ldr lr, [r7, #0x8] */
/* @0x212938 ldrd r0, r1, [r4] */
/* @0x21293c ldrd r2, r3, [r4, #8] */
/* @0x212940 str lr, [sp] */
/* @0x212944 ldr r12, [r12, #0xc] */
/* @0x212948 blx r12 */
/* @0x21294c stm r6, {r0, r1} */
/* @0x212950 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212954 ldrd r2, r3, [r4, #16] */
/* @0x212958 ldrd r0, r1, [r4, #24] */
/* @0x21295c strd r2, r3, [sp] */
/* @0x212960 strd r0, r1, [sp, #8] */
/* @0x212964 ldrd r0, r1, [r4] */
/* @0x212968 ldr r12, [r12, #0xc] */
/* @0x21296c ldrd r2, r3, [r4, #8] */
/* @0x212970 blx r12 */
/* @0x212974 stm r6, {r0, r1} */
/* @0x212978 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x21297c ldrd r2, r3, [r4, #16] */
/* @0x212980 ldr lr, [r7, #0xc] */
/* @0x212984 ldrd r0, r1, [r4] */
/* @0x212988 strd r2, r3, [sp] */
/* @0x21298c ldrd r2, r3, [r4, #8] */
/* @0x212990 str lr, [sp, #0x8] */
/* @0x212994 ldr r12, [r12, #0xc] */
/* @0x212998 blx r12 */
/* @0x21299c stm r6, {r0, r1} */
/* @0x2129a0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129a4 ldrd r2, r3, [r4, #16] */
/* @0x2129a8 ldrd r0, r1, [r4] */
/* @0x2129ac strd r2, r3, [sp] */
/* @0x2129b0 ldr r12, [r12, #0xc] */
/* @0x2129b4 ldrd r2, r3, [r4, #8] */
/* @0x2129b8 blx r12 */
/* @0x2129bc stm r6, {r0, r1} */
/* @0x2129c0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129c4 ldr r1, [r12, #0xc] */
/* @0x2129c8 ldr r0, [r7] */
/* @0x2129cc ldrd r2, r3, [r4, #8] */
/* @0x2129d0 blx r1 */
/* @0x2129d4 mov r1, r0 */
/* @0x2129d8 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x2129dc ldr r1, [r12, #0xc] */
/* @0x2129e0 ldr r0, [r7] */
/* @0x2129e4 ldrd r2, r3, [r4, #8] */
/* @0x2129e8 blx r1 */
/* @0x2129ec stm r6, {r0, r1} */
/* @0x2129f0 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x2129f4 ldm r7, {r0, r1} */
/* @0x2129f8 ldr r3, [r12, #0xc] */
/* @0x2129fc blx r3 */
/* @0x212a00 mov r1, r0 */
/* @0x212a04 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a08 ldr r3, [r12, #0xc] */
/* @0x212a0c ldm r7, {r0, r1} */
/* @0x212a10 blx r3 */
/* @0x212a14 stm r6, {r0, r1} */
/* @0x212a18 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a1c ldrd r2, r3, [r4, #24] */
/* @0x212a20 ldr r1, [r7, #0x4] */
/* @0x212a24 ldr r0, [r7] */
/* @0x212a28 strd r2, r3, [sp] */
/* @0x212a2c ldr r2, [r7, #0x8] */
/* @0x212a30 ldr r3, [r12, #0xc] */
/* @0x212a34 blx r3 */
/* @0x212a38 mov r1, r0 */
/* @0x212a3c b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a40 ldrd r2, r3, [r4, #24] */
/* @0x212a44 ldr r0, [r7] */
/* @0x212a48 ldr r1, [r7, #0x4] */
/* @0x212a4c strd r2, r3, [sp] */
/* @0x212a50 ldr r2, [r7, #0x8] */
/* @0x212a54 ldr r3, [r12, #0xc] */
/* @0x212a58 blx r3 */
/* @0x212a5c stm r6, {r0, r1} */
/* @0x212a60 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a64 ldm r7, {r0, r1} */
/* @0x212a68 ldr r12, [r12, #0xc] */
/* @0x212a6c ldrd r2, r3, [r4, #16] */
/* @0x212a70 blx r12 */
/* @0x212a74 mov r1, r0 */
/* @0x212a78 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212a7c ldr r12, [r12, #0xc] */
/* @0x212a80 ldm r7, {r0, r1} */
/* @0x212a84 ldrd r2, r3, [r4, #16] */
/* @0x212a88 blx r12 */
/* @0x212a8c stm r6, {r0, r1} */
/* @0x212a90 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212a94 ldm r7, {r0, r1, r2} */
/* @0x212a98 ldr r3, [r12, #0xc] */
/* @0x212a9c blx r3 */
/* @0x212aa0 mov r1, r0 */
/* @0x212aa4 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212aa8 ldr r3, [r12, #0xc] */
/* @0x212aac ldm r7, {r0, r1, r2} */
/* @0x212ab0 blx r3 */
/* @0x212ab4 stm r6, {r0, r1} */
/* @0x212ab8 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* @0x212abc ldrd r4, r5, [r4, #16] */
/* @0x212ac0 ldr r3, [r7, #0xc] */
/* @0x212ac4 ldm r7, {r0, r1} */
/* @0x212ac8 mov r2, r4 */
/* @0x212acc str r3, [sp] */
/* @0x212ad0 mov r3, r5 */
/* @0x212ad4 ldr r12, [r12, #0xc] */
/* @0x212ad8 blx r12 */
/* @0x212adc mov r1, r0 */
/* @0x212ae0 b 0x21237c <_Z11Call_NormaliPdPPKcP6RValue+0x3d4> */
/* @0x212ae4 ldr lr, [r7, #0xc] */
/* @0x212ae8 ldrd r2, r3, [r4, #16] */
/* @0x212aec ldm r7, {r0, r1} */
/* @0x212af0 str lr, [sp] */
/* @0x212af4 ldr r12, [r12, #0xc] */
/* @0x212af8 blx r12 */
/* @0x212afc stm r6, {r0, r1} */
/* @0x212b00 b 0x212110 <_Z11Call_NormaliPdPPKcP6RValue+0x168> */
/* ── 段 6 · 字面池：0x001df3fc → GOT[0x3f13b4] 中止字节；0x001df3dc → GOT[0x3f13b8] 表对象 ── */
/* @0x212b04 ldrsheq pc, [sp], -r12 */
/* @0x212b08 ldrsbeq pc, [sp], -r12 */
